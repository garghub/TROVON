void
F_1 ( void )
{
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = F_2 ( F_3 () ) ;
V_3 = F_2 ( F_3 () ) ;
}
static void
F_4 ( T_1 V_4 , T_1 T_2 V_5 )
{
T_3 * V_6 = ( T_3 * ) V_4 ;
switch ( V_6 -> type ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
break;
case V_14 :
case V_15 :
case V_16 :
F_5 ( ( char * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = NULL ;
F_5 ( V_6 -> V_18 . string ) ;
V_6 -> V_18 . string = NULL ;
break;
case V_19 :
F_5 ( * V_6 -> V_17 . V_20 ) ;
* V_6 -> V_17 . V_20 = NULL ;
F_5 ( V_6 -> V_18 . V_20 ) ;
V_6 -> V_18 . V_20 = NULL ;
break;
case V_21 :
if ( strcmp ( V_6 -> V_22 , L_1 ) == 0 )
V_6 -> V_23 . V_24 = TRUE ;
V_6 -> V_25 . V_26 ( V_6 ) ;
break;
}
F_5 ( V_6 ) ;
}
static T_4
F_6 ( T_5 * V_27 , T_1 V_4 V_5 )
{
if ( V_27 -> V_1 ) {
F_7 ( V_27 -> V_1 , F_4 , NULL ) ;
F_8 ( V_27 -> V_1 ) ;
}
V_27 -> V_1 = NULL ;
V_27 -> V_28 = 0 ;
if ( V_27 -> V_29 ) {
F_9 ( V_27 , F_6 , NULL ) ;
}
return 0 ;
}
void
F_10 ( void )
{
F_11 ( F_6 , NULL ) ;
}
T_5 *
F_12 ( T_5 * V_30 , const char * V_22 , const char * V_31 ,
const char * V_32 , void (* F_13)( void ) ,
const T_6 V_33 )
{
return F_14 ( V_30 , V_22 , V_31 , V_32 ,
FALSE , F_13 , V_33 ) ;
}
static void
F_15 ( T_5 * V_30 , const char * V_22 , const char * V_31 )
{
T_5 * V_27 = ( T_5 * ) F_16 ( V_2 , V_22 , V_34 ) ;
if ( ! V_27 )
return;
if ( V_30 == NULL ) {
F_16 ( V_3 , V_31 , V_34 ) ;
} else if ( V_30 -> V_29 ) {
F_16 ( V_30 -> V_29 , V_31 , V_34 ) ;
}
F_6 ( V_27 , NULL ) ;
F_17 ( F_3 () , V_27 ) ;
}
T_5 *
F_18 ( T_5 * V_30 , const char * V_31 , const char * V_32 ,
void (* F_13)( void ) )
{
return F_14 ( V_30 , NULL , V_31 , V_32 ,
TRUE , F_13 ,
V_30 ? V_30 -> V_33 : FALSE ) ;
}
static T_5 *
F_14 ( T_5 * V_30 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_6 V_35 , void (* F_13)( void ) ,
T_6 V_33 )
{
T_5 * V_27 ;
const char * V_36 ;
T_7 V_37 ;
if ( ( V_27 = F_19 ( V_30 , V_31 ) ) ) {
V_27 -> V_22 = V_22 ;
V_27 -> F_13 = F_13 ;
V_27 -> V_32 = V_32 ;
if ( F_20 ( V_22 ) == NULL ) {
F_21 ( V_2 , V_22 , V_27 ,
V_34 ) ;
}
return V_27 ;
}
V_27 = F_22 ( F_3 () , T_5 ) ;
V_27 -> V_22 = V_22 ;
V_27 -> V_31 = V_31 ;
V_27 -> V_32 = V_32 ;
V_27 -> F_13 = F_13 ;
V_27 -> V_1 = NULL ;
V_27 -> V_30 = V_30 ;
V_27 -> V_29 = NULL ;
V_27 -> V_28 = 0 ;
V_27 -> V_38 = FALSE ;
V_27 -> V_39 = FALSE ;
V_27 -> V_33 = V_33 ;
if ( V_22 != NULL ) {
for ( V_36 = V_22 ; ( V_37 = * V_36 ) != '\0' ; V_36 ++ )
F_23 ( F_24 ( V_37 ) || F_25 ( V_37 ) || V_37 == '_' ||
V_37 == '-' || V_37 == '.' ) ;
F_23 ( F_20 ( V_22 ) == NULL ) ;
F_21 ( V_2 , V_22 , V_27 , V_34 ) ;
} else {
F_23 ( V_35 ) ;
}
if ( V_30 == NULL ) {
F_21 ( V_3 , V_31 , V_27 , V_34 ) ;
} else {
if ( V_30 -> V_29 == NULL )
V_30 -> V_29 = F_2 ( F_3 () ) ;
F_21 ( V_30 -> V_29 , V_31 , V_27 , V_34 ) ;
}
return V_27 ;
}
T_5 *
F_26 ( int V_40 , void (* F_13)( void ) )
{
T_8 * V_41 ;
if ( V_42 == NULL ) {
F_27 () ;
F_28 () ;
}
V_41 = F_29 ( V_40 ) ;
return F_12 ( V_42 ,
F_30 ( V_40 ) ,
F_31 ( V_41 ) ,
F_32 ( V_40 ) , F_13 , TRUE ) ;
}
void
F_33 ( int V_40 )
{
T_8 * V_41 = F_29 ( V_40 ) ;
F_15 ( V_42 ,
F_30 ( V_40 ) ,
F_31 ( V_41 ) ) ;
}
T_5 *
F_34 ( const char * V_43 , int V_40 , void (* F_13)( void ) )
{
T_8 * V_41 ;
T_5 * V_44 ;
T_5 * V_45 ;
char * V_46 = NULL , * V_47 = NULL , * V_48 = NULL ;
if ( V_42 == NULL ) {
F_27 () ;
F_28 () ;
}
V_44 = V_42 ;
if ( V_43 ) {
V_48 = V_47 = F_35 ( V_43 ) ;
while ( V_47 && * V_47 ) {
if ( ( V_46 = strchr ( V_47 , '/' ) ) )
* V_46 ++ = '\0' ;
if ( ! ( V_45 = F_19 ( V_44 , V_47 ) ) ) {
V_47 = F_36 ( F_3 () , V_47 ) ,
V_45 = F_18 ( V_44 , V_47 , V_47 , NULL ) ;
}
V_44 = V_45 ;
V_47 = V_46 ;
}
F_5 ( V_48 ) ;
}
V_41 = F_29 ( V_40 ) ;
return F_12 ( V_44 ,
F_30 ( V_40 ) ,
F_31 ( V_41 ) ,
F_32 ( V_40 ) , F_13 , TRUE ) ;
}
T_5 *
F_37 ( int V_40 )
{
T_5 * V_27 ;
T_8 * V_41 ;
if ( V_42 == NULL ) {
F_27 () ;
F_28 () ;
}
V_41 = F_29 ( V_40 ) ;
V_27 = F_12 ( V_42 ,
F_30 ( V_40 ) ,
F_31 ( V_41 ) ,
F_32 ( V_40 ) , NULL , TRUE ) ;
V_27 -> V_39 = TRUE ;
return V_27 ;
}
T_5 *
F_38 ( const char * V_22 , const char * V_31 ,
const char * V_32 , void (* F_13)( void ) )
{
if ( V_49 == NULL ) {
F_27 () ;
F_28 () ;
}
return F_12 ( V_49 , V_22 , V_31 , V_32 ,
F_13 , TRUE ) ;
}
T_5 *
F_20 ( const char * V_22 )
{
return ( T_5 * ) F_39 ( V_2 , V_22 , V_34 ) ;
}
static T_5 *
F_19 ( T_5 * V_30 , const char * V_22 )
{
return ( T_5 * ) F_39 ( V_30 ? V_30 -> V_29 : V_3 , V_22 , V_34 ) ;
}
static T_6
F_40 ( const void * T_9 V_5 , void * V_50 , void * V_4 )
{
T_5 * V_27 = ( T_5 * ) V_50 ;
T_10 * V_51 = ( T_10 * ) V_4 ;
if ( ! V_27 -> V_39 )
V_51 -> V_52 = (* V_51 -> V_53 )( V_27 , V_51 -> T_2 ) ;
return ( V_51 -> V_52 != 0 ) ;
}
static T_4
F_41 ( T_11 * V_54 , T_12 V_53 ,
T_1 T_2 )
{
T_10 V_51 ;
if ( V_54 == NULL )
V_54 = V_3 ;
V_51 . V_53 = V_53 ;
V_51 . T_2 = T_2 ;
V_51 . V_52 = 0 ;
F_42 ( V_54 , F_40 , & V_51 ) ;
return V_51 . V_52 ;
}
T_6
F_43 ( T_5 * V_27 )
{
if ( V_27 -> V_29 == NULL ) {
return FALSE ;
}
if ( F_44 ( V_27 -> V_29 ) ) {
return FALSE ;
}
return TRUE ;
}
T_4
F_11 ( T_12 V_53 , T_1 T_2 )
{
return F_41 ( V_2 , V_53 , T_2 ) ;
}
T_4
F_9 ( T_5 * V_27 , T_12 V_53 ,
T_1 T_2 )
{
return F_41 ( ( V_27 ) ? V_27 -> V_29 : V_3 , V_53 , T_2 ) ;
}
static T_6
F_45 ( const void * T_9 V_5 , void * V_50 , void * V_4 V_5 )
{
T_5 * V_27 = ( T_5 * ) V_50 ;
if ( V_27 -> V_39 )
return FALSE ;
if ( V_27 -> V_38 ) {
if ( V_27 -> F_13 != NULL )
(* V_27 -> F_13 )() ;
V_27 -> V_38 = FALSE ;
}
return FALSE ;
}
void
F_46 ( void )
{
F_42 ( V_2 , F_45 , NULL ) ;
}
void
F_47 ( T_5 * V_27 )
{
if ( V_27 && V_27 -> V_38 )
F_45 ( NULL , V_27 , NULL ) ;
}
static T_3 *
F_48 ( T_5 * V_27 , const char * V_22 , const char * V_31 ,
const char * V_32 , T_13 type )
{
T_3 * V_55 ;
const T_14 * V_36 ;
V_55 = F_49 ( T_3 , 1 ) ;
V_55 -> V_22 = V_22 ;
V_55 -> V_31 = V_31 ;
V_55 -> V_32 = V_32 ;
V_55 -> type = type ;
V_55 -> V_56 = V_57 ;
if ( V_31 != NULL )
V_55 -> V_58 = V_27 -> V_28 ;
else
V_55 -> V_58 = - 1 ;
for ( V_36 = V_22 ; * V_36 != '\0' ; V_36 ++ )
if ( ! ( F_24 ( * V_36 ) || F_25 ( * V_36 ) || * V_36 == '_' || * V_36 == '.' ) )
F_50 ( L_2 , V_27 -> V_22 , V_22 ) ;
if ( F_51 ( V_27 , V_22 ) != NULL )
F_50 ( L_3 , V_22 ) ;
if ( ( type != V_7 ) &&
( V_27 -> V_22 != NULL ) ) {
if ( ! ( ( strncmp ( V_22 , V_27 -> V_22 , strlen ( V_27 -> V_22 ) ) != 0 ) ||
( ( ( V_22 [ strlen ( V_27 -> V_22 ) ] ) != '.' ) && ( ( V_22 [ strlen ( V_27 -> V_22 ) ] ) != '_' ) ) ) )
F_50 ( L_4 , V_22 ) ;
}
V_27 -> V_1 = F_52 ( V_27 -> V_1 , V_55 ) ;
if ( V_31 != NULL )
V_27 -> V_28 ++ ;
return V_55 ;
}
static T_15
F_53 ( T_16 V_59 , T_16 V_60 )
{
const T_3 * V_6 = ( const T_3 * ) V_59 ;
const char * V_22 = ( const char * ) V_60 ;
return strcmp ( V_22 , V_6 -> V_22 ) ;
}
static T_6
F_54 ( const void * T_9 V_5 , void * V_50 , void * V_4 )
{
T_17 * V_61 = ( T_17 * ) V_4 ;
T_18 * V_62 ;
T_5 * V_27 = ( T_5 * ) V_50 ;
if ( V_27 == NULL )
return FALSE ;
V_62 = F_55 ( V_27 -> V_1 , V_61 -> V_22 ,
F_53 ) ;
if ( V_62 == NULL )
return FALSE ;
V_61 -> V_62 = V_62 ;
return TRUE ;
}
struct V_55 *
F_51 ( T_5 * V_27 , const char * V_22 )
{
T_17 V_61 ;
T_18 * V_62 ;
if ( V_27 == NULL )
return NULL ;
V_62 = F_55 ( V_27 -> V_1 , V_22 ,
F_53 ) ;
if ( V_62 == NULL )
{
V_61 . V_62 = NULL ;
if ( V_27 -> V_29 != NULL )
{
V_61 . V_22 = V_22 ;
F_42 ( V_27 -> V_29 , F_54 , & V_61 ) ;
}
V_62 = V_61 . V_62 ;
}
if ( V_62 == NULL )
return NULL ;
return (struct V_55 * ) V_62 -> V_4 ;
}
T_6
F_56 ( const char * V_22 )
{
T_5 * V_63 = F_20 ( V_22 ) ;
return ( V_63 != NULL && ! V_63 -> V_39 ) ;
}
const char *
F_57 ( const char * V_22 )
{
T_5 * V_63 = F_20 ( V_22 ) ;
return ( V_63 != NULL && ! V_63 -> V_39 ) ? V_63 -> V_31 : NULL ;
}
void
F_58 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_4 V_64 , T_4 * V_65 )
{
T_3 * V_55 ;
V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 ,
V_10 ) ;
V_55 -> V_17 . V_66 = V_65 ;
V_55 -> V_18 . V_66 = * V_65 ;
F_23 ( V_64 > 0 && V_64 != 1 && V_64 < 37 ) ;
V_55 -> V_67 . V_64 = V_64 ;
}
static void
F_59 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_25 , T_4 * V_65 )
{
T_3 * V_55 ;
V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 ,
V_21 ) ;
V_55 -> V_25 = * V_25 ;
V_55 -> V_17 . V_66 = V_65 ;
V_55 -> V_18 . V_66 = * V_65 ;
}
void
F_60 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_6 * V_65 )
{
T_3 * V_55 ;
V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 ,
V_8 ) ;
V_55 -> V_17 . V_69 = V_65 ;
V_55 -> V_18 . V_24 = * V_65 ;
}
void
F_61 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_15 * V_65 , const T_19 * V_70 ,
T_6 V_71 )
{
T_3 * V_55 ;
V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 ,
V_9 ) ;
V_55 -> V_17 . V_72 = V_65 ;
V_55 -> V_18 . V_73 = * V_65 ;
V_55 -> V_67 . V_74 . V_70 = V_70 ;
V_55 -> V_67 . V_74 . V_71 = V_71 ;
}
static T_3 *
F_62 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 , T_13 type )
{
T_3 * V_55 ;
char * V_75 ;
V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 ,
type ) ;
if ( * V_65 == NULL ) {
* V_65 = F_35 ( L_5 ) ;
V_75 = F_35 ( L_5 ) ;
} else {
* V_65 = F_35 ( * V_65 ) ;
V_75 = F_35 ( * V_65 ) ;
}
V_55 -> V_17 . string = V_65 ;
V_55 -> V_18 . string = V_75 ;
V_55 -> V_23 . string = NULL ;
return V_55 ;
}
void
F_63 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 )
{
F_62 ( V_27 , V_22 , V_31 , V_32 , V_65 ,
V_14 ) ;
}
static void
F_64 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_25 , const char * * V_65 )
{
T_3 * V_55 ;
V_55 = F_62 ( V_27 , V_22 , V_31 , V_32 , V_65 ,
V_21 ) ;
V_55 -> V_25 = * V_25 ;
}
void
F_65 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 )
{
F_62 ( V_27 , V_22 , V_31 , V_32 , V_65 ,
V_15 ) ;
}
void
F_66 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 )
{
F_62 ( V_27 , V_22 , V_31 , V_32 , V_65 ,
V_16 ) ;
}
void
F_67 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_20 * * V_65 , T_21 V_76 )
{
T_3 * V_55 ;
V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 ,
V_19 ) ;
V_55 -> V_67 . V_76 = V_76 ;
if ( * V_65 == NULL )
* V_65 = F_68 () ;
V_55 -> V_17 . V_20 = V_65 ;
V_55 -> V_18 . V_20 = F_69 ( * V_65 ) ;
V_55 -> V_23 . V_20 = NULL ;
}
void
F_70 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 ,
const char * V_32 )
{
F_48 ( V_27 , V_22 , V_31 , V_32 , V_11 ) ;
}
extern void
F_71 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_22 * V_77 )
{
T_3 * V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 , V_12 ) ;
V_55 -> V_17 . V_77 = V_77 ;
}
extern void
F_72 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_22 * V_77 )
{
T_3 * V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 , V_12 ) ;
V_55 -> V_17 . V_77 = V_77 ;
V_55 -> V_56 = V_78 ;
}
void
F_73 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
T_23 * V_79 )
{
T_3 * V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 , V_13 ) ;
V_55 -> V_17 . V_80 = V_79 ;
V_55 -> V_18 . V_79 = * V_79 ;
}
static void
F_74 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_25 ,
T_24 V_81 ,
T_18 * * V_82 )
{
T_3 * V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 , V_21 ) ;
V_55 -> V_25 = * V_25 ;
V_81 ( V_55 , V_82 ) ;
}
void
F_75 ( T_5 * V_27 , const char * V_22 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_25 ,
void * * T_25 V_5 )
{
T_3 * V_55 = F_48 ( V_27 , V_22 , V_31 , V_32 , V_21 ) ;
V_55 -> V_25 = * V_25 ;
}
void
F_76 ( T_5 * V_27 , const char * V_22 )
{
F_48 ( V_27 , V_22 , NULL , NULL , V_7 ) ;
}
extern T_6
F_77 ( T_3 * V_6 )
{
if ( V_6 )
return V_6 -> type == V_7 ? TRUE : FALSE ;
return TRUE ;
}
extern T_26
F_78 ( T_3 * V_6 )
{
if ( V_6 ) {
V_6 -> type = V_7 ;
return V_83 ;
}
return V_84 ;
}
T_4
F_79 ( T_5 * V_27 , T_27 V_53 , T_1 T_2 )
{
T_18 * V_85 ;
T_3 * V_6 ;
T_4 V_52 ;
for ( V_85 = F_80 ( V_27 -> V_1 ) ; V_85 != NULL ; V_85 = F_81 ( V_85 ) ) {
V_6 = ( T_3 * ) V_85 -> V_4 ;
if ( V_6 -> type == V_7 ) {
continue;
}
V_52 = (* V_53)( V_6 , T_2 ) ;
if ( V_52 != 0 )
return V_52 ;
}
return 0 ;
}
static void
F_82 ( void )
{
if ( V_1 . V_86 < 100 || V_1 . V_86 > 10000 )
V_1 . V_86 = V_87 ;
#ifdef F_83
if ( V_1 . V_88 < 1 || V_1 . V_88 > 10 )
V_1 . V_88 = V_89 ;
#endif
if ( V_1 . V_90 < 1 ) {
V_1 . V_90 = 1 ;
}
else if ( V_1 . V_90 > V_91 ) {
V_1 . V_90 = V_91 ;
}
if ( V_1 . V_92 < V_1 . V_90 ) {
V_1 . V_92 = V_1 . V_90 ;
}
V_1 . V_92 -= V_1 . V_92 % V_1 . V_90 ;
if ( ( V_1 . V_92 / V_1 . V_90 ) > V_93 ) {
V_1 . V_92 = V_1 . V_90 * V_93 ;
}
}
static void
F_84 ( void )
{
if ( V_1 . V_94 == 0 )
V_1 . V_94 = 10 ;
if ( V_1 . V_95 == 0 )
V_1 . V_95 = 10 ;
}
static void
F_85 ( void )
{
if ( V_1 . V_96 == V_97 ||
V_1 . V_96 >= V_98 ) {
V_1 . V_96 = V_99 ;
}
}
static void F_86 ( T_3 * V_6 V_5 ) {}
static void
F_87 ( T_3 * V_6 )
{
* V_6 -> V_17 . V_66 = V_6 -> V_18 . V_66 ;
}
static T_26
F_88 ( T_3 * V_6 , const T_14 * V_50 , T_6 * V_100 )
{
T_4 V_101 ;
V_101 = ( T_4 ) strtoul ( V_50 , NULL , 10 ) ;
if ( * V_6 -> V_17 . V_66 != V_101 ) {
* V_100 = TRUE ;
* V_6 -> V_17 . V_66 = V_101 ;
}
if ( * V_6 -> V_17 . V_66 & ( V_102 | V_103 ) ) {
F_89 ( L_6 , L_7 , TRUE ) ;
}
return V_83 ;
}
static const char * F_90 ( void ) {
return L_8 ;
}
static char * F_91 ( void ) {
return F_92 (
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ) ;
}
static T_6 F_93 ( T_3 * V_6 ) {
return * V_6 -> V_17 . V_66 == V_6 -> V_18 . V_66 ;
}
static char * F_94 ( T_3 * V_6 , T_6 V_18 ) {
return F_92 ( L_17 , V_18 ? V_6 -> V_18 . V_66 : * V_6 -> V_17 . V_66 ) ;
}
static void
F_95 ( T_3 * V_6 )
{
F_5 ( ( char * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = NULL ;
F_5 ( V_6 -> V_18 . string ) ;
V_6 -> V_18 . string = NULL ;
}
static void
F_96 ( T_3 * V_6 )
{
F_5 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_35 ( V_6 -> V_18 . string ) ;
}
static T_26
F_97 ( T_3 * V_6 , const T_14 * V_50 , T_6 * V_100 )
{
T_18 * V_104 ;
T_28 * V_105 ;
T_3 * V_106 ;
if ( * V_6 -> V_17 . string ) {
if ( strcmp ( * V_6 -> V_17 . string , V_50 ) != 0 ) {
* V_100 = TRUE ;
F_5 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_35 ( V_50 ) ;
}
} else if ( V_50 ) {
* V_6 -> V_17 . string = F_35 ( V_50 ) ;
}
V_106 = F_51 ( V_107 , V_108 ) ;
for ( V_104 = * V_106 -> V_17 . V_82 ; V_104 != NULL ; V_104 = V_104 -> V_109 ) {
V_105 = ( T_28 * ) V_104 -> V_4 ;
V_105 -> V_110 = F_98 ( * V_6 -> V_17 . string , V_105 ) ;
}
return V_83 ;
}
static const char *
F_99 ( void )
{
return L_18 ;
}
static char *
F_100 ( void )
{
return F_35 ( L_19 ) ;
}
static char *
F_101 ( T_3 * V_6 , T_6 V_18 )
{
T_29 * V_111 = F_102 ( L_5 ) ;
T_18 * V_104 ;
T_28 * V_105 ;
T_3 * V_106 ;
if ( V_18 )
return F_35 ( V_6 -> V_18 . string ) ;
V_106 = F_51 ( V_107 , V_108 ) ;
V_104 = ( V_106 ) ? * V_106 -> V_17 . V_82 : NULL ;
while ( V_104 ) {
T_14 * V_112 ;
V_105 = ( T_28 * ) V_104 -> V_4 ;
if ( ( V_105 -> V_113 == V_114 ) && ( V_105 -> V_115 ) ) {
V_112 = F_92 ( L_20 ,
F_103 ( V_105 -> V_113 ) ,
V_105 -> V_115 ,
V_105 -> V_116 ,
V_105 -> V_117 ? 'R' : 'U' ) ;
} else {
V_112 = F_35 ( F_103 ( V_105 -> V_113 ) ) ;
}
if ( ! V_105 -> V_110 ) {
if ( V_111 -> V_118 )
F_104 ( V_111 , L_21 ) ;
F_104 ( V_111 , V_112 ) ;
}
F_5 ( V_112 ) ;
V_104 = V_104 -> V_109 ;
}
return F_105 ( V_111 , FALSE ) ;
}
static T_6
F_106 ( T_3 * V_6 )
{
char * V_119 = F_101 ( V_6 , FALSE ) ;
T_6 V_120 = F_107 ( V_119 , V_6 -> V_18 . string ) == 0 ;
F_5 ( V_119 ) ;
return V_120 ;
}
static void
F_108 ( T_3 * V_6 )
{
* V_6 -> V_17 . V_66 = V_6 -> V_18 . V_66 ;
}
static T_26
F_109 ( T_3 * V_6 V_5 , const T_14 * V_50 V_5 , T_6 * V_100 V_5 )
{
return V_83 ;
}
static const char *
F_110 ( void )
{
return NULL ;
}
static char *
F_111 ( void )
{
return F_35 ( L_5 ) ;
}
static T_6
F_112 ( T_3 * V_6 V_5 )
{
return TRUE ;
}
static char *
F_113 ( T_3 * V_6 V_5 , T_6 V_18 V_5 )
{
return F_35 ( L_5 ) ;
}
static void
F_114 ( T_3 * V_6 , T_18 * * V_50 )
{
T_28 * V_121 , * V_122 ;
T_18 * V_123 ;
V_6 -> V_17 . V_82 = V_50 ;
V_6 -> V_18 . V_82 = NULL ;
for ( V_123 = * V_6 -> V_17 . V_82 ; V_123 != NULL ; V_123 = F_81 ( V_123 ) ) {
V_121 = ( T_28 * ) V_123 -> V_4 ;
V_122 = F_49 ( T_28 , 1 ) ;
V_122 -> V_31 = F_35 ( V_121 -> V_31 ) ;
V_122 -> V_113 = V_121 -> V_113 ;
if ( V_121 -> V_115 ) {
V_122 -> V_115 = F_35 ( V_121 -> V_115 ) ;
V_122 -> V_116 = V_121 -> V_116 ;
} else {
V_122 -> V_115 = NULL ;
V_122 -> V_116 = 0 ;
}
V_122 -> V_110 = V_121 -> V_110 ;
V_122 -> V_117 = V_121 -> V_117 ;
V_6 -> V_18 . V_82 = F_52 ( V_6 -> V_18 . V_82 , V_122 ) ;
}
}
static void
F_115 ( T_3 * V_6 )
{
F_116 ( * V_6 -> V_17 . V_82 ) ;
F_116 ( V_6 -> V_18 . V_82 ) ;
}
static void
F_117 ( T_3 * V_6 )
{
T_28 * V_121 , * V_122 ;
T_18 * V_123 ;
T_3 * V_124 ;
F_116 ( * V_6 -> V_17 . V_82 ) ;
* V_6 -> V_17 . V_82 = NULL ;
for ( V_123 = V_6 -> V_18 . V_82 ; V_123 != NULL ; V_123 = F_81 ( V_123 ) ) {
V_121 = ( T_28 * ) V_123 -> V_4 ;
V_122 = F_49 ( T_28 , 1 ) ;
V_122 -> V_31 = F_35 ( V_121 -> V_31 ) ;
V_122 -> V_113 = V_121 -> V_113 ;
if ( V_121 -> V_115 ) {
V_122 -> V_115 = F_35 ( V_121 -> V_115 ) ;
V_122 -> V_116 = V_121 -> V_116 ;
} else {
V_122 -> V_115 = NULL ;
V_122 -> V_116 = 0 ;
}
V_122 -> V_110 = V_121 -> V_110 ;
V_122 -> V_117 = V_121 -> V_117 ;
* V_6 -> V_17 . V_82 = F_52 ( * V_6 -> V_17 . V_82 , V_122 ) ;
}
V_124 = F_51 ( V_107 , V_125 ) ;
F_23 ( V_124 != NULL ) ;
F_108 ( V_124 ) ;
}
static T_26
F_118 ( T_3 * V_6 , const T_14 * V_50 , T_6 * V_100 V_5 )
{
T_18 * V_126 , * V_127 ;
T_28 * V_105 ;
T_15 V_128 ;
T_3 * V_129 , * V_124 ;
V_126 = F_119 ( V_50 ) ;
if ( V_126 == NULL )
return V_130 ;
if ( ( F_120 ( V_126 ) % 2 ) != 0 ) {
F_121 ( V_126 ) ;
return V_130 ;
}
V_127 = F_80 ( V_126 ) ;
while ( V_127 ) {
T_28 V_131 ;
V_127 = V_127 -> V_109 ;
if ( ! F_122 ( & V_131 , ( char * ) V_127 -> V_4 ) ) {
F_121 ( V_126 ) ;
return V_130 ;
}
if ( V_131 . V_113 != V_114 ) {
F_123 ( & V_127 -> V_4 ) ;
} else {
F_5 ( V_131 . V_115 ) ;
}
V_127 = V_127 -> V_109 ;
}
F_116 ( * V_6 -> V_17 . V_82 ) ;
* V_6 -> V_17 . V_82 = NULL ;
V_129 = F_51 ( V_107 , V_132 ) ;
F_23 ( V_129 != NULL ) ;
V_124 = F_51 ( V_107 , V_125 ) ;
F_23 ( V_124 != NULL ) ;
V_128 = F_120 ( V_126 ) ;
* V_124 -> V_17 . V_66 = V_128 / 2 ;
V_127 = F_80 ( V_126 ) ;
while ( V_127 ) {
V_105 = F_49 ( T_28 , 1 ) ;
V_105 -> V_31 = F_35 ( ( T_14 * ) V_127 -> V_4 ) ;
V_127 = V_127 -> V_109 ;
F_122 ( V_105 , ( char * ) V_127 -> V_4 ) ;
V_105 -> V_110 = F_98 ( * V_129 -> V_17 . string , V_105 ) ;
V_127 = V_127 -> V_109 ;
* V_6 -> V_17 . V_82 = F_52 ( * V_6 -> V_17 . V_82 , V_105 ) ;
}
F_121 ( V_126 ) ;
F_95 ( V_129 ) ;
return V_83 ;
}
static const char *
F_124 ( void )
{
return L_22 ;
}
static char *
F_125 ( void )
{
return F_35 ( L_23 ) ;
}
static T_6
F_126 ( T_3 * V_6 )
{
T_18 * V_104 = * V_6 -> V_17 . V_82 ,
* V_133 = F_80 ( V_104 ) ,
* V_134 = F_80 ( V_6 -> V_18 . V_82 ) ;
T_28 * V_105 , * V_135 ;
T_6 V_120 = TRUE ;
T_3 * V_124 ;
V_124 = F_51 ( V_107 , V_125 ) ;
if ( V_124 && * V_124 -> V_17 . V_66 != V_124 -> V_18 . V_66 ) {
V_120 = FALSE ;
} else {
while ( V_133 && V_134 ) {
V_105 = ( T_28 * ) V_133 -> V_4 ;
V_135 = ( T_28 * ) V_134 -> V_4 ;
if ( ( F_107 ( V_105 -> V_31 , V_135 -> V_31 ) != 0 ) ||
( V_105 -> V_113 != V_135 -> V_113 ) ||
( ( ( V_105 -> V_113 == V_114 ) && ( V_105 -> V_115 ) ) &&
( ( F_107 ( V_105 -> V_115 , V_135 -> V_115 ) != 0 ) ||
( V_105 -> V_117 != V_135 -> V_117 ) ) ) ) {
V_120 = FALSE ;
break;
}
V_133 = V_133 -> V_109 ;
V_134 = V_134 -> V_109 ;
}
}
return V_120 ;
}
static char *
F_127 ( T_3 * V_6 , T_6 V_18 )
{
T_18 * V_136 = V_18 ? V_6 -> V_18 . V_82 : * V_6 -> V_17 . V_82 ;
T_18 * V_104 = F_80 ( V_136 ) ;
T_18 * V_126 ;
T_28 * V_105 ;
T_14 * V_112 ;
char * V_137 ;
V_126 = NULL ;
while ( V_104 ) {
V_105 = ( T_28 * ) V_104 -> V_4 ;
V_126 = F_52 ( V_126 , F_35 ( V_105 -> V_31 ) ) ;
if ( ( V_105 -> V_113 == V_114 ) && ( V_105 -> V_115 ) ) {
V_112 = F_92 ( L_20 ,
F_103 ( V_105 -> V_113 ) ,
V_105 -> V_115 ,
V_105 -> V_116 ,
V_105 -> V_117 ? 'R' : 'U' ) ;
} else {
V_112 = F_35 ( F_103 ( V_105 -> V_113 ) ) ;
}
V_126 = F_52 ( V_126 , V_112 ) ;
V_104 = V_104 -> V_109 ;
}
V_137 = F_128 ( V_126 ) ;
F_121 ( V_126 ) ;
return V_137 ;
}
static void
F_129 ( T_3 * V_6 , T_18 * * V_138 )
{
T_18 * V_139 = * V_138 ,
* V_140 = NULL ;
while ( V_139 ) {
V_140 = F_52 ( V_140 , F_35 ( ( T_14 * ) V_139 -> V_4 ) ) ;
V_139 = V_139 -> V_109 ;
}
V_6 -> V_18 . V_82 = V_140 ;
V_6 -> V_17 . V_82 = & V_1 . V_141 ;
V_6 -> V_23 . V_24 = FALSE ;
}
static void
F_130 ( T_3 * V_6 )
{
F_121 ( V_1 . V_141 ) ;
V_1 . V_141 = NULL ;
if ( V_6 -> V_23 . V_24 == TRUE ) {
F_121 ( V_6 -> V_18 . V_82 ) ;
V_6 -> V_18 . V_82 = NULL ;
}
}
static void
F_131 ( T_3 * V_6 )
{
T_18 * V_142 = NULL , * V_140 ;
F_121 ( * V_6 -> V_17 . V_82 ) ;
for ( V_140 = V_6 -> V_18 . V_82 ; V_140 != NULL ; V_140 = F_81 ( V_140 ) ) {
V_142 = F_52 ( V_142 , F_35 ( ( T_14 * ) V_140 -> V_4 ) ) ;
}
* V_6 -> V_17 . V_82 = V_142 ;
}
static T_26
F_132 ( T_3 * V_6 , const T_14 * V_50 , T_6 * V_100 V_5 )
{
T_18 * V_126 = F_119 ( V_50 ) ;
T_18 * V_127 ;
T_14 * V_143 ;
int V_144 ;
if ( V_126 == NULL )
return V_130 ;
F_130 ( V_6 ) ;
V_127 = F_80 ( V_126 ) ;
if ( ! ( * ( T_14 * ) V_127 -> V_4 ) ) {
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ ) {
V_143 = F_35 ( V_146 [ V_144 ] ) ;
V_1 . V_141 = F_52 ( V_1 . V_141 , V_143 ) ;
}
}
while ( V_127 ) {
T_6 V_147 = FALSE ;
V_143 = ( T_14 * ) V_127 -> V_4 ;
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ ) {
if ( strcmp ( V_143 , V_146 [ V_144 ] ) == 0 ) {
V_147 = TRUE ;
break;
}
}
if ( ! V_147 ) {
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ ) {
V_143 = F_35 ( V_146 [ V_144 ] ) ;
V_1 . V_141 = F_52 ( V_1 . V_141 , V_143 ) ;
}
V_6 -> V_17 . V_82 = & V_1 . V_141 ;
F_121 ( V_126 ) ;
return V_130 ;
}
V_127 = V_127 -> V_109 ;
}
V_127 = F_80 ( V_126 ) ;
while ( V_127 ) {
V_143 = ( T_14 * ) V_127 -> V_4 ;
V_1 . V_141 = F_52 ( V_1 . V_141 , V_143 ) ;
V_127 = V_127 -> V_109 ;
}
V_6 -> V_17 . V_82 = & V_1 . V_141 ;
F_8 ( V_126 ) ;
return V_83 ;
}
static const char *
F_133 ( void )
{
return L_24 ;
}
static char *
F_134 ( void )
{
return F_35 (
L_25
V_148 ) ;
}
static T_6
F_135 ( T_3 * V_6 )
{
T_18 * V_133 = F_80 ( V_1 . V_141 ) ,
* V_134 = F_80 ( V_6 -> V_18 . V_82 ) ;
T_6 V_120 = TRUE ;
while ( V_133 && V_134 ) {
if ( strcmp ( ( T_14 * ) V_133 -> V_4 , ( T_14 * ) V_134 -> V_4 ) != 0 ) {
V_120 = FALSE ;
break;
}
V_133 = V_133 -> V_109 ;
V_134 = V_134 -> V_109 ;
}
if ( ( ( V_133 == NULL ) && ( V_134 != NULL ) ) ||
( ( V_133 != NULL ) && ( V_134 == NULL ) ) )
V_120 = FALSE ;
return V_120 ;
}
static char *
F_136 ( T_3 * V_6 , T_6 V_18 )
{
T_18 * V_136 = V_18 ? V_6 -> V_18 . V_82 : V_1 . V_141 ;
T_18 * V_104 = F_80 ( V_136 ) ;
T_18 * V_126 = NULL ;
T_14 * V_149 ;
char * V_150 ;
while ( V_104 ) {
V_149 = ( T_14 * ) V_104 -> V_4 ;
V_126 = F_52 ( V_126 , F_35 ( V_149 ) ) ;
V_104 = V_104 -> V_109 ;
}
V_150 = F_128 ( V_126 ) ;
F_121 ( V_126 ) ;
return V_150 ;
}
static void
F_137 ( T_3 * V_6 )
{
F_5 ( ( char * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = NULL ;
F_5 ( V_6 -> V_18 . string ) ;
V_6 -> V_18 . string = NULL ;
}
static void
F_138 ( T_3 * V_6 )
{
F_5 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_35 ( V_6 -> V_18 . string ) ;
}
static T_26
F_139 ( T_3 * V_6 , const T_14 * V_50 , T_6 * V_100 )
{
if ( strcmp ( * V_6 -> V_17 . string , V_50 ) != 0 ) {
* V_100 = TRUE ;
F_5 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_35 ( V_50 ) ;
}
return V_83 ;
}
static const char *
F_140 ( void )
{
return NULL ;
}
static char *
F_141 ( void )
{
return F_35 ( L_5 ) ;
}
static T_6
F_142 ( T_3 * V_6 V_5 )
{
return TRUE ;
}
static char *
F_143 ( T_3 * V_6 V_5 , T_6 V_18 V_5 )
{
return F_35 ( L_5 ) ;
}
void
F_28 ( void )
{
T_5 * V_151 , * V_152 , * V_153 ,
* V_154 , * V_155 ;
struct V_68 V_25 ;
T_14 * V_156 ;
if ( V_42 != NULL ) {
return;
}
V_157 = F_12 ( NULL , L_26 , L_27 ,
L_27 , & F_84 , FALSE ) ;
F_61 ( V_157 , L_28 ,
L_29 ,
L_30 ,
( T_15 * ) ( void * ) ( & V_1 . V_158 ) , V_159 , FALSE ) ;
F_76 ( V_157 , L_31 ) ;
F_76 ( V_157 , L_32 ) ;
F_76 ( V_157 , L_33 ) ;
F_60 ( V_157 , L_34 ,
L_35 ,
L_36 ,
& V_1 . V_160 ) ;
F_60 ( V_157 , L_37 ,
L_38 ,
L_39 ,
& V_1 . V_161 ) ;
F_60 ( V_157 , L_40 ,
L_41 ,
L_42 ,
& V_1 . V_162 ) ;
F_61 ( V_157 , L_43 ,
L_44 ,
L_44 ,
& V_1 . V_163 , V_163 , FALSE ) ;
F_61 ( V_157 , L_45 ,
L_46 ,
L_46 ,
& V_1 . V_164 , V_164 , FALSE ) ;
F_61 ( V_157 , L_47 ,
L_48 ,
L_48 ,
& V_1 . V_165 , V_165 , FALSE ) ;
V_107 = F_18 ( V_157 , L_49 , L_49 , NULL ) ;
V_25 . V_26 = F_95 ;
V_25 . V_166 = F_96 ;
V_25 . V_167 = F_97 ;
V_25 . V_168 = F_99 ;
V_25 . V_169 = F_100 ;
V_25 . V_170 = F_106 ;
V_25 . V_171 = F_101 ;
F_64 ( V_107 , V_132 , L_18 ,
L_50 , & V_25 , ( const char * * ) & V_172 ) ;
V_25 . V_26 = F_115 ;
V_25 . V_166 = F_117 ;
V_25 . V_167 = F_118 ;
V_25 . V_168 = F_124 ;
V_25 . V_169 = F_125 ;
V_25 . V_170 = F_126 ;
V_25 . V_171 = F_127 ;
F_74 ( V_107 , V_108 , L_22 ,
L_23 , & V_25 ,
F_114 , & V_1 . V_173 ) ;
V_25 . V_26 = F_86 ;
V_25 . V_166 = F_108 ;
V_25 . V_167 = F_109 ;
V_25 . V_168 = F_110 ;
V_25 . V_169 = F_111 ;
V_25 . V_170 = F_112 ;
V_25 . V_171 = F_113 ;
F_59 ( V_107 , V_125 , L_51 ,
L_52 , & V_25 , & V_1 . V_174 ) ;
V_155 = F_18 ( V_157 , L_53 , L_53 , NULL ) ;
F_76 ( V_155 , L_54 ) ;
V_156 = V_1 . V_175 ;
F_63 ( V_155 , L_55 , L_56 ,
L_57 , ( const char * * ) & V_1 . V_175 ) ;
F_5 ( V_156 ) ;
V_156 = V_1 . V_176 ;
F_63 ( V_155 , L_58 , L_56 ,
L_59 , ( const char * * ) & V_1 . V_176 ) ;
F_5 ( V_156 ) ;
V_177 = F_18 ( V_157 , L_60 , L_60 , NULL ) ;
F_73 ( V_177 , L_61 , L_62 ,
L_62 , & V_1 . V_178 ) ;
F_73 ( V_177 , L_63 , L_62 ,
L_62 , & V_1 . V_179 ) ;
F_73 ( V_177 , L_64 , L_65 ,
L_65 , & V_1 . V_180 ) ;
F_73 ( V_177 , L_66 , L_65 ,
L_65 , & V_1 . V_181 ) ;
F_73 ( V_177 , L_67 , L_68 ,
L_68 , & V_1 . V_182 ) ;
F_73 ( V_177 , L_69 , L_68 ,
L_68 , & V_1 . V_183 ) ;
F_73 ( V_177 , L_70 , L_68 ,
L_68 , & V_1 . V_184 ) ;
F_73 ( V_177 , L_71 , L_68 ,
L_68 , & V_1 . V_185 ) ;
V_25 . V_26 = F_137 ;
V_25 . V_166 = F_138 ;
V_25 . V_167 = F_139 ;
V_25 . V_168 = F_140 ;
V_25 . V_169 = F_141 ;
V_25 . V_170 = F_142 ;
V_25 . V_171 = F_143 ;
V_156 = V_1 . V_186 ;
F_64 ( V_107 , L_72 , L_73 ,
L_74 , & V_25 , ( const char * * ) & V_1 . V_186 ) ;
F_5 ( V_156 ) ;
V_25 . V_26 = F_137 ;
V_25 . V_166 = F_138 ;
V_25 . V_167 = F_139 ;
V_25 . V_168 = F_140 ;
V_25 . V_169 = F_141 ;
V_25 . V_170 = F_142 ;
V_25 . V_171 = F_143 ;
V_156 = V_1 . V_187 ;
F_64 ( V_107 , L_75 , L_76 ,
L_77 , & V_25 , ( const char * * ) & V_1 . V_187 ) ;
F_5 ( V_156 ) ;
F_73 ( V_177 , L_78 , L_79 ,
L_79 , & V_1 . V_188 ) ;
F_73 ( V_177 , L_80 , L_81 ,
L_81 , & V_1 . V_189 ) ;
F_73 ( V_177 , L_82 , L_83 ,
L_83 , & V_1 . V_190 ) ;
F_61 ( V_157 , L_84 ,
L_85 ,
L_85 ,
& V_1 . V_191 , V_191 , FALSE ) ;
F_58 ( V_157 , L_86 ,
L_87 ,
L_87 ,
10 ,
& V_1 . V_94 ) ;
F_58 ( V_157 , L_88 ,
L_89 ,
L_89 ,
10 ,
& V_1 . V_95 ) ;
V_156 = V_1 . V_192 ;
F_66 ( V_157 , L_90 , L_91 ,
L_92 , ( const char * * ) & V_1 . V_192 ) ;
F_5 ( V_156 ) ;
F_76 ( V_157 , L_93 ) ;
F_58 ( V_157 , L_94 ,
L_95 ,
L_95 ,
10 ,
& V_1 . V_193 ) ;
F_60 ( V_157 , L_96 ,
L_97 ,
L_98 ,
& V_1 . V_194 ) ;
F_60 ( V_157 , L_99 ,
L_100 ,
L_101 ,
& V_1 . V_195 ) ;
F_60 ( V_157 , L_102 ,
L_103 ,
L_104 ,
& V_1 . V_196 ) ;
F_60 ( V_157 , L_105 ,
L_106 ,
L_107 ,
& V_1 . V_197 ) ;
F_60 ( V_157 , L_108 ,
L_109 ,
L_110 ,
& V_1 . V_198 ) ;
F_60 ( V_157 , L_111 ,
L_112 ,
L_113 ,
& V_1 . V_199 ) ;
F_60 ( V_157 , L_114 ,
L_115 ,
L_116 ,
& V_1 . V_200 ) ;
F_76 ( V_157 , L_117 ) ;
F_76 ( V_157 , L_118 ) ;
F_76 ( V_157 , L_119 ) ;
F_76 ( V_157 , L_120 ) ;
F_76 ( V_157 , L_121 ) ;
F_61 ( V_157 , L_122 ,
L_123 ,
L_123 ,
& V_1 . V_201 , V_202 , FALSE ) ;
F_61 ( V_157 , L_124 ,
L_125 ,
L_125 ,
& V_1 . V_203 , V_202 , FALSE ) ;
V_156 = V_1 . V_204 ;
F_63 ( V_157 , L_126 , L_127 ,
L_128 , ( const char * * ) & V_1 . V_204 ) ;
F_5 ( V_156 ) ;
F_60 ( V_157 , L_129 ,
L_130 ,
L_131 ,
& V_1 . V_205 ) ;
F_61 ( V_157 , L_132 ,
L_133 ,
L_134 ,
( T_15 * ) ( void * ) ( & V_1 . V_206 ) , V_206 , FALSE ) ;
F_58 ( V_157 , L_135 ,
L_136 ,
L_137 ,
10 ,
& V_1 . V_207 ) ;
V_156 = V_1 . V_208 ;
F_63 ( V_157 , L_138 , L_139 ,
L_140 , ( const char * * ) & V_1 . V_208 ) ;
F_5 ( V_156 ) ;
V_156 = V_1 . V_209 ;
F_63 ( V_157 , L_141 , L_142 ,
L_142 , ( const char * * ) ( & V_1 . V_209 ) ) ;
F_5 ( V_156 ) ;
F_61 ( V_157 , L_143 ,
L_144 ,
L_144 ,
( T_15 * ) ( void * ) ( & V_1 . V_210 ) , V_211 , FALSE ) ;
F_60 ( V_157 , L_145 ,
L_146 ,
L_146 ,
& V_1 . V_212 ) ;
F_58 ( V_157 , L_147 ,
L_148 ,
L_148 ,
10 ,
& V_1 . V_213 ) ;
V_154 = F_18 ( V_157 , L_149 , L_149 , F_85 ) ;
F_58 ( V_154 , L_150 ,
L_151 ,
L_152 ,
10 ,
( T_4 * ) ( void * ) ( & V_1 . V_96 ) ) ;
F_61 ( V_154 , L_153 ,
L_154 ,
L_154 ,
( T_15 * ) ( void * ) ( & V_1 . V_214 ) , V_215 , FALSE ) ;
F_61 ( V_154 , L_155 ,
L_156 ,
L_156 ,
( T_15 * ) ( void * ) ( & V_1 . V_216 ) , V_215 , FALSE ) ;
F_61 ( V_154 , L_157 ,
L_158 ,
L_158 ,
( T_15 * ) ( void * ) ( & V_1 . V_217 ) , V_215 , FALSE ) ;
F_60 ( V_154 , L_159 ,
L_160 ,
L_160 ,
& V_1 . V_218 ) ;
F_60 ( V_157 , L_161 ,
L_162 ,
L_163 ,
& V_1 . V_219 ) ;
F_61 ( V_157 , L_164 ,
L_165 ,
L_166 ,
( T_15 * ) ( void * ) ( & V_1 . V_220 ) , V_220 , FALSE ) ;
F_60 ( V_154 , L_167 ,
L_168 ,
L_169 ,
& V_1 . V_221 ) ;
F_60 ( V_154 , L_170 ,
L_171 ,
L_172 ,
& V_1 . V_222 ) ;
V_153 = F_12 ( NULL , L_173 , L_174 ,
L_175 , NULL , FALSE ) ;
V_25 . V_26 = F_86 ;
V_25 . V_166 = F_87 ;
V_25 . V_167 = F_88 ;
V_25 . V_168 = F_90 ;
V_25 . V_169 = F_91 ;
V_25 . V_170 = F_93 ;
V_25 . V_171 = F_94 ;
F_59 ( V_153 , L_176 , L_177 ,
L_178 , & V_25 , & V_1 . V_223 ) ;
V_152 = F_12 ( NULL , L_179 , L_180 ,
L_181 , NULL , FALSE ) ;
F_63 ( V_152 , L_182 , L_183 ,
L_183 , ( const char * * ) & V_1 . V_224 ) ;
F_63 ( V_152 , L_184 , L_185 ,
L_186 ,
( const char * * ) & V_1 . V_225 ) ;
F_63 ( V_152 , L_187 , L_188 ,
L_189 ,
( const char * * ) & V_1 . V_226 ) ;
F_63 ( V_152 , L_190 , L_191 ,
L_192 , ( const char * * ) & V_1 . V_227 ) ;
F_63 ( V_152 , L_193 , L_194 ,
L_195 ,
( const char * * ) & V_1 . V_228 ) ;
#ifdef F_144
F_63 ( V_152 , L_196 , L_197 ,
L_198 ,
( ( const char * * ) & V_1 . V_229 ) ) ;
#endif
F_63 ( V_152 , L_199 , L_200 ,
L_201 ,
( const char * * ) & V_1 . V_230 ) ;
F_63 ( V_152 , L_202 , L_203 ,
L_204 ,
( const char * * ) & V_1 . V_231 ) ;
F_60 ( V_152 , L_205 , L_206 ,
L_207 , & V_1 . V_232 ) ;
F_63 ( V_152 , L_208 , L_209 ,
L_210 ,
( const char * * ) & V_1 . V_233 ) ;
F_60 ( V_152 , L_211 , L_212 ,
L_213 , & V_1 . V_234 ) ;
F_60 ( V_152 , L_214 , L_215 ,
L_216 , & V_1 . V_235 ) ;
F_60 ( V_152 , L_217 , L_218 ,
L_219 , & V_1 . V_236 ) ;
F_60 ( V_152 , L_220 , L_221 ,
L_222 , & V_1 . V_237 ) ;
F_76 ( V_152 , L_223 ) ;
V_25 . V_26 = F_130 ;
V_25 . V_166 = F_131 ;
V_25 . V_167 = F_132 ;
V_25 . V_168 = F_133 ;
V_25 . V_169 = F_134 ;
V_25 . V_170 = F_135 ;
V_25 . V_171 = F_136 ;
F_74 ( V_152 , L_1 , L_224 ,
L_225 , & V_25 , F_129 , & V_1 . V_141 ) ;
V_238 = F_12 ( NULL , L_226 , L_227 ,
L_227 , NULL , TRUE ) ;
F_145 ( V_238 ) ;
F_146 ( V_238 ) ;
#ifdef F_147
F_148 ( V_238 ) ;
#endif
V_151 = F_12 ( NULL , L_228 , L_229 ,
L_229 , NULL , TRUE ) ;
F_61 ( V_151 , L_230 ,
L_231 , L_232 ,
& V_1 . V_239 , V_240 , TRUE ) ;
F_61 ( V_151 , L_233 ,
L_234 , L_235 ,
& V_1 . V_241 , V_242 , TRUE ) ;
#ifndef F_149
V_156 = V_1 . V_243 ;
F_63 ( V_151 , L_236 , L_237 ,
L_238 , ( const char * * ) ( & V_1 . V_243 ) ) ;
F_5 ( V_156 ) ;
#endif
V_156 = V_1 . V_244 ;
F_65 ( V_151 , L_239 , L_240 ,
L_241 , ( const char * * ) ( & V_1 . V_244 ) ) ;
F_5 ( V_156 ) ;
V_49 = F_12 ( NULL , L_242 , L_243 ,
L_243 , & F_82 , TRUE ) ;
F_58 ( V_49 , L_244 ,
L_245 ,
L_246 ,
10 ,
& V_1 . V_86 ) ;
#ifdef F_83
F_58 ( V_49 , L_247 ,
L_248 ,
L_249 ,
10 ,
& V_1 . V_88 ) ;
#endif
F_60 ( V_49 , L_250 ,
L_251 ,
L_252
L_253 ,
& V_1 . V_245 ) ;
F_60 ( V_49 , L_254 ,
L_255 ,
L_256
L_257
L_258 ,
& V_1 . V_246 ) ;
F_58 ( V_49 , L_259 ,
L_260 ,
L_261
L_262 ,
10 , & V_1 . V_90 ) ;
F_58 ( V_49 , L_263 ,
L_264 ,
L_265
L_266
L_267 ,
10 , & V_1 . V_92 ) ;
F_61 ( V_49 , L_268 ,
L_269 ,
L_270
L_271 ,
& V_1 . V_247 , V_248 , FALSE ) ;
F_60 ( V_49 , L_272 ,
L_273 ,
L_274
L_275 ,
& V_1 . V_249 ) ;
F_60 ( V_49 , L_276 ,
L_277 ,
L_278
L_279
L_280 ,
& V_1 . V_250 ) ;
F_60 ( V_49 , L_281 ,
L_282 ,
L_283
L_284
L_285
L_286 ,
& V_1 . V_251 ) ;
F_60 ( V_49 , L_287 ,
L_288 ,
L_283
L_289
L_290
L_291 ,
& V_1 . V_252 ) ;
F_60 ( V_49 , L_292 ,
L_293 ,
L_294
L_295
L_296 ,
& V_1 . V_253 ) ;
V_42 = F_12 ( NULL , L_297 , L_298 ,
L_298 , NULL , TRUE ) ;
F_60 ( V_42 , L_299 ,
L_300 ,
L_301 ,
& V_1 . V_254 ) ;
F_60 ( V_42 , L_302 ,
L_303 ,
L_304 ,
& V_1 . V_255 ) ;
F_60 ( V_42 , L_305 ,
L_306 ,
L_307 ,
& V_1 . V_256 ) ;
F_12 ( NULL , L_308 , L_309 , L_309 , NULL , FALSE ) ;
F_12 ( NULL , L_310 , L_311 , L_311 , NULL , FALSE ) ;
F_12 ( NULL , L_312 , L_313 , L_313 , NULL , FALSE ) ;
}
T_18 *
F_119 ( const T_14 * V_257 )
{
enum { V_258 , V_259 , V_260 };
T_15 V_261 = V_258 , V_144 = 0 , V_262 = 0 ;
T_6 V_263 = FALSE ;
T_7 V_264 ;
T_14 * V_265 = NULL ;
T_18 * V_266 = NULL ;
V_265 = ( T_14 * ) F_150 ( sizeof( T_14 ) * V_267 ) ;
V_262 = 0 ;
for (; ; ) {
V_264 = V_257 [ V_144 ] ;
if ( V_264 == '\0' ) {
if ( V_261 == V_259 || V_263 ) {
F_5 ( V_265 ) ;
F_121 ( V_266 ) ;
return NULL ;
}
V_265 [ V_262 ] = '\0' ;
V_266 = F_52 ( V_266 , V_265 ) ;
break;
}
if ( V_264 == '"' && ! V_263 ) {
switch ( V_261 ) {
case V_258 :
V_261 = V_259 ;
break;
case V_259 :
V_261 = V_260 ;
break;
case V_260 :
V_261 = V_259 ;
break;
default:
break;
}
} else if ( V_264 == '\\' && ! V_263 ) {
V_263 = TRUE ;
if ( V_261 == V_258 )
V_261 = V_260 ;
} else if ( V_264 == ',' && V_261 != V_259 && ! V_263 ) {
V_265 [ V_262 ] = '\0' ;
V_266 = F_52 ( V_266 , V_265 ) ;
V_261 = V_258 ;
V_265 = ( T_14 * ) F_150 ( sizeof( T_14 ) * V_267 ) ;
V_262 = 0 ;
} else if ( ! F_151 ( V_264 ) || V_261 != V_258 ) {
if ( V_262 < V_267 ) {
V_265 [ V_262 ] = V_264 ;
V_262 ++ ;
}
V_263 = FALSE ;
}
V_144 ++ ;
}
return ( V_266 ) ;
}
char * F_128 ( T_18 * V_266 )
{
T_29 * V_268 = F_102 ( L_5 ) ;
T_18 * V_269 , * V_270 ;
T_14 * V_257 ;
T_14 * V_271 ;
T_4 V_272 = 0 ;
V_269 = V_270 = F_80 ( V_266 ) ;
while ( V_269 ) {
V_272 ++ ;
V_257 = ( T_14 * ) V_269 -> V_4 ;
if ( V_269 != V_270 )
F_152 ( V_268 , ',' ) ;
if ( V_272 % 2 ) {
F_104 ( V_268 , L_314 ) ;
} else
F_152 ( V_268 , ' ' ) ;
V_271 = F_153 ( V_257 , L_5 ) ;
F_154 ( V_268 , L_315 , V_271 ) ;
F_5 ( V_271 ) ;
V_269 = V_269 -> V_109 ;
}
return F_105 ( V_268 , FALSE ) ;
}
void
F_121 ( T_18 * V_266 )
{
F_7 ( V_266 , ( V_273 ) F_5 , NULL ) ;
F_8 ( V_266 ) ;
}
static T_15
F_155 ( const char * V_274 , const T_19 * V_275 ,
T_15 V_276 )
{
int V_144 ;
for ( V_144 = 0 ; V_275 [ V_144 ] . V_22 != NULL ; V_144 ++ ) {
if ( F_156 ( V_274 , V_275 [ V_144 ] . V_22 ) == 0 ) {
return V_275 [ V_144 ] . V_50 ;
}
}
for ( V_144 = 0 ; V_275 [ V_144 ] . V_22 != NULL ; V_144 ++ ) {
if ( F_156 ( V_274 , V_275 [ V_144 ] . V_32 ) == 0 ) {
return V_275 [ V_144 ] . V_50 ;
}
}
return V_276 ;
}
static T_6
F_122 ( T_28 * V_105 , const char * V_113 )
{
const T_14 * V_277 = F_103 ( V_114 ) ;
T_30 V_278 = strlen ( V_277 ) ;
T_14 * * V_279 ;
char * V_36 ;
int V_280 ;
T_14 * V_281 = NULL ;
long V_282 = 0 ;
T_6 V_283 = TRUE ;
if ( ( strlen ( V_113 ) > V_278 ) && ( V_113 [ V_278 ] == ':' ) &&
strncmp ( V_113 , V_277 , V_278 ) == 0 ) {
V_280 = V_114 ;
V_279 = F_157 ( & V_113 [ V_278 + 1 ] , L_316 , 3 ) ;
V_281 = F_35 ( V_279 [ 0 ] ) ;
if ( V_281 && V_279 [ 1 ] ) {
V_282 = strtol ( V_279 [ 1 ] , & V_36 , 10 ) ;
if ( V_36 == V_279 [ 1 ] || * V_36 != '\0' ) {
F_5 ( V_281 ) ;
F_158 ( V_279 ) ;
return FALSE ;
}
}
if ( V_281 && V_279 [ 1 ] && V_279 [ 2 ] ) {
V_283 = ( V_279 [ 2 ] [ 0 ] == 'U' ) ? FALSE : TRUE ;
}
F_158 ( V_279 ) ;
} else {
V_280 = F_159 ( V_113 ) ;
if ( V_280 == - 1 )
return FALSE ;
}
V_105 -> V_113 = V_280 ;
V_105 -> V_115 = V_281 ;
V_105 -> V_116 = ( int ) V_282 ;
V_105 -> V_117 = V_283 ;
return TRUE ;
}
static void
F_160 ( void )
{
if ( V_284 )
return;
F_161 () ;
F_27 () ;
F_28 () ;
F_162 ( TRUE ) ;
V_284 = TRUE ;
}
static void
F_27 ( void )
{
int V_144 ;
T_14 * V_143 ;
T_28 * V_105 ;
static const T_14 * V_280 [ V_285 * 2 ] = {
L_317 , L_318 , L_319 , L_320 ,
L_321 , L_322 , L_323 , L_324 ,
L_325 , L_326 , L_327 , L_328 ,
L_329 , L_330 } ;
V_1 . V_239 = V_286 ;
V_1 . V_241 = V_287 ;
if ( V_1 . V_244 ) F_5 ( V_1 . V_244 ) ;
V_1 . V_244 = F_35 ( L_331 ) ;
if ( V_1 . V_243 ) F_5 ( V_1 . V_243 ) ;
V_1 . V_243 = F_35 ( L_332 ) ;
V_1 . V_160 = FALSE ;
V_1 . V_161 = FALSE ;
V_1 . V_163 = 0 ;
V_1 . V_164 = 1 ;
V_1 . V_165 = 1 ;
V_1 . V_162 = FALSE ;
V_1 . V_201 = V_288 ;
V_1 . V_203 = V_289 ;
if ( V_1 . V_175 ) F_5 ( V_1 . V_175 ) ;
#ifdef F_149
V_1 . V_175 = F_35 ( L_333 ) ;
#else
V_1 . V_175 = F_35 ( L_334 ) ;
#endif
if ( V_1 . V_176 ) F_5 ( V_1 . V_176 ) ;
V_1 . V_176 = F_35 ( L_5 ) ;
V_1 . V_178 . V_290 = 65535 ;
V_1 . V_178 . V_291 = 65535 ;
V_1 . V_178 . V_292 = 65535 ;
V_1 . V_178 . V_293 = 65535 ;
V_1 . V_179 . V_290 = 0 ;
V_1 . V_179 . V_291 = 0 ;
V_1 . V_179 . V_292 = 8224 ;
V_1 . V_179 . V_293 = 10794 ;
V_1 . V_180 . V_290 = 32767 ;
V_1 . V_180 . V_291 = 32767 ;
V_1 . V_180 . V_292 = 32767 ;
V_1 . V_180 . V_293 = 32767 ;
V_1 . V_181 . V_290 = 65535 ;
V_1 . V_181 . V_291 = 65535 ;
V_1 . V_181 . V_292 = 65535 ;
V_1 . V_181 . V_293 = 65535 ;
if ( V_1 . V_186 ) F_5 ( V_1 . V_186 ) ;
V_1 . V_186 = F_35 ( L_335 ) ;
if ( V_1 . V_187 ) F_5 ( V_1 . V_187 ) ;
V_1 . V_187 = F_35 ( L_336 ) ;
V_1 . V_182 . V_290 = 0 ;
V_1 . V_182 . V_291 = 32767 ;
V_1 . V_182 . V_292 = 0 ;
V_1 . V_182 . V_293 = 0 ;
V_1 . V_183 . V_290 = 0 ;
V_1 . V_183 . V_291 = 64507 ;
V_1 . V_183 . V_292 = 60909 ;
V_1 . V_183 . V_293 = 60909 ;
V_1 . V_184 . V_290 = 0 ;
V_1 . V_184 . V_291 = 0 ;
V_1 . V_184 . V_292 = 0 ;
V_1 . V_184 . V_293 = 32767 ;
V_1 . V_185 . V_290 = 0 ;
V_1 . V_185 . V_291 = 60909 ;
V_1 . V_185 . V_292 = 60909 ;
V_1 . V_185 . V_293 = 64507 ;
V_1 . V_188 . V_290 = 0 ;
V_1 . V_188 . V_291 = 0xAFFF ;
V_1 . V_188 . V_292 = 0xFFFF ;
V_1 . V_188 . V_293 = 0xAFFF ;
V_1 . V_189 . V_290 = 0 ;
V_1 . V_189 . V_291 = 0xFFFF ;
V_1 . V_189 . V_292 = 0xAFFF ;
V_1 . V_189 . V_293 = 0xAFFF ;
V_1 . V_190 . V_290 = 0 ;
V_1 . V_190 . V_291 = 0xFFFF ;
V_1 . V_190 . V_292 = 0xFFFF ;
V_1 . V_190 . V_293 = 0xAFFF ;
V_1 . V_197 = TRUE ;
V_1 . V_198 = TRUE ;
V_1 . V_199 = TRUE ;
V_1 . V_200 = TRUE ;
V_1 . V_158 = V_294 ;
V_1 . V_191 = V_295 ;
V_1 . V_95 = 10 ;
V_1 . V_94 = 10 ;
if ( V_1 . V_192 ) F_5 ( V_1 . V_192 ) ;
V_1 . V_192 = F_35 ( F_163 () ) ;
V_1 . V_193 = 3 ;
V_1 . V_194 = TRUE ;
V_1 . V_195 = TRUE ;
V_1 . V_196 = FALSE ;
V_1 . V_205 = TRUE ;
V_1 . V_206 = V_296 ;
V_1 . V_207 = 60 * 60 * 24 ;
if ( V_1 . V_204 ) F_5 ( V_1 . V_204 ) ;
#ifdef F_164
V_1 . V_204 = F_35 ( F_164 L_337 ) ;
#else
V_1 . V_204 = F_35 ( L_5 ) ;
#endif
if ( V_1 . V_208 ) F_5 ( V_1 . V_208 ) ;
V_1 . V_208 = F_35 ( L_5 ) ;
if ( V_1 . V_209 ) F_5 ( V_1 . V_209 ) ;
V_1 . V_209 = F_35 ( L_338 ) ;
V_1 . V_210 = V_297 ;
V_1 . V_212 = FALSE ;
V_1 . V_213 = 0 ;
V_1 . V_96 = V_99 ;
V_1 . V_214 = V_298 ;
V_1 . V_216 = V_299 ;
V_1 . V_217 = V_300 ;
V_1 . V_219 = FALSE ;
V_1 . V_220 = V_301 ;
V_1 . V_221 = TRUE ;
V_1 . V_222 = TRUE ;
V_1 . V_218 = FALSE ;
if ( ! V_1 . V_173 ) {
for ( V_144 = 0 ; V_144 < V_285 ; V_144 ++ ) {
V_105 = F_49 ( T_28 , 1 ) ;
V_105 -> V_31 = F_35 ( V_280 [ V_144 * 2 ] ) ;
F_122 ( V_105 , V_280 [ ( V_144 * 2 ) + 1 ] ) ;
V_105 -> V_110 = TRUE ;
V_105 -> V_117 = TRUE ;
V_105 -> V_115 = NULL ;
V_105 -> V_116 = 0 ;
V_1 . V_173 = F_52 ( V_1 . V_173 , V_105 ) ;
}
V_1 . V_174 = V_285 ;
}
V_1 . V_232 = TRUE ;
#ifdef F_165
V_1 . V_234 = TRUE ;
#else
V_1 . V_234 = FALSE ;
#endif
V_1 . V_235 = TRUE ;
V_1 . V_236 = TRUE ;
V_1 . V_237 = FALSE ;
if ( ! V_1 . V_141 ) {
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ ) {
V_143 = F_35 ( V_146 [ V_144 ] ) ;
V_1 . V_141 = F_52 ( V_1 . V_141 , V_143 ) ;
}
}
V_1 . V_223 =
V_302 | V_303 | V_304 ;
V_1 . V_86 = V_87 ;
V_1 . V_88 = V_89 ;
V_1 . V_245 = TRUE ;
V_1 . V_246 = FALSE ;
V_1 . V_90 = V_305 ;
V_1 . V_92 = V_306 ;
V_1 . V_250 = TRUE ;
V_1 . V_252 = TRUE ;
V_1 . V_251 = TRUE ;
V_1 . V_247 = V_307 ;
V_1 . V_249 = TRUE ;
V_1 . V_253 = FALSE ;
V_1 . V_254 = FALSE ;
V_1 . V_255 = FALSE ;
}
static void
F_166 ( T_3 * V_6 )
{
if ( ! V_6 ) return;
switch ( V_6 -> type ) {
case V_10 :
* V_6 -> V_17 . V_66 = V_6 -> V_18 . V_66 ;
break;
case V_8 :
* V_6 -> V_17 . V_69 = V_6 -> V_18 . V_24 ;
break;
case V_9 :
* V_6 -> V_17 . V_72 = V_6 -> V_18 . V_73 ;
break;
case V_14 :
case V_15 :
case V_16 :
F_5 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_35 ( V_6 -> V_18 . string ) ;
break;
case V_19 :
F_5 ( * V_6 -> V_17 . V_20 ) ;
* V_6 -> V_17 . V_20 = F_69 ( V_6 -> V_18 . V_20 ) ;
break;
case V_11 :
case V_12 :
break;
case V_13 :
* V_6 -> V_17 . V_80 = V_6 -> V_18 . V_79 ;
break;
case V_21 :
V_6 -> V_25 . V_166 ( V_6 ) ;
break;
case V_7 :
break;
}
}
static void
F_167 ( T_1 V_4 , T_1 T_2 V_5 )
{
T_3 * V_6 = ( T_3 * ) V_4 ;
F_166 ( V_6 ) ;
}
static T_6
F_168 ( const void * T_9 V_5 , void * V_50 , void * V_4 V_5 )
{
T_31 V_61 ;
V_61 . V_27 = ( T_5 * ) V_50 ;
F_7 ( V_61 . V_27 -> V_1 , F_167 , & V_61 ) ;
return FALSE ;
}
void
F_169 ( void )
{
V_284 = FALSE ;
F_5 ( V_1 . V_308 ) ;
V_1 . V_308 = NULL ;
F_170 () ;
F_171 () ;
F_172 ( * V_309 ) ;
* V_309 = NULL ;
F_160 () ;
F_42 ( V_2 , F_168 , NULL ) ;
}
T_32 *
F_173 ( int * V_310 , int * V_311 ,
char * * V_312 , int * V_313 ,
int * V_314 , char * * V_315 )
{
int V_316 ;
char * V_317 ;
T_33 * V_318 ;
F_171 () ;
F_160 () ;
if ( V_319 == NULL ) {
V_319 = F_174 ( V_320 ) ;
if ( ( V_318 = F_175 ( V_319 , L_339 ) ) == NULL && V_321 == V_322 ) {
F_5 ( V_319 ) ;
V_319 = F_174 ( V_323 ) ;
V_318 = F_175 ( V_319 , L_339 ) ;
}
} else {
V_318 = F_175 ( V_319 , L_339 ) ;
}
* V_312 = NULL ;
if ( V_318 != NULL ) {
V_324 = 0 ;
V_325 = 0 ;
V_316 = F_176 ( V_319 , V_318 , V_326 , NULL ) ;
if ( V_316 != 0 ) {
* V_310 = 0 ;
* V_311 = V_316 ;
* V_312 = V_319 ;
}
fclose ( V_318 ) ;
} else {
if ( V_321 != V_322 ) {
* V_310 = V_321 ;
* V_311 = 0 ;
* V_312 = V_319 ;
}
}
V_317 = F_177 ( V_320 , TRUE ) ;
* V_315 = NULL ;
if ( ( V_318 = F_175 ( V_317 , L_339 ) ) != NULL ) {
V_324 = 0 ;
V_325 = 0 ;
V_316 = F_176 ( V_317 , V_318 , V_326 , NULL ) ;
if ( V_316 != 0 ) {
* V_313 = 0 ;
* V_314 = V_316 ;
* V_315 = V_317 ;
} else
F_5 ( V_317 ) ;
fclose ( V_318 ) ;
} else {
if ( V_321 != V_322 ) {
* V_313 = V_321 ;
* V_314 = 0 ;
* V_315 = V_317 ;
} else
F_5 ( V_317 ) ;
}
F_178 () ;
return & V_1 ;
}
int
F_176 ( const char * V_317 , T_33 * V_318 ,
T_34 V_327 , void * V_328 )
{
enum {
V_329 ,
V_330 ,
V_331 ,
V_332 ,
V_333
} V_261 = V_329 ;
int V_334 ;
T_29 * V_335 ;
T_29 * V_336 ;
T_6 V_337 = FALSE ;
T_15 V_338 = 1 , V_339 = 1 ;
T_14 V_340 [] = L_340 ;
T_14 V_341 [ 128 ] ;
V_335 = F_102 ( L_5 ) ;
V_336 = F_102 ( L_5 ) ;
if ( fscanf ( V_318 , L_341 , V_341 ) == 1 ) {
F_5 ( V_1 . V_308 ) ;
V_1 . V_308 = F_179 ( V_341 , strlen ( V_341 ) - 1 ) ;
}
rewind ( V_318 ) ;
while ( ( V_334 = getc ( V_318 ) ) != V_342 ) {
if ( V_334 == '\r' ) {
V_334 = getc ( V_318 ) ;
if ( V_334 == V_342 )
break;
if ( V_334 != '\n' ) {
ungetc ( V_334 , V_318 ) ;
V_334 = '\r' ;
}
}
if ( V_334 == '\n' ) {
V_261 = V_329 ;
V_338 ++ ;
continue;
}
switch ( V_261 ) {
case V_329 :
if ( F_180 ( V_334 ) ) {
if ( V_336 -> V_118 > 0 ) {
if ( V_337 ) {
if ( V_335 -> V_118 > 0 ) {
if ( V_335 -> V_257 [ V_335 -> V_118 - 1 ] == ',' ) {
V_335 -> V_257 [ V_335 -> V_118 - 1 ] = '\0' ;
F_181 ( L_342 , V_317 , V_339 , V_336 -> V_257 , V_340 ) ;
}
}
switch ( V_327 ( V_336 -> V_257 , V_335 -> V_257 , V_328 , FALSE ) ) {
case V_83 :
break;
case V_130 :
F_181 ( L_343 ,
V_336 -> V_257 , V_339 , V_317 , V_340 ) ;
break;
case V_84 :
if ( strcmp ( V_336 -> V_257 , L_344 ) != 0 )
F_181 ( L_345 ,
V_336 -> V_257 , V_339 , V_317 , V_340 ) ;
V_1 . V_343 = TRUE ;
break;
case V_344 :
if ( strcmp ( V_336 -> V_257 , L_344 ) != 0 )
F_181 ( L_346 ,
V_336 -> V_257 , V_339 , V_317 , V_340 ) ;
V_1 . V_343 = TRUE ;
break;
}
} else {
F_181 ( L_347 , V_339 , V_317 , V_340 ) ;
}
}
V_261 = V_330 ;
V_337 = FALSE ;
F_182 ( V_336 , 0 ) ;
F_152 ( V_336 , ( T_14 ) V_334 ) ;
V_339 = V_338 ;
} else if ( F_151 ( V_334 ) && V_336 -> V_118 > 0 && V_337 ) {
V_261 = V_331 ;
} else if ( V_334 == '#' ) {
V_261 = V_333 ;
} else {
F_181 ( L_348 , V_338 , V_317 , V_340 ) ;
}
break;
case V_330 :
if ( V_334 != ':' ) {
F_152 ( V_336 , ( T_14 ) V_334 ) ;
} else {
V_261 = V_331 ;
F_182 ( V_335 , 0 ) ;
V_337 = TRUE ;
}
break;
case V_331 :
if ( ! F_151 ( V_334 ) ) {
V_261 = V_332 ;
F_152 ( V_335 , ( T_14 ) V_334 ) ;
}
break;
case V_332 :
F_152 ( V_335 , ( T_14 ) V_334 ) ;
break;
case V_333 :
break;
}
}
if ( V_336 -> V_118 > 0 ) {
if ( V_337 ) {
switch ( V_327 ( V_336 -> V_257 , V_335 -> V_257 , V_328 , FALSE ) ) {
case V_83 :
break;
case V_130 :
F_181 ( L_349 ,
V_336 -> V_257 , V_339 , V_317 , V_340 ) ;
break;
case V_84 :
F_181 ( L_345 ,
V_336 -> V_257 , V_339 , V_317 , V_340 ) ;
V_1 . V_343 = TRUE ;
break;
case V_344 :
V_1 . V_343 = TRUE ;
break;
}
} else {
F_181 ( L_350 ,
V_339 , V_317 , V_340 ) ;
}
}
F_105 ( V_335 , TRUE ) ;
F_105 ( V_336 , TRUE ) ;
if ( ferror ( V_318 ) )
return V_321 ;
else
return 0 ;
}
static T_6
F_183 ( char * V_345 ) {
T_14 * V_36 , * V_346 ;
T_22 * V_77 ;
T_14 * V_316 = NULL ;
T_6 V_52 ;
V_346 = strchr ( V_345 , ':' ) ;
if ( V_346 == NULL )
return FALSE ;
V_36 = V_346 ;
* V_36 ++ = '\0' ;
while ( F_151 ( * V_36 ) )
V_36 ++ ;
if ( * V_36 == '\0' ) {
* V_346 = ':' ;
return FALSE ;
}
V_77 = F_184 ( V_345 ) ;
* V_346 = ':' ;
if ( V_77 == NULL ) {
return FALSE ;
}
V_52 = F_185 ( V_77 , V_36 , & V_316 ) ;
F_5 ( V_316 ) ;
return V_52 ;
}
T_26
F_186 ( char * V_347 )
{
T_14 * V_36 , * V_346 ;
T_26 V_52 ;
V_324 = - 1 ;
V_325 = - 1 ;
V_346 = strchr ( V_347 , ':' ) ;
if ( V_346 == NULL )
return V_130 ;
V_36 = V_346 ;
* V_36 ++ = '\0' ;
while ( F_151 ( * V_36 ) )
V_36 ++ ;
if ( * V_36 == '\0' ) {
* V_346 = ':' ;
return V_130 ;
}
if ( strcmp ( V_347 , L_351 ) ) {
V_52 = V_326 ( V_347 , V_36 , NULL , TRUE ) ;
} else {
V_52 = F_183 ( V_36 ) ? V_83 : V_130 ;
}
* V_346 = ':' ;
return V_52 ;
}
T_6
F_187 ( const char * V_22 )
{
T_14 * V_348 , * V_349 ;
T_30 V_118 ;
if ( V_1 . V_227 && V_22 ) {
V_349 = F_35 ( V_1 . V_227 ) ;
V_118 = strlen ( V_22 ) ;
for ( V_348 = strtok ( V_349 , L_21 ) ; V_348 ; V_348 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_348 ) == V_118 && strcmp ( V_22 , V_348 ) == 0 ) {
F_5 ( V_349 ) ;
return TRUE ;
}
}
F_5 ( V_349 ) ;
}
return FALSE ;
}
static T_6
F_98 ( const T_14 * V_111 , T_28 * V_105 )
{
T_14 * V_348 , * V_350 ;
T_28 V_351 ;
if ( V_111 ) {
V_350 = F_35 ( V_111 ) ;
for ( V_348 = strtok ( V_350 , L_21 ) ; V_348 ; V_348 = strtok ( NULL , L_21 ) ) {
V_348 = F_188 ( V_348 ) ;
if ( ! F_122 ( & V_351 , V_348 ) ) {
continue;
}
if ( V_105 -> V_113 != V_351 . V_113 ) {
F_5 ( V_351 . V_115 ) ;
V_351 . V_115 = NULL ;
continue;
}
if ( V_105 -> V_113 == V_114 ) {
if ( V_351 . V_115 && V_105 -> V_115 ) {
if ( strcmp ( V_105 -> V_115 ,
V_351 . V_115 ) != 0 ) {
F_5 ( V_351 . V_115 ) ;
V_351 . V_115 = NULL ;
continue;
}
if ( V_105 -> V_116 != V_351 . V_116 ) {
F_5 ( V_351 . V_115 ) ;
V_351 . V_115 = NULL ;
continue;
}
}
}
F_5 ( V_351 . V_115 ) ;
F_5 ( V_350 ) ;
return FALSE ;
}
F_5 ( V_350 ) ;
}
return TRUE ;
}
T_6
F_189 ( const char * V_22 )
{
T_14 * V_348 , * V_349 ;
T_30 V_118 ;
if ( V_1 . V_228 && V_22 ) {
V_349 = F_35 ( V_1 . V_228 ) ;
V_118 = strlen ( V_22 ) ;
for ( V_348 = strtok ( V_349 , L_21 ) ; V_348 ; V_348 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_348 ) == V_118 && strcmp ( V_22 , V_348 ) == 0 ) {
F_5 ( V_349 ) ;
return TRUE ;
}
}
F_5 ( V_349 ) ;
}
return FALSE ;
}
T_6
F_190 ( const T_14 * V_352 )
{
T_18 * V_353 ;
T_14 * V_149 ;
for ( V_353 = F_80 ( V_1 . V_141 ) ; V_353 ; V_353 = F_81 ( V_353 ) ) {
V_149 = ( T_14 * ) V_353 -> V_4 ;
if ( V_149 && ( F_156 ( V_149 , V_352 ) == 0 ) ) {
return TRUE ;
}
}
return FALSE ;
}
char
F_191 ( const char * string , T_35 * V_354 )
{
char V_37 ;
memset ( V_354 , 0 , sizeof( T_35 ) ) ;
while ( ( V_37 = * string ++ ) != '\0' ) {
switch ( V_37 ) {
case 'm' :
V_354 -> V_355 = TRUE ;
break;
case 'n' :
V_354 -> V_356 = TRUE ;
break;
case 'N' :
V_354 -> V_357 = TRUE ;
break;
case 't' :
V_354 -> V_358 = TRUE ;
break;
case 'C' :
V_354 -> V_359 = TRUE ;
break;
case 'd' :
V_354 -> V_360 = TRUE ;
break;
default:
return V_37 ;
}
}
return '\0' ;
}
static void
F_123 ( T_1 * V_361 )
{
struct {
T_15 V_362 ;
const T_14 * V_363 ;
} V_364 [] = {
{ V_365 , L_352 } ,
{ V_366 , L_353 } ,
{ V_367 , L_354 } ,
{ V_368 , L_355 } ,
{ V_369 , L_356 } ,
{ V_370 , L_357 } ,
{ V_371 , L_358 } ,
{ V_372 , L_359 } ,
{ V_373 , L_360 } ,
{ V_374 , L_361 } ,
{ V_375 , L_362 } ,
{ V_376 , L_363 } ,
{ V_377 , L_364 }
} ;
T_4 V_378 ;
const T_14 * V_379 ;
T_14 * * V_113 = ( T_14 * * ) V_361 ;
for ( V_378 = 0 ;
V_378 < F_192 ( V_364 ) ;
++ V_378 ) {
V_379 = F_103 ( V_364 [ V_378 ] . V_362 ) ;
if ( strcmp ( V_379 , * V_113 ) == 0 ) {
T_14 * V_380 = F_92 ( L_365 ,
V_364 [ V_378 ] . V_363 ) ;
F_5 ( * V_113 ) ;
* V_113 = V_380 ;
}
}
}
static T_6
F_193 ( T_14 * V_381 , const T_14 * V_50 )
{
struct V_382
{
const char * V_381 ;
const char * V_383 ;
T_6 V_384 ;
};
struct V_382 V_385 [] = {
{ L_366 , L_367 , 0 } ,
{ L_368 , L_369 , 1 } ,
{ L_368 , L_370 , 0 } ,
{ L_371 , L_372 , 0 } ,
{ L_373 , L_374 , 0 } ,
{ L_375 , L_376 , 0 } ,
{ L_377 , L_378 , 0 } ,
{ L_379 , L_380 , 0 } ,
{ L_381 , L_382 , 1 } ,
{ L_381 , L_383 , 0 } ,
{ L_384 , L_385 , 0 } ,
{ L_386 , L_387 , 0 } ,
{ L_388 , L_389 , 0 } ,
{ L_390 , L_391 , 0 } ,
{ L_392 , L_393 , 0 } ,
{ L_394 , L_395 , 0 } ,
{ L_396 , L_397 , 0 } ,
{ L_398 , L_399 , 0 } ,
{ L_400 , L_401 , 0 } ,
{ L_402 , L_403 , 0 } ,
{ L_404 , L_405 , 0 } ,
{ L_406 , L_407 , 0 } ,
{ L_408 , L_409 , 0 } ,
{ L_410 , L_411 , 0 } ,
{ L_412 , L_413 , 0 } ,
{ L_414 , L_415 , 0 } ,
{ L_416 , L_417 , 1 } ,
{ L_416 , L_418 , 0 } ,
{ L_419 , L_420 , 1 } ,
{ L_419 , L_421 , 0 } ,
{ L_422 , L_423 , 0 } ,
{ L_424 , L_425 , 0 } ,
{ L_426 , L_427 , 1 } ,
{ L_426 , L_428 , 1 } ,
{ L_426 , L_429 , 0 } ,
{ L_430 , L_431 , 0 } ,
{ L_432 , L_433 , 0 } ,
} ;
unsigned int V_144 ;
T_36 * V_386 ;
for ( V_144 = 0 ; V_144 < sizeof( V_385 ) / sizeof( struct V_382 ) ; V_144 ++ )
{
if ( strcmp ( V_381 , V_385 [ V_144 ] . V_381 ) == 0 )
{
V_386 = F_194 ( V_385 [ V_144 ] . V_383 ) ;
if ( V_386 != NULL ) {
V_386 -> V_387 = ( ( F_156 ( V_50 , L_434 ) == 0 ) ? TRUE : FALSE ) ;
}
if ( ! V_385 [ V_144 ] . V_384 )
return TRUE ;
}
}
return FALSE ;
}
static T_26
V_326 ( T_14 * V_381 , const T_14 * V_50 , void * V_328 V_5 ,
T_6 V_388 )
{
unsigned long int V_389 ;
T_4 V_101 ;
T_6 V_390 ;
T_15 V_391 ;
char * V_36 ;
T_14 * V_392 , * V_393 ;
static T_14 * V_394 = NULL ;
static T_6 V_395 = FALSE ;
T_14 * V_396 = NULL ;
T_5 * V_27 ;
T_3 * V_6 ;
if ( strcmp ( V_381 , V_397 ) == 0 ) {
V_394 = F_35 ( V_50 ) ;
} else if ( strcmp ( V_381 , V_398 ) == 0 ) {
V_395 = ( strcmp ( V_50 , L_435 ) == 0 ) ? TRUE : FALSE ;
} else if ( strcmp ( V_381 , V_399 ) == 0 ) {
V_396 = F_35 ( V_50 ) ;
F_195 ( V_394 , V_396 , V_395 ) ;
F_5 ( V_394 ) ;
F_5 ( V_396 ) ;
} else if ( strcmp ( V_381 , L_436 ) == 0 ) {
if ( F_156 ( V_50 , L_434 ) == 0 ) {
V_1 . V_210 = V_297 ;
} else {
V_1 . V_210 = V_400 ;
}
} else if ( strcmp ( V_381 , L_437 ) == 0 ||
strcmp ( V_381 , L_438 ) == 0 ) {
if ( F_156 ( V_50 , L_434 ) == 0 ) {
V_401 . V_355 = TRUE ;
V_401 . V_356 = TRUE ;
V_401 . V_358 = TRUE ;
V_401 . V_359 = TRUE ;
}
else if ( F_156 ( V_50 , L_439 ) == 0 ) {
F_196 () ;
}
else {
F_196 () ;
if ( F_191 ( V_50 , & V_401 ) != '\0' )
return V_130 ;
}
} else if ( F_193 ( V_381 , V_50 ) ) {
} else {
if ( ( strcmp ( V_381 , L_440 ) == 0 ) ||
( strcmp ( V_381 , L_441 ) == 0 ) ||
( strcmp ( V_381 , L_442 ) == 0 ) ) {
V_27 = V_238 ;
V_392 = V_381 ;
} else {
V_27 = NULL ;
V_393 = V_381 ;
while ( ! V_27 ) {
V_392 = strchr ( V_393 , '.' ) ;
if ( V_392 == NULL ) {
return V_84 ;
}
* V_392 = '\0' ;
V_27 = F_20 ( V_381 ) ;
if ( V_27 == NULL ) {
if ( strcmp ( V_381 , L_443 ) == 0 )
V_27 = V_107 ;
else if ( strcmp ( V_381 , L_444 ) == 0 )
V_27 = F_20 ( L_445 ) ;
else if ( strcmp ( V_381 , L_446 ) == 0 )
V_27 = F_20 ( L_447 ) ;
else if ( strcmp ( V_381 , L_448 ) == 0 ||
strcmp ( V_381 , L_449 ) == 0 )
V_27 = F_20 ( L_450 ) ;
else if ( strcmp ( V_381 , L_451 ) == 0 )
V_27 = F_20 ( L_452 ) ;
else if ( strcmp ( V_381 , L_453 ) == 0 )
V_27 = F_20 ( L_454 ) ;
else if ( strcmp ( V_381 , L_455 ) == 0 )
V_27 = F_20 ( L_456 ) ;
else if ( strcmp ( V_381 , L_457 ) == 0 )
V_27 = F_20 ( L_458 ) ;
else if ( strcmp ( V_381 , L_459 ) == 0 )
V_27 = F_20 ( L_460 ) ;
else if ( strcmp ( V_381 , L_461 ) == 0 )
V_27 = F_20 ( L_462 ) ;
else if ( strcmp ( V_381 , L_463 ) == 0 ||
strcmp ( V_381 , L_464 ) == 0 ) {
return V_344 ;
}
if ( V_27 ) {
F_181 ( L_465
L_466 ,
V_381 , V_392 + 1 , V_27 -> V_30 -> V_22 , V_381 , V_392 + 1 ) ;
V_1 . V_343 = TRUE ;
}
}
* V_392 = '.' ;
V_392 ++ ;
V_393 = V_392 ;
}
}
V_6 = F_51 ( V_27 , V_392 ) ;
if ( V_6 == NULL ) {
V_1 . V_343 = TRUE ;
if ( ( strcmp ( V_381 , V_132 ) == 0 ) ||
( strcmp ( V_381 , V_108 ) == 0 ) ) {
V_6 = F_51 ( V_27 , V_381 ) ;
}
else if ( strcmp ( V_27 -> V_22 , L_467 ) == 0 ) {
if ( strcmp ( V_392 , L_468 ) == 0 )
V_6 = F_51 ( V_27 , L_469 ) ;
else if ( strcmp ( V_392 , L_470 ) == 0 )
V_6 = F_51 ( V_27 , L_471 ) ;
else if ( strcmp ( V_392 , L_472 ) == 0 ) {
V_324 ++ ;
if ( V_324 == 1 ) {
V_6 = F_51 ( V_27 , L_473 ) ;
} else if ( V_324 == 2 ) {
V_6 = F_51 ( V_27 , L_474 ) ;
}
} else if ( strcmp ( V_392 , L_475 ) == 0 ) {
V_325 ++ ;
if ( V_325 == 1 ) {
V_6 = F_51 ( V_27 , L_476 ) ;
} else if ( V_325 == 2 ) {
V_6 = F_51 ( V_27 , L_477 ) ;
}
}
} else if ( strcmp ( V_27 -> V_22 , L_478 ) == 0 ) {
if ( strcmp ( V_392 , L_479 ) == 0 )
V_6 = F_51 ( V_27 , L_480 ) ;
else if ( strcmp ( V_392 , L_481 ) == 0 )
V_6 = F_51 ( V_27 , L_482 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_483 ) == 0 ) {
if ( strcmp ( V_392 , L_484 ) == 0 )
V_6 = F_51 ( V_27 , L_485 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_445 ) == 0 ) {
if ( strcmp ( V_392 , L_486 ) == 0 )
V_6 = F_51 ( V_27 , L_485 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_487 ) == 0 ) {
if ( strcmp ( V_392 , L_488 ) == 0 )
V_6 = F_51 ( V_27 , L_489 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_490 ) == 0 ) {
if ( strcmp ( V_392 , L_491 ) == 0 )
V_6 = F_51 ( V_27 , L_489 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_492 ) == 0 ) {
if ( strcmp ( V_392 , L_493 ) == 0 )
V_6 = F_51 ( V_27 , L_494 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_495 ) == 0 ) {
if ( strcmp ( V_392 , L_496 ) == 0 )
V_6 = F_51 ( V_27 , L_497 ) ;
else if ( strcmp ( V_392 , L_498 ) == 0 )
V_6 = F_51 ( V_27 , L_499 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_500 ) == 0 ) {
if ( strcmp ( V_392 , L_501 ) == 0 )
V_6 = F_51 ( V_27 , L_485 ) ;
else if ( strcmp ( V_392 , L_502 ) == 0 )
V_6 = F_51 ( V_27 , L_503 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_450 ) == 0 ) {
if ( strcmp ( V_392 , L_504 ) == 0 )
V_6 = F_51 ( V_27 , L_505 ) ;
else if ( strcmp ( V_392 , L_506 ) == 0 )
V_6 = F_51 ( V_27 , L_507 ) ;
else if ( strcmp ( V_392 , L_508 ) == 0 )
V_6 = F_51 ( V_27 , L_509 ) ;
else if ( strcmp ( V_392 , L_510 ) == 0 )
V_6 = F_51 ( V_27 , L_511 ) ;
else if ( strcmp ( V_392 , L_512 ) == 0 )
V_6 = F_51 ( V_27 , L_513 ) ;
else if ( strcmp ( V_392 , L_514 ) == 0 )
V_6 = F_51 ( V_27 , L_515 ) ;
else if ( strcmp ( V_392 , L_516 ) == 0 )
V_6 = F_51 ( V_27 , L_517 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_518 ) == 0 ) {
if ( strcmp ( V_392 , L_519 ) == 0 )
V_6 = F_51 ( V_27 , L_520 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_521 ) == 0 ) {
if ( strcmp ( V_392 , L_522 ) == 0 )
V_6 = F_51 ( V_27 , L_503 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_523 ) == 0 ) {
if ( strcmp ( V_392 , L_524 ) == 0 )
V_6 = F_51 ( V_27 , L_525 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_526 ) == 0 ) {
if ( strcmp ( V_392 , L_527 ) == 0 )
V_6 = F_51 ( V_27 , L_528 ) ;
else if ( strcmp ( V_392 , L_529 ) == 0 )
V_6 = F_51 ( V_27 , L_530 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_531 ) == 0 ) {
if ( strcmp ( V_392 , L_532 ) == 0 )
V_6 = F_51 ( V_27 , L_533 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_534 ) == 0 ) {
if ( strcmp ( V_392 , L_535 ) == 0 )
V_6 = F_51 ( V_27 , L_536 ) ;
else if ( strcmp ( V_392 , L_537 ) == 0 )
V_6 = F_51 ( V_27 , L_538 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_539 ) == 0 ) {
if ( strcmp ( V_392 , L_540 ) == 0 )
V_6 = F_51 ( V_27 , L_541 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_542 ) == 0 ) {
if ( strcmp ( V_392 , L_543 ) == 0 )
V_6 = F_51 ( V_27 , L_520 ) ;
else if ( strcmp ( V_392 , L_544 ) == 0 )
V_6 = F_51 ( V_27 , L_545 ) ;
else if ( strcmp ( V_392 , L_546 ) == 0 )
V_6 = F_51 ( V_27 , L_547 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_548 ) == 0 ) {
if ( strcmp ( V_392 , L_549 ) == 0 )
V_6 = F_51 ( V_27 , L_520 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_550 ) == 0 ) {
if ( strcmp ( V_392 , L_551 ) == 0 )
V_6 = F_51 ( V_27 , L_552 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_553 ) == 0 ) {
if ( strcmp ( V_392 , L_554 ) == 0 )
V_6 = F_51 ( V_27 , L_555 ) ;
else if ( strcmp ( V_392 , L_556 ) == 0 )
V_6 = F_51 ( V_27 , L_557 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_558 ) == 0 ) {
T_5 * V_45 = F_20 ( L_452 ) ;
if ( V_45 ) {
if ( strcmp ( V_392 , L_559 ) == 0 )
V_6 = F_51 ( V_45 , L_559 ) ;
else if ( strcmp ( V_392 , L_560 ) == 0 )
V_6 = F_51 ( V_45 , L_560 ) ;
}
} else if ( strcmp ( V_27 -> V_22 , L_561 ) == 0 ) {
if ( strcmp ( V_392 , L_562 ) == 0 )
V_6 = F_51 ( V_27 , L_563 ) ;
else if ( strcmp ( V_392 , L_489 ) == 0 )
V_6 = F_51 ( V_27 , L_564 ) ;
else if ( strcmp ( V_392 , L_565 ) == 0 )
V_6 = F_51 ( V_27 , L_566 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_567 ) == 0 ) {
if ( strcmp ( V_392 , L_568 ) == 0 )
V_6 = F_51 ( V_27 , L_569 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_570 ) == 0 ) {
if ( strcmp ( V_392 , L_571 ) == 0 ) {
V_6 = F_51 ( V_27 , L_572 ) ;
if ( strcmp ( V_50 , L_572 ) == 0 || strcmp ( V_50 , L_573 ) == 0 )
V_50 = L_435 ;
else if ( strcmp ( V_50 , L_574 ) == 0 || strcmp ( V_50 , L_575 ) == 0 )
V_50 = L_576 ;
else if ( strcmp ( V_50 , L_577 ) == 0 || strcmp ( V_50 , L_578 ) == 0 )
V_50 = L_435 ;
} else if ( strcmp ( V_392 , L_579 ) == 0 ) {
V_6 = F_51 ( V_27 , L_580 ) ;
if ( strcmp ( V_50 , L_581 ) == 0 || strcmp ( V_50 , L_582 ) == 0 )
V_50 = L_583 ;
else if ( strcmp ( V_50 , L_584 ) == 0 || strcmp ( V_50 , L_585 ) == 0 )
V_50 = L_584 ;
else if ( strcmp ( V_50 , L_577 ) == 0 || strcmp ( V_50 , L_578 ) == 0 )
V_50 = L_583 ;
} else if ( strcmp ( V_392 , L_586 ) == 0 ) {
V_6 = F_51 ( V_27 , L_587 ) ;
if ( strcmp ( V_50 , L_588 ) == 0 || strcmp ( V_50 , L_589 ) == 0 )
V_50 = L_588 ;
else if ( strcmp ( V_50 , L_534 ) == 0 || strcmp ( V_50 , L_590 ) == 0 )
V_50 = L_534 ;
else if ( strcmp ( V_50 , L_591 ) == 0 || strcmp ( V_50 , L_592 ) == 0 )
V_50 = L_593 ;
else if ( strcmp ( V_50 , L_594 ) == 0 || strcmp ( V_50 , L_595 ) == 0 )
V_50 = L_594 ;
else if ( strcmp ( V_50 , L_577 ) == 0 || strcmp ( V_50 , L_578 ) == 0 )
V_50 = L_583 ;
}
} else if ( strcmp ( V_27 -> V_22 , L_574 ) == 0 ) {
if ( strcmp ( V_392 , L_596 ) == 0 ) {
T_5 * V_45 = F_20 ( L_597 ) ;
if ( V_45 ) {
V_6 = F_51 ( V_45 , L_596 ) ;
V_27 = V_45 ;
}
}
} else if ( strcmp ( V_27 -> V_22 , L_308 ) == 0 ) {
if ( strcmp ( V_392 , L_244 ) == 0 ||
strcmp ( V_392 , L_247 ) == 0 )
V_6 = F_51 ( V_49 , V_392 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_310 ) == 0 ) {
if ( strcmp ( V_392 , L_299 ) == 0 )
V_6 = F_51 ( V_42 , V_392 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_312 ) == 0 ) {
if ( ( strcmp ( V_392 , L_598 ) == 0 ) ||
( strcmp ( V_392 , L_599 ) == 0 ) ||
( strcmp ( V_392 , L_600 ) == 0 ) ||
( strcmp ( V_392 , L_601 ) == 0 ) )
V_6 = F_51 ( V_177 , V_381 ) ;
} else if ( strcmp ( V_27 -> V_22 , L_226 ) == 0 ) {
if ( strcmp ( V_381 , L_440 ) == 0 ) {
V_6 = F_51 ( V_238 , V_381 ) ;
} else if ( strcmp ( V_381 , L_441 ) == 0 ) {
V_6 = F_51 ( V_238 , L_602 ) ;
} else if ( strcmp ( V_381 , L_442 ) == 0 ) {
V_6 = F_51 ( V_238 , L_603 ) ;
}
}
}
if ( V_6 == NULL )
return V_84 ;
switch ( V_6 -> type ) {
case V_10 :
V_101 = ( T_4 ) strtoul ( V_50 , & V_36 , V_6 -> V_67 . V_64 ) ;
if ( V_36 == V_50 || * V_36 != '\0' )
return V_130 ;
if ( * V_6 -> V_17 . V_66 != V_101 ) {
V_27 -> V_38 = TRUE ;
* V_6 -> V_17 . V_66 = V_101 ;
}
break;
case V_8 :
if ( F_156 ( V_50 , L_434 ) == 0 )
V_390 = TRUE ;
else
V_390 = FALSE ;
if ( * V_6 -> V_17 . V_69 != V_390 ) {
V_27 -> V_38 = TRUE ;
* V_6 -> V_17 . V_69 = V_390 ;
}
break;
case V_9 :
V_391 = F_155 ( V_50 , V_6 -> V_67 . V_74 . V_70 ,
* V_6 -> V_17 . V_72 ) ;
if ( * V_6 -> V_17 . V_72 != V_391 ) {
V_27 -> V_38 = TRUE ;
* V_6 -> V_17 . V_72 = V_391 ;
}
break;
case V_14 :
case V_15 :
case V_16 :
if ( strcmp ( * V_6 -> V_17 . string , V_50 ) != 0 ) {
V_27 -> V_38 = TRUE ;
F_5 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_35 ( V_50 ) ;
}
break;
case V_19 :
{
T_20 * V_402 ;
if ( F_197 ( & V_402 , V_50 , V_6 -> V_67 . V_76 ,
V_388 ) != V_403 ) {
return V_130 ;
}
if ( ! F_198 ( * V_6 -> V_17 . V_20 , V_402 ) ) {
V_27 -> V_38 = TRUE ;
F_5 ( * V_6 -> V_17 . V_20 ) ;
* V_6 -> V_17 . V_20 = V_402 ;
} else {
F_5 ( V_402 ) ;
}
break;
}
case V_13 :
{
V_389 = strtoul ( V_50 , NULL , 16 ) ;
V_6 -> V_17 . V_80 -> V_290 = 0 ;
if ( ( V_6 -> V_17 . V_80 -> V_291 != F_199 ( V_389 ) ) ||
( V_6 -> V_17 . V_80 -> V_292 != F_200 ( V_389 ) ) ||
( V_6 -> V_17 . V_80 -> V_293 != F_201 ( V_389 ) ) ) {
V_27 -> V_38 = TRUE ;
V_6 -> V_17 . V_80 -> V_291 = F_199 ( V_389 ) ;
V_6 -> V_17 . V_80 -> V_292 = F_200 ( V_389 ) ;
V_6 -> V_17 . V_80 -> V_293 = F_201 ( V_389 ) ;
}
break;
}
case V_21 :
return V_6 -> V_25 . V_167 ( V_6 , V_50 , & V_27 -> V_38 ) ;
case V_11 :
case V_12 :
{
break;
}
case V_7 :
return V_344 ;
}
}
return V_83 ;
}
const char *
F_202 ( T_3 * V_6 )
{
const char * V_404 = L_604 ;
if ( ! V_6 ) {
return V_404 ;
}
switch ( V_6 -> type ) {
case V_10 :
switch ( V_6 -> V_67 . V_64 ) {
case 10 :
V_404 = L_605 ;
break;
case 8 :
V_404 = L_606 ;
break;
case 16 :
V_404 = L_607 ;
break;
}
break;
case V_8 :
V_404 = L_608 ;
break;
case V_9 :
V_404 = L_609 ;
break;
case V_14 :
V_404 = L_610 ;
break;
case V_15 :
V_404 = L_611 ;
break;
case V_16 :
V_404 = L_612 ;
break;
case V_19 :
V_404 = L_613 ;
break;
case V_13 :
V_404 = L_614 ;
break;
case V_21 :
if ( V_6 -> V_25 . V_168 )
return V_6 -> V_25 . V_168 () ;
V_404 = L_615 ;
break;
case V_7 :
V_404 = L_616 ;
break;
case V_11 :
V_404 = L_617 ;
break;
case V_12 :
V_404 = L_618 ;
break;
}
return V_404 ;
}
char *
F_203 ( T_3 * V_6 )
{
const char * V_405 = L_619 ;
if ( ! V_6 ) {
return F_92 ( L_620 , V_405 ) ;
}
switch ( V_6 -> type ) {
case V_10 :
switch ( V_6 -> V_67 . V_64 ) {
case 10 :
V_405 = L_621 ;
break;
case 8 :
V_405 = L_622 ;
break;
case 16 :
V_405 = L_623 ;
break;
}
break;
case V_8 :
V_405 = L_624 ;
break;
case V_9 :
{
const T_19 * V_406 = V_6 -> V_67 . V_74 . V_70 ;
T_29 * V_407 = F_102 ( L_625 ) ;
while ( V_406 -> V_22 != NULL ) {
F_104 ( V_407 , V_406 -> V_32 ) ;
V_406 ++ ;
if ( V_406 -> V_22 != NULL )
F_104 ( V_407 , L_626 ) ;
}
F_104 ( V_407 , L_627 ) ;
return F_105 ( V_407 , FALSE ) ;
break;
}
case V_14 :
V_405 = L_628 ;
break;
case V_15 :
V_405 = L_629 ;
break;
case V_16 :
V_405 = L_630 ;
break;
case V_19 :
{
V_405 = L_631 ;
break;
}
case V_13 :
{
V_405 = L_632 ;
break;
}
case V_21 :
if ( V_6 -> V_25 . V_169 )
return V_6 -> V_25 . V_169 () ;
V_405 = L_633 ;
break;
case V_7 :
V_405 = L_634 ;
break;
case V_11 :
V_405 = L_635 ;
break;
case V_12 :
V_405 = L_636 ;
break;
default:
break;
}
return F_35 ( V_405 ) ;
}
static T_6
F_204 ( T_3 * V_6 ) {
if ( ! V_6 ) return FALSE ;
switch ( V_6 -> type ) {
case V_10 :
if ( V_6 -> V_18 . V_66 == * V_6 -> V_17 . V_66 )
return TRUE ;
break;
case V_8 :
if ( V_6 -> V_18 . V_24 == * V_6 -> V_17 . V_69 )
return TRUE ;
break;
case V_9 :
if ( V_6 -> V_18 . V_73 == * V_6 -> V_17 . V_72 )
return TRUE ;
break;
case V_14 :
case V_15 :
case V_16 :
if ( ! ( F_107 ( V_6 -> V_18 . string , * V_6 -> V_17 . string ) ) )
return TRUE ;
break;
case V_19 :
{
if ( ( F_198 ( V_6 -> V_18 . V_20 , * V_6 -> V_17 . V_20 ) ) )
return TRUE ;
break;
}
case V_13 :
{
if ( ( V_6 -> V_18 . V_79 . V_291 == V_6 -> V_17 . V_80 -> V_291 ) &&
( V_6 -> V_18 . V_79 . V_292 == V_6 -> V_17 . V_80 -> V_292 ) &&
( V_6 -> V_18 . V_79 . V_293 == V_6 -> V_17 . V_80 -> V_293 ) )
return TRUE ;
break;
}
case V_21 :
return V_6 -> V_25 . V_170 ( V_6 ) ;
case V_7 :
case V_11 :
case V_12 :
return FALSE ;
break;
}
return FALSE ;
}
char *
F_205 ( T_3 * V_6 , T_37 V_408 ) {
const char * V_409 = L_604 ;
void * V_410 ;
T_23 * V_411 ;
T_14 * V_412 , * V_413 ;
if ( ! V_6 ) {
return F_35 ( V_409 ) ;
}
switch ( V_408 ) {
case V_414 :
V_410 = & V_6 -> V_18 ;
V_411 = & V_6 -> V_18 . V_79 ;
break;
case V_415 :
V_410 = & V_6 -> V_23 ;
V_411 = & V_6 -> V_23 . V_79 ;
break;
case V_416 :
V_410 = V_6 -> V_17 . V_66 ;
V_411 = V_6 -> V_17 . V_80 ;
break;
default:
return F_35 ( V_409 ) ;
}
switch ( V_6 -> type ) {
case V_10 :
{
T_4 V_417 = * ( T_4 * ) V_410 ;
switch ( V_6 -> V_67 . V_64 ) {
case 10 :
return F_92 ( L_17 , V_417 ) ;
case 8 :
return F_92 ( L_637 , V_417 ) ;
case 16 :
return F_92 ( L_638 , V_417 ) ;
}
break;
}
case V_8 :
return F_92 ( L_322 , ( * ( T_6 * ) V_410 ) ? L_435 : L_576 ) ;
case V_9 :
{
T_15 V_418 = * ( T_15 * ) V_410 ;
const T_19 * V_406 = V_6 -> V_67 . V_74 . V_70 ;
while ( V_406 -> V_22 != NULL ) {
if ( V_406 -> V_50 == V_418 )
return F_35 ( V_406 -> V_32 ) ;
V_406 ++ ;
}
break;
}
case V_14 :
case V_15 :
case V_16 :
return F_35 ( * ( const char * * ) V_410 ) ;
case V_19 :
V_412 = F_206 ( NULL , * ( T_20 * * ) V_410 ) ;
V_413 = F_35 ( V_412 ) ;
F_17 ( NULL , V_412 ) ;
return V_413 ;
case V_13 :
return F_92 ( L_639 ,
( V_411 -> V_291 * 255 / 65535 ) ,
( V_411 -> V_292 * 255 / 65535 ) ,
( V_411 -> V_293 * 255 / 65535 ) ) ;
case V_21 :
if ( V_6 -> V_25 . V_171 )
return V_6 -> V_25 . V_171 ( V_6 , V_408 == V_414 ? TRUE : FALSE ) ;
V_409 = L_640 ;
break;
case V_7 :
V_409 = L_641 ;
break;
case V_11 :
V_409 = L_635 ;
break;
case V_12 :
{
T_22 * V_77 = V_6 -> V_17 . V_77 ;
if ( V_77 && V_77 -> V_419 )
return F_92 ( L_642 , V_77 -> V_419 ) ;
else
V_409 = L_643 ;
break;
}
default:
break;
}
return F_35 ( V_409 ) ;
}
static void
F_207 ( T_1 V_4 , T_1 T_2 )
{
T_3 * V_6 = ( T_3 * ) V_4 ;
T_38 * V_61 = ( T_38 * ) T_2 ;
T_14 * * V_420 ;
int V_144 ;
switch ( V_6 -> type ) {
case V_7 :
return;
case V_11 :
case V_12 :
return;
default:
break;
}
if ( V_6 -> type != V_21 || V_6 -> V_25 . V_168 () != NULL ) {
const char * V_421 = ( V_61 -> V_27 -> V_22 != NULL ) ? V_61 -> V_27 -> V_22 : V_61 -> V_27 -> V_30 -> V_22 ;
char * V_405 , * V_409 ;
const char * V_422 = F_204 ( V_6 ) ? L_644 : L_5 ;
if ( V_6 -> type == V_21 ) fprintf ( V_61 -> V_318 , L_645 , V_6 -> V_25 . V_168 () ) ;
fprintf ( V_61 -> V_318 , L_646 ) ;
if ( V_6 -> V_32 &&
( F_208 ( V_6 -> V_32 , L_5 , 2 ) != 0 ) ) {
if ( V_6 -> type != V_21 ) {
V_420 = F_157 ( V_6 -> V_32 , L_646 , 0 ) ;
for ( V_144 = 0 ; V_420 [ V_144 ] != NULL ; ++ V_144 ) {
fprintf ( V_61 -> V_318 , L_647 , V_420 [ V_144 ] ) ;
}
F_158 ( V_420 ) ;
}
} else {
fprintf ( V_61 -> V_318 , L_648 ) ;
}
V_405 = F_203 ( V_6 ) ;
V_420 = F_157 ( V_405 , L_646 , 0 ) ;
for ( V_144 = 0 ; V_420 [ V_144 ] != NULL ; ++ V_144 ) {
fprintf ( V_61 -> V_318 , L_647 , V_420 [ V_144 ] ) ;
}
F_158 ( V_420 ) ;
F_5 ( V_405 ) ;
V_409 = F_205 ( V_6 , V_416 ) ;
fprintf ( V_61 -> V_318 , L_649 , V_422 , V_421 , V_6 -> V_22 ) ;
V_420 = F_157 ( V_409 , L_646 , 0 ) ;
for ( V_144 = 0 ; V_420 [ V_144 ] != NULL ; ++ V_144 ) {
fprintf ( V_61 -> V_318 , L_650 , V_144 == 0 ? L_5 : V_422 , V_420 [ V_144 ] ) ;
}
if ( V_144 == 0 ) fprintf ( V_61 -> V_318 , L_646 ) ;
F_158 ( V_420 ) ;
F_5 ( V_409 ) ;
}
}
static T_4
F_209 ( T_5 * V_27 , T_1 T_2 )
{
T_39 * V_423 = ( T_39 * ) T_2 ;
T_38 V_61 ;
if ( ( V_27 == V_157 ) && ( V_423 -> V_424 != TRUE ) )
return 0 ;
if ( ( ( V_27 -> V_30 == NULL ) || ( V_27 -> V_30 == V_157 ) ) &&
( ( F_43 ( V_27 ) ) ||
( V_27 -> V_28 > 0 ) ||
( V_27 -> V_22 == NULL ) ) ) {
if ( ( V_27 -> V_22 == NULL ) && ( V_27 -> V_30 != NULL ) ) {
fprintf ( V_423 -> V_318 , L_651 , V_27 -> V_30 -> V_31 , V_27 -> V_31 ) ;
} else {
fprintf ( V_423 -> V_318 , L_652 , V_27 -> V_31 ) ;
}
}
V_61 . V_27 = V_27 ;
V_61 . V_318 = V_423 -> V_318 ;
F_7 ( V_61 . V_27 -> V_1 , F_207 , & V_61 ) ;
if ( F_43 ( V_27 ) )
return F_9 ( V_27 , F_209 , T_2 ) ;
return 0 ;
}
int
F_210 ( char * * V_315 )
{
char * V_317 ;
T_33 * V_318 ;
T_39 V_425 ;
F_160 () ;
if ( V_315 != NULL ) {
V_317 = F_177 ( V_320 , TRUE ) ;
if ( ( V_318 = F_175 ( V_317 , L_653 ) ) == NULL ) {
* V_315 = V_317 ;
return V_321 ;
}
} else {
V_318 = stdout ;
}
fputs ( L_654 V_426 L_655
L_656
L_657
L_658
L_659
L_660 , V_318 ) ;
V_425 . V_318 = V_318 ;
V_425 . V_424 = TRUE ;
F_209 ( V_157 , & V_425 ) ;
{
struct V_427 * V_428 = * (struct V_427 * * ) V_1 . V_429 ;
if ( V_428 != NULL )
fprintf ( V_318 , L_661 ) ;
while ( V_428 != NULL ) {
if ( V_428 -> V_430 == FALSE ) {
fprintf ( V_318 , L_662 , V_397 , V_428 -> V_431 ) ;
fprintf ( V_318 , L_662 , V_398 ,
V_428 -> V_387 == TRUE ? L_435 : L_576 ) ;
fprintf ( V_318 , L_662 , V_399 , V_428 -> V_432 ) ;
}
V_428 = V_428 -> V_109 ;
}
}
V_425 . V_424 = FALSE ;
F_9 ( NULL , F_209 , & V_425 ) ;
fclose ( V_318 ) ;
return 0 ;
}
static void
F_116 ( T_18 * V_82 )
{
T_28 * V_105 ;
T_18 * V_433 = V_82 ;
while ( V_82 != NULL ) {
V_105 = ( T_28 * ) V_82 -> V_4 ;
F_5 ( V_105 -> V_31 ) ;
F_5 ( V_105 -> V_115 ) ;
F_5 ( V_105 ) ;
V_82 = F_81 ( V_82 ) ;
}
F_8 ( V_433 ) ;
}
