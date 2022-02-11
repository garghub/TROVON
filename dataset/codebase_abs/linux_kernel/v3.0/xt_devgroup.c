static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_8 & V_9 &&
( ( ( V_6 -> V_10 ^ V_4 -> V_11 -> V_12 ) & V_6 -> V_13 ? 1 : 0 ) ^
( ( V_6 -> V_8 & V_14 ) ? 1 : 0 ) ) )
return false ;
if ( V_6 -> V_8 & V_15 &&
( ( ( V_6 -> V_16 ^ V_4 -> V_17 -> V_12 ) & V_6 -> V_18 ? 1 : 0 ) ^
( ( V_6 -> V_8 & V_19 ) ? 1 : 0 ) ) )
return false ;
return true ;
}
static int F_2 ( const struct V_20 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_8 & ~ ( V_9 | V_14 |
V_15 | V_19 ) )
return - V_21 ;
if ( V_6 -> V_8 & V_9 &&
V_4 -> V_22 & ~ ( ( 1 << V_23 ) |
( 1 << V_24 ) |
( 1 << V_25 ) ) )
return - V_21 ;
if ( V_6 -> V_8 & V_15 &&
V_4 -> V_22 & ~ ( ( 1 << V_25 ) |
( 1 << V_26 ) |
( 1 << V_27 ) ) )
return - V_21 ;
return 0 ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_28 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( & V_28 ) ;
}
