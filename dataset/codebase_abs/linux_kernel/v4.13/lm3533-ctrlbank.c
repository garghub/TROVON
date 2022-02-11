static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_3 + V_2 -> V_4 ;
}
int F_2 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_1 , V_8 , V_2 -> V_4 ) ;
V_5 = 1 << V_2 -> V_4 ;
V_6 = F_4 ( V_2 -> V_9 , V_10 ,
V_5 , V_5 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_2 , V_2 -> V_4 ) ;
return V_6 ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_1 , V_8 , V_2 -> V_4 ) ;
V_5 = 1 << V_2 -> V_4 ;
V_6 = F_4 ( V_2 -> V_9 , V_10 , 0 , V_5 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_3 , V_2 -> V_4 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 , T_2 V_11 )
{
T_1 V_12 ;
T_1 V_13 ;
int V_6 ;
if ( V_11 < V_14 || V_11 > V_15 )
return - V_16 ;
V_13 = ( V_11 - V_14 ) / V_17 ;
V_12 = F_1 ( V_2 , V_18 ) ;
V_6 = F_8 ( V_2 -> V_9 , V_12 , V_13 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_4 ) ;
return V_6 ;
}
