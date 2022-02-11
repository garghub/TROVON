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
T_1 F_15 ( struct V_29 * V_30 , char * V_31 , T_1 V_6 , const char * V_32 , int V_33 )
{
int V_34 = V_33 - V_30 -> V_5 ;
if ( V_34 < 0 || V_34 >= V_30 -> V_35 )
return F_16 ( V_31 , V_6 , V_32 , V_33 ) ;
return F_16 ( V_31 , V_6 , L_3 , V_30 -> V_36 [ V_34 ] ) ;
}
static T_1 F_17 ( char * V_31 , T_1 V_6 ,
const char * V_32 ,
struct V_37 * V_38 )
{
return F_15 ( V_38 -> V_39 , V_31 , V_6 , V_32 , V_38 -> V_33 ) ;
}
static T_1 F_18 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
return F_17 ( V_31 , V_6 , L_4 , V_38 ) ;
}
T_1 F_19 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
struct V_40 * V_41 = V_38 -> V_39 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_41 -> V_35 ; ++ V_42 ) {
struct V_29 * V_30 = V_41 -> V_36 [ V_42 ] ;
int V_34 = V_38 -> V_33 - V_30 -> V_5 ;
if ( V_34 >= 0 && V_34 < V_30 -> V_35 ) {
if ( V_30 -> V_36 [ V_34 ] == NULL )
break;
return F_16 ( V_31 , V_6 , L_3 , V_30 -> V_36 [ V_34 ] ) ;
}
}
return F_16 ( V_31 , V_6 , L_4 , V_38 -> V_33 ) ;
}
static T_1 F_20 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
int V_43 = V_38 -> V_33 ;
if ( V_43 == V_44 )
return F_16 ( V_31 , V_6 , L_5 ) ;
return F_21 ( V_31 , V_6 , V_38 ) ;
}
T_1 F_22 ( char * V_31 , T_1 V_6 , struct V_37 * V_38 )
{
return F_16 ( V_31 , V_6 , L_6 , V_38 -> V_33 ) ;
}
T_1 F_23 ( char * V_31 , T_1 V_6 , struct V_37 * V_38 )
{
return F_16 ( V_31 , V_6 , L_4 , V_38 -> V_33 ) ;
}
T_1 F_24 ( char * V_31 , T_1 V_6 , struct V_37 * V_38 )
{
return F_16 ( V_31 , V_6 , L_7 , V_38 -> V_33 ) ;
}
static T_1 F_25 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
T_1 V_45 = 0 ;
int V_46 = V_38 -> V_33 ;
if ( V_46 == V_47 )
return F_16 ( V_31 , V_6 , L_8 ) ;
#define F_26 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_26 ( V_48 ) ;
F_26 ( V_49 ) ;
F_26 ( V_50 ) ;
#undef F_26
if ( V_46 )
V_45 += F_16 ( V_31 + V_45 , V_6 - V_45 , L_9 , V_46 ) ;
return V_45 ;
}
static T_1 F_27 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
int V_45 = 0 , V_51 = V_38 -> V_33 ;
#define F_28 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_28 ( V_52 ) ;
F_28 ( V_53 ) ;
#undef F_28
if ( V_51 )
V_45 += F_16 ( V_31 + V_45 , V_6 - V_45 , L_10 , V_45 ? L_11 : L_12 , V_51 ) ;
return V_45 ;
}
static T_1 F_29 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
int V_45 = 0 , V_51 = V_38 -> V_33 ;
#define F_28 ( T_2 ) \
if (flags & GRND_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~GRND_##n; \
}
F_28 ( V_54 ) ;
F_28 ( V_53 ) ;
#undef F_28
if ( V_51 )
V_45 += F_16 ( V_31 + V_45 , V_6 - V_45 , L_10 , V_45 ? L_11 : L_12 , V_51 ) ;
return V_45 ;
}
static int F_30 ( const void * V_20 , const void * V_55 )
{
const struct V_56 * V_57 = V_55 ;
return strcmp ( V_20 , V_57 -> V_20 ) ;
}
static struct V_56 * F_31 ( const char * V_20 )
{
const int V_58 = F_32 ( V_59 ) ;
return bsearch ( V_20 , V_59 , V_58 , sizeof( struct V_56 ) , F_30 ) ;
}
static T_1 F_33 ( unsigned long V_60 , bool V_61 , T_3 * V_62 )
{
double V_63 = ( double ) V_60 / V_64 ;
T_1 V_45 = fprintf ( V_62 , L_13 ) ;
if ( ! V_61 )
V_45 += fprintf ( V_62 , L_14 ) ;
else if ( V_63 >= 1.0 )
V_45 += F_34 ( V_62 , V_65 , L_15 , V_63 ) ;
else if ( V_63 >= 0.01 )
V_45 += F_34 ( V_62 , V_66 , L_15 , V_63 ) ;
else
V_45 += F_34 ( V_62 , V_67 , L_15 , V_63 ) ;
return V_45 + fprintf ( V_62 , L_16 ) ;
}
static struct V_68 * F_35 ( void )
{
struct V_68 * V_69 = F_36 ( sizeof( struct V_68 ) ) ;
if ( V_69 )
V_69 -> V_70 . V_71 = - 1 ;
V_69 -> V_72 = F_37 ( NULL ) ;
return V_69 ;
}
static struct V_68 * F_38 ( struct V_73 * V_73 , T_3 * V_62 )
{
struct V_68 * V_69 ;
if ( V_73 == NULL )
goto V_74;
if ( F_39 ( V_73 ) == NULL )
F_40 ( V_73 , F_35 () ) ;
if ( F_39 ( V_73 ) == NULL )
goto V_74;
V_69 = F_39 ( V_73 ) ;
++ V_69 -> V_75 ;
return V_69 ;
V_74:
F_34 ( V_62 , V_65 ,
L_17 ) ;
return NULL ;
}
void F_41 ( struct V_37 * V_38 ,
T_1 (* F_42)( char * V_31 , T_1 V_6 , struct V_37 * V_38 ) )
{
struct V_68 * V_69 = F_39 ( V_38 -> V_73 ) ;
V_69 -> F_42 = F_42 ;
}
static int F_43 ( struct V_73 * V_73 , int V_43 , const char * V_76 )
{
struct V_68 * V_69 = F_39 ( V_73 ) ;
if ( V_43 > V_69 -> V_70 . V_71 ) {
char * * V_77 = realloc ( V_69 -> V_70 . V_78 , ( V_43 + 1 ) * sizeof( char * ) ) ;
if ( V_77 == NULL )
return - 1 ;
if ( V_69 -> V_70 . V_71 != - 1 ) {
memset ( V_77 + V_69 -> V_70 . V_71 + 1 , 0 ,
( V_43 - V_69 -> V_70 . V_71 ) * sizeof( char * ) ) ;
} else {
memset ( V_77 , 0 , ( V_43 + 1 ) * sizeof( char * ) ) ;
}
V_69 -> V_70 . V_78 = V_77 ;
V_69 -> V_70 . V_71 = V_43 ;
}
V_69 -> V_70 . V_78 [ V_43 ] = F_44 ( V_76 ) ;
return V_69 -> V_70 . V_78 [ V_43 ] != NULL ? 0 : - 1 ;
}
static int F_45 ( struct V_73 * V_73 , int V_43 )
{
char V_79 [ V_80 ] , V_76 [ V_80 ] ;
struct V_81 V_82 ;
int V_83 ;
if ( V_73 -> V_84 == V_73 -> V_85 ) {
F_16 ( V_79 , sizeof( V_79 ) ,
L_18 , V_73 -> V_84 , V_43 ) ;
} else {
F_16 ( V_79 , sizeof( V_79 ) ,
L_19 , V_73 -> V_84 , V_73 -> V_85 , V_43 ) ;
}
if ( F_46 ( V_79 , & V_82 ) < 0 || V_82 . V_86 + 1 > ( V_87 ) sizeof( V_76 ) )
return - 1 ;
V_83 = F_47 ( V_79 , V_76 , sizeof( V_76 ) ) ;
if ( V_83 < 0 || V_83 > V_82 . V_86 )
return - 1 ;
V_76 [ V_83 ] = '\0' ;
return F_43 ( V_73 , V_43 , V_76 ) ;
}
static const char * F_48 ( struct V_73 * V_73 , int V_43 ,
struct V_88 * V_88 )
{
struct V_68 * V_69 = F_39 ( V_73 ) ;
if ( V_69 == NULL )
return NULL ;
if ( V_43 < 0 )
return NULL ;
if ( ( V_43 > V_69 -> V_70 . V_71 || V_69 -> V_70 . V_78 [ V_43 ] == NULL ) ) {
if ( ! V_88 -> V_89 )
return NULL ;
++ V_88 -> V_90 . V_91 ;
if ( F_45 ( V_73 , V_43 ) )
return NULL ;
}
return V_69 -> V_70 . V_78 [ V_43 ] ;
}
T_1 F_21 ( char * V_31 , T_1 V_6 , struct V_37 * V_38 )
{
int V_43 = V_38 -> V_33 ;
T_1 V_45 = F_16 ( V_31 , V_6 , L_4 , V_43 ) ;
const char * V_92 = F_48 ( V_38 -> V_73 , V_43 , V_38 -> V_88 ) ;
if ( V_92 )
V_45 += F_16 ( V_31 + V_45 , V_6 - V_45 , L_20 , V_92 ) ;
return V_45 ;
}
static T_1 F_49 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
int V_43 = V_38 -> V_33 ;
T_1 V_45 = F_21 ( V_31 , V_6 , V_38 ) ;
struct V_68 * V_69 = F_39 ( V_38 -> V_73 ) ;
if ( V_69 && V_43 >= 0 && V_43 <= V_69 -> V_70 . V_71 )
F_8 ( & V_69 -> V_70 . V_78 [ V_43 ] ) ;
return V_45 ;
}
static void F_50 ( struct V_73 * V_73 , const char * V_31 ,
unsigned long V_93 )
{
struct V_68 * V_69 = F_39 ( V_73 ) ;
V_69 -> V_94 . V_93 = V_93 ;
V_69 -> V_94 . V_95 = V_31 - V_69 -> V_96 ;
}
static T_1 F_51 ( char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
unsigned long V_93 = V_38 -> V_33 ;
if ( ! V_38 -> V_88 -> V_97 )
return F_16 ( V_31 , V_6 , L_21 , V_93 ) ;
F_50 ( V_38 -> V_73 , V_31 , V_93 ) ;
return 0 ;
}
static bool F_52 ( struct V_88 * V_88 , double V_60 )
{
return V_60 < ( V_88 -> V_98 * V_64 ) ;
}
static T_1 F_53 ( struct V_88 * V_88 , T_4 V_99 , T_3 * V_62 )
{
double V_100 = ( double ) ( V_99 - V_88 -> V_101 ) / V_64 ;
return fprintf ( V_62 , L_22 , V_100 ) ;
}
static T_1 F_54 ( struct V_88 * V_88 , T_4 V_99 , T_3 * V_62 )
{
if ( V_99 > 0 )
return F_53 ( V_88 , V_99 , V_62 ) ;
return fprintf ( V_62 , L_23 ) ;
}
static void F_55 ( int V_102 )
{
V_103 = true ;
V_104 = V_102 == V_105 ;
}
static T_1 F_56 ( struct V_88 * V_88 , struct V_73 * V_73 ,
T_4 V_63 , bool V_106 , T_4 V_99 , T_3 * V_62 )
{
T_1 V_45 = F_54 ( V_88 , V_99 , V_62 ) ;
V_45 += F_33 ( V_63 , V_106 , V_62 ) ;
if ( V_88 -> V_107 ) {
if ( V_88 -> V_108 )
V_45 += fprintf ( V_62 , L_24 , F_57 ( V_73 ) ) ;
V_45 += fprintf ( V_62 , L_25 , V_73 -> V_85 ) ;
}
return V_45 ;
}
static int F_58 ( struct V_88 * V_88 , struct V_109 * V_109 ,
union V_110 * V_111 , struct V_14 * V_15 )
{
int V_83 = 0 ;
switch ( V_111 -> V_112 . type ) {
case V_113 :
F_34 ( V_88 -> V_114 , V_65 ,
L_26 V_115 L_27 , V_111 -> V_116 . V_116 ) ;
V_83 = F_59 ( V_109 , V_111 , V_15 ) ;
break;
default:
V_83 = F_60 ( V_109 , V_111 , V_15 ) ;
break;
}
return V_83 ;
}
static int F_61 ( struct V_117 * V_118 ,
union V_110 * V_111 ,
struct V_14 * V_15 ,
struct V_109 * V_109 )
{
struct V_88 * V_88 = F_62 ( V_118 , struct V_88 , V_118 ) ;
return F_58 ( V_88 , V_109 , V_111 , V_15 ) ;
}
static char * F_63 ( void * V_119 , unsigned long long * V_120 , char * * V_121 )
{
struct V_109 * V_109 = V_119 ;
if ( V_109 -> V_122 )
return NULL ;
if ( V_123 . V_124 ) {
F_64 ( L_28
L_29
L_30 ) ;
V_109 -> V_122 = true ;
return NULL ;
}
return F_65 ( V_119 , V_120 , V_121 ) ;
}
static int F_66 ( struct V_88 * V_88 , struct V_125 * V_126 )
{
int V_127 = F_67 ( NULL ) ;
if ( V_127 )
return V_127 ;
V_88 -> V_128 = F_68 () ;
if ( V_88 -> V_128 == NULL )
return - V_26 ;
if ( F_69 ( V_88 -> V_128 , F_63 ) < 0 )
return - V_129 ;
V_127 = F_70 ( V_88 -> V_128 , & V_88 -> V_118 , & V_88 -> V_130 . V_131 ,
V_126 -> V_132 , F_61 , false ,
V_88 -> V_130 . V_133 ) ;
if ( V_127 )
F_71 () ;
return V_127 ;
}
static void F_72 ( struct V_88 * V_88 )
{
F_73 ( V_88 -> V_128 ) ;
V_88 -> V_128 = NULL ;
F_71 () ;
}
static int F_74 ( struct V_134 * V_135 , int V_136 )
{
int V_34 ;
if ( V_136 == 6 && V_135 -> V_57 && V_135 -> V_57 -> V_136 != 0 )
V_136 = V_135 -> V_57 -> V_136 ;
V_135 -> V_137 = calloc ( V_136 , sizeof( * V_135 -> V_137 ) ) ;
if ( V_135 -> V_137 == NULL )
return - 1 ;
for ( V_34 = 0 ; V_34 < V_136 ; ++ V_34 ) {
if ( V_135 -> V_57 )
V_135 -> V_137 [ V_34 ] = V_135 -> V_57 -> V_38 [ V_34 ] ;
}
V_135 -> V_136 = V_136 ;
return 0 ;
}
static int F_75 ( struct V_134 * V_135 )
{
struct V_3 * V_2 ;
int V_34 = 0 , V_138 ;
for ( V_2 = V_135 -> args ; V_2 ; V_2 = V_2 -> V_139 , ++ V_34 ) {
if ( V_135 -> V_57 && V_135 -> V_57 -> V_38 [ V_34 ] . F_16 )
continue;
if ( strcmp ( V_2 -> type , L_31 ) == 0 &&
( strcmp ( V_2 -> V_20 , L_32 ) == 0 ||
strcmp ( V_2 -> V_20 , L_33 ) == 0 ||
strcmp ( V_2 -> V_20 , L_34 ) == 0 ) )
V_135 -> V_137 [ V_34 ] . F_16 = V_140 ;
else if ( V_2 -> V_51 & V_141 )
V_135 -> V_137 [ V_34 ] . F_16 = F_22 ;
else if ( strcmp ( V_2 -> type , L_35 ) == 0 )
V_135 -> V_137 [ V_34 ] . F_16 = V_142 ;
else if ( strcmp ( V_2 -> type , L_36 ) == 0 )
V_135 -> V_137 [ V_34 ] . F_16 = V_143 ;
else if ( ( strcmp ( V_2 -> type , L_37 ) == 0 ||
strcmp ( V_2 -> type , L_38 ) == 0 ||
strcmp ( V_2 -> type , L_39 ) == 0 ) &&
( V_138 = strlen ( V_2 -> V_20 ) ) >= 2 &&
strcmp ( V_2 -> V_20 + V_138 - 2 , L_40 ) == 0 ) {
V_135 -> V_137 [ V_34 ] . F_16 = V_144 ;
}
}
return 0 ;
}
static int F_76 ( struct V_88 * V_88 , int V_24 )
{
char V_145 [ 128 ] ;
struct V_134 * V_135 ;
const char * V_20 = F_77 ( V_88 -> V_146 , V_24 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_88 -> V_147 . V_71 ) {
struct V_134 * V_148 = realloc ( V_88 -> V_147 . V_78 , ( V_24 + 1 ) * sizeof( * V_135 ) ) ;
if ( V_148 == NULL )
return - 1 ;
if ( V_88 -> V_147 . V_71 != - 1 ) {
memset ( V_148 + V_88 -> V_147 . V_71 + 1 , 0 ,
( V_24 - V_88 -> V_147 . V_71 ) * sizeof( * V_135 ) ) ;
} else {
memset ( V_148 , 0 , ( V_24 + 1 ) * sizeof( * V_135 ) ) ;
}
V_88 -> V_147 . V_78 = V_148 ;
V_88 -> V_147 . V_71 = V_24 ;
}
V_135 = V_88 -> V_147 . V_78 + V_24 ;
V_135 -> V_20 = V_20 ;
V_135 -> V_57 = F_31 ( V_135 -> V_20 ) ;
snprintf ( V_145 , sizeof( V_145 ) , L_41 , V_135 -> V_20 ) ;
V_135 -> V_149 = F_78 ( L_2 , V_145 ) ;
if ( F_14 ( V_135 -> V_149 ) && V_135 -> V_57 && V_135 -> V_57 -> V_150 ) {
snprintf ( V_145 , sizeof( V_145 ) , L_41 , V_135 -> V_57 -> V_150 ) ;
V_135 -> V_149 = F_78 ( L_2 , V_145 ) ;
}
if ( F_74 ( V_135 , F_14 ( V_135 -> V_149 ) ? 6 : V_135 -> V_149 -> V_151 . V_152 ) )
return - 1 ;
if ( F_14 ( V_135 -> V_149 ) )
return - 1 ;
V_135 -> args = V_135 -> V_149 -> V_151 . V_153 ;
if ( V_135 -> args && ( ! strcmp ( V_135 -> args -> V_20 , L_42 ) || ! strcmp ( V_135 -> args -> V_20 , L_43 ) ) ) {
V_135 -> args = V_135 -> args -> V_139 ;
-- V_135 -> V_136 ;
}
V_135 -> V_154 = ! strcmp ( V_20 , L_44 ) || ! strcmp ( V_20 , L_45 ) ;
return F_75 ( V_135 ) ;
}
static int F_79 ( struct V_88 * V_88 )
{
int V_127 = 0 , V_42 ;
T_1 V_155 ;
struct V_156 * V_157 ;
V_88 -> V_158 . V_159 = F_80 ( V_88 -> V_160 ) ;
V_88 -> V_158 . V_36 = malloc ( V_88 -> V_158 . V_159 *
sizeof( V_88 -> V_158 . V_36 [ 0 ] ) ) ;
if ( V_88 -> V_158 . V_36 == NULL ) {
fputs ( L_46 ,
V_88 -> V_114 ) ;
V_127 = - V_161 ;
goto V_162;
}
V_155 = V_88 -> V_158 . V_159 ;
V_42 = 0 ;
F_81 (pos, trace->ev_qualifier) {
const char * V_135 = V_157 -> V_163 ;
int V_24 = F_82 ( V_88 -> V_146 , V_135 ) , V_164 = - 1 ;
if ( V_24 < 0 ) {
V_24 = F_83 ( V_88 -> V_146 , V_135 , & V_164 ) ;
if ( V_24 >= 0 )
goto V_165;
if ( V_127 == 0 ) {
fputs ( L_47 , V_88 -> V_114 ) ;
V_127 = - V_161 ;
} else {
fputs ( L_48 , V_88 -> V_114 ) ;
}
fputs ( V_135 , V_88 -> V_114 ) ;
}
V_165:
V_88 -> V_158 . V_36 [ V_42 ++ ] = V_24 ;
if ( V_164 == - 1 )
continue;
while ( 1 ) {
V_24 = F_84 ( V_88 -> V_146 , V_135 , & V_164 ) ;
if ( V_24 < 0 )
break;
if ( V_155 == V_88 -> V_158 . V_159 ) {
void * V_36 ;
V_155 += 8 ;
V_36 = realloc ( V_88 -> V_158 . V_36 ,
V_155 * sizeof( V_88 -> V_158 . V_36 [ 0 ] ) ) ;
if ( V_36 == NULL ) {
V_127 = - V_26 ;
fputs ( L_49 , V_88 -> V_114 ) ;
goto V_166;
}
V_88 -> V_158 . V_36 = V_36 ;
}
V_88 -> V_158 . V_159 ++ ;
V_88 -> V_158 . V_36 [ V_42 ++ ] = V_24 ;
}
}
if ( V_127 < 0 ) {
fputs ( L_50
L_51 , V_88 -> V_114 ) ;
V_166:
F_8 ( & V_88 -> V_158 . V_36 ) ;
V_88 -> V_158 . V_159 = 0 ;
}
V_162:
return V_127 ;
}
unsigned long F_85 ( struct V_37 * V_38 , T_5 V_34 )
{
unsigned long V_33 ;
unsigned char * V_167 = V_38 -> args + sizeof( unsigned long ) * V_34 ;
memcpy ( & V_33 , V_167 , sizeof( V_33 ) ) ;
return V_33 ;
}
static T_1 F_86 ( struct V_134 * V_135 , char * V_31 , T_1 V_6 ,
struct V_37 * V_38 )
{
if ( V_135 -> V_137 && V_135 -> V_137 [ V_38 -> V_34 ] . V_20 )
return F_16 ( V_31 , V_6 , L_52 , V_135 -> V_137 [ V_38 -> V_34 ] . V_20 ) ;
return F_16 ( V_31 , V_6 , L_53 , V_38 -> V_34 ) ;
}
static T_1 F_87 ( struct V_134 * V_135 , char * V_31 , T_1 V_6 ,
struct V_37 * V_38 , unsigned long V_33 )
{
if ( V_135 -> V_137 && V_135 -> V_137 [ V_38 -> V_34 ] . F_16 ) {
V_38 -> V_33 = V_33 ;
if ( V_135 -> V_137 [ V_38 -> V_34 ] . V_39 )
V_38 -> V_39 = V_135 -> V_137 [ V_38 -> V_34 ] . V_39 ;
return V_135 -> V_137 [ V_38 -> V_34 ] . F_16 ( V_31 , V_6 , V_38 ) ;
}
return F_16 ( V_31 , V_6 , L_7 , V_33 ) ;
}
static T_1 F_88 ( struct V_134 * V_135 , char * V_31 , T_1 V_6 ,
unsigned char * args , struct V_88 * V_88 ,
struct V_73 * V_73 )
{
T_1 V_45 = 0 ;
unsigned long V_33 ;
T_5 V_168 = 1 ;
struct V_37 V_38 = {
. args = args ,
. V_34 = 0 ,
. V_169 = 0 ,
. V_88 = V_88 ,
. V_73 = V_73 ,
} ;
struct V_68 * V_69 = F_39 ( V_73 ) ;
V_69 -> F_42 = NULL ;
if ( V_135 -> args != NULL ) {
struct V_3 * V_2 ;
for ( V_2 = V_135 -> args ; V_2 ;
V_2 = V_2 -> V_139 , ++ V_38 . V_34 , V_168 <<= 1 ) {
if ( V_38 . V_169 & V_168 )
continue;
V_33 = F_85 ( & V_38 , V_38 . V_34 ) ;
if ( V_33 == 0 &&
! ( V_135 -> V_137 &&
( V_135 -> V_137 [ V_38 . V_34 ] . V_170 ||
V_135 -> V_137 [ V_38 . V_34 ] . F_16 == V_171 ||
V_135 -> V_137 [ V_38 . V_34 ] . F_16 == V_172 ) &&
V_135 -> V_137 [ V_38 . V_34 ] . V_39 ) )
continue;
V_45 += F_16 ( V_31 + V_45 , V_6 - V_45 ,
L_54 , V_45 ? L_48 : L_12 , V_2 -> V_20 ) ;
V_45 += F_87 ( V_135 , V_31 + V_45 , V_6 - V_45 , & V_38 , V_33 ) ;
}
} else if ( F_14 ( V_135 -> V_149 ) ) {
while ( V_38 . V_34 < V_135 -> V_136 ) {
if ( V_38 . V_169 & V_168 )
goto V_173;
V_33 = F_85 ( & V_38 , V_38 . V_34 ) ;
if ( V_45 )
V_45 += F_16 ( V_31 + V_45 , V_6 - V_45 , L_48 ) ;
V_45 += F_86 ( V_135 , V_31 + V_45 , V_6 - V_45 , & V_38 ) ;
V_45 += F_87 ( V_135 , V_31 + V_45 , V_6 - V_45 , & V_38 , V_33 ) ;
V_173:
++ V_38 . V_34 ;
V_168 <<= 1 ;
}
}
return V_45 ;
}
static struct V_134 * F_89 ( struct V_88 * V_88 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_174 > 1 ) {
static T_4 T_2 ;
fprintf ( V_88 -> V_114 , L_55 V_115 L_56 ,
V_24 , F_90 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_88 -> V_147 . V_71 || V_88 -> V_147 . V_78 [ V_24 ] . V_20 == NULL ) &&
F_76 ( V_88 , V_24 ) )
goto V_175;
if ( ( V_24 > V_88 -> V_147 . V_71 || V_88 -> V_147 . V_78 [ V_24 ] . V_20 == NULL ) )
goto V_175;
return & V_88 -> V_147 . V_78 [ V_24 ] ;
V_175:
if ( V_174 > 0 ) {
fprintf ( V_88 -> V_114 , L_57 , V_24 ) ;
if ( V_24 <= V_88 -> V_147 . V_71 && V_88 -> V_147 . V_78 [ V_24 ] . V_20 != NULL )
fprintf ( V_88 -> V_114 , L_58 , V_88 -> V_147 . V_78 [ V_24 ] . V_20 ) ;
fputs ( L_59 , V_88 -> V_114 ) ;
}
return NULL ;
}
static void F_91 ( struct V_68 * V_69 ,
int V_24 , struct V_14 * V_15 )
{
struct V_176 * V_177 ;
struct V_90 * V_90 ;
T_4 V_63 = 0 ;
V_177 = F_92 ( V_69 -> V_72 , V_24 ) ;
if ( V_177 == NULL )
return;
V_90 = V_177 -> V_21 ;
if ( V_90 == NULL ) {
V_90 = malloc ( sizeof( struct V_90 ) ) ;
if ( V_90 == NULL )
return;
F_93 ( V_90 ) ;
V_177 -> V_21 = V_90 ;
}
if ( V_69 -> V_178 && V_15 -> time > V_69 -> V_178 )
V_63 = V_15 -> time - V_69 -> V_178 ;
F_94 ( V_90 , V_63 ) ;
}
static int F_95 ( struct V_88 * V_88 , struct V_14 * V_15 )
{
struct V_68 * V_69 ;
T_4 V_63 ;
T_1 V_45 ;
if ( V_88 -> V_179 == NULL )
return 0 ;
V_69 = F_39 ( V_88 -> V_179 ) ;
if ( ! V_69 -> V_180 )
return 0 ;
V_63 = V_15 -> time - V_69 -> V_178 ;
V_45 = F_56 ( V_88 , V_88 -> V_179 , V_63 , true , V_69 -> V_178 , V_88 -> V_114 ) ;
V_45 += fprintf ( V_88 -> V_114 , L_60 , V_69 -> V_96 ) ;
V_69 -> V_180 = false ;
return V_45 ;
}
static int F_96 ( struct V_88 * V_88 , struct V_18 * V_19 ,
union V_110 * V_111 V_181 ,
struct V_14 * V_15 )
{
char * V_182 ;
void * args ;
T_1 V_45 = 0 ;
struct V_73 * V_73 ;
int V_24 = F_97 ( V_19 , V_24 , V_15 ) , V_127 = - 1 ;
struct V_134 * V_135 = F_89 ( V_88 , V_19 , V_24 ) ;
struct V_68 * V_69 ;
if ( V_135 == NULL )
return - 1 ;
V_73 = F_98 ( V_88 -> V_128 , V_15 -> V_183 , V_15 -> V_85 ) ;
V_69 = F_38 ( V_73 , V_88 -> V_114 ) ;
if ( V_69 == NULL )
goto V_184;
args = F_99 ( V_19 , args , V_15 ) ;
if ( V_69 -> V_96 == NULL ) {
V_69 -> V_96 = malloc ( V_185 ) ;
if ( ! V_69 -> V_96 )
goto V_184;
}
if ( ! ( V_88 -> V_98 || V_88 -> V_186 || V_88 -> V_187 ) )
F_95 ( V_88 , V_15 ) ;
V_69 -> V_178 = V_15 -> time ;
V_182 = V_69 -> V_96 ;
V_45 += F_16 ( V_182 + V_45 , V_185 - V_45 , L_61 , V_135 -> V_20 ) ;
V_45 += F_88 ( V_135 , V_182 + V_45 , V_185 - V_45 ,
args , V_88 , V_73 ) ;
if ( V_135 -> V_154 ) {
if ( ! ( V_88 -> V_98 || V_88 -> V_186 || V_88 -> V_187 ) ) {
F_56 ( V_88 , V_73 , 0 , false , V_69 -> V_178 , V_88 -> V_114 ) ;
fprintf ( V_88 -> V_114 , L_62 , V_69 -> V_96 ) ;
}
} else {
V_69 -> V_180 = true ;
V_69 -> V_94 . V_188 = false ;
}
if ( V_88 -> V_179 != V_73 ) {
F_100 ( V_88 -> V_179 ) ;
V_88 -> V_179 = F_101 ( V_73 ) ;
}
V_127 = 0 ;
V_184:
F_100 ( V_73 ) ;
return V_127 ;
}
static int F_102 ( struct V_88 * V_88 , struct V_18 * V_19 ,
struct V_14 * V_15 ,
struct V_189 * V_190 )
{
struct V_191 V_192 ;
if ( F_103 ( V_88 -> V_128 , & V_192 , V_15 ) < 0 ||
F_104 ( V_192 . V_73 , V_190 , V_19 , V_15 , NULL , NULL , V_88 -> V_193 ) )
return - 1 ;
return 0 ;
}
static int F_105 ( struct V_88 * V_88 , struct V_14 * V_15 )
{
const unsigned int V_194 = V_195 |
V_196 |
V_197 ;
return F_106 ( V_15 , 38 , V_194 , & V_189 , V_88 -> V_114 ) ;
}
static int F_107 ( struct V_88 * V_88 , struct V_18 * V_19 ,
union V_110 * V_111 V_181 ,
struct V_14 * V_15 )
{
long V_83 ;
T_4 V_63 = 0 ;
bool V_106 = false ;
struct V_73 * V_73 ;
int V_24 = F_97 ( V_19 , V_24 , V_15 ) , V_127 = - 1 , V_198 = 0 ;
struct V_134 * V_135 = F_89 ( V_88 , V_19 , V_24 ) ;
struct V_68 * V_69 ;
if ( V_135 == NULL )
return - 1 ;
V_73 = F_98 ( V_88 -> V_128 , V_15 -> V_183 , V_15 -> V_85 ) ;
V_69 = F_38 ( V_73 , V_88 -> V_114 ) ;
if ( V_69 == NULL )
goto V_184;
if ( V_88 -> V_199 )
F_91 ( V_69 , V_24 , V_15 ) ;
V_83 = F_97 ( V_19 , V_83 , V_15 ) ;
if ( V_24 == V_88 -> V_200 && V_83 >= 0 && V_69 -> V_94 . V_188 ) {
F_43 ( V_73 , V_83 , V_69 -> V_94 . V_20 ) ;
V_69 -> V_94 . V_188 = false ;
++ V_88 -> V_90 . V_97 ;
}
if ( V_69 -> V_178 ) {
V_63 = V_15 -> time - V_69 -> V_178 ;
if ( F_52 ( V_88 , V_63 ) )
goto V_162;
V_106 = true ;
} else if ( V_88 -> V_98 )
goto V_162;
if ( V_15 -> V_201 ) {
V_198 = F_102 ( V_88 , V_19 , V_15 , & V_189 ) ;
if ( V_198 == 0 ) {
if ( V_189 . V_159 < V_88 -> V_187 )
goto V_162;
V_198 = 1 ;
}
}
if ( V_88 -> V_186 )
goto V_162;
F_56 ( V_88 , V_73 , V_63 , V_106 , V_69 -> V_178 , V_88 -> V_114 ) ;
if ( V_69 -> V_180 ) {
fprintf ( V_88 -> V_114 , L_63 , V_69 -> V_96 ) ;
} else {
fprintf ( V_88 -> V_114 , L_64 ) ;
F_34 ( V_88 -> V_114 , V_66 , L_65 ) ;
fprintf ( V_88 -> V_114 , L_66 , V_135 -> V_20 ) ;
}
if ( V_135 -> V_57 == NULL ) {
if ( V_83 < 0 )
goto V_202;
V_203:
fprintf ( V_88 -> V_114 , L_67 , V_83 ) ;
} else if ( V_83 < 0 ) {
V_202: {
char V_31 [ V_204 ] ;
const char * V_205 = F_108 ( - V_83 , V_31 , sizeof( V_31 ) ) ,
* V_206 = F_109 ( - V_83 ) ;
fprintf ( V_88 -> V_114 , L_68 , V_206 , V_205 ) ;
}
} else if ( V_83 == 0 && V_135 -> V_57 -> V_207 )
fprintf ( V_88 -> V_114 , L_69 ) ;
else if ( V_69 -> F_42 ) {
char V_31 [ 1024 ] ;
struct V_37 V_38 = {
. V_33 = V_83 ,
. V_73 = V_73 ,
. V_88 = V_88 ,
} ;
V_69 -> F_42 ( V_31 , sizeof( V_31 ) , & V_38 ) ;
V_69 -> F_42 = NULL ;
fprintf ( V_88 -> V_114 , L_70 , V_31 ) ;
} else if ( V_135 -> V_57 -> V_208 )
fprintf ( V_88 -> V_114 , L_71 , V_83 ) ;
else if ( V_135 -> V_57 -> V_209 ) {
struct V_73 * V_210 = F_110 ( V_88 -> V_128 , V_83 , V_83 ) ;
if ( V_210 != NULL ) {
fprintf ( V_88 -> V_114 , L_67 , V_83 ) ;
if ( V_210 -> V_211 )
fprintf ( V_88 -> V_114 , L_72 , F_57 ( V_210 ) ) ;
F_100 ( V_210 ) ;
}
} else
goto V_203;
fputc ( '\n' , V_88 -> V_114 ) ;
if ( V_198 > 0 )
F_105 ( V_88 , V_15 ) ;
else if ( V_198 < 0 )
F_111 ( L_73 , F_90 ( V_19 ) ) ;
V_162:
V_69 -> V_180 = false ;
V_127 = 0 ;
V_184:
F_100 ( V_73 ) ;
return V_127 ;
}
static int F_112 ( struct V_88 * V_88 , struct V_18 * V_19 ,
union V_110 * V_111 V_181 ,
struct V_14 * V_15 )
{
struct V_73 * V_73 = F_98 ( V_88 -> V_128 , V_15 -> V_183 , V_15 -> V_85 ) ;
struct V_68 * V_69 ;
T_1 V_212 , V_213 , V_214 ;
T_6 V_215 ;
char * V_157 ;
const char * V_94 = F_113 ( V_19 , V_15 , L_34 ) ;
if ( ! V_73 )
goto V_162;
V_69 = F_39 ( V_73 ) ;
if ( ! V_69 )
goto V_184;
V_212 = strlen ( V_94 ) ;
if ( V_212 == 0 )
goto V_184;
if ( V_69 -> V_94 . V_216 < V_212 ) {
char * V_217 = realloc ( V_69 -> V_94 . V_20 , V_212 + 1 ) ;
if ( V_217 == NULL )
goto V_184;
V_69 -> V_94 . V_216 = V_212 ;
V_69 -> V_94 . V_20 = V_217 ;
}
strcpy ( V_69 -> V_94 . V_20 , V_94 ) ;
V_69 -> V_94 . V_188 = true ;
if ( ! V_69 -> V_94 . V_93 )
goto V_184;
V_213 = strlen ( V_69 -> V_96 ) ;
V_215 = V_185 - V_213 - 1 ;
if ( V_215 <= 0 )
goto V_184;
if ( V_212 > ( T_1 ) V_215 ) {
V_94 += V_212 - V_215 ;
V_212 = V_215 ;
}
V_214 = V_213 - V_69 -> V_94 . V_95 + 1 ;
V_157 = V_69 -> V_96 + V_69 -> V_94 . V_95 ;
memmove ( V_157 + V_212 , V_157 , V_214 ) ;
memcpy ( V_157 , V_94 , V_212 ) ;
V_69 -> V_94 . V_93 = 0 ;
V_69 -> V_94 . V_95 = 0 ;
V_184:
F_100 ( V_73 ) ;
V_162:
return 0 ;
}
static int F_114 ( struct V_88 * V_88 , struct V_18 * V_19 ,
union V_110 * V_111 V_181 ,
struct V_14 * V_15 )
{
T_4 V_218 = F_115 ( V_19 , V_15 , L_74 ) ;
double V_219 = ( double ) V_218 / V_64 ;
struct V_73 * V_73 = F_98 ( V_88 -> V_128 ,
V_15 -> V_183 ,
V_15 -> V_85 ) ;
struct V_68 * V_69 = F_38 ( V_73 , V_88 -> V_114 ) ;
if ( V_69 == NULL )
goto V_220;
V_69 -> V_219 += V_219 ;
V_88 -> V_219 += V_219 ;
V_184:
F_100 ( V_73 ) ;
return 0 ;
V_220:
fprintf ( V_88 -> V_114 , L_75 V_115 L_76 V_115 L_77 ,
V_19 -> V_20 ,
F_116 ( V_19 , V_15 , L_78 ) ,
( V_221 ) F_115 ( V_19 , V_15 , L_79 ) ,
V_218 ,
F_115 ( V_19 , V_15 , L_80 ) ) ;
goto V_184;
}
static void F_117 ( enum V_222 V_223 ,
unsigned int V_33 , void * V_224 )
{
T_3 * V_114 = V_224 ;
unsigned char V_225 = ( unsigned char ) V_33 ;
switch ( V_223 ) {
case V_226 :
fprintf ( V_114 , L_81 , isprint ( V_225 ) ? V_225 : '.' ) ;
break;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
default:
break;
}
}
static void F_118 ( struct V_88 * V_88 ,
struct V_14 * V_15 )
{
F_119 ( V_15 -> V_16 , V_15 -> V_236 , 8 ,
F_117 , V_88 -> V_114 ) ;
}
static int F_120 ( struct V_88 * V_88 , struct V_18 * V_19 ,
union V_110 * V_111 V_181 ,
struct V_14 * V_15 )
{
int V_198 = 0 ;
if ( V_15 -> V_201 ) {
V_198 = F_102 ( V_88 , V_19 , V_15 , & V_189 ) ;
if ( V_198 == 0 ) {
if ( V_189 . V_159 < V_88 -> V_187 )
goto V_162;
V_198 = 1 ;
}
}
F_95 ( V_88 , V_15 ) ;
F_54 ( V_88 , V_15 -> time , V_88 -> V_114 ) ;
if ( V_88 -> V_237 )
fprintf ( V_88 -> V_114 , L_82 ) ;
fprintf ( V_88 -> V_114 , L_83 , V_19 -> V_20 ) ;
if ( F_121 ( V_19 ) ) {
F_118 ( V_88 , V_15 ) ;
} else if ( V_19 -> V_149 ) {
F_122 ( V_19 -> V_149 , V_15 -> V_238 ,
V_15 -> V_16 , V_15 -> V_236 ,
V_88 -> V_114 ) ;
}
fprintf ( V_88 -> V_114 , L_77 ) ;
if ( V_198 > 0 )
F_105 ( V_88 , V_15 ) ;
else if ( V_198 < 0 )
F_111 ( L_73 , F_90 ( V_19 ) ) ;
V_162:
return 0 ;
}
static void F_123 ( T_3 * V_217 , struct V_14 * V_15 ,
struct V_191 * V_192 ,
bool V_239 , bool V_240 )
{
if ( ( V_174 > 0 || V_239 ) && V_192 -> V_241 )
fprintf ( V_217 , L_84 , V_192 -> V_241 -> V_242 -> V_243 ) ;
if ( ( V_174 > 0 || V_240 ) && V_192 -> V_244 )
fprintf ( V_217 , L_85 V_245 , V_192 -> V_244 -> V_20 ,
V_192 -> V_246 - V_192 -> V_244 -> V_247 ) ;
else if ( V_192 -> V_241 )
fprintf ( V_217 , L_86 V_245 , V_192 -> V_246 ) ;
else
fprintf ( V_217 , L_86 V_245 , V_15 -> V_246 ) ;
}
static int F_124 ( struct V_88 * V_88 ,
struct V_18 * V_19 ,
union V_110 * V_111 V_181 ,
struct V_14 * V_15 )
{
struct V_73 * V_73 ;
struct V_191 V_192 ;
char V_248 = 'd' ;
struct V_68 * V_69 ;
int V_127 = - 1 ;
int V_198 = 0 ;
V_73 = F_98 ( V_88 -> V_128 , V_15 -> V_183 , V_15 -> V_85 ) ;
if ( V_15 -> V_201 ) {
V_198 = F_102 ( V_88 , V_19 , V_15 , & V_189 ) ;
if ( V_198 == 0 ) {
if ( V_189 . V_159 < V_88 -> V_187 )
goto V_184;
V_198 = 1 ;
}
}
V_69 = F_38 ( V_73 , V_88 -> V_114 ) ;
if ( V_69 == NULL )
goto V_184;
if ( V_19 -> V_249 . V_250 == V_251 )
V_69 -> V_252 ++ ;
else
V_69 -> V_253 ++ ;
if ( V_88 -> V_186 )
goto V_162;
F_125 ( V_73 , V_15 -> V_254 , V_255 ,
V_15 -> V_256 , & V_192 ) ;
F_56 ( V_88 , V_73 , 0 , true , V_15 -> time , V_88 -> V_114 ) ;
fprintf ( V_88 -> V_114 , L_87 ,
V_19 -> V_249 . V_250 == V_251 ?
L_88 : L_89 ) ;
F_123 ( V_88 -> V_114 , V_15 , & V_192 , false , true ) ;
fprintf ( V_88 -> V_114 , L_90 ) ;
F_125 ( V_73 , V_15 -> V_254 , V_257 ,
V_15 -> V_246 , & V_192 ) ;
if ( ! V_192 . V_241 ) {
F_125 ( V_73 , V_15 -> V_254 ,
V_255 , V_15 -> V_246 , & V_192 ) ;
if ( V_192 . V_241 )
V_248 = 'x' ;
else
V_248 = '?' ;
}
F_123 ( V_88 -> V_114 , V_15 , & V_192 , true , false ) ;
fprintf ( V_88 -> V_114 , L_91 , V_248 , V_192 . V_258 ) ;
if ( V_198 > 0 )
F_105 ( V_88 , V_15 ) ;
else if ( V_198 < 0 )
F_111 ( L_73 , F_90 ( V_19 ) ) ;
V_162:
V_127 = 0 ;
V_184:
F_100 ( V_73 ) ;
return V_127 ;
}
static void F_126 ( struct V_88 * V_88 ,
struct V_18 * V_19 ,
struct V_14 * V_15 )
{
if ( V_88 -> V_101 == 0 && ! V_88 -> V_259 &&
( V_19 -> V_249 . V_260 & V_261 ) )
V_88 -> V_101 = V_15 -> time ;
}
static int F_127 ( struct V_117 * V_118 ,
union V_110 * V_111 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_109 * V_109 V_181 )
{
struct V_88 * V_88 = F_62 ( V_118 , struct V_88 , V_118 ) ;
struct V_73 * V_73 ;
int V_127 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
V_73 = F_98 ( V_88 -> V_128 , V_15 -> V_183 , V_15 -> V_85 ) ;
if ( V_73 && F_128 ( V_73 ) )
goto V_162;
F_126 ( V_88 , V_19 , V_15 ) ;
if ( V_22 ) {
++ V_88 -> V_75 ;
V_22 ( V_88 , V_19 , V_111 , V_15 ) ;
}
V_162:
F_100 ( V_73 ) ;
return V_127 ;
}
static int F_129 ( struct V_88 * V_88 , int V_262 , const char * * V_263 )
{
unsigned int V_264 , V_42 , V_265 ;
const char * * V_266 ;
const char * const V_267 [] = {
L_92 ,
L_93 ,
L_94 , L_95 ,
L_96 , L_97 ,
} ;
const char * const V_268 [] = { L_98 , } ;
unsigned int V_269 = F_32 ( V_268 ) ;
const char * const V_270 [] = { L_98 , L_99 } ;
unsigned int V_271 = F_32 ( V_270 ) ;
const char * const V_272 [] = { L_98 , L_100 } ;
unsigned int V_273 = F_32 ( V_272 ) ;
V_264 = F_32 ( V_267 ) + V_269 + 1 +
V_271 + V_273 + V_262 ;
V_266 = calloc ( V_264 + 1 , sizeof( char * ) ) ;
if ( V_266 == NULL )
return - V_26 ;
V_265 = 0 ;
for ( V_42 = 0 ; V_42 < F_32 ( V_267 ) ; V_42 ++ )
V_266 [ V_265 ++ ] = V_267 [ V_42 ] ;
if ( V_88 -> V_237 ) {
for ( V_42 = 0 ; V_42 < V_269 ; V_42 ++ )
V_266 [ V_265 ++ ] = V_268 [ V_42 ] ;
if ( F_130 ( L_101 ) )
V_266 [ V_265 ++ ] = L_102 ;
else if ( F_130 ( L_103 ) )
V_266 [ V_265 ++ ] = L_104 ;
else {
F_111 ( L_105 ) ;
return - 1 ;
}
}
if ( V_88 -> V_274 & V_275 )
for ( V_42 = 0 ; V_42 < V_271 ; V_42 ++ )
V_266 [ V_265 ++ ] = V_270 [ V_42 ] ;
if ( V_88 -> V_274 & V_276 )
for ( V_42 = 0 ; V_42 < V_273 ; V_42 ++ )
V_266 [ V_265 ++ ] = V_272 [ V_42 ] ;
for ( V_42 = 0 ; V_42 < ( unsigned int ) V_262 ; V_42 ++ )
V_266 [ V_265 ++ ] = V_263 [ V_42 ] ;
return F_131 ( V_265 , V_266 ) ;
}
static bool F_132 ( struct V_125 * V_126 )
{
struct V_18 * V_19 = F_13 ( L_106 , L_107 ) ;
if ( F_14 ( V_19 ) )
return false ;
if ( F_5 ( V_19 , L_34 ) == NULL ) {
F_9 ( V_19 ) ;
return false ;
}
V_19 -> V_22 = F_112 ;
F_133 ( V_126 , V_19 ) ;
return true ;
}
static struct V_18 * F_134 ( T_4 V_250 )
{
struct V_18 * V_19 ;
struct V_277 V_249 = {
. type = V_278 ,
. V_279 = 1 ,
} ;
V_249 . V_250 = V_250 ;
V_249 . V_280 = 1 ;
F_135 ( & V_249 ) ;
V_19 = F_136 ( & V_249 ) ;
if ( V_19 )
V_19 -> V_22 = F_124 ;
return V_19 ;
}
static void F_137 ( struct V_88 * V_88 , union V_110 * V_111 , struct V_14 * V_15 )
{
const T_8 type = V_111 -> V_112 . type ;
struct V_18 * V_19 ;
if ( type != V_281 ) {
F_58 ( V_88 , V_88 -> V_128 , V_111 , V_15 ) ;
return;
}
V_19 = F_138 ( V_88 -> V_126 , V_15 -> V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_88 -> V_114 , L_108 V_115 L_109 , V_15 -> V_24 ) ;
return;
}
F_126 ( V_88 , V_19 , V_15 ) ;
if ( V_19 -> V_249 . type == V_282 &&
V_15 -> V_16 == NULL ) {
fprintf ( V_88 -> V_114 , L_110 ,
F_90 ( V_19 ) , V_15 -> V_85 ,
V_15 -> V_238 , V_15 -> V_236 ) ;
} else {
T_7 V_22 = V_19 -> V_22 ;
V_22 ( V_88 , V_19 , V_111 , V_15 ) ;
}
}
static int F_139 ( struct V_88 * V_88 )
{
int V_83 = - 1 ;
struct V_125 * V_126 = V_88 -> V_126 ;
struct V_18 * V_283 , * V_284 ;
V_283 = F_12 ( L_111 , F_96 ) ;
if ( V_283 == NULL )
goto V_162;
if ( F_140 ( V_283 , args ) )
goto V_285;
V_284 = F_12 ( L_112 , F_107 ) ;
if ( V_284 == NULL )
goto V_285;
if ( F_11 ( V_284 , V_83 ) )
goto V_286;
F_133 ( V_126 , V_283 ) ;
F_133 ( V_126 , V_284 ) ;
if ( V_287 . V_288 && ! V_88 -> V_289 ) {
V_284 -> V_249 . V_290 = 1 ;
}
V_88 -> V_147 . V_291 . V_283 = V_283 ;
V_88 -> V_147 . V_291 . V_284 = V_284 ;
V_83 = 0 ;
V_162:
return V_83 ;
V_286:
F_7 ( V_284 ) ;
V_285:
F_7 ( V_283 ) ;
goto V_162;
}
static int F_141 ( struct V_88 * V_88 )
{
int V_127 = - 1 ;
struct V_18 * V_284 ;
char * V_292 = F_142 ( L_113 , ! V_88 -> V_293 ,
V_88 -> V_158 . V_159 ,
V_88 -> V_158 . V_36 ) ;
if ( V_292 == NULL )
goto V_294;
if ( ! F_143 ( V_88 -> V_147 . V_291 . V_283 ,
V_292 ) ) {
V_284 = V_88 -> V_147 . V_291 . V_284 ;
V_127 = F_143 ( V_284 , V_292 ) ;
}
free ( V_292 ) ;
V_162:
return V_127 ;
V_294:
V_129 = V_26 ;
goto V_162;
}
static int F_144 ( struct V_88 * V_88 )
{
unsigned int V_159 = 1 ;
V_221 V_295 [ 32 ] = {
F_145 () ,
} ;
struct V_73 * V_73 = F_110 ( V_88 -> V_128 , V_295 [ 0 ] , V_295 [ 0 ] ) ;
while ( V_73 && V_159 < F_32 ( V_295 ) ) {
struct V_73 * V_296 = F_110 ( V_88 -> V_128 , V_73 -> V_297 , V_73 -> V_297 ) ;
if ( V_296 == NULL )
break;
if ( ! strcmp ( F_57 ( V_296 ) , L_114 ) ) {
V_295 [ V_159 ++ ] = V_296 -> V_85 ;
break;
}
V_73 = V_296 ;
}
return F_146 ( V_88 -> V_126 , V_159 , V_295 ) ;
}
static int F_147 ( struct V_88 * V_88 , int V_262 , const char * * V_263 )
{
struct V_125 * V_126 = V_88 -> V_126 ;
struct V_18 * V_19 , * V_298 = NULL , * V_299 = NULL ;
int V_127 = - 1 , V_42 ;
unsigned long V_300 ;
const bool V_301 = V_262 > 0 ;
bool V_302 = false ;
V_88 -> V_89 = true ;
if ( V_88 -> V_237 && F_139 ( V_88 ) )
goto V_303;
if ( V_88 -> V_237 )
V_88 -> V_97 = F_132 ( V_126 ) ;
if ( ( V_88 -> V_274 & V_275 ) ) {
V_298 = F_134 ( V_251 ) ;
if ( V_298 == NULL )
goto V_304;
F_133 ( V_126 , V_298 ) ;
}
if ( ( V_88 -> V_274 & V_276 ) ) {
V_299 = F_134 ( V_305 ) ;
if ( V_299 == NULL )
goto V_304;
F_133 ( V_126 , V_299 ) ;
}
if ( V_88 -> V_306 &&
F_148 ( V_126 , L_115 , L_116 ,
F_114 ) )
goto V_307;
V_127 = F_149 ( V_126 , & V_88 -> V_130 . V_131 ) ;
if ( V_127 < 0 ) {
fprintf ( V_88 -> V_114 , L_117 ) ;
goto V_308;
}
V_127 = F_66 ( V_88 , V_126 ) ;
if ( V_127 < 0 ) {
fprintf ( V_88 -> V_114 , L_118 ) ;
goto V_308;
}
F_150 ( V_126 , & V_88 -> V_130 , NULL ) ;
if ( V_287 . V_288 ) {
bool V_309 = false ;
if ( V_88 -> V_147 . V_291 . V_284 ) {
F_151 ( V_88 -> V_147 . V_291 . V_284 ,
& V_88 -> V_130 , & V_287 ) ;
V_309 = true ;
}
if ( V_298 ) {
F_151 ( V_298 , & V_88 -> V_130 , & V_287 ) ;
V_309 = true ;
}
if ( V_299 ) {
F_151 ( V_299 , & V_88 -> V_130 , & V_287 ) ;
V_309 = true ;
}
if ( V_309 ) {
F_152 ( V_126 , V_310 ) ;
F_153 ( V_126 , V_311 ) ;
}
}
signal ( V_312 , F_55 ) ;
signal ( V_105 , F_55 ) ;
if ( V_301 ) {
V_127 = F_154 ( V_126 , & V_88 -> V_130 . V_131 ,
V_263 , false , NULL ) ;
if ( V_127 < 0 ) {
fprintf ( V_88 -> V_114 , L_119 ) ;
goto V_308;
}
}
V_127 = F_155 ( V_126 ) ;
if ( V_127 < 0 )
goto V_313;
V_127 = F_156 () ;
if ( V_127 ) {
char V_314 [ V_315 ] ;
F_157 ( V_127 , V_314 , sizeof( V_314 ) ) ;
F_111 ( L_120 ,
V_314 ) ;
goto V_313;
}
if ( V_88 -> V_316 . V_159 > 0 )
V_127 = F_146 ( V_126 , V_88 -> V_316 . V_159 , V_88 -> V_316 . V_36 ) ;
else if ( F_158 ( V_126 -> V_132 , 0 ) == - 1 )
V_127 = F_144 ( V_88 ) ;
if ( V_127 < 0 )
goto V_304;
if ( V_88 -> V_158 . V_159 > 0 ) {
V_127 = F_141 ( V_88 ) ;
if ( V_127 < 0 )
goto V_317;
F_159 ( L_121 ,
V_88 -> V_147 . V_291 . V_284 -> V_292 ) ;
}
V_127 = F_160 ( V_126 , & V_19 ) ;
if ( V_127 < 0 )
goto V_318;
V_127 = F_161 ( V_126 , V_88 -> V_130 . V_319 , false ) ;
if ( V_127 < 0 )
goto V_320;
if ( ! F_162 ( & V_88 -> V_130 . V_131 ) && ! V_88 -> V_130 . V_321 )
F_163 ( V_126 ) ;
if ( V_301 )
F_164 ( V_126 ) ;
if ( V_88 -> V_130 . V_321 ) {
F_165 ( V_88 -> V_130 . V_321 * 1000 ) ;
F_163 ( V_126 ) ;
}
V_88 -> V_107 = F_158 ( V_126 -> V_132 , 0 ) == - 1 ||
V_126 -> V_132 -> V_159 > 1 ||
F_166 ( V_126 ) -> V_249 . V_322 ;
V_323:
V_300 = V_88 -> V_75 ;
for ( V_42 = 0 ; V_42 < V_126 -> V_324 ; V_42 ++ ) {
union V_110 * V_111 ;
while ( ( V_111 = F_167 ( V_126 , V_42 ) ) != NULL ) {
struct V_14 V_15 ;
++ V_88 -> V_75 ;
V_127 = F_168 ( V_126 , V_111 , & V_15 ) ;
if ( V_127 ) {
fprintf ( V_88 -> V_114 , L_122 , V_127 ) ;
goto V_325;
}
F_137 ( V_88 , V_111 , & V_15 ) ;
V_325:
F_169 ( V_126 , V_42 ) ;
if ( V_104 )
goto V_326;
if ( V_103 && ! V_302 ) {
F_170 ( V_126 ) ;
V_302 = true ;
}
}
}
if ( V_88 -> V_75 == V_300 ) {
int V_207 = V_103 ? 100 : - 1 ;
if ( ! V_302 && F_171 ( V_126 , V_207 ) > 0 ) {
if ( F_172 ( V_126 , V_327 | V_328 ) == 0 )
V_302 = true ;
goto V_323;
}
} else {
goto V_323;
}
V_326:
F_173 ( V_88 -> V_179 ) ;
F_170 ( V_126 ) ;
if ( ! V_127 ) {
if ( V_88 -> V_199 )
F_174 ( V_88 , V_88 -> V_114 ) ;
if ( V_88 -> V_329 ) {
fprintf ( V_88 -> V_114 , L_123
L_124 V_115 L_125
L_126 V_115 L_125 ,
V_88 -> V_90 . V_97 ,
V_88 -> V_90 . V_91 ) ;
}
}
V_308:
F_72 ( V_88 ) ;
F_175 ( V_126 ) ;
V_88 -> V_126 = NULL ;
V_88 -> V_89 = false ;
return V_127 ;
{
char V_314 [ V_315 ] ;
V_307:
F_176 ( V_129 , V_314 , sizeof( V_314 ) , L_115 , L_116 ) ;
goto V_330;
V_303:
F_176 ( V_129 , V_314 , sizeof( V_314 ) , L_1 , L_127 ) ;
goto V_330;
V_320:
F_177 ( V_126 , V_129 , V_314 , sizeof( V_314 ) ) ;
goto V_330;
V_313:
F_178 ( V_126 , V_129 , V_314 , sizeof( V_314 ) ) ;
V_330:
fprintf ( V_88 -> V_114 , L_128 , V_314 ) ;
goto V_308;
V_318:
fprintf ( V_88 -> V_114 ,
L_129 ,
V_19 -> V_292 , F_90 ( V_19 ) , V_129 ,
F_108 ( V_129 , V_314 , sizeof( V_314 ) ) ) ;
goto V_308;
}
V_304:
fprintf ( V_88 -> V_114 , L_130 ) ;
goto V_308;
V_317:
fprintf ( V_88 -> V_114 , L_131 , V_129 , strerror ( V_129 ) ) ;
goto V_308;
}
static int F_179 ( struct V_88 * V_88 )
{
const struct V_331 V_332 [] = {
{ L_132 , F_112 , } ,
} ;
struct V_333 V_334 = {
. V_92 = V_335 ,
. V_46 = V_336 ,
. V_337 = V_88 -> V_337 ,
} ;
struct V_338 * V_339 ;
struct V_18 * V_19 ;
int V_127 = - 1 ;
V_88 -> V_118 . V_15 = F_127 ;
V_88 -> V_118 . V_340 = V_341 ;
V_88 -> V_118 . V_342 = V_343 ;
V_88 -> V_118 . V_344 = V_345 ;
V_88 -> V_118 . exit = V_346 ;
V_88 -> V_118 . V_347 = V_348 ;
V_88 -> V_118 . V_249 = V_349 ;
V_88 -> V_118 . V_350 = V_351 ;
V_88 -> V_118 . V_352 = V_353 ;
V_88 -> V_118 . V_354 = V_355 ;
V_88 -> V_118 . V_356 = true ;
V_88 -> V_118 . V_357 = true ;
V_88 -> V_107 = true ;
V_339 = F_180 ( & V_334 , false , & V_88 -> V_118 ) ;
if ( V_339 == NULL )
return - 1 ;
if ( V_88 -> V_130 . V_131 . V_183 )
V_123 . V_358 = F_44 ( V_88 -> V_130 . V_131 . V_183 ) ;
if ( V_88 -> V_130 . V_131 . V_85 )
V_123 . V_359 = F_44 ( V_88 -> V_130 . V_131 . V_85 ) ;
if ( F_67 ( & V_339 -> V_112 . V_360 ) < 0 )
goto V_162;
V_88 -> V_128 = & V_339 -> V_361 . V_128 ;
V_127 = F_181 ( V_339 , V_332 ) ;
if ( V_127 )
goto V_162;
V_19 = F_182 ( V_339 -> V_126 ,
L_101 ) ;
if ( V_19 == NULL )
V_19 = F_182 ( V_339 -> V_126 ,
L_103 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_96 ) < 0 ||
F_140 ( V_19 , args ) ) ) {
F_111 ( L_133 ) ;
goto V_162;
}
V_19 = F_182 ( V_339 -> V_126 ,
L_134 ) ;
if ( V_19 == NULL )
V_19 = F_182 ( V_339 -> V_126 ,
L_135 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_107 ) < 0 ||
F_11 ( V_19 , V_83 ) ) ) {
F_111 ( L_136 ) ;
goto V_162;
}
F_183 (session->evlist, evsel) {
if ( V_19 -> V_249 . type == V_278 &&
( V_19 -> V_249 . V_250 == V_251 ||
V_19 -> V_249 . V_250 == V_305 ||
V_19 -> V_249 . V_250 == V_362 ) )
V_19 -> V_22 = F_124 ;
}
F_184 () ;
V_127 = F_185 ( V_339 ) ;
if ( V_127 )
F_111 ( L_137 , V_127 ) ;
else if ( V_88 -> V_199 )
F_174 ( V_88 , V_88 -> V_114 ) ;
V_162:
F_186 ( V_339 ) ;
return V_127 ;
}
static T_1 F_187 ( T_3 * V_62 )
{
T_1 V_45 ;
V_45 = fprintf ( V_62 , L_138 ) ;
return V_45 ;
}
static T_1 F_188 ( struct V_68 * V_69 ,
struct V_88 * V_88 , T_3 * V_62 )
{
T_1 V_45 = 0 ;
struct V_134 * V_135 ;
struct V_363 * V_364 ;
F_189 ( V_72 , V_69 -> V_72 ) ;
if ( V_72 == NULL )
return 0 ;
V_45 += fprintf ( V_62 , L_125 ) ;
V_45 += fprintf ( V_62 , L_139 ) ;
V_45 += fprintf ( V_62 , L_140 ) ;
V_45 += fprintf ( V_62 , L_141 ) ;
F_190 (nd, syscall_stats) {
struct V_90 * V_90 = V_365 -> V_90 ;
if ( V_90 ) {
double V_366 = ( double ) ( V_90 -> V_366 ) / V_64 ;
double V_71 = ( double ) ( V_90 -> V_71 ) / V_64 ;
double V_367 = F_191 ( V_90 ) ;
double V_368 ;
T_4 T_2 = ( T_4 ) V_90 -> T_2 ;
V_368 = V_367 ? 100.0 * F_192 ( V_90 ) / V_367 : 0.0 ;
V_367 /= V_64 ;
V_135 = & V_88 -> V_147 . V_78 [ V_365 -> V_134 ] ;
V_45 += fprintf ( V_62 , L_142 , V_135 -> V_20 ) ;
V_45 += fprintf ( V_62 , L_143 V_115 L_144 ,
T_2 , V_365 -> V_369 , V_366 , V_367 ) ;
V_45 += fprintf ( V_62 , L_145 , V_71 , V_368 ) ;
}
}
F_193 ( V_72 ) ;
V_45 += fprintf ( V_62 , L_146 ) ;
return V_45 ;
}
static T_1 F_194 ( T_3 * V_62 , struct V_73 * V_73 , struct V_88 * V_88 )
{
T_1 V_45 = 0 ;
struct V_68 * V_69 = F_39 ( V_73 ) ;
double V_370 ;
if ( V_69 == NULL )
return 0 ;
V_370 = ( double ) V_69 -> V_75 / V_88 -> V_75 * 100.0 ;
V_45 += fprintf ( V_62 , L_147 , F_57 ( V_73 ) , V_73 -> V_85 ) ;
V_45 += fprintf ( V_62 , L_148 , V_69 -> V_75 ) ;
V_45 += fprintf ( V_62 , L_149 , V_370 ) ;
if ( V_69 -> V_252 )
V_45 += fprintf ( V_62 , L_150 , V_69 -> V_252 ) ;
if ( V_69 -> V_253 )
V_45 += fprintf ( V_62 , L_151 , V_69 -> V_253 ) ;
if ( V_88 -> V_306 )
V_45 += fprintf ( V_62 , L_152 , V_69 -> V_219 ) ;
else if ( fputc ( '\n' , V_62 ) != V_371 )
++ V_45 ;
V_45 += F_188 ( V_69 , V_88 , V_62 ) ;
return V_45 ;
}
static unsigned long F_195 ( struct V_68 * V_69 )
{
return V_69 ? V_69 -> V_75 : 0 ;
}
static T_1 F_174 ( struct V_88 * V_88 , T_3 * V_62 )
{
F_196 ( V_132 , V_88 -> V_128 ) ;
T_1 V_45 = F_187 ( V_62 ) ;
struct V_363 * V_364 ;
if ( V_132 == NULL ) {
fprintf ( V_62 , L_3 , L_153 ) ;
return 0 ;
}
F_190 (nd, threads)
V_45 += F_194 ( V_62 , V_372 -> V_73 , V_88 ) ;
F_193 ( V_132 ) ;
return V_45 ;
}
static int F_197 ( const struct V_373 * V_374 , const char * V_375 ,
int T_9 V_181 )
{
struct V_88 * V_88 = V_374 -> V_376 ;
V_88 -> V_98 = atof ( V_375 ) ;
return 0 ;
}
static int F_198 ( const struct V_373 * V_374 , const char * V_375 ,
int T_9 V_181 )
{
int V_83 = - 1 ;
T_1 V_42 ;
struct V_88 * V_88 = V_374 -> V_376 ;
struct V_377 * V_378 = F_37 ( V_375 ) ;
if ( V_378 == NULL )
return - 1 ;
V_42 = V_88 -> V_316 . V_159 = F_199 ( V_378 ) + 1 ;
V_88 -> V_316 . V_36 = calloc ( V_42 , sizeof( V_221 ) ) ;
if ( V_88 -> V_316 . V_36 == NULL )
goto V_162;
V_88 -> V_316 . V_36 [ 0 ] = F_145 () ;
for ( V_42 = 1 ; V_42 < V_88 -> V_316 . V_159 ; ++ V_42 )
V_88 -> V_316 . V_36 [ V_42 ] = F_200 ( V_378 , V_42 - 1 ) -> V_42 ;
F_201 ( V_378 ) ;
V_83 = 0 ;
V_162:
return V_83 ;
}
static int F_202 ( struct V_88 * V_88 , const char * V_94 )
{
struct V_81 V_82 ;
if ( ! V_81 ( V_94 , & V_82 ) && V_82 . V_86 ) {
char V_379 [ V_80 ] ;
F_16 ( V_379 , sizeof( V_379 ) , L_154 , V_94 ) ;
F_203 ( V_379 ) ;
rename ( V_94 , V_379 ) ;
}
V_88 -> V_114 = fopen ( V_94 , L_155 ) ;
return V_88 -> V_114 == NULL ? - V_129 : 0 ;
}
static int F_204 ( const struct V_373 * V_374 , const char * V_375 ,
int T_9 V_181 )
{
int * V_274 = V_374 -> V_376 ;
if ( strcmp ( V_375 , L_156 ) == 0 )
* V_274 |= V_275 | V_276 ;
else if ( strcmp ( V_375 , L_88 ) == 0 )
* V_274 |= V_275 ;
else if ( strcmp ( V_375 , L_89 ) == 0 )
* V_274 |= V_276 ;
else
return - 1 ;
return 0 ;
}
static void F_205 ( struct V_125 * V_126 , void * V_22 )
{
struct V_18 * V_19 ;
F_183 (evlist, evsel)
V_19 -> V_22 = V_22 ;
}
static int F_206 ( const struct V_373 * V_374 , const char * V_375 ,
int T_9 V_181 )
{
struct V_88 * V_88 = (struct V_88 * ) V_374 -> V_376 ;
const char * V_163 = V_375 ;
char * V_380 = NULL , * V_381 [ 2 ] = { NULL , NULL , } ;
int V_138 = strlen ( V_375 ) + 1 , V_127 = - 1 , V_378 , V_34 ;
char * V_382 = F_207 ( V_383 ) ;
char V_384 [ V_80 ] ;
if ( V_382 == NULL )
return - 1 ;
if ( * V_163 == '!' ) {
++ V_163 ;
V_88 -> V_293 = true ;
}
while ( 1 ) {
if ( ( V_380 = strchr ( V_163 , ',' ) ) != NULL )
* V_380 = '\0' ;
V_378 = 0 ;
if ( F_82 ( V_88 -> V_146 , V_163 ) >= 0 ||
F_83 ( V_88 -> V_146 , V_163 , & V_34 ) >= 0 ) {
V_378 = 1 ;
} else {
F_208 ( V_384 , sizeof( V_384 ) , V_382 , V_163 ) ;
if ( F_209 ( V_384 , V_385 ) == 0 )
V_378 = 1 ;
}
if ( V_381 [ V_378 ] ) {
sprintf ( V_381 [ V_378 ] + strlen ( V_381 [ V_378 ] ) , L_157 , V_163 ) ;
} else {
V_381 [ V_378 ] = malloc ( V_138 ) ;
if ( V_381 [ V_378 ] == NULL )
goto V_162;
strcpy ( V_381 [ V_378 ] , V_163 ) ;
}
if ( ! V_380 )
break;
* V_380 = ',' ;
V_163 = V_380 + 1 ;
}
if ( V_381 [ 1 ] != NULL ) {
struct V_386 V_387 = {
. V_388 = V_382 ,
} ;
V_88 -> V_160 = F_210 ( V_381 [ 1 ] , & V_387 ) ;
if ( V_88 -> V_160 == NULL ) {
fputs ( L_158 , V_88 -> V_114 ) ;
goto V_162;
}
if ( F_79 ( V_88 ) )
goto V_162;
}
V_127 = 0 ;
if ( V_381 [ 0 ] ) {
struct V_373 V_389 = F_211 ( 'e' , L_159 , & V_88 -> V_126 , L_159 ,
L_160 ,
V_390 ) ;
V_127 = V_390 ( & V_389 , V_381 [ 0 ] , 0 ) ;
}
V_162:
if ( V_380 )
* V_380 = ',' ;
return V_127 ;
}
int F_212 ( int V_262 , const char * * V_263 )
{
const char * V_391 [] = {
L_161 ,
L_162 ,
L_163 ,
L_164 ,
NULL
} ;
struct V_88 V_88 = {
. V_147 = {
. V_71 = - 1 ,
} ,
. V_130 = {
. V_131 = {
. V_392 = V_393 ,
. V_394 = true ,
} ,
. V_395 = V_393 ,
. V_396 = V_397 ,
. V_398 = true ,
. V_319 = V_393 ,
. V_133 = 500 ,
} ,
. V_114 = V_399 ,
. V_108 = true ,
. V_237 = true ,
. V_289 = false ,
. V_193 = V_393 ,
} ;
const char * V_400 = NULL ;
const struct V_373 V_401 [] = {
F_211 ( 'e' , L_159 , & V_88 , L_159 ,
L_165 ,
F_206 ) ,
F_213 ( 0 , L_78 , & V_88 . V_108 ,
L_166 ) ,
F_213 ( 0 , L_167 , & V_88 . V_329 , L_168 ) ,
F_211 ( 0 , L_169 , & V_88 , L_169 , L_170 ,
F_206 ) ,
F_214 ( 'o' , L_171 , & V_400 , L_172 , L_173 ) ,
F_214 ( 'i' , L_174 , & V_335 , L_172 , L_175 ) ,
F_214 ( 'p' , L_79 , & V_88 . V_130 . V_131 . V_183 , L_79 ,
L_176 ) ,
F_214 ( 't' , L_177 , & V_88 . V_130 . V_131 . V_85 , L_177 ,
L_178 ) ,
F_211 ( 0 , L_179 , & V_88 , L_180 ,
L_181 , F_198 ) ,
F_213 ( 'a' , L_182 , & V_88 . V_130 . V_131 . V_402 ,
L_183 ) ,
F_214 ( 'C' , L_184 , & V_88 . V_130 . V_131 . V_403 , L_184 ,
L_185 ) ,
F_213 ( 0 , L_186 , & V_88 . V_130 . V_404 ,
L_187 ) ,
F_211 ( 'm' , L_188 , & V_88 . V_130 . V_319 , L_189 ,
L_190 ,
V_405 ) ,
F_214 ( 'u' , L_191 , & V_88 . V_130 . V_131 . V_406 , L_192 ,
L_193 ) ,
F_211 ( 0 , L_194 , & V_88 , L_195 ,
L_196 ,
F_197 ) ,
F_213 ( 0 , L_115 , & V_88 . V_306 , L_197 ) ,
F_215 ( 'v' , L_198 , & V_174 , L_199 ) ,
F_213 ( 'T' , L_200 , & V_88 . V_259 ,
L_201 ) ,
F_213 ( 's' , L_202 , & V_88 . V_186 ,
L_203 ) ,
F_213 ( 'S' , L_204 , & V_88 . V_199 ,
L_205 ) ,
F_216 ( 'F' , L_206 , & V_88 . V_274 , L_207 ,
L_208 , F_204 , L_88 ) ,
F_213 ( 0 , L_2 , & V_88 . V_237 , L_209 ) ,
F_213 ( 'f' , L_210 , & V_88 . V_337 , L_211 ) ,
F_211 ( 0 , L_212 , & V_88 . V_130 ,
L_213 , V_407 ,
& V_408 ) ,
F_213 ( 0 , L_214 , & V_88 . V_289 ,
L_215 ) ,
F_217 ( 0 , L_216 , & V_88 . V_187 ,
L_217
L_218 ) ,
F_217 ( 0 , L_219 , & V_88 . V_193 ,
L_220
L_221
L_222 F_218 ( V_409 ) ) ,
F_217 ( 0 , L_223 , & V_88 . V_130 . V_133 ,
L_224 ) ,
F_217 ( 'D' , L_225 , & V_88 . V_130 . V_321 ,
L_226
L_227 ) ,
F_219 ()
} ;
bool V_181 V_410 = true ;
bool V_411 = true ;
const char * const V_412 [] = { L_92 , NULL } ;
int V_127 ;
char V_31 [ V_315 ] ;
signal ( V_413 , V_414 ) ;
signal ( V_415 , V_414 ) ;
V_88 . V_126 = F_220 () ;
V_88 . V_146 = F_221 () ;
if ( V_88 . V_126 == NULL || V_88 . V_146 == NULL ) {
F_111 ( L_130 ) ;
V_127 = - V_26 ;
goto V_162;
}
V_262 = F_222 ( V_262 , V_263 , V_401 , V_412 ,
V_391 , V_416 ) ;
V_127 = F_223 ( V_88 . V_126 ) ;
if ( V_127 ) {
F_224 ( V_88 . V_126 , V_127 , V_31 , sizeof( V_31 ) ) ;
F_111 ( L_228 , V_31 ) ;
goto V_162;
}
V_127 = - 1 ;
if ( V_88 . V_274 ) {
V_88 . V_130 . V_417 = true ;
V_88 . V_130 . V_418 = true ;
}
if ( V_88 . V_130 . V_319 == V_393 )
V_411 = false ;
if ( V_88 . V_193 == V_393 ) {
V_88 . V_193 = V_335 ? V_409 : V_419 ;
V_410 = false ;
}
#ifdef F_225
if ( ( V_88 . V_187 || V_410 ) && ! V_287 . V_288 && V_88 . V_237 )
F_226 ( & V_88 . V_130 , & V_287 , L_229 , false ) ;
#endif
if ( V_287 . V_288 ) {
if ( ! V_411 && F_227 () == 0 )
V_88 . V_130 . V_319 = F_228 () * 4 ;
V_123 . V_420 = true ;
}
if ( V_88 . V_126 -> V_35 > 0 )
F_205 ( V_88 . V_126 , F_120 ) ;
if ( ( V_262 >= 1 ) && ( strcmp ( V_263 [ 0 ] , L_92 ) == 0 ) )
return F_129 ( & V_88 , V_262 - 1 , & V_263 [ 1 ] ) ;
if ( V_88 . V_186 )
V_88 . V_199 = V_88 . V_186 ;
if ( ! V_88 . V_237 && ! V_88 . V_274 &&
V_88 . V_126 -> V_35 == 0 ) {
F_111 ( L_230 ) ;
return - 1 ;
}
if ( ! V_88 . V_237 && V_88 . V_160 ) {
F_111 ( L_231 ) ;
goto V_162;
}
if ( V_400 != NULL ) {
V_127 = F_202 ( & V_88 , V_400 ) ;
if ( V_127 < 0 ) {
perror ( L_232 ) ;
goto V_162;
}
}
V_88 . V_200 = F_82 ( V_88 . V_146 , L_233 ) ;
V_127 = F_229 ( & V_88 . V_130 . V_131 ) ;
if ( V_127 ) {
F_230 ( & V_88 . V_130 . V_131 , V_127 , V_31 , sizeof( V_31 ) ) ;
fprintf ( V_88 . V_114 , L_3 , V_31 ) ;
goto V_421;
}
V_127 = F_231 ( & V_88 . V_130 . V_131 ) ;
if ( V_127 ) {
F_230 ( & V_88 . V_130 . V_131 , V_127 , V_31 , sizeof( V_31 ) ) ;
fprintf ( V_88 . V_114 , L_3 , V_31 ) ;
goto V_421;
}
if ( ! V_262 && F_162 ( & V_88 . V_130 . V_131 ) )
V_88 . V_130 . V_131 . V_402 = true ;
if ( V_335 )
V_127 = F_179 ( & V_88 ) ;
else
V_127 = F_147 ( & V_88 , V_262 , V_263 ) ;
V_421:
if ( V_400 != NULL )
fclose ( V_88 . V_114 ) ;
V_162:
return V_127 ;
}
