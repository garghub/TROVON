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
if ( F_44 ( V_59 , & V_7 -> V_60 ) &&
F_45 ( V_7 -> V_61 ) )
return - V_62 ;
if ( F_46 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_58 ( V_52 , V_5 , V_53 , V_54 ) ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_26 ( V_7 -> V_61 ) ;
if ( V_7 -> V_9 )
F_47 ( V_63 L_3 ,
F_48 ( V_7 ) , V_53 , V_55 ) ;
return V_55 ;
}
static T_1 F_49 ( struct V_34 * V_52 , const char T_4 * V_5 ,
T_2 V_53 , T_5 * V_54 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = - V_56 ;
if ( ! V_7 -> V_57 -> V_64 )
return - V_47 ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) &&
F_45 ( V_7 -> V_61 ) )
return - V_62 ;
if ( F_46 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_64 ( V_52 , V_5 , V_53 , V_54 ) ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_26 ( V_7 -> V_61 ) ;
if ( V_7 -> V_9 )
F_47 ( V_63 L_4 ,
F_48 ( V_7 ) , V_53 , V_55 ) ;
return V_55 ;
}
static unsigned int F_50 ( struct V_34 * V_52 , struct V_65 * V_66 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = V_67 | V_68 ;
if ( ! V_7 -> V_57 -> V_66 )
return V_69 ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_24 ( V_7 -> V_61 ) ;
if ( F_46 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_66 ( V_52 , V_66 ) ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_26 ( V_7 -> V_61 ) ;
if ( V_7 -> V_9 )
F_47 ( V_63 L_5 ,
F_48 ( V_7 ) , V_55 ) ;
return V_55 ;
}
static long F_51 ( struct V_34 * V_52 , unsigned int V_70 , unsigned long V_71 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = - V_56 ;
if ( V_7 -> V_57 -> V_72 ) {
struct V_73 * V_61 = F_52 ( V_7 , V_70 ) ;
if ( V_61 && F_45 ( V_61 ) )
return - V_62 ;
if ( F_46 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_72 ( V_52 , V_70 , V_71 ) ;
if ( V_61 )
F_26 ( V_61 ) ;
} else if ( V_7 -> V_57 -> V_74 ) {
static F_53 ( V_75 ) ;
struct V_73 * V_76 = V_7 -> V_25 ?
& V_7 -> V_25 -> V_77 : & V_75 ;
if ( V_70 != V_78 && F_45 ( V_76 ) )
return - V_62 ;
if ( F_46 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_74 ( V_52 , V_70 , V_71 ) ;
if ( V_70 != V_78 )
F_26 ( V_76 ) ;
} else
V_55 = - V_79 ;
return V_55 ;
}
static unsigned long F_54 ( struct V_34 * V_52 ,
unsigned long V_80 , unsigned long V_10 , unsigned long V_81 ,
unsigned long V_60 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 ;
if ( ! V_7 -> V_57 -> V_82 )
return - V_83 ;
if ( ! F_46 ( V_7 ) )
return - V_56 ;
V_55 = V_7 -> V_57 -> V_82 ( V_52 , V_80 , V_10 , V_81 , V_60 ) ;
if ( V_7 -> V_9 )
F_47 ( V_63 L_6 ,
F_48 ( V_7 ) , V_55 ) ;
return V_55 ;
}
static int F_55 ( struct V_34 * V_52 , struct V_84 * V_85 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = - V_56 ;
if ( ! V_7 -> V_57 -> V_86 )
return V_55 ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) &&
F_45 ( V_7 -> V_61 ) )
return - V_62 ;
if ( F_46 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_86 ( V_52 , V_85 ) ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_26 ( V_7 -> V_61 ) ;
if ( V_7 -> V_9 )
F_47 ( V_63 L_7 ,
F_48 ( V_7 ) , V_55 ) ;
return V_55 ;
}
static int F_56 ( struct V_87 * V_87 , struct V_34 * V_52 )
{
struct V_6 * V_7 ;
int V_55 = 0 ;
F_24 ( & V_26 ) ;
V_7 = F_31 ( V_52 ) ;
if ( V_7 == NULL || ! F_46 ( V_7 ) ) {
F_26 ( & V_26 ) ;
return - V_56 ;
}
F_19 ( V_7 ) ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_57 -> V_88 ) {
if ( F_44 ( V_59 , & V_7 -> V_60 ) &&
F_45 ( V_7 -> V_61 ) ) {
V_55 = - V_62 ;
goto V_89;
}
if ( F_46 ( V_7 ) )
V_55 = V_7 -> V_57 -> V_88 ( V_52 ) ;
else
V_55 = - V_56 ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_26 ( V_7 -> V_61 ) ;
}
V_89:
if ( V_7 -> V_9 )
F_47 ( V_63 L_8 ,
F_48 ( V_7 ) , V_55 ) ;
if ( V_55 )
F_21 ( V_7 ) ;
return V_55 ;
}
static int F_57 ( struct V_87 * V_87 , struct V_34 * V_52 )
{
struct V_6 * V_7 = F_31 ( V_52 ) ;
int V_55 = 0 ;
if ( V_7 -> V_57 -> V_33 ) {
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_24 ( V_7 -> V_61 ) ;
V_7 -> V_57 -> V_33 ( V_52 ) ;
if ( F_44 ( V_59 , & V_7 -> V_60 ) )
F_26 ( V_7 -> V_61 ) ;
}
if ( V_7 -> V_9 )
F_47 ( V_63 L_9 ,
F_48 ( V_7 ) ) ;
F_21 ( V_7 ) ;
return V_55 ;
}
static int F_58 ( struct V_6 * V_7 )
{
static F_59 ( V_90 , V_91 ) ;
int V_92 ;
if ( V_7 -> V_93 == NULL )
return 0 ;
F_60 ( V_90 , V_91 ) ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
if ( V_6 [ V_92 ] != NULL &&
V_6 [ V_92 ] -> V_93 == V_7 -> V_93 ) {
F_9 ( V_6 [ V_92 ] -> V_8 , V_90 ) ;
}
}
return F_61 ( V_90 , V_91 ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
F_59 ( V_94 , V_95 ) ;
const struct V_96 * V_97 = V_7 -> V_98 ;
F_60 ( V_94 , V_95 ) ;
F_63 ( V_97 , V_99 , V_100 ) ;
if ( V_97 -> V_101 ||
F_44 ( V_102 , & V_7 -> V_60 ) )
F_9 ( F_64 ( V_103 ) , V_94 ) ;
if ( V_97 -> V_104 ||
F_44 ( V_102 , & V_7 -> V_60 ) )
F_9 ( F_64 ( V_105 ) , V_94 ) ;
if ( V_97 -> V_106 ||
V_97 -> V_107 ||
V_97 -> V_108 ||
V_97 -> V_109 ||
V_97 -> V_110 ||
V_97 -> V_111 )
F_9 ( F_64 ( V_112 ) , V_94 ) ;
if ( V_97 -> V_113 ||
V_97 -> V_114 ||
V_97 -> V_115 ||
V_97 -> V_116 ||
V_97 -> V_117 ||
V_97 -> V_118 ||
V_97 -> V_119 ||
V_97 -> V_120 ||
V_97 -> V_121 ||
V_97 -> V_122 ||
V_97 -> V_123 )
F_9 ( F_64 ( V_124 ) , V_94 ) ;
if ( V_97 -> V_125 ||
V_97 -> V_126 ||
V_97 -> V_127 ||
V_97 -> V_128 ||
V_97 -> V_129 ||
V_97 -> V_130 ||
V_97 -> V_131 ||
V_97 -> V_132 ||
V_97 -> V_133 ||
V_97 -> V_134 ||
V_97 -> V_135 )
F_9 ( F_64 ( V_136 ) , V_94 ) ;
if ( V_97 -> V_137 ||
V_97 -> V_138 ||
V_97 -> V_139 ||
V_97 -> V_140 ||
V_97 -> V_141 ||
V_97 -> V_142 ||
V_97 -> V_143 ||
V_97 -> V_144 ||
V_97 -> V_145 ||
V_97 -> V_146 ||
V_97 -> V_147 )
F_9 ( F_64 ( V_148 ) , V_94 ) ;
F_63 ( V_97 , V_149 , V_150 ) ;
F_63 ( V_97 , V_151 , V_152 ) ;
F_63 ( V_97 , V_153 , V_154 ) ;
F_63 ( V_97 , V_78 , V_155 ) ;
F_63 ( V_97 , V_156 , V_157 ) ;
F_63 ( V_97 , V_158 , V_159 ) ;
F_63 ( V_97 , V_160 , V_161 ) ;
F_63 ( V_97 , V_162 , V_163 ) ;
F_63 ( V_97 , V_164 , V_165 ) ;
if ( V_7 -> V_166 )
F_9 ( F_64 ( V_167 ) , V_94 ) ;
if ( V_97 -> V_168 || V_7 -> V_169 )
F_9 ( F_64 ( V_170 ) , V_94 ) ;
F_63 ( V_97 , V_171 , V_172 ) ;
F_63 ( V_97 , V_173 , V_174 ) ;
F_63 ( V_97 , V_175 , V_176 ) ;
F_63 ( V_97 , V_177 , V_178 ) ;
F_63 ( V_97 , V_179 , V_180 ) ;
F_63 ( V_97 , V_181 , V_182 ) ;
F_63 ( V_97 , V_183 , V_184 ) ;
F_63 ( V_97 , V_185 , V_186 ) ;
if ( V_7 -> V_187 || V_97 -> V_188 )
F_9 ( F_64 ( V_189 ) , V_94 ) ;
if ( V_7 -> V_187 || V_97 -> V_190 || V_97 -> V_191 )
F_9 ( F_64 ( V_192 ) , V_94 ) ;
if ( V_7 -> V_187 || V_97 -> V_193 || V_97 -> V_194 )
F_9 ( F_64 ( V_195 ) , V_94 ) ;
if ( V_7 -> V_187 || V_97 -> V_191 )
F_9 ( F_64 ( V_196 ) , V_94 ) ;
if ( V_7 -> V_187 || V_97 -> V_194 )
F_9 ( F_64 ( V_197 ) , V_94 ) ;
if ( V_7 -> V_187 || V_97 -> V_198 )
F_9 ( F_64 ( V_199 ) , V_94 ) ;
if ( V_7 -> V_187 || V_97 -> V_200 )
F_9 ( F_64 ( V_201 ) , V_94 ) ;
F_63 ( V_97 , V_202 , V_203 ) ;
F_63 ( V_97 , V_204 , V_205 ) ;
F_63 ( V_97 , V_206 , V_207 ) ;
F_63 ( V_97 , V_208 , V_209 ) ;
F_63 ( V_97 , V_210 , V_211 ) ;
F_63 ( V_97 , V_212 , V_213 ) ;
F_63 ( V_97 , V_214 , V_215 ) ;
F_63 ( V_97 , V_216 , V_217 ) ;
if ( V_97 -> V_218 || V_97 -> V_219 )
F_9 ( F_64 ( V_220 ) , V_94 ) ;
if ( V_97 -> V_221 || V_97 -> V_222 )
F_9 ( F_64 ( V_223 ) , V_94 ) ;
F_63 ( V_97 , V_224 , V_219 ) ;
F_63 ( V_97 , V_225 , V_222 ) ;
if ( V_97 -> V_226 || V_97 -> V_219 )
F_9 ( F_64 ( V_227 ) , V_94 ) ;
F_63 ( V_97 , V_228 , V_229 ) ;
F_63 ( V_97 , V_230 , V_231 ) ;
F_63 ( V_97 , V_232 , V_233 ) ;
F_63 ( V_97 , V_234 , V_235 ) ;
F_63 ( V_97 , V_236 , V_237 ) ;
F_63 ( V_97 , V_238 , V_239 ) ;
F_63 ( V_97 , V_240 , V_241 ) ;
if ( V_97 -> V_242 || ( V_7 -> V_14 == V_243 &&
( V_97 -> V_168 || V_7 -> V_166 ) ) )
F_9 ( F_64 ( V_244 ) , V_94 ) ;
F_63 ( V_97 , V_245 , V_246 ) ;
F_63 ( V_97 , V_247 , V_248 ) ;
F_63 ( V_97 , V_249 , V_250 ) ;
F_63 ( V_97 , V_251 , V_252 ) ;
F_63 ( V_97 , V_253 , V_254 ) ;
F_63 ( V_97 , V_255 , V_256 ) ;
F_63 ( V_97 , V_257 , V_258 ) ;
#ifdef F_65
F_63 ( V_97 , V_259 , V_260 ) ;
F_63 ( V_97 , V_261 , V_262 ) ;
#endif
F_63 ( V_97 , V_263 , V_264 ) ;
F_63 ( V_97 , V_265 , V_266 ) ;
F_63 ( V_97 , V_267 , V_268 ) ;
F_63 ( V_97 , V_269 , V_270 ) ;
F_63 ( V_97 , V_271 , V_272 ) ;
F_63 ( V_97 , V_273 , V_274 ) ;
F_63 ( V_97 , V_275 , V_276 ) ;
F_63 ( V_97 , V_277 , V_278 ) ;
F_63 ( V_97 , V_279 , V_280 ) ;
F_63 ( V_97 , V_281 , V_282 ) ;
F_63 ( V_97 , V_283 , V_284 ) ;
F_63 ( V_97 , V_285 , V_286 ) ;
F_63 ( V_97 , V_287 , V_288 ) ;
F_63 ( V_97 , V_289 , V_290 ) ;
F_63 ( V_97 , V_291 , V_290 ) ;
F_63 ( V_97 , V_292 , V_293 ) ;
F_63 ( V_97 , V_294 , V_295 ) ;
F_63 ( V_97 , V_296 , V_297 ) ;
if ( V_97 -> V_298 || V_97 -> V_248 || V_97 -> V_215 )
F_9 ( F_64 ( V_299 ) , V_94 ) ;
F_66 ( V_7 -> V_94 , V_94 , V_7 -> V_94 ,
V_95 ) ;
}
int F_67 ( struct V_6 * V_7 , int type , int V_300 ,
int V_301 , struct V_302 * V_303 )
{
int V_92 = 0 ;
int V_55 ;
int V_304 = 0 ;
int V_305 = V_91 ;
const char * V_306 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_33 ) )
return - V_47 ;
F_68 ( & V_7 -> V_307 ) ;
F_69 ( & V_7 -> V_308 ) ;
switch ( type ) {
case V_243 :
V_306 = L_10 ;
break;
case V_309 :
V_306 = L_11 ;
break;
case V_16 :
V_306 = L_12 ;
break;
case V_31 :
V_306 = L_13 ;
break;
default:
F_47 ( V_310 L_14 ,
V_311 , type ) ;
return - V_47 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_25 ) {
if ( V_7 -> V_25 -> V_23 )
V_7 -> V_93 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_187 == NULL )
V_7 -> V_187 = V_7 -> V_25 -> V_187 ;
if ( V_7 -> V_39 == NULL )
V_7 -> V_39 = & V_7 -> V_25 -> V_39 ;
}
#ifdef F_70
switch ( type ) {
case V_243 :
V_304 = 0 ;
V_305 = 64 ;
break;
case V_16 :
V_304 = 64 ;
V_305 = 64 ;
break;
case V_309 :
V_304 = 224 ;
V_305 = 32 ;
break;
default:
V_304 = 128 ;
V_305 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_300 = F_12 ( V_7 , V_300 == - 1 ? 0 : V_300 , V_305 ) ;
if ( V_300 == V_305 )
V_300 = F_12 ( V_7 , 0 , V_305 ) ;
if ( V_300 == V_305 ) {
F_47 ( V_310 L_15 ) ;
F_26 ( & V_26 ) ;
return - V_312 ;
}
#ifdef F_70
V_92 = V_300 ;
#else
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ )
if ( V_6 [ V_92 ] == NULL )
break;
if ( V_92 == V_91 ) {
F_26 ( & V_26 ) ;
F_47 ( V_310 L_16 ) ;
return - V_312 ;
}
#endif
V_7 -> V_27 = V_92 + V_304 ;
V_7 -> V_19 = V_300 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_58 ( V_7 ) ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_61 == NULL )
F_25 ( F_71 ( V_59 , & V_7 -> V_60 ) ) ;
if ( V_7 -> V_98 )
F_62 ( V_7 ) ;
V_7 -> V_28 = F_72 () ;
if ( V_7 -> V_28 == NULL ) {
V_55 = - V_313 ;
goto V_314;
}
V_7 -> V_28 -> V_97 = & V_315 ;
V_7 -> V_28 -> V_303 = V_303 ;
V_55 = F_73 ( V_7 -> V_28 , F_74 ( V_316 , V_7 -> V_27 ) , 1 ) ;
if ( V_55 < 0 ) {
F_47 ( V_310 L_17 , V_311 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_314;
}
V_7 -> V_23 . V_317 = & V_318 ;
V_7 -> V_23 . V_319 = F_74 ( V_316 , V_7 -> V_27 ) ;
if ( V_7 -> V_93 )
V_7 -> V_23 . V_93 = V_7 -> V_93 ;
F_75 ( & V_7 -> V_23 , L_18 , V_306 , V_7 -> V_19 ) ;
V_55 = F_76 ( & V_7 -> V_23 ) ;
if ( V_55 < 0 ) {
F_47 ( V_310 L_19 , V_311 ) ;
goto V_314;
}
V_7 -> V_23 . V_33 = F_23 ;
if ( V_300 != - 1 && V_300 != V_7 -> V_19 && V_301 )
F_47 ( V_320 L_20 , V_311 ,
V_306 , V_300 , F_48 ( V_7 ) ) ;
if ( V_7 -> V_25 )
F_77 ( V_7 -> V_25 ) ;
#if F_28 ( V_29 )
if ( V_7 -> V_25 && V_7 -> V_25 -> V_30 &&
V_7 -> V_14 != V_31 ) {
V_7 -> V_32 . type = V_321 ;
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_322 . V_323 . V_324 = V_316 ;
V_7 -> V_32 . V_322 . V_323 . V_27 = V_7 -> V_27 ;
V_55 = F_78 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_55 < 0 )
F_47 ( V_320
L_21 ,
V_311 ) ;
}
#endif
F_9 ( V_325 , & V_7 -> V_60 ) ;
F_24 ( & V_26 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
return 0 ;
V_314:
F_24 ( & V_26 ) ;
if ( V_7 -> V_28 )
F_27 ( V_7 -> V_28 ) ;
F_10 ( V_7 ) ;
F_26 ( & V_26 ) ;
V_7 -> V_27 = - 1 ;
return V_55 ;
}
void F_79 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_46 ( V_7 ) )
return;
F_24 ( & V_26 ) ;
F_11 ( V_325 , & V_7 -> V_60 ) ;
F_26 ( & V_26 ) ;
F_80 ( & V_7 -> V_23 ) ;
}
static int T_6 F_81 ( void )
{
T_7 V_23 = F_74 ( V_316 , 0 ) ;
int V_55 ;
F_47 ( V_326 L_22 ) ;
V_55 = F_82 ( V_23 , V_91 , V_327 ) ;
if ( V_55 < 0 ) {
F_47 ( V_320 L_23 ,
V_316 ) ;
return V_55 ;
}
V_55 = F_83 ( & V_318 ) ;
if ( V_55 < 0 ) {
F_84 ( V_23 , V_91 ) ;
F_47 ( V_320 L_24 ) ;
return - V_328 ;
}
return 0 ;
}
static void T_8 F_85 ( void )
{
T_7 V_23 = F_74 ( V_316 , 0 ) ;
F_86 ( & V_318 ) ;
F_84 ( V_23 , V_91 ) ;
}
