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
struct V_5 * V_6 = ( void * ) V_2 ;
struct V_7 * V_8 ;
V_8 = F_4 ( sizeof( * V_8 ) , V_9 ) ;
V_6 -> V_10 = V_8 ;
if ( ! V_8 )
return - V_11 ;
V_8 -> type = L_1 ;
V_8 -> V_12 = F_1 ;
V_8 -> V_13 = F_2 ;
return 0 ;
}
