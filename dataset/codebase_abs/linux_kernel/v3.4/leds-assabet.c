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
V_4 = V_5 | V_6 ;
F_3 ( V_10 , V_4 ) ;
break;
case V_11 :
V_7 |= V_12 ;
V_4 = V_5 | V_6 ;
break;
case V_13 :
V_7 &= ~ V_12 ;
V_4 = V_5 | V_6 ;
break;
#ifdef F_4
case V_14 :
if ( ! ( V_7 & V_12 ) )
V_4 ^= V_6 ;
break;
#endif
#ifdef F_5
case V_15 :
if ( ! ( V_7 & V_12 ) )
V_4 |= V_5 ;
break;
case V_16 :
if ( ! ( V_7 & V_12 ) )
V_4 &= ~ V_5 ;
break;
#endif
case V_17 :
break;
case V_18 :
if ( V_7 & V_12 )
V_4 &= ~ V_6 ;
break;
case V_19 :
if ( V_7 & V_12 )
V_4 |= V_6 ;
break;
case V_20 :
break;
case V_21 :
break;
case V_22 :
if ( V_7 & V_12 )
V_4 &= ~ V_5 ;
break;
case V_23 :
if ( V_7 & V_12 )
V_4 |= V_5 ;
break;
default:
break;
}
if ( V_7 & V_8 )
F_3 ( V_10 , V_4 ) ;
F_6 ( V_2 ) ;
}
