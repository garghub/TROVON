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
F_6 ( V_11 -> V_13 , ( V_8 ? 1 : 0 ) ^
( V_11 -> V_14 & V_15 ) ) ;
if ( V_11 -> V_14 & V_16 )
F_7 ( V_11 -> V_13 ,
V_8 ? V_17 : V_18 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_9 ( & V_9 -> V_6 ) ;
F_10 ( V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_10 * V_12 = V_3 -> V_3 . V_19 ;
struct V_1 * V_9 ;
int V_20 ;
V_9 = F_12 ( sizeof( struct V_1 ) , V_21 ) ;
if ( V_9 == NULL ) {
F_13 ( & V_3 -> V_3 , L_1 ) ;
return - V_22 ;
}
F_14 ( V_3 , V_9 ) ;
V_9 -> V_6 . V_23 = F_5 ;
V_9 -> V_6 . V_24 = V_12 -> V_25 ;
V_9 -> V_6 . V_26 = V_12 -> V_26 ;
V_9 -> V_6 . V_14 |= V_27 ;
V_9 -> V_12 = V_12 ;
if ( V_12 -> V_14 & V_16 ) {
F_6 ( V_12 -> V_13 , 0 ) ;
F_7 ( V_12 -> V_13 , V_18 ) ;
} else {
F_15 ( V_12 -> V_13 , 0 ) ;
F_6 ( V_12 -> V_13 , 0 ) ;
F_7 ( V_12 -> V_13 , V_17 ) ;
}
V_20 = F_16 ( & V_3 -> V_3 , & V_9 -> V_6 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_3 -> V_3 , L_2 ) ;
F_10 ( V_9 ) ;
return V_20 ;
}
return 0 ;
}
