static void F_1 ( void )
{
F_2 ( & V_1 ) ;
V_2 ++ ;
F_3 ( & V_1 ) ;
F_4 ( V_3 , V_4 == 0 ) ;
}
static void F_5 ( void )
{
F_2 ( & V_1 ) ;
V_2 -- ;
F_3 ( & V_1 ) ;
F_6 ( & V_5 ) ;
}
static T_1 F_7 ( struct V_6 * V_7 )
{
T_1 V_8 ;
V_7 -> type = V_7 -> V_9 . type ;
F_2 ( & V_1 ) ;
while ( ! V_4 && V_2 ) {
F_3 ( & V_1 ) ;
F_4 ( V_5 , V_2 == 0 ) ;
F_2 ( & V_1 ) ;
}
if ( V_7 -> type == V_10 )
V_4 ++ ;
V_4 ++ ;
V_8 = V_11 ++ ;
F_3 ( & V_1 ) ;
return V_8 ;
}
void F_8 ( struct V_6 * V_7 )
{
F_2 ( & V_1 ) ;
V_4 -- ;
if ( ( V_7 -> type == V_10 && V_7 -> V_9 . type == V_12 ) ||
V_7 -> type == V_13 )
V_4 -- ;
F_3 ( & V_1 ) ;
if ( V_2 && ! V_4 )
F_9 ( & V_3 ) ;
}
static int F_10 ( const char * V_14 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; strcmp ( V_14 , V_16 [ V_15 ] . V_17 ) != 0 ; V_15 ++ ) {
if ( V_15 == F_11 ( V_16 ) - 1 ) {
F_12 ( L_1 ,
V_14 ) ;
return V_18 ;
}
}
return V_16 [ V_15 ] . V_19 ;
}
static bool F_13 ( void )
{
switch ( V_20 ) {
case V_21 :
switch ( V_22 ) {
case V_23 :
case V_24 :
case V_25 :
return false ;
default:
break;
}
return true ;
case V_26 :
case V_27 :
return true ;
default:
break;
}
return false ;
}
static bool F_14 ( struct V_6 * V_7 )
{
if ( V_7 -> V_28 == V_29 || ! F_13 () )
return true ;
F_15 () ;
return false ;
}
static void * F_16 ( struct V_6 * V_7 )
{
while ( V_7 -> V_28 != V_29 ) {
F_4 ( V_7 -> V_30 , F_14 ( V_7 ) ) ;
if ( ! F_13 () )
return F_17 ( - V_31 ) ;
if ( V_7 -> V_32 )
return F_17 ( V_7 -> V_32 ) ;
}
return V_7 -> V_33 ;
}
static void F_18 ( struct V_6 * V_7 , struct V_34 * V_9 )
{
bool V_35 ;
V_7 -> V_9 = * V_9 ;
V_7 -> V_32 = 0 ;
V_7 -> V_28 = V_36 ;
F_19 ( & V_7 -> V_30 ) ;
V_7 -> V_9 . V_37 = F_7 ( V_7 ) ;
F_20 ( & V_38 ) ;
F_21 ( & V_7 -> V_39 , & V_40 ) ;
V_35 = F_22 ( & V_40 ) ;
F_23 ( & V_38 ) ;
if ( V_35 )
F_9 ( & V_41 ) ;
}
static void * F_24 ( struct V_6 * V_7 , struct V_34 * V_9 )
{
void * V_42 ;
V_42 = F_16 ( V_7 ) ;
F_8 ( V_7 ) ;
V_9 -> type = V_7 -> V_9 . type ;
V_9 -> V_43 = V_7 -> V_9 . V_43 ;
F_20 ( & V_38 ) ;
if ( V_7 -> V_28 == V_36 ||
V_7 -> V_28 == V_44 )
V_7 -> V_28 = V_45 ;
else
F_25 ( V_7 ) ;
F_23 ( & V_38 ) ;
return V_42 ;
}
static void F_26 ( struct V_6 * V_7 )
{
F_9 ( & V_7 -> V_30 ) ;
}
int F_27 ( struct V_34 * V_9 , void * V_46 )
{
struct V_6 * V_7 ;
struct V_47 * V_48 ;
V_7 = F_28 ( sizeof( * V_7 ) + sizeof( * V_48 ) , V_49 ) ;
if ( ! V_7 )
return - V_50 ;
V_48 = (struct V_47 * ) ( V_7 + 1 ) ;
V_48 -> V_51 = V_9 -> V_43 ;
V_48 -> V_52 = V_9 + 1 ;
V_7 -> V_48 = V_48 ;
V_7 -> V_53 = 1 ;
V_7 -> V_54 = V_55 ;
V_7 -> V_46 = V_46 ;
F_18 ( V_7 , V_9 ) ;
return 0 ;
}
static void * F_29 ( struct V_56 V_57 ,
enum V_58 type ,
const struct V_47 * V_59 ,
unsigned int V_53 ,
unsigned int * V_43 )
{
struct V_6 * V_7 ;
struct V_34 V_9 ;
void * V_42 = NULL ;
unsigned int V_15 ;
int V_32 ;
V_7 = F_28 ( sizeof( * V_7 ) , V_60 | V_61 ) ;
if ( ! V_7 )
return F_17 ( - V_50 ) ;
V_7 -> V_48 = V_59 ;
V_7 -> V_53 = V_53 ;
V_7 -> V_54 = F_26 ;
V_9 . V_62 = V_57 . V_63 ;
V_9 . type = type ;
V_9 . V_43 = 0 ;
for ( V_15 = 0 ; V_15 < V_53 ; V_15 ++ )
V_9 . V_43 += V_59 [ V_15 ] . V_51 ;
F_18 ( V_7 , & V_9 ) ;
V_42 = F_24 ( V_7 , & V_9 ) ;
if ( V_43 )
* V_43 = V_9 . V_43 ;
if ( F_30 ( V_42 ) )
return V_42 ;
if ( V_9 . type == V_12 ) {
V_32 = F_10 ( V_42 ) ;
F_25 ( V_42 ) ;
return F_17 ( - V_32 ) ;
}
if ( V_9 . type != type ) {
F_31 ( L_2 ,
V_9 . type , type ) ;
F_25 ( V_42 ) ;
return F_17 ( - V_18 ) ;
}
return V_42 ;
}
static void * F_32 ( struct V_56 V_57 ,
enum V_58 type ,
const char * string ,
unsigned int * V_43 )
{
struct V_47 V_59 ;
V_59 . V_52 = ( void * ) string ;
V_59 . V_51 = strlen ( string ) + 1 ;
return F_29 ( V_57 , type , & V_59 , 1 , V_43 ) ;
}
static int F_33 ( char * V_64 )
{
if ( F_30 ( V_64 ) )
return F_34 ( V_64 ) ;
F_25 ( V_64 ) ;
return 0 ;
}
static unsigned int F_35 ( const char * V_65 , unsigned int V_43 )
{
unsigned int V_66 ;
const char * V_67 ;
for ( V_67 = V_65 , V_66 = 0 ; V_67 < V_65 + V_43 ; V_67 += strlen ( V_67 ) + 1 )
V_66 ++ ;
return V_66 ;
}
static char * F_36 ( const char * V_68 , const char * V_69 )
{
char * V_70 ;
if ( strlen ( V_69 ) == 0 )
V_70 = F_37 ( V_60 | V_61 , L_3 , V_68 ) ;
else
V_70 = F_37 ( V_60 | V_61 , L_4 , V_68 , V_69 ) ;
return ( ! V_70 ) ? F_17 ( - V_50 ) : V_70 ;
}
static char * * F_38 ( char * V_65 , unsigned int V_43 , unsigned int * V_66 )
{
char * V_67 , * * V_42 ;
* V_66 = F_35 ( V_65 , V_43 ) ;
V_42 = F_28 ( * V_66 * sizeof( char * ) + V_43 , V_60 | V_61 ) ;
if ( ! V_42 ) {
F_25 ( V_65 ) ;
return F_17 ( - V_50 ) ;
}
memcpy ( & V_42 [ * V_66 ] , V_65 , V_43 ) ;
F_25 ( V_65 ) ;
V_65 = ( char * ) & V_42 [ * V_66 ] ;
for ( V_67 = V_65 , * V_66 = 0 ; V_67 < V_65 + V_43 ; V_67 += strlen ( V_67 ) + 1 )
V_42 [ ( * V_66 ) ++ ] = V_67 ;
return V_42 ;
}
char * * F_39 ( struct V_56 V_57 ,
const char * V_68 , const char * V_71 , unsigned int * V_66 )
{
char * V_65 , * V_72 ;
unsigned int V_43 ;
V_72 = F_36 ( V_68 , V_71 ) ;
if ( F_30 ( V_72 ) )
return ( char * * ) V_72 ;
V_65 = F_32 ( V_57 , V_73 , V_72 , & V_43 ) ;
F_25 ( V_72 ) ;
if ( F_30 ( V_65 ) )
return ( char * * ) V_65 ;
return F_38 ( V_65 , V_43 , V_66 ) ;
}
int F_40 ( struct V_56 V_57 ,
const char * V_68 , const char * V_71 )
{
char * * V_74 ;
int V_75 ;
V_74 = F_39 ( V_57 , V_68 , V_71 , & V_75 ) ;
if ( F_30 ( V_74 ) )
return 0 ;
F_25 ( V_74 ) ;
return 1 ;
}
void * F_41 ( struct V_56 V_57 ,
const char * V_68 , const char * V_71 , unsigned int * V_43 )
{
char * V_72 ;
void * V_42 ;
V_72 = F_36 ( V_68 , V_71 ) ;
if ( F_30 ( V_72 ) )
return ( void * ) V_72 ;
V_42 = F_32 ( V_57 , V_76 , V_72 , V_43 ) ;
F_25 ( V_72 ) ;
return V_42 ;
}
int F_42 ( struct V_56 V_57 ,
const char * V_68 , const char * V_71 , const char * string )
{
const char * V_72 ;
struct V_47 V_59 [ 2 ] ;
int V_42 ;
V_72 = F_36 ( V_68 , V_71 ) ;
if ( F_30 ( V_72 ) )
return F_34 ( V_72 ) ;
V_59 [ 0 ] . V_52 = ( void * ) V_72 ;
V_59 [ 0 ] . V_51 = strlen ( V_72 ) + 1 ;
V_59 [ 1 ] . V_52 = ( void * ) string ;
V_59 [ 1 ] . V_51 = strlen ( string ) ;
V_42 = F_33 ( F_29 ( V_57 , V_77 , V_59 , F_11 ( V_59 ) , NULL ) ) ;
F_25 ( V_72 ) ;
return V_42 ;
}
int F_43 ( struct V_56 V_57 ,
const char * V_68 , const char * V_71 )
{
char * V_72 ;
int V_42 ;
V_72 = F_36 ( V_68 , V_71 ) ;
if ( F_30 ( V_72 ) )
return F_34 ( V_72 ) ;
V_42 = F_33 ( F_32 ( V_57 , V_78 , V_72 , NULL ) ) ;
F_25 ( V_72 ) ;
return V_42 ;
}
int F_44 ( struct V_56 V_57 , const char * V_68 , const char * V_71 )
{
char * V_72 ;
int V_42 ;
V_72 = F_36 ( V_68 , V_71 ) ;
if ( F_30 ( V_72 ) )
return F_34 ( V_72 ) ;
V_42 = F_33 ( F_32 ( V_57 , V_79 , V_72 , NULL ) ) ;
F_25 ( V_72 ) ;
return V_42 ;
}
int F_45 ( struct V_56 * V_57 )
{
char * V_80 ;
V_80 = F_32 ( V_81 , V_10 , L_5 , NULL ) ;
if ( F_30 ( V_80 ) )
return F_34 ( V_80 ) ;
V_57 -> V_63 = F_46 ( V_80 , NULL , 0 ) ;
F_25 ( V_80 ) ;
return 0 ;
}
int F_47 ( struct V_56 V_57 , int abort )
{
char V_82 [ 2 ] ;
if ( abort )
strcpy ( V_82 , L_6 ) ;
else
strcpy ( V_82 , L_7 ) ;
return F_33 ( F_32 ( V_57 , V_13 , V_82 , NULL ) ) ;
}
int F_48 ( struct V_56 V_57 ,
const char * V_68 , const char * V_71 , const char * V_83 , ... )
{
T_2 V_84 ;
int V_42 ;
char * V_85 ;
V_85 = F_41 ( V_57 , V_68 , V_71 , NULL ) ;
if ( F_30 ( V_85 ) )
return F_34 ( V_85 ) ;
va_start ( V_84 , V_83 ) ;
V_42 = vsscanf ( V_85 , V_83 , V_84 ) ;
va_end ( V_84 ) ;
F_25 ( V_85 ) ;
if ( V_42 == 0 )
return - V_86 ;
return V_42 ;
}
unsigned int F_49 ( const char * V_68 , const char * V_71 ,
unsigned int V_87 )
{
unsigned int V_85 ;
int V_42 ;
V_42 = F_48 ( V_81 , V_68 , V_71 , L_8 , & V_85 ) ;
if ( V_42 <= 0 )
V_85 = V_87 ;
return V_85 ;
}
int F_50 ( struct V_56 V_57 ,
const char * V_68 , const char * V_71 , const char * V_83 , ... )
{
T_2 V_84 ;
int V_42 ;
char * V_88 ;
va_start ( V_84 , V_83 ) ;
V_88 = F_51 ( V_60 | V_61 , V_83 , V_84 ) ;
va_end ( V_84 ) ;
if ( ! V_88 )
return - V_50 ;
V_42 = F_42 ( V_57 , V_68 , V_71 , V_88 ) ;
F_25 ( V_88 ) ;
return V_42 ;
}
int F_52 ( struct V_56 V_57 , const char * V_68 , ... )
{
T_2 V_84 ;
const char * V_69 ;
int V_42 = 0 ;
va_start ( V_84 , V_68 ) ;
while ( V_42 == 0 && ( V_69 = va_arg ( V_84 , char * ) ) != NULL ) {
const char * V_83 = va_arg ( V_84 , char * ) ;
void * V_89 = va_arg ( V_84 , void * ) ;
char * V_67 ;
V_67 = F_41 ( V_57 , V_68 , V_69 , NULL ) ;
if ( F_30 ( V_67 ) ) {
V_42 = F_34 ( V_67 ) ;
break;
}
if ( V_83 ) {
if ( sscanf ( V_67 , V_83 , V_89 ) == 0 )
V_42 = - V_18 ;
F_25 ( V_67 ) ;
} else
* ( char * * ) V_89 = V_67 ;
}
va_end ( V_84 ) ;
return V_42 ;
}
static int F_53 ( const char * V_72 , const char * V_90 )
{
struct V_47 V_91 [ 2 ] ;
V_91 [ 0 ] . V_52 = ( void * ) V_72 ;
V_91 [ 0 ] . V_51 = strlen ( V_72 ) + 1 ;
V_91 [ 1 ] . V_52 = ( void * ) V_90 ;
V_91 [ 1 ] . V_51 = strlen ( V_90 ) + 1 ;
return F_33 ( F_29 ( V_81 , V_92 , V_91 ,
F_11 ( V_91 ) , NULL ) ) ;
}
static int F_54 ( const char * V_72 , const char * V_90 )
{
struct V_47 V_91 [ 2 ] ;
V_91 [ 0 ] . V_52 = ( char * ) V_72 ;
V_91 [ 0 ] . V_51 = strlen ( V_72 ) + 1 ;
V_91 [ 1 ] . V_52 = ( char * ) V_90 ;
V_91 [ 1 ] . V_51 = strlen ( V_90 ) + 1 ;
return F_33 ( F_29 ( V_81 , V_93 , V_91 ,
F_11 ( V_91 ) , NULL ) ) ;
}
static struct V_94 * F_55 ( const char * V_90 )
{
struct V_94 * V_15 , * V_95 ;
V_95 = ( void * ) F_46 ( V_90 , NULL , 16 ) ;
F_56 (i, &watches, list)
if ( V_15 == V_95 )
return V_15 ;
return NULL ;
}
int F_57 ( struct V_96 * V_97 )
{
if ( F_35 ( V_97 -> V_33 , V_97 -> V_43 ) != 2 ) {
F_25 ( V_97 ) ;
return - V_18 ;
}
V_97 -> V_72 = ( const char * ) V_97 -> V_33 ;
V_97 -> V_90 = ( const char * ) strchr ( V_97 -> V_33 , '\0' ) + 1 ;
F_2 ( & V_98 ) ;
V_97 -> V_99 = F_55 ( V_97 -> V_90 ) ;
if ( V_97 -> V_99 != NULL ) {
F_2 ( & V_100 ) ;
F_21 ( & V_97 -> V_39 , & V_101 ) ;
F_9 ( & V_102 ) ;
F_3 ( & V_100 ) ;
} else
F_25 ( V_97 ) ;
F_3 ( & V_98 ) ;
return 0 ;
}
static bool F_58 ( void )
{
#ifdef F_59
T_1 V_103 , V_104 , V_105 , V_106 , V_107 ;
V_107 = F_60 () ;
F_61 ( V_107 + 1 , & V_103 , & V_104 , & V_105 , & V_106 ) ;
if ( ( V_103 >> 16 ) < 4 )
return true ;
#endif
return false ;
}
static void F_62 ( void )
{
int V_32 ;
if ( ! F_63 () || F_64 () )
return;
if ( F_58 () )
return;
if ( ! F_49 ( L_9 ,
L_10 , 0 ) )
return;
V_32 = F_33 ( F_32 ( V_81 , V_108 , L_5 , NULL ) ) ;
if ( V_32 && V_32 != - V_109 )
F_12 ( L_11 , V_32 ) ;
}
int F_65 ( struct V_94 * V_110 )
{
char V_90 [ sizeof( V_110 ) * 2 + 1 ] ;
int V_32 ;
sprintf ( V_90 , L_12 , ( long ) V_110 ) ;
F_66 ( & V_111 ) ;
F_2 ( & V_98 ) ;
F_67 ( F_55 ( V_90 ) ) ;
F_68 ( & V_110 -> V_39 , & V_112 ) ;
F_3 ( & V_98 ) ;
V_32 = F_53 ( V_110 -> V_71 , V_90 ) ;
if ( V_32 ) {
F_2 ( & V_98 ) ;
F_69 ( & V_110 -> V_39 ) ;
F_3 ( & V_98 ) ;
}
F_70 ( & V_111 ) ;
return V_32 ;
}
void F_71 ( struct V_94 * V_110 )
{
struct V_96 * V_97 , * V_113 ;
char V_90 [ sizeof( V_110 ) * 2 + 1 ] ;
int V_32 ;
sprintf ( V_90 , L_12 , ( long ) V_110 ) ;
F_66 ( & V_111 ) ;
F_2 ( & V_98 ) ;
F_67 ( ! F_55 ( V_90 ) ) ;
F_69 ( & V_110 -> V_39 ) ;
F_3 ( & V_98 ) ;
V_32 = F_54 ( V_110 -> V_71 , V_90 ) ;
if ( V_32 )
F_12 ( L_13 , V_110 -> V_71 , V_32 ) ;
F_70 ( & V_111 ) ;
if ( V_114 -> V_115 != V_116 )
F_20 ( & V_117 ) ;
F_2 ( & V_100 ) ;
F_72 (event, tmp, &watch_events, list) {
if ( V_97 -> V_99 != V_110 )
continue;
F_69 ( & V_97 -> V_39 ) ;
F_25 ( V_97 ) ;
}
F_3 ( & V_100 ) ;
if ( V_114 -> V_115 != V_116 )
F_23 ( & V_117 ) ;
}
void F_73 ( void )
{
F_1 () ;
F_74 ( & V_111 ) ;
F_20 ( & V_118 ) ;
}
void F_75 ( void )
{
struct V_94 * V_110 ;
char V_90 [ sizeof( V_110 ) * 2 + 1 ] ;
F_76 () ;
F_23 ( & V_118 ) ;
F_5 () ;
F_56 (watch, &watches, list) {
sprintf ( V_90 , L_12 , ( long ) V_110 ) ;
F_53 ( V_110 -> V_71 , V_90 ) ;
}
F_77 ( & V_111 ) ;
}
void F_78 ( void )
{
F_23 ( & V_118 ) ;
F_77 ( & V_111 ) ;
F_5 () ;
}
static int F_79 ( void * V_119 )
{
struct V_120 * V_121 ;
struct V_96 * V_97 ;
V_116 = V_114 -> V_115 ;
for (; ; ) {
F_80 ( V_102 ,
! F_81 ( & V_101 ) ) ;
if ( F_82 () )
break;
F_20 ( & V_117 ) ;
F_2 ( & V_100 ) ;
V_121 = V_101 . V_122 ;
if ( V_121 != & V_101 )
F_69 ( V_121 ) ;
F_3 ( & V_100 ) ;
if ( V_121 != & V_101 ) {
V_97 = F_83 ( V_121 , struct V_96 , V_39 ) ;
V_97 -> V_99 -> V_123 ( V_97 -> V_99 , V_97 -> V_72 ,
V_97 -> V_90 ) ;
F_25 ( V_97 ) ;
}
F_23 ( & V_117 ) ;
}
return 0 ;
}
static int F_84 ( struct V_124 * V_125 ,
unsigned long V_126 , void * V_119 )
{
struct V_6 * V_7 ;
F_20 ( & V_38 ) ;
F_56 (req, &xs_reply_list, list)
F_9 ( & V_7 -> V_30 ) ;
F_56 (req, &xb_write_list, list)
F_9 ( & V_7 -> V_30 ) ;
F_23 ( & V_38 ) ;
return V_127 ;
}
int F_85 ( void )
{
int V_32 ;
struct V_128 * V_129 ;
F_86 ( & V_130 ) ;
V_32 = F_76 () ;
if ( V_32 )
return V_32 ;
V_129 = F_87 ( F_79 , NULL , L_14 ) ;
if ( F_30 ( V_129 ) )
return F_34 ( V_129 ) ;
F_62 () ;
return 0 ;
}
