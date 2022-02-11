static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
const struct V_8 * V_10 ;
V_10 = F_2 ( V_2 , V_4 -> V_11 , sizeof( V_9 ) , & V_9 ) ;
if ( V_10 == NULL )
return false ;
if ( V_6 -> V_12 & V_13 ) {
if ( V_6 -> V_14 & V_13 ) {
if ( V_10 -> V_15 == 1 )
return false ;
} else {
if ( V_10 -> V_15 == 0 )
return false ;
}
}
if ( V_6 -> V_12 & V_16 ) {
if ( V_6 -> V_14 & V_16 ) {
if ( V_10 -> V_17 == 1 )
return false ;
} else {
if ( V_10 -> V_17 == 0 )
return false ;
}
}
return true ;
}
static inline bool F_3 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
return ( ( F_4 ( V_2 ) -> V_18 & V_19 ) == V_6 -> V_20 ) ^
! ! ( V_6 -> V_14 & V_21 ) ;
}
static bool F_5 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_22 = V_4 -> V_7 ;
if ( V_22 -> V_12 & V_21 && ! F_3 ( V_2 , V_22 ) )
return false ;
if ( V_22 -> V_12 & ( V_13 | V_16 ) &&
! F_1 ( V_2 , V_4 ) )
return false ;
return true ;
}
static int F_6 ( const struct V_23 * V_4 )
{
const struct V_5 * V_22 = V_4 -> V_7 ;
const struct V_24 * V_25 = V_4 -> V_26 ;
if ( V_22 -> V_12 & V_27 )
return - V_28 ;
if ( V_22 -> V_14 & V_27 )
return - V_28 ;
if ( V_22 -> V_12 & ( V_13 | V_16 ) &&
( V_25 -> V_29 != V_30 || V_25 -> V_31 & V_32 ) ) {
F_7 ( L_1 ) ;
return - V_28 ;
}
return 0 ;
}
static inline bool F_8 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
return ( ( ( F_9 ( V_2 ) -> V_33 [ 0 ] >> 4 ) & V_19 ) ==
V_6 -> V_20 ) ^
! ! ( V_6 -> V_14 & V_21 ) ;
}
static bool F_10 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_22 = V_4 -> V_7 ;
if ( V_22 -> V_12 & V_21 && ! F_8 ( V_2 , V_22 ) )
return false ;
if ( V_22 -> V_12 & ( V_13 | V_16 ) &&
! F_1 ( V_2 , V_4 ) )
return false ;
return true ;
}
static int F_11 ( const struct V_23 * V_4 )
{
const struct V_5 * V_22 = V_4 -> V_7 ;
const struct V_34 * V_25 = V_4 -> V_26 ;
if ( V_22 -> V_12 & V_27 )
return - V_28 ;
if ( V_22 -> V_14 & V_27 )
return - V_28 ;
if ( V_22 -> V_12 & ( V_13 | V_16 ) &&
( V_25 -> V_29 != V_30 || V_25 -> V_31 & V_35 ) ) {
F_7 ( L_1 ) ;
return - V_28 ;
}
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( V_36 , F_14 ( V_36 ) ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( V_36 , F_14 ( V_36 ) ) ;
}
