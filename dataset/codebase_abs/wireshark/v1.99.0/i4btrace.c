int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
T_4 V_5 = FALSE ;
T_5 * V_6 ;
V_7 = V_8 ;
if ( ! F_2 ( V_1 -> V_9 , & V_4 , sizeof( V_4 ) , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return - 1 ;
return 0 ;
}
if ( ! F_3 ( V_4 ) ) {
V_4 . V_11 = F_4 ( V_4 . V_11 ) ;
V_4 . V_12 = F_4 ( V_4 . V_12 ) ;
V_4 . type = F_4 ( V_4 . type ) ;
V_4 . V_13 = F_4 ( V_4 . V_13 ) ;
V_4 . V_14 = F_4 ( V_4 . V_14 ) ;
if ( ! F_3 ( V_4 ) ) {
return 0 ;
}
V_5 = TRUE ;
}
if ( F_5 ( V_1 -> V_9 , 0 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_16 = V_17 ;
V_6 = ( T_5 * ) F_6 ( sizeof( T_5 ) ) ;
V_1 -> V_18 = ( void * ) V_6 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_6 -> V_5 = V_5 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
return 1 ;
}
static T_4 V_20 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_28 )
{
* V_28 = F_7 ( V_1 -> V_9 ) ;
return F_8 ( V_1 , V_1 -> V_9 , & V_1 -> V_29 , V_1 -> V_30 ,
V_2 , V_3 ) ;
}
static T_4
V_22 ( T_1 * V_1 , T_6 V_31 , struct V_32 * V_29 ,
T_7 * V_33 , int * V_2 , T_2 * * V_3 )
{
if ( F_5 ( V_1 -> V_34 , V_31 , V_15 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 , V_1 -> V_34 , V_29 , V_33 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_10 ;
}
return FALSE ;
}
return TRUE ;
}
static T_4
F_8 ( T_1 * V_1 , T_8 V_9 , struct V_32 * V_29 , T_7 * V_33 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_6 = ( T_5 * ) V_1 -> V_18 ;
T_3 V_4 ;
T_9 V_11 ;
V_7 = V_8 ;
if ( ! F_9 ( V_9 , & V_4 , sizeof V_4 , V_2 , V_3 ) )
return FALSE ;
if ( V_6 -> V_5 ) {
V_4 . V_11 = F_4 ( V_4 . V_11 ) ;
V_4 . V_12 = F_4 ( V_4 . V_12 ) ;
V_4 . type = F_4 ( V_4 . type ) ;
V_4 . V_13 = F_4 ( V_4 . V_13 ) ;
V_4 . V_14 = F_4 ( V_4 . V_14 ) ;
V_4 . V_35 = F_4 ( V_4 . V_35 ) ;
V_4 . V_36 = F_4 ( V_4 . V_36 ) ;
V_4 . V_37 = F_4 ( V_4 . V_37 ) ;
}
if ( V_4 . V_11 < sizeof( V_4 ) ) {
* V_2 = V_38 ;
* V_3 = F_10 ( L_1 ,
V_4 . V_11 , ( unsigned long ) sizeof( V_4 ) ) ;
return FALSE ;
}
V_11 = V_4 . V_11 - ( T_9 ) sizeof( V_4 ) ;
if ( V_11 > V_39 ) {
* V_2 = V_38 ;
* V_3 = F_10 ( L_2 ,
V_11 , V_39 ) ;
return FALSE ;
}
V_29 -> V_40 = V_41 ;
V_29 -> V_42 = V_43 ;
V_29 -> V_44 = V_11 ;
V_29 -> V_45 = V_11 ;
V_29 -> V_46 . V_47 = V_4 . V_36 ;
V_29 -> V_46 . V_48 = V_4 . V_37 * 1000 ;
switch ( V_4 . type ) {
case V_49 :
V_29 -> V_50 = V_51 ;
break;
case V_52 :
V_29 -> V_50 = V_25 ;
V_29 -> V_53 . V_54 . V_55 = 0 ;
break;
case V_56 :
V_29 -> V_50 = V_25 ;
V_29 -> V_53 . V_54 . V_55 = 1 ;
break;
case V_57 :
V_29 -> V_50 = V_25 ;
V_29 -> V_53 . V_54 . V_55 = 2 ;
break;
}
V_29 -> V_53 . V_54 . V_58 = ( V_4 . V_13 == V_59 ) ;
return F_11 ( V_9 , V_33 , V_11 , V_2 , V_3 ) ;
}
