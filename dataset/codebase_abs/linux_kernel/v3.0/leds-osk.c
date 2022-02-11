static void F_1 ( void )
{
int V_1 = 0 ;
int V_2 = 0 ;
if ( V_3 & V_4 )
V_1 = 1 ;
else if ( V_3 & V_5 )
V_2 = 1 ;
F_2 ( V_6 , V_2 ) ;
F_2 ( V_7 , V_1 ) ;
}
void F_3 ( T_1 V_8 )
{
unsigned long V_9 ;
T_2 V_10 ;
F_4 ( V_9 ) ;
if ( ! ( V_11 & V_12 ) && V_8 != V_13 )
goto V_14;
V_10 = V_3 ;
switch ( V_8 ) {
case V_13 :
V_11 |= V_12 ;
V_3 = 0 ;
V_10 = ~ 0 ;
break;
case V_15 :
case V_16 :
V_11 &= ~ V_12 ;
V_3 = 0 ;
break;
case V_17 :
V_11 |= V_18 ;
V_3 = 0 ;
V_10 = ~ 0 ;
break;
case V_19 :
V_11 &= ~ V_18 ;
V_3 = 0 ;
break;
#ifdef F_5
case V_20 :
V_3 ^= V_4 ;
F_1 () ;
break;
case V_21 :
V_3 &= ~ V_5 ;
F_1 () ;
break;
case V_22 :
V_3 |= V_5 ;
F_1 () ;
break;
#endif
default:
break;
}
V_10 ^= V_3 ;
V_14:
F_6 ( V_9 ) ;
}
