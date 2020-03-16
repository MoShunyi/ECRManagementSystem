/********************************************************************************
** Form generated from reading UI file 'ecrmanagementsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECRMANAGEMENTSYSTEM_H
#define UI_ECRMANAGEMENTSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ECRManagementSystemClass
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUAES;
    QLabel *labelTitle;
    QLabel *labelBOSCH;
    QLabel *labelUnderline;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelPlatformQuery;
    QLineEdit *lineEditPlatformQuery;
    QLabel *labelTypeNoQuery;
    QLineEdit *lineEditTypeNoQuery;
    QLabel *labelECRNumberQuery;
    QLineEdit *lineEditECRNumberQuery;
    QDialogButtonBox *buttonBoxQuery;
    QTableView *tableView;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPlatform;
    QLineEdit *lineEditPlatform;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelTypeNo;
    QLineEdit *lineEditTypeNo;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelECRNumber;
    QLineEdit *lineEditECRNumber;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelOperate;
    QRadioButton *radioButtonBreakpoint;
    QRadioButton *radioButtonRecover;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *textEditContent;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *buttonBoxInsertData;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ECRManagementSystemClass)
    {
        if (ECRManagementSystemClass->objectName().isEmpty())
            ECRManagementSystemClass->setObjectName(QStringLiteral("ECRManagementSystemClass"));
        ECRManagementSystemClass->resize(1177, 817);
        ECRManagementSystemClass->setStyleSheet(QLatin1String("#ECRManagementSystemClass{\n"
"border-image: url(:/ECRManagementSystem/Resources/bottom2.png);\n"
"}\n"
"#ECRManagementSystemClass * {\n"
"border-image: url();\n"
"}"));
        actionLogin = new QAction(ECRManagementSystemClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        QFont font;
        font.setPointSize(10);
        actionLogin->setFont(font);
        actionLogout = new QAction(ECRManagementSystemClass);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        centralWidget = new QWidget(ECRManagementSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelUAES = new QLabel(centralWidget);
        labelUAES->setObjectName(QStringLiteral("labelUAES"));
        labelUAES->setMinimumSize(QSize(189, 20));
        labelUAES->setMaximumSize(QSize(380, 80));
        labelUAES->setSizeIncrement(QSize(9, 1));
        labelUAES->setBaseSize(QSize(189, 20));
        labelUAES->setPixmap(QPixmap(QString::fromUtf8(":/ECRManagementSystem/Resources/\344\274\201\344\270\232\346\240\207\345\277\227\344\270\216\344\274\201\344\270\232\344\270\255\350\213\261\346\226\207\345\205\250\347\247\260\347\273\204\345\220\210_\350\223\235\357\274\215Logo with Company Name in Chinese and English_Blue.jpg")));
        labelUAES->setScaledContents(true);

        horizontalLayout->addWidget(labelUAES);

        labelTitle = new QLabel(centralWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setMinimumSize(QSize(500, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);
        labelTitle->setLayoutDirection(Qt::LeftToRight);
        labelTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelTitle);

        labelBOSCH = new QLabel(centralWidget);
        labelBOSCH->setObjectName(QStringLiteral("labelBOSCH"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelBOSCH->sizePolicy().hasHeightForWidth());
        labelBOSCH->setSizePolicy(sizePolicy);
        labelBOSCH->setMinimumSize(QSize(189, 20));
        labelBOSCH->setMaximumSize(QSize(380, 60));
        labelBOSCH->setSizeIncrement(QSize(2, 1));
        labelBOSCH->setBaseSize(QSize(569, 299));
        labelBOSCH->setPixmap(QPixmap(QString::fromUtf8(":/ECRManagementSystem/Resources/bosch.png")));
        labelBOSCH->setScaledContents(true);
        labelBOSCH->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelBOSCH);


        verticalLayout->addLayout(horizontalLayout);

        labelUnderline = new QLabel(centralWidget);
        labelUnderline->setObjectName(QStringLiteral("labelUnderline"));
        labelUnderline->setBaseSize(QSize(300, 0));
        labelUnderline->setPixmap(QPixmap(QString::fromUtf8(":/ECRManagementSystem/Resources/bottom.png")));
        labelUnderline->setScaledContents(true);

        verticalLayout->addWidget(labelUnderline);


        verticalLayout_2->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        tabWidget->setFont(font2);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_10 = new QHBoxLayout(tab);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelPlatformQuery = new QLabel(tab);
        labelPlatformQuery->setObjectName(QStringLiteral("labelPlatformQuery"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        labelPlatformQuery->setFont(font3);
        labelPlatformQuery->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(labelPlatformQuery);

        lineEditPlatformQuery = new QLineEdit(tab);
        lineEditPlatformQuery->setObjectName(QStringLiteral("lineEditPlatformQuery"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(14);
        lineEditPlatformQuery->setFont(font4);

        horizontalLayout_9->addWidget(lineEditPlatformQuery);

        labelTypeNoQuery = new QLabel(tab);
        labelTypeNoQuery->setObjectName(QStringLiteral("labelTypeNoQuery"));
        labelTypeNoQuery->setFont(font3);
        labelTypeNoQuery->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(labelTypeNoQuery);

        lineEditTypeNoQuery = new QLineEdit(tab);
        lineEditTypeNoQuery->setObjectName(QStringLiteral("lineEditTypeNoQuery"));
        lineEditTypeNoQuery->setFont(font4);

        horizontalLayout_9->addWidget(lineEditTypeNoQuery);

        labelECRNumberQuery = new QLabel(tab);
        labelECRNumberQuery->setObjectName(QStringLiteral("labelECRNumberQuery"));
        labelECRNumberQuery->setFont(font3);
        labelECRNumberQuery->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(labelECRNumberQuery);

        lineEditECRNumberQuery = new QLineEdit(tab);
        lineEditECRNumberQuery->setObjectName(QStringLiteral("lineEditECRNumberQuery"));
        lineEditECRNumberQuery->setFont(font4);

        horizontalLayout_9->addWidget(lineEditECRNumberQuery);

        buttonBoxQuery = new QDialogButtonBox(tab);
        buttonBoxQuery->setObjectName(QStringLiteral("buttonBoxQuery"));
        buttonBoxQuery->setMinimumSize(QSize(193, 28));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(9);
        buttonBoxQuery->setFont(font5);
        buttonBoxQuery->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        buttonBoxQuery->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        buttonBoxQuery->setCenterButtons(true);

        horizontalLayout_9->addWidget(buttonBoxQuery);


        verticalLayout_5->addLayout(horizontalLayout_9);

        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_5->addWidget(tableView);


        horizontalLayout_10->addLayout(verticalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_8 = new QHBoxLayout(tab_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelPlatform = new QLabel(tab_2);
        labelPlatform->setObjectName(QStringLiteral("labelPlatform"));
        labelPlatform->setFont(font3);
        labelPlatform->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labelPlatform);

        lineEditPlatform = new QLineEdit(tab_2);
        lineEditPlatform->setObjectName(QStringLiteral("lineEditPlatform"));
        lineEditPlatform->setFont(font4);

        horizontalLayout_3->addWidget(lineEditPlatform);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelTypeNo = new QLabel(tab_2);
        labelTypeNo->setObjectName(QStringLiteral("labelTypeNo"));
        labelTypeNo->setFont(font3);
        labelTypeNo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(labelTypeNo);

        lineEditTypeNo = new QLineEdit(tab_2);
        lineEditTypeNo->setObjectName(QStringLiteral("lineEditTypeNo"));
        lineEditTypeNo->setFont(font4);

        horizontalLayout_4->addWidget(lineEditTypeNo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelECRNumber = new QLabel(tab_2);
        labelECRNumber->setObjectName(QStringLiteral("labelECRNumber"));
        labelECRNumber->setFont(font3);
        labelECRNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labelECRNumber);

        lineEditECRNumber = new QLineEdit(tab_2);
        lineEditECRNumber->setObjectName(QStringLiteral("lineEditECRNumber"));
        lineEditECRNumber->setFont(font4);

        horizontalLayout_5->addWidget(lineEditECRNumber);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelOperate = new QLabel(tab_2);
        labelOperate->setObjectName(QStringLiteral("labelOperate"));
        labelOperate->setFont(font3);
        labelOperate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(labelOperate);

        radioButtonBreakpoint = new QRadioButton(tab_2);
        radioButtonBreakpoint->setObjectName(QStringLiteral("radioButtonBreakpoint"));
        radioButtonBreakpoint->setFont(font3);

        horizontalLayout_6->addWidget(radioButtonBreakpoint);

        radioButtonRecover = new QRadioButton(tab_2);
        radioButtonRecover->setObjectName(QStringLiteral("radioButtonRecover"));
        radioButtonRecover->setFont(font3);

        horizontalLayout_6->addWidget(radioButtonRecover);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_6);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font3);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEditContent = new QTextEdit(groupBox);
        textEditContent->setObjectName(QStringLiteral("textEditContent"));
        textEditContent->setFont(font4);

        gridLayout->addWidget(textEditContent, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        buttonBoxInsertData = new QDialogButtonBox(tab_2);
        buttonBoxInsertData->setObjectName(QStringLiteral("buttonBoxInsertData"));
        buttonBoxInsertData->setMinimumSize(QSize(193, 28));
        buttonBoxInsertData->setFont(font5);
        buttonBoxInsertData->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        buttonBoxInsertData->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        buttonBoxInsertData->setCenterButtons(true);

        horizontalLayout_7->addWidget(buttonBoxInsertData);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);

        ECRManagementSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ECRManagementSystemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1177, 29));
        menuBar->setFont(font);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setWeight(50);
        menu->setFont(font6);
        ECRManagementSystemClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ECRManagementSystemClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ECRManagementSystemClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionLogin);
        menu->addAction(actionLogout);

        retranslateUi(ECRManagementSystemClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ECRManagementSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *ECRManagementSystemClass)
    {
        ECRManagementSystemClass->setWindowTitle(QApplication::translate("ECRManagementSystemClass", "ECRManagementSystem", 0));
        actionLogin->setText(QApplication::translate("ECRManagementSystemClass", "\347\231\273\345\275\225", 0));
        actionLogout->setText(QApplication::translate("ECRManagementSystemClass", "\351\200\200\345\207\272", 0));
        labelUAES->setText(QString());
        labelTitle->setText(QApplication::translate("ECRManagementSystemClass", "ECR Management System", 0));
        labelBOSCH->setText(QString());
        labelUnderline->setText(QString());
        labelPlatformQuery->setText(QApplication::translate("ECRManagementSystemClass", "\345\271\263\345\217\260\357\274\232", 0));
        labelTypeNoQuery->setText(QApplication::translate("ECRManagementSystemClass", "\345\236\213\345\217\267\357\274\232", 0));
        labelECRNumberQuery->setText(QApplication::translate("ECRManagementSystemClass", "ECR\347\274\226\345\217\267\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ECRManagementSystemClass", "\346\237\245\350\257\242", 0));
        labelPlatform->setText(QApplication::translate("ECRManagementSystemClass", "      \345\271\263\345\217\260\357\274\232", 0));
        labelTypeNo->setText(QApplication::translate("ECRManagementSystemClass", "      \345\236\213\345\217\267\357\274\232", 0));
        labelECRNumber->setText(QApplication::translate("ECRManagementSystemClass", "ECR\347\274\226\345\217\267\357\274\232", 0));
        labelOperate->setText(QApplication::translate("ECRManagementSystemClass", "      \346\223\215\344\275\234\357\274\232", 0));
        radioButtonBreakpoint->setText(QApplication::translate("ECRManagementSystemClass", "ECR\346\226\255\347\202\271", 0));
        radioButtonRecover->setText(QApplication::translate("ECRManagementSystemClass", "ECR\345\210\207\345\233\236", 0));
        groupBox->setTitle(QApplication::translate("ECRManagementSystemClass", "ECR\345\206\205\345\256\271", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ECRManagementSystemClass", "\346\226\255\347\202\271/\345\210\207\345\233\236", 0));
        menu->setTitle(QApplication::translate("ECRManagementSystemClass", "\347\231\273\345\275\225/\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ECRManagementSystemClass: public Ui_ECRManagementSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECRMANAGEMENTSYSTEM_H
