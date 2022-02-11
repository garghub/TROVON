static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
V_2 -> V_5 . V_6 ( V_2 ) ;
F_3 ( V_2 , 0x01 ) ;
F_4 ( 5 ) ;
F_3 ( V_2 , 0x28 ) ;
F_3 ( V_2 , 0xCF , 0x00 , 0x83 , 0x30 ) ;
F_3 ( V_2 , 0xED , 0x64 , 0x03 , 0x12 , 0x81 ) ;
F_3 ( V_2 , 0xE8 , 0x85 , 0x01 , 0x79 ) ;
F_3 ( V_2 , 0xCB , 0x39 , 0X2C , 0x00 , 0x34 , 0x02 ) ;
F_3 ( V_2 , 0xF7 , 0x20 ) ;
F_3 ( V_2 , 0xEA , 0x00 , 0x00 ) ;
F_3 ( V_2 , 0xC0 , 0x26 ) ;
F_3 ( V_2 , 0xC1 , 0x11 ) ;
F_3 ( V_2 , 0xC5 , 0x35 , 0x3E ) ;
F_3 ( V_2 , 0xC7 , 0xBE ) ;
F_3 ( V_2 , 0x3A , 0x55 ) ;
F_3 ( V_2 , 0xB1 , 0x00 , 0x1B ) ;
F_3 ( V_2 , 0x26 , 0x01 ) ;
F_3 ( V_2 , 0xB7 , 0x07 ) ;
F_3 ( V_2 , 0xB6 , 0x0A , 0x82 , 0x27 , 0x00 ) ;
F_3 ( V_2 , 0x11 ) ;
F_4 ( 100 ) ;
F_3 ( V_2 , 0x29 ) ;
F_4 ( 20 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_7 , int V_8 , int V_9 , int V_10 )
{
F_2 ( V_11 , V_2 ,
L_2 , V_4 , V_7 , V_8 , V_9 , V_10 ) ;
F_3 ( V_2 , 0x2A ,
( V_7 >> 8 ) & 0xFF , V_7 & 0xFF , ( V_9 >> 8 ) & 0xFF , V_9 & 0xFF ) ;
F_3 ( V_2 , 0x2B ,
( V_8 >> 8 ) & 0xFF , V_8 & 0xFF , ( V_10 >> 8 ) & 0xFF , V_10 & 0xFF ) ;
F_3 ( V_2 , 0x2C ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
switch ( V_2 -> V_12 -> V_13 . V_14 ) {
case 0 :
F_3 ( V_2 , 0x36 , ( 1 << V_15 ) | ( V_2 -> V_16 << V_17 ) ) ;
break;
case 270 :
F_3 ( V_2 , 0x36 ,
( 1 << V_18 ) | ( 1 << V_19 ) | ( V_2 -> V_16 << V_17 ) ) ;
break;
case 180 :
F_3 ( V_2 , 0x36 , ( 1 << V_20 ) | ( V_2 -> V_16 << V_17 ) ) ;
break;
case 90 :
F_3 ( V_2 , 0x36 , ( 1 << V_20 ) | ( 1 << V_15 ) |
( 1 << V_18 ) | ( V_2 -> V_16 << V_17 ) ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long * V_21 )
{
int V_22 ;
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> gamma . V_23 ; V_22 ++ )
F_3 ( V_2 , 0xE0 + V_22 ,
F_8 ( V_22 , 0 ) , F_8 ( V_22 , 1 ) , F_8 ( V_22 , 2 ) ,
F_8 ( V_22 , 3 ) , F_8 ( V_22 , 4 ) , F_8 ( V_22 , 5 ) ,
F_8 ( V_22 , 6 ) , F_8 ( V_22 , 7 ) , F_8 ( V_22 , 8 ) ,
F_8 ( V_22 , 9 ) , F_8 ( V_22 , 10 ) , F_8 ( V_22 , 11 ) ,
F_8 ( V_22 , 12 ) , F_8 ( V_22 , 13 ) , F_8 ( V_22 , 14 ) ) ;
return 0 ;
}
