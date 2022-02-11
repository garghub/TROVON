static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
V_2 -> V_5 . V_6 ( V_2 ) ;
if ( V_2 -> V_7 . V_8 != - 1 )
F_3 ( V_2 -> V_7 . V_8 , 0 ) ;
F_4 ( V_2 , V_9 ) ;
F_5 ( 500 ) ;
F_4 ( V_2 , V_10 ) ;
F_5 ( 5 ) ;
F_4 ( V_2 , V_11 , 0x05 ) ;
F_4 ( V_2 , V_12 , 0x02 ) ;
#ifdef F_6
F_4 ( V_2 , V_13 , 0x01 ) ;
#endif
F_4 ( V_2 , V_14 ) ;
F_4 ( V_2 , V_15 , 0xff , 0x06 ) ;
F_4 ( V_2 , V_16 , 0x08 , 0x02 ) ;
F_4 ( V_2 , V_17 , 0x07 ) ;
F_4 ( V_2 , V_18 , 0x0A , 0x02 ) ;
F_4 ( V_2 , V_19 , 0x02 ) ;
F_4 ( V_2 , V_20 , 0x50 , 0x63 ) ;
F_4 ( V_2 , V_21 , 0 ) ;
F_4 ( V_2 , V_22 , 0 , 0 , 0 , V_23 ) ;
F_4 ( V_2 , V_24 , 0 , 0 , 0 , V_25 ) ;
F_4 ( V_2 , V_26 ) ;
F_4 ( V_2 , V_27 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , int V_28 , int V_29 ,
int V_30 , int V_31 )
{
F_2 ( V_32 , V_2 ,
L_2 , V_4 , V_28 , V_29 , V_30 , V_31 ) ;
switch ( V_2 -> V_33 -> V_34 . V_35 ) {
case 0 :
F_4 ( V_2 , V_22 , V_28 >> 8 , V_28 & 0xff , V_30 >> 8 ,
V_30 & 0xff ) ;
F_4 ( V_2 , V_24 ,
( V_29 + V_36 ) >> 8 , ( V_29 + V_36 ) & 0xff ,
( V_31 + V_36 ) >> 8 , ( V_31 + V_36 ) & 0xff ) ;
break;
case 90 :
F_4 ( V_2 , V_22 ,
( V_28 + V_36 ) >> 8 , ( V_28 + V_36 ) & 0xff ,
( V_30 + V_36 ) >> 8 , ( V_30 + V_36 ) & 0xff ) ;
F_4 ( V_2 , V_24 , V_29 >> 8 , V_29 & 0xff , V_31 >> 8 ,
V_31 & 0xff ) ;
break;
case 180 :
case 270 :
F_4 ( V_2 , V_22 , V_28 >> 8 , V_28 & 0xff , V_30 >> 8 ,
V_30 & 0xff ) ;
F_4 ( V_2 , V_24 , V_29 >> 8 , V_29 & 0xff , V_31 >> 8 ,
V_31 & 0xff ) ;
break;
default:
V_2 -> V_33 -> V_34 . V_35 = 0 ;
}
F_4 ( V_2 , V_27 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_37 = 0 ;
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
switch ( V_2 -> V_33 -> V_34 . V_35 ) {
case 0 :
V_37 = 0x08 ;
break;
case 180 :
V_37 = 0xC8 ;
break;
case 270 :
V_37 = 0xA8 ;
break;
case 90 :
V_37 = 0x68 ;
break;
}
if ( V_2 -> V_38 )
V_37 |= ( 1 << 2 ) ;
F_4 ( V_2 , V_39 , V_37 ) ;
F_4 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long * V_40 )
{
unsigned long V_41 [] = {
0x3F , 0x3F , 0x3F , 0x3F , 0x3F ,
0x1f , 0x3f , 0x0f , 0x0f , 0x7f , 0x1f ,
0x3F , 0x3F , 0x3F , 0x3F , 0x3F } ;
int V_42 , V_43 ;
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
F_10 ( V_42 , V_43 ) &= V_41 [ V_42 * V_2 -> gamma . V_46 + V_43 ] ;
F_4 ( V_2 , V_47 ,
F_10 ( 0 , 0 ) ,
F_10 ( 0 , 1 ) ,
F_10 ( 0 , 2 ) ,
F_10 ( 0 , 3 ) ,
F_10 ( 0 , 4 ) ,
F_10 ( 0 , 5 ) ,
F_10 ( 0 , 6 ) ,
( F_10 ( 0 , 7 ) << 4 ) | F_10 ( 0 , 8 ) ,
F_10 ( 0 , 9 ) ,
F_10 ( 0 , 10 ) ,
F_10 ( 0 , 11 ) ,
F_10 ( 0 , 12 ) ,
F_10 ( 0 , 13 ) ,
F_10 ( 0 , 14 ) ,
F_10 ( 0 , 15 )
) ;
F_4 ( V_2 , V_27 ) ;
return 0 ;
}
