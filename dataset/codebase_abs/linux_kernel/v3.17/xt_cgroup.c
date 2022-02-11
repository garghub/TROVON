static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & ~ 1 )
return - V_7 ;
return 0 ;
}
static bool
F_2 ( const struct V_8 * V_9 , struct V_10 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_9 -> V_11 == NULL )
return false ;
return ( V_4 -> V_12 == V_9 -> V_11 -> V_13 ) ^ V_4 -> V_6 ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_14 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( & V_14 ) ;
}
