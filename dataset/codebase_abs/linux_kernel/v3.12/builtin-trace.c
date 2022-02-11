static T_1 F_1 ( char * V_1 , T_1 V_2 ,
unsigned long V_3 ,
T_2 T_3 V_4 ,
T_2 * T_4 V_4 )
{
return F_2 ( V_1 , V_2 , L_1 , V_3 ) ;
}
static T_1 F_3 ( char * V_1 , T_1 V_2 ,
unsigned long V_3 ,
T_2 T_3 V_4 ,
T_2 * T_4 V_4 )
{
int V_5 = V_3 ;
switch ( V_5 ) {
#define F_4 ( T_5 ) case SEEK_##n: return scnprintf(bf, size, #n)
F_4 ( V_6 ) ;
F_4 ( V_7 ) ;
F_4 ( V_8 ) ;
#ifdef F_5
F_4 ( V_9 ) ;
#endif
#ifdef F_6
F_4 ( V_10 ) ;
#endif
#undef F_4
default: break;
}
return F_2 ( V_1 , V_2 , L_2 , V_5 ) ;
}
static T_1 F_7 ( char * V_1 , T_1 V_2 ,
unsigned long V_3 ,
T_2 T_3 V_4 ,
T_2 * T_4 V_4 )
{
int V_11 = 0 , V_12 = V_3 ;
if ( V_12 == V_13 )
return F_2 ( V_1 , V_2 , L_3 ) ;
#define F_8 ( T_5 ) \
if (prot & PROT_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
prot &= ~PROT_##n; \
}
F_8 ( V_14 ) ;
F_8 ( V_15 ) ;
F_8 ( V_16 ) ;
#ifdef F_9
F_8 ( V_17 ) ;
#endif
F_8 ( V_18 ) ;
F_8 ( V_19 ) ;
#undef F_8
if ( V_12 )
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 , L_4 , V_11 ? L_5 : L_6 , V_12 ) ;
return V_11 ;
}
static T_1 F_10 ( char * V_1 , T_1 V_2 ,
unsigned long V_3 , T_2 T_3 V_4 ,
T_2 * T_4 V_4 )
{
int V_11 = 0 , V_20 = V_3 ;
#define F_11 ( T_5 ) \
if (flags & MAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MAP_##n; \
}
F_11 ( V_21 ) ;
F_11 ( V_22 ) ;
#ifdef F_12
F_11 ( 32BIT ) ;
#endif
F_11 ( V_23 ) ;
F_11 ( V_24 ) ;
F_11 ( V_25 ) ;
F_11 ( V_26 ) ;
F_11 ( V_27 ) ;
F_11 ( V_18 ) ;
#ifdef F_13
F_11 ( V_28 ) ;
#endif
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
F_11 ( V_31 ) ;
F_11 ( V_32 ) ;
F_11 ( V_33 ) ;
#ifdef F_14
F_11 ( V_34 ) ;
#endif
#undef F_11
if ( V_20 )
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 , L_4 , V_11 ? L_5 : L_6 , V_20 ) ;
return V_11 ;
}
static T_1 F_15 ( char * V_1 , T_1 V_2 ,
unsigned long V_3 , T_2 T_3 V_4 ,
T_2 * T_4 V_4 )
{
int V_35 = V_3 ;
switch ( V_35 ) {
#define F_16 ( T_5 ) case MADV_##n: return scnprintf(bf, size, #n)
F_16 ( V_36 ) ;
F_16 ( V_37 ) ;
F_16 ( V_38 ) ;
F_16 ( V_39 ) ;
F_16 ( V_40 ) ;
F_16 ( REMOVE ) ;
F_16 ( V_41 ) ;
F_16 ( V_42 ) ;
F_16 ( V_43 ) ;
#ifdef F_17
F_16 ( V_44 ) ;
#endif
F_16 ( V_45 ) ;
F_16 ( V_46 ) ;
#ifdef F_18
F_16 ( V_47 ) ;
#endif
#ifdef F_19
F_16 ( V_48 ) ;
#endif
#ifdef F_20
F_16 ( V_49 ) ;
#endif
#ifdef F_21
F_16 ( V_50 ) ;
#endif
#undef V_51
default: break;
}
return F_2 ( V_1 , V_2 , L_2 , V_35 ) ;
}
static T_1 F_22 ( char * V_1 , T_1 V_2 , unsigned long V_3 ,
T_2 T_3 V_4 , T_2 * T_4 )
{
enum T_6 {
V_52 = ( 1 << 0 ) ,
V_53 = ( 1 << 1 ) ,
V_54 = ( 1 << 2 ) ,
V_55 = ( 1 << 3 ) ,
V_56 = ( 1 << 4 ) ,
V_57 = ( 1 << 5 ) ,
};
int V_58 = V_3 ;
int V_59 = V_58 & V_60 ;
T_1 V_11 = 0 ;
switch ( V_59 ) {
#define F_23 ( T_5 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_23 ( V_61 ) ; * T_4 |= V_57 | V_56 ; break;
F_23 ( V_62 ) ; * T_4 |= V_57 | V_56 | V_55 ; break;
F_23 ( V_63 ) ; * T_4 |= V_57 | V_56 | V_55 ; break;
F_23 ( V_64 ) ; * T_4 |= V_57 | V_55 ; break;
F_23 ( V_65 ) ; * T_4 |= V_55 ; break;
F_23 ( V_66 ) ; * T_4 |= V_55 ; break;
F_23 ( V_67 ) ; break;
F_23 ( V_68 ) ; * T_4 |= V_57 | V_56 | V_55 ; break;
F_23 ( V_69 ) ; * T_4 |= V_57 | V_56 | V_55 ; break;
F_23 ( V_70 ) ; * T_4 |= V_57 | V_56 ; break;
F_23 ( V_71 ) ; * T_4 |= V_56 ; break;
F_23 ( V_72 ) ; * T_4 |= V_56 ; break;
F_23 ( V_73 ) ; break;
default: V_11 = F_2 ( V_1 , V_2 , L_2 , V_59 ) ; break;
}
if ( V_58 & V_74 )
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 , L_7 ) ;
if ( V_58 & V_75 )
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 , L_8 ) ;
return V_11 ;
}
static T_1 F_24 ( char * V_1 , T_1 V_2 ,
unsigned long V_3 ,
T_2 T_3 , T_2 * T_4 )
{
int V_11 = 0 , V_20 = V_3 ;
if ( ! ( V_20 & V_76 ) )
* T_4 |= 1 << ( T_3 + 1 ) ;
if ( V_20 == 0 )
return F_2 ( V_1 , V_2 , L_9 ) ;
#define F_25 ( T_5 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_25 ( V_77 ) ;
F_25 ( V_78 ) ;
F_25 ( V_79 ) ;
F_25 ( V_80 ) ;
F_25 ( V_81 ) ;
F_25 ( V_82 ) ;
F_25 ( V_83 ) ;
F_25 ( V_84 ) ;
F_25 ( V_85 ) ;
F_25 ( V_86 ) ;
#ifdef F_26
F_25 ( V_30 ) ;
#elif V_87
F_25 ( V_88 ) ;
#endif
#ifdef F_27
F_25 ( V_89 ) ;
#endif
F_25 ( V_90 ) ;
#ifdef F_28
if ( ( V_20 & V_91 ) == V_91 )
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 , L_10 , V_11 ? L_5 : L_6 , L_11 ) ;
else {
F_25 ( V_92 ) ;
}
#else
F_25 ( V_93 ) ;
#endif
F_25 ( V_94 ) ;
F_25 ( V_95 ) ;
#undef F_25
if ( V_20 )
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 , L_4 , V_11 ? L_5 : L_6 , V_20 ) ;
return V_11 ;
}
static int F_29 ( const void * V_96 , const void * V_97 )
{
const struct V_98 * V_99 = V_97 ;
return strcmp ( V_96 , V_99 -> V_96 ) ;
}
static struct V_98 * F_30 ( const char * V_96 )
{
const int V_100 = F_31 ( V_101 ) ;
return bsearch ( V_96 , V_101 , V_100 , sizeof( struct V_98 ) , F_29 ) ;
}
static T_1 F_32 ( unsigned long V_102 , V_26 * V_103 )
{
double V_104 = ( double ) V_102 / V_105 ;
T_1 V_11 = fprintf ( V_103 , L_12 ) ;
if ( V_104 >= 1.0 )
V_11 += F_33 ( V_103 , V_106 , L_13 , V_104 ) ;
else if ( V_104 >= 0.01 )
V_11 += F_33 ( V_103 , V_107 , L_13 , V_104 ) ;
else
V_11 += F_33 ( V_103 , V_108 , L_13 , V_104 ) ;
return V_11 + fprintf ( V_103 , L_14 ) ;
}
static struct V_109 * F_34 ( void )
{
return F_35 ( sizeof( struct V_109 ) ) ;
}
static struct V_109 * F_36 ( struct V_110 * V_110 , V_26 * V_103 )
{
struct V_109 * V_111 ;
if ( V_110 == NULL )
goto V_112;
if ( V_110 -> V_113 == NULL )
V_110 -> V_113 = F_34 () ;
if ( V_110 -> V_113 == NULL )
goto V_112;
V_111 = V_110 -> V_113 ;
++ V_111 -> V_114 ;
return V_111 ;
V_112:
F_33 ( V_103 , V_106 ,
L_15 ) ;
return NULL ;
}
static bool F_37 ( struct V_115 * V_115 , double V_102 )
{
return V_102 < ( V_115 -> V_116 * V_105 ) ;
}
static T_1 F_38 ( struct V_115 * V_115 , T_7 V_117 , V_26 * V_103 )
{
double V_118 = ( double ) ( V_117 - V_115 -> V_119 ) / V_105 ;
return fprintf ( V_103 , L_16 , V_118 ) ;
}
static void F_39 ( int T_8 V_4 )
{
V_120 = true ;
}
static T_1 F_40 ( struct V_115 * V_115 , struct V_110 * V_110 ,
T_7 V_104 , T_7 V_117 , V_26 * V_103 )
{
T_1 V_11 = F_38 ( V_115 , V_117 , V_103 ) ;
V_11 += F_32 ( V_104 , V_103 ) ;
if ( V_115 -> V_121 )
V_11 += fprintf ( V_103 , L_17 , V_110 -> V_122 ) ;
return V_11 ;
}
static int F_41 ( struct V_115 * V_115 , struct V_123 * V_123 ,
union V_124 * V_125 )
{
int V_126 = 0 ;
switch ( V_125 -> V_127 . type ) {
case V_128 :
F_33 ( V_115 -> V_129 , V_106 ,
L_18 V_130 L_19 , V_125 -> V_131 . V_131 ) ;
V_126 = F_42 ( V_123 , V_125 ) ;
default:
V_126 = F_43 ( V_123 , V_125 ) ;
break;
}
return V_126 ;
}
static int F_44 ( struct V_132 * V_133 ,
union V_124 * V_125 ,
struct V_134 * T_9 V_4 ,
struct V_123 * V_123 )
{
struct V_115 * V_115 = F_45 ( V_133 , struct V_115 , V_133 ) ;
return F_41 ( V_115 , V_123 , V_125 ) ;
}
static int F_46 ( struct V_115 * V_115 , struct V_135 * V_136 )
{
int V_137 = F_47 () ;
if ( V_137 )
return V_137 ;
F_48 ( & V_115 -> V_138 , L_6 , V_139 ) ;
F_49 ( & V_115 -> V_138 ) ;
if ( F_50 ( & V_115 -> V_140 . V_141 ) ) {
V_137 = F_51 ( & V_115 -> V_133 , V_136 -> V_142 ,
F_44 ,
& V_115 -> V_138 ) ;
} else {
V_137 = F_52 ( & V_115 -> V_133 , F_44 ,
& V_115 -> V_138 ) ;
}
if ( V_137 )
F_53 () ;
return V_137 ;
}
static int F_54 ( struct V_143 * V_144 )
{
struct V_145 * V_146 ;
int V_147 = 0 ;
V_144 -> V_148 = calloc ( V_144 -> V_149 -> V_150 . V_151 - 1 , sizeof( void * ) ) ;
if ( V_144 -> V_148 == NULL )
return - 1 ;
for ( V_146 = V_144 -> V_149 -> V_150 . V_152 -> V_153 ; V_146 ; V_146 = V_146 -> V_153 ) {
if ( V_144 -> V_99 && V_144 -> V_99 -> V_148 [ V_147 ] )
V_144 -> V_148 [ V_147 ] = V_144 -> V_99 -> V_148 [ V_147 ] ;
else if ( V_146 -> V_20 & V_154 )
V_144 -> V_148 [ V_147 ] = F_1 ;
++ V_147 ;
}
return 0 ;
}
static int F_55 ( struct V_115 * V_115 , int V_155 )
{
char V_156 [ 128 ] ;
struct V_143 * V_144 ;
const char * V_96 = F_56 ( V_155 , V_115 -> V_157 ) ;
if ( V_96 == NULL )
return - 1 ;
if ( V_155 > V_115 -> V_158 . V_159 ) {
struct V_143 * V_160 = realloc ( V_115 -> V_158 . V_161 , ( V_155 + 1 ) * sizeof( * V_144 ) ) ;
if ( V_160 == NULL )
return - 1 ;
if ( V_115 -> V_158 . V_159 != - 1 ) {
memset ( V_160 + V_115 -> V_158 . V_159 + 1 , 0 ,
( V_155 - V_115 -> V_158 . V_159 ) * sizeof( * V_144 ) ) ;
} else {
memset ( V_160 , 0 , ( V_155 + 1 ) * sizeof( * V_144 ) ) ;
}
V_115 -> V_158 . V_161 = V_160 ;
V_115 -> V_158 . V_159 = V_155 ;
}
V_144 = V_115 -> V_158 . V_161 + V_155 ;
V_144 -> V_96 = V_96 ;
if ( V_115 -> V_162 ) {
bool V_163 = F_57 ( V_115 -> V_162 , V_96 ) != NULL ;
if ( ! ( V_163 ^ V_115 -> V_164 ) ) {
V_144 -> V_165 = true ;
return 0 ;
}
}
V_144 -> V_99 = F_30 ( V_144 -> V_96 ) ;
snprintf ( V_156 , sizeof( V_156 ) , L_20 , V_144 -> V_96 ) ;
V_144 -> V_149 = F_58 ( L_21 , V_156 ) ;
if ( V_144 -> V_149 == NULL && V_144 -> V_99 && V_144 -> V_99 -> V_166 ) {
snprintf ( V_156 , sizeof( V_156 ) , L_20 , V_144 -> V_99 -> V_166 ) ;
V_144 -> V_149 = F_58 ( L_21 , V_156 ) ;
}
if ( V_144 -> V_149 == NULL )
return - 1 ;
return F_54 ( V_144 ) ;
}
static T_1 F_59 ( struct V_143 * V_144 , char * V_1 , T_1 V_2 ,
unsigned long * args )
{
int V_167 = 0 ;
T_1 V_11 = 0 ;
if ( V_144 -> V_149 != NULL ) {
struct V_145 * V_146 ;
T_2 V_168 = 0 , V_169 = 1 ;
for ( V_146 = V_144 -> V_149 -> V_150 . V_152 -> V_153 ; V_146 ;
V_146 = V_146 -> V_153 , ++ V_167 , V_169 <<= 1 ) {
if ( V_168 & V_169 )
continue;
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 ,
L_22 , V_11 ? L_23 : L_6 , V_146 -> V_96 ) ;
if ( V_144 -> V_148 && V_144 -> V_148 [ V_167 ] ) {
V_11 += V_144 -> V_148 [ V_167 ] ( V_1 + V_11 , V_2 - V_11 ,
args [ V_167 ] , V_167 , & V_168 ) ;
} else {
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 ,
L_24 , args [ V_167 ] ) ;
}
}
} else {
while ( V_167 < 6 ) {
V_11 += F_2 ( V_1 + V_11 , V_2 - V_11 ,
L_25 ,
V_11 ? L_23 : L_6 , V_167 , args [ V_167 ] ) ;
++ V_167 ;
}
}
return V_11 ;
}
static struct V_143 * F_60 ( struct V_115 * V_115 ,
struct V_170 * V_171 ,
struct V_134 * T_9 )
{
int V_155 = F_61 ( V_171 , T_9 , L_26 ) ;
if ( V_155 < 0 ) {
if ( V_172 > 1 ) {
static T_7 T_5 ;
fprintf ( V_115 -> V_129 , L_27 V_130 L_28 ,
V_155 , F_62 ( V_171 ) , ++ T_5 ) ;
}
return NULL ;
}
if ( ( V_155 > V_115 -> V_158 . V_159 || V_115 -> V_158 . V_161 [ V_155 ] . V_96 == NULL ) &&
F_55 ( V_115 , V_155 ) )
goto V_173;
if ( ( V_155 > V_115 -> V_158 . V_159 || V_115 -> V_158 . V_161 [ V_155 ] . V_96 == NULL ) )
goto V_173;
return & V_115 -> V_158 . V_161 [ V_155 ] ;
V_173:
if ( V_172 ) {
fprintf ( V_115 -> V_129 , L_29 , V_155 ) ;
if ( V_155 <= V_115 -> V_158 . V_159 && V_115 -> V_158 . V_161 [ V_155 ] . V_96 != NULL )
fprintf ( V_115 -> V_129 , L_30 , V_115 -> V_158 . V_161 [ V_155 ] . V_96 ) ;
fputs ( L_31 , V_115 -> V_129 ) ;
}
return NULL ;
}
static int F_63 ( struct V_115 * V_115 , struct V_170 * V_171 ,
struct V_134 * T_9 )
{
char * V_174 ;
void * args ;
T_1 V_11 = 0 ;
struct V_110 * V_110 ;
struct V_143 * V_144 = F_60 ( V_115 , V_171 , T_9 ) ;
struct V_109 * V_111 ;
if ( V_144 == NULL )
return - 1 ;
if ( V_144 -> V_165 )
return 0 ;
V_110 = F_64 ( & V_115 -> V_138 , T_9 -> V_175 ,
T_9 -> V_122 ) ;
V_111 = F_36 ( V_110 , V_115 -> V_129 ) ;
if ( V_111 == NULL )
return - 1 ;
args = F_65 ( V_171 , T_9 , L_32 ) ;
if ( args == NULL ) {
fprintf ( V_115 -> V_129 , L_33 ) ;
return - 1 ;
}
V_111 = V_110 -> V_113 ;
if ( V_111 -> V_176 == NULL ) {
V_111 -> V_176 = malloc ( 1024 ) ;
if ( ! V_111 -> V_176 )
return - 1 ;
}
V_111 -> V_177 = T_9 -> time ;
V_174 = V_111 -> V_176 ;
V_11 += F_2 ( V_174 + V_11 , 1024 - V_11 , L_34 , V_144 -> V_96 ) ;
V_11 += F_59 ( V_144 , V_174 + V_11 , 1024 - V_11 , args ) ;
if ( ! strcmp ( V_144 -> V_96 , L_35 ) || ! strcmp ( V_144 -> V_96 , L_36 ) ) {
if ( ! V_115 -> V_116 ) {
F_40 ( V_115 , V_110 , 1 , T_9 -> time , V_115 -> V_129 ) ;
fprintf ( V_115 -> V_129 , L_37 , V_111 -> V_176 ) ;
}
} else
V_111 -> V_178 = true ;
return 0 ;
}
static int F_66 ( struct V_115 * V_115 , struct V_170 * V_171 ,
struct V_134 * T_9 )
{
int V_126 ;
T_7 V_104 = 0 ;
struct V_110 * V_110 ;
struct V_143 * V_144 = F_60 ( V_115 , V_171 , T_9 ) ;
struct V_109 * V_111 ;
if ( V_144 == NULL )
return - 1 ;
if ( V_144 -> V_165 )
return 0 ;
V_110 = F_64 ( & V_115 -> V_138 , T_9 -> V_175 ,
T_9 -> V_122 ) ;
V_111 = F_36 ( V_110 , V_115 -> V_129 ) ;
if ( V_111 == NULL )
return - 1 ;
V_126 = F_61 ( V_171 , T_9 , L_38 ) ;
V_111 = V_110 -> V_113 ;
V_111 -> V_179 = T_9 -> time ;
if ( V_111 -> V_177 ) {
V_104 = T_9 -> time - V_111 -> V_177 ;
if ( F_37 ( V_115 , V_104 ) )
goto V_180;
} else if ( V_115 -> V_116 )
goto V_180;
F_40 ( V_115 , V_110 , V_104 , T_9 -> time , V_115 -> V_129 ) ;
if ( V_111 -> V_178 ) {
fprintf ( V_115 -> V_129 , L_39 , V_111 -> V_176 ) ;
} else {
fprintf ( V_115 -> V_129 , L_40 ) ;
F_33 ( V_115 -> V_129 , V_107 , L_41 ) ;
fprintf ( V_115 -> V_129 , L_42 , V_144 -> V_96 ) ;
}
if ( V_144 -> V_99 == NULL ) {
V_181:
fprintf ( V_115 -> V_129 , L_43 , V_126 ) ;
} else if ( V_126 < 0 && V_144 -> V_99 -> V_182 ) {
char V_1 [ 256 ] ;
const char * V_183 = F_67 ( - V_126 , V_1 , sizeof( V_1 ) ) ,
* V_184 = F_68 ( - V_126 ) ;
fprintf ( V_115 -> V_129 , L_44 , V_184 , V_183 ) ;
} else if ( V_126 == 0 && V_144 -> V_99 -> V_185 )
fprintf ( V_115 -> V_129 , L_45 ) ;
else if ( V_144 -> V_99 -> V_186 )
fprintf ( V_115 -> V_129 , L_46 , V_126 ) ;
else
goto V_181;
fputc ( '\n' , V_115 -> V_129 ) ;
V_180:
V_111 -> V_178 = false ;
return 0 ;
}
static int F_69 ( struct V_115 * V_115 , struct V_170 * V_171 ,
struct V_134 * T_9 )
{
T_7 V_187 = F_61 ( V_171 , T_9 , L_47 ) ;
double V_188 = ( double ) V_187 / V_105 ;
struct V_110 * V_110 = F_64 ( & V_115 -> V_138 ,
T_9 -> V_175 ,
T_9 -> V_122 ) ;
struct V_109 * V_111 = F_36 ( V_110 , V_115 -> V_129 ) ;
if ( V_111 == NULL )
goto V_189;
V_111 -> V_188 += V_188 ;
V_115 -> V_188 += V_188 ;
return 0 ;
V_189:
fprintf ( V_115 -> V_129 , L_48 V_130 L_49 V_130 L_50 ,
V_171 -> V_96 ,
F_70 ( V_171 , T_9 , L_51 ) ,
( V_190 ) F_61 ( V_171 , T_9 , L_52 ) ,
V_187 ,
F_61 ( V_171 , T_9 , L_53 ) ) ;
return 0 ;
}
static bool F_71 ( struct V_115 * V_115 , struct V_134 * T_9 )
{
if ( ( V_115 -> V_191 && F_72 ( V_115 -> V_191 , T_9 -> V_175 ) ) ||
( V_115 -> V_192 && F_72 ( V_115 -> V_192 , T_9 -> V_122 ) ) )
return false ;
if ( V_115 -> V_191 || V_115 -> V_192 )
return true ;
return false ;
}
static int F_73 ( struct V_132 * V_133 ,
union V_124 * V_125 V_4 ,
struct V_134 * T_9 ,
struct V_170 * V_171 ,
struct V_123 * V_123 V_4 )
{
struct V_115 * V_115 = F_45 ( V_133 , struct V_115 , V_133 ) ;
int V_137 = 0 ;
T_10 V_193 = V_171 -> V_193 . V_194 ;
if ( F_71 ( V_115 , T_9 ) )
return 0 ;
if ( V_115 -> V_119 == 0 )
V_115 -> V_119 = T_9 -> time ;
if ( V_193 )
V_193 ( V_115 , V_171 , T_9 ) ;
return V_137 ;
}
static bool
F_74 ( struct V_195 * V_196 , const char * V_96 )
{
struct V_170 * V_171 ;
V_171 = F_75 ( V_196 -> V_136 , V_96 ) ;
return V_171 != NULL ;
}
static int F_76 ( struct V_115 * V_115 )
{
if ( V_115 -> V_140 . V_141 . V_175 ) {
V_115 -> V_191 = F_77 ( V_115 -> V_140 . V_141 . V_175 ) ;
if ( V_115 -> V_191 == NULL ) {
F_78 ( L_54 ) ;
return - V_197 ;
}
}
if ( V_115 -> V_140 . V_141 . V_122 ) {
V_115 -> V_192 = F_77 ( V_115 -> V_140 . V_141 . V_122 ) ;
if ( V_115 -> V_192 == NULL ) {
F_78 ( L_55 ) ;
return - V_197 ;
}
}
return 0 ;
}
static int F_79 ( struct V_115 * V_115 , int V_198 , const char * * V_199 )
{
struct V_135 * V_136 = F_80 () ;
struct V_170 * V_171 ;
int V_137 = - 1 , V_167 ;
unsigned long V_200 ;
const bool V_201 = V_198 > 0 ;
if ( V_136 == NULL ) {
fprintf ( V_115 -> V_129 , L_56 ) ;
goto V_180;
}
if ( F_81 ( V_136 , L_57 , L_58 , F_63 ) ||
F_81 ( V_136 , L_57 , L_59 , F_66 ) ) {
fprintf ( V_115 -> V_129 , L_60 ) ;
goto V_202;
}
if ( V_115 -> V_203 &&
F_81 ( V_136 , L_61 , L_62 ,
F_69 ) ) {
fprintf ( V_115 -> V_129 , L_63 ) ;
goto V_202;
}
V_137 = F_82 ( V_136 , & V_115 -> V_140 . V_141 ) ;
if ( V_137 < 0 ) {
fprintf ( V_115 -> V_129 , L_64 ) ;
goto V_202;
}
V_137 = F_46 ( V_115 , V_136 ) ;
if ( V_137 < 0 ) {
fprintf ( V_115 -> V_129 , L_65 ) ;
goto V_204;
}
F_83 ( V_136 , & V_115 -> V_140 ) ;
signal ( V_205 , F_39 ) ;
signal ( V_206 , F_39 ) ;
if ( V_201 ) {
V_137 = F_84 ( V_136 , & V_115 -> V_140 . V_141 ,
V_199 , false , false ) ;
if ( V_137 < 0 ) {
fprintf ( V_115 -> V_129 , L_66 ) ;
goto V_204;
}
}
V_137 = F_85 ( V_136 ) ;
if ( V_137 < 0 ) {
fprintf ( V_115 -> V_129 , L_67 , strerror ( V_207 ) ) ;
goto V_204;
}
V_137 = F_86 ( V_136 , V_208 , false ) ;
if ( V_137 < 0 ) {
fprintf ( V_115 -> V_129 , L_68 , strerror ( V_207 ) ) ;
goto V_209;
}
F_87 ( V_136 ) ;
if ( V_201 )
F_88 ( V_136 ) ;
V_115 -> V_121 = V_136 -> V_142 -> V_210 [ 0 ] == - 1 || V_136 -> V_142 -> V_211 > 1 ;
V_212:
V_200 = V_115 -> V_114 ;
for ( V_167 = 0 ; V_167 < V_136 -> V_213 ; V_167 ++ ) {
union V_124 * V_125 ;
while ( ( V_125 = F_89 ( V_136 , V_167 ) ) != NULL ) {
const T_11 type = V_125 -> V_127 . type ;
T_10 V_193 ;
struct V_134 T_9 ;
++ V_115 -> V_114 ;
V_137 = F_90 ( V_136 , V_125 , & T_9 ) ;
if ( V_137 ) {
fprintf ( V_115 -> V_129 , L_69 , V_137 ) ;
goto V_214;
}
if ( V_115 -> V_119 == 0 )
V_115 -> V_119 = T_9 . time ;
if ( type != V_215 ) {
F_41 ( V_115 , & V_115 -> V_138 , V_125 ) ;
continue;
}
V_171 = F_91 ( V_136 , T_9 . V_155 ) ;
if ( V_171 == NULL ) {
fprintf ( V_115 -> V_129 , L_70 V_130 L_71 , T_9 . V_155 ) ;
goto V_214;
}
if ( T_9 . V_216 == NULL ) {
fprintf ( V_115 -> V_129 , L_72 ,
F_62 ( V_171 ) , T_9 . V_122 ,
T_9 . V_217 , T_9 . V_218 ) ;
goto V_214;
}
V_193 = V_171 -> V_193 . V_194 ;
V_193 ( V_115 , V_171 , & T_9 ) ;
V_214:
F_92 ( V_136 , V_167 ) ;
if ( V_120 )
goto V_219;
}
}
if ( V_115 -> V_114 == V_200 ) {
if ( V_120 )
goto V_219;
F_93 ( V_136 -> V_220 , V_136 -> V_221 , - 1 ) ;
}
if ( V_120 )
F_94 ( V_136 ) ;
goto V_212;
V_219:
F_95 ( V_136 ) ;
V_209:
F_96 ( V_136 ) ;
V_204:
F_97 ( V_136 ) ;
V_202:
F_98 ( V_136 ) ;
V_180:
return V_137 ;
}
static int F_99 ( struct V_115 * V_115 )
{
const struct V_222 V_223 [] = {
{ L_73 , F_63 , } ,
{ L_74 , F_66 , } ,
} ;
struct V_195 * V_196 ;
int V_137 = - 1 ;
V_115 -> V_133 . T_9 = F_73 ;
V_115 -> V_133 . V_224 = V_225 ;
V_115 -> V_133 . V_226 = V_227 ;
V_115 -> V_133 . V_228 = V_229 ;
V_115 -> V_133 . exit = V_230 ;
V_115 -> V_133 . V_231 = V_232 ;
V_115 -> V_133 . V_233 = V_234 ;
V_115 -> V_133 . V_235 = V_236 ;
V_115 -> V_133 . V_237 = V_238 ;
V_115 -> V_133 . V_239 = true ;
V_115 -> V_133 . V_240 = true ;
V_115 -> V_121 = true ;
if ( F_47 () < 0 )
return - 1 ;
V_196 = F_100 ( V_241 , V_242 , 0 , false ,
& V_115 -> V_133 ) ;
if ( V_196 == NULL )
return - V_243 ;
V_137 = F_101 ( V_196 , V_223 ) ;
if ( V_137 )
goto V_180;
if ( ! F_74 ( V_196 , L_73 ) ) {
F_78 ( L_75 ) ;
goto V_180;
}
if ( ! F_74 ( V_196 , L_74 ) ) {
F_78 ( L_76 ) ;
goto V_180;
}
V_137 = F_76 ( V_115 ) ;
if ( V_137 != 0 )
goto V_180;
F_102 () ;
V_137 = F_103 ( V_196 , & V_115 -> V_133 ) ;
if ( V_137 )
F_78 ( L_77 , V_137 ) ;
V_180:
F_104 ( V_196 ) ;
return V_137 ;
}
static T_1 F_105 ( V_26 * V_103 )
{
T_1 V_11 ;
V_11 = fprintf ( V_103 , L_78 ) ;
V_11 += fprintf ( V_103 , L_79 ) ;
V_11 += fprintf ( V_103 , L_80 ) ;
V_11 += fprintf ( V_103 , L_81 ) ;
return V_11 ;
}
static T_1 F_106 ( struct V_115 * V_115 , V_26 * V_103 )
{
T_1 V_11 = F_105 ( V_103 ) ;
struct V_244 * V_245 ;
for ( V_245 = F_107 ( & V_115 -> V_138 . V_142 ) ; V_245 ; V_245 = F_108 ( V_245 ) ) {
struct V_110 * V_110 = F_109 ( V_245 , struct V_110 , V_244 ) ;
struct V_109 * V_111 = V_110 -> V_113 ;
const char * V_246 ;
double V_247 ;
if ( V_111 == NULL )
continue;
V_247 = ( double ) V_111 -> V_114 / V_115 -> V_114 * 100.0 ;
V_246 = V_108 ;
if ( V_247 > 50.0 )
V_246 = V_106 ;
else if ( V_247 > 25.0 )
V_246 = V_248 ;
else if ( V_247 > 5.0 )
V_246 = V_107 ;
V_11 += F_33 ( V_103 , V_246 , L_82 , V_110 -> V_228 ) ;
V_11 += fprintf ( V_103 , L_83 , V_110 -> V_122 , V_111 -> V_114 ) ;
V_11 += F_33 ( V_103 , V_246 , L_84 , V_247 ) ;
V_11 += fprintf ( V_103 , L_85 , V_111 -> V_188 ) ;
}
return V_11 ;
}
static int F_110 ( const struct V_249 * V_250 , const char * V_251 ,
int T_12 V_4 )
{
struct V_115 * V_115 = V_250 -> V_252 ;
V_115 -> V_116 = atof ( V_251 ) ;
return 0 ;
}
static int F_111 ( struct V_115 * V_115 , const char * V_253 )
{
struct V_254 V_255 ;
if ( ! V_254 ( V_253 , & V_255 ) && V_255 . V_256 ) {
char V_257 [ V_258 ] ;
F_2 ( V_257 , sizeof( V_257 ) , L_86 , V_253 ) ;
F_112 ( V_257 ) ;
rename ( V_253 , V_257 ) ;
}
V_115 -> V_129 = fopen ( V_253 , L_87 ) ;
return V_115 -> V_129 == NULL ? - V_207 : 0 ;
}
int F_113 ( int V_198 , const char * * V_199 , const char * T_13 V_4 )
{
const char * const V_259 [] = {
L_88 ,
L_89 ,
NULL
} ;
struct V_115 V_115 = {
. V_157 = F_114 () ,
. V_158 = {
. V_159 = - 1 ,
} ,
. V_140 = {
. V_141 = {
. V_260 = V_208 ,
. V_261 = true ,
} ,
. V_262 = V_208 ,
. V_263 = V_264 ,
. V_265 = true ,
. V_266 = 1024 ,
} ,
. V_129 = stdout ,
} ;
const char * V_267 = NULL ;
const char * V_268 = NULL ;
const struct V_249 V_269 [] = {
F_115 ( 'e' , L_90 , & V_268 , L_90 ,
L_91 ) ,
F_115 ( 'o' , L_92 , & V_267 , L_93 , L_94 ) ,
F_115 ( 'i' , L_95 , & V_241 , L_93 , L_96 ) ,
F_115 ( 'p' , L_52 , & V_115 . V_140 . V_141 . V_175 , L_52 ,
L_97 ) ,
F_115 ( 't' , L_98 , & V_115 . V_140 . V_141 . V_122 , L_98 ,
L_99 ) ,
F_116 ( 'a' , L_100 , & V_115 . V_140 . V_141 . V_270 ,
L_101 ) ,
F_115 ( 'C' , L_102 , & V_115 . V_140 . V_141 . V_271 , L_102 ,
L_103 ) ,
F_116 ( 0 , L_104 , & V_115 . V_140 . V_272 ,
L_105 ) ,
F_117 ( 'm' , L_106 , & V_115 . V_140 . V_266 ,
L_107 ) ,
F_115 ( 'u' , L_108 , & V_115 . V_140 . V_141 . V_273 , L_109 ,
L_110 ) ,
F_118 ( 0 , L_111 , & V_115 , L_112 ,
L_113 ,
F_110 ) ,
F_116 ( 0 , L_61 , & V_115 . V_203 , L_114 ) ,
F_119 ( 'v' , L_115 , & V_172 , L_116 ) ,
F_120 ()
} ;
int V_137 ;
char V_1 [ V_274 ] ;
V_198 = F_121 ( V_198 , V_199 , V_269 , V_259 , 0 ) ;
if ( V_267 != NULL ) {
V_137 = F_111 ( & V_115 , V_267 ) ;
if ( V_137 < 0 ) {
perror ( L_117 ) ;
goto V_180;
}
}
if ( V_268 != NULL ) {
const char * V_275 = V_268 ;
V_115 . V_164 = * V_275 == '!' ;
if ( V_115 . V_164 )
++ V_275 ;
V_115 . V_162 = F_122 ( true , V_275 ) ;
if ( V_115 . V_162 == NULL ) {
fputs ( L_118 ,
V_115 . V_129 ) ;
V_137 = - V_243 ;
goto V_276;
}
}
V_137 = F_123 ( & V_115 . V_140 . V_141 ) ;
if ( V_137 ) {
F_124 ( & V_115 . V_140 . V_141 , V_137 , V_1 , sizeof( V_1 ) ) ;
fprintf ( V_115 . V_129 , L_119 , V_1 ) ;
goto V_276;
}
V_137 = F_125 ( & V_115 . V_140 . V_141 ) ;
if ( V_137 ) {
F_124 ( & V_115 . V_140 . V_141 , V_137 , V_1 , sizeof( V_1 ) ) ;
fprintf ( V_115 . V_129 , L_119 , V_1 ) ;
goto V_276;
}
if ( ! V_198 && F_126 ( & V_115 . V_140 . V_141 ) )
V_115 . V_140 . V_141 . V_270 = true ;
if ( V_241 )
V_137 = F_99 ( & V_115 ) ;
else
V_137 = F_79 ( & V_115 , V_198 , V_199 ) ;
if ( V_115 . V_203 && ! V_137 )
F_106 ( & V_115 , V_115 . V_129 ) ;
V_276:
if ( V_267 != NULL )
fclose ( V_115 . V_129 ) ;
V_180:
return V_137 ;
}
