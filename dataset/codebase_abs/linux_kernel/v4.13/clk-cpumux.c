static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_6 = F_4 ( V_4 ) ;
unsigned int V_7 ;
F_5 ( V_5 -> V_8 , V_5 -> V_9 , & V_7 ) ;
V_7 >>= V_5 -> V_10 ;
V_7 &= V_5 -> V_11 ;
if ( V_7 >= V_6 )
return - V_12 ;
return V_7 ;
}
static int F_6 ( struct V_2 * V_4 , T_1 V_13 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_11 , V_7 ;
V_7 = V_13 << V_5 -> V_10 ;
V_11 = V_5 -> V_11 << V_5 -> V_10 ;
return F_7 ( V_5 -> V_8 , V_5 -> V_9 , V_11 , V_7 ) ;
}
static struct V_14 T_3 *
F_8 ( const struct V_15 * V_5 ,
struct V_8 * V_8 )
{
struct V_1 * V_16 ;
struct V_14 * V_14 ;
struct V_17 V_18 ;
V_16 = F_9 ( sizeof( * V_16 ) , V_19 ) ;
if ( ! V_16 )
return F_10 ( - V_20 ) ;
V_18 . V_21 = V_5 -> V_21 ;
V_18 . V_22 = & V_23 ;
V_18 . V_24 = V_5 -> V_24 ;
V_18 . V_6 = V_5 -> V_6 ;
V_18 . V_25 = V_5 -> V_25 ;
V_16 -> V_9 = V_5 -> V_26 ;
V_16 -> V_10 = V_5 -> V_27 ;
V_16 -> V_11 = F_11 ( V_5 -> V_28 ) - 1 ;
V_16 -> V_8 = V_8 ;
V_16 -> V_4 . V_18 = & V_18 ;
V_14 = F_12 ( NULL , & V_16 -> V_4 ) ;
if ( F_13 ( V_14 ) )
F_14 ( V_16 ) ;
return V_14 ;
}
int T_3 F_15 ( struct V_29 * V_30 ,
const struct V_15 * V_31 , int V_32 ,
struct V_33 * V_34 )
{
int V_35 ;
struct V_14 * V_14 ;
struct V_8 * V_8 ;
V_8 = F_16 ( V_30 ) ;
if ( F_13 ( V_8 ) ) {
F_17 ( L_1 , V_30 -> V_36 ,
F_18 ( V_8 ) ) ;
return F_18 ( V_8 ) ;
}
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
const struct V_15 * V_5 = & V_31 [ V_35 ] ;
V_14 = F_8 ( V_5 , V_8 ) ;
if ( F_13 ( V_14 ) ) {
F_17 ( L_2 ,
V_5 -> V_21 , F_18 ( V_14 ) ) ;
continue;
}
V_34 -> V_31 [ V_5 -> V_37 ] = V_14 ;
}
return 0 ;
}
