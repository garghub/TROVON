void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( V_2 ) ;
switch ( V_1 ) {
case V_3 :
V_4 = V_5 ;
V_6 = V_7 ;
break;
case V_8 :
V_6 &= ~ V_7 ;
break;
case V_9 :
V_6 |= V_10 ;
V_4 = V_5 ;
break;
case V_11 :
V_6 &= ~ V_10 ;
V_4 = V_5 ;
break;
#ifdef F_3
case V_12 :
if ( ! ( V_6 & V_10 ) )
V_4 ^= V_13 ;
break;
#endif
#ifdef F_4
case V_14 :
if ( ! ( V_6 & V_10 ) )
V_4 &= ~ V_15 ;
break;
case V_16 :
if ( ! ( V_6 & V_10 ) )
V_4 |= V_15 ;
break;
#endif
case V_17 :
if ( ! ( V_6 & V_10 ) )
V_4 &= ~ V_18 ;
break;
case V_19 :
if ( ! ( V_6 & V_10 ) )
V_4 |= V_18 ;
break;
case V_20 :
if ( ! ( V_6 & V_10 ) )
V_4 &= ~ V_21 ;
break;
case V_22 :
if ( ! ( V_6 & V_10 ) )
V_4 |= V_21 ;
break;
case V_23 :
if ( ! ( V_6 & V_10 ) )
V_4 &= ~ V_15 ;
break;
case V_24 :
if ( ! ( V_6 & V_10 ) )
V_4 |= V_15 ;
break;
default:
break;
}
if ( V_6 & V_7 ) {
V_25 = V_4 ;
V_26 = V_4 ^ V_5 ;
}
F_5 ( V_2 ) ;
}
