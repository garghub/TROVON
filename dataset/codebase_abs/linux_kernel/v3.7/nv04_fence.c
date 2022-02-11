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
V_4 -> V_2 = V_16 ;
return 0 ;
}
return - V_19 ;
}
static void
F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_2 ;
V_21 -> V_2 = NULL ;
F_11 ( V_23 ) ;
}
int
F_16 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
V_23 = V_21 -> V_2 = F_13 ( sizeof( * V_23 ) , V_18 ) ;
if ( ! V_23 )
return - V_19 ;
V_23 -> V_17 . V_24 = F_15 ;
V_23 -> V_17 . V_25 = F_12 ;
V_23 -> V_17 . V_26 = F_9 ;
V_23 -> V_17 . V_27 = F_1 ;
V_23 -> V_17 . V_28 = F_6 ;
V_23 -> V_17 . V_29 = F_7 ;
return 0 ;
}
