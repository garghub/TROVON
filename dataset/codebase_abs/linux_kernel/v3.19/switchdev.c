int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_8 )
return - V_9 ;
return V_6 -> V_8 ( V_2 , V_4 ) ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_10 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_11 )
return - V_9 ;
F_3 ( ! V_6 -> V_8 ) ;
return V_6 -> V_11 ( V_2 , V_10 ) ;
}
