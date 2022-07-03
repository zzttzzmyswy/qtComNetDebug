#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	utf8codec = QTextCodec::codecForName("UTF-8");
	if (utf8codec == NULL)
		qFatal("Don't find UTF-8");
	gbkcodec = QTextCodec::codecForName("gb18030");
	if (gbkcodec == NULL) {
		qWarning("Don't find gb18030, use gbk");
		gbkcodec = QTextCodec::codecForName("gbk");
		if (gbkcodec == NULL) {
			qFatal("Don't find GBK");
		}
	}
	QTextCodec::setCodecForLocale(utf8codec);

	lableno2 = new QLabel(this);
	lableno1 = new QLabel(this);
	timeLable = new QLabel(this);
	timer = new QTimer(this);
	sendtimer = new QTimer(this);
	timerScanCom = new QTimer(this);

	ui->tabWidget->setCurrentIndex(0);

	ui->pushButtonConnect->setEnabled(true);
	ui->pushButtonSendData->setEnabled(false);
	ui->checkBoxSendTime->setEnabled(false);

	ui->comboBoxBitNum->setCurrentText(QString("115200"));

	ui->comboBoxDataBit->addItem("5", QSerialPort::Data5);
	ui->comboBoxDataBit->addItem("6", QSerialPort::Data6);
	ui->comboBoxDataBit->addItem("7", QSerialPort::Data7);
	ui->comboBoxDataBit->addItem("8", QSerialPort::Data8);
	ui->comboBoxDataBit->setCurrentIndex(3);

	ui->comboBoxStopBit->addItem("1", QSerialPort::OneStop);
	ui->comboBoxStopBit->addItem("1.5", QSerialPort::OneAndHalfStop);
	ui->comboBoxStopBit->addItem("2", QSerialPort::TwoStop);
	ui->comboBoxStopBit->setCurrentIndex(0);

	ui->comboBoxCheckBit->addItem("NoParity", QSerialPort::NoParity);
	ui->comboBoxCheckBit->addItem("EvenParity", QSerialPort::EvenParity);
	ui->comboBoxCheckBit->addItem("OddParity", QSerialPort::OddParity);
	ui->comboBoxCheckBit->addItem("SpaceParity", QSerialPort::SpaceParity);
	ui->comboBoxCheckBit->addItem("MarkParity", QSerialPort::MarkParity);
	ui->comboBoxCheckBit->setCurrentIndex(0);

	ui->comboBoxFlowControl->addItem("NoFlowControl",
					 QSerialPort::NoFlowControl);
	ui->comboBoxFlowControl->addItem("SoftwareControl",
					 QSerialPort::SoftwareControl);
	ui->comboBoxFlowControl->addItem("HardwareControl",
					 QSerialPort::HardwareControl);
	ui->comboBoxFlowControl->setCurrentIndex(0);

	ui->comboBoxDataFormat->addItem("UTF8", 0);
	ui->comboBoxDataFormat->addItem("GBK", 1);
	ui->comboBoxDataFormat->addItem("Unicode", 2);
	ui->comboBoxDataFormat->addItem("HEX", 3);
	ui->comboBoxDataFormat->addItem("BIN", 4);
	ui->comboBoxDataFormat->setCurrentIndex(0);

	ui->comboBoxSendDataFormat->addItem("UTF8", 0);
	ui->comboBoxSendDataFormat->addItem("GBK", 1);
	ui->comboBoxSendDataFormat->addItem("Unicode", 2);
	ui->comboBoxSendDataFormat->setCurrentIndex(0);

	ui->comboBoxNetServerType->addItem("TCP", 0);

	ui->comboBoxNetClientType->addItem("TCP", 0);

	//qDebug()<<"本机IP"<<getLocalIp();
	QStringList ipAdd = getLocalIpList();
	qDebug() << "获取本机IP列表" << ipAdd;
	ui->comboBoxNetServerAddress->addItem(QString("Any"));
	ui->comboBoxNetServerAddress->addItems(ipAdd);
	ui->comboBoxNetServerAddress->addItem(QString("Customize"));
	ui->comboBoxNetServerAddress->setCurrentIndex(0);

	ui->comboBoxNetClientAddress->addItem(QString("127.0.0.1"));
	ui->comboBoxNetClientAddress->addItem(QString("Customize"));
	ui->comboBoxNetClientAddress->setCurrentIndex(0);

	timer->start(500);
	comScanTime = ui->spinBoxScanTime->value();

	lableno1->setText(QString("串口信息:连接已关闭"));
	lableno2->setText(QString("串口发送:%1,串口接受:%2")
				  .arg(comSendBytes)
				  .arg(comReceiveBytes));

	ui->statusbar->addPermanentWidget(lableno1, 2);
	ui->statusbar->addPermanentWidget(lableno2, 1);
	ui->statusbar->addPermanentWidget(timeLable, 0);
	ui->statusbar->setSizeGripEnabled(true);

	ui->spinBoxSendTime->setRange(100, 60000);
	ui->spinBoxSendTime->setValue(1000);

	on_pushButtonScanCom_clicked();

	connect(timer, SIGNAL(timeout()), this, SLOT(TimeUpdate()));
	connect(&serial, &QSerialPort::readyRead, this,
		&MainWindow::comSerialPortReadyRead);
	connect(sendtimer, SIGNAL(timeout()), this,
		SLOT(on_pushButtonSendData_clicked()));
	connect(timerScanCom, SIGNAL(timeout()), this,
		SLOT(comTimeScanComData()));

	connect(&netTcpServer, &QTcpServer::newConnection, this,
		&MainWindow::netServerAcceptConnection);
	connect(&netTcpClient, &QAbstractSocket::connected, this,
		&MainWindow::netClientConnectOk);
	connect(&netTcpClient, &QIODevice::bytesWritten, this,
		&MainWindow::netUpdateClientProgressWrite);
	connect(&netTcpClient, &QIODevice::readyRead, this,
		&MainWindow::netUpdateClientProgressRead);
	connect(&netTcpClient, &QAbstractSocket::errorOccurred, this,
		&MainWindow::netDisplayErrorClient);
}

MainWindow::~MainWindow()
{
	serial.close();
	netTcpServer.close();
	netTcpClient.close();
	delete ui;
}

void MainWindow::on_pushButtonScanCom_clicked()
{
	ui->comboBoxComName->clear();
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		ui->comboBoxComName->addItem(info.portName());
		qDebug() << "串口搜索到:" << info.portName();
	}
	ui->comboBoxComName->addItem(QString("Customize"));
}

void MainWindow::on_comboBoxBitNum_activated(const QString &arg1)
{
	if (arg1 == QString("Customize")) {
		ui->comboBoxBitNum->setEditable(true);
		QValidator *validator = new QIntValidator(0, 400000000, this);
		ui->comboBoxBitNum->lineEdit()->setValidator(validator);
	} else {
		ui->comboBoxBitNum->setEditable(false);
	}
}

void MainWindow::on_pushButtonConnect_clicked()
{
	if (ui->pushButtonConnect->text() == QString("打开连接")) {
		if (serial_status) {
			serial_status = false;
			comChangeButtonAfterStatusChanged();
		} else {
			serial.setPortName(
				ui->comboBoxComName->currentText()); //设置串口号
			serial.setBaudRate(ui->comboBoxBitNum->currentText()
						   .toInt()); //设置比特率
			serial.setDataBits(QSerialPort::DataBits(
				ui->comboBoxDataBit->currentData()
					.toInt())); //设置数据位
			serial.setStopBits(QSerialPort::StopBits(
				ui->comboBoxStopBit->currentData().toInt()));
			serial.setParity(QSerialPort::Parity(
				ui->comboBoxCheckBit->currentData().toInt()));
			serial.setFlowControl(QSerialPort::FlowControl(
				ui->comboBoxFlowControl->currentData().toInt()));
			serial.close();
			if (!serial.open(QIODevice::ReadWrite)) {
				QMessageBox::critical(NULL, "提示",
						      "串口打开失败");
				comChangeButtonAfterStatusChanged();
			} else {
				serial_status = true;
				comChangeButtonAfterStatusChanged();
			}
		}
	} else {
		serial_status = false;
		comChangeButtonAfterStatusChanged();
	}
}

void MainWindow::comChangeButtonAfterStatusChanged()
{
	if (serial_status) {
		timerScanCom->start(20);
		ui->pushButtonConnect->setText(QString("关闭连接"));
		ui->pushButtonScanCom->setEnabled(false);
		ui->pushButtonSendData->setEnabled(true);
		lableno1->setText(
			QString("串口信息:比特率:%1 数据位:%2 校验位:%3 停止位:%4 流控:%5")
				.arg(ui->comboBoxBitNum->currentText())
				.arg(ui->comboBoxDataBit->currentText())
				.arg(ui->comboBoxCheckBit->currentText())
				.arg(ui->comboBoxStopBit->currentText())
				.arg(ui->comboBoxFlowControl->currentText()));
		ui->checkBoxSendTime->setCheckState(Qt::Unchecked);
		ui->checkBoxSendTime->setEnabled(true);
	} else {
		sendtimer->stop();
		timerScanCom->stop();
		serial.close();
		ui->pushButtonConnect->setText(QString("打开连接"));
		serial_status = false;
		ui->pushButtonScanCom->setEnabled(true);
		ui->pushButtonSendData->setEnabled(false);
		lableno1->setText(QString("串口信息:连接已关闭"));
		ui->checkBoxSendTime->setCheckState(Qt::Unchecked);
		ui->checkBoxSendTime->setEnabled(false);
	}
}

void MainWindow::comSendDataFromTextEdit()
{
	QString textEditStr = ui->textEditSend->toPlainText();
	textEditStr += QString(
		ui->checkBoxEnter->checkState() == Qt::Checked ? "\r\n" : "");
	QString UnicodesendStr;
	QByteArray sendData;
	switch (ui->comboBoxSendDataFormat->currentData().toInt()) {
	case 0: //UTF8
		sendData = textEditStr.toLocal8Bit();
		break;
	case 1: //GBK
		UnicodesendStr =
			utf8codec->toUnicode(textEditStr.toLocal8Bit());
		sendData = gbkcodec->fromUnicode(UnicodesendStr);
		break;
	case 2: //Unicode
		UnicodesendStr =
			utf8codec->toUnicode(textEditStr.toLocal8Bit());
		sendData = UnicodesendStr.toLocal8Bit();
		break;
	default:
		break;
	}
	serial.write(sendData);
	comSendBytes += sendData.length();
}

void MainWindow::comSerialPortReadyRead()
{
	if (serial_status) {
		comRxBuf += serial.readAll();
		timerScanCom->stop();
		timerScanCom->start(comScanTime);
	}
}

void MainWindow::TimeUpdate()
{
	QDateTime CurrentTime = QDateTime::currentDateTime();
	QString strTime =
		CurrentTime.toString(" yyyy年MM月dd日 hh:mm:ss ") +
		QString("| Author: ZZT | Power By Qt5"); //设置显示的格式
	timeLable->setText(strTime);
	QString strLableNo2;
	switch (ui->tabWidget->currentIndex()) {
	case 0: //串口
		strLableNo2 = QString(" 串口发送:%1,串口接收:%2")
				      .arg(comSendBytes)
				      .arg(comReceiveBytes);
		break;
	case 1: //网络
		strLableNo2 =
			QString(" 服务端发送:%1,服务端接收:%2 | 客户端发送:%3,客户端接收:%4")
				.arg(netServerSendBytes)
				.arg(netServerReceiveBytes)
				.arg(netClientSendBytes)
				.arg(netClientReceiveBytes);
		lableno1->setText(QString("服务端:%1|客户端:%2")
					  .arg(netServerStrConnect)
					  .arg(netClientStrConnect));
		break;
	default:
		break;
	}

	lableno2->setText(strLableNo2);
}

void MainWindow::comTimeScanComData()
{
	if (comRxBuf.isEmpty())
		return;
	QString rxStr;
	QString strUnicode;
	switch (ui->comboBoxDataFormat->currentData().toInt()) {
	case 0: //UTF8
		rxStr = QString::fromUtf8(comRxBuf);
		break;
	case 1: //GBK
		strUnicode = gbkcodec->toUnicode(comRxBuf);
		rxStr = utf8codec->fromUnicode(strUnicode);
		break;
	case 2: //Unicode
		rxStr = utf8codec->fromUnicode(comRxBuf);
		break;
	case 3: //HEX
		foreach(uint8_t dataOne, comRxBuf)
		{
			rxStr.append(QString::number(dataOne, 16).toUpper() +
				     " ");
		}
		break;
	case 4: //BIN
		foreach(uint8_t dataOne, comRxBuf)
		{
			rxStr.append(QString::number(dataOne, 2) + " ");
		}
		break;
	default:
		break;
	}
	comReceiveBytes += comRxBuf.length();
	comRxBuf.clear();
	ui->textEditRecive->moveCursor(QTextCursor::End);
	ui->textEditRecive->insertPlainText(rxStr);
}

void MainWindow::netServerAcceptConnection()
{
	netTcpServerConnection = netTcpServer.nextPendingConnection();
	if (!netTcpServerConnection) {
		QMessageBox::critical(
			NULL, "Error",
			tr("Error: got invalid pending connection!"),
			QMessageBox::Yes, QMessageBox::Yes);
		return;
	}

	connect(netTcpServerConnection, &QIODevice::readyRead, this,
		&MainWindow::netUpdateServerProgressRead);
	connect(netTcpServerConnection, &QIODevice::bytesWritten, this,
		&MainWindow::netUpdateServerProgressWrite);
	connect(netTcpServerConnection, &QAbstractSocket::errorOccurred, this,
		&MainWindow::netDisplayErrorServer);
	connect(netTcpServerConnection, &QTcpSocket::disconnected, this,
		&MainWindow::netServerDisconnect);

	//QMessageBox::information(NULL, "Inf",tr("Accepted connection"));
	netServerStrConnect = QString("已连接");
	netTcpServer.close();
}

void MainWindow::netServerDisconnect()
{
	qDebug() << "net server disconnect\n";
	emit ui->pushButtonNetServerTogger->clicked(false);
	netTcpServerConnection->deleteLater();
}

void MainWindow::netUpdateServerProgressRead()
{
	netServerReceiveBytes +=
		qint32(netTcpServerConnection->bytesAvailable());
	QByteArray rxBuf = netTcpServerConnection->readAll();
	QString rxStr = QString::fromUtf8(rxBuf);
	ui->textEditNetServerR->append(rxStr);
}

void MainWindow::netUpdateServerProgressWrite(qint64 numBytes)
{
	netServerSendBytes += numBytes;
}

void MainWindow::netUpdateClientProgressRead()
{
	netClientReceiveBytes += qint32(netTcpClient.bytesAvailable());
	QByteArray rxBuf = netTcpClient.readAll();
	QString rxStr = QString::fromUtf8(rxBuf);
	ui->textEditNetClientR->append(rxStr);
}

void MainWindow::netUpdateClientProgressWrite(qint64 numBytes)
{
	netClientSendBytes += numBytes;
}

void MainWindow::netDisplayErrorServer(QAbstractSocket::SocketError socketError)
{
	if (socketError == QTcpSocket::RemoteHostClosedError) {
		netTcpServer.close();
		netServerStrConnect = QString("未连接");
		return;
	}
	QMessageBox::information(
		this, tr("Network error"),
		tr("The following error occurred: %1\r\n%2.")
			.arg(netTcpServer.errorString())
			.arg(netTcpServerConnection->errorString()));
	netTcpServer.close();
	netServerStrConnect = QString("未连接");
}

void MainWindow::netDisplayErrorClient(QAbstractSocket::SocketError socketError)
{
	if (socketError == QTcpSocket::RemoteHostClosedError) {
		netTcpClient.close();
		ui->pushButtonClientTogger->setEnabled(true);
		netClientStrConnect = QString("未连接");
		return;
	}

	QMessageBox::information(this, tr("Network error"),
				 tr("The following error occurred: %1.")
					 .arg(netTcpClient.errorString()));
	netTcpClient.close();
	netClientStrConnect = QString("未连接");
	ui->pushButtonClientTogger->setEnabled(true);
}

void MainWindow::netClientConnectOk()
{
	ui->pushButtonClientTogger->setEnabled(true);
	ui->pushButtonClientTogger->setText(QString("关闭连接"));
	netClientStrConnect = QString("已连接");
}

void MainWindow::netServerOpenOk()
{
}

void MainWindow::on_pushButtonSendData_clicked()
{
	comSendDataFromTextEdit();
}

void MainWindow::on_pushButtonClearData_clicked()
{
	ui->textEditRecive->clear();
	comRxBuf.clear();
	comSendBytes = 0;
	comReceiveBytes = 0;
}

void MainWindow::on_checkBoxSendTime_clicked(bool checked)
{
	if (serial_status) {
		if (checked == true) {
			sendtimer->start(ui->spinBoxSendTime->value());
			ui->pushButtonSendData->setEnabled(false);
		} else {
			sendtimer->stop();
			ui->pushButtonSendData->setEnabled(true);
		}
	}
}

void MainWindow::on_spinBoxScanTime_valueChanged(int arg1)
{
	comScanTime = arg1;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
	switch (index) {
	case 0:
		lableno1->setText(QString("串口信息:"));
		break;
	case 1:
		lableno1->setText(QString("网络信息:"));
		break;
	default:
		break;
	}
}

void MainWindow::on_pushButtonNetServerTogger_clicked()
{
	if (ui->pushButtonNetServerTogger->text() == "开启监听") {
		if (ui->comboBoxNetServerAddress->currentText() ==
		    QString("Customize"))
			return;
		if (netTcpServer.listen(
			    ui->comboBoxNetServerAddress->currentText() ==
					    "Any" ?
				    (QHostAddress::Any) :
					  QHostAddress(ui->comboBoxNetServerAddress
							 ->currentText()),
			    ui->spinBoxNetServerPort->value())) {
			ui->pushButtonNetServerTogger->setText("关闭监听");
		} else {
			netTcpServer.close();
			netServerStrConnect = QString("未连接");
		}
	} else {
		netTcpServer.close();
		netServerStrConnect = QString("未连接");
		ui->pushButtonNetServerTogger->setText("开启监听");
	}
}

void MainWindow::on_pushButtonNetServerSendData_clicked()
{
	if (netTcpServerConnection == NULL)
		return;
	if (!netTcpServerConnection->isWritable())
		return;
	QByteArray serverSendData;
	serverSendData = ui->textEditNetServerT->toPlainText().toLocal8Bit();
	netTcpServerConnection->write(serverSendData);
}

void MainWindow::on_pushButtonClientTogger_clicked()
{
	if (ui->pushButtonClientTogger->text() == "打开连接") {
		netTcpClient.connectToHost(
			ui->comboBoxNetClientAddress->currentText(),
			ui->spinBoxNetClientPort->value());
		ui->pushButtonClientTogger->setEnabled(false);
	} else {
		netTcpClient.close();
		netClientStrConnect = QString("未连接");
		ui->pushButtonClientTogger->setText("打开连接");
	}
}

void MainWindow::on_pushButtonClientSendData_clicked()
{
	if (!netTcpClient.isWritable())
		return;
	QByteArray clientSendData;
	clientSendData = ui->textEditNetClientT->toPlainText().toUtf8();
	netTcpClient.write(clientSendData);
}

// 获取ip地址
QString MainWindow::getLocalIp()
{
	// 循环遍历获取所有的ip地址
	foreach(const QHostAddress &hostAddress,
		QNetworkInterface::allAddresses())
		//  这里我们判断ip地址是否有效kdlsk;jfg
		if (hostAddress != QHostAddress::LocalHost &&
		    hostAddress.toIPv4Address()) return hostAddress.toString();
	//  这里我们就直接返回本机ip地址
	return QHostAddress(QHostAddress::LocalHost).toString();
}

// 获取ip地址列表
QStringList MainWindow::getLocalIpList()
{
	QStringList addList;
	// 循环遍历获取所有的ip地址
	foreach(const QHostAddress &hostAddress,
		QNetworkInterface::allAddresses())
		//  这里我们判断ip地址是否有效kdlsk;jfg
		if (hostAddress != QHostAddress::LocalHost &&
		    hostAddress.toIPv4Address()) addList
		<< hostAddress.toString();
	return addList;
}

void MainWindow::on_pushButtonNetServerScanIp_clicked()
{
	ui->comboBoxNetServerAddress->clear();
	ui->comboBoxNetServerAddress->addItem(QString("Any"));
	ui->comboBoxNetServerAddress->addItems(getLocalIpList());
	ui->comboBoxNetServerAddress->addItem(QString("Customize"));
	ui->comboBoxNetServerAddress->setCurrentIndex(0);
}

void MainWindow::on_comboBoxNetServerAddress_activated(const QString &arg1)
{
	if (arg1 == QString("Customize")) {
		ui->comboBoxNetServerAddress->setEditable(true);
		QRegExp regExpIP(
			"((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[\\.]){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
		ui->comboBoxNetServerAddress->lineEdit()->setValidator(
			new QRegExpValidator(regExpIP, this));
	} else {
		ui->comboBoxNetServerAddress->setEditable(false);
	}
}

void MainWindow::on_comboBoxNetClientAddress_activated(const QString &arg1)
{
	if (arg1 == QString("Customize")) {
		ui->comboBoxNetClientAddress->setEditable(true);
		QRegExp regExpIP(
			"((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[\\.]){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
		ui->comboBoxNetClientAddress->lineEdit()->setValidator(
			new QRegExpValidator(regExpIP, this));
	} else {
		ui->comboBoxNetClientAddress->setEditable(false);
	}
}
