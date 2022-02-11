int F_1 ( int V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( F_3 ( V_4 + V_5 ) ) ;
switch ( V_1 ) {
case 0 :
V_3 &= ~ ( V_6 | V_7 | V_8 |
V_9 ) ;
V_3 |= ( V_2 & V_10 ) << V_11 ;
if ( ! ( V_2 & V_12 ) )
V_3 |= V_7 ;
if ( V_2 & V_13 )
V_3 |= V_8 ;
if ( ! ( V_2 & V_14 ) )
V_3 |= V_9 ;
break;
case 1 :
V_3 &= ~ ( V_15 | V_16 | V_17 |
V_18 | V_19 | V_20 |
V_21 | V_22 ) ;
V_3 |= ( V_2 & V_10 ) << V_23 ;
if ( ! ( V_2 & V_12 ) )
V_3 |= V_16 ;
if ( V_2 & V_13 )
V_3 |= V_17 ;
if ( ! ( V_2 & V_14 ) )
V_3 |= V_18 ;
if ( ! ( V_2 & V_24 ) )
V_3 |= V_19 ;
if ( V_2 & V_25 )
V_3 |= V_20 ;
if ( V_2 & V_26 )
V_3 |= V_21 ;
if ( V_2 & V_27 )
V_3 |= V_22 ;
break;
default:
return - V_28 ;
}
F_4 ( V_3 , F_3 ( V_4 + V_5 ) ) ;
return 0 ;
}
