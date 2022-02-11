static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
return ( V_2 -> V_8 == V_6 -> V_8 ) ^ V_6 -> V_9 ;
}
static int F_2 ( const struct V_10 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_9 != 0 && V_6 -> V_9 != 1 )
return - V_11 ;
return 0 ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_12 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( & V_12 ) ;
}
