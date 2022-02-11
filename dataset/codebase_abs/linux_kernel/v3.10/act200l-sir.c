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
F_7 ( V_3 , TRUE , TRUE ) ;
V_5 -> V_7 . V_8 &= V_9 | V_10 | V_11 | V_12 | V_13 ;
V_5 -> V_14 . V_8 = 0x03 ;
F_8 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
F_6 ( 2 , L_1 , V_6 ) ;
F_7 ( V_3 , FALSE , FALSE ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_15 )
{
T_3 V_16 [ 3 ] ;
int V_17 = 0 ;
F_6 ( 2 , L_1 , V_6 ) ;
F_7 ( V_3 , FALSE , TRUE ) ;
switch ( V_15 ) {
default:
V_17 = - V_18 ;
case 9600 :
V_16 [ 0 ] = V_19 | ( V_20 & 0x0f ) ;
V_16 [ 1 ] = V_21 | ( ( V_20 >> 4 ) & 0x0f ) ;
break;
case 19200 :
V_16 [ 0 ] = V_19 | ( V_22 & 0x0f ) ;
V_16 [ 1 ] = V_21 | ( ( V_22 >> 4 ) & 0x0f ) ;
break;
case 38400 :
V_16 [ 0 ] = V_19 | ( V_23 & 0x0f ) ;
V_16 [ 1 ] = V_21 | ( ( V_23 >> 4 ) & 0x0f ) ;
break;
case 57600 :
V_16 [ 0 ] = V_19 | ( V_24 & 0x0f ) ;
V_16 [ 1 ] = V_21 | ( ( V_24 >> 4 ) & 0x0f ) ;
break;
case 115200 :
V_16 [ 0 ] = V_19 | ( V_25 & 0x0f ) ;
V_16 [ 1 ] = V_21 | ( ( V_25 >> 4 ) & 0x0f ) ;
break;
}
V_16 [ 2 ] = V_26 | V_27 | V_28 ;
F_11 ( V_3 , V_16 , 3 ) ;
F_12 ( 5 ) ;
F_7 ( V_3 , TRUE , TRUE ) ;
V_3 -> V_15 = V_15 ;
return V_17 ;
}
static int F_13 ( struct V_2 * V_3 )
{
unsigned V_29 = V_3 -> V_30 . V_31 ;
unsigned V_32 = 0 ;
static const T_3 V_16 [ 9 ] = {
V_33 ,
V_34 | V_35 ,
V_36 | V_37 | V_38 ,
V_34 ,
V_39 | V_40 ,
V_41 | V_42 | V_43 ,
V_44 | V_45 ,
V_46 | V_47 | V_48 | V_49 ,
V_50 | V_51 | V_52
} ;
int V_17 = 0 ;
F_6 ( 2 , L_1 , V_6 ) ;
switch ( V_29 ) {
case V_53 :
F_7 ( V_3 , TRUE , FALSE ) ;
V_29 = V_54 ;
V_32 = 50 ;
break;
case V_54 :
F_7 ( V_3 , FALSE , TRUE ) ;
F_14 ( 25 ) ;
F_11 ( V_3 , V_16 , sizeof( V_16 ) ) ;
V_29 = V_55 ;
V_32 = 15 ;
break;
case V_55 :
F_7 ( V_3 , TRUE , TRUE ) ;
V_3 -> V_15 = 9600 ;
break;
default:
F_15 ( L_2 , V_6 , V_29 ) ;
V_17 = - 1 ;
break;
}
V_3 -> V_30 . V_31 = V_29 ;
return ( V_32 > 0 ) ? V_32 : V_17 ;
}
