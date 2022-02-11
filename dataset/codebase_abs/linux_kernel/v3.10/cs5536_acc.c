void F_1 ( int V_1 , T_1 V_2 )
{
T_1 V_3 = 0 , V_4 = V_2 ;
switch ( V_1 ) {
case V_5 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
if ( V_2 & V_7 )
V_4 |= ( 0x03 << 8 ) ;
else
V_4 &= ~ ( 0x03 << 8 ) ;
F_4 ( F_3 ( V_6 ) , V_3 , V_4 ) ;
break;
case V_8 :
if ( V_2 & V_9 ) {
F_2 ( F_5 ( V_10 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_11 ) {
V_4 = ( V_4 & 0x0000ffff ) | V_11 ;
F_4 ( F_5 ( V_10 ) , V_3 , V_4 ) ;
}
}
break;
case V_12 :
if ( V_2 == V_13 ) {
F_2 ( F_6 ( V_14 ) , & V_3 , & V_4 ) ;
V_4 |= V_15 ;
F_4 ( F_6 ( V_14 ) , V_3 , V_4 ) ;
} else if ( V_2 & 0x01 ) {
V_2 &= 0xfffffffc ;
V_3 = 0xA0000000 | ( ( V_2 & 0x000ff000 ) >> 12 ) ;
V_4 = 0x000fff80 | ( ( V_2 & 0x00000fff ) << 20 ) ;
F_4 ( F_3 ( V_16 ) , V_3 , V_4 ) ;
}
break;
case V_17 :
F_2 ( F_7 ( V_18 ) , & V_3 , & V_4 ) ;
V_4 &= ~ ( 0xf << V_19 ) ;
if ( V_2 )
V_4 |= ( V_20 << V_19 ) ;
F_4 ( F_7 ( V_18 ) , V_3 , V_4 ) ;
break;
default:
break;
}
}
T_1 F_8 ( int V_1 )
{
T_1 V_3 , V_4 ;
T_1 V_21 = 0 ;
switch ( V_1 ) {
case V_22 :
V_21 =
F_9 ( V_23 , V_24 ) ;
break;
case V_5 :
F_2 ( F_3 ( V_16 ) , & V_3 , & V_4 ) ;
if ( ( ( V_4 & 0xfff00000 ) || ( V_3 & 0x000000ff ) )
&& ( ( V_3 & 0xf0000000 ) == 0xa0000000 ) )
V_21 |= V_25 ;
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
if ( ( V_4 & 0x300 ) == 0x300 )
V_21 |= V_7 ;
break;
case V_8 :
V_21 |= V_26 ;
V_21 |= V_27 ;
F_2 ( F_5 ( V_10 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_11 )
V_21 |= V_9 ;
V_21 |= V_28 ;
break;
case V_29 :
F_2 ( F_10 ( V_30 ) , & V_3 , & V_4 ) ;
V_21 = V_4 & 0x000000ff ;
V_21 |= ( V_31 << 8 ) ;
break;
case V_32 :
V_21 =
F_11 ( V_33 ,
V_34 ) ;
break;
case V_12 :
F_2 ( F_6 ( V_14 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_15 ) {
V_21 = V_35 |
V_36 ;
V_4 &= ~ V_15 ;
F_4 ( F_6 ( V_14 ) , V_3 , V_4 ) ;
} else {
F_2 ( F_3 ( V_16 ) , & V_3 , & V_4 ) ;
V_21 = ( V_3 & 0x000000ff ) << 12 ;
V_21 |= ( V_4 & 0xfff00000 ) >> 20 ;
V_21 |= 0x01 ;
V_21 &= ~ 0x02 ;
}
break;
case V_37 :
V_21 = V_38 ;
break;
case V_39 :
V_21 =
F_9 ( V_40 , V_41 ) ;
break;
case V_42 :
V_21 = V_43 ;
break;
case V_44 :
V_21 = V_45 ;
break;
case V_46 :
V_21 =
F_12 ( V_47 , V_20 ) ;
break;
default:
break;
}
return V_21 ;
}
