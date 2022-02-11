static inline bool
F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , bool V_4 )
{
bool V_5 ;
F_2 ( L_1 ,
V_4 ? '!' : ' ' , V_1 , V_3 , V_2 ) ;
V_5 = ( V_3 >= V_1 && V_3 <= V_2 ) ^ V_4 ;
F_2 ( L_2 , V_5 ? L_3 : L_4 ) ;
return V_5 ;
}
static bool F_3 ( const struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 V_11 ;
const struct V_10 * V_12 ;
const struct V_13 * V_14 = V_9 -> V_15 ;
if ( V_9 -> V_16 != 0 )
return false ;
V_12 = F_4 ( V_7 , V_9 -> V_17 , sizeof( V_11 ) , & V_11 ) ;
if ( V_12 == NULL ) {
F_2 ( L_5 ) ;
V_9 -> V_18 = true ;
return 0 ;
}
return F_1 ( V_14 -> V_19 [ 0 ] , V_14 -> V_19 [ 1 ] ,
F_5 ( V_12 -> V_20 << 16 ) ,
! ! ( V_14 -> V_21 & V_22 ) ) ;
}
static int F_6 ( const struct V_23 * V_9 )
{
const struct V_13 * V_14 = V_9 -> V_15 ;
if ( V_14 -> V_21 & ~ V_24 ) {
F_7 ( L_6 , V_14 -> V_21 ) ;
return - V_25 ;
}
return 0 ;
}
static int T_2 F_8 ( void )
{
return F_9 ( V_26 , F_10 ( V_26 ) ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( V_26 , F_10 ( V_26 ) ) ;
}
