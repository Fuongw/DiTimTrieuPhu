/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *cat_hoi;
    QPushButton *btn_5050;
    QPushButton *btn_CallFriend;
    QPushButton *btn_Swap;
    QLabel *lbl_Question;
    QPushButton *btn_AnswerA;
    QPushButton *btn_AnswerB;
    QPushButton *btn_AnswerC;
    QPushButton *btn_AnswerD;
    QLabel *lbl_Money;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1095, 668);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        cat_hoi = new QLabel(centralwidget);
        cat_hoi->setObjectName("cat_hoi");
        cat_hoi->setGeometry(QRect(-40, -140, 1151, 921));
        cat_hoi->setPixmap(QPixmap(QString::fromUtf8("images/cat_hoi.gif")));
        btn_5050 = new QPushButton(centralwidget);
        btn_5050->setObjectName("btn_5050");
        btn_5050->setGeometry(QRect(730, 50, 81, 51));
        btn_5050->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_5050->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        btn_CallFriend = new QPushButton(centralwidget);
        btn_CallFriend->setObjectName("btn_CallFriend");
        btn_CallFriend->setGeometry(QRect(830, 50, 81, 51));
        btn_CallFriend->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_CallFriend->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        btn_Swap = new QPushButton(centralwidget);
        btn_Swap->setObjectName("btn_Swap");
        btn_Swap->setGeometry(QRect(930, 50, 81, 51));
        btn_Swap->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_Swap->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        lbl_Question = new QLabel(centralwidget);
        lbl_Question->setObjectName("lbl_Question");
        lbl_Question->setGeometry(QRect(200, 330, 701, 111));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lbl_Question->setFont(font);
        lbl_Question->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        lbl_Question->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lbl_Question->setWordWrap(true);
        btn_AnswerA = new QPushButton(centralwidget);
        btn_AnswerA->setObjectName("btn_AnswerA");
        btn_AnswerA->setGeometry(QRect(140, 460, 341, 31));
        btn_AnswerA->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_AnswerA->setStyleSheet(QString::fromUtf8("/* Tr\341\272\241ng th\303\241i b\303\254nh th\306\260\341\273\235ng */\n"
"QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white; \n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    text-align: left; \n"
"    padding-left: 20px; \n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi r\303\252 chu\341\273\231t v\303\240o (Hover) */\n"
"QPushButton:hover {\n"
"    color: #FFD700; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u V\303\240ng Gold */\n"
"    background-color: rgba(255, 255, 255, 0.1); /* Ph\341\273\247 m\341\273\231t l\341\273\233p tr\341\272\257ng m\341\273\235 10% l\303\252n n\303\272t */\n"
"    border-radius: 20px; /* Bo g\303\263c v\341\273\207t s\303\241ng cho h\341\273\243p v\341\273\233i h\303\254nh l\341\273\245c gi\303\241c */\n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi click chu\341\273\231t xu\341\273\221ng (Pressed) */\n"
"QPushButton:pressed {\n"
"    color: #FF8C00; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u "
                        "Cam */\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"}"));
        btn_AnswerB = new QPushButton(centralwidget);
        btn_AnswerB->setObjectName("btn_AnswerB");
        btn_AnswerB->setGeometry(QRect(590, 460, 371, 31));
        btn_AnswerB->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_AnswerB->setStyleSheet(QString::fromUtf8("/* Tr\341\272\241ng th\303\241i b\303\254nh th\306\260\341\273\235ng */\n"
"QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white; \n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    text-align: left; \n"
"    padding-left: 20px; \n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi r\303\252 chu\341\273\231t v\303\240o (Hover) */\n"
"QPushButton:hover {\n"
"    color: #FFD700; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u V\303\240ng Gold */\n"
"    background-color: rgba(255, 255, 255, 0.1); /* Ph\341\273\247 m\341\273\231t l\341\273\233p tr\341\272\257ng m\341\273\235 10% l\303\252n n\303\272t */\n"
"    border-radius: 20px; /* Bo g\303\263c v\341\273\207t s\303\241ng cho h\341\273\243p v\341\273\233i h\303\254nh l\341\273\245c gi\303\241c */\n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi click chu\341\273\231t xu\341\273\221ng (Pressed) */\n"
"QPushButton:pressed {\n"
"    color: #FF8C00; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u "
                        "Cam */\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"}"));
        btn_AnswerC = new QPushButton(centralwidget);
        btn_AnswerC->setObjectName("btn_AnswerC");
        btn_AnswerC->setGeometry(QRect(140, 520, 341, 31));
        btn_AnswerC->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_AnswerC->setStyleSheet(QString::fromUtf8("/* Tr\341\272\241ng th\303\241i b\303\254nh th\306\260\341\273\235ng */\n"
"QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white; \n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    text-align: left; \n"
"    padding-left: 20px; \n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi r\303\252 chu\341\273\231t v\303\240o (Hover) */\n"
"QPushButton:hover {\n"
"    color: #FFD700; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u V\303\240ng Gold */\n"
"    background-color: rgba(255, 255, 255, 0.1); /* Ph\341\273\247 m\341\273\231t l\341\273\233p tr\341\272\257ng m\341\273\235 10% l\303\252n n\303\272t */\n"
"    border-radius: 20px; /* Bo g\303\263c v\341\273\207t s\303\241ng cho h\341\273\243p v\341\273\233i h\303\254nh l\341\273\245c gi\303\241c */\n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi click chu\341\273\231t xu\341\273\221ng (Pressed) */\n"
"QPushButton:pressed {\n"
"    color: #FF8C00; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u "
                        "Cam */\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"}"));
        btn_AnswerD = new QPushButton(centralwidget);
        btn_AnswerD->setObjectName("btn_AnswerD");
        btn_AnswerD->setGeometry(QRect(590, 520, 371, 31));
        btn_AnswerD->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_AnswerD->setStyleSheet(QString::fromUtf8("/* Tr\341\272\241ng th\303\241i b\303\254nh th\306\260\341\273\235ng */\n"
"QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white; \n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    text-align: left; \n"
"    padding-left: 20px; \n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi r\303\252 chu\341\273\231t v\303\240o (Hover) */\n"
"QPushButton:hover {\n"
"    color: #FFD700; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u V\303\240ng Gold */\n"
"    background-color: rgba(255, 255, 255, 0.1); /* Ph\341\273\247 m\341\273\231t l\341\273\233p tr\341\272\257ng m\341\273\235 10% l\303\252n n\303\272t */\n"
"    border-radius: 20px; /* Bo g\303\263c v\341\273\207t s\303\241ng cho h\341\273\243p v\341\273\233i h\303\254nh l\341\273\245c gi\303\241c */\n"
"}\n"
"\n"
"/* Tr\341\272\241ng th\303\241i khi click chu\341\273\231t xu\341\273\221ng (Pressed) */\n"
"QPushButton:pressed {\n"
"    color: #FF8C00; /* \304\220\341\273\225i ch\341\273\257 sang m\303\240u "
                        "Cam */\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"}"));
        lbl_Money = new QLabel(centralwidget);
        lbl_Money->setObjectName("lbl_Money");
        lbl_Money->setGeometry(QRect(105, 40, 201, 41));
        lbl_Money->setStyleSheet(QString::fromUtf8("color: #d35400; font-weight: bold;"));
        lbl_Money->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        cat_hoi->raise();
        lbl_Question->raise();
        btn_AnswerD->raise();
        btn_AnswerC->raise();
        btn_AnswerA->raise();
        btn_CallFriend->raise();
        btn_Swap->raise();
        btn_5050->raise();
        btn_AnswerB->raise();
        lbl_Money->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1095, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        cat_hoi->setText(QString());
        btn_5050->setText(QString());
        btn_CallFriend->setText(QString());
        btn_Swap->setText(QString());
        lbl_Question->setText(QCoreApplication::translate("MainWindow", "N\341\273\231i dung c\303\242u h\341\273\217i s\341\272\275 hi\341\273\203n th\341\273\213 \341\273\237 \304\221\303\242y...", nullptr));
        btn_AnswerA->setText(QCoreApplication::translate("MainWindow", "A. \304\220\303\241p \303\241n th\341\273\251 nh\341\272\245t", nullptr));
        btn_AnswerB->setText(QCoreApplication::translate("MainWindow", "B. \304\220\303\241p \303\241n th\341\273\251 hai", nullptr));
        btn_AnswerC->setText(QCoreApplication::translate("MainWindow", "C. \304\220\303\241p \303\241n th\341\273\251 ba", nullptr));
        btn_AnswerD->setText(QCoreApplication::translate("MainWindow", "D. \304\220\303\241p \303\241n th\341\273\251 b\341\273\221n", nullptr));
        lbl_Money->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
