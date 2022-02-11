static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_2 -> V_11 = V_8 ;
if ( ! F_4 ( V_4 -> V_12 [ 0 ] , V_6 -> V_13 ,
V_6 -> V_14 ) )
return - V_15 ;
return F_5 ( V_2 , V_4 -> V_12 [ 0 ] ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_16 )
F_8 ( V_2 -> V_16 , V_6 -> V_13 ) ;
}
