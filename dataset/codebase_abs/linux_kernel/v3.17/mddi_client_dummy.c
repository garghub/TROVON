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
F_6 ( & V_4 -> V_7 , sizeof( struct V_9 ) , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
F_7 ( V_4 , V_10 ) ;
V_10 -> V_2 . V_13 = F_1 ;
V_10 -> V_2 . V_14 = F_2 ;
V_10 -> V_2 . V_15 = F_3 ;
V_10 -> V_2 . V_16 = F_4 ;
V_10 -> V_2 . V_17 = V_18 ;
V_10 -> V_4 . V_19 = L_1 ;
V_10 -> V_4 . V_20 = V_4 -> V_20 ;
F_8 ( & V_10 -> V_4 ,
V_6 -> V_21 , 1 ) ;
V_10 -> V_2 . V_22 = V_6 -> V_23 ;
V_10 -> V_4 . V_7 . V_8 = & V_10 -> V_2 ;
return F_9 ( & V_10 -> V_4 ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_24 ) ;
return 0 ;
}
