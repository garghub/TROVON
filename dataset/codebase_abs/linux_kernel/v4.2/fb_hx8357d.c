static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
V_2 -> V_5 . V_6 ( V_2 ) ;
F_3 ( V_2 , V_7 ) ;
F_4 ( 5000 , 7000 ) ;
F_3 ( V_2 , V_8 , 0xFF , 0x83 , 0x57 ) ;
F_5 ( 150 ) ;
F_3 ( V_2 , V_9 , 0x00 , 0x00 , 0x06 , 0x06 ) ;
F_3 ( V_2 , V_10 , 0x25 ) ;
F_3 ( V_2 , V_11 , 0x68 ) ;
F_3 ( V_2 , V_12 , 0x05 ) ;
F_3 ( V_2 , V_13 ,
0x00 ,
0x15 ,
0x1C ,
0x1C ,
0x83 ,
0xAA ) ;
F_3 ( V_2 , V_14 ,
0x50 ,
0x50 ,
0x01 ,
0x3C ,
0x1E ,
0x08 ) ;
F_3 ( V_2 , V_15 ,
0x02 ,
0x40 ,
0x00 ,
0x2A ,
0x2A ,
0x0D ,
0x78 ) ;
F_3 ( V_2 , V_16 ,
0x02 ,
0x0A ,
0x11 ,
0x1d ,
0x23 ,
0x35 ,
0x41 ,
0x4b ,
0x4b ,
0x42 ,
0x3A ,
0x27 ,
0x1B ,
0x08 ,
0x09 ,
0x03 ,
0x02 ,
0x0A ,
0x11 ,
0x1d ,
0x23 ,
0x35 ,
0x41 ,
0x4b ,
0x4b ,
0x42 ,
0x3A ,
0x27 ,
0x1B ,
0x08 ,
0x09 ,
0x03 ,
0x00 ,
0x01 ) ;
F_3 ( V_2 , V_17 , 0x55 ) ;
F_3 ( V_2 , V_18 , 0xC0 ) ;
F_3 ( V_2 , V_19 , 0x00 ) ;
F_3 ( V_2 , V_20 , 0x00 , 0x02 ) ;
F_3 ( V_2 , V_21 ) ;
F_5 ( 150 ) ;
F_3 ( V_2 , V_22 ) ;
F_4 ( 5000 , 7000 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , int V_23 , int V_24 , int V_25 , int V_26 )
{
F_2 ( V_27 , V_2 ,
L_2 , V_4 , V_23 , V_24 , V_25 , V_26 ) ;
F_3 ( V_2 , V_28 ,
V_23 >> 8 , V_23 & 0xff ,
V_25 >> 8 , V_25 & 0xff ) ;
F_3 ( V_2 , V_29 ,
V_24 >> 8 , V_24 & 0xff ,
V_26 >> 8 , V_26 & 0xff ) ;
F_3 ( V_2 , V_30 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_31 ;
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
switch ( V_2 -> V_32 -> V_33 . V_34 ) {
case 270 :
V_31 = V_35 | V_36 ;
break;
case 180 :
V_31 = 0 ;
break;
case 90 :
V_31 = V_35 | V_37 ;
break;
default:
V_31 = V_36 | V_37 ;
break;
}
V_31 |= ( V_2 -> V_38 ? V_39 : V_40 ) ;
F_3 ( V_2 , V_18 , V_31 ) ;
return 0 ;
}
