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
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_33 ( T_2 ) \
if (flags & MREMAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MREMAP_##n; \
}
F_33 ( V_76 ) ;
#ifdef F_34
F_33 ( V_68 ) ;
#endif
#undef F_33
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_35 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_77 = V_42 -> V_47 ;
switch ( V_77 ) {
#define F_36 ( T_2 ) case MADV_##n: return scnprintf(bf, size, #n)
F_36 ( V_78 ) ;
F_36 ( V_79 ) ;
F_36 ( V_80 ) ;
F_36 ( V_81 ) ;
F_36 ( V_82 ) ;
F_36 ( REMOVE ) ;
F_36 ( V_83 ) ;
F_36 ( V_84 ) ;
F_36 ( V_85 ) ;
#ifdef F_37
F_36 ( V_86 ) ;
#endif
F_36 ( V_87 ) ;
F_36 ( V_88 ) ;
#ifdef F_38
F_36 ( V_89 ) ;
#endif
#ifdef F_39
F_36 ( V_90 ) ;
#endif
#ifdef F_40
F_36 ( V_91 ) ;
#endif
#ifdef F_41
F_36 ( V_92 ) ;
#endif
#undef V_93
default: break;
}
return F_18 ( V_39 , V_6 , L_7 , V_77 ) ;
}
static T_1 F_42 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_94 = V_42 -> V_47 ;
if ( V_94 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_43 ( T_3 ) \
if ((op & LOCK_##cmd) == LOCK_##cmd) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #cmd); \
op &= ~LOCK_##cmd; \
}
F_43 ( V_95 ) ;
F_43 ( V_96 ) ;
F_43 ( V_97 ) ;
F_43 ( V_98 ) ;
F_43 ( V_99 ) ;
F_43 ( V_100 ) ;
F_43 ( V_56 ) ;
F_43 ( V_57 ) ;
#undef V_101
if ( V_94 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_94 ) ;
return V_52 ;
}
static T_1 F_44 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
{
enum T_4 {
V_102 = ( 1 << 0 ) ,
V_103 = ( 1 << 1 ) ,
V_104 = ( 1 << 2 ) ,
V_105 = ( 1 << 3 ) ,
V_106 = ( 1 << 4 ) ,
V_107 = ( 1 << 5 ) ,
};
int V_94 = V_42 -> V_47 ;
int T_3 = V_94 & V_108 ;
T_1 V_52 = 0 ;
switch ( T_3 ) {
#define F_45 ( T_2 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_45 ( V_109 ) ; V_42 -> V_110 |= V_107 | V_106 ; break;
F_45 ( V_111 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_45 ( V_112 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_45 ( V_113 ) ; V_42 -> V_110 |= V_107 | V_105 ; break;
F_45 ( V_114 ) ; V_42 -> V_110 |= V_105 ; break;
F_45 ( V_115 ) ; V_42 -> V_110 |= V_105 ; break;
F_45 ( V_116 ) ; break;
F_45 ( V_117 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_45 ( V_118 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_45 ( V_119 ) ; V_42 -> V_110 |= V_107 | V_106 ; break;
F_45 ( V_120 ) ; V_42 -> V_110 |= V_106 ; break;
F_45 ( V_121 ) ; V_42 -> V_110 |= V_106 ; break;
F_45 ( V_122 ) ; break;
default: V_52 = F_18 ( V_39 , V_6 , L_7 , T_3 ) ; break;
}
if ( V_94 & V_123 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_14 ) ;
if ( V_94 & V_124 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_15 ) ;
return V_52 ;
}
static T_1 F_46 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 ;
int type = V_42 -> V_47 ,
V_61 = type & ~ V_125 ;
type &= V_125 ;
switch ( type ) {
#define F_47 ( T_2 ) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
F_47 ( V_126 ) ;
F_47 ( V_127 ) ;
F_47 ( V_128 ) ;
F_47 ( V_129 ) ;
F_47 ( V_130 ) ;
F_47 ( V_131 ) ;
F_47 ( V_132 ) ;
#undef F_47
default:
V_52 = F_18 ( V_39 , V_6 , L_7 , type ) ;
}
#define F_48 ( T_2 ) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
F_48 ( V_133 ) ;
F_48 ( V_71 ) ;
#undef F_48
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_16 , V_61 ) ;
return V_52 ;
}
static T_1 F_49 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_50 ( T_2 ) \
if (flags & MSG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MSG_##n; \
}
F_50 ( V_134 ) ;
F_50 ( V_135 ) ;
F_50 ( V_136 ) ;
F_50 ( V_137 ) ;
F_50 ( V_138 ) ;
F_50 ( V_139 ) ;
F_50 ( V_140 ) ;
F_50 ( V_141 ) ;
F_50 ( V_142 ) ;
F_50 ( V_143 ) ;
F_50 ( V_144 ) ;
F_50 ( V_145 ) ;
F_50 ( V_146 ) ;
F_50 ( V_147 ) ;
F_50 ( V_148 ) ;
F_50 ( V_149 ) ;
F_50 ( V_150 ) ;
F_50 ( V_151 ) ;
F_50 ( V_152 ) ;
F_50 ( V_153 ) ;
F_50 ( V_154 ) ;
#undef F_50
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_51 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 = 0 ;
int V_155 = V_42 -> V_47 ;
if ( V_155 == V_156 )
return F_18 ( V_39 , V_6 , L_17 ) ;
#define F_52 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_52 ( V_157 ) ;
F_52 ( V_158 ) ;
F_52 ( V_159 ) ;
#undef F_52
if ( V_155 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_16 , V_155 ) ;
return V_52 ;
}
static T_1 F_53 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( ! ( V_61 & V_160 ) )
V_42 -> V_110 |= 1 << ( V_42 -> V_46 + 1 ) ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_18 ) ;
#define F_54 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_54 ( V_161 ) ;
F_54 ( V_162 ) ;
F_54 ( V_133 ) ;
F_54 ( V_163 ) ;
F_54 ( V_164 ) ;
F_54 ( V_165 ) ;
F_54 ( V_166 ) ;
F_54 ( V_167 ) ;
F_54 ( V_168 ) ;
F_54 ( V_169 ) ;
#ifdef F_55
F_54 ( V_71 ) ;
#elif V_170
F_54 ( V_171 ) ;
#endif
#ifdef F_56
F_54 ( V_172 ) ;
#endif
F_54 ( V_173 ) ;
#ifdef F_57
if ( ( V_61 & V_174 ) == V_174 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_19 , V_52 ? L_12 : L_13 , L_20 ) ;
else {
F_54 ( V_175 ) ;
}
#else
F_54 ( V_176 ) ;
#endif
F_54 ( V_140 ) ;
F_54 ( V_177 ) ;
#undef F_54
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_58 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_54 ( T_2 ) \
if (flags & EFD_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~EFD_##n; \
}
F_54 ( V_178 ) ;
F_54 ( V_133 ) ;
F_54 ( V_71 ) ;
#undef F_54
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_59 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_54 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_54 ( V_133 ) ;
F_54 ( V_71 ) ;
#undef F_54
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_60 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
{
int V_179 = V_42 -> V_47 ;
switch ( V_179 ) {
#define F_61 ( T_2 ) case SIG##n: return scnprintf(bf, size, #n)
F_61 ( V_180 ) ;
F_61 ( INT ) ;
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
F_61 ( V_203 ) ;
F_61 ( V_204 ) ;
F_61 ( V_205 ) ;
F_61 ( V_206 ) ;
F_61 ( V_207 ) ;
F_61 ( V_208 ) ;
#ifdef F_62
F_61 ( V_209 ) ;
#endif
#ifdef F_63
F_61 ( V_210 ) ;
#endif
#ifdef F_64
F_61 ( V_211 ) ;
#endif
default: break;
}
return F_18 ( V_39 , V_6 , L_7 , V_179 ) ;
}
static int F_65 ( const void * V_20 , const void * V_212 )
{
const struct V_213 * V_214 = V_212 ;
return strcmp ( V_20 , V_214 -> V_20 ) ;
}
static struct V_213 * F_66 ( const char * V_20 )
{
const int V_215 = F_67 ( V_216 ) ;
return bsearch ( V_20 , V_216 , V_215 , sizeof( struct V_213 ) , F_65 ) ;
}
static T_1 F_68 ( unsigned long V_217 , V_67 * V_218 )
{
double V_219 = ( double ) V_217 / V_220 ;
T_1 V_52 = fprintf ( V_218 , L_21 ) ;
if ( V_219 >= 1.0 )
V_52 += F_69 ( V_218 , V_221 , L_22 , V_219 ) ;
else if ( V_219 >= 0.01 )
V_52 += F_69 ( V_218 , V_222 , L_22 , V_219 ) ;
else
V_52 += F_69 ( V_218 , V_223 , L_22 , V_219 ) ;
return V_52 + fprintf ( V_218 , L_23 ) ;
}
static struct V_224 * F_70 ( void )
{
struct V_224 * V_225 = F_71 ( sizeof( struct V_224 ) ) ;
if ( V_225 )
V_225 -> V_226 . V_227 = - 1 ;
V_225 -> V_228 = F_72 ( NULL ) ;
return V_225 ;
}
static struct V_224 * F_73 ( struct V_229 * V_229 , V_67 * V_218 )
{
struct V_224 * V_225 ;
if ( V_229 == NULL )
goto V_230;
if ( F_74 ( V_229 ) == NULL )
F_75 ( V_229 , F_70 () ) ;
if ( F_74 ( V_229 ) == NULL )
goto V_230;
V_225 = F_74 ( V_229 ) ;
++ V_225 -> V_231 ;
return V_225 ;
V_230:
F_69 ( V_218 , V_221 ,
L_24 ) ;
return NULL ;
}
static int F_76 ( struct V_229 * V_229 , int V_50 , const char * V_232 )
{
struct V_224 * V_225 = F_74 ( V_229 ) ;
if ( V_50 > V_225 -> V_226 . V_227 ) {
char * * V_233 = realloc ( V_225 -> V_226 . V_234 , ( V_50 + 1 ) * sizeof( char * ) ) ;
if ( V_233 == NULL )
return - 1 ;
if ( V_225 -> V_226 . V_227 != - 1 ) {
memset ( V_233 + V_225 -> V_226 . V_227 + 1 , 0 ,
( V_50 - V_225 -> V_226 . V_227 ) * sizeof( char * ) ) ;
} else {
memset ( V_233 , 0 , ( V_50 + 1 ) * sizeof( char * ) ) ;
}
V_225 -> V_226 . V_234 = V_233 ;
V_225 -> V_226 . V_227 = V_50 ;
}
V_225 -> V_226 . V_234 [ V_50 ] = F_77 ( V_232 ) ;
return V_225 -> V_226 . V_234 [ V_50 ] != NULL ? 0 : - 1 ;
}
static int F_78 ( struct V_229 * V_229 , int V_50 )
{
char V_235 [ V_236 ] , V_232 [ V_236 ] ;
struct V_237 V_238 ;
int V_33 ;
if ( V_229 -> V_239 == V_229 -> V_240 ) {
F_18 ( V_235 , sizeof( V_235 ) ,
L_25 , V_229 -> V_239 , V_50 ) ;
} else {
F_18 ( V_235 , sizeof( V_235 ) ,
L_26 , V_229 -> V_239 , V_229 -> V_240 , V_50 ) ;
}
if ( F_79 ( V_235 , & V_238 ) < 0 || V_238 . V_241 + 1 > ( V_242 ) sizeof( V_232 ) )
return - 1 ;
V_33 = F_80 ( V_235 , V_232 , sizeof( V_232 ) ) ;
if ( V_33 < 0 || V_33 > V_238 . V_241 )
return - 1 ;
V_232 [ V_33 ] = '\0' ;
return F_76 ( V_229 , V_50 , V_232 ) ;
}
static const char * F_81 ( struct V_229 * V_229 , int V_50 ,
struct V_243 * V_243 )
{
struct V_224 * V_225 = F_74 ( V_229 ) ;
if ( V_225 == NULL )
return NULL ;
if ( V_50 < 0 )
return NULL ;
if ( ( V_50 > V_225 -> V_226 . V_227 || V_225 -> V_226 . V_234 [ V_50 ] == NULL ) ) {
if ( ! V_243 -> V_244 )
return NULL ;
++ V_243 -> V_245 . V_246 ;
if ( F_78 ( V_229 , V_50 ) )
return NULL ;
}
return V_225 -> V_226 . V_234 [ V_50 ] ;
}
static T_1 F_22 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_18 ( V_39 , V_6 , L_6 , V_50 ) ;
const char * V_247 = F_81 ( V_42 -> V_229 , V_50 , V_42 -> V_243 ) ;
if ( V_247 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_27 , V_247 ) ;
return V_52 ;
}
static T_1 F_82 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_22 ( V_39 , V_6 , V_42 ) ;
struct V_224 * V_225 = F_74 ( V_42 -> V_229 ) ;
if ( V_225 && V_50 >= 0 && V_50 <= V_225 -> V_226 . V_227 )
F_8 ( & V_225 -> V_226 . V_234 [ V_50 ] ) ;
return V_52 ;
}
static bool F_83 ( struct V_243 * V_243 , double V_217 )
{
return V_217 < ( V_243 -> V_248 * V_220 ) ;
}
static T_1 F_84 ( struct V_243 * V_243 , T_5 V_249 , V_67 * V_218 )
{
double V_250 = ( double ) ( V_249 - V_243 -> V_251 ) / V_220 ;
return fprintf ( V_218 , L_28 , V_250 ) ;
}
static void F_85 ( int V_179 )
{
V_252 = true ;
V_253 = V_179 == V_254 ;
}
static T_1 F_86 ( struct V_243 * V_243 , struct V_229 * V_229 ,
T_5 V_219 , T_5 V_249 , V_67 * V_218 )
{
T_1 V_52 = F_84 ( V_243 , V_249 , V_218 ) ;
V_52 += F_68 ( V_219 , V_218 ) ;
if ( V_243 -> V_255 ) {
if ( V_243 -> V_256 )
V_52 += fprintf ( V_218 , L_29 , F_87 ( V_229 ) ) ;
V_52 += fprintf ( V_218 , L_30 , V_229 -> V_240 ) ;
}
return V_52 ;
}
static int F_88 ( struct V_243 * V_243 , struct V_257 * V_257 ,
union V_258 * V_259 , struct V_14 * V_15 )
{
int V_33 = 0 ;
switch ( V_259 -> V_260 . type ) {
case V_261 :
F_69 ( V_243 -> V_262 , V_221 ,
L_31 V_263 L_32 , V_259 -> V_264 . V_264 ) ;
V_33 = F_89 ( V_257 , V_259 , V_15 ) ;
default:
V_33 = F_90 ( V_257 , V_259 , V_15 ) ;
break;
}
return V_33 ;
}
static int F_91 ( struct V_265 * V_266 ,
union V_258 * V_259 ,
struct V_14 * V_15 ,
struct V_257 * V_257 )
{
struct V_243 * V_243 = F_92 ( V_266 , struct V_243 , V_266 ) ;
return F_88 ( V_243 , V_257 , V_259 , V_15 ) ;
}
static int F_93 ( struct V_243 * V_243 , struct V_29 * V_30 )
{
int V_267 = F_94 ( NULL ) ;
if ( V_267 )
return V_267 ;
V_243 -> V_268 = F_95 () ;
if ( V_243 -> V_268 == NULL )
return - V_26 ;
V_267 = F_96 ( V_243 -> V_268 , & V_243 -> V_266 , & V_243 -> V_269 . V_270 ,
V_30 -> V_271 , F_91 , false ) ;
if ( V_267 )
F_97 () ;
return V_267 ;
}
static int F_98 ( struct V_272 * V_273 )
{
struct V_3 * V_2 ;
int V_46 = 0 ;
V_273 -> V_274 = calloc ( V_273 -> V_275 , sizeof( void * ) ) ;
if ( V_273 -> V_274 == NULL )
return - 1 ;
if ( V_273 -> V_214 )
V_273 -> V_276 = V_273 -> V_214 -> V_276 ;
for ( V_2 = V_273 -> args ; V_2 ; V_2 = V_2 -> V_277 ) {
if ( V_273 -> V_214 && V_273 -> V_214 -> V_274 [ V_46 ] )
V_273 -> V_274 [ V_46 ] = V_273 -> V_214 -> V_274 [ V_46 ] ;
else if ( V_2 -> V_61 & V_278 )
V_273 -> V_274 [ V_46 ] = F_23 ;
++ V_46 ;
}
return 0 ;
}
static int F_99 ( struct V_243 * V_243 , int V_24 )
{
char V_279 [ 128 ] ;
struct V_272 * V_273 ;
const char * V_20 = F_100 ( V_24 , V_243 -> V_280 . V_257 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_243 -> V_281 . V_227 ) {
struct V_272 * V_282 = realloc ( V_243 -> V_281 . V_234 , ( V_24 + 1 ) * sizeof( * V_273 ) ) ;
if ( V_282 == NULL )
return - 1 ;
if ( V_243 -> V_281 . V_227 != - 1 ) {
memset ( V_282 + V_243 -> V_281 . V_227 + 1 , 0 ,
( V_24 - V_243 -> V_281 . V_227 ) * sizeof( * V_273 ) ) ;
} else {
memset ( V_282 , 0 , ( V_24 + 1 ) * sizeof( * V_273 ) ) ;
}
V_243 -> V_281 . V_234 = V_282 ;
V_243 -> V_281 . V_227 = V_24 ;
}
V_273 = V_243 -> V_281 . V_234 + V_24 ;
V_273 -> V_20 = V_20 ;
if ( V_243 -> V_283 ) {
bool V_284 = F_101 ( V_243 -> V_283 , V_20 ) != NULL ;
if ( ! ( V_284 ^ V_243 -> V_285 ) ) {
V_273 -> V_286 = true ;
return 0 ;
}
}
V_273 -> V_214 = F_66 ( V_273 -> V_20 ) ;
snprintf ( V_279 , sizeof( V_279 ) , L_33 , V_273 -> V_20 ) ;
V_273 -> V_287 = F_102 ( L_2 , V_279 ) ;
if ( V_273 -> V_287 == NULL && V_273 -> V_214 && V_273 -> V_214 -> V_288 ) {
snprintf ( V_279 , sizeof( V_279 ) , L_33 , V_273 -> V_214 -> V_288 ) ;
V_273 -> V_287 = F_102 ( L_2 , V_279 ) ;
}
if ( V_273 -> V_287 == NULL )
return - 1 ;
V_273 -> args = V_273 -> V_287 -> V_289 . V_290 ;
V_273 -> V_275 = V_273 -> V_287 -> V_289 . V_291 ;
if ( V_273 -> args && strcmp ( V_273 -> args -> V_20 , L_34 ) == 0 ) {
V_273 -> args = V_273 -> args -> V_277 ;
-- V_273 -> V_275 ;
}
V_273 -> V_292 = ! strcmp ( V_20 , L_35 ) || ! strcmp ( V_20 , L_36 ) ;
return F_98 ( V_273 ) ;
}
static T_1 F_103 ( struct V_272 * V_273 , char * V_39 , T_1 V_6 ,
unsigned char * args , struct V_243 * V_243 ,
struct V_229 * V_229 )
{
T_1 V_52 = 0 ;
unsigned char * V_293 ;
unsigned long V_47 ;
if ( V_273 -> args != NULL ) {
struct V_3 * V_2 ;
T_6 V_294 = 1 ;
struct V_41 V_42 = {
. V_46 = 0 ,
. V_110 = 0 ,
. V_243 = V_243 ,
. V_229 = V_229 ,
} ;
for ( V_2 = V_273 -> args ; V_2 ;
V_2 = V_2 -> V_277 , ++ V_42 . V_46 , V_294 <<= 1 ) {
if ( V_42 . V_110 & V_294 )
continue;
V_293 = args + sizeof( unsigned long ) * V_42 . V_46 ;
memcpy ( & V_47 , V_293 , sizeof( V_47 ) ) ;
if ( V_47 == 0 &&
! ( V_273 -> V_274 &&
V_273 -> V_274 [ V_42 . V_46 ] == V_295 &&
V_273 -> V_276 [ V_42 . V_46 ] ) )
continue;
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_37 , V_52 ? L_38 : L_13 , V_2 -> V_20 ) ;
if ( V_273 -> V_274 && V_273 -> V_274 [ V_42 . V_46 ] ) {
V_42 . V_47 = V_47 ;
if ( V_273 -> V_276 )
V_42 . V_45 = V_273 -> V_276 [ V_42 . V_46 ] ;
V_52 += V_273 -> V_274 [ V_42 . V_46 ] ( V_39 + V_52 ,
V_6 - V_52 , & V_42 ) ;
} else {
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_39 , V_47 ) ;
}
}
} else {
int V_296 = 0 ;
while ( V_296 < 6 ) {
V_293 = args + sizeof( unsigned long ) * V_296 ;
memcpy ( & V_47 , V_293 , sizeof( V_47 ) ) ;
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_40 ,
V_52 ? L_38 : L_13 , V_296 , V_47 ) ;
++ V_296 ;
}
}
return V_52 ;
}
static struct V_272 * F_104 ( struct V_243 * V_243 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_297 > 1 ) {
static T_5 T_2 ;
fprintf ( V_243 -> V_262 , L_41 V_263 L_42 ,
V_24 , F_105 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_243 -> V_281 . V_227 || V_243 -> V_281 . V_234 [ V_24 ] . V_20 == NULL ) &&
F_99 ( V_243 , V_24 ) )
goto V_298;
if ( ( V_24 > V_243 -> V_281 . V_227 || V_243 -> V_281 . V_234 [ V_24 ] . V_20 == NULL ) )
goto V_298;
return & V_243 -> V_281 . V_234 [ V_24 ] ;
V_298:
if ( V_297 ) {
fprintf ( V_243 -> V_262 , L_43 , V_24 ) ;
if ( V_24 <= V_243 -> V_281 . V_227 && V_243 -> V_281 . V_234 [ V_24 ] . V_20 != NULL )
fprintf ( V_243 -> V_262 , L_44 , V_243 -> V_281 . V_234 [ V_24 ] . V_20 ) ;
fputs ( L_45 , V_243 -> V_262 ) ;
}
return NULL ;
}
static void F_106 ( struct V_224 * V_225 ,
int V_24 , struct V_14 * V_15 )
{
struct V_299 * V_300 ;
struct V_245 * V_245 ;
T_5 V_219 = 0 ;
V_300 = F_107 ( V_225 -> V_228 , V_24 ) ;
if ( V_300 == NULL )
return;
V_245 = V_300 -> V_21 ;
if ( V_245 == NULL ) {
V_245 = malloc ( sizeof( struct V_245 ) ) ;
if ( V_245 == NULL )
return;
F_108 ( V_245 ) ;
V_300 -> V_21 = V_245 ;
}
if ( V_225 -> V_301 && V_15 -> time > V_225 -> V_301 )
V_219 = V_15 -> time - V_225 -> V_301 ;
F_109 ( V_245 , V_219 ) ;
}
static int F_110 ( struct V_243 * V_243 , struct V_14 * V_15 )
{
struct V_224 * V_225 ;
T_5 V_219 ;
T_1 V_52 ;
if ( V_243 -> V_302 == NULL )
return 0 ;
V_225 = F_74 ( V_243 -> V_302 ) ;
if ( ! V_225 -> V_303 )
return 0 ;
V_219 = V_15 -> time - V_225 -> V_301 ;
V_52 = F_86 ( V_243 , V_243 -> V_302 , V_219 , V_15 -> time , V_243 -> V_262 ) ;
V_52 += fprintf ( V_243 -> V_262 , L_46 , V_225 -> V_304 ) ;
V_225 -> V_303 = false ;
return V_52 ;
}
static int F_111 ( struct V_243 * V_243 , struct V_18 * V_19 ,
union V_258 * V_259 V_305 ,
struct V_14 * V_15 )
{
char * V_306 ;
void * args ;
T_1 V_52 = 0 ;
struct V_229 * V_229 ;
int V_24 = F_112 ( V_19 , V_24 , V_15 ) ;
struct V_272 * V_273 = F_104 ( V_243 , V_19 , V_24 ) ;
struct V_224 * V_225 ;
if ( V_273 == NULL )
return - 1 ;
if ( V_273 -> V_286 )
return 0 ;
V_229 = F_113 ( V_243 -> V_268 , V_15 -> V_307 , V_15 -> V_240 ) ;
V_225 = F_73 ( V_229 , V_243 -> V_262 ) ;
if ( V_225 == NULL )
return - 1 ;
args = F_114 ( V_19 , args , V_15 ) ;
if ( V_225 -> V_304 == NULL ) {
V_225 -> V_304 = malloc ( 1024 ) ;
if ( ! V_225 -> V_304 )
return - 1 ;
}
if ( ! V_243 -> V_308 )
F_110 ( V_243 , V_15 ) ;
V_225 -> V_301 = V_15 -> time ;
V_306 = V_225 -> V_304 ;
V_52 += F_18 ( V_306 + V_52 , 1024 - V_52 , L_47 , V_273 -> V_20 ) ;
V_52 += F_103 ( V_273 , V_306 + V_52 , 1024 - V_52 ,
args , V_243 , V_229 ) ;
if ( V_273 -> V_292 ) {
if ( ! V_243 -> V_248 && ! V_243 -> V_308 ) {
F_86 ( V_243 , V_229 , 1 , V_15 -> time , V_243 -> V_262 ) ;
fprintf ( V_243 -> V_262 , L_48 , V_225 -> V_304 ) ;
}
} else
V_225 -> V_303 = true ;
if ( V_243 -> V_302 != V_229 ) {
F_115 ( V_243 -> V_302 ) ;
V_243 -> V_302 = F_116 ( V_229 ) ;
}
return 0 ;
}
static int F_117 ( struct V_243 * V_243 , struct V_18 * V_19 ,
union V_258 * V_259 V_305 ,
struct V_14 * V_15 )
{
long V_33 ;
T_5 V_219 = 0 ;
struct V_229 * V_229 ;
int V_24 = F_112 ( V_19 , V_24 , V_15 ) ;
struct V_272 * V_273 = F_104 ( V_243 , V_19 , V_24 ) ;
struct V_224 * V_225 ;
if ( V_273 == NULL )
return - 1 ;
if ( V_273 -> V_286 )
return 0 ;
V_229 = F_113 ( V_243 -> V_268 , V_15 -> V_307 , V_15 -> V_240 ) ;
V_225 = F_73 ( V_229 , V_243 -> V_262 ) ;
if ( V_225 == NULL )
return - 1 ;
if ( V_243 -> V_309 )
F_106 ( V_225 , V_24 , V_15 ) ;
V_33 = F_112 ( V_19 , V_33 , V_15 ) ;
if ( V_24 == V_243 -> V_280 . V_310 && V_33 >= 0 && V_243 -> V_311 ) {
F_76 ( V_229 , V_33 , V_243 -> V_311 ) ;
V_243 -> V_311 = NULL ;
++ V_243 -> V_245 . V_312 ;
}
V_225 -> V_313 = V_15 -> time ;
if ( V_225 -> V_301 ) {
V_219 = V_15 -> time - V_225 -> V_301 ;
if ( F_83 ( V_243 , V_219 ) )
goto V_36;
} else if ( V_243 -> V_248 )
goto V_36;
if ( V_243 -> V_308 )
goto V_36;
F_86 ( V_243 , V_229 , V_219 , V_15 -> time , V_243 -> V_262 ) ;
if ( V_225 -> V_303 ) {
fprintf ( V_243 -> V_262 , L_49 , V_225 -> V_304 ) ;
} else {
fprintf ( V_243 -> V_262 , L_50 ) ;
F_69 ( V_243 -> V_262 , V_222 , L_51 ) ;
fprintf ( V_243 -> V_262 , L_52 , V_273 -> V_20 ) ;
}
if ( V_273 -> V_214 == NULL ) {
V_314:
fprintf ( V_243 -> V_262 , L_53 , V_33 ) ;
} else if ( V_33 < 0 && V_273 -> V_214 -> V_315 ) {
char V_39 [ V_316 ] ;
const char * V_317 = F_118 ( - V_33 , V_39 , sizeof( V_39 ) ) ,
* V_318 = F_119 ( - V_33 ) ;
fprintf ( V_243 -> V_262 , L_54 , V_318 , V_317 ) ;
} else if ( V_33 == 0 && V_273 -> V_214 -> V_319 )
fprintf ( V_243 -> V_262 , L_55 ) ;
else if ( V_273 -> V_214 -> V_320 )
fprintf ( V_243 -> V_262 , L_56 , V_33 ) ;
else
goto V_314;
fputc ( '\n' , V_243 -> V_262 ) ;
V_36:
V_225 -> V_303 = false ;
return 0 ;
}
static int F_120 ( struct V_243 * V_243 , struct V_18 * V_19 ,
union V_258 * V_259 V_305 ,
struct V_14 * V_15 )
{
V_243 -> V_311 = F_121 ( V_19 , V_15 , L_57 ) ;
return 0 ;
}
static int F_122 ( struct V_243 * V_243 , struct V_18 * V_19 ,
union V_258 * V_259 V_305 ,
struct V_14 * V_15 )
{
T_5 V_321 = F_123 ( V_19 , V_15 , L_58 ) ;
double V_322 = ( double ) V_321 / V_220 ;
struct V_229 * V_229 = F_113 ( V_243 -> V_268 ,
V_15 -> V_307 ,
V_15 -> V_240 ) ;
struct V_224 * V_225 = F_73 ( V_229 , V_243 -> V_262 ) ;
if ( V_225 == NULL )
goto V_323;
V_225 -> V_322 += V_322 ;
V_243 -> V_322 += V_322 ;
return 0 ;
V_323:
fprintf ( V_243 -> V_262 , L_59 V_263 L_60 V_263 L_61 ,
V_19 -> V_20 ,
F_124 ( V_19 , V_15 , L_62 ) ,
( V_324 ) F_123 ( V_19 , V_15 , L_63 ) ,
V_321 ,
F_123 ( V_19 , V_15 , L_64 ) ) ;
return 0 ;
}
static int F_125 ( struct V_243 * V_243 , struct V_18 * V_19 ,
union V_258 * V_259 V_305 ,
struct V_14 * V_15 )
{
F_110 ( V_243 , V_15 ) ;
F_84 ( V_243 , V_15 -> time , V_243 -> V_262 ) ;
if ( V_243 -> V_325 )
fprintf ( V_243 -> V_262 , L_65 ) ;
fprintf ( V_243 -> V_262 , L_66 , V_19 -> V_20 ) ;
if ( V_19 -> V_287 ) {
F_126 ( V_19 -> V_287 , V_15 -> V_326 ,
V_15 -> V_16 , V_15 -> V_327 ,
V_243 -> V_262 ) ;
}
fprintf ( V_243 -> V_262 , L_61 ) ;
return 0 ;
}
static void F_127 ( V_67 * V_328 , struct V_14 * V_15 ,
struct V_329 * V_330 ,
bool V_331 , bool V_332 )
{
if ( ( V_297 || V_331 ) && V_330 -> V_333 )
fprintf ( V_328 , L_67 , V_330 -> V_333 -> V_334 -> V_335 ) ;
if ( ( V_297 || V_332 ) && V_330 -> V_336 )
fprintf ( V_328 , L_68 V_337 , V_330 -> V_336 -> V_20 ,
V_330 -> V_338 - V_330 -> V_336 -> V_339 ) ;
else if ( V_330 -> V_333 )
fprintf ( V_328 , L_69 V_337 , V_330 -> V_338 ) ;
else
fprintf ( V_328 , L_69 V_337 , V_15 -> V_338 ) ;
}
static int F_128 ( struct V_243 * V_243 ,
struct V_18 * V_19 ,
union V_258 * V_259 ,
struct V_14 * V_15 )
{
struct V_229 * V_229 ;
T_6 V_340 = V_259 -> V_260 . V_341 & V_342 ;
struct V_329 V_330 ;
char V_343 = 'd' ;
struct V_224 * V_225 ;
V_229 = F_113 ( V_243 -> V_268 , V_15 -> V_307 , V_15 -> V_240 ) ;
V_225 = F_73 ( V_229 , V_243 -> V_262 ) ;
if ( V_225 == NULL )
return - 1 ;
if ( V_19 -> V_344 . V_345 == V_346 )
V_225 -> V_347 ++ ;
else
V_225 -> V_348 ++ ;
if ( V_243 -> V_308 )
return 0 ;
F_129 ( V_229 , V_340 , V_349 ,
V_15 -> V_350 , & V_330 ) ;
F_86 ( V_243 , V_229 , 0 , V_15 -> time , V_243 -> V_262 ) ;
fprintf ( V_243 -> V_262 , L_70 ,
V_19 -> V_344 . V_345 == V_346 ?
L_71 : L_72 ) ;
F_127 ( V_243 -> V_262 , V_15 , & V_330 , false , true ) ;
fprintf ( V_243 -> V_262 , L_73 ) ;
F_129 ( V_229 , V_340 , V_351 ,
V_15 -> V_338 , & V_330 ) ;
if ( ! V_330 . V_333 ) {
F_129 ( V_229 , V_340 ,
V_349 , V_15 -> V_338 , & V_330 ) ;
if ( V_330 . V_333 )
V_343 = 'x' ;
else
V_343 = '?' ;
}
F_127 ( V_243 -> V_262 , V_15 , & V_330 , true , false ) ;
fprintf ( V_243 -> V_262 , L_74 , V_343 , V_330 . V_352 ) ;
return 0 ;
}
static bool F_130 ( struct V_243 * V_243 , struct V_14 * V_15 )
{
if ( ( V_243 -> V_353 && F_131 ( V_243 -> V_353 , V_15 -> V_307 ) ) ||
( V_243 -> V_354 && F_131 ( V_243 -> V_354 , V_15 -> V_240 ) ) )
return false ;
if ( V_243 -> V_353 || V_243 -> V_354 )
return true ;
return false ;
}
static int F_132 ( struct V_265 * V_266 ,
union V_258 * V_259 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_257 * V_257 V_305 )
{
struct V_243 * V_243 = F_92 ( V_266 , struct V_243 , V_266 ) ;
int V_267 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
if ( F_130 ( V_243 , V_15 ) )
return 0 ;
if ( ! V_243 -> V_355 && V_243 -> V_251 == 0 )
V_243 -> V_251 = V_15 -> time ;
if ( V_22 ) {
++ V_243 -> V_231 ;
V_22 ( V_243 , V_19 , V_259 , V_15 ) ;
}
return V_267 ;
}
static int F_133 ( struct V_243 * V_243 )
{
if ( V_243 -> V_269 . V_270 . V_307 ) {
V_243 -> V_353 = F_72 ( V_243 -> V_269 . V_270 . V_307 ) ;
if ( V_243 -> V_353 == NULL ) {
F_134 ( L_75 ) ;
return - V_356 ;
}
}
if ( V_243 -> V_269 . V_270 . V_240 ) {
V_243 -> V_354 = F_72 ( V_243 -> V_269 . V_270 . V_240 ) ;
if ( V_243 -> V_354 == NULL ) {
F_134 ( L_76 ) ;
return - V_356 ;
}
}
return 0 ;
}
static int F_135 ( struct V_243 * V_243 , int V_357 , const char * * V_358 )
{
unsigned int V_359 , V_296 , V_360 ;
const char * * V_361 ;
const char * const V_362 [] = {
L_77 ,
L_78 ,
L_79 , L_80 ,
L_81 , L_82 ,
} ;
const char * const V_363 [] = { L_83 , } ;
unsigned int V_364 = F_67 ( V_363 ) ;
const char * const V_365 [] = { L_83 , L_84 } ;
unsigned int V_366 = F_67 ( V_365 ) ;
const char * const V_367 [] = { L_83 , L_85 } ;
unsigned int V_368 = F_67 ( V_367 ) ;
V_359 = F_67 ( V_362 ) + V_364 + 1 +
V_366 + V_368 + V_357 ;
V_361 = calloc ( V_359 + 1 , sizeof( char * ) ) ;
if ( V_361 == NULL )
return - V_26 ;
V_360 = 0 ;
for ( V_296 = 0 ; V_296 < F_67 ( V_362 ) ; V_296 ++ )
V_361 [ V_360 ++ ] = V_362 [ V_296 ] ;
if ( V_243 -> V_325 ) {
for ( V_296 = 0 ; V_296 < V_364 ; V_296 ++ )
V_361 [ V_360 ++ ] = V_363 [ V_296 ] ;
if ( F_136 ( L_86 ) )
V_361 [ V_360 ++ ] = L_87 ;
else if ( F_136 ( L_88 ) )
V_361 [ V_360 ++ ] = L_89 ;
else {
F_134 ( L_90 ) ;
return - 1 ;
}
}
if ( V_243 -> V_369 & V_370 )
for ( V_296 = 0 ; V_296 < V_366 ; V_296 ++ )
V_361 [ V_360 ++ ] = V_365 [ V_296 ] ;
if ( V_243 -> V_369 & V_371 )
for ( V_296 = 0 ; V_296 < V_368 ; V_296 ++ )
V_361 [ V_360 ++ ] = V_367 [ V_296 ] ;
for ( V_296 = 0 ; V_296 < ( unsigned int ) V_357 ; V_296 ++ )
V_361 [ V_360 ++ ] = V_358 [ V_296 ] ;
return F_137 ( V_360 , V_361 , NULL ) ;
}
static void F_138 ( struct V_29 * V_30 )
{
struct V_18 * V_19 = F_13 ( L_91 , L_92 ) ;
if ( V_19 == NULL )
return;
if ( F_5 ( V_19 , L_57 ) == NULL ) {
F_9 ( V_19 ) ;
return;
}
V_19 -> V_22 = F_120 ;
F_16 ( V_30 , V_19 ) ;
}
static int F_139 ( struct V_29 * V_30 ,
T_5 V_345 )
{
struct V_18 * V_19 ;
struct V_372 V_344 = {
. type = V_373 ,
. V_374 = 1 ,
} ;
V_344 . V_345 = V_345 ;
V_344 . V_375 = 1 ;
F_140 ( & V_344 ) ;
V_19 = F_141 ( & V_344 ) ;
if ( ! V_19 )
return - V_26 ;
V_19 -> V_22 = F_128 ;
F_16 ( V_30 , V_19 ) ;
return 0 ;
}
static void F_142 ( struct V_243 * V_243 , union V_258 * V_259 , struct V_14 * V_15 )
{
const T_8 type = V_259 -> V_260 . type ;
struct V_18 * V_19 ;
if ( ! V_243 -> V_355 && V_243 -> V_251 == 0 )
V_243 -> V_251 = V_15 -> time ;
if ( type != V_376 ) {
F_88 ( V_243 , V_243 -> V_268 , V_259 , V_15 ) ;
return;
}
V_19 = F_143 ( V_243 -> V_30 , V_15 -> V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_243 -> V_262 , L_93 V_263 L_94 , V_15 -> V_24 ) ;
return;
}
if ( V_19 -> V_344 . type == V_377 &&
V_15 -> V_16 == NULL ) {
fprintf ( V_243 -> V_262 , L_95 ,
F_105 ( V_19 ) , V_15 -> V_240 ,
V_15 -> V_326 , V_15 -> V_327 ) ;
} else {
T_7 V_22 = V_19 -> V_22 ;
V_22 ( V_243 , V_19 , V_259 , V_15 ) ;
}
}
static int F_144 ( struct V_243 * V_243 , int V_357 , const char * * V_358 )
{
struct V_29 * V_30 = V_243 -> V_30 ;
int V_267 = - 1 , V_296 ;
unsigned long V_378 ;
const bool V_379 = V_357 > 0 ;
bool V_380 = false ;
V_243 -> V_244 = true ;
if ( V_243 -> V_325 &&
F_14 ( V_30 , F_111 ,
F_117 ) )
goto V_381;
if ( V_243 -> V_325 )
F_138 ( V_30 ) ;
if ( ( V_243 -> V_369 & V_370 ) &&
F_139 ( V_30 , V_346 ) ) {
goto V_382;
}
if ( ( V_243 -> V_369 & V_371 ) &&
F_139 ( V_30 , V_383 ) )
goto V_382;
if ( V_243 -> V_384 &&
F_145 ( V_30 , L_96 , L_97 ,
F_122 ) )
goto V_385;
V_267 = F_146 ( V_30 , & V_243 -> V_269 . V_270 ) ;
if ( V_267 < 0 ) {
fprintf ( V_243 -> V_262 , L_98 ) ;
goto V_386;
}
V_267 = F_93 ( V_243 , V_30 ) ;
if ( V_267 < 0 ) {
fprintf ( V_243 -> V_262 , L_99 ) ;
goto V_386;
}
F_147 ( V_30 , & V_243 -> V_269 ) ;
signal ( V_387 , F_85 ) ;
signal ( V_254 , F_85 ) ;
if ( V_379 ) {
V_267 = F_148 ( V_30 , & V_243 -> V_269 . V_270 ,
V_358 , false , NULL ) ;
if ( V_267 < 0 ) {
fprintf ( V_243 -> V_262 , L_100 ) ;
goto V_386;
}
}
V_267 = F_149 ( V_30 ) ;
if ( V_267 < 0 )
goto V_388;
if ( V_243 -> V_389 . V_390 > 0 )
V_267 = F_150 ( V_30 , V_243 -> V_389 . V_390 , V_243 -> V_389 . V_49 ) ;
else if ( V_30 -> V_271 -> V_333 [ 0 ] == - 1 )
V_267 = F_151 ( V_30 , F_152 () ) ;
if ( V_267 < 0 ) {
printf ( L_101 , - V_267 , strerror ( - V_267 ) ) ;
exit ( 1 ) ;
}
V_267 = F_153 ( V_30 , V_243 -> V_269 . V_391 , false ) ;
if ( V_267 < 0 )
goto V_392;
if ( ! F_154 ( & V_243 -> V_269 . V_270 ) )
F_155 ( V_30 ) ;
if ( V_379 )
F_156 ( V_30 ) ;
V_243 -> V_255 = V_30 -> V_271 -> V_333 [ 0 ] == - 1 ||
V_30 -> V_271 -> V_390 > 1 ||
F_157 ( V_30 ) -> V_344 . V_393 ;
V_394:
V_378 = V_243 -> V_231 ;
for ( V_296 = 0 ; V_296 < V_30 -> V_395 ; V_296 ++ ) {
union V_258 * V_259 ;
while ( ( V_259 = F_158 ( V_30 , V_296 ) ) != NULL ) {
struct V_14 V_15 ;
++ V_243 -> V_231 ;
V_267 = F_159 ( V_30 , V_259 , & V_15 ) ;
if ( V_267 ) {
fprintf ( V_243 -> V_262 , L_102 , V_267 ) ;
goto V_396;
}
F_142 ( V_243 , V_259 , & V_15 ) ;
V_396:
F_160 ( V_30 , V_296 ) ;
if ( V_253 )
goto V_397;
if ( V_252 && ! V_380 ) {
F_161 ( V_30 ) ;
V_380 = true ;
}
}
}
if ( V_243 -> V_231 == V_378 ) {
int V_319 = V_252 ? 100 : - 1 ;
if ( ! V_380 && F_162 ( V_30 , V_319 ) > 0 ) {
if ( F_163 ( V_30 , V_398 | V_399 ) == 0 )
V_380 = true ;
goto V_394;
}
} else {
goto V_394;
}
V_397:
F_164 ( V_243 -> V_302 ) ;
F_161 ( V_30 ) ;
if ( ! V_267 ) {
if ( V_243 -> V_309 )
F_165 ( V_243 , V_243 -> V_262 ) ;
if ( V_243 -> V_400 ) {
fprintf ( V_243 -> V_262 , L_103
L_104 V_263 L_105
L_106 V_263 L_105 ,
V_243 -> V_245 . V_312 ,
V_243 -> V_245 . V_246 ) ;
}
}
V_386:
F_166 ( V_30 ) ;
V_243 -> V_30 = NULL ;
V_243 -> V_244 = false ;
return V_267 ;
{
char V_401 [ V_402 ] ;
V_385:
F_167 ( V_403 , V_401 , sizeof( V_401 ) , L_96 , L_97 ) ;
goto V_404;
V_381:
F_167 ( V_403 , V_401 , sizeof( V_401 ) , L_1 , L_107 ) ;
goto V_404;
V_392:
F_168 ( V_30 , V_403 , V_401 , sizeof( V_401 ) ) ;
goto V_404;
V_388:
F_169 ( V_30 , V_403 , V_401 , sizeof( V_401 ) ) ;
V_404:
fprintf ( V_243 -> V_262 , L_108 , V_401 ) ;
goto V_386;
}
V_382:
fprintf ( V_243 -> V_262 , L_109 ) ;
goto V_386;
}
static int F_170 ( struct V_243 * V_243 )
{
const struct V_405 V_406 [] = {
{ L_110 , F_120 , } ,
} ;
struct V_407 V_408 = {
. V_247 = V_409 ,
. V_155 = V_410 ,
. V_411 = V_243 -> V_411 ,
} ;
struct V_412 * V_413 ;
struct V_18 * V_19 ;
int V_267 = - 1 ;
V_243 -> V_266 . V_15 = F_132 ;
V_243 -> V_266 . V_414 = V_415 ;
V_243 -> V_266 . V_416 = V_417 ;
V_243 -> V_266 . V_418 = V_419 ;
V_243 -> V_266 . exit = V_420 ;
V_243 -> V_266 . V_421 = V_422 ;
V_243 -> V_266 . V_344 = V_423 ;
V_243 -> V_266 . V_424 = V_425 ;
V_243 -> V_266 . V_426 = V_427 ;
V_243 -> V_266 . V_428 = true ;
V_243 -> V_266 . V_429 = true ;
V_243 -> V_255 = true ;
V_413 = F_171 ( & V_408 , false , & V_243 -> V_266 ) ;
if ( V_413 == NULL )
return - 1 ;
if ( F_94 ( & V_413 -> V_260 . V_430 ) < 0 )
goto V_36;
V_243 -> V_268 = & V_413 -> V_431 . V_268 ;
V_267 = F_172 ( V_413 , V_406 ) ;
if ( V_267 )
goto V_36;
V_19 = F_173 ( V_413 -> V_30 ,
L_86 ) ;
if ( V_19 == NULL )
V_19 = F_173 ( V_413 -> V_30 ,
L_88 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_111 ) < 0 ||
F_15 ( V_19 , args ) ) ) {
F_134 ( L_111 ) ;
goto V_36;
}
V_19 = F_173 ( V_413 -> V_30 ,
L_112 ) ;
if ( V_19 == NULL )
V_19 = F_173 ( V_413 -> V_30 ,
L_113 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_117 ) < 0 ||
F_11 ( V_19 , V_33 ) ) ) {
F_134 ( L_114 ) ;
goto V_36;
}
F_174 (session->evlist, evsel) {
if ( V_19 -> V_344 . type == V_373 &&
( V_19 -> V_344 . V_345 == V_346 ||
V_19 -> V_344 . V_345 == V_383 ||
V_19 -> V_344 . V_345 == V_432 ) )
V_19 -> V_22 = F_128 ;
}
V_267 = F_133 ( V_243 ) ;
if ( V_267 != 0 )
goto V_36;
F_175 () ;
V_267 = F_176 ( V_413 ) ;
if ( V_267 )
F_134 ( L_115 , V_267 ) ;
else if ( V_243 -> V_309 )
F_165 ( V_243 , V_243 -> V_262 ) ;
V_36:
F_177 ( V_413 ) ;
return V_267 ;
}
static T_1 F_178 ( V_67 * V_218 )
{
T_1 V_52 ;
V_52 = fprintf ( V_218 , L_116 ) ;
return V_52 ;
}
static T_1 F_179 ( struct V_224 * V_225 ,
struct V_243 * V_243 , V_67 * V_218 )
{
struct V_245 * V_245 ;
T_1 V_52 = 0 ;
struct V_272 * V_273 ;
struct V_299 * V_300 = F_180 ( V_225 -> V_228 ) ;
if ( V_300 == NULL )
return 0 ;
V_52 += fprintf ( V_218 , L_105 ) ;
V_52 += fprintf ( V_218 , L_117 ) ;
V_52 += fprintf ( V_218 , L_118 ) ;
V_52 += fprintf ( V_218 , L_119 ) ;
while ( V_300 ) {
V_245 = V_300 -> V_21 ;
if ( V_245 ) {
double V_433 = ( double ) ( V_245 -> V_433 ) / V_220 ;
double V_227 = ( double ) ( V_245 -> V_227 ) / V_220 ;
double V_434 = F_181 ( V_245 ) ;
double V_435 ;
T_5 T_2 = ( T_5 ) V_245 -> T_2 ;
V_435 = V_434 ? 100.0 * F_182 ( V_245 ) / V_434 : 0.0 ;
V_434 /= V_220 ;
V_273 = & V_243 -> V_281 . V_234 [ V_300 -> V_296 ] ;
V_52 += fprintf ( V_218 , L_120 , V_273 -> V_20 ) ;
V_52 += fprintf ( V_218 , L_121 V_263 L_122 ,
T_2 , V_433 , V_434 ) ;
V_52 += fprintf ( V_218 , L_123 , V_227 , V_435 ) ;
}
V_300 = F_183 ( V_300 ) ;
}
V_52 += fprintf ( V_218 , L_124 ) ;
return V_52 ;
}
static int F_184 ( struct V_229 * V_229 , void * V_21 )
{
struct V_436 * V_437 = V_21 ;
V_67 * V_218 = V_437 -> V_218 ;
T_1 V_52 = V_437 -> V_52 ;
struct V_243 * V_243 = V_437 -> V_243 ;
struct V_224 * V_225 = F_74 ( V_229 ) ;
double V_438 ;
if ( V_225 == NULL )
return 0 ;
V_438 = ( double ) V_225 -> V_231 / V_243 -> V_231 * 100.0 ;
V_52 += fprintf ( V_218 , L_125 , F_87 ( V_229 ) , V_229 -> V_240 ) ;
V_52 += fprintf ( V_218 , L_126 , V_225 -> V_231 ) ;
V_52 += fprintf ( V_218 , L_127 , V_438 ) ;
if ( V_225 -> V_347 )
V_52 += fprintf ( V_218 , L_128 , V_225 -> V_347 ) ;
if ( V_225 -> V_348 )
V_52 += fprintf ( V_218 , L_129 , V_225 -> V_348 ) ;
V_52 += fprintf ( V_218 , L_130 , V_225 -> V_322 ) ;
V_52 += F_179 ( V_225 , V_243 , V_218 ) ;
V_437 -> V_52 += V_52 ;
return 0 ;
}
static T_1 F_165 ( struct V_243 * V_243 , V_67 * V_218 )
{
struct V_436 V_437 = {
. V_218 = V_218 ,
. V_243 = V_243
} ;
V_437 . V_52 = F_178 ( V_218 ) ;
F_185 ( V_243 -> V_268 , F_184 , & V_437 ) ;
return V_437 . V_52 ;
}
static int F_186 ( const struct V_439 * V_440 , const char * V_441 ,
int T_9 V_305 )
{
struct V_243 * V_243 = V_440 -> V_442 ;
V_243 -> V_248 = atof ( V_441 ) ;
return 0 ;
}
static int F_187 ( const struct V_439 * V_440 , const char * V_441 ,
int T_9 V_305 )
{
int V_33 = - 1 ;
T_1 V_296 ;
struct V_243 * V_243 = V_440 -> V_442 ;
struct V_443 * V_444 = F_72 ( V_441 ) ;
if ( V_444 == NULL )
return - 1 ;
V_296 = V_243 -> V_389 . V_390 = F_188 ( V_444 ) + 1 ;
V_243 -> V_389 . V_49 = calloc ( V_296 , sizeof( V_324 ) ) ;
if ( V_243 -> V_389 . V_49 == NULL )
goto V_36;
V_243 -> V_389 . V_49 [ 0 ] = F_152 () ;
for ( V_296 = 1 ; V_296 < V_243 -> V_389 . V_390 ; ++ V_296 )
V_243 -> V_389 . V_49 [ V_296 ] = F_189 ( V_444 , V_296 - 1 ) -> V_296 ;
F_190 ( V_444 ) ;
V_33 = 0 ;
V_36:
return V_33 ;
}
static int F_191 ( struct V_243 * V_243 , const char * V_445 )
{
struct V_237 V_238 ;
if ( ! V_237 ( V_445 , & V_238 ) && V_238 . V_241 ) {
char V_446 [ V_236 ] ;
F_18 ( V_446 , sizeof( V_446 ) , L_131 , V_445 ) ;
F_192 ( V_446 ) ;
rename ( V_445 , V_446 ) ;
}
V_243 -> V_262 = fopen ( V_445 , L_132 ) ;
return V_243 -> V_262 == NULL ? - V_403 : 0 ;
}
static int F_193 ( const struct V_439 * V_440 , const char * V_441 ,
int T_9 V_305 )
{
int * V_369 = V_440 -> V_442 ;
if ( strcmp ( V_441 , L_133 ) == 0 )
* V_369 |= V_370 | V_371 ;
else if ( strcmp ( V_441 , L_71 ) == 0 )
* V_369 |= V_370 ;
else if ( strcmp ( V_441 , L_72 ) == 0 )
* V_369 |= V_371 ;
else
return - 1 ;
return 0 ;
}
static void F_194 ( struct V_29 * V_30 , void * V_22 )
{
struct V_18 * V_19 ;
F_174 (evlist, evsel)
V_19 -> V_22 = V_22 ;
}
int F_195 ( int V_357 , const char * * V_358 , const char * T_10 V_305 )
{
const char * V_447 [] = {
L_134 ,
L_135 ,
L_136 ,
L_137 ,
NULL
} ;
struct V_243 V_243 = {
. V_280 = {
. V_257 = F_196 () ,
. V_310 = F_197 ( L_138 , V_243 . V_280 . V_257 ) ,
} ,
. V_281 = {
. V_227 = - 1 ,
} ,
. V_269 = {
. V_270 = {
. V_448 = V_449 ,
. V_450 = true ,
} ,
. V_451 = V_449 ,
. V_452 = V_453 ,
. V_454 = true ,
. V_391 = V_449 ,
} ,
. V_262 = stdout ,
. V_256 = true ,
. V_325 = true ,
} ;
const char * V_455 = NULL ;
const char * V_456 = NULL ;
const struct V_439 V_457 [] = {
F_198 ( 0 , L_139 , & V_243 . V_30 , L_139 ,
L_140 ,
V_458 ) ,
F_199 ( 0 , L_62 , & V_243 . V_256 ,
L_141 ) ,
F_199 ( 0 , L_142 , & V_243 . V_400 , L_143 ) ,
F_200 ( 'e' , L_144 , & V_456 , L_144 ,
L_145 ) ,
F_200 ( 'o' , L_146 , & V_455 , L_147 , L_148 ) ,
F_200 ( 'i' , L_149 , & V_409 , L_147 , L_150 ) ,
F_200 ( 'p' , L_63 , & V_243 . V_269 . V_270 . V_307 , L_63 ,
L_151 ) ,
F_200 ( 't' , L_152 , & V_243 . V_269 . V_270 . V_240 , L_152 ,
L_153 ) ,
F_198 ( 0 , L_154 , & V_243 , L_155 ,
L_156 , F_187 ) ,
F_199 ( 'a' , L_157 , & V_243 . V_269 . V_270 . V_459 ,
L_158 ) ,
F_200 ( 'C' , L_159 , & V_243 . V_269 . V_270 . V_460 , L_159 ,
L_160 ) ,
F_199 ( 0 , L_161 , & V_243 . V_269 . V_461 ,
L_162 ) ,
F_198 ( 'm' , L_163 , & V_243 . V_269 . V_391 , L_164 ,
L_165 ,
V_462 ) ,
F_200 ( 'u' , L_166 , & V_243 . V_269 . V_270 . V_463 , L_167 ,
L_168 ) ,
F_198 ( 0 , L_169 , & V_243 , L_155 ,
L_156 ,
F_186 ) ,
F_199 ( 0 , L_96 , & V_243 . V_384 , L_170 ) ,
F_201 ( 'v' , L_171 , & V_297 , L_172 ) ,
F_199 ( 'T' , L_173 , & V_243 . V_355 ,
L_174 ) ,
F_199 ( 's' , L_175 , & V_243 . V_308 ,
L_176 ) ,
F_199 ( 'S' , L_177 , & V_243 . V_309 ,
L_178 ) ,
F_202 ( 'F' , L_179 , & V_243 . V_369 , L_180 ,
L_181 , F_193 , L_71 ) ,
F_199 ( 0 , L_2 , & V_243 . V_325 , L_182 ) ,
F_199 ( 'f' , L_183 , & V_243 . V_411 , L_184 ) ,
F_203 ()
} ;
const char * const V_464 [] = { L_77 , NULL } ;
int V_267 ;
char V_39 [ V_402 ] ;
signal ( V_465 , V_466 ) ;
signal ( V_467 , V_466 ) ;
V_243 . V_30 = F_204 () ;
if ( V_243 . V_30 == NULL )
return - V_26 ;
if ( V_243 . V_30 == NULL ) {
F_134 ( L_109 ) ;
goto V_36;
}
V_357 = F_205 ( V_357 , V_358 , V_457 , V_464 ,
V_447 , V_468 ) ;
if ( V_243 . V_369 ) {
V_243 . V_269 . V_469 = true ;
V_243 . V_269 . V_470 = true ;
}
if ( V_243 . V_30 -> V_48 > 0 )
F_194 ( V_243 . V_30 , F_125 ) ;
if ( ( V_357 >= 1 ) && ( strcmp ( V_358 [ 0 ] , L_77 ) == 0 ) )
return F_135 ( & V_243 , V_357 - 1 , & V_358 [ 1 ] ) ;
if ( V_243 . V_308 )
V_243 . V_309 = V_243 . V_308 ;
if ( ! V_243 . V_325 && ! V_243 . V_369 &&
V_243 . V_30 -> V_48 == 0 ) {
F_134 ( L_185 ) ;
return - 1 ;
}
if ( V_455 != NULL ) {
V_267 = F_191 ( & V_243 , V_455 ) ;
if ( V_267 < 0 ) {
perror ( L_186 ) ;
goto V_36;
}
}
if ( V_456 != NULL ) {
const char * V_471 = V_456 ;
V_243 . V_285 = * V_471 == '!' ;
if ( V_243 . V_285 )
++ V_471 ;
V_243 . V_283 = F_206 ( true , V_471 ) ;
if ( V_243 . V_283 == NULL ) {
fputs ( L_187 ,
V_243 . V_262 ) ;
V_267 = - V_26 ;
goto V_472;
}
}
V_267 = F_207 ( & V_243 . V_269 . V_270 ) ;
if ( V_267 ) {
F_208 ( & V_243 . V_269 . V_270 , V_267 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_243 . V_262 , L_5 , V_39 ) ;
goto V_472;
}
V_267 = F_209 ( & V_243 . V_269 . V_270 ) ;
if ( V_267 ) {
F_208 ( & V_243 . V_269 . V_270 , V_267 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_243 . V_262 , L_5 , V_39 ) ;
goto V_472;
}
if ( ! V_357 && F_154 ( & V_243 . V_269 . V_270 ) )
V_243 . V_269 . V_270 . V_459 = true ;
if ( V_409 )
V_267 = F_170 ( & V_243 ) ;
else
V_267 = F_144 ( & V_243 , V_357 , V_358 ) ;
V_472:
if ( V_455 != NULL )
fclose ( V_243 . V_262 ) ;
V_36:
return V_267 ;
}
