int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
T_4 V_6 = FALSE ;
T_5 * V_7 ;
V_8 = V_9 ;
V_4 = F_2 ( & V_5 , sizeof( V_5 ) , V_1 -> V_10 ) ;
if ( V_4 != sizeof( V_5 ) ) {
* V_2 = F_3 ( V_1 -> V_10 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_11 )
return - 1 ;
return 0 ;
}
if ( ! F_4 ( V_5 ) ) {
V_5 . V_12 = F_5 ( V_5 . V_12 ) ;
V_5 . V_13 = F_5 ( V_5 . V_13 ) ;
V_5 . type = F_5 ( V_5 . type ) ;
V_5 . V_14 = F_5 ( V_5 . V_14 ) ;
V_5 . V_15 = F_5 ( V_5 . V_15 ) ;
if ( ! F_4 ( V_5 ) ) {
return 0 ;
}
V_6 = TRUE ;
}
if ( F_6 ( V_1 -> V_10 , 0 , V_16 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_17 = V_18 ;
V_7 = ( T_5 * ) F_7 ( sizeof( T_5 ) ) ;
V_1 -> V_19 = ( void * ) V_7 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = 0 ;
V_7 -> V_6 = V_6 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
return 1 ;
}
static T_4 V_21 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_29 )
{
* V_29 = F_8 ( V_1 -> V_10 ) ;
return F_9 ( V_1 , V_1 -> V_10 , & V_1 -> V_30 , V_1 -> V_31 ,
V_2 , V_3 ) ;
}
static T_4
V_23 ( T_1 * V_1 , T_6 V_32 , struct V_33 * V_30 ,
T_7 * V_34 , int V_12 V_35 , int * V_2 , T_2 * * V_3 )
{
if ( F_6 ( V_1 -> V_36 , V_32 , V_16 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_9 ( V_1 , V_1 -> V_36 , V_30 , V_34 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_11 ;
}
return FALSE ;
}
return TRUE ;
}
static int
F_9 ( T_1 * V_1 , T_8 V_10 , struct V_33 * V_30 , T_7 * V_34 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_7 = ( T_5 * ) V_1 -> V_19 ;
T_3 V_5 ;
int V_4 ;
T_9 V_12 ;
V_8 = V_9 ;
V_4 = F_2 ( & V_5 , sizeof V_5 , V_10 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_3 ( V_10 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_11 ;
}
return FALSE ;
}
if ( V_7 -> V_6 ) {
V_5 . V_12 = F_5 ( V_5 . V_12 ) ;
V_5 . V_13 = F_5 ( V_5 . V_13 ) ;
V_5 . type = F_5 ( V_5 . type ) ;
V_5 . V_14 = F_5 ( V_5 . V_14 ) ;
V_5 . V_15 = F_5 ( V_5 . V_15 ) ;
V_5 . V_37 = F_5 ( V_5 . V_37 ) ;
V_5 . V_38 = F_5 ( V_5 . V_38 ) ;
V_5 . V_39 = F_5 ( V_5 . V_39 ) ;
}
if ( V_5 . V_12 < sizeof( V_5 ) ) {
* V_2 = V_40 ;
* V_3 = F_10 ( L_1 ,
V_5 . V_12 , ( unsigned long ) sizeof( V_5 ) ) ;
return FALSE ;
}
V_12 = V_5 . V_12 - ( T_9 ) sizeof( V_5 ) ;
if ( V_12 > V_41 ) {
* V_2 = V_40 ;
* V_3 = F_10 ( L_2 ,
V_12 , V_41 ) ;
return FALSE ;
}
V_30 -> V_42 = V_43 ;
V_30 -> V_44 = V_12 ;
V_30 -> V_45 = V_12 ;
V_30 -> V_46 . V_47 = V_5 . V_38 ;
V_30 -> V_46 . V_48 = V_5 . V_39 * 1000 ;
switch ( V_5 . type ) {
case V_49 :
V_30 -> V_50 = V_51 ;
break;
case V_52 :
V_30 -> V_50 = V_26 ;
V_30 -> V_53 . V_54 . V_55 = 0 ;
break;
case V_56 :
V_30 -> V_50 = V_26 ;
V_30 -> V_53 . V_54 . V_55 = 1 ;
break;
case V_57 :
V_30 -> V_50 = V_26 ;
V_30 -> V_53 . V_54 . V_55 = 2 ;
break;
}
V_30 -> V_53 . V_54 . V_58 = ( V_5 . V_14 == V_59 ) ;
return F_11 ( V_10 , V_34 , V_12 , V_2 , V_3 ) ;
}
