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
if ( ( V_50 > V_224 -> V_225 . V_226 || V_224 -> V_225 . V_233 [ V_50 ] == NULL ) ) {
if ( ! V_242 -> V_243 )
return NULL ;
++ V_242 -> V_244 . V_245 ;
if ( F_73 ( V_228 , V_50 ) )
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
V_272 -> V_290 = ! strcmp ( V_20 , L_34 ) || ! strcmp ( V_20 , L_35 ) ;
return F_93 ( V_272 ) ;
}
static T_1 F_98 ( struct V_271 * V_272 , char * V_39 , T_1 V_6 ,
unsigned long * args , struct V_242 * V_242 ,
struct V_228 * V_228 )
{
T_1 V_52 = 0 ;
if ( V_272 -> V_274 != NULL ) {
struct V_3 * V_2 ;
T_6 V_291 = 1 ;
struct V_41 V_42 = {
. V_46 = 0 ,
. V_109 = 0 ,
. V_242 = V_242 ,
. V_228 = V_228 ,
} ;
for ( V_2 = V_272 -> V_274 -> V_275 . V_278 -> V_279 ; V_2 ;
V_2 = V_2 -> V_279 , ++ V_42 . V_46 , V_291 <<= 1 ) {
if ( V_42 . V_109 & V_291 )
continue;
if ( args [ V_42 . V_46 ] == 0 &&
! ( V_272 -> V_273 &&
V_272 -> V_273 [ V_42 . V_46 ] == V_292 &&
V_272 -> V_277 [ V_42 . V_46 ] ) )
continue;
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_36 , V_52 ? L_37 : L_13 , V_2 -> V_20 ) ;
if ( V_272 -> V_273 && V_272 -> V_273 [ V_42 . V_46 ] ) {
V_42 . V_47 = args [ V_42 . V_46 ] ;
if ( V_272 -> V_277 )
V_42 . V_45 = V_272 -> V_277 [ V_42 . V_46 ] ;
V_52 += V_272 -> V_273 [ V_42 . V_46 ] ( V_39 + V_52 ,
V_6 - V_52 , & V_42 ) ;
} else {
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_38 , args [ V_42 . V_46 ] ) ;
}
}
} else {
int V_293 = 0 ;
while ( V_293 < 6 ) {
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_39 ,
V_52 ? L_37 : L_13 , V_293 , args [ V_293 ] ) ;
++ V_293 ;
}
}
return V_52 ;
}
static struct V_271 * F_99 ( struct V_242 * V_242 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_294 > 1 ) {
static T_5 T_2 ;
fprintf ( V_242 -> V_261 , L_40 V_262 L_41 ,
V_24 , F_100 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_242 -> V_283 . V_226 || V_242 -> V_283 . V_233 [ V_24 ] . V_20 == NULL ) &&
F_94 ( V_242 , V_24 ) )
goto V_295;
if ( ( V_24 > V_242 -> V_283 . V_226 || V_242 -> V_283 . V_233 [ V_24 ] . V_20 == NULL ) )
goto V_295;
return & V_242 -> V_283 . V_233 [ V_24 ] ;
V_295:
if ( V_294 ) {
fprintf ( V_242 -> V_261 , L_42 , V_24 ) ;
if ( V_24 <= V_242 -> V_283 . V_226 && V_242 -> V_283 . V_233 [ V_24 ] . V_20 != NULL )
fprintf ( V_242 -> V_261 , L_43 , V_242 -> V_283 . V_233 [ V_24 ] . V_20 ) ;
fputs ( L_44 , V_242 -> V_261 ) ;
}
return NULL ;
}
static void F_101 ( struct V_223 * V_224 ,
int V_24 , struct V_14 * V_15 )
{
struct V_296 * V_297 ;
struct V_244 * V_244 ;
T_5 V_218 = 0 ;
V_297 = F_102 ( V_224 -> V_227 , V_24 ) ;
if ( V_297 == NULL )
return;
V_244 = V_297 -> V_21 ;
if ( V_244 == NULL ) {
V_244 = malloc ( sizeof( struct V_244 ) ) ;
if ( V_244 == NULL )
return;
F_103 ( V_244 ) ;
V_297 -> V_21 = V_244 ;
}
if ( V_224 -> V_298 && V_15 -> time > V_224 -> V_298 )
V_218 = V_15 -> time - V_224 -> V_298 ;
F_104 ( V_244 , V_218 ) ;
}
static int F_105 ( struct V_242 * V_242 , struct V_18 * V_19 ,
union V_257 * V_258 V_299 ,
struct V_14 * V_15 )
{
char * V_300 ;
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
V_228 = F_107 ( V_242 -> V_267 , V_15 -> V_301 , V_15 -> V_239 ) ;
V_224 = F_70 ( V_228 , V_242 -> V_261 ) ;
if ( V_224 == NULL )
return - 1 ;
args = F_108 ( V_19 , args , V_15 ) ;
if ( V_224 -> V_302 == NULL ) {
V_224 -> V_302 = malloc ( 1024 ) ;
if ( ! V_224 -> V_302 )
return - 1 ;
}
V_224 -> V_298 = V_15 -> time ;
V_300 = V_224 -> V_302 ;
V_52 += F_18 ( V_300 + V_52 , 1024 - V_52 , L_45 , V_272 -> V_20 ) ;
V_52 += F_98 ( V_272 , V_300 + V_52 , 1024 - V_52 ,
args , V_242 , V_228 ) ;
if ( V_272 -> V_290 ) {
if ( ! V_242 -> V_247 && ! V_242 -> V_303 ) {
F_81 ( V_242 , V_228 , 1 , V_15 -> time , V_242 -> V_261 ) ;
fprintf ( V_242 -> V_261 , L_46 , V_224 -> V_302 ) ;
}
} else
V_224 -> V_304 = true ;
return 0 ;
}
static int F_109 ( struct V_242 * V_242 , struct V_18 * V_19 ,
union V_257 * V_258 V_299 ,
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
V_228 = F_107 ( V_242 -> V_267 , V_15 -> V_301 , V_15 -> V_239 ) ;
V_224 = F_70 ( V_228 , V_242 -> V_261 ) ;
if ( V_224 == NULL )
return - 1 ;
if ( V_242 -> V_305 )
F_101 ( V_224 , V_24 , V_15 ) ;
V_33 = F_106 ( V_19 , V_33 , V_15 ) ;
if ( V_24 == V_242 -> V_282 . V_306 && V_33 >= 0 && V_242 -> V_307 ) {
F_71 ( V_228 , V_33 , V_242 -> V_307 ) ;
V_242 -> V_307 = NULL ;
++ V_242 -> V_244 . V_308 ;
}
V_224 -> V_309 = V_15 -> time ;
if ( V_224 -> V_298 ) {
V_218 = V_15 -> time - V_224 -> V_298 ;
if ( F_78 ( V_242 , V_218 ) )
goto V_36;
} else if ( V_242 -> V_247 )
goto V_36;
if ( V_242 -> V_303 )
goto V_36;
F_81 ( V_242 , V_228 , V_218 , V_15 -> time , V_242 -> V_261 ) ;
if ( V_224 -> V_304 ) {
fprintf ( V_242 -> V_261 , L_47 , V_224 -> V_302 ) ;
} else {
fprintf ( V_242 -> V_261 , L_48 ) ;
F_66 ( V_242 -> V_261 , V_221 , L_49 ) ;
fprintf ( V_242 -> V_261 , L_50 , V_272 -> V_20 ) ;
}
if ( V_272 -> V_213 == NULL ) {
V_310:
fprintf ( V_242 -> V_261 , L_51 , V_33 ) ;
} else if ( V_33 < 0 && V_272 -> V_213 -> V_311 ) {
char V_39 [ 256 ] ;
const char * V_312 = F_110 ( - V_33 , V_39 , sizeof( V_39 ) ) ,
* V_313 = F_111 ( - V_33 ) ;
fprintf ( V_242 -> V_261 , L_52 , V_313 , V_312 ) ;
} else if ( V_33 == 0 && V_272 -> V_213 -> V_314 )
fprintf ( V_242 -> V_261 , L_53 ) ;
else if ( V_272 -> V_213 -> V_315 )
fprintf ( V_242 -> V_261 , L_54 , V_33 ) ;
else
goto V_310;
fputc ( '\n' , V_242 -> V_261 ) ;
V_36:
V_224 -> V_304 = false ;
return 0 ;
}
static int F_112 ( struct V_242 * V_242 , struct V_18 * V_19 ,
union V_257 * V_258 V_299 ,
struct V_14 * V_15 )
{
V_242 -> V_307 = F_113 ( V_19 , V_15 , L_55 ) ;
return 0 ;
}
static int F_114 ( struct V_242 * V_242 , struct V_18 * V_19 ,
union V_257 * V_258 V_299 ,
struct V_14 * V_15 )
{
T_5 V_316 = F_115 ( V_19 , V_15 , L_56 ) ;
double V_317 = ( double ) V_316 / V_219 ;
struct V_228 * V_228 = F_107 ( V_242 -> V_267 ,
V_15 -> V_301 ,
V_15 -> V_239 ) ;
struct V_223 * V_224 = F_70 ( V_228 , V_242 -> V_261 ) ;
if ( V_224 == NULL )
goto V_318;
V_224 -> V_317 += V_317 ;
V_242 -> V_317 += V_317 ;
return 0 ;
V_318:
fprintf ( V_242 -> V_261 , L_57 V_262 L_58 V_262 L_59 ,
V_19 -> V_20 ,
F_116 ( V_19 , V_15 , L_60 ) ,
( V_319 ) F_115 ( V_19 , V_15 , L_61 ) ,
V_316 ,
F_115 ( V_19 , V_15 , L_62 ) ) ;
return 0 ;
}
static void F_117 ( V_67 * V_320 , struct V_14 * V_15 ,
struct V_321 * V_322 ,
bool V_323 , bool V_324 )
{
if ( ( V_294 || V_323 ) && V_322 -> V_325 )
fprintf ( V_320 , L_63 , V_322 -> V_325 -> V_326 -> V_327 ) ;
if ( ( V_294 || V_324 ) && V_322 -> V_328 )
fprintf ( V_320 , L_64 V_329 , V_322 -> V_328 -> V_20 ,
V_322 -> V_330 - V_322 -> V_328 -> V_331 ) ;
else if ( V_322 -> V_325 )
fprintf ( V_320 , L_65 V_329 , V_322 -> V_330 ) ;
else
fprintf ( V_320 , L_65 V_329 , V_15 -> V_330 ) ;
}
static int F_118 ( struct V_242 * V_242 ,
struct V_18 * V_19 ,
union V_257 * V_258 ,
struct V_14 * V_15 )
{
struct V_228 * V_228 ;
T_6 V_332 = V_258 -> V_259 . V_333 & V_334 ;
struct V_321 V_322 ;
char V_335 = 'd' ;
struct V_223 * V_224 ;
V_228 = F_107 ( V_242 -> V_267 , V_15 -> V_301 , V_15 -> V_239 ) ;
V_224 = F_70 ( V_228 , V_242 -> V_261 ) ;
if ( V_224 == NULL )
return - 1 ;
if ( V_19 -> V_336 . V_337 == V_338 )
V_224 -> V_339 ++ ;
else
V_224 -> V_340 ++ ;
if ( V_242 -> V_303 )
return 0 ;
F_119 ( V_228 , V_242 -> V_267 , V_332 , V_341 ,
V_15 -> V_342 , & V_322 ) ;
F_81 ( V_242 , V_228 , 0 , V_15 -> time , V_242 -> V_261 ) ;
fprintf ( V_242 -> V_261 , L_66 ,
V_19 -> V_336 . V_337 == V_338 ?
L_67 : L_68 ) ;
F_117 ( V_242 -> V_261 , V_15 , & V_322 , false , true ) ;
fprintf ( V_242 -> V_261 , L_69 ) ;
F_119 ( V_228 , V_242 -> V_267 , V_332 , V_343 ,
V_15 -> V_330 , & V_322 ) ;
if ( ! V_322 . V_325 ) {
F_119 ( V_228 , V_242 -> V_267 , V_332 ,
V_341 , V_15 -> V_330 , & V_322 ) ;
if ( V_322 . V_325 )
V_335 = 'x' ;
else
V_335 = '?' ;
}
F_117 ( V_242 -> V_261 , V_15 , & V_322 , true , false ) ;
fprintf ( V_242 -> V_261 , L_70 , V_335 , V_322 . V_344 ) ;
return 0 ;
}
static bool F_120 ( struct V_242 * V_242 , struct V_14 * V_15 )
{
if ( ( V_242 -> V_345 && F_121 ( V_242 -> V_345 , V_15 -> V_301 ) ) ||
( V_242 -> V_346 && F_121 ( V_242 -> V_346 , V_15 -> V_239 ) ) )
return false ;
if ( V_242 -> V_345 || V_242 -> V_346 )
return true ;
return false ;
}
static int F_122 ( struct V_264 * V_265 ,
union V_257 * V_258 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_256 * V_256 V_299 )
{
struct V_242 * V_242 = F_87 ( V_265 , struct V_242 , V_265 ) ;
int V_266 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
if ( F_120 ( V_242 , V_15 ) )
return 0 ;
if ( ! V_242 -> V_347 && V_242 -> V_250 == 0 )
V_242 -> V_250 = V_15 -> time ;
if ( V_22 ) {
++ V_242 -> V_230 ;
V_22 ( V_242 , V_19 , V_258 , V_15 ) ;
}
return V_266 ;
}
static int F_123 ( struct V_242 * V_242 )
{
if ( V_242 -> V_268 . V_269 . V_301 ) {
V_242 -> V_345 = F_69 ( V_242 -> V_268 . V_269 . V_301 ) ;
if ( V_242 -> V_345 == NULL ) {
F_124 ( L_71 ) ;
return - V_348 ;
}
}
if ( V_242 -> V_268 . V_269 . V_239 ) {
V_242 -> V_346 = F_69 ( V_242 -> V_268 . V_269 . V_239 ) ;
if ( V_242 -> V_346 == NULL ) {
F_124 ( L_72 ) ;
return - V_348 ;
}
}
return 0 ;
}
static int F_125 ( struct V_242 * V_242 , int V_349 , const char * * V_350 )
{
unsigned int V_351 , V_293 , V_352 ;
const char * * V_353 ;
const char * const V_354 [] = {
L_73 ,
L_74 ,
L_75 , L_76 ,
L_77 , L_78 ,
} ;
const char * const V_355 [] = { L_79 , } ;
unsigned int V_356 = F_64 ( V_355 ) ;
const char * const V_357 [] = { L_79 , L_80 } ;
unsigned int V_358 = F_64 ( V_357 ) ;
const char * const V_359 [] = { L_79 , L_81 } ;
unsigned int V_360 = F_64 ( V_359 ) ;
V_351 = F_64 ( V_354 ) + V_356 + 1 +
V_358 + V_360 + V_349 ;
V_353 = calloc ( V_351 + 1 , sizeof( char * ) ) ;
if ( V_353 == NULL )
return - V_26 ;
V_352 = 0 ;
for ( V_293 = 0 ; V_293 < F_64 ( V_354 ) ; V_293 ++ )
V_353 [ V_352 ++ ] = V_354 [ V_293 ] ;
if ( V_242 -> V_361 ) {
for ( V_293 = 0 ; V_293 < V_356 ; V_293 ++ )
V_353 [ V_352 ++ ] = V_355 [ V_293 ] ;
if ( F_126 ( L_82 ) )
V_353 [ V_352 ++ ] = L_83 ;
else if ( F_126 ( L_84 ) )
V_353 [ V_352 ++ ] = L_85 ;
else {
F_124 ( L_86 ) ;
return - 1 ;
}
}
if ( V_242 -> V_362 & V_363 )
for ( V_293 = 0 ; V_293 < V_358 ; V_293 ++ )
V_353 [ V_352 ++ ] = V_357 [ V_293 ] ;
if ( V_242 -> V_362 & V_364 )
for ( V_293 = 0 ; V_293 < V_360 ; V_293 ++ )
V_353 [ V_352 ++ ] = V_359 [ V_293 ] ;
for ( V_293 = 0 ; V_293 < ( unsigned int ) V_349 ; V_293 ++ )
V_353 [ V_352 ++ ] = V_350 [ V_293 ] ;
return F_127 ( V_352 , V_353 , NULL ) ;
}
static void F_128 ( struct V_29 * V_30 )
{
struct V_18 * V_19 = F_13 ( L_87 , L_88 ) ;
if ( V_19 == NULL )
return;
if ( F_5 ( V_19 , L_55 ) == NULL ) {
F_9 ( V_19 ) ;
return;
}
V_19 -> V_22 = F_112 ;
F_16 ( V_30 , V_19 ) ;
}
static int F_129 ( struct V_29 * V_30 ,
T_5 V_337 )
{
struct V_18 * V_19 ;
struct V_365 V_336 = {
. type = V_366 ,
. V_367 = 1 ,
} ;
V_336 . V_337 = V_337 ;
V_336 . V_368 = 1 ;
F_130 ( & V_336 ) ;
V_19 = F_131 ( & V_336 ) ;
if ( ! V_19 )
return - V_26 ;
V_19 -> V_22 = F_118 ;
F_16 ( V_30 , V_19 ) ;
return 0 ;
}
static int F_132 ( struct V_242 * V_242 , int V_349 , const char * * V_350 )
{
struct V_29 * V_30 = F_133 () ;
struct V_18 * V_19 ;
int V_266 = - 1 , V_293 ;
unsigned long V_369 ;
const bool V_370 = V_349 > 0 ;
V_242 -> V_243 = true ;
if ( V_30 == NULL ) {
fprintf ( V_242 -> V_261 , L_89 ) ;
goto V_36;
}
if ( V_242 -> V_361 &&
F_14 ( V_30 , F_105 ,
F_109 ) )
goto V_371;
if ( V_242 -> V_361 )
F_128 ( V_30 ) ;
if ( ( V_242 -> V_362 & V_363 ) &&
F_129 ( V_30 , V_338 ) )
goto V_371;
if ( ( V_242 -> V_362 & V_364 ) &&
F_129 ( V_30 , V_372 ) )
goto V_371;
if ( V_242 -> V_373 &&
F_134 ( V_30 , L_90 , L_91 ,
F_114 ) )
goto V_371;
V_266 = F_135 ( V_30 , & V_242 -> V_268 . V_269 ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_92 ) ;
goto V_374;
}
V_266 = F_88 ( V_242 , V_30 ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_93 ) ;
goto V_374;
}
F_136 ( V_30 , & V_242 -> V_268 ) ;
signal ( V_375 , F_80 ) ;
signal ( V_253 , F_80 ) ;
if ( V_370 ) {
V_266 = F_137 ( V_30 , & V_242 -> V_268 . V_269 ,
V_350 , false , NULL ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_94 ) ;
goto V_374;
}
}
V_266 = F_138 ( V_30 ) ;
if ( V_266 < 0 )
goto V_376;
V_266 = F_139 ( V_30 , V_242 -> V_268 . V_377 , false ) ;
if ( V_266 < 0 ) {
fprintf ( V_242 -> V_261 , L_95 , strerror ( V_378 ) ) ;
goto V_374;
}
F_140 ( V_30 ) ;
if ( V_370 )
F_141 ( V_30 ) ;
V_242 -> V_254 = V_30 -> V_270 -> V_325 [ 0 ] == - 1 || V_30 -> V_270 -> V_379 > 1 ;
V_380:
V_369 = V_242 -> V_230 ;
for ( V_293 = 0 ; V_293 < V_30 -> V_381 ; V_293 ++ ) {
union V_257 * V_258 ;
while ( ( V_258 = F_142 ( V_30 , V_293 ) ) != NULL ) {
const T_8 type = V_258 -> V_259 . type ;
T_7 V_22 ;
struct V_14 V_15 ;
++ V_242 -> V_230 ;
V_266 = F_143 ( V_30 , V_258 , & V_15 ) ;
if ( V_266 ) {
fprintf ( V_242 -> V_261 , L_96 , V_266 ) ;
goto V_382;
}
if ( ! V_242 -> V_347 && V_242 -> V_250 == 0 )
V_242 -> V_250 = V_15 . time ;
if ( type != V_383 ) {
F_83 ( V_242 , V_242 -> V_267 , V_258 , & V_15 ) ;
continue;
}
V_19 = F_144 ( V_30 , V_15 . V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_242 -> V_261 , L_97 V_262 L_98 , V_15 . V_24 ) ;
goto V_382;
}
if ( V_19 -> V_336 . type == V_384 &&
V_15 . V_16 == NULL ) {
fprintf ( V_242 -> V_261 , L_99 ,
F_100 ( V_19 ) , V_15 . V_239 ,
V_15 . V_385 , V_15 . V_386 ) ;
goto V_382;
}
V_22 = V_19 -> V_22 ;
V_22 ( V_242 , V_19 , V_258 , & V_15 ) ;
V_382:
F_145 ( V_30 , V_293 ) ;
if ( V_252 )
goto V_387;
}
}
if ( V_242 -> V_230 == V_369 ) {
int V_314 = V_251 ? 100 : - 1 ;
if ( F_146 ( V_30 -> V_388 , V_30 -> V_389 , V_314 ) > 0 )
goto V_380;
} else {
goto V_380;
}
V_387:
F_147 ( V_30 ) ;
if ( ! V_266 ) {
if ( V_242 -> V_305 )
F_148 ( V_242 , V_242 -> V_261 ) ;
if ( V_242 -> V_390 ) {
fprintf ( V_242 -> V_261 , L_100
L_101 V_262 L_102
L_103 V_262 L_102 ,
V_242 -> V_244 . V_308 ,
V_242 -> V_244 . V_245 ) ;
}
}
V_374:
F_149 ( V_30 ) ;
V_36:
V_242 -> V_243 = false ;
return V_266 ;
{
char V_391 [ V_392 ] ;
V_371:
F_150 ( V_30 , V_378 , V_391 , sizeof( V_391 ) ) ;
goto V_393;
V_376:
F_151 ( V_30 , V_378 , V_391 , sizeof( V_391 ) ) ;
V_393:
fprintf ( V_242 -> V_261 , L_104 , V_391 ) ;
goto V_374;
}
}
static int F_152 ( struct V_242 * V_242 )
{
const struct V_394 V_395 [] = {
{ L_105 , F_112 , } ,
} ;
struct V_396 V_397 = {
. V_246 = V_398 ,
. V_154 = V_399 ,
} ;
struct V_400 * V_401 ;
struct V_18 * V_19 ;
int V_266 = - 1 ;
V_242 -> V_265 . V_15 = F_122 ;
V_242 -> V_265 . V_402 = V_403 ;
V_242 -> V_265 . V_404 = V_405 ;
V_242 -> V_265 . V_406 = V_407 ;
V_242 -> V_265 . exit = V_408 ;
V_242 -> V_265 . V_409 = V_410 ;
V_242 -> V_265 . V_336 = V_411 ;
V_242 -> V_265 . V_412 = V_413 ;
V_242 -> V_265 . V_414 = V_415 ;
V_242 -> V_265 . V_416 = true ;
V_242 -> V_265 . V_417 = true ;
V_242 -> V_254 = true ;
if ( F_89 () < 0 )
return - 1 ;
V_401 = F_153 ( & V_397 , false , & V_242 -> V_265 ) ;
if ( V_401 == NULL )
return - V_26 ;
V_242 -> V_267 = & V_401 -> V_418 . V_267 ;
V_266 = F_154 ( V_401 , V_395 ) ;
if ( V_266 )
goto V_36;
V_19 = F_155 ( V_401 -> V_30 ,
L_82 ) ;
if ( V_19 == NULL )
V_19 = F_155 ( V_401 -> V_30 ,
L_84 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_105 ) < 0 ||
F_15 ( V_19 , args ) ) ) {
F_124 ( L_106 ) ;
goto V_36;
}
V_19 = F_155 ( V_401 -> V_30 ,
L_107 ) ;
if ( V_19 == NULL )
V_19 = F_155 ( V_401 -> V_30 ,
L_108 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_109 ) < 0 ||
F_11 ( V_19 , V_33 ) ) ) {
F_124 ( L_109 ) ;
goto V_36;
}
F_156 (session->evlist, evsel) {
if ( V_19 -> V_336 . type == V_366 &&
( V_19 -> V_336 . V_337 == V_338 ||
V_19 -> V_336 . V_337 == V_372 ||
V_19 -> V_336 . V_337 == V_419 ) )
V_19 -> V_22 = F_118 ;
}
V_266 = F_123 ( V_242 ) ;
if ( V_266 != 0 )
goto V_36;
F_157 () ;
V_266 = F_158 ( V_401 , & V_242 -> V_265 ) ;
if ( V_266 )
F_124 ( L_110 , V_266 ) ;
else if ( V_242 -> V_305 )
F_148 ( V_242 , V_242 -> V_261 ) ;
V_36:
F_159 ( V_401 ) ;
return V_266 ;
}
static T_1 F_160 ( V_67 * V_217 )
{
T_1 V_52 ;
V_52 = fprintf ( V_217 , L_111 ) ;
return V_52 ;
}
static T_1 F_161 ( struct V_223 * V_224 ,
struct V_242 * V_242 , V_67 * V_217 )
{
struct V_244 * V_244 ;
T_1 V_52 = 0 ;
struct V_271 * V_272 ;
struct V_296 * V_297 = F_162 ( V_224 -> V_227 ) ;
if ( V_297 == NULL )
return 0 ;
V_52 += fprintf ( V_217 , L_102 ) ;
V_52 += fprintf ( V_217 , L_112 ) ;
V_52 += fprintf ( V_217 , L_113 ) ;
V_52 += fprintf ( V_217 , L_114 ) ;
while ( V_297 ) {
V_244 = V_297 -> V_21 ;
if ( V_244 ) {
double V_420 = ( double ) ( V_244 -> V_420 ) / V_219 ;
double V_226 = ( double ) ( V_244 -> V_226 ) / V_219 ;
double V_421 = F_163 ( V_244 ) ;
double V_422 ;
T_5 T_2 = ( T_5 ) V_244 -> T_2 ;
V_422 = V_421 ? 100.0 * F_164 ( V_244 ) / V_421 : 0.0 ;
V_421 /= V_219 ;
V_272 = & V_242 -> V_283 . V_233 [ V_297 -> V_293 ] ;
V_52 += fprintf ( V_217 , L_115 , V_272 -> V_20 ) ;
V_52 += fprintf ( V_217 , L_116 V_262 L_117 ,
T_2 , V_420 , V_421 ) ;
V_52 += fprintf ( V_217 , L_118 , V_226 , V_422 ) ;
}
V_297 = F_165 ( V_297 ) ;
}
V_52 += fprintf ( V_217 , L_119 ) ;
return V_52 ;
}
static int F_166 ( struct V_228 * V_228 , void * V_21 )
{
struct V_423 * V_424 = V_21 ;
V_67 * V_217 = V_424 -> V_217 ;
T_1 V_52 = V_424 -> V_52 ;
struct V_242 * V_242 = V_424 -> V_242 ;
struct V_223 * V_224 = V_228 -> V_21 ;
double V_425 ;
if ( V_224 == NULL )
return 0 ;
V_425 = ( double ) V_224 -> V_230 / V_242 -> V_230 * 100.0 ;
V_52 += fprintf ( V_217 , L_120 , F_82 ( V_228 ) , V_228 -> V_239 ) ;
V_52 += fprintf ( V_217 , L_121 , V_224 -> V_230 ) ;
V_52 += fprintf ( V_217 , L_122 , V_425 ) ;
if ( V_224 -> V_339 )
V_52 += fprintf ( V_217 , L_123 , V_224 -> V_339 ) ;
if ( V_224 -> V_340 )
V_52 += fprintf ( V_217 , L_124 , V_224 -> V_340 ) ;
V_52 += fprintf ( V_217 , L_125 , V_224 -> V_317 ) ;
V_52 += F_161 ( V_224 , V_242 , V_217 ) ;
V_424 -> V_52 += V_52 ;
return 0 ;
}
static T_1 F_148 ( struct V_242 * V_242 , V_67 * V_217 )
{
struct V_423 V_424 = {
. V_217 = V_217 ,
. V_242 = V_242
} ;
V_424 . V_52 = F_160 ( V_217 ) ;
F_167 ( V_242 -> V_267 , F_166 , & V_424 ) ;
return V_424 . V_52 ;
}
static int F_168 ( const struct V_426 * V_427 , const char * V_428 ,
int T_9 V_299 )
{
struct V_242 * V_242 = V_427 -> V_429 ;
V_242 -> V_247 = atof ( V_428 ) ;
return 0 ;
}
static int F_169 ( struct V_242 * V_242 , const char * V_430 )
{
struct V_236 V_237 ;
if ( ! V_236 ( V_430 , & V_237 ) && V_237 . V_240 ) {
char V_431 [ V_235 ] ;
F_18 ( V_431 , sizeof( V_431 ) , L_126 , V_430 ) ;
F_170 ( V_431 ) ;
rename ( V_430 , V_431 ) ;
}
V_242 -> V_261 = fopen ( V_430 , L_127 ) ;
return V_242 -> V_261 == NULL ? - V_378 : 0 ;
}
static int F_171 ( const struct V_426 * V_427 , const char * V_428 ,
int T_9 V_299 )
{
int * V_362 = V_427 -> V_429 ;
if ( strcmp ( V_428 , L_128 ) == 0 )
* V_362 |= V_363 | V_364 ;
else if ( strcmp ( V_428 , L_67 ) == 0 )
* V_362 |= V_363 ;
else if ( strcmp ( V_428 , L_68 ) == 0 )
* V_362 |= V_364 ;
else
return - 1 ;
return 0 ;
}
int F_172 ( int V_349 , const char * * V_350 , const char * T_10 V_299 )
{
const char * const V_432 [] = {
L_129 ,
L_130 ,
L_131 ,
L_132 ,
NULL
} ;
struct V_242 V_242 = {
. V_282 = {
. V_256 = F_173 () ,
. V_306 = F_174 ( L_133 , V_242 . V_282 . V_256 ) ,
} ,
. V_283 = {
. V_226 = - 1 ,
} ,
. V_268 = {
. V_269 = {
. V_433 = V_434 ,
. V_435 = true ,
} ,
. V_436 = V_434 ,
. V_437 = V_438 ,
. V_439 = true ,
. V_377 = 1024 ,
} ,
. V_261 = stdout ,
. V_255 = true ,
. V_361 = true ,
} ;
const char * V_440 = NULL ;
const char * V_441 = NULL ;
const struct V_426 V_442 [] = {
F_175 ( 0 , L_60 , & V_242 . V_255 ,
L_134 ) ,
F_175 ( 0 , L_135 , & V_242 . V_390 , L_136 ) ,
F_176 ( 'e' , L_137 , & V_441 , L_137 ,
L_138 ) ,
F_176 ( 'o' , L_139 , & V_440 , L_140 , L_141 ) ,
F_176 ( 'i' , L_142 , & V_398 , L_140 , L_143 ) ,
F_176 ( 'p' , L_61 , & V_242 . V_268 . V_269 . V_301 , L_61 ,
L_144 ) ,
F_176 ( 't' , L_145 , & V_242 . V_268 . V_269 . V_239 , L_145 ,
L_146 ) ,
F_175 ( 'a' , L_147 , & V_242 . V_268 . V_269 . V_443 ,
L_148 ) ,
F_176 ( 'C' , L_149 , & V_242 . V_268 . V_269 . V_444 , L_149 ,
L_150 ) ,
F_175 ( 0 , L_151 , & V_242 . V_268 . V_445 ,
L_152 ) ,
F_177 ( 'm' , L_153 , & V_242 . V_268 . V_377 , L_154 ,
L_155 ,
V_446 ) ,
F_176 ( 'u' , L_156 , & V_242 . V_268 . V_269 . V_447 , L_157 ,
L_158 ) ,
F_177 ( 0 , L_159 , & V_242 , L_160 ,
L_161 ,
F_168 ) ,
F_175 ( 0 , L_90 , & V_242 . V_373 , L_162 ) ,
F_178 ( 'v' , L_163 , & V_294 , L_164 ) ,
F_175 ( 'T' , L_165 , & V_242 . V_347 ,
L_166 ) ,
F_175 ( 's' , L_167 , & V_242 . V_303 ,
L_168 ) ,
F_175 ( 'S' , L_169 , & V_242 . V_305 ,
L_170 ) ,
F_179 ( 'F' , L_171 , & V_242 . V_362 , L_172 ,
L_173 , F_171 , L_67 ) ,
F_175 ( 0 , L_2 , & V_242 . V_361 , L_174 ) ,
F_180 ()
} ;
int V_266 ;
char V_39 [ V_392 ] ;
V_349 = F_181 ( V_349 , V_350 , V_442 , V_432 ,
V_448 ) ;
if ( V_242 . V_362 ) {
V_242 . V_268 . V_449 = true ;
V_242 . V_268 . V_450 = true ;
}
if ( ( V_349 >= 1 ) && ( strcmp ( V_350 [ 0 ] , L_73 ) == 0 ) )
return F_125 ( & V_242 , V_349 - 1 , & V_350 [ 1 ] ) ;
if ( V_242 . V_303 )
V_242 . V_305 = V_242 . V_303 ;
if ( ! V_242 . V_361 && ! V_242 . V_362 ) {
F_124 ( L_175 ) ;
return - 1 ;
}
if ( V_440 != NULL ) {
V_266 = F_169 ( & V_242 , V_440 ) ;
if ( V_266 < 0 ) {
perror ( L_176 ) ;
goto V_36;
}
}
if ( V_441 != NULL ) {
const char * V_451 = V_441 ;
V_242 . V_287 = * V_451 == '!' ;
if ( V_242 . V_287 )
++ V_451 ;
V_242 . V_285 = F_182 ( true , V_451 ) ;
if ( V_242 . V_285 == NULL ) {
fputs ( L_177 ,
V_242 . V_261 ) ;
V_266 = - V_26 ;
goto V_452;
}
}
V_266 = F_183 ( & V_242 . V_268 . V_269 ) ;
if ( V_266 ) {
F_184 ( & V_242 . V_268 . V_269 , V_266 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_242 . V_261 , L_5 , V_39 ) ;
goto V_452;
}
V_266 = F_185 ( & V_242 . V_268 . V_269 ) ;
if ( V_266 ) {
F_184 ( & V_242 . V_268 . V_269 , V_266 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_242 . V_261 , L_5 , V_39 ) ;
goto V_452;
}
if ( ! V_349 && F_186 ( & V_242 . V_268 . V_269 ) )
V_242 . V_268 . V_269 . V_443 = true ;
if ( V_398 )
V_266 = F_152 ( & V_242 ) ;
else
V_266 = F_132 ( & V_242 , V_349 , V_350 ) ;
V_452:
if ( V_440 != NULL )
fclose ( V_242 . V_261 ) ;
V_36:
return V_266 ;
}
