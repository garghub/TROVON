static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_2 , V_7 ,
V_3 >> 8 , V_3 & 0xFF , V_5 >> 8 , V_5 & 0xFF ) ;
F_2 ( V_2 , V_8 ,
V_4 >> 8 , V_4 & 0xFF , V_6 >> 8 , V_6 & 0xFF ) ;
F_2 ( V_2 , V_9 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 -> V_11 . V_12 ) {
case 0 :
F_2 ( V_2 , V_13 ,
V_14 | V_15 | ( V_2 -> V_16 << 3 ) ) ;
break;
case 270 :
F_2 ( V_2 , V_13 ,
V_15 | V_17 | ( V_2 -> V_16 << 3 ) ) ;
break;
case 180 :
F_2 ( V_2 , V_13 ,
V_2 -> V_16 << 3 ) ;
break;
case 90 :
F_2 ( V_2 , V_13 ,
V_14 | V_17 | ( V_2 -> V_16 << 3 ) ) ;
break;
}
return 0 ;
}
