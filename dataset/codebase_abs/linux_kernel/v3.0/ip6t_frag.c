static inline bool
F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , bool V_4 )
{
bool V_5 ;
F_2 ( L_1 , V_4 ? '!' : ' ' ,
V_1 , V_3 , V_2 ) ;
V_5 = ( V_3 >= V_1 && V_3 <= V_2 ) ^ V_4 ;
F_2 ( L_2 , V_5 ? L_3 : L_4 ) ;
return V_5 ;
}
static bool
F_3 ( const struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 V_11 ;
const struct V_10 * V_12 ;
const struct V_13 * V_14 = V_9 -> V_15 ;
unsigned int V_16 ;
int V_17 ;
V_17 = F_4 ( V_7 , & V_16 , V_18 , NULL ) ;
if ( V_17 < 0 ) {
if ( V_17 != - V_19 )
V_9 -> V_20 = true ;
return false ;
}
V_12 = F_5 ( V_7 , V_16 , sizeof( V_11 ) , & V_11 ) ;
if ( V_12 == NULL ) {
V_9 -> V_20 = true ;
return false ;
}
F_2 ( L_5 , V_12 -> V_21 ) ;
F_2 ( L_6 , F_6 ( V_12 -> V_21 ) & ~ 0x7 ) ;
F_2 ( L_7 , V_12 -> V_22 , F_6 ( V_12 -> V_21 ) & 0x6 ) ;
F_2 ( L_8 , V_12 -> V_21 & F_7 ( V_23 ) ) ;
F_2 ( L_9 , F_8 ( V_12 -> V_24 ) ,
F_8 ( V_12 -> V_24 ) ) ;
F_2 ( L_10 ,
F_1 ( V_14 -> V_25 [ 0 ] , V_14 -> V_25 [ 1 ] ,
F_8 ( V_12 -> V_24 ) ,
! ! ( V_14 -> V_26 & V_27 ) ) ) ;
F_2 ( L_11 ,
V_14 -> V_28 & V_29 , V_12 -> V_22 ,
F_6 ( V_12 -> V_21 ) & 0x6 ,
! ( ( V_14 -> V_28 & V_29 ) &&
( V_12 -> V_22 || ( F_6 ( V_12 -> V_21 ) & 0x06 ) ) ) ) ;
F_2 ( L_12 ,
V_14 -> V_28 & V_30 ,
F_6 ( V_12 -> V_21 ) & ~ 0x7 ,
! ( ( V_14 -> V_28 & V_30 ) &&
( F_6 ( V_12 -> V_21 ) & ~ 0x7 ) ) ) ;
F_2 ( L_13 ,
V_14 -> V_28 & V_31 ,
F_6 ( V_12 -> V_21 ) & V_23 ,
! ( ( V_14 -> V_28 & V_31 ) &&
! ( ( F_6 ( V_12 -> V_21 ) & V_23 ) ) ) ) ;
F_2 ( L_14 ,
V_14 -> V_28 & V_32 ,
F_6 ( V_12 -> V_21 ) & V_23 ,
! ( ( V_14 -> V_28 & V_32 ) &&
( F_6 ( V_12 -> V_21 ) & V_23 ) ) ) ;
return ( V_12 != NULL ) &&
F_1 ( V_14 -> V_25 [ 0 ] , V_14 -> V_25 [ 1 ] ,
F_8 ( V_12 -> V_24 ) ,
! ! ( V_14 -> V_26 & V_27 ) ) &&
! ( ( V_14 -> V_28 & V_29 ) &&
( V_12 -> V_22 || ( F_6 ( V_12 -> V_21 ) & 0x6 ) ) ) &&
! ( ( V_14 -> V_28 & V_30 ) &&
( F_6 ( V_12 -> V_21 ) & ~ 0x7 ) ) &&
! ( ( V_14 -> V_28 & V_31 ) &&
! ( F_6 ( V_12 -> V_21 ) & V_23 ) ) &&
! ( ( V_14 -> V_28 & V_32 ) &&
( F_6 ( V_12 -> V_21 ) & V_23 ) ) ;
}
static int F_9 ( const struct V_33 * V_9 )
{
const struct V_13 * V_14 = V_9 -> V_15 ;
if ( V_14 -> V_26 & ~ V_34 ) {
F_2 ( L_15 , V_14 -> V_26 ) ;
return - V_35 ;
}
return 0 ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_36 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_36 ) ;
}
