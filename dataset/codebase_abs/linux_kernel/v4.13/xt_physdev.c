static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
unsigned long V_10 ;
const char * V_11 , * V_12 ;
if ( ! V_2 -> V_13 ) {
if ( ( V_6 -> V_14 & V_15 ) &&
! ( V_6 -> V_16 & V_15 ) )
return false ;
if ( ( V_6 -> V_14 & V_17 ) &&
! ( V_6 -> V_16 & V_17 ) )
return false ;
if ( ( V_6 -> V_14 & V_18 ) &&
! ( V_6 -> V_16 & V_18 ) )
return false ;
if ( ( V_6 -> V_14 & V_19 ) &&
! ( V_6 -> V_16 & V_19 ) )
return false ;
if ( ( V_6 -> V_14 & V_20 ) &&
! ( V_6 -> V_16 & V_20 ) )
return false ;
return true ;
}
V_9 = F_2 ( V_2 ) ;
V_12 = V_9 ? V_9 -> V_21 : NULL ;
if ( ( V_6 -> V_14 & V_15 ) &&
( ! ! V_12 ^ ! ( V_6 -> V_16 & V_15 ) ) )
return false ;
V_9 = F_3 ( V_2 ) ;
V_11 = V_9 ? V_9 -> V_21 : NULL ;
if ( ( V_6 -> V_14 & V_17 &&
( ! V_11 ^ ! ! ( V_6 -> V_16 & V_17 ) ) ) ||
( V_6 -> V_14 & V_18 &&
( ! V_12 ^ ! ! ( V_6 -> V_16 & V_18 ) ) ) )
return false ;
if ( ! ( V_6 -> V_14 & V_19 ) )
goto V_22;
if ( V_11 ) {
V_10 = F_4 ( V_11 , V_6 -> V_23 ,
V_6 -> V_24 ) ;
if ( ! V_10 ^ ! ( V_6 -> V_16 & V_19 ) )
return false ;
}
V_22:
if ( ! ( V_6 -> V_14 & V_20 ) )
return true ;
if ( ! V_12 )
return false ;
V_10 = F_4 ( V_12 , V_6 -> V_25 , V_6 -> V_26 ) ;
return ( ! ! V_10 ^ ! ( V_6 -> V_16 & V_20 ) ) ;
}
static int F_5 ( const struct V_27 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
F_6 () ;
if ( ! ( V_6 -> V_14 & V_28 ) ||
V_6 -> V_14 & ~ V_28 )
return - V_29 ;
if ( V_6 -> V_14 & ( V_20 | V_18 ) &&
( ! ( V_6 -> V_14 & V_15 ) ||
V_6 -> V_16 & V_15 ) &&
V_4 -> V_30 & ( ( 1 << V_31 ) |
( 1 << V_32 ) | ( 1 << V_33 ) ) ) {
F_7 ( L_1
L_2
L_3 ) ;
if ( V_4 -> V_30 & ( 1 << V_31 ) )
return - V_29 ;
}
return 0 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_34 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_34 ) ;
}
