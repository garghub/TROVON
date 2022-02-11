void
F_1 ( T_1 * V_1 , const char * V_2 ,
T_2 V_3 )
{
T_3 * V_4 ;
T_3 * V_5 ;
const T_3 * V_6 = NULL ;
T_4 V_7 ;
T_5 V_8 ;
V_5 = F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < strlen ( V_4 ) ; V_8 ++ ) {
if ( V_4 [ V_8 ] == '/' ) {
V_4 [ V_8 ] = '#' ;
}
}
V_7 . V_3 = V_3 ;
V_7 . V_9 = V_5 ;
V_7 . V_10 = V_1 -> V_11 ;
V_7 . V_12 = V_1 -> V_12 ;
V_7 . V_13 = V_1 -> V_13 ;
V_7 . V_14 = V_1 -> V_14 ;
F_4 ( & V_7 , NULL ) ;
switch ( V_3 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
break;
case V_19 :
V_6 = V_20 ;
break;
case V_21 :
V_6 = V_22 ;
break;
case V_23 :
V_6 = V_24 ;
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
break;
case V_31 :
break;
}
F_5 (
F_6 ( V_3 ) ,
V_4 ,
V_6 ,
V_5 ,
NULL ,
NULL ,
V_32 ,
V_1 ,
TRUE ,
NULL ,
NULL ) ;
}
void F_7 ( void )
{
T_6 * V_33 = V_34 ;
char * V_35 ;
char * V_9 ;
while( V_33 != NULL ) {
if( V_33 -> V_36 ) {
V_35 = F_8 ( & V_37 ) ;
V_9 = F_2 ( L_2 , V_33 -> V_38 . V_39 , V_35 ) ;
F_9 ( V_35 ) ;
F_10 ( F_11 ( V_33 -> V_36 ) , V_9 ) ;
F_9 ( V_9 ) ;
}
V_33 = V_33 -> V_40 ;
}
}
static void
F_12 ( T_7 * T_8 V_41 , T_9 V_42 )
{
T_6 * V_43 = ( T_6 * ) V_42 ;
V_43 -> V_36 = NULL ;
}
static void
F_13 ( T_7 * T_8 V_41 , T_9 V_42 )
{
T_10 * V_14 ;
T_5 V_8 ;
T_11 V_44 ;
T_12 V_45 ;
T_6 * V_43 = ( T_6 * ) V_42 ;
V_14 = F_14 ( V_43 -> V_38 . V_11 ) ;
for( V_8 = 0 ; V_8 < V_43 -> V_38 . V_13 ; V_8 ++ ) {
F_15 ( V_14 , ',' ) ;
switch ( V_43 -> V_38 . V_14 [ V_8 ] . type ) {
case V_46 :
V_45 = F_16 ( F_17 ( V_43 -> V_47 [ V_8 ] ) ) ;
F_18 ( V_14 , L_3 ,
V_43 -> V_38 . V_14 [ V_8 ] . V_48 [ V_45 ] . V_49 ) ;
break;
case V_50 :
V_44 = F_19 ( F_20 ( V_43 -> V_47 [ V_8 ] ) ) ;
F_18 ( V_14 , L_4 , ( V_51 ) V_44 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
F_21 ( V_14 ,
F_22 ( F_23 ( V_43 -> V_47 [ V_8 ] ) ) ) ;
break;
}
}
( V_43 -> V_38 . V_12 ) ( V_14 -> V_55 , V_43 -> V_38 . V_56 ) ;
F_24 ( V_14 , TRUE ) ;
}
void
V_32 ( T_13 * T_14 V_41 , T_9 V_57 )
{
const char * V_58 ;
char * V_35 ;
char * V_9 ;
T_7 * V_59 ;
T_7 * V_60 , * T_8 , * V_61 , * V_62 ;
T_7 * V_63 , * V_64 , * V_65 ;
T_5 V_8 , V_45 ;
char * V_66 ;
T_1 * V_43 = ( T_1 * ) V_57 ;
if( V_43 == NULL )
return;
if( V_43 -> V_67 == - 1 ) {
if( V_34 == NULL ) {
V_34 = ( T_6 * ) F_25 ( sizeof ( T_6 ) ) ;
V_68 = V_34 ;
V_68 -> V_38 . V_67 = 0 ;
} else {
V_68 -> V_40 = ( T_6 * ) F_25 ( sizeof ( T_6 ) ) ;
V_68 -> V_40 -> V_38 . V_67 = V_68 -> V_38 . V_67 + 1 ;
V_68 = V_68 -> V_40 ;
}
V_68 -> V_36 = NULL ;
V_68 -> V_47 = ( T_7 * * ) F_25 ( V_43 -> V_13 * sizeof ( T_7 * ) ) ;
V_68 -> V_38 . V_39 = V_43 -> V_39 ;
V_68 -> V_38 . V_11 = V_43 -> V_11 ;
V_68 -> V_38 . V_12 = V_43 -> V_12 ;
V_68 -> V_38 . V_13 = V_43 -> V_13 ;
V_68 -> V_38 . V_14 = V_43 -> V_14 ;
V_68 -> V_38 . V_56 = V_43 -> V_56 ;
V_68 -> args . V_9 = F_2 ( L_5 , V_43 -> V_39 ) ;
V_68 -> args . V_69 = TRUE ;
V_68 -> args . V_70 = FALSE ;
V_68 -> args . V_71 = FALSE ;
V_68 -> V_40 = NULL ;
V_43 -> V_67 = V_68 -> V_38 . V_67 ;
V_72 = V_68 ;
} else {
V_72 = V_34 ;
while( V_43 -> V_67 != V_72 -> V_38 . V_67 )
{
if( V_72 -> V_40 == NULL ) {
return;
}
V_72 = V_72 -> V_40 ;
}
}
if( V_72 -> V_36 ) {
F_26 ( F_27 ( V_72 -> V_36 ) ) ;
return;
}
if ( V_72 -> V_38 . V_13 == 0 )
{
F_13 ( NULL , V_72 ) ;
return;
}
V_35 = F_8 ( & V_37 ) ;
V_9 = F_2 ( L_2 , V_72 -> V_38 . V_39 , V_35 ) ;
F_9 ( V_35 ) ;
V_72 -> V_36 = F_28 ( V_9 , V_72 -> V_38 . V_39 , V_73 ) ;
F_29 ( F_11 ( V_72 -> V_36 ) , 300 , - 1 ) ;
F_9 ( V_9 ) ;
V_59 = F_30 ( V_74 , 10 , FALSE ) ;
F_31 ( F_32 ( V_59 ) , 10 ) ;
F_33 ( F_32 ( V_72 -> V_36 ) , V_59 ) ;
F_34 ( V_59 ) ;
for( V_8 = 0 ; V_8 < V_72 -> V_38 . V_13 ; V_8 ++ ) {
V_60 = F_30 ( V_75 , 3 , FALSE ) ;
switch ( V_72 -> V_38 . V_14 [ V_8 ] . type ) {
case V_50 :
V_66 = F_2 ( L_6 , V_72 -> V_38 . V_14 [ V_8 ] . V_9 ) ;
V_61 = F_35 ( V_66 ) ;
F_9 ( V_66 ) ;
F_36 ( F_37 ( V_60 ) , V_61 , FALSE , TRUE , 0 ) ;
F_34 ( V_61 ) ;
T_8 = F_38 ( 0 , V_76 , 1 ) ;
F_39 ( F_20 ( T_8 ) , TRUE ) ;
break;
case V_52 :
V_66 = F_2 ( L_6 , V_72 -> V_38 . V_14 [ V_8 ] . V_9 ) ;
V_61 = F_35 ( V_66 ) ;
F_9 ( V_66 ) ;
F_36 ( F_37 ( V_60 ) , V_61 , FALSE , TRUE , 0 ) ;
F_34 ( V_61 ) ;
T_8 = F_40 () ;
break;
case V_46 :
V_66 = F_2 ( L_6 , V_72 -> V_38 . V_14 [ V_8 ] . V_9 ) ;
V_61 = F_35 ( V_66 ) ;
F_9 ( V_66 ) ;
F_36 ( F_37 ( V_60 ) , V_61 , FALSE , TRUE , 0 ) ;
F_34 ( V_61 ) ;
T_8 = F_41 () ;
for ( V_45 = 0 ; V_72 -> V_38 . V_14 [ V_8 ] . V_48 [ V_45 ] . V_2 != NULL ;
V_45 ++ )
F_42 ( F_43 ( T_8 ) ,
V_72 -> V_38 . V_14 [ V_8 ] . V_48 [ V_45 ] . V_77 ) ;
F_44 ( F_17 ( T_8 ) , 0 ) ;
break;
case V_54 :
V_62 = F_45 ( V_78 ) ;
F_46 ( V_62 , L_7 , F_47 ( V_79 ) , & ( V_72 -> args ) ) ;
F_36 ( F_37 ( V_60 ) , V_62 , FALSE , TRUE , 0 ) ;
F_34 ( V_62 ) ;
T_8 = F_40 () ;
F_46 ( T_8 , L_8 , F_47 ( V_80 ) , NULL ) ;
F_48 ( F_49 ( V_60 ) , V_81 , NULL ) ;
F_46 ( T_8 , L_9 , F_47 ( V_82 ) , NULL ) ;
F_46 ( V_72 -> V_36 , L_9 , F_47 ( V_83 ) , NULL ) ;
F_48 ( F_49 ( V_62 ) , V_84 , T_8 ) ;
V_58 = F_22 ( F_23 ( V_85 ) ) ;
if( V_58 ) {
F_50 ( F_23 ( T_8 ) , V_58 ) ;
} else {
F_51 ( T_8 ) ;
}
break;
default:
F_52 () ;
T_8 = NULL ;
break;
}
F_36 ( F_37 ( V_60 ) , T_8 , TRUE , TRUE , 0 ) ;
V_72 -> V_47 [ V_8 ] = T_8 ;
F_34 ( T_8 ) ;
F_36 ( F_37 ( V_59 ) , V_60 , TRUE , TRUE , 0 ) ;
F_34 ( V_60 ) ;
}
V_63 = F_53 ( V_86 , V_87 , NULL ) ;
F_36 ( F_37 ( V_59 ) , V_63 , FALSE , FALSE , 0 ) ;
F_34 ( V_63 ) ;
V_64 = ( T_7 * ) F_54 ( F_49 ( V_63 ) , V_86 ) ;
F_46 ( V_64 , L_7 ,
F_47 ( F_13 ) , V_72 ) ;
V_65 = ( T_7 * ) F_54 ( F_49 ( V_63 ) , V_87 ) ;
F_55 ( V_72 -> V_36 , V_65 , V_88 ) ;
for( V_8 = 0 ; V_8 < V_72 -> V_38 . V_13 ; V_8 ++ ) {
switch ( V_72 -> V_38 . V_14 [ V_8 ] . type ) {
case V_50 :
case V_46 :
break;
case V_52 :
case V_54 :
case V_53 :
F_56 ( V_72 -> V_47 [ V_8 ] , V_64 ) ;
break;
}
}
if( V_72 -> V_38 . V_13 > 0 ) {
F_57 ( V_72 -> V_47 [ 0 ] ) ;
}
F_58 ( V_64 ) ;
F_46 ( V_72 -> V_36 , L_10 , F_47 ( V_89 ) , NULL ) ;
F_46 ( V_72 -> V_36 , L_11 , F_47 ( F_12 ) , V_72 ) ;
F_59 ( V_72 -> V_36 ) ;
F_60 ( V_72 -> V_36 ) ;
}
