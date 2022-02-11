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
F_3 ( V_2 , 0x36 , V_13 | V_14 | ( V_2 -> V_15 << 3 ) ) ;
break;
case 270 :
F_3 ( V_2 , 0x36 , V_14 | V_16 | ( V_2 -> V_15 << 3 ) ) ;
break;
case 180 :
F_3 ( V_2 , 0x36 , V_2 -> V_15 << 3 ) ;
break;
case 90 :
F_3 ( V_2 , 0x36 , V_13 | V_16 | ( V_2 -> V_15 << 3 ) ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long * V_17 )
{
int V_18 , V_19 ;
F_2 ( V_9 , V_2 , L_2 , V_8 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> gamma . V_20 ; V_18 ++ )
for ( V_19 = 0 ; V_19 < V_2 -> gamma . V_21 ; V_19 ++ )
F_6 ( V_18 , V_19 ) &= 0x3f ;
for ( V_18 = 0 ; V_18 < V_2 -> gamma . V_20 ; V_18 ++ )
F_3 ( V_2 , 0xE0 + V_18 ,
F_6 ( V_18 , 0 ) , F_6 ( V_18 , 1 ) , F_6 ( V_18 , 2 ) , F_6 ( V_18 , 3 ) ,
F_6 ( V_18 , 4 ) , F_6 ( V_18 , 5 ) , F_6 ( V_18 , 6 ) , F_6 ( V_18 , 7 ) ,
F_6 ( V_18 , 8 ) , F_6 ( V_18 , 9 ) , F_6 ( V_18 , 10 ) , F_6 ( V_18 , 11 ) ,
F_6 ( V_18 , 12 ) , F_6 ( V_18 , 13 ) , F_6 ( V_18 , 14 ) , F_6 ( V_18 , 15 ) ) ;
return 0 ;
}
