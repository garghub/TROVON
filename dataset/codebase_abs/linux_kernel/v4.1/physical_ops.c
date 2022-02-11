static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return 0 ;
}
static T_1
F_2 ( struct V_7 * V_8 )
{
return F_3 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt)) ;
}
static int
F_4 ( struct V_7 * V_8 )
{
return 0 ;
}
static int
F_5 ( struct V_7 * V_8 , struct V_9 * V_10 ,
int V_11 , bool V_12 )
{
struct V_1 * V_2 = & V_8 -> V_13 ;
F_6 ( V_2 -> V_14 -> V_15 , V_10 ,
F_7 ( V_12 ) ) ;
V_10 -> V_16 = V_2 -> V_17 -> V_18 ;
V_10 -> V_19 = V_10 -> V_20 ;
V_10 -> V_21 = 1 ;
return 1 ;
}
static int
F_8 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_8 -> V_13 ;
F_9 ( & V_2 -> V_22 ) ;
F_10 ( V_2 -> V_14 -> V_15 , V_10 ) ;
F_11 ( & V_2 -> V_22 ) ;
return 1 ;
}
static void
F_12 ( struct V_7 * V_8 )
{
}
static void
F_13 ( struct V_23 * V_24 )
{
}
