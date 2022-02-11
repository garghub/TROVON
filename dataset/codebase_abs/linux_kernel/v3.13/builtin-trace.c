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
free ( V_19 -> V_21 ) ;
V_19 -> V_21 = NULL ;
F_8 ( V_19 ) ;
}
static int F_9 ( struct V_18 * V_19 , void * V_22 )
{
V_19 -> V_21 = malloc ( sizeof( struct V_23 ) ) ;
if ( V_19 -> V_21 != NULL ) {
if ( F_10 ( V_19 , V_24 ) )
goto V_25;
V_19 -> V_22 = V_22 ;
return 0 ;
}
return - V_26 ;
V_25:
free ( V_19 -> V_21 ) ;
V_19 -> V_21 = NULL ;
return - V_27 ;
}
static struct V_18 * F_11 ( const char * V_28 , void * V_22 )
{
struct V_18 * V_19 = F_12 ( L_1 , V_28 ) ;
if ( V_19 ) {
if ( F_9 ( V_19 , V_22 ) )
goto V_25;
}
return V_19 ;
V_25:
F_7 ( V_19 ) ;
return NULL ;
}
static int F_13 ( struct V_29 * V_30 ,
void * V_31 ,
void * V_32 )
{
int V_33 = - 1 ;
struct V_18 * V_34 , * V_35 ;
V_34 = F_11 ( L_2 , V_31 ) ;
if ( V_34 == NULL )
goto V_36;
if ( F_14 ( V_34 , args ) )
goto V_37;
V_35 = F_11 ( L_3 , V_32 ) ;
if ( V_35 == NULL )
goto V_37;
if ( F_10 ( V_35 , V_33 ) )
goto V_38;
F_15 ( V_30 , V_34 ) ;
F_15 ( V_30 , V_35 ) ;
V_33 = 0 ;
V_36:
return V_33 ;
V_38:
F_7 ( V_35 ) ;
V_37:
F_7 ( V_34 ) ;
goto V_36;
}
static T_1 F_16 ( char * V_39 , T_1 V_6 ,
const char * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_45 ;
int V_46 = V_42 -> V_47 - V_44 -> V_5 ;
if ( V_46 < 0 || V_46 >= V_44 -> V_48 )
return F_17 ( V_39 , V_6 , V_40 , V_42 -> V_47 ) ;
return F_17 ( V_39 , V_6 , L_4 , V_44 -> V_49 [ V_46 ] ) ;
}
static T_1 F_18 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
return F_16 ( V_39 , V_6 , L_5 , V_42 ) ;
}
static T_1 F_19 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
return F_16 ( V_39 , V_6 , L_6 , V_42 ) ;
}
static T_1 F_20 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
if ( V_50 == V_51 )
return F_17 ( V_39 , V_6 , L_7 ) ;
return F_21 ( V_39 , V_6 , V_42 ) ;
}
static T_1 F_22 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
return F_17 ( V_39 , V_6 , L_8 , V_42 -> V_47 ) ;
}
static T_1 F_23 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_53 = V_42 -> V_47 ;
if ( V_53 == V_54 )
return F_17 ( V_39 , V_6 , L_9 ) ;
#define F_24 ( T_2 ) \
if (prot & PROT_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
prot &= ~PROT_##n; \
}
F_24 ( V_55 ) ;
F_24 ( V_56 ) ;
F_24 ( V_57 ) ;
#ifdef F_25
F_24 ( V_58 ) ;
#endif
F_24 ( V_59 ) ;
F_24 ( V_60 ) ;
#undef F_24
if ( V_53 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_10 , V_52 ? L_11 : L_12 , V_53 ) ;
return V_52 ;
}
static T_1 F_26 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_27 ( T_2 ) \
if (flags & MAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MAP_##n; \
}
F_27 ( V_62 ) ;
F_27 ( V_63 ) ;
#ifdef F_28
F_27 ( 32BIT ) ;
#endif
F_27 ( V_64 ) ;
F_27 ( V_65 ) ;
F_27 ( V_66 ) ;
F_27 ( V_67 ) ;
F_27 ( V_68 ) ;
F_27 ( V_59 ) ;
#ifdef F_29
F_27 ( V_69 ) ;
#endif
F_27 ( V_70 ) ;
F_27 ( V_71 ) ;
F_27 ( V_72 ) ;
F_27 ( V_73 ) ;
F_27 ( V_74 ) ;
#ifdef F_30
F_27 ( V_75 ) ;
#endif
#undef F_27
if ( V_61 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_10 , V_52 ? L_11 : L_12 , V_61 ) ;
return V_52 ;
}
static T_1 F_31 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_76 = V_42 -> V_47 ;
switch ( V_76 ) {
#define F_32 ( T_2 ) case MADV_##n: return scnprintf(bf, size, #n)
F_32 ( V_77 ) ;
F_32 ( V_78 ) ;
F_32 ( V_79 ) ;
F_32 ( V_80 ) ;
F_32 ( V_81 ) ;
F_32 ( REMOVE ) ;
F_32 ( V_82 ) ;
F_32 ( V_83 ) ;
F_32 ( V_84 ) ;
#ifdef F_33
F_32 ( V_85 ) ;
#endif
F_32 ( V_86 ) ;
F_32 ( V_87 ) ;
#ifdef F_34
F_32 ( V_88 ) ;
#endif
#ifdef F_35
F_32 ( V_89 ) ;
#endif
#ifdef F_36
F_32 ( V_90 ) ;
#endif
#ifdef F_37
F_32 ( V_91 ) ;
#endif
#undef V_92
default: break;
}
return F_17 ( V_39 , V_6 , L_6 , V_76 ) ;
}
static T_1 F_38 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_93 = V_42 -> V_47 ;
if ( V_93 == 0 )
return F_17 ( V_39 , V_6 , L_9 ) ;
#define F_39 ( T_3 ) \
if ((op & LOCK_##cmd) == LOCK_##cmd) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #cmd); \
op &= ~LOCK_##cmd; \
}
F_39 ( V_94 ) ;
F_39 ( V_95 ) ;
F_39 ( V_96 ) ;
F_39 ( V_97 ) ;
F_39 ( V_98 ) ;
F_39 ( V_99 ) ;
F_39 ( V_56 ) ;
F_39 ( V_57 ) ;
#undef V_100
if ( V_93 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_10 , V_52 ? L_11 : L_12 , V_93 ) ;
return V_52 ;
}
static T_1 F_40 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
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
#define F_41 ( T_2 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_41 ( V_108 ) ; V_42 -> V_109 |= V_106 | V_105 ; break;
F_41 ( V_110 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_41 ( V_111 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_41 ( V_112 ) ; V_42 -> V_109 |= V_106 | V_104 ; break;
F_41 ( V_113 ) ; V_42 -> V_109 |= V_104 ; break;
F_41 ( V_114 ) ; V_42 -> V_109 |= V_104 ; break;
F_41 ( V_115 ) ; break;
F_41 ( V_116 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_41 ( V_117 ) ; V_42 -> V_109 |= V_106 | V_105 | V_104 ; break;
F_41 ( V_118 ) ; V_42 -> V_109 |= V_106 | V_105 ; break;
F_41 ( V_119 ) ; V_42 -> V_109 |= V_105 ; break;
F_41 ( V_120 ) ; V_42 -> V_109 |= V_105 ; break;
F_41 ( V_121 ) ; break;
default: V_52 = F_17 ( V_39 , V_6 , L_6 , T_3 ) ; break;
}
if ( V_93 & V_122 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_13 ) ;
if ( V_93 & V_123 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_14 ) ;
return V_52 ;
}
static T_1 F_42 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 ;
int type = V_42 -> V_47 ,
V_61 = type & ~ V_124 ;
type &= V_124 ;
switch ( type ) {
#define F_43 ( T_2 ) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
F_43 ( V_125 ) ;
F_43 ( V_126 ) ;
F_43 ( V_127 ) ;
F_43 ( V_128 ) ;
F_43 ( V_129 ) ;
F_43 ( V_130 ) ;
F_43 ( V_131 ) ;
#undef F_43
default:
V_52 = F_17 ( V_39 , V_6 , L_6 , type ) ;
}
#define F_44 ( T_2 ) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
F_44 ( V_132 ) ;
F_44 ( V_71 ) ;
#undef F_44
if ( V_61 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_15 , V_61 ) ;
return V_52 ;
}
static T_1 F_45 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_17 ( V_39 , V_6 , L_9 ) ;
#define F_46 ( T_2 ) \
if (flags & MSG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MSG_##n; \
}
F_46 ( V_133 ) ;
F_46 ( V_134 ) ;
F_46 ( V_135 ) ;
F_46 ( V_136 ) ;
F_46 ( V_137 ) ;
F_46 ( V_138 ) ;
F_46 ( V_139 ) ;
F_46 ( V_140 ) ;
F_46 ( V_141 ) ;
F_46 ( V_142 ) ;
F_46 ( V_143 ) ;
F_46 ( V_144 ) ;
F_46 ( V_145 ) ;
F_46 ( V_146 ) ;
F_46 ( V_147 ) ;
F_46 ( V_148 ) ;
F_46 ( V_149 ) ;
F_46 ( V_150 ) ;
F_46 ( V_151 ) ;
F_46 ( V_152 ) ;
F_46 ( V_153 ) ;
#undef F_46
if ( V_61 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_10 , V_52 ? L_11 : L_12 , V_61 ) ;
return V_52 ;
}
static T_1 F_47 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 = 0 ;
int V_154 = V_42 -> V_47 ;
if ( V_154 == V_155 )
return F_17 ( V_39 , V_6 , L_16 ) ;
#define F_48 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_48 ( V_156 ) ;
F_48 ( V_157 ) ;
F_48 ( V_158 ) ;
#undef F_48
if ( V_154 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_15 , V_154 ) ;
return V_52 ;
}
static T_1 F_49 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( ! ( V_61 & V_159 ) )
V_42 -> V_109 |= 1 << ( V_42 -> V_46 + 1 ) ;
if ( V_61 == 0 )
return F_17 ( V_39 , V_6 , L_17 ) ;
#define F_50 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_50 ( V_160 ) ;
F_50 ( V_161 ) ;
F_50 ( V_132 ) ;
F_50 ( V_162 ) ;
F_50 ( V_163 ) ;
F_50 ( V_164 ) ;
F_50 ( V_165 ) ;
F_50 ( V_166 ) ;
F_50 ( V_167 ) ;
F_50 ( V_168 ) ;
#ifdef F_51
F_50 ( V_71 ) ;
#elif V_169
F_50 ( V_170 ) ;
#endif
#ifdef F_52
F_50 ( V_171 ) ;
#endif
F_50 ( V_172 ) ;
#ifdef F_53
if ( ( V_61 & V_173 ) == V_173 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_18 , V_52 ? L_11 : L_12 , L_19 ) ;
else {
F_50 ( V_174 ) ;
}
#else
F_50 ( V_175 ) ;
#endif
F_50 ( V_139 ) ;
F_50 ( V_176 ) ;
#undef F_50
if ( V_61 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_10 , V_52 ? L_11 : L_12 , V_61 ) ;
return V_52 ;
}
static T_1 F_54 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_17 ( V_39 , V_6 , L_9 ) ;
#define F_50 ( T_2 ) \
if (flags & EFD_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~EFD_##n; \
}
F_50 ( V_177 ) ;
F_50 ( V_132 ) ;
F_50 ( V_71 ) ;
#undef F_50
if ( V_61 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_10 , V_52 ? L_11 : L_12 , V_61 ) ;
return V_52 ;
}
static T_1 F_55 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_50 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_50 ( V_132 ) ;
F_50 ( V_71 ) ;
#undef F_50
if ( V_61 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_10 , V_52 ? L_11 : L_12 , V_61 ) ;
return V_52 ;
}
static T_1 F_56 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
{
int V_178 = V_42 -> V_47 ;
switch ( V_178 ) {
#define F_57 ( T_2 ) case SIG##n: return scnprintf(bf, size, #n)
F_57 ( V_179 ) ;
F_57 ( INT ) ;
F_57 ( V_180 ) ;
F_57 ( V_181 ) ;
F_57 ( V_182 ) ;
F_57 ( V_183 ) ;
F_57 ( V_184 ) ;
F_57 ( V_185 ) ;
F_57 ( V_186 ) ;
F_57 ( V_187 ) ;
F_57 ( V_188 ) ;
F_57 ( V_189 ) ;
F_57 ( V_190 ) ;
F_57 ( V_191 ) ;
F_57 ( V_192 ) ;
F_57 ( V_193 ) ;
F_57 ( V_194 ) ;
F_57 ( V_195 ) ;
F_57 ( V_196 ) ;
F_57 ( V_197 ) ;
F_57 ( V_198 ) ;
F_57 ( V_199 ) ;
F_57 ( V_200 ) ;
F_57 ( V_201 ) ;
F_57 ( V_202 ) ;
F_57 ( V_203 ) ;
F_57 ( V_204 ) ;
F_57 ( V_205 ) ;
F_57 ( V_206 ) ;
F_57 ( V_207 ) ;
F_57 ( V_208 ) ;
default: break;
}
return F_17 ( V_39 , V_6 , L_6 , V_178 ) ;
}
static int F_58 ( const void * V_20 , const void * V_209 )
{
const struct V_210 * V_211 = V_209 ;
return strcmp ( V_20 , V_211 -> V_20 ) ;
}
static struct V_210 * F_59 ( const char * V_20 )
{
const int V_212 = F_60 ( V_213 ) ;
return bsearch ( V_20 , V_213 , V_212 , sizeof( struct V_210 ) , F_58 ) ;
}
static T_1 F_61 ( unsigned long V_214 , V_67 * V_215 )
{
double V_216 = ( double ) V_214 / V_217 ;
T_1 V_52 = fprintf ( V_215 , L_20 ) ;
if ( V_216 >= 1.0 )
V_52 += F_62 ( V_215 , V_218 , L_21 , V_216 ) ;
else if ( V_216 >= 0.01 )
V_52 += F_62 ( V_215 , V_219 , L_21 , V_216 ) ;
else
V_52 += F_62 ( V_215 , V_220 , L_21 , V_216 ) ;
return V_52 + fprintf ( V_215 , L_22 ) ;
}
static struct V_221 * F_63 ( void )
{
struct V_221 * V_222 = F_64 ( sizeof( struct V_221 ) ) ;
if ( V_222 )
V_222 -> V_223 . V_224 = - 1 ;
V_222 -> V_225 = F_65 ( NULL ) ;
return V_222 ;
}
static struct V_221 * F_66 ( struct V_226 * V_226 , V_67 * V_215 )
{
struct V_221 * V_222 ;
if ( V_226 == NULL )
goto V_227;
if ( V_226 -> V_21 == NULL )
V_226 -> V_21 = F_63 () ;
if ( V_226 -> V_21 == NULL )
goto V_227;
V_222 = V_226 -> V_21 ;
++ V_222 -> V_228 ;
return V_222 ;
V_227:
F_62 ( V_215 , V_218 ,
L_23 ) ;
return NULL ;
}
static int F_67 ( struct V_226 * V_226 , int V_50 , const char * V_229 )
{
struct V_221 * V_222 = V_226 -> V_21 ;
if ( V_50 > V_222 -> V_223 . V_224 ) {
char * * V_230 = realloc ( V_222 -> V_223 . V_231 , ( V_50 + 1 ) * sizeof( char * ) ) ;
if ( V_230 == NULL )
return - 1 ;
if ( V_222 -> V_223 . V_224 != - 1 ) {
memset ( V_230 + V_222 -> V_223 . V_224 + 1 , 0 ,
( V_50 - V_222 -> V_223 . V_224 ) * sizeof( char * ) ) ;
} else {
memset ( V_230 , 0 , ( V_50 + 1 ) * sizeof( char * ) ) ;
}
V_222 -> V_223 . V_231 = V_230 ;
V_222 -> V_223 . V_224 = V_50 ;
}
V_222 -> V_223 . V_231 [ V_50 ] = F_68 ( V_229 ) ;
return V_222 -> V_223 . V_231 [ V_50 ] != NULL ? 0 : - 1 ;
}
static int F_69 ( struct V_226 * V_226 , int V_50 )
{
char V_232 [ V_233 ] , V_229 [ V_233 ] ;
struct V_234 V_235 ;
int V_33 ;
if ( V_226 -> V_236 == V_226 -> V_237 ) {
F_17 ( V_232 , sizeof( V_232 ) ,
L_24 , V_226 -> V_236 , V_50 ) ;
} else {
F_17 ( V_232 , sizeof( V_232 ) ,
L_25 , V_226 -> V_236 , V_226 -> V_237 , V_50 ) ;
}
if ( F_70 ( V_232 , & V_235 ) < 0 || V_235 . V_238 + 1 > ( V_239 ) sizeof( V_229 ) )
return - 1 ;
V_33 = F_71 ( V_232 , V_229 , sizeof( V_229 ) ) ;
if ( V_33 < 0 || V_33 > V_235 . V_238 )
return - 1 ;
V_229 [ V_33 ] = '\0' ;
return F_67 ( V_226 , V_50 , V_229 ) ;
}
static const char * F_72 ( struct V_226 * V_226 , int V_50 ,
struct V_240 * V_240 )
{
struct V_221 * V_222 = V_226 -> V_21 ;
if ( V_222 == NULL )
return NULL ;
if ( V_50 < 0 )
return NULL ;
if ( ( V_50 > V_222 -> V_223 . V_224 || V_222 -> V_223 . V_231 [ V_50 ] == NULL ) )
if ( ! V_240 -> V_241 )
return NULL ;
++ V_240 -> V_242 . V_243 ;
if ( F_69 ( V_226 , V_50 ) ) {
return NULL ;
}
return V_222 -> V_223 . V_231 [ V_50 ] ;
}
static T_1 F_21 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_17 ( V_39 , V_6 , L_5 , V_50 ) ;
const char * V_244 = F_72 ( V_42 -> V_226 , V_50 , V_42 -> V_240 ) ;
if ( V_244 )
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 , L_26 , V_244 ) ;
return V_52 ;
}
static T_1 F_73 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_21 ( V_39 , V_6 , V_42 ) ;
struct V_221 * V_222 = V_42 -> V_226 -> V_21 ;
if ( V_222 && V_50 >= 0 && V_50 <= V_222 -> V_223 . V_224 ) {
free ( V_222 -> V_223 . V_231 [ V_50 ] ) ;
V_222 -> V_223 . V_231 [ V_50 ] = NULL ;
}
return V_52 ;
}
static bool F_74 ( struct V_240 * V_240 , double V_214 )
{
return V_214 < ( V_240 -> V_245 * V_217 ) ;
}
static T_1 F_75 ( struct V_240 * V_240 , T_5 V_246 , V_67 * V_215 )
{
double V_247 = ( double ) ( V_246 - V_240 -> V_248 ) / V_217 ;
return fprintf ( V_215 , L_27 , V_247 ) ;
}
static void F_76 ( int V_178 )
{
V_249 = true ;
V_250 = V_178 == V_251 ;
}
static T_1 F_77 ( struct V_240 * V_240 , struct V_226 * V_226 ,
T_5 V_216 , T_5 V_246 , V_67 * V_215 )
{
T_1 V_52 = F_75 ( V_240 , V_246 , V_215 ) ;
V_52 += F_61 ( V_216 , V_215 ) ;
if ( V_240 -> V_252 ) {
if ( V_240 -> V_253 )
V_52 += fprintf ( V_215 , L_28 , F_78 ( V_226 ) ) ;
V_52 += fprintf ( V_215 , L_29 , V_226 -> V_237 ) ;
}
return V_52 ;
}
static int F_79 ( struct V_240 * V_240 , struct V_254 * V_254 ,
union V_255 * V_256 , struct V_14 * V_15 )
{
int V_33 = 0 ;
switch ( V_256 -> V_257 . type ) {
case V_258 :
F_62 ( V_240 -> V_259 , V_218 ,
L_30 V_260 L_31 , V_256 -> V_261 . V_261 ) ;
V_33 = F_80 ( V_254 , V_256 , V_15 ) ;
default:
V_33 = F_81 ( V_254 , V_256 , V_15 ) ;
break;
}
return V_33 ;
}
static int F_82 ( struct V_262 * V_263 ,
union V_255 * V_256 ,
struct V_14 * V_15 ,
struct V_254 * V_254 )
{
struct V_240 * V_240 = F_83 ( V_263 , struct V_240 , V_263 ) ;
return F_79 ( V_240 , V_254 , V_256 , V_15 ) ;
}
static int F_84 ( struct V_240 * V_240 , struct V_29 * V_30 )
{
int V_264 = F_85 () ;
if ( V_264 )
return V_264 ;
V_240 -> V_265 = F_86 () ;
if ( V_240 -> V_265 == NULL )
return - V_26 ;
V_264 = F_87 ( V_240 -> V_265 , & V_240 -> V_263 , & V_240 -> V_266 . V_267 ,
V_30 -> V_268 , F_82 , false ) ;
if ( V_264 )
F_88 () ;
return V_264 ;
}
static int F_89 ( struct V_269 * V_270 )
{
struct V_3 * V_2 ;
int V_46 = 0 ;
V_270 -> V_271 = calloc ( V_270 -> V_272 -> V_273 . V_274 - 1 , sizeof( void * ) ) ;
if ( V_270 -> V_271 == NULL )
return - 1 ;
if ( V_270 -> V_211 )
V_270 -> V_275 = V_270 -> V_211 -> V_275 ;
for ( V_2 = V_270 -> V_272 -> V_273 . V_276 -> V_277 ; V_2 ; V_2 = V_2 -> V_277 ) {
if ( V_270 -> V_211 && V_270 -> V_211 -> V_271 [ V_46 ] )
V_270 -> V_271 [ V_46 ] = V_270 -> V_211 -> V_271 [ V_46 ] ;
else if ( V_2 -> V_61 & V_278 )
V_270 -> V_271 [ V_46 ] = F_22 ;
++ V_46 ;
}
return 0 ;
}
static int F_90 ( struct V_240 * V_240 , int V_24 )
{
char V_279 [ 128 ] ;
struct V_269 * V_270 ;
const char * V_20 = F_91 ( V_24 , V_240 -> V_280 . V_254 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_240 -> V_281 . V_224 ) {
struct V_269 * V_282 = realloc ( V_240 -> V_281 . V_231 , ( V_24 + 1 ) * sizeof( * V_270 ) ) ;
if ( V_282 == NULL )
return - 1 ;
if ( V_240 -> V_281 . V_224 != - 1 ) {
memset ( V_282 + V_240 -> V_281 . V_224 + 1 , 0 ,
( V_24 - V_240 -> V_281 . V_224 ) * sizeof( * V_270 ) ) ;
} else {
memset ( V_282 , 0 , ( V_24 + 1 ) * sizeof( * V_270 ) ) ;
}
V_240 -> V_281 . V_231 = V_282 ;
V_240 -> V_281 . V_224 = V_24 ;
}
V_270 = V_240 -> V_281 . V_231 + V_24 ;
V_270 -> V_20 = V_20 ;
if ( V_240 -> V_283 ) {
bool V_284 = F_92 ( V_240 -> V_283 , V_20 ) != NULL ;
if ( ! ( V_284 ^ V_240 -> V_285 ) ) {
V_270 -> V_286 = true ;
return 0 ;
}
}
V_270 -> V_211 = F_59 ( V_270 -> V_20 ) ;
snprintf ( V_279 , sizeof( V_279 ) , L_32 , V_270 -> V_20 ) ;
V_270 -> V_272 = F_93 ( L_33 , V_279 ) ;
if ( V_270 -> V_272 == NULL && V_270 -> V_211 && V_270 -> V_211 -> V_287 ) {
snprintf ( V_279 , sizeof( V_279 ) , L_32 , V_270 -> V_211 -> V_287 ) ;
V_270 -> V_272 = F_93 ( L_33 , V_279 ) ;
}
if ( V_270 -> V_272 == NULL )
return - 1 ;
return F_89 ( V_270 ) ;
}
static T_1 F_94 ( struct V_269 * V_270 , char * V_39 , T_1 V_6 ,
unsigned long * args , struct V_240 * V_240 ,
struct V_226 * V_226 )
{
T_1 V_52 = 0 ;
if ( V_270 -> V_272 != NULL ) {
struct V_3 * V_2 ;
T_6 V_288 = 1 ;
struct V_41 V_42 = {
. V_46 = 0 ,
. V_109 = 0 ,
. V_240 = V_240 ,
. V_226 = V_226 ,
} ;
for ( V_2 = V_270 -> V_272 -> V_273 . V_276 -> V_277 ; V_2 ;
V_2 = V_2 -> V_277 , ++ V_42 . V_46 , V_288 <<= 1 ) {
if ( V_42 . V_109 & V_288 )
continue;
if ( args [ V_42 . V_46 ] == 0 &&
! ( V_270 -> V_271 &&
V_270 -> V_271 [ V_42 . V_46 ] == V_289 &&
V_270 -> V_275 [ V_42 . V_46 ] ) )
continue;
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 ,
L_34 , V_52 ? L_35 : L_12 , V_2 -> V_20 ) ;
if ( V_270 -> V_271 && V_270 -> V_271 [ V_42 . V_46 ] ) {
V_42 . V_47 = args [ V_42 . V_46 ] ;
if ( V_270 -> V_275 )
V_42 . V_45 = V_270 -> V_275 [ V_42 . V_46 ] ;
V_52 += V_270 -> V_271 [ V_42 . V_46 ] ( V_39 + V_52 ,
V_6 - V_52 , & V_42 ) ;
} else {
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 ,
L_36 , args [ V_42 . V_46 ] ) ;
}
}
} else {
int V_290 = 0 ;
while ( V_290 < 6 ) {
V_52 += F_17 ( V_39 + V_52 , V_6 - V_52 ,
L_37 ,
V_52 ? L_35 : L_12 , V_290 , args [ V_290 ] ) ;
++ V_290 ;
}
}
return V_52 ;
}
static struct V_269 * F_95 ( struct V_240 * V_240 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_291 > 1 ) {
static T_5 T_2 ;
fprintf ( V_240 -> V_259 , L_38 V_260 L_39 ,
V_24 , F_96 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_240 -> V_281 . V_224 || V_240 -> V_281 . V_231 [ V_24 ] . V_20 == NULL ) &&
F_90 ( V_240 , V_24 ) )
goto V_292;
if ( ( V_24 > V_240 -> V_281 . V_224 || V_240 -> V_281 . V_231 [ V_24 ] . V_20 == NULL ) )
goto V_292;
return & V_240 -> V_281 . V_231 [ V_24 ] ;
V_292:
if ( V_291 ) {
fprintf ( V_240 -> V_259 , L_40 , V_24 ) ;
if ( V_24 <= V_240 -> V_281 . V_224 && V_240 -> V_281 . V_231 [ V_24 ] . V_20 != NULL )
fprintf ( V_240 -> V_259 , L_41 , V_240 -> V_281 . V_231 [ V_24 ] . V_20 ) ;
fputs ( L_42 , V_240 -> V_259 ) ;
}
return NULL ;
}
static void F_97 ( struct V_221 * V_222 ,
int V_24 , struct V_14 * V_15 )
{
struct V_293 * V_294 ;
struct V_242 * V_242 ;
T_5 V_216 = 0 ;
V_294 = F_98 ( V_222 -> V_225 , V_24 ) ;
if ( V_294 == NULL )
return;
V_242 = V_294 -> V_21 ;
if ( V_242 == NULL ) {
V_242 = malloc ( sizeof( struct V_242 ) ) ;
if ( V_242 == NULL )
return;
F_99 ( V_242 ) ;
V_294 -> V_21 = V_242 ;
}
if ( V_222 -> V_295 && V_15 -> time > V_222 -> V_295 )
V_216 = V_15 -> time - V_222 -> V_295 ;
F_100 ( V_242 , V_216 ) ;
}
static int F_101 ( struct V_240 * V_240 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
char * V_296 ;
void * args ;
T_1 V_52 = 0 ;
struct V_226 * V_226 ;
int V_24 = F_102 ( V_19 , V_24 , V_15 ) ;
struct V_269 * V_270 = F_95 ( V_240 , V_19 , V_24 ) ;
struct V_221 * V_222 ;
if ( V_270 == NULL )
return - 1 ;
if ( V_270 -> V_286 )
return 0 ;
V_226 = F_103 ( V_240 -> V_265 , V_15 -> V_297 , V_15 -> V_237 ) ;
V_222 = F_66 ( V_226 , V_240 -> V_259 ) ;
if ( V_222 == NULL )
return - 1 ;
args = F_104 ( V_19 , args , V_15 ) ;
V_222 = V_226 -> V_21 ;
if ( V_222 -> V_298 == NULL ) {
V_222 -> V_298 = malloc ( 1024 ) ;
if ( ! V_222 -> V_298 )
return - 1 ;
}
V_222 -> V_295 = V_15 -> time ;
V_296 = V_222 -> V_298 ;
V_52 += F_17 ( V_296 + V_52 , 1024 - V_52 , L_43 , V_270 -> V_20 ) ;
V_52 += F_94 ( V_270 , V_296 + V_52 , 1024 - V_52 ,
args , V_240 , V_226 ) ;
if ( ! strcmp ( V_270 -> V_20 , L_44 ) || ! strcmp ( V_270 -> V_20 , L_45 ) ) {
if ( ! V_240 -> V_245 && ! V_240 -> V_299 ) {
F_77 ( V_240 , V_226 , 1 , V_15 -> time , V_240 -> V_259 ) ;
fprintf ( V_240 -> V_259 , L_46 , V_222 -> V_298 ) ;
}
} else
V_222 -> V_300 = true ;
return 0 ;
}
static int F_105 ( struct V_240 * V_240 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
int V_33 ;
T_5 V_216 = 0 ;
struct V_226 * V_226 ;
int V_24 = F_102 ( V_19 , V_24 , V_15 ) ;
struct V_269 * V_270 = F_95 ( V_240 , V_19 , V_24 ) ;
struct V_221 * V_222 ;
if ( V_270 == NULL )
return - 1 ;
if ( V_270 -> V_286 )
return 0 ;
V_226 = F_103 ( V_240 -> V_265 , V_15 -> V_297 , V_15 -> V_237 ) ;
V_222 = F_66 ( V_226 , V_240 -> V_259 ) ;
if ( V_222 == NULL )
return - 1 ;
if ( V_240 -> V_301 )
F_97 ( V_222 , V_24 , V_15 ) ;
V_33 = F_102 ( V_19 , V_33 , V_15 ) ;
if ( V_24 == V_240 -> V_280 . V_302 && V_33 >= 0 && V_240 -> V_303 ) {
F_67 ( V_226 , V_33 , V_240 -> V_303 ) ;
V_240 -> V_303 = NULL ;
++ V_240 -> V_242 . V_304 ;
}
V_222 = V_226 -> V_21 ;
V_222 -> V_305 = V_15 -> time ;
if ( V_222 -> V_295 ) {
V_216 = V_15 -> time - V_222 -> V_295 ;
if ( F_74 ( V_240 , V_216 ) )
goto V_36;
} else if ( V_240 -> V_245 )
goto V_36;
if ( V_240 -> V_299 )
goto V_36;
F_77 ( V_240 , V_226 , V_216 , V_15 -> time , V_240 -> V_259 ) ;
if ( V_222 -> V_300 ) {
fprintf ( V_240 -> V_259 , L_47 , V_222 -> V_298 ) ;
} else {
fprintf ( V_240 -> V_259 , L_48 ) ;
F_62 ( V_240 -> V_259 , V_219 , L_49 ) ;
fprintf ( V_240 -> V_259 , L_50 , V_270 -> V_20 ) ;
}
if ( V_270 -> V_211 == NULL ) {
V_306:
fprintf ( V_240 -> V_259 , L_51 , V_33 ) ;
} else if ( V_33 < 0 && V_270 -> V_211 -> V_307 ) {
char V_39 [ 256 ] ;
const char * V_308 = F_106 ( - V_33 , V_39 , sizeof( V_39 ) ) ,
* V_309 = F_107 ( - V_33 ) ;
fprintf ( V_240 -> V_259 , L_52 , V_309 , V_308 ) ;
} else if ( V_33 == 0 && V_270 -> V_211 -> V_310 )
fprintf ( V_240 -> V_259 , L_53 ) ;
else if ( V_270 -> V_211 -> V_311 )
fprintf ( V_240 -> V_259 , L_54 , V_33 ) ;
else
goto V_306;
fputc ( '\n' , V_240 -> V_259 ) ;
V_36:
V_222 -> V_300 = false ;
return 0 ;
}
static int F_108 ( struct V_240 * V_240 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
V_240 -> V_303 = F_109 ( V_19 , V_15 , L_55 ) ;
return 0 ;
}
static int F_110 ( struct V_240 * V_240 , struct V_18 * V_19 ,
struct V_14 * V_15 )
{
T_5 V_312 = F_111 ( V_19 , V_15 , L_56 ) ;
double V_313 = ( double ) V_312 / V_217 ;
struct V_226 * V_226 = F_103 ( V_240 -> V_265 ,
V_15 -> V_297 ,
V_15 -> V_237 ) ;
struct V_221 * V_222 = F_66 ( V_226 , V_240 -> V_259 ) ;
if ( V_222 == NULL )
goto V_314;
V_222 -> V_313 += V_313 ;
V_240 -> V_313 += V_313 ;
return 0 ;
V_314:
fprintf ( V_240 -> V_259 , L_57 V_260 L_58 V_260 L_59 ,
V_19 -> V_20 ,
F_112 ( V_19 , V_15 , L_60 ) ,
( V_315 ) F_111 ( V_19 , V_15 , L_61 ) ,
V_312 ,
F_111 ( V_19 , V_15 , L_62 ) ) ;
return 0 ;
}
static bool F_113 ( struct V_240 * V_240 , struct V_14 * V_15 )
{
if ( ( V_240 -> V_316 && F_114 ( V_240 -> V_316 , V_15 -> V_297 ) ) ||
( V_240 -> V_317 && F_114 ( V_240 -> V_317 , V_15 -> V_237 ) ) )
return false ;
if ( V_240 -> V_316 || V_240 -> V_317 )
return true ;
return false ;
}
static int F_115 ( struct V_262 * V_263 ,
union V_255 * V_256 V_318 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_254 * V_254 V_318 )
{
struct V_240 * V_240 = F_83 ( V_263 , struct V_240 , V_263 ) ;
int V_264 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
if ( F_113 ( V_240 , V_15 ) )
return 0 ;
if ( ! V_240 -> V_319 && V_240 -> V_248 == 0 )
V_240 -> V_248 = V_15 -> time ;
if ( V_22 )
V_22 ( V_240 , V_19 , V_15 ) ;
return V_264 ;
}
static int F_116 ( struct V_240 * V_240 )
{
if ( V_240 -> V_266 . V_267 . V_297 ) {
V_240 -> V_316 = F_65 ( V_240 -> V_266 . V_267 . V_297 ) ;
if ( V_240 -> V_316 == NULL ) {
F_117 ( L_63 ) ;
return - V_320 ;
}
}
if ( V_240 -> V_266 . V_267 . V_237 ) {
V_240 -> V_317 = F_65 ( V_240 -> V_266 . V_267 . V_237 ) ;
if ( V_240 -> V_317 == NULL ) {
F_117 ( L_64 ) ;
return - V_320 ;
}
}
return 0 ;
}
static int F_118 ( int V_321 , const char * * V_322 )
{
unsigned int V_323 , V_290 , V_324 ;
const char * * V_325 ;
const char * const V_326 [] = {
L_65 ,
L_66 ,
L_67 , L_68 ,
L_69 , L_70 ,
L_71 , L_72 ,
} ;
V_323 = F_60 ( V_326 ) + V_321 ;
V_325 = calloc ( V_323 + 1 , sizeof( char * ) ) ;
if ( V_325 == NULL )
return - V_26 ;
for ( V_290 = 0 ; V_290 < F_60 ( V_326 ) ; V_290 ++ )
V_325 [ V_290 ] = V_326 [ V_290 ] ;
for ( V_324 = 0 ; V_324 < ( unsigned int ) V_321 ; V_324 ++ , V_290 ++ )
V_325 [ V_290 ] = V_322 [ V_324 ] ;
return F_119 ( V_290 , V_325 , NULL ) ;
}
static void F_120 ( struct V_29 * V_30 )
{
struct V_18 * V_19 = F_12 ( L_73 , L_74 ) ;
if ( V_19 == NULL )
return;
if ( F_5 ( V_19 , L_55 ) == NULL ) {
F_8 ( V_19 ) ;
return;
}
V_19 -> V_22 = F_108 ;
F_15 ( V_30 , V_19 ) ;
}
static int F_121 ( struct V_240 * V_240 , int V_321 , const char * * V_322 )
{
struct V_29 * V_30 = F_122 () ;
struct V_18 * V_19 ;
int V_264 = - 1 , V_290 ;
unsigned long V_327 ;
const bool V_328 = V_321 > 0 ;
V_240 -> V_241 = true ;
if ( V_30 == NULL ) {
fprintf ( V_240 -> V_259 , L_75 ) ;
goto V_36;
}
if ( F_13 ( V_30 , F_101 , F_105 ) )
goto V_329;
F_120 ( V_30 ) ;
if ( V_240 -> V_330 &&
F_123 ( V_30 , L_76 , L_77 ,
F_110 ) )
goto V_329;
V_264 = F_124 ( V_30 , & V_240 -> V_266 . V_267 ) ;
if ( V_264 < 0 ) {
fprintf ( V_240 -> V_259 , L_78 ) ;
goto V_331;
}
V_264 = F_84 ( V_240 , V_30 ) ;
if ( V_264 < 0 ) {
fprintf ( V_240 -> V_259 , L_79 ) ;
goto V_332;
}
F_125 ( V_30 , & V_240 -> V_266 ) ;
signal ( V_333 , F_76 ) ;
signal ( V_251 , F_76 ) ;
if ( V_328 ) {
V_264 = F_126 ( V_30 , & V_240 -> V_266 . V_267 ,
V_322 , false , false ) ;
if ( V_264 < 0 ) {
fprintf ( V_240 -> V_259 , L_80 ) ;
goto V_332;
}
}
V_264 = F_127 ( V_30 ) ;
if ( V_264 < 0 )
goto V_334;
V_264 = F_128 ( V_30 , V_335 , false ) ;
if ( V_264 < 0 ) {
fprintf ( V_240 -> V_259 , L_81 , strerror ( V_336 ) ) ;
goto V_337;
}
F_129 ( V_30 ) ;
if ( V_328 )
F_130 ( V_30 ) ;
V_240 -> V_252 = V_30 -> V_268 -> V_338 [ 0 ] == - 1 || V_30 -> V_268 -> V_339 > 1 ;
V_340:
V_327 = V_240 -> V_228 ;
for ( V_290 = 0 ; V_290 < V_30 -> V_341 ; V_290 ++ ) {
union V_255 * V_256 ;
while ( ( V_256 = F_131 ( V_30 , V_290 ) ) != NULL ) {
const T_8 type = V_256 -> V_257 . type ;
T_7 V_22 ;
struct V_14 V_15 ;
++ V_240 -> V_228 ;
V_264 = F_132 ( V_30 , V_256 , & V_15 ) ;
if ( V_264 ) {
fprintf ( V_240 -> V_259 , L_82 , V_264 ) ;
goto V_342;
}
if ( ! V_240 -> V_319 && V_240 -> V_248 == 0 )
V_240 -> V_248 = V_15 . time ;
if ( type != V_343 ) {
F_79 ( V_240 , V_240 -> V_265 , V_256 , & V_15 ) ;
continue;
}
V_19 = F_133 ( V_30 , V_15 . V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_240 -> V_259 , L_83 V_260 L_84 , V_15 . V_24 ) ;
goto V_342;
}
if ( V_15 . V_16 == NULL ) {
fprintf ( V_240 -> V_259 , L_85 ,
F_96 ( V_19 ) , V_15 . V_237 ,
V_15 . V_344 , V_15 . V_345 ) ;
goto V_342;
}
V_22 = V_19 -> V_22 ;
V_22 ( V_240 , V_19 , & V_15 ) ;
V_342:
F_134 ( V_30 , V_290 ) ;
if ( V_250 )
goto V_346;
}
}
if ( V_240 -> V_228 == V_327 ) {
int V_310 = V_249 ? 100 : - 1 ;
if ( F_135 ( V_30 -> V_347 , V_30 -> V_348 , V_310 ) > 0 )
goto V_340;
} else {
goto V_340;
}
V_346:
F_136 ( V_30 ) ;
if ( ! V_264 ) {
if ( V_240 -> V_301 )
F_137 ( V_240 , V_240 -> V_259 ) ;
if ( V_240 -> V_349 ) {
fprintf ( V_240 -> V_259 , L_86
L_87 V_260 L_88
L_89 V_260 L_88 ,
V_240 -> V_242 . V_304 ,
V_240 -> V_242 . V_243 ) ;
}
}
F_138 ( V_30 ) ;
V_337:
F_139 ( V_30 ) ;
V_332:
F_140 ( V_30 ) ;
V_331:
F_141 ( V_30 ) ;
V_36:
V_240 -> V_241 = false ;
return V_264 ;
{
char V_350 [ V_351 ] ;
V_329:
F_142 ( V_30 , V_336 , V_350 , sizeof( V_350 ) ) ;
goto V_352;
V_334:
F_143 ( V_30 , V_336 , V_350 , sizeof( V_350 ) ) ;
V_352:
fprintf ( V_240 -> V_259 , L_90 , V_350 ) ;
goto V_331;
}
}
static int F_144 ( struct V_240 * V_240 )
{
const struct V_353 V_354 [] = {
{ L_91 , F_108 , } ,
} ;
struct V_355 V_356 = {
. V_244 = V_357 ,
. V_154 = V_358 ,
} ;
struct V_359 * V_360 ;
struct V_18 * V_19 ;
int V_264 = - 1 ;
V_240 -> V_263 . V_15 = F_115 ;
V_240 -> V_263 . V_361 = V_362 ;
V_240 -> V_263 . V_363 = V_364 ;
V_240 -> V_263 . V_365 = V_366 ;
V_240 -> V_263 . exit = V_367 ;
V_240 -> V_263 . V_368 = V_369 ;
V_240 -> V_263 . V_370 = V_371 ;
V_240 -> V_263 . V_372 = V_373 ;
V_240 -> V_263 . V_374 = V_375 ;
V_240 -> V_263 . V_376 = true ;
V_240 -> V_263 . V_377 = true ;
V_240 -> V_252 = true ;
if ( F_85 () < 0 )
return - 1 ;
V_360 = F_145 ( & V_356 , false , & V_240 -> V_263 ) ;
if ( V_360 == NULL )
return - V_26 ;
V_240 -> V_265 = & V_360 -> V_378 . V_265 ;
V_264 = F_146 ( V_360 , V_354 ) ;
if ( V_264 )
goto V_36;
V_19 = F_147 ( V_360 -> V_30 ,
L_92 ) ;
if ( V_19 == NULL ) {
F_117 ( L_93 ) ;
goto V_36;
}
if ( F_9 ( V_19 , F_101 ) < 0 ||
F_14 ( V_19 , args ) ) {
F_117 ( L_94 ) ;
goto V_36;
}
V_19 = F_147 ( V_360 -> V_30 ,
L_95 ) ;
if ( V_19 == NULL ) {
F_117 ( L_96 ) ;
goto V_36;
}
if ( F_9 ( V_19 , F_105 ) < 0 ||
F_10 ( V_19 , V_33 ) ) {
F_117 ( L_97 ) ;
goto V_36;
}
V_264 = F_116 ( V_240 ) ;
if ( V_264 != 0 )
goto V_36;
F_148 () ;
V_264 = F_149 ( V_360 , & V_240 -> V_263 ) ;
if ( V_264 )
F_117 ( L_98 , V_264 ) ;
else if ( V_240 -> V_301 )
F_137 ( V_240 , V_240 -> V_259 ) ;
V_36:
F_150 ( V_360 ) ;
return V_264 ;
}
static T_1 F_151 ( V_67 * V_215 )
{
T_1 V_52 ;
V_52 = fprintf ( V_215 , L_99 ) ;
return V_52 ;
}
static T_1 F_152 ( struct V_221 * V_222 ,
struct V_240 * V_240 , V_67 * V_215 )
{
struct V_242 * V_242 ;
T_1 V_52 = 0 ;
struct V_269 * V_270 ;
struct V_293 * V_294 = F_153 ( V_222 -> V_225 ) ;
if ( V_294 == NULL )
return 0 ;
V_52 += fprintf ( V_215 , L_88 ) ;
V_52 += fprintf ( V_215 , L_100 ) ;
V_52 += fprintf ( V_215 , L_101 ) ;
V_52 += fprintf ( V_215 , L_102 ) ;
while ( V_294 ) {
V_242 = V_294 -> V_21 ;
if ( V_242 ) {
double V_379 = ( double ) ( V_242 -> V_379 ) / V_217 ;
double V_224 = ( double ) ( V_242 -> V_224 ) / V_217 ;
double V_380 = F_154 ( V_242 ) ;
double V_381 ;
T_5 T_2 = ( T_5 ) V_242 -> T_2 ;
V_381 = V_380 ? 100.0 * F_155 ( V_242 ) / V_380 : 0.0 ;
V_380 /= V_217 ;
V_270 = & V_240 -> V_281 . V_231 [ V_294 -> V_290 ] ;
V_52 += fprintf ( V_215 , L_103 , V_270 -> V_20 ) ;
V_52 += fprintf ( V_215 , L_104 V_260 L_105 ,
T_2 , V_379 , V_380 ) ;
V_52 += fprintf ( V_215 , L_106 , V_224 , V_381 ) ;
}
V_294 = F_156 ( V_294 ) ;
}
V_52 += fprintf ( V_215 , L_107 ) ;
return V_52 ;
}
static int F_157 ( struct V_226 * V_226 , void * V_21 )
{
struct V_382 * V_383 = V_21 ;
V_67 * V_215 = V_383 -> V_215 ;
T_1 V_52 = V_383 -> V_52 ;
struct V_240 * V_240 = V_383 -> V_240 ;
struct V_221 * V_222 = V_226 -> V_21 ;
const char * V_384 ;
double V_385 ;
if ( V_222 == NULL )
return 0 ;
V_385 = ( double ) V_222 -> V_228 / V_240 -> V_228 * 100.0 ;
V_384 = V_220 ;
if ( V_385 > 50.0 )
V_384 = V_218 ;
else if ( V_385 > 25.0 )
V_384 = V_386 ;
else if ( V_385 > 5.0 )
V_384 = V_219 ;
V_52 += F_62 ( V_215 , V_384 , L_108 , F_78 ( V_226 ) , V_226 -> V_237 ) ;
V_52 += fprintf ( V_215 , L_109 , V_222 -> V_228 ) ;
V_52 += F_62 ( V_215 , V_384 , L_110 , V_385 ) ;
V_52 += fprintf ( V_215 , L_111 , V_222 -> V_313 ) ;
V_52 += F_152 ( V_222 , V_240 , V_215 ) ;
V_383 -> V_52 += V_52 ;
return 0 ;
}
static T_1 F_137 ( struct V_240 * V_240 , V_67 * V_215 )
{
struct V_382 V_383 = {
. V_215 = V_215 ,
. V_240 = V_240
} ;
V_383 . V_52 = F_151 ( V_215 ) ;
F_158 ( V_240 -> V_265 , F_157 , & V_383 ) ;
return V_383 . V_52 ;
}
static int F_159 ( const struct V_387 * V_388 , const char * V_389 ,
int T_9 V_318 )
{
struct V_240 * V_240 = V_388 -> V_390 ;
V_240 -> V_245 = atof ( V_389 ) ;
return 0 ;
}
static int F_160 ( struct V_240 * V_240 , const char * V_391 )
{
struct V_234 V_235 ;
if ( ! V_234 ( V_391 , & V_235 ) && V_235 . V_238 ) {
char V_392 [ V_233 ] ;
F_17 ( V_392 , sizeof( V_392 ) , L_112 , V_391 ) ;
F_161 ( V_392 ) ;
rename ( V_391 , V_392 ) ;
}
V_240 -> V_259 = fopen ( V_391 , L_113 ) ;
return V_240 -> V_259 == NULL ? - V_336 : 0 ;
}
int F_162 ( int V_321 , const char * * V_322 , const char * T_10 V_318 )
{
const char * const V_393 [] = {
L_114 ,
L_115 ,
L_116 ,
L_117 ,
NULL
} ;
struct V_240 V_240 = {
. V_280 = {
. V_254 = F_163 () ,
. V_302 = F_164 ( L_118 , V_240 . V_280 . V_254 ) ,
} ,
. V_281 = {
. V_224 = - 1 ,
} ,
. V_266 = {
. V_267 = {
. V_394 = V_335 ,
. V_395 = true ,
} ,
. V_396 = V_335 ,
. V_397 = V_398 ,
. V_399 = true ,
. V_400 = 1024 ,
} ,
. V_259 = stdout ,
. V_253 = true ,
} ;
const char * V_401 = NULL ;
const char * V_402 = NULL ;
const struct V_387 V_403 [] = {
F_165 ( 0 , L_60 , & V_240 . V_253 ,
L_119 ) ,
F_165 ( 0 , L_120 , & V_240 . V_349 , L_121 ) ,
F_166 ( 'e' , L_122 , & V_402 , L_122 ,
L_123 ) ,
F_166 ( 'o' , L_124 , & V_401 , L_125 , L_126 ) ,
F_166 ( 'i' , L_127 , & V_357 , L_125 , L_128 ) ,
F_166 ( 'p' , L_61 , & V_240 . V_266 . V_267 . V_297 , L_61 ,
L_129 ) ,
F_166 ( 't' , L_130 , & V_240 . V_266 . V_267 . V_237 , L_130 ,
L_131 ) ,
F_165 ( 'a' , L_132 , & V_240 . V_266 . V_267 . V_404 ,
L_133 ) ,
F_166 ( 'C' , L_134 , & V_240 . V_266 . V_267 . V_405 , L_134 ,
L_135 ) ,
F_165 ( 0 , L_136 , & V_240 . V_266 . V_406 ,
L_137 ) ,
F_167 ( 'm' , L_138 , & V_240 . V_266 . V_400 , L_139 ,
L_140 ,
V_407 ) ,
F_166 ( 'u' , L_141 , & V_240 . V_266 . V_267 . V_408 , L_142 ,
L_143 ) ,
F_167 ( 0 , L_144 , & V_240 , L_145 ,
L_146 ,
F_159 ) ,
F_165 ( 0 , L_76 , & V_240 . V_330 , L_147 ) ,
F_168 ( 'v' , L_148 , & V_291 , L_149 ) ,
F_165 ( 'T' , L_150 , & V_240 . V_319 ,
L_151 ) ,
F_165 ( 's' , L_152 , & V_240 . V_299 ,
L_153 ) ,
F_165 ( 'S' , L_154 , & V_240 . V_301 ,
L_155 ) ,
F_169 ()
} ;
int V_264 ;
char V_39 [ V_351 ] ;
if ( ( V_321 > 1 ) && ( strcmp ( V_322 [ 1 ] , L_65 ) == 0 ) )
return F_118 ( V_321 - 2 , & V_322 [ 2 ] ) ;
V_321 = F_170 ( V_321 , V_322 , V_403 , V_393 , 0 ) ;
if ( V_240 . V_299 )
V_240 . V_301 = V_240 . V_299 ;
if ( V_401 != NULL ) {
V_264 = F_160 ( & V_240 , V_401 ) ;
if ( V_264 < 0 ) {
perror ( L_156 ) ;
goto V_36;
}
}
if ( V_402 != NULL ) {
const char * V_409 = V_402 ;
V_240 . V_285 = * V_409 == '!' ;
if ( V_240 . V_285 )
++ V_409 ;
V_240 . V_283 = F_171 ( true , V_409 ) ;
if ( V_240 . V_283 == NULL ) {
fputs ( L_157 ,
V_240 . V_259 ) ;
V_264 = - V_26 ;
goto V_410;
}
}
V_264 = F_172 ( & V_240 . V_266 . V_267 ) ;
if ( V_264 ) {
F_173 ( & V_240 . V_266 . V_267 , V_264 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_240 . V_259 , L_4 , V_39 ) ;
goto V_410;
}
V_264 = F_174 ( & V_240 . V_266 . V_267 ) ;
if ( V_264 ) {
F_173 ( & V_240 . V_266 . V_267 , V_264 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_240 . V_259 , L_4 , V_39 ) ;
goto V_410;
}
if ( ! V_321 && F_175 ( & V_240 . V_266 . V_267 ) )
V_240 . V_266 . V_267 . V_404 = true ;
if ( V_357 )
V_264 = F_144 ( & V_240 ) ;
else
V_264 = F_121 ( & V_240 , V_321 , V_322 ) ;
V_410:
if ( V_401 != NULL )
fclose ( V_240 . V_259 ) ;
V_36:
return V_264 ;
}
