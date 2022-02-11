static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_6 ;
F_4 ( V_5 -> V_7 , V_5 -> V_8 , & V_6 ) ;
V_6 >>= V_5 -> V_9 ;
V_6 &= V_5 -> V_10 ;
return V_6 ;
}
static int F_5 ( struct V_2 * V_4 , T_1 V_11 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_10 , V_6 ;
V_6 = V_11 << V_5 -> V_9 ;
V_10 = V_5 -> V_10 << V_5 -> V_9 ;
return F_6 ( V_5 -> V_7 , V_5 -> V_8 , V_10 , V_6 ) ;
}
static struct V_12 T_3 *
F_7 ( const struct V_13 * V_5 ,
struct V_7 * V_7 )
{
struct V_1 * V_14 ;
struct V_12 * V_12 ;
struct V_15 V_16 ;
V_14 = F_8 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
return F_9 ( - V_18 ) ;
V_16 . V_19 = V_5 -> V_19 ;
V_16 . V_20 = & V_21 ;
V_16 . V_22 = V_5 -> V_22 ;
V_16 . V_23 = V_5 -> V_23 ;
V_16 . V_24 = V_5 -> V_24 ;
V_14 -> V_8 = V_5 -> V_25 ;
V_14 -> V_9 = V_5 -> V_26 ;
V_14 -> V_10 = F_10 ( V_5 -> V_27 ) - 1 ;
V_14 -> V_7 = V_7 ;
V_14 -> V_4 . V_16 = & V_16 ;
V_12 = F_11 ( NULL , & V_14 -> V_4 ) ;
if ( F_12 ( V_12 ) )
F_13 ( V_14 ) ;
return V_12 ;
}
int T_3 F_14 ( struct V_28 * V_29 ,
const struct V_13 * V_30 , int V_31 ,
struct V_32 * V_33 )
{
int V_34 ;
struct V_12 * V_12 ;
struct V_7 * V_7 ;
V_7 = F_15 ( V_29 ) ;
if ( F_12 ( V_7 ) ) {
F_16 ( L_1 , V_29 ,
F_17 ( V_7 ) ) ;
return F_17 ( V_7 ) ;
}
for ( V_34 = 0 ; V_34 < V_31 ; V_34 ++ ) {
const struct V_13 * V_5 = & V_30 [ V_34 ] ;
V_12 = F_7 ( V_5 , V_7 ) ;
if ( F_12 ( V_12 ) ) {
F_16 ( L_2 ,
V_5 -> V_19 , F_17 ( V_12 ) ) ;
continue;
}
V_33 -> V_30 [ V_5 -> V_35 ] = V_12 ;
}
return 0 ;
}
