#include "interfaceserie.h"
#include "ui_interfaceserie.h"
#include <iostream>
#include <libusb.h>
#include <stdio.h>
#include "rs232.h"
#include <bitset>
#include <iomanip>
#include <QtCharts>
#include <QAction>
#include <QIcon>
#include <QRandomGenerator>

using namespace QtCharts;



InterfaceSerie::InterfaceSerie(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InterfaceSerie)
{
    ui->setupUi(this);
    QString textintel;
    textintel = "Start to scan available ComPort";
    ui->intel->setText(textintel);
    ui->widget_signal1->hide();
    ui->widget_signal2->hide();
    ui->widgetchannel1->hide();
    ui->widgetchannel2->hide();
    ui->widgetsignalEN->hide();
    ui->wigetCRatio->hide();
    ui->wigetCRatio_2->hide();
    ui->button_Send->hide();
    ui->widgetFreqSin->hide();
    ui->widgetFreqSin_2->hide();
    ui->chooseMode_2->hide();
    ui->gridBode->hide();
    ui->button_OkBode->hide();
    ui->linefile1->hide();
    ui->linefile2->hide();
    ui->progressBar->setValue(0);
    ui->progressBar2->setValue(0);
    ui->progressBar->hide();
    ui->progressBar2->hide();
}

InterfaceSerie::~InterfaceSerie()
{
    delete ui;
}

void InterfaceSerie::on_browse1_clicked(){

    #ifdef _WIN32
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:",
                                                    tr("*.txt (*.txt)"));
     #else
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("*.txt (*.txt)"));
     #endif
    ui->lineEdit->setText(fileName);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    ui->intel->setText("\"" + fileName+ "\"" + " loaded, ready to send");
    QString line[65536];

    QTextStream in(&file);
    nb_coef_ram=0;

    while (!in.atEnd()) {
        line[nb_coef_ram]=in.readLine() ;nb_coef_ram++;
    }

    for(int k=0;k<nb_coef_ram;k++){
        tab_user_coef1[k]=(unsigned short)line[k].toInt();
        tab_user_coef1[k]=tab_user_coef1[k];
    }
    file.close();
     ui->progressBar->setValue(0);
}
void InterfaceSerie::on_browse2_clicked(){

#ifdef _WIN32
QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                "C:",
                                                tr("*.txt (*.txt)"));
 #else
QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                "/home",
                                                tr("*.txt (*.txt)"));
 #endif
ui->lineEdit_2->setText(fileName);
QFile file(fileName);
if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;

ui->intel->setText("\"" + fileName+ "\"" + " loaded, ready to send");
QString line[65536];

QTextStream in(&file);
nb_coef_ram2=0;

while (!in.atEnd()) {
    line[nb_coef_ram2]=in.readLine() ;nb_coef_ram2++;
}

for(int k=0;k<nb_coef_ram2;k++){
    tab_user_coef2[k]=(unsigned short)line[k].toInt();
    tab_user_coef2[k]=tab_user_coef2[k]-32767;
}
file.close();
 ui->progressBar2->setValue(0);
}

void InterfaceSerie::wait(int time){
#ifdef _WIN32
 Sleep(time/1000);
 #else
 usleep(time); //sleep for 'time' milliSeconds
 #endif
}
void InterfaceSerie::on_button_Send_clicked(){

    QString textFreq, textFreq2,
            text_cyclicRatio1,
            text_cyclicRatio2,
            textAmpl1,
            textAmpl2,
            unit,
            textintel ="",
            n_string,
            text_offset1,
            text_offset2,
            text_tri_freq1_1,
            text_tri_freq1_2,
            text_tri_freq2_1,
            text_tri_freq2_2;


    double amplitude1_double,
            amplitude2_double,
            offset1_double,
            offset2_double;

    short short_cyclicRatio1,
          short_cyclicRatio2;
    int int_tri1,
        int_tri2;

    ok1=false;


//*************amplitude*********
    textAmpl1 = ui->lineAmplitude1->text();
    amplitude1_double = textAmpl1.toDouble();
    amplitude1_double = amplitude1_double * 9935;
    amplitude1 = (short) amplitude1_double;
    std::cout<<"ampli1 : "<<amplitude1<<std::endl;

    textAmpl2 = ui->lineAmplitude2->text();
    amplitude2_double = textAmpl2.toDouble();
    amplitude2_double = amplitude2_double*9935;
    amplitude2 = (short) amplitude2_double;
    std::cout<<"ampli2 : "<<amplitude2<<std::endl;
//*************offset*********
    text_offset1 = ui->lineOffset1->text();
    offset1_double = text_offset1.toDouble();
    offset1_double = offset1_double * 9935;// * 2;
    offset1 = (short) offset1_double;

    text_offset2 = ui->lineoffset2->text();
    offset2_double = text_offset2.toDouble();
    offset2_double = offset2_double * 9935 ;//* 2;
    offset2 = (short) offset2_double;
//*************cyclic ratio*********
    if(ui->radioSquare1->isChecked()){
        text_cyclicRatio1 = ui->CyclicRatio1->text();
        short_cyclicRatio1 = text_cyclicRatio1.toShort();
        cyclicRatio1 = short_cyclicRatio1*(655);

    }
    if(ui->radioSquare2->isChecked()){
        text_cyclicRatio2 = ui->CyclicRatio2->text();
        short_cyclicRatio2 = text_cyclicRatio2.toShort();
        cyclicRatio2 = short_cyclicRatio2*(655);
    }
//*************frequency*********
        textFreq = ui->linefreq1->text(); //get freq value into text
        freq_double = textFreq.toDouble(); //change it into double
        this->freq_int1 = textFreq.toInt(); //change text into int

        textFreq2 = ui->linefreq2->text(); //get freq value into text
        this->freq_int2 = textFreq2.toInt(); //change text into int

        std::cout<<"freq2 : "<<freq_int2<<std::endl;


    if(ui->radioButtonHz1->isChecked()){
        unit = " Hz";
        freq_double = freq_double * 1.0;
        freq_int1 = freq_int1 *1;
        this->ok1 = true;
    }if(ui->radioButtonkHz1->isChecked()){
        unit = " KHz";
       freq_double = freq_double  * 1000.0;
       freq_int1 = freq_int1 *1000;
        this->ok1 = true;
    }if(ui->radioButtonmHz1->isChecked()){
        unit = " MHz";
      freq_double = freq_double * 1000000.0;
      freq_int1 = freq_int1 *1000000;
        this->ok1 = true;
    }if(ui->radioNoise1->isChecked() || ui->radiofile1->isChecked()){
           this->ok1 = true;
    }if(!ok1){
        ui->intel->setText("Please select frequency unit");

    }

    if(ui->radioButtonHz2->isChecked()){
        unit = " Hz";
        freq_int2 = freq_int2 *1;
        this->ok2 = true;
    }if(ui->radioButtonkHz2->isChecked()){
        unit = " KHz";
       freq_double = freq_double  * 1000.0;
       freq_int2 = freq_int2 *1000;
        this->ok2 = true;
    }if(ui->radioButtonmHz2->isChecked()){
        unit = " MHz";
      freq_double = freq_double * 1000000.0;
      freq_int2 = freq_int2 *1000000;
        this->ok2 = true;
    }if(ui->radioNoise2->isChecked() || ui->radiofile2->isChecked()){
           this->ok2 = true;
    }if(!ok2){
        ui->intel->setText("Please select frequency unit2");

    }

    if(ui->radiofile1->isChecked()){
        freq_int1 = ((freq_int1 *nb_coef_ram)/1525.878906);
    }else{
    freq_int1 = floor(freq_int1*42.94967296);
    }
    if(ui->radiofile2->isChecked()){
        freq_int2 = ((freq_int2 *nb_coef_ram)/1525.878906);
    }else{freq_int2 = floor(freq_int2*42.94967296);}
    ui->intel->setText(textintel);


//*************triangle ramps*********
    if(ui->radioSaw1->isChecked()){
        text_tri_freq1_1 = ui->CyclicRatio1->text();
        int_tri1 = text_tri_freq1_1.toInt();
        //freq_int1 = freq_int1 / 43;
        if(int_tri1!=0){
            tri_freq_1_1 = floor(freq_int1*(100.0/int_tri1));
            tri_freq_1_2 = floor(((freq_int1*1.0)/(100-int_tri1))*100);

            }else(textintel="Can't set 0");
    }
    if(ui->radioSaw2->isChecked()){
        text_tri_freq2_1 = ui->CyclicRatio2->text();
        int_tri2 = text_tri_freq2_1.toInt();
        if(int_tri2!=0){
        tri_freq_2_1 = floor((freq_int2*(100.0/int_tri2)));
        tri_freq_2_2 =floor((freq_int2*(100.0/(100-int_tri2))));
        }else(textintel="Can't set 0");
    }
//***************************
    ui->intel->setText(textintel);
    std::cout<<"#1"<<std::endl;
    std::cout<<"ok1 : "<<ok1<<std::endl;
    std::cout<<"ok2 : "<<ok2<<std::endl;
    if(ok2 || ok1){
       InterfaceSerie::send_on_port();
    }else return;
}
void InterfaceSerie::send_signal1(){

    int     *ptr_freq_int1,
            *ptr_f11,
            *ptr_f12;


    long    *ptr_noise1=nullptr,
            *ptr_noise11=nullptr;
    short   *ptr_ampl1,
            *ptr_off1,
            *ptr_cyclic1;
    unsigned short *ptr_nb_coef_ram;

    if(ui->radioSin1->isChecked()){
       this->waveform1 = 0x01;
    }else if (ui->radioSquare1->isChecked()){
        this->waveform1 =  0x02;
    }else if (ui->radioSaw1->isChecked()) {
        this->waveform1 = 0x03;
    }else if(ui->radioNoise1->isChecked()){
            waveform1 = 0x04;
    }else {//File
        waveform1 = 0x05;
    }



    ptr_freq_int1 = &(this->freq_int1);
    ptr_ampl1 = &(this->amplitude1);
    ptr_off1 = &(this->offset1);
    ptr_cyclic1 = &(this->cyclicRatio1);
    ptr_f11 = &(this->tri_freq_1_1);
    ptr_f12 = &(this->tri_freq_1_2);
    ptr_nb_coef_ram = &(this->nb_coef_ram);


    if(waveform1==0x04){//Noise
        long noise1,noise11;
        do{
            noise1 = QRandomGenerator::global()->generate();
            noise11 = QRandomGenerator::global()->generate();

        }while (noise1==0);
        ptr_noise1=&(noise1);
        ptr_noise11=&(noise11);
    }

    unsigned char part10=0,part11=0,part12=0,part13=0;
    //convert a short into 2 char
    unsigned char ampl10=0,ampl11=0,
                  off10=0,off11=0,
                  cycl10=0,cycl11=0;

    unsigned char   tri110=0,tri111=0,tri112=0,tri113=0,
                    tri120=0,tri121=0,tri122=0,tri123=0;

    unsigned char   noi10=0,noi11=0,noi12=0,noi13=0,noi14=0,noi15=0,noi16=0,noi17=0;

    unsigned char ram10=0,ram11=0;

    unsigned char *ptrchar1 = (unsigned char *) ptr_freq_int1;

    unsigned char *ptrchar_ampl1 = (unsigned char *) ptr_ampl1;

    unsigned char *ptrchar_off1 = (unsigned char *) ptr_off1;

    unsigned char *ptrchar_cycl1 = (unsigned char *) ptr_cyclic1;

    unsigned char *ptrchar_tri11 = (unsigned char *) ptr_f11;
    unsigned char *ptrchar_tri12 = (unsigned char *) ptr_f12;

    unsigned char *ptrchar_noise1 = (unsigned char *) ptr_noise1;
    unsigned char *ptrchar_noise11 = (unsigned char *) ptr_noise11;

    unsigned char *ptrchar_ram = (unsigned char *) ptr_nb_coef_ram;


    //ram
    ram10 = *ptrchar_ram;
    ram11 = *(ptrchar_ram+1);


    //freq
    part10 = *ptrchar1;
    part11 = *(ptrchar1+1);
    part12 = *(ptrchar1+2);
    part13 = *(ptrchar1+3);


    //ampl
    ampl10 = *ptrchar_ampl1;
    ampl11 = *(ptrchar_ampl1+1);

    //offset
    off10 = *ptrchar_off1;
    off11 = *(ptrchar_off1+1);

   //tri : f1 and f2
    if (waveform1==3){

    tri110 = *ptrchar_tri11;
    tri111 = *(ptrchar_tri11+1);
    tri112 = *(ptrchar_tri11+2);
    tri113 = *(ptrchar_tri11+3);

    tri120 = *ptrchar_tri12;
    tri121 = *(ptrchar_tri12+1);
    tri122 = *(ptrchar_tri12+2);
    tri123 = *(ptrchar_tri12+3);
    }

     if (waveform1==0x02){//square : cyclic ratio
        cycl10 = *ptrchar_cycl1;
        cycl11 = *(ptrchar_cycl1+1);
    }
    if (waveform1==0x04){//noise
        noi10 = *ptrchar_noise1;
        noi11 = *(ptrchar_noise1+1);
        noi12 = *(ptrchar_noise1+2);
        noi13 = *(ptrchar_noise1+3);
        noi14 = *ptrchar_noise11;
        noi15 = *(ptrchar_noise11+1);
        noi16 = *(ptrchar_noise11+2);
        noi17 = *(ptrchar_noise11+3);
    }

    RS232_SendByte(cport_nr,  this->waveform1); //Send the byte through the serial port
    wait(100000);

    short *ptr_tab=nullptr;

    unsigned char tab1=0,tab2=0;
    unsigned char *ptrchar_tab;
    ptrchar_tab = (unsigned char *) ptr_tab;
    int i=0;

    switch (waveform1)
    {
        case 1 :
                    RS232_SendByte(cport_nr,  part10);wait(100000);

                    RS232_SendByte(cport_nr,  part11);wait(100000);

                    RS232_SendByte(cport_nr,  part12);wait(100000);

                    RS232_SendByte(cport_nr,  part13);wait(100000);


                    RS232_SendByte(cport_nr,  off10);wait(100000);

                    RS232_SendByte(cport_nr,  off11);wait(100000);

                    //amplitude
                    RS232_SendByte(cport_nr,  ampl10);wait(100000);

                    RS232_SendByte(cport_nr,  ampl11);wait(100000);
                    break;

    case 2 :
        RS232_SendByte(cport_nr,  part10);wait(100000);

        RS232_SendByte(cport_nr,  part11);wait(100000);

        RS232_SendByte(cport_nr,  part12);wait(100000);

        RS232_SendByte(cport_nr,  part13);wait(100000);


        RS232_SendByte(cport_nr,  off10);wait(100000);

        RS232_SendByte(cport_nr,  off11);wait(100000);

        //amplitude
        RS232_SendByte(cport_nr,  ampl10);wait(100000);

        RS232_SendByte(cport_nr,  ampl11);wait(100000);


        RS232_SendByte(cport_nr,  cycl10);wait(100000);

        RS232_SendByte(cport_nr,  cycl11);wait(100000);
        break;

    case 3 :

        RS232_SendByte(cport_nr,  tri110);wait(100000);

        RS232_SendByte(cport_nr,  tri111);wait(100000);

        RS232_SendByte(cport_nr,  tri112);wait(100000);

        RS232_SendByte(cport_nr,  tri113);wait(100000);


        RS232_SendByte(cport_nr,  off10);wait(100000);

        RS232_SendByte(cport_nr,  off11);wait(100000);


        RS232_SendByte(cport_nr,  ampl10);wait(100000);

        RS232_SendByte(cport_nr,  ampl11);wait(100000);


        RS232_SendByte(cport_nr,  tri120);wait(100000);

        RS232_SendByte(cport_nr,  tri121);wait(100000);

        RS232_SendByte(cport_nr,  tri122);wait(100000);

        RS232_SendByte(cport_nr,  tri123);wait(100000);
        break;

    case 4 :
        RS232_SendByte(cport_nr,  noi10);wait(100000);

        RS232_SendByte(cport_nr,  noi11);wait(100000);

        //RS232_SendByte(cport_nr,  noi12);wait(100000);

       // RS232_SendByte(cport_nr,  noi13);wait(100000);

        RS232_SendByte(cport_nr,  noi14);wait(100000);

        RS232_SendByte(cport_nr,  noi15);wait(100000);

       // RS232_SendByte(cport_nr,  noi16);wait(100000);

       // RS232_SendByte(cport_nr,  noi17);wait(100000);

        RS232_SendByte(cport_nr,  off10);wait(100000);

        RS232_SendByte(cport_nr,  off11);wait(100000);


        RS232_SendByte(cport_nr,  ampl10);wait(100000);

        RS232_SendByte(cport_nr,  ampl11);wait(100000);
        break;

    case 5 :


        RS232_SendByte(cport_nr,  part10);wait(100000);

        RS232_SendByte(cport_nr,  part11);wait(100000);

        RS232_SendByte(cport_nr,  part12);wait(100000);

        RS232_SendByte(cport_nr,  part13);wait(100000);

        RS232_SendByte(cport_nr,  ram10);wait(100000);

        RS232_SendByte(cport_nr,  ram11);wait(100000);

        ui->intel->setText("Sending...");
        for (i = 0; i <= nb_coef_ram; ++i) {
                        //std::cout<<"*1*"<<std::endl;
            ptr_tab = &(tab_user_coef1[i]);
                        //std::cout<<"*2*"<<std::endl;
            ptrchar_tab = (unsigned char *) ptr_tab;
                        //std::cout<<"*2-2*"<<std::endl;
            tab1 = *(ptrchar_tab);
                        //std::cout<<"*3*"<<std::endl;
            tab2 = *(ptrchar_tab + 1);
                        //std::cout<<"*4*"<<std::endl;
            RS232_SendByte(cport_nr,tab1);
                        //std::cout<<"*5*"<<std::endl;
            RS232_SendByte(cport_nr,tab2);wait(100);
                        //std::cout<<"*6*"<<std::endl;
            ui->progressBar->setValue(i*100/nb_coef_ram);

        }
        RS232_SendByte(cport_nr,  off10);wait(100000);

        RS232_SendByte(cport_nr,  off11);wait(100000);

            //amplitude
        RS232_SendByte(cport_nr,  ampl10);wait(100000);

        RS232_SendByte(cport_nr,  ampl11);wait(100000);
        ui->intel->setText("Done");
        break;


    default:
        std::cout<<"error in the signal type"<<std::endl;
        break;
    }
}
void InterfaceSerie::send_signal2(){
    int     *ptr_freq_int2,
            *ptr_f21,
            *ptr_f22;
    long    *ptr_noise2=nullptr,
            *ptr_noise22=nullptr;
    short   *ptr_ampl2,
            *ptr_off2,
            *ptr_cyclic2;
    unsigned short *ptr_nb_coef_ram2;


    if(ui->radioSin2->isChecked()){
       this->waveform2 = 0x01;
    }else if (ui->radioSquare2->isChecked()){
        this->waveform2 =  0x02;
    }else if (ui->radioSaw2->isChecked()) {
        this->waveform2 = 0x03;
    }else if (ui->radioNoise2->isChecked()){
        waveform2 = 0x04;//noise
    }else{
        waveform2 = 0x05;
    }

    ptr_freq_int2 = &(this->freq_int2);

    ptr_ampl2 = &(this->amplitude2);

    ptr_off2 = &(this->offset2);

    ptr_cyclic2 = &(this->cyclicRatio2);

    ptr_f21 = &(this->tri_freq_2_1);
    ptr_f22 = &(this->tri_freq_2_2);

    ptr_nb_coef_ram2 = &(this->nb_coef_ram2);


    if(waveform2==0x04){
        long noise2,noise22;
        do{
            noise2= QRandomGenerator::global()->generate();
            noise22= QRandomGenerator::global()->generate();

        }while (noise2==0);
        ptr_noise2=&(noise2);
        ptr_noise22=&(noise22);

    }
//convert a int into 4 char/home/boris/Documents/ENSIL/4a/projet/vhdl2020/Projet v2 2020/Projet v2 - debug 3/project_02.srcs/sources_1/new/Gen1.vhd
    unsigned char part20,part21,part22,part23;
    //convert a short into 2 char
    unsigned char ampl20,ampl21,
                  off20,off21,
                  cycl20 = '\0',cycl21 = '\0';

    unsigned char   tri210 = '\0',tri211 = '\0',tri212 = '\0',tri213 = '\0',
                    tri220 = '\0',tri221 = '\0',tri222 = '\0',tri223 = '\0';

    unsigned char ram20=0,ram21=0;

    unsigned char   noi20 = '\0',noi21 = '\0',noi22 = '\0',noi23 = '\0',noi24 = '\0',noi25 = '\0',noi26 = '\0',noi27 = '\0';
    unsigned char *ptrchar2 = (unsigned char *) ptr_freq_int2;

    unsigned char *ptrchar_ampl2 = (unsigned char *) ptr_ampl2;

    unsigned char *ptrchar_off2 = (unsigned char *) ptr_off2;

    unsigned char *ptrchar_cycl2 = (unsigned char *) ptr_cyclic2;

    unsigned char *ptrchar_tri21 = (unsigned char *) ptr_f21;
    unsigned char *ptrchar_tri22 = (unsigned char *) ptr_f22;

    unsigned char *ptrchar_noise2 = (unsigned char *) ptr_noise2;
    unsigned char *ptrchar_noise22 = (unsigned char *) ptr_noise22;

    unsigned char *ptrchar_ram2 = (unsigned char *) ptr_nb_coef_ram2;


    ram20 = *ptrchar_ram2;
    ram21 = *(ptrchar_ram2+1);

//freq

    part23 = *(ptrchar2+3);
    part22 = *(ptrchar2+2);
    part21 = *(ptrchar2+1);
    part20 = *ptrchar2;
//ampl
    ampl20 = *(ptrchar_ampl2);
    ampl21 = *(ptrchar_ampl2+1);
//offset

    off20 = *(ptrchar_off2);
    off21 = *(ptrchar_off2+1);
//tri : f1 and f2
    if(waveform2==3) {
                    tri213 = *(ptrchar_tri21+3);
                    tri212 = *(ptrchar_tri21+2);
                    tri211 = *(ptrchar_tri21+1);
                    tri210 = *ptrchar_tri21;

                    tri223 = *(ptrchar_tri22+3);
                    tri222 = *(ptrchar_tri22+2);
                    tri221 = *(ptrchar_tri22+1);
                    tri220 = *ptrchar_tri22;
        }
    if(waveform2==2){
        //square : cyclic ratio
                cycl20 = *(ptrchar_cycl2);
                cycl21 = *(ptrchar_cycl2+1);
        }
    if(waveform2==4){
       //noise
                noi20 = *(ptrchar_noise2);
                noi21 = *(ptrchar_noise2+1);
                noi22 = *(ptrchar_noise2+2);
                noi23 = *(ptrchar_noise2+3);
                noi24 = *(ptrchar_noise22);
                noi25 = *(ptrchar_noise22+1);
                noi26 = *(ptrchar_noise22+2);
                noi27 = *(ptrchar_noise22+3);
       }



    RS232_SendByte(cport_nr,waveform2);
    wait(100000);

    short *ptr_tab2=nullptr;

    unsigned char tab1=0,tab2=0;
    unsigned char *ptrchar_tab2;
    ptrchar_tab2 = (unsigned char *) ptr_tab2;
    int i=0;
    switch (waveform2) {

    case 1 :
    //sending frequency
            RS232_SendByte(cport_nr,  part20);
            wait(100000);
            RS232_SendByte(cport_nr,  part21);
            wait(100000);
            RS232_SendByte(cport_nr,  part22);
            wait(100000);
            RS232_SendByte(cport_nr,  part23);

            //offset
            RS232_SendByte(cport_nr,  off20);
            wait(100000);
            RS232_SendByte(cport_nr,  off21);
            wait(100000);

            //amplitude
            RS232_SendByte(cport_nr,  ampl20);
            wait(100000);
            RS232_SendByte(cport_nr,  ampl21);
            wait(100000);
        break;
      case 2 :
        RS232_SendByte(cport_nr,  part20);
        wait(100000);
        RS232_SendByte(cport_nr,  part21);
        wait(100000);
        RS232_SendByte(cport_nr,  part22);
        wait(100000);
        RS232_SendByte(cport_nr,  part23);

        //offset
        RS232_SendByte(cport_nr,  off20);
        wait(100000);
        RS232_SendByte(cport_nr,  off21);
        wait(100000);

        //amplitude
        RS232_SendByte(cport_nr,  ampl20);
        wait(100000);
        RS232_SendByte(cport_nr,  ampl21);
        wait(100000);

        RS232_SendByte(cport_nr,  cycl20);
        wait(100000);
        RS232_SendByte(cport_nr,  cycl21);
        wait(100000);
        break;

        case 3 :RS232_SendByte(cport_nr,  tri210);
                wait(100000);
                RS232_SendByte(cport_nr,  tri211);
                wait(100000);
                RS232_SendByte(cport_nr,  tri212);
                wait(100000);
                RS232_SendByte(cport_nr,  tri213);
                wait(100000);

                RS232_SendByte(cport_nr,  off20);
                wait(100000);
                RS232_SendByte(cport_nr,  off21);
                wait(100000);

                //amplitude
                RS232_SendByte(cport_nr,  ampl20);
                wait(100000);
                RS232_SendByte(cport_nr,  ampl21);
                wait(100000);

                RS232_SendByte(cport_nr,  tri220);
                wait(100000);
                RS232_SendByte(cport_nr,  tri221);
                wait(100000);
                RS232_SendByte(cport_nr,  tri222);
                wait(100000);
                RS232_SendByte(cport_nr,  tri223);
                wait(100000);
        break;

    case 4:     RS232_SendByte(cport_nr,  noi20);
                wait(100000);
                RS232_SendByte(cport_nr,  noi21);
                wait(100000);
                /*RS232_SendByte(cport_nr,  noi22);
                wait(100000);
                RS232_SendByte(cport_nr,  noi23);wait(100000);*/
                RS232_SendByte(cport_nr,  noi24);wait(100000);
                RS232_SendByte(cport_nr,  noi25);wait(100000);
               /* RS232_SendByte(cport_nr,  noi26);wait(100000);
                RS232_SendByte(cport_nr,  noi27);wait(100000);*/
                RS232_SendByte(cport_nr,  off20);
                wait(100000);
                RS232_SendByte(cport_nr,  off21);
                wait(100000);

                RS232_SendByte(cport_nr,  ampl20);wait(100000);
                RS232_SendByte(cport_nr,  ampl21);wait(100000);
        break;

    case 5 :;

        RS232_SendByte(cport_nr,  part20);wait(100000);

        RS232_SendByte(cport_nr,  part21);wait(100000);

        RS232_SendByte(cport_nr,  part22);wait(100000);

        RS232_SendByte(cport_nr,  part23);wait(100000);

        RS232_SendByte(cport_nr,  ram20);wait(100000);

        RS232_SendByte(cport_nr,  ram21);wait(100000);


        for (i = 0; i <= nb_coef_ram2; ++i) {
                        //std::cout<<"*1*"<<std::endl;
            ptr_tab2 = &(tab_user_coef2[i]);
                        //std::cout<<"*2*"<<std::endl;
            ptrchar_tab2 = (unsigned char *) ptr_tab2;
                        //std::cout<<"*2-2*"<<std::endl;
            tab1 = *(ptrchar_tab2);
                        //std::cout<<"*3*"<<std::endl;
            tab2 = *(ptrchar_tab2 + 1);
                        //std::cout<<"*4*"<<std::endl;
            RS232_SendByte(cport_nr,tab1);
                        //std::cout<<"*5*"<<std::endl;
            RS232_SendByte(cport_nr,tab2);wait(100);
                        //std::cout<<"*6*"<<std::endl;
            ui->progressBar2->setValue(i*100/nb_coef_ram2);

        }


        RS232_SendByte(cport_nr,  off20);wait(100000);

        RS232_SendByte(cport_nr,  off21);wait(100000);

            //amplitude
        RS232_SendByte(cport_nr,  ampl20);wait(100000);

        RS232_SendByte(cport_nr,  ampl21);wait(100000);
        break;


    default:std::cout<<"error in sig_sel2"<<std::endl;break;
    }

}
void InterfaceSerie::send_on_port(){

        int bdrate=115200;       // 115200 baud
        QString cport_text;
        unsigned char Signal_selected=0;
        char mode[]={'8','N','1',0}; //send type 8N1 (8 data, no parity, 1 stop bit)

        cport_text=ui->portnumber->text();

        cport_nr = cport_text.toInt();


//****************************opening the comport*******************************
        ui->intel->setText("Sending");
        if(RS232_OpenComport(cport_nr, bdrate, mode,0))
        {
            ui->intel->setText("Cannot open comport");
        }

        //first send : ready signal
        RS232_SendByte(cport_nr,  0x00);
        wait(100000);



        //then, signals selected
        if((ui->signal1_en->isChecked()) && ((ui->signal2_en->isChecked()))){
            Signal_selected = 3;
            ui->intel->setText("Signal  1&2 selected");

        }
        else if((ui->signal2_en->isChecked())&& !((ui->signal1_en->isChecked()))){
            Signal_selected = 2;
            ui->intel->setText("Signal 2 selected");


        }else {
            Signal_selected = 1;
            ui->intel->setText("Signal 1 selected");


        }        
        RS232_SendByte(cport_nr,  Signal_selected);
        wait(100000);

        switch (Signal_selected) {

        case 1 :
            ui->intel->setText("Sending Signal 1");
            InterfaceSerie::send_signal1();
            RS232_SendByte(cport_nr,  0x00);
            //wait(100000);
            ui->intel->setText("Done");

            break;
        case 2 :
            ui->intel->setText("Sending Signal 2");
            InterfaceSerie::send_signal2();
            RS232_SendByte(cport_nr,  0x00);
            wait(100000);
            ui->intel->setText("Done");
            break;

        case 3 :
            ui->intel->setText("Sending Signal 1");
            InterfaceSerie::send_signal1();
            ui->intel->setText("Done 1");
            RS232_SendByte(cport_nr,  0x00);

            ui->intel->setText("Sending Signal 2");
            InterfaceSerie::send_signal2();
            RS232_SendByte(cport_nr,  0x00);
            ui->intel->setText("Done");
            break;


        default: std::cout<<"error in signal selection"<<std::endl;
            break;
        }


        //channel Selector
        int index1 = ui->comboBox1->currentIndex();
        channel1 = ((unsigned char) index1)+1;

        int index2 = ui->comboBox_2->currentIndex();
        channel2 = ((unsigned char) index2)+1;
        channel2 = channel2 * 16;//4 left-shifts
        channel1 = channel1 | channel2;//logical OR (MSBs : chan2, LSBs : chan1)


        RS232_SendByte(cport_nr,  channel1);
        wait(100000);

        RS232_SendByte(cport_nr,  0x00);
        wait(100000);
        RS232_SendByte(cport_nr,  0x00);
        wait(100000);
        //closing port
        RS232_CloseComport(cport_nr);
    //     ************** sending over ****************

}

void InterfaceSerie::on_ButtonScan_clicked()
{
    int i=0,j=0,ok[36],bdrate=115200,ok2=0;
    char mode[]={'8','N','1',0};
    QString text="No ComPort found",text1,text2;


    #if defined(__linux__) || defined(__FreeBSD__)
    QString comports[38]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2","/dev/ttyS3","/dev/ttyS4","/dev/ttyS5",
                           "/dev/ttyS6","/dev/ttyS7","/dev/ttyS8","/dev/ttyS9","/dev/ttyS10","/dev/ttyS11",
                           "/dev/ttyS12","/dev/ttyS13","/dev/ttyS14","/dev/ttyS15","/dev/ttyUSB0",
                           "/dev/ttyUSB1","/dev/ttyUSB2","/dev/ttyUSB3","/dev/ttyUSB4","/dev/ttyUSB5",
                           "/dev/ttyAMA0","/dev/ttyAMA1","/dev/ttyACM0","/dev/ttyACM1",
                           "/dev/rfcomm0","/dev/rfcomm1","/dev/ircomm0","/dev/ircomm1",
                           "/dev/cuau0","/dev/cuau1","/dev/cuau2","/dev/cuau3",
                           "/dev/cuaU0","/dev/cuaU1","/dev/cuaU2","/dev/cuaU3"};

#else
    QString comports[32]={"\\\\.\\COM1",  "\\\\.\\COM2",  "\\\\.\\COM3",  "\\\\.\\COM4",
    "\\\\.\\COM5",  "\\\\.\\COM6",  "\\\\.\\COM7",  "\\\\.\\COM8",
    "\\\\.\\COM9",  "\\\\.\\COM10", "\\\\.\\COM11", "\\\\.\\COM12",
    "\\\\.\\COM13", "\\\\.\\COM14", "\\\\.\\COM15", "\\\\.\\COM16",
    "\\\\.\\COM17", "\\\\.\\COM18", "\\\\.\\COM19", "\\\\.\\COM20",
    "\\\\.\\COM21", "\\\\.\\COM22", "\\\\.\\COM23", "\\\\.\\COM24",
    "\\\\.\\COM25", "\\\\.\\COM26", "\\\\.\\COM27", "\\\\.\\COM28",
    "\\\\.\\COM29", "\\\\.\\COM30", "\\\\.\\COM31", "\\\\.\\COM32"};
#endif
   do{
       ok[i] = RS232_OpenComport(i,bdrate,mode,0);

       if(ok[i]==0){
       RS232_CloseComport(i);
       }
        i++;
   }while( (i<36));

   for(j=0;j<36;j++){
        if(ok[j]==0){
            text1 = QString::number(j);
            text2 += "N° " + text1  + " " + " ( " + comports[j] + ")" + "  |  ";
            ok2++;
            ui->intel->setText("port(s) found : \n"+text2);
        }else if(ok2==0) ui->intel->setText(text);
    }
}
void InterfaceSerie::on_pushButtonPortOk_clicked(){

    int port;
    QString port_s;

    port_s = ui->portnumber->text();
    port = port_s.toInt();


    if(ui->portnumber->text()==""){
    ui->intel->setText("Please enter a port number");
#if defined(__linux__) || defined(__FreeBSD__)
    }else if(port<0 || port >39){
        ui->intel->setText("Illegal port - please choose a number between 1 & 38");
    }
#else
    }else if(port<0 || port >33){
        ui->intel->setText("Illegal port - please choose a number between 1 & 32");
    }
#endif
    else{
        ui->chooseMode_2->show();        
        ui->intel->setText("Select the mode");
    }


}
void InterfaceSerie::on_radioSin1_clicked(){
    QString textintel="Select a frequency, an amplitude and the offset";
    ui->widgetFreqSin->show();
    ui->wigetCRatio->hide();
    ui->progressBar->hide();
    ui->WidgetUnit1->setEnabled(true);
    ui->widgetFreqline1->setEnabled(true);
    ui->widgetOff1->setEnabled(true);
     ui->linefile1->hide();
    ui->intel->setText(textintel);
}
void InterfaceSerie::on_radioSin2_clicked(){
    QString textintel="Select a frequency, an amplitude and the offset";
    ui->widgetFreqSin_2->show();
    ui->progressBar->hide();
    ui->wigetCRatio_2->hide();
    ui->WidgetFreqline2->setEnabled(true);
    ui->widgetOff2->setEnabled(true);
    ui->linefile2->hide();
    ui->progressBar2->hide();
    ui->intel->setText(textintel);
}
void InterfaceSerie::on_radioSquare1_clicked(){
    QString textintel="Select a frequency, an amplitude, the offset and the cyclic ratio";
    ui->widgetFreqSin->show();
    ui->widgetFreqline1->setEnabled(true);
    ui->widgetOff1->setEnabled(true);
    ui->wigetCRatio->show();
    ui->WidgetUnit1->setEnabled(true);
    ui->label_ratio1->setText("Cylic Ratio (1 - 100%)");
    ui->linefile1->hide();
    ui->progressBar->hide();
    ui->intel->setText(textintel);
}
void InterfaceSerie::on_radioSquare2_clicked(){
    QString textintel="Select a frequency, an amplitude, the offset and the cyclic ratio";
    ui->widgetFreqSin_2->show();
    ui->WidgetFreqline2->setEnabled(true);
    ui->widgetOff2->setEnabled(true);
    ui->wigetCRatio_2->show();
    ui->progressBar->hide();
    ui->progressBar2->hide();
    ui->linefile2->hide();
    ui->label_ratio2->setText("Cylic Ratio (1 - 100%)");
    ui->intel->setText(textintel);
}
void InterfaceSerie::on_radioSaw1_clicked(){
    ui->widgetFreqSin->show();
    ui->WidgetUnit1->setEnabled(true);
    ui->wigetCRatio->show();
    ui->widgetFreqline1->setEnabled(true);
    ui->progressBar->hide();
    ui->widgetOff1->setEnabled(true);
    ui->linefile1->hide();
    ui->label_ratio1->setText("Peak (0 - 100)");
    ui->intel->setText("Select a frequency, an amplitude, the offset and the peak position");
}
void InterfaceSerie::on_radioSaw2_clicked(){
    ui->widgetFreqSin_2->show();
    ui->wigetCRatio_2->show();
    ui->WidgetFreqline2->setEnabled(true);
    ui->widgetOff2->setEnabled(true);
    ui->label_ratio2->setText("Peak (0 - 100)");
    ui->linefile2->hide();
    ui->progressBar2->hide();
    ui->intel->setText("Select a frequency, an amplitude, the offset and the peak position");
}
void InterfaceSerie::on_radioNoise1_clicked(){
    ui->wigetCRatio->hide();
    ui->widgetFreqSin->show();
    ui->widgetAmp1->setEnabled(true);
    ui->widgetFreqline1->setDisabled(true);
    ui->WidgetUnit1->setDisabled(true);
    ui->widgetOff1->setEnabled(true);
    ui->linefile1->hide();
    ui->intel->setText("");
    ui->progressBar->hide();
}
void InterfaceSerie::on_radioNoise2_clicked(){
    ui->wigetCRatio_2->hide();
    ui->widgetFreqSin_2->show();
    ui->widgetAmp2->setEnabled(true);
    ui->WidgetFreqline2->setDisabled(true);
    ui->widgetOff2->setEnabled(true);
    ui->linefile2->hide();
    ui->intel->setText("");
    ui->progressBar2->hide();
}
void InterfaceSerie::on_radiofile1_clicked(){
    ui->wigetCRatio->hide();
    ui->progressBar->show();
    ui->widgetFreqSin->show();
    ui->WidgetUnit1->setEnabled(true);
    ui->widgetOff1->setEnabled(true);
    ui->widgetFreqline1->setEnabled(true);
    ui->linefile1->show();    
    ui->intel->setText("Choose a .txt file with 65536 coefficients MAX between 0 and 65536 (1 per line)");
}
void InterfaceSerie::on_radiofile2_clicked(){
    ui->wigetCRatio_2->hide();
    ui->widgetFreqSin_2->show();
    ui->linefile2->show();
    ui->WidgetFreqline2->setEnabled(true);
    ui->widgetOff2->setEnabled(true);
    ui->progressBar2->show();
    ui->intel->setText("Choose a .txt file with 65536 coefficients MAX between 0 and 65536 (1 per line)");
}
void InterfaceSerie::on_signal1_en_clicked(bool checked){
    if(checked){
        ui->widget_signal1->show();
        ui->widgetchannel1->show();
        ui->button_Send->show();
    }else {
        ui->widget_signal1->hide();
        ui->widgetchannel1->hide();
    }
    if(ui->signal1_en->isChecked() && ui->signal2_en->isChecked()){
        ui->comboBox1->addItem("Signal 2");
        ui->comboBox1->addItem("Signal 1+2");
        ui->comboBox1->addItem("Signal 1-2");
        ui->comboBox1->addItem("Signal 2-1");
        ui->comboBox1->addItem("Signal 1x2");
        ui->comboBox_2->addItem("Signal 1");
        ui->comboBox_2->addItem("Signal 1+2");
        ui->comboBox_2->addItem("Signal 1-2");
        ui->comboBox_2->addItem("Signal 2-1");
        ui->comboBox_2->addItem("Signal 1x2");

    } else{
        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);
        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);
    }
    if(!(ui->signal1_en->isChecked() || ui->signal2_en->isChecked())){
        ui->button_Send->hide();
    }
}
void InterfaceSerie::on_signal2_en_clicked(bool checked){

    if(checked){
    ui->widget_signal2->show();
    ui->widgetchannel2->show();
    ui->button_Send->show();

    }else{
        ui->widget_signal2->hide();
        ui->widgetchannel2->hide();
    }
    if(ui->signal1_en->isChecked() && ui->signal2_en->isChecked()){
        ui->comboBox_2->addItem("Signal 1");
        ui->comboBox_2->addItem("Signal 1+2");
        ui->comboBox_2->addItem("Signal 1-2");
        ui->comboBox_2->addItem("Signal 2-1");
        ui->comboBox_2->addItem("Signal 1x2");
        ui->comboBox1->addItem("Signal 2");
        ui->comboBox1->addItem("Signal 1+2");
        ui->comboBox1->addItem("Signal 1-2");
        ui->comboBox1->addItem("Signal 2-1");
        ui->comboBox1->addItem("Signal 1x2");
    }else{

        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);
        ui->comboBox_2->removeItem(1);

        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);
        ui->comboBox1->removeItem(1);

    }
    if(!(ui->signal1_en->isChecked() || ui->signal2_en->isChecked())){
        ui->button_Send->hide();
    }
}
void InterfaceSerie::on_RadioSignalGen_clicked(){
    ui->widgetsignalEN->show();
    ui->gridBode->hide();
    ui->button_OkBode->hide();
    ui->intel->setText("");
}
void InterfaceSerie::on_RadioBode_clicked(){
    ui->gridBode->show();
    ui->button_OkBode->show();
    ui->widget_signal1->hide();
    ui->widget_signal2->hide();
    ui->widgetchannel1->hide();
    ui->widgetchannel2->hide();
    ui->widgetsignalEN->hide();
    ui->wigetCRatio->hide();
    ui->wigetCRatio_2->hide();
    ui->button_Send->hide();
    ui->widgetFreqSin->hide();
    ui->widgetFreqSin_2->hide();
    ui->intel->setText("Choose a start, a stop and the step frequency");
}
void InterfaceSerie::on_button_OkBode_clicked(){

    QString text_start, text_stop,text_step;
    int start,stop,step,start42,step42,stop42,*ptr_step,*ptr_start,*ptr_stop;
    unsigned char start01,start02,start03,start04,
                  step01, step02, step03, step04,
                  stop01,stop02,stop03,stop04;
    char mode[]={'8','N','1',0};
    int bdrate=115200;       // 115200 baud
    QString cport_text;



    cport_text=ui->portnumber->text();
    cport_nr = cport_text.toInt();
    int nb_received=0;
    unsigned char buf[4096];
    for(int a =0;a<4096;a++){
        buf[a]=0;
    }

    //**********************variables recevant les données
    int amplitude_sinus=0,amplitude_dut=0;
    int phase=0;

    text_start = ui->lineStart->text();
    text_stop = ui->lineStop->text();
    text_step = ui->line_step->text();
    start = text_start.toInt();
    stop = text_stop.toInt();
    step = text_step.toInt();
    if(ui->radioButtonHzBodestart->isChecked()){
        start = start * 1;
    }else if(ui->radioButtonkHzBodestart->isChecked()){
        start = start * 1000;
    }else if(ui->radioButtonmHzBodestart->isChecked()){
        start = start * 1000000;
    }
    if(ui->radioButtonHzBodestop->isChecked()){
        stop = stop * 1;
    }else if(ui->radioButtonkHzBodestop->isChecked()){
        stop = stop * 1000;
    }else if(ui->radioButtonmHzBodestop->isChecked()){
        stop = stop * 1000000;
    }
    if(ui->radioButtonHzBodestep->isChecked()){
          step = step * 1;
    }else if(ui->radioButtonkHzBodestep->isChecked()){
          step = step * 1000;
    }else if (ui->radioButtonmHzBodestep->isChecked()){
          step = step * 1000000;
    }

    start42 = floor(start * 42.94967296);
    step42 = floor(step * 42.94967296);
    stop42 = floor(stop * 42.94967296);


    int arret = 0;
    arret = ((stop-start)+step)/step;


 //********************************************************************
    if (start > stop){
            ui->intel->setText("Please select a start frequency lower than the stop frequency");
    }else{


            ptr_start = &(start42);
            ptr_stop = &(stop42);
            ptr_step = &(step42);

            unsigned char *ptr_char_start = (unsigned char *) ptr_start;

            start01 = *(ptr_char_start);
            start02 = *(ptr_char_start+1);
            start03 = *(ptr_char_start+2);
            start04 = *(ptr_char_start+3);

            unsigned char *ptr_char_stop = (unsigned char *) ptr_stop;

            stop01 = *(ptr_char_stop);
            stop02 = *(ptr_char_stop+1);
            stop03 = *(ptr_char_stop+2);
            stop04 = *(ptr_char_stop+3);

            unsigned char *ptr_char_step = (unsigned char *) ptr_step;

            step01 = *(ptr_char_step);
            step02 = *(ptr_char_step+1);
            step03 = *(ptr_char_step+2);
            step04 = *(ptr_char_step+3);


//***************************************************************
            RS232_OpenComport(cport_nr, bdrate, mode,0);

            RS232_SendByte(cport_nr,0);//rdy signal
            wait(100000);
            RS232_SendByte(cport_nr,4);//function selector (Bode)
            wait(100000);
            RS232_SendByte(cport_nr,1);//rdy signal Bode
            wait(100000);

            RS232_SendByte(cport_nr,start01);wait(100000);
            RS232_SendByte(cport_nr,start02);wait(100000);
            RS232_SendByte(cport_nr,start03);wait(100000);
            RS232_SendByte(cport_nr,start04);wait(100000);

            RS232_SendByte(cport_nr,step01);wait(100000);
            RS232_SendByte(cport_nr,step02);wait(100000);
            RS232_SendByte(cport_nr,step03);wait(100000);
            RS232_SendByte(cport_nr,step04);wait(100000);

            RS232_SendByte(cport_nr,stop01);wait(100000);
            RS232_SendByte(cport_nr,stop02);wait(100000);
            RS232_SendByte(cport_nr,stop03);wait(100000);
            RS232_SendByte(cport_nr,stop04);wait(100000);
            RS232_SendByte(cport_nr,0);wait(1000000);
            RS232_SendByte(cport_nr,1);wait(1000000);


//*************************************************************
          /*  RS232_SendByte(cport_nr,0);wait(100000);
            RS232_SendByte(cport_nr,4);wait(100000);
            RS232_SendByte(cport_nr,1);wait(100000);
            RS232_SendByte(cport_nr,1);wait(100000);
            RS232_SendByte(cport_nr,2);wait(100000);
            RS232_SendByte(cport_nr,4);wait(100000);
            RS232_SendByte(cport_nr,8);wait(100000);

            RS232_SendByte(cport_nr,16);wait(100000);
            RS232_SendByte(cport_nr,32);wait(100000);
            RS232_SendByte(cport_nr,7);wait(100000);
            RS232_SendByte(cport_nr,8);wait(100000);*/


            short dut_in,dut_out,*ptr_dut_in,*ptr_dut_out;

            ptr_dut_in = &(dut_in);
            ptr_dut_out = &(dut_out);            

            QLineSeries *series = new QLineSeries();
            QLineSeries *series_phase = new QLineSeries();


            unsigned char tab_ech[arret*9];
            int b=0;

            do{
                    nb_received = RS232_PollComport(cport_nr,buf,4096);

                    if(nb_received>0){
                       for(int a=0;a<nb_received;a++){
                           tab_ech[b]=buf[a];
                           b++;
                       }

                    }


              }while(b!=(arret*9));

           RS232_CloseComport(cport_nr);
           int i=0;
           unsigned char phase_end;

           for (int c=0;c<b;c+=9) {
               amplitude_sinus = tab_ech[c] | tab_ech[c+1]*256;
               amplitude_dut = tab_ech[c+2] | tab_ech[c+3]*256;
               phase = buf[c+4] |buf[c+5]*256 | buf[c+6]*65536 | buf[c+7]*16777216;
               phase_end = buf[c+8];
                phase = -phase*(360/4294967296.0);                
               if((buf[c+7]&0x80)==0x80){
                phase=-phase;
               }
               series->append((start+step*i),20*log(amplitude_dut*1.0/amplitude_sinus));
               series_phase->append((start+step*i),phase);
               i++;
           }

           InterfaceSerie::graph(series,series_phase,start,stop);

        }

}

void InterfaceSerie::graph(QLineSeries *series, QLineSeries *series1,int min, int max){

    QChart *chart = new QChart();
    chart->legend()->hide();
   // chart->setTitle("Bode chart - Gain");
    //chart->addSeries(series);

    QChart *chart1 = new QChart();    
    chart1->legend()->hide();
   // chart1->setTitle("Bode chart - Phase");
    //chart1->addSeries(series1);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->addSeries(series);
    QChartView *chartView1 = new QChartView(chart1);
    chartView1->setRenderHint(QPainter::Antialiasing);
    chartView1->chart()->addSeries(series1);


    QLogValueAxis *axisX = new QLogValueAxis();

    axisX->setTitleText("Frequency (Hz)");
    axisX->setLabelFormat("%g");
    axisX->setBase(10.0);
    axisX->setMinorTickCount(-1);
    chart->addAxis(axisX, Qt::AlignBottom);
    axisX->setRange(min,max);


    QLogValueAxis *axisX1 = new QLogValueAxis();
    axisX1->setTitleText("Frequency (Hz)");
    axisX1->setLabelFormat("%g");
    axisX1->setBase(10.0);
    axisX1->setMinorTickCount(-1);
    chart1->addAxis(axisX1, Qt::AlignBottom);
    axisX1->setRange(min,max);




    QValueAxis *axisY = new QValueAxis();
    //axisY->setMin(-10);
    //axisY->setMax(2);
    axisY->setTitleText("Gain (dB)");
    axisY->setLabelFormat("%1.1lf");
    chart->addAxis(axisY, Qt::AlignLeft);


    QValueAxis *axisY_phase = new QValueAxis();
    axisY_phase->setMin(-180);
    axisY_phase->setMax(180);
    axisY_phase->setTitleText("Phase (°)");
    axisY_phase->setLabelFormat("%g");
    chart1->addAxis(axisY_phase, Qt::AlignLeft);


    series->attachAxis(axisX);
    series->attachAxis(axisY);
    series1->attachAxis(axisX1);
    series1->attachAxis(axisY_phase);


     QFrame* centralFrame = new QFrame();

     QVBoxLayout* myLayout = new QVBoxLayout;
     myLayout->addWidget(chartView,Qt::AlignBottom);
     myLayout->addWidget(chartView1,Qt::AlignBottom);

     centralFrame->setLayout(myLayout);



       window.setCentralWidget(centralFrame);
       window.resize(800, 600);
       window.setWindowTitle("Bode Chart");
       window.show();


}

