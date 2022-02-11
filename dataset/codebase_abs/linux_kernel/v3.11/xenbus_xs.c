static int F_1 ( const char * V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; strcmp ( V_1 , V_3 [ V_2 ] . V_4 ) != 0 ; V_2 ++ ) {
if ( V_2 == F_2 ( V_3 ) - 1 ) {
F_3 ( L_1 ,
V_1 ) ;
return V_5 ;
}
}
return V_3 [ V_2 ] . V_6 ;
}
static void * F_4 ( enum V_7 * type , unsigned int * V_8 )
{
struct V_9 * V_10 ;
char * V_11 ;
F_5 ( & V_12 . V_13 ) ;
while ( F_6 ( & V_12 . V_14 ) ) {
F_7 ( & V_12 . V_13 ) ;
F_8 ( V_12 . V_15 ,
! F_6 ( & V_12 . V_14 ) ) ;
F_5 ( & V_12 . V_13 ) ;
}
V_10 = F_9 ( V_12 . V_14 . V_16 ,
struct V_9 , V_17 ) ;
F_10 ( & V_10 -> V_17 ) ;
F_7 ( & V_12 . V_13 ) ;
* type = V_10 -> V_18 . type ;
if ( V_8 )
* V_8 = V_10 -> V_18 . V_8 ;
V_11 = V_10 -> V_19 . V_20 . V_11 ;
F_11 ( V_10 ) ;
return V_11 ;
}
static void F_12 ( void )
{
F_13 ( & V_12 . V_21 ) ;
F_14 ( & V_12 . V_22 ) ;
F_15 ( & V_12 . V_21 ) ;
}
static void F_16 ( void )
{
if ( F_17 ( & V_12 . V_22 ) )
F_18 ( & V_12 . V_23 ) ;
}
static void F_19 ( void )
{
F_13 ( & V_12 . V_21 ) ;
F_8 ( V_12 . V_23 ,
F_20 ( & V_12 . V_22 ) == 0 ) ;
}
static void F_21 ( void )
{
F_15 ( & V_12 . V_21 ) ;
}
void * F_22 ( struct V_24 * V_10 )
{
void * V_25 ;
struct V_24 V_26 = * V_10 ;
int V_27 ;
if ( V_26 . type == V_28 )
F_12 () ;
F_13 ( & V_12 . V_29 ) ;
V_27 = F_23 ( V_10 , sizeof( * V_10 ) + V_10 -> V_8 ) ;
if ( V_27 ) {
V_10 -> type = V_30 ;
V_25 = F_24 ( V_27 ) ;
} else
V_25 = F_4 ( & V_10 -> type , & V_10 -> V_8 ) ;
F_15 ( & V_12 . V_29 ) ;
if ( ( V_10 -> type == V_31 ) ||
( ( V_26 . type == V_28 ) &&
( V_10 -> type == V_30 ) ) )
F_16 () ;
return V_25 ;
}
static void * F_25 ( struct V_32 V_33 ,
enum V_7 type ,
const struct V_34 * V_35 ,
unsigned int V_36 ,
unsigned int * V_8 )
{
struct V_24 V_10 ;
void * V_25 = NULL ;
unsigned int V_2 ;
int V_27 ;
V_10 . V_37 = V_33 . V_38 ;
V_10 . V_39 = 0 ;
V_10 . type = type ;
V_10 . V_8 = 0 ;
for ( V_2 = 0 ; V_2 < V_36 ; V_2 ++ )
V_10 . V_8 += V_35 [ V_2 ] . V_40 ;
F_13 ( & V_12 . V_29 ) ;
V_27 = F_23 ( & V_10 , sizeof( V_10 ) ) ;
if ( V_27 ) {
F_15 ( & V_12 . V_29 ) ;
return F_24 ( V_27 ) ;
}
for ( V_2 = 0 ; V_2 < V_36 ; V_2 ++ ) {
V_27 = F_23 ( V_35 [ V_2 ] . V_41 , V_35 [ V_2 ] . V_40 ) ;
if ( V_27 ) {
F_15 ( & V_12 . V_29 ) ;
return F_24 ( V_27 ) ;
}
}
V_25 = F_4 ( & V_10 . type , V_8 ) ;
F_15 ( & V_12 . V_29 ) ;
if ( F_26 ( V_25 ) )
return V_25 ;
if ( V_10 . type == V_30 ) {
V_27 = F_1 ( V_25 ) ;
F_11 ( V_25 ) ;
return F_24 ( - V_27 ) ;
}
if ( V_10 . type != type ) {
F_27 ( L_2 ,
V_10 . type , type ) ;
F_11 ( V_25 ) ;
return F_24 ( - V_5 ) ;
}
return V_25 ;
}
static void * F_28 ( struct V_32 V_33 ,
enum V_7 type ,
const char * string ,
unsigned int * V_8 )
{
struct V_34 V_35 ;
V_35 . V_41 = ( void * ) string ;
V_35 . V_40 = strlen ( string ) + 1 ;
return F_25 ( V_33 , type , & V_35 , 1 , V_8 ) ;
}
static int F_29 ( char * V_20 )
{
if ( F_26 ( V_20 ) )
return F_30 ( V_20 ) ;
F_11 ( V_20 ) ;
return 0 ;
}
static unsigned int F_31 ( const char * V_42 , unsigned int V_8 )
{
unsigned int V_43 ;
const char * V_44 ;
for ( V_44 = V_42 , V_43 = 0 ; V_44 < V_42 + V_8 ; V_44 += strlen ( V_44 ) + 1 )
V_43 ++ ;
return V_43 ;
}
static char * F_32 ( const char * V_45 , const char * V_46 )
{
char * V_47 ;
if ( strlen ( V_46 ) == 0 )
V_47 = F_33 ( V_48 | V_49 , L_3 , V_45 ) ;
else
V_47 = F_33 ( V_48 | V_49 , L_4 , V_45 , V_46 ) ;
return ( ! V_47 ) ? F_24 ( - V_50 ) : V_47 ;
}
static char * * F_34 ( char * V_42 , unsigned int V_8 , unsigned int * V_43 )
{
char * V_44 , * * V_25 ;
* V_43 = F_31 ( V_42 , V_8 ) ;
V_25 = F_35 ( * V_43 * sizeof( char * ) + V_8 , V_48 | V_49 ) ;
if ( ! V_25 ) {
F_11 ( V_42 ) ;
return F_24 ( - V_50 ) ;
}
memcpy ( & V_25 [ * V_43 ] , V_42 , V_8 ) ;
F_11 ( V_42 ) ;
V_42 = ( char * ) & V_25 [ * V_43 ] ;
for ( V_44 = V_42 , * V_43 = 0 ; V_44 < V_42 + V_8 ; V_44 += strlen ( V_44 ) + 1 )
V_25 [ ( * V_43 ) ++ ] = V_44 ;
return V_25 ;
}
char * * F_36 ( struct V_32 V_33 ,
const char * V_45 , const char * V_51 , unsigned int * V_43 )
{
char * V_42 , * V_52 ;
unsigned int V_8 ;
V_52 = F_32 ( V_45 , V_51 ) ;
if ( F_26 ( V_52 ) )
return ( char * * ) V_52 ;
V_42 = F_28 ( V_33 , V_53 , V_52 , & V_8 ) ;
F_11 ( V_52 ) ;
if ( F_26 ( V_42 ) )
return ( char * * ) V_42 ;
return F_34 ( V_42 , V_8 , V_43 ) ;
}
int F_37 ( struct V_32 V_33 ,
const char * V_45 , const char * V_51 )
{
char * * V_54 ;
int V_55 ;
V_54 = F_36 ( V_33 , V_45 , V_51 , & V_55 ) ;
if ( F_26 ( V_54 ) )
return 0 ;
F_11 ( V_54 ) ;
return 1 ;
}
void * F_38 ( struct V_32 V_33 ,
const char * V_45 , const char * V_51 , unsigned int * V_8 )
{
char * V_52 ;
void * V_25 ;
V_52 = F_32 ( V_45 , V_51 ) ;
if ( F_26 ( V_52 ) )
return ( void * ) V_52 ;
V_25 = F_28 ( V_33 , V_56 , V_52 , V_8 ) ;
F_11 ( V_52 ) ;
return V_25 ;
}
int F_39 ( struct V_32 V_33 ,
const char * V_45 , const char * V_51 , const char * string )
{
const char * V_52 ;
struct V_34 V_35 [ 2 ] ;
int V_25 ;
V_52 = F_32 ( V_45 , V_51 ) ;
if ( F_26 ( V_52 ) )
return F_30 ( V_52 ) ;
V_35 [ 0 ] . V_41 = ( void * ) V_52 ;
V_35 [ 0 ] . V_40 = strlen ( V_52 ) + 1 ;
V_35 [ 1 ] . V_41 = ( void * ) string ;
V_35 [ 1 ] . V_40 = strlen ( string ) ;
V_25 = F_29 ( F_25 ( V_33 , V_57 , V_35 , F_2 ( V_35 ) , NULL ) ) ;
F_11 ( V_52 ) ;
return V_25 ;
}
int F_40 ( struct V_32 V_33 ,
const char * V_45 , const char * V_51 )
{
char * V_52 ;
int V_25 ;
V_52 = F_32 ( V_45 , V_51 ) ;
if ( F_26 ( V_52 ) )
return F_30 ( V_52 ) ;
V_25 = F_29 ( F_28 ( V_33 , V_58 , V_52 , NULL ) ) ;
F_11 ( V_52 ) ;
return V_25 ;
}
int F_41 ( struct V_32 V_33 , const char * V_45 , const char * V_51 )
{
char * V_52 ;
int V_25 ;
V_52 = F_32 ( V_45 , V_51 ) ;
if ( F_26 ( V_52 ) )
return F_30 ( V_52 ) ;
V_25 = F_29 ( F_28 ( V_33 , V_59 , V_52 , NULL ) ) ;
F_11 ( V_52 ) ;
return V_25 ;
}
int F_42 ( struct V_32 * V_33 )
{
char * V_60 ;
F_12 () ;
V_60 = F_28 ( V_61 , V_28 , L_5 , NULL ) ;
if ( F_26 ( V_60 ) ) {
F_16 () ;
return F_30 ( V_60 ) ;
}
V_33 -> V_38 = F_43 ( V_60 , NULL , 0 ) ;
F_11 ( V_60 ) ;
return 0 ;
}
int F_44 ( struct V_32 V_33 , int abort )
{
char V_62 [ 2 ] ;
int V_27 ;
if ( abort )
strcpy ( V_62 , L_6 ) ;
else
strcpy ( V_62 , L_7 ) ;
V_27 = F_29 ( F_28 ( V_33 , V_31 , V_62 , NULL ) ) ;
F_16 () ;
return V_27 ;
}
int F_45 ( struct V_32 V_33 ,
const char * V_45 , const char * V_51 , const char * V_63 , ... )
{
T_1 V_64 ;
int V_25 ;
char * V_65 ;
V_65 = F_38 ( V_33 , V_45 , V_51 , NULL ) ;
if ( F_26 ( V_65 ) )
return F_30 ( V_65 ) ;
va_start ( V_64 , V_63 ) ;
V_25 = vsscanf ( V_65 , V_63 , V_64 ) ;
va_end ( V_64 ) ;
F_11 ( V_65 ) ;
if ( V_25 == 0 )
return - V_66 ;
return V_25 ;
}
int F_46 ( struct V_32 V_33 ,
const char * V_45 , const char * V_51 , const char * V_63 , ... )
{
T_1 V_64 ;
int V_25 ;
char * V_67 ;
va_start ( V_64 , V_63 ) ;
V_67 = F_47 ( V_48 | V_49 , V_63 , V_64 ) ;
va_end ( V_64 ) ;
if ( ! V_67 )
return - V_50 ;
V_25 = F_39 ( V_33 , V_45 , V_51 , V_67 ) ;
F_11 ( V_67 ) ;
return V_25 ;
}
int F_48 ( struct V_32 V_33 , const char * V_45 , ... )
{
T_1 V_64 ;
const char * V_46 ;
int V_25 = 0 ;
va_start ( V_64 , V_45 ) ;
while ( V_25 == 0 && ( V_46 = va_arg ( V_64 , char * ) ) != NULL ) {
const char * V_63 = va_arg ( V_64 , char * ) ;
void * V_68 = va_arg ( V_64 , void * ) ;
char * V_44 ;
V_44 = F_38 ( V_33 , V_45 , V_46 , NULL ) ;
if ( F_26 ( V_44 ) ) {
V_25 = F_30 ( V_44 ) ;
break;
}
if ( V_63 ) {
if ( sscanf ( V_44 , V_63 , V_68 ) == 0 )
V_25 = - V_5 ;
F_11 ( V_44 ) ;
} else
* ( char * * ) V_68 = V_44 ;
}
va_end ( V_64 ) ;
return V_25 ;
}
static int F_49 ( const char * V_52 , const char * V_69 )
{
struct V_34 V_70 [ 2 ] ;
V_70 [ 0 ] . V_41 = ( void * ) V_52 ;
V_70 [ 0 ] . V_40 = strlen ( V_52 ) + 1 ;
V_70 [ 1 ] . V_41 = ( void * ) V_69 ;
V_70 [ 1 ] . V_40 = strlen ( V_69 ) + 1 ;
return F_29 ( F_25 ( V_61 , V_71 , V_70 ,
F_2 ( V_70 ) , NULL ) ) ;
}
static int F_50 ( const char * V_52 , const char * V_69 )
{
struct V_34 V_70 [ 2 ] ;
V_70 [ 0 ] . V_41 = ( char * ) V_52 ;
V_70 [ 0 ] . V_40 = strlen ( V_52 ) + 1 ;
V_70 [ 1 ] . V_41 = ( char * ) V_69 ;
V_70 [ 1 ] . V_40 = strlen ( V_69 ) + 1 ;
return F_29 ( F_25 ( V_61 , V_72 , V_70 ,
F_2 ( V_70 ) , NULL ) ) ;
}
static struct V_73 * F_51 ( const char * V_69 )
{
struct V_73 * V_2 , * V_74 ;
V_74 = ( void * ) F_43 ( V_69 , NULL , 16 ) ;
F_52 (i, &watches, list)
if ( V_2 == V_74 )
return V_2 ;
return NULL ;
}
static bool F_53 ( void )
{
#ifdef F_54
T_2 V_75 , V_76 , V_77 , V_78 , V_79 ;
V_79 = F_55 () ;
F_56 ( V_79 + 1 , & V_75 , & V_76 , & V_77 , & V_78 ) ;
if ( ( V_75 >> 16 ) < 4 )
return true ;
#endif
return false ;
}
static void F_57 ( void )
{
int V_27 , V_80 = 0 ;
if ( ! F_58 () || F_59 () )
return;
if ( F_53 () )
return;
V_27 = F_45 ( V_61 , L_8 ,
L_9 , L_10 , & V_80 ) ;
if ( V_27 != 1 || ! V_80 )
return;
V_27 = F_29 ( F_28 ( V_61 , V_81 , L_5 , NULL ) ) ;
if ( V_27 && V_27 != - V_82 )
F_3 ( L_11 , V_27 ) ;
}
int F_60 ( struct V_73 * V_83 )
{
char V_69 [ sizeof( V_83 ) * 2 + 1 ] ;
int V_27 ;
sprintf ( V_69 , L_12 , ( long ) V_83 ) ;
F_61 ( & V_12 . V_84 ) ;
F_5 ( & V_85 ) ;
F_62 ( F_51 ( V_69 ) ) ;
F_63 ( & V_83 -> V_17 , & V_86 ) ;
F_7 ( & V_85 ) ;
V_27 = F_49 ( V_83 -> V_51 , V_69 ) ;
if ( V_27 ) {
F_5 ( & V_85 ) ;
F_10 ( & V_83 -> V_17 ) ;
F_7 ( & V_85 ) ;
}
F_64 ( & V_12 . V_84 ) ;
return V_27 ;
}
void F_65 ( struct V_73 * V_83 )
{
struct V_9 * V_10 , * V_87 ;
char V_69 [ sizeof( V_83 ) * 2 + 1 ] ;
int V_27 ;
sprintf ( V_69 , L_12 , ( long ) V_83 ) ;
F_61 ( & V_12 . V_84 ) ;
F_5 ( & V_85 ) ;
F_62 ( ! F_51 ( V_69 ) ) ;
F_10 ( & V_83 -> V_17 ) ;
F_7 ( & V_85 ) ;
V_27 = F_50 ( V_83 -> V_51 , V_69 ) ;
if ( V_27 )
F_3 ( L_13 , V_83 -> V_51 , V_27 ) ;
F_64 ( & V_12 . V_84 ) ;
if ( V_88 -> V_89 != V_90 )
F_13 ( & V_91 ) ;
F_5 ( & V_92 ) ;
F_66 (msg, tmp, &watch_events, list) {
if ( V_10 -> V_19 . V_83 . V_93 != V_83 )
continue;
F_10 ( & V_10 -> V_17 ) ;
F_11 ( V_10 -> V_19 . V_83 . V_94 ) ;
F_11 ( V_10 ) ;
}
F_7 ( & V_92 ) ;
if ( V_88 -> V_89 != V_90 )
F_15 ( & V_91 ) ;
}
void F_67 ( void )
{
F_19 () ;
F_68 ( & V_12 . V_84 ) ;
F_13 ( & V_12 . V_29 ) ;
F_13 ( & V_12 . V_95 ) ;
}
void F_69 ( void )
{
struct V_73 * V_83 ;
char V_69 [ sizeof( V_83 ) * 2 + 1 ] ;
F_70 () ;
F_15 ( & V_12 . V_95 ) ;
F_15 ( & V_12 . V_29 ) ;
F_21 () ;
F_52 (watch, &watches, list) {
sprintf ( V_69 , L_12 , ( long ) V_83 ) ;
F_49 ( V_83 -> V_51 , V_69 ) ;
}
F_71 ( & V_12 . V_84 ) ;
}
void F_72 ( void )
{
F_15 ( & V_12 . V_95 ) ;
F_15 ( & V_12 . V_29 ) ;
F_71 ( & V_12 . V_84 ) ;
F_15 ( & V_12 . V_21 ) ;
}
static int F_73 ( void * V_96 )
{
struct V_97 * V_98 ;
struct V_9 * V_10 ;
for (; ; ) {
F_74 ( V_99 ,
! F_6 ( & V_100 ) ) ;
if ( F_75 () )
break;
F_13 ( & V_91 ) ;
F_5 ( & V_92 ) ;
V_98 = V_100 . V_16 ;
if ( V_98 != & V_100 )
F_10 ( V_98 ) ;
F_7 ( & V_92 ) ;
if ( V_98 != & V_100 ) {
V_10 = F_9 ( V_98 , struct V_9 , V_17 ) ;
V_10 -> V_19 . V_83 . V_93 -> V_101 (
V_10 -> V_19 . V_83 . V_93 ,
( const char * * ) V_10 -> V_19 . V_83 . V_94 ,
V_10 -> V_19 . V_83 . V_102 ) ;
F_11 ( V_10 -> V_19 . V_83 . V_94 ) ;
F_11 ( V_10 ) ;
}
F_15 ( & V_91 ) ;
}
return 0 ;
}
static int F_76 ( void )
{
struct V_9 * V_10 ;
char * V_11 ;
int V_27 ;
for (; ; ) {
V_27 = F_77 () ;
if ( V_27 )
return V_27 ;
F_13 ( & V_12 . V_95 ) ;
if ( F_78 () )
break;
F_15 ( & V_12 . V_95 ) ;
}
V_10 = F_35 ( sizeof( * V_10 ) , V_48 | V_49 ) ;
if ( V_10 == NULL ) {
V_27 = - V_50 ;
goto V_103;
}
V_27 = F_79 ( & V_10 -> V_18 , sizeof( V_10 -> V_18 ) ) ;
if ( V_27 ) {
F_11 ( V_10 ) ;
goto V_103;
}
if ( V_10 -> V_18 . V_8 > V_104 ) {
F_11 ( V_10 ) ;
V_27 = - V_5 ;
goto V_103;
}
V_11 = F_35 ( V_10 -> V_18 . V_8 + 1 , V_48 | V_49 ) ;
if ( V_11 == NULL ) {
F_11 ( V_10 ) ;
V_27 = - V_50 ;
goto V_103;
}
V_27 = F_79 ( V_11 , V_10 -> V_18 . V_8 ) ;
if ( V_27 ) {
F_11 ( V_11 ) ;
F_11 ( V_10 ) ;
goto V_103;
}
V_11 [ V_10 -> V_18 . V_8 ] = '\0' ;
if ( V_10 -> V_18 . type == V_105 ) {
V_10 -> V_19 . V_83 . V_94 = F_34 ( V_11 , V_10 -> V_18 . V_8 ,
& V_10 -> V_19 . V_83 . V_102 ) ;
if ( F_26 ( V_10 -> V_19 . V_83 . V_94 ) ) {
V_27 = F_30 ( V_10 -> V_19 . V_83 . V_94 ) ;
F_11 ( V_10 ) ;
goto V_103;
}
F_5 ( & V_85 ) ;
V_10 -> V_19 . V_83 . V_93 = F_51 (
V_10 -> V_19 . V_83 . V_94 [ V_106 ] ) ;
if ( V_10 -> V_19 . V_83 . V_93 != NULL ) {
F_5 ( & V_92 ) ;
F_80 ( & V_10 -> V_17 , & V_100 ) ;
F_18 ( & V_99 ) ;
F_7 ( & V_92 ) ;
} else {
F_11 ( V_10 -> V_19 . V_83 . V_94 ) ;
F_11 ( V_10 ) ;
}
F_7 ( & V_85 ) ;
} else {
V_10 -> V_19 . V_20 . V_11 = V_11 ;
F_5 ( & V_12 . V_13 ) ;
F_80 ( & V_10 -> V_17 , & V_12 . V_14 ) ;
F_7 ( & V_12 . V_13 ) ;
F_18 ( & V_12 . V_15 ) ;
}
V_103:
F_15 ( & V_12 . V_95 ) ;
return V_27 ;
}
static int F_81 ( void * V_96 )
{
int V_27 ;
for (; ; ) {
V_27 = F_76 () ;
if ( V_27 )
F_3 ( L_14 , V_27 ) ;
if ( F_75 () )
break;
}
return 0 ;
}
int F_82 ( void )
{
int V_27 ;
struct V_107 * V_108 ;
F_83 ( & V_12 . V_14 ) ;
F_84 ( & V_12 . V_13 ) ;
F_85 ( & V_12 . V_15 ) ;
F_86 ( & V_12 . V_29 ) ;
F_86 ( & V_12 . V_95 ) ;
F_86 ( & V_12 . V_21 ) ;
F_87 ( & V_12 . V_84 ) ;
F_88 ( & V_12 . V_22 , 0 ) ;
F_85 ( & V_12 . V_23 ) ;
V_27 = F_70 () ;
if ( V_27 )
return V_27 ;
V_108 = F_89 ( F_73 , NULL , L_15 ) ;
if ( F_26 ( V_108 ) )
return F_30 ( V_108 ) ;
V_90 = V_108 -> V_89 ;
V_108 = F_89 ( F_81 , NULL , L_16 ) ;
if ( F_26 ( V_108 ) )
return F_30 ( V_108 ) ;
F_57 () ;
return 0 ;
}
