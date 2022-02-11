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
void * V_53 ;
int V_54 ;
V_54 = F_23 ( V_49 , V_55 ) ;
if ( V_54 < 0 || F_24 ( V_54 , & V_52 ) != 0 )
return NULL ;
* V_50 = V_52 . V_56 ;
V_53 = F_25 ( NULL , * V_50 , V_57 | V_58 , V_59 , V_54 , 0 ) ;
F_26 ( V_54 ) ;
if ( V_53 == V_60 )
return NULL ;
return V_53 ;
}
char * F_27 ( unsigned long * V_61 , void * V_62 , unsigned long V_50 )
{
static char line [ 4096 ] ;
int V_63 = 1 ;
T_2 V_64 = 0 ;
signed char * V_13 = ( signed char * ) V_62 + * V_61 ;
char * V_14 = line ;
for (; * V_61 < V_50 ; ( * V_61 ) ++ ) {
if ( V_63 && isspace ( * V_13 ) ) {
V_13 ++ ;
continue;
}
V_63 = 0 ;
if ( * V_13 != '\n' && ( * V_61 < V_50 ) ) {
V_64 ++ ;
* V_14 ++ = * V_13 ++ ;
if ( V_64 > 4095 )
break;
} else {
* V_14 = '\0' ;
return line ;
}
}
return NULL ;
}
void F_28 ( void * V_62 , unsigned long V_50 )
{
F_29 ( V_62 , V_50 ) ;
}
static int F_30 ( struct V_30 * V_65 , const char * V_49 )
{
unsigned int V_18 ;
T_3 * V_66 ;
T_4 * V_67 ;
T_5 * V_68 ;
const char * V_69 ;
unsigned int V_70 = ~ 0U , V_71 = ~ 0U ;
V_66 = F_22 ( V_49 , & V_65 -> V_50 ) ;
if ( ! V_66 ) {
perror ( V_49 ) ;
exit ( 1 ) ;
}
V_65 -> V_66 = V_66 ;
if ( V_65 -> V_50 < sizeof( * V_66 ) ) {
return 0 ;
}
if ( ( V_66 -> V_72 [ V_73 ] != V_74 ) ||
( V_66 -> V_72 [ V_75 ] != V_76 ) ||
( V_66 -> V_72 [ V_77 ] != V_78 ) ||
( V_66 -> V_72 [ V_79 ] != V_80 ) ) {
return 0 ;
}
V_66 -> V_81 = F_31 ( V_66 -> V_81 ) ;
V_66 -> V_82 = F_31 ( V_66 -> V_82 ) ;
V_66 -> V_83 = F_31 ( V_66 -> V_83 ) ;
V_66 -> V_84 = F_31 ( V_66 -> V_84 ) ;
V_66 -> V_85 = F_31 ( V_66 -> V_85 ) ;
V_66 -> V_86 = F_31 ( V_66 -> V_86 ) ;
V_66 -> V_87 = F_31 ( V_66 -> V_87 ) ;
V_66 -> V_88 = F_31 ( V_66 -> V_88 ) ;
V_66 -> V_89 = F_31 ( V_66 -> V_89 ) ;
V_66 -> V_90 = F_31 ( V_66 -> V_90 ) ;
V_66 -> V_91 = F_31 ( V_66 -> V_91 ) ;
V_66 -> V_92 = F_31 ( V_66 -> V_92 ) ;
V_66 -> V_93 = F_31 ( V_66 -> V_93 ) ;
V_67 = ( void * ) V_66 + V_66 -> V_86 ;
V_65 -> V_67 = V_67 ;
if ( V_66 -> V_86 > V_65 -> V_50 ) {
F_1 ( L_17
L_18 , ( unsigned long ) V_66 -> V_86 ,
V_49 , V_65 -> V_50 ) ;
return 0 ;
}
if ( V_66 -> V_92 == V_94 ) {
V_65 -> V_95 = F_31 ( V_67 [ 0 ] . V_96 ) ;
}
else {
V_65 -> V_95 = V_66 -> V_92 ;
}
if ( V_66 -> V_93 == V_97 ) {
V_65 -> V_98 = F_31 ( V_67 [ 0 ] . V_99 ) ;
}
else {
V_65 -> V_98 = V_66 -> V_93 ;
}
for ( V_18 = 0 ; V_18 < V_65 -> V_95 ; V_18 ++ ) {
V_67 [ V_18 ] . V_100 = F_31 ( V_67 [ V_18 ] . V_100 ) ;
V_67 [ V_18 ] . V_101 = F_31 ( V_67 [ V_18 ] . V_101 ) ;
V_67 [ V_18 ] . V_102 = F_31 ( V_67 [ V_18 ] . V_102 ) ;
V_67 [ V_18 ] . V_103 = F_31 ( V_67 [ V_18 ] . V_103 ) ;
V_67 [ V_18 ] . V_104 = F_31 ( V_67 [ V_18 ] . V_104 ) ;
V_67 [ V_18 ] . V_96 = F_31 ( V_67 [ V_18 ] . V_96 ) ;
V_67 [ V_18 ] . V_99 = F_31 ( V_67 [ V_18 ] . V_99 ) ;
V_67 [ V_18 ] . V_105 = F_31 ( V_67 [ V_18 ] . V_105 ) ;
V_67 [ V_18 ] . V_106 = F_31 ( V_67 [ V_18 ] . V_106 ) ;
V_67 [ V_18 ] . V_107 = F_31 ( V_67 [ V_18 ] . V_107 ) ;
}
V_69 = ( void * ) V_66 + V_67 [ V_65 -> V_98 ] . V_104 ;
for ( V_18 = 1 ; V_18 < V_65 -> V_95 ; V_18 ++ ) {
const char * V_33 ;
int V_108 = V_67 [ V_18 ] . V_101 == V_109 ;
if ( ! V_108 && V_67 [ V_18 ] . V_104 > V_65 -> V_50 ) {
F_1 ( L_19
L_20 , V_49 ,
( unsigned long ) V_67 [ V_18 ] . V_104 ,
sizeof( * V_66 ) ) ;
return 0 ;
}
V_33 = V_69 + V_67 [ V_18 ] . V_100 ;
if ( strcmp ( V_33 , L_21 ) == 0 ) {
if ( V_108 )
F_1 ( L_22 , V_49 ) ;
V_65 -> V_110 = ( void * ) V_66 + V_67 [ V_18 ] . V_104 ;
V_65 -> V_111 = V_67 [ V_18 ] . V_96 ;
} else if ( strcmp ( V_33 , L_23 ) == 0 )
V_65 -> V_39 = V_18 ;
else if ( strcmp ( V_33 , L_24 ) == 0 )
V_65 -> V_40 = V_18 ;
else if ( strcmp ( V_33 , L_25 ) == 0 )
V_65 -> V_41 = V_18 ;
else if ( strcmp ( V_33 , L_26 ) == 0 )
V_65 -> V_42 = V_18 ;
else if ( strcmp ( V_33 , L_27 ) == 0 )
V_65 -> V_43 = V_18 ;
if ( V_67 [ V_18 ] . V_101 == V_112 ) {
unsigned int V_113 ;
V_70 = V_18 ;
V_65 -> V_114 = ( void * ) V_66 +
V_67 [ V_18 ] . V_104 ;
V_65 -> V_115 = ( void * ) V_66 +
V_67 [ V_18 ] . V_104 + V_67 [ V_18 ] . V_96 ;
V_113 = V_67 [ V_18 ] . V_99 ;
V_65 -> V_116 = ( void * ) V_66 +
V_67 [ V_113 ] . V_104 ;
}
if ( V_67 [ V_18 ] . V_101 == V_117 ) {
V_71 = V_18 ;
V_65 -> V_118 = ( void * ) V_66 +
V_67 [ V_18 ] . V_104 ;
V_65 -> V_119 = ( void * ) V_66 +
V_67 [ V_18 ] . V_104 + V_67 [ V_18 ] . V_96 ;
}
}
if ( ! V_65 -> V_114 )
F_1 ( L_28 , V_49 ) ;
for ( V_68 = V_65 -> V_114 ; V_68 < V_65 -> V_115 ; V_68 ++ ) {
V_68 -> V_120 = F_31 ( V_68 -> V_120 ) ;
V_68 -> V_121 = F_31 ( V_68 -> V_121 ) ;
V_68 -> V_122 = F_31 ( V_68 -> V_122 ) ;
V_68 -> V_56 = F_31 ( V_68 -> V_56 ) ;
}
if ( V_71 != ~ 0U ) {
T_6 * V_13 ;
if ( V_70 != V_67 [ V_71 ] . V_99 )
F_1 ( L_29 ,
V_49 , V_67 [ V_71 ] . V_99 ,
V_70 ) ;
for ( V_13 = V_65 -> V_118 ; V_13 < V_65 -> V_119 ;
V_13 ++ )
* V_13 = F_31 ( * V_13 ) ;
}
return 1 ;
}
static void F_32 ( struct V_30 * V_65 )
{
F_28 ( V_65 -> V_66 , V_65 -> V_50 ) ;
}
static int F_33 ( struct V_30 * V_65 , const char * V_123 )
{
if ( strcmp ( V_123 , V_124 L_30 ) == 0 )
return 1 ;
if ( strcmp ( V_123 , L_31 ) == 0 )
return 1 ;
if ( V_65 -> V_66 -> V_82 == V_125 )
if ( strncmp ( V_123 , L_32 , sizeof( L_32 ) - 1 ) == 0 ||
strncmp ( V_123 , L_33 , sizeof( L_33 ) - 1 ) == 0 ||
strncmp ( V_123 , L_34 , sizeof( L_34 ) - 1 ) == 0 ||
strncmp ( V_123 , L_35 , sizeof( L_35 ) - 1 ) == 0 )
return 1 ;
if ( V_65 -> V_66 -> V_82 == V_126 )
if ( strncmp ( V_123 , L_36 , sizeof( L_36 ) - 1 ) == 0 ||
strncmp ( V_123 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
return 1 ;
return 0 ;
}
static void F_34 ( struct V_8 * V_9 , struct V_30 * V_65 ,
T_5 * V_68 , const char * V_123 )
{
unsigned int V_47 ;
enum V_21 V_21 ;
if ( ( ! F_4 ( V_9 -> V_12 ) || V_9 -> V_15 ) &&
strncmp ( V_123 , L_23 , 9 ) == 0 )
V_21 = F_16 ( V_65 , F_35 ( V_65 , V_68 ) ) ;
else
V_21 = F_19 ( V_65 , F_35 ( V_65 , V_68 ) ) ;
switch ( V_68 -> V_120 ) {
case V_127 :
F_2 ( L_38 , V_123 , V_9 -> V_12 ) ;
break;
case V_128 :
if ( strncmp ( V_123 , V_129 , strlen ( V_129 ) ) == 0 ) {
V_47 = ( unsigned int ) V_68 -> V_122 ;
F_21 ( V_123 + strlen ( V_129 ) , V_9 , V_47 ,
V_21 ) ;
}
break;
case V_94 :
if ( F_36 ( V_68 -> V_130 ) != V_131 &&
F_36 ( V_68 -> V_130 ) != V_132 )
break;
if ( F_33 ( V_65 , V_123 ) )
break;
#if F_37 ( V_133 ) || F_37 ( V_134 )
#ifndef V_134
#define V_134 STT_REGISTER
#endif
if ( V_65 -> V_66 -> V_82 == V_135 ||
V_65 -> V_66 -> V_82 == V_136 ) {
if ( F_38 ( V_68 -> V_130 ) == V_134 )
break;
if ( V_123 [ 0 ] == '.' ) {
char * V_137 = F_9 ( V_123 ) ;
V_137 [ 0 ] = '_' ;
V_137 [ 1 ] = toupper ( V_137 [ 1 ] ) ;
V_123 = V_137 ;
}
}
#endif
if ( memcmp ( V_123 , V_124 ,
strlen ( V_124 ) ) == 0 ) {
V_9 -> V_138 =
F_11 ( V_123 +
strlen ( V_124 ) ,
F_36 ( V_68 -> V_130 ) == V_132 ,
V_9 -> V_138 ) ;
}
break;
default:
if ( strncmp ( V_123 , V_139 , strlen ( V_139 ) ) == 0 ) {
F_20 ( V_123 + strlen ( V_139 ) , V_9 ,
V_21 ) ;
}
if ( strcmp ( V_123 , V_124 L_39 ) == 0 )
V_9 -> V_140 = 1 ;
if ( strcmp ( V_123 , V_124 L_40 ) == 0 )
V_9 -> V_141 = 1 ;
break;
}
}
static char * F_39 ( char * string , unsigned long * V_142 )
{
while ( string [ 0 ] ) {
string ++ ;
if ( ( * V_142 ) -- <= 1 )
return NULL ;
}
while ( ! string [ 0 ] ) {
string ++ ;
if ( ( * V_142 ) -- <= 1 )
return NULL ;
}
return string ;
}
static char * F_40 ( void * V_110 , unsigned long V_111 ,
const char * V_143 , char * V_65 )
{
char * V_13 ;
unsigned int V_144 = strlen ( V_143 ) ;
unsigned long V_50 = V_111 ;
if ( V_65 ) {
V_50 -= V_65 - ( char * ) V_110 ;
V_110 = F_39 ( V_65 , & V_50 ) ;
}
for ( V_13 = V_110 ; V_13 ; V_13 = F_39 ( V_13 , & V_50 ) ) {
if ( strncmp ( V_13 , V_143 , V_144 ) == 0 && V_13 [ V_144 ] == '=' )
return V_13 + V_144 + 1 ;
}
return NULL ;
}
static char * F_41 ( void * V_110 , unsigned long V_111 ,
const char * V_143 )
{
return F_40 ( V_110 , V_111 , V_143 , NULL ) ;
}
static int F_42 ( const char * V_14 , const char * V_145 )
{
int V_146 , V_147 ;
if ( ! V_14 || ! V_145 )
return 1 ;
V_146 = strlen ( V_14 ) ;
V_147 = strlen ( V_145 ) ;
if ( ( V_146 == 0 ) || ( V_147 == 0 ) )
return 1 ;
if ( V_147 > V_146 )
return 1 ;
return memcmp ( V_14 + V_146 - V_147 , V_145 , V_147 ) ;
}
static const char * F_43 ( struct V_30 * V_31 , T_5 * V_68 )
{
if ( V_68 )
return V_31 -> V_116 + V_68 -> V_121 ;
else
return L_41 ;
}
static const char * F_17 ( struct V_30 * V_31 , int V_148 )
{
T_4 * V_67 = V_31 -> V_67 ;
return ( void * ) V_31 -> V_66 +
V_31 -> V_67 [ V_31 -> V_98 ] . V_104 +
V_67 [ V_148 ] . V_100 ;
}
static const char * F_44 ( struct V_30 * V_31 , T_4 * V_149 )
{
return ( void * ) V_31 -> V_66 +
V_31 -> V_67 [ V_31 -> V_98 ] . V_104 +
V_149 -> V_100 ;
}
static int F_45 ( const char * V_68 )
{
if ( * V_68 ++ == '\0' )
return 1 ;
if ( * V_68 != '.' )
return 0 ;
do {
char V_150 = * V_68 ++ ;
if ( V_150 < '0' || V_150 > '9' )
return 0 ;
} while ( * V_68 );
return 1 ;
}
static int F_46 ( const char * V_68 , const char * const V_151 [] )
{
const char * V_13 ;
while ( * V_151 ) {
V_13 = * V_151 ++ ;
const char * V_152 = V_13 + strlen ( V_13 ) - 1 ;
if ( * V_13 == '*' ) {
if ( F_42 ( V_68 , V_13 + 1 ) == 0 )
return 1 ;
}
else if ( * V_152 == '*' ) {
if ( strncmp ( V_68 , V_13 , strlen ( V_13 ) - 1 ) == 0 )
return 1 ;
}
else if ( * V_152 == '$' ) {
if ( strncmp ( V_68 , V_13 , strlen ( V_13 ) - 1 ) == 0 ) {
if ( F_45 ( V_68 + strlen ( V_13 ) - 1 ) )
return 1 ;
}
}
else {
if ( strcmp ( V_13 , V_68 ) == 0 )
return 1 ;
}
}
return 0 ;
}
static void F_47 ( const char * V_4 , struct V_30 * V_31 ,
T_4 * V_149 )
{
const char * V_32 = F_44 ( V_31 , V_149 ) ;
if ( V_149 -> V_101 == V_153 &&
! ( V_149 -> V_102 & V_154 ) &&
! F_46 ( V_32 , V_155 ) ) {
F_2 ( L_42
L_43
L_44
L_45 ,
V_4 , V_32 ) ;
}
}
static const struct V_156 * F_48 (
const char * V_157 , const char * V_158 )
{
int V_18 ;
int V_159 = sizeof( V_156 ) / sizeof( struct V_156 ) ;
const struct V_156 * V_160 = & V_156 [ 0 ] ;
for ( V_18 = 0 ; V_18 < V_159 ; V_18 ++ ) {
if ( F_46 ( V_157 , V_160 -> V_157 ) &&
F_46 ( V_158 , V_160 -> V_158 ) )
return V_160 ;
V_160 ++ ;
}
return NULL ;
}
static int F_49 ( const struct V_156 * V_161 ,
const char * V_157 , const char * V_162 ,
const char * V_158 , const char * V_163 )
{
if ( F_46 ( V_158 , V_164 ) &&
F_46 ( V_157 , V_165 ) &&
( strncmp ( V_162 , L_46 , strlen ( L_46 ) ) == 0 ) )
return 0 ;
if ( strcmp ( V_158 , L_47 ) == 0 &&
F_46 ( V_157 , V_165 ) &&
( strncmp ( V_162 , L_48 , strlen ( L_48 ) ) == 0 ) )
return 0 ;
if ( F_46 ( V_158 , V_166 ) &&
F_46 ( V_157 , V_165 ) &&
F_46 ( V_162 , V_161 -> V_167 ) )
return 0 ;
if ( F_46 ( V_157 , V_168 ) &&
F_46 ( V_158 , V_169 ) )
return 0 ;
if ( F_46 ( V_163 , V_170 ) )
return 0 ;
return 1 ;
}
static T_5 * F_50 ( struct V_30 * V_31 , T_7 V_171 ,
T_5 * V_172 )
{
T_5 * V_68 ;
T_5 * V_173 = NULL ;
T_7 V_174 = 20 ;
T_7 V_175 ;
unsigned int V_176 ;
if ( V_172 -> V_121 != 0 )
return V_172 ;
V_176 = F_35 ( V_31 , V_172 ) ;
for ( V_68 = V_31 -> V_114 ; V_68 < V_31 -> V_115 ; V_68 ++ ) {
if ( F_35 ( V_31 , V_68 ) != V_176 )
continue;
if ( F_38 ( V_68 -> V_130 ) == V_177 )
continue;
if ( V_68 -> V_122 == V_171 )
return V_68 ;
V_175 = V_68 -> V_122 - V_171 ;
if ( V_175 < 0 )
V_175 = V_171 - V_68 -> V_122 ;
if ( V_175 < V_174 ) {
V_174 = V_175 ;
V_173 = V_68 ;
}
}
if ( V_174 < 20 )
return V_173 ;
else
return NULL ;
}
static inline int F_51 ( const char * V_28 )
{
return V_28 [ 0 ] == '$' && strchr ( L_49 , V_28 [ 1 ] )
&& ( V_28 [ 2 ] == '\0' || V_28 [ 2 ] == '.' ) ;
}
static inline int F_52 ( struct V_30 * V_31 , T_5 * V_68 )
{
const char * V_12 = V_31 -> V_116 + V_68 -> V_121 ;
if ( ! V_12 || ! strlen ( V_12 ) )
return 0 ;
return ! F_51 ( V_12 ) ;
}
static T_5 * F_53 ( struct V_30 * V_31 , T_8 V_171 ,
const char * V_32 )
{
T_5 * V_68 ;
T_5 * V_173 = NULL ;
T_8 V_174 = ~ 0 ;
for ( V_68 = V_31 -> V_114 ; V_68 < V_31 -> V_115 ; V_68 ++ ) {
const char * V_178 ;
if ( F_54 ( V_68 -> V_120 ) )
continue;
V_178 = F_17 ( V_31 , F_35 ( V_31 , V_68 ) ) ;
if ( strcmp ( V_178 , V_32 ) != 0 )
continue;
if ( ! F_52 ( V_31 , V_68 ) )
continue;
if ( V_68 -> V_122 <= V_171 ) {
if ( ( V_171 - V_68 -> V_122 ) < V_174 ) {
V_174 = V_171 - V_68 -> V_122 ;
V_173 = V_68 ;
} else if ( ( V_171 - V_68 -> V_122 ) == V_174 ) {
V_173 = V_68 ;
}
}
}
return V_173 ;
}
static char * F_55 ( const char * V_14 )
{
if ( F_46 ( V_14 , V_166 ) ) {
char * V_13 = malloc ( 20 ) ;
char * V_179 = V_13 ;
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
return V_179 ;
} else {
return F_9 ( L_15 ) ;
}
}
static int F_56 ( T_5 * V_68 )
{
if ( V_68 )
return F_38 ( V_68 -> V_130 ) == V_180 ;
else
return - 1 ;
}
static void F_57 ( const char * const V_181 [ 20 ] )
{
const char * const * V_14 = V_181 ;
while ( * V_14 ) {
fprintf ( V_3 , L_55 , * V_14 ) ;
V_14 ++ ;
if ( * V_14 )
fprintf ( V_3 , L_56 ) ;
}
fprintf ( V_3 , L_57 ) ;
}
static void F_58 ( const char * V_4 ,
const struct V_156 * V_161 ,
const char * V_157 ,
unsigned long long V_182 ,
const char * V_162 ,
int V_183 ,
const char * V_158 , const char * V_163 ,
int V_184 )
{
const char * V_185 , * V_186 ;
const char * V_187 , * V_188 ;
char * V_189 ;
char * V_190 ;
switch ( V_183 ) {
case 0 : V_185 = L_58 ; V_186 = L_15 ; break;
case 1 : V_185 = L_59 ; V_186 = L_60 ; break;
default: V_185 = L_61 ; V_186 = L_15 ; break;
}
switch ( V_184 ) {
case 0 : V_187 = L_58 ; V_188 = L_15 ; break;
case 1 : V_187 = L_59 ; V_188 = L_60 ; break;
default: V_187 = L_61 ; V_188 = L_15 ; break;
}
V_191 ++ ;
if ( ! V_192 )
return;
F_2 ( L_62
L_63 ,
V_4 , V_157 , V_182 , V_185 , V_162 , V_186 , V_187 , V_158 ,
V_163 , V_188 ) ;
switch ( V_161 -> V_161 ) {
case V_193 :
V_189 = F_55 ( V_157 ) ;
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_64
L_65
L_66
L_67 ,
V_189 , V_162 ,
V_187 , V_190 , V_163 , V_188 ,
V_162 , V_190 , V_163 ) ;
free ( V_189 ) ;
free ( V_190 ) ;
break;
case V_194 : {
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_68
L_69
L_70
L_71
L_72 ,
V_162 , V_187 , V_190 , V_163 , V_188 ) ;
F_57 ( V_161 -> V_167 ) ;
free ( V_190 ) ;
break;
}
case V_195 :
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_73
L_74
L_75 ,
V_162 , V_187 , V_187 , V_163 , V_188 , V_190 , V_163 ) ;
free ( V_190 ) ;
break;
case V_196 : {
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_68
L_69
L_70
L_76
L_77 ,
V_162 , V_187 , V_190 , V_163 , V_188 ) ;
F_57 ( V_161 -> V_167 ) ;
free ( V_190 ) ;
break;
}
case V_197 :
case V_198 :
V_189 = F_55 ( V_157 ) ;
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_78
L_79
L_80
L_81 ,
V_185 , V_189 , V_162 , V_186 ,
V_187 , V_190 , V_163 , V_188 ,
V_163 , V_162 , V_163 ) ;
free ( V_189 ) ;
free ( V_190 ) ;
break;
case V_199 :
V_189 = F_55 ( V_157 ) ;
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_78
L_79
L_82
L_83
L_84
L_85
L_86 ,
V_185 , V_189 , V_162 , V_186 ,
V_187 , V_190 , V_163 , V_188 ,
V_190 , V_163 , V_188 ) ;
free ( V_189 ) ;
free ( V_190 ) ;
break;
case V_200 :
V_189 = F_55 ( V_157 ) ;
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_78
L_79
L_82
L_87
L_88
L_85
L_89 ,
V_185 , V_189 , V_162 , V_186 ,
V_187 , V_190 , V_163 , V_188 ,
V_190 , V_163 , V_188 ) ;
free ( V_189 ) ;
free ( V_190 ) ;
break;
case V_201 :
V_190 = F_55 ( V_158 ) ;
fprintf ( V_3 ,
L_90
L_91
L_92 ,
V_163 , V_190 , V_190 , V_163 ) ;
free ( V_190 ) ;
break;
}
fprintf ( V_3 , L_57 ) ;
}
static void F_59 ( const char * V_4 , struct V_30 * V_31 ,
T_9 * V_179 , T_5 * V_68 , const char * V_157 )
{
const char * V_158 ;
const struct V_156 * V_161 ;
V_158 = F_17 ( V_31 , F_35 ( V_31 , V_68 ) ) ;
V_161 = F_48 ( V_157 , V_158 ) ;
if ( V_161 ) {
T_5 * V_187 ;
T_5 * V_185 ;
const char * V_163 ;
const char * V_162 ;
V_185 = F_53 ( V_31 , V_179 -> V_202 , V_157 ) ;
V_162 = F_43 ( V_31 , V_185 ) ;
V_187 = F_50 ( V_31 , V_179 -> V_203 , V_68 ) ;
V_163 = F_43 ( V_31 , V_187 ) ;
if ( F_49 ( V_161 ,
V_157 , V_162 , V_158 , V_163 ) ) {
F_58 ( V_4 , V_161 ,
V_157 , V_179 -> V_202 , V_162 ,
F_56 ( V_185 ) , V_158 , V_163 ,
F_56 ( V_187 ) ) ;
}
}
}
static unsigned int * F_60 ( struct V_30 * V_31 ,
T_4 * V_149 , T_9 * V_179 )
{
T_4 * V_67 = V_31 -> V_67 ;
int V_204 = V_149 -> V_105 ;
return ( void * ) V_31 -> V_66 + V_67 [ V_204 ] . V_104 +
V_179 -> V_202 ;
}
static int F_61 ( struct V_30 * V_31 , T_4 * V_149 , T_9 * V_179 )
{
unsigned int V_205 = F_62 ( V_179 -> V_206 ) ;
unsigned int * V_207 = F_60 ( V_31 , V_149 , V_179 ) ;
switch ( V_205 ) {
case V_208 :
V_179 -> V_203 = F_31 ( * V_207 ) ;
break;
case V_209 :
V_179 -> V_203 = F_31 ( * V_207 ) + 4 ;
if ( V_31 -> V_66 -> V_81 == V_210 )
V_179 -> V_203 += V_179 -> V_202 ;
break;
}
return 0 ;
}
static int F_63 ( struct V_30 * V_31 , T_4 * V_149 , T_9 * V_179 )
{
unsigned int V_205 = F_62 ( V_179 -> V_206 ) ;
switch ( V_205 ) {
case V_211 :
V_179 -> V_203 = ( int ) ( long )
( V_31 -> V_114 + F_64 ( V_179 -> V_206 ) ) ;
break;
case V_212 :
case V_213 :
case V_214 :
V_179 -> V_203 = ( int ) ( long ) ( V_31 -> V_66 +
V_149 -> V_104 +
( V_179 -> V_202 - V_149 -> V_103 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_65 ( struct V_30 * V_31 , T_4 * V_149 , T_9 * V_179 )
{
unsigned int V_205 = F_62 ( V_179 -> V_206 ) ;
unsigned int * V_207 = F_60 ( V_31 , V_149 , V_179 ) ;
unsigned int V_215 ;
if ( V_205 == V_216 )
return 1 ;
V_215 = F_31 ( * V_207 ) ;
switch ( V_205 ) {
case V_217 :
V_179 -> V_203 = V_215 & 0xffff ;
break;
case V_218 :
V_179 -> V_203 = ( V_215 & 0x03ffffff ) << 2 ;
break;
case V_219 :
V_179 -> V_203 = V_215 ;
break;
}
return 0 ;
}
static void F_66 ( const char * V_4 , struct V_30 * V_31 ,
T_4 * V_149 )
{
T_5 * V_68 ;
T_9 * V_220 ;
T_9 V_179 ;
unsigned int V_221 ;
const char * V_157 ;
T_9 * V_222 = ( void * ) V_31 -> V_66 + V_149 -> V_104 ;
T_9 * V_223 = ( void * ) V_222 + V_149 -> V_96 ;
V_157 = F_44 ( V_31 , V_149 ) ;
V_157 += strlen ( L_93 ) ;
if ( F_46 ( V_157 , V_155 ) )
return;
for ( V_220 = V_222 ; V_220 < V_223 ; V_220 ++ ) {
V_179 . V_202 = F_31 ( V_220 -> V_202 ) ;
#if V_224 == V_225
if ( V_31 -> V_66 -> V_82 == V_226 ) {
unsigned int V_205 ;
V_221 = F_67 ( V_220 -> V_206 ) ;
V_221 = F_31 ( V_221 ) ;
V_205 = F_68 ( V_220 -> V_206 ) ;
V_179 . V_206 = F_69 ( V_221 , V_205 ) ;
} else {
V_179 . V_206 = F_31 ( V_220 -> V_206 ) ;
V_221 = F_64 ( V_179 . V_206 ) ;
}
#else
V_179 . V_206 = F_31 ( V_220 -> V_206 ) ;
V_221 = F_64 ( V_179 . V_206 ) ;
#endif
V_179 . V_203 = F_31 ( V_220 -> V_203 ) ;
V_68 = V_31 -> V_114 + V_221 ;
if ( F_54 ( V_68 -> V_120 ) )
continue;
F_59 ( V_4 , V_31 , & V_179 , V_68 , V_157 ) ;
}
}
static void F_70 ( const char * V_4 , struct V_30 * V_31 ,
T_4 * V_149 )
{
T_5 * V_68 ;
T_10 * V_227 ;
T_9 V_179 ;
unsigned int V_221 ;
const char * V_157 ;
T_10 * V_222 = ( void * ) V_31 -> V_66 + V_149 -> V_104 ;
T_10 * V_223 = ( void * ) V_222 + V_149 -> V_96 ;
V_157 = F_44 ( V_31 , V_149 ) ;
V_157 += strlen ( L_94 ) ;
if ( F_46 ( V_157 , V_155 ) )
return;
for ( V_227 = V_222 ; V_227 < V_223 ; V_227 ++ ) {
V_179 . V_202 = F_31 ( V_227 -> V_202 ) ;
#if V_224 == V_225
if ( V_31 -> V_66 -> V_82 == V_226 ) {
unsigned int V_205 ;
V_221 = F_67 ( V_227 -> V_206 ) ;
V_221 = F_31 ( V_221 ) ;
V_205 = F_68 ( V_227 -> V_206 ) ;
V_179 . V_206 = F_69 ( V_221 , V_205 ) ;
} else {
V_179 . V_206 = F_31 ( V_227 -> V_206 ) ;
V_221 = F_64 ( V_179 . V_206 ) ;
}
#else
V_179 . V_206 = F_31 ( V_227 -> V_206 ) ;
V_221 = F_64 ( V_179 . V_206 ) ;
#endif
V_179 . V_203 = 0 ;
switch ( V_31 -> V_66 -> V_82 ) {
case V_228 :
if ( F_61 ( V_31 , V_149 , & V_179 ) )
continue;
break;
case V_229 :
if ( F_63 ( V_31 , V_149 , & V_179 ) )
continue;
break;
case V_226 :
if ( F_65 ( V_31 , V_149 , & V_179 ) )
continue;
break;
}
V_68 = V_31 -> V_114 + V_221 ;
if ( F_54 ( V_68 -> V_120 ) )
continue;
F_59 ( V_4 , V_31 , & V_179 , V_68 , V_157 ) ;
}
}
static void F_71 ( struct V_8 * V_9 , const char * V_4 ,
struct V_30 * V_31 )
{
int V_18 ;
T_4 * V_67 = V_31 -> V_67 ;
for ( V_18 = 0 ; V_18 < V_31 -> V_95 ; V_18 ++ ) {
F_47 ( V_4 , V_31 , & V_31 -> V_67 [ V_18 ] ) ;
if ( V_67 [ V_18 ] . V_101 == V_230 )
F_66 ( V_4 , V_31 , & V_31 -> V_67 [ V_18 ] ) ;
else if ( V_67 [ V_18 ] . V_101 == V_231 )
F_70 ( V_4 , V_31 , & V_31 -> V_67 [ V_18 ] ) ;
}
}
static void F_72 ( char * V_4 )
{
const char * V_123 ;
char * V_232 ;
char * V_233 ;
struct V_8 * V_9 ;
struct V_30 V_65 = { } ;
T_5 * V_68 ;
if ( ! F_30 ( & V_65 , V_4 ) )
return;
V_9 = F_7 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
V_234 = 1 ;
V_9 -> V_63 = 1 ;
}
V_233 = F_41 ( V_65 . V_110 , V_65 . V_111 , L_95 ) ;
if ( V_65 . V_110 && ! V_233 && ! F_4 ( V_4 ) )
F_2 ( L_96
L_97
L_98 , V_4 ) ;
while ( V_233 ) {
if ( F_73 ( V_233 ) )
V_9 -> V_16 = 1 ;
else {
V_9 -> V_16 = 0 ;
break;
}
V_233 = F_40 ( V_65 . V_110 , V_65 . V_111 ,
L_95 , V_233 ) ;
}
for ( V_68 = V_65 . V_114 ; V_68 < V_65 . V_115 ; V_68 ++ ) {
V_123 = V_65 . V_116 + V_68 -> V_121 ;
F_34 ( V_9 , & V_65 , V_68 , V_123 ) ;
F_74 ( V_9 , & V_65 , V_68 , V_123 ) ;
}
if ( ! F_4 ( V_4 ) ||
( F_4 ( V_4 ) && V_235 ) )
F_71 ( V_9 , V_4 , & V_65 ) ;
V_232 = F_41 ( V_65 . V_110 , V_65 . V_111 , L_99 ) ;
if ( V_232 )
F_75 ( V_4 , V_232 , V_65 . V_110 ,
V_232 - ( char * ) V_65 . V_66 ) ;
if ( V_232 || ( V_236 && ! F_4 ( V_4 ) ) )
F_76 ( V_4 , V_9 -> V_237 ,
sizeof( V_9 -> V_237 ) - 1 ) ;
F_32 ( & V_65 ) ;
if ( V_238 )
V_9 -> V_138 = F_11 ( L_100 , 0 , V_9 -> V_138 ) ;
}
void F_77 ( struct V_239 * V_240 , const char * V_14 , int V_64 )
{
if ( V_240 -> V_50 - V_240 -> V_61 < V_64 ) {
V_240 -> V_50 += V_64 + V_241 ;
V_240 -> V_13 = realloc ( V_240 -> V_13 , V_240 -> V_50 ) ;
}
strncpy ( V_240 -> V_13 + V_240 -> V_61 , V_14 , V_64 ) ;
V_240 -> V_61 += V_64 ;
}
static void F_78 ( enum V_21 exp , const char * V_242 , const char * V_14 )
{
const char * V_243 = F_4 ( V_242 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_36 :
F_1 ( L_101
L_102 , V_242 , V_243 , V_14 ) ;
break;
case V_37 :
F_1 ( L_101
L_103 , V_242 , V_243 , V_14 ) ;
break;
case V_38 :
F_2 ( L_101
L_104 , V_242 , V_243 , V_14 ) ;
break;
case V_34 :
case V_35 :
case V_29 :
break;
}
}
static void F_79 ( enum V_21 exp , const char * V_242 , const char * V_14 )
{
const char * V_243 = F_4 ( V_242 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_35 :
case V_37 :
F_2 ( L_105
L_106 , V_242 , V_243 , V_14 ) ;
break;
default:
break;
}
}
static void F_80 ( struct V_8 * V_9 )
{
struct V_19 * V_14 , * exp ;
for ( V_14 = V_9 -> V_138 ; V_14 ; V_14 = V_14 -> V_11 ) {
const char * V_244 ;
exp = F_13 ( V_14 -> V_12 ) ;
if ( ! exp || exp -> V_8 == V_9 )
continue;
V_244 = strrchr ( V_9 -> V_12 , '/' ) ;
if ( V_244 )
V_244 ++ ;
else
V_244 = V_9 -> V_12 ;
if ( ! V_9 -> V_16 )
F_78 ( exp -> V_21 , V_244 , exp -> V_12 ) ;
F_79 ( exp -> V_21 , V_244 , exp -> V_12 ) ;
}
}
static void F_81 ( struct V_239 * V_245 , struct V_8 * V_9 )
{
F_82 ( V_245 , L_107 ) ;
F_82 ( V_245 , L_108 ) ;
F_82 ( V_245 , L_109 ) ;
F_82 ( V_245 , L_57 ) ;
F_82 ( V_245 , L_110 ) ;
F_82 ( V_245 , L_57 ) ;
F_82 ( V_245 , L_111 ) ;
F_82 ( V_245 , L_112 ) ;
F_82 ( V_245 , L_113 ) ;
if ( V_9 -> V_140 )
F_82 ( V_245 , L_114 ) ;
if ( V_9 -> V_141 )
F_82 ( V_245 , L_115
L_116
L_117 ) ;
F_82 ( V_245 , L_118 ) ;
F_82 ( V_245 , L_119 ) ;
}
static void F_83 ( struct V_239 * V_245 , int V_246 )
{
if ( V_246 )
F_82 ( V_245 , L_120 ) ;
}
static void F_84 ( struct V_239 * V_245 , const char * V_12 )
{
static const char * V_247 = L_121 ;
if ( strncmp ( V_247 , V_12 , strlen ( V_247 ) ) == 0 )
F_82 ( V_245 , L_122 ) ;
}
static int F_85 ( struct V_239 * V_245 , struct V_8 * V_9 )
{
struct V_19 * V_14 , * exp ;
int V_248 = 0 ;
for ( V_14 = V_9 -> V_138 ; V_14 ; V_14 = V_14 -> V_11 ) {
exp = F_13 ( V_14 -> V_12 ) ;
if ( ! exp || exp -> V_8 == V_9 ) {
if ( V_234 && ! V_14 -> V_20 ) {
if ( V_249 ) {
F_2 ( L_123 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
} else {
F_3 ( L_123 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
V_248 = 1 ;
}
}
continue;
}
V_14 -> V_8 = exp -> V_8 ;
V_14 -> V_48 = exp -> V_48 ;
V_14 -> V_47 = exp -> V_47 ;
}
if ( ! V_238 )
return V_248 ;
F_82 ( V_245 , L_57 ) ;
F_82 ( V_245 , L_124 ) ;
F_82 ( V_245 , L_125 ) ;
F_82 ( V_245 , L_126 ) ;
for ( V_14 = V_9 -> V_138 ; V_14 ; V_14 = V_14 -> V_11 ) {
if ( ! V_14 -> V_8 )
continue;
if ( ! V_14 -> V_48 ) {
F_2 ( L_127 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
continue;
}
F_82 ( V_245 , L_128 , V_14 -> V_47 , V_14 -> V_12 ) ;
}
F_82 ( V_245 , L_119 ) ;
return V_248 ;
}
static void F_86 ( struct V_239 * V_245 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_19 * V_14 ;
struct V_8 * V_242 ;
int V_250 = 1 ;
for ( V_242 = V_10 ; V_242 ; V_242 = V_242 -> V_11 )
V_242 -> V_251 = F_4 ( V_242 -> V_12 ) ;
F_82 ( V_245 , L_57 ) ;
F_82 ( V_245 , L_129 ) ;
F_82 ( V_245 , L_125 ) ;
F_82 ( V_245 , L_130 ) ;
F_82 ( V_245 , L_131 ) ;
for ( V_14 = V_9 -> V_138 ; V_14 ; V_14 = V_14 -> V_11 ) {
const char * V_13 ;
if ( ! V_14 -> V_8 )
continue;
if ( V_14 -> V_8 -> V_251 )
continue;
V_14 -> V_8 -> V_251 = 1 ;
V_13 = strrchr ( V_14 -> V_8 -> V_12 , '/' ) ;
if ( V_13 )
V_13 ++ ;
else
V_13 = V_14 -> V_8 -> V_12 ;
F_82 ( V_245 , L_132 , V_250 ? L_15 : L_133 , V_13 ) ;
V_250 = 0 ;
}
F_82 ( V_245 , L_134 ) ;
}
static void F_87 ( struct V_239 * V_245 , struct V_8 * V_9 )
{
if ( V_9 -> V_237 [ 0 ] ) {
F_82 ( V_245 , L_57 ) ;
F_82 ( V_245 , L_135 ,
V_9 -> V_237 ) ;
}
}
static void F_88 ( struct V_239 * V_245 , const char * V_252 )
{
char * V_253 ;
T_11 * V_62 ;
struct V_51 V_52 ;
V_62 = fopen ( V_252 , L_136 ) ;
if ( ! V_62 )
goto V_254;
if ( F_24 ( fileno ( V_62 ) , & V_52 ) < 0 )
goto V_255;
if ( V_52 . V_56 != V_245 -> V_61 )
goto V_255;
V_253 = F_8 ( malloc ( V_245 -> V_61 ) ) ;
if ( fread ( V_253 , 1 , V_245 -> V_61 , V_62 ) != V_245 -> V_61 )
goto V_256;
if ( memcmp ( V_253 , V_245 -> V_13 , V_245 -> V_61 ) != 0 )
goto V_256;
free ( V_253 ) ;
fclose ( V_62 ) ;
return;
V_256:
free ( V_253 ) ;
V_255:
fclose ( V_62 ) ;
V_254:
V_62 = fopen ( V_252 , L_137 ) ;
if ( ! V_62 ) {
perror ( V_252 ) ;
exit ( 1 ) ;
}
if ( fwrite ( V_245 -> V_13 , 1 , V_245 -> V_61 , V_62 ) != V_245 -> V_61 ) {
perror ( V_252 ) ;
exit ( 1 ) ;
}
fclose ( V_62 ) ;
}
static void F_89 ( const char * V_252 , unsigned int V_46 )
{
unsigned long V_50 , V_61 = 0 ;
void * V_62 = F_22 ( V_252 , & V_50 ) ;
char * line ;
if ( ! V_62 )
return;
while ( ( line = F_27 ( & V_61 , V_62 , V_50 ) ) ) {
char * V_123 , * V_4 , * V_175 , * V_21 , * V_257 ;
unsigned int V_47 ;
struct V_8 * V_9 ;
struct V_19 * V_14 ;
if ( ! ( V_123 = strchr ( line , '\t' ) ) )
goto V_258;
* V_123 ++ = '\0' ;
if ( ! ( V_4 = strchr ( V_123 , '\t' ) ) )
goto V_258;
* V_4 ++ = '\0' ;
if ( ( V_21 = strchr ( V_4 , '\t' ) ) != NULL )
* V_21 ++ = '\0' ;
if ( V_21 && ( ( V_257 = strchr ( V_21 , '\t' ) ) != NULL ) )
* V_257 = '\0' ;
V_47 = strtoul ( line , & V_175 , 16 ) ;
if ( * V_123 == '\0' || * V_4 == '\0' || * V_175 != '\0' )
goto V_258;
V_9 = F_6 ( V_4 ) ;
if ( ! V_9 ) {
if ( F_4 ( V_4 ) )
V_234 = 1 ;
V_9 = F_7 ( V_4 ) ;
V_9 -> V_63 = 1 ;
}
V_14 = F_20 ( V_123 , V_9 , F_15 ( V_21 ) ) ;
V_14 -> V_46 = V_46 ;
V_14 -> V_44 = 1 ;
F_21 ( V_123 , V_9 , V_47 , F_15 ( V_21 ) ) ;
}
return;
V_258:
F_1 ( L_138 ) ;
}
static int F_90 ( struct V_19 * V_68 )
{
if ( ! V_259 )
return 1 ;
if ( V_68 -> V_45 || V_68 -> V_46 )
return 0 ;
return 1 ;
}
static void F_91 ( const char * V_252 )
{
struct V_239 V_240 = { } ;
struct V_19 * V_19 ;
int V_260 ;
for ( V_260 = 0 ; V_260 < V_24 ; V_260 ++ ) {
V_19 = V_25 [ V_260 ] ;
while ( V_19 ) {
if ( F_90 ( V_19 ) )
F_82 ( & V_240 , L_139 ,
V_19 -> V_47 , V_19 -> V_12 ,
V_19 -> V_8 -> V_12 ,
F_14 ( V_19 -> V_21 ) ) ;
V_19 = V_19 -> V_11 ;
}
}
F_88 ( & V_240 , V_252 ) ;
}
int main ( int V_261 , char * * V_262 )
{
struct V_8 * V_9 ;
struct V_239 V_240 = { } ;
char * V_263 = NULL , * V_264 = NULL ;
char * V_265 = NULL ;
int V_266 ;
int V_248 ;
struct V_267 * V_268 ;
struct V_267 * V_269 = NULL ;
while ( ( V_266 = F_92 ( V_261 , V_262 , L_140 ) ) != - 1 ) {
switch ( V_266 ) {
case 'i' :
V_263 = V_270 ;
break;
case 'I' :
V_264 = V_270 ;
V_259 = 1 ;
break;
case 'c' :
V_271 = 1 ;
break;
case 'e' :
V_259 = 1 ;
V_268 =
F_8 ( malloc ( sizeof( * V_268 ) ) ) ;
V_268 -> V_11 = V_269 ;
V_268 -> V_62 = V_270 ;
V_269 = V_268 ;
break;
case 'm' :
V_238 = 1 ;
break;
case 'o' :
V_265 = V_270 ;
break;
case 'a' :
V_236 = 1 ;
break;
case 's' :
V_235 = 0 ;
break;
case 'S' :
V_192 = 0 ;
break;
case 'w' :
V_249 = 1 ;
break;
default:
exit ( 1 ) ;
}
}
if ( V_263 )
F_89 ( V_263 , 1 ) ;
if ( V_264 )
F_89 ( V_264 , 0 ) ;
while ( V_269 ) {
F_89 ( V_269 -> V_62 , 0 ) ;
V_268 = V_269 -> V_11 ;
free ( V_269 ) ;
V_269 = V_268 ;
}
while ( V_272 < V_261 )
F_72 ( V_262 [ V_272 ++ ] ) ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
if ( V_9 -> V_63 )
continue;
F_80 ( V_9 ) ;
}
V_248 = 0 ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
char V_252 [ strlen ( V_9 -> V_12 ) + 10 ] ;
if ( V_9 -> V_63 )
continue;
V_240 . V_61 = 0 ;
F_81 ( & V_240 , V_9 ) ;
F_83 ( & V_240 , ! V_259 ) ;
F_84 ( & V_240 , V_9 -> V_12 ) ;
V_248 |= F_85 ( & V_240 , V_9 ) ;
F_86 ( & V_240 , V_9 , V_10 ) ;
F_93 ( & V_240 , V_9 ) ;
F_87 ( & V_240 , V_9 ) ;
sprintf ( V_252 , L_141 , V_9 -> V_12 ) ;
F_88 ( & V_240 , V_252 ) ;
}
if ( V_265 )
F_91 ( V_265 ) ;
if ( V_191 && ! V_192 )
F_2 ( L_142
L_143
L_144 ,
V_191 ) ;
return V_248 ;
}
