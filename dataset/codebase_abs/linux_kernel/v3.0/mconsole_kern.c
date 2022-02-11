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
char V_36 [ 64 ] ;
char * V_37 ;
int V_33 ;
int V_18 ;
int V_38 = 1 ;
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_6 ) ;
V_34 = F_23 ( V_34 ) ;
snprintf ( V_36 , sizeof( V_36 ) , L_7 , V_34 ) ;
V_18 = F_24 ( V_36 , 0 , 0 ) ;
if ( V_18 < 0 ) {
F_13 ( V_8 , L_8 , 1 , 0 ) ;
F_21 ( V_39 L_9 , V_36 , V_18 ) ;
goto V_40;
}
V_37 = F_12 ( V_41 , V_42 ) ;
if ( V_37 == NULL ) {
F_13 ( V_8 , L_10 , 1 , 0 ) ;
goto V_43;
}
for (; ; ) {
V_33 = F_25 ( V_18 , V_37 , V_41 - 1 ) ;
if ( V_33 < 0 ) {
F_13 ( V_8 , L_11 , 1 , 0 ) ;
goto V_44;
}
if ( V_38 ) {
F_13 ( V_8 , L_12 , 0 , 1 ) ;
V_38 = 0 ;
}
if ( V_33 == V_41 - 1 ) {
V_37 [ V_33 ] = '\0' ;
F_13 ( V_8 , V_37 , 0 , 1 ) ;
} else {
V_37 [ V_33 ] = '\0' ;
F_13 ( V_8 , V_37 , 0 , 0 ) ;
break;
}
}
V_44:
F_9 ( V_37 ) ;
V_43:
F_26 ( V_18 ) ;
V_40:
;
}
void F_27 ( struct V_20 * V_8 )
{
F_13 ( V_8 , V_45 , 0 , 0 ) ;
}
void F_28 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_29 () ;
}
void F_30 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_31 ( NULL ) ;
}
void F_32 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_33 () ;
}
void F_34 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_13 , 1 , 0 ) ;
}
void F_35 ( struct V_20 * V_8 )
{
F_36 ( V_8 -> V_46 , V_26 ) ;
F_37 ( V_8 -> V_46 , 1 ) ;
F_13 ( V_8 , L_14 , 0 , 0 ) ;
for (; ; ) {
if ( ! F_11 ( V_8 -> V_46 , V_8 ) )
continue;
if ( V_8 -> V_14 -> V_15 == F_34 )
break;
if ( V_8 -> V_14 -> V_15 == F_35 ) {
F_13 ( V_8 , L_15 , 1 , 0 ) ;
continue;
}
if ( V_8 -> V_14 -> V_15 == V_47 ) {
struct V_48 * V_49 ;
V_49 = F_38 ( (struct V_48 * ) & V_8 -> V_24 ) ;
V_47 ( V_8 ) ;
F_38 ( V_49 ) ;
continue;
}
(* V_8 -> V_14 -> V_15 )( V_8 ) ;
}
F_37 ( V_8 -> V_46 , 0 ) ;
F_17 ( V_8 -> V_46 , V_26 ) ;
F_13 ( V_8 , L_5 , 0 , 0 ) ;
}
void F_39 ( struct V_50 * V_19 )
{
F_40 ( & V_51 ) ;
F_41 ( ! F_4 ( & V_19 -> V_12 ) ) ;
F_15 ( & V_19 -> V_12 , & V_52 ) ;
F_42 ( & V_51 ) ;
}
static struct V_50 * F_43 ( char * V_53 )
{
struct V_54 * V_55 ;
struct V_50 * V_56 ;
F_44 (ele, &mconsole_devices) {
V_56 = F_6 ( V_55 , struct V_50 , V_12 ) ;
if ( ! strncmp ( V_53 , V_56 -> V_53 , strlen ( V_56 -> V_53 ) ) )
return V_56 ;
}
return NULL ;
}
static int F_45 ( char * V_57 , char * * V_58 )
{
unsigned long long V_59 ;
int V_60 = - V_61 , V_62 , V_63 ;
char * V_64 ;
if ( V_57 [ 0 ] != '=' ) {
* V_58 = L_16 ;
goto V_40;
}
V_57 ++ ;
if ( V_57 [ 0 ] == '-' )
V_63 = 0 ;
else if ( V_57 [ 0 ] == '+' ) {
V_63 = 1 ;
}
else {
* V_58 = L_17 ;
goto V_40;
}
V_57 ++ ;
V_59 = F_46 ( V_57 , & V_64 ) ;
if ( * V_64 != '\0' ) {
* V_58 = L_18 ;
goto V_40;
}
V_59 /= V_41 ;
F_47 ( & V_65 ) ;
for ( V_62 = 0 ; V_62 < V_59 ; V_62 ++ ) {
struct V_66 * V_67 ;
void * V_68 ;
if ( V_63 ) {
if ( F_4 ( & V_66 ) )
break;
V_67 = F_6 ( V_66 . V_11 ,
struct V_66 , V_12 ) ;
if ( V_69 > 0 )
V_68 = V_67 -> V_70 [ -- V_69 ] ;
else {
F_7 ( & V_67 -> V_12 ) ;
V_68 = V_67 ;
V_69 = V_71 ;
}
F_48 ( ( unsigned long ) V_68 ) ;
V_72 -- ;
}
else {
struct V_73 * V_73 ;
V_73 = F_49 ( V_74 ) ;
if ( V_73 == NULL )
break;
V_67 = F_50 ( V_73 ) ;
if ( V_69 == V_71 ) {
F_15 ( & V_67 -> V_12 , & V_66 ) ;
V_69 = 0 ;
}
else {
struct V_54 * V_75 = V_66 . V_11 ;
V_68 = V_67 ;
V_67 = F_6 ( V_75 ,
struct V_66 ,
V_12 ) ;
V_60 = F_51 ( V_68 , V_41 ) ;
if ( V_60 ) {
F_21 ( V_39 L_19
L_20 , V_60 ) ;
* V_58 = L_21 ;
goto V_76;
}
V_67 -> V_70 [ V_69 ++ ] = V_68 ;
}
V_72 ++ ;
}
}
V_60 = 0 ;
V_76:
F_52 ( & V_65 ) ;
V_40:
return V_60 ;
}
static int F_53 ( char * V_53 , char * V_57 , int V_77 , char * * V_58 )
{
char V_37 [ sizeof( L_22 ) ] ;
int V_33 = 0 ;
sprintf ( V_37 , L_23 , V_78 ) ;
F_54 ( V_57 , V_77 , V_33 , V_37 , 1 ) ;
return V_33 ;
}
static int F_55 ( char * * V_57 , int * V_79 , int * V_80 )
{
* V_79 = 0 ;
* V_80 = 0 ;
return 0 ;
}
static int F_56 ( int V_81 , char * * V_58 )
{
* V_58 = L_24 ;
return - V_82 ;
}
static int T_2 F_57 ( void )
{
if ( F_58 () )
F_39 ( & V_83 ) ;
else F_21 ( V_39 L_25
L_26 ) ;
return 0 ;
}
static void F_59 ( int (* F_60)( char * , char * , int ,
char * * ) ,
struct V_20 * V_8 , char * V_53 )
{
char V_84 [ V_85 ] , * error , * V_37 ;
int V_81 , V_77 ;
if ( F_60 == NULL ) {
F_13 ( V_8 , L_27 , 1 , 0 ) ;
return;
}
error = NULL ;
V_77 = F_61 ( V_84 ) ;
V_37 = V_84 ;
while ( 1 ) {
V_81 = (* F_60)( V_53 , V_37 , V_77 , & error ) ;
if ( error != NULL ) {
F_13 ( V_8 , error , 1 , 0 ) ;
goto V_40;
}
if ( V_81 <= V_77 ) {
F_13 ( V_8 , V_37 , 0 , 0 ) ;
goto V_40;
}
if ( V_37 != V_84 )
F_9 ( V_37 ) ;
V_77 = V_81 ;
V_37 = F_12 ( V_77 , V_42 ) ;
if ( V_37 == NULL ) {
F_13 ( V_8 , L_10 , 1 , 0 ) ;
return;
}
}
V_40:
if ( V_37 != V_84 )
F_9 ( V_37 ) ;
}
void F_62 ( struct V_20 * V_8 )
{
struct V_50 * V_56 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_53 , * V_86 = L_5 ;
int V_60 ;
V_34 += strlen ( L_28 ) ;
V_34 = F_23 ( V_34 ) ;
V_56 = F_43 ( V_34 ) ;
if ( V_56 == NULL ) {
F_13 ( V_8 , L_29 , 1 , 0 ) ;
return;
}
V_53 = & V_34 [ strlen ( V_56 -> V_53 ) ] ;
V_34 = V_53 ;
while ( ( * V_34 != '=' ) && ( * V_34 != '\0' ) )
V_34 ++ ;
if ( * V_34 == '=' ) {
V_60 = (* V_56 -> V_87 )( V_53 , & V_86 ) ;
F_13 ( V_8 , V_86 , V_60 , 0 ) ;
}
else F_59 ( V_56 -> F_60 , V_8 , V_53 ) ;
}
void F_63 ( struct V_20 * V_8 )
{
struct V_50 * V_56 ;
char * V_34 = V_8 -> V_13 . V_4 , * V_88 = L_5 ;
char error [ 256 ] ;
int V_60 , V_89 , V_90 , V_81 ;
V_34 += strlen ( L_30 ) ;
V_34 = F_23 ( V_34 ) ;
V_56 = F_43 ( V_34 ) ;
if ( V_56 == NULL ) {
F_13 ( V_8 , L_31 , 1 , 0 ) ;
return;
}
V_34 = & V_34 [ strlen ( V_56 -> V_53 ) ] ;
V_60 = 1 ;
V_81 = (* V_56 -> V_91 )( & V_34 , & V_89 , & V_90 ) ;
if ( V_81 < 0 ) {
V_88 = L_32 ;
goto V_40;
}
else if ( ( V_81 < V_89 ) || ( V_81 > V_90 ) ) {
sprintf ( error , L_33
L_34 , V_89 , V_90 ) ;
V_88 = error ;
goto V_40;
}
V_88 = NULL ;
V_60 = (* V_56 -> remove )( V_81 , & V_88 ) ;
switch( V_60 ) {
case 0 :
V_88 = L_5 ;
break;
case - V_92 :
if ( V_88 == NULL )
V_88 = L_35 ;
break;
case - V_82 :
if ( V_88 == NULL )
V_88 = L_36 ;
break;
default:
break;
}
V_40:
F_13 ( V_8 , V_88 , V_60 , 0 ) ;
}
static void F_64 ( struct V_93 * V_93 , const char * string ,
unsigned int V_33 )
{
struct V_54 * V_55 ;
int V_81 ;
if ( F_4 ( & V_94 ) )
return;
while ( V_33 > 0 ) {
V_81 = F_65 ( ( V_95 ) V_33 , F_61 ( V_96 ) ) ;
strncpy ( V_96 , string , V_81 ) ;
string += V_81 ;
V_33 -= V_81 ;
F_44 (ele, &clients) {
struct V_97 * V_75 ;
V_75 = F_6 ( V_55 , struct V_97 , V_12 ) ;
F_66 ( V_75 -> V_8 , V_96 , V_81 , 0 , 1 ) ;
}
}
}
static int F_67 ( void )
{
F_68 ( & V_98 ) ;
return 0 ;
}
static void F_69 ( struct V_20 * V_8 , void (* F_70)( void * ) ,
void * V_99 )
{
struct V_97 V_75 ;
unsigned long V_9 ;
V_75 . V_8 = V_8 ;
F_71 ( & V_100 , V_9 ) ;
F_15 ( & V_75 . V_12 , & V_94 ) ;
F_72 ( & V_100 , V_9 ) ;
(* F_70)( V_99 ) ;
F_66 ( V_8 , L_5 , 0 , 0 , 0 ) ;
F_71 ( & V_100 , V_9 ) ;
F_7 ( & V_75 . V_12 ) ;
F_72 ( & V_100 , V_9 ) ;
}
static void F_73 ( void * V_99 )
{
char * V_101 = V_99 ;
F_74 ( * V_101 ) ;
}
void V_47 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
V_34 += strlen ( L_37 ) ;
V_34 = F_23 ( V_34 ) ;
if ( * V_34 == 'b' )
F_13 ( V_8 , L_5 , 0 , 0 ) ;
F_69 ( V_8 , F_73 , V_34 ) ;
}
void V_47 ( struct V_20 * V_8 )
{
F_13 ( V_8 , L_38 , 1 , 0 ) ;
}
static void F_75 ( void * V_99 )
{
struct V_102 * V_103 = V_104 , * V_105 = V_99 ;
V_105 -> V_106 . V_107 = V_103 ;
F_76 ( V_103 , V_105 , V_103 ) ;
}
void F_77 ( struct V_20 * V_8 )
{
char * V_34 = V_8 -> V_13 . V_4 ;
int V_108 = - 1 ;
struct V_102 * V_105 = NULL ;
V_34 += strlen ( L_39 ) ;
V_34 = F_23 ( V_34 ) ;
if ( sscanf ( V_34 , L_40 , & V_108 ) == 0 ) {
F_13 ( V_8 , L_41 , 1 , 0 ) ;
return;
}
V_105 = F_78 ( V_108 , & V_109 ) ;
if ( ( V_105 == NULL ) || ( V_108 == 0 ) ) {
F_13 ( V_8 , L_42 , 1 , 0 ) ;
return;
}
F_69 ( V_8 , F_75 , V_105 ) ;
}
static int T_2 F_79 ( void )
{
long V_110 ;
int V_60 ;
char V_111 [ V_112 ] ;
if ( F_80 ( L_43 , V_111 , sizeof( V_111 ) ) )
return - 1 ;
snprintf ( V_113 , sizeof( V_111 ) , L_44 , V_111 ) ;
V_110 = F_81 ( V_111 , sizeof( V_111 ) , 1 ) ;
if ( V_110 < 0 ) {
F_21 ( V_39 L_45 ) ;
return 1 ;
}
if ( F_37 ( V_110 , 0 ) )
goto V_40;
F_82 ( & V_114 ) ;
V_60 = F_83 ( V_26 , V_110 , V_115 , F_10 ,
V_116 | V_117 | V_118 ,
L_43 , ( void * ) V_110 ) ;
if ( V_60 ) {
F_21 ( V_39 L_46 ) ;
goto V_40;
}
if ( V_119 != NULL ) {
V_119 = F_84 ( V_119 , V_42 ) ;
if ( V_119 != NULL )
F_85 ( V_119 , V_120 ,
V_113 ,
strlen ( V_113 ) + 1 ) ;
else F_21 ( V_39 L_47
L_48 ) ;
}
F_21 ( V_121 L_49 ,
V_122 , V_113 ) ;
return 0 ;
V_40:
F_86 ( V_110 ) ;
return 1 ;
}
static T_3 F_87 ( struct V_111 * V_111 ,
const char T_4 * V_123 , V_95 V_124 , T_5 * V_125 )
{
char * V_37 ;
V_37 = F_12 ( V_124 + 1 , V_42 ) ;
if ( V_37 == NULL )
return - V_126 ;
if ( F_88 ( V_37 , V_123 , V_124 ) ) {
V_124 = - V_127 ;
goto V_40;
}
V_37 [ V_124 ] = '\0' ;
F_85 ( V_119 , V_128 , V_37 , V_124 ) ;
V_40:
F_9 ( V_37 ) ;
return V_124 ;
}
static int F_89 ( void )
{
struct V_129 * V_130 ;
if ( V_119 == NULL )
return 0 ;
V_130 = F_90 ( L_43 , 0200 , NULL , & V_131 ) ;
if ( V_130 == NULL ) {
F_21 ( V_121 L_50
L_51 ) ;
return 0 ;
}
return 0 ;
}
void F_91 ( void )
{
F_40 ( & V_132 ) ;
}
void F_92 ( void )
{
F_42 ( & V_132 ) ;
}
static int F_93 ( char * V_57 )
{
if ( ! strncmp ( V_57 , V_133 , strlen ( V_133 ) ) ) {
V_57 += strlen ( V_133 ) ;
V_119 = V_57 ;
}
else F_21 ( V_39 L_52 , V_57 ) ;
return 1 ;
}
static int F_94 ( struct V_1 * V_134 , unsigned long V_135 ,
void * V_34 )
{
char * V_136 = V_34 ;
if ( V_119 == NULL )
return 0 ;
F_85 ( V_119 , V_137 , V_136 ,
strlen ( V_136 ) + 1 ) ;
return 0 ;
}
static int F_95 ( void )
{
F_96 ( & V_138 ,
& V_139 ) ;
return 0 ;
}
char * F_97 ( void )
{
return V_119 ;
}
