int F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
T_1 V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_7 = F_2 ( V_2 -> V_8 ) ;
if ( ! V_3 || ( V_3 & ( V_9 - 1 ) ) )
return 0 ;
if ( ! V_7 || ( V_7 & ( V_9 - 1 ) ) )
return 0 ;
if ( V_7 < V_3 || V_7 % V_3 )
return 0 ;
if ( ! V_5 )
return 0 ;
return 1 ;
}
int F_3 ( int V_10 )
{
int V_11 ;
#ifdef F_4
if ( ( V_10 & F_4 ) == F_4 )
return V_12 ;
#endif
switch ( V_10 & V_13 ) {
case V_14 :
V_11 = V_15 ;
break;
case V_16 :
V_11 = V_17 ;
break;
case V_18 :
case V_13 :
V_11 = V_19 ;
break;
}
#ifdef F_5
if ( V_10 & F_5 )
V_11 |= V_20 ;
#endif
return V_11 ;
}
int F_6 ( int V_11 )
{
int V_21 = V_22 ;
if ( V_11 & V_17 )
V_21 |= V_23 |
V_24 | V_25 ;
if ( V_11 & V_15 )
V_21 |= V_26 |
V_27 | V_28 |
V_29 | V_30 |
V_31 | V_32 ;
if ( V_11 & V_20 )
V_21 |= V_33 ;
return V_21 ;
}
