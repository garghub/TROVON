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
V_41 = F_25 ( V_37 -> V_43 , V_37 , V_34 , V_44 ) ;
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
T_2 V_50 ;
T_3 V_51 = F_28 () ;
F_29 ( V_52 ) ;
V_33 = F_30 ( V_41 , V_40 , V_47 - 1 , & V_50 ) ;
F_29 ( V_51 ) ;
V_41 -> V_53 = V_50 ;
if ( V_33 < 0 ) {
F_13 ( V_8 , L_10 , 1 , 0 ) ;
goto V_54;
}
if ( V_42 ) {
F_13 ( V_8 , L_11 , 0 , 1 ) ;
V_42 = 0 ;
}
V_40 [ V_33 ] = '\0' ;
F_13 ( V_8 , V_40 , 0 , ( V_33 > 0 ) ) ;
} while ( V_33 > 0 );
V_54:
F_9 ( V_40 ) ;
V_49:
F_31 ( V_41 ) ;
V_46: ;
}
void F_32 ( struct V_20 * V_8 )
{
F_13 ( V_8 , V_55 , 0 , 0 ) ;
}
void F_33 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_34 () ;
}
void F_35 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_36 ( NULL ) ;
}
void F_37 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_38 () ;
}
void F_39 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_12 , 1 , 0 ) ;
}
void F_40 ( struct V_20 * V_8 )
{
F_41 ( V_8 -> V_56 , V_26 ) ;
F_42 ( V_8 -> V_56 , 1 ) ;
F_13 ( V_8 , L_13 , 0 , 0 ) ;
for (; ; ) {
if ( ! F_11 ( V_8 -> V_56 , V_8 ) )
continue;
if ( V_8 -> V_14 -> V_15 == F_39 )
break;
if ( V_8 -> V_14 -> V_15 == F_40 ) {
F_13 ( V_8 , L_14 , 1 , 0 ) ;
continue;
}
if ( V_8 -> V_14 -> V_15 == V_57 ) {
struct V_58 * V_59 ;
V_59 = F_43 ( (struct V_58 * ) & V_8 -> V_24 ) ;
V_57 ( V_8 ) ;
F_43 ( V_59 ) ;
continue;
}
(* V_8 -> V_14 -> V_15 )( V_8 ) ;
}
F_42 ( V_8 -> V_56 , 0 ) ;
F_17 ( V_8 -> V_56 , V_26 ) ;
F_13 ( V_8 , L_5 , 0 , 0 ) ;
}
void F_44 ( struct V_60 * V_19 )
{
F_45 ( & V_61 ) ;
F_46 ( ! F_4 ( & V_19 -> V_12 ) ) ;
F_15 ( & V_19 -> V_12 , & V_62 ) ;
F_47 ( & V_61 ) ;
}
static struct V_60 * F_48 ( char * V_63 )
{
struct V_64 * V_65 ;
struct V_60 * V_66 ;
F_49 (ele, &mconsole_devices) {
V_66 = F_6 ( V_65 , struct V_60 , V_12 ) ;
if ( ! strncmp ( V_63 , V_66 -> V_63 , strlen ( V_66 -> V_63 ) ) )
return V_66 ;
}
return NULL ;
}
static int F_50 ( char * V_67 , char * * V_68 )
{
unsigned long long V_69 ;
int V_70 = - V_71 , V_72 , V_73 ;
char * V_74 ;
if ( V_67 [ 0 ] != '=' ) {
* V_68 = L_15 ;
goto V_46;
}
V_67 ++ ;
if ( V_67 [ 0 ] == '-' )
V_73 = 0 ;
else if ( V_67 [ 0 ] == '+' ) {
V_73 = 1 ;
}
else {
* V_68 = L_16 ;
goto V_46;
}
V_67 ++ ;
V_69 = F_51 ( V_67 , & V_74 ) ;
if ( * V_74 != '\0' ) {
* V_68 = L_17 ;
goto V_46;
}
V_69 /= V_47 ;
F_52 ( & V_75 ) ;
for ( V_72 = 0 ; V_72 < V_69 ; V_72 ++ ) {
struct V_76 * V_77 ;
void * V_78 ;
if ( V_73 ) {
if ( F_4 ( & V_76 ) )
break;
V_77 = F_6 ( V_76 . V_11 ,
struct V_76 , V_12 ) ;
if ( V_79 > 0 )
V_78 = V_77 -> V_80 [ -- V_79 ] ;
else {
F_7 ( & V_77 -> V_12 ) ;
V_78 = V_77 ;
V_79 = V_81 ;
}
F_53 ( ( unsigned long ) V_78 ) ;
V_82 -- ;
}
else {
struct V_83 * V_83 ;
V_83 = F_54 ( V_84 ) ;
if ( V_83 == NULL )
break;
V_77 = F_55 ( V_83 ) ;
if ( V_79 == V_81 ) {
F_15 ( & V_77 -> V_12 , & V_76 ) ;
V_79 = 0 ;
}
else {
struct V_64 * V_85 = V_76 . V_11 ;
V_78 = V_77 ;
V_77 = F_6 ( V_85 ,
struct V_76 ,
V_12 ) ;
V_70 = F_56 ( V_78 , V_47 ) ;
if ( V_70 ) {
F_21 ( V_45 L_18
L_19 , V_70 ) ;
* V_68 = L_20 ;
goto V_86;
}
V_77 -> V_80 [ V_79 ++ ] = V_78 ;
}
V_82 ++ ;
}
}
V_70 = 0 ;
V_86:
F_57 ( & V_75 ) ;
V_46:
return V_70 ;
}
static int F_58 ( char * V_63 , char * V_67 , int V_87 , char * * V_68 )
{
char V_40 [ sizeof( L_21 ) ] ;
int V_33 = 0 ;
sprintf ( V_40 , L_22 , V_88 ) ;
F_59 ( V_67 , V_87 , V_33 , V_40 , 1 ) ;
return V_33 ;
}
static int F_60 ( char * * V_67 , int * V_89 , int * V_90 )
{
* V_89 = 0 ;
* V_90 = 0 ;
return 0 ;
}
static int F_61 ( int V_91 , char * * V_68 )
{
* V_68 = L_23 ;
return - V_92 ;
}
static int T_4 F_62 ( void )
{
if ( F_63 () )
F_44 ( & V_93 ) ;
else F_21 ( V_45 L_24
L_25 ) ;
return 0 ;
}
static void F_64 ( int (* F_65)( char * , char * , int ,
char * * ) ,
struct V_20 * V_8 , char * V_63 )
{
char V_94 [ V_95 ] , * error , * V_40 ;
int V_91 , V_87 ;
if ( F_65 == NULL ) {
F_13 ( V_8 , L_26 , 1 , 0 ) ;
return;
}
error = NULL ;
V_87 = F_66 ( V_94 ) ;
V_40 = V_94 ;
while ( 1 ) {
V_91 = (* F_65)( V_63 , V_40 , V_87 , & error ) ;
if ( error != NULL ) {
F_13 ( V_8 , error , 1 , 0 ) ;
goto V_46;
}
if ( V_91 <= V_87 ) {
F_13 ( V_8 , V_40 , 0 , 0 ) ;
goto V_46;
}
if ( V_40 != V_94 )
F_9 ( V_40 ) ;
V_87 = V_91 ;
V_40 = F_12 ( V_87 , V_48 ) ;
if ( V_40 == NULL ) {
F_13 ( V_8 , L_9 , 1 , 0 ) ;
return;
}
}
V_46:
if ( V_40 != V_94 )
F_9 ( V_40 ) ;
}
void F_67 ( struct V_20 * V_8 )
{
struct V_60 * V_66 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_63 , * V_96 = L_5 ;
int V_70 ;
V_34 += strlen ( L_27 ) ;
V_34 = F_24 ( V_34 ) ;
V_66 = F_48 ( V_34 ) ;
if ( V_66 == NULL ) {
F_13 ( V_8 , L_28 , 1 , 0 ) ;
return;
}
V_63 = & V_34 [ strlen ( V_66 -> V_63 ) ] ;
V_34 = V_63 ;
while ( ( * V_34 != '=' ) && ( * V_34 != '\0' ) )
V_34 ++ ;
if ( * V_34 == '=' ) {
V_70 = (* V_66 -> V_97 )( V_63 , & V_96 ) ;
F_13 ( V_8 , V_96 , V_70 , 0 ) ;
}
else F_64 ( V_66 -> F_65 , V_8 , V_63 ) ;
}
void F_68 ( struct V_20 * V_8 )
{
struct V_60 * V_66 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_98 = L_5 ;
char error [ 256 ] ;
int V_70 , V_99 , V_100 , V_91 ;
V_34 += strlen ( L_29 ) ;
V_34 = F_24 ( V_34 ) ;
V_66 = F_48 ( V_34 ) ;
if ( V_66 == NULL ) {
F_13 ( V_8 , L_30 , 1 , 0 ) ;
return;
}
V_34 = & V_34 [ strlen ( V_66 -> V_63 ) ] ;
V_70 = 1 ;
V_91 = (* V_66 -> V_101 )( & V_34 , & V_99 , & V_100 ) ;
if ( V_91 < 0 ) {
V_98 = L_31 ;
goto V_46;
}
else if ( ( V_91 < V_99 ) || ( V_91 > V_100 ) ) {
sprintf ( error , L_32
L_33 , V_99 , V_100 ) ;
V_98 = error ;
goto V_46;
}
V_98 = NULL ;
V_70 = (* V_66 -> remove )( V_91 , & V_98 ) ;
switch( V_70 ) {
case 0 :
V_98 = L_5 ;
break;
case - V_102 :
if ( V_98 == NULL )
V_98 = L_34 ;
break;
case - V_92 :
if ( V_98 == NULL )
V_98 = L_35 ;
break;
default:
break;
}
V_46:
F_13 ( V_8 , V_98 , V_70 , 0 ) ;
}
static void F_69 ( struct V_103 * V_103 , const char * string ,
unsigned int V_33 )
{
struct V_64 * V_65 ;
int V_91 ;
if ( F_4 ( & V_104 ) )
return;
while ( V_33 > 0 ) {
V_91 = F_70 ( ( V_105 ) V_33 , F_66 ( V_106 ) ) ;
strncpy ( V_106 , string , V_91 ) ;
string += V_91 ;
V_33 -= V_91 ;
F_49 (ele, &clients) {
struct V_107 * V_85 ;
V_85 = F_6 ( V_65 , struct V_107 , V_12 ) ;
F_71 ( V_85 -> V_8 , V_106 , V_91 , 0 , 1 ) ;
}
}
}
static int F_72 ( void )
{
F_73 ( & V_108 ) ;
return 0 ;
}
static void F_74 ( struct V_20 * V_8 , void (* F_75)( void * ) ,
void * V_109 )
{
struct V_107 V_85 ;
unsigned long V_9 ;
V_85 . V_8 = V_8 ;
F_76 ( & V_110 , V_9 ) ;
F_15 ( & V_85 . V_12 , & V_104 ) ;
F_77 ( & V_110 , V_9 ) ;
(* F_75)( V_109 ) ;
F_71 ( V_8 , L_5 , 0 , 0 , 0 ) ;
F_76 ( & V_110 , V_9 ) ;
F_7 ( & V_85 . V_12 ) ;
F_77 ( & V_110 , V_9 ) ;
}
static void F_78 ( void * V_109 )
{
char * V_111 = V_109 ;
F_79 ( * V_111 ) ;
}
void V_57 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_36 ) ;
V_34 = F_24 ( V_34 ) ;
if ( * V_34 == 'b' )
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_74 ( V_8 , F_78 , V_34 ) ;
}
void V_57 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_37 , 1 , 0 ) ;
}
static void F_80 ( void * V_109 )
{
struct V_112 * V_113 = V_38 , * V_114 = V_109 ;
V_114 -> V_115 . V_116 = V_113 ;
F_81 ( V_113 , V_114 ) ;
F_82 ( V_113 , V_114 , V_113 ) ;
}
void F_83 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
int V_117 = - 1 ;
struct V_112 * V_114 = NULL ;
V_34 += strlen ( L_38 ) ;
V_34 = F_24 ( V_34 ) ;
if ( sscanf ( V_34 , L_39 , & V_117 ) == 0 ) {
F_13 ( V_8 , L_40 , 1 , 0 ) ;
return;
}
V_114 = F_84 ( V_117 , & V_118 ) ;
if ( ( V_114 == NULL ) || ( V_117 == 0 ) ) {
F_13 ( V_8 , L_41 , 1 , 0 ) ;
return;
}
F_74 ( V_8 , F_80 , V_114 ) ;
}
static int T_4 F_85 ( void )
{
long V_119 ;
int V_70 ;
char V_41 [ V_120 ] ;
if ( F_86 ( L_42 , V_41 , sizeof( V_41 ) ) )
return - 1 ;
snprintf ( V_121 , sizeof( V_41 ) , L_43 , V_41 ) ;
V_119 = F_87 ( V_41 , sizeof( V_41 ) , 1 ) ;
if ( V_119 < 0 ) {
F_21 ( V_45 L_44 ) ;
return 1 ;
}
if ( F_42 ( V_119 , 0 ) )
goto V_46;
F_88 ( & V_122 ) ;
V_70 = F_89 ( V_26 , V_119 , V_123 , F_10 ,
V_124 , L_42 , ( void * ) V_119 ) ;
if ( V_70 ) {
F_21 ( V_45 L_45 ) ;
goto V_46;
}
if ( V_125 != NULL ) {
V_125 = F_90 ( V_125 , V_48 ) ;
if ( V_125 != NULL )
F_91 ( V_125 , V_126 ,
V_121 ,
strlen ( V_121 ) + 1 ) ;
else F_21 ( V_45 L_46
L_47 ) ;
}
F_21 ( V_127 L_48 ,
V_128 , V_121 ) ;
return 0 ;
V_46:
F_92 ( V_119 ) ;
return 1 ;
}
static T_5 F_93 ( struct V_41 * V_41 ,
const char T_6 * V_129 , V_105 V_130 , T_2 * V_50 )
{
char * V_40 ;
V_40 = F_12 ( V_130 + 1 , V_48 ) ;
if ( V_40 == NULL )
return - V_131 ;
if ( F_94 ( V_40 , V_129 , V_130 ) ) {
V_130 = - V_132 ;
goto V_46;
}
V_40 [ V_130 ] = '\0' ;
F_91 ( V_125 , V_133 , V_40 , V_130 ) ;
V_46:
F_9 ( V_40 ) ;
return V_130 ;
}
static int F_95 ( void )
{
struct V_134 * V_135 ;
if ( V_125 == NULL )
return 0 ;
V_135 = F_96 ( L_42 , 0200 , NULL , & V_136 ) ;
if ( V_135 == NULL ) {
F_21 ( V_127 L_49
L_50 ) ;
return 0 ;
}
return 0 ;
}
void F_97 ( void )
{
F_45 ( & V_137 ) ;
}
void F_98 ( void )
{
F_47 ( & V_137 ) ;
}
static int F_99 ( char * V_67 )
{
if ( ! strncmp ( V_67 , V_138 , strlen ( V_138 ) ) ) {
V_67 += strlen ( V_138 ) ;
V_125 = V_67 ;
}
else F_21 ( V_45 L_51 , V_67 ) ;
return 1 ;
}
static int F_100 ( struct V_1 * V_139 , unsigned long V_140 ,
void * V_34 )
{
char * V_141 = V_34 ;
if ( V_125 == NULL )
return 0 ;
F_91 ( V_125 , V_142 , V_141 ,
strlen ( V_141 ) + 1 ) ;
return 0 ;
}
static int F_101 ( void )
{
F_102 ( & V_143 ,
& V_144 ) ;
return 0 ;
}
char * F_103 ( void )
{
return V_125 ;
}
