/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *menu_screen;
    QPushButton *downarrow;
    QPushButton *uparrow;
    QPushButton *leftarrow;
    QPushButton *rightarrow;
    QPushButton *ok;
    QPushButton *power;
    QPushButton *mainmenu;
    QPushButton *back;
    QListWidget *programs_screen;
    QListWidget *freq_screen;
    QProgressBar *battery;
    QCheckBox *electrode;
    QListWidget *power_screen;
    QProgressBar *power_level;
    QLabel *power_label;
    QListWidget *session_screen;
    QLabel *session_time;
    QListWidget *freq_power_screen;
    QLabel *freq_session;
    QLabel *current_freq;
    QLabel *next_freq;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(346, 546);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        menu_screen = new QListWidget(centralWidget);
        menu_screen->setObjectName(QString::fromUtf8("menu_screen"));
        menu_screen->setGeometry(QRect(20, 20, 301, 141));
        menu_screen->setAutoFillBackground(true);
        menu_screen->setStyleSheet(QString::fromUtf8("QListWidget{background: black}"));
        downarrow = new QPushButton(centralWidget);
        downarrow->setObjectName(QString::fromUtf8("downarrow"));
        downarrow->setGeometry(QRect(150, 350, 40, 40));
        downarrow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        uparrow = new QPushButton(centralWidget);
        uparrow->setObjectName(QString::fromUtf8("uparrow"));
        uparrow->setGeometry(QRect(150, 210, 40, 40));
        uparrow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        leftarrow = new QPushButton(centralWidget);
        leftarrow->setObjectName(QString::fromUtf8("leftarrow"));
        leftarrow->setGeometry(QRect(80, 280, 40, 40));
        leftarrow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        rightarrow = new QPushButton(centralWidget);
        rightarrow->setObjectName(QString::fromUtf8("rightarrow"));
        rightarrow->setGeometry(QRect(220, 280, 40, 40));
        rightarrow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        ok = new QPushButton(centralWidget);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(150, 280, 40, 40));
        ok->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        power = new QPushButton(centralWidget);
        power->setObjectName(QString::fromUtf8("power"));
        power->setGeometry(QRect(150, 430, 40, 40));
        power->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        mainmenu = new QPushButton(centralWidget);
        mainmenu->setObjectName(QString::fromUtf8("mainmenu"));
        mainmenu->setGeometry(QRect(290, 170, 40, 40));
        mainmenu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        back = new QPushButton(centralWidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 170, 40, 40));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        programs_screen = new QListWidget(centralWidget);
        programs_screen->setObjectName(QString::fromUtf8("programs_screen"));
        programs_screen->setGeometry(QRect(20, 20, 301, 141));
        freq_screen = new QListWidget(centralWidget);
        freq_screen->setObjectName(QString::fromUtf8("freq_screen"));
        freq_screen->setGeometry(QRect(20, 20, 301, 141));
        battery = new QProgressBar(centralWidget);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(270, 0, 51, 20));
        battery->setStyleSheet(QString::fromUtf8("QProgressBar::chunk{background:rgb(39, 254, 29)}"));
        battery->setValue(100);
        electrode = new QCheckBox(centralWidget);
        electrode->setObjectName(QString::fromUtf8("electrode"));
        electrode->setGeometry(QRect(239, 460, 101, 31));
        power_screen = new QListWidget(centralWidget);
        power_screen->setObjectName(QString::fromUtf8("power_screen"));
        power_screen->setGeometry(QRect(20, 20, 301, 141));
        power_level = new QProgressBar(centralWidget);
        power_level->setObjectName(QString::fromUtf8("power_level"));
        power_level->setGeometry(QRect(110, 70, 118, 23));
        power_level->setValue(0);
        power_label = new QLabel(centralWidget);
        power_label->setObjectName(QString::fromUtf8("power_label"));
        power_label->setGeometry(QRect(120, 30, 91, 41));
        session_screen = new QListWidget(centralWidget);
        session_screen->setObjectName(QString::fromUtf8("session_screen"));
        session_screen->setGeometry(QRect(20, 20, 301, 141));
        session_time = new QLabel(centralWidget);
        session_time->setObjectName(QString::fromUtf8("session_time"));
        session_time->setGeometry(QRect(110, 70, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Gothic L"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        session_time->setFont(font);
        freq_power_screen = new QListWidget(centralWidget);
        freq_power_screen->setObjectName(QString::fromUtf8("freq_power_screen"));
        freq_power_screen->setGeometry(QRect(20, 20, 301, 141));
        freq_session = new QLabel(centralWidget);
        freq_session->setObjectName(QString::fromUtf8("freq_session"));
        freq_session->setGeometry(QRect(110, 70, 121, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("URW Gothic L"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        freq_session->setFont(font1);
        current_freq = new QLabel(centralWidget);
        current_freq->setObjectName(QString::fromUtf8("current_freq"));
        current_freq->setGeometry(QRect(30, 139, 161, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setWeight(75);
        current_freq->setFont(font2);
        next_freq = new QLabel(centralWidget);
        next_freq->setObjectName(QString::fromUtf8("next_freq"));
        next_freq->setGeometry(QRect(30, 139, 161, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font3.setPointSize(7);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        next_freq->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        current_freq->raise();
        freq_session->raise();
        freq_power_screen->raise();
        session_time->raise();
        session_screen->raise();
        power_label->raise();
        power_level->raise();
        power_screen->raise();
        freq_screen->raise();
        programs_screen->raise();
        menu_screen->raise();
        downarrow->raise();
        uparrow->raise();
        leftarrow->raise();
        rightarrow->raise();
        ok->raise();
        power->raise();
        mainmenu->raise();
        back->raise();
        battery->raise();
        electrode->raise();
        next_freq->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 346, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        downarrow->setText(QString());
        uparrow->setText(QString());
        leftarrow->setText(QString());
        rightarrow->setText(QString());
        ok->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        power->setText(QString());
        mainmenu->setText(QString());
        back->setText(QString());
        electrode->setText(QCoreApplication::translate("MainWindow", "Electrode", nullptr));
        power_label->setText(QCoreApplication::translate("MainWindow", "Power Level", nullptr));
        session_time->setText(QCoreApplication::translate("MainWindow", "               0", nullptr));
        freq_session->setText(QCoreApplication::translate("MainWindow", "        0 ", nullptr));
        current_freq->setText(QString());
        next_freq->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
