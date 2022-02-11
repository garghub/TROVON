static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
struct V_8 V_10 ;
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_9 = F_2 ( V_2 , 0 , sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL )
return false ;
if ( ( V_6 -> V_14 & V_15 ) &&
F_3 ( V_6 , V_15 , V_6 -> V_16 != V_9 -> V_16 ) )
return false ;
if ( ( V_6 -> V_14 & V_17 ) &&
F_3 ( V_6 , V_17 ,
( V_9 -> V_18 & V_6 -> V_19 ) != V_6 -> V_18 ) )
return false ;
if ( ( V_6 -> V_14 & V_20 ) &&
F_3 ( V_6 , V_20 ,
( V_9 -> V_21 & V_6 -> V_22 ) != V_6 -> V_21 ) )
return false ;
if ( V_6 -> V_14 & V_23 ) {
if ( F_3 ( V_6 , V_23 , V_6 -> V_24 != V_9 -> V_24 ) )
return false ;
if ( ! ( V_6 -> V_14 & V_25 ) &&
! ( V_6 -> V_14 & V_26 ) )
return true ;
if ( F_4 ( V_9 -> V_27 ) & V_28 )
return false ;
V_12 = F_2 ( V_2 , V_9 -> V_29 * 4 ,
sizeof( V_13 ) , & V_13 ) ;
if ( V_12 == NULL )
return false ;
if ( V_6 -> V_14 & V_25 ) {
T_1 V_30 = F_4 ( V_12 -> V_30 ) ;
if ( F_3 ( V_6 , V_25 ,
V_30 < V_6 -> V_31 [ 0 ] ||
V_30 > V_6 -> V_31 [ 1 ] ) )
return false ;
}
if ( V_6 -> V_14 & V_26 ) {
T_1 V_32 = F_4 ( V_12 -> V_32 ) ;
if ( F_3 ( V_6 , V_26 ,
V_32 < V_6 -> V_33 [ 0 ] ||
V_32 > V_6 -> V_33 [ 1 ] ) )
return false ;
}
}
return true ;
}
static int F_5 ( const struct V_34 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_35 * V_36 = V_4 -> V_37 ;
if ( V_36 -> V_38 != F_6 ( V_39 ) ||
V_36 -> V_40 & V_41 )
return - V_42 ;
if ( V_6 -> V_14 & ~ V_43 || V_6 -> V_40 & ~ V_43 )
return - V_42 ;
if ( V_6 -> V_14 & ( V_25 | V_26 ) ) {
if ( V_6 -> V_40 & V_23 )
return - V_42 ;
if ( V_6 -> V_24 != V_44 &&
V_6 -> V_24 != V_45 &&
V_6 -> V_24 != V_46 &&
V_6 -> V_24 != V_47 &&
V_6 -> V_24 != V_48 )
return - V_42 ;
}
if ( V_6 -> V_14 & V_25 && V_6 -> V_31 [ 0 ] > V_6 -> V_31 [ 1 ] )
return - V_42 ;
if ( V_6 -> V_14 & V_26 && V_6 -> V_33 [ 0 ] > V_6 -> V_33 [ 1 ] )
return - V_42 ;
return 0 ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_49 ) ;
}
static void T_3 F_9 ( void )
{
F_10 ( & V_49 ) ;
}
