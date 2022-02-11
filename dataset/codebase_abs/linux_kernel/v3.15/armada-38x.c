static T_1 T_2 F_1 ( void T_3 * V_1 )
{
T_4 V_2 ;
V_2 = ( ( F_2 ( V_1 ) >> V_3 ) &
V_4 ) ;
return V_5 [ V_2 ] ;
}
static T_1 T_2 F_3 ( void T_3 * V_1 )
{
T_4 V_6 ;
V_6 = ( ( F_2 ( V_1 ) >> V_7 ) &
V_8 ) ;
if ( V_6 >= F_4 ( V_9 ) ) {
F_5 ( L_1 ,
V_6 ) ;
return 0 ;
}
return V_9 [ V_6 ] ;
}
static void T_2 F_6 (
void T_3 * V_1 , int V_10 , int * V_11 , int * div )
{
T_1 V_12 = ( ( F_2 ( V_1 ) >> V_7 ) &
V_8 ) ;
switch ( V_10 ) {
case V_13 :
* V_11 = V_14 [ V_12 ] [ 0 ] ;
* div = V_14 [ V_12 ] [ 1 ] ;
break;
case V_15 :
* V_11 = V_16 [ V_12 ] [ 0 ] ;
* div = V_16 [ V_12 ] [ 1 ] ;
break;
}
}
static void T_2 F_7 ( struct V_17 * V_18 )
{
F_8 ( V_18 , & V_19 ) ;
}
static void T_2 F_9 ( struct V_17 * V_18 )
{
F_10 ( V_18 , V_20 ) ;
}
