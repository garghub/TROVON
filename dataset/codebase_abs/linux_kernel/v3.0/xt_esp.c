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
const struct V_10 * V_11 ;
struct V_10 V_12 ;
const struct V_13 * V_14 = V_9 -> V_15 ;
if ( V_9 -> V_16 != 0 )
return false ;
V_11 = F_4 ( V_7 , V_9 -> V_17 , sizeof( V_12 ) , & V_12 ) ;
if ( V_11 == NULL ) {
F_2 ( L_5 ) ;
V_9 -> V_18 = true ;
return false ;
}
return F_1 ( V_14 -> V_19 [ 0 ] , V_14 -> V_19 [ 1 ] , F_5 ( V_11 -> V_3 ) ,
! ! ( V_14 -> V_20 & V_21 ) ) ;
}
static int F_6 ( const struct V_22 * V_9 )
{
const struct V_13 * V_14 = V_9 -> V_15 ;
if ( V_14 -> V_20 & ~ V_23 ) {
F_2 ( L_6 , V_14 -> V_20 ) ;
return - V_24 ;
}
return 0 ;
}
static int T_2 F_7 ( void )
{
return F_8 ( V_25 , F_9 ( V_25 ) ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( V_25 , F_9 ( V_25 ) ) ;
}
