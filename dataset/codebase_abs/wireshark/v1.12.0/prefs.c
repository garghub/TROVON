void
F_1 ( void )
{
V_1 = F_2 ( F_3 () ) ;
V_2 = F_2 ( F_3 () ) ;
}
static void
F_4 ( T_1 V_3 , T_1 T_2 V_4 )
{
T_3 * V_5 = ( T_3 * ) V_3 ;
switch ( V_5 -> type ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
break;
case V_13 :
case V_14 :
case V_15 :
F_5 ( ( char * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = NULL ;
F_5 ( V_5 -> V_17 . string ) ;
V_5 -> V_17 . string = NULL ;
break;
case V_18 :
F_5 ( * V_5 -> V_16 . V_19 ) ;
* V_5 -> V_16 . V_19 = NULL ;
F_5 ( V_5 -> V_17 . V_19 ) ;
V_5 -> V_17 . V_19 = NULL ;
break;
case V_20 :
if ( strcmp ( V_5 -> V_21 , L_1 ) == 0 )
V_5 -> V_22 . V_23 = TRUE ;
V_5 -> V_24 . V_25 ( V_5 ) ;
break;
}
F_5 ( V_5 ) ;
}
static T_4
F_6 ( T_5 * V_26 , T_1 V_3 V_4 )
{
if ( V_26 -> V_27 ) {
F_7 ( V_26 -> V_27 , F_4 , NULL ) ;
F_8 ( V_26 -> V_27 ) ;
}
V_26 -> V_27 = NULL ;
V_26 -> V_28 = 0 ;
if ( V_26 -> V_29 ) {
F_9 ( V_26 , F_6 , NULL ) ;
}
return 0 ;
}
void
F_10 ( void )
{
F_11 ( F_6 , NULL ) ;
}
T_5 *
F_12 ( T_5 * V_30 , const char * V_21 , const char * V_31 ,
const char * V_32 , void (* F_13)( void ) ,
const T_6 V_33 )
{
return F_14 ( V_30 , V_21 , V_31 , V_32 ,
FALSE , F_13 , V_33 ) ;
}
T_5 *
F_15 ( T_5 * V_30 , const char * V_31 , const char * V_32 ,
void (* F_13)( void ) )
{
return F_14 ( V_30 , NULL , V_31 , V_32 ,
TRUE , F_13 ,
V_30 ? V_30 -> V_33 : FALSE ) ;
}
static T_5 *
F_14 ( T_5 * V_30 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_6 V_34 , void (* F_13)( void ) ,
T_6 V_33 )
{
T_5 * V_26 ;
const char * V_35 ;
T_7 V_36 ;
if ( ( V_26 = F_16 ( V_30 , V_31 ) ) ) {
V_26 -> V_21 = V_21 ;
V_26 -> F_13 = F_13 ;
V_26 -> V_32 = V_32 ;
if ( F_17 ( V_21 ) == NULL ) {
F_18 ( V_1 , V_21 , V_26 ,
V_37 ) ;
}
return V_26 ;
}
V_26 = F_19 ( F_3 () , T_5 ) ;
V_26 -> V_21 = V_21 ;
V_26 -> V_31 = V_31 ;
V_26 -> V_32 = V_32 ;
V_26 -> F_13 = F_13 ;
V_26 -> V_27 = NULL ;
V_26 -> V_30 = V_30 ;
V_26 -> V_29 = NULL ;
V_26 -> V_28 = 0 ;
V_26 -> V_38 = FALSE ;
V_26 -> V_39 = FALSE ;
V_26 -> V_33 = V_33 ;
if ( V_21 != NULL ) {
for ( V_35 = V_21 ; ( V_36 = * V_35 ) != '\0' ; V_35 ++ )
F_20 ( isascii ( V_36 ) &&
( islower ( V_36 ) || isdigit ( V_36 ) || V_36 == '_' ||
V_36 == '-' || V_36 == '.' ) ) ;
F_20 ( F_17 ( V_21 ) == NULL ) ;
F_18 ( V_1 , V_21 , V_26 , V_37 ) ;
} else {
F_20 ( V_34 ) ;
}
if ( V_30 == NULL ) {
F_18 ( V_2 , V_31 , V_26 , V_37 ) ;
} else {
if ( V_30 -> V_29 == NULL )
V_30 -> V_29 = F_2 ( F_3 () ) ;
F_18 ( V_30 -> V_29 , V_31 , V_26 , V_37 ) ;
}
return V_26 ;
}
T_5 *
F_21 ( int V_40 , void (* F_13)( void ) )
{
T_8 * V_41 ;
if ( V_42 == NULL ) {
F_22 () ;
}
V_41 = F_23 ( V_40 ) ;
return F_12 ( V_42 ,
F_24 ( V_40 ) ,
F_25 ( V_41 ) ,
F_26 ( V_40 ) , F_13 , TRUE ) ;
}
T_5 *
F_27 ( const char * V_43 , int V_40 , void (* F_13)( void ) )
{
T_8 * V_41 ;
T_5 * V_44 ;
T_5 * V_45 ;
char * V_46 = NULL , * V_47 = NULL , * V_48 = NULL ;
if ( V_42 == NULL ) {
F_22 () ;
}
V_44 = V_42 ;
if ( V_43 ) {
V_48 = V_47 = F_28 ( V_43 ) ;
while ( V_47 && * V_47 ) {
if ( ( V_46 = strchr ( V_47 , '/' ) ) )
* V_46 ++ = '\0' ;
if ( ! ( V_45 = F_16 ( V_44 , V_47 ) ) ) {
V_47 = F_29 ( F_3 () , V_47 ) ,
V_45 = F_15 ( V_44 , V_47 , V_47 , NULL ) ;
}
V_44 = V_45 ;
V_47 = V_46 ;
}
F_5 ( V_48 ) ;
}
V_41 = F_23 ( V_40 ) ;
return F_12 ( V_44 ,
F_24 ( V_40 ) ,
F_25 ( V_41 ) ,
F_26 ( V_40 ) , F_13 , TRUE ) ;
}
T_5 *
F_30 ( int V_40 )
{
T_5 * V_26 ;
T_8 * V_41 ;
if ( V_42 == NULL ) {
F_22 () ;
}
V_41 = F_23 ( V_40 ) ;
V_26 = F_12 ( V_42 ,
F_24 ( V_40 ) ,
F_25 ( V_41 ) ,
F_26 ( V_40 ) , NULL , TRUE ) ;
V_26 -> V_39 = TRUE ;
return V_26 ;
}
T_5 *
F_31 ( const char * V_21 , const char * V_31 ,
const char * V_32 , void (* F_13)( void ) )
{
if ( V_49 == NULL ) {
F_22 () ;
}
return F_12 ( V_49 , V_21 , V_31 , V_32 ,
F_13 , TRUE ) ;
}
T_5 *
F_17 ( const char * V_21 )
{
return ( T_5 * ) F_32 ( V_1 , V_21 , V_37 ) ;
}
static T_5 *
F_16 ( T_5 * V_30 , const char * V_21 )
{
return ( T_5 * ) F_32 ( V_30 ? V_30 -> V_29 : V_2 , V_21 , V_37 ) ;
}
static T_6
F_33 ( void * V_50 , void * V_3 )
{
T_5 * V_26 = ( T_5 * ) V_50 ;
T_9 * V_51 = ( T_9 * ) V_3 ;
if ( ! V_26 -> V_39 )
V_51 -> V_52 = (* V_51 -> V_53 )( V_26 , V_51 -> T_2 ) ;
return ( V_51 -> V_52 != 0 ) ;
}
static T_4
F_34 ( T_10 * V_54 , T_11 V_53 ,
T_1 T_2 )
{
T_9 V_51 ;
if ( V_54 == NULL )
V_54 = V_2 ;
V_51 . V_53 = V_53 ;
V_51 . T_2 = T_2 ;
V_51 . V_52 = 0 ;
F_35 ( V_54 , F_33 , & V_51 ) ;
return V_51 . V_52 ;
}
T_6
F_36 ( T_5 * V_26 )
{
if ( V_26 -> V_29 == NULL ) {
return FALSE ;
}
if ( F_37 ( V_26 -> V_29 ) ) {
return FALSE ;
}
return TRUE ;
}
T_4
F_11 ( T_11 V_53 , T_1 T_2 )
{
return F_34 ( V_1 , V_53 , T_2 ) ;
}
T_4
F_9 ( T_5 * V_26 , T_11 V_53 ,
T_1 T_2 )
{
return F_34 ( ( V_26 ) ? V_26 -> V_29 : V_2 , V_53 , T_2 ) ;
}
static T_6
F_38 ( void * V_50 , void * V_3 V_4 )
{
T_5 * V_26 = ( T_5 * ) V_50 ;
if ( V_26 -> V_39 )
return FALSE ;
if ( V_26 -> V_38 ) {
if ( V_26 -> F_13 != NULL )
(* V_26 -> F_13 )() ;
V_26 -> V_38 = FALSE ;
}
return FALSE ;
}
void
F_39 ( void )
{
F_35 ( V_1 , F_38 , NULL ) ;
}
void
F_40 ( T_5 * V_26 )
{
if ( V_26 && V_26 -> V_38 )
F_38 ( V_26 , NULL ) ;
}
static T_3 *
F_41 ( T_5 * V_26 , const char * V_21 , const char * V_31 ,
const char * V_32 , T_12 type )
{
T_3 * V_55 ;
const T_13 * V_35 ;
V_55 = F_42 ( T_3 , 1 ) ;
V_55 -> V_21 = V_21 ;
V_55 -> V_31 = V_31 ;
V_55 -> V_32 = V_32 ;
V_55 -> type = type ;
V_55 -> V_56 = V_57 ;
if ( V_31 != NULL )
V_55 -> V_58 = V_26 -> V_28 ;
else
V_55 -> V_58 = - 1 ;
for ( V_35 = V_21 ; * V_35 != '\0' ; V_35 ++ )
if ( ! ( isascii ( ( T_7 ) * V_35 ) &&
( islower ( ( T_7 ) * V_35 ) || isdigit ( ( T_7 ) * V_35 ) || * V_35 == '_' || * V_35 == '.' ) ) )
F_43 ( L_2 , V_26 -> V_21 , V_21 ) ;
if ( F_44 ( V_26 , V_21 ) != NULL )
F_43 ( L_3 , V_21 ) ;
if ( ( type != V_6 ) &&
( V_26 -> V_21 != NULL ) ) {
if ( ! ( ( strncmp ( V_21 , V_26 -> V_21 , strlen ( V_26 -> V_21 ) ) != 0 ) ||
( ( ( V_21 [ strlen ( V_26 -> V_21 ) ] ) != '.' ) && ( ( V_21 [ strlen ( V_26 -> V_21 ) ] ) != '_' ) ) ) )
F_43 ( L_4 , V_21 ) ;
}
V_26 -> V_27 = F_45 ( V_26 -> V_27 , V_55 ) ;
if ( V_31 != NULL )
V_26 -> V_28 ++ ;
return V_55 ;
}
static T_14
F_46 ( T_15 V_59 , T_15 V_60 )
{
const T_3 * V_5 = ( const T_3 * ) V_59 ;
const char * V_21 = ( const char * ) V_60 ;
return strcmp ( V_21 , V_5 -> V_21 ) ;
}
static T_6
F_47 ( void * V_50 , void * V_3 )
{
T_16 * V_61 = ( T_16 * ) V_3 ;
T_17 * V_62 ;
T_5 * V_26 = ( T_5 * ) V_50 ;
if ( V_26 == NULL )
return FALSE ;
V_62 = F_48 ( V_26 -> V_27 , V_61 -> V_21 ,
F_46 ) ;
if ( V_62 == NULL )
return FALSE ;
V_61 -> V_62 = V_62 ;
return TRUE ;
}
struct V_55 *
F_44 ( T_5 * V_26 , const char * V_21 )
{
T_16 V_61 ;
T_17 * V_62 ;
if ( V_26 == NULL )
return NULL ;
V_62 = F_48 ( V_26 -> V_27 , V_21 ,
F_46 ) ;
if ( V_62 == NULL )
{
V_61 . V_62 = NULL ;
if ( V_26 -> V_29 != NULL )
{
V_61 . V_21 = V_21 ;
F_35 ( V_26 -> V_29 , F_47 , & V_61 ) ;
}
V_62 = V_61 . V_62 ;
}
if ( V_62 == NULL )
return NULL ;
return (struct V_55 * ) V_62 -> V_3 ;
}
T_6
F_49 ( const char * V_21 )
{
T_5 * V_63 = F_17 ( V_21 ) ;
return ( V_63 != NULL && ! V_63 -> V_39 ) ;
}
const char *
F_50 ( const char * V_21 )
{
T_5 * V_63 = F_17 ( V_21 ) ;
return ( V_63 != NULL && ! V_63 -> V_39 ) ? V_63 -> V_31 : NULL ;
}
void
F_51 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_4 V_64 , T_4 * V_65 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_9 ) ;
V_55 -> V_16 . V_66 = V_65 ;
V_55 -> V_17 . V_66 = * V_65 ;
F_20 ( V_64 > 0 && V_64 != 1 && V_64 < 37 ) ;
V_55 -> V_67 . V_64 = V_64 ;
}
static void
F_52 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_24 , T_4 * V_65 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_20 ) ;
V_55 -> V_24 = * V_24 ;
V_55 -> V_16 . V_66 = V_65 ;
V_55 -> V_17 . V_66 = * V_65 ;
}
void
F_53 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_6 * V_65 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_7 ) ;
V_55 -> V_16 . V_69 = V_65 ;
V_55 -> V_17 . V_23 = * V_65 ;
}
void
F_54 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_14 * V_65 , const T_18 * V_70 ,
T_6 V_71 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_8 ) ;
V_55 -> V_16 . V_72 = V_65 ;
V_55 -> V_17 . V_73 = * V_65 ;
V_55 -> V_67 . V_74 . V_70 = V_70 ;
V_55 -> V_67 . V_74 . V_71 = V_71 ;
}
static T_3 *
F_55 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 , T_12 type )
{
T_3 * V_55 ;
char * V_75 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
type ) ;
if ( * V_65 == NULL ) {
* V_65 = F_28 ( L_5 ) ;
V_75 = F_28 ( L_5 ) ;
} else {
* V_65 = F_28 ( * V_65 ) ;
V_75 = F_28 ( * V_65 ) ;
}
V_55 -> V_16 . string = V_65 ;
V_55 -> V_17 . string = V_75 ;
V_55 -> V_22 . string = NULL ;
return V_55 ;
}
void
F_56 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 )
{
F_55 ( V_26 , V_21 , V_31 , V_32 , V_65 ,
V_13 ) ;
}
static void
F_57 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_24 , const char * * V_65 )
{
T_3 * V_55 ;
V_55 = F_55 ( V_26 , V_21 , V_31 , V_32 , V_65 ,
V_20 ) ;
V_55 -> V_24 = * V_24 ;
}
void
F_58 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 )
{
F_55 ( V_26 , V_21 , V_31 , V_32 , V_65 ,
V_14 ) ;
}
void
F_59 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_65 )
{
F_55 ( V_26 , V_21 , V_31 , V_32 , V_65 ,
V_15 ) ;
}
void
F_60 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_19 * * V_65 , T_20 V_76 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_18 ) ;
V_55 -> V_67 . V_76 = V_76 ;
if ( * V_65 == NULL )
* V_65 = F_61 () ;
V_55 -> V_16 . V_19 = V_65 ;
V_55 -> V_17 . V_19 = F_62 ( * V_65 ) ;
V_55 -> V_22 . V_19 = NULL ;
}
void
F_63 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 ,
const char * V_32 )
{
F_41 ( V_26 , V_21 , V_31 , V_32 , V_10 ) ;
}
extern void
F_64 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_21 * V_77 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_11 ) ;
V_55 -> V_16 . V_77 = V_77 ;
}
extern void
F_65 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_21 * V_77 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_11 ) ;
V_55 -> V_16 . V_77 = V_77 ;
V_55 -> V_56 = V_78 ;
}
void
F_66 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_22 * V_79 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_12 ) ;
V_55 -> V_16 . V_80 = V_79 ;
V_55 -> V_17 . V_79 = * V_79 ;
}
static void
F_67 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_24 ,
T_23 V_81 ,
T_17 * * V_82 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_20 ) ;
V_55 -> V_24 = * V_24 ;
V_81 ( V_55 , V_82 ) ;
}
void
F_68 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
struct V_68 * V_24 ,
void * * T_24 V_4 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_20 ) ;
V_55 -> V_24 = * V_24 ;
}
void
F_69 ( T_5 * V_26 , const char * V_21 )
{
F_41 ( V_26 , V_21 , NULL , NULL , V_6 ) ;
}
extern T_6
F_70 ( T_3 * V_5 )
{
if ( V_5 )
return V_5 -> type == V_6 ? TRUE : FALSE ;
return TRUE ;
}
extern T_25
F_71 ( T_3 * V_5 )
{
if ( V_5 ) {
V_5 -> type = V_6 ;
return V_83 ;
}
return V_84 ;
}
T_4
F_72 ( T_3 * V_5 )
{
if ( V_5 && V_5 -> type == V_9 )
return * V_5 -> V_16 . V_66 ;
return 0 ;
}
T_4
F_73 ( T_5 * V_26 , T_26 V_53 , T_1 T_2 )
{
T_17 * V_85 ;
T_3 * V_5 ;
T_4 V_52 ;
for ( V_85 = F_74 ( V_26 -> V_27 ) ; V_85 != NULL ; V_85 = F_75 ( V_85 ) ) {
V_5 = ( T_3 * ) V_85 -> V_3 ;
if ( V_5 -> type == V_6 ) {
continue;
}
V_52 = (* V_53)( V_5 , T_2 ) ;
if ( V_52 != 0 )
return V_52 ;
}
return 0 ;
}
static void
F_76 ( void )
{
if ( V_27 . V_86 < 100 || V_27 . V_86 > 10000 )
V_27 . V_86 = V_87 ;
#ifdef F_77
if ( V_27 . V_88 < 1 || V_27 . V_88 > 10 )
V_27 . V_88 = V_89 ;
#endif
if ( V_27 . V_90 < 1 ) {
V_27 . V_90 = 1 ;
}
else if ( V_27 . V_90 > V_91 ) {
V_27 . V_90 = V_91 ;
}
if ( V_27 . V_92 < V_27 . V_90 ) {
V_27 . V_92 = V_27 . V_90 ;
}
V_27 . V_92 -= V_27 . V_92 % V_27 . V_90 ;
if ( ( V_27 . V_92 / V_27 . V_90 ) > V_93 ) {
V_27 . V_92 = V_27 . V_90 * V_93 ;
}
}
static void
F_78 ( void )
{
if ( V_27 . V_94 == 0 )
V_27 . V_94 = 10 ;
if ( V_27 . V_95 == 0 )
V_27 . V_95 = 10 ;
}
static void
F_79 ( void )
{
if ( V_27 . V_96 == V_97 ||
V_27 . V_96 >= V_98 ) {
V_27 . V_96 = V_99 ;
}
}
static void F_80 ( T_3 * V_5 V_4 ) {}
static void
F_81 ( T_3 * V_5 )
{
* V_5 -> V_16 . V_66 = V_5 -> V_17 . V_66 ;
}
static T_25
F_82 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_100 )
{
T_4 V_101 ;
V_101 = ( T_4 ) strtoul ( V_50 , NULL , 10 ) ;
if ( * V_5 -> V_16 . V_66 != V_101 ) {
* V_100 = TRUE ;
* V_5 -> V_16 . V_66 = V_101 ;
}
if ( * V_5 -> V_16 . V_66 & ( V_102 | V_103 ) ) {
F_83 ( L_6 , L_7 , TRUE ) ;
}
return V_83 ;
}
static const char * F_84 ( void ) {
return L_8 ;
}
static char * F_85 ( void ) {
return F_86 (
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ) ;
}
static T_6 F_87 ( T_3 * V_5 ) {
return * V_5 -> V_16 . V_66 == V_5 -> V_17 . V_66 ;
}
static char * F_88 ( T_3 * V_5 , T_6 V_17 ) {
return F_86 ( L_17 , V_17 ? V_5 -> V_17 . V_66 : * V_5 -> V_16 . V_66 ) ;
}
static void
F_89 ( T_3 * V_5 )
{
F_5 ( ( char * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = NULL ;
F_5 ( V_5 -> V_17 . string ) ;
V_5 -> V_17 . string = NULL ;
}
static void
F_90 ( T_3 * V_5 )
{
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_5 -> V_17 . string ) ;
}
static T_25
F_91 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_100 )
{
T_17 * V_104 ;
T_27 * V_105 ;
T_3 * V_106 ;
if ( * V_5 -> V_16 . string ) {
if ( strcmp ( * V_5 -> V_16 . string , V_50 ) != 0 ) {
* V_100 = TRUE ;
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_50 ) ;
}
} else if ( V_50 ) {
* V_5 -> V_16 . string = F_28 ( V_50 ) ;
}
V_106 = F_44 ( V_107 , V_108 ) ;
for ( V_104 = * V_106 -> V_16 . V_82 ; V_104 != NULL ; V_104 = V_104 -> V_109 ) {
V_105 = ( T_27 * ) V_104 -> V_3 ;
V_105 -> V_110 = F_92 ( * V_5 -> V_16 . string , V_105 ) ;
}
return V_83 ;
}
static const char *
F_93 ( void )
{
return L_18 ;
}
static char *
F_94 ( void )
{
return F_28 ( L_19 ) ;
}
static char *
F_95 ( T_3 * V_5 , T_6 V_17 )
{
T_28 * V_111 = F_96 ( L_5 ) ;
T_17 * V_104 ;
T_27 * V_105 ;
T_3 * V_106 ;
if ( V_17 )
return F_28 ( V_5 -> V_17 . string ) ;
V_106 = F_44 ( V_107 , V_108 ) ;
V_104 = ( V_106 ) ? * V_106 -> V_16 . V_82 : NULL ;
while ( V_104 ) {
T_13 * V_112 ;
V_105 = ( T_27 * ) V_104 -> V_3 ;
if ( ( V_105 -> V_113 == V_114 ) && ( V_105 -> V_115 ) ) {
V_112 = F_86 ( L_20 ,
F_97 ( V_105 -> V_113 ) ,
V_105 -> V_115 ,
V_105 -> V_116 ,
V_105 -> V_117 ? 'R' : 'U' ) ;
} else {
V_112 = F_28 ( F_97 ( V_105 -> V_113 ) ) ;
}
if ( ! V_105 -> V_110 ) {
if ( V_111 -> V_118 )
F_98 ( V_111 , L_21 ) ;
F_98 ( V_111 , V_112 ) ;
}
V_104 = V_104 -> V_109 ;
}
return F_99 ( V_111 , FALSE ) ;
}
static T_6
F_100 ( T_3 * V_5 )
{
char * V_119 = F_95 ( V_5 , FALSE ) ;
T_6 V_120 = F_101 ( V_119 , V_5 -> V_17 . string ) == 0 ;
F_5 ( V_119 ) ;
return V_120 ;
}
static void
F_102 ( T_3 * V_5 )
{
* V_5 -> V_16 . V_66 = V_5 -> V_17 . V_66 ;
}
static T_25
F_103 ( T_3 * V_5 V_4 , const T_13 * V_50 V_4 , T_6 * V_100 V_4 )
{
return V_83 ;
}
static const char *
F_104 ( void )
{
return NULL ;
}
static char *
F_105 ( void )
{
return F_28 ( L_5 ) ;
}
static T_6
F_106 ( T_3 * V_5 V_4 )
{
return TRUE ;
}
static char *
F_107 ( T_3 * V_5 V_4 , T_6 V_17 V_4 )
{
return F_28 ( L_5 ) ;
}
static void
F_108 ( T_3 * V_5 , T_17 * * V_50 )
{
T_27 * V_121 , * V_122 ;
T_17 * V_123 ;
V_5 -> V_16 . V_82 = V_50 ;
V_5 -> V_17 . V_82 = NULL ;
for ( V_123 = * V_5 -> V_16 . V_82 ; V_123 != NULL ; V_123 = F_75 ( V_123 ) ) {
V_121 = ( T_27 * ) V_123 -> V_3 ;
V_122 = F_42 ( T_27 , 1 ) ;
V_122 -> V_31 = F_28 ( V_121 -> V_31 ) ;
V_122 -> V_113 = V_121 -> V_113 ;
if ( V_121 -> V_115 ) {
V_122 -> V_115 = F_28 ( V_121 -> V_115 ) ;
V_122 -> V_116 = V_121 -> V_116 ;
} else {
V_122 -> V_115 = NULL ;
V_122 -> V_116 = 0 ;
}
V_122 -> V_110 = V_121 -> V_110 ;
V_122 -> V_117 = V_121 -> V_117 ;
V_5 -> V_17 . V_82 = F_45 ( V_5 -> V_17 . V_82 , V_122 ) ;
}
}
static void
F_109 ( T_3 * V_5 )
{
F_110 ( * V_5 -> V_16 . V_82 ) ;
F_110 ( V_5 -> V_17 . V_82 ) ;
}
static void
F_111 ( T_3 * V_5 )
{
T_27 * V_121 , * V_122 ;
T_17 * V_123 ;
T_3 * V_124 ;
F_110 ( * V_5 -> V_16 . V_82 ) ;
* V_5 -> V_16 . V_82 = NULL ;
for ( V_123 = V_5 -> V_17 . V_82 ; V_123 != NULL ; V_123 = F_75 ( V_123 ) ) {
V_121 = ( T_27 * ) V_123 -> V_3 ;
V_122 = F_42 ( T_27 , 1 ) ;
V_122 -> V_31 = F_28 ( V_121 -> V_31 ) ;
V_122 -> V_113 = V_121 -> V_113 ;
if ( V_121 -> V_115 ) {
V_122 -> V_115 = F_28 ( V_121 -> V_115 ) ;
V_122 -> V_116 = V_121 -> V_116 ;
} else {
V_122 -> V_115 = NULL ;
V_122 -> V_116 = 0 ;
}
V_122 -> V_110 = V_121 -> V_110 ;
V_122 -> V_117 = V_121 -> V_117 ;
* V_5 -> V_16 . V_82 = F_45 ( * V_5 -> V_16 . V_82 , V_122 ) ;
}
V_124 = F_44 ( V_107 , V_125 ) ;
F_20 ( V_124 != NULL ) ;
F_102 ( V_124 ) ;
}
static T_25
F_112 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_100 V_4 )
{
T_17 * V_126 , * V_127 ;
T_27 * V_105 ;
T_14 V_128 ;
T_3 * V_129 , * V_124 ;
V_126 = F_113 ( V_50 ) ;
if ( V_126 == NULL )
return V_130 ;
if ( ( F_114 ( V_126 ) % 2 ) != 0 ) {
F_115 ( V_126 ) ;
return V_130 ;
}
V_127 = F_74 ( V_126 ) ;
while ( V_127 ) {
T_27 V_131 ;
V_127 = V_127 -> V_109 ;
if ( ! F_116 ( & V_131 , ( char * ) V_127 -> V_3 ) ) {
F_115 ( V_126 ) ;
return V_130 ;
}
if ( V_131 . V_113 != V_114 ) {
F_117 ( & V_127 -> V_3 ) ;
} else {
F_5 ( V_131 . V_115 ) ;
}
V_127 = V_127 -> V_109 ;
}
F_110 ( * V_5 -> V_16 . V_82 ) ;
* V_5 -> V_16 . V_82 = NULL ;
V_129 = F_44 ( V_107 , V_132 ) ;
F_20 ( V_129 != NULL ) ;
V_124 = F_44 ( V_107 , V_125 ) ;
F_20 ( V_124 != NULL ) ;
V_128 = F_114 ( V_126 ) ;
* V_124 -> V_16 . V_66 = V_128 / 2 ;
V_127 = F_74 ( V_126 ) ;
while ( V_127 ) {
V_105 = F_42 ( T_27 , 1 ) ;
V_105 -> V_31 = F_28 ( ( T_13 * ) V_127 -> V_3 ) ;
V_127 = V_127 -> V_109 ;
F_116 ( V_105 , ( char * ) V_127 -> V_3 ) ;
V_105 -> V_110 = F_92 ( * V_129 -> V_16 . string , V_105 ) ;
V_127 = V_127 -> V_109 ;
* V_5 -> V_16 . V_82 = F_45 ( * V_5 -> V_16 . V_82 , V_105 ) ;
}
F_115 ( V_126 ) ;
F_89 ( V_129 ) ;
return V_83 ;
}
static const char *
F_118 ( void )
{
return L_22 ;
}
static char *
F_119 ( void )
{
return F_28 ( L_23 ) ;
}
static T_6
F_120 ( T_3 * V_5 )
{
T_17 * V_104 = * V_5 -> V_16 . V_82 ,
* V_133 = F_74 ( V_104 ) ,
* V_134 = F_74 ( V_5 -> V_17 . V_82 ) ;
T_27 * V_105 , * V_135 ;
T_6 V_120 = TRUE ;
T_3 * V_124 ;
V_124 = F_44 ( V_107 , V_125 ) ;
if ( V_124 && * V_124 -> V_16 . V_66 != V_124 -> V_17 . V_66 ) {
V_120 = FALSE ;
} else {
while ( V_133 && V_134 ) {
V_105 = ( T_27 * ) V_133 -> V_3 ;
V_135 = ( T_27 * ) V_134 -> V_3 ;
if ( ( F_101 ( V_105 -> V_31 , V_135 -> V_31 ) != 0 ) ||
( V_105 -> V_113 != V_135 -> V_113 ) ||
( ( ( V_105 -> V_113 == V_114 ) && ( V_105 -> V_115 ) ) &&
( ( F_101 ( V_105 -> V_115 , V_135 -> V_115 ) != 0 ) ||
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
F_121 ( T_3 * V_5 , T_6 V_17 )
{
T_17 * V_136 = V_17 ? V_5 -> V_17 . V_82 : * V_5 -> V_16 . V_82 ;
T_17 * V_104 = F_74 ( V_136 ) ;
T_17 * V_126 ;
T_27 * V_105 ;
T_13 * V_112 ;
char * V_137 ;
V_126 = NULL ;
while ( V_104 ) {
V_105 = ( T_27 * ) V_104 -> V_3 ;
V_126 = F_45 ( V_126 , F_28 ( V_105 -> V_31 ) ) ;
if ( ( V_105 -> V_113 == V_114 ) && ( V_105 -> V_115 ) ) {
V_112 = F_86 ( L_20 ,
F_97 ( V_105 -> V_113 ) ,
V_105 -> V_115 ,
V_105 -> V_116 ,
V_105 -> V_117 ? 'R' : 'U' ) ;
} else {
V_112 = F_28 ( F_97 ( V_105 -> V_113 ) ) ;
}
V_126 = F_45 ( V_126 , V_112 ) ;
V_104 = V_104 -> V_109 ;
}
V_137 = F_122 ( V_126 ) ;
F_8 ( V_126 ) ;
return V_137 ;
}
static void
F_123 ( T_3 * V_5 , T_17 * * V_138 )
{
T_17 * V_139 = * V_138 ,
* V_140 = NULL ;
while ( V_139 ) {
V_140 = F_45 ( V_140 , F_28 ( ( T_13 * ) V_139 -> V_3 ) ) ;
V_139 = V_139 -> V_109 ;
}
V_5 -> V_17 . V_82 = V_140 ;
V_5 -> V_16 . V_82 = & V_27 . V_141 ;
V_5 -> V_22 . V_23 = FALSE ;
}
static void
F_124 ( T_3 * V_5 )
{
T_17 * V_142 = V_27 . V_141 ;
T_13 * V_143 ;
while ( V_142 ) {
V_143 = ( T_13 * ) V_142 -> V_3 ;
F_5 ( V_143 ) ;
V_142 = F_125 ( V_142 , V_142 ) ;
}
F_8 ( V_142 ) ;
V_27 . V_141 = NULL ;
if ( V_5 -> V_22 . V_23 == TRUE ) {
T_17 * V_140 ;
T_13 * V_144 ;
V_140 = V_5 -> V_17 . V_82 ;
while ( V_140 != NULL ) {
V_144 = ( T_13 * ) V_140 -> V_3 ;
F_5 ( V_144 ) ;
V_140 = F_125 ( V_140 , V_140 ) ;
}
F_8 ( V_140 ) ;
V_140 = NULL ;
}
}
static void
F_126 ( T_3 * V_5 )
{
T_17 * V_145 , * V_140 ;
T_13 * V_146 ;
V_145 = * V_5 -> V_16 . V_82 ;
while ( V_145 != NULL ) {
V_146 = ( T_13 * ) V_145 -> V_3 ;
F_5 ( V_146 ) ;
V_145 = F_125 ( V_145 , V_145 ) ;
}
F_8 ( V_145 ) ;
V_145 = NULL ;
for ( V_140 = V_5 -> V_17 . V_82 ; V_140 != NULL ; V_140 = F_75 ( V_140 ) ) {
V_145 = F_45 ( V_145 , F_28 ( ( T_13 * ) V_140 -> V_3 ) ) ;
}
* V_5 -> V_16 . V_82 = V_145 ;
}
static T_25
F_127 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_100 V_4 )
{
T_17 * V_126 = F_113 ( V_50 ) ;
T_17 * V_127 ;
T_13 * V_143 ;
int V_147 ;
if ( V_126 == NULL )
return V_130 ;
F_124 ( V_5 ) ;
V_127 = F_74 ( V_126 ) ;
if ( ! ( * ( T_13 * ) V_127 -> V_3 ) ) {
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
V_143 = F_28 ( V_149 [ V_147 ] ) ;
V_27 . V_141 = F_45 ( V_27 . V_141 , V_143 ) ;
}
}
while ( V_127 ) {
T_6 V_150 = FALSE ;
V_143 = ( T_13 * ) V_127 -> V_3 ;
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
if ( strcmp ( V_143 , V_149 [ V_147 ] ) == 0 ) {
V_150 = TRUE ;
break;
}
}
if ( ! V_150 ) {
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
V_143 = F_28 ( V_149 [ V_147 ] ) ;
V_27 . V_141 = F_45 ( V_27 . V_141 , V_143 ) ;
}
V_5 -> V_16 . V_82 = & V_27 . V_141 ;
return V_130 ;
}
V_127 = V_127 -> V_109 ;
}
V_127 = F_74 ( V_126 ) ;
while ( V_127 ) {
V_143 = ( T_13 * ) V_127 -> V_3 ;
V_27 . V_141 = F_45 ( V_27 . V_141 , V_143 ) ;
V_127 = V_127 -> V_109 ;
}
V_5 -> V_16 . V_82 = & V_27 . V_141 ;
return V_83 ;
}
static const char *
F_128 ( void )
{
return L_24 ;
}
static char *
F_129 ( void )
{
return F_28 (
L_25
V_151 ) ;
}
static T_6
F_130 ( T_3 * V_5 )
{
T_17 * V_133 = F_74 ( V_27 . V_141 ) ,
* V_134 = F_74 ( V_5 -> V_17 . V_82 ) ;
T_6 V_120 = TRUE ;
while ( V_133 && V_134 ) {
if ( strcmp ( ( T_13 * ) V_133 -> V_3 , ( T_13 * ) V_134 -> V_3 ) != 0 ) {
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
F_131 ( T_3 * V_5 , T_6 V_17 )
{
T_17 * V_136 = V_17 ? V_5 -> V_17 . V_82 : V_27 . V_141 ;
T_17 * V_104 = F_74 ( V_136 ) ;
T_17 * V_126 = NULL ;
T_13 * V_144 , * V_152 ;
while ( V_104 ) {
V_144 = ( T_13 * ) V_104 -> V_3 ;
V_126 = F_45 ( V_126 , F_28 ( V_144 ) ) ;
V_104 = V_104 -> V_109 ;
}
V_152 = F_122 ( V_126 ) ;
F_8 ( V_126 ) ;
return V_152 ;
}
static void
F_132 ( T_3 * V_5 )
{
F_5 ( ( char * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = NULL ;
F_5 ( V_5 -> V_17 . string ) ;
V_5 -> V_17 . string = NULL ;
}
static void
F_133 ( T_3 * V_5 )
{
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_5 -> V_17 . string ) ;
}
static T_25
F_134 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_100 )
{
if ( strcmp ( * V_5 -> V_16 . string , V_50 ) != 0 ) {
* V_100 = TRUE ;
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_50 ) ;
}
return V_83 ;
}
static const char *
F_135 ( void )
{
return NULL ;
}
static char *
F_136 ( void )
{
return F_28 ( L_5 ) ;
}
static T_6
F_137 ( T_3 * V_5 V_4 )
{
return TRUE ;
}
static char *
F_138 ( T_3 * V_5 V_4 , T_6 V_17 V_4 )
{
return F_28 ( L_5 ) ;
}
void
F_22 ( void )
{
T_5 * V_153 , * V_154 , * V_155 ,
* V_156 , * V_157 ;
struct V_68 V_24 ;
if ( V_42 != NULL ) {
return;
}
F_139 () ;
V_158 = F_12 ( NULL , L_26 , L_27 ,
L_27 , & F_78 , FALSE ) ;
F_54 ( V_158 , L_28 ,
L_29 ,
L_30 ,
( T_14 * ) ( void * ) ( & V_27 . V_159 ) , V_160 , FALSE ) ;
F_69 ( V_158 , L_31 ) ;
F_69 ( V_158 , L_32 ) ;
F_69 ( V_158 , L_33 ) ;
F_53 ( V_158 , L_34 ,
L_35 ,
L_36 ,
& V_27 . V_161 ) ;
F_53 ( V_158 , L_37 ,
L_38 ,
L_39 ,
& V_27 . V_162 ) ;
F_53 ( V_158 , L_40 ,
L_41 ,
L_42 ,
& V_27 . V_163 ) ;
F_54 ( V_158 , L_43 ,
L_44 ,
L_44 ,
& V_27 . V_164 , V_164 , FALSE ) ;
F_54 ( V_158 , L_45 ,
L_46 ,
L_46 ,
& V_27 . V_165 , V_165 , FALSE ) ;
F_54 ( V_158 , L_47 ,
L_48 ,
L_48 ,
& V_27 . V_166 , V_166 , FALSE ) ;
V_107 = F_15 ( V_158 , L_49 , L_49 , NULL ) ;
V_24 . V_25 = F_89 ;
V_24 . V_167 = F_90 ;
V_24 . V_168 = F_91 ;
V_24 . V_169 = F_93 ;
V_24 . V_170 = F_94 ;
V_24 . V_171 = F_100 ;
V_24 . V_172 = F_95 ;
F_57 ( V_107 , V_132 , L_18 ,
L_50 , & V_24 , ( const char * * ) & V_173 ) ;
V_24 . V_25 = F_109 ;
V_24 . V_167 = F_111 ;
V_24 . V_168 = F_112 ;
V_24 . V_169 = F_118 ;
V_24 . V_170 = F_119 ;
V_24 . V_171 = F_120 ;
V_24 . V_172 = F_121 ;
F_67 ( V_107 , V_108 , L_22 ,
L_23 , & V_24 ,
F_108 , & V_27 . V_174 ) ;
V_24 . V_25 = F_80 ;
V_24 . V_167 = F_102 ;
V_24 . V_168 = F_103 ;
V_24 . V_169 = F_104 ;
V_24 . V_170 = F_105 ;
V_24 . V_171 = F_106 ;
V_24 . V_172 = F_107 ;
F_52 ( V_107 , V_125 , L_51 ,
L_52 , & V_24 , & V_27 . V_175 ) ;
V_157 = F_15 ( V_158 , L_53 , L_53 , NULL ) ;
F_69 ( V_157 , L_54 ) ;
F_56 ( V_157 , L_55 , L_56 ,
L_57 , ( const char * * ) & V_27 . V_176 ) ;
F_56 ( V_157 , L_58 , L_56 ,
L_59 , ( const char * * ) & V_27 . V_177 ) ;
V_178 = F_15 ( V_158 , L_60 , L_60 , NULL ) ;
F_66 ( V_178 , L_61 , L_62 ,
L_62 , & V_27 . V_179 ) ;
F_66 ( V_178 , L_63 , L_62 ,
L_62 , & V_27 . V_180 ) ;
F_66 ( V_178 , L_64 , L_65 ,
L_65 , & V_27 . V_181 ) ;
F_66 ( V_178 , L_66 , L_65 ,
L_65 , & V_27 . V_182 ) ;
F_66 ( V_178 , L_67 , L_68 ,
L_68 , & V_27 . V_183 ) ;
F_66 ( V_178 , L_69 , L_68 ,
L_68 , & V_27 . V_184 ) ;
F_66 ( V_178 , L_70 , L_68 ,
L_68 , & V_27 . V_185 ) ;
F_66 ( V_178 , L_71 , L_68 ,
L_68 , & V_27 . V_186 ) ;
V_24 . V_25 = F_132 ;
V_24 . V_167 = F_133 ;
V_24 . V_168 = F_134 ;
V_24 . V_169 = F_135 ;
V_24 . V_170 = F_136 ;
V_24 . V_171 = F_137 ;
V_24 . V_172 = F_138 ;
F_57 ( V_107 , L_72 , L_73 ,
L_74 , & V_24 , ( const char * * ) & V_27 . V_187 ) ;
V_24 . V_25 = F_132 ;
V_24 . V_167 = F_133 ;
V_24 . V_168 = F_134 ;
V_24 . V_169 = F_135 ;
V_24 . V_170 = F_136 ;
V_24 . V_171 = F_137 ;
V_24 . V_172 = F_138 ;
F_57 ( V_107 , L_75 , L_76 ,
L_77 , & V_24 , ( const char * * ) & V_27 . V_188 ) ;
F_66 ( V_178 , L_78 , L_79 ,
L_79 , & V_27 . V_189 ) ;
F_66 ( V_178 , L_80 , L_81 ,
L_81 , & V_27 . V_190 ) ;
F_66 ( V_178 , L_82 , L_83 ,
L_83 , & V_27 . V_191 ) ;
F_54 ( V_158 , L_84 ,
L_85 ,
L_85 ,
& V_27 . V_192 , V_192 , FALSE ) ;
F_51 ( V_158 , L_86 ,
L_87 ,
L_87 ,
10 ,
& V_27 . V_94 ) ;
F_51 ( V_158 , L_88 ,
L_89 ,
L_89 ,
10 ,
& V_27 . V_95 ) ;
F_59 ( V_158 , L_90 , L_91 ,
L_92 , ( const char * * ) & V_27 . V_193 ) ;
F_69 ( V_158 , L_93 ) ;
F_51 ( V_158 , L_94 ,
L_95 ,
L_95 ,
10 ,
& V_27 . V_194 ) ;
F_53 ( V_158 , L_96 ,
L_97 ,
L_98 ,
& V_27 . V_195 ) ;
F_53 ( V_158 , L_99 ,
L_100 ,
L_101 ,
& V_27 . V_196 ) ;
F_53 ( V_158 , L_102 ,
L_103 ,
L_104 ,
& V_27 . V_197 ) ;
F_53 ( V_158 , L_105 ,
L_106 ,
L_107 ,
& V_27 . V_198 ) ;
F_53 ( V_158 , L_108 ,
L_109 ,
L_110 ,
& V_27 . V_199 ) ;
F_53 ( V_158 , L_111 ,
L_112 ,
L_113 ,
& V_27 . V_200 ) ;
F_53 ( V_158 , L_114 ,
L_115 ,
L_116 ,
& V_27 . V_201 ) ;
F_69 ( V_158 , L_117 ) ;
F_69 ( V_158 , L_118 ) ;
F_69 ( V_158 , L_119 ) ;
F_69 ( V_158 , L_120 ) ;
F_69 ( V_158 , L_121 ) ;
F_54 ( V_158 , L_122 ,
L_123 ,
L_123 ,
& V_27 . V_202 , V_203 , FALSE ) ;
F_54 ( V_158 , L_124 ,
L_125 ,
L_125 ,
& V_27 . V_204 , V_203 , FALSE ) ;
F_56 ( V_158 , L_126 , L_127 ,
L_128 , ( const char * * ) & V_27 . V_205 ) ;
F_53 ( V_158 , L_129 ,
L_130 ,
L_131 ,
& V_27 . V_206 ) ;
F_54 ( V_158 , L_132 ,
L_133 ,
L_134 ,
( T_14 * ) ( void * ) ( & V_27 . V_207 ) , V_207 , FALSE ) ;
F_51 ( V_158 , L_135 ,
L_136 ,
L_137 ,
10 ,
& V_27 . V_208 ) ;
F_56 ( V_158 , L_138 , L_139 ,
L_140 , ( const char * * ) & V_27 . V_209 ) ;
F_56 ( V_158 , L_141 , L_142 ,
L_142 , ( const char * * ) ( & V_27 . V_210 ) ) ;
F_54 ( V_158 , L_143 ,
L_144 ,
L_144 ,
( T_14 * ) ( void * ) ( & V_27 . V_211 ) , V_212 , FALSE ) ;
F_53 ( V_158 , L_145 ,
L_146 ,
L_146 ,
& V_27 . V_213 ) ;
F_51 ( V_158 , L_147 ,
L_148 ,
L_148 ,
10 ,
& V_27 . V_214 ) ;
F_54 ( V_158 , L_149 ,
L_150 ,
L_150 ,
& V_27 . V_215 , V_215 , FALSE ) ;
V_156 = F_15 ( V_158 , L_151 , L_151 , F_79 ) ;
F_51 ( V_156 , L_152 ,
L_153 ,
L_154 ,
10 ,
( T_4 * ) ( void * ) ( & V_27 . V_96 ) ) ;
F_54 ( V_156 , L_155 ,
L_156 ,
L_156 ,
( T_14 * ) ( void * ) ( & V_27 . V_216 ) , V_217 , FALSE ) ;
F_54 ( V_156 , L_157 ,
L_158 ,
L_158 ,
( T_14 * ) ( void * ) ( & V_27 . V_218 ) , V_217 , FALSE ) ;
F_54 ( V_156 , L_159 ,
L_160 ,
L_160 ,
( T_14 * ) ( void * ) ( & V_27 . V_219 ) , V_217 , FALSE ) ;
F_53 ( V_158 , L_161 ,
L_162 ,
L_163 ,
& V_27 . V_220 ) ;
V_155 = F_12 ( NULL , L_164 , L_165 ,
L_166 , NULL , FALSE ) ;
V_24 . V_25 = F_80 ;
V_24 . V_167 = F_81 ;
V_24 . V_168 = F_82 ;
V_24 . V_169 = F_84 ;
V_24 . V_170 = F_85 ;
V_24 . V_171 = F_87 ;
V_24 . V_172 = F_88 ;
F_52 ( V_155 , L_167 , L_168 ,
L_169 , & V_24 , & V_27 . V_221 ) ;
V_154 = F_12 ( NULL , L_170 , L_171 ,
L_172 , NULL , FALSE ) ;
F_56 ( V_154 , L_173 , L_174 ,
L_174 , ( const char * * ) & V_27 . V_222 ) ;
F_56 ( V_154 , L_175 , L_176 ,
L_177 ,
( const char * * ) & V_27 . V_223 ) ;
F_56 ( V_154 , L_178 , L_179 ,
L_180 ,
( const char * * ) & V_27 . V_224 ) ;
F_56 ( V_154 , L_181 , L_182 ,
L_183 , ( const char * * ) & V_27 . V_225 ) ;
F_56 ( V_154 , L_184 , L_185 ,
L_186 ,
( const char * * ) & V_27 . V_226 ) ;
#if F_140 ( V_227 ) || F_140 ( V_228 )
F_56 ( V_154 , L_187 , L_188 ,
L_189 ,
( ( const char * * ) & V_27 . V_229 ) ) ;
#endif
F_56 ( V_154 , L_190 , L_191 ,
L_192 ,
( const char * * ) & V_27 . V_230 ) ;
F_56 ( V_154 , L_193 , L_194 ,
L_195 ,
( const char * * ) & V_27 . V_231 ) ;
F_53 ( V_154 , L_196 , L_197 ,
L_198 , & V_27 . V_232 ) ;
F_53 ( V_154 , L_199 , L_200 ,
L_201 , & V_27 . V_233 ) ;
F_53 ( V_154 , L_202 , L_203 ,
L_204 , & V_27 . V_234 ) ;
F_53 ( V_154 , L_205 , L_206 ,
L_207 , & V_27 . V_235 ) ;
F_53 ( V_154 , L_208 , L_209 ,
L_210 , & V_27 . V_236 ) ;
F_69 ( V_154 , L_211 ) ;
V_24 . V_25 = F_124 ;
V_24 . V_167 = F_126 ;
V_24 . V_168 = F_127 ;
V_24 . V_169 = F_128 ;
V_24 . V_170 = F_129 ;
V_24 . V_171 = F_130 ;
V_24 . V_172 = F_131 ;
F_67 ( V_154 , L_1 , L_212 ,
L_213 , & V_24 , F_123 , & V_27 . V_141 ) ;
V_237 = F_12 ( NULL , L_214 , L_215 ,
L_215 , NULL , TRUE ) ;
F_141 ( V_237 ) ;
F_142 ( V_237 ) ;
#ifdef F_143
F_144 ( V_237 ) ;
#endif
V_153 = F_12 ( NULL , L_216 , L_217 ,
L_217 , NULL , TRUE ) ;
F_54 ( V_153 , L_218 ,
L_219 , L_220 ,
& V_27 . V_238 , V_239 , TRUE ) ;
F_54 ( V_153 , L_221 ,
L_222 , L_223 ,
& V_27 . V_240 , V_241 , TRUE ) ;
#ifndef V_227
F_56 ( V_153 , L_224 , L_225 ,
L_226 , ( const char * * ) ( & V_27 . V_242 ) ) ;
#endif
F_58 ( V_153 , L_227 , L_228 ,
L_229 , ( const char * * ) ( & V_27 . V_243 ) ) ;
V_49 = F_12 ( NULL , L_230 , L_231 ,
L_231 , & F_76 , TRUE ) ;
F_51 ( V_49 , L_232 ,
L_233 ,
L_234 ,
10 ,
& V_27 . V_86 ) ;
#ifdef F_77
F_51 ( V_49 , L_235 ,
L_236 ,
L_237 ,
10 ,
& V_27 . V_88 ) ;
#endif
F_53 ( V_49 , L_238 ,
L_239 ,
L_240
L_241 ,
& V_27 . V_244 ) ;
F_53 ( V_49 , L_242 ,
L_243 ,
L_244
L_245
L_246 ,
& V_27 . V_245 ) ;
F_51 ( V_49 , L_247 ,
L_248 ,
L_249
L_250 ,
10 , & V_27 . V_90 ) ;
F_51 ( V_49 , L_251 ,
L_252 ,
L_253
L_254
L_255 ,
10 , & V_27 . V_92 ) ;
F_54 ( V_49 , L_256 ,
L_257 ,
L_258
L_259 ,
& V_27 . V_246 , V_247 , FALSE ) ;
F_53 ( V_49 , L_260 ,
L_261 ,
L_262
L_263 ,
& V_27 . V_248 ) ;
F_53 ( V_49 , L_264 ,
L_265 ,
L_266
L_267
L_268 ,
& V_27 . V_249 ) ;
F_53 ( V_49 , L_269 ,
L_270 ,
L_271
L_272
L_273
L_274 ,
& V_27 . V_250 ) ;
F_53 ( V_49 , L_275 ,
L_276 ,
L_271
L_277
L_278
L_279 ,
& V_27 . V_251 ) ;
F_53 ( V_49 , L_280 ,
L_281 ,
L_282
L_283
L_284 ,
& V_27 . V_252 ) ;
V_42 = F_12 ( NULL , L_285 , L_286 ,
L_286 , NULL , TRUE ) ;
F_53 ( V_42 , L_287 ,
L_288 ,
L_289 ,
& V_27 . V_253 ) ;
F_12 ( NULL , L_290 , L_291 , L_291 , NULL , FALSE ) ;
F_12 ( NULL , L_292 , L_293 , L_293 , NULL , FALSE ) ;
F_12 ( NULL , L_294 , L_295 , L_295 , NULL , FALSE ) ;
}
T_17 *
F_113 ( const T_13 * V_254 )
{
enum { V_255 , V_256 , V_257 };
T_14 V_258 = V_255 , V_147 = 0 , V_259 = 0 ;
T_6 V_260 = FALSE ;
T_7 V_261 ;
T_13 * V_262 = NULL ;
T_17 * V_263 = NULL ;
V_262 = ( T_13 * ) F_145 ( sizeof( T_13 ) * V_264 ) ;
V_259 = 0 ;
for (; ; ) {
V_261 = V_254 [ V_147 ] ;
if ( V_261 == '\0' ) {
if ( V_258 == V_256 || V_260 ) {
F_5 ( V_262 ) ;
F_115 ( V_263 ) ;
return NULL ;
}
V_262 [ V_259 ] = '\0' ;
V_263 = F_45 ( V_263 , V_262 ) ;
break;
}
if ( V_261 == '"' && ! V_260 ) {
switch ( V_258 ) {
case V_255 :
V_258 = V_256 ;
break;
case V_256 :
V_258 = V_257 ;
break;
case V_257 :
V_258 = V_256 ;
break;
default:
break;
}
} else if ( V_261 == '\\' && ! V_260 ) {
V_260 = TRUE ;
if ( V_258 == V_255 )
V_258 = V_257 ;
} else if ( V_261 == ',' && V_258 != V_256 && ! V_260 ) {
V_262 [ V_259 ] = '\0' ;
V_263 = F_45 ( V_263 , V_262 ) ;
V_258 = V_255 ;
V_262 = ( T_13 * ) F_145 ( sizeof( T_13 ) * V_264 ) ;
V_259 = 0 ;
} else if ( ! isspace ( V_261 ) || V_258 != V_255 ) {
if ( V_259 < V_264 ) {
V_262 [ V_259 ] = V_261 ;
V_259 ++ ;
}
V_260 = FALSE ;
}
V_147 ++ ;
}
return ( V_263 ) ;
}
static char *
F_122 ( T_17 * V_263 )
{
T_28 * V_265 = F_96 ( L_5 ) ;
T_17 * V_266 , * V_267 ;
T_13 * V_254 ;
T_13 * V_268 ;
T_4 V_269 = 0 ;
V_266 = V_267 = F_74 ( V_263 ) ;
while ( V_266 ) {
V_269 ++ ;
V_254 = ( T_13 * ) V_266 -> V_3 ;
if ( V_266 != V_267 )
F_146 ( V_265 , ',' ) ;
if ( V_269 % 2 ) {
F_98 ( V_265 , L_296 ) ;
} else
F_146 ( V_265 , ' ' ) ;
V_268 = F_147 ( V_254 , L_5 ) ;
F_148 ( V_265 , L_297 , V_268 ) ;
F_5 ( V_268 ) ;
V_266 = V_266 -> V_109 ;
}
return F_99 ( V_265 , FALSE ) ;
}
void
F_115 ( T_17 * V_263 )
{
T_17 * V_270 = V_263 ;
while ( V_270 ) {
F_5 ( V_270 -> V_3 ) ;
V_270 = F_125 ( V_270 , V_270 ) ;
}
}
static T_14
F_149 ( const char * V_271 , const T_18 * V_272 ,
T_14 V_273 )
{
int V_147 ;
for ( V_147 = 0 ; V_272 [ V_147 ] . V_21 != NULL ; V_147 ++ ) {
if ( F_150 ( V_271 , V_272 [ V_147 ] . V_21 ) == 0 ) {
return V_272 [ V_147 ] . V_50 ;
}
}
for ( V_147 = 0 ; V_272 [ V_147 ] . V_21 != NULL ; V_147 ++ ) {
if ( F_150 ( V_271 , V_272 [ V_147 ] . V_32 ) == 0 ) {
return V_272 [ V_147 ] . V_50 ;
}
}
return V_273 ;
}
static T_6
F_116 ( T_27 * V_105 , const char * V_113 )
{
const T_13 * V_274 = F_97 ( V_114 ) ;
T_29 V_275 = strlen ( V_274 ) ;
T_13 * * V_276 ;
char * V_35 ;
int V_277 ;
T_13 * V_278 ;
long V_279 ;
T_6 V_280 ;
if ( ( strlen ( V_113 ) > V_275 ) && ( V_113 [ V_275 ] == ':' ) &&
strncmp ( V_113 , V_274 , V_275 ) == 0 ) {
V_277 = V_114 ;
V_276 = F_151 ( & V_113 [ V_275 + 1 ] , L_298 , 3 ) ;
V_278 = F_28 ( V_276 [ 0 ] ) ;
if ( V_278 && V_276 [ 1 ] ) {
V_279 = strtol ( V_276 [ 1 ] , & V_35 , 10 ) ;
if ( V_35 == V_276 [ 1 ] || * V_35 != '\0' ) {
F_5 ( V_278 ) ;
F_152 ( V_276 ) ;
return FALSE ;
}
} else {
V_279 = 0 ;
}
if ( V_278 && V_276 [ 1 ] && V_276 [ 2 ] ) {
V_280 = ( V_276 [ 2 ] [ 0 ] == 'U' ) ? FALSE : TRUE ;
} else {
V_280 = TRUE ;
}
F_152 ( V_276 ) ;
} else {
V_277 = F_153 ( V_113 ) ;
if ( V_277 == - 1 )
return FALSE ;
V_278 = NULL ;
V_279 = 0 ;
V_280 = TRUE ;
}
V_105 -> V_113 = V_277 ;
V_105 -> V_115 = V_278 ;
V_105 -> V_116 = ( int ) V_279 ;
V_105 -> V_117 = V_280 ;
return TRUE ;
}
static void
F_154 ( void )
{
if ( V_281 )
return;
F_155 () ;
F_22 () ;
F_156 ( TRUE ) ;
V_281 = TRUE ;
}
static void
F_139 ( void )
{
int V_147 ;
T_13 * V_143 ;
T_27 * V_105 ;
static const T_13 * V_277 [ V_282 * 2 ] = {
L_299 , L_300 , L_301 , L_302 ,
L_303 , L_304 , L_305 , L_306 ,
L_307 , L_308 , L_309 , L_310 ,
L_311 , L_312 } ;
if ( V_283 )
return;
V_27 . V_238 = V_284 ;
V_27 . V_240 = V_285 ;
V_27 . V_243 = L_313 ;
V_27 . V_242 = L_314 ;
V_27 . V_161 = FALSE ;
V_27 . V_162 = FALSE ;
V_27 . V_164 = 0 ;
V_27 . V_165 = 1 ;
V_27 . V_166 = 1 ;
V_27 . V_163 = FALSE ;
V_27 . V_202 = V_286 ;
V_27 . V_204 = V_287 ;
#ifdef V_227
V_27 . V_176 = ( char * ) L_315 ;
#else
V_27 . V_176 = ( char * ) L_316 ;
#endif
V_27 . V_177 = ( char * ) L_5 ;
V_27 . V_179 . V_288 = 65535 ;
V_27 . V_179 . V_289 = 65535 ;
V_27 . V_179 . V_290 = 65535 ;
V_27 . V_179 . V_291 = 65535 ;
V_27 . V_180 . V_288 = 0 ;
V_27 . V_180 . V_289 = 0 ;
V_27 . V_180 . V_290 = 8224 ;
V_27 . V_180 . V_291 = 10794 ;
V_27 . V_181 . V_288 = 32767 ;
V_27 . V_181 . V_289 = 32767 ;
V_27 . V_181 . V_290 = 32767 ;
V_27 . V_181 . V_291 = 32767 ;
V_27 . V_182 . V_288 = 65535 ;
V_27 . V_182 . V_289 = 65535 ;
V_27 . V_182 . V_290 = 65535 ;
V_27 . V_182 . V_291 = 65535 ;
V_27 . V_187 = L_317 ;
V_27 . V_188 = L_318 ;
V_27 . V_183 . V_288 = 0 ;
V_27 . V_183 . V_289 = 32767 ;
V_27 . V_183 . V_290 = 0 ;
V_27 . V_183 . V_291 = 0 ;
V_27 . V_184 . V_288 = 0 ;
V_27 . V_184 . V_289 = 64507 ;
V_27 . V_184 . V_290 = 60909 ;
V_27 . V_184 . V_291 = 60909 ;
V_27 . V_185 . V_288 = 0 ;
V_27 . V_185 . V_289 = 0 ;
V_27 . V_185 . V_290 = 0 ;
V_27 . V_185 . V_291 = 32767 ;
V_27 . V_186 . V_288 = 0 ;
V_27 . V_186 . V_289 = 60909 ;
V_27 . V_186 . V_290 = 60909 ;
V_27 . V_186 . V_291 = 64507 ;
V_27 . V_189 . V_288 = 0 ;
V_27 . V_189 . V_289 = 0xAFFF ;
V_27 . V_189 . V_290 = 0xFFFF ;
V_27 . V_189 . V_291 = 0xAFFF ;
V_27 . V_190 . V_288 = 0 ;
V_27 . V_190 . V_289 = 0xFFFF ;
V_27 . V_190 . V_290 = 0xAFFF ;
V_27 . V_190 . V_291 = 0xAFFF ;
V_27 . V_191 . V_288 = 0 ;
V_27 . V_191 . V_289 = 0xFFFF ;
V_27 . V_191 . V_290 = 0xFFFF ;
V_27 . V_191 . V_291 = 0xAFFF ;
V_27 . V_198 = TRUE ;
V_27 . V_199 = TRUE ;
V_27 . V_200 = TRUE ;
V_27 . V_201 = TRUE ;
V_27 . V_159 = V_292 ;
V_27 . V_192 = V_293 ;
V_27 . V_95 = 10 ;
V_27 . V_94 = 10 ;
V_27 . V_193 = ( char * ) F_157 () ;
V_27 . V_194 = 3 ;
V_27 . V_195 = TRUE ;
V_27 . V_196 = TRUE ;
V_27 . V_197 = FALSE ;
V_27 . V_206 = TRUE ;
V_27 . V_207 = V_294 ;
V_27 . V_208 = 60 * 60 * 24 ;
#ifdef F_158
V_27 . V_205 = ( char * ) F_158 L_319 ;
#else
V_27 . V_205 = ( char * ) L_5 ;
#endif
V_27 . V_209 = ( char * ) L_5 ;
V_27 . V_210 = L_320 ;
V_27 . V_211 = V_295 ;
V_27 . V_213 = FALSE ;
V_27 . V_214 = 0 ;
V_27 . V_96 = V_99 ;
V_27 . V_216 = V_296 ;
V_27 . V_218 = V_297 ;
V_27 . V_219 = V_298 ;
V_27 . V_215 = 0 ;
V_27 . V_220 = FALSE ;
V_27 . V_174 = NULL ;
for ( V_147 = 0 ; V_147 < V_282 ; V_147 ++ ) {
V_105 = F_42 ( T_27 , 1 ) ;
V_105 -> V_31 = F_28 ( V_277 [ V_147 * 2 ] ) ;
F_116 ( V_105 , V_277 [ ( V_147 * 2 ) + 1 ] ) ;
V_105 -> V_110 = TRUE ;
V_105 -> V_117 = TRUE ;
V_105 -> V_115 = NULL ;
V_105 -> V_116 = 0 ;
V_27 . V_174 = F_45 ( V_27 . V_174 , V_105 ) ;
}
V_27 . V_175 = V_282 ;
V_27 . V_232 = TRUE ;
#ifdef F_159
V_27 . V_233 = TRUE ;
#else
V_27 . V_233 = FALSE ;
#endif
V_27 . V_234 = TRUE ;
V_27 . V_235 = TRUE ;
V_27 . V_236 = FALSE ;
V_27 . V_141 = NULL ;
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
V_143 = F_28 ( V_149 [ V_147 ] ) ;
V_27 . V_141 = F_45 ( V_27 . V_141 , V_143 ) ;
}
V_27 . V_221 =
V_299 | V_300 | V_301 ;
V_27 . V_86 = V_87 ;
V_27 . V_88 = V_89 ;
V_27 . V_244 = TRUE ;
V_27 . V_245 = FALSE ;
V_27 . V_90 = V_302 ;
V_27 . V_92 = V_303 ;
V_27 . V_249 = TRUE ;
V_27 . V_251 = TRUE ;
V_27 . V_250 = TRUE ;
V_27 . V_246 = V_304 ;
V_27 . V_248 = TRUE ;
V_27 . V_252 = FALSE ;
V_27 . V_253 = FALSE ;
V_283 = TRUE ;
}
static void
F_160 ( T_3 * V_5 )
{
if ( ! V_5 ) return;
switch ( V_5 -> type ) {
case V_9 :
* V_5 -> V_16 . V_66 = V_5 -> V_17 . V_66 ;
break;
case V_7 :
* V_5 -> V_16 . V_69 = V_5 -> V_17 . V_23 ;
break;
case V_8 :
* V_5 -> V_16 . V_72 = V_5 -> V_17 . V_73 ;
break;
case V_13 :
case V_14 :
case V_15 :
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_5 -> V_17 . string ) ;
break;
case V_18 :
F_5 ( * V_5 -> V_16 . V_19 ) ;
* V_5 -> V_16 . V_19 = F_62 ( V_5 -> V_17 . V_19 ) ;
break;
case V_10 :
case V_11 :
break;
case V_12 :
* V_5 -> V_16 . V_80 = V_5 -> V_17 . V_79 ;
break;
case V_20 :
V_5 -> V_24 . V_167 ( V_5 ) ;
break;
case V_6 :
break;
}
}
static void
F_161 ( T_1 V_3 , T_1 T_2 V_4 )
{
T_3 * V_5 = ( T_3 * ) V_3 ;
F_160 ( V_5 ) ;
}
static T_6
F_162 ( void * V_50 , void * V_3 V_4 )
{
T_30 V_61 ;
V_61 . V_26 = ( T_5 * ) V_50 ;
F_7 ( V_61 . V_26 -> V_27 , F_161 , & V_61 ) ;
return FALSE ;
}
void
F_163 ( void )
{
V_281 = FALSE ;
F_5 ( V_27 . V_305 ) ;
V_27 . V_305 = NULL ;
F_164 () ;
F_165 () ;
F_154 () ;
F_35 ( V_1 , F_162 , NULL ) ;
}
T_31 *
F_166 ( int * V_306 , int * V_307 ,
char * * V_308 , int * V_309 ,
int * V_310 , char * * V_311 )
{
int V_312 ;
char * V_313 ;
T_32 * V_314 ;
F_165 () ;
F_154 () ;
if ( V_315 == NULL ) {
V_315 = F_167 ( V_316 ) ;
if ( ( V_314 = F_168 ( V_315 , L_321 ) ) == NULL && V_317 == V_318 ) {
F_5 ( V_315 ) ;
V_315 = F_167 ( V_319 ) ;
V_314 = F_168 ( V_315 , L_321 ) ;
}
} else {
V_314 = F_168 ( V_315 , L_321 ) ;
}
* V_308 = NULL ;
if ( V_314 != NULL ) {
V_320 = 0 ;
V_321 = 0 ;
V_312 = F_169 ( V_315 , V_314 , V_322 , NULL ) ;
if ( V_312 != 0 ) {
* V_306 = 0 ;
* V_307 = V_312 ;
* V_308 = V_315 ;
}
fclose ( V_314 ) ;
} else {
if ( V_317 != V_318 ) {
* V_306 = V_317 ;
* V_307 = 0 ;
* V_308 = V_315 ;
}
}
V_313 = F_170 ( V_316 , TRUE ) ;
* V_311 = NULL ;
if ( ( V_314 = F_168 ( V_313 , L_321 ) ) != NULL ) {
V_320 = 0 ;
V_321 = 0 ;
V_312 = F_169 ( V_313 , V_314 , V_322 , NULL ) ;
if ( V_312 != 0 ) {
* V_309 = 0 ;
* V_310 = V_312 ;
* V_311 = V_313 ;
} else
F_5 ( V_313 ) ;
fclose ( V_314 ) ;
} else {
if ( V_317 != V_318 ) {
* V_309 = V_317 ;
* V_310 = 0 ;
* V_311 = V_313 ;
} else
F_5 ( V_313 ) ;
}
F_171 () ;
return & V_27 ;
}
int
F_169 ( const char * V_313 , T_32 * V_314 ,
T_33 V_323 , void * V_324 )
{
enum { V_325 , V_326 , V_327 , V_328 , V_329 };
int V_330 , V_258 = V_325 ;
T_28 * V_331 ;
T_28 * V_332 ;
T_6 V_333 = FALSE ;
T_14 V_334 = 1 , V_335 = 1 ;
T_13 V_336 [] = L_322 ;
T_13 V_337 [ 128 ] ;
V_331 = F_96 ( L_5 ) ;
V_332 = F_96 ( L_5 ) ;
if ( fscanf ( V_314 , L_323 , V_337 ) == 1 ) {
V_27 . V_305 = F_172 ( V_337 , strlen ( V_337 ) - 1 ) ;
}
rewind ( V_314 ) ;
while ( ( V_330 = getc ( V_314 ) ) != V_338 ) {
if ( V_330 == '\r' ) {
V_330 = getc ( V_314 ) ;
if ( V_330 == V_338 )
break;
if ( V_330 != '\n' ) {
ungetc ( V_330 , V_314 ) ;
V_330 = '\r' ;
}
}
if ( V_330 == '\n' ) {
V_258 = V_325 ;
V_334 ++ ;
continue;
}
switch ( V_258 ) {
case V_325 :
if ( isalnum ( V_330 ) ) {
if ( V_332 -> V_118 > 0 ) {
if ( V_333 ) {
if ( V_331 -> V_118 > 0 ) {
if ( V_331 -> V_254 [ V_331 -> V_118 - 1 ] == ',' ) {
V_331 -> V_254 [ V_331 -> V_118 - 1 ] = '\0' ;
F_173 ( L_324 , V_313 , V_335 , V_332 -> V_254 , V_336 ) ;
}
}
switch ( V_323 ( V_332 -> V_254 , V_331 -> V_254 , V_324 , FALSE ) ) {
case V_83 :
break;
case V_130 :
F_173 ( L_325 ,
V_332 -> V_254 , V_335 , V_313 , V_336 ) ;
break;
case V_84 :
if ( strcmp ( V_332 -> V_254 , L_326 ) != 0 )
F_173 ( L_327 ,
V_332 -> V_254 , V_335 , V_313 , V_336 ) ;
V_27 . V_339 = TRUE ;
break;
case V_340 :
if ( strcmp ( V_332 -> V_254 , L_326 ) != 0 )
F_173 ( L_328 ,
V_332 -> V_254 , V_335 , V_313 , V_336 ) ;
V_27 . V_339 = TRUE ;
break;
}
} else {
F_173 ( L_329 , V_335 , V_313 , V_336 ) ;
}
}
V_258 = V_326 ;
V_333 = FALSE ;
F_174 ( V_332 , 0 ) ;
F_146 ( V_332 , ( T_13 ) V_330 ) ;
V_335 = V_334 ;
} else if ( isspace ( V_330 ) && V_332 -> V_118 > 0 && V_333 ) {
V_258 = V_327 ;
} else if ( V_330 == '#' ) {
V_258 = V_329 ;
} else {
F_173 ( L_330 , V_334 , V_313 , V_336 ) ;
}
break;
case V_326 :
if ( V_330 != ':' ) {
F_146 ( V_332 , ( T_13 ) V_330 ) ;
} else {
V_258 = V_327 ;
F_174 ( V_331 , 0 ) ;
V_333 = TRUE ;
}
break;
case V_327 :
if ( ! isspace ( V_330 ) ) {
V_258 = V_328 ;
F_146 ( V_331 , ( T_13 ) V_330 ) ;
}
break;
case V_328 :
F_146 ( V_331 , ( T_13 ) V_330 ) ;
break;
}
}
if ( V_332 -> V_118 > 0 ) {
if ( V_333 ) {
switch ( V_323 ( V_332 -> V_254 , V_331 -> V_254 , V_324 , FALSE ) ) {
case V_83 :
break;
case V_130 :
F_173 ( L_331 ,
V_332 -> V_254 , V_335 , V_313 , V_336 ) ;
break;
case V_84 :
F_173 ( L_327 ,
V_332 -> V_254 , V_335 , V_313 , V_336 ) ;
V_27 . V_339 = TRUE ;
break;
case V_340 :
V_27 . V_339 = TRUE ;
break;
}
} else {
F_173 ( L_332 ,
V_335 , V_313 , V_336 ) ;
}
}
F_99 ( V_331 , TRUE ) ;
F_99 ( V_332 , TRUE ) ;
if ( ferror ( V_314 ) )
return V_317 ;
else
return 0 ;
}
static T_6
F_175 ( char * V_341 ) {
T_13 * V_35 , * V_342 ;
T_21 * V_77 ;
T_13 * V_312 ;
V_342 = strchr ( V_341 , ':' ) ;
if ( V_342 == NULL )
return FALSE ;
V_35 = V_342 ;
* V_35 ++ = '\0' ;
while ( isspace ( ( T_7 ) * V_35 ) )
V_35 ++ ;
if ( * V_35 == '\0' ) {
* V_342 = ':' ;
return FALSE ;
}
V_77 = F_176 ( V_341 ) ;
* V_342 = ':' ;
if ( V_77 == NULL ) {
return FALSE ;
}
if ( F_177 ( V_77 , V_35 , & V_312 ) ) {
return TRUE ;
}
return FALSE ;
}
T_25
F_178 ( char * V_343 )
{
T_13 * V_35 , * V_342 ;
T_25 V_52 ;
V_320 = - 1 ;
V_321 = - 1 ;
V_342 = strchr ( V_343 , ':' ) ;
if ( V_342 == NULL )
return V_130 ;
V_35 = V_342 ;
* V_35 ++ = '\0' ;
while ( isspace ( ( T_7 ) * V_35 ) )
V_35 ++ ;
if ( * V_35 == '\0' ) {
* V_342 = ':' ;
return V_130 ;
}
if ( strcmp ( V_343 , L_333 ) ) {
V_52 = V_322 ( V_343 , V_35 , NULL , TRUE ) ;
} else {
V_52 = F_175 ( V_35 ) ? V_83 : V_130 ;
}
* V_342 = ':' ;
return V_52 ;
}
T_6
F_179 ( const char * V_21 )
{
T_13 * V_344 , * V_345 ;
T_29 V_118 ;
if ( V_27 . V_225 && V_21 ) {
V_345 = F_28 ( V_27 . V_225 ) ;
V_118 = strlen ( V_21 ) ;
for ( V_344 = strtok ( V_345 , L_21 ) ; V_344 ; V_344 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_344 ) == V_118 && strcmp ( V_21 , V_344 ) == 0 ) {
F_5 ( V_345 ) ;
return TRUE ;
}
}
F_5 ( V_345 ) ;
}
return FALSE ;
}
static T_6
F_92 ( const T_13 * V_111 , T_27 * V_105 )
{
T_13 * V_344 , * V_346 ;
T_27 V_347 ;
if ( V_111 ) {
V_346 = F_28 ( V_111 ) ;
for ( V_344 = strtok ( V_346 , L_21 ) ; V_344 ; V_344 = strtok ( NULL , L_21 ) ) {
V_344 = F_180 ( V_344 ) ;
if ( ! F_116 ( & V_347 , V_344 ) ) {
continue;
}
if ( V_105 -> V_113 != V_347 . V_113 ) {
F_5 ( V_347 . V_115 ) ;
V_347 . V_115 = NULL ;
continue;
}
if ( V_105 -> V_113 == V_114 ) {
if ( V_347 . V_115 && V_105 -> V_115 ) {
if ( strcmp ( V_105 -> V_115 ,
V_347 . V_115 ) != 0 ) {
F_5 ( V_347 . V_115 ) ;
V_347 . V_115 = NULL ;
continue;
}
if ( V_105 -> V_116 != V_347 . V_116 ) {
F_5 ( V_347 . V_115 ) ;
V_347 . V_115 = NULL ;
continue;
}
}
}
F_5 ( V_347 . V_115 ) ;
F_5 ( V_346 ) ;
return FALSE ;
}
F_5 ( V_346 ) ;
}
return TRUE ;
}
T_6
F_181 ( const char * V_21 )
{
T_13 * V_344 , * V_345 ;
T_29 V_118 ;
if ( V_27 . V_226 && V_21 ) {
V_345 = F_28 ( V_27 . V_226 ) ;
V_118 = strlen ( V_21 ) ;
for ( V_344 = strtok ( V_345 , L_21 ) ; V_344 ; V_344 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_344 ) == V_118 && strcmp ( V_21 , V_344 ) == 0 ) {
F_5 ( V_345 ) ;
return TRUE ;
}
}
F_5 ( V_345 ) ;
}
return FALSE ;
}
T_6
F_182 ( const T_13 * V_348 )
{
T_17 * V_349 ;
T_13 * V_144 ;
for ( V_349 = F_74 ( V_27 . V_141 ) ; V_349 ; V_349 = F_75 ( V_349 ) ) {
V_144 = ( T_13 * ) V_349 -> V_3 ;
if ( V_144 && ( F_150 ( V_144 , V_348 ) == 0 ) ) {
return TRUE ;
}
}
return FALSE ;
}
char
F_183 ( const char * string , T_34 * V_350 )
{
char V_36 ;
memset ( V_350 , 0 , sizeof( T_34 ) ) ;
while ( ( V_36 = * string ++ ) != '\0' ) {
switch ( V_36 ) {
case 'm' :
V_350 -> V_351 = TRUE ;
break;
case 'n' :
V_350 -> V_352 = TRUE ;
break;
case 'N' :
V_350 -> V_353 = TRUE ;
break;
case 't' :
V_350 -> V_354 = TRUE ;
break;
case 'C' :
V_350 -> V_355 = TRUE ;
break;
default:
return V_36 ;
}
}
return '\0' ;
}
static void
F_117 ( T_1 * V_356 )
{
struct {
T_14 V_357 ;
const T_13 * V_358 ;
} V_359 [] = {
{ V_360 , L_334 } ,
{ V_361 , L_335 } ,
{ V_362 , L_336 } ,
{ V_363 , L_337 } ,
{ V_364 , L_338 } ,
{ V_365 , L_339 } ,
{ V_366 , L_340 } ,
{ V_367 , L_341 } ,
{ V_368 , L_342 } ,
{ V_369 , L_343 } ,
{ V_370 , L_344 } ,
{ V_371 , L_345 } ,
{ V_372 , L_346 }
} ;
T_4 V_373 ;
const T_13 * V_374 ;
T_13 * * V_113 = ( T_13 * * ) V_356 ;
for ( V_373 = 0 ;
V_373 < F_184 ( V_359 ) ;
++ V_373 ) {
V_374 = F_97 ( V_359 [ V_373 ] . V_357 ) ;
if ( strcmp ( V_374 , * V_113 ) == 0 ) {
T_13 * V_375 = F_86 ( L_347 ,
V_359 [ V_373 ] . V_358 ) ;
F_5 ( * V_113 ) ;
* V_113 = V_375 ;
}
}
}
static T_25
V_322 ( T_13 * V_376 , const T_13 * V_50 , void * V_324 V_4 ,
T_6 V_377 )
{
unsigned long int V_378 ;
T_4 V_101 ;
T_6 V_379 ;
T_14 V_380 ;
char * V_35 ;
T_13 * V_381 , * V_382 ;
static T_13 * V_383 = NULL ;
static T_6 V_384 = FALSE ;
T_13 * V_385 = NULL ;
T_5 * V_26 ;
T_3 * V_5 ;
if ( strcmp ( V_376 , V_386 ) == 0 ) {
V_383 = F_28 ( V_50 ) ;
} else if ( strcmp ( V_376 , V_387 ) == 0 ) {
V_384 = ( strcmp ( V_50 , L_348 ) == 0 ) ? TRUE : FALSE ;
} else if ( strcmp ( V_376 , V_388 ) == 0 ) {
V_385 = F_28 ( V_50 ) ;
F_185 ( V_383 , V_385 , V_384 ) ;
F_5 ( V_383 ) ;
F_5 ( V_385 ) ;
} else if ( strcmp ( V_376 , L_349 ) == 0 ) {
if ( F_150 ( V_50 , L_350 ) == 0 ) {
V_27 . V_211 = V_295 ;
} else {
V_27 . V_211 = V_389 ;
}
} else if ( strcmp ( V_376 , L_351 ) == 0 ||
strcmp ( V_376 , L_352 ) == 0 ) {
if ( F_150 ( V_50 , L_350 ) == 0 ) {
V_390 . V_351 = TRUE ;
V_390 . V_352 = TRUE ;
V_390 . V_354 = TRUE ;
V_390 . V_355 = TRUE ;
}
else if ( F_150 ( V_50 , L_353 ) == 0 ) {
V_390 . V_351 = FALSE ;
V_390 . V_352 = FALSE ;
V_390 . V_354 = FALSE ;
V_390 . V_355 = FALSE ;
}
else {
V_390 . V_351 = FALSE ;
V_390 . V_352 = FALSE ;
V_390 . V_354 = FALSE ;
V_390 . V_355 = FALSE ;
if ( F_183 ( V_50 , & V_390 ) != '\0' )
return V_130 ;
}
} else {
if ( ( strcmp ( V_376 , L_354 ) == 0 ) ||
( strcmp ( V_376 , L_355 ) == 0 ) ||
( strcmp ( V_376 , L_356 ) == 0 ) ) {
V_26 = V_237 ;
V_381 = V_376 ;
} else {
V_26 = NULL ;
V_382 = V_376 ;
while ( ! V_26 ) {
V_381 = strchr ( V_382 , '.' ) ;
if ( V_381 == NULL ) {
return V_84 ;
}
* V_381 = '\0' ;
V_26 = F_17 ( V_376 ) ;
if ( V_26 == NULL ) {
if ( strcmp ( V_376 , L_357 ) == 0 )
V_26 = V_107 ;
else if ( strcmp ( V_376 , L_358 ) == 0 )
V_26 = F_17 ( L_359 ) ;
else if ( strcmp ( V_376 , L_360 ) == 0 )
V_26 = F_17 ( L_361 ) ;
else if ( strcmp ( V_376 , L_362 ) == 0 ||
strcmp ( V_376 , L_363 ) == 0 )
V_26 = F_17 ( L_364 ) ;
else if ( strcmp ( V_376 , L_365 ) == 0 )
V_26 = F_17 ( L_366 ) ;
else if ( strcmp ( V_376 , L_367 ) == 0 )
V_26 = F_17 ( L_368 ) ;
else if ( strcmp ( V_376 , L_369 ) == 0 )
V_26 = F_17 ( L_370 ) ;
else if ( strcmp ( V_376 , L_371 ) == 0 )
V_26 = F_17 ( L_372 ) ;
else if ( strcmp ( V_376 , L_373 ) == 0 )
V_26 = F_17 ( L_374 ) ;
else if ( strcmp ( V_376 , L_375 ) == 0 )
V_26 = F_17 ( L_376 ) ;
else if ( strcmp ( V_376 , L_377 ) == 0 ||
strcmp ( V_376 , L_378 ) == 0 ) {
return V_340 ;
}
if ( V_26 ) {
F_173 ( L_379
L_380 ,
V_376 , V_381 + 1 , V_26 -> V_30 -> V_21 , V_376 , V_381 + 1 ) ;
V_27 . V_339 = TRUE ;
}
}
* V_381 = '.' ;
V_381 ++ ;
V_382 = V_381 ;
}
}
V_5 = F_44 ( V_26 , V_381 ) ;
if ( V_5 == NULL ) {
V_27 . V_339 = TRUE ;
if ( ( strcmp ( V_376 , V_132 ) == 0 ) ||
( strcmp ( V_376 , V_108 ) == 0 ) ) {
V_5 = F_44 ( V_26 , V_376 ) ;
}
else if ( strcmp ( V_26 -> V_21 , L_381 ) == 0 ) {
if ( strcmp ( V_381 , L_382 ) == 0 )
V_5 = F_44 ( V_26 , L_383 ) ;
else if ( strcmp ( V_381 , L_384 ) == 0 )
V_5 = F_44 ( V_26 , L_385 ) ;
else if ( strcmp ( V_381 , L_386 ) == 0 ) {
V_320 ++ ;
if ( V_320 == 1 ) {
V_5 = F_44 ( V_26 , L_387 ) ;
} else if ( V_320 == 2 ) {
V_5 = F_44 ( V_26 , L_388 ) ;
}
} else if ( strcmp ( V_381 , L_389 ) == 0 ) {
V_321 ++ ;
if ( V_321 == 1 ) {
V_5 = F_44 ( V_26 , L_390 ) ;
} else if ( V_321 == 2 ) {
V_5 = F_44 ( V_26 , L_391 ) ;
}
}
} else if ( strcmp ( V_26 -> V_21 , L_392 ) == 0 ) {
if ( strcmp ( V_381 , L_393 ) == 0 )
V_5 = F_44 ( V_26 , L_394 ) ;
else if ( strcmp ( V_381 , L_395 ) == 0 )
V_5 = F_44 ( V_26 , L_396 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_397 ) == 0 ) {
if ( strcmp ( V_381 , L_398 ) == 0 )
V_5 = F_44 ( V_26 , L_399 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_359 ) == 0 ) {
if ( strcmp ( V_381 , L_400 ) == 0 )
V_5 = F_44 ( V_26 , L_399 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_401 ) == 0 ) {
if ( strcmp ( V_381 , L_402 ) == 0 )
V_5 = F_44 ( V_26 , L_403 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_404 ) == 0 ) {
if ( strcmp ( V_381 , L_405 ) == 0 )
V_5 = F_44 ( V_26 , L_403 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_406 ) == 0 ) {
if ( strcmp ( V_381 , L_407 ) == 0 )
V_5 = F_44 ( V_26 , L_408 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_409 ) == 0 ) {
if ( strcmp ( V_381 , L_410 ) == 0 )
V_5 = F_44 ( V_26 , L_411 ) ;
else if ( strcmp ( V_381 , L_412 ) == 0 )
V_5 = F_44 ( V_26 , L_413 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_414 ) == 0 ) {
if ( strcmp ( V_381 , L_415 ) == 0 )
V_5 = F_44 ( V_26 , L_399 ) ;
else if ( strcmp ( V_381 , L_416 ) == 0 )
V_5 = F_44 ( V_26 , L_417 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_364 ) == 0 ) {
if ( strcmp ( V_381 , L_418 ) == 0 )
V_5 = F_44 ( V_26 , L_419 ) ;
else if ( strcmp ( V_381 , L_420 ) == 0 )
V_5 = F_44 ( V_26 , L_421 ) ;
else if ( strcmp ( V_381 , L_422 ) == 0 )
V_5 = F_44 ( V_26 , L_423 ) ;
else if ( strcmp ( V_381 , L_424 ) == 0 )
V_5 = F_44 ( V_26 , L_425 ) ;
else if ( strcmp ( V_381 , L_426 ) == 0 )
V_5 = F_44 ( V_26 , L_427 ) ;
else if ( strcmp ( V_381 , L_428 ) == 0 )
V_5 = F_44 ( V_26 , L_429 ) ;
else if ( strcmp ( V_381 , L_430 ) == 0 )
V_5 = F_44 ( V_26 , L_431 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_432 ) == 0 ) {
if ( strcmp ( V_381 , L_433 ) == 0 )
V_5 = F_44 ( V_26 , L_434 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_435 ) == 0 ) {
if ( strcmp ( V_381 , L_436 ) == 0 )
V_5 = F_44 ( V_26 , L_417 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_437 ) == 0 ) {
if ( strcmp ( V_381 , L_438 ) == 0 )
V_5 = F_44 ( V_26 , L_439 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_440 ) == 0 ) {
if ( strcmp ( V_381 , L_441 ) == 0 )
V_5 = F_44 ( V_26 , L_442 ) ;
else if ( strcmp ( V_381 , L_443 ) == 0 )
V_5 = F_44 ( V_26 , L_444 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_445 ) == 0 ) {
if ( strcmp ( V_381 , L_446 ) == 0 )
V_5 = F_44 ( V_26 , L_447 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_448 ) == 0 ) {
if ( strcmp ( V_381 , L_449 ) == 0 )
V_5 = F_44 ( V_26 , L_450 ) ;
else if ( strcmp ( V_381 , L_451 ) == 0 )
V_5 = F_44 ( V_26 , L_452 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_453 ) == 0 ) {
if ( strcmp ( V_381 , L_454 ) == 0 )
V_5 = F_44 ( V_26 , L_455 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_456 ) == 0 ) {
if ( strcmp ( V_381 , L_457 ) == 0 )
V_5 = F_44 ( V_26 , L_434 ) ;
else if ( strcmp ( V_381 , L_458 ) == 0 )
V_5 = F_44 ( V_26 , L_459 ) ;
else if ( strcmp ( V_381 , L_460 ) == 0 )
V_5 = F_44 ( V_26 , L_461 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_462 ) == 0 ) {
if ( strcmp ( V_381 , L_463 ) == 0 )
V_5 = F_44 ( V_26 , L_434 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_464 ) == 0 ) {
if ( strcmp ( V_381 , L_465 ) == 0 )
V_5 = F_44 ( V_26 , L_466 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_467 ) == 0 ) {
if ( strcmp ( V_381 , L_468 ) == 0 )
V_5 = F_44 ( V_26 , L_469 ) ;
else if ( strcmp ( V_381 , L_470 ) == 0 )
V_5 = F_44 ( V_26 , L_471 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_472 ) == 0 ) {
T_5 * V_45 = F_17 ( L_366 ) ;
if ( V_45 ) {
if ( strcmp ( V_381 , L_473 ) == 0 )
V_5 = F_44 ( V_45 , L_473 ) ;
else if ( strcmp ( V_381 , L_474 ) == 0 )
V_5 = F_44 ( V_45 , L_474 ) ;
}
} else if ( strcmp ( V_26 -> V_21 , L_475 ) == 0 ) {
if ( strcmp ( V_381 , L_476 ) == 0 )
V_5 = F_44 ( V_26 , L_477 ) ;
else if ( strcmp ( V_381 , L_403 ) == 0 )
V_5 = F_44 ( V_26 , L_478 ) ;
else if ( strcmp ( V_381 , L_479 ) == 0 )
V_5 = F_44 ( V_26 , L_480 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_481 ) == 0 ) {
if ( strcmp ( V_381 , L_482 ) == 0 )
V_5 = F_44 ( V_26 , L_483 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_484 ) == 0 ) {
if ( strcmp ( V_381 , L_485 ) == 0 ) {
V_5 = F_44 ( V_26 , L_486 ) ;
if ( strcmp ( V_50 , L_486 ) == 0 || strcmp ( V_50 , L_487 ) == 0 )
V_50 = L_348 ;
else if ( strcmp ( V_50 , L_488 ) == 0 || strcmp ( V_50 , L_489 ) == 0 )
V_50 = L_490 ;
else if ( strcmp ( V_50 , L_491 ) == 0 || strcmp ( V_50 , L_492 ) == 0 )
V_50 = L_348 ;
} else if ( strcmp ( V_381 , L_493 ) == 0 ) {
V_5 = F_44 ( V_26 , L_494 ) ;
if ( strcmp ( V_50 , L_495 ) == 0 || strcmp ( V_50 , L_496 ) == 0 )
V_50 = L_497 ;
else if ( strcmp ( V_50 , L_498 ) == 0 || strcmp ( V_50 , L_499 ) == 0 )
V_50 = L_498 ;
else if ( strcmp ( V_50 , L_491 ) == 0 || strcmp ( V_50 , L_492 ) == 0 )
V_50 = L_497 ;
} else if ( strcmp ( V_381 , L_500 ) == 0 ) {
V_5 = F_44 ( V_26 , L_501 ) ;
if ( strcmp ( V_50 , L_502 ) == 0 || strcmp ( V_50 , L_503 ) == 0 )
V_50 = L_502 ;
else if ( strcmp ( V_50 , L_448 ) == 0 || strcmp ( V_50 , L_504 ) == 0 )
V_50 = L_448 ;
else if ( strcmp ( V_50 , L_505 ) == 0 || strcmp ( V_50 , L_506 ) == 0 )
V_50 = L_507 ;
else if ( strcmp ( V_50 , L_508 ) == 0 || strcmp ( V_50 , L_509 ) == 0 )
V_50 = L_508 ;
else if ( strcmp ( V_50 , L_491 ) == 0 || strcmp ( V_50 , L_492 ) == 0 )
V_50 = L_497 ;
}
} else if ( strcmp ( V_26 -> V_21 , L_488 ) == 0 ) {
if ( strcmp ( V_381 , L_510 ) == 0 ) {
T_5 * V_45 = F_17 ( L_511 ) ;
if ( V_45 ) {
V_5 = F_44 ( V_45 , L_510 ) ;
V_26 = V_45 ;
}
}
} else if ( strcmp ( V_26 -> V_21 , L_290 ) == 0 ) {
if ( strcmp ( V_381 , L_232 ) == 0 ||
strcmp ( V_381 , L_235 ) == 0 )
V_5 = F_44 ( V_49 , V_381 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_292 ) == 0 ) {
if ( strcmp ( V_381 , L_287 ) == 0 )
V_5 = F_44 ( V_42 , V_381 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_294 ) == 0 ) {
if ( ( strcmp ( V_381 , L_512 ) == 0 ) ||
( strcmp ( V_381 , L_513 ) == 0 ) ||
( strcmp ( V_381 , L_514 ) == 0 ) ||
( strcmp ( V_381 , L_515 ) == 0 ) )
V_5 = F_44 ( V_178 , V_376 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_214 ) == 0 ) {
if ( strcmp ( V_376 , L_354 ) == 0 ) {
V_5 = F_44 ( V_237 , V_376 ) ;
} else if ( strcmp ( V_376 , L_355 ) == 0 ) {
V_5 = F_44 ( V_237 , L_516 ) ;
} else if ( strcmp ( V_376 , L_356 ) == 0 ) {
V_5 = F_44 ( V_237 , L_517 ) ;
}
}
}
if ( V_5 == NULL )
return V_84 ;
switch ( V_5 -> type ) {
case V_9 :
V_101 = ( T_4 ) strtoul ( V_50 , & V_35 , V_5 -> V_67 . V_64 ) ;
if ( V_35 == V_50 || * V_35 != '\0' )
return V_130 ;
if ( * V_5 -> V_16 . V_66 != V_101 ) {
V_26 -> V_38 = TRUE ;
* V_5 -> V_16 . V_66 = V_101 ;
}
break;
case V_7 :
if ( F_150 ( V_50 , L_350 ) == 0 )
V_379 = TRUE ;
else
V_379 = FALSE ;
if ( * V_5 -> V_16 . V_69 != V_379 ) {
V_26 -> V_38 = TRUE ;
* V_5 -> V_16 . V_69 = V_379 ;
}
break;
case V_8 :
V_380 = F_149 ( V_50 , V_5 -> V_67 . V_74 . V_70 ,
* V_5 -> V_16 . V_72 ) ;
if ( * V_5 -> V_16 . V_72 != V_380 ) {
V_26 -> V_38 = TRUE ;
* V_5 -> V_16 . V_72 = V_380 ;
}
break;
case V_13 :
case V_14 :
case V_15 :
if ( strcmp ( * V_5 -> V_16 . string , V_50 ) != 0 ) {
V_26 -> V_38 = TRUE ;
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_50 ) ;
}
break;
case V_18 :
{
T_19 * V_391 ;
if ( F_186 ( & V_391 , V_50 , V_5 -> V_67 . V_76 ,
V_377 ) != V_392 ) {
return V_130 ;
}
if ( ! F_187 ( * V_5 -> V_16 . V_19 , V_391 ) ) {
V_26 -> V_38 = TRUE ;
F_5 ( * V_5 -> V_16 . V_19 ) ;
* V_5 -> V_16 . V_19 = V_391 ;
} else {
F_5 ( V_391 ) ;
}
break;
}
case V_12 :
{
V_378 = strtoul ( V_50 , NULL , 16 ) ;
V_5 -> V_16 . V_80 -> V_288 = 0 ;
if ( ( V_5 -> V_16 . V_80 -> V_289 != F_188 ( V_378 ) ) ||
( V_5 -> V_16 . V_80 -> V_290 != F_189 ( V_378 ) ) ||
( V_5 -> V_16 . V_80 -> V_291 != F_190 ( V_378 ) ) ) {
V_26 -> V_38 = TRUE ;
V_5 -> V_16 . V_80 -> V_289 = F_188 ( V_378 ) ;
V_5 -> V_16 . V_80 -> V_290 = F_189 ( V_378 ) ;
V_5 -> V_16 . V_80 -> V_291 = F_190 ( V_378 ) ;
}
break;
}
case V_20 :
return V_5 -> V_24 . V_168 ( V_5 , V_50 , & V_26 -> V_38 ) ;
case V_10 :
case V_11 :
{
break;
}
case V_6 :
return V_340 ;
}
}
return V_83 ;
}
const char *
F_191 ( T_3 * V_5 )
{
const char * V_393 = L_518 ;
if ( ! V_5 ) {
return V_393 ;
}
switch ( V_5 -> type ) {
case V_9 :
switch ( V_5 -> V_67 . V_64 ) {
case 10 :
V_393 = L_519 ;
break;
case 8 :
V_393 = L_520 ;
break;
case 16 :
V_393 = L_521 ;
break;
}
break;
case V_7 :
V_393 = L_522 ;
break;
case V_8 :
V_393 = L_523 ;
break;
case V_13 :
V_393 = L_524 ;
break;
case V_14 :
V_393 = L_525 ;
break;
case V_15 :
V_393 = L_526 ;
break;
case V_18 :
V_393 = L_527 ;
break;
case V_12 :
V_393 = L_528 ;
break;
case V_20 :
if ( V_5 -> V_24 . V_169 )
return V_5 -> V_24 . V_169 () ;
V_393 = L_529 ;
break;
case V_6 :
V_393 = L_530 ;
break;
case V_10 :
V_393 = L_531 ;
break;
case V_11 :
V_393 = L_532 ;
break;
}
return V_393 ;
}
char *
F_192 ( T_3 * V_5 )
{
const char * V_394 = L_533 ;
if ( ! V_5 ) {
return F_86 ( L_534 , V_394 ) ;
}
switch ( V_5 -> type ) {
case V_9 :
switch ( V_5 -> V_67 . V_64 ) {
case 10 :
V_394 = L_535 ;
break;
case 8 :
V_394 = L_536 ;
break;
case 16 :
V_394 = L_537 ;
break;
}
break;
case V_7 :
V_394 = L_538 ;
break;
case V_8 :
{
const T_18 * V_395 = V_5 -> V_67 . V_74 . V_70 ;
T_28 * V_396 = F_96 ( L_539 ) ;
while ( V_395 -> V_21 != NULL ) {
F_98 ( V_396 , V_395 -> V_32 ) ;
V_395 ++ ;
if ( V_395 -> V_21 != NULL )
F_98 ( V_396 , L_540 ) ;
}
F_98 ( V_396 , L_541 ) ;
return F_99 ( V_396 , FALSE ) ;
break;
}
case V_13 :
V_394 = L_542 ;
break;
case V_14 :
V_394 = L_543 ;
break;
case V_15 :
V_394 = L_544 ;
break;
case V_18 :
{
V_394 = L_545 ;
break;
}
case V_12 :
{
V_394 = L_546 ;
break;
}
case V_20 :
if ( V_5 -> V_24 . V_170 )
return V_5 -> V_24 . V_170 () ;
V_394 = L_547 ;
break;
case V_6 :
V_394 = L_548 ;
break;
case V_10 :
V_394 = L_549 ;
break;
case V_11 :
V_394 = L_550 ;
break;
default:
break;
}
return F_28 ( V_394 ) ;
}
static T_6
F_193 ( T_3 * V_5 ) {
if ( ! V_5 ) return FALSE ;
switch ( V_5 -> type ) {
case V_9 :
if ( V_5 -> V_17 . V_66 == * V_5 -> V_16 . V_66 )
return TRUE ;
break;
case V_7 :
if ( V_5 -> V_17 . V_23 == * V_5 -> V_16 . V_69 )
return TRUE ;
break;
case V_8 :
if ( V_5 -> V_17 . V_73 == * V_5 -> V_16 . V_72 )
return TRUE ;
break;
case V_13 :
case V_14 :
case V_15 :
if ( ! ( F_101 ( V_5 -> V_17 . string , * V_5 -> V_16 . string ) ) )
return TRUE ;
break;
case V_18 :
{
if ( ( F_187 ( V_5 -> V_17 . V_19 , * V_5 -> V_16 . V_19 ) ) )
return TRUE ;
break;
}
case V_12 :
{
if ( ( V_5 -> V_17 . V_79 . V_289 == V_5 -> V_16 . V_80 -> V_289 ) &&
( V_5 -> V_17 . V_79 . V_290 == V_5 -> V_16 . V_80 -> V_290 ) &&
( V_5 -> V_17 . V_79 . V_291 == V_5 -> V_16 . V_80 -> V_291 ) )
return TRUE ;
break;
}
case V_20 :
return V_5 -> V_24 . V_171 ( V_5 ) ;
case V_6 :
case V_10 :
case V_11 :
return FALSE ;
break;
}
return FALSE ;
}
char *
F_194 ( T_3 * V_5 , T_35 V_397 ) {
const char * V_398 = L_518 ;
void * V_399 ;
T_22 * V_400 ;
if ( ! V_5 ) {
return F_28 ( V_398 ) ;
}
switch ( V_397 ) {
case V_401 :
V_399 = & V_5 -> V_17 ;
V_400 = & V_5 -> V_17 . V_79 ;
break;
case V_402 :
V_399 = & V_5 -> V_22 ;
V_400 = & V_5 -> V_22 . V_79 ;
break;
case V_403 :
V_399 = V_5 -> V_16 . V_66 ;
V_400 = V_5 -> V_16 . V_80 ;
break;
default:
return F_28 ( V_398 ) ;
}
switch ( V_5 -> type ) {
case V_9 :
{
T_4 V_404 = * ( T_4 * ) V_399 ;
switch ( V_5 -> V_67 . V_64 ) {
case 10 :
return F_86 ( L_17 , V_404 ) ;
case 8 :
return F_86 ( L_551 , V_404 ) ;
case 16 :
return F_86 ( L_552 , V_404 ) ;
}
break;
}
case V_7 :
return F_86 ( L_304 , ( * ( T_6 * ) V_399 ) ? L_348 : L_490 ) ;
case V_8 :
{
T_14 V_405 = * ( T_14 * ) V_399 ;
const T_18 * V_395 = V_5 -> V_67 . V_74 . V_70 ;
while ( V_395 -> V_21 != NULL ) {
if ( V_395 -> V_50 == V_405 )
return F_28 ( V_395 -> V_32 ) ;
V_395 ++ ;
}
break;
}
case V_13 :
case V_14 :
case V_15 :
return F_28 ( * ( const char * * ) V_399 ) ;
case V_18 :
V_398 = F_195 ( * ( T_19 * * ) V_399 ) ;
break;
case V_12 :
return F_86 ( L_553 ,
( V_400 -> V_289 * 255 / 65535 ) ,
( V_400 -> V_290 * 255 / 65535 ) ,
( V_400 -> V_291 * 255 / 65535 ) ) ;
case V_20 :
if ( V_5 -> V_24 . V_172 )
return V_5 -> V_24 . V_172 ( V_5 , V_397 == V_401 ? TRUE : FALSE ) ;
V_398 = L_554 ;
break;
case V_6 :
V_398 = L_555 ;
break;
case V_10 :
V_398 = L_549 ;
break;
case V_11 :
{
T_21 * V_77 = V_5 -> V_16 . V_77 ;
if ( V_77 && V_77 -> V_406 )
return F_86 ( L_556 , V_77 -> V_406 ) ;
else
V_398 = L_557 ;
break;
}
default:
break;
}
return F_28 ( V_398 ) ;
}
static void
F_196 ( T_1 V_3 , T_1 T_2 )
{
T_3 * V_5 = ( T_3 * ) V_3 ;
T_36 * V_61 = ( T_36 * ) T_2 ;
T_13 * * V_407 ;
int V_147 ;
switch ( V_5 -> type ) {
case V_6 :
return;
case V_10 :
case V_11 :
return;
default:
break;
}
if ( V_5 -> type != V_20 || V_5 -> V_24 . V_169 () != NULL ) {
const char * V_408 = ( V_61 -> V_26 -> V_21 != NULL ) ? V_61 -> V_26 -> V_21 : V_61 -> V_26 -> V_30 -> V_21 ;
char * V_394 , * V_398 ;
const char * V_409 = F_193 ( V_5 ) ? L_558 : L_5 ;
if ( V_5 -> type == V_20 ) fprintf ( V_61 -> V_314 , L_559 , V_5 -> V_24 . V_169 () ) ;
fprintf ( V_61 -> V_314 , L_560 ) ;
if ( V_5 -> V_32 &&
( F_197 ( V_5 -> V_32 , L_5 , 2 ) != 0 ) ) {
if ( V_5 -> type != V_20 ) {
V_407 = F_151 ( V_5 -> V_32 , L_560 , 0 ) ;
for ( V_147 = 0 ; V_407 [ V_147 ] != NULL ; ++ V_147 ) {
fprintf ( V_61 -> V_314 , L_561 , V_407 [ V_147 ] ) ;
}
F_152 ( V_407 ) ;
}
} else {
fprintf ( V_61 -> V_314 , L_562 ) ;
}
V_394 = F_192 ( V_5 ) ;
V_407 = F_151 ( V_394 , L_560 , 0 ) ;
for ( V_147 = 0 ; V_407 [ V_147 ] != NULL ; ++ V_147 ) {
fprintf ( V_61 -> V_314 , L_561 , V_407 [ V_147 ] ) ;
}
F_152 ( V_407 ) ;
F_5 ( V_394 ) ;
V_398 = F_194 ( V_5 , V_403 ) ;
fprintf ( V_61 -> V_314 , L_563 , V_409 , V_408 , V_5 -> V_21 ) ;
V_407 = F_151 ( V_398 , L_560 , 0 ) ;
for ( V_147 = 0 ; V_407 [ V_147 ] != NULL ; ++ V_147 ) {
fprintf ( V_61 -> V_314 , L_564 , V_147 == 0 ? L_5 : V_409 , V_407 [ V_147 ] ) ;
}
if ( V_147 == 0 ) fprintf ( V_61 -> V_314 , L_560 ) ;
F_152 ( V_407 ) ;
F_5 ( V_398 ) ;
}
}
static T_4
F_198 ( T_5 * V_26 , T_1 T_2 )
{
T_37 * V_410 = ( T_37 * ) T_2 ;
T_36 V_61 ;
if ( ( V_26 == V_158 ) && ( V_410 -> V_411 != TRUE ) )
return 0 ;
if ( ( ( V_26 -> V_30 == NULL ) || ( V_26 -> V_30 == V_158 ) ) &&
( ( F_36 ( V_26 ) ) ||
( V_26 -> V_28 > 0 ) ||
( V_26 -> V_21 == NULL ) ) ) {
if ( ( V_26 -> V_21 == NULL ) && ( V_26 -> V_30 != NULL ) ) {
fprintf ( V_410 -> V_314 , L_565 , V_26 -> V_30 -> V_31 , V_26 -> V_31 ) ;
} else {
fprintf ( V_410 -> V_314 , L_566 , V_26 -> V_31 ) ;
}
}
V_61 . V_26 = V_26 ;
V_61 . V_314 = V_410 -> V_314 ;
F_7 ( V_61 . V_26 -> V_27 , F_196 , & V_61 ) ;
if ( F_36 ( V_26 ) )
return F_9 ( V_26 , F_198 , T_2 ) ;
return 0 ;
}
int
F_199 ( char * * V_311 )
{
char * V_313 ;
T_32 * V_314 ;
T_37 V_412 ;
F_154 () ;
if ( V_311 != NULL ) {
V_313 = F_170 ( V_316 , TRUE ) ;
if ( ( V_314 = F_168 ( V_313 , L_567 ) ) == NULL ) {
* V_311 = V_313 ;
return V_317 ;
}
} else {
V_314 = stdout ;
}
fputs ( L_568 V_413 L_569
L_570
L_571
L_572
L_573
L_574 , V_314 ) ;
V_412 . V_314 = V_314 ;
V_412 . V_411 = TRUE ;
F_198 ( V_158 , & V_412 ) ;
{
struct V_414 * V_415 = * (struct V_414 * * ) V_27 . V_416 ;
if ( V_415 != NULL )
fprintf ( V_314 , L_575 ) ;
while ( V_415 != NULL ) {
if ( V_415 -> V_417 == FALSE ) {
fprintf ( V_314 , L_576 , V_386 , V_415 -> V_418 ) ;
fprintf ( V_314 , L_576 , V_387 ,
V_415 -> V_419 == TRUE ? L_348 : L_490 ) ;
fprintf ( V_314 , L_576 , V_388 , V_415 -> V_420 ) ;
}
V_415 = V_415 -> V_109 ;
}
}
V_412 . V_411 = FALSE ;
F_9 ( NULL , F_198 , & V_412 ) ;
fclose ( V_314 ) ;
return 0 ;
}
static void
F_110 ( T_17 * V_82 )
{
T_27 * V_105 ;
while ( V_82 != NULL ) {
V_105 = ( T_27 * ) V_82 -> V_3 ;
F_5 ( V_105 -> V_31 ) ;
F_5 ( V_105 -> V_115 ) ;
F_5 ( V_105 ) ;
V_82 = F_125 ( V_82 , V_82 ) ;
}
F_8 ( V_82 ) ;
V_82 = NULL ;
}
