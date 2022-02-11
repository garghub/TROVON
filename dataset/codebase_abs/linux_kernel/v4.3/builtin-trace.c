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
if ( V_19 == NULL )
V_19 = F_13 ( L_2 , V_28 ) ;
if ( V_19 ) {
if ( F_10 ( V_19 , V_22 ) )
goto V_25;
}
return V_19 ;
V_25:
F_7 ( V_19 ) ;
return NULL ;
}
static T_1 F_14 ( char * V_29 , T_1 V_6 ,
const char * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
int V_36 = V_32 -> V_37 - V_34 -> V_5 ;
if ( V_36 < 0 || V_36 >= V_34 -> V_38 )
return F_15 ( V_29 , V_6 , V_30 , V_32 -> V_37 ) ;
return F_15 ( V_29 , V_6 , L_3 , V_34 -> V_39 [ V_36 ] ) ;
}
static T_1 F_16 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_14 ( V_29 , V_6 , L_4 , V_32 ) ;
}
static T_1 F_17 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_14 ( V_29 , V_6 , L_5 , V_32 ) ;
}
static T_1 F_18 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
if ( V_40 == V_41 )
return F_15 ( V_29 , V_6 , L_6 ) ;
return F_19 ( V_29 , V_6 , V_32 ) ;
}
static T_1 F_20 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_15 ( V_29 , V_6 , L_7 , V_32 -> V_37 ) ;
}
static T_1 F_21 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
return F_15 ( V_29 , V_6 , L_4 , V_32 -> V_37 ) ;
}
static T_1 F_22 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_43 = V_32 -> V_37 ;
if ( V_43 == V_44 )
return F_15 ( V_29 , V_6 , L_8 ) ;
#define F_23 ( T_2 ) \
if (prot & PROT_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
prot &= ~PROT_##n; \
}
F_23 ( V_45 ) ;
F_23 ( V_46 ) ;
F_23 ( V_47 ) ;
#ifdef F_24
F_23 ( V_48 ) ;
#endif
F_23 ( V_49 ) ;
F_23 ( V_50 ) ;
#undef F_23
if ( V_43 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_43 ) ;
return V_42 ;
}
static T_1 F_25 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
#define F_26 ( T_2 ) \
if (flags & MAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MAP_##n; \
}
F_26 ( V_52 ) ;
F_26 ( V_53 ) ;
#ifdef F_27
F_26 ( 32BIT ) ;
#endif
F_26 ( V_54 ) ;
F_26 ( V_55 ) ;
F_26 ( V_56 ) ;
F_26 ( V_57 ) ;
F_26 ( V_58 ) ;
F_26 ( V_49 ) ;
#ifdef F_28
F_26 ( V_59 ) ;
#endif
F_26 ( V_60 ) ;
F_26 ( V_61 ) ;
F_26 ( V_62 ) ;
F_26 ( V_63 ) ;
F_26 ( V_64 ) ;
#ifdef F_29
F_26 ( V_65 ) ;
#endif
#undef F_26
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_30 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
#define F_31 ( T_2 ) \
if (flags & MREMAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MREMAP_##n; \
}
F_31 ( V_66 ) ;
#ifdef F_32
F_31 ( V_58 ) ;
#endif
#undef F_31
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_33 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_67 = V_32 -> V_37 ;
switch ( V_67 ) {
#define F_34 ( T_2 ) case MADV_##n: return scnprintf(bf, size, #n)
F_34 ( V_68 ) ;
F_34 ( V_69 ) ;
F_34 ( V_70 ) ;
F_34 ( V_71 ) ;
F_34 ( V_72 ) ;
F_34 ( REMOVE ) ;
F_34 ( V_73 ) ;
F_34 ( V_74 ) ;
F_34 ( V_75 ) ;
#ifdef F_35
F_34 ( V_76 ) ;
#endif
F_34 ( V_77 ) ;
F_34 ( V_78 ) ;
#ifdef F_36
F_34 ( V_79 ) ;
#endif
#ifdef F_37
F_34 ( V_80 ) ;
#endif
#ifdef F_38
F_34 ( V_81 ) ;
#endif
#ifdef F_39
F_34 ( V_82 ) ;
#endif
#undef V_83
default: break;
}
return F_15 ( V_29 , V_6 , L_5 , V_67 ) ;
}
static T_1 F_40 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_84 = V_32 -> V_37 ;
if ( V_84 == 0 )
return F_15 ( V_29 , V_6 , L_8 ) ;
#define F_41 ( T_3 ) \
if ((op & LOCK_##cmd) == LOCK_##cmd) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #cmd); \
op &= ~LOCK_##cmd; \
}
F_41 ( V_85 ) ;
F_41 ( V_86 ) ;
F_41 ( V_87 ) ;
F_41 ( V_88 ) ;
F_41 ( V_89 ) ;
F_41 ( V_90 ) ;
F_41 ( V_46 ) ;
F_41 ( V_47 ) ;
#undef V_91
if ( V_84 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_84 ) ;
return V_42 ;
}
static T_1 F_42 ( char * V_29 , T_1 V_6 , struct V_31 * V_32 )
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
#define F_43 ( T_2 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_43 ( V_99 ) ; V_32 -> V_100 |= V_97 | V_96 ; break;
F_43 ( V_101 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_43 ( V_102 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_43 ( V_103 ) ; V_32 -> V_100 |= V_97 | V_95 ; break;
F_43 ( V_104 ) ; V_32 -> V_100 |= V_95 ; break;
F_43 ( V_105 ) ; V_32 -> V_100 |= V_95 ; break;
F_43 ( V_106 ) ; break;
F_43 ( V_107 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_43 ( V_108 ) ; V_32 -> V_100 |= V_97 | V_96 | V_95 ; break;
F_43 ( V_109 ) ; V_32 -> V_100 |= V_97 | V_96 ; break;
F_43 ( V_110 ) ; V_32 -> V_100 |= V_96 ; break;
F_43 ( V_111 ) ; V_32 -> V_100 |= V_96 ; break;
F_43 ( V_112 ) ; break;
default: V_42 = F_15 ( V_29 , V_6 , L_5 , T_3 ) ; break;
}
if ( V_84 & V_113 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_12 ) ;
if ( V_84 & V_114 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_13 ) ;
return V_42 ;
}
static T_1 F_44 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
T_1 V_42 ;
int type = V_32 -> V_37 ,
V_51 = type & ~ V_115 ;
type &= V_115 ;
switch ( type ) {
#define F_45 ( T_2 ) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
F_45 ( V_116 ) ;
F_45 ( V_117 ) ;
F_45 ( V_118 ) ;
F_45 ( V_119 ) ;
F_45 ( V_120 ) ;
F_45 ( V_121 ) ;
F_45 ( V_122 ) ;
#undef F_45
default:
V_42 = F_15 ( V_29 , V_6 , L_5 , type ) ;
}
#define F_46 ( T_2 ) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
F_46 ( V_123 ) ;
F_46 ( V_61 ) ;
#undef F_46
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_14 , V_51 ) ;
return V_42 ;
}
static T_1 F_47 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( V_51 == 0 )
return F_15 ( V_29 , V_6 , L_8 ) ;
#define F_48 ( T_2 ) \
if (flags & MSG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MSG_##n; \
}
F_48 ( V_124 ) ;
F_48 ( V_125 ) ;
F_48 ( V_126 ) ;
F_48 ( V_127 ) ;
F_48 ( V_128 ) ;
F_48 ( V_129 ) ;
F_48 ( V_130 ) ;
F_48 ( V_131 ) ;
F_48 ( V_132 ) ;
F_48 ( V_133 ) ;
F_48 ( V_134 ) ;
F_48 ( V_135 ) ;
F_48 ( V_136 ) ;
F_48 ( V_137 ) ;
F_48 ( V_138 ) ;
F_48 ( V_139 ) ;
F_48 ( V_140 ) ;
F_48 ( V_141 ) ;
F_48 ( V_142 ) ;
F_48 ( V_143 ) ;
F_48 ( V_144 ) ;
#undef F_48
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_49 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
T_1 V_42 = 0 ;
int V_145 = V_32 -> V_37 ;
if ( V_145 == V_146 )
return F_15 ( V_29 , V_6 , L_15 ) ;
#define F_50 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_50 ( V_147 ) ;
F_50 ( V_148 ) ;
F_50 ( V_149 ) ;
#undef F_50
if ( V_145 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_14 , V_145 ) ;
return V_42 ;
}
static T_1 F_51 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( ! ( V_51 & V_150 ) )
V_32 -> V_100 |= 1 << ( V_32 -> V_36 + 1 ) ;
if ( V_51 == 0 )
return F_15 ( V_29 , V_6 , L_16 ) ;
#define F_52 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_52 ( V_151 ) ;
F_52 ( V_152 ) ;
F_52 ( V_123 ) ;
F_52 ( V_153 ) ;
F_52 ( V_154 ) ;
F_52 ( V_155 ) ;
F_52 ( V_156 ) ;
F_52 ( V_157 ) ;
F_52 ( V_158 ) ;
F_52 ( V_159 ) ;
#ifdef F_53
F_52 ( V_61 ) ;
#elif V_160
F_52 ( V_161 ) ;
#endif
#ifdef F_54
F_52 ( V_162 ) ;
#endif
F_52 ( V_163 ) ;
#ifdef F_55
if ( ( V_51 & V_164 ) == V_164 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_17 , V_42 ? L_10 : L_11 , L_18 ) ;
else {
F_52 ( V_165 ) ;
}
#else
F_52 ( V_166 ) ;
#endif
F_52 ( V_130 ) ;
F_52 ( V_167 ) ;
#undef F_52
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_56 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( V_51 == 0 )
return 0 ;
#define F_52 ( T_2 ) \
if (flags & PERF_FLAG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~PERF_FLAG_##n; \
}
F_52 ( V_168 ) ;
F_52 ( V_169 ) ;
F_52 ( V_170 ) ;
F_52 ( V_171 ) ;
#undef F_52
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_57 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
if ( V_51 == 0 )
return F_15 ( V_29 , V_6 , L_8 ) ;
#define F_52 ( T_2 ) \
if (flags & EFD_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~EFD_##n; \
}
F_52 ( V_172 ) ;
F_52 ( V_123 ) ;
F_52 ( V_61 ) ;
#undef F_52
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_58 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_42 = 0 , V_51 = V_32 -> V_37 ;
#define F_52 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_52 ( V_123 ) ;
F_52 ( V_61 ) ;
#undef F_52
if ( V_51 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_9 , V_42 ? L_10 : L_11 , V_51 ) ;
return V_42 ;
}
static T_1 F_59 ( char * V_29 , T_1 V_6 , struct V_31 * V_32 )
{
int V_173 = V_32 -> V_37 ;
switch ( V_173 ) {
#define F_60 ( T_2 ) case SIG##n: return scnprintf(bf, size, #n)
F_60 ( V_174 ) ;
F_60 ( INT ) ;
F_60 ( V_175 ) ;
F_60 ( V_176 ) ;
F_60 ( V_177 ) ;
F_60 ( V_178 ) ;
F_60 ( V_179 ) ;
F_60 ( V_180 ) ;
F_60 ( V_181 ) ;
F_60 ( V_182 ) ;
F_60 ( V_183 ) ;
F_60 ( V_184 ) ;
F_60 ( V_185 ) ;
F_60 ( V_186 ) ;
F_60 ( V_187 ) ;
F_60 ( V_188 ) ;
F_60 ( V_189 ) ;
F_60 ( V_190 ) ;
F_60 ( V_191 ) ;
F_60 ( V_192 ) ;
F_60 ( V_193 ) ;
F_60 ( V_194 ) ;
F_60 ( V_195 ) ;
F_60 ( V_196 ) ;
F_60 ( V_197 ) ;
F_60 ( V_198 ) ;
F_60 ( V_199 ) ;
F_60 ( V_200 ) ;
F_60 ( V_201 ) ;
F_60 ( V_202 ) ;
#ifdef F_61
F_60 ( V_203 ) ;
#endif
#ifdef F_62
F_60 ( V_204 ) ;
#endif
#ifdef F_63
F_60 ( V_205 ) ;
#endif
default: break;
}
return F_15 ( V_29 , V_6 , L_5 , V_173 ) ;
}
static int F_64 ( const void * V_20 , const void * V_206 )
{
const struct V_207 * V_208 = V_206 ;
return strcmp ( V_20 , V_208 -> V_20 ) ;
}
static struct V_207 * F_65 ( const char * V_20 )
{
const int V_209 = F_66 ( V_210 ) ;
return bsearch ( V_20 , V_210 , V_209 , sizeof( struct V_207 ) , F_64 ) ;
}
static T_1 F_67 ( unsigned long V_211 , V_57 * V_212 )
{
double V_213 = ( double ) V_211 / V_214 ;
T_1 V_42 = fprintf ( V_212 , L_19 ) ;
if ( V_213 >= 1.0 )
V_42 += F_68 ( V_212 , V_215 , L_20 , V_213 ) ;
else if ( V_213 >= 0.01 )
V_42 += F_68 ( V_212 , V_216 , L_20 , V_213 ) ;
else
V_42 += F_68 ( V_212 , V_217 , L_20 , V_213 ) ;
return V_42 + fprintf ( V_212 , L_21 ) ;
}
static struct V_218 * F_69 ( void )
{
struct V_218 * V_219 = F_70 ( sizeof( struct V_218 ) ) ;
if ( V_219 )
V_219 -> V_220 . V_221 = - 1 ;
V_219 -> V_222 = F_71 ( NULL ) ;
return V_219 ;
}
static struct V_218 * F_72 ( struct V_223 * V_223 , V_57 * V_212 )
{
struct V_218 * V_219 ;
if ( V_223 == NULL )
goto V_224;
if ( F_73 ( V_223 ) == NULL )
F_74 ( V_223 , F_69 () ) ;
if ( F_73 ( V_223 ) == NULL )
goto V_224;
V_219 = F_73 ( V_223 ) ;
++ V_219 -> V_225 ;
return V_219 ;
V_224:
F_68 ( V_212 , V_215 ,
L_22 ) ;
return NULL ;
}
static int F_75 ( struct V_223 * V_223 , int V_40 , const char * V_226 )
{
struct V_218 * V_219 = F_73 ( V_223 ) ;
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
V_219 -> V_220 . V_228 [ V_40 ] = F_76 ( V_226 ) ;
return V_219 -> V_220 . V_228 [ V_40 ] != NULL ? 0 : - 1 ;
}
static int F_77 ( struct V_223 * V_223 , int V_40 )
{
char V_229 [ V_230 ] , V_226 [ V_230 ] ;
struct V_231 V_232 ;
int V_233 ;
if ( V_223 -> V_234 == V_223 -> V_235 ) {
F_15 ( V_229 , sizeof( V_229 ) ,
L_23 , V_223 -> V_234 , V_40 ) ;
} else {
F_15 ( V_229 , sizeof( V_229 ) ,
L_24 , V_223 -> V_234 , V_223 -> V_235 , V_40 ) ;
}
if ( F_78 ( V_229 , & V_232 ) < 0 || V_232 . V_236 + 1 > ( V_237 ) sizeof( V_226 ) )
return - 1 ;
V_233 = F_79 ( V_229 , V_226 , sizeof( V_226 ) ) ;
if ( V_233 < 0 || V_233 > V_232 . V_236 )
return - 1 ;
V_226 [ V_233 ] = '\0' ;
return F_75 ( V_223 , V_40 , V_226 ) ;
}
static const char * F_80 ( struct V_223 * V_223 , int V_40 ,
struct V_238 * V_238 )
{
struct V_218 * V_219 = F_73 ( V_223 ) ;
if ( V_219 == NULL )
return NULL ;
if ( V_40 < 0 )
return NULL ;
if ( ( V_40 > V_219 -> V_220 . V_221 || V_219 -> V_220 . V_228 [ V_40 ] == NULL ) ) {
if ( ! V_238 -> V_239 )
return NULL ;
++ V_238 -> V_240 . V_241 ;
if ( F_77 ( V_223 , V_40 ) )
return NULL ;
}
return V_219 -> V_220 . V_228 [ V_40 ] ;
}
static T_1 F_19 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_15 ( V_29 , V_6 , L_4 , V_40 ) ;
const char * V_242 = F_80 ( V_32 -> V_223 , V_40 , V_32 -> V_238 ) ;
if ( V_242 )
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 , L_25 , V_242 ) ;
return V_42 ;
}
static T_1 F_81 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
int V_40 = V_32 -> V_37 ;
T_1 V_42 = F_19 ( V_29 , V_6 , V_32 ) ;
struct V_218 * V_219 = F_73 ( V_32 -> V_223 ) ;
if ( V_219 && V_40 >= 0 && V_40 <= V_219 -> V_220 . V_221 )
F_8 ( & V_219 -> V_220 . V_228 [ V_40 ] ) ;
return V_42 ;
}
static void F_82 ( struct V_223 * V_223 , const char * V_29 ,
unsigned long V_243 )
{
struct V_218 * V_219 = F_73 ( V_223 ) ;
V_219 -> V_244 . V_243 = V_243 ;
V_219 -> V_244 . V_245 = V_29 - V_219 -> V_246 ;
}
static T_1 F_83 ( char * V_29 , T_1 V_6 ,
struct V_31 * V_32 )
{
unsigned long V_243 = V_32 -> V_37 ;
if ( ! V_32 -> V_238 -> V_247 )
return F_15 ( V_29 , V_6 , L_5 , V_243 ) ;
F_82 ( V_32 -> V_223 , V_29 , V_243 ) ;
return 0 ;
}
static bool F_84 ( struct V_238 * V_238 , double V_211 )
{
return V_211 < ( V_238 -> V_248 * V_214 ) ;
}
static T_1 F_85 ( struct V_238 * V_238 , T_5 V_249 , V_57 * V_212 )
{
double V_250 = ( double ) ( V_249 - V_238 -> V_251 ) / V_214 ;
return fprintf ( V_212 , L_26 , V_250 ) ;
}
static void F_86 ( int V_173 )
{
V_252 = true ;
V_253 = V_173 == V_254 ;
}
static T_1 F_87 ( struct V_238 * V_238 , struct V_223 * V_223 ,
T_5 V_213 , T_5 V_249 , V_57 * V_212 )
{
T_1 V_42 = F_85 ( V_238 , V_249 , V_212 ) ;
V_42 += F_67 ( V_213 , V_212 ) ;
if ( V_238 -> V_255 ) {
if ( V_238 -> V_256 )
V_42 += fprintf ( V_212 , L_27 , F_88 ( V_223 ) ) ;
V_42 += fprintf ( V_212 , L_28 , V_223 -> V_235 ) ;
}
return V_42 ;
}
static int F_89 ( struct V_238 * V_238 , struct V_257 * V_257 ,
union V_258 * V_259 , struct V_14 * V_15 )
{
int V_233 = 0 ;
switch ( V_259 -> V_260 . type ) {
case V_261 :
F_68 ( V_238 -> V_262 , V_215 ,
L_29 V_263 L_30 , V_259 -> V_264 . V_264 ) ;
V_233 = F_90 ( V_257 , V_259 , V_15 ) ;
default:
V_233 = F_91 ( V_257 , V_259 , V_15 ) ;
break;
}
return V_233 ;
}
static int F_92 ( struct V_265 * V_266 ,
union V_258 * V_259 ,
struct V_14 * V_15 ,
struct V_257 * V_257 )
{
struct V_238 * V_238 = F_93 ( V_266 , struct V_238 , V_266 ) ;
return F_89 ( V_238 , V_257 , V_259 , V_15 ) ;
}
static int F_94 ( struct V_238 * V_238 , struct V_267 * V_268 )
{
int V_269 = F_95 ( NULL ) ;
if ( V_269 )
return V_269 ;
V_238 -> V_270 = F_96 () ;
if ( V_238 -> V_270 == NULL )
return - V_26 ;
if ( F_97 ( V_238 -> V_270 , V_271 ) < 0 )
return - V_272 ;
V_269 = F_98 ( V_238 -> V_270 , & V_238 -> V_266 , & V_238 -> V_273 . V_274 ,
V_268 -> V_275 , F_92 , false ,
V_238 -> V_273 . V_276 ) ;
if ( V_269 )
F_99 () ;
return V_269 ;
}
static int F_100 ( struct V_277 * V_278 )
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
V_278 -> V_279 [ V_36 ] = F_20 ;
++ V_36 ;
}
return 0 ;
}
static int F_101 ( struct V_238 * V_238 , int V_24 )
{
char V_284 [ 128 ] ;
struct V_277 * V_278 ;
const char * V_20 = F_102 ( V_24 , V_238 -> V_285 . V_257 ) ;
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
V_278 -> V_208 = F_65 ( V_278 -> V_20 ) ;
snprintf ( V_284 , sizeof( V_284 ) , L_31 , V_278 -> V_20 ) ;
V_278 -> V_288 = F_103 ( L_2 , V_284 ) ;
if ( V_278 -> V_288 == NULL && V_278 -> V_208 && V_278 -> V_208 -> V_289 ) {
snprintf ( V_284 , sizeof( V_284 ) , L_31 , V_278 -> V_208 -> V_289 ) ;
V_278 -> V_288 = F_103 ( L_2 , V_284 ) ;
}
if ( V_278 -> V_288 == NULL )
return - 1 ;
V_278 -> args = V_278 -> V_288 -> V_290 . V_291 ;
V_278 -> V_280 = V_278 -> V_288 -> V_290 . V_292 ;
if ( V_278 -> args && strcmp ( V_278 -> args -> V_20 , L_32 ) == 0 ) {
V_278 -> args = V_278 -> args -> V_282 ;
-- V_278 -> V_280 ;
}
V_278 -> V_293 = ! strcmp ( V_20 , L_33 ) || ! strcmp ( V_20 , L_34 ) ;
return F_100 ( V_278 ) ;
}
static int F_104 ( struct V_238 * V_238 )
{
int V_269 = 0 , V_294 ;
struct V_295 * V_296 ;
V_238 -> V_297 . V_298 = F_105 ( V_238 -> V_299 ) ;
V_238 -> V_297 . V_39 = malloc ( V_238 -> V_297 . V_298 *
sizeof( V_238 -> V_297 . V_39 [ 0 ] ) ) ;
if ( V_238 -> V_297 . V_39 == NULL ) {
fputs ( L_35 ,
V_238 -> V_262 ) ;
V_269 = - V_300 ;
goto V_301;
}
V_294 = 0 ;
F_106 (pos, trace->ev_qualifier) {
const char * V_278 = V_296 -> V_302 ;
int V_24 = F_107 ( V_278 , V_238 -> V_285 . V_257 ) ;
if ( V_24 < 0 ) {
if ( V_269 == 0 ) {
fputs ( L_36 , V_238 -> V_262 ) ;
V_269 = - V_300 ;
} else {
fputs ( L_37 , V_238 -> V_262 ) ;
}
fputs ( V_278 , V_238 -> V_262 ) ;
}
V_238 -> V_297 . V_39 [ V_294 ++ ] = V_24 ;
}
if ( V_269 < 0 ) {
fputs ( L_38
L_39 , V_238 -> V_262 ) ;
F_8 ( & V_238 -> V_297 . V_39 ) ;
V_238 -> V_297 . V_298 = 0 ;
}
V_301:
return V_269 ;
}
static T_1 F_108 ( struct V_277 * V_278 , char * V_29 , T_1 V_6 ,
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
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 ,
L_40 , V_42 ? L_37 : L_11 , V_2 -> V_20 ) ;
if ( V_278 -> V_279 && V_278 -> V_279 [ V_32 . V_36 ] ) {
V_32 . V_37 = V_37 ;
if ( V_278 -> V_281 )
V_32 . V_35 = V_278 -> V_281 [ V_32 . V_36 ] ;
V_42 += V_278 -> V_279 [ V_32 . V_36 ] ( V_29 + V_42 ,
V_6 - V_42 , & V_32 ) ;
} else {
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 ,
L_41 , V_37 ) ;
}
}
} else {
int V_294 = 0 ;
while ( V_294 < 6 ) {
V_303 = args + sizeof( unsigned long ) * V_294 ;
memcpy ( & V_37 , V_303 , sizeof( V_37 ) ) ;
V_42 += F_15 ( V_29 + V_42 , V_6 - V_42 ,
L_42 ,
V_42 ? L_37 : L_11 , V_294 , V_37 ) ;
++ V_294 ;
}
}
return V_42 ;
}
static struct V_277 * F_109 ( struct V_238 * V_238 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_306 > 1 ) {
static T_5 T_2 ;
fprintf ( V_238 -> V_262 , L_43 V_263 L_44 ,
V_24 , F_110 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_238 -> V_286 . V_221 || V_238 -> V_286 . V_228 [ V_24 ] . V_20 == NULL ) &&
F_101 ( V_238 , V_24 ) )
goto V_307;
if ( ( V_24 > V_238 -> V_286 . V_221 || V_238 -> V_286 . V_228 [ V_24 ] . V_20 == NULL ) )
goto V_307;
return & V_238 -> V_286 . V_228 [ V_24 ] ;
V_307:
if ( V_306 ) {
fprintf ( V_238 -> V_262 , L_45 , V_24 ) ;
if ( V_24 <= V_238 -> V_286 . V_221 && V_238 -> V_286 . V_228 [ V_24 ] . V_20 != NULL )
fprintf ( V_238 -> V_262 , L_46 , V_238 -> V_286 . V_228 [ V_24 ] . V_20 ) ;
fputs ( L_47 , V_238 -> V_262 ) ;
}
return NULL ;
}
static void F_111 ( struct V_218 * V_219 ,
int V_24 , struct V_14 * V_15 )
{
struct V_308 * V_309 ;
struct V_240 * V_240 ;
T_5 V_213 = 0 ;
V_309 = F_112 ( V_219 -> V_222 , V_24 ) ;
if ( V_309 == NULL )
return;
V_240 = V_309 -> V_21 ;
if ( V_240 == NULL ) {
V_240 = malloc ( sizeof( struct V_240 ) ) ;
if ( V_240 == NULL )
return;
F_113 ( V_240 ) ;
V_309 -> V_21 = V_240 ;
}
if ( V_219 -> V_310 && V_15 -> time > V_219 -> V_310 )
V_213 = V_15 -> time - V_219 -> V_310 ;
F_114 ( V_240 , V_213 ) ;
}
static int F_115 ( struct V_238 * V_238 , struct V_14 * V_15 )
{
struct V_218 * V_219 ;
T_5 V_213 ;
T_1 V_42 ;
if ( V_238 -> V_311 == NULL )
return 0 ;
V_219 = F_73 ( V_238 -> V_311 ) ;
if ( ! V_219 -> V_312 )
return 0 ;
V_213 = V_15 -> time - V_219 -> V_310 ;
V_42 = F_87 ( V_238 , V_238 -> V_311 , V_213 , V_15 -> time , V_238 -> V_262 ) ;
V_42 += fprintf ( V_238 -> V_262 , L_48 , V_219 -> V_246 ) ;
V_219 -> V_312 = false ;
return V_42 ;
}
static int F_116 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
char * V_314 ;
void * args ;
T_1 V_42 = 0 ;
struct V_223 * V_223 ;
int V_24 = F_117 ( V_19 , V_24 , V_15 ) , V_269 = - 1 ;
struct V_277 * V_278 = F_109 ( V_238 , V_19 , V_24 ) ;
struct V_218 * V_219 ;
if ( V_278 == NULL )
return - 1 ;
V_223 = F_118 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
V_219 = F_72 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_316;
args = F_119 ( V_19 , args , V_15 ) ;
if ( V_219 -> V_246 == NULL ) {
V_219 -> V_246 = malloc ( V_317 ) ;
if ( ! V_219 -> V_246 )
goto V_316;
}
if ( ! V_238 -> V_318 )
F_115 ( V_238 , V_15 ) ;
V_219 -> V_310 = V_15 -> time ;
V_314 = V_219 -> V_246 ;
V_42 += F_15 ( V_314 + V_42 , V_317 - V_42 , L_49 , V_278 -> V_20 ) ;
V_42 += F_108 ( V_278 , V_314 + V_42 , V_317 - V_42 ,
args , V_238 , V_223 ) ;
if ( V_278 -> V_293 ) {
if ( ! V_238 -> V_248 && ! V_238 -> V_318 ) {
F_87 ( V_238 , V_223 , 1 , V_15 -> time , V_238 -> V_262 ) ;
fprintf ( V_238 -> V_262 , L_50 , V_219 -> V_246 ) ;
}
} else {
V_219 -> V_312 = true ;
V_219 -> V_244 . V_319 = false ;
}
if ( V_238 -> V_311 != V_223 ) {
F_120 ( V_238 -> V_311 ) ;
V_238 -> V_311 = F_121 ( V_223 ) ;
}
V_269 = 0 ;
V_316:
F_120 ( V_223 ) ;
return V_269 ;
}
static int F_122 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
long V_233 ;
T_5 V_213 = 0 ;
struct V_223 * V_223 ;
int V_24 = F_117 ( V_19 , V_24 , V_15 ) , V_269 = - 1 ;
struct V_277 * V_278 = F_109 ( V_238 , V_19 , V_24 ) ;
struct V_218 * V_219 ;
if ( V_278 == NULL )
return - 1 ;
V_223 = F_118 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
V_219 = F_72 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_316;
if ( V_238 -> V_320 )
F_111 ( V_219 , V_24 , V_15 ) ;
V_233 = F_117 ( V_19 , V_233 , V_15 ) ;
if ( V_24 == V_238 -> V_285 . V_321 && V_233 >= 0 && V_219 -> V_244 . V_319 ) {
F_75 ( V_223 , V_233 , V_219 -> V_244 . V_20 ) ;
V_219 -> V_244 . V_319 = false ;
++ V_238 -> V_240 . V_247 ;
}
V_219 -> V_322 = V_15 -> time ;
if ( V_219 -> V_310 ) {
V_213 = V_15 -> time - V_219 -> V_310 ;
if ( F_84 ( V_238 , V_213 ) )
goto V_301;
} else if ( V_238 -> V_248 )
goto V_301;
if ( V_238 -> V_318 )
goto V_301;
F_87 ( V_238 , V_223 , V_213 , V_15 -> time , V_238 -> V_262 ) ;
if ( V_219 -> V_312 ) {
fprintf ( V_238 -> V_262 , L_51 , V_219 -> V_246 ) ;
} else {
fprintf ( V_238 -> V_262 , L_52 ) ;
F_68 ( V_238 -> V_262 , V_216 , L_53 ) ;
fprintf ( V_238 -> V_262 , L_54 , V_278 -> V_20 ) ;
}
if ( V_278 -> V_208 == NULL ) {
V_323:
fprintf ( V_238 -> V_262 , L_55 , V_233 ) ;
} else if ( V_233 < 0 && V_278 -> V_208 -> V_324 ) {
char V_29 [ V_325 ] ;
const char * V_326 = F_123 ( - V_233 , V_29 , sizeof( V_29 ) ) ,
* V_327 = F_124 ( - V_233 ) ;
fprintf ( V_238 -> V_262 , L_56 , V_327 , V_326 ) ;
} else if ( V_233 == 0 && V_278 -> V_208 -> V_328 )
fprintf ( V_238 -> V_262 , L_57 ) ;
else if ( V_278 -> V_208 -> V_329 )
fprintf ( V_238 -> V_262 , L_58 , V_233 ) ;
else
goto V_323;
fputc ( '\n' , V_238 -> V_262 ) ;
V_301:
V_219 -> V_312 = false ;
V_269 = 0 ;
V_316:
F_120 ( V_223 ) ;
return V_269 ;
}
static int F_125 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
struct V_223 * V_223 = F_118 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
struct V_218 * V_219 ;
T_1 V_330 , V_331 , V_332 ;
T_7 V_333 ;
char * V_296 ;
const char * V_244 = F_126 ( V_19 , V_15 , L_59 ) ;
if ( ! V_223 )
goto V_301;
V_219 = F_73 ( V_223 ) ;
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
static int F_127 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
T_5 V_336 = F_128 ( V_19 , V_15 , L_60 ) ;
double V_337 = ( double ) V_336 / V_214 ;
struct V_223 * V_223 = F_118 ( V_238 -> V_270 ,
V_15 -> V_315 ,
V_15 -> V_235 ) ;
struct V_218 * V_219 = F_72 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_338;
V_219 -> V_337 += V_337 ;
V_238 -> V_337 += V_337 ;
F_120 ( V_223 ) ;
return 0 ;
V_338:
fprintf ( V_238 -> V_262 , L_61 V_263 L_62 V_263 L_63 ,
V_19 -> V_20 ,
F_129 ( V_19 , V_15 , L_64 ) ,
( V_339 ) F_128 ( V_19 , V_15 , L_65 ) ,
V_336 ,
F_128 ( V_19 , V_15 , L_66 ) ) ;
F_120 ( V_223 ) ;
return 0 ;
}
static int F_130 ( struct V_238 * V_238 , struct V_18 * V_19 ,
union V_258 * V_259 V_313 ,
struct V_14 * V_15 )
{
F_115 ( V_238 , V_15 ) ;
F_85 ( V_238 , V_15 -> time , V_238 -> V_262 ) ;
if ( V_238 -> V_340 )
fprintf ( V_238 -> V_262 , L_67 ) ;
fprintf ( V_238 -> V_262 , L_68 , V_19 -> V_20 ) ;
if ( V_19 -> V_288 ) {
F_131 ( V_19 -> V_288 , V_15 -> V_341 ,
V_15 -> V_16 , V_15 -> V_342 ,
V_238 -> V_262 ) ;
}
fprintf ( V_238 -> V_262 , L_63 ) ;
return 0 ;
}
static void F_132 ( V_57 * V_335 , struct V_14 * V_15 ,
struct V_343 * V_344 ,
bool V_345 , bool V_346 )
{
if ( ( V_306 || V_345 ) && V_344 -> V_347 )
fprintf ( V_335 , L_69 , V_344 -> V_347 -> V_348 -> V_349 ) ;
if ( ( V_306 || V_346 ) && V_344 -> V_350 )
fprintf ( V_335 , L_70 V_351 , V_344 -> V_350 -> V_20 ,
V_344 -> V_352 - V_344 -> V_350 -> V_353 ) ;
else if ( V_344 -> V_347 )
fprintf ( V_335 , L_71 V_351 , V_344 -> V_352 ) ;
else
fprintf ( V_335 , L_71 V_351 , V_15 -> V_352 ) ;
}
static int F_133 ( struct V_238 * V_238 ,
struct V_18 * V_19 ,
union V_258 * V_259 ,
struct V_14 * V_15 )
{
struct V_223 * V_223 ;
T_6 V_354 = V_259 -> V_260 . V_355 & V_356 ;
struct V_343 V_344 ;
char V_357 = 'd' ;
struct V_218 * V_219 ;
int V_269 = - 1 ;
V_223 = F_118 ( V_238 -> V_270 , V_15 -> V_315 , V_15 -> V_235 ) ;
V_219 = F_72 ( V_223 , V_238 -> V_262 ) ;
if ( V_219 == NULL )
goto V_316;
if ( V_19 -> V_358 . V_359 == V_360 )
V_219 -> V_361 ++ ;
else
V_219 -> V_362 ++ ;
if ( V_238 -> V_318 )
goto V_301;
F_134 ( V_223 , V_354 , V_363 ,
V_15 -> V_364 , & V_344 ) ;
F_87 ( V_238 , V_223 , 0 , V_15 -> time , V_238 -> V_262 ) ;
fprintf ( V_238 -> V_262 , L_72 ,
V_19 -> V_358 . V_359 == V_360 ?
L_73 : L_74 ) ;
F_132 ( V_238 -> V_262 , V_15 , & V_344 , false , true ) ;
fprintf ( V_238 -> V_262 , L_75 ) ;
F_134 ( V_223 , V_354 , V_365 ,
V_15 -> V_352 , & V_344 ) ;
if ( ! V_344 . V_347 ) {
F_134 ( V_223 , V_354 ,
V_363 , V_15 -> V_352 , & V_344 ) ;
if ( V_344 . V_347 )
V_357 = 'x' ;
else
V_357 = '?' ;
}
F_132 ( V_238 -> V_262 , V_15 , & V_344 , true , false ) ;
fprintf ( V_238 -> V_262 , L_76 , V_357 , V_344 . V_366 ) ;
V_301:
V_269 = 0 ;
V_316:
F_120 ( V_223 ) ;
return V_269 ;
}
static bool F_135 ( struct V_238 * V_238 , struct V_14 * V_15 )
{
if ( ( V_238 -> V_367 && F_136 ( V_238 -> V_367 , V_15 -> V_315 ) ) ||
( V_238 -> V_368 && F_136 ( V_238 -> V_368 , V_15 -> V_235 ) ) )
return false ;
if ( V_238 -> V_367 || V_238 -> V_368 )
return true ;
return false ;
}
static int F_137 ( struct V_265 * V_266 ,
union V_258 * V_259 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_257 * V_257 V_313 )
{
struct V_238 * V_238 = F_93 ( V_266 , struct V_238 , V_266 ) ;
int V_269 = 0 ;
T_8 V_22 = V_19 -> V_22 ;
if ( F_135 ( V_238 , V_15 ) )
return 0 ;
if ( ! V_238 -> V_369 && V_238 -> V_251 == 0 )
V_238 -> V_251 = V_15 -> time ;
if ( V_22 ) {
++ V_238 -> V_225 ;
V_22 ( V_238 , V_19 , V_259 , V_15 ) ;
}
return V_269 ;
}
static int F_138 ( struct V_238 * V_238 )
{
if ( V_238 -> V_273 . V_274 . V_315 ) {
V_238 -> V_367 = F_71 ( V_238 -> V_273 . V_274 . V_315 ) ;
if ( V_238 -> V_367 == NULL ) {
F_139 ( L_77 ) ;
return - V_300 ;
}
}
if ( V_238 -> V_273 . V_274 . V_235 ) {
V_238 -> V_368 = F_71 ( V_238 -> V_273 . V_274 . V_235 ) ;
if ( V_238 -> V_368 == NULL ) {
F_139 ( L_78 ) ;
return - V_300 ;
}
}
return 0 ;
}
static int F_140 ( struct V_238 * V_238 , int V_370 , const char * * V_371 )
{
unsigned int V_372 , V_294 , V_373 ;
const char * * V_374 ;
const char * const V_375 [] = {
L_79 ,
L_80 ,
L_81 , L_82 ,
L_83 , L_84 ,
} ;
const char * const V_376 [] = { L_85 , } ;
unsigned int V_377 = F_66 ( V_376 ) ;
const char * const V_378 [] = { L_85 , L_86 } ;
unsigned int V_379 = F_66 ( V_378 ) ;
const char * const V_380 [] = { L_85 , L_87 } ;
unsigned int V_381 = F_66 ( V_380 ) ;
V_372 = F_66 ( V_375 ) + V_377 + 1 +
V_379 + V_381 + V_370 ;
V_374 = calloc ( V_372 + 1 , sizeof( char * ) ) ;
if ( V_374 == NULL )
return - V_26 ;
V_373 = 0 ;
for ( V_294 = 0 ; V_294 < F_66 ( V_375 ) ; V_294 ++ )
V_374 [ V_373 ++ ] = V_375 [ V_294 ] ;
if ( V_238 -> V_340 ) {
for ( V_294 = 0 ; V_294 < V_377 ; V_294 ++ )
V_374 [ V_373 ++ ] = V_376 [ V_294 ] ;
if ( F_141 ( L_88 ) )
V_374 [ V_373 ++ ] = L_89 ;
else if ( F_141 ( L_90 ) )
V_374 [ V_373 ++ ] = L_91 ;
else {
F_139 ( L_92 ) ;
return - 1 ;
}
}
if ( V_238 -> V_382 & V_383 )
for ( V_294 = 0 ; V_294 < V_379 ; V_294 ++ )
V_374 [ V_373 ++ ] = V_378 [ V_294 ] ;
if ( V_238 -> V_382 & V_384 )
for ( V_294 = 0 ; V_294 < V_381 ; V_294 ++ )
V_374 [ V_373 ++ ] = V_380 [ V_294 ] ;
for ( V_294 = 0 ; V_294 < ( unsigned int ) V_370 ; V_294 ++ )
V_374 [ V_373 ++ ] = V_371 [ V_294 ] ;
return F_142 ( V_373 , V_374 , NULL ) ;
}
static bool F_143 ( struct V_267 * V_268 )
{
struct V_18 * V_19 = F_13 ( L_93 , L_94 ) ;
if ( V_19 == NULL )
return false ;
if ( F_5 ( V_19 , L_59 ) == NULL ) {
F_9 ( V_19 ) ;
return false ;
}
V_19 -> V_22 = F_125 ;
F_144 ( V_268 , V_19 ) ;
return true ;
}
static int F_145 ( struct V_267 * V_268 ,
T_5 V_359 )
{
struct V_18 * V_19 ;
struct V_385 V_358 = {
. type = V_386 ,
. V_387 = 1 ,
} ;
V_358 . V_359 = V_359 ;
V_358 . V_388 = 1 ;
F_146 ( & V_358 ) ;
V_19 = F_147 ( & V_358 ) ;
if ( ! V_19 )
return - V_26 ;
V_19 -> V_22 = F_133 ;
F_144 ( V_268 , V_19 ) ;
return 0 ;
}
static void F_148 ( struct V_238 * V_238 , union V_258 * V_259 , struct V_14 * V_15 )
{
const T_9 type = V_259 -> V_260 . type ;
struct V_18 * V_19 ;
if ( ! V_238 -> V_369 && V_238 -> V_251 == 0 )
V_238 -> V_251 = V_15 -> time ;
if ( type != V_389 ) {
F_89 ( V_238 , V_238 -> V_270 , V_259 , V_15 ) ;
return;
}
V_19 = F_149 ( V_238 -> V_268 , V_15 -> V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_238 -> V_262 , L_95 V_263 L_96 , V_15 -> V_24 ) ;
return;
}
if ( V_19 -> V_358 . type == V_390 &&
V_15 -> V_16 == NULL ) {
fprintf ( V_238 -> V_262 , L_97 ,
F_110 ( V_19 ) , V_15 -> V_235 ,
V_15 -> V_341 , V_15 -> V_342 ) ;
} else {
T_8 V_22 = V_19 -> V_22 ;
V_22 ( V_238 , V_19 , V_259 , V_15 ) ;
}
}
static int F_150 ( struct V_238 * V_238 )
{
int V_233 = - 1 ;
struct V_267 * V_268 = V_238 -> V_268 ;
struct V_18 * V_391 , * V_392 ;
V_391 = F_12 ( L_98 , F_116 ) ;
if ( V_391 == NULL )
goto V_301;
if ( F_151 ( V_391 , args ) )
goto V_393;
V_392 = F_12 ( L_99 , F_122 ) ;
if ( V_392 == NULL )
goto V_393;
if ( F_11 ( V_392 , V_233 ) )
goto V_394;
F_144 ( V_268 , V_391 ) ;
F_144 ( V_268 , V_392 ) ;
V_238 -> V_286 . V_395 . V_391 = V_391 ;
V_238 -> V_286 . V_395 . V_392 = V_392 ;
V_233 = 0 ;
V_301:
return V_233 ;
V_394:
F_7 ( V_392 ) ;
V_393:
F_7 ( V_391 ) ;
goto V_301;
}
static int F_152 ( struct V_238 * V_238 )
{
int V_269 = - 1 ;
char * V_396 = F_153 ( L_100 , ! V_238 -> V_397 ,
V_238 -> V_297 . V_298 ,
V_238 -> V_297 . V_39 ) ;
if ( V_396 == NULL )
goto V_398;
if ( ! F_154 ( V_238 -> V_286 . V_395 . V_391 , L_101 , V_396 ) )
V_269 = F_154 ( V_238 -> V_286 . V_395 . V_392 , L_101 , V_396 ) ;
free ( V_396 ) ;
V_301:
return V_269 ;
V_398:
V_272 = V_26 ;
goto V_301;
}
static int F_155 ( struct V_238 * V_238 , int V_370 , const char * * V_371 )
{
struct V_267 * V_268 = V_238 -> V_268 ;
struct V_18 * V_19 ;
int V_269 = - 1 , V_294 ;
unsigned long V_399 ;
const bool V_400 = V_370 > 0 ;
bool V_401 = false ;
V_238 -> V_239 = true ;
if ( V_238 -> V_340 && F_150 ( V_238 ) )
goto V_402;
if ( V_238 -> V_340 )
V_238 -> V_247 = F_143 ( V_268 ) ;
if ( ( V_238 -> V_382 & V_383 ) &&
F_145 ( V_268 , V_360 ) ) {
goto V_403;
}
if ( ( V_238 -> V_382 & V_384 ) &&
F_145 ( V_268 , V_404 ) )
goto V_403;
if ( V_238 -> V_405 &&
F_156 ( V_268 , L_102 , L_103 ,
F_127 ) )
goto V_406;
V_269 = F_157 ( V_268 , & V_238 -> V_273 . V_274 ) ;
if ( V_269 < 0 ) {
fprintf ( V_238 -> V_262 , L_104 ) ;
goto V_407;
}
V_269 = F_94 ( V_238 , V_268 ) ;
if ( V_269 < 0 ) {
fprintf ( V_238 -> V_262 , L_105 ) ;
goto V_407;
}
F_158 ( V_268 , & V_238 -> V_273 ) ;
signal ( V_408 , F_86 ) ;
signal ( V_254 , F_86 ) ;
if ( V_400 ) {
V_269 = F_159 ( V_268 , & V_238 -> V_273 . V_274 ,
V_371 , false , NULL ) ;
if ( V_269 < 0 ) {
fprintf ( V_238 -> V_262 , L_106 ) ;
goto V_407;
}
}
V_269 = F_160 ( V_268 ) ;
if ( V_269 < 0 )
goto V_409;
if ( V_238 -> V_410 . V_298 > 0 )
V_269 = F_161 ( V_268 , V_238 -> V_410 . V_298 , V_238 -> V_410 . V_39 ) ;
else if ( F_162 ( V_268 -> V_275 , 0 ) == - 1 )
V_269 = F_163 ( V_268 , F_164 () ) ;
if ( V_269 < 0 )
goto V_403;
if ( V_238 -> V_297 . V_298 > 0 ) {
V_269 = F_152 ( V_238 ) ;
if ( V_269 < 0 )
goto V_411;
F_165 ( L_107 ,
V_238 -> V_286 . V_395 . V_392 -> V_396 ) ;
}
V_269 = F_166 ( V_268 , & V_19 ) ;
if ( V_269 < 0 )
goto V_412;
V_269 = F_167 ( V_268 , V_238 -> V_273 . V_413 , false ) ;
if ( V_269 < 0 )
goto V_414;
if ( ! F_168 ( & V_238 -> V_273 . V_274 ) )
F_169 ( V_268 ) ;
if ( V_400 )
F_170 ( V_268 ) ;
V_238 -> V_255 = F_162 ( V_268 -> V_275 , 0 ) == - 1 ||
V_268 -> V_275 -> V_298 > 1 ||
F_171 ( V_268 ) -> V_358 . V_415 ;
V_416:
V_399 = V_238 -> V_225 ;
for ( V_294 = 0 ; V_294 < V_268 -> V_417 ; V_294 ++ ) {
union V_258 * V_259 ;
while ( ( V_259 = F_172 ( V_268 , V_294 ) ) != NULL ) {
struct V_14 V_15 ;
++ V_238 -> V_225 ;
V_269 = F_173 ( V_268 , V_259 , & V_15 ) ;
if ( V_269 ) {
fprintf ( V_238 -> V_262 , L_108 , V_269 ) ;
goto V_418;
}
F_148 ( V_238 , V_259 , & V_15 ) ;
V_418:
F_174 ( V_268 , V_294 ) ;
if ( V_253 )
goto V_419;
if ( V_252 && ! V_401 ) {
F_175 ( V_268 ) ;
V_401 = true ;
}
}
}
if ( V_238 -> V_225 == V_399 ) {
int V_328 = V_252 ? 100 : - 1 ;
if ( ! V_401 && F_176 ( V_268 , V_328 ) > 0 ) {
if ( F_177 ( V_268 , V_420 | V_421 ) == 0 )
V_401 = true ;
goto V_416;
}
} else {
goto V_416;
}
V_419:
F_178 ( V_238 -> V_311 ) ;
F_175 ( V_268 ) ;
if ( ! V_269 ) {
if ( V_238 -> V_320 )
F_179 ( V_238 , V_238 -> V_262 ) ;
if ( V_238 -> V_422 ) {
fprintf ( V_238 -> V_262 , L_109
L_110 V_263 L_111
L_112 V_263 L_111 ,
V_238 -> V_240 . V_247 ,
V_238 -> V_240 . V_241 ) ;
}
}
V_407:
F_180 ( V_268 ) ;
V_238 -> V_268 = NULL ;
V_238 -> V_239 = false ;
return V_269 ;
{
char V_423 [ V_424 ] ;
V_406:
F_181 ( V_272 , V_423 , sizeof( V_423 ) , L_102 , L_103 ) ;
goto V_425;
V_402:
F_181 ( V_272 , V_423 , sizeof( V_423 ) , L_1 , L_113 ) ;
goto V_425;
V_414:
F_182 ( V_268 , V_272 , V_423 , sizeof( V_423 ) ) ;
goto V_425;
V_409:
F_183 ( V_268 , V_272 , V_423 , sizeof( V_423 ) ) ;
V_425:
fprintf ( V_238 -> V_262 , L_114 , V_423 ) ;
goto V_407;
V_412:
fprintf ( V_238 -> V_262 ,
L_115 ,
V_19 -> V_396 , F_110 ( V_19 ) , V_272 ,
F_123 ( V_272 , V_423 , sizeof( V_423 ) ) ) ;
goto V_407;
}
V_403:
fprintf ( V_238 -> V_262 , L_116 ) ;
goto V_407;
V_411:
fprintf ( V_238 -> V_262 , L_117 , V_272 , strerror ( V_272 ) ) ;
goto V_407;
}
static int F_184 ( struct V_238 * V_238 )
{
const struct V_426 V_427 [] = {
{ L_118 , F_125 , } ,
} ;
struct V_428 V_429 = {
. V_242 = V_430 ,
. V_145 = V_431 ,
. V_432 = V_238 -> V_432 ,
} ;
struct V_433 * V_434 ;
struct V_18 * V_19 ;
int V_269 = - 1 ;
V_238 -> V_266 . V_15 = F_137 ;
V_238 -> V_266 . V_435 = V_436 ;
V_238 -> V_266 . V_437 = V_438 ;
V_238 -> V_266 . V_439 = V_440 ;
V_238 -> V_266 . exit = V_441 ;
V_238 -> V_266 . V_442 = V_443 ;
V_238 -> V_266 . V_358 = V_444 ;
V_238 -> V_266 . V_445 = V_446 ;
V_238 -> V_266 . V_447 = V_448 ;
V_238 -> V_266 . V_449 = true ;
V_238 -> V_266 . V_450 = true ;
V_238 -> V_255 = true ;
V_434 = F_185 ( & V_429 , false , & V_238 -> V_266 ) ;
if ( V_434 == NULL )
return - 1 ;
if ( F_95 ( & V_434 -> V_260 . V_451 ) < 0 )
goto V_301;
V_238 -> V_270 = & V_434 -> V_452 . V_270 ;
V_269 = F_186 ( V_434 , V_427 ) ;
if ( V_269 )
goto V_301;
V_19 = F_187 ( V_434 -> V_268 ,
L_88 ) ;
if ( V_19 == NULL )
V_19 = F_187 ( V_434 -> V_268 ,
L_90 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_116 ) < 0 ||
F_151 ( V_19 , args ) ) ) {
F_139 ( L_119 ) ;
goto V_301;
}
V_19 = F_187 ( V_434 -> V_268 ,
L_120 ) ;
if ( V_19 == NULL )
V_19 = F_187 ( V_434 -> V_268 ,
L_121 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_122 ) < 0 ||
F_11 ( V_19 , V_233 ) ) ) {
F_139 ( L_122 ) ;
goto V_301;
}
F_188 (session->evlist, evsel) {
if ( V_19 -> V_358 . type == V_386 &&
( V_19 -> V_358 . V_359 == V_360 ||
V_19 -> V_358 . V_359 == V_404 ||
V_19 -> V_358 . V_359 == V_453 ) )
V_19 -> V_22 = F_133 ;
}
V_269 = F_138 ( V_238 ) ;
if ( V_269 != 0 )
goto V_301;
F_189 () ;
V_269 = F_190 ( V_434 ) ;
if ( V_269 )
F_139 ( L_123 , V_269 ) ;
else if ( V_238 -> V_320 )
F_179 ( V_238 , V_238 -> V_262 ) ;
V_301:
F_191 ( V_434 ) ;
return V_269 ;
}
static T_1 F_192 ( V_57 * V_212 )
{
T_1 V_42 ;
V_42 = fprintf ( V_212 , L_124 ) ;
return V_42 ;
}
static T_1 F_193 ( struct V_218 * V_219 ,
struct V_238 * V_238 , V_57 * V_212 )
{
struct V_240 * V_240 ;
T_1 V_42 = 0 ;
struct V_277 * V_278 ;
struct V_308 * V_309 = F_194 ( V_219 -> V_222 ) ;
if ( V_309 == NULL )
return 0 ;
V_42 += fprintf ( V_212 , L_111 ) ;
V_42 += fprintf ( V_212 , L_125 ) ;
V_42 += fprintf ( V_212 , L_126 ) ;
V_42 += fprintf ( V_212 , L_127 ) ;
while ( V_309 ) {
V_240 = V_309 -> V_21 ;
if ( V_240 ) {
double V_454 = ( double ) ( V_240 -> V_454 ) / V_214 ;
double V_221 = ( double ) ( V_240 -> V_221 ) / V_214 ;
double V_455 = F_195 ( V_240 ) ;
double V_456 ;
T_5 T_2 = ( T_5 ) V_240 -> T_2 ;
V_456 = V_455 ? 100.0 * F_196 ( V_240 ) / V_455 : 0.0 ;
V_455 /= V_214 ;
V_278 = & V_238 -> V_286 . V_228 [ V_309 -> V_294 ] ;
V_42 += fprintf ( V_212 , L_128 , V_278 -> V_20 ) ;
V_42 += fprintf ( V_212 , L_129 V_263 L_130 ,
T_2 , V_455 * T_2 , V_454 , V_455 ) ;
V_42 += fprintf ( V_212 , L_131 , V_221 , V_456 ) ;
}
V_309 = F_197 ( V_309 ) ;
}
V_42 += fprintf ( V_212 , L_132 ) ;
return V_42 ;
}
static int F_198 ( struct V_223 * V_223 , void * V_21 )
{
struct V_457 * V_458 = V_21 ;
V_57 * V_212 = V_458 -> V_212 ;
T_1 V_42 = V_458 -> V_42 ;
struct V_238 * V_238 = V_458 -> V_238 ;
struct V_218 * V_219 = F_73 ( V_223 ) ;
double V_459 ;
if ( V_219 == NULL )
return 0 ;
V_459 = ( double ) V_219 -> V_225 / V_238 -> V_225 * 100.0 ;
V_42 += fprintf ( V_212 , L_133 , F_88 ( V_223 ) , V_223 -> V_235 ) ;
V_42 += fprintf ( V_212 , L_134 , V_219 -> V_225 ) ;
V_42 += fprintf ( V_212 , L_135 , V_459 ) ;
if ( V_219 -> V_361 )
V_42 += fprintf ( V_212 , L_136 , V_219 -> V_361 ) ;
if ( V_219 -> V_362 )
V_42 += fprintf ( V_212 , L_137 , V_219 -> V_362 ) ;
V_42 += fprintf ( V_212 , L_138 , V_219 -> V_337 ) ;
V_42 += F_193 ( V_219 , V_238 , V_212 ) ;
V_458 -> V_42 += V_42 ;
return 0 ;
}
static T_1 F_179 ( struct V_238 * V_238 , V_57 * V_212 )
{
struct V_457 V_458 = {
. V_212 = V_212 ,
. V_238 = V_238
} ;
V_458 . V_42 = F_192 ( V_212 ) ;
F_199 ( V_238 -> V_270 , F_198 , & V_458 ) ;
return V_458 . V_42 ;
}
static int F_200 ( const struct V_460 * V_461 , const char * V_462 ,
int T_10 V_313 )
{
struct V_238 * V_238 = V_461 -> V_463 ;
V_238 -> V_248 = atof ( V_462 ) ;
return 0 ;
}
static int F_201 ( const struct V_460 * V_461 , const char * V_462 ,
int T_10 V_313 )
{
int V_233 = - 1 ;
T_1 V_294 ;
struct V_238 * V_238 = V_461 -> V_463 ;
struct V_464 * V_465 = F_71 ( V_462 ) ;
if ( V_465 == NULL )
return - 1 ;
V_294 = V_238 -> V_410 . V_298 = F_202 ( V_465 ) + 1 ;
V_238 -> V_410 . V_39 = calloc ( V_294 , sizeof( V_339 ) ) ;
if ( V_238 -> V_410 . V_39 == NULL )
goto V_301;
V_238 -> V_410 . V_39 [ 0 ] = F_164 () ;
for ( V_294 = 1 ; V_294 < V_238 -> V_410 . V_298 ; ++ V_294 )
V_238 -> V_410 . V_39 [ V_294 ] = F_203 ( V_465 , V_294 - 1 ) -> V_294 ;
F_204 ( V_465 ) ;
V_233 = 0 ;
V_301:
return V_233 ;
}
static int F_205 ( struct V_238 * V_238 , const char * V_244 )
{
struct V_231 V_232 ;
if ( ! V_231 ( V_244 , & V_232 ) && V_232 . V_236 ) {
char V_466 [ V_230 ] ;
F_15 ( V_466 , sizeof( V_466 ) , L_139 , V_244 ) ;
F_206 ( V_466 ) ;
rename ( V_244 , V_466 ) ;
}
V_238 -> V_262 = fopen ( V_244 , L_140 ) ;
return V_238 -> V_262 == NULL ? - V_272 : 0 ;
}
static int F_207 ( const struct V_460 * V_461 , const char * V_462 ,
int T_10 V_313 )
{
int * V_382 = V_461 -> V_463 ;
if ( strcmp ( V_462 , L_141 ) == 0 )
* V_382 |= V_383 | V_384 ;
else if ( strcmp ( V_462 , L_73 ) == 0 )
* V_382 |= V_383 ;
else if ( strcmp ( V_462 , L_74 ) == 0 )
* V_382 |= V_384 ;
else
return - 1 ;
return 0 ;
}
static void F_208 ( struct V_267 * V_268 , void * V_22 )
{
struct V_18 * V_19 ;
F_188 (evlist, evsel)
V_19 -> V_22 = V_22 ;
}
int F_209 ( int V_370 , const char * * V_371 , const char * T_11 V_313 )
{
const char * V_467 [] = {
L_142 ,
L_143 ,
L_144 ,
L_145 ,
NULL
} ;
struct V_238 V_238 = {
. V_285 = {
. V_257 = F_210 () ,
. V_321 = F_107 ( L_146 , V_238 . V_285 . V_257 ) ,
} ,
. V_286 = {
. V_221 = - 1 ,
} ,
. V_273 = {
. V_274 = {
. V_468 = V_469 ,
. V_470 = true ,
} ,
. V_471 = V_469 ,
. V_472 = V_473 ,
. V_474 = true ,
. V_413 = V_469 ,
. V_276 = 500 ,
} ,
. V_262 = V_475 ,
. V_256 = true ,
. V_340 = true ,
} ;
const char * V_476 = NULL ;
const char * V_477 = NULL ;
const struct V_460 V_478 [] = {
F_211 ( 0 , L_147 , & V_238 . V_268 , L_147 ,
L_148 ,
V_479 ) ,
F_212 ( 0 , L_64 , & V_238 . V_256 ,
L_149 ) ,
F_212 ( 0 , L_150 , & V_238 . V_422 , L_151 ) ,
F_213 ( 'e' , L_152 , & V_477 , L_152 , L_153 ) ,
F_213 ( 'o' , L_154 , & V_476 , L_155 , L_156 ) ,
F_213 ( 'i' , L_157 , & V_430 , L_155 , L_158 ) ,
F_213 ( 'p' , L_65 , & V_238 . V_273 . V_274 . V_315 , L_65 ,
L_159 ) ,
F_213 ( 't' , L_160 , & V_238 . V_273 . V_274 . V_235 , L_160 ,
L_161 ) ,
F_211 ( 0 , L_162 , & V_238 , L_163 ,
L_164 , F_201 ) ,
F_212 ( 'a' , L_165 , & V_238 . V_273 . V_274 . V_480 ,
L_166 ) ,
F_213 ( 'C' , L_167 , & V_238 . V_273 . V_274 . V_481 , L_167 ,
L_168 ) ,
F_212 ( 0 , L_169 , & V_238 . V_273 . V_482 ,
L_170 ) ,
F_211 ( 'm' , L_171 , & V_238 . V_273 . V_413 , L_172 ,
L_173 ,
V_483 ) ,
F_213 ( 'u' , L_174 , & V_238 . V_273 . V_274 . V_484 , L_175 ,
L_176 ) ,
F_211 ( 0 , L_177 , & V_238 , L_178 ,
L_179 ,
F_200 ) ,
F_212 ( 0 , L_102 , & V_238 . V_405 , L_180 ) ,
F_214 ( 'v' , L_181 , & V_306 , L_182 ) ,
F_212 ( 'T' , L_183 , & V_238 . V_369 ,
L_184 ) ,
F_212 ( 's' , L_185 , & V_238 . V_318 ,
L_186 ) ,
F_212 ( 'S' , L_187 , & V_238 . V_320 ,
L_188 ) ,
F_215 ( 'F' , L_189 , & V_238 . V_382 , L_190 ,
L_191 , F_207 , L_73 ) ,
F_212 ( 0 , L_2 , & V_238 . V_340 , L_192 ) ,
F_212 ( 'f' , L_193 , & V_238 . V_432 , L_194 ) ,
F_216 ( 0 , L_195 , & V_238 . V_273 . V_276 ,
L_196 ) ,
F_217 ()
} ;
const char * const V_485 [] = { L_79 , NULL } ;
int V_269 ;
char V_29 [ V_424 ] ;
signal ( V_486 , V_487 ) ;
signal ( V_488 , V_487 ) ;
V_238 . V_268 = F_218 () ;
if ( V_238 . V_268 == NULL ) {
F_139 ( L_116 ) ;
V_269 = - V_26 ;
goto V_301;
}
V_370 = F_219 ( V_370 , V_371 , V_478 , V_485 ,
V_467 , V_489 ) ;
if ( V_238 . V_382 ) {
V_238 . V_273 . V_490 = true ;
V_238 . V_273 . V_491 = true ;
}
if ( V_238 . V_268 -> V_38 > 0 )
F_208 ( V_238 . V_268 , F_130 ) ;
if ( ( V_370 >= 1 ) && ( strcmp ( V_371 [ 0 ] , L_79 ) == 0 ) )
return F_140 ( & V_238 , V_370 - 1 , & V_371 [ 1 ] ) ;
if ( V_238 . V_318 )
V_238 . V_320 = V_238 . V_318 ;
if ( ! V_238 . V_340 && ! V_238 . V_382 &&
V_238 . V_268 -> V_38 == 0 ) {
F_139 ( L_197 ) ;
return - 1 ;
}
if ( V_476 != NULL ) {
V_269 = F_205 ( & V_238 , V_476 ) ;
if ( V_269 < 0 ) {
perror ( L_198 ) ;
goto V_301;
}
}
if ( V_477 != NULL ) {
const char * V_302 = V_477 ;
struct V_492 V_493 = {
. V_494 = F_220 ( V_495 ) ,
} ;
V_238 . V_397 = * V_302 == '!' ;
if ( V_238 . V_397 )
++ V_302 ;
V_238 . V_299 = F_221 ( V_302 , & V_493 ) ;
if ( V_238 . V_299 == NULL ) {
fputs ( L_199 ,
V_238 . V_262 ) ;
V_269 = - V_26 ;
goto V_496;
}
V_269 = F_104 ( & V_238 ) ;
if ( V_269 )
goto V_496;
}
V_269 = F_222 ( & V_238 . V_273 . V_274 ) ;
if ( V_269 ) {
F_223 ( & V_238 . V_273 . V_274 , V_269 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_238 . V_262 , L_3 , V_29 ) ;
goto V_496;
}
V_269 = F_224 ( & V_238 . V_273 . V_274 ) ;
if ( V_269 ) {
F_223 ( & V_238 . V_273 . V_274 , V_269 , V_29 , sizeof( V_29 ) ) ;
fprintf ( V_238 . V_262 , L_3 , V_29 ) ;
goto V_496;
}
if ( ! V_370 && F_168 ( & V_238 . V_273 . V_274 ) )
V_238 . V_273 . V_274 . V_480 = true ;
if ( V_430 )
V_269 = F_184 ( & V_238 ) ;
else
V_269 = F_155 ( & V_238 , V_370 , V_371 ) ;
V_496:
if ( V_476 != NULL )
fclose ( V_238 . V_262 ) ;
V_301:
return V_269 ;
}
