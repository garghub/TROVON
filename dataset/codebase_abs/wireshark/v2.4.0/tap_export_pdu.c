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
V_8 . V_19 . V_20 = V_2 -> V_21 . V_20 ;
V_8 . V_19 . V_22 = V_2 -> V_21 . V_22 ;
V_8 . V_23 = V_11 ;
V_8 . V_24 = V_5 -> V_25 + V_5 -> V_14 ;
V_8 . V_26 = V_6 -> V_26 ;
if ( V_2 -> V_27 -> V_28 . V_29 ) {
V_8 . V_30 = F_5 ( F_6 ( V_3 -> V_31 , V_2 -> V_27 ) ) ;
V_8 . V_32 = TRUE ;
} else if ( V_2 -> V_27 -> V_28 . V_33 ) {
V_8 . V_30 = F_5 ( V_2 -> V_34 -> V_30 ) ;
}
V_8 . V_35 = V_36 | V_37 | V_38 | V_39 ;
if ( ! F_7 ( V_6 -> V_40 , & V_8 , V_12 , & V_9 , & V_10 ) ) {
switch ( V_9 ) {
case V_41 :
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
int
F_8 ( T_5 * V_6 , int V_27 , char * V_42 )
{
int V_9 ;
T_8 V_43 ;
T_9 * V_44 = F_9 ( FALSE , FALSE , sizeof( T_8 ) ) ;
T_10 * V_45 ;
T_8 V_46 ;
T_11 * V_47 ;
T_12 * V_48 ;
T_13 V_49 ;
T_6 * V_50 ;
V_48 = F_10 ( L_1 ) ;
F_11 ( V_48 ) ;
V_43 = F_12 ( V_51 ) ;
F_13 ( V_43 , V_52 , V_42 , strlen ( V_42 ) ) ;
F_3 ( V_42 ) ;
V_49 = V_48 -> V_24 ;
V_50 = F_14 ( V_48 , FALSE ) ;
if ( V_50 ) {
F_13 ( V_43 , V_53 , V_50 , V_49 ) ;
F_3 ( V_50 ) ;
}
F_15 ( V_43 , V_54 , L_2 , F_16 () ) ;
V_45 = F_17 ( T_10 , 1 ) ;
V_45 -> V_55 = F_9 ( FALSE , FALSE , sizeof( T_8 ) ) ;
V_46 = F_12 ( V_56 ) ;
V_47 = ( T_11 * ) F_18 ( V_46 ) ;
V_47 -> V_57 = V_58 ;
V_47 -> V_59 = 1000000000 ;
V_47 -> V_60 = V_61 ;
F_13 ( V_46 , V_62 , L_3 , strlen ( L_3 ) ) ;
F_19 ( V_46 , V_63 , 9 ) ;
F_20 ( V_45 -> V_55 , V_46 ) ;
F_20 ( V_44 , V_43 ) ;
V_6 -> V_40 = F_21 ( V_27 , V_64 , V_58 , V_61 , FALSE ,
V_44 , V_45 , NULL , & V_9 ) ;
if ( V_6 -> V_40 == NULL ) {
F_22 ( V_9 != 0 ) ;
return V_9 ;
}
return 0 ;
}
int
F_23 ( T_5 * V_6 )
{
int V_9 = 0 ;
if ( ! F_24 ( V_6 -> V_40 , & V_9 ) )
F_22 ( V_9 != 0 ) ;
F_25 ( V_6 ) ;
return V_9 ;
}
char *
F_26 ( const char * V_65 , const char * V_66 , T_5 * V_6 )
{
T_12 * V_67 ;
V_6 -> V_26 = F_27 ( V_58 ) ;
V_67 = F_28 ( V_65 ,
V_6 ,
V_66 ,
V_68 ,
NULL ,
F_1 ,
NULL ) ;
if ( V_67 != NULL )
return F_14 ( V_67 , FALSE ) ;
return NULL ;
}
