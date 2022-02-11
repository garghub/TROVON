static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
V_4 = F_2 ( & V_2 -> V_6 , sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_4 -> V_9 = L_1 ;
V_5 = F_3 ( & V_2 -> V_6 , V_4 -> V_9 , NULL ,
V_10 , 100000000 ) ;
if ( F_4 ( V_5 ) )
return F_5 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
F_6 ( V_2 , V_4 ) ;
return 0 ;
}
int T_1 F_7 ( void )
{
return F_8 ( & V_11 ) ;
}
