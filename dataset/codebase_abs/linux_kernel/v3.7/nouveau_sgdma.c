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
T_1 V_10 = V_6 -> V_11 << 12 ;
if ( V_2 -> V_12 ) {
V_8 -> V_12 = V_2 -> V_12 ;
F_5 ( & V_8 -> V_13 [ 0 ] , 0 , V_10 , V_8 ) ;
} else {
V_8 -> V_14 = V_4 -> V_2 . V_15 ;
F_6 ( & V_8 -> V_13 [ 0 ] , 0 , V_10 , V_8 ) ;
}
V_4 -> V_8 = V_8 ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_8 ( & V_4 -> V_8 -> V_13 [ 0 ] ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( V_2 -> V_12 ) {
V_8 -> V_12 = V_2 -> V_12 ;
} else
V_8 -> V_14 = V_4 -> V_2 . V_15 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
struct V_1 *
F_11 ( struct V_16 * V_17 ,
unsigned long V_10 , T_2 V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_12 ( V_17 ) ;
struct V_3 * V_4 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_24 = V_22 -> V_24 ;
if ( F_14 ( V_22 -> V_25 ) -> V_26 < V_27 )
V_4 -> V_2 . V_2 . V_28 = & V_29 ;
else
V_4 -> V_2 . V_2 . V_28 = & V_30 ;
if ( F_15 ( & V_4 -> V_2 , V_17 , V_10 , V_18 , V_20 ) ) {
F_3 ( V_4 ) ;
return NULL ;
}
return & V_4 -> V_2 . V_2 ;
}
