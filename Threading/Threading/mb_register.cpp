#include "mb_register.h"

MB_Register::MB_Register(quint8 ID,quint16 address,quint8 length,quint8 data_type,QString description)
{
    this->ID=ID;
    this->address=address;
    this->length=length;
    this->data_type=data_type;
    this->description=description;
}

MB_Register::MB_Register()
{
    ID=0;
    address=0;
    length=1;
    data_type=MB_Register::mb_int;
    description="DEFAULT";
}
