#include "dialog_com.h"
#include "ui_dialog_com.h"

Dialog_com::Dialog_com(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_com)
{
    ui->setupUi(this);

    QSettings *settings = new QSettings("settings.ini",QSettings::IniFormat);

    ui->comboBox->setCurrentIndex(settings->value("com_port/port",0).toInt());  //устанавливаем значение

    ui->comboBox_2->setCurrentIndex(settings->value("com_port/speed",0).toInt());  //устанавливаем значение

    ui->radioButton->setChecked(settings->value("com_port/stop_bit",true).toBool());  //устанавливаем значение

    qDebug() << "COM INIT";
}

Dialog_com::~Dialog_com()
{
    delete ui;
}

void Dialog_com::on_buttonBox_accepted()
{
   // QString integer;
    QSettings *settings = new QSettings("settings.ini",QSettings::IniFormat);
    settings->clear();

    settings->setValue("com_port/port",ui->comboBox->currentIndex());  //устанавливаем значение
    settings->setValue("com_port/speed",ui->comboBox_2->currentIndex());  //устанавливаем значение
    settings->setValue("com_port/stop_bit",ui->radioButton->isChecked());  //устанавливаем значение


    settings->sync(); //записываем настройки
    qDebug() << "COM SAVED";
}
