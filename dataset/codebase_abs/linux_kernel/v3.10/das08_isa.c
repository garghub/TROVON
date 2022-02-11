static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return - V_11 ;
V_2 -> V_12 = V_8 ;
V_9 = F_4 ( V_2 , V_4 -> V_13 [ 0 ] , V_6 -> V_14 ) ;
if ( V_9 )
return V_9 ;
return F_5 ( V_2 , V_2 -> V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
