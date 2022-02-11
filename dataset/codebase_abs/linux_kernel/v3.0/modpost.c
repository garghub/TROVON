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
if ( strcmp ( V_14 , L_7 ) == 0 )
* V_14 = '\0' ;
V_9 -> V_12 = V_13 ;
V_9 -> V_15 = - 1 ;
V_9 -> V_11 = V_10 ;
V_10 = V_9 ;
return V_9 ;
}
static inline unsigned int F_10 ( const char * V_12 )
{
unsigned V_16 ;
unsigned V_17 ;
for ( V_16 = 0x238F13AF * strlen ( V_12 ) , V_17 = 0 ; V_12 [ V_17 ] ; V_17 ++ )
V_16 = ( V_16 + ( ( ( unsigned char * ) V_12 ) [ V_17 ] << ( V_17 * 5 % 24 ) ) ) ;
return ( 1103515243 * V_16 + 12345 ) ;
}
static struct V_18 * F_11 ( const char * V_12 , unsigned int V_19 ,
struct V_18 * V_11 )
{
struct V_18 * V_14 = F_8 ( malloc ( sizeof( * V_14 ) + strlen ( V_12 ) + 1 ) ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
strcpy ( V_14 -> V_12 , V_12 ) ;
V_14 -> V_19 = V_19 ;
V_14 -> V_11 = V_11 ;
return V_14 ;
}
static struct V_18 * F_12 ( const char * V_12 , struct V_8 * V_8 ,
enum V_20 V_20 )
{
unsigned int V_21 ;
struct V_18 * V_22 ;
V_21 = F_10 ( V_12 ) % V_23 ;
V_22 = V_24 [ V_21 ] = F_11 ( V_12 , 0 , V_24 [ V_21 ] ) ;
V_22 -> V_8 = V_8 ;
V_22 -> V_20 = V_20 ;
return V_22 ;
}
static struct V_18 * F_13 ( const char * V_12 )
{
struct V_18 * V_14 ;
if ( V_12 [ 0 ] == '.' )
V_12 ++ ;
for ( V_14 = V_24 [ F_10 ( V_12 ) % V_23 ] ; V_14 ; V_14 = V_14 -> V_11 ) {
if ( strcmp ( V_14 -> V_12 , V_12 ) == 0 )
return V_14 ;
}
return NULL ;
}
static const char * F_14 ( enum V_20 V_25 )
{
return V_26 [ V_25 ] . V_27 ;
}
static enum V_20 F_15 ( const char * V_14 )
{
int V_17 ;
if ( ! V_14 )
return V_28 ;
for ( V_17 = 0 ; V_26 [ V_17 ] . V_20 != V_28 ; V_17 ++ ) {
if ( strcmp ( V_26 [ V_17 ] . V_27 , V_14 ) == 0 )
return V_26 [ V_17 ] . V_20 ;
}
return V_28 ;
}
static enum V_20 F_16 ( struct V_29 * V_30 , unsigned int V_31 )
{
if ( V_31 == V_30 -> V_32 )
return V_33 ;
else if ( V_31 == V_30 -> V_34 )
return V_35 ;
else if ( V_31 == V_30 -> V_36 )
return V_37 ;
else if ( V_31 == V_30 -> V_38 )
return V_39 ;
else if ( V_31 == V_30 -> V_40 )
return V_41 ;
else
return V_28 ;
}
static struct V_18 * F_17 ( const char * V_12 , struct V_8 * V_9 ,
enum V_20 V_20 )
{
struct V_18 * V_14 = F_13 ( V_12 ) ;
if ( ! V_14 ) {
V_14 = F_12 ( V_12 , V_9 , V_20 ) ;
} else {
if ( ! V_14 -> V_42 ) {
F_2 ( L_8
L_9 , V_9 -> V_12 , V_12 ,
V_14 -> V_8 -> V_12 ,
F_4 ( V_14 -> V_8 -> V_12 ) ? L_10 : L_11 ) ;
} else {
V_14 -> V_8 = V_9 ;
}
}
V_14 -> V_42 = 0 ;
V_14 -> V_43 = F_4 ( V_9 -> V_12 ) ;
V_14 -> V_44 = 0 ;
V_14 -> V_20 = V_20 ;
return V_14 ;
}
static void F_18 ( const char * V_12 , struct V_8 * V_9 ,
unsigned int V_45 , enum V_20 V_20 )
{
struct V_18 * V_14 = F_13 ( V_12 ) ;
if ( ! V_14 )
V_14 = F_12 ( V_12 , V_9 , V_20 ) ;
V_14 -> V_45 = V_45 ;
V_14 -> V_46 = 1 ;
}
void * F_19 ( const char * V_47 , unsigned long * V_48 )
{
struct V_49 V_50 ;
void * V_51 ;
int V_52 ;
V_52 = F_20 ( V_47 , V_53 ) ;
if ( V_52 < 0 || F_21 ( V_52 , & V_50 ) != 0 )
return NULL ;
* V_48 = V_50 . V_54 ;
V_51 = F_22 ( NULL , * V_48 , V_55 | V_56 , V_57 , V_52 , 0 ) ;
F_23 ( V_52 ) ;
if ( V_51 == V_58 )
return NULL ;
return V_51 ;
}
char * F_24 ( unsigned long * V_59 , void * V_60 , unsigned long V_48 )
{
static char line [ 4096 ] ;
int V_61 = 1 ;
T_2 V_62 = 0 ;
signed char * V_13 = ( signed char * ) V_60 + * V_59 ;
char * V_14 = line ;
for (; * V_59 < V_48 ; ( * V_59 ) ++ ) {
if ( V_61 && isspace ( * V_13 ) ) {
V_13 ++ ;
continue;
}
V_61 = 0 ;
if ( * V_13 != '\n' && ( * V_59 < V_48 ) ) {
V_62 ++ ;
* V_14 ++ = * V_13 ++ ;
if ( V_62 > 4095 )
break;
} else {
* V_14 = '\0' ;
return line ;
}
}
return NULL ;
}
void F_25 ( void * V_60 , unsigned long V_48 )
{
F_26 ( V_60 , V_48 ) ;
}
static int F_27 ( struct V_29 * V_63 , const char * V_47 )
{
unsigned int V_17 ;
T_3 * V_64 ;
T_4 * V_65 ;
T_5 * V_66 ;
const char * V_67 ;
unsigned int V_68 = ~ 0U , V_69 = ~ 0U ;
V_64 = F_19 ( V_47 , & V_63 -> V_48 ) ;
if ( ! V_64 ) {
perror ( V_47 ) ;
exit ( 1 ) ;
}
V_63 -> V_64 = V_64 ;
if ( V_63 -> V_48 < sizeof( * V_64 ) ) {
return 0 ;
}
if ( ( V_64 -> V_70 [ V_71 ] != V_72 ) ||
( V_64 -> V_70 [ V_73 ] != V_74 ) ||
( V_64 -> V_70 [ V_75 ] != V_76 ) ||
( V_64 -> V_70 [ V_77 ] != V_78 ) ) {
return 0 ;
}
V_64 -> V_79 = F_28 ( V_64 -> V_79 ) ;
V_64 -> V_80 = F_28 ( V_64 -> V_80 ) ;
V_64 -> V_81 = F_28 ( V_64 -> V_81 ) ;
V_64 -> V_82 = F_28 ( V_64 -> V_82 ) ;
V_64 -> V_83 = F_28 ( V_64 -> V_83 ) ;
V_64 -> V_84 = F_28 ( V_64 -> V_84 ) ;
V_64 -> V_85 = F_28 ( V_64 -> V_85 ) ;
V_64 -> V_86 = F_28 ( V_64 -> V_86 ) ;
V_64 -> V_87 = F_28 ( V_64 -> V_87 ) ;
V_64 -> V_88 = F_28 ( V_64 -> V_88 ) ;
V_64 -> V_89 = F_28 ( V_64 -> V_89 ) ;
V_64 -> V_90 = F_28 ( V_64 -> V_90 ) ;
V_64 -> V_91 = F_28 ( V_64 -> V_91 ) ;
V_65 = ( void * ) V_64 + V_64 -> V_84 ;
V_63 -> V_65 = V_65 ;
if ( V_64 -> V_84 > V_63 -> V_48 ) {
F_1 ( L_12
L_13 , ( unsigned long ) V_64 -> V_84 ,
V_47 , V_63 -> V_48 ) ;
return 0 ;
}
if ( V_64 -> V_90 == V_92 ) {
V_63 -> V_93 = F_28 ( V_65 [ 0 ] . V_94 ) ;
}
else {
V_63 -> V_93 = V_64 -> V_90 ;
}
if ( V_64 -> V_91 == V_95 ) {
V_63 -> V_96 = F_28 ( V_65 [ 0 ] . V_97 ) ;
}
else {
V_63 -> V_96 = V_64 -> V_91 ;
}
for ( V_17 = 0 ; V_17 < V_63 -> V_93 ; V_17 ++ ) {
V_65 [ V_17 ] . V_98 = F_28 ( V_65 [ V_17 ] . V_98 ) ;
V_65 [ V_17 ] . V_99 = F_28 ( V_65 [ V_17 ] . V_99 ) ;
V_65 [ V_17 ] . V_100 = F_28 ( V_65 [ V_17 ] . V_100 ) ;
V_65 [ V_17 ] . V_101 = F_28 ( V_65 [ V_17 ] . V_101 ) ;
V_65 [ V_17 ] . V_102 = F_28 ( V_65 [ V_17 ] . V_102 ) ;
V_65 [ V_17 ] . V_94 = F_28 ( V_65 [ V_17 ] . V_94 ) ;
V_65 [ V_17 ] . V_97 = F_28 ( V_65 [ V_17 ] . V_97 ) ;
V_65 [ V_17 ] . V_103 = F_28 ( V_65 [ V_17 ] . V_103 ) ;
V_65 [ V_17 ] . V_104 = F_28 ( V_65 [ V_17 ] . V_104 ) ;
V_65 [ V_17 ] . V_105 = F_28 ( V_65 [ V_17 ] . V_105 ) ;
}
V_67 = ( void * ) V_64 + V_65 [ V_63 -> V_96 ] . V_102 ;
for ( V_17 = 1 ; V_17 < V_63 -> V_93 ; V_17 ++ ) {
const char * V_106 ;
int V_107 = V_65 [ V_17 ] . V_99 == V_108 ;
if ( ! V_107 && V_65 [ V_17 ] . V_102 > V_63 -> V_48 ) {
F_1 ( L_14
L_15 , V_47 ,
( unsigned long ) V_65 [ V_17 ] . V_102 ,
sizeof( * V_64 ) ) ;
return 0 ;
}
V_106 = V_67 + V_65 [ V_17 ] . V_98 ;
if ( strcmp ( V_106 , L_16 ) == 0 ) {
if ( V_107 )
F_1 ( L_17 , V_47 ) ;
V_63 -> V_109 = ( void * ) V_64 + V_65 [ V_17 ] . V_102 ;
V_63 -> V_110 = V_65 [ V_17 ] . V_94 ;
} else if ( strcmp ( V_106 , L_18 ) == 0 )
V_63 -> V_32 = V_17 ;
else if ( strcmp ( V_106 , L_19 ) == 0 )
V_63 -> V_34 = V_17 ;
else if ( strcmp ( V_106 , L_20 ) == 0 )
V_63 -> V_36 = V_17 ;
else if ( strcmp ( V_106 , L_21 ) == 0 )
V_63 -> V_38 = V_17 ;
else if ( strcmp ( V_106 , L_22 ) == 0 )
V_63 -> V_40 = V_17 ;
if ( V_65 [ V_17 ] . V_99 == V_111 ) {
unsigned int V_112 ;
V_68 = V_17 ;
V_63 -> V_113 = ( void * ) V_64 +
V_65 [ V_17 ] . V_102 ;
V_63 -> V_114 = ( void * ) V_64 +
V_65 [ V_17 ] . V_102 + V_65 [ V_17 ] . V_94 ;
V_112 = V_65 [ V_17 ] . V_97 ;
V_63 -> V_115 = ( void * ) V_64 +
V_65 [ V_112 ] . V_102 ;
}
if ( V_65 [ V_17 ] . V_99 == V_116 ) {
V_69 = V_17 ;
V_63 -> V_117 = ( void * ) V_64 +
V_65 [ V_17 ] . V_102 ;
V_63 -> V_118 = ( void * ) V_64 +
V_65 [ V_17 ] . V_102 + V_65 [ V_17 ] . V_94 ;
}
}
if ( ! V_63 -> V_113 )
F_1 ( L_23 , V_47 ) ;
for ( V_66 = V_63 -> V_113 ; V_66 < V_63 -> V_114 ; V_66 ++ ) {
V_66 -> V_119 = F_28 ( V_66 -> V_119 ) ;
V_66 -> V_120 = F_28 ( V_66 -> V_120 ) ;
V_66 -> V_121 = F_28 ( V_66 -> V_121 ) ;
V_66 -> V_54 = F_28 ( V_66 -> V_54 ) ;
}
if ( V_69 != ~ 0U ) {
T_6 * V_13 ;
if ( V_68 != V_65 [ V_69 ] . V_97 )
F_1 ( L_24 ,
V_47 , V_65 [ V_69 ] . V_97 ,
V_68 ) ;
for ( V_13 = V_63 -> V_117 ; V_13 < V_63 -> V_118 ;
V_13 ++ )
* V_13 = F_28 ( * V_13 ) ;
}
return 1 ;
}
static void F_29 ( struct V_29 * V_63 )
{
F_25 ( V_63 -> V_64 , V_63 -> V_48 ) ;
}
static int F_30 ( struct V_29 * V_63 , const char * V_122 )
{
if ( strcmp ( V_122 , V_123 L_25 ) == 0 )
return 1 ;
if ( strcmp ( V_122 , L_26 ) == 0 )
return 1 ;
if ( V_63 -> V_64 -> V_80 == V_124 )
if ( strncmp ( V_122 , L_27 , sizeof( L_27 ) - 1 ) == 0 ||
strncmp ( V_122 , L_28 , sizeof( L_28 ) - 1 ) == 0 ||
strncmp ( V_122 , L_29 , sizeof( L_29 ) - 1 ) == 0 ||
strncmp ( V_122 , L_30 , sizeof( L_30 ) - 1 ) == 0 )
return 1 ;
if ( V_63 -> V_64 -> V_80 == V_125 )
if ( strncmp ( V_122 , L_31 , sizeof( L_31 ) - 1 ) == 0 ||
strncmp ( V_122 , L_32 , sizeof( L_32 ) - 1 ) == 0 )
return 1 ;
return 0 ;
}
static void F_31 ( struct V_8 * V_9 , struct V_29 * V_63 ,
T_5 * V_66 , const char * V_122 )
{
unsigned int V_45 ;
enum V_20 V_20 = F_16 ( V_63 , F_32 ( V_63 , V_66 ) ) ;
switch ( V_66 -> V_119 ) {
case V_126 :
F_2 ( L_33 , V_122 , V_9 -> V_12 ) ;
break;
case V_127 :
if ( strncmp ( V_122 , V_128 , strlen ( V_128 ) ) == 0 ) {
V_45 = ( unsigned int ) V_66 -> V_121 ;
F_18 ( V_122 + strlen ( V_128 ) , V_9 , V_45 ,
V_20 ) ;
}
break;
case V_92 :
if ( F_33 ( V_66 -> V_129 ) != V_130 &&
F_33 ( V_66 -> V_129 ) != V_131 )
break;
if ( F_30 ( V_63 , V_122 ) )
break;
#if F_34 ( V_132 ) || F_34 ( V_133 )
#ifndef V_133
#define V_133 STT_REGISTER
#endif
if ( V_63 -> V_64 -> V_80 == V_134 ||
V_63 -> V_64 -> V_80 == V_135 ) {
if ( F_35 ( V_66 -> V_129 ) == V_133 )
break;
if ( V_122 [ 0 ] == '.' ) {
char * V_136 = F_9 ( V_122 ) ;
V_136 [ 0 ] = '_' ;
V_136 [ 1 ] = toupper ( V_136 [ 1 ] ) ;
V_122 = V_136 ;
}
}
#endif
if ( memcmp ( V_122 , V_123 ,
strlen ( V_123 ) ) == 0 ) {
V_9 -> V_137 =
F_11 ( V_122 +
strlen ( V_123 ) ,
F_33 ( V_66 -> V_129 ) == V_131 ,
V_9 -> V_137 ) ;
}
break;
default:
if ( strncmp ( V_122 , V_138 , strlen ( V_138 ) ) == 0 ) {
F_17 ( V_122 + strlen ( V_138 ) , V_9 ,
V_20 ) ;
}
if ( strcmp ( V_122 , V_123 L_34 ) == 0 )
V_9 -> V_139 = 1 ;
if ( strcmp ( V_122 , V_123 L_35 ) == 0 )
V_9 -> V_140 = 1 ;
break;
}
}
static char * F_36 ( char * string , unsigned long * V_141 )
{
while ( string [ 0 ] ) {
string ++ ;
if ( ( * V_141 ) -- <= 1 )
return NULL ;
}
while ( ! string [ 0 ] ) {
string ++ ;
if ( ( * V_141 ) -- <= 1 )
return NULL ;
}
return string ;
}
static char * F_37 ( void * V_109 , unsigned long V_110 ,
const char * V_142 , char * V_63 )
{
char * V_13 ;
unsigned int V_143 = strlen ( V_142 ) ;
unsigned long V_48 = V_110 ;
if ( V_63 ) {
V_48 -= V_63 - ( char * ) V_109 ;
V_109 = F_36 ( V_63 , & V_48 ) ;
}
for ( V_13 = V_109 ; V_13 ; V_13 = F_36 ( V_13 , & V_48 ) ) {
if ( strncmp ( V_13 , V_142 , V_143 ) == 0 && V_13 [ V_143 ] == '=' )
return V_13 + V_143 + 1 ;
}
return NULL ;
}
static char * F_38 ( void * V_109 , unsigned long V_110 ,
const char * V_142 )
{
return F_37 ( V_109 , V_110 , V_142 , NULL ) ;
}
static int F_39 ( const char * V_14 , const char * V_144 )
{
int V_145 , V_146 ;
if ( ! V_14 || ! V_144 )
return 1 ;
V_145 = strlen ( V_14 ) ;
V_146 = strlen ( V_144 ) ;
if ( ( V_145 == 0 ) || ( V_146 == 0 ) )
return 1 ;
if ( V_146 > V_145 )
return 1 ;
return memcmp ( V_14 + V_145 - V_146 , V_144 , V_146 ) ;
}
static const char * F_40 ( struct V_29 * V_30 , T_5 * V_66 )
{
if ( V_66 )
return V_30 -> V_115 + V_66 -> V_120 ;
else
return L_36 ;
}
static const char * F_41 ( struct V_29 * V_30 , int V_147 )
{
T_4 * V_65 = V_30 -> V_65 ;
return ( void * ) V_30 -> V_64 +
V_30 -> V_65 [ V_30 -> V_96 ] . V_102 +
V_65 [ V_147 ] . V_98 ;
}
static const char * F_42 ( struct V_29 * V_30 , T_4 * V_148 )
{
return ( void * ) V_30 -> V_64 +
V_30 -> V_65 [ V_30 -> V_96 ] . V_102 +
V_148 -> V_98 ;
}
static int F_43 ( const char * V_66 )
{
if ( * V_66 ++ == '\0' )
return 1 ;
if ( * V_66 != '.' )
return 0 ;
do {
char V_149 = * V_66 ++ ;
if ( V_149 < '0' || V_149 > '9' )
return 0 ;
} while ( * V_66 );
return 1 ;
}
static int F_44 ( const char * V_66 , const char * const V_150 [] )
{
const char * V_13 ;
while ( * V_150 ) {
V_13 = * V_150 ++ ;
const char * V_151 = V_13 + strlen ( V_13 ) - 1 ;
if ( * V_13 == '*' ) {
if ( F_39 ( V_66 , V_13 + 1 ) == 0 )
return 1 ;
}
else if ( * V_151 == '*' ) {
if ( strncmp ( V_66 , V_13 , strlen ( V_13 ) - 1 ) == 0 )
return 1 ;
}
else if ( * V_151 == '$' ) {
if ( strncmp ( V_66 , V_13 , strlen ( V_13 ) - 1 ) == 0 ) {
if ( F_43 ( V_66 + strlen ( V_13 ) - 1 ) )
return 1 ;
}
}
else {
if ( strcmp ( V_13 , V_66 ) == 0 )
return 1 ;
}
}
return 0 ;
}
static void F_45 ( const char * V_4 , struct V_29 * V_30 ,
T_4 * V_148 )
{
const char * V_31 = F_42 ( V_30 , V_148 ) ;
if ( V_148 -> V_99 == V_152 &&
! ( V_148 -> V_100 & V_153 ) &&
! F_44 ( V_31 , V_154 ) ) {
F_2 ( L_37
L_38
L_39
L_40 ,
V_4 , V_31 ) ;
}
}
static const struct V_155 * F_46 (
const char * V_156 , const char * V_157 )
{
int V_17 ;
int V_158 = sizeof( V_155 ) / sizeof( struct V_155 ) ;
const struct V_155 * V_159 = & V_155 [ 0 ] ;
for ( V_17 = 0 ; V_17 < V_158 ; V_17 ++ ) {
if ( F_44 ( V_156 , V_159 -> V_156 ) &&
F_44 ( V_157 , V_159 -> V_157 ) )
return V_159 ;
V_159 ++ ;
}
return NULL ;
}
static int F_47 ( const struct V_155 * V_160 ,
const char * V_156 , const char * V_161 ,
const char * V_157 , const char * V_162 )
{
if ( F_44 ( V_157 , V_163 ) &&
F_44 ( V_156 , V_164 ) &&
( strncmp ( V_161 , L_41 , strlen ( L_41 ) ) == 0 ) )
return 0 ;
if ( strcmp ( V_157 , L_42 ) == 0 &&
F_44 ( V_156 , V_164 ) &&
( strncmp ( V_161 , L_43 , strlen ( L_43 ) ) == 0 ) )
return 0 ;
if ( F_44 ( V_157 , V_165 ) &&
F_44 ( V_156 , V_164 ) &&
F_44 ( V_161 , V_160 -> V_166 ) )
return 0 ;
if ( F_44 ( V_156 , V_167 ) &&
F_44 ( V_157 , V_168 ) )
return 0 ;
if ( F_44 ( V_162 , V_169 ) )
return 0 ;
return 1 ;
}
static T_5 * F_48 ( struct V_29 * V_30 , T_7 V_170 ,
T_5 * V_171 )
{
T_5 * V_66 ;
T_5 * V_172 = NULL ;
T_7 V_173 = 20 ;
T_7 V_174 ;
unsigned int V_175 ;
if ( V_171 -> V_120 != 0 )
return V_171 ;
V_175 = F_32 ( V_30 , V_171 ) ;
for ( V_66 = V_30 -> V_113 ; V_66 < V_30 -> V_114 ; V_66 ++ ) {
if ( F_32 ( V_30 , V_66 ) != V_175 )
continue;
if ( F_35 ( V_66 -> V_129 ) == V_176 )
continue;
if ( V_66 -> V_121 == V_170 )
return V_66 ;
V_174 = V_66 -> V_121 - V_170 ;
if ( V_174 < 0 )
V_174 = V_170 - V_66 -> V_121 ;
if ( V_174 < V_173 ) {
V_173 = V_174 ;
V_172 = V_66 ;
}
}
if ( V_173 < 20 )
return V_172 ;
else
return NULL ;
}
static inline int F_49 ( const char * V_27 )
{
return V_27 [ 0 ] == '$' && strchr ( L_44 , V_27 [ 1 ] )
&& ( V_27 [ 2 ] == '\0' || V_27 [ 2 ] == '.' ) ;
}
static inline int F_50 ( struct V_29 * V_30 , T_5 * V_66 )
{
const char * V_12 = V_30 -> V_115 + V_66 -> V_120 ;
if ( ! V_12 || ! strlen ( V_12 ) )
return 0 ;
return ! F_49 ( V_12 ) ;
}
static T_5 * F_51 ( struct V_29 * V_30 , T_8 V_170 ,
const char * V_31 )
{
T_5 * V_66 ;
T_5 * V_172 = NULL ;
T_8 V_173 = ~ 0 ;
for ( V_66 = V_30 -> V_113 ; V_66 < V_30 -> V_114 ; V_66 ++ ) {
const char * V_177 ;
if ( F_52 ( V_66 -> V_119 ) )
continue;
V_177 = F_41 ( V_30 , F_32 ( V_30 , V_66 ) ) ;
if ( strcmp ( V_177 , V_31 ) != 0 )
continue;
if ( ! F_50 ( V_30 , V_66 ) )
continue;
if ( V_66 -> V_121 <= V_170 ) {
if ( ( V_170 - V_66 -> V_121 ) < V_173 ) {
V_173 = V_170 - V_66 -> V_121 ;
V_172 = V_66 ;
} else if ( ( V_170 - V_66 -> V_121 ) == V_173 ) {
V_172 = V_66 ;
}
}
}
return V_172 ;
}
static char * F_53 ( const char * V_14 )
{
if ( F_44 ( V_14 , V_165 ) ) {
char * V_13 = malloc ( 20 ) ;
char * V_178 = V_13 ;
* V_13 ++ = '_' ;
* V_13 ++ = '_' ;
if ( * V_14 == '.' )
V_14 ++ ;
while ( * V_14 && * V_14 != '.' )
* V_13 ++ = * V_14 ++ ;
* V_13 = '\0' ;
if ( * V_14 == '.' )
V_14 ++ ;
if ( strstr ( V_14 , L_45 ) != NULL )
strcat ( V_13 , L_46 ) ;
else if ( strstr ( V_14 , L_47 ) != NULL )
strcat ( V_13 , L_48 ) ;
else
strcat ( V_13 , L_49 ) ;
return V_178 ;
} else {
return F_9 ( L_10 ) ;
}
}
static int F_54 ( T_5 * V_66 )
{
if ( V_66 )
return F_35 ( V_66 -> V_129 ) == V_179 ;
else
return - 1 ;
}
static void F_55 ( const char * const V_180 [ 20 ] )
{
const char * const * V_14 = V_180 ;
while ( * V_14 ) {
fprintf ( V_3 , L_50 , * V_14 ) ;
V_14 ++ ;
if ( * V_14 )
fprintf ( V_3 , L_51 ) ;
}
fprintf ( V_3 , L_52 ) ;
}
static void F_56 ( const char * V_4 ,
const struct V_155 * V_160 ,
const char * V_156 ,
unsigned long long V_181 ,
const char * V_161 ,
int V_182 ,
const char * V_157 , const char * V_162 ,
int V_183 )
{
const char * V_184 , * V_185 ;
const char * V_186 , * V_187 ;
char * V_188 ;
char * V_189 ;
switch ( V_182 ) {
case 0 : V_184 = L_53 ; V_185 = L_10 ; break;
case 1 : V_184 = L_54 ; V_185 = L_55 ; break;
default: V_184 = L_56 ; V_185 = L_10 ; break;
}
switch ( V_183 ) {
case 0 : V_186 = L_53 ; V_187 = L_10 ; break;
case 1 : V_186 = L_54 ; V_187 = L_55 ; break;
default: V_186 = L_56 ; V_187 = L_10 ; break;
}
V_190 ++ ;
if ( ! V_191 )
return;
F_2 ( L_57
L_58 ,
V_4 , V_156 , V_181 , V_184 , V_161 , V_185 , V_186 , V_157 ,
V_162 , V_187 ) ;
switch ( V_160 -> V_160 ) {
case V_192 :
V_188 = F_53 ( V_156 ) ;
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_59
L_60
L_61
L_62 ,
V_188 , V_161 ,
V_186 , V_189 , V_162 , V_187 ,
V_161 , V_189 , V_162 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_193 : {
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_63
L_64
L_65
L_66
L_67 ,
V_161 , V_186 , V_189 , V_162 , V_187 ) ;
F_55 ( V_160 -> V_166 ) ;
free ( V_189 ) ;
break;
}
case V_194 :
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_68
L_69
L_70 ,
V_161 , V_186 , V_186 , V_162 , V_187 , V_189 , V_162 ) ;
free ( V_189 ) ;
break;
case V_195 : {
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_63
L_64
L_65
L_71
L_72 ,
V_161 , V_186 , V_189 , V_162 , V_187 ) ;
F_55 ( V_160 -> V_166 ) ;
free ( V_189 ) ;
break;
}
case V_196 :
case V_197 :
V_188 = F_53 ( V_156 ) ;
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_73
L_74
L_75
L_76 ,
V_184 , V_188 , V_161 , V_185 ,
V_186 , V_189 , V_162 , V_187 ,
V_162 , V_161 , V_162 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_198 :
V_188 = F_53 ( V_156 ) ;
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_73
L_74
L_77
L_78
L_79
L_80
L_81 ,
V_184 , V_188 , V_161 , V_185 ,
V_186 , V_189 , V_162 , V_187 ,
V_189 , V_162 , V_187 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_199 :
V_188 = F_53 ( V_156 ) ;
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_73
L_74
L_77
L_82
L_83
L_80
L_84 ,
V_184 , V_188 , V_161 , V_185 ,
V_186 , V_189 , V_162 , V_187 ,
V_189 , V_162 , V_187 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_200 :
V_189 = F_53 ( V_157 ) ;
fprintf ( V_3 ,
L_85
L_86
L_87 ,
V_162 , V_189 , V_189 , V_162 ) ;
free ( V_189 ) ;
break;
}
fprintf ( V_3 , L_52 ) ;
}
static void F_57 ( const char * V_4 , struct V_29 * V_30 ,
T_9 * V_178 , T_5 * V_66 , const char * V_156 )
{
const char * V_157 ;
const struct V_155 * V_160 ;
V_157 = F_41 ( V_30 , F_32 ( V_30 , V_66 ) ) ;
V_160 = F_46 ( V_156 , V_157 ) ;
if ( V_160 ) {
T_5 * V_186 ;
T_5 * V_184 ;
const char * V_162 ;
const char * V_161 ;
V_184 = F_51 ( V_30 , V_178 -> V_201 , V_156 ) ;
V_161 = F_40 ( V_30 , V_184 ) ;
V_186 = F_48 ( V_30 , V_178 -> V_202 , V_66 ) ;
V_162 = F_40 ( V_30 , V_186 ) ;
if ( F_47 ( V_160 ,
V_156 , V_161 , V_157 , V_162 ) ) {
F_56 ( V_4 , V_160 ,
V_156 , V_178 -> V_201 , V_161 ,
F_54 ( V_184 ) , V_157 , V_162 ,
F_54 ( V_186 ) ) ;
}
}
}
static unsigned int * F_58 ( struct V_29 * V_30 ,
T_4 * V_148 , T_9 * V_178 )
{
T_4 * V_65 = V_30 -> V_65 ;
int V_203 = V_148 -> V_103 ;
return ( void * ) V_30 -> V_64 + V_65 [ V_203 ] . V_102 +
V_178 -> V_201 ;
}
static int F_59 ( struct V_29 * V_30 , T_4 * V_148 , T_9 * V_178 )
{
unsigned int V_204 = F_60 ( V_178 -> V_205 ) ;
unsigned int * V_206 = F_58 ( V_30 , V_148 , V_178 ) ;
switch ( V_204 ) {
case V_207 :
V_178 -> V_202 = F_28 ( * V_206 ) ;
break;
case V_208 :
V_178 -> V_202 = F_28 ( * V_206 ) + 4 ;
if ( V_30 -> V_64 -> V_79 == V_209 )
V_178 -> V_202 += V_178 -> V_201 ;
break;
}
return 0 ;
}
static int F_61 ( struct V_29 * V_30 , T_4 * V_148 , T_9 * V_178 )
{
unsigned int V_204 = F_60 ( V_178 -> V_205 ) ;
switch ( V_204 ) {
case V_210 :
V_178 -> V_202 = ( int ) ( long )
( V_30 -> V_113 + F_62 ( V_178 -> V_205 ) ) ;
break;
case V_211 :
V_178 -> V_202 = ( int ) ( long ) ( V_30 -> V_64 +
V_148 -> V_102 +
( V_178 -> V_201 - V_148 -> V_101 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_63 ( struct V_29 * V_30 , T_4 * V_148 , T_9 * V_178 )
{
unsigned int V_204 = F_60 ( V_178 -> V_205 ) ;
unsigned int * V_206 = F_58 ( V_30 , V_148 , V_178 ) ;
unsigned int V_212 ;
if ( V_204 == V_213 )
return 1 ;
V_212 = F_28 ( * V_206 ) ;
switch ( V_204 ) {
case V_214 :
V_178 -> V_202 = V_212 & 0xffff ;
break;
case V_215 :
V_178 -> V_202 = ( V_212 & 0x03ffffff ) << 2 ;
break;
case V_216 :
V_178 -> V_202 = V_212 ;
break;
}
return 0 ;
}
static void F_64 ( const char * V_4 , struct V_29 * V_30 ,
T_4 * V_148 )
{
T_5 * V_66 ;
T_9 * V_217 ;
T_9 V_178 ;
unsigned int V_218 ;
const char * V_156 ;
T_9 * V_219 = ( void * ) V_30 -> V_64 + V_148 -> V_102 ;
T_9 * V_220 = ( void * ) V_219 + V_148 -> V_94 ;
V_156 = F_42 ( V_30 , V_148 ) ;
V_156 += strlen ( L_88 ) ;
if ( F_44 ( V_156 , V_154 ) )
return;
for ( V_217 = V_219 ; V_217 < V_220 ; V_217 ++ ) {
V_178 . V_201 = F_28 ( V_217 -> V_201 ) ;
#if V_221 == V_222
if ( V_30 -> V_64 -> V_80 == V_223 ) {
unsigned int V_204 ;
V_218 = F_65 ( V_217 -> V_205 ) ;
V_218 = F_28 ( V_218 ) ;
V_204 = F_66 ( V_217 -> V_205 ) ;
V_178 . V_205 = F_67 ( V_218 , V_204 ) ;
} else {
V_178 . V_205 = F_28 ( V_217 -> V_205 ) ;
V_218 = F_62 ( V_178 . V_205 ) ;
}
#else
V_178 . V_205 = F_28 ( V_217 -> V_205 ) ;
V_218 = F_62 ( V_178 . V_205 ) ;
#endif
V_178 . V_202 = F_28 ( V_217 -> V_202 ) ;
V_66 = V_30 -> V_113 + V_218 ;
if ( F_52 ( V_66 -> V_119 ) )
continue;
F_57 ( V_4 , V_30 , & V_178 , V_66 , V_156 ) ;
}
}
static void F_68 ( const char * V_4 , struct V_29 * V_30 ,
T_4 * V_148 )
{
T_5 * V_66 ;
T_10 * V_224 ;
T_9 V_178 ;
unsigned int V_218 ;
const char * V_156 ;
T_10 * V_219 = ( void * ) V_30 -> V_64 + V_148 -> V_102 ;
T_10 * V_220 = ( void * ) V_219 + V_148 -> V_94 ;
V_156 = F_42 ( V_30 , V_148 ) ;
V_156 += strlen ( L_89 ) ;
if ( F_44 ( V_156 , V_154 ) )
return;
for ( V_224 = V_219 ; V_224 < V_220 ; V_224 ++ ) {
V_178 . V_201 = F_28 ( V_224 -> V_201 ) ;
#if V_221 == V_222
if ( V_30 -> V_64 -> V_80 == V_223 ) {
unsigned int V_204 ;
V_218 = F_65 ( V_224 -> V_205 ) ;
V_218 = F_28 ( V_218 ) ;
V_204 = F_66 ( V_224 -> V_205 ) ;
V_178 . V_205 = F_67 ( V_218 , V_204 ) ;
} else {
V_178 . V_205 = F_28 ( V_224 -> V_205 ) ;
V_218 = F_62 ( V_178 . V_205 ) ;
}
#else
V_178 . V_205 = F_28 ( V_224 -> V_205 ) ;
V_218 = F_62 ( V_178 . V_205 ) ;
#endif
V_178 . V_202 = 0 ;
switch ( V_30 -> V_64 -> V_80 ) {
case V_225 :
if ( F_59 ( V_30 , V_148 , & V_178 ) )
continue;
break;
case V_226 :
if ( F_61 ( V_30 , V_148 , & V_178 ) )
continue;
break;
case V_223 :
if ( F_63 ( V_30 , V_148 , & V_178 ) )
continue;
break;
}
V_66 = V_30 -> V_113 + V_218 ;
if ( F_52 ( V_66 -> V_119 ) )
continue;
F_57 ( V_4 , V_30 , & V_178 , V_66 , V_156 ) ;
}
}
static void F_69 ( struct V_8 * V_9 , const char * V_4 ,
struct V_29 * V_30 )
{
int V_17 ;
T_4 * V_65 = V_30 -> V_65 ;
for ( V_17 = 0 ; V_17 < V_30 -> V_93 ; V_17 ++ ) {
F_45 ( V_4 , V_30 , & V_30 -> V_65 [ V_17 ] ) ;
if ( V_65 [ V_17 ] . V_99 == V_227 )
F_64 ( V_4 , V_30 , & V_30 -> V_65 [ V_17 ] ) ;
else if ( V_65 [ V_17 ] . V_99 == V_228 )
F_68 ( V_4 , V_30 , & V_30 -> V_65 [ V_17 ] ) ;
}
}
static void F_70 ( char * V_4 )
{
const char * V_122 ;
char * V_229 ;
char * V_230 ;
struct V_8 * V_9 ;
struct V_29 V_63 = { } ;
T_5 * V_66 ;
if ( ! F_27 ( & V_63 , V_4 ) )
return;
V_9 = F_7 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
V_231 = 1 ;
V_9 -> V_61 = 1 ;
}
V_230 = F_38 ( V_63 . V_109 , V_63 . V_110 , L_90 ) ;
if ( V_63 . V_109 && ! V_230 && ! F_4 ( V_4 ) )
F_2 ( L_91
L_92
L_93 , V_4 ) ;
while ( V_230 ) {
if ( F_71 ( V_230 ) )
V_9 -> V_15 = 1 ;
else {
V_9 -> V_15 = 0 ;
break;
}
V_230 = F_37 ( V_63 . V_109 , V_63 . V_110 ,
L_90 , V_230 ) ;
}
for ( V_66 = V_63 . V_113 ; V_66 < V_63 . V_114 ; V_66 ++ ) {
V_122 = V_63 . V_115 + V_66 -> V_120 ;
F_31 ( V_9 , & V_63 , V_66 , V_122 ) ;
F_72 ( V_9 , & V_63 , V_66 , V_122 ) ;
}
if ( ! F_4 ( V_4 ) ||
( F_4 ( V_4 ) && V_232 ) )
F_69 ( V_9 , V_4 , & V_63 ) ;
V_229 = F_38 ( V_63 . V_109 , V_63 . V_110 , L_94 ) ;
if ( V_229 )
F_73 ( V_4 , V_229 , V_63 . V_109 ,
V_229 - ( char * ) V_63 . V_64 ) ;
if ( V_229 || ( V_233 && ! F_4 ( V_4 ) ) )
F_74 ( V_4 , V_9 -> V_234 ,
sizeof( V_9 -> V_234 ) - 1 ) ;
F_29 ( & V_63 ) ;
if ( V_235 )
V_9 -> V_137 = F_11 ( L_95 , 0 , V_9 -> V_137 ) ;
}
void F_75 ( struct V_236 * V_237 , const char * V_14 , int V_62 )
{
if ( V_237 -> V_48 - V_237 -> V_59 < V_62 ) {
V_237 -> V_48 += V_62 + V_238 ;
V_237 -> V_13 = realloc ( V_237 -> V_13 , V_237 -> V_48 ) ;
}
strncpy ( V_237 -> V_13 + V_237 -> V_59 , V_14 , V_62 ) ;
V_237 -> V_59 += V_62 ;
}
static void F_76 ( enum V_20 exp , const char * V_239 , const char * V_14 )
{
const char * V_240 = F_4 ( V_239 ) ? L_10 : L_11 ;
switch ( exp ) {
case V_37 :
F_1 ( L_96
L_97 , V_239 , V_240 , V_14 ) ;
break;
case V_39 :
F_1 ( L_96
L_98 , V_239 , V_240 , V_14 ) ;
break;
case V_41 :
F_2 ( L_96
L_99 , V_239 , V_240 , V_14 ) ;
break;
case V_33 :
case V_35 :
case V_28 :
break;
}
}
static void F_77 ( enum V_20 exp , const char * V_239 , const char * V_14 )
{
const char * V_240 = F_4 ( V_239 ) ? L_10 : L_11 ;
switch ( exp ) {
case V_35 :
case V_39 :
F_2 ( L_100
L_101 , V_239 , V_240 , V_14 ) ;
break;
default:
break;
}
}
static void F_78 ( struct V_8 * V_9 )
{
struct V_18 * V_14 , * exp ;
for ( V_14 = V_9 -> V_137 ; V_14 ; V_14 = V_14 -> V_11 ) {
const char * V_241 ;
exp = F_13 ( V_14 -> V_12 ) ;
if ( ! exp || exp -> V_8 == V_9 )
continue;
V_241 = strrchr ( V_9 -> V_12 , '/' ) ;
if ( V_241 )
V_241 ++ ;
else
V_241 = V_9 -> V_12 ;
if ( ! V_9 -> V_15 )
F_76 ( exp -> V_20 , V_241 , exp -> V_12 ) ;
F_77 ( exp -> V_20 , V_241 , exp -> V_12 ) ;
}
}
static void F_79 ( struct V_236 * V_242 , struct V_8 * V_9 )
{
F_80 ( V_242 , L_102 ) ;
F_80 ( V_242 , L_103 ) ;
F_80 ( V_242 , L_104 ) ;
F_80 ( V_242 , L_52 ) ;
F_80 ( V_242 , L_105 ) ;
F_80 ( V_242 , L_52 ) ;
F_80 ( V_242 , L_106 ) ;
F_80 ( V_242 , L_107 ) ;
F_80 ( V_242 , L_108 ) ;
if ( V_9 -> V_139 )
F_80 ( V_242 , L_109 ) ;
if ( V_9 -> V_140 )
F_80 ( V_242 , L_110
L_111
L_112 ) ;
F_80 ( V_242 , L_113 ) ;
F_80 ( V_242 , L_114 ) ;
}
static void F_81 ( struct V_236 * V_242 , const char * V_12 )
{
static const char * V_243 = L_115 ;
if ( strncmp ( V_243 , V_12 , strlen ( V_243 ) ) == 0 )
F_80 ( V_242 , L_116 ) ;
}
static int F_82 ( struct V_236 * V_242 , struct V_8 * V_9 )
{
struct V_18 * V_14 , * exp ;
int V_244 = 0 ;
for ( V_14 = V_9 -> V_137 ; V_14 ; V_14 = V_14 -> V_11 ) {
exp = F_13 ( V_14 -> V_12 ) ;
if ( ! exp || exp -> V_8 == V_9 ) {
if ( V_231 && ! V_14 -> V_19 ) {
if ( V_245 ) {
F_2 ( L_117 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
} else {
F_3 ( L_117 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
V_244 = 1 ;
}
}
continue;
}
V_14 -> V_8 = exp -> V_8 ;
V_14 -> V_46 = exp -> V_46 ;
V_14 -> V_45 = exp -> V_45 ;
}
if ( ! V_235 )
return V_244 ;
F_80 ( V_242 , L_52 ) ;
F_80 ( V_242 , L_118 ) ;
F_80 ( V_242 , L_119 ) ;
F_80 ( V_242 , L_120 ) ;
for ( V_14 = V_9 -> V_137 ; V_14 ; V_14 = V_14 -> V_11 ) {
if ( ! V_14 -> V_8 )
continue;
if ( ! V_14 -> V_46 ) {
F_2 ( L_121 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
continue;
}
F_80 ( V_242 , L_122 , V_14 -> V_45 , V_14 -> V_12 ) ;
}
F_80 ( V_242 , L_114 ) ;
return V_244 ;
}
static void F_83 ( struct V_236 * V_242 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_18 * V_14 ;
struct V_8 * V_239 ;
int V_246 = 1 ;
for ( V_239 = V_10 ; V_239 ; V_239 = V_239 -> V_11 )
V_239 -> V_247 = F_4 ( V_239 -> V_12 ) ;
F_80 ( V_242 , L_52 ) ;
F_80 ( V_242 , L_123 ) ;
F_80 ( V_242 , L_119 ) ;
F_80 ( V_242 , L_124 ) ;
F_80 ( V_242 , L_125 ) ;
for ( V_14 = V_9 -> V_137 ; V_14 ; V_14 = V_14 -> V_11 ) {
const char * V_13 ;
if ( ! V_14 -> V_8 )
continue;
if ( V_14 -> V_8 -> V_247 )
continue;
V_14 -> V_8 -> V_247 = 1 ;
V_13 = strrchr ( V_14 -> V_8 -> V_12 , '/' ) ;
if ( V_13 )
V_13 ++ ;
else
V_13 = V_14 -> V_8 -> V_12 ;
F_80 ( V_242 , L_126 , V_246 ? L_10 : L_127 , V_13 ) ;
V_246 = 0 ;
}
F_80 ( V_242 , L_128 ) ;
}
static void F_84 ( struct V_236 * V_242 , struct V_8 * V_9 )
{
if ( V_9 -> V_234 [ 0 ] ) {
F_80 ( V_242 , L_52 ) ;
F_80 ( V_242 , L_129 ,
V_9 -> V_234 ) ;
}
}
static void F_85 ( struct V_236 * V_242 , const char * V_248 )
{
char * V_249 ;
T_11 * V_60 ;
struct V_49 V_50 ;
V_60 = fopen ( V_248 , L_130 ) ;
if ( ! V_60 )
goto V_250;
if ( F_21 ( fileno ( V_60 ) , & V_50 ) < 0 )
goto V_251;
if ( V_50 . V_54 != V_242 -> V_59 )
goto V_251;
V_249 = F_8 ( malloc ( V_242 -> V_59 ) ) ;
if ( fread ( V_249 , 1 , V_242 -> V_59 , V_60 ) != V_242 -> V_59 )
goto V_252;
if ( memcmp ( V_249 , V_242 -> V_13 , V_242 -> V_59 ) != 0 )
goto V_252;
free ( V_249 ) ;
fclose ( V_60 ) ;
return;
V_252:
free ( V_249 ) ;
V_251:
fclose ( V_60 ) ;
V_250:
V_60 = fopen ( V_248 , L_131 ) ;
if ( ! V_60 ) {
perror ( V_248 ) ;
exit ( 1 ) ;
}
if ( fwrite ( V_242 -> V_13 , 1 , V_242 -> V_59 , V_60 ) != V_242 -> V_59 ) {
perror ( V_248 ) ;
exit ( 1 ) ;
}
fclose ( V_60 ) ;
}
static void F_86 ( const char * V_248 , unsigned int V_44 )
{
unsigned long V_48 , V_59 = 0 ;
void * V_60 = F_19 ( V_248 , & V_48 ) ;
char * line ;
if ( ! V_60 )
return;
while ( ( line = F_24 ( & V_59 , V_60 , V_48 ) ) ) {
char * V_122 , * V_4 , * V_174 , * V_20 , * V_253 ;
unsigned int V_45 ;
struct V_8 * V_9 ;
struct V_18 * V_14 ;
if ( ! ( V_122 = strchr ( line , '\t' ) ) )
goto V_254;
* V_122 ++ = '\0' ;
if ( ! ( V_4 = strchr ( V_122 , '\t' ) ) )
goto V_254;
* V_4 ++ = '\0' ;
if ( ( V_20 = strchr ( V_4 , '\t' ) ) != NULL )
* V_20 ++ = '\0' ;
if ( V_20 && ( ( V_253 = strchr ( V_20 , '\t' ) ) != NULL ) )
* V_253 = '\0' ;
V_45 = strtoul ( line , & V_174 , 16 ) ;
if ( * V_122 == '\0' || * V_4 == '\0' || * V_174 != '\0' )
goto V_254;
V_9 = F_6 ( V_4 ) ;
if ( ! V_9 ) {
if ( F_4 ( V_4 ) )
V_231 = 1 ;
V_9 = F_7 ( V_4 ) ;
V_9 -> V_61 = 1 ;
}
V_14 = F_17 ( V_122 , V_9 , F_15 ( V_20 ) ) ;
V_14 -> V_44 = V_44 ;
V_14 -> V_42 = 1 ;
F_18 ( V_122 , V_9 , V_45 , F_15 ( V_20 ) ) ;
}
return;
V_254:
F_1 ( L_132 ) ;
}
static int F_87 ( struct V_18 * V_66 )
{
if ( ! V_255 )
return 1 ;
if ( V_66 -> V_43 || V_66 -> V_44 )
return 0 ;
return 1 ;
}
static void F_88 ( const char * V_248 )
{
struct V_236 V_237 = { } ;
struct V_18 * V_18 ;
int V_256 ;
for ( V_256 = 0 ; V_256 < V_23 ; V_256 ++ ) {
V_18 = V_24 [ V_256 ] ;
while ( V_18 ) {
if ( F_87 ( V_18 ) )
F_80 ( & V_237 , L_133 ,
V_18 -> V_45 , V_18 -> V_12 ,
V_18 -> V_8 -> V_12 ,
F_14 ( V_18 -> V_20 ) ) ;
V_18 = V_18 -> V_11 ;
}
}
F_85 ( & V_237 , V_248 ) ;
}
int main ( int V_257 , char * * V_258 )
{
struct V_8 * V_9 ;
struct V_236 V_237 = { } ;
char * V_259 = NULL , * V_260 = NULL ;
char * V_261 = NULL ;
int V_262 ;
int V_244 ;
struct V_263 * V_264 ;
struct V_263 * V_265 = NULL ;
while ( ( V_262 = F_89 ( V_257 , V_258 , L_134 ) ) != - 1 ) {
switch ( V_262 ) {
case 'i' :
V_259 = V_266 ;
break;
case 'I' :
V_260 = V_266 ;
V_255 = 1 ;
break;
case 'c' :
V_267 = 1 ;
break;
case 'e' :
V_255 = 1 ;
V_264 =
F_8 ( malloc ( sizeof( * V_264 ) ) ) ;
V_264 -> V_11 = V_265 ;
V_264 -> V_60 = V_266 ;
V_265 = V_264 ;
break;
case 'm' :
V_235 = 1 ;
break;
case 'o' :
V_261 = V_266 ;
break;
case 'a' :
V_233 = 1 ;
break;
case 's' :
V_232 = 0 ;
break;
case 'S' :
V_191 = 0 ;
break;
case 'w' :
V_245 = 1 ;
break;
default:
exit ( 1 ) ;
}
}
if ( V_259 )
F_86 ( V_259 , 1 ) ;
if ( V_260 )
F_86 ( V_260 , 0 ) ;
while ( V_265 ) {
F_86 ( V_265 -> V_60 , 0 ) ;
V_264 = V_265 -> V_11 ;
free ( V_265 ) ;
V_265 = V_264 ;
}
while ( V_268 < V_257 )
F_70 ( V_258 [ V_268 ++ ] ) ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
if ( V_9 -> V_61 )
continue;
F_78 ( V_9 ) ;
}
V_244 = 0 ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
char V_248 [ strlen ( V_9 -> V_12 ) + 10 ] ;
if ( V_9 -> V_61 )
continue;
V_237 . V_59 = 0 ;
F_79 ( & V_237 , V_9 ) ;
F_81 ( & V_237 , V_9 -> V_12 ) ;
V_244 |= F_82 ( & V_237 , V_9 ) ;
F_83 ( & V_237 , V_9 , V_10 ) ;
F_90 ( & V_237 , V_9 ) ;
F_84 ( & V_237 , V_9 ) ;
sprintf ( V_248 , L_135 , V_9 -> V_12 ) ;
F_85 ( & V_237 , V_248 ) ;
}
if ( V_261 )
F_88 ( V_261 ) ;
if ( V_190 && ! V_191 )
F_2 ( L_136
L_137
L_138 ,
V_190 ) ;
return V_244 ;
}
