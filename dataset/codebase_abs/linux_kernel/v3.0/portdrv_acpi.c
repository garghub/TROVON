int F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
T_2 V_7 ;
if ( V_8 )
return 0 ;
V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return - V_9 ;
V_5 = F_3 ( V_6 ) ;
if ( ! V_5 )
return - V_10 ;
V_7 = V_5 -> V_11 ;
* V_3 = V_12 ;
if ( V_7 & V_13 )
* V_3 |= V_14 ;
if ( V_7 & V_15 )
* V_3 |= V_16 ;
if ( V_7 & V_17 )
* V_3 |= V_18 ;
return 0 ;
}
