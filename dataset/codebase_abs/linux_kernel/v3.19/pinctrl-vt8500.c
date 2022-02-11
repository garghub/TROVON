static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_5 , L_1 ) ;
return - V_7 ;
}
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = F_4 ( V_9 ) ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = F_4 ( V_12 ) ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = F_4 ( V_15 ) ;
return F_5 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
