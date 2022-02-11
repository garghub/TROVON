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
struct V_36 * V_37 = V_38 -> V_39 -> V_40 -> V_41 ;
char * V_42 ;
int V_33 ;
struct V_43 * V_43 ;
int V_44 = 1 ;
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_6 ) ;
V_34 = F_23 ( V_34 ) ;
V_43 = F_24 ( V_37 -> V_45 , V_37 , V_34 , V_46 ) ;
if ( F_25 ( V_43 ) ) {
F_13 ( V_8 , L_7 , 1 , 0 ) ;
F_21 ( V_47 L_8 , V_34 , F_26 ( V_43 ) ) ;
goto V_48;
}
V_42 = F_12 ( V_49 , V_50 ) ;
if ( V_42 == NULL ) {
F_13 ( V_8 , L_9 , 1 , 0 ) ;
goto V_51;
}
do {
T_2 V_52 ;
T_3 V_53 = F_27 () ;
F_28 ( V_54 ) ;
V_33 = F_29 ( V_43 , V_42 , V_49 - 1 , & V_52 ) ;
F_28 ( V_53 ) ;
V_43 -> V_55 = V_52 ;
if ( V_33 < 0 ) {
F_13 ( V_8 , L_10 , 1 , 0 ) ;
goto V_56;
}
if ( V_44 ) {
F_13 ( V_8 , L_11 , 0 , 1 ) ;
V_44 = 0 ;
}
V_42 [ V_33 ] = '\0' ;
F_13 ( V_8 , V_42 , 0 , ( V_33 > 0 ) ) ;
} while ( V_33 > 0 );
V_56:
F_9 ( V_42 ) ;
V_51:
F_30 ( V_43 ) ;
V_48: ;
}
void F_31 ( struct V_20 * V_8 )
{
F_13 ( V_8 , V_57 , 0 , 0 ) ;
}
void F_32 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_33 () ;
}
void F_34 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_35 ( NULL ) ;
}
void F_36 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_37 () ;
}
void F_38 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_12 , 1 , 0 ) ;
}
void F_39 ( struct V_20 * V_8 )
{
F_40 ( V_8 -> V_58 , V_26 ) ;
F_41 ( V_8 -> V_58 , 1 ) ;
F_13 ( V_8 , L_13 , 0 , 0 ) ;
for (; ; ) {
if ( ! F_11 ( V_8 -> V_58 , V_8 ) )
continue;
if ( V_8 -> V_14 -> V_15 == F_38 )
break;
if ( V_8 -> V_14 -> V_15 == F_39 ) {
F_13 ( V_8 , L_14 , 1 , 0 ) ;
continue;
}
if ( V_8 -> V_14 -> V_15 == V_59 ) {
struct V_60 * V_61 ;
V_61 = F_42 ( (struct V_60 * ) & V_8 -> V_24 ) ;
V_59 ( V_8 ) ;
F_42 ( V_61 ) ;
continue;
}
(* V_8 -> V_14 -> V_15 )( V_8 ) ;
}
F_41 ( V_8 -> V_58 , 0 ) ;
F_17 ( V_8 -> V_58 , V_26 ) ;
F_13 ( V_8 , L_5 , 0 , 0 ) ;
}
void F_43 ( struct V_62 * V_19 )
{
F_44 ( & V_63 ) ;
F_45 ( ! F_4 ( & V_19 -> V_12 ) ) ;
F_15 ( & V_19 -> V_12 , & V_64 ) ;
F_46 ( & V_63 ) ;
}
static struct V_62 * F_47 ( char * V_65 )
{
struct V_66 * V_67 ;
struct V_62 * V_68 ;
F_48 (ele, &mconsole_devices) {
V_68 = F_6 ( V_67 , struct V_62 , V_12 ) ;
if ( ! strncmp ( V_65 , V_68 -> V_65 , strlen ( V_68 -> V_65 ) ) )
return V_68 ;
}
return NULL ;
}
static int F_49 ( char * V_69 , char * * V_70 )
{
unsigned long long V_71 ;
int V_72 = - V_73 , V_74 , V_75 ;
char * V_76 ;
if ( V_69 [ 0 ] != '=' ) {
* V_70 = L_15 ;
goto V_48;
}
V_69 ++ ;
if ( V_69 [ 0 ] == '-' )
V_75 = 0 ;
else if ( V_69 [ 0 ] == '+' ) {
V_75 = 1 ;
}
else {
* V_70 = L_16 ;
goto V_48;
}
V_69 ++ ;
V_71 = F_50 ( V_69 , & V_76 ) ;
if ( * V_76 != '\0' ) {
* V_70 = L_17 ;
goto V_48;
}
V_71 /= V_49 ;
F_51 ( & V_77 ) ;
for ( V_74 = 0 ; V_74 < V_71 ; V_74 ++ ) {
struct V_78 * V_79 ;
void * V_80 ;
if ( V_75 ) {
if ( F_4 ( & V_78 ) )
break;
V_79 = F_6 ( V_78 . V_11 ,
struct V_78 , V_12 ) ;
if ( V_81 > 0 )
V_80 = V_79 -> V_82 [ -- V_81 ] ;
else {
F_7 ( & V_79 -> V_12 ) ;
V_80 = V_79 ;
V_81 = V_83 ;
}
F_52 ( ( unsigned long ) V_80 ) ;
V_84 -- ;
}
else {
struct V_85 * V_85 ;
V_85 = F_53 ( V_86 ) ;
if ( V_85 == NULL )
break;
V_79 = F_54 ( V_85 ) ;
if ( V_81 == V_83 ) {
F_15 ( & V_79 -> V_12 , & V_78 ) ;
V_81 = 0 ;
}
else {
struct V_66 * V_87 = V_78 . V_11 ;
V_80 = V_79 ;
V_79 = F_6 ( V_87 ,
struct V_78 ,
V_12 ) ;
V_72 = F_55 ( V_80 , V_49 ) ;
if ( V_72 ) {
F_21 ( V_47 L_18
L_19 , V_72 ) ;
* V_70 = L_20 ;
goto V_88;
}
V_79 -> V_82 [ V_81 ++ ] = V_80 ;
}
V_84 ++ ;
}
}
V_72 = 0 ;
V_88:
F_56 ( & V_77 ) ;
V_48:
return V_72 ;
}
static int F_57 ( char * V_65 , char * V_69 , int V_89 , char * * V_70 )
{
char V_42 [ sizeof( L_21 ) ] ;
int V_33 = 0 ;
sprintf ( V_42 , L_22 , V_90 ) ;
F_58 ( V_69 , V_89 , V_33 , V_42 , 1 ) ;
return V_33 ;
}
static int F_59 ( char * * V_69 , int * V_91 , int * V_92 )
{
* V_91 = 0 ;
* V_92 = 0 ;
return 0 ;
}
static int F_60 ( int V_93 , char * * V_70 )
{
* V_70 = L_23 ;
return - V_94 ;
}
static int T_4 F_61 ( void )
{
if ( F_62 () )
F_43 ( & V_95 ) ;
else F_21 ( V_47 L_24
L_25 ) ;
return 0 ;
}
static void F_63 ( int (* F_64)( char * , char * , int ,
char * * ) ,
struct V_20 * V_8 , char * V_65 )
{
char V_96 [ V_97 ] , * error , * V_42 ;
int V_93 , V_89 ;
if ( F_64 == NULL ) {
F_13 ( V_8 , L_26 , 1 , 0 ) ;
return;
}
error = NULL ;
V_89 = F_65 ( V_96 ) ;
V_42 = V_96 ;
while ( 1 ) {
V_93 = (* F_64)( V_65 , V_42 , V_89 , & error ) ;
if ( error != NULL ) {
F_13 ( V_8 , error , 1 , 0 ) ;
goto V_48;
}
if ( V_93 <= V_89 ) {
F_13 ( V_8 , V_42 , 0 , 0 ) ;
goto V_48;
}
if ( V_42 != V_96 )
F_9 ( V_42 ) ;
V_89 = V_93 ;
V_42 = F_12 ( V_89 , V_50 ) ;
if ( V_42 == NULL ) {
F_13 ( V_8 , L_9 , 1 , 0 ) ;
return;
}
}
V_48:
if ( V_42 != V_96 )
F_9 ( V_42 ) ;
}
void F_66 ( struct V_20 * V_8 )
{
struct V_62 * V_68 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_65 , * V_98 = L_5 ;
int V_72 ;
V_34 += strlen ( L_27 ) ;
V_34 = F_23 ( V_34 ) ;
V_68 = F_47 ( V_34 ) ;
if ( V_68 == NULL ) {
F_13 ( V_8 , L_28 , 1 , 0 ) ;
return;
}
V_65 = & V_34 [ strlen ( V_68 -> V_65 ) ] ;
V_34 = V_65 ;
while ( ( * V_34 != '=' ) && ( * V_34 != '\0' ) )
V_34 ++ ;
if ( * V_34 == '=' ) {
V_72 = (* V_68 -> V_99 )( V_65 , & V_98 ) ;
F_13 ( V_8 , V_98 , V_72 , 0 ) ;
}
else F_63 ( V_68 -> F_64 , V_8 , V_65 ) ;
}
void F_67 ( struct V_20 * V_8 )
{
struct V_62 * V_68 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_100 = L_5 ;
char error [ 256 ] ;
int V_72 , V_101 , V_102 , V_93 ;
V_34 += strlen ( L_29 ) ;
V_34 = F_23 ( V_34 ) ;
V_68 = F_47 ( V_34 ) ;
if ( V_68 == NULL ) {
F_13 ( V_8 , L_30 , 1 , 0 ) ;
return;
}
V_34 = & V_34 [ strlen ( V_68 -> V_65 ) ] ;
V_72 = 1 ;
V_93 = (* V_68 -> V_103 )( & V_34 , & V_101 , & V_102 ) ;
if ( V_93 < 0 ) {
V_100 = L_31 ;
goto V_48;
}
else if ( ( V_93 < V_101 ) || ( V_93 > V_102 ) ) {
sprintf ( error , L_32
L_33 , V_101 , V_102 ) ;
V_100 = error ;
goto V_48;
}
V_100 = NULL ;
V_72 = (* V_68 -> remove )( V_93 , & V_100 ) ;
switch( V_72 ) {
case 0 :
V_100 = L_5 ;
break;
case - V_104 :
if ( V_100 == NULL )
V_100 = L_34 ;
break;
case - V_94 :
if ( V_100 == NULL )
V_100 = L_35 ;
break;
default:
break;
}
V_48:
F_13 ( V_8 , V_100 , V_72 , 0 ) ;
}
static void F_68 ( struct V_105 * V_105 , const char * string ,
unsigned int V_33 )
{
struct V_66 * V_67 ;
int V_93 ;
if ( F_4 ( & V_106 ) )
return;
while ( V_33 > 0 ) {
V_93 = F_69 ( ( V_107 ) V_33 , F_65 ( V_108 ) ) ;
strncpy ( V_108 , string , V_93 ) ;
string += V_93 ;
V_33 -= V_93 ;
F_48 (ele, &clients) {
struct V_109 * V_87 ;
V_87 = F_6 ( V_67 , struct V_109 , V_12 ) ;
F_70 ( V_87 -> V_8 , V_108 , V_93 , 0 , 1 ) ;
}
}
}
static int F_71 ( void )
{
F_72 ( & V_110 ) ;
return 0 ;
}
static void F_73 ( struct V_20 * V_8 , void (* F_74)( void * ) ,
void * V_111 )
{
struct V_109 V_87 ;
unsigned long V_9 ;
V_87 . V_8 = V_8 ;
F_75 ( & V_112 , V_9 ) ;
F_15 ( & V_87 . V_12 , & V_106 ) ;
F_76 ( & V_112 , V_9 ) ;
(* F_74)( V_111 ) ;
F_70 ( V_8 , L_5 , 0 , 0 , 0 ) ;
F_75 ( & V_112 , V_9 ) ;
F_7 ( & V_87 . V_12 ) ;
F_76 ( & V_112 , V_9 ) ;
}
static void F_77 ( void * V_111 )
{
char * V_113 = V_111 ;
F_78 ( * V_113 ) ;
}
void V_59 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_36 ) ;
V_34 = F_23 ( V_34 ) ;
if ( * V_34 == 'b' )
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_73 ( V_8 , F_77 , V_34 ) ;
}
void V_59 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_37 , 1 , 0 ) ;
}
static void F_79 ( void * V_111 )
{
struct V_114 * V_115 = V_38 , * V_116 = V_111 ;
V_116 -> V_117 . V_118 = V_115 ;
F_80 ( V_115 , V_116 ) ;
F_81 ( V_115 , V_116 , V_115 ) ;
}
void F_82 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
int V_119 = - 1 ;
struct V_114 * V_116 = NULL ;
V_34 += strlen ( L_38 ) ;
V_34 = F_23 ( V_34 ) ;
if ( sscanf ( V_34 , L_39 , & V_119 ) == 0 ) {
F_13 ( V_8 , L_40 , 1 , 0 ) ;
return;
}
V_116 = F_83 ( V_119 , & V_120 ) ;
if ( ( V_116 == NULL ) || ( V_119 == 0 ) ) {
F_13 ( V_8 , L_41 , 1 , 0 ) ;
return;
}
F_73 ( V_8 , F_79 , V_116 ) ;
}
static int T_4 F_84 ( void )
{
long V_121 ;
int V_72 ;
char V_43 [ V_122 ] ;
if ( F_85 ( L_42 , V_43 , sizeof( V_43 ) ) )
return - 1 ;
snprintf ( V_123 , sizeof( V_43 ) , L_43 , V_43 ) ;
V_121 = F_86 ( V_43 , sizeof( V_43 ) , 1 ) ;
if ( V_121 < 0 ) {
F_21 ( V_47 L_44 ) ;
return 1 ;
}
if ( F_41 ( V_121 , 0 ) )
goto V_48;
F_87 ( & V_124 ) ;
V_72 = F_88 ( V_26 , V_121 , V_125 , F_10 ,
V_126 , L_42 , ( void * ) V_121 ) ;
if ( V_72 ) {
F_21 ( V_47 L_45 ) ;
goto V_48;
}
if ( V_127 != NULL ) {
V_127 = F_89 ( V_127 , V_50 ) ;
if ( V_127 != NULL )
F_90 ( V_127 , V_128 ,
V_123 ,
strlen ( V_123 ) + 1 ) ;
else F_21 ( V_47 L_46
L_47 ) ;
}
F_21 ( V_129 L_48 ,
V_130 , V_123 ) ;
return 0 ;
V_48:
F_91 ( V_121 ) ;
return 1 ;
}
static T_5 F_92 ( struct V_43 * V_43 ,
const char T_6 * V_131 , V_107 V_132 , T_2 * V_52 )
{
char * V_42 ;
V_42 = F_12 ( V_132 + 1 , V_50 ) ;
if ( V_42 == NULL )
return - V_133 ;
if ( F_93 ( V_42 , V_131 , V_132 ) ) {
V_132 = - V_134 ;
goto V_48;
}
V_42 [ V_132 ] = '\0' ;
F_90 ( V_127 , V_135 , V_42 , V_132 ) ;
V_48:
F_9 ( V_42 ) ;
return V_132 ;
}
static int F_94 ( void )
{
struct V_136 * V_137 ;
if ( V_127 == NULL )
return 0 ;
V_137 = F_95 ( L_42 , 0200 , NULL , & V_138 ) ;
if ( V_137 == NULL ) {
F_21 ( V_129 L_49
L_50 ) ;
return 0 ;
}
return 0 ;
}
void F_96 ( void )
{
F_44 ( & V_139 ) ;
}
void F_97 ( void )
{
F_46 ( & V_139 ) ;
}
static int F_98 ( char * V_69 )
{
if ( ! strncmp ( V_69 , V_140 , strlen ( V_140 ) ) ) {
V_69 += strlen ( V_140 ) ;
V_127 = V_69 ;
}
else F_21 ( V_47 L_51 , V_69 ) ;
return 1 ;
}
static int F_99 ( struct V_1 * V_141 , unsigned long V_142 ,
void * V_34 )
{
char * V_143 = V_34 ;
if ( V_127 == NULL )
return 0 ;
F_90 ( V_127 , V_144 , V_143 ,
strlen ( V_143 ) + 1 ) ;
return 0 ;
}
static int F_100 ( void )
{
F_101 ( & V_145 ,
& V_146 ) ;
return 0 ;
}
char * F_102 ( void )
{
return V_127 ;
}
