static void F_1 ( void )
{
F_2 () ;
F_3 () ;
F_4 () ;
F_5 () ;
F_6 () ;
F_7 () ;
F_8 () ;
}
static int F_9 ( T_1 * V_1 ) {
F_10 ( V_1 , L_1 ) ;
return 0 ;
}
int F_11 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 , void * T_5 V_5 ) {
int V_6 = F_12 ( V_2 ) ;
V_7 = V_3 ;
V_8 = V_2 ;
V_9 = (struct V_10 * ) F_13 ( sizeof( struct V_10 ) ) ;
V_9 -> V_4 = V_4 ;
V_9 -> V_11 = F_14 ( V_4 , V_2 , 0 , 0 , L_2 ) ;
V_9 -> V_12 = FALSE ;
F_15 ( V_9 -> V_11 ) ;
F_16 ( V_13 , 0 ) ;
F_17 ( V_13 , V_14 , V_15 ) ;
F_18 ( V_13 , V_3 -> V_16 ) ;
F_19 ( V_13 , - 2 ) ;
F_20 ( V_13 , 1 ) ;
if ( F_21 ( V_13 , 1 ) ) {
F_22 ( V_13 , V_2 ) ;
F_23 ( V_13 , V_3 ) ;
F_24 ( V_13 , V_9 ) ;
if ( F_25 ( V_13 , 3 , 1 , 0 ) ) {
F_26 ( V_4 , V_3 , & V_17 , V_2 , 0 , 0 , L_3 , F_27 ( V_13 , - 1 ) ) ;
} else {
if ( F_28 ( V_13 , - 1 ) ) {
V_6 = ( int ) F_29 ( V_13 , - 1 ) ;
F_30 ( V_13 , 1 ) ;
}
}
} else {
F_26 ( V_4 , V_3 , & V_17 , V_2 , 0 , 0 ,
L_4 , V_3 -> V_16 ) ;
}
F_31 ( V_3 , F_1 ) ;
V_7 = NULL ;
V_9 = NULL ;
V_8 = NULL ;
return V_6 ;
}
static void F_32 ( T_1 * V_1 , const T_6 * V_18 , T_7 V_19 ) {
F_16 ( V_1 , 0 ) ;
F_33 ( V_1 , V_19 ) ;
F_34 ( V_1 , V_18 ) ;
if ( ! F_35 ( V_1 , 2 ) ) {
F_36 ( L_5 , V_18 ) ;
F_37 ( V_1 ) ;
V_13 = NULL ;
return;
}
F_38 ( V_1 ) ;
while ( F_39 ( V_1 , 2 ) ) {
const T_6 * V_20 = F_27 ( V_13 , - 2 ) ;
if ( F_21 ( V_1 , - 1 ) ) {
if ( F_25 ( V_1 , 0 , 0 , 1 ) ) {
F_30 ( V_1 , 1 ) ;
}
} else {
F_36 ( L_6 , V_18 , V_20 ) ;
F_37 ( V_1 ) ;
V_13 = NULL ;
return;
}
}
F_16 ( V_1 , 0 ) ;
}
static int F_40 ( T_1 * V_1 ) {
const T_6 * error = F_27 ( V_1 , 1 ) ;
F_36 ( L_7 , error ) ;
return 0 ;
}
static void F_41 ( void ) {
static T_8 V_21 = FALSE ;
if ( ! V_21 ) {
F_42 ( NULL ) ;
V_21 = TRUE ;
}
if ( V_13 ) {
F_32 ( V_13 , V_22 , F_40 ) ;
}
}
static int F_43 ( T_1 * V_1 ) {
const T_6 * error = F_27 ( V_1 , 1 ) ;
F_36 ( L_8 , error ) ;
return 0 ;
}
void F_44 ( void ) {
if ( V_13 ) {
F_32 ( V_13 , V_23 , F_43 ) ;
}
}
static const char * F_45 ( T_1 * V_1 V_5 , void * V_24 , T_9 * V_25 )
{
T_10 * V_26 = ( T_10 * ) V_24 ;
static char V_27 [ 512 ] ;
if ( feof ( V_26 ) ) return NULL ;
* V_25 = fread ( V_27 , 1 , sizeof( V_27 ) , V_26 ) ;
return ( * V_25 > 0 ) ? V_27 : NULL ;
}
static int F_46 ( T_1 * V_1 ) {
const T_6 * error = F_27 ( V_1 , 1 ) ;
F_36 ( L_9 , error ) ;
return 0 ;
}
static void F_47 ( T_6 * V_20 , T_6 * V_28 , T_6 * V_29 )
{
T_11 * V_30 , * V_31 ;
V_31 = V_32 ;
V_30 = ( T_11 * ) F_13 ( sizeof( T_11 ) ) ;
if ( ! V_31 ) {
V_32 = V_30 ;
} else {
while ( V_31 -> V_33 != NULL ) {
V_31 = V_31 -> V_33 ;
}
V_31 -> V_33 = V_30 ;
}
V_30 -> V_20 = V_20 ;
V_30 -> V_28 = V_28 ;
V_30 -> V_29 = V_29 ;
V_30 -> V_33 = NULL ;
}
static T_8 F_48 ( const T_6 * V_29 ) {
T_10 * V_34 ;
int error ;
if ( ! ( V_34 = F_49 ( V_29 , L_10 ) ) ) {
F_50 ( V_29 , V_35 , FALSE ) ;
return FALSE ;
}
F_16 ( V_13 , 0 ) ;
F_33 ( V_13 , F_46 ) ;
#if V_36 >= 502
error = F_51 ( V_13 , F_45 , V_34 , V_29 , NULL ) ;
#else
error = F_51 ( V_13 , F_45 , V_34 , V_29 ) ;
#endif
switch ( error ) {
case 0 :
F_25 ( V_13 , 0 , 0 , 1 ) ;
fclose ( V_34 ) ;
return TRUE ;
case V_37 : {
F_36 ( L_11 , V_29 , F_27 ( V_13 , - 1 ) ) ;
fclose ( V_34 ) ;
return FALSE ;
}
case V_38 :
F_36 ( L_12 , V_29 ) ;
fclose ( V_34 ) ;
return FALSE ;
default:
F_36 ( L_13 , V_29 , error ) ;
fclose ( V_34 ) ;
return FALSE ;
}
}
static void F_52 ( const T_6 * T_12 V_5 ,
T_13 T_14 V_5 ,
const T_6 * V_39 ,
T_15 T_16 V_5 ) {
fputs ( V_39 , V_40 ) ;
}
static int F_53 ( T_1 * V_1 ) {
F_54 ( L_14 , F_27 ( V_1 , - 1 ) ) ;
return 0 ;
}
static int F_55 ( const char * V_41 , T_17 V_42 , T_15 V_43 , T_8 V_44 ) {
T_18 * V_45 ;
T_19 * V_34 ;
T_6 * V_29 , * V_46 ;
const T_6 * V_20 ;
int V_47 = 0 ;
if ( ( V_45 = F_56 ( V_41 , 0 , NULL ) ) != NULL ) {
while ( ( V_34 = F_57 ( V_45 ) ) != NULL ) {
V_20 = F_58 ( V_34 ) ;
if ( strcmp ( V_20 , L_15 ) == 0 || strcmp ( V_20 , L_16 ) == 0 )
continue;
V_29 = F_59 ( L_17 V_48 L_17 , V_41 , V_20 ) ;
if ( F_60 ( V_29 ) == V_49 ) {
V_47 += F_55 ( V_29 , V_42 , V_43 , V_44 ) ;
F_61 ( V_29 ) ;
continue;
}
if ( V_20 [ 0 ] == '.' ) {
F_61 ( V_29 ) ;
continue;
}
V_46 = strrchr ( V_20 , '.' ) ;
if ( V_46 == NULL || F_62 ( V_46 + 1 , L_18 ) != 0 ) {
F_61 ( V_29 ) ;
continue;
}
if ( F_63 ( V_29 ) ) {
if ( ! V_44 ) {
if ( V_42 )
(* V_42)( V_50 , V_20 , V_43 ) ;
if ( F_48 ( V_29 ) ) {
F_47 ( F_64 ( V_20 ) , F_64 ( L_19 ) , F_64 ( V_29 ) ) ;
}
}
V_47 ++ ;
}
F_61 ( V_29 ) ;
}
F_65 ( V_45 ) ;
}
return V_47 ;
}
int F_66 ( void ) {
T_6 * V_29 ;
int V_47 ;
V_47 = F_55 ( F_67 () , NULL , NULL , TRUE ) ;
V_29 = F_68 ( L_20 , FALSE ) ;
if ( ( F_63 ( V_29 ) ) ) {
V_47 ++ ;
}
F_61 ( V_29 ) ;
V_29 = F_69 () ;
V_47 += F_55 ( V_29 , NULL , NULL , TRUE ) ;
F_61 ( V_29 ) ;
V_47 += F_70 ( L_21 ) ;
return V_47 ;
}
int F_71 ( T_17 V_42 , T_15 V_43 ) {
T_6 * V_29 ;
const T_20 * V_51 = F_72 () ;
T_8 V_52 = FALSE ;
T_21 * V_53 ;
static T_22 V_54 [] = {
{ & V_17 , { L_22 , V_55 , V_56 , L_23 , V_57 } } ,
} ;
F_73 ( V_58 , ( T_13 ) ( V_59 |
V_60 |
V_61 |
V_62 |
V_63 ) ,
V_51 ? V_51 -> V_64 : F_52 ,
NULL ) ;
if ( ! V_13 ) {
V_13 = F_74 () ;
}
F_75 ( V_13 ) ;
V_65 = F_76 ( L_24 , L_24 , L_25 ) ;
V_53 = F_77 ( V_65 ) ;
F_78 ( V_53 , V_54 , F_79 ( V_54 ) ) ;
F_80 ( V_13 , F_53 ) ;
F_81 ( V_13 ) ;
F_82 ( V_13 , V_22 ) ;
F_81 ( V_13 ) ;
V_15 = F_83 ( V_13 , V_14 ) ;
F_81 ( V_13 ) ;
F_82 ( V_13 , V_23 ) ;
F_84 ( V_13 , L_26 , F_85 () ) ;
F_86 ( V_13 , L_27 , V_66 ) ;
V_29 = F_87 ( L_20 ) ;
if ( ( F_63 ( V_29 ) ) ) {
F_48 ( V_29 ) ;
}
F_61 ( V_29 ) ;
V_29 = NULL ;
F_34 ( V_13 , L_28 ) ;
if ( F_88 ( V_13 , - 1 ) && F_89 ( V_13 , - 1 ) ) {
F_37 ( V_13 ) ;
V_13 = NULL ;
return 0 ;
}
F_55 ( F_67 () , V_42 , V_43 , FALSE ) ;
F_34 ( V_13 , L_29 ) ;
if ( F_88 ( V_13 , - 1 ) && F_89 ( V_13 , - 1 ) ) {
V_52 = TRUE ;
}
if ( ( ! F_85 () ) || V_52 ) {
V_29 = F_68 ( L_20 , FALSE ) ;
if ( ( F_63 ( V_29 ) ) ) {
if ( V_42 )
(* V_42)( V_50 , F_90 ( V_29 ) , V_43 ) ;
F_48 ( V_29 ) ;
}
F_61 ( V_29 ) ;
V_29 = F_69 () ;
F_55 ( V_29 , V_42 , V_43 , FALSE ) ;
F_61 ( V_29 ) ;
while( ( V_29 = ( T_6 * ) F_91 ( L_21 ) ) ) {
if ( V_42 )
(* V_42)( V_50 , F_90 ( V_29 ) , V_43 ) ;
F_48 ( V_29 ) ;
}
}
F_92 ( F_41 ) ;
F_33 ( V_13 , F_9 ) ;
F_82 ( V_13 , L_30 ) ;
V_7 = NULL ;
V_9 = NULL ;
V_8 = NULL ;
V_67 = F_93 ( L_31 ) ;
F_94 ( V_13 ) ;
return 0 ;
}
T_1 * F_95 ( void ) { return V_13 ; }
