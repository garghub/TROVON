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
V_5 -> V_6 . V_7 &= V_8 | V_9 | V_10 | V_11 | V_12 ;
V_5 -> V_13 . V_7 = 0x01 ;
F_6 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
F_8 ( V_3 , TRUE , TRUE ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_14 )
{
unsigned V_15 = V_3 -> V_16 . V_17 ;
unsigned V_18 = 0 ;
T_3 V_19 [ 2 ] ;
static int V_20 = 0 ;
switch ( V_15 ) {
case V_21 :
F_8 ( V_3 , TRUE , FALSE ) ;
F_10 ( 500 ) ;
V_20 = 0 ;
switch ( V_14 ) {
default:
V_14 = 9600 ;
V_20 = - V_22 ;
case 9600 :
V_19 [ 0 ] = V_23 ;
break;
case 19200 :
V_19 [ 0 ] = V_24 ;
break;
case 34800 :
V_19 [ 0 ] = V_25 ;
break;
case 57600 :
V_19 [ 0 ] = V_26 ;
break;
case 115200 :
V_19 [ 0 ] = V_27 ;
break;
}
V_19 [ 1 ] = V_28 ;
F_11 ( V_3 , V_19 , 2 ) ;
V_3 -> V_14 = V_14 ;
V_15 = V_29 ;
V_18 = 100 ;
break;
case V_29 :
F_8 ( V_3 , FALSE , FALSE ) ;
break;
default:
F_12 ( L_1 ,
V_30 , V_15 ) ;
V_20 = - V_22 ;
break;
}
V_3 -> V_16 . V_17 = V_15 ;
return ( V_18 > 0 ) ? V_18 : V_20 ;
}
static int F_13 ( struct V_2 * V_3 )
{
unsigned V_15 = V_3 -> V_16 . V_17 ;
unsigned V_18 = 0 ;
int V_20 = 0 ;
switch ( V_15 ) {
case V_31 :
F_8 ( V_3 , TRUE , TRUE ) ;
V_15 = V_32 ;
V_18 = 50 ;
break;
case V_32 :
F_8 ( V_3 , FALSE , FALSE ) ;
V_15 = V_33 ;
V_18 = 50 ;
break;
case V_33 :
F_8 ( V_3 , FALSE , FALSE ) ;
break;
default:
F_12 ( L_2 ,
V_30 , V_15 ) ;
V_20 = - V_22 ;
break;
}
V_3 -> V_16 . V_17 = V_15 ;
return ( V_18 > 0 ) ? V_18 : V_20 ;
}
