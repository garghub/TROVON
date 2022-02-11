void F_1 ( T_1 V_1 )
{
F_2 ( V_2 L_1 , V_1 ) ;
F_3 ( V_3 , 0x0D , V_1 & 0xFF ) ;
F_3 ( V_3 , 0x0C , ( V_1 >> 8 ) & 0xFF ) ;
F_3 ( V_3 , 0x34 , ( V_1 >> 16 ) & 0xFF ) ;
F_4 ( V_3 , 0x48 , ( V_1 >> 24 ) & 0x1F , 0x1F ) ;
}
void F_5 ( T_1 V_1 )
{
F_2 ( V_2 L_2 , V_1 ) ;
F_4 ( V_3 , 0x62 , ( V_1 >> 2 ) & 0xFE , 0xFE ) ;
F_3 ( V_3 , 0x63 , ( V_1 >> 10 ) & 0xFF ) ;
F_3 ( V_3 , 0x64 , ( V_1 >> 18 ) & 0xFF ) ;
F_4 ( V_3 , 0xA3 , ( V_1 >> 26 ) & 0x07 , 0x07 ) ;
}
void F_6 ( T_1 V_4 )
{
F_2 ( V_2 L_3 , V_4 ) ;
V_4 = V_4 >> 3 ;
F_3 ( V_3 , 0x13 , V_4 & 0xFF ) ;
F_4 ( V_3 , 0x35 , ( V_4 >> ( 8 - 5 ) ) & 0xE0 , 0xE0 ) ;
}
void F_7 ( T_1 V_4 )
{
F_2 ( V_2 L_4 , V_4 ) ;
V_4 = V_4 >> 3 ;
F_3 ( V_3 , 0x66 , V_4 & 0xFF ) ;
F_4 ( V_3 , 0x67 , ( V_4 >> 8 ) & 0x03 , 0x03 ) ;
F_4 ( V_3 , 0x71 , ( V_4 >> ( 10 - 7 ) ) & 0x80 , 0x80 ) ;
}
void F_8 ( T_2 V_5 )
{
T_2 V_6 ;
F_2 ( V_2 L_5 , V_5 ) ;
switch ( V_5 ) {
case 8 :
V_6 = 0x00 ;
break;
case 15 :
V_6 = 0x04 ;
break;
case 16 :
V_6 = 0x14 ;
break;
case 24 :
V_6 = 0x0C ;
break;
case 30 :
V_6 = 0x08 ;
break;
default:
F_9 ( V_7 L_6
L_7 , V_5 ) ;
return;
}
F_4 ( V_8 , 0x15 , V_6 , 0x1C ) ;
}
void F_10 ( T_2 V_5 )
{
T_2 V_6 ;
F_2 ( V_2 L_8 , V_5 ) ;
switch ( V_5 ) {
case 8 :
V_6 = 0x00 ;
break;
case 16 :
V_6 = 0x40 ;
break;
case 24 :
V_6 = 0xC0 ;
break;
case 30 :
V_6 = 0x80 ;
break;
default:
F_9 ( V_7 L_9
L_7 , V_5 ) ;
return;
}
F_4 ( V_3 , 0x67 , V_6 , 0xC0 ) ;
}
