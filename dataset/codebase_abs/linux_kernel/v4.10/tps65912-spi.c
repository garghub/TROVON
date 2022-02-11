static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
F_3 ( V_2 , V_4 ) ;
V_4 -> V_5 = & V_2 -> V_5 ;
V_4 -> V_8 = V_2 -> V_8 ;
V_4 -> V_9 = F_4 ( V_2 , & V_10 ) ;
if ( F_5 ( V_4 -> V_9 ) ) {
F_6 ( V_4 -> V_5 , L_1 ) ;
return F_7 ( V_4 -> V_9 ) ;
}
return F_8 ( V_4 ) ;
}
static int F_9 ( struct V_1 * V_11 )
{
struct V_3 * V_4 = F_10 ( V_11 ) ;
return F_11 ( V_4 ) ;
}
