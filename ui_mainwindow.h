/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tabCom;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QGroupBox *groupBoxInfo;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxComName;
    QLabel *label_2;
    QComboBox *comboBoxBitNum;
    QLabel *label_3;
    QComboBox *comboBoxCheckBit;
    QLabel *label_7;
    QComboBox *comboBoxDataBit;
    QLabel *label_4;
    QComboBox *comboBoxStopBit;
    QLabel *label_5;
    QComboBox *comboBoxFlowControl;
    QPushButton *pushButtonScanCom;
    QPushButton *pushButtonConnect;
    QGroupBox *groupBoxCtrl;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonSendData;
    QCheckBox *checkBoxEnter;
    QPushButton *pushButtonClearData;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *comboBoxDataFormat;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QComboBox *comboBoxSendDataFormat;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxSendTime;
    QSpinBox *spinBoxSendTime;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QSpinBox *spinBoxScanTime;
    QSplitter *splitter;
    QGroupBox *groupBoxRecive;
    QGridLayout *gridLayout;
    QTextEdit *textEditRecive;
    QGroupBox *groupBoxSend;
    QGridLayout *gridLayout_2;
    QTextEdit *textEditSend;
    QWidget *tabNet;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_11;
    QFormLayout *formLayout_3;
    QLabel *label_13;
    QComboBox *comboBoxNetClientAddress;
    QLabel *label_14;
    QComboBox *comboBoxNetClientType;
    QLabel *label_15;
    QSpinBox *spinBoxNetClientPort;
    QPushButton *pushButtonClientTogger;
    QPushButton *pushButtonClientSendData;
    QSplitter *splitter_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QTextEdit *textEditNetClientR;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_9;
    QTextEdit *textEditNetClientT;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QComboBox *comboBoxNetServerAddress;
    QLabel *label_11;
    QComboBox *comboBoxNetServerType;
    QLabel *label_12;
    QSpinBox *spinBoxNetServerPort;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButtonNetServerTogger;
    QPushButton *pushButtonNetServerScanIp;
    QPushButton *pushButtonNetServerSendData;
    QSplitter *splitter_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QTextEdit *textEditNetServerR;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QTextEdit *textEditNetServerT;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1089, 614);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabCom = new QWidget();
        tabCom->setObjectName(QString::fromUtf8("tabCom"));
        gridLayout_3 = new QGridLayout(tabCom);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter_3 = new QSplitter(tabCom);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        groupBoxInfo = new QGroupBox(splitter_2);
        groupBoxInfo->setObjectName(QString::fromUtf8("groupBoxInfo"));
        verticalLayout = new QVBoxLayout(groupBoxInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBoxInfo);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxComName = new QComboBox(groupBoxInfo);
        comboBoxComName->addItem(QString());
        comboBoxComName->setObjectName(QString::fromUtf8("comboBoxComName"));
        comboBoxComName->setEditable(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxComName);

        label_2 = new QLabel(groupBoxInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBoxBitNum = new QComboBox(groupBoxInfo);
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->addItem(QString());
        comboBoxBitNum->setObjectName(QString::fromUtf8("comboBoxBitNum"));
        comboBoxBitNum->setCurrentText(QString::fromUtf8("1200"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxBitNum);

        label_3 = new QLabel(groupBoxInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBoxCheckBit = new QComboBox(groupBoxInfo);
        comboBoxCheckBit->setObjectName(QString::fromUtf8("comboBoxCheckBit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxCheckBit);

        label_7 = new QLabel(groupBoxInfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        comboBoxDataBit = new QComboBox(groupBoxInfo);
        comboBoxDataBit->setObjectName(QString::fromUtf8("comboBoxDataBit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxDataBit);

        label_4 = new QLabel(groupBoxInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        comboBoxStopBit = new QComboBox(groupBoxInfo);
        comboBoxStopBit->setObjectName(QString::fromUtf8("comboBoxStopBit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxStopBit);

        label_5 = new QLabel(groupBoxInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        comboBoxFlowControl = new QComboBox(groupBoxInfo);
        comboBoxFlowControl->setObjectName(QString::fromUtf8("comboBoxFlowControl"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBoxFlowControl);


        verticalLayout->addLayout(formLayout);

        pushButtonScanCom = new QPushButton(groupBoxInfo);
        pushButtonScanCom->setObjectName(QString::fromUtf8("pushButtonScanCom"));

        verticalLayout->addWidget(pushButtonScanCom);

        pushButtonConnect = new QPushButton(groupBoxInfo);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        verticalLayout->addWidget(pushButtonConnect);

        splitter_2->addWidget(groupBoxInfo);
        groupBoxCtrl = new QGroupBox(splitter_2);
        groupBoxCtrl->setObjectName(QString::fromUtf8("groupBoxCtrl"));
        verticalLayout_2 = new QVBoxLayout(groupBoxCtrl);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonSendData = new QPushButton(groupBoxCtrl);
        pushButtonSendData->setObjectName(QString::fromUtf8("pushButtonSendData"));

        horizontalLayout->addWidget(pushButtonSendData);

        checkBoxEnter = new QCheckBox(groupBoxCtrl);
        checkBoxEnter->setObjectName(QString::fromUtf8("checkBoxEnter"));

        horizontalLayout->addWidget(checkBoxEnter);


        verticalLayout_2->addLayout(horizontalLayout);

        pushButtonClearData = new QPushButton(groupBoxCtrl);
        pushButtonClearData->setObjectName(QString::fromUtf8("pushButtonClearData"));

        verticalLayout_2->addWidget(pushButtonClearData);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(groupBoxCtrl);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        comboBoxDataFormat = new QComboBox(groupBoxCtrl);
        comboBoxDataFormat->setObjectName(QString::fromUtf8("comboBoxDataFormat"));

        horizontalLayout_2->addWidget(comboBoxDataFormat);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(groupBoxCtrl);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        comboBoxSendDataFormat = new QComboBox(groupBoxCtrl);
        comboBoxSendDataFormat->setObjectName(QString::fromUtf8("comboBoxSendDataFormat"));

        horizontalLayout_5->addWidget(comboBoxSendDataFormat);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBoxSendTime = new QCheckBox(groupBoxCtrl);
        checkBoxSendTime->setObjectName(QString::fromUtf8("checkBoxSendTime"));

        horizontalLayout_3->addWidget(checkBoxSendTime);

        spinBoxSendTime = new QSpinBox(groupBoxCtrl);
        spinBoxSendTime->setObjectName(QString::fromUtf8("spinBoxSendTime"));

        horizontalLayout_3->addWidget(spinBoxSendTime);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(groupBoxCtrl);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        spinBoxScanTime = new QSpinBox(groupBoxCtrl);
        spinBoxScanTime->setObjectName(QString::fromUtf8("spinBoxScanTime"));
        spinBoxScanTime->setMinimum(5);
        spinBoxScanTime->setMaximum(1000);
        spinBoxScanTime->setValue(20);

        horizontalLayout_4->addWidget(spinBoxScanTime);


        verticalLayout_2->addLayout(horizontalLayout_4);

        splitter_2->addWidget(groupBoxCtrl);
        splitter_3->addWidget(splitter_2);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(0, 0));
        splitter->setOrientation(Qt::Vertical);
        groupBoxRecive = new QGroupBox(splitter);
        groupBoxRecive->setObjectName(QString::fromUtf8("groupBoxRecive"));
        gridLayout = new QGridLayout(groupBoxRecive);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEditRecive = new QTextEdit(groupBoxRecive);
        textEditRecive->setObjectName(QString::fromUtf8("textEditRecive"));
        textEditRecive->setUndoRedoEnabled(true);
        textEditRecive->setReadOnly(true);

        gridLayout->addWidget(textEditRecive, 0, 0, 1, 1);

        splitter->addWidget(groupBoxRecive);
        groupBoxSend = new QGroupBox(splitter);
        groupBoxSend->setObjectName(QString::fromUtf8("groupBoxSend"));
        gridLayout_2 = new QGridLayout(groupBoxSend);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEditSend = new QTextEdit(groupBoxSend);
        textEditSend->setObjectName(QString::fromUtf8("textEditSend"));

        gridLayout_2->addWidget(textEditSend, 0, 0, 1, 1);

        splitter->addWidget(groupBoxSend);
        splitter_3->addWidget(splitter);

        gridLayout_3->addWidget(splitter_3, 0, 0, 1, 1);

        tabWidget->addTab(tabCom, QString());
        tabNet = new QWidget();
        tabNet->setObjectName(QString::fromUtf8("tabNet"));
        gridLayout_5 = new QGridLayout(tabNet);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox_2 = new QGroupBox(tabNet);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_12 = new QGridLayout(groupBox_2);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_13);

        comboBoxNetClientAddress = new QComboBox(groupBox_2);
        comboBoxNetClientAddress->setObjectName(QString::fromUtf8("comboBoxNetClientAddress"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, comboBoxNetClientAddress);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_14);

        comboBoxNetClientType = new QComboBox(groupBox_2);
        comboBoxNetClientType->setObjectName(QString::fromUtf8("comboBoxNetClientType"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, comboBoxNetClientType);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_15);

        spinBoxNetClientPort = new QSpinBox(groupBox_2);
        spinBoxNetClientPort->setObjectName(QString::fromUtf8("spinBoxNetClientPort"));
        spinBoxNetClientPort->setMinimum(1);
        spinBoxNetClientPort->setMaximum(65535);
        spinBoxNetClientPort->setValue(18085);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, spinBoxNetClientPort);


        gridLayout_11->addLayout(formLayout_3, 0, 0, 2, 1);

        pushButtonClientTogger = new QPushButton(groupBox_2);
        pushButtonClientTogger->setObjectName(QString::fromUtf8("pushButtonClientTogger"));

        gridLayout_11->addWidget(pushButtonClientTogger, 0, 1, 1, 1);

        pushButtonClientSendData = new QPushButton(groupBox_2);
        pushButtonClientSendData->setObjectName(QString::fromUtf8("pushButtonClientSendData"));

        gridLayout_11->addWidget(pushButtonClientSendData, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_11);

        splitter_5 = new QSplitter(groupBox_2);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setOrientation(Qt::Vertical);
        groupBox_5 = new QGroupBox(splitter_5);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        textEditNetClientR = new QTextEdit(groupBox_5);
        textEditNetClientR->setObjectName(QString::fromUtf8("textEditNetClientR"));
        textEditNetClientR->setReadOnly(true);

        gridLayout_8->addWidget(textEditNetClientR, 0, 0, 1, 1);

        splitter_5->addWidget(groupBox_5);
        groupBox_6 = new QGroupBox(splitter_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_9 = new QGridLayout(groupBox_6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        textEditNetClientT = new QTextEdit(groupBox_6);
        textEditNetClientT->setObjectName(QString::fromUtf8("textEditNetClientT"));

        gridLayout_9->addWidget(textEditNetClientT, 0, 0, 1, 1);

        splitter_5->addWidget(groupBox_6);

        verticalLayout_3->addWidget(splitter_5);


        gridLayout_12->addLayout(verticalLayout_3, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(groupBox_2);


        gridLayout_5->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        groupBox = new QGroupBox(tabNet);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        comboBoxNetServerAddress = new QComboBox(groupBox);
        comboBoxNetServerAddress->setObjectName(QString::fromUtf8("comboBoxNetServerAddress"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBoxNetServerAddress);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_11);

        comboBoxNetServerType = new QComboBox(groupBox);
        comboBoxNetServerType->setObjectName(QString::fromUtf8("comboBoxNetServerType"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboBoxNetServerType);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_12);

        spinBoxNetServerPort = new QSpinBox(groupBox);
        spinBoxNetServerPort->setObjectName(QString::fromUtf8("spinBoxNetServerPort"));
        spinBoxNetServerPort->setMinimum(1);
        spinBoxNetServerPort->setMaximum(65535);
        spinBoxNetServerPort->setValue(18085);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinBoxNetServerPort);


        horizontalLayout_7->addLayout(formLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButtonNetServerTogger = new QPushButton(groupBox);
        pushButtonNetServerTogger->setObjectName(QString::fromUtf8("pushButtonNetServerTogger"));

        verticalLayout_4->addWidget(pushButtonNetServerTogger);

        pushButtonNetServerScanIp = new QPushButton(groupBox);
        pushButtonNetServerScanIp->setObjectName(QString::fromUtf8("pushButtonNetServerScanIp"));

        verticalLayout_4->addWidget(pushButtonNetServerScanIp);

        pushButtonNetServerSendData = new QPushButton(groupBox);
        pushButtonNetServerSendData->setObjectName(QString::fromUtf8("pushButtonNetServerSendData"));

        verticalLayout_4->addWidget(pushButtonNetServerSendData);


        horizontalLayout_7->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_7);

        splitter_4 = new QSplitter(groupBox);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        groupBox_3 = new QGroupBox(splitter_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        textEditNetServerR = new QTextEdit(groupBox_3);
        textEditNetServerR->setObjectName(QString::fromUtf8("textEditNetServerR"));
        textEditNetServerR->setReadOnly(true);

        gridLayout_6->addWidget(textEditNetServerR, 0, 0, 1, 1);

        splitter_4->addWidget(groupBox_3);
        groupBox_4 = new QGroupBox(splitter_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        textEditNetServerT = new QTextEdit(groupBox_4);
        textEditNetServerT->setObjectName(QString::fromUtf8("textEditNetServerT"));

        gridLayout_7->addWidget(textEditNetServerT, 0, 0, 1, 1);

        splitter_4->addWidget(groupBox_4);

        verticalLayout_5->addWidget(splitter_4);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        tabWidget->addTab(tabNet, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\344\277\241\346\201\257\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267:", nullptr));
        comboBoxComName->setItemText(0, QCoreApplication::translate("MainWindow", "Customize", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\346\257\224\347\211\271\347\216\207:", nullptr));
        comboBoxBitNum->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        comboBoxBitNum->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        comboBoxBitNum->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        comboBoxBitNum->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBoxBitNum->setItemText(4, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboBoxBitNum->setItemText(5, QCoreApplication::translate("MainWindow", "34800", nullptr));
        comboBoxBitNum->setItemText(6, QCoreApplication::translate("MainWindow", "57600", nullptr));
        comboBoxBitNum->setItemText(7, QCoreApplication::translate("MainWindow", "96000", nullptr));
        comboBoxBitNum->setItemText(8, QCoreApplication::translate("MainWindow", "115200", nullptr));
        comboBoxBitNum->setItemText(9, QCoreApplication::translate("MainWindow", "Customize", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", nullptr));
        comboBoxDataBit->setCurrentText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\265\201\346\216\247\345\210\266:", nullptr));
        pushButtonScanCom->setText(QCoreApplication::translate("MainWindow", "\346\211\253\346\217\217\344\270\262\345\217\243", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\277\236\346\216\245", nullptr));
        groupBoxCtrl->setTitle(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\345\214\272\345\237\237", nullptr));
        pushButtonSendData->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        checkBoxEnter->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        pushButtonClearData->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\230\276\347\244\272\346\240\274\345\274\217:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\221\351\200\201\346\240\274\345\274\217:", nullptr));
        checkBoxSendTime->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\244\215\345\217\221\351\200\201(s)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\344\277\241\346\201\257\345\210\244\345\256\232\346\227\266\351\227\264(ms):", nullptr));
        groupBoxRecive->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\345\217\227\345\214\272", nullptr));
        groupBoxSend->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\221\351\200\201\345\214\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCom), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\260\203\350\257\225\345\267\245\345\205\267", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Client", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\345\234\260\345\235\200:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\261\273\345\236\213:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267:", nullptr));
        pushButtonClientTogger->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\277\236\346\216\245", nullptr));
        pushButtonClientSendData->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\346\224\266\345\214\272", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\221\351\200\201\345\214\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Server", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\347\233\221\345\220\254\345\234\260\345\235\200:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\261\273\345\236\213:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267:", nullptr));
        pushButtonNetServerTogger->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\347\233\221\345\220\254", nullptr));
        pushButtonNetServerScanIp->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\345\234\260\345\235\200", nullptr));
        pushButtonNetServerSendData->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\346\224\266\345\214\272", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\221\351\200\201\345\214\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabNet), QCoreApplication::translate("MainWindow", "TCP/IP\350\260\203\350\257\225\345\267\245\345\205\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
