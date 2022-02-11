static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , V_7 , 0x0150 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 . V_9 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_10 , struct V_3 * V_4 )
{
return - V_11 ;
}
static T_1
F_7 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = F_8 ( V_4 ) ; ;
return F_9 ( & V_13 -> V_14 ) ;
}
static void
F_10 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_2 ;
F_11 ( & V_16 -> V_8 ) ;
V_4 -> V_2 = NULL ;
F_12 ( & V_16 -> V_8 ) ;
}
static int
F_13 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_14 ( sizeof( * V_16 ) , V_17 ) ;
if ( V_16 ) {
F_15 ( V_4 , & V_16 -> V_8 ) ;
V_16 -> V_8 . V_18 = F_1 ;
V_16 -> V_8 . V_19 = F_6 ;
V_16 -> V_8 . V_20 = F_7 ;
V_4 -> V_2 = V_16 ;
return 0 ;
}
return - V_21 ;
}
static void
F_16 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_2 ;
V_23 -> V_2 = NULL ;
F_17 ( V_25 ) ;
}
int
F_18 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
V_25 = V_23 -> V_2 = F_14 ( sizeof( * V_25 ) , V_17 ) ;
if ( ! V_25 )
return - V_21 ;
V_25 -> V_8 . V_26 = F_16 ;
V_25 -> V_8 . V_27 = F_13 ;
V_25 -> V_8 . V_28 = F_10 ;
V_25 -> V_8 . V_29 = 15 ;
V_25 -> V_8 . V_30 = F_19 ( V_25 -> V_8 . V_29 ) ;
return 0 ;
}
