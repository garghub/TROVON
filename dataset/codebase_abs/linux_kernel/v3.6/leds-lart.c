void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( V_2 ) ;
switch( V_1 ) {
case V_3 :
V_4 |= V_5 ;
V_6 = V_7 ;
V_8 = V_9 ;
break;
case V_10 :
V_8 &= ~ V_9 ;
break;
case V_11 :
V_8 |= V_12 ;
V_6 = V_7 ;
break;
case V_13 :
V_8 &= ~ V_12 ;
V_6 = V_7 ;
break;
#ifdef F_3
case V_14 :
if ( ! ( V_8 & V_12 ) )
V_6 ^= V_5 ;
break;
#endif
#ifdef F_4
case V_15 :
if ( ! ( V_8 & V_12 ) )
V_6 &= ~ V_5 ;
break;
case V_16 :
if ( ! ( V_8 & V_12 ) )
V_6 |= V_5 ;
break;
#endif
case V_17 :
if ( V_8 & V_12 )
V_6 &= ~ V_5 ;
break;
case V_18 :
if ( V_8 & V_12 )
V_6 |= V_5 ;
break;
default:
break;
}
if ( V_8 & V_9 ) {
V_19 = V_6 ;
V_20 = V_6 ^ V_7 ;
}
F_5 ( V_2 ) ;
}
