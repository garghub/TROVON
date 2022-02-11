int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
V_6 = V_4 -> V_7 * V_4 -> V_8 ;
if ( ! V_6 )
return 0 ;
F_2 ( V_2 -> V_9 , L_1 ,
V_2 -> V_10 . V_11 ) ;
if ( V_4 -> V_12 )
V_2 -> V_13 = F_3 ( V_4 -> V_12 ,
V_6 , V_14 ) ;
else
V_2 -> V_13 = F_4 ( V_6 , V_14 ) ;
if ( ! V_2 -> V_13 )
return - V_15 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_9 , L_2 ,
V_2 -> V_10 . V_11 ) ;
F_6 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
return 0 ;
}
