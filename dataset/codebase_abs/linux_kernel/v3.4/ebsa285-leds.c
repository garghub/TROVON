static void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
switch ( V_1 ) {
case V_4 :
V_5 = V_6 | V_7 ;
#ifndef F_3
V_5 |= V_8 ;
#endif
V_9 |= V_10 ;
break;
case V_11 :
V_9 &= ~ V_10 ;
break;
case V_12 :
V_9 |= V_13 ;
V_5 = V_6 | V_7 | V_8 ;
break;
case V_14 :
V_9 &= ~ V_13 ;
V_5 = V_6 | V_7 | V_8 ;
break;
#ifdef F_4
case V_15 :
if ( ! ( V_9 & V_13 ) )
V_5 ^= V_7 ;
break;
#endif
#ifdef F_3
case V_16 :
if ( ! ( V_9 & V_13 ) )
V_5 |= V_8 ;
break;
case V_17 :
if ( ! ( V_9 & V_13 ) )
V_5 &= ~ V_8 ;
break;
#endif
case V_18 :
if ( ! ( V_9 & V_13 ) )
V_5 &= ~ V_6 ;
break;
case V_19 :
if ( V_9 & V_13 )
V_5 &= ~ V_7 ;
break;
case V_20 :
if ( V_9 & V_13 )
V_5 |= V_7 ;
break;
case V_21 :
if ( V_9 & V_13 )
V_5 &= ~ V_8 ;
break;
case V_22 :
if ( V_9 & V_13 )
V_5 |= V_8 ;
break;
case V_23 :
if ( V_9 & V_13 )
V_5 &= ~ V_6 ;
break;
case V_24 :
if ( V_9 & V_13 )
V_5 |= V_6 ;
break;
default:
break;
}
if ( V_9 & V_10 )
* V_25 = V_5 ;
F_5 ( & V_3 , V_2 ) ;
}
static int T_2 F_6 ( void )
{
if ( F_7 () )
V_26 = F_1 ;
V_26 ( V_4 ) ;
return 0 ;
}
