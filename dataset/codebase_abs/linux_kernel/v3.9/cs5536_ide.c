void F_1 ( int V_1 , T_1 V_2 )
{
T_1 V_3 = 0 , V_4 = V_2 ;
switch ( V_1 ) {
case V_5 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
if ( V_2 & V_7 )
V_4 |= ( 0x03 << 4 ) ;
else
V_4 &= ~ ( 0x03 << 4 ) ;
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
V_2 &= 0x0000ff00 ;
F_2 ( F_5 ( V_13 ) , & V_3 , & V_4 ) ;
V_3 &= 0xffffff00 ;
V_3 |= ( V_2 >> 8 ) ;
F_4 ( F_5 ( V_13 ) , V_3 , V_4 ) ;
break;
case V_14 :
if ( V_2 == V_15 ) {
F_2 ( F_6 ( V_16 ) , & V_3 , & V_4 ) ;
V_4 |= V_17 ;
F_4 ( F_6 ( V_16 ) , V_3 , V_4 ) ;
} else if ( V_2 & 0x01 ) {
F_2 ( F_7 ( V_18 ) , & V_3 , & V_4 ) ;
V_4 = ( V_2 & 0xfffffff0 ) | 0x1 ;
F_4 ( F_7 ( V_18 ) , V_3 , V_4 ) ;
V_2 &= 0xfffffffc ;
V_3 = 0x60000000 | ( ( V_2 & 0x000ff000 ) >> 12 ) ;
V_4 = 0x000ffff0 | ( ( V_2 & 0x00000fff ) << 20 ) ;
F_4 ( F_3 ( V_19 ) , V_3 , V_4 ) ;
}
break;
case V_20 :
if ( V_2 == V_21 ) {
F_2 ( F_8 ( V_22 ) , & V_3 , & V_4 ) ;
V_4 |= 0x01 ;
F_4 ( F_8 ( V_22 ) , V_3 , V_4 ) ;
} else {
F_2 ( F_7 ( V_23 ) , & V_3 , & V_4 ) ;
V_4 = V_2 ;
F_4 ( F_7 ( V_23 ) , V_3 , V_4 ) ;
}
break;
case V_24 :
F_2 ( F_7 ( V_25 ) , & V_3 , & V_4 ) ;
V_4 = V_2 ;
F_4 ( F_7 ( V_25 ) , V_3 , V_4 ) ;
break;
case V_26 :
F_2 ( F_7 ( V_27 ) , & V_3 , & V_4 ) ;
V_4 = V_2 ;
F_4 ( F_7 ( V_27 ) , V_3 , V_4 ) ;
break;
case V_28 :
F_2 ( F_7 ( V_29 ) , & V_3 , & V_4 ) ;
V_4 = V_2 ;
F_4 ( F_7 ( V_29 ) , V_3 , V_4 ) ;
break;
case V_30 :
F_2 ( F_7 ( V_31 ) , & V_3 , & V_4 ) ;
V_4 = V_2 ;
F_4 ( F_7 ( V_31 ) , V_3 , V_4 ) ;
break;
default:
break;
}
}
T_1 F_9 ( int V_1 )
{
T_1 V_32 = 0 ;
T_1 V_3 , V_4 ;
switch ( V_1 ) {
case V_33 :
V_32 =
F_10 ( V_34 , V_35 ) ;
break;
case V_5 :
F_2 ( F_7 ( V_18 ) , & V_3 , & V_4 ) ;
if ( V_4 & 0xfffffff0 )
V_32 |= V_36 ;
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
if ( ( V_4 & 0x30 ) == 0x30 )
V_32 |= V_7 ;
break;
case V_8 :
V_32 |= V_37 ;
V_32 |= V_38 ;
F_2 ( F_5 ( V_10 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_11 )
V_32 |= V_9 ;
V_32 |= V_39 ;
break;
case V_40 :
F_2 ( F_7 ( V_41 ) , & V_3 , & V_4 ) ;
V_32 = V_4 & 0x000000ff ;
V_32 |= ( V_42 << 8 ) ;
break;
case V_12 :
F_2 ( F_5 ( V_13 ) , & V_3 , & V_4 ) ;
V_3 &= 0x000000f8 ;
V_32 = F_11 ( V_43 , V_3 ) ;
break;
case V_14 :
F_2 ( F_6 ( V_16 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_17 ) {
V_32 = V_44 |
V_45 ;
V_4 &= ~ V_17 ;
F_4 ( F_6 ( V_16 ) , V_3 , V_4 ) ;
} else {
F_2 ( F_7 ( V_18 ) , & V_3 , & V_4 ) ;
V_32 = V_4 & 0xfffffff0 ;
V_32 |= 0x01 ;
V_32 &= ~ 0x02 ;
}
break;
case V_46 :
V_32 = V_47 ;
break;
case V_48 :
V_32 =
F_10 ( V_49 , V_50 ) ;
break;
case V_51 :
V_32 = V_52 ;
break;
case V_53 :
V_32 = V_54 ;
break;
case V_55 :
V_32 =
F_12 ( V_56 , V_57 ) ;
break;
case V_20 :
F_2 ( F_7 ( V_23 ) , & V_3 , & V_4 ) ;
V_32 = V_4 ;
break;
case V_24 :
F_2 ( F_7 ( V_25 ) , & V_3 , & V_4 ) ;
V_32 = V_4 ;
break;
case V_26 :
F_2 ( F_7 ( V_27 ) , & V_3 , & V_4 ) ;
V_32 = V_4 ;
break;
case V_28 :
F_2 ( F_7 ( V_29 ) , & V_3 , & V_4 ) ;
V_32 = V_4 ;
break;
case V_30 :
F_2 ( F_7 ( V_31 ) , & V_3 , & V_4 ) ;
V_32 = V_4 ;
break;
default:
break;
}
return V_32 ;
}
