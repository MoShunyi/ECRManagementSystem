#include "login.h"

Login::Login(QWidget *parent)
	: QDialog(parent)
{
	uiLog = new Ui::Login();
	uiLog->setupUi(this);
	uiLog->buttonBoxLogin->button(QDialogButtonBox::Ok)->setText(QStringLiteral("确定"));//将buttonbox中的ok汉化
	uiLog->buttonBoxLogin->button(QDialogButtonBox::Reset)->setText(QStringLiteral("重置"));
	uiLog->lineEditUsername->setFocus();
	uiLog->lineEditPassword->setEchoMode(QLineEdit::Password);

	//accessDB = new SqlDatabase;
	//连接信号和槽
	connect(uiLog->buttonBoxLogin,static_cast<void (QDialogButtonBox::*)(QAbstractButton *)>(&QDialogButtonBox::clicked),this,&Login::OnButtonBoxLoginClicked);
}

Login::~Login()
{
	delete uiLog;
}
QString Login::GetLoginName()
{
	return loginName;
}
void Login::OnButtonBoxLoginClicked(QAbstractButton *button)
{
	SqlDatabase *sqlDB = new SqlDatabase;
	QString strUsername = uiLog->lineEditUsername->text().trimmed();
	QString strPassword = uiLog->lineEditPassword->text().trimmed();
	if (button == uiLog->buttonBoxLogin->button(QDialogButtonBox::Reset))
	{
		uiLog->lineEditUsername->setText("");
		uiLog->lineEditPassword->setText("");
	}else
		if (strUsername.isEmpty() || strPassword.isEmpty())
		{
			QMessageBox mb;
			mb.setIcon(QMessageBox::Warning);
			mb.setText(QString(QStringLiteral("<font size = 6>用户名或密码为空，请重新输入</font>")));
			mb.exec();

		} 
		else
		{
			if (sqlDB->LoginCheck(strUsername,strPassword))
			{
				loginName = strUsername;
				delete sqlDB;
				accept();
			}
			else 
			{
				QMessageBox::warning(this,QStringLiteral("警告！"),QStringLiteral("<font size = 6>用户名或者密码错误</font>"),QMessageBox::Yes);
				delete sqlDB;
			}
		}

}
