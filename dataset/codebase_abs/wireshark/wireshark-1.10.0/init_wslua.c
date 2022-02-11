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
const T_6 * error = F_26 ( V_13 , - 1 ) ;
T_7 * V_17 = F_14 ( V_4 , V_2 , 0 , 0 , L_3 , error ) ;
F_27 ( V_3 , V_17 , V_18 , V_19 , L_4 ) ;
} else {
if ( F_28 ( V_13 , - 1 ) ) {
V_6 = ( int ) F_29 ( V_13 , - 1 ) ;
F_30 ( V_13 , 1 ) ;
}
}
} else {
T_7 * V_17 = F_14 ( V_4 , V_2 , 0 , 0 , L_5
L_6 , V_3 -> V_16 ) ;
F_27 ( V_3 , V_17 , V_18 , V_19 , L_4 ) ;
}
F_31 ( V_3 , F_1 ) ;
V_7 = NULL ;
V_9 = NULL ;
V_8 = NULL ;
return V_6 ;
}
static void F_32 ( T_1 * V_1 , const T_6 * V_20 , T_8 V_21 ) {
F_16 ( V_1 , 0 ) ;
F_33 ( V_1 , V_21 ) ;
F_34 ( V_1 , V_20 ) ;
if ( ! F_35 ( V_1 , 2 ) ) {
F_36 ( L_7 , V_20 ) ;
F_37 ( V_1 ) ;
V_13 = NULL ;
return;
}
F_38 ( V_1 ) ;
while ( F_39 ( V_1 , 2 ) ) {
const T_6 * V_22 = F_26 ( V_13 , - 2 ) ;
if ( F_21 ( V_1 , - 1 ) ) {
if ( F_25 ( V_1 , 0 , 0 , 1 ) ) {
F_30 ( V_1 , 1 ) ;
}
} else {
F_36 ( L_8 , V_20 , V_22 ) ;
F_37 ( V_1 ) ;
V_13 = NULL ;
return;
}
}
F_16 ( V_1 , 0 ) ;
}
static int F_40 ( T_1 * V_1 ) {
const T_6 * error = F_26 ( V_1 , 1 ) ;
F_36 ( L_9 , error ) ;
return 0 ;
}
static void F_41 ( void ) {
static T_9 V_23 = FALSE ;
if ( ! V_23 ) {
F_42 ( NULL ) ;
V_23 = TRUE ;
}
if ( V_13 ) {
F_32 ( V_13 , V_24 , F_40 ) ;
}
}
static const char * F_43 ( T_1 * V_1 V_5 , void * V_25 , T_10 * V_26 )
{
T_11 * V_27 = ( T_11 * ) V_25 ;
static char V_28 [ 512 ] ;
if ( feof ( V_27 ) ) return NULL ;
* V_26 = fread ( V_28 , 1 , sizeof( V_28 ) , V_27 ) ;
return ( * V_26 > 0 ) ? V_28 : NULL ;
}
static int F_44 ( T_1 * V_1 ) {
const T_6 * error = F_26 ( V_1 , 1 ) ;
F_36 ( L_10 , error ) ;
return 0 ;
}
static void F_45 ( T_6 * V_22 , T_6 * V_29 , T_6 * V_30 )
{
T_12 * V_31 , * V_32 ;
V_32 = V_33 ;
V_31 = ( T_12 * ) F_13 ( sizeof( T_12 ) ) ;
if ( ! V_32 ) {
V_33 = V_31 ;
} else {
while ( V_32 -> V_34 != NULL ) {
V_32 = V_32 -> V_34 ;
}
V_32 -> V_34 = V_31 ;
}
V_31 -> V_22 = V_22 ;
V_31 -> V_29 = V_29 ;
V_31 -> V_30 = V_30 ;
V_31 -> V_34 = NULL ;
}
static T_9 F_46 ( const T_6 * V_30 ) {
T_11 * V_35 ;
int error ;
if ( ! ( V_35 = F_47 ( V_30 , L_11 ) ) ) {
F_48 ( V_30 , V_36 , FALSE ) ;
return FALSE ;
}
F_16 ( V_13 , 0 ) ;
F_33 ( V_13 , F_44 ) ;
#if V_37 >= 502
error = F_49 ( V_13 , F_43 , V_35 , V_30 , NULL ) ;
#else
error = F_49 ( V_13 , F_43 , V_35 , V_30 ) ;
#endif
switch ( error ) {
case 0 :
F_25 ( V_13 , 0 , 0 , 1 ) ;
fclose ( V_35 ) ;
return TRUE ;
case V_38 : {
F_36 ( L_12 , V_30 , F_26 ( V_13 , - 1 ) ) ;
fclose ( V_35 ) ;
return FALSE ;
}
case V_39 :
F_36 ( L_13 , V_30 ) ;
fclose ( V_35 ) ;
return FALSE ;
default:
F_36 ( L_14 , V_30 , error ) ;
fclose ( V_35 ) ;
return FALSE ;
}
}
static void F_50 ( const T_6 * T_13 V_5 ,
T_14 T_15 V_5 ,
const T_6 * V_40 ,
T_16 T_17 V_5 ) {
fputs ( V_40 , V_41 ) ;
}
static int F_51 ( T_1 * V_1 ) {
F_52 ( L_15 , F_26 ( V_1 , - 1 ) ) ;
return 0 ;
}
static void F_53 ( const char * V_42 )
{
T_18 * V_43 ;
T_19 * V_35 ;
T_6 * V_30 , * V_44 ;
const T_6 * V_22 ;
if ( ( V_43 = F_54 ( V_42 , 0 , NULL ) ) != NULL ) {
while ( ( V_35 = F_55 ( V_43 ) ) != NULL ) {
V_22 = F_56 ( V_35 ) ;
if ( strcmp ( V_22 , L_16 ) == 0 || strcmp ( V_22 , L_17 ) == 0 )
continue;
V_30 = F_57 ( L_18 V_45 L_18 , V_42 , V_22 ) ;
if ( F_58 ( V_30 ) == V_46 ) {
F_53 ( V_30 ) ;
F_59 ( V_30 ) ;
continue;
}
if ( V_22 [ 0 ] == '.' ) {
F_59 ( V_30 ) ;
continue;
}
V_44 = strrchr ( V_22 , '.' ) ;
if ( V_44 == NULL || F_60 ( V_44 + 1 , L_19 ) != 0 ) {
F_59 ( V_30 ) ;
continue;
}
if ( F_61 ( V_30 ) ) {
if ( F_46 ( V_30 ) ) {
F_45 ( F_62 ( V_22 ) , F_62 ( L_20 ) , F_62 ( V_30 ) ) ;
}
}
F_59 ( V_30 ) ;
}
F_63 ( V_43 ) ;
}
}
int F_64 ( T_20 V_47 , T_16 V_48 ) {
T_6 * V_30 ;
const T_21 * V_49 = F_65 () ;
T_9 V_50 = FALSE ;
if( V_47 )
(* V_47)( V_51 , NULL , V_48 ) ;
F_66 ( V_52 , ( T_14 ) ( V_53 |
V_54 |
V_55 |
V_56 |
V_57 ) ,
V_49 ? V_49 -> V_58 : F_50 ,
NULL ) ;
if ( ! V_13 ) {
V_13 = F_67 () ;
}
F_68 ( V_13 ) ;
F_69 ( V_13 , F_51 ) ;
F_70 ( V_13 ) ;
F_71 ( V_13 , V_24 ) ;
F_70 ( V_13 ) ;
V_15 = F_72 ( V_13 , V_14 ) ;
F_73 ( V_13 , L_21 , F_74 () ) ;
F_75 ( V_13 , L_22 , V_59 ) ;
V_30 = F_76 ( L_23 ) ;
if ( ( F_61 ( V_30 ) ) ) {
F_46 ( V_30 ) ;
}
F_59 ( V_30 ) ;
V_30 = NULL ;
F_34 ( V_13 , L_24 ) ;
if ( F_77 ( V_13 , - 1 ) && F_78 ( V_13 , - 1 ) ) {
F_37 ( V_13 ) ;
V_13 = NULL ;
return 0 ;
}
F_53 ( F_79 () ) ;
F_34 ( V_13 , L_25 ) ;
if ( F_77 ( V_13 , - 1 ) && F_78 ( V_13 , - 1 ) ) {
V_50 = TRUE ;
}
if ( ( ! F_74 () ) || V_50 ) {
V_30 = F_80 ( L_23 , FALSE ) ;
if ( ( F_61 ( V_30 ) ) ) {
F_46 ( V_30 ) ;
}
F_59 ( V_30 ) ;
V_30 = F_81 () ;
F_53 ( V_30 ) ;
F_59 ( V_30 ) ;
while( ( V_30 = ( T_6 * ) F_82 ( L_26 ) ) ) {
F_46 ( V_30 ) ;
}
}
F_83 ( F_41 ) ;
F_33 ( V_13 , F_9 ) ;
F_71 ( V_13 , L_27 ) ;
V_7 = NULL ;
V_9 = NULL ;
V_8 = NULL ;
V_60 = F_84 ( L_28 ) ;
F_85 ( V_13 ) ;
return 0 ;
}
T_1 * F_86 ( void ) { return V_13 ; }
