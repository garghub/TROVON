static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 V_8 = { } ;
V_6 = F_2 ( V_2 -> V_9 . V_10 ) ;
V_8 . V_9 = & V_2 -> V_9 ;
V_8 . V_11 = F_3 ( & V_2 -> V_9 ) ;
V_8 . V_12 = V_6 ;
V_8 . V_13 = V_6 -> V_13 ;
V_4 = F_4 ( & V_14 [ V_2 -> V_15 ] , & V_8 ) ;
if ( F_5 ( V_4 ) )
return F_6 ( V_4 ) ;
F_7 ( V_2 , V_4 ) ;
if ( V_6 -> V_16 -> V_17 )
V_6 -> V_16 -> V_17 ( V_6 , V_2 -> V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_18 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_18 ) ;
}
