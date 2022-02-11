int F_1 ( union V_1 V_2 , union V_1 V_3 , int V_4 , int V_5 )
{
int V_6 ;
int V_7 ;
V_8 ;
V_9 ;
V_10 ;
V_11 ;
V_12 ;
V_13 ;
F_2 () ;
if ( F_3 ( V_14 ) || F_3 ( V_15 ) ) {
if ( V_5 ||
V_14 == V_16 || V_15 == V_16 )
F_4 ( V_17 ) ;
return ( V_4 & V_18 ) != 0 ;
} else {
V_6 = V_2 . V_19 ;
V_7 = V_3 . V_19 ;
if ( V_6 < 0 )
V_6 = - V_6 ^ V_20 ;
if ( V_7 < 0 )
V_7 = - V_7 ^ V_20 ;
if ( V_6 < V_7 )
return ( V_4 & V_21 ) != 0 ;
else if ( V_6 == V_7 )
return ( V_4 & V_22 ) != 0 ;
else
return ( V_4 & V_23 ) != 0 ;
}
}
