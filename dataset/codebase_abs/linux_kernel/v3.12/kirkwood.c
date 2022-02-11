static T_1 T_2 F_1 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_3 ) &
V_4 ;
return ( V_2 ) ? 166666667 : 200000000 ;
}
static T_1 T_2 F_3 ( void T_3 * V_1 )
{
T_1 V_2 = F_4 ( F_2 ( V_1 ) ) ;
return V_5 [ V_2 ] ;
}
static void T_2 F_5 (
void T_3 * V_1 , int V_6 , int * V_7 , int * div )
{
switch ( V_6 ) {
case V_8 :
{
T_1 V_2 = F_6 ( F_2 ( V_1 ) ) ;
* V_7 = V_9 [ V_2 ] [ 0 ] ;
* div = V_9 [ V_2 ] [ 1 ] ;
break;
}
case V_10 :
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_11 ) &
V_12 ;
* V_7 = V_13 [ V_2 ] [ 0 ] ;
* div = V_13 [ V_2 ] [ 1 ] ;
break;
}
}
}
static T_1 T_2 F_7 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_14 ) & V_15 ;
return V_16 [ V_2 ] ;
}
static void T_2 F_8 (
void T_3 * V_1 , int V_6 , int * V_7 , int * div )
{
switch ( V_6 ) {
case V_8 :
{
* V_7 = 1 ;
* div = 2 ;
break;
}
case V_10 :
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_14 ) &
V_15 ;
* V_7 = V_17 [ V_2 ] [ 0 ] ;
* div = V_17 [ V_2 ] [ 1 ] ;
break;
}
}
}
static void T_2 F_9 ( struct V_18 * V_19 )
{
F_10 ( V_19 , & V_20 ) ;
}
static void T_2 F_11 ( struct V_18 * V_19 )
{
F_10 ( V_19 , & V_21 ) ;
}
static void T_2 F_12 ( struct V_18 * V_19 )
{
F_13 ( V_19 , V_22 ) ;
}
