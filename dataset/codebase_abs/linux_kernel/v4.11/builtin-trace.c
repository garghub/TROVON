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
static T_1 F_31 ( unsigned long V_57 , T_3 * V_58 )
{
double V_59 = ( double ) V_57 / V_60 ;
T_1 V_42 = fprintf ( V_58 , L_13 ) ;
if ( V_59 >= 1.0 )
V_42 += F_32 ( V_58 , V_61 , L_14 , V_59 ) ;
else if ( V_59 >= 0.01 )
V_42 += F_32 ( V_58 , V_62 , L_14 , V_59 ) ;
else
V_42 += F_32 ( V_58 , V_63 , L_14 , V_59 ) ;
return V_42 + fprintf ( V_58 , L_15 ) ;
}
static struct V_64 * F_33 ( void )
{
struct V_64 * V_65 = F_34 ( sizeof( struct V_64 ) ) ;
if ( V_65 )
V_65 -> V_66 . V_67 = - 1 ;
V_65 -> V_68 = F_35 ( NULL ) ;
return V_65 ;
}
static struct V_64 * F_36 ( struct V_69 * V_69 , T_3 * V_58 )
{
struct V_64 * V_65 ;
if ( V_69 == NULL )
goto V_70;
if ( F_37 ( V_69 ) == NULL )
F_38 ( V_69 , F_33 () ) ;
if ( F_37 ( V_69 ) == NULL )
goto V_70;
V_65 = F_37 ( V_69 ) ;
++ V_65 -> V_71 ;
return V_65 ;
V_70:
F_32 ( V_58 , V_61 ,
L_16 ) ;
return NULL ;
}
static int F_39 ( struct V_69 * V_69 , int V_40 , const char * V_72 )
{
struct V_64 * V_65 = F_37 ( V_69 ) ;
if ( V_40 > V_65 -> V_66 . V_67 ) {
char * * V_73 = realloc ( V_65 -> V_66 . V_74 , ( V_40 + 1 ) * sizeof( char * ) ) ;
if ( V_73 == NULL )
return - 1 ;
if ( V_65 -> V_66 . V_67 != - 1 ) {
memset ( V_73 + V_65 -> V_66 . V_67 + 1 , 0 ,
( V_40 - V_65 -> V_66 . V_67 ) * sizeof( char * ) ) ;
} else {
memset ( V_73 , 0 , ( V_40 + 1 ) * sizeof( char * ) ) ;
}
V_65 -> V_66 . V_74 = V_73 ;
V_65 -> V_66 . V_67 = V_40 ;
}
V_65 -> V_66 . V_74 [ V_40 ] = F_40 ( V_72 ) ;
return V_65 -> V_66 . V_74 [ V_40 ] != NULL ? 0 : - 1 ;
}
static int F_41 ( struct V_69 * V_69 , int V_40 )
{
char V_75 [ V_76 ] , V_72 [ V_76 ] ;
struct V_77 V_78 ;
int V_79 ;
if ( V_69 -> V_80 == V_69 -> V_81 ) {
F_16 ( V_75 , sizeof( V_75 ) ,
L_17 , V_69 -> V_80 , V_40 ) ;
} else {
F_16 ( V_75 , sizeof( V_75 ) ,
L_18 , V_69 -> V_80 , V_69 -> V_81 , V_40 ) ;
}
if ( F_42 ( V_75 , & V_78 ) < 0 || V_78 . V_82 + 1 > ( V_83 ) sizeof( V_72 ) )
return - 1 ;
V_79 = F_43 ( V_75 , V_72 , sizeof( V_72 ) ) ;
if ( V_79 < 0 || V_79 > V_78 . V_82 )
return - 1 ;
V_72 [ V_79 ] = '\0' ;
return F_39 ( V_69 , V_40 , V_72 ) ;
}
static const char * F_44 ( struct V_69 * V_69 , int V_40 ,
struct V_84 * V_84 )
{
struct V_64 * V_65 = F_37 ( V_69 ) ;
if ( V_65 == NULL )
return NULL ;
if ( V_40 < 0 )
return NULL ;
if ( ( V_40 > V_65 -> V_66 . V_67 || V_65 -> V_66 . V_74 [ V_40 ] == NULL ) ) {
if ( ! V_84 -> V_85 )
return NULL ;
++ V_84 -> V_86 . V_87 ;
if ( F_41 ( V_69 , V_40 ) )
return NULL ;
}
return V_65 -> V_66 . V_74 [ V_40 ] ;
}
static T_1 F_20 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_16 ( V_29 , V_6 , L_4 , V_40 ) ;
const char * V_88 = F_44 ( V_32 -> V_69 , V_40 , V_32 -> V_84 ) ;
if ( V_88 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_19 , V_88 ) ;
return V_42 ;
}
static T_1 F_45 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_20 ( V_29 , V_6 , V_32 ) ;
struct V_64 * V_65 = F_37 ( V_32 -> V_69 ) ;
if ( V_65 && V_40 >= 0 && V_40 <= V_65 -> V_66 . V_67 )
F_8 ( & V_65 -> V_66 . V_74 [ V_40 ] ) ;
return V_42 ;
}
static void F_46 ( struct V_69 * V_69 , const char * V_29 ,
unsigned long V_89 )
{
struct V_64 * V_65 = F_37 ( V_69 ) ;
V_65 -> V_90 . V_89 = V_89 ;
V_65 -> V_90 . V_91 = V_29 - V_65 -> V_92 ;
}
static T_1 F_47 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
unsigned long V_89 = V_32 -> V_37 ;
if ( ! V_32 -> V_84 -> V_93 )
return F_16 ( V_29 , V_6 , L_5 , V_89 ) ;
F_46 ( V_32 -> V_69 , V_29 , V_89 ) ;
return 0 ;
}
static bool F_48 ( struct V_84 * V_84 , double V_57 )
{
return V_57 < ( V_84 -> V_94 * V_60 ) ;
}
static T_1 F_49 ( struct V_84 * V_84 , T_4 V_95 , T_3 * V_58 )
{
double V_96 = ( double ) ( V_95 - V_84 -> V_97 ) / V_60 ;
return fprintf ( V_58 , L_20 , V_96 ) ;
}
static void F_50 ( int V_98 )
{
V_99 = true ;
V_100 = V_98 == V_101 ;
}
static T_1 F_51 ( struct V_84 * V_84 , struct V_69 * V_69 ,
T_4 V_59 , T_4 V_95 , T_3 * V_58 )
{
T_1 V_42 = F_49 ( V_84 , V_95 , V_58 ) ;
V_42 += F_31 ( V_59 , V_58 ) ;
if ( V_84 -> V_102 ) {
if ( V_84 -> V_103 )
V_42 += fprintf ( V_58 , L_21 , F_52 ( V_69 ) ) ;
V_42 += fprintf ( V_58 , L_22 , V_69 -> V_81 ) ;
}
return V_42 ;
}
static int F_53 ( struct V_84 * V_84 , struct V_104 * V_104 ,
union V_105 * V_106 , struct V_14 * V_15 )
{
int V_79 = 0 ;
switch ( V_106 -> V_107 . type ) {
case V_108 :
F_32 ( V_84 -> V_109 , V_61 ,
L_23 V_110 L_24 , V_106 -> V_111 . V_111 ) ;
V_79 = F_54 ( V_104 , V_106 , V_15 ) ;
break;
default:
V_79 = F_55 ( V_104 , V_106 , V_15 ) ;
break;
}
return V_79 ;
}
static int F_56 ( struct V_112 * V_113 ,
union V_105 * V_106 ,
struct V_14 * V_15 ,
struct V_104 * V_104 )
{
struct V_84 * V_84 = F_57 ( V_113 , struct V_84 , V_113 ) ;
return F_53 ( V_84 , V_104 , V_106 , V_15 ) ;
}
static char * F_58 ( void * V_114 , unsigned long long * V_115 , char * * V_116 )
{
struct V_104 * V_104 = V_114 ;
if ( V_104 -> V_117 )
return NULL ;
if ( V_118 . V_119 ) {
F_59 ( L_25
L_26
L_27 ) ;
V_104 -> V_117 = true ;
return NULL ;
}
return F_60 ( V_114 , V_115 , V_116 ) ;
}
static int F_61 ( struct V_84 * V_84 , struct V_120 * V_121 )
{
int V_122 = F_62 ( NULL ) ;
if ( V_122 )
return V_122 ;
V_84 -> V_123 = F_63 () ;
if ( V_84 -> V_123 == NULL )
return - V_26 ;
if ( F_64 ( V_84 -> V_123 , F_58 ) < 0 )
return - V_124 ;
V_122 = F_65 ( V_84 -> V_123 , & V_84 -> V_113 , & V_84 -> V_125 . V_126 ,
V_121 -> V_127 , F_56 , false ,
V_84 -> V_125 . V_128 ) ;
if ( V_122 )
F_66 () ;
return V_122 ;
}
static int F_67 ( struct V_129 * V_130 )
{
struct V_3 * V_2 ;
int V_36 = 0 , V_131 ;
V_130 -> V_132 = calloc ( V_130 -> V_133 , sizeof( void * ) ) ;
if ( V_130 -> V_132 == NULL )
return - 1 ;
if ( V_130 -> V_54 )
V_130 -> V_134 = V_130 -> V_54 -> V_134 ;
for ( V_2 = V_130 -> args ; V_2 ; V_2 = V_2 -> V_135 ) {
if ( V_130 -> V_54 && V_130 -> V_54 -> V_132 [ V_36 ] )
V_130 -> V_132 [ V_36 ] = V_130 -> V_54 -> V_132 [ V_36 ] ;
else if ( strcmp ( V_2 -> type , L_28 ) == 0 &&
( strcmp ( V_2 -> V_20 , L_29 ) == 0 ||
strcmp ( V_2 -> V_20 , L_30 ) == 0 ||
strcmp ( V_2 -> V_20 , L_31 ) == 0 ) )
V_130 -> V_132 [ V_36 ] = V_136 ;
else if ( V_2 -> V_48 & V_137 )
V_130 -> V_132 [ V_36 ] = F_21 ;
else if ( strcmp ( V_2 -> type , L_32 ) == 0 )
V_130 -> V_132 [ V_36 ] = V_138 ;
else if ( strcmp ( V_2 -> type , L_33 ) == 0 )
V_130 -> V_132 [ V_36 ] = V_139 ;
else if ( ( strcmp ( V_2 -> type , L_34 ) == 0 ||
strcmp ( V_2 -> type , L_35 ) == 0 ||
strcmp ( V_2 -> type , L_36 ) == 0 ) &&
( V_131 = strlen ( V_2 -> V_20 ) ) >= 2 &&
strcmp ( V_2 -> V_20 + V_131 - 2 , L_37 ) == 0 ) {
V_130 -> V_132 [ V_36 ] = V_140 ;
}
++ V_36 ;
}
return 0 ;
}
static int F_68 ( struct V_84 * V_84 , int V_24 )
{
char V_141 [ 128 ] ;
struct V_129 * V_130 ;
const char * V_20 = F_69 ( V_84 -> V_142 , V_24 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_84 -> V_143 . V_67 ) {
struct V_129 * V_144 = realloc ( V_84 -> V_143 . V_74 , ( V_24 + 1 ) * sizeof( * V_130 ) ) ;
if ( V_144 == NULL )
return - 1 ;
if ( V_84 -> V_143 . V_67 != - 1 ) {
memset ( V_144 + V_84 -> V_143 . V_67 + 1 , 0 ,
( V_24 - V_84 -> V_143 . V_67 ) * sizeof( * V_130 ) ) ;
} else {
memset ( V_144 , 0 , ( V_24 + 1 ) * sizeof( * V_130 ) ) ;
}
V_84 -> V_143 . V_74 = V_144 ;
V_84 -> V_143 . V_67 = V_24 ;
}
V_130 = V_84 -> V_143 . V_74 + V_24 ;
V_130 -> V_20 = V_20 ;
V_130 -> V_54 = F_29 ( V_130 -> V_20 ) ;
snprintf ( V_141 , sizeof( V_141 ) , L_38 , V_130 -> V_20 ) ;
V_130 -> V_145 = F_70 ( L_2 , V_141 ) ;
if ( F_14 ( V_130 -> V_145 ) && V_130 -> V_54 && V_130 -> V_54 -> V_146 ) {
snprintf ( V_141 , sizeof( V_141 ) , L_38 , V_130 -> V_54 -> V_146 ) ;
V_130 -> V_145 = F_70 ( L_2 , V_141 ) ;
}
if ( F_14 ( V_130 -> V_145 ) )
return - 1 ;
V_130 -> args = V_130 -> V_145 -> V_147 . V_148 ;
V_130 -> V_133 = V_130 -> V_145 -> V_147 . V_149 ;
if ( V_130 -> args && ( ! strcmp ( V_130 -> args -> V_20 , L_39 ) || ! strcmp ( V_130 -> args -> V_20 , L_40 ) ) ) {
V_130 -> args = V_130 -> args -> V_135 ;
-- V_130 -> V_133 ;
}
V_130 -> V_150 = ! strcmp ( V_20 , L_41 ) || ! strcmp ( V_20 , L_42 ) ;
return F_67 ( V_130 ) ;
}
static int F_71 ( struct V_84 * V_84 )
{
int V_122 = 0 , V_151 ;
struct V_152 * V_153 ;
V_84 -> V_154 . V_155 = F_72 ( V_84 -> V_156 ) ;
V_84 -> V_154 . V_39 = malloc ( V_84 -> V_154 . V_155 *
sizeof( V_84 -> V_154 . V_39 [ 0 ] ) ) ;
if ( V_84 -> V_154 . V_39 == NULL ) {
fputs ( L_43 ,
V_84 -> V_109 ) ;
V_122 = - V_157 ;
goto V_158;
}
V_151 = 0 ;
F_73 (pos, trace->ev_qualifier) {
const char * V_130 = V_153 -> V_159 ;
int V_24 = F_74 ( V_84 -> V_142 , V_130 ) ;
if ( V_24 < 0 ) {
if ( V_122 == 0 ) {
fputs ( L_44 , V_84 -> V_109 ) ;
V_122 = - V_157 ;
} else {
fputs ( L_45 , V_84 -> V_109 ) ;
}
fputs ( V_130 , V_84 -> V_109 ) ;
}
V_84 -> V_154 . V_39 [ V_151 ++ ] = V_24 ;
}
if ( V_122 < 0 ) {
fputs ( L_46
L_47 , V_84 -> V_109 ) ;
F_8 ( & V_84 -> V_154 . V_39 ) ;
V_84 -> V_154 . V_155 = 0 ;
}
V_158:
return V_122 ;
}
static T_1 F_75 ( struct V_129 * V_130 , char * V_29 , T_1 V_6 ,
unsigned char * args , struct V_84 * V_84 ,
struct V_69 * V_69 )
{
T_1 V_42 = 0 ;
unsigned char * V_160 ;
unsigned long V_37 ;
if ( V_130 -> args != NULL ) {
struct V_3 * V_2 ;
T_5 V_161 = 1 ;
struct V_31 V_32 = {
. V_36 = 0 ,
. V_162 = 0 ,
. V_84 = V_84 ,
. V_69 = V_69 ,
} ;
for ( V_2 = V_130 -> args ; V_2 ;
V_2 = V_2 -> V_135 , ++ V_32 . V_36 , V_161 <<= 1 ) {
if ( V_32 . V_162 & V_161 )
continue;
V_160 = args + sizeof( unsigned long ) * V_32 . V_36 ;
memcpy ( & V_37 , V_160 , sizeof( V_37 ) ) ;
if ( V_37 == 0 &&
! ( V_130 -> V_132 &&
V_130 -> V_132 [ V_32 . V_36 ] == V_163 &&
V_130 -> V_134 [ V_32 . V_36 ] ) )
continue;
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_48 , V_42 ? L_45 : L_12 , V_2 -> V_20 ) ;
if ( V_130 -> V_132 && V_130 -> V_132 [ V_32 . V_36 ] ) {
V_32 . V_37 = V_37 ;
if ( V_130 -> V_134 )
V_32 . V_35 = V_130 -> V_134 [ V_32 . V_36 ] ;
V_42 += V_130 -> V_132 [ V_32 . V_36 ] ( V_29 + V_42 ,
V_6 - V_42 , & V_32 ) ;
} else {
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_49 , V_37 ) ;
}
}
} else if ( F_14 ( V_130 -> V_145 ) ) {
int V_151 = 0 ;
while ( V_151 < 6 ) {
V_160 = args + sizeof( unsigned long ) * V_151 ;
memcpy ( & V_37 , V_160 , sizeof( V_37 ) ) ;
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_50 ,
V_42 ? L_45 : L_12 , V_151 , V_37 ) ;
++ V_151 ;
}
}
return V_42 ;
}
static struct V_129 * F_76 ( struct V_84 * V_84 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_164 > 1 ) {
static T_4 T_2 ;
fprintf ( V_84 -> V_109 , L_51 V_110 L_52 ,
V_24 , F_77 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_84 -> V_143 . V_67 || V_84 -> V_143 . V_74 [ V_24 ] . V_20 == NULL ) &&
F_68 ( V_84 , V_24 ) )
goto V_165;
if ( ( V_24 > V_84 -> V_143 . V_67 || V_84 -> V_143 . V_74 [ V_24 ] . V_20 == NULL ) )
goto V_165;
return & V_84 -> V_143 . V_74 [ V_24 ] ;
V_165:
if ( V_164 > 0 ) {
fprintf ( V_84 -> V_109 , L_53 , V_24 ) ;
if ( V_24 <= V_84 -> V_143 . V_67 && V_84 -> V_143 . V_74 [ V_24 ] . V_20 != NULL )
fprintf ( V_84 -> V_109 , L_54 , V_84 -> V_143 . V_74 [ V_24 ] . V_20 ) ;
fputs ( L_55 , V_84 -> V_109 ) ;
}
return NULL ;
}
static void F_78 ( struct V_64 * V_65 ,
int V_24 , struct V_14 * V_15 )
{
struct V_166 * V_167 ;
struct V_86 * V_86 ;
T_4 V_59 = 0 ;
V_167 = F_79 ( V_65 -> V_68 , V_24 ) ;
if ( V_167 == NULL )
return;
V_86 = V_167 -> V_21 ;
if ( V_86 == NULL ) {
V_86 = malloc ( sizeof( struct V_86 ) ) ;
if ( V_86 == NULL )
return;
F_80 ( V_86 ) ;
V_167 -> V_21 = V_86 ;
}
if ( V_65 -> V_168 && V_15 -> time > V_65 -> V_168 )
V_59 = V_15 -> time - V_65 -> V_168 ;
F_81 ( V_86 , V_59 ) ;
}
static int F_82 ( struct V_84 * V_84 , struct V_14 * V_15 )
{
struct V_64 * V_65 ;
T_4 V_59 ;
T_1 V_42 ;
if ( V_84 -> V_169 == NULL )
return 0 ;
V_65 = F_37 ( V_84 -> V_169 ) ;
if ( ! V_65 -> V_170 )
return 0 ;
V_59 = V_15 -> time - V_65 -> V_168 ;
V_42 = F_51 ( V_84 , V_84 -> V_169 , V_59 , V_65 -> V_168 , V_84 -> V_109 ) ;
V_42 += fprintf ( V_84 -> V_109 , L_56 , V_65 -> V_92 ) ;
V_65 -> V_170 = false ;
return V_42 ;
}
static int F_83 ( struct V_84 * V_84 , struct V_18 * V_19 ,
union V_105 * V_106 V_171 ,
struct V_14 * V_15 )
{
char * V_172 ;
void * args ;
T_1 V_42 = 0 ;
struct V_69 * V_69 ;
int V_24 = F_84 ( V_19 , V_24 , V_15 ) , V_122 = - 1 ;
struct V_129 * V_130 = F_76 ( V_84 , V_19 , V_24 ) ;
struct V_64 * V_65 ;
if ( V_130 == NULL )
return - 1 ;
V_69 = F_85 ( V_84 -> V_123 , V_15 -> V_173 , V_15 -> V_81 ) ;
V_65 = F_36 ( V_69 , V_84 -> V_109 ) ;
if ( V_65 == NULL )
goto V_174;
args = F_86 ( V_19 , args , V_15 ) ;
if ( V_65 -> V_92 == NULL ) {
V_65 -> V_92 = malloc ( V_175 ) ;
if ( ! V_65 -> V_92 )
goto V_174;
}
if ( ! ( V_84 -> V_94 || V_84 -> V_176 || V_84 -> V_177 ) )
F_82 ( V_84 , V_15 ) ;
V_65 -> V_168 = V_15 -> time ;
V_172 = V_65 -> V_92 ;
V_42 += F_16 ( V_172 + V_42 , V_175 - V_42 , L_57 , V_130 -> V_20 ) ;
V_42 += F_75 ( V_130 , V_172 + V_42 , V_175 - V_42 ,
args , V_84 , V_69 ) ;
if ( V_130 -> V_150 ) {
if ( ! ( V_84 -> V_94 || V_84 -> V_176 || V_84 -> V_177 ) ) {
F_51 ( V_84 , V_69 , 1 , V_65 -> V_168 , V_84 -> V_109 ) ;
fprintf ( V_84 -> V_109 , L_58 , V_65 -> V_92 ) ;
}
} else {
V_65 -> V_170 = true ;
V_65 -> V_90 . V_178 = false ;
}
if ( V_84 -> V_169 != V_69 ) {
F_87 ( V_84 -> V_169 ) ;
V_84 -> V_169 = F_88 ( V_69 ) ;
}
V_122 = 0 ;
V_174:
F_87 ( V_69 ) ;
return V_122 ;
}
static int F_89 ( struct V_84 * V_84 , struct V_18 * V_19 ,
struct V_14 * V_15 ,
struct V_179 * V_180 )
{
struct V_181 V_182 ;
if ( F_90 ( V_84 -> V_123 , & V_182 , V_15 ) < 0 ||
F_91 ( V_182 . V_69 , V_180 , V_19 , V_15 , NULL , NULL , V_84 -> V_183 ) )
return - 1 ;
return 0 ;
}
static int F_92 ( struct V_84 * V_84 , struct V_14 * V_15 )
{
const unsigned int V_184 = V_185 |
V_186 |
V_187 ;
return F_93 ( V_15 , 38 , V_184 , & V_179 , V_84 -> V_109 ) ;
}
static int F_94 ( struct V_84 * V_84 , struct V_18 * V_19 ,
union V_105 * V_106 V_171 ,
struct V_14 * V_15 )
{
long V_79 ;
T_4 V_59 = 0 ;
struct V_69 * V_69 ;
int V_24 = F_84 ( V_19 , V_24 , V_15 ) , V_122 = - 1 , V_188 = 0 ;
struct V_129 * V_130 = F_76 ( V_84 , V_19 , V_24 ) ;
struct V_64 * V_65 ;
if ( V_130 == NULL )
return - 1 ;
V_69 = F_85 ( V_84 -> V_123 , V_15 -> V_173 , V_15 -> V_81 ) ;
V_65 = F_36 ( V_69 , V_84 -> V_109 ) ;
if ( V_65 == NULL )
goto V_174;
if ( V_84 -> V_189 )
F_78 ( V_65 , V_24 , V_15 ) ;
V_79 = F_84 ( V_19 , V_79 , V_15 ) ;
if ( V_24 == V_84 -> V_190 && V_79 >= 0 && V_65 -> V_90 . V_178 ) {
F_39 ( V_69 , V_79 , V_65 -> V_90 . V_20 ) ;
V_65 -> V_90 . V_178 = false ;
++ V_84 -> V_86 . V_93 ;
}
if ( V_65 -> V_168 ) {
V_59 = V_15 -> time - V_65 -> V_168 ;
if ( F_48 ( V_84 , V_59 ) )
goto V_158;
} else if ( V_84 -> V_94 )
goto V_158;
if ( V_15 -> V_191 ) {
V_188 = F_89 ( V_84 , V_19 , V_15 , & V_179 ) ;
if ( V_188 == 0 ) {
if ( V_179 . V_155 < V_84 -> V_177 )
goto V_158;
V_188 = 1 ;
}
}
if ( V_84 -> V_176 )
goto V_158;
F_51 ( V_84 , V_69 , V_59 , V_65 -> V_168 , V_84 -> V_109 ) ;
if ( V_65 -> V_170 ) {
fprintf ( V_84 -> V_109 , L_59 , V_65 -> V_92 ) ;
} else {
fprintf ( V_84 -> V_109 , L_60 ) ;
F_32 ( V_84 -> V_109 , V_62 , L_61 ) ;
fprintf ( V_84 -> V_109 , L_62 , V_130 -> V_20 ) ;
}
if ( V_130 -> V_54 == NULL ) {
V_192:
fprintf ( V_84 -> V_109 , L_63 , V_79 ) ;
} else if ( V_79 < 0 && ( V_130 -> V_54 -> V_193 || V_130 -> V_54 -> V_194 ) ) {
char V_29 [ V_195 ] ;
const char * V_196 = F_95 ( - V_79 , V_29 , sizeof( V_29 ) ) ,
* V_197 = F_96 ( - V_79 ) ;
fprintf ( V_84 -> V_109 , L_64 , V_197 , V_196 ) ;
} else if ( V_79 == 0 && V_130 -> V_54 -> V_198 )
fprintf ( V_84 -> V_109 , L_65 ) ;
else if ( V_130 -> V_54 -> V_199 )
fprintf ( V_84 -> V_109 , L_66 , V_79 ) ;
else if ( V_130 -> V_54 -> V_194 ) {
struct V_69 * V_200 = F_97 ( V_84 -> V_123 , V_79 , V_79 ) ;
if ( V_200 != NULL ) {
fprintf ( V_84 -> V_109 , L_63 , V_79 ) ;
if ( V_200 -> V_201 )
fprintf ( V_84 -> V_109 , L_67 , F_52 ( V_200 ) ) ;
F_87 ( V_200 ) ;
}
} else
goto V_192;
fputc ( '\n' , V_84 -> V_109 ) ;
if ( V_188 > 0 )
F_92 ( V_84 , V_15 ) ;
else if ( V_188 < 0 )
F_98 ( L_68 , F_77 ( V_19 ) ) ;
V_158:
V_65 -> V_170 = false ;
V_122 = 0 ;
V_174:
F_87 ( V_69 ) ;
return V_122 ;
}
static int F_99 ( struct V_84 * V_84 , struct V_18 * V_19 ,
union V_105 * V_106 V_171 ,
struct V_14 * V_15 )
{
struct V_69 * V_69 = F_85 ( V_84 -> V_123 , V_15 -> V_173 , V_15 -> V_81 ) ;
struct V_64 * V_65 ;
T_1 V_202 , V_203 , V_204 ;
T_6 V_205 ;
char * V_153 ;
const char * V_90 = F_100 ( V_19 , V_15 , L_31 ) ;
if ( ! V_69 )
goto V_158;
V_65 = F_37 ( V_69 ) ;
if ( ! V_65 )
goto V_158;
V_202 = strlen ( V_90 ) ;
if ( V_65 -> V_90 . V_206 < V_202 ) {
char * V_207 = realloc ( V_65 -> V_90 . V_20 , V_202 + 1 ) ;
if ( V_207 == NULL )
goto V_158;
V_65 -> V_90 . V_206 = V_202 ;
V_65 -> V_90 . V_20 = V_207 ;
}
strcpy ( V_65 -> V_90 . V_20 , V_90 ) ;
V_65 -> V_90 . V_178 = true ;
if ( ! V_65 -> V_90 . V_89 )
goto V_158;
V_203 = strlen ( V_65 -> V_92 ) ;
V_205 = V_175 - V_203 - 1 ;
if ( V_205 <= 0 )
goto V_158;
if ( V_202 > ( T_1 ) V_205 ) {
V_90 += V_202 - V_205 ;
V_202 = V_205 ;
}
V_204 = V_203 - V_65 -> V_90 . V_91 + 1 ;
V_153 = V_65 -> V_92 + V_65 -> V_90 . V_91 ;
memmove ( V_153 + V_202 , V_153 , V_204 ) ;
memcpy ( V_153 , V_90 , V_202 ) ;
V_65 -> V_90 . V_89 = 0 ;
V_65 -> V_90 . V_91 = 0 ;
V_158:
return 0 ;
}
static int F_101 ( struct V_84 * V_84 , struct V_18 * V_19 ,
union V_105 * V_106 V_171 ,
struct V_14 * V_15 )
{
T_4 V_208 = F_102 ( V_19 , V_15 , L_69 ) ;
double V_209 = ( double ) V_208 / V_60 ;
struct V_69 * V_69 = F_85 ( V_84 -> V_123 ,
V_15 -> V_173 ,
V_15 -> V_81 ) ;
struct V_64 * V_65 = F_36 ( V_69 , V_84 -> V_109 ) ;
if ( V_65 == NULL )
goto V_210;
V_65 -> V_209 += V_209 ;
V_84 -> V_209 += V_209 ;
F_87 ( V_69 ) ;
return 0 ;
V_210:
fprintf ( V_84 -> V_109 , L_70 V_110 L_71 V_110 L_72 ,
V_19 -> V_20 ,
F_103 ( V_19 , V_15 , L_73 ) ,
( V_211 ) F_102 ( V_19 , V_15 , L_74 ) ,
V_208 ,
F_102 ( V_19 , V_15 , L_75 ) ) ;
F_87 ( V_69 ) ;
return 0 ;
}
static void F_104 ( enum V_212 V_213 ,
unsigned int V_37 , void * V_214 )
{
T_3 * V_109 = V_214 ;
unsigned char V_215 = ( unsigned char ) V_37 ;
switch ( V_213 ) {
case V_216 :
fprintf ( V_109 , L_76 , isprint ( V_215 ) ? V_215 : '.' ) ;
break;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
default:
break;
}
}
static void F_105 ( struct V_84 * V_84 ,
struct V_14 * V_15 )
{
F_106 ( V_15 -> V_16 , V_15 -> V_226 , 8 ,
F_104 , V_84 -> V_109 ) ;
}
static int F_107 ( struct V_84 * V_84 , struct V_18 * V_19 ,
union V_105 * V_106 V_171 ,
struct V_14 * V_15 )
{
int V_188 = 0 ;
if ( V_15 -> V_191 ) {
V_188 = F_89 ( V_84 , V_19 , V_15 , & V_179 ) ;
if ( V_188 == 0 ) {
if ( V_179 . V_155 < V_84 -> V_177 )
goto V_158;
V_188 = 1 ;
}
}
F_82 ( V_84 , V_15 ) ;
F_49 ( V_84 , V_15 -> time , V_84 -> V_109 ) ;
if ( V_84 -> V_227 )
fprintf ( V_84 -> V_109 , L_77 ) ;
fprintf ( V_84 -> V_109 , L_78 , V_19 -> V_20 ) ;
if ( F_108 ( V_19 ) ) {
F_105 ( V_84 , V_15 ) ;
} else if ( V_19 -> V_145 ) {
F_109 ( V_19 -> V_145 , V_15 -> V_228 ,
V_15 -> V_16 , V_15 -> V_226 ,
V_84 -> V_109 ) ;
}
fprintf ( V_84 -> V_109 , L_72 ) ;
if ( V_188 > 0 )
F_92 ( V_84 , V_15 ) ;
else if ( V_188 < 0 )
F_98 ( L_68 , F_77 ( V_19 ) ) ;
V_158:
return 0 ;
}
static void F_110 ( T_3 * V_207 , struct V_14 * V_15 ,
struct V_181 * V_182 ,
bool V_229 , bool V_230 )
{
if ( ( V_164 > 0 || V_229 ) && V_182 -> V_231 )
fprintf ( V_207 , L_79 , V_182 -> V_231 -> V_232 -> V_233 ) ;
if ( ( V_164 > 0 || V_230 ) && V_182 -> V_234 )
fprintf ( V_207 , L_80 V_235 , V_182 -> V_234 -> V_20 ,
V_182 -> V_236 - V_182 -> V_234 -> V_237 ) ;
else if ( V_182 -> V_231 )
fprintf ( V_207 , L_81 V_235 , V_182 -> V_236 ) ;
else
fprintf ( V_207 , L_81 V_235 , V_15 -> V_236 ) ;
}
static int F_111 ( struct V_84 * V_84 ,
struct V_18 * V_19 ,
union V_105 * V_106 V_171 ,
struct V_14 * V_15 )
{
struct V_69 * V_69 ;
struct V_181 V_182 ;
char V_238 = 'd' ;
struct V_64 * V_65 ;
int V_122 = - 1 ;
int V_188 = 0 ;
V_69 = F_85 ( V_84 -> V_123 , V_15 -> V_173 , V_15 -> V_81 ) ;
if ( V_15 -> V_191 ) {
V_188 = F_89 ( V_84 , V_19 , V_15 , & V_179 ) ;
if ( V_188 == 0 ) {
if ( V_179 . V_155 < V_84 -> V_177 )
goto V_174;
V_188 = 1 ;
}
}
V_65 = F_36 ( V_69 , V_84 -> V_109 ) ;
if ( V_65 == NULL )
goto V_174;
if ( V_19 -> V_239 . V_240 == V_241 )
V_65 -> V_242 ++ ;
else
V_65 -> V_243 ++ ;
if ( V_84 -> V_176 )
goto V_158;
F_112 ( V_69 , V_15 -> V_244 , V_245 ,
V_15 -> V_246 , & V_182 ) ;
F_51 ( V_84 , V_69 , 0 , V_15 -> time , V_84 -> V_109 ) ;
fprintf ( V_84 -> V_109 , L_82 ,
V_19 -> V_239 . V_240 == V_241 ?
L_83 : L_84 ) ;
F_110 ( V_84 -> V_109 , V_15 , & V_182 , false , true ) ;
fprintf ( V_84 -> V_109 , L_85 ) ;
F_112 ( V_69 , V_15 -> V_244 , V_247 ,
V_15 -> V_236 , & V_182 ) ;
if ( ! V_182 . V_231 ) {
F_112 ( V_69 , V_15 -> V_244 ,
V_245 , V_15 -> V_236 , & V_182 ) ;
if ( V_182 . V_231 )
V_238 = 'x' ;
else
V_238 = '?' ;
}
F_110 ( V_84 -> V_109 , V_15 , & V_182 , true , false ) ;
fprintf ( V_84 -> V_109 , L_86 , V_238 , V_182 . V_248 ) ;
if ( V_188 > 0 )
F_92 ( V_84 , V_15 ) ;
else if ( V_188 < 0 )
F_98 ( L_68 , F_77 ( V_19 ) ) ;
V_158:
V_122 = 0 ;
V_174:
F_87 ( V_69 ) ;
return V_122 ;
}
static void F_113 ( struct V_84 * V_84 ,
struct V_18 * V_19 ,
struct V_14 * V_15 )
{
if ( V_84 -> V_97 == 0 && ! V_84 -> V_249 &&
( V_19 -> V_239 . V_250 & V_251 ) )
V_84 -> V_97 = V_15 -> time ;
}
static int F_114 ( struct V_112 * V_113 ,
union V_105 * V_106 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_104 * V_104 V_171 )
{
struct V_84 * V_84 = F_57 ( V_113 , struct V_84 , V_113 ) ;
struct V_69 * V_69 ;
int V_122 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
V_69 = F_85 ( V_84 -> V_123 , V_15 -> V_173 , V_15 -> V_81 ) ;
if ( V_69 && F_115 ( V_69 ) )
return 0 ;
F_113 ( V_84 , V_19 , V_15 ) ;
if ( V_22 ) {
++ V_84 -> V_71 ;
V_22 ( V_84 , V_19 , V_106 , V_15 ) ;
}
return V_122 ;
}
static int F_116 ( struct V_84 * V_84 , int V_252 , const char * * V_253 )
{
unsigned int V_254 , V_151 , V_255 ;
const char * * V_256 ;
const char * const V_257 [] = {
L_87 ,
L_88 ,
L_89 , L_90 ,
L_91 , L_92 ,
} ;
const char * const V_258 [] = { L_93 , } ;
unsigned int V_259 = F_30 ( V_258 ) ;
const char * const V_260 [] = { L_93 , L_94 } ;
unsigned int V_261 = F_30 ( V_260 ) ;
const char * const V_262 [] = { L_93 , L_95 } ;
unsigned int V_263 = F_30 ( V_262 ) ;
V_254 = F_30 ( V_257 ) + V_259 + 1 +
V_261 + V_263 + V_252 ;
V_256 = calloc ( V_254 + 1 , sizeof( char * ) ) ;
if ( V_256 == NULL )
return - V_26 ;
V_255 = 0 ;
for ( V_151 = 0 ; V_151 < F_30 ( V_257 ) ; V_151 ++ )
V_256 [ V_255 ++ ] = V_257 [ V_151 ] ;
if ( V_84 -> V_227 ) {
for ( V_151 = 0 ; V_151 < V_259 ; V_151 ++ )
V_256 [ V_255 ++ ] = V_258 [ V_151 ] ;
if ( F_117 ( L_96 ) )
V_256 [ V_255 ++ ] = L_97 ;
else if ( F_117 ( L_98 ) )
V_256 [ V_255 ++ ] = L_99 ;
else {
F_98 ( L_100 ) ;
return - 1 ;
}
}
if ( V_84 -> V_264 & V_265 )
for ( V_151 = 0 ; V_151 < V_261 ; V_151 ++ )
V_256 [ V_255 ++ ] = V_260 [ V_151 ] ;
if ( V_84 -> V_264 & V_266 )
for ( V_151 = 0 ; V_151 < V_263 ; V_151 ++ )
V_256 [ V_255 ++ ] = V_262 [ V_151 ] ;
for ( V_151 = 0 ; V_151 < ( unsigned int ) V_252 ; V_151 ++ )
V_256 [ V_255 ++ ] = V_253 [ V_151 ] ;
return F_118 ( V_255 , V_256 , NULL ) ;
}
static bool F_119 ( struct V_120 * V_121 )
{
struct V_18 * V_19 = F_13 ( L_101 , L_102 ) ;
if ( F_14 ( V_19 ) )
return false ;
if ( F_5 ( V_19 , L_31 ) == NULL ) {
F_9 ( V_19 ) ;
return false ;
}
V_19 -> V_22 = F_99 ;
F_120 ( V_121 , V_19 ) ;
return true ;
}
static struct V_18 * F_121 ( T_4 V_240 )
{
struct V_18 * V_19 ;
struct V_267 V_239 = {
. type = V_268 ,
. V_269 = 1 ,
} ;
V_239 . V_240 = V_240 ;
V_239 . V_270 = 1 ;
F_122 ( & V_239 ) ;
V_19 = F_123 ( & V_239 ) ;
if ( V_19 )
V_19 -> V_22 = F_111 ;
return V_19 ;
}
static void F_124 ( struct V_84 * V_84 , union V_105 * V_106 , struct V_14 * V_15 )
{
const T_8 type = V_106 -> V_107 . type ;
struct V_18 * V_19 ;
if ( type != V_271 ) {
F_53 ( V_84 , V_84 -> V_123 , V_106 , V_15 ) ;
return;
}
V_19 = F_125 ( V_84 -> V_121 , V_15 -> V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_84 -> V_109 , L_103 V_110 L_104 , V_15 -> V_24 ) ;
return;
}
F_113 ( V_84 , V_19 , V_15 ) ;
if ( V_19 -> V_239 . type == V_272 &&
V_15 -> V_16 == NULL ) {
fprintf ( V_84 -> V_109 , L_105 ,
F_77 ( V_19 ) , V_15 -> V_81 ,
V_15 -> V_228 , V_15 -> V_226 ) ;
} else {
T_7 V_22 = V_19 -> V_22 ;
V_22 ( V_84 , V_19 , V_106 , V_15 ) ;
}
}
static int F_126 ( struct V_84 * V_84 )
{
int V_79 = - 1 ;
struct V_120 * V_121 = V_84 -> V_121 ;
struct V_18 * V_273 , * V_274 ;
V_273 = F_12 ( L_106 , F_83 ) ;
if ( V_273 == NULL )
goto V_158;
if ( F_127 ( V_273 , args ) )
goto V_275;
V_274 = F_12 ( L_107 , F_94 ) ;
if ( V_274 == NULL )
goto V_275;
if ( F_11 ( V_274 , V_79 ) )
goto V_276;
F_120 ( V_121 , V_273 ) ;
F_120 ( V_121 , V_274 ) ;
if ( V_277 . V_278 && ! V_84 -> V_279 ) {
V_274 -> V_239 . V_280 = 1 ;
}
V_84 -> V_143 . V_281 . V_273 = V_273 ;
V_84 -> V_143 . V_281 . V_274 = V_274 ;
V_79 = 0 ;
V_158:
return V_79 ;
V_276:
F_7 ( V_274 ) ;
V_275:
F_7 ( V_273 ) ;
goto V_158;
}
static int F_128 ( struct V_84 * V_84 )
{
int V_122 = - 1 ;
struct V_18 * V_274 ;
char * V_282 = F_129 ( L_108 , ! V_84 -> V_283 ,
V_84 -> V_154 . V_155 ,
V_84 -> V_154 . V_39 ) ;
if ( V_282 == NULL )
goto V_284;
if ( ! F_130 ( V_84 -> V_143 . V_281 . V_273 ,
V_282 ) ) {
V_274 = V_84 -> V_143 . V_281 . V_274 ;
V_122 = F_130 ( V_274 , V_282 ) ;
}
free ( V_282 ) ;
V_158:
return V_122 ;
V_284:
V_124 = V_26 ;
goto V_158;
}
static int F_131 ( struct V_84 * V_84 , int V_252 , const char * * V_253 )
{
struct V_120 * V_121 = V_84 -> V_121 ;
struct V_18 * V_19 , * V_285 = NULL , * V_286 = NULL ;
int V_122 = - 1 , V_151 ;
unsigned long V_287 ;
const bool V_288 = V_252 > 0 ;
bool V_289 = false ;
V_84 -> V_85 = true ;
if ( V_84 -> V_227 && F_126 ( V_84 ) )
goto V_290;
if ( V_84 -> V_227 )
V_84 -> V_93 = F_119 ( V_121 ) ;
if ( ( V_84 -> V_264 & V_265 ) ) {
V_285 = F_121 ( V_241 ) ;
if ( V_285 == NULL )
goto V_291;
F_120 ( V_121 , V_285 ) ;
}
if ( ( V_84 -> V_264 & V_266 ) ) {
V_286 = F_121 ( V_292 ) ;
if ( V_286 == NULL )
goto V_291;
F_120 ( V_121 , V_286 ) ;
}
if ( V_84 -> V_293 &&
F_132 ( V_121 , L_109 , L_110 ,
F_101 ) )
goto V_294;
V_122 = F_133 ( V_121 , & V_84 -> V_125 . V_126 ) ;
if ( V_122 < 0 ) {
fprintf ( V_84 -> V_109 , L_111 ) ;
goto V_295;
}
V_122 = F_61 ( V_84 , V_121 ) ;
if ( V_122 < 0 ) {
fprintf ( V_84 -> V_109 , L_112 ) ;
goto V_295;
}
F_134 ( V_121 , & V_84 -> V_125 , NULL ) ;
if ( V_277 . V_278 ) {
bool V_296 = false ;
if ( V_84 -> V_143 . V_281 . V_274 ) {
F_135 ( V_84 -> V_143 . V_281 . V_274 ,
& V_84 -> V_125 , & V_277 ) ;
V_296 = true ;
}
if ( V_285 ) {
F_135 ( V_285 , & V_84 -> V_125 , & V_277 ) ;
V_296 = true ;
}
if ( V_286 ) {
F_135 ( V_286 , & V_84 -> V_125 , & V_277 ) ;
V_296 = true ;
}
if ( V_296 ) {
F_136 ( V_121 , V_297 ) ;
F_137 ( V_121 , V_298 ) ;
}
}
signal ( V_299 , F_50 ) ;
signal ( V_101 , F_50 ) ;
if ( V_288 ) {
V_122 = F_138 ( V_121 , & V_84 -> V_125 . V_126 ,
V_253 , false , NULL ) ;
if ( V_122 < 0 ) {
fprintf ( V_84 -> V_109 , L_113 ) ;
goto V_295;
}
}
V_122 = F_139 ( V_121 ) ;
if ( V_122 < 0 )
goto V_300;
V_122 = F_140 () ;
if ( V_122 ) {
char V_301 [ V_302 ] ;
F_141 ( V_122 , V_301 , sizeof( V_301 ) ) ;
F_98 ( L_114 ,
V_301 ) ;
goto V_300;
}
if ( V_84 -> V_303 . V_155 > 0 )
V_122 = F_142 ( V_121 , V_84 -> V_303 . V_155 , V_84 -> V_303 . V_39 ) ;
else if ( F_143 ( V_121 -> V_127 , 0 ) == - 1 )
V_122 = F_144 ( V_121 , F_145 () ) ;
if ( V_122 < 0 )
goto V_291;
if ( V_84 -> V_154 . V_155 > 0 ) {
V_122 = F_128 ( V_84 ) ;
if ( V_122 < 0 )
goto V_304;
F_146 ( L_115 ,
V_84 -> V_143 . V_281 . V_274 -> V_282 ) ;
}
V_122 = F_147 ( V_121 , & V_19 ) ;
if ( V_122 < 0 )
goto V_305;
V_122 = F_148 ( V_121 , V_84 -> V_125 . V_306 , false ) ;
if ( V_122 < 0 )
goto V_307;
if ( ! F_149 ( & V_84 -> V_125 . V_126 ) && ! V_84 -> V_125 . V_308 )
F_150 ( V_121 ) ;
if ( V_288 )
F_151 ( V_121 ) ;
if ( V_84 -> V_125 . V_308 ) {
F_152 ( V_84 -> V_125 . V_308 * 1000 ) ;
F_150 ( V_121 ) ;
}
V_84 -> V_102 = F_143 ( V_121 -> V_127 , 0 ) == - 1 ||
V_121 -> V_127 -> V_155 > 1 ||
F_153 ( V_121 ) -> V_239 . V_309 ;
V_310:
V_287 = V_84 -> V_71 ;
for ( V_151 = 0 ; V_151 < V_121 -> V_311 ; V_151 ++ ) {
union V_105 * V_106 ;
while ( ( V_106 = F_154 ( V_121 , V_151 ) ) != NULL ) {
struct V_14 V_15 ;
++ V_84 -> V_71 ;
V_122 = F_155 ( V_121 , V_106 , & V_15 ) ;
if ( V_122 ) {
fprintf ( V_84 -> V_109 , L_116 , V_122 ) ;
goto V_312;
}
F_124 ( V_84 , V_106 , & V_15 ) ;
V_312:
F_156 ( V_121 , V_151 ) ;
if ( V_100 )
goto V_313;
if ( V_99 && ! V_289 ) {
F_157 ( V_121 ) ;
V_289 = true ;
}
}
}
if ( V_84 -> V_71 == V_287 ) {
int V_198 = V_99 ? 100 : - 1 ;
if ( ! V_289 && F_158 ( V_121 , V_198 ) > 0 ) {
if ( F_159 ( V_121 , V_314 | V_315 ) == 0 )
V_289 = true ;
goto V_310;
}
} else {
goto V_310;
}
V_313:
F_160 ( V_84 -> V_169 ) ;
F_157 ( V_121 ) ;
if ( ! V_122 ) {
if ( V_84 -> V_189 )
F_161 ( V_84 , V_84 -> V_109 ) ;
if ( V_84 -> V_316 ) {
fprintf ( V_84 -> V_109 , L_117
L_118 V_110 L_119
L_120 V_110 L_119 ,
V_84 -> V_86 . V_93 ,
V_84 -> V_86 . V_87 ) ;
}
}
V_295:
F_162 ( V_121 ) ;
V_84 -> V_121 = NULL ;
V_84 -> V_85 = false ;
return V_122 ;
{
char V_301 [ V_302 ] ;
V_294:
F_163 ( V_124 , V_301 , sizeof( V_301 ) , L_109 , L_110 ) ;
goto V_317;
V_290:
F_163 ( V_124 , V_301 , sizeof( V_301 ) , L_1 , L_121 ) ;
goto V_317;
V_307:
F_164 ( V_121 , V_124 , V_301 , sizeof( V_301 ) ) ;
goto V_317;
V_300:
F_165 ( V_121 , V_124 , V_301 , sizeof( V_301 ) ) ;
V_317:
fprintf ( V_84 -> V_109 , L_122 , V_301 ) ;
goto V_295;
V_305:
fprintf ( V_84 -> V_109 ,
L_123 ,
V_19 -> V_282 , F_77 ( V_19 ) , V_124 ,
F_95 ( V_124 , V_301 , sizeof( V_301 ) ) ) ;
goto V_295;
}
V_291:
fprintf ( V_84 -> V_109 , L_124 ) ;
goto V_295;
V_304:
fprintf ( V_84 -> V_109 , L_125 , V_124 , strerror ( V_124 ) ) ;
goto V_295;
}
static int F_166 ( struct V_84 * V_84 )
{
const struct V_318 V_319 [] = {
{ L_126 , F_99 , } ,
} ;
struct V_320 V_321 = {
. V_88 = V_322 ,
. V_43 = V_323 ,
. V_324 = V_84 -> V_324 ,
} ;
struct V_325 * V_326 ;
struct V_18 * V_19 ;
int V_122 = - 1 ;
V_84 -> V_113 . V_15 = F_114 ;
V_84 -> V_113 . V_327 = V_328 ;
V_84 -> V_113 . V_329 = V_330 ;
V_84 -> V_113 . V_331 = V_332 ;
V_84 -> V_113 . exit = V_333 ;
V_84 -> V_113 . V_334 = V_335 ;
V_84 -> V_113 . V_239 = V_336 ;
V_84 -> V_113 . V_337 = V_338 ;
V_84 -> V_113 . V_339 = V_340 ;
V_84 -> V_113 . V_341 = true ;
V_84 -> V_113 . V_342 = true ;
V_84 -> V_102 = true ;
V_326 = F_167 ( & V_321 , false , & V_84 -> V_113 ) ;
if ( V_326 == NULL )
return - 1 ;
if ( V_84 -> V_125 . V_126 . V_173 )
V_118 . V_343 = F_40 ( V_84 -> V_125 . V_126 . V_173 ) ;
if ( V_84 -> V_125 . V_126 . V_81 )
V_118 . V_344 = F_40 ( V_84 -> V_125 . V_126 . V_81 ) ;
if ( F_62 ( & V_326 -> V_107 . V_345 ) < 0 )
goto V_158;
V_84 -> V_123 = & V_326 -> V_346 . V_123 ;
V_122 = F_168 ( V_326 , V_319 ) ;
if ( V_122 )
goto V_158;
V_19 = F_169 ( V_326 -> V_121 ,
L_96 ) ;
if ( V_19 == NULL )
V_19 = F_169 ( V_326 -> V_121 ,
L_98 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_83 ) < 0 ||
F_127 ( V_19 , args ) ) ) {
F_98 ( L_127 ) ;
goto V_158;
}
V_19 = F_169 ( V_326 -> V_121 ,
L_128 ) ;
if ( V_19 == NULL )
V_19 = F_169 ( V_326 -> V_121 ,
L_129 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_94 ) < 0 ||
F_11 ( V_19 , V_79 ) ) ) {
F_98 ( L_130 ) ;
goto V_158;
}
F_170 (session->evlist, evsel) {
if ( V_19 -> V_239 . type == V_268 &&
( V_19 -> V_239 . V_240 == V_241 ||
V_19 -> V_239 . V_240 == V_292 ||
V_19 -> V_239 . V_240 == V_347 ) )
V_19 -> V_22 = F_111 ;
}
F_171 () ;
V_122 = F_172 ( V_326 ) ;
if ( V_122 )
F_98 ( L_131 , V_122 ) ;
else if ( V_84 -> V_189 )
F_161 ( V_84 , V_84 -> V_109 ) ;
V_158:
F_173 ( V_326 ) ;
return V_122 ;
}
static T_1 F_174 ( T_3 * V_58 )
{
T_1 V_42 ;
V_42 = fprintf ( V_58 , L_132 ) ;
return V_42 ;
}
static T_1 F_175 ( struct V_64 * V_65 ,
struct V_84 * V_84 , T_3 * V_58 )
{
T_1 V_42 = 0 ;
struct V_129 * V_130 ;
struct V_348 * V_349 ;
F_176 ( V_68 , V_65 -> V_68 ) ;
if ( V_68 == NULL )
return 0 ;
V_42 += fprintf ( V_58 , L_119 ) ;
V_42 += fprintf ( V_58 , L_133 ) ;
V_42 += fprintf ( V_58 , L_134 ) ;
V_42 += fprintf ( V_58 , L_135 ) ;
F_177 (nd, syscall_stats) {
struct V_86 * V_86 = V_350 -> V_86 ;
if ( V_86 ) {
double V_351 = ( double ) ( V_86 -> V_351 ) / V_60 ;
double V_67 = ( double ) ( V_86 -> V_67 ) / V_60 ;
double V_352 = F_178 ( V_86 ) ;
double V_353 ;
T_4 T_2 = ( T_4 ) V_86 -> T_2 ;
V_353 = V_352 ? 100.0 * F_179 ( V_86 ) / V_352 : 0.0 ;
V_352 /= V_60 ;
V_130 = & V_84 -> V_143 . V_74 [ V_350 -> V_129 ] ;
V_42 += fprintf ( V_58 , L_136 , V_130 -> V_20 ) ;
V_42 += fprintf ( V_58 , L_137 V_110 L_138 ,
T_2 , V_350 -> V_354 , V_351 , V_352 ) ;
V_42 += fprintf ( V_58 , L_139 , V_67 , V_353 ) ;
}
}
F_180 ( V_68 ) ;
V_42 += fprintf ( V_58 , L_140 ) ;
return V_42 ;
}
static T_1 F_181 ( T_3 * V_58 , struct V_69 * V_69 , struct V_84 * V_84 )
{
T_1 V_42 = 0 ;
struct V_64 * V_65 = F_37 ( V_69 ) ;
double V_355 ;
if ( V_65 == NULL )
return 0 ;
V_355 = ( double ) V_65 -> V_71 / V_84 -> V_71 * 100.0 ;
V_42 += fprintf ( V_58 , L_141 , F_52 ( V_69 ) , V_69 -> V_81 ) ;
V_42 += fprintf ( V_58 , L_142 , V_65 -> V_71 ) ;
V_42 += fprintf ( V_58 , L_143 , V_355 ) ;
if ( V_65 -> V_242 )
V_42 += fprintf ( V_58 , L_144 , V_65 -> V_242 ) ;
if ( V_65 -> V_243 )
V_42 += fprintf ( V_58 , L_145 , V_65 -> V_243 ) ;
if ( V_84 -> V_293 )
V_42 += fprintf ( V_58 , L_146 , V_65 -> V_209 ) ;
else if ( fputc ( '\n' , V_58 ) != V_356 )
++ V_42 ;
V_42 += F_175 ( V_65 , V_84 , V_58 ) ;
return V_42 ;
}
static unsigned long F_182 ( struct V_64 * V_65 )
{
return V_65 ? V_65 -> V_71 : 0 ;
}
static T_1 F_161 ( struct V_84 * V_84 , T_3 * V_58 )
{
F_183 ( V_127 , V_84 -> V_123 ) ;
T_1 V_42 = F_174 ( V_58 ) ;
struct V_348 * V_349 ;
if ( V_127 == NULL ) {
fprintf ( V_58 , L_3 , L_147 ) ;
return 0 ;
}
F_177 (nd, threads)
V_42 += F_181 ( V_58 , V_357 -> V_69 , V_84 ) ;
F_180 ( V_127 ) ;
return V_42 ;
}
static int F_184 ( const struct V_358 * V_359 , const char * V_360 ,
int T_9 V_171 )
{
struct V_84 * V_84 = V_359 -> V_361 ;
V_84 -> V_94 = atof ( V_360 ) ;
return 0 ;
}
static int F_185 ( const struct V_358 * V_359 , const char * V_360 ,
int T_9 V_171 )
{
int V_79 = - 1 ;
T_1 V_151 ;
struct V_84 * V_84 = V_359 -> V_361 ;
struct V_362 * V_363 = F_35 ( V_360 ) ;
if ( V_363 == NULL )
return - 1 ;
V_151 = V_84 -> V_303 . V_155 = F_186 ( V_363 ) + 1 ;
V_84 -> V_303 . V_39 = calloc ( V_151 , sizeof( V_211 ) ) ;
if ( V_84 -> V_303 . V_39 == NULL )
goto V_158;
V_84 -> V_303 . V_39 [ 0 ] = F_145 () ;
for ( V_151 = 1 ; V_151 < V_84 -> V_303 . V_155 ; ++ V_151 )
V_84 -> V_303 . V_39 [ V_151 ] = F_187 ( V_363 , V_151 - 1 ) -> V_151 ;
F_188 ( V_363 ) ;
V_79 = 0 ;
V_158:
return V_79 ;
}
static int F_189 ( struct V_84 * V_84 , const char * V_90 )
{
struct V_77 V_78 ;
if ( ! V_77 ( V_90 , & V_78 ) && V_78 . V_82 ) {
char V_364 [ V_76 ] ;
F_16 ( V_364 , sizeof( V_364 ) , L_148 , V_90 ) ;
F_190 ( V_364 ) ;
rename ( V_90 , V_364 ) ;
}
V_84 -> V_109 = fopen ( V_90 , L_149 ) ;
return V_84 -> V_109 == NULL ? - V_124 : 0 ;
}
static int F_191 ( const struct V_358 * V_359 , const char * V_360 ,
int T_9 V_171 )
{
int * V_264 = V_359 -> V_361 ;
if ( strcmp ( V_360 , L_150 ) == 0 )
* V_264 |= V_265 | V_266 ;
else if ( strcmp ( V_360 , L_83 ) == 0 )
* V_264 |= V_265 ;
else if ( strcmp ( V_360 , L_84 ) == 0 )
* V_264 |= V_266 ;
else
return - 1 ;
return 0 ;
}
static void F_192 ( struct V_120 * V_121 , void * V_22 )
{
struct V_18 * V_19 ;
F_170 (evlist, evsel)
V_19 -> V_22 = V_22 ;
}
static int F_193 ( const struct V_358 * V_359 , const char * V_360 ,
int T_9 V_171 )
{
struct V_84 * V_84 = (struct V_84 * ) V_359 -> V_361 ;
const char * V_159 = V_360 ;
char * V_365 = NULL , * V_366 [ 2 ] = { NULL , NULL , } ;
int V_131 = strlen ( V_360 ) , V_122 = - 1 , V_363 ;
char * V_367 = F_194 ( V_368 ) ;
char V_369 [ V_76 ] ;
if ( V_367 == NULL )
return - 1 ;
if ( * V_159 == '!' ) {
++ V_159 ;
V_84 -> V_283 = true ;
}
while ( 1 ) {
if ( ( V_365 = strchr ( V_159 , ',' ) ) != NULL )
* V_365 = '\0' ;
V_363 = 0 ;
if ( F_74 ( V_84 -> V_142 , V_159 ) >= 0 ) {
V_363 = 1 ;
} else {
F_195 ( V_369 , sizeof( V_369 ) , V_367 , V_159 ) ;
if ( F_196 ( V_369 , V_370 ) == 0 )
V_363 = 1 ;
}
if ( V_366 [ V_363 ] ) {
sprintf ( V_366 [ V_363 ] + strlen ( V_366 [ V_363 ] ) , L_151 , V_159 ) ;
} else {
V_366 [ V_363 ] = malloc ( V_131 ) ;
if ( V_366 [ V_363 ] == NULL )
goto V_158;
strcpy ( V_366 [ V_363 ] , V_159 ) ;
}
if ( ! V_365 )
break;
* V_365 = ',' ;
V_159 = V_365 + 1 ;
}
if ( V_366 [ 1 ] != NULL ) {
struct V_371 V_372 = {
. V_373 = V_367 ,
} ;
V_84 -> V_156 = F_197 ( V_366 [ 1 ] , & V_372 ) ;
if ( V_84 -> V_156 == NULL ) {
fputs ( L_152 , V_84 -> V_109 ) ;
goto V_158;
}
if ( F_71 ( V_84 ) )
goto V_158;
}
V_122 = 0 ;
if ( V_366 [ 0 ] ) {
struct V_358 V_374 = F_198 ( 'e' , L_153 , & V_84 -> V_121 , L_153 ,
L_154 ,
V_375 ) ;
V_122 = V_375 ( & V_374 , V_366 [ 0 ] , 0 ) ;
}
V_158:
if ( V_365 )
* V_365 = ',' ;
return V_122 ;
}
int F_199 ( int V_252 , const char * * V_253 , const char * T_10 V_171 )
{
const char * V_376 [] = {
L_155 ,
L_156 ,
L_157 ,
L_158 ,
NULL
} ;
struct V_84 V_84 = {
. V_143 = {
. V_67 = - 1 ,
} ,
. V_125 = {
. V_126 = {
. V_377 = V_378 ,
. V_379 = true ,
} ,
. V_380 = V_378 ,
. V_381 = V_382 ,
. V_383 = true ,
. V_306 = V_378 ,
. V_128 = 500 ,
} ,
. V_109 = V_384 ,
. V_103 = true ,
. V_227 = true ,
. V_279 = false ,
. V_183 = V_378 ,
} ;
const char * V_385 = NULL ;
const struct V_358 V_386 [] = {
F_198 ( 'e' , L_153 , & V_84 , L_153 ,
L_159 ,
F_193 ) ,
F_200 ( 0 , L_73 , & V_84 . V_103 ,
L_160 ) ,
F_200 ( 0 , L_161 , & V_84 . V_316 , L_162 ) ,
F_198 ( 0 , L_163 , & V_84 , L_163 , L_164 ,
F_193 ) ,
F_201 ( 'o' , L_165 , & V_385 , L_166 , L_167 ) ,
F_201 ( 'i' , L_168 , & V_322 , L_166 , L_169 ) ,
F_201 ( 'p' , L_74 , & V_84 . V_125 . V_126 . V_173 , L_74 ,
L_170 ) ,
F_201 ( 't' , L_171 , & V_84 . V_125 . V_126 . V_81 , L_171 ,
L_172 ) ,
F_198 ( 0 , L_173 , & V_84 , L_174 ,
L_175 , F_185 ) ,
F_200 ( 'a' , L_176 , & V_84 . V_125 . V_126 . V_387 ,
L_177 ) ,
F_201 ( 'C' , L_178 , & V_84 . V_125 . V_126 . V_388 , L_178 ,
L_179 ) ,
F_200 ( 0 , L_180 , & V_84 . V_125 . V_389 ,
L_181 ) ,
F_198 ( 'm' , L_182 , & V_84 . V_125 . V_306 , L_183 ,
L_184 ,
V_390 ) ,
F_201 ( 'u' , L_185 , & V_84 . V_125 . V_126 . V_391 , L_186 ,
L_187 ) ,
F_198 ( 0 , L_188 , & V_84 , L_189 ,
L_190 ,
F_184 ) ,
F_200 ( 0 , L_109 , & V_84 . V_293 , L_191 ) ,
F_202 ( 'v' , L_192 , & V_164 , L_193 ) ,
F_200 ( 'T' , L_194 , & V_84 . V_249 ,
L_195 ) ,
F_200 ( 's' , L_196 , & V_84 . V_176 ,
L_197 ) ,
F_200 ( 'S' , L_198 , & V_84 . V_189 ,
L_199 ) ,
F_203 ( 'F' , L_200 , & V_84 . V_264 , L_201 ,
L_202 , F_191 , L_83 ) ,
F_200 ( 0 , L_2 , & V_84 . V_227 , L_203 ) ,
F_200 ( 'f' , L_204 , & V_84 . V_324 , L_205 ) ,
F_198 ( 0 , L_206 , & V_84 . V_125 ,
L_207 , V_392 ,
& V_393 ) ,
F_200 ( 0 , L_208 , & V_84 . V_279 ,
L_209 ) ,
F_204 ( 0 , L_210 , & V_84 . V_177 ,
L_211
L_212 ) ,
F_204 ( 0 , L_213 , & V_84 . V_183 ,
L_214
L_215
L_216 F_205 ( V_394 ) ) ,
F_204 ( 0 , L_217 , & V_84 . V_125 . V_128 ,
L_218 ) ,
F_204 ( 'D' , L_219 , & V_84 . V_125 . V_308 ,
L_220
L_221 ) ,
F_206 ()
} ;
bool V_171 V_395 = true ;
bool V_396 = true ;
const char * const V_397 [] = { L_87 , NULL } ;
int V_122 ;
char V_29 [ V_302 ] ;
signal ( V_398 , V_399 ) ;
signal ( V_400 , V_399 ) ;
V_84 . V_121 = F_207 () ;
V_84 . V_142 = F_208 () ;
if ( V_84 . V_121 == NULL || V_84 . V_142 == NULL ) {
F_98 ( L_124 ) ;
V_122 = - V_26 ;
goto V_158;
}
V_252 = F_209 ( V_252 , V_253 , V_386 , V_397 ,
V_376 , V_401 ) ;
V_122 = F_210 ( V_84 . V_121 ) ;
if ( V_122 ) {
F_211 ( V_84 . V_121 , V_122 , V_29 , sizeof( V_29 ) ) ;
F_98 ( L_222 , V_29 ) ;
goto V_158;
}
V_122 = - 1 ;
if ( V_84 . V_264 ) {
V_84 . V_125 . V_402 = true ;
V_84 . V_125 . V_403 = true ;
}
if ( V_84 . V_125 . V_306 == V_378 )
V_396 = false ;
if ( V_84 . V_183 == V_378 ) {
V_84 . V_183 = V_322 ? V_394 : V_404 ;
V_395 = false ;
}
#ifdef F_212
if ( ( V_84 . V_177 || V_395 ) && ! V_277 . V_278 && V_84 . V_227 )
F_213 ( & V_84 . V_125 , & V_277 , L_223 , false ) ;
#endif
if ( V_277 . V_278 ) {
if ( ! V_396 && F_214 () == 0 )
V_84 . V_125 . V_306 = F_215 () * 4 ;
V_118 . V_405 = true ;
}
if ( V_84 . V_121 -> V_38 > 0 )
F_192 ( V_84 . V_121 , F_107 ) ;
if ( ( V_252 >= 1 ) && ( strcmp ( V_253 [ 0 ] , L_87 ) == 0 ) )
return F_116 ( & V_84 , V_252 - 1 , & V_253 [ 1 ] ) ;
if ( V_84 . V_176 )
V_84 . V_189 = V_84 . V_176 ;
if ( ! V_84 . V_227 && ! V_84 . V_264 &&
V_84 . V_121 -> V_38 == 0 ) {
F_98 ( L_224 ) ;
return - 1 ;
}
if ( ! V_84 . V_227 && V_84 . V_156 ) {
F_98 ( L_225 ) ;
goto V_158;
}
if ( V_385 != NULL ) {
V_122 = F_189 ( & V_84 , V_385 ) ;
if ( V_122 < 0 ) {
perror ( L_226 ) ;
goto V_158;
}
}
V_84 . V_190 = F_74 ( V_84 . V_142 , L_227 ) ;
V_122 = F_216 ( & V_84 . V_125 . V_126 ) ;
if ( V_122 ) {
F_217 ( & V_84 . V_125 . V_126 , V_122 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_84 . V_109 , L_3 , V_29 ) ;
goto V_406;
}
V_122 = F_218 ( & V_84 . V_125 . V_126 ) ;
if ( V_122 ) {
F_217 ( & V_84 . V_125 . V_126 , V_122 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_84 . V_109 , L_3 , V_29 ) ;
goto V_406;
}
if ( ! V_252 && F_149 ( & V_84 . V_125 . V_126 ) )
V_84 . V_125 . V_126 . V_387 = true ;
if ( V_322 )
V_122 = F_166 ( & V_84 ) ;
else
V_122 = F_131 ( & V_84 , V_252 , V_253 ) ;
V_406:
if ( V_385 != NULL )
fclose ( V_84 . V_109 ) ;
V_158:
return V_122 ;
}
