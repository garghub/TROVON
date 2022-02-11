static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
T_1 type ;
if ( V_2 -> V_8 != V_9 )
type = V_2 -> V_8 ;
else if ( V_4 -> V_10 == V_11 &&
F_2 ( F_3 ( V_2 ) -> V_12 ) )
type = V_13 ;
else if ( V_4 -> V_10 == V_14 &&
F_4 ( V_2 ) -> V_12 . V_15 [ 0 ] == 0xFF )
type = V_13 ;
else
type = V_16 ;
return ( type == V_6 -> V_17 ) ^ V_6 -> V_18 ;
}
static int T_2 F_5 ( void )
{
return F_6 ( & V_19 ) ;
}
static void T_3 F_7 ( void )
{
F_8 ( & V_19 ) ;
}
