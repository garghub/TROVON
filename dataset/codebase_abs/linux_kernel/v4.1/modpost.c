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
static inline bool F_4 ( const char * V_4 , const char * V_5 )
{
if ( strlen ( V_4 ) < strlen ( V_5 ) )
return false ;
return strcmp ( V_4 + strlen ( V_4 ) - strlen ( V_5 ) , V_5 ) == 0 ;
}
static int F_5 ( const char * V_6 )
{
const char * V_7 ;
V_7 = strrchr ( V_6 , '/' ) ;
if ( V_7 )
V_7 ++ ;
else
V_7 = V_6 ;
return ( strcmp ( V_7 , L_4 ) == 0 ) ||
( strcmp ( V_7 , L_5 ) == 0 ) ;
}
void * F_6 ( void * V_8 , const char * V_9 )
{
if ( ! V_8 )
F_1 ( L_6 , V_9 ) ;
return V_8 ;
}
static struct V_10 * F_7 ( char * V_6 )
{
struct V_10 * V_11 ;
for ( V_11 = V_12 ; V_11 ; V_11 = V_11 -> V_13 )
if ( strcmp ( V_11 -> V_14 , V_6 ) == 0 )
break;
return V_11 ;
}
static struct V_10 * F_8 ( const char * V_6 )
{
struct V_10 * V_11 ;
char * V_15 ;
V_11 = F_9 ( malloc ( sizeof( * V_11 ) ) ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_15 = F_9 ( F_10 ( V_6 ) ) ;
if ( F_4 ( V_15 , L_7 ) ) {
V_15 [ strlen ( V_15 ) - 2 ] = '\0' ;
V_11 -> V_16 = 1 ;
}
V_11 -> V_14 = V_15 ;
V_11 -> V_17 = - 1 ;
V_11 -> V_13 = V_12 ;
V_12 = V_11 ;
return V_11 ;
}
static inline unsigned int F_11 ( const char * V_14 )
{
unsigned V_18 ;
unsigned V_19 ;
for ( V_18 = 0x238F13AF * strlen ( V_14 ) , V_19 = 0 ; V_14 [ V_19 ] ; V_19 ++ )
V_18 = ( V_18 + ( ( ( unsigned char * ) V_14 ) [ V_19 ] << ( V_19 * 5 % 24 ) ) ) ;
return ( 1103515243 * V_18 + 12345 ) ;
}
static struct V_20 * F_12 ( const char * V_14 , unsigned int V_21 ,
struct V_20 * V_13 )
{
struct V_20 * V_22 = F_9 ( malloc ( sizeof( * V_22 ) + strlen ( V_14 ) + 1 ) ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
strcpy ( V_22 -> V_14 , V_14 ) ;
V_22 -> V_21 = V_21 ;
V_22 -> V_13 = V_13 ;
return V_22 ;
}
static struct V_20 * F_13 ( const char * V_14 , struct V_10 * V_10 ,
enum V_23 V_23 )
{
unsigned int V_24 ;
struct V_20 * V_25 ;
V_24 = F_11 ( V_14 ) % V_26 ;
V_25 = V_27 [ V_24 ] = F_12 ( V_14 , 0 , V_27 [ V_24 ] ) ;
V_25 -> V_10 = V_10 ;
V_25 -> V_23 = V_23 ;
return V_25 ;
}
static struct V_20 * F_14 ( const char * V_14 )
{
struct V_20 * V_22 ;
if ( V_14 [ 0 ] == '.' )
V_14 ++ ;
for ( V_22 = V_27 [ F_11 ( V_14 ) % V_26 ] ; V_22 ; V_22 = V_22 -> V_13 ) {
if ( strcmp ( V_22 -> V_14 , V_14 ) == 0 )
return V_22 ;
}
return NULL ;
}
static const char * F_15 ( enum V_23 V_28 )
{
return V_29 [ V_28 ] . V_4 ;
}
static enum V_23 F_16 ( const char * V_22 )
{
int V_19 ;
if ( ! V_22 )
return V_30 ;
for ( V_19 = 0 ; V_29 [ V_19 ] . V_23 != V_30 ; V_19 ++ ) {
if ( strcmp ( V_29 [ V_19 ] . V_4 , V_22 ) == 0 )
return V_29 [ V_19 ] . V_23 ;
}
return V_30 ;
}
static enum V_23 F_17 ( struct V_31 * V_32 , unsigned int V_33 )
{
const char * V_34 = F_18 ( V_32 , V_33 ) ;
if ( F_19 ( V_34 , L_8 ) )
return V_35 ;
else if ( F_19 ( V_34 , L_9 ) )
return V_36 ;
else if ( F_19 ( V_34 , L_10 ) )
return V_37 ;
else if ( F_19 ( V_34 , L_11 ) )
return V_38 ;
else if ( F_19 ( V_34 , L_12 ) )
return V_39 ;
else
return V_30 ;
}
static enum V_23 F_20 ( struct V_31 * V_32 , unsigned int V_33 )
{
if ( V_33 == V_32 -> V_40 )
return V_35 ;
else if ( V_33 == V_32 -> V_41 )
return V_36 ;
else if ( V_33 == V_32 -> V_42 )
return V_37 ;
else if ( V_33 == V_32 -> V_43 )
return V_38 ;
else if ( V_33 == V_32 -> V_44 )
return V_39 ;
else
return V_30 ;
}
static struct V_20 * F_21 ( const char * V_14 , struct V_10 * V_11 ,
enum V_23 V_23 )
{
struct V_20 * V_22 = F_14 ( V_14 ) ;
if ( ! V_22 ) {
V_22 = F_13 ( V_14 , V_11 , V_23 ) ;
} else {
if ( ! V_22 -> V_45 ) {
F_2 ( L_13
L_14 , V_11 -> V_14 , V_14 ,
V_22 -> V_10 -> V_14 ,
F_5 ( V_22 -> V_10 -> V_14 ) ? L_15 : L_16 ) ;
} else {
V_22 -> V_10 = V_11 ;
}
}
V_22 -> V_45 = 0 ;
V_22 -> V_46 = F_5 ( V_11 -> V_14 ) ;
V_22 -> V_47 = 0 ;
V_22 -> V_23 = V_23 ;
return V_22 ;
}
static void F_22 ( const char * V_14 , struct V_10 * V_11 ,
unsigned int V_48 , enum V_23 V_23 )
{
struct V_20 * V_22 = F_14 ( V_14 ) ;
if ( ! V_22 ) {
V_22 = F_13 ( V_14 , V_11 , V_23 ) ;
V_22 -> V_45 = 1 ;
}
V_22 -> V_48 = V_48 ;
V_22 -> V_49 = 1 ;
}
void * F_23 ( const char * V_50 , unsigned long * V_51 )
{
struct V_52 V_53 ;
void * V_54 = V_55 ;
int V_56 ;
V_56 = F_24 ( V_50 , V_57 ) ;
if ( V_56 < 0 )
return NULL ;
if ( F_25 ( V_56 , & V_53 ) )
goto V_58;
* V_51 = V_53 . V_59 ;
V_54 = F_26 ( NULL , * V_51 , V_60 | V_61 , V_62 , V_56 , 0 ) ;
V_58:
F_27 ( V_56 ) ;
if ( V_54 == V_55 )
return NULL ;
return V_54 ;
}
char * F_28 ( unsigned long * V_63 , void * V_64 , unsigned long V_51 )
{
static char line [ 4096 ] ;
int V_65 = 1 ;
T_2 V_66 = 0 ;
signed char * V_15 = ( signed char * ) V_64 + * V_63 ;
char * V_22 = line ;
for (; * V_63 < V_51 ; ( * V_63 ) ++ ) {
if ( V_65 && isspace ( * V_15 ) ) {
V_15 ++ ;
continue;
}
V_65 = 0 ;
if ( * V_15 != '\n' && ( * V_63 < V_51 ) ) {
V_66 ++ ;
* V_22 ++ = * V_15 ++ ;
if ( V_66 > 4095 )
break;
} else {
* V_22 = '\0' ;
return line ;
}
}
return NULL ;
}
void F_29 ( void * V_64 , unsigned long V_51 )
{
F_30 ( V_64 , V_51 ) ;
}
static int F_31 ( struct V_31 * V_67 , const char * V_50 )
{
unsigned int V_19 ;
T_3 * V_68 ;
T_4 * V_69 ;
T_5 * V_70 ;
const char * V_71 ;
unsigned int V_72 = ~ 0U , V_73 = ~ 0U ;
V_68 = F_23 ( V_50 , & V_67 -> V_51 ) ;
if ( ! V_68 ) {
if ( V_74 ) {
fprintf ( V_3 , L_17 , V_50 ,
strerror ( V_75 ) ) ;
return 0 ;
}
perror ( V_50 ) ;
exit ( 1 ) ;
}
V_67 -> V_68 = V_68 ;
if ( V_67 -> V_51 < sizeof( * V_68 ) ) {
return 0 ;
}
if ( ( V_68 -> V_76 [ V_77 ] != V_78 ) ||
( V_68 -> V_76 [ V_79 ] != V_80 ) ||
( V_68 -> V_76 [ V_81 ] != V_82 ) ||
( V_68 -> V_76 [ V_83 ] != V_84 ) ) {
return 0 ;
}
V_68 -> V_85 = F_32 ( V_68 -> V_85 ) ;
V_68 -> V_86 = F_32 ( V_68 -> V_86 ) ;
V_68 -> V_87 = F_32 ( V_68 -> V_87 ) ;
V_68 -> V_88 = F_32 ( V_68 -> V_88 ) ;
V_68 -> V_89 = F_32 ( V_68 -> V_89 ) ;
V_68 -> V_90 = F_32 ( V_68 -> V_90 ) ;
V_68 -> V_91 = F_32 ( V_68 -> V_91 ) ;
V_68 -> V_92 = F_32 ( V_68 -> V_92 ) ;
V_68 -> V_93 = F_32 ( V_68 -> V_93 ) ;
V_68 -> V_94 = F_32 ( V_68 -> V_94 ) ;
V_68 -> V_95 = F_32 ( V_68 -> V_95 ) ;
V_68 -> V_96 = F_32 ( V_68 -> V_96 ) ;
V_68 -> V_97 = F_32 ( V_68 -> V_97 ) ;
V_69 = ( void * ) V_68 + V_68 -> V_90 ;
V_67 -> V_69 = V_69 ;
if ( V_68 -> V_90 > V_67 -> V_51 ) {
F_1 ( L_18
L_19 , ( unsigned long ) V_68 -> V_90 ,
V_50 , V_67 -> V_51 ) ;
return 0 ;
}
if ( V_68 -> V_96 == V_98 ) {
V_67 -> V_99 = F_32 ( V_69 [ 0 ] . V_100 ) ;
}
else {
V_67 -> V_99 = V_68 -> V_96 ;
}
if ( V_68 -> V_97 == V_101 ) {
V_67 -> V_102 = F_32 ( V_69 [ 0 ] . V_103 ) ;
}
else {
V_67 -> V_102 = V_68 -> V_97 ;
}
for ( V_19 = 0 ; V_19 < V_67 -> V_99 ; V_19 ++ ) {
V_69 [ V_19 ] . V_104 = F_32 ( V_69 [ V_19 ] . V_104 ) ;
V_69 [ V_19 ] . V_105 = F_32 ( V_69 [ V_19 ] . V_105 ) ;
V_69 [ V_19 ] . V_106 = F_32 ( V_69 [ V_19 ] . V_106 ) ;
V_69 [ V_19 ] . V_107 = F_32 ( V_69 [ V_19 ] . V_107 ) ;
V_69 [ V_19 ] . V_108 = F_32 ( V_69 [ V_19 ] . V_108 ) ;
V_69 [ V_19 ] . V_100 = F_32 ( V_69 [ V_19 ] . V_100 ) ;
V_69 [ V_19 ] . V_103 = F_32 ( V_69 [ V_19 ] . V_103 ) ;
V_69 [ V_19 ] . V_109 = F_32 ( V_69 [ V_19 ] . V_109 ) ;
V_69 [ V_19 ] . V_110 = F_32 ( V_69 [ V_19 ] . V_110 ) ;
V_69 [ V_19 ] . V_111 = F_32 ( V_69 [ V_19 ] . V_111 ) ;
}
V_71 = ( void * ) V_68 + V_69 [ V_67 -> V_102 ] . V_108 ;
for ( V_19 = 1 ; V_19 < V_67 -> V_99 ; V_19 ++ ) {
const char * V_34 ;
int V_112 = V_69 [ V_19 ] . V_105 == V_113 ;
if ( ! V_112 && V_69 [ V_19 ] . V_108 > V_67 -> V_51 ) {
F_1 ( L_20
L_21 , V_50 ,
( unsigned long ) V_69 [ V_19 ] . V_108 ,
sizeof( * V_68 ) ) ;
return 0 ;
}
V_34 = V_71 + V_69 [ V_19 ] . V_104 ;
if ( strcmp ( V_34 , L_22 ) == 0 ) {
if ( V_112 )
F_1 ( L_23 , V_50 ) ;
V_67 -> V_114 = ( void * ) V_68 + V_69 [ V_19 ] . V_108 ;
V_67 -> V_115 = V_69 [ V_19 ] . V_100 ;
} else if ( strcmp ( V_34 , L_24 ) == 0 )
V_67 -> V_40 = V_19 ;
else if ( strcmp ( V_34 , L_25 ) == 0 )
V_67 -> V_41 = V_19 ;
else if ( strcmp ( V_34 , L_26 ) == 0 )
V_67 -> V_42 = V_19 ;
else if ( strcmp ( V_34 , L_27 ) == 0 )
V_67 -> V_43 = V_19 ;
else if ( strcmp ( V_34 , L_28 ) == 0 )
V_67 -> V_44 = V_19 ;
if ( V_69 [ V_19 ] . V_105 == V_116 ) {
unsigned int V_117 ;
V_72 = V_19 ;
V_67 -> V_118 = ( void * ) V_68 +
V_69 [ V_19 ] . V_108 ;
V_67 -> V_119 = ( void * ) V_68 +
V_69 [ V_19 ] . V_108 + V_69 [ V_19 ] . V_100 ;
V_117 = V_69 [ V_19 ] . V_103 ;
V_67 -> V_120 = ( void * ) V_68 +
V_69 [ V_117 ] . V_108 ;
}
if ( V_69 [ V_19 ] . V_105 == V_121 ) {
V_73 = V_19 ;
V_67 -> V_122 = ( void * ) V_68 +
V_69 [ V_19 ] . V_108 ;
V_67 -> V_123 = ( void * ) V_68 +
V_69 [ V_19 ] . V_108 + V_69 [ V_19 ] . V_100 ;
}
}
if ( ! V_67 -> V_118 )
F_1 ( L_29 , V_50 ) ;
for ( V_70 = V_67 -> V_118 ; V_70 < V_67 -> V_119 ; V_70 ++ ) {
V_70 -> V_124 = F_32 ( V_70 -> V_124 ) ;
V_70 -> V_125 = F_32 ( V_70 -> V_125 ) ;
V_70 -> V_126 = F_32 ( V_70 -> V_126 ) ;
V_70 -> V_59 = F_32 ( V_70 -> V_59 ) ;
}
if ( V_73 != ~ 0U ) {
T_6 * V_15 ;
if ( V_72 != V_69 [ V_73 ] . V_103 )
F_1 ( L_30 ,
V_50 , V_69 [ V_73 ] . V_103 ,
V_72 ) ;
for ( V_15 = V_67 -> V_122 ; V_15 < V_67 -> V_123 ;
V_15 ++ )
* V_15 = F_32 ( * V_15 ) ;
}
return 1 ;
}
static void F_33 ( struct V_31 * V_67 )
{
F_29 ( V_67 -> V_68 , V_67 -> V_51 ) ;
}
static int F_34 ( struct V_31 * V_67 , const char * V_127 )
{
if ( strcmp ( V_127 , F_35 ( V_128 ) ) == 0 )
return 1 ;
if ( strcmp ( V_127 , L_31 ) == 0 )
return 1 ;
if ( V_67 -> V_68 -> V_86 == V_129 )
if ( strncmp ( V_127 , L_32 , sizeof( L_32 ) - 1 ) == 0 ||
strncmp ( V_127 , L_33 , sizeof( L_33 ) - 1 ) == 0 ||
strncmp ( V_127 , L_34 , sizeof( L_34 ) - 1 ) == 0 ||
strncmp ( V_127 , L_35 , sizeof( L_35 ) - 1 ) == 0 ||
strncmp ( V_127 , L_36 , sizeof( L_36 ) - 1 ) == 0 ||
strncmp ( V_127 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
return 1 ;
if ( V_67 -> V_68 -> V_86 == V_130 )
if ( strncmp ( V_127 , L_38 , sizeof( L_38 ) - 1 ) == 0 ||
strncmp ( V_127 , L_39 , sizeof( L_39 ) - 1 ) == 0 ||
strncmp ( V_127 , L_36 , sizeof( L_36 ) - 1 ) == 0 ||
strncmp ( V_127 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
return 1 ;
return 0 ;
}
static void F_36 ( struct V_10 * V_11 , struct V_31 * V_67 ,
T_5 * V_70 , const char * V_127 )
{
unsigned int V_48 ;
enum V_23 V_23 ;
if ( ( ! F_5 ( V_11 -> V_14 ) || V_11 -> V_16 ) &&
strncmp ( V_127 , L_24 , 9 ) == 0 )
V_23 = F_17 ( V_67 , F_37 ( V_67 , V_70 ) ) ;
else
V_23 = F_20 ( V_67 , F_37 ( V_67 , V_70 ) ) ;
if ( strncmp ( V_127 , V_131 , strlen ( V_131 ) ) == 0 ) {
V_48 = ( unsigned int ) V_70 -> V_126 ;
F_22 ( V_127 + strlen ( V_131 ) , V_11 , V_48 ,
V_23 ) ;
}
switch ( V_70 -> V_124 ) {
case V_132 :
if ( ! strncmp ( V_127 , L_40 , sizeof( L_40 ) - 1 ) ) {
} else
F_2 ( L_41 , V_127 , V_11 -> V_14 ) ;
break;
case V_98 :
if ( F_38 ( V_70 -> V_133 ) != V_134 &&
F_38 ( V_70 -> V_133 ) != V_135 )
break;
if ( F_34 ( V_67 , V_127 ) )
break;
#if F_39 ( V_136 ) || F_39 ( V_137 )
#ifndef V_137
#define V_137 STT_REGISTER
#endif
if ( V_67 -> V_68 -> V_86 == V_138 ||
V_67 -> V_68 -> V_86 == V_139 ) {
if ( F_40 ( V_70 -> V_133 ) == V_137 )
break;
if ( V_127 [ 0 ] == '.' ) {
char * V_140 = F_10 ( V_127 ) ;
V_140 [ 0 ] = '_' ;
V_140 [ 1 ] = toupper ( V_140 [ 1 ] ) ;
V_127 = V_140 ;
}
}
#endif
#ifdef F_41
if ( V_127 [ 0 ] != '_' )
break;
else
V_127 ++ ;
#endif
V_11 -> V_141 = F_12 ( V_127 ,
F_38 ( V_70 -> V_133 ) == V_135 ,
V_11 -> V_141 ) ;
break;
default:
if ( strncmp ( V_127 , V_142 , strlen ( V_142 ) ) == 0 ) {
F_21 ( V_127 + strlen ( V_142 ) , V_11 ,
V_23 ) ;
}
if ( strcmp ( V_127 , F_35 ( V_143 ) ) == 0 )
V_11 -> V_144 = 1 ;
if ( strcmp ( V_127 , F_35 ( V_145 ) ) == 0 )
V_11 -> V_146 = 1 ;
break;
}
}
static char * F_42 ( char * string , unsigned long * V_147 )
{
while ( string [ 0 ] ) {
string ++ ;
if ( ( * V_147 ) -- <= 1 )
return NULL ;
}
while ( ! string [ 0 ] ) {
string ++ ;
if ( ( * V_147 ) -- <= 1 )
return NULL ;
}
return string ;
}
static char * F_43 ( void * V_114 , unsigned long V_115 ,
const char * V_148 , char * V_67 )
{
char * V_15 ;
unsigned int V_149 = strlen ( V_148 ) ;
unsigned long V_51 = V_115 ;
if ( V_67 ) {
V_51 -= V_67 - ( char * ) V_114 ;
V_114 = F_42 ( V_67 , & V_51 ) ;
}
for ( V_15 = V_114 ; V_15 ; V_15 = F_42 ( V_15 , & V_51 ) ) {
if ( strncmp ( V_15 , V_148 , V_149 ) == 0 && V_15 [ V_149 ] == '=' )
return V_15 + V_149 + 1 ;
}
return NULL ;
}
static char * F_44 ( void * V_114 , unsigned long V_115 ,
const char * V_148 )
{
return F_43 ( V_114 , V_115 , V_148 , NULL ) ;
}
static int F_45 ( const char * V_22 , const char * V_150 )
{
int V_151 , V_152 ;
if ( ! V_22 || ! V_150 )
return 1 ;
V_151 = strlen ( V_22 ) ;
V_152 = strlen ( V_150 ) ;
if ( ( V_151 == 0 ) || ( V_152 == 0 ) )
return 1 ;
if ( V_152 > V_151 )
return 1 ;
return memcmp ( V_22 + V_151 - V_152 , V_150 , V_152 ) ;
}
static const char * F_46 ( struct V_31 * V_32 , T_5 * V_70 )
{
if ( V_70 )
return V_32 -> V_120 + V_70 -> V_125 ;
else
return L_42 ;
}
static const char * F_18 ( struct V_31 * V_32 , int V_153 )
{
T_4 * V_69 = V_32 -> V_69 ;
return ( void * ) V_32 -> V_68 +
V_32 -> V_69 [ V_32 -> V_102 ] . V_108 +
V_69 [ V_153 ] . V_104 ;
}
static const char * F_47 ( struct V_31 * V_32 , T_4 * V_154 )
{
return ( void * ) V_32 -> V_68 +
V_32 -> V_69 [ V_32 -> V_102 ] . V_108 +
V_154 -> V_104 ;
}
static int F_48 ( const char * V_70 , const char * const V_155 [] )
{
const char * V_15 ;
while ( * V_155 ) {
V_15 = * V_155 ++ ;
const char * V_156 = V_15 + strlen ( V_15 ) - 1 ;
if ( * V_15 == '*' && * V_156 == '*' ) {
char * V_157 , * V_158 = F_49 ( V_15 + 1 , strlen ( V_15 ) - 2 ) ;
V_157 = strstr ( V_70 , V_158 ) ;
free ( V_158 ) ;
if ( V_157 != NULL )
return 1 ;
}
else if ( * V_15 == '*' ) {
if ( F_45 ( V_70 , V_15 + 1 ) == 0 )
return 1 ;
}
else if ( * V_156 == '*' ) {
if ( strncmp ( V_70 , V_15 , strlen ( V_15 ) - 1 ) == 0 )
return 1 ;
}
else {
if ( strcmp ( V_15 , V_70 ) == 0 )
return 1 ;
}
}
return 0 ;
}
static void F_50 ( const char * V_6 , struct V_31 * V_32 ,
T_4 * V_154 )
{
const char * V_33 = F_47 ( V_32 , V_154 ) ;
if ( V_154 -> V_105 == V_159 &&
! ( V_154 -> V_106 & V_160 ) &&
! F_48 ( V_33 , V_161 ) ) {
F_2 ( L_43
L_44
L_45
L_46 ,
V_6 , V_33 ) ;
}
}
static const struct V_162 * F_51 (
const char * V_163 , const char * V_164 )
{
int V_19 ;
int V_165 = sizeof( V_162 ) / sizeof( struct V_162 ) ;
const struct V_162 * V_166 = & V_162 [ 0 ] ;
if ( * V_164 == '\0' )
return NULL ;
for ( V_19 = 0 ; V_19 < V_165 ; V_19 ++ ) {
if ( F_48 ( V_163 , V_166 -> V_163 ) ) {
if ( V_166 -> V_167 [ 0 ] && F_48 ( V_164 , V_166 -> V_167 ) )
return V_166 ;
if ( V_166 -> V_168 [ 0 ] && ! F_48 ( V_164 , V_166 -> V_168 ) )
return V_166 ;
}
V_166 ++ ;
}
return NULL ;
}
static int F_52 ( const struct V_162 * V_169 ,
const char * V_163 , const char * V_170 ,
const char * V_164 , const char * V_171 )
{
if ( F_48 ( V_164 , V_172 ) &&
F_48 ( V_163 , V_173 ) &&
( strncmp ( V_170 , L_47 , strlen ( L_47 ) ) == 0 ) )
return 0 ;
if ( strcmp ( V_164 , L_48 ) == 0 &&
F_48 ( V_163 , V_173 ) &&
( strncmp ( V_170 , L_49 , strlen ( L_49 ) ) == 0 ) )
return 0 ;
if ( F_48 ( V_164 , V_174 ) &&
F_48 ( V_163 , V_173 ) &&
F_48 ( V_170 , V_169 -> V_175 ) )
return 0 ;
if ( F_48 ( V_163 , V_176 ) &&
F_48 ( V_164 , V_177 ) )
return 0 ;
if ( F_48 ( V_171 , V_178 ) )
return 0 ;
if ( F_48 ( V_163 , V_179 ) &&
F_48 ( V_164 , V_177 ) &&
F_48 ( V_170 , V_180 ) )
return 0 ;
return 1 ;
}
static T_5 * F_53 ( struct V_31 * V_32 , T_7 V_181 ,
T_5 * V_182 )
{
T_5 * V_70 ;
T_5 * V_183 = NULL ;
T_7 V_184 = 20 ;
T_7 V_185 ;
unsigned int V_186 ;
if ( V_182 -> V_125 != 0 )
return V_182 ;
V_186 = F_37 ( V_32 , V_182 ) ;
for ( V_70 = V_32 -> V_118 ; V_70 < V_32 -> V_119 ; V_70 ++ ) {
if ( F_37 ( V_32 , V_70 ) != V_186 )
continue;
if ( F_40 ( V_70 -> V_133 ) == V_187 )
continue;
if ( V_70 -> V_126 == V_181 )
return V_70 ;
V_185 = V_70 -> V_126 - V_181 ;
if ( V_185 < 0 )
V_185 = V_181 - V_70 -> V_126 ;
if ( V_185 < V_184 ) {
V_184 = V_185 ;
V_183 = V_70 ;
}
}
if ( V_184 < 20 )
return V_183 ;
else
return NULL ;
}
static inline int F_54 ( const char * V_4 )
{
return V_4 [ 0 ] == '$' && strchr ( L_50 , V_4 [ 1 ] )
&& ( V_4 [ 2 ] == '\0' || V_4 [ 2 ] == '.' ) ;
}
static inline int F_55 ( struct V_31 * V_32 , T_5 * V_70 )
{
const char * V_14 = V_32 -> V_120 + V_70 -> V_125 ;
if ( ! V_14 || ! strlen ( V_14 ) )
return 0 ;
return ! F_54 ( V_14 ) ;
}
static T_5 * F_56 ( struct V_31 * V_32 , T_8 V_181 ,
const char * V_33 )
{
T_5 * V_70 ;
T_5 * V_183 = NULL ;
T_8 V_184 = ~ 0 ;
for ( V_70 = V_32 -> V_118 ; V_70 < V_32 -> V_119 ; V_70 ++ ) {
const char * V_188 ;
if ( F_57 ( V_70 -> V_124 ) )
continue;
V_188 = F_18 ( V_32 , F_37 ( V_32 , V_70 ) ) ;
if ( strcmp ( V_188 , V_33 ) != 0 )
continue;
if ( ! F_55 ( V_32 , V_70 ) )
continue;
if ( V_70 -> V_126 <= V_181 ) {
if ( ( V_181 - V_70 -> V_126 ) < V_184 ) {
V_184 = V_181 - V_70 -> V_126 ;
V_183 = V_70 ;
} else if ( ( V_181 - V_70 -> V_126 ) == V_184 ) {
V_183 = V_70 ;
}
}
}
return V_183 ;
}
static char * F_58 ( const char * V_22 )
{
if ( F_48 ( V_22 , V_174 ) ) {
char * V_15 = malloc ( 20 ) ;
char * V_189 = V_15 ;
* V_15 ++ = '_' ;
* V_15 ++ = '_' ;
if ( * V_22 == '.' )
V_22 ++ ;
while ( * V_22 && * V_22 != '.' )
* V_15 ++ = * V_22 ++ ;
* V_15 = '\0' ;
if ( * V_22 == '.' )
V_22 ++ ;
if ( strstr ( V_22 , L_51 ) != NULL )
strcat ( V_15 , L_52 ) ;
else if ( strstr ( V_22 , L_53 ) != NULL )
strcat ( V_15 , L_54 ) ;
else
strcat ( V_15 , L_55 ) ;
return V_189 ;
} else {
return F_10 ( L_15 ) ;
}
}
static int F_59 ( T_5 * V_70 )
{
if ( V_70 )
return F_40 ( V_70 -> V_133 ) == V_190 ;
else
return - 1 ;
}
static void F_60 ( const char * const V_191 [ 20 ] )
{
const char * const * V_22 = V_191 ;
while ( * V_22 ) {
fprintf ( V_3 , L_56 , * V_22 ) ;
V_22 ++ ;
if ( * V_22 )
fprintf ( V_3 , L_57 ) ;
}
fprintf ( V_3 , L_58 ) ;
}
static inline void F_61 ( int V_192 , const char * * V_14 , const char * * V_193 )
{
switch ( V_192 ) {
case 0 : * V_14 = L_59 ; * V_193 = L_15 ; break;
case 1 : * V_14 = L_60 ; * V_193 = L_61 ; break;
default: * V_14 = L_62 ; * V_193 = L_15 ; break;
}
}
static void F_62 ( const char * V_6 ,
const struct V_162 * V_169 ,
const char * V_163 ,
unsigned long long V_194 ,
const char * V_170 ,
int V_195 ,
const char * V_164 , const char * V_171 ,
int V_196 )
{
const char * V_197 , * V_198 ;
const char * V_199 , * V_200 ;
char * V_201 ;
char * V_202 ;
V_203 ++ ;
if ( ! V_204 )
return;
F_61 ( V_195 , & V_197 , & V_198 ) ;
F_61 ( V_196 , & V_199 , & V_200 ) ;
F_2 ( L_63
L_64 ,
V_6 , V_163 , V_194 , V_197 , V_170 , V_198 , V_199 , V_164 ,
V_171 , V_200 ) ;
switch ( V_169 -> V_169 ) {
case V_205 :
V_201 = F_58 ( V_163 ) ;
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_65
L_66
L_67
L_68 ,
V_201 , V_170 ,
V_199 , V_202 , V_171 , V_200 ,
V_170 , V_202 , V_171 ) ;
free ( V_201 ) ;
free ( V_202 ) ;
break;
case V_206 : {
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_69
L_70
L_71
L_72
L_73 ,
V_170 , V_199 , V_202 , V_171 , V_200 ) ;
F_60 ( V_169 -> V_175 ) ;
free ( V_202 ) ;
break;
}
case V_207 :
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_74
L_75
L_76 ,
V_170 , V_199 , V_199 , V_171 , V_200 , V_202 , V_171 ) ;
free ( V_202 ) ;
break;
case V_208 : {
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_69
L_70
L_71
L_77
L_78 ,
V_170 , V_199 , V_202 , V_171 , V_200 ) ;
F_60 ( V_169 -> V_175 ) ;
free ( V_202 ) ;
break;
}
case V_209 :
case V_210 :
V_201 = F_58 ( V_163 ) ;
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_79
L_80
L_81
L_82 ,
V_197 , V_201 , V_170 , V_198 ,
V_199 , V_202 , V_171 , V_200 ,
V_171 , V_170 , V_171 ) ;
free ( V_201 ) ;
free ( V_202 ) ;
break;
case V_211 :
V_201 = F_58 ( V_163 ) ;
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_79
L_80
L_83
L_84
L_85
L_86
L_87 ,
V_197 , V_201 , V_170 , V_198 ,
V_199 , V_202 , V_171 , V_200 ,
V_202 , V_171 , V_200 ) ;
free ( V_201 ) ;
free ( V_202 ) ;
break;
case V_212 :
V_201 = F_58 ( V_163 ) ;
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_79
L_80
L_83
L_88
L_89
L_86
L_90 ,
V_197 , V_201 , V_170 , V_198 ,
V_199 , V_202 , V_171 , V_200 ,
V_202 , V_171 , V_200 ) ;
free ( V_201 ) ;
free ( V_202 ) ;
break;
case V_213 :
V_202 = F_58 ( V_164 ) ;
fprintf ( V_3 ,
L_91
L_92
L_93 ,
V_171 , V_202 , V_202 , V_171 ) ;
free ( V_202 ) ;
break;
case V_214 :
F_1 ( L_94
L_95 ) ;
break;
}
fprintf ( V_3 , L_58 ) ;
}
static void F_63 ( const char * V_6 , struct V_31 * V_32 ,
const struct V_162 * const V_169 ,
T_9 * V_189 , T_5 * V_70 , const char * V_163 )
{
const char * V_164 ;
T_5 * V_199 ;
T_5 * V_197 ;
const char * V_171 ;
const char * V_170 ;
V_197 = F_56 ( V_32 , V_189 -> V_215 , V_163 ) ;
V_170 = F_46 ( V_32 , V_197 ) ;
if ( ! strncmp ( V_170 , L_96 ,
sizeof( L_96 ) - 1 ) )
return;
V_164 = F_18 ( V_32 , F_37 ( V_32 , V_70 ) ) ;
V_199 = F_53 ( V_32 , V_189 -> V_216 , V_70 ) ;
V_171 = F_46 ( V_32 , V_199 ) ;
if ( F_52 ( V_169 ,
V_163 , V_170 , V_164 , V_171 ) ) {
F_62 ( V_6 , V_169 ,
V_163 , V_189 -> V_215 , V_170 ,
F_59 ( V_197 ) , V_164 , V_171 ,
F_59 ( V_199 ) ) ;
}
}
static int F_64 ( struct V_31 * V_32 , unsigned int V_217 )
{
if ( V_217 > V_32 -> V_99 )
F_1 ( L_97 ) ;
return ( ( V_32 -> V_69 [ V_217 ] . V_106 & V_218 ) == V_218 ) ;
}
static void F_65 ( const char * const V_33 , const T_9 * V_189 )
{
if ( ! V_219 )
V_219 = V_189 -> V_215 * 2 ;
}
static inline bool F_66 ( T_9 * V_189 )
{
if ( V_189 -> V_215 && V_219 == 0 )
F_1 ( L_98 ) ;
return ( ( V_189 -> V_215 == 0 ) ||
( V_189 -> V_215 % V_219 == 0 ) ) ;
}
static void F_67 ( const char * V_6 , struct V_31 * V_32 ,
const struct V_162 * const V_169 ,
T_9 * V_189 , T_5 * V_70 ,
const char * V_163 , const char * V_164 )
{
T_5 * V_170 = F_56 ( V_32 , V_189 -> V_215 , V_163 ) ;
const char * V_220 = F_46 ( V_32 , V_170 ) ;
T_5 * V_171 = F_53 ( V_32 , V_189 -> V_216 , V_70 ) ;
const char * V_221 = F_46 ( V_32 , V_171 ) ;
const char * V_222 ;
const char * V_223 ;
const char * V_224 ;
const char * V_225 ;
F_61 ( F_59 ( V_170 ) ,
& V_222 , & V_223 ) ;
F_61 ( F_59 ( V_171 ) ,
& V_224 , & V_225 ) ;
F_2 ( L_99
L_100 ,
V_6 , V_163 , ( long ) V_189 -> V_215 , V_222 ,
V_220 , V_223 ,
V_224 , V_164 , V_221 , V_225 ) ;
if ( ! F_48 ( V_164 , V_169 -> V_167 ) &&
F_64 ( V_32 , F_37 ( V_32 , V_70 ) ) )
fprintf ( V_3 ,
L_101
L_102
L_103
L_104
L_105
L_106
L_107 ,
V_163 , ( long ) V_189 -> V_215 , V_164 , V_164 , V_164 ) ;
}
static void F_68 ( const char * V_6 , struct V_31 * V_32 ,
const struct V_162 * const V_169 ,
T_9 * V_189 , T_5 * V_70 ,
const char * V_163 )
{
const char * V_164 = F_18 ( V_32 , F_37 ( V_32 , V_70 ) ) ;
V_203 ++ ;
if ( V_204 )
F_67 ( V_6 , V_32 , V_169 , V_189 , V_70 ,
V_163 , V_164 ) ;
if ( F_48 ( V_164 , V_169 -> V_167 ) )
F_1 ( L_101
L_108
L_109
L_110
L_111 ,
V_163 , ( long ) V_189 -> V_215 , V_164 , V_6 ) ;
else if ( ! F_64 ( V_32 , F_37 ( V_32 , V_70 ) ) ) {
if ( F_66 ( V_189 ) )
F_1 ( L_101
L_112
L_113
L_114
L_115 ,
V_163 , ( long ) V_189 -> V_215 , V_164 ) ;
else
F_1 ( L_101
L_112
L_116
L_117
L_115 ,
V_163 , ( long ) V_189 -> V_215 , V_164 ) ;
}
}
static void F_69 ( const char * V_6 , struct V_31 * V_32 ,
T_9 * V_189 , T_5 * V_70 , const char * V_163 )
{
const char * V_164 = F_18 ( V_32 , F_37 ( V_32 , V_70 ) ) ; ;
const struct V_162 * V_169 = F_51 ( V_163 , V_164 ) ;
if ( V_169 ) {
if ( V_169 -> V_226 )
V_169 -> V_226 ( V_6 , V_32 , V_169 ,
V_189 , V_70 , V_163 ) ;
else
F_63 ( V_6 , V_32 , V_169 ,
V_189 , V_70 , V_163 ) ;
}
}
static unsigned int * F_70 ( struct V_31 * V_32 ,
T_4 * V_154 , T_9 * V_189 )
{
T_4 * V_69 = V_32 -> V_69 ;
int V_227 = V_154 -> V_109 ;
return ( void * ) V_32 -> V_68 + V_69 [ V_227 ] . V_108 +
V_189 -> V_215 ;
}
static int F_71 ( struct V_31 * V_32 , T_4 * V_154 , T_9 * V_189 )
{
unsigned int V_228 = F_72 ( V_189 -> V_229 ) ;
unsigned int * V_230 = F_70 ( V_32 , V_154 , V_189 ) ;
switch ( V_228 ) {
case V_231 :
V_189 -> V_216 = F_32 ( * V_230 ) ;
break;
case V_232 :
V_189 -> V_216 = F_32 ( * V_230 ) + 4 ;
if ( V_32 -> V_68 -> V_85 == V_233 )
V_189 -> V_216 += V_189 -> V_215 ;
break;
}
return 0 ;
}
static int F_73 ( struct V_31 * V_32 , T_4 * V_154 , T_9 * V_189 )
{
unsigned int V_228 = F_72 ( V_189 -> V_229 ) ;
switch ( V_228 ) {
case V_234 :
V_189 -> V_216 = ( int ) ( long )
( V_32 -> V_118 + F_74 ( V_189 -> V_229 ) ) ;
break;
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
V_189 -> V_216 = ( int ) ( long ) ( V_32 -> V_68 +
V_154 -> V_108 +
( V_189 -> V_215 - V_154 -> V_107 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_31 * V_32 , T_4 * V_154 , T_9 * V_189 )
{
unsigned int V_228 = F_72 ( V_189 -> V_229 ) ;
unsigned int * V_230 = F_70 ( V_32 , V_154 , V_189 ) ;
unsigned int V_241 ;
if ( V_228 == V_242 )
return 1 ;
V_241 = F_32 ( * V_230 ) ;
switch ( V_228 ) {
case V_243 :
V_189 -> V_216 = V_241 & 0xffff ;
break;
case V_244 :
V_189 -> V_216 = ( V_241 & 0x03ffffff ) << 2 ;
break;
case V_245 :
V_189 -> V_216 = V_241 ;
break;
}
return 0 ;
}
static void F_76 ( const char * V_6 , struct V_31 * V_32 ,
T_4 * V_154 )
{
T_5 * V_70 ;
T_9 * V_246 ;
T_9 V_189 ;
unsigned int V_247 ;
const char * V_163 ;
T_9 * V_248 = ( void * ) V_32 -> V_68 + V_154 -> V_108 ;
T_9 * V_249 = ( void * ) V_248 + V_154 -> V_100 ;
V_163 = F_47 ( V_32 , V_154 ) ;
V_163 += strlen ( L_118 ) ;
if ( F_48 ( V_163 , V_161 ) )
return;
for ( V_246 = V_248 ; V_246 < V_249 ; V_246 ++ ) {
V_189 . V_215 = F_32 ( V_246 -> V_215 ) ;
#if V_250 == V_251
if ( V_32 -> V_68 -> V_86 == V_252 ) {
unsigned int V_228 ;
V_247 = F_77 ( V_246 -> V_229 ) ;
V_247 = F_32 ( V_247 ) ;
V_228 = F_78 ( V_246 -> V_229 ) ;
V_189 . V_229 = F_79 ( V_247 , V_228 ) ;
} else {
V_189 . V_229 = F_32 ( V_246 -> V_229 ) ;
V_247 = F_74 ( V_189 . V_229 ) ;
}
#else
V_189 . V_229 = F_32 ( V_246 -> V_229 ) ;
V_247 = F_74 ( V_189 . V_229 ) ;
#endif
V_189 . V_216 = F_32 ( V_246 -> V_216 ) ;
V_70 = V_32 -> V_118 + V_247 ;
if ( F_57 ( V_70 -> V_124 ) )
continue;
if ( F_80 ( V_248 , V_246 , V_163 ) )
F_65 ( V_163 , & V_189 ) ;
F_69 ( V_6 , V_32 , & V_189 , V_70 , V_163 ) ;
}
}
static void F_81 ( const char * V_6 , struct V_31 * V_32 ,
T_4 * V_154 )
{
T_5 * V_70 ;
T_10 * V_253 ;
T_9 V_189 ;
unsigned int V_247 ;
const char * V_163 ;
T_10 * V_248 = ( void * ) V_32 -> V_68 + V_154 -> V_108 ;
T_10 * V_249 = ( void * ) V_248 + V_154 -> V_100 ;
V_163 = F_47 ( V_32 , V_154 ) ;
V_163 += strlen ( L_119 ) ;
if ( F_48 ( V_163 , V_161 ) )
return;
for ( V_253 = V_248 ; V_253 < V_249 ; V_253 ++ ) {
V_189 . V_215 = F_32 ( V_253 -> V_215 ) ;
#if V_250 == V_251
if ( V_32 -> V_68 -> V_86 == V_252 ) {
unsigned int V_228 ;
V_247 = F_77 ( V_253 -> V_229 ) ;
V_247 = F_32 ( V_247 ) ;
V_228 = F_78 ( V_253 -> V_229 ) ;
V_189 . V_229 = F_79 ( V_247 , V_228 ) ;
} else {
V_189 . V_229 = F_32 ( V_253 -> V_229 ) ;
V_247 = F_74 ( V_189 . V_229 ) ;
}
#else
V_189 . V_229 = F_32 ( V_253 -> V_229 ) ;
V_247 = F_74 ( V_189 . V_229 ) ;
#endif
V_189 . V_216 = 0 ;
switch ( V_32 -> V_68 -> V_86 ) {
case V_254 :
if ( F_71 ( V_32 , V_154 , & V_189 ) )
continue;
break;
case V_255 :
if ( F_73 ( V_32 , V_154 , & V_189 ) )
continue;
break;
case V_252 :
if ( F_75 ( V_32 , V_154 , & V_189 ) )
continue;
break;
}
V_70 = V_32 -> V_118 + V_247 ;
if ( F_57 ( V_70 -> V_124 ) )
continue;
if ( F_80 ( V_248 , V_253 , V_163 ) )
F_65 ( V_163 , & V_189 ) ;
F_69 ( V_6 , V_32 , & V_189 , V_70 , V_163 ) ;
}
}
static void F_82 ( struct V_10 * V_11 , const char * V_6 ,
struct V_31 * V_32 )
{
int V_19 ;
T_4 * V_69 = V_32 -> V_69 ;
for ( V_19 = 0 ; V_19 < V_32 -> V_99 ; V_19 ++ ) {
F_50 ( V_6 , V_32 , & V_32 -> V_69 [ V_19 ] ) ;
if ( V_69 [ V_19 ] . V_105 == V_256 )
F_76 ( V_6 , V_32 , & V_32 -> V_69 [ V_19 ] ) ;
else if ( V_69 [ V_19 ] . V_105 == V_257 )
F_81 ( V_6 , V_32 , & V_32 -> V_69 [ V_19 ] ) ;
}
}
static char * F_83 ( char * V_22 )
{
T_2 V_258 = strcspn ( V_22 , L_120 ) ;
if ( V_258 && V_22 [ V_258 ] ) {
T_2 V_259 = strspn ( V_22 + V_258 + 1 , L_121 ) ;
if ( V_259 && ( V_22 [ V_258 + V_259 ] == '.' || V_22 [ V_258 + V_259 ] == 0 ) )
V_22 [ V_258 ] = 0 ;
}
return V_22 ;
}
static void F_84 ( char * V_6 )
{
const char * V_127 ;
char * V_260 ;
char * V_261 ;
struct V_10 * V_11 ;
struct V_31 V_67 = { } ;
T_5 * V_70 ;
if ( ! F_31 ( & V_67 , V_6 ) )
return;
V_11 = F_8 ( V_6 ) ;
if ( F_5 ( V_6 ) ) {
V_262 = 1 ;
V_11 -> V_65 = 1 ;
}
V_261 = F_44 ( V_67 . V_114 , V_67 . V_115 , L_122 ) ;
if ( V_67 . V_114 && ! V_261 && ! F_5 ( V_6 ) )
F_2 ( L_123
L_124
L_125 , V_6 ) ;
while ( V_261 ) {
if ( F_85 ( V_261 ) )
V_11 -> V_17 = 1 ;
else {
V_11 -> V_17 = 0 ;
break;
}
V_261 = F_43 ( V_67 . V_114 , V_67 . V_115 ,
L_122 , V_261 ) ;
}
for ( V_70 = V_67 . V_118 ; V_70 < V_67 . V_119 ; V_70 ++ ) {
V_127 = F_83 ( V_67 . V_120 + V_70 -> V_125 ) ;
F_36 ( V_11 , & V_67 , V_70 , V_127 ) ;
F_86 ( V_11 , & V_67 , V_70 , V_127 ) ;
}
if ( ! F_5 ( V_6 ) ||
( F_5 ( V_6 ) && V_263 ) )
F_82 ( V_11 , V_6 , & V_67 ) ;
V_260 = F_44 ( V_67 . V_114 , V_67 . V_115 , L_126 ) ;
if ( V_260 )
F_87 ( V_6 , V_260 , V_67 . V_114 ,
V_260 - ( char * ) V_67 . V_68 ) ;
if ( V_260 || ( V_264 && ! F_5 ( V_6 ) ) )
F_88 ( V_6 , V_11 -> V_265 ,
sizeof( V_11 -> V_265 ) - 1 ) ;
F_33 ( & V_67 ) ;
if ( V_266 )
V_11 -> V_141 = F_12 ( L_127 , 0 , V_11 -> V_141 ) ;
}
static void F_89 ( const char * V_50 )
{
T_11 * V_267 = V_268 ;
char V_269 [ V_270 ] ;
if ( strcmp ( V_50 , L_128 ) != 0 ) {
V_267 = fopen ( V_50 , L_129 ) ;
if ( ! V_267 )
F_1 ( L_130 , V_50 ) ;
}
while ( fgets ( V_269 , V_270 , V_267 ) != NULL ) {
if ( F_4 ( V_269 , L_58 ) )
V_269 [ strlen ( V_269 ) - 1 ] = '\0' ;
F_84 ( V_269 ) ;
}
if ( V_267 != V_268 )
fclose ( V_267 ) ;
}
void F_90 ( struct V_271 * V_272 , const char * V_22 , int V_66 )
{
if ( V_272 -> V_51 - V_272 -> V_63 < V_66 ) {
V_272 -> V_51 += V_66 + V_273 ;
V_272 -> V_15 = realloc ( V_272 -> V_15 , V_272 -> V_51 ) ;
}
strncpy ( V_272 -> V_15 + V_272 -> V_63 , V_22 , V_66 ) ;
V_272 -> V_63 += V_66 ;
}
static void F_91 ( enum V_23 exp , const char * V_259 , const char * V_22 )
{
const char * V_274 = F_5 ( V_259 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_37 :
F_1 ( L_131
L_132 , V_259 , V_274 , V_22 ) ;
break;
case V_38 :
F_1 ( L_131
L_133 , V_259 , V_274 , V_22 ) ;
break;
case V_39 :
F_2 ( L_131
L_134 , V_259 , V_274 , V_22 ) ;
break;
case V_35 :
case V_36 :
case V_30 :
break;
}
}
static void F_92 ( enum V_23 exp , const char * V_259 , const char * V_22 )
{
const char * V_274 = F_5 ( V_259 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_36 :
case V_38 :
F_2 ( L_135
L_136 , V_259 , V_274 , V_22 ) ;
break;
default:
break;
}
}
static void F_93 ( struct V_10 * V_11 )
{
struct V_20 * V_22 , * exp ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
const char * V_275 ;
exp = F_14 ( V_22 -> V_14 ) ;
if ( ! exp || exp -> V_10 == V_11 )
continue;
V_275 = strrchr ( V_11 -> V_14 , '/' ) ;
if ( V_275 )
V_275 ++ ;
else
V_275 = V_11 -> V_14 ;
if ( ! V_11 -> V_17 )
F_91 ( exp -> V_23 , V_275 , exp -> V_14 ) ;
F_92 ( exp -> V_23 , V_275 , exp -> V_14 ) ;
}
}
static void F_94 ( struct V_271 * V_276 , struct V_10 * V_11 )
{
F_95 ( V_276 , L_137 ) ;
F_95 ( V_276 , L_138 ) ;
F_95 ( V_276 , L_139 ) ;
F_95 ( V_276 , L_58 ) ;
F_95 ( V_276 , L_140 ) ;
F_95 ( V_276 , L_58 ) ;
F_95 ( V_276 , L_141 ) ;
F_95 ( V_276 , L_142 ) ;
F_95 ( V_276 , L_143 ) ;
if ( V_11 -> V_144 )
F_95 ( V_276 , L_144 ) ;
if ( V_11 -> V_146 )
F_95 ( V_276 , L_145
L_146
L_147 ) ;
F_95 ( V_276 , L_148 ) ;
F_95 ( V_276 , L_149 ) ;
}
static void F_96 ( struct V_271 * V_276 , int V_277 )
{
if ( V_277 )
F_95 ( V_276 , L_150 ) ;
}
static void F_97 ( struct V_271 * V_276 , const char * V_14 )
{
static const char * V_278 = L_151 ;
if ( strncmp ( V_278 , V_14 , strlen ( V_278 ) ) == 0 )
F_95 ( V_276 , L_152 ) ;
}
static int F_98 ( struct V_271 * V_276 , struct V_10 * V_11 )
{
struct V_20 * V_22 , * exp ;
int V_279 = 0 ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
exp = F_14 ( V_22 -> V_14 ) ;
if ( ! exp || exp -> V_10 == V_11 ) {
if ( V_262 && ! V_22 -> V_21 ) {
if ( V_280 ) {
F_2 ( L_153 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
} else {
F_3 ( L_153 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
V_279 = 1 ;
}
}
continue;
}
V_22 -> V_10 = exp -> V_10 ;
V_22 -> V_49 = exp -> V_49 ;
V_22 -> V_48 = exp -> V_48 ;
}
if ( ! V_266 )
return V_279 ;
F_95 ( V_276 , L_58 ) ;
F_95 ( V_276 , L_154 ) ;
F_95 ( V_276 , L_155 ) ;
F_95 ( V_276 , L_156 ) ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
if ( ! V_22 -> V_10 )
continue;
if ( ! V_22 -> V_49 ) {
F_2 ( L_157 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
continue;
}
F_95 ( V_276 , L_158 ,
V_22 -> V_48 , V_22 -> V_14 ) ;
}
F_95 ( V_276 , L_149 ) ;
return V_279 ;
}
static void F_99 ( struct V_271 * V_276 , struct V_10 * V_11 ,
struct V_10 * V_12 )
{
struct V_20 * V_22 ;
struct V_10 * V_259 ;
int V_281 = 1 ;
for ( V_259 = V_12 ; V_259 ; V_259 = V_259 -> V_13 )
V_259 -> V_282 = F_5 ( V_259 -> V_14 ) ;
F_95 ( V_276 , L_58 ) ;
F_95 ( V_276 , L_159 ) ;
F_95 ( V_276 , L_155 ) ;
F_95 ( V_276 , L_160 ) ;
F_95 ( V_276 , L_161 ) ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
const char * V_15 ;
if ( ! V_22 -> V_10 )
continue;
if ( V_22 -> V_10 -> V_282 )
continue;
V_22 -> V_10 -> V_282 = 1 ;
V_15 = strrchr ( V_22 -> V_10 -> V_14 , '/' ) ;
if ( V_15 )
V_15 ++ ;
else
V_15 = V_22 -> V_10 -> V_14 ;
F_95 ( V_276 , L_162 , V_281 ? L_15 : L_163 , V_15 ) ;
V_281 = 0 ;
}
F_95 ( V_276 , L_164 ) ;
}
static void F_100 ( struct V_271 * V_276 , struct V_10 * V_11 )
{
if ( V_11 -> V_265 [ 0 ] ) {
F_95 ( V_276 , L_58 ) ;
F_95 ( V_276 , L_165 ,
V_11 -> V_265 ) ;
}
}
static void F_101 ( struct V_271 * V_276 , const char * V_269 )
{
char * V_283 ;
T_11 * V_64 ;
struct V_52 V_53 ;
V_64 = fopen ( V_269 , L_129 ) ;
if ( ! V_64 )
goto V_284;
if ( F_25 ( fileno ( V_64 ) , & V_53 ) < 0 )
goto V_285;
if ( V_53 . V_59 != V_276 -> V_63 )
goto V_285;
V_283 = F_9 ( malloc ( V_276 -> V_63 ) ) ;
if ( fread ( V_283 , 1 , V_276 -> V_63 , V_64 ) != V_276 -> V_63 )
goto V_286;
if ( memcmp ( V_283 , V_276 -> V_15 , V_276 -> V_63 ) != 0 )
goto V_286;
free ( V_283 ) ;
fclose ( V_64 ) ;
return;
V_286:
free ( V_283 ) ;
V_285:
fclose ( V_64 ) ;
V_284:
V_64 = fopen ( V_269 , L_166 ) ;
if ( ! V_64 ) {
perror ( V_269 ) ;
exit ( 1 ) ;
}
if ( fwrite ( V_276 -> V_15 , 1 , V_276 -> V_63 , V_64 ) != V_276 -> V_63 ) {
perror ( V_269 ) ;
exit ( 1 ) ;
}
fclose ( V_64 ) ;
}
static void F_102 ( const char * V_269 , unsigned int V_47 )
{
unsigned long V_51 , V_63 = 0 ;
void * V_64 = F_23 ( V_269 , & V_51 ) ;
char * line ;
if ( ! V_64 )
return;
while ( ( line = F_28 ( & V_63 , V_64 , V_51 ) ) ) {
char * V_127 , * V_6 , * V_185 , * V_23 , * V_287 ;
unsigned int V_48 ;
struct V_10 * V_11 ;
struct V_20 * V_22 ;
if ( ! ( V_127 = strchr ( line , '\t' ) ) )
goto V_288;
* V_127 ++ = '\0' ;
if ( ! ( V_6 = strchr ( V_127 , '\t' ) ) )
goto V_288;
* V_6 ++ = '\0' ;
if ( ( V_23 = strchr ( V_6 , '\t' ) ) != NULL )
* V_23 ++ = '\0' ;
if ( V_23 && ( ( V_287 = strchr ( V_23 , '\t' ) ) != NULL ) )
* V_287 = '\0' ;
V_48 = strtoul ( line , & V_185 , 16 ) ;
if ( * V_127 == '\0' || * V_6 == '\0' || * V_185 != '\0' )
goto V_288;
V_11 = F_7 ( V_6 ) ;
if ( ! V_11 ) {
if ( F_5 ( V_6 ) )
V_262 = 1 ;
V_11 = F_8 ( V_6 ) ;
V_11 -> V_65 = 1 ;
}
V_22 = F_21 ( V_127 , V_11 , F_16 ( V_23 ) ) ;
V_22 -> V_47 = V_47 ;
V_22 -> V_45 = 1 ;
F_22 ( V_127 , V_11 , V_48 , F_16 ( V_23 ) ) ;
}
F_29 ( V_64 , V_51 ) ;
return;
V_288:
F_29 ( V_64 , V_51 ) ;
F_1 ( L_167 ) ;
}
static int F_103 ( struct V_20 * V_70 )
{
if ( ! V_289 )
return 1 ;
if ( V_70 -> V_46 || V_70 -> V_47 )
return 0 ;
return 1 ;
}
static void F_104 ( const char * V_269 )
{
struct V_271 V_272 = { } ;
struct V_20 * V_20 ;
int V_258 ;
for ( V_258 = 0 ; V_258 < V_26 ; V_258 ++ ) {
V_20 = V_27 [ V_258 ] ;
while ( V_20 ) {
if ( F_103 ( V_20 ) )
F_95 ( & V_272 , L_168 ,
V_20 -> V_48 , V_20 -> V_14 ,
V_20 -> V_10 -> V_14 ,
F_15 ( V_20 -> V_23 ) ) ;
V_20 = V_20 -> V_13 ;
}
}
F_101 ( & V_272 , V_269 ) ;
}
int main ( int V_290 , char * * V_291 )
{
struct V_10 * V_11 ;
struct V_271 V_272 = { } ;
char * V_292 = NULL , * V_293 = NULL ;
char * V_294 = NULL , * V_295 = NULL ;
int V_296 ;
int V_279 ;
struct V_297 * V_298 ;
struct V_297 * V_299 = NULL ;
while ( ( V_296 = F_105 ( V_290 , V_291 , L_169 ) ) != - 1 ) {
switch ( V_296 ) {
case 'i' :
V_292 = V_300 ;
break;
case 'I' :
V_293 = V_300 ;
V_289 = 1 ;
break;
case 'e' :
V_289 = 1 ;
V_298 =
F_9 ( malloc ( sizeof( * V_298 ) ) ) ;
V_298 -> V_13 = V_299 ;
V_298 -> V_64 = V_300 ;
V_299 = V_298 ;
break;
case 'm' :
V_266 = 1 ;
break;
case 'n' :
V_74 = 1 ;
break;
case 'o' :
V_294 = V_300 ;
break;
case 'a' :
V_264 = 1 ;
break;
case 's' :
V_263 = 0 ;
break;
case 'S' :
V_204 = 0 ;
break;
case 'T' :
V_295 = V_300 ;
break;
case 'w' :
V_280 = 1 ;
break;
default:
exit ( 1 ) ;
}
}
if ( V_292 )
F_102 ( V_292 , 1 ) ;
if ( V_293 )
F_102 ( V_293 , 0 ) ;
while ( V_299 ) {
F_102 ( V_299 -> V_64 , 0 ) ;
V_298 = V_299 -> V_13 ;
free ( V_299 ) ;
V_299 = V_298 ;
}
while ( V_301 < V_290 )
F_84 ( V_291 [ V_301 ++ ] ) ;
if ( V_295 )
F_89 ( V_295 ) ;
for ( V_11 = V_12 ; V_11 ; V_11 = V_11 -> V_13 ) {
if ( V_11 -> V_65 )
continue;
F_93 ( V_11 ) ;
}
V_279 = 0 ;
for ( V_11 = V_12 ; V_11 ; V_11 = V_11 -> V_13 ) {
char V_269 [ V_270 ] ;
if ( V_11 -> V_65 )
continue;
V_272 . V_63 = 0 ;
F_94 ( & V_272 , V_11 ) ;
F_96 ( & V_272 , ! V_289 ) ;
F_97 ( & V_272 , V_11 -> V_14 ) ;
V_279 |= F_98 ( & V_272 , V_11 ) ;
F_99 ( & V_272 , V_11 , V_12 ) ;
F_106 ( & V_272 , V_11 ) ;
F_100 ( & V_272 , V_11 ) ;
sprintf ( V_269 , L_170 , V_11 -> V_14 ) ;
F_101 ( & V_272 , V_269 ) ;
}
if ( V_294 )
F_104 ( V_294 ) ;
if ( V_203 && ! V_204 )
F_2 ( L_171
L_172
L_173 ,
V_203 ) ;
return V_279 ;
}
