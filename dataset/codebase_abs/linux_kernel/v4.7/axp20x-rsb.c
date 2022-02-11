static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( & V_2 -> V_6 , sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_4 -> V_6 = & V_2 -> V_6 ;
V_4 -> V_9 = V_2 -> V_9 ;
F_3 ( & V_2 -> V_6 , V_4 ) ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_10 = F_5 ( V_2 , V_4 -> V_11 ) ;
if ( F_6 ( V_4 -> V_10 ) ) {
V_5 = F_7 ( V_4 -> V_10 ) ;
F_8 ( & V_2 -> V_6 , L_1 , V_5 ) ;
return V_5 ;
}
return F_9 ( V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_11 ( V_2 ) ;
return F_12 ( V_4 ) ;
}
