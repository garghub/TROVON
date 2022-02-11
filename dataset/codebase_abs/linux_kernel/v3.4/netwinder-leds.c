static void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
switch ( V_1 ) {
case V_4 :
V_5 |= V_6 ;
V_7 = V_8 ;
break;
case V_9 :
V_5 &= ~ V_6 ;
break;
case V_10 :
V_5 |= V_11 ;
V_7 = 0 ;
break;
case V_12 :
V_5 &= ~ V_11 ;
V_7 = 0 ;
break;
#ifdef F_3
case V_13 :
if ( ! ( V_5 & V_11 ) )
V_7 ^= V_8 ;
break;
#endif
#ifdef F_4
case V_14 :
if ( ! ( V_5 & V_11 ) )
V_7 &= ~ V_15 ;
break;
case V_16 :
if ( ! ( V_5 & V_11 ) )
V_7 |= V_15 ;
break;
#endif
case V_17 :
if ( ! ( V_5 & V_11 ) )
V_7 |= V_15 ;
break;
case V_18 :
if ( V_5 & V_11 )
V_7 |= V_8 ;
break;
case V_19 :
if ( V_5 & V_11 )
V_7 &= ~ V_8 ;
break;
case V_20 :
if ( V_5 & V_11 )
V_7 |= V_8 | V_15 ;
break;
case V_21 :
if ( V_5 & V_11 )
V_7 &= ~ ( V_8 | V_15 ) ;
break;
case V_22 :
if ( V_5 & V_11 )
V_7 |= V_15 ;
break;
case V_23 :
if ( V_5 & V_11 )
V_7 &= ~ V_15 ;
break;
default:
break;
}
F_5 ( & V_3 , V_2 ) ;
if ( V_5 & V_6 ) {
F_2 ( & V_24 , V_2 ) ;
F_6 ( V_15 | V_8 , V_7 ) ;
F_5 ( & V_24 , V_2 ) ;
}
}
static int T_2 F_7 ( void )
{
if ( F_8 () )
V_25 = F_1 ;
V_25 ( V_4 ) ;
return 0 ;
}
