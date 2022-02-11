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
if ( ( V_7 -> V_9 & V_56 ) &&
( V_7 -> V_9 & V_57 ) )
F_46 ( V_58 L_3 ,
F_47 ( V_7 ) , V_50 , V_52 ) ;
return V_52 ;
}
static T_1 F_48 ( struct V_34 * V_49 , const char T_4 * V_5 ,
T_2 V_50 , T_5 * V_51 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( ! V_7 -> V_54 -> V_59 )
return - V_44 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_59 ( V_49 , V_5 , V_50 , V_51 ) ;
if ( ( V_7 -> V_9 & V_56 ) &&
( V_7 -> V_9 & V_57 ) )
F_46 ( V_58 L_4 ,
F_47 ( V_7 ) , V_50 , V_52 ) ;
return V_52 ;
}
static unsigned int F_49 ( struct V_34 * V_49 , struct V_60 * V_61 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
unsigned int V_11 = V_62 | V_63 ;
if ( ! V_7 -> V_54 -> V_61 )
return V_64 ;
if ( F_45 ( V_7 ) )
V_11 = V_7 -> V_54 -> V_61 ( V_49 , V_61 ) ;
if ( V_7 -> V_9 & V_65 )
F_46 ( V_58 L_5 ,
F_47 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static long F_50 ( struct V_34 * V_49 , unsigned int V_66 , unsigned long V_67 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( V_7 -> V_54 -> V_68 ) {
struct V_69 * V_70 = F_51 ( V_7 , V_66 ) ;
if ( V_70 && F_52 ( V_70 ) )
return - V_71 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_68 ( V_49 , V_66 , V_67 ) ;
if ( V_70 )
F_26 ( V_70 ) ;
} else if ( V_7 -> V_54 -> V_72 ) {
struct V_69 * V_73 = & V_7 -> V_25 -> V_74 ;
if ( V_66 != V_75 && F_52 ( V_73 ) )
return - V_71 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_72 ( V_49 , V_66 , V_67 ) ;
if ( V_66 != V_75 )
F_26 ( V_73 ) ;
} else
V_52 = - V_76 ;
return V_52 ;
}
static unsigned long F_53 ( struct V_34 * V_49 ,
unsigned long V_77 , unsigned long V_10 , unsigned long V_78 ,
unsigned long V_79 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 ;
if ( ! V_7 -> V_54 -> V_80 )
return - V_81 ;
if ( ! F_45 ( V_7 ) )
return - V_53 ;
V_52 = V_7 -> V_54 -> V_80 ( V_49 , V_77 , V_10 , V_78 , V_79 ) ;
if ( V_7 -> V_9 & V_56 )
F_46 ( V_58 L_6 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_54 ( struct V_34 * V_49 , struct V_82 * V_83 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( ! V_7 -> V_54 -> V_84 )
return - V_53 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_84 ( V_49 , V_83 ) ;
if ( V_7 -> V_9 & V_56 )
F_46 ( V_58 L_7 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_55 ( struct V_85 * V_85 , struct V_34 * V_49 )
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
if ( V_7 -> V_54 -> V_86 ) {
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_86 ( V_49 ) ;
else
V_52 = - V_53 ;
}
if ( V_7 -> V_9 & V_56 )
F_46 ( V_58 L_8 ,
F_47 ( V_7 ) , V_52 ) ;
if ( V_52 )
F_21 ( V_7 ) ;
return V_52 ;
}
static int F_56 ( struct V_85 * V_85 , struct V_34 * V_49 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = 0 ;
if ( V_7 -> V_54 -> V_33 )
V_52 = V_7 -> V_54 -> V_33 ( V_49 ) ;
if ( V_7 -> V_9 & V_56 )
F_46 ( V_58 L_9 ,
F_47 ( V_7 ) ) ;
F_21 ( V_7 ) ;
return V_52 ;
}
static int F_57 ( struct V_6 * V_7 )
{
static F_58 ( V_87 , V_88 ) ;
int V_89 ;
F_59 ( V_87 , V_88 ) ;
for ( V_89 = 0 ; V_89 < V_88 ; V_89 ++ ) {
if ( V_6 [ V_89 ] != NULL &&
V_6 [ V_89 ] -> V_25 == V_7 -> V_25 ) {
F_9 ( V_6 [ V_89 ] -> V_8 , V_87 ) ;
}
}
return F_60 ( V_87 , V_88 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_58 ( V_90 , V_91 ) ;
const struct V_92 * V_93 = V_7 -> V_94 ;
bool V_95 = V_7 -> V_14 == V_96 ;
bool V_97 = V_7 -> V_14 == V_98 ;
bool V_99 = V_7 -> V_14 == V_16 ;
bool V_100 = V_7 -> V_14 == V_101 ;
bool V_102 = V_7 -> V_103 != V_104 ;
bool V_105 = V_7 -> V_103 != V_106 ;
F_59 ( V_90 , V_91 ) ;
F_62 ( V_93 , V_107 , V_108 ) ;
if ( V_93 -> V_109 )
F_9 ( F_63 ( V_110 ) , V_90 ) ;
if ( V_93 -> V_111 )
F_9 ( F_63 ( V_112 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_114 )
F_9 ( F_63 ( V_115 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_116 )
F_9 ( F_63 ( V_117 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_118 || V_93 -> V_119 )
F_9 ( F_63 ( V_120 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_121 || V_93 -> V_122 )
F_9 ( F_63 ( V_123 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_119 )
F_9 ( F_63 ( V_124 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_122 )
F_9 ( F_63 ( V_125 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_126 )
F_9 ( F_63 ( V_127 ) , V_90 ) ;
if ( V_7 -> V_113 || V_93 -> V_128 )
F_9 ( F_63 ( V_129 ) , V_90 ) ;
F_62 ( V_93 , V_130 , V_131 ) ;
F_62 ( V_93 , V_132 , V_133 ) ;
F_62 ( V_93 , V_134 , V_135 ) ;
#ifdef F_64
F_9 ( F_63 ( V_136 ) , V_90 ) ;
F_9 ( F_63 ( V_137 ) , V_90 ) ;
F_9 ( F_63 ( V_138 ) , V_90 ) ;
#endif
F_62 ( V_93 , V_139 , V_140 ) ;
F_62 ( V_93 , V_141 , V_140 ) ;
F_62 ( V_93 , V_142 , V_143 ) ;
if ( V_93 -> V_144 || V_93 -> V_145 || V_93 -> V_146 )
F_9 ( F_63 ( V_147 ) , V_90 ) ;
if ( V_95 ) {
if ( ( V_102 && ( V_93 -> V_148 ||
V_93 -> V_149 ||
V_93 -> V_150 ) ) ||
( V_105 && ( V_93 -> V_151 ||
V_93 -> V_152 ) ) )
F_9 ( F_63 ( V_153 ) , V_90 ) ;
if ( ( V_102 && ( V_93 -> V_154 ||
V_93 -> V_155 ||
V_93 -> V_156 ) ) ||
( V_105 && ( V_93 -> V_157 ||
V_93 -> V_158 ||
V_93 -> V_159 ) ) )
F_9 ( F_63 ( V_160 ) , V_90 ) ;
if ( ( V_102 && ( V_93 -> V_161 ||
V_93 -> V_162 ||
V_93 -> V_163 ) ) ||
( V_105 && ( V_93 -> V_164 ||
V_93 -> V_165 ||
V_93 -> V_166 ) ) )
F_9 ( F_63 ( V_167 ) , V_90 ) ;
if ( ( V_102 && ( V_93 -> V_168 ||
V_93 -> V_169 ||
V_93 -> V_170 ) ) ||
( V_105 && ( V_93 -> V_171 ||
V_93 -> V_172 ||
V_93 -> V_173 ) ) )
F_9 ( F_63 ( V_174 ) , V_90 ) ;
F_62 ( V_93 , V_175 , V_176 ) ;
F_62 ( V_93 , V_177 , V_178 ) ;
F_62 ( V_93 , V_179 , V_180 ) ;
F_62 ( V_93 , V_181 , V_182 ) ;
F_62 ( V_93 , V_183 , V_184 ) ;
F_62 ( V_93 , V_185 , V_186 ) ;
F_62 ( V_93 , V_187 , V_188 ) ;
F_62 ( V_93 , V_189 , V_190 ) ;
F_62 ( V_93 , V_191 , V_192 ) ;
F_62 ( V_93 , V_193 , V_194 ) ;
F_62 ( V_93 , V_195 , V_196 ) ;
F_62 ( V_93 , V_197 , V_198 ) ;
} else if ( V_97 ) {
if ( ( V_102 && ( V_93 -> V_199 ||
V_93 -> V_200 ) ) ||
( V_105 && ( V_93 -> V_201 ||
V_93 -> V_202 ) ) )
F_9 ( F_63 ( V_160 ) , V_90 ) ;
if ( ( V_102 && ( V_93 -> V_203 ||
V_93 -> V_204 ) ) ||
( V_105 && ( V_93 -> V_205 ||
V_93 -> V_206 ) ) )
F_9 ( F_63 ( V_167 ) , V_90 ) ;
if ( ( V_102 && ( V_93 -> V_207 ||
V_93 -> V_208 ) ) ||
( V_105 && ( V_93 -> V_209 ||
V_93 -> V_210 ) ) )
F_9 ( F_63 ( V_174 ) , V_90 ) ;
F_62 ( V_93 , V_211 , V_212 ) ;
} else if ( V_100 ) {
if ( V_93 -> V_213 )
F_9 ( F_63 ( V_153 ) , V_90 ) ;
if ( V_93 -> V_214 )
F_9 ( F_63 ( V_160 ) , V_90 ) ;
if ( V_93 -> V_215 )
F_9 ( F_63 ( V_167 ) , V_90 ) ;
if ( V_93 -> V_216 )
F_9 ( F_63 ( V_174 ) , V_90 ) ;
}
if ( V_95 || V_97 || V_100 ) {
F_62 ( V_93 , V_217 , V_218 ) ;
F_62 ( V_93 , V_219 , V_220 ) ;
F_62 ( V_93 , V_221 , V_222 ) ;
F_62 ( V_93 , V_223 , V_224 ) ;
F_62 ( V_93 , V_75 , V_225 ) ;
F_62 ( V_93 , V_226 , V_227 ) ;
F_62 ( V_93 , V_228 , V_229 ) ;
F_62 ( V_93 , V_230 , V_231 ) ;
F_62 ( V_93 , V_232 , V_233 ) ;
}
if ( V_95 || V_97 ) {
if ( V_93 -> V_234 )
F_9 ( F_63 ( V_235 ) , V_90 ) ;
F_62 ( V_93 , V_236 , V_234 ) ;
F_62 ( V_93 , V_237 , V_238 ) ;
if ( V_102 ) {
F_62 ( V_93 , V_239 , V_240 ) ;
F_62 ( V_93 , V_241 , V_242 ) ;
F_62 ( V_93 , V_243 , V_244 ) ;
F_62 ( V_93 , V_245 , V_246 ) ;
F_62 ( V_93 , V_247 , V_248 ) ;
F_62 ( V_93 , V_249 , V_250 ) ;
F_62 ( V_93 , V_251 , V_252 ) ;
F_62 ( V_93 , V_253 , V_254 ) ;
F_62 ( V_93 , V_255 , V_256 ) ;
}
if ( V_105 ) {
F_62 ( V_93 , V_257 , V_258 ) ;
F_62 ( V_93 , V_259 , V_260 ) ;
F_62 ( V_93 , V_261 , V_262 ) ;
F_62 ( V_93 , V_263 , V_264 ) ;
F_62 ( V_93 , V_265 , V_266 ) ;
F_62 ( V_93 , V_267 , V_268 ) ;
}
if ( V_93 -> V_269 || V_93 -> V_270 )
F_9 ( F_63 ( V_271 ) , V_90 ) ;
if ( V_93 -> V_272 || V_93 -> V_273 )
F_9 ( F_63 ( V_274 ) , V_90 ) ;
F_62 ( V_93 , V_275 , V_270 ) ;
F_62 ( V_93 , V_276 , V_273 ) ;
if ( V_93 -> V_277 || V_93 -> V_270 )
F_9 ( F_63 ( V_278 ) , V_90 ) ;
if ( V_93 -> V_279 || ( V_7 -> V_14 == V_96 &&
V_93 -> V_238 ) )
F_9 ( F_63 ( V_280 ) , V_90 ) ;
F_62 ( V_93 , V_281 , V_282 ) ;
F_62 ( V_93 , V_283 , V_284 ) ;
F_62 ( V_93 , V_285 , V_286 ) ;
F_62 ( V_93 , V_287 , V_288 ) ;
F_62 ( V_93 , V_289 , V_290 ) ;
F_62 ( V_93 , V_291 , V_292 ) ;
}
if ( V_105 && ( V_99 || V_100 ) ) {
F_62 ( V_93 , V_293 , V_146 ) ;
F_62 ( V_93 , V_294 , V_295 ) ;
}
if ( V_102 ) {
F_62 ( V_93 , V_296 , V_145 ) ;
F_62 ( V_93 , V_297 , V_298 ) ;
F_62 ( V_93 , V_299 , V_300 ) ;
}
F_65 ( V_7 -> V_90 , V_90 , V_7 -> V_90 ,
V_91 ) ;
}
int F_66 ( struct V_6 * V_7 , int type , int V_301 ,
int V_302 , struct V_303 * V_304 )
{
int V_89 = 0 ;
int V_52 ;
int V_305 = 0 ;
int V_306 = V_88 ;
const char * V_307 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_33 ) )
return - V_44 ;
if ( F_25 ( ! V_7 -> V_25 ) )
return - V_44 ;
F_67 ( & V_7 -> V_308 ) ;
F_68 ( & V_7 -> V_309 ) ;
switch ( type ) {
case V_96 :
V_307 = L_10 ;
break;
case V_98 :
V_307 = L_11 ;
break;
case V_16 :
V_307 = L_12 ;
break;
case V_31 :
V_307 = L_13 ;
break;
case V_101 :
V_307 = L_14 ;
break;
default:
F_46 ( V_310 L_15 ,
V_311 , type ) ;
return - V_44 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_312 == NULL )
V_7 -> V_312 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_113 == NULL )
V_7 -> V_113 = V_7 -> V_25 -> V_113 ;
if ( V_7 -> V_36 == NULL )
V_7 -> V_36 = & V_7 -> V_25 -> V_36 ;
#ifdef F_69
switch ( type ) {
case V_96 :
V_305 = 0 ;
V_306 = 64 ;
break;
case V_16 :
V_305 = 64 ;
V_306 = 64 ;
break;
case V_98 :
V_305 = 224 ;
V_306 = 32 ;
break;
default:
V_305 = 128 ;
V_306 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_301 = F_12 ( V_7 , V_301 == - 1 ? 0 : V_301 , V_306 ) ;
if ( V_301 == V_306 )
V_301 = F_12 ( V_7 , 0 , V_306 ) ;
if ( V_301 == V_306 ) {
F_46 ( V_310 L_16 ) ;
F_26 ( & V_26 ) ;
return - V_313 ;
}
#ifdef F_69
V_89 = V_301 ;
#else
for ( V_89 = 0 ; V_89 < V_88 ; V_89 ++ )
if ( V_6 [ V_89 ] == NULL )
break;
if ( V_89 == V_88 ) {
F_26 ( & V_26 ) ;
F_46 ( V_310 L_17 ) ;
return - V_313 ;
}
#endif
V_7 -> V_27 = V_89 + V_305 ;
V_7 -> V_19 = V_301 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_57 ( V_7 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_94 )
F_61 ( V_7 ) ;
V_7 -> V_28 = F_70 () ;
if ( V_7 -> V_28 == NULL ) {
V_52 = - V_314 ;
goto V_315;
}
V_7 -> V_28 -> V_93 = & V_316 ;
V_7 -> V_28 -> V_304 = V_304 ;
V_52 = F_71 ( V_7 -> V_28 , F_72 ( V_317 , V_7 -> V_27 ) , 1 ) ;
if ( V_52 < 0 ) {
F_46 ( V_310 L_18 , V_311 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_315;
}
V_7 -> V_23 . V_318 = & V_319 ;
V_7 -> V_23 . V_320 = F_72 ( V_317 , V_7 -> V_27 ) ;
V_7 -> V_23 . V_321 = V_7 -> V_312 ;
F_73 ( & V_7 -> V_23 , L_19 , V_307 , V_7 -> V_19 ) ;
V_52 = F_74 ( & V_7 -> V_23 ) ;
if ( V_52 < 0 ) {
F_46 ( V_310 L_20 , V_311 ) ;
goto V_315;
}
V_7 -> V_23 . V_33 = F_23 ;
if ( V_301 != - 1 && V_301 != V_7 -> V_19 && V_302 )
F_46 ( V_322 L_21 , V_311 ,
V_307 , V_301 , F_47 ( V_7 ) ) ;
F_75 ( V_7 -> V_25 ) ;
#if F_28 ( V_29 )
if ( V_7 -> V_25 -> V_30 &&
V_7 -> V_14 != V_31 ) {
V_7 -> V_32 . type = V_323 ;
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_324 . V_325 . V_326 = V_317 ;
V_7 -> V_32 . V_324 . V_325 . V_27 = V_7 -> V_27 ;
V_52 = F_76 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_52 < 0 )
F_46 ( V_322
L_22 ,
V_311 ) ;
}
#endif
F_9 ( V_327 , & V_7 -> V_79 ) ;
return 0 ;
V_315:
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
F_11 ( V_327 , & V_7 -> V_79 ) ;
F_26 ( & V_26 ) ;
F_78 ( & V_7 -> V_23 ) ;
}
static int T_6 F_79 ( void )
{
T_7 V_23 = F_72 ( V_317 , 0 ) ;
int V_52 ;
F_46 ( V_328 L_23 ) ;
V_52 = F_80 ( V_23 , V_88 , V_329 ) ;
if ( V_52 < 0 ) {
F_46 ( V_322 L_24 ,
V_317 ) ;
return V_52 ;
}
V_52 = F_81 ( & V_319 ) ;
if ( V_52 < 0 ) {
F_82 ( V_23 , V_88 ) ;
F_46 ( V_322 L_25 ) ;
return - V_330 ;
}
return 0 ;
}
static void T_8 F_83 ( void )
{
T_7 V_23 = F_72 ( V_317 , 0 ) ;
F_84 ( & V_319 ) ;
F_82 ( V_23 , V_88 ) ;
}
