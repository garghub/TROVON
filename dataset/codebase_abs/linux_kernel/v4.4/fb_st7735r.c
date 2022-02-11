static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_2 , 0x2A , V_3 >> 8 , V_3 & 0xFF , V_5 >> 8 , V_5 & 0xFF ) ;
F_2 ( V_2 , 0x2B , V_4 >> 8 , V_4 & 0xFF , V_6 >> 8 , V_6 & 0xFF ) ;
F_2 ( V_2 , 0x2C ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_7 -> V_8 . V_9 ) {
case 0 :
F_2 ( V_2 , 0x36 , V_10 | V_11 | ( V_2 -> V_12 << 3 ) ) ;
break;
case 270 :
F_2 ( V_2 , 0x36 , V_11 | V_13 | ( V_2 -> V_12 << 3 ) ) ;
break;
case 180 :
F_2 ( V_2 , 0x36 , V_2 -> V_12 << 3 ) ;
break;
case 90 :
F_2 ( V_2 , 0x36 , V_10 | V_13 | ( V_2 -> V_12 << 3 ) ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long * V_14 )
{
int V_15 , V_16 ;
for ( V_15 = 0 ; V_15 < V_2 -> gamma . V_17 ; V_15 ++ )
for ( V_16 = 0 ; V_16 < V_2 -> gamma . V_18 ; V_16 ++ )
F_5 ( V_15 , V_16 ) &= 0x3f ;
for ( V_15 = 0 ; V_15 < V_2 -> gamma . V_17 ; V_15 ++ )
F_2 ( V_2 , 0xE0 + V_15 ,
F_5 ( V_15 , 0 ) , F_5 ( V_15 , 1 ) , F_5 ( V_15 , 2 ) , F_5 ( V_15 , 3 ) ,
F_5 ( V_15 , 4 ) , F_5 ( V_15 , 5 ) , F_5 ( V_15 , 6 ) , F_5 ( V_15 , 7 ) ,
F_5 ( V_15 , 8 ) , F_5 ( V_15 , 9 ) , F_5 ( V_15 , 10 ) , F_5 ( V_15 , 11 ) ,
F_5 ( V_15 , 12 ) , F_5 ( V_15 , 13 ) , F_5 ( V_15 , 14 ) , F_5 ( V_15 , 15 ) ) ;
return 0 ;
}
