static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
V_2 -> V_8 = ( V_2 -> V_8 & ~ V_6 -> V_9 ) ^ V_6 -> V_8 ;
return V_10 ;
}
static bool
F_2 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_11 * V_6 = V_4 -> V_12 ;
return ( ( V_2 -> V_8 & V_6 -> V_9 ) == V_6 -> V_8 ) ^ V_6 -> V_13 ;
}
static int T_1 F_3 ( void )
{
int V_14 ;
V_14 = F_4 ( & V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( & V_16 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_15 ) ;
return V_14 ;
}
return 0 ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_16 ) ;
F_6 ( & V_15 ) ;
}
