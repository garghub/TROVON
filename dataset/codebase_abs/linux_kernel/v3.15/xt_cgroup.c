static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & ~ 1 )
return - V_7 ;
return V_4 -> V_8 ? 0 : - V_7 ;
}
static bool
F_2 ( const struct V_9 * V_10 , struct V_11 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_10 -> V_12 == NULL )
return false ;
return ( V_4 -> V_8 == V_10 -> V_12 -> V_13 ) ^ V_4 -> V_6 ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_14 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( & V_14 ) ;
}
