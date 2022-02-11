static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
V_4 -> V_5 . V_6 = 1 ;
V_4 -> V_5 . V_7 = 1 ;
V_4 -> V_5 . V_8 = 0 ;
V_4 -> V_5 . V_9 = 1 ;
V_4 -> V_5 . V_10 = 0 ;
V_4 -> V_5 . V_11 . V_12 = 90 ;
V_4 -> V_5 . V_11 . V_13 = 3 ;
V_4 -> V_5 . V_14 . V_12 = 95 ;
V_4 -> V_5 . V_14 . V_13 = 3 ;
V_4 -> V_5 . V_15 . V_12 = 105 ;
V_4 -> V_5 . V_15 . V_13 = 5 ;
V_4 -> V_5 . V_16 . V_12 = 135 ;
V_4 -> V_5 . V_16 . V_13 = 5 ;
}
static void
F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
if ( ! V_4 -> V_5 . V_7 )
V_4 -> V_5 . V_7 = 1 ;
if ( ! V_4 -> V_5 . V_9 )
V_4 -> V_5 . V_9 = 1 ;
}
int
F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_17 * V_18 = V_17 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( F_4 ( V_18 , V_19 ,
& V_4 -> V_5 ) )
F_5 ( V_2 , L_1 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
