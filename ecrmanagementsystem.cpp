#include "ecrmanagementsystem.h"

ECRManagementSystem::ECRManagementSystem(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ReadSettings();
	tcpServer = NULL;
	tcpSocket = NULL;

	tcpServer = new QTcpServer(this);
	tcpServer->listen(QHostAddress::Any,8888);

	connect(tcpServer,&QTcpServer::newConnection,
		[=]()
	{
		//取出建立好连接的套接字
		tcpSocket = tcpServer->nextPendingConnection();

		//获取对方IP和端口
		QString ip = tcpSocket->peerAddress().toString();
		int port = tcpSocket->peerPort();
		qDebug()<<port;
		//提示连接成功
		QString temp = QString("[%1:%2]:connected success").arg(ip).arg(QString::number(port));
		qDebug()<<temp;

		connect(tcpSocket,&QTcpSocket::readyRead,this,&ECRManagementSystem::ReadReceiveData);
	});
	ui.buttonBoxInsertData->button(QDialogButtonBox::Ok)->setText(QStringLiteral("确定"));//将buttonbox中的ok汉化
	ui.buttonBoxInsertData->button(QDialogButtonBox::Reset)->setText(QStringLiteral("重置"));
	ui.buttonBoxQuery->button(QDialogButtonBox::Ok)->setText(QStringLiteral("查询"));
	ui.buttonBoxQuery->button(QDialogButtonBox::Reset)->setText(QStringLiteral("重置"));

	//设置页面为未激活状态，需登录后才激活
	ui.tabWidget->setTabEnabled(1,false);
	ui.actionLogout->setEnabled(false);

	//状态栏显示登录状态
	welcomeLabel.setText(QStringLiteral("游客访问！     "));
	welcomeLabel.setStyleSheet("font: 75 12pt ");
	ui.statusBar->addWidget(&welcomeLabel);

	//状态栏实时显示时间日期
	currentTimeLabel = new QLabel;
	currentTimeLabel->setStyleSheet("font: 75 12pt ");
	QTimer *timer = new QTimer(this);
	timer->start(1000); // 每次发射timeout信号时间间隔为1秒
	ui.statusBar->addWidget(currentTimeLabel);
	connect(timer,&QTimer::timeout,this,&ECRManagementSystem::UpdateTime);

	//点击登录注销菜单
	connect(ui.actionLogin,&QAction::triggered,this,&ECRManagementSystem::OnActionLoginClicked);
	connect(ui.actionLogout,&QAction::triggered,this,&ECRManagementSystem::OnActionLogoutClicked);

	connect(ui.buttonBoxQuery,&QDialogButtonBox::clicked,this,&ECRManagementSystem::OnButtonBoxQueryClicked);
	connect(ui.buttonBoxInsertData,&QDialogButtonBox::clicked,this,&ECRManagementSystem::OnButtonBoxInsertDataClicked);
}

ECRManagementSystem::~ECRManagementSystem()
{

}

TabQuerySQlQueryModel::TabQuerySQlQueryModel()
{

}

QVariant TabQuerySQlQueryModel::data(const QModelIndex &index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);

	if(role == Qt::TextAlignmentRole)
	{
		value = (Qt::AlignCenter);//居中对齐
		return value;
		//return QVariant(Qt::AlignCenter);
	}

	return value;
}
void ECRManagementSystem::ReadTimer()
{
	QTimer *readTimer = new QTimer(this);
	readTimer->start(1000);
	connect(readTimer,&QTimer::timeout,this,&ECRManagementSystem::ReadReceiveData);
}
void ECRManagementSystem::ReadReceiveData()
{
	//从通信套接字中取出内容
	tcpSocket->waitForReadyRead(3000);
	QByteArray array = tcpSocket->readAll();
	qDebug()<<"array = "<<array;
	QString typeNo = array.data();
	SqlDatabase *accessDB = new SqlDatabase;
	QSqlQuery *query = new QSqlQuery;
	QString sql;
	sql = QString("select top 1 partNumber from ECR where partNumber = '%1' and actions = '%2' ").arg(typeNo,QStringLiteral("ECR断点"))
		+ QString("and timestamps = (select MAX(timestamps)  from ECR where partNumber = '%1') order by timestamps desc").arg(typeNo);
	qDebug()<<sql;
	accessDB->QueryData(sql,query);
	if (query->next())
	{
		qDebug()<<query->value("partNumber");
		QByteArray sendData("NG</root>");
		tcpSocket->write(sendData);
	} 
	else
	{
		QByteArray sendData("OK</root>");
		qDebug()<<sendData;
		tcpSocket->write(sendData);
		tcpSocket->waitForBytesWritten(3000);
	}
}
void ECRManagementSystem::UpdateTime()
{
	QDateTime currentTime = QDateTime::currentDateTime();
	QString strTime = currentTime.toString(QStringLiteral("yyyy年-MM月-dd日 hh:mm:ss"));
	currentTimeLabel->setText(strTime);
}

void ECRManagementSystem::OnActionLoginClicked()
{
	log = new Login(this);
	log->setModal(true);
	log->show();
	if (log->exec() == QDialog::Accepted)
	{
		welcomeLabel.setText(QStringLiteral("%1已登录!").arg(log->GetLoginName()));

		//激活页面
		ui.tabWidget->setTabEnabled(1,true);

		ui.actionLogout->setEnabled(true);
		ui.actionLogin->setEnabled(false);
		setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint); //显示关闭按钮
		show();
	}
}

void ECRManagementSystem::OnActionLogoutClicked()
{
	welcomeLabel.setText(QStringLiteral("游客访问！"));
	ui.tabWidget->setTabEnabled(1,false);
	ui.actionLogout->setEnabled(false);
	ui.actionLogin->setEnabled(true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint); //隐藏关闭按钮
	show();
}

void ECRManagementSystem::OnButtonBoxQueryClicked(QAbstractButton *button)
{
	if (button == ui.buttonBoxQuery->button(QDialogButtonBox::Reset))
	{
		ui.lineEditPlatformQuery->setText("");
		ui.lineEditTypeNoQuery->setText("");
		ui.lineEditECRNumberQuery->setText("");
		return;
	}
	
	if (button == ui.buttonBoxQuery->button(QDialogButtonBox::Ok))
	{
		QString platform = ui.lineEditPlatformQuery->text().trimmed();
		QString typeNo = ui.lineEditTypeNoQuery->text().trimmed();
		QString ecrNumber = ui.lineEditECRNumberQuery->text().trimmed();
		QString sql;
		if (platform.isEmpty() && typeNo.isEmpty() && ecrNumber.isEmpty())
		{
			sql = QString(QStringLiteral("select ecrNumber,platform,partNumber,actions,timestamps,content from ECR order by timestamps desc "));
		} else
		{
			sql = QString(QStringLiteral("select ecrNumber,platform,partNumber,actions,timestamps,content "))
				+ QString(QStringLiteral("from ECR where ecrNumber like '%%1%' and platform like '%%2%' and partNumber like '%%3%' order by timestamps desc ")).arg(ecrNumber,platform,typeNo);
		}
		
		qDebug()<<sql;
		SqlDatabase *accessDB = new SqlDatabase;
		QSqlQuery *query = new QSqlQuery;
		accessDB->QueryData(sql,query);
		//TabQuerySQlQueryModel *queryModel = new TabQuerySQlQueryModel();
		if (query==nullptr)
		{
			delete accessDB;
			delete query;
			return;
		}
		TabQuerySQlQueryModel *queryModel = new TabQuerySQlQueryModel;
		queryModel->setQuery(*query);
		queryModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("ECR编号"));
		queryModel->setHeaderData(1, Qt::Horizontal, QStringLiteral("平台"));
		queryModel->setHeaderData(2, Qt::Horizontal, QStringLiteral("型号"));
		queryModel->setHeaderData(3, Qt::Horizontal, QStringLiteral("操作"));
		queryModel->setHeaderData(4, Qt::Horizontal, QStringLiteral("日期时间"));
		queryModel->setHeaderData(5, Qt::Horizontal, QStringLiteral("ECR内容"));

		while (queryModel->canFetchMore())//查询结果超过256个时
		{
			queryModel->fetchMore();
		}
		if (queryModel->lastError().isValid())
			qDebug() << queryModel->lastError();

		QHeaderView *hor = ui.tableView->horizontalHeader();
		hor->setSectionResizeMode(QHeaderView::Inteivracte);//表头可调整列宽
		hor->setSectionResizeMode(QHeaderView::ResizeToContents);  //按内容调整表头大小
		hor->setStretchLastSection(true);//最后一列填满

		QSortFilterProxyModel *sqlproxy = new QSortFilterProxyModel(ui.tableView);
		sqlproxy->setSourceModel(queryModel);

		ui.tableView->verticalHeader()->hide();//隐藏垂直表头(行标)
		ui.tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行，填满整个表
		ui.tableView->setSortingEnabled(true);//设置可排序
		ui.tableView->setModel(sqlproxy);
		ui.tableView->show();
		delete accessDB;
		delete query;
		//accessDB = nullptr;

		
	}
}

void ECRManagementSystem::OnButtonBoxInsertDataClicked(QAbstractButton *button)
{
	if (button == ui.buttonBoxInsertData->button(QDialogButtonBox::Reset))
	{
		ui.lineEditPlatform->setText("");
		ui.lineEditTypeNo->setText("");
		ui.lineEditECRNumber->setText("");
		ui.textEditContent->setText("");
		return;
	}

	if (button == ui.buttonBoxInsertData->button(QDialogButtonBox::Ok))
	{
		QString platform = ui.lineEditPlatform->text().trimmed();
		QString typeNo = ui.lineEditTypeNo->text().trimmed();
		QString ecrNumber = ui.lineEditECRNumber->text().trimmed();
		QString operate;
		if (ui.radioButtonBreakpoint->isChecked())
		{
			operate = QStringLiteral("ECR断点");
		}
		if (ui.radioButtonRecover->isChecked())
		{
			operate = QStringLiteral("ECR切回");
		}
		QString content = ui.textEditContent->toPlainText();

		if (platform.isEmpty() || typeNo.isEmpty() || ecrNumber.isEmpty() || operate.isEmpty() || content.isEmpty())
		{
			QMessageBox mb; 
			mb.setIcon(QMessageBox::Warning);
			mb.setText(QStringLiteral("<font size = 6>发现有数据项为空，请检查数据完整性！</font>"));
			mb.exec();
			return;
		}

		QDateTime currentTime = QDateTime::currentDateTime();
		QString timestamp = currentTime.toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"));
		QString sql = QString(QStringLiteral("insert into ECR(ecrNumber,platform,partNumber,actions,content,timestamps) "))
			+ QString(QStringLiteral("values ('%1','%2','%3','%4','%5','%6')")).arg(ecrNumber,platform,typeNo,operate,content,timestamp);
		qDebug()<<sql;
		SqlDatabase *accessDB = new SqlDatabase;
		bool result = accessDB->InsertData(sql);
		QMessageBox msgBox;
		if (result)
		{
			msgBox.setIcon(QMessageBox::Information);
			msgBox.setText(QStringLiteral("<font size = 6>ECR录入成功! </font>"));
			msgBox.setIconPixmap(QPixmap(":/ECRManagementSystem/Resources/icon-ok.png"));
			msgBox.exec();
			delete accessDB;
			//accessDB = nullptr;
		} 
		else
		{
			msgBox.setIcon(QMessageBox::Critical);
			msgBox.setText(QStringLiteral("<font size = 6>ECR录入失败，请重新提交！</font>"));
			msgBox.setIconPixmap(QPixmap(":/ECRManagementSystem/Resources/icon-fail.png"));
			msgBox.exec();
			delete accessDB;
			//accessDB = nullptr;
		}
	}
}