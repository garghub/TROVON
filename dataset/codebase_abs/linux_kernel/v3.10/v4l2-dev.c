static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_11 = 0 ;
T_3 V_12 ;
V_11 = F_5 ( V_5 , 0 , & V_12 ) ;
if ( V_11 )
return V_11 ;
V_7 -> V_9 = V_12 ;
return V_10 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( int ) sizeof( V_7 -> V_13 ) , V_7 -> V_13 ) ;
}
static inline unsigned long * F_7 ( int V_14 )
{
int V_15 = ( V_14 > V_16 ) ? V_17 - 1 : V_14 ;
return V_18 [ V_15 ] ;
}
static inline unsigned long * F_7 ( int V_14 )
{
return V_18 [ V_14 ] ;
}
static inline void F_8 ( struct V_6 * V_7 )
{
F_9 ( V_7 -> V_19 , F_7 ( V_7 -> V_14 ) ) ;
}
static inline void F_10 ( struct V_6 * V_7 )
{
F_11 ( V_7 -> V_19 , F_7 ( V_7 -> V_14 ) ) ;
}
static inline int F_12 ( struct V_6 * V_7 , int V_20 , int V_21 )
{
return F_13 ( F_7 ( V_7 -> V_14 ) , V_21 , V_20 ) ;
}
struct V_6 * F_14 ( void )
{
return F_15 ( sizeof( struct V_6 ) , V_22 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
F_17 ( V_7 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
}
static inline void F_19 ( struct V_6 * V_7 )
{
F_20 ( & V_7 -> V_23 ) ;
}
static inline void F_21 ( struct V_6 * V_7 )
{
F_22 ( & V_7 -> V_23 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_24 * V_25 = V_7 -> V_25 ;
F_24 ( & V_26 ) ;
if ( F_25 ( V_6 [ V_7 -> V_27 ] != V_7 ) ) {
F_26 ( & V_26 ) ;
return;
}
V_6 [ V_7 -> V_27 ] = NULL ;
F_27 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
F_10 ( V_7 ) ;
F_26 ( & V_26 ) ;
#if F_28 ( V_29 )
if ( V_25 && V_25 -> V_30 &&
V_7 -> V_14 != V_31 )
F_29 ( & V_7 -> V_32 ) ;
#endif
if ( V_25 && V_25 -> V_33 == NULL )
V_25 = NULL ;
V_7 -> V_33 ( V_7 ) ;
if ( V_25 )
F_30 ( V_25 ) ;
}
struct V_6 * F_31 ( struct V_34 * V_34 )
{
return V_6 [ F_32 ( F_33 ( V_34 ) ) ] ;
}
static inline bool F_34 ( enum V_35 V_36 )
{
return V_36 == V_37 ||
V_36 == V_38 ||
V_36 == V_39 ;
}
void F_35 ( struct V_40 * V_41 )
{
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
}
int F_36 ( struct V_40 * V_41 , enum V_35 * V_42 ,
enum V_35 V_43 )
{
if ( ! F_34 ( V_43 ) )
return - V_44 ;
if ( * V_42 == V_43 )
return 0 ;
F_37 ( & V_41 -> V_45 [ V_43 ] ) ;
if ( F_34 ( * V_42 ) )
F_38 ( & V_41 -> V_45 [ * V_42 ] ) ;
* V_42 = V_43 ;
return 0 ;
}
void F_39 ( struct V_40 * V_41 , enum V_35 * V_42 )
{
F_36 ( V_41 , V_42 , V_46 ) ;
}
void F_40 ( struct V_40 * V_41 , enum V_35 V_42 )
{
if ( F_34 ( V_42 ) )
F_38 ( & V_41 -> V_45 [ V_42 ] ) ;
}
enum V_35 F_41 ( struct V_40 * V_41 )
{
if ( F_42 ( & V_41 -> V_45 [ V_39 ] ) > 0 )
return V_39 ;
if ( F_42 ( & V_41 -> V_45 [ V_38 ] ) > 0 )
return V_38 ;
if ( F_42 ( & V_41 -> V_45 [ V_37 ] ) > 0 )
return V_37 ;
return V_47 ;
}
int F_43 ( struct V_40 * V_41 , enum V_35 V_42 )
{
return ( V_42 < F_41 ( V_41 ) ) ? - V_48 : 0 ;
}
static T_1 F_44 ( struct V_34 * V_49 , char T_4 * V_5 ,
T_2 V_50 , T_5 * V_51 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( ! V_7 -> V_54 -> V_55 )
return - V_44 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_55 ( V_49 , V_5 , V_50 , V_51 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_3 ,
F_47 ( V_7 ) , V_50 , V_52 ) ;
return V_52 ;
}
static T_1 F_48 ( struct V_34 * V_49 , const char T_4 * V_5 ,
T_2 V_50 , T_5 * V_51 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( ! V_7 -> V_54 -> V_57 )
return - V_44 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_57 ( V_49 , V_5 , V_50 , V_51 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_4 ,
F_47 ( V_7 ) , V_50 , V_52 ) ;
return V_52 ;
}
static unsigned int F_49 ( struct V_34 * V_49 , struct V_58 * V_59 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
unsigned int V_11 = V_60 | V_61 ;
if ( ! V_7 -> V_54 -> V_59 )
return V_62 ;
if ( F_45 ( V_7 ) )
V_11 = V_7 -> V_54 -> V_59 ( V_49 , V_59 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_5 ,
F_47 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static long F_50 ( struct V_34 * V_49 , unsigned int V_63 , unsigned long V_64 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( V_7 -> V_54 -> V_65 ) {
struct V_66 * V_67 = F_51 ( V_7 , V_63 ) ;
if ( V_67 && F_52 ( V_67 ) )
return - V_68 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_65 ( V_49 , V_63 , V_64 ) ;
if ( V_67 )
F_26 ( V_67 ) ;
} else if ( V_7 -> V_54 -> V_69 ) {
static F_53 ( V_70 ) ;
struct V_66 * V_71 = V_7 -> V_25 ?
& V_7 -> V_25 -> V_72 : & V_70 ;
if ( V_63 != V_73 && F_52 ( V_71 ) )
return - V_68 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_69 ( V_49 , V_63 , V_64 ) ;
if ( V_63 != V_73 )
F_26 ( V_71 ) ;
} else
V_52 = - V_74 ;
return V_52 ;
}
static unsigned long F_54 ( struct V_34 * V_49 ,
unsigned long V_75 , unsigned long V_10 , unsigned long V_76 ,
unsigned long V_77 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 ;
if ( ! V_7 -> V_54 -> V_78 )
return - V_79 ;
if ( ! F_45 ( V_7 ) )
return - V_53 ;
V_52 = V_7 -> V_54 -> V_78 ( V_49 , V_75 , V_10 , V_76 , V_77 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_6 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_55 ( struct V_34 * V_49 , struct V_80 * V_81 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( ! V_7 -> V_54 -> V_82 )
return - V_53 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_82 ( V_49 , V_81 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_7 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_56 ( struct V_83 * V_83 , struct V_34 * V_49 )
{
struct V_6 * V_7 ;
int V_52 = 0 ;
F_24 ( & V_26 ) ;
V_7 = F_31 ( V_49 ) ;
if ( V_7 == NULL || ! F_45 ( V_7 ) ) {
F_26 ( & V_26 ) ;
return - V_53 ;
}
F_19 ( V_7 ) ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_54 -> V_84 ) {
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_84 ( V_49 ) ;
else
V_52 = - V_53 ;
}
if ( V_7 -> V_9 )
F_46 ( V_56 L_8 ,
F_47 ( V_7 ) , V_52 ) ;
if ( V_52 )
F_21 ( V_7 ) ;
return V_52 ;
}
static int F_57 ( struct V_83 * V_83 , struct V_34 * V_49 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = 0 ;
if ( V_7 -> V_54 -> V_33 )
V_52 = V_7 -> V_54 -> V_33 ( V_49 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_9 ,
F_47 ( V_7 ) ) ;
F_21 ( V_7 ) ;
return V_52 ;
}
static int F_58 ( struct V_6 * V_7 )
{
static F_59 ( V_85 , V_86 ) ;
int V_87 ;
if ( V_7 -> V_88 == NULL )
return 0 ;
F_60 ( V_85 , V_86 ) ;
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ ) {
if ( V_6 [ V_87 ] != NULL &&
V_6 [ V_87 ] -> V_88 == V_7 -> V_88 ) {
F_9 ( V_6 [ V_87 ] -> V_8 , V_85 ) ;
}
}
return F_61 ( V_85 , V_86 ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
F_59 ( V_89 , V_90 ) ;
const struct V_91 * V_92 = V_7 -> V_93 ;
bool V_94 = V_7 -> V_14 == V_95 ;
bool V_96 = V_7 -> V_14 == V_97 ;
bool V_98 = V_7 -> V_14 == V_16 ;
bool V_99 = V_7 -> V_100 != V_101 ;
bool V_102 = V_7 -> V_100 != V_103 ;
F_60 ( V_89 , V_90 ) ;
F_63 ( V_92 , V_104 , V_105 ) ;
if ( V_92 -> V_106 ||
F_64 ( V_107 , & V_7 -> V_77 ) )
F_9 ( F_65 ( V_108 ) , V_89 ) ;
if ( V_92 -> V_109 ||
F_64 ( V_107 , & V_7 -> V_77 ) )
F_9 ( F_65 ( V_110 ) , V_89 ) ;
F_63 ( V_92 , V_111 , V_112 ) ;
F_63 ( V_92 , V_113 , V_114 ) ;
if ( V_7 -> V_115 || V_92 -> V_116 )
F_9 ( F_65 ( V_117 ) , V_89 ) ;
if ( V_7 -> V_115 || V_92 -> V_118 || V_92 -> V_119 )
F_9 ( F_65 ( V_120 ) , V_89 ) ;
if ( V_7 -> V_115 || V_92 -> V_121 || V_92 -> V_122 )
F_9 ( F_65 ( V_123 ) , V_89 ) ;
if ( V_7 -> V_115 || V_92 -> V_119 )
F_9 ( F_65 ( V_124 ) , V_89 ) ;
if ( V_7 -> V_115 || V_92 -> V_122 )
F_9 ( F_65 ( V_125 ) , V_89 ) ;
if ( V_7 -> V_115 || V_92 -> V_126 )
F_9 ( F_65 ( V_127 ) , V_89 ) ;
if ( V_7 -> V_115 || V_92 -> V_128 )
F_9 ( F_65 ( V_129 ) , V_89 ) ;
F_63 ( V_92 , V_130 , V_131 ) ;
F_63 ( V_92 , V_132 , V_133 ) ;
F_63 ( V_92 , V_134 , V_135 ) ;
#ifdef F_66
F_9 ( F_65 ( V_136 ) , V_89 ) ;
F_9 ( F_65 ( V_137 ) , V_89 ) ;
F_9 ( F_65 ( V_138 ) , V_89 ) ;
#endif
F_63 ( V_92 , V_139 , V_140 ) ;
F_63 ( V_92 , V_141 , V_142 ) ;
F_63 ( V_92 , V_143 , V_142 ) ;
F_63 ( V_92 , V_144 , V_145 ) ;
if ( V_92 -> V_146 || V_92 -> V_147 || V_92 -> V_148 )
F_9 ( F_65 ( V_149 ) , V_89 ) ;
if ( V_94 ) {
if ( ( V_99 && ( V_92 -> V_150 ||
V_92 -> V_151 ||
V_92 -> V_152 ) ) ||
( V_102 && ( V_92 -> V_153 ||
V_92 -> V_154 ) ) )
F_9 ( F_65 ( V_155 ) , V_89 ) ;
if ( ( V_99 && ( V_92 -> V_156 ||
V_92 -> V_157 ||
V_92 -> V_158 ) ) ||
( V_102 && ( V_92 -> V_159 ||
V_92 -> V_160 ||
V_92 -> V_161 ) ) )
F_9 ( F_65 ( V_162 ) , V_89 ) ;
if ( ( V_99 && ( V_92 -> V_163 ||
V_92 -> V_164 ||
V_92 -> V_165 ) ) ||
( V_102 && ( V_92 -> V_166 ||
V_92 -> V_167 ||
V_92 -> V_168 ) ) )
F_9 ( F_65 ( V_169 ) , V_89 ) ;
if ( ( V_99 && ( V_92 -> V_170 ||
V_92 -> V_171 ||
V_92 -> V_172 ) ) ||
( V_102 && ( V_92 -> V_173 ||
V_92 -> V_174 ||
V_92 -> V_175 ) ) )
F_9 ( F_65 ( V_176 ) , V_89 ) ;
F_63 ( V_92 , V_177 , V_178 ) ;
F_63 ( V_92 , V_179 , V_180 ) ;
F_63 ( V_92 , V_181 , V_182 ) ;
F_63 ( V_92 , V_183 , V_184 ) ;
F_63 ( V_92 , V_185 , V_186 ) ;
F_63 ( V_92 , V_187 , V_188 ) ;
F_63 ( V_92 , V_189 , V_190 ) ;
F_63 ( V_92 , V_191 , V_192 ) ;
F_63 ( V_92 , V_193 , V_194 ) ;
F_63 ( V_92 , V_195 , V_196 ) ;
F_63 ( V_92 , V_197 , V_198 ) ;
F_63 ( V_92 , V_199 , V_200 ) ;
} else if ( V_96 ) {
if ( ( V_99 && ( V_92 -> V_201 ||
V_92 -> V_202 ) ) ||
( V_102 && ( V_92 -> V_203 ||
V_92 -> V_204 ) ) )
F_9 ( F_65 ( V_162 ) , V_89 ) ;
if ( ( V_99 && ( V_92 -> V_205 ||
V_92 -> V_206 ) ) ||
( V_102 && ( V_92 -> V_207 ||
V_92 -> V_208 ) ) )
F_9 ( F_65 ( V_169 ) , V_89 ) ;
if ( ( V_99 && ( V_92 -> V_209 ||
V_92 -> V_210 ) ) ||
( V_102 && ( V_92 -> V_211 ||
V_92 -> V_212 ) ) )
F_9 ( F_65 ( V_176 ) , V_89 ) ;
F_63 ( V_92 , V_213 , V_214 ) ;
}
if ( ! V_98 ) {
F_63 ( V_92 , V_215 , V_216 ) ;
F_63 ( V_92 , V_217 , V_218 ) ;
F_63 ( V_92 , V_219 , V_220 ) ;
F_63 ( V_92 , V_221 , V_222 ) ;
F_63 ( V_92 , V_73 , V_223 ) ;
F_63 ( V_92 , V_224 , V_225 ) ;
F_63 ( V_92 , V_226 , V_227 ) ;
if ( V_92 -> V_228 )
F_9 ( F_65 ( V_229 ) , V_89 ) ;
if ( V_92 -> V_230 || V_7 -> V_231 )
F_9 ( F_65 ( V_232 ) , V_89 ) ;
F_63 ( V_92 , V_233 , V_228 ) ;
if ( V_99 ) {
F_63 ( V_92 , V_234 , V_235 ) ;
F_63 ( V_92 , V_236 , V_237 ) ;
F_63 ( V_92 , V_238 , V_239 ) ;
F_63 ( V_92 , V_240 , V_241 ) ;
F_63 ( V_92 , V_242 , V_243 ) ;
F_63 ( V_92 , V_244 , V_245 ) ;
F_63 ( V_92 , V_246 , V_247 ) ;
F_63 ( V_92 , V_248 , V_249 ) ;
}
if ( V_102 ) {
F_63 ( V_92 , V_250 , V_251 ) ;
F_63 ( V_92 , V_252 , V_253 ) ;
F_63 ( V_92 , V_254 , V_255 ) ;
F_63 ( V_92 , V_256 , V_257 ) ;
F_63 ( V_92 , V_258 , V_259 ) ;
F_63 ( V_92 , V_260 , V_261 ) ;
}
if ( V_92 -> V_262 || V_92 -> V_263 )
F_9 ( F_65 ( V_264 ) , V_89 ) ;
if ( V_92 -> V_265 || V_92 -> V_266 )
F_9 ( F_65 ( V_267 ) , V_89 ) ;
F_63 ( V_92 , V_268 , V_263 ) ;
F_63 ( V_92 , V_269 , V_266 ) ;
if ( V_92 -> V_270 || V_92 -> V_263 )
F_9 ( F_65 ( V_271 ) , V_89 ) ;
if ( V_92 -> V_272 || ( V_7 -> V_14 == V_95 &&
( V_92 -> V_230 || V_7 -> V_231 ) ) )
F_9 ( F_65 ( V_273 ) , V_89 ) ;
F_63 ( V_92 , V_274 , V_275 ) ;
F_63 ( V_92 , V_276 , V_277 ) ;
F_63 ( V_92 , V_278 , V_279 ) ;
F_63 ( V_92 , V_280 , V_281 ) ;
F_63 ( V_92 , V_282 , V_283 ) ;
}
if ( V_102 ) {
F_63 ( V_92 , V_284 , V_148 ) ;
F_63 ( V_92 , V_285 , V_286 ) ;
}
if ( V_99 ) {
F_63 ( V_92 , V_287 , V_147 ) ;
F_63 ( V_92 , V_288 , V_289 ) ;
F_63 ( V_92 , V_290 , V_291 ) ;
}
F_67 ( V_7 -> V_89 , V_89 , V_7 -> V_89 ,
V_90 ) ;
}
int F_68 ( struct V_6 * V_7 , int type , int V_292 ,
int V_293 , struct V_294 * V_295 )
{
int V_87 = 0 ;
int V_52 ;
int V_296 = 0 ;
int V_297 = V_86 ;
const char * V_298 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_33 ) )
return - V_44 ;
F_69 ( & V_7 -> V_299 ) ;
F_70 ( & V_7 -> V_300 ) ;
switch ( type ) {
case V_95 :
V_298 = L_10 ;
break;
case V_97 :
V_298 = L_11 ;
break;
case V_16 :
V_298 = L_12 ;
break;
case V_31 :
V_298 = L_13 ;
break;
default:
F_46 ( V_301 L_14 ,
V_302 , type ) ;
return - V_44 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_25 ) {
if ( V_7 -> V_25 -> V_23 )
V_7 -> V_88 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_115 == NULL )
V_7 -> V_115 = V_7 -> V_25 -> V_115 ;
if ( V_7 -> V_36 == NULL )
V_7 -> V_36 = & V_7 -> V_25 -> V_36 ;
}
#ifdef F_71
switch ( type ) {
case V_95 :
V_296 = 0 ;
V_297 = 64 ;
break;
case V_16 :
V_296 = 64 ;
V_297 = 64 ;
break;
case V_97 :
V_296 = 224 ;
V_297 = 32 ;
break;
default:
V_296 = 128 ;
V_297 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_292 = F_12 ( V_7 , V_292 == - 1 ? 0 : V_292 , V_297 ) ;
if ( V_292 == V_297 )
V_292 = F_12 ( V_7 , 0 , V_297 ) ;
if ( V_292 == V_297 ) {
F_46 ( V_301 L_15 ) ;
F_26 ( & V_26 ) ;
return - V_303 ;
}
#ifdef F_71
V_87 = V_292 ;
#else
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ )
if ( V_6 [ V_87 ] == NULL )
break;
if ( V_87 == V_86 ) {
F_26 ( & V_26 ) ;
F_46 ( V_301 L_16 ) ;
return - V_303 ;
}
#endif
V_7 -> V_27 = V_87 + V_296 ;
V_7 -> V_19 = V_292 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_58 ( V_7 ) ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_93 )
F_62 ( V_7 ) ;
V_7 -> V_28 = F_72 () ;
if ( V_7 -> V_28 == NULL ) {
V_52 = - V_304 ;
goto V_305;
}
V_7 -> V_28 -> V_92 = & V_306 ;
V_7 -> V_28 -> V_295 = V_295 ;
V_52 = F_73 ( V_7 -> V_28 , F_74 ( V_307 , V_7 -> V_27 ) , 1 ) ;
if ( V_52 < 0 ) {
F_46 ( V_301 L_17 , V_302 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_305;
}
V_7 -> V_23 . V_308 = & V_309 ;
V_7 -> V_23 . V_310 = F_74 ( V_307 , V_7 -> V_27 ) ;
if ( V_7 -> V_88 )
V_7 -> V_23 . V_88 = V_7 -> V_88 ;
F_75 ( & V_7 -> V_23 , L_18 , V_298 , V_7 -> V_19 ) ;
V_52 = F_76 ( & V_7 -> V_23 ) ;
if ( V_52 < 0 ) {
F_46 ( V_301 L_19 , V_302 ) ;
goto V_305;
}
V_7 -> V_23 . V_33 = F_23 ;
if ( V_292 != - 1 && V_292 != V_7 -> V_19 && V_293 )
F_46 ( V_311 L_20 , V_302 ,
V_298 , V_292 , F_47 ( V_7 ) ) ;
if ( V_7 -> V_25 )
F_77 ( V_7 -> V_25 ) ;
#if F_28 ( V_29 )
if ( V_7 -> V_25 && V_7 -> V_25 -> V_30 &&
V_7 -> V_14 != V_31 ) {
V_7 -> V_32 . type = V_312 ;
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_313 . V_314 . V_315 = V_307 ;
V_7 -> V_32 . V_313 . V_314 . V_27 = V_7 -> V_27 ;
V_52 = F_78 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_52 < 0 )
F_46 ( V_311
L_21 ,
V_302 ) ;
}
#endif
F_9 ( V_316 , & V_7 -> V_77 ) ;
F_24 ( & V_26 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
return 0 ;
V_305:
F_24 ( & V_26 ) ;
if ( V_7 -> V_28 )
F_27 ( V_7 -> V_28 ) ;
F_10 ( V_7 ) ;
F_26 ( & V_26 ) ;
V_7 -> V_27 = - 1 ;
return V_52 ;
}
void F_79 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_45 ( V_7 ) )
return;
F_24 ( & V_26 ) ;
F_11 ( V_316 , & V_7 -> V_77 ) ;
F_26 ( & V_26 ) ;
F_80 ( & V_7 -> V_23 ) ;
}
static int T_6 F_81 ( void )
{
T_7 V_23 = F_74 ( V_307 , 0 ) ;
int V_52 ;
F_46 ( V_317 L_22 ) ;
V_52 = F_82 ( V_23 , V_86 , V_318 ) ;
if ( V_52 < 0 ) {
F_46 ( V_311 L_23 ,
V_307 ) ;
return V_52 ;
}
V_52 = F_83 ( & V_309 ) ;
if ( V_52 < 0 ) {
F_84 ( V_23 , V_86 ) ;
F_46 ( V_311 L_24 ) ;
return - V_319 ;
}
return 0 ;
}
static void T_8 F_85 ( void )
{
T_7 V_23 = F_74 ( V_307 , 0 ) ;
F_86 ( & V_309 ) ;
F_84 ( V_23 , V_86 ) ;
}
