void F_1 ( const struct V_1 * V_2 )
{
struct V_1 V_3 ;
V_3 . V_4 = V_2 -> V_4 / 8 - 5 ;
V_3 . V_5 = V_2 -> V_5 / 8 - 1 ;
V_3 . V_6 = V_2 -> V_6 / 8 - 1 ;
V_3 . V_7 = V_2 -> V_7 / 8 - 1 ;
V_3 . V_8 = V_2 -> V_8 / 8 ;
V_3 . V_9 = V_2 -> V_9 / 8 ;
V_3 . V_10 = V_2 -> V_10 - 2 ;
V_3 . V_11 = V_2 -> V_11 - 1 ;
V_3 . V_12 = V_2 -> V_12 - 1 ;
V_3 . V_13 = V_2 -> V_13 - 1 ;
V_3 . V_14 = V_2 -> V_14 - 1 ;
V_3 . V_15 = V_2 -> V_15 - 1 ;
F_2 ( V_16 , 0x11 , 0x00 , 0x80 ) ;
F_3 ( V_16 , 0x00 , V_3 . V_4 & 0xFF ) ;
F_3 ( V_16 , 0x01 , V_3 . V_5 & 0xFF ) ;
F_3 ( V_16 , 0x02 , V_3 . V_6 & 0xFF ) ;
F_2 ( V_16 , 0x03 , V_3 . V_7 & 0x1F , 0x1F ) ;
F_3 ( V_16 , 0x04 , V_3 . V_8 & 0xFF ) ;
F_2 ( V_16 , 0x05 , ( V_3 . V_9 & 0x1F )
| ( V_3 . V_7 << ( 7 - 5 ) & 0x80 ) , 0x9F ) ;
F_3 ( V_16 , 0x06 , V_3 . V_10 & 0xFF ) ;
F_2 ( V_16 , 0x07 , ( V_3 . V_10 >> 8 & 0x01 )
| ( V_3 . V_11 >> ( 8 - 1 ) & 0x02 )
| ( V_3 . V_14 >> ( 8 - 2 ) & 0x04 )
| ( V_3 . V_12 >> ( 8 - 3 ) & 0x08 )
| ( V_3 . V_10 >> ( 9 - 5 ) & 0x20 )
| ( V_3 . V_11 >> ( 9 - 6 ) & 0x40 )
| ( V_3 . V_14 >> ( 9 - 7 ) & 0x80 ) , 0xEF ) ;
F_2 ( V_16 , 0x09 , V_3 . V_12 >> ( 9 - 5 ) & 0x20 ,
0x20 ) ;
F_3 ( V_16 , 0x10 , V_3 . V_14 & 0xFF ) ;
F_2 ( V_16 , 0x11 , V_3 . V_15 & 0x0F , 0x0F ) ;
F_3 ( V_16 , 0x12 , V_3 . V_11 & 0xFF ) ;
F_3 ( V_16 , 0x15 , V_3 . V_12 & 0xFF ) ;
F_3 ( V_16 , 0x16 , V_3 . V_13 & 0xFF ) ;
F_2 ( V_16 , 0x33 , ( V_3 . V_8 >> ( 8 - 4 ) & 0x10 )
| ( V_3 . V_7 >> ( 6 - 5 ) & 0x20 ) , 0x30 ) ;
F_2 ( V_16 , 0x35 , ( V_3 . V_10 >> 10 & 0x01 )
| ( V_3 . V_14 >> ( 10 - 1 ) & 0x02 )
| ( V_3 . V_11 >> ( 10 - 2 ) & 0x04 )
| ( V_3 . V_12 >> ( 10 - 3 ) & 0x08 ) , 0x0F ) ;
F_2 ( V_16 , 0x36 , V_3 . V_4 >> ( 8 - 3 ) & 0x08 , 0x08 ) ;
F_2 ( V_16 , 0x11 , 0x80 , 0x80 ) ;
F_2 ( V_16 , 0x17 , 0x00 , 0x80 ) ;
F_2 ( V_16 , 0x17 , 0x80 , 0x80 ) ;
}
void F_4 ( const struct V_1 * V_2 )
{
struct V_1 V_3 ;
V_3 . V_4 = V_2 -> V_4 - 1 ;
V_3 . V_5 = V_2 -> V_5 - 1 ;
V_3 . V_6 = V_2 -> V_6 - 1 ;
V_3 . V_7 = V_2 -> V_7 - 1 ;
V_3 . V_8 = V_2 -> V_8 - 1 ;
V_3 . V_9 = V_2 -> V_9 - 1 ;
V_3 . V_10 = V_2 -> V_10 - 1 ;
V_3 . V_11 = V_2 -> V_11 - 1 ;
V_3 . V_12 = V_2 -> V_12 - 1 ;
V_3 . V_13 = V_2 -> V_13 - 1 ;
V_3 . V_14 = V_2 -> V_14 - 1 ;
V_3 . V_15 = V_2 -> V_15 - 1 ;
F_3 ( V_16 , 0x50 , V_3 . V_4 & 0xFF ) ;
F_3 ( V_16 , 0x51 , V_3 . V_5 & 0xFF ) ;
F_3 ( V_16 , 0x52 , V_3 . V_6 & 0xFF ) ;
F_3 ( V_16 , 0x53 , V_3 . V_7 & 0xFF ) ;
F_3 ( V_16 , 0x54 , ( V_3 . V_6 >> 8 & 0x07 )
| ( V_3 . V_7 >> ( 8 - 3 ) & 0x38 )
| ( V_3 . V_8 >> ( 8 - 6 ) & 0xC0 ) ) ;
F_2 ( V_16 , 0x55 , ( V_3 . V_4 >> 8 & 0x0F )
| ( V_3 . V_5 >> ( 8 - 4 ) & 0x70 ) , 0x7F ) ;
F_3 ( V_16 , 0x56 , V_3 . V_8 & 0xFF ) ;
F_3 ( V_16 , 0x57 , V_3 . V_9 & 0xFF ) ;
F_3 ( V_16 , 0x58 , V_3 . V_10 & 0xFF ) ;
F_3 ( V_16 , 0x59 , V_3 . V_11 & 0xFF ) ;
F_3 ( V_16 , 0x5A , V_3 . V_12 & 0xFF ) ;
F_3 ( V_16 , 0x5B , V_3 . V_13 & 0xFF ) ;
F_3 ( V_16 , 0x5C , ( V_3 . V_12 >> 8 & 0x07 )
| ( V_3 . V_13 >> ( 8 - 3 ) & 0x38 )
| ( V_3 . V_9 >> ( 8 - 6 ) & 0x40 )
| ( V_3 . V_8 >> ( 10 - 7 ) & 0x80 ) ) ;
F_3 ( V_16 , 0x5D , ( V_3 . V_10 >> 8 & 0x07 )
| ( V_3 . V_11 >> ( 8 - 3 ) & 0x38 )
| ( V_3 . V_7 >> ( 11 - 6 ) & 0x40 )
| ( V_3 . V_8 >> ( 11 - 7 ) & 0x80 ) ) ;
F_3 ( V_16 , 0x5E , V_3 . V_14 & 0xFF ) ;
F_3 ( V_16 , 0x5F , ( V_3 . V_15 & 0x1F )
| ( V_3 . V_14 >> ( 8 - 5 ) & 0xE0 ) ) ;
}
void F_5 ( T_1 V_17 )
{
F_6 ( V_18 L_1 , V_17 ) ;
F_3 ( V_16 , 0x0D , V_17 & 0xFF ) ;
F_3 ( V_16 , 0x0C , ( V_17 >> 8 ) & 0xFF ) ;
F_3 ( V_16 , 0x34 , ( V_17 >> 16 ) & 0xFF ) ;
F_2 ( V_16 , 0x48 , ( V_17 >> 24 ) & 0x1F , 0x1F ) ;
}
void F_7 ( T_1 V_17 )
{
F_6 ( V_18 L_2 , V_17 ) ;
F_2 ( V_16 , 0x62 , ( V_17 >> 2 ) & 0xFE , 0xFE ) ;
F_3 ( V_16 , 0x63 , ( V_17 >> 10 ) & 0xFF ) ;
F_3 ( V_16 , 0x64 , ( V_17 >> 18 ) & 0xFF ) ;
F_2 ( V_16 , 0xA3 , ( V_17 >> 26 ) & 0x07 , 0x07 ) ;
}
void F_8 ( T_1 V_19 )
{
F_6 ( V_18 L_3 , V_19 ) ;
V_19 = V_19 >> 3 ;
F_3 ( V_16 , 0x13 , V_19 & 0xFF ) ;
F_2 ( V_16 , 0x35 , ( V_19 >> ( 8 - 5 ) ) & 0xE0 , 0xE0 ) ;
}
void F_9 ( T_1 V_19 )
{
F_6 ( V_18 L_4 , V_19 ) ;
V_19 = V_19 >> 3 ;
F_3 ( V_16 , 0x66 , V_19 & 0xFF ) ;
F_2 ( V_16 , 0x67 , ( V_19 >> 8 ) & 0x03 , 0x03 ) ;
F_2 ( V_16 , 0x71 , ( V_19 >> ( 10 - 7 ) ) & 0x80 , 0x80 ) ;
}
void F_10 ( T_2 V_20 )
{
T_2 V_21 ;
F_6 ( V_18 L_5 , V_20 ) ;
switch ( V_20 ) {
case 8 :
V_21 = 0x00 ;
break;
case 15 :
V_21 = 0x04 ;
break;
case 16 :
V_21 = 0x14 ;
break;
case 24 :
V_21 = 0x0C ;
break;
case 30 :
V_21 = 0x08 ;
break;
default:
F_11 ( V_22 L_6
L_7 , V_20 ) ;
return;
}
F_2 ( V_23 , 0x15 , V_21 , 0x1C ) ;
}
void F_12 ( T_2 V_20 )
{
T_2 V_21 ;
F_6 ( V_18 L_8 , V_20 ) ;
switch ( V_20 ) {
case 8 :
V_21 = 0x00 ;
break;
case 16 :
V_21 = 0x40 ;
break;
case 24 :
V_21 = 0xC0 ;
break;
case 30 :
V_21 = 0x80 ;
break;
default:
F_11 ( V_22 L_9
L_7 , V_20 ) ;
return;
}
F_2 ( V_16 , 0x67 , V_21 , 0xC0 ) ;
}
