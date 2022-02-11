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
enum V_15 type = V_18 -> type ;
int V_35 ;
if ( type == V_36 )
F_15 () ;
F_16 ( & V_20 . V_37 ) ;
V_35 = F_27 ( V_18 , sizeof( * V_18 ) + V_18 -> V_16 ) ;
if ( V_35 ) {
V_18 -> type = V_38 ;
V_34 = F_11 ( V_35 ) ;
} else
V_34 = F_5 ( & V_18 -> type , & V_18 -> V_16 ) ;
F_18 ( & V_20 . V_37 ) ;
if ( ( V_18 -> type == V_39 ) ||
( ( type == V_36 ) && ( V_18 -> type == V_38 ) ) )
F_19 () ;
return V_34 ;
}
static void * F_28 ( struct V_40 V_41 ,
enum V_15 type ,
const struct V_42 * V_43 ,
unsigned int V_44 ,
unsigned int * V_16 )
{
struct V_33 V_18 ;
void * V_34 = NULL ;
unsigned int V_2 ;
int V_35 ;
V_18 . V_45 = V_41 . V_46 ;
V_18 . V_47 = 0 ;
V_18 . type = type ;
V_18 . V_16 = 0 ;
for ( V_2 = 0 ; V_2 < V_44 ; V_2 ++ )
V_18 . V_16 += V_43 [ V_2 ] . V_48 ;
F_16 ( & V_20 . V_37 ) ;
V_35 = F_27 ( & V_18 , sizeof( V_18 ) ) ;
if ( V_35 ) {
F_18 ( & V_20 . V_37 ) ;
return F_11 ( V_35 ) ;
}
for ( V_2 = 0 ; V_2 < V_44 ; V_2 ++ ) {
V_35 = F_27 ( V_43 [ V_2 ] . V_49 , V_43 [ V_2 ] . V_48 ) ;
if ( V_35 ) {
F_18 ( & V_20 . V_37 ) ;
return F_11 ( V_35 ) ;
}
}
V_34 = F_5 ( & V_18 . type , V_16 ) ;
F_18 ( & V_20 . V_37 ) ;
if ( F_29 ( V_34 ) )
return V_34 ;
if ( V_18 . type == V_38 ) {
V_35 = F_1 ( V_34 ) ;
F_14 ( V_34 ) ;
return F_11 ( - V_35 ) ;
}
if ( V_18 . type != type ) {
F_30 ( L_2 ,
V_18 . type , type ) ;
F_14 ( V_34 ) ;
return F_11 ( - V_5 ) ;
}
return V_34 ;
}
static void * F_31 ( struct V_40 V_41 ,
enum V_15 type ,
const char * string ,
unsigned int * V_16 )
{
struct V_42 V_43 ;
V_43 . V_49 = ( void * ) string ;
V_43 . V_48 = strlen ( string ) + 1 ;
return F_28 ( V_41 , type , & V_43 , 1 , V_16 ) ;
}
static int F_32 ( char * V_29 )
{
if ( F_29 ( V_29 ) )
return F_33 ( V_29 ) ;
F_14 ( V_29 ) ;
return 0 ;
}
static unsigned int F_34 ( const char * V_50 , unsigned int V_16 )
{
unsigned int V_51 ;
const char * V_52 ;
for ( V_52 = V_50 , V_51 = 0 ; V_52 < V_50 + V_16 ; V_52 += strlen ( V_52 ) + 1 )
V_51 ++ ;
return V_51 ;
}
static char * F_35 ( const char * V_53 , const char * V_54 )
{
char * V_55 ;
if ( strlen ( V_54 ) == 0 )
V_55 = F_36 ( V_56 | V_57 , L_3 , V_53 ) ;
else
V_55 = F_36 ( V_56 | V_57 , L_4 , V_53 , V_54 ) ;
return ( ! V_55 ) ? F_11 ( - V_58 ) : V_55 ;
}
static char * * F_37 ( char * V_50 , unsigned int V_16 , unsigned int * V_51 )
{
char * V_52 , * * V_34 ;
* V_51 = F_34 ( V_50 , V_16 ) ;
V_34 = F_38 ( * V_51 * sizeof( char * ) + V_16 , V_56 | V_57 ) ;
if ( ! V_34 ) {
F_14 ( V_50 ) ;
return F_11 ( - V_58 ) ;
}
memcpy ( & V_34 [ * V_51 ] , V_50 , V_16 ) ;
F_14 ( V_50 ) ;
V_50 = ( char * ) & V_34 [ * V_51 ] ;
for ( V_52 = V_50 , * V_51 = 0 ; V_52 < V_50 + V_16 ; V_52 += strlen ( V_52 ) + 1 )
V_34 [ ( * V_51 ) ++ ] = V_52 ;
return V_34 ;
}
char * * F_39 ( struct V_40 V_41 ,
const char * V_53 , const char * V_59 , unsigned int * V_51 )
{
char * V_50 , * V_60 ;
unsigned int V_16 ;
V_60 = F_35 ( V_53 , V_59 ) ;
if ( F_29 ( V_60 ) )
return ( char * * ) V_60 ;
V_50 = F_31 ( V_41 , V_61 , V_60 , & V_16 ) ;
F_14 ( V_60 ) ;
if ( F_29 ( V_50 ) )
return ( char * * ) V_50 ;
return F_37 ( V_50 , V_16 , V_51 ) ;
}
int F_40 ( struct V_40 V_41 ,
const char * V_53 , const char * V_59 )
{
char * * V_62 ;
int V_63 ;
V_62 = F_39 ( V_41 , V_53 , V_59 , & V_63 ) ;
if ( F_29 ( V_62 ) )
return 0 ;
F_14 ( V_62 ) ;
return 1 ;
}
void * F_41 ( struct V_40 V_41 ,
const char * V_53 , const char * V_59 , unsigned int * V_16 )
{
char * V_60 ;
void * V_34 ;
V_60 = F_35 ( V_53 , V_59 ) ;
if ( F_29 ( V_60 ) )
return ( void * ) V_60 ;
V_34 = F_31 ( V_41 , V_64 , V_60 , V_16 ) ;
F_14 ( V_60 ) ;
return V_34 ;
}
int F_42 ( struct V_40 V_41 ,
const char * V_53 , const char * V_59 , const char * string )
{
const char * V_60 ;
struct V_42 V_43 [ 2 ] ;
int V_34 ;
V_60 = F_35 ( V_53 , V_59 ) ;
if ( F_29 ( V_60 ) )
return F_33 ( V_60 ) ;
V_43 [ 0 ] . V_49 = ( void * ) V_60 ;
V_43 [ 0 ] . V_48 = strlen ( V_60 ) + 1 ;
V_43 [ 1 ] . V_49 = ( void * ) string ;
V_43 [ 1 ] . V_48 = strlen ( string ) ;
V_34 = F_32 ( F_28 ( V_41 , V_65 , V_43 , F_2 ( V_43 ) , NULL ) ) ;
F_14 ( V_60 ) ;
return V_34 ;
}
int F_43 ( struct V_40 V_41 ,
const char * V_53 , const char * V_59 )
{
char * V_60 ;
int V_34 ;
V_60 = F_35 ( V_53 , V_59 ) ;
if ( F_29 ( V_60 ) )
return F_33 ( V_60 ) ;
V_34 = F_32 ( F_31 ( V_41 , V_66 , V_60 , NULL ) ) ;
F_14 ( V_60 ) ;
return V_34 ;
}
int F_44 ( struct V_40 V_41 , const char * V_53 , const char * V_59 )
{
char * V_60 ;
int V_34 ;
V_60 = F_35 ( V_53 , V_59 ) ;
if ( F_29 ( V_60 ) )
return F_33 ( V_60 ) ;
V_34 = F_32 ( F_31 ( V_41 , V_67 , V_60 , NULL ) ) ;
F_14 ( V_60 ) ;
return V_34 ;
}
int F_45 ( struct V_40 * V_41 )
{
char * V_68 ;
F_15 () ;
V_68 = F_31 ( V_69 , V_36 , L_5 , NULL ) ;
if ( F_29 ( V_68 ) ) {
F_19 () ;
return F_33 ( V_68 ) ;
}
V_41 -> V_46 = F_46 ( V_68 , NULL , 0 ) ;
F_14 ( V_68 ) ;
return 0 ;
}
int F_47 ( struct V_40 V_41 , int abort )
{
char V_70 [ 2 ] ;
int V_35 ;
if ( abort )
strcpy ( V_70 , L_6 ) ;
else
strcpy ( V_70 , L_7 ) ;
V_35 = F_32 ( F_31 ( V_41 , V_39 , V_70 , NULL ) ) ;
F_19 () ;
return V_35 ;
}
int F_48 ( struct V_40 V_41 ,
const char * V_53 , const char * V_59 , const char * V_71 , ... )
{
T_1 V_72 ;
int V_34 ;
char * V_73 ;
V_73 = F_41 ( V_41 , V_53 , V_59 , NULL ) ;
if ( F_29 ( V_73 ) )
return F_33 ( V_73 ) ;
va_start ( V_72 , V_71 ) ;
V_34 = vsscanf ( V_73 , V_71 , V_72 ) ;
va_end ( V_72 ) ;
F_14 ( V_73 ) ;
if ( V_34 == 0 )
return - V_74 ;
return V_34 ;
}
int F_49 ( struct V_40 V_41 ,
const char * V_53 , const char * V_59 , const char * V_71 , ... )
{
T_1 V_72 ;
int V_34 ;
char * V_75 ;
va_start ( V_72 , V_71 ) ;
V_75 = F_50 ( V_56 | V_57 , V_71 , V_72 ) ;
va_end ( V_72 ) ;
if ( ! V_75 )
return - V_58 ;
V_34 = F_42 ( V_41 , V_53 , V_59 , V_75 ) ;
F_14 ( V_75 ) ;
return V_34 ;
}
int F_51 ( struct V_40 V_41 , const char * V_53 , ... )
{
T_1 V_72 ;
const char * V_54 ;
int V_34 = 0 ;
va_start ( V_72 , V_53 ) ;
while ( V_34 == 0 && ( V_54 = va_arg ( V_72 , char * ) ) != NULL ) {
const char * V_71 = va_arg ( V_72 , char * ) ;
void * V_76 = va_arg ( V_72 , void * ) ;
char * V_52 ;
V_52 = F_41 ( V_41 , V_53 , V_54 , NULL ) ;
if ( F_29 ( V_52 ) ) {
V_34 = F_33 ( V_52 ) ;
break;
}
if ( V_71 ) {
if ( sscanf ( V_52 , V_71 , V_76 ) == 0 )
V_34 = - V_5 ;
F_14 ( V_52 ) ;
} else
* ( char * * ) V_76 = V_52 ;
}
va_end ( V_72 ) ;
return V_34 ;
}
static int F_52 ( const char * V_60 , const char * V_77 )
{
struct V_42 V_78 [ 2 ] ;
V_78 [ 0 ] . V_49 = ( void * ) V_60 ;
V_78 [ 0 ] . V_48 = strlen ( V_60 ) + 1 ;
V_78 [ 1 ] . V_49 = ( void * ) V_77 ;
V_78 [ 1 ] . V_48 = strlen ( V_77 ) + 1 ;
return F_32 ( F_28 ( V_69 , V_79 , V_78 ,
F_2 ( V_78 ) , NULL ) ) ;
}
static int F_53 ( const char * V_60 , const char * V_77 )
{
struct V_42 V_78 [ 2 ] ;
V_78 [ 0 ] . V_49 = ( char * ) V_60 ;
V_78 [ 0 ] . V_48 = strlen ( V_60 ) + 1 ;
V_78 [ 1 ] . V_49 = ( char * ) V_77 ;
V_78 [ 1 ] . V_48 = strlen ( V_77 ) + 1 ;
return F_32 ( F_28 ( V_69 , V_80 , V_78 ,
F_2 ( V_78 ) , NULL ) ) ;
}
static struct V_81 * F_54 ( const char * V_77 )
{
struct V_81 * V_2 , * V_82 ;
V_82 = ( void * ) F_46 ( V_77 , NULL , 16 ) ;
F_55 (i, &watches, list)
if ( V_2 == V_82 )
return V_2 ;
return NULL ;
}
static bool F_56 ( void )
{
#ifdef F_57
T_2 V_83 , V_84 , V_85 , V_86 , V_87 ;
V_87 = F_58 () ;
F_59 ( V_87 + 1 , & V_83 , & V_84 , & V_85 , & V_86 ) ;
if ( ( V_83 >> 16 ) < 4 )
return true ;
#endif
return false ;
}
static void F_60 ( void )
{
int V_35 , V_88 = 0 ;
if ( ! F_61 () || F_62 () )
return;
if ( F_56 () )
return;
V_35 = F_48 ( V_69 , L_8 ,
L_9 , L_10 , & V_88 ) ;
if ( V_35 != 1 || ! V_88 )
return;
V_35 = F_32 ( F_31 ( V_69 , V_89 , L_5 , NULL ) ) ;
if ( V_35 && V_35 != - V_90 )
F_3 ( L_11 , V_35 ) ;
}
int F_63 ( struct V_81 * V_91 )
{
char V_77 [ sizeof( V_91 ) * 2 + 1 ] ;
int V_35 ;
sprintf ( V_77 , L_12 , ( long ) V_91 ) ;
F_64 ( & V_20 . V_92 ) ;
F_6 ( & V_93 ) ;
F_65 ( F_54 ( V_77 ) ) ;
F_66 ( & V_91 -> V_26 , & V_94 ) ;
F_8 ( & V_93 ) ;
V_35 = F_52 ( V_91 -> V_59 , V_77 ) ;
if ( V_35 ) {
F_6 ( & V_93 ) ;
F_13 ( & V_91 -> V_26 ) ;
F_8 ( & V_93 ) ;
}
F_67 ( & V_20 . V_92 ) ;
return V_35 ;
}
void F_68 ( struct V_81 * V_91 )
{
struct V_17 * V_18 , * V_95 ;
char V_77 [ sizeof( V_91 ) * 2 + 1 ] ;
int V_35 ;
sprintf ( V_77 , L_12 , ( long ) V_91 ) ;
F_64 ( & V_20 . V_92 ) ;
F_6 ( & V_93 ) ;
F_65 ( ! F_54 ( V_77 ) ) ;
F_13 ( & V_91 -> V_26 ) ;
F_8 ( & V_93 ) ;
V_35 = F_53 ( V_91 -> V_59 , V_77 ) ;
if ( V_35 )
F_3 ( L_13 , V_91 -> V_59 , V_35 ) ;
F_67 ( & V_20 . V_92 ) ;
if ( V_96 -> V_97 != V_98 )
F_16 ( & V_99 ) ;
F_6 ( & V_100 ) ;
F_69 (msg, tmp, &watch_events, list) {
if ( V_18 -> V_28 . V_91 . V_101 != V_91 )
continue;
F_13 ( & V_18 -> V_26 ) ;
F_14 ( V_18 -> V_28 . V_91 . V_102 ) ;
F_14 ( V_18 ) ;
}
F_8 ( & V_100 ) ;
if ( V_96 -> V_97 != V_98 )
F_18 ( & V_99 ) ;
}
void F_70 ( void )
{
F_22 () ;
F_71 ( & V_20 . V_92 ) ;
F_16 ( & V_20 . V_37 ) ;
F_16 ( & V_20 . V_103 ) ;
}
void F_72 ( void )
{
struct V_81 * V_91 ;
char V_77 [ sizeof( V_91 ) * 2 + 1 ] ;
F_73 () ;
F_18 ( & V_20 . V_103 ) ;
F_18 ( & V_20 . V_37 ) ;
F_25 () ;
F_55 (watch, &watches, list) {
sprintf ( V_77 , L_12 , ( long ) V_91 ) ;
F_52 ( V_91 -> V_59 , V_77 ) ;
}
F_74 ( & V_20 . V_92 ) ;
}
void F_75 ( void )
{
F_18 ( & V_20 . V_103 ) ;
F_18 ( & V_20 . V_37 ) ;
F_74 ( & V_20 . V_92 ) ;
F_18 ( & V_20 . V_30 ) ;
}
static int F_76 ( void * V_104 )
{
struct V_105 * V_106 ;
struct V_17 * V_18 ;
for (; ; ) {
F_77 ( V_107 ,
! F_7 ( & V_108 ) ) ;
if ( F_78 () )
break;
F_16 ( & V_99 ) ;
F_6 ( & V_100 ) ;
V_106 = V_108 . V_25 ;
if ( V_106 != & V_108 )
F_13 ( V_106 ) ;
F_8 ( & V_100 ) ;
if ( V_106 != & V_108 ) {
V_18 = F_12 ( V_106 , struct V_17 , V_26 ) ;
V_18 -> V_28 . V_91 . V_101 -> V_109 (
V_18 -> V_28 . V_91 . V_101 ,
( const char * * ) V_18 -> V_28 . V_91 . V_102 ,
V_18 -> V_28 . V_91 . V_110 ) ;
F_14 ( V_18 -> V_28 . V_91 . V_102 ) ;
F_14 ( V_18 ) ;
}
F_18 ( & V_99 ) ;
}
return 0 ;
}
static int F_79 ( void )
{
struct V_17 * V_18 ;
char * V_19 ;
int V_35 ;
for (; ; ) {
V_35 = F_80 () ;
if ( V_35 )
return V_35 ;
F_16 ( & V_20 . V_103 ) ;
if ( F_81 () )
break;
F_18 ( & V_20 . V_103 ) ;
}
V_18 = F_38 ( sizeof( * V_18 ) , V_56 | V_57 ) ;
if ( V_18 == NULL ) {
V_35 = - V_58 ;
goto V_111;
}
V_35 = F_82 ( & V_18 -> V_27 , sizeof( V_18 -> V_27 ) ) ;
if ( V_35 ) {
F_14 ( V_18 ) ;
goto V_111;
}
if ( V_18 -> V_27 . V_16 > V_112 ) {
F_14 ( V_18 ) ;
V_35 = - V_5 ;
goto V_111;
}
V_19 = F_38 ( V_18 -> V_27 . V_16 + 1 , V_56 | V_57 ) ;
if ( V_19 == NULL ) {
F_14 ( V_18 ) ;
V_35 = - V_58 ;
goto V_111;
}
V_35 = F_82 ( V_19 , V_18 -> V_27 . V_16 ) ;
if ( V_35 ) {
F_14 ( V_19 ) ;
F_14 ( V_18 ) ;
goto V_111;
}
V_19 [ V_18 -> V_27 . V_16 ] = '\0' ;
if ( V_18 -> V_27 . type == V_113 ) {
V_18 -> V_28 . V_91 . V_102 = F_37 ( V_19 , V_18 -> V_27 . V_16 ,
& V_18 -> V_28 . V_91 . V_110 ) ;
if ( F_29 ( V_18 -> V_28 . V_91 . V_102 ) ) {
V_35 = F_33 ( V_18 -> V_28 . V_91 . V_102 ) ;
F_14 ( V_18 ) ;
goto V_111;
}
F_6 ( & V_93 ) ;
V_18 -> V_28 . V_91 . V_101 = F_54 (
V_18 -> V_28 . V_91 . V_102 [ V_114 ] ) ;
if ( V_18 -> V_28 . V_91 . V_101 != NULL ) {
F_6 ( & V_100 ) ;
F_83 ( & V_18 -> V_26 , & V_108 ) ;
F_21 ( & V_107 ) ;
F_8 ( & V_100 ) ;
} else {
F_14 ( V_18 -> V_28 . V_91 . V_102 ) ;
F_14 ( V_18 ) ;
}
F_8 ( & V_93 ) ;
} else {
V_18 -> V_28 . V_29 . V_19 = V_19 ;
F_6 ( & V_20 . V_21 ) ;
F_83 ( & V_18 -> V_26 , & V_20 . V_22 ) ;
F_8 ( & V_20 . V_21 ) ;
F_21 ( & V_20 . V_23 ) ;
}
V_111:
F_18 ( & V_20 . V_103 ) ;
return V_35 ;
}
static int F_84 ( void * V_104 )
{
int V_35 ;
for (; ; ) {
V_35 = F_79 () ;
if ( V_35 )
F_3 ( L_14 , V_35 ) ;
if ( F_78 () )
break;
}
return 0 ;
}
int F_85 ( void )
{
int V_35 ;
struct V_115 * V_116 ;
F_86 ( & V_20 . V_22 ) ;
F_87 ( & V_20 . V_21 ) ;
F_88 ( & V_20 . V_23 ) ;
F_89 ( & V_20 . V_37 ) ;
F_89 ( & V_20 . V_103 ) ;
F_89 ( & V_20 . V_30 ) ;
F_90 ( & V_20 . V_92 ) ;
F_91 ( & V_20 . V_31 , 0 ) ;
F_88 ( & V_20 . V_32 ) ;
V_35 = F_73 () ;
if ( V_35 )
return V_35 ;
V_116 = F_92 ( F_76 , NULL , L_15 ) ;
if ( F_29 ( V_116 ) )
return F_33 ( V_116 ) ;
V_98 = V_116 -> V_97 ;
V_116 = F_92 ( F_84 , NULL , L_16 ) ;
if ( F_29 ( V_116 ) )
return F_33 ( V_116 ) ;
F_60 () ;
return 0 ;
}
