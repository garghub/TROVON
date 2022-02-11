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
int V_42 = 0 , V_43 = V_32 -> V_37 ;
if ( V_43 == V_44 )
return F_16 ( V_29 , V_6 , L_8 ) ;
#define F_24 ( T_2 ) \
if (prot & PROT_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
prot &= ~PROT_##n; \
}
F_24 ( V_45 ) ;
F_24 ( V_46 ) ;
F_24 ( V_47 ) ;
#ifdef F_25
F_24 ( V_48 ) ;
#endif
F_24 ( V_49 ) ;
F_24 ( V_50 ) ;
#undef F_24
if ( V_43 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_43 ) ;
return V_42 ;
}
static T_1 F_26 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
#define F_27 ( T_2 ) \
if (flags & MAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MAP_##n; \
}
F_27 ( V_52 ) ;
F_27 ( V_53 ) ;
#ifdef F_28
F_27 ( 32BIT ) ;
#endif
F_27 ( V_54 ) ;
F_27 ( V_55 ) ;
F_27 ( V_56 ) ;
F_27 ( V_57 ) ;
F_27 ( V_58 ) ;
F_27 ( V_49 ) ;
#ifdef F_29
F_27 ( V_59 ) ;
#endif
F_27 ( V_60 ) ;
F_27 ( V_61 ) ;
F_27 ( V_62 ) ;
F_27 ( V_63 ) ;
F_27 ( V_64 ) ;
#ifdef F_30
F_27 ( V_65 ) ;
#endif
#undef F_27
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_31 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
#define F_32 ( T_2 ) \
if (flags & MREMAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MREMAP_##n; \
}
F_32 ( V_66 ) ;
#ifdef F_33
F_32 ( V_58 ) ;
#endif
#undef F_32
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_34 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_67 = V_32 -> V_37 ;
switch ( V_67 ) {
#define F_35 ( T_2 ) case MADV_##n: return scnprintf(bf, size, #n)
F_35 ( V_68 ) ;
F_35 ( V_69 ) ;
F_35 ( V_70 ) ;
F_35 ( V_71 ) ;
F_35 ( V_72 ) ;
F_35 ( REMOVE ) ;
F_35 ( V_73 ) ;
F_35 ( V_74 ) ;
F_35 ( V_75 ) ;
#ifdef F_36
F_35 ( V_76 ) ;
#endif
F_35 ( V_77 ) ;
F_35 ( V_78 ) ;
#ifdef F_37
F_35 ( V_79 ) ;
#endif
#ifdef F_38
F_35 ( V_80 ) ;
#endif
#ifdef F_39
F_35 ( V_81 ) ;
#endif
#ifdef F_40
F_35 ( V_82 ) ;
#endif
#undef V_83
default: break;
}
return F_16 ( V_29 , V_6 , L_5 , V_67 ) ;
}
static T_1 F_41 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_84 = V_32 -> V_37 ;
if ( V_84 == 0 )
return F_16 ( V_29 , V_6 , L_8 ) ;
#define F_42 ( T_3 ) \
if ((op & LOCK_##cmd) == LOCK_##cmd) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #cmd); \
op &= ~LOCK_##cmd; \
}
F_42 ( V_85 ) ;
F_42 ( V_86 ) ;
F_42 ( V_87 ) ;
F_42 ( V_88 ) ;
F_42 ( V_89 ) ;
F_42 ( V_90 ) ;
F_42 ( V_46 ) ;
F_42 ( V_47 ) ;
#undef V_91
if ( V_84 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_84 ) ;
return V_42 ;
}
static T_1 F_43 ( char * V_29 , T_1 V_6 , struct V_31 * V_32 )
{
enum T_4 {
V_92 = ( 1 << 0 ) ,
V_93 = ( 1 << 1 ) ,
V_94 = ( 1 << 2 ) ,
V_95 = ( 1 << 3 ) ,
V_96 = ( 1 << 4 ) ,
V_97 = ( 1 << 5 ) ,
};
int V_84 = V_32 -> V_37 ;
int T_3 = V_84 & V_98 ;
T_1 V_42 = 0 ;
switch ( T_3 ) {
#define F_44 ( T_2 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_44 ( V_99 ) ; V_32 -> V_100 |= V_97 | V_96 ; break;
F_44 ( V_101 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_44 ( V_102 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_44 ( V_103 ) ; V_32 -> V_100 |= V_97 | V_95 ; break;
F_44 ( V_104 ) ; V_32 -> V_100 |= V_95 ; break;
F_44 ( V_105 ) ; V_32 -> V_100 |= V_95 ; break;
F_44 ( V_106 ) ; break;
F_44 ( V_107 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_44 ( V_108 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_44 ( V_109 ) ; V_32 -> V_100 |= V_97 | V_96 ; break;
F_44 ( V_110 ) ; V_32 -> V_100 |= V_96 ; break;
F_44 ( V_111 ) ; V_32 -> V_100 |= V_96 ; break;
F_44 ( V_112 ) ; break;
default: V_42 = F_16 ( V_29 , V_6 , L_5 , T_3 ) ; break;
}
if ( V_84 & V_113 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_12 ) ;
if ( V_84 & V_114 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_13 ) ;
return V_42 ;
}
static T_1 F_45 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
T_1 V_42 ;
int type = V_32 -> V_37 ,
V_51 = type & ~ V_115 ;
type &= V_115 ;
switch ( type ) {
#define F_46 ( T_2 ) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
F_46 ( V_116 ) ;
F_46 ( V_117 ) ;
F_46 ( V_118 ) ;
F_46 ( V_119 ) ;
F_46 ( V_120 ) ;
F_46 ( V_121 ) ;
F_46 ( V_122 ) ;
#undef F_46
default:
V_42 = F_16 ( V_29 , V_6 , L_5 , type ) ;
}
#define F_47 ( T_2 ) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
F_47 ( V_123 ) ;
F_47 ( V_61 ) ;
#undef F_47
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_14 , V_51 ) ;
return V_42 ;
}
static T_1 F_48 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( V_51 == 0 )
return F_16 ( V_29 , V_6 , L_8 ) ;
#define F_49 ( T_2 ) \
if (flags & MSG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MSG_##n; \
}
F_49 ( V_124 ) ;
F_49 ( V_125 ) ;
F_49 ( V_126 ) ;
F_49 ( V_127 ) ;
F_49 ( V_128 ) ;
F_49 ( V_129 ) ;
F_49 ( V_130 ) ;
F_49 ( V_131 ) ;
F_49 ( V_132 ) ;
F_49 ( V_133 ) ;
F_49 ( V_134 ) ;
F_49 ( V_135 ) ;
F_49 ( V_136 ) ;
F_49 ( V_137 ) ;
F_49 ( V_138 ) ;
F_49 ( V_139 ) ;
F_49 ( V_140 ) ;
F_49 ( V_141 ) ;
F_49 ( V_142 ) ;
F_49 ( V_143 ) ;
F_49 ( V_144 ) ;
#undef F_49
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_50 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
T_1 V_42 = 0 ;
int V_145 = V_32 -> V_37 ;
if ( V_145 == V_146 )
return F_16 ( V_29 , V_6 , L_15 ) ;
#define F_51 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_51 ( V_147 ) ;
F_51 ( V_148 ) ;
F_51 ( V_149 ) ;
#undef F_51
if ( V_145 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_14 , V_145 ) ;
return V_42 ;
}
static T_1 F_52 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( ! ( V_51 & V_150 ) )
V_32 -> V_100 |= 1 << ( V_32 -> V_36 + 1 ) ;
if ( V_51 == 0 )
return F_16 ( V_29 , V_6 , L_16 ) ;
#define F_53 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_53 ( V_151 ) ;
F_53 ( V_152 ) ;
F_53 ( V_123 ) ;
F_53 ( V_153 ) ;
F_53 ( V_154 ) ;
F_53 ( V_155 ) ;
F_53 ( V_156 ) ;
F_53 ( V_157 ) ;
F_53 ( V_158 ) ;
F_53 ( V_159 ) ;
#ifdef F_54
F_53 ( V_61 ) ;
#elif V_160
F_53 ( V_161 ) ;
#endif
#ifdef F_55
F_53 ( V_162 ) ;
#endif
F_53 ( V_163 ) ;
#ifdef F_56
if ( ( V_51 & V_164 ) == V_164 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_17 , V_42 ? L_10 : L_11 , L_18 ) ;
else {
F_53 ( V_165 ) ;
}
#else
F_53 ( V_166 ) ;
#endif
F_53 ( V_130 ) ;
F_53 ( V_167 ) ;
#undef F_53
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_57 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( V_51 == 0 )
return 0 ;
#define F_53 ( T_2 ) \
if (flags & PERF_FLAG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~PERF_FLAG_##n; \
}
F_53 ( V_168 ) ;
F_53 ( V_169 ) ;
F_53 ( V_170 ) ;
F_53 ( V_171 ) ;
#undef F_53
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_58 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( V_51 == 0 )
return F_16 ( V_29 , V_6 , L_8 ) ;
#define F_53 ( T_2 ) \
if (flags & EFD_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~EFD_##n; \
}
F_53 ( V_172 ) ;
F_53 ( V_123 ) ;
F_53 ( V_61 ) ;
#undef F_53
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_59 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
#define F_53 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_53 ( V_123 ) ;
F_53 ( V_61 ) ;
#undef F_53
if ( V_51 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_60 ( char * V_29 , T_1 V_6 , struct V_31 * V_32 )
{
int V_173 = V_32 -> V_37 ;
switch ( V_173 ) {
#define F_61 ( T_2 ) case SIG##n: return scnprintf(bf, size, #n)
F_61 ( V_174 ) ;
F_61 ( INT ) ;
F_61 ( V_175 ) ;
F_61 ( V_176 ) ;
F_61 ( V_177 ) ;
F_61 ( V_178 ) ;
F_61 ( V_179 ) ;
F_61 ( V_180 ) ;
F_61 ( V_181 ) ;
F_61 ( V_182 ) ;
F_61 ( V_183 ) ;
F_61 ( V_184 ) ;
F_61 ( V_185 ) ;
F_61 ( V_186 ) ;
F_61 ( V_187 ) ;
F_61 ( V_188 ) ;
F_61 ( V_189 ) ;
F_61 ( V_190 ) ;
F_61 ( V_191 ) ;
F_61 ( V_192 ) ;
F_61 ( V_193 ) ;
F_61 ( V_194 ) ;
F_61 ( V_195 ) ;
F_61 ( V_196 ) ;
F_61 ( V_197 ) ;
F_61 ( V_198 ) ;
F_61 ( V_199 ) ;
F_61 ( V_200 ) ;
F_61 ( V_201 ) ;
F_61 ( V_202 ) ;
#ifdef F_62
F_61 ( V_203 ) ;
#endif
#ifdef F_63
F_61 ( V_204 ) ;
#endif
#ifdef F_64
F_61 ( V_205 ) ;
#endif
default: break;
}
return F_16 ( V_29 , V_6 , L_5 , V_173 ) ;
}
static int F_65 ( const void * V_20 , const void * V_206 )
{
const struct V_207 * V_208 = V_206 ;
return strcmp ( V_20 , V_208 -> V_20 ) ;
}
static struct V_207 * F_66 ( const char * V_20 )
{
const int V_209 = F_67 ( V_210 ) ;
return bsearch ( V_20 , V_210 , V_209 , sizeof( struct V_207 ) , F_65 ) ;
}
static T_1 F_68 ( unsigned long V_211 , V_57 * V_212 )
{
double V_213 = ( double ) V_211 / V_214 ;
T_1 V_42 = fprintf ( V_212 , L_19 ) ;
if ( V_213 >= 1.0 )
V_42 += F_69 ( V_212 , V_215 , L_20 , V_213 ) ;
else if ( V_213 >= 0.01 )
V_42 += F_69 ( V_212 , V_216 , L_20 , V_213 ) ;
else
V_42 += F_69 ( V_212 , V_217 , L_20 , V_213 ) ;
return V_42 + fprintf ( V_212 , L_21 ) ;
}
static struct V_218 * F_70 ( void )
{
struct V_218 * V_219 = F_71 ( sizeof( struct V_218 ) ) ;
if ( V_219 )
V_219 -> V_220 . V_221 = - 1 ;
V_219 -> V_222 = F_72 ( NULL ) ;
return V_219 ;
}
static struct V_218 * F_73 ( struct V_223 * V_223 , V_57 * V_212 )
{
struct V_218 * V_219 ;
if ( V_223 == NULL )
goto V_224;
if ( F_74 ( V_223 ) == NULL )
F_75 ( V_223 , F_70 () ) ;
if ( F_74 ( V_223 ) == NULL )
goto V_224;
V_219 = F_74 ( V_223 ) ;
++ V_219 -> V_225 ;
return V_219 ;
V_224:
F_69 ( V_212 , V_215 ,
L_22 ) ;
return NULL ;
}
static int F_76 ( struct V_223 * V_223 , int V_40 , const char * V_226 )
{
struct V_218 * V_219 = F_74 ( V_223 ) ;
if ( V_40 > V_219 -> V_220 . V_221 ) {
char * * V_227 = realloc ( V_219 -> V_220 . V_228 , ( V_40 + 1 ) * sizeof( char * ) ) ;
if ( V_227 == NULL )
return - 1 ;
if ( V_219 -> V_220 . V_221 != - 1 ) {
memset ( V_227 + V_219 -> V_220 . V_221 + 1 , 0 ,
( V_40 - V_219 -> V_220 . V_221 ) * sizeof( char * ) ) ;
} else {
memset ( V_227 , 0 , ( V_40 + 1 ) * sizeof( char * ) ) ;
}
V_219 -> V_220 . V_228 = V_227 ;
V_219 -> V_220 . V_221 = V_40 ;
}
V_219 -> V_220 . V_228 [ V_40 ] = F_77 ( V_226 ) ;
return V_219 -> V_220 . V_228 [ V_40 ] != NULL ? 0 : - 1 ;
}
static int F_78 ( struct V_223 * V_223 , int V_40 )
{
char V_229 [ V_230 ] , V_226 [ V_230 ] ;
struct V_231 V_232 ;
int V_233 ;
if ( V_223 -> V_234 == V_223 -> V_235 ) {
F_16 ( V_229 , sizeof( V_229 ) ,
L_23 , V_223 -> V_234 , V_40 ) ;
} else {
F_16 ( V_229 , sizeof( V_229 ) ,
L_24 , V_223 -> V_234 , V_223 -> V_235 , V_40 ) ;
}
if ( F_79 ( V_229 , & V_232 ) < 0 || V_232 . V_236 + 1 > ( V_237 ) sizeof( V_226 ) )
return - 1 ;
V_233 = F_80 ( V_229 , V_226 , sizeof( V_226 ) ) ;
if ( V_233 < 0 || V_233 > V_232 . V_236 )
return - 1 ;
V_226 [ V_233 ] = '\0' ;
return F_76 ( V_223 , V_40 , V_226 ) ;
}
static const char * F_81 ( struct V_223 * V_223 , int V_40 ,
struct V_238 * V_238 )
{
struct V_218 * V_219 = F_74 ( V_223 ) ;
if ( V_219 == NULL )
return NULL ;
if ( V_40 < 0 )
return NULL ;
if ( ( V_40 > V_219 -> V_220 . V_221 || V_219 -> V_220 . V_228 [ V_40 ] == NULL ) ) {
if ( ! V_238 -> V_239 )
return NULL ;
++ V_238 -> V_240 . V_241 ;
if ( F_78 ( V_223 , V_40 ) )
return NULL ;
}
return V_219 -> V_220 . V_228 [ V_40 ] ;
}
static T_1 F_20 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_16 ( V_29 , V_6 , L_4 , V_40 ) ;
const char * V_242 = F_81 ( V_32 -> V_223 , V_40 , V_32 -> V_238 ) ;
if ( V_242 )
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 , L_25 , V_242 ) ;
return V_42 ;
}
static T_1 F_82 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_20 ( V_29 , V_6 , V_32 ) ;
struct V_218 * V_219 = F_74 ( V_32 -> V_223 ) ;
if ( V_219 && V_40 >= 0 && V_40 <= V_219 -> V_220 . V_221 )
F_8 ( & V_219 -> V_220 . V_228 [ V_40 ] ) ;
return V_42 ;
}
static void F_83 ( struct V_223 * V_223 , const char * V_29 ,
unsigned long V_243 )
{
struct V_218 * V_219 = F_74 ( V_223 ) ;
V_219 -> V_244 . V_243 = V_243 ;
V_219 -> V_244 . V_245 = V_29 - V_219 -> V_246 ;
}
static T_1 F_84 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
unsigned long V_243 = V_32 -> V_37 ;
if ( ! V_32 -> V_238 -> V_247 )
return F_16 ( V_29 , V_6 , L_5 , V_243 ) ;
F_83 ( V_32 -> V_223 , V_29 , V_243 ) ;
return 0 ;
}
static bool F_85 ( struct V_238 * V_238 , double V_211 )
{
return V_211 < ( V_238 -> V_248 * V_214 ) ;
}
static T_1 F_86 ( struct V_238 * V_238 , T_5 V_249 , V_57 * V_212 )
{
double V_250 = ( double ) ( V_249 - V_238 -> V_251 ) / V_214 ;
return fprintf ( V_212 , L_26 , V_250 ) ;
}
static void F_87 ( int V_173 )
{
V_252 = true ;
V_253 = V_173 == V_254 ;
}
static T_1 F_88 ( struct V_238 * V_238 , struct V_223 * V_223 ,
T_5 V_213 , T_5 V_249 , V_57 * V_212 )
{
T_1 V_42 = F_86 ( V_238 , V_249 , V_212 ) ;
V_42 += F_68 ( V_213 , V_212 ) ;
if ( V_238 -> V_255 ) {
if ( V_238 -> V_256 )
V_42 += fprintf ( V_212 , L_27 , F_89 ( V_223 ) ) ;
V_42 += fprintf ( V_212 , L_28 , V_223 -> V_235 ) ;
}
return V_42 ;
}
static int F_90 ( struct V_238 * V_238 , struct V_257 * V_257 ,
union V_258 * V_259 , struct V_14 * V_15 )
{
int V_233 = 0 ;
switch ( V_259 -> V_260 . type ) {
case V_261 :
F_69 ( V_238 -> V_262 , V_215 ,
L_29 V_263 L_30 , V_259 -> V_264 . V_264 ) ;
V_233 = F_91 ( V_257 , V_259 , V_15 ) ;
default:
V_233 = F_92 ( V_257 , V_259 , V_15 ) ;
break;
}
return V_233 ;
}
static int F_93 ( struct V_265 * V_266 ,
union V_258 * V_259 ,
struct V_14 * V_15 ,
struct V_257 * V_257 )
{
struct V_238 * V_238 = F_94 ( V_266 , struct V_238 , V_266 ) ;
return F_90 ( V_238 , V_257 , V_259 , V_15 ) ;
}
static int F_95 ( struct V_238 * V_238 , struct V_267 * V_268 )
{
int V_269 = F_96 ( NULL ) ;
if ( V_269 )
return V_269 ;
V_238 -> V_270 = F_97 () ;
if ( V_238 -> V_270 == NULL )
return - V_26 ;
if ( F_98 ( V_238 -> V_270 , V_271 ) < 0 )
return - V_272 ;
V_269 = F_99 ( V_238 -> V_270 , & V_238 -> V_266 , & V_238 -> V_273 . V_274 ,
V_268 -> V_275 , F_93 , false ,
V_238 -> V_273 . V_276 ) ;
if ( V_269 )
F_100 () ;
return V_269 ;
}
static int F_101 ( struct V_277 * V_278 )
{
struct V_3 * V_2 ;
int V_36 = 0 ;
V_278 -> V_279 = calloc ( V_278 -> V_280 , sizeof( void * ) ) ;
if ( V_278 -> V_279 == NULL )
return - 1 ;
if ( V_278 -> V_208 )
V_278 -> V_281 = V_278 -> V_208 -> V_281 ;
for ( V_2 = V_278 -> args ; V_2 ; V_2 = V_2 -> V_282 ) {
if ( V_278 -> V_208 && V_278 -> V_208 -> V_279 [ V_36 ] )
V_278 -> V_279 [ V_36 ] = V_278 -> V_208 -> V_279 [ V_36 ] ;
else if ( V_2 -> V_51 & V_283 )
V_278 -> V_279 [ V_36 ] = F_21 ;
++ V_36 ;
}
return 0 ;
}
static int F_102 ( struct V_238 * V_238 , int V_24 )
{
char V_284 [ 128 ] ;
struct V_277 * V_278 ;
const char * V_20 = F_103 ( V_24 , V_238 -> V_285 . V_257 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_238 -> V_286 . V_221 ) {
struct V_277 * V_287 = realloc ( V_238 -> V_286 . V_228 , ( V_24 + 1 ) * sizeof( * V_278 ) ) ;
if ( V_287 == NULL )
return - 1 ;
if ( V_238 -> V_286 . V_221 != - 1 ) {
memset ( V_287 + V_238 -> V_286 . V_221 + 1 , 0 ,
( V_24 - V_238 -> V_286 . V_221 ) * sizeof( * V_278 ) ) ;
} else {
memset ( V_287 , 0 , ( V_24 + 1 ) * sizeof( * V_278 ) ) ;
}
V_238 -> V_286 . V_228 = V_287 ;
V_238 -> V_286 . V_221 = V_24 ;
}
V_278 = V_238 -> V_286 . V_228 + V_24 ;
V_278 -> V_20 = V_20 ;
V_278 -> V_208 = F_66 ( V_278 -> V_20 ) ;
snprintf ( V_284 , sizeof( V_284 ) , L_31 , V_278 -> V_20 ) ;
V_278 -> V_288 = F_104 ( L_2 , V_284 ) ;
if ( F_14 ( V_278 -> V_288 ) && V_278 -> V_208 && V_278 -> V_208 -> V_289 ) {
snprintf ( V_284 , sizeof( V_284 ) , L_31 , V_278 -> V_208 -> V_289 ) ;
V_278 -> V_288 = F_104 ( L_2 , V_284 ) ;
}
if ( F_14 ( V_278 -> V_288 ) )
return - 1 ;
V_278 -> args = V_278 -> V_288 -> V_290 . V_291 ;
V_278 -> V_280 = V_278 -> V_288 -> V_290 . V_292 ;
if ( V_278 -> args && ( ! strcmp ( V_278 -> args -> V_20 , L_32 ) || ! strcmp ( V_278 -> args -> V_20 , L_33 ) ) ) {
V_278 -> args = V_278 -> args -> V_282 ;
-- V_278 -> V_280 ;
}
V_278 -> V_293 = ! strcmp ( V_20 , L_34 ) || ! strcmp ( V_20 , L_35 ) ;
return F_101 ( V_278 ) ;
}
static int F_105 ( struct V_238 * V_238 )
{
int V_269 = 0 , V_294 ;
struct V_295 * V_296 ;
V_238 -> V_297 . V_298 = F_106 ( V_238 -> V_299 ) ;
V_238 -> V_297 . V_39 = malloc ( V_238 -> V_297 . V_298 *
sizeof( V_238 -> V_297 . V_39 [ 0 ] ) ) ;
if ( V_238 -> V_297 . V_39 == NULL ) {
fputs ( L_36 ,
V_238 -> V_262 ) ;
V_269 = - V_300 ;
goto V_301;
}
V_294 = 0 ;
F_107 (pos, trace->ev_qualifier) {
const char * V_278 = V_296 -> V_302 ;
int V_24 = F_108 ( V_278 , V_238 -> V_285 . V_257 ) ;
if ( V_24 < 0 ) {
if ( V_269 == 0 ) {
fputs ( L_37 , V_238 -> V_262 ) ;
V_269 = - V_300 ;
} else {
fputs ( L_38 , V_238 -> V_262 ) ;
}
fputs ( V_278 , V_238 -> V_262 ) ;
}
V_238 -> V_297 . V_39 [ V_294 ++ ] = V_24 ;
}
if ( V_269 < 0 ) {
fputs ( L_39
L_40 , V_238 -> V_262 ) ;
F_8 ( & V_238 -> V_297 . V_39 ) ;
V_238 -> V_297 . V_298 = 0 ;
}
V_301:
return V_269 ;
}
static T_1 F_109 ( struct V_277 * V_278 , char * V_29 , T_1 V_6 ,
unsigned char * args , struct V_238 * V_238 ,
struct V_223 * V_223 )
{
T_1 V_42 = 0 ;
unsigned char * V_303 ;
unsigned long V_37 ;
if ( V_278 -> args != NULL ) {
struct V_3 * V_2 ;
T_6 V_304 = 1 ;
struct V_31 V_32 = {
. V_36 = 0 ,
. V_100 = 0 ,
. V_238 = V_238 ,
. V_223 = V_223 ,
} ;
for ( V_2 = V_278 -> args ; V_2 ;
V_2 = V_2 -> V_282 , ++ V_32 . V_36 , V_304 <<= 1 ) {
if ( V_32 . V_100 & V_304 )
continue;
V_303 = args + sizeof( unsigned long ) * V_32 . V_36 ;
memcpy ( & V_37 , V_303 , sizeof( V_37 ) ) ;
if ( V_37 == 0 &&
! ( V_278 -> V_279 &&
V_278 -> V_279 [ V_32 . V_36 ] == V_305 &&
V_278 -> V_281 [ V_32 . V_36 ] ) )
continue;
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_41 , V_42 ? L_38 : L_11 , V_2 -> V_20 ) ;
if ( V_278 -> V_279 && V_278 -> V_279 [ V_32 . V_36 ] ) {
V_32 . V_37 = V_37 ;
if ( V_278 -> V_281 )
V_32 . V_35 = V_278 -> V_281 [ V_32 . V_36 ] ;
V_42 += V_278 -> V_279 [ V_32 . V_36 ] ( V_29 + V_42 ,
V_6 - V_42 , & V_32 ) ;
} else {
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_42 , V_37 ) ;
}
}
} else {
int V_294 = 0 ;
while ( V_294 < 6 ) {
V_303 = args + sizeof( unsigned long ) * V_294 ;
memcpy ( & V_37 , V_303 , sizeof( V_37 ) ) ;
V_42 += F_16 ( V_29 + V_42 , V_6 - V_42 ,
L_43 ,
V_42 ? L_38 : L_11 , V_294 , V_37 ) ;
++ V_294 ;
}
}
return V_42 ;
}
static struct V_277 * F_110 ( struct V_238 * V_238 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_306 > 1 ) {
static T_5 T_2 ;
fprintf ( V_238 -> V_262 , L_44 V_263 L_45 ,
V_24 , F_111 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_238 -> V_286 . V_221 || V_238 -> V_286 . V_228 [ V_24 ] . V_20 == NULL ) &&
F_102 ( V_238 , V_24 ) )
goto V_307;
if ( ( V_24 > V_238 -> V_286 . V_221 || V_238 -> V_286 . V_228 [ V_24 ] . V_20 == NULL ) )
goto V_307;
return & V_238 -> V_286 . V_228 [ V_24 ] ;
V_307:
if ( V_306 ) {
fprintf ( V_238 -> V_262 , L_46 , V_24 ) ;
if ( V_24 <= V_238 -> V_286 . V_221 && V_238 -> V_286 . V_228 [ V_24 ] . V_20 != NULL )
fprintf ( V_238 -> V_262 , L_47 , V_238 -> V_286 . V_228 [ V_24 ] . V_20 ) ;
fputs ( L_48 , V_238 -> V_262 ) ;
}
return NULL ;
}
static void F_112 ( struct V_218 * V_219 ,
int V_24 , struct V_14 * V_15 )
{
struct V_308 * V_309 ;
struct V_240 * V_240 ;
T_5 V_213 = 0 ;
V_309 = F_113 ( V_219 -> V_222 , V_24 ) ;
if ( V_309 == NULL )
return;
V_240 = V_309 -> V_21 ;
if ( V_240 == NULL ) {
V_240 = malloc ( sizeof( struct V_240 ) ) ;
if ( V_240 == NULL )
return;
F_114 ( V_240 ) ;
V_309 -> V_21 = V_240 ;
}
if ( V_219 -> V_310 && V_15 -> time > V_219 -> V_310 )
V_213 = V_15 -> time - V_219 -> V_310 ;
F_115 ( V_240 , V_213 ) ;
}
static int F_116 ( struct V_238 * V_238 , struct V_14 * V_15 )
{
struct V_218 * V_219 ;
T_5 V_213 ;
T_1 V_42 ;
if ( V_238 -> V_311 == NULL )
return 0 ;
V_219 = F_74 ( V_238 -> V_311 ) ;
if ( ! V_219 -> V_312 )
return 0 ;
V_213 = V_15 -> time - V_219 -> V_310 ;
V_42 = F_88 ( V_238 , V_238 -> V_311 , V_213 , V_15 -> time , V_238 -> V_262 ) ;
V_42 += fprintf ( V_238 -> V_262 , L_49 , V_219 -> V_246 ) ;
V_219 -> V_312 = false ;
return V_42 ;
}
static int F_117 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
char * V_314 ;
void * args ;
T_1 V_42 = 0 ;
struct V_223 * V_223 ;
int V_24 = F_118 ( V_19 , V_24 , V_15 ) , V_269 = - 1 ;
struct V_277 * V_278 = F_110 ( V_238 , V_19 , V_24 ) ;
struct V_218 * V_219 ;
if ( V_278 == NULL )
return - 1 ;
V_223 = F_119 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
V_219 = F_73 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_316;
args = F_120 ( V_19 , args , V_15 ) ;
if ( V_219 -> V_246 == NULL ) {
V_219 -> V_246 = malloc ( V_317 ) ;
if ( ! V_219 -> V_246 )
goto V_316;
}
if ( ! V_238 -> V_318 )
F_116 ( V_238 , V_15 ) ;
V_219 -> V_310 = V_15 -> time ;
V_314 = V_219 -> V_246 ;
V_42 += F_16 ( V_314 + V_42 , V_317 - V_42 , L_50 , V_278 -> V_20 ) ;
V_42 += F_109 ( V_278 , V_314 + V_42 , V_317 - V_42 ,
args , V_238 , V_223 ) ;
if ( V_278 -> V_293 ) {
if ( ! V_238 -> V_248 && ! V_238 -> V_318 ) {
F_88 ( V_238 , V_223 , 1 , V_15 -> time , V_238 -> V_262 ) ;
fprintf ( V_238 -> V_262 , L_51 , V_219 -> V_246 ) ;
}
} else {
V_219 -> V_312 = true ;
V_219 -> V_244 . V_319 = false ;
}
if ( V_238 -> V_311 != V_223 ) {
F_121 ( V_238 -> V_311 ) ;
V_238 -> V_311 = F_122 ( V_223 ) ;
}
V_269 = 0 ;
V_316:
F_121 ( V_223 ) ;
return V_269 ;
}
static int F_123 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
long V_233 ;
T_5 V_213 = 0 ;
struct V_223 * V_223 ;
int V_24 = F_118 ( V_19 , V_24 , V_15 ) , V_269 = - 1 ;
struct V_277 * V_278 = F_110 ( V_238 , V_19 , V_24 ) ;
struct V_218 * V_219 ;
if ( V_278 == NULL )
return - 1 ;
V_223 = F_119 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
V_219 = F_73 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_316;
if ( V_238 -> V_320 )
F_112 ( V_219 , V_24 , V_15 ) ;
V_233 = F_118 ( V_19 , V_233 , V_15 ) ;
if ( V_24 == V_238 -> V_285 . V_321 && V_233 >= 0 && V_219 -> V_244 . V_319 ) {
F_76 ( V_223 , V_233 , V_219 -> V_244 . V_20 ) ;
V_219 -> V_244 . V_319 = false ;
++ V_238 -> V_240 . V_247 ;
}
V_219 -> V_322 = V_15 -> time ;
if ( V_219 -> V_310 ) {
V_213 = V_15 -> time - V_219 -> V_310 ;
if ( F_85 ( V_238 , V_213 ) )
goto V_301;
} else if ( V_238 -> V_248 )
goto V_301;
if ( V_238 -> V_318 )
goto V_301;
F_88 ( V_238 , V_223 , V_213 , V_15 -> time , V_238 -> V_262 ) ;
if ( V_219 -> V_312 ) {
fprintf ( V_238 -> V_262 , L_52 , V_219 -> V_246 ) ;
} else {
fprintf ( V_238 -> V_262 , L_53 ) ;
F_69 ( V_238 -> V_262 , V_216 , L_54 ) ;
fprintf ( V_238 -> V_262 , L_55 , V_278 -> V_20 ) ;
}
if ( V_278 -> V_208 == NULL ) {
V_323:
fprintf ( V_238 -> V_262 , L_56 , V_233 ) ;
} else if ( V_233 < 0 && V_278 -> V_208 -> V_324 ) {
char V_29 [ V_325 ] ;
const char * V_326 = F_124 ( - V_233 , V_29 , sizeof( V_29 ) ) ,
* V_327 = F_125 ( - V_233 ) ;
fprintf ( V_238 -> V_262 , L_57 , V_327 , V_326 ) ;
} else if ( V_233 == 0 && V_278 -> V_208 -> V_328 )
fprintf ( V_238 -> V_262 , L_58 ) ;
else if ( V_278 -> V_208 -> V_329 )
fprintf ( V_238 -> V_262 , L_59 , V_233 ) ;
else
goto V_323;
fputc ( '\n' , V_238 -> V_262 ) ;
V_301:
V_219 -> V_312 = false ;
V_269 = 0 ;
V_316:
F_121 ( V_223 ) ;
return V_269 ;
}
static int F_126 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
struct V_223 * V_223 = F_119 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
struct V_218 * V_219 ;
T_1 V_330 , V_331 , V_332 ;
T_7 V_333 ;
char * V_296 ;
const char * V_244 = F_127 ( V_19 , V_15 , L_60 ) ;
if ( ! V_223 )
goto V_301;
V_219 = F_74 ( V_223 ) ;
if ( ! V_219 )
goto V_301;
V_330 = strlen ( V_244 ) ;
if ( V_219 -> V_244 . V_334 < V_330 ) {
char * V_335 = realloc ( V_219 -> V_244 . V_20 , V_330 + 1 ) ;
if ( V_335 == NULL )
goto V_301;
V_219 -> V_244 . V_334 = V_330 ;
V_219 -> V_244 . V_20 = V_335 ;
}
strcpy ( V_219 -> V_244 . V_20 , V_244 ) ;
V_219 -> V_244 . V_319 = true ;
if ( ! V_219 -> V_244 . V_243 )
goto V_301;
V_331 = strlen ( V_219 -> V_246 ) ;
V_333 = V_317 - V_331 - 1 ;
if ( V_333 <= 0 )
goto V_301;
if ( V_330 > ( T_1 ) V_333 ) {
V_244 += V_330 - V_333 ;
V_330 = V_333 ;
}
V_332 = V_331 - V_219 -> V_244 . V_245 + 1 ;
V_296 = V_219 -> V_246 + V_219 -> V_244 . V_245 ;
memmove ( V_296 + V_330 , V_296 , V_332 ) ;
memcpy ( V_296 , V_244 , V_330 ) ;
V_219 -> V_244 . V_243 = 0 ;
V_219 -> V_244 . V_245 = 0 ;
V_301:
return 0 ;
}
static int F_128 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
T_5 V_336 = F_129 ( V_19 , V_15 , L_61 ) ;
double V_337 = ( double ) V_336 / V_214 ;
struct V_223 * V_223 = F_119 ( V_238 -> V_270 ,
V_15 -> V_315 ,
V_15 -> V_235 ) ;
struct V_218 * V_219 = F_73 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_338;
V_219 -> V_337 += V_337 ;
V_238 -> V_337 += V_337 ;
F_121 ( V_223 ) ;
return 0 ;
V_338:
fprintf ( V_238 -> V_262 , L_62 V_263 L_63 V_263 L_64 ,
V_19 -> V_20 ,
F_130 ( V_19 , V_15 , L_65 ) ,
( V_339 ) F_129 ( V_19 , V_15 , L_66 ) ,
V_336 ,
F_129 ( V_19 , V_15 , L_67 ) ) ;
F_121 ( V_223 ) ;
return 0 ;
}
static void F_131 ( enum V_340 V_84 ,
unsigned int V_37 , void * V_341 )
{
V_57 * V_262 = V_341 ;
unsigned char V_342 = ( unsigned char ) V_37 ;
switch ( V_84 ) {
case V_343 :
fprintf ( V_262 , L_68 , isprint ( V_342 ) ? V_342 : '.' ) ;
break;
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
default:
break;
}
}
static void F_132 ( struct V_238 * V_238 ,
struct V_14 * V_15 )
{
F_133 ( V_15 -> V_16 , V_15 -> V_353 , 8 ,
F_131 , V_238 -> V_262 ) ;
}
static int F_134 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
F_116 ( V_238 , V_15 ) ;
F_86 ( V_238 , V_15 -> time , V_238 -> V_262 ) ;
if ( V_238 -> V_354 )
fprintf ( V_238 -> V_262 , L_69 ) ;
fprintf ( V_238 -> V_262 , L_70 , V_19 -> V_20 ) ;
if ( F_135 ( V_19 ) ) {
F_132 ( V_238 , V_15 ) ;
} else if ( V_19 -> V_288 ) {
F_136 ( V_19 -> V_288 , V_15 -> V_355 ,
V_15 -> V_16 , V_15 -> V_353 ,
V_238 -> V_262 ) ;
}
fprintf ( V_238 -> V_262 , L_64 ) ;
return 0 ;
}
static void F_137 ( V_57 * V_335 , struct V_14 * V_15 ,
struct V_356 * V_357 ,
bool V_358 , bool V_359 )
{
if ( ( V_306 || V_358 ) && V_357 -> V_360 )
fprintf ( V_335 , L_71 , V_357 -> V_360 -> V_361 -> V_362 ) ;
if ( ( V_306 || V_359 ) && V_357 -> V_363 )
fprintf ( V_335 , L_72 V_364 , V_357 -> V_363 -> V_20 ,
V_357 -> V_365 - V_357 -> V_363 -> V_366 ) ;
else if ( V_357 -> V_360 )
fprintf ( V_335 , L_73 V_364 , V_357 -> V_365 ) ;
else
fprintf ( V_335 , L_73 V_364 , V_15 -> V_365 ) ;
}
static int F_138 ( struct V_238 * V_238 ,
struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
struct V_223 * V_223 ;
struct V_356 V_357 ;
char V_367 = 'd' ;
struct V_218 * V_219 ;
int V_269 = - 1 ;
V_223 = F_119 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
V_219 = F_73 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_316;
if ( V_19 -> V_368 . V_369 == V_370 )
V_219 -> V_371 ++ ;
else
V_219 -> V_372 ++ ;
if ( V_238 -> V_318 )
goto V_301;
F_139 ( V_223 , V_15 -> V_373 , V_374 ,
V_15 -> V_375 , & V_357 ) ;
F_88 ( V_238 , V_223 , 0 , V_15 -> time , V_238 -> V_262 ) ;
fprintf ( V_238 -> V_262 , L_74 ,
V_19 -> V_368 . V_369 == V_370 ?
L_75 : L_76 ) ;
F_137 ( V_238 -> V_262 , V_15 , & V_357 , false , true ) ;
fprintf ( V_238 -> V_262 , L_77 ) ;
F_139 ( V_223 , V_15 -> V_373 , V_376 ,
V_15 -> V_365 , & V_357 ) ;
if ( ! V_357 . V_360 ) {
F_139 ( V_223 , V_15 -> V_373 ,
V_374 , V_15 -> V_365 , & V_357 ) ;
if ( V_357 . V_360 )
V_367 = 'x' ;
else
V_367 = '?' ;
}
F_137 ( V_238 -> V_262 , V_15 , & V_357 , true , false ) ;
fprintf ( V_238 -> V_262 , L_78 , V_367 , V_357 . V_377 ) ;
V_301:
V_269 = 0 ;
V_316:
F_121 ( V_223 ) ;
return V_269 ;
}
static bool F_140 ( struct V_238 * V_238 , struct V_14 * V_15 )
{
if ( ( V_238 -> V_378 && F_141 ( V_238 -> V_378 , V_15 -> V_315 ) ) ||
( V_238 -> V_379 && F_141 ( V_238 -> V_379 , V_15 -> V_235 ) ) )
return false ;
if ( V_238 -> V_378 || V_238 -> V_379 )
return true ;
return false ;
}
static int F_142 ( struct V_265 * V_266 ,
union V_258 * V_259 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_257 * V_257 V_313 )
{
struct V_238 * V_238 = F_94 ( V_266 , struct V_238 , V_266 ) ;
int V_269 = 0 ;
T_8 V_22 = V_19 -> V_22 ;
if ( F_140 ( V_238 , V_15 ) )
return 0 ;
if ( ! V_238 -> V_380 && V_238 -> V_251 == 0 )
V_238 -> V_251 = V_15 -> time ;
if ( V_22 ) {
++ V_238 -> V_225 ;
V_22 ( V_238 , V_19 , V_259 , V_15 ) ;
}
return V_269 ;
}
static int F_143 ( struct V_238 * V_238 )
{
if ( V_238 -> V_273 . V_274 . V_315 ) {
V_238 -> V_378 = F_72 ( V_238 -> V_273 . V_274 . V_315 ) ;
if ( V_238 -> V_378 == NULL ) {
F_144 ( L_79 ) ;
return - V_300 ;
}
}
if ( V_238 -> V_273 . V_274 . V_235 ) {
V_238 -> V_379 = F_72 ( V_238 -> V_273 . V_274 . V_235 ) ;
if ( V_238 -> V_379 == NULL ) {
F_144 ( L_80 ) ;
return - V_300 ;
}
}
return 0 ;
}
static int F_145 ( struct V_238 * V_238 , int V_381 , const char * * V_382 )
{
unsigned int V_383 , V_294 , V_384 ;
const char * * V_385 ;
const char * const V_386 [] = {
L_81 ,
L_82 ,
L_83 , L_84 ,
L_85 , L_86 ,
} ;
const char * const V_387 [] = { L_87 , } ;
unsigned int V_388 = F_67 ( V_387 ) ;
const char * const V_389 [] = { L_87 , L_88 } ;
unsigned int V_390 = F_67 ( V_389 ) ;
const char * const V_391 [] = { L_87 , L_89 } ;
unsigned int V_392 = F_67 ( V_391 ) ;
V_383 = F_67 ( V_386 ) + V_388 + 1 +
V_390 + V_392 + V_381 ;
V_385 = calloc ( V_383 + 1 , sizeof( char * ) ) ;
if ( V_385 == NULL )
return - V_26 ;
V_384 = 0 ;
for ( V_294 = 0 ; V_294 < F_67 ( V_386 ) ; V_294 ++ )
V_385 [ V_384 ++ ] = V_386 [ V_294 ] ;
if ( V_238 -> V_354 ) {
for ( V_294 = 0 ; V_294 < V_388 ; V_294 ++ )
V_385 [ V_384 ++ ] = V_387 [ V_294 ] ;
if ( F_146 ( L_90 ) )
V_385 [ V_384 ++ ] = L_91 ;
else if ( F_146 ( L_92 ) )
V_385 [ V_384 ++ ] = L_93 ;
else {
F_144 ( L_94 ) ;
return - 1 ;
}
}
if ( V_238 -> V_393 & V_394 )
for ( V_294 = 0 ; V_294 < V_390 ; V_294 ++ )
V_385 [ V_384 ++ ] = V_389 [ V_294 ] ;
if ( V_238 -> V_393 & V_395 )
for ( V_294 = 0 ; V_294 < V_392 ; V_294 ++ )
V_385 [ V_384 ++ ] = V_391 [ V_294 ] ;
for ( V_294 = 0 ; V_294 < ( unsigned int ) V_381 ; V_294 ++ )
V_385 [ V_384 ++ ] = V_382 [ V_294 ] ;
return F_147 ( V_384 , V_385 , NULL ) ;
}
static bool F_148 ( struct V_267 * V_268 )
{
struct V_18 * V_19 = F_13 ( L_95 , L_96 ) ;
if ( F_14 ( V_19 ) )
return false ;
if ( F_5 ( V_19 , L_60 ) == NULL ) {
F_9 ( V_19 ) ;
return false ;
}
V_19 -> V_22 = F_126 ;
F_149 ( V_268 , V_19 ) ;
return true ;
}
static int F_150 ( struct V_267 * V_268 ,
T_5 V_369 )
{
struct V_18 * V_19 ;
struct V_396 V_368 = {
. type = V_397 ,
. V_398 = 1 ,
} ;
V_368 . V_369 = V_369 ;
V_368 . V_399 = 1 ;
F_151 ( & V_368 ) ;
V_19 = F_152 ( & V_368 ) ;
if ( ! V_19 )
return - V_26 ;
V_19 -> V_22 = F_138 ;
F_149 ( V_268 , V_19 ) ;
return 0 ;
}
static void F_153 ( struct V_238 * V_238 , union V_258 * V_259 , struct V_14 * V_15 )
{
const T_9 type = V_259 -> V_260 . type ;
struct V_18 * V_19 ;
if ( ! V_238 -> V_380 && V_238 -> V_251 == 0 )
V_238 -> V_251 = V_15 -> time ;
if ( type != V_400 ) {
F_90 ( V_238 , V_238 -> V_270 , V_259 , V_15 ) ;
return;
}
V_19 = F_154 ( V_238 -> V_268 , V_15 -> V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_238 -> V_262 , L_97 V_263 L_98 , V_15 -> V_24 ) ;
return;
}
if ( V_19 -> V_368 . type == V_401 &&
V_15 -> V_16 == NULL ) {
fprintf ( V_238 -> V_262 , L_99 ,
F_111 ( V_19 ) , V_15 -> V_235 ,
V_15 -> V_355 , V_15 -> V_353 ) ;
} else {
T_8 V_22 = V_19 -> V_22 ;
V_22 ( V_238 , V_19 , V_259 , V_15 ) ;
}
}
static int F_155 ( struct V_238 * V_238 )
{
int V_233 = - 1 ;
struct V_267 * V_268 = V_238 -> V_268 ;
struct V_18 * V_402 , * V_403 ;
V_402 = F_12 ( L_100 , F_117 ) ;
if ( V_402 == NULL )
goto V_301;
if ( F_156 ( V_402 , args ) )
goto V_404;
V_403 = F_12 ( L_101 , F_123 ) ;
if ( V_403 == NULL )
goto V_404;
if ( F_11 ( V_403 , V_233 ) )
goto V_405;
F_149 ( V_268 , V_402 ) ;
F_149 ( V_268 , V_403 ) ;
V_238 -> V_286 . V_406 . V_402 = V_402 ;
V_238 -> V_286 . V_406 . V_403 = V_403 ;
V_233 = 0 ;
V_301:
return V_233 ;
V_405:
F_7 ( V_403 ) ;
V_404:
F_7 ( V_402 ) ;
goto V_301;
}
static int F_157 ( struct V_238 * V_238 )
{
int V_269 = - 1 ;
char * V_407 = F_158 ( L_102 , ! V_238 -> V_408 ,
V_238 -> V_297 . V_298 ,
V_238 -> V_297 . V_39 ) ;
if ( V_407 == NULL )
goto V_409;
if ( ! F_159 ( V_238 -> V_286 . V_406 . V_402 , L_103 , V_407 ) )
V_269 = F_159 ( V_238 -> V_286 . V_406 . V_403 , L_103 , V_407 ) ;
free ( V_407 ) ;
V_301:
return V_269 ;
V_409:
V_272 = V_26 ;
goto V_301;
}
static int F_160 ( struct V_238 * V_238 , int V_381 , const char * * V_382 )
{
struct V_267 * V_268 = V_238 -> V_268 ;
struct V_18 * V_19 ;
int V_269 = - 1 , V_294 ;
unsigned long V_410 ;
const bool V_411 = V_381 > 0 ;
bool V_412 = false ;
V_238 -> V_239 = true ;
if ( V_238 -> V_354 && F_155 ( V_238 ) )
goto V_413;
if ( V_238 -> V_354 )
V_238 -> V_247 = F_148 ( V_268 ) ;
if ( ( V_238 -> V_393 & V_394 ) &&
F_150 ( V_268 , V_370 ) ) {
goto V_414;
}
if ( ( V_238 -> V_393 & V_395 ) &&
F_150 ( V_268 , V_415 ) )
goto V_414;
if ( V_238 -> V_416 &&
F_161 ( V_268 , L_104 , L_105 ,
F_128 ) )
goto V_417;
V_269 = F_162 ( V_268 , & V_238 -> V_273 . V_274 ) ;
if ( V_269 < 0 ) {
fprintf ( V_238 -> V_262 , L_106 ) ;
goto V_418;
}
V_269 = F_95 ( V_238 , V_268 ) ;
if ( V_269 < 0 ) {
fprintf ( V_238 -> V_262 , L_107 ) ;
goto V_418;
}
F_163 ( V_268 , & V_238 -> V_273 ) ;
signal ( V_419 , F_87 ) ;
signal ( V_254 , F_87 ) ;
if ( V_411 ) {
V_269 = F_164 ( V_268 , & V_238 -> V_273 . V_274 ,
V_382 , false , NULL ) ;
if ( V_269 < 0 ) {
fprintf ( V_238 -> V_262 , L_108 ) ;
goto V_418;
}
}
V_269 = F_165 ( V_268 ) ;
if ( V_269 < 0 )
goto V_420;
V_269 = F_166 () ;
if ( V_269 ) {
char V_421 [ V_422 ] ;
F_167 ( V_269 , V_421 , sizeof( V_421 ) ) ;
F_144 ( L_109 ,
V_421 ) ;
goto V_420;
}
if ( V_238 -> V_423 . V_298 > 0 )
V_269 = F_168 ( V_268 , V_238 -> V_423 . V_298 , V_238 -> V_423 . V_39 ) ;
else if ( F_169 ( V_268 -> V_275 , 0 ) == - 1 )
V_269 = F_170 ( V_268 , F_171 () ) ;
if ( V_269 < 0 )
goto V_414;
if ( V_238 -> V_297 . V_298 > 0 ) {
V_269 = F_157 ( V_238 ) ;
if ( V_269 < 0 )
goto V_424;
F_172 ( L_110 ,
V_238 -> V_286 . V_406 . V_403 -> V_407 ) ;
}
V_269 = F_173 ( V_268 , & V_19 ) ;
if ( V_269 < 0 )
goto V_425;
V_269 = F_174 ( V_268 , V_238 -> V_273 . V_426 , false ) ;
if ( V_269 < 0 )
goto V_427;
if ( ! F_175 ( & V_238 -> V_273 . V_274 ) )
F_176 ( V_268 ) ;
if ( V_411 )
F_177 ( V_268 ) ;
V_238 -> V_255 = F_169 ( V_268 -> V_275 , 0 ) == - 1 ||
V_268 -> V_275 -> V_298 > 1 ||
F_178 ( V_268 ) -> V_368 . V_428 ;
V_429:
V_410 = V_238 -> V_225 ;
for ( V_294 = 0 ; V_294 < V_268 -> V_430 ; V_294 ++ ) {
union V_258 * V_259 ;
while ( ( V_259 = F_179 ( V_268 , V_294 ) ) != NULL ) {
struct V_14 V_15 ;
++ V_238 -> V_225 ;
V_269 = F_180 ( V_268 , V_259 , & V_15 ) ;
if ( V_269 ) {
fprintf ( V_238 -> V_262 , L_111 , V_269 ) ;
goto V_431;
}
F_153 ( V_238 , V_259 , & V_15 ) ;
V_431:
F_181 ( V_268 , V_294 ) ;
if ( V_253 )
goto V_432;
if ( V_252 && ! V_412 ) {
F_182 ( V_268 ) ;
V_412 = true ;
}
}
}
if ( V_238 -> V_225 == V_410 ) {
int V_328 = V_252 ? 100 : - 1 ;
if ( ! V_412 && F_183 ( V_268 , V_328 ) > 0 ) {
if ( F_184 ( V_268 , V_433 | V_434 ) == 0 )
V_412 = true ;
goto V_429;
}
} else {
goto V_429;
}
V_432:
F_185 ( V_238 -> V_311 ) ;
F_182 ( V_268 ) ;
if ( ! V_269 ) {
if ( V_238 -> V_320 )
F_186 ( V_238 , V_238 -> V_262 ) ;
if ( V_238 -> V_435 ) {
fprintf ( V_238 -> V_262 , L_112
L_113 V_263 L_114
L_115 V_263 L_114 ,
V_238 -> V_240 . V_247 ,
V_238 -> V_240 . V_241 ) ;
}
}
V_418:
F_187 ( V_268 ) ;
V_238 -> V_268 = NULL ;
V_238 -> V_239 = false ;
return V_269 ;
{
char V_421 [ V_422 ] ;
V_417:
F_188 ( V_272 , V_421 , sizeof( V_421 ) , L_104 , L_105 ) ;
goto V_436;
V_413:
F_188 ( V_272 , V_421 , sizeof( V_421 ) , L_1 , L_116 ) ;
goto V_436;
V_427:
F_189 ( V_268 , V_272 , V_421 , sizeof( V_421 ) ) ;
goto V_436;
V_420:
F_190 ( V_268 , V_272 , V_421 , sizeof( V_421 ) ) ;
V_436:
fprintf ( V_238 -> V_262 , L_117 , V_421 ) ;
goto V_418;
V_425:
fprintf ( V_238 -> V_262 ,
L_118 ,
V_19 -> V_407 , F_111 ( V_19 ) , V_272 ,
F_124 ( V_272 , V_421 , sizeof( V_421 ) ) ) ;
goto V_418;
}
V_414:
fprintf ( V_238 -> V_262 , L_119 ) ;
goto V_418;
V_424:
fprintf ( V_238 -> V_262 , L_120 , V_272 , strerror ( V_272 ) ) ;
goto V_418;
}
static int F_191 ( struct V_238 * V_238 )
{
const struct V_437 V_438 [] = {
{ L_121 , F_126 , } ,
} ;
struct V_439 V_440 = {
. V_242 = V_441 ,
. V_145 = V_442 ,
. V_443 = V_238 -> V_443 ,
} ;
struct V_444 * V_445 ;
struct V_18 * V_19 ;
int V_269 = - 1 ;
V_238 -> V_266 . V_15 = F_142 ;
V_238 -> V_266 . V_446 = V_447 ;
V_238 -> V_266 . V_448 = V_449 ;
V_238 -> V_266 . V_450 = V_451 ;
V_238 -> V_266 . exit = V_452 ;
V_238 -> V_266 . V_453 = V_454 ;
V_238 -> V_266 . V_368 = V_455 ;
V_238 -> V_266 . V_456 = V_457 ;
V_238 -> V_266 . V_458 = V_459 ;
V_238 -> V_266 . V_460 = true ;
V_238 -> V_266 . V_461 = true ;
V_238 -> V_255 = true ;
V_445 = F_192 ( & V_440 , false , & V_238 -> V_266 ) ;
if ( V_445 == NULL )
return - 1 ;
if ( F_96 ( & V_445 -> V_260 . V_462 ) < 0 )
goto V_301;
V_238 -> V_270 = & V_445 -> V_463 . V_270 ;
V_269 = F_193 ( V_445 , V_438 ) ;
if ( V_269 )
goto V_301;
V_19 = F_194 ( V_445 -> V_268 ,
L_90 ) ;
if ( V_19 == NULL )
V_19 = F_194 ( V_445 -> V_268 ,
L_92 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_117 ) < 0 ||
F_156 ( V_19 , args ) ) ) {
F_144 ( L_122 ) ;
goto V_301;
}
V_19 = F_194 ( V_445 -> V_268 ,
L_123 ) ;
if ( V_19 == NULL )
V_19 = F_194 ( V_445 -> V_268 ,
L_124 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_123 ) < 0 ||
F_11 ( V_19 , V_233 ) ) ) {
F_144 ( L_125 ) ;
goto V_301;
}
F_195 (session->evlist, evsel) {
if ( V_19 -> V_368 . type == V_397 &&
( V_19 -> V_368 . V_369 == V_370 ||
V_19 -> V_368 . V_369 == V_415 ||
V_19 -> V_368 . V_369 == V_464 ) )
V_19 -> V_22 = F_138 ;
}
V_269 = F_143 ( V_238 ) ;
if ( V_269 != 0 )
goto V_301;
F_196 () ;
V_269 = F_197 ( V_445 ) ;
if ( V_269 )
F_144 ( L_126 , V_269 ) ;
else if ( V_238 -> V_320 )
F_186 ( V_238 , V_238 -> V_262 ) ;
V_301:
F_198 ( V_445 ) ;
return V_269 ;
}
static T_1 F_199 ( V_57 * V_212 )
{
T_1 V_42 ;
V_42 = fprintf ( V_212 , L_127 ) ;
return V_42 ;
}
static T_1 F_200 ( struct V_218 * V_219 ,
struct V_238 * V_238 , V_57 * V_212 )
{
struct V_240 * V_240 ;
T_1 V_42 = 0 ;
struct V_277 * V_278 ;
struct V_308 * V_309 = F_201 ( V_219 -> V_222 ) ;
if ( V_309 == NULL )
return 0 ;
V_42 += fprintf ( V_212 , L_114 ) ;
V_42 += fprintf ( V_212 , L_128 ) ;
V_42 += fprintf ( V_212 , L_129 ) ;
V_42 += fprintf ( V_212 , L_130 ) ;
while ( V_309 ) {
V_240 = V_309 -> V_21 ;
if ( V_240 ) {
double V_465 = ( double ) ( V_240 -> V_465 ) / V_214 ;
double V_221 = ( double ) ( V_240 -> V_221 ) / V_214 ;
double V_466 = F_202 ( V_240 ) ;
double V_467 ;
T_5 T_2 = ( T_5 ) V_240 -> T_2 ;
V_467 = V_466 ? 100.0 * F_203 ( V_240 ) / V_466 : 0.0 ;
V_466 /= V_214 ;
V_278 = & V_238 -> V_286 . V_228 [ V_309 -> V_294 ] ;
V_42 += fprintf ( V_212 , L_131 , V_278 -> V_20 ) ;
V_42 += fprintf ( V_212 , L_132 V_263 L_133 ,
T_2 , V_466 * T_2 , V_465 , V_466 ) ;
V_42 += fprintf ( V_212 , L_134 , V_221 , V_467 ) ;
}
V_309 = F_204 ( V_309 ) ;
}
V_42 += fprintf ( V_212 , L_135 ) ;
return V_42 ;
}
static int F_205 ( struct V_223 * V_223 , void * V_21 )
{
struct V_468 * V_469 = V_21 ;
V_57 * V_212 = V_469 -> V_212 ;
T_1 V_42 = V_469 -> V_42 ;
struct V_238 * V_238 = V_469 -> V_238 ;
struct V_218 * V_219 = F_74 ( V_223 ) ;
double V_470 ;
if ( V_219 == NULL )
return 0 ;
V_470 = ( double ) V_219 -> V_225 / V_238 -> V_225 * 100.0 ;
V_42 += fprintf ( V_212 , L_136 , F_89 ( V_223 ) , V_223 -> V_235 ) ;
V_42 += fprintf ( V_212 , L_137 , V_219 -> V_225 ) ;
V_42 += fprintf ( V_212 , L_138 , V_470 ) ;
if ( V_219 -> V_371 )
V_42 += fprintf ( V_212 , L_139 , V_219 -> V_371 ) ;
if ( V_219 -> V_372 )
V_42 += fprintf ( V_212 , L_140 , V_219 -> V_372 ) ;
V_42 += fprintf ( V_212 , L_141 , V_219 -> V_337 ) ;
V_42 += F_200 ( V_219 , V_238 , V_212 ) ;
V_469 -> V_42 += V_42 ;
return 0 ;
}
static T_1 F_186 ( struct V_238 * V_238 , V_57 * V_212 )
{
struct V_468 V_469 = {
. V_212 = V_212 ,
. V_238 = V_238
} ;
V_469 . V_42 = F_199 ( V_212 ) ;
F_206 ( V_238 -> V_270 , F_205 , & V_469 ) ;
return V_469 . V_42 ;
}
static int F_207 ( const struct V_471 * V_472 , const char * V_473 ,
int T_10 V_313 )
{
struct V_238 * V_238 = V_472 -> V_474 ;
V_238 -> V_248 = atof ( V_473 ) ;
return 0 ;
}
static int F_208 ( const struct V_471 * V_472 , const char * V_473 ,
int T_10 V_313 )
{
int V_233 = - 1 ;
T_1 V_294 ;
struct V_238 * V_238 = V_472 -> V_474 ;
struct V_475 * V_476 = F_72 ( V_473 ) ;
if ( V_476 == NULL )
return - 1 ;
V_294 = V_238 -> V_423 . V_298 = F_209 ( V_476 ) + 1 ;
V_238 -> V_423 . V_39 = calloc ( V_294 , sizeof( V_339 ) ) ;
if ( V_238 -> V_423 . V_39 == NULL )
goto V_301;
V_238 -> V_423 . V_39 [ 0 ] = F_171 () ;
for ( V_294 = 1 ; V_294 < V_238 -> V_423 . V_298 ; ++ V_294 )
V_238 -> V_423 . V_39 [ V_294 ] = F_210 ( V_476 , V_294 - 1 ) -> V_294 ;
F_211 ( V_476 ) ;
V_233 = 0 ;
V_301:
return V_233 ;
}
static int F_212 ( struct V_238 * V_238 , const char * V_244 )
{
struct V_231 V_232 ;
if ( ! V_231 ( V_244 , & V_232 ) && V_232 . V_236 ) {
char V_477 [ V_230 ] ;
F_16 ( V_477 , sizeof( V_477 ) , L_142 , V_244 ) ;
F_213 ( V_477 ) ;
rename ( V_244 , V_477 ) ;
}
V_238 -> V_262 = fopen ( V_244 , L_143 ) ;
return V_238 -> V_262 == NULL ? - V_272 : 0 ;
}
static int F_214 ( const struct V_471 * V_472 , const char * V_473 ,
int T_10 V_313 )
{
int * V_393 = V_472 -> V_474 ;
if ( strcmp ( V_473 , L_144 ) == 0 )
* V_393 |= V_394 | V_395 ;
else if ( strcmp ( V_473 , L_75 ) == 0 )
* V_393 |= V_394 ;
else if ( strcmp ( V_473 , L_76 ) == 0 )
* V_393 |= V_395 ;
else
return - 1 ;
return 0 ;
}
static void F_215 ( struct V_267 * V_268 , void * V_22 )
{
struct V_18 * V_19 ;
F_195 (evlist, evsel)
V_19 -> V_22 = V_22 ;
}
int F_216 ( int V_381 , const char * * V_382 , const char * T_11 V_313 )
{
const char * V_478 [] = {
L_145 ,
L_146 ,
L_147 ,
L_148 ,
NULL
} ;
struct V_238 V_238 = {
. V_285 = {
. V_257 = F_217 () ,
. V_321 = F_108 ( L_149 , V_238 . V_285 . V_257 ) ,
} ,
. V_286 = {
. V_221 = - 1 ,
} ,
. V_273 = {
. V_274 = {
. V_479 = V_480 ,
. V_481 = true ,
} ,
. V_482 = V_480 ,
. V_483 = V_484 ,
. V_485 = true ,
. V_426 = V_480 ,
. V_276 = 500 ,
} ,
. V_262 = V_486 ,
. V_256 = true ,
. V_354 = true ,
} ;
const char * V_487 = NULL ;
const char * V_488 = NULL ;
const struct V_471 V_489 [] = {
F_218 ( 0 , L_150 , & V_238 . V_268 , L_150 ,
L_151 ,
V_490 ) ,
F_219 ( 0 , L_65 , & V_238 . V_256 ,
L_152 ) ,
F_219 ( 0 , L_153 , & V_238 . V_435 , L_154 ) ,
F_220 ( 'e' , L_155 , & V_488 , L_155 , L_156 ) ,
F_220 ( 'o' , L_157 , & V_487 , L_158 , L_159 ) ,
F_220 ( 'i' , L_160 , & V_441 , L_158 , L_161 ) ,
F_220 ( 'p' , L_66 , & V_238 . V_273 . V_274 . V_315 , L_66 ,
L_162 ) ,
F_220 ( 't' , L_163 , & V_238 . V_273 . V_274 . V_235 , L_163 ,
L_164 ) ,
F_218 ( 0 , L_165 , & V_238 , L_166 ,
L_167 , F_208 ) ,
F_219 ( 'a' , L_168 , & V_238 . V_273 . V_274 . V_491 ,
L_169 ) ,
F_220 ( 'C' , L_170 , & V_238 . V_273 . V_274 . V_492 , L_170 ,
L_171 ) ,
F_219 ( 0 , L_172 , & V_238 . V_273 . V_493 ,
L_173 ) ,
F_218 ( 'm' , L_174 , & V_238 . V_273 . V_426 , L_175 ,
L_176 ,
V_494 ) ,
F_220 ( 'u' , L_177 , & V_238 . V_273 . V_274 . V_495 , L_178 ,
L_179 ) ,
F_218 ( 0 , L_180 , & V_238 , L_181 ,
L_182 ,
F_207 ) ,
F_219 ( 0 , L_104 , & V_238 . V_416 , L_183 ) ,
F_221 ( 'v' , L_184 , & V_306 , L_185 ) ,
F_219 ( 'T' , L_186 , & V_238 . V_380 ,
L_187 ) ,
F_219 ( 's' , L_188 , & V_238 . V_318 ,
L_189 ) ,
F_219 ( 'S' , L_190 , & V_238 . V_320 ,
L_191 ) ,
F_222 ( 'F' , L_192 , & V_238 . V_393 , L_193 ,
L_194 , F_214 , L_75 ) ,
F_219 ( 0 , L_2 , & V_238 . V_354 , L_195 ) ,
F_219 ( 'f' , L_196 , & V_238 . V_443 , L_197 ) ,
F_223 ( 0 , L_198 , & V_238 . V_273 . V_276 ,
L_199 ) ,
F_224 ()
} ;
const char * const V_496 [] = { L_81 , NULL } ;
int V_269 ;
char V_29 [ V_422 ] ;
signal ( V_497 , V_498 ) ;
signal ( V_499 , V_498 ) ;
V_238 . V_268 = F_225 () ;
if ( V_238 . V_268 == NULL ) {
F_144 ( L_119 ) ;
V_269 = - V_26 ;
goto V_301;
}
V_381 = F_226 ( V_381 , V_382 , V_489 , V_496 ,
V_478 , V_500 ) ;
if ( V_238 . V_393 ) {
V_238 . V_273 . V_501 = true ;
V_238 . V_273 . V_502 = true ;
}
if ( V_238 . V_268 -> V_38 > 0 )
F_215 ( V_238 . V_268 , F_134 ) ;
if ( ( V_381 >= 1 ) && ( strcmp ( V_382 [ 0 ] , L_81 ) == 0 ) )
return F_145 ( & V_238 , V_381 - 1 , & V_382 [ 1 ] ) ;
if ( V_238 . V_318 )
V_238 . V_320 = V_238 . V_318 ;
if ( ! V_238 . V_354 && ! V_238 . V_393 &&
V_238 . V_268 -> V_38 == 0 ) {
F_144 ( L_200 ) ;
return - 1 ;
}
if ( V_487 != NULL ) {
V_269 = F_212 ( & V_238 , V_487 ) ;
if ( V_269 < 0 ) {
perror ( L_201 ) ;
goto V_301;
}
}
if ( V_488 != NULL ) {
const char * V_302 = V_488 ;
struct V_503 V_504 = {
. V_505 = F_227 ( V_506 ) ,
} ;
V_238 . V_408 = * V_302 == '!' ;
if ( V_238 . V_408 )
++ V_302 ;
V_238 . V_299 = F_228 ( V_302 , & V_504 ) ;
if ( V_238 . V_299 == NULL ) {
fputs ( L_202 ,
V_238 . V_262 ) ;
V_269 = - V_26 ;
goto V_507;
}
V_269 = F_105 ( & V_238 ) ;
if ( V_269 )
goto V_507;
}
V_269 = F_229 ( & V_238 . V_273 . V_274 ) ;
if ( V_269 ) {
F_230 ( & V_238 . V_273 . V_274 , V_269 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_238 . V_262 , L_3 , V_29 ) ;
goto V_507;
}
V_269 = F_231 ( & V_238 . V_273 . V_274 ) ;
if ( V_269 ) {
F_230 ( & V_238 . V_273 . V_274 , V_269 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_238 . V_262 , L_3 , V_29 ) ;
goto V_507;
}
if ( ! V_381 && F_175 ( & V_238 . V_273 . V_274 ) )
V_238 . V_273 . V_274 . V_491 = true ;
if ( V_441 )
V_269 = F_191 ( & V_238 ) ;
else
V_269 = F_160 ( & V_238 , V_381 , V_382 ) ;
V_507:
if ( V_487 != NULL )
fclose ( V_238 . V_262 ) ;
V_301:
return V_269 ;
}
