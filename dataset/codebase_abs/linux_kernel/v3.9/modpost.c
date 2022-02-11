PRINTF void F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
fprintf ( V_3 , L_1 ) ;
va_start ( V_2 , V_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
va_end ( V_2 ) ;
exit ( 1 ) ;
}
PRINTF void F_2 ( const char * V_1 , ... )
{
T_1 V_2 ;
fprintf ( V_3 , L_2 ) ;
va_start ( V_2 , V_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
PRINTF void F_3 ( const char * V_1 , ... )
{
T_1 V_2 ;
fprintf ( V_3 , L_3 ) ;
va_start ( V_2 , V_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
static int F_4 ( const char * V_4 )
{
const char * V_5 ;
V_5 = strrchr ( V_4 , '/' ) ;
if ( V_5 )
V_5 ++ ;
else
V_5 = V_4 ;
return ( strcmp ( V_5 , L_4 ) == 0 ) ||
( strcmp ( V_5 , L_5 ) == 0 ) ;
}
void * F_5 ( void * V_6 , const char * V_7 )
{
if ( ! V_6 )
F_1 ( L_6 , V_7 ) ;
return V_6 ;
}
static struct V_8 * F_6 ( char * V_4 )
{
struct V_8 * V_9 ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 )
if ( strcmp ( V_9 -> V_12 , V_4 ) == 0 )
break;
return V_9 ;
}
static struct V_8 * F_7 ( char * V_4 )
{
struct V_8 * V_9 ;
char * V_13 , * V_14 ;
V_9 = F_8 ( malloc ( sizeof( * V_9 ) ) ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_13 = F_8 ( F_9 ( V_4 ) ) ;
V_14 = strrchr ( V_13 , '.' ) ;
if ( V_14 != NULL )
if ( strcmp ( V_14 , L_7 ) == 0 ) {
* V_14 = '\0' ;
V_9 -> V_15 = 1 ;
}
V_9 -> V_12 = V_13 ;
V_9 -> V_16 = - 1 ;
V_9 -> V_11 = V_10 ;
V_10 = V_9 ;
return V_9 ;
}
static inline unsigned int F_10 ( const char * V_12 )
{
unsigned V_17 ;
unsigned V_18 ;
for ( V_17 = 0x238F13AF * strlen ( V_12 ) , V_18 = 0 ; V_12 [ V_18 ] ; V_18 ++ )
V_17 = ( V_17 + ( ( ( unsigned char * ) V_12 ) [ V_18 ] << ( V_18 * 5 % 24 ) ) ) ;
return ( 1103515243 * V_17 + 12345 ) ;
}
static struct V_19 * F_11 ( const char * V_12 , unsigned int V_20 ,
struct V_19 * V_11 )
{
struct V_19 * V_14 = F_8 ( malloc ( sizeof( * V_14 ) + strlen ( V_12 ) + 1 ) ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
strcpy ( V_14 -> V_12 , V_12 ) ;
V_14 -> V_20 = V_20 ;
V_14 -> V_11 = V_11 ;
return V_14 ;
}
static struct V_19 * F_12 ( const char * V_12 , struct V_8 * V_8 ,
enum V_21 V_21 )
{
unsigned int V_22 ;
struct V_19 * V_23 ;
V_22 = F_10 ( V_12 ) % V_24 ;
V_23 = V_25 [ V_22 ] = F_11 ( V_12 , 0 , V_25 [ V_22 ] ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_21 = V_21 ;
return V_23 ;
}
static struct V_19 * F_13 ( const char * V_12 )
{
struct V_19 * V_14 ;
if ( V_12 [ 0 ] == '.' )
V_12 ++ ;
for ( V_14 = V_25 [ F_10 ( V_12 ) % V_24 ] ; V_14 ; V_14 = V_14 -> V_11 ) {
if ( strcmp ( V_14 -> V_12 , V_12 ) == 0 )
return V_14 ;
}
return NULL ;
}
static const char * F_14 ( enum V_21 V_26 )
{
return V_27 [ V_26 ] . V_28 ;
}
static enum V_21 F_15 ( const char * V_14 )
{
int V_18 ;
if ( ! V_14 )
return V_29 ;
for ( V_18 = 0 ; V_27 [ V_18 ] . V_21 != V_29 ; V_18 ++ ) {
if ( strcmp ( V_27 [ V_18 ] . V_28 , V_14 ) == 0 )
return V_27 [ V_18 ] . V_21 ;
}
return V_29 ;
}
static enum V_21 F_16 ( struct V_30 * V_31 , unsigned int V_32 )
{
const char * V_33 = F_17 ( V_31 , V_32 ) ;
if ( F_18 ( V_33 , L_8 ) )
return V_34 ;
else if ( F_18 ( V_33 , L_9 ) )
return V_35 ;
else if ( F_18 ( V_33 , L_10 ) )
return V_36 ;
else if ( F_18 ( V_33 , L_11 ) )
return V_37 ;
else if ( F_18 ( V_33 , L_12 ) )
return V_38 ;
else
return V_29 ;
}
static enum V_21 F_19 ( struct V_30 * V_31 , unsigned int V_32 )
{
if ( V_32 == V_31 -> V_39 )
return V_34 ;
else if ( V_32 == V_31 -> V_40 )
return V_35 ;
else if ( V_32 == V_31 -> V_41 )
return V_36 ;
else if ( V_32 == V_31 -> V_42 )
return V_37 ;
else if ( V_32 == V_31 -> V_43 )
return V_38 ;
else
return V_29 ;
}
static struct V_19 * F_20 ( const char * V_12 , struct V_8 * V_9 ,
enum V_21 V_21 )
{
struct V_19 * V_14 = F_13 ( V_12 ) ;
if ( ! V_14 ) {
V_14 = F_12 ( V_12 , V_9 , V_21 ) ;
} else {
if ( ! V_14 -> V_44 ) {
F_2 ( L_13
L_14 , V_9 -> V_12 , V_12 ,
V_14 -> V_8 -> V_12 ,
F_4 ( V_14 -> V_8 -> V_12 ) ? L_15 : L_16 ) ;
} else {
V_14 -> V_8 = V_9 ;
}
}
V_14 -> V_44 = 0 ;
V_14 -> V_45 = F_4 ( V_9 -> V_12 ) ;
V_14 -> V_46 = 0 ;
V_14 -> V_21 = V_21 ;
return V_14 ;
}
static void F_21 ( const char * V_12 , struct V_8 * V_9 ,
unsigned int V_47 , enum V_21 V_21 )
{
struct V_19 * V_14 = F_13 ( V_12 ) ;
if ( ! V_14 )
V_14 = F_12 ( V_12 , V_9 , V_21 ) ;
V_14 -> V_47 = V_47 ;
V_14 -> V_48 = 1 ;
}
void * F_22 ( const char * V_49 , unsigned long * V_50 )
{
struct V_51 V_52 ;
void * V_53 = V_54 ;
int V_55 ;
V_55 = F_23 ( V_49 , V_56 ) ;
if ( V_55 < 0 )
return NULL ;
if ( F_24 ( V_55 , & V_52 ) )
goto V_57;
* V_50 = V_52 . V_58 ;
V_53 = F_25 ( NULL , * V_50 , V_59 | V_60 , V_61 , V_55 , 0 ) ;
V_57:
F_26 ( V_55 ) ;
if ( V_53 == V_54 )
return NULL ;
return V_53 ;
}
char * F_27 ( unsigned long * V_62 , void * V_63 , unsigned long V_50 )
{
static char line [ 4096 ] ;
int V_64 = 1 ;
T_2 V_65 = 0 ;
signed char * V_13 = ( signed char * ) V_63 + * V_62 ;
char * V_14 = line ;
for (; * V_62 < V_50 ; ( * V_62 ) ++ ) {
if ( V_64 && isspace ( * V_13 ) ) {
V_13 ++ ;
continue;
}
V_64 = 0 ;
if ( * V_13 != '\n' && ( * V_62 < V_50 ) ) {
V_65 ++ ;
* V_14 ++ = * V_13 ++ ;
if ( V_65 > 4095 )
break;
} else {
* V_14 = '\0' ;
return line ;
}
}
return NULL ;
}
void F_28 ( void * V_63 , unsigned long V_50 )
{
F_29 ( V_63 , V_50 ) ;
}
static int F_30 ( struct V_30 * V_66 , const char * V_49 )
{
unsigned int V_18 ;
T_3 * V_67 ;
T_4 * V_68 ;
T_5 * V_69 ;
const char * V_70 ;
unsigned int V_71 = ~ 0U , V_72 = ~ 0U ;
V_67 = F_22 ( V_49 , & V_66 -> V_50 ) ;
if ( ! V_67 ) {
perror ( V_49 ) ;
exit ( 1 ) ;
}
V_66 -> V_67 = V_67 ;
if ( V_66 -> V_50 < sizeof( * V_67 ) ) {
return 0 ;
}
if ( ( V_67 -> V_73 [ V_74 ] != V_75 ) ||
( V_67 -> V_73 [ V_76 ] != V_77 ) ||
( V_67 -> V_73 [ V_78 ] != V_79 ) ||
( V_67 -> V_73 [ V_80 ] != V_81 ) ) {
return 0 ;
}
V_67 -> V_82 = F_31 ( V_67 -> V_82 ) ;
V_67 -> V_83 = F_31 ( V_67 -> V_83 ) ;
V_67 -> V_84 = F_31 ( V_67 -> V_84 ) ;
V_67 -> V_85 = F_31 ( V_67 -> V_85 ) ;
V_67 -> V_86 = F_31 ( V_67 -> V_86 ) ;
V_67 -> V_87 = F_31 ( V_67 -> V_87 ) ;
V_67 -> V_88 = F_31 ( V_67 -> V_88 ) ;
V_67 -> V_89 = F_31 ( V_67 -> V_89 ) ;
V_67 -> V_90 = F_31 ( V_67 -> V_90 ) ;
V_67 -> V_91 = F_31 ( V_67 -> V_91 ) ;
V_67 -> V_92 = F_31 ( V_67 -> V_92 ) ;
V_67 -> V_93 = F_31 ( V_67 -> V_93 ) ;
V_67 -> V_94 = F_31 ( V_67 -> V_94 ) ;
V_68 = ( void * ) V_67 + V_67 -> V_87 ;
V_66 -> V_68 = V_68 ;
if ( V_67 -> V_87 > V_66 -> V_50 ) {
F_1 ( L_17
L_18 , ( unsigned long ) V_67 -> V_87 ,
V_49 , V_66 -> V_50 ) ;
return 0 ;
}
if ( V_67 -> V_93 == V_95 ) {
V_66 -> V_96 = F_31 ( V_68 [ 0 ] . V_97 ) ;
}
else {
V_66 -> V_96 = V_67 -> V_93 ;
}
if ( V_67 -> V_94 == V_98 ) {
V_66 -> V_99 = F_31 ( V_68 [ 0 ] . V_100 ) ;
}
else {
V_66 -> V_99 = V_67 -> V_94 ;
}
for ( V_18 = 0 ; V_18 < V_66 -> V_96 ; V_18 ++ ) {
V_68 [ V_18 ] . V_101 = F_31 ( V_68 [ V_18 ] . V_101 ) ;
V_68 [ V_18 ] . V_102 = F_31 ( V_68 [ V_18 ] . V_102 ) ;
V_68 [ V_18 ] . V_103 = F_31 ( V_68 [ V_18 ] . V_103 ) ;
V_68 [ V_18 ] . V_104 = F_31 ( V_68 [ V_18 ] . V_104 ) ;
V_68 [ V_18 ] . V_105 = F_31 ( V_68 [ V_18 ] . V_105 ) ;
V_68 [ V_18 ] . V_97 = F_31 ( V_68 [ V_18 ] . V_97 ) ;
V_68 [ V_18 ] . V_100 = F_31 ( V_68 [ V_18 ] . V_100 ) ;
V_68 [ V_18 ] . V_106 = F_31 ( V_68 [ V_18 ] . V_106 ) ;
V_68 [ V_18 ] . V_107 = F_31 ( V_68 [ V_18 ] . V_107 ) ;
V_68 [ V_18 ] . V_108 = F_31 ( V_68 [ V_18 ] . V_108 ) ;
}
V_70 = ( void * ) V_67 + V_68 [ V_66 -> V_99 ] . V_105 ;
for ( V_18 = 1 ; V_18 < V_66 -> V_96 ; V_18 ++ ) {
const char * V_33 ;
int V_109 = V_68 [ V_18 ] . V_102 == V_110 ;
if ( ! V_109 && V_68 [ V_18 ] . V_105 > V_66 -> V_50 ) {
F_1 ( L_19
L_20 , V_49 ,
( unsigned long ) V_68 [ V_18 ] . V_105 ,
sizeof( * V_67 ) ) ;
return 0 ;
}
V_33 = V_70 + V_68 [ V_18 ] . V_101 ;
if ( strcmp ( V_33 , L_21 ) == 0 ) {
if ( V_109 )
F_1 ( L_22 , V_49 ) ;
V_66 -> V_111 = ( void * ) V_67 + V_68 [ V_18 ] . V_105 ;
V_66 -> V_112 = V_68 [ V_18 ] . V_97 ;
} else if ( strcmp ( V_33 , L_23 ) == 0 )
V_66 -> V_39 = V_18 ;
else if ( strcmp ( V_33 , L_24 ) == 0 )
V_66 -> V_40 = V_18 ;
else if ( strcmp ( V_33 , L_25 ) == 0 )
V_66 -> V_41 = V_18 ;
else if ( strcmp ( V_33 , L_26 ) == 0 )
V_66 -> V_42 = V_18 ;
else if ( strcmp ( V_33 , L_27 ) == 0 )
V_66 -> V_43 = V_18 ;
if ( V_68 [ V_18 ] . V_102 == V_113 ) {
unsigned int V_114 ;
V_71 = V_18 ;
V_66 -> V_115 = ( void * ) V_67 +
V_68 [ V_18 ] . V_105 ;
V_66 -> V_116 = ( void * ) V_67 +
V_68 [ V_18 ] . V_105 + V_68 [ V_18 ] . V_97 ;
V_114 = V_68 [ V_18 ] . V_100 ;
V_66 -> V_117 = ( void * ) V_67 +
V_68 [ V_114 ] . V_105 ;
}
if ( V_68 [ V_18 ] . V_102 == V_118 ) {
V_72 = V_18 ;
V_66 -> V_119 = ( void * ) V_67 +
V_68 [ V_18 ] . V_105 ;
V_66 -> V_120 = ( void * ) V_67 +
V_68 [ V_18 ] . V_105 + V_68 [ V_18 ] . V_97 ;
}
}
if ( ! V_66 -> V_115 )
F_1 ( L_28 , V_49 ) ;
for ( V_69 = V_66 -> V_115 ; V_69 < V_66 -> V_116 ; V_69 ++ ) {
V_69 -> V_121 = F_31 ( V_69 -> V_121 ) ;
V_69 -> V_122 = F_31 ( V_69 -> V_122 ) ;
V_69 -> V_123 = F_31 ( V_69 -> V_123 ) ;
V_69 -> V_58 = F_31 ( V_69 -> V_58 ) ;
}
if ( V_72 != ~ 0U ) {
T_6 * V_13 ;
if ( V_71 != V_68 [ V_72 ] . V_100 )
F_1 ( L_29 ,
V_49 , V_68 [ V_72 ] . V_100 ,
V_71 ) ;
for ( V_13 = V_66 -> V_119 ; V_13 < V_66 -> V_120 ;
V_13 ++ )
* V_13 = F_31 ( * V_13 ) ;
}
return 1 ;
}
static void F_32 ( struct V_30 * V_66 )
{
F_28 ( V_66 -> V_67 , V_66 -> V_50 ) ;
}
static int F_33 ( struct V_30 * V_66 , const char * V_124 )
{
if ( strcmp ( V_124 , V_125 L_30 ) == 0 )
return 1 ;
if ( strcmp ( V_124 , L_31 ) == 0 )
return 1 ;
if ( V_66 -> V_67 -> V_83 == V_126 )
if ( strncmp ( V_124 , L_32 , sizeof( L_32 ) - 1 ) == 0 ||
strncmp ( V_124 , L_33 , sizeof( L_33 ) - 1 ) == 0 ||
strncmp ( V_124 , L_34 , sizeof( L_34 ) - 1 ) == 0 ||
strncmp ( V_124 , L_35 , sizeof( L_35 ) - 1 ) == 0 )
return 1 ;
if ( V_66 -> V_67 -> V_83 == V_127 )
if ( strncmp ( V_124 , L_36 , sizeof( L_36 ) - 1 ) == 0 ||
strncmp ( V_124 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
return 1 ;
return 0 ;
}
static void F_34 ( struct V_8 * V_9 , struct V_30 * V_66 ,
T_5 * V_69 , const char * V_124 )
{
unsigned int V_47 ;
enum V_21 V_21 ;
if ( ( ! F_4 ( V_9 -> V_12 ) || V_9 -> V_15 ) &&
strncmp ( V_124 , L_23 , 9 ) == 0 )
V_21 = F_16 ( V_66 , F_35 ( V_66 , V_69 ) ) ;
else
V_21 = F_19 ( V_66 , F_35 ( V_66 , V_69 ) ) ;
switch ( V_69 -> V_121 ) {
case V_128 :
F_2 ( L_38 , V_124 , V_9 -> V_12 ) ;
break;
case V_129 :
if ( strncmp ( V_124 , V_130 , strlen ( V_130 ) ) == 0 ) {
V_47 = ( unsigned int ) V_69 -> V_123 ;
F_21 ( V_124 + strlen ( V_130 ) , V_9 , V_47 ,
V_21 ) ;
}
break;
case V_95 :
if ( F_36 ( V_69 -> V_131 ) != V_132 &&
F_36 ( V_69 -> V_131 ) != V_133 )
break;
if ( F_33 ( V_66 , V_124 ) )
break;
#if F_37 ( V_134 ) || F_37 ( V_135 )
#ifndef V_135
#define V_135 STT_REGISTER
#endif
if ( V_66 -> V_67 -> V_83 == V_136 ||
V_66 -> V_67 -> V_83 == V_137 ) {
if ( F_38 ( V_69 -> V_131 ) == V_135 )
break;
if ( V_124 [ 0 ] == '.' ) {
char * V_138 = F_9 ( V_124 ) ;
V_138 [ 0 ] = '_' ;
V_138 [ 1 ] = toupper ( V_138 [ 1 ] ) ;
V_124 = V_138 ;
}
}
#endif
if ( memcmp ( V_124 , V_125 ,
strlen ( V_125 ) ) == 0 ) {
V_9 -> V_139 =
F_11 ( V_124 +
strlen ( V_125 ) ,
F_36 ( V_69 -> V_131 ) == V_133 ,
V_9 -> V_139 ) ;
}
break;
default:
if ( strncmp ( V_124 , V_140 , strlen ( V_140 ) ) == 0 ) {
F_20 ( V_124 + strlen ( V_140 ) , V_9 ,
V_21 ) ;
}
if ( strcmp ( V_124 , V_125 L_39 ) == 0 )
V_9 -> V_141 = 1 ;
if ( strcmp ( V_124 , V_125 L_40 ) == 0 )
V_9 -> V_142 = 1 ;
break;
}
}
static char * F_39 ( char * string , unsigned long * V_143 )
{
while ( string [ 0 ] ) {
string ++ ;
if ( ( * V_143 ) -- <= 1 )
return NULL ;
}
while ( ! string [ 0 ] ) {
string ++ ;
if ( ( * V_143 ) -- <= 1 )
return NULL ;
}
return string ;
}
static char * F_40 ( void * V_111 , unsigned long V_112 ,
const char * V_144 , char * V_66 )
{
char * V_13 ;
unsigned int V_145 = strlen ( V_144 ) ;
unsigned long V_50 = V_112 ;
if ( V_66 ) {
V_50 -= V_66 - ( char * ) V_111 ;
V_111 = F_39 ( V_66 , & V_50 ) ;
}
for ( V_13 = V_111 ; V_13 ; V_13 = F_39 ( V_13 , & V_50 ) ) {
if ( strncmp ( V_13 , V_144 , V_145 ) == 0 && V_13 [ V_145 ] == '=' )
return V_13 + V_145 + 1 ;
}
return NULL ;
}
static char * F_41 ( void * V_111 , unsigned long V_112 ,
const char * V_144 )
{
return F_40 ( V_111 , V_112 , V_144 , NULL ) ;
}
static int F_42 ( const char * V_14 , const char * V_146 )
{
int V_147 , V_148 ;
if ( ! V_14 || ! V_146 )
return 1 ;
V_147 = strlen ( V_14 ) ;
V_148 = strlen ( V_146 ) ;
if ( ( V_147 == 0 ) || ( V_148 == 0 ) )
return 1 ;
if ( V_148 > V_147 )
return 1 ;
return memcmp ( V_14 + V_147 - V_148 , V_146 , V_148 ) ;
}
static const char * F_43 ( struct V_30 * V_31 , T_5 * V_69 )
{
if ( V_69 )
return V_31 -> V_117 + V_69 -> V_122 ;
else
return L_41 ;
}
static const char * F_17 ( struct V_30 * V_31 , int V_149 )
{
T_4 * V_68 = V_31 -> V_68 ;
return ( void * ) V_31 -> V_67 +
V_31 -> V_68 [ V_31 -> V_99 ] . V_105 +
V_68 [ V_149 ] . V_101 ;
}
static const char * F_44 ( struct V_30 * V_31 , T_4 * V_150 )
{
return ( void * ) V_31 -> V_67 +
V_31 -> V_68 [ V_31 -> V_99 ] . V_105 +
V_150 -> V_101 ;
}
static int F_45 ( const char * V_69 )
{
if ( * V_69 ++ == '\0' )
return 1 ;
if ( * V_69 != '.' )
return 0 ;
do {
char V_151 = * V_69 ++ ;
if ( V_151 < '0' || V_151 > '9' )
return 0 ;
} while ( * V_69 );
return 1 ;
}
static int F_46 ( const char * V_69 , const char * const V_152 [] )
{
const char * V_13 ;
while ( * V_152 ) {
V_13 = * V_152 ++ ;
const char * V_153 = V_13 + strlen ( V_13 ) - 1 ;
if ( * V_13 == '*' ) {
if ( F_42 ( V_69 , V_13 + 1 ) == 0 )
return 1 ;
}
else if ( * V_153 == '*' ) {
if ( strncmp ( V_69 , V_13 , strlen ( V_13 ) - 1 ) == 0 )
return 1 ;
}
else if ( * V_153 == '$' ) {
if ( strncmp ( V_69 , V_13 , strlen ( V_13 ) - 1 ) == 0 ) {
if ( F_45 ( V_69 + strlen ( V_13 ) - 1 ) )
return 1 ;
}
}
else {
if ( strcmp ( V_13 , V_69 ) == 0 )
return 1 ;
}
}
return 0 ;
}
static void F_47 ( const char * V_4 , struct V_30 * V_31 ,
T_4 * V_150 )
{
const char * V_32 = F_44 ( V_31 , V_150 ) ;
if ( V_150 -> V_102 == V_154 &&
! ( V_150 -> V_103 & V_155 ) &&
! F_46 ( V_32 , V_156 ) ) {
F_2 ( L_42
L_43
L_44
L_45 ,
V_4 , V_32 ) ;
}
}
static const struct V_157 * F_48 (
const char * V_158 , const char * V_159 )
{
int V_18 ;
int V_160 = sizeof( V_157 ) / sizeof( struct V_157 ) ;
const struct V_157 * V_161 = & V_157 [ 0 ] ;
for ( V_18 = 0 ; V_18 < V_160 ; V_18 ++ ) {
if ( F_46 ( V_158 , V_161 -> V_158 ) &&
F_46 ( V_159 , V_161 -> V_159 ) )
return V_161 ;
V_161 ++ ;
}
return NULL ;
}
static int F_49 ( const struct V_157 * V_162 ,
const char * V_158 , const char * V_163 ,
const char * V_159 , const char * V_164 )
{
if ( F_46 ( V_159 , V_165 ) &&
F_46 ( V_158 , V_166 ) &&
( strncmp ( V_163 , L_46 , strlen ( L_46 ) ) == 0 ) )
return 0 ;
if ( strcmp ( V_159 , L_47 ) == 0 &&
F_46 ( V_158 , V_166 ) &&
( strncmp ( V_163 , L_48 , strlen ( L_48 ) ) == 0 ) )
return 0 ;
if ( F_46 ( V_159 , V_167 ) &&
F_46 ( V_158 , V_166 ) &&
F_46 ( V_163 , V_162 -> V_168 ) )
return 0 ;
if ( F_46 ( V_158 , V_169 ) &&
F_46 ( V_159 , V_170 ) )
return 0 ;
if ( F_46 ( V_164 , V_171 ) )
return 0 ;
return 1 ;
}
static T_5 * F_50 ( struct V_30 * V_31 , T_7 V_172 ,
T_5 * V_173 )
{
T_5 * V_69 ;
T_5 * V_174 = NULL ;
T_7 V_175 = 20 ;
T_7 V_176 ;
unsigned int V_177 ;
if ( V_173 -> V_122 != 0 )
return V_173 ;
V_177 = F_35 ( V_31 , V_173 ) ;
for ( V_69 = V_31 -> V_115 ; V_69 < V_31 -> V_116 ; V_69 ++ ) {
if ( F_35 ( V_31 , V_69 ) != V_177 )
continue;
if ( F_38 ( V_69 -> V_131 ) == V_178 )
continue;
if ( V_69 -> V_123 == V_172 )
return V_69 ;
V_176 = V_69 -> V_123 - V_172 ;
if ( V_176 < 0 )
V_176 = V_172 - V_69 -> V_123 ;
if ( V_176 < V_175 ) {
V_175 = V_176 ;
V_174 = V_69 ;
}
}
if ( V_175 < 20 )
return V_174 ;
else
return NULL ;
}
static inline int F_51 ( const char * V_28 )
{
return V_28 [ 0 ] == '$' && strchr ( L_49 , V_28 [ 1 ] )
&& ( V_28 [ 2 ] == '\0' || V_28 [ 2 ] == '.' ) ;
}
static inline int F_52 ( struct V_30 * V_31 , T_5 * V_69 )
{
const char * V_12 = V_31 -> V_117 + V_69 -> V_122 ;
if ( ! V_12 || ! strlen ( V_12 ) )
return 0 ;
return ! F_51 ( V_12 ) ;
}
static T_5 * F_53 ( struct V_30 * V_31 , T_8 V_172 ,
const char * V_32 )
{
T_5 * V_69 ;
T_5 * V_174 = NULL ;
T_8 V_175 = ~ 0 ;
for ( V_69 = V_31 -> V_115 ; V_69 < V_31 -> V_116 ; V_69 ++ ) {
const char * V_179 ;
if ( F_54 ( V_69 -> V_121 ) )
continue;
V_179 = F_17 ( V_31 , F_35 ( V_31 , V_69 ) ) ;
if ( strcmp ( V_179 , V_32 ) != 0 )
continue;
if ( ! F_52 ( V_31 , V_69 ) )
continue;
if ( V_69 -> V_123 <= V_172 ) {
if ( ( V_172 - V_69 -> V_123 ) < V_175 ) {
V_175 = V_172 - V_69 -> V_123 ;
V_174 = V_69 ;
} else if ( ( V_172 - V_69 -> V_123 ) == V_175 ) {
V_174 = V_69 ;
}
}
}
return V_174 ;
}
static char * F_55 ( const char * V_14 )
{
if ( F_46 ( V_14 , V_167 ) ) {
char * V_13 = malloc ( 20 ) ;
char * V_180 = V_13 ;
* V_13 ++ = '_' ;
* V_13 ++ = '_' ;
if ( * V_14 == '.' )
V_14 ++ ;
while ( * V_14 && * V_14 != '.' )
* V_13 ++ = * V_14 ++ ;
* V_13 = '\0' ;
if ( * V_14 == '.' )
V_14 ++ ;
if ( strstr ( V_14 , L_50 ) != NULL )
strcat ( V_13 , L_51 ) ;
else if ( strstr ( V_14 , L_52 ) != NULL )
strcat ( V_13 , L_53 ) ;
else
strcat ( V_13 , L_54 ) ;
return V_180 ;
} else {
return F_9 ( L_15 ) ;
}
}
static int F_56 ( T_5 * V_69 )
{
if ( V_69 )
return F_38 ( V_69 -> V_131 ) == V_181 ;
else
return - 1 ;
}
static void F_57 ( const char * const V_182 [ 20 ] )
{
const char * const * V_14 = V_182 ;
while ( * V_14 ) {
fprintf ( V_3 , L_55 , * V_14 ) ;
V_14 ++ ;
if ( * V_14 )
fprintf ( V_3 , L_56 ) ;
}
fprintf ( V_3 , L_57 ) ;
}
static void F_58 ( const char * V_4 ,
const struct V_157 * V_162 ,
const char * V_158 ,
unsigned long long V_183 ,
const char * V_163 ,
int V_184 ,
const char * V_159 , const char * V_164 ,
int V_185 )
{
const char * V_186 , * V_187 ;
const char * V_188 , * V_189 ;
char * V_190 ;
char * V_191 ;
switch ( V_184 ) {
case 0 : V_186 = L_58 ; V_187 = L_15 ; break;
case 1 : V_186 = L_59 ; V_187 = L_60 ; break;
default: V_186 = L_61 ; V_187 = L_15 ; break;
}
switch ( V_185 ) {
case 0 : V_188 = L_58 ; V_189 = L_15 ; break;
case 1 : V_188 = L_59 ; V_189 = L_60 ; break;
default: V_188 = L_61 ; V_189 = L_15 ; break;
}
V_192 ++ ;
if ( ! V_193 )
return;
F_2 ( L_62
L_63 ,
V_4 , V_158 , V_183 , V_186 , V_163 , V_187 , V_188 , V_159 ,
V_164 , V_189 ) ;
switch ( V_162 -> V_162 ) {
case V_194 :
V_190 = F_55 ( V_158 ) ;
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_64
L_65
L_66
L_67 ,
V_190 , V_163 ,
V_188 , V_191 , V_164 , V_189 ,
V_163 , V_191 , V_164 ) ;
free ( V_190 ) ;
free ( V_191 ) ;
break;
case V_195 : {
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_68
L_69
L_70
L_71
L_72 ,
V_163 , V_188 , V_191 , V_164 , V_189 ) ;
F_57 ( V_162 -> V_168 ) ;
free ( V_191 ) ;
break;
}
case V_196 :
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_73
L_74
L_75 ,
V_163 , V_188 , V_188 , V_164 , V_189 , V_191 , V_164 ) ;
free ( V_191 ) ;
break;
case V_197 : {
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_68
L_69
L_70
L_76
L_77 ,
V_163 , V_188 , V_191 , V_164 , V_189 ) ;
F_57 ( V_162 -> V_168 ) ;
free ( V_191 ) ;
break;
}
case V_198 :
case V_199 :
V_190 = F_55 ( V_158 ) ;
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_78
L_79
L_80
L_81 ,
V_186 , V_190 , V_163 , V_187 ,
V_188 , V_191 , V_164 , V_189 ,
V_164 , V_163 , V_164 ) ;
free ( V_190 ) ;
free ( V_191 ) ;
break;
case V_200 :
V_190 = F_55 ( V_158 ) ;
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_78
L_79
L_82
L_83
L_84
L_85
L_86 ,
V_186 , V_190 , V_163 , V_187 ,
V_188 , V_191 , V_164 , V_189 ,
V_191 , V_164 , V_189 ) ;
free ( V_190 ) ;
free ( V_191 ) ;
break;
case V_201 :
V_190 = F_55 ( V_158 ) ;
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_78
L_79
L_82
L_87
L_88
L_85
L_89 ,
V_186 , V_190 , V_163 , V_187 ,
V_188 , V_191 , V_164 , V_189 ,
V_191 , V_164 , V_189 ) ;
free ( V_190 ) ;
free ( V_191 ) ;
break;
case V_202 :
V_191 = F_55 ( V_159 ) ;
fprintf ( V_3 ,
L_90
L_91
L_92 ,
V_164 , V_191 , V_191 , V_164 ) ;
free ( V_191 ) ;
break;
}
fprintf ( V_3 , L_57 ) ;
}
static void F_59 ( const char * V_4 , struct V_30 * V_31 ,
T_9 * V_180 , T_5 * V_69 , const char * V_158 )
{
const char * V_159 ;
const struct V_157 * V_162 ;
V_159 = F_17 ( V_31 , F_35 ( V_31 , V_69 ) ) ;
V_162 = F_48 ( V_158 , V_159 ) ;
if ( V_162 ) {
T_5 * V_188 ;
T_5 * V_186 ;
const char * V_164 ;
const char * V_163 ;
V_186 = F_53 ( V_31 , V_180 -> V_203 , V_158 ) ;
V_163 = F_43 ( V_31 , V_186 ) ;
V_188 = F_50 ( V_31 , V_180 -> V_204 , V_69 ) ;
V_164 = F_43 ( V_31 , V_188 ) ;
if ( F_49 ( V_162 ,
V_158 , V_163 , V_159 , V_164 ) ) {
F_58 ( V_4 , V_162 ,
V_158 , V_180 -> V_203 , V_163 ,
F_56 ( V_186 ) , V_159 , V_164 ,
F_56 ( V_188 ) ) ;
}
}
}
static unsigned int * F_60 ( struct V_30 * V_31 ,
T_4 * V_150 , T_9 * V_180 )
{
T_4 * V_68 = V_31 -> V_68 ;
int V_205 = V_150 -> V_106 ;
return ( void * ) V_31 -> V_67 + V_68 [ V_205 ] . V_105 +
V_180 -> V_203 ;
}
static int F_61 ( struct V_30 * V_31 , T_4 * V_150 , T_9 * V_180 )
{
unsigned int V_206 = F_62 ( V_180 -> V_207 ) ;
unsigned int * V_208 = F_60 ( V_31 , V_150 , V_180 ) ;
switch ( V_206 ) {
case V_209 :
V_180 -> V_204 = F_31 ( * V_208 ) ;
break;
case V_210 :
V_180 -> V_204 = F_31 ( * V_208 ) + 4 ;
if ( V_31 -> V_67 -> V_82 == V_211 )
V_180 -> V_204 += V_180 -> V_203 ;
break;
}
return 0 ;
}
static int F_63 ( struct V_30 * V_31 , T_4 * V_150 , T_9 * V_180 )
{
unsigned int V_206 = F_62 ( V_180 -> V_207 ) ;
switch ( V_206 ) {
case V_212 :
V_180 -> V_204 = ( int ) ( long )
( V_31 -> V_115 + F_64 ( V_180 -> V_207 ) ) ;
break;
case V_213 :
case V_214 :
case V_215 :
V_180 -> V_204 = ( int ) ( long ) ( V_31 -> V_67 +
V_150 -> V_105 +
( V_180 -> V_203 - V_150 -> V_104 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_65 ( struct V_30 * V_31 , T_4 * V_150 , T_9 * V_180 )
{
unsigned int V_206 = F_62 ( V_180 -> V_207 ) ;
unsigned int * V_208 = F_60 ( V_31 , V_150 , V_180 ) ;
unsigned int V_216 ;
if ( V_206 == V_217 )
return 1 ;
V_216 = F_31 ( * V_208 ) ;
switch ( V_206 ) {
case V_218 :
V_180 -> V_204 = V_216 & 0xffff ;
break;
case V_219 :
V_180 -> V_204 = ( V_216 & 0x03ffffff ) << 2 ;
break;
case V_220 :
V_180 -> V_204 = V_216 ;
break;
}
return 0 ;
}
static void F_66 ( const char * V_4 , struct V_30 * V_31 ,
T_4 * V_150 )
{
T_5 * V_69 ;
T_9 * V_221 ;
T_9 V_180 ;
unsigned int V_222 ;
const char * V_158 ;
T_9 * V_223 = ( void * ) V_31 -> V_67 + V_150 -> V_105 ;
T_9 * V_224 = ( void * ) V_223 + V_150 -> V_97 ;
V_158 = F_44 ( V_31 , V_150 ) ;
V_158 += strlen ( L_93 ) ;
if ( F_46 ( V_158 , V_156 ) )
return;
for ( V_221 = V_223 ; V_221 < V_224 ; V_221 ++ ) {
V_180 . V_203 = F_31 ( V_221 -> V_203 ) ;
#if V_225 == V_226
if ( V_31 -> V_67 -> V_83 == V_227 ) {
unsigned int V_206 ;
V_222 = F_67 ( V_221 -> V_207 ) ;
V_222 = F_31 ( V_222 ) ;
V_206 = F_68 ( V_221 -> V_207 ) ;
V_180 . V_207 = F_69 ( V_222 , V_206 ) ;
} else {
V_180 . V_207 = F_31 ( V_221 -> V_207 ) ;
V_222 = F_64 ( V_180 . V_207 ) ;
}
#else
V_180 . V_207 = F_31 ( V_221 -> V_207 ) ;
V_222 = F_64 ( V_180 . V_207 ) ;
#endif
V_180 . V_204 = F_31 ( V_221 -> V_204 ) ;
V_69 = V_31 -> V_115 + V_222 ;
if ( F_54 ( V_69 -> V_121 ) )
continue;
F_59 ( V_4 , V_31 , & V_180 , V_69 , V_158 ) ;
}
}
static void F_70 ( const char * V_4 , struct V_30 * V_31 ,
T_4 * V_150 )
{
T_5 * V_69 ;
T_10 * V_228 ;
T_9 V_180 ;
unsigned int V_222 ;
const char * V_158 ;
T_10 * V_223 = ( void * ) V_31 -> V_67 + V_150 -> V_105 ;
T_10 * V_224 = ( void * ) V_223 + V_150 -> V_97 ;
V_158 = F_44 ( V_31 , V_150 ) ;
V_158 += strlen ( L_94 ) ;
if ( F_46 ( V_158 , V_156 ) )
return;
for ( V_228 = V_223 ; V_228 < V_224 ; V_228 ++ ) {
V_180 . V_203 = F_31 ( V_228 -> V_203 ) ;
#if V_225 == V_226
if ( V_31 -> V_67 -> V_83 == V_227 ) {
unsigned int V_206 ;
V_222 = F_67 ( V_228 -> V_207 ) ;
V_222 = F_31 ( V_222 ) ;
V_206 = F_68 ( V_228 -> V_207 ) ;
V_180 . V_207 = F_69 ( V_222 , V_206 ) ;
} else {
V_180 . V_207 = F_31 ( V_228 -> V_207 ) ;
V_222 = F_64 ( V_180 . V_207 ) ;
}
#else
V_180 . V_207 = F_31 ( V_228 -> V_207 ) ;
V_222 = F_64 ( V_180 . V_207 ) ;
#endif
V_180 . V_204 = 0 ;
switch ( V_31 -> V_67 -> V_83 ) {
case V_229 :
if ( F_61 ( V_31 , V_150 , & V_180 ) )
continue;
break;
case V_230 :
if ( F_63 ( V_31 , V_150 , & V_180 ) )
continue;
break;
case V_227 :
if ( F_65 ( V_31 , V_150 , & V_180 ) )
continue;
break;
}
V_69 = V_31 -> V_115 + V_222 ;
if ( F_54 ( V_69 -> V_121 ) )
continue;
F_59 ( V_4 , V_31 , & V_180 , V_69 , V_158 ) ;
}
}
static void F_71 ( struct V_8 * V_9 , const char * V_4 ,
struct V_30 * V_31 )
{
int V_18 ;
T_4 * V_68 = V_31 -> V_68 ;
for ( V_18 = 0 ; V_18 < V_31 -> V_96 ; V_18 ++ ) {
F_47 ( V_4 , V_31 , & V_31 -> V_68 [ V_18 ] ) ;
if ( V_68 [ V_18 ] . V_102 == V_231 )
F_66 ( V_4 , V_31 , & V_31 -> V_68 [ V_18 ] ) ;
else if ( V_68 [ V_18 ] . V_102 == V_232 )
F_70 ( V_4 , V_31 , & V_31 -> V_68 [ V_18 ] ) ;
}
}
static void F_72 ( char * V_4 )
{
const char * V_124 ;
char * V_233 ;
char * V_234 ;
struct V_8 * V_9 ;
struct V_30 V_66 = { } ;
T_5 * V_69 ;
if ( ! F_30 ( & V_66 , V_4 ) )
return;
V_9 = F_7 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
V_235 = 1 ;
V_9 -> V_64 = 1 ;
}
V_234 = F_41 ( V_66 . V_111 , V_66 . V_112 , L_95 ) ;
if ( V_66 . V_111 && ! V_234 && ! F_4 ( V_4 ) )
F_2 ( L_96
L_97
L_98 , V_4 ) ;
while ( V_234 ) {
if ( F_73 ( V_234 ) )
V_9 -> V_16 = 1 ;
else {
V_9 -> V_16 = 0 ;
break;
}
V_234 = F_40 ( V_66 . V_111 , V_66 . V_112 ,
L_95 , V_234 ) ;
}
for ( V_69 = V_66 . V_115 ; V_69 < V_66 . V_116 ; V_69 ++ ) {
V_124 = V_66 . V_117 + V_69 -> V_122 ;
F_34 ( V_9 , & V_66 , V_69 , V_124 ) ;
F_74 ( V_9 , & V_66 , V_69 , V_124 ) ;
}
if ( ! F_4 ( V_4 ) ||
( F_4 ( V_4 ) && V_236 ) )
F_71 ( V_9 , V_4 , & V_66 ) ;
V_233 = F_41 ( V_66 . V_111 , V_66 . V_112 , L_99 ) ;
if ( V_233 )
F_75 ( V_4 , V_233 , V_66 . V_111 ,
V_233 - ( char * ) V_66 . V_67 ) ;
if ( V_233 || ( V_237 && ! F_4 ( V_4 ) ) )
F_76 ( V_4 , V_9 -> V_238 ,
sizeof( V_9 -> V_238 ) - 1 ) ;
F_32 ( & V_66 ) ;
if ( V_239 )
V_9 -> V_139 = F_11 ( L_100 , 0 , V_9 -> V_139 ) ;
}
void F_77 ( struct V_240 * V_241 , const char * V_14 , int V_65 )
{
if ( V_241 -> V_50 - V_241 -> V_62 < V_65 ) {
V_241 -> V_50 += V_65 + V_242 ;
V_241 -> V_13 = realloc ( V_241 -> V_13 , V_241 -> V_50 ) ;
}
strncpy ( V_241 -> V_13 + V_241 -> V_62 , V_14 , V_65 ) ;
V_241 -> V_62 += V_65 ;
}
static void F_78 ( enum V_21 exp , const char * V_243 , const char * V_14 )
{
const char * V_244 = F_4 ( V_243 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_36 :
F_1 ( L_101
L_102 , V_243 , V_244 , V_14 ) ;
break;
case V_37 :
F_1 ( L_101
L_103 , V_243 , V_244 , V_14 ) ;
break;
case V_38 :
F_2 ( L_101
L_104 , V_243 , V_244 , V_14 ) ;
break;
case V_34 :
case V_35 :
case V_29 :
break;
}
}
static void F_79 ( enum V_21 exp , const char * V_243 , const char * V_14 )
{
const char * V_244 = F_4 ( V_243 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_35 :
case V_37 :
F_2 ( L_105
L_106 , V_243 , V_244 , V_14 ) ;
break;
default:
break;
}
}
static void F_80 ( struct V_8 * V_9 )
{
struct V_19 * V_14 , * exp ;
for ( V_14 = V_9 -> V_139 ; V_14 ; V_14 = V_14 -> V_11 ) {
const char * V_245 ;
exp = F_13 ( V_14 -> V_12 ) ;
if ( ! exp || exp -> V_8 == V_9 )
continue;
V_245 = strrchr ( V_9 -> V_12 , '/' ) ;
if ( V_245 )
V_245 ++ ;
else
V_245 = V_9 -> V_12 ;
if ( ! V_9 -> V_16 )
F_78 ( exp -> V_21 , V_245 , exp -> V_12 ) ;
F_79 ( exp -> V_21 , V_245 , exp -> V_12 ) ;
}
}
static void F_81 ( struct V_240 * V_246 , struct V_8 * V_9 )
{
F_82 ( V_246 , L_107 ) ;
F_82 ( V_246 , L_108 ) ;
F_82 ( V_246 , L_109 ) ;
F_82 ( V_246 , L_57 ) ;
F_82 ( V_246 , L_110 ) ;
F_82 ( V_246 , L_57 ) ;
F_82 ( V_246 , L_111 ) ;
F_82 ( V_246 , L_112 ) ;
F_82 ( V_246 , L_113 ) ;
if ( V_9 -> V_141 )
F_82 ( V_246 , L_114 ) ;
if ( V_9 -> V_142 )
F_82 ( V_246 , L_115
L_116
L_117 ) ;
F_82 ( V_246 , L_118 ) ;
F_82 ( V_246 , L_119 ) ;
}
static void F_83 ( struct V_240 * V_246 , int V_247 )
{
if ( V_247 )
F_82 ( V_246 , L_120 ) ;
}
static void F_84 ( struct V_240 * V_246 , const char * V_12 )
{
static const char * V_248 = L_121 ;
if ( strncmp ( V_248 , V_12 , strlen ( V_248 ) ) == 0 )
F_82 ( V_246 , L_122 ) ;
}
static int F_85 ( struct V_240 * V_246 , struct V_8 * V_9 )
{
struct V_19 * V_14 , * exp ;
int V_249 = 0 ;
for ( V_14 = V_9 -> V_139 ; V_14 ; V_14 = V_14 -> V_11 ) {
exp = F_13 ( V_14 -> V_12 ) ;
if ( ! exp || exp -> V_8 == V_9 ) {
if ( V_235 && ! V_14 -> V_20 ) {
if ( V_250 ) {
F_2 ( L_123 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
} else {
F_3 ( L_123 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
V_249 = 1 ;
}
}
continue;
}
V_14 -> V_8 = exp -> V_8 ;
V_14 -> V_48 = exp -> V_48 ;
V_14 -> V_47 = exp -> V_47 ;
}
if ( ! V_239 )
return V_249 ;
F_82 ( V_246 , L_57 ) ;
F_82 ( V_246 , L_124 ) ;
F_82 ( V_246 , L_125 ) ;
F_82 ( V_246 , L_126 ) ;
for ( V_14 = V_9 -> V_139 ; V_14 ; V_14 = V_14 -> V_11 ) {
if ( ! V_14 -> V_8 )
continue;
if ( ! V_14 -> V_48 ) {
F_2 ( L_127 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
continue;
}
F_82 ( V_246 , L_128 , V_14 -> V_47 , V_14 -> V_12 ) ;
}
F_82 ( V_246 , L_119 ) ;
return V_249 ;
}
static void F_86 ( struct V_240 * V_246 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_19 * V_14 ;
struct V_8 * V_243 ;
int V_251 = 1 ;
for ( V_243 = V_10 ; V_243 ; V_243 = V_243 -> V_11 )
V_243 -> V_252 = F_4 ( V_243 -> V_12 ) ;
F_82 ( V_246 , L_57 ) ;
F_82 ( V_246 , L_129 ) ;
F_82 ( V_246 , L_125 ) ;
F_82 ( V_246 , L_130 ) ;
F_82 ( V_246 , L_131 ) ;
for ( V_14 = V_9 -> V_139 ; V_14 ; V_14 = V_14 -> V_11 ) {
const char * V_13 ;
if ( ! V_14 -> V_8 )
continue;
if ( V_14 -> V_8 -> V_252 )
continue;
V_14 -> V_8 -> V_252 = 1 ;
V_13 = strrchr ( V_14 -> V_8 -> V_12 , '/' ) ;
if ( V_13 )
V_13 ++ ;
else
V_13 = V_14 -> V_8 -> V_12 ;
F_82 ( V_246 , L_132 , V_251 ? L_15 : L_133 , V_13 ) ;
V_251 = 0 ;
}
F_82 ( V_246 , L_134 ) ;
}
static void F_87 ( struct V_240 * V_246 , struct V_8 * V_9 )
{
if ( V_9 -> V_238 [ 0 ] ) {
F_82 ( V_246 , L_57 ) ;
F_82 ( V_246 , L_135 ,
V_9 -> V_238 ) ;
}
}
static void F_88 ( struct V_240 * V_246 , const char * V_253 )
{
char * V_254 ;
T_11 * V_63 ;
struct V_51 V_52 ;
V_63 = fopen ( V_253 , L_136 ) ;
if ( ! V_63 )
goto V_255;
if ( F_24 ( fileno ( V_63 ) , & V_52 ) < 0 )
goto V_256;
if ( V_52 . V_58 != V_246 -> V_62 )
goto V_256;
V_254 = F_8 ( malloc ( V_246 -> V_62 ) ) ;
if ( fread ( V_254 , 1 , V_246 -> V_62 , V_63 ) != V_246 -> V_62 )
goto V_257;
if ( memcmp ( V_254 , V_246 -> V_13 , V_246 -> V_62 ) != 0 )
goto V_257;
free ( V_254 ) ;
fclose ( V_63 ) ;
return;
V_257:
free ( V_254 ) ;
V_256:
fclose ( V_63 ) ;
V_255:
V_63 = fopen ( V_253 , L_137 ) ;
if ( ! V_63 ) {
perror ( V_253 ) ;
exit ( 1 ) ;
}
if ( fwrite ( V_246 -> V_13 , 1 , V_246 -> V_62 , V_63 ) != V_246 -> V_62 ) {
perror ( V_253 ) ;
exit ( 1 ) ;
}
fclose ( V_63 ) ;
}
static void F_89 ( const char * V_253 , unsigned int V_46 )
{
unsigned long V_50 , V_62 = 0 ;
void * V_63 = F_22 ( V_253 , & V_50 ) ;
char * line ;
if ( ! V_63 )
return;
while ( ( line = F_27 ( & V_62 , V_63 , V_50 ) ) ) {
char * V_124 , * V_4 , * V_176 , * V_21 , * V_258 ;
unsigned int V_47 ;
struct V_8 * V_9 ;
struct V_19 * V_14 ;
if ( ! ( V_124 = strchr ( line , '\t' ) ) )
goto V_259;
* V_124 ++ = '\0' ;
if ( ! ( V_4 = strchr ( V_124 , '\t' ) ) )
goto V_259;
* V_4 ++ = '\0' ;
if ( ( V_21 = strchr ( V_4 , '\t' ) ) != NULL )
* V_21 ++ = '\0' ;
if ( V_21 && ( ( V_258 = strchr ( V_21 , '\t' ) ) != NULL ) )
* V_258 = '\0' ;
V_47 = strtoul ( line , & V_176 , 16 ) ;
if ( * V_124 == '\0' || * V_4 == '\0' || * V_176 != '\0' )
goto V_259;
V_9 = F_6 ( V_4 ) ;
if ( ! V_9 ) {
if ( F_4 ( V_4 ) )
V_235 = 1 ;
V_9 = F_7 ( V_4 ) ;
V_9 -> V_64 = 1 ;
}
V_14 = F_20 ( V_124 , V_9 , F_15 ( V_21 ) ) ;
V_14 -> V_46 = V_46 ;
V_14 -> V_44 = 1 ;
F_21 ( V_124 , V_9 , V_47 , F_15 ( V_21 ) ) ;
}
return;
V_259:
F_1 ( L_138 ) ;
}
static int F_90 ( struct V_19 * V_69 )
{
if ( ! V_260 )
return 1 ;
if ( V_69 -> V_45 || V_69 -> V_46 )
return 0 ;
return 1 ;
}
static void F_91 ( const char * V_253 )
{
struct V_240 V_241 = { } ;
struct V_19 * V_19 ;
int V_261 ;
for ( V_261 = 0 ; V_261 < V_24 ; V_261 ++ ) {
V_19 = V_25 [ V_261 ] ;
while ( V_19 ) {
if ( F_90 ( V_19 ) )
F_82 ( & V_241 , L_139 ,
V_19 -> V_47 , V_19 -> V_12 ,
V_19 -> V_8 -> V_12 ,
F_14 ( V_19 -> V_21 ) ) ;
V_19 = V_19 -> V_11 ;
}
}
F_88 ( & V_241 , V_253 ) ;
}
int main ( int V_262 , char * * V_263 )
{
struct V_8 * V_9 ;
struct V_240 V_241 = { } ;
char * V_264 = NULL , * V_265 = NULL ;
char * V_266 = NULL ;
int V_267 ;
int V_249 ;
struct V_268 * V_269 ;
struct V_268 * V_270 = NULL ;
while ( ( V_267 = F_92 ( V_262 , V_263 , L_140 ) ) != - 1 ) {
switch ( V_267 ) {
case 'i' :
V_264 = V_271 ;
break;
case 'I' :
V_265 = V_271 ;
V_260 = 1 ;
break;
case 'e' :
V_260 = 1 ;
V_269 =
F_8 ( malloc ( sizeof( * V_269 ) ) ) ;
V_269 -> V_11 = V_270 ;
V_269 -> V_63 = V_271 ;
V_270 = V_269 ;
break;
case 'm' :
V_239 = 1 ;
break;
case 'o' :
V_266 = V_271 ;
break;
case 'a' :
V_237 = 1 ;
break;
case 's' :
V_236 = 0 ;
break;
case 'S' :
V_193 = 0 ;
break;
case 'w' :
V_250 = 1 ;
break;
default:
exit ( 1 ) ;
}
}
if ( V_264 )
F_89 ( V_264 , 1 ) ;
if ( V_265 )
F_89 ( V_265 , 0 ) ;
while ( V_270 ) {
F_89 ( V_270 -> V_63 , 0 ) ;
V_269 = V_270 -> V_11 ;
free ( V_270 ) ;
V_270 = V_269 ;
}
while ( V_272 < V_262 )
F_72 ( V_263 [ V_272 ++ ] ) ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
if ( V_9 -> V_64 )
continue;
F_80 ( V_9 ) ;
}
V_249 = 0 ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
char V_253 [ strlen ( V_9 -> V_12 ) + 10 ] ;
if ( V_9 -> V_64 )
continue;
V_241 . V_62 = 0 ;
F_81 ( & V_241 , V_9 ) ;
F_83 ( & V_241 , ! V_260 ) ;
F_84 ( & V_241 , V_9 -> V_12 ) ;
V_249 |= F_85 ( & V_241 , V_9 ) ;
F_86 ( & V_241 , V_9 , V_10 ) ;
F_93 ( & V_241 , V_9 ) ;
F_87 ( & V_241 , V_9 ) ;
sprintf ( V_253 , L_141 , V_9 -> V_12 ) ;
F_88 ( & V_241 , V_253 ) ;
}
if ( V_266 )
F_91 ( V_266 ) ;
if ( V_192 && ! V_193 )
F_2 ( L_142
L_143
L_144 ,
V_192 ) ;
return V_249 ;
}
