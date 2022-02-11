void F_1 ( enum V_1 V_2 )
{
T_1 V_3 , V_4 , V_5 ;
T_1 V_6 , V_7 ;
int V_8 = 0 ;
V_3 = F_2 ( V_9 ) &
~ ( V_10 ) ;
V_5 = F_2 ( V_11 ) & ~ ( V_12 ) ;
V_4 = F_2 ( V_13 ) & ~ ( V_14 ) ;
V_6 = F_2 ( V_15 ) & ~ ( V_14 ) ;
V_7 = F_2 ( V_16 ) & ~ ( V_14 ) ;
switch ( V_2 ) {
case V_17 :
break;
case V_18 :
V_5 |= 0x1 << V_19 ;
break;
case V_20 :
case V_21 :
V_3 |= V_10
| V_22 ;
if ( V_2 == V_20 ) {
V_5 |= 0x1 << V_19 ;
V_5 &= ~ V_23 ;
V_5 &= ~ V_24 ;
V_8 = 0 ;
} else {
V_5 |= 0x2 << V_19 ;
V_5 |= 0x3 << V_25 ;
V_5 |= V_23 ;
V_5 |= V_24 ;
V_8 = 1 ;
}
V_4 |= V_14 ;
if ( F_3 ( 1 ) != 0 )
return;
break;
case V_26 :
V_5 |= 0x2 << V_19 ;
break;
default:
F_4 ( V_27 L_1 , V_2 ) ;
return;
}
F_5 ( V_3 , V_9 ) ;
F_5 ( V_5 , V_11 ) ;
F_5 ( V_4 , V_13 ) ;
if ( F_6 () != V_28 )
F_5 ( V_4 , V_29 ) ;
if ( V_8 ) {
V_6 |= V_14 ;
V_7 |= V_14 ;
F_5 ( V_6 , V_15 ) ;
F_5 ( V_7 , V_16 ) ;
}
}
