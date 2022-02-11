static inline bool
F_1 ( T_1 V_1 , T_1 V_2 , T_1 type , bool V_3 )
{
return ( type >= V_1 && type <= V_2 ) ^ V_3 ;
}
static bool F_2 ( const struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 V_9 ;
const struct V_8 * V_10 ;
const struct V_11 * V_12 = V_7 -> V_13 ;
if ( V_7 -> V_14 != 0 )
return false ;
V_10 = F_3 ( V_5 , V_7 -> V_15 , sizeof( V_9 ) , & V_9 ) ;
if ( V_10 == NULL ) {
F_4 ( L_1 ) ;
V_7 -> V_16 = true ;
return false ;
}
if ( V_10 -> V_17 != V_18 ) {
F_4 ( L_2 ,
V_10 -> V_17 ) ;
V_7 -> V_16 = true ;
return false ;
}
return F_1 ( V_12 -> V_19 [ 0 ] , V_12 -> V_19 [ 1 ] , V_10 -> V_20 ,
! ! ( V_12 -> V_21 & V_22 ) ) ;
}
static int F_5 ( const struct V_23 * V_7 )
{
const struct V_11 * V_12 = V_7 -> V_13 ;
return ( V_12 -> V_21 & ~ V_24 ) ? - V_25 : 0 ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_26 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_26 ) ;
}
