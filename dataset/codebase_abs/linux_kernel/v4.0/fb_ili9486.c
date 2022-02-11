static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 ,
L_1 , V_8 , V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( V_2 , 0x2A , V_3 >> 8 , V_3 & 0xFF , V_5 >> 8 , V_5 & 0xFF ) ;
F_3 ( V_2 , 0x2B , V_4 >> 8 , V_4 & 0xFF , V_6 >> 8 , V_6 & 0xFF ) ;
F_3 ( V_2 , 0x2C ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
F_2 ( V_9 , V_2 , L_2 , V_8 ) ;
switch ( V_2 -> V_10 -> V_11 . V_12 ) {
case 0 :
F_3 ( V_2 , 0x36 , 0x80 | ( V_2 -> V_13 << 3 ) ) ;
break;
case 90 :
F_3 ( V_2 , 0x36 , 0x20 | ( V_2 -> V_13 << 3 ) ) ;
break;
case 180 :
F_3 ( V_2 , 0x36 , 0x40 | ( V_2 -> V_13 << 3 ) ) ;
break;
case 270 :
F_3 ( V_2 , 0x36 , 0xE0 | ( V_2 -> V_13 << 3 ) ) ;
break;
default:
break;
}
return 0 ;
}
