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
V_4 = 0 ;
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
if ( ! ( V_5 & V_9 ) )
V_4 ^= 0 ;
break;
#endif
#ifdef F_4
case V_12 :
if ( ! ( V_5 & V_9 ) )
V_4 |= 0 ;
break;
case V_13 :
if ( ! ( V_5 & V_9 ) )
V_4 &= ~ 0 ;
break;
#endif
case V_14 :
break;
case V_15 :
if ( V_5 & V_9 )
V_4 &= ~ 0 ;
break;
case V_16 :
if ( V_5 & V_9 )
V_4 |= 0 ;
break;
case V_17 :
break;
case V_18 :
break;
case V_19 :
if ( V_5 & V_9 )
V_4 &= ~ 0 ;
break;
case V_20 :
if ( V_5 & V_9 )
V_4 |= 0 ;
break;
default:
break;
}
F_5 ( V_2 ) ;
}
