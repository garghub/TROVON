static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 ,
enum V_5 V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_11 = ( V_6 ? 1 : 0 ) ^ ( V_9 -> V_12 & V_13 ) ;
F_4 ( V_9 -> V_14 , V_11 ) ;
if ( V_9 -> V_12 & V_15 ) {
if ( V_6 )
F_5 ( V_9 -> V_14 , V_11 ) ;
else
F_6 ( V_9 -> V_14 ) ;
}
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_8 * V_10 = F_8 ( & V_17 -> V_17 ) ;
struct V_1 * V_7 ;
int V_18 ;
V_7 = F_9 ( & V_17 -> V_17 , sizeof( struct V_1 ) ,
V_19 ) ;
if ( ! V_7 )
return - V_20 ;
V_7 -> V_4 . V_21 = F_3 ;
V_7 -> V_4 . V_22 = V_10 -> V_23 ;
V_7 -> V_4 . V_24 = V_10 -> V_24 ;
V_7 -> V_4 . V_12 |= V_25 ;
V_7 -> V_10 = V_10 ;
V_18 = F_10 ( & V_17 -> V_17 , V_10 -> V_14 , L_1 ) ;
if ( V_18 < 0 )
return V_18 ;
F_11 ( V_10 -> V_14 , V_26 ) ;
if ( V_10 -> V_12 & V_15 )
F_6 ( V_10 -> V_14 ) ;
else
F_5 ( V_10 -> V_14 ,
V_10 -> V_12 & V_13 ? 1 : 0 ) ;
V_18 = F_12 ( & V_17 -> V_17 , & V_7 -> V_4 ) ;
if ( V_18 < 0 )
F_13 ( & V_17 -> V_17 , L_2 ) ;
return V_18 ;
}
