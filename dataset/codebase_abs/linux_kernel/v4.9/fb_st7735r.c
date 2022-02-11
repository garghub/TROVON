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
static int F_4 ( struct V_1 * V_2 , unsigned long * V_18 )
{
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_2 -> gamma . V_21 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < V_2 -> gamma . V_22 ; V_20 ++ )
F_5 ( V_19 , V_20 ) &= 0x3f ;
for ( V_19 = 0 ; V_19 < V_2 -> gamma . V_21 ; V_19 ++ )
F_2 ( V_2 , 0xE0 + V_19 ,
F_5 ( V_19 , 0 ) , F_5 ( V_19 , 1 ) , F_5 ( V_19 , 2 ) , F_5 ( V_19 , 3 ) ,
F_5 ( V_19 , 4 ) , F_5 ( V_19 , 5 ) , F_5 ( V_19 , 6 ) , F_5 ( V_19 , 7 ) ,
F_5 ( V_19 , 8 ) , F_5 ( V_19 , 9 ) , F_5 ( V_19 , 10 ) , F_5 ( V_19 , 11 ) ,
F_5 ( V_19 , 12 ) , F_5 ( V_19 , 13 ) , F_5 ( V_19 , 14 ) , F_5 ( V_19 , 15 ) ) ;
return 0 ;
}
