static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
struct V_9 * V_10 =
F_6 ( sizeof( struct V_9 ) , V_11 ) ;
int V_12 ;
if ( ! V_10 )
return - V_13 ;
F_7 ( V_4 , V_10 ) ;
V_10 -> V_2 . V_14 = F_1 ;
V_10 -> V_2 . V_15 = F_2 ;
V_10 -> V_2 . V_16 = F_3 ;
V_10 -> V_2 . V_17 = F_4 ;
V_10 -> V_2 . V_18 = V_19 ;
V_10 -> V_4 . V_20 = L_1 ;
V_10 -> V_4 . V_21 = V_4 -> V_21 ;
F_8 ( & V_10 -> V_4 ,
V_6 -> V_22 , 1 ) ;
V_10 -> V_2 . V_23 = V_6 -> V_24 ;
V_10 -> V_4 . V_7 . V_8 = & V_10 -> V_2 ;
V_12 = F_9 ( & V_10 -> V_4 ) ;
if ( V_12 ) {
F_10 ( V_10 ) ;
return V_12 ;
}
return 0 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = F_12 ( V_4 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
F_14 ( & V_25 ) ;
return 0 ;
}
