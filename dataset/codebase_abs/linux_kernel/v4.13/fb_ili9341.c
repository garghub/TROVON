static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
F_2 ( V_2 , V_5 ) ;
F_3 ( 5 ) ;
F_2 ( V_2 , V_6 ) ;
F_2 ( V_2 , 0xCF , 0x00 , 0x83 , 0x30 ) ;
F_2 ( V_2 , 0xED , 0x64 , 0x03 , 0x12 , 0x81 ) ;
F_2 ( V_2 , 0xE8 , 0x85 , 0x01 , 0x79 ) ;
F_2 ( V_2 , 0xCB , 0x39 , 0X2C , 0x00 , 0x34 , 0x02 ) ;
F_2 ( V_2 , 0xF7 , 0x20 ) ;
F_2 ( V_2 , 0xEA , 0x00 , 0x00 ) ;
F_2 ( V_2 , 0xC0 , 0x26 ) ;
F_2 ( V_2 , 0xC1 , 0x11 ) ;
F_2 ( V_2 , 0xC5 , 0x35 , 0x3E ) ;
F_2 ( V_2 , 0xC7 , 0xBE ) ;
F_2 ( V_2 , V_7 , 0x55 ) ;
F_2 ( V_2 , 0xB1 , 0x00 , 0x1B ) ;
F_2 ( V_2 , V_8 , 0x01 ) ;
F_2 ( V_2 , 0xB7 , 0x07 ) ;
F_2 ( V_2 , 0xB6 , 0x0A , 0x82 , 0x27 , 0x00 ) ;
F_2 ( V_2 , V_9 ) ;
F_3 ( 100 ) ;
F_2 ( V_2 , V_10 ) ;
F_3 ( 20 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_11 , int V_12 , int V_13 , int V_14 )
{
F_2 ( V_2 , V_15 ,
( V_11 >> 8 ) & 0xFF , V_11 & 0xFF , ( V_13 >> 8 ) & 0xFF , V_13 & 0xFF ) ;
F_2 ( V_2 , V_16 ,
( V_12 >> 8 ) & 0xFF , V_12 & 0xFF , ( V_14 >> 8 ) & 0xFF , V_14 & 0xFF ) ;
F_2 ( V_2 , V_17 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_18 -> V_19 . V_20 ) {
case 0 :
F_2 ( V_2 , V_21 ,
V_22 | ( V_2 -> V_23 << V_24 ) ) ;
break;
case 270 :
F_2 ( V_2 , V_21 ,
V_25 | V_26 | ( V_2 -> V_23 << V_24 ) ) ;
break;
case 180 :
F_2 ( V_2 , V_21 ,
V_27 | ( V_2 -> V_23 << V_24 ) ) ;
break;
case 90 :
F_2 ( V_2 , V_21 ,
V_27 | V_22 | V_25 | ( V_2 -> V_23 << V_24 ) ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> gamma . V_30 ; V_29 ++ )
F_2 ( V_2 , 0xE0 + V_29 ,
F_7 ( V_29 , 0 ) , F_7 ( V_29 , 1 ) , F_7 ( V_29 , 2 ) ,
F_7 ( V_29 , 3 ) , F_7 ( V_29 , 4 ) , F_7 ( V_29 , 5 ) ,
F_7 ( V_29 , 6 ) , F_7 ( V_29 , 7 ) , F_7 ( V_29 , 8 ) ,
F_7 ( V_29 , 9 ) , F_7 ( V_29 , 10 ) , F_7 ( V_29 , 11 ) ,
F_7 ( V_29 , 12 ) , F_7 ( V_29 , 13 ) , F_7 ( V_29 , 14 ) ) ;
return 0 ;
}
