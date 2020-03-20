#ifndef ECRMANAGEMENTSYSTEM_H
#define ECRMANAGEMENTSYSTEM_H

#include <QtWidgets/QMainWindow>
#include <QSettings>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QStringList>
#include <QCompleter>
#include "ui_ecrmanagementsystem.h"
#include "login.h"

//查询界面自定义查询模型
class TabQuerySQlQueryModel:public QSqlQueryModel
{
public:
	explicit  TabQuerySQlQueryModel();
public:
	QVariant data(const QModelIndex &index, int role) const;
protected:
};

class ECRManagementSystem : public QMainWindow
{
	Q_OBJECT

public:
	ECRManagementSystem(QWidget *parent = 0);
	~ECRManagementSystem();

	void ReadSettings();
	bool ConnectDatabase();
	bool LoginCheck(QString userName, QString password);
	void QueryData(QString sql);
	bool InsertData(QString sql);

	//槽函数
	void ReadReceiveData();
	void UpdateTime();
	void OnActionLoginClicked();
	void OnActionLogoutClicked();
	void OnButtonBoxQueryClicked(QAbstractButton *button);
	void OnButtonBoxInsertDataClicked(QAbstractButton *button);
private:
	Ui::ECRManagementSystemClass ui;
	Login *log;
	QSettings *config;
	SqlDatabase *accessDB;
	TabQuerySQlQueryModel *queryModel;
	QSortFilterProxyModel *sqlproxy;
	QHeaderView *hor;
	//QSqlQuery *query;
	//QSqlDatabase accessDB;
	//QString accessDatabaseDir;
	//QString accessDatabaseUID;
	//QString accessDatabasePWD;

	QTcpServer *tcpServer;
	QTcpSocket *tcpSocket;
	
	QLabel welcomeLabel;
	QLabel *currentTimeLabel;

};

#endif // ECRMANAGEMENTSYSTEM_H
