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
T_2 V_25 ;
int V_26 ;
V_26 = F_6 ( V_2 , sizeof( V_10 ) , & V_24 , & V_25 ) ;
if ( V_26 == - 1 )
return false ;
if ( F_3 ( V_6 -> V_27 != V_24 , V_23 ) )
return false ;
if ( ! ( V_6 -> V_14 & ( V_28 |
V_29 | V_30 ) ) )
return true ;
V_12 = F_2 ( V_2 , V_26 , sizeof( V_13 ) ,
& V_13 ) ;
if ( V_12 == NULL )
return false ;
if ( V_6 -> V_14 & V_28 ) {
T_3 V_31 = F_7 ( V_12 -> V_32 . V_31 ) ;
if ( F_3 ( V_31 < V_6 -> V_33 [ 0 ] ||
V_31 > V_6 -> V_33 [ 1 ] , V_28 ) )
return false ;
}
if ( V_6 -> V_14 & V_29 ) {
T_3 V_34 = F_7 ( V_12 -> V_32 . V_34 ) ;
if ( F_3 ( V_34 < V_6 -> V_35 [ 0 ] ||
V_34 > V_6 -> V_35 [ 1 ] , V_29 ) )
return false ;
}
if ( ( V_6 -> V_14 & V_30 ) &&
F_3 ( V_12 -> V_36 . type < V_6 -> V_37 [ 0 ] ||
V_12 -> V_36 . type > V_6 -> V_37 [ 1 ] ||
V_12 -> V_36 . V_38 < V_6 -> V_39 [ 0 ] ||
V_12 -> V_36 . V_38 > V_6 -> V_39 [ 1 ] ,
V_30 ) )
return false ;
}
return true ;
}
static int F_8 ( const struct V_40 * V_4 )
{
const struct V_41 * V_42 = V_4 -> V_43 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_42 -> V_44 != F_9 ( V_45 ) || V_42 -> V_46 & V_47 )
return - V_48 ;
if ( V_6 -> V_14 & ~ V_49 || V_6 -> V_46 & ~ V_49 )
return - V_48 ;
if ( V_6 -> V_14 & ( V_28 | V_29 ) ) {
if ( V_6 -> V_46 & V_23 )
return - V_48 ;
if ( V_6 -> V_27 != V_50 &&
V_6 -> V_27 != V_51 &&
V_6 -> V_27 != V_52 &&
V_6 -> V_27 != V_53 &&
V_6 -> V_27 != V_54 )
return - V_48 ;
}
if ( V_6 -> V_14 & V_28 && V_6 -> V_33 [ 0 ] > V_6 -> V_33 [ 1 ] )
return - V_48 ;
if ( V_6 -> V_14 & V_29 && V_6 -> V_35 [ 0 ] > V_6 -> V_35 [ 1 ] )
return - V_48 ;
if ( V_6 -> V_14 & V_30 ) {
if ( ( V_6 -> V_46 & V_23 ) ||
V_6 -> V_27 != V_55 )
return - V_48 ;
if ( V_6 -> V_37 [ 0 ] > V_6 -> V_37 [ 1 ] ||
V_6 -> V_39 [ 0 ] > V_6 -> V_39 [ 1 ] )
return - V_48 ;
}
return 0 ;
}
static int T_4 F_10 ( void )
{
return F_11 ( & V_56 ) ;
}
static void T_5 F_12 ( void )
{
F_13 ( & V_56 ) ;
}
