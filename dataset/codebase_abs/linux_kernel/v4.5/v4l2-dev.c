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
if ( V_25 -> V_30 ) {
F_29 ( V_7 -> V_31 ) ;
if ( V_7 -> V_32 . V_33 != V_34 )
F_30 ( & V_7 -> V_32 ) ;
}
#endif
if ( V_25 -> V_35 == NULL )
V_25 = NULL ;
V_7 -> V_35 ( V_7 ) ;
if ( V_25 )
F_31 ( V_25 ) ;
}
struct V_6 * F_32 ( struct V_36 * V_36 )
{
return V_6 [ F_33 ( F_34 ( V_36 ) ) ] ;
}
static inline bool F_35 ( enum V_37 V_38 )
{
return V_38 == V_39 ||
V_38 == V_40 ||
V_38 == V_41 ;
}
void F_36 ( struct V_42 * V_43 )
{
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
}
int F_37 ( struct V_42 * V_43 , enum V_37 * V_44 ,
enum V_37 V_45 )
{
if ( ! F_35 ( V_45 ) )
return - V_46 ;
if ( * V_44 == V_45 )
return 0 ;
F_38 ( & V_43 -> V_47 [ V_45 ] ) ;
if ( F_35 ( * V_44 ) )
F_39 ( & V_43 -> V_47 [ * V_44 ] ) ;
* V_44 = V_45 ;
return 0 ;
}
void F_40 ( struct V_42 * V_43 , enum V_37 * V_44 )
{
F_37 ( V_43 , V_44 , V_48 ) ;
}
void F_41 ( struct V_42 * V_43 , enum V_37 V_44 )
{
if ( F_35 ( V_44 ) )
F_39 ( & V_43 -> V_47 [ V_44 ] ) ;
}
enum V_37 F_42 ( struct V_42 * V_43 )
{
if ( F_43 ( & V_43 -> V_47 [ V_41 ] ) > 0 )
return V_41 ;
if ( F_43 ( & V_43 -> V_47 [ V_40 ] ) > 0 )
return V_40 ;
if ( F_43 ( & V_43 -> V_47 [ V_39 ] ) > 0 )
return V_39 ;
return V_49 ;
}
int F_44 ( struct V_42 * V_43 , enum V_37 V_44 )
{
return ( V_44 < F_42 ( V_43 ) ) ? - V_50 : 0 ;
}
static T_1 F_45 ( struct V_36 * V_51 , char T_4 * V_5 ,
T_2 V_52 , T_5 * V_53 )
{
struct V_6 * V_7 = F_32 ( V_51 ) ;
int V_54 = - V_55 ;
if ( ! V_7 -> V_56 -> V_57 )
return - V_46 ;
if ( F_46 ( V_7 ) )
V_54 = V_7 -> V_56 -> V_57 ( V_51 , V_5 , V_52 , V_53 ) ;
if ( ( V_7 -> V_9 & V_58 ) &&
( V_7 -> V_9 & V_59 ) )
F_47 ( V_60 L_3 ,
F_48 ( V_7 ) , V_52 , V_54 ) ;
return V_54 ;
}
static T_1 F_49 ( struct V_36 * V_51 , const char T_4 * V_5 ,
T_2 V_52 , T_5 * V_53 )
{
struct V_6 * V_7 = F_32 ( V_51 ) ;
int V_54 = - V_55 ;
if ( ! V_7 -> V_56 -> V_61 )
return - V_46 ;
if ( F_46 ( V_7 ) )
V_54 = V_7 -> V_56 -> V_61 ( V_51 , V_5 , V_52 , V_53 ) ;
if ( ( V_7 -> V_9 & V_58 ) &&
( V_7 -> V_9 & V_59 ) )
F_47 ( V_60 L_4 ,
F_48 ( V_7 ) , V_52 , V_54 ) ;
return V_54 ;
}
static unsigned int F_50 ( struct V_36 * V_51 , struct V_62 * V_63 )
{
struct V_6 * V_7 = F_32 ( V_51 ) ;
unsigned int V_11 = V_64 | V_65 ;
if ( ! V_7 -> V_56 -> V_63 )
return V_66 ;
if ( F_46 ( V_7 ) )
V_11 = V_7 -> V_56 -> V_63 ( V_51 , V_63 ) ;
if ( V_7 -> V_9 & V_67 )
F_47 ( V_60 L_5 ,
F_48 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static long F_51 ( struct V_36 * V_51 , unsigned int V_68 , unsigned long V_69 )
{
struct V_6 * V_7 = F_32 ( V_51 ) ;
int V_54 = - V_55 ;
if ( V_7 -> V_56 -> V_70 ) {
struct V_71 * V_72 = F_52 ( V_7 , V_68 ) ;
if ( V_72 && F_53 ( V_72 ) )
return - V_73 ;
if ( F_46 ( V_7 ) )
V_54 = V_7 -> V_56 -> V_70 ( V_51 , V_68 , V_69 ) ;
if ( V_72 )
F_26 ( V_72 ) ;
} else
V_54 = - V_74 ;
return V_54 ;
}
static unsigned long F_54 ( struct V_36 * V_51 ,
unsigned long V_75 , unsigned long V_10 , unsigned long V_76 ,
unsigned long V_77 )
{
struct V_6 * V_7 = F_32 ( V_51 ) ;
int V_54 ;
if ( ! V_7 -> V_56 -> V_78 )
return - V_79 ;
if ( ! F_46 ( V_7 ) )
return - V_55 ;
V_54 = V_7 -> V_56 -> V_78 ( V_51 , V_75 , V_10 , V_76 , V_77 ) ;
if ( V_7 -> V_9 & V_58 )
F_47 ( V_60 L_6 ,
F_48 ( V_7 ) , V_54 ) ;
return V_54 ;
}
static int F_55 ( struct V_36 * V_51 , struct V_80 * V_81 )
{
struct V_6 * V_7 = F_32 ( V_51 ) ;
int V_54 = - V_55 ;
if ( ! V_7 -> V_56 -> V_82 )
return - V_55 ;
if ( F_46 ( V_7 ) )
V_54 = V_7 -> V_56 -> V_82 ( V_51 , V_81 ) ;
if ( V_7 -> V_9 & V_58 )
F_47 ( V_60 L_7 ,
F_48 ( V_7 ) , V_54 ) ;
return V_54 ;
}
static int F_56 ( struct V_83 * V_83 , struct V_36 * V_51 )
{
struct V_6 * V_7 ;
int V_54 = 0 ;
F_24 ( & V_26 ) ;
V_7 = F_32 ( V_51 ) ;
if ( V_7 == NULL || ! F_46 ( V_7 ) ) {
F_26 ( & V_26 ) ;
return - V_55 ;
}
F_19 ( V_7 ) ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_56 -> V_84 ) {
if ( F_46 ( V_7 ) )
V_54 = V_7 -> V_56 -> V_84 ( V_51 ) ;
else
V_54 = - V_55 ;
}
if ( V_7 -> V_9 & V_58 )
F_47 ( V_60 L_8 ,
F_48 ( V_7 ) , V_54 ) ;
if ( V_54 )
F_21 ( V_7 ) ;
return V_54 ;
}
static int F_57 ( struct V_83 * V_83 , struct V_36 * V_51 )
{
struct V_6 * V_7 = F_32 ( V_51 ) ;
int V_54 = 0 ;
if ( V_7 -> V_56 -> V_35 )
V_54 = V_7 -> V_56 -> V_35 ( V_51 ) ;
if ( V_7 -> V_9 & V_58 )
F_47 ( V_60 L_9 ,
F_48 ( V_7 ) ) ;
F_21 ( V_7 ) ;
return V_54 ;
}
static int F_58 ( struct V_6 * V_7 )
{
static F_59 ( V_85 , V_86 ) ;
int V_87 ;
F_60 ( V_85 , V_86 ) ;
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ ) {
if ( V_6 [ V_87 ] != NULL &&
V_6 [ V_87 ] -> V_25 == V_7 -> V_25 ) {
F_9 ( V_6 [ V_87 ] -> V_8 , V_85 ) ;
}
}
return F_61 ( V_85 , V_86 ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
F_59 ( V_88 , V_89 ) ;
const struct V_90 * V_91 = V_7 -> V_92 ;
bool V_93 = V_7 -> V_14 == V_94 ;
bool V_95 = V_7 -> V_14 == V_96 ;
bool V_97 = V_7 -> V_14 == V_16 ;
bool V_98 = V_7 -> V_14 == V_99 ;
bool V_100 = V_7 -> V_101 != V_102 ;
bool V_103 = V_7 -> V_101 != V_104 ;
F_60 ( V_88 , V_89 ) ;
F_63 ( V_91 , V_105 , V_106 ) ;
F_9 ( F_64 ( V_107 ) , V_88 ) ;
F_9 ( F_64 ( V_108 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_110 )
F_9 ( F_64 ( V_111 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_112 )
F_9 ( F_64 ( V_113 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_114 || V_91 -> V_115 )
F_9 ( F_64 ( V_116 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_117 || V_91 -> V_118 )
F_9 ( F_64 ( V_119 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_115 )
F_9 ( F_64 ( V_120 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_118 )
F_9 ( F_64 ( V_121 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_122 )
F_9 ( F_64 ( V_123 ) , V_88 ) ;
if ( V_7 -> V_109 || V_91 -> V_124 )
F_9 ( F_64 ( V_125 ) , V_88 ) ;
F_63 ( V_91 , V_126 , V_127 ) ;
F_63 ( V_91 , V_128 , V_129 ) ;
F_63 ( V_91 , V_130 , V_131 ) ;
#ifdef F_65
F_9 ( F_64 ( V_132 ) , V_88 ) ;
F_9 ( F_64 ( V_133 ) , V_88 ) ;
F_9 ( F_64 ( V_134 ) , V_88 ) ;
#endif
F_63 ( V_91 , V_135 , V_136 ) ;
F_63 ( V_91 , V_137 , V_136 ) ;
F_63 ( V_91 , V_138 , V_139 ) ;
if ( V_91 -> V_140 || V_91 -> V_141 || V_91 -> V_142 )
F_9 ( F_64 ( V_143 ) , V_88 ) ;
if ( V_93 ) {
if ( ( V_100 && ( V_91 -> V_144 ||
V_91 -> V_145 ||
V_91 -> V_146 ) ) ||
( V_103 && ( V_91 -> V_147 ||
V_91 -> V_148 ) ) )
F_9 ( F_64 ( V_149 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_150 ||
V_91 -> V_151 ||
V_91 -> V_152 ) ) ||
( V_103 && ( V_91 -> V_153 ||
V_91 -> V_154 ||
V_91 -> V_155 ) ) )
F_9 ( F_64 ( V_156 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_157 ||
V_91 -> V_158 ||
V_91 -> V_159 ) ) ||
( V_103 && ( V_91 -> V_160 ||
V_91 -> V_161 ||
V_91 -> V_162 ) ) )
F_9 ( F_64 ( V_163 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_164 ||
V_91 -> V_165 ||
V_91 -> V_166 ) ) ||
( V_103 && ( V_91 -> V_167 ||
V_91 -> V_168 ||
V_91 -> V_169 ) ) )
F_9 ( F_64 ( V_170 ) , V_88 ) ;
F_63 ( V_91 , V_171 , V_172 ) ;
F_63 ( V_91 , V_173 , V_174 ) ;
F_63 ( V_91 , V_175 , V_176 ) ;
F_63 ( V_91 , V_177 , V_178 ) ;
F_63 ( V_91 , V_179 , V_180 ) ;
F_63 ( V_91 , V_181 , V_182 ) ;
F_63 ( V_91 , V_183 , V_184 ) ;
F_63 ( V_91 , V_185 , V_186 ) ;
F_63 ( V_91 , V_187 , V_188 ) ;
F_63 ( V_91 , V_189 , V_190 ) ;
F_63 ( V_91 , V_191 , V_192 ) ;
F_63 ( V_91 , V_193 , V_194 ) ;
if ( V_91 -> V_195 || V_91 -> V_196 )
F_9 ( F_64 ( V_197 ) , V_88 ) ;
if ( V_91 -> V_198 || V_91 -> V_199 )
F_9 ( F_64 ( V_200 ) , V_88 ) ;
F_63 ( V_91 , V_201 , V_196 ) ;
F_63 ( V_91 , V_202 , V_199 ) ;
if ( V_91 -> V_203 || V_91 -> V_196 )
F_9 ( F_64 ( V_204 ) , V_88 ) ;
} else if ( V_95 ) {
if ( ( V_100 && ( V_91 -> V_205 ||
V_91 -> V_206 ) ) ||
( V_103 && ( V_91 -> V_207 ||
V_91 -> V_208 ) ) )
F_9 ( F_64 ( V_156 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_209 ||
V_91 -> V_210 ) ) ||
( V_103 && ( V_91 -> V_211 ||
V_91 -> V_212 ) ) )
F_9 ( F_64 ( V_163 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_213 ||
V_91 -> V_214 ) ) ||
( V_103 && ( V_91 -> V_215 ||
V_91 -> V_216 ) ) )
F_9 ( F_64 ( V_170 ) , V_88 ) ;
F_63 ( V_91 , V_217 , V_218 ) ;
} else if ( V_98 && V_100 ) {
if ( V_91 -> V_219 )
F_9 ( F_64 ( V_149 ) , V_88 ) ;
if ( V_91 -> V_220 )
F_9 ( F_64 ( V_156 ) , V_88 ) ;
if ( V_91 -> V_221 )
F_9 ( F_64 ( V_163 ) , V_88 ) ;
if ( V_91 -> V_222 )
F_9 ( F_64 ( V_170 ) , V_88 ) ;
} else if ( V_98 && V_103 ) {
if ( V_91 -> V_223 )
F_9 ( F_64 ( V_149 ) , V_88 ) ;
if ( V_91 -> V_224 )
F_9 ( F_64 ( V_156 ) , V_88 ) ;
if ( V_91 -> V_225 )
F_9 ( F_64 ( V_163 ) , V_88 ) ;
if ( V_91 -> V_226 )
F_9 ( F_64 ( V_170 ) , V_88 ) ;
}
if ( V_93 || V_95 || V_98 ) {
F_63 ( V_91 , V_227 , V_228 ) ;
F_63 ( V_91 , V_229 , V_230 ) ;
F_63 ( V_91 , V_231 , V_232 ) ;
F_63 ( V_91 , V_233 , V_234 ) ;
F_63 ( V_91 , V_235 , V_236 ) ;
F_63 ( V_91 , V_237 , V_238 ) ;
F_63 ( V_91 , V_239 , V_240 ) ;
F_63 ( V_91 , V_241 , V_242 ) ;
F_63 ( V_91 , V_243 , V_244 ) ;
}
if ( V_93 || V_95 ) {
if ( V_91 -> V_245 )
F_9 ( F_64 ( V_246 ) , V_88 ) ;
F_63 ( V_91 , V_247 , V_245 ) ;
F_63 ( V_91 , V_248 , V_249 ) ;
if ( V_100 ) {
F_63 ( V_91 , V_250 , V_251 ) ;
F_63 ( V_91 , V_252 , V_253 ) ;
F_63 ( V_91 , V_254 , V_255 ) ;
F_63 ( V_91 , V_256 , V_257 ) ;
F_63 ( V_91 , V_258 , V_259 ) ;
F_63 ( V_91 , V_260 , V_261 ) ;
F_63 ( V_91 , V_262 , V_263 ) ;
F_63 ( V_91 , V_264 , V_265 ) ;
F_63 ( V_91 , V_266 , V_267 ) ;
}
if ( V_103 ) {
F_63 ( V_91 , V_268 , V_269 ) ;
F_63 ( V_91 , V_270 , V_271 ) ;
F_63 ( V_91 , V_272 , V_273 ) ;
F_63 ( V_91 , V_274 , V_275 ) ;
F_63 ( V_91 , V_276 , V_277 ) ;
F_63 ( V_91 , V_278 , V_279 ) ;
}
if ( V_91 -> V_280 || ( V_7 -> V_14 == V_94 &&
V_91 -> V_249 ) )
F_9 ( F_64 ( V_281 ) , V_88 ) ;
F_63 ( V_91 , V_282 , V_283 ) ;
F_63 ( V_91 , V_284 , V_285 ) ;
F_63 ( V_91 , V_286 , V_287 ) ;
F_63 ( V_91 , V_288 , V_289 ) ;
F_63 ( V_91 , V_290 , V_291 ) ;
F_63 ( V_91 , V_292 , V_293 ) ;
}
if ( V_103 && ( V_97 || V_98 ) ) {
F_63 ( V_91 , V_294 , V_142 ) ;
F_63 ( V_91 , V_295 , V_296 ) ;
}
if ( V_100 ) {
F_63 ( V_91 , V_297 , V_141 ) ;
F_63 ( V_91 , V_298 , V_299 ) ;
F_63 ( V_91 , V_300 , V_301 ) ;
}
F_66 ( V_7 -> V_88 , V_88 , V_7 -> V_88 ,
V_89 ) ;
}
static int F_67 ( struct V_6 * V_7 , int type )
{
#if F_28 ( V_29 )
T_6 V_302 ;
int V_54 ;
if ( ! V_7 -> V_25 -> V_30 )
return 0 ;
V_7 -> V_32 . V_33 = V_34 ;
switch ( type ) {
case V_94 :
V_302 = V_303 ;
V_7 -> V_32 . V_33 = V_304 ;
break;
case V_96 :
V_302 = V_305 ;
V_7 -> V_32 . V_33 = V_306 ;
break;
case V_99 :
V_302 = V_307 ;
V_7 -> V_32 . V_33 = V_308 ;
break;
case V_16 :
V_302 = V_309 ;
break;
case V_310 :
V_302 = V_311 ;
break;
default:
return 0 ;
}
if ( V_7 -> V_32 . V_33 != V_34 ) {
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_312 . V_23 . V_313 = V_314 ;
V_7 -> V_32 . V_312 . V_23 . V_27 = V_7 -> V_27 ;
V_54 = F_68 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_54 < 0 ) {
F_47 ( V_315
L_10 ,
V_316 ) ;
return V_54 ;
}
}
V_7 -> V_31 = F_69 ( V_7 -> V_25 -> V_30 ,
V_302 ,
0 , V_314 ,
V_7 -> V_27 ) ;
if ( ! V_7 -> V_31 ) {
F_30 ( & V_7 -> V_32 ) ;
return - V_317 ;
}
if ( V_7 -> V_32 . V_33 != V_34 ) {
struct V_318 * V_319 ;
V_319 = F_70 ( & V_7 -> V_32 ,
& V_7 -> V_31 -> V_320 ,
V_321 ) ;
if ( ! V_319 ) {
F_29 ( V_7 -> V_31 ) ;
F_30 ( & V_7 -> V_32 ) ;
return - V_317 ;
}
}
#endif
return 0 ;
}
int F_71 ( struct V_6 * V_7 , int type , int V_322 ,
int V_323 , struct V_324 * V_325 )
{
int V_87 = 0 ;
int V_54 ;
int V_326 = 0 ;
int V_327 = V_86 ;
const char * V_328 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_35 ) )
return - V_46 ;
if ( F_25 ( ! V_7 -> V_25 ) )
return - V_46 ;
F_72 ( & V_7 -> V_329 ) ;
F_73 ( & V_7 -> V_330 ) ;
switch ( type ) {
case V_94 :
V_328 = L_11 ;
break;
case V_96 :
V_328 = L_12 ;
break;
case V_16 :
V_328 = L_13 ;
break;
case V_310 :
V_328 = L_14 ;
break;
case V_99 :
V_328 = L_15 ;
break;
default:
F_47 ( V_331 L_16 ,
V_316 , type ) ;
return - V_46 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_332 == NULL )
V_7 -> V_332 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_109 == NULL )
V_7 -> V_109 = V_7 -> V_25 -> V_109 ;
if ( V_7 -> V_38 == NULL )
V_7 -> V_38 = & V_7 -> V_25 -> V_38 ;
#ifdef F_74
switch ( type ) {
case V_94 :
V_326 = 0 ;
V_327 = 64 ;
break;
case V_16 :
V_326 = 64 ;
V_327 = 64 ;
break;
case V_96 :
V_326 = 224 ;
V_327 = 32 ;
break;
default:
V_326 = 128 ;
V_327 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_322 = F_12 ( V_7 , V_322 == - 1 ? 0 : V_322 , V_327 ) ;
if ( V_322 == V_327 )
V_322 = F_12 ( V_7 , 0 , V_327 ) ;
if ( V_322 == V_327 ) {
F_47 ( V_331 L_17 ) ;
F_26 ( & V_26 ) ;
return - V_333 ;
}
#ifdef F_74
V_87 = V_322 ;
#else
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ )
if ( V_6 [ V_87 ] == NULL )
break;
if ( V_87 == V_86 ) {
F_26 ( & V_26 ) ;
F_47 ( V_331 L_18 ) ;
return - V_333 ;
}
#endif
V_7 -> V_27 = V_87 + V_326 ;
V_7 -> V_19 = V_322 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_58 ( V_7 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_92 )
F_62 ( V_7 ) ;
V_7 -> V_28 = F_75 () ;
if ( V_7 -> V_28 == NULL ) {
V_54 = - V_317 ;
goto V_334;
}
V_7 -> V_28 -> V_91 = & V_335 ;
V_7 -> V_28 -> V_325 = V_325 ;
V_54 = F_76 ( V_7 -> V_28 , F_77 ( V_314 , V_7 -> V_27 ) , 1 ) ;
if ( V_54 < 0 ) {
F_47 ( V_331 L_19 , V_316 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_334;
}
V_7 -> V_23 . V_336 = & V_337 ;
V_7 -> V_23 . V_338 = F_77 ( V_314 , V_7 -> V_27 ) ;
V_7 -> V_23 . V_339 = V_7 -> V_332 ;
F_78 ( & V_7 -> V_23 , L_20 , V_328 , V_7 -> V_19 ) ;
V_54 = F_79 ( & V_7 -> V_23 ) ;
if ( V_54 < 0 ) {
F_47 ( V_331 L_21 , V_316 ) ;
goto V_334;
}
V_7 -> V_23 . V_35 = F_23 ;
if ( V_322 != - 1 && V_322 != V_7 -> V_19 && V_323 )
F_47 ( V_315 L_22 , V_316 ,
V_328 , V_322 , F_48 ( V_7 ) ) ;
F_80 ( V_7 -> V_25 ) ;
V_54 = F_67 ( V_7 , type ) ;
F_9 ( V_340 , & V_7 -> V_77 ) ;
return 0 ;
V_334:
F_24 ( & V_26 ) ;
if ( V_7 -> V_28 )
F_27 ( V_7 -> V_28 ) ;
V_6 [ V_7 -> V_27 ] = NULL ;
F_10 ( V_7 ) ;
F_26 ( & V_26 ) ;
V_7 -> V_27 = - 1 ;
return V_54 ;
}
void F_81 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_46 ( V_7 ) )
return;
F_24 ( & V_26 ) ;
F_11 ( V_340 , & V_7 -> V_77 ) ;
F_26 ( & V_26 ) ;
F_82 ( & V_7 -> V_23 ) ;
}
static int T_7 F_83 ( void )
{
T_8 V_23 = F_77 ( V_314 , 0 ) ;
int V_54 ;
F_47 ( V_341 L_23 ) ;
V_54 = F_84 ( V_23 , V_86 , V_342 ) ;
if ( V_54 < 0 ) {
F_47 ( V_315 L_24 ,
V_314 ) ;
return V_54 ;
}
V_54 = F_85 ( & V_337 ) ;
if ( V_54 < 0 ) {
F_86 ( V_23 , V_86 ) ;
F_47 ( V_315 L_25 ) ;
return - V_343 ;
}
return 0 ;
}
static void T_9 F_87 ( void )
{
T_8 V_23 = F_77 ( V_314 , 0 ) ;
F_88 ( & V_337 ) ;
F_86 ( V_23 , V_86 ) ;
}
