#include "SqlDatabase.h"


SqlDatabase::SqlDatabase(void)
{
	InitSql();
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
	if (!accessDB.open())
	{
		ConnectDatabase();
	}
	query = new QSqlQuery(accessDB);
	query->exec(sql);
	
	/*while(query->next())
	{
		qDebug()<<query->value("userName").toString()<<" "<<query->value("password").toString();
	}*/
	if (!query->next())
	{
		return false;
	}
	return true;
}
void SqlDatabase::QueryData(QString sql,QSqlQuery *query)
{
	/*if (sql.isEmpty())
	{
		return ;
	}*/
	if (!accessDB.open())
	{
		ConnectDatabase();
	}
	QSqlQuery *temQuery =new QSqlQuery(accessDB);
	temQuery->exec(sql);
	if (temQuery->lastError().isValid())
	{
		return;
		query = nullptr;
		delete temQuery;
	}else
	{
		*query = *temQuery;
		delete temQuery;
	}
	
}
bool SqlDatabase::InsertData(QString sql)
{
	if (sql.isEmpty())
	{
		return false;
	}
	if (!accessDB.open())
	{
		ConnectDatabase();
	}
	QSqlDatabase::database().transaction();
	query = new QSqlQuery(accessDB);
	query->exec(sql);
	
	qDebug()<<sql;
	
	if (query->numRowsAffected() != 0 && query->numRowsAffected() != -1)
	{
		QSqlDatabase::database().commit();
		return true;
	} 
	else
	{
		return false;
	}
}
