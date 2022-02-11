void
F_1 ( void )
{
V_1 = F_2 ( V_2 , L_1 ) ;
V_3 = F_2 ( V_2 , L_2 ) ;
}
static void
F_3 ( T_1 V_4 , T_1 T_2 V_5 )
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
F_4 ( ( char * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = NULL ;
F_4 ( V_6 -> V_18 . string ) ;
V_6 -> V_18 . string = NULL ;
break;
case V_19 :
F_4 ( * V_6 -> V_17 . V_20 ) ;
* V_6 -> V_17 . V_20 = NULL ;
F_4 ( V_6 -> V_18 . V_20 ) ;
V_6 -> V_18 . V_20 = NULL ;
break;
case V_21 :
V_6 -> V_22 . V_23 ( V_6 ) ;
break;
}
F_4 ( V_6 ) ;
}
static T_4
F_5 ( T_5 * V_24 , T_1 V_4 V_5 )
{
F_6 ( V_24 -> V_25 , F_3 , NULL ) ;
F_7 ( V_24 -> V_25 ) ;
V_24 -> V_25 = NULL ;
V_24 -> V_26 = 0 ;
return 0 ;
}
void
F_8 ( void )
{
F_9 ( F_5 , NULL ) ;
}
T_5 *
F_10 ( T_5 * V_27 , const char * V_28 , const char * V_29 ,
const char * V_30 , void (* F_11)( void ) ,
const T_6 V_31 )
{
return F_12 ( V_27 , V_28 , V_29 , V_30 ,
FALSE , F_11 , V_31 ) ;
}
T_5 *
F_13 ( T_5 * V_27 , const char * V_29 , const char * V_30 ,
void (* F_11)( void ) )
{
return F_12 ( V_27 , NULL , V_29 , V_30 ,
TRUE , F_11 ,
V_27 ? V_27 -> V_31 : FALSE ) ;
}
static T_5 *
F_12 ( T_5 * V_27 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
T_6 V_32 , void (* F_11)( void ) ,
T_6 V_31 )
{
T_5 * V_24 ;
const char * V_33 ;
T_7 V_34 ;
if( ( V_24 = F_14 ( V_27 , V_29 ) ) ) {
V_24 -> V_28 = V_28 ;
V_24 -> F_11 = F_11 ;
V_24 -> V_30 = V_30 ;
if ( F_15 ( V_28 ) == NULL ) {
F_16 ( V_1 , V_28 , V_24 ,
V_35 ) ;
}
return V_24 ;
}
V_24 = F_17 ( T_5 , 1 ) ;
V_24 -> V_28 = V_28 ;
V_24 -> V_29 = V_29 ;
V_24 -> V_30 = V_30 ;
V_24 -> F_11 = F_11 ;
V_24 -> V_25 = NULL ;
V_24 -> V_27 = V_27 ;
V_24 -> V_36 = NULL ;
V_24 -> V_26 = 0 ;
V_24 -> V_37 = FALSE ;
V_24 -> V_38 = FALSE ;
V_24 -> V_31 = V_31 ;
if ( V_28 != NULL ) {
for ( V_33 = V_28 ; ( V_34 = * V_33 ) != '\0' ; V_33 ++ )
F_18 ( isascii ( V_34 ) &&
( islower ( V_34 ) || isdigit ( V_34 ) || V_34 == '_' ||
V_34 == '-' || V_34 == '.' ) ) ;
F_18 ( F_15 ( V_28 ) == NULL ) ;
F_16 ( V_1 , V_28 , V_24 , V_35 ) ;
} else {
F_18 ( V_32 ) ;
}
if ( V_27 == NULL ) {
F_16 ( V_3 , V_29 , V_24 , V_35 ) ;
} else {
if ( V_27 -> V_36 == NULL )
V_27 -> V_36 = F_2 ( V_2 , L_3 ) ;
F_16 ( V_27 -> V_36 , V_29 , V_24 , V_35 ) ;
}
return V_24 ;
}
T_5 *
F_19 ( int V_39 , void (* F_11)( void ) )
{
T_8 * V_40 ;
if ( V_41 == NULL ) {
F_20 () ;
}
V_40 = F_21 ( V_39 ) ;
return F_10 ( V_41 ,
F_22 ( V_39 ) ,
F_23 ( V_40 ) ,
F_24 ( V_39 ) , F_11 , TRUE ) ;
}
T_5 *
F_25 ( const char * V_42 , int V_39 , void (* F_11)( void ) )
{
T_8 * V_40 ;
T_5 * V_43 ;
T_5 * V_44 ;
char * V_45 = NULL , * V_46 = NULL , * V_47 = NULL ;
if ( V_41 == NULL ) {
F_20 () ;
}
V_43 = V_41 ;
if( V_42 ) {
V_47 = V_46 = F_26 ( V_42 ) ;
while( V_46 && * V_46 ) {
if( ( V_45 = strchr ( V_46 , '/' ) ) )
* V_45 ++ = '\0' ;
if( ! ( V_44 = F_14 ( V_43 , V_46 ) ) ) {
V_46 = F_27 ( F_28 () , V_46 ) ,
V_44 = F_13 ( V_43 , V_46 , V_46 , NULL ) ;
}
V_43 = V_44 ;
V_46 = V_45 ;
}
F_4 ( V_47 ) ;
}
V_40 = F_21 ( V_39 ) ;
return F_10 ( V_43 ,
F_22 ( V_39 ) ,
F_23 ( V_40 ) ,
F_24 ( V_39 ) , F_11 , TRUE ) ;
}
T_5 *
F_29 ( int V_39 )
{
T_5 * V_24 ;
T_8 * V_40 ;
if ( V_41 == NULL ) {
F_20 () ;
}
V_40 = F_21 ( V_39 ) ;
V_24 = F_10 ( V_41 ,
F_22 ( V_39 ) ,
F_23 ( V_40 ) ,
F_24 ( V_39 ) , NULL , TRUE ) ;
V_24 -> V_38 = TRUE ;
return V_24 ;
}
T_5 *
F_30 ( const char * V_28 , const char * V_29 ,
const char * V_30 , void (* F_11)( void ) )
{
if ( V_48 == NULL ) {
F_20 () ;
}
return F_10 ( V_48 , V_28 , V_29 , V_30 ,
F_11 , TRUE ) ;
}
T_5 *
F_15 ( const char * V_28 )
{
return ( T_5 * ) F_31 ( V_1 , V_28 , V_35 ) ;
}
static T_5 *
F_14 ( T_5 * V_27 , const char * V_28 )
{
return ( T_5 * ) F_31 ( V_27 ? V_27 -> V_36 : V_3 , V_28 , V_35 ) ;
}
static T_6
F_32 ( void * V_49 , void * V_4 )
{
T_5 * V_24 = ( T_5 * ) V_49 ;
T_9 * V_50 = ( T_9 * ) V_4 ;
if ( ! V_24 -> V_38 ) {
V_50 -> V_51 = (* V_50 -> V_52 )( V_24 , V_50 -> T_2 ) ;
}
return ( V_50 -> V_51 != 0 ) ;
}
static T_4
F_33 ( T_10 * V_53 , T_11 V_52 ,
T_1 T_2 )
{
T_9 V_50 ;
if ( V_53 == NULL )
V_53 = V_3 ;
V_50 . V_52 = V_52 ;
V_50 . T_2 = T_2 ;
V_50 . V_51 = 0 ;
F_34 ( V_53 , F_32 , & V_50 ) ;
return V_50 . V_51 ;
}
T_6
F_35 ( T_5 * V_24 )
{
if ( V_24 -> V_36 == NULL ) {
return FALSE ;
}
if ( V_24 -> V_36 -> V_54 == NULL ) {
return FALSE ;
}
return TRUE ;
}
T_4
F_9 ( T_11 V_52 , T_1 T_2 )
{
return F_33 ( V_1 , V_52 , T_2 ) ;
}
T_4
F_36 ( T_5 * V_24 , T_11 V_52 ,
T_1 T_2 )
{
return F_33 ( ( V_24 ) ? V_24 -> V_36 : V_3 , V_52 , T_2 ) ;
}
static T_6
F_37 ( void * V_49 , void * V_4 V_5 )
{
T_5 * V_24 = ( T_5 * ) V_49 ;
if ( V_24 -> V_38 )
return FALSE ;
if ( V_24 -> V_37 ) {
if ( V_24 -> F_11 != NULL )
(* V_24 -> F_11 )() ;
V_24 -> V_37 = FALSE ;
}
return FALSE ;
}
void
F_38 ( void )
{
F_34 ( V_1 , F_37 , NULL ) ;
}
void
F_39 ( T_5 * V_24 )
{
if ( V_24 && V_24 -> V_37 )
F_37 ( V_24 , NULL ) ;
}
static T_3 *
F_40 ( T_5 * V_24 , const char * V_28 , const char * V_29 ,
const char * V_30 , T_12 type )
{
T_3 * V_55 ;
const T_13 * V_33 ;
V_55 = F_17 ( T_3 , 1 ) ;
V_55 -> V_28 = V_28 ;
V_55 -> V_29 = V_29 ;
V_55 -> V_30 = V_30 ;
V_55 -> type = type ;
if ( V_29 != NULL )
V_55 -> V_56 = V_24 -> V_26 ;
else
V_55 -> V_56 = - 1 ;
for ( V_33 = V_28 ; * V_33 != '\0' ; V_33 ++ )
if ( ! ( isascii ( ( T_7 ) * V_33 ) &&
( islower ( ( T_7 ) * V_33 ) || isdigit ( ( T_7 ) * V_33 ) || * V_33 == '_' || * V_33 == '.' ) ) )
F_41 ( L_4 , V_24 -> V_28 , V_28 ) ;
if ( F_42 ( V_24 , V_28 ) != NULL )
F_41 ( L_5 , V_28 ) ;
if ( ( type != V_7 ) &&
( V_24 -> V_28 != NULL ) ) {
if( ! ( ( strncmp ( V_28 , V_24 -> V_28 , strlen ( V_24 -> V_28 ) ) != 0 ) ||
( ( ( V_28 [ strlen ( V_24 -> V_28 ) ] ) != '.' ) && ( ( V_28 [ strlen ( V_24 -> V_28 ) ] ) != '_' ) ) ) )
F_41 ( L_6 , V_28 ) ;
}
V_24 -> V_25 = F_43 ( V_24 -> V_25 , V_55 ) ;
if ( V_29 != NULL )
V_24 -> V_26 ++ ;
return V_55 ;
}
static T_14
F_44 ( T_15 V_57 , T_15 V_58 )
{
const T_3 * V_6 = ( const T_3 * ) V_57 ;
const char * V_28 = ( const char * ) V_58 ;
return strcmp ( V_28 , V_6 -> V_28 ) ;
}
static T_6 F_45 ( void * V_49 , void * V_4 )
{
T_16 * V_59 = ( T_16 * ) V_4 ;
T_17 * V_60 ;
T_5 * V_24 = ( T_5 * ) V_49 ;
if ( V_24 == NULL )
return FALSE ;
V_60 = F_46 ( V_24 -> V_25 , V_59 -> V_28 ,
F_44 ) ;
if ( V_60 == NULL )
return FALSE ;
V_59 -> V_60 = V_60 ;
return TRUE ;
}
struct V_55 *
F_42 ( T_5 * V_24 , const char * V_28 )
{
T_16 V_59 ;
T_17 * V_60 ;
if ( V_24 == NULL )
return NULL ;
V_60 = F_46 ( V_24 -> V_25 , V_28 ,
F_44 ) ;
if ( V_60 == NULL )
{
V_59 . V_60 = NULL ;
if ( V_24 -> V_36 != NULL )
{
V_59 . V_28 = V_28 ;
F_34 ( V_24 -> V_36 , F_45 , & V_59 ) ;
}
V_60 = V_59 . V_60 ;
}
if ( V_60 == NULL )
{
return NULL ;
}
return (struct V_55 * ) V_60 -> V_4 ;
}
T_6
F_47 ( const char * V_28 )
{
T_5 * V_61 = F_15 ( V_28 ) ;
return ( V_61 != NULL && ! V_61 -> V_38 ) ;
}
const char *
F_48 ( const char * V_28 )
{
T_5 * V_61 = F_15 ( V_28 ) ;
return ( V_61 != NULL && ! V_61 -> V_38 ) ? V_61 -> V_29 : NULL ;
}
void
F_49 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
T_4 V_62 , T_4 * V_63 )
{
T_3 * V_55 ;
V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 ,
V_10 ) ;
V_55 -> V_17 . V_64 = V_63 ;
V_55 -> V_18 . V_64 = * V_63 ;
F_18 ( V_62 > 0 && V_62 != 1 && V_62 < 37 ) ;
V_55 -> V_65 . V_62 = V_62 ;
}
static void
F_50 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
struct V_66 * V_22 , T_4 * V_63 )
{
T_3 * V_55 ;
V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 ,
V_21 ) ;
V_55 -> V_22 = * V_22 ;
V_55 -> V_17 . V_64 = V_63 ;
V_55 -> V_18 . V_64 = * V_63 ;
}
void
F_51 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
T_6 * V_63 )
{
T_3 * V_55 ;
V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 ,
V_8 ) ;
V_55 -> V_17 . V_67 = V_63 ;
V_55 -> V_18 . V_68 = * V_63 ;
}
void
F_52 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
T_14 * V_63 , const T_18 * V_69 ,
T_6 V_70 )
{
T_3 * V_55 ;
V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 ,
V_9 ) ;
V_55 -> V_17 . V_71 = V_63 ;
V_55 -> V_18 . V_72 = * V_63 ;
V_55 -> V_65 . V_73 . V_69 = V_69 ;
V_55 -> V_65 . V_73 . V_70 = V_70 ;
}
static T_3 *
F_53 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
const char * * V_63 , T_12 type )
{
T_3 * V_55 ;
char * V_74 ;
V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 ,
type ) ;
if ( * V_63 == NULL ) {
* V_63 = F_26 ( L_7 ) ;
V_74 = F_26 ( L_7 ) ;
} else {
* V_63 = F_26 ( * V_63 ) ;
V_74 = F_26 ( * V_63 ) ;
}
V_55 -> V_17 . string = V_63 ;
V_55 -> V_18 . string = V_74 ;
V_55 -> V_75 . string = NULL ;
return V_55 ;
}
void
F_54 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
const char * * V_63 )
{
F_53 ( V_24 , V_28 , V_29 , V_30 , V_63 ,
V_14 ) ;
}
static
void F_55 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
struct V_66 * V_22 , const char * * V_63 )
{
T_3 * V_55 ;
V_55 = F_53 ( V_24 , V_28 , V_29 , V_30 , V_63 ,
V_21 ) ;
V_55 -> V_22 = * V_22 ;
}
void
F_56 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
const char * * V_63 )
{
F_53 ( V_24 , V_28 , V_29 , V_30 , V_63 ,
V_15 ) ;
}
void
F_57 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
const char * * V_63 )
{
F_53 ( V_24 , V_28 , V_29 , V_30 , V_63 ,
V_16 ) ;
}
void
F_58 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
T_19 * * V_63 , T_20 V_76 )
{
T_3 * V_55 ;
V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 ,
V_19 ) ;
V_55 -> V_65 . V_76 = V_76 ;
if ( * V_63 == NULL )
* V_63 = F_59 () ;
V_55 -> V_17 . V_20 = V_63 ;
V_55 -> V_18 . V_20 = F_60 ( * V_63 ) ;
V_55 -> V_75 . V_20 = NULL ;
}
void
F_61 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 ,
const char * V_30 )
{
F_40 ( V_24 , V_28 , V_29 , V_30 , V_11 ) ;
}
extern void
F_62 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 ,
void * V_77 )
{
T_3 * V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 , V_12 ) ;
V_55 -> V_17 . V_77 = V_77 ;
}
void F_63 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 , T_21 * V_78 )
{
T_3 * V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 , V_13 ) ;
V_55 -> V_17 . V_79 = V_78 ;
V_55 -> V_18 . V_78 = * V_78 ;
}
static
void F_64 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 , struct V_66 * V_22 ,
T_22 V_80 , T_17 * * V_81 )
{
T_3 * V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 , V_21 ) ;
V_55 -> V_22 = * V_22 ;
V_80 ( V_55 , V_81 ) ;
}
void F_65 ( T_5 * V_24 , const char * V_28 ,
const char * V_29 , const char * V_30 , struct V_66 * V_22 ,
void * * T_23 V_5 )
{
T_3 * V_55 = F_40 ( V_24 , V_28 , V_29 , V_30 , V_21 ) ;
V_55 -> V_22 = * V_22 ;
}
void
F_66 ( T_5 * V_24 , const char * V_28 )
{
F_40 ( V_24 , V_28 , NULL , NULL , V_7 ) ;
}
extern T_6
F_67 ( T_3 * V_6 )
{
if ( V_6 ) {
return V_6 -> type == V_7 ? TRUE : FALSE ;
}
return TRUE ;
}
extern T_24
F_68 ( T_3 * V_6 )
{
if ( V_6 ) {
V_6 -> type = V_7 ;
return V_82 ;
}
return V_83 ;
}
T_4 F_69 ( T_3 * V_6 )
{
if ( V_6 && V_6 -> type == V_10 )
return * V_6 -> V_17 . V_64 ;
return 0 ;
}
T_4
F_70 ( T_5 * V_24 , T_25 V_52 , T_1 T_2 )
{
T_17 * V_84 ;
T_3 * V_6 ;
T_4 V_51 ;
for ( V_84 = F_71 ( V_24 -> V_25 ) ; V_84 != NULL ; V_84 = F_72 ( V_84 ) ) {
V_6 = ( T_3 * ) V_84 -> V_4 ;
if ( V_6 -> type == V_7 ) {
continue;
}
V_51 = (* V_52)( V_6 , T_2 ) ;
if ( V_51 != 0 )
return V_51 ;
}
return 0 ;
}
static void F_73 ( void )
{
if ( V_25 . V_85 < 100 || V_25 . V_85 > 10000 ) {
V_25 . V_85 = V_86 ;
}
#ifdef F_74
if ( V_25 . V_87 < 1 || V_25 . V_87 > 10 )
V_25 . V_87 = V_88 ;
#endif
}
static void F_75 ( void )
{
if ( V_25 . V_89 == 0 )
V_25 . V_89 = 10 ;
if ( V_25 . V_90 == 0 )
V_25 . V_90 = 10 ;
}
static void F_76 ( void )
{
if ( V_25 . V_91 == V_92 ||
V_25 . V_91 >= V_93 ) {
V_25 . V_91 = V_94 ;
}
}
static void F_77 ( T_3 * V_6 V_5 ) {}
static void F_78 ( T_3 * V_6 )
{
* V_6 -> V_17 . V_64 = V_6 -> V_18 . V_64 ;
}
static T_24 F_79 ( T_3 * V_6 , const T_13 * V_49 , T_6 * V_95 )
{
T_4 V_96 ;
V_96 = ( T_4 ) strtoul ( V_49 , NULL , 10 ) ;
if ( * V_6 -> V_17 . V_64 != V_96 ) {
* V_95 = TRUE ;
* V_6 -> V_17 . V_64 = V_96 ;
}
if ( * V_6 -> V_17 . V_64 & ( V_97 | V_98 ) ) {
F_80 ( L_8 , L_9 , TRUE ) ;
}
return V_82 ;
}
static const char * F_81 ( void ) {
return L_10 ;
}
static char * F_82 ( void ) {
return F_83 (
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18 ) ;
}
static T_6 F_84 ( T_3 * V_6 ) {
return * V_6 -> V_17 . V_64 == V_6 -> V_18 . V_64 ;
}
static char * F_85 ( T_3 * V_6 , T_6 V_18 ) {
return F_83 ( L_19 , V_18 ? V_6 -> V_18 . V_64 : * V_6 -> V_17 . V_64 ) ;
}
static void F_86 ( T_3 * V_6 )
{
F_4 ( ( char * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = NULL ;
F_4 ( V_6 -> V_18 . string ) ;
V_6 -> V_18 . string = NULL ;
}
static void F_87 ( T_3 * V_6 )
{
F_4 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_26 ( V_6 -> V_18 . string ) ;
}
static T_24 F_88 ( T_3 * V_6 , const T_13 * V_49 , T_6 * V_95 )
{
T_17 * V_99 ;
T_26 * V_100 ;
T_3 * V_101 ;
if ( * V_6 -> V_17 . string ) {
if ( strcmp ( * V_6 -> V_17 . string , V_49 ) != 0 ) {
* V_95 = TRUE ;
F_4 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_26 ( V_49 ) ;
}
} else if ( V_49 ) {
* V_6 -> V_17 . string = F_26 ( V_49 ) ;
}
V_101 = F_42 ( V_102 , V_103 ) ;
for ( V_99 = * V_101 -> V_17 . V_81 ; V_99 != NULL ; V_99 = V_99 -> V_104 ) {
V_100 = ( T_26 * ) V_99 -> V_4 ;
V_100 -> V_105 = F_89 ( * V_6 -> V_17 . string , V_100 ) ;
}
return V_82 ;
}
static const char * F_90 ( void ) {
return L_20 ;
}
static char * F_91 ( void ) {
return F_26 ( L_21 ) ;
}
static char * F_92 ( T_3 * V_6 , T_6 V_18 ) {
T_27 * V_106 = F_93 ( L_7 ) ;
T_17 * V_99 ;
T_26 * V_100 ;
T_3 * V_101 ;
if ( V_18 )
return F_26 ( V_6 -> V_18 . string ) ;
V_101 = F_42 ( V_102 , V_103 ) ;
V_99 = ( V_101 ) ? * V_101 -> V_17 . V_81 : NULL ;
while ( V_99 ) {
T_13 * V_107 ;
V_100 = ( T_26 * ) V_99 -> V_4 ;
if ( ( V_100 -> V_108 == V_109 ) && ( V_100 -> V_110 ) ) {
V_107 = F_83 ( L_22 ,
F_94 ( V_100 -> V_108 ) ,
V_100 -> V_110 ,
V_100 -> V_111 ,
V_100 -> V_112 ? 'R' : 'U' ) ;
} else {
V_107 = F_26 ( F_94 ( V_100 -> V_108 ) ) ;
}
if ( ! V_100 -> V_105 ) {
if ( V_106 -> V_113 ) {
F_95 ( V_106 , L_23 ) ;
}
F_95 ( V_106 , V_107 ) ;
}
V_99 = V_99 -> V_104 ;
}
return F_96 ( V_106 , FALSE ) ;
}
static T_6 F_97 ( T_3 * V_6 ) {
char * V_114 = F_92 ( V_6 , FALSE ) ;
T_6 V_115 = F_98 ( V_114 , V_6 -> V_18 . string ) == 0 ;
F_4 ( V_114 ) ;
return V_115 ;
}
static void F_99 ( T_3 * V_6 )
{
* V_6 -> V_17 . V_64 = V_6 -> V_18 . V_64 ;
}
static T_24 F_100 ( T_3 * V_6 V_5 , const T_13 * V_49 V_5 , T_6 * V_95 V_5 )
{
return V_82 ;
}
static const char * F_101 ( void ) {
return NULL ;
}
static char * F_102 ( void ) {
return F_26 ( L_7 ) ;
}
static T_6 F_103 ( T_3 * V_6 V_5 ) {
return TRUE ;
}
static char * F_104 ( T_3 * V_6 V_5 , T_6 V_18 V_5 ) {
return F_26 ( L_7 ) ;
}
static void F_105 ( T_3 * V_6 , T_17 * * V_49 )
{
T_26 * V_116 , * V_117 ;
T_17 * V_118 ;
V_6 -> V_17 . V_81 = V_49 ;
V_6 -> V_18 . V_81 = NULL ;
for ( V_118 = * V_6 -> V_17 . V_81 ; V_118 != NULL ; V_118 = F_72 ( V_118 ) ) {
V_116 = ( T_26 * ) V_118 -> V_4 ;
V_117 = F_17 ( T_26 , 1 ) ;
V_117 -> V_29 = F_26 ( V_116 -> V_29 ) ;
V_117 -> V_108 = V_116 -> V_108 ;
if ( V_116 -> V_110 ) {
V_117 -> V_110 = F_26 ( V_116 -> V_110 ) ;
V_117 -> V_111 = V_116 -> V_111 ;
} else {
V_117 -> V_110 = NULL ;
V_117 -> V_111 = 0 ;
}
V_117 -> V_105 = V_116 -> V_105 ;
V_117 -> V_112 = V_116 -> V_112 ;
V_6 -> V_18 . V_81 = F_43 ( V_6 -> V_18 . V_81 , V_117 ) ;
}
}
static void F_106 ( T_3 * V_6 )
{
F_107 ( * V_6 -> V_17 . V_81 ) ;
F_107 ( V_6 -> V_18 . V_81 ) ;
}
static void F_108 ( T_3 * V_6 )
{
T_26 * V_116 , * V_117 ;
T_17 * V_118 ;
T_3 * V_119 ;
F_107 ( * V_6 -> V_17 . V_81 ) ;
* V_6 -> V_17 . V_81 = NULL ;
for ( V_118 = V_6 -> V_18 . V_81 ; V_118 != NULL ; V_118 = F_72 ( V_118 ) ) {
V_116 = ( T_26 * ) V_118 -> V_4 ;
V_117 = F_17 ( T_26 , 1 ) ;
V_117 -> V_29 = F_26 ( V_116 -> V_29 ) ;
V_117 -> V_108 = V_116 -> V_108 ;
if ( V_116 -> V_110 ) {
V_117 -> V_110 = F_26 ( V_116 -> V_110 ) ;
V_117 -> V_111 = V_116 -> V_111 ;
} else {
V_117 -> V_110 = NULL ;
V_117 -> V_111 = 0 ;
}
V_117 -> V_105 = V_116 -> V_105 ;
V_117 -> V_112 = V_116 -> V_112 ;
* V_6 -> V_17 . V_81 = F_43 ( * V_6 -> V_17 . V_81 , V_117 ) ;
}
V_119 = F_42 ( V_102 , V_120 ) ;
F_99 ( V_119 ) ;
}
static T_24 F_109 ( T_3 * V_6 , const T_13 * V_49 , T_6 * V_95 V_5 )
{
T_17 * V_121 , * V_122 ;
T_26 * V_100 ;
T_14 V_123 ;
T_3 * V_124 , * V_119 ;
V_121 = F_110 ( V_49 ) ;
if ( V_121 == NULL )
return V_125 ;
if ( ( F_111 ( V_121 ) % 2 ) != 0 ) {
F_112 ( V_121 ) ;
return V_125 ;
}
V_122 = F_71 ( V_121 ) ;
while( V_122 ) {
T_26 V_126 ;
V_122 = V_122 -> V_104 ;
if ( ! F_113 ( & V_126 , ( char * ) V_122 -> V_4 ) ) {
F_112 ( V_121 ) ;
return V_125 ;
}
if ( V_126 . V_108 != V_109 ) {
F_114 ( & V_122 -> V_4 ) ;
} else {
F_4 ( V_126 . V_110 ) ;
}
V_122 = V_122 -> V_104 ;
}
F_107 ( * V_6 -> V_17 . V_81 ) ;
* V_6 -> V_17 . V_81 = NULL ;
V_124 = F_42 ( V_102 , V_127 ) ;
V_119 = F_42 ( V_102 , V_120 ) ;
V_123 = F_111 ( V_121 ) ;
* V_119 -> V_17 . V_64 = V_123 / 2 ;
V_122 = F_71 ( V_121 ) ;
while( V_122 ) {
V_100 = F_17 ( T_26 , 1 ) ;
V_100 -> V_29 = F_26 ( ( T_13 * ) V_122 -> V_4 ) ;
V_122 = V_122 -> V_104 ;
F_113 ( V_100 , ( char * ) V_122 -> V_4 ) ;
V_100 -> V_105 = F_89 ( ( T_13 * ) ( * V_124 -> V_17 . string ) , V_100 ) ;
V_122 = V_122 -> V_104 ;
* V_6 -> V_17 . V_81 = F_43 ( * V_6 -> V_17 . V_81 , V_100 ) ;
}
F_112 ( V_121 ) ;
F_86 ( V_124 ) ;
return V_82 ;
}
static const char * F_115 ( void ) {
return L_24 ;
}
static char * F_116 ( void ) {
return F_26 ( L_25 ) ;
}
static T_6 F_117 ( T_3 * V_6 ) {
T_17 * V_99 = * V_6 -> V_17 . V_81 ,
* V_128 = F_71 ( V_99 ) ,
* V_129 = F_71 ( V_6 -> V_18 . V_81 ) ;
T_26 * V_100 , * V_130 ;
T_6 V_115 = TRUE ;
T_3 * V_119 ;
V_119 = F_42 ( V_102 , V_120 ) ;
if ( V_119 && * V_119 -> V_17 . V_64 != V_119 -> V_18 . V_64 ) {
V_115 = FALSE ;
} else {
while ( V_128 && V_129 ) {
V_100 = ( T_26 * ) V_128 -> V_4 ;
V_130 = ( T_26 * ) V_129 -> V_4 ;
if ( ( F_98 ( V_100 -> V_29 , V_130 -> V_29 ) != 0 ) ||
( V_100 -> V_108 != V_130 -> V_108 ) ||
( ( ( V_100 -> V_108 == V_109 ) && ( V_100 -> V_110 ) ) &&
( ( F_98 ( V_100 -> V_110 , V_130 -> V_110 ) != 0 ) ||
( V_100 -> V_112 != V_130 -> V_112 ) ) ) ) {
V_115 = FALSE ;
break;
}
V_128 = V_128 -> V_104 ;
V_129 = V_129 -> V_104 ;
}
}
return V_115 ;
}
static char * F_118 ( T_3 * V_6 , T_6 V_18 ) {
T_17 * V_131 = V_18 ? V_6 -> V_18 . V_81 : * V_6 -> V_17 . V_81 ;
T_17 * V_99 = F_71 ( V_131 ) ;
T_17 * V_121 ;
T_26 * V_100 ;
T_13 * V_107 ;
char * V_132 ;
V_121 = NULL ;
while ( V_99 ) {
V_100 = ( T_26 * ) V_99 -> V_4 ;
V_121 = F_43 ( V_121 , F_26 ( V_100 -> V_29 ) ) ;
if ( ( V_100 -> V_108 == V_109 ) && ( V_100 -> V_110 ) ) {
V_107 = F_83 ( L_22 ,
F_94 ( V_100 -> V_108 ) ,
V_100 -> V_110 ,
V_100 -> V_111 ,
V_100 -> V_112 ? 'R' : 'U' ) ;
} else {
V_107 = F_26 ( F_94 ( V_100 -> V_108 ) ) ;
}
V_121 = F_43 ( V_121 , V_107 ) ;
V_99 = V_99 -> V_104 ;
}
V_132 = F_119 ( V_121 ) ;
F_7 ( V_121 ) ;
return V_132 ;
}
static void F_120 ( T_3 * V_6 , T_17 * * V_49 )
{
T_17 * V_81 = * V_49 ,
* V_133 = NULL ;
T_13 * V_134 ;
V_6 -> V_17 . V_81 = V_49 ;
while ( V_81 ) {
V_134 = ( T_13 * ) V_81 -> V_4 ;
V_133 = F_43 ( V_133 , F_26 ( V_134 ) ) ;
V_81 = V_81 -> V_104 ;
}
V_6 -> V_18 . V_81 = V_133 ;
}
static void F_121 ( T_3 * V_6 )
{
T_17 * V_81 = * V_6 -> V_17 . V_81 ;
T_13 * V_135 ;
while ( V_81 != NULL ) {
V_135 = ( T_13 * ) V_81 -> V_4 ;
F_4 ( V_135 ) ;
V_81 = F_122 ( V_81 , V_81 ) ;
}
F_7 ( V_81 ) ;
V_81 = V_6 -> V_18 . V_81 ;
while ( V_81 != NULL ) {
V_135 = ( T_13 * ) V_81 -> V_4 ;
F_4 ( V_135 ) ;
V_81 = F_122 ( V_81 , V_81 ) ;
}
F_7 ( V_81 ) ;
}
static void F_123 ( T_3 * V_6 )
{
T_17 * V_133 = * V_6 -> V_17 . V_81 ,
* V_81 = V_6 -> V_18 . V_81 ;
T_13 * V_135 ;
while ( V_133 != NULL ) {
V_135 = ( T_13 * ) V_133 -> V_4 ;
F_4 ( V_135 ) ;
V_133 = F_122 ( V_133 , V_133 ) ;
}
while ( V_81 ) {
V_135 = ( T_13 * ) V_81 -> V_4 ;
V_133 = F_43 ( V_133 , F_26 ( V_135 ) ) ;
V_81 = V_81 -> V_104 ;
}
}
static T_24 F_124 ( T_3 * V_6 , const T_13 * V_49 , T_6 * V_95 V_5 )
{
T_17 * V_121 , * V_122 ;
T_13 * V_135 ;
V_121 = F_110 ( V_49 ) ;
if ( V_121 == NULL )
return V_125 ;
F_7 ( * V_6 -> V_17 . V_81 ) ;
* V_6 -> V_17 . V_81 = NULL ;
V_122 = F_71 ( V_121 ) ;
while( V_122 ) {
V_135 = ( T_13 * ) V_122 -> V_4 ;
* V_6 -> V_17 . V_81 = F_43 ( * V_6 -> V_17 . V_81 , V_135 ) ;
V_122 = V_122 -> V_104 ;
}
return V_82 ;
}
static const char * F_125 ( void ) {
return L_26 ;
}
static char * F_126 ( void ) {
return F_83 (
L_27
L_28 ) ;
}
static T_6 F_127 ( T_3 * V_6 ) {
T_17 * V_99 = * V_6 -> V_17 . V_81 ,
* V_128 = F_71 ( V_99 ) ,
* V_129 = F_71 ( V_6 -> V_18 . V_81 ) ;
T_13 * V_134 , * V_136 ;
T_6 V_115 = TRUE ;
while ( V_128 && V_129 ) {
V_134 = ( T_13 * ) V_128 -> V_4 ;
V_136 = ( T_13 * ) V_129 -> V_4 ;
if ( strcmp ( V_134 , V_136 ) != 0 ) {
V_115 = FALSE ;
break;
}
V_128 = V_128 -> V_104 ;
V_129 = V_129 -> V_104 ;
}
if ( ( ( V_128 == NULL ) && ( V_129 != NULL ) ) ||
( ( V_128 != NULL ) && ( V_129 == NULL ) ) )
V_115 = FALSE ;
return V_115 ;
}
static char * F_128 ( T_3 * V_6 , T_6 V_18 ) {
T_17 * V_131 = V_18 ? V_6 -> V_18 . V_81 : * V_6 -> V_17 . V_81 ;
T_17 * V_99 = F_71 ( V_131 ) ;
T_17 * V_121 = NULL ;
T_13 * V_134 , * V_137 ;
while ( V_99 ) {
V_134 = ( T_13 * ) V_99 -> V_4 ;
V_121 = F_43 ( V_121 , F_26 ( V_134 ) ) ;
V_99 = V_99 -> V_104 ;
}
V_137 = F_119 ( V_121 ) ;
F_7 ( V_121 ) ;
return V_137 ;
}
static void F_129 ( T_3 * V_6 )
{
F_4 ( ( char * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = NULL ;
F_4 ( V_6 -> V_18 . string ) ;
V_6 -> V_18 . string = NULL ;
}
static void F_130 ( T_3 * V_6 )
{
F_4 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_26 ( V_6 -> V_18 . string ) ;
}
static T_24 F_131 ( T_3 * V_6 , const T_13 * V_49 , T_6 * V_95 )
{
if ( strcmp ( * V_6 -> V_17 . string , V_49 ) != 0 ) {
* V_95 = TRUE ;
F_4 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_26 ( V_49 ) ;
}
return V_82 ;
}
static const char * F_132 ( void ) {
return NULL ;
}
static char * F_133 ( void ) {
return F_26 ( L_7 ) ;
}
static T_6 F_134 ( T_3 * V_6 V_5 ) {
return TRUE ;
}
static char * F_135 ( T_3 * V_6 V_5 , T_6 V_18 V_5 ) {
return F_26 ( L_7 ) ;
}
void
F_20 ( void )
{
T_5 * V_138 , * V_139 , * V_140 ,
* V_141 , * V_142 ;
struct V_66 V_22 ;
if ( V_41 != NULL ) {
return;
}
F_136 () ;
V_143 = F_10 ( NULL , L_29 , L_30 ,
L_30 , & F_75 , FALSE ) ;
F_66 ( V_143 , L_31 ) ;
F_66 ( V_143 , L_32 ) ;
F_66 ( V_143 , L_33 ) ;
F_51 ( V_143 , L_34 ,
L_35 ,
L_36 ,
& V_25 . V_144 ) ;
F_51 ( V_143 , L_37 ,
L_38 ,
L_39 ,
& V_25 . V_145 ) ;
F_51 ( V_143 , L_40 ,
L_41 ,
L_42 ,
& V_25 . V_146 ) ;
F_52 ( V_143 , L_43 ,
L_44 ,
L_44 ,
& V_25 . V_147 , V_147 , FALSE ) ;
F_52 ( V_143 , L_45 ,
L_46 ,
L_46 ,
& V_25 . V_148 , V_148 , FALSE ) ;
F_52 ( V_143 , L_47 ,
L_48 ,
L_48 ,
& V_25 . V_149 , V_149 , FALSE ) ;
V_102 = F_13 ( V_143 , L_49 , L_49 , NULL ) ;
V_22 . V_23 = F_86 ;
V_22 . V_150 = F_87 ;
V_22 . V_151 = F_88 ;
V_22 . V_152 = F_90 ;
V_22 . V_153 = F_91 ;
V_22 . V_154 = F_97 ;
V_22 . V_155 = F_92 ;
F_55 ( V_102 , V_127 , L_20 ,
L_50 , & V_22 , ( const char * * ) & V_156 ) ;
V_22 . V_23 = F_106 ;
V_22 . V_150 = F_108 ;
V_22 . V_151 = F_109 ;
V_22 . V_152 = F_115 ;
V_22 . V_153 = F_116 ;
V_22 . V_154 = F_117 ;
V_22 . V_155 = F_118 ;
F_64 ( V_102 , V_103 , L_24 ,
L_25 , & V_22 ,
F_105 , & V_25 . V_157 ) ;
V_22 . V_23 = F_77 ;
V_22 . V_150 = F_99 ;
V_22 . V_151 = F_100 ;
V_22 . V_152 = F_101 ;
V_22 . V_153 = F_102 ;
V_22 . V_154 = F_103 ;
V_22 . V_155 = F_104 ;
F_50 ( V_102 , V_120 , L_51 ,
L_52 , & V_22 , & V_25 . V_158 ) ;
V_142 = F_13 ( V_143 , L_53 , L_53 , NULL ) ;
F_66 ( V_142 , L_54 ) ;
F_54 ( V_142 , L_55 , L_56 ,
L_57 , ( const char * * ) ( & V_25 . V_159 ) ) ;
F_54 ( V_142 , L_58 , L_56 ,
L_59 , ( const char * * ) ( & V_25 . V_160 ) ) ;
V_161 = F_13 ( V_143 , L_60 , L_60 , NULL ) ;
F_63 ( V_161 , L_61 , L_62 ,
L_62 , & V_25 . V_162 ) ;
F_63 ( V_161 , L_63 , L_62 ,
L_62 , & V_25 . V_163 ) ;
F_63 ( V_161 , L_64 , L_65 ,
L_65 , & V_25 . V_164 ) ;
F_63 ( V_161 , L_66 , L_65 ,
L_65 , & V_25 . V_165 ) ;
F_63 ( V_161 , L_67 , L_68 ,
L_68 , & V_25 . V_166 ) ;
F_63 ( V_161 , L_69 , L_68 ,
L_68 , & V_25 . V_167 ) ;
F_63 ( V_161 , L_70 , L_68 ,
L_68 , & V_25 . V_168 ) ;
F_63 ( V_161 , L_71 , L_68 ,
L_68 , & V_25 . V_169 ) ;
V_22 . V_23 = F_129 ;
V_22 . V_150 = F_130 ;
V_22 . V_151 = F_131 ;
V_22 . V_152 = F_132 ;
V_22 . V_153 = F_133 ;
V_22 . V_154 = F_134 ;
V_22 . V_155 = F_135 ;
F_55 ( V_102 , L_72 , L_73 ,
L_74 , & V_22 , ( const char * * ) & V_25 . V_170 ) ;
V_22 . V_23 = F_129 ;
V_22 . V_150 = F_130 ;
V_22 . V_151 = F_131 ;
V_22 . V_152 = F_132 ;
V_22 . V_153 = F_133 ;
V_22 . V_154 = F_134 ;
V_22 . V_155 = F_135 ;
F_55 ( V_102 , L_75 , L_76 ,
L_77 , & V_22 , ( const char * * ) & V_25 . V_171 ) ;
F_52 ( V_143 , L_78 ,
L_79 ,
L_80 ,
( T_14 * ) ( void * ) ( & V_25 . V_172 ) , V_173 , FALSE ) ;
F_52 ( V_143 , L_81 ,
L_82 ,
L_82 ,
& V_25 . V_174 , V_174 , FALSE ) ;
F_49 ( V_143 , L_83 ,
L_84 ,
L_84 ,
10 ,
& V_25 . V_89 ) ;
F_49 ( V_143 , L_85 ,
L_86 ,
L_86 ,
10 ,
& V_25 . V_90 ) ;
F_57 ( V_143 , L_87 , L_88 ,
L_89 , ( const char * * ) ( & V_25 . V_175 ) ) ;
F_66 ( V_143 , L_90 ) ;
F_49 ( V_143 , L_91 ,
L_92 ,
L_92 ,
10 ,
& V_25 . V_176 ) ;
F_51 ( V_143 , L_93 ,
L_94 ,
L_95 ,
& V_25 . V_177 ) ;
F_51 ( V_143 , L_96 ,
L_97 ,
L_98 ,
& V_25 . V_178 ) ;
F_51 ( V_143 , L_99 ,
L_100 ,
L_101 ,
& V_25 . V_179 ) ;
F_51 ( V_143 , L_102 ,
L_103 ,
L_104 ,
& V_25 . V_180 ) ;
F_51 ( V_143 , L_105 ,
L_106 ,
L_107 ,
& V_25 . V_181 ) ;
F_51 ( V_143 , L_108 ,
L_109 ,
L_110 ,
& V_25 . V_182 ) ;
F_51 ( V_143 , L_111 ,
L_112 ,
L_113 ,
& V_25 . V_183 ) ;
F_66 ( V_143 , L_114 ) ;
F_66 ( V_143 , L_115 ) ;
F_66 ( V_143 , L_116 ) ;
F_66 ( V_143 , L_117 ) ;
F_66 ( V_143 , L_118 ) ;
F_52 ( V_143 , L_119 ,
L_120 ,
L_120 ,
& V_25 . V_184 , V_185 , FALSE ) ;
F_52 ( V_143 , L_121 ,
L_122 ,
L_122 ,
& V_25 . V_186 , V_185 , FALSE ) ;
F_54 ( V_143 , L_123 , L_124 ,
L_125 , ( const char * * ) ( & V_25 . V_187 ) ) ;
F_51 ( V_143 , L_126 ,
L_127 ,
L_128 ,
& V_25 . V_188 ) ;
F_52 ( V_143 , L_129 ,
L_130 ,
L_131 ,
( T_14 * ) ( void * ) ( & V_25 . V_189 ) , V_189 , FALSE ) ;
F_49 ( V_143 , L_132 ,
L_133 ,
L_134 ,
10 ,
& V_25 . V_190 ) ;
F_54 ( V_143 , L_135 , L_136 ,
L_137 , ( const char * * ) ( & V_25 . V_191 ) ) ;
F_54 ( V_143 , L_138 , L_139 ,
L_139 , ( const char * * ) ( & V_25 . V_192 ) ) ;
F_52 ( V_143 , L_140 ,
L_141 ,
L_141 ,
( T_14 * ) ( void * ) ( & V_25 . V_193 ) , V_194 , FALSE ) ;
F_51 ( V_143 , L_142 ,
L_143 ,
L_143 ,
& V_25 . V_195 ) ;
F_49 ( V_143 , L_144 ,
L_145 ,
L_145 ,
10 ,
& V_25 . V_196 ) ;
V_141 = F_13 ( V_143 , L_146 , L_146 , F_76 ) ;
F_49 ( V_141 , L_147 ,
L_148 ,
L_149 ,
10 ,
( T_4 * ) ( void * ) ( & V_25 . V_91 ) ) ;
F_52 ( V_141 , L_150 ,
L_151 ,
L_151 ,
( T_14 * ) ( void * ) ( & V_25 . V_197 ) , V_198 , FALSE ) ;
F_52 ( V_141 , L_152 ,
L_153 ,
L_153 ,
( T_14 * ) ( void * ) ( & V_25 . V_199 ) , V_198 , FALSE ) ;
F_52 ( V_141 , L_154 ,
L_155 ,
L_155 ,
( T_14 * ) ( void * ) ( & V_25 . V_200 ) , V_198 , FALSE ) ;
V_140 = F_10 ( NULL , L_156 , L_157 ,
L_158 , NULL , FALSE ) ;
V_22 . V_23 = F_77 ;
V_22 . V_150 = F_78 ;
V_22 . V_151 = F_79 ;
V_22 . V_152 = F_81 ;
V_22 . V_153 = F_82 ;
V_22 . V_154 = F_84 ;
V_22 . V_155 = F_85 ;
F_50 ( V_140 , L_159 , L_160 ,
L_161 , & V_22 , & V_25 . V_201 ) ;
V_139 = F_10 ( NULL , L_162 , L_163 ,
L_164 , NULL , FALSE ) ;
F_54 ( V_139 , L_165 , L_166 ,
L_166 , ( const char * * ) ( & V_25 . V_202 ) ) ;
F_54 ( V_139 , L_167 , L_168 ,
L_169 ,
( const char * * ) ( & V_25 . V_203 ) ) ;
F_54 ( V_139 , L_170 , L_171 ,
L_172 ,
( const char * * ) ( & V_25 . V_204 ) ) ;
F_54 ( V_139 , L_173 , L_174 ,
L_175 , ( const char * * ) ( & V_25 . V_205 ) ) ;
F_54 ( V_139 , L_176 , L_177 ,
L_178 ,
( const char * * ) ( & V_25 . V_206 ) ) ;
#if F_137 ( V_207 ) || F_137 ( V_208 )
F_54 ( V_139 , L_179 , L_180 ,
L_181 ,
( const char * * ) ( & V_25 . V_209 ) ) ;
#endif
F_54 ( V_139 , L_182 , L_183 ,
L_184 ,
( const char * * ) ( & V_25 . V_210 ) ) ;
F_54 ( V_139 , L_185 , L_186 ,
L_187 ,
( const char * * ) ( & V_25 . V_211 ) ) ;
F_51 ( V_139 , L_188 , L_189 ,
L_190 , & V_25 . V_212 ) ;
F_51 ( V_139 , L_191 , L_192 ,
L_193 , & V_25 . V_213 ) ;
F_51 ( V_139 , L_194 , L_195 ,
L_196 , & V_25 . V_214 ) ;
F_51 ( V_139 , L_197 , L_198 ,
L_199 , & V_25 . V_215 ) ;
F_51 ( V_139 , L_200 , L_201 ,
L_202 , & V_25 . V_216 ) ;
F_66 ( V_139 , L_203 ) ;
V_22 . V_23 = F_121 ;
V_22 . V_150 = F_123 ;
V_22 . V_151 = F_124 ;
V_22 . V_152 = F_125 ;
V_22 . V_153 = F_126 ;
V_22 . V_154 = F_127 ;
V_22 . V_155 = F_128 ;
F_64 ( V_139 , L_204 , L_205 ,
L_206 , & V_22 , F_120 , & V_25 . V_217 ) ;
V_218 = F_10 ( NULL , L_207 , L_208 ,
L_208 , NULL , TRUE ) ;
F_138 ( V_218 ) ;
F_139 ( V_218 ) ;
#ifdef F_140
F_141 ( V_218 ) ;
#endif
V_138 = F_10 ( NULL , L_209 , L_210 ,
L_210 , NULL , TRUE ) ;
F_52 ( V_138 , L_211 ,
L_212 , L_213 ,
& V_25 . V_219 , V_220 , TRUE ) ;
F_52 ( V_138 , L_214 ,
L_215 , L_216 ,
& V_25 . V_221 , V_222 , TRUE ) ;
#ifndef V_207
F_54 ( V_138 , L_217 , L_218 ,
L_219 , ( const char * * ) ( & V_25 . V_223 ) ) ;
#endif
F_56 ( V_138 , L_220 , L_221 ,
L_222 , ( const char * * ) ( & V_25 . V_224 ) ) ;
V_48 = F_10 ( NULL , L_223 , L_224 ,
L_224 , & F_73 , TRUE ) ;
F_49 ( V_48 , L_225 ,
L_226 ,
L_227 ,
10 ,
& V_25 . V_85 ) ;
#ifdef F_74
F_49 ( V_48 , L_228 ,
L_229 ,
L_230 ,
10 ,
& V_25 . V_87 ) ;
#endif
V_41 = F_10 ( NULL , L_231 , L_232 ,
L_232 , NULL , TRUE ) ;
F_51 ( V_41 , L_233 ,
L_234 ,
L_235 ,
& V_25 . V_225 ) ;
F_10 ( NULL , L_236 , L_237 , L_237 , NULL , FALSE ) ;
F_10 ( NULL , L_238 , L_239 , L_239 , NULL , FALSE ) ;
F_10 ( NULL , L_240 , L_241 , L_241 , NULL , FALSE ) ;
}
T_17 *
F_110 ( const T_13 * V_226 )
{
enum { V_227 , V_228 , V_229 };
T_14 V_230 = V_227 , V_231 = 0 , V_232 = 0 ;
T_6 V_233 = FALSE ;
T_7 V_234 ;
T_13 * V_235 = NULL ;
T_17 * V_236 = NULL ;
V_235 = ( T_13 * ) F_142 ( sizeof( T_13 ) * V_237 ) ;
V_232 = 0 ;
for (; ; ) {
V_234 = V_226 [ V_231 ] ;
if ( V_234 == '\0' ) {
if ( V_230 == V_228 || V_233 ) {
F_4 ( V_235 ) ;
F_112 ( V_236 ) ;
return NULL ;
}
V_235 [ V_232 ] = '\0' ;
V_236 = F_43 ( V_236 , V_235 ) ;
break;
}
if ( V_234 == '"' && ! V_233 ) {
switch ( V_230 ) {
case V_227 :
V_230 = V_228 ;
break;
case V_228 :
V_230 = V_229 ;
break;
case V_229 :
V_230 = V_228 ;
break;
default:
break;
}
} else if ( V_234 == '\\' && ! V_233 ) {
V_233 = TRUE ;
if ( V_230 == V_227 )
V_230 = V_229 ;
} else if ( V_234 == ',' && V_230 != V_228 && ! V_233 ) {
V_235 [ V_232 ] = '\0' ;
V_236 = F_43 ( V_236 , V_235 ) ;
V_230 = V_227 ;
V_235 = ( T_13 * ) F_142 ( sizeof( T_13 ) * V_237 ) ;
V_232 = 0 ;
} else if ( ! isspace ( V_234 ) || V_230 != V_227 ) {
if ( V_232 < V_237 ) {
V_235 [ V_232 ] = V_234 ;
V_232 ++ ;
}
V_233 = FALSE ;
}
V_231 ++ ;
}
return ( V_236 ) ;
}
static char *
F_119 ( T_17 * V_236 )
{
T_27 * V_238 = F_93 ( L_7 ) ;
T_17 * V_239 , * V_240 ;
T_13 * V_226 ;
T_13 * V_241 ;
T_4 V_242 = 0 ;
V_239 = V_240 = F_71 ( V_236 ) ;
while ( V_239 ) {
V_242 ++ ;
V_226 = ( T_13 * ) V_239 -> V_4 ;
if ( V_239 != V_240 ) {
F_143 ( V_238 , ',' ) ;
}
if ( V_242 % 2 ) {
F_95 ( V_238 , L_242 ) ;
} else {
F_143 ( V_238 , ' ' ) ;
}
V_241 = F_144 ( V_226 , L_7 ) ;
F_145 ( V_238 , L_243 , V_241 ) ;
F_4 ( V_241 ) ;
V_239 = V_239 -> V_104 ;
}
return F_96 ( V_238 , FALSE ) ;
}
void
F_112 ( T_17 * V_236 )
{
T_17 * V_243 = V_236 ;
while ( V_243 ) {
F_4 ( V_243 -> V_4 ) ;
V_243 = F_122 ( V_243 , V_243 ) ;
}
}
static T_14
F_146 ( const char * V_244 , const T_18 * V_245 ,
T_14 V_246 )
{
int V_231 ;
for ( V_231 = 0 ; V_245 [ V_231 ] . V_28 != NULL ; V_231 ++ ) {
if ( F_147 ( V_244 , V_245 [ V_231 ] . V_28 ) == 0 ) {
return V_245 [ V_231 ] . V_49 ;
}
}
for ( V_231 = 0 ; V_245 [ V_231 ] . V_28 != NULL ; V_231 ++ ) {
if ( F_147 ( V_244 , V_245 [ V_231 ] . V_30 ) == 0 ) {
return V_245 [ V_231 ] . V_49 ;
}
}
return V_246 ;
}
static T_6
F_113 ( T_26 * V_100 , const char * V_108 )
{
const T_13 * V_247 = F_94 ( V_109 ) ;
T_28 V_248 = strlen ( V_247 ) ;
T_13 * * V_249 ;
char * V_33 ;
int V_250 ;
T_13 * V_251 ;
long V_252 ;
T_6 V_253 ;
if ( ( strlen ( V_108 ) > V_248 ) && ( V_108 [ V_248 ] == ':' ) &&
strncmp ( V_108 , V_247 , V_248 ) == 0 ) {
V_250 = V_109 ;
V_249 = F_148 ( & V_108 [ V_248 + 1 ] , L_244 , 3 ) ;
V_251 = F_26 ( V_249 [ 0 ] ) ;
if ( V_251 && V_249 [ 1 ] ) {
V_252 = strtol ( V_249 [ 1 ] , & V_33 , 10 ) ;
if ( V_33 == V_249 [ 1 ] || * V_33 != '\0' ) {
F_4 ( V_251 ) ;
F_149 ( V_249 ) ;
return FALSE ;
}
} else {
V_252 = 0 ;
}
if ( V_251 && V_249 [ 1 ] && V_249 [ 2 ] ) {
V_253 = ( V_249 [ 2 ] [ 0 ] == 'U' ) ? FALSE : TRUE ;
} else {
V_253 = TRUE ;
}
F_149 ( V_249 ) ;
} else {
V_250 = F_150 ( V_108 ) ;
if ( V_250 == - 1 )
return FALSE ;
V_251 = NULL ;
V_252 = 0 ;
V_253 = TRUE ;
}
V_100 -> V_108 = V_250 ;
V_100 -> V_110 = V_251 ;
V_100 -> V_111 = ( int ) V_252 ;
V_100 -> V_112 = V_253 ;
return TRUE ;
}
static void
F_151 ( void )
{
if ( V_254 )
return;
F_152 () ;
F_136 () ;
F_153 ( TRUE ) ;
V_254 = TRUE ;
}
static void
F_136 ( void )
{
int V_231 ;
T_13 * V_135 ;
T_26 * V_100 ;
static const T_13 * V_250 [ V_255 * 2 ] = {
L_245 , L_246 , L_247 , L_248 ,
L_249 , L_250 , L_251 , L_252 ,
L_253 , L_254 , L_255 , L_256 ,
L_257 , L_258 } ;
#if F_137 ( V_208 )
static T_14 V_256 = 7 ;
static const T_13 * V_257 [ 7 ] = {
L_259 ,
L_260 ,
L_261 ,
L_262 ,
L_263 ,
L_264 ,
L_265 } ;
#elif F_137 ( V_207 ) && ! F_137 ( V_208 )
static T_14 V_256 = 6 ;
static const T_13 * V_257 [ 6 ] = {
L_259 ,
L_260 ,
L_261 ,
L_262 ,
L_264 ,
L_265 } ;
#else
static T_14 V_256 = 5 ;
static const T_13 * V_257 [ 5 ] = {
L_259 ,
L_260 ,
L_261 ,
L_262 ,
L_265 } ;
#endif
if ( V_258 )
return;
V_25 . V_219 = V_259 ;
V_25 . V_221 = V_260 ;
V_25 . V_224 = L_266 ;
V_25 . V_223 = L_267 ;
V_25 . V_144 = FALSE ;
V_25 . V_145 = FALSE ;
V_25 . V_147 = 0 ;
V_25 . V_148 = 1 ;
V_25 . V_149 = 1 ;
V_25 . V_146 = FALSE ;
V_25 . V_184 = V_261 ;
V_25 . V_186 = V_262 ;
#ifdef V_207
V_25 . V_159 = F_26 ( L_268 ) ;
#else
V_25 . V_159 = F_26 ( L_269 ) ;
#endif
V_25 . V_160 = F_26 ( L_7 ) ;
V_25 . V_162 . V_263 = 65535 ;
V_25 . V_162 . V_264 = 65535 ;
V_25 . V_162 . V_265 = 65535 ;
V_25 . V_162 . V_266 = 65535 ;
V_25 . V_163 . V_263 = 0 ;
V_25 . V_163 . V_264 = 0 ;
V_25 . V_163 . V_265 = 8224 ;
V_25 . V_163 . V_266 = 10794 ;
V_25 . V_164 . V_263 = 32767 ;
V_25 . V_164 . V_264 = 32767 ;
V_25 . V_164 . V_265 = 32767 ;
V_25 . V_164 . V_266 = 32767 ;
V_25 . V_165 . V_263 = 65535 ;
V_25 . V_165 . V_264 = 65535 ;
V_25 . V_165 . V_265 = 65535 ;
V_25 . V_165 . V_266 = 65535 ;
V_25 . V_170 = L_270 ;
V_25 . V_171 = L_271 ;
V_25 . V_166 . V_263 = 0 ;
V_25 . V_166 . V_264 = 32767 ;
V_25 . V_166 . V_265 = 0 ;
V_25 . V_166 . V_266 = 0 ;
V_25 . V_167 . V_263 = 0 ;
V_25 . V_167 . V_264 = 64507 ;
V_25 . V_167 . V_265 = 60909 ;
V_25 . V_167 . V_266 = 60909 ;
V_25 . V_168 . V_263 = 0 ;
V_25 . V_168 . V_264 = 0 ;
V_25 . V_168 . V_265 = 0 ;
V_25 . V_168 . V_266 = 32767 ;
V_25 . V_169 . V_263 = 0 ;
V_25 . V_169 . V_264 = 60909 ;
V_25 . V_169 . V_265 = 60909 ;
V_25 . V_169 . V_266 = 64507 ;
V_25 . V_180 = TRUE ;
V_25 . V_181 = TRUE ;
V_25 . V_182 = TRUE ;
V_25 . V_183 = TRUE ;
V_25 . V_172 = V_267 ;
V_25 . V_174 = V_268 ;
V_25 . V_90 = 10 ;
V_25 . V_89 = 10 ;
V_25 . V_175 = F_27 ( F_28 () , F_154 () ) ;
V_25 . V_176 = 3 ;
V_25 . V_177 = TRUE ;
V_25 . V_178 = TRUE ;
V_25 . V_179 = FALSE ;
V_25 . V_188 = TRUE ;
V_25 . V_189 = V_269 ;
V_25 . V_190 = 60 * 60 * 24 ;
V_25 . V_187 = F_26 ( V_270 L_272 ) ;
V_25 . V_191 = F_26 ( L_7 ) ;
V_25 . V_192 = L_273 ;
V_25 . V_193 = V_271 ;
V_25 . V_195 = FALSE ;
V_25 . V_196 = 0 ;
V_25 . V_91 = V_94 ;
V_25 . V_197 = V_272 ;
V_25 . V_199 = V_273 ;
V_25 . V_200 = V_274 ;
V_25 . V_157 = NULL ;
for ( V_231 = 0 ; V_231 < V_255 ; V_231 ++ ) {
V_100 = F_17 ( T_26 , 1 ) ;
V_100 -> V_29 = F_26 ( V_250 [ V_231 * 2 ] ) ;
F_113 ( V_100 , V_250 [ ( V_231 * 2 ) + 1 ] ) ;
V_100 -> V_105 = TRUE ;
V_100 -> V_112 = TRUE ;
V_100 -> V_110 = NULL ;
V_100 -> V_111 = 0 ;
V_25 . V_157 = F_43 ( V_25 . V_157 , V_100 ) ;
}
V_25 . V_158 = V_255 ;
V_25 . V_212 = TRUE ;
#ifdef F_155
V_25 . V_213 = TRUE ;
#else
V_25 . V_213 = FALSE ;
#endif
V_25 . V_214 = TRUE ;
V_25 . V_215 = TRUE ;
V_25 . V_216 = FALSE ;
V_25 . V_217 = NULL ;
for ( V_231 = 0 ; V_231 < V_256 ; V_231 ++ ) {
V_135 = F_26 ( V_257 [ V_231 ] ) ;
V_25 . V_217 = F_43 ( V_25 . V_217 , V_135 ) ;
}
V_25 . V_201 =
V_275 | V_276 | V_277 ;
V_25 . V_85 = V_86 ;
V_25 . V_87 = V_88 ;
V_25 . V_225 = FALSE ;
V_258 = TRUE ;
}
static void
F_156 ( T_3 * V_6 )
{
if ( ! V_6 ) return;
switch ( V_6 -> type ) {
case V_10 :
* V_6 -> V_17 . V_64 = V_6 -> V_18 . V_64 ;
break;
case V_8 :
* V_6 -> V_17 . V_67 = V_6 -> V_18 . V_68 ;
break;
case V_9 :
* V_6 -> V_17 . V_71 = V_6 -> V_18 . V_72 ;
break;
case V_14 :
case V_15 :
case V_16 :
F_4 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_26 ( V_6 -> V_18 . string ) ;
break;
case V_19 :
F_4 ( * V_6 -> V_17 . V_20 ) ;
* V_6 -> V_17 . V_20 = F_60 ( V_6 -> V_18 . V_20 ) ;
break;
case V_11 :
case V_12 :
break;
case V_13 :
* V_6 -> V_17 . V_79 = V_6 -> V_18 . V_78 ;
break;
case V_21 :
V_6 -> V_22 . V_150 ( V_6 ) ;
break;
case V_7 :
break;
}
}
static void
F_157 ( T_1 V_4 , T_1 T_2 V_5 )
{
T_3 * V_6 = ( T_3 * ) V_4 ;
F_156 ( V_6 ) ;
}
static T_6
F_158 ( void * V_49 , void * V_4 V_5 )
{
T_29 V_59 ;
V_59 . V_24 = ( T_5 * ) V_49 ;
F_6 ( V_59 . V_24 -> V_25 , F_157 , & V_59 ) ;
return FALSE ;
}
void
F_159 ( void )
{
V_254 = FALSE ;
F_160 () ;
F_161 () ;
F_151 () ;
F_34 ( V_1 , F_158 , NULL ) ;
}
T_30 *
F_162 ( int * V_278 , int * V_279 ,
char * * V_280 , int * V_281 ,
int * V_282 , char * * V_283 )
{
int V_284 ;
char * V_285 ;
T_31 * V_286 ;
F_161 () ;
F_151 () ;
if ( V_287 == NULL ) {
V_287 = F_163 ( V_288 ) ;
if ( ( V_286 = F_164 ( V_287 , L_274 ) ) == NULL && V_289 == V_290 ) {
F_4 ( V_287 ) ;
V_287 = F_163 ( V_291 ) ;
V_286 = F_164 ( V_287 , L_274 ) ;
}
} else {
V_286 = F_164 ( V_287 , L_274 ) ;
}
* V_280 = NULL ;
if ( V_286 != NULL ) {
V_292 = 0 ;
V_293 = 0 ;
V_284 = F_165 ( V_287 , V_286 , V_294 , NULL ) ;
if ( V_284 != 0 ) {
* V_278 = 0 ;
* V_279 = V_284 ;
* V_280 = V_287 ;
}
fclose ( V_286 ) ;
} else {
if ( V_289 != V_290 ) {
* V_278 = V_289 ;
* V_279 = 0 ;
* V_280 = V_287 ;
}
}
V_285 = F_166 ( V_288 , TRUE ) ;
* V_283 = NULL ;
if ( ( V_286 = F_164 ( V_285 , L_274 ) ) != NULL ) {
V_292 = 0 ;
V_293 = 0 ;
V_284 = F_165 ( V_285 , V_286 , V_294 , NULL ) ;
if ( V_284 != 0 ) {
* V_281 = 0 ;
* V_282 = V_284 ;
* V_283 = V_285 ;
} else
F_4 ( V_285 ) ;
fclose ( V_286 ) ;
} else {
if ( V_289 != V_290 ) {
* V_281 = V_289 ;
* V_282 = 0 ;
* V_283 = V_285 ;
} else
F_4 ( V_285 ) ;
}
F_167 () ;
return & V_25 ;
}
int
F_165 ( const char * V_285 , T_31 * V_286 ,
T_32 V_295 , void * V_296 )
{
enum { V_297 , V_298 , V_299 , V_300 , V_301 };
int V_302 , V_230 = V_297 ;
T_27 * V_303 ;
T_27 * V_304 ;
T_6 V_305 = FALSE ;
T_14 V_306 = 1 , V_307 = 1 ;
T_13 V_308 [] = L_275 ;
V_303 = F_93 ( L_7 ) ;
V_304 = F_93 ( L_7 ) ;
while ( ( V_302 = getc ( V_286 ) ) != V_309 ) {
if ( V_302 == '\n' ) {
V_230 = V_297 ;
V_306 ++ ;
continue;
}
switch ( V_230 ) {
case V_297 :
if ( isalnum ( V_302 ) ) {
if ( V_304 -> V_113 > 0 ) {
if ( V_305 ) {
switch ( V_295 ( V_304 -> V_226 , V_303 -> V_226 , V_296 , FALSE ) ) {
case V_82 :
break;
case V_125 :
F_168 ( L_276 , V_285 , V_307 , V_304 -> V_226 , V_308 ) ;
break;
case V_83 :
F_168 ( L_277 , V_285 ,
V_307 , V_304 -> V_226 , V_308 ) ;
break;
case V_310 :
break;
}
} else {
F_168 ( L_278 , V_285 , V_307 , V_308 ) ;
}
}
V_230 = V_298 ;
V_305 = FALSE ;
F_169 ( V_304 , 0 ) ;
F_143 ( V_304 , ( T_13 ) V_302 ) ;
V_307 = V_306 ;
} else if ( isspace ( V_302 ) && V_304 -> V_113 > 0 && V_305 ) {
V_230 = V_299 ;
} else if ( V_302 == '#' ) {
V_230 = V_301 ;
} else {
F_168 ( L_279 , V_285 , V_306 , V_308 ) ;
}
break;
case V_298 :
if ( V_302 != ':' ) {
F_143 ( V_304 , ( T_13 ) V_302 ) ;
} else {
V_230 = V_299 ;
F_169 ( V_303 , 0 ) ;
V_305 = TRUE ;
}
break;
case V_299 :
if ( ! isspace ( V_302 ) ) {
V_230 = V_300 ;
F_143 ( V_303 , ( T_13 ) V_302 ) ;
}
break;
case V_300 :
F_143 ( V_303 , ( T_13 ) V_302 ) ;
break;
}
}
if ( V_304 -> V_113 > 0 ) {
if ( V_305 ) {
switch ( V_295 ( V_304 -> V_226 , V_303 -> V_226 , V_296 , FALSE ) ) {
case V_82 :
break;
case V_125 :
F_168 ( L_276 , V_285 , V_307 , V_304 -> V_226 , V_308 ) ;
break;
case V_83 :
F_168 ( L_277 , V_285 ,
V_307 , V_304 -> V_226 , V_308 ) ;
break;
case V_310 :
break;
}
} else {
F_168 ( L_278 , V_285 , V_307 , V_308 ) ;
}
}
F_96 ( V_303 , TRUE ) ;
F_96 ( V_304 , TRUE ) ;
if ( ferror ( V_286 ) )
return V_289 ;
else
return 0 ;
}
static T_6
F_170 ( char * V_311 ) {
T_13 * V_33 , * V_312 ;
T_33 * V_77 ;
T_13 * V_284 ;
V_312 = strchr ( V_311 , ':' ) ;
if ( V_312 == NULL )
return FALSE ;
V_33 = V_312 ;
* V_33 ++ = '\0' ;
while ( isspace ( ( T_7 ) * V_33 ) )
V_33 ++ ;
if ( * V_33 == '\0' ) {
* V_312 = ':' ;
return FALSE ;
}
V_77 = F_171 ( V_311 ) ;
* V_312 = ':' ;
if ( V_77 == NULL ) {
return FALSE ;
}
if ( F_172 ( V_77 , V_33 , & V_284 ) ) {
return TRUE ;
}
return FALSE ;
}
T_24
F_173 ( char * V_313 )
{
T_13 * V_33 , * V_312 ;
T_24 V_51 ;
V_292 = - 1 ;
V_293 = - 1 ;
V_312 = strchr ( V_313 , ':' ) ;
if ( V_312 == NULL )
return V_125 ;
V_33 = V_312 ;
* V_33 ++ = '\0' ;
while ( isspace ( ( T_7 ) * V_33 ) )
V_33 ++ ;
if ( * V_33 == '\0' ) {
* V_312 = ':' ;
return V_125 ;
}
if ( strcmp ( V_313 , L_280 ) ) {
V_51 = V_294 ( V_313 , V_33 , NULL , TRUE ) ;
} else {
V_51 = F_170 ( V_33 ) ? V_82 : V_125 ;
}
* V_312 = ':' ;
return V_51 ;
}
T_6
F_174 ( const char * V_28 )
{
T_13 * V_314 , * V_315 ;
T_28 V_113 ;
if ( V_25 . V_205 && V_28 ) {
V_315 = F_26 ( V_25 . V_205 ) ;
V_113 = strlen ( V_28 ) ;
for ( V_314 = strtok ( V_315 , L_23 ) ; V_314 ; V_314 = strtok ( NULL , L_23 ) ) {
if ( strlen ( V_314 ) == V_113 && strcmp ( V_28 , V_314 ) == 0 ) {
F_4 ( V_315 ) ;
return TRUE ;
}
}
F_4 ( V_315 ) ;
}
return FALSE ;
}
static T_6
F_89 ( const T_13 * V_106 , T_26 * V_100 )
{
T_13 * V_314 , * V_316 ;
T_26 V_317 ;
if ( V_106 ) {
V_316 = F_26 ( V_106 ) ;
for ( V_314 = strtok ( V_316 , L_23 ) ; V_314 ; V_314 = strtok ( NULL , L_23 ) ) {
V_314 = F_175 ( V_314 ) ;
if ( ! F_113 ( & V_317 , V_314 ) ) {
continue;
}
if ( V_100 -> V_108 != V_317 . V_108 ) {
F_4 ( V_317 . V_110 ) ;
continue;
}
if ( V_100 -> V_108 == V_109 ) {
if ( strcmp ( V_100 -> V_110 ,
V_317 . V_110 ) != 0 ) {
F_4 ( V_317 . V_110 ) ;
continue;
}
if ( V_100 -> V_111 != V_317 . V_111 ) {
F_4 ( V_317 . V_110 ) ;
continue;
}
}
F_4 ( V_317 . V_110 ) ;
F_4 ( V_316 ) ;
return FALSE ;
}
F_4 ( V_316 ) ;
}
return TRUE ;
}
T_6
F_176 ( const char * V_28 )
{
T_13 * V_314 , * V_315 ;
T_28 V_113 ;
if ( V_25 . V_206 && V_28 ) {
V_315 = F_26 ( V_25 . V_206 ) ;
V_113 = strlen ( V_28 ) ;
for ( V_314 = strtok ( V_315 , L_23 ) ; V_314 ; V_314 = strtok ( NULL , L_23 ) ) {
if ( strlen ( V_314 ) == V_113 && strcmp ( V_28 , V_314 ) == 0 ) {
F_4 ( V_315 ) ;
return TRUE ;
}
}
F_4 ( V_315 ) ;
}
return FALSE ;
}
T_6
F_177 ( const T_13 * V_318 )
{
T_17 * V_319 ;
T_13 * V_134 ;
for ( V_319 = F_71 ( V_25 . V_217 ) ; V_319 ; V_319 = F_72 ( V_319 ) ) {
V_134 = ( T_13 * ) V_319 -> V_4 ;
if ( V_134 && ( F_147 ( V_134 , V_318 ) == 0 ) ) {
return TRUE ;
}
}
return FALSE ;
}
char
F_178 ( const char * string , T_34 * V_320 )
{
char V_34 ;
memset ( V_320 , 0 , sizeof( T_34 ) ) ;
while ( ( V_34 = * string ++ ) != '\0' ) {
switch ( V_34 ) {
case 'm' :
V_320 -> V_321 = TRUE ;
break;
case 'n' :
V_320 -> V_322 = TRUE ;
break;
case 'N' :
V_320 -> V_323 = TRUE ;
break;
case 't' :
V_320 -> V_324 = TRUE ;
break;
case 'C' :
V_320 -> V_325 = TRUE ;
break;
default:
return V_34 ;
}
}
return '\0' ;
}
static void
F_114 ( T_1 * V_326 )
{
struct {
T_14 V_327 ;
const T_13 * V_328 ;
} V_329 [] = {
{ V_330 , L_281 } ,
{ V_331 , L_282 } ,
{ V_332 , L_283 } ,
{ V_333 , L_284 } ,
{ V_334 , L_285 } ,
{ V_335 , L_286 } ,
{ V_336 , L_287 } ,
{ V_337 , L_288 } ,
{ V_338 , L_289 } ,
{ V_339 , L_290 } ,
{ V_340 , L_291 } ,
{ V_341 , L_292 } ,
{ V_342 , L_293 }
} ;
T_4 V_343 ;
const T_13 * V_344 ;
T_13 * * V_108 = ( T_13 * * ) V_326 ;
for ( V_343 = 0 ;
V_343 < F_179 ( V_329 ) ;
++ V_343 ) {
V_344 = F_94 ( V_329 [ V_343 ] . V_327 ) ;
if ( strcmp ( V_344 , * V_108 ) == 0 ) {
T_13 * V_345 = F_83 ( L_294 ,
V_329 [ V_343 ] . V_328 ) ;
F_4 ( * V_108 ) ;
* V_108 = V_345 ;
}
}
}
static T_24
V_294 ( T_13 * V_346 , const T_13 * V_49 , void * V_296 V_5 ,
T_6 V_347 )
{
unsigned long int V_348 ;
T_4 V_96 ;
T_6 V_349 ;
T_14 V_350 ;
char * V_33 ;
T_13 * V_351 , * V_352 ;
static T_13 * V_353 = NULL ;
static T_6 V_354 = FALSE ;
T_13 * V_355 = NULL ;
T_5 * V_24 ;
T_3 * V_6 ;
T_6 V_356 ;
if ( strcmp ( V_346 , V_357 ) == 0 ) {
V_353 = F_26 ( V_49 ) ;
} else if ( strcmp ( V_346 , V_358 ) == 0 ) {
V_354 = ( strcmp ( V_49 , L_295 ) == 0 ) ? TRUE : FALSE ;
} else if ( strcmp ( V_346 , V_359 ) == 0 ) {
V_355 = F_26 ( V_49 ) ;
F_180 ( V_353 , V_355 , V_354 ) ;
F_4 ( V_353 ) ;
F_4 ( V_355 ) ;
} else if ( strcmp ( V_346 , L_296 ) == 0 ) {
if ( F_147 ( V_49 , L_297 ) == 0 ) {
V_25 . V_193 = V_271 ;
} else {
V_25 . V_193 = V_360 ;
}
} else if ( strcmp ( V_346 , L_298 ) == 0 ||
strcmp ( V_346 , L_299 ) == 0 ) {
if ( F_147 ( V_49 , L_297 ) == 0 ) {
V_361 . V_321 = TRUE ;
V_361 . V_322 = TRUE ;
V_361 . V_324 = TRUE ;
V_361 . V_325 = TRUE ;
}
else if ( F_147 ( V_49 , L_300 ) == 0 ) {
V_361 . V_321 = FALSE ;
V_361 . V_322 = FALSE ;
V_361 . V_324 = FALSE ;
V_361 . V_325 = FALSE ;
}
else {
V_361 . V_321 = FALSE ;
V_361 . V_322 = FALSE ;
V_361 . V_324 = FALSE ;
V_361 . V_325 = FALSE ;
if ( F_178 ( V_49 , & V_361 ) != '\0' )
return V_125 ;
}
} else {
if ( ( strcmp ( V_346 , L_301 ) == 0 ) ||
( strcmp ( V_346 , L_302 ) == 0 ) ||
( strcmp ( V_346 , L_303 ) == 0 ) ) {
V_24 = V_218 ;
V_351 = V_346 ;
} else {
V_24 = NULL ;
V_352 = V_346 ;
V_356 = FALSE ;
while ( ! V_24 ) {
V_351 = strchr ( V_352 , '.' ) ;
if ( V_351 == NULL ) {
if ( V_356 ) {
return V_83 ;
}
else {
return V_125 ;
}
}
else {
V_356 = TRUE ;
}
* V_351 = '\0' ;
V_24 = F_15 ( V_346 ) ;
if ( V_24 == NULL ) {
if ( strcmp ( V_346 , L_304 ) == 0 )
V_24 = V_102 ;
else if ( strcmp ( V_346 , L_305 ) == 0 )
V_24 = F_15 ( L_306 ) ;
else if ( strcmp ( V_346 , L_307 ) == 0 )
V_24 = F_15 ( L_308 ) ;
else if ( strcmp ( V_346 , L_309 ) == 0 ||
strcmp ( V_346 , L_310 ) == 0 )
V_24 = F_15 ( L_311 ) ;
else if ( strcmp ( V_346 , L_312 ) == 0 )
V_24 = F_15 ( L_313 ) ;
else if ( strcmp ( V_346 , L_314 ) == 0 )
V_24 = F_15 ( L_315 ) ;
else if ( strcmp ( V_346 , L_316 ) == 0 )
V_24 = F_15 ( L_317 ) ;
else if ( strcmp ( V_346 , L_318 ) == 0 )
V_24 = F_15 ( L_319 ) ;
else if ( strcmp ( V_346 , L_320 ) == 0 )
V_24 = F_15 ( L_321 ) ;
else if ( strcmp ( V_346 , L_322 ) == 0 )
V_24 = F_15 ( L_323 ) ;
else if ( strcmp ( V_346 , L_324 ) == 0 ||
strcmp ( V_346 , L_325 ) == 0 )
return V_310 ;
}
* V_351 = '.' ;
V_351 ++ ;
V_352 = V_351 ;
}
}
V_6 = F_42 ( V_24 , V_351 ) ;
if ( V_6 == NULL ) {
if ( ( strcmp ( V_346 , V_127 ) == 0 ) ||
( strcmp ( V_346 , V_103 ) == 0 ) ) {
V_6 = F_42 ( V_24 , V_346 ) ;
}
else if ( strcmp ( V_24 -> V_28 , L_326 ) == 0 ) {
if ( strcmp ( V_351 , L_327 ) == 0 )
V_6 = F_42 ( V_24 , L_328 ) ;
else if ( strcmp ( V_351 , L_329 ) == 0 )
V_6 = F_42 ( V_24 , L_330 ) ;
else if ( strcmp ( V_351 , L_331 ) == 0 ) {
V_292 ++ ;
if ( V_292 == 1 ) {
V_6 = F_42 ( V_24 , L_332 ) ;
} else if ( V_292 == 2 ) {
V_6 = F_42 ( V_24 , L_333 ) ;
}
} else if ( strcmp ( V_351 , L_334 ) == 0 ) {
V_293 ++ ;
if ( V_293 == 1 ) {
V_6 = F_42 ( V_24 , L_335 ) ;
} else if ( V_293 == 2 ) {
V_6 = F_42 ( V_24 , L_336 ) ;
}
}
} else if ( strcmp ( V_24 -> V_28 , L_337 ) == 0 ) {
if ( strcmp ( V_351 , L_338 ) == 0 )
V_6 = F_42 ( V_24 , L_339 ) ;
else if ( strcmp ( V_351 , L_340 ) == 0 )
V_6 = F_42 ( V_24 , L_341 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_342 ) == 0 ) {
if ( strcmp ( V_351 , L_343 ) == 0 )
V_6 = F_42 ( V_24 , L_344 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_306 ) == 0 ) {
if ( strcmp ( V_351 , L_345 ) == 0 )
V_6 = F_42 ( V_24 , L_344 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_346 ) == 0 ) {
if ( strcmp ( V_351 , L_347 ) == 0 )
V_6 = F_42 ( V_24 , L_348 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_349 ) == 0 ) {
if ( strcmp ( V_351 , L_350 ) == 0 )
V_6 = F_42 ( V_24 , L_348 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_351 ) == 0 ) {
if ( strcmp ( V_351 , L_352 ) == 0 )
V_6 = F_42 ( V_24 , L_353 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_354 ) == 0 ) {
if ( strcmp ( V_351 , L_355 ) == 0 )
V_6 = F_42 ( V_24 , L_356 ) ;
else if ( strcmp ( V_351 , L_357 ) == 0 )
V_6 = F_42 ( V_24 , L_358 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_359 ) == 0 ) {
if ( strcmp ( V_351 , L_360 ) == 0 )
V_6 = F_42 ( V_24 , L_344 ) ;
else if ( strcmp ( V_351 , L_361 ) == 0 )
V_6 = F_42 ( V_24 , L_362 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_311 ) == 0 ) {
if ( strcmp ( V_351 , L_363 ) == 0 )
V_6 = F_42 ( V_24 , L_364 ) ;
else if ( strcmp ( V_351 , L_365 ) == 0 )
V_6 = F_42 ( V_24 , L_366 ) ;
else if ( strcmp ( V_351 , L_367 ) == 0 )
V_6 = F_42 ( V_24 , L_368 ) ;
else if ( strcmp ( V_351 , L_369 ) == 0 )
V_6 = F_42 ( V_24 , L_370 ) ;
else if ( strcmp ( V_351 , L_371 ) == 0 )
V_6 = F_42 ( V_24 , L_372 ) ;
else if ( strcmp ( V_351 , L_373 ) == 0 )
V_6 = F_42 ( V_24 , L_374 ) ;
else if ( strcmp ( V_351 , L_375 ) == 0 )
V_6 = F_42 ( V_24 , L_376 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_377 ) == 0 ) {
if ( strcmp ( V_351 , L_378 ) == 0 )
V_6 = F_42 ( V_24 , L_379 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_380 ) == 0 ) {
if ( strcmp ( V_351 , L_381 ) == 0 )
V_6 = F_42 ( V_24 , L_362 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_382 ) == 0 ) {
if ( strcmp ( V_351 , L_383 ) == 0 )
V_6 = F_42 ( V_24 , L_384 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_385 ) == 0 ) {
if ( strcmp ( V_351 , L_386 ) == 0 )
V_6 = F_42 ( V_24 , L_387 ) ;
else if ( strcmp ( V_351 , L_388 ) == 0 )
V_6 = F_42 ( V_24 , L_389 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_390 ) == 0 ) {
if ( strcmp ( V_351 , L_391 ) == 0 )
V_6 = F_42 ( V_24 , L_392 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_393 ) == 0 ) {
if ( strcmp ( V_351 , L_394 ) == 0 )
V_6 = F_42 ( V_24 , L_395 ) ;
else if ( strcmp ( V_351 , L_396 ) == 0 )
V_6 = F_42 ( V_24 , L_397 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_398 ) == 0 ) {
if ( strcmp ( V_351 , L_399 ) == 0 )
V_6 = F_42 ( V_24 , L_400 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_401 ) == 0 ) {
if ( strcmp ( V_351 , L_402 ) == 0 )
V_6 = F_42 ( V_24 , L_379 ) ;
else if ( strcmp ( V_351 , L_403 ) == 0 )
V_6 = F_42 ( V_24 , L_404 ) ;
else if ( strcmp ( V_351 , L_405 ) == 0 )
V_6 = F_42 ( V_24 , L_406 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_407 ) == 0 ) {
if ( strcmp ( V_351 , L_408 ) == 0 )
V_6 = F_42 ( V_24 , L_379 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_409 ) == 0 ) {
if ( strcmp ( V_351 , L_410 ) == 0 )
V_6 = F_42 ( V_24 , L_411 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_412 ) == 0 ) {
if ( strcmp ( V_351 , L_413 ) == 0 )
V_6 = F_42 ( V_24 , L_414 ) ;
else if ( strcmp ( V_351 , L_415 ) == 0 )
V_6 = F_42 ( V_24 , L_416 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_417 ) == 0 ) {
T_5 * V_44 = F_15 ( L_313 ) ;
if( V_44 ) {
if ( strcmp ( V_351 , L_418 ) == 0 )
V_6 = F_42 ( V_44 , L_418 ) ;
else if ( strcmp ( V_351 , L_419 ) == 0 )
V_6 = F_42 ( V_44 , L_419 ) ;
}
} else if ( strcmp ( V_24 -> V_28 , L_420 ) == 0 ) {
if ( strcmp ( V_351 , L_421 ) == 0 )
V_6 = F_42 ( V_24 , L_422 ) ;
else if ( strcmp ( V_351 , L_348 ) == 0 )
V_6 = F_42 ( V_24 , L_423 ) ;
else if ( strcmp ( V_351 , L_424 ) == 0 )
V_6 = F_42 ( V_24 , L_425 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_426 ) == 0 ) {
if ( strcmp ( V_351 , L_427 ) == 0 )
V_6 = F_42 ( V_24 , L_428 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_429 ) == 0 ) {
if ( strcmp ( V_351 , L_430 ) == 0 ) {
V_6 = F_42 ( V_24 , L_431 ) ;
if ( strcmp ( V_49 , L_431 ) == 0 || strcmp ( V_49 , L_432 ) == 0 )
V_49 = L_295 ;
else if ( strcmp ( V_49 , L_433 ) == 0 || strcmp ( V_49 , L_434 ) == 0 )
V_49 = L_435 ;
else if ( strcmp ( V_49 , L_436 ) == 0 || strcmp ( V_49 , L_437 ) == 0 )
V_49 = L_295 ;
} else if ( strcmp ( V_351 , L_438 ) == 0 ) {
V_6 = F_42 ( V_24 , L_439 ) ;
if ( strcmp ( V_49 , L_440 ) == 0 || strcmp ( V_49 , L_441 ) == 0 )
V_49 = L_442 ;
else if ( strcmp ( V_49 , L_443 ) == 0 || strcmp ( V_49 , L_444 ) == 0 )
V_49 = L_443 ;
else if ( strcmp ( V_49 , L_436 ) == 0 || strcmp ( V_49 , L_437 ) == 0 )
V_49 = L_442 ;
} else if ( strcmp ( V_351 , L_445 ) == 0 ) {
V_6 = F_42 ( V_24 , L_446 ) ;
if ( strcmp ( V_49 , L_447 ) == 0 || strcmp ( V_49 , L_448 ) == 0 )
V_49 = L_447 ;
else if ( strcmp ( V_49 , L_393 ) == 0 || strcmp ( V_49 , L_449 ) == 0 )
V_49 = L_393 ;
else if ( strcmp ( V_49 , L_450 ) == 0 || strcmp ( V_49 , L_451 ) == 0 )
V_49 = L_452 ;
else if ( strcmp ( V_49 , L_453 ) == 0 || strcmp ( V_49 , L_454 ) == 0 )
V_49 = L_453 ;
else if ( strcmp ( V_49 , L_436 ) == 0 || strcmp ( V_49 , L_437 ) == 0 )
V_49 = L_442 ;
}
} else if ( strcmp ( V_24 -> V_28 , L_433 ) == 0 ) {
if ( strcmp ( V_351 , L_455 ) == 0 ) {
T_5 * V_44 = F_15 ( L_456 ) ;
if( V_44 ) {
V_6 = F_42 ( V_44 , L_455 ) ;
V_24 = V_44 ;
}
}
} else if ( strcmp ( V_24 -> V_28 , L_236 ) == 0 ) {
if ( strcmp ( V_351 , L_225 ) == 0 || strcmp ( V_49 , L_228 ) == 0 )
V_6 = F_42 ( V_48 , V_351 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_238 ) == 0 ) {
if ( strcmp ( V_351 , L_233 ) == 0 )
V_6 = F_42 ( V_41 , V_351 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_240 ) == 0 ) {
if ( ( strcmp ( V_351 , L_67 ) == 0 ) || ( strcmp ( V_49 , L_69 ) == 0 ) ||
( strcmp ( V_351 , L_70 ) == 0 ) || ( strcmp ( V_49 , L_71 ) == 0 ) )
V_6 = F_42 ( V_161 , V_346 ) ;
} else if ( strcmp ( V_24 -> V_28 , L_207 ) == 0 ) {
if ( strcmp ( V_346 , L_301 ) == 0 ) {
V_6 = F_42 ( V_218 , V_346 ) ;
} else if ( strcmp ( V_346 , L_302 ) == 0 ) {
V_6 = F_42 ( V_218 , L_457 ) ;
} else if ( strcmp ( V_346 , L_303 ) == 0 ) {
V_6 = F_42 ( V_218 , L_458 ) ;
}
}
}
if ( V_6 == NULL )
return V_83 ;
switch ( V_6 -> type ) {
case V_10 :
V_96 = ( T_4 ) strtoul ( V_49 , & V_33 , V_6 -> V_65 . V_62 ) ;
if ( V_33 == V_49 || * V_33 != '\0' )
return V_125 ;
if ( * V_6 -> V_17 . V_64 != V_96 ) {
V_24 -> V_37 = TRUE ;
* V_6 -> V_17 . V_64 = V_96 ;
}
break;
case V_8 :
if ( F_147 ( V_49 , L_297 ) == 0 )
V_349 = TRUE ;
else
V_349 = FALSE ;
if ( * V_6 -> V_17 . V_67 != V_349 ) {
V_24 -> V_37 = TRUE ;
* V_6 -> V_17 . V_67 = V_349 ;
}
break;
case V_9 :
V_350 = F_146 ( V_49 , V_6 -> V_65 . V_73 . V_69 ,
* V_6 -> V_17 . V_71 ) ;
if ( * V_6 -> V_17 . V_71 != V_350 ) {
V_24 -> V_37 = TRUE ;
* V_6 -> V_17 . V_71 = V_350 ;
}
break;
case V_14 :
case V_15 :
case V_16 :
if ( strcmp ( * V_6 -> V_17 . string , V_49 ) != 0 ) {
V_24 -> V_37 = TRUE ;
F_4 ( ( void * ) * V_6 -> V_17 . string ) ;
* V_6 -> V_17 . string = F_26 ( V_49 ) ;
}
break;
case V_19 :
{
T_19 * V_362 ;
if ( F_181 ( & V_362 , V_49 , V_6 -> V_65 . V_76 ,
V_347 ) != V_363 ) {
return V_125 ;
}
if ( ! F_182 ( * V_6 -> V_17 . V_20 , V_362 ) ) {
V_24 -> V_37 = TRUE ;
F_4 ( * V_6 -> V_17 . V_20 ) ;
* V_6 -> V_17 . V_20 = V_362 ;
} else {
F_4 ( V_362 ) ;
}
break;
}
case V_13 :
{
V_348 = strtoul ( V_49 , NULL , 16 ) ;
V_6 -> V_17 . V_79 -> V_263 = 0 ;
if ( ( V_6 -> V_17 . V_79 -> V_264 != F_183 ( V_348 ) ) ||
( V_6 -> V_17 . V_79 -> V_265 != F_184 ( V_348 ) ) ||
( V_6 -> V_17 . V_79 -> V_266 != F_185 ( V_348 ) ) ) {
V_24 -> V_37 = TRUE ;
V_6 -> V_17 . V_79 -> V_264 = F_183 ( V_348 ) ;
V_6 -> V_17 . V_79 -> V_265 = F_184 ( V_348 ) ;
V_6 -> V_17 . V_79 -> V_266 = F_185 ( V_348 ) ;
}
break;
}
case V_21 :
return V_6 -> V_22 . V_151 ( V_6 , V_49 , & V_24 -> V_37 ) ;
case V_11 :
case V_12 :
{
break;
}
case V_7 :
return V_310 ;
}
}
return V_82 ;
}
const char *
F_186 ( T_3 * V_6 )
{
const char * V_364 = L_459 ;
if ( ! V_6 ) {
return V_364 ;
}
switch ( V_6 -> type ) {
case V_10 :
switch ( V_6 -> V_65 . V_62 ) {
case 10 :
V_364 = L_460 ;
break;
case 8 :
V_364 = L_461 ;
break;
case 16 :
V_364 = L_462 ;
break;
}
break;
case V_8 :
V_364 = L_463 ;
break;
case V_9 :
V_364 = L_464 ;
break;
case V_14 :
V_364 = L_465 ;
break;
case V_15 :
V_364 = L_466 ;
break;
case V_16 :
V_364 = L_467 ;
break;
case V_19 :
V_364 = L_468 ;
break;
case V_13 :
V_364 = L_469 ;
break;
case V_21 :
if ( V_6 -> V_22 . V_152 )
return V_6 -> V_22 . V_152 () ;
V_364 = L_470 ;
break;
case V_7 :
V_364 = L_471 ;
break;
case V_11 :
V_364 = L_472 ;
break;
case V_12 :
V_364 = L_473 ;
break;
}
return V_364 ;
}
char *
F_187 ( T_3 * V_6 )
{
const char * V_365 = L_474 ;
if ( ! V_6 ) {
return F_83 ( L_475 , V_365 ) ;
}
switch ( V_6 -> type ) {
case V_10 :
switch ( V_6 -> V_65 . V_62 ) {
case 10 :
V_365 = L_476 ;
break;
case 8 :
V_365 = L_477 ;
break;
case 16 :
V_365 = L_478 ;
break;
}
break;
case V_8 :
V_365 = L_479 ;
break;
case V_9 :
{
const T_18 * V_366 = V_6 -> V_65 . V_73 . V_69 ;
T_27 * V_367 = F_93 ( L_480 ) ;
while ( V_366 -> V_28 != NULL ) {
F_95 ( V_367 , V_366 -> V_30 ) ;
V_366 ++ ;
if ( V_366 -> V_28 != NULL )
F_95 ( V_367 , L_481 ) ;
}
F_95 ( V_367 , L_482 ) ;
return F_96 ( V_367 , FALSE ) ;
break;
}
case V_14 :
V_365 = L_483 ;
break;
case V_15 :
V_365 = L_484 ;
break;
case V_16 :
V_365 = L_485 ;
break;
case V_19 :
{
V_365 = L_486 ;
break;
}
case V_13 :
{
V_365 = L_487 ;
break;
}
case V_21 :
if ( V_6 -> V_22 . V_153 )
return V_6 -> V_22 . V_153 () ;
V_365 = L_488 ;
break;
case V_7 :
V_365 = L_489 ;
break;
case V_11 :
V_365 = L_490 ;
break;
case V_12 :
V_365 = L_491 ;
break;
default:
break;
}
return F_26 ( V_365 ) ;
}
static T_6
F_188 ( T_3 * V_6 ) {
if ( ! V_6 ) return FALSE ;
switch ( V_6 -> type ) {
case V_10 :
if ( V_6 -> V_18 . V_64 == * V_6 -> V_17 . V_64 )
return TRUE ;
break;
case V_8 :
if ( V_6 -> V_18 . V_68 == * V_6 -> V_17 . V_67 )
return TRUE ;
break;
case V_9 :
if ( V_6 -> V_18 . V_72 == * V_6 -> V_17 . V_71 )
return TRUE ;
break;
case V_14 :
case V_15 :
case V_16 :
if ( ! ( F_98 ( V_6 -> V_18 . string , * V_6 -> V_17 . string ) ) )
return TRUE ;
break;
case V_19 :
{
if ( ( F_182 ( V_6 -> V_18 . V_20 , * V_6 -> V_17 . V_20 ) ) )
return TRUE ;
break;
}
case V_13 :
{
if ( ( V_6 -> V_18 . V_78 . V_264 == V_6 -> V_17 . V_79 -> V_264 ) &&
( V_6 -> V_18 . V_78 . V_265 == V_6 -> V_17 . V_79 -> V_265 ) &&
( V_6 -> V_18 . V_78 . V_266 == V_6 -> V_17 . V_79 -> V_266 ) )
return TRUE ;
break;
}
case V_21 :
return V_6 -> V_22 . V_154 ( V_6 ) ;
case V_7 :
case V_11 :
case V_12 :
return FALSE ;
break;
}
return FALSE ;
}
char *
F_189 ( T_3 * V_6 , T_35 V_368 ) {
const char * V_369 = L_459 ;
T_4 V_370 ;
T_6 V_371 ;
T_14 V_372 ;
const char * V_373 ;
T_19 * V_374 ;
T_21 * V_375 ;
if ( ! V_6 ) {
return F_26 ( V_369 ) ;
}
switch ( V_368 ) {
case V_376 :
V_370 = V_6 -> V_18 . V_64 ;
V_371 = V_6 -> V_18 . V_68 ;
V_372 = V_6 -> V_18 . V_72 ;
V_373 = V_6 -> V_18 . string ;
V_374 = V_6 -> V_18 . V_20 ;
V_375 = & V_6 -> V_18 . V_78 ;
break;
case V_377 :
V_370 = V_6 -> V_75 . V_64 ;
V_371 = V_6 -> V_75 . V_68 ;
V_372 = V_6 -> V_75 . V_72 ;
V_373 = V_6 -> V_75 . string ;
V_374 = V_6 -> V_75 . V_20 ;
V_375 = & V_6 -> V_75 . V_78 ;
break;
case V_378 :
V_370 = * V_6 -> V_17 . V_64 ;
V_371 = * V_6 -> V_17 . V_67 ;
V_372 = * V_6 -> V_17 . V_71 ;
V_373 = * V_6 -> V_17 . string ;
V_374 = * V_6 -> V_17 . V_20 ;
V_375 = V_6 -> V_17 . V_79 ;
break;
default:
return F_26 ( V_369 ) ;
}
switch ( V_6 -> type ) {
case V_10 :
switch ( V_6 -> V_65 . V_62 ) {
case 10 :
return F_83 ( L_19 , V_370 ) ;
break;
case 8 :
return F_83 ( L_492 , V_370 ) ;
break;
case 16 :
return F_83 ( L_493 , V_370 ) ;
break;
}
break;
case V_8 :
return F_83 ( L_250 , V_371 ? L_295 : L_435 ) ;
break;
case V_9 :
{
const T_18 * V_366 = V_6 -> V_65 . V_73 . V_69 ;
while ( V_366 -> V_28 != NULL ) {
if ( V_366 -> V_49 == V_372 )
return F_26 ( V_366 -> V_30 ) ;
V_366 ++ ;
}
break;
}
case V_14 :
case V_15 :
case V_16 :
return F_26 ( V_373 ) ;
break;
case V_19 :
V_369 = F_190 ( V_374 ) ;
break;
case V_13 :
return F_83 ( L_494 ,
( V_375 -> V_264 * 255 / 65535 ) ,
( V_375 -> V_265 * 255 / 65535 ) ,
( V_375 -> V_266 * 255 / 65535 ) ) ;
break;
case V_21 :
if ( V_6 -> V_22 . V_155 )
return V_6 -> V_22 . V_155 ( V_6 , V_368 == V_376 ? TRUE : FALSE ) ;
V_369 = L_495 ;
break;
case V_7 :
V_369 = L_496 ;
break;
case V_11 :
V_369 = L_490 ;
break;
case V_12 :
{
T_33 * V_77 = ( T_33 * ) V_6 -> V_17 . V_77 ;
if ( V_77 && V_77 -> V_379 )
return F_83 ( L_497 , V_77 -> V_379 ) ;
else
V_369 = L_498 ;
break;
}
default:
break;
}
return F_26 ( V_369 ) ;
}
static void
F_191 ( T_1 V_4 , T_1 T_2 )
{
T_3 * V_6 = ( T_3 * ) V_4 ;
T_36 * V_59 = ( T_36 * ) T_2 ;
T_13 * * V_380 ;
int V_231 ;
switch ( V_6 -> type ) {
case V_7 :
return;
case V_11 :
case V_12 :
return;
default:
break;
}
if ( V_6 -> type != V_21 || V_6 -> V_22 . V_152 () != NULL ) {
const char * V_381 = ( V_59 -> V_24 -> V_28 != NULL ) ? V_59 -> V_24 -> V_28 : V_59 -> V_24 -> V_27 -> V_28 ;
char * V_365 , * V_369 ;
const char * V_382 = F_188 ( V_6 ) ? L_499 : L_7 ;
if ( V_6 -> type == V_21 ) fprintf ( V_59 -> V_286 , L_500 , V_6 -> V_22 . V_152 () ) ;
fprintf ( V_59 -> V_286 , L_501 ) ;
if ( V_6 -> V_30 &&
( F_192 ( V_6 -> V_30 , L_7 , 2 ) != 0 ) ) {
if ( V_6 -> type != V_21 ) {
V_380 = F_148 ( V_6 -> V_30 , L_501 , 0 ) ;
for ( V_231 = 0 ; V_380 [ V_231 ] != NULL ; ++ V_231 ) {
fprintf ( V_59 -> V_286 , L_502 , V_380 [ V_231 ] ) ;
}
F_149 ( V_380 ) ;
}
} else {
fprintf ( V_59 -> V_286 , L_503 ) ;
}
V_365 = F_187 ( V_6 ) ;
V_380 = F_148 ( V_365 , L_501 , 0 ) ;
for ( V_231 = 0 ; V_380 [ V_231 ] != NULL ; ++ V_231 ) {
fprintf ( V_59 -> V_286 , L_502 , V_380 [ V_231 ] ) ;
}
F_149 ( V_380 ) ;
F_4 ( V_365 ) ;
V_369 = F_189 ( V_6 , V_378 ) ;
fprintf ( V_59 -> V_286 , L_504 , V_382 , V_381 , V_6 -> V_28 ) ;
V_380 = F_148 ( V_369 , L_501 , 0 ) ;
for ( V_231 = 0 ; V_380 [ V_231 ] != NULL ; ++ V_231 ) {
fprintf ( V_59 -> V_286 , L_505 , V_231 == 0 ? L_7 : V_382 , V_380 [ V_231 ] ) ;
}
if ( V_231 == 0 ) fprintf ( V_59 -> V_286 , L_501 ) ;
F_149 ( V_380 ) ;
F_4 ( V_369 ) ;
}
}
static T_4
F_193 ( T_5 * V_24 , T_1 T_2 )
{
T_37 * V_383 = ( T_37 * ) T_2 ;
T_36 V_59 ;
if ( ( V_24 == V_143 ) && ( V_383 -> V_384 != TRUE ) )
return 0 ;
if ( ( ( V_24 -> V_27 == NULL ) || ( V_24 -> V_27 == V_143 ) ) &&
( ( F_35 ( V_24 ) ) ||
( V_24 -> V_26 > 0 ) ||
( V_24 -> V_28 == NULL ) ) ) {
if ( ( V_24 -> V_28 == NULL ) && ( V_24 -> V_27 != NULL ) ) {
fprintf ( V_383 -> V_286 , L_506 , V_24 -> V_27 -> V_29 , V_24 -> V_29 ) ;
} else {
fprintf ( V_383 -> V_286 , L_507 , V_24 -> V_29 ) ;
}
}
V_59 . V_24 = V_24 ;
V_59 . V_286 = V_383 -> V_286 ;
F_6 ( V_59 . V_24 -> V_25 , F_191 , & V_59 ) ;
if( F_35 ( V_24 ) )
return F_36 ( V_24 , F_193 , T_2 ) ;
return 0 ;
}
int
F_194 ( char * * V_283 )
{
char * V_285 ;
T_31 * V_286 ;
T_37 V_385 ;
F_151 () ;
if ( V_283 != NULL ) {
V_285 = F_166 ( V_288 , TRUE ) ;
if ( ( V_286 = F_164 ( V_285 , L_508 ) ) == NULL ) {
* V_283 = V_285 ;
return V_289 ;
}
} else {
V_286 = stdout ;
}
fputs ( L_509 V_386 L_510
L_511
L_512
L_513
L_514
L_515 , V_286 ) ;
V_385 . V_286 = V_286 ;
V_385 . V_384 = TRUE ;
F_193 ( V_143 , & V_385 ) ;
{
struct V_387 * V_388 = * (struct V_387 * * ) V_25 . V_389 ;
if ( V_388 != NULL )
fprintf ( V_286 , L_516 ) ;
while ( V_388 != NULL ) {
if ( V_388 -> V_390 == FALSE ) {
fprintf ( V_286 , L_517 , V_357 , V_388 -> V_391 ) ;
fprintf ( V_286 , L_517 , V_358 ,
V_388 -> V_392 == TRUE ? L_295 : L_435 ) ;
fprintf ( V_286 , L_517 , V_359 , V_388 -> V_393 ) ;
}
V_388 = V_388 -> V_104 ;
}
}
V_385 . V_384 = FALSE ;
F_36 ( NULL , F_193 , & V_385 ) ;
fclose ( V_286 ) ;
return 0 ;
}
static void
F_107 ( T_17 * V_81 )
{
T_26 * V_100 ;
while ( V_81 != NULL ) {
V_100 = ( T_26 * ) V_81 -> V_4 ;
F_4 ( V_100 -> V_29 ) ;
F_4 ( V_100 -> V_110 ) ;
F_4 ( V_100 ) ;
V_81 = F_122 ( V_81 , V_81 ) ;
}
F_7 ( V_81 ) ;
V_81 = NULL ;
}
