static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
T_1 type ;
if ( V_2 -> V_8 != V_9 )
type = V_2 -> V_8 ;
else if ( F_2 ( V_4 ) == V_10 &&
F_3 ( F_4 ( V_2 ) -> V_11 ) )
type = V_12 ;
else if ( F_2 ( V_4 ) == V_13 )
type = V_12 ;
else
type = V_14 ;
return ( type == V_6 -> V_15 ) ^ V_6 -> V_16 ;
}
static int T_2 F_5 ( void )
{
return F_6 ( & V_17 ) ;
}
static void T_3 F_7 ( void )
{
F_8 ( & V_17 ) ;
}
