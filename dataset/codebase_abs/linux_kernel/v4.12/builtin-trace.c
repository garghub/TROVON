static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
bool V_4 )
{
V_2 -> V_5 = V_3 -> V_5 ;
switch ( V_3 -> V_6 ) {
case 1 :
V_2 -> integer = V_7 ;
break;
case 2 :
V_2 -> integer = V_4 ? V_8 : V_9 ;
break;
case 4 :
V_2 -> integer = V_4 ? V_10 : V_11 ;
break;
case 8 :
V_2 -> integer = V_4 ? V_12 : V_13 ;
break;
default:
return - 1 ;
}
return 0 ;
}
static void * F_2 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return V_15 -> V_16 + V_2 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
V_2 -> V_5 = V_3 -> V_5 ;
V_2 -> V_17 = F_2 ;
return 0 ;
}
static int F_4 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
const char * V_20 )
{
struct V_3 * V_3 = F_5 ( V_19 , V_20 ) ;
if ( V_3 == NULL )
return - 1 ;
return F_1 ( V_2 , V_3 , V_19 -> V_4 ) ;
}
static int F_6 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
const char * V_20 )
{
struct V_3 * V_3 = F_5 ( V_19 , V_20 ) ;
if ( V_3 == NULL )
return - 1 ;
return F_3 ( V_2 , V_3 ) ;
}
static void F_7 ( struct V_18 * V_19 )
{
F_8 ( & V_19 -> V_21 ) ;
F_9 ( V_19 ) ;
}
static int F_10 ( struct V_18 * V_19 , void * V_22 )
{
V_19 -> V_21 = malloc ( sizeof( struct V_23 ) ) ;
if ( V_19 -> V_21 != NULL ) {
if ( F_11 ( V_19 , V_24 ) )
goto V_25;
V_19 -> V_22 = V_22 ;
return 0 ;
}
return - V_26 ;
V_25:
F_8 ( & V_19 -> V_21 ) ;
return - V_27 ;
}
static struct V_18 * F_12 ( const char * V_28 , void * V_22 )
{
struct V_18 * V_19 = F_13 ( L_1 , V_28 ) ;
if ( F_14 ( V_19 ) )
V_19 = F_13 ( L_2 , V_28 ) ;
if ( F_14 ( V_19 ) )
return NULL ;
if ( F_10 ( V_19 , V_22 ) )
goto V_25;
return V_19 ;
V_25:
F_7 ( V_19 ) ;
return NULL ;
}
static T_1 F_15 ( char * V_29 , T_1 V_6 ,
const char * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
int V_36 = V_32 -> V_37 - V_34 -> V_5 ;
if ( V_36 < 0 || V_36 >= V_34 -> V_38 )
return F_16 ( V_29 , V_6 , V_30 , V_32 -> V_37 ) ;
return F_16 ( V_29 , V_6 , L_3 , V_34 -> V_39 [ V_36 ] ) ;
}
static T_1 F_17 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_15 ( V_29 , V_6 , L_4 , V_32 ) ;
}
static T_1 F_18 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_15 ( V_29 , V_6 , L_5 , V_32 ) ;
}
static T_1 F_19 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
if ( V_40 == V_41 )
return F_16 ( V_29 , V_6 , L_6 ) ;
return F_20 ( V_29 , V_6 , V_32 ) ;
}
static T_1 F_21 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_16 ( V_29 , V_6 , L_7 , V_32 -> V_37 ) ;
}
static T_1 F_22 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_16 ( V_29 , V_6 , L_4 , V_32 -> V_37 ) ;
}
static T_1 F_23 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
T_1 V_42 = 0 ;
int V_43 = V_32 -> V_37 ;
if ( V_43 == V_44 )
return F_16 ( V_29 , V_6 , L_8 ) ;
#define F_24 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_24 ( V_45 ) ;
F_24 ( V_46 ) ;
F_24 ( V_47 ) ;
#undef F_24
if ( V_43 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_43 ) ;
return V_42 ;
}
static T_1 F_25 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_48 = V_32 -> V_37 ;
#define F_26 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_26 ( V_49 ) ;
F_26 ( V_50 ) ;
#undef F_26
if ( V_48 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_10 , V_42 ? L_11 : L_12 , V_48 ) ;
return V_42 ;
}
static T_1 F_27 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_48 = V_32 -> V_37 ;
#define F_26 ( T_2 ) \
if (flags & GRND_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~GRND_##n; \
}
F_26 ( V_51 ) ;
F_26 ( V_50 ) ;
#undef F_26
if ( V_48 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_10 , V_42 ? L_11 : L_12 , V_48 ) ;
return V_42 ;
}
static int F_28 ( const void * V_20 , const void * V_52 )
{
const struct V_53 * V_54 = V_52 ;
return strcmp ( V_20 , V_54 -> V_20 ) ;
}
static struct V_53 * F_29 ( const char * V_20 )
{
const int V_55 = F_30 ( V_56 ) ;
return bsearch ( V_20 , V_56 , V_55 , sizeof( struct V_53 ) , F_28 ) ;
}
static T_1 F_31 ( unsigned long V_57 , bool V_58 , T_3 * V_59 )
{
double V_60 = ( double ) V_57 / V_61 ;
T_1 V_42 = fprintf ( V_59 , L_13 ) ;
if ( ! V_58 )
V_42 += fprintf ( V_59 , L_14 ) ;
else if ( V_60 >= 1.0 )
V_42 += F_32 ( V_59 , V_62 , L_15 , V_60 ) ;
else if ( V_60 >= 0.01 )
V_42 += F_32 ( V_59 , V_63 , L_15 , V_60 ) ;
else
V_42 += F_32 ( V_59 , V_64 , L_15 , V_60 ) ;
return V_42 + fprintf ( V_59 , L_16 ) ;
}
static struct V_65 * F_33 ( void )
{
struct V_65 * V_66 = F_34 ( sizeof( struct V_65 ) ) ;
if ( V_66 )
V_66 -> V_67 . V_68 = - 1 ;
V_66 -> V_69 = F_35 ( NULL ) ;
return V_66 ;
}
static struct V_65 * F_36 ( struct V_70 * V_70 , T_3 * V_59 )
{
struct V_65 * V_66 ;
if ( V_70 == NULL )
goto V_71;
if ( F_37 ( V_70 ) == NULL )
F_38 ( V_70 , F_33 () ) ;
if ( F_37 ( V_70 ) == NULL )
goto V_71;
V_66 = F_37 ( V_70 ) ;
++ V_66 -> V_72 ;
return V_66 ;
V_71:
F_32 ( V_59 , V_62 ,
L_17 ) ;
return NULL ;
}
static int F_39 ( struct V_70 * V_70 , int V_40 , const char * V_73 )
{
struct V_65 * V_66 = F_37 ( V_70 ) ;
if ( V_40 > V_66 -> V_67 . V_68 ) {
char * * V_74 = realloc ( V_66 -> V_67 . V_75 , ( V_40 + 1 ) * sizeof( char * ) ) ;
if ( V_74 == NULL )
return - 1 ;
if ( V_66 -> V_67 . V_68 != - 1 ) {
memset ( V_74 + V_66 -> V_67 . V_68 + 1 , 0 ,
( V_40 - V_66 -> V_67 . V_68 ) * sizeof( char * ) ) ;
} else {
memset ( V_74 , 0 , ( V_40 + 1 ) * sizeof( char * ) ) ;
}
V_66 -> V_67 . V_75 = V_74 ;
V_66 -> V_67 . V_68 = V_40 ;
}
V_66 -> V_67 . V_75 [ V_40 ] = F_40 ( V_73 ) ;
return V_66 -> V_67 . V_75 [ V_40 ] != NULL ? 0 : - 1 ;
}
static int F_41 ( struct V_70 * V_70 , int V_40 )
{
char V_76 [ V_77 ] , V_73 [ V_77 ] ;
struct V_78 V_79 ;
int V_80 ;
if ( V_70 -> V_81 == V_70 -> V_82 ) {
F_16 ( V_76 , sizeof( V_76 ) ,
L_18 , V_70 -> V_81 , V_40 ) ;
} else {
F_16 ( V_76 , sizeof( V_76 ) ,
L_19 , V_70 -> V_81 , V_70 -> V_82 , V_40 ) ;
}
if ( F_42 ( V_76 , & V_79 ) < 0 || V_79 . V_83 + 1 > ( V_84 ) sizeof( V_73 ) )
return - 1 ;
V_80 = F_43 ( V_76 , V_73 , sizeof( V_73 ) ) ;
if ( V_80 < 0 || V_80 > V_79 . V_83 )
return - 1 ;
V_73 [ V_80 ] = '\0' ;
return F_39 ( V_70 , V_40 , V_73 ) ;
}
static const char * F_44 ( struct V_70 * V_70 , int V_40 ,
struct V_85 * V_85 )
{
struct V_65 * V_66 = F_37 ( V_70 ) ;
if ( V_66 == NULL )
return NULL ;
if ( V_40 < 0 )
return NULL ;
if ( ( V_40 > V_66 -> V_67 . V_68 || V_66 -> V_67 . V_75 [ V_40 ] == NULL ) ) {
if ( ! V_85 -> V_86 )
return NULL ;
++ V_85 -> V_87 . V_88 ;
if ( F_41 ( V_70 , V_40 ) )
return NULL ;
}
return V_66 -> V_67 . V_75 [ V_40 ] ;
}
static T_1 F_20 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_16 ( V_29 , V_6 , L_4 , V_40 ) ;
const char * V_89 = F_44 ( V_32 -> V_70 , V_40 , V_32 -> V_85 ) ;
if ( V_89 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_20 , V_89 ) ;
return V_42 ;
}
static T_1 F_45 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_20 ( V_29 , V_6 , V_32 ) ;
struct V_65 * V_66 = F_37 ( V_32 -> V_70 ) ;
if ( V_66 && V_40 >= 0 && V_40 <= V_66 -> V_67 . V_68 )
F_8 ( & V_66 -> V_67 . V_75 [ V_40 ] ) ;
return V_42 ;
}
static void F_46 ( struct V_70 * V_70 , const char * V_29 ,
unsigned long V_90 )
{
struct V_65 * V_66 = F_37 ( V_70 ) ;
V_66 -> V_91 . V_90 = V_90 ;
V_66 -> V_91 . V_92 = V_29 - V_66 -> V_93 ;
}
static T_1 F_47 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
unsigned long V_90 = V_32 -> V_37 ;
if ( ! V_32 -> V_85 -> V_94 )
return F_16 ( V_29 , V_6 , L_5 , V_90 ) ;
F_46 ( V_32 -> V_70 , V_29 , V_90 ) ;
return 0 ;
}
static bool F_48 ( struct V_85 * V_85 , double V_57 )
{
return V_57 < ( V_85 -> V_95 * V_61 ) ;
}
static T_1 F_49 ( struct V_85 * V_85 , T_4 V_96 , T_3 * V_59 )
{
double V_97 = ( double ) ( V_96 - V_85 -> V_98 ) / V_61 ;
return fprintf ( V_59 , L_21 , V_97 ) ;
}
static T_1 F_50 ( struct V_85 * V_85 , T_4 V_96 , T_3 * V_59 )
{
if ( V_96 > 0 )
return F_49 ( V_85 , V_96 , V_59 ) ;
return fprintf ( V_59 , L_22 ) ;
}
static void F_51 ( int V_99 )
{
V_100 = true ;
V_101 = V_99 == V_102 ;
}
static T_1 F_52 ( struct V_85 * V_85 , struct V_70 * V_70 ,
T_4 V_60 , bool V_103 , T_4 V_96 , T_3 * V_59 )
{
T_1 V_42 = F_50 ( V_85 , V_96 , V_59 ) ;
V_42 += F_31 ( V_60 , V_103 , V_59 ) ;
if ( V_85 -> V_104 ) {
if ( V_85 -> V_105 )
V_42 += fprintf ( V_59 , L_23 , F_53 ( V_70 ) ) ;
V_42 += fprintf ( V_59 , L_24 , V_70 -> V_82 ) ;
}
return V_42 ;
}
static int F_54 ( struct V_85 * V_85 , struct V_106 * V_106 ,
union V_107 * V_108 , struct V_14 * V_15 )
{
int V_80 = 0 ;
switch ( V_108 -> V_109 . type ) {
case V_110 :
F_32 ( V_85 -> V_111 , V_62 ,
L_25 V_112 L_26 , V_108 -> V_113 . V_113 ) ;
V_80 = F_55 ( V_106 , V_108 , V_15 ) ;
break;
default:
V_80 = F_56 ( V_106 , V_108 , V_15 ) ;
break;
}
return V_80 ;
}
static int F_57 ( struct V_114 * V_115 ,
union V_107 * V_108 ,
struct V_14 * V_15 ,
struct V_106 * V_106 )
{
struct V_85 * V_85 = F_58 ( V_115 , struct V_85 , V_115 ) ;
return F_54 ( V_85 , V_106 , V_108 , V_15 ) ;
}
static char * F_59 ( void * V_116 , unsigned long long * V_117 , char * * V_118 )
{
struct V_106 * V_106 = V_116 ;
if ( V_106 -> V_119 )
return NULL ;
if ( V_120 . V_121 ) {
F_60 ( L_27
L_28
L_29 ) ;
V_106 -> V_119 = true ;
return NULL ;
}
return F_61 ( V_116 , V_117 , V_118 ) ;
}
static int F_62 ( struct V_85 * V_85 , struct V_122 * V_123 )
{
int V_124 = F_63 ( NULL ) ;
if ( V_124 )
return V_124 ;
V_85 -> V_125 = F_64 () ;
if ( V_85 -> V_125 == NULL )
return - V_26 ;
if ( F_65 ( V_85 -> V_125 , F_59 ) < 0 )
return - V_126 ;
V_124 = F_66 ( V_85 -> V_125 , & V_85 -> V_115 , & V_85 -> V_127 . V_128 ,
V_123 -> V_129 , F_57 , false ,
V_85 -> V_127 . V_130 ) ;
if ( V_124 )
F_67 () ;
return V_124 ;
}
static int F_68 ( struct V_131 * V_132 )
{
struct V_3 * V_2 ;
int V_36 = 0 , V_133 ;
V_132 -> V_134 = calloc ( V_132 -> V_135 , sizeof( void * ) ) ;
if ( V_132 -> V_134 == NULL )
return - 1 ;
if ( V_132 -> V_54 )
V_132 -> V_136 = V_132 -> V_54 -> V_136 ;
for ( V_2 = V_132 -> args ; V_2 ; V_2 = V_2 -> V_137 ) {
if ( V_132 -> V_54 && V_132 -> V_54 -> V_134 [ V_36 ] )
V_132 -> V_134 [ V_36 ] = V_132 -> V_54 -> V_134 [ V_36 ] ;
else if ( strcmp ( V_2 -> type , L_30 ) == 0 &&
( strcmp ( V_2 -> V_20 , L_31 ) == 0 ||
strcmp ( V_2 -> V_20 , L_32 ) == 0 ||
strcmp ( V_2 -> V_20 , L_33 ) == 0 ) )
V_132 -> V_134 [ V_36 ] = V_138 ;
else if ( V_2 -> V_48 & V_139 )
V_132 -> V_134 [ V_36 ] = F_21 ;
else if ( strcmp ( V_2 -> type , L_34 ) == 0 )
V_132 -> V_134 [ V_36 ] = V_140 ;
else if ( strcmp ( V_2 -> type , L_35 ) == 0 )
V_132 -> V_134 [ V_36 ] = V_141 ;
else if ( ( strcmp ( V_2 -> type , L_36 ) == 0 ||
strcmp ( V_2 -> type , L_37 ) == 0 ||
strcmp ( V_2 -> type , L_38 ) == 0 ) &&
( V_133 = strlen ( V_2 -> V_20 ) ) >= 2 &&
strcmp ( V_2 -> V_20 + V_133 - 2 , L_39 ) == 0 ) {
V_132 -> V_134 [ V_36 ] = V_142 ;
}
++ V_36 ;
}
return 0 ;
}
static int F_69 ( struct V_85 * V_85 , int V_24 )
{
char V_143 [ 128 ] ;
struct V_131 * V_132 ;
const char * V_20 = F_70 ( V_85 -> V_144 , V_24 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_85 -> V_145 . V_68 ) {
struct V_131 * V_146 = realloc ( V_85 -> V_145 . V_75 , ( V_24 + 1 ) * sizeof( * V_132 ) ) ;
if ( V_146 == NULL )
return - 1 ;
if ( V_85 -> V_145 . V_68 != - 1 ) {
memset ( V_146 + V_85 -> V_145 . V_68 + 1 , 0 ,
( V_24 - V_85 -> V_145 . V_68 ) * sizeof( * V_132 ) ) ;
} else {
memset ( V_146 , 0 , ( V_24 + 1 ) * sizeof( * V_132 ) ) ;
}
V_85 -> V_145 . V_75 = V_146 ;
V_85 -> V_145 . V_68 = V_24 ;
}
V_132 = V_85 -> V_145 . V_75 + V_24 ;
V_132 -> V_20 = V_20 ;
V_132 -> V_54 = F_29 ( V_132 -> V_20 ) ;
snprintf ( V_143 , sizeof( V_143 ) , L_40 , V_132 -> V_20 ) ;
V_132 -> V_147 = F_71 ( L_2 , V_143 ) ;
if ( F_14 ( V_132 -> V_147 ) && V_132 -> V_54 && V_132 -> V_54 -> V_148 ) {
snprintf ( V_143 , sizeof( V_143 ) , L_40 , V_132 -> V_54 -> V_148 ) ;
V_132 -> V_147 = F_71 ( L_2 , V_143 ) ;
}
if ( F_14 ( V_132 -> V_147 ) )
return - 1 ;
V_132 -> args = V_132 -> V_147 -> V_149 . V_150 ;
V_132 -> V_135 = V_132 -> V_147 -> V_149 . V_151 ;
if ( V_132 -> args && ( ! strcmp ( V_132 -> args -> V_20 , L_41 ) || ! strcmp ( V_132 -> args -> V_20 , L_42 ) ) ) {
V_132 -> args = V_132 -> args -> V_137 ;
-- V_132 -> V_135 ;
}
V_132 -> V_152 = ! strcmp ( V_20 , L_43 ) || ! strcmp ( V_20 , L_44 ) ;
return F_68 ( V_132 ) ;
}
static int F_72 ( struct V_85 * V_85 )
{
int V_124 = 0 , V_153 ;
struct V_154 * V_155 ;
V_85 -> V_156 . V_157 = F_73 ( V_85 -> V_158 ) ;
V_85 -> V_156 . V_39 = malloc ( V_85 -> V_156 . V_157 *
sizeof( V_85 -> V_156 . V_39 [ 0 ] ) ) ;
if ( V_85 -> V_156 . V_39 == NULL ) {
fputs ( L_45 ,
V_85 -> V_111 ) ;
V_124 = - V_159 ;
goto V_160;
}
V_153 = 0 ;
F_74 (pos, trace->ev_qualifier) {
const char * V_132 = V_155 -> V_161 ;
int V_24 = F_75 ( V_85 -> V_144 , V_132 ) ;
if ( V_24 < 0 ) {
if ( V_124 == 0 ) {
fputs ( L_46 , V_85 -> V_111 ) ;
V_124 = - V_159 ;
} else {
fputs ( L_47 , V_85 -> V_111 ) ;
}
fputs ( V_132 , V_85 -> V_111 ) ;
}
V_85 -> V_156 . V_39 [ V_153 ++ ] = V_24 ;
}
if ( V_124 < 0 ) {
fputs ( L_48
L_49 , V_85 -> V_111 ) ;
F_8 ( & V_85 -> V_156 . V_39 ) ;
V_85 -> V_156 . V_157 = 0 ;
}
V_160:
return V_124 ;
}
static T_1 F_76 ( struct V_131 * V_132 , char * V_29 , T_1 V_6 ,
unsigned char * args , struct V_85 * V_85 ,
struct V_70 * V_70 )
{
T_1 V_42 = 0 ;
unsigned char * V_162 ;
unsigned long V_37 ;
if ( V_132 -> args != NULL ) {
struct V_3 * V_2 ;
T_5 V_163 = 1 ;
struct V_31 V_32 = {
. V_36 = 0 ,
. V_164 = 0 ,
. V_85 = V_85 ,
. V_70 = V_70 ,
} ;
for ( V_2 = V_132 -> args ; V_2 ;
V_2 = V_2 -> V_137 , ++ V_32 . V_36 , V_163 <<= 1 ) {
if ( V_32 . V_164 & V_163 )
continue;
V_162 = args + sizeof( unsigned long ) * V_32 . V_36 ;
memcpy ( & V_37 , V_162 , sizeof( V_37 ) ) ;
if ( V_37 == 0 &&
! ( V_132 -> V_134 &&
V_132 -> V_134 [ V_32 . V_36 ] == V_165 &&
V_132 -> V_136 [ V_32 . V_36 ] ) )
continue;
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_50 , V_42 ? L_47 : L_12 , V_2 -> V_20 ) ;
if ( V_132 -> V_134 && V_132 -> V_134 [ V_32 . V_36 ] ) {
V_32 . V_37 = V_37 ;
if ( V_132 -> V_136 )
V_32 . V_35 = V_132 -> V_136 [ V_32 . V_36 ] ;
V_42 += V_132 -> V_134 [ V_32 . V_36 ] ( V_29 + V_42 ,
V_6 - V_42 , & V_32 ) ;
} else {
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_51 , V_37 ) ;
}
}
} else if ( F_14 ( V_132 -> V_147 ) ) {
int V_153 = 0 ;
while ( V_153 < 6 ) {
V_162 = args + sizeof( unsigned long ) * V_153 ;
memcpy ( & V_37 , V_162 , sizeof( V_37 ) ) ;
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_52 ,
V_42 ? L_47 : L_12 , V_153 , V_37 ) ;
++ V_153 ;
}
}
return V_42 ;
}
static struct V_131 * F_77 ( struct V_85 * V_85 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_166 > 1 ) {
static T_4 T_2 ;
fprintf ( V_85 -> V_111 , L_53 V_112 L_54 ,
V_24 , F_78 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_85 -> V_145 . V_68 || V_85 -> V_145 . V_75 [ V_24 ] . V_20 == NULL ) &&
F_69 ( V_85 , V_24 ) )
goto V_167;
if ( ( V_24 > V_85 -> V_145 . V_68 || V_85 -> V_145 . V_75 [ V_24 ] . V_20 == NULL ) )
goto V_167;
return & V_85 -> V_145 . V_75 [ V_24 ] ;
V_167:
if ( V_166 > 0 ) {
fprintf ( V_85 -> V_111 , L_55 , V_24 ) ;
if ( V_24 <= V_85 -> V_145 . V_68 && V_85 -> V_145 . V_75 [ V_24 ] . V_20 != NULL )
fprintf ( V_85 -> V_111 , L_56 , V_85 -> V_145 . V_75 [ V_24 ] . V_20 ) ;
fputs ( L_57 , V_85 -> V_111 ) ;
}
return NULL ;
}
static void F_79 ( struct V_65 * V_66 ,
int V_24 , struct V_14 * V_15 )
{
struct V_168 * V_169 ;
struct V_87 * V_87 ;
T_4 V_60 = 0 ;
V_169 = F_80 ( V_66 -> V_69 , V_24 ) ;
if ( V_169 == NULL )
return;
V_87 = V_169 -> V_21 ;
if ( V_87 == NULL ) {
V_87 = malloc ( sizeof( struct V_87 ) ) ;
if ( V_87 == NULL )
return;
F_81 ( V_87 ) ;
V_169 -> V_21 = V_87 ;
}
if ( V_66 -> V_170 && V_15 -> time > V_66 -> V_170 )
V_60 = V_15 -> time - V_66 -> V_170 ;
F_82 ( V_87 , V_60 ) ;
}
static int F_83 ( struct V_85 * V_85 , struct V_14 * V_15 )
{
struct V_65 * V_66 ;
T_4 V_60 ;
T_1 V_42 ;
if ( V_85 -> V_171 == NULL )
return 0 ;
V_66 = F_37 ( V_85 -> V_171 ) ;
if ( ! V_66 -> V_172 )
return 0 ;
V_60 = V_15 -> time - V_66 -> V_170 ;
V_42 = F_52 ( V_85 , V_85 -> V_171 , V_60 , true , V_66 -> V_170 , V_85 -> V_111 ) ;
V_42 += fprintf ( V_85 -> V_111 , L_58 , V_66 -> V_93 ) ;
V_66 -> V_172 = false ;
return V_42 ;
}
static int F_84 ( struct V_85 * V_85 , struct V_18 * V_19 ,
union V_107 * V_108 V_173 ,
struct V_14 * V_15 )
{
char * V_174 ;
void * args ;
T_1 V_42 = 0 ;
struct V_70 * V_70 ;
int V_24 = F_85 ( V_19 , V_24 , V_15 ) , V_124 = - 1 ;
struct V_131 * V_132 = F_77 ( V_85 , V_19 , V_24 ) ;
struct V_65 * V_66 ;
if ( V_132 == NULL )
return - 1 ;
V_70 = F_86 ( V_85 -> V_125 , V_15 -> V_175 , V_15 -> V_82 ) ;
V_66 = F_36 ( V_70 , V_85 -> V_111 ) ;
if ( V_66 == NULL )
goto V_176;
args = F_87 ( V_19 , args , V_15 ) ;
if ( V_66 -> V_93 == NULL ) {
V_66 -> V_93 = malloc ( V_177 ) ;
if ( ! V_66 -> V_93 )
goto V_176;
}
if ( ! ( V_85 -> V_95 || V_85 -> V_178 || V_85 -> V_179 ) )
F_83 ( V_85 , V_15 ) ;
V_66 -> V_170 = V_15 -> time ;
V_174 = V_66 -> V_93 ;
V_42 += F_16 ( V_174 + V_42 , V_177 - V_42 , L_59 , V_132 -> V_20 ) ;
V_42 += F_76 ( V_132 , V_174 + V_42 , V_177 - V_42 ,
args , V_85 , V_70 ) ;
if ( V_132 -> V_152 ) {
if ( ! ( V_85 -> V_95 || V_85 -> V_178 || V_85 -> V_179 ) ) {
F_52 ( V_85 , V_70 , 0 , false , V_66 -> V_170 , V_85 -> V_111 ) ;
fprintf ( V_85 -> V_111 , L_60 , V_66 -> V_93 ) ;
}
} else {
V_66 -> V_172 = true ;
V_66 -> V_91 . V_180 = false ;
}
if ( V_85 -> V_171 != V_70 ) {
F_88 ( V_85 -> V_171 ) ;
V_85 -> V_171 = F_89 ( V_70 ) ;
}
V_124 = 0 ;
V_176:
F_88 ( V_70 ) ;
return V_124 ;
}
static int F_90 ( struct V_85 * V_85 , struct V_18 * V_19 ,
struct V_14 * V_15 ,
struct V_181 * V_182 )
{
struct V_183 V_184 ;
if ( F_91 ( V_85 -> V_125 , & V_184 , V_15 ) < 0 ||
F_92 ( V_184 . V_70 , V_182 , V_19 , V_15 , NULL , NULL , V_85 -> V_185 ) )
return - 1 ;
return 0 ;
}
static int F_93 ( struct V_85 * V_85 , struct V_14 * V_15 )
{
const unsigned int V_186 = V_187 |
V_188 |
V_189 ;
return F_94 ( V_15 , 38 , V_186 , & V_181 , V_85 -> V_111 ) ;
}
static int F_95 ( struct V_85 * V_85 , struct V_18 * V_19 ,
union V_107 * V_108 V_173 ,
struct V_14 * V_15 )
{
long V_80 ;
T_4 V_60 = 0 ;
bool V_103 = false ;
struct V_70 * V_70 ;
int V_24 = F_85 ( V_19 , V_24 , V_15 ) , V_124 = - 1 , V_190 = 0 ;
struct V_131 * V_132 = F_77 ( V_85 , V_19 , V_24 ) ;
struct V_65 * V_66 ;
if ( V_132 == NULL )
return - 1 ;
V_70 = F_86 ( V_85 -> V_125 , V_15 -> V_175 , V_15 -> V_82 ) ;
V_66 = F_36 ( V_70 , V_85 -> V_111 ) ;
if ( V_66 == NULL )
goto V_176;
if ( V_85 -> V_191 )
F_79 ( V_66 , V_24 , V_15 ) ;
V_80 = F_85 ( V_19 , V_80 , V_15 ) ;
if ( V_24 == V_85 -> V_192 && V_80 >= 0 && V_66 -> V_91 . V_180 ) {
F_39 ( V_70 , V_80 , V_66 -> V_91 . V_20 ) ;
V_66 -> V_91 . V_180 = false ;
++ V_85 -> V_87 . V_94 ;
}
if ( V_66 -> V_170 ) {
V_60 = V_15 -> time - V_66 -> V_170 ;
if ( F_48 ( V_85 , V_60 ) )
goto V_160;
V_103 = true ;
} else if ( V_85 -> V_95 )
goto V_160;
if ( V_15 -> V_193 ) {
V_190 = F_90 ( V_85 , V_19 , V_15 , & V_181 ) ;
if ( V_190 == 0 ) {
if ( V_181 . V_157 < V_85 -> V_179 )
goto V_160;
V_190 = 1 ;
}
}
if ( V_85 -> V_178 )
goto V_160;
F_52 ( V_85 , V_70 , V_60 , V_103 , V_66 -> V_170 , V_85 -> V_111 ) ;
if ( V_66 -> V_172 ) {
fprintf ( V_85 -> V_111 , L_61 , V_66 -> V_93 ) ;
} else {
fprintf ( V_85 -> V_111 , L_62 ) ;
F_32 ( V_85 -> V_111 , V_63 , L_63 ) ;
fprintf ( V_85 -> V_111 , L_64 , V_132 -> V_20 ) ;
}
if ( V_132 -> V_54 == NULL ) {
V_194:
fprintf ( V_85 -> V_111 , L_65 , V_80 ) ;
} else if ( V_80 < 0 && ( V_132 -> V_54 -> V_195 || V_132 -> V_54 -> V_196 ) ) {
char V_29 [ V_197 ] ;
const char * V_198 = F_96 ( - V_80 , V_29 , sizeof( V_29 ) ) ,
* V_199 = F_97 ( - V_80 ) ;
fprintf ( V_85 -> V_111 , L_66 , V_199 , V_198 ) ;
} else if ( V_80 == 0 && V_132 -> V_54 -> V_200 )
fprintf ( V_85 -> V_111 , L_67 ) ;
else if ( V_132 -> V_54 -> V_201 )
fprintf ( V_85 -> V_111 , L_68 , V_80 ) ;
else if ( V_132 -> V_54 -> V_196 ) {
struct V_70 * V_202 = F_98 ( V_85 -> V_125 , V_80 , V_80 ) ;
if ( V_202 != NULL ) {
fprintf ( V_85 -> V_111 , L_65 , V_80 ) ;
if ( V_202 -> V_203 )
fprintf ( V_85 -> V_111 , L_69 , F_53 ( V_202 ) ) ;
F_88 ( V_202 ) ;
}
} else
goto V_194;
fputc ( '\n' , V_85 -> V_111 ) ;
if ( V_190 > 0 )
F_93 ( V_85 , V_15 ) ;
else if ( V_190 < 0 )
F_99 ( L_70 , F_78 ( V_19 ) ) ;
V_160:
V_66 -> V_172 = false ;
V_124 = 0 ;
V_176:
F_88 ( V_70 ) ;
return V_124 ;
}
static int F_100 ( struct V_85 * V_85 , struct V_18 * V_19 ,
union V_107 * V_108 V_173 ,
struct V_14 * V_15 )
{
struct V_70 * V_70 = F_86 ( V_85 -> V_125 , V_15 -> V_175 , V_15 -> V_82 ) ;
struct V_65 * V_66 ;
T_1 V_204 , V_205 , V_206 ;
T_6 V_207 ;
char * V_155 ;
const char * V_91 = F_101 ( V_19 , V_15 , L_33 ) ;
if ( ! V_70 )
goto V_160;
V_66 = F_37 ( V_70 ) ;
if ( ! V_66 )
goto V_176;
V_204 = strlen ( V_91 ) ;
if ( V_204 == 0 )
goto V_176;
if ( V_66 -> V_91 . V_208 < V_204 ) {
char * V_209 = realloc ( V_66 -> V_91 . V_20 , V_204 + 1 ) ;
if ( V_209 == NULL )
goto V_176;
V_66 -> V_91 . V_208 = V_204 ;
V_66 -> V_91 . V_20 = V_209 ;
}
strcpy ( V_66 -> V_91 . V_20 , V_91 ) ;
V_66 -> V_91 . V_180 = true ;
if ( ! V_66 -> V_91 . V_90 )
goto V_176;
V_205 = strlen ( V_66 -> V_93 ) ;
V_207 = V_177 - V_205 - 1 ;
if ( V_207 <= 0 )
goto V_176;
if ( V_204 > ( T_1 ) V_207 ) {
V_91 += V_204 - V_207 ;
V_204 = V_207 ;
}
V_206 = V_205 - V_66 -> V_91 . V_92 + 1 ;
V_155 = V_66 -> V_93 + V_66 -> V_91 . V_92 ;
memmove ( V_155 + V_204 , V_155 , V_206 ) ;
memcpy ( V_155 , V_91 , V_204 ) ;
V_66 -> V_91 . V_90 = 0 ;
V_66 -> V_91 . V_92 = 0 ;
V_176:
F_88 ( V_70 ) ;
V_160:
return 0 ;
}
static int F_102 ( struct V_85 * V_85 , struct V_18 * V_19 ,
union V_107 * V_108 V_173 ,
struct V_14 * V_15 )
{
T_4 V_210 = F_103 ( V_19 , V_15 , L_71 ) ;
double V_211 = ( double ) V_210 / V_61 ;
struct V_70 * V_70 = F_86 ( V_85 -> V_125 ,
V_15 -> V_175 ,
V_15 -> V_82 ) ;
struct V_65 * V_66 = F_36 ( V_70 , V_85 -> V_111 ) ;
if ( V_66 == NULL )
goto V_212;
V_66 -> V_211 += V_211 ;
V_85 -> V_211 += V_211 ;
V_176:
F_88 ( V_70 ) ;
return 0 ;
V_212:
fprintf ( V_85 -> V_111 , L_72 V_112 L_73 V_112 L_74 ,
V_19 -> V_20 ,
F_104 ( V_19 , V_15 , L_75 ) ,
( V_213 ) F_103 ( V_19 , V_15 , L_76 ) ,
V_210 ,
F_103 ( V_19 , V_15 , L_77 ) ) ;
goto V_176;
}
static void F_105 ( enum V_214 V_215 ,
unsigned int V_37 , void * V_216 )
{
T_3 * V_111 = V_216 ;
unsigned char V_217 = ( unsigned char ) V_37 ;
switch ( V_215 ) {
case V_218 :
fprintf ( V_111 , L_78 , isprint ( V_217 ) ? V_217 : '.' ) ;
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
default:
break;
}
}
static void F_106 ( struct V_85 * V_85 ,
struct V_14 * V_15 )
{
F_107 ( V_15 -> V_16 , V_15 -> V_228 , 8 ,
F_105 , V_85 -> V_111 ) ;
}
static int F_108 ( struct V_85 * V_85 , struct V_18 * V_19 ,
union V_107 * V_108 V_173 ,
struct V_14 * V_15 )
{
int V_190 = 0 ;
if ( V_15 -> V_193 ) {
V_190 = F_90 ( V_85 , V_19 , V_15 , & V_181 ) ;
if ( V_190 == 0 ) {
if ( V_181 . V_157 < V_85 -> V_179 )
goto V_160;
V_190 = 1 ;
}
}
F_83 ( V_85 , V_15 ) ;
F_50 ( V_85 , V_15 -> time , V_85 -> V_111 ) ;
if ( V_85 -> V_229 )
fprintf ( V_85 -> V_111 , L_79 ) ;
fprintf ( V_85 -> V_111 , L_80 , V_19 -> V_20 ) ;
if ( F_109 ( V_19 ) ) {
F_106 ( V_85 , V_15 ) ;
} else if ( V_19 -> V_147 ) {
F_110 ( V_19 -> V_147 , V_15 -> V_230 ,
V_15 -> V_16 , V_15 -> V_228 ,
V_85 -> V_111 ) ;
}
fprintf ( V_85 -> V_111 , L_74 ) ;
if ( V_190 > 0 )
F_93 ( V_85 , V_15 ) ;
else if ( V_190 < 0 )
F_99 ( L_70 , F_78 ( V_19 ) ) ;
V_160:
return 0 ;
}
static void F_111 ( T_3 * V_209 , struct V_14 * V_15 ,
struct V_183 * V_184 ,
bool V_231 , bool V_232 )
{
if ( ( V_166 > 0 || V_231 ) && V_184 -> V_233 )
fprintf ( V_209 , L_81 , V_184 -> V_233 -> V_234 -> V_235 ) ;
if ( ( V_166 > 0 || V_232 ) && V_184 -> V_236 )
fprintf ( V_209 , L_82 V_237 , V_184 -> V_236 -> V_20 ,
V_184 -> V_238 - V_184 -> V_236 -> V_239 ) ;
else if ( V_184 -> V_233 )
fprintf ( V_209 , L_83 V_237 , V_184 -> V_238 ) ;
else
fprintf ( V_209 , L_83 V_237 , V_15 -> V_238 ) ;
}
static int F_112 ( struct V_85 * V_85 ,
struct V_18 * V_19 ,
union V_107 * V_108 V_173 ,
struct V_14 * V_15 )
{
struct V_70 * V_70 ;
struct V_183 V_184 ;
char V_240 = 'd' ;
struct V_65 * V_66 ;
int V_124 = - 1 ;
int V_190 = 0 ;
V_70 = F_86 ( V_85 -> V_125 , V_15 -> V_175 , V_15 -> V_82 ) ;
if ( V_15 -> V_193 ) {
V_190 = F_90 ( V_85 , V_19 , V_15 , & V_181 ) ;
if ( V_190 == 0 ) {
if ( V_181 . V_157 < V_85 -> V_179 )
goto V_176;
V_190 = 1 ;
}
}
V_66 = F_36 ( V_70 , V_85 -> V_111 ) ;
if ( V_66 == NULL )
goto V_176;
if ( V_19 -> V_241 . V_242 == V_243 )
V_66 -> V_244 ++ ;
else
V_66 -> V_245 ++ ;
if ( V_85 -> V_178 )
goto V_160;
F_113 ( V_70 , V_15 -> V_246 , V_247 ,
V_15 -> V_248 , & V_184 ) ;
F_52 ( V_85 , V_70 , 0 , true , V_15 -> time , V_85 -> V_111 ) ;
fprintf ( V_85 -> V_111 , L_84 ,
V_19 -> V_241 . V_242 == V_243 ?
L_85 : L_86 ) ;
F_111 ( V_85 -> V_111 , V_15 , & V_184 , false , true ) ;
fprintf ( V_85 -> V_111 , L_87 ) ;
F_113 ( V_70 , V_15 -> V_246 , V_249 ,
V_15 -> V_238 , & V_184 ) ;
if ( ! V_184 . V_233 ) {
F_113 ( V_70 , V_15 -> V_246 ,
V_247 , V_15 -> V_238 , & V_184 ) ;
if ( V_184 . V_233 )
V_240 = 'x' ;
else
V_240 = '?' ;
}
F_111 ( V_85 -> V_111 , V_15 , & V_184 , true , false ) ;
fprintf ( V_85 -> V_111 , L_88 , V_240 , V_184 . V_250 ) ;
if ( V_190 > 0 )
F_93 ( V_85 , V_15 ) ;
else if ( V_190 < 0 )
F_99 ( L_70 , F_78 ( V_19 ) ) ;
V_160:
V_124 = 0 ;
V_176:
F_88 ( V_70 ) ;
return V_124 ;
}
static void F_114 ( struct V_85 * V_85 ,
struct V_18 * V_19 ,
struct V_14 * V_15 )
{
if ( V_85 -> V_98 == 0 && ! V_85 -> V_251 &&
( V_19 -> V_241 . V_252 & V_253 ) )
V_85 -> V_98 = V_15 -> time ;
}
static int F_115 ( struct V_114 * V_115 ,
union V_107 * V_108 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_106 * V_106 V_173 )
{
struct V_85 * V_85 = F_58 ( V_115 , struct V_85 , V_115 ) ;
struct V_70 * V_70 ;
int V_124 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
V_70 = F_86 ( V_85 -> V_125 , V_15 -> V_175 , V_15 -> V_82 ) ;
if ( V_70 && F_116 ( V_70 ) )
goto V_160;
F_114 ( V_85 , V_19 , V_15 ) ;
if ( V_22 ) {
++ V_85 -> V_72 ;
V_22 ( V_85 , V_19 , V_108 , V_15 ) ;
}
V_160:
F_88 ( V_70 ) ;
return V_124 ;
}
static int F_117 ( struct V_85 * V_85 , int V_254 , const char * * V_255 )
{
unsigned int V_256 , V_153 , V_257 ;
const char * * V_258 ;
const char * const V_259 [] = {
L_89 ,
L_90 ,
L_91 , L_92 ,
L_93 , L_94 ,
} ;
const char * const V_260 [] = { L_95 , } ;
unsigned int V_261 = F_30 ( V_260 ) ;
const char * const V_262 [] = { L_95 , L_96 } ;
unsigned int V_263 = F_30 ( V_262 ) ;
const char * const V_264 [] = { L_95 , L_97 } ;
unsigned int V_265 = F_30 ( V_264 ) ;
V_256 = F_30 ( V_259 ) + V_261 + 1 +
V_263 + V_265 + V_254 ;
V_258 = calloc ( V_256 + 1 , sizeof( char * ) ) ;
if ( V_258 == NULL )
return - V_26 ;
V_257 = 0 ;
for ( V_153 = 0 ; V_153 < F_30 ( V_259 ) ; V_153 ++ )
V_258 [ V_257 ++ ] = V_259 [ V_153 ] ;
if ( V_85 -> V_229 ) {
for ( V_153 = 0 ; V_153 < V_261 ; V_153 ++ )
V_258 [ V_257 ++ ] = V_260 [ V_153 ] ;
if ( F_118 ( L_98 ) )
V_258 [ V_257 ++ ] = L_99 ;
else if ( F_118 ( L_100 ) )
V_258 [ V_257 ++ ] = L_101 ;
else {
F_99 ( L_102 ) ;
return - 1 ;
}
}
if ( V_85 -> V_266 & V_267 )
for ( V_153 = 0 ; V_153 < V_263 ; V_153 ++ )
V_258 [ V_257 ++ ] = V_262 [ V_153 ] ;
if ( V_85 -> V_266 & V_268 )
for ( V_153 = 0 ; V_153 < V_265 ; V_153 ++ )
V_258 [ V_257 ++ ] = V_264 [ V_153 ] ;
for ( V_153 = 0 ; V_153 < ( unsigned int ) V_254 ; V_153 ++ )
V_258 [ V_257 ++ ] = V_255 [ V_153 ] ;
return F_119 ( V_257 , V_258 ) ;
}
static bool F_120 ( struct V_122 * V_123 )
{
struct V_18 * V_19 = F_13 ( L_103 , L_104 ) ;
if ( F_14 ( V_19 ) )
return false ;
if ( F_5 ( V_19 , L_33 ) == NULL ) {
F_9 ( V_19 ) ;
return false ;
}
V_19 -> V_22 = F_100 ;
F_121 ( V_123 , V_19 ) ;
return true ;
}
static struct V_18 * F_122 ( T_4 V_242 )
{
struct V_18 * V_19 ;
struct V_269 V_241 = {
. type = V_270 ,
. V_271 = 1 ,
} ;
V_241 . V_242 = V_242 ;
V_241 . V_272 = 1 ;
F_123 ( & V_241 ) ;
V_19 = F_124 ( & V_241 ) ;
if ( V_19 )
V_19 -> V_22 = F_112 ;
return V_19 ;
}
static void F_125 ( struct V_85 * V_85 , union V_107 * V_108 , struct V_14 * V_15 )
{
const T_8 type = V_108 -> V_109 . type ;
struct V_18 * V_19 ;
if ( type != V_273 ) {
F_54 ( V_85 , V_85 -> V_125 , V_108 , V_15 ) ;
return;
}
V_19 = F_126 ( V_85 -> V_123 , V_15 -> V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_85 -> V_111 , L_105 V_112 L_106 , V_15 -> V_24 ) ;
return;
}
F_114 ( V_85 , V_19 , V_15 ) ;
if ( V_19 -> V_241 . type == V_274 &&
V_15 -> V_16 == NULL ) {
fprintf ( V_85 -> V_111 , L_107 ,
F_78 ( V_19 ) , V_15 -> V_82 ,
V_15 -> V_230 , V_15 -> V_228 ) ;
} else {
T_7 V_22 = V_19 -> V_22 ;
V_22 ( V_85 , V_19 , V_108 , V_15 ) ;
}
}
static int F_127 ( struct V_85 * V_85 )
{
int V_80 = - 1 ;
struct V_122 * V_123 = V_85 -> V_123 ;
struct V_18 * V_275 , * V_276 ;
V_275 = F_12 ( L_108 , F_84 ) ;
if ( V_275 == NULL )
goto V_160;
if ( F_128 ( V_275 , args ) )
goto V_277;
V_276 = F_12 ( L_109 , F_95 ) ;
if ( V_276 == NULL )
goto V_277;
if ( F_11 ( V_276 , V_80 ) )
goto V_278;
F_121 ( V_123 , V_275 ) ;
F_121 ( V_123 , V_276 ) ;
if ( V_279 . V_280 && ! V_85 -> V_281 ) {
V_276 -> V_241 . V_282 = 1 ;
}
V_85 -> V_145 . V_283 . V_275 = V_275 ;
V_85 -> V_145 . V_283 . V_276 = V_276 ;
V_80 = 0 ;
V_160:
return V_80 ;
V_278:
F_7 ( V_276 ) ;
V_277:
F_7 ( V_275 ) ;
goto V_160;
}
static int F_129 ( struct V_85 * V_85 )
{
int V_124 = - 1 ;
struct V_18 * V_276 ;
char * V_284 = F_130 ( L_110 , ! V_85 -> V_285 ,
V_85 -> V_156 . V_157 ,
V_85 -> V_156 . V_39 ) ;
if ( V_284 == NULL )
goto V_286;
if ( ! F_131 ( V_85 -> V_145 . V_283 . V_275 ,
V_284 ) ) {
V_276 = V_85 -> V_145 . V_283 . V_276 ;
V_124 = F_131 ( V_276 , V_284 ) ;
}
free ( V_284 ) ;
V_160:
return V_124 ;
V_286:
V_126 = V_26 ;
goto V_160;
}
static int F_132 ( struct V_85 * V_85 , int V_254 , const char * * V_255 )
{
struct V_122 * V_123 = V_85 -> V_123 ;
struct V_18 * V_19 , * V_287 = NULL , * V_288 = NULL ;
int V_124 = - 1 , V_153 ;
unsigned long V_289 ;
const bool V_290 = V_254 > 0 ;
bool V_291 = false ;
V_85 -> V_86 = true ;
if ( V_85 -> V_229 && F_127 ( V_85 ) )
goto V_292;
if ( V_85 -> V_229 )
V_85 -> V_94 = F_120 ( V_123 ) ;
if ( ( V_85 -> V_266 & V_267 ) ) {
V_287 = F_122 ( V_243 ) ;
if ( V_287 == NULL )
goto V_293;
F_121 ( V_123 , V_287 ) ;
}
if ( ( V_85 -> V_266 & V_268 ) ) {
V_288 = F_122 ( V_294 ) ;
if ( V_288 == NULL )
goto V_293;
F_121 ( V_123 , V_288 ) ;
}
if ( V_85 -> V_295 &&
F_133 ( V_123 , L_111 , L_112 ,
F_102 ) )
goto V_296;
V_124 = F_134 ( V_123 , & V_85 -> V_127 . V_128 ) ;
if ( V_124 < 0 ) {
fprintf ( V_85 -> V_111 , L_113 ) ;
goto V_297;
}
V_124 = F_62 ( V_85 , V_123 ) ;
if ( V_124 < 0 ) {
fprintf ( V_85 -> V_111 , L_114 ) ;
goto V_297;
}
F_135 ( V_123 , & V_85 -> V_127 , NULL ) ;
if ( V_279 . V_280 ) {
bool V_298 = false ;
if ( V_85 -> V_145 . V_283 . V_276 ) {
F_136 ( V_85 -> V_145 . V_283 . V_276 ,
& V_85 -> V_127 , & V_279 ) ;
V_298 = true ;
}
if ( V_287 ) {
F_136 ( V_287 , & V_85 -> V_127 , & V_279 ) ;
V_298 = true ;
}
if ( V_288 ) {
F_136 ( V_288 , & V_85 -> V_127 , & V_279 ) ;
V_298 = true ;
}
if ( V_298 ) {
F_137 ( V_123 , V_299 ) ;
F_138 ( V_123 , V_300 ) ;
}
}
signal ( V_301 , F_51 ) ;
signal ( V_102 , F_51 ) ;
if ( V_290 ) {
V_124 = F_139 ( V_123 , & V_85 -> V_127 . V_128 ,
V_255 , false , NULL ) ;
if ( V_124 < 0 ) {
fprintf ( V_85 -> V_111 , L_115 ) ;
goto V_297;
}
}
V_124 = F_140 ( V_123 ) ;
if ( V_124 < 0 )
goto V_302;
V_124 = F_141 () ;
if ( V_124 ) {
char V_303 [ V_304 ] ;
F_142 ( V_124 , V_303 , sizeof( V_303 ) ) ;
F_99 ( L_116 ,
V_303 ) ;
goto V_302;
}
if ( V_85 -> V_305 . V_157 > 0 )
V_124 = F_143 ( V_123 , V_85 -> V_305 . V_157 , V_85 -> V_305 . V_39 ) ;
else if ( F_144 ( V_123 -> V_129 , 0 ) == - 1 )
V_124 = F_145 ( V_123 , F_146 () ) ;
if ( V_124 < 0 )
goto V_293;
if ( V_85 -> V_156 . V_157 > 0 ) {
V_124 = F_129 ( V_85 ) ;
if ( V_124 < 0 )
goto V_306;
F_147 ( L_117 ,
V_85 -> V_145 . V_283 . V_276 -> V_284 ) ;
}
V_124 = F_148 ( V_123 , & V_19 ) ;
if ( V_124 < 0 )
goto V_307;
V_124 = F_149 ( V_123 , V_85 -> V_127 . V_308 , false ) ;
if ( V_124 < 0 )
goto V_309;
if ( ! F_150 ( & V_85 -> V_127 . V_128 ) && ! V_85 -> V_127 . V_310 )
F_151 ( V_123 ) ;
if ( V_290 )
F_152 ( V_123 ) ;
if ( V_85 -> V_127 . V_310 ) {
F_153 ( V_85 -> V_127 . V_310 * 1000 ) ;
F_151 ( V_123 ) ;
}
V_85 -> V_104 = F_144 ( V_123 -> V_129 , 0 ) == - 1 ||
V_123 -> V_129 -> V_157 > 1 ||
F_154 ( V_123 ) -> V_241 . V_311 ;
V_312:
V_289 = V_85 -> V_72 ;
for ( V_153 = 0 ; V_153 < V_123 -> V_313 ; V_153 ++ ) {
union V_107 * V_108 ;
while ( ( V_108 = F_155 ( V_123 , V_153 ) ) != NULL ) {
struct V_14 V_15 ;
++ V_85 -> V_72 ;
V_124 = F_156 ( V_123 , V_108 , & V_15 ) ;
if ( V_124 ) {
fprintf ( V_85 -> V_111 , L_118 , V_124 ) ;
goto V_314;
}
F_125 ( V_85 , V_108 , & V_15 ) ;
V_314:
F_157 ( V_123 , V_153 ) ;
if ( V_101 )
goto V_315;
if ( V_100 && ! V_291 ) {
F_158 ( V_123 ) ;
V_291 = true ;
}
}
}
if ( V_85 -> V_72 == V_289 ) {
int V_200 = V_100 ? 100 : - 1 ;
if ( ! V_291 && F_159 ( V_123 , V_200 ) > 0 ) {
if ( F_160 ( V_123 , V_316 | V_317 ) == 0 )
V_291 = true ;
goto V_312;
}
} else {
goto V_312;
}
V_315:
F_161 ( V_85 -> V_171 ) ;
F_158 ( V_123 ) ;
if ( ! V_124 ) {
if ( V_85 -> V_191 )
F_162 ( V_85 , V_85 -> V_111 ) ;
if ( V_85 -> V_318 ) {
fprintf ( V_85 -> V_111 , L_119
L_120 V_112 L_121
L_122 V_112 L_121 ,
V_85 -> V_87 . V_94 ,
V_85 -> V_87 . V_88 ) ;
}
}
V_297:
F_163 ( V_123 ) ;
V_85 -> V_123 = NULL ;
V_85 -> V_86 = false ;
return V_124 ;
{
char V_303 [ V_304 ] ;
V_296:
F_164 ( V_126 , V_303 , sizeof( V_303 ) , L_111 , L_112 ) ;
goto V_319;
V_292:
F_164 ( V_126 , V_303 , sizeof( V_303 ) , L_1 , L_123 ) ;
goto V_319;
V_309:
F_165 ( V_123 , V_126 , V_303 , sizeof( V_303 ) ) ;
goto V_319;
V_302:
F_166 ( V_123 , V_126 , V_303 , sizeof( V_303 ) ) ;
V_319:
fprintf ( V_85 -> V_111 , L_124 , V_303 ) ;
goto V_297;
V_307:
fprintf ( V_85 -> V_111 ,
L_125 ,
V_19 -> V_284 , F_78 ( V_19 ) , V_126 ,
F_96 ( V_126 , V_303 , sizeof( V_303 ) ) ) ;
goto V_297;
}
V_293:
fprintf ( V_85 -> V_111 , L_126 ) ;
goto V_297;
V_306:
fprintf ( V_85 -> V_111 , L_127 , V_126 , strerror ( V_126 ) ) ;
goto V_297;
}
static int F_167 ( struct V_85 * V_85 )
{
const struct V_320 V_321 [] = {
{ L_128 , F_100 , } ,
} ;
struct V_322 V_323 = {
. V_89 = V_324 ,
. V_43 = V_325 ,
. V_326 = V_85 -> V_326 ,
} ;
struct V_327 * V_328 ;
struct V_18 * V_19 ;
int V_124 = - 1 ;
V_85 -> V_115 . V_15 = F_115 ;
V_85 -> V_115 . V_329 = V_330 ;
V_85 -> V_115 . V_331 = V_332 ;
V_85 -> V_115 . V_333 = V_334 ;
V_85 -> V_115 . exit = V_335 ;
V_85 -> V_115 . V_336 = V_337 ;
V_85 -> V_115 . V_241 = V_338 ;
V_85 -> V_115 . V_339 = V_340 ;
V_85 -> V_115 . V_341 = V_342 ;
V_85 -> V_115 . V_343 = V_344 ;
V_85 -> V_115 . V_345 = true ;
V_85 -> V_115 . V_346 = true ;
V_85 -> V_104 = true ;
V_328 = F_168 ( & V_323 , false , & V_85 -> V_115 ) ;
if ( V_328 == NULL )
return - 1 ;
if ( V_85 -> V_127 . V_128 . V_175 )
V_120 . V_347 = F_40 ( V_85 -> V_127 . V_128 . V_175 ) ;
if ( V_85 -> V_127 . V_128 . V_82 )
V_120 . V_348 = F_40 ( V_85 -> V_127 . V_128 . V_82 ) ;
if ( F_63 ( & V_328 -> V_109 . V_349 ) < 0 )
goto V_160;
V_85 -> V_125 = & V_328 -> V_350 . V_125 ;
V_124 = F_169 ( V_328 , V_321 ) ;
if ( V_124 )
goto V_160;
V_19 = F_170 ( V_328 -> V_123 ,
L_98 ) ;
if ( V_19 == NULL )
V_19 = F_170 ( V_328 -> V_123 ,
L_100 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_84 ) < 0 ||
F_128 ( V_19 , args ) ) ) {
F_99 ( L_129 ) ;
goto V_160;
}
V_19 = F_170 ( V_328 -> V_123 ,
L_130 ) ;
if ( V_19 == NULL )
V_19 = F_170 ( V_328 -> V_123 ,
L_131 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_95 ) < 0 ||
F_11 ( V_19 , V_80 ) ) ) {
F_99 ( L_132 ) ;
goto V_160;
}
F_171 (session->evlist, evsel) {
if ( V_19 -> V_241 . type == V_270 &&
( V_19 -> V_241 . V_242 == V_243 ||
V_19 -> V_241 . V_242 == V_294 ||
V_19 -> V_241 . V_242 == V_351 ) )
V_19 -> V_22 = F_112 ;
}
F_172 () ;
V_124 = F_173 ( V_328 ) ;
if ( V_124 )
F_99 ( L_133 , V_124 ) ;
else if ( V_85 -> V_191 )
F_162 ( V_85 , V_85 -> V_111 ) ;
V_160:
F_174 ( V_328 ) ;
return V_124 ;
}
static T_1 F_175 ( T_3 * V_59 )
{
T_1 V_42 ;
V_42 = fprintf ( V_59 , L_134 ) ;
return V_42 ;
}
static T_1 F_176 ( struct V_65 * V_66 ,
struct V_85 * V_85 , T_3 * V_59 )
{
T_1 V_42 = 0 ;
struct V_131 * V_132 ;
struct V_352 * V_353 ;
F_177 ( V_69 , V_66 -> V_69 ) ;
if ( V_69 == NULL )
return 0 ;
V_42 += fprintf ( V_59 , L_121 ) ;
V_42 += fprintf ( V_59 , L_135 ) ;
V_42 += fprintf ( V_59 , L_136 ) ;
V_42 += fprintf ( V_59 , L_137 ) ;
F_178 (nd, syscall_stats) {
struct V_87 * V_87 = V_354 -> V_87 ;
if ( V_87 ) {
double V_355 = ( double ) ( V_87 -> V_355 ) / V_61 ;
double V_68 = ( double ) ( V_87 -> V_68 ) / V_61 ;
double V_356 = F_179 ( V_87 ) ;
double V_357 ;
T_4 T_2 = ( T_4 ) V_87 -> T_2 ;
V_357 = V_356 ? 100.0 * F_180 ( V_87 ) / V_356 : 0.0 ;
V_356 /= V_61 ;
V_132 = & V_85 -> V_145 . V_75 [ V_354 -> V_131 ] ;
V_42 += fprintf ( V_59 , L_138 , V_132 -> V_20 ) ;
V_42 += fprintf ( V_59 , L_139 V_112 L_140 ,
T_2 , V_354 -> V_358 , V_355 , V_356 ) ;
V_42 += fprintf ( V_59 , L_141 , V_68 , V_357 ) ;
}
}
F_181 ( V_69 ) ;
V_42 += fprintf ( V_59 , L_142 ) ;
return V_42 ;
}
static T_1 F_182 ( T_3 * V_59 , struct V_70 * V_70 , struct V_85 * V_85 )
{
T_1 V_42 = 0 ;
struct V_65 * V_66 = F_37 ( V_70 ) ;
double V_359 ;
if ( V_66 == NULL )
return 0 ;
V_359 = ( double ) V_66 -> V_72 / V_85 -> V_72 * 100.0 ;
V_42 += fprintf ( V_59 , L_143 , F_53 ( V_70 ) , V_70 -> V_82 ) ;
V_42 += fprintf ( V_59 , L_144 , V_66 -> V_72 ) ;
V_42 += fprintf ( V_59 , L_145 , V_359 ) ;
if ( V_66 -> V_244 )
V_42 += fprintf ( V_59 , L_146 , V_66 -> V_244 ) ;
if ( V_66 -> V_245 )
V_42 += fprintf ( V_59 , L_147 , V_66 -> V_245 ) ;
if ( V_85 -> V_295 )
V_42 += fprintf ( V_59 , L_148 , V_66 -> V_211 ) ;
else if ( fputc ( '\n' , V_59 ) != V_360 )
++ V_42 ;
V_42 += F_176 ( V_66 , V_85 , V_59 ) ;
return V_42 ;
}
static unsigned long F_183 ( struct V_65 * V_66 )
{
return V_66 ? V_66 -> V_72 : 0 ;
}
static T_1 F_162 ( struct V_85 * V_85 , T_3 * V_59 )
{
F_184 ( V_129 , V_85 -> V_125 ) ;
T_1 V_42 = F_175 ( V_59 ) ;
struct V_352 * V_353 ;
if ( V_129 == NULL ) {
fprintf ( V_59 , L_3 , L_149 ) ;
return 0 ;
}
F_178 (nd, threads)
V_42 += F_182 ( V_59 , V_361 -> V_70 , V_85 ) ;
F_181 ( V_129 ) ;
return V_42 ;
}
static int F_185 ( const struct V_362 * V_363 , const char * V_364 ,
int T_9 V_173 )
{
struct V_85 * V_85 = V_363 -> V_365 ;
V_85 -> V_95 = atof ( V_364 ) ;
return 0 ;
}
static int F_186 ( const struct V_362 * V_363 , const char * V_364 ,
int T_9 V_173 )
{
int V_80 = - 1 ;
T_1 V_153 ;
struct V_85 * V_85 = V_363 -> V_365 ;
struct V_366 * V_367 = F_35 ( V_364 ) ;
if ( V_367 == NULL )
return - 1 ;
V_153 = V_85 -> V_305 . V_157 = F_187 ( V_367 ) + 1 ;
V_85 -> V_305 . V_39 = calloc ( V_153 , sizeof( V_213 ) ) ;
if ( V_85 -> V_305 . V_39 == NULL )
goto V_160;
V_85 -> V_305 . V_39 [ 0 ] = F_146 () ;
for ( V_153 = 1 ; V_153 < V_85 -> V_305 . V_157 ; ++ V_153 )
V_85 -> V_305 . V_39 [ V_153 ] = F_188 ( V_367 , V_153 - 1 ) -> V_153 ;
F_189 ( V_367 ) ;
V_80 = 0 ;
V_160:
return V_80 ;
}
static int F_190 ( struct V_85 * V_85 , const char * V_91 )
{
struct V_78 V_79 ;
if ( ! V_78 ( V_91 , & V_79 ) && V_79 . V_83 ) {
char V_368 [ V_77 ] ;
F_16 ( V_368 , sizeof( V_368 ) , L_150 , V_91 ) ;
F_191 ( V_368 ) ;
rename ( V_91 , V_368 ) ;
}
V_85 -> V_111 = fopen ( V_91 , L_151 ) ;
return V_85 -> V_111 == NULL ? - V_126 : 0 ;
}
static int F_192 ( const struct V_362 * V_363 , const char * V_364 ,
int T_9 V_173 )
{
int * V_266 = V_363 -> V_365 ;
if ( strcmp ( V_364 , L_152 ) == 0 )
* V_266 |= V_267 | V_268 ;
else if ( strcmp ( V_364 , L_85 ) == 0 )
* V_266 |= V_267 ;
else if ( strcmp ( V_364 , L_86 ) == 0 )
* V_266 |= V_268 ;
else
return - 1 ;
return 0 ;
}
static void F_193 ( struct V_122 * V_123 , void * V_22 )
{
struct V_18 * V_19 ;
F_171 (evlist, evsel)
V_19 -> V_22 = V_22 ;
}
static int F_194 ( const struct V_362 * V_363 , const char * V_364 ,
int T_9 V_173 )
{
struct V_85 * V_85 = (struct V_85 * ) V_363 -> V_365 ;
const char * V_161 = V_364 ;
char * V_369 = NULL , * V_370 [ 2 ] = { NULL , NULL , } ;
int V_133 = strlen ( V_364 ) , V_124 = - 1 , V_367 ;
char * V_371 = F_195 ( V_372 ) ;
char V_373 [ V_77 ] ;
if ( V_371 == NULL )
return - 1 ;
if ( * V_161 == '!' ) {
++ V_161 ;
V_85 -> V_285 = true ;
}
while ( 1 ) {
if ( ( V_369 = strchr ( V_161 , ',' ) ) != NULL )
* V_369 = '\0' ;
V_367 = 0 ;
if ( F_75 ( V_85 -> V_144 , V_161 ) >= 0 ) {
V_367 = 1 ;
} else {
F_196 ( V_373 , sizeof( V_373 ) , V_371 , V_161 ) ;
if ( F_197 ( V_373 , V_374 ) == 0 )
V_367 = 1 ;
}
if ( V_370 [ V_367 ] ) {
sprintf ( V_370 [ V_367 ] + strlen ( V_370 [ V_367 ] ) , L_153 , V_161 ) ;
} else {
V_370 [ V_367 ] = malloc ( V_133 ) ;
if ( V_370 [ V_367 ] == NULL )
goto V_160;
strcpy ( V_370 [ V_367 ] , V_161 ) ;
}
if ( ! V_369 )
break;
* V_369 = ',' ;
V_161 = V_369 + 1 ;
}
if ( V_370 [ 1 ] != NULL ) {
struct V_375 V_376 = {
. V_377 = V_371 ,
} ;
V_85 -> V_158 = F_198 ( V_370 [ 1 ] , & V_376 ) ;
if ( V_85 -> V_158 == NULL ) {
fputs ( L_154 , V_85 -> V_111 ) ;
goto V_160;
}
if ( F_72 ( V_85 ) )
goto V_160;
}
V_124 = 0 ;
if ( V_370 [ 0 ] ) {
struct V_362 V_378 = F_199 ( 'e' , L_155 , & V_85 -> V_123 , L_155 ,
L_156 ,
V_379 ) ;
V_124 = V_379 ( & V_378 , V_370 [ 0 ] , 0 ) ;
}
V_160:
if ( V_369 )
* V_369 = ',' ;
return V_124 ;
}
int F_200 ( int V_254 , const char * * V_255 )
{
const char * V_380 [] = {
L_157 ,
L_158 ,
L_159 ,
L_160 ,
NULL
} ;
struct V_85 V_85 = {
. V_145 = {
. V_68 = - 1 ,
} ,
. V_127 = {
. V_128 = {
. V_381 = V_382 ,
. V_383 = true ,
} ,
. V_384 = V_382 ,
. V_385 = V_386 ,
. V_387 = true ,
. V_308 = V_382 ,
. V_130 = 500 ,
} ,
. V_111 = V_388 ,
. V_105 = true ,
. V_229 = true ,
. V_281 = false ,
. V_185 = V_382 ,
} ;
const char * V_389 = NULL ;
const struct V_362 V_390 [] = {
F_199 ( 'e' , L_155 , & V_85 , L_155 ,
L_161 ,
F_194 ) ,
F_201 ( 0 , L_75 , & V_85 . V_105 ,
L_162 ) ,
F_201 ( 0 , L_163 , & V_85 . V_318 , L_164 ) ,
F_199 ( 0 , L_165 , & V_85 , L_165 , L_166 ,
F_194 ) ,
F_202 ( 'o' , L_167 , & V_389 , L_168 , L_169 ) ,
F_202 ( 'i' , L_170 , & V_324 , L_168 , L_171 ) ,
F_202 ( 'p' , L_76 , & V_85 . V_127 . V_128 . V_175 , L_76 ,
L_172 ) ,
F_202 ( 't' , L_173 , & V_85 . V_127 . V_128 . V_82 , L_173 ,
L_174 ) ,
F_199 ( 0 , L_175 , & V_85 , L_176 ,
L_177 , F_186 ) ,
F_201 ( 'a' , L_178 , & V_85 . V_127 . V_128 . V_391 ,
L_179 ) ,
F_202 ( 'C' , L_180 , & V_85 . V_127 . V_128 . V_392 , L_180 ,
L_181 ) ,
F_201 ( 0 , L_182 , & V_85 . V_127 . V_393 ,
L_183 ) ,
F_199 ( 'm' , L_184 , & V_85 . V_127 . V_308 , L_185 ,
L_186 ,
V_394 ) ,
F_202 ( 'u' , L_187 , & V_85 . V_127 . V_128 . V_395 , L_188 ,
L_189 ) ,
F_199 ( 0 , L_190 , & V_85 , L_191 ,
L_192 ,
F_185 ) ,
F_201 ( 0 , L_111 , & V_85 . V_295 , L_193 ) ,
F_203 ( 'v' , L_194 , & V_166 , L_195 ) ,
F_201 ( 'T' , L_196 , & V_85 . V_251 ,
L_197 ) ,
F_201 ( 's' , L_198 , & V_85 . V_178 ,
L_199 ) ,
F_201 ( 'S' , L_200 , & V_85 . V_191 ,
L_201 ) ,
F_204 ( 'F' , L_202 , & V_85 . V_266 , L_203 ,
L_204 , F_192 , L_85 ) ,
F_201 ( 0 , L_2 , & V_85 . V_229 , L_205 ) ,
F_201 ( 'f' , L_206 , & V_85 . V_326 , L_207 ) ,
F_199 ( 0 , L_208 , & V_85 . V_127 ,
L_209 , V_396 ,
& V_397 ) ,
F_201 ( 0 , L_210 , & V_85 . V_281 ,
L_211 ) ,
F_205 ( 0 , L_212 , & V_85 . V_179 ,
L_213
L_214 ) ,
F_205 ( 0 , L_215 , & V_85 . V_185 ,
L_216
L_217
L_218 F_206 ( V_398 ) ) ,
F_205 ( 0 , L_219 , & V_85 . V_127 . V_130 ,
L_220 ) ,
F_205 ( 'D' , L_221 , & V_85 . V_127 . V_310 ,
L_222
L_223 ) ,
F_207 ()
} ;
bool V_173 V_399 = true ;
bool V_400 = true ;
const char * const V_401 [] = { L_89 , NULL } ;
int V_124 ;
char V_29 [ V_304 ] ;
signal ( V_402 , V_403 ) ;
signal ( V_404 , V_403 ) ;
V_85 . V_123 = F_208 () ;
V_85 . V_144 = F_209 () ;
if ( V_85 . V_123 == NULL || V_85 . V_144 == NULL ) {
F_99 ( L_126 ) ;
V_124 = - V_26 ;
goto V_160;
}
V_254 = F_210 ( V_254 , V_255 , V_390 , V_401 ,
V_380 , V_405 ) ;
V_124 = F_211 ( V_85 . V_123 ) ;
if ( V_124 ) {
F_212 ( V_85 . V_123 , V_124 , V_29 , sizeof( V_29 ) ) ;
F_99 ( L_224 , V_29 ) ;
goto V_160;
}
V_124 = - 1 ;
if ( V_85 . V_266 ) {
V_85 . V_127 . V_406 = true ;
V_85 . V_127 . V_407 = true ;
}
if ( V_85 . V_127 . V_308 == V_382 )
V_400 = false ;
if ( V_85 . V_185 == V_382 ) {
V_85 . V_185 = V_324 ? V_398 : V_408 ;
V_399 = false ;
}
#ifdef F_213
if ( ( V_85 . V_179 || V_399 ) && ! V_279 . V_280 && V_85 . V_229 )
F_214 ( & V_85 . V_127 , & V_279 , L_225 , false ) ;
#endif
if ( V_279 . V_280 ) {
if ( ! V_400 && F_215 () == 0 )
V_85 . V_127 . V_308 = F_216 () * 4 ;
V_120 . V_409 = true ;
}
if ( V_85 . V_123 -> V_38 > 0 )
F_193 ( V_85 . V_123 , F_108 ) ;
if ( ( V_254 >= 1 ) && ( strcmp ( V_255 [ 0 ] , L_89 ) == 0 ) )
return F_117 ( & V_85 , V_254 - 1 , & V_255 [ 1 ] ) ;
if ( V_85 . V_178 )
V_85 . V_191 = V_85 . V_178 ;
if ( ! V_85 . V_229 && ! V_85 . V_266 &&
V_85 . V_123 -> V_38 == 0 ) {
F_99 ( L_226 ) ;
return - 1 ;
}
if ( ! V_85 . V_229 && V_85 . V_158 ) {
F_99 ( L_227 ) ;
goto V_160;
}
if ( V_389 != NULL ) {
V_124 = F_190 ( & V_85 , V_389 ) ;
if ( V_124 < 0 ) {
perror ( L_228 ) ;
goto V_160;
}
}
V_85 . V_192 = F_75 ( V_85 . V_144 , L_229 ) ;
V_124 = F_217 ( & V_85 . V_127 . V_128 ) ;
if ( V_124 ) {
F_218 ( & V_85 . V_127 . V_128 , V_124 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_85 . V_111 , L_3 , V_29 ) ;
goto V_410;
}
V_124 = F_219 ( & V_85 . V_127 . V_128 ) ;
if ( V_124 ) {
F_218 ( & V_85 . V_127 . V_128 , V_124 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_85 . V_111 , L_3 , V_29 ) ;
goto V_410;
}
if ( ! V_254 && F_150 ( & V_85 . V_127 . V_128 ) )
V_85 . V_127 . V_128 . V_391 = true ;
if ( V_324 )
V_124 = F_167 ( & V_85 ) ;
else
V_124 = F_132 ( & V_85 , V_254 , V_255 ) ;
V_410:
if ( V_389 != NULL )
fclose ( V_85 . V_111 ) ;
V_160:
return V_124 ;
}
