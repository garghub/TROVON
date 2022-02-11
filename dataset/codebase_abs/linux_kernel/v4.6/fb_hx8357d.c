static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
F_2 ( V_2 , V_5 ) ;
F_3 ( 5000 , 7000 ) ;
F_2 ( V_2 , V_6 , 0xFF , 0x83 , 0x57 ) ;
F_4 ( 150 ) ;
F_2 ( V_2 , V_7 , 0x00 , 0x00 , 0x06 , 0x06 ) ;
F_2 ( V_2 , V_8 , 0x25 ) ;
F_2 ( V_2 , V_9 , 0x68 ) ;
F_2 ( V_2 , V_10 , 0x05 ) ;
F_2 ( V_2 , V_11 ,
0x00 ,
0x15 ,
0x1C ,
0x1C ,
0x83 ,
0xAA ) ;
F_2 ( V_2 , V_12 ,
0x50 ,
0x50 ,
0x01 ,
0x3C ,
0x1E ,
0x08 ) ;
F_2 ( V_2 , V_13 ,
0x02 ,
0x40 ,
0x00 ,
0x2A ,
0x2A ,
0x0D ,
0x78 ) ;
F_2 ( V_2 , V_14 ,
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
F_2 ( V_2 , V_15 , 0x55 ) ;
F_2 ( V_2 , V_16 , 0xC0 ) ;
F_2 ( V_2 , V_17 , 0x00 ) ;
F_2 ( V_2 , V_18 , 0x00 , 0x02 ) ;
F_2 ( V_2 , V_19 ) ;
F_4 ( 150 ) ;
F_2 ( V_2 , V_20 ) ;
F_3 ( 5000 , 7000 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_21 , int V_22 , int V_23 , int V_24 )
{
F_2 ( V_2 , V_25 ,
V_21 >> 8 , V_21 & 0xff ,
V_23 >> 8 , V_23 & 0xff ) ;
F_2 ( V_2 , V_26 ,
V_22 >> 8 , V_22 & 0xff ,
V_24 >> 8 , V_24 & 0xff ) ;
F_2 ( V_2 , V_27 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_28 ;
switch ( V_2 -> V_29 -> V_30 . V_31 ) {
case 270 :
V_28 = V_32 | V_33 ;
break;
case 180 :
V_28 = 0 ;
break;
case 90 :
V_28 = V_32 | V_34 ;
break;
default:
V_28 = V_33 | V_34 ;
break;
}
V_28 |= ( V_2 -> V_35 ? V_36 : V_37 ) ;
F_2 ( V_2 , V_16 , V_28 ) ;
return 0 ;
}
