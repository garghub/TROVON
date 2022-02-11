static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 , V_5 ;
if ( F_2 ( V_3 < V_6 ( 3, 0 ) || V_3 > V_6 ( 3 , 31 ) , L_1 , V_3 ) )
return - V_7 ;
V_4 = F_3 ( V_2 -> V_8 -> V_9 + V_10 ) ,
V_5 = 0x80000000 >> ( V_3 & 0x1f ) ;
return ( V_4 & V_5 ) ? 3300 : 1800 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 , T_2 V_11 )
{
T_1 V_4 , V_5 ;
if ( F_2 ( V_3 < V_6 ( 3, 0 ) || V_3 > V_6 ( 3 , 31 ) , L_1 , V_3 ) )
return - V_7 ;
if ( V_11 != 1800 && V_11 != 3300 )
return - V_7 ;
V_4 = F_3 ( V_2 -> V_8 -> V_9 + V_10 ) ;
V_5 = 0x80000000 >> ( V_3 & 0x1f ) ;
if ( V_11 == 3300 )
V_4 |= V_5 ;
else
V_4 &= ~ V_5 ;
F_5 ( ~ V_4 , V_2 -> V_8 -> V_9 ) ;
F_5 ( V_4 , V_2 -> V_8 -> V_9 + V_10 ) ;
return 0 ;
}
