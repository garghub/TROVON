static int
F_1 ( struct V_1 * V_2 )
{
return - V_3 ;
}
static int
F_2 ( struct V_1 * V_2 , int V_4 )
{
return - V_3 ;
}
int
F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( sizeof( * V_6 ) , V_7 ) ;
V_2 -> V_8 = V_6 ;
if ( ! V_6 )
return - V_9 ;
V_6 -> type = L_1 ;
V_6 -> V_10 = F_1 ;
V_6 -> V_11 = F_2 ;
return 0 ;
}
