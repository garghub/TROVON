static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( & V_2 -> V_8 , sizeof( * V_6 ) ) ;
if ( ! V_4 )
return - V_9 ;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_8 = & V_2 -> V_8 ;
F_4 ( V_4 , V_2 , V_6 ) ;
V_7 = F_5 ( V_4 ,
(struct V_10 * ) & V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( F_8 ( V_2 ) ) ;
return 0 ;
}
