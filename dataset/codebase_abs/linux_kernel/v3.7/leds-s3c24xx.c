static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 , struct V_1 , V_6 ) ;
}
static void F_5 ( struct V_4 * V_5 ,
enum V_7 V_8 )
{
struct V_1 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_13 = ( V_8 ? 1 : 0 ) ^ ( V_11 -> V_14 & V_15 ) ;
F_6 ( V_11 -> V_16 , V_13 ) ;
if ( V_11 -> V_14 & V_17 ) {
if ( V_8 )
F_7 ( V_11 -> V_16 , V_13 ) ;
else
F_8 ( V_11 -> V_16 ) ;
}
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_10 ( & V_9 -> V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_10 * V_12 = V_3 -> V_3 . V_18 ;
struct V_1 * V_9 ;
int V_19 ;
V_9 = F_12 ( & V_3 -> V_3 , sizeof( struct V_1 ) ,
V_20 ) ;
if ( V_9 == NULL ) {
F_13 ( & V_3 -> V_3 , L_1 ) ;
return - V_21 ;
}
F_14 ( V_3 , V_9 ) ;
V_9 -> V_6 . V_22 = F_5 ;
V_9 -> V_6 . V_23 = V_12 -> V_24 ;
V_9 -> V_6 . V_25 = V_12 -> V_25 ;
V_9 -> V_6 . V_14 |= V_26 ;
V_9 -> V_12 = V_12 ;
V_19 = F_15 ( & V_3 -> V_3 , V_12 -> V_16 , L_2 ) ;
if ( V_19 < 0 )
return V_19 ;
F_16 ( V_12 -> V_16 , V_27 ) ;
if ( V_12 -> V_14 & V_17 )
F_8 ( V_12 -> V_16 ) ;
else
F_7 ( V_12 -> V_16 ,
V_12 -> V_14 & V_15 ? 1 : 0 ) ;
V_19 = F_17 ( & V_3 -> V_3 , & V_9 -> V_6 ) ;
if ( V_19 < 0 )
F_13 ( & V_3 -> V_3 , L_3 ) ;
return V_19 ;
}
