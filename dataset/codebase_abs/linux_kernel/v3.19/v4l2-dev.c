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
if ( V_25 -> V_30 &&
V_7 -> V_14 != V_31 )
F_29 ( & V_7 -> V_32 ) ;
#endif
if ( V_25 -> V_33 == NULL )
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
if ( V_7 -> V_9 > 2 )
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
struct V_66 * V_70 = & V_7 -> V_25 -> V_71 ;
if ( V_63 != V_72 && F_52 ( V_70 ) )
return - V_68 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_69 ( V_49 , V_63 , V_64 ) ;
if ( V_63 != V_72 )
F_26 ( V_70 ) ;
} else
V_52 = - V_73 ;
return V_52 ;
}
static unsigned long F_53 ( struct V_34 * V_49 ,
unsigned long V_74 , unsigned long V_10 , unsigned long V_75 ,
unsigned long V_76 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 ;
if ( ! V_7 -> V_54 -> V_77 )
return - V_78 ;
if ( ! F_45 ( V_7 ) )
return - V_53 ;
V_52 = V_7 -> V_54 -> V_77 ( V_49 , V_74 , V_10 , V_75 , V_76 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_6 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_54 ( struct V_34 * V_49 , struct V_79 * V_80 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( ! V_7 -> V_54 -> V_81 )
return - V_53 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_81 ( V_49 , V_80 ) ;
if ( V_7 -> V_9 )
F_46 ( V_56 L_7 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_55 ( struct V_82 * V_82 , struct V_34 * V_49 )
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
if ( V_7 -> V_54 -> V_83 ) {
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_83 ( V_49 ) ;
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
static int F_56 ( struct V_82 * V_82 , struct V_34 * V_49 )
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
static int F_57 ( struct V_6 * V_7 )
{
static F_58 ( V_84 , V_85 ) ;
int V_86 ;
F_59 ( V_84 , V_85 ) ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
if ( V_6 [ V_86 ] != NULL &&
V_6 [ V_86 ] -> V_25 == V_7 -> V_25 ) {
F_9 ( V_6 [ V_86 ] -> V_8 , V_84 ) ;
}
}
return F_60 ( V_84 , V_85 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_58 ( V_87 , V_88 ) ;
const struct V_89 * V_90 = V_7 -> V_91 ;
bool V_92 = V_7 -> V_14 == V_93 ;
bool V_94 = V_7 -> V_14 == V_95 ;
bool V_96 = V_7 -> V_14 == V_16 ;
bool V_97 = V_7 -> V_14 == V_98 ;
bool V_99 = V_7 -> V_100 != V_101 ;
bool V_102 = V_7 -> V_100 != V_103 ;
F_59 ( V_87 , V_88 ) ;
F_62 ( V_90 , V_104 , V_105 ) ;
if ( V_90 -> V_106 )
F_9 ( F_63 ( V_107 ) , V_87 ) ;
if ( V_90 -> V_108 )
F_9 ( F_63 ( V_109 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_111 )
F_9 ( F_63 ( V_112 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_113 )
F_9 ( F_63 ( V_114 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_115 || V_90 -> V_116 )
F_9 ( F_63 ( V_117 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_118 || V_90 -> V_119 )
F_9 ( F_63 ( V_120 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_116 )
F_9 ( F_63 ( V_121 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_119 )
F_9 ( F_63 ( V_122 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_123 )
F_9 ( F_63 ( V_124 ) , V_87 ) ;
if ( V_7 -> V_110 || V_90 -> V_125 )
F_9 ( F_63 ( V_126 ) , V_87 ) ;
F_62 ( V_90 , V_127 , V_128 ) ;
F_62 ( V_90 , V_129 , V_130 ) ;
F_62 ( V_90 , V_131 , V_132 ) ;
#ifdef F_64
F_9 ( F_63 ( V_133 ) , V_87 ) ;
F_9 ( F_63 ( V_134 ) , V_87 ) ;
F_9 ( F_63 ( V_135 ) , V_87 ) ;
#endif
F_62 ( V_90 , V_136 , V_137 ) ;
F_62 ( V_90 , V_138 , V_137 ) ;
F_62 ( V_90 , V_139 , V_140 ) ;
if ( V_90 -> V_141 || V_90 -> V_142 || V_90 -> V_143 )
F_9 ( F_63 ( V_144 ) , V_87 ) ;
if ( V_92 ) {
if ( ( V_99 && ( V_90 -> V_145 ||
V_90 -> V_146 ||
V_90 -> V_147 ) ) ||
( V_102 && ( V_90 -> V_148 ||
V_90 -> V_149 ) ) )
F_9 ( F_63 ( V_150 ) , V_87 ) ;
if ( ( V_99 && ( V_90 -> V_151 ||
V_90 -> V_152 ||
V_90 -> V_153 ) ) ||
( V_102 && ( V_90 -> V_154 ||
V_90 -> V_155 ||
V_90 -> V_156 ) ) )
F_9 ( F_63 ( V_157 ) , V_87 ) ;
if ( ( V_99 && ( V_90 -> V_158 ||
V_90 -> V_159 ||
V_90 -> V_160 ) ) ||
( V_102 && ( V_90 -> V_161 ||
V_90 -> V_162 ||
V_90 -> V_163 ) ) )
F_9 ( F_63 ( V_164 ) , V_87 ) ;
if ( ( V_99 && ( V_90 -> V_165 ||
V_90 -> V_166 ||
V_90 -> V_167 ) ) ||
( V_102 && ( V_90 -> V_168 ||
V_90 -> V_169 ||
V_90 -> V_170 ) ) )
F_9 ( F_63 ( V_171 ) , V_87 ) ;
F_62 ( V_90 , V_172 , V_173 ) ;
F_62 ( V_90 , V_174 , V_175 ) ;
F_62 ( V_90 , V_176 , V_177 ) ;
F_62 ( V_90 , V_178 , V_179 ) ;
F_62 ( V_90 , V_180 , V_181 ) ;
F_62 ( V_90 , V_182 , V_183 ) ;
F_62 ( V_90 , V_184 , V_185 ) ;
F_62 ( V_90 , V_186 , V_187 ) ;
F_62 ( V_90 , V_188 , V_189 ) ;
F_62 ( V_90 , V_190 , V_191 ) ;
F_62 ( V_90 , V_192 , V_193 ) ;
F_62 ( V_90 , V_194 , V_195 ) ;
} else if ( V_94 ) {
if ( ( V_99 && ( V_90 -> V_196 ||
V_90 -> V_197 ) ) ||
( V_102 && ( V_90 -> V_198 ||
V_90 -> V_199 ) ) )
F_9 ( F_63 ( V_157 ) , V_87 ) ;
if ( ( V_99 && ( V_90 -> V_200 ||
V_90 -> V_201 ) ) ||
( V_102 && ( V_90 -> V_202 ||
V_90 -> V_203 ) ) )
F_9 ( F_63 ( V_164 ) , V_87 ) ;
if ( ( V_99 && ( V_90 -> V_204 ||
V_90 -> V_205 ) ) ||
( V_102 && ( V_90 -> V_206 ||
V_90 -> V_207 ) ) )
F_9 ( F_63 ( V_171 ) , V_87 ) ;
F_62 ( V_90 , V_208 , V_209 ) ;
} else if ( V_97 ) {
if ( V_90 -> V_210 )
F_9 ( F_63 ( V_150 ) , V_87 ) ;
if ( V_90 -> V_211 )
F_9 ( F_63 ( V_157 ) , V_87 ) ;
if ( V_90 -> V_212 )
F_9 ( F_63 ( V_164 ) , V_87 ) ;
if ( V_90 -> V_213 )
F_9 ( F_63 ( V_171 ) , V_87 ) ;
}
if ( V_92 || V_94 || V_97 ) {
F_62 ( V_90 , V_214 , V_215 ) ;
F_62 ( V_90 , V_216 , V_217 ) ;
F_62 ( V_90 , V_218 , V_219 ) ;
F_62 ( V_90 , V_220 , V_221 ) ;
F_62 ( V_90 , V_72 , V_222 ) ;
F_62 ( V_90 , V_223 , V_224 ) ;
F_62 ( V_90 , V_225 , V_226 ) ;
F_62 ( V_90 , V_227 , V_228 ) ;
F_62 ( V_90 , V_229 , V_230 ) ;
}
if ( V_92 || V_94 ) {
if ( V_90 -> V_231 )
F_9 ( F_63 ( V_232 ) , V_87 ) ;
F_62 ( V_90 , V_233 , V_231 ) ;
F_62 ( V_90 , V_234 , V_235 ) ;
if ( V_99 ) {
F_62 ( V_90 , V_236 , V_237 ) ;
F_62 ( V_90 , V_238 , V_239 ) ;
F_62 ( V_90 , V_240 , V_241 ) ;
F_62 ( V_90 , V_242 , V_243 ) ;
F_62 ( V_90 , V_244 , V_245 ) ;
F_62 ( V_90 , V_246 , V_247 ) ;
F_62 ( V_90 , V_248 , V_249 ) ;
F_62 ( V_90 , V_250 , V_251 ) ;
F_62 ( V_90 , V_252 , V_253 ) ;
}
if ( V_102 ) {
F_62 ( V_90 , V_254 , V_255 ) ;
F_62 ( V_90 , V_256 , V_257 ) ;
F_62 ( V_90 , V_258 , V_259 ) ;
F_62 ( V_90 , V_260 , V_261 ) ;
F_62 ( V_90 , V_262 , V_263 ) ;
F_62 ( V_90 , V_264 , V_265 ) ;
}
if ( V_90 -> V_266 || V_90 -> V_267 )
F_9 ( F_63 ( V_268 ) , V_87 ) ;
if ( V_90 -> V_269 || V_90 -> V_270 )
F_9 ( F_63 ( V_271 ) , V_87 ) ;
F_62 ( V_90 , V_272 , V_267 ) ;
F_62 ( V_90 , V_273 , V_270 ) ;
if ( V_90 -> V_274 || V_90 -> V_267 )
F_9 ( F_63 ( V_275 ) , V_87 ) ;
if ( V_90 -> V_276 || ( V_7 -> V_14 == V_93 &&
V_90 -> V_235 ) )
F_9 ( F_63 ( V_277 ) , V_87 ) ;
F_62 ( V_90 , V_278 , V_279 ) ;
F_62 ( V_90 , V_280 , V_281 ) ;
F_62 ( V_90 , V_282 , V_283 ) ;
F_62 ( V_90 , V_284 , V_285 ) ;
F_62 ( V_90 , V_286 , V_287 ) ;
F_62 ( V_90 , V_288 , V_289 ) ;
}
if ( V_102 && ( V_96 || V_97 ) ) {
F_62 ( V_90 , V_290 , V_143 ) ;
F_62 ( V_90 , V_291 , V_292 ) ;
}
if ( V_99 ) {
F_62 ( V_90 , V_293 , V_142 ) ;
F_62 ( V_90 , V_294 , V_295 ) ;
F_62 ( V_90 , V_296 , V_297 ) ;
}
F_65 ( V_7 -> V_87 , V_87 , V_7 -> V_87 ,
V_88 ) ;
}
int F_66 ( struct V_6 * V_7 , int type , int V_298 ,
int V_299 , struct V_300 * V_301 )
{
int V_86 = 0 ;
int V_52 ;
int V_302 = 0 ;
int V_303 = V_85 ;
const char * V_304 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_33 ) )
return - V_44 ;
if ( F_25 ( ! V_7 -> V_25 ) )
return - V_44 ;
F_67 ( & V_7 -> V_305 ) ;
F_68 ( & V_7 -> V_306 ) ;
switch ( type ) {
case V_93 :
V_304 = L_10 ;
break;
case V_95 :
V_304 = L_11 ;
break;
case V_16 :
V_304 = L_12 ;
break;
case V_31 :
V_304 = L_13 ;
break;
case V_98 :
V_304 = L_14 ;
break;
default:
F_46 ( V_307 L_15 ,
V_308 , type ) ;
return - V_44 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_309 == NULL )
V_7 -> V_309 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_110 == NULL )
V_7 -> V_110 = V_7 -> V_25 -> V_110 ;
if ( V_7 -> V_36 == NULL )
V_7 -> V_36 = & V_7 -> V_25 -> V_36 ;
#ifdef F_69
switch ( type ) {
case V_93 :
V_302 = 0 ;
V_303 = 64 ;
break;
case V_16 :
V_302 = 64 ;
V_303 = 64 ;
break;
case V_95 :
V_302 = 224 ;
V_303 = 32 ;
break;
default:
V_302 = 128 ;
V_303 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_298 = F_12 ( V_7 , V_298 == - 1 ? 0 : V_298 , V_303 ) ;
if ( V_298 == V_303 )
V_298 = F_12 ( V_7 , 0 , V_303 ) ;
if ( V_298 == V_303 ) {
F_46 ( V_307 L_16 ) ;
F_26 ( & V_26 ) ;
return - V_310 ;
}
#ifdef F_69
V_86 = V_298 ;
#else
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ )
if ( V_6 [ V_86 ] == NULL )
break;
if ( V_86 == V_85 ) {
F_26 ( & V_26 ) ;
F_46 ( V_307 L_17 ) ;
return - V_310 ;
}
#endif
V_7 -> V_27 = V_86 + V_302 ;
V_7 -> V_19 = V_298 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_57 ( V_7 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_91 )
F_61 ( V_7 ) ;
V_7 -> V_28 = F_70 () ;
if ( V_7 -> V_28 == NULL ) {
V_52 = - V_311 ;
goto V_312;
}
V_7 -> V_28 -> V_90 = & V_313 ;
V_7 -> V_28 -> V_301 = V_301 ;
V_52 = F_71 ( V_7 -> V_28 , F_72 ( V_314 , V_7 -> V_27 ) , 1 ) ;
if ( V_52 < 0 ) {
F_46 ( V_307 L_18 , V_308 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_312;
}
V_7 -> V_23 . V_315 = & V_316 ;
V_7 -> V_23 . V_317 = F_72 ( V_314 , V_7 -> V_27 ) ;
V_7 -> V_23 . V_318 = V_7 -> V_309 ;
F_73 ( & V_7 -> V_23 , L_19 , V_304 , V_7 -> V_19 ) ;
V_52 = F_74 ( & V_7 -> V_23 ) ;
if ( V_52 < 0 ) {
F_46 ( V_307 L_20 , V_308 ) ;
goto V_312;
}
V_7 -> V_23 . V_33 = F_23 ;
if ( V_298 != - 1 && V_298 != V_7 -> V_19 && V_299 )
F_46 ( V_319 L_21 , V_308 ,
V_304 , V_298 , F_47 ( V_7 ) ) ;
F_75 ( V_7 -> V_25 ) ;
#if F_28 ( V_29 )
if ( V_7 -> V_25 -> V_30 &&
V_7 -> V_14 != V_31 ) {
V_7 -> V_32 . type = V_320 ;
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_321 . V_322 . V_323 = V_314 ;
V_7 -> V_32 . V_321 . V_322 . V_27 = V_7 -> V_27 ;
V_52 = F_76 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_52 < 0 )
F_46 ( V_319
L_22 ,
V_308 ) ;
}
#endif
F_9 ( V_324 , & V_7 -> V_76 ) ;
return 0 ;
V_312:
F_24 ( & V_26 ) ;
if ( V_7 -> V_28 )
F_27 ( V_7 -> V_28 ) ;
V_6 [ V_7 -> V_27 ] = NULL ;
F_10 ( V_7 ) ;
F_26 ( & V_26 ) ;
V_7 -> V_27 = - 1 ;
return V_52 ;
}
void F_77 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_45 ( V_7 ) )
return;
F_24 ( & V_26 ) ;
F_11 ( V_324 , & V_7 -> V_76 ) ;
F_26 ( & V_26 ) ;
F_78 ( & V_7 -> V_23 ) ;
}
static int T_6 F_79 ( void )
{
T_7 V_23 = F_72 ( V_314 , 0 ) ;
int V_52 ;
F_46 ( V_325 L_23 ) ;
V_52 = F_80 ( V_23 , V_85 , V_326 ) ;
if ( V_52 < 0 ) {
F_46 ( V_319 L_24 ,
V_314 ) ;
return V_52 ;
}
V_52 = F_81 ( & V_316 ) ;
if ( V_52 < 0 ) {
F_82 ( V_23 , V_85 ) ;
F_46 ( V_319 L_25 ) ;
return - V_327 ;
}
return 0 ;
}
static void T_8 F_83 ( void )
{
T_7 V_23 = F_72 ( V_314 , 0 ) ;
F_84 ( & V_316 ) ;
F_82 ( V_23 , V_85 ) ;
}
