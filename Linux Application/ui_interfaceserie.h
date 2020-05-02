/********************************************************************************
** Form generated from reading UI file 'interfaceserie.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACESERIE_H
#define UI_INTERFACESERIE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceSerie
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *portnumber;
    QPushButton *pushButtonPortOk;
    QGroupBox *widget_signal2;
    QWidget *widgetFreqSin_2;
    QWidget *widgetAmp2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineAmplitude2;
    QLabel *label_15;
    QFrame *line_2;
    QWidget *WidgetFreqline2;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_2;
    QLineEdit *linefreq2;
    QRadioButton *radioButtonHz2;
    QRadioButton *radioButtonkHz2;
    QRadioButton *radioButtonmHz2;
    QWidget *widgetOff2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_18;
    QLineEdit *lineoffset2;
    QLabel *label_19;
    QWidget *widgetWaveform_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QRadioButton *radioSin2;
    QRadioButton *radioSquare2;
    QRadioButton *radioSaw2;
    QRadioButton *radioNoise2;
    QRadioButton *radiofile2;
    QWidget *linefile2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QLineEdit *lineEdit_2;
    QPushButton *browse2;
    QWidget *wigetCRatio_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_ratio2;
    QLineEdit *CyclicRatio2;
    QProgressBar *progressBar2;
    QLabel *intel;
    QPushButton *button_Send;
    QGroupBox *widget_signal1;
    QWidget *widgetWaveform;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QRadioButton *radioSin1;
    QRadioButton *radioSquare1;
    QRadioButton *radioSaw1;
    QRadioButton *radioNoise1;
    QRadioButton *radiofile1;
    QWidget *wigetCRatio;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_ratio1;
    QLineEdit *CyclicRatio1;
    QWidget *widgetFreqSin;
    QWidget *widgetFreqline1;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QLineEdit *linefreq1;
    QFrame *line;
    QWidget *widgetOff1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_16;
    QLineEdit *lineOffset1;
    QLabel *label_17;
    QWidget *widgetAmp1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *lineAmplitude1;
    QLabel *label_14;
    QWidget *WidgetUnit1;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *radioButtonHz1;
    QRadioButton *radioButtonkHz1;
    QRadioButton *radioButtonmHz1;
    QWidget *linefile1;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_11;
    QLineEdit *lineEdit;
    QPushButton *browse1;
    QProgressBar *progressBar;
    QWidget *widgetsignalEN;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *signal1_en;
    QCheckBox *signal2_en;
    QPushButton *ButtonScan;
    QPushButton *button_OkBode;
    QWidget *chooseMode_2;
    QHBoxLayout *chooseMode;
    QRadioButton *RadioSignalGen;
    QRadioButton *RadioBode;
    QWidget *gridBode;
    QGridLayout *grid;
    QRadioButton *radioButtonkHzBodestart;
    QLineEdit *lineStart;
    QRadioButton *radioButtonkHzBodestop;
    QRadioButton *radioButtonHzBodestop;
    QRadioButton *radioButtonmHzBodestop;
    QLabel *label_3;
    QRadioButton *radioButtonHzBodestart;
    QLabel *label_9;
    QRadioButton *radioButtonmHzBodestart;
    QLineEdit *lineStop;
    QLabel *label_20;
    QLineEdit *line_step;
    QRadioButton *radioButtonHzBodestep;
    QRadioButton *radioButtonkHzBodestep;
    QRadioButton *radioButtonmHzBodestep;
    QWidget *widgetchannel1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QComboBox *comboBox1;
    QWidget *widgetchannel2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_13;
    QComboBox *comboBox_2;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_3;

    void setupUi(QWidget *InterfaceSerie)
    {
        if (InterfaceSerie->objectName().isEmpty())
            InterfaceSerie->setObjectName(QString::fromUtf8("InterfaceSerie"));
        InterfaceSerie->resize(841, 629);
        QIcon icon;
        icon.addFile(QString::fromUtf8("ico/eltlogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        InterfaceSerie->setWindowIcon(icon);
        widget = new QWidget(InterfaceSerie);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 70, 331, 41));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, -1, 1);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        portnumber = new QLineEdit(widget);
        portnumber->setObjectName(QString::fromUtf8("portnumber"));

        horizontalLayout_7->addWidget(portnumber);

        pushButtonPortOk = new QPushButton(widget);
        pushButtonPortOk->setObjectName(QString::fromUtf8("pushButtonPortOk"));

        horizontalLayout_7->addWidget(pushButtonPortOk);

        widget_signal2 = new QGroupBox(InterfaceSerie);
        widget_signal2->setObjectName(QString::fromUtf8("widget_signal2"));
        widget_signal2->setGeometry(QRect(40, 370, 781, 171));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        widget_signal2->setFont(font);
        widget_signal2->setAutoFillBackground(true);
        widgetFreqSin_2 = new QWidget(widget_signal2);
        widgetFreqSin_2->setObjectName(QString::fromUtf8("widgetFreqSin_2"));
        widgetFreqSin_2->setGeometry(QRect(12, 75, 761, 51));
        widgetAmp2 = new QWidget(widgetFreqSin_2);
        widgetAmp2->setObjectName(QString::fromUtf8("widgetAmp2"));
        widgetAmp2->setGeometry(QRect(410, -2, 221, 51));
        horizontalLayout_5 = new QHBoxLayout(widgetAmp2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(widgetAmp2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineAmplitude2 = new QLineEdit(widgetAmp2);
        lineAmplitude2->setObjectName(QString::fromUtf8("lineAmplitude2"));

        horizontalLayout_5->addWidget(lineAmplitude2);

        label_15 = new QLabel(widgetAmp2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_5->addWidget(label_15);

        line_2 = new QFrame(widgetFreqSin_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(393, 0, 20, 81));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        WidgetFreqline2 = new QWidget(widgetFreqSin_2);
        WidgetFreqline2->setObjectName(QString::fromUtf8("WidgetFreqline2"));
        WidgetFreqline2->setGeometry(QRect(0, 0, 391, 51));
        horizontalLayout_17 = new QHBoxLayout(WidgetFreqline2);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_2 = new QLabel(WidgetFreqline2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_11->addWidget(label_2);

        linefreq2 = new QLineEdit(WidgetFreqline2);
        linefreq2->setObjectName(QString::fromUtf8("linefreq2"));

        horizontalLayout_11->addWidget(linefreq2);


        horizontalLayout_17->addLayout(horizontalLayout_11);

        radioButtonHz2 = new QRadioButton(WidgetFreqline2);
        radioButtonHz2->setObjectName(QString::fromUtf8("radioButtonHz2"));
        radioButtonHz2->setChecked(true);

        horizontalLayout_17->addWidget(radioButtonHz2);

        radioButtonkHz2 = new QRadioButton(WidgetFreqline2);
        radioButtonkHz2->setObjectName(QString::fromUtf8("radioButtonkHz2"));

        horizontalLayout_17->addWidget(radioButtonkHz2);

        radioButtonmHz2 = new QRadioButton(WidgetFreqline2);
        radioButtonmHz2->setObjectName(QString::fromUtf8("radioButtonmHz2"));

        horizontalLayout_17->addWidget(radioButtonmHz2);

        widgetOff2 = new QWidget(widgetFreqSin_2);
        widgetOff2->setObjectName(QString::fromUtf8("widgetOff2"));
        widgetOff2->setGeometry(QRect(630, 0, 121, 51));
        horizontalLayout_12 = new QHBoxLayout(widgetOff2);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_18 = new QLabel(widgetOff2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_12->addWidget(label_18);

        lineoffset2 = new QLineEdit(widgetOff2);
        lineoffset2->setObjectName(QString::fromUtf8("lineoffset2"));

        horizontalLayout_12->addWidget(lineoffset2);

        label_19 = new QLabel(widgetOff2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_12->addWidget(label_19);

        widgetWaveform_2 = new QWidget(widget_signal2);
        widgetWaveform_2->setObjectName(QString::fromUtf8("widgetWaveform_2"));
        widgetWaveform_2->setGeometry(QRect(12, 27, 471, 43));
        horizontalLayout_9 = new QHBoxLayout(widgetWaveform_2);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(widgetWaveform_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        radioSin2 = new QRadioButton(widgetWaveform_2);
        radioSin2->setObjectName(QString::fromUtf8("radioSin2"));

        horizontalLayout_9->addWidget(radioSin2);

        radioSquare2 = new QRadioButton(widgetWaveform_2);
        radioSquare2->setObjectName(QString::fromUtf8("radioSquare2"));

        horizontalLayout_9->addWidget(radioSquare2);

        radioSaw2 = new QRadioButton(widgetWaveform_2);
        radioSaw2->setObjectName(QString::fromUtf8("radioSaw2"));

        horizontalLayout_9->addWidget(radioSaw2);

        radioNoise2 = new QRadioButton(widgetWaveform_2);
        radioNoise2->setObjectName(QString::fromUtf8("radioNoise2"));

        horizontalLayout_9->addWidget(radioNoise2);

        radiofile2 = new QRadioButton(widgetWaveform_2);
        radiofile2->setObjectName(QString::fromUtf8("radiofile2"));

        horizontalLayout_9->addWidget(radiofile2);

        linefile2 = new QWidget(widget_signal2);
        linefile2->setObjectName(QString::fromUtf8("linefile2"));
        linefile2->setGeometry(QRect(10, 130, 381, 31));
        horizontalLayout_16 = new QHBoxLayout(linefile2);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(1, 1, 1, 1);
        label_12 = new QLabel(linefile2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_16->addWidget(label_12);

        lineEdit_2 = new QLineEdit(linefile2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_16->addWidget(lineEdit_2);

        browse2 = new QPushButton(linefile2);
        browse2->setObjectName(QString::fromUtf8("browse2"));

        horizontalLayout_16->addWidget(browse2);

        wigetCRatio_2 = new QWidget(widget_signal2);
        wigetCRatio_2->setObjectName(QString::fromUtf8("wigetCRatio_2"));
        wigetCRatio_2->setGeometry(QRect(480, 30, 300, 41));
        layoutWidget = new QWidget(wigetCRatio_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 284, 29));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_ratio2 = new QLabel(layoutWidget);
        label_ratio2->setObjectName(QString::fromUtf8("label_ratio2"));

        horizontalLayout_14->addWidget(label_ratio2);

        CyclicRatio2 = new QLineEdit(layoutWidget);
        CyclicRatio2->setObjectName(QString::fromUtf8("CyclicRatio2"));

        horizontalLayout_14->addWidget(CyclicRatio2);

        progressBar2 = new QProgressBar(widget_signal2);
        progressBar2->setObjectName(QString::fromUtf8("progressBar2"));
        progressBar2->setGeometry(QRect(460, 140, 281, 21));
        progressBar2->setValue(24);
        intel = new QLabel(InterfaceSerie);
        intel->setObjectName(QString::fromUtf8("intel"));
        intel->setGeometry(QRect(70, 10, 671, 61));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        intel->setFont(font1);
        intel->setLayoutDirection(Qt::LeftToRight);
        intel->setAutoFillBackground(false);
        intel->setFrameShape(QFrame::StyledPanel);
        intel->setFrameShadow(QFrame::Plain);
        intel->setAlignment(Qt::AlignCenter);
        button_Send = new QPushButton(InterfaceSerie);
        button_Send->setObjectName(QString::fromUtf8("button_Send"));
        button_Send->setGeometry(QRect(700, 550, 88, 27));
        QPalette palette;
        QBrush brush(QColor(78, 154, 6, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        button_Send->setPalette(palette);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Carlito"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        button_Send->setFont(font2);
        widget_signal1 = new QGroupBox(InterfaceSerie);
        widget_signal1->setObjectName(QString::fromUtf8("widget_signal1"));
        widget_signal1->setEnabled(true);
        widget_signal1->setGeometry(QRect(40, 210, 784, 181));
        QFont font3;
        font3.setBold(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        widget_signal1->setFont(font3);
        widget_signal1->setAutoFillBackground(true);
        widgetWaveform = new QWidget(widget_signal1);
        widgetWaveform->setObjectName(QString::fromUtf8("widgetWaveform"));
        widgetWaveform->setGeometry(QRect(12, 27, 459, 41));
        layoutWidget1 = new QWidget(widgetWaveform);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(9, 9, 443, 27));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        radioSin1 = new QRadioButton(layoutWidget1);
        radioSin1->setObjectName(QString::fromUtf8("radioSin1"));

        horizontalLayout_8->addWidget(radioSin1);

        radioSquare1 = new QRadioButton(layoutWidget1);
        radioSquare1->setObjectName(QString::fromUtf8("radioSquare1"));

        horizontalLayout_8->addWidget(radioSquare1);

        radioSaw1 = new QRadioButton(layoutWidget1);
        radioSaw1->setObjectName(QString::fromUtf8("radioSaw1"));

        horizontalLayout_8->addWidget(radioSaw1);

        radioNoise1 = new QRadioButton(layoutWidget1);
        radioNoise1->setObjectName(QString::fromUtf8("radioNoise1"));

        horizontalLayout_8->addWidget(radioNoise1);

        radiofile1 = new QRadioButton(layoutWidget1);
        radiofile1->setObjectName(QString::fromUtf8("radiofile1"));

        horizontalLayout_8->addWidget(radiofile1);

        wigetCRatio = new QWidget(widget_signal1);
        wigetCRatio->setObjectName(QString::fromUtf8("wigetCRatio"));
        wigetCRatio->setGeometry(QRect(474, 27, 300, 41));
        layoutWidget2 = new QWidget(wigetCRatio);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 284, 29));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_ratio1 = new QLabel(layoutWidget2);
        label_ratio1->setObjectName(QString::fromUtf8("label_ratio1"));

        horizontalLayout_18->addWidget(label_ratio1);

        CyclicRatio1 = new QLineEdit(layoutWidget2);
        CyclicRatio1->setObjectName(QString::fromUtf8("CyclicRatio1"));

        horizontalLayout_18->addWidget(CyclicRatio1);

        widgetFreqSin = new QWidget(widget_signal1);
        widgetFreqSin->setObjectName(QString::fromUtf8("widgetFreqSin"));
        widgetFreqSin->setEnabled(true);
        widgetFreqSin->setGeometry(QRect(12, 70, 762, 51));
        widgetFreqSin->setInputMethodHints(Qt::ImhNone);
        widgetFreqline1 = new QWidget(widgetFreqSin);
        widgetFreqline1->setObjectName(QString::fromUtf8("widgetFreqline1"));
        widgetFreqline1->setGeometry(QRect(10, 0, 204, 51));
        horizontalLayout_10 = new QHBoxLayout(widgetFreqline1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label = new QLabel(widgetFreqline1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_10->addWidget(label);

        linefreq1 = new QLineEdit(widgetFreqline1);
        linefreq1->setObjectName(QString::fromUtf8("linefreq1"));

        horizontalLayout_10->addWidget(linefreq1);

        line = new QFrame(widgetFreqSin);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(393, 0, 20, 101));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        widgetOff1 = new QWidget(widgetFreqSin);
        widgetOff1->setObjectName(QString::fromUtf8("widgetOff1"));
        widgetOff1->setGeometry(QRect(630, 0, 131, 51));
        horizontalLayout_6 = new QHBoxLayout(widgetOff1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_16 = new QLabel(widgetOff1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Cantarell"));
        label_16->setFont(font4);

        horizontalLayout_6->addWidget(label_16);

        lineOffset1 = new QLineEdit(widgetOff1);
        lineOffset1->setObjectName(QString::fromUtf8("lineOffset1"));

        horizontalLayout_6->addWidget(lineOffset1);

        label_17 = new QLabel(widgetOff1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_6->addWidget(label_17);

        widgetAmp1 = new QWidget(widgetFreqSin);
        widgetAmp1->setObjectName(QString::fromUtf8("widgetAmp1"));
        widgetAmp1->setGeometry(QRect(410, 0, 221, 51));
        horizontalLayout_4 = new QHBoxLayout(widgetAmp1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(widgetAmp1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font4);

        horizontalLayout_4->addWidget(label_8);

        lineAmplitude1 = new QLineEdit(widgetAmp1);
        lineAmplitude1->setObjectName(QString::fromUtf8("lineAmplitude1"));

        horizontalLayout_4->addWidget(lineAmplitude1);

        label_14 = new QLabel(widgetAmp1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_4->addWidget(label_14);

        WidgetUnit1 = new QWidget(widgetFreqSin);
        WidgetUnit1->setObjectName(QString::fromUtf8("WidgetUnit1"));
        WidgetUnit1->setGeometry(QRect(220, 0, 181, 51));
        horizontalLayout_13 = new QHBoxLayout(WidgetUnit1);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        radioButtonHz1 = new QRadioButton(WidgetUnit1);
        radioButtonHz1->setObjectName(QString::fromUtf8("radioButtonHz1"));
        radioButtonHz1->setChecked(true);

        horizontalLayout_13->addWidget(radioButtonHz1);

        radioButtonkHz1 = new QRadioButton(WidgetUnit1);
        radioButtonkHz1->setObjectName(QString::fromUtf8("radioButtonkHz1"));

        horizontalLayout_13->addWidget(radioButtonkHz1);

        radioButtonmHz1 = new QRadioButton(WidgetUnit1);
        radioButtonmHz1->setObjectName(QString::fromUtf8("radioButtonmHz1"));

        horizontalLayout_13->addWidget(radioButtonmHz1);

        linefile1 = new QWidget(widget_signal1);
        linefile1->setObjectName(QString::fromUtf8("linefile1"));
        linefile1->setGeometry(QRect(10, 120, 381, 41));
        horizontalLayout_15 = new QHBoxLayout(linefile1);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_11 = new QLabel(linefile1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_15->addWidget(label_11);

        lineEdit = new QLineEdit(linefile1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_15->addWidget(lineEdit);

        browse1 = new QPushButton(linefile1);
        browse1->setObjectName(QString::fromUtf8("browse1"));

        horizontalLayout_15->addWidget(browse1);

        progressBar = new QProgressBar(widget_signal1);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(460, 130, 281, 21));
        progressBar->setValue(24);
        widgetsignalEN = new QWidget(InterfaceSerie);
        widgetsignalEN->setObjectName(QString::fromUtf8("widgetsignalEN"));
        widgetsignalEN->setGeometry(QRect(30, 150, 211, 51));
        horizontalLayout_2 = new QHBoxLayout(widgetsignalEN);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        signal1_en = new QCheckBox(widgetsignalEN);
        signal1_en->setObjectName(QString::fromUtf8("signal1_en"));

        horizontalLayout_2->addWidget(signal1_en);

        signal2_en = new QCheckBox(widgetsignalEN);
        signal2_en->setObjectName(QString::fromUtf8("signal2_en"));

        horizontalLayout_2->addWidget(signal2_en);

        ButtonScan = new QPushButton(InterfaceSerie);
        ButtonScan->setObjectName(QString::fromUtf8("ButtonScan"));
        ButtonScan->setGeometry(QRect(30, 80, 91, 27));
        button_OkBode = new QPushButton(InterfaceSerie);
        button_OkBode->setObjectName(QString::fromUtf8("button_OkBode"));
        button_OkBode->setGeometry(QRect(760, 150, 51, 27));
        chooseMode_2 = new QWidget(InterfaceSerie);
        chooseMode_2->setObjectName(QString::fromUtf8("chooseMode_2"));
        chooseMode_2->setGeometry(QRect(30, 110, 301, 41));
        chooseMode = new QHBoxLayout(chooseMode_2);
        chooseMode->setObjectName(QString::fromUtf8("chooseMode"));
        RadioSignalGen = new QRadioButton(chooseMode_2);
        RadioSignalGen->setObjectName(QString::fromUtf8("RadioSignalGen"));

        chooseMode->addWidget(RadioSignalGen);

        RadioBode = new QRadioButton(chooseMode_2);
        RadioBode->setObjectName(QString::fromUtf8("RadioBode"));

        chooseMode->addWidget(RadioBode);

        gridBode = new QWidget(InterfaceSerie);
        gridBode->setObjectName(QString::fromUtf8("gridBode"));
        gridBode->setGeometry(QRect(450, 110, 301, 101));
        grid = new QGridLayout(gridBode);
        grid->setObjectName(QString::fromUtf8("grid"));
        radioButtonkHzBodestart = new QRadioButton(gridBode);
        buttonGroup = new QButtonGroup(InterfaceSerie);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButtonkHzBodestart);
        radioButtonkHzBodestart->setObjectName(QString::fromUtf8("radioButtonkHzBodestart"));
        radioButtonkHzBodestart->setChecked(true);

        grid->addWidget(radioButtonkHzBodestart, 0, 3, 1, 1);

        lineStart = new QLineEdit(gridBode);
        lineStart->setObjectName(QString::fromUtf8("lineStart"));

        grid->addWidget(lineStart, 0, 1, 1, 1);

        radioButtonkHzBodestop = new QRadioButton(gridBode);
        buttonGroup_2 = new QButtonGroup(InterfaceSerie);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButtonkHzBodestop);
        radioButtonkHzBodestop->setObjectName(QString::fromUtf8("radioButtonkHzBodestop"));
        radioButtonkHzBodestop->setChecked(false);

        grid->addWidget(radioButtonkHzBodestop, 1, 3, 1, 1);

        radioButtonHzBodestop = new QRadioButton(gridBode);
        buttonGroup_2->addButton(radioButtonHzBodestop);
        radioButtonHzBodestop->setObjectName(QString::fromUtf8("radioButtonHzBodestop"));
        radioButtonHzBodestop->setChecked(false);

        grid->addWidget(radioButtonHzBodestop, 1, 2, 1, 1);

        radioButtonmHzBodestop = new QRadioButton(gridBode);
        buttonGroup_2->addButton(radioButtonmHzBodestop);
        radioButtonmHzBodestop->setObjectName(QString::fromUtf8("radioButtonmHzBodestop"));
        radioButtonmHzBodestop->setChecked(true);

        grid->addWidget(radioButtonmHzBodestop, 1, 4, 1, 1);

        label_3 = new QLabel(gridBode);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        grid->addWidget(label_3, 0, 0, 1, 1);

        radioButtonHzBodestart = new QRadioButton(gridBode);
        buttonGroup->addButton(radioButtonHzBodestart);
        radioButtonHzBodestart->setObjectName(QString::fromUtf8("radioButtonHzBodestart"));
        radioButtonHzBodestart->setChecked(false);

        grid->addWidget(radioButtonHzBodestart, 0, 2, 1, 1);

        label_9 = new QLabel(gridBode);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        grid->addWidget(label_9, 1, 0, 1, 1);

        radioButtonmHzBodestart = new QRadioButton(gridBode);
        buttonGroup->addButton(radioButtonmHzBodestart);
        radioButtonmHzBodestart->setObjectName(QString::fromUtf8("radioButtonmHzBodestart"));
        radioButtonmHzBodestart->setChecked(false);

        grid->addWidget(radioButtonmHzBodestart, 0, 4, 1, 1);

        lineStop = new QLineEdit(gridBode);
        lineStop->setObjectName(QString::fromUtf8("lineStop"));

        grid->addWidget(lineStop, 1, 1, 1, 1);

        label_20 = new QLabel(gridBode);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        grid->addWidget(label_20, 2, 0, 1, 1);

        line_step = new QLineEdit(gridBode);
        line_step->setObjectName(QString::fromUtf8("line_step"));

        grid->addWidget(line_step, 2, 1, 1, 1);

        radioButtonHzBodestep = new QRadioButton(gridBode);
        buttonGroup_3 = new QButtonGroup(InterfaceSerie);
        buttonGroup_3->setObjectName(QString::fromUtf8("buttonGroup_3"));
        buttonGroup_3->addButton(radioButtonHzBodestep);
        radioButtonHzBodestep->setObjectName(QString::fromUtf8("radioButtonHzBodestep"));
        radioButtonHzBodestep->setChecked(false);

        grid->addWidget(radioButtonHzBodestep, 2, 2, 1, 1);

        radioButtonkHzBodestep = new QRadioButton(gridBode);
        buttonGroup_3->addButton(radioButtonkHzBodestep);
        radioButtonkHzBodestep->setObjectName(QString::fromUtf8("radioButtonkHzBodestep"));
        radioButtonkHzBodestep->setChecked(true);

        grid->addWidget(radioButtonkHzBodestep, 2, 3, 1, 1);

        radioButtonmHzBodestep = new QRadioButton(gridBode);
        buttonGroup_3->addButton(radioButtonmHzBodestep);
        radioButtonmHzBodestep->setObjectName(QString::fromUtf8("radioButtonmHzBodestep"));

        grid->addWidget(radioButtonmHzBodestep, 2, 4, 1, 1);

        widgetchannel1 = new QWidget(InterfaceSerie);
        widgetchannel1->setObjectName(QString::fromUtf8("widgetchannel1"));
        widgetchannel1->setGeometry(QRect(60, 540, 281, 51));
        horizontalLayout_3 = new QHBoxLayout(widgetchannel1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_10 = new QLabel(widgetchannel1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Carlito"));
        font5.setBold(true);
        font5.setWeight(75);
        label_10->setFont(font5);

        horizontalLayout_3->addWidget(label_10);

        comboBox1 = new QComboBox(widgetchannel1);
        comboBox1->addItem(QString());
        comboBox1->setObjectName(QString::fromUtf8("comboBox1"));

        horizontalLayout_3->addWidget(comboBox1);

        widgetchannel2 = new QWidget(InterfaceSerie);
        widgetchannel2->setObjectName(QString::fromUtf8("widgetchannel2"));
        widgetchannel2->setGeometry(QRect(360, 540, 281, 51));
        horizontalLayout = new QHBoxLayout(widgetchannel2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_13 = new QLabel(widgetchannel2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font5);

        horizontalLayout->addWidget(label_13);

        comboBox_2 = new QComboBox(widgetchannel2);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);


        retranslateUi(InterfaceSerie);

        QMetaObject::connectSlotsByName(InterfaceSerie);
    } // setupUi

    void retranslateUi(QWidget *InterfaceSerie)
    {
        InterfaceSerie->setWindowTitle(QCoreApplication::translate("InterfaceSerie", "TestTool", nullptr));
        label_5->setText(QCoreApplication::translate("InterfaceSerie", "Type your port number :", nullptr));
        portnumber->setText(QString());
        pushButtonPortOk->setText(QCoreApplication::translate("InterfaceSerie", "OK", nullptr));
        widget_signal2->setTitle(QCoreApplication::translate("InterfaceSerie", "Signal 2", nullptr));
        label_4->setText(QCoreApplication::translate("InterfaceSerie", "Amplitude (0-3.3V) ", nullptr));
        lineAmplitude2->setText(QCoreApplication::translate("InterfaceSerie", "3.3", nullptr));
        label_15->setText(QCoreApplication::translate("InterfaceSerie", "V  ", nullptr));
        label_2->setText(QCoreApplication::translate("InterfaceSerie", "Frequency", nullptr));
        linefreq2->setText(QString());
        radioButtonHz2->setText(QCoreApplication::translate("InterfaceSerie", "Hz", nullptr));
        radioButtonkHz2->setText(QCoreApplication::translate("InterfaceSerie", "KHz", nullptr));
        radioButtonmHz2->setText(QCoreApplication::translate("InterfaceSerie", "MHz", nullptr));
        label_18->setText(QCoreApplication::translate("InterfaceSerie", "Offset  ", nullptr));
        lineoffset2->setText(QCoreApplication::translate("InterfaceSerie", "0", nullptr));
        label_19->setText(QCoreApplication::translate("InterfaceSerie", "V  ", nullptr));
        label_7->setText(QCoreApplication::translate("InterfaceSerie", "Waveform : ", nullptr));
        radioSin2->setText(QCoreApplication::translate("InterfaceSerie", "Sinus", nullptr));
        radioSquare2->setText(QCoreApplication::translate("InterfaceSerie", "Square", nullptr));
        radioSaw2->setText(QCoreApplication::translate("InterfaceSerie", "Triangle", nullptr));
        radioNoise2->setText(QCoreApplication::translate("InterfaceSerie", "Noise", nullptr));
        radiofile2->setText(QCoreApplication::translate("InterfaceSerie", "File", nullptr));
        label_12->setText(QCoreApplication::translate("InterfaceSerie", "File : ", nullptr));
        browse2->setText(QCoreApplication::translate("InterfaceSerie", "Browse", nullptr));
        label_ratio2->setText(QCoreApplication::translate("InterfaceSerie", "Cyclic ratio (1-100)% : ", nullptr));
        CyclicRatio2->setText(QCoreApplication::translate("InterfaceSerie", "50", nullptr));
        intel->setText(QString());
        button_Send->setText(QCoreApplication::translate("InterfaceSerie", "Send", nullptr));
        widget_signal1->setTitle(QCoreApplication::translate("InterfaceSerie", "Signal 1", nullptr));
        label_6->setText(QCoreApplication::translate("InterfaceSerie", "Waveform : ", nullptr));
        radioSin1->setText(QCoreApplication::translate("InterfaceSerie", "Sinus", nullptr));
        radioSquare1->setText(QCoreApplication::translate("InterfaceSerie", "Square", nullptr));
        radioSaw1->setText(QCoreApplication::translate("InterfaceSerie", "Triangle", nullptr));
        radioNoise1->setText(QCoreApplication::translate("InterfaceSerie", "Noise", nullptr));
        radiofile1->setText(QCoreApplication::translate("InterfaceSerie", "File", nullptr));
        label_ratio1->setText(QCoreApplication::translate("InterfaceSerie", "Cyclic ratio (1-100)% : ", nullptr));
        CyclicRatio1->setText(QCoreApplication::translate("InterfaceSerie", "50", nullptr));
        label->setText(QCoreApplication::translate("InterfaceSerie", "Frequency", nullptr));
        linefreq1->setText(QString());
        label_16->setText(QCoreApplication::translate("InterfaceSerie", "Offset   ", nullptr));
        lineOffset1->setText(QCoreApplication::translate("InterfaceSerie", "0", nullptr));
        label_17->setText(QCoreApplication::translate("InterfaceSerie", "V  ", nullptr));
        label_8->setText(QCoreApplication::translate("InterfaceSerie", "Amplitude (0-3.3V) ", nullptr));
        lineAmplitude1->setText(QCoreApplication::translate("InterfaceSerie", "3.3", nullptr));
        label_14->setText(QCoreApplication::translate("InterfaceSerie", "V  ", nullptr));
        radioButtonHz1->setText(QCoreApplication::translate("InterfaceSerie", "Hz", nullptr));
        radioButtonkHz1->setText(QCoreApplication::translate("InterfaceSerie", "KHz", nullptr));
        radioButtonmHz1->setText(QCoreApplication::translate("InterfaceSerie", "MHz", nullptr));
        label_11->setText(QCoreApplication::translate("InterfaceSerie", "File : ", nullptr));
        browse1->setText(QCoreApplication::translate("InterfaceSerie", "Browse", nullptr));
        signal1_en->setText(QCoreApplication::translate("InterfaceSerie", "Signal 1", nullptr));
        signal2_en->setText(QCoreApplication::translate("InterfaceSerie", "Signal 2", nullptr));
        ButtonScan->setText(QCoreApplication::translate("InterfaceSerie", "Scan ", nullptr));
        button_OkBode->setText(QCoreApplication::translate("InterfaceSerie", "Ok", nullptr));
        RadioSignalGen->setText(QCoreApplication::translate("InterfaceSerie", "Signal Generator", nullptr));
        RadioBode->setText(QCoreApplication::translate("InterfaceSerie", "Bode Diagram", nullptr));
        radioButtonkHzBodestart->setText(QCoreApplication::translate("InterfaceSerie", "KHz", nullptr));
        lineStart->setText(QCoreApplication::translate("InterfaceSerie", "1", nullptr));
        radioButtonkHzBodestop->setText(QCoreApplication::translate("InterfaceSerie", "KHz", nullptr));
        radioButtonHzBodestop->setText(QCoreApplication::translate("InterfaceSerie", "Hz", nullptr));
        radioButtonmHzBodestop->setText(QCoreApplication::translate("InterfaceSerie", "MHz", nullptr));
        label_3->setText(QCoreApplication::translate("InterfaceSerie", "Start ", nullptr));
        radioButtonHzBodestart->setText(QCoreApplication::translate("InterfaceSerie", "Hz", nullptr));
        label_9->setText(QCoreApplication::translate("InterfaceSerie", "Stop ", nullptr));
        radioButtonmHzBodestart->setText(QCoreApplication::translate("InterfaceSerie", "MHz", nullptr));
        lineStop->setText(QCoreApplication::translate("InterfaceSerie", "1", nullptr));
        label_20->setText(QCoreApplication::translate("InterfaceSerie", "Step", nullptr));
        line_step->setText(QCoreApplication::translate("InterfaceSerie", "100", nullptr));
        radioButtonHzBodestep->setText(QCoreApplication::translate("InterfaceSerie", "Hz", nullptr));
        radioButtonkHzBodestep->setText(QCoreApplication::translate("InterfaceSerie", "KHz", nullptr));
        radioButtonmHzBodestep->setText(QCoreApplication::translate("InterfaceSerie", "MHz", nullptr));
        label_10->setText(QCoreApplication::translate("InterfaceSerie", "Channel 1 output :", nullptr));
        comboBox1->setItemText(0, QCoreApplication::translate("InterfaceSerie", "Signal 1", nullptr));

        label_13->setText(QCoreApplication::translate("InterfaceSerie", "Channel 2 output :", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("InterfaceSerie", "Signal 2", nullptr));

    } // retranslateUi

};

namespace Ui {
    class InterfaceSerie: public Ui_InterfaceSerie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACESERIE_H
