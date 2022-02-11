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
struct V_16 * V_17 = F_4 ( V_12 ) ;
if ( V_17 == NULL || V_17 -> V_18 == NULL )
return ( V_4 -> V_6 ^ V_4 -> V_19 ) == 0 ;
else if ( V_4 -> V_6 & V_4 -> V_19 & V_20 )
return false ;
V_15 = V_17 -> V_18 -> V_14 ;
if ( V_15 == NULL )
return ( ( V_4 -> V_6 ^ V_4 -> V_19 ) &
( V_7 | V_8 ) ) == 0 ;
if ( V_4 -> V_6 & V_7 ) {
T_1 V_21 = F_5 ( & V_9 , V_4 -> V_21 ) ;
T_1 V_22 = F_5 ( & V_9 , V_4 -> V_22 ) ;
if ( ( F_6 ( V_15 -> V_23 -> V_24 , V_21 ) &&
F_7 ( V_15 -> V_23 -> V_24 , V_22 ) ) ^
! ( V_4 -> V_19 & V_7 ) )
return false ;
}
if ( V_4 -> V_6 & V_8 ) {
T_2 V_25 = F_8 ( & V_9 , V_4 -> V_25 ) ;
T_2 V_26 = F_8 ( & V_9 , V_4 -> V_26 ) ;
if ( ( F_9 ( V_15 -> V_23 -> V_27 , V_25 ) &&
F_10 ( V_15 -> V_23 -> V_27 , V_26 ) ) ^
! ( V_4 -> V_19 & V_8 ) )
return false ;
}
return true ;
}
static int T_3 F_11 ( void )
{
return F_12 ( & V_28 ) ;
}
static void T_4 F_13 ( void )
{
F_14 ( & V_28 ) ;
}
