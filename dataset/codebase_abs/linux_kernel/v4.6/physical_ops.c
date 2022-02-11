static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 -> V_9 ,
V_10 |
V_11 |
V_12 ) ;
if ( F_3 ( V_8 ) ) {
F_4 ( L_1 ,
V_13 , F_5 ( V_8 ) ) ;
return - V_14 ;
}
V_2 -> V_15 = V_8 ;
return 0 ;
}
static T_1
F_6 ( struct V_16 * V_17 )
{
return F_7 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt)) ;
}
static int
F_8 ( struct V_16 * V_17 )
{
return 0 ;
}
static int
F_9 ( struct V_16 * V_17 , struct V_18 * V_19 ,
int V_20 , bool V_21 )
{
struct V_1 * V_2 = & V_17 -> V_22 ;
F_10 ( V_2 -> V_23 , V_19 , F_11 ( V_21 ) ) ;
V_19 -> V_24 = V_2 -> V_15 -> V_25 ;
V_19 -> V_26 = V_19 -> V_27 ;
return 1 ;
}
static int
F_12 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_1 * V_2 = & V_17 -> V_22 ;
F_13 ( V_2 -> V_23 , V_19 ) ;
return 1 ;
}
static void
F_14 ( struct V_16 * V_17 , struct V_28 * V_29 )
{
struct V_30 * V_31 = V_17 -> V_22 . V_23 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_29 -> V_33 ; -- V_29 -> V_33 )
F_13 ( V_31 , & V_29 -> V_34 [ V_32 ++ ] ) ;
}
static void
F_15 ( struct V_35 * V_36 )
{
}
