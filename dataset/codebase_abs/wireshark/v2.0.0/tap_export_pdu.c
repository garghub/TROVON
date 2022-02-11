static T_1
F_1 ( void * V_1 , T_2 * V_2 , T_3 * V_3 , const void * V_4 )
{
const T_4 * V_5 = ( const T_4 * ) V_4 ;
T_5 * V_6 = ( T_5 * ) V_1 ;
struct V_7 V_8 ;
int V_9 ;
T_6 * V_10 ;
int V_11 ;
T_7 * V_12 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_11 = V_5 -> V_13 + V_5 -> V_14 ;
V_12 = ( T_7 * ) F_2 ( V_11 ) ;
if( V_5 -> V_14 > 0 ) {
memcpy ( V_12 , V_5 -> V_15 , V_5 -> V_14 ) ;
F_3 ( V_5 -> V_15 ) ;
}
if( V_5 -> V_13 > 0 ) {
F_4 ( V_5 -> V_16 , V_12 + V_5 -> V_14 , 0 , V_5 -> V_13 ) ;
}
V_8 . V_17 = V_18 ;
V_8 . V_19 . V_20 = V_2 -> V_21 -> V_22 . V_20 ;
V_8 . V_19 . V_23 = V_2 -> V_21 -> V_22 . V_23 ;
V_8 . V_24 = V_11 ;
V_8 . V_25 = V_5 -> V_26 + V_5 -> V_14 ;
V_8 . V_27 = V_6 -> V_27 ;
if ( V_2 -> V_21 -> V_28 . V_29 )
V_8 . V_30 = F_5 ( F_6 ( V_3 -> V_31 , V_2 -> V_21 ) ) ;
else if ( V_2 -> V_21 -> V_28 . V_32 )
V_8 . V_30 = F_5 ( V_2 -> V_33 -> V_30 ) ;
V_8 . V_34 = V_35 | V_36 | V_37 | V_38 ;
if ( ! F_7 ( V_6 -> V_39 , & V_8 , V_12 , & V_9 , & V_10 ) ) {
switch ( V_9 ) {
case V_40 :
F_3 ( V_10 ) ;
break;
default:
break;
}
}
F_3 ( V_12 ) ;
F_3 ( V_8 . V_30 ) ;
return FALSE ;
}
static void
F_8 ( T_5 * V_6 )
{
char * V_41 , * V_42 ;
int V_9 ;
T_8 * V_43 ;
T_9 * V_44 ;
T_10 V_45 ;
T_11 * V_46 ;
V_46 = F_9 ( L_1 ) ;
F_10 ( V_46 ) ;
V_43 = F_11 ( T_8 , 1 ) ;
V_43 -> V_47 = - 1 ;
V_43 -> V_30 = F_12 ( L_2 , V_48 . V_49 ) ;
V_43 -> V_50 = NULL ;
V_43 -> V_51 = F_13 ( V_46 , FALSE ) ;
V_43 -> V_52 = F_12 ( L_3 , F_14 () ) ;
V_44 = F_15 ( T_9 , 1 ) ;
V_44 -> V_53 = F_16 ( FALSE , FALSE , sizeof( T_10 ) ) ;
V_45 . V_54 = V_55 ;
V_45 . V_56 = 1000000000 ;
V_45 . V_57 = F_17 ( V_55 ) ;
V_45 . V_58 = V_59 ;
V_45 . V_60 = F_5 ( L_4 ) ;
V_45 . V_30 = NULL ;
V_45 . V_61 = NULL ;
V_45 . V_62 = 0 ;
V_45 . V_63 = 9 ;
V_45 . V_64 = NULL ;
V_45 . V_65 = 0 ;
V_45 . V_66 = NULL ;
V_45 . V_67 = NULL ;
V_45 . V_68 = - 1 ;
V_45 . V_69 = 0 ;
V_45 . V_70 = NULL ;
F_18 ( V_44 -> V_53 , V_45 ) ;
V_6 -> V_39 = F_19 ( & V_41 , L_5 ,
V_71 ,
V_55 , V_59 ,
FALSE , V_43 , V_44 , NULL , & V_9 ) ;
V_42 = F_5 ( V_41 ) ;
if ( V_6 -> V_39 == NULL ) {
F_20 ( V_42 ? V_42 : L_6 , V_9 , TRUE ) ;
goto V_72;
}
F_21 ( & V_48 ) ;
if ( ! F_22 ( V_6 -> V_39 , & V_9 ) ) {
F_23 ( V_42 , V_9 ) ;
}
F_24 ( V_6 ) ;
if ( F_25 ( & V_48 , V_42 , V_73 , TRUE , & V_9 ) != V_74 ) {
F_20 ( V_42 , V_9 , FALSE ) ;
goto V_72;
}
switch ( F_26 ( & V_48 , FALSE ) ) {
case V_75 :
case V_76 :
break;
case V_77 :
break;
}
V_72:
F_3 ( V_42 ) ;
F_27 ( V_43 ) ;
F_28 ( V_44 ) ;
}
T_1
F_29 ( const char * V_78 , T_6 * V_79 , T_5 * V_6 )
{
T_11 * V_80 ;
V_80 = F_30 ( V_79 ,
V_6 ,
V_78 ,
V_81 ,
NULL ,
F_1 ,
NULL ) ;
if ( V_80 ) {
F_31 ( V_82 , V_83 , L_7 , V_80 -> V_84 ) ;
F_13 ( V_80 , TRUE ) ;
return FALSE ;
}
F_8 ( V_6 ) ;
return TRUE ;
}
