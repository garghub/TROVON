static T_1 T_2 F_1 ( void T_3 * V_1 )
{
return 250000000 ;
}
static T_1 T_2 F_2 ( void T_3 * V_1 )
{
T_1 V_2 ;
T_4 V_3 = 0 ;
V_3 = ( ( F_3 ( V_1 + V_4 ) >> V_5 ) &
V_6 ) ;
V_3 |= ( ( ( F_3 ( V_1 + V_7 ) >> V_8 ) &
V_9 ) << V_10 ) ;
if ( V_3 >= F_4 ( V_11 ) ) {
F_5 ( L_1 , V_3 ) ;
V_2 = 0 ;
} else
V_2 = V_11 [ V_3 ] ;
return V_2 ;
}
static void T_2 F_6 (
void T_3 * V_1 , int V_12 , int * V_13 , int * div )
{
T_1 V_14 = ( ( F_3 ( V_1 + V_4 ) >> V_15 ) &
V_16 ) ;
V_14 |= ( ( ( F_3 ( V_1 + V_7 ) >> V_17 ) &
V_18 ) << V_19 ) ;
switch ( V_12 ) {
case V_20 :
* V_13 = V_21 [ V_14 ] [ 0 ] ;
* div = V_21 [ V_14 ] [ 1 ] ;
break;
case V_22 :
* V_13 = V_23 [ V_14 ] [ 0 ] ;
* div = V_23 [ V_14 ] [ 1 ] ;
break;
case V_24 :
* V_13 = V_25 [ V_14 ] [ 0 ] ;
* div = V_25 [ V_14 ] [ 1 ] ;
break;
}
}
static void T_2 F_7 ( struct V_26 * V_27 )
{
struct V_26 * V_28 =
F_8 ( NULL , NULL , L_2 ) ;
F_9 ( V_27 , & V_29 ) ;
if ( V_28 )
F_10 ( V_28 , V_30 ) ;
}
