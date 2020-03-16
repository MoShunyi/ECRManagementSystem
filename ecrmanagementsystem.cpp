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
		//ȡ�����������ӵ��׽���
		tcpSocket = tcpServer->nextPendingConnection();

		//��ȡ�Է�IP�Ͷ˿�
		QString ip = tcpSocket->peerAddress().toString();
		int port = tcpSocket->peerPort();
		qDebug()<<port;
		//��ʾ���ӳɹ�
		QString temp = QString("[%1:%2]:connected success").arg(ip).arg(QString::number(port));
		qDebug()<<temp;

		connect(tcpSocket,&QTcpSocket::readyRead,this,&ECRManagementSystem::ReadReceiveData);
	});
	ui.buttonBoxInsertData->button(QDialogButtonBox::Ok)->setText(QStringLiteral("ȷ��"));//��buttonbox�е�ok����
	ui.buttonBoxInsertData->button(QDialogButtonBox::Reset)->setText(QStringLiteral("����"));
	ui.buttonBoxQuery->button(QDialogButtonBox::Ok)->setText(QStringLiteral("��ѯ"));
	ui.buttonBoxQuery->button(QDialogButtonBox::Reset)->setText(QStringLiteral("����"));

	//����ҳ��Ϊδ����״̬�����¼��ż���
	ui.tabWidget->setTabEnabled(1,false);
	ui.actionLogout->setEnabled(false);

	//״̬����ʾ��¼״̬
	welcomeLabel.setText(QStringLiteral("�οͷ��ʣ�     "));
	welcomeLabel.setStyleSheet("font: 75 12pt ");
	ui.statusBar->addWidget(&welcomeLabel);

	//״̬��ʵʱ��ʾʱ������
	currentTimeLabel = new QLabel;
	currentTimeLabel->setStyleSheet("font: 75 12pt ");
	QTimer *timer = new QTimer(this);
	timer->start(1000); // ÿ�η���timeout�ź�ʱ����Ϊ1��
	ui.statusBar->addWidget(currentTimeLabel);
	connect(timer,&QTimer::timeout,this,&ECRManagementSystem::UpdateTime);

	//�����¼ע���˵�
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
		value = (Qt::AlignCenter);//���ж���
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
	//��ͨ���׽�����ȡ������
	tcpSocket->waitForReadyRead(3000);
	QByteArray array = tcpSocket->readAll();
	qDebug()<<"array = "<<array;
	QString typeNo = array.data();
	SqlDatabase *accessDB = new SqlDatabase;
	QSqlQuery *query = new QSqlQuery;
	QString sql;
	sql = QString("select top 1 partNumber from ECR where partNumber = '%1' and actions = '%2' ").arg(typeNo,QStringLiteral("ECR�ϵ�"))
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
	QString strTime = currentTime.toString(QStringLiteral("yyyy��-MM��-dd�� hh:mm:ss"));
	currentTimeLabel->setText(strTime);
}

void ECRManagementSystem::OnActionLoginClicked()
{
	log = new Login(this);
	log->setModal(true);
	log->show();
	if (log->exec() == QDialog::Accepted)
	{
		welcomeLabel.setText(QStringLiteral("%1�ѵ�¼!").arg(log->GetLoginName()));

		//����ҳ��
		ui.tabWidget->setTabEnabled(1,true);

		ui.actionLogout->setEnabled(true);
		ui.actionLogin->setEnabled(false);
		setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint); //��ʾ�رհ�ť
		show();
	}
}

void ECRManagementSystem::OnActionLogoutClicked()
{
	welcomeLabel.setText(QStringLiteral("�οͷ��ʣ�"));
	ui.tabWidget->setTabEnabled(1,false);
	ui.actionLogout->setEnabled(false);
	ui.actionLogin->setEnabled(true);
	setWindowFlags(Qt::WindowMinMaxButtonsHint); //���عرհ�ť
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
		queryModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("ECR���"));
		queryModel->setHeaderData(1, Qt::Horizontal, QStringLiteral("ƽ̨"));
		queryModel->setHeaderData(2, Qt::Horizontal, QStringLiteral("�ͺ�"));
		queryModel->setHeaderData(3, Qt::Horizontal, QStringLiteral("����"));
		queryModel->setHeaderData(4, Qt::Horizontal, QStringLiteral("����ʱ��"));
		queryModel->setHeaderData(5, Qt::Horizontal, QStringLiteral("ECR����"));

		while (queryModel->canFetchMore())//��ѯ�������256��ʱ
		{
			queryModel->fetchMore();
		}
		if (queryModel->lastError().isValid())
			qDebug() << queryModel->lastError();

		QHeaderView *hor = ui.tableView->horizontalHeader();
		hor->setSectionResizeMode(QHeaderView::Inteivracte);//��ͷ�ɵ����п�
		hor->setSectionResizeMode(QHeaderView::ResizeToContents);  //�����ݵ�����ͷ��С
		hor->setStretchLastSection(true);//���һ������

		QSortFilterProxyModel *sqlproxy = new QSortFilterProxyModel(ui.tableView);
		sqlproxy->setSourceModel(queryModel);

		ui.tableView->verticalHeader()->hide();//���ش�ֱ��ͷ(�б�)
		ui.tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//�����У�����������
		ui.tableView->setSortingEnabled(true);//���ÿ�����
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
			operate = QStringLiteral("ECR�ϵ�");
		}
		if (ui.radioButtonRecover->isChecked())
		{
			operate = QStringLiteral("ECR�л�");
		}
		QString content = ui.textEditContent->toPlainText();

		if (platform.isEmpty() || typeNo.isEmpty() || ecrNumber.isEmpty() || operate.isEmpty() || content.isEmpty())
		{
			QMessageBox mb; 
			mb.setIcon(QMessageBox::Warning);
			mb.setText(QStringLiteral("<font size = 6>������������Ϊ�գ��������������ԣ�</font>"));
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
			msgBox.setText(QStringLiteral("<font size = 6>ECR¼��ɹ�! </font>"));
			msgBox.setIconPixmap(QPixmap(":/ECRManagementSystem/Resources/icon-ok.png"));
			msgBox.exec();
			delete accessDB;
			//accessDB = nullptr;
		} 
		else
		{
			msgBox.setIcon(QMessageBox::Critical);
			msgBox.setText(QStringLiteral("<font size = 6>ECR¼��ʧ�ܣ��������ύ��</font>"));
			msgBox.setIconPixmap(QPixmap(":/ECRManagementSystem/Resources/icon-fail.png"));
			msgBox.exec();
			delete accessDB;
			//accessDB = nullptr;
		}
	}
}