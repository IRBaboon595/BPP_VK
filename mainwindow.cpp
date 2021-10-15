#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    power_ctrl_byte_1 = 0;

    ui->att_address_combo->addItem("Address 0x00");
    ui->att_address_combo->addItem("Address 0x01");
    ui->att_address_combo->addItem("Address 0x02");
    ui->att_address_combo->addItem("Address 0x03");
    ui->att_address_combo->addItem("Address 0x04");
    ui->att_address_combo->addItem("Address 0x05");
    ui->att_address_combo->addItem("Address 0x06");

    ui->plus_5_omega_1->setDisabled(true);
    ui->plus_5_omega_2->setDisabled(true);

    ui->plus_5_delta_1->setDisabled(true);
    ui->plus_5_delta_2->setDisabled(true);

    ui->plus_5_sigma_1->setDisabled(true);
    ui->plus_5_sigma_2->setDisabled(true);

    COM = new QSerialPort(this);
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox->addItem(info.portName());

    connect(ui->com_button, SIGNAL(clicked(bool)), this, SLOT(connectCOM()));
    connect(ui->echo_button, SIGNAL(clicked(bool)), this, SLOT(getEcho()));
    connect(ui->SupplyButton, SIGNAL(clicked(bool)), this, SLOT(power_ctrl_Data()));
    connect(ui->att_slider, SIGNAL(valueChanged(int)), this, SLOT(selectAtt()));
    connect(ui->att_line_edit, SIGNAL(editingFinished()), this, SLOT(writeAtt()));
    connect(ui->att_ctrl_pushbutton, SIGNAL(clicked(bool)), this, SLOT(setAttenuation()));
    connect(ui->synt_send, SIGNAL(clicked(bool)), this, SLOT(setSyntParam()));

    connect(COM, SIGNAL(readyRead()), this, SLOT(readData()));
}

/**************************************** Service Functions ****************************************/

void MainWindow::connectCOM(void)
{
    if(COM->portName() != ui->com_combobox->currentText())
    {
        COM->close();
        COM->setPortName(ui->com_combobox->currentText());
    }

    COM->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
    COM->setDataBits(QSerialPort::Data8);
    COM->setParity(QSerialPort::NoParity);
    COM->setStopBits(QSerialPort::OneStop);
    COM->setFlowControl(QSerialPort::NoFlowControl);
    COM->setReadBufferSize(0);
    if(COM->open(QSerialPort::ReadWrite))
    {
        ui->comstate_label->setText("<FONT COLOR=#008000>Opened</FONT>");
        com_mode = 1;
        ui->com_button->setText("Close port");
        //COM->setDataTerminalReady(true);
        //ui->label->setStyleSheet()
    }
    else
    {
        COM->close();
        ui->comstate_label->setText("<FONT COLOR=red>Closed</FONT>");
        ui->com_button->setText("Open port");
        com_mode = 0;
    }
}

/***************************************** Control Functions *********************************************/

void MainWindow::getEcho(void)
{
    QByteArray ba_1;
    char len = 0x06;
    char crc = 0;
    char echo = ECHO;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(echo);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
//    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));           //Если слать в закрытый порт будет зависание
    COM->waitForReadyRead(100);

}

void MainWindow::readData(void)
{
    char temp = 0;
    std_union temp_1;
    temp_1.istd = 0;
    uint16_t len_effective = 0;
    long_std_union data_temp;
    data_temp.listd = 0;
    //uint16_t window = 360;
    qDebug() << "ReadyRead_Got";
    ba.append(COM->readAll());
    qDebug() << ba.size();
    /*if(ba.size() < 806)
    {
        ba.push_back(COM->readAll());
    }*/

    int idx = ba.indexOf(SYNCHRO, 0);
    if(idx >= 0)
    {
        qDebug() << "Synchro byte found";
        if(idx > 0)
        {
            ba.remove(0,idx);
            idx = 0;
        }
        if(ba.size() > 2)
        {
            qDebug() << "Potential parcel";
            len.cstd[1] = ba[1];
            len.cstd[0] = ba[2];
            qDebug() << len.istd;
            if(len.istd > 3000)
            {
                ba.clear();
                /*COM->close();

                COM->open(QSerialPort::ReadWrite);*/
            }
            if(ba.size() >= len.istd)
            {
                qDebug() << "Potential parcel len achieved";
                temp = ba[3];
                if(temp == UART_ADDR)
                {
                    qDebug() << "Address achieved";
                    for(int i = 0; i < len.istd; i++)
                    {
                        CRC ^= ba[i];
                    }
                    if(CRC == 0)
                    {
                        qDebug() << "XOR approved";
                        temp = ba[4];
                        switch (temp)
                        {
                        case ECHO:
                            ui->service_message->setText("Echo Got");
                            uart_command = 0;
                            break;
                        case SUPPLY_CTRL:

                            break;
                        /*case GENERATION_CTRL:

                            uart_command = 2;
                            break;
                        case OUTPUT_SWITCH:

                            uart_command = 3;
                            break;
                        case SET_ATT:

                            uart_command = 4;
                            break;
                        case AMP_MANAGE:

                            uart_command = 5;
                            break;
                        case ADC_ECHO:
                            timer_1->stop();
                            ba.remove(0, temp_1.istd);
                            //COM->clear();
                            break;*/
                        default:

                            uart_command = 255;
                            timer_1->start();
                            break;
                        }
                        ba.clear();
                    }
                    else
                    {
                        qDebug() << "XOR error";
                        ui->service_message->setText("XOR error");
                        ba.remove(0, 1);
                    }
                }
                else
                {
                    qDebug() << "Address error";
                    ui->service_message->setText("Wrong address");
                    ba.remove(0, 1);
                }
            }
            else
            {
                qDebug() << "Not enough bytes";
                ui->service_message->setText("Not enough bytes");
            }
        }
        else
        {
            qDebug() << "Error length";
            ui->service_message->setText("Error length");
        }
    }
    else {
        qDebug() << "No Synchro";
        ui->service_message->setText("No Synchro");
        ba.clear();
    }


    CRC = 0;
}

void MainWindow::power_ctrl_Data(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data_1 = 0;
    char data_2 = 0;

    //first power byte ctrl
    if(ui->plus_5_omega_1->isChecked())
    {
        power_ctrl_byte_1 &=~ 0x80;
    }
    else
    {
        power_ctrl_byte_1 |= 0x80;
    }
    if(ui->plus_5_omega_2->isChecked())
    {
        power_ctrl_byte_1 &=~ 0x40;
    }
    else
    {
        power_ctrl_byte_1 |= 0x40;
    }
    if(ui->plus_5_rf_omega->isChecked())
    {
        power_ctrl_byte_1 |= 0x20;
    }
    else
    {
        power_ctrl_byte_1 &=~ 0x20;
    }
    if(ui->plus_5_delta_1->isChecked())
    {
        power_ctrl_byte_1 &=~ 0x10;
    }
    else
    {
        power_ctrl_byte_1 |= 0x10;
    }
    if(ui->plus_5_delta_2->isChecked())
    {
        power_ctrl_byte_1 &=~ 0x08;
    }
    else
    {
        power_ctrl_byte_1 |= 0x08;
    }
    if(ui->minus_5->isChecked())
    {
        power_ctrl_byte_1 |= 0x04;
    }
    else
    {
        power_ctrl_byte_1 &=~ 0x04;
    }
    if(ui->plus_5_rf_LO->isChecked())
    {
        power_ctrl_byte_1 |= 0x02;
    }
    else
    {
        power_ctrl_byte_1 &=~ 0x02;
    }
    if(ui->plus_5_LO->isChecked())
    {
        power_ctrl_byte_1 |= 0x01;
    }
    else
    {
        power_ctrl_byte_1 &=~ 0x01;
    }

    //second power byte ctrl
    if(ui->plus_5_rf_sigma->isChecked())
    {
        power_ctrl_byte_2 |= 0x08;
    }
    else
    {
        power_ctrl_byte_2 &=~ 0x08;
    }
    if(ui->plus_5_sigma_1->isChecked())
    {
        power_ctrl_byte_2 &=~ 0x04;
    }
    else
    {
        power_ctrl_byte_2 |= 0x04;
    }
    if(ui->plus_5_sigma_2->isChecked())
    {
        power_ctrl_byte_2 &=~ 0x02;
    }
    else
    {
        power_ctrl_byte_2 |= 0x02;
    }
    if(ui->plus_5_rf_delta->isChecked())
    {
        power_ctrl_byte_2 |= 0x01;
    }
    else
    {
        power_ctrl_byte_2 &=~ 0x01;
    }

    data_1 = (char)power_ctrl_byte_1;
    data_2 = (char)power_ctrl_byte_2;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(SUPPLY_CTRL);
    ba_1.append(data_1);
    ba_1.append(data_2);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));           //Если слать в закрытый порт будет зависание
    COM->waitForReadyRead(100);

}



/**************************************** Attenuator control ***********************************************/

void MainWindow::setAttenuation(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data_1 = 0;
    char data_2 = 0;
    std_union att_temp;

    data_2 = ui->att_address_combo->currentIndex();

    data_1 = (char)attenuation_selected;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(ATT_CTRL);
    ba_1.append(data_1);
    ba_1.append(data_2);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));
    COM->waitForReadyRead(100);
}

void MainWindow::selectAtt(void)
{
    double temp;
    attenuation_selected = ui->att_slider->value();
    temp = attenuation_selected;
    ui->att_line_edit->setText(QString::number(temp/2));
}

void MainWindow::writeAtt(void)
{
    QString string(ui->att_line_edit->text());
    double att_double_temp = string.toDouble(0);
    qDebug() << att_double_temp;
    attenuation_selected = att_double_temp*2;
}

/************************************** Synthesizer Functions *****************************************/

void MainWindow::setSyntParam(void)
{
    QByteArray ba_1;
    QString string;
    long_std_union temp;
    char len = 0x0D;
    char crc = 0;
    char data[7];
    std_union att_temp;

    if(ui->synt_power->value() != 4)
    {
        data[0] = ui->synt_power->value();
    }
    else
    {
        data[0] = 0;
    }

    if(ui->synt_presc->value() != 4)
    {
        data[1] = ui->synt_presc->value();
    }
    else
    {
        data[1] = 0;
    }

    string = ui->a_lineedit->text();
    data[2] = string.toInt(nullptr, 10);

    string = ui->b_lineedit->text();
    temp.istd[1] = string.toUInt(nullptr, 10);

    string = ui->r_lineedit->text();
    temp.istd[0] = string.toUInt(nullptr, 10);

    data[3] = temp.cstd[3];
    data[4] = temp.cstd[2];
    data[5] = temp.cstd[1];
    data[6] = temp.cstd[0];

    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(ATT_CTRL);
    ba_1.append(data[0]);
    ba_1.append(data[1]);
    ba_1.append(data[2]);
    ba_1.append(data[3]);
    ba_1.append(data[4]);
    ba_1.append(data[5]);
    ba_1.append(data[6]);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));
    COM->waitForReadyRead(100);
}

/************************************** Graph Functions *********************************************/


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_plus_5_rf_omega_toggled(bool checked)
{
    if(!checked)
    {
        ui->plus_5_omega_1->setDisabled(true);
        ui->plus_5_omega_2->setDisabled(true);
    }
    else
    {
        ui->plus_5_omega_1->setDisabled(false);
        ui->plus_5_omega_2->setDisabled(false);
    }
}

void MainWindow::on_plus_5_rf_delta_toggled(bool checked)
{
    if(!checked)
    {
        ui->plus_5_delta_1->setDisabled(true);
        ui->plus_5_delta_2->setDisabled(true);
    }
    else
    {
        ui->plus_5_delta_1->setDisabled(false);
        ui->plus_5_delta_2->setDisabled(false);
    }
}

void MainWindow::on_plus_5_rf_sigma_toggled(bool checked)
{
    if(!checked)
    {
        ui->plus_5_sigma_1->setDisabled(true);
        ui->plus_5_sigma_2->setDisabled(true);
    }
    else
    {
        ui->plus_5_sigma_1->setDisabled(false);
        ui->plus_5_sigma_2->setDisabled(false);
    }
}
