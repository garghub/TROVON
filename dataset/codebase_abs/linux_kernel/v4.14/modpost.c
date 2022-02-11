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
static const char * F_17 ( struct V_31 * V_32 , T_2 * V_33 )
{
return ( void * ) V_32 -> V_34 +
V_32 -> V_35 [ V_32 -> V_36 ] . V_37 +
V_33 -> V_38 ;
}
static const char * F_18 ( struct V_31 * V_32 , int V_39 )
{
return F_17 ( V_32 , & V_32 -> V_35 [ V_39 ] ) ;
}
static enum V_23 F_19 ( struct V_31 * V_32 , unsigned int V_40 )
{
const char * V_41 = F_18 ( V_32 , V_40 ) ;
if ( F_20 ( V_41 , L_8 ) )
return V_42 ;
else if ( F_20 ( V_41 , L_9 ) )
return V_43 ;
else if ( F_20 ( V_41 , L_10 ) )
return V_44 ;
else if ( F_20 ( V_41 , L_11 ) )
return V_45 ;
else if ( F_20 ( V_41 , L_12 ) )
return V_46 ;
else
return V_30 ;
}
static enum V_23 F_21 ( struct V_31 * V_32 , unsigned int V_40 )
{
if ( V_40 == V_32 -> V_47 )
return V_42 ;
else if ( V_40 == V_32 -> V_48 )
return V_43 ;
else if ( V_40 == V_32 -> V_49 )
return V_44 ;
else if ( V_40 == V_32 -> V_50 )
return V_45 ;
else if ( V_40 == V_32 -> V_51 )
return V_46 ;
else
return V_30 ;
}
static struct V_20 * F_22 ( const char * V_14 , struct V_10 * V_11 ,
enum V_23 V_23 )
{
struct V_20 * V_22 = F_14 ( V_14 ) ;
if ( ! V_22 ) {
V_22 = F_13 ( V_14 , V_11 , V_23 ) ;
} else {
if ( ! V_22 -> V_52 ) {
F_2 ( L_13
L_14 , V_11 -> V_14 , V_14 ,
V_22 -> V_10 -> V_14 ,
F_5 ( V_22 -> V_10 -> V_14 ) ? L_15 : L_16 ) ;
} else {
V_22 -> V_10 = V_11 ;
}
}
V_22 -> V_52 = 0 ;
V_22 -> V_53 = F_5 ( V_11 -> V_14 ) ;
V_22 -> V_54 = 0 ;
V_22 -> V_23 = V_23 ;
return V_22 ;
}
static void F_23 ( const char * V_14 , struct V_10 * V_11 ,
unsigned int V_55 , enum V_23 V_23 )
{
struct V_20 * V_22 = F_14 ( V_14 ) ;
if ( ! V_22 ) {
V_22 = F_13 ( V_14 , V_11 , V_23 ) ;
V_22 -> V_52 = 1 ;
}
V_22 -> V_55 = V_55 ;
V_22 -> V_56 = 1 ;
}
void * F_24 ( const char * V_57 , unsigned long * V_58 )
{
struct V_59 V_60 ;
void * V_61 = V_62 ;
int V_63 ;
V_63 = F_25 ( V_57 , V_64 ) ;
if ( V_63 < 0 )
return NULL ;
if ( F_26 ( V_63 , & V_60 ) )
goto V_65;
* V_58 = V_60 . V_66 ;
V_61 = F_27 ( NULL , * V_58 , V_67 | V_68 , V_69 , V_63 , 0 ) ;
V_65:
F_28 ( V_63 ) ;
if ( V_61 == V_62 )
return NULL ;
return V_61 ;
}
char * F_29 ( unsigned long * V_70 , void * V_71 , unsigned long V_58 )
{
static char line [ 4096 ] ;
int V_72 = 1 ;
T_3 V_73 = 0 ;
signed char * V_15 = ( signed char * ) V_71 + * V_70 ;
char * V_22 = line ;
for (; * V_70 < V_58 ; ( * V_70 ) ++ ) {
if ( V_72 && isspace ( * V_15 ) ) {
V_15 ++ ;
continue;
}
V_72 = 0 ;
if ( * V_15 != '\n' && ( * V_70 < V_58 ) ) {
V_73 ++ ;
* V_22 ++ = * V_15 ++ ;
if ( V_73 > 4095 )
break;
} else {
* V_22 = '\0' ;
return line ;
}
}
return NULL ;
}
void F_30 ( void * V_71 , unsigned long V_58 )
{
F_31 ( V_71 , V_58 ) ;
}
static int F_32 ( struct V_31 * V_74 , const char * V_57 )
{
unsigned int V_19 ;
T_4 * V_34 ;
T_2 * V_35 ;
T_5 * V_75 ;
const char * V_76 ;
unsigned int V_77 = ~ 0U , V_78 = ~ 0U ;
V_34 = F_24 ( V_57 , & V_74 -> V_58 ) ;
if ( ! V_34 ) {
if ( V_79 ) {
fprintf ( V_3 , L_17 , V_57 ,
strerror ( V_80 ) ) ;
return 0 ;
}
perror ( V_57 ) ;
exit ( 1 ) ;
}
V_74 -> V_34 = V_34 ;
if ( V_74 -> V_58 < sizeof( * V_34 ) ) {
return 0 ;
}
if ( ( V_34 -> V_81 [ V_82 ] != V_83 ) ||
( V_34 -> V_81 [ V_84 ] != V_85 ) ||
( V_34 -> V_81 [ V_86 ] != V_87 ) ||
( V_34 -> V_81 [ V_88 ] != V_89 ) ) {
return 0 ;
}
V_34 -> V_90 = F_33 ( V_34 -> V_90 ) ;
V_34 -> V_91 = F_33 ( V_34 -> V_91 ) ;
V_34 -> V_92 = F_33 ( V_34 -> V_92 ) ;
V_34 -> V_93 = F_33 ( V_34 -> V_93 ) ;
V_34 -> V_94 = F_33 ( V_34 -> V_94 ) ;
V_34 -> V_95 = F_33 ( V_34 -> V_95 ) ;
V_34 -> V_96 = F_33 ( V_34 -> V_96 ) ;
V_34 -> V_97 = F_33 ( V_34 -> V_97 ) ;
V_34 -> V_98 = F_33 ( V_34 -> V_98 ) ;
V_34 -> V_99 = F_33 ( V_34 -> V_99 ) ;
V_34 -> V_100 = F_33 ( V_34 -> V_100 ) ;
V_34 -> V_101 = F_33 ( V_34 -> V_101 ) ;
V_34 -> V_102 = F_33 ( V_34 -> V_102 ) ;
V_35 = ( void * ) V_34 + V_34 -> V_95 ;
V_74 -> V_35 = V_35 ;
if ( V_34 -> V_95 > V_74 -> V_58 ) {
F_1 ( L_18
L_19 , ( unsigned long ) V_34 -> V_95 ,
V_57 , V_74 -> V_58 ) ;
return 0 ;
}
if ( V_34 -> V_101 == V_103 ) {
V_74 -> V_104 = F_33 ( V_35 [ 0 ] . V_105 ) ;
}
else {
V_74 -> V_104 = V_34 -> V_101 ;
}
if ( V_34 -> V_102 == V_106 ) {
V_74 -> V_36 = F_33 ( V_35 [ 0 ] . V_107 ) ;
}
else {
V_74 -> V_36 = V_34 -> V_102 ;
}
for ( V_19 = 0 ; V_19 < V_74 -> V_104 ; V_19 ++ ) {
V_35 [ V_19 ] . V_38 = F_33 ( V_35 [ V_19 ] . V_38 ) ;
V_35 [ V_19 ] . V_108 = F_33 ( V_35 [ V_19 ] . V_108 ) ;
V_35 [ V_19 ] . V_109 = F_33 ( V_35 [ V_19 ] . V_109 ) ;
V_35 [ V_19 ] . V_110 = F_33 ( V_35 [ V_19 ] . V_110 ) ;
V_35 [ V_19 ] . V_37 = F_33 ( V_35 [ V_19 ] . V_37 ) ;
V_35 [ V_19 ] . V_105 = F_33 ( V_35 [ V_19 ] . V_105 ) ;
V_35 [ V_19 ] . V_107 = F_33 ( V_35 [ V_19 ] . V_107 ) ;
V_35 [ V_19 ] . V_111 = F_33 ( V_35 [ V_19 ] . V_111 ) ;
V_35 [ V_19 ] . V_112 = F_33 ( V_35 [ V_19 ] . V_112 ) ;
V_35 [ V_19 ] . V_113 = F_33 ( V_35 [ V_19 ] . V_113 ) ;
}
V_76 = ( void * ) V_34 + V_35 [ V_74 -> V_36 ] . V_37 ;
for ( V_19 = 1 ; V_19 < V_74 -> V_104 ; V_19 ++ ) {
const char * V_41 ;
int V_114 = V_35 [ V_19 ] . V_108 == V_115 ;
if ( ! V_114 && V_35 [ V_19 ] . V_37 > V_74 -> V_58 ) {
F_1 ( L_20
L_21 , V_57 ,
( unsigned long ) V_35 [ V_19 ] . V_37 ,
sizeof( * V_34 ) ) ;
return 0 ;
}
V_41 = V_76 + V_35 [ V_19 ] . V_38 ;
if ( strcmp ( V_41 , L_22 ) == 0 ) {
if ( V_114 )
F_1 ( L_23 , V_57 ) ;
V_74 -> V_116 = ( void * ) V_34 + V_35 [ V_19 ] . V_37 ;
V_74 -> V_117 = V_35 [ V_19 ] . V_105 ;
} else if ( strcmp ( V_41 , L_24 ) == 0 )
V_74 -> V_47 = V_19 ;
else if ( strcmp ( V_41 , L_25 ) == 0 )
V_74 -> V_48 = V_19 ;
else if ( strcmp ( V_41 , L_26 ) == 0 )
V_74 -> V_49 = V_19 ;
else if ( strcmp ( V_41 , L_27 ) == 0 )
V_74 -> V_50 = V_19 ;
else if ( strcmp ( V_41 , L_28 ) == 0 )
V_74 -> V_51 = V_19 ;
if ( V_35 [ V_19 ] . V_108 == V_118 ) {
unsigned int V_119 ;
V_77 = V_19 ;
V_74 -> V_120 = ( void * ) V_34 +
V_35 [ V_19 ] . V_37 ;
V_74 -> V_121 = ( void * ) V_34 +
V_35 [ V_19 ] . V_37 + V_35 [ V_19 ] . V_105 ;
V_119 = V_35 [ V_19 ] . V_107 ;
V_74 -> V_122 = ( void * ) V_34 +
V_35 [ V_119 ] . V_37 ;
}
if ( V_35 [ V_19 ] . V_108 == V_123 ) {
V_78 = V_19 ;
V_74 -> V_124 = ( void * ) V_34 +
V_35 [ V_19 ] . V_37 ;
V_74 -> V_125 = ( void * ) V_34 +
V_35 [ V_19 ] . V_37 + V_35 [ V_19 ] . V_105 ;
}
}
if ( ! V_74 -> V_120 )
F_1 ( L_29 , V_57 ) ;
for ( V_75 = V_74 -> V_120 ; V_75 < V_74 -> V_121 ; V_75 ++ ) {
V_75 -> V_126 = F_33 ( V_75 -> V_126 ) ;
V_75 -> V_127 = F_33 ( V_75 -> V_127 ) ;
V_75 -> V_128 = F_33 ( V_75 -> V_128 ) ;
V_75 -> V_66 = F_33 ( V_75 -> V_66 ) ;
}
if ( V_78 != ~ 0U ) {
T_6 * V_15 ;
if ( V_77 != V_35 [ V_78 ] . V_107 )
F_1 ( L_30 ,
V_57 , V_35 [ V_78 ] . V_107 ,
V_77 ) ;
for ( V_15 = V_74 -> V_124 ; V_15 < V_74 -> V_125 ;
V_15 ++ )
* V_15 = F_33 ( * V_15 ) ;
}
return 1 ;
}
static void F_34 ( struct V_31 * V_74 )
{
F_30 ( V_74 -> V_34 , V_74 -> V_58 ) ;
}
static int F_35 ( struct V_31 * V_74 , const char * V_129 )
{
if ( strcmp ( V_129 , F_36 ( V_130 ) ) == 0 )
return 1 ;
if ( strcmp ( V_129 , L_31 ) == 0 )
return 1 ;
if ( V_74 -> V_34 -> V_91 == V_131 )
if ( strncmp ( V_129 , L_32 , sizeof( L_32 ) - 1 ) == 0 ||
strncmp ( V_129 , L_33 , sizeof( L_33 ) - 1 ) == 0 ||
strncmp ( V_129 , L_34 , sizeof( L_34 ) - 1 ) == 0 ||
strncmp ( V_129 , L_35 , sizeof( L_35 ) - 1 ) == 0 ||
strncmp ( V_129 , L_36 , sizeof( L_36 ) - 1 ) == 0 ||
strncmp ( V_129 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
return 1 ;
if ( V_74 -> V_34 -> V_91 == V_132 )
if ( strncmp ( V_129 , L_38 , sizeof( L_38 ) - 1 ) == 0 ||
strncmp ( V_129 , L_39 , sizeof( L_39 ) - 1 ) == 0 ||
strncmp ( V_129 , L_36 , sizeof( L_36 ) - 1 ) == 0 ||
strncmp ( V_129 , L_37 , sizeof( L_37 ) - 1 ) == 0 ||
strcmp ( V_129 , L_40 ) == 0 )
return 1 ;
return 0 ;
}
static void F_37 ( struct V_10 * V_11 , struct V_31 * V_74 ,
T_5 * V_75 , const char * V_129 )
{
unsigned int V_55 ;
enum V_23 V_23 ;
bool V_133 = false ;
if ( ( ! F_5 ( V_11 -> V_14 ) || V_11 -> V_16 ) &&
strncmp ( V_129 , L_24 , 9 ) == 0 )
V_23 = F_19 ( V_74 , F_38 ( V_74 , V_75 ) ) ;
else
V_23 = F_21 ( V_74 , F_38 ( V_74 , V_75 ) ) ;
if ( strncmp ( V_129 , V_134 , strlen ( V_134 ) ) == 0 ) {
V_133 = true ;
V_55 = ( unsigned int ) V_75 -> V_128 ;
if ( V_75 -> V_126 != V_103 && V_75 -> V_126 != V_135 ) {
unsigned int * V_136 ;
V_136 = ( void * ) V_74 -> V_34 + V_75 -> V_128 +
V_74 -> V_35 [ V_75 -> V_126 ] . V_37 -
( V_74 -> V_34 -> V_90 != V_137 ?
V_74 -> V_35 [ V_75 -> V_126 ] . V_110 : 0 ) ;
V_55 = * V_136 ;
}
F_23 ( V_129 + strlen ( V_134 ) , V_11 , V_55 ,
V_23 ) ;
}
switch ( V_75 -> V_126 ) {
case V_138 :
if ( ! strncmp ( V_129 , L_41 , sizeof( L_41 ) - 1 ) ) {
} else
F_2 ( L_42 , V_129 , V_11 -> V_14 ) ;
break;
case V_103 :
if ( F_39 ( V_75 -> V_139 ) != V_140 &&
F_39 ( V_75 -> V_139 ) != V_141 )
break;
if ( F_35 ( V_74 , V_129 ) )
break;
#if F_40 ( V_142 ) || F_40 ( V_143 )
#ifndef V_143
#define V_143 STT_REGISTER
#endif
if ( V_74 -> V_34 -> V_91 == V_144 ||
V_74 -> V_34 -> V_91 == V_145 ) {
if ( F_41 ( V_75 -> V_139 ) == V_143 )
break;
if ( V_129 [ 0 ] == '.' ) {
char * V_146 = F_10 ( V_129 ) ;
V_146 [ 0 ] = '_' ;
V_146 [ 1 ] = toupper ( V_146 [ 1 ] ) ;
V_129 = V_146 ;
}
}
#endif
#ifdef F_42
if ( V_129 [ 0 ] != '_' )
break;
else
V_129 ++ ;
#endif
if ( V_133 ) {
const char * V_147 = F_5 ( V_11 -> V_14 ) ? L_15 : L_16 ;
F_2 ( L_43 , V_129 + strlen ( V_134 ) , V_11 -> V_14 , V_147 ) ;
}
V_11 -> V_148 = F_12 ( V_129 ,
F_39 ( V_75 -> V_139 ) == V_141 ,
V_11 -> V_148 ) ;
break;
default:
if ( strncmp ( V_129 , V_149 , strlen ( V_149 ) ) == 0 ) {
F_22 ( V_129 + strlen ( V_149 ) , V_11 ,
V_23 ) ;
}
if ( strcmp ( V_129 , F_36 ( V_150 ) ) == 0 )
V_11 -> V_151 = 1 ;
if ( strcmp ( V_129 , F_36 ( V_152 ) ) == 0 )
V_11 -> V_153 = 1 ;
break;
}
}
static char * F_43 ( char * string , unsigned long * V_154 )
{
while ( string [ 0 ] ) {
string ++ ;
if ( ( * V_154 ) -- <= 1 )
return NULL ;
}
while ( ! string [ 0 ] ) {
string ++ ;
if ( ( * V_154 ) -- <= 1 )
return NULL ;
}
return string ;
}
static char * F_44 ( void * V_116 , unsigned long V_117 ,
const char * V_155 , char * V_74 )
{
char * V_15 ;
unsigned int V_156 = strlen ( V_155 ) ;
unsigned long V_58 = V_117 ;
if ( V_74 ) {
V_58 -= V_74 - ( char * ) V_116 ;
V_116 = F_43 ( V_74 , & V_58 ) ;
}
for ( V_15 = V_116 ; V_15 ; V_15 = F_43 ( V_15 , & V_58 ) ) {
if ( strncmp ( V_15 , V_155 , V_156 ) == 0 && V_15 [ V_156 ] == '=' )
return V_15 + V_156 + 1 ;
}
return NULL ;
}
static char * F_45 ( void * V_116 , unsigned long V_117 ,
const char * V_155 )
{
return F_44 ( V_116 , V_117 , V_155 , NULL ) ;
}
static int F_46 ( const char * V_22 , const char * V_157 )
{
int V_158 , V_159 ;
if ( ! V_22 || ! V_157 )
return 1 ;
V_158 = strlen ( V_22 ) ;
V_159 = strlen ( V_157 ) ;
if ( ( V_158 == 0 ) || ( V_159 == 0 ) )
return 1 ;
if ( V_159 > V_158 )
return 1 ;
return memcmp ( V_22 + V_158 - V_159 , V_157 , V_159 ) ;
}
static const char * F_47 ( struct V_31 * V_32 , T_5 * V_75 )
{
if ( V_75 )
return V_32 -> V_122 + V_75 -> V_127 ;
else
return L_44 ;
}
static int F_48 ( const char * V_75 , const char * const V_160 [] )
{
const char * V_15 ;
while ( * V_160 ) {
V_15 = * V_160 ++ ;
const char * V_161 = V_15 + strlen ( V_15 ) - 1 ;
if ( * V_15 == '*' && * V_161 == '*' ) {
char * V_162 , * V_163 = F_49 ( V_15 + 1 , strlen ( V_15 ) - 2 ) ;
V_162 = strstr ( V_75 , V_163 ) ;
free ( V_163 ) ;
if ( V_162 != NULL )
return 1 ;
}
else if ( * V_15 == '*' ) {
if ( F_46 ( V_75 , V_15 + 1 ) == 0 )
return 1 ;
}
else if ( * V_161 == '*' ) {
if ( strncmp ( V_75 , V_15 , strlen ( V_15 ) - 1 ) == 0 )
return 1 ;
}
else {
if ( strcmp ( V_15 , V_75 ) == 0 )
return 1 ;
}
}
return 0 ;
}
static void F_50 ( const char * V_6 , struct V_31 * V_32 ,
T_2 * V_33 )
{
const char * V_40 = F_17 ( V_32 , V_33 ) ;
if ( V_33 -> V_108 == V_164 &&
! ( V_33 -> V_109 & V_165 ) &&
! F_48 ( V_40 , V_166 ) ) {
F_2 ( L_45
L_46
L_47
L_48 ,
V_6 , V_40 ) ;
}
}
static const struct V_167 * F_51 (
const char * V_168 , const char * V_169 )
{
int V_19 ;
int V_170 = sizeof( V_167 ) / sizeof( struct V_167 ) ;
const struct V_167 * V_171 = & V_167 [ 0 ] ;
if ( * V_169 == '\0' )
return NULL ;
for ( V_19 = 0 ; V_19 < V_170 ; V_19 ++ ) {
if ( F_48 ( V_168 , V_171 -> V_168 ) ) {
if ( V_171 -> V_172 [ 0 ] && F_48 ( V_169 , V_171 -> V_172 ) )
return V_171 ;
if ( V_171 -> V_173 [ 0 ] && ! F_48 ( V_169 , V_171 -> V_173 ) )
return V_171 ;
}
V_171 ++ ;
}
return NULL ;
}
static int F_52 ( const struct V_167 * V_174 ,
const char * V_168 , const char * V_175 ,
const char * V_169 , const char * V_176 )
{
if ( F_48 ( V_169 , V_177 ) &&
F_48 ( V_168 , V_178 ) &&
( strncmp ( V_175 , L_49 , strlen ( L_49 ) ) == 0 ) )
return 0 ;
if ( strcmp ( V_169 , L_50 ) == 0 &&
F_48 ( V_168 , V_178 ) &&
( strncmp ( V_175 , L_51 , strlen ( L_51 ) ) == 0 ) )
return 0 ;
if ( F_48 ( V_169 , V_179 ) &&
F_48 ( V_168 , V_178 ) &&
F_48 ( V_175 , V_174 -> V_180 ) )
return 0 ;
if ( F_48 ( V_168 , V_181 ) &&
F_48 ( V_169 , V_182 ) )
return 0 ;
if ( F_48 ( V_176 , V_183 ) )
return 0 ;
if ( F_48 ( V_168 , V_184 ) &&
F_48 ( V_169 , V_182 ) &&
F_48 ( V_175 , V_185 ) )
return 0 ;
return 1 ;
}
static T_5 * F_53 ( struct V_31 * V_32 , T_7 V_186 ,
T_5 * V_187 )
{
T_5 * V_75 ;
T_5 * V_188 = NULL ;
T_7 V_189 = 20 ;
T_7 V_190 ;
unsigned int V_191 ;
if ( V_187 -> V_127 != 0 )
return V_187 ;
V_191 = F_38 ( V_32 , V_187 ) ;
for ( V_75 = V_32 -> V_120 ; V_75 < V_32 -> V_121 ; V_75 ++ ) {
if ( F_38 ( V_32 , V_75 ) != V_191 )
continue;
if ( F_41 ( V_75 -> V_139 ) == V_192 )
continue;
if ( V_75 -> V_128 == V_186 )
return V_75 ;
V_190 = V_75 -> V_128 - V_186 ;
if ( V_190 < 0 )
V_190 = V_186 - V_75 -> V_128 ;
if ( V_190 < V_189 ) {
V_189 = V_190 ;
V_188 = V_75 ;
}
}
if ( V_189 < 20 )
return V_188 ;
else
return NULL ;
}
static inline int F_54 ( const char * V_4 )
{
return V_4 [ 0 ] == '$' && strchr ( L_52 , V_4 [ 1 ] )
&& ( V_4 [ 2 ] == '\0' || V_4 [ 2 ] == '.' ) ;
}
static inline int F_55 ( struct V_31 * V_32 , T_5 * V_75 )
{
const char * V_14 = V_32 -> V_122 + V_75 -> V_127 ;
if ( ! V_14 || ! strlen ( V_14 ) )
return 0 ;
return ! F_54 ( V_14 ) ;
}
static T_5 * F_56 ( struct V_31 * V_32 , T_8 V_186 ,
const char * V_40 )
{
T_5 * V_75 ;
T_5 * V_188 = NULL ;
T_8 V_189 = ~ 0 ;
for ( V_75 = V_32 -> V_120 ; V_75 < V_32 -> V_121 ; V_75 ++ ) {
const char * V_193 ;
if ( F_57 ( V_75 -> V_126 ) )
continue;
V_193 = F_18 ( V_32 , F_38 ( V_32 , V_75 ) ) ;
if ( strcmp ( V_193 , V_40 ) != 0 )
continue;
if ( ! F_55 ( V_32 , V_75 ) )
continue;
if ( V_75 -> V_128 <= V_186 ) {
if ( ( V_186 - V_75 -> V_128 ) < V_189 ) {
V_189 = V_186 - V_75 -> V_128 ;
V_188 = V_75 ;
} else if ( ( V_186 - V_75 -> V_128 ) == V_189 ) {
V_188 = V_75 ;
}
}
}
return V_188 ;
}
static char * F_58 ( const char * V_22 )
{
if ( F_48 ( V_22 , V_179 ) ) {
char * V_15 = malloc ( 20 ) ;
char * V_194 = V_15 ;
* V_15 ++ = '_' ;
* V_15 ++ = '_' ;
if ( * V_22 == '.' )
V_22 ++ ;
while ( * V_22 && * V_22 != '.' )
* V_15 ++ = * V_22 ++ ;
* V_15 = '\0' ;
if ( * V_22 == '.' )
V_22 ++ ;
if ( strstr ( V_22 , L_53 ) != NULL )
strcat ( V_15 , L_54 ) ;
else if ( strstr ( V_22 , L_55 ) != NULL )
strcat ( V_15 , L_56 ) ;
else
strcat ( V_15 , L_57 ) ;
return V_194 ;
} else {
return F_10 ( L_15 ) ;
}
}
static int F_59 ( T_5 * V_75 )
{
if ( V_75 )
return F_41 ( V_75 -> V_139 ) == V_195 ;
else
return - 1 ;
}
static void F_60 ( const char * const V_196 [ 20 ] )
{
const char * const * V_22 = V_196 ;
while ( * V_22 ) {
fprintf ( V_3 , L_58 , * V_22 ) ;
V_22 ++ ;
if ( * V_22 )
fprintf ( V_3 , L_59 ) ;
}
fprintf ( V_3 , L_60 ) ;
}
static inline void F_61 ( int V_197 , const char * * V_14 , const char * * V_198 )
{
switch ( V_197 ) {
case 0 : * V_14 = L_61 ; * V_198 = L_15 ; break;
case 1 : * V_14 = L_62 ; * V_198 = L_63 ; break;
default: * V_14 = L_64 ; * V_198 = L_15 ; break;
}
}
static void F_62 ( const char * V_6 ,
const struct V_167 * V_174 ,
const char * V_168 ,
unsigned long long V_199 ,
const char * V_175 ,
int V_200 ,
const char * V_169 , const char * V_176 ,
int V_201 )
{
const char * V_202 , * V_203 ;
const char * V_204 , * V_205 ;
char * V_206 ;
char * V_207 ;
V_208 ++ ;
if ( ! V_209 )
return;
F_61 ( V_200 , & V_202 , & V_203 ) ;
F_61 ( V_201 , & V_204 , & V_205 ) ;
F_2 ( L_65
L_66 ,
V_6 , V_168 , V_199 , V_202 , V_175 , V_203 , V_204 , V_169 ,
V_176 , V_205 ) ;
switch ( V_174 -> V_174 ) {
case V_210 :
V_206 = F_58 ( V_168 ) ;
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_67
L_68
L_69
L_70 ,
V_206 , V_175 ,
V_204 , V_207 , V_176 , V_205 ,
V_175 , V_207 , V_176 ) ;
free ( V_206 ) ;
free ( V_207 ) ;
break;
case V_211 : {
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_71
L_72
L_73
L_74
L_75 ,
V_175 , V_204 , V_207 , V_176 , V_205 ) ;
F_60 ( V_174 -> V_180 ) ;
free ( V_207 ) ;
break;
}
case V_212 :
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_76
L_77
L_78 ,
V_175 , V_204 , V_204 , V_176 , V_205 , V_207 , V_176 ) ;
free ( V_207 ) ;
break;
case V_213 : {
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_71
L_72
L_73
L_79
L_80 ,
V_175 , V_204 , V_207 , V_176 , V_205 ) ;
F_60 ( V_174 -> V_180 ) ;
free ( V_207 ) ;
break;
}
case V_214 :
case V_215 :
V_206 = F_58 ( V_168 ) ;
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_81
L_82
L_83
L_84 ,
V_202 , V_206 , V_175 , V_203 ,
V_204 , V_207 , V_176 , V_205 ,
V_176 , V_175 , V_176 ) ;
free ( V_206 ) ;
free ( V_207 ) ;
break;
case V_216 :
V_206 = F_58 ( V_168 ) ;
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_81
L_82
L_85
L_86
L_87
L_88
L_89 ,
V_202 , V_206 , V_175 , V_203 ,
V_204 , V_207 , V_176 , V_205 ,
V_207 , V_176 , V_205 ) ;
free ( V_206 ) ;
free ( V_207 ) ;
break;
case V_217 :
V_206 = F_58 ( V_168 ) ;
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_81
L_82
L_85
L_90
L_91
L_88
L_92 ,
V_202 , V_206 , V_175 , V_203 ,
V_204 , V_207 , V_176 , V_205 ,
V_207 , V_176 , V_205 ) ;
free ( V_206 ) ;
free ( V_207 ) ;
break;
case V_218 :
V_207 = F_58 ( V_169 ) ;
fprintf ( V_3 ,
L_93
L_94
L_95 ,
V_176 , V_207 , V_207 , V_176 ) ;
free ( V_207 ) ;
break;
case V_219 :
F_1 ( L_96
L_97 ) ;
break;
}
fprintf ( V_3 , L_60 ) ;
}
static void F_63 ( const char * V_6 , struct V_31 * V_32 ,
const struct V_167 * const V_174 ,
T_9 * V_194 , T_5 * V_75 , const char * V_168 )
{
const char * V_169 ;
T_5 * V_204 ;
T_5 * V_202 ;
const char * V_176 ;
const char * V_175 ;
V_202 = F_56 ( V_32 , V_194 -> V_220 , V_168 ) ;
V_175 = F_47 ( V_32 , V_202 ) ;
if ( ! strncmp ( V_175 , L_98 ,
sizeof( L_98 ) - 1 ) )
return;
V_169 = F_18 ( V_32 , F_38 ( V_32 , V_75 ) ) ;
V_204 = F_53 ( V_32 , V_194 -> V_221 , V_75 ) ;
V_176 = F_47 ( V_32 , V_204 ) ;
if ( F_52 ( V_174 ,
V_168 , V_175 , V_169 , V_176 ) ) {
F_62 ( V_6 , V_174 ,
V_168 , V_194 -> V_220 , V_175 ,
F_59 ( V_202 ) , V_169 , V_176 ,
F_59 ( V_204 ) ) ;
}
}
static int F_64 ( struct V_31 * V_32 , unsigned int V_222 )
{
if ( V_222 > V_32 -> V_104 )
F_1 ( L_99 ) ;
return ( ( V_32 -> V_35 [ V_222 ] . V_109 & V_223 ) == V_223 ) ;
}
static void F_65 ( const char * const V_40 , const T_9 * V_194 )
{
if ( ! V_224 )
V_224 = V_194 -> V_220 * 2 ;
}
static inline bool F_66 ( T_9 * V_194 )
{
if ( V_194 -> V_220 && V_224 == 0 )
F_1 ( L_100 ) ;
return ( ( V_194 -> V_220 == 0 ) ||
( V_194 -> V_220 % V_224 == 0 ) ) ;
}
static void F_67 ( const char * V_6 , struct V_31 * V_32 ,
const struct V_167 * const V_174 ,
T_9 * V_194 , T_5 * V_75 ,
const char * V_168 , const char * V_169 )
{
T_5 * V_175 = F_56 ( V_32 , V_194 -> V_220 , V_168 ) ;
const char * V_225 = F_47 ( V_32 , V_175 ) ;
T_5 * V_176 = F_53 ( V_32 , V_194 -> V_221 , V_75 ) ;
const char * V_226 = F_47 ( V_32 , V_176 ) ;
const char * V_227 ;
const char * V_228 ;
const char * V_229 ;
const char * V_230 ;
F_61 ( F_59 ( V_175 ) ,
& V_227 , & V_228 ) ;
F_61 ( F_59 ( V_176 ) ,
& V_229 , & V_230 ) ;
F_2 ( L_101
L_102 ,
V_6 , V_168 , ( long ) V_194 -> V_220 , V_227 ,
V_225 , V_228 ,
V_229 , V_169 , V_226 , V_230 ) ;
if ( ! F_48 ( V_169 , V_174 -> V_172 ) &&
F_64 ( V_32 , F_38 ( V_32 , V_75 ) ) )
fprintf ( V_3 ,
L_103
L_104
L_105
L_106
L_107
L_108
L_109 ,
V_168 , ( long ) V_194 -> V_220 , V_169 , V_169 , V_169 ) ;
}
static void F_68 ( const char * V_6 , struct V_31 * V_32 ,
const struct V_167 * const V_174 ,
T_9 * V_194 , T_5 * V_75 ,
const char * V_168 )
{
const char * V_169 = F_18 ( V_32 , F_38 ( V_32 , V_75 ) ) ;
V_208 ++ ;
if ( V_209 )
F_67 ( V_6 , V_32 , V_174 , V_194 , V_75 ,
V_168 , V_169 ) ;
if ( F_48 ( V_169 , V_174 -> V_172 ) )
F_1 ( L_103
L_110
L_111
L_112
L_113 ,
V_168 , ( long ) V_194 -> V_220 , V_169 , V_6 ) ;
else if ( ! F_64 ( V_32 , F_38 ( V_32 , V_75 ) ) ) {
if ( F_66 ( V_194 ) )
F_1 ( L_103
L_114
L_115
L_116
L_117 ,
V_168 , ( long ) V_194 -> V_220 , V_169 ) ;
else
F_1 ( L_103
L_114
L_118
L_119
L_117 ,
V_168 , ( long ) V_194 -> V_220 , V_169 ) ;
}
}
static void F_69 ( const char * V_6 , struct V_31 * V_32 ,
T_9 * V_194 , T_5 * V_75 , const char * V_168 )
{
const char * V_169 = F_18 ( V_32 , F_38 ( V_32 , V_75 ) ) ; ;
const struct V_167 * V_174 = F_51 ( V_168 , V_169 ) ;
if ( V_174 ) {
if ( V_174 -> V_231 )
V_174 -> V_231 ( V_6 , V_32 , V_174 ,
V_194 , V_75 , V_168 ) ;
else
F_63 ( V_6 , V_32 , V_174 ,
V_194 , V_75 , V_168 ) ;
}
}
static unsigned int * F_70 ( struct V_31 * V_32 ,
T_2 * V_33 , T_9 * V_194 )
{
T_2 * V_35 = V_32 -> V_35 ;
int V_232 = V_33 -> V_111 ;
return ( void * ) V_32 -> V_34 + V_35 [ V_232 ] . V_37 +
V_194 -> V_220 ;
}
static int F_71 ( struct V_31 * V_32 , T_2 * V_33 , T_9 * V_194 )
{
unsigned int V_233 = F_72 ( V_194 -> V_234 ) ;
unsigned int * V_235 = F_70 ( V_32 , V_33 , V_194 ) ;
switch ( V_233 ) {
case V_236 :
V_194 -> V_221 = F_33 ( * V_235 ) ;
break;
case V_237 :
V_194 -> V_221 = F_33 ( * V_235 ) + 4 ;
if ( V_32 -> V_34 -> V_90 == V_238 )
V_194 -> V_221 += V_194 -> V_220 ;
break;
}
return 0 ;
}
static int F_73 ( struct V_31 * V_32 , T_2 * V_33 , T_9 * V_194 )
{
unsigned int V_233 = F_72 ( V_194 -> V_234 ) ;
switch ( V_233 ) {
case V_239 :
V_194 -> V_221 = ( int ) ( long )
( V_32 -> V_120 + F_74 ( V_194 -> V_234 ) ) ;
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
V_194 -> V_221 = ( int ) ( long ) ( V_32 -> V_34 +
V_33 -> V_37 +
( V_194 -> V_220 - V_33 -> V_110 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_31 * V_32 , T_2 * V_33 , T_9 * V_194 )
{
unsigned int V_233 = F_72 ( V_194 -> V_234 ) ;
unsigned int * V_235 = F_70 ( V_32 , V_33 , V_194 ) ;
unsigned int V_246 ;
if ( V_233 == V_247 )
return 1 ;
V_246 = F_33 ( * V_235 ) ;
switch ( V_233 ) {
case V_248 :
V_194 -> V_221 = V_246 & 0xffff ;
break;
case V_249 :
V_194 -> V_221 = ( V_246 & 0x03ffffff ) << 2 ;
break;
case V_250 :
V_194 -> V_221 = V_246 ;
break;
}
return 0 ;
}
static void F_76 ( const char * V_6 , struct V_31 * V_32 ,
T_2 * V_33 )
{
T_5 * V_75 ;
T_9 * V_251 ;
T_9 V_194 ;
unsigned int V_252 ;
const char * V_168 ;
T_9 * V_253 = ( void * ) V_32 -> V_34 + V_33 -> V_37 ;
T_9 * V_254 = ( void * ) V_253 + V_33 -> V_105 ;
V_168 = F_17 ( V_32 , V_33 ) ;
V_168 += strlen ( L_120 ) ;
if ( F_48 ( V_168 , V_166 ) )
return;
for ( V_251 = V_253 ; V_251 < V_254 ; V_251 ++ ) {
V_194 . V_220 = F_33 ( V_251 -> V_220 ) ;
#if V_255 == V_256
if ( V_32 -> V_34 -> V_91 == V_257 ) {
unsigned int V_233 ;
V_252 = F_77 ( V_251 -> V_234 ) ;
V_252 = F_33 ( V_252 ) ;
V_233 = F_78 ( V_251 -> V_234 ) ;
V_194 . V_234 = F_79 ( V_252 , V_233 ) ;
} else {
V_194 . V_234 = F_33 ( V_251 -> V_234 ) ;
V_252 = F_74 ( V_194 . V_234 ) ;
}
#else
V_194 . V_234 = F_33 ( V_251 -> V_234 ) ;
V_252 = F_74 ( V_194 . V_234 ) ;
#endif
V_194 . V_221 = F_33 ( V_251 -> V_221 ) ;
V_75 = V_32 -> V_120 + V_252 ;
if ( F_57 ( V_75 -> V_126 ) )
continue;
if ( F_80 ( V_253 , V_251 , V_168 ) )
F_65 ( V_168 , & V_194 ) ;
F_69 ( V_6 , V_32 , & V_194 , V_75 , V_168 ) ;
}
}
static void F_81 ( const char * V_6 , struct V_31 * V_32 ,
T_2 * V_33 )
{
T_5 * V_75 ;
T_10 * V_258 ;
T_9 V_194 ;
unsigned int V_252 ;
const char * V_168 ;
T_10 * V_253 = ( void * ) V_32 -> V_34 + V_33 -> V_37 ;
T_10 * V_254 = ( void * ) V_253 + V_33 -> V_105 ;
V_168 = F_17 ( V_32 , V_33 ) ;
V_168 += strlen ( L_121 ) ;
if ( F_48 ( V_168 , V_166 ) )
return;
for ( V_258 = V_253 ; V_258 < V_254 ; V_258 ++ ) {
V_194 . V_220 = F_33 ( V_258 -> V_220 ) ;
#if V_255 == V_256
if ( V_32 -> V_34 -> V_91 == V_257 ) {
unsigned int V_233 ;
V_252 = F_77 ( V_258 -> V_234 ) ;
V_252 = F_33 ( V_252 ) ;
V_233 = F_78 ( V_258 -> V_234 ) ;
V_194 . V_234 = F_79 ( V_252 , V_233 ) ;
} else {
V_194 . V_234 = F_33 ( V_258 -> V_234 ) ;
V_252 = F_74 ( V_194 . V_234 ) ;
}
#else
V_194 . V_234 = F_33 ( V_258 -> V_234 ) ;
V_252 = F_74 ( V_194 . V_234 ) ;
#endif
V_194 . V_221 = 0 ;
switch ( V_32 -> V_34 -> V_91 ) {
case V_259 :
if ( F_71 ( V_32 , V_33 , & V_194 ) )
continue;
break;
case V_260 :
if ( F_73 ( V_32 , V_33 , & V_194 ) )
continue;
break;
case V_257 :
if ( F_75 ( V_32 , V_33 , & V_194 ) )
continue;
break;
}
V_75 = V_32 -> V_120 + V_252 ;
if ( F_57 ( V_75 -> V_126 ) )
continue;
if ( F_80 ( V_253 , V_258 , V_168 ) )
F_65 ( V_168 , & V_194 ) ;
F_69 ( V_6 , V_32 , & V_194 , V_75 , V_168 ) ;
}
}
static void F_82 ( struct V_10 * V_11 , const char * V_6 ,
struct V_31 * V_32 )
{
int V_19 ;
T_2 * V_35 = V_32 -> V_35 ;
for ( V_19 = 0 ; V_19 < V_32 -> V_104 ; V_19 ++ ) {
F_50 ( V_6 , V_32 , & V_32 -> V_35 [ V_19 ] ) ;
if ( V_35 [ V_19 ] . V_108 == V_261 )
F_76 ( V_6 , V_32 , & V_32 -> V_35 [ V_19 ] ) ;
else if ( V_35 [ V_19 ] . V_108 == V_262 )
F_81 ( V_6 , V_32 , & V_32 -> V_35 [ V_19 ] ) ;
}
}
static char * F_83 ( char * V_22 )
{
T_3 V_263 = strcspn ( V_22 , L_122 ) ;
if ( V_263 && V_22 [ V_263 ] ) {
T_3 V_264 = strspn ( V_22 + V_263 + 1 , L_123 ) ;
if ( V_264 && ( V_22 [ V_263 + V_264 ] == '.' || V_22 [ V_263 + V_264 ] == 0 ) )
V_22 [ V_263 ] = 0 ;
}
return V_22 ;
}
static void F_84 ( char * V_6 )
{
const char * V_129 ;
char * V_265 ;
char * V_266 ;
struct V_10 * V_11 ;
struct V_31 V_74 = { } ;
T_5 * V_75 ;
if ( ! F_32 ( & V_74 , V_6 ) )
return;
V_11 = F_8 ( V_6 ) ;
if ( F_5 ( V_6 ) ) {
V_267 = 1 ;
V_11 -> V_72 = 1 ;
}
V_266 = F_45 ( V_74 . V_116 , V_74 . V_117 , L_124 ) ;
if ( V_74 . V_116 && ! V_266 && ! F_5 ( V_6 ) )
F_2 ( L_125
L_126
L_127 , V_6 ) ;
while ( V_266 ) {
if ( F_85 ( V_266 ) )
V_11 -> V_17 = 1 ;
else {
V_11 -> V_17 = 0 ;
break;
}
V_266 = F_44 ( V_74 . V_116 , V_74 . V_117 ,
L_124 , V_266 ) ;
}
for ( V_75 = V_74 . V_120 ; V_75 < V_74 . V_121 ; V_75 ++ ) {
V_129 = F_83 ( V_74 . V_122 + V_75 -> V_127 ) ;
F_37 ( V_11 , & V_74 , V_75 , V_129 ) ;
F_86 ( V_11 , & V_74 , V_75 , V_129 ) ;
}
if ( ! F_5 ( V_6 ) ||
( F_5 ( V_6 ) && V_268 ) )
F_82 ( V_11 , V_6 , & V_74 ) ;
V_265 = F_45 ( V_74 . V_116 , V_74 . V_117 , L_128 ) ;
if ( V_265 )
F_87 ( V_6 , V_265 , V_74 . V_116 ,
V_265 - ( char * ) V_74 . V_34 ) ;
if ( V_265 || ( V_269 && ! F_5 ( V_6 ) ) )
F_88 ( V_6 , V_11 -> V_270 ,
sizeof( V_11 -> V_270 ) - 1 ) ;
F_34 ( & V_74 ) ;
if ( V_271 )
V_11 -> V_148 = F_12 ( L_129 , 0 , V_11 -> V_148 ) ;
}
static void F_89 ( const char * V_57 )
{
T_11 * V_272 = V_273 ;
char V_274 [ V_275 ] ;
if ( strcmp ( V_57 , L_130 ) != 0 ) {
V_272 = fopen ( V_57 , L_131 ) ;
if ( ! V_272 )
F_1 ( L_132 , V_57 ) ;
}
while ( fgets ( V_274 , V_275 , V_272 ) != NULL ) {
if ( F_4 ( V_274 , L_60 ) )
V_274 [ strlen ( V_274 ) - 1 ] = '\0' ;
F_84 ( V_274 ) ;
}
if ( V_272 != V_273 )
fclose ( V_272 ) ;
}
void F_90 ( struct V_276 * V_277 , const char * V_22 , int V_73 )
{
if ( V_277 -> V_58 - V_277 -> V_70 < V_73 ) {
V_277 -> V_58 += V_73 + V_278 ;
V_277 -> V_15 = realloc ( V_277 -> V_15 , V_277 -> V_58 ) ;
}
strncpy ( V_277 -> V_15 + V_277 -> V_70 , V_22 , V_73 ) ;
V_277 -> V_70 += V_73 ;
}
static void F_91 ( enum V_23 exp , const char * V_264 , const char * V_22 )
{
const char * V_147 = F_5 ( V_264 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_44 :
F_1 ( L_133
L_134 , V_264 , V_147 , V_22 ) ;
break;
case V_45 :
F_1 ( L_133
L_135 , V_264 , V_147 , V_22 ) ;
break;
case V_46 :
F_2 ( L_133
L_136 , V_264 , V_147 , V_22 ) ;
break;
case V_42 :
case V_43 :
case V_30 :
break;
}
}
static void F_92 ( enum V_23 exp , const char * V_264 , const char * V_22 )
{
const char * V_147 = F_5 ( V_264 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_43 :
case V_45 :
F_2 ( L_137
L_138 , V_264 , V_147 , V_22 ) ;
break;
default:
break;
}
}
static void F_93 ( struct V_10 * V_11 )
{
struct V_20 * V_22 , * exp ;
for ( V_22 = V_11 -> V_148 ; V_22 ; V_22 = V_22 -> V_13 ) {
const char * V_279 ;
exp = F_14 ( V_22 -> V_14 ) ;
if ( ! exp || exp -> V_10 == V_11 )
continue;
V_279 = strrchr ( V_11 -> V_14 , '/' ) ;
if ( V_279 )
V_279 ++ ;
else
V_279 = V_11 -> V_14 ;
if ( ! V_11 -> V_17 )
F_91 ( exp -> V_23 , V_279 , exp -> V_14 ) ;
F_92 ( exp -> V_23 , V_279 , exp -> V_14 ) ;
}
}
static int F_94 ( struct V_10 * V_11 )
{
const char * V_280 ;
V_280 = strrchr ( V_11 -> V_14 , '/' ) ;
if ( V_280 == NULL )
V_280 = V_11 -> V_14 ;
else
V_280 ++ ;
if ( strlen ( V_280 ) >= V_281 ) {
F_3 ( L_139 , V_11 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
static void F_95 ( struct V_276 * V_282 , struct V_10 * V_11 )
{
F_96 ( V_282 , L_140 ) ;
F_96 ( V_282 , L_141 ) ;
F_96 ( V_282 , L_142 ) ;
F_96 ( V_282 , L_60 ) ;
F_96 ( V_282 , L_143 ) ;
F_96 ( V_282 , L_144 ) ;
F_96 ( V_282 , L_60 ) ;
F_96 ( V_282 , L_145 ) ;
F_96 ( V_282 , L_146 ) ;
F_96 ( V_282 , L_147 ) ;
if ( V_11 -> V_151 )
F_96 ( V_282 , L_148 ) ;
if ( V_11 -> V_153 )
F_96 ( V_282 , L_149
L_150
L_151 ) ;
F_96 ( V_282 , L_152 ) ;
F_96 ( V_282 , L_153 ) ;
}
static void F_97 ( struct V_276 * V_282 , int V_283 )
{
if ( V_283 )
F_96 ( V_282 , L_154 ) ;
}
static void F_98 ( struct V_276 * V_282 , const char * V_14 )
{
static const char * V_284 = L_155 ;
if ( strncmp ( V_284 , V_14 , strlen ( V_284 ) ) == 0 )
F_96 ( V_282 , L_156 ) ;
}
static int F_99 ( struct V_276 * V_282 , struct V_10 * V_11 )
{
struct V_20 * V_22 , * exp ;
int V_285 = 0 ;
for ( V_22 = V_11 -> V_148 ; V_22 ; V_22 = V_22 -> V_13 ) {
exp = F_14 ( V_22 -> V_14 ) ;
if ( ! exp || exp -> V_10 == V_11 ) {
if ( V_267 && ! V_22 -> V_21 ) {
if ( V_286 ) {
F_2 ( L_157 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
} else {
F_3 ( L_157 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
V_285 = 1 ;
}
}
continue;
}
V_22 -> V_10 = exp -> V_10 ;
V_22 -> V_56 = exp -> V_56 ;
V_22 -> V_55 = exp -> V_55 ;
}
if ( ! V_271 )
return V_285 ;
F_96 ( V_282 , L_60 ) ;
F_96 ( V_282 , L_158 ) ;
F_96 ( V_282 , L_159 ) ;
F_96 ( V_282 , L_160 ) ;
for ( V_22 = V_11 -> V_148 ; V_22 ; V_22 = V_22 -> V_13 ) {
if ( ! V_22 -> V_10 )
continue;
if ( ! V_22 -> V_56 ) {
F_2 ( L_161 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
continue;
}
if ( strlen ( V_22 -> V_14 ) >= V_281 ) {
F_3 ( L_162 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
V_285 = 1 ;
break;
}
F_96 ( V_282 , L_163 ,
V_22 -> V_55 , V_22 -> V_14 ) ;
}
F_96 ( V_282 , L_153 ) ;
return V_285 ;
}
static void F_100 ( struct V_276 * V_282 , struct V_10 * V_11 ,
struct V_10 * V_12 )
{
struct V_20 * V_22 ;
struct V_10 * V_264 ;
int V_287 = 1 ;
for ( V_264 = V_12 ; V_264 ; V_264 = V_264 -> V_13 )
V_264 -> V_288 = F_5 ( V_264 -> V_14 ) ;
F_96 ( V_282 , L_60 ) ;
F_96 ( V_282 , L_164 ) ;
F_96 ( V_282 , L_159 ) ;
F_96 ( V_282 , L_165 ) ;
F_96 ( V_282 , L_166 ) ;
for ( V_22 = V_11 -> V_148 ; V_22 ; V_22 = V_22 -> V_13 ) {
const char * V_15 ;
if ( ! V_22 -> V_10 )
continue;
if ( V_22 -> V_10 -> V_288 )
continue;
V_22 -> V_10 -> V_288 = 1 ;
V_15 = strrchr ( V_22 -> V_10 -> V_14 , '/' ) ;
if ( V_15 )
V_15 ++ ;
else
V_15 = V_22 -> V_10 -> V_14 ;
F_96 ( V_282 , L_167 , V_287 ? L_15 : L_168 , V_15 ) ;
V_287 = 0 ;
}
F_96 ( V_282 , L_169 ) ;
}
static void F_101 ( struct V_276 * V_282 , struct V_10 * V_11 )
{
if ( V_11 -> V_270 [ 0 ] ) {
F_96 ( V_282 , L_60 ) ;
F_96 ( V_282 , L_170 ,
V_11 -> V_270 ) ;
}
}
static void F_102 ( struct V_276 * V_282 , const char * V_274 )
{
char * V_289 ;
T_11 * V_71 ;
struct V_59 V_60 ;
V_71 = fopen ( V_274 , L_131 ) ;
if ( ! V_71 )
goto V_290;
if ( F_26 ( fileno ( V_71 ) , & V_60 ) < 0 )
goto V_291;
if ( V_60 . V_66 != V_282 -> V_70 )
goto V_291;
V_289 = F_9 ( malloc ( V_282 -> V_70 ) ) ;
if ( fread ( V_289 , 1 , V_282 -> V_70 , V_71 ) != V_282 -> V_70 )
goto V_292;
if ( memcmp ( V_289 , V_282 -> V_15 , V_282 -> V_70 ) != 0 )
goto V_292;
free ( V_289 ) ;
fclose ( V_71 ) ;
return;
V_292:
free ( V_289 ) ;
V_291:
fclose ( V_71 ) ;
V_290:
V_71 = fopen ( V_274 , L_171 ) ;
if ( ! V_71 ) {
perror ( V_274 ) ;
exit ( 1 ) ;
}
if ( fwrite ( V_282 -> V_15 , 1 , V_282 -> V_70 , V_71 ) != V_282 -> V_70 ) {
perror ( V_274 ) ;
exit ( 1 ) ;
}
fclose ( V_71 ) ;
}
static void F_103 ( const char * V_274 , unsigned int V_54 )
{
unsigned long V_58 , V_70 = 0 ;
void * V_71 = F_24 ( V_274 , & V_58 ) ;
char * line ;
if ( ! V_71 )
return;
while ( ( line = F_29 ( & V_70 , V_71 , V_58 ) ) ) {
char * V_129 , * V_6 , * V_190 , * V_23 , * V_293 ;
unsigned int V_55 ;
struct V_10 * V_11 ;
struct V_20 * V_22 ;
if ( ! ( V_129 = strchr ( line , '\t' ) ) )
goto V_294;
* V_129 ++ = '\0' ;
if ( ! ( V_6 = strchr ( V_129 , '\t' ) ) )
goto V_294;
* V_6 ++ = '\0' ;
if ( ( V_23 = strchr ( V_6 , '\t' ) ) != NULL )
* V_23 ++ = '\0' ;
if ( V_23 && ( ( V_293 = strchr ( V_23 , '\t' ) ) != NULL ) )
* V_293 = '\0' ;
V_55 = strtoul ( line , & V_190 , 16 ) ;
if ( * V_129 == '\0' || * V_6 == '\0' || * V_190 != '\0' )
goto V_294;
V_11 = F_7 ( V_6 ) ;
if ( ! V_11 ) {
if ( F_5 ( V_6 ) )
V_267 = 1 ;
V_11 = F_8 ( V_6 ) ;
V_11 -> V_72 = 1 ;
}
V_22 = F_22 ( V_129 , V_11 , F_16 ( V_23 ) ) ;
V_22 -> V_54 = V_54 ;
V_22 -> V_52 = 1 ;
F_23 ( V_129 , V_11 , V_55 , F_16 ( V_23 ) ) ;
}
F_30 ( V_71 , V_58 ) ;
return;
V_294:
F_30 ( V_71 , V_58 ) ;
F_1 ( L_172 ) ;
}
static int F_104 ( struct V_20 * V_75 )
{
if ( ! V_295 )
return 1 ;
if ( V_75 -> V_53 || V_75 -> V_54 )
return 0 ;
return 1 ;
}
static void F_105 ( const char * V_274 )
{
struct V_276 V_277 = { } ;
struct V_20 * V_20 ;
int V_263 ;
for ( V_263 = 0 ; V_263 < V_26 ; V_263 ++ ) {
V_20 = V_27 [ V_263 ] ;
while ( V_20 ) {
if ( F_104 ( V_20 ) )
F_96 ( & V_277 , L_173 ,
V_20 -> V_55 , V_20 -> V_14 ,
V_20 -> V_10 -> V_14 ,
F_15 ( V_20 -> V_23 ) ) ;
V_20 = V_20 -> V_13 ;
}
}
F_102 ( & V_277 , V_274 ) ;
free ( V_277 . V_15 ) ;
}
int main ( int V_296 , char * * V_297 )
{
struct V_10 * V_11 ;
struct V_276 V_277 = { } ;
char * V_298 = NULL , * V_299 = NULL ;
char * V_300 = NULL , * V_301 = NULL ;
int V_302 ;
int V_285 ;
struct V_303 * V_304 ;
struct V_303 * V_305 = NULL ;
while ( ( V_302 = F_106 ( V_296 , V_297 , L_174 ) ) != - 1 ) {
switch ( V_302 ) {
case 'i' :
V_298 = V_306 ;
break;
case 'I' :
V_299 = V_306 ;
V_295 = 1 ;
break;
case 'e' :
V_295 = 1 ;
V_304 =
F_9 ( malloc ( sizeof( * V_304 ) ) ) ;
V_304 -> V_13 = V_305 ;
V_304 -> V_71 = V_306 ;
V_305 = V_304 ;
break;
case 'm' :
V_271 = 1 ;
break;
case 'n' :
V_79 = 1 ;
break;
case 'o' :
V_300 = V_306 ;
break;
case 'a' :
V_269 = 1 ;
break;
case 's' :
V_268 = 0 ;
break;
case 'S' :
V_209 = 0 ;
break;
case 'T' :
V_301 = V_306 ;
break;
case 'w' :
V_286 = 1 ;
break;
case 'E' :
V_307 = 1 ;
break;
default:
exit ( 1 ) ;
}
}
if ( V_298 )
F_103 ( V_298 , 1 ) ;
if ( V_299 )
F_103 ( V_299 , 0 ) ;
while ( V_305 ) {
F_103 ( V_305 -> V_71 , 0 ) ;
V_304 = V_305 -> V_13 ;
free ( V_305 ) ;
V_305 = V_304 ;
}
while ( V_308 < V_296 )
F_84 ( V_297 [ V_308 ++ ] ) ;
if ( V_301 )
F_89 ( V_301 ) ;
for ( V_11 = V_12 ; V_11 ; V_11 = V_11 -> V_13 ) {
if ( V_11 -> V_72 )
continue;
F_93 ( V_11 ) ;
}
V_285 = 0 ;
for ( V_11 = V_12 ; V_11 ; V_11 = V_11 -> V_13 ) {
char V_274 [ V_275 ] ;
if ( V_11 -> V_72 )
continue;
V_277 . V_70 = 0 ;
V_285 |= F_94 ( V_11 ) ;
F_95 ( & V_277 , V_11 ) ;
F_97 ( & V_277 , ! V_295 ) ;
F_98 ( & V_277 , V_11 -> V_14 ) ;
V_285 |= F_99 ( & V_277 , V_11 ) ;
F_100 ( & V_277 , V_11 , V_12 ) ;
F_107 ( & V_277 , V_11 ) ;
F_101 ( & V_277 , V_11 ) ;
sprintf ( V_274 , L_175 , V_11 -> V_14 ) ;
F_102 ( & V_277 , V_274 ) ;
}
if ( V_300 )
F_105 ( V_300 ) ;
if ( V_208 ) {
if ( ! V_209 ) {
F_2 ( L_176
L_177
L_178 ,
V_208 ) ;
}
if ( V_307 ) {
F_1 ( L_179
L_180 ) ;
}
}
free ( V_277 . V_15 ) ;
return V_285 ;
}
