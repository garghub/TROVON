int F_1 ( union V_1 V_2 , union V_1 V_3 , int V_4 , int V_5 )
{
T_1 V_6 ;
T_1 V_7 ;
V_8 ;
V_9 ;
V_10 ;
V_11 ;
V_12 ;
V_13 ;
F_2 () ;
if ( F_3 ( V_2 ) || F_3 ( V_3 ) ) {
if ( V_5 || V_14 == V_15 || V_16 == V_15 )
F_4 ( V_17 ) ;
if ( V_4 & V_18 )
return 1 ;
if ( V_4 & ( V_19 | V_20 ) ) {
if ( V_5 && F_5 ( V_17 ) )
return 0 ;
}
return 0 ;
} else {
V_6 = V_2 . V_21 ;
V_7 = V_3 . V_21 ;
if ( V_6 < 0 )
V_6 = - V_6 ^ V_22 ;
if ( V_7 < 0 )
V_7 = - V_7 ^ V_22 ;
if ( V_6 < V_7 )
return ( V_4 & V_19 ) != 0 ;
else if ( V_6 == V_7 )
return ( V_4 & V_23 ) != 0 ;
else
return ( V_4 & V_20 ) != 0 ;
}
}
