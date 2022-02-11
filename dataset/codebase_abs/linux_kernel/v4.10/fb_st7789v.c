static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
F_3 ( 120 ) ;
F_2 ( V_2 , V_4 , V_5 ) ;
F_2 ( V_2 , V_6 , 0x08 , 0x08 , 0x00 , 0x22 , 0x22 ) ;
F_2 ( V_2 , V_7 , 0x35 ) ;
F_2 ( V_2 , V_8 , 0x01 , 0xFF ) ;
F_2 ( V_2 , V_9 , 0x0B ) ;
F_2 ( V_2 , V_10 , 0x20 ) ;
F_2 ( V_2 , V_11 , 0x20 ) ;
F_2 ( V_2 , V_12 , 0x20 ) ;
F_2 ( V_2 , V_13 , 0xA4 , 0xA1 ) ;
F_2 ( V_2 , V_14 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_15 = 0 ;
if ( V_2 -> V_16 )
V_15 |= V_17 ;
switch ( V_2 -> V_18 -> V_19 . V_20 ) {
case 0 :
break;
case 90 :
V_15 |= ( V_21 | V_22 ) ;
break;
case 180 :
V_15 |= ( V_23 | V_22 ) ;
break;
case 270 :
V_15 |= ( V_21 | V_23 ) ;
break;
default:
return - V_24 ;
}
F_2 ( V_2 , V_25 , V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long * V_26 )
{
int V_27 ;
int V_28 ;
int V_29 ;
const T_1 V_30 [] = {
0xFF ,
0x3F ,
0x3F ,
0x1F ,
0x1F ,
0x3F ,
0x7F ,
0x77 ,
0x7F ,
0x3F ,
0x1F ,
0x1F ,
0x3F ,
0x3F ,
} ;
for ( V_27 = 0 ; V_27 < V_2 -> gamma . V_31 ; V_27 ++ ) {
V_29 = V_27 * V_2 -> gamma . V_32 ;
for ( V_28 = 0 ; V_28 < V_2 -> gamma . V_32 ; V_28 ++ )
V_26 [ V_29 + V_28 ] &= V_30 [ V_28 ] ;
F_2 (
V_2 , V_33 + V_27 ,
V_26 [ V_29 + 0 ] , V_26 [ V_29 + 1 ] , V_26 [ V_29 + 2 ] ,
V_26 [ V_29 + 3 ] , V_26 [ V_29 + 4 ] , V_26 [ V_29 + 5 ] ,
V_26 [ V_29 + 6 ] , V_26 [ V_29 + 7 ] , V_26 [ V_29 + 8 ] ,
V_26 [ V_29 + 9 ] , V_26 [ V_29 + 10 ] , V_26 [ V_29 + 11 ] ,
V_26 [ V_29 + 12 ] , V_26 [ V_29 + 13 ] ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_34 )
{
if ( V_34 )
F_2 ( V_2 , V_35 ) ;
else
F_2 ( V_2 , V_14 ) ;
return 0 ;
}
