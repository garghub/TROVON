static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 = F_2 ( F_3 ( V_2 ) -> V_9 ) ;
return ( V_8 >= V_6 -> V_10 && V_8 <= V_6 -> V_11 ) ^ V_6 -> V_12 ;
}
static bool
F_4 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const T_1 V_8 = F_2 ( F_5 ( V_2 ) -> V_13 ) +
sizeof( struct V_14 ) ;
return ( V_8 >= V_6 -> V_10 && V_8 <= V_6 -> V_11 ) ^ V_6 -> V_12 ;
}
static int T_2 F_6 ( void )
{
return F_7 ( V_15 , F_8 ( V_15 ) ) ;
}
static void T_3 F_9 ( void )
{
F_10 ( V_15 , F_8 ( V_15 ) ) ;
}
