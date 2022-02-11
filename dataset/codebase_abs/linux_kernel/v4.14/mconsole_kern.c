static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
return F_2 () ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
while ( ! F_4 ( & V_10 ) ) {
F_5 ( V_9 ) ;
V_8 = F_6 ( V_10 . V_11 , struct V_7 , V_12 ) ;
F_7 ( & V_8 -> V_12 ) ;
F_8 ( V_9 ) ;
V_8 -> V_13 . V_14 -> V_15 ( & V_8 -> V_13 ) ;
F_9 ( V_8 ) ;
}
}
static T_1 F_10 ( int V_16 , void * V_17 )
{
long V_18 ;
struct V_7 * V_19 ;
static struct V_20 V_8 ;
V_18 = ( long ) V_17 ;
while ( F_11 ( V_18 , & V_8 ) ) {
if ( V_8 . V_14 -> V_21 == V_22 )
(* V_8 . V_14 -> V_15 )( & V_8 ) ;
else {
V_19 = F_12 ( sizeof( * V_19 ) , V_23 ) ;
if ( V_19 == NULL )
F_13 ( & V_8 , L_1 , 1 , 0 ) ;
else {
V_19 -> V_13 = V_8 ;
V_19 -> V_13 . V_24 = F_14 () -> V_24 ;
F_15 ( & V_19 -> V_12 , & V_10 ) ;
}
}
}
if ( ! F_4 ( & V_10 ) )
F_16 ( & V_25 ) ;
F_17 ( V_18 , V_26 ) ;
return V_27 ;
}
void F_18 ( struct V_20 * V_8 )
{
char V_28 [ 256 ] ;
sprintf ( V_28 , L_2 , F_19 () -> V_29 ,
F_19 () -> V_30 , F_19 () -> V_31 , F_19 () -> V_28 ,
F_19 () -> V_32 ) ;
F_13 ( V_8 , V_28 , 0 , 0 ) ;
}
void F_20 ( struct V_20 * V_8 )
{
int V_33 ;
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_3 ) ;
V_33 = V_8 -> V_33 - ( V_34 - V_8 -> V_13 . V_4 ) ;
F_21 ( V_35 L_4 , V_33 , V_34 ) ;
F_13 ( V_8 , L_5 , 0 , 0 ) ;
}
void F_22 ( struct V_20 * V_8 )
{
struct V_36 * V_37 = F_23 ( V_38 ) -> V_39 ;
char * V_40 ;
int V_33 ;
struct V_41 * V_41 ;
int V_42 = 1 ;
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_6 ) ;
V_34 = F_24 ( V_34 ) ;
V_41 = F_25 ( V_37 -> V_43 , V_37 , V_34 , V_44 , 0 ) ;
if ( F_26 ( V_41 ) ) {
F_13 ( V_8 , L_7 , 1 , 0 ) ;
F_21 ( V_45 L_8 , V_34 , F_27 ( V_41 ) ) ;
goto V_46;
}
V_40 = F_12 ( V_47 , V_48 ) ;
if ( V_40 == NULL ) {
F_13 ( V_8 , L_9 , 1 , 0 ) ;
goto V_49;
}
do {
V_33 = F_28 ( V_41 , V_40 , V_47 - 1 , & V_41 -> V_50 ) ;
if ( V_33 < 0 ) {
F_13 ( V_8 , L_10 , 1 , 0 ) ;
goto V_51;
}
if ( V_42 ) {
F_13 ( V_8 , L_11 , 0 , 1 ) ;
V_42 = 0 ;
}
V_40 [ V_33 ] = '\0' ;
F_13 ( V_8 , V_40 , 0 , ( V_33 > 0 ) ) ;
} while ( V_33 > 0 );
V_51:
F_9 ( V_40 ) ;
V_49:
F_29 ( V_41 ) ;
V_46: ;
}
void F_30 ( struct V_20 * V_8 )
{
F_13 ( V_8 , V_52 , 0 , 0 ) ;
}
void F_31 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_32 () ;
}
void F_33 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_34 ( NULL ) ;
}
void F_35 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_36 () ;
}
void F_37 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_12 , 1 , 0 ) ;
}
void F_38 ( struct V_20 * V_8 )
{
F_39 ( V_8 -> V_53 , V_26 ) ;
F_40 ( V_8 -> V_53 , 1 ) ;
F_13 ( V_8 , L_13 , 0 , 0 ) ;
for (; ; ) {
if ( ! F_11 ( V_8 -> V_53 , V_8 ) )
continue;
if ( V_8 -> V_14 -> V_15 == F_37 )
break;
if ( V_8 -> V_14 -> V_15 == F_38 ) {
F_13 ( V_8 , L_14 , 1 , 0 ) ;
continue;
}
if ( V_8 -> V_14 -> V_15 == V_54 ) {
struct V_55 * V_56 ;
V_56 = F_41 ( (struct V_55 * ) & V_8 -> V_24 ) ;
V_54 ( V_8 ) ;
F_41 ( V_56 ) ;
continue;
}
(* V_8 -> V_14 -> V_15 )( V_8 ) ;
}
F_40 ( V_8 -> V_53 , 0 ) ;
F_17 ( V_8 -> V_53 , V_26 ) ;
F_13 ( V_8 , L_5 , 0 , 0 ) ;
}
void F_42 ( struct V_57 * V_19 )
{
F_43 ( & V_58 ) ;
F_44 ( ! F_4 ( & V_19 -> V_12 ) ) ;
F_15 ( & V_19 -> V_12 , & V_59 ) ;
F_45 ( & V_58 ) ;
}
static struct V_57 * F_46 ( char * V_60 )
{
struct V_61 * V_62 ;
struct V_57 * V_63 ;
F_47 (ele, &mconsole_devices) {
V_63 = F_6 ( V_62 , struct V_57 , V_12 ) ;
if ( ! strncmp ( V_60 , V_63 -> V_60 , strlen ( V_63 -> V_60 ) ) )
return V_63 ;
}
return NULL ;
}
static int F_48 ( char * V_64 , char * * V_65 )
{
unsigned long long V_66 ;
int V_67 = - V_68 , V_69 , V_70 ;
char * V_71 ;
if ( V_64 [ 0 ] != '=' ) {
* V_65 = L_15 ;
goto V_46;
}
V_64 ++ ;
if ( V_64 [ 0 ] == '-' )
V_70 = 0 ;
else if ( V_64 [ 0 ] == '+' ) {
V_70 = 1 ;
}
else {
* V_65 = L_16 ;
goto V_46;
}
V_64 ++ ;
V_66 = F_49 ( V_64 , & V_71 ) ;
if ( * V_71 != '\0' ) {
* V_65 = L_17 ;
goto V_46;
}
V_66 /= V_47 ;
F_50 ( & V_72 ) ;
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ ) {
struct V_73 * V_74 ;
void * V_75 ;
if ( V_70 ) {
if ( F_4 ( & V_73 ) )
break;
V_74 = F_6 ( V_73 . V_11 ,
struct V_73 , V_12 ) ;
if ( V_76 > 0 )
V_75 = V_74 -> V_77 [ -- V_76 ] ;
else {
F_7 ( & V_74 -> V_12 ) ;
V_75 = V_74 ;
V_76 = V_78 ;
}
F_51 ( ( unsigned long ) V_75 ) ;
V_79 -- ;
}
else {
struct V_80 * V_80 ;
V_80 = F_52 ( V_81 ) ;
if ( V_80 == NULL )
break;
V_74 = F_53 ( V_80 ) ;
if ( V_76 == V_78 ) {
F_15 ( & V_74 -> V_12 , & V_73 ) ;
V_76 = 0 ;
}
else {
struct V_61 * V_82 = V_73 . V_11 ;
V_75 = V_74 ;
V_74 = F_6 ( V_82 ,
struct V_73 ,
V_12 ) ;
V_67 = F_54 ( V_75 , V_47 ) ;
if ( V_67 ) {
F_21 ( V_45 L_18
L_19 , V_67 ) ;
* V_65 = L_20 ;
goto V_83;
}
V_74 -> V_77 [ V_76 ++ ] = V_75 ;
}
V_79 ++ ;
}
}
V_67 = 0 ;
V_83:
F_55 ( & V_72 ) ;
V_46:
return V_67 ;
}
static int F_56 ( char * V_60 , char * V_64 , int V_84 , char * * V_65 )
{
char V_40 [ sizeof( L_21 ) ] ;
int V_33 = 0 ;
sprintf ( V_40 , L_22 , V_85 ) ;
F_57 ( V_64 , V_84 , V_33 , V_40 , 1 ) ;
return V_33 ;
}
static int F_58 ( char * * V_64 , int * V_86 , int * V_87 )
{
* V_86 = 0 ;
* V_87 = 0 ;
return 0 ;
}
static int F_59 ( int V_88 , char * * V_65 )
{
* V_65 = L_23 ;
return - V_89 ;
}
static int T_2 F_60 ( void )
{
if ( F_61 () )
F_42 ( & V_90 ) ;
else F_21 ( V_45 L_24
L_25 ) ;
return 0 ;
}
static void F_62 ( int (* F_63)( char * , char * , int ,
char * * ) ,
struct V_20 * V_8 , char * V_60 )
{
char V_91 [ V_92 ] , * error , * V_40 ;
int V_88 , V_84 ;
if ( F_63 == NULL ) {
F_13 ( V_8 , L_26 , 1 , 0 ) ;
return;
}
error = NULL ;
V_84 = F_64 ( V_91 ) ;
V_40 = V_91 ;
while ( 1 ) {
V_88 = (* F_63)( V_60 , V_40 , V_84 , & error ) ;
if ( error != NULL ) {
F_13 ( V_8 , error , 1 , 0 ) ;
goto V_46;
}
if ( V_88 <= V_84 ) {
F_13 ( V_8 , V_40 , 0 , 0 ) ;
goto V_46;
}
if ( V_40 != V_91 )
F_9 ( V_40 ) ;
V_84 = V_88 ;
V_40 = F_12 ( V_84 , V_48 ) ;
if ( V_40 == NULL ) {
F_13 ( V_8 , L_9 , 1 , 0 ) ;
return;
}
}
V_46:
if ( V_40 != V_91 )
F_9 ( V_40 ) ;
}
void F_65 ( struct V_20 * V_8 )
{
struct V_57 * V_63 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_60 , * V_93 = L_5 ;
int V_67 ;
V_34 += strlen ( L_27 ) ;
V_34 = F_24 ( V_34 ) ;
V_63 = F_46 ( V_34 ) ;
if ( V_63 == NULL ) {
F_13 ( V_8 , L_28 , 1 , 0 ) ;
return;
}
V_60 = & V_34 [ strlen ( V_63 -> V_60 ) ] ;
V_34 = V_60 ;
while ( ( * V_34 != '=' ) && ( * V_34 != '\0' ) )
V_34 ++ ;
if ( * V_34 == '=' ) {
V_67 = (* V_63 -> V_94 )( V_60 , & V_93 ) ;
F_13 ( V_8 , V_93 , V_67 , 0 ) ;
}
else F_62 ( V_63 -> F_63 , V_8 , V_60 ) ;
}
void F_66 ( struct V_20 * V_8 )
{
struct V_57 * V_63 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_95 = L_5 ;
char error [ 256 ] ;
int V_67 , V_96 , V_97 , V_88 ;
V_34 += strlen ( L_29 ) ;
V_34 = F_24 ( V_34 ) ;
V_63 = F_46 ( V_34 ) ;
if ( V_63 == NULL ) {
F_13 ( V_8 , L_30 , 1 , 0 ) ;
return;
}
V_34 = & V_34 [ strlen ( V_63 -> V_60 ) ] ;
V_67 = 1 ;
V_88 = (* V_63 -> V_98 )( & V_34 , & V_96 , & V_97 ) ;
if ( V_88 < 0 ) {
V_95 = L_31 ;
goto V_46;
}
else if ( ( V_88 < V_96 ) || ( V_88 > V_97 ) ) {
sprintf ( error , L_32
L_33 , V_96 , V_97 ) ;
V_95 = error ;
goto V_46;
}
V_95 = NULL ;
V_67 = (* V_63 -> remove )( V_88 , & V_95 ) ;
switch( V_67 ) {
case 0 :
V_95 = L_5 ;
break;
case - V_99 :
if ( V_95 == NULL )
V_95 = L_34 ;
break;
case - V_89 :
if ( V_95 == NULL )
V_95 = L_35 ;
break;
default:
break;
}
V_46:
F_13 ( V_8 , V_95 , V_67 , 0 ) ;
}
static void F_67 ( struct V_100 * V_100 , const char * string ,
unsigned int V_33 )
{
struct V_61 * V_62 ;
int V_88 ;
if ( F_4 ( & V_101 ) )
return;
while ( V_33 > 0 ) {
V_88 = F_68 ( ( V_102 ) V_33 , F_64 ( V_103 ) ) ;
strncpy ( V_103 , string , V_88 ) ;
string += V_88 ;
V_33 -= V_88 ;
F_47 (ele, &clients) {
struct V_104 * V_82 ;
V_82 = F_6 ( V_62 , struct V_104 , V_12 ) ;
F_69 ( V_82 -> V_8 , V_103 , V_88 , 0 , 1 ) ;
}
}
}
static int F_70 ( void )
{
F_71 ( & V_105 ) ;
return 0 ;
}
static void F_72 ( struct V_20 * V_8 , void (* F_73)( void * ) ,
void * V_106 )
{
struct V_104 V_82 ;
unsigned long V_9 ;
V_82 . V_8 = V_8 ;
F_74 ( & V_107 , V_9 ) ;
F_15 ( & V_82 . V_12 , & V_101 ) ;
F_75 ( & V_107 , V_9 ) ;
(* F_73)( V_106 ) ;
F_69 ( V_8 , L_5 , 0 , 0 , 0 ) ;
F_74 ( & V_107 , V_9 ) ;
F_7 ( & V_82 . V_12 ) ;
F_75 ( & V_107 , V_9 ) ;
}
static void F_76 ( void * V_106 )
{
char * V_108 = V_106 ;
F_77 ( * V_108 ) ;
}
void V_54 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_36 ) ;
V_34 = F_24 ( V_34 ) ;
if ( * V_34 == 'b' )
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_72 ( V_8 , F_76 , V_34 ) ;
}
void V_54 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_37 , 1 , 0 ) ;
}
static void F_78 ( void * V_106 )
{
struct V_109 * V_110 = V_106 ;
F_79 ( V_110 , NULL ) ;
}
void F_80 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
int V_111 = - 1 ;
struct V_109 * V_112 = NULL ;
V_34 += strlen ( L_38 ) ;
V_34 = F_24 ( V_34 ) ;
if ( sscanf ( V_34 , L_39 , & V_111 ) == 0 ) {
F_13 ( V_8 , L_40 , 1 , 0 ) ;
return;
}
V_112 = F_81 ( V_111 , & V_113 ) ;
if ( ( V_112 == NULL ) || ( V_111 == 0 ) ) {
F_13 ( V_8 , L_41 , 1 , 0 ) ;
return;
}
F_72 ( V_8 , F_78 , V_112 ) ;
}
static int T_2 F_82 ( void )
{
long V_114 ;
int V_67 ;
char V_41 [ V_115 ] ;
if ( F_83 ( L_42 , V_41 , sizeof( V_41 ) ) )
return - 1 ;
snprintf ( V_116 , sizeof( V_41 ) , L_43 , V_41 ) ;
V_114 = F_84 ( V_41 , sizeof( V_41 ) , 1 ) ;
if ( V_114 < 0 ) {
F_21 ( V_45 L_44 ) ;
return 1 ;
}
if ( F_40 ( V_114 , 0 ) )
goto V_46;
F_85 ( & V_117 ) ;
V_67 = F_86 ( V_26 , V_114 , V_118 , F_10 ,
V_119 , L_42 , ( void * ) V_114 ) ;
if ( V_67 ) {
F_21 ( V_45 L_45 ) ;
goto V_46;
}
if ( V_120 != NULL ) {
V_120 = F_87 ( V_120 , V_48 ) ;
if ( V_120 != NULL )
F_88 ( V_120 , V_121 ,
V_116 ,
strlen ( V_116 ) + 1 ) ;
else F_21 ( V_45 L_46
L_47 ) ;
}
F_21 ( V_122 L_48 ,
V_123 , V_116 ) ;
return 0 ;
V_46:
F_89 ( V_114 ) ;
return 1 ;
}
static T_3 F_90 ( struct V_41 * V_41 ,
const char T_4 * V_124 , V_102 V_125 , T_5 * V_126 )
{
char * V_40 ;
V_40 = F_91 ( V_124 , V_125 ) ;
if ( F_26 ( V_40 ) )
return F_27 ( V_40 ) ;
F_88 ( V_120 , V_127 , V_40 , V_125 ) ;
F_9 ( V_40 ) ;
return V_125 ;
}
static int F_92 ( void )
{
struct V_128 * V_129 ;
if ( V_120 == NULL )
return 0 ;
V_129 = F_93 ( L_42 , 0200 , NULL , & V_130 ) ;
if ( V_129 == NULL ) {
F_21 ( V_122 L_49 ) ;
return 0 ;
}
return 0 ;
}
void F_94 ( void )
{
F_43 ( & V_131 ) ;
}
void F_95 ( void )
{
F_45 ( & V_131 ) ;
}
static int F_96 ( char * V_64 )
{
if ( ! strncmp ( V_64 , V_132 , strlen ( V_132 ) ) ) {
V_64 += strlen ( V_132 ) ;
V_120 = V_64 ;
}
else F_21 ( V_45 L_50 , V_64 ) ;
return 1 ;
}
static int F_97 ( struct V_1 * V_133 , unsigned long V_134 ,
void * V_34 )
{
char * V_135 = V_34 ;
if ( V_120 == NULL )
return 0 ;
F_88 ( V_120 , V_136 , V_135 ,
strlen ( V_135 ) + 1 ) ;
return 0 ;
}
static int F_98 ( void )
{
F_99 ( & V_137 ,
& V_138 ) ;
return 0 ;
}
char * F_100 ( void )
{
return V_120 ;
}
