#include "SqlDatabase.h"


SqlDatabase::SqlDatabase(void)
{
	InitSql();
	ConnectDatabase();
}


SqlDatabase::~SqlDatabase(void)
{
	delete config;
}

void SqlDatabase::InitSql()
{
	config = new QSettings("config.ini",QSettings::IniFormat);
	accessDatabaseDir = config->value("Access/dbDir").toString();
	accessDatabaseUID = config->value("Access/userId").toString();
	accessDatabasePWD = config->value("Access/password").toString();
}
bool SqlDatabase::ConnectDatabase()
{
	accessDB = QSqlDatabase::addDatabase("QODBC");
	accessDB.setDatabaseName(QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1;UID=%2;PWD=%3")
		.arg(accessDatabaseDir,accessDatabaseUID,accessDatabasePWD));

	if(!accessDB.open())                                  //打开数据库
	{
		qDebug()<<accessDB.lastError().text();
		QMessageBox::critical(0, QObject::tr("Database error"), accessDB.lastError().text());

		return false;                                   //打开失败
	}
	else
	{
		qDebug()<<"database open success!";
		return true;
	}
}
bool SqlDatabase::LoginCheck(QString userName, QString password)
{
	QString sql = QString("select * from users where userName='%1' and password = '%2' ").arg(userName).arg(password);
	if (!accessDB.isOpen())
	{
		ConnectDatabase();
	}
	QSqlQuery *query = new QSqlQuery(accessDB);
	query->exec(sql);
	if (!query->next())
	{
		delete query;
		return false;
	}
	delete query;
	return true;
}
void SqlDatabase::QueryData(QString sql,QSqlQuery *pQuery)
{
	if (sql.isEmpty())
	{
		return;
	}
	if (!accessDB.isOpen())
	{
		ConnectDatabase();
	}

	QSqlQuery *query =new QSqlQuery(accessDB);
	query->exec(sql);
	if (query->lastError().isValid())
	{
		pQuery = nullptr;
		delete query;
		return;
	}else
	{
		*pQuery = *query;
		//query->clear();
		//while(pQuery->next())
		//{
		//	qDebug()<<query->value("platform").toString()<<" "<<pQuery->value("partNumber").toString();
		//}
		//pQuery->first();
		delete query;
	}
}

bool SqlDatabase::InsertData(QString sql)
{
	if (sql.isEmpty())
	{
		return false;
	}
	if (!accessDB.isOpen())
	{
		ConnectDatabase();
	}
	QSqlDatabase::database().transaction();

	QSqlQuery *query = new QSqlQuery(accessDB);
	query->exec(sql);
	
	if (query->numRowsAffected() != 0 && query->numRowsAffected() != -1)
	{
		QSqlDatabase::database().commit();
		delete query;
		return true;
	} 
	else
	{
		delete query;
		return false;
	}
}
