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
unsigned int V_16 ;
unsigned int V_17 = 0 ;
int V_18 ;
V_18 = F_4 ( V_7 , & V_16 , V_19 , NULL ) ;
if ( V_18 < 0 ) {
if ( V_18 != - V_20 )
V_9 -> V_21 = true ;
return false ;
}
V_12 = F_5 ( V_7 , V_16 , sizeof( V_11 ) , & V_11 ) ;
if ( V_12 == NULL ) {
V_9 -> V_21 = true ;
return false ;
}
V_17 = ( V_12 -> V_17 + 2 ) << 2 ;
F_2 ( L_5 , V_17 , V_12 -> V_17 ) ;
F_2 ( L_6 , V_12 -> V_22 ) ;
F_2 ( L_7 , F_6 ( V_12 -> V_3 ) , F_6 ( V_12 -> V_3 ) ) ;
F_2 ( L_8 ,
F_1 ( V_14 -> V_23 [ 0 ] , V_14 -> V_23 [ 1 ] ,
F_6 ( V_12 -> V_3 ) ,
! ! ( V_14 -> V_24 & V_25 ) ) ) ;
F_2 ( L_9 ,
V_14 -> V_17 , V_17 ,
( ! V_14 -> V_17 ||
( V_14 -> V_17 == V_17 ) ^
! ! ( V_14 -> V_24 & V_26 ) ) ) ;
F_2 ( L_10 ,
V_14 -> V_27 , V_12 -> V_22 ,
! ( V_14 -> V_27 && V_12 -> V_22 ) ) ;
return ( V_12 != NULL ) &&
F_1 ( V_14 -> V_23 [ 0 ] , V_14 -> V_23 [ 1 ] ,
F_6 ( V_12 -> V_3 ) ,
! ! ( V_14 -> V_24 & V_25 ) ) &&
( ! V_14 -> V_17 ||
( V_14 -> V_17 == V_17 ) ^
! ! ( V_14 -> V_24 & V_26 ) ) &&
! ( V_14 -> V_27 && V_12 -> V_22 ) ;
}
static int F_7 ( const struct V_28 * V_9 )
{
const struct V_13 * V_14 = V_9 -> V_15 ;
if ( V_14 -> V_24 & ~ V_29 ) {
F_2 ( L_11 , V_14 -> V_24 ) ;
return - V_30 ;
}
return 0 ;
}
static int T_2 F_8 ( void )
{
return F_9 ( & V_31 ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_31 ) ;
}
