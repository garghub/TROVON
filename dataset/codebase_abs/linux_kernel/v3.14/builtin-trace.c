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
static int F_14 ( struct V_29 * V_30 ,
void * V_31 ,
void * V_32 )
{
int V_33 = - 1 ;
struct V_18 * V_34 , * V_35 ;
V_34 = F_12 ( L_3 , V_31 ) ;
if ( V_34 == NULL )
goto V_36;
if ( F_15 ( V_34 , args ) )
goto V_37;
V_35 = F_12 ( L_4 , V_32 ) ;
if ( V_35 == NULL )
goto V_37;
if ( F_11 ( V_35 , V_33 ) )
goto V_38;
F_16 ( V_30 , V_34 ) ;
F_16 ( V_30 , V_35 ) ;
V_33 = 0 ;
V_36:
return V_33 ;
V_38:
F_7 ( V_35 ) ;
V_37:
F_7 ( V_34 ) ;
goto V_36;
}
static T_1 F_17 ( char * V_39 , T_1 V_6 ,
const char * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_45 ;
int V_46 = V_42 -> V_47 - V_44 -> V_5 ;
if ( V_46 < 0 || V_46 >= V_44 -> V_48 )
return F_18 ( V_39 , V_6 , V_40 , V_42 -> V_47 ) ;
return F_18 ( V_39 , V_6 , L_5 , V_44 -> V_49 [ V_46 ] ) ;
}
static T_1 F_19 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
return F_17 ( V_39 , V_6 , L_6 , V_42 ) ;
}
static T_1 F_20 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
return F_17 ( V_39 , V_6 , L_7 , V_42 ) ;
}
static T_1 F_21 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
if ( V_50 == V_51 )
return F_18 ( V_39 , V_6 , L_8 ) ;
return F_22 ( V_39 , V_6 , V_42 ) ;
}
static T_1 F_23 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
return F_18 ( V_39 , V_6 , L_9 , V_42 -> V_47 ) ;
}
static T_1 F_24 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_53 = V_42 -> V_47 ;
if ( V_53 == V_54 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_25 ( T_2 ) \
if (prot & PROT_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
prot &= ~PROT_##n; \
}
F_25 ( V_55 ) ;
F_25 ( V_56 ) ;
F_25 ( V_57 ) ;
#ifdef F_26
F_25 ( V_58 ) ;
#endif
F_25 ( V_59 ) ;
F_25 ( V_60 ) ;
#undef F_25
if ( V_53 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_53 ) ;
return V_52 ;
}
static T_1 F_27 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_28 ( T_2 ) \
if (flags & MAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MAP_##n; \
}
F_28 ( V_62 ) ;
F_28 ( V_63 ) ;
#ifdef F_29
F_28 ( 32BIT ) ;
#endif
F_28 ( V_64 ) ;
F_28 ( V_65 ) ;
F_28 ( V_66 ) ;
F_28 ( V_67 ) ;
F_28 ( V_68 ) ;
F_28 ( V_59 ) ;
#ifdef F_30
F_28 ( V_69 ) ;
#endif
F_28 ( V_70 ) ;
F_28 ( V_71 ) ;
F_28 ( V_72 ) ;
F_28 ( V_73 ) ;
F_28 ( V_74 ) ;
#ifdef F_31
F_28 ( V_75 ) ;
#endif
#undef F_28
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_32 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_76 = V_42 -> V_47 ;
switch ( V_76 ) {
#define F_33 ( T_2 ) case MADV_##n: return scnprintf(bf, size, #n)
F_33 ( V_77 ) ;
F_33 ( V_78 ) ;
F_33 ( V_79 ) ;
F_33 ( V_80 ) ;
F_33 ( V_81 ) ;
F_33 ( REMOVE ) ;
F_33 ( V_82 ) ;
F_33 ( V_83 ) ;
F_33 ( V_84 ) ;
#ifdef F_34
F_33 ( V_85 ) ;
#endif
F_33 ( V_86 ) ;
F_33 ( V_87 ) ;
#ifdef F_35
F_33 ( V_88 ) ;
#endif
#ifdef F_36
F_33 ( V_89 ) ;
#endif
#ifdef F_37
F_33 ( V_90 ) ;
#endif
#ifdef F_38
F_33 ( V_91 ) ;
#endif
#undef V_92
default: break;
}
return F_18 ( V_39 , V_6 , L_7 , V_76 ) ;
}
static T_1 F_39 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_93 = V_42 -> V_47 ;
if ( V_93 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_40 ( T_3 ) \
if ((op & LOCK_##cmd) == LOCK_##cmd) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #cmd); \
op &= ~LOCK_##cmd; \
}
F_40 ( V_94 ) ;
F_40 ( V_95 ) ;
F_40 ( V_96 ) ;
F_40 ( V_97 ) ;
F_40 ( V_98 ) ;
F_40 ( V_99 ) ;
F_40 ( V_56 ) ;
F_40 ( V_57 ) ;
#undef V_100
if ( V_93 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_93 ) ;
return V_52 ;
}
static T_1 F_41 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
{
enum T_4 {
V_101 = ( 1 << 0 ) ,
V_102 = ( 1 << 1 ) ,
V_103 = ( 1 << 2 ) ,
V_104 = ( 1 << 3 ) ,
V_105 = ( 1 << 4 ) ,
V_106 = ( 1 << 5 ) ,
};
int V_93 = V_42 -> V_47 ;
int T_3 = V_93 & V_107 ;
T_1 V_52 = 0 ;
switch ( T_3 ) {
#define F_42 ( T_2 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_42 ( V_108 ) ; V_42 -> V_109 |= V_106 | V_105 ; break;
F_42 ( V_110 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_42 ( V_111 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_42 ( V_112 ) ; V_42 -> V_109 |= V_106 | V_104 ; break;
F_42 ( V_113 ) ; V_42 -> V_109 |= V_104 ; break;
F_42 ( V_114 ) ; V_42 -> V_109 |= V_104 ; break;
F_42 ( V_115 ) ; break;
F_42 ( V_116 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_42 ( V_117 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_42 ( V_118 ) ; V_42 -> V_109 |= V_106 | V_105 ; break;
F_42 ( V_119 ) ; V_42 -> V_109 |= V_105 ; break;
F_42 ( V_120 ) ; V_42 -> V_109 |= V_105 ; break;
F_42 ( V_121 ) ; break;
default: V_52 = F_18 ( V_39 , V_6 , L_7 , T_3 ) ; break;
}
if ( V_93 & V_122 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_14 ) ;
if ( V_93 & V_123 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_15 ) ;
return V_52 ;
}
static T_1 F_43 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 ;
int type = V_42 -> V_47 ,
V_61 = type & ~ V_124 ;
type &= V_124 ;
switch ( type ) {
#define F_44 ( T_2 ) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
F_44 ( V_125 ) ;
F_44 ( V_126 ) ;
F_44 ( V_127 ) ;
F_44 ( V_128 ) ;
F_44 ( V_129 ) ;
F_44 ( V_130 ) ;
F_44 ( V_131 ) ;
#undef F_44
default:
V_52 = F_18 ( V_39 , V_6 , L_7 , type ) ;
}
#define F_45 ( T_2 ) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
F_45 ( V_132 ) ;
F_45 ( V_71 ) ;
#undef F_45
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_16 , V_61 ) ;
return V_52 ;
}
static T_1 F_46 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_47 ( T_2 ) \
if (flags & MSG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MSG_##n; \
}
F_47 ( V_133 ) ;
F_47 ( V_134 ) ;
F_47 ( V_135 ) ;
F_47 ( V_136 ) ;
F_47 ( V_137 ) ;
F_47 ( V_138 ) ;
F_47 ( V_139 ) ;
F_47 ( V_140 ) ;
F_47 ( V_141 ) ;
F_47 ( V_142 ) ;
F_47 ( V_143 ) ;
F_47 ( V_144 ) ;
F_47 ( V_145 ) ;
F_47 ( V_146 ) ;
F_47 ( V_147 ) ;
F_47 ( V_148 ) ;
F_47 ( V_149 ) ;
F_47 ( V_150 ) ;
F_47 ( V_151 ) ;
F_47 ( V_152 ) ;
F_47 ( V_153 ) ;
#undef F_47
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_48 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 = 0 ;
int V_154 = V_42 -> V_47 ;
if ( V_154 == V_155 )
return F_18 ( V_39 , V_6 , L_17 ) ;
#define F_49 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_49 ( V_156 ) ;
F_49 ( V_157 ) ;
F_49 ( V_158 ) ;
#undef F_49
if ( V_154 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_16 , V_154 ) ;
return V_52 ;
}
static T_1 F_50 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( ! ( V_61 & V_159 ) )
V_42 -> V_109 |= 1 << ( V_42 -> V_46 + 1 ) ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_18 ) ;
#define F_51 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_51 ( V_160 ) ;
F_51 ( V_161 ) ;
F_51 ( V_132 ) ;
F_51 ( V_162 ) ;
F_51 ( V_163 ) ;
F_51 ( V_164 ) ;
F_51 ( V_165 ) ;
F_51 ( V_166 ) ;
F_51 ( V_167 ) ;
F_51 ( V_168 ) ;
#ifdef F_52
F_51 ( V_71 ) ;
#elif V_169
F_51 ( V_170 ) ;
#endif
#ifdef F_53
F_51 ( V_171 ) ;
#endif
F_51 ( V_172 ) ;
#ifdef F_54
if ( ( V_61 & V_173 ) == V_173 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_19 , V_52 ? L_12 : L_13 , L_20 ) ;
else {
F_51 ( V_174 ) ;
}
#else
F_51 ( V_175 ) ;
#endif
F_51 ( V_139 ) ;
F_51 ( V_176 ) ;
#undef F_51
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_55 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_51 ( T_2 ) \
if (flags & EFD_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~EFD_##n; \
}
F_51 ( V_177 ) ;
F_51 ( V_132 ) ;
F_51 ( V_71 ) ;
#undef F_51
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_56 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_51 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_51 ( V_132 ) ;
F_51 ( V_71 ) ;
#undef F_51
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_57 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
{
int V_178 = V_42 -> V_47 ;
switch ( V_178 ) {
#define F_58 ( T_2 ) case SIG##n: return scnprintf(bf, size, #n)
F_58 ( V_179 ) ;
F_58 ( INT ) ;
F_58 ( V_180 ) ;
F_58 ( V_181 ) ;
F_58 ( V_182 ) ;
F_58 ( V_183 ) ;
F_58 ( V_184 ) ;
F_58 ( V_185 ) ;
F_58 ( V_186 ) ;
F_58 ( V_187 ) ;
F_58 ( V_188 ) ;
F_58 ( V_189 ) ;
F_58 ( V_190 ) ;
F_58 ( V_191 ) ;
F_58 ( V_192 ) ;
F_58 ( V_193 ) ;
F_58 ( V_194 ) ;
F_58 ( V_195 ) ;
F_58 ( V_196 ) ;
F_58 ( V_197 ) ;
F_58 ( V_198 ) ;
F_58 ( V_199 ) ;
F_58 ( V_200 ) ;
F_58 ( V_201 ) ;
F_58 ( V_202 ) ;
F_58 ( V_203 ) ;
F_58 ( V_204 ) ;
F_58 ( V_205 ) ;
F_58 ( V_206 ) ;
F_58 ( V_207 ) ;
#ifdef F_59
F_58 ( V_208 ) ;
#endif
#ifdef F_60
F_58 ( V_209 ) ;
#endif
#ifdef F_61
F_58 ( V_210 ) ;
#endif
default: break;
}
return F_18 ( V_39 , V_6 , L_7 , V_178 ) ;
}
static int F_62 ( const void * V_20 , const void * V_211 )
{
const struct V_212 * V_213 = V_211 ;
return strcmp ( V_20 , V_213 -> V_20 ) ;
}
static struct V_212 * F_63 ( const char * V_20 )
{
const int V_214 = F_64 ( V_215 ) ;
return bsearch ( V_20 , V_215 , V_214 , sizeof( struct V_212 ) , F_62 ) ;
}
static T_1 F_65 ( unsigned long V_216 , V_67 * V_217 )
{
double V_218 = ( double ) V_216 / V_219 ;
T_1 V_52 = fprintf ( V_217 , L_21 ) ;
if ( V_218 >= 1.0 )
V_52 += F_66 ( V_217 , V_220 , L_22 , V_218 ) ;
else if ( V_218 >= 0.01 )
V_52 += F_66 ( V_217 , V_221 , L_22 , V_218 ) ;
else
V_52 += F_66 ( V_217 , V_222 , L_22 , V_218 ) ;
return V_52 + fprintf ( V_217 , L_23 ) ;
}
static struct V_223 * F_67 ( void )
{
struct V_223 * V_224 = F_68 ( sizeof( struct V_223 ) ) ;
if ( V_224 )
V_224 -> V_225 . V_226 = - 1 ;
V_224 -> V_227 = F_69 ( NULL ) ;
return V_224 ;
}
static struct V_223 * F_70 ( struct V_228 * V_228 , V_67 * V_217 )
{
struct V_223 * V_224 ;
if ( V_228 == NULL )
goto V_229;
if ( V_228 -> V_21 == NULL )
V_228 -> V_21 = F_67 () ;
if ( V_228 -> V_21 == NULL )
goto V_229;
V_224 = V_228 -> V_21 ;
++ V_224 -> V_230 ;
return V_224 ;
V_229:
F_66 ( V_217 , V_220 ,
L_24 ) ;
return NULL ;
}
static int F_71 ( struct V_228 * V_228 , int V_50 , const char * V_231 )
{
struct V_223 * V_224 = V_228 -> V_21 ;
if ( V_50 > V_224 -> V_225 . V_226 ) {
char * * V_232 = realloc ( V_224 -> V_225 . V_233 , ( V_50 + 1 ) * sizeof( char * ) ) ;
if ( V_232 == NULL )
return - 1 ;
if ( V_224 -> V_225 . V_226 != - 1 ) {
memset ( V_232 + V_224 -> V_225 . V_226 + 1 , 0 ,
( V_50 - V_224 -> V_225 . V_226 ) * sizeof( char * ) ) ;
} else {
memset ( V_232 , 0 , ( V_50 + 1 ) * sizeof( char * ) ) ;
}
V_224 -> V_225 . V_233 = V_232 ;
V_224 -> V_225 . V_226 = V_50 ;
}
V_224 -> V_225 . V_233 [ V_50 ] = F_72 ( V_231 ) ;
return V_224 -> V_225 . V_233 [ V_50 ] != NULL ? 0 : - 1 ;
}
static int F_73 ( struct V_228 * V_228 , int V_50 )
{
char V_234 [ V_235 ] , V_231 [ V_235 ] ;
struct V_236 V_237 ;
int V_33 ;
if ( V_228 -> V_238 == V_228 -> V_239 ) {
F_18 ( V_234 , sizeof( V_234 ) ,
L_25 , V_228 -> V_238 , V_50 ) ;
} else {
F_18 ( V_234 , sizeof( V_234 ) ,
L_26 , V_228 -> V_238 , V_228 -> V_239 , V_50 ) ;
}
if ( F_74 ( V_234 , & V_237 ) < 0 || V_237 . V_240 + 1 > ( V_241 ) sizeof( V_231 ) )
return - 1 ;
V_33 = F_75 ( V_234 , V_231 , sizeof( V_231 ) ) ;
if ( V_33 < 0 || V_33 > V_237 . V_240 )
return - 1 ;
V_231 [ V_33 ] = '\0' ;
return F_71 ( V_228 , V_50 , V_231 ) ;
}
static const char * F_76 ( struct V_228 * V_228 , int V_50 ,
struct V_242 * V_242 )
{
struct V_223 * V_224 = V_228 -> V_21 ;
if ( V_224 == NULL )
return NULL ;
if ( V_50 < 0 )
return NULL ;
if ( ( V_50 > V_224 -> V_225 . V_226 || V_224 -> V_225 . V_233 [ V_50 ] == NULL ) )
if ( ! V_242 -> V_243 )
return NULL ;
++ V_242 -> V_244 . V_245 ;
if ( F_73 ( V_228 , V_50 ) ) {
return NULL ;
}
return V_224 -> V_225 . V_233 [ V_50 ] ;
}
static T_1 F_22 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_18 ( V_39 , V_6 , L_6 , V_50 ) ;
const char * V_246 = F_76 ( V_42 -> V_228 , V_50 , V_42 -> V_242 ) ;
if ( V_246 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_27 , V_246 ) ;
return V_52 ;
}
static T_1 F_77 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_22 ( V_39 , V_6 , V_42 ) ;
struct V_223 * V_224 = V_42 -> V_228 -> V_21 ;
if ( V_224 && V_50 >= 0 && V_50 <= V_224 -> V_225 . V_226 )
F_8 ( & V_224 -> V_225 . V_233 [ V_50 ] ) ;
return V_52 ;
}
static bool F_78 ( struct V_242 * V_242 , double V_216 )
{
return V_216 < ( V_242 -> V_247 * V_219 ) ;
}
static T_1 F_79 ( struct V_242 * V_242 , T_5 V_248 , V_67 * V_217 )
{
double V_249 = ( double ) ( V_248 - V_242 -> V_250 ) / V_219 ;
return fprintf ( V_217 , L_28 , V_249 ) ;
}
static void F_80 ( int V_178 )
{
V_251 = true ;
V_252 = V_178 == V_253 ;
}
static T_1 F_81 ( struct V_242 * V_242 , struct V_228 * V_228 ,
T_5 V_218 , T_5 V_248 , V_67 * V_217 )
{
T_1 V_52 = F_79 ( V_242 , V_248 , V_217 ) ;
V_52 += F_65 ( V_218 , V_217 ) ;
if ( V_242 -> V_254 ) {
if ( V_242 -> V_255 )
V_52 += fprintf ( V_217 , L_29 , F_82 ( V_228 ) ) ;
V_52 += fprintf ( V_217 , L_30 , V_228 -> V_239 ) ;
}
return V_52 ;
}
static int F_83 ( struct V_242 * V_242 , struct V_256 * V_256 ,
union V_257 * V_258 , struct V_14 * V_15 )
{
int V_33 = 0 ;
switch ( V_258 -> V_259 . type ) {
case V_260 :
F_66 ( V_242 -> V_261 , V_220 ,
L_31 V_262 L_32 , V_258 -> V_263 . V_263 ) ;
V_33 = F_84 ( V_256 , V_258 , V_15 ) ;
default:
V_33 = F_85 ( V_256 , V_258 , V_15 ) ;
break;
}
return V_33 ;
}
static int F_86 ( struct V_264 * V_265 ,
union V_257 * V_258 ,
struct V_14 * V_15 ,
struct V_256 * V_256 )
{
struct V_242 * V_242 = F_87 ( V_265 , struct V_242 , V_265 ) ;
return F_83 ( V_242 , V_256 , V_258 , V_15 ) ;
}
static int F_88 ( struct V_242 * V_242 , struct V_29 * V_30 )
{
int V_266 = F_89 () ;
if ( V_266 )
return V_266 ;
V_242 -> V_267 = F_90 () ;
if ( V_242 -> V_267 == NULL )
return - V_26 ;
V_266 = F_91 ( V_242 -> V_267 , & V_242 -> V_265 , & V_242 -> V_268 . V_269 ,
V_30 -> V_270 , F_86 , false ) ;
if ( V_266 )
F_92 () ;
return V_266 ;
}
static int F_93 ( struct V_271 * V_272 )
{
struct V_3 * V_2 ;
int V_46 = 0 ;
V_272 -> V_273 = calloc ( V_272 -> V_274 -> V_275 . V_276 - 1 , sizeof( void * ) ) ;
if ( V_272 -> V_273 == NULL )
return - 1 ;
if ( V_272 -> V_213 )
V_272 -> V_277 = V_272 -> V_213 -> V_277 ;
for ( V_2 = V_272 -> V_274 -> V_275 . V_278 -> V_279 ; V_2 ; V_2 = V_2 -> V_279 ) {
if ( V_272 -> V_213 && V_272 -> V_213 -> V_273 [ V_46 ] )
V_272 -> V_273 [ V_46 ] = V_272 -> V_213 -> V_273 [ V_46 ] ;
else if ( V_2 -> V_61 & V_280 )
V_272 -> V_273 [ V_46 ] = F_23 ;
++ V_46 ;
}
return 0 ;
}
static int F_94 ( struct V_242 * V_242 , int V_24 )
{
char V_281 [ 128 ] ;
struct V_271 * V_272 ;
const char * V_20 = F_95 ( V_24 , V_242 -> V_282 . V_256 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_242 -> V_283 . V_226 ) {
struct V_271 * V_284 = realloc ( V_242 -> V_283 . V_233 , ( V_24 + 1 ) * sizeof( * V_272 ) ) ;
if ( V_284 == NULL )
return - 1 ;
if ( V_242 -> V_283 . V_226 != - 1 ) {
memset ( V_284 + V_242 -> V_283 . V_226 + 1 , 0 ,
( V_24 - V_242 -> V_283 . V_226 ) * sizeof( * V_272 ) ) ;
} else {
memset ( V_284 , 0 , ( V_24 + 1 ) * sizeof( * V_272 ) ) ;
}
V_242 -> V_283 . V_233 = V_284 ;
V_242 -> V_283 . V_226 = V_24 ;
}
V_272 = V_242 -> V_283 . V_233 + V_24 ;
V_272 -> V_20 = V_20 ;
if ( V_242 -> V_285 ) {
bool V_286 = F_96 ( V_242 -> V_285 , V_20 ) != NULL ;
if ( ! ( V_286 ^ V_242 -> V_287 ) ) {
V_272 -> V_288 = true ;
return 0 ;
}
}
V_272 -> V_213 = F_63 ( V_272 -> V_20 ) ;
snprintf ( V_281 , sizeof( V_281 ) , L_33 , V_272 -> V_20 ) ;
V_272 -> V_274 = F_97 ( L_2 , V_281 ) ;
if ( V_272 -> V_274 == NULL && V_272 -> V_213 && V_272 -> V_213 -> V_289 ) {
snprintf ( V_281 , sizeof( V_281 ) , L_33 , V_272 -> V_213 -> V_289 ) ;
V_272 -> V_274 = F_97 ( L_2 , V_281 ) ;
}
if ( V_272 -> V_274 == NULL )
return - 1 ;
return F_93 ( V_272 ) ;
}
static T_1 F_98 ( struct V_271 * V_272 , char * V_39 , T_1 V_6 ,
unsigned long * args , struct V_242 * V_242 ,
struct V_228 * V_228 )
{
T_1 V_52 = 0 ;
if ( V_272 -> V_274 != NULL ) {
struct V_3 * V_2 ;
T_6 V_290 = 1 ;
struct V_41 V_42 = {
. V_46 = 0 ,
. V_109 = 0 ,
. V_242 = V_242 ,
. V_228 = V_228 ,
} ;
for ( V_2 = V_272 -> V_274 -> V_275 . V_278 -> V_279 ; V_2 ;
V_2 = V_2 -> V_279 , ++ V_42 . V_46 , V_290 <<= 1 ) {
if ( V_42 . V_109 & V_290 )
continue;
if ( args [ V_42 . V_46 ] == 0 &&
! ( V_272 -> V_273 &&
V_272 -> V_273 [ V_42 . V_46 ] == V_291 &&
V_272 -> V_277 [ V_42 . V_46 ] ) )
continue;
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_34 , V_52 ? L_35 : L_13 , V_2 -> V_20 ) ;
if ( V_272 -> V_273 && V_272 -> V_273 [ V_42 . V_46 ] ) {
V_42 . V_47 = args [ V_42 . V_46 ] ;
if ( V_272 -> V_277 )
V_42 . V_45 = V_272 -> V_277 [ V_42 . V_46 ] ;
V_52 += V_272 -> V_273 [ V_42 . V_46 ] ( V_39 + V_52 ,
V_6 - V_52 , & V_42 ) ;
} else {
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_36 , args [ V_42 . V_46 ] ) ;
}
}
} else {
int V_292 = 0 ;
while ( V_292 < 6 ) {
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_37 ,
V_52 ? L_35 : L_13 , V_292 , args [ V_292 ] ) ;
++ V_292 ;
}
}
return V_52 ;
}
static struct V_271 * F_99 ( struct V_242 * V_242 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_293 > 1 ) {
static T_5 T_2 ;
fprintf ( V_242 -> V_261 , L_38 V_262 L_39 ,
V_24 , F_100 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_242 -> V_283 . V_226 || V_242 -> V_283 . V_233 [ V_24 ] . V_20 == NULL ) &&
F_94 ( V_242 , V_24 ) )
goto V_294;
if ( ( V_24 > V_242 -> V_283 . V_226 || V_242 -> V_283 . V_233 [ V_24 ] . V_20 == NULL ) )
goto V_294;
return & V_242 -> V_283 . V_233 [ V_24 ] ;
V_294:
if ( V_293 ) {
fprintf ( V_242 -> V_261 , L_40 , V_24 ) ;
if ( V_24 <= V_242 -> V_283 . V_226 && V_242 -> V_283 . V_233 [ V_24 ] . V_20 != NULL )
fprintf ( V_242 -> V_261 , L_41 , V_242 -> V_283 . V_233 [ V_24 ] . V_20 ) ;
fputs ( L_42 , V_242 -> V_261 ) ;
}
return NULL ;
}
static void F_101 ( struct V_223 * V_224 ,
int V_24 , struct V_14 * V_15 )
{
struct V_295 * V_296 ;
struct V_244 * V_244 ;
T_5 V_218 = 0 ;
V_296 = F_102 ( V_224 -> V_227 , V_24 ) ;
if ( V_296 == NULL )
return;
V_244 = V_296 -> V_21 ;
if ( V_244 == NULL ) {
V_244 = malloc ( sizeof( struct V_244 ) ) ;
if ( V_244 == NULL )
return;
F_103 ( V_244 ) ;
V_296 -> V_21 = V_244 ;
}
if ( V_224 -> V_297 && V_15 -> time > V_224 -> V_297 )
V_218 = V_15 -> time - V_224 -> V_297 ;
F_104 ( V_244 , V_218 ) ;
}
static int F_105 ( struct V_242 * V_242 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
char * V_298 ;
void * args ;
T_1 V_52 = 0 ;
struct V_228 * V_228 ;
int V_24 = F_106 ( V_19 , V_24 , V_15 ) ;
struct V_271 * V_272 = F_99 ( V_242 , V_19 , V_24 ) ;
struct V_223 * V_224 ;
if ( V_272 == NULL )
return - 1 ;
if ( V_272 -> V_288 )
return 0 ;
V_228 = F_107 ( V_242 -> V_267 , V_15 -> V_299 , V_15 -> V_239 ) ;
V_224 = F_70 ( V_228 , V_242 -> V_261 ) ;
if ( V_224 == NULL )
return - 1 ;
args = F_108 ( V_19 , args , V_15 ) ;
V_224 = V_228 -> V_21 ;
if ( V_224 -> V_300 == NULL ) {
V_224 -> V_300 = malloc ( 1024 ) ;
if ( ! V_224 -> V_300 )
return - 1 ;
}
V_224 -> V_297 = V_15 -> time ;
V_298 = V_224 -> V_300 ;
V_52 += F_18 ( V_298 + V_52 , 1024 - V_52 , L_43 , V_272 -> V_20 ) ;
V_52 += F_98 ( V_272 , V_298 + V_52 , 1024 - V_52 ,
args , V_242 , V_228 ) ;
if ( ! strcmp ( V_272 -> V_20 , L_44 ) || ! strcmp ( V_272 -> V_20 , L_45 ) ) {
if ( ! V_242 -> V_247 && ! V_242 -> V_301 ) {
F_81 ( V_242 , V_228 , 1 , V_15 -> time , V_242 -> V_261 ) ;
fprintf ( V_242 -> V_261 , L_46 , V_224 -> V_300 ) ;
}
} else
V_224 -> V_302 = true ;
return 0 ;
}
static int F_109 ( struct V_242 * V_242 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
int V_33 ;
T_5 V_218 = 0 ;
struct V_228 * V_228 ;
int V_24 = F_106 ( V_19 , V_24 , V_15 ) ;
struct V_271 * V_272 = F_99 ( V_242 , V_19 , V_24 ) ;
struct V_223 * V_224 ;
if ( V_272 == NULL )
return - 1 ;
if ( V_272 -> V_288 )
return 0 ;
V_228 = F_107 ( V_242 -> V_267 , V_15 -> V_299 , V_15 -> V_239 ) ;
V_224 = F_70 ( V_228 , V_242 -> V_261 ) ;
if ( V_224 == NULL )
return - 1 ;
if ( V_242 -> V_303 )
F_101 ( V_224 , V_24 , V_15 ) ;
V_33 = F_106 ( V_19 , V_33 , V_15 ) ;
if ( V_24 == V_242 -> V_282 . V_304 && V_33 >= 0 && V_242 -> V_305 ) {
F_71 ( V_228 , V_33 , V_242 -> V_305 ) ;
V_242 -> V_305 = NULL ;
++ V_242 -> V_244 . V_306 ;
}
V_224 = V_228 -> V_21 ;
V_224 -> V_307 = V_15 -> time ;
if ( V_224 -> V_297 ) {
V_218 = V_15 -> time - V_224 -> V_297 ;
if ( F_78 ( V_242 , V_218 ) )
goto V_36;
} else if ( V_242 -> V_247 )
goto V_36;
if ( V_242 -> V_301 )
goto V_36;
F_81 ( V_242 , V_228 , V_218 , V_15 -> time , V_242 -> V_261 ) ;
if ( V_224 -> V_302 ) {
fprintf ( V_242 -> V_261 , L_47 , V_224 -> V_300 ) ;
} else {
fprintf ( V_242 -> V_261 , L_48 ) ;
F_66 ( V_242 -> V_261 , V_221 , L_49 ) ;
fprintf ( V_242 -> V_261 , L_50 , V_272 -> V_20 ) ;
}
if ( V_272 -> V_213 == NULL ) {
V_308:
fprintf ( V_242 -> V_261 , L_51 , V_33 ) ;
} else if ( V_33 < 0 && V_272 -> V_213 -> V_309 ) {
char V_39 [ 256 ] ;
const char * V_310 = F_110 ( - V_33 , V_39 , sizeof( V_39 ) ) ,
* V_311 = F_111 ( - V_33 ) ;
fprintf ( V_242 -> V_261 , L_52 , V_311 , V_310 ) ;
} else if ( V_33 == 0 && V_272 -> V_213 -> V_312 )
fprintf ( V_242 -> V_261 , L_53 ) ;
else if ( V_272 -> V_213 -> V_313 )
fprintf ( V_242 -> V_261 , L_54 , V_33 ) ;
else
goto V_308;
fputc ( '\n' , V_242 -> V_261 ) ;
V_36:
V_224 -> V_302 = false ;
return 0 ;
}
static int F_112 ( struct V_242 * V_242 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
V_242 -> V_305 = F_113 ( V_19 , V_15 , L_55 ) ;
return 0 ;
}
static int F_114 ( struct V_242 * V_242 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
T_5 V_314 = F_115 ( V_19 , V_15 , L_56 ) ;
double V_315 = ( double ) V_314 / V_219 ;
struct V_228 * V_228 = F_107 ( V_242 -> V_267 ,
V_15 -> V_299 ,
V_15 -> V_239 ) ;
struct V_223 * V_224 = F_70 ( V_228 , V_242 -> V_261 ) ;
if ( V_224 == NULL )
goto V_316;
V_224 -> V_315 += V_315 ;
V_242 -> V_315 += V_315 ;
return 0 ;
V_316:
fprintf ( V_242 -> V_261 , L_57 V_262 L_58 V_262 L_59 ,
V_19 -> V_20 ,
F_116 ( V_19 , V_15 , L_60 ) ,
( V_317 ) F_115 ( V_19 , V_15 , L_61 ) ,
V_314 ,
F_115 ( V_19 , V_15 , L_62 ) ) ;
return 0 ;
}
static bool F_117 ( struct V_242 * V_242 , struct V_14 * V_15 )
{
if ( ( V_242 -> V_318 && F_118 ( V_242 -> V_318 , V_15 -> V_299 ) ) ||
( V_242 -> V_319 && F_118 ( V_242 -> V_319 , V_15 -> V_239 ) ) )
return false ;
if ( V_242 -> V_318 || V_242 -> V_319 )
return true ;
return false ;
}
static int F_119 ( struct V_264 * V_265 ,
union V_257 * V_258 V_320 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_256 * V_256 V_320 )
{
struct V_242 * V_242 = F_87 ( V_265 , struct V_242 , V_265 ) ;
int V_266 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
if ( F_117 ( V_242 , V_15 ) )
return 0 ;
if ( ! V_242 -> V_321 && V_242 -> V_250 == 0 )
V_242 -> V_250 = V_15 -> time ;
if ( V_22 ) {
++ V_242 -> V_230 ;
V_22 ( V_242 , V_19 , V_15 ) ;
}
return V_266 ;
}
static int F_120 ( struct V_242 * V_242 )
{
if ( V_242 -> V_268 . V_269 . V_299 ) {
V_242 -> V_318 = F_69 ( V_242 -> V_268 . V_269 . V_299 ) ;
if ( V_242 -> V_318 == NULL ) {
F_121 ( L_63 ) ;
return - V_322 ;
}
}
if ( V_242 -> V_268 . V_269 . V_239 ) {
V_242 -> V_319 = F_69 ( V_242 -> V_268 . V_269 . V_239 ) ;
if ( V_242 -> V_319 == NULL ) {
F_121 ( L_64 ) ;
return - V_322 ;
}
}
return 0 ;
}
static int F_122 ( int V_323 , const char * * V_324 )
{
unsigned int V_325 , V_292 , V_326 ;
const char * * V_327 ;
const char * const V_328 [] = {
L_65 ,
L_66 ,
L_67 , L_68 ,
L_69 , L_70 ,
L_71 ,
} ;
V_325 = F_64 ( V_328 ) + 1 + V_323 ;
V_327 = calloc ( V_325 + 1 , sizeof( char * ) ) ;
if ( V_327 == NULL )
return - V_26 ;
for ( V_292 = 0 ; V_292 < F_64 ( V_328 ) ; V_292 ++ )
V_327 [ V_292 ] = V_328 [ V_292 ] ;
if ( F_123 ( L_72 ) )
V_327 [ V_292 ] = L_73 ;
else if ( F_123 ( L_74 ) )
V_327 [ V_292 ] = L_75 ;
else {
F_121 ( L_76 ) ;
return - 1 ;
}
V_292 ++ ;
for ( V_326 = 0 ; V_326 < ( unsigned int ) V_323 ; V_326 ++ , V_292 ++ )
V_327 [ V_292 ] = V_324 [ V_326 ] ;
return F_124 ( V_292 , V_327 , NULL ) ;
}
static void F_125 ( struct V_29 * V_30 )
{
struct V_18 * V_19 = F_13 ( L_77 , L_78 ) ;
if ( V_19 == NULL )
return;
if ( F_5 ( V_19 , L_55 ) == NULL ) {
F_9 ( V_19 ) ;
return;
}
V_19 -> V_22 = F_112 ;
F_16 ( V_30 , V_19 ) ;
}
static int F_126 ( struct V_242 * V_242 , int V_323 , const char * * V_324 )
{
struct V_29 * V_30 = F_127 () ;
struct V_18 * V_19 ;
int V_266 = - 1 , V_292 ;
unsigned long V_329 ;
const bool V_330 = V_323 > 0 ;
V_242 -> V_243 = true ;
if ( V_30 == NULL ) {
fprintf ( V_242 -> V_261 , L_79 ) ;
goto V_36;
}
if ( F_14 ( V_30 , F_105 , F_109 ) )
goto V_331;
F_125 ( V_30 ) ;
if ( V_242 -> V_332 &&
F_128 ( V_30 , L_80 , L_81 ,
F_114 ) )
goto V_331;
V_266 = F_129 ( V_30 , & V_242 -> V_268 . V_269 ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_82 ) ;
goto V_333;
}
V_266 = F_88 ( V_242 , V_30 ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_83 ) ;
goto V_333;
}
F_130 ( V_30 , & V_242 -> V_268 ) ;
signal ( V_334 , F_80 ) ;
signal ( V_253 , F_80 ) ;
if ( V_330 ) {
V_266 = F_131 ( V_30 , & V_242 -> V_268 . V_269 ,
V_324 , false , NULL ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_84 ) ;
goto V_333;
}
}
V_266 = F_132 ( V_30 ) ;
if ( V_266 < 0 )
goto V_335;
V_266 = F_133 ( V_30 , V_242 -> V_268 . V_336 , false ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_85 , strerror ( V_337 ) ) ;
goto V_333;
}
F_134 ( V_30 ) ;
if ( V_330 )
F_135 ( V_30 ) ;
V_242 -> V_254 = V_30 -> V_270 -> V_338 [ 0 ] == - 1 || V_30 -> V_270 -> V_339 > 1 ;
V_340:
V_329 = V_242 -> V_230 ;
for ( V_292 = 0 ; V_292 < V_30 -> V_341 ; V_292 ++ ) {
union V_257 * V_258 ;
while ( ( V_258 = F_136 ( V_30 , V_292 ) ) != NULL ) {
const T_8 type = V_258 -> V_259 . type ;
T_7 V_22 ;
struct V_14 V_15 ;
++ V_242 -> V_230 ;
V_266 = F_137 ( V_30 , V_258 , & V_15 ) ;
if ( V_266 ) {
fprintf ( V_242 -> V_261 , L_86 , V_266 ) ;
goto V_342;
}
if ( ! V_242 -> V_321 && V_242 -> V_250 == 0 )
V_242 -> V_250 = V_15 . time ;
if ( type != V_343 ) {
F_83 ( V_242 , V_242 -> V_267 , V_258 , & V_15 ) ;
continue;
}
V_19 = F_138 ( V_30 , V_15 . V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_242 -> V_261 , L_87 V_262 L_88 , V_15 . V_24 ) ;
goto V_342;
}
if ( V_15 . V_16 == NULL ) {
fprintf ( V_242 -> V_261 , L_89 ,
F_100 ( V_19 ) , V_15 . V_239 ,
V_15 . V_344 , V_15 . V_345 ) ;
goto V_342;
}
V_22 = V_19 -> V_22 ;
V_22 ( V_242 , V_19 , & V_15 ) ;
V_342:
F_139 ( V_30 , V_292 ) ;
if ( V_252 )
goto V_346;
}
}
if ( V_242 -> V_230 == V_329 ) {
int V_312 = V_251 ? 100 : - 1 ;
if ( F_140 ( V_30 -> V_347 , V_30 -> V_348 , V_312 ) > 0 )
goto V_340;
} else {
goto V_340;
}
V_346:
F_141 ( V_30 ) ;
if ( ! V_266 ) {
if ( V_242 -> V_303 )
F_142 ( V_242 , V_242 -> V_261 ) ;
if ( V_242 -> V_349 ) {
fprintf ( V_242 -> V_261 , L_90
L_91 V_262 L_92
L_93 V_262 L_92 ,
V_242 -> V_244 . V_306 ,
V_242 -> V_244 . V_245 ) ;
}
}
V_333:
F_143 ( V_30 ) ;
V_36:
V_242 -> V_243 = false ;
return V_266 ;
{
char V_350 [ V_351 ] ;
V_331:
F_144 ( V_30 , V_337 , V_350 , sizeof( V_350 ) ) ;
goto V_352;
V_335:
F_145 ( V_30 , V_337 , V_350 , sizeof( V_350 ) ) ;
V_352:
fprintf ( V_242 -> V_261 , L_94 , V_350 ) ;
goto V_333;
}
}
static int F_146 ( struct V_242 * V_242 )
{
const struct V_353 V_354 [] = {
{ L_95 , F_112 , } ,
} ;
struct V_355 V_356 = {
. V_246 = V_357 ,
. V_154 = V_358 ,
} ;
struct V_359 * V_360 ;
struct V_18 * V_19 ;
int V_266 = - 1 ;
V_242 -> V_265 . V_15 = F_119 ;
V_242 -> V_265 . V_361 = V_362 ;
V_242 -> V_265 . V_363 = V_364 ;
V_242 -> V_265 . V_365 = V_366 ;
V_242 -> V_265 . exit = V_367 ;
V_242 -> V_265 . V_368 = V_369 ;
V_242 -> V_265 . V_370 = V_371 ;
V_242 -> V_265 . V_372 = V_373 ;
V_242 -> V_265 . V_374 = V_375 ;
V_242 -> V_265 . V_376 = true ;
V_242 -> V_265 . V_377 = true ;
V_242 -> V_254 = true ;
if ( F_89 () < 0 )
return - 1 ;
V_360 = F_147 ( & V_356 , false , & V_242 -> V_265 ) ;
if ( V_360 == NULL )
return - V_26 ;
V_242 -> V_267 = & V_360 -> V_378 . V_267 ;
V_266 = F_148 ( V_360 , V_354 ) ;
if ( V_266 )
goto V_36;
V_19 = F_149 ( V_360 -> V_30 ,
L_72 ) ;
if ( V_19 == NULL )
V_19 = F_149 ( V_360 -> V_30 ,
L_74 ) ;
if ( V_19 == NULL ) {
F_121 ( L_96 ) ;
goto V_36;
}
if ( F_10 ( V_19 , F_105 ) < 0 ||
F_15 ( V_19 , args ) ) {
F_121 ( L_97 ) ;
goto V_36;
}
V_19 = F_149 ( V_360 -> V_30 ,
L_98 ) ;
if ( V_19 == NULL )
V_19 = F_149 ( V_360 -> V_30 ,
L_99 ) ;
if ( V_19 == NULL ) {
F_121 ( L_100 ) ;
goto V_36;
}
if ( F_10 ( V_19 , F_109 ) < 0 ||
F_11 ( V_19 , V_33 ) ) {
F_121 ( L_101 ) ;
goto V_36;
}
V_266 = F_120 ( V_242 ) ;
if ( V_266 != 0 )
goto V_36;
F_150 () ;
V_266 = F_151 ( V_360 , & V_242 -> V_265 ) ;
if ( V_266 )
F_121 ( L_102 , V_266 ) ;
else if ( V_242 -> V_303 )
F_142 ( V_242 , V_242 -> V_261 ) ;
V_36:
F_152 ( V_360 ) ;
return V_266 ;
}
static T_1 F_153 ( V_67 * V_217 )
{
T_1 V_52 ;
V_52 = fprintf ( V_217 , L_103 ) ;
return V_52 ;
}
static T_1 F_154 ( struct V_223 * V_224 ,
struct V_242 * V_242 , V_67 * V_217 )
{
struct V_244 * V_244 ;
T_1 V_52 = 0 ;
struct V_271 * V_272 ;
struct V_295 * V_296 = F_155 ( V_224 -> V_227 ) ;
if ( V_296 == NULL )
return 0 ;
V_52 += fprintf ( V_217 , L_92 ) ;
V_52 += fprintf ( V_217 , L_104 ) ;
V_52 += fprintf ( V_217 , L_105 ) ;
V_52 += fprintf ( V_217 , L_106 ) ;
while ( V_296 ) {
V_244 = V_296 -> V_21 ;
if ( V_244 ) {
double V_379 = ( double ) ( V_244 -> V_379 ) / V_219 ;
double V_226 = ( double ) ( V_244 -> V_226 ) / V_219 ;
double V_380 = F_156 ( V_244 ) ;
double V_381 ;
T_5 T_2 = ( T_5 ) V_244 -> T_2 ;
V_381 = V_380 ? 100.0 * F_157 ( V_244 ) / V_380 : 0.0 ;
V_380 /= V_219 ;
V_272 = & V_242 -> V_283 . V_233 [ V_296 -> V_292 ] ;
V_52 += fprintf ( V_217 , L_107 , V_272 -> V_20 ) ;
V_52 += fprintf ( V_217 , L_108 V_262 L_109 ,
T_2 , V_379 , V_380 ) ;
V_52 += fprintf ( V_217 , L_110 , V_226 , V_381 ) ;
}
V_296 = F_158 ( V_296 ) ;
}
V_52 += fprintf ( V_217 , L_111 ) ;
return V_52 ;
}
static int F_159 ( struct V_228 * V_228 , void * V_21 )
{
struct V_382 * V_383 = V_21 ;
V_67 * V_217 = V_383 -> V_217 ;
T_1 V_52 = V_383 -> V_52 ;
struct V_242 * V_242 = V_383 -> V_242 ;
struct V_223 * V_224 = V_228 -> V_21 ;
double V_384 ;
if ( V_224 == NULL )
return 0 ;
V_384 = ( double ) V_224 -> V_230 / V_242 -> V_230 * 100.0 ;
V_52 += fprintf ( V_217 , L_112 , F_82 ( V_228 ) , V_228 -> V_239 ) ;
V_52 += fprintf ( V_217 , L_113 , V_224 -> V_230 ) ;
V_52 += fprintf ( V_217 , L_114 , V_384 ) ;
V_52 += fprintf ( V_217 , L_115 , V_224 -> V_315 ) ;
V_52 += F_154 ( V_224 , V_242 , V_217 ) ;
V_383 -> V_52 += V_52 ;
return 0 ;
}
static T_1 F_142 ( struct V_242 * V_242 , V_67 * V_217 )
{
struct V_382 V_383 = {
. V_217 = V_217 ,
. V_242 = V_242
} ;
V_383 . V_52 = F_153 ( V_217 ) ;
F_160 ( V_242 -> V_267 , F_159 , & V_383 ) ;
return V_383 . V_52 ;
}
static int F_161 ( const struct V_385 * V_386 , const char * V_387 ,
int T_9 V_320 )
{
struct V_242 * V_242 = V_386 -> V_388 ;
V_242 -> V_247 = atof ( V_387 ) ;
return 0 ;
}
static int F_162 ( struct V_242 * V_242 , const char * V_389 )
{
struct V_236 V_237 ;
if ( ! V_236 ( V_389 , & V_237 ) && V_237 . V_240 ) {
char V_390 [ V_235 ] ;
F_18 ( V_390 , sizeof( V_390 ) , L_116 , V_389 ) ;
F_163 ( V_390 ) ;
rename ( V_389 , V_390 ) ;
}
V_242 -> V_261 = fopen ( V_389 , L_117 ) ;
return V_242 -> V_261 == NULL ? - V_337 : 0 ;
}
int F_164 ( int V_323 , const char * * V_324 , const char * T_10 V_320 )
{
const char * const V_391 [] = {
L_118 ,
L_119 ,
L_120 ,
L_121 ,
NULL
} ;
struct V_242 V_242 = {
. V_282 = {
. V_256 = F_165 () ,
. V_304 = F_166 ( L_122 , V_242 . V_282 . V_256 ) ,
} ,
. V_283 = {
. V_226 = - 1 ,
} ,
. V_268 = {
. V_269 = {
. V_392 = V_393 ,
. V_394 = true ,
} ,
. V_395 = V_393 ,
. V_396 = V_397 ,
. V_398 = true ,
. V_336 = 1024 ,
} ,
. V_261 = stdout ,
. V_255 = true ,
} ;
const char * V_399 = NULL ;
const char * V_400 = NULL ;
const struct V_385 V_401 [] = {
F_167 ( 0 , L_60 , & V_242 . V_255 ,
L_123 ) ,
F_167 ( 0 , L_124 , & V_242 . V_349 , L_125 ) ,
F_168 ( 'e' , L_126 , & V_400 , L_126 ,
L_127 ) ,
F_168 ( 'o' , L_128 , & V_399 , L_129 , L_130 ) ,
F_168 ( 'i' , L_131 , & V_357 , L_129 , L_132 ) ,
F_168 ( 'p' , L_61 , & V_242 . V_268 . V_269 . V_299 , L_61 ,
L_133 ) ,
F_168 ( 't' , L_134 , & V_242 . V_268 . V_269 . V_239 , L_134 ,
L_135 ) ,
F_167 ( 'a' , L_136 , & V_242 . V_268 . V_269 . V_402 ,
L_137 ) ,
F_168 ( 'C' , L_138 , & V_242 . V_268 . V_269 . V_403 , L_138 ,
L_139 ) ,
F_167 ( 0 , L_140 , & V_242 . V_268 . V_404 ,
L_141 ) ,
F_169 ( 'm' , L_142 , & V_242 . V_268 . V_336 , L_143 ,
L_144 ,
V_405 ) ,
F_168 ( 'u' , L_145 , & V_242 . V_268 . V_269 . V_406 , L_146 ,
L_147 ) ,
F_169 ( 0 , L_148 , & V_242 , L_149 ,
L_150 ,
F_161 ) ,
F_167 ( 0 , L_80 , & V_242 . V_332 , L_151 ) ,
F_170 ( 'v' , L_152 , & V_293 , L_153 ) ,
F_167 ( 'T' , L_154 , & V_242 . V_321 ,
L_155 ) ,
F_167 ( 's' , L_156 , & V_242 . V_301 ,
L_157 ) ,
F_167 ( 'S' , L_158 , & V_242 . V_303 ,
L_159 ) ,
F_171 ()
} ;
int V_266 ;
char V_39 [ V_351 ] ;
if ( ( V_323 > 1 ) && ( strcmp ( V_324 [ 1 ] , L_65 ) == 0 ) )
return F_122 ( V_323 - 2 , & V_324 [ 2 ] ) ;
V_323 = F_172 ( V_323 , V_324 , V_401 , V_391 , 0 ) ;
if ( V_242 . V_301 )
V_242 . V_303 = V_242 . V_301 ;
if ( V_399 != NULL ) {
V_266 = F_162 ( & V_242 , V_399 ) ;
if ( V_266 < 0 ) {
perror ( L_160 ) ;
goto V_36;
}
}
if ( V_400 != NULL ) {
const char * V_407 = V_400 ;
V_242 . V_287 = * V_407 == '!' ;
if ( V_242 . V_287 )
++ V_407 ;
V_242 . V_285 = F_173 ( true , V_407 ) ;
if ( V_242 . V_285 == NULL ) {
fputs ( L_161 ,
V_242 . V_261 ) ;
V_266 = - V_26 ;
goto V_408;
}
}
V_266 = F_174 ( & V_242 . V_268 . V_269 ) ;
if ( V_266 ) {
F_175 ( & V_242 . V_268 . V_269 , V_266 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_242 . V_261 , L_5 , V_39 ) ;
goto V_408;
}
V_266 = F_176 ( & V_242 . V_268 . V_269 ) ;
if ( V_266 ) {
F_175 ( & V_242 . V_268 . V_269 , V_266 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_242 . V_261 , L_5 , V_39 ) ;
goto V_408;
}
if ( ! V_323 && F_177 ( & V_242 . V_268 . V_269 ) )
V_242 . V_268 . V_269 . V_402 = true ;
if ( V_357 )
V_266 = F_146 ( & V_242 ) ;
else
V_266 = F_126 ( & V_242 , V_323 , V_324 ) ;
V_408:
if ( V_399 != NULL )
fclose ( V_242 . V_261 ) ;
V_36:
return V_266 ;
}
