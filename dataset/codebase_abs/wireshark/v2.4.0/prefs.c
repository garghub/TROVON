const char * F_1 ( T_1 * V_1 )
{
return V_1 -> V_2 ;
}
const char * F_2 ( T_1 * V_1 )
{
return V_1 -> V_3 ;
}
int F_3 ( T_1 * V_1 )
{
return V_1 -> type ;
}
T_2 F_4 ( T_1 * V_1 )
{
return V_1 -> V_4 ;
}
const char * F_5 ( T_1 * V_1 )
{
return V_1 -> V_5 ;
}
T_3 F_6 ( T_1 * V_1 )
{
return V_1 -> V_6 . V_7 ;
}
void * F_7 ( T_1 * V_1 )
{
return V_1 -> V_8 ;
}
void F_8 ( T_1 * V_1 , void * V_8 )
{
V_1 -> V_8 = V_8 ;
}
int F_9 ( T_1 * V_1 )
{
return V_1 -> V_9 ;
}
void
F_10 ( void )
{
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = F_11 ( F_12 () ) ;
V_12 = F_11 ( F_12 () ) ;
}
static void
F_13 ( T_1 * V_1 )
{
F_14 ( * V_1 -> V_13 . string ) ;
* V_1 -> V_13 . string = NULL ;
F_14 ( V_1 -> V_14 . string ) ;
V_1 -> V_14 . string = NULL ;
}
static void
F_15 ( T_4 V_15 , T_4 T_5 V_16 )
{
T_1 * V_1 = ( T_1 * ) V_15 ;
int type = V_1 -> type ;
F_16 ( type ) ;
switch ( type ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
F_14 ( * V_1 -> V_13 . string ) ;
* V_1 -> V_13 . string = NULL ;
F_14 ( V_1 -> V_14 . string ) ;
V_1 -> V_14 . string = NULL ;
break;
case V_28 :
case V_29 :
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = NULL ;
F_17 ( F_12 () , V_1 -> V_14 . V_30 ) ;
V_1 -> V_14 . V_30 = NULL ;
break;
case V_31 :
if ( strcmp ( V_1 -> V_5 , L_1 ) == 0 )
V_1 -> V_32 . V_33 = TRUE ;
V_1 -> V_34 . V_35 ( V_1 ) ;
break;
}
F_14 ( V_1 ) ;
}
static T_6
F_18 ( T_7 * V_36 , T_4 V_15 V_16 )
{
if ( V_36 -> V_10 ) {
F_19 ( V_36 -> V_10 , F_15 , NULL ) ;
F_20 ( V_36 -> V_10 ) ;
}
V_36 -> V_10 = NULL ;
V_36 -> V_37 = 0 ;
if ( V_36 -> V_38 ) {
F_21 ( V_36 , F_18 , NULL ) ;
}
return 0 ;
}
void
F_22 ( void )
{
F_23 ( F_18 , NULL ) ;
F_24 () ;
F_14 ( V_10 . V_39 ) ;
F_14 ( V_40 ) ;
V_40 = NULL ;
}
void F_25 ( T_8 V_41 )
{
V_42 = V_41 ;
}
static T_7 *
F_26 ( T_7 * V_43 , const char * V_5 , const char * V_3 ,
const char * V_2 , void (* F_27)( void ) ,
const T_8 V_44 )
{
return F_28 ( V_43 , V_5 , V_3 , V_2 ,
FALSE , F_27 , V_44 ) ;
}
static void
F_29 ( T_7 * V_43 , const char * V_5 , const char * V_3 )
{
T_7 * V_36 = ( T_7 * ) F_30 ( V_11 , V_5 , V_45 ) ;
if ( ! V_36 )
return;
if ( V_43 == NULL ) {
F_30 ( V_12 , V_3 , V_45 ) ;
} else if ( V_43 -> V_38 ) {
F_30 ( V_43 -> V_38 , V_3 , V_45 ) ;
}
F_18 ( V_36 , NULL ) ;
F_17 ( F_12 () , V_36 ) ;
}
static T_7 *
F_31 ( T_7 * V_43 , const char * V_3 , const char * V_2 ,
void (* F_27)( void ) )
{
return F_28 ( V_43 , NULL , V_3 , V_2 ,
TRUE , F_27 ,
V_43 ? V_43 -> V_44 : FALSE ) ;
}
static T_7 *
F_28 ( T_7 * V_43 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_8 V_46 , void (* F_27)( void ) ,
T_8 V_44 )
{
T_7 * V_36 ;
const char * V_47 ;
T_9 V_48 ;
if ( ( V_36 = F_32 ( V_43 , V_3 ) ) ) {
V_36 -> V_5 = V_5 ;
V_36 -> F_27 = F_27 ;
V_36 -> V_2 = V_2 ;
if ( F_33 ( V_5 ) == NULL ) {
F_34 ( V_11 , V_5 , V_36 ,
V_45 ) ;
}
return V_36 ;
}
V_36 = F_35 ( F_12 () , T_7 ) ;
V_36 -> V_5 = V_5 ;
V_36 -> V_3 = V_3 ;
V_36 -> V_2 = V_2 ;
V_36 -> F_27 = F_27 ;
V_36 -> V_10 = NULL ;
V_36 -> V_43 = V_43 ;
V_36 -> V_38 = NULL ;
V_36 -> V_37 = 0 ;
V_36 -> V_49 = FALSE ;
V_36 -> V_50 = FALSE ;
V_36 -> V_44 = V_44 ;
if ( V_5 != NULL ) {
for ( V_47 = V_5 ; ( V_48 = * V_47 ) != '\0' ; V_47 ++ ) {
if ( ! ( F_36 ( V_48 ) || F_37 ( V_48 ) || V_48 == '_' ||
V_48 == '-' || V_48 == '.' ) )
F_38 ( L_2 , V_5 ) ;
}
F_39 ( F_33 ( V_5 ) == NULL ) ;
F_34 ( V_11 , V_5 , V_36 , V_45 ) ;
} else {
F_39 ( V_46 ) ;
}
if ( V_43 == NULL ) {
F_34 ( V_12 , V_3 , V_36 , V_45 ) ;
} else {
if ( V_43 -> V_38 == NULL )
V_43 -> V_38 = F_11 ( F_12 () ) ;
F_34 ( V_43 -> V_38 , V_3 , V_36 , V_45 ) ;
}
return V_36 ;
}
T_7 *
F_40 ( int V_51 , void (* F_27)( void ) )
{
T_10 * V_52 ;
if ( V_53 == NULL ) {
F_41 () ;
F_42 () ;
}
V_52 = F_43 ( V_51 ) ;
if ( V_52 == NULL )
F_38 ( L_3 ) ;
return F_26 ( V_53 ,
F_44 ( V_51 ) ,
F_45 ( V_52 ) ,
F_46 ( V_51 ) , F_27 , TRUE ) ;
}
void
F_47 ( int V_51 )
{
T_10 * V_52 = F_43 ( V_51 ) ;
if ( V_52 == NULL )
F_38 ( L_4 ) ;
F_29 ( V_53 ,
F_44 ( V_51 ) ,
F_45 ( V_52 ) ) ;
}
T_7 *
F_48 ( const char * V_54 , int V_51 , void (* F_27)( void ) )
{
T_10 * V_52 ;
T_7 * V_55 ;
T_7 * V_56 ;
char * V_57 = NULL , * V_58 = NULL , * V_59 = NULL ;
if ( V_53 == NULL ) {
F_41 () ;
F_42 () ;
}
V_55 = V_53 ;
if ( V_54 ) {
V_59 = V_58 = F_49 ( V_54 ) ;
while ( V_58 && * V_58 ) {
if ( ( V_57 = strchr ( V_58 , '/' ) ) )
* V_57 ++ = '\0' ;
if ( ! ( V_56 = F_32 ( V_55 , V_58 ) ) ) {
V_58 = F_50 ( F_12 () , V_58 ) ,
V_56 = F_31 ( V_55 , V_58 , V_58 , NULL ) ;
}
V_55 = V_56 ;
V_58 = V_57 ;
}
F_14 ( V_59 ) ;
}
V_52 = F_43 ( V_51 ) ;
if ( V_52 == NULL )
F_38 ( L_5 ) ;
return F_26 ( V_55 ,
F_44 ( V_51 ) ,
F_45 ( V_52 ) ,
F_46 ( V_51 ) , F_27 , TRUE ) ;
}
T_7 *
F_51 ( int V_51 )
{
T_7 * V_36 ;
T_10 * V_52 ;
if ( V_53 == NULL ) {
F_41 () ;
F_42 () ;
}
V_52 = F_43 ( V_51 ) ;
if ( V_52 == NULL )
F_38 ( L_6 ) ;
V_36 = F_26 ( V_53 ,
F_44 ( V_51 ) ,
F_45 ( V_52 ) ,
F_46 ( V_51 ) , NULL , TRUE ) ;
V_36 -> V_50 = TRUE ;
return V_36 ;
}
T_7 *
F_52 ( const char * V_5 , const char * V_3 ,
const char * V_2 , void (* F_27)( void ) )
{
if ( V_60 == NULL ) {
F_41 () ;
F_42 () ;
}
return F_26 ( V_60 , V_5 , V_3 , V_2 ,
F_27 , TRUE ) ;
}
T_7 *
F_33 ( const char * V_5 )
{
return ( T_7 * ) F_53 ( V_11 , V_5 , V_45 ) ;
}
static T_7 *
F_32 ( T_7 * V_43 , const char * V_5 )
{
return ( T_7 * ) F_53 ( V_43 ? V_43 -> V_38 : V_12 , V_5 , V_45 ) ;
}
static T_8
F_54 ( const void * T_11 V_16 , void * V_61 , void * V_15 )
{
T_7 * V_36 = ( T_7 * ) V_61 ;
T_12 * V_62 = ( T_12 * ) V_15 ;
if ( ! V_36 -> V_50 )
V_62 -> V_63 = (* V_62 -> V_64 )( V_36 , V_62 -> T_5 ) ;
return ( V_62 -> V_63 != 0 ) ;
}
static T_6
F_55 ( T_13 * V_65 , T_14 V_64 ,
T_4 T_5 )
{
T_12 V_62 ;
if ( V_65 == NULL )
V_65 = V_12 ;
V_62 . V_64 = V_64 ;
V_62 . T_5 = T_5 ;
V_62 . V_63 = 0 ;
F_56 ( V_65 , F_54 , & V_62 ) ;
return V_62 . V_63 ;
}
T_8
F_57 ( T_7 * V_36 )
{
if ( V_36 -> V_38 == NULL ) {
return FALSE ;
}
if ( F_58 ( V_36 -> V_38 ) ) {
return FALSE ;
}
return TRUE ;
}
T_6
F_23 ( T_14 V_64 , T_4 T_5 )
{
return F_55 ( V_11 , V_64 , T_5 ) ;
}
T_6
F_21 ( T_7 * V_36 , T_14 V_64 ,
T_4 T_5 )
{
return F_55 ( ( V_36 ) ? V_36 -> V_38 : V_12 , V_64 , T_5 ) ;
}
static T_8
F_59 ( const void * T_11 V_16 , void * V_61 , void * V_15 V_16 )
{
T_7 * V_36 = ( T_7 * ) V_61 ;
if ( V_36 -> V_50 )
return FALSE ;
if ( V_36 -> V_49 ) {
if ( V_36 -> F_27 != NULL )
(* V_36 -> F_27 )() ;
V_36 -> V_49 = FALSE ;
}
if ( V_36 -> V_38 )
F_56 ( V_36 -> V_38 , F_59 , NULL ) ;
return FALSE ;
}
void
F_60 ( void )
{
F_56 ( V_11 , F_59 , NULL ) ;
}
void
F_61 ( T_7 * V_36 )
{
if ( V_36 && V_36 -> V_49 )
F_59 ( NULL , V_36 , NULL ) ;
}
static T_1 *
F_62 ( T_7 * V_36 , const char * V_5 , const char * V_3 ,
const char * V_2 , int type )
{
T_1 * V_66 ;
const T_15 * V_47 ;
const char * V_67 = ( V_36 -> V_5 != NULL ) ? V_36 -> V_5 : V_36 -> V_43 -> V_5 ;
V_66 = F_63 ( T_1 , 1 ) ;
V_66 -> V_5 = V_5 ;
V_66 -> V_3 = V_3 ;
V_66 -> V_2 = V_2 ;
V_66 -> type = type ;
V_66 -> V_4 = V_68 ;
if ( V_3 != NULL )
V_66 -> V_9 = V_36 -> V_37 ;
else
V_66 -> V_9 = - 1 ;
for ( V_47 = V_5 ; * V_47 != '\0' ; V_47 ++ )
if ( ! ( F_36 ( * V_47 ) || F_37 ( * V_47 ) || * V_47 == '_' || * V_47 == '.' ) )
F_38 ( L_7 , V_36 -> V_5 , V_5 ) ;
if ( F_64 ( V_36 , V_5 ) != NULL )
F_38 ( L_8 , V_5 ) ;
if ( ( ! F_65 ( type ) ) &&
( V_36 -> V_5 != NULL ) ) {
if ( ! ( ( strncmp ( V_5 , V_36 -> V_5 , strlen ( V_36 -> V_5 ) ) != 0 ) ||
( ( ( V_5 [ strlen ( V_36 -> V_5 ) ] ) != '.' ) && ( ( V_5 [ strlen ( V_36 -> V_5 ) ] ) != '_' ) ) ) )
F_38 ( L_9 , V_5 ) ;
}
if ( V_66 -> V_3 ) {
const char * V_69 ;
if ( V_66 -> type != V_21 && F_66 ( V_66 -> V_3 , - 1 ) > 80 ) {
F_38 ( L_10 , V_67 , V_66 -> V_5 , V_66 -> V_3 ) ;
}
if ( ! F_67 ( V_66 -> V_3 , - 1 , NULL ) ) {
F_38 ( L_11 , V_67 , V_66 -> V_5 ) ;
}
for ( V_69 = V_66 -> V_3 ; * V_69 ; V_69 = F_68 ( V_69 ) ) {
if ( ! F_69 ( F_70 ( V_69 ) ) ) {
F_38 ( L_12 , V_67 , V_66 -> V_5 ) ;
}
}
}
if ( V_66 -> V_2 ) {
if ( ! F_67 ( V_66 -> V_2 , - 1 , NULL ) ) {
F_38 ( L_13 , V_67 , V_66 -> V_5 ) ;
}
}
V_36 -> V_10 = F_71 ( V_36 -> V_10 , V_66 ) ;
if ( V_3 != NULL )
V_36 -> V_37 ++ ;
return V_66 ;
}
static T_16
F_72 ( T_17 V_70 , T_17 V_71 )
{
const T_1 * V_1 = ( const T_1 * ) V_70 ;
const char * V_5 = ( const char * ) V_71 ;
return strcmp ( V_5 , V_1 -> V_5 ) ;
}
static T_8
F_73 ( const void * T_11 V_16 , void * V_61 , void * V_15 )
{
T_18 * V_72 = ( T_18 * ) V_15 ;
T_19 * V_73 ;
T_7 * V_36 = ( T_7 * ) V_61 ;
if ( V_36 == NULL )
return FALSE ;
V_73 = F_74 ( V_36 -> V_10 , V_72 -> V_5 ,
F_72 ) ;
if ( V_73 == NULL )
return FALSE ;
V_72 -> V_73 = V_73 ;
V_72 -> V_74 = V_36 ;
return TRUE ;
}
static struct V_66 *
F_75 ( T_7 * V_36 , const char * V_5 ,
T_7 * * V_75 )
{
T_18 V_72 ;
T_19 * V_73 ;
if ( V_36 == NULL )
return NULL ;
V_73 = F_74 ( V_36 -> V_10 , V_5 ,
F_72 ) ;
V_72 . V_74 = NULL ;
if ( V_73 == NULL )
{
V_72 . V_73 = NULL ;
if ( V_36 -> V_38 != NULL )
{
V_72 . V_5 = V_5 ;
F_56 ( V_36 -> V_38 , F_73 , & V_72 ) ;
}
V_73 = V_72 . V_73 ;
}
if ( V_73 == NULL )
return NULL ;
if ( V_75 )
* V_75 = V_72 . V_74 ? V_72 . V_74 : V_36 ;
return (struct V_66 * ) V_73 -> V_15 ;
}
struct V_66 *
F_64 ( T_7 * V_36 , const char * V_5 )
{
return F_75 ( V_36 , V_5 , NULL ) ;
}
T_8
F_76 ( const char * V_5 )
{
T_7 * V_76 = F_33 ( V_5 ) ;
return ( V_76 != NULL && ! V_76 -> V_50 ) ;
}
const char *
F_77 ( const char * V_5 )
{
T_7 * V_76 = F_33 ( V_5 ) ;
return ( V_76 != NULL && ! V_76 -> V_50 ) ? V_76 -> V_3 : NULL ;
}
void
F_78 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_6 V_77 , T_6 * V_78 )
{
T_1 * V_66 ;
V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 ,
V_19 ) ;
V_66 -> V_13 . V_79 = V_78 ;
V_66 -> V_14 . V_79 = * V_78 ;
F_39 ( V_77 > 0 && V_77 != 1 && V_77 < 37 ) ;
V_66 -> V_6 . V_77 = V_77 ;
}
static void
F_79 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
struct V_80 * V_34 , T_6 * V_78 )
{
T_1 * V_66 ;
V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 ,
V_31 ) ;
V_66 -> V_34 = * V_34 ;
V_66 -> V_13 . V_79 = V_78 ;
V_66 -> V_14 . V_79 = * V_78 ;
}
void
F_80 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_8 * V_78 )
{
T_1 * V_66 ;
V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 ,
V_17 ) ;
V_66 -> V_13 . V_81 = V_78 ;
V_66 -> V_14 . V_33 = * V_78 ;
}
T_8 F_81 ( T_1 * V_1 , T_8 V_61 , T_20 V_82 )
{
T_8 V_83 = FALSE ;
switch ( V_82 )
{
case V_84 :
if ( V_1 -> V_14 . V_33 != V_61 ) {
V_1 -> V_14 . V_33 = V_61 ;
V_83 = TRUE ;
}
break;
case V_85 :
if ( V_1 -> V_32 . V_33 != V_61 ) {
V_1 -> V_32 . V_33 = V_61 ;
V_83 = TRUE ;
}
break;
case V_86 :
if ( * V_1 -> V_13 . V_81 != V_61 ) {
* V_1 -> V_13 . V_81 = V_61 ;
V_83 = TRUE ;
}
break;
default:
F_82 () ;
break;
}
return V_83 ;
}
void F_83 ( T_1 * V_1 , T_20 V_82 )
{
switch ( V_82 )
{
case V_84 :
V_1 -> V_14 . V_33 = ! V_1 -> V_14 . V_33 ;
break;
case V_85 :
V_1 -> V_32 . V_33 = ! V_1 -> V_32 . V_33 ;
break;
case V_86 :
* V_1 -> V_13 . V_81 = ! ( * V_1 -> V_13 . V_81 ) ;
break;
default:
F_82 () ;
break;
}
}
T_8 F_84 ( T_1 * V_1 , T_20 V_82 )
{
switch ( V_82 )
{
case V_84 :
return V_1 -> V_14 . V_33 ;
break;
case V_85 :
return V_1 -> V_32 . V_33 ;
break;
case V_86 :
return * V_1 -> V_13 . V_81 ;
break;
default:
F_82 () ;
break;
}
return FALSE ;
}
void
F_85 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_16 * V_78 , const T_21 * V_87 ,
T_8 V_88 )
{
T_1 * V_66 ;
V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 ,
V_18 ) ;
V_66 -> V_13 . V_89 = V_78 ;
V_66 -> V_14 . V_90 = * V_78 ;
V_66 -> V_6 . V_91 . V_87 = V_87 ;
V_66 -> V_6 . V_91 . V_88 = V_88 ;
}
T_8 F_86 ( T_1 * V_1 , T_16 V_61 , T_20 V_82 )
{
T_8 V_83 = FALSE ;
switch ( V_82 )
{
case V_84 :
if ( V_1 -> V_14 . V_90 != V_61 ) {
V_1 -> V_14 . V_90 = V_61 ;
V_83 = TRUE ;
}
break;
case V_85 :
if ( V_1 -> V_32 . V_90 != V_61 ) {
V_1 -> V_32 . V_90 = V_61 ;
V_83 = TRUE ;
}
break;
case V_86 :
if ( * V_1 -> V_13 . V_89 != V_61 ) {
* V_1 -> V_13 . V_89 = V_61 ;
V_83 = TRUE ;
}
break;
default:
F_82 () ;
break;
}
return V_83 ;
}
T_16 F_87 ( T_1 * V_1 , T_20 V_82 )
{
switch ( V_82 )
{
case V_84 :
return V_1 -> V_14 . V_90 ;
break;
case V_85 :
return V_1 -> V_32 . V_90 ;
break;
case V_86 :
return * V_1 -> V_13 . V_89 ;
break;
default:
F_82 () ;
break;
}
return 0 ;
}
const T_21 * F_88 ( T_1 * V_1 )
{
return V_1 -> V_6 . V_91 . V_87 ;
}
T_8 F_89 ( T_1 * V_1 )
{
return V_1 -> V_6 . V_91 . V_88 ;
}
static void
F_90 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
char * * V_78 , int type ,
struct V_80 * V_34 ,
T_8 V_92 )
{
T_1 * V_1 ;
T_15 * V_93 ;
V_1 = F_62 ( V_36 , V_5 , V_3 , V_2 , type ) ;
V_93 = * V_78 ;
if ( * V_78 == NULL ) {
* V_78 = F_49 ( L_14 ) ;
} else {
* V_78 = F_49 ( * V_78 ) ;
}
if ( V_92 ) {
F_14 ( V_93 ) ;
}
V_1 -> V_13 . string = V_78 ;
V_1 -> V_14 . string = F_49 ( * V_78 ) ;
V_1 -> V_32 . string = NULL ;
if ( type == V_31 ) {
F_39 ( V_34 ) ;
V_1 -> V_34 = * V_34 ;
}
}
T_8
F_91 ( T_1 * V_1 , const char * V_61 , T_20 V_82 )
{
T_8 V_83 = FALSE ;
switch ( V_82 )
{
case V_84 :
if ( * V_1 -> V_14 . string ) {
if ( strcmp ( V_1 -> V_14 . string , V_61 ) != 0 ) {
V_83 = TRUE ;
F_14 ( V_1 -> V_14 . string ) ;
V_1 -> V_14 . string = F_49 ( V_61 ) ;
}
} else if ( V_61 ) {
V_1 -> V_14 . string = F_49 ( V_61 ) ;
}
break;
case V_85 :
if ( V_1 -> V_32 . string ) {
if ( strcmp ( V_1 -> V_32 . string , V_61 ) != 0 ) {
V_83 = TRUE ;
F_14 ( V_1 -> V_32 . string ) ;
V_1 -> V_32 . string = F_49 ( V_61 ) ;
}
} else if ( V_61 ) {
V_1 -> V_32 . string = F_49 ( V_61 ) ;
}
break;
case V_86 :
if ( * V_1 -> V_13 . string ) {
if ( strcmp ( * V_1 -> V_13 . string , V_61 ) != 0 ) {
V_83 = TRUE ;
F_14 ( * V_1 -> V_13 . string ) ;
* V_1 -> V_13 . string = F_49 ( V_61 ) ;
}
} else if ( V_61 ) {
* V_1 -> V_13 . string = F_49 ( V_61 ) ;
}
break;
default:
F_82 () ;
break;
}
return V_83 ;
}
char * F_92 ( T_1 * V_1 , T_20 V_82 )
{
switch ( V_82 )
{
case V_84 :
return V_1 -> V_14 . string ;
case V_85 :
return V_1 -> V_32 . string ;
case V_86 :
return * V_1 -> V_13 . string ;
default:
F_82 () ;
break;
}
return NULL ;
}
static void
F_93 ( T_1 * V_1 )
{
F_14 ( * V_1 -> V_13 . string ) ;
* V_1 -> V_13 . string = F_49 ( V_1 -> V_14 . string ) ;
}
void
F_94 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
const char * * V_78 )
{
F_95 (cast-qual)
F_90 ( V_36 , V_5 , V_3 , V_2 ,
( char * * ) V_78 , V_24 , NULL , FALSE ) ;
F_96 (cast-qual)
}
void
F_97 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
const char * * V_78 , T_8 V_94 )
{
F_95 (cast-qual)
F_90 ( V_36 , V_5 , V_3 , V_2 , ( char * * ) V_78 ,
V_94 ? V_25 : V_26 , NULL , FALSE ) ;
F_96 (cast-qual)
}
void
F_98 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
const char * * V_78 )
{
F_95 (cast-qual)
F_90 ( V_36 , V_5 , V_3 , V_2 ,
( char * * ) V_78 , V_27 , NULL , FALSE ) ;
F_96 (cast-qual)
}
static void
F_99 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_22 * * V_78 , T_3 V_7 , int type )
{
T_1 * V_66 ;
V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 , type ) ;
V_66 -> V_6 . V_7 = V_7 ;
if ( * V_78 == NULL )
* V_78 = F_100 ( F_12 () ) ;
V_66 -> V_13 . V_30 = V_78 ;
V_66 -> V_14 . V_30 = F_101 ( F_12 () , * V_78 ) ;
V_66 -> V_32 . V_30 = NULL ;
}
void
F_102 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_22 * * V_78 , T_3 V_7 )
{
F_99 ( V_36 , V_5 , V_3 ,
V_2 , V_78 , V_7 , V_28 ) ;
}
T_8
F_103 ( T_1 * V_1 , const T_15 * V_61 ,
T_8 V_95 , T_8 * V_83 )
{
T_22 * V_96 ;
if ( F_104 ( F_12 () , & V_96 , V_61 , V_1 -> V_6 . V_7 ,
V_95 ) != V_97 ) {
return FALSE ;
}
if ( ! F_105 ( * V_1 -> V_13 . V_30 , V_96 ) ) {
* V_83 = TRUE ;
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = V_96 ;
} else {
F_17 ( F_12 () , V_96 ) ;
}
return TRUE ;
}
T_8
F_106 ( T_1 * V_1 , const T_15 * V_61 )
{
T_22 * V_96 ;
if ( F_104 ( F_12 () , & V_96 , V_61 , V_1 -> V_6 . V_7 ,
TRUE ) != V_97 ) {
return FALSE ;
}
if ( ! F_105 ( V_1 -> V_32 . V_30 , V_96 ) ) {
F_17 ( F_12 () , V_1 -> V_32 . V_30 ) ;
V_1 -> V_32 . V_30 = V_96 ;
} else {
F_17 ( F_12 () , V_96 ) ;
}
return TRUE ;
}
T_8 F_107 ( T_1 * V_1 , T_22 * V_61 , T_20 V_82 )
{
T_8 V_83 = FALSE ;
switch ( V_82 )
{
case V_84 :
if ( ! F_105 ( V_1 -> V_14 . V_30 , V_61 ) ) {
F_17 ( F_12 () , V_1 -> V_14 . V_30 ) ;
V_1 -> V_14 . V_30 = F_101 ( F_12 () , V_61 ) ;
V_83 = TRUE ;
}
break;
case V_85 :
if ( ! F_105 ( V_1 -> V_32 . V_30 , V_61 ) ) {
F_17 ( F_12 () , V_1 -> V_32 . V_30 ) ;
V_1 -> V_32 . V_30 = F_101 ( F_12 () , V_61 ) ;
V_83 = TRUE ;
}
break;
case V_86 :
if ( ! F_105 ( * V_1 -> V_13 . V_30 , V_61 ) ) {
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = F_101 ( F_12 () , V_61 ) ;
V_83 = TRUE ;
}
break;
default:
F_82 () ;
break;
}
return V_83 ;
}
T_22 * F_108 ( T_1 * V_1 , T_20 V_82 )
{
switch ( V_82 )
{
case V_84 :
return V_1 -> V_14 . V_30 ;
case V_85 :
return V_1 -> V_32 . V_30 ;
break;
case V_86 :
return * V_1 -> V_13 . V_30 ;
break;
default:
F_82 () ;
break;
}
return NULL ;
}
T_22 * F_109 ( const char * V_98 , const char * V_99 )
{
return F_108 ( F_64 ( F_33 ( V_98 ) , V_99 ) , V_86 ) ;
}
void
F_110 ( T_1 * V_1 , T_3 V_100 )
{
F_111 ( F_12 () , V_1 -> V_13 . V_30 , V_100 ) ;
}
void
F_112 ( T_1 * V_1 , T_3 V_100 )
{
F_113 ( F_12 () , V_1 -> V_13 . V_30 , V_100 ) ;
}
void
F_114 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 ,
const char * V_2 )
{
F_62 ( V_36 , V_5 , V_3 , V_2 , V_21 ) ;
}
extern void
F_115 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_23 * V_101 )
{
T_1 * V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 , V_22 ) ;
V_66 -> V_13 . V_101 = V_101 ;
}
extern void
F_116 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_23 * V_101 )
{
T_1 * V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 , V_22 ) ;
V_66 -> V_13 . V_101 = V_101 ;
V_66 -> V_4 = V_102 ;
}
struct V_103 * F_117 ( T_1 * V_1 )
{
return V_1 -> V_13 . V_101 ;
}
void
F_118 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
T_24 * V_104 )
{
T_1 * V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 , V_23 ) ;
V_66 -> V_13 . V_105 = V_104 ;
V_66 -> V_14 . V_104 = * V_104 ;
}
T_8 F_119 ( T_1 * V_1 , T_24 V_61 , T_20 V_82 )
{
T_8 V_83 = FALSE ;
switch ( V_82 )
{
case V_84 :
if ( ( V_1 -> V_14 . V_104 . V_106 != V_61 . V_106 ) &&
( V_1 -> V_14 . V_104 . V_107 != V_61 . V_107 ) &&
( V_1 -> V_14 . V_104 . V_108 != V_61 . V_108 ) ) {
V_83 = TRUE ;
V_1 -> V_14 . V_104 = V_61 ;
}
break;
case V_85 :
if ( ( V_1 -> V_32 . V_104 . V_106 != V_61 . V_106 ) &&
( V_1 -> V_32 . V_104 . V_107 != V_61 . V_107 ) &&
( V_1 -> V_32 . V_104 . V_108 != V_61 . V_108 ) ) {
V_83 = TRUE ;
V_1 -> V_32 . V_104 = V_61 ;
}
break;
case V_86 :
if ( ( V_1 -> V_13 . V_105 -> V_106 != V_61 . V_106 ) &&
( V_1 -> V_13 . V_105 -> V_107 != V_61 . V_107 ) &&
( V_1 -> V_13 . V_105 -> V_108 != V_61 . V_108 ) ) {
V_83 = TRUE ;
* V_1 -> V_13 . V_105 = V_61 ;
}
break;
default:
F_82 () ;
break;
}
return V_83 ;
}
T_24 * F_120 ( T_1 * V_1 , T_20 V_82 )
{
switch ( V_82 )
{
case V_84 :
return & V_1 -> V_14 . V_104 ;
case V_85 :
return & V_1 -> V_32 . V_104 ;
break;
case V_86 :
return V_1 -> V_13 . V_105 ;
break;
default:
F_82 () ;
break;
}
return NULL ;
}
static void
F_121 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
struct V_80 * V_34 ,
T_25 V_109 ,
T_19 * * V_110 )
{
T_1 * V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 , V_31 ) ;
V_66 -> V_34 = * V_34 ;
V_109 ( V_66 , V_110 ) ;
}
void
F_122 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 ,
struct V_80 * V_34 ,
void * * T_26 V_16 )
{
T_1 * V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 , V_31 ) ;
V_66 -> V_34 = * V_34 ;
}
void F_123 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 , T_22 * * V_78 ,
T_3 V_7 )
{
F_99 ( V_36 , V_5 , V_3 ,
V_2 , V_78 , V_7 , V_29 ) ;
}
void F_124 ( T_7 * V_36 , const char * V_5 ,
const char * V_3 , const char * V_2 , T_6 * V_78 )
{
T_1 * V_66 ;
V_66 = F_62 ( V_36 , V_5 , V_3 , V_2 ,
V_20 ) ;
V_66 -> V_13 . V_79 = V_78 ;
V_66 -> V_14 . V_79 = * V_78 ;
V_66 -> V_6 . V_77 = 10 ;
}
T_8 F_125 ( T_1 * V_1 , T_6 V_61 , T_8 V_111 )
{
switch( V_1 -> type )
{
case V_20 :
* V_1 -> V_13 . V_79 = V_61 ;
break;
case V_29 :
if ( V_111 )
{
if ( ( ( * V_1 -> V_13 . V_30 ) -> V_112 == 1 ) &&
( ( * V_1 -> V_13 . V_30 ) -> V_113 [ 0 ] . V_114 == ( * V_1 -> V_13 . V_30 ) -> V_113 [ 0 ] . V_115 ) ) {
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = F_100 ( F_12 () ) ;
}
}
F_110 ( V_1 , V_61 ) ;
break;
default:
break;
}
return TRUE ;
}
T_8 F_126 ( T_1 * V_1 , T_6 V_61 , T_8 V_116 )
{
switch( V_1 -> type )
{
case V_20 :
if ( V_116 ) {
* V_1 -> V_13 . V_79 = V_1 -> V_14 . V_79 ;
} else {
* V_1 -> V_13 . V_79 = 0 ;
}
break;
case V_29 :
F_112 ( V_1 , V_61 ) ;
break;
default:
break;
}
return TRUE ;
}
void
F_127 ( T_7 * V_36 , const char * V_5 )
{
F_62 ( V_36 , V_5 , NULL , NULL , V_117 ) ;
}
extern T_8
F_128 ( T_1 * V_1 )
{
if ( V_1 )
return ( F_65 ( V_1 -> type ) ? TRUE : FALSE ) ;
return TRUE ;
}
extern T_27
F_129 ( T_1 * V_1 )
{
if ( V_1 ) {
F_130 ( V_1 -> type ) ;
return V_118 ;
}
return V_119 ;
}
T_6
F_131 ( T_1 * V_1 , T_4 T_28 V_16 )
{
switch ( V_1 -> type ) {
case V_20 :
V_1 -> V_32 . V_79 = * V_1 -> V_13 . V_79 ;
break;
case V_19 :
V_1 -> V_32 . V_79 = * V_1 -> V_13 . V_79 ;
break;
case V_17 :
V_1 -> V_32 . V_33 = * V_1 -> V_13 . V_81 ;
break;
case V_18 :
V_1 -> V_32 . V_90 = * V_1 -> V_13 . V_89 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
F_14 ( V_1 -> V_32 . string ) ;
V_1 -> V_32 . string = F_49 ( * V_1 -> V_13 . string ) ;
break;
case V_29 :
case V_28 :
F_17 ( F_12 () , V_1 -> V_32 . V_30 ) ;
V_1 -> V_32 . V_30 = F_101 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
break;
case V_23 :
V_1 -> V_32 . V_104 = * V_1 -> V_13 . V_105 ;
break;
case V_21 :
case V_22 :
case V_31 :
break;
case V_117 :
F_82 () ;
break;
}
return 0 ;
}
T_6
F_132 ( T_1 * V_1 , T_4 V_120 )
{
T_29 * V_121 = ( T_29 * ) V_120 ;
T_30 V_122 = NULL ;
T_31 V_123 = NULL ;
switch ( V_1 -> type ) {
case V_20 :
if ( * V_1 -> V_13 . V_79 != V_1 -> V_32 . V_79 ) {
V_121 -> V_36 -> V_49 = TRUE ;
if ( V_121 -> V_124 ) {
if ( * V_1 -> V_13 . V_79 != V_1 -> V_14 . V_79 ) {
F_133 ( V_1 -> V_5 , * V_1 -> V_13 . V_79 ) ;
}
}
* V_1 -> V_13 . V_79 = V_1 -> V_32 . V_79 ;
if ( V_121 -> V_124 ) {
V_122 = F_134 ( V_1 -> V_5 ) ;
if ( V_122 != NULL ) {
V_123 = F_135 ( V_122 , ( T_15 * ) V_121 -> V_36 -> V_3 ) ;
if ( V_123 != NULL ) {
F_136 ( V_1 -> V_5 , * V_1 -> V_13 . V_79 , V_123 ) ;
}
}
}
}
break;
case V_19 :
if ( * V_1 -> V_13 . V_79 != V_1 -> V_32 . V_79 ) {
V_121 -> V_36 -> V_49 = TRUE ;
* V_1 -> V_13 . V_79 = V_1 -> V_32 . V_79 ;
}
break;
case V_17 :
if ( * V_1 -> V_13 . V_81 != V_1 -> V_32 . V_33 ) {
V_121 -> V_36 -> V_49 = TRUE ;
* V_1 -> V_13 . V_81 = V_1 -> V_32 . V_33 ;
}
break;
case V_18 :
if ( * V_1 -> V_13 . V_89 != V_1 -> V_32 . V_90 ) {
V_121 -> V_36 -> V_49 = TRUE ;
* V_1 -> V_13 . V_89 = V_1 -> V_32 . V_90 ;
}
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
if ( strcmp ( * V_1 -> V_13 . string , V_1 -> V_32 . string ) != 0 ) {
V_121 -> V_36 -> V_49 = TRUE ;
F_14 ( * V_1 -> V_13 . string ) ;
* V_1 -> V_13 . string = F_49 ( V_1 -> V_32 . string ) ;
}
break;
case V_29 :
if ( ! F_105 ( * V_1 -> V_13 . V_30 , V_1 -> V_32 . V_30 ) ) {
T_3 V_125 , V_126 ;
V_121 -> V_36 -> V_49 = TRUE ;
if ( V_121 -> V_124 ) {
V_122 = F_134 ( V_1 -> V_5 ) ;
if ( V_122 != NULL ) {
V_123 = F_135 ( V_122 , ( T_15 * ) V_121 -> V_36 -> V_3 ) ;
if ( V_123 != NULL ) {
for ( V_125 = 0 ; V_125 < ( * V_1 -> V_13 . V_30 ) -> V_112 ; V_125 ++ ) {
for ( V_126 = ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_114 ; V_126 < ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 ; V_126 ++ ) {
F_137 ( V_1 -> V_5 , V_126 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( V_126 ) , NULL , NULL ) ;
}
F_137 ( V_1 -> V_5 , ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 ) , NULL , NULL ) ;
}
}
}
}
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = F_101 ( F_12 () , V_1 -> V_32 . V_30 ) ;
if ( V_121 -> V_124 ) {
if ( ( V_122 != NULL ) && ( V_123 != NULL ) ) {
for ( V_125 = 0 ; V_125 < ( * V_1 -> V_13 . V_30 ) -> V_112 ; V_125 ++ ) {
for ( V_126 = ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_114 ; V_126 < ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 ; V_126 ++ ) {
F_136 ( V_1 -> V_5 , V_126 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( V_126 ) , NULL , NULL ) ;
}
F_136 ( V_1 -> V_5 , ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 ) , NULL , NULL ) ;
}
}
}
}
break;
case V_28 :
if ( ! F_105 ( * V_1 -> V_13 . V_30 , V_1 -> V_32 . V_30 ) ) {
V_121 -> V_36 -> V_49 = TRUE ;
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = F_101 ( F_12 () , V_1 -> V_32 . V_30 ) ;
}
break;
case V_23 :
* V_1 -> V_13 . V_105 = V_1 -> V_32 . V_104 ;
break;
case V_21 :
case V_22 :
case V_31 :
break;
case V_117 :
F_82 () ;
break;
}
return 0 ;
}
void
F_141 ( T_1 * V_1 ) {
switch ( V_1 -> type ) {
case V_20 :
V_1 -> V_32 . V_79 = V_1 -> V_14 . V_79 ;
break;
case V_19 :
V_1 -> V_32 . V_79 = V_1 -> V_14 . V_79 ;
break;
case V_17 :
V_1 -> V_32 . V_33 = V_1 -> V_14 . V_33 ;
break;
case V_18 :
V_1 -> V_32 . V_90 = V_1 -> V_14 . V_90 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
F_14 ( V_1 -> V_32 . string ) ;
V_1 -> V_32 . string = F_49 ( V_1 -> V_14 . string ) ;
break;
case V_29 :
case V_28 :
F_17 ( F_12 () , V_1 -> V_32 . V_30 ) ;
V_1 -> V_32 . V_30 = F_101 ( F_12 () , V_1 -> V_14 . V_30 ) ;
break;
case V_23 :
memcpy ( & V_1 -> V_32 . V_104 , & V_1 -> V_14 . V_104 , sizeof( T_24 ) ) ;
break;
case V_21 :
case V_22 :
case V_31 :
break;
case V_117 :
F_82 () ;
break;
}
}
T_6
F_142 ( T_1 * V_1 , T_4 T_28 V_16 )
{
switch ( V_1 -> type ) {
case V_19 :
case V_20 :
break;
case V_17 :
break;
case V_18 :
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
if ( V_1 -> V_32 . string != NULL ) {
F_14 ( V_1 -> V_32 . string ) ;
V_1 -> V_32 . string = NULL ;
}
break;
case V_29 :
case V_28 :
if ( V_1 -> V_32 . V_30 != NULL ) {
F_17 ( F_12 () , V_1 -> V_32 . V_30 ) ;
V_1 -> V_32 . V_30 = NULL ;
}
break;
case V_21 :
case V_22 :
case V_23 :
case V_31 :
break;
case V_117 :
F_82 () ;
break;
}
return 0 ;
}
T_6
F_143 ( T_7 * V_36 , T_32 V_64 , T_4 T_5 )
{
T_19 * V_127 ;
T_1 * V_1 ;
T_6 V_63 ;
for ( V_127 = F_144 ( V_36 -> V_10 ) ; V_127 != NULL ; V_127 = F_145 ( V_127 ) ) {
V_1 = ( T_1 * ) V_127 -> V_15 ;
if ( F_65 ( V_1 -> type ) ) {
continue;
}
V_63 = (* V_64)( V_1 , T_5 ) ;
if ( V_63 != 0 )
return V_63 ;
}
return 0 ;
}
static void
F_146 ( void )
{
if ( V_10 . V_128 < 100 || V_10 . V_128 > 10000 )
V_10 . V_128 = V_129 ;
#ifdef F_147
if ( V_10 . V_130 < 1 || V_10 . V_130 > 10 )
V_10 . V_130 = V_131 ;
#endif
if ( V_10 . V_132 < 1 ) {
V_10 . V_132 = 1 ;
}
else if ( V_10 . V_132 > V_133 ) {
V_10 . V_132 = V_133 ;
}
if ( V_10 . V_134 < V_10 . V_132 ) {
V_10 . V_134 = V_10 . V_132 ;
}
V_10 . V_134 -= V_10 . V_134 % V_10 . V_132 ;
if ( ( V_10 . V_134 / V_10 . V_132 ) > V_135 ) {
V_10 . V_134 = V_10 . V_132 * V_135 ;
}
}
static void
F_148 ( void )
{
if ( V_10 . V_136 == 0 )
V_10 . V_136 = 10 ;
if ( V_10 . V_137 == 0 )
V_10 . V_137 = 10 ;
}
static void
F_149 ( void )
{
if ( V_10 . V_138 == V_139 ||
V_10 . V_138 >= V_140 ) {
V_10 . V_138 = V_141 ;
}
}
static void F_150 ( T_1 * V_1 V_16 ) {}
static void
F_151 ( T_1 * V_1 )
{
* V_1 -> V_13 . V_79 = V_1 -> V_14 . V_79 ;
}
static T_27
F_152 ( T_1 * V_1 , const T_15 * V_61 , T_8 * V_83 )
{
T_6 V_142 ;
V_142 = ( T_6 ) strtoul ( V_61 , NULL , 10 ) ;
if ( * V_1 -> V_13 . V_79 != V_142 ) {
* V_83 = TRUE ;
* V_1 -> V_13 . V_79 = V_142 ;
}
if ( * V_1 -> V_13 . V_79 & ( V_143 | V_144 ) ) {
F_153 ( L_15 , L_16 , TRUE ) ;
}
return V_118 ;
}
static const char * F_154 ( void ) {
return L_17 ;
}
static char * F_155 ( void ) {
return F_156 (
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25 ) ;
}
static T_8 F_157 ( T_1 * V_1 ) {
return * V_1 -> V_13 . V_79 == V_1 -> V_14 . V_79 ;
}
static char * F_158 ( T_1 * V_1 , T_8 V_14 ) {
return F_156 ( L_26 , V_14 ? V_1 -> V_14 . V_79 : * V_1 -> V_13 . V_79 ) ;
}
static T_27
F_159 ( T_1 * V_1 , const T_15 * V_61 , T_8 * V_83 )
{
T_19 * V_145 ;
T_33 * V_146 ;
T_1 * V_147 ;
( * V_83 ) |= F_91 ( V_1 , V_61 , V_86 ) ;
V_147 = F_64 ( V_148 , V_149 ) ;
for ( V_145 = * V_147 -> V_13 . V_110 ; V_145 != NULL ; V_145 = V_145 -> V_150 ) {
V_146 = ( T_33 * ) V_145 -> V_15 ;
V_146 -> V_151 = F_160 ( * V_1 -> V_13 . string , V_146 ) ;
}
return V_118 ;
}
static const char *
F_161 ( void )
{
return L_27 ;
}
static char *
F_162 ( void )
{
return F_49 ( L_28 ) ;
}
static char *
F_163 ( T_1 * V_1 , T_8 V_14 )
{
T_34 * V_152 = F_164 ( L_14 ) ;
T_19 * V_145 ;
T_33 * V_146 ;
T_1 * V_147 ;
if ( V_14 )
return F_49 ( V_1 -> V_14 . string ) ;
V_147 = F_64 ( V_148 , V_149 ) ;
V_145 = ( V_147 ) ? * V_147 -> V_13 . V_110 : NULL ;
while ( V_145 ) {
T_15 * V_153 ;
V_146 = ( T_33 * ) V_145 -> V_15 ;
if ( ( V_146 -> V_154 == V_155 ) && ( V_146 -> V_156 ) ) {
V_153 = F_156 ( L_29 ,
F_165 ( V_146 -> V_154 ) ,
V_146 -> V_156 ,
V_146 -> V_157 ,
V_146 -> V_158 ? 'R' : 'U' ) ;
} else {
V_153 = F_49 ( F_165 ( V_146 -> V_154 ) ) ;
}
if ( ! V_146 -> V_151 ) {
if ( V_152 -> V_159 )
F_166 ( V_152 , L_30 ) ;
F_166 ( V_152 , V_153 ) ;
}
F_14 ( V_153 ) ;
V_145 = V_145 -> V_150 ;
}
return F_167 ( V_152 , FALSE ) ;
}
static T_8
F_168 ( T_1 * V_1 )
{
char * V_160 = F_163 ( V_1 , FALSE ) ;
T_8 V_161 = F_169 ( V_160 , V_1 -> V_14 . string ) == 0 ;
F_14 ( V_160 ) ;
return V_161 ;
}
static void
F_170 ( T_1 * V_1 )
{
* V_1 -> V_13 . V_79 = V_1 -> V_14 . V_79 ;
}
static T_27
F_171 ( T_1 * V_1 V_16 , const T_15 * V_61 V_16 , T_8 * V_83 V_16 )
{
return V_118 ;
}
static const char *
F_172 ( void )
{
return NULL ;
}
static char *
F_173 ( void )
{
return F_49 ( L_14 ) ;
}
static T_8
F_174 ( T_1 * V_1 V_16 )
{
return TRUE ;
}
static char *
F_175 ( T_1 * V_1 V_16 , T_8 V_14 V_16 )
{
return F_49 ( L_14 ) ;
}
static void
F_176 ( T_1 * V_1 , T_19 * * V_61 )
{
T_33 * V_162 , * V_163 ;
T_19 * V_164 ;
V_1 -> V_13 . V_110 = V_61 ;
V_1 -> V_14 . V_110 = NULL ;
for ( V_164 = * V_1 -> V_13 . V_110 ; V_164 != NULL ; V_164 = F_145 ( V_164 ) ) {
V_162 = ( T_33 * ) V_164 -> V_15 ;
V_163 = F_63 ( T_33 , 1 ) ;
V_163 -> V_3 = F_49 ( V_162 -> V_3 ) ;
V_163 -> V_154 = V_162 -> V_154 ;
if ( V_162 -> V_156 ) {
V_163 -> V_156 = F_49 ( V_162 -> V_156 ) ;
V_163 -> V_157 = V_162 -> V_157 ;
} else {
V_163 -> V_156 = NULL ;
V_163 -> V_157 = 0 ;
}
V_163 -> V_151 = V_162 -> V_151 ;
V_163 -> V_158 = V_162 -> V_158 ;
V_1 -> V_14 . V_110 = F_71 ( V_1 -> V_14 . V_110 , V_163 ) ;
}
}
static void
F_177 ( T_1 * V_1 )
{
F_178 ( * V_1 -> V_13 . V_110 ) ;
F_178 ( V_1 -> V_14 . V_110 ) ;
}
static void
F_179 ( T_1 * V_1 )
{
T_33 * V_162 , * V_163 ;
T_19 * V_164 ;
T_1 * V_165 ;
F_178 ( * V_1 -> V_13 . V_110 ) ;
* V_1 -> V_13 . V_110 = NULL ;
for ( V_164 = V_1 -> V_14 . V_110 ; V_164 != NULL ; V_164 = F_145 ( V_164 ) ) {
V_162 = ( T_33 * ) V_164 -> V_15 ;
V_163 = F_63 ( T_33 , 1 ) ;
V_163 -> V_3 = F_49 ( V_162 -> V_3 ) ;
V_163 -> V_154 = V_162 -> V_154 ;
if ( V_162 -> V_156 ) {
V_163 -> V_156 = F_49 ( V_162 -> V_156 ) ;
V_163 -> V_157 = V_162 -> V_157 ;
} else {
V_163 -> V_156 = NULL ;
V_163 -> V_157 = 0 ;
}
V_163 -> V_151 = V_162 -> V_151 ;
V_163 -> V_158 = V_162 -> V_158 ;
* V_1 -> V_13 . V_110 = F_71 ( * V_1 -> V_13 . V_110 , V_163 ) ;
}
V_165 = F_64 ( V_148 , V_166 ) ;
F_39 ( V_165 != NULL ) ;
F_170 ( V_165 ) ;
}
static T_27
F_180 ( T_1 * V_1 , const T_15 * V_61 , T_8 * V_83 V_16 )
{
T_19 * V_167 , * V_168 ;
T_33 * V_146 ;
T_16 V_169 ;
T_1 * V_170 , * V_165 ;
V_167 = F_181 ( V_61 ) ;
if ( V_167 == NULL )
return V_171 ;
if ( ( F_182 ( V_167 ) % 2 ) != 0 ) {
F_183 ( V_167 ) ;
return V_171 ;
}
V_168 = F_144 ( V_167 ) ;
while ( V_168 ) {
T_33 V_172 ;
V_168 = V_168 -> V_150 ;
if ( ! F_184 ( & V_172 , ( char * ) V_168 -> V_15 ) ) {
F_183 ( V_167 ) ;
return V_171 ;
}
if ( V_172 . V_154 != V_155 ) {
F_185 ( & V_168 -> V_15 ) ;
} else {
F_14 ( V_172 . V_156 ) ;
}
V_168 = V_168 -> V_150 ;
}
F_178 ( * V_1 -> V_13 . V_110 ) ;
* V_1 -> V_13 . V_110 = NULL ;
V_170 = F_64 ( V_148 , V_173 ) ;
F_39 ( V_170 != NULL ) ;
V_165 = F_64 ( V_148 , V_166 ) ;
F_39 ( V_165 != NULL ) ;
V_169 = F_182 ( V_167 ) ;
* V_165 -> V_13 . V_79 = V_169 / 2 ;
V_168 = F_144 ( V_167 ) ;
while ( V_168 ) {
V_146 = F_63 ( T_33 , 1 ) ;
V_146 -> V_3 = F_49 ( ( T_15 * ) V_168 -> V_15 ) ;
V_168 = V_168 -> V_150 ;
F_184 ( V_146 , ( char * ) V_168 -> V_15 ) ;
V_146 -> V_151 = F_160 ( * V_170 -> V_13 . string , V_146 ) ;
V_168 = V_168 -> V_150 ;
* V_1 -> V_13 . V_110 = F_71 ( * V_1 -> V_13 . V_110 , V_146 ) ;
}
F_183 ( V_167 ) ;
F_13 ( V_170 ) ;
return V_118 ;
}
static const char *
F_186 ( void )
{
return L_31 ;
}
static char *
F_187 ( void )
{
return F_49 ( L_32 ) ;
}
static T_8
F_188 ( T_1 * V_1 )
{
T_19 * V_145 = * V_1 -> V_13 . V_110 ,
* V_174 = F_144 ( V_145 ) ,
* V_175 = F_144 ( V_1 -> V_14 . V_110 ) ;
T_33 * V_146 , * V_176 ;
T_8 V_161 = TRUE ;
T_1 * V_165 ;
V_165 = F_64 ( V_148 , V_166 ) ;
if ( V_165 && * V_165 -> V_13 . V_79 != V_165 -> V_14 . V_79 ) {
V_161 = FALSE ;
} else {
while ( V_174 && V_175 ) {
V_146 = ( T_33 * ) V_174 -> V_15 ;
V_176 = ( T_33 * ) V_175 -> V_15 ;
if ( ( F_169 ( V_146 -> V_3 , V_176 -> V_3 ) != 0 ) ||
( V_146 -> V_154 != V_176 -> V_154 ) ||
( ( ( V_146 -> V_154 == V_155 ) && ( V_146 -> V_156 ) ) &&
( ( F_169 ( V_146 -> V_156 , V_176 -> V_156 ) != 0 ) ||
( V_146 -> V_158 != V_176 -> V_158 ) ) ) ) {
V_161 = FALSE ;
break;
}
V_174 = V_174 -> V_150 ;
V_175 = V_175 -> V_150 ;
}
}
return V_161 ;
}
static char *
F_189 ( T_1 * V_1 , T_8 V_14 )
{
T_19 * V_177 = V_14 ? V_1 -> V_14 . V_110 : * V_1 -> V_13 . V_110 ;
T_19 * V_145 = F_144 ( V_177 ) ;
T_19 * V_167 ;
T_33 * V_146 ;
T_15 * V_153 ;
char * V_178 ;
V_167 = NULL ;
while ( V_145 ) {
V_146 = ( T_33 * ) V_145 -> V_15 ;
V_167 = F_71 ( V_167 , F_49 ( V_146 -> V_3 ) ) ;
if ( ( V_146 -> V_154 == V_155 ) && ( V_146 -> V_156 ) ) {
V_153 = F_156 ( L_29 ,
F_165 ( V_146 -> V_154 ) ,
V_146 -> V_156 ,
V_146 -> V_157 ,
V_146 -> V_158 ? 'R' : 'U' ) ;
} else {
V_153 = F_49 ( F_165 ( V_146 -> V_154 ) ) ;
}
V_167 = F_71 ( V_167 , V_153 ) ;
V_145 = V_145 -> V_150 ;
}
V_178 = F_190 ( V_167 ) ;
F_183 ( V_167 ) ;
return V_178 ;
}
static void
F_191 ( T_1 * V_1 , T_19 * * V_179 )
{
T_19 * V_180 = * V_179 ,
* V_181 = NULL ;
while ( V_180 ) {
V_181 = F_71 ( V_181 , F_49 ( ( T_15 * ) V_180 -> V_15 ) ) ;
V_180 = V_180 -> V_150 ;
}
V_1 -> V_14 . V_110 = V_181 ;
V_1 -> V_13 . V_110 = & V_10 . V_182 ;
V_1 -> V_32 . V_33 = FALSE ;
}
static void
F_192 ( T_1 * V_1 )
{
F_183 ( V_10 . V_182 ) ;
V_10 . V_182 = NULL ;
if ( V_1 -> V_32 . V_33 == TRUE ) {
F_183 ( V_1 -> V_14 . V_110 ) ;
V_1 -> V_14 . V_110 = NULL ;
}
}
static void
F_193 ( T_1 * V_1 )
{
T_19 * V_183 = NULL , * V_181 ;
F_183 ( * V_1 -> V_13 . V_110 ) ;
for ( V_181 = V_1 -> V_14 . V_110 ; V_181 != NULL ; V_181 = F_145 ( V_181 ) ) {
V_183 = F_71 ( V_183 , F_49 ( ( T_15 * ) V_181 -> V_15 ) ) ;
}
* V_1 -> V_13 . V_110 = V_183 ;
}
static T_27
F_194 ( T_1 * V_1 , const T_15 * V_61 , T_8 * V_83 V_16 )
{
T_19 * V_167 = F_181 ( V_61 ) ;
T_19 * V_168 ;
T_15 * V_184 ;
int V_125 ;
if ( V_167 == NULL )
return V_171 ;
F_192 ( V_1 ) ;
V_168 = F_144 ( V_167 ) ;
if ( ! ( * ( T_15 * ) V_168 -> V_15 ) ) {
for ( V_125 = 0 ; V_125 < V_185 ; V_125 ++ ) {
V_184 = F_49 ( V_186 [ V_125 ] ) ;
V_10 . V_182 = F_71 ( V_10 . V_182 , V_184 ) ;
}
}
while ( V_168 ) {
T_8 V_187 = FALSE ;
V_184 = ( T_15 * ) V_168 -> V_15 ;
for ( V_125 = 0 ; V_125 < V_185 ; V_125 ++ ) {
if ( strcmp ( V_184 , V_186 [ V_125 ] ) == 0 ) {
V_187 = TRUE ;
break;
}
}
if ( ! V_187 ) {
for ( V_125 = 0 ; V_125 < V_185 ; V_125 ++ ) {
V_184 = F_49 ( V_186 [ V_125 ] ) ;
V_10 . V_182 = F_71 ( V_10 . V_182 , V_184 ) ;
}
V_1 -> V_13 . V_110 = & V_10 . V_182 ;
F_183 ( V_167 ) ;
return V_171 ;
}
V_168 = V_168 -> V_150 ;
}
V_168 = F_144 ( V_167 ) ;
while ( V_168 ) {
V_184 = ( T_15 * ) V_168 -> V_15 ;
V_10 . V_182 = F_71 ( V_10 . V_182 , V_184 ) ;
V_168 = V_168 -> V_150 ;
}
V_1 -> V_13 . V_110 = & V_10 . V_182 ;
F_20 ( V_167 ) ;
return V_118 ;
}
static const char *
F_195 ( void )
{
return L_33 ;
}
static char *
F_196 ( void )
{
return F_49 (
L_34
V_188 ) ;
}
static T_8
F_197 ( T_1 * V_1 )
{
T_19 * V_174 = F_144 ( V_10 . V_182 ) ,
* V_175 = F_144 ( V_1 -> V_14 . V_110 ) ;
T_8 V_161 = TRUE ;
while ( V_174 && V_175 ) {
if ( strcmp ( ( T_15 * ) V_174 -> V_15 , ( T_15 * ) V_175 -> V_15 ) != 0 ) {
V_161 = FALSE ;
break;
}
V_174 = V_174 -> V_150 ;
V_175 = V_175 -> V_150 ;
}
if ( ( ( V_174 == NULL ) && ( V_175 != NULL ) ) ||
( ( V_174 != NULL ) && ( V_175 == NULL ) ) )
V_161 = FALSE ;
return V_161 ;
}
static char *
F_198 ( T_1 * V_1 , T_8 V_14 )
{
T_19 * V_177 = V_14 ? V_1 -> V_14 . V_110 : V_10 . V_182 ;
T_19 * V_145 = F_144 ( V_177 ) ;
T_19 * V_167 = NULL ;
T_15 * V_189 ;
char * V_190 ;
while ( V_145 ) {
V_189 = ( T_15 * ) V_145 -> V_15 ;
V_167 = F_71 ( V_167 , F_49 ( V_189 ) ) ;
V_145 = V_145 -> V_150 ;
}
V_190 = F_190 ( V_167 ) ;
F_183 ( V_167 ) ;
return V_190 ;
}
static T_27
F_199 ( T_1 * V_1 , const T_15 * V_61 , T_8 * V_83 )
{
( * V_83 ) |= F_91 ( V_1 , V_61 , V_86 ) ;
return V_118 ;
}
static const char *
F_200 ( void )
{
return NULL ;
}
static char *
F_201 ( void )
{
return F_49 ( L_14 ) ;
}
static T_8
F_202 ( T_1 * V_1 V_16 )
{
return TRUE ;
}
static char *
F_203 ( T_1 * V_1 V_16 , T_8 V_14 V_16 )
{
return F_49 ( L_14 ) ;
}
static void
F_42 ( void )
{
T_7 * V_191 , * V_192 , * V_193 ,
* V_194 , * V_195 ;
#ifdef F_204
T_7 * V_196 ;
#endif
struct V_80 V_34 ;
if ( V_53 != NULL ) {
return;
}
#ifdef F_204
V_196 = F_26 ( NULL , L_35 , L_36 ,
L_36 , NULL , FALSE ) ;
V_10 . V_197 = TRUE ;
F_80 ( V_196 , L_37 ,
L_38 ,
L_38 ,
& V_10 . V_197 ) ;
#endif
V_198 = F_26 ( NULL , L_39 , L_40 ,
L_40 , & F_148 , FALSE ) ;
F_85 ( V_198 , L_41 ,
L_42 ,
L_43 ,
( T_16 * ) ( void * ) ( & V_10 . V_199 ) , V_200 , FALSE ) ;
F_127 ( V_198 , L_44 ) ;
F_127 ( V_198 , L_45 ) ;
F_127 ( V_198 , L_46 ) ;
F_80 ( V_198 , L_47 ,
L_48 ,
L_49 ,
& V_10 . V_201 ) ;
F_80 ( V_198 , L_50 ,
L_51 ,
L_52 ,
& V_10 . V_202 ) ;
F_80 ( V_198 , L_53 ,
L_54 ,
L_55 ,
& V_10 . V_203 ) ;
F_85 ( V_198 , L_56 ,
L_57 ,
L_57 ,
& V_10 . V_204 , V_204 , FALSE ) ;
F_85 ( V_198 , L_58 ,
L_59 ,
L_59 ,
& V_10 . V_205 , V_205 , FALSE ) ;
F_85 ( V_198 , L_60 ,
L_61 ,
L_61 ,
& V_10 . V_206 , V_206 , FALSE ) ;
V_148 = F_31 ( V_198 , L_62 , L_62 , NULL ) ;
V_34 . V_35 = F_13 ;
V_34 . V_207 = F_93 ;
V_34 . V_208 = F_159 ;
V_34 . V_209 = F_161 ;
V_34 . V_210 = F_162 ;
V_34 . V_211 = F_168 ;
V_34 . V_212 = F_163 ;
F_90 ( V_148 , V_173 , L_27 ,
L_63 ,
& V_213 , V_31 , & V_34 , FALSE ) ;
V_34 . V_35 = F_177 ;
V_34 . V_207 = F_179 ;
V_34 . V_208 = F_180 ;
V_34 . V_209 = F_186 ;
V_34 . V_210 = F_187 ;
V_34 . V_211 = F_188 ;
V_34 . V_212 = F_189 ;
F_121 ( V_148 , V_149 , L_31 ,
L_32 , & V_34 ,
F_176 , & V_10 . V_214 ) ;
V_34 . V_35 = F_150 ;
V_34 . V_207 = F_170 ;
V_34 . V_208 = F_171 ;
V_34 . V_209 = F_172 ;
V_34 . V_210 = F_173 ;
V_34 . V_211 = F_174 ;
V_34 . V_212 = F_175 ;
F_79 ( V_148 , V_166 , L_64 ,
L_65 , & V_34 , & V_10 . V_215 ) ;
V_195 = F_31 ( V_198 , L_66 , L_66 , NULL ) ;
F_127 ( V_195 , L_67 ) ;
F_90 ( V_195 , L_68 , L_69 ,
L_70 ,
& V_10 . V_216 , V_24 , NULL , TRUE ) ;
F_90 ( V_195 , L_71 , L_69 ,
L_72 ,
& V_10 . V_217 , V_24 , NULL , TRUE ) ;
V_218 = F_31 ( V_198 , L_73 , L_73 , NULL ) ;
F_118 ( V_218 , L_74 , L_75 ,
L_75 , & V_10 . V_219 ) ;
F_118 ( V_218 , L_76 , L_75 ,
L_75 , & V_10 . V_220 ) ;
F_118 ( V_218 , L_77 , L_78 ,
L_78 , & V_10 . V_221 ) ;
F_118 ( V_218 , L_79 , L_78 ,
L_78 , & V_10 . V_222 ) ;
F_118 ( V_218 , L_80 , L_81 ,
L_81 , & V_10 . V_223 ) ;
F_118 ( V_218 , L_82 , L_81 ,
L_81 , & V_10 . V_224 ) ;
F_118 ( V_218 , L_83 , L_81 ,
L_81 , & V_10 . V_225 ) ;
F_118 ( V_218 , L_84 , L_81 ,
L_81 , & V_10 . V_226 ) ;
V_34 . V_35 = F_13 ;
V_34 . V_207 = F_93 ;
V_34 . V_208 = F_199 ;
V_34 . V_209 = F_200 ;
V_34 . V_210 = F_201 ;
V_34 . V_211 = F_202 ;
V_34 . V_212 = F_203 ;
F_90 ( V_148 , L_85 , L_86 ,
L_87 ,
& V_10 . V_227 , V_31 , & V_34 , TRUE ) ;
V_34 . V_35 = F_13 ;
V_34 . V_207 = F_93 ;
V_34 . V_208 = F_199 ;
V_34 . V_209 = F_200 ;
V_34 . V_210 = F_201 ;
V_34 . V_211 = F_202 ;
V_34 . V_212 = F_203 ;
F_90 ( V_148 , L_88 , L_89 ,
L_90 ,
& V_10 . V_228 , V_31 , & V_34 , TRUE ) ;
F_118 ( V_218 , L_91 , L_92 ,
L_92 , & V_10 . V_229 ) ;
F_118 ( V_218 , L_93 , L_94 ,
L_94 , & V_10 . V_230 ) ;
F_118 ( V_218 , L_95 , L_96 ,
L_96 , & V_10 . V_231 ) ;
F_85 ( V_198 , L_97 ,
L_98 ,
L_98 ,
& V_10 . V_232 , V_232 , FALSE ) ;
F_78 ( V_198 , L_99 ,
L_100 ,
L_100 ,
10 ,
& V_10 . V_136 ) ;
F_78 ( V_198 , L_101 ,
L_102 ,
L_102 ,
10 ,
& V_10 . V_137 ) ;
F_90 ( V_198 , L_103 , L_104 ,
L_105 ,
& V_10 . V_233 , V_27 , NULL , TRUE ) ;
F_127 ( V_198 , L_106 ) ;
F_78 ( V_198 , L_107 ,
L_108 ,
L_108 ,
10 ,
& V_10 . V_234 ) ;
F_80 ( V_198 , L_109 ,
L_110 ,
L_111 ,
& V_10 . V_235 ) ;
F_80 ( V_198 , L_112 ,
L_113 ,
L_114 ,
& V_10 . V_236 ) ;
F_80 ( V_198 , L_115 ,
L_116 ,
L_117 ,
& V_10 . V_237 ) ;
F_80 ( V_198 , L_118 ,
L_119 ,
L_120 ,
& V_10 . V_238 ) ;
F_80 ( V_198 , L_121 ,
L_122 ,
L_123 ,
& V_10 . V_239 ) ;
F_80 ( V_198 , L_124 ,
L_125 ,
L_126 ,
& V_10 . V_240 ) ;
F_80 ( V_198 , L_127 ,
L_128 ,
L_129 ,
& V_10 . V_241 ) ;
F_127 ( V_198 , L_130 ) ;
F_127 ( V_198 , L_131 ) ;
F_127 ( V_198 , L_132 ) ;
F_127 ( V_198 , L_133 ) ;
F_127 ( V_198 , L_134 ) ;
F_85 ( V_198 , L_135 ,
L_136 ,
L_136 ,
& V_10 . V_242 , V_243 , FALSE ) ;
F_85 ( V_198 , L_137 ,
L_138 ,
L_138 ,
& V_10 . V_244 , V_243 , FALSE ) ;
F_90 ( V_198 , L_139 , L_140 ,
L_141 ,
& V_10 . V_245 , V_24 , NULL , TRUE ) ;
F_80 ( V_198 , L_142 ,
L_143 ,
L_144 ,
& V_10 . V_246 ) ;
F_85 ( V_198 , L_145 ,
L_146 ,
L_147 ,
( T_16 * ) ( void * ) ( & V_10 . V_247 ) , V_247 , FALSE ) ;
F_78 ( V_198 , L_148 ,
L_149 ,
L_150 ,
10 ,
& V_10 . V_248 ) ;
F_90 ( V_198 , L_151 , L_152 ,
L_153 ,
& V_10 . V_249 , V_24 , NULL , TRUE ) ;
F_90 ( V_198 , L_154 , L_155 ,
L_156 ,
& V_10 . V_250 , V_24 , NULL , TRUE ) ;
F_90 ( V_198 , L_157 , L_158 ,
L_158 ,
& V_10 . V_251 , V_24 , NULL , TRUE ) ;
F_85 ( V_198 , L_159 ,
L_160 ,
L_160 ,
( T_16 * ) ( void * ) ( & V_10 . V_252 ) , V_253 , FALSE ) ;
F_80 ( V_198 , L_161 ,
L_162 ,
L_163
L_164
L_165 ,
& V_10 . V_254 ) ;
F_78 ( V_198 , L_166 ,
L_167 ,
L_168 ,
10 ,
& V_10 . V_255 ) ;
V_194 = F_31 ( V_198 , L_169 , L_169 , F_149 ) ;
F_78 ( V_194 , L_170 ,
L_171 ,
L_172 ,
10 ,
( T_6 * ) ( void * ) ( & V_10 . V_138 ) ) ;
F_85 ( V_194 , L_173 ,
L_174 ,
L_174 ,
( T_16 * ) ( void * ) ( & V_10 . V_256 ) , V_257 , FALSE ) ;
F_85 ( V_194 , L_175 ,
L_176 ,
L_176 ,
( T_16 * ) ( void * ) ( & V_10 . V_258 ) , V_257 , FALSE ) ;
F_85 ( V_194 , L_177 ,
L_178 ,
L_178 ,
( T_16 * ) ( void * ) ( & V_10 . V_259 ) , V_257 , FALSE ) ;
F_80 ( V_194 , L_179 ,
L_180 ,
L_180 ,
& V_10 . V_260 ) ;
F_80 ( V_198 , L_181 ,
L_182 ,
L_183 ,
& V_10 . V_261 ) ;
F_85 ( V_198 , L_184 ,
L_185 ,
L_186 ,
( T_16 * ) ( void * ) ( & V_10 . V_262 ) , V_262 , FALSE ) ;
F_80 ( V_194 , L_187 ,
L_188 ,
L_189 ,
& V_10 . V_263 ) ;
F_80 ( V_194 , L_190 ,
L_191 ,
L_192 ,
& V_10 . V_264 ) ;
F_80 ( V_198 , L_193 ,
L_194 ,
L_195 ,
& V_10 . V_265 ) ;
#ifdef F_205
F_80 ( V_198 , L_196 ,
L_197 ,
L_198 ,
& V_10 . V_266 ) ;
#endif
F_90 ( V_198 , L_199 , L_200 ,
L_201 ,
& V_10 . V_267 , V_24 , NULL , TRUE ) ;
V_193 = F_26 ( NULL , L_202 , L_203 ,
L_204 , NULL , FALSE ) ;
V_34 . V_35 = F_150 ;
V_34 . V_207 = F_151 ;
V_34 . V_208 = F_152 ;
V_34 . V_209 = F_154 ;
V_34 . V_210 = F_155 ;
V_34 . V_211 = F_157 ;
V_34 . V_212 = F_158 ;
F_79 ( V_193 , L_205 , L_206 ,
L_207 , & V_34 , & V_10 . V_268 ) ;
F_80 ( V_193 , L_208 ,
L_209 ,
L_210 ,
& V_10 . V_269 ) ;
V_192 = F_26 ( NULL , L_211 , L_212 ,
L_213 , NULL , FALSE ) ;
F_90 ( V_192 , L_214 , L_215 ,
L_215 ,
& V_10 . V_270 , V_24 , NULL , FALSE ) ;
F_90 ( V_192 , L_216 , L_217 ,
L_218 ,
& V_10 . V_271 , V_24 , NULL , FALSE ) ;
F_90 ( V_192 , L_219 , L_220 ,
L_221 ,
& V_10 . V_272 , V_24 , NULL , FALSE ) ;
F_90 ( V_192 , L_222 , L_223 ,
L_224 ,
& V_10 . V_273 , V_24 , NULL , FALSE ) ;
F_90 ( V_192 , L_225 , L_226 ,
L_227 ,
& V_10 . V_274 , V_24 , NULL , FALSE ) ;
#ifdef F_206
F_90 ( V_192 , L_228 , L_229 ,
L_230 ,
& V_10 . V_275 , V_24 , NULL , FALSE ) ;
#endif
F_90 ( V_192 , L_231 , L_232 ,
L_233 ,
& V_10 . V_276 , V_24 , NULL , FALSE ) ;
F_90 ( V_192 , L_234 , L_235 ,
L_236 ,
& V_10 . V_277 , V_24 , NULL , FALSE ) ;
F_80 ( V_192 , L_237 , L_238 ,
L_239 , & V_10 . V_278 ) ;
F_90 ( V_192 , L_240 , L_241 ,
L_242 ,
& V_10 . V_279 , V_24 , NULL , FALSE ) ;
F_80 ( V_192 , L_243 , L_244 ,
L_245 , & V_10 . V_280 ) ;
F_80 ( V_192 , L_246 , L_247 ,
L_248 , & V_10 . V_281 ) ;
F_80 ( V_192 , L_249 , L_250 ,
L_251 , & V_10 . V_282 ) ;
F_80 ( V_192 , L_252 , L_253 ,
L_254 , & V_10 . V_283 ) ;
F_127 ( V_192 , L_255 ) ;
V_34 . V_35 = F_192 ;
V_34 . V_207 = F_193 ;
V_34 . V_208 = F_194 ;
V_34 . V_209 = F_195 ;
V_34 . V_210 = F_196 ;
V_34 . V_211 = F_197 ;
V_34 . V_212 = F_198 ;
F_121 ( V_192 , L_1 , L_256 ,
L_257 , & V_34 , F_191 , & V_10 . V_182 ) ;
V_284 = F_26 ( NULL , L_258 , L_259 ,
L_259 , NULL , TRUE ) ;
F_207 ( V_284 ) ;
F_208 ( V_284 ) ;
#ifdef F_209
F_210 ( V_284 ) ;
#endif
V_191 = F_26 ( NULL , L_260 , L_261 ,
L_261 , NULL , TRUE ) ;
F_85 ( V_191 , L_262 ,
L_263 , L_264 ,
& V_10 . V_285 , V_286 , TRUE ) ;
F_85 ( V_191 , L_265 ,
L_266 , L_267 ,
& V_10 . V_287 , V_288 , TRUE ) ;
#ifndef F_211
F_90 ( V_191 , L_268 , L_269 ,
L_270 ,
& V_10 . V_289 , V_24 , NULL , TRUE ) ;
#endif
F_90 ( V_191 , L_271 , L_272 ,
L_273 ,
& V_10 . V_290 , V_25 , NULL , TRUE ) ;
V_60 = F_26 ( NULL , L_274 , L_275 ,
L_275 , & F_146 , TRUE ) ;
F_78 ( V_60 , L_276 ,
L_277 ,
L_278 ,
10 ,
& V_10 . V_128 ) ;
#ifdef F_147
F_78 ( V_60 , L_279 ,
L_280 ,
L_281 ,
10 ,
& V_10 . V_130 ) ;
#endif
F_80 ( V_60 , L_282 ,
L_283 ,
L_284
L_285 ,
& V_10 . V_291 ) ;
F_80 ( V_60 , L_286 ,
L_287 ,
L_288
L_289
L_290 ,
& V_10 . V_292 ) ;
F_78 ( V_60 , L_291 ,
L_292 ,
L_293
L_294 ,
10 , & V_10 . V_132 ) ;
F_78 ( V_60 , L_295 ,
L_296 ,
L_297
L_298
L_299 ,
10 , & V_10 . V_134 ) ;
F_85 ( V_60 , L_300 ,
L_301 ,
L_302
L_303 ,
& V_10 . V_293 , V_294 , FALSE ) ;
F_80 ( V_60 , L_304 ,
L_305 ,
L_306
L_307 ,
& V_10 . V_295 ) ;
F_80 ( V_60 , L_308 ,
L_309 ,
L_310
L_311
L_312 ,
& V_10 . V_296 ) ;
F_80 ( V_60 , L_313 ,
L_314 ,
L_315
L_316
L_317
L_318 ,
& V_10 . V_297 ) ;
F_80 ( V_60 , L_319 ,
L_320 ,
L_315
L_321
L_322
L_323 ,
& V_10 . V_298 ) ;
F_80 ( V_60 , L_324 ,
L_325 ,
L_326
L_327
L_328 ,
& V_10 . V_299 ) ;
V_53 = F_26 ( NULL , L_329 , L_330 ,
L_330 , NULL , TRUE ) ;
F_80 ( V_53 , L_331 ,
L_332 ,
L_333 ,
& V_10 . V_300 ) ;
F_80 ( V_53 , L_334 ,
L_335 ,
L_336 ,
& V_10 . V_301 ) ;
F_80 ( V_53 , L_337 ,
L_338 ,
L_339 ,
& V_10 . V_302 ) ;
F_26 ( NULL , L_340 , L_341 , L_341 , NULL , FALSE ) ;
F_26 ( NULL , L_342 , L_343 , L_343 , NULL , FALSE ) ;
F_26 ( NULL , L_344 , L_345 , L_345 , NULL , FALSE ) ;
}
T_19 *
F_181 ( const T_15 * V_303 )
{
enum { V_304 , V_305 , V_306 };
T_16 V_307 = V_304 , V_125 = 0 , V_126 = 0 ;
T_8 V_308 = FALSE ;
T_9 V_309 ;
T_15 * V_310 = NULL ;
T_19 * V_311 = NULL ;
V_310 = ( T_15 * ) F_212 ( sizeof( T_15 ) * V_312 ) ;
V_126 = 0 ;
for (; ; ) {
V_309 = V_303 [ V_125 ] ;
if ( V_309 == '\0' ) {
if ( V_307 == V_305 || V_308 ) {
F_14 ( V_310 ) ;
F_183 ( V_311 ) ;
return NULL ;
}
V_310 [ V_126 ] = '\0' ;
if ( V_126 > 0 )
V_311 = F_71 ( V_311 , V_310 ) ;
break;
}
if ( V_309 == '"' && ! V_308 ) {
switch ( V_307 ) {
case V_304 :
V_307 = V_305 ;
break;
case V_305 :
V_307 = V_306 ;
break;
case V_306 :
V_307 = V_305 ;
break;
default:
break;
}
} else if ( V_309 == '\\' && ! V_308 ) {
V_308 = TRUE ;
if ( V_307 == V_304 )
V_307 = V_306 ;
} else if ( V_309 == ',' && V_307 != V_305 && ! V_308 ) {
V_310 [ V_126 ] = '\0' ;
if ( V_126 > 0 )
V_311 = F_71 ( V_311 , V_310 ) ;
V_307 = V_304 ;
V_310 = ( T_15 * ) F_212 ( sizeof( T_15 ) * V_312 ) ;
V_126 = 0 ;
} else if ( ! F_213 ( V_309 ) || V_307 != V_304 ) {
if ( V_126 < V_312 ) {
V_310 [ V_126 ] = V_309 ;
V_126 ++ ;
}
V_308 = FALSE ;
}
V_125 ++ ;
}
return ( V_311 ) ;
}
char * F_190 ( T_19 * V_311 )
{
T_34 * V_313 = F_164 ( L_14 ) ;
T_19 * V_314 , * V_315 ;
T_15 * V_303 ;
T_6 V_316 = 0 ;
V_314 = V_315 = F_144 ( V_311 ) ;
while ( V_314 ) {
V_316 ++ ;
V_303 = ( T_15 * ) V_314 -> V_15 ;
if ( V_314 != V_315 )
F_214 ( V_313 , ',' ) ;
if ( V_316 % 2 ) {
F_166 ( V_313 , L_346 ) ;
} else
F_214 ( V_313 , ' ' ) ;
F_214 ( V_313 , '"' ) ;
while ( * V_303 ) {
T_35 V_317 = F_70 ( V_303 ) ;
if ( V_317 == '"' || V_317 == '\\' )
F_214 ( V_313 , '\\' ) ;
if ( F_69 ( V_317 ) )
F_215 ( V_313 , V_317 ) ;
V_303 = F_68 ( V_303 ) ;
}
F_214 ( V_313 , '"' ) ;
V_314 = V_314 -> V_150 ;
}
return F_167 ( V_313 , FALSE ) ;
}
void
F_183 ( T_19 * V_311 )
{
F_19 ( V_311 , ( V_318 ) F_14 , NULL ) ;
F_20 ( V_311 ) ;
}
static T_16
F_216 ( const char * V_319 , const T_21 * V_320 ,
T_16 V_321 )
{
int V_125 ;
for ( V_125 = 0 ; V_320 [ V_125 ] . V_5 != NULL ; V_125 ++ ) {
if ( F_217 ( V_319 , V_320 [ V_125 ] . V_5 ) == 0 ) {
return V_320 [ V_125 ] . V_61 ;
}
}
for ( V_125 = 0 ; V_320 [ V_125 ] . V_5 != NULL ; V_125 ++ ) {
if ( F_217 ( V_319 , V_320 [ V_125 ] . V_2 ) == 0 ) {
return V_320 [ V_125 ] . V_61 ;
}
}
return V_321 ;
}
static T_8
F_218 ( const T_15 * V_154 )
{
T_6 V_322 ;
for ( V_322 = 0 ;
V_322 < F_219 ( V_323 ) ;
++ V_322 ) {
if ( strcmp ( V_323 [ V_322 ] . V_324 , V_154 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_8
F_184 ( T_33 * V_146 , const char * V_154 )
{
const T_15 * V_325 = F_165 ( V_155 ) ;
T_36 V_326 = strlen ( V_325 ) ;
T_15 * * V_327 ;
char * V_47 ;
int V_324 ;
T_15 * V_328 = NULL ;
long V_329 = 0 ;
T_8 V_330 = TRUE ;
if ( ( strlen ( V_154 ) > V_326 ) && ( V_154 [ V_326 ] == ':' ) &&
strncmp ( V_154 , V_325 , V_326 ) == 0 ) {
V_324 = V_155 ;
V_327 = F_220 ( & V_154 [ V_326 + 1 ] , L_347 , 3 ) ;
V_328 = F_49 ( V_327 [ 0 ] ) ;
if ( V_328 && V_327 [ 1 ] ) {
V_329 = strtol ( V_327 [ 1 ] , & V_47 , 10 ) ;
if ( V_47 == V_327 [ 1 ] || * V_47 != '\0' ) {
F_14 ( V_328 ) ;
F_221 ( V_327 ) ;
return FALSE ;
}
}
if ( V_328 && V_327 [ 1 ] && V_327 [ 2 ] ) {
V_330 = ( V_327 [ 2 ] [ 0 ] == 'U' ) ? FALSE : TRUE ;
}
F_221 ( V_327 ) ;
} else {
V_324 = F_222 ( V_154 ) ;
if ( ( V_324 == - 1 ) && ( ! F_218 ( V_154 ) ) )
return FALSE ;
}
V_146 -> V_154 = V_324 ;
V_146 -> V_156 = V_328 ;
V_146 -> V_157 = ( int ) V_329 ;
V_146 -> V_158 = V_330 ;
return TRUE ;
}
static void
F_223 ( void )
{
if ( V_331 )
return;
F_224 () ;
F_41 () ;
F_42 () ;
F_225 () ;
V_331 = TRUE ;
}
static void
F_41 ( void )
{
int V_125 ;
T_15 * V_184 ;
T_33 * V_146 ;
static const T_15 * V_324 [ V_332 * 2 ] = {
L_348 , L_349 , L_350 , L_351 ,
L_352 , L_353 , L_354 , L_355 ,
L_356 , L_357 , L_358 , L_359 ,
L_360 , L_361 } ;
V_10 . V_285 = V_333 ;
V_10 . V_287 = V_334 ;
if ( V_10 . V_290 ) F_14 ( V_10 . V_290 ) ;
V_10 . V_290 = F_49 ( L_362 ) ;
if ( V_10 . V_289 ) F_14 ( V_10 . V_289 ) ;
V_10 . V_289 = F_49 ( L_363 ) ;
V_10 . V_201 = FALSE ;
V_10 . V_202 = FALSE ;
V_10 . V_204 = 0 ;
V_10 . V_205 = 1 ;
V_10 . V_206 = 1 ;
V_10 . V_203 = FALSE ;
V_10 . V_242 = V_335 ;
V_10 . V_244 = V_336 ;
if ( V_10 . V_216 ) F_14 ( V_10 . V_216 ) ;
#ifdef F_211
V_10 . V_216 = F_49 ( L_364 ) ;
#else
V_10 . V_216 = F_49 ( L_365 ) ;
#endif
if ( V_10 . V_217 ) F_14 ( V_10 . V_217 ) ;
V_10 . V_217 = F_49 ( L_14 ) ;
V_10 . V_219 . V_106 = 65535 ;
V_10 . V_219 . V_107 = 65535 ;
V_10 . V_219 . V_108 = 65535 ;
V_10 . V_220 . V_106 = 0 ;
V_10 . V_220 . V_107 = 8224 ;
V_10 . V_220 . V_108 = 10794 ;
V_10 . V_221 . V_106 = 32767 ;
V_10 . V_221 . V_107 = 32767 ;
V_10 . V_221 . V_108 = 32767 ;
V_10 . V_222 . V_106 = 65535 ;
V_10 . V_222 . V_107 = 65535 ;
V_10 . V_222 . V_108 = 65535 ;
if ( V_10 . V_227 ) F_14 ( V_10 . V_227 ) ;
V_10 . V_227 = F_49 ( L_366 ) ;
if ( V_10 . V_228 ) F_14 ( V_10 . V_228 ) ;
V_10 . V_228 = F_49 ( L_367 ) ;
V_10 . V_223 . V_106 = 32767 ;
V_10 . V_223 . V_107 = 0 ;
V_10 . V_223 . V_108 = 0 ;
V_10 . V_224 . V_106 = 64507 ;
V_10 . V_224 . V_107 = 60909 ;
V_10 . V_224 . V_108 = 60909 ;
V_10 . V_225 . V_106 = 0 ;
V_10 . V_225 . V_107 = 0 ;
V_10 . V_225 . V_108 = 32767 ;
V_10 . V_226 . V_106 = 60909 ;
V_10 . V_226 . V_107 = 60909 ;
V_10 . V_226 . V_108 = 64507 ;
if ( V_42 ) {
V_10 . V_229 . V_106 = 0x0000 ;
V_10 . V_229 . V_107 = 0x66ff ;
V_10 . V_229 . V_108 = 0x0000 ;
V_10 . V_230 . V_106 = 0x66FF ;
V_10 . V_230 . V_107 = 0x0000 ;
V_10 . V_230 . V_108 = 0x0000 ;
V_10 . V_231 . V_106 = 0x66FF ;
V_10 . V_231 . V_107 = 0x66FF ;
V_10 . V_231 . V_108 = 0x0000 ;
} else {
V_10 . V_229 . V_106 = 0xAFFF ;
V_10 . V_229 . V_107 = 0xFFFF ;
V_10 . V_229 . V_108 = 0xAFFF ;
V_10 . V_230 . V_106 = 0xFFFF ;
V_10 . V_230 . V_107 = 0xAFFF ;
V_10 . V_230 . V_108 = 0xAFFF ;
V_10 . V_231 . V_106 = 0xFFFF ;
V_10 . V_231 . V_107 = 0xFFFF ;
V_10 . V_231 . V_108 = 0xAFFF ;
}
V_10 . V_238 = TRUE ;
V_10 . V_239 = TRUE ;
V_10 . V_240 = TRUE ;
V_10 . V_241 = TRUE ;
V_10 . V_199 = V_337 ;
V_10 . V_232 = V_338 ;
V_10 . V_137 = 10 ;
V_10 . V_136 = 10 ;
if ( V_10 . V_233 ) F_14 ( V_10 . V_233 ) ;
V_10 . V_233 = F_49 ( F_226 () ) ;
V_10 . V_234 = 3 ;
V_10 . V_235 = TRUE ;
V_10 . V_236 = TRUE ;
V_10 . V_237 = FALSE ;
V_10 . V_246 = TRUE ;
V_10 . V_247 = V_339 ;
V_10 . V_248 = 60 * 60 * 24 ;
if ( V_10 . V_245 ) F_14 ( V_10 . V_245 ) ;
V_10 . V_245 = F_49 ( L_14 ) ;
if ( V_10 . V_249 ) F_14 ( V_10 . V_249 ) ;
V_10 . V_249 = F_49 ( L_14 ) ;
if ( V_10 . V_250 ) F_14 ( V_10 . V_250 ) ;
V_10 . V_250 = F_49 ( L_14 ) ;
if ( V_10 . V_251 ) F_14 ( V_10 . V_251 ) ;
V_10 . V_251 = F_49 ( L_368 ) ;
V_10 . V_252 = V_340 ;
V_10 . V_254 = FALSE ;
V_10 . V_255 = 0 ;
V_10 . V_138 = V_141 ;
V_10 . V_256 = V_341 ;
V_10 . V_258 = V_342 ;
V_10 . V_259 = V_343 ;
V_10 . V_261 = FALSE ;
V_10 . V_262 = V_344 ;
V_10 . V_263 = TRUE ;
V_10 . V_264 = TRUE ;
if ( V_10 . V_267 ) F_14 ( V_10 . V_267 ) ;
V_10 . V_267 = F_49 ( L_14 ) ;
V_10 . V_265 = FALSE ;
#ifdef F_205
V_10 . V_266 = TRUE ;
#endif
V_10 . V_260 = FALSE ;
if ( V_10 . V_214 ) {
F_178 ( V_10 . V_214 ) ;
V_10 . V_214 = NULL ;
}
for ( V_125 = 0 ; V_125 < V_332 ; V_125 ++ ) {
V_146 = F_63 ( T_33 , 1 ) ;
V_146 -> V_3 = F_49 ( V_324 [ V_125 * 2 ] ) ;
F_184 ( V_146 , V_324 [ ( V_125 * 2 ) + 1 ] ) ;
V_146 -> V_151 = TRUE ;
V_146 -> V_158 = TRUE ;
V_146 -> V_156 = NULL ;
V_146 -> V_157 = 0 ;
V_10 . V_214 = F_71 ( V_10 . V_214 , V_146 ) ;
}
V_10 . V_215 = V_332 ;
V_10 . V_278 = TRUE ;
#ifdef F_227
V_10 . V_280 = TRUE ;
#else
V_10 . V_280 = FALSE ;
#endif
V_10 . V_281 = TRUE ;
V_10 . V_282 = TRUE ;
V_10 . V_283 = FALSE ;
if ( ! V_10 . V_182 ) {
for ( V_125 = 0 ; V_125 < V_185 ; V_125 ++ ) {
V_184 = F_49 ( V_186 [ V_125 ] ) ;
V_10 . V_182 = F_71 ( V_10 . V_182 , V_184 ) ;
}
}
V_10 . V_268 =
V_345 | V_346 | V_347 ;
V_10 . V_128 = V_129 ;
V_10 . V_130 = V_131 ;
V_10 . V_291 = TRUE ;
V_10 . V_292 = FALSE ;
V_10 . V_132 = V_348 ;
V_10 . V_134 = V_349 ;
V_10 . V_296 = TRUE ;
V_10 . V_298 = TRUE ;
V_10 . V_297 = TRUE ;
V_10 . V_293 = V_350 ;
V_10 . V_295 = TRUE ;
V_10 . V_299 = FALSE ;
V_10 . V_300 = FALSE ;
V_10 . V_301 = FALSE ;
}
void
F_228 ( T_1 * V_1 )
{
int type ;
if ( ! V_1 ) return;
type = V_1 -> type ;
if ( F_65 ( type ) )
return;
else
F_16 ( type ) ;
switch ( type ) {
case V_19 :
case V_20 :
* V_1 -> V_13 . V_79 = V_1 -> V_14 . V_79 ;
break;
case V_17 :
* V_1 -> V_13 . V_81 = V_1 -> V_14 . V_33 ;
break;
case V_18 :
* V_1 -> V_13 . V_89 = V_1 -> V_14 . V_90 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
F_93 ( V_1 ) ;
break;
case V_28 :
case V_29 :
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = F_101 ( F_12 () , V_1 -> V_14 . V_30 ) ;
break;
case V_21 :
case V_22 :
break;
case V_23 :
* V_1 -> V_13 . V_105 = V_1 -> V_14 . V_104 ;
break;
case V_31 :
V_1 -> V_34 . V_207 ( V_1 ) ;
break;
}
}
static void
F_229 ( T_4 V_15 , T_4 T_5 V_16 )
{
T_1 * V_1 = ( T_1 * ) V_15 ;
F_228 ( V_1 ) ;
}
static T_8
F_230 ( const void * T_11 V_16 , void * V_61 , void * V_15 V_16 )
{
T_37 V_72 ;
V_72 . V_36 = ( T_7 * ) V_61 ;
F_19 ( V_72 . V_36 -> V_10 , F_229 , & V_72 ) ;
return FALSE ;
}
void
F_231 ( void )
{
V_331 = FALSE ;
F_14 ( V_10 . V_39 ) ;
V_10 . V_39 = NULL ;
F_232 () ;
F_233 () ;
F_234 ( * V_351 ) ;
* V_351 = NULL ;
F_223 () ;
F_56 ( V_11 , F_230 , NULL ) ;
}
T_38 *
F_235 ( void )
{
int V_352 ;
char * V_353 ;
T_39 * V_354 ;
F_233 () ;
F_223 () ;
if ( V_40 == NULL ) {
V_40 = F_236 ( V_355 ) ;
if ( ( V_354 = F_237 ( V_40 , L_369 ) ) == NULL && V_356 == V_357 ) {
F_14 ( V_40 ) ;
V_40 = F_236 ( V_358 ) ;
V_354 = F_237 ( V_40 , L_369 ) ;
}
} else {
V_354 = F_237 ( V_40 , L_369 ) ;
}
if ( V_354 != NULL ) {
V_359 = 0 ;
V_360 = 0 ;
V_352 = F_238 ( V_40 , V_354 , V_361 , NULL ) ;
if ( V_352 != 0 ) {
F_239 ( L_370 ,
V_40 , F_240 ( V_352 ) ) ;
}
fclose ( V_354 ) ;
} else {
if ( V_356 != V_357 ) {
if ( V_356 != 0 ) {
F_239 ( L_371 ,
V_40 , F_240 ( V_356 ) ) ;
}
}
}
V_353 = F_241 ( V_355 , TRUE ) ;
if ( ( V_354 = F_237 ( V_353 , L_369 ) ) != NULL ) {
V_359 = 0 ;
V_360 = 0 ;
V_352 = F_238 ( V_353 , V_354 , V_361 , NULL ) ;
if ( V_352 != 0 ) {
F_239 ( L_372 ,
V_353 , F_240 ( V_352 ) ) ;
} else
F_14 ( V_353 ) ;
fclose ( V_354 ) ;
} else {
if ( V_356 != V_357 ) {
F_239 ( L_373 ,
V_353 , F_240 ( V_356 ) ) ;
} else
F_14 ( V_353 ) ;
}
F_242 () ;
return & V_10 ;
}
int
F_238 ( const char * V_353 , T_39 * V_354 ,
T_40 V_362 , void * V_363 )
{
enum {
V_364 ,
V_365 ,
V_366 ,
V_367 ,
V_368
} V_307 = V_364 ;
int V_369 ;
T_34 * V_370 ;
T_34 * V_371 ;
T_8 V_372 = FALSE ;
T_16 V_373 = 1 , V_374 = 1 ;
T_15 V_375 [] = L_374 ;
T_15 V_376 [ 128 ] ;
V_370 = F_164 ( L_14 ) ;
V_371 = F_164 ( L_14 ) ;
if ( fscanf ( V_354 , L_375 , V_376 ) == 1 ) {
F_14 ( V_10 . V_39 ) ;
V_10 . V_39 = F_243 ( V_376 , strlen ( V_376 ) - 1 ) ;
}
rewind ( V_354 ) ;
while ( ( V_369 = F_244 ( V_354 ) ) != V_377 ) {
if ( V_369 == '\r' ) {
V_369 = F_244 ( V_354 ) ;
if ( V_369 == V_377 )
break;
if ( V_369 != '\n' ) {
ungetc ( V_369 , V_354 ) ;
V_369 = '\r' ;
}
}
if ( V_369 == '\n' ) {
V_307 = V_364 ;
V_373 ++ ;
continue;
}
switch ( V_307 ) {
case V_364 :
if ( F_245 ( V_369 ) ) {
if ( V_371 -> V_159 > 0 ) {
if ( V_372 ) {
if ( V_370 -> V_159 > 0 ) {
if ( V_370 -> V_303 [ V_370 -> V_159 - 1 ] == ',' ) {
V_370 -> V_303 [ V_370 -> V_159 - 1 ] = '\0' ;
F_246 ( L_376 , V_353 , V_374 , V_371 -> V_303 , V_375 ) ;
}
}
switch ( V_362 ( V_371 -> V_303 , V_370 -> V_303 , V_363 , FALSE ) ) {
case V_118 :
break;
case V_171 :
F_246 ( L_377 ,
V_371 -> V_303 , V_374 , V_353 , V_375 ) ;
break;
case V_119 :
if ( strcmp ( V_371 -> V_303 , L_378 ) != 0 )
F_246 ( L_379 ,
V_371 -> V_303 , V_374 , V_353 , V_375 ) ;
V_10 . V_378 = TRUE ;
break;
case V_379 :
if ( strcmp ( V_371 -> V_303 , L_378 ) != 0 )
F_246 ( L_380 ,
V_371 -> V_303 , V_374 , V_353 , V_375 ) ;
V_10 . V_378 = TRUE ;
break;
}
} else {
F_246 ( L_381 , V_374 , V_353 , V_375 ) ;
}
}
V_307 = V_365 ;
V_372 = FALSE ;
F_247 ( V_371 , 0 ) ;
F_214 ( V_371 , ( T_15 ) V_369 ) ;
V_374 = V_373 ;
} else if ( F_213 ( V_369 ) && V_371 -> V_159 > 0 && V_372 ) {
V_307 = V_366 ;
} else if ( V_369 == '#' ) {
V_307 = V_368 ;
} else {
F_246 ( L_382 , V_373 , V_353 , V_375 ) ;
}
break;
case V_365 :
if ( V_369 != ':' ) {
F_214 ( V_371 , ( T_15 ) V_369 ) ;
} else {
V_307 = V_366 ;
F_247 ( V_370 , 0 ) ;
V_372 = TRUE ;
}
break;
case V_366 :
if ( ! F_213 ( V_369 ) ) {
V_307 = V_367 ;
F_214 ( V_370 , ( T_15 ) V_369 ) ;
}
break;
case V_367 :
F_214 ( V_370 , ( T_15 ) V_369 ) ;
break;
case V_368 :
break;
}
}
if ( V_371 -> V_159 > 0 ) {
if ( V_372 ) {
switch ( V_362 ( V_371 -> V_303 , V_370 -> V_303 , V_363 , FALSE ) ) {
case V_118 :
break;
case V_171 :
F_246 ( L_383 ,
V_371 -> V_303 , V_374 , V_353 , V_375 ) ;
break;
case V_119 :
F_246 ( L_379 ,
V_371 -> V_303 , V_374 , V_353 , V_375 ) ;
V_10 . V_378 = TRUE ;
break;
case V_379 :
V_10 . V_378 = TRUE ;
break;
}
} else {
F_246 ( L_384 ,
V_374 , V_353 , V_375 ) ;
}
}
F_167 ( V_370 , TRUE ) ;
F_167 ( V_371 , TRUE ) ;
if ( ferror ( V_354 ) )
return V_356 ;
else
return 0 ;
}
static T_8
F_248 ( char * V_380 , char * * V_381 ) {
T_15 * V_47 , * V_382 ;
T_23 * V_101 ;
T_8 V_63 ;
V_382 = strchr ( V_380 , ':' ) ;
if ( V_382 == NULL )
return FALSE ;
V_47 = V_382 ;
* V_47 ++ = '\0' ;
while ( F_213 ( * V_47 ) )
V_47 ++ ;
if ( * V_47 == '\0' ) {
* V_382 = ':' ;
return FALSE ;
}
V_101 = F_249 ( V_380 ) ;
* V_382 = ':' ;
if ( V_101 == NULL ) {
* V_381 = F_49 ( L_385 ) ;
return FALSE ;
}
V_63 = F_250 ( V_101 , V_47 , V_381 ) ;
return V_63 ;
}
T_27
F_251 ( char * V_383 , char * * V_381 )
{
T_15 * V_47 , * V_382 ;
T_27 V_63 ;
V_359 = - 1 ;
V_360 = - 1 ;
* V_381 = NULL ;
V_382 = strchr ( V_383 , ':' ) ;
if ( V_382 == NULL )
return V_171 ;
V_47 = V_382 ;
* V_47 ++ = '\0' ;
while ( F_213 ( * V_47 ) )
V_47 ++ ;
if ( * V_47 == '\0' ) {
* V_382 = ':' ;
return V_171 ;
}
if ( strcmp ( V_383 , L_386 ) ) {
V_63 = V_361 ( V_383 , V_47 , NULL , TRUE ) ;
} else {
V_63 = F_248 ( V_47 , V_381 ) ? V_118 : V_171 ;
}
* V_382 = ':' ;
return V_63 ;
}
T_6 F_252 ( T_1 * V_1 , T_20 V_82 )
{
switch ( V_82 )
{
case V_84 :
return V_1 -> V_14 . V_79 ;
break;
case V_85 :
return V_1 -> V_32 . V_79 ;
break;
case V_86 :
return * V_1 -> V_13 . V_79 ;
break;
default:
F_82 () ;
break;
}
return 0 ;
}
T_6 F_253 ( const char * V_98 , const char * V_99 )
{
return F_252 ( F_64 ( F_33 ( V_98 ) , V_99 ) , V_86 ) ;
}
T_8 F_254 ( T_1 * V_1 , T_6 V_61 , T_20 V_82 )
{
T_8 V_83 = FALSE ;
switch ( V_82 )
{
case V_84 :
if ( V_1 -> V_14 . V_79 != V_61 ) {
V_1 -> V_14 . V_79 = V_61 ;
V_83 = TRUE ;
}
break;
case V_85 :
if ( V_1 -> V_32 . V_79 != V_61 ) {
V_1 -> V_32 . V_79 = V_61 ;
V_83 = TRUE ;
}
break;
case V_86 :
if ( * V_1 -> V_13 . V_79 != V_61 ) {
* V_1 -> V_13 . V_79 = V_61 ;
V_83 = TRUE ;
}
break;
default:
F_82 () ;
break;
}
return V_83 ;
}
T_6 F_255 ( T_1 * V_1 )
{
return V_1 -> V_6 . V_77 ;
}
T_8
F_256 ( const char * V_5 )
{
T_15 * V_384 , * V_385 ;
T_36 V_159 ;
if ( V_10 . V_273 && V_5 ) {
V_385 = F_49 ( V_10 . V_273 ) ;
V_159 = strlen ( V_5 ) ;
for ( V_384 = strtok ( V_385 , L_30 ) ; V_384 ; V_384 = strtok ( NULL , L_30 ) ) {
if ( strlen ( V_384 ) == V_159 && strcmp ( V_5 , V_384 ) == 0 ) {
F_14 ( V_385 ) ;
return TRUE ;
}
}
F_14 ( V_385 ) ;
}
return FALSE ;
}
static T_8
F_160 ( const T_15 * V_152 , T_33 * V_146 )
{
T_15 * V_384 , * V_386 ;
T_33 V_387 ;
if ( V_152 ) {
V_386 = F_49 ( V_152 ) ;
for ( V_384 = strtok ( V_386 , L_30 ) ; V_384 ; V_384 = strtok ( NULL , L_30 ) ) {
V_384 = F_257 ( V_384 ) ;
if ( ! F_184 ( & V_387 , V_384 ) ) {
continue;
}
if ( V_146 -> V_154 != V_387 . V_154 ) {
F_14 ( V_387 . V_156 ) ;
V_387 . V_156 = NULL ;
continue;
}
if ( V_146 -> V_154 == V_155 ) {
if ( V_387 . V_156 && V_146 -> V_156 ) {
if ( strcmp ( V_146 -> V_156 ,
V_387 . V_156 ) != 0 ) {
F_14 ( V_387 . V_156 ) ;
V_387 . V_156 = NULL ;
continue;
}
if ( V_146 -> V_157 != V_387 . V_157 ) {
F_14 ( V_387 . V_156 ) ;
V_387 . V_156 = NULL ;
continue;
}
}
}
F_14 ( V_387 . V_156 ) ;
F_14 ( V_386 ) ;
return FALSE ;
}
F_14 ( V_386 ) ;
}
return TRUE ;
}
T_8
F_258 ( const char * V_5 )
{
T_15 * V_384 , * V_385 ;
T_36 V_159 ;
if ( V_10 . V_274 && V_5 ) {
V_385 = F_49 ( V_10 . V_274 ) ;
V_159 = strlen ( V_5 ) ;
for ( V_384 = strtok ( V_385 , L_30 ) ; V_384 ; V_384 = strtok ( NULL , L_30 ) ) {
if ( strlen ( V_384 ) == V_159 && strcmp ( V_5 , V_384 ) == 0 ) {
F_14 ( V_385 ) ;
return TRUE ;
}
}
F_14 ( V_385 ) ;
}
return FALSE ;
}
T_8
F_259 ( const T_15 * V_388 )
{
T_19 * V_389 ;
T_15 * V_189 ;
for ( V_389 = F_144 ( V_10 . V_182 ) ; V_389 ; V_389 = F_145 ( V_389 ) ) {
V_189 = ( T_15 * ) V_389 -> V_15 ;
if ( V_189 && ( F_217 ( V_189 , V_388 ) == 0 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_8
F_260 ( T_41 V_390 )
{
return ( ( V_10 . V_256 == V_390 ) ||
( V_10 . V_258 == V_390 ) ||
( V_10 . V_259 == V_390 ) ) ;
}
char
F_261 ( const char * string , T_42 * V_391 )
{
char V_48 ;
memset ( V_391 , 0 , sizeof( T_42 ) ) ;
while ( ( V_48 = * string ++ ) != '\0' ) {
switch ( V_48 ) {
case 'm' :
V_391 -> V_392 = TRUE ;
break;
case 'n' :
V_391 -> V_393 = TRUE ;
break;
case 'N' :
V_391 -> V_394 = TRUE ;
break;
case 't' :
V_391 -> V_395 = TRUE ;
break;
case 'C' :
break;
case 'd' :
V_391 -> V_396 = TRUE ;
break;
case 'v' :
V_391 -> V_397 = TRUE ;
break;
default:
return V_48 ;
}
}
return '\0' ;
}
static void
F_185 ( T_4 * V_398 )
{
T_6 V_322 ;
T_15 * * V_154 = ( T_15 * * ) V_398 ;
for ( V_322 = 0 ;
V_322 < F_219 ( V_323 ) ;
++ V_322 ) {
if ( strcmp ( V_323 [ V_322 ] . V_324 , * V_154 ) == 0 ) {
T_15 * V_399 = F_156 ( L_387 ,
V_323 [ V_322 ] . V_400 ) ;
F_14 ( * V_154 ) ;
* V_154 = V_399 ;
}
}
}
static T_8
F_262 ( T_15 * V_99 , const T_15 * V_61 )
{
struct V_401
{
const char * V_99 ;
const char * V_402 ;
T_8 V_403 ;
};
struct V_401 V_404 [] = {
{ L_388 , L_389 , 0 } ,
{ L_390 , L_391 , 1 } ,
{ L_390 , L_392 , 0 } ,
{ L_393 , L_394 , 0 } ,
{ L_395 , L_396 , 0 } ,
{ L_397 , L_398 , 0 } ,
{ L_399 , L_400 , 0 } ,
{ L_401 , L_402 , 0 } ,
{ L_403 , L_404 , 1 } ,
{ L_403 , L_405 , 0 } ,
{ L_406 , L_407 , 0 } ,
{ L_408 , L_409 , 0 } ,
{ L_410 , L_411 , 0 } ,
{ L_412 , L_413 , 0 } ,
{ L_414 , L_415 , 0 } ,
{ L_416 , L_417 , 0 } ,
{ L_418 , L_419 , 1 } ,
{ L_420 , L_421 , 0 } ,
{ L_422 , L_423 , 0 } ,
{ L_424 , L_425 , 0 } ,
{ L_426 , L_427 , 0 } ,
{ L_428 , L_429 , 0 } ,
{ L_430 , L_431 , 0 } ,
{ L_432 , L_433 , 0 } ,
{ L_434 , L_435 , 0 } ,
{ L_436 , L_437 , 0 } ,
{ L_438 , L_439 , 0 } ,
{ L_440 , L_441 , 0 } ,
{ L_442 , L_443 , 1 } ,
{ L_442 , L_444 , 0 } ,
{ L_445 , L_446 , 1 } ,
{ L_445 , L_447 , 0 } ,
{ L_448 , L_449 , 0 } ,
{ L_450 , L_451 , 0 } ,
{ L_452 , L_453 , 1 } ,
{ L_452 , L_454 , 1 } ,
{ L_452 , L_455 , 0 } ,
{ L_456 , L_457 , 0 } ,
{ L_458 , L_459 , 0 } ,
} ;
unsigned int V_125 ;
T_43 * V_405 ;
for ( V_125 = 0 ; V_125 < sizeof( V_404 ) / sizeof( struct V_401 ) ; V_125 ++ )
{
if ( strcmp ( V_99 , V_404 [ V_125 ] . V_99 ) == 0 )
{
V_405 = F_263 ( V_404 [ V_125 ] . V_402 ) ;
if ( V_405 != NULL ) {
V_405 -> V_406 = ( ( F_217 ( V_61 , L_460 ) == 0 ) ? TRUE : FALSE ) ;
}
if ( ! V_404 [ V_125 ] . V_403 )
return TRUE ;
}
}
return FALSE ;
}
static T_8
F_264 ( T_15 * V_99 , const T_15 * V_61 )
{
struct V_407
{
const char * V_99 ;
const char * V_402 ;
};
struct V_407 V_408 [] = {
{ L_461 , L_462 } ,
{ L_463 , L_464 } ,
{ L_465 , L_466 } ,
} ;
unsigned int V_125 ;
int V_409 ;
for ( V_125 = 0 ; V_125 < sizeof( V_408 ) / sizeof( struct V_407 ) ; V_125 ++ )
{
if ( strcmp ( V_99 , V_408 [ V_125 ] . V_99 ) == 0 )
{
V_409 = F_265 ( V_408 [ V_125 ] . V_402 ) ;
if ( V_409 >= 0 )
F_266 ( V_409 , ( ( F_217 ( V_61 , L_460 ) == 0 ) ? TRUE : FALSE ) ) ;
return TRUE ;
}
}
return FALSE ;
}
static T_8
F_267 ( T_15 * V_99 , const T_15 * V_61 )
{
struct V_410
{
const char * V_99 ;
const char * V_98 ;
const char * V_411 ;
T_6 V_77 ;
};
struct V_412
{
const char * V_99 ;
};
struct V_410 V_413 [] = {
{ L_467 , L_468 , L_469 , 10 } ,
{ L_470 , L_471 , L_469 , 10 } ,
{ L_472 , L_473 , L_469 , 10 } ,
{ L_474 , L_475 , L_469 , 10 } ,
{ L_476 , L_477 , L_469 , 10 } ,
{ L_478 , L_479 , L_469 , 10 } ,
{ L_480 , L_481 , L_469 , 10 } ,
{ L_482 , L_483 , L_469 , 10 } ,
{ L_484 , L_485 , L_469 , 10 } ,
{ L_486 , L_487 , L_469 , 10 } ,
{ L_488 , L_489 , L_469 , 10 } ,
{ L_490 , L_491 , L_469 , 10 } ,
{ L_492 , L_493 , L_469 , 10 } ,
{ L_494 , L_495 , L_469 , 10 } ,
{ L_496 , L_497 , L_469 , 10 } ,
{ L_498 , L_499 , L_469 , 10 } ,
{ L_500 , L_501 , L_469 , 10 } ,
{ L_502 , L_503 , L_469 , 10 } ,
{ L_504 , L_505 , L_469 , 10 } ,
{ L_506 , L_505 , L_469 , 10 } ,
{ L_507 , L_471 , L_508 , 10 } ,
{ L_509 , L_510 , L_508 , 10 } ,
{ L_511 , L_512 , L_508 , 10 } ,
{ L_513 , L_514 , L_508 , 10 } ,
{ L_515 , L_516 , L_508 , 10 } ,
{ L_517 , L_516 , L_508 , 10 } ,
{ L_518 , L_519 , L_508 , 10 } ,
{ L_520 , L_477 , L_508 , 10 } ,
{ L_521 , L_479 , L_508 , 10 } ,
{ L_522 , L_523 , L_508 , 10 } ,
{ L_524 , L_525 , L_508 , 10 } ,
{ L_526 , L_527 , L_508 , 10 } ,
{ L_528 , L_529 , L_508 , 10 } ,
{ L_530 , L_487 , L_508 , 10 } ,
{ L_531 , L_532 , L_508 , 10 } ,
{ L_533 , L_532 , L_508 , 10 } ,
{ L_534 , L_535 , L_508 , 10 } ,
{ L_536 , L_535 , L_508 , 10 } ,
{ L_537 , L_538 , L_508 , 10 } ,
{ L_539 , L_540 , L_508 , 10 } ,
{ L_541 , L_542 , L_508 , 10 } ,
{ L_543 , L_497 , L_508 , 10 } ,
{ L_544 , L_499 , L_508 , 10 } ,
{ L_545 , L_546 , L_508 , 10 } ,
{ L_547 , L_548 , L_508 , 10 } ,
{ L_549 , L_548 , L_508 , 10 } ,
{ L_550 , L_548 , L_508 , 10 } ,
{ L_551 , L_548 , L_508 , 10 } ,
{ L_552 , L_553 , L_508 , 10 } ,
{ L_554 , L_555 , L_508 , 10 } ,
{ L_556 , L_557 , L_508 , 10 } ,
{ L_558 , L_559 , L_508 , 10 } ,
} ;
struct V_410 V_414 [] = {
{ L_560 , L_561 , L_469 , 10 } ,
{ L_562 , L_563 , L_469 , 10 } ,
{ L_564 , L_565 , L_469 , 10 } ,
{ L_566 , L_567 , L_469 , 10 } ,
{ L_568 , L_569 , L_469 , 10 } ,
{ L_570 , L_571 , L_469 , 10 } ,
{ L_572 , L_573 , L_469 , 10 } ,
{ L_574 , L_575 , L_469 , 10 } ,
{ L_576 , L_577 , L_469 , 10 } ,
{ L_578 , L_579 , L_469 , 10 } ,
{ L_580 , L_581 , L_508 , 10 } ,
{ L_582 , L_583 , L_508 , 10 } ,
{ L_584 , L_585 , L_508 , 10 } ,
{ L_586 , L_587 , L_508 , 10 } ,
{ L_588 , L_563 , L_508 , 10 } ,
{ L_589 , L_590 , L_508 , 10 } ,
{ L_591 , L_569 , L_508 , 10 } ,
{ L_592 , L_593 , L_508 , 10 } ,
{ L_594 , L_595 , L_508 , 10 } ,
{ L_596 , L_597 , L_508 , 10 } ,
{ L_598 , L_538 , L_508 , 10 } ,
{ L_599 , L_600 , L_508 , 10 } ,
{ L_601 , L_602 , L_508 , 10 } ,
{ L_603 , L_604 , L_508 , 10 } ,
{ L_605 , L_501 , L_508 , 10 } ,
} ;
struct V_410 V_415 [] = {
{ L_606 , L_607 , L_469 , 10 } ,
{ L_608 , L_609 , L_469 , 10 } ,
{ L_610 , L_611 , L_469 , 10 } ,
{ L_612 , L_613 , L_469 , 10 } ,
{ L_614 , L_615 , L_469 , 10 } ,
{ L_616 , L_617 , L_469 , 10 } ,
{ L_618 , L_619 , L_469 , 10 } ,
} ;
struct V_412 V_416 [] = {
{ L_620 } ,
{ L_621 } ,
{ L_622 } ,
{ L_623 } ,
{ L_624 } ,
{ L_625 } ,
} ;
unsigned int V_125 ;
char * V_47 ;
T_6 V_142 ;
T_30 V_122 ;
T_31 V_123 , V_417 ;
T_7 * V_36 ;
T_1 * V_1 ;
for ( V_125 = 0 ; V_125 < sizeof( V_413 ) / sizeof( struct V_410 ) ; V_125 ++ )
{
if ( strcmp ( V_99 , V_413 [ V_125 ] . V_99 ) == 0 )
{
V_142 = ( T_6 ) strtoul ( V_61 , & V_47 , V_413 [ V_125 ] . V_77 ) ;
if ( V_47 == V_61 || * V_47 != '\0' )
return FALSE ;
V_36 = F_33 ( ( T_15 * ) V_413 [ V_125 ] . V_98 ) ;
V_1 = F_64 ( V_36 , V_413 [ V_125 ] . V_411 ) ;
if ( V_1 != NULL )
{
V_36 -> V_49 = TRUE ;
* V_1 -> V_13 . V_79 = V_142 ;
}
if ( V_142 != 0 )
{
V_122 = F_134 ( V_413 [ V_125 ] . V_411 ) ;
if ( V_122 != NULL ) {
V_123 = F_135 ( V_122 , ( T_15 * ) V_413 [ V_125 ] . V_98 ) ;
if ( V_123 != NULL ) {
F_136 ( V_413 [ V_125 ] . V_411 , V_142 , V_123 ) ;
F_138 ( V_413 [ V_125 ] . V_411 , F_139 ( V_122 ) , F_140 ( V_142 ) , NULL , NULL ) ;
}
}
}
return TRUE ;
}
}
for ( V_125 = 0 ; V_125 < sizeof( V_414 ) / sizeof( struct V_410 ) ; V_125 ++ )
{
if ( strcmp ( V_99 , V_414 [ V_125 ] . V_99 ) == 0 )
{
T_3 V_418 , V_419 ;
V_122 = F_134 ( V_414 [ V_125 ] . V_411 ) ;
if ( V_122 != NULL ) {
switch ( F_139 ( V_122 ) ) {
case V_420 :
case V_421 :
case V_422 :
case V_423 :
break;
default:
F_38 ( L_626 , V_414 [ V_125 ] . V_411 , F_268 ( V_414 [ V_125 ] . V_411 ) ) ;
F_82 () ;
}
V_36 = F_33 ( ( T_15 * ) V_414 [ V_125 ] . V_98 ) ;
V_1 = F_64 ( V_36 , V_414 [ V_125 ] . V_411 ) ;
if ( V_1 != NULL )
{
if ( ! F_103 ( V_1 , V_61 , TRUE , & V_36 -> V_49 ) )
{
return FALSE ;
}
V_123 = F_135 ( V_122 , ( T_15 * ) V_414 [ V_125 ] . V_98 ) ;
if ( V_123 != NULL ) {
for ( V_418 = 0 ; V_418 < ( * V_1 -> V_13 . V_30 ) -> V_112 ; V_418 ++ ) {
for ( V_419 = ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_418 ] . V_114 ; V_419 < ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_418 ] . V_115 ; V_419 ++ ) {
F_136 ( V_414 [ V_125 ] . V_411 , V_419 , V_123 ) ;
F_138 ( V_414 [ V_125 ] . V_411 , F_139 ( V_122 ) , F_140 ( V_419 ) , NULL , NULL ) ;
}
F_136 ( V_414 [ V_125 ] . V_411 , ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_418 ] . V_115 , V_123 ) ;
F_138 ( V_414 [ V_125 ] . V_411 , F_139 ( V_122 ) , F_140 ( ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_418 ] . V_115 ) , NULL , NULL ) ;
}
}
}
}
return TRUE ;
}
}
for ( V_125 = 0 ; V_125 < sizeof( V_415 ) / sizeof( struct V_410 ) ; V_125 ++ )
{
if ( strcmp ( V_99 , V_415 [ V_125 ] . V_99 ) == 0 )
{
V_142 = ( T_6 ) strtoul ( V_61 , & V_47 , V_415 [ V_125 ] . V_77 ) ;
if ( V_47 == V_61 || * V_47 != '\0' )
return FALSE ;
if ( ( V_142 != 0 ) && ( V_142 != 102 ) )
{
V_417 = F_269 ( L_627 ) ;
if ( V_417 != NULL ) {
F_136 ( V_415 [ V_125 ] . V_411 , V_142 , V_417 ) ;
}
}
return TRUE ;
}
}
for ( V_125 = 0 ; V_125 < sizeof( V_416 ) / sizeof( struct V_412 ) ; V_125 ++ )
{
if ( strcmp ( V_99 , V_416 [ V_125 ] . V_99 ) == 0 )
{
return TRUE ;
}
}
return FALSE ;
}
static T_27
V_361 ( T_15 * V_99 , const T_15 * V_61 , void * V_363 V_16 ,
T_8 V_95 )
{
unsigned long int V_424 ;
T_6 V_142 ;
T_8 V_425 ;
T_16 V_426 ;
char * V_47 ;
T_15 * V_427 , * V_428 ;
static T_15 * V_429 = NULL ;
static T_8 V_430 = FALSE ;
T_15 * V_431 = NULL ;
T_7 * V_36 , * V_75 ;
T_1 * V_1 ;
int type ;
if ( strcmp ( V_99 , V_432 ) == 0 ) {
V_429 = F_49 ( V_61 ) ;
} else if ( strcmp ( V_99 , V_433 ) == 0 ) {
V_430 = ( strcmp ( V_61 , L_628 ) == 0 ) ? TRUE : FALSE ;
} else if ( strcmp ( V_99 , V_434 ) == 0 ) {
V_431 = F_49 ( V_61 ) ;
F_270 ( V_429 , V_431 , V_430 ) ;
F_14 ( V_429 ) ;
F_14 ( V_431 ) ;
} else if ( strcmp ( V_99 , L_629 ) == 0 ) {
if ( F_217 ( V_61 , L_460 ) == 0 ) {
V_10 . V_252 = V_340 ;
} else {
V_10 . V_252 = V_435 ;
}
} else if ( strcmp ( V_99 , L_630 ) == 0 ||
strcmp ( V_99 , L_631 ) == 0 ) {
if ( F_217 ( V_61 , L_460 ) == 0 ) {
V_436 . V_392 = TRUE ;
V_436 . V_393 = TRUE ;
V_436 . V_395 = TRUE ;
}
else if ( F_217 ( V_61 , L_632 ) == 0 ) {
F_271 () ;
}
else {
F_271 () ;
if ( F_261 ( V_61 , & V_436 ) != '\0' )
return V_171 ;
}
} else if ( F_262 ( V_99 , V_61 ) ) {
} else if ( F_264 ( V_99 , V_61 ) ) {
} else if ( F_267 ( V_99 , V_61 ) ) {
} else {
if ( ( strcmp ( V_99 , L_633 ) == 0 ) ||
( strcmp ( V_99 , L_634 ) == 0 ) ||
( strcmp ( V_99 , L_635 ) == 0 ) ) {
V_36 = V_284 ;
V_427 = V_99 ;
} else {
V_36 = NULL ;
V_428 = V_99 ;
while ( ! V_36 ) {
V_427 = strchr ( V_428 , '.' ) ;
if ( V_427 == NULL ) {
return V_119 ;
}
* V_427 = '\0' ;
V_36 = F_33 ( V_99 ) ;
if ( V_36 == NULL ) {
if ( strcmp ( V_99 , L_636 ) == 0 )
V_36 = V_148 ;
else if ( strcmp ( V_99 , L_637 ) == 0 )
V_36 = F_33 ( L_638 ) ;
else if ( strcmp ( V_99 , L_639 ) == 0 )
V_36 = F_33 ( L_640 ) ;
else if ( strcmp ( V_99 , L_641 ) == 0 ||
strcmp ( V_99 , L_642 ) == 0 )
V_36 = F_33 ( L_643 ) ;
else if ( strcmp ( V_99 , L_644 ) == 0 )
V_36 = F_33 ( L_645 ) ;
else if ( strcmp ( V_99 , L_646 ) == 0 )
V_36 = F_33 ( L_647 ) ;
else if ( strcmp ( V_99 , L_648 ) == 0 )
V_36 = F_33 ( L_649 ) ;
else if ( strcmp ( V_99 , L_650 ) == 0 )
V_36 = F_33 ( L_651 ) ;
else if ( strcmp ( V_99 , L_652 ) == 0 )
V_36 = F_33 ( L_653 ) ;
else if ( strcmp ( V_99 , L_654 ) == 0 )
V_36 = F_33 ( L_655 ) ;
else if ( strcmp ( V_99 , L_656 ) == 0 ||
strcmp ( V_99 , L_657 ) == 0 ) {
return V_379 ;
}
if ( V_36 ) {
F_246 ( L_658
L_659 ,
V_99 , V_427 + 1 , V_36 -> V_43 -> V_5 , V_99 , V_427 + 1 ) ;
V_10 . V_378 = TRUE ;
}
}
* V_427 = '.' ;
V_427 ++ ;
V_428 = V_427 ;
}
}
V_75 = V_36 ;
V_1 = F_75 ( V_36 , V_427 , & V_75 ) ;
if ( V_1 == NULL ) {
V_10 . V_378 = TRUE ;
if ( V_36 == V_148 ) {
V_1 = F_64 ( V_36 , V_99 ) ;
}
else if ( strcmp ( V_36 -> V_5 , L_660 ) == 0 ) {
if ( strcmp ( V_427 , L_661 ) == 0 )
V_1 = F_64 ( V_36 , L_662 ) ;
else if ( strcmp ( V_427 , L_663 ) == 0 )
V_1 = F_64 ( V_36 , L_664 ) ;
else if ( strcmp ( V_427 , L_469 ) == 0 ) {
V_359 ++ ;
if ( V_359 == 1 ) {
V_1 = F_64 ( V_36 , L_665 ) ;
} else if ( V_359 == 2 ) {
V_1 = F_64 ( V_36 , L_666 ) ;
}
} else if ( strcmp ( V_427 , L_508 ) == 0 ) {
V_360 ++ ;
if ( V_360 == 1 ) {
V_1 = F_64 ( V_36 , L_667 ) ;
} else if ( V_360 == 2 ) {
V_1 = F_64 ( V_36 , L_668 ) ;
}
}
} else if ( strcmp ( V_36 -> V_5 , L_669 ) == 0 ) {
if ( strcmp ( V_427 , L_670 ) == 0 )
V_1 = F_64 ( V_36 , L_671 ) ;
else if ( strcmp ( V_427 , L_672 ) == 0 )
V_1 = F_64 ( V_36 , L_673 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_674 ) == 0 ) {
if ( strcmp ( V_427 , L_675 ) == 0 )
V_1 = F_64 ( V_36 , L_676 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_638 ) == 0 ) {
if ( strcmp ( V_427 , L_677 ) == 0 )
V_1 = F_64 ( V_36 , L_676 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_678 ) == 0 ) {
if ( strcmp ( V_427 , L_679 ) == 0 )
V_1 = F_64 ( V_36 , L_680 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_681 ) == 0 ) {
if ( strcmp ( V_427 , L_682 ) == 0 )
V_1 = F_64 ( V_36 , L_680 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_683 ) == 0 ) {
if ( strcmp ( V_427 , L_684 ) == 0 )
V_1 = F_64 ( V_36 , L_685 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_686 ) == 0 ) {
if ( strcmp ( V_427 , L_687 ) == 0 )
V_1 = F_64 ( V_36 , L_688 ) ;
else if ( strcmp ( V_427 , L_689 ) == 0 )
V_1 = F_64 ( V_36 , L_690 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_691 ) == 0 ) {
if ( strcmp ( V_427 , L_692 ) == 0 )
V_1 = F_64 ( V_36 , L_676 ) ;
else if ( strcmp ( V_427 , L_693 ) == 0 )
V_1 = F_64 ( V_36 , L_694 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_643 ) == 0 ) {
if ( strcmp ( V_427 , L_695 ) == 0 )
V_1 = F_64 ( V_36 , L_696 ) ;
else if ( strcmp ( V_427 , L_697 ) == 0 )
V_1 = F_64 ( V_36 , L_698 ) ;
else if ( strcmp ( V_427 , L_699 ) == 0 )
V_1 = F_64 ( V_36 , L_700 ) ;
else if ( strcmp ( V_427 , L_701 ) == 0 )
V_1 = F_64 ( V_36 , L_702 ) ;
else if ( strcmp ( V_427 , L_703 ) == 0 )
V_1 = F_64 ( V_36 , L_704 ) ;
else if ( strcmp ( V_427 , L_705 ) == 0 )
V_1 = F_64 ( V_36 , L_706 ) ;
else if ( strcmp ( V_427 , L_707 ) == 0 )
V_1 = F_64 ( V_36 , L_708 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_709 ) == 0 ) {
if ( strcmp ( V_427 , L_710 ) == 0 )
V_1 = F_64 ( V_36 , L_711 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_712 ) == 0 ) {
if ( strcmp ( V_427 , L_713 ) == 0 )
V_1 = F_64 ( V_36 , L_694 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_714 ) == 0 ) {
if ( strcmp ( V_427 , L_715 ) == 0 )
V_1 = F_64 ( V_36 , L_716 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_717 ) == 0 ) {
if ( strcmp ( V_427 , L_718 ) == 0 )
V_1 = F_64 ( V_36 , L_719 ) ;
else if ( strcmp ( V_427 , L_720 ) == 0 )
V_1 = F_64 ( V_36 , L_721 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_722 ) == 0 ) {
if ( strcmp ( V_427 , L_723 ) == 0 )
V_1 = F_64 ( V_36 , L_724 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_725 ) == 0 ) {
if ( strcmp ( V_427 , L_726 ) == 0 )
V_1 = F_64 ( V_36 , L_727 ) ;
else if ( strcmp ( V_427 , L_728 ) == 0 )
V_1 = F_64 ( V_36 , L_729 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_730 ) == 0 ) {
if ( strcmp ( V_427 , L_731 ) == 0 )
V_1 = F_64 ( V_36 , L_732 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_733 ) == 0 ) {
if ( strcmp ( V_427 , L_734 ) == 0 )
V_1 = F_64 ( V_36 , L_711 ) ;
else if ( strcmp ( V_427 , L_735 ) == 0 )
V_1 = F_64 ( V_36 , L_736 ) ;
else if ( strcmp ( V_427 , L_737 ) == 0 )
V_1 = F_64 ( V_36 , L_738 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_739 ) == 0 ) {
if ( strcmp ( V_427 , L_740 ) == 0 )
V_1 = F_64 ( V_36 , L_711 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_741 ) == 0 ) {
if ( strcmp ( V_427 , L_742 ) == 0 )
V_1 = F_64 ( V_36 , L_743 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_744 ) == 0 ) {
if ( strcmp ( V_427 , L_745 ) == 0 )
V_1 = F_64 ( V_36 , L_746 ) ;
else if ( strcmp ( V_427 , L_747 ) == 0 )
V_1 = F_64 ( V_36 , L_748 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_749 ) == 0 ) {
T_7 * V_56 = F_33 ( L_645 ) ;
if ( V_56 ) {
if ( strcmp ( V_427 , L_750 ) == 0 ) {
V_1 = F_64 ( V_56 , L_750 ) ;
V_75 = V_56 ;
} else if ( strcmp ( V_427 , L_751 ) == 0 ) {
V_1 = F_64 ( V_56 , L_751 ) ;
V_75 = V_56 ;
}
}
} else if ( strcmp ( V_36 -> V_5 , L_752 ) == 0 ) {
if ( strcmp ( V_427 , L_753 ) == 0 )
V_1 = F_64 ( V_36 , L_754 ) ;
else if ( strcmp ( V_427 , L_680 ) == 0 )
V_1 = F_64 ( V_36 , L_755 ) ;
else if ( strcmp ( V_427 , L_756 ) == 0 )
V_1 = F_64 ( V_36 , L_757 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_758 ) == 0 ) {
if ( strcmp ( V_427 , L_759 ) == 0 )
V_1 = F_64 ( V_36 , L_760 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_761 ) == 0 ) {
if ( strcmp ( V_427 , L_762 ) == 0 ) {
V_1 = F_64 ( V_36 , L_763 ) ;
if ( strcmp ( V_61 , L_763 ) == 0 || strcmp ( V_61 , L_764 ) == 0 )
V_61 = L_628 ;
else if ( strcmp ( V_61 , L_765 ) == 0 || strcmp ( V_61 , L_766 ) == 0 )
V_61 = L_767 ;
else if ( strcmp ( V_61 , L_768 ) == 0 || strcmp ( V_61 , L_769 ) == 0 )
V_61 = L_628 ;
} else if ( strcmp ( V_427 , L_770 ) == 0 ) {
V_1 = F_64 ( V_36 , L_771 ) ;
if ( strcmp ( V_61 , L_772 ) == 0 || strcmp ( V_61 , L_773 ) == 0 )
V_61 = L_774 ;
else if ( strcmp ( V_61 , L_775 ) == 0 || strcmp ( V_61 , L_776 ) == 0 )
V_61 = L_775 ;
else if ( strcmp ( V_61 , L_768 ) == 0 || strcmp ( V_61 , L_769 ) == 0 )
V_61 = L_774 ;
} else if ( strcmp ( V_427 , L_777 ) == 0 ) {
V_1 = F_64 ( V_36 , L_778 ) ;
if ( strcmp ( V_61 , L_779 ) == 0 || strcmp ( V_61 , L_780 ) == 0 )
V_61 = L_779 ;
else if ( strcmp ( V_61 , L_725 ) == 0 || strcmp ( V_61 , L_781 ) == 0 )
V_61 = L_725 ;
else if ( strcmp ( V_61 , L_782 ) == 0 || strcmp ( V_61 , L_783 ) == 0 )
V_61 = L_784 ;
else if ( strcmp ( V_61 , L_785 ) == 0 || strcmp ( V_61 , L_786 ) == 0 )
V_61 = L_785 ;
else if ( strcmp ( V_61 , L_768 ) == 0 || strcmp ( V_61 , L_769 ) == 0 )
V_61 = L_774 ;
}
} else if ( strcmp ( V_36 -> V_5 , L_765 ) == 0 ) {
if ( strcmp ( V_427 , L_787 ) == 0 ) {
T_7 * V_56 = F_33 ( L_788 ) ;
if ( V_56 ) {
V_1 = F_64 ( V_56 , L_787 ) ;
V_75 = V_56 ;
}
}
} else if ( strcmp ( V_36 -> V_5 , L_340 ) == 0 ) {
if ( strcmp ( V_427 , L_276 ) == 0 ||
strcmp ( V_427 , L_279 ) == 0 )
V_1 = F_64 ( V_60 , V_427 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_342 ) == 0 ) {
if ( strcmp ( V_427 , L_331 ) == 0 )
V_1 = F_64 ( V_53 , V_427 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_344 ) == 0 ) {
if ( ( strcmp ( V_427 , L_789 ) == 0 ) ||
( strcmp ( V_427 , L_790 ) == 0 ) ||
( strcmp ( V_427 , L_791 ) == 0 ) ||
( strcmp ( V_427 , L_792 ) == 0 ) )
V_1 = F_64 ( V_218 , V_99 ) ;
} else if ( strcmp ( V_36 -> V_5 , L_258 ) == 0 ) {
if ( strcmp ( V_99 , L_633 ) == 0 ) {
V_1 = F_64 ( V_284 , V_99 ) ;
} else if ( strcmp ( V_99 , L_634 ) == 0 ) {
V_1 = F_64 ( V_284 , L_793 ) ;
} else if ( strcmp ( V_99 , L_635 ) == 0 ) {
V_1 = F_64 ( V_284 , L_794 ) ;
}
}
}
if ( V_1 == NULL )
return V_119 ;
type = V_1 -> type ;
if ( F_65 ( type ) ) {
return V_379 ;
} else {
F_16 ( type ) ;
}
switch ( type ) {
case V_19 :
V_142 = ( T_6 ) strtoul ( V_61 , & V_47 , V_1 -> V_6 . V_77 ) ;
if ( V_47 == V_61 || * V_47 != '\0' )
return V_171 ;
if ( * V_1 -> V_13 . V_79 != V_142 ) {
V_75 -> V_49 = TRUE ;
* V_1 -> V_13 . V_79 = V_142 ;
}
break;
case V_20 :
{
T_30 V_122 ;
T_31 V_123 ;
V_142 = ( T_6 ) strtoul ( V_61 , & V_47 , V_1 -> V_6 . V_77 ) ;
if ( V_47 == V_61 || * V_47 != '\0' )
return V_171 ;
if ( * V_1 -> V_13 . V_79 != V_142 ) {
V_75 -> V_49 = TRUE ;
* V_1 -> V_13 . V_79 = V_142 ;
V_122 = F_134 ( V_1 -> V_5 ) ;
if ( V_122 != NULL ) {
V_123 = F_135 ( V_122 , ( T_15 * ) V_36 -> V_3 ) ;
if ( V_123 != NULL ) {
if ( V_142 != 0 ) {
F_136 ( V_1 -> V_5 , V_142 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( V_142 ) , NULL , NULL ) ;
} else {
F_137 ( V_1 -> V_5 , * V_1 -> V_13 . V_79 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , V_1 -> V_13 . V_79 , NULL , NULL ) ;
}
}
}
}
break;
}
case V_17 :
if ( F_217 ( V_61 , L_460 ) == 0 )
V_425 = TRUE ;
else
V_425 = FALSE ;
if ( * V_1 -> V_13 . V_81 != V_425 ) {
V_75 -> V_49 = TRUE ;
* V_1 -> V_13 . V_81 = V_425 ;
}
break;
case V_18 :
V_426 = F_216 ( V_61 , V_1 -> V_6 . V_91 . V_87 ,
* V_1 -> V_13 . V_89 ) ;
if ( * V_1 -> V_13 . V_89 != V_426 ) {
V_75 -> V_49 = TRUE ;
* V_1 -> V_13 . V_89 = V_426 ;
}
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_75 -> V_49 |= F_91 ( V_1 , V_61 , V_86 ) ;
break;
case V_28 :
{
if ( ! F_103 ( V_1 , V_61 , V_95 ,
& V_75 -> V_49 ) )
return V_171 ;
break;
}
case V_29 :
{
T_22 * V_96 ;
T_30 V_122 ;
T_31 V_123 ;
T_3 V_125 , V_126 ;
if ( F_104 ( F_12 () , & V_96 , V_61 , V_1 -> V_6 . V_7 ,
V_95 ) != V_97 ) {
return V_171 ;
}
if ( ! F_105 ( * V_1 -> V_13 . V_30 , V_96 ) ) {
F_17 ( F_12 () , * V_1 -> V_13 . V_30 ) ;
* V_1 -> V_13 . V_30 = V_96 ;
V_75 -> V_49 = TRUE ;
V_122 = F_134 ( V_1 -> V_5 ) ;
if ( V_122 != NULL ) {
V_123 = F_135 ( V_122 , ( T_15 * ) V_36 -> V_3 ) ;
if ( V_123 != NULL ) {
for ( V_125 = 0 ; V_125 < ( * V_1 -> V_13 . V_30 ) -> V_112 ; V_125 ++ ) {
for ( V_126 = ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_114 ; V_126 < ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 ; V_126 ++ ) {
F_137 ( V_1 -> V_5 , V_126 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( V_126 ) , NULL , NULL ) ;
}
F_137 ( V_1 -> V_5 , ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( ( * V_1 -> V_13 . V_30 ) -> V_113 [ V_125 ] . V_115 ) , NULL , NULL ) ;
}
for ( V_125 = 0 ; V_125 < V_96 -> V_112 ; V_125 ++ ) {
for ( V_126 = V_96 -> V_113 [ V_125 ] . V_114 ; V_126 < V_96 -> V_113 [ V_125 ] . V_115 ; V_126 ++ ) {
F_136 ( V_1 -> V_5 , V_126 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( V_126 ) , NULL , NULL ) ;
}
F_136 ( V_1 -> V_5 , V_96 -> V_113 [ V_125 ] . V_115 , V_123 ) ;
F_138 ( V_1 -> V_5 , F_139 ( V_122 ) , F_140 ( V_96 -> V_113 [ V_125 ] . V_115 ) , NULL , NULL ) ;
}
}
}
} else {
F_17 ( F_12 () , V_96 ) ;
}
break;
}
case V_23 :
{
V_424 = strtoul ( V_61 , NULL , 16 ) ;
if ( ( V_1 -> V_13 . V_105 -> V_106 != F_272 ( V_424 ) ) ||
( V_1 -> V_13 . V_105 -> V_107 != F_273 ( V_424 ) ) ||
( V_1 -> V_13 . V_105 -> V_108 != F_274 ( V_424 ) ) ) {
V_75 -> V_49 = TRUE ;
V_1 -> V_13 . V_105 -> V_106 = F_272 ( V_424 ) ;
V_1 -> V_13 . V_105 -> V_107 = F_273 ( V_424 ) ;
V_1 -> V_13 . V_105 -> V_108 = F_274 ( V_424 ) ;
}
break;
}
case V_31 :
return V_1 -> V_34 . V_208 ( V_1 , V_61 , & V_75 -> V_49 ) ;
case V_21 :
case V_22 :
{
break;
}
}
}
return V_118 ;
}
const char *
F_275 ( T_1 * V_1 )
{
const char * V_437 = L_795 ;
int type ;
if ( ! V_1 ) {
return V_437 ;
}
type = V_1 -> type ;
if ( F_65 ( type ) ) {
V_437 = L_796 ;
} else {
F_16 ( type ) ;
}
switch ( type ) {
case V_19 :
switch ( V_1 -> V_6 . V_77 ) {
case 10 :
V_437 = L_797 ;
break;
case 8 :
V_437 = L_798 ;
break;
case 16 :
V_437 = L_799 ;
break;
}
break;
case V_17 :
V_437 = L_800 ;
break;
case V_18 :
V_437 = L_801 ;
break;
case V_24 :
V_437 = L_802 ;
break;
case V_25 :
case V_26 :
V_437 = L_803 ;
break;
case V_27 :
V_437 = L_804 ;
break;
case V_28 :
V_437 = L_805 ;
break;
case V_23 :
V_437 = L_806 ;
break;
case V_31 :
if ( V_1 -> V_34 . V_209 )
return V_1 -> V_34 . V_209 () ;
V_437 = L_807 ;
break;
case V_20 :
V_437 = L_808 ;
break;
case V_29 :
V_437 = L_809 ;
break;
case V_21 :
V_437 = L_810 ;
break;
case V_22 :
V_437 = L_811 ;
break;
}
return V_437 ;
}
char *
F_276 ( T_1 * V_1 )
{
const char * V_438 = L_812 ;
int type ;
if ( ! V_1 ) {
return F_156 ( L_813 , V_438 ) ;
}
type = V_1 -> type ;
if ( F_65 ( type ) ) {
V_438 = L_814 ;
} else {
F_16 ( type ) ;
}
switch ( type ) {
case V_19 :
switch ( V_1 -> V_6 . V_77 ) {
case 10 :
V_438 = L_815 ;
break;
case 8 :
V_438 = L_816 ;
break;
case 16 :
V_438 = L_817 ;
break;
}
break;
case V_17 :
V_438 = L_818 ;
break;
case V_18 :
{
const T_21 * V_439 = V_1 -> V_6 . V_91 . V_87 ;
T_34 * V_440 = F_164 ( L_819 ) ;
while ( V_439 -> V_5 != NULL ) {
F_166 ( V_440 , V_439 -> V_2 ) ;
V_439 ++ ;
if ( V_439 -> V_5 != NULL )
F_166 ( V_440 , L_820 ) ;
}
F_166 ( V_440 , L_821 ) ;
return F_167 ( V_440 , FALSE ) ;
break;
}
case V_24 :
V_438 = L_822 ;
break;
case V_25 :
case V_26 :
V_438 = L_823 ;
break;
case V_27 :
V_438 = L_824 ;
break;
case V_28 :
{
V_438 = L_825 ;
break;
}
case V_23 :
{
V_438 = L_826 ;
break;
}
case V_31 :
if ( V_1 -> V_34 . V_210 )
return V_1 -> V_34 . V_210 () ;
V_438 = L_827 ;
break;
case V_20 :
V_438 = L_828 ;
break;
case V_29 :
V_438 = L_829 ;
break;
case V_21 :
V_438 = L_830 ;
break;
case V_22 :
V_438 = L_831 ;
break;
default:
break;
}
return F_49 ( V_438 ) ;
}
T_8
F_277 ( T_1 * V_1 )
{
int type ;
if ( ! V_1 ) return FALSE ;
type = V_1 -> type ;
if ( F_65 ( type ) ) {
return FALSE ;
} else {
F_16 ( type ) ;
}
switch ( type ) {
case V_20 :
if ( V_1 -> V_14 . V_79 == * V_1 -> V_13 . V_79 )
return TRUE ;
break;
case V_19 :
if ( V_1 -> V_14 . V_79 == * V_1 -> V_13 . V_79 )
return TRUE ;
break;
case V_17 :
if ( V_1 -> V_14 . V_33 == * V_1 -> V_13 . V_81 )
return TRUE ;
break;
case V_18 :
if ( V_1 -> V_14 . V_90 == * V_1 -> V_13 . V_89 )
return TRUE ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
if ( ! ( F_169 ( V_1 -> V_14 . string , * V_1 -> V_13 . string ) ) )
return TRUE ;
break;
case V_29 :
case V_28 :
{
if ( ( F_105 ( V_1 -> V_14 . V_30 , * V_1 -> V_13 . V_30 ) ) )
return TRUE ;
break;
}
case V_23 :
{
if ( ( V_1 -> V_14 . V_104 . V_106 == V_1 -> V_13 . V_105 -> V_106 ) &&
( V_1 -> V_14 . V_104 . V_107 == V_1 -> V_13 . V_105 -> V_107 ) &&
( V_1 -> V_14 . V_104 . V_108 == V_1 -> V_13 . V_105 -> V_108 ) )
return TRUE ;
break;
}
case V_31 :
return V_1 -> V_34 . V_211 ( V_1 ) ;
case V_21 :
case V_22 :
return FALSE ;
break;
}
return FALSE ;
}
char *
F_278 ( T_1 * V_1 , T_20 V_82 ) {
const char * V_441 = L_795 ;
void * V_442 ;
T_24 * V_443 ;
T_15 * V_444 , * V_445 ;
int type ;
if ( ! V_1 ) {
return F_49 ( V_441 ) ;
}
switch ( V_82 ) {
case V_84 :
V_442 = & V_1 -> V_14 ;
V_443 = & V_1 -> V_14 . V_104 ;
break;
case V_85 :
V_442 = & V_1 -> V_32 ;
V_443 = & V_1 -> V_32 . V_104 ;
break;
case V_86 :
V_442 = V_1 -> V_13 . V_79 ;
V_443 = V_1 -> V_13 . V_105 ;
break;
default:
return F_49 ( V_441 ) ;
}
type = V_1 -> type ;
if ( F_65 ( type ) ) {
V_441 = L_832 ;
} else {
F_16 ( type ) ;
}
switch ( type ) {
case V_20 :
case V_19 :
{
T_6 V_446 = * ( T_6 * ) V_442 ;
switch ( V_1 -> V_6 . V_77 ) {
case 10 :
return F_156 ( L_26 , V_446 ) ;
case 8 :
return F_156 ( L_833 , V_446 ) ;
case 16 :
return F_156 ( L_834 , V_446 ) ;
}
break;
}
case V_17 :
return F_49 ( ( * ( T_8 * ) V_442 ) ? L_628 : L_767 ) ;
case V_18 :
{
T_16 V_447 = * ( T_16 * ) V_442 ;
const T_21 * V_439 = V_1 -> V_6 . V_91 . V_87 ;
while ( V_439 -> V_5 != NULL ) {
if ( V_439 -> V_61 == V_447 )
return F_49 ( V_439 -> V_2 ) ;
V_439 ++ ;
}
break;
}
case V_24 :
case V_25 :
case V_26 :
case V_27 :
return F_49 ( * ( const char * * ) V_442 ) ;
case V_29 :
case V_28 :
V_444 = F_279 ( NULL , * ( T_22 * * ) V_442 ) ;
V_445 = F_49 ( V_444 ) ;
F_17 ( NULL , V_444 ) ;
return V_445 ;
case V_23 :
return F_156 ( L_835 ,
( V_443 -> V_106 * 255 / 65535 ) ,
( V_443 -> V_107 * 255 / 65535 ) ,
( V_443 -> V_108 * 255 / 65535 ) ) ;
case V_31 :
if ( V_1 -> V_34 . V_212 )
return V_1 -> V_34 . V_212 ( V_1 , V_82 == V_84 ? TRUE : FALSE ) ;
V_441 = L_836 ;
break;
case V_21 :
V_441 = L_830 ;
break;
case V_22 :
{
T_23 * V_101 = V_1 -> V_13 . V_101 ;
if ( V_101 && V_101 -> V_448 )
return F_156 ( L_837 , V_101 -> V_448 ) ;
else
V_441 = L_838 ;
break;
}
default:
break;
}
return F_49 ( V_441 ) ;
}
static void
F_280 ( T_4 V_15 , T_4 T_5 )
{
T_1 * V_1 = ( T_1 * ) V_15 ;
T_44 * V_72 = ( T_44 * ) T_5 ;
T_15 * * V_449 ;
int V_125 ;
int type ;
type = V_1 -> type ;
if ( F_65 ( type ) ) {
return;
} else {
F_16 ( type ) ;
}
switch ( type ) {
case V_21 :
case V_22 :
return;
case V_20 :
case V_29 :
return;
default:
break;
}
if ( V_1 -> type != V_31 || V_1 -> V_34 . V_209 () != NULL ) {
const char * V_67 = ( V_72 -> V_36 -> V_5 != NULL ) ? V_72 -> V_36 -> V_5 : V_72 -> V_36 -> V_43 -> V_5 ;
char * V_438 , * V_441 ;
const char * V_450 = F_277 ( V_1 ) ? L_839 : L_14 ;
if ( V_1 -> type == V_31 ) fprintf ( V_72 -> V_354 , L_840 , V_1 -> V_34 . V_209 () ) ;
fprintf ( V_72 -> V_354 , L_841 ) ;
if ( V_1 -> V_2 &&
( F_281 ( V_1 -> V_2 , L_14 , 2 ) != 0 ) ) {
if ( V_1 -> type != V_31 ) {
V_449 = F_220 ( V_1 -> V_2 , L_841 , 0 ) ;
for ( V_125 = 0 ; V_449 [ V_125 ] != NULL ; ++ V_125 ) {
fprintf ( V_72 -> V_354 , L_842 , V_449 [ V_125 ] ) ;
}
F_221 ( V_449 ) ;
}
} else {
fprintf ( V_72 -> V_354 , L_843 ) ;
}
V_438 = F_276 ( V_1 ) ;
V_449 = F_220 ( V_438 , L_841 , 0 ) ;
for ( V_125 = 0 ; V_449 [ V_125 ] != NULL ; ++ V_125 ) {
fprintf ( V_72 -> V_354 , L_842 , V_449 [ V_125 ] ) ;
}
F_221 ( V_449 ) ;
F_14 ( V_438 ) ;
V_441 = F_278 ( V_1 , V_86 ) ;
fprintf ( V_72 -> V_354 , L_844 , V_450 , V_67 , V_1 -> V_5 ) ;
V_449 = F_220 ( V_441 , L_841 , 0 ) ;
for ( V_125 = 0 ; V_449 [ V_125 ] != NULL ; ++ V_125 ) {
fprintf ( V_72 -> V_354 , L_845 , V_125 == 0 ? L_14 : V_450 , V_449 [ V_125 ] ) ;
}
if ( V_125 == 0 ) fprintf ( V_72 -> V_354 , L_841 ) ;
F_221 ( V_449 ) ;
F_14 ( V_441 ) ;
}
}
static T_6
F_282 ( T_7 * V_36 , T_4 T_5 )
{
T_45 * V_451 = ( T_45 * ) T_5 ;
T_44 V_72 ;
if ( ( V_36 == V_198 ) && ( V_451 -> V_452 != TRUE ) )
return 0 ;
if ( ( ( V_36 -> V_43 == NULL ) || ( V_36 -> V_43 == V_198 ) ) &&
( ( F_57 ( V_36 ) ) ||
( V_36 -> V_37 > 0 ) ||
( V_36 -> V_5 == NULL ) ) ) {
if ( ( V_36 -> V_5 == NULL ) && ( V_36 -> V_43 != NULL ) ) {
fprintf ( V_451 -> V_354 , L_846 , V_36 -> V_43 -> V_3 , V_36 -> V_3 ) ;
} else {
fprintf ( V_451 -> V_354 , L_847 , V_36 -> V_3 ) ;
}
}
V_72 . V_36 = V_36 ;
V_72 . V_354 = V_451 -> V_354 ;
F_19 ( V_72 . V_36 -> V_10 , F_280 , & V_72 ) ;
if ( F_57 ( V_36 ) )
return F_21 ( V_36 , F_282 , T_5 ) ;
return 0 ;
}
int
F_283 ( char * * V_453 )
{
char * V_353 ;
T_39 * V_354 ;
T_45 V_454 ;
F_223 () ;
if ( V_453 != NULL ) {
V_353 = F_241 ( V_355 , TRUE ) ;
if ( ( V_354 = F_237 ( V_353 , L_848 ) ) == NULL ) {
* V_453 = V_353 ;
return V_356 ;
}
F_14 ( V_353 ) ;
} else {
V_354 = stdout ;
}
fputs ( L_849 V_455 L_850
L_851
L_852
L_853
L_854
L_855 , V_354 ) ;
V_454 . V_354 = V_354 ;
V_454 . V_452 = TRUE ;
F_282 ( V_198 , & V_454 ) ;
{
struct V_456 * V_457 = * (struct V_456 * * ) V_10 . V_458 ;
if ( V_457 != NULL )
fprintf ( V_354 , L_856 ) ;
while ( V_457 != NULL ) {
if ( V_457 -> V_459 == FALSE ) {
fprintf ( V_354 , L_857 , V_432 , V_457 -> V_460 ) ;
fprintf ( V_354 , L_857 , V_433 ,
V_457 -> V_406 == TRUE ? L_628 : L_767 ) ;
fprintf ( V_354 , L_857 , V_434 , V_457 -> V_461 ) ;
}
V_457 = V_457 -> V_150 ;
}
}
V_454 . V_452 = FALSE ;
F_21 ( NULL , F_282 , & V_454 ) ;
fclose ( V_354 ) ;
return 0 ;
}
static void
F_178 ( T_19 * V_110 )
{
T_33 * V_146 ;
T_19 * V_462 = V_110 ;
while ( V_110 != NULL ) {
V_146 = ( T_33 * ) V_110 -> V_15 ;
F_14 ( V_146 -> V_3 ) ;
F_14 ( V_146 -> V_156 ) ;
F_14 ( V_146 ) ;
V_110 = F_145 ( V_110 ) ;
}
F_20 ( V_462 ) ;
}
