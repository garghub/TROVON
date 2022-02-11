static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
F_6 ( 2 , L_1 , V_6 ) ;
V_5 -> V_7 . V_8 &= V_9 | V_10 | V_11 | V_12 | V_13 ;
V_5 -> V_14 . V_8 = 0x01 ;
F_7 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
F_6 ( 2 , L_1 , V_6 ) ;
F_9 ( V_3 , TRUE , TRUE ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_15 )
{
unsigned V_16 = V_3 -> V_17 . V_18 ;
unsigned V_19 = 0 ;
T_3 V_20 [ 2 ] ;
static int V_21 = 0 ;
F_6 ( 2 , L_1 , V_6 ) ;
switch ( V_16 ) {
case V_22 :
F_9 ( V_3 , TRUE , FALSE ) ;
F_11 ( 500 ) ;
V_21 = 0 ;
switch ( V_15 ) {
default:
V_15 = 9600 ;
V_21 = - V_23 ;
case 9600 :
V_20 [ 0 ] = V_24 ;
break;
case 19200 :
V_20 [ 0 ] = V_25 ;
break;
case 34800 :
V_20 [ 0 ] = V_26 ;
break;
case 57600 :
V_20 [ 0 ] = V_27 ;
break;
case 115200 :
V_20 [ 0 ] = V_28 ;
break;
}
V_20 [ 1 ] = V_29 ;
F_12 ( V_3 , V_20 , 2 ) ;
V_3 -> V_15 = V_15 ;
V_16 = V_30 ;
V_19 = 100 ;
break;
case V_30 :
F_9 ( V_3 , FALSE , FALSE ) ;
break;
default:
F_13 ( L_2 , V_6 , V_16 ) ;
V_21 = - V_23 ;
break;
}
V_3 -> V_17 . V_18 = V_16 ;
return ( V_19 > 0 ) ? V_19 : V_21 ;
}
static int F_14 ( struct V_2 * V_3 )
{
unsigned V_16 = V_3 -> V_17 . V_18 ;
unsigned V_19 = 0 ;
int V_21 = 0 ;
F_6 ( 2 , L_1 , V_6 ) ;
switch ( V_16 ) {
case V_31 :
F_9 ( V_3 , TRUE , TRUE ) ;
V_16 = V_32 ;
V_19 = 50 ;
break;
case V_32 :
F_9 ( V_3 , FALSE , FALSE ) ;
V_16 = V_33 ;
V_19 = 50 ;
break;
case V_33 :
F_9 ( V_3 , FALSE , FALSE ) ;
break;
default:
F_13 ( L_3 , V_6 , V_16 ) ;
V_21 = - V_23 ;
break;
}
V_3 -> V_17 . V_18 = V_16 ;
return ( V_19 > 0 ) ? V_19 : V_21 ;
}
