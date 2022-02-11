static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 V_8 = { } ;
V_6 = F_2 ( V_2 -> V_9 . V_10 ) ;
V_8 . V_9 = & V_2 -> V_9 ;
V_8 . V_11 = V_2 -> V_9 . V_12 ;
V_8 . V_13 = V_6 ;
V_8 . V_14 = V_6 -> V_14 ;
V_4 = F_3 ( & V_15 [ V_2 -> V_16 ] , & V_8 ) ;
if ( F_4 ( V_4 ) )
return F_5 ( V_4 ) ;
F_6 ( V_2 , V_4 ) ;
if ( V_6 -> V_17 -> V_18 )
V_6 -> V_17 -> V_18 ( V_6 , V_2 -> V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_19 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_19 ) ;
}
