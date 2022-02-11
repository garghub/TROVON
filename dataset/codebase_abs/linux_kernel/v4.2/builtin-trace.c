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
return F_18 ( V_39 , V_6 , L_6 , V_42 -> V_47 ) ;
}
static T_1 F_25 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_53 = V_42 -> V_47 ;
if ( V_53 == V_54 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_26 ( T_2 ) \
if (prot & PROT_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
prot &= ~PROT_##n; \
}
F_26 ( V_55 ) ;
F_26 ( V_56 ) ;
F_26 ( V_57 ) ;
#ifdef F_27
F_26 ( V_58 ) ;
#endif
F_26 ( V_59 ) ;
F_26 ( V_60 ) ;
#undef F_26
if ( V_53 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_53 ) ;
return V_52 ;
}
static T_1 F_28 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_29 ( T_2 ) \
if (flags & MAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MAP_##n; \
}
F_29 ( V_62 ) ;
F_29 ( V_63 ) ;
#ifdef F_30
F_29 ( 32BIT ) ;
#endif
F_29 ( V_64 ) ;
F_29 ( V_65 ) ;
F_29 ( V_66 ) ;
F_29 ( V_67 ) ;
F_29 ( V_68 ) ;
F_29 ( V_59 ) ;
#ifdef F_31
F_29 ( V_69 ) ;
#endif
F_29 ( V_70 ) ;
F_29 ( V_71 ) ;
F_29 ( V_72 ) ;
F_29 ( V_73 ) ;
F_29 ( V_74 ) ;
#ifdef F_32
F_29 ( V_75 ) ;
#endif
#undef F_29
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_33 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_34 ( T_2 ) \
if (flags & MREMAP_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MREMAP_##n; \
}
F_34 ( V_76 ) ;
#ifdef F_35
F_34 ( V_68 ) ;
#endif
#undef F_34
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_36 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_77 = V_42 -> V_47 ;
switch ( V_77 ) {
#define F_37 ( T_2 ) case MADV_##n: return scnprintf(bf, size, #n)
F_37 ( V_78 ) ;
F_37 ( V_79 ) ;
F_37 ( V_80 ) ;
F_37 ( V_81 ) ;
F_37 ( V_82 ) ;
F_37 ( REMOVE ) ;
F_37 ( V_83 ) ;
F_37 ( V_84 ) ;
F_37 ( V_85 ) ;
#ifdef F_38
F_37 ( V_86 ) ;
#endif
F_37 ( V_87 ) ;
F_37 ( V_88 ) ;
#ifdef F_39
F_37 ( V_89 ) ;
#endif
#ifdef F_40
F_37 ( V_90 ) ;
#endif
#ifdef F_41
F_37 ( V_91 ) ;
#endif
#ifdef F_42
F_37 ( V_92 ) ;
#endif
#undef V_93
default: break;
}
return F_18 ( V_39 , V_6 , L_7 , V_77 ) ;
}
static T_1 F_43 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_94 = V_42 -> V_47 ;
if ( V_94 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_44 ( T_3 ) \
if ((op & LOCK_##cmd) == LOCK_##cmd) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #cmd); \
op &= ~LOCK_##cmd; \
}
F_44 ( V_95 ) ;
F_44 ( V_96 ) ;
F_44 ( V_97 ) ;
F_44 ( V_98 ) ;
F_44 ( V_99 ) ;
F_44 ( V_100 ) ;
F_44 ( V_56 ) ;
F_44 ( V_57 ) ;
#undef V_101
if ( V_94 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_94 ) ;
return V_52 ;
}
static T_1 F_45 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
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
#define F_46 ( T_2 ) case FUTEX_##n: printed = scnprintf(bf, size, #n);
F_46 ( V_109 ) ; V_42 -> V_110 |= V_107 | V_106 ; break;
F_46 ( V_111 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_46 ( V_112 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_46 ( V_113 ) ; V_42 -> V_110 |= V_107 | V_105 ; break;
F_46 ( V_114 ) ; V_42 -> V_110 |= V_105 ; break;
F_46 ( V_115 ) ; V_42 -> V_110 |= V_105 ; break;
F_46 ( V_116 ) ; break;
F_46 ( V_117 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_46 ( V_118 ) ; V_42 -> V_110 |= V_107 | V_106 | V_105 ; break;
F_46 ( V_119 ) ; V_42 -> V_110 |= V_107 | V_106 ; break;
F_46 ( V_120 ) ; V_42 -> V_110 |= V_106 ; break;
F_46 ( V_121 ) ; V_42 -> V_110 |= V_106 ; break;
F_46 ( V_122 ) ; break;
default: V_52 = F_18 ( V_39 , V_6 , L_7 , T_3 ) ; break;
}
if ( V_94 & V_123 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_14 ) ;
if ( V_94 & V_124 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_15 ) ;
return V_52 ;
}
static T_1 F_47 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 ;
int type = V_42 -> V_47 ,
V_61 = type & ~ V_125 ;
type &= V_125 ;
switch ( type ) {
#define F_48 ( T_2 ) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
F_48 ( V_126 ) ;
F_48 ( V_127 ) ;
F_48 ( V_128 ) ;
F_48 ( V_129 ) ;
F_48 ( V_130 ) ;
F_48 ( V_131 ) ;
F_48 ( V_132 ) ;
#undef F_48
default:
V_52 = F_18 ( V_39 , V_6 , L_7 , type ) ;
}
#define F_49 ( T_2 ) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
F_49 ( V_133 ) ;
F_49 ( V_71 ) ;
#undef F_49
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_16 , V_61 ) ;
return V_52 ;
}
static T_1 F_50 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_51 ( T_2 ) \
if (flags & MSG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~MSG_##n; \
}
F_51 ( V_134 ) ;
F_51 ( V_135 ) ;
F_51 ( V_136 ) ;
F_51 ( V_137 ) ;
F_51 ( V_138 ) ;
F_51 ( V_139 ) ;
F_51 ( V_140 ) ;
F_51 ( V_141 ) ;
F_51 ( V_142 ) ;
F_51 ( V_143 ) ;
F_51 ( V_144 ) ;
F_51 ( V_145 ) ;
F_51 ( V_146 ) ;
F_51 ( V_147 ) ;
F_51 ( V_148 ) ;
F_51 ( V_149 ) ;
F_51 ( V_150 ) ;
F_51 ( V_151 ) ;
F_51 ( V_152 ) ;
F_51 ( V_153 ) ;
F_51 ( V_154 ) ;
#undef F_51
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_52 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
T_1 V_52 = 0 ;
int V_155 = V_42 -> V_47 ;
if ( V_155 == V_156 )
return F_18 ( V_39 , V_6 , L_17 ) ;
#define F_53 ( T_2 ) \
if (mode & n##_OK) { \
printed += scnprintf(bf + printed, size - printed, "%s", #n); \
mode &= ~n##_OK; \
}
F_53 ( V_157 ) ;
F_53 ( V_158 ) ;
F_53 ( V_159 ) ;
#undef F_53
if ( V_155 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_16 , V_155 ) ;
return V_52 ;
}
static T_1 F_54 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( ! ( V_61 & V_160 ) )
V_42 -> V_110 |= 1 << ( V_42 -> V_46 + 1 ) ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_18 ) ;
#define F_55 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_55 ( V_161 ) ;
F_55 ( V_162 ) ;
F_55 ( V_133 ) ;
F_55 ( V_163 ) ;
F_55 ( V_164 ) ;
F_55 ( V_165 ) ;
F_55 ( V_166 ) ;
F_55 ( V_167 ) ;
F_55 ( V_168 ) ;
F_55 ( V_169 ) ;
#ifdef F_56
F_55 ( V_71 ) ;
#elif V_170
F_55 ( V_171 ) ;
#endif
#ifdef F_57
F_55 ( V_172 ) ;
#endif
F_55 ( V_173 ) ;
#ifdef F_58
if ( ( V_61 & V_174 ) == V_174 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_19 , V_52 ? L_12 : L_13 , L_20 ) ;
else {
F_55 ( V_175 ) ;
}
#else
F_55 ( V_176 ) ;
#endif
F_55 ( V_140 ) ;
F_55 ( V_177 ) ;
#undef F_55
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_59 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return 0 ;
#define F_55 ( T_2 ) \
if (flags & PERF_FLAG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~PERF_FLAG_##n; \
}
F_55 ( V_178 ) ;
F_55 ( V_179 ) ;
F_55 ( V_180 ) ;
F_55 ( V_181 ) ;
#undef F_55
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_60 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
if ( V_61 == 0 )
return F_18 ( V_39 , V_6 , L_10 ) ;
#define F_55 ( T_2 ) \
if (flags & EFD_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~EFD_##n; \
}
F_55 ( V_182 ) ;
F_55 ( V_133 ) ;
F_55 ( V_71 ) ;
#undef F_55
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_61 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_52 = 0 , V_61 = V_42 -> V_47 ;
#define F_55 ( T_2 ) \
if (flags & O_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~O_##n; \
}
F_55 ( V_133 ) ;
F_55 ( V_71 ) ;
#undef F_55
if ( V_61 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_11 , V_52 ? L_12 : L_13 , V_61 ) ;
return V_52 ;
}
static T_1 F_62 ( char * V_39 , T_1 V_6 , struct V_41 * V_42 )
{
int V_183 = V_42 -> V_47 ;
switch ( V_183 ) {
#define F_63 ( T_2 ) case SIG##n: return scnprintf(bf, size, #n)
F_63 ( V_184 ) ;
F_63 ( INT ) ;
F_63 ( V_185 ) ;
F_63 ( V_186 ) ;
F_63 ( V_187 ) ;
F_63 ( V_188 ) ;
F_63 ( V_189 ) ;
F_63 ( V_190 ) ;
F_63 ( V_191 ) ;
F_63 ( V_192 ) ;
F_63 ( V_193 ) ;
F_63 ( V_194 ) ;
F_63 ( V_195 ) ;
F_63 ( V_196 ) ;
F_63 ( V_197 ) ;
F_63 ( V_198 ) ;
F_63 ( V_199 ) ;
F_63 ( V_200 ) ;
F_63 ( V_201 ) ;
F_63 ( V_202 ) ;
F_63 ( V_203 ) ;
F_63 ( V_204 ) ;
F_63 ( V_205 ) ;
F_63 ( V_206 ) ;
F_63 ( V_207 ) ;
F_63 ( V_208 ) ;
F_63 ( V_209 ) ;
F_63 ( V_210 ) ;
F_63 ( V_211 ) ;
F_63 ( V_212 ) ;
#ifdef F_64
F_63 ( V_213 ) ;
#endif
#ifdef F_65
F_63 ( V_214 ) ;
#endif
#ifdef F_66
F_63 ( V_215 ) ;
#endif
default: break;
}
return F_18 ( V_39 , V_6 , L_7 , V_183 ) ;
}
static int F_67 ( const void * V_20 , const void * V_216 )
{
const struct V_217 * V_218 = V_216 ;
return strcmp ( V_20 , V_218 -> V_20 ) ;
}
static struct V_217 * F_68 ( const char * V_20 )
{
const int V_219 = F_69 ( V_220 ) ;
return bsearch ( V_20 , V_220 , V_219 , sizeof( struct V_217 ) , F_67 ) ;
}
static T_1 F_70 ( unsigned long V_221 , V_67 * V_222 )
{
double V_223 = ( double ) V_221 / V_224 ;
T_1 V_52 = fprintf ( V_222 , L_21 ) ;
if ( V_223 >= 1.0 )
V_52 += F_71 ( V_222 , V_225 , L_22 , V_223 ) ;
else if ( V_223 >= 0.01 )
V_52 += F_71 ( V_222 , V_226 , L_22 , V_223 ) ;
else
V_52 += F_71 ( V_222 , V_227 , L_22 , V_223 ) ;
return V_52 + fprintf ( V_222 , L_23 ) ;
}
static struct V_228 * F_72 ( void )
{
struct V_228 * V_229 = F_73 ( sizeof( struct V_228 ) ) ;
if ( V_229 )
V_229 -> V_230 . V_231 = - 1 ;
V_229 -> V_232 = F_74 ( NULL ) ;
return V_229 ;
}
static struct V_228 * F_75 ( struct V_233 * V_233 , V_67 * V_222 )
{
struct V_228 * V_229 ;
if ( V_233 == NULL )
goto V_234;
if ( F_76 ( V_233 ) == NULL )
F_77 ( V_233 , F_72 () ) ;
if ( F_76 ( V_233 ) == NULL )
goto V_234;
V_229 = F_76 ( V_233 ) ;
++ V_229 -> V_235 ;
return V_229 ;
V_234:
F_71 ( V_222 , V_225 ,
L_24 ) ;
return NULL ;
}
static int F_78 ( struct V_233 * V_233 , int V_50 , const char * V_236 )
{
struct V_228 * V_229 = F_76 ( V_233 ) ;
if ( V_50 > V_229 -> V_230 . V_231 ) {
char * * V_237 = realloc ( V_229 -> V_230 . V_238 , ( V_50 + 1 ) * sizeof( char * ) ) ;
if ( V_237 == NULL )
return - 1 ;
if ( V_229 -> V_230 . V_231 != - 1 ) {
memset ( V_237 + V_229 -> V_230 . V_231 + 1 , 0 ,
( V_50 - V_229 -> V_230 . V_231 ) * sizeof( char * ) ) ;
} else {
memset ( V_237 , 0 , ( V_50 + 1 ) * sizeof( char * ) ) ;
}
V_229 -> V_230 . V_238 = V_237 ;
V_229 -> V_230 . V_231 = V_50 ;
}
V_229 -> V_230 . V_238 [ V_50 ] = F_79 ( V_236 ) ;
return V_229 -> V_230 . V_238 [ V_50 ] != NULL ? 0 : - 1 ;
}
static int F_80 ( struct V_233 * V_233 , int V_50 )
{
char V_239 [ V_240 ] , V_236 [ V_240 ] ;
struct V_241 V_242 ;
int V_33 ;
if ( V_233 -> V_243 == V_233 -> V_244 ) {
F_18 ( V_239 , sizeof( V_239 ) ,
L_25 , V_233 -> V_243 , V_50 ) ;
} else {
F_18 ( V_239 , sizeof( V_239 ) ,
L_26 , V_233 -> V_243 , V_233 -> V_244 , V_50 ) ;
}
if ( F_81 ( V_239 , & V_242 ) < 0 || V_242 . V_245 + 1 > ( V_246 ) sizeof( V_236 ) )
return - 1 ;
V_33 = F_82 ( V_239 , V_236 , sizeof( V_236 ) ) ;
if ( V_33 < 0 || V_33 > V_242 . V_245 )
return - 1 ;
V_236 [ V_33 ] = '\0' ;
return F_78 ( V_233 , V_50 , V_236 ) ;
}
static const char * F_83 ( struct V_233 * V_233 , int V_50 ,
struct V_247 * V_247 )
{
struct V_228 * V_229 = F_76 ( V_233 ) ;
if ( V_229 == NULL )
return NULL ;
if ( V_50 < 0 )
return NULL ;
if ( ( V_50 > V_229 -> V_230 . V_231 || V_229 -> V_230 . V_238 [ V_50 ] == NULL ) ) {
if ( ! V_247 -> V_248 )
return NULL ;
++ V_247 -> V_249 . V_250 ;
if ( F_80 ( V_233 , V_50 ) )
return NULL ;
}
return V_229 -> V_230 . V_238 [ V_50 ] ;
}
static T_1 F_22 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_18 ( V_39 , V_6 , L_6 , V_50 ) ;
const char * V_251 = F_83 ( V_42 -> V_233 , V_50 , V_42 -> V_247 ) ;
if ( V_251 )
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 , L_27 , V_251 ) ;
return V_52 ;
}
static T_1 F_84 ( char * V_39 , T_1 V_6 ,
struct V_41 * V_42 )
{
int V_50 = V_42 -> V_47 ;
T_1 V_52 = F_22 ( V_39 , V_6 , V_42 ) ;
struct V_228 * V_229 = F_76 ( V_42 -> V_233 ) ;
if ( V_229 && V_50 >= 0 && V_50 <= V_229 -> V_230 . V_231 )
F_8 ( & V_229 -> V_230 . V_238 [ V_50 ] ) ;
return V_52 ;
}
static bool F_85 ( struct V_247 * V_247 , double V_221 )
{
return V_221 < ( V_247 -> V_252 * V_224 ) ;
}
static T_1 F_86 ( struct V_247 * V_247 , T_5 V_253 , V_67 * V_222 )
{
double V_254 = ( double ) ( V_253 - V_247 -> V_255 ) / V_224 ;
return fprintf ( V_222 , L_28 , V_254 ) ;
}
static void F_87 ( int V_183 )
{
V_256 = true ;
V_257 = V_183 == V_258 ;
}
static T_1 F_88 ( struct V_247 * V_247 , struct V_233 * V_233 ,
T_5 V_223 , T_5 V_253 , V_67 * V_222 )
{
T_1 V_52 = F_86 ( V_247 , V_253 , V_222 ) ;
V_52 += F_70 ( V_223 , V_222 ) ;
if ( V_247 -> V_259 ) {
if ( V_247 -> V_260 )
V_52 += fprintf ( V_222 , L_29 , F_89 ( V_233 ) ) ;
V_52 += fprintf ( V_222 , L_30 , V_233 -> V_244 ) ;
}
return V_52 ;
}
static int F_90 ( struct V_247 * V_247 , struct V_261 * V_261 ,
union V_262 * V_263 , struct V_14 * V_15 )
{
int V_33 = 0 ;
switch ( V_263 -> V_264 . type ) {
case V_265 :
F_71 ( V_247 -> V_266 , V_225 ,
L_31 V_267 L_32 , V_263 -> V_268 . V_268 ) ;
V_33 = F_91 ( V_261 , V_263 , V_15 ) ;
default:
V_33 = F_92 ( V_261 , V_263 , V_15 ) ;
break;
}
return V_33 ;
}
static int F_93 ( struct V_269 * V_270 ,
union V_262 * V_263 ,
struct V_14 * V_15 ,
struct V_261 * V_261 )
{
struct V_247 * V_247 = F_94 ( V_270 , struct V_247 , V_270 ) ;
return F_90 ( V_247 , V_261 , V_263 , V_15 ) ;
}
static int F_95 ( struct V_247 * V_247 , struct V_29 * V_30 )
{
int V_271 = F_96 ( NULL ) ;
if ( V_271 )
return V_271 ;
V_247 -> V_272 = F_97 () ;
if ( V_247 -> V_272 == NULL )
return - V_26 ;
V_271 = F_98 ( V_247 -> V_272 , & V_247 -> V_270 , & V_247 -> V_273 . V_274 ,
V_30 -> V_275 , F_93 , false ,
V_247 -> V_273 . V_276 ) ;
if ( V_271 )
F_99 () ;
return V_271 ;
}
static int F_100 ( struct V_277 * V_278 )
{
struct V_3 * V_2 ;
int V_46 = 0 ;
V_278 -> V_279 = calloc ( V_278 -> V_280 , sizeof( void * ) ) ;
if ( V_278 -> V_279 == NULL )
return - 1 ;
if ( V_278 -> V_218 )
V_278 -> V_281 = V_278 -> V_218 -> V_281 ;
for ( V_2 = V_278 -> args ; V_2 ; V_2 = V_2 -> V_282 ) {
if ( V_278 -> V_218 && V_278 -> V_218 -> V_279 [ V_46 ] )
V_278 -> V_279 [ V_46 ] = V_278 -> V_218 -> V_279 [ V_46 ] ;
else if ( V_2 -> V_61 & V_283 )
V_278 -> V_279 [ V_46 ] = F_23 ;
++ V_46 ;
}
return 0 ;
}
static int F_101 ( struct V_247 * V_247 , int V_24 )
{
char V_284 [ 128 ] ;
struct V_277 * V_278 ;
const char * V_20 = F_102 ( V_24 , V_247 -> V_285 . V_261 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_24 > V_247 -> V_286 . V_231 ) {
struct V_277 * V_287 = realloc ( V_247 -> V_286 . V_238 , ( V_24 + 1 ) * sizeof( * V_278 ) ) ;
if ( V_287 == NULL )
return - 1 ;
if ( V_247 -> V_286 . V_231 != - 1 ) {
memset ( V_287 + V_247 -> V_286 . V_231 + 1 , 0 ,
( V_24 - V_247 -> V_286 . V_231 ) * sizeof( * V_278 ) ) ;
} else {
memset ( V_287 , 0 , ( V_24 + 1 ) * sizeof( * V_278 ) ) ;
}
V_247 -> V_286 . V_238 = V_287 ;
V_247 -> V_286 . V_231 = V_24 ;
}
V_278 = V_247 -> V_286 . V_238 + V_24 ;
V_278 -> V_20 = V_20 ;
if ( V_247 -> V_288 ) {
bool V_289 = F_103 ( V_247 -> V_288 , V_20 ) != NULL ;
if ( ! ( V_289 ^ V_247 -> V_290 ) ) {
V_278 -> V_291 = true ;
return 0 ;
}
}
V_278 -> V_218 = F_68 ( V_278 -> V_20 ) ;
snprintf ( V_284 , sizeof( V_284 ) , L_33 , V_278 -> V_20 ) ;
V_278 -> V_292 = F_104 ( L_2 , V_284 ) ;
if ( V_278 -> V_292 == NULL && V_278 -> V_218 && V_278 -> V_218 -> V_293 ) {
snprintf ( V_284 , sizeof( V_284 ) , L_33 , V_278 -> V_218 -> V_293 ) ;
V_278 -> V_292 = F_104 ( L_2 , V_284 ) ;
}
if ( V_278 -> V_292 == NULL )
return - 1 ;
V_278 -> args = V_278 -> V_292 -> V_294 . V_295 ;
V_278 -> V_280 = V_278 -> V_292 -> V_294 . V_296 ;
if ( V_278 -> args && strcmp ( V_278 -> args -> V_20 , L_34 ) == 0 ) {
V_278 -> args = V_278 -> args -> V_282 ;
-- V_278 -> V_280 ;
}
V_278 -> V_297 = ! strcmp ( V_20 , L_35 ) || ! strcmp ( V_20 , L_36 ) ;
return F_100 ( V_278 ) ;
}
static int F_105 ( struct V_247 * V_247 )
{
int V_271 = 0 ;
struct V_298 * V_299 ;
F_106 (pos, trace->ev_qualifier) {
const char * V_278 = V_299 -> V_300 ;
if ( F_107 ( V_278 , V_247 -> V_285 . V_261 ) < 0 ) {
if ( V_271 == 0 ) {
fputs ( L_37 , V_247 -> V_266 ) ;
V_271 = - V_301 ;
} else {
fputs ( L_38 , V_247 -> V_266 ) ;
}
fputs ( V_278 , V_247 -> V_266 ) ;
}
}
if ( V_271 < 0 ) {
fputs ( L_39
L_40 , V_247 -> V_266 ) ;
}
return V_271 ;
}
static T_1 F_108 ( struct V_277 * V_278 , char * V_39 , T_1 V_6 ,
unsigned char * args , struct V_247 * V_247 ,
struct V_233 * V_233 )
{
T_1 V_52 = 0 ;
unsigned char * V_302 ;
unsigned long V_47 ;
if ( V_278 -> args != NULL ) {
struct V_3 * V_2 ;
T_6 V_303 = 1 ;
struct V_41 V_42 = {
. V_46 = 0 ,
. V_110 = 0 ,
. V_247 = V_247 ,
. V_233 = V_233 ,
} ;
for ( V_2 = V_278 -> args ; V_2 ;
V_2 = V_2 -> V_282 , ++ V_42 . V_46 , V_303 <<= 1 ) {
if ( V_42 . V_110 & V_303 )
continue;
V_302 = args + sizeof( unsigned long ) * V_42 . V_46 ;
memcpy ( & V_47 , V_302 , sizeof( V_47 ) ) ;
if ( V_47 == 0 &&
! ( V_278 -> V_279 &&
V_278 -> V_279 [ V_42 . V_46 ] == V_304 &&
V_278 -> V_281 [ V_42 . V_46 ] ) )
continue;
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_41 , V_52 ? L_38 : L_13 , V_2 -> V_20 ) ;
if ( V_278 -> V_279 && V_278 -> V_279 [ V_42 . V_46 ] ) {
V_42 . V_47 = V_47 ;
if ( V_278 -> V_281 )
V_42 . V_45 = V_278 -> V_281 [ V_42 . V_46 ] ;
V_52 += V_278 -> V_279 [ V_42 . V_46 ] ( V_39 + V_52 ,
V_6 - V_52 , & V_42 ) ;
} else {
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_42 , V_47 ) ;
}
}
} else {
int V_305 = 0 ;
while ( V_305 < 6 ) {
V_302 = args + sizeof( unsigned long ) * V_305 ;
memcpy ( & V_47 , V_302 , sizeof( V_47 ) ) ;
V_52 += F_18 ( V_39 + V_52 , V_6 - V_52 ,
L_43 ,
V_52 ? L_38 : L_13 , V_305 , V_47 ) ;
++ V_305 ;
}
}
return V_52 ;
}
static struct V_277 * F_109 ( struct V_247 * V_247 ,
struct V_18 * V_19 , int V_24 )
{
if ( V_24 < 0 ) {
if ( V_306 > 1 ) {
static T_5 T_2 ;
fprintf ( V_247 -> V_266 , L_44 V_267 L_45 ,
V_24 , F_110 ( V_19 ) , ++ T_2 ) ;
}
return NULL ;
}
if ( ( V_24 > V_247 -> V_286 . V_231 || V_247 -> V_286 . V_238 [ V_24 ] . V_20 == NULL ) &&
F_101 ( V_247 , V_24 ) )
goto V_307;
if ( ( V_24 > V_247 -> V_286 . V_231 || V_247 -> V_286 . V_238 [ V_24 ] . V_20 == NULL ) )
goto V_307;
return & V_247 -> V_286 . V_238 [ V_24 ] ;
V_307:
if ( V_306 ) {
fprintf ( V_247 -> V_266 , L_46 , V_24 ) ;
if ( V_24 <= V_247 -> V_286 . V_231 && V_247 -> V_286 . V_238 [ V_24 ] . V_20 != NULL )
fprintf ( V_247 -> V_266 , L_47 , V_247 -> V_286 . V_238 [ V_24 ] . V_20 ) ;
fputs ( L_48 , V_247 -> V_266 ) ;
}
return NULL ;
}
static void F_111 ( struct V_228 * V_229 ,
int V_24 , struct V_14 * V_15 )
{
struct V_308 * V_309 ;
struct V_249 * V_249 ;
T_5 V_223 = 0 ;
V_309 = F_112 ( V_229 -> V_232 , V_24 ) ;
if ( V_309 == NULL )
return;
V_249 = V_309 -> V_21 ;
if ( V_249 == NULL ) {
V_249 = malloc ( sizeof( struct V_249 ) ) ;
if ( V_249 == NULL )
return;
F_113 ( V_249 ) ;
V_309 -> V_21 = V_249 ;
}
if ( V_229 -> V_310 && V_15 -> time > V_229 -> V_310 )
V_223 = V_15 -> time - V_229 -> V_310 ;
F_114 ( V_249 , V_223 ) ;
}
static int F_115 ( struct V_247 * V_247 , struct V_14 * V_15 )
{
struct V_228 * V_229 ;
T_5 V_223 ;
T_1 V_52 ;
if ( V_247 -> V_311 == NULL )
return 0 ;
V_229 = F_76 ( V_247 -> V_311 ) ;
if ( ! V_229 -> V_312 )
return 0 ;
V_223 = V_15 -> time - V_229 -> V_310 ;
V_52 = F_88 ( V_247 , V_247 -> V_311 , V_223 , V_15 -> time , V_247 -> V_266 ) ;
V_52 += fprintf ( V_247 -> V_266 , L_49 , V_229 -> V_313 ) ;
V_229 -> V_312 = false ;
return V_52 ;
}
static int F_116 ( struct V_247 * V_247 , struct V_18 * V_19 ,
union V_262 * V_263 V_314 ,
struct V_14 * V_15 )
{
char * V_315 ;
void * args ;
T_1 V_52 = 0 ;
struct V_233 * V_233 ;
int V_24 = F_117 ( V_19 , V_24 , V_15 ) , V_271 = - 1 ;
struct V_277 * V_278 = F_109 ( V_247 , V_19 , V_24 ) ;
struct V_228 * V_229 ;
if ( V_278 == NULL )
return - 1 ;
if ( V_278 -> V_291 )
return 0 ;
V_233 = F_118 ( V_247 -> V_272 , V_15 -> V_316 , V_15 -> V_244 ) ;
V_229 = F_75 ( V_233 , V_247 -> V_266 ) ;
if ( V_229 == NULL )
goto V_317;
args = F_119 ( V_19 , args , V_15 ) ;
if ( V_229 -> V_313 == NULL ) {
V_229 -> V_313 = malloc ( 1024 ) ;
if ( ! V_229 -> V_313 )
goto V_317;
}
if ( ! V_247 -> V_318 )
F_115 ( V_247 , V_15 ) ;
V_229 -> V_310 = V_15 -> time ;
V_315 = V_229 -> V_313 ;
V_52 += F_18 ( V_315 + V_52 , 1024 - V_52 , L_50 , V_278 -> V_20 ) ;
V_52 += F_108 ( V_278 , V_315 + V_52 , 1024 - V_52 ,
args , V_247 , V_233 ) ;
if ( V_278 -> V_297 ) {
if ( ! V_247 -> V_252 && ! V_247 -> V_318 ) {
F_88 ( V_247 , V_233 , 1 , V_15 -> time , V_247 -> V_266 ) ;
fprintf ( V_247 -> V_266 , L_51 , V_229 -> V_313 ) ;
}
} else
V_229 -> V_312 = true ;
if ( V_247 -> V_311 != V_233 ) {
F_120 ( V_247 -> V_311 ) ;
V_247 -> V_311 = F_121 ( V_233 ) ;
}
V_271 = 0 ;
V_317:
F_120 ( V_233 ) ;
return V_271 ;
}
static int F_122 ( struct V_247 * V_247 , struct V_18 * V_19 ,
union V_262 * V_263 V_314 ,
struct V_14 * V_15 )
{
long V_33 ;
T_5 V_223 = 0 ;
struct V_233 * V_233 ;
int V_24 = F_117 ( V_19 , V_24 , V_15 ) , V_271 = - 1 ;
struct V_277 * V_278 = F_109 ( V_247 , V_19 , V_24 ) ;
struct V_228 * V_229 ;
if ( V_278 == NULL )
return - 1 ;
if ( V_278 -> V_291 )
return 0 ;
V_233 = F_118 ( V_247 -> V_272 , V_15 -> V_316 , V_15 -> V_244 ) ;
V_229 = F_75 ( V_233 , V_247 -> V_266 ) ;
if ( V_229 == NULL )
goto V_317;
if ( V_247 -> V_319 )
F_111 ( V_229 , V_24 , V_15 ) ;
V_33 = F_117 ( V_19 , V_33 , V_15 ) ;
if ( V_24 == V_247 -> V_285 . V_320 && V_33 >= 0 && V_247 -> V_321 ) {
F_78 ( V_233 , V_33 , V_247 -> V_321 ) ;
V_247 -> V_321 = NULL ;
++ V_247 -> V_249 . V_322 ;
}
V_229 -> V_323 = V_15 -> time ;
if ( V_229 -> V_310 ) {
V_223 = V_15 -> time - V_229 -> V_310 ;
if ( F_85 ( V_247 , V_223 ) )
goto V_36;
} else if ( V_247 -> V_252 )
goto V_36;
if ( V_247 -> V_318 )
goto V_36;
F_88 ( V_247 , V_233 , V_223 , V_15 -> time , V_247 -> V_266 ) ;
if ( V_229 -> V_312 ) {
fprintf ( V_247 -> V_266 , L_52 , V_229 -> V_313 ) ;
} else {
fprintf ( V_247 -> V_266 , L_53 ) ;
F_71 ( V_247 -> V_266 , V_226 , L_54 ) ;
fprintf ( V_247 -> V_266 , L_55 , V_278 -> V_20 ) ;
}
if ( V_278 -> V_218 == NULL ) {
V_324:
fprintf ( V_247 -> V_266 , L_56 , V_33 ) ;
} else if ( V_33 < 0 && V_278 -> V_218 -> V_325 ) {
char V_39 [ V_326 ] ;
const char * V_327 = F_123 ( - V_33 , V_39 , sizeof( V_39 ) ) ,
* V_328 = F_124 ( - V_33 ) ;
fprintf ( V_247 -> V_266 , L_57 , V_328 , V_327 ) ;
} else if ( V_33 == 0 && V_278 -> V_218 -> V_329 )
fprintf ( V_247 -> V_266 , L_58 ) ;
else if ( V_278 -> V_218 -> V_330 )
fprintf ( V_247 -> V_266 , L_59 , V_33 ) ;
else
goto V_324;
fputc ( '\n' , V_247 -> V_266 ) ;
V_36:
V_229 -> V_312 = false ;
V_271 = 0 ;
V_317:
F_120 ( V_233 ) ;
return V_271 ;
}
static int F_125 ( struct V_247 * V_247 , struct V_18 * V_19 ,
union V_262 * V_263 V_314 ,
struct V_14 * V_15 )
{
V_247 -> V_321 = F_126 ( V_19 , V_15 , L_60 ) ;
return 0 ;
}
static int F_127 ( struct V_247 * V_247 , struct V_18 * V_19 ,
union V_262 * V_263 V_314 ,
struct V_14 * V_15 )
{
T_5 V_331 = F_128 ( V_19 , V_15 , L_61 ) ;
double V_332 = ( double ) V_331 / V_224 ;
struct V_233 * V_233 = F_118 ( V_247 -> V_272 ,
V_15 -> V_316 ,
V_15 -> V_244 ) ;
struct V_228 * V_229 = F_75 ( V_233 , V_247 -> V_266 ) ;
if ( V_229 == NULL )
goto V_333;
V_229 -> V_332 += V_332 ;
V_247 -> V_332 += V_332 ;
F_120 ( V_233 ) ;
return 0 ;
V_333:
fprintf ( V_247 -> V_266 , L_62 V_267 L_63 V_267 L_64 ,
V_19 -> V_20 ,
F_129 ( V_19 , V_15 , L_65 ) ,
( V_334 ) F_128 ( V_19 , V_15 , L_66 ) ,
V_331 ,
F_128 ( V_19 , V_15 , L_67 ) ) ;
F_120 ( V_233 ) ;
return 0 ;
}
static int F_130 ( struct V_247 * V_247 , struct V_18 * V_19 ,
union V_262 * V_263 V_314 ,
struct V_14 * V_15 )
{
F_115 ( V_247 , V_15 ) ;
F_86 ( V_247 , V_15 -> time , V_247 -> V_266 ) ;
if ( V_247 -> V_335 )
fprintf ( V_247 -> V_266 , L_68 ) ;
fprintf ( V_247 -> V_266 , L_69 , V_19 -> V_20 ) ;
if ( V_19 -> V_292 ) {
F_131 ( V_19 -> V_292 , V_15 -> V_336 ,
V_15 -> V_16 , V_15 -> V_337 ,
V_247 -> V_266 ) ;
}
fprintf ( V_247 -> V_266 , L_64 ) ;
return 0 ;
}
static void F_132 ( V_67 * V_338 , struct V_14 * V_15 ,
struct V_339 * V_340 ,
bool V_341 , bool V_342 )
{
if ( ( V_306 || V_341 ) && V_340 -> V_343 )
fprintf ( V_338 , L_70 , V_340 -> V_343 -> V_344 -> V_345 ) ;
if ( ( V_306 || V_342 ) && V_340 -> V_346 )
fprintf ( V_338 , L_71 V_347 , V_340 -> V_346 -> V_20 ,
V_340 -> V_348 - V_340 -> V_346 -> V_349 ) ;
else if ( V_340 -> V_343 )
fprintf ( V_338 , L_72 V_347 , V_340 -> V_348 ) ;
else
fprintf ( V_338 , L_72 V_347 , V_15 -> V_348 ) ;
}
static int F_133 ( struct V_247 * V_247 ,
struct V_18 * V_19 ,
union V_262 * V_263 ,
struct V_14 * V_15 )
{
struct V_233 * V_233 ;
T_6 V_350 = V_263 -> V_264 . V_351 & V_352 ;
struct V_339 V_340 ;
char V_353 = 'd' ;
struct V_228 * V_229 ;
int V_271 = - 1 ;
V_233 = F_118 ( V_247 -> V_272 , V_15 -> V_316 , V_15 -> V_244 ) ;
V_229 = F_75 ( V_233 , V_247 -> V_266 ) ;
if ( V_229 == NULL )
goto V_317;
if ( V_19 -> V_354 . V_355 == V_356 )
V_229 -> V_357 ++ ;
else
V_229 -> V_358 ++ ;
if ( V_247 -> V_318 )
goto V_36;
F_134 ( V_233 , V_350 , V_359 ,
V_15 -> V_360 , & V_340 ) ;
F_88 ( V_247 , V_233 , 0 , V_15 -> time , V_247 -> V_266 ) ;
fprintf ( V_247 -> V_266 , L_73 ,
V_19 -> V_354 . V_355 == V_356 ?
L_74 : L_75 ) ;
F_132 ( V_247 -> V_266 , V_15 , & V_340 , false , true ) ;
fprintf ( V_247 -> V_266 , L_76 ) ;
F_134 ( V_233 , V_350 , V_361 ,
V_15 -> V_348 , & V_340 ) ;
if ( ! V_340 . V_343 ) {
F_134 ( V_233 , V_350 ,
V_359 , V_15 -> V_348 , & V_340 ) ;
if ( V_340 . V_343 )
V_353 = 'x' ;
else
V_353 = '?' ;
}
F_132 ( V_247 -> V_266 , V_15 , & V_340 , true , false ) ;
fprintf ( V_247 -> V_266 , L_77 , V_353 , V_340 . V_362 ) ;
V_36:
V_271 = 0 ;
V_317:
F_120 ( V_233 ) ;
return V_271 ;
}
static bool F_135 ( struct V_247 * V_247 , struct V_14 * V_15 )
{
if ( ( V_247 -> V_363 && F_136 ( V_247 -> V_363 , V_15 -> V_316 ) ) ||
( V_247 -> V_364 && F_136 ( V_247 -> V_364 , V_15 -> V_244 ) ) )
return false ;
if ( V_247 -> V_363 || V_247 -> V_364 )
return true ;
return false ;
}
static int F_137 ( struct V_269 * V_270 ,
union V_262 * V_263 ,
struct V_14 * V_15 ,
struct V_18 * V_19 ,
struct V_261 * V_261 V_314 )
{
struct V_247 * V_247 = F_94 ( V_270 , struct V_247 , V_270 ) ;
int V_271 = 0 ;
T_7 V_22 = V_19 -> V_22 ;
if ( F_135 ( V_247 , V_15 ) )
return 0 ;
if ( ! V_247 -> V_365 && V_247 -> V_255 == 0 )
V_247 -> V_255 = V_15 -> time ;
if ( V_22 ) {
++ V_247 -> V_235 ;
V_22 ( V_247 , V_19 , V_263 , V_15 ) ;
}
return V_271 ;
}
static int F_138 ( struct V_247 * V_247 )
{
if ( V_247 -> V_273 . V_274 . V_316 ) {
V_247 -> V_363 = F_74 ( V_247 -> V_273 . V_274 . V_316 ) ;
if ( V_247 -> V_363 == NULL ) {
F_139 ( L_78 ) ;
return - V_301 ;
}
}
if ( V_247 -> V_273 . V_274 . V_244 ) {
V_247 -> V_364 = F_74 ( V_247 -> V_273 . V_274 . V_244 ) ;
if ( V_247 -> V_364 == NULL ) {
F_139 ( L_79 ) ;
return - V_301 ;
}
}
return 0 ;
}
static int F_140 ( struct V_247 * V_247 , int V_366 , const char * * V_367 )
{
unsigned int V_368 , V_305 , V_369 ;
const char * * V_370 ;
const char * const V_371 [] = {
L_80 ,
L_81 ,
L_82 , L_83 ,
L_84 , L_85 ,
} ;
const char * const V_372 [] = { L_86 , } ;
unsigned int V_373 = F_69 ( V_372 ) ;
const char * const V_374 [] = { L_86 , L_87 } ;
unsigned int V_375 = F_69 ( V_374 ) ;
const char * const V_376 [] = { L_86 , L_88 } ;
unsigned int V_377 = F_69 ( V_376 ) ;
V_368 = F_69 ( V_371 ) + V_373 + 1 +
V_375 + V_377 + V_366 ;
V_370 = calloc ( V_368 + 1 , sizeof( char * ) ) ;
if ( V_370 == NULL )
return - V_26 ;
V_369 = 0 ;
for ( V_305 = 0 ; V_305 < F_69 ( V_371 ) ; V_305 ++ )
V_370 [ V_369 ++ ] = V_371 [ V_305 ] ;
if ( V_247 -> V_335 ) {
for ( V_305 = 0 ; V_305 < V_373 ; V_305 ++ )
V_370 [ V_369 ++ ] = V_372 [ V_305 ] ;
if ( F_141 ( L_89 ) )
V_370 [ V_369 ++ ] = L_90 ;
else if ( F_141 ( L_91 ) )
V_370 [ V_369 ++ ] = L_92 ;
else {
F_139 ( L_93 ) ;
return - 1 ;
}
}
if ( V_247 -> V_378 & V_379 )
for ( V_305 = 0 ; V_305 < V_375 ; V_305 ++ )
V_370 [ V_369 ++ ] = V_374 [ V_305 ] ;
if ( V_247 -> V_378 & V_380 )
for ( V_305 = 0 ; V_305 < V_377 ; V_305 ++ )
V_370 [ V_369 ++ ] = V_376 [ V_305 ] ;
for ( V_305 = 0 ; V_305 < ( unsigned int ) V_366 ; V_305 ++ )
V_370 [ V_369 ++ ] = V_367 [ V_305 ] ;
return F_142 ( V_369 , V_370 , NULL ) ;
}
static void F_143 ( struct V_29 * V_30 )
{
struct V_18 * V_19 = F_13 ( L_94 , L_95 ) ;
if ( V_19 == NULL )
return;
if ( F_5 ( V_19 , L_60 ) == NULL ) {
F_9 ( V_19 ) ;
return;
}
V_19 -> V_22 = F_125 ;
F_16 ( V_30 , V_19 ) ;
}
static int F_144 ( struct V_29 * V_30 ,
T_5 V_355 )
{
struct V_18 * V_19 ;
struct V_381 V_354 = {
. type = V_382 ,
. V_383 = 1 ,
} ;
V_354 . V_355 = V_355 ;
V_354 . V_384 = 1 ;
F_145 ( & V_354 ) ;
V_19 = F_146 ( & V_354 ) ;
if ( ! V_19 )
return - V_26 ;
V_19 -> V_22 = F_133 ;
F_16 ( V_30 , V_19 ) ;
return 0 ;
}
static void F_147 ( struct V_247 * V_247 , union V_262 * V_263 , struct V_14 * V_15 )
{
const T_8 type = V_263 -> V_264 . type ;
struct V_18 * V_19 ;
if ( ! V_247 -> V_365 && V_247 -> V_255 == 0 )
V_247 -> V_255 = V_15 -> time ;
if ( type != V_385 ) {
F_90 ( V_247 , V_247 -> V_272 , V_263 , V_15 ) ;
return;
}
V_19 = F_148 ( V_247 -> V_30 , V_15 -> V_24 ) ;
if ( V_19 == NULL ) {
fprintf ( V_247 -> V_266 , L_96 V_267 L_97 , V_15 -> V_24 ) ;
return;
}
if ( V_19 -> V_354 . type == V_386 &&
V_15 -> V_16 == NULL ) {
fprintf ( V_247 -> V_266 , L_98 ,
F_110 ( V_19 ) , V_15 -> V_244 ,
V_15 -> V_336 , V_15 -> V_337 ) ;
} else {
T_7 V_22 = V_19 -> V_22 ;
V_22 ( V_247 , V_19 , V_263 , V_15 ) ;
}
}
static int F_149 ( struct V_247 * V_247 , int V_366 , const char * * V_367 )
{
struct V_29 * V_30 = V_247 -> V_30 ;
int V_271 = - 1 , V_305 ;
unsigned long V_387 ;
const bool V_388 = V_366 > 0 ;
bool V_389 = false ;
V_247 -> V_248 = true ;
if ( V_247 -> V_335 &&
F_14 ( V_30 , F_116 ,
F_122 ) )
goto V_390;
if ( V_247 -> V_335 )
F_143 ( V_30 ) ;
if ( ( V_247 -> V_378 & V_379 ) &&
F_144 ( V_30 , V_356 ) ) {
goto V_391;
}
if ( ( V_247 -> V_378 & V_380 ) &&
F_144 ( V_30 , V_392 ) )
goto V_391;
if ( V_247 -> V_393 &&
F_150 ( V_30 , L_99 , L_100 ,
F_127 ) )
goto V_394;
V_271 = F_151 ( V_30 , & V_247 -> V_273 . V_274 ) ;
if ( V_271 < 0 ) {
fprintf ( V_247 -> V_266 , L_101 ) ;
goto V_395;
}
V_271 = F_95 ( V_247 , V_30 ) ;
if ( V_271 < 0 ) {
fprintf ( V_247 -> V_266 , L_102 ) ;
goto V_395;
}
F_152 ( V_30 , & V_247 -> V_273 ) ;
signal ( V_396 , F_87 ) ;
signal ( V_258 , F_87 ) ;
if ( V_388 ) {
V_271 = F_153 ( V_30 , & V_247 -> V_273 . V_274 ,
V_367 , false , NULL ) ;
if ( V_271 < 0 ) {
fprintf ( V_247 -> V_266 , L_103 ) ;
goto V_395;
}
}
V_271 = F_154 ( V_30 ) ;
if ( V_271 < 0 )
goto V_397;
if ( V_247 -> V_398 . V_399 > 0 )
V_271 = F_155 ( V_30 , V_247 -> V_398 . V_399 , V_247 -> V_398 . V_49 ) ;
else if ( F_156 ( V_30 -> V_275 , 0 ) == - 1 )
V_271 = F_157 ( V_30 , F_158 () ) ;
if ( V_271 < 0 ) {
printf ( L_104 , - V_271 , strerror ( - V_271 ) ) ;
exit ( 1 ) ;
}
V_271 = F_159 ( V_30 , V_247 -> V_273 . V_400 , false ) ;
if ( V_271 < 0 )
goto V_401;
if ( ! F_160 ( & V_247 -> V_273 . V_274 ) )
F_161 ( V_30 ) ;
if ( V_388 )
F_162 ( V_30 ) ;
V_247 -> V_259 = F_156 ( V_30 -> V_275 , 0 ) == - 1 ||
V_30 -> V_275 -> V_399 > 1 ||
F_163 ( V_30 ) -> V_354 . V_402 ;
V_403:
V_387 = V_247 -> V_235 ;
for ( V_305 = 0 ; V_305 < V_30 -> V_404 ; V_305 ++ ) {
union V_262 * V_263 ;
while ( ( V_263 = F_164 ( V_30 , V_305 ) ) != NULL ) {
struct V_14 V_15 ;
++ V_247 -> V_235 ;
V_271 = F_165 ( V_30 , V_263 , & V_15 ) ;
if ( V_271 ) {
fprintf ( V_247 -> V_266 , L_105 , V_271 ) ;
goto V_405;
}
F_147 ( V_247 , V_263 , & V_15 ) ;
V_405:
F_166 ( V_30 , V_305 ) ;
if ( V_257 )
goto V_406;
if ( V_256 && ! V_389 ) {
F_167 ( V_30 ) ;
V_389 = true ;
}
}
}
if ( V_247 -> V_235 == V_387 ) {
int V_329 = V_256 ? 100 : - 1 ;
if ( ! V_389 && F_168 ( V_30 , V_329 ) > 0 ) {
if ( F_169 ( V_30 , V_407 | V_408 ) == 0 )
V_389 = true ;
goto V_403;
}
} else {
goto V_403;
}
V_406:
F_170 ( V_247 -> V_311 ) ;
F_167 ( V_30 ) ;
if ( ! V_271 ) {
if ( V_247 -> V_319 )
F_171 ( V_247 , V_247 -> V_266 ) ;
if ( V_247 -> V_409 ) {
fprintf ( V_247 -> V_266 , L_106
L_107 V_267 L_108
L_109 V_267 L_108 ,
V_247 -> V_249 . V_322 ,
V_247 -> V_249 . V_250 ) ;
}
}
V_395:
F_172 ( V_30 ) ;
V_247 -> V_30 = NULL ;
V_247 -> V_248 = false ;
return V_271 ;
{
char V_410 [ V_411 ] ;
V_394:
F_173 ( V_412 , V_410 , sizeof( V_410 ) , L_99 , L_100 ) ;
goto V_413;
V_390:
F_173 ( V_412 , V_410 , sizeof( V_410 ) , L_1 , L_110 ) ;
goto V_413;
V_401:
F_174 ( V_30 , V_412 , V_410 , sizeof( V_410 ) ) ;
goto V_413;
V_397:
F_175 ( V_30 , V_412 , V_410 , sizeof( V_410 ) ) ;
V_413:
fprintf ( V_247 -> V_266 , L_111 , V_410 ) ;
goto V_395;
}
V_391:
fprintf ( V_247 -> V_266 , L_112 ) ;
goto V_395;
}
static int F_176 ( struct V_247 * V_247 )
{
const struct V_414 V_415 [] = {
{ L_113 , F_125 , } ,
} ;
struct V_416 V_417 = {
. V_251 = V_418 ,
. V_155 = V_419 ,
. V_420 = V_247 -> V_420 ,
} ;
struct V_421 * V_422 ;
struct V_18 * V_19 ;
int V_271 = - 1 ;
V_247 -> V_270 . V_15 = F_137 ;
V_247 -> V_270 . V_423 = V_424 ;
V_247 -> V_270 . V_425 = V_426 ;
V_247 -> V_270 . V_427 = V_428 ;
V_247 -> V_270 . exit = V_429 ;
V_247 -> V_270 . V_430 = V_431 ;
V_247 -> V_270 . V_354 = V_432 ;
V_247 -> V_270 . V_433 = V_434 ;
V_247 -> V_270 . V_435 = V_436 ;
V_247 -> V_270 . V_437 = true ;
V_247 -> V_270 . V_438 = true ;
V_247 -> V_259 = true ;
V_422 = F_177 ( & V_417 , false , & V_247 -> V_270 ) ;
if ( V_422 == NULL )
return - 1 ;
if ( F_96 ( & V_422 -> V_264 . V_439 ) < 0 )
goto V_36;
V_247 -> V_272 = & V_422 -> V_440 . V_272 ;
V_271 = F_178 ( V_422 , V_415 ) ;
if ( V_271 )
goto V_36;
V_19 = F_179 ( V_422 -> V_30 ,
L_89 ) ;
if ( V_19 == NULL )
V_19 = F_179 ( V_422 -> V_30 ,
L_91 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_116 ) < 0 ||
F_15 ( V_19 , args ) ) ) {
F_139 ( L_114 ) ;
goto V_36;
}
V_19 = F_179 ( V_422 -> V_30 ,
L_115 ) ;
if ( V_19 == NULL )
V_19 = F_179 ( V_422 -> V_30 ,
L_116 ) ;
if ( V_19 &&
( F_10 ( V_19 , F_122 ) < 0 ||
F_11 ( V_19 , V_33 ) ) ) {
F_139 ( L_117 ) ;
goto V_36;
}
F_180 (session->evlist, evsel) {
if ( V_19 -> V_354 . type == V_382 &&
( V_19 -> V_354 . V_355 == V_356 ||
V_19 -> V_354 . V_355 == V_392 ||
V_19 -> V_354 . V_355 == V_441 ) )
V_19 -> V_22 = F_133 ;
}
V_271 = F_138 ( V_247 ) ;
if ( V_271 != 0 )
goto V_36;
F_181 () ;
V_271 = F_182 ( V_422 ) ;
if ( V_271 )
F_139 ( L_118 , V_271 ) ;
else if ( V_247 -> V_319 )
F_171 ( V_247 , V_247 -> V_266 ) ;
V_36:
F_183 ( V_422 ) ;
return V_271 ;
}
static T_1 F_184 ( V_67 * V_222 )
{
T_1 V_52 ;
V_52 = fprintf ( V_222 , L_119 ) ;
return V_52 ;
}
static T_1 F_185 ( struct V_228 * V_229 ,
struct V_247 * V_247 , V_67 * V_222 )
{
struct V_249 * V_249 ;
T_1 V_52 = 0 ;
struct V_277 * V_278 ;
struct V_308 * V_309 = F_186 ( V_229 -> V_232 ) ;
if ( V_309 == NULL )
return 0 ;
V_52 += fprintf ( V_222 , L_108 ) ;
V_52 += fprintf ( V_222 , L_120 ) ;
V_52 += fprintf ( V_222 , L_121 ) ;
V_52 += fprintf ( V_222 , L_122 ) ;
while ( V_309 ) {
V_249 = V_309 -> V_21 ;
if ( V_249 ) {
double V_442 = ( double ) ( V_249 -> V_442 ) / V_224 ;
double V_231 = ( double ) ( V_249 -> V_231 ) / V_224 ;
double V_443 = F_187 ( V_249 ) ;
double V_444 ;
T_5 T_2 = ( T_5 ) V_249 -> T_2 ;
V_444 = V_443 ? 100.0 * F_188 ( V_249 ) / V_443 : 0.0 ;
V_443 /= V_224 ;
V_278 = & V_247 -> V_286 . V_238 [ V_309 -> V_305 ] ;
V_52 += fprintf ( V_222 , L_123 , V_278 -> V_20 ) ;
V_52 += fprintf ( V_222 , L_124 V_267 L_125 ,
T_2 , V_442 , V_443 ) ;
V_52 += fprintf ( V_222 , L_126 , V_231 , V_444 ) ;
}
V_309 = F_189 ( V_309 ) ;
}
V_52 += fprintf ( V_222 , L_127 ) ;
return V_52 ;
}
static int F_190 ( struct V_233 * V_233 , void * V_21 )
{
struct V_445 * V_446 = V_21 ;
V_67 * V_222 = V_446 -> V_222 ;
T_1 V_52 = V_446 -> V_52 ;
struct V_247 * V_247 = V_446 -> V_247 ;
struct V_228 * V_229 = F_76 ( V_233 ) ;
double V_447 ;
if ( V_229 == NULL )
return 0 ;
V_447 = ( double ) V_229 -> V_235 / V_247 -> V_235 * 100.0 ;
V_52 += fprintf ( V_222 , L_128 , F_89 ( V_233 ) , V_233 -> V_244 ) ;
V_52 += fprintf ( V_222 , L_129 , V_229 -> V_235 ) ;
V_52 += fprintf ( V_222 , L_130 , V_447 ) ;
if ( V_229 -> V_357 )
V_52 += fprintf ( V_222 , L_131 , V_229 -> V_357 ) ;
if ( V_229 -> V_358 )
V_52 += fprintf ( V_222 , L_132 , V_229 -> V_358 ) ;
V_52 += fprintf ( V_222 , L_133 , V_229 -> V_332 ) ;
V_52 += F_185 ( V_229 , V_247 , V_222 ) ;
V_446 -> V_52 += V_52 ;
return 0 ;
}
static T_1 F_171 ( struct V_247 * V_247 , V_67 * V_222 )
{
struct V_445 V_446 = {
. V_222 = V_222 ,
. V_247 = V_247
} ;
V_446 . V_52 = F_184 ( V_222 ) ;
F_191 ( V_247 -> V_272 , F_190 , & V_446 ) ;
return V_446 . V_52 ;
}
static int F_192 ( const struct V_448 * V_449 , const char * V_450 ,
int T_9 V_314 )
{
struct V_247 * V_247 = V_449 -> V_451 ;
V_247 -> V_252 = atof ( V_450 ) ;
return 0 ;
}
static int F_193 ( const struct V_448 * V_449 , const char * V_450 ,
int T_9 V_314 )
{
int V_33 = - 1 ;
T_1 V_305 ;
struct V_247 * V_247 = V_449 -> V_451 ;
struct V_452 * V_453 = F_74 ( V_450 ) ;
if ( V_453 == NULL )
return - 1 ;
V_305 = V_247 -> V_398 . V_399 = F_194 ( V_453 ) + 1 ;
V_247 -> V_398 . V_49 = calloc ( V_305 , sizeof( V_334 ) ) ;
if ( V_247 -> V_398 . V_49 == NULL )
goto V_36;
V_247 -> V_398 . V_49 [ 0 ] = F_158 () ;
for ( V_305 = 1 ; V_305 < V_247 -> V_398 . V_399 ; ++ V_305 )
V_247 -> V_398 . V_49 [ V_305 ] = F_195 ( V_453 , V_305 - 1 ) -> V_305 ;
F_196 ( V_453 ) ;
V_33 = 0 ;
V_36:
return V_33 ;
}
static int F_197 ( struct V_247 * V_247 , const char * V_454 )
{
struct V_241 V_242 ;
if ( ! V_241 ( V_454 , & V_242 ) && V_242 . V_245 ) {
char V_455 [ V_240 ] ;
F_18 ( V_455 , sizeof( V_455 ) , L_134 , V_454 ) ;
F_198 ( V_455 ) ;
rename ( V_454 , V_455 ) ;
}
V_247 -> V_266 = fopen ( V_454 , L_135 ) ;
return V_247 -> V_266 == NULL ? - V_412 : 0 ;
}
static int F_199 ( const struct V_448 * V_449 , const char * V_450 ,
int T_9 V_314 )
{
int * V_378 = V_449 -> V_451 ;
if ( strcmp ( V_450 , L_136 ) == 0 )
* V_378 |= V_379 | V_380 ;
else if ( strcmp ( V_450 , L_74 ) == 0 )
* V_378 |= V_379 ;
else if ( strcmp ( V_450 , L_75 ) == 0 )
* V_378 |= V_380 ;
else
return - 1 ;
return 0 ;
}
static void F_200 ( struct V_29 * V_30 , void * V_22 )
{
struct V_18 * V_19 ;
F_180 (evlist, evsel)
V_19 -> V_22 = V_22 ;
}
int F_201 ( int V_366 , const char * * V_367 , const char * T_10 V_314 )
{
const char * V_456 [] = {
L_137 ,
L_138 ,
L_139 ,
L_140 ,
NULL
} ;
struct V_247 V_247 = {
. V_285 = {
. V_261 = F_202 () ,
. V_320 = F_107 ( L_141 , V_247 . V_285 . V_261 ) ,
} ,
. V_286 = {
. V_231 = - 1 ,
} ,
. V_273 = {
. V_274 = {
. V_457 = V_458 ,
. V_459 = true ,
} ,
. V_460 = V_458 ,
. V_461 = V_462 ,
. V_463 = true ,
. V_400 = V_458 ,
. V_276 = 500 ,
} ,
. V_266 = stdout ,
. V_260 = true ,
. V_335 = true ,
} ;
const char * V_464 = NULL ;
const char * V_465 = NULL ;
const struct V_448 V_466 [] = {
F_203 ( 0 , L_142 , & V_247 . V_30 , L_142 ,
L_143 ,
V_467 ) ,
F_204 ( 0 , L_65 , & V_247 . V_260 ,
L_144 ) ,
F_204 ( 0 , L_145 , & V_247 . V_409 , L_146 ) ,
F_205 ( 'e' , L_147 , & V_465 , L_147 , L_148 ) ,
F_205 ( 'o' , L_149 , & V_464 , L_150 , L_151 ) ,
F_205 ( 'i' , L_152 , & V_418 , L_150 , L_153 ) ,
F_205 ( 'p' , L_66 , & V_247 . V_273 . V_274 . V_316 , L_66 ,
L_154 ) ,
F_205 ( 't' , L_155 , & V_247 . V_273 . V_274 . V_244 , L_155 ,
L_156 ) ,
F_203 ( 0 , L_157 , & V_247 , L_158 ,
L_159 , F_193 ) ,
F_204 ( 'a' , L_160 , & V_247 . V_273 . V_274 . V_468 ,
L_161 ) ,
F_205 ( 'C' , L_162 , & V_247 . V_273 . V_274 . V_469 , L_162 ,
L_163 ) ,
F_204 ( 0 , L_164 , & V_247 . V_273 . V_470 ,
L_165 ) ,
F_203 ( 'm' , L_166 , & V_247 . V_273 . V_400 , L_167 ,
L_168 ,
V_471 ) ,
F_205 ( 'u' , L_169 , & V_247 . V_273 . V_274 . V_472 , L_170 ,
L_171 ) ,
F_203 ( 0 , L_172 , & V_247 , L_173 ,
L_174 ,
F_192 ) ,
F_204 ( 0 , L_99 , & V_247 . V_393 , L_175 ) ,
F_206 ( 'v' , L_176 , & V_306 , L_177 ) ,
F_204 ( 'T' , L_178 , & V_247 . V_365 ,
L_179 ) ,
F_204 ( 's' , L_180 , & V_247 . V_318 ,
L_181 ) ,
F_204 ( 'S' , L_182 , & V_247 . V_319 ,
L_183 ) ,
F_207 ( 'F' , L_184 , & V_247 . V_378 , L_185 ,
L_186 , F_199 , L_74 ) ,
F_204 ( 0 , L_2 , & V_247 . V_335 , L_187 ) ,
F_204 ( 'f' , L_188 , & V_247 . V_420 , L_189 ) ,
F_208 ( 0 , L_190 , & V_247 . V_273 . V_276 ,
L_191 ) ,
F_209 ()
} ;
const char * const V_473 [] = { L_80 , NULL } ;
int V_271 ;
char V_39 [ V_411 ] ;
signal ( V_474 , V_475 ) ;
signal ( V_476 , V_475 ) ;
V_247 . V_30 = F_210 () ;
if ( V_247 . V_30 == NULL ) {
F_139 ( L_112 ) ;
V_271 = - V_26 ;
goto V_36;
}
V_366 = F_211 ( V_366 , V_367 , V_466 , V_473 ,
V_456 , V_477 ) ;
if ( V_247 . V_378 ) {
V_247 . V_273 . V_478 = true ;
V_247 . V_273 . V_479 = true ;
}
if ( V_247 . V_30 -> V_48 > 0 )
F_200 ( V_247 . V_30 , F_130 ) ;
if ( ( V_366 >= 1 ) && ( strcmp ( V_367 [ 0 ] , L_80 ) == 0 ) )
return F_140 ( & V_247 , V_366 - 1 , & V_367 [ 1 ] ) ;
if ( V_247 . V_318 )
V_247 . V_319 = V_247 . V_318 ;
if ( ! V_247 . V_335 && ! V_247 . V_378 &&
V_247 . V_30 -> V_48 == 0 ) {
F_139 ( L_192 ) ;
return - 1 ;
}
if ( V_464 != NULL ) {
V_271 = F_197 ( & V_247 , V_464 ) ;
if ( V_271 < 0 ) {
perror ( L_193 ) ;
goto V_36;
}
}
if ( V_465 != NULL ) {
const char * V_300 = V_465 ;
V_247 . V_290 = * V_300 == '!' ;
if ( V_247 . V_290 )
++ V_300 ;
V_247 . V_288 = F_212 ( true , V_300 ) ;
if ( V_247 . V_288 == NULL ) {
fputs ( L_194 ,
V_247 . V_266 ) ;
V_271 = - V_26 ;
goto V_480;
}
V_271 = F_105 ( & V_247 ) ;
if ( V_271 )
goto V_480;
}
V_271 = F_213 ( & V_247 . V_273 . V_274 ) ;
if ( V_271 ) {
F_214 ( & V_247 . V_273 . V_274 , V_271 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_247 . V_266 , L_5 , V_39 ) ;
goto V_480;
}
V_271 = F_215 ( & V_247 . V_273 . V_274 ) ;
if ( V_271 ) {
F_214 ( & V_247 . V_273 . V_274 , V_271 , V_39 , sizeof( V_39 ) ) ;
fprintf ( V_247 . V_266 , L_5 , V_39 ) ;
goto V_480;
}
if ( ! V_366 && F_160 ( & V_247 . V_273 . V_274 ) )
V_247 . V_273 . V_274 . V_468 = true ;
if ( V_418 )
V_271 = F_176 ( & V_247 ) ;
else
V_271 = F_149 ( & V_247 , V_366 , V_367 ) ;
V_480:
if ( V_464 != NULL )
fclose ( V_247 . V_266 ) ;
V_36:
return V_271 ;
}
