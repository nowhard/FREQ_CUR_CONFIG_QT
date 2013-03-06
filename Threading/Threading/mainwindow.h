#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "com_thread.h"
#include <abstractserial.h>
#include <QDebug>
#include <QTimer>
#include "serial_io.h"
#include "proto_uso.h"

#include "dialog_com.h"
#include "ui_dialog_com.h"
#include "delegate.h"
#include <QTextCodec>
#include <QStringList>
#include <QCheckBox>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QIODevice>
#include <QSettings>
#include <QVector>
#include <QPointF>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:


private:
    class CalibrPoints
    {
    public:
        unsigned long first_point_x;
        unsigned long first_point_y;
        unsigned long second_point_x;
        unsigned long second_point_y;
    };
    Ui::MainWindow *ui;

    //---------------------
    AbstractSerial *port;
   // Serial_IO *srl_io;

    proto_uso *p_uso;
    //---------------------
    //MB_Register reg_pack;
    //---------------------
    QTimer *timer;
  //  QTimer *timer2;
  //  QTimer *query_timer;
   // QFile settings;

    //---------------------
    Dialog_com com_dlg;

  //  quint16 query_counter;
  //  bool read_reg_flag;
  //  quint8 addr_counter;
    bool read_flag;
    QStringList strlist;
    CHANNEL *chnl[11];
    QVector<CalibrPoints*> CalibrList;

private slots:



    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_action_COM_triggered();

    void on_pushButton_clicked();
   // void on_dev_info_responsed(QByteArray);
  //  void on_set_dev_info_clicked(void);
 //   void on_dev_get_data_responsed(void);
  //  void on_Reg_Read(QByteArray registers);
   // void on_Reg_Read(MB_Register reg,QByteArray registers);


  //  void MessageReadOK(bool mess);
   // void MessageWriteOK(bool mess);
  //  void MessageNotConnected(void);



//    void Display_Dev_Info(bool OK,quint16 ID, QString Description);
//    void Info_Is_Set(bool OK);
 //   void Get_All_Data(void);



 //   void on_calibrate_0_button_clicked();
 //   void on_calibrate_full_button_clicked();
 //   void on_calibrate_flag_clicked();
  //  void on_calibrate_set_button_clicked();

  //  void on_menu_load_settings_clicked();
   // void on_menu_save_settings_clicked();

};




#endif // MAINWINDOW_H
