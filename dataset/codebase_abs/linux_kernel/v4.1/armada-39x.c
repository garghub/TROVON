static T_1 T_2 F_1 ( void T_3 * V_1 )
{
T_4 V_2 ;
V_2 = ( ( F_2 ( V_1 + V_3 ) >> V_4 ) &
V_5 ) ;
return V_6 [ V_2 ] ;
}
static T_1 T_2 F_3 ( void T_3 * V_1 )
{
T_4 V_7 ;
V_7 = ( ( F_2 ( V_1 + V_3 ) >> V_8 ) &
V_9 ) ;
if ( V_7 >= F_4 ( V_10 ) ) {
F_5 ( L_1 ,
V_7 ) ;
return 0 ;
}
return V_10 [ V_7 ] ;
}
static void T_2 F_6 (
void T_3 * V_1 , int V_11 , int * V_12 , int * div )
{
switch ( V_11 ) {
case V_13 :
* V_12 = 1 ;
* div = 2 ;
break;
case V_14 :
* V_12 = 1 ;
* div = 4 ;
break;
case V_15 :
* V_12 = 1 ;
* div = 2 ;
break;
}
}
static T_1 T_2 F_7 ( void T_3 * V_1 )
{
if ( F_2 ( V_1 + V_16 ) & V_17 )
return 40 * 1000 * 1000 ;
else
return 25 * 1000 * 1000 ;
}
static void T_2 F_8 ( struct V_18 * V_19 )
{
F_9 ( V_19 , & V_20 ) ;
}
static void T_2 F_10 ( struct V_18 * V_19 )
{
F_11 ( V_19 , V_21 ) ;
}
