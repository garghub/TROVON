static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & ( V_7 | V_8 ) ) &&
( F_2 () != & V_9 ) )
return - V_10 ;
return 0 ;
}
static bool
F_3 ( const struct V_11 * V_12 , struct V_13 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_14 * V_15 ;
if ( V_12 -> V_16 == NULL || V_12 -> V_16 -> V_17 == NULL )
return ( V_4 -> V_6 ^ V_4 -> V_18 ) == 0 ;
else if ( V_4 -> V_6 & V_4 -> V_18 & V_19 )
return false ;
V_15 = V_12 -> V_16 -> V_17 -> V_14 ;
if ( V_15 == NULL )
return ( ( V_4 -> V_6 ^ V_4 -> V_18 ) &
( V_7 | V_8 ) ) == 0 ;
if ( V_4 -> V_6 & V_7 ) {
T_1 V_20 = F_4 ( & V_9 , V_4 -> V_20 ) ;
T_1 V_21 = F_4 ( & V_9 , V_4 -> V_21 ) ;
if ( ( F_5 ( V_15 -> V_22 -> V_23 , V_20 ) &&
F_6 ( V_15 -> V_22 -> V_23 , V_21 ) ) ^
! ( V_4 -> V_18 & V_7 ) )
return false ;
}
if ( V_4 -> V_6 & V_8 ) {
T_2 V_24 = F_7 ( & V_9 , V_4 -> V_24 ) ;
T_2 V_25 = F_7 ( & V_9 , V_4 -> V_25 ) ;
if ( ( F_8 ( V_15 -> V_22 -> V_26 , V_24 ) &&
F_9 ( V_15 -> V_22 -> V_26 , V_25 ) ) ^
! ( V_4 -> V_18 & V_8 ) )
return false ;
}
return true ;
}
static int T_3 F_10 ( void )
{
return F_11 ( & V_27 ) ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_27 ) ;
}
