#include "login.h"

Login::Login(QWidget *parent)
	: QDialog(parent)
{
	uiLog = new Ui::Login();
	uiLog->setupUi(this);
	uiLog->buttonBoxLogin->button(QDialogButtonBox::Ok)->setText(QStringLiteral("ȷ��"));//��buttonbox�е�ok����
	uiLog->buttonBoxLogin->button(QDialogButtonBox::Reset)->setText(QStringLiteral("����"));
	uiLog->lineEditUsername->setFocus();
	uiLog->lineEditPassword->setEchoMode(QLineEdit::Password);

	//accessDB = new SqlDatabase;
	//�����źźͲ�
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
			mb.setText(QString(QStringLiteral("<font size = 6>�û���������Ϊ�գ�����������</font>")));
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
				QMessageBox::warning(this,QStringLiteral("���棡"),QStringLiteral("<font size = 6>�û��������������</font>"),QMessageBox::Yes);
				delete sqlDB;
			}
		}

}
