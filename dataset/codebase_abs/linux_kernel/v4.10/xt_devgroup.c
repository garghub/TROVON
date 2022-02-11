static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_8 & V_9 &&
( ( ( V_6 -> V_10 ^ F_2 ( V_4 ) -> V_11 ) & V_6 -> V_12 ? 1 : 0 ) ^
( ( V_6 -> V_8 & V_13 ) ? 1 : 0 ) ) )
return false ;
if ( V_6 -> V_8 & V_14 &&
( ( ( V_6 -> V_15 ^ F_3 ( V_4 ) -> V_11 ) & V_6 -> V_16 ? 1 : 0 ) ^
( ( V_6 -> V_8 & V_17 ) ? 1 : 0 ) ) )
return false ;
return true ;
}
static int F_4 ( const struct V_18 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_8 & ~ ( V_9 | V_13 |
V_14 | V_17 ) )
return - V_19 ;
if ( V_6 -> V_8 & V_9 &&
V_4 -> V_20 & ~ ( ( 1 << V_21 ) |
( 1 << V_22 ) |
( 1 << V_23 ) ) )
return - V_19 ;
if ( V_6 -> V_8 & V_14 &&
V_4 -> V_20 & ~ ( ( 1 << V_23 ) |
( 1 << V_24 ) |
( 1 << V_25 ) ) )
return - V_19 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_26 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_26 ) ;
}
