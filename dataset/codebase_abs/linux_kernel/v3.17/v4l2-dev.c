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
if ( V_91 -> V_107 )
F_9 ( F_64 ( V_108 ) , V_88 ) ;
if ( V_91 -> V_109 )
F_9 ( F_64 ( V_110 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_112 )
F_9 ( F_64 ( V_113 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_114 )
F_9 ( F_64 ( V_115 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_116 || V_91 -> V_117 )
F_9 ( F_64 ( V_118 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_119 || V_91 -> V_120 )
F_9 ( F_64 ( V_121 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_117 )
F_9 ( F_64 ( V_122 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_120 )
F_9 ( F_64 ( V_123 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_124 )
F_9 ( F_64 ( V_125 ) , V_88 ) ;
if ( V_7 -> V_111 || V_91 -> V_126 )
F_9 ( F_64 ( V_127 ) , V_88 ) ;
F_63 ( V_91 , V_128 , V_129 ) ;
F_63 ( V_91 , V_130 , V_131 ) ;
F_63 ( V_91 , V_132 , V_133 ) ;
#ifdef F_65
F_9 ( F_64 ( V_134 ) , V_88 ) ;
F_9 ( F_64 ( V_135 ) , V_88 ) ;
F_9 ( F_64 ( V_136 ) , V_88 ) ;
#endif
F_63 ( V_91 , V_137 , V_138 ) ;
F_63 ( V_91 , V_139 , V_138 ) ;
F_63 ( V_91 , V_140 , V_141 ) ;
if ( V_91 -> V_142 || V_91 -> V_143 || V_91 -> V_144 )
F_9 ( F_64 ( V_145 ) , V_88 ) ;
if ( V_93 ) {
if ( ( V_100 && ( V_91 -> V_146 ||
V_91 -> V_147 ||
V_91 -> V_148 ) ) ||
( V_103 && ( V_91 -> V_149 ||
V_91 -> V_150 ) ) )
F_9 ( F_64 ( V_151 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_152 ||
V_91 -> V_153 ||
V_91 -> V_154 ) ) ||
( V_103 && ( V_91 -> V_155 ||
V_91 -> V_156 ||
V_91 -> V_157 ) ) )
F_9 ( F_64 ( V_158 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_159 ||
V_91 -> V_160 ||
V_91 -> V_161 ) ) ||
( V_103 && ( V_91 -> V_162 ||
V_91 -> V_163 ||
V_91 -> V_164 ) ) )
F_9 ( F_64 ( V_165 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_166 ||
V_91 -> V_167 ||
V_91 -> V_168 ) ) ||
( V_103 && ( V_91 -> V_169 ||
V_91 -> V_170 ||
V_91 -> V_171 ) ) )
F_9 ( F_64 ( V_172 ) , V_88 ) ;
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
F_63 ( V_91 , V_195 , V_196 ) ;
} else if ( V_95 ) {
if ( ( V_100 && ( V_91 -> V_197 ||
V_91 -> V_198 ) ) ||
( V_103 && ( V_91 -> V_199 ||
V_91 -> V_200 ) ) )
F_9 ( F_64 ( V_158 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_201 ||
V_91 -> V_202 ) ) ||
( V_103 && ( V_91 -> V_203 ||
V_91 -> V_204 ) ) )
F_9 ( F_64 ( V_165 ) , V_88 ) ;
if ( ( V_100 && ( V_91 -> V_205 ||
V_91 -> V_206 ) ) ||
( V_103 && ( V_91 -> V_207 ||
V_91 -> V_208 ) ) )
F_9 ( F_64 ( V_172 ) , V_88 ) ;
F_63 ( V_91 , V_209 , V_210 ) ;
} else if ( V_98 ) {
if ( V_91 -> V_211 )
F_9 ( F_64 ( V_151 ) , V_88 ) ;
if ( V_91 -> V_212 )
F_9 ( F_64 ( V_158 ) , V_88 ) ;
if ( V_91 -> V_213 )
F_9 ( F_64 ( V_165 ) , V_88 ) ;
if ( V_91 -> V_214 )
F_9 ( F_64 ( V_172 ) , V_88 ) ;
}
if ( V_93 || V_95 || V_98 ) {
F_63 ( V_91 , V_215 , V_216 ) ;
F_63 ( V_91 , V_217 , V_218 ) ;
F_63 ( V_91 , V_219 , V_220 ) ;
F_63 ( V_91 , V_221 , V_222 ) ;
F_63 ( V_91 , V_73 , V_223 ) ;
F_63 ( V_91 , V_224 , V_225 ) ;
F_63 ( V_91 , V_226 , V_227 ) ;
F_63 ( V_91 , V_228 , V_229 ) ;
F_63 ( V_91 , V_230 , V_231 ) ;
}
if ( V_93 || V_95 ) {
if ( V_91 -> V_232 )
F_9 ( F_64 ( V_233 ) , V_88 ) ;
F_63 ( V_91 , V_234 , V_232 ) ;
F_63 ( V_91 , V_235 , V_236 ) ;
if ( V_100 ) {
F_63 ( V_91 , V_237 , V_238 ) ;
F_63 ( V_91 , V_239 , V_240 ) ;
F_63 ( V_91 , V_241 , V_242 ) ;
F_63 ( V_91 , V_243 , V_244 ) ;
F_63 ( V_91 , V_245 , V_246 ) ;
F_63 ( V_91 , V_247 , V_248 ) ;
F_63 ( V_91 , V_249 , V_250 ) ;
F_63 ( V_91 , V_251 , V_252 ) ;
F_63 ( V_91 , V_253 , V_254 ) ;
}
if ( V_103 ) {
F_63 ( V_91 , V_255 , V_256 ) ;
F_63 ( V_91 , V_257 , V_258 ) ;
F_63 ( V_91 , V_259 , V_260 ) ;
F_63 ( V_91 , V_261 , V_262 ) ;
F_63 ( V_91 , V_263 , V_264 ) ;
F_63 ( V_91 , V_265 , V_266 ) ;
}
if ( V_91 -> V_267 || V_91 -> V_268 )
F_9 ( F_64 ( V_269 ) , V_88 ) ;
if ( V_91 -> V_270 || V_91 -> V_271 )
F_9 ( F_64 ( V_272 ) , V_88 ) ;
F_63 ( V_91 , V_273 , V_268 ) ;
F_63 ( V_91 , V_274 , V_271 ) ;
if ( V_91 -> V_275 || V_91 -> V_268 )
F_9 ( F_64 ( V_276 ) , V_88 ) ;
if ( V_91 -> V_277 || ( V_7 -> V_14 == V_94 &&
V_91 -> V_236 ) )
F_9 ( F_64 ( V_278 ) , V_88 ) ;
F_63 ( V_91 , V_279 , V_280 ) ;
F_63 ( V_91 , V_281 , V_282 ) ;
F_63 ( V_91 , V_283 , V_284 ) ;
F_63 ( V_91 , V_285 , V_286 ) ;
F_63 ( V_91 , V_287 , V_288 ) ;
F_63 ( V_91 , V_289 , V_290 ) ;
}
if ( V_103 && ( V_97 || V_98 ) ) {
F_63 ( V_91 , V_291 , V_144 ) ;
F_63 ( V_91 , V_292 , V_293 ) ;
}
if ( V_100 ) {
F_63 ( V_91 , V_294 , V_143 ) ;
F_63 ( V_91 , V_295 , V_296 ) ;
F_63 ( V_91 , V_297 , V_298 ) ;
}
F_66 ( V_7 -> V_88 , V_88 , V_7 -> V_88 ,
V_89 ) ;
}
int F_67 ( struct V_6 * V_7 , int type , int V_299 ,
int V_300 , struct V_301 * V_302 )
{
int V_87 = 0 ;
int V_52 ;
int V_303 = 0 ;
int V_304 = V_86 ;
const char * V_305 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_33 ) )
return - V_44 ;
if ( F_25 ( ! V_7 -> V_25 ) )
return - V_44 ;
F_68 ( & V_7 -> V_306 ) ;
F_69 ( & V_7 -> V_307 ) ;
switch ( type ) {
case V_94 :
V_305 = L_10 ;
break;
case V_96 :
V_305 = L_11 ;
break;
case V_16 :
V_305 = L_12 ;
break;
case V_31 :
V_305 = L_13 ;
break;
case V_99 :
V_305 = L_14 ;
break;
default:
F_46 ( V_308 L_15 ,
V_309 , type ) ;
return - V_44 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_310 == NULL )
V_7 -> V_310 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_111 == NULL )
V_7 -> V_111 = V_7 -> V_25 -> V_111 ;
if ( V_7 -> V_36 == NULL )
V_7 -> V_36 = & V_7 -> V_25 -> V_36 ;
#ifdef F_70
switch ( type ) {
case V_94 :
V_303 = 0 ;
V_304 = 64 ;
break;
case V_16 :
V_303 = 64 ;
V_304 = 64 ;
break;
case V_96 :
V_303 = 224 ;
V_304 = 32 ;
break;
default:
V_303 = 128 ;
V_304 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_299 = F_12 ( V_7 , V_299 == - 1 ? 0 : V_299 , V_304 ) ;
if ( V_299 == V_304 )
V_299 = F_12 ( V_7 , 0 , V_304 ) ;
if ( V_299 == V_304 ) {
F_46 ( V_308 L_16 ) ;
F_26 ( & V_26 ) ;
return - V_311 ;
}
#ifdef F_70
V_87 = V_299 ;
#else
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ )
if ( V_6 [ V_87 ] == NULL )
break;
if ( V_87 == V_86 ) {
F_26 ( & V_26 ) ;
F_46 ( V_308 L_17 ) ;
return - V_311 ;
}
#endif
V_7 -> V_27 = V_87 + V_303 ;
V_7 -> V_19 = V_299 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_58 ( V_7 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_92 )
F_62 ( V_7 ) ;
V_7 -> V_28 = F_71 () ;
if ( V_7 -> V_28 == NULL ) {
V_52 = - V_312 ;
goto V_313;
}
V_7 -> V_28 -> V_91 = & V_314 ;
V_7 -> V_28 -> V_302 = V_302 ;
V_52 = F_72 ( V_7 -> V_28 , F_73 ( V_315 , V_7 -> V_27 ) , 1 ) ;
if ( V_52 < 0 ) {
F_46 ( V_308 L_18 , V_309 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_313;
}
V_7 -> V_23 . V_316 = & V_317 ;
V_7 -> V_23 . V_318 = F_73 ( V_315 , V_7 -> V_27 ) ;
V_7 -> V_23 . V_319 = V_7 -> V_310 ;
F_74 ( & V_7 -> V_23 , L_19 , V_305 , V_7 -> V_19 ) ;
V_52 = F_75 ( & V_7 -> V_23 ) ;
if ( V_52 < 0 ) {
F_46 ( V_308 L_20 , V_309 ) ;
goto V_313;
}
V_7 -> V_23 . V_33 = F_23 ;
if ( V_299 != - 1 && V_299 != V_7 -> V_19 && V_300 )
F_46 ( V_320 L_21 , V_309 ,
V_305 , V_299 , F_47 ( V_7 ) ) ;
if ( V_7 -> V_25 )
F_76 ( V_7 -> V_25 ) ;
#if F_28 ( V_29 )
if ( V_7 -> V_25 && V_7 -> V_25 -> V_30 &&
V_7 -> V_14 != V_31 ) {
V_7 -> V_32 . type = V_321 ;
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_322 . V_323 . V_324 = V_315 ;
V_7 -> V_32 . V_322 . V_323 . V_27 = V_7 -> V_27 ;
V_52 = F_77 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_52 < 0 )
F_46 ( V_320
L_22 ,
V_309 ) ;
}
#endif
F_9 ( V_325 , & V_7 -> V_77 ) ;
return 0 ;
V_313:
F_24 ( & V_26 ) ;
if ( V_7 -> V_28 )
F_27 ( V_7 -> V_28 ) ;
V_6 [ V_7 -> V_27 ] = NULL ;
F_10 ( V_7 ) ;
F_26 ( & V_26 ) ;
V_7 -> V_27 = - 1 ;
return V_52 ;
}
void F_78 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_45 ( V_7 ) )
return;
F_24 ( & V_26 ) ;
F_11 ( V_325 , & V_7 -> V_77 ) ;
F_26 ( & V_26 ) ;
F_79 ( & V_7 -> V_23 ) ;
}
static int T_6 F_80 ( void )
{
T_7 V_23 = F_73 ( V_315 , 0 ) ;
int V_52 ;
F_46 ( V_326 L_23 ) ;
V_52 = F_81 ( V_23 , V_86 , V_327 ) ;
if ( V_52 < 0 ) {
F_46 ( V_320 L_24 ,
V_315 ) ;
return V_52 ;
}
V_52 = F_82 ( & V_317 ) ;
if ( V_52 < 0 ) {
F_83 ( V_23 , V_86 ) ;
F_46 ( V_320 L_25 ) ;
return - V_328 ;
}
return 0 ;
}
static void T_8 F_84 ( void )
{
T_7 V_23 = F_73 ( V_315 , 0 ) ;
F_85 ( & V_317 ) ;
F_83 ( V_23 , V_86 ) ;
}
