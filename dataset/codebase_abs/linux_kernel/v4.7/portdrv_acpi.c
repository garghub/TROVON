void F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
T_2 V_7 ;
if ( V_8 )
return;
V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
V_5 = F_3 ( V_6 ) ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_9 ;
* V_3 = V_10 | V_11 ;
if ( V_7 & V_12 )
* V_3 |= V_13 ;
if ( V_7 & V_14 )
* V_3 |= V_15 ;
if ( V_7 & V_16 )
* V_3 |= V_17 ;
}
