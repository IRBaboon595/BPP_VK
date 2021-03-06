#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QTextEdit>
#include <iostream>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <QtMath>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <Shlwapi.h>
#include <iomanip>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QDialog>
#include <QTabWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QFile>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <QMouseEvent>
#include <QLabel>
#include <QDataStream>
#include <QGroupBox>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QDebug>
#include <QDial>

#define	SYNCHRO                     0x02
#define UART_ADDR                   0x0A
#define SERVICE_BITS_LEN            0x06

#define ECHO						0x00
#define SUPPLY_CTRL					0x01
#define ATT_CTRL					0x02
#define DAC_REVISION				0x03
#define	DAC_CTRL					0x04
#define POWER_AMP_EN				0x05
#define UM78_SUPPLY_CTRL			0x06
#define UM78_AMP_EN					0x07
#define UM78_DAC_CTRL				0x08

#define	OUT_POW_13dBm               0x0
#define	OUT_POW_11dBm               0x1
#define	OUT_POW_8dBm                0x2
#define	OUT_POW_6dBm                0x3

#define	PRESC_8_9					0x0
#define	PRESC_16_17                 0x1
#define	PRESC_32_33                 0x2
#define	PRESC_32_33_d               0x3

#define ON                          0x01
#define OFF                         0x00

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort                     *COM;
    QFile                           *File;
    QTime                           *Timer_Data;
    QTabWidget                      *TabS;
    QWidget                         *first_tab;
    QWidget                         *second_tab;
    QWidget                         *third_tab;
    QWidget                         *fourth_tab;
    QWidget                         *fifth_tab;
    QDataStream                     fileStream;
    QGroupBox                       *crystal_group;
    QGroupBox                       *ad5932_group;
    QGroupBox                       *adf4360_group;
    QCheckBox                       *crystal_status;
    QCheckBox                       *msb_status;
    QCheckBox                       *signal_type_status;
    QCheckBox                       *ctrl_type_status;
    QCheckBox                       *test_radio_button;
    QCheckBox                       *signal_type;
    QLabel                          *freq_start_label;
    QLabel                          *freq_delta_label;
    QLabel                          *n_increment_label;
    QLabel                          *time_interval_label;
    QLabel                          *a_counter_label;
    QLabel                          *b_counter_label;
    QLabel                          *r_counter_label;
    QLabel                          *power_level_label;
    QLabel                          *p_prescaler_label;
    QLineEdit                       *freq_start;
    QLineEdit                       *freq_delta;
    QLineEdit                       *n_increment;
    QLineEdit                       *time_interval;
    QLineEdit                       *a_counter;
    QLineEdit                       *b_counter;
    QLineEdit                       *r_counter;
    QPushButton                     *ad5932_send;
    QPushButton                     *crystal_send;
    QPushButton                     *adf4360_send;
    QPushButton                     *addParamFreq_tag;
    QPushButton                     *sendparamFreq_total;
    QPushButton                     *Parcel_test;
    QComboBox                       *power_level;
    QComboBox                       *p_prescaler;
    QString                         file_string;
    QByteArray                      file_byte_array;

    uint8_t                         signal_type_mode;
    uint16_t                        tag_number;
    quint32                         file_log_number;
    uint64_t                        tag_frequency[18];
    uint64_t                        band_frequency[18];
    uint64_t                        sweep_step_frequency[18];
    uint64_t                        temperature_points;
    double                          a;
    double                          b;
    double                          c;

private:
    Ui::MainWindow *ui;
    typedef union{
        uint16_t 	istd;
        uint8_t 	cstd[2];
    }std_union;

    typedef union{
        uint32_t 	listd;
        uint16_t 	istd[2];
        uint8_t 	cstd[4];
    }long_std_union;

    typedef union{
        uint64_t 	llistd;
        uint32_t 	listd[2];
        uint16_t 	istd[4];
        uint8_t 	cstd[8];
    }long_long_std_union;

    typedef struct
    {
        double      *module;
        double      *real;
        double      *image;
    }DFT_result;

    char            CRC = 0;

    uint8_t         com_mode;
    uint8_t         uart_command;
    uint8_t         antenna_selected;
    uint8_t         path_selected;
    uint8_t         data_check_box;
    uint8_t         timer_2_mode;
    uint8_t         UART_RECEIVE_BUFFER[10000];
    uint8_t         power_ctrl_byte_1;
    uint8_t         power_ctrl_byte_2;

    uint16_t        adc_call_command_counter;
    uint16_t        adc_global_counter;
    uint16_t        attenuation_selected;
    uint16_t        gatevoltage_selected;
    uint16_t        UM78_gatevoltage_selected;
    uint16_t        X_DATA_BUFFER[1000];

    uint64_t        time;
    QTimer          *timer_1;
    QElapsedTimer   *timer_2;
    QTimer          *timer_3;
    QPixmap         *echo_pix;
    QByteArray      ba;

    std_union       len;

    double          ADC_DATA_BUFFER[1000];
    double          zero[1000];

    DFT_result      Fourier;
    DFT_result      Fourier_1;
    DFT_result      Fourier_2;

    QLabel          *current_temperature;
    QString         *cur_temp;
private slots:
    void getEcho(void);
    void connectCOM(void);
    void readData(void);
    void power_ctrl_Data(void);
    void setAttenuation(void);
    void selectAtt(void);
    void writeAtt(void);
    void setSyntParam(void);
    void on_plus_5_rf_omega_toggled(bool checked);
    void on_plus_5_rf_delta_toggled(bool checked);
    void on_plus_5_rf_sigma_toggled(bool checked);
};
#endif // MAINWINDOW_H
