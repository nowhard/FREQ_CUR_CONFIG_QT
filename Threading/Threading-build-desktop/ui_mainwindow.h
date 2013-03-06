/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 26. Jul 14:47:51 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_COM;
    QAction *action;
    QAction *action_SAVE;
    QAction *action_LOAD;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label_16;
    QComboBox *comboBox_5;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QSpinBox *spinBox;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_3;
    QSpinBox *spinBox_2;
    QLabel *label;
    QSpinBox *spinBox_3;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(330, 440);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(330, 440));
        MainWindow->setMaximumSize(QSize(330, 440));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferDefault);
        MainWindow->setFont(font);
        action_COM = new QAction(MainWindow);
        action_COM->setObjectName(QString::fromUtf8("action_COM"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_SAVE = new QAction(MainWindow);
        action_SAVE->setObjectName(QString::fromUtf8("action_SAVE"));
        action_LOAD = new QAction(MainWindow);
        action_LOAD->setObjectName(QString::fromUtf8("action_LOAD"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 311, 61));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(210, 20, 75, 23));
        QPalette palette;
        QBrush brush(QColor(52, 212, 28, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButton->setPalette(palette);
        pushButton->setCheckable(false);
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 20, 91, 16));
        comboBox_5 = new QComboBox(groupBox);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(120, 20, 51, 22));
        comboBox_5->setMaxVisibleItems(15);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 80, 311, 291));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 291, 81));
        radioButton = new QRadioButton(groupBox_2);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 20, 82, 18));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        radioButton->setFont(font1);
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox_2);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 50, 82, 18));
        radioButton_2->setFont(font1);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 20, 31, 23));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 50, 31, 23));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(160, 30, 61, 31));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10);
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 110, 291, 171));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 120, 111, 23));
        spinBox_2 = new QSpinBox(groupBox_4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(20, 21, 71, 31));
        spinBox_2->setMinimum(10);
        spinBox_2->setMaximum(255);
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 30, 111, 16));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        spinBox_3 = new QSpinBox(groupBox_4);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(20, 70, 71, 31));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(20);
        spinBox_3->setValue(20);
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 80, 191, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        label_2->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 330, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_COM);
        menu_2->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260-\321\202\320\276\320\272.\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        action_COM->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        action_SAVE->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        action_LOAD->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8)
        );
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\263\320\276\320\275\320\272\320\260  min, max", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "4 \320\274\320\220", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "20 \320\274\320\220", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Hz=20\320\274\320\220", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
