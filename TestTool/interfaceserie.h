#ifndef INTERFACESERIE_H
#define INTERFACESERIE_H

#include <QWidget>
#include <QtCharts>


QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceSerie; }
QT_END_NAMESPACE

class InterfaceSerie : public QWidget
{
    Q_OBJECT

public:
    InterfaceSerie(QWidget *parent = nullptr);
    ~InterfaceSerie();


    double freq_double;
    unsigned char waveform1=0,waveform2=0,channel1=0,channel2=0;
    int     freq_int1=0,
            freq_ram=0,
            freq_int2=0,
            tri_freq_1_1=0,
            tri_freq_1_2=0,
            tri_freq_2_1=0,
            tri_freq_2_2=0,
            cport_nr=0;



    short   amplitude1=0,
            amplitude2=0,            
            cyclicRatio1=0,
            cyclicRatio2=0,
            tab_user_coef1[65536],
            tab_user_coef2[65536];

    signed short offset1=0,
                 offset2=0;

    unsigned short nb_coef_ram=0,nb_coef_ram2=0;

    bool ok1=false,ok2=false,click=true;

  QMainWindow window;


    void send_on_port();


private slots:

    void wait(int time);

    void send_signal1();
    void send_signal2();

    void on_ButtonScan_clicked();
    void on_pushButtonPortOk_clicked();    

    void on_radioSin1_clicked();
    void on_radioSin2_clicked();

    void on_radioSquare1_clicked();
    void on_radioSquare2_clicked();

    void on_radioSaw1_clicked();
    void on_radioSaw2_clicked();

    void on_signal1_en_clicked(bool checked);
    void on_signal2_en_clicked(bool checked);

    void on_button_Send_clicked();

    void on_radioNoise1_clicked();
    void on_radioNoise2_clicked();

    void on_RadioSignalGen_clicked();

    void on_RadioBode_clicked();

    void on_button_OkBode_clicked();

    void graph(QLineSeries *series,QLineSeries *series1, int min, int max);

    void on_browse1_clicked();
    void on_browse2_clicked();

    void on_radiofile1_clicked();
    void on_radiofile2_clicked();


private:
    Ui::InterfaceSerie *ui;
};
#endif // INTERFACESERIE_H
