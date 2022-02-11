static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_6 = V_2 -> V_6 ;
if ( ( V_4 -> V_7 & ( V_8 | V_9 ) ) &&
( F_2 () != V_6 -> V_10 ) )
return - V_11 ;
if ( V_4 -> V_7 & V_8 ) {
T_1 V_12 = F_3 ( V_6 -> V_10 , V_4 -> V_12 ) ;
T_1 V_13 = F_3 ( V_6 -> V_10 , V_4 -> V_13 ) ;
if ( ! F_4 ( V_12 ) || ! F_4 ( V_13 ) ||
( V_4 -> V_13 < V_4 -> V_12 ) ||
F_5 ( V_13 , V_12 ) ) {
return - V_11 ;
}
}
if ( V_4 -> V_7 & V_9 ) {
T_2 V_14 = F_6 ( V_6 -> V_10 , V_4 -> V_14 ) ;
T_2 V_15 = F_6 ( V_6 -> V_10 , V_4 -> V_15 ) ;
if ( ! F_7 ( V_14 ) || ! F_7 ( V_15 ) ||
( V_4 -> V_15 < V_4 -> V_14 ) ||
F_8 ( V_15 , V_14 ) ) {
return - V_11 ;
}
}
return 0 ;
}
static bool
F_9 ( const struct V_16 * V_17 , struct V_18 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_19 * V_20 ;
struct V_21 * V_22 = F_10 ( V_17 ) ;
struct V_6 * V_6 = F_11 ( V_2 ) ;
if ( V_22 == NULL || V_22 -> V_23 == NULL )
return ( V_4 -> V_7 ^ V_4 -> V_24 ) == 0 ;
else if ( V_4 -> V_7 & V_4 -> V_24 & V_25 )
return false ;
V_20 = V_22 -> V_23 -> V_19 ;
if ( V_20 == NULL )
return ( ( V_4 -> V_7 ^ V_4 -> V_24 ) &
( V_8 | V_9 ) ) == 0 ;
if ( V_4 -> V_7 & V_8 ) {
T_1 V_12 = F_3 ( V_6 -> V_10 , V_4 -> V_12 ) ;
T_1 V_13 = F_3 ( V_6 -> V_10 , V_4 -> V_13 ) ;
if ( ( F_12 ( V_20 -> V_26 -> V_27 , V_12 ) &&
F_13 ( V_20 -> V_26 -> V_27 , V_13 ) ) ^
! ( V_4 -> V_24 & V_8 ) )
return false ;
}
if ( V_4 -> V_7 & V_9 ) {
T_2 V_14 = F_6 ( V_6 -> V_10 , V_4 -> V_14 ) ;
T_2 V_15 = F_6 ( V_6 -> V_10 , V_4 -> V_15 ) ;
if ( ( F_14 ( V_20 -> V_26 -> V_28 , V_14 ) &&
F_15 ( V_20 -> V_26 -> V_28 , V_15 ) ) ^
! ( V_4 -> V_24 & V_9 ) )
return false ;
}
return true ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_29 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_29 ) ;
}
