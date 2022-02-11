static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_2 , 0x2a , V_3 >> 8 , V_3 & 0xff , V_5 >> 8 , V_5 & 0xff ) ;
F_2 ( V_2 , 0x2b , V_4 >> 8 , V_4 & 0xff , V_6 >> 8 , V_6 & 0xff ) ;
F_2 ( V_2 , 0x2c ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_7 -> V_8 . V_9 ) {
case 270 :
F_2 ( V_2 , 0x36 , V_10 | V_11 | V_12 | ( V_2 -> V_13 << 3 ) ) ;
break;
case 180 :
F_2 ( V_2 , 0x36 , V_12 | ( V_2 -> V_13 << 3 ) ) ;
break;
case 90 :
F_2 ( V_2 , 0x36 , V_10 | ( V_2 -> V_13 << 3 ) ) ;
break;
default:
F_2 ( V_2 , 0x36 , V_11 | ( V_2 -> V_13 << 3 ) ) ;
break;
}
return 0 ;
}
