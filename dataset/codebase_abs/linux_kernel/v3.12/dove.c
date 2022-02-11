static T_1 T_2 F_1 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_3 ) &
V_4 ;
return V_5 [ V_2 ] ;
}
static T_1 T_2 F_3 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_6 ) &
V_7 ;
return V_8 [ V_2 ] ;
}
static void T_2 F_4 (
void T_3 * V_1 , int V_9 , int * V_10 , int * div )
{
switch ( V_9 ) {
case V_11 :
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_12 ) &
V_13 ;
* V_10 = V_14 [ V_2 ] [ 0 ] ;
* div = V_14 [ V_2 ] [ 1 ] ;
break;
}
case V_15 :
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_16 ) &
V_17 ;
* V_10 = V_18 [ V_2 ] [ 0 ] ;
* div = V_18 [ V_2 ] [ 1 ] ;
break;
}
}
}
static void T_2 F_5 ( struct V_19 * V_20 )
{
F_6 ( V_20 , & V_21 ) ;
}
static void T_2 F_7 ( struct V_19 * V_20 )
{
F_8 ( V_20 , V_22 ) ;
}
