static T_1 F_1 ( T_2 V_1 , struct V_2 * V_3 ,
T_3 * V_4 , int * V_5 , T_4 * * V_6 )
{
struct V_7 V_8 ;
int V_9 ;
if ( ! F_2 ( V_1 , & V_8 , V_10 , V_5 , V_6 ) )
return FALSE ;
V_9 = F_3 ( V_8 . V_11 ) ;
if ( V_9 > V_12 ) {
* V_5 = V_13 ;
* V_6 = F_4 ( L_1 ,
V_9 , V_12 ) ;
return FALSE ;
}
V_3 -> V_14 = V_15 ;
V_3 -> V_16 = V_17 ;
V_3 -> V_18 . V_19 = F_5 ( V_8 . V_20 ) ;
V_3 -> V_18 . V_21 = F_5 ( V_8 . V_22 ) * 1000 ;
V_3 -> V_23 = V_9 ;
V_3 -> V_11 = V_9 ;
V_3 -> V_24 . V_25 . V_26 = ( V_8 . V_27 ? FALSE : TRUE ) ;
return F_6 ( V_1 , V_4 , V_9 , V_5 , V_6 ) ;
}
static T_1 F_7 ( T_5 * V_28 , int * V_5 , T_4 * * V_6 ,
T_6 * V_29 )
{
* V_29 = F_8 ( V_28 -> V_1 ) ;
return F_1 ( V_28 -> V_1 , & V_28 -> V_3 , V_28 -> V_30 ,
V_5 , V_6 ) ;
}
static T_1 F_9 ( T_5 * V_28 , T_6 V_31 ,
struct V_2 * V_3 , T_3 * V_4 , int * V_5 , T_4 * * V_6 )
{
if ( F_10 ( V_28 -> V_32 , V_31 , V_33 , V_5 ) == - 1 )
return FALSE ;
return F_1 ( V_28 -> V_32 , V_3 , V_4 , V_5 , V_6 ) ;
}
T_7 F_11 ( T_5 * V_28 , int * V_5 , T_4 * * V_6 )
{
struct V_7 V_8 ;
T_8 type ;
if ( ! F_12 ( V_28 -> V_1 , & V_8 , V_10 , V_5 , V_6 ) ) {
if ( * V_5 != V_34 )
return V_35 ;
return V_36 ;
}
if ( ( V_8 . V_27 != 0 && V_8 . V_27 != 1 ) || V_8 . V_37 != 0
|| F_3 ( V_8 . V_11 ) < 1 )
return V_36 ;
if ( ! F_12 ( V_28 -> V_1 , & type , 1 , V_5 , V_6 ) ) {
if ( * V_5 != V_34 )
return V_35 ;
return V_36 ;
}
if ( type < 1 || type > 4 )
return V_36 ;
if ( F_10 ( V_28 -> V_1 , 0 , V_33 , V_5 ) == - 1 )
return V_35 ;
V_28 -> V_38 = V_39 ;
V_28 -> V_40 = V_41 ;
V_28 -> V_42 = 0 ;
V_28 -> V_43 = F_7 ;
V_28 -> V_44 = F_9 ;
V_28 -> V_45 = V_46 ;
return V_47 ;
}
