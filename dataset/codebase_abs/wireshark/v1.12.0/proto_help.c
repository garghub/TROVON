void F_1 ( T_1 * T_2 V_1 , T_3 * T_4 V_1 ) {}
void F_2 ( T_5 * T_6 V_1 ) {}
void F_3 ( void ) {}
void F_3 ( void )
{
T_7 * V_2 [ V_3 ] ;
const T_7 * V_4 ;
T_7 * V_5 ;
T_8 * V_6 ;
int V_7 ;
V_2 [ 0 ] = F_4 ( L_1 G_DIR_SEPARATOR_S PH_CONFFILE_SUBDIR, get_datafile_dir()) ;
V_2 [ 1 ] = F_5 ( V_8 , FALSE , FALSE ) ;
#ifdef F_6
F_7 ( NULL , V_9 | V_10 | V_11 , V_12 , NULL ) ;
#endif
if ( V_13 )
return;
V_13 = F_8 () ;
#ifdef F_6
V_14 = F_4 ( L_1 V_15 L_1 , F_9 () , V_16 ) ;
#endif
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
F_10 ( NULL , V_17 , L_2 , V_2 [ V_7 ] ) ;
V_6 = F_11 ( V_2 [ V_7 ] , 0 , NULL ) ;
if ( ! V_6 ) {
continue;
}
while ( ( V_4 = F_12 ( V_6 ) ) != NULL ) {
if ( ! F_13 ( V_4 , V_18 ) ) {
continue;
}
F_10 ( NULL , V_17 , L_3 , V_4 ) ;
V_5 = F_4 ( L_1 V_15 L_1 , V_2 [ V_7 ] , V_4 ) ;
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
}
F_16 ( V_6 ) ;
}
}
void F_2 ( T_5 * T_6 )
{
V_19 = F_17 ( T_6 ) ;
F_18 () ;
}
static void F_18 ( void )
{
T_5 * V_20 = NULL ;
T_9 * V_21 = NULL ;
T_9 * V_22 = NULL ;
if( ! V_19 ) return;
V_20 = F_19 ( V_19 , V_23 ) ;
V_21 = F_20 ( F_21 ( V_20 ) ) ;
for( V_22 = F_22 ( V_21 ) ; V_22 != NULL ; V_22 = F_23 ( V_22 ) )
{
F_24 ( F_21 ( V_20 ) , V_22 -> V_24 ) ;
}
V_20 = F_25 ( V_19 , V_23 ) ;
F_26 ( V_20 , FALSE ) ;
}
static void
F_27 ( T_5 * T_10 V_1 , T_11 V_25 ) {
F_15 ( V_25 ) ;
}
void F_1 ( T_1 * T_2 , T_3 * T_4 )
{
T_7 * V_26 ;
const T_7 * V_27 , * V_28 ;
T_7 * V_29 ;
T_7 * * V_30 ;
T_12 * V_31 ;
T_13 V_7 = 0 , V_32 ;
T_5 * V_20 = NULL ;
T_14 * V_22 = NULL ;
T_15 * V_33 ;
T_7 * V_34 ;
T_16 V_35 = FALSE ;
T_16 V_36 = FALSE ;
if( ! V_19 ) return;
F_18 () ;
V_27 = F_28 ( T_2 , T_4 ) ;
if( ! V_27 ) return;
V_28 = F_29 ( T_2 , T_4 ) ;
if( ! V_28 ) return;
V_26 = F_30 ( T_4 ) ;
for ( V_32 = 0 ; V_32 < V_13 -> V_37 ; V_32 ++ ) {
V_33 = ( T_15 * ) F_31 ( V_13 , V_32 ) ;
F_32 ( V_33 ) ;
V_29 = F_33 ( V_33 -> V_38 , V_27 , V_39 ) ;
if( ! V_29 )
{
F_10 ( NULL , V_40 , L_4 , V_27 ) ;
continue;
}
V_34 = F_34 ( V_33 -> V_41 , V_42 , V_29 ) ;
F_15 ( V_29 ) ;
if ( ! V_34 || ! strlen ( V_34 ) ) continue;
if ( V_35 ) {
V_22 = F_35 ( sizeof( T_14 ) ) ;
V_22 -> V_43 = F_4 ( L_5 , V_23 ) ;
V_22 -> V_44 = L_6 ;
F_36 ( V_19 , V_22 , NULL , 2 ) ;
}
V_35 = TRUE ;
V_22 = F_35 ( sizeof( T_14 ) ) ;
V_22 -> V_43 = F_4 ( L_7 , V_23 , V_33 -> V_45 , V_28 ) ;
V_22 -> V_46 = V_47 ;
F_36 ( V_19 , V_22 , V_34 , 2 ) ;
V_20 = F_19 ( V_19 , V_22 -> V_43 ) ;
F_32 ( V_20 ) ;
F_37 ( V_20 , L_8 , F_38 ( F_27 ) , V_34 ) ;
V_36 = TRUE ;
if( V_26 )
{
V_30 = F_39 ( V_33 -> V_38 , V_27 ) ;
V_31 = F_40 ( V_48 , V_49 , F_15 , NULL ) ;
for( V_7 = 0 ; V_30 [ V_7 ] != NULL ; V_7 ++ )
{
if( ! strcmp ( V_30 [ V_7 ] , V_39 ) ) continue;
if( ! F_41 ( V_26 , V_30 [ V_7 ] ) ) continue;
if( F_42 ( V_31 , F_43 ( V_30 [ V_7 ] , - 1 ) ) != NULL ) continue;
V_29 = F_33 ( V_33 -> V_38 , V_27 , V_30 [ V_7 ] ) ;
if( ! V_29 || ! strlen ( V_29 ) ) continue;
V_34 = F_34 ( V_33 -> V_41 , V_42 , V_29 ) ;
F_15 ( V_29 ) ;
if ( ! V_34 || ! strlen ( V_34 ) ) continue;
F_44 ( V_31 , F_43 ( V_30 [ V_7 ] , - 1 ) , F_45 ( 1 ) ) ;
V_22 = F_35 ( sizeof( T_14 ) ) ;
V_22 -> V_43 = F_4 ( L_9 , V_23 , V_30 [ V_7 ] ) ;
V_22 -> V_46 = V_47 ;
F_36 ( V_19 , V_22 , V_34 , 2 ) ;
V_20 = F_19 ( V_19 , V_22 -> V_43 ) ;
F_32 ( V_20 ) ;
F_37 ( V_20 , L_8 , F_38 ( F_27 ) , V_34 ) ;
}
F_46 ( V_31 ) ;
}
}
F_15 ( V_26 ) ;
V_20 = F_25 ( V_19 , V_23 ) ;
F_26 ( V_20 , V_36 ) ;
}
static void V_47 ( T_5 * T_6 V_1 , T_11 V_24 , T_13 T_17 V_1 )
{
T_7 * V_34 = ( T_7 * ) V_24 ;
F_10 ( NULL , V_40 , L_10 , V_34 ) ;
if ( ! V_34 ) {
F_10 ( NULL , V_40 , L_11 ) ;
return;
}
if ( ! F_47 ( V_34 ) ) {
F_10 ( NULL , V_40 , L_12 , V_34 ) ;
}
}
static int
F_48 ( T_1 * T_2 , T_3 * T_4 )
{
T_18 * V_50 = NULL ;
T_19 V_51 ;
T_19 V_52 ;
T_20 * V_53 = NULL ;
int V_54 = 0 ;
if( ! T_4 -> V_55 ) return 0 ;
V_54 = T_4 -> V_55 -> V_56 -> V_57 ;
if( ! V_54 )
{
if( ! F_49 ( F_50 ( T_2 ) , & V_50 , & V_51 ) ) return 0 ;
while( F_51 ( V_50 , & V_52 , & V_51 ) )
{
F_52 ( V_50 , & V_52 , 1 , & V_53 , - 1 ) ;
V_51 = V_52 ;
if( V_53 -> V_56 -> V_57 > 0 )
{
V_54 = V_53 -> V_56 -> V_57 ;
break;
}
}
}
while( V_54 && ! F_53 ( V_54 ) )
{
V_54 = F_54 ( V_54 ) ;
}
return V_54 ;
}
static const T_7 *
F_29 ( T_1 * T_2 , T_3 * T_4 )
{
int V_54 = F_48 ( T_2 , T_4 ) ;
return ( ! V_54 ) ? NULL : F_55 ( F_56 ( V_54 ) ) ;
}
static const T_7 *
F_28 ( T_1 * T_2 , T_3 * T_4 )
{
int V_54 = F_48 ( T_2 , T_4 ) ;
return ( ! V_54 ) ? NULL : F_57 ( V_54 ) ;
}
static T_7 * F_30 ( T_3 * T_4 )
{
T_7 * V_58 = NULL ;
if( T_4 -> V_55 -> V_59 &&
strlen ( T_4 -> V_55 -> V_59 -> V_60 ) > 0 )
{
V_58 = F_58 ( T_4 -> V_55 -> V_59 -> V_60 ) ;
}
else
{
V_58 = F_59 ( V_61 ) ;
F_60 ( T_4 -> V_55 , V_58 ) ;
}
return V_58 ;
}
static T_15 *
F_14 ( const T_7 * V_62 )
{
T_21 * V_63 ;
T_22 * error = NULL ;
T_15 * V_33 = NULL ;
T_7 * V_64 , * V_41 ;
T_7 * * V_65 , * V_66 , * V_67 ;
T_23 V_7 , V_37 ;
if( ! F_61 ( V_62 , V_68 ) )
{
F_10 ( NULL , V_40 , L_13 , V_62 ) ;
return NULL ;
}
V_63 = F_62 () ;
if( ! F_63 ( V_63 , V_62 , V_69 , & error ) )
{
F_10 ( NULL , V_40 , L_14 , V_62 , error -> V_70 ) ;
F_64 ( error ) ;
F_65 ( V_63 ) ;
return NULL ;
}
V_41 = F_66 ( V_63 , V_71 , V_72 , NULL ) ;
if ( ! V_41 ) {
F_65 ( V_63 ) ;
return NULL ;
}
V_65 = F_67 ( V_63 , V_73 , & V_37 , NULL ) ;
if ( V_65 ) {
for ( V_7 = 0 ; V_7 < V_37 ; V_7 ++ ) {
V_66 = F_66 ( V_63 , V_73 , V_65 [ V_7 ] , NULL ) ;
V_64 = V_41 ;
V_67 = F_4 ( L_15 , V_65 [ V_7 ] ) ;
V_41 = F_34 ( V_41 , V_67 , V_66 ) ;
F_15 ( V_66 ) ;
F_15 ( V_67 ) ;
F_15 ( V_64 ) ;
}
}
if ( ! strstr ( V_41 , V_42 ) ) {
V_64 = V_41 ;
V_41 = F_4 ( L_1 V_42 , V_64 ) ;
F_15 ( V_64 ) ;
}
V_33 = F_59 ( sizeof( T_15 ) ) ;
V_33 -> V_38 = V_63 ;
V_33 -> V_45 = F_66 ( V_63 , V_71 , V_74 , L_16 ) ;
V_33 -> V_41 = V_41 ;
F_68 ( V_13 , V_33 ) ;
return V_33 ;
}
static T_7 *
F_66 ( T_21 * V_38 , const T_7 * V_75 , const T_7 * V_76 , T_7 * V_77 )
{
T_7 * V_29 = NULL ;
if ( V_38 ) {
V_29 = F_69 ( V_38 , V_75 , V_76 , NULL ) ;
}
if ( ! V_29 ) {
V_29 = F_58 ( V_77 ) ;
}
return V_29 ;
}
static T_7 *
F_33 ( T_21 * V_38 , const T_7 * V_78 , const T_7 * V_79 )
{
T_22 * error = NULL ;
T_7 * V_80 ;
T_7 * V_29 ;
if( ! V_38 || ! V_78 || ! V_79 ) return NULL ;
V_80 = F_69 ( V_38 , V_81 , V_78 , & error ) ;
if( ! V_80 )
{
F_10 ( NULL , V_40 , L_17 , V_78 , error -> V_70 ) ;
F_64 ( error ) ;
return NULL ;
}
V_29 = F_69 ( V_38 , V_80 , V_79 , NULL ) ;
F_15 ( V_80 ) ;
return V_29 ;
}
static T_7 * *
F_39 ( T_21 * V_38 , const T_7 * V_78 )
{
T_22 * error = NULL ;
T_7 * V_80 ;
T_7 * * V_30 ;
T_23 V_82 = 0 ;
if( ! V_38 ) return NULL ;
V_80 = F_69 ( V_38 , V_81 , V_78 , & error ) ;
if( ! V_80 )
{
F_10 ( NULL , V_40 , L_17 , V_78 , error -> V_70 ) ;
F_64 ( error ) ;
return NULL ;
}
error = NULL ;
V_30 = F_67 ( V_38 , V_80 , & V_82 , & error ) ;
F_15 ( V_80 ) ;
if( ! V_30 )
{
F_10 ( NULL , V_40 , L_18 , V_78 ) ;
F_64 ( error ) ;
}
return V_30 ;
}
static T_13 F_41 ( const T_7 * V_26 , const T_7 * V_29 )
{
T_24 * V_83 = NULL ;
T_25 * V_84 = NULL ;
T_7 * V_85 = NULL ;
T_13 V_86 = 0 ;
V_85 = F_4 ( L_19 , V_29 ) ;
V_83 = F_70 ( V_85 , 0 , 0 , NULL ) ;
F_71 ( V_83 , V_26 , 0 , & V_84 ) ;
if( F_72 ( V_84 ) ) V_86 = 1 ;
F_73 ( V_84 ) ;
F_74 ( V_83 ) ;
return V_86 ;
}
static void V_12 ( const T_7 * T_26 V_1 , T_27 V_87 , const T_7 * V_70 , T_11 V_24 V_1 )
{
T_7 * log = NULL ;
T_7 * type = NULL ;
T_28 * V_88 = NULL ;
struct V_89 * V_90 = NULL ;
T_29 V_91 ;
time ( & V_91 ) ;
V_90 = localtime ( & V_91 ) ;
switch( V_87 & V_9 )
{
case V_92 :
type = L_20 ;
break;
case V_40 :
type = L_21 ;
break;
case V_17 :
type = L_22 ;
break;
default:
type = L_23 ;
}
V_88 = F_75 ( V_14 , L_24 ) ;
if( V_88 )
{
log = F_4 ( L_25 , V_90 -> V_93 + 1900 , V_90 -> V_94 + 1 , V_90 -> V_95 , V_90 -> V_96 , V_90 -> V_97 , V_90 -> V_98 , type , V_70 ) ;
fputs ( log , V_88 ) ;
fclose ( V_88 ) ;
}
}
