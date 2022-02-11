short F_1 ( int V_1 ) {
F_2 ( V_1 , 0x24 ) ;
return F_3 ( 0x26 ) ;
}
void F_4 ( short V_2 , short V_1 ) {
F_2 ( V_1 , 0x24 ) ;
F_2 ( V_2 , 0x26 ) ;
}
static void F_5 ( T_1 V_3 )
{
unsigned long V_4 ;
F_6 ( & V_5 , V_4 ) ;
V_6 = F_1 ( 0x09 ) ;
switch ( V_3 ) {
case V_7 :
V_6 |= V_8 ;
V_6 |= V_9 ;
#ifdef F_7
V_6 |= V_10 ;
#else
V_6 &= ~ V_10 ;
#endif
V_11 |= V_12 ;
break;
case V_13 :
V_6 &= ~ V_10 ;
V_6 |= V_8 ;
V_6 |= V_9 ;
V_11 &= ~ V_12 ;
break;
case V_14 :
V_11 |= V_15 ;
V_16 = V_6 ;
V_6 &= ~ V_10 ;
V_6 |= V_8 ;
V_6 |= V_9 ;
break;
case V_17 :
V_11 &= ~ V_15 ;
V_6 = V_16 ;
break;
#ifdef F_8
case V_18 :
if ( ! ( V_11 & V_15 ) )
V_6 ^= V_8 ;
break;
#endif
#ifdef F_7
case V_19 :
if ( ! ( V_11 & V_15 ) )
V_6 &= ~ V_10 ;
break;
case V_20 :
if ( ! ( V_11 & V_15 ) )
V_6 |= V_10 ;
break;
#endif
case V_21 :
if ( V_11 & V_15 )
V_6 &= ~ V_8 ;
break;
case V_22 :
if ( V_11 & V_15 )
V_6 |= V_8 ;
break;
case V_23 :
if ( V_11 & V_15 )
V_6 &= ~ V_9 ;
break;
case V_24 :
if ( V_11 & V_15 )
V_6 |= V_9 ;
break;
case V_25 :
if ( V_11 & V_15 )
V_6 |= V_10 ;
break;
case V_26 :
if ( V_11 & V_15 )
V_6 &= ~ V_10 ;
break;
default:
break;
}
if ( V_11 & V_12 )
F_4 ( V_6 , 0x09 ) ;
F_9 ( & V_5 , V_4 ) ;
}
static int T_2 F_10 ( void )
{
extern void (* F_11)( T_1 );
short V_27 ;
F_11 = F_5 ;
F_12 ( 0x24 , 4 , L_1 ) ;
V_27 = F_1 ( 0x09 ) ;
V_27 |= 1 << 10 ;
F_4 ( V_27 , 0x09 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
