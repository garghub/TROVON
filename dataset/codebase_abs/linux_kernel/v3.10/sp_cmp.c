int F_1 ( T_1 V_1 , T_1 V_2 , int V_3 , int V_4 )
{
V_5 ;
V_6 ;
V_7 ;
V_8 ;
V_9 ;
V_10 ;
V_11 ;
if ( F_2 ( V_1 ) || F_2 ( V_2 ) ) {
if ( V_4 || V_12 == V_13 || V_14 == V_13 )
F_3 ( V_15 ) ;
if ( V_3 & V_16 )
return 1 ;
if ( V_3 & ( V_17 | V_18 ) ) {
if ( V_4 && F_4 ( V_15 ) )
return F_5 ( 0 , L_1 , V_1 ) ;
}
return 0 ;
} else {
int V_19 = V_1 . V_20 ;
int V_21 = V_2 . V_20 ;
if ( V_19 < 0 )
V_19 = - V_19 ^ V_22 ;
if ( V_21 < 0 )
V_21 = - V_21 ^ V_22 ;
if ( V_19 < V_21 )
return ( V_3 & V_17 ) != 0 ;
else if ( V_19 == V_21 )
return ( V_3 & V_23 ) != 0 ;
else
return ( V_3 & V_18 ) != 0 ;
}
}
