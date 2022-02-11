static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & ~ 1 )
return - V_7 ;
return 0 ;
}
static bool F_2 ( const struct V_8 * V_9 , struct V_10 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
return ( V_4 -> V_11 == F_3 () ) ^ V_4 -> V_6 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_12 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_12 ) ;
}
