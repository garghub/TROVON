static T_1 F_1 ( T_2 V_1 , struct V_2 * V_3 ,
T_3 * V_4 , int * V_5 , T_4 * * V_6 )
{
struct V_7 V_8 ;
int V_9 , V_10 ;
V_9 = F_2 ( & V_8 , V_11 , V_1 ) ;
if ( V_9 != V_11 ) {
* V_5 = F_3 ( V_1 , V_6 ) ;
if ( * V_5 == 0 && V_9 != 0 )
* V_5 = V_12 ;
return FALSE ;
}
V_10 = F_4 ( V_8 . V_13 ) ;
if ( V_10 > V_14 ) {
* V_5 = V_15 ;
* V_6 = F_5 ( L_1 ,
V_10 , V_14 ) ;
return FALSE ;
}
V_3 -> V_16 = V_17 ;
V_3 -> V_18 . V_19 = F_6 ( V_8 . V_20 ) ;
V_3 -> V_18 . V_21 = F_6 ( V_8 . V_22 ) * 1000 ;
V_3 -> V_23 = V_10 ;
V_3 -> V_13 = V_10 ;
V_3 -> V_24 . V_25 . V_26 = ( V_8 . V_27 ? FALSE : TRUE ) ;
return F_7 ( V_1 , V_4 , V_10 , V_5 , V_6 ) ;
}
static T_1 F_8 ( T_5 * V_28 , int * V_5 , T_4 * * V_6 ,
T_6 * V_29 )
{
* V_29 = F_9 ( V_28 -> V_1 ) ;
return F_1 ( V_28 -> V_1 , & V_28 -> V_3 , V_28 -> V_30 ,
V_5 , V_6 ) ;
}
static T_1 F_10 ( T_5 * V_28 , T_6 V_31 ,
struct V_2 * V_3 , T_3 * V_4 , int T_7 V_32 ,
int * V_5 , T_4 * * V_6 )
{
if ( F_11 ( V_28 -> V_33 , V_31 , V_34 , V_5 ) == - 1 )
return FALSE ;
return F_1 ( V_28 -> V_33 , V_3 , V_4 , V_5 , V_6 ) ;
}
int F_12 ( T_5 * V_28 , int * V_5 , T_4 * * V_6 )
{
struct V_7 V_8 ;
T_8 type ;
int V_9 ;
V_9 = F_2 ( & V_8 , V_11 , V_28 -> V_1 ) ;
if ( V_9 != V_11 ) {
* V_5 = F_3 ( V_28 -> V_1 , V_6 ) ;
if ( * V_5 != 0 && * V_5 != V_12 )
return - 1 ;
return 0 ;
}
if ( ( V_8 . V_27 != 0 && V_8 . V_27 != 1 ) || V_8 . V_35 != 0
|| F_4 ( V_8 . V_13 ) < 1 )
return 0 ;
V_9 = F_2 ( & type , 1 , V_28 -> V_1 ) ;
if ( V_9 != 1 ) {
* V_5 = F_3 ( V_28 -> V_1 , V_6 ) ;
if ( * V_5 != 0 && * V_5 != V_12 )
return - 1 ;
return 0 ;
}
if ( type < 1 || type > 4 )
return 0 ;
if ( F_11 ( V_28 -> V_1 , 0 , V_34 , V_5 ) == - 1 )
return - 1 ;
V_28 -> V_36 = V_37 ;
V_28 -> V_38 = V_39 ;
V_28 -> V_40 = 0 ;
V_28 -> V_41 = F_8 ;
V_28 -> V_42 = F_10 ;
V_28 -> V_43 = V_44 ;
return 1 ;
}
