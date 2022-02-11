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
if ( V_31 != NULL )
V_55 -> V_56 = V_26 -> V_28 ;
else
V_55 -> V_56 = - 1 ;
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
F_46 ( T_15 V_57 , T_15 V_58 )
{
const T_3 * V_5 = ( const T_3 * ) V_57 ;
const char * V_21 = ( const char * ) V_58 ;
return strcmp ( V_21 , V_5 -> V_21 ) ;
}
static T_6 F_47 ( void * V_50 , void * V_3 )
{
T_16 * V_59 = ( T_16 * ) V_3 ;
T_17 * V_60 ;
T_5 * V_26 = ( T_5 * ) V_50 ;
if ( V_26 == NULL )
return FALSE ;
V_60 = F_48 ( V_26 -> V_27 , V_59 -> V_21 ,
F_46 ) ;
if ( V_60 == NULL )
return FALSE ;
V_59 -> V_60 = V_60 ;
return TRUE ;
}
struct V_55 *
F_44 ( T_5 * V_26 , const char * V_21 )
{
T_16 V_59 ;
T_17 * V_60 ;
if ( V_26 == NULL )
return NULL ;
V_60 = F_48 ( V_26 -> V_27 , V_21 ,
F_46 ) ;
if ( V_60 == NULL )
{
V_59 . V_60 = NULL ;
if ( V_26 -> V_29 != NULL )
{
V_59 . V_21 = V_21 ;
F_35 ( V_26 -> V_29 , F_47 , & V_59 ) ;
}
V_60 = V_59 . V_60 ;
}
if ( V_60 == NULL )
return NULL ;
return (struct V_55 * ) V_60 -> V_3 ;
}
T_6
F_49 ( const char * V_21 )
{
T_5 * V_61 = F_17 ( V_21 ) ;
return ( V_61 != NULL && ! V_61 -> V_39 ) ;
}
const char *
F_50 ( const char * V_21 )
{
T_5 * V_61 = F_17 ( V_21 ) ;
return ( V_61 != NULL && ! V_61 -> V_39 ) ? V_61 -> V_31 : NULL ;
}
void
F_51 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_4 V_62 , T_4 * V_63 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_9 ) ;
V_55 -> V_16 . V_64 = V_63 ;
V_55 -> V_17 . V_64 = * V_63 ;
F_20 ( V_62 > 0 && V_62 != 1 && V_62 < 37 ) ;
V_55 -> V_65 . V_62 = V_62 ;
}
static void
F_52 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
struct V_66 * V_24 , T_4 * V_63 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_20 ) ;
V_55 -> V_24 = * V_24 ;
V_55 -> V_16 . V_64 = V_63 ;
V_55 -> V_17 . V_64 = * V_63 ;
}
void
F_53 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_6 * V_63 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_7 ) ;
V_55 -> V_16 . V_67 = V_63 ;
V_55 -> V_17 . V_23 = * V_63 ;
}
void
F_54 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_14 * V_63 , const T_18 * V_68 ,
T_6 V_69 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_8 ) ;
V_55 -> V_16 . V_70 = V_63 ;
V_55 -> V_17 . V_71 = * V_63 ;
V_55 -> V_65 . V_72 . V_68 = V_68 ;
V_55 -> V_65 . V_72 . V_69 = V_69 ;
}
static T_3 *
F_55 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_63 , T_12 type )
{
T_3 * V_55 ;
char * V_73 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
type ) ;
if ( * V_63 == NULL ) {
* V_63 = F_28 ( L_5 ) ;
V_73 = F_28 ( L_5 ) ;
} else {
* V_63 = F_28 ( * V_63 ) ;
V_73 = F_28 ( * V_63 ) ;
}
V_55 -> V_16 . string = V_63 ;
V_55 -> V_17 . string = V_73 ;
V_55 -> V_22 . string = NULL ;
return V_55 ;
}
void
F_56 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_63 )
{
F_55 ( V_26 , V_21 , V_31 , V_32 , V_63 ,
V_13 ) ;
}
static
void F_57 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
struct V_66 * V_24 , const char * * V_63 )
{
T_3 * V_55 ;
V_55 = F_55 ( V_26 , V_21 , V_31 , V_32 , V_63 ,
V_20 ) ;
V_55 -> V_24 = * V_24 ;
}
void
F_58 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_63 )
{
F_55 ( V_26 , V_21 , V_31 , V_32 , V_63 ,
V_14 ) ;
}
void
F_59 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
const char * * V_63 )
{
F_55 ( V_26 , V_21 , V_31 , V_32 , V_63 ,
V_15 ) ;
}
void
F_60 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 ,
T_19 * * V_63 , T_20 V_74 )
{
T_3 * V_55 ;
V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 ,
V_18 ) ;
V_55 -> V_65 . V_74 = V_74 ;
if ( * V_63 == NULL )
* V_63 = F_61 () ;
V_55 -> V_16 . V_19 = V_63 ;
V_55 -> V_17 . V_19 = F_62 ( * V_63 ) ;
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
T_21 * V_75 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_11 ) ;
V_55 -> V_16 . V_75 = V_75 ;
}
void F_65 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 , T_22 * V_76 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_12 ) ;
V_55 -> V_16 . V_77 = V_76 ;
V_55 -> V_17 . V_76 = * V_76 ;
}
static
void F_66 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 , struct V_66 * V_24 ,
T_23 V_78 , T_17 * * V_79 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_20 ) ;
V_55 -> V_24 = * V_24 ;
V_78 ( V_55 , V_79 ) ;
}
void F_67 ( T_5 * V_26 , const char * V_21 ,
const char * V_31 , const char * V_32 , struct V_66 * V_24 ,
void * * T_24 V_4 )
{
T_3 * V_55 = F_41 ( V_26 , V_21 , V_31 , V_32 , V_20 ) ;
V_55 -> V_24 = * V_24 ;
}
void
F_68 ( T_5 * V_26 , const char * V_21 )
{
F_41 ( V_26 , V_21 , NULL , NULL , V_6 ) ;
}
extern T_6
F_69 ( T_3 * V_5 )
{
if ( V_5 )
return V_5 -> type == V_6 ? TRUE : FALSE ;
return TRUE ;
}
extern T_25
F_70 ( T_3 * V_5 )
{
if ( V_5 ) {
V_5 -> type = V_6 ;
return V_80 ;
}
return V_81 ;
}
T_4 F_71 ( T_3 * V_5 )
{
if ( V_5 && V_5 -> type == V_9 )
return * V_5 -> V_16 . V_64 ;
return 0 ;
}
T_4
F_72 ( T_5 * V_26 , T_26 V_53 , T_1 T_2 )
{
T_17 * V_82 ;
T_3 * V_5 ;
T_4 V_52 ;
for ( V_82 = F_73 ( V_26 -> V_27 ) ; V_82 != NULL ; V_82 = F_74 ( V_82 ) ) {
V_5 = ( T_3 * ) V_82 -> V_3 ;
if ( V_5 -> type == V_6 ) {
continue;
}
V_52 = (* V_53)( V_5 , T_2 ) ;
if ( V_52 != 0 )
return V_52 ;
}
return 0 ;
}
static void F_75 ( void )
{
if ( V_27 . V_83 < 100 || V_27 . V_83 > 10000 )
V_27 . V_83 = V_84 ;
#ifdef F_76
if ( V_27 . V_85 < 1 || V_27 . V_85 > 10 )
V_27 . V_85 = V_86 ;
#endif
}
static void F_77 ( void )
{
if ( V_27 . V_87 == 0 )
V_27 . V_87 = 10 ;
if ( V_27 . V_88 == 0 )
V_27 . V_88 = 10 ;
}
static void F_78 ( void )
{
if ( V_27 . V_89 == V_90 ||
V_27 . V_89 >= V_91 ) {
V_27 . V_89 = V_92 ;
}
}
static void F_79 ( T_3 * V_5 V_4 ) {}
static void F_80 ( T_3 * V_5 )
{
* V_5 -> V_16 . V_64 = V_5 -> V_17 . V_64 ;
}
static T_25 F_81 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_93 )
{
T_4 V_94 ;
V_94 = ( T_4 ) strtoul ( V_50 , NULL , 10 ) ;
if ( * V_5 -> V_16 . V_64 != V_94 ) {
* V_93 = TRUE ;
* V_5 -> V_16 . V_64 = V_94 ;
}
if ( * V_5 -> V_16 . V_64 & ( V_95 | V_96 ) ) {
F_82 ( L_6 , L_7 , TRUE ) ;
}
return V_80 ;
}
static const char * F_83 ( void ) {
return L_8 ;
}
static char * F_84 ( void ) {
return F_85 (
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ) ;
}
static T_6 F_86 ( T_3 * V_5 ) {
return * V_5 -> V_16 . V_64 == V_5 -> V_17 . V_64 ;
}
static char * F_87 ( T_3 * V_5 , T_6 V_17 ) {
return F_85 ( L_17 , V_17 ? V_5 -> V_17 . V_64 : * V_5 -> V_16 . V_64 ) ;
}
static void F_88 ( T_3 * V_5 )
{
F_5 ( ( char * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = NULL ;
F_5 ( V_5 -> V_17 . string ) ;
V_5 -> V_17 . string = NULL ;
}
static void F_89 ( T_3 * V_5 )
{
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_5 -> V_17 . string ) ;
}
static T_25 F_90 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_93 )
{
T_17 * V_97 ;
T_27 * V_98 ;
T_3 * V_99 ;
if ( * V_5 -> V_16 . string ) {
if ( strcmp ( * V_5 -> V_16 . string , V_50 ) != 0 ) {
* V_93 = TRUE ;
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_50 ) ;
}
} else if ( V_50 ) {
* V_5 -> V_16 . string = F_28 ( V_50 ) ;
}
V_99 = F_44 ( V_100 , V_101 ) ;
for ( V_97 = * V_99 -> V_16 . V_79 ; V_97 != NULL ; V_97 = V_97 -> V_102 ) {
V_98 = ( T_27 * ) V_97 -> V_3 ;
V_98 -> V_103 = F_91 ( * V_5 -> V_16 . string , V_98 ) ;
}
return V_80 ;
}
static const char * F_92 ( void ) {
return L_18 ;
}
static char * F_93 ( void ) {
return F_28 ( L_19 ) ;
}
static char * F_94 ( T_3 * V_5 , T_6 V_17 ) {
T_28 * V_104 = F_95 ( L_5 ) ;
T_17 * V_97 ;
T_27 * V_98 ;
T_3 * V_99 ;
if ( V_17 )
return F_28 ( V_5 -> V_17 . string ) ;
V_99 = F_44 ( V_100 , V_101 ) ;
V_97 = ( V_99 ) ? * V_99 -> V_16 . V_79 : NULL ;
while ( V_97 ) {
T_13 * V_105 ;
V_98 = ( T_27 * ) V_97 -> V_3 ;
if ( ( V_98 -> V_106 == V_107 ) && ( V_98 -> V_108 ) ) {
V_105 = F_85 ( L_20 ,
F_96 ( V_98 -> V_106 ) ,
V_98 -> V_108 ,
V_98 -> V_109 ,
V_98 -> V_110 ? 'R' : 'U' ) ;
} else {
V_105 = F_28 ( F_96 ( V_98 -> V_106 ) ) ;
}
if ( ! V_98 -> V_103 ) {
if ( V_104 -> V_111 )
F_97 ( V_104 , L_21 ) ;
F_97 ( V_104 , V_105 ) ;
}
V_97 = V_97 -> V_102 ;
}
return F_98 ( V_104 , FALSE ) ;
}
static T_6 F_99 ( T_3 * V_5 ) {
char * V_112 = F_94 ( V_5 , FALSE ) ;
T_6 V_113 = F_100 ( V_112 , V_5 -> V_17 . string ) == 0 ;
F_5 ( V_112 ) ;
return V_113 ;
}
static void F_101 ( T_3 * V_5 )
{
* V_5 -> V_16 . V_64 = V_5 -> V_17 . V_64 ;
}
static T_25 F_102 ( T_3 * V_5 V_4 , const T_13 * V_50 V_4 , T_6 * V_93 V_4 )
{
return V_80 ;
}
static const char * F_103 ( void ) {
return NULL ;
}
static char * F_104 ( void ) {
return F_28 ( L_5 ) ;
}
static T_6 F_105 ( T_3 * V_5 V_4 ) {
return TRUE ;
}
static char * F_106 ( T_3 * V_5 V_4 , T_6 V_17 V_4 ) {
return F_28 ( L_5 ) ;
}
static void F_107 ( T_3 * V_5 , T_17 * * V_50 )
{
T_27 * V_114 , * V_115 ;
T_17 * V_116 ;
V_5 -> V_16 . V_79 = V_50 ;
V_5 -> V_17 . V_79 = NULL ;
for ( V_116 = * V_5 -> V_16 . V_79 ; V_116 != NULL ; V_116 = F_74 ( V_116 ) ) {
V_114 = ( T_27 * ) V_116 -> V_3 ;
V_115 = F_42 ( T_27 , 1 ) ;
V_115 -> V_31 = F_28 ( V_114 -> V_31 ) ;
V_115 -> V_106 = V_114 -> V_106 ;
if ( V_114 -> V_108 ) {
V_115 -> V_108 = F_28 ( V_114 -> V_108 ) ;
V_115 -> V_109 = V_114 -> V_109 ;
} else {
V_115 -> V_108 = NULL ;
V_115 -> V_109 = 0 ;
}
V_115 -> V_103 = V_114 -> V_103 ;
V_115 -> V_110 = V_114 -> V_110 ;
V_5 -> V_17 . V_79 = F_45 ( V_5 -> V_17 . V_79 , V_115 ) ;
}
}
static void F_108 ( T_3 * V_5 )
{
F_109 ( * V_5 -> V_16 . V_79 ) ;
F_109 ( V_5 -> V_17 . V_79 ) ;
}
static void F_110 ( T_3 * V_5 )
{
T_27 * V_114 , * V_115 ;
T_17 * V_116 ;
T_3 * V_117 ;
F_109 ( * V_5 -> V_16 . V_79 ) ;
* V_5 -> V_16 . V_79 = NULL ;
for ( V_116 = V_5 -> V_17 . V_79 ; V_116 != NULL ; V_116 = F_74 ( V_116 ) ) {
V_114 = ( T_27 * ) V_116 -> V_3 ;
V_115 = F_42 ( T_27 , 1 ) ;
V_115 -> V_31 = F_28 ( V_114 -> V_31 ) ;
V_115 -> V_106 = V_114 -> V_106 ;
if ( V_114 -> V_108 ) {
V_115 -> V_108 = F_28 ( V_114 -> V_108 ) ;
V_115 -> V_109 = V_114 -> V_109 ;
} else {
V_115 -> V_108 = NULL ;
V_115 -> V_109 = 0 ;
}
V_115 -> V_103 = V_114 -> V_103 ;
V_115 -> V_110 = V_114 -> V_110 ;
* V_5 -> V_16 . V_79 = F_45 ( * V_5 -> V_16 . V_79 , V_115 ) ;
}
V_117 = F_44 ( V_100 , V_118 ) ;
F_101 ( V_117 ) ;
}
static T_25 F_111 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_93 V_4 )
{
T_17 * V_119 , * V_120 ;
T_27 * V_98 ;
T_14 V_121 ;
T_3 * V_122 , * V_117 ;
V_119 = F_112 ( V_50 ) ;
if ( V_119 == NULL )
return V_123 ;
if ( ( F_113 ( V_119 ) % 2 ) != 0 ) {
F_114 ( V_119 ) ;
return V_123 ;
}
V_120 = F_73 ( V_119 ) ;
while ( V_120 ) {
T_27 V_124 ;
V_120 = V_120 -> V_102 ;
if ( ! F_115 ( & V_124 , ( char * ) V_120 -> V_3 ) ) {
F_114 ( V_119 ) ;
return V_123 ;
}
if ( V_124 . V_106 != V_107 ) {
F_116 ( & V_120 -> V_3 ) ;
} else {
F_5 ( V_124 . V_108 ) ;
}
V_120 = V_120 -> V_102 ;
}
F_109 ( * V_5 -> V_16 . V_79 ) ;
* V_5 -> V_16 . V_79 = NULL ;
V_122 = F_44 ( V_100 , V_125 ) ;
V_117 = F_44 ( V_100 , V_118 ) ;
V_121 = F_113 ( V_119 ) ;
* V_117 -> V_16 . V_64 = V_121 / 2 ;
V_120 = F_73 ( V_119 ) ;
while ( V_120 ) {
V_98 = F_42 ( T_27 , 1 ) ;
V_98 -> V_31 = F_28 ( ( T_13 * ) V_120 -> V_3 ) ;
V_120 = V_120 -> V_102 ;
F_115 ( V_98 , ( char * ) V_120 -> V_3 ) ;
V_98 -> V_103 = F_91 ( ( T_13 * ) ( * V_122 -> V_16 . string ) , V_98 ) ;
V_120 = V_120 -> V_102 ;
* V_5 -> V_16 . V_79 = F_45 ( * V_5 -> V_16 . V_79 , V_98 ) ;
}
F_114 ( V_119 ) ;
F_88 ( V_122 ) ;
return V_80 ;
}
static const char * F_117 ( void ) {
return L_22 ;
}
static char * F_118 ( void ) {
return F_28 ( L_23 ) ;
}
static T_6 F_119 ( T_3 * V_5 ) {
T_17 * V_97 = * V_5 -> V_16 . V_79 ,
* V_126 = F_73 ( V_97 ) ,
* V_127 = F_73 ( V_5 -> V_17 . V_79 ) ;
T_27 * V_98 , * V_128 ;
T_6 V_113 = TRUE ;
T_3 * V_117 ;
V_117 = F_44 ( V_100 , V_118 ) ;
if ( V_117 && * V_117 -> V_16 . V_64 != V_117 -> V_17 . V_64 ) {
V_113 = FALSE ;
} else {
while ( V_126 && V_127 ) {
V_98 = ( T_27 * ) V_126 -> V_3 ;
V_128 = ( T_27 * ) V_127 -> V_3 ;
if ( ( F_100 ( V_98 -> V_31 , V_128 -> V_31 ) != 0 ) ||
( V_98 -> V_106 != V_128 -> V_106 ) ||
( ( ( V_98 -> V_106 == V_107 ) && ( V_98 -> V_108 ) ) &&
( ( F_100 ( V_98 -> V_108 , V_128 -> V_108 ) != 0 ) ||
( V_98 -> V_110 != V_128 -> V_110 ) ) ) ) {
V_113 = FALSE ;
break;
}
V_126 = V_126 -> V_102 ;
V_127 = V_127 -> V_102 ;
}
}
return V_113 ;
}
static char * F_120 ( T_3 * V_5 , T_6 V_17 ) {
T_17 * V_129 = V_17 ? V_5 -> V_17 . V_79 : * V_5 -> V_16 . V_79 ;
T_17 * V_97 = F_73 ( V_129 ) ;
T_17 * V_119 ;
T_27 * V_98 ;
T_13 * V_105 ;
char * V_130 ;
V_119 = NULL ;
while ( V_97 ) {
V_98 = ( T_27 * ) V_97 -> V_3 ;
V_119 = F_45 ( V_119 , F_28 ( V_98 -> V_31 ) ) ;
if ( ( V_98 -> V_106 == V_107 ) && ( V_98 -> V_108 ) ) {
V_105 = F_85 ( L_20 ,
F_96 ( V_98 -> V_106 ) ,
V_98 -> V_108 ,
V_98 -> V_109 ,
V_98 -> V_110 ? 'R' : 'U' ) ;
} else {
V_105 = F_28 ( F_96 ( V_98 -> V_106 ) ) ;
}
V_119 = F_45 ( V_119 , V_105 ) ;
V_97 = V_97 -> V_102 ;
}
V_130 = F_121 ( V_119 ) ;
F_8 ( V_119 ) ;
return V_130 ;
}
static void F_122 ( T_3 * V_5 , T_17 * * V_131 )
{
T_17 * V_132 = * V_131 ,
* V_133 = NULL ;
while ( V_132 ) {
V_133 = F_45 ( V_133 , F_28 ( ( T_13 * ) V_132 -> V_3 ) ) ;
V_132 = V_132 -> V_102 ;
}
V_5 -> V_17 . V_79 = V_133 ;
V_5 -> V_16 . V_79 = & V_27 . V_134 ;
V_5 -> V_22 . V_23 = FALSE ;
}
static void F_123 ( T_3 * V_5 )
{
T_17 * V_135 = V_27 . V_134 ;
T_13 * V_136 ;
while ( V_135 ) {
V_136 = ( T_13 * ) V_135 -> V_3 ;
F_5 ( V_136 ) ;
V_135 = F_124 ( V_135 , V_135 ) ;
}
F_8 ( V_135 ) ;
V_27 . V_134 = NULL ;
if ( V_5 -> V_22 . V_23 == TRUE ) {
T_17 * V_133 ;
T_13 * V_137 ;
V_133 = V_5 -> V_17 . V_79 ;
while ( V_133 != NULL ) {
V_137 = ( T_13 * ) V_133 -> V_3 ;
F_5 ( V_137 ) ;
V_133 = F_124 ( V_133 , V_133 ) ;
}
F_8 ( V_133 ) ;
V_133 = NULL ;
}
}
static void F_125 ( T_3 * V_5 )
{
T_17 * V_138 , * V_133 ;
T_13 * V_139 ;
V_138 = * V_5 -> V_16 . V_79 ;
while ( V_138 != NULL ) {
V_139 = ( T_13 * ) V_138 -> V_3 ;
F_5 ( V_139 ) ;
V_138 = F_124 ( V_138 , V_138 ) ;
}
F_8 ( V_138 ) ;
V_138 = NULL ;
for ( V_133 = V_5 -> V_17 . V_79 ; V_133 != NULL ; V_133 = F_74 ( V_133 ) ) {
V_138 = F_45 ( V_138 , F_28 ( ( T_13 * ) V_133 -> V_3 ) ) ;
}
* V_5 -> V_16 . V_79 = V_138 ;
}
static T_25 F_126 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_93 V_4 )
{
T_17 * V_119 = F_112 ( V_50 ) ;
T_17 * V_120 ;
T_13 * V_136 ;
int V_140 ;
if ( V_119 == NULL )
return V_123 ;
F_123 ( V_5 ) ;
V_120 = F_73 ( V_119 ) ;
if ( ! ( * ( T_13 * ) V_120 -> V_3 ) ) {
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
V_136 = F_28 ( V_142 [ V_140 ] ) ;
V_27 . V_134 = F_45 ( V_27 . V_134 , V_136 ) ;
}
}
while ( V_120 ) {
T_6 V_143 = FALSE ;
V_136 = ( T_13 * ) V_120 -> V_3 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
if ( strcmp ( V_136 , V_142 [ V_140 ] ) == 0 ) {
V_143 = TRUE ;
break;
}
}
if ( ! V_143 ) {
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
V_136 = F_28 ( V_142 [ V_140 ] ) ;
V_27 . V_134 = F_45 ( V_27 . V_134 , V_136 ) ;
}
V_5 -> V_16 . V_79 = & V_27 . V_134 ;
return V_123 ;
}
V_120 = V_120 -> V_102 ;
}
V_120 = F_73 ( V_119 ) ;
while ( V_120 ) {
V_136 = ( T_13 * ) V_120 -> V_3 ;
V_27 . V_134 = F_45 ( V_27 . V_134 , V_136 ) ;
V_120 = V_120 -> V_102 ;
}
V_5 -> V_16 . V_79 = & V_27 . V_134 ;
return V_80 ;
}
static const char * F_127 ( void ) {
return L_24 ;
}
static char * F_128 ( void ) {
return F_28 (
L_25
V_144 ) ;
}
static T_6 F_129 ( T_3 * V_5 ) {
T_17 * V_126 = F_73 ( V_27 . V_134 ) ,
* V_127 = F_73 ( V_5 -> V_17 . V_79 ) ;
T_6 V_113 = TRUE ;
while ( V_126 && V_127 ) {
if ( strcmp ( ( T_13 * ) V_126 -> V_3 , ( T_13 * ) V_127 -> V_3 ) != 0 ) {
V_113 = FALSE ;
break;
}
V_126 = V_126 -> V_102 ;
V_127 = V_127 -> V_102 ;
}
if ( ( ( V_126 == NULL ) && ( V_127 != NULL ) ) ||
( ( V_126 != NULL ) && ( V_127 == NULL ) ) )
V_113 = FALSE ;
return V_113 ;
}
static char * F_130 ( T_3 * V_5 , T_6 V_17 ) {
T_17 * V_129 = V_17 ? V_5 -> V_17 . V_79 : V_27 . V_134 ;
T_17 * V_97 = F_73 ( V_129 ) ;
T_17 * V_119 = NULL ;
T_13 * V_137 , * V_145 ;
while ( V_97 ) {
V_137 = ( T_13 * ) V_97 -> V_3 ;
V_119 = F_45 ( V_119 , F_28 ( V_137 ) ) ;
V_97 = V_97 -> V_102 ;
}
V_145 = F_121 ( V_119 ) ;
F_8 ( V_119 ) ;
return V_145 ;
}
static void F_131 ( T_3 * V_5 )
{
F_5 ( ( char * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = NULL ;
F_5 ( V_5 -> V_17 . string ) ;
V_5 -> V_17 . string = NULL ;
}
static void F_132 ( T_3 * V_5 )
{
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_5 -> V_17 . string ) ;
}
static T_25 F_133 ( T_3 * V_5 , const T_13 * V_50 , T_6 * V_93 )
{
if ( strcmp ( * V_5 -> V_16 . string , V_50 ) != 0 ) {
* V_93 = TRUE ;
F_5 ( ( void * ) * V_5 -> V_16 . string ) ;
* V_5 -> V_16 . string = F_28 ( V_50 ) ;
}
return V_80 ;
}
static const char * F_134 ( void ) {
return NULL ;
}
static char * F_135 ( void ) {
return F_28 ( L_5 ) ;
}
static T_6 F_136 ( T_3 * V_5 V_4 ) {
return TRUE ;
}
static char * F_137 ( T_3 * V_5 V_4 , T_6 V_17 V_4 ) {
return F_28 ( L_5 ) ;
}
void
F_22 ( void )
{
T_5 * V_146 , * V_147 , * V_148 ,
* V_149 , * V_150 ;
struct V_66 V_24 ;
if ( V_42 != NULL ) {
return;
}
F_138 () ;
V_151 = F_12 ( NULL , L_26 , L_27 ,
L_27 , & F_77 , FALSE ) ;
F_54 ( V_151 , L_28 ,
L_29 ,
L_30 ,
( T_14 * ) ( void * ) ( & V_27 . V_152 ) , V_153 , FALSE ) ;
F_68 ( V_151 , L_31 ) ;
F_68 ( V_151 , L_32 ) ;
F_68 ( V_151 , L_33 ) ;
F_53 ( V_151 , L_34 ,
L_35 ,
L_36 ,
& V_27 . V_154 ) ;
F_53 ( V_151 , L_37 ,
L_38 ,
L_39 ,
& V_27 . V_155 ) ;
F_53 ( V_151 , L_40 ,
L_41 ,
L_42 ,
& V_27 . V_156 ) ;
F_54 ( V_151 , L_43 ,
L_44 ,
L_44 ,
& V_27 . V_157 , V_157 , FALSE ) ;
F_54 ( V_151 , L_45 ,
L_46 ,
L_46 ,
& V_27 . V_158 , V_158 , FALSE ) ;
F_54 ( V_151 , L_47 ,
L_48 ,
L_48 ,
& V_27 . V_159 , V_159 , FALSE ) ;
V_100 = F_15 ( V_151 , L_49 , L_49 , NULL ) ;
V_24 . V_25 = F_88 ;
V_24 . V_160 = F_89 ;
V_24 . V_161 = F_90 ;
V_24 . V_162 = F_92 ;
V_24 . V_163 = F_93 ;
V_24 . V_164 = F_99 ;
V_24 . V_165 = F_94 ;
F_57 ( V_100 , V_125 , L_18 ,
L_50 , & V_24 , ( const char * * ) & V_166 ) ;
V_24 . V_25 = F_108 ;
V_24 . V_160 = F_110 ;
V_24 . V_161 = F_111 ;
V_24 . V_162 = F_117 ;
V_24 . V_163 = F_118 ;
V_24 . V_164 = F_119 ;
V_24 . V_165 = F_120 ;
F_66 ( V_100 , V_101 , L_22 ,
L_23 , & V_24 ,
F_107 , & V_27 . V_167 ) ;
V_24 . V_25 = F_79 ;
V_24 . V_160 = F_101 ;
V_24 . V_161 = F_102 ;
V_24 . V_162 = F_103 ;
V_24 . V_163 = F_104 ;
V_24 . V_164 = F_105 ;
V_24 . V_165 = F_106 ;
F_52 ( V_100 , V_118 , L_51 ,
L_52 , & V_24 , & V_27 . V_168 ) ;
V_150 = F_15 ( V_151 , L_53 , L_53 , NULL ) ;
F_68 ( V_150 , L_54 ) ;
F_56 ( V_150 , L_55 , L_56 ,
L_57 , ( const char * * ) & V_27 . V_169 ) ;
F_56 ( V_150 , L_58 , L_56 ,
L_59 , ( const char * * ) & V_27 . V_170 ) ;
V_171 = F_15 ( V_151 , L_60 , L_60 , NULL ) ;
F_65 ( V_171 , L_61 , L_62 ,
L_62 , & V_27 . V_172 ) ;
F_65 ( V_171 , L_63 , L_62 ,
L_62 , & V_27 . V_173 ) ;
F_65 ( V_171 , L_64 , L_65 ,
L_65 , & V_27 . V_174 ) ;
F_65 ( V_171 , L_66 , L_65 ,
L_65 , & V_27 . V_175 ) ;
F_65 ( V_171 , L_67 , L_68 ,
L_68 , & V_27 . V_176 ) ;
F_65 ( V_171 , L_69 , L_68 ,
L_68 , & V_27 . V_177 ) ;
F_65 ( V_171 , L_70 , L_68 ,
L_68 , & V_27 . V_178 ) ;
F_65 ( V_171 , L_71 , L_68 ,
L_68 , & V_27 . V_179 ) ;
V_24 . V_25 = F_131 ;
V_24 . V_160 = F_132 ;
V_24 . V_161 = F_133 ;
V_24 . V_162 = F_134 ;
V_24 . V_163 = F_135 ;
V_24 . V_164 = F_136 ;
V_24 . V_165 = F_137 ;
F_57 ( V_100 , L_72 , L_73 ,
L_74 , & V_24 , ( const char * * ) & V_27 . V_180 ) ;
V_24 . V_25 = F_131 ;
V_24 . V_160 = F_132 ;
V_24 . V_161 = F_133 ;
V_24 . V_162 = F_134 ;
V_24 . V_163 = F_135 ;
V_24 . V_164 = F_136 ;
V_24 . V_165 = F_137 ;
F_57 ( V_100 , L_75 , L_76 ,
L_77 , & V_24 , ( const char * * ) & V_27 . V_181 ) ;
F_65 ( V_171 , L_78 , L_79 ,
L_79 , & V_27 . V_182 ) ;
F_65 ( V_171 , L_80 , L_81 ,
L_81 , & V_27 . V_183 ) ;
F_65 ( V_171 , L_82 , L_83 ,
L_83 , & V_27 . V_184 ) ;
F_54 ( V_151 , L_84 ,
L_85 ,
L_85 ,
& V_27 . V_185 , V_185 , FALSE ) ;
F_51 ( V_151 , L_86 ,
L_87 ,
L_87 ,
10 ,
& V_27 . V_87 ) ;
F_51 ( V_151 , L_88 ,
L_89 ,
L_89 ,
10 ,
& V_27 . V_88 ) ;
F_59 ( V_151 , L_90 , L_91 ,
L_92 , ( const char * * ) & V_27 . V_186 ) ;
F_68 ( V_151 , L_93 ) ;
F_51 ( V_151 , L_94 ,
L_95 ,
L_95 ,
10 ,
& V_27 . V_187 ) ;
F_53 ( V_151 , L_96 ,
L_97 ,
L_98 ,
& V_27 . V_188 ) ;
F_53 ( V_151 , L_99 ,
L_100 ,
L_101 ,
& V_27 . V_189 ) ;
F_53 ( V_151 , L_102 ,
L_103 ,
L_104 ,
& V_27 . V_190 ) ;
F_53 ( V_151 , L_105 ,
L_106 ,
L_107 ,
& V_27 . V_191 ) ;
F_53 ( V_151 , L_108 ,
L_109 ,
L_110 ,
& V_27 . V_192 ) ;
F_53 ( V_151 , L_111 ,
L_112 ,
L_113 ,
& V_27 . V_193 ) ;
F_53 ( V_151 , L_114 ,
L_115 ,
L_116 ,
& V_27 . V_194 ) ;
F_68 ( V_151 , L_117 ) ;
F_68 ( V_151 , L_118 ) ;
F_68 ( V_151 , L_119 ) ;
F_68 ( V_151 , L_120 ) ;
F_68 ( V_151 , L_121 ) ;
F_54 ( V_151 , L_122 ,
L_123 ,
L_123 ,
& V_27 . V_195 , V_196 , FALSE ) ;
F_54 ( V_151 , L_124 ,
L_125 ,
L_125 ,
& V_27 . V_197 , V_196 , FALSE ) ;
F_56 ( V_151 , L_126 , L_127 ,
L_128 , ( const char * * ) & V_27 . V_198 ) ;
F_53 ( V_151 , L_129 ,
L_130 ,
L_131 ,
& V_27 . V_199 ) ;
F_54 ( V_151 , L_132 ,
L_133 ,
L_134 ,
( T_14 * ) ( void * ) ( & V_27 . V_200 ) , V_200 , FALSE ) ;
F_51 ( V_151 , L_135 ,
L_136 ,
L_137 ,
10 ,
& V_27 . V_201 ) ;
F_56 ( V_151 , L_138 , L_139 ,
L_140 , ( const char * * ) & V_27 . V_202 ) ;
F_56 ( V_151 , L_141 , L_142 ,
L_142 , ( const char * * ) ( & V_27 . V_203 ) ) ;
F_54 ( V_151 , L_143 ,
L_144 ,
L_144 ,
( T_14 * ) ( void * ) ( & V_27 . V_204 ) , V_205 , FALSE ) ;
F_53 ( V_151 , L_145 ,
L_146 ,
L_146 ,
& V_27 . V_206 ) ;
F_51 ( V_151 , L_147 ,
L_148 ,
L_148 ,
10 ,
& V_27 . V_207 ) ;
F_54 ( V_151 , L_149 ,
L_150 ,
L_150 ,
& V_27 . V_208 , V_208 , FALSE ) ;
V_149 = F_15 ( V_151 , L_151 , L_151 , F_78 ) ;
F_51 ( V_149 , L_152 ,
L_153 ,
L_154 ,
10 ,
( T_4 * ) ( void * ) ( & V_27 . V_89 ) ) ;
F_54 ( V_149 , L_155 ,
L_156 ,
L_156 ,
( T_14 * ) ( void * ) ( & V_27 . V_209 ) , V_210 , FALSE ) ;
F_54 ( V_149 , L_157 ,
L_158 ,
L_158 ,
( T_14 * ) ( void * ) ( & V_27 . V_211 ) , V_210 , FALSE ) ;
F_54 ( V_149 , L_159 ,
L_160 ,
L_160 ,
( T_14 * ) ( void * ) ( & V_27 . V_212 ) , V_210 , FALSE ) ;
V_148 = F_12 ( NULL , L_161 , L_162 ,
L_163 , NULL , FALSE ) ;
V_24 . V_25 = F_79 ;
V_24 . V_160 = F_80 ;
V_24 . V_161 = F_81 ;
V_24 . V_162 = F_83 ;
V_24 . V_163 = F_84 ;
V_24 . V_164 = F_86 ;
V_24 . V_165 = F_87 ;
F_52 ( V_148 , L_164 , L_165 ,
L_166 , & V_24 , & V_27 . V_213 ) ;
V_147 = F_12 ( NULL , L_167 , L_168 ,
L_169 , NULL , FALSE ) ;
F_56 ( V_147 , L_170 , L_171 ,
L_171 , ( const char * * ) & V_27 . V_214 ) ;
F_56 ( V_147 , L_172 , L_173 ,
L_174 ,
( const char * * ) & V_27 . V_215 ) ;
F_56 ( V_147 , L_175 , L_176 ,
L_177 ,
( const char * * ) & V_27 . V_216 ) ;
F_56 ( V_147 , L_178 , L_179 ,
L_180 , ( const char * * ) & V_27 . V_217 ) ;
F_56 ( V_147 , L_181 , L_182 ,
L_183 ,
( const char * * ) & V_27 . V_218 ) ;
#if F_139 ( V_219 ) || F_139 ( V_220 )
F_56 ( V_147 , L_184 , L_185 ,
L_186 ,
( ( const char * * ) & V_27 . V_221 ) ) ;
#endif
F_56 ( V_147 , L_187 , L_188 ,
L_189 ,
( const char * * ) & V_27 . V_222 ) ;
F_56 ( V_147 , L_190 , L_191 ,
L_192 ,
( const char * * ) & V_27 . V_223 ) ;
F_53 ( V_147 , L_193 , L_194 ,
L_195 , & V_27 . V_224 ) ;
F_53 ( V_147 , L_196 , L_197 ,
L_198 , & V_27 . V_225 ) ;
F_53 ( V_147 , L_199 , L_200 ,
L_201 , & V_27 . V_226 ) ;
F_53 ( V_147 , L_202 , L_203 ,
L_204 , & V_27 . V_227 ) ;
F_53 ( V_147 , L_205 , L_206 ,
L_207 , & V_27 . V_228 ) ;
F_68 ( V_147 , L_208 ) ;
V_24 . V_25 = F_123 ;
V_24 . V_160 = F_125 ;
V_24 . V_161 = F_126 ;
V_24 . V_162 = F_127 ;
V_24 . V_163 = F_128 ;
V_24 . V_164 = F_129 ;
V_24 . V_165 = F_130 ;
F_66 ( V_147 , L_1 , L_209 ,
L_210 , & V_24 , F_122 , & V_27 . V_134 ) ;
V_229 = F_12 ( NULL , L_211 , L_212 ,
L_212 , NULL , TRUE ) ;
F_140 ( V_229 ) ;
F_141 ( V_229 ) ;
#ifdef F_142
F_143 ( V_229 ) ;
#endif
V_146 = F_12 ( NULL , L_213 , L_214 ,
L_214 , NULL , TRUE ) ;
F_54 ( V_146 , L_215 ,
L_216 , L_217 ,
& V_27 . V_230 , V_231 , TRUE ) ;
F_54 ( V_146 , L_218 ,
L_219 , L_220 ,
& V_27 . V_232 , V_233 , TRUE ) ;
#ifndef V_219
F_56 ( V_146 , L_221 , L_222 ,
L_223 , ( const char * * ) ( & V_27 . V_234 ) ) ;
#endif
F_58 ( V_146 , L_224 , L_225 ,
L_226 , ( const char * * ) ( & V_27 . V_235 ) ) ;
V_49 = F_12 ( NULL , L_227 , L_228 ,
L_228 , & F_75 , TRUE ) ;
F_51 ( V_49 , L_229 ,
L_230 ,
L_231 ,
10 ,
& V_27 . V_83 ) ;
#ifdef F_76
F_51 ( V_49 , L_232 ,
L_233 ,
L_234 ,
10 ,
& V_27 . V_85 ) ;
#endif
V_42 = F_12 ( NULL , L_235 , L_236 ,
L_236 , NULL , TRUE ) ;
F_53 ( V_42 , L_237 ,
L_238 ,
L_239 ,
& V_27 . V_236 ) ;
F_12 ( NULL , L_240 , L_241 , L_241 , NULL , FALSE ) ;
F_12 ( NULL , L_242 , L_243 , L_243 , NULL , FALSE ) ;
F_12 ( NULL , L_244 , L_245 , L_245 , NULL , FALSE ) ;
}
T_17 *
F_112 ( const T_13 * V_237 )
{
enum { V_238 , V_239 , V_240 };
T_14 V_241 = V_238 , V_140 = 0 , V_242 = 0 ;
T_6 V_243 = FALSE ;
T_7 V_244 ;
T_13 * V_245 = NULL ;
T_17 * V_246 = NULL ;
V_245 = ( T_13 * ) F_144 ( sizeof( T_13 ) * V_247 ) ;
V_242 = 0 ;
for (; ; ) {
V_244 = V_237 [ V_140 ] ;
if ( V_244 == '\0' ) {
if ( V_241 == V_239 || V_243 ) {
F_5 ( V_245 ) ;
F_114 ( V_246 ) ;
return NULL ;
}
V_245 [ V_242 ] = '\0' ;
V_246 = F_45 ( V_246 , V_245 ) ;
break;
}
if ( V_244 == '"' && ! V_243 ) {
switch ( V_241 ) {
case V_238 :
V_241 = V_239 ;
break;
case V_239 :
V_241 = V_240 ;
break;
case V_240 :
V_241 = V_239 ;
break;
default:
break;
}
} else if ( V_244 == '\\' && ! V_243 ) {
V_243 = TRUE ;
if ( V_241 == V_238 )
V_241 = V_240 ;
} else if ( V_244 == ',' && V_241 != V_239 && ! V_243 ) {
V_245 [ V_242 ] = '\0' ;
V_246 = F_45 ( V_246 , V_245 ) ;
V_241 = V_238 ;
V_245 = ( T_13 * ) F_144 ( sizeof( T_13 ) * V_247 ) ;
V_242 = 0 ;
} else if ( ! isspace ( V_244 ) || V_241 != V_238 ) {
if ( V_242 < V_247 ) {
V_245 [ V_242 ] = V_244 ;
V_242 ++ ;
}
V_243 = FALSE ;
}
V_140 ++ ;
}
return ( V_246 ) ;
}
static char *
F_121 ( T_17 * V_246 )
{
T_28 * V_248 = F_95 ( L_5 ) ;
T_17 * V_249 , * V_250 ;
T_13 * V_237 ;
T_13 * V_251 ;
T_4 V_252 = 0 ;
V_249 = V_250 = F_73 ( V_246 ) ;
while ( V_249 ) {
V_252 ++ ;
V_237 = ( T_13 * ) V_249 -> V_3 ;
if ( V_249 != V_250 )
F_145 ( V_248 , ',' ) ;
if ( V_252 % 2 ) {
F_97 ( V_248 , L_246 ) ;
} else
F_145 ( V_248 , ' ' ) ;
V_251 = F_146 ( V_237 , L_5 ) ;
F_147 ( V_248 , L_247 , V_251 ) ;
F_5 ( V_251 ) ;
V_249 = V_249 -> V_102 ;
}
return F_98 ( V_248 , FALSE ) ;
}
void
F_114 ( T_17 * V_246 )
{
T_17 * V_253 = V_246 ;
while ( V_253 ) {
F_5 ( V_253 -> V_3 ) ;
V_253 = F_124 ( V_253 , V_253 ) ;
}
}
static T_14
F_148 ( const char * V_254 , const T_18 * V_255 ,
T_14 V_256 )
{
int V_140 ;
for ( V_140 = 0 ; V_255 [ V_140 ] . V_21 != NULL ; V_140 ++ ) {
if ( F_149 ( V_254 , V_255 [ V_140 ] . V_21 ) == 0 ) {
return V_255 [ V_140 ] . V_50 ;
}
}
for ( V_140 = 0 ; V_255 [ V_140 ] . V_21 != NULL ; V_140 ++ ) {
if ( F_149 ( V_254 , V_255 [ V_140 ] . V_32 ) == 0 ) {
return V_255 [ V_140 ] . V_50 ;
}
}
return V_256 ;
}
static T_6
F_115 ( T_27 * V_98 , const char * V_106 )
{
const T_13 * V_257 = F_96 ( V_107 ) ;
T_29 V_258 = strlen ( V_257 ) ;
T_13 * * V_259 ;
char * V_35 ;
int V_260 ;
T_13 * V_261 ;
long V_262 ;
T_6 V_263 ;
if ( ( strlen ( V_106 ) > V_258 ) && ( V_106 [ V_258 ] == ':' ) &&
strncmp ( V_106 , V_257 , V_258 ) == 0 ) {
V_260 = V_107 ;
V_259 = F_150 ( & V_106 [ V_258 + 1 ] , L_248 , 3 ) ;
V_261 = F_28 ( V_259 [ 0 ] ) ;
if ( V_261 && V_259 [ 1 ] ) {
V_262 = strtol ( V_259 [ 1 ] , & V_35 , 10 ) ;
if ( V_35 == V_259 [ 1 ] || * V_35 != '\0' ) {
F_5 ( V_261 ) ;
F_151 ( V_259 ) ;
return FALSE ;
}
} else {
V_262 = 0 ;
}
if ( V_261 && V_259 [ 1 ] && V_259 [ 2 ] ) {
V_263 = ( V_259 [ 2 ] [ 0 ] == 'U' ) ? FALSE : TRUE ;
} else {
V_263 = TRUE ;
}
F_151 ( V_259 ) ;
} else {
V_260 = F_152 ( V_106 ) ;
if ( V_260 == - 1 )
return FALSE ;
V_261 = NULL ;
V_262 = 0 ;
V_263 = TRUE ;
}
V_98 -> V_106 = V_260 ;
V_98 -> V_108 = V_261 ;
V_98 -> V_109 = ( int ) V_262 ;
V_98 -> V_110 = V_263 ;
return TRUE ;
}
static void
F_153 ( void )
{
if ( V_264 )
return;
F_154 () ;
F_22 () ;
F_155 ( TRUE ) ;
V_264 = TRUE ;
}
static void
F_138 ( void )
{
int V_140 ;
T_13 * V_136 ;
T_27 * V_98 ;
static const T_13 * V_260 [ V_265 * 2 ] = {
L_249 , L_250 , L_251 , L_252 ,
L_253 , L_254 , L_255 , L_256 ,
L_257 , L_258 , L_259 , L_260 ,
L_261 , L_262 } ;
if ( V_266 )
return;
V_27 . V_230 = V_267 ;
V_27 . V_232 = V_268 ;
V_27 . V_235 = L_263 ;
V_27 . V_234 = L_264 ;
V_27 . V_154 = FALSE ;
V_27 . V_155 = FALSE ;
V_27 . V_157 = 0 ;
V_27 . V_158 = 1 ;
V_27 . V_159 = 1 ;
V_27 . V_156 = FALSE ;
V_27 . V_195 = V_269 ;
V_27 . V_197 = V_270 ;
#ifdef V_219
V_27 . V_169 = ( char * ) L_265 ;
#else
V_27 . V_169 = ( char * ) L_266 ;
#endif
V_27 . V_170 = ( char * ) L_5 ;
V_27 . V_172 . V_271 = 65535 ;
V_27 . V_172 . V_272 = 65535 ;
V_27 . V_172 . V_273 = 65535 ;
V_27 . V_172 . V_274 = 65535 ;
V_27 . V_173 . V_271 = 0 ;
V_27 . V_173 . V_272 = 0 ;
V_27 . V_173 . V_273 = 8224 ;
V_27 . V_173 . V_274 = 10794 ;
V_27 . V_174 . V_271 = 32767 ;
V_27 . V_174 . V_272 = 32767 ;
V_27 . V_174 . V_273 = 32767 ;
V_27 . V_174 . V_274 = 32767 ;
V_27 . V_175 . V_271 = 65535 ;
V_27 . V_175 . V_272 = 65535 ;
V_27 . V_175 . V_273 = 65535 ;
V_27 . V_175 . V_274 = 65535 ;
V_27 . V_180 = L_267 ;
V_27 . V_181 = L_268 ;
V_27 . V_176 . V_271 = 0 ;
V_27 . V_176 . V_272 = 32767 ;
V_27 . V_176 . V_273 = 0 ;
V_27 . V_176 . V_274 = 0 ;
V_27 . V_177 . V_271 = 0 ;
V_27 . V_177 . V_272 = 64507 ;
V_27 . V_177 . V_273 = 60909 ;
V_27 . V_177 . V_274 = 60909 ;
V_27 . V_178 . V_271 = 0 ;
V_27 . V_178 . V_272 = 0 ;
V_27 . V_178 . V_273 = 0 ;
V_27 . V_178 . V_274 = 32767 ;
V_27 . V_179 . V_271 = 0 ;
V_27 . V_179 . V_272 = 60909 ;
V_27 . V_179 . V_273 = 60909 ;
V_27 . V_179 . V_274 = 64507 ;
V_27 . V_182 . V_271 = 0 ;
V_27 . V_182 . V_272 = 0xAFFF ;
V_27 . V_182 . V_273 = 0xFFFF ;
V_27 . V_182 . V_274 = 0xAFFF ;
V_27 . V_183 . V_271 = 0 ;
V_27 . V_183 . V_272 = 0xFFFF ;
V_27 . V_183 . V_273 = 0xAFFF ;
V_27 . V_183 . V_274 = 0xAFFF ;
V_27 . V_184 . V_271 = 0 ;
V_27 . V_184 . V_272 = 0xFFFF ;
V_27 . V_184 . V_273 = 0xFFFF ;
V_27 . V_184 . V_274 = 0xAFFF ;
V_27 . V_191 = TRUE ;
V_27 . V_192 = TRUE ;
V_27 . V_193 = TRUE ;
V_27 . V_194 = TRUE ;
V_27 . V_152 = V_275 ;
V_27 . V_185 = V_276 ;
V_27 . V_88 = 10 ;
V_27 . V_87 = 10 ;
V_27 . V_186 = ( char * ) F_156 () ;
V_27 . V_187 = 3 ;
V_27 . V_188 = TRUE ;
V_27 . V_189 = TRUE ;
V_27 . V_190 = FALSE ;
V_27 . V_199 = TRUE ;
V_27 . V_200 = V_277 ;
V_27 . V_201 = 60 * 60 * 24 ;
V_27 . V_198 = ( char * ) V_278 L_269 ;
V_27 . V_202 = ( char * ) L_5 ;
V_27 . V_203 = L_270 ;
V_27 . V_204 = V_279 ;
V_27 . V_206 = FALSE ;
V_27 . V_207 = 0 ;
V_27 . V_89 = V_92 ;
V_27 . V_209 = V_280 ;
V_27 . V_211 = V_281 ;
V_27 . V_212 = V_282 ;
V_27 . V_208 = 0 ;
V_27 . V_167 = NULL ;
for ( V_140 = 0 ; V_140 < V_265 ; V_140 ++ ) {
V_98 = F_42 ( T_27 , 1 ) ;
V_98 -> V_31 = F_28 ( V_260 [ V_140 * 2 ] ) ;
F_115 ( V_98 , V_260 [ ( V_140 * 2 ) + 1 ] ) ;
V_98 -> V_103 = TRUE ;
V_98 -> V_110 = TRUE ;
V_98 -> V_108 = NULL ;
V_98 -> V_109 = 0 ;
V_27 . V_167 = F_45 ( V_27 . V_167 , V_98 ) ;
}
V_27 . V_168 = V_265 ;
V_27 . V_224 = TRUE ;
#ifdef F_157
V_27 . V_225 = TRUE ;
#else
V_27 . V_225 = FALSE ;
#endif
V_27 . V_226 = TRUE ;
V_27 . V_227 = TRUE ;
V_27 . V_228 = FALSE ;
V_27 . V_134 = NULL ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
V_136 = F_28 ( V_142 [ V_140 ] ) ;
V_27 . V_134 = F_45 ( V_27 . V_134 , V_136 ) ;
}
V_27 . V_213 =
V_283 | V_284 | V_285 ;
V_27 . V_83 = V_84 ;
V_27 . V_85 = V_86 ;
V_27 . V_236 = FALSE ;
V_266 = TRUE ;
}
static void
F_158 ( T_3 * V_5 )
{
if ( ! V_5 ) return;
switch ( V_5 -> type ) {
case V_9 :
* V_5 -> V_16 . V_64 = V_5 -> V_17 . V_64 ;
break;
case V_7 :
* V_5 -> V_16 . V_67 = V_5 -> V_17 . V_23 ;
break;
case V_8 :
* V_5 -> V_16 . V_70 = V_5 -> V_17 . V_71 ;
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
* V_5 -> V_16 . V_77 = V_5 -> V_17 . V_76 ;
break;
case V_20 :
V_5 -> V_24 . V_160 ( V_5 ) ;
break;
case V_6 :
break;
}
}
static void
F_159 ( T_1 V_3 , T_1 T_2 V_4 )
{
T_3 * V_5 = ( T_3 * ) V_3 ;
F_158 ( V_5 ) ;
}
static T_6
F_160 ( void * V_50 , void * V_3 V_4 )
{
T_30 V_59 ;
V_59 . V_26 = ( T_5 * ) V_50 ;
F_7 ( V_59 . V_26 -> V_27 , F_159 , & V_59 ) ;
return FALSE ;
}
void
F_161 ( void )
{
V_264 = FALSE ;
F_5 ( V_27 . V_286 ) ;
F_162 () ;
F_163 () ;
F_153 () ;
F_35 ( V_1 , F_160 , NULL ) ;
}
T_31 *
F_164 ( int * V_287 , int * V_288 ,
char * * V_289 , int * V_290 ,
int * V_291 , char * * V_292 )
{
int V_293 ;
char * V_294 ;
T_32 * V_295 ;
F_163 () ;
F_153 () ;
if ( V_296 == NULL ) {
V_296 = F_165 ( V_297 ) ;
if ( ( V_295 = F_166 ( V_296 , L_271 ) ) == NULL && V_298 == V_299 ) {
F_5 ( V_296 ) ;
V_296 = F_165 ( V_300 ) ;
V_295 = F_166 ( V_296 , L_271 ) ;
}
} else {
V_295 = F_166 ( V_296 , L_271 ) ;
}
* V_289 = NULL ;
if ( V_295 != NULL ) {
V_301 = 0 ;
V_302 = 0 ;
V_293 = F_167 ( V_296 , V_295 , V_303 , NULL ) ;
if ( V_293 != 0 ) {
* V_287 = 0 ;
* V_288 = V_293 ;
* V_289 = V_296 ;
}
fclose ( V_295 ) ;
} else {
if ( V_298 != V_299 ) {
* V_287 = V_298 ;
* V_288 = 0 ;
* V_289 = V_296 ;
}
}
V_294 = F_168 ( V_297 , TRUE ) ;
* V_292 = NULL ;
if ( ( V_295 = F_166 ( V_294 , L_271 ) ) != NULL ) {
V_301 = 0 ;
V_302 = 0 ;
V_293 = F_167 ( V_294 , V_295 , V_303 , NULL ) ;
if ( V_293 != 0 ) {
* V_290 = 0 ;
* V_291 = V_293 ;
* V_292 = V_294 ;
} else
F_5 ( V_294 ) ;
fclose ( V_295 ) ;
} else {
if ( V_298 != V_299 ) {
* V_290 = V_298 ;
* V_291 = 0 ;
* V_292 = V_294 ;
} else
F_5 ( V_294 ) ;
}
F_169 () ;
return & V_27 ;
}
int
F_167 ( const char * V_294 , T_32 * V_295 ,
T_33 V_304 , void * V_305 )
{
enum { V_306 , V_307 , V_308 , V_309 , V_310 };
int V_311 , V_241 = V_306 ;
T_28 * V_312 ;
T_28 * V_313 ;
T_6 V_314 = FALSE ;
T_14 V_315 = 1 , V_316 = 1 ;
T_13 V_317 [] = L_272 ;
V_312 = F_95 ( L_5 ) ;
V_313 = F_95 ( L_5 ) ;
V_311 = getc ( V_295 ) ;
if ( V_311 ) {
char V_318 [ 100 ] ;
if ( fgets ( V_318 , 100 , V_295 ) != NULL ) {
if ( strncmp ( ( const char * ) V_318 , L_273 , 24 ) == 0 ) {
const T_13 * V_319 = ( T_13 * ) & V_318 [ 24 ] ;
V_27 . V_286 = F_170 ( V_319 , strlen ( V_319 ) - 2 ) ;
}
}
}
rewind ( V_295 ) ;
while ( ( V_311 = getc ( V_295 ) ) != V_320 ) {
if ( V_311 == '\n' ) {
V_241 = V_306 ;
V_315 ++ ;
continue;
}
switch ( V_241 ) {
case V_306 :
if ( isalnum ( V_311 ) ) {
if ( V_313 -> V_111 > 0 ) {
if ( V_314 ) {
if ( V_312 -> V_111 > 0 ) {
if ( V_312 -> V_237 [ V_312 -> V_111 - 1 ] == ',' ) {
V_312 -> V_237 [ V_312 -> V_111 - 1 ] = '\0' ;
F_171 ( L_274 , V_294 , V_316 , V_313 -> V_237 , V_317 ) ;
}
}
switch ( V_304 ( V_313 -> V_237 , V_312 -> V_237 , V_305 , FALSE ) ) {
case V_80 :
break;
case V_123 :
F_171 ( L_275 ,
V_313 -> V_237 , V_316 , V_294 , V_317 ) ;
break;
case V_81 :
if ( strcmp ( V_313 -> V_237 , L_276 ) != 0 )
F_171 ( L_277 ,
V_313 -> V_237 , V_316 , V_294 , V_317 ) ;
V_27 . V_321 = TRUE ;
break;
case V_322 :
if ( strcmp ( V_313 -> V_237 , L_276 ) != 0 )
F_171 ( L_278 ,
V_313 -> V_237 , V_316 , V_294 , V_317 ) ;
V_27 . V_321 = TRUE ;
break;
}
} else {
F_171 ( L_279 , V_316 , V_294 , V_317 ) ;
}
}
V_241 = V_307 ;
V_314 = FALSE ;
F_172 ( V_313 , 0 ) ;
F_145 ( V_313 , ( T_13 ) V_311 ) ;
V_316 = V_315 ;
} else if ( isspace ( V_311 ) && V_313 -> V_111 > 0 && V_314 ) {
V_241 = V_308 ;
} else if ( V_311 == '#' ) {
V_241 = V_310 ;
} else {
F_171 ( L_280 , V_315 , V_294 , V_317 ) ;
}
break;
case V_307 :
if ( V_311 != ':' ) {
F_145 ( V_313 , ( T_13 ) V_311 ) ;
} else {
V_241 = V_308 ;
F_172 ( V_312 , 0 ) ;
V_314 = TRUE ;
}
break;
case V_308 :
if ( ! isspace ( V_311 ) ) {
V_241 = V_309 ;
F_145 ( V_312 , ( T_13 ) V_311 ) ;
}
break;
case V_309 :
F_145 ( V_312 , ( T_13 ) V_311 ) ;
break;
}
}
if ( V_313 -> V_111 > 0 ) {
if ( V_314 ) {
switch ( V_304 ( V_313 -> V_237 , V_312 -> V_237 , V_305 , FALSE ) ) {
case V_80 :
break;
case V_123 :
F_171 ( L_281 ,
V_313 -> V_237 , V_316 , V_294 , V_317 ) ;
break;
case V_81 :
F_171 ( L_277 ,
V_313 -> V_237 , V_316 , V_294 , V_317 ) ;
V_27 . V_321 = TRUE ;
break;
case V_322 :
V_27 . V_321 = TRUE ;
break;
}
} else {
F_171 ( L_282 ,
V_316 , V_294 , V_317 ) ;
}
}
F_98 ( V_312 , TRUE ) ;
F_98 ( V_313 , TRUE ) ;
if ( ferror ( V_295 ) )
return V_298 ;
else
return 0 ;
}
static T_6
F_173 ( char * V_323 ) {
T_13 * V_35 , * V_324 ;
T_21 * V_75 ;
T_13 * V_293 ;
V_324 = strchr ( V_323 , ':' ) ;
if ( V_324 == NULL )
return FALSE ;
V_35 = V_324 ;
* V_35 ++ = '\0' ;
while ( isspace ( ( T_7 ) * V_35 ) )
V_35 ++ ;
if ( * V_35 == '\0' ) {
* V_324 = ':' ;
return FALSE ;
}
V_75 = F_174 ( V_323 ) ;
* V_324 = ':' ;
if ( V_75 == NULL ) {
return FALSE ;
}
if ( F_175 ( V_75 , V_35 , & V_293 ) ) {
return TRUE ;
}
return FALSE ;
}
T_25
F_176 ( char * V_325 )
{
T_13 * V_35 , * V_324 ;
T_25 V_52 ;
V_301 = - 1 ;
V_302 = - 1 ;
V_324 = strchr ( V_325 , ':' ) ;
if ( V_324 == NULL )
return V_123 ;
V_35 = V_324 ;
* V_35 ++ = '\0' ;
while ( isspace ( ( T_7 ) * V_35 ) )
V_35 ++ ;
if ( * V_35 == '\0' ) {
* V_324 = ':' ;
return V_123 ;
}
if ( strcmp ( V_325 , L_283 ) ) {
V_52 = V_303 ( V_325 , V_35 , NULL , TRUE ) ;
} else {
V_52 = F_173 ( V_35 ) ? V_80 : V_123 ;
}
* V_324 = ':' ;
return V_52 ;
}
T_6
F_177 ( const char * V_21 )
{
T_13 * V_326 , * V_327 ;
T_29 V_111 ;
if ( V_27 . V_217 && V_21 ) {
V_327 = F_28 ( V_27 . V_217 ) ;
V_111 = strlen ( V_21 ) ;
for ( V_326 = strtok ( V_327 , L_21 ) ; V_326 ; V_326 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_326 ) == V_111 && strcmp ( V_21 , V_326 ) == 0 ) {
F_5 ( V_327 ) ;
return TRUE ;
}
}
F_5 ( V_327 ) ;
}
return FALSE ;
}
static T_6
F_91 ( const T_13 * V_104 , T_27 * V_98 )
{
T_13 * V_326 , * V_328 ;
T_27 V_329 ;
if ( V_104 ) {
V_328 = F_28 ( V_104 ) ;
for ( V_326 = strtok ( V_328 , L_21 ) ; V_326 ; V_326 = strtok ( NULL , L_21 ) ) {
V_326 = F_178 ( V_326 ) ;
if ( ! F_115 ( & V_329 , V_326 ) ) {
continue;
}
if ( V_98 -> V_106 != V_329 . V_106 ) {
F_5 ( V_329 . V_108 ) ;
continue;
}
if ( V_98 -> V_106 == V_107 ) {
if ( strcmp ( V_98 -> V_108 ,
V_329 . V_108 ) != 0 ) {
F_5 ( V_329 . V_108 ) ;
continue;
}
if ( V_98 -> V_109 != V_329 . V_109 ) {
F_5 ( V_329 . V_108 ) ;
continue;
}
}
F_5 ( V_329 . V_108 ) ;
F_5 ( V_328 ) ;
return FALSE ;
}
F_5 ( V_328 ) ;
}
return TRUE ;
}
T_6
F_179 ( const char * V_21 )
{
T_13 * V_326 , * V_327 ;
T_29 V_111 ;
if ( V_27 . V_218 && V_21 ) {
V_327 = F_28 ( V_27 . V_218 ) ;
V_111 = strlen ( V_21 ) ;
for ( V_326 = strtok ( V_327 , L_21 ) ; V_326 ; V_326 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_326 ) == V_111 && strcmp ( V_21 , V_326 ) == 0 ) {
F_5 ( V_327 ) ;
return TRUE ;
}
}
F_5 ( V_327 ) ;
}
return FALSE ;
}
T_6
F_180 ( const T_13 * V_330 )
{
T_17 * V_331 ;
T_13 * V_137 ;
for ( V_331 = F_73 ( V_27 . V_134 ) ; V_331 ; V_331 = F_74 ( V_331 ) ) {
V_137 = ( T_13 * ) V_331 -> V_3 ;
if ( V_137 && ( F_149 ( V_137 , V_330 ) == 0 ) ) {
return TRUE ;
}
}
return FALSE ;
}
char
F_181 ( const char * string , T_34 * V_332 )
{
char V_36 ;
memset ( V_332 , 0 , sizeof( T_34 ) ) ;
while ( ( V_36 = * string ++ ) != '\0' ) {
switch ( V_36 ) {
case 'm' :
V_332 -> V_333 = TRUE ;
break;
case 'n' :
V_332 -> V_334 = TRUE ;
break;
case 'N' :
V_332 -> V_335 = TRUE ;
break;
case 't' :
V_332 -> V_336 = TRUE ;
break;
case 'C' :
V_332 -> V_337 = TRUE ;
break;
default:
return V_36 ;
}
}
return '\0' ;
}
static void
F_116 ( T_1 * V_338 )
{
struct {
T_14 V_339 ;
const T_13 * V_340 ;
} V_341 [] = {
{ V_342 , L_284 } ,
{ V_343 , L_285 } ,
{ V_344 , L_286 } ,
{ V_345 , L_287 } ,
{ V_346 , L_288 } ,
{ V_347 , L_289 } ,
{ V_348 , L_290 } ,
{ V_349 , L_291 } ,
{ V_350 , L_292 } ,
{ V_351 , L_293 } ,
{ V_352 , L_294 } ,
{ V_353 , L_295 } ,
{ V_354 , L_296 }
} ;
T_4 V_355 ;
const T_13 * V_356 ;
T_13 * * V_106 = ( T_13 * * ) V_338 ;
for ( V_355 = 0 ;
V_355 < F_182 ( V_341 ) ;
++ V_355 ) {
V_356 = F_96 ( V_341 [ V_355 ] . V_339 ) ;
if ( strcmp ( V_356 , * V_106 ) == 0 ) {
T_13 * V_357 = F_85 ( L_297 ,
V_341 [ V_355 ] . V_340 ) ;
F_5 ( * V_106 ) ;
* V_106 = V_357 ;
}
}
}
static T_25
V_303 ( T_13 * V_358 , const T_13 * V_50 , void * V_305 V_4 ,
T_6 V_359 )
{
unsigned long int V_360 ;
T_4 V_94 ;
T_6 V_361 ;
T_14 V_362 ;
char * V_35 ;
T_13 * V_363 , * V_364 ;
static T_13 * V_365 = NULL ;
static T_6 V_366 = FALSE ;
T_13 * V_367 = NULL ;
T_5 * V_26 ;
T_3 * V_5 ;
if ( strcmp ( V_358 , V_368 ) == 0 ) {
V_365 = F_28 ( V_50 ) ;
} else if ( strcmp ( V_358 , V_369 ) == 0 ) {
V_366 = ( strcmp ( V_50 , L_298 ) == 0 ) ? TRUE : FALSE ;
} else if ( strcmp ( V_358 , V_370 ) == 0 ) {
V_367 = F_28 ( V_50 ) ;
F_183 ( V_365 , V_367 , V_366 ) ;
F_5 ( V_365 ) ;
F_5 ( V_367 ) ;
} else if ( strcmp ( V_358 , L_299 ) == 0 ) {
if ( F_149 ( V_50 , L_300 ) == 0 ) {
V_27 . V_204 = V_279 ;
} else {
V_27 . V_204 = V_371 ;
}
} else if ( strcmp ( V_358 , L_301 ) == 0 ||
strcmp ( V_358 , L_302 ) == 0 ) {
if ( F_149 ( V_50 , L_300 ) == 0 ) {
V_372 . V_333 = TRUE ;
V_372 . V_334 = TRUE ;
V_372 . V_336 = TRUE ;
V_372 . V_337 = TRUE ;
}
else if ( F_149 ( V_50 , L_303 ) == 0 ) {
V_372 . V_333 = FALSE ;
V_372 . V_334 = FALSE ;
V_372 . V_336 = FALSE ;
V_372 . V_337 = FALSE ;
}
else {
V_372 . V_333 = FALSE ;
V_372 . V_334 = FALSE ;
V_372 . V_336 = FALSE ;
V_372 . V_337 = FALSE ;
if ( F_181 ( V_50 , & V_372 ) != '\0' )
return V_123 ;
}
} else {
if ( ( strcmp ( V_358 , L_304 ) == 0 ) ||
( strcmp ( V_358 , L_305 ) == 0 ) ||
( strcmp ( V_358 , L_306 ) == 0 ) ) {
V_26 = V_229 ;
V_363 = V_358 ;
} else {
V_26 = NULL ;
V_364 = V_358 ;
while ( ! V_26 ) {
V_363 = strchr ( V_364 , '.' ) ;
if ( V_363 == NULL ) {
return V_81 ;
}
* V_363 = '\0' ;
V_26 = F_17 ( V_358 ) ;
if ( V_26 == NULL ) {
if ( strcmp ( V_358 , L_307 ) == 0 )
V_26 = V_100 ;
else if ( strcmp ( V_358 , L_308 ) == 0 )
V_26 = F_17 ( L_309 ) ;
else if ( strcmp ( V_358 , L_310 ) == 0 )
V_26 = F_17 ( L_311 ) ;
else if ( strcmp ( V_358 , L_312 ) == 0 ||
strcmp ( V_358 , L_313 ) == 0 )
V_26 = F_17 ( L_314 ) ;
else if ( strcmp ( V_358 , L_315 ) == 0 )
V_26 = F_17 ( L_316 ) ;
else if ( strcmp ( V_358 , L_317 ) == 0 )
V_26 = F_17 ( L_318 ) ;
else if ( strcmp ( V_358 , L_319 ) == 0 )
V_26 = F_17 ( L_320 ) ;
else if ( strcmp ( V_358 , L_321 ) == 0 )
V_26 = F_17 ( L_322 ) ;
else if ( strcmp ( V_358 , L_323 ) == 0 )
V_26 = F_17 ( L_324 ) ;
else if ( strcmp ( V_358 , L_325 ) == 0 )
V_26 = F_17 ( L_326 ) ;
else if ( strcmp ( V_358 , L_327 ) == 0 ||
strcmp ( V_358 , L_328 ) == 0 ) {
return V_322 ;
}
if ( V_26 ) {
F_171 ( L_329
L_330 ,
V_358 , V_363 + 1 , V_26 -> V_30 -> V_21 , V_358 , V_363 + 1 ) ;
V_27 . V_321 = TRUE ;
}
}
* V_363 = '.' ;
V_363 ++ ;
V_364 = V_363 ;
}
}
V_5 = F_44 ( V_26 , V_363 ) ;
if ( V_5 == NULL ) {
V_27 . V_321 = TRUE ;
if ( ( strcmp ( V_358 , V_125 ) == 0 ) ||
( strcmp ( V_358 , V_101 ) == 0 ) ) {
V_5 = F_44 ( V_26 , V_358 ) ;
}
else if ( strcmp ( V_26 -> V_21 , L_331 ) == 0 ) {
if ( strcmp ( V_363 , L_332 ) == 0 )
V_5 = F_44 ( V_26 , L_333 ) ;
else if ( strcmp ( V_363 , L_334 ) == 0 )
V_5 = F_44 ( V_26 , L_335 ) ;
else if ( strcmp ( V_363 , L_336 ) == 0 ) {
V_301 ++ ;
if ( V_301 == 1 ) {
V_5 = F_44 ( V_26 , L_337 ) ;
} else if ( V_301 == 2 ) {
V_5 = F_44 ( V_26 , L_338 ) ;
}
} else if ( strcmp ( V_363 , L_339 ) == 0 ) {
V_302 ++ ;
if ( V_302 == 1 ) {
V_5 = F_44 ( V_26 , L_340 ) ;
} else if ( V_302 == 2 ) {
V_5 = F_44 ( V_26 , L_341 ) ;
}
}
} else if ( strcmp ( V_26 -> V_21 , L_342 ) == 0 ) {
if ( strcmp ( V_363 , L_343 ) == 0 )
V_5 = F_44 ( V_26 , L_344 ) ;
else if ( strcmp ( V_363 , L_345 ) == 0 )
V_5 = F_44 ( V_26 , L_346 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_347 ) == 0 ) {
if ( strcmp ( V_363 , L_348 ) == 0 )
V_5 = F_44 ( V_26 , L_349 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_309 ) == 0 ) {
if ( strcmp ( V_363 , L_350 ) == 0 )
V_5 = F_44 ( V_26 , L_349 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_351 ) == 0 ) {
if ( strcmp ( V_363 , L_352 ) == 0 )
V_5 = F_44 ( V_26 , L_353 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_354 ) == 0 ) {
if ( strcmp ( V_363 , L_355 ) == 0 )
V_5 = F_44 ( V_26 , L_353 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_356 ) == 0 ) {
if ( strcmp ( V_363 , L_357 ) == 0 )
V_5 = F_44 ( V_26 , L_358 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_359 ) == 0 ) {
if ( strcmp ( V_363 , L_360 ) == 0 )
V_5 = F_44 ( V_26 , L_361 ) ;
else if ( strcmp ( V_363 , L_362 ) == 0 )
V_5 = F_44 ( V_26 , L_363 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_364 ) == 0 ) {
if ( strcmp ( V_363 , L_365 ) == 0 )
V_5 = F_44 ( V_26 , L_349 ) ;
else if ( strcmp ( V_363 , L_366 ) == 0 )
V_5 = F_44 ( V_26 , L_367 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_314 ) == 0 ) {
if ( strcmp ( V_363 , L_368 ) == 0 )
V_5 = F_44 ( V_26 , L_369 ) ;
else if ( strcmp ( V_363 , L_370 ) == 0 )
V_5 = F_44 ( V_26 , L_371 ) ;
else if ( strcmp ( V_363 , L_372 ) == 0 )
V_5 = F_44 ( V_26 , L_373 ) ;
else if ( strcmp ( V_363 , L_374 ) == 0 )
V_5 = F_44 ( V_26 , L_375 ) ;
else if ( strcmp ( V_363 , L_376 ) == 0 )
V_5 = F_44 ( V_26 , L_377 ) ;
else if ( strcmp ( V_363 , L_378 ) == 0 )
V_5 = F_44 ( V_26 , L_379 ) ;
else if ( strcmp ( V_363 , L_380 ) == 0 )
V_5 = F_44 ( V_26 , L_381 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_382 ) == 0 ) {
if ( strcmp ( V_363 , L_383 ) == 0 )
V_5 = F_44 ( V_26 , L_384 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_385 ) == 0 ) {
if ( strcmp ( V_363 , L_386 ) == 0 )
V_5 = F_44 ( V_26 , L_367 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_387 ) == 0 ) {
if ( strcmp ( V_363 , L_388 ) == 0 )
V_5 = F_44 ( V_26 , L_389 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_390 ) == 0 ) {
if ( strcmp ( V_363 , L_391 ) == 0 )
V_5 = F_44 ( V_26 , L_392 ) ;
else if ( strcmp ( V_363 , L_393 ) == 0 )
V_5 = F_44 ( V_26 , L_394 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_395 ) == 0 ) {
if ( strcmp ( V_363 , L_396 ) == 0 )
V_5 = F_44 ( V_26 , L_397 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_398 ) == 0 ) {
if ( strcmp ( V_363 , L_399 ) == 0 )
V_5 = F_44 ( V_26 , L_400 ) ;
else if ( strcmp ( V_363 , L_401 ) == 0 )
V_5 = F_44 ( V_26 , L_402 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_403 ) == 0 ) {
if ( strcmp ( V_363 , L_404 ) == 0 )
V_5 = F_44 ( V_26 , L_405 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_406 ) == 0 ) {
if ( strcmp ( V_363 , L_407 ) == 0 )
V_5 = F_44 ( V_26 , L_384 ) ;
else if ( strcmp ( V_363 , L_408 ) == 0 )
V_5 = F_44 ( V_26 , L_409 ) ;
else if ( strcmp ( V_363 , L_410 ) == 0 )
V_5 = F_44 ( V_26 , L_411 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_412 ) == 0 ) {
if ( strcmp ( V_363 , L_413 ) == 0 )
V_5 = F_44 ( V_26 , L_384 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_414 ) == 0 ) {
if ( strcmp ( V_363 , L_415 ) == 0 )
V_5 = F_44 ( V_26 , L_416 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_417 ) == 0 ) {
if ( strcmp ( V_363 , L_418 ) == 0 )
V_5 = F_44 ( V_26 , L_419 ) ;
else if ( strcmp ( V_363 , L_420 ) == 0 )
V_5 = F_44 ( V_26 , L_421 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_422 ) == 0 ) {
T_5 * V_45 = F_17 ( L_316 ) ;
if ( V_45 ) {
if ( strcmp ( V_363 , L_423 ) == 0 )
V_5 = F_44 ( V_45 , L_423 ) ;
else if ( strcmp ( V_363 , L_424 ) == 0 )
V_5 = F_44 ( V_45 , L_424 ) ;
}
} else if ( strcmp ( V_26 -> V_21 , L_425 ) == 0 ) {
if ( strcmp ( V_363 , L_426 ) == 0 )
V_5 = F_44 ( V_26 , L_427 ) ;
else if ( strcmp ( V_363 , L_353 ) == 0 )
V_5 = F_44 ( V_26 , L_428 ) ;
else if ( strcmp ( V_363 , L_429 ) == 0 )
V_5 = F_44 ( V_26 , L_430 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_431 ) == 0 ) {
if ( strcmp ( V_363 , L_432 ) == 0 )
V_5 = F_44 ( V_26 , L_433 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_434 ) == 0 ) {
if ( strcmp ( V_363 , L_435 ) == 0 ) {
V_5 = F_44 ( V_26 , L_436 ) ;
if ( strcmp ( V_50 , L_436 ) == 0 || strcmp ( V_50 , L_437 ) == 0 )
V_50 = L_298 ;
else if ( strcmp ( V_50 , L_438 ) == 0 || strcmp ( V_50 , L_439 ) == 0 )
V_50 = L_440 ;
else if ( strcmp ( V_50 , L_441 ) == 0 || strcmp ( V_50 , L_442 ) == 0 )
V_50 = L_298 ;
} else if ( strcmp ( V_363 , L_443 ) == 0 ) {
V_5 = F_44 ( V_26 , L_444 ) ;
if ( strcmp ( V_50 , L_445 ) == 0 || strcmp ( V_50 , L_446 ) == 0 )
V_50 = L_447 ;
else if ( strcmp ( V_50 , L_448 ) == 0 || strcmp ( V_50 , L_449 ) == 0 )
V_50 = L_448 ;
else if ( strcmp ( V_50 , L_441 ) == 0 || strcmp ( V_50 , L_442 ) == 0 )
V_50 = L_447 ;
} else if ( strcmp ( V_363 , L_450 ) == 0 ) {
V_5 = F_44 ( V_26 , L_451 ) ;
if ( strcmp ( V_50 , L_452 ) == 0 || strcmp ( V_50 , L_453 ) == 0 )
V_50 = L_452 ;
else if ( strcmp ( V_50 , L_398 ) == 0 || strcmp ( V_50 , L_454 ) == 0 )
V_50 = L_398 ;
else if ( strcmp ( V_50 , L_455 ) == 0 || strcmp ( V_50 , L_456 ) == 0 )
V_50 = L_457 ;
else if ( strcmp ( V_50 , L_458 ) == 0 || strcmp ( V_50 , L_459 ) == 0 )
V_50 = L_458 ;
else if ( strcmp ( V_50 , L_441 ) == 0 || strcmp ( V_50 , L_442 ) == 0 )
V_50 = L_447 ;
}
} else if ( strcmp ( V_26 -> V_21 , L_438 ) == 0 ) {
if ( strcmp ( V_363 , L_460 ) == 0 ) {
T_5 * V_45 = F_17 ( L_461 ) ;
if ( V_45 ) {
V_5 = F_44 ( V_45 , L_460 ) ;
V_26 = V_45 ;
}
}
} else if ( strcmp ( V_26 -> V_21 , L_240 ) == 0 ) {
if ( strcmp ( V_363 , L_229 ) == 0 ||
strcmp ( V_363 , L_232 ) == 0 )
V_5 = F_44 ( V_49 , V_363 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_242 ) == 0 ) {
if ( strcmp ( V_363 , L_237 ) == 0 )
V_5 = F_44 ( V_42 , V_363 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_244 ) == 0 ) {
if ( ( strcmp ( V_363 , L_462 ) == 0 ) ||
( strcmp ( V_363 , L_463 ) == 0 ) ||
( strcmp ( V_363 , L_464 ) == 0 ) ||
( strcmp ( V_363 , L_465 ) == 0 ) )
V_5 = F_44 ( V_171 , V_358 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_211 ) == 0 ) {
if ( strcmp ( V_358 , L_304 ) == 0 ) {
V_5 = F_44 ( V_229 , V_358 ) ;
} else if ( strcmp ( V_358 , L_305 ) == 0 ) {
V_5 = F_44 ( V_229 , L_466 ) ;
} else if ( strcmp ( V_358 , L_306 ) == 0 ) {
V_5 = F_44 ( V_229 , L_467 ) ;
}
}
}
if ( V_5 == NULL )
return V_81 ;
switch ( V_5 -> type ) {
case V_9 :
V_94 = ( T_4 ) strtoul ( V_50 , & V_35 , V_5 -> V_65 . V_62 ) ;
if ( V_35 == V_50 || * V_35 != '\0' )
return V_123 ;
if ( * V_5 -> V_16 . V_64 != V_94 ) {
V_26 -> V_38 = TRUE ;
* V_5 -> V_16 . V_64 = V_94 ;
}
break;
case V_7 :
if ( F_149 ( V_50 , L_300 ) == 0 )
V_361 = TRUE ;
else
V_361 = FALSE ;
if ( * V_5 -> V_16 . V_67 != V_361 ) {
V_26 -> V_38 = TRUE ;
* V_5 -> V_16 . V_67 = V_361 ;
}
break;
case V_8 :
V_362 = F_148 ( V_50 , V_5 -> V_65 . V_72 . V_68 ,
* V_5 -> V_16 . V_70 ) ;
if ( * V_5 -> V_16 . V_70 != V_362 ) {
V_26 -> V_38 = TRUE ;
* V_5 -> V_16 . V_70 = V_362 ;
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
T_19 * V_373 ;
if ( F_184 ( & V_373 , V_50 , V_5 -> V_65 . V_74 ,
V_359 ) != V_374 ) {
return V_123 ;
}
if ( ! F_185 ( * V_5 -> V_16 . V_19 , V_373 ) ) {
V_26 -> V_38 = TRUE ;
F_5 ( * V_5 -> V_16 . V_19 ) ;
* V_5 -> V_16 . V_19 = V_373 ;
} else {
F_5 ( V_373 ) ;
}
break;
}
case V_12 :
{
V_360 = strtoul ( V_50 , NULL , 16 ) ;
V_5 -> V_16 . V_77 -> V_271 = 0 ;
if ( ( V_5 -> V_16 . V_77 -> V_272 != F_186 ( V_360 ) ) ||
( V_5 -> V_16 . V_77 -> V_273 != F_187 ( V_360 ) ) ||
( V_5 -> V_16 . V_77 -> V_274 != F_188 ( V_360 ) ) ) {
V_26 -> V_38 = TRUE ;
V_5 -> V_16 . V_77 -> V_272 = F_186 ( V_360 ) ;
V_5 -> V_16 . V_77 -> V_273 = F_187 ( V_360 ) ;
V_5 -> V_16 . V_77 -> V_274 = F_188 ( V_360 ) ;
}
break;
}
case V_20 :
return V_5 -> V_24 . V_161 ( V_5 , V_50 , & V_26 -> V_38 ) ;
case V_10 :
case V_11 :
{
break;
}
case V_6 :
return V_322 ;
}
}
return V_80 ;
}
const char *
F_189 ( T_3 * V_5 )
{
const char * V_375 = L_468 ;
if ( ! V_5 ) {
return V_375 ;
}
switch ( V_5 -> type ) {
case V_9 :
switch ( V_5 -> V_65 . V_62 ) {
case 10 :
V_375 = L_469 ;
break;
case 8 :
V_375 = L_470 ;
break;
case 16 :
V_375 = L_471 ;
break;
}
break;
case V_7 :
V_375 = L_472 ;
break;
case V_8 :
V_375 = L_473 ;
break;
case V_13 :
V_375 = L_474 ;
break;
case V_14 :
V_375 = L_475 ;
break;
case V_15 :
V_375 = L_476 ;
break;
case V_18 :
V_375 = L_477 ;
break;
case V_12 :
V_375 = L_478 ;
break;
case V_20 :
if ( V_5 -> V_24 . V_162 )
return V_5 -> V_24 . V_162 () ;
V_375 = L_479 ;
break;
case V_6 :
V_375 = L_480 ;
break;
case V_10 :
V_375 = L_481 ;
break;
case V_11 :
V_375 = L_482 ;
break;
}
return V_375 ;
}
char *
F_190 ( T_3 * V_5 )
{
const char * V_376 = L_483 ;
if ( ! V_5 ) {
return F_85 ( L_484 , V_376 ) ;
}
switch ( V_5 -> type ) {
case V_9 :
switch ( V_5 -> V_65 . V_62 ) {
case 10 :
V_376 = L_485 ;
break;
case 8 :
V_376 = L_486 ;
break;
case 16 :
V_376 = L_487 ;
break;
}
break;
case V_7 :
V_376 = L_488 ;
break;
case V_8 :
{
const T_18 * V_377 = V_5 -> V_65 . V_72 . V_68 ;
T_28 * V_378 = F_95 ( L_489 ) ;
while ( V_377 -> V_21 != NULL ) {
F_97 ( V_378 , V_377 -> V_32 ) ;
V_377 ++ ;
if ( V_377 -> V_21 != NULL )
F_97 ( V_378 , L_490 ) ;
}
F_97 ( V_378 , L_491 ) ;
return F_98 ( V_378 , FALSE ) ;
break;
}
case V_13 :
V_376 = L_492 ;
break;
case V_14 :
V_376 = L_493 ;
break;
case V_15 :
V_376 = L_494 ;
break;
case V_18 :
{
V_376 = L_495 ;
break;
}
case V_12 :
{
V_376 = L_496 ;
break;
}
case V_20 :
if ( V_5 -> V_24 . V_163 )
return V_5 -> V_24 . V_163 () ;
V_376 = L_497 ;
break;
case V_6 :
V_376 = L_498 ;
break;
case V_10 :
V_376 = L_499 ;
break;
case V_11 :
V_376 = L_500 ;
break;
default:
break;
}
return F_28 ( V_376 ) ;
}
static T_6
F_191 ( T_3 * V_5 ) {
if ( ! V_5 ) return FALSE ;
switch ( V_5 -> type ) {
case V_9 :
if ( V_5 -> V_17 . V_64 == * V_5 -> V_16 . V_64 )
return TRUE ;
break;
case V_7 :
if ( V_5 -> V_17 . V_23 == * V_5 -> V_16 . V_67 )
return TRUE ;
break;
case V_8 :
if ( V_5 -> V_17 . V_71 == * V_5 -> V_16 . V_70 )
return TRUE ;
break;
case V_13 :
case V_14 :
case V_15 :
if ( ! ( F_100 ( V_5 -> V_17 . string , * V_5 -> V_16 . string ) ) )
return TRUE ;
break;
case V_18 :
{
if ( ( F_185 ( V_5 -> V_17 . V_19 , * V_5 -> V_16 . V_19 ) ) )
return TRUE ;
break;
}
case V_12 :
{
if ( ( V_5 -> V_17 . V_76 . V_272 == V_5 -> V_16 . V_77 -> V_272 ) &&
( V_5 -> V_17 . V_76 . V_273 == V_5 -> V_16 . V_77 -> V_273 ) &&
( V_5 -> V_17 . V_76 . V_274 == V_5 -> V_16 . V_77 -> V_274 ) )
return TRUE ;
break;
}
case V_20 :
return V_5 -> V_24 . V_164 ( V_5 ) ;
case V_6 :
case V_10 :
case V_11 :
return FALSE ;
break;
}
return FALSE ;
}
char *
F_192 ( T_3 * V_5 , T_35 V_379 ) {
const char * V_380 = L_468 ;
T_4 V_381 ;
T_6 V_382 ;
T_14 V_383 ;
const char * V_384 ;
T_19 * V_385 ;
T_22 * V_386 ;
if ( ! V_5 ) {
return F_28 ( V_380 ) ;
}
switch ( V_379 ) {
case V_387 :
V_381 = V_5 -> V_17 . V_64 ;
V_382 = V_5 -> V_17 . V_23 ;
V_383 = V_5 -> V_17 . V_71 ;
V_384 = V_5 -> V_17 . string ;
V_385 = V_5 -> V_17 . V_19 ;
V_386 = & V_5 -> V_17 . V_76 ;
break;
case V_388 :
V_381 = V_5 -> V_22 . V_64 ;
V_382 = V_5 -> V_22 . V_23 ;
V_383 = V_5 -> V_22 . V_71 ;
V_384 = V_5 -> V_22 . string ;
V_385 = V_5 -> V_22 . V_19 ;
V_386 = & V_5 -> V_22 . V_76 ;
break;
case V_389 :
V_381 = * V_5 -> V_16 . V_64 ;
V_382 = * V_5 -> V_16 . V_67 ;
V_383 = * V_5 -> V_16 . V_70 ;
V_384 = * V_5 -> V_16 . string ;
V_385 = * V_5 -> V_16 . V_19 ;
V_386 = V_5 -> V_16 . V_77 ;
break;
default:
return F_28 ( V_380 ) ;
}
switch ( V_5 -> type ) {
case V_9 :
switch ( V_5 -> V_65 . V_62 ) {
case 10 :
return F_85 ( L_17 , V_381 ) ;
break;
case 8 :
return F_85 ( L_501 , V_381 ) ;
break;
case 16 :
return F_85 ( L_502 , V_381 ) ;
break;
}
break;
case V_7 :
return F_85 ( L_254 , V_382 ? L_298 : L_440 ) ;
break;
case V_8 :
{
const T_18 * V_377 = V_5 -> V_65 . V_72 . V_68 ;
while ( V_377 -> V_21 != NULL ) {
if ( V_377 -> V_50 == V_383 )
return F_28 ( V_377 -> V_32 ) ;
V_377 ++ ;
}
break;
}
case V_13 :
case V_14 :
case V_15 :
return F_28 ( V_384 ) ;
break;
case V_18 :
V_380 = F_193 ( V_385 ) ;
break;
case V_12 :
return F_85 ( L_503 ,
( V_386 -> V_272 * 255 / 65535 ) ,
( V_386 -> V_273 * 255 / 65535 ) ,
( V_386 -> V_274 * 255 / 65535 ) ) ;
break;
case V_20 :
if ( V_5 -> V_24 . V_165 )
return V_5 -> V_24 . V_165 ( V_5 , V_379 == V_387 ? TRUE : FALSE ) ;
V_380 = L_504 ;
break;
case V_6 :
V_380 = L_505 ;
break;
case V_10 :
V_380 = L_499 ;
break;
case V_11 :
{
T_21 * V_75 = V_5 -> V_16 . V_75 ;
if ( V_75 && V_75 -> V_390 )
return F_85 ( L_506 , V_75 -> V_390 ) ;
else
V_380 = L_507 ;
break;
}
default:
break;
}
return F_28 ( V_380 ) ;
}
static void
F_194 ( T_1 V_3 , T_1 T_2 )
{
T_3 * V_5 = ( T_3 * ) V_3 ;
T_36 * V_59 = ( T_36 * ) T_2 ;
T_13 * * V_391 ;
int V_140 ;
switch ( V_5 -> type ) {
case V_6 :
return;
case V_10 :
case V_11 :
return;
default:
break;
}
if ( V_5 -> type != V_20 || V_5 -> V_24 . V_162 () != NULL ) {
const char * V_392 = ( V_59 -> V_26 -> V_21 != NULL ) ? V_59 -> V_26 -> V_21 : V_59 -> V_26 -> V_30 -> V_21 ;
char * V_376 , * V_380 ;
const char * V_393 = F_191 ( V_5 ) ? L_508 : L_5 ;
if ( V_5 -> type == V_20 ) fprintf ( V_59 -> V_295 , L_509 , V_5 -> V_24 . V_162 () ) ;
fprintf ( V_59 -> V_295 , L_510 ) ;
if ( V_5 -> V_32 &&
( F_195 ( V_5 -> V_32 , L_5 , 2 ) != 0 ) ) {
if ( V_5 -> type != V_20 ) {
V_391 = F_150 ( V_5 -> V_32 , L_510 , 0 ) ;
for ( V_140 = 0 ; V_391 [ V_140 ] != NULL ; ++ V_140 ) {
fprintf ( V_59 -> V_295 , L_511 , V_391 [ V_140 ] ) ;
}
F_151 ( V_391 ) ;
}
} else {
fprintf ( V_59 -> V_295 , L_512 ) ;
}
V_376 = F_190 ( V_5 ) ;
V_391 = F_150 ( V_376 , L_510 , 0 ) ;
for ( V_140 = 0 ; V_391 [ V_140 ] != NULL ; ++ V_140 ) {
fprintf ( V_59 -> V_295 , L_511 , V_391 [ V_140 ] ) ;
}
F_151 ( V_391 ) ;
F_5 ( V_376 ) ;
V_380 = F_192 ( V_5 , V_389 ) ;
fprintf ( V_59 -> V_295 , L_513 , V_393 , V_392 , V_5 -> V_21 ) ;
V_391 = F_150 ( V_380 , L_510 , 0 ) ;
for ( V_140 = 0 ; V_391 [ V_140 ] != NULL ; ++ V_140 ) {
fprintf ( V_59 -> V_295 , L_514 , V_140 == 0 ? L_5 : V_393 , V_391 [ V_140 ] ) ;
}
if ( V_140 == 0 ) fprintf ( V_59 -> V_295 , L_510 ) ;
F_151 ( V_391 ) ;
F_5 ( V_380 ) ;
}
}
static T_4
F_196 ( T_5 * V_26 , T_1 T_2 )
{
T_37 * V_394 = ( T_37 * ) T_2 ;
T_36 V_59 ;
if ( ( V_26 == V_151 ) && ( V_394 -> V_395 != TRUE ) )
return 0 ;
if ( ( ( V_26 -> V_30 == NULL ) || ( V_26 -> V_30 == V_151 ) ) &&
( ( F_36 ( V_26 ) ) ||
( V_26 -> V_28 > 0 ) ||
( V_26 -> V_21 == NULL ) ) ) {
if ( ( V_26 -> V_21 == NULL ) && ( V_26 -> V_30 != NULL ) ) {
fprintf ( V_394 -> V_295 , L_515 , V_26 -> V_30 -> V_31 , V_26 -> V_31 ) ;
} else {
fprintf ( V_394 -> V_295 , L_516 , V_26 -> V_31 ) ;
}
}
V_59 . V_26 = V_26 ;
V_59 . V_295 = V_394 -> V_295 ;
F_7 ( V_59 . V_26 -> V_27 , F_194 , & V_59 ) ;
if ( F_36 ( V_26 ) )
return F_9 ( V_26 , F_196 , T_2 ) ;
return 0 ;
}
int
F_197 ( char * * V_292 )
{
char * V_294 ;
T_32 * V_295 ;
T_37 V_396 ;
F_153 () ;
if ( V_292 != NULL ) {
V_294 = F_168 ( V_297 , TRUE ) ;
if ( ( V_295 = F_166 ( V_294 , L_517 ) ) == NULL ) {
* V_292 = V_294 ;
return V_298 ;
}
} else {
V_295 = stdout ;
}
fputs ( L_518 V_397 L_519
L_520
L_521
L_522
L_523
L_524 , V_295 ) ;
V_396 . V_295 = V_295 ;
V_396 . V_395 = TRUE ;
F_196 ( V_151 , & V_396 ) ;
{
struct V_398 * V_399 = * (struct V_398 * * ) V_27 . V_400 ;
if ( V_399 != NULL )
fprintf ( V_295 , L_525 ) ;
while ( V_399 != NULL ) {
if ( V_399 -> V_401 == FALSE ) {
fprintf ( V_295 , L_526 , V_368 , V_399 -> V_402 ) ;
fprintf ( V_295 , L_526 , V_369 ,
V_399 -> V_403 == TRUE ? L_298 : L_440 ) ;
fprintf ( V_295 , L_526 , V_370 , V_399 -> V_404 ) ;
}
V_399 = V_399 -> V_102 ;
}
}
V_396 . V_395 = FALSE ;
F_9 ( NULL , F_196 , & V_396 ) ;
fclose ( V_295 ) ;
return 0 ;
}
static void
F_109 ( T_17 * V_79 )
{
T_27 * V_98 ;
while ( V_79 != NULL ) {
V_98 = ( T_27 * ) V_79 -> V_3 ;
F_5 ( V_98 -> V_31 ) ;
F_5 ( V_98 -> V_108 ) ;
F_5 ( V_98 ) ;
V_79 = F_124 ( V_79 , V_79 ) ;
}
F_8 ( V_79 ) ;
V_79 = NULL ;
}
