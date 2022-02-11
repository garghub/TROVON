void F_1 ( T_1 V_1 )
{
switch ( V_1 )
{
case V_2 :
V_3 = V_4 ;
V_5 = V_6 ;
break;
case V_7 :
V_5 &= ~ V_6 ;
break;
case V_8 :
V_5 |= V_9 ;
V_3 = V_4 ;
break;
case V_10 :
V_5 &= ~ V_9 ;
V_3 = V_4 ;
break;
#ifdef F_2
case V_11 :
if ( ! ( V_5 & V_9 ) )
V_3 ^= V_4 ;
break;
#endif
#ifdef F_3
case V_12 :
break;
case V_13 :
break;
#endif
case V_14 :
break;
case V_15 :
if ( V_5 & V_9 )
V_3 |= V_4 ;
break;
case V_16 :
if ( V_5 & V_9 )
V_3 &= ~ V_4 ;
break;
case V_17 :
break;
case V_18 :
break;
case V_19 :
break;
case V_20 :
break;
default:
break;
}
if ( V_5 & V_6 )
F_4 ( V_21 ) ;
else
F_5 ( V_21 ) ;
}
