static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
F_2 ( V_2 , 0x01 ) ;
F_3 ( 5 ) ;
F_2 ( V_2 , 0x28 ) ;
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
F_2 ( V_2 , 0x3A , 0x55 ) ;
F_2 ( V_2 , 0xB1 , 0x00 , 0x1B ) ;
F_2 ( V_2 , 0x26 , 0x01 ) ;
F_2 ( V_2 , 0xB7 , 0x07 ) ;
F_2 ( V_2 , 0xB6 , 0x0A , 0x82 , 0x27 , 0x00 ) ;
F_2 ( V_2 , 0x11 ) ;
F_3 ( 100 ) ;
F_2 ( V_2 , 0x29 ) ;
F_3 ( 20 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_5 , int V_6 , int V_7 , int V_8 )
{
F_2 ( V_2 , 0x2A ,
( V_5 >> 8 ) & 0xFF , V_5 & 0xFF , ( V_7 >> 8 ) & 0xFF , V_7 & 0xFF ) ;
F_2 ( V_2 , 0x2B ,
( V_6 >> 8 ) & 0xFF , V_6 & 0xFF , ( V_8 >> 8 ) & 0xFF , V_8 & 0xFF ) ;
F_2 ( V_2 , 0x2C ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_9 -> V_10 . V_11 ) {
case 0 :
F_2 ( V_2 , 0x36 , ( 1 << V_12 ) | ( V_2 -> V_13 << V_14 ) ) ;
break;
case 270 :
F_2 ( V_2 , 0x36 ,
( 1 << V_15 ) | ( 1 << V_16 ) | ( V_2 -> V_13 << V_14 ) ) ;
break;
case 180 :
F_2 ( V_2 , 0x36 , ( 1 << V_17 ) | ( V_2 -> V_13 << V_14 ) ) ;
break;
case 90 :
F_2 ( V_2 , 0x36 , ( 1 << V_17 ) | ( 1 << V_12 ) |
( 1 << V_15 ) | ( V_2 -> V_13 << V_14 ) ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long * V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_2 -> gamma . V_20 ; V_19 ++ )
F_2 ( V_2 , 0xE0 + V_19 ,
F_7 ( V_19 , 0 ) , F_7 ( V_19 , 1 ) , F_7 ( V_19 , 2 ) ,
F_7 ( V_19 , 3 ) , F_7 ( V_19 , 4 ) , F_7 ( V_19 , 5 ) ,
F_7 ( V_19 , 6 ) , F_7 ( V_19 , 7 ) , F_7 ( V_19 , 8 ) ,
F_7 ( V_19 , 9 ) , F_7 ( V_19 , 10 ) , F_7 ( V_19 , 11 ) ,
F_7 ( V_19 , 12 ) , F_7 ( V_19 , 13 ) , F_7 ( V_19 , 14 ) ) ;
return 0 ;
}
