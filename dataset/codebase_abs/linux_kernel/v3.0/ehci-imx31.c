int F_1 ( int V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( F_3 ( V_4 + V_5 ) ) ;
switch ( V_1 ) {
case 0 :
V_3 &= ~ ( V_6 | V_7 ) ;
V_3 |= ( V_2 & V_8 ) << V_9 ;
if ( ! ( V_2 & V_10 ) )
V_3 |= V_7 ;
break;
case 1 :
V_3 &= ~ ( V_11 | V_12 | V_13 ) ;
V_3 |= ( V_2 & V_8 ) << V_14 ;
if ( ! ( V_2 & V_10 ) )
V_3 |= V_12 ;
if ( ! ( V_2 & V_15 ) )
V_3 |= V_13 ;
break;
case 2 :
V_3 &= ~ ( V_16 | V_17 | V_18 ) ;
V_3 |= ( V_2 & V_8 ) << V_19 ;
if ( ! ( V_2 & V_10 ) )
V_3 |= V_17 ;
if ( ! ( V_2 & V_15 ) )
V_3 |= V_18 ;
break;
default:
return - V_20 ;
}
F_4 ( V_3 , F_3 ( V_4 + V_5 ) ) ;
return 0 ;
}
