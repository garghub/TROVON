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
const char * V_32 = F_17 ( V_30 , V_31 ) ;
if ( F_18 ( V_32 , L_8 ) )
return V_33 ;
else if ( F_18 ( V_32 , L_9 ) )
return V_34 ;
else if ( F_18 ( V_32 , L_10 ) )
return V_35 ;
else if ( F_18 ( V_32 , L_11 ) )
return V_36 ;
else if ( F_18 ( V_32 , L_12 ) )
return V_37 ;
else
return V_28 ;
}
static enum V_20 F_19 ( struct V_29 * V_30 , unsigned int V_31 )
{
if ( V_31 == V_30 -> V_38 )
return V_33 ;
else if ( V_31 == V_30 -> V_39 )
return V_34 ;
else if ( V_31 == V_30 -> V_40 )
return V_35 ;
else if ( V_31 == V_30 -> V_41 )
return V_36 ;
else if ( V_31 == V_30 -> V_42 )
return V_37 ;
else
return V_28 ;
}
static struct V_18 * F_20 ( const char * V_12 , struct V_8 * V_9 ,
enum V_20 V_20 )
{
struct V_18 * V_14 = F_13 ( V_12 ) ;
if ( ! V_14 ) {
V_14 = F_12 ( V_12 , V_9 , V_20 ) ;
} else {
if ( ! V_14 -> V_43 ) {
F_2 ( L_13
L_14 , V_9 -> V_12 , V_12 ,
V_14 -> V_8 -> V_12 ,
F_4 ( V_14 -> V_8 -> V_12 ) ? L_15 : L_16 ) ;
} else {
V_14 -> V_8 = V_9 ;
}
}
V_14 -> V_43 = 0 ;
V_14 -> V_44 = F_4 ( V_9 -> V_12 ) ;
V_14 -> V_45 = 0 ;
V_14 -> V_20 = V_20 ;
return V_14 ;
}
static void F_21 ( const char * V_12 , struct V_8 * V_9 ,
unsigned int V_46 , enum V_20 V_20 )
{
struct V_18 * V_14 = F_13 ( V_12 ) ;
if ( ! V_14 )
V_14 = F_12 ( V_12 , V_9 , V_20 ) ;
V_14 -> V_46 = V_46 ;
V_14 -> V_47 = 1 ;
}
void * F_22 ( const char * V_48 , unsigned long * V_49 )
{
struct V_50 V_51 ;
void * V_52 ;
int V_53 ;
V_53 = F_23 ( V_48 , V_54 ) ;
if ( V_53 < 0 || F_24 ( V_53 , & V_51 ) != 0 )
return NULL ;
* V_49 = V_51 . V_55 ;
V_52 = F_25 ( NULL , * V_49 , V_56 | V_57 , V_58 , V_53 , 0 ) ;
F_26 ( V_53 ) ;
if ( V_52 == V_59 )
return NULL ;
return V_52 ;
}
char * F_27 ( unsigned long * V_60 , void * V_61 , unsigned long V_49 )
{
static char line [ 4096 ] ;
int V_62 = 1 ;
T_2 V_63 = 0 ;
signed char * V_13 = ( signed char * ) V_61 + * V_60 ;
char * V_14 = line ;
for (; * V_60 < V_49 ; ( * V_60 ) ++ ) {
if ( V_62 && isspace ( * V_13 ) ) {
V_13 ++ ;
continue;
}
V_62 = 0 ;
if ( * V_13 != '\n' && ( * V_60 < V_49 ) ) {
V_63 ++ ;
* V_14 ++ = * V_13 ++ ;
if ( V_63 > 4095 )
break;
} else {
* V_14 = '\0' ;
return line ;
}
}
return NULL ;
}
void F_28 ( void * V_61 , unsigned long V_49 )
{
F_29 ( V_61 , V_49 ) ;
}
static int F_30 ( struct V_29 * V_64 , const char * V_48 )
{
unsigned int V_17 ;
T_3 * V_65 ;
T_4 * V_66 ;
T_5 * V_67 ;
const char * V_68 ;
unsigned int V_69 = ~ 0U , V_70 = ~ 0U ;
V_65 = F_22 ( V_48 , & V_64 -> V_49 ) ;
if ( ! V_65 ) {
perror ( V_48 ) ;
exit ( 1 ) ;
}
V_64 -> V_65 = V_65 ;
if ( V_64 -> V_49 < sizeof( * V_65 ) ) {
return 0 ;
}
if ( ( V_65 -> V_71 [ V_72 ] != V_73 ) ||
( V_65 -> V_71 [ V_74 ] != V_75 ) ||
( V_65 -> V_71 [ V_76 ] != V_77 ) ||
( V_65 -> V_71 [ V_78 ] != V_79 ) ) {
return 0 ;
}
V_65 -> V_80 = F_31 ( V_65 -> V_80 ) ;
V_65 -> V_81 = F_31 ( V_65 -> V_81 ) ;
V_65 -> V_82 = F_31 ( V_65 -> V_82 ) ;
V_65 -> V_83 = F_31 ( V_65 -> V_83 ) ;
V_65 -> V_84 = F_31 ( V_65 -> V_84 ) ;
V_65 -> V_85 = F_31 ( V_65 -> V_85 ) ;
V_65 -> V_86 = F_31 ( V_65 -> V_86 ) ;
V_65 -> V_87 = F_31 ( V_65 -> V_87 ) ;
V_65 -> V_88 = F_31 ( V_65 -> V_88 ) ;
V_65 -> V_89 = F_31 ( V_65 -> V_89 ) ;
V_65 -> V_90 = F_31 ( V_65 -> V_90 ) ;
V_65 -> V_91 = F_31 ( V_65 -> V_91 ) ;
V_65 -> V_92 = F_31 ( V_65 -> V_92 ) ;
V_66 = ( void * ) V_65 + V_65 -> V_85 ;
V_64 -> V_66 = V_66 ;
if ( V_65 -> V_85 > V_64 -> V_49 ) {
F_1 ( L_17
L_18 , ( unsigned long ) V_65 -> V_85 ,
V_48 , V_64 -> V_49 ) ;
return 0 ;
}
if ( V_65 -> V_91 == V_93 ) {
V_64 -> V_94 = F_31 ( V_66 [ 0 ] . V_95 ) ;
}
else {
V_64 -> V_94 = V_65 -> V_91 ;
}
if ( V_65 -> V_92 == V_96 ) {
V_64 -> V_97 = F_31 ( V_66 [ 0 ] . V_98 ) ;
}
else {
V_64 -> V_97 = V_65 -> V_92 ;
}
for ( V_17 = 0 ; V_17 < V_64 -> V_94 ; V_17 ++ ) {
V_66 [ V_17 ] . V_99 = F_31 ( V_66 [ V_17 ] . V_99 ) ;
V_66 [ V_17 ] . V_100 = F_31 ( V_66 [ V_17 ] . V_100 ) ;
V_66 [ V_17 ] . V_101 = F_31 ( V_66 [ V_17 ] . V_101 ) ;
V_66 [ V_17 ] . V_102 = F_31 ( V_66 [ V_17 ] . V_102 ) ;
V_66 [ V_17 ] . V_103 = F_31 ( V_66 [ V_17 ] . V_103 ) ;
V_66 [ V_17 ] . V_95 = F_31 ( V_66 [ V_17 ] . V_95 ) ;
V_66 [ V_17 ] . V_98 = F_31 ( V_66 [ V_17 ] . V_98 ) ;
V_66 [ V_17 ] . V_104 = F_31 ( V_66 [ V_17 ] . V_104 ) ;
V_66 [ V_17 ] . V_105 = F_31 ( V_66 [ V_17 ] . V_105 ) ;
V_66 [ V_17 ] . V_106 = F_31 ( V_66 [ V_17 ] . V_106 ) ;
}
V_68 = ( void * ) V_65 + V_66 [ V_64 -> V_97 ] . V_103 ;
for ( V_17 = 1 ; V_17 < V_64 -> V_94 ; V_17 ++ ) {
const char * V_32 ;
int V_107 = V_66 [ V_17 ] . V_100 == V_108 ;
if ( ! V_107 && V_66 [ V_17 ] . V_103 > V_64 -> V_49 ) {
F_1 ( L_19
L_20 , V_48 ,
( unsigned long ) V_66 [ V_17 ] . V_103 ,
sizeof( * V_65 ) ) ;
return 0 ;
}
V_32 = V_68 + V_66 [ V_17 ] . V_99 ;
if ( strcmp ( V_32 , L_21 ) == 0 ) {
if ( V_107 )
F_1 ( L_22 , V_48 ) ;
V_64 -> V_109 = ( void * ) V_65 + V_66 [ V_17 ] . V_103 ;
V_64 -> V_110 = V_66 [ V_17 ] . V_95 ;
} else if ( strcmp ( V_32 , L_23 ) == 0 )
V_64 -> V_38 = V_17 ;
else if ( strcmp ( V_32 , L_24 ) == 0 )
V_64 -> V_39 = V_17 ;
else if ( strcmp ( V_32 , L_25 ) == 0 )
V_64 -> V_40 = V_17 ;
else if ( strcmp ( V_32 , L_26 ) == 0 )
V_64 -> V_41 = V_17 ;
else if ( strcmp ( V_32 , L_27 ) == 0 )
V_64 -> V_42 = V_17 ;
if ( V_66 [ V_17 ] . V_100 == V_111 ) {
unsigned int V_112 ;
V_69 = V_17 ;
V_64 -> V_113 = ( void * ) V_65 +
V_66 [ V_17 ] . V_103 ;
V_64 -> V_114 = ( void * ) V_65 +
V_66 [ V_17 ] . V_103 + V_66 [ V_17 ] . V_95 ;
V_112 = V_66 [ V_17 ] . V_98 ;
V_64 -> V_115 = ( void * ) V_65 +
V_66 [ V_112 ] . V_103 ;
}
if ( V_66 [ V_17 ] . V_100 == V_116 ) {
V_70 = V_17 ;
V_64 -> V_117 = ( void * ) V_65 +
V_66 [ V_17 ] . V_103 ;
V_64 -> V_118 = ( void * ) V_65 +
V_66 [ V_17 ] . V_103 + V_66 [ V_17 ] . V_95 ;
}
}
if ( ! V_64 -> V_113 )
F_1 ( L_28 , V_48 ) ;
for ( V_67 = V_64 -> V_113 ; V_67 < V_64 -> V_114 ; V_67 ++ ) {
V_67 -> V_119 = F_31 ( V_67 -> V_119 ) ;
V_67 -> V_120 = F_31 ( V_67 -> V_120 ) ;
V_67 -> V_121 = F_31 ( V_67 -> V_121 ) ;
V_67 -> V_55 = F_31 ( V_67 -> V_55 ) ;
}
if ( V_70 != ~ 0U ) {
T_6 * V_13 ;
if ( V_69 != V_66 [ V_70 ] . V_98 )
F_1 ( L_29 ,
V_48 , V_66 [ V_70 ] . V_98 ,
V_69 ) ;
for ( V_13 = V_64 -> V_117 ; V_13 < V_64 -> V_118 ;
V_13 ++ )
* V_13 = F_31 ( * V_13 ) ;
}
return 1 ;
}
static void F_32 ( struct V_29 * V_64 )
{
F_28 ( V_64 -> V_65 , V_64 -> V_49 ) ;
}
static int F_33 ( struct V_29 * V_64 , const char * V_122 )
{
if ( strcmp ( V_122 , V_123 L_30 ) == 0 )
return 1 ;
if ( strcmp ( V_122 , L_31 ) == 0 )
return 1 ;
if ( V_64 -> V_65 -> V_81 == V_124 )
if ( strncmp ( V_122 , L_32 , sizeof( L_32 ) - 1 ) == 0 ||
strncmp ( V_122 , L_33 , sizeof( L_33 ) - 1 ) == 0 ||
strncmp ( V_122 , L_34 , sizeof( L_34 ) - 1 ) == 0 ||
strncmp ( V_122 , L_35 , sizeof( L_35 ) - 1 ) == 0 )
return 1 ;
if ( V_64 -> V_65 -> V_81 == V_125 )
if ( strncmp ( V_122 , L_36 , sizeof( L_36 ) - 1 ) == 0 ||
strncmp ( V_122 , L_37 , sizeof( L_37 ) - 1 ) == 0 )
return 1 ;
return 0 ;
}
static void F_34 ( struct V_8 * V_9 , struct V_29 * V_64 ,
T_5 * V_67 , const char * V_122 )
{
unsigned int V_46 ;
enum V_20 V_20 ;
if ( ! F_4 ( V_9 -> V_12 ) && strncmp ( V_122 , L_23 , 9 ) == 0 )
V_20 = F_16 ( V_64 , F_35 ( V_64 , V_67 ) ) ;
else
V_20 = F_19 ( V_64 , F_35 ( V_64 , V_67 ) ) ;
switch ( V_67 -> V_119 ) {
case V_126 :
F_2 ( L_38 , V_122 , V_9 -> V_12 ) ;
break;
case V_127 :
if ( strncmp ( V_122 , V_128 , strlen ( V_128 ) ) == 0 ) {
V_46 = ( unsigned int ) V_67 -> V_121 ;
F_21 ( V_122 + strlen ( V_128 ) , V_9 , V_46 ,
V_20 ) ;
}
break;
case V_93 :
if ( F_36 ( V_67 -> V_129 ) != V_130 &&
F_36 ( V_67 -> V_129 ) != V_131 )
break;
if ( F_33 ( V_64 , V_122 ) )
break;
#if F_37 ( V_132 ) || F_37 ( V_133 )
#ifndef V_133
#define V_133 STT_REGISTER
#endif
if ( V_64 -> V_65 -> V_81 == V_134 ||
V_64 -> V_65 -> V_81 == V_135 ) {
if ( F_38 ( V_67 -> V_129 ) == V_133 )
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
F_36 ( V_67 -> V_129 ) == V_131 ,
V_9 -> V_137 ) ;
}
break;
default:
if ( strncmp ( V_122 , V_138 , strlen ( V_138 ) ) == 0 ) {
F_20 ( V_122 + strlen ( V_138 ) , V_9 ,
V_20 ) ;
}
if ( strcmp ( V_122 , V_123 L_39 ) == 0 )
V_9 -> V_139 = 1 ;
if ( strcmp ( V_122 , V_123 L_40 ) == 0 )
V_9 -> V_140 = 1 ;
break;
}
}
static char * F_39 ( char * string , unsigned long * V_141 )
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
static char * F_40 ( void * V_109 , unsigned long V_110 ,
const char * V_142 , char * V_64 )
{
char * V_13 ;
unsigned int V_143 = strlen ( V_142 ) ;
unsigned long V_49 = V_110 ;
if ( V_64 ) {
V_49 -= V_64 - ( char * ) V_109 ;
V_109 = F_39 ( V_64 , & V_49 ) ;
}
for ( V_13 = V_109 ; V_13 ; V_13 = F_39 ( V_13 , & V_49 ) ) {
if ( strncmp ( V_13 , V_142 , V_143 ) == 0 && V_13 [ V_143 ] == '=' )
return V_13 + V_143 + 1 ;
}
return NULL ;
}
static char * F_41 ( void * V_109 , unsigned long V_110 ,
const char * V_142 )
{
return F_40 ( V_109 , V_110 , V_142 , NULL ) ;
}
static int F_42 ( const char * V_14 , const char * V_144 )
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
static const char * F_43 ( struct V_29 * V_30 , T_5 * V_67 )
{
if ( V_67 )
return V_30 -> V_115 + V_67 -> V_120 ;
else
return L_41 ;
}
static const char * F_17 ( struct V_29 * V_30 , int V_147 )
{
T_4 * V_66 = V_30 -> V_66 ;
return ( void * ) V_30 -> V_65 +
V_30 -> V_66 [ V_30 -> V_97 ] . V_103 +
V_66 [ V_147 ] . V_99 ;
}
static const char * F_44 ( struct V_29 * V_30 , T_4 * V_148 )
{
return ( void * ) V_30 -> V_65 +
V_30 -> V_66 [ V_30 -> V_97 ] . V_103 +
V_148 -> V_99 ;
}
static int F_45 ( const char * V_67 )
{
if ( * V_67 ++ == '\0' )
return 1 ;
if ( * V_67 != '.' )
return 0 ;
do {
char V_149 = * V_67 ++ ;
if ( V_149 < '0' || V_149 > '9' )
return 0 ;
} while ( * V_67 );
return 1 ;
}
static int F_46 ( const char * V_67 , const char * const V_150 [] )
{
const char * V_13 ;
while ( * V_150 ) {
V_13 = * V_150 ++ ;
const char * V_151 = V_13 + strlen ( V_13 ) - 1 ;
if ( * V_13 == '*' ) {
if ( F_42 ( V_67 , V_13 + 1 ) == 0 )
return 1 ;
}
else if ( * V_151 == '*' ) {
if ( strncmp ( V_67 , V_13 , strlen ( V_13 ) - 1 ) == 0 )
return 1 ;
}
else if ( * V_151 == '$' ) {
if ( strncmp ( V_67 , V_13 , strlen ( V_13 ) - 1 ) == 0 ) {
if ( F_45 ( V_67 + strlen ( V_13 ) - 1 ) )
return 1 ;
}
}
else {
if ( strcmp ( V_13 , V_67 ) == 0 )
return 1 ;
}
}
return 0 ;
}
static void F_47 ( const char * V_4 , struct V_29 * V_30 ,
T_4 * V_148 )
{
const char * V_31 = F_44 ( V_30 , V_148 ) ;
if ( V_148 -> V_100 == V_152 &&
! ( V_148 -> V_101 & V_153 ) &&
! F_46 ( V_31 , V_154 ) ) {
F_2 ( L_42
L_43
L_44
L_45 ,
V_4 , V_31 ) ;
}
}
static const struct V_155 * F_48 (
const char * V_156 , const char * V_157 )
{
int V_17 ;
int V_158 = sizeof( V_155 ) / sizeof( struct V_155 ) ;
const struct V_155 * V_159 = & V_155 [ 0 ] ;
for ( V_17 = 0 ; V_17 < V_158 ; V_17 ++ ) {
if ( F_46 ( V_156 , V_159 -> V_156 ) &&
F_46 ( V_157 , V_159 -> V_157 ) )
return V_159 ;
V_159 ++ ;
}
return NULL ;
}
static int F_49 ( const struct V_155 * V_160 ,
const char * V_156 , const char * V_161 ,
const char * V_157 , const char * V_162 )
{
if ( F_46 ( V_157 , V_163 ) &&
F_46 ( V_156 , V_164 ) &&
( strncmp ( V_161 , L_46 , strlen ( L_46 ) ) == 0 ) )
return 0 ;
if ( strcmp ( V_157 , L_47 ) == 0 &&
F_46 ( V_156 , V_164 ) &&
( strncmp ( V_161 , L_48 , strlen ( L_48 ) ) == 0 ) )
return 0 ;
if ( F_46 ( V_157 , V_165 ) &&
F_46 ( V_156 , V_164 ) &&
F_46 ( V_161 , V_160 -> V_166 ) )
return 0 ;
if ( F_46 ( V_156 , V_167 ) &&
F_46 ( V_157 , V_168 ) )
return 0 ;
if ( F_46 ( V_162 , V_169 ) )
return 0 ;
return 1 ;
}
static T_5 * F_50 ( struct V_29 * V_30 , T_7 V_170 ,
T_5 * V_171 )
{
T_5 * V_67 ;
T_5 * V_172 = NULL ;
T_7 V_173 = 20 ;
T_7 V_174 ;
unsigned int V_175 ;
if ( V_171 -> V_120 != 0 )
return V_171 ;
V_175 = F_35 ( V_30 , V_171 ) ;
for ( V_67 = V_30 -> V_113 ; V_67 < V_30 -> V_114 ; V_67 ++ ) {
if ( F_35 ( V_30 , V_67 ) != V_175 )
continue;
if ( F_38 ( V_67 -> V_129 ) == V_176 )
continue;
if ( V_67 -> V_121 == V_170 )
return V_67 ;
V_174 = V_67 -> V_121 - V_170 ;
if ( V_174 < 0 )
V_174 = V_170 - V_67 -> V_121 ;
if ( V_174 < V_173 ) {
V_173 = V_174 ;
V_172 = V_67 ;
}
}
if ( V_173 < 20 )
return V_172 ;
else
return NULL ;
}
static inline int F_51 ( const char * V_27 )
{
return V_27 [ 0 ] == '$' && strchr ( L_49 , V_27 [ 1 ] )
&& ( V_27 [ 2 ] == '\0' || V_27 [ 2 ] == '.' ) ;
}
static inline int F_52 ( struct V_29 * V_30 , T_5 * V_67 )
{
const char * V_12 = V_30 -> V_115 + V_67 -> V_120 ;
if ( ! V_12 || ! strlen ( V_12 ) )
return 0 ;
return ! F_51 ( V_12 ) ;
}
static T_5 * F_53 ( struct V_29 * V_30 , T_8 V_170 ,
const char * V_31 )
{
T_5 * V_67 ;
T_5 * V_172 = NULL ;
T_8 V_173 = ~ 0 ;
for ( V_67 = V_30 -> V_113 ; V_67 < V_30 -> V_114 ; V_67 ++ ) {
const char * V_177 ;
if ( F_54 ( V_67 -> V_119 ) )
continue;
V_177 = F_17 ( V_30 , F_35 ( V_30 , V_67 ) ) ;
if ( strcmp ( V_177 , V_31 ) != 0 )
continue;
if ( ! F_52 ( V_30 , V_67 ) )
continue;
if ( V_67 -> V_121 <= V_170 ) {
if ( ( V_170 - V_67 -> V_121 ) < V_173 ) {
V_173 = V_170 - V_67 -> V_121 ;
V_172 = V_67 ;
} else if ( ( V_170 - V_67 -> V_121 ) == V_173 ) {
V_172 = V_67 ;
}
}
}
return V_172 ;
}
static char * F_55 ( const char * V_14 )
{
if ( F_46 ( V_14 , V_165 ) ) {
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
if ( strstr ( V_14 , L_50 ) != NULL )
strcat ( V_13 , L_51 ) ;
else if ( strstr ( V_14 , L_52 ) != NULL )
strcat ( V_13 , L_53 ) ;
else
strcat ( V_13 , L_54 ) ;
return V_178 ;
} else {
return F_9 ( L_15 ) ;
}
}
static int F_56 ( T_5 * V_67 )
{
if ( V_67 )
return F_38 ( V_67 -> V_129 ) == V_179 ;
else
return - 1 ;
}
static void F_57 ( const char * const V_180 [ 20 ] )
{
const char * const * V_14 = V_180 ;
while ( * V_14 ) {
fprintf ( V_3 , L_55 , * V_14 ) ;
V_14 ++ ;
if ( * V_14 )
fprintf ( V_3 , L_56 ) ;
}
fprintf ( V_3 , L_57 ) ;
}
static void F_58 ( const char * V_4 ,
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
case 0 : V_184 = L_58 ; V_185 = L_15 ; break;
case 1 : V_184 = L_59 ; V_185 = L_60 ; break;
default: V_184 = L_61 ; V_185 = L_15 ; break;
}
switch ( V_183 ) {
case 0 : V_186 = L_58 ; V_187 = L_15 ; break;
case 1 : V_186 = L_59 ; V_187 = L_60 ; break;
default: V_186 = L_61 ; V_187 = L_15 ; break;
}
V_190 ++ ;
if ( ! V_191 )
return;
F_2 ( L_62
L_63 ,
V_4 , V_156 , V_181 , V_184 , V_161 , V_185 , V_186 , V_157 ,
V_162 , V_187 ) ;
switch ( V_160 -> V_160 ) {
case V_192 :
V_188 = F_55 ( V_156 ) ;
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_64
L_65
L_66
L_67 ,
V_188 , V_161 ,
V_186 , V_189 , V_162 , V_187 ,
V_161 , V_189 , V_162 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_193 : {
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_68
L_69
L_70
L_71
L_72 ,
V_161 , V_186 , V_189 , V_162 , V_187 ) ;
F_57 ( V_160 -> V_166 ) ;
free ( V_189 ) ;
break;
}
case V_194 :
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_73
L_74
L_75 ,
V_161 , V_186 , V_186 , V_162 , V_187 , V_189 , V_162 ) ;
free ( V_189 ) ;
break;
case V_195 : {
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_68
L_69
L_70
L_76
L_77 ,
V_161 , V_186 , V_189 , V_162 , V_187 ) ;
F_57 ( V_160 -> V_166 ) ;
free ( V_189 ) ;
break;
}
case V_196 :
case V_197 :
V_188 = F_55 ( V_156 ) ;
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_78
L_79
L_80
L_81 ,
V_184 , V_188 , V_161 , V_185 ,
V_186 , V_189 , V_162 , V_187 ,
V_162 , V_161 , V_162 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_198 :
V_188 = F_55 ( V_156 ) ;
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_78
L_79
L_82
L_83
L_84
L_85
L_86 ,
V_184 , V_188 , V_161 , V_185 ,
V_186 , V_189 , V_162 , V_187 ,
V_189 , V_162 , V_187 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_199 :
V_188 = F_55 ( V_156 ) ;
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_78
L_79
L_82
L_87
L_88
L_85
L_89 ,
V_184 , V_188 , V_161 , V_185 ,
V_186 , V_189 , V_162 , V_187 ,
V_189 , V_162 , V_187 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
break;
case V_200 :
V_189 = F_55 ( V_157 ) ;
fprintf ( V_3 ,
L_90
L_91
L_92 ,
V_162 , V_189 , V_189 , V_162 ) ;
free ( V_189 ) ;
break;
}
fprintf ( V_3 , L_57 ) ;
}
static void F_59 ( const char * V_4 , struct V_29 * V_30 ,
T_9 * V_178 , T_5 * V_67 , const char * V_156 )
{
const char * V_157 ;
const struct V_155 * V_160 ;
V_157 = F_17 ( V_30 , F_35 ( V_30 , V_67 ) ) ;
V_160 = F_48 ( V_156 , V_157 ) ;
if ( V_160 ) {
T_5 * V_186 ;
T_5 * V_184 ;
const char * V_162 ;
const char * V_161 ;
V_184 = F_53 ( V_30 , V_178 -> V_201 , V_156 ) ;
V_161 = F_43 ( V_30 , V_184 ) ;
V_186 = F_50 ( V_30 , V_178 -> V_202 , V_67 ) ;
V_162 = F_43 ( V_30 , V_186 ) ;
if ( F_49 ( V_160 ,
V_156 , V_161 , V_157 , V_162 ) ) {
F_58 ( V_4 , V_160 ,
V_156 , V_178 -> V_201 , V_161 ,
F_56 ( V_184 ) , V_157 , V_162 ,
F_56 ( V_186 ) ) ;
}
}
}
static unsigned int * F_60 ( struct V_29 * V_30 ,
T_4 * V_148 , T_9 * V_178 )
{
T_4 * V_66 = V_30 -> V_66 ;
int V_203 = V_148 -> V_104 ;
return ( void * ) V_30 -> V_65 + V_66 [ V_203 ] . V_103 +
V_178 -> V_201 ;
}
static int F_61 ( struct V_29 * V_30 , T_4 * V_148 , T_9 * V_178 )
{
unsigned int V_204 = F_62 ( V_178 -> V_205 ) ;
unsigned int * V_206 = F_60 ( V_30 , V_148 , V_178 ) ;
switch ( V_204 ) {
case V_207 :
V_178 -> V_202 = F_31 ( * V_206 ) ;
break;
case V_208 :
V_178 -> V_202 = F_31 ( * V_206 ) + 4 ;
if ( V_30 -> V_65 -> V_80 == V_209 )
V_178 -> V_202 += V_178 -> V_201 ;
break;
}
return 0 ;
}
static int F_63 ( struct V_29 * V_30 , T_4 * V_148 , T_9 * V_178 )
{
unsigned int V_204 = F_62 ( V_178 -> V_205 ) ;
switch ( V_204 ) {
case V_210 :
V_178 -> V_202 = ( int ) ( long )
( V_30 -> V_113 + F_64 ( V_178 -> V_205 ) ) ;
break;
case V_211 :
V_178 -> V_202 = ( int ) ( long ) ( V_30 -> V_65 +
V_148 -> V_103 +
( V_178 -> V_201 - V_148 -> V_102 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_65 ( struct V_29 * V_30 , T_4 * V_148 , T_9 * V_178 )
{
unsigned int V_204 = F_62 ( V_178 -> V_205 ) ;
unsigned int * V_206 = F_60 ( V_30 , V_148 , V_178 ) ;
unsigned int V_212 ;
if ( V_204 == V_213 )
return 1 ;
V_212 = F_31 ( * V_206 ) ;
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
static void F_66 ( const char * V_4 , struct V_29 * V_30 ,
T_4 * V_148 )
{
T_5 * V_67 ;
T_9 * V_217 ;
T_9 V_178 ;
unsigned int V_218 ;
const char * V_156 ;
T_9 * V_219 = ( void * ) V_30 -> V_65 + V_148 -> V_103 ;
T_9 * V_220 = ( void * ) V_219 + V_148 -> V_95 ;
V_156 = F_44 ( V_30 , V_148 ) ;
V_156 += strlen ( L_93 ) ;
if ( F_46 ( V_156 , V_154 ) )
return;
for ( V_217 = V_219 ; V_217 < V_220 ; V_217 ++ ) {
V_178 . V_201 = F_31 ( V_217 -> V_201 ) ;
#if V_221 == V_222
if ( V_30 -> V_65 -> V_81 == V_223 ) {
unsigned int V_204 ;
V_218 = F_67 ( V_217 -> V_205 ) ;
V_218 = F_31 ( V_218 ) ;
V_204 = F_68 ( V_217 -> V_205 ) ;
V_178 . V_205 = F_69 ( V_218 , V_204 ) ;
} else {
V_178 . V_205 = F_31 ( V_217 -> V_205 ) ;
V_218 = F_64 ( V_178 . V_205 ) ;
}
#else
V_178 . V_205 = F_31 ( V_217 -> V_205 ) ;
V_218 = F_64 ( V_178 . V_205 ) ;
#endif
V_178 . V_202 = F_31 ( V_217 -> V_202 ) ;
V_67 = V_30 -> V_113 + V_218 ;
if ( F_54 ( V_67 -> V_119 ) )
continue;
F_59 ( V_4 , V_30 , & V_178 , V_67 , V_156 ) ;
}
}
static void F_70 ( const char * V_4 , struct V_29 * V_30 ,
T_4 * V_148 )
{
T_5 * V_67 ;
T_10 * V_224 ;
T_9 V_178 ;
unsigned int V_218 ;
const char * V_156 ;
T_10 * V_219 = ( void * ) V_30 -> V_65 + V_148 -> V_103 ;
T_10 * V_220 = ( void * ) V_219 + V_148 -> V_95 ;
V_156 = F_44 ( V_30 , V_148 ) ;
V_156 += strlen ( L_94 ) ;
if ( F_46 ( V_156 , V_154 ) )
return;
for ( V_224 = V_219 ; V_224 < V_220 ; V_224 ++ ) {
V_178 . V_201 = F_31 ( V_224 -> V_201 ) ;
#if V_221 == V_222
if ( V_30 -> V_65 -> V_81 == V_223 ) {
unsigned int V_204 ;
V_218 = F_67 ( V_224 -> V_205 ) ;
V_218 = F_31 ( V_218 ) ;
V_204 = F_68 ( V_224 -> V_205 ) ;
V_178 . V_205 = F_69 ( V_218 , V_204 ) ;
} else {
V_178 . V_205 = F_31 ( V_224 -> V_205 ) ;
V_218 = F_64 ( V_178 . V_205 ) ;
}
#else
V_178 . V_205 = F_31 ( V_224 -> V_205 ) ;
V_218 = F_64 ( V_178 . V_205 ) ;
#endif
V_178 . V_202 = 0 ;
switch ( V_30 -> V_65 -> V_81 ) {
case V_225 :
if ( F_61 ( V_30 , V_148 , & V_178 ) )
continue;
break;
case V_226 :
if ( F_63 ( V_30 , V_148 , & V_178 ) )
continue;
break;
case V_223 :
if ( F_65 ( V_30 , V_148 , & V_178 ) )
continue;
break;
}
V_67 = V_30 -> V_113 + V_218 ;
if ( F_54 ( V_67 -> V_119 ) )
continue;
F_59 ( V_4 , V_30 , & V_178 , V_67 , V_156 ) ;
}
}
static void F_71 ( struct V_8 * V_9 , const char * V_4 ,
struct V_29 * V_30 )
{
int V_17 ;
T_4 * V_66 = V_30 -> V_66 ;
for ( V_17 = 0 ; V_17 < V_30 -> V_94 ; V_17 ++ ) {
F_47 ( V_4 , V_30 , & V_30 -> V_66 [ V_17 ] ) ;
if ( V_66 [ V_17 ] . V_100 == V_227 )
F_66 ( V_4 , V_30 , & V_30 -> V_66 [ V_17 ] ) ;
else if ( V_66 [ V_17 ] . V_100 == V_228 )
F_70 ( V_4 , V_30 , & V_30 -> V_66 [ V_17 ] ) ;
}
}
static void F_72 ( char * V_4 )
{
const char * V_122 ;
char * V_229 ;
char * V_230 ;
struct V_8 * V_9 ;
struct V_29 V_64 = { } ;
T_5 * V_67 ;
if ( ! F_30 ( & V_64 , V_4 ) )
return;
V_9 = F_7 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
V_231 = 1 ;
V_9 -> V_62 = 1 ;
}
V_230 = F_41 ( V_64 . V_109 , V_64 . V_110 , L_95 ) ;
if ( V_64 . V_109 && ! V_230 && ! F_4 ( V_4 ) )
F_2 ( L_96
L_97
L_98 , V_4 ) ;
while ( V_230 ) {
if ( F_73 ( V_230 ) )
V_9 -> V_15 = 1 ;
else {
V_9 -> V_15 = 0 ;
break;
}
V_230 = F_40 ( V_64 . V_109 , V_64 . V_110 ,
L_95 , V_230 ) ;
}
for ( V_67 = V_64 . V_113 ; V_67 < V_64 . V_114 ; V_67 ++ ) {
V_122 = V_64 . V_115 + V_67 -> V_120 ;
F_34 ( V_9 , & V_64 , V_67 , V_122 ) ;
F_74 ( V_9 , & V_64 , V_67 , V_122 ) ;
}
if ( ! F_4 ( V_4 ) ||
( F_4 ( V_4 ) && V_232 ) )
F_71 ( V_9 , V_4 , & V_64 ) ;
V_229 = F_41 ( V_64 . V_109 , V_64 . V_110 , L_99 ) ;
if ( V_229 )
F_75 ( V_4 , V_229 , V_64 . V_109 ,
V_229 - ( char * ) V_64 . V_65 ) ;
if ( V_229 || ( V_233 && ! F_4 ( V_4 ) ) )
F_76 ( V_4 , V_9 -> V_234 ,
sizeof( V_9 -> V_234 ) - 1 ) ;
F_32 ( & V_64 ) ;
if ( V_235 )
V_9 -> V_137 = F_11 ( L_100 , 0 , V_9 -> V_137 ) ;
}
void F_77 ( struct V_236 * V_237 , const char * V_14 , int V_63 )
{
if ( V_237 -> V_49 - V_237 -> V_60 < V_63 ) {
V_237 -> V_49 += V_63 + V_238 ;
V_237 -> V_13 = realloc ( V_237 -> V_13 , V_237 -> V_49 ) ;
}
strncpy ( V_237 -> V_13 + V_237 -> V_60 , V_14 , V_63 ) ;
V_237 -> V_60 += V_63 ;
}
static void F_78 ( enum V_20 exp , const char * V_239 , const char * V_14 )
{
const char * V_240 = F_4 ( V_239 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_35 :
F_1 ( L_101
L_102 , V_239 , V_240 , V_14 ) ;
break;
case V_36 :
F_1 ( L_101
L_103 , V_239 , V_240 , V_14 ) ;
break;
case V_37 :
F_2 ( L_101
L_104 , V_239 , V_240 , V_14 ) ;
break;
case V_33 :
case V_34 :
case V_28 :
break;
}
}
static void F_79 ( enum V_20 exp , const char * V_239 , const char * V_14 )
{
const char * V_240 = F_4 ( V_239 ) ? L_15 : L_16 ;
switch ( exp ) {
case V_34 :
case V_36 :
F_2 ( L_105
L_106 , V_239 , V_240 , V_14 ) ;
break;
default:
break;
}
}
static void F_80 ( struct V_8 * V_9 )
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
F_78 ( exp -> V_20 , V_241 , exp -> V_12 ) ;
F_79 ( exp -> V_20 , V_241 , exp -> V_12 ) ;
}
}
static void F_81 ( struct V_236 * V_242 , struct V_8 * V_9 )
{
F_82 ( V_242 , L_107 ) ;
F_82 ( V_242 , L_108 ) ;
F_82 ( V_242 , L_109 ) ;
F_82 ( V_242 , L_57 ) ;
F_82 ( V_242 , L_110 ) ;
F_82 ( V_242 , L_57 ) ;
F_82 ( V_242 , L_111 ) ;
F_82 ( V_242 , L_112 ) ;
F_82 ( V_242 , L_113 ) ;
if ( V_9 -> V_139 )
F_82 ( V_242 , L_114 ) ;
if ( V_9 -> V_140 )
F_82 ( V_242 , L_115
L_116
L_117 ) ;
F_82 ( V_242 , L_118 ) ;
F_82 ( V_242 , L_119 ) ;
}
static void F_83 ( struct V_236 * V_242 , const char * V_12 )
{
static const char * V_243 = L_120 ;
if ( strncmp ( V_243 , V_12 , strlen ( V_243 ) ) == 0 )
F_82 ( V_242 , L_121 ) ;
}
static int F_84 ( struct V_236 * V_242 , struct V_8 * V_9 )
{
struct V_18 * V_14 , * exp ;
int V_244 = 0 ;
for ( V_14 = V_9 -> V_137 ; V_14 ; V_14 = V_14 -> V_11 ) {
exp = F_13 ( V_14 -> V_12 ) ;
if ( ! exp || exp -> V_8 == V_9 ) {
if ( V_231 && ! V_14 -> V_19 ) {
if ( V_245 ) {
F_2 ( L_122 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
} else {
F_3 ( L_122 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
V_244 = 1 ;
}
}
continue;
}
V_14 -> V_8 = exp -> V_8 ;
V_14 -> V_47 = exp -> V_47 ;
V_14 -> V_46 = exp -> V_46 ;
}
if ( ! V_235 )
return V_244 ;
F_82 ( V_242 , L_57 ) ;
F_82 ( V_242 , L_123 ) ;
F_82 ( V_242 , L_124 ) ;
F_82 ( V_242 , L_125 ) ;
for ( V_14 = V_9 -> V_137 ; V_14 ; V_14 = V_14 -> V_11 ) {
if ( ! V_14 -> V_8 )
continue;
if ( ! V_14 -> V_47 ) {
F_2 ( L_126 ,
V_14 -> V_12 , V_9 -> V_12 ) ;
continue;
}
F_82 ( V_242 , L_127 , V_14 -> V_46 , V_14 -> V_12 ) ;
}
F_82 ( V_242 , L_119 ) ;
return V_244 ;
}
static void F_85 ( struct V_236 * V_242 , struct V_8 * V_9 ,
struct V_8 * V_10 )
{
struct V_18 * V_14 ;
struct V_8 * V_239 ;
int V_246 = 1 ;
for ( V_239 = V_10 ; V_239 ; V_239 = V_239 -> V_11 )
V_239 -> V_247 = F_4 ( V_239 -> V_12 ) ;
F_82 ( V_242 , L_57 ) ;
F_82 ( V_242 , L_128 ) ;
F_82 ( V_242 , L_124 ) ;
F_82 ( V_242 , L_129 ) ;
F_82 ( V_242 , L_130 ) ;
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
F_82 ( V_242 , L_131 , V_246 ? L_15 : L_132 , V_13 ) ;
V_246 = 0 ;
}
F_82 ( V_242 , L_133 ) ;
}
static void F_86 ( struct V_236 * V_242 , struct V_8 * V_9 )
{
if ( V_9 -> V_234 [ 0 ] ) {
F_82 ( V_242 , L_57 ) ;
F_82 ( V_242 , L_134 ,
V_9 -> V_234 ) ;
}
}
static void F_87 ( struct V_236 * V_242 , const char * V_248 )
{
char * V_249 ;
T_11 * V_61 ;
struct V_50 V_51 ;
V_61 = fopen ( V_248 , L_135 ) ;
if ( ! V_61 )
goto V_250;
if ( F_24 ( fileno ( V_61 ) , & V_51 ) < 0 )
goto V_251;
if ( V_51 . V_55 != V_242 -> V_60 )
goto V_251;
V_249 = F_8 ( malloc ( V_242 -> V_60 ) ) ;
if ( fread ( V_249 , 1 , V_242 -> V_60 , V_61 ) != V_242 -> V_60 )
goto V_252;
if ( memcmp ( V_249 , V_242 -> V_13 , V_242 -> V_60 ) != 0 )
goto V_252;
free ( V_249 ) ;
fclose ( V_61 ) ;
return;
V_252:
free ( V_249 ) ;
V_251:
fclose ( V_61 ) ;
V_250:
V_61 = fopen ( V_248 , L_136 ) ;
if ( ! V_61 ) {
perror ( V_248 ) ;
exit ( 1 ) ;
}
if ( fwrite ( V_242 -> V_13 , 1 , V_242 -> V_60 , V_61 ) != V_242 -> V_60 ) {
perror ( V_248 ) ;
exit ( 1 ) ;
}
fclose ( V_61 ) ;
}
static void F_88 ( const char * V_248 , unsigned int V_45 )
{
unsigned long V_49 , V_60 = 0 ;
void * V_61 = F_22 ( V_248 , & V_49 ) ;
char * line ;
if ( ! V_61 )
return;
while ( ( line = F_27 ( & V_60 , V_61 , V_49 ) ) ) {
char * V_122 , * V_4 , * V_174 , * V_20 , * V_253 ;
unsigned int V_46 ;
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
V_46 = strtoul ( line , & V_174 , 16 ) ;
if ( * V_122 == '\0' || * V_4 == '\0' || * V_174 != '\0' )
goto V_254;
V_9 = F_6 ( V_4 ) ;
if ( ! V_9 ) {
if ( F_4 ( V_4 ) )
V_231 = 1 ;
V_9 = F_7 ( V_4 ) ;
V_9 -> V_62 = 1 ;
}
V_14 = F_20 ( V_122 , V_9 , F_15 ( V_20 ) ) ;
V_14 -> V_45 = V_45 ;
V_14 -> V_43 = 1 ;
F_21 ( V_122 , V_9 , V_46 , F_15 ( V_20 ) ) ;
}
return;
V_254:
F_1 ( L_137 ) ;
}
static int F_89 ( struct V_18 * V_67 )
{
if ( ! V_255 )
return 1 ;
if ( V_67 -> V_44 || V_67 -> V_45 )
return 0 ;
return 1 ;
}
static void F_90 ( const char * V_248 )
{
struct V_236 V_237 = { } ;
struct V_18 * V_18 ;
int V_256 ;
for ( V_256 = 0 ; V_256 < V_23 ; V_256 ++ ) {
V_18 = V_24 [ V_256 ] ;
while ( V_18 ) {
if ( F_89 ( V_18 ) )
F_82 ( & V_237 , L_138 ,
V_18 -> V_46 , V_18 -> V_12 ,
V_18 -> V_8 -> V_12 ,
F_14 ( V_18 -> V_20 ) ) ;
V_18 = V_18 -> V_11 ;
}
}
F_87 ( & V_237 , V_248 ) ;
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
while ( ( V_262 = F_91 ( V_257 , V_258 , L_139 ) ) != - 1 ) {
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
V_264 -> V_61 = V_266 ;
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
F_88 ( V_259 , 1 ) ;
if ( V_260 )
F_88 ( V_260 , 0 ) ;
while ( V_265 ) {
F_88 ( V_265 -> V_61 , 0 ) ;
V_264 = V_265 -> V_11 ;
free ( V_265 ) ;
V_265 = V_264 ;
}
while ( V_268 < V_257 )
F_72 ( V_258 [ V_268 ++ ] ) ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
if ( V_9 -> V_62 )
continue;
F_80 ( V_9 ) ;
}
V_244 = 0 ;
for ( V_9 = V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
char V_248 [ strlen ( V_9 -> V_12 ) + 10 ] ;
if ( V_9 -> V_62 )
continue;
V_237 . V_60 = 0 ;
F_81 ( & V_237 , V_9 ) ;
F_83 ( & V_237 , V_9 -> V_12 ) ;
V_244 |= F_84 ( & V_237 , V_9 ) ;
F_85 ( & V_237 , V_9 , V_10 ) ;
F_92 ( & V_237 , V_9 ) ;
F_86 ( & V_237 , V_9 ) ;
sprintf ( V_248 , L_140 , V_9 -> V_12 ) ;
F_87 ( & V_237 , V_248 ) ;
}
if ( V_261 )
F_90 ( V_261 ) ;
if ( V_190 && ! V_191 )
F_2 ( L_141
L_142
L_143 ,
V_190 ) ;
return V_244 ;
}
