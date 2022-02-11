static int T_1 F_1 ( void )
{
if ( V_1 < 1 || V_1 > 500 )
V_1 = 200 ;
F_2 ( L_1 ,
V_2 . V_3 , V_1 ) ;
return F_3 ( & V_2 ) ;
}
static void T_2 F_4 ( void )
{
F_5 ( & V_2 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
F_7 ( V_5 , TRUE , TRUE ) ;
V_7 -> V_8 . V_9 &= V_10 | V_11 | V_12 | V_13 | V_14 ;
V_7 -> V_15 . V_9 = 0x01 ;
F_8 ( V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
F_7 ( V_5 , FALSE , FALSE ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 , unsigned V_16 )
{
unsigned V_17 = V_5 -> V_18 . V_19 ;
unsigned V_20 = 0 ;
T_3 V_21 ;
static int V_22 = 0 ;
switch( V_17 ) {
case V_23 :
switch ( V_16 ) {
default:
V_16 = 9600 ;
V_22 = - V_24 ;
case 9600 :
V_21 = V_25 | V_26 ;
break;
case 19200 :
V_21 = V_25 | V_27 ;
break;
case 38400 :
V_21 = V_25 | V_28 ;
break;
case 57600 :
V_21 = V_25 | V_29 ;
break;
case 115200 :
V_21 = V_30 ;
break;
}
F_7 ( V_5 , TRUE , FALSE ) ;
F_11 ( 14 ) ;
F_12 ( V_5 , & V_21 , 1 ) ;
V_5 -> V_16 = V_16 ;
V_17 = V_31 ;
V_20 = V_1 ;
break;
case V_31 :
F_7 ( V_5 , TRUE , TRUE ) ;
F_11 ( 50 ) ;
break;
default:
F_13 ( L_2 ,
V_32 , V_17 ) ;
V_22 = - V_24 ;
break;
}
V_5 -> V_18 . V_19 = V_17 ;
return ( V_20 > 0 ) ? V_20 : V_22 ;
}
static int F_14 ( struct V_4 * V_5 )
{
F_7 ( V_5 , FALSE , TRUE ) ;
F_15 ( 1 ) ;
F_7 ( V_5 , TRUE , TRUE ) ;
F_11 ( 75 ) ;
V_5 -> V_16 = 9600 ;
return 0 ;
}
