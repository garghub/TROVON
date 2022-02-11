static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
static const char V_5 [ V_6 ] V_7 ( ( F_2 ( sizeof( long ) ) ) ) ;
const struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_11 ;
const char * V_12 , * V_13 ;
const struct V_14 * V_15 ;
if ( ! ( V_15 = V_2 -> V_15 ) ) {
if ( ( V_9 -> V_16 & V_17 ) &&
! ( V_9 -> V_18 & V_17 ) )
return false ;
if ( ( V_9 -> V_16 & V_19 ) &&
! ( V_9 -> V_18 & V_19 ) )
return false ;
if ( ( V_9 -> V_16 & V_20 ) &&
! ( V_9 -> V_18 & V_20 ) )
return false ;
if ( ( V_9 -> V_16 & V_21 ) &&
! ( V_9 -> V_18 & V_21 ) )
return false ;
if ( ( V_9 -> V_16 & V_22 ) &&
! ( V_9 -> V_18 & V_22 ) )
return false ;
return true ;
}
if ( ( V_9 -> V_16 & V_17 ) &&
( ! ! ( V_15 -> V_23 & V_24 ) ^
! ( V_9 -> V_18 & V_17 ) ) )
return false ;
if ( ( V_9 -> V_16 & V_19 &&
( ! V_15 -> V_25 ^ ! ! ( V_9 -> V_18 & V_19 ) ) ) ||
( V_9 -> V_16 & V_20 &&
( ! V_15 -> V_26 ^ ! ! ( V_9 -> V_18 & V_20 ) ) ) )
return false ;
if ( ! ( V_9 -> V_16 & V_21 ) )
goto V_27;
V_12 = V_15 -> V_25 ? V_15 -> V_25 -> V_28 : V_5 ;
V_11 = F_3 ( V_12 , V_9 -> V_25 , V_9 -> V_29 ) ;
if ( ! V_11 ^ ! ( V_9 -> V_18 & V_21 ) )
return false ;
V_27:
if ( ! ( V_9 -> V_16 & V_22 ) )
return true ;
V_13 = V_15 -> V_26 ?
V_15 -> V_26 -> V_28 : V_5 ;
V_11 = F_3 ( V_13 , V_9 -> V_26 , V_9 -> V_30 ) ;
return ( ! ! V_11 ^ ! ( V_9 -> V_18 & V_22 ) ) ;
}
static int F_4 ( const struct V_31 * V_4 )
{
const struct V_8 * V_9 = V_4 -> V_10 ;
if ( ! ( V_9 -> V_16 & V_32 ) ||
V_9 -> V_16 & ~ V_32 )
return - V_33 ;
if ( V_9 -> V_16 & V_22 &&
( ! ( V_9 -> V_16 & V_17 ) ||
V_9 -> V_18 & V_17 ) &&
V_4 -> V_34 & ( ( 1 << V_35 ) |
( 1 << V_36 ) | ( 1 << V_37 ) ) ) {
F_5 ( L_1
L_2
L_3 ) ;
if ( V_4 -> V_34 & ( 1 << V_35 ) )
return - V_33 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_38 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_38 ) ;
}
