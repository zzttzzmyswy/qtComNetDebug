#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QLineEdit>
#include <QMessageBox>
#include <QTextCodec>
#include <QDateTime>

#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>

#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkInterface>

#include <QTimer>
#include <QDebug>
#include <QtMath>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT

    public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	//user satrt

    private:
	QSerialPort serial;
	bool serial_status = false;
	QTimer *timer;
	QTimer *sendtimer;
	QTimer *timerScanCom;

	QTcpServer netTcpServer;
	QTcpSocket netTcpClient;
	QTcpSocket *netTcpServerConnection = nullptr;

	qint32 comSendBytes = 0;
	qint32 comReceiveBytes = 0;
	qint32 comScanTime = 20;

	qint32 netServerReceiveBytes = 0;
	qint32 netServerSendBytes = 0;
	qint32 netClientReceiveBytes = 0;
	qint32 netClientSendBytes = 0;

	QTextCodec *utf8codec;
	QTextCodec *gbkcodec;
	QTextCodec *gb18030codec;

	QLabel *lableno2;
	QLabel *lableno1;
	QLabel *timeLable;

	QString netServerStrConnect = QString("未连接");
	QString netClientStrConnect = QString("未连接");

	QByteArray comRxBuf;

	void comChangeButtonAfterStatusChanged();
	void comSendDataFromTextEdit();
	QString getLocalIp();
	QStringList getLocalIpList();

    private slots:
	void comSerialPortReadyRead();
	void TimeUpdate();
	void comTimeScanComData();

	void netServerAcceptConnection();
	void netUpdateServerProgressRead();
	void netUpdateServerProgressWrite(qint64 numBytes);
	void netUpdateClientProgressRead();
	void netUpdateClientProgressWrite(qint64 numBytes);
	void netDisplayErrorServer(QAbstractSocket::SocketError socketError);
	void netDisplayErrorClient(QAbstractSocket::SocketError socketError);

	void netClientConnectOk();
	void netServerOpenOk();
	void netServerDisconnect();

	//user end

    private slots:
	void on_pushButtonScanCom_clicked();

	void on_comboBoxBitNum_activated(const QString &arg1);

	void on_pushButtonConnect_clicked();

	void on_pushButtonSendData_clicked();

	void on_pushButtonClearData_clicked();

	void on_checkBoxSendTime_clicked(bool checked);

	void on_spinBoxScanTime_valueChanged(int arg1);

	void on_tabWidget_currentChanged(int index);

	void on_pushButtonNetServerTogger_clicked();

	void on_pushButtonNetServerSendData_clicked();

	void on_pushButtonClientTogger_clicked();

	void on_pushButtonClientSendData_clicked();

	void on_pushButtonNetServerScanIp_clicked();

	void on_comboBoxNetServerAddress_activated(const QString &arg1);

	void on_comboBoxNetClientAddress_activated(const QString &arg1);

    private:
	Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
