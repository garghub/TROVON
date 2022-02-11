static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_8 ;
V_7 = F_3 ( V_2 , V_4 -> V_9 [ 0 ] , 0x4 ) ;
if ( V_7 )
return V_7 ;
return F_4 ( V_2 , V_2 -> V_10 , V_4 -> V_9 [ 1 ] , 0 ) ;
}
