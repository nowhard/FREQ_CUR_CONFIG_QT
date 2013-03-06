#ifndef MB_REGISTER_H
#define MB_REGISTER_H

#include<QString>

class MB_Register
{
public:
    MB_Register(quint8 ID,quint16 address,quint8 length,quint8 data_type,QString description);
    MB_Register();
    quint8 ID;
    quint16 address;
    quint8 length;
    quint8 data_type;
    QString description;

    enum {mb_int=1,mb_float=2};
    enum{TEMP_REG=0,PRESSURE_REG=2,DENSITY_REG=4,DENSITY_REG_NOT_COMPENSED=6,CRC_ERR_CNT_REG=8,COMMAND_ERR_CNT_REG=9,TIMEOUT_15_ERR=10};

};

#endif // MB_REGISTER_H
