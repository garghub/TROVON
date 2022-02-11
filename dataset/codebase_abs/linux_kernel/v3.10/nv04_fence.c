static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , V_7 , 0x0150 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_9 , struct V_3 * V_4 )
{
return - V_10 ;
}
static T_1
F_7 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = ( void * ) V_4 -> V_13 ;
return F_8 ( & V_12 -> V_14 ) ;
}
static void
F_9 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_2 ;
F_10 ( & V_16 -> V_17 ) ;
V_4 -> V_2 = NULL ;
F_11 ( V_16 ) ;
}
static int
F_12 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_13 ( sizeof( * V_16 ) , V_18 ) ;
if ( V_16 ) {
F_14 ( & V_16 -> V_17 ) ;
V_16 -> V_17 . V_19 = F_1 ;
V_16 -> V_17 . V_20 = F_6 ;
V_16 -> V_17 . V_21 = F_7 ;
V_4 -> V_2 = V_16 ;
return 0 ;
}
return - V_22 ;
}
static void
F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_2 ;
V_24 -> V_2 = NULL ;
F_11 ( V_26 ) ;
}
int
F_16 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
V_26 = V_24 -> V_2 = F_13 ( sizeof( * V_26 ) , V_18 ) ;
if ( ! V_26 )
return - V_22 ;
V_26 -> V_17 . V_27 = F_15 ;
V_26 -> V_17 . V_28 = F_12 ;
V_26 -> V_17 . V_29 = F_9 ;
return 0 ;
}
