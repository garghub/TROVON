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
static int F_48 ( const char * V_70 )
{
if ( * V_70 ++ == '\0' )
return 1 ;
if ( * V_70 != '.' )
return 0 ;
do {
char V_155 = * V_70 ++ ;
if ( V_155 < '0' || V_155 > '9' )
return 0 ;
} while ( * V_70 );
return 1 ;
}
static int F_49 ( const char * V_70 , const char * const V_156 [] )
{
const char * V_15 ;
while ( * V_156 ) {
V_15 = * V_156 ++ ;
const char * V_157 = V_15 + strlen ( V_15 ) - 1 ;
if ( * V_15 == '*' ) {
if ( F_45 ( V_70 , V_15 + 1 ) == 0 )
return 1 ;
}
else if ( * V_157 == '*' ) {
if ( strncmp ( V_70 , V_15 , strlen ( V_15 ) - 1 ) == 0 )
return 1 ;
}
else if ( * V_157 == '$' ) {
if ( strncmp ( V_70 , V_15 , strlen ( V_15 ) - 1 ) == 0 ) {
if ( F_48 ( V_70 + strlen ( V_15 ) - 1 ) )
return 1 ;
}
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
if ( V_154 -> V_105 == V_158 &&
! ( V_154 -> V_106 & V_159 ) &&
! F_49 ( V_33 , V_160 ) ) {
F_2 ( L_43
L_44
L_45
L_46 ,
V_6 , V_33 ) ;
}
}
static const struct V_161 * F_51 (
const char * V_162 , const char * V_163 )
{
int V_19 ;
int V_164 = sizeof( V_161 ) / sizeof( struct V_161 ) ;
const struct V_161 * V_165 = & V_161 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_164 ; V_19 ++ ) {
if ( F_49 ( V_162 , V_165 -> V_162 ) &&
F_49 ( V_163 , V_165 -> V_163 ) )
return V_165 ;
V_165 ++ ;
}
return NULL ;
}
static int F_52 ( const struct V_161 * V_166 ,
const char * V_162 , const char * V_167 ,
const char * V_163 , const char * V_168 )
{
if ( F_49 ( V_163 , V_169 ) &&
F_49 ( V_162 , V_170 ) &&
( strncmp ( V_167 , L_47 , strlen ( L_47 ) ) == 0 ) )
return 0 ;
if ( strcmp ( V_163 , L_48 ) == 0 &&
F_49 ( V_162 , V_170 ) &&
( strncmp ( V_167 , L_49 , strlen ( L_49 ) ) == 0 ) )
return 0 ;
if ( F_49 ( V_163 , V_171 ) &&
F_49 ( V_162 , V_170 ) &&
F_49 ( V_167 , V_166 -> V_172 ) )
return 0 ;
if ( F_49 ( V_162 , V_173 ) &&
F_49 ( V_163 , V_174 ) )
return 0 ;
if ( F_49 ( V_168 , V_175 ) )
return 0 ;
return 1 ;
}
static T_5 * F_53 ( struct V_31 * V_32 , T_7 V_176 ,
T_5 * V_177 )
{
T_5 * V_70 ;
T_5 * V_178 = NULL ;
T_7 V_179 = 20 ;
T_7 V_180 ;
unsigned int V_181 ;
if ( V_177 -> V_125 != 0 )
return V_177 ;
V_181 = F_37 ( V_32 , V_177 ) ;
for ( V_70 = V_32 -> V_118 ; V_70 < V_32 -> V_119 ; V_70 ++ ) {
if ( F_37 ( V_32 , V_70 ) != V_181 )
continue;
if ( F_40 ( V_70 -> V_133 ) == V_182 )
continue;
if ( V_70 -> V_126 == V_176 )
return V_70 ;
V_180 = V_70 -> V_126 - V_176 ;
if ( V_180 < 0 )
V_180 = V_176 - V_70 -> V_126 ;
if ( V_180 < V_179 ) {
V_179 = V_180 ;
V_178 = V_70 ;
}
}
if ( V_179 < 20 )
return V_178 ;
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
static T_5 * F_56 ( struct V_31 * V_32 , T_8 V_176 ,
const char * V_33 )
{
T_5 * V_70 ;
T_5 * V_178 = NULL ;
T_8 V_179 = ~ 0 ;
for ( V_70 = V_32 -> V_118 ; V_70 < V_32 -> V_119 ; V_70 ++ ) {
const char * V_183 ;
if ( F_57 ( V_70 -> V_124 ) )
continue;
V_183 = F_18 ( V_32 , F_37 ( V_32 , V_70 ) ) ;
if ( strcmp ( V_183 , V_33 ) != 0 )
continue;
if ( ! F_55 ( V_32 , V_70 ) )
continue;
if ( V_70 -> V_126 <= V_176 ) {
if ( ( V_176 - V_70 -> V_126 ) < V_179 ) {
V_179 = V_176 - V_70 -> V_126 ;
V_178 = V_70 ;
} else if ( ( V_176 - V_70 -> V_126 ) == V_179 ) {
V_178 = V_70 ;
}
}
}
return V_178 ;
}
static char * F_58 ( const char * V_22 )
{
if ( F_49 ( V_22 , V_171 ) ) {
char * V_15 = malloc ( 20 ) ;
char * V_184 = V_15 ;
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
return V_184 ;
} else {
return F_10 ( L_15 ) ;
}
}
static int F_59 ( T_5 * V_70 )
{
if ( V_70 )
return F_40 ( V_70 -> V_133 ) == V_185 ;
else
return - 1 ;
}
static void F_60 ( const char * const V_186 [ 20 ] )
{
const char * const * V_22 = V_186 ;
while ( * V_22 ) {
fprintf ( V_3 , L_56 , * V_22 ) ;
V_22 ++ ;
if ( * V_22 )
fprintf ( V_3 , L_57 ) ;
}
fprintf ( V_3 , L_58 ) ;
}
static void F_61 ( const char * V_6 ,
const struct V_161 * V_166 ,
const char * V_162 ,
unsigned long long V_187 ,
const char * V_167 ,
int V_188 ,
const char * V_163 , const char * V_168 ,
int V_189 )
{
const char * V_190 , * V_191 ;
const char * V_192 , * V_193 ;
char * V_194 ;
char * V_195 ;
switch ( V_188 ) {
case 0 : V_190 = L_59 ; V_191 = L_15 ; break;
case 1 : V_190 = L_60 ; V_191 = L_61 ; break;
default: V_190 = L_62 ; V_191 = L_15 ; break;
}
switch ( V_189 ) {
case 0 : V_192 = L_59 ; V_193 = L_15 ; break;
case 1 : V_192 = L_60 ; V_193 = L_61 ; break;
default: V_192 = L_62 ; V_193 = L_15 ; break;
}
V_196 ++ ;
if ( ! V_197 )
return;
F_2 ( L_63
L_64 ,
V_6 , V_162 , V_187 , V_190 , V_167 , V_191 , V_192 , V_163 ,
V_168 , V_193 ) ;
switch ( V_166 -> V_166 ) {
case V_198 :
V_194 = F_58 ( V_162 ) ;
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_65
L_66
L_67
L_68 ,
V_194 , V_167 ,
V_192 , V_195 , V_168 , V_193 ,
V_167 , V_195 , V_168 ) ;
free ( V_194 ) ;
free ( V_195 ) ;
break;
case V_199 : {
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_69
L_70
L_71
L_72
L_73 ,
V_167 , V_192 , V_195 , V_168 , V_193 ) ;
F_60 ( V_166 -> V_172 ) ;
free ( V_195 ) ;
break;
}
case V_200 :
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_74
L_75
L_76 ,
V_167 , V_192 , V_192 , V_168 , V_193 , V_195 , V_168 ) ;
free ( V_195 ) ;
break;
case V_201 : {
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_69
L_70
L_71
L_77
L_78 ,
V_167 , V_192 , V_195 , V_168 , V_193 ) ;
F_60 ( V_166 -> V_172 ) ;
free ( V_195 ) ;
break;
}
case V_202 :
case V_203 :
V_194 = F_58 ( V_162 ) ;
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_79
L_80
L_81
L_82 ,
V_190 , V_194 , V_167 , V_191 ,
V_192 , V_195 , V_168 , V_193 ,
V_168 , V_167 , V_168 ) ;
free ( V_194 ) ;
free ( V_195 ) ;
break;
case V_204 :
V_194 = F_58 ( V_162 ) ;
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_79
L_80
L_83
L_84
L_85
L_86
L_87 ,
V_190 , V_194 , V_167 , V_191 ,
V_192 , V_195 , V_168 , V_193 ,
V_195 , V_168 , V_193 ) ;
free ( V_194 ) ;
free ( V_195 ) ;
break;
case V_205 :
V_194 = F_58 ( V_162 ) ;
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_79
L_80
L_83
L_88
L_89
L_86
L_90 ,
V_190 , V_194 , V_167 , V_191 ,
V_192 , V_195 , V_168 , V_193 ,
V_195 , V_168 , V_193 ) ;
free ( V_194 ) ;
free ( V_195 ) ;
break;
case V_206 :
V_195 = F_58 ( V_163 ) ;
fprintf ( V_3 ,
L_91
L_92
L_93 ,
V_168 , V_195 , V_195 , V_168 ) ;
free ( V_195 ) ;
break;
}
fprintf ( V_3 , L_58 ) ;
}
static void F_62 ( const char * V_6 , struct V_31 * V_32 ,
T_9 * V_184 , T_5 * V_70 , const char * V_162 )
{
const char * V_163 ;
const struct V_161 * V_166 ;
V_163 = F_18 ( V_32 , F_37 ( V_32 , V_70 ) ) ;
V_166 = F_51 ( V_162 , V_163 ) ;
if ( V_166 ) {
T_5 * V_192 ;
T_5 * V_190 ;
const char * V_168 ;
const char * V_167 ;
V_190 = F_56 ( V_32 , V_184 -> V_207 , V_162 ) ;
V_167 = F_46 ( V_32 , V_190 ) ;
V_192 = F_53 ( V_32 , V_184 -> V_208 , V_70 ) ;
V_168 = F_46 ( V_32 , V_192 ) ;
if ( ! strncmp ( V_167 , L_94 ,
sizeof( L_94 ) - 1 ) )
return;
if ( F_52 ( V_166 ,
V_162 , V_167 , V_163 , V_168 ) ) {
F_61 ( V_6 , V_166 ,
V_162 , V_184 -> V_207 , V_167 ,
F_59 ( V_190 ) , V_163 , V_168 ,
F_59 ( V_192 ) ) ;
}
}
}
static unsigned int * F_63 ( struct V_31 * V_32 ,
T_4 * V_154 , T_9 * V_184 )
{
T_4 * V_69 = V_32 -> V_69 ;
int V_209 = V_154 -> V_109 ;
return ( void * ) V_32 -> V_68 + V_69 [ V_209 ] . V_108 +
V_184 -> V_207 ;
}
static int F_64 ( struct V_31 * V_32 , T_4 * V_154 , T_9 * V_184 )
{
unsigned int V_210 = F_65 ( V_184 -> V_211 ) ;
unsigned int * V_212 = F_63 ( V_32 , V_154 , V_184 ) ;
switch ( V_210 ) {
case V_213 :
V_184 -> V_208 = F_32 ( * V_212 ) ;
break;
case V_214 :
V_184 -> V_208 = F_32 ( * V_212 ) + 4 ;
if ( V_32 -> V_68 -> V_85 == V_215 )
V_184 -> V_208 += V_184 -> V_207 ;
break;
}
return 0 ;
}
static int F_66 ( struct V_31 * V_32 , T_4 * V_154 , T_9 * V_184 )
{
unsigned int V_210 = F_65 ( V_184 -> V_211 ) ;
switch ( V_210 ) {
case V_216 :
V_184 -> V_208 = ( int ) ( long )
( V_32 -> V_118 + F_67 ( V_184 -> V_211 ) ) ;
break;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
V_184 -> V_208 = ( int ) ( long ) ( V_32 -> V_68 +
V_154 -> V_108 +
( V_184 -> V_207 - V_154 -> V_107 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_68 ( struct V_31 * V_32 , T_4 * V_154 , T_9 * V_184 )
{
unsigned int V_210 = F_65 ( V_184 -> V_211 ) ;
unsigned int * V_212 = F_63 ( V_32 , V_154 , V_184 ) ;
unsigned int V_223 ;
if ( V_210 == V_224 )
return 1 ;
V_223 = F_32 ( * V_212 ) ;
switch ( V_210 ) {
case V_225 :
V_184 -> V_208 = V_223 & 0xffff ;
break;
case V_226 :
V_184 -> V_208 = ( V_223 & 0x03ffffff ) << 2 ;
break;
case V_227 :
V_184 -> V_208 = V_223 ;
break;
}
return 0 ;
}
static void F_69 ( const char * V_6 , struct V_31 * V_32 ,
T_4 * V_154 )
{
T_5 * V_70 ;
T_9 * V_228 ;
T_9 V_184 ;
unsigned int V_229 ;
const char * V_162 ;
T_9 * V_230 = ( void * ) V_32 -> V_68 + V_154 -> V_108 ;
T_9 * V_231 = ( void * ) V_230 + V_154 -> V_100 ;
V_162 = F_47 ( V_32 , V_154 ) ;
V_162 += strlen ( L_95 ) ;
if ( F_49 ( V_162 , V_160 ) )
return;
for ( V_228 = V_230 ; V_228 < V_231 ; V_228 ++ ) {
V_184 . V_207 = F_32 ( V_228 -> V_207 ) ;
#if V_232 == V_233
if ( V_32 -> V_68 -> V_86 == V_234 ) {
unsigned int V_210 ;
V_229 = F_70 ( V_228 -> V_211 ) ;
V_229 = F_32 ( V_229 ) ;
V_210 = F_71 ( V_228 -> V_211 ) ;
V_184 . V_211 = F_72 ( V_229 , V_210 ) ;
} else {
V_184 . V_211 = F_32 ( V_228 -> V_211 ) ;
V_229 = F_67 ( V_184 . V_211 ) ;
}
#else
V_184 . V_211 = F_32 ( V_228 -> V_211 ) ;
V_229 = F_67 ( V_184 . V_211 ) ;
#endif
V_184 . V_208 = F_32 ( V_228 -> V_208 ) ;
V_70 = V_32 -> V_118 + V_229 ;
if ( F_57 ( V_70 -> V_124 ) )
continue;
F_62 ( V_6 , V_32 , & V_184 , V_70 , V_162 ) ;
}
}
static void F_73 ( const char * V_6 , struct V_31 * V_32 ,
T_4 * V_154 )
{
T_5 * V_70 ;
T_10 * V_235 ;
T_9 V_184 ;
unsigned int V_229 ;
const char * V_162 ;
T_10 * V_230 = ( void * ) V_32 -> V_68 + V_154 -> V_108 ;
T_10 * V_231 = ( void * ) V_230 + V_154 -> V_100 ;
V_162 = F_47 ( V_32 , V_154 ) ;
V_162 += strlen ( L_96 ) ;
if ( F_49 ( V_162 , V_160 ) )
return;
for ( V_235 = V_230 ; V_235 < V_231 ; V_235 ++ ) {
V_184 . V_207 = F_32 ( V_235 -> V_207 ) ;
#if V_232 == V_233
if ( V_32 -> V_68 -> V_86 == V_234 ) {
unsigned int V_210 ;
V_229 = F_70 ( V_235 -> V_211 ) ;
V_229 = F_32 ( V_229 ) ;
V_210 = F_71 ( V_235 -> V_211 ) ;
V_184 . V_211 = F_72 ( V_229 , V_210 ) ;
} else {
V_184 . V_211 = F_32 ( V_235 -> V_211 ) ;
V_229 = F_67 ( V_184 . V_211 ) ;
}
#else
V_184 . V_211 = F_32 ( V_235 -> V_211 ) ;
V_229 = F_67 ( V_184 . V_211 ) ;
#endif
V_184 . V_208 = 0 ;
switch ( V_32 -> V_68 -> V_86 ) {
case V_236 :
if ( F_64 ( V_32 , V_154 , & V_184 ) )
continue;
break;
case V_237 :
if ( F_66 ( V_32 , V_154 , & V_184 ) )
continue;
break;
case V_234 :
if ( F_68 ( V_32 , V_154 , & V_184 ) )
continue;
break;
}
V_70 = V_32 -> V_118 + V_229 ;
if ( F_57 ( V_70 -> V_124 ) )
continue;
F_62 ( V_6 , V_32 , & V_184 , V_70 , V_162 ) ;
}
}
static void F_74 ( struct V_10 * V_11 , const char * V_6 ,
struct V_31 * V_32 )
{
int V_19 ;
T_4 * V_69 = V_32 -> V_69 ;
for ( V_19 = 0 ; V_19 < V_32 -> V_99 ; V_19 ++ ) {
F_50 ( V_6 , V_32 , & V_32 -> V_69 [ V_19 ] ) ;
if ( V_69 [ V_19 ] . V_105 == V_238 )
F_69 ( V_6 , V_32 , & V_32 -> V_69 [ V_19 ] ) ;
else if ( V_69 [ V_19 ] . V_105 == V_239 )
F_73 ( V_6 , V_32 , & V_32 -> V_69 [ V_19 ] ) ;
}
}
static char * F_75 ( char * V_22 )
{
char * V_240 ;
int V_241 = strcspn ( V_22 , L_97 ) ;
if ( V_241 > 0 && V_22 [ V_241 ] != 0 ) {
strtoul ( V_22 + V_241 + 1 , & V_240 , 10 ) ;
if ( V_240 > V_22 + V_241 + 1 && ( * V_240 == '.' || * V_240 == 0 ) )
V_22 [ V_241 ] = 0 ;
}
return V_22 ;
}
static void F_76 ( char * V_6 )
{
const char * V_127 ;
char * V_242 ;
char * V_243 ;
struct V_10 * V_11 ;
struct V_31 V_67 = { } ;
T_5 * V_70 ;
if ( ! F_31 ( & V_67 , V_6 ) )
return;
V_11 = F_8 ( V_6 ) ;
if ( F_5 ( V_6 ) ) {
V_244 = 1 ;
V_11 -> V_65 = 1 ;
}
V_243 = F_44 ( V_67 . V_114 , V_67 . V_115 , L_98 ) ;
if ( V_67 . V_114 && ! V_243 && ! F_5 ( V_6 ) )
F_2 ( L_99
L_100
L_101 , V_6 ) ;
while ( V_243 ) {
if ( F_77 ( V_243 ) )
V_11 -> V_17 = 1 ;
else {
V_11 -> V_17 = 0 ;
break;
}
V_243 = F_43 ( V_67 . V_114 , V_67 . V_115 ,
L_98 , V_243 ) ;
}
for ( V_70 = V_67 . V_118 ; V_70 < V_67 . V_119 ; V_70 ++ ) {
V_127 = F_75 ( V_67 . V_120 + V_70 -> V_125 ) ;
F_36 ( V_11 , & V_67 , V_70 , V_127 ) ;
F_78 ( V_11 , & V_67 , V_70 , V_127 ) ;
}
if ( ! F_5 ( V_6 ) ||
( F_5 ( V_6 ) && V_245 ) )
F_74 ( V_11 , V_6 , & V_67 ) ;
V_242 = F_44 ( V_67 . V_114 , V_67 . V_115 , L_102 ) ;
if ( V_242 )
F_79 ( V_6 , V_242 , V_67 . V_114 ,
V_242 - ( char * ) V_67 . V_68 ) ;
if ( V_242 || ( V_246 && ! F_5 ( V_6 ) ) )
F_80 ( V_6 , V_11 -> V_247 ,
sizeof( V_11 -> V_247 ) - 1 ) ;
F_33 ( & V_67 ) ;
if ( V_248 )
V_11 -> V_141 = F_12 ( L_103 , 0 , V_11 -> V_141 ) ;
}
static void F_81 ( const char * V_50 )
{
T_11 * V_249 = V_250 ;
char V_251 [ V_252 ] ;
if ( strcmp ( V_50 , L_104 ) != 0 ) {
V_249 = fopen ( V_50 , L_105 ) ;
if ( ! V_249 )
F_1 ( L_106 , V_50 ) ;
}
while ( fgets ( V_251 , V_252 , V_249 ) != NULL ) {
if ( F_4 ( V_251 , L_58 ) )
V_251 [ strlen ( V_251 ) - 1 ] = '\0' ;
F_76 ( V_251 ) ;
}
if ( V_249 != V_250 )
fclose ( V_249 ) ;
}
void F_82 ( struct V_253 * V_254 , const char * V_22 , int V_66 )
{
if ( V_254 -> V_51 - V_254 -> V_63 < V_66 ) {
V_254 -> V_51 += V_66 + V_255 ;
V_254 -> V_15 = realloc ( V_254 -> V_15 , V_254 -> V_51 ) ;
}
strncpy ( V_254 -> V_15 + V_254 -> V_63 , V_22 , V_66 ) ;
V_254 -> V_63 += V_66 ;
}
static void F_83 ( enum V_23 exp , const char * V_256 , const char * V_22 )
{
const char * V_257 = F_5 ( V_256 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_37 :
F_1 ( L_107
L_108 , V_256 , V_257 , V_22 ) ;
break;
case V_38 :
F_1 ( L_107
L_109 , V_256 , V_257 , V_22 ) ;
break;
case V_39 :
F_2 ( L_107
L_110 , V_256 , V_257 , V_22 ) ;
break;
case V_35 :
case V_36 :
case V_30 :
break;
}
}
static void F_84 ( enum V_23 exp , const char * V_256 , const char * V_22 )
{
const char * V_257 = F_5 ( V_256 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_36 :
case V_38 :
F_2 ( L_111
L_112 , V_256 , V_257 , V_22 ) ;
break;
default:
break;
}
}
static void F_85 ( struct V_10 * V_11 )
{
struct V_20 * V_22 , * exp ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
const char * V_258 ;
exp = F_14 ( V_22 -> V_14 ) ;
if ( ! exp || exp -> V_10 == V_11 )
continue;
V_258 = strrchr ( V_11 -> V_14 , '/' ) ;
if ( V_258 )
V_258 ++ ;
else
V_258 = V_11 -> V_14 ;
if ( ! V_11 -> V_17 )
F_83 ( exp -> V_23 , V_258 , exp -> V_14 ) ;
F_84 ( exp -> V_23 , V_258 , exp -> V_14 ) ;
}
}
static void F_86 ( struct V_253 * V_259 , struct V_10 * V_11 )
{
F_87 ( V_259 , L_113 ) ;
F_87 ( V_259 , L_114 ) ;
F_87 ( V_259 , L_115 ) ;
F_87 ( V_259 , L_58 ) ;
F_87 ( V_259 , L_116 ) ;
F_87 ( V_259 , L_58 ) ;
F_87 ( V_259 , L_117 ) ;
F_87 ( V_259 , L_118 ) ;
F_87 ( V_259 , L_119 ) ;
if ( V_11 -> V_144 )
F_87 ( V_259 , L_120 ) ;
if ( V_11 -> V_146 )
F_87 ( V_259 , L_121
L_122
L_123 ) ;
F_87 ( V_259 , L_124 ) ;
F_87 ( V_259 , L_125 ) ;
}
static void F_88 ( struct V_253 * V_259 , int V_260 )
{
if ( V_260 )
F_87 ( V_259 , L_126 ) ;
}
static void F_89 ( struct V_253 * V_259 , const char * V_14 )
{
static const char * V_261 = L_127 ;
if ( strncmp ( V_261 , V_14 , strlen ( V_261 ) ) == 0 )
F_87 ( V_259 , L_128 ) ;
}
static int F_90 ( struct V_253 * V_259 , struct V_10 * V_11 )
{
struct V_20 * V_22 , * exp ;
int V_262 = 0 ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
exp = F_14 ( V_22 -> V_14 ) ;
if ( ! exp || exp -> V_10 == V_11 ) {
if ( V_244 && ! V_22 -> V_21 ) {
if ( V_263 ) {
F_2 ( L_129 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
} else {
F_3 ( L_129 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
V_262 = 1 ;
}
}
continue;
}
V_22 -> V_10 = exp -> V_10 ;
V_22 -> V_49 = exp -> V_49 ;
V_22 -> V_48 = exp -> V_48 ;
}
if ( ! V_248 )
return V_262 ;
F_87 ( V_259 , L_58 ) ;
F_87 ( V_259 , L_130 ) ;
F_87 ( V_259 , L_131 ) ;
F_87 ( V_259 , L_132 ) ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
if ( ! V_22 -> V_10 )
continue;
if ( ! V_22 -> V_49 ) {
F_2 ( L_133 ,
V_22 -> V_14 , V_11 -> V_14 ) ;
continue;
}
F_87 ( V_259 , L_134 ,
V_22 -> V_48 , V_22 -> V_14 ) ;
}
F_87 ( V_259 , L_125 ) ;
return V_262 ;
}
static void F_91 ( struct V_253 * V_259 , struct V_10 * V_11 ,
struct V_10 * V_12 )
{
struct V_20 * V_22 ;
struct V_10 * V_256 ;
int V_264 = 1 ;
for ( V_256 = V_12 ; V_256 ; V_256 = V_256 -> V_13 )
V_256 -> V_265 = F_5 ( V_256 -> V_14 ) ;
F_87 ( V_259 , L_58 ) ;
F_87 ( V_259 , L_135 ) ;
F_87 ( V_259 , L_131 ) ;
F_87 ( V_259 , L_136 ) ;
F_87 ( V_259 , L_137 ) ;
for ( V_22 = V_11 -> V_141 ; V_22 ; V_22 = V_22 -> V_13 ) {
const char * V_15 ;
if ( ! V_22 -> V_10 )
continue;
if ( V_22 -> V_10 -> V_265 )
continue;
V_22 -> V_10 -> V_265 = 1 ;
V_15 = strrchr ( V_22 -> V_10 -> V_14 , '/' ) ;
if ( V_15 )
V_15 ++ ;
else
V_15 = V_22 -> V_10 -> V_14 ;
F_87 ( V_259 , L_138 , V_264 ? L_15 : L_139 , V_15 ) ;
V_264 = 0 ;
}
F_87 ( V_259 , L_140 ) ;
}
static void F_92 ( struct V_253 * V_259 , struct V_10 * V_11 )
{
if ( V_11 -> V_247 [ 0 ] ) {
F_87 ( V_259 , L_58 ) ;
F_87 ( V_259 , L_141 ,
V_11 -> V_247 ) ;
}
}
static void F_93 ( struct V_253 * V_259 , const char * V_251 )
{
char * V_266 ;
T_11 * V_64 ;
struct V_52 V_53 ;
V_64 = fopen ( V_251 , L_105 ) ;
if ( ! V_64 )
goto V_267;
if ( F_25 ( fileno ( V_64 ) , & V_53 ) < 0 )
goto V_268;
if ( V_53 . V_59 != V_259 -> V_63 )
goto V_268;
V_266 = F_9 ( malloc ( V_259 -> V_63 ) ) ;
if ( fread ( V_266 , 1 , V_259 -> V_63 , V_64 ) != V_259 -> V_63 )
goto V_269;
if ( memcmp ( V_266 , V_259 -> V_15 , V_259 -> V_63 ) != 0 )
goto V_269;
free ( V_266 ) ;
fclose ( V_64 ) ;
return;
V_269:
free ( V_266 ) ;
V_268:
fclose ( V_64 ) ;
V_267:
V_64 = fopen ( V_251 , L_142 ) ;
if ( ! V_64 ) {
perror ( V_251 ) ;
exit ( 1 ) ;
}
if ( fwrite ( V_259 -> V_15 , 1 , V_259 -> V_63 , V_64 ) != V_259 -> V_63 ) {
perror ( V_251 ) ;
exit ( 1 ) ;
}
fclose ( V_64 ) ;
}
static void F_94 ( const char * V_251 , unsigned int V_47 )
{
unsigned long V_51 , V_63 = 0 ;
void * V_64 = F_23 ( V_251 , & V_51 ) ;
char * line ;
if ( ! V_64 )
return;
while ( ( line = F_28 ( & V_63 , V_64 , V_51 ) ) ) {
char * V_127 , * V_6 , * V_180 , * V_23 , * V_240 ;
unsigned int V_48 ;
struct V_10 * V_11 ;
struct V_20 * V_22 ;
if ( ! ( V_127 = strchr ( line , '\t' ) ) )
goto V_270;
* V_127 ++ = '\0' ;
if ( ! ( V_6 = strchr ( V_127 , '\t' ) ) )
goto V_270;
* V_6 ++ = '\0' ;
if ( ( V_23 = strchr ( V_6 , '\t' ) ) != NULL )
* V_23 ++ = '\0' ;
if ( V_23 && ( ( V_240 = strchr ( V_23 , '\t' ) ) != NULL ) )
* V_240 = '\0' ;
V_48 = strtoul ( line , & V_180 , 16 ) ;
if ( * V_127 == '\0' || * V_6 == '\0' || * V_180 != '\0' )
goto V_270;
V_11 = F_7 ( V_6 ) ;
if ( ! V_11 ) {
if ( F_5 ( V_6 ) )
V_244 = 1 ;
V_11 = F_8 ( V_6 ) ;
V_11 -> V_65 = 1 ;
}
V_22 = F_21 ( V_127 , V_11 , F_16 ( V_23 ) ) ;
V_22 -> V_47 = V_47 ;
V_22 -> V_45 = 1 ;
F_22 ( V_127 , V_11 , V_48 , F_16 ( V_23 ) ) ;
}
return;
V_270:
F_1 ( L_143 ) ;
}
static int F_95 ( struct V_20 * V_70 )
{
if ( ! V_271 )
return 1 ;
if ( V_70 -> V_46 || V_70 -> V_47 )
return 0 ;
return 1 ;
}
static void F_96 ( const char * V_251 )
{
struct V_253 V_254 = { } ;
struct V_20 * V_20 ;
int V_241 ;
for ( V_241 = 0 ; V_241 < V_26 ; V_241 ++ ) {
V_20 = V_27 [ V_241 ] ;
while ( V_20 ) {
if ( F_95 ( V_20 ) )
F_87 ( & V_254 , L_144 ,
V_20 -> V_48 , V_20 -> V_14 ,
V_20 -> V_10 -> V_14 ,
F_15 ( V_20 -> V_23 ) ) ;
V_20 = V_20 -> V_13 ;
}
}
F_93 ( & V_254 , V_251 ) ;
}
int main ( int V_272 , char * * V_273 )
{
struct V_10 * V_11 ;
struct V_253 V_254 = { } ;
char * V_274 = NULL , * V_275 = NULL ;
char * V_276 = NULL , * V_277 = NULL ;
int V_278 ;
int V_262 ;
struct V_279 * V_280 ;
struct V_279 * V_281 = NULL ;
while ( ( V_278 = F_97 ( V_272 , V_273 , L_145 ) ) != - 1 ) {
switch ( V_278 ) {
case 'i' :
V_274 = V_282 ;
break;
case 'I' :
V_275 = V_282 ;
V_271 = 1 ;
break;
case 'e' :
V_271 = 1 ;
V_280 =
F_9 ( malloc ( sizeof( * V_280 ) ) ) ;
V_280 -> V_13 = V_281 ;
V_280 -> V_64 = V_282 ;
V_281 = V_280 ;
break;
case 'm' :
V_248 = 1 ;
break;
case 'n' :
V_74 = 1 ;
break;
case 'o' :
V_276 = V_282 ;
break;
case 'a' :
V_246 = 1 ;
break;
case 's' :
V_245 = 0 ;
break;
case 'S' :
V_197 = 0 ;
break;
case 'T' :
V_277 = V_282 ;
break;
case 'w' :
V_263 = 1 ;
break;
default:
exit ( 1 ) ;
}
}
if ( V_274 )
F_94 ( V_274 , 1 ) ;
if ( V_275 )
F_94 ( V_275 , 0 ) ;
while ( V_281 ) {
F_94 ( V_281 -> V_64 , 0 ) ;
V_280 = V_281 -> V_13 ;
free ( V_281 ) ;
V_281 = V_280 ;
}
while ( V_283 < V_272 )
F_76 ( V_273 [ V_283 ++ ] ) ;
if ( V_277 )
F_81 ( V_277 ) ;
for ( V_11 = V_12 ; V_11 ; V_11 = V_11 -> V_13 ) {
if ( V_11 -> V_65 )
continue;
F_85 ( V_11 ) ;
}
V_262 = 0 ;
for ( V_11 = V_12 ; V_11 ; V_11 = V_11 -> V_13 ) {
char V_251 [ strlen ( V_11 -> V_14 ) + 10 ] ;
if ( V_11 -> V_65 )
continue;
V_254 . V_63 = 0 ;
F_86 ( & V_254 , V_11 ) ;
F_88 ( & V_254 , ! V_271 ) ;
F_89 ( & V_254 , V_11 -> V_14 ) ;
V_262 |= F_90 ( & V_254 , V_11 ) ;
F_91 ( & V_254 , V_11 , V_12 ) ;
F_98 ( & V_254 , V_11 ) ;
F_92 ( & V_254 , V_11 ) ;
sprintf ( V_251 , L_146 , V_11 -> V_14 ) ;
F_93 ( & V_254 , V_251 ) ;
}
if ( V_276 )
F_96 ( V_276 ) ;
if ( V_196 && ! V_197 )
F_2 ( L_147
L_148
L_149 ,
V_196 ) ;
return V_262 ;
}
