void
F_1 ( void )
{
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = F_2 ( F_3 () ) ;
V_3 = F_2 ( F_3 () ) ;
}
static void
F_4 ( T_1 * V_4 )
{
F_5 ( * V_4 -> V_5 . string ) ;
* V_4 -> V_5 . string = NULL ;
F_5 ( V_4 -> V_6 . string ) ;
V_4 -> V_6 . string = NULL ;
}
static void
F_6 ( T_2 V_7 , T_2 T_3 V_8 )
{
T_1 * V_4 = ( T_1 * ) V_7 ;
int type = V_4 -> type ;
F_7 ( type ) ;
switch ( type ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
break;
case V_15 :
case V_16 :
case V_17 :
F_5 ( * V_4 -> V_5 . string ) ;
* V_4 -> V_5 . string = NULL ;
F_5 ( V_4 -> V_6 . string ) ;
V_4 -> V_6 . string = NULL ;
break;
case V_18 :
F_5 ( * V_4 -> V_5 . V_19 ) ;
* V_4 -> V_5 . V_19 = NULL ;
F_5 ( V_4 -> V_6 . V_19 ) ;
V_4 -> V_6 . V_19 = NULL ;
break;
case V_20 :
if ( strcmp ( V_4 -> V_21 , L_1 ) == 0 )
V_4 -> V_22 . V_23 = TRUE ;
V_4 -> V_24 . V_25 ( V_4 ) ;
break;
}
F_5 ( V_4 ) ;
}
static T_4
F_8 ( T_5 * V_26 , T_2 V_7 V_8 )
{
if ( V_26 -> V_1 ) {
F_9 ( V_26 -> V_1 , F_6 , NULL ) ;
F_10 ( V_26 -> V_1 ) ;
}
V_26 -> V_1 = NULL ;
V_26 -> V_27 = 0 ;
if ( V_26 -> V_28 ) {
F_11 ( V_26 , F_8 , NULL ) ;
}
return 0 ;
}
void
F_12 ( void )
{
F_13 ( F_8 , NULL ) ;
}
T_5 *
F_14 ( T_5 * V_29 , const char * V_21 , const char * V_30 ,
const char * V_31 , void (* F_15)( void ) ,
const T_6 V_32 )
{
return F_16 ( V_29 , V_21 , V_30 , V_31 ,
FALSE , F_15 , V_32 ) ;
}
static void
F_17 ( T_5 * V_29 , const char * V_21 , const char * V_30 )
{
T_5 * V_26 = ( T_5 * ) F_18 ( V_2 , V_21 , V_33 ) ;
if ( ! V_26 )
return;
if ( V_29 == NULL ) {
F_18 ( V_3 , V_30 , V_33 ) ;
} else if ( V_29 -> V_28 ) {
F_18 ( V_29 -> V_28 , V_30 , V_33 ) ;
}
F_8 ( V_26 , NULL ) ;
F_19 ( F_3 () , V_26 ) ;
}
T_5 *
F_20 ( T_5 * V_29 , const char * V_30 , const char * V_31 ,
void (* F_15)( void ) )
{
return F_16 ( V_29 , NULL , V_30 , V_31 ,
TRUE , F_15 ,
V_29 ? V_29 -> V_32 : FALSE ) ;
}
static T_5 *
F_16 ( T_5 * V_29 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_6 V_34 , void (* F_15)( void ) ,
T_6 V_32 )
{
T_5 * V_26 ;
const char * V_35 ;
T_7 V_36 ;
if ( ( V_26 = F_21 ( V_29 , V_30 ) ) ) {
V_26 -> V_21 = V_21 ;
V_26 -> F_15 = F_15 ;
V_26 -> V_31 = V_31 ;
if ( F_22 ( V_21 ) == NULL ) {
F_23 ( V_2 , V_21 , V_26 ,
V_33 ) ;
}
return V_26 ;
}
V_26 = F_24 ( F_3 () , T_5 ) ;
V_26 -> V_21 = V_21 ;
V_26 -> V_30 = V_30 ;
V_26 -> V_31 = V_31 ;
V_26 -> F_15 = F_15 ;
V_26 -> V_1 = NULL ;
V_26 -> V_29 = V_29 ;
V_26 -> V_28 = NULL ;
V_26 -> V_27 = 0 ;
V_26 -> V_37 = FALSE ;
V_26 -> V_38 = FALSE ;
V_26 -> V_32 = V_32 ;
if ( V_21 != NULL ) {
for ( V_35 = V_21 ; ( V_36 = * V_35 ) != '\0' ; V_35 ++ )
F_25 ( F_26 ( V_36 ) || F_27 ( V_36 ) || V_36 == '_' ||
V_36 == '-' || V_36 == '.' ) ;
F_25 ( F_22 ( V_21 ) == NULL ) ;
F_23 ( V_2 , V_21 , V_26 , V_33 ) ;
} else {
F_25 ( V_34 ) ;
}
if ( V_29 == NULL ) {
F_23 ( V_3 , V_30 , V_26 , V_33 ) ;
} else {
if ( V_29 -> V_28 == NULL )
V_29 -> V_28 = F_2 ( F_3 () ) ;
F_23 ( V_29 -> V_28 , V_30 , V_26 , V_33 ) ;
}
return V_26 ;
}
T_5 *
F_28 ( int V_39 , void (* F_15)( void ) )
{
T_8 * V_40 ;
if ( V_41 == NULL ) {
F_29 () ;
F_30 () ;
}
V_40 = F_31 ( V_39 ) ;
return F_14 ( V_41 ,
F_32 ( V_39 ) ,
F_33 ( V_40 ) ,
F_34 ( V_39 ) , F_15 , TRUE ) ;
}
void
F_35 ( int V_39 )
{
T_8 * V_40 = F_31 ( V_39 ) ;
F_17 ( V_41 ,
F_32 ( V_39 ) ,
F_33 ( V_40 ) ) ;
}
T_5 *
F_36 ( const char * V_42 , int V_39 , void (* F_15)( void ) )
{
T_8 * V_40 ;
T_5 * V_43 ;
T_5 * V_44 ;
char * V_45 = NULL , * V_46 = NULL , * V_47 = NULL ;
if ( V_41 == NULL ) {
F_29 () ;
F_30 () ;
}
V_43 = V_41 ;
if ( V_42 ) {
V_47 = V_46 = F_37 ( V_42 ) ;
while ( V_46 && * V_46 ) {
if ( ( V_45 = strchr ( V_46 , '/' ) ) )
* V_45 ++ = '\0' ;
if ( ! ( V_44 = F_21 ( V_43 , V_46 ) ) ) {
V_46 = F_38 ( F_3 () , V_46 ) ,
V_44 = F_20 ( V_43 , V_46 , V_46 , NULL ) ;
}
V_43 = V_44 ;
V_46 = V_45 ;
}
F_5 ( V_47 ) ;
}
V_40 = F_31 ( V_39 ) ;
return F_14 ( V_43 ,
F_32 ( V_39 ) ,
F_33 ( V_40 ) ,
F_34 ( V_39 ) , F_15 , TRUE ) ;
}
T_5 *
F_39 ( int V_39 )
{
T_5 * V_26 ;
T_8 * V_40 ;
if ( V_41 == NULL ) {
F_29 () ;
F_30 () ;
}
V_40 = F_31 ( V_39 ) ;
V_26 = F_14 ( V_41 ,
F_32 ( V_39 ) ,
F_33 ( V_40 ) ,
F_34 ( V_39 ) , NULL , TRUE ) ;
V_26 -> V_38 = TRUE ;
return V_26 ;
}
T_5 *
F_40 ( const char * V_21 , const char * V_30 ,
const char * V_31 , void (* F_15)( void ) )
{
if ( V_48 == NULL ) {
F_29 () ;
F_30 () ;
}
return F_14 ( V_48 , V_21 , V_30 , V_31 ,
F_15 , TRUE ) ;
}
T_5 *
F_22 ( const char * V_21 )
{
return ( T_5 * ) F_41 ( V_2 , V_21 , V_33 ) ;
}
static T_5 *
F_21 ( T_5 * V_29 , const char * V_21 )
{
return ( T_5 * ) F_41 ( V_29 ? V_29 -> V_28 : V_3 , V_21 , V_33 ) ;
}
static T_6
F_42 ( const void * T_9 V_8 , void * V_49 , void * V_7 )
{
T_5 * V_26 = ( T_5 * ) V_49 ;
T_10 * V_50 = ( T_10 * ) V_7 ;
if ( ! V_26 -> V_38 )
V_50 -> V_51 = (* V_50 -> V_52 )( V_26 , V_50 -> T_3 ) ;
return ( V_50 -> V_51 != 0 ) ;
}
static T_4
F_43 ( T_11 * V_53 , T_12 V_52 ,
T_2 T_3 )
{
T_10 V_50 ;
if ( V_53 == NULL )
V_53 = V_3 ;
V_50 . V_52 = V_52 ;
V_50 . T_3 = T_3 ;
V_50 . V_51 = 0 ;
F_44 ( V_53 , F_42 , & V_50 ) ;
return V_50 . V_51 ;
}
T_6
F_45 ( T_5 * V_26 )
{
if ( V_26 -> V_28 == NULL ) {
return FALSE ;
}
if ( F_46 ( V_26 -> V_28 ) ) {
return FALSE ;
}
return TRUE ;
}
T_4
F_13 ( T_12 V_52 , T_2 T_3 )
{
return F_43 ( V_2 , V_52 , T_3 ) ;
}
T_4
F_11 ( T_5 * V_26 , T_12 V_52 ,
T_2 T_3 )
{
return F_43 ( ( V_26 ) ? V_26 -> V_28 : V_3 , V_52 , T_3 ) ;
}
static T_6
F_47 ( const void * T_9 V_8 , void * V_49 , void * V_7 V_8 )
{
T_5 * V_26 = ( T_5 * ) V_49 ;
if ( V_26 -> V_38 )
return FALSE ;
if ( V_26 -> V_37 ) {
if ( V_26 -> F_15 != NULL )
(* V_26 -> F_15 )() ;
V_26 -> V_37 = FALSE ;
}
if ( V_26 -> V_28 )
F_44 ( V_26 -> V_28 , F_47 , NULL ) ;
return FALSE ;
}
void
F_48 ( void )
{
F_44 ( V_2 , F_47 , NULL ) ;
}
void
F_49 ( T_5 * V_26 )
{
if ( V_26 && V_26 -> V_37 )
F_47 ( NULL , V_26 , NULL ) ;
}
static T_1 *
F_50 ( T_5 * V_26 , const char * V_21 , const char * V_30 ,
const char * V_31 , int type )
{
T_1 * V_54 ;
const T_13 * V_35 ;
V_54 = F_51 ( T_1 , 1 ) ;
V_54 -> V_21 = V_21 ;
V_54 -> V_30 = V_30 ;
V_54 -> V_31 = V_31 ;
V_54 -> type = type ;
V_54 -> V_55 = V_56 ;
if ( V_30 != NULL )
V_54 -> V_57 = V_26 -> V_27 ;
else
V_54 -> V_57 = - 1 ;
for ( V_35 = V_21 ; * V_35 != '\0' ; V_35 ++ )
if ( ! ( F_26 ( * V_35 ) || F_27 ( * V_35 ) || * V_35 == '_' || * V_35 == '.' ) )
F_52 ( L_2 , V_26 -> V_21 , V_21 ) ;
if ( F_53 ( V_26 , V_21 ) != NULL )
F_52 ( L_3 , V_21 ) ;
if ( ( ! F_54 ( type ) ) &&
( V_26 -> V_21 != NULL ) ) {
if ( ! ( ( strncmp ( V_21 , V_26 -> V_21 , strlen ( V_26 -> V_21 ) ) != 0 ) ||
( ( ( V_21 [ strlen ( V_26 -> V_21 ) ] ) != '.' ) && ( ( V_21 [ strlen ( V_26 -> V_21 ) ] ) != '_' ) ) ) )
F_52 ( L_4 , V_21 ) ;
}
V_26 -> V_1 = F_55 ( V_26 -> V_1 , V_54 ) ;
if ( V_30 != NULL )
V_26 -> V_27 ++ ;
return V_54 ;
}
static T_14
F_56 ( T_15 V_58 , T_15 V_59 )
{
const T_1 * V_4 = ( const T_1 * ) V_58 ;
const char * V_21 = ( const char * ) V_59 ;
return strcmp ( V_21 , V_4 -> V_21 ) ;
}
static T_6
F_57 ( const void * T_9 V_8 , void * V_49 , void * V_7 )
{
T_16 * V_60 = ( T_16 * ) V_7 ;
T_17 * V_61 ;
T_5 * V_26 = ( T_5 * ) V_49 ;
if ( V_26 == NULL )
return FALSE ;
V_61 = F_58 ( V_26 -> V_1 , V_60 -> V_21 ,
F_56 ) ;
if ( V_61 == NULL )
return FALSE ;
V_60 -> V_61 = V_61 ;
V_60 -> V_62 = V_26 ;
return TRUE ;
}
static struct V_54 *
F_59 ( T_5 * V_26 , const char * V_21 ,
T_5 * * V_63 )
{
T_16 V_60 ;
T_17 * V_61 ;
if ( V_26 == NULL )
return NULL ;
V_61 = F_58 ( V_26 -> V_1 , V_21 ,
F_56 ) ;
V_60 . V_62 = NULL ;
if ( V_61 == NULL )
{
V_60 . V_61 = NULL ;
if ( V_26 -> V_28 != NULL )
{
V_60 . V_21 = V_21 ;
F_44 ( V_26 -> V_28 , F_57 , & V_60 ) ;
}
V_61 = V_60 . V_61 ;
}
if ( V_61 == NULL )
return NULL ;
if ( V_63 )
* V_63 = V_60 . V_62 ? V_60 . V_62 : V_26 ;
return (struct V_54 * ) V_61 -> V_7 ;
}
struct V_54 *
F_53 ( T_5 * V_26 , const char * V_21 )
{
return F_59 ( V_26 , V_21 , NULL ) ;
}
T_6
F_60 ( const char * V_21 )
{
T_5 * V_64 = F_22 ( V_21 ) ;
return ( V_64 != NULL && ! V_64 -> V_38 ) ;
}
const char *
F_61 ( const char * V_21 )
{
T_5 * V_64 = F_22 ( V_21 ) ;
return ( V_64 != NULL && ! V_64 -> V_38 ) ? V_64 -> V_30 : NULL ;
}
void
F_62 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_4 V_65 , T_4 * V_66 )
{
T_1 * V_54 ;
V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 ,
V_11 ) ;
V_54 -> V_5 . V_67 = V_66 ;
V_54 -> V_6 . V_67 = * V_66 ;
F_25 ( V_65 > 0 && V_65 != 1 && V_65 < 37 ) ;
V_54 -> V_68 . V_65 = V_65 ;
}
static void
F_63 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
struct V_69 * V_24 , T_4 * V_66 )
{
T_1 * V_54 ;
V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 ,
V_20 ) ;
V_54 -> V_24 = * V_24 ;
V_54 -> V_5 . V_67 = V_66 ;
V_54 -> V_6 . V_67 = * V_66 ;
}
void
F_64 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_6 * V_66 )
{
T_1 * V_54 ;
V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 ,
V_9 ) ;
V_54 -> V_5 . V_70 = V_66 ;
V_54 -> V_6 . V_23 = * V_66 ;
}
void
F_65 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_14 * V_66 , const T_18 * V_71 ,
T_6 V_72 )
{
T_1 * V_54 ;
V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 ,
V_10 ) ;
V_54 -> V_5 . V_73 = V_66 ;
V_54 -> V_6 . V_74 = * V_66 ;
V_54 -> V_68 . V_75 . V_71 = V_71 ;
V_54 -> V_68 . V_75 . V_72 = V_72 ;
}
static void
F_66 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
char * * V_66 , int type ,
struct V_69 * V_24 ,
T_6 V_76 )
{
T_1 * V_4 ;
T_13 * V_77 ;
V_4 = F_50 ( V_26 , V_21 , V_30 , V_31 , type ) ;
V_77 = * V_66 ;
if ( * V_66 == NULL ) {
* V_66 = F_37 ( L_5 ) ;
} else {
* V_66 = F_37 ( * V_66 ) ;
}
if ( V_76 ) {
F_5 ( V_77 ) ;
}
V_4 -> V_5 . string = V_66 ;
V_4 -> V_6 . string = F_37 ( * V_66 ) ;
V_4 -> V_22 . string = NULL ;
if ( type == V_20 ) {
F_25 ( V_24 ) ;
V_4 -> V_24 = * V_24 ;
}
}
void
F_67 ( T_1 * V_4 , const T_13 * V_49 , T_6 * V_78 )
{
if ( * V_4 -> V_5 . string ) {
if ( strcmp ( * V_4 -> V_5 . string , V_49 ) != 0 ) {
* V_78 = TRUE ;
F_5 ( * V_4 -> V_5 . string ) ;
* V_4 -> V_5 . string = F_37 ( V_49 ) ;
}
} else if ( V_49 ) {
* V_4 -> V_5 . string = F_37 ( V_49 ) ;
}
}
static void
F_68 ( T_1 * V_4 )
{
F_5 ( * V_4 -> V_5 . string ) ;
* V_4 -> V_5 . string = F_37 ( V_4 -> V_6 . string ) ;
}
void
F_69 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
const char * * V_66 )
{
F_70 (cast-qual)
F_66 ( V_26 , V_21 , V_30 , V_31 ,
( char * * ) V_66 , V_15 , NULL , FALSE ) ;
F_71 (cast-qual)
}
void
F_72 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
const char * * V_66 )
{
F_70 (cast-qual)
F_66 ( V_26 , V_21 , V_30 , V_31 ,
( char * * ) V_66 , V_16 , NULL , FALSE ) ;
F_71 (cast-qual)
}
void
F_73 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
const char * * V_66 )
{
F_70 (cast-qual)
F_66 ( V_26 , V_21 , V_30 , V_31 ,
( char * * ) V_66 , V_17 , NULL , FALSE ) ;
F_71 (cast-qual)
}
void
F_74 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_19 * * V_66 , T_20 V_79 )
{
T_1 * V_54 ;
V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 ,
V_18 ) ;
V_54 -> V_68 . V_79 = V_79 ;
if ( * V_66 == NULL )
* V_66 = F_75 () ;
V_54 -> V_5 . V_19 = V_66 ;
V_54 -> V_6 . V_19 = F_76 ( * V_66 ) ;
V_54 -> V_22 . V_19 = NULL ;
}
static T_6
F_77 ( T_1 * V_4 , const T_13 * V_49 ,
T_6 V_80 , T_6 * V_78 )
{
T_19 * V_81 ;
if ( F_78 ( & V_81 , V_49 , V_4 -> V_68 . V_79 ,
V_80 ) != V_82 ) {
return FALSE ;
}
if ( ! F_79 ( * V_4 -> V_5 . V_19 , V_81 ) ) {
* V_78 = TRUE ;
F_5 ( * V_4 -> V_5 . V_19 ) ;
* V_4 -> V_5 . V_19 = V_81 ;
} else {
F_5 ( V_81 ) ;
}
return TRUE ;
}
T_6
F_80 ( T_1 * V_4 , const T_13 * V_49 , T_6 * V_78 )
{
return F_77 ( V_4 , V_49 , TRUE , V_78 ) ;
}
void
F_81 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 ,
const char * V_31 )
{
F_50 ( V_26 , V_21 , V_30 , V_31 , V_12 ) ;
}
extern void
F_82 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_21 * V_83 )
{
T_1 * V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 , V_13 ) ;
V_54 -> V_5 . V_83 = V_83 ;
}
extern void
F_83 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_21 * V_83 )
{
T_1 * V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 , V_13 ) ;
V_54 -> V_5 . V_83 = V_83 ;
V_54 -> V_55 = V_84 ;
}
void
F_84 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
T_22 * V_85 )
{
T_1 * V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 , V_14 ) ;
V_54 -> V_5 . V_86 = V_85 ;
V_54 -> V_6 . V_85 = * V_85 ;
}
static void
F_85 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
struct V_69 * V_24 ,
T_23 V_87 ,
T_17 * * V_88 )
{
T_1 * V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 , V_20 ) ;
V_54 -> V_24 = * V_24 ;
V_87 ( V_54 , V_88 ) ;
}
void
F_86 ( T_5 * V_26 , const char * V_21 ,
const char * V_30 , const char * V_31 ,
struct V_69 * V_24 ,
void * * T_24 V_8 )
{
T_1 * V_54 = F_50 ( V_26 , V_21 , V_30 , V_31 , V_20 ) ;
V_54 -> V_24 = * V_24 ;
}
void
F_87 ( T_5 * V_26 , const char * V_21 )
{
F_50 ( V_26 , V_21 , NULL , NULL , V_89 ) ;
}
extern T_6
F_88 ( T_1 * V_4 )
{
if ( V_4 )
return ( F_54 ( V_4 -> type ) ? TRUE : FALSE ) ;
return TRUE ;
}
extern T_25
F_89 ( T_1 * V_4 )
{
if ( V_4 ) {
F_90 ( V_4 -> type ) ;
return V_90 ;
}
return V_91 ;
}
T_4
F_91 ( T_5 * V_26 , T_26 V_52 , T_2 T_3 )
{
T_17 * V_92 ;
T_1 * V_4 ;
T_4 V_51 ;
for ( V_92 = F_92 ( V_26 -> V_1 ) ; V_92 != NULL ; V_92 = F_93 ( V_92 ) ) {
V_4 = ( T_1 * ) V_92 -> V_7 ;
if ( F_54 ( V_4 -> type ) ) {
continue;
}
V_51 = (* V_52)( V_4 , T_3 ) ;
if ( V_51 != 0 )
return V_51 ;
}
return 0 ;
}
static void
F_94 ( void )
{
if ( V_1 . V_93 < 100 || V_1 . V_93 > 10000 )
V_1 . V_93 = V_94 ;
#ifdef F_95
if ( V_1 . V_95 < 1 || V_1 . V_95 > 10 )
V_1 . V_95 = V_96 ;
#endif
if ( V_1 . V_97 < 1 ) {
V_1 . V_97 = 1 ;
}
else if ( V_1 . V_97 > V_98 ) {
V_1 . V_97 = V_98 ;
}
if ( V_1 . V_99 < V_1 . V_97 ) {
V_1 . V_99 = V_1 . V_97 ;
}
V_1 . V_99 -= V_1 . V_99 % V_1 . V_97 ;
if ( ( V_1 . V_99 / V_1 . V_97 ) > V_100 ) {
V_1 . V_99 = V_1 . V_97 * V_100 ;
}
}
static void
F_96 ( void )
{
if ( V_1 . V_101 == 0 )
V_1 . V_101 = 10 ;
if ( V_1 . V_102 == 0 )
V_1 . V_102 = 10 ;
}
static void
F_97 ( void )
{
if ( V_1 . V_103 == V_104 ||
V_1 . V_103 >= V_105 ) {
V_1 . V_103 = V_106 ;
}
}
static void F_98 ( T_1 * V_4 V_8 ) {}
static void
F_99 ( T_1 * V_4 )
{
* V_4 -> V_5 . V_67 = V_4 -> V_6 . V_67 ;
}
static T_25
F_100 ( T_1 * V_4 , const T_13 * V_49 , T_6 * V_78 )
{
T_4 V_107 ;
V_107 = ( T_4 ) strtoul ( V_49 , NULL , 10 ) ;
if ( * V_4 -> V_5 . V_67 != V_107 ) {
* V_78 = TRUE ;
* V_4 -> V_5 . V_67 = V_107 ;
}
if ( * V_4 -> V_5 . V_67 & ( V_108 | V_109 ) ) {
F_101 ( L_6 , L_7 , TRUE ) ;
}
return V_90 ;
}
static const char * F_102 ( void ) {
return L_8 ;
}
static char * F_103 ( void ) {
return F_104 (
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ) ;
}
static T_6 F_105 ( T_1 * V_4 ) {
return * V_4 -> V_5 . V_67 == V_4 -> V_6 . V_67 ;
}
static char * F_106 ( T_1 * V_4 , T_6 V_6 ) {
return F_104 ( L_17 , V_6 ? V_4 -> V_6 . V_67 : * V_4 -> V_5 . V_67 ) ;
}
static T_25
F_107 ( T_1 * V_4 , const T_13 * V_49 , T_6 * V_78 )
{
T_17 * V_110 ;
T_27 * V_111 ;
T_1 * V_112 ;
F_67 ( V_4 , V_49 , V_78 ) ;
V_112 = F_53 ( V_113 , V_114 ) ;
for ( V_110 = * V_112 -> V_5 . V_88 ; V_110 != NULL ; V_110 = V_110 -> V_115 ) {
V_111 = ( T_27 * ) V_110 -> V_7 ;
V_111 -> V_116 = F_108 ( * V_4 -> V_5 . string , V_111 ) ;
}
return V_90 ;
}
static const char *
F_109 ( void )
{
return L_18 ;
}
static char *
F_110 ( void )
{
return F_37 ( L_19 ) ;
}
static char *
F_111 ( T_1 * V_4 , T_6 V_6 )
{
T_28 * V_117 = F_112 ( L_5 ) ;
T_17 * V_110 ;
T_27 * V_111 ;
T_1 * V_112 ;
if ( V_6 )
return F_37 ( V_4 -> V_6 . string ) ;
V_112 = F_53 ( V_113 , V_114 ) ;
V_110 = ( V_112 ) ? * V_112 -> V_5 . V_88 : NULL ;
while ( V_110 ) {
T_13 * V_118 ;
V_111 = ( T_27 * ) V_110 -> V_7 ;
if ( ( V_111 -> V_119 == V_120 ) && ( V_111 -> V_121 ) ) {
V_118 = F_104 ( L_20 ,
F_113 ( V_111 -> V_119 ) ,
V_111 -> V_121 ,
V_111 -> V_122 ,
V_111 -> V_123 ? 'R' : 'U' ) ;
} else {
V_118 = F_37 ( F_113 ( V_111 -> V_119 ) ) ;
}
if ( ! V_111 -> V_116 ) {
if ( V_117 -> V_124 )
F_114 ( V_117 , L_21 ) ;
F_114 ( V_117 , V_118 ) ;
}
F_5 ( V_118 ) ;
V_110 = V_110 -> V_115 ;
}
return F_115 ( V_117 , FALSE ) ;
}
static T_6
F_116 ( T_1 * V_4 )
{
char * V_125 = F_111 ( V_4 , FALSE ) ;
T_6 V_126 = F_117 ( V_125 , V_4 -> V_6 . string ) == 0 ;
F_5 ( V_125 ) ;
return V_126 ;
}
static void
F_118 ( T_1 * V_4 )
{
* V_4 -> V_5 . V_67 = V_4 -> V_6 . V_67 ;
}
static T_25
F_119 ( T_1 * V_4 V_8 , const T_13 * V_49 V_8 , T_6 * V_78 V_8 )
{
return V_90 ;
}
static const char *
F_120 ( void )
{
return NULL ;
}
static char *
F_121 ( void )
{
return F_37 ( L_5 ) ;
}
static T_6
F_122 ( T_1 * V_4 V_8 )
{
return TRUE ;
}
static char *
F_123 ( T_1 * V_4 V_8 , T_6 V_6 V_8 )
{
return F_37 ( L_5 ) ;
}
static void
F_124 ( T_1 * V_4 , T_17 * * V_49 )
{
T_27 * V_127 , * V_128 ;
T_17 * V_129 ;
V_4 -> V_5 . V_88 = V_49 ;
V_4 -> V_6 . V_88 = NULL ;
for ( V_129 = * V_4 -> V_5 . V_88 ; V_129 != NULL ; V_129 = F_93 ( V_129 ) ) {
V_127 = ( T_27 * ) V_129 -> V_7 ;
V_128 = F_51 ( T_27 , 1 ) ;
V_128 -> V_30 = F_37 ( V_127 -> V_30 ) ;
V_128 -> V_119 = V_127 -> V_119 ;
if ( V_127 -> V_121 ) {
V_128 -> V_121 = F_37 ( V_127 -> V_121 ) ;
V_128 -> V_122 = V_127 -> V_122 ;
} else {
V_128 -> V_121 = NULL ;
V_128 -> V_122 = 0 ;
}
V_128 -> V_116 = V_127 -> V_116 ;
V_128 -> V_123 = V_127 -> V_123 ;
V_4 -> V_6 . V_88 = F_55 ( V_4 -> V_6 . V_88 , V_128 ) ;
}
}
static void
F_125 ( T_1 * V_4 )
{
F_126 ( * V_4 -> V_5 . V_88 ) ;
F_126 ( V_4 -> V_6 . V_88 ) ;
}
static void
F_127 ( T_1 * V_4 )
{
T_27 * V_127 , * V_128 ;
T_17 * V_129 ;
T_1 * V_130 ;
F_126 ( * V_4 -> V_5 . V_88 ) ;
* V_4 -> V_5 . V_88 = NULL ;
for ( V_129 = V_4 -> V_6 . V_88 ; V_129 != NULL ; V_129 = F_93 ( V_129 ) ) {
V_127 = ( T_27 * ) V_129 -> V_7 ;
V_128 = F_51 ( T_27 , 1 ) ;
V_128 -> V_30 = F_37 ( V_127 -> V_30 ) ;
V_128 -> V_119 = V_127 -> V_119 ;
if ( V_127 -> V_121 ) {
V_128 -> V_121 = F_37 ( V_127 -> V_121 ) ;
V_128 -> V_122 = V_127 -> V_122 ;
} else {
V_128 -> V_121 = NULL ;
V_128 -> V_122 = 0 ;
}
V_128 -> V_116 = V_127 -> V_116 ;
V_128 -> V_123 = V_127 -> V_123 ;
* V_4 -> V_5 . V_88 = F_55 ( * V_4 -> V_5 . V_88 , V_128 ) ;
}
V_130 = F_53 ( V_113 , V_131 ) ;
F_25 ( V_130 != NULL ) ;
F_118 ( V_130 ) ;
}
static T_25
F_128 ( T_1 * V_4 , const T_13 * V_49 , T_6 * V_78 V_8 )
{
T_17 * V_132 , * V_133 ;
T_27 * V_111 ;
T_14 V_134 ;
T_1 * V_135 , * V_130 ;
V_132 = F_129 ( V_49 ) ;
if ( V_132 == NULL )
return V_136 ;
if ( ( F_130 ( V_132 ) % 2 ) != 0 ) {
F_131 ( V_132 ) ;
return V_136 ;
}
V_133 = F_92 ( V_132 ) ;
while ( V_133 ) {
T_27 V_137 ;
V_133 = V_133 -> V_115 ;
if ( ! F_132 ( & V_137 , ( char * ) V_133 -> V_7 ) ) {
F_131 ( V_132 ) ;
return V_136 ;
}
if ( V_137 . V_119 != V_120 ) {
F_133 ( & V_133 -> V_7 ) ;
} else {
F_5 ( V_137 . V_121 ) ;
}
V_133 = V_133 -> V_115 ;
}
F_126 ( * V_4 -> V_5 . V_88 ) ;
* V_4 -> V_5 . V_88 = NULL ;
V_135 = F_53 ( V_113 , V_138 ) ;
F_25 ( V_135 != NULL ) ;
V_130 = F_53 ( V_113 , V_131 ) ;
F_25 ( V_130 != NULL ) ;
V_134 = F_130 ( V_132 ) ;
* V_130 -> V_5 . V_67 = V_134 / 2 ;
V_133 = F_92 ( V_132 ) ;
while ( V_133 ) {
V_111 = F_51 ( T_27 , 1 ) ;
V_111 -> V_30 = F_37 ( ( T_13 * ) V_133 -> V_7 ) ;
V_133 = V_133 -> V_115 ;
F_132 ( V_111 , ( char * ) V_133 -> V_7 ) ;
V_111 -> V_116 = F_108 ( * V_135 -> V_5 . string , V_111 ) ;
V_133 = V_133 -> V_115 ;
* V_4 -> V_5 . V_88 = F_55 ( * V_4 -> V_5 . V_88 , V_111 ) ;
}
F_131 ( V_132 ) ;
F_4 ( V_135 ) ;
return V_90 ;
}
static const char *
F_134 ( void )
{
return L_22 ;
}
static char *
F_135 ( void )
{
return F_37 ( L_23 ) ;
}
static T_6
F_136 ( T_1 * V_4 )
{
T_17 * V_110 = * V_4 -> V_5 . V_88 ,
* V_139 = F_92 ( V_110 ) ,
* V_140 = F_92 ( V_4 -> V_6 . V_88 ) ;
T_27 * V_111 , * V_141 ;
T_6 V_126 = TRUE ;
T_1 * V_130 ;
V_130 = F_53 ( V_113 , V_131 ) ;
if ( V_130 && * V_130 -> V_5 . V_67 != V_130 -> V_6 . V_67 ) {
V_126 = FALSE ;
} else {
while ( V_139 && V_140 ) {
V_111 = ( T_27 * ) V_139 -> V_7 ;
V_141 = ( T_27 * ) V_140 -> V_7 ;
if ( ( F_117 ( V_111 -> V_30 , V_141 -> V_30 ) != 0 ) ||
( V_111 -> V_119 != V_141 -> V_119 ) ||
( ( ( V_111 -> V_119 == V_120 ) && ( V_111 -> V_121 ) ) &&
( ( F_117 ( V_111 -> V_121 , V_141 -> V_121 ) != 0 ) ||
( V_111 -> V_123 != V_141 -> V_123 ) ) ) ) {
V_126 = FALSE ;
break;
}
V_139 = V_139 -> V_115 ;
V_140 = V_140 -> V_115 ;
}
}
return V_126 ;
}
static char *
F_137 ( T_1 * V_4 , T_6 V_6 )
{
T_17 * V_142 = V_6 ? V_4 -> V_6 . V_88 : * V_4 -> V_5 . V_88 ;
T_17 * V_110 = F_92 ( V_142 ) ;
T_17 * V_132 ;
T_27 * V_111 ;
T_13 * V_118 ;
char * V_143 ;
V_132 = NULL ;
while ( V_110 ) {
V_111 = ( T_27 * ) V_110 -> V_7 ;
V_132 = F_55 ( V_132 , F_37 ( V_111 -> V_30 ) ) ;
if ( ( V_111 -> V_119 == V_120 ) && ( V_111 -> V_121 ) ) {
V_118 = F_104 ( L_20 ,
F_113 ( V_111 -> V_119 ) ,
V_111 -> V_121 ,
V_111 -> V_122 ,
V_111 -> V_123 ? 'R' : 'U' ) ;
} else {
V_118 = F_37 ( F_113 ( V_111 -> V_119 ) ) ;
}
V_132 = F_55 ( V_132 , V_118 ) ;
V_110 = V_110 -> V_115 ;
}
V_143 = F_138 ( V_132 ) ;
F_131 ( V_132 ) ;
return V_143 ;
}
static void
F_139 ( T_1 * V_4 , T_17 * * V_144 )
{
T_17 * V_145 = * V_144 ,
* V_146 = NULL ;
while ( V_145 ) {
V_146 = F_55 ( V_146 , F_37 ( ( T_13 * ) V_145 -> V_7 ) ) ;
V_145 = V_145 -> V_115 ;
}
V_4 -> V_6 . V_88 = V_146 ;
V_4 -> V_5 . V_88 = & V_1 . V_147 ;
V_4 -> V_22 . V_23 = FALSE ;
}
static void
F_140 ( T_1 * V_4 )
{
F_131 ( V_1 . V_147 ) ;
V_1 . V_147 = NULL ;
if ( V_4 -> V_22 . V_23 == TRUE ) {
F_131 ( V_4 -> V_6 . V_88 ) ;
V_4 -> V_6 . V_88 = NULL ;
}
}
static void
F_141 ( T_1 * V_4 )
{
T_17 * V_148 = NULL , * V_146 ;
F_131 ( * V_4 -> V_5 . V_88 ) ;
for ( V_146 = V_4 -> V_6 . V_88 ; V_146 != NULL ; V_146 = F_93 ( V_146 ) ) {
V_148 = F_55 ( V_148 , F_37 ( ( T_13 * ) V_146 -> V_7 ) ) ;
}
* V_4 -> V_5 . V_88 = V_148 ;
}
static T_25
F_142 ( T_1 * V_4 , const T_13 * V_49 , T_6 * V_78 V_8 )
{
T_17 * V_132 = F_129 ( V_49 ) ;
T_17 * V_133 ;
T_13 * V_149 ;
int V_150 ;
if ( V_132 == NULL )
return V_136 ;
F_140 ( V_4 ) ;
V_133 = F_92 ( V_132 ) ;
if ( ! ( * ( T_13 * ) V_133 -> V_7 ) ) {
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
V_149 = F_37 ( V_152 [ V_150 ] ) ;
V_1 . V_147 = F_55 ( V_1 . V_147 , V_149 ) ;
}
}
while ( V_133 ) {
T_6 V_153 = FALSE ;
V_149 = ( T_13 * ) V_133 -> V_7 ;
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
if ( strcmp ( V_149 , V_152 [ V_150 ] ) == 0 ) {
V_153 = TRUE ;
break;
}
}
if ( ! V_153 ) {
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
V_149 = F_37 ( V_152 [ V_150 ] ) ;
V_1 . V_147 = F_55 ( V_1 . V_147 , V_149 ) ;
}
V_4 -> V_5 . V_88 = & V_1 . V_147 ;
F_131 ( V_132 ) ;
return V_136 ;
}
V_133 = V_133 -> V_115 ;
}
V_133 = F_92 ( V_132 ) ;
while ( V_133 ) {
V_149 = ( T_13 * ) V_133 -> V_7 ;
V_1 . V_147 = F_55 ( V_1 . V_147 , V_149 ) ;
V_133 = V_133 -> V_115 ;
}
V_4 -> V_5 . V_88 = & V_1 . V_147 ;
F_10 ( V_132 ) ;
return V_90 ;
}
static const char *
F_143 ( void )
{
return L_24 ;
}
static char *
F_144 ( void )
{
return F_37 (
L_25
V_154 ) ;
}
static T_6
F_145 ( T_1 * V_4 )
{
T_17 * V_139 = F_92 ( V_1 . V_147 ) ,
* V_140 = F_92 ( V_4 -> V_6 . V_88 ) ;
T_6 V_126 = TRUE ;
while ( V_139 && V_140 ) {
if ( strcmp ( ( T_13 * ) V_139 -> V_7 , ( T_13 * ) V_140 -> V_7 ) != 0 ) {
V_126 = FALSE ;
break;
}
V_139 = V_139 -> V_115 ;
V_140 = V_140 -> V_115 ;
}
if ( ( ( V_139 == NULL ) && ( V_140 != NULL ) ) ||
( ( V_139 != NULL ) && ( V_140 == NULL ) ) )
V_126 = FALSE ;
return V_126 ;
}
static char *
F_146 ( T_1 * V_4 , T_6 V_6 )
{
T_17 * V_142 = V_6 ? V_4 -> V_6 . V_88 : V_1 . V_147 ;
T_17 * V_110 = F_92 ( V_142 ) ;
T_17 * V_132 = NULL ;
T_13 * V_155 ;
char * V_156 ;
while ( V_110 ) {
V_155 = ( T_13 * ) V_110 -> V_7 ;
V_132 = F_55 ( V_132 , F_37 ( V_155 ) ) ;
V_110 = V_110 -> V_115 ;
}
V_156 = F_138 ( V_132 ) ;
F_131 ( V_132 ) ;
return V_156 ;
}
static T_25
F_147 ( T_1 * V_4 , const T_13 * V_49 , T_6 * V_78 )
{
F_67 ( V_4 , V_49 , V_78 ) ;
return V_90 ;
}
static const char *
F_148 ( void )
{
return NULL ;
}
static char *
F_149 ( void )
{
return F_37 ( L_5 ) ;
}
static T_6
F_150 ( T_1 * V_4 V_8 )
{
return TRUE ;
}
static char *
F_151 ( T_1 * V_4 V_8 , T_6 V_6 V_8 )
{
return F_37 ( L_5 ) ;
}
static void
F_30 ( void )
{
T_5 * V_157 , * V_158 , * V_159 ,
* V_160 , * V_161 ;
#ifdef F_152
T_5 * V_162 ;
#endif
struct V_69 V_24 ;
if ( V_41 != NULL ) {
return;
}
#ifdef F_152
V_162 = F_14 ( NULL , L_26 , L_27 ,
L_27 , NULL , FALSE ) ;
V_1 . V_163 = TRUE ;
F_64 ( V_162 , L_28 ,
L_29 ,
L_29 ,
& V_1 . V_163 ) ;
#endif
V_164 = F_14 ( NULL , L_30 , L_31 ,
L_31 , & F_96 , FALSE ) ;
F_65 ( V_164 , L_32 ,
L_33 ,
L_34 ,
( T_14 * ) ( void * ) ( & V_1 . V_165 ) , V_166 , FALSE ) ;
F_87 ( V_164 , L_35 ) ;
F_87 ( V_164 , L_36 ) ;
F_87 ( V_164 , L_37 ) ;
F_64 ( V_164 , L_38 ,
L_39 ,
L_40 ,
& V_1 . V_167 ) ;
F_64 ( V_164 , L_41 ,
L_42 ,
L_43 ,
& V_1 . V_168 ) ;
F_64 ( V_164 , L_44 ,
L_45 ,
L_46 ,
& V_1 . V_169 ) ;
F_65 ( V_164 , L_47 ,
L_48 ,
L_48 ,
& V_1 . V_170 , V_170 , FALSE ) ;
F_65 ( V_164 , L_49 ,
L_50 ,
L_50 ,
& V_1 . V_171 , V_171 , FALSE ) ;
F_65 ( V_164 , L_51 ,
L_52 ,
L_52 ,
& V_1 . V_172 , V_172 , FALSE ) ;
V_113 = F_20 ( V_164 , L_53 , L_53 , NULL ) ;
V_24 . V_25 = F_4 ;
V_24 . V_173 = F_68 ;
V_24 . V_174 = F_107 ;
V_24 . V_175 = F_109 ;
V_24 . V_176 = F_110 ;
V_24 . V_177 = F_116 ;
V_24 . V_178 = F_111 ;
F_66 ( V_113 , V_138 , L_18 ,
L_54 ,
& V_179 , V_20 , & V_24 , FALSE ) ;
V_24 . V_25 = F_125 ;
V_24 . V_173 = F_127 ;
V_24 . V_174 = F_128 ;
V_24 . V_175 = F_134 ;
V_24 . V_176 = F_135 ;
V_24 . V_177 = F_136 ;
V_24 . V_178 = F_137 ;
F_85 ( V_113 , V_114 , L_22 ,
L_23 , & V_24 ,
F_124 , & V_1 . V_180 ) ;
V_24 . V_25 = F_98 ;
V_24 . V_173 = F_118 ;
V_24 . V_174 = F_119 ;
V_24 . V_175 = F_120 ;
V_24 . V_176 = F_121 ;
V_24 . V_177 = F_122 ;
V_24 . V_178 = F_123 ;
F_63 ( V_113 , V_131 , L_55 ,
L_56 , & V_24 , & V_1 . V_181 ) ;
V_161 = F_20 ( V_164 , L_57 , L_57 , NULL ) ;
F_87 ( V_161 , L_58 ) ;
F_66 ( V_161 , L_59 , L_60 ,
L_61 ,
& V_1 . V_182 , V_15 , NULL , TRUE ) ;
F_66 ( V_161 , L_62 , L_60 ,
L_63 ,
& V_1 . V_183 , V_15 , NULL , TRUE ) ;
V_184 = F_20 ( V_164 , L_64 , L_64 , NULL ) ;
F_84 ( V_184 , L_65 , L_66 ,
L_66 , & V_1 . V_185 ) ;
F_84 ( V_184 , L_67 , L_66 ,
L_66 , & V_1 . V_186 ) ;
F_84 ( V_184 , L_68 , L_69 ,
L_69 , & V_1 . V_187 ) ;
F_84 ( V_184 , L_70 , L_69 ,
L_69 , & V_1 . V_188 ) ;
F_84 ( V_184 , L_71 , L_72 ,
L_72 , & V_1 . V_189 ) ;
F_84 ( V_184 , L_73 , L_72 ,
L_72 , & V_1 . V_190 ) ;
F_84 ( V_184 , L_74 , L_72 ,
L_72 , & V_1 . V_191 ) ;
F_84 ( V_184 , L_75 , L_72 ,
L_72 , & V_1 . V_192 ) ;
V_24 . V_25 = F_4 ;
V_24 . V_173 = F_68 ;
V_24 . V_174 = F_147 ;
V_24 . V_175 = F_148 ;
V_24 . V_176 = F_149 ;
V_24 . V_177 = F_150 ;
V_24 . V_178 = F_151 ;
F_66 ( V_113 , L_76 , L_77 ,
L_78 ,
& V_1 . V_193 , V_20 , & V_24 , TRUE ) ;
V_24 . V_25 = F_4 ;
V_24 . V_173 = F_68 ;
V_24 . V_174 = F_147 ;
V_24 . V_175 = F_148 ;
V_24 . V_176 = F_149 ;
V_24 . V_177 = F_150 ;
V_24 . V_178 = F_151 ;
F_66 ( V_113 , L_79 , L_80 ,
L_81 ,
& V_1 . V_194 , V_20 , & V_24 , TRUE ) ;
F_84 ( V_184 , L_82 , L_83 ,
L_83 , & V_1 . V_195 ) ;
F_84 ( V_184 , L_84 , L_85 ,
L_85 , & V_1 . V_196 ) ;
F_84 ( V_184 , L_86 , L_87 ,
L_87 , & V_1 . V_197 ) ;
F_65 ( V_164 , L_88 ,
L_89 ,
L_89 ,
& V_1 . V_198 , V_198 , FALSE ) ;
F_62 ( V_164 , L_90 ,
L_91 ,
L_91 ,
10 ,
& V_1 . V_101 ) ;
F_62 ( V_164 , L_92 ,
L_93 ,
L_93 ,
10 ,
& V_1 . V_102 ) ;
F_66 ( V_164 , L_94 , L_95 ,
L_96 ,
& V_1 . V_199 , V_17 , NULL , TRUE ) ;
F_87 ( V_164 , L_97 ) ;
F_62 ( V_164 , L_98 ,
L_99 ,
L_99 ,
10 ,
& V_1 . V_200 ) ;
F_64 ( V_164 , L_100 ,
L_101 ,
L_102 ,
& V_1 . V_201 ) ;
F_64 ( V_164 , L_103 ,
L_104 ,
L_105 ,
& V_1 . V_202 ) ;
F_64 ( V_164 , L_106 ,
L_107 ,
L_108 ,
& V_1 . V_203 ) ;
F_64 ( V_164 , L_109 ,
L_110 ,
L_111 ,
& V_1 . V_204 ) ;
F_64 ( V_164 , L_112 ,
L_113 ,
L_114 ,
& V_1 . V_205 ) ;
F_64 ( V_164 , L_115 ,
L_116 ,
L_117 ,
& V_1 . V_206 ) ;
F_64 ( V_164 , L_118 ,
L_119 ,
L_120 ,
& V_1 . V_207 ) ;
F_87 ( V_164 , L_121 ) ;
F_87 ( V_164 , L_122 ) ;
F_87 ( V_164 , L_123 ) ;
F_87 ( V_164 , L_124 ) ;
F_87 ( V_164 , L_125 ) ;
F_65 ( V_164 , L_126 ,
L_127 ,
L_127 ,
& V_1 . V_208 , V_209 , FALSE ) ;
F_65 ( V_164 , L_128 ,
L_129 ,
L_129 ,
& V_1 . V_210 , V_209 , FALSE ) ;
F_66 ( V_164 , L_130 , L_131 ,
L_132 ,
& V_1 . V_211 , V_15 , NULL , TRUE ) ;
F_64 ( V_164 , L_133 ,
L_134 ,
L_135 ,
& V_1 . V_212 ) ;
F_65 ( V_164 , L_136 ,
L_137 ,
L_138 ,
( T_14 * ) ( void * ) ( & V_1 . V_213 ) , V_213 , FALSE ) ;
F_62 ( V_164 , L_139 ,
L_140 ,
L_141 ,
10 ,
& V_1 . V_214 ) ;
F_66 ( V_164 , L_142 , L_143 ,
L_144 ,
& V_1 . V_215 , V_15 , NULL , TRUE ) ;
F_66 ( V_164 , L_145 , L_146 ,
L_147 ,
& V_1 . V_216 , V_15 , NULL , TRUE ) ;
F_66 ( V_164 , L_148 , L_149 ,
L_149 ,
& V_1 . V_217 , V_15 , NULL , TRUE ) ;
F_65 ( V_164 , L_150 ,
L_151 ,
L_151 ,
( T_14 * ) ( void * ) ( & V_1 . V_218 ) , V_219 , FALSE ) ;
F_64 ( V_164 , L_152 ,
L_153 ,
L_153 ,
& V_1 . V_220 ) ;
F_62 ( V_164 , L_154 ,
L_155 ,
L_155 ,
10 ,
& V_1 . V_221 ) ;
V_160 = F_20 ( V_164 , L_156 , L_156 , F_97 ) ;
F_62 ( V_160 , L_157 ,
L_158 ,
L_159 ,
10 ,
( T_4 * ) ( void * ) ( & V_1 . V_103 ) ) ;
F_65 ( V_160 , L_160 ,
L_161 ,
L_161 ,
( T_14 * ) ( void * ) ( & V_1 . V_222 ) , V_223 , FALSE ) ;
F_65 ( V_160 , L_162 ,
L_163 ,
L_163 ,
( T_14 * ) ( void * ) ( & V_1 . V_224 ) , V_223 , FALSE ) ;
F_65 ( V_160 , L_164 ,
L_165 ,
L_165 ,
( T_14 * ) ( void * ) ( & V_1 . V_225 ) , V_223 , FALSE ) ;
F_64 ( V_160 , L_166 ,
L_167 ,
L_167 ,
& V_1 . V_226 ) ;
F_64 ( V_164 , L_168 ,
L_169 ,
L_170 ,
& V_1 . V_227 ) ;
F_65 ( V_164 , L_171 ,
L_172 ,
L_173 ,
( T_14 * ) ( void * ) ( & V_1 . V_228 ) , V_228 , FALSE ) ;
F_64 ( V_160 , L_174 ,
L_175 ,
L_176 ,
& V_1 . V_229 ) ;
F_64 ( V_160 , L_177 ,
L_178 ,
L_179 ,
& V_1 . V_230 ) ;
V_159 = F_14 ( NULL , L_180 , L_181 ,
L_182 , NULL , FALSE ) ;
V_24 . V_25 = F_98 ;
V_24 . V_173 = F_99 ;
V_24 . V_174 = F_100 ;
V_24 . V_175 = F_102 ;
V_24 . V_176 = F_103 ;
V_24 . V_177 = F_105 ;
V_24 . V_178 = F_106 ;
F_63 ( V_159 , L_183 , L_184 ,
L_185 , & V_24 , & V_1 . V_231 ) ;
V_158 = F_14 ( NULL , L_186 , L_187 ,
L_188 , NULL , FALSE ) ;
F_66 ( V_158 , L_189 , L_190 ,
L_190 ,
& V_1 . V_232 , V_15 , NULL , FALSE ) ;
F_66 ( V_158 , L_191 , L_192 ,
L_193 ,
& V_1 . V_233 , V_15 , NULL , FALSE ) ;
F_66 ( V_158 , L_194 , L_195 ,
L_196 ,
& V_1 . V_234 , V_15 , NULL , FALSE ) ;
F_66 ( V_158 , L_197 , L_198 ,
L_199 ,
& V_1 . V_235 , V_15 , NULL , FALSE ) ;
F_66 ( V_158 , L_200 , L_201 ,
L_202 ,
& V_1 . V_236 , V_15 , NULL , FALSE ) ;
#ifdef F_153
F_66 ( V_158 , L_203 , L_204 ,
L_205 ,
& V_1 . V_237 , V_15 , NULL , FALSE ) ;
#endif
F_66 ( V_158 , L_206 , L_207 ,
L_208 ,
& V_1 . V_238 , V_15 , NULL , FALSE ) ;
F_66 ( V_158 , L_209 , L_210 ,
L_211 ,
& V_1 . V_239 , V_15 , NULL , FALSE ) ;
F_64 ( V_158 , L_212 , L_213 ,
L_214 , & V_1 . V_240 ) ;
F_66 ( V_158 , L_215 , L_216 ,
L_217 ,
& V_1 . V_241 , V_15 , NULL , FALSE ) ;
F_64 ( V_158 , L_218 , L_219 ,
L_220 , & V_1 . V_242 ) ;
F_64 ( V_158 , L_221 , L_222 ,
L_223 , & V_1 . V_243 ) ;
F_64 ( V_158 , L_224 , L_225 ,
L_226 , & V_1 . V_244 ) ;
F_64 ( V_158 , L_227 , L_228 ,
L_229 , & V_1 . V_245 ) ;
F_87 ( V_158 , L_230 ) ;
V_24 . V_25 = F_140 ;
V_24 . V_173 = F_141 ;
V_24 . V_174 = F_142 ;
V_24 . V_175 = F_143 ;
V_24 . V_176 = F_144 ;
V_24 . V_177 = F_145 ;
V_24 . V_178 = F_146 ;
F_85 ( V_158 , L_1 , L_231 ,
L_232 , & V_24 , F_139 , & V_1 . V_147 ) ;
V_246 = F_14 ( NULL , L_233 , L_234 ,
L_234 , NULL , TRUE ) ;
F_154 ( V_246 ) ;
F_155 ( V_246 ) ;
#ifdef F_156
F_157 ( V_246 ) ;
#endif
V_157 = F_14 ( NULL , L_235 , L_236 ,
L_236 , NULL , TRUE ) ;
F_65 ( V_157 , L_237 ,
L_238 , L_239 ,
& V_1 . V_247 , V_248 , TRUE ) ;
F_65 ( V_157 , L_240 ,
L_241 , L_242 ,
& V_1 . V_249 , V_250 , TRUE ) ;
#ifndef F_158
F_66 ( V_157 , L_243 , L_244 ,
L_245 ,
& V_1 . V_251 , V_15 , NULL , TRUE ) ;
#endif
F_66 ( V_157 , L_246 , L_247 ,
L_248 ,
& V_1 . V_252 , V_16 , NULL , TRUE ) ;
V_48 = F_14 ( NULL , L_249 , L_250 ,
L_250 , & F_94 , TRUE ) ;
F_62 ( V_48 , L_251 ,
L_252 ,
L_253 ,
10 ,
& V_1 . V_93 ) ;
#ifdef F_95
F_62 ( V_48 , L_254 ,
L_255 ,
L_256 ,
10 ,
& V_1 . V_95 ) ;
#endif
F_64 ( V_48 , L_257 ,
L_258 ,
L_259
L_260 ,
& V_1 . V_253 ) ;
F_64 ( V_48 , L_261 ,
L_262 ,
L_263
L_264
L_265 ,
& V_1 . V_254 ) ;
F_62 ( V_48 , L_266 ,
L_267 ,
L_268
L_269 ,
10 , & V_1 . V_97 ) ;
F_62 ( V_48 , L_270 ,
L_271 ,
L_272
L_273
L_274 ,
10 , & V_1 . V_99 ) ;
F_65 ( V_48 , L_275 ,
L_276 ,
L_277
L_278 ,
& V_1 . V_255 , V_256 , FALSE ) ;
F_64 ( V_48 , L_279 ,
L_280 ,
L_281
L_282 ,
& V_1 . V_257 ) ;
F_64 ( V_48 , L_283 ,
L_284 ,
L_285
L_286
L_287 ,
& V_1 . V_258 ) ;
F_64 ( V_48 , L_288 ,
L_289 ,
L_290
L_291
L_292
L_293 ,
& V_1 . V_259 ) ;
F_64 ( V_48 , L_294 ,
L_295 ,
L_290
L_296
L_297
L_298 ,
& V_1 . V_260 ) ;
F_64 ( V_48 , L_299 ,
L_300 ,
L_301
L_302
L_303 ,
& V_1 . V_261 ) ;
V_41 = F_14 ( NULL , L_304 , L_305 ,
L_305 , NULL , TRUE ) ;
F_64 ( V_41 , L_306 ,
L_307 ,
L_308 ,
& V_1 . V_262 ) ;
F_64 ( V_41 , L_309 ,
L_310 ,
L_311 ,
& V_1 . V_263 ) ;
F_64 ( V_41 , L_312 ,
L_313 ,
L_314 ,
& V_1 . V_264 ) ;
F_14 ( NULL , L_315 , L_316 , L_316 , NULL , FALSE ) ;
F_14 ( NULL , L_317 , L_318 , L_318 , NULL , FALSE ) ;
F_14 ( NULL , L_319 , L_320 , L_320 , NULL , FALSE ) ;
}
T_17 *
F_129 ( const T_13 * V_265 )
{
enum { V_266 , V_267 , V_268 };
T_14 V_269 = V_266 , V_150 = 0 , V_270 = 0 ;
T_6 V_271 = FALSE ;
T_7 V_272 ;
T_13 * V_273 = NULL ;
T_17 * V_274 = NULL ;
V_273 = ( T_13 * ) F_159 ( sizeof( T_13 ) * V_275 ) ;
V_270 = 0 ;
for (; ; ) {
V_272 = V_265 [ V_150 ] ;
if ( V_272 == '\0' ) {
if ( V_269 == V_267 || V_271 ) {
F_5 ( V_273 ) ;
F_131 ( V_274 ) ;
return NULL ;
}
V_273 [ V_270 ] = '\0' ;
V_274 = F_55 ( V_274 , V_273 ) ;
break;
}
if ( V_272 == '"' && ! V_271 ) {
switch ( V_269 ) {
case V_266 :
V_269 = V_267 ;
break;
case V_267 :
V_269 = V_268 ;
break;
case V_268 :
V_269 = V_267 ;
break;
default:
break;
}
} else if ( V_272 == '\\' && ! V_271 ) {
V_271 = TRUE ;
if ( V_269 == V_266 )
V_269 = V_268 ;
} else if ( V_272 == ',' && V_269 != V_267 && ! V_271 ) {
V_273 [ V_270 ] = '\0' ;
V_274 = F_55 ( V_274 , V_273 ) ;
V_269 = V_266 ;
V_273 = ( T_13 * ) F_159 ( sizeof( T_13 ) * V_275 ) ;
V_270 = 0 ;
} else if ( ! F_160 ( V_272 ) || V_269 != V_266 ) {
if ( V_270 < V_275 ) {
V_273 [ V_270 ] = V_272 ;
V_270 ++ ;
}
V_271 = FALSE ;
}
V_150 ++ ;
}
return ( V_274 ) ;
}
char * F_138 ( T_17 * V_274 )
{
T_28 * V_276 = F_112 ( L_5 ) ;
T_17 * V_277 , * V_278 ;
T_13 * V_265 ;
T_13 * V_279 ;
T_4 V_280 = 0 ;
V_277 = V_278 = F_92 ( V_274 ) ;
while ( V_277 ) {
V_280 ++ ;
V_265 = ( T_13 * ) V_277 -> V_7 ;
if ( V_277 != V_278 )
F_161 ( V_276 , ',' ) ;
if ( V_280 % 2 ) {
F_114 ( V_276 , L_321 ) ;
} else
F_161 ( V_276 , ' ' ) ;
V_279 = F_162 ( V_265 , L_5 ) ;
F_163 ( V_276 , L_322 , V_279 ) ;
F_5 ( V_279 ) ;
V_277 = V_277 -> V_115 ;
}
return F_115 ( V_276 , FALSE ) ;
}
void
F_131 ( T_17 * V_274 )
{
F_9 ( V_274 , ( V_281 ) F_5 , NULL ) ;
F_10 ( V_274 ) ;
}
static T_14
F_164 ( const char * V_282 , const T_18 * V_283 ,
T_14 V_284 )
{
int V_150 ;
for ( V_150 = 0 ; V_283 [ V_150 ] . V_21 != NULL ; V_150 ++ ) {
if ( F_165 ( V_282 , V_283 [ V_150 ] . V_21 ) == 0 ) {
return V_283 [ V_150 ] . V_49 ;
}
}
for ( V_150 = 0 ; V_283 [ V_150 ] . V_21 != NULL ; V_150 ++ ) {
if ( F_165 ( V_282 , V_283 [ V_150 ] . V_31 ) == 0 ) {
return V_283 [ V_150 ] . V_49 ;
}
}
return V_284 ;
}
static T_6
F_166 ( const T_13 * V_119 )
{
T_4 V_285 ;
for ( V_285 = 0 ;
V_285 < F_167 ( V_286 ) ;
++ V_285 ) {
if ( strcmp ( V_286 [ V_285 ] . V_287 , V_119 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
static T_6
F_132 ( T_27 * V_111 , const char * V_119 )
{
const T_13 * V_288 = F_113 ( V_120 ) ;
T_29 V_289 = strlen ( V_288 ) ;
T_13 * * V_290 ;
char * V_35 ;
int V_287 ;
T_13 * V_291 = NULL ;
long V_292 = 0 ;
T_6 V_293 = TRUE ;
if ( ( strlen ( V_119 ) > V_289 ) && ( V_119 [ V_289 ] == ':' ) &&
strncmp ( V_119 , V_288 , V_289 ) == 0 ) {
V_287 = V_120 ;
V_290 = F_168 ( & V_119 [ V_289 + 1 ] , L_323 , 3 ) ;
V_291 = F_37 ( V_290 [ 0 ] ) ;
if ( V_291 && V_290 [ 1 ] ) {
V_292 = strtol ( V_290 [ 1 ] , & V_35 , 10 ) ;
if ( V_35 == V_290 [ 1 ] || * V_35 != '\0' ) {
F_5 ( V_291 ) ;
F_169 ( V_290 ) ;
return FALSE ;
}
}
if ( V_291 && V_290 [ 1 ] && V_290 [ 2 ] ) {
V_293 = ( V_290 [ 2 ] [ 0 ] == 'U' ) ? FALSE : TRUE ;
}
F_169 ( V_290 ) ;
} else {
V_287 = F_170 ( V_119 ) ;
if ( ( V_287 == - 1 ) && ( ! F_166 ( V_119 ) ) )
return FALSE ;
}
V_111 -> V_119 = V_287 ;
V_111 -> V_121 = V_291 ;
V_111 -> V_122 = ( int ) V_292 ;
V_111 -> V_123 = V_293 ;
return TRUE ;
}
static void
F_171 ( void )
{
if ( V_294 )
return;
F_172 () ;
F_29 () ;
F_30 () ;
F_173 () ;
V_294 = TRUE ;
}
static void
F_29 ( void )
{
int V_150 ;
T_13 * V_149 ;
T_27 * V_111 ;
static const T_13 * V_287 [ V_295 * 2 ] = {
L_324 , L_325 , L_326 , L_327 ,
L_328 , L_329 , L_330 , L_331 ,
L_332 , L_333 , L_334 , L_335 ,
L_336 , L_337 } ;
V_1 . V_247 = V_296 ;
V_1 . V_249 = V_297 ;
if ( V_1 . V_252 ) F_5 ( V_1 . V_252 ) ;
V_1 . V_252 = F_37 ( L_338 ) ;
if ( V_1 . V_251 ) F_5 ( V_1 . V_251 ) ;
V_1 . V_251 = F_37 ( L_339 ) ;
V_1 . V_167 = FALSE ;
V_1 . V_168 = FALSE ;
V_1 . V_170 = 0 ;
V_1 . V_171 = 1 ;
V_1 . V_172 = 1 ;
V_1 . V_169 = FALSE ;
V_1 . V_208 = V_298 ;
V_1 . V_210 = V_299 ;
if ( V_1 . V_182 ) F_5 ( V_1 . V_182 ) ;
#ifdef F_158
V_1 . V_182 = F_37 ( L_340 ) ;
#else
V_1 . V_182 = F_37 ( L_341 ) ;
#endif
if ( V_1 . V_183 ) F_5 ( V_1 . V_183 ) ;
V_1 . V_183 = F_37 ( L_5 ) ;
V_1 . V_185 . V_300 = 65535 ;
V_1 . V_185 . V_301 = 65535 ;
V_1 . V_185 . V_302 = 65535 ;
V_1 . V_186 . V_300 = 0 ;
V_1 . V_186 . V_301 = 8224 ;
V_1 . V_186 . V_302 = 10794 ;
V_1 . V_187 . V_300 = 32767 ;
V_1 . V_187 . V_301 = 32767 ;
V_1 . V_187 . V_302 = 32767 ;
V_1 . V_188 . V_300 = 65535 ;
V_1 . V_188 . V_301 = 65535 ;
V_1 . V_188 . V_302 = 65535 ;
if ( V_1 . V_193 ) F_5 ( V_1 . V_193 ) ;
V_1 . V_193 = F_37 ( L_342 ) ;
if ( V_1 . V_194 ) F_5 ( V_1 . V_194 ) ;
V_1 . V_194 = F_37 ( L_343 ) ;
V_1 . V_189 . V_300 = 32767 ;
V_1 . V_189 . V_301 = 0 ;
V_1 . V_189 . V_302 = 0 ;
V_1 . V_190 . V_300 = 64507 ;
V_1 . V_190 . V_301 = 60909 ;
V_1 . V_190 . V_302 = 60909 ;
V_1 . V_191 . V_300 = 0 ;
V_1 . V_191 . V_301 = 0 ;
V_1 . V_191 . V_302 = 32767 ;
V_1 . V_192 . V_300 = 60909 ;
V_1 . V_192 . V_301 = 60909 ;
V_1 . V_192 . V_302 = 64507 ;
V_1 . V_195 . V_300 = 0xAFFF ;
V_1 . V_195 . V_301 = 0xFFFF ;
V_1 . V_195 . V_302 = 0xAFFF ;
V_1 . V_196 . V_300 = 0xFFFF ;
V_1 . V_196 . V_301 = 0xAFFF ;
V_1 . V_196 . V_302 = 0xAFFF ;
V_1 . V_197 . V_300 = 0xFFFF ;
V_1 . V_197 . V_301 = 0xFFFF ;
V_1 . V_197 . V_302 = 0xAFFF ;
V_1 . V_204 = TRUE ;
V_1 . V_205 = TRUE ;
V_1 . V_206 = TRUE ;
V_1 . V_207 = TRUE ;
V_1 . V_165 = V_303 ;
V_1 . V_198 = V_304 ;
V_1 . V_102 = 10 ;
V_1 . V_101 = 10 ;
if ( V_1 . V_199 ) F_5 ( V_1 . V_199 ) ;
V_1 . V_199 = F_37 ( F_174 () ) ;
V_1 . V_200 = 3 ;
V_1 . V_201 = TRUE ;
V_1 . V_202 = TRUE ;
V_1 . V_203 = FALSE ;
V_1 . V_212 = TRUE ;
V_1 . V_213 = V_305 ;
V_1 . V_214 = 60 * 60 * 24 ;
if ( V_1 . V_211 ) F_5 ( V_1 . V_211 ) ;
V_1 . V_211 = F_37 ( L_5 ) ;
if ( V_1 . V_215 ) F_5 ( V_1 . V_215 ) ;
V_1 . V_215 = F_37 ( L_5 ) ;
if ( V_1 . V_216 ) F_5 ( V_1 . V_216 ) ;
V_1 . V_216 = F_37 ( L_5 ) ;
if ( V_1 . V_217 ) F_5 ( V_1 . V_217 ) ;
V_1 . V_217 = F_37 ( L_344 ) ;
V_1 . V_218 = V_306 ;
V_1 . V_220 = FALSE ;
V_1 . V_221 = 0 ;
V_1 . V_103 = V_106 ;
V_1 . V_222 = V_307 ;
V_1 . V_224 = V_308 ;
V_1 . V_225 = V_309 ;
V_1 . V_227 = FALSE ;
V_1 . V_228 = V_310 ;
V_1 . V_229 = TRUE ;
V_1 . V_230 = TRUE ;
V_1 . V_226 = FALSE ;
if ( V_1 . V_180 ) {
F_126 ( V_1 . V_180 ) ;
V_1 . V_180 = NULL ;
}
for ( V_150 = 0 ; V_150 < V_295 ; V_150 ++ ) {
V_111 = F_51 ( T_27 , 1 ) ;
V_111 -> V_30 = F_37 ( V_287 [ V_150 * 2 ] ) ;
F_132 ( V_111 , V_287 [ ( V_150 * 2 ) + 1 ] ) ;
V_111 -> V_116 = TRUE ;
V_111 -> V_123 = TRUE ;
V_111 -> V_121 = NULL ;
V_111 -> V_122 = 0 ;
V_1 . V_180 = F_55 ( V_1 . V_180 , V_111 ) ;
}
V_1 . V_181 = V_295 ;
V_1 . V_240 = TRUE ;
#ifdef F_175
V_1 . V_242 = TRUE ;
#else
V_1 . V_242 = FALSE ;
#endif
V_1 . V_243 = TRUE ;
V_1 . V_244 = TRUE ;
V_1 . V_245 = FALSE ;
if ( ! V_1 . V_147 ) {
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
V_149 = F_37 ( V_152 [ V_150 ] ) ;
V_1 . V_147 = F_55 ( V_1 . V_147 , V_149 ) ;
}
}
V_1 . V_231 =
V_311 | V_312 | V_313 ;
V_1 . V_93 = V_94 ;
V_1 . V_95 = V_96 ;
V_1 . V_253 = TRUE ;
V_1 . V_254 = FALSE ;
V_1 . V_97 = V_314 ;
V_1 . V_99 = V_315 ;
V_1 . V_258 = TRUE ;
V_1 . V_260 = TRUE ;
V_1 . V_259 = TRUE ;
V_1 . V_255 = V_316 ;
V_1 . V_257 = TRUE ;
V_1 . V_261 = FALSE ;
V_1 . V_262 = FALSE ;
V_1 . V_263 = FALSE ;
}
static void
F_176 ( T_1 * V_4 )
{
int type ;
if ( ! V_4 ) return;
type = V_4 -> type ;
if ( F_54 ( type ) )
return;
else
F_7 ( type ) ;
switch ( type ) {
case V_11 :
* V_4 -> V_5 . V_67 = V_4 -> V_6 . V_67 ;
break;
case V_9 :
* V_4 -> V_5 . V_70 = V_4 -> V_6 . V_23 ;
break;
case V_10 :
* V_4 -> V_5 . V_73 = V_4 -> V_6 . V_74 ;
break;
case V_15 :
case V_16 :
case V_17 :
F_68 ( V_4 ) ;
break;
case V_18 :
F_5 ( * V_4 -> V_5 . V_19 ) ;
* V_4 -> V_5 . V_19 = F_76 ( V_4 -> V_6 . V_19 ) ;
break;
case V_12 :
case V_13 :
break;
case V_14 :
* V_4 -> V_5 . V_86 = V_4 -> V_6 . V_85 ;
break;
case V_20 :
V_4 -> V_24 . V_173 ( V_4 ) ;
break;
}
}
static void
F_177 ( T_2 V_7 , T_2 T_3 V_8 )
{
T_1 * V_4 = ( T_1 * ) V_7 ;
F_176 ( V_4 ) ;
}
static T_6
F_178 ( const void * T_9 V_8 , void * V_49 , void * V_7 V_8 )
{
T_30 V_60 ;
V_60 . V_26 = ( T_5 * ) V_49 ;
F_9 ( V_60 . V_26 -> V_1 , F_177 , & V_60 ) ;
return FALSE ;
}
void
F_179 ( void )
{
V_294 = FALSE ;
F_5 ( V_1 . V_317 ) ;
V_1 . V_317 = NULL ;
F_180 () ;
F_181 () ;
F_182 ( * V_318 ) ;
* V_318 = NULL ;
F_171 () ;
F_44 ( V_2 , F_178 , NULL ) ;
}
T_31 *
F_183 ( int * V_319 , int * V_320 ,
char * * V_321 , int * V_322 ,
int * V_323 , char * * V_324 )
{
int V_325 ;
char * V_326 ;
T_32 * V_327 ;
F_181 () ;
F_171 () ;
if ( V_328 == NULL ) {
V_328 = F_184 ( V_329 ) ;
if ( ( V_327 = F_185 ( V_328 , L_345 ) ) == NULL && V_330 == V_331 ) {
F_5 ( V_328 ) ;
V_328 = F_184 ( V_332 ) ;
V_327 = F_185 ( V_328 , L_345 ) ;
}
} else {
V_327 = F_185 ( V_328 , L_345 ) ;
}
* V_321 = NULL ;
if ( V_327 != NULL ) {
V_333 = 0 ;
V_334 = 0 ;
V_325 = F_186 ( V_328 , V_327 , V_335 , NULL ) ;
if ( V_325 != 0 ) {
* V_319 = 0 ;
* V_320 = V_325 ;
* V_321 = V_328 ;
}
fclose ( V_327 ) ;
} else {
if ( V_330 != V_331 ) {
* V_319 = V_330 ;
* V_320 = 0 ;
* V_321 = V_328 ;
}
}
V_326 = F_187 ( V_329 , TRUE ) ;
* V_324 = NULL ;
if ( ( V_327 = F_185 ( V_326 , L_345 ) ) != NULL ) {
V_333 = 0 ;
V_334 = 0 ;
V_325 = F_186 ( V_326 , V_327 , V_335 , NULL ) ;
if ( V_325 != 0 ) {
* V_322 = 0 ;
* V_323 = V_325 ;
* V_324 = V_326 ;
} else
F_5 ( V_326 ) ;
fclose ( V_327 ) ;
} else {
if ( V_330 != V_331 ) {
* V_322 = V_330 ;
* V_323 = 0 ;
* V_324 = V_326 ;
} else
F_5 ( V_326 ) ;
}
F_188 () ;
return & V_1 ;
}
int
F_186 ( const char * V_326 , T_32 * V_327 ,
T_33 V_336 , void * V_337 )
{
enum {
V_338 ,
V_339 ,
V_340 ,
V_341 ,
V_342
} V_269 = V_338 ;
int V_343 ;
T_28 * V_344 ;
T_28 * V_345 ;
T_6 V_346 = FALSE ;
T_14 V_347 = 1 , V_348 = 1 ;
T_13 V_349 [] = L_346 ;
T_13 V_350 [ 128 ] ;
V_344 = F_112 ( L_5 ) ;
V_345 = F_112 ( L_5 ) ;
if ( fscanf ( V_327 , L_347 , V_350 ) == 1 ) {
F_5 ( V_1 . V_317 ) ;
V_1 . V_317 = F_189 ( V_350 , strlen ( V_350 ) - 1 ) ;
}
rewind ( V_327 ) ;
while ( ( V_343 = F_190 ( V_327 ) ) != V_351 ) {
if ( V_343 == '\r' ) {
V_343 = F_190 ( V_327 ) ;
if ( V_343 == V_351 )
break;
if ( V_343 != '\n' ) {
ungetc ( V_343 , V_327 ) ;
V_343 = '\r' ;
}
}
if ( V_343 == '\n' ) {
V_269 = V_338 ;
V_347 ++ ;
continue;
}
switch ( V_269 ) {
case V_338 :
if ( F_191 ( V_343 ) ) {
if ( V_345 -> V_124 > 0 ) {
if ( V_346 ) {
if ( V_344 -> V_124 > 0 ) {
if ( V_344 -> V_265 [ V_344 -> V_124 - 1 ] == ',' ) {
V_344 -> V_265 [ V_344 -> V_124 - 1 ] = '\0' ;
F_192 ( L_348 , V_326 , V_348 , V_345 -> V_265 , V_349 ) ;
}
}
switch ( V_336 ( V_345 -> V_265 , V_344 -> V_265 , V_337 , FALSE ) ) {
case V_90 :
break;
case V_136 :
F_192 ( L_349 ,
V_345 -> V_265 , V_348 , V_326 , V_349 ) ;
break;
case V_91 :
if ( strcmp ( V_345 -> V_265 , L_350 ) != 0 )
F_192 ( L_351 ,
V_345 -> V_265 , V_348 , V_326 , V_349 ) ;
V_1 . V_352 = TRUE ;
break;
case V_353 :
if ( strcmp ( V_345 -> V_265 , L_350 ) != 0 )
F_192 ( L_352 ,
V_345 -> V_265 , V_348 , V_326 , V_349 ) ;
V_1 . V_352 = TRUE ;
break;
}
} else {
F_192 ( L_353 , V_348 , V_326 , V_349 ) ;
}
}
V_269 = V_339 ;
V_346 = FALSE ;
F_193 ( V_345 , 0 ) ;
F_161 ( V_345 , ( T_13 ) V_343 ) ;
V_348 = V_347 ;
} else if ( F_160 ( V_343 ) && V_345 -> V_124 > 0 && V_346 ) {
V_269 = V_340 ;
} else if ( V_343 == '#' ) {
V_269 = V_342 ;
} else {
F_192 ( L_354 , V_347 , V_326 , V_349 ) ;
}
break;
case V_339 :
if ( V_343 != ':' ) {
F_161 ( V_345 , ( T_13 ) V_343 ) ;
} else {
V_269 = V_340 ;
F_193 ( V_344 , 0 ) ;
V_346 = TRUE ;
}
break;
case V_340 :
if ( ! F_160 ( V_343 ) ) {
V_269 = V_341 ;
F_161 ( V_344 , ( T_13 ) V_343 ) ;
}
break;
case V_341 :
F_161 ( V_344 , ( T_13 ) V_343 ) ;
break;
case V_342 :
break;
}
}
if ( V_345 -> V_124 > 0 ) {
if ( V_346 ) {
switch ( V_336 ( V_345 -> V_265 , V_344 -> V_265 , V_337 , FALSE ) ) {
case V_90 :
break;
case V_136 :
F_192 ( L_355 ,
V_345 -> V_265 , V_348 , V_326 , V_349 ) ;
break;
case V_91 :
F_192 ( L_351 ,
V_345 -> V_265 , V_348 , V_326 , V_349 ) ;
V_1 . V_352 = TRUE ;
break;
case V_353 :
V_1 . V_352 = TRUE ;
break;
}
} else {
F_192 ( L_356 ,
V_348 , V_326 , V_349 ) ;
}
}
F_115 ( V_344 , TRUE ) ;
F_115 ( V_345 , TRUE ) ;
if ( ferror ( V_327 ) )
return V_330 ;
else
return 0 ;
}
static T_6
F_194 ( char * V_354 ) {
T_13 * V_35 , * V_355 ;
T_21 * V_83 ;
T_13 * V_325 = NULL ;
T_6 V_51 ;
V_355 = strchr ( V_354 , ':' ) ;
if ( V_355 == NULL )
return FALSE ;
V_35 = V_355 ;
* V_35 ++ = '\0' ;
while ( F_160 ( * V_35 ) )
V_35 ++ ;
if ( * V_35 == '\0' ) {
* V_355 = ':' ;
return FALSE ;
}
V_83 = F_195 ( V_354 ) ;
* V_355 = ':' ;
if ( V_83 == NULL ) {
return FALSE ;
}
V_51 = F_196 ( V_83 , V_35 , & V_325 ) ;
F_5 ( V_325 ) ;
return V_51 ;
}
T_25
F_197 ( char * V_356 )
{
T_13 * V_35 , * V_355 ;
T_25 V_51 ;
V_333 = - 1 ;
V_334 = - 1 ;
V_355 = strchr ( V_356 , ':' ) ;
if ( V_355 == NULL )
return V_136 ;
V_35 = V_355 ;
* V_35 ++ = '\0' ;
while ( F_160 ( * V_35 ) )
V_35 ++ ;
if ( * V_35 == '\0' ) {
* V_355 = ':' ;
return V_136 ;
}
if ( strcmp ( V_356 , L_357 ) ) {
V_51 = V_335 ( V_356 , V_35 , NULL , TRUE ) ;
} else {
V_51 = F_194 ( V_35 ) ? V_90 : V_136 ;
}
* V_355 = ':' ;
return V_51 ;
}
T_6
F_198 ( const char * V_21 )
{
T_13 * V_357 , * V_358 ;
T_29 V_124 ;
if ( V_1 . V_235 && V_21 ) {
V_358 = F_37 ( V_1 . V_235 ) ;
V_124 = strlen ( V_21 ) ;
for ( V_357 = strtok ( V_358 , L_21 ) ; V_357 ; V_357 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_357 ) == V_124 && strcmp ( V_21 , V_357 ) == 0 ) {
F_5 ( V_358 ) ;
return TRUE ;
}
}
F_5 ( V_358 ) ;
}
return FALSE ;
}
static T_6
F_108 ( const T_13 * V_117 , T_27 * V_111 )
{
T_13 * V_357 , * V_359 ;
T_27 V_360 ;
if ( V_117 ) {
V_359 = F_37 ( V_117 ) ;
for ( V_357 = strtok ( V_359 , L_21 ) ; V_357 ; V_357 = strtok ( NULL , L_21 ) ) {
V_357 = F_199 ( V_357 ) ;
if ( ! F_132 ( & V_360 , V_357 ) ) {
continue;
}
if ( V_111 -> V_119 != V_360 . V_119 ) {
F_5 ( V_360 . V_121 ) ;
V_360 . V_121 = NULL ;
continue;
}
if ( V_111 -> V_119 == V_120 ) {
if ( V_360 . V_121 && V_111 -> V_121 ) {
if ( strcmp ( V_111 -> V_121 ,
V_360 . V_121 ) != 0 ) {
F_5 ( V_360 . V_121 ) ;
V_360 . V_121 = NULL ;
continue;
}
if ( V_111 -> V_122 != V_360 . V_122 ) {
F_5 ( V_360 . V_121 ) ;
V_360 . V_121 = NULL ;
continue;
}
}
}
F_5 ( V_360 . V_121 ) ;
F_5 ( V_359 ) ;
return FALSE ;
}
F_5 ( V_359 ) ;
}
return TRUE ;
}
T_6
F_200 ( const char * V_21 )
{
T_13 * V_357 , * V_358 ;
T_29 V_124 ;
if ( V_1 . V_236 && V_21 ) {
V_358 = F_37 ( V_1 . V_236 ) ;
V_124 = strlen ( V_21 ) ;
for ( V_357 = strtok ( V_358 , L_21 ) ; V_357 ; V_357 = strtok ( NULL , L_21 ) ) {
if ( strlen ( V_357 ) == V_124 && strcmp ( V_21 , V_357 ) == 0 ) {
F_5 ( V_358 ) ;
return TRUE ;
}
}
F_5 ( V_358 ) ;
}
return FALSE ;
}
T_6
F_201 ( const T_13 * V_361 )
{
T_17 * V_362 ;
T_13 * V_155 ;
for ( V_362 = F_92 ( V_1 . V_147 ) ; V_362 ; V_362 = F_93 ( V_362 ) ) {
V_155 = ( T_13 * ) V_362 -> V_7 ;
if ( V_155 && ( F_165 ( V_155 , V_361 ) == 0 ) ) {
return TRUE ;
}
}
return FALSE ;
}
char
F_202 ( const char * string , T_34 * V_363 )
{
char V_36 ;
memset ( V_363 , 0 , sizeof( T_34 ) ) ;
while ( ( V_36 = * string ++ ) != '\0' ) {
switch ( V_36 ) {
case 'm' :
V_363 -> V_364 = TRUE ;
break;
case 'n' :
V_363 -> V_365 = TRUE ;
break;
case 'N' :
V_363 -> V_366 = TRUE ;
break;
case 't' :
V_363 -> V_367 = TRUE ;
break;
case 'C' :
break;
case 'd' :
V_363 -> V_368 = TRUE ;
break;
case 'v' :
V_363 -> V_369 = TRUE ;
break;
default:
return V_36 ;
}
}
return '\0' ;
}
static void
F_133 ( T_2 * V_370 )
{
T_4 V_285 ;
T_13 * * V_119 = ( T_13 * * ) V_370 ;
for ( V_285 = 0 ;
V_285 < F_167 ( V_286 ) ;
++ V_285 ) {
if ( strcmp ( V_286 [ V_285 ] . V_287 , * V_119 ) == 0 ) {
T_13 * V_371 = F_104 ( L_358 ,
V_286 [ V_285 ] . V_372 ) ;
F_5 ( * V_119 ) ;
* V_119 = V_371 ;
}
}
}
static T_6
F_203 ( T_13 * V_373 , const T_13 * V_49 )
{
struct V_374
{
const char * V_373 ;
const char * V_375 ;
T_6 V_376 ;
};
struct V_374 V_377 [] = {
{ L_359 , L_360 , 0 } ,
{ L_361 , L_362 , 1 } ,
{ L_361 , L_363 , 0 } ,
{ L_364 , L_365 , 0 } ,
{ L_366 , L_367 , 0 } ,
{ L_368 , L_369 , 0 } ,
{ L_370 , L_371 , 0 } ,
{ L_372 , L_373 , 0 } ,
{ L_374 , L_375 , 1 } ,
{ L_374 , L_376 , 0 } ,
{ L_377 , L_378 , 0 } ,
{ L_379 , L_380 , 0 } ,
{ L_381 , L_382 , 0 } ,
{ L_383 , L_384 , 0 } ,
{ L_385 , L_386 , 0 } ,
{ L_387 , L_388 , 0 } ,
{ L_389 , L_390 , 0 } ,
{ L_391 , L_392 , 0 } ,
{ L_393 , L_394 , 0 } ,
{ L_395 , L_396 , 0 } ,
{ L_397 , L_398 , 0 } ,
{ L_399 , L_400 , 0 } ,
{ L_401 , L_402 , 0 } ,
{ L_403 , L_404 , 0 } ,
{ L_405 , L_406 , 0 } ,
{ L_407 , L_408 , 0 } ,
{ L_409 , L_410 , 1 } ,
{ L_409 , L_411 , 0 } ,
{ L_412 , L_413 , 1 } ,
{ L_412 , L_414 , 0 } ,
{ L_415 , L_416 , 0 } ,
{ L_417 , L_418 , 0 } ,
{ L_419 , L_420 , 1 } ,
{ L_419 , L_421 , 1 } ,
{ L_419 , L_422 , 0 } ,
{ L_423 , L_424 , 0 } ,
{ L_425 , L_426 , 0 } ,
} ;
unsigned int V_150 ;
T_35 * V_378 ;
for ( V_150 = 0 ; V_150 < sizeof( V_377 ) / sizeof( struct V_374 ) ; V_150 ++ )
{
if ( strcmp ( V_373 , V_377 [ V_150 ] . V_373 ) == 0 )
{
V_378 = F_204 ( V_377 [ V_150 ] . V_375 ) ;
if ( V_378 != NULL ) {
V_378 -> V_379 = ( ( F_165 ( V_49 , L_427 ) == 0 ) ? TRUE : FALSE ) ;
}
if ( ! V_377 [ V_150 ] . V_376 )
return TRUE ;
}
}
return FALSE ;
}
static T_25
V_335 ( T_13 * V_373 , const T_13 * V_49 , void * V_337 V_8 ,
T_6 V_80 )
{
unsigned long int V_380 ;
T_4 V_107 ;
T_6 V_381 ;
T_14 V_382 ;
char * V_35 ;
T_13 * V_383 , * V_384 ;
static T_13 * V_385 = NULL ;
static T_6 V_386 = FALSE ;
T_13 * V_387 = NULL ;
T_5 * V_26 , * V_63 ;
T_1 * V_4 ;
int type ;
if ( strcmp ( V_373 , V_388 ) == 0 ) {
V_385 = F_37 ( V_49 ) ;
} else if ( strcmp ( V_373 , V_389 ) == 0 ) {
V_386 = ( strcmp ( V_49 , L_428 ) == 0 ) ? TRUE : FALSE ;
} else if ( strcmp ( V_373 , V_390 ) == 0 ) {
V_387 = F_37 ( V_49 ) ;
F_205 ( V_385 , V_387 , V_386 ) ;
F_5 ( V_385 ) ;
F_5 ( V_387 ) ;
} else if ( strcmp ( V_373 , L_429 ) == 0 ) {
if ( F_165 ( V_49 , L_427 ) == 0 ) {
V_1 . V_218 = V_306 ;
} else {
V_1 . V_218 = V_391 ;
}
} else if ( strcmp ( V_373 , L_430 ) == 0 ||
strcmp ( V_373 , L_431 ) == 0 ) {
if ( F_165 ( V_49 , L_427 ) == 0 ) {
V_392 . V_364 = TRUE ;
V_392 . V_365 = TRUE ;
V_392 . V_367 = TRUE ;
}
else if ( F_165 ( V_49 , L_432 ) == 0 ) {
F_206 () ;
}
else {
F_206 () ;
if ( F_202 ( V_49 , & V_392 ) != '\0' )
return V_136 ;
}
} else if ( F_203 ( V_373 , V_49 ) ) {
} else {
if ( ( strcmp ( V_373 , L_433 ) == 0 ) ||
( strcmp ( V_373 , L_434 ) == 0 ) ||
( strcmp ( V_373 , L_435 ) == 0 ) ) {
V_26 = V_246 ;
V_383 = V_373 ;
} else {
V_26 = NULL ;
V_384 = V_373 ;
while ( ! V_26 ) {
V_383 = strchr ( V_384 , '.' ) ;
if ( V_383 == NULL ) {
return V_91 ;
}
* V_383 = '\0' ;
V_26 = F_22 ( V_373 ) ;
if ( V_26 == NULL ) {
if ( strcmp ( V_373 , L_436 ) == 0 )
V_26 = V_113 ;
else if ( strcmp ( V_373 , L_437 ) == 0 )
V_26 = F_22 ( L_438 ) ;
else if ( strcmp ( V_373 , L_439 ) == 0 )
V_26 = F_22 ( L_440 ) ;
else if ( strcmp ( V_373 , L_441 ) == 0 ||
strcmp ( V_373 , L_442 ) == 0 )
V_26 = F_22 ( L_443 ) ;
else if ( strcmp ( V_373 , L_444 ) == 0 )
V_26 = F_22 ( L_445 ) ;
else if ( strcmp ( V_373 , L_446 ) == 0 )
V_26 = F_22 ( L_447 ) ;
else if ( strcmp ( V_373 , L_448 ) == 0 )
V_26 = F_22 ( L_449 ) ;
else if ( strcmp ( V_373 , L_450 ) == 0 )
V_26 = F_22 ( L_451 ) ;
else if ( strcmp ( V_373 , L_452 ) == 0 )
V_26 = F_22 ( L_453 ) ;
else if ( strcmp ( V_373 , L_454 ) == 0 )
V_26 = F_22 ( L_455 ) ;
else if ( strcmp ( V_373 , L_456 ) == 0 ||
strcmp ( V_373 , L_457 ) == 0 ) {
return V_353 ;
}
if ( V_26 ) {
F_192 ( L_458
L_459 ,
V_373 , V_383 + 1 , V_26 -> V_29 -> V_21 , V_373 , V_383 + 1 ) ;
V_1 . V_352 = TRUE ;
}
}
* V_383 = '.' ;
V_383 ++ ;
V_384 = V_383 ;
}
}
V_63 = V_26 ;
V_4 = F_59 ( V_26 , V_383 , & V_63 ) ;
if ( V_4 == NULL ) {
V_1 . V_352 = TRUE ;
if ( V_26 == V_113 ) {
V_4 = F_53 ( V_26 , V_373 ) ;
}
else if ( strcmp ( V_26 -> V_21 , L_460 ) == 0 ) {
if ( strcmp ( V_383 , L_461 ) == 0 )
V_4 = F_53 ( V_26 , L_462 ) ;
else if ( strcmp ( V_383 , L_463 ) == 0 )
V_4 = F_53 ( V_26 , L_464 ) ;
else if ( strcmp ( V_383 , L_465 ) == 0 ) {
V_333 ++ ;
if ( V_333 == 1 ) {
V_4 = F_53 ( V_26 , L_466 ) ;
} else if ( V_333 == 2 ) {
V_4 = F_53 ( V_26 , L_467 ) ;
}
} else if ( strcmp ( V_383 , L_468 ) == 0 ) {
V_334 ++ ;
if ( V_334 == 1 ) {
V_4 = F_53 ( V_26 , L_469 ) ;
} else if ( V_334 == 2 ) {
V_4 = F_53 ( V_26 , L_470 ) ;
}
}
} else if ( strcmp ( V_26 -> V_21 , L_471 ) == 0 ) {
if ( strcmp ( V_383 , L_472 ) == 0 )
V_4 = F_53 ( V_26 , L_473 ) ;
else if ( strcmp ( V_383 , L_474 ) == 0 )
V_4 = F_53 ( V_26 , L_475 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_476 ) == 0 ) {
if ( strcmp ( V_383 , L_477 ) == 0 )
V_4 = F_53 ( V_26 , L_478 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_438 ) == 0 ) {
if ( strcmp ( V_383 , L_479 ) == 0 )
V_4 = F_53 ( V_26 , L_478 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_480 ) == 0 ) {
if ( strcmp ( V_383 , L_481 ) == 0 )
V_4 = F_53 ( V_26 , L_482 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_483 ) == 0 ) {
if ( strcmp ( V_383 , L_484 ) == 0 )
V_4 = F_53 ( V_26 , L_482 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_485 ) == 0 ) {
if ( strcmp ( V_383 , L_486 ) == 0 )
V_4 = F_53 ( V_26 , L_487 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_488 ) == 0 ) {
if ( strcmp ( V_383 , L_489 ) == 0 )
V_4 = F_53 ( V_26 , L_490 ) ;
else if ( strcmp ( V_383 , L_491 ) == 0 )
V_4 = F_53 ( V_26 , L_492 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_493 ) == 0 ) {
if ( strcmp ( V_383 , L_494 ) == 0 )
V_4 = F_53 ( V_26 , L_478 ) ;
else if ( strcmp ( V_383 , L_495 ) == 0 )
V_4 = F_53 ( V_26 , L_496 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_443 ) == 0 ) {
if ( strcmp ( V_383 , L_497 ) == 0 )
V_4 = F_53 ( V_26 , L_498 ) ;
else if ( strcmp ( V_383 , L_499 ) == 0 )
V_4 = F_53 ( V_26 , L_500 ) ;
else if ( strcmp ( V_383 , L_501 ) == 0 )
V_4 = F_53 ( V_26 , L_502 ) ;
else if ( strcmp ( V_383 , L_503 ) == 0 )
V_4 = F_53 ( V_26 , L_504 ) ;
else if ( strcmp ( V_383 , L_505 ) == 0 )
V_4 = F_53 ( V_26 , L_506 ) ;
else if ( strcmp ( V_383 , L_507 ) == 0 )
V_4 = F_53 ( V_26 , L_508 ) ;
else if ( strcmp ( V_383 , L_509 ) == 0 )
V_4 = F_53 ( V_26 , L_510 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_511 ) == 0 ) {
if ( strcmp ( V_383 , L_512 ) == 0 )
V_4 = F_53 ( V_26 , L_513 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_514 ) == 0 ) {
if ( strcmp ( V_383 , L_515 ) == 0 )
V_4 = F_53 ( V_26 , L_496 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_516 ) == 0 ) {
if ( strcmp ( V_383 , L_517 ) == 0 )
V_4 = F_53 ( V_26 , L_518 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_519 ) == 0 ) {
if ( strcmp ( V_383 , L_520 ) == 0 )
V_4 = F_53 ( V_26 , L_521 ) ;
else if ( strcmp ( V_383 , L_522 ) == 0 )
V_4 = F_53 ( V_26 , L_523 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_524 ) == 0 ) {
if ( strcmp ( V_383 , L_525 ) == 0 )
V_4 = F_53 ( V_26 , L_526 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_527 ) == 0 ) {
if ( strcmp ( V_383 , L_528 ) == 0 )
V_4 = F_53 ( V_26 , L_529 ) ;
else if ( strcmp ( V_383 , L_530 ) == 0 )
V_4 = F_53 ( V_26 , L_531 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_532 ) == 0 ) {
if ( strcmp ( V_383 , L_533 ) == 0 )
V_4 = F_53 ( V_26 , L_534 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_535 ) == 0 ) {
if ( strcmp ( V_383 , L_536 ) == 0 )
V_4 = F_53 ( V_26 , L_513 ) ;
else if ( strcmp ( V_383 , L_537 ) == 0 )
V_4 = F_53 ( V_26 , L_538 ) ;
else if ( strcmp ( V_383 , L_539 ) == 0 )
V_4 = F_53 ( V_26 , L_540 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_541 ) == 0 ) {
if ( strcmp ( V_383 , L_542 ) == 0 )
V_4 = F_53 ( V_26 , L_513 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_543 ) == 0 ) {
if ( strcmp ( V_383 , L_544 ) == 0 )
V_4 = F_53 ( V_26 , L_545 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_546 ) == 0 ) {
if ( strcmp ( V_383 , L_547 ) == 0 )
V_4 = F_53 ( V_26 , L_548 ) ;
else if ( strcmp ( V_383 , L_549 ) == 0 )
V_4 = F_53 ( V_26 , L_550 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_551 ) == 0 ) {
T_5 * V_44 = F_22 ( L_445 ) ;
if ( V_44 ) {
if ( strcmp ( V_383 , L_552 ) == 0 ) {
V_4 = F_53 ( V_44 , L_552 ) ;
V_63 = V_44 ;
} else if ( strcmp ( V_383 , L_553 ) == 0 ) {
V_4 = F_53 ( V_44 , L_553 ) ;
V_63 = V_44 ;
}
}
} else if ( strcmp ( V_26 -> V_21 , L_554 ) == 0 ) {
if ( strcmp ( V_383 , L_555 ) == 0 )
V_4 = F_53 ( V_26 , L_556 ) ;
else if ( strcmp ( V_383 , L_482 ) == 0 )
V_4 = F_53 ( V_26 , L_557 ) ;
else if ( strcmp ( V_383 , L_558 ) == 0 )
V_4 = F_53 ( V_26 , L_559 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_560 ) == 0 ) {
if ( strcmp ( V_383 , L_561 ) == 0 )
V_4 = F_53 ( V_26 , L_562 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_563 ) == 0 ) {
if ( strcmp ( V_383 , L_564 ) == 0 ) {
V_4 = F_53 ( V_26 , L_565 ) ;
if ( strcmp ( V_49 , L_565 ) == 0 || strcmp ( V_49 , L_566 ) == 0 )
V_49 = L_428 ;
else if ( strcmp ( V_49 , L_567 ) == 0 || strcmp ( V_49 , L_568 ) == 0 )
V_49 = L_569 ;
else if ( strcmp ( V_49 , L_570 ) == 0 || strcmp ( V_49 , L_571 ) == 0 )
V_49 = L_428 ;
} else if ( strcmp ( V_383 , L_572 ) == 0 ) {
V_4 = F_53 ( V_26 , L_573 ) ;
if ( strcmp ( V_49 , L_574 ) == 0 || strcmp ( V_49 , L_575 ) == 0 )
V_49 = L_576 ;
else if ( strcmp ( V_49 , L_577 ) == 0 || strcmp ( V_49 , L_578 ) == 0 )
V_49 = L_577 ;
else if ( strcmp ( V_49 , L_570 ) == 0 || strcmp ( V_49 , L_571 ) == 0 )
V_49 = L_576 ;
} else if ( strcmp ( V_383 , L_579 ) == 0 ) {
V_4 = F_53 ( V_26 , L_580 ) ;
if ( strcmp ( V_49 , L_581 ) == 0 || strcmp ( V_49 , L_582 ) == 0 )
V_49 = L_581 ;
else if ( strcmp ( V_49 , L_527 ) == 0 || strcmp ( V_49 , L_583 ) == 0 )
V_49 = L_527 ;
else if ( strcmp ( V_49 , L_584 ) == 0 || strcmp ( V_49 , L_585 ) == 0 )
V_49 = L_586 ;
else if ( strcmp ( V_49 , L_587 ) == 0 || strcmp ( V_49 , L_588 ) == 0 )
V_49 = L_587 ;
else if ( strcmp ( V_49 , L_570 ) == 0 || strcmp ( V_49 , L_571 ) == 0 )
V_49 = L_576 ;
}
} else if ( strcmp ( V_26 -> V_21 , L_567 ) == 0 ) {
if ( strcmp ( V_383 , L_589 ) == 0 ) {
T_5 * V_44 = F_22 ( L_590 ) ;
if ( V_44 ) {
V_4 = F_53 ( V_44 , L_589 ) ;
V_63 = V_44 ;
}
}
} else if ( strcmp ( V_26 -> V_21 , L_315 ) == 0 ) {
if ( strcmp ( V_383 , L_251 ) == 0 ||
strcmp ( V_383 , L_254 ) == 0 )
V_4 = F_53 ( V_48 , V_383 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_317 ) == 0 ) {
if ( strcmp ( V_383 , L_306 ) == 0 )
V_4 = F_53 ( V_41 , V_383 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_319 ) == 0 ) {
if ( ( strcmp ( V_383 , L_591 ) == 0 ) ||
( strcmp ( V_383 , L_592 ) == 0 ) ||
( strcmp ( V_383 , L_593 ) == 0 ) ||
( strcmp ( V_383 , L_594 ) == 0 ) )
V_4 = F_53 ( V_184 , V_373 ) ;
} else if ( strcmp ( V_26 -> V_21 , L_233 ) == 0 ) {
if ( strcmp ( V_373 , L_433 ) == 0 ) {
V_4 = F_53 ( V_246 , V_373 ) ;
} else if ( strcmp ( V_373 , L_434 ) == 0 ) {
V_4 = F_53 ( V_246 , L_595 ) ;
} else if ( strcmp ( V_373 , L_435 ) == 0 ) {
V_4 = F_53 ( V_246 , L_596 ) ;
}
}
}
if ( V_4 == NULL )
return V_91 ;
type = V_4 -> type ;
if ( F_54 ( type ) ) {
return V_353 ;
} else {
F_7 ( type ) ;
}
switch ( type ) {
case V_11 :
V_107 = ( T_4 ) strtoul ( V_49 , & V_35 , V_4 -> V_68 . V_65 ) ;
if ( V_35 == V_49 || * V_35 != '\0' )
return V_136 ;
if ( * V_4 -> V_5 . V_67 != V_107 ) {
V_63 -> V_37 = TRUE ;
* V_4 -> V_5 . V_67 = V_107 ;
}
break;
case V_9 :
if ( F_165 ( V_49 , L_427 ) == 0 )
V_381 = TRUE ;
else
V_381 = FALSE ;
if ( * V_4 -> V_5 . V_70 != V_381 ) {
V_63 -> V_37 = TRUE ;
* V_4 -> V_5 . V_70 = V_381 ;
}
break;
case V_10 :
V_382 = F_164 ( V_49 , V_4 -> V_68 . V_75 . V_71 ,
* V_4 -> V_5 . V_73 ) ;
if ( * V_4 -> V_5 . V_73 != V_382 ) {
V_63 -> V_37 = TRUE ;
* V_4 -> V_5 . V_73 = V_382 ;
}
break;
case V_15 :
case V_16 :
case V_17 :
F_67 ( V_4 , V_49 , & V_63 -> V_37 ) ;
break;
case V_18 :
{
if ( ! F_77 ( V_4 , V_49 , V_80 ,
& V_63 -> V_37 ) )
return V_136 ;
break;
}
case V_14 :
{
V_380 = strtoul ( V_49 , NULL , 16 ) ;
if ( ( V_4 -> V_5 . V_86 -> V_300 != F_207 ( V_380 ) ) ||
( V_4 -> V_5 . V_86 -> V_301 != F_208 ( V_380 ) ) ||
( V_4 -> V_5 . V_86 -> V_302 != F_209 ( V_380 ) ) ) {
V_63 -> V_37 = TRUE ;
V_4 -> V_5 . V_86 -> V_300 = F_207 ( V_380 ) ;
V_4 -> V_5 . V_86 -> V_301 = F_208 ( V_380 ) ;
V_4 -> V_5 . V_86 -> V_302 = F_209 ( V_380 ) ;
}
break;
}
case V_20 :
return V_4 -> V_24 . V_174 ( V_4 , V_49 , & V_63 -> V_37 ) ;
case V_12 :
case V_13 :
{
break;
}
}
}
return V_90 ;
}
const char *
F_210 ( T_1 * V_4 )
{
const char * V_393 = L_597 ;
int type ;
if ( ! V_4 ) {
return V_393 ;
}
type = V_4 -> type ;
if ( F_54 ( type ) ) {
V_393 = L_598 ;
} else {
F_7 ( type ) ;
}
switch ( type ) {
case V_11 :
switch ( V_4 -> V_68 . V_65 ) {
case 10 :
V_393 = L_599 ;
break;
case 8 :
V_393 = L_600 ;
break;
case 16 :
V_393 = L_601 ;
break;
}
break;
case V_9 :
V_393 = L_602 ;
break;
case V_10 :
V_393 = L_603 ;
break;
case V_15 :
V_393 = L_604 ;
break;
case V_16 :
V_393 = L_605 ;
break;
case V_17 :
V_393 = L_606 ;
break;
case V_18 :
V_393 = L_607 ;
break;
case V_14 :
V_393 = L_608 ;
break;
case V_20 :
if ( V_4 -> V_24 . V_175 )
return V_4 -> V_24 . V_175 () ;
V_393 = L_609 ;
break;
case V_12 :
V_393 = L_610 ;
break;
case V_13 :
V_393 = L_611 ;
break;
}
return V_393 ;
}
char *
F_211 ( T_1 * V_4 )
{
const char * V_394 = L_612 ;
int type ;
if ( ! V_4 ) {
return F_104 ( L_613 , V_394 ) ;
}
type = V_4 -> type ;
if ( F_54 ( type ) ) {
V_394 = L_614 ;
} else {
F_7 ( type ) ;
}
switch ( type ) {
case V_11 :
switch ( V_4 -> V_68 . V_65 ) {
case 10 :
V_394 = L_615 ;
break;
case 8 :
V_394 = L_616 ;
break;
case 16 :
V_394 = L_617 ;
break;
}
break;
case V_9 :
V_394 = L_618 ;
break;
case V_10 :
{
const T_18 * V_395 = V_4 -> V_68 . V_75 . V_71 ;
T_28 * V_396 = F_112 ( L_619 ) ;
while ( V_395 -> V_21 != NULL ) {
F_114 ( V_396 , V_395 -> V_31 ) ;
V_395 ++ ;
if ( V_395 -> V_21 != NULL )
F_114 ( V_396 , L_620 ) ;
}
F_114 ( V_396 , L_621 ) ;
return F_115 ( V_396 , FALSE ) ;
break;
}
case V_15 :
V_394 = L_622 ;
break;
case V_16 :
V_394 = L_623 ;
break;
case V_17 :
V_394 = L_624 ;
break;
case V_18 :
{
V_394 = L_625 ;
break;
}
case V_14 :
{
V_394 = L_626 ;
break;
}
case V_20 :
if ( V_4 -> V_24 . V_176 )
return V_4 -> V_24 . V_176 () ;
V_394 = L_627 ;
break;
case V_12 :
V_394 = L_628 ;
break;
case V_13 :
V_394 = L_629 ;
break;
default:
break;
}
return F_37 ( V_394 ) ;
}
static T_6
F_212 ( T_1 * V_4 )
{
int type ;
if ( ! V_4 ) return FALSE ;
type = V_4 -> type ;
if ( F_54 ( type ) ) {
return FALSE ;
} else {
F_7 ( type ) ;
}
switch ( type ) {
case V_11 :
if ( V_4 -> V_6 . V_67 == * V_4 -> V_5 . V_67 )
return TRUE ;
break;
case V_9 :
if ( V_4 -> V_6 . V_23 == * V_4 -> V_5 . V_70 )
return TRUE ;
break;
case V_10 :
if ( V_4 -> V_6 . V_74 == * V_4 -> V_5 . V_73 )
return TRUE ;
break;
case V_15 :
case V_16 :
case V_17 :
if ( ! ( F_117 ( V_4 -> V_6 . string , * V_4 -> V_5 . string ) ) )
return TRUE ;
break;
case V_18 :
{
if ( ( F_79 ( V_4 -> V_6 . V_19 , * V_4 -> V_5 . V_19 ) ) )
return TRUE ;
break;
}
case V_14 :
{
if ( ( V_4 -> V_6 . V_85 . V_300 == V_4 -> V_5 . V_86 -> V_300 ) &&
( V_4 -> V_6 . V_85 . V_301 == V_4 -> V_5 . V_86 -> V_301 ) &&
( V_4 -> V_6 . V_85 . V_302 == V_4 -> V_5 . V_86 -> V_302 ) )
return TRUE ;
break;
}
case V_20 :
return V_4 -> V_24 . V_177 ( V_4 ) ;
case V_12 :
case V_13 :
return FALSE ;
break;
}
return FALSE ;
}
char *
F_213 ( T_1 * V_4 , T_36 V_397 ) {
const char * V_398 = L_597 ;
void * V_399 ;
T_22 * V_400 ;
T_13 * V_401 , * V_402 ;
int type ;
if ( ! V_4 ) {
return F_37 ( V_398 ) ;
}
switch ( V_397 ) {
case V_403 :
V_399 = & V_4 -> V_6 ;
V_400 = & V_4 -> V_6 . V_85 ;
break;
case V_404 :
V_399 = & V_4 -> V_22 ;
V_400 = & V_4 -> V_22 . V_85 ;
break;
case V_405 :
V_399 = V_4 -> V_5 . V_67 ;
V_400 = V_4 -> V_5 . V_86 ;
break;
default:
return F_37 ( V_398 ) ;
}
type = V_4 -> type ;
if ( F_54 ( type ) ) {
V_398 = L_630 ;
} else {
F_7 ( type ) ;
}
switch ( type ) {
case V_11 :
{
T_4 V_406 = * ( T_4 * ) V_399 ;
switch ( V_4 -> V_68 . V_65 ) {
case 10 :
return F_104 ( L_17 , V_406 ) ;
case 8 :
return F_104 ( L_631 , V_406 ) ;
case 16 :
return F_104 ( L_632 , V_406 ) ;
}
break;
}
case V_9 :
return F_37 ( ( * ( T_6 * ) V_399 ) ? L_428 : L_569 ) ;
case V_10 :
{
T_14 V_407 = * ( T_14 * ) V_399 ;
const T_18 * V_395 = V_4 -> V_68 . V_75 . V_71 ;
while ( V_395 -> V_21 != NULL ) {
if ( V_395 -> V_49 == V_407 )
return F_37 ( V_395 -> V_31 ) ;
V_395 ++ ;
}
break;
}
case V_15 :
case V_16 :
case V_17 :
return F_37 ( * ( const char * * ) V_399 ) ;
case V_18 :
V_401 = F_214 ( NULL , * ( T_19 * * ) V_399 ) ;
V_402 = F_37 ( V_401 ) ;
F_19 ( NULL , V_401 ) ;
return V_402 ;
case V_14 :
return F_104 ( L_633 ,
( V_400 -> V_300 * 255 / 65535 ) ,
( V_400 -> V_301 * 255 / 65535 ) ,
( V_400 -> V_302 * 255 / 65535 ) ) ;
case V_20 :
if ( V_4 -> V_24 . V_178 )
return V_4 -> V_24 . V_178 ( V_4 , V_397 == V_403 ? TRUE : FALSE ) ;
V_398 = L_634 ;
break;
case V_12 :
V_398 = L_628 ;
break;
case V_13 :
{
T_21 * V_83 = V_4 -> V_5 . V_83 ;
if ( V_83 && V_83 -> V_408 )
return F_104 ( L_635 , V_83 -> V_408 ) ;
else
V_398 = L_636 ;
break;
}
default:
break;
}
return F_37 ( V_398 ) ;
}
static void
F_215 ( T_2 V_7 , T_2 T_3 )
{
T_1 * V_4 = ( T_1 * ) V_7 ;
T_37 * V_60 = ( T_37 * ) T_3 ;
T_13 * * V_409 ;
int V_150 ;
int type ;
type = V_4 -> type ;
if ( F_54 ( type ) ) {
return;
} else {
F_7 ( type ) ;
}
switch ( type ) {
case V_12 :
case V_13 :
return;
default:
break;
}
if ( V_4 -> type != V_20 || V_4 -> V_24 . V_175 () != NULL ) {
const char * V_410 = ( V_60 -> V_26 -> V_21 != NULL ) ? V_60 -> V_26 -> V_21 : V_60 -> V_26 -> V_29 -> V_21 ;
char * V_394 , * V_398 ;
const char * V_411 = F_212 ( V_4 ) ? L_637 : L_5 ;
if ( V_4 -> type == V_20 ) fprintf ( V_60 -> V_327 , L_638 , V_4 -> V_24 . V_175 () ) ;
fprintf ( V_60 -> V_327 , L_639 ) ;
if ( V_4 -> V_31 &&
( F_216 ( V_4 -> V_31 , L_5 , 2 ) != 0 ) ) {
if ( V_4 -> type != V_20 ) {
V_409 = F_168 ( V_4 -> V_31 , L_639 , 0 ) ;
for ( V_150 = 0 ; V_409 [ V_150 ] != NULL ; ++ V_150 ) {
fprintf ( V_60 -> V_327 , L_640 , V_409 [ V_150 ] ) ;
}
F_169 ( V_409 ) ;
}
} else {
fprintf ( V_60 -> V_327 , L_641 ) ;
}
V_394 = F_211 ( V_4 ) ;
V_409 = F_168 ( V_394 , L_639 , 0 ) ;
for ( V_150 = 0 ; V_409 [ V_150 ] != NULL ; ++ V_150 ) {
fprintf ( V_60 -> V_327 , L_640 , V_409 [ V_150 ] ) ;
}
F_169 ( V_409 ) ;
F_5 ( V_394 ) ;
V_398 = F_213 ( V_4 , V_405 ) ;
fprintf ( V_60 -> V_327 , L_642 , V_411 , V_410 , V_4 -> V_21 ) ;
V_409 = F_168 ( V_398 , L_639 , 0 ) ;
for ( V_150 = 0 ; V_409 [ V_150 ] != NULL ; ++ V_150 ) {
fprintf ( V_60 -> V_327 , L_643 , V_150 == 0 ? L_5 : V_411 , V_409 [ V_150 ] ) ;
}
if ( V_150 == 0 ) fprintf ( V_60 -> V_327 , L_639 ) ;
F_169 ( V_409 ) ;
F_5 ( V_398 ) ;
}
}
static T_4
F_217 ( T_5 * V_26 , T_2 T_3 )
{
T_38 * V_412 = ( T_38 * ) T_3 ;
T_37 V_60 ;
if ( ( V_26 == V_164 ) && ( V_412 -> V_413 != TRUE ) )
return 0 ;
if ( ( ( V_26 -> V_29 == NULL ) || ( V_26 -> V_29 == V_164 ) ) &&
( ( F_45 ( V_26 ) ) ||
( V_26 -> V_27 > 0 ) ||
( V_26 -> V_21 == NULL ) ) ) {
if ( ( V_26 -> V_21 == NULL ) && ( V_26 -> V_29 != NULL ) ) {
fprintf ( V_412 -> V_327 , L_644 , V_26 -> V_29 -> V_30 , V_26 -> V_30 ) ;
} else {
fprintf ( V_412 -> V_327 , L_645 , V_26 -> V_30 ) ;
}
}
V_60 . V_26 = V_26 ;
V_60 . V_327 = V_412 -> V_327 ;
F_9 ( V_60 . V_26 -> V_1 , F_215 , & V_60 ) ;
if ( F_45 ( V_26 ) )
return F_11 ( V_26 , F_217 , T_3 ) ;
return 0 ;
}
int
F_218 ( char * * V_324 )
{
char * V_326 ;
T_32 * V_327 ;
T_38 V_414 ;
F_171 () ;
if ( V_324 != NULL ) {
V_326 = F_187 ( V_329 , TRUE ) ;
if ( ( V_327 = F_185 ( V_326 , L_646 ) ) == NULL ) {
* V_324 = V_326 ;
return V_330 ;
}
F_5 ( V_326 ) ;
} else {
V_327 = stdout ;
}
fputs ( L_647 V_415 L_648
L_649
L_650
L_651
L_652
L_653 , V_327 ) ;
V_414 . V_327 = V_327 ;
V_414 . V_413 = TRUE ;
F_217 ( V_164 , & V_414 ) ;
{
struct V_416 * V_417 = * (struct V_416 * * ) V_1 . V_418 ;
if ( V_417 != NULL )
fprintf ( V_327 , L_654 ) ;
while ( V_417 != NULL ) {
if ( V_417 -> V_419 == FALSE ) {
fprintf ( V_327 , L_655 , V_388 , V_417 -> V_420 ) ;
fprintf ( V_327 , L_655 , V_389 ,
V_417 -> V_379 == TRUE ? L_428 : L_569 ) ;
fprintf ( V_327 , L_655 , V_390 , V_417 -> V_421 ) ;
}
V_417 = V_417 -> V_115 ;
}
}
V_414 . V_413 = FALSE ;
F_11 ( NULL , F_217 , & V_414 ) ;
fclose ( V_327 ) ;
return 0 ;
}
static void
F_126 ( T_17 * V_88 )
{
T_27 * V_111 ;
T_17 * V_422 = V_88 ;
while ( V_88 != NULL ) {
V_111 = ( T_27 * ) V_88 -> V_7 ;
F_5 ( V_111 -> V_30 ) ;
F_5 ( V_111 -> V_121 ) ;
F_5 ( V_111 ) ;
V_88 = F_93 ( V_88 ) ;
}
F_10 ( V_422 ) ;
}
