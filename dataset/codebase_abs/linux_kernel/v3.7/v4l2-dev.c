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
return V_6 [ F_32 ( V_34 -> V_35 . V_36 -> V_37 ) ] ;
}
static inline bool F_33 ( enum V_38 V_39 )
{
return V_39 == V_40 ||
V_39 == V_41 ||
V_39 == V_42 ;
}
void F_34 ( struct V_43 * V_44 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
}
int F_35 ( struct V_43 * V_44 , enum V_38 * V_45 ,
enum V_38 V_46 )
{
if ( ! F_33 ( V_46 ) )
return - V_47 ;
if ( * V_45 == V_46 )
return 0 ;
F_36 ( & V_44 -> V_48 [ V_46 ] ) ;
if ( F_33 ( * V_45 ) )
F_37 ( & V_44 -> V_48 [ * V_45 ] ) ;
* V_45 = V_46 ;
return 0 ;
}
void F_38 ( struct V_43 * V_44 , enum V_38 * V_45 )
{
F_35 ( V_44 , V_45 , V_49 ) ;
}
void F_39 ( struct V_43 * V_44 , enum V_38 V_45 )
{
if ( F_33 ( V_45 ) )
F_37 ( & V_44 -> V_48 [ V_45 ] ) ;
}
enum V_38 F_40 ( struct V_43 * V_44 )
{
if ( F_41 ( & V_44 -> V_48 [ V_42 ] ) > 0 )
return V_42 ;
if ( F_41 ( & V_44 -> V_48 [ V_41 ] ) > 0 )
return V_41 ;
if ( F_41 ( & V_44 -> V_48 [ V_40 ] ) > 0 )
return V_40 ;
return V_50 ;
}
int F_42 ( struct V_43 * V_44 , enum V_38 V_45 )
{
return ( V_45 < F_40 ( V_44 ) ) ? - V_51 : 0 ;
}
static T_1 F_43 ( struct V_34 * V_52 , char T_4 * V_5 ,
T_2 V_53 , T_5 * V_54 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = - V_56 ;
if ( ! V_7 -> V_57 -> V_58 )
return - V_47 ;
if ( F_44 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_58 ( V_52 , V_5 , V_53 , V_54 ) ;
if ( V_7 -> V_9 )
F_45 ( V_59 L_3 ,
F_46 ( V_7 ) , V_53 , V_55 ) ;
return V_55 ;
}
static T_1 F_47 ( struct V_34 * V_52 , const char T_4 * V_5 ,
T_2 V_53 , T_5 * V_54 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = - V_56 ;
if ( ! V_7 -> V_57 -> V_60 )
return - V_47 ;
if ( F_44 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_60 ( V_52 , V_5 , V_53 , V_54 ) ;
if ( V_7 -> V_9 )
F_45 ( V_59 L_4 ,
F_46 ( V_7 ) , V_53 , V_55 ) ;
return V_55 ;
}
static unsigned int F_48 ( struct V_34 * V_52 , struct V_61 * V_62 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
unsigned int V_11 = V_63 | V_64 ;
if ( ! V_7 -> V_57 -> V_62 )
return V_65 ;
if ( F_44 ( V_7 ) )
V_11 = V_7 -> V_57 -> V_62 ( V_52 , V_62 ) ;
if ( V_7 -> V_9 )
F_45 ( V_59 L_5 ,
F_46 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static long F_49 ( struct V_34 * V_52 , unsigned int V_66 , unsigned long V_67 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = - V_56 ;
if ( V_7 -> V_57 -> V_68 ) {
struct V_69 * V_70 = F_50 ( V_7 , V_66 ) ;
if ( V_70 && F_51 ( V_70 ) )
return - V_71 ;
if ( F_44 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_68 ( V_52 , V_66 , V_67 ) ;
if ( V_70 )
F_26 ( V_70 ) ;
} else if ( V_7 -> V_57 -> V_72 ) {
static F_52 ( V_73 ) ;
struct V_69 * V_74 = V_7 -> V_25 ?
& V_7 -> V_25 -> V_75 : & V_73 ;
if ( V_66 != V_76 && F_51 ( V_74 ) )
return - V_71 ;
if ( F_44 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_72 ( V_52 , V_66 , V_67 ) ;
if ( V_66 != V_76 )
F_26 ( V_74 ) ;
} else
V_55 = - V_77 ;
return V_55 ;
}
static unsigned long F_53 ( struct V_34 * V_52 ,
unsigned long V_78 , unsigned long V_10 , unsigned long V_79 ,
unsigned long V_80 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 ;
if ( ! V_7 -> V_57 -> V_81 )
return - V_82 ;
if ( ! F_44 ( V_7 ) )
return - V_56 ;
V_55 = V_7 -> V_57 -> V_81 ( V_52 , V_78 , V_10 , V_79 , V_80 ) ;
if ( V_7 -> V_9 )
F_45 ( V_59 L_6 ,
F_46 ( V_7 ) , V_55 ) ;
return V_55 ;
}
static int F_54 ( struct V_34 * V_52 , struct V_83 * V_84 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = - V_56 ;
if ( ! V_7 -> V_57 -> V_85 )
return - V_56 ;
if ( F_44 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_85 ( V_52 , V_84 ) ;
if ( V_7 -> V_9 )
F_45 ( V_59 L_7 ,
F_46 ( V_7 ) , V_55 ) ;
return V_55 ;
}
static int F_55 ( struct V_86 * V_86 , struct V_34 * V_52 )
{
struct V_6 * V_7 ;
int V_55 = 0 ;
F_24 ( & V_26 ) ;
V_7 = F_31 ( V_52 ) ;
if ( V_7 == NULL || ! F_44 ( V_7 ) ) {
F_26 ( & V_26 ) ;
return - V_56 ;
}
F_19 ( V_7 ) ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_57 -> V_87 ) {
if ( F_44 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_87 ( V_52 ) ;
else
V_55 = - V_56 ;
}
if ( V_7 -> V_9 )
F_45 ( V_59 L_8 ,
F_46 ( V_7 ) , V_55 ) ;
if ( V_55 )
F_21 ( V_7 ) ;
return V_55 ;
}
static int F_56 ( struct V_86 * V_86 , struct V_34 * V_52 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = 0 ;
if ( V_7 -> V_57 -> V_33 )
V_55 = V_7 -> V_57 -> V_33 ( V_52 ) ;
if ( V_7 -> V_9 )
F_45 ( V_59 L_9 ,
F_46 ( V_7 ) ) ;
F_21 ( V_7 ) ;
return V_55 ;
}
static int F_57 ( struct V_6 * V_7 )
{
static F_58 ( V_88 , V_89 ) ;
int V_90 ;
if ( V_7 -> V_91 == NULL )
return 0 ;
F_59 ( V_88 , V_89 ) ;
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ ) {
if ( V_6 [ V_90 ] != NULL &&
V_6 [ V_90 ] -> V_91 == V_7 -> V_91 ) {
F_9 ( V_6 [ V_90 ] -> V_8 , V_88 ) ;
}
}
return F_60 ( V_88 , V_89 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_58 ( V_92 , V_93 ) ;
const struct V_94 * V_95 = V_7 -> V_96 ;
bool V_97 = V_7 -> V_14 == V_98 ;
bool V_99 = V_7 -> V_14 == V_100 ;
bool V_101 = V_7 -> V_14 == V_16 ;
bool V_102 = V_7 -> V_103 != V_104 ;
bool V_105 = V_7 -> V_103 != V_106 ;
F_59 ( V_92 , V_93 ) ;
F_62 ( V_95 , V_107 , V_108 ) ;
if ( V_95 -> V_109 ||
F_63 ( V_110 , & V_7 -> V_80 ) )
F_9 ( F_64 ( V_111 ) , V_92 ) ;
if ( V_95 -> V_112 ||
F_63 ( V_110 , & V_7 -> V_80 ) )
F_9 ( F_64 ( V_113 ) , V_92 ) ;
F_62 ( V_95 , V_114 , V_115 ) ;
F_62 ( V_95 , V_116 , V_117 ) ;
F_62 ( V_95 , V_118 , V_119 ) ;
F_62 ( V_95 , V_76 , V_120 ) ;
F_62 ( V_95 , V_121 , V_122 ) ;
F_62 ( V_95 , V_123 , V_124 ) ;
if ( V_7 -> V_125 || V_95 -> V_126 )
F_9 ( F_64 ( V_127 ) , V_92 ) ;
if ( V_7 -> V_125 || V_95 -> V_128 || V_95 -> V_129 )
F_9 ( F_64 ( V_130 ) , V_92 ) ;
if ( V_7 -> V_125 || V_95 -> V_131 || V_95 -> V_132 )
F_9 ( F_64 ( V_133 ) , V_92 ) ;
if ( V_7 -> V_125 || V_95 -> V_129 )
F_9 ( F_64 ( V_134 ) , V_92 ) ;
if ( V_7 -> V_125 || V_95 -> V_132 )
F_9 ( F_64 ( V_135 ) , V_92 ) ;
if ( V_7 -> V_125 || V_95 -> V_136 )
F_9 ( F_64 ( V_137 ) , V_92 ) ;
if ( V_7 -> V_125 || V_95 -> V_138 )
F_9 ( F_64 ( V_139 ) , V_92 ) ;
F_62 ( V_95 , V_140 , V_141 ) ;
F_62 ( V_95 , V_142 , V_143 ) ;
F_62 ( V_95 , V_144 , V_145 ) ;
#ifdef F_65
F_62 ( V_95 , V_146 , V_147 ) ;
F_62 ( V_95 , V_148 , V_149 ) ;
#endif
F_62 ( V_95 , V_150 , V_151 ) ;
F_62 ( V_95 , V_152 , V_153 ) ;
F_62 ( V_95 , V_154 , V_153 ) ;
F_62 ( V_95 , V_155 , V_156 ) ;
F_62 ( V_95 , V_157 , V_158 ) ;
F_62 ( V_95 , V_159 , V_160 ) ;
if ( V_95 -> V_161 || V_95 -> V_162 || V_95 -> V_163 )
F_9 ( F_64 ( V_164 ) , V_92 ) ;
if ( V_97 ) {
if ( ( V_102 && ( V_95 -> V_165 ||
V_95 -> V_166 ||
V_95 -> V_167 ) ) ||
( V_105 && ( V_95 -> V_168 ||
V_95 -> V_169 ) ) )
F_9 ( F_64 ( V_170 ) , V_92 ) ;
if ( ( V_102 && ( V_95 -> V_171 ||
V_95 -> V_172 ||
V_95 -> V_173 ) ) ||
( V_105 && ( V_95 -> V_174 ||
V_95 -> V_175 ||
V_95 -> V_176 ) ) )
F_9 ( F_64 ( V_177 ) , V_92 ) ;
if ( ( V_102 && ( V_95 -> V_178 ||
V_95 -> V_179 ||
V_95 -> V_180 ) ) ||
( V_105 && ( V_95 -> V_181 ||
V_95 -> V_182 ||
V_95 -> V_183 ) ) )
F_9 ( F_64 ( V_184 ) , V_92 ) ;
if ( ( V_102 && ( V_95 -> V_185 ||
V_95 -> V_186 ||
V_95 -> V_187 ) ) ||
( V_105 && ( V_95 -> V_188 ||
V_95 -> V_189 ||
V_95 -> V_190 ) ) )
F_9 ( F_64 ( V_191 ) , V_92 ) ;
F_62 ( V_95 , V_192 , V_193 ) ;
F_62 ( V_95 , V_194 , V_195 ) ;
F_62 ( V_95 , V_196 , V_197 ) ;
F_62 ( V_95 , V_198 , V_199 ) ;
F_62 ( V_95 , V_200 , V_201 ) ;
F_62 ( V_95 , V_202 , V_203 ) ;
F_62 ( V_95 , V_204 , V_205 ) ;
F_62 ( V_95 , V_206 , V_207 ) ;
F_62 ( V_95 , V_208 , V_209 ) ;
F_62 ( V_95 , V_210 , V_211 ) ;
F_62 ( V_95 , V_212 , V_213 ) ;
F_62 ( V_95 , V_214 , V_215 ) ;
} else if ( V_99 ) {
if ( ( V_102 && ( V_95 -> V_216 ||
V_95 -> V_217 ) ) ||
( V_105 && ( V_95 -> V_218 ||
V_95 -> V_219 ) ) )
F_9 ( F_64 ( V_177 ) , V_92 ) ;
if ( ( V_102 && ( V_95 -> V_220 ||
V_95 -> V_221 ) ) ||
( V_105 && ( V_95 -> V_222 ||
V_95 -> V_223 ) ) )
F_9 ( F_64 ( V_184 ) , V_92 ) ;
if ( ( V_102 && ( V_95 -> V_224 ||
V_95 -> V_225 ) ) ||
( V_105 && ( V_95 -> V_226 ||
V_95 -> V_227 ) ) )
F_9 ( F_64 ( V_191 ) , V_92 ) ;
F_62 ( V_95 , V_228 , V_229 ) ;
}
if ( ! V_101 ) {
if ( V_95 -> V_230 )
F_9 ( F_64 ( V_231 ) , V_92 ) ;
if ( V_95 -> V_232 || V_7 -> V_233 )
F_9 ( F_64 ( V_234 ) , V_92 ) ;
F_62 ( V_95 , V_235 , V_230 ) ;
if ( V_102 ) {
F_62 ( V_95 , V_236 , V_237 ) ;
F_62 ( V_95 , V_238 , V_239 ) ;
F_62 ( V_95 , V_240 , V_241 ) ;
F_62 ( V_95 , V_242 , V_243 ) ;
F_62 ( V_95 , V_244 , V_245 ) ;
F_62 ( V_95 , V_246 , V_247 ) ;
F_62 ( V_95 , V_248 , V_249 ) ;
F_62 ( V_95 , V_250 , V_251 ) ;
F_62 ( V_95 , V_252 , V_253 ) ;
}
if ( V_105 ) {
F_62 ( V_95 , V_254 , V_255 ) ;
F_62 ( V_95 , V_256 , V_257 ) ;
F_62 ( V_95 , V_258 , V_259 ) ;
F_62 ( V_95 , V_260 , V_261 ) ;
F_62 ( V_95 , V_262 , V_263 ) ;
F_62 ( V_95 , V_264 , V_265 ) ;
}
if ( V_95 -> V_266 || V_95 -> V_267 )
F_9 ( F_64 ( V_268 ) , V_92 ) ;
if ( V_95 -> V_269 || V_95 -> V_270 )
F_9 ( F_64 ( V_271 ) , V_92 ) ;
F_62 ( V_95 , V_272 , V_267 ) ;
F_62 ( V_95 , V_273 , V_270 ) ;
if ( V_95 -> V_274 || V_95 -> V_267 )
F_9 ( F_64 ( V_275 ) , V_92 ) ;
if ( V_95 -> V_276 || ( V_7 -> V_14 == V_98 &&
( V_95 -> V_232 || V_7 -> V_233 ) ) )
F_9 ( F_64 ( V_277 ) , V_92 ) ;
F_62 ( V_95 , V_278 , V_279 ) ;
F_62 ( V_95 , V_280 , V_281 ) ;
F_62 ( V_95 , V_282 , V_283 ) ;
F_62 ( V_95 , V_284 , V_285 ) ;
F_62 ( V_95 , V_286 , V_287 ) ;
F_62 ( V_95 , V_288 , V_289 ) ;
F_62 ( V_95 , V_290 , V_291 ) ;
F_62 ( V_95 , V_292 , V_293 ) ;
}
if ( V_105 ) {
F_62 ( V_95 , V_294 , V_163 ) ;
F_62 ( V_95 , V_295 , V_296 ) ;
}
if ( V_102 ) {
F_62 ( V_95 , V_297 , V_162 ) ;
F_62 ( V_95 , V_298 , V_299 ) ;
F_62 ( V_95 , V_300 , V_301 ) ;
}
F_66 ( V_7 -> V_92 , V_92 , V_7 -> V_92 ,
V_93 ) ;
}
int F_67 ( struct V_6 * V_7 , int type , int V_302 ,
int V_303 , struct V_304 * V_305 )
{
int V_90 = 0 ;
int V_55 ;
int V_306 = 0 ;
int V_307 = V_89 ;
const char * V_308 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_33 ) )
return - V_47 ;
F_68 ( & V_7 -> V_309 ) ;
F_69 ( & V_7 -> V_310 ) ;
switch ( type ) {
case V_98 :
V_308 = L_10 ;
break;
case V_100 :
V_308 = L_11 ;
break;
case V_16 :
V_308 = L_12 ;
break;
case V_31 :
V_308 = L_13 ;
break;
default:
F_45 ( V_311 L_14 ,
V_312 , type ) ;
return - V_47 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_25 ) {
if ( V_7 -> V_25 -> V_23 )
V_7 -> V_91 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_125 == NULL )
V_7 -> V_125 = V_7 -> V_25 -> V_125 ;
if ( V_7 -> V_39 == NULL )
V_7 -> V_39 = & V_7 -> V_25 -> V_39 ;
}
#ifdef F_70
switch ( type ) {
case V_98 :
V_306 = 0 ;
V_307 = 64 ;
break;
case V_16 :
V_306 = 64 ;
V_307 = 64 ;
break;
case V_100 :
V_306 = 224 ;
V_307 = 32 ;
break;
default:
V_306 = 128 ;
V_307 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_302 = F_12 ( V_7 , V_302 == - 1 ? 0 : V_302 , V_307 ) ;
if ( V_302 == V_307 )
V_302 = F_12 ( V_7 , 0 , V_307 ) ;
if ( V_302 == V_307 ) {
F_45 ( V_311 L_15 ) ;
F_26 ( & V_26 ) ;
return - V_313 ;
}
#ifdef F_70
V_90 = V_302 ;
#else
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ )
if ( V_6 [ V_90 ] == NULL )
break;
if ( V_90 == V_89 ) {
F_26 ( & V_26 ) ;
F_45 ( V_311 L_16 ) ;
return - V_313 ;
}
#endif
V_7 -> V_27 = V_90 + V_306 ;
V_7 -> V_19 = V_302 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_57 ( V_7 ) ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_96 )
F_61 ( V_7 ) ;
V_7 -> V_28 = F_71 () ;
if ( V_7 -> V_28 == NULL ) {
V_55 = - V_314 ;
goto V_315;
}
V_7 -> V_28 -> V_95 = & V_316 ;
V_7 -> V_28 -> V_305 = V_305 ;
V_55 = F_72 ( V_7 -> V_28 , F_73 ( V_317 , V_7 -> V_27 ) , 1 ) ;
if ( V_55 < 0 ) {
F_45 ( V_311 L_17 , V_312 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_315;
}
V_7 -> V_23 . V_318 = & V_319 ;
V_7 -> V_23 . V_320 = F_73 ( V_317 , V_7 -> V_27 ) ;
if ( V_7 -> V_91 )
V_7 -> V_23 . V_91 = V_7 -> V_91 ;
F_74 ( & V_7 -> V_23 , L_18 , V_308 , V_7 -> V_19 ) ;
V_55 = F_75 ( & V_7 -> V_23 ) ;
if ( V_55 < 0 ) {
F_45 ( V_311 L_19 , V_312 ) ;
goto V_315;
}
V_7 -> V_23 . V_33 = F_23 ;
if ( V_302 != - 1 && V_302 != V_7 -> V_19 && V_303 )
F_45 ( V_321 L_20 , V_312 ,
V_308 , V_302 , F_46 ( V_7 ) ) ;
if ( V_7 -> V_25 )
F_76 ( V_7 -> V_25 ) ;
#if F_28 ( V_29 )
if ( V_7 -> V_25 && V_7 -> V_25 -> V_30 &&
V_7 -> V_14 != V_31 ) {
V_7 -> V_32 . type = V_322 ;
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_323 . V_324 . V_325 = V_317 ;
V_7 -> V_32 . V_323 . V_324 . V_27 = V_7 -> V_27 ;
V_55 = F_77 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_55 < 0 )
F_45 ( V_321
L_21 ,
V_312 ) ;
}
#endif
F_9 ( V_326 , & V_7 -> V_80 ) ;
F_24 ( & V_26 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
return 0 ;
V_315:
F_24 ( & V_26 ) ;
if ( V_7 -> V_28 )
F_27 ( V_7 -> V_28 ) ;
F_10 ( V_7 ) ;
F_26 ( & V_26 ) ;
V_7 -> V_27 = - 1 ;
return V_55 ;
}
void F_78 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_44 ( V_7 ) )
return;
F_24 ( & V_26 ) ;
F_11 ( V_326 , & V_7 -> V_80 ) ;
F_26 ( & V_26 ) ;
F_79 ( & V_7 -> V_23 ) ;
}
static int T_6 F_80 ( void )
{
T_7 V_23 = F_73 ( V_317 , 0 ) ;
int V_55 ;
F_45 ( V_327 L_22 ) ;
V_55 = F_81 ( V_23 , V_89 , V_328 ) ;
if ( V_55 < 0 ) {
F_45 ( V_321 L_23 ,
V_317 ) ;
return V_55 ;
}
V_55 = F_82 ( & V_319 ) ;
if ( V_55 < 0 ) {
F_83 ( V_23 , V_89 ) ;
F_45 ( V_321 L_24 ) ;
return - V_329 ;
}
return 0 ;
}
static void T_8 F_84 ( void )
{
T_7 V_23 = F_73 ( V_317 , 0 ) ;
F_85 ( & V_319 ) ;
F_83 ( V_23 , V_89 ) ;
}
