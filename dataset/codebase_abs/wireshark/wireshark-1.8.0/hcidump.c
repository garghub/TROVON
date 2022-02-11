static T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_4 * V_4 )
{
struct V_5 V_6 ;
T_5 * V_7 ;
int V_8 , V_9 ;
* V_4 = F_2 ( V_1 -> V_10 ) ;
V_8 = F_3 ( & V_6 , V_11 , V_1 -> V_10 ) ;
if ( V_8 != V_11 ) {
* V_2 = F_4 ( V_1 -> V_10 , V_3 ) ;
if ( * V_2 == 0 && V_8 != 0 )
* V_2 = V_12 ;
return FALSE ;
}
V_9 = F_5 ( V_6 . V_13 ) ;
if ( V_9 > V_14 ) {
* V_2 = V_15 ;
* V_3 = F_6 ( L_1 ,
V_9 , V_14 ) ;
return FALSE ;
}
F_7 ( V_1 -> V_16 , V_9 ) ;
V_7 = F_8 ( V_1 -> V_16 ) ;
V_8 = F_3 ( V_7 , V_9 , V_1 -> V_10 ) ;
if ( V_8 != V_9 ) {
* V_2 = F_4 ( V_1 -> V_10 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_12 ;
return FALSE ;
}
V_1 -> V_17 . V_18 = V_19 ;
V_1 -> V_17 . V_20 . V_21 = F_9 ( V_6 . V_22 ) ;
V_1 -> V_17 . V_20 . V_23 = F_9 ( V_6 . V_24 ) * 1000 ;
V_1 -> V_17 . V_25 = V_9 ;
V_1 -> V_17 . V_13 = V_9 ;
V_1 -> V_26 . V_27 . V_28 = ( V_6 . V_29 ? FALSE : TRUE ) ;
return TRUE ;
}
static T_1 F_10 ( T_2 * V_1 , T_4 V_30 ,
union V_31 * V_26 , T_5 * V_32 , int V_33 ,
int * V_2 , T_3 * * V_3 )
{
struct V_5 V_6 ;
int V_8 ;
if ( F_11 ( V_1 -> V_34 , V_30 , V_35 , V_2 ) == - 1 )
return FALSE ;
V_8 = F_3 ( & V_6 , V_11 , V_1 -> V_34 ) ;
if ( V_8 != V_11 ) {
* V_2 = F_4 ( V_1 -> V_34 , V_3 ) ;
if ( * V_2 == 0 && V_8 != 0 )
* V_2 = V_12 ;
return FALSE ;
}
V_8 = F_3 ( V_32 , V_33 , V_1 -> V_34 ) ;
if ( V_8 != V_33 ) {
* V_2 = F_4 ( V_1 -> V_34 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_12 ;
return FALSE ;
}
V_26 -> V_27 . V_28 = ( V_6 . V_29 ? FALSE : TRUE ) ;
return TRUE ;
}
int F_12 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
struct V_5 V_6 ;
T_5 type ;
int V_8 ;
V_8 = F_3 ( & V_6 , V_11 , V_1 -> V_10 ) ;
if ( V_8 != V_11 ) {
* V_2 = F_4 ( V_1 -> V_10 , V_3 ) ;
return ( * V_2 != 0 ) ? - 1 : 0 ;
}
if ( ( V_6 . V_29 != 0 && V_6 . V_29 != 1 ) || V_6 . V_36 != 0
|| F_5 ( V_6 . V_13 ) < 1 )
return 0 ;
V_8 = F_3 ( & type , 1 , V_1 -> V_10 ) ;
if ( V_8 != 1 ) {
* V_2 = F_4 ( V_1 -> V_10 , V_3 ) ;
return ( * V_2 != 0 ) ? - 1 : 0 ;
}
if ( type < 1 || type > 4 )
return 0 ;
if ( F_11 ( V_1 -> V_10 , 0 , V_35 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_39 = V_40 ;
V_1 -> V_41 = 0 ;
V_1 -> V_42 = F_1 ;
V_1 -> V_43 = F_10 ;
V_1 -> V_44 = V_45 ;
return 1 ;
}
