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
static bool F_4 ( void )
{
switch ( V_7 ) {
case V_8 :
switch ( V_9 ) {
case V_10 :
case V_11 :
case V_12 :
return false ;
default:
break;
}
return true ;
case V_13 :
case V_14 :
return true ;
default:
break;
}
return false ;
}
static void * F_5 ( enum V_15 * type , unsigned int * V_16 )
{
struct V_17 * V_18 ;
char * V_19 ;
F_6 ( & V_20 . V_21 ) ;
while ( F_7 ( & V_20 . V_22 ) ) {
F_8 ( & V_20 . V_21 ) ;
if ( F_4 () )
F_9 ( V_20 . V_23 ,
! F_7 ( & V_20 . V_22 ) ,
F_10 ( 500 ) ) ;
else {
return F_11 ( - V_24 ) ;
}
F_6 ( & V_20 . V_21 ) ;
}
V_18 = F_12 ( V_20 . V_22 . V_25 ,
struct V_17 , V_26 ) ;
F_13 ( & V_18 -> V_26 ) ;
F_8 ( & V_20 . V_21 ) ;
* type = V_18 -> V_27 . type ;
if ( V_16 )
* V_16 = V_18 -> V_27 . V_16 ;
V_19 = V_18 -> V_28 . V_29 . V_19 ;
F_14 ( V_18 ) ;
return V_19 ;
}
static void F_15 ( void )
{
F_16 ( & V_20 . V_30 ) ;
F_17 ( & V_20 . V_31 ) ;
F_18 ( & V_20 . V_30 ) ;
}
static void F_19 ( void )
{
if ( F_20 ( & V_20 . V_31 ) )
F_21 ( & V_20 . V_32 ) ;
}
static void F_22 ( void )
{
F_16 ( & V_20 . V_30 ) ;
F_23 ( V_20 . V_32 ,
F_24 ( & V_20 . V_31 ) == 0 ) ;
}
static void F_25 ( void )
{
F_18 ( & V_20 . V_30 ) ;
}
void * F_26 ( struct V_33 * V_18 )
{
void * V_34 ;
struct V_33 V_35 = * V_18 ;
int V_36 ;
if ( V_35 . type == V_37 )
F_15 () ;
F_16 ( & V_20 . V_38 ) ;
V_36 = F_27 ( V_18 , sizeof( * V_18 ) + V_18 -> V_16 ) ;
if ( V_36 ) {
V_18 -> type = V_39 ;
V_34 = F_11 ( V_36 ) ;
} else
V_34 = F_5 ( & V_18 -> type , & V_18 -> V_16 ) ;
F_18 ( & V_20 . V_38 ) ;
if ( F_28 ( V_34 ) )
return V_34 ;
if ( ( V_18 -> type == V_40 ) ||
( ( V_35 . type == V_37 ) &&
( V_18 -> type == V_39 ) ) )
F_19 () ;
return V_34 ;
}
static void * F_29 ( struct V_41 V_42 ,
enum V_15 type ,
const struct V_43 * V_44 ,
unsigned int V_45 ,
unsigned int * V_16 )
{
struct V_33 V_18 ;
void * V_34 = NULL ;
unsigned int V_2 ;
int V_36 ;
V_18 . V_46 = V_42 . V_47 ;
V_18 . V_48 = 0 ;
V_18 . type = type ;
V_18 . V_16 = 0 ;
for ( V_2 = 0 ; V_2 < V_45 ; V_2 ++ )
V_18 . V_16 += V_44 [ V_2 ] . V_49 ;
F_16 ( & V_20 . V_38 ) ;
V_36 = F_27 ( & V_18 , sizeof( V_18 ) ) ;
if ( V_36 ) {
F_18 ( & V_20 . V_38 ) ;
return F_11 ( V_36 ) ;
}
for ( V_2 = 0 ; V_2 < V_45 ; V_2 ++ ) {
V_36 = F_27 ( V_44 [ V_2 ] . V_50 , V_44 [ V_2 ] . V_49 ) ;
if ( V_36 ) {
F_18 ( & V_20 . V_38 ) ;
return F_11 ( V_36 ) ;
}
}
V_34 = F_5 ( & V_18 . type , V_16 ) ;
F_18 ( & V_20 . V_38 ) ;
if ( F_28 ( V_34 ) )
return V_34 ;
if ( V_18 . type == V_39 ) {
V_36 = F_1 ( V_34 ) ;
F_14 ( V_34 ) ;
return F_11 ( - V_36 ) ;
}
if ( V_18 . type != type ) {
F_30 ( L_2 ,
V_18 . type , type ) ;
F_14 ( V_34 ) ;
return F_11 ( - V_5 ) ;
}
return V_34 ;
}
static void * F_31 ( struct V_41 V_42 ,
enum V_15 type ,
const char * string ,
unsigned int * V_16 )
{
struct V_43 V_44 ;
V_44 . V_50 = ( void * ) string ;
V_44 . V_49 = strlen ( string ) + 1 ;
return F_29 ( V_42 , type , & V_44 , 1 , V_16 ) ;
}
static int F_32 ( char * V_29 )
{
if ( F_28 ( V_29 ) )
return F_33 ( V_29 ) ;
F_14 ( V_29 ) ;
return 0 ;
}
static unsigned int F_34 ( const char * V_51 , unsigned int V_16 )
{
unsigned int V_52 ;
const char * V_53 ;
for ( V_53 = V_51 , V_52 = 0 ; V_53 < V_51 + V_16 ; V_53 += strlen ( V_53 ) + 1 )
V_52 ++ ;
return V_52 ;
}
static char * F_35 ( const char * V_54 , const char * V_55 )
{
char * V_56 ;
if ( strlen ( V_55 ) == 0 )
V_56 = F_36 ( V_57 | V_58 , L_3 , V_54 ) ;
else
V_56 = F_36 ( V_57 | V_58 , L_4 , V_54 , V_55 ) ;
return ( ! V_56 ) ? F_11 ( - V_59 ) : V_56 ;
}
static char * * F_37 ( char * V_51 , unsigned int V_16 , unsigned int * V_52 )
{
char * V_53 , * * V_34 ;
* V_52 = F_34 ( V_51 , V_16 ) ;
V_34 = F_38 ( * V_52 * sizeof( char * ) + V_16 , V_57 | V_58 ) ;
if ( ! V_34 ) {
F_14 ( V_51 ) ;
return F_11 ( - V_59 ) ;
}
memcpy ( & V_34 [ * V_52 ] , V_51 , V_16 ) ;
F_14 ( V_51 ) ;
V_51 = ( char * ) & V_34 [ * V_52 ] ;
for ( V_53 = V_51 , * V_52 = 0 ; V_53 < V_51 + V_16 ; V_53 += strlen ( V_53 ) + 1 )
V_34 [ ( * V_52 ) ++ ] = V_53 ;
return V_34 ;
}
char * * F_39 ( struct V_41 V_42 ,
const char * V_54 , const char * V_60 , unsigned int * V_52 )
{
char * V_51 , * V_61 ;
unsigned int V_16 ;
V_61 = F_35 ( V_54 , V_60 ) ;
if ( F_28 ( V_61 ) )
return ( char * * ) V_61 ;
V_51 = F_31 ( V_42 , V_62 , V_61 , & V_16 ) ;
F_14 ( V_61 ) ;
if ( F_28 ( V_51 ) )
return ( char * * ) V_51 ;
return F_37 ( V_51 , V_16 , V_52 ) ;
}
int F_40 ( struct V_41 V_42 ,
const char * V_54 , const char * V_60 )
{
char * * V_63 ;
int V_64 ;
V_63 = F_39 ( V_42 , V_54 , V_60 , & V_64 ) ;
if ( F_28 ( V_63 ) )
return 0 ;
F_14 ( V_63 ) ;
return 1 ;
}
void * F_41 ( struct V_41 V_42 ,
const char * V_54 , const char * V_60 , unsigned int * V_16 )
{
char * V_61 ;
void * V_34 ;
V_61 = F_35 ( V_54 , V_60 ) ;
if ( F_28 ( V_61 ) )
return ( void * ) V_61 ;
V_34 = F_31 ( V_42 , V_65 , V_61 , V_16 ) ;
F_14 ( V_61 ) ;
return V_34 ;
}
int F_42 ( struct V_41 V_42 ,
const char * V_54 , const char * V_60 , const char * string )
{
const char * V_61 ;
struct V_43 V_44 [ 2 ] ;
int V_34 ;
V_61 = F_35 ( V_54 , V_60 ) ;
if ( F_28 ( V_61 ) )
return F_33 ( V_61 ) ;
V_44 [ 0 ] . V_50 = ( void * ) V_61 ;
V_44 [ 0 ] . V_49 = strlen ( V_61 ) + 1 ;
V_44 [ 1 ] . V_50 = ( void * ) string ;
V_44 [ 1 ] . V_49 = strlen ( string ) ;
V_34 = F_32 ( F_29 ( V_42 , V_66 , V_44 , F_2 ( V_44 ) , NULL ) ) ;
F_14 ( V_61 ) ;
return V_34 ;
}
int F_43 ( struct V_41 V_42 ,
const char * V_54 , const char * V_60 )
{
char * V_61 ;
int V_34 ;
V_61 = F_35 ( V_54 , V_60 ) ;
if ( F_28 ( V_61 ) )
return F_33 ( V_61 ) ;
V_34 = F_32 ( F_31 ( V_42 , V_67 , V_61 , NULL ) ) ;
F_14 ( V_61 ) ;
return V_34 ;
}
int F_44 ( struct V_41 V_42 , const char * V_54 , const char * V_60 )
{
char * V_61 ;
int V_34 ;
V_61 = F_35 ( V_54 , V_60 ) ;
if ( F_28 ( V_61 ) )
return F_33 ( V_61 ) ;
V_34 = F_32 ( F_31 ( V_42 , V_68 , V_61 , NULL ) ) ;
F_14 ( V_61 ) ;
return V_34 ;
}
int F_45 ( struct V_41 * V_42 )
{
char * V_69 ;
F_15 () ;
V_69 = F_31 ( V_70 , V_37 , L_5 , NULL ) ;
if ( F_28 ( V_69 ) ) {
F_19 () ;
return F_33 ( V_69 ) ;
}
V_42 -> V_47 = F_46 ( V_69 , NULL , 0 ) ;
F_14 ( V_69 ) ;
return 0 ;
}
int F_47 ( struct V_41 V_42 , int abort )
{
char V_71 [ 2 ] ;
int V_36 ;
if ( abort )
strcpy ( V_71 , L_6 ) ;
else
strcpy ( V_71 , L_7 ) ;
V_36 = F_32 ( F_31 ( V_42 , V_40 , V_71 , NULL ) ) ;
F_19 () ;
return V_36 ;
}
int F_48 ( struct V_41 V_42 ,
const char * V_54 , const char * V_60 , const char * V_72 , ... )
{
T_1 V_73 ;
int V_34 ;
char * V_74 ;
V_74 = F_41 ( V_42 , V_54 , V_60 , NULL ) ;
if ( F_28 ( V_74 ) )
return F_33 ( V_74 ) ;
va_start ( V_73 , V_72 ) ;
V_34 = vsscanf ( V_74 , V_72 , V_73 ) ;
va_end ( V_73 ) ;
F_14 ( V_74 ) ;
if ( V_34 == 0 )
return - V_75 ;
return V_34 ;
}
int F_49 ( struct V_41 V_42 ,
const char * V_54 , const char * V_60 , const char * V_72 , ... )
{
T_1 V_73 ;
int V_34 ;
char * V_76 ;
va_start ( V_73 , V_72 ) ;
V_76 = F_50 ( V_57 | V_58 , V_72 , V_73 ) ;
va_end ( V_73 ) ;
if ( ! V_76 )
return - V_59 ;
V_34 = F_42 ( V_42 , V_54 , V_60 , V_76 ) ;
F_14 ( V_76 ) ;
return V_34 ;
}
int F_51 ( struct V_41 V_42 , const char * V_54 , ... )
{
T_1 V_73 ;
const char * V_55 ;
int V_34 = 0 ;
va_start ( V_73 , V_54 ) ;
while ( V_34 == 0 && ( V_55 = va_arg ( V_73 , char * ) ) != NULL ) {
const char * V_72 = va_arg ( V_73 , char * ) ;
void * V_77 = va_arg ( V_73 , void * ) ;
char * V_53 ;
V_53 = F_41 ( V_42 , V_54 , V_55 , NULL ) ;
if ( F_28 ( V_53 ) ) {
V_34 = F_33 ( V_53 ) ;
break;
}
if ( V_72 ) {
if ( sscanf ( V_53 , V_72 , V_77 ) == 0 )
V_34 = - V_5 ;
F_14 ( V_53 ) ;
} else
* ( char * * ) V_77 = V_53 ;
}
va_end ( V_73 ) ;
return V_34 ;
}
static int F_52 ( const char * V_61 , const char * V_78 )
{
struct V_43 V_79 [ 2 ] ;
V_79 [ 0 ] . V_50 = ( void * ) V_61 ;
V_79 [ 0 ] . V_49 = strlen ( V_61 ) + 1 ;
V_79 [ 1 ] . V_50 = ( void * ) V_78 ;
V_79 [ 1 ] . V_49 = strlen ( V_78 ) + 1 ;
return F_32 ( F_29 ( V_70 , V_80 , V_79 ,
F_2 ( V_79 ) , NULL ) ) ;
}
static int F_53 ( const char * V_61 , const char * V_78 )
{
struct V_43 V_79 [ 2 ] ;
V_79 [ 0 ] . V_50 = ( char * ) V_61 ;
V_79 [ 0 ] . V_49 = strlen ( V_61 ) + 1 ;
V_79 [ 1 ] . V_50 = ( char * ) V_78 ;
V_79 [ 1 ] . V_49 = strlen ( V_78 ) + 1 ;
return F_32 ( F_29 ( V_70 , V_81 , V_79 ,
F_2 ( V_79 ) , NULL ) ) ;
}
static struct V_82 * F_54 ( const char * V_78 )
{
struct V_82 * V_2 , * V_83 ;
V_83 = ( void * ) F_46 ( V_78 , NULL , 16 ) ;
F_55 (i, &watches, list)
if ( V_2 == V_83 )
return V_2 ;
return NULL ;
}
static bool F_56 ( void )
{
#ifdef F_57
T_2 V_84 , V_85 , V_86 , V_87 , V_88 ;
V_88 = F_58 () ;
F_59 ( V_88 + 1 , & V_84 , & V_85 , & V_86 , & V_87 ) ;
if ( ( V_84 >> 16 ) < 4 )
return true ;
#endif
return false ;
}
static void F_60 ( void )
{
int V_36 , V_89 = 0 ;
if ( ! F_61 () || F_62 () )
return;
if ( F_56 () )
return;
V_36 = F_48 ( V_70 , L_8 ,
L_9 , L_10 , & V_89 ) ;
if ( V_36 != 1 || ! V_89 )
return;
V_36 = F_32 ( F_31 ( V_70 , V_90 , L_5 , NULL ) ) ;
if ( V_36 && V_36 != - V_91 )
F_3 ( L_11 , V_36 ) ;
}
int F_63 ( struct V_82 * V_92 )
{
char V_78 [ sizeof( V_92 ) * 2 + 1 ] ;
int V_36 ;
sprintf ( V_78 , L_12 , ( long ) V_92 ) ;
F_64 ( & V_20 . V_93 ) ;
F_6 ( & V_94 ) ;
F_65 ( F_54 ( V_78 ) ) ;
F_66 ( & V_92 -> V_26 , & V_95 ) ;
F_8 ( & V_94 ) ;
V_36 = F_52 ( V_92 -> V_60 , V_78 ) ;
if ( V_36 ) {
F_6 ( & V_94 ) ;
F_13 ( & V_92 -> V_26 ) ;
F_8 ( & V_94 ) ;
}
F_67 ( & V_20 . V_93 ) ;
return V_36 ;
}
void F_68 ( struct V_82 * V_92 )
{
struct V_17 * V_18 , * V_96 ;
char V_78 [ sizeof( V_92 ) * 2 + 1 ] ;
int V_36 ;
sprintf ( V_78 , L_12 , ( long ) V_92 ) ;
F_64 ( & V_20 . V_93 ) ;
F_6 ( & V_94 ) ;
F_65 ( ! F_54 ( V_78 ) ) ;
F_13 ( & V_92 -> V_26 ) ;
F_8 ( & V_94 ) ;
V_36 = F_53 ( V_92 -> V_60 , V_78 ) ;
if ( V_36 )
F_3 ( L_13 , V_92 -> V_60 , V_36 ) ;
F_67 ( & V_20 . V_93 ) ;
if ( V_97 -> V_98 != V_99 )
F_16 ( & V_100 ) ;
F_6 ( & V_101 ) ;
F_69 (msg, tmp, &watch_events, list) {
if ( V_18 -> V_28 . V_92 . V_102 != V_92 )
continue;
F_13 ( & V_18 -> V_26 ) ;
F_14 ( V_18 -> V_28 . V_92 . V_103 ) ;
F_14 ( V_18 ) ;
}
F_8 ( & V_101 ) ;
if ( V_97 -> V_98 != V_99 )
F_18 ( & V_100 ) ;
}
void F_70 ( void )
{
F_22 () ;
F_71 ( & V_20 . V_93 ) ;
F_16 ( & V_20 . V_38 ) ;
F_16 ( & V_20 . V_104 ) ;
}
void F_72 ( void )
{
struct V_82 * V_92 ;
char V_78 [ sizeof( V_92 ) * 2 + 1 ] ;
F_73 () ;
F_18 ( & V_20 . V_104 ) ;
F_18 ( & V_20 . V_38 ) ;
F_25 () ;
F_55 (watch, &watches, list) {
sprintf ( V_78 , L_12 , ( long ) V_92 ) ;
F_52 ( V_92 -> V_60 , V_78 ) ;
}
F_74 ( & V_20 . V_93 ) ;
}
void F_75 ( void )
{
F_18 ( & V_20 . V_104 ) ;
F_18 ( & V_20 . V_38 ) ;
F_74 ( & V_20 . V_93 ) ;
F_18 ( & V_20 . V_30 ) ;
}
static int F_76 ( void * V_105 )
{
struct V_106 * V_107 ;
struct V_17 * V_18 ;
for (; ; ) {
F_77 ( V_108 ,
! F_7 ( & V_109 ) ) ;
if ( F_78 () )
break;
F_16 ( & V_100 ) ;
F_6 ( & V_101 ) ;
V_107 = V_109 . V_25 ;
if ( V_107 != & V_109 )
F_13 ( V_107 ) ;
F_8 ( & V_101 ) ;
if ( V_107 != & V_109 ) {
V_18 = F_12 ( V_107 , struct V_17 , V_26 ) ;
V_18 -> V_28 . V_92 . V_102 -> V_110 (
V_18 -> V_28 . V_92 . V_102 ,
( const char * * ) V_18 -> V_28 . V_92 . V_103 ,
V_18 -> V_28 . V_92 . V_111 ) ;
F_14 ( V_18 -> V_28 . V_92 . V_103 ) ;
F_14 ( V_18 ) ;
}
F_18 ( & V_100 ) ;
}
return 0 ;
}
static int F_79 ( void )
{
struct V_17 * V_18 ;
char * V_19 ;
int V_36 ;
for (; ; ) {
V_36 = F_80 () ;
if ( V_36 )
return V_36 ;
F_16 ( & V_20 . V_104 ) ;
if ( F_81 () )
break;
F_18 ( & V_20 . V_104 ) ;
}
V_18 = F_38 ( sizeof( * V_18 ) , V_57 | V_58 ) ;
if ( V_18 == NULL ) {
V_36 = - V_59 ;
goto V_112;
}
V_36 = F_82 ( & V_18 -> V_27 , sizeof( V_18 -> V_27 ) ) ;
if ( V_36 ) {
F_14 ( V_18 ) ;
goto V_112;
}
if ( V_18 -> V_27 . V_16 > V_113 ) {
F_14 ( V_18 ) ;
V_36 = - V_5 ;
goto V_112;
}
V_19 = F_38 ( V_18 -> V_27 . V_16 + 1 , V_57 | V_58 ) ;
if ( V_19 == NULL ) {
F_14 ( V_18 ) ;
V_36 = - V_59 ;
goto V_112;
}
V_36 = F_82 ( V_19 , V_18 -> V_27 . V_16 ) ;
if ( V_36 ) {
F_14 ( V_19 ) ;
F_14 ( V_18 ) ;
goto V_112;
}
V_19 [ V_18 -> V_27 . V_16 ] = '\0' ;
if ( V_18 -> V_27 . type == V_114 ) {
V_18 -> V_28 . V_92 . V_103 = F_37 ( V_19 , V_18 -> V_27 . V_16 ,
& V_18 -> V_28 . V_92 . V_111 ) ;
if ( F_28 ( V_18 -> V_28 . V_92 . V_103 ) ) {
V_36 = F_33 ( V_18 -> V_28 . V_92 . V_103 ) ;
F_14 ( V_18 ) ;
goto V_112;
}
F_6 ( & V_94 ) ;
V_18 -> V_28 . V_92 . V_102 = F_54 (
V_18 -> V_28 . V_92 . V_103 [ V_115 ] ) ;
if ( V_18 -> V_28 . V_92 . V_102 != NULL ) {
F_6 ( & V_101 ) ;
F_83 ( & V_18 -> V_26 , & V_109 ) ;
F_21 ( & V_108 ) ;
F_8 ( & V_101 ) ;
} else {
F_14 ( V_18 -> V_28 . V_92 . V_103 ) ;
F_14 ( V_18 ) ;
}
F_8 ( & V_94 ) ;
} else {
V_18 -> V_28 . V_29 . V_19 = V_19 ;
F_6 ( & V_20 . V_21 ) ;
F_83 ( & V_18 -> V_26 , & V_20 . V_22 ) ;
F_8 ( & V_20 . V_21 ) ;
F_21 ( & V_20 . V_23 ) ;
}
V_112:
F_18 ( & V_20 . V_104 ) ;
return V_36 ;
}
static int F_84 ( void * V_105 )
{
int V_36 ;
for (; ; ) {
V_36 = F_79 () ;
if ( V_36 )
F_3 ( L_14 , V_36 ) ;
if ( F_78 () )
break;
}
return 0 ;
}
int F_85 ( void )
{
int V_36 ;
struct V_116 * V_117 ;
F_86 ( & V_20 . V_22 ) ;
F_87 ( & V_20 . V_21 ) ;
F_88 ( & V_20 . V_23 ) ;
F_89 ( & V_20 . V_38 ) ;
F_89 ( & V_20 . V_104 ) ;
F_89 ( & V_20 . V_30 ) ;
F_90 ( & V_20 . V_93 ) ;
F_91 ( & V_20 . V_31 , 0 ) ;
F_88 ( & V_20 . V_32 ) ;
V_36 = F_73 () ;
if ( V_36 )
return V_36 ;
V_117 = F_92 ( F_76 , NULL , L_15 ) ;
if ( F_28 ( V_117 ) )
return F_33 ( V_117 ) ;
V_99 = V_117 -> V_98 ;
V_117 = F_92 ( F_84 , NULL , L_16 ) ;
if ( F_28 ( V_117 ) )
return F_33 ( V_117 ) ;
F_60 () ;
return 0 ;
}
