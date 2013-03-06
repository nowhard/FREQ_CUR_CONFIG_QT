#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    port=new AbstractSerial(this);
    port->setTotalReadConstantTimeout(0);

    timer=new QTimer();

    p_uso=new proto_uso(this,port);
     QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));





   //  connect(p_uso,SIGNAL(DEV_INFO_RESPONSED(QByteArray)),this,SLOT(on_dev_info_responsed(QByteArray)));
    // connect(p_uso,SIGNAL(GET_ALL_DATA_RESPONSED()),this,SLOT(on_dev_get_data_responsed()));

  //   connect(ui->action_LOAD,SIGNAL(triggered()),this,SLOT(on_menu_load_settings_clicked()));
   //  connect(ui->action_SAVE,SIGNAL(triggered()),this,SLOT(on_menu_save_settings_clicked()));

     connect(timer,SIGNAL(timeout()),this,SLOT(Get_All_Data()));


     strlist<<tr("±10 ìÂ")<<tr("±20 ìÂ")<<tr("±40 ìÂ")<<tr("±80 ìÂ")<<tr("±160 ìÂ")<<tr("±320 ìÂ")<<tr("±640 Â")<<tr("±1.28 Â");
     read_flag=false;




}

MainWindow::~MainWindow()
{

    port->close();
    delete port;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   if(!port->isOpen())
    {
    port->setDeviceName(com_dlg.ui->comboBox->currentText());


    if ( !port->open(AbstractSerial::ReadWrite | AbstractSerial::Unbuffered) ) {
        qDebug() << "Serial device by default: " << port->deviceName() << " open fail.";
        ui->statusBar->showMessage("Port Open Fail");
        return;
    }
    if (!port->setBaudRate(AbstractSerial::BaudRate57600/*com_dlg.ui->comboBox_2->currentText()*/)) {
        qDebug() << "Set baud rate  error.";
        return;
    };

    if (!port->setDataBits(AbstractSerial::DataBits8)) {
        qDebug() << "Set data bits " <<  AbstractSerial::DataBits8 << " error.";
        return;
    }
    if (!port->setParity(AbstractSerial::ParityNone)) {
        qDebug() << "Set parity " <<  AbstractSerial::ParityNone << " error.";
        return;
    }

   if(com_dlg.ui->radioButton->isChecked())
    {
        if (!port->setStopBits(AbstractSerial::StopBits1)) {
            qDebug() << "Set stop bits " <<  AbstractSerial::StopBits1 << " error.";
            return;
        }
    }
   else
   {
       if (!port->setStopBits(AbstractSerial::StopBits2)) {
           qDebug() << "Set stop bits " <<  AbstractSerial::StopBits2 << " error.";
           return;
       }
   }

    if (!port->setFlowControl(AbstractSerial::FlowControlOff)) {
        qDebug() << "Set flow " <<  AbstractSerial::FlowControlOff << " error.";
        return;
    }

    if (port->openMode() & AbstractSerial::Unbuffered)
        port->setTotalReadConstantTimeout(10);

     //port->setCharIntervalTimeout(int((8*1000000/com_dlg.ui->comboBox_2->currentText().toInt())));

    ui->pushButton->setText(tr("Îòêëþ÷èòü"));

     //timer->start(30);

     qDebug() << "Serial device : " << port->deviceName() << " opened!!!.";
     qDebug() << "Serial device baudrate : " << port->baudRate() ;
     qDebug() << "Serial device databits : " << port->dataBits() ;
     qDebug() << "Serial device stopbits : " << port->stopBits() ;
     qDebug() << "Serial device flowcontrol : " << port->flowControl() ;


 }
else
   {
        port->close();
        ui->pushButton->setText(tr("Ïîäêëþ÷èòü"));
\
         //timer->stop();
    }
}


void MainWindow::on_action_COM_triggered()
{
    com_dlg.show();
}

/*void MainWindow::MessageReadOK(bool mess)
{
    if(mess)
    {
       ui->statusBar->showMessage("Device Read OK");
       //Get_All_Data();
    }
    else
    {
       ui->statusBar->showMessage("Device Read Error");
    }
}*/





void MainWindow::on_pushButton_3_clicked()
{
   // p_uso->GET_DEV_INFO_REQ(ui->comboBox_5->currentText().toInt());
    p_uso->CHANNEL_SET_CALIBRATE(ui->comboBox_5->currentText().toInt(),ui->spinBox_2->value(),ui->spinBox_3->value());
}

//void MainWindow::on_dev_info_responsed(QByteArray response)
//{


//    return;
//}

//void MainWindow::on_set_dev_info_clicked(void)
//{

//    QByteArray settings;
//    union
//    {
//        quint8 res[4];
//        float result;
//    };


//    return;
//}

void MainWindow::on_pushButton_4_clicked()
{
    p_uso->CHANNEL_SET_PARAMETERS_REQ(ui->comboBox_5->currentText().toInt(),ui->radioButton_2->isChecked(),1,ui->spinBox->value());
}

void MainWindow::on_pushButton_2_clicked()
{
    p_uso->CHANNEL_SET_PARAMETERS_REQ(ui->comboBox_5->currentText().toInt(),ui->radioButton_2->isChecked(),0,ui->spinBox->value());
}
