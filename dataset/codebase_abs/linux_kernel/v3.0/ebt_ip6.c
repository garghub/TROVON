static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
struct V_8 V_10 ;
const union V_11 * V_12 ;
union V_11 V_13 ;
V_9 = F_2 ( V_2 , 0 , sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL )
return false ;
if ( V_6 -> V_14 & V_15 &&
F_3 ( V_6 -> V_16 != F_4 ( V_9 ) , V_15 ) )
return false ;
if ( F_3 ( F_5 ( & V_9 -> V_17 , & V_6 -> V_18 ,
& V_6 -> V_17 ) , V_19 ) ||
F_3 ( F_5 ( & V_9 -> V_20 , & V_6 -> V_21 ,
& V_6 -> V_20 ) , V_22 ) )
return false ;
if ( V_6 -> V_14 & V_23 ) {
T_1 V_24 = V_9 -> V_24 ;
int V_25 ;
V_25 = F_6 ( V_2 , sizeof( V_10 ) , & V_24 ) ;
if ( V_25 == - 1 )
return false ;
if ( F_3 ( V_6 -> V_26 != V_24 , V_23 ) )
return false ;
if ( ! ( V_6 -> V_14 & ( V_27 |
V_28 | V_29 ) ) )
return true ;
V_12 = F_2 ( V_2 , V_25 , sizeof( V_13 ) ,
& V_13 ) ;
if ( V_12 == NULL )
return false ;
if ( V_6 -> V_14 & V_27 ) {
T_2 V_30 = F_7 ( V_12 -> V_31 . V_30 ) ;
if ( F_3 ( V_30 < V_6 -> V_32 [ 0 ] ||
V_30 > V_6 -> V_32 [ 1 ] , V_27 ) )
return false ;
}
if ( V_6 -> V_14 & V_28 ) {
T_2 V_33 = F_7 ( V_12 -> V_31 . V_33 ) ;
if ( F_3 ( V_33 < V_6 -> V_34 [ 0 ] ||
V_33 > V_6 -> V_34 [ 1 ] , V_28 ) )
return false ;
}
if ( ( V_6 -> V_14 & V_29 ) &&
F_3 ( V_12 -> V_35 . type < V_6 -> V_36 [ 0 ] ||
V_12 -> V_35 . type > V_6 -> V_36 [ 1 ] ||
V_12 -> V_35 . V_37 < V_6 -> V_38 [ 0 ] ||
V_12 -> V_35 . V_37 > V_6 -> V_38 [ 1 ] ,
V_29 ) )
return false ;
}
return true ;
}
static int F_8 ( const struct V_39 * V_4 )
{
const struct V_40 * V_41 = V_4 -> V_42 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_41 -> V_43 != F_9 ( V_44 ) || V_41 -> V_45 & V_46 )
return - V_47 ;
if ( V_6 -> V_14 & ~ V_48 || V_6 -> V_45 & ~ V_48 )
return - V_47 ;
if ( V_6 -> V_14 & ( V_27 | V_28 ) ) {
if ( V_6 -> V_45 & V_23 )
return - V_47 ;
if ( V_6 -> V_26 != V_49 &&
V_6 -> V_26 != V_50 &&
V_6 -> V_26 != V_51 &&
V_6 -> V_26 != V_52 &&
V_6 -> V_26 != V_53 )
return - V_47 ;
}
if ( V_6 -> V_14 & V_27 && V_6 -> V_32 [ 0 ] > V_6 -> V_32 [ 1 ] )
return - V_47 ;
if ( V_6 -> V_14 & V_28 && V_6 -> V_34 [ 0 ] > V_6 -> V_34 [ 1 ] )
return - V_47 ;
if ( V_6 -> V_14 & V_29 ) {
if ( ( V_6 -> V_45 & V_23 ) ||
V_6 -> V_26 != V_54 )
return - V_47 ;
if ( V_6 -> V_36 [ 0 ] > V_6 -> V_36 [ 1 ] ||
V_6 -> V_38 [ 0 ] > V_6 -> V_38 [ 1 ] )
return - V_47 ;
}
return 0 ;
}
static int T_3 F_10 ( void )
{
return F_11 ( & V_55 ) ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_55 ) ;
}
