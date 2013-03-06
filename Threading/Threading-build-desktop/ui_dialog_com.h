/********************************************************************************
** Form generated from reading UI file 'dialog_com.ui'
**
** Created: Tue 28. Feb 14:10:05 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_COM_H
#define UI_DIALOG_COM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_com
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *Dialog_com)
    {
        if (Dialog_com->objectName().isEmpty())
            Dialog_com->setObjectName(QString::fromUtf8("Dialog_com"));
        Dialog_com->resize(265, 229);
        buttonBox = new QDialogButtonBox(Dialog_com);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 190, 211, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Dialog_com);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 231, 161));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 20, 74, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 46, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 111, 31));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 60, 81, 22));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 110, 71, 16));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(110, 110, 41, 18));
        radioButton->setChecked(false);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(170, 110, 31, 18));
        radioButton_2->setChecked(true);

        retranslateUi(Dialog_com);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_com, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_com, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_com);
    } // setupUi

    void retranslateUi(QDialog *Dialog_com)
    {
        Dialog_com->setWindowTitle(QApplication::translate("Dialog_com", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog_com", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog_com", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "COM10", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("Dialog_com", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_com", "          \320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \n"
" \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\270 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Dialog_com", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog_com", "115200", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("Dialog_com", "\320\241\321\202\320\276\320\277 \320\261\320\270\321\202\321\213", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Dialog_com", "1", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Dialog_com", "2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_com: public Ui_Dialog_com {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_COM_H
