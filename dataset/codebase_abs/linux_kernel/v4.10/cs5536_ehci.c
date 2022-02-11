void F_1 ( int V_1 , T_1 V_2 )
{
T_1 V_3 = 0 , V_4 = V_2 ;
switch ( V_1 ) {
case V_5 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
if ( V_2 & V_7 )
V_3 |= V_7 ;
else
V_3 &= ~ V_7 ;
if ( V_2 & V_8 )
V_3 |= V_8 ;
else
V_3 &= ~ V_8 ;
F_4 ( F_3 ( V_6 ) , V_3 , V_4 ) ;
break;
case V_9 :
if ( V_2 & V_10 ) {
F_2 ( F_5 ( V_11 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_12 ) {
V_4 = ( V_4 & 0x0000ffff ) | V_12 ;
F_4 ( F_5 ( V_11 ) , V_3 , V_4 ) ;
}
}
break;
case V_13 :
if ( V_2 == V_14 ) {
F_2 ( F_6 ( V_15 ) , & V_3 , & V_4 ) ;
V_4 |= V_16 ;
F_4 ( F_6 ( V_15 ) , V_3 , V_4 ) ;
} else if ( ( V_2 & 0x01 ) == 0x00 ) {
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
V_4 = V_2 ;
F_4 ( F_3 ( V_6 ) , V_3 , V_4 ) ;
V_2 &= 0xfffffff0 ;
V_3 = 0x40000000 | ( ( V_2 & 0xff000000 ) >> 24 ) ;
V_4 = 0x000fffff | ( ( V_2 & 0x00fff000 ) << 8 ) ;
F_4 ( F_7 ( V_17 ) , V_3 , V_4 ) ;
}
break;
case V_18 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
V_3 &= 0x003f0000 ;
V_3 |= ( V_2 & 0x3f ) << 16 ;
F_4 ( F_3 ( V_6 ) , V_3 , V_4 ) ;
break;
case V_19 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
V_3 &= ~ 0x00003f00 ;
V_3 |= V_2 & 0x00003f00 ;
F_4 ( F_3 ( V_6 ) , V_3 , V_4 ) ;
break;
default:
break;
}
}
T_1 F_8 ( int V_1 )
{
T_1 V_20 = 0 ;
T_1 V_3 , V_4 ;
switch ( V_1 ) {
case V_21 :
V_20 =
F_9 ( V_22 , V_23 ) ;
break;
case V_5 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
if ( V_3 & V_7 )
V_20 |= V_7 ;
if ( V_3 & V_8 )
V_20 |= V_8 ;
break;
case V_9 :
V_20 |= V_24 ;
V_20 |= V_25 ;
F_2 ( F_5 ( V_11 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_12 )
V_20 |= V_10 ;
V_20 |= V_26 ;
break;
case V_27 :
F_2 ( F_3 ( V_28 ) , & V_3 , & V_4 ) ;
V_20 = V_4 & 0x000000ff ;
V_20 |= ( V_29 << 8 ) ;
break;
case V_30 :
V_20 =
F_10 ( V_31 ,
V_32 ) ;
break;
case V_13 :
F_2 ( F_6 ( V_15 ) , & V_3 , & V_4 ) ;
if ( V_4 & V_16 ) {
V_20 = V_33 |
V_34 ;
V_4 &= ~ V_16 ;
F_4 ( F_6 ( V_15 ) , V_3 , V_4 ) ;
} else {
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
V_20 = V_4 & 0xfffff000 ;
}
break;
case V_35 :
V_20 = V_36 ;
break;
case V_37 :
V_20 =
F_9 ( V_38 , V_39 ) ;
break;
case V_40 :
V_20 = V_41 ;
break;
case V_42 :
V_20 = V_43 ;
break;
case V_44 :
V_20 =
F_11 ( V_45 , V_46 ) ;
break;
case V_18 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
V_20 = ( V_3 & 0x003f0000 ) >> 16 ;
break;
case V_47 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
V_20 = ( V_3 & 0x3f000000 ) >> 24 ;
break;
case V_19 :
F_2 ( F_3 ( V_6 ) , & V_3 , & V_4 ) ;
V_20 = V_3 & 0x00003f00 ;
break;
default:
break;
}
return V_20 ;
}
