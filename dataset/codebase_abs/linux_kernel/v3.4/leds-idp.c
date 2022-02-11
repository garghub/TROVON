void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( V_2 ) ;
switch ( V_1 ) {
case V_3 :
V_4 = V_5 | V_6 ;
V_7 = V_8 ;
break;
case V_9 :
V_7 &= ~ V_8 ;
break;
case V_10 :
V_7 |= V_11 ;
V_4 = V_5 | V_6 ;
break;
case V_12 :
V_7 &= ~ V_11 ;
V_4 = V_5 | V_6 ;
break;
#ifdef F_3
case V_13 :
if ( ! ( V_7 & V_11 ) )
V_4 ^= V_5 ;
break;
#endif
#ifdef F_4
case V_14 :
if ( ! ( V_7 & V_11 ) )
V_4 &= ~ V_6 ;
break;
case V_15 :
if ( ! ( V_7 & V_11 ) )
V_4 |= V_6 ;
break;
#endif
case V_16 :
break;
case V_17 :
if ( V_7 & V_11 )
V_4 |= V_5 ;
break;
case V_18 :
if ( V_7 & V_11 )
V_4 &= ~ V_5 ;
break;
case V_19 :
break;
case V_20 :
break;
case V_21 :
if ( V_7 & V_11 )
V_4 |= V_6 ;
break;
case V_22 :
if ( V_7 & V_11 )
V_4 &= ~ V_6 ;
break;
default:
break;
}
if ( V_7 & V_8 )
V_23 = ( ( V_23 | V_24 ) & ~ V_4 ) ;
else
V_23 |= V_24 ;
F_5 ( V_2 ) ;
}
