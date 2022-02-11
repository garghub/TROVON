static int T_1 F_1 ( void )
{
if ( V_1 < 1 || V_1 > 500 )
V_1 = 200 ;
F_2 ( 1 , L_1 ,
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
F_2 ( 2 , L_2 , V_8 ) ;
F_7 ( V_5 , TRUE , TRUE ) ;
V_7 -> V_9 . V_10 &= V_11 | V_12 | V_13 | V_14 | V_15 ;
V_7 -> V_16 . V_10 = 0x01 ;
F_8 ( V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
F_2 ( 2 , L_2 , V_8 ) ;
F_7 ( V_5 , FALSE , FALSE ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 , unsigned V_17 )
{
unsigned V_18 = V_5 -> V_19 . V_20 ;
unsigned V_21 = 0 ;
T_3 V_22 ;
static int V_23 = 0 ;
F_2 ( 2 , L_2 , V_8 ) ;
switch( V_18 ) {
case V_24 :
switch ( V_17 ) {
default:
V_17 = 9600 ;
V_23 = - V_25 ;
case 9600 :
V_22 = V_26 | V_27 ;
break;
case 19200 :
V_22 = V_26 | V_28 ;
break;
case 38400 :
V_22 = V_26 | V_29 ;
break;
case 57600 :
V_22 = V_26 | V_30 ;
break;
case 115200 :
V_22 = V_31 ;
break;
}
F_7 ( V_5 , TRUE , FALSE ) ;
F_11 ( 14 ) ;
F_12 ( V_5 , & V_22 , 1 ) ;
V_5 -> V_17 = V_17 ;
V_18 = V_32 ;
V_21 = V_1 ;
break;
case V_32 :
F_7 ( V_5 , TRUE , TRUE ) ;
F_11 ( 50 ) ;
break;
default:
F_13 ( L_3 , V_8 , V_18 ) ;
V_23 = - V_25 ;
break;
}
V_5 -> V_19 . V_20 = V_18 ;
return ( V_21 > 0 ) ? V_21 : V_23 ;
}
static int F_14 ( struct V_4 * V_5 )
{
F_2 ( 2 , L_2 , V_8 ) ;
F_7 ( V_5 , FALSE , TRUE ) ;
F_15 ( 1 ) ;
F_7 ( V_5 , TRUE , TRUE ) ;
F_11 ( 75 ) ;
V_5 -> V_17 = 9600 ;
return 0 ;
}
