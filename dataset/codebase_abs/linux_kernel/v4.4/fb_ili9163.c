static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 != - 1 )
F_2 ( V_2 -> V_5 . V_6 , 0 ) ;
F_3 ( V_2 , V_7 ) ;
F_4 ( 500 ) ;
F_3 ( V_2 , V_8 ) ;
F_4 ( 5 ) ;
F_3 ( V_2 , V_9 , 0x05 ) ;
F_3 ( V_2 , V_10 , 0x02 ) ;
#ifdef F_5
F_3 ( V_2 , V_11 , 0x01 ) ;
#endif
F_3 ( V_2 , V_12 ) ;
F_3 ( V_2 , V_13 , 0xff , 0x06 ) ;
F_3 ( V_2 , V_14 , 0x08 , 0x02 ) ;
F_3 ( V_2 , V_15 , 0x07 ) ;
F_3 ( V_2 , V_16 , 0x0A , 0x02 ) ;
F_3 ( V_2 , V_17 , 0x02 ) ;
F_3 ( V_2 , V_18 , 0x50 , 0x63 ) ;
F_3 ( V_2 , V_19 , 0 ) ;
F_3 ( V_2 , V_20 , 0 , 0 , 0 , V_21 ) ;
F_3 ( V_2 , V_22 , 0 , 0 , 0 , V_23 ) ;
F_3 ( V_2 , V_24 ) ;
F_3 ( V_2 , V_25 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , int V_26 , int V_27 ,
int V_28 , int V_29 )
{
switch ( V_2 -> V_30 -> V_31 . V_32 ) {
case 0 :
F_3 ( V_2 , V_20 , V_26 >> 8 , V_26 & 0xff , V_28 >> 8 ,
V_28 & 0xff ) ;
F_3 ( V_2 , V_22 ,
( V_27 + V_33 ) >> 8 , ( V_27 + V_33 ) & 0xff ,
( V_29 + V_33 ) >> 8 , ( V_29 + V_33 ) & 0xff ) ;
break;
case 90 :
F_3 ( V_2 , V_20 ,
( V_26 + V_33 ) >> 8 , ( V_26 + V_33 ) & 0xff ,
( V_28 + V_33 ) >> 8 , ( V_28 + V_33 ) & 0xff ) ;
F_3 ( V_2 , V_22 , V_27 >> 8 , V_27 & 0xff , V_29 >> 8 ,
V_29 & 0xff ) ;
break;
case 180 :
case 270 :
F_3 ( V_2 , V_20 , V_26 >> 8 , V_26 & 0xff , V_28 >> 8 ,
V_28 & 0xff ) ;
F_3 ( V_2 , V_22 , V_27 >> 8 , V_27 & 0xff , V_29 >> 8 ,
V_29 & 0xff ) ;
break;
default:
V_2 -> V_30 -> V_31 . V_32 = 0 ;
}
F_3 ( V_2 , V_25 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_34 = 0 ;
switch ( V_2 -> V_30 -> V_31 . V_32 ) {
case 0 :
V_34 = 0x08 ;
break;
case 180 :
V_34 = 0xC8 ;
break;
case 270 :
V_34 = 0xA8 ;
break;
case 90 :
V_34 = 0x68 ;
break;
}
if ( V_2 -> V_35 )
V_34 |= ( 1 << 2 ) ;
F_3 ( V_2 , V_36 , V_34 ) ;
F_3 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long * V_37 )
{
unsigned long V_38 [] = {
0x3F , 0x3F , 0x3F , 0x3F , 0x3F ,
0x1f , 0x3f , 0x0f , 0x0f , 0x7f , 0x1f ,
0x3F , 0x3F , 0x3F , 0x3F , 0x3F } ;
int V_39 , V_40 ;
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ )
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ )
F_9 ( V_39 , V_40 ) &= V_38 [ V_39 * V_2 -> gamma . V_43 + V_40 ] ;
F_3 ( V_2 , V_44 ,
F_9 ( 0 , 0 ) ,
F_9 ( 0 , 1 ) ,
F_9 ( 0 , 2 ) ,
F_9 ( 0 , 3 ) ,
F_9 ( 0 , 4 ) ,
F_9 ( 0 , 5 ) ,
F_9 ( 0 , 6 ) ,
( F_9 ( 0 , 7 ) << 4 ) | F_9 ( 0 , 8 ) ,
F_9 ( 0 , 9 ) ,
F_9 ( 0 , 10 ) ,
F_9 ( 0 , 11 ) ,
F_9 ( 0 , 12 ) ,
F_9 ( 0 , 13 ) ,
F_9 ( 0 , 14 ) ,
F_9 ( 0 , 15 )
) ;
F_3 ( V_2 , V_25 ) ;
return 0 ;
}
