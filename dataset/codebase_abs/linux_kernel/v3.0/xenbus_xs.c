static int F_1 ( const char * V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; strcmp ( V_1 , V_3 [ V_2 ] . V_4 ) != 0 ; V_2 ++ ) {
if ( V_2 == F_2 ( V_3 ) - 1 ) {
F_3 ( V_5
L_1 ,
V_1 ) ;
return V_6 ;
}
}
return V_3 [ V_2 ] . V_7 ;
}
static void * F_4 ( enum V_8 * type , unsigned int * V_9 )
{
struct V_10 * V_11 ;
char * V_12 ;
F_5 ( & V_13 . V_14 ) ;
while ( F_6 ( & V_13 . V_15 ) ) {
F_7 ( & V_13 . V_14 ) ;
F_8 ( V_13 . V_16 ,
! F_6 ( & V_13 . V_15 ) ) ;
F_5 ( & V_13 . V_14 ) ;
}
V_11 = F_9 ( V_13 . V_15 . V_17 ,
struct V_10 , V_18 ) ;
F_10 ( & V_11 -> V_18 ) ;
F_7 ( & V_13 . V_14 ) ;
* type = V_11 -> V_19 . type ;
if ( V_9 )
* V_9 = V_11 -> V_19 . V_9 ;
V_12 = V_11 -> V_20 . V_21 . V_12 ;
F_11 ( V_11 ) ;
return V_12 ;
}
static void F_12 ( void )
{
F_13 ( & V_13 . V_22 ) ;
F_14 ( & V_13 . V_23 ) ;
F_15 ( & V_13 . V_22 ) ;
}
static void F_16 ( void )
{
if ( F_17 ( & V_13 . V_23 ) )
F_18 ( & V_13 . V_24 ) ;
}
static void F_19 ( void )
{
F_13 ( & V_13 . V_22 ) ;
F_8 ( V_13 . V_24 ,
F_20 ( & V_13 . V_23 ) == 0 ) ;
}
static void F_21 ( void )
{
F_15 ( & V_13 . V_22 ) ;
}
void * F_22 ( struct V_25 * V_11 )
{
void * V_26 ;
struct V_25 V_27 = * V_11 ;
int V_28 ;
if ( V_27 . type == V_29 )
F_12 () ;
F_13 ( & V_13 . V_30 ) ;
V_28 = F_23 ( V_11 , sizeof( * V_11 ) + V_11 -> V_9 ) ;
if ( V_28 ) {
V_11 -> type = V_31 ;
V_26 = F_24 ( V_28 ) ;
} else
V_26 = F_4 ( & V_11 -> type , & V_11 -> V_9 ) ;
F_15 ( & V_13 . V_30 ) ;
if ( ( V_11 -> type == V_32 ) ||
( ( V_27 . type == V_29 ) &&
( V_11 -> type == V_31 ) ) )
F_16 () ;
return V_26 ;
}
static void * F_25 ( struct V_33 V_34 ,
enum V_8 type ,
const struct V_35 * V_36 ,
unsigned int V_37 ,
unsigned int * V_9 )
{
struct V_25 V_11 ;
void * V_26 = NULL ;
unsigned int V_2 ;
int V_28 ;
V_11 . V_38 = V_34 . V_39 ;
V_11 . V_40 = 0 ;
V_11 . type = type ;
V_11 . V_9 = 0 ;
for ( V_2 = 0 ; V_2 < V_37 ; V_2 ++ )
V_11 . V_9 += V_36 [ V_2 ] . V_41 ;
F_13 ( & V_13 . V_30 ) ;
V_28 = F_23 ( & V_11 , sizeof( V_11 ) ) ;
if ( V_28 ) {
F_15 ( & V_13 . V_30 ) ;
return F_24 ( V_28 ) ;
}
for ( V_2 = 0 ; V_2 < V_37 ; V_2 ++ ) {
V_28 = F_23 ( V_36 [ V_2 ] . V_42 , V_36 [ V_2 ] . V_41 ) ;
if ( V_28 ) {
F_15 ( & V_13 . V_30 ) ;
return F_24 ( V_28 ) ;
}
}
V_26 = F_4 ( & V_11 . type , V_9 ) ;
F_15 ( & V_13 . V_30 ) ;
if ( F_26 ( V_26 ) )
return V_26 ;
if ( V_11 . type == V_31 ) {
V_28 = F_1 ( V_26 ) ;
F_11 ( V_26 ) ;
return F_24 ( - V_28 ) ;
}
if ( V_11 . type != type ) {
if ( F_27 () )
F_3 ( V_5
L_2 ,
V_11 . type , type ) ;
F_11 ( V_26 ) ;
return F_24 ( - V_6 ) ;
}
return V_26 ;
}
static void * F_28 ( struct V_33 V_34 ,
enum V_8 type ,
const char * string ,
unsigned int * V_9 )
{
struct V_35 V_36 ;
V_36 . V_42 = ( void * ) string ;
V_36 . V_41 = strlen ( string ) + 1 ;
return F_25 ( V_34 , type , & V_36 , 1 , V_9 ) ;
}
static int F_29 ( char * V_21 )
{
if ( F_26 ( V_21 ) )
return F_30 ( V_21 ) ;
F_11 ( V_21 ) ;
return 0 ;
}
static unsigned int F_31 ( const char * V_43 , unsigned int V_9 )
{
unsigned int V_44 ;
const char * V_45 ;
for ( V_45 = V_43 , V_44 = 0 ; V_45 < V_43 + V_9 ; V_45 += strlen ( V_45 ) + 1 )
V_44 ++ ;
return V_44 ;
}
static char * F_32 ( const char * V_46 , const char * V_47 )
{
char * V_48 ;
if ( strlen ( V_47 ) == 0 )
V_48 = F_33 ( V_49 | V_50 , L_3 , V_46 ) ;
else
V_48 = F_33 ( V_49 | V_50 , L_4 , V_46 , V_47 ) ;
return ( ! V_48 ) ? F_24 ( - V_51 ) : V_48 ;
}
static char * * F_34 ( char * V_43 , unsigned int V_9 , unsigned int * V_44 )
{
char * V_45 , * * V_26 ;
* V_44 = F_31 ( V_43 , V_9 ) ;
V_26 = F_35 ( * V_44 * sizeof( char * ) + V_9 , V_49 | V_50 ) ;
if ( ! V_26 ) {
F_11 ( V_43 ) ;
return F_24 ( - V_51 ) ;
}
memcpy ( & V_26 [ * V_44 ] , V_43 , V_9 ) ;
F_11 ( V_43 ) ;
V_43 = ( char * ) & V_26 [ * V_44 ] ;
for ( V_45 = V_43 , * V_44 = 0 ; V_45 < V_43 + V_9 ; V_45 += strlen ( V_45 ) + 1 )
V_26 [ ( * V_44 ) ++ ] = V_45 ;
return V_26 ;
}
char * * F_36 ( struct V_33 V_34 ,
const char * V_46 , const char * V_52 , unsigned int * V_44 )
{
char * V_43 , * V_53 ;
unsigned int V_9 ;
V_53 = F_32 ( V_46 , V_52 ) ;
if ( F_26 ( V_53 ) )
return ( char * * ) V_53 ;
V_43 = F_28 ( V_34 , V_54 , V_53 , & V_9 ) ;
F_11 ( V_53 ) ;
if ( F_26 ( V_43 ) )
return ( char * * ) V_43 ;
return F_34 ( V_43 , V_9 , V_44 ) ;
}
int F_37 ( struct V_33 V_34 ,
const char * V_46 , const char * V_52 )
{
char * * V_55 ;
int V_56 ;
V_55 = F_36 ( V_34 , V_46 , V_52 , & V_56 ) ;
if ( F_26 ( V_55 ) )
return 0 ;
F_11 ( V_55 ) ;
return 1 ;
}
void * F_38 ( struct V_33 V_34 ,
const char * V_46 , const char * V_52 , unsigned int * V_9 )
{
char * V_53 ;
void * V_26 ;
V_53 = F_32 ( V_46 , V_52 ) ;
if ( F_26 ( V_53 ) )
return ( void * ) V_53 ;
V_26 = F_28 ( V_34 , V_57 , V_53 , V_9 ) ;
F_11 ( V_53 ) ;
return V_26 ;
}
int F_39 ( struct V_33 V_34 ,
const char * V_46 , const char * V_52 , const char * string )
{
const char * V_53 ;
struct V_35 V_36 [ 2 ] ;
int V_26 ;
V_53 = F_32 ( V_46 , V_52 ) ;
if ( F_26 ( V_53 ) )
return F_30 ( V_53 ) ;
V_36 [ 0 ] . V_42 = ( void * ) V_53 ;
V_36 [ 0 ] . V_41 = strlen ( V_53 ) + 1 ;
V_36 [ 1 ] . V_42 = ( void * ) string ;
V_36 [ 1 ] . V_41 = strlen ( string ) ;
V_26 = F_29 ( F_25 ( V_34 , V_58 , V_36 , F_2 ( V_36 ) , NULL ) ) ;
F_11 ( V_53 ) ;
return V_26 ;
}
int F_40 ( struct V_33 V_34 ,
const char * V_46 , const char * V_52 )
{
char * V_53 ;
int V_26 ;
V_53 = F_32 ( V_46 , V_52 ) ;
if ( F_26 ( V_53 ) )
return F_30 ( V_53 ) ;
V_26 = F_29 ( F_28 ( V_34 , V_59 , V_53 , NULL ) ) ;
F_11 ( V_53 ) ;
return V_26 ;
}
int F_41 ( struct V_33 V_34 , const char * V_46 , const char * V_52 )
{
char * V_53 ;
int V_26 ;
V_53 = F_32 ( V_46 , V_52 ) ;
if ( F_26 ( V_53 ) )
return F_30 ( V_53 ) ;
V_26 = F_29 ( F_28 ( V_34 , V_60 , V_53 , NULL ) ) ;
F_11 ( V_53 ) ;
return V_26 ;
}
int F_42 ( struct V_33 * V_34 )
{
char * V_61 ;
F_12 () ;
V_61 = F_28 ( V_62 , V_29 , L_5 , NULL ) ;
if ( F_26 ( V_61 ) ) {
F_16 () ;
return F_30 ( V_61 ) ;
}
V_34 -> V_39 = F_43 ( V_61 , NULL , 0 ) ;
F_11 ( V_61 ) ;
return 0 ;
}
int F_44 ( struct V_33 V_34 , int abort )
{
char V_63 [ 2 ] ;
int V_28 ;
if ( abort )
strcpy ( V_63 , L_6 ) ;
else
strcpy ( V_63 , L_7 ) ;
V_28 = F_29 ( F_28 ( V_34 , V_32 , V_63 , NULL ) ) ;
F_16 () ;
return V_28 ;
}
int F_45 ( struct V_33 V_34 ,
const char * V_46 , const char * V_52 , const char * V_64 , ... )
{
T_1 V_65 ;
int V_26 ;
char * V_66 ;
V_66 = F_38 ( V_34 , V_46 , V_52 , NULL ) ;
if ( F_26 ( V_66 ) )
return F_30 ( V_66 ) ;
va_start ( V_65 , V_64 ) ;
V_26 = vsscanf ( V_66 , V_64 , V_65 ) ;
va_end ( V_65 ) ;
F_11 ( V_66 ) ;
if ( V_26 == 0 )
return - V_67 ;
return V_26 ;
}
int F_46 ( struct V_33 V_34 ,
const char * V_46 , const char * V_52 , const char * V_64 , ... )
{
T_1 V_65 ;
int V_26 ;
#define F_47 4096
char * V_68 ;
V_68 = F_35 ( F_47 , V_49 | V_50 ) ;
if ( V_68 == NULL )
return - V_51 ;
va_start ( V_65 , V_64 ) ;
V_26 = vsnprintf ( V_68 , F_47 , V_64 , V_65 ) ;
va_end ( V_65 ) ;
F_48 ( V_26 > F_47 - 1 ) ;
V_26 = F_39 ( V_34 , V_46 , V_52 , V_68 ) ;
F_11 ( V_68 ) ;
return V_26 ;
}
int F_49 ( struct V_33 V_34 , const char * V_46 , ... )
{
T_1 V_65 ;
const char * V_47 ;
int V_26 = 0 ;
va_start ( V_65 , V_46 ) ;
while ( V_26 == 0 && ( V_47 = va_arg ( V_65 , char * ) ) != NULL ) {
const char * V_64 = va_arg ( V_65 , char * ) ;
void * V_69 = va_arg ( V_65 , void * ) ;
char * V_45 ;
V_45 = F_38 ( V_34 , V_46 , V_47 , NULL ) ;
if ( F_26 ( V_45 ) ) {
V_26 = F_30 ( V_45 ) ;
break;
}
if ( V_64 ) {
if ( sscanf ( V_45 , V_64 , V_69 ) == 0 )
V_26 = - V_6 ;
F_11 ( V_45 ) ;
} else
* ( char * * ) V_69 = V_45 ;
}
va_end ( V_65 ) ;
return V_26 ;
}
static int F_50 ( const char * V_53 , const char * V_70 )
{
struct V_35 V_71 [ 2 ] ;
V_71 [ 0 ] . V_42 = ( void * ) V_53 ;
V_71 [ 0 ] . V_41 = strlen ( V_53 ) + 1 ;
V_71 [ 1 ] . V_42 = ( void * ) V_70 ;
V_71 [ 1 ] . V_41 = strlen ( V_70 ) + 1 ;
return F_29 ( F_25 ( V_62 , V_72 , V_71 ,
F_2 ( V_71 ) , NULL ) ) ;
}
static int F_51 ( const char * V_53 , const char * V_70 )
{
struct V_35 V_71 [ 2 ] ;
V_71 [ 0 ] . V_42 = ( char * ) V_53 ;
V_71 [ 0 ] . V_41 = strlen ( V_53 ) + 1 ;
V_71 [ 1 ] . V_42 = ( char * ) V_70 ;
V_71 [ 1 ] . V_41 = strlen ( V_70 ) + 1 ;
return F_29 ( F_25 ( V_62 , V_73 , V_71 ,
F_2 ( V_71 ) , NULL ) ) ;
}
static struct V_74 * F_52 ( const char * V_70 )
{
struct V_74 * V_2 , * V_75 ;
V_75 = ( void * ) F_43 ( V_70 , NULL , 16 ) ;
F_53 (i, &watches, list)
if ( V_2 == V_75 )
return V_2 ;
return NULL ;
}
int F_54 ( struct V_74 * V_76 )
{
char V_70 [ sizeof( V_76 ) * 2 + 1 ] ;
int V_28 ;
sprintf ( V_70 , L_8 , ( long ) V_76 ) ;
F_55 ( & V_13 . V_77 ) ;
F_5 ( & V_78 ) ;
F_48 ( F_52 ( V_70 ) ) ;
F_56 ( & V_76 -> V_18 , & V_79 ) ;
F_7 ( & V_78 ) ;
V_28 = F_50 ( V_76 -> V_52 , V_70 ) ;
if ( ( V_28 != 0 ) && ( V_28 != - V_80 ) ) {
F_5 ( & V_78 ) ;
F_10 ( & V_76 -> V_18 ) ;
F_7 ( & V_78 ) ;
}
F_57 ( & V_13 . V_77 ) ;
return V_28 ;
}
void F_58 ( struct V_74 * V_76 )
{
struct V_10 * V_11 , * V_81 ;
char V_70 [ sizeof( V_76 ) * 2 + 1 ] ;
int V_28 ;
sprintf ( V_70 , L_8 , ( long ) V_76 ) ;
F_55 ( & V_13 . V_77 ) ;
F_5 ( & V_78 ) ;
F_48 ( ! F_52 ( V_70 ) ) ;
F_10 ( & V_76 -> V_18 ) ;
F_7 ( & V_78 ) ;
V_28 = F_51 ( V_76 -> V_52 , V_70 ) ;
if ( V_28 )
F_3 ( V_5
L_9 ,
V_76 -> V_52 , V_28 ) ;
F_57 ( & V_13 . V_77 ) ;
if ( V_82 -> V_83 != V_84 )
F_13 ( & V_85 ) ;
F_5 ( & V_86 ) ;
F_59 (msg, tmp, &watch_events, list) {
if ( V_11 -> V_20 . V_76 . V_87 != V_76 )
continue;
F_10 ( & V_11 -> V_18 ) ;
F_11 ( V_11 -> V_20 . V_76 . V_88 ) ;
F_11 ( V_11 ) ;
}
F_7 ( & V_86 ) ;
if ( V_82 -> V_83 != V_84 )
F_15 ( & V_85 ) ;
}
void F_60 ( void )
{
F_19 () ;
F_61 ( & V_13 . V_77 ) ;
F_13 ( & V_13 . V_30 ) ;
F_13 ( & V_13 . V_89 ) ;
}
void F_62 ( void )
{
struct V_74 * V_76 ;
char V_70 [ sizeof( V_76 ) * 2 + 1 ] ;
F_63 () ;
F_15 ( & V_13 . V_89 ) ;
F_15 ( & V_13 . V_30 ) ;
F_21 () ;
F_53 (watch, &watches, list) {
sprintf ( V_70 , L_8 , ( long ) V_76 ) ;
F_50 ( V_76 -> V_52 , V_70 ) ;
}
F_64 ( & V_13 . V_77 ) ;
}
void F_65 ( void )
{
F_15 ( & V_13 . V_89 ) ;
F_15 ( & V_13 . V_30 ) ;
F_64 ( & V_13 . V_77 ) ;
F_15 ( & V_13 . V_22 ) ;
}
static int F_66 ( void * V_90 )
{
struct V_91 * V_92 ;
struct V_10 * V_11 ;
for (; ; ) {
F_67 ( V_93 ,
! F_6 ( & V_94 ) ) ;
if ( F_68 () )
break;
F_13 ( & V_85 ) ;
F_5 ( & V_86 ) ;
V_92 = V_94 . V_17 ;
if ( V_92 != & V_94 )
F_10 ( V_92 ) ;
F_7 ( & V_86 ) ;
if ( V_92 != & V_94 ) {
V_11 = F_9 ( V_92 , struct V_10 , V_18 ) ;
V_11 -> V_20 . V_76 . V_87 -> V_95 (
V_11 -> V_20 . V_76 . V_87 ,
( const char * * ) V_11 -> V_20 . V_76 . V_88 ,
V_11 -> V_20 . V_76 . V_96 ) ;
F_11 ( V_11 -> V_20 . V_76 . V_88 ) ;
F_11 ( V_11 ) ;
}
F_15 ( & V_85 ) ;
}
return 0 ;
}
static int F_69 ( void )
{
struct V_10 * V_11 ;
char * V_12 ;
int V_28 ;
for (; ; ) {
V_28 = F_70 () ;
if ( V_28 )
return V_28 ;
F_13 ( & V_13 . V_89 ) ;
if ( F_71 () )
break;
F_15 ( & V_13 . V_89 ) ;
}
V_11 = F_35 ( sizeof( * V_11 ) , V_49 | V_50 ) ;
if ( V_11 == NULL ) {
V_28 = - V_51 ;
goto V_97;
}
V_28 = F_72 ( & V_11 -> V_19 , sizeof( V_11 -> V_19 ) ) ;
if ( V_28 ) {
F_11 ( V_11 ) ;
goto V_97;
}
V_12 = F_35 ( V_11 -> V_19 . V_9 + 1 , V_49 | V_50 ) ;
if ( V_12 == NULL ) {
F_11 ( V_11 ) ;
V_28 = - V_51 ;
goto V_97;
}
V_28 = F_72 ( V_12 , V_11 -> V_19 . V_9 ) ;
if ( V_28 ) {
F_11 ( V_12 ) ;
F_11 ( V_11 ) ;
goto V_97;
}
V_12 [ V_11 -> V_19 . V_9 ] = '\0' ;
if ( V_11 -> V_19 . type == V_98 ) {
V_11 -> V_20 . V_76 . V_88 = F_34 ( V_12 , V_11 -> V_19 . V_9 ,
& V_11 -> V_20 . V_76 . V_96 ) ;
if ( F_26 ( V_11 -> V_20 . V_76 . V_88 ) ) {
V_28 = F_30 ( V_11 -> V_20 . V_76 . V_88 ) ;
F_11 ( V_11 ) ;
goto V_97;
}
F_5 ( & V_78 ) ;
V_11 -> V_20 . V_76 . V_87 = F_52 (
V_11 -> V_20 . V_76 . V_88 [ V_99 ] ) ;
if ( V_11 -> V_20 . V_76 . V_87 != NULL ) {
F_5 ( & V_86 ) ;
F_73 ( & V_11 -> V_18 , & V_94 ) ;
F_18 ( & V_93 ) ;
F_7 ( & V_86 ) ;
} else {
F_11 ( V_11 -> V_20 . V_76 . V_88 ) ;
F_11 ( V_11 ) ;
}
F_7 ( & V_78 ) ;
} else {
V_11 -> V_20 . V_21 . V_12 = V_12 ;
F_5 ( & V_13 . V_14 ) ;
F_73 ( & V_11 -> V_18 , & V_13 . V_15 ) ;
F_7 ( & V_13 . V_14 ) ;
F_18 ( & V_13 . V_16 ) ;
}
V_97:
F_15 ( & V_13 . V_89 ) ;
return V_28 ;
}
static int F_74 ( void * V_90 )
{
int V_28 ;
for (; ; ) {
V_28 = F_69 () ;
if ( V_28 )
F_3 ( V_5 L_10
L_11 , V_28 ) ;
if ( F_68 () )
break;
}
return 0 ;
}
int F_75 ( void )
{
int V_28 ;
struct V_100 * V_101 ;
F_76 ( & V_13 . V_15 ) ;
F_77 ( & V_13 . V_14 ) ;
F_78 ( & V_13 . V_16 ) ;
F_79 ( & V_13 . V_30 ) ;
F_79 ( & V_13 . V_89 ) ;
F_79 ( & V_13 . V_22 ) ;
F_80 ( & V_13 . V_77 ) ;
F_81 ( & V_13 . V_23 , 0 ) ;
F_78 ( & V_13 . V_24 ) ;
V_28 = F_63 () ;
if ( V_28 )
return V_28 ;
V_101 = F_82 ( F_66 , NULL , L_12 ) ;
if ( F_26 ( V_101 ) )
return F_30 ( V_101 ) ;
V_84 = V_101 -> V_83 ;
V_101 = F_82 ( F_74 , NULL , L_13 ) ;
if ( F_26 ( V_101 ) )
return F_30 ( V_101 ) ;
return 0 ;
}
