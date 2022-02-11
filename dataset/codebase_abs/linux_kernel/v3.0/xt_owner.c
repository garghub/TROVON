static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
if ( V_2 -> V_10 == NULL || V_2 -> V_10 -> V_11 == NULL )
return ( V_6 -> V_12 ^ V_6 -> V_13 ) == 0 ;
else if ( V_6 -> V_12 & V_6 -> V_13 & V_14 )
return false ;
V_9 = V_2 -> V_10 -> V_11 -> V_8 ;
if ( V_9 == NULL )
return ( ( V_6 -> V_12 ^ V_6 -> V_13 ) &
( V_15 | V_16 ) ) == 0 ;
if ( V_6 -> V_12 & V_15 )
if ( ( V_9 -> V_17 -> V_18 >= V_6 -> V_19 &&
V_9 -> V_17 -> V_18 <= V_6 -> V_20 ) ^
! ( V_6 -> V_13 & V_15 ) )
return false ;
if ( V_6 -> V_12 & V_16 )
if ( ( V_9 -> V_17 -> V_21 >= V_6 -> V_22 &&
V_9 -> V_17 -> V_21 <= V_6 -> V_23 ) ^
! ( V_6 -> V_13 & V_16 ) )
return false ;
return true ;
}
static int T_1 F_2 ( void )
{
return F_3 ( & V_24 ) ;
}
static void T_2 F_4 ( void )
{
F_5 ( & V_24 ) ;
}
