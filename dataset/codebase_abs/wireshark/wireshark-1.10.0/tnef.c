static T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_4 * V_4 )
{
T_4 V_5 ;
T_5 * V_6 ;
T_4 V_7 ;
int V_8 ;
* V_2 = 0 ;
V_5 = F_2 ( V_1 -> V_9 ) ;
if ( V_5 )
return FALSE ;
* V_4 = V_5 ;
if ( ( V_7 = F_3 ( V_1 , V_2 ) ) == - 1 )
return FALSE ;
if ( V_7 > V_10 ) {
* V_2 = V_11 ;
* V_3 = F_4 ( L_1 V_12 L_2 ,
V_7 , V_10 ) ;
return FALSE ;
}
V_8 = ( int ) V_7 ;
F_5 ( V_1 -> V_13 , V_8 ) ;
V_6 = F_6 ( V_1 -> V_13 ) ;
F_7 ( V_6 , V_8 , V_1 -> V_9 , V_2 , V_3 ) ;
V_1 -> V_14 . V_15 = 0 ;
V_1 -> V_14 . V_16 = V_8 ;
V_1 -> V_14 . V_17 = V_8 ;
V_1 -> V_14 . V_18 . V_19 = 0 ;
V_1 -> V_14 . V_18 . V_20 = 0 ;
return TRUE ;
}
static T_1 F_8 ( T_2 * V_1 , T_4 V_21 ,
struct V_22 * V_14 V_23 ,
T_5 * V_24 , int V_25 , int * V_2 , T_3 * * V_3 )
{
int V_8 = V_25 ;
if( V_21 > 0 ) {
* V_2 = 0 ;
return FALSE ;
}
if ( F_9 ( V_1 -> V_26 , V_21 , V_27 , V_2 ) == - 1 )
return FALSE ;
F_7 ( V_24 , V_8 , V_1 -> V_26 , V_2 , V_3 ) ;
return TRUE ;
}
int F_10 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
int V_28 ;
T_6 V_29 ;
V_28 = F_11 ( & V_29 , sizeof V_29 , V_1 -> V_9 ) ;
if ( V_28 != sizeof V_29 ) {
* V_2 = F_12 ( V_1 -> V_9 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_30 )
return - 1 ;
return 0 ;
}
if ( F_13 ( V_29 ) != V_31 )
return 0 ;
if ( F_9 ( V_1 -> V_9 , 0 , V_27 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_32 = V_33 ;
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = 0 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_38 = F_8 ;
V_1 -> V_39 = V_40 ;
return 1 ;
}
