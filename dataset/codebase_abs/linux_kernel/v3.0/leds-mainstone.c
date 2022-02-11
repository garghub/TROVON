void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( V_2 ) ;
switch ( V_1 ) {
case V_3 :
V_4 = 0 ;
V_5 = V_6 ;
break;
case V_7 :
V_5 &= ~ V_6 ;
break;
case V_8 :
V_5 |= V_9 ;
V_4 = 0 ;
break;
case V_10 :
V_5 &= ~ V_9 ;
V_4 = 0 ;
break;
#ifdef F_3
case V_11 :
V_4 ^= V_12 ;
break;
#endif
#ifdef F_4
case V_13 :
V_4 &= ~ V_14 ;
break;
case V_15 :
V_4 |= V_14 ;
break;
#endif
case V_16 :
break;
case V_17 :
V_4 |= V_18 ;
break;
case V_19 :
V_4 &= ~ V_18 ;
break;
case V_20 :
V_4 |= V_21 ;
break;
case V_22 :
V_4 &= ~ V_21 ;
break;
case V_23 :
V_4 |= V_24 ;
break;
case V_25 :
V_4 &= ~ V_24 ;
break;
default:
break;
}
if ( V_5 & V_6 )
V_26 = ( V_26 | 0xff ) & ~ V_4 ;
else
V_26 |= 0xff ;
F_5 ( V_2 ) ;
}
