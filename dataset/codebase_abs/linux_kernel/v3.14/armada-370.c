static T_1 T_2 F_1 ( void T_3 * V_1 )
{
T_4 V_2 = 0 ;
V_2 = ( ( F_2 ( V_1 ) >> V_3 ) &
V_4 ) ;
return V_5 [ V_2 ] ;
}
static T_1 T_2 F_3 ( void T_3 * V_1 )
{
T_1 V_6 ;
T_4 V_7 = 0 ;
V_7 = ( ( F_2 ( V_1 ) >> V_8 ) &
V_9 ) ;
if ( V_7 >= F_4 ( V_10 ) ) {
F_5 ( L_1 , V_7 ) ;
V_6 = 0 ;
} else
V_6 = V_10 [ V_7 ] ;
return V_6 ;
}
static void T_2 F_6 (
void T_3 * V_1 , int V_11 , int * V_12 , int * div )
{
T_1 V_13 = ( ( F_2 ( V_1 ) >> V_14 ) &
V_15 ) ;
switch ( V_11 ) {
case V_16 :
* V_12 = V_17 [ V_13 ] [ 0 ] ;
* div = V_17 [ V_13 ] [ 1 ] ;
break;
case V_18 :
* V_12 = V_19 [ V_13 ] [ 0 ] ;
* div = V_19 [ V_13 ] [ 1 ] ;
break;
case V_20 :
* V_12 = V_21 [ V_13 ] [ 0 ] ;
* div = V_21 [ V_13 ] [ 1 ] ;
break;
}
}
static void T_2 F_7 ( struct V_22 * V_23 )
{
struct V_22 * V_24 =
F_8 ( NULL , NULL , L_2 ) ;
F_9 ( V_23 , & V_25 ) ;
if ( V_24 )
F_10 ( V_24 , V_26 ) ;
}
