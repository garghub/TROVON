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
F_6 ( V_3 , TRUE , TRUE ) ;
V_5 -> V_6 . V_7 &= V_8 | V_9 | V_10 | V_11 | V_12 ;
V_5 -> V_13 . V_7 = 0x03 ;
F_7 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
F_6 ( V_3 , FALSE , FALSE ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_14 )
{
T_3 V_15 [ 3 ] ;
int V_16 = 0 ;
F_6 ( V_3 , FALSE , TRUE ) ;
switch ( V_14 ) {
default:
V_16 = - V_17 ;
case 9600 :
V_15 [ 0 ] = V_18 | ( V_19 & 0x0f ) ;
V_15 [ 1 ] = V_20 | ( ( V_19 >> 4 ) & 0x0f ) ;
break;
case 19200 :
V_15 [ 0 ] = V_18 | ( V_21 & 0x0f ) ;
V_15 [ 1 ] = V_20 | ( ( V_21 >> 4 ) & 0x0f ) ;
break;
case 38400 :
V_15 [ 0 ] = V_18 | ( V_22 & 0x0f ) ;
V_15 [ 1 ] = V_20 | ( ( V_22 >> 4 ) & 0x0f ) ;
break;
case 57600 :
V_15 [ 0 ] = V_18 | ( V_23 & 0x0f ) ;
V_15 [ 1 ] = V_20 | ( ( V_23 >> 4 ) & 0x0f ) ;
break;
case 115200 :
V_15 [ 0 ] = V_18 | ( V_24 & 0x0f ) ;
V_15 [ 1 ] = V_20 | ( ( V_24 >> 4 ) & 0x0f ) ;
break;
}
V_15 [ 2 ] = V_25 | V_26 | V_27 ;
F_10 ( V_3 , V_15 , 3 ) ;
F_11 ( 5 ) ;
F_6 ( V_3 , TRUE , TRUE ) ;
V_3 -> V_14 = V_14 ;
return V_16 ;
}
static int F_12 ( struct V_2 * V_3 )
{
unsigned V_28 = V_3 -> V_29 . V_30 ;
unsigned V_31 = 0 ;
static const T_3 V_15 [ 9 ] = {
V_32 ,
V_33 | V_34 ,
V_35 | V_36 | V_37 ,
V_33 ,
V_38 | V_39 ,
V_40 | V_41 | V_42 ,
V_43 | V_44 ,
V_45 | V_46 | V_47 | V_48 ,
V_49 | V_50 | V_51
} ;
int V_16 = 0 ;
switch ( V_28 ) {
case V_52 :
F_6 ( V_3 , TRUE , FALSE ) ;
V_28 = V_53 ;
V_31 = 50 ;
break;
case V_53 :
F_6 ( V_3 , FALSE , TRUE ) ;
F_13 ( 25 ) ;
F_10 ( V_3 , V_15 , sizeof( V_15 ) ) ;
V_28 = V_54 ;
V_31 = 15 ;
break;
case V_54 :
F_6 ( V_3 , TRUE , TRUE ) ;
V_3 -> V_14 = 9600 ;
break;
default:
F_14 ( L_1 ,
V_55 , V_28 ) ;
V_16 = - 1 ;
break;
}
V_3 -> V_29 . V_30 = V_28 ;
return ( V_31 > 0 ) ? V_31 : V_16 ;
}
