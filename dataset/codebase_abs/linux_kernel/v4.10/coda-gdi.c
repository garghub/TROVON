void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const T_1 * V_5 ;
T_2 V_6 ;
int V_7 ;
switch ( V_2 -> V_8 ) {
case V_9 :
default:
V_5 = V_10 ;
V_6 = 0 ;
break;
case V_11 :
V_5 = V_12 ;
V_6 = V_13 |
V_14 |
( 16 - 1 ) << 12 | ( 8 - 1 ) << 4 ;
break;
}
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
F_2 ( V_4 , V_5 [ V_7 ] ,
V_15 + 4 * V_7 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_2 ( V_4 , F_3 ( V_16 , 0 , V_16 , 0 ) ,
V_17 + 4 * V_7 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
F_2 ( V_4 , F_3 ( V_16 , 0 , V_16 , 0 ) ,
V_18 + 4 * V_7 ) ;
F_2 ( V_4 , V_6 , V_19 ) ;
if ( V_6 ) {
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ )
F_2 ( V_4 , V_20 [ V_7 ] ,
V_21 + 4 * V_7 ) ;
}
}
