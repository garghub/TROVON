static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
unsigned int V_9 ;
int V_10 ;
V_9 = V_4 -> V_11 [ 1 ] ;
V_8 = F_3 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_12 ;
V_10 = F_4 ( V_2 , V_4 -> V_11 [ 0 ] , V_6 -> V_13 ) ;
if ( V_10 )
return V_10 ;
return F_5 ( V_2 , V_9 , 0 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
