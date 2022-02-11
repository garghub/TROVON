static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_2 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_11 ;
V_10 = F_3 ( V_2 , V_4 -> V_12 [ 0 ] , V_6 -> V_13 ) ;
if ( V_10 )
return V_10 ;
return F_4 ( V_2 , V_2 -> V_14 ) ;
}
