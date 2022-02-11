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
int F_11 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ) {
int V_5 = F_12 ( V_2 ) ;
V_6 = V_3 ;
V_7 = V_2 ;
V_8 = F_13 ( sizeof( struct V_9 ) ) ;
V_8 -> V_4 = V_4 ;
V_8 -> V_10 = F_14 ( V_4 , V_2 , 0 , 0 , L_2 ) ;
V_8 -> V_11 = FALSE ;
F_15 ( V_8 -> V_10 ) ;
F_16 ( V_12 , 0 ) ;
F_17 ( V_12 , V_13 , V_14 ) ;
F_18 ( V_12 , V_3 -> V_15 ) ;
F_19 ( V_12 , - 2 ) ;
F_20 ( V_12 , 1 ) ;
if ( F_21 ( V_12 , 1 ) ) {
F_22 ( V_12 , V_2 ) ;
F_23 ( V_12 , V_3 ) ;
F_24 ( V_12 , V_8 ) ;
if ( F_25 ( V_12 , 3 , 1 , 0 ) ) {
const T_5 * error = F_26 ( V_12 , - 1 ) ;
T_6 * V_16 = F_14 ( V_4 , V_2 , 0 , 0 , L_3 , error ) ;
F_27 ( V_3 , V_16 , V_17 , V_18 , L_4 ) ;
} else {
if ( F_28 ( V_12 , - 1 ) ) {
V_5 = ( int ) F_29 ( V_12 , - 1 ) ;
F_30 ( V_12 , 1 ) ;
}
}
} else {
T_6 * V_16 = F_14 ( V_4 , V_2 , 0 , 0 , L_5
L_6 , V_3 -> V_15 ) ;
F_27 ( V_3 , V_16 , V_17 , V_18 , L_4 ) ;
}
F_31 ( F_1 ) ;
V_6 = NULL ;
V_8 = NULL ;
V_7 = NULL ;
return V_5 ;
}
static void F_32 ( T_1 * V_1 , int V_19 , const T_5 * V_20 , T_7 V_21 ) {
F_16 ( V_1 , 0 ) ;
F_33 ( V_1 , V_21 ) ;
F_18 ( V_1 , V_20 ) ;
F_19 ( V_1 , V_19 ) ;
if ( ! F_34 ( V_1 , 2 ) ) {
F_35 ( L_7 , V_20 ) ;
F_36 ( V_1 ) ;
V_12 = NULL ;
return;
}
F_37 ( V_1 ) ;
while ( F_38 ( V_1 , 2 ) ) {
const T_5 * V_22 = F_26 ( V_12 , - 2 ) ;
if ( F_21 ( V_1 , - 1 ) ) {
if ( F_25 ( V_1 , 0 , 0 , 1 ) ) {
F_30 ( V_1 , 1 ) ;
}
} else {
F_35 ( L_8 , V_20 , V_22 ) ;
F_36 ( V_1 ) ;
V_12 = NULL ;
return;
}
}
F_16 ( V_1 , 0 ) ;
}
static int F_39 ( T_1 * V_1 ) {
const T_5 * error = F_26 ( V_1 , 1 ) ;
F_35 ( L_9 , error ) ;
return 0 ;
}
static void F_40 ( void ) {
static T_8 V_23 = FALSE ;
if ( ! V_23 ) {
F_41 ( NULL ) ;
V_23 = TRUE ;
}
if ( V_12 ) {
F_32 ( V_12 , V_24 , V_25 , F_39 ) ;
}
}
static const char * F_42 ( T_1 * V_1 V_26 , void * V_27 , T_9 * V_28 )
{
T_10 * V_29 = ( T_10 * ) V_27 ;
static char V_30 [ 512 ] ;
if ( feof ( V_29 ) ) return NULL ;
* V_28 = fread ( V_30 , 1 , sizeof( V_30 ) , V_29 ) ;
return ( * V_28 > 0 ) ? V_30 : NULL ;
}
static int F_43 ( T_1 * V_1 ) {
const T_5 * error = F_26 ( V_1 , 1 ) ;
F_35 ( L_10 , error ) ;
return 0 ;
}
static void F_44 ( T_5 * V_22 , T_5 * V_31 , T_5 * V_32 )
{
T_11 * V_33 , * V_34 ;
V_34 = V_35 ;
V_33 = ( T_11 * ) F_13 ( sizeof( T_11 ) ) ;
if ( ! V_34 ) {
V_35 = V_33 ;
} else {
while ( V_34 -> V_36 != NULL ) {
V_34 = V_34 -> V_36 ;
}
V_34 -> V_36 = V_33 ;
}
V_33 -> V_22 = V_22 ;
V_33 -> V_31 = V_31 ;
V_33 -> V_32 = V_32 ;
V_33 -> V_36 = NULL ;
}
static T_8 F_45 ( const T_5 * V_32 ) {
T_10 * V_37 ;
int error ;
if ( ! ( V_37 = F_46 ( V_32 , L_11 ) ) ) {
F_47 ( V_32 , V_38 , FALSE ) ;
return FALSE ;
}
F_16 ( V_12 , 0 ) ;
F_33 ( V_12 , F_43 ) ;
error = F_48 ( V_12 , F_42 , V_37 , V_32 ) ;
switch ( error ) {
case 0 :
F_25 ( V_12 , 0 , 0 , 1 ) ;
fclose ( V_37 ) ;
return TRUE ;
case V_39 : {
F_35 ( L_12 , V_32 , F_26 ( V_12 , - 1 ) ) ;
fclose ( V_37 ) ;
return FALSE ;
}
case V_40 :
F_35 ( L_13 , V_32 ) ;
fclose ( V_37 ) ;
return FALSE ;
}
F_35 ( L_14 , V_32 , error ) ;
fclose ( V_37 ) ;
return FALSE ;
}
static void F_49 ( const T_5 * T_12 V_26 ,
T_13 T_14 V_26 ,
const T_5 * V_41 ,
T_15 T_16 V_26 ) {
fputs ( V_41 , V_42 ) ;
}
static int F_50 ( T_1 * V_1 ) {
F_51 ( L_15 , F_26 ( V_1 , - 1 ) ) ;
return 0 ;
}
static void F_52 ( const char * V_43 )
{
T_17 * V_44 ;
T_18 * V_37 ;
T_5 * V_32 , * V_45 ;
const T_5 * V_22 ;
if ( ( V_44 = F_53 ( V_43 , 0 , NULL ) ) != NULL ) {
while ( ( V_37 = F_54 ( V_44 ) ) != NULL ) {
V_22 = F_55 ( V_37 ) ;
if ( strcmp ( V_22 , L_16 ) == 0 || strcmp ( V_22 , L_17 ) == 0 )
continue;
V_32 = F_56 ( L_18 V_46 L_18 , V_43 , V_22 ) ;
if ( F_57 ( V_32 ) == V_47 ) {
F_52 ( V_32 ) ;
F_58 ( V_32 ) ;
continue;
}
if ( V_22 [ 0 ] == '.' ) {
F_58 ( V_32 ) ;
continue;
}
V_45 = strrchr ( V_22 , '.' ) ;
if ( V_45 == NULL || F_59 ( V_45 + 1 , L_19 ) != 0 ) {
F_58 ( V_32 ) ;
continue;
}
if ( F_60 ( V_32 ) ) {
if ( F_45 ( V_32 ) ) {
F_44 ( F_61 ( V_22 ) , F_61 ( L_20 ) , F_61 ( V_32 ) ) ;
}
}
F_58 ( V_32 ) ;
}
F_62 ( V_44 ) ;
}
}
int F_63 ( T_19 V_48 , T_15 V_49 ) {
T_5 * V_32 ;
const T_20 * V_50 = F_64 () ;
T_8 V_51 = FALSE ;
if( V_48 )
(* V_48)( V_52 , NULL , V_49 ) ;
F_65 ( V_53 , V_54 |
V_55 |
V_56 |
V_57 |
V_58 ,
V_50 ? V_50 -> V_59 : F_49 , NULL ) ;
if ( ! V_12 ) {
V_12 = F_66 () ;
}
F_67 ( V_12 ) ;
F_68 ( V_12 , F_50 ) ;
F_18 ( V_12 , V_25 ) ;
F_69 ( V_12 ) ;
F_70 ( V_12 , V_24 ) ;
F_69 ( V_12 ) ;
V_14 = F_71 ( V_12 , V_13 ) ;
F_72 ( V_12 , L_21 , F_73 () ) ;
F_74 ( V_12 , L_22 , V_60 ) ;
V_32 = F_75 ( L_23 ) ;
if ( ( F_60 ( V_32 ) ) ) {
F_45 ( V_32 ) ;
}
F_58 ( V_32 ) ;
V_32 = NULL ;
F_18 ( V_12 , L_24 ) ;
F_19 ( V_12 , V_24 ) ;
if ( F_76 ( V_12 , - 1 ) && F_77 ( V_12 , - 1 ) ) {
F_36 ( V_12 ) ;
V_12 = NULL ;
return 0 ;
}
F_52 ( F_78 () ) ;
F_18 ( V_12 , L_25 ) ;
F_19 ( V_12 , V_24 ) ;
if ( F_76 ( V_12 , - 1 ) && F_77 ( V_12 , - 1 ) ) {
V_51 = TRUE ;
}
if ( ( ! F_73 () ) || V_51 ) {
V_32 = F_79 ( L_23 , FALSE , FALSE ) ;
if ( ( F_60 ( V_32 ) ) ) {
F_45 ( V_32 ) ;
}
F_58 ( V_32 ) ;
V_32 = F_80 () ;
F_52 ( V_32 ) ;
F_58 ( V_32 ) ;
while( ( V_32 = ( T_5 * ) F_81 ( L_26 ) ) ) {
F_45 ( V_32 ) ;
}
}
F_82 ( F_40 ) ;
F_18 ( V_12 , L_27 ) ;
F_33 ( V_12 , F_9 ) ;
F_70 ( V_12 , V_24 ) ;
V_6 = NULL ;
V_8 = NULL ;
V_7 = NULL ;
V_61 = F_83 ( L_28 ) ;
V_62 = F_84 ( L_29 ) ;
F_85 ( V_12 ) ;
return 0 ;
}
T_1 * F_86 ( void ) { return V_12 ; }
