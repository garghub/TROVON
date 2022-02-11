static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_2 ) {
F_2 ( & V_4 -> V_2 ) ;
F_3 ( V_4 ) ;
}
}
static int
F_4 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( V_2 -> V_10 ) {
V_8 -> V_10 = V_2 -> V_10 ;
V_8 -> V_11 = NULL ;
} else {
V_8 -> V_10 = NULL ;
V_8 -> V_11 = V_4 -> V_2 . V_12 ;
}
V_8 -> V_13 = ( V_6 -> V_14 << V_15 ) >> 12 ;
F_5 ( & V_8 -> V_16 [ 0 ] , V_8 ) ;
V_4 -> V_8 = V_8 ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_7 ( & V_4 -> V_8 -> V_16 [ 0 ] ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( V_2 -> V_10 ) {
V_8 -> V_10 = V_2 -> V_10 ;
V_8 -> V_11 = NULL ;
} else {
V_8 -> V_10 = NULL ;
V_8 -> V_11 = V_4 -> V_2 . V_12 ;
}
V_8 -> V_13 = ( V_6 -> V_14 << V_15 ) >> 12 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
struct V_1 *
F_10 ( struct V_17 * V_18 ,
unsigned long V_13 , T_1 V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_3 * V_4 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
if ( V_23 -> V_25 . V_26 . V_27 . V_28 < V_29 )
V_4 -> V_2 . V_2 . V_30 = & V_31 ;
else
V_4 -> V_2 . V_2 . V_30 = & V_32 ;
if ( F_13 ( & V_4 -> V_2 , V_18 , V_13 , V_19 , V_21 ) )
return NULL ;
return & V_4 -> V_2 . V_2 ;
}
