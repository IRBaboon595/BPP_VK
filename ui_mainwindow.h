/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *SupplyCtrl;
    QCheckBox *plus_5_LO;
    QCheckBox *plus_5_rf_LO;
    QCheckBox *minus_5;
    QCheckBox *plus_5_delta_2;
    QCheckBox *plus_5_delta_1;
    QCheckBox *plus_5_rf_omega;
    QCheckBox *plus_5_omega_2;
    QCheckBox *plus_5_omega_1;
    QCheckBox *plus_5_sigma_2;
    QCheckBox *plus_5_rf_delta;
    QCheckBox *plus_5_sigma_1;
    QCheckBox *plus_5_rf_sigma;
    QPushButton *SupplyButton;
    QGroupBox *groupBox_2;
    QPushButton *com_button;
    QComboBox *com_combobox;
    QLabel *comstate_label;
    QPushButton *echo_button;
    QLabel *service_message;
    QGroupBox *groupBox_3;
    QSlider *att_slider;
    QLineEdit *att_line_edit;
    QPushButton *att_ctrl_pushbutton;
    QComboBox *att_address_combo;
    QGroupBox *groupBox;
    QDial *synt_power;
    QDial *synt_presc;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *a_lineedit;
    QLineEdit *b_lineedit;
    QLineEdit *r_lineedit;
    QPushButton *synt_send;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SupplyCtrl = new QGroupBox(centralwidget);
        SupplyCtrl->setObjectName(QString::fromUtf8("SupplyCtrl"));
        SupplyCtrl->setGeometry(QRect(10, 180, 291, 211));
        plus_5_LO = new QCheckBox(SupplyCtrl);
        plus_5_LO->setObjectName(QString::fromUtf8("plus_5_LO"));
        plus_5_LO->setGeometry(QRect(10, 30, 101, 17));
        plus_5_rf_LO = new QCheckBox(SupplyCtrl);
        plus_5_rf_LO->setObjectName(QString::fromUtf8("plus_5_rf_LO"));
        plus_5_rf_LO->setGeometry(QRect(10, 50, 111, 17));
        minus_5 = new QCheckBox(SupplyCtrl);
        minus_5->setObjectName(QString::fromUtf8("minus_5"));
        minus_5->setGeometry(QRect(10, 70, 70, 17));
        plus_5_delta_2 = new QCheckBox(SupplyCtrl);
        plus_5_delta_2->setObjectName(QString::fromUtf8("plus_5_delta_2"));
        plus_5_delta_2->setGeometry(QRect(10, 90, 131, 17));
        plus_5_delta_1 = new QCheckBox(SupplyCtrl);
        plus_5_delta_1->setObjectName(QString::fromUtf8("plus_5_delta_1"));
        plus_5_delta_1->setGeometry(QRect(10, 110, 131, 17));
        plus_5_rf_omega = new QCheckBox(SupplyCtrl);
        plus_5_rf_omega->setObjectName(QString::fromUtf8("plus_5_rf_omega"));
        plus_5_rf_omega->setGeometry(QRect(10, 130, 131, 17));
        plus_5_omega_2 = new QCheckBox(SupplyCtrl);
        plus_5_omega_2->setObjectName(QString::fromUtf8("plus_5_omega_2"));
        plus_5_omega_2->setGeometry(QRect(10, 150, 131, 17));
        plus_5_omega_1 = new QCheckBox(SupplyCtrl);
        plus_5_omega_1->setObjectName(QString::fromUtf8("plus_5_omega_1"));
        plus_5_omega_1->setGeometry(QRect(10, 170, 141, 17));
        plus_5_sigma_2 = new QCheckBox(SupplyCtrl);
        plus_5_sigma_2->setObjectName(QString::fromUtf8("plus_5_sigma_2"));
        plus_5_sigma_2->setGeometry(QRect(150, 50, 141, 17));
        plus_5_rf_delta = new QCheckBox(SupplyCtrl);
        plus_5_rf_delta->setObjectName(QString::fromUtf8("plus_5_rf_delta"));
        plus_5_rf_delta->setGeometry(QRect(150, 30, 131, 17));
        plus_5_sigma_1 = new QCheckBox(SupplyCtrl);
        plus_5_sigma_1->setObjectName(QString::fromUtf8("plus_5_sigma_1"));
        plus_5_sigma_1->setGeometry(QRect(150, 70, 131, 17));
        plus_5_rf_sigma = new QCheckBox(SupplyCtrl);
        plus_5_rf_sigma->setObjectName(QString::fromUtf8("plus_5_rf_sigma"));
        plus_5_rf_sigma->setGeometry(QRect(150, 90, 131, 17));
        SupplyButton = new QPushButton(SupplyCtrl);
        SupplyButton->setObjectName(QString::fromUtf8("SupplyButton"));
        SupplyButton->setGeometry(QRect(180, 140, 75, 23));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 201, 151));
        com_button = new QPushButton(groupBox_2);
        com_button->setObjectName(QString::fromUtf8("com_button"));
        com_button->setGeometry(QRect(100, 30, 91, 21));
        com_combobox = new QComboBox(groupBox_2);
        com_combobox->setObjectName(QString::fromUtf8("com_combobox"));
        com_combobox->setGeometry(QRect(10, 30, 81, 22));
        comstate_label = new QLabel(groupBox_2);
        comstate_label->setObjectName(QString::fromUtf8("comstate_label"));
        comstate_label->setGeometry(QRect(10, 60, 181, 16));
        comstate_label->setAlignment(Qt::AlignCenter);
        echo_button = new QPushButton(groupBox_2);
        echo_button->setObjectName(QString::fromUtf8("echo_button"));
        echo_button->setGeometry(QRect(10, 90, 181, 21));
        service_message = new QLabel(groupBox_2);
        service_message->setObjectName(QString::fromUtf8("service_message"));
        service_message->setGeometry(QRect(10, 120, 181, 16));
        service_message->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(220, 10, 201, 151));
        att_slider = new QSlider(groupBox_3);
        att_slider->setObjectName(QString::fromUtf8("att_slider"));
        att_slider->setGeometry(QRect(10, 30, 181, 16));
        att_slider->setMaximum(63);
        att_slider->setOrientation(Qt::Horizontal);
        att_slider->setTickPosition(QSlider::TicksAbove);
        att_slider->setTickInterval(2);
        att_line_edit = new QLineEdit(groupBox_3);
        att_line_edit->setObjectName(QString::fromUtf8("att_line_edit"));
        att_line_edit->setGeometry(QRect(10, 80, 181, 21));
        att_ctrl_pushbutton = new QPushButton(groupBox_3);
        att_ctrl_pushbutton->setObjectName(QString::fromUtf8("att_ctrl_pushbutton"));
        att_ctrl_pushbutton->setGeometry(QRect(10, 110, 181, 21));
        att_address_combo = new QComboBox(groupBox_3);
        att_address_combo->setObjectName(QString::fromUtf8("att_address_combo"));
        att_address_combo->setGeometry(QRect(10, 50, 181, 22));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(310, 180, 431, 261));
        synt_power = new QDial(groupBox);
        synt_power->setObjectName(QString::fromUtf8("synt_power"));
        synt_power->setGeometry(QRect(30, 30, 81, 81));
        synt_power->setMaximum(4);
        synt_power->setSliderPosition(0);
        synt_power->setWrapping(true);
        synt_power->setNotchTarget(5.000000000000000);
        synt_power->setNotchesVisible(true);
        synt_presc = new QDial(groupBox);
        synt_presc->setObjectName(QString::fromUtf8("synt_presc"));
        synt_presc->setGeometry(QRect(180, 30, 81, 81));
        synt_presc->setMaximum(4);
        synt_presc->setWrapping(true);
        synt_presc->setNotchTarget(5.000000000000000);
        synt_presc->setNotchesVisible(true);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 130, 81, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 130, 81, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 110, 21, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 21, 20));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 10, 21, 20));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 60, 21, 20));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(260, 60, 21, 20));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(210, 110, 21, 20));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(160, 60, 21, 20));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 10, 21, 20));
        label_10->setAlignment(Qt::AlignCenter);
        a_lineedit = new QLineEdit(groupBox);
        a_lineedit->setObjectName(QString::fromUtf8("a_lineedit"));
        a_lineedit->setGeometry(QRect(20, 170, 113, 20));
        b_lineedit = new QLineEdit(groupBox);
        b_lineedit->setObjectName(QString::fromUtf8("b_lineedit"));
        b_lineedit->setGeometry(QRect(160, 170, 113, 20));
        r_lineedit = new QLineEdit(groupBox);
        r_lineedit->setObjectName(QString::fromUtf8("r_lineedit"));
        r_lineedit->setGeometry(QRect(300, 170, 113, 20));
        synt_send = new QPushButton(groupBox);
        synt_send->setObjectName(QString::fromUtf8("synt_send"));
        synt_send->setGeometry(QRect(130, 220, 181, 21));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 190, 81, 20));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(180, 190, 81, 20));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(320, 190, 81, 20));
        label_13->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SupplyCtrl->setTitle(QCoreApplication::translate("MainWindow", "Supply control", nullptr));
        plus_5_LO->setText(QCoreApplication::translate("MainWindow", "+5V LO", nullptr));
        plus_5_rf_LO->setText(QCoreApplication::translate("MainWindow", "+5V RF Supply LO", nullptr));
        minus_5->setText(QCoreApplication::translate("MainWindow", "-5V Supply", nullptr));
        plus_5_delta_2->setText(QCoreApplication::translate("MainWindow", "+5V Amplifier 2 Delta", nullptr));
        plus_5_delta_1->setText(QCoreApplication::translate("MainWindow", "+5V Amplifier 1 Delta", nullptr));
        plus_5_rf_omega->setText(QCoreApplication::translate("MainWindow", "+5V RF Supply Omega", nullptr));
        plus_5_omega_2->setText(QCoreApplication::translate("MainWindow", "+5V Amplifier 2 Omega", nullptr));
        plus_5_omega_1->setText(QCoreApplication::translate("MainWindow", "+5V Amplifier 1 Omega", nullptr));
        plus_5_sigma_2->setText(QCoreApplication::translate("MainWindow", "+5V Amplifier 2 Sigma", nullptr));
        plus_5_rf_delta->setText(QCoreApplication::translate("MainWindow", "+5V RF Supply Delta", nullptr));
        plus_5_sigma_1->setText(QCoreApplication::translate("MainWindow", "+5V Amplifier 1 Sigma", nullptr));
        plus_5_rf_sigma->setText(QCoreApplication::translate("MainWindow", "+5V RF Supply Sigma", nullptr));
        SupplyButton->setText(QCoreApplication::translate("MainWindow", "Send Supply", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "COM Port", nullptr));
        com_button->setText(QCoreApplication::translate("MainWindow", "Open port", nullptr));
        comstate_label->setText(QCoreApplication::translate("MainWindow", "Closed", nullptr));
        echo_button->setText(QCoreApplication::translate("MainWindow", "Echo", nullptr));
        service_message->setText(QCoreApplication::translate("MainWindow", "No Echo", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Attenuator Control", nullptr));
        att_ctrl_pushbutton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Synthesizer control", nullptr));
#if QT_CONFIG(tooltip)
        synt_presc->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "Power select", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Prescaler select", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "-13", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "-11", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "-8", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "-6", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        synt_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
