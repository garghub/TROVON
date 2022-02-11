static T_1 F_1 ( T_2 * V_1 , T_3 V_2 , struct V_3 * V_4 ,
T_4 * V_5 , int * V_6 , T_5 * * V_7 )
{
struct V_8 V_9 ;
int V_10 ;
if ( ! F_2 ( V_2 , & V_9 , V_11 , V_6 , V_7 ) )
return FALSE ;
V_10 = F_3 ( V_9 . V_12 ) ;
if ( V_10 > V_13 ) {
* V_6 = V_14 ;
* V_7 = F_4 ( L_1 ,
V_10 , V_13 ) ;
return FALSE ;
}
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = V_1 -> V_18 ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 . V_22 = F_5 ( V_9 . V_23 ) ;
V_4 -> V_21 . V_24 = F_5 ( V_9 . V_25 ) * 1000 ;
V_4 -> V_26 = V_10 ;
V_4 -> V_12 = V_10 ;
V_4 -> V_27 . V_28 . V_29 = ( V_9 . V_30 ? FALSE : TRUE ) ;
return F_6 ( V_2 , V_5 , V_10 , V_6 , V_7 ) ;
}
static T_1 F_7 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 ,
T_6 * V_31 )
{
* V_31 = F_8 ( V_1 -> V_2 ) ;
return F_1 ( V_1 , V_1 -> V_2 , & V_1 -> V_4 , V_1 -> V_32 ,
V_6 , V_7 ) ;
}
static T_1 F_9 ( T_2 * V_1 , T_6 V_33 ,
struct V_3 * V_4 , T_4 * V_5 , int * V_6 , T_5 * * V_7 )
{
if ( F_10 ( V_1 -> V_34 , V_33 , V_35 , V_6 ) == - 1 )
return FALSE ;
return F_1 ( V_1 , V_1 -> V_34 , V_4 , V_5 , V_6 , V_7 ) ;
}
T_7 F_11 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 )
{
struct V_8 V_9 ;
T_8 type ;
if ( ! F_12 ( V_1 -> V_2 , & V_9 , V_11 , V_6 , V_7 ) ) {
if ( * V_6 != V_36 )
return V_37 ;
return V_38 ;
}
if ( ( V_9 . V_30 != 0 && V_9 . V_30 != 1 ) || V_9 . V_39 != 0
|| F_3 ( V_9 . V_12 ) < 1 )
return V_38 ;
if ( ! F_12 ( V_1 -> V_2 , & type , 1 , V_6 , V_7 ) ) {
if ( * V_6 != V_36 )
return V_37 ;
return V_38 ;
}
if ( type < 1 || type > 4 )
return V_38 ;
if ( F_10 ( V_1 -> V_2 , 0 , V_35 , V_6 ) == - 1 )
return V_37 ;
V_1 -> V_40 = V_41 ;
V_1 -> V_18 = V_42 ;
V_1 -> V_43 = 0 ;
V_1 -> V_44 = F_7 ;
V_1 -> V_45 = F_9 ;
V_1 -> V_46 = V_47 ;
return V_48 ;
}
