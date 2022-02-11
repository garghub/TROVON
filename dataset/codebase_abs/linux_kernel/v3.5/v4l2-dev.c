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
return sprintf ( V_5 , L_2 , ( int ) sizeof( V_7 -> V_9 ) , V_7 -> V_9 ) ;
}
static inline unsigned long * F_4 ( int V_10 )
{
int V_11 = ( V_10 > V_12 ) ? V_13 - 1 : V_10 ;
return V_14 [ V_11 ] ;
}
static inline unsigned long * F_4 ( int V_10 )
{
return V_14 [ V_10 ] ;
}
static inline void F_5 ( struct V_6 * V_7 )
{
F_6 ( V_7 -> V_15 , F_4 ( V_7 -> V_10 ) ) ;
}
static inline void F_7 ( struct V_6 * V_7 )
{
F_8 ( V_7 -> V_15 , F_4 ( V_7 -> V_10 ) ) ;
}
static inline int F_9 ( struct V_6 * V_7 , int V_16 , int V_17 )
{
return F_10 ( F_4 ( V_7 -> V_10 ) , V_17 , V_16 ) ;
}
struct V_6 * F_11 ( void )
{
return F_12 ( sizeof( struct V_6 ) , V_18 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_7 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
}
static inline void F_16 ( struct V_6 * V_7 )
{
F_17 ( & V_7 -> V_19 ) ;
}
static inline void F_18 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_19 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
F_21 ( & V_22 ) ;
if ( F_22 ( V_6 [ V_7 -> V_23 ] != V_7 ) ) {
F_23 ( & V_22 ) ;
return;
}
V_6 [ V_7 -> V_23 ] = NULL ;
F_24 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
F_7 ( V_7 ) ;
F_23 ( & V_22 ) ;
#if F_25 ( V_25 )
if ( V_21 && V_21 -> V_26 &&
V_7 -> V_10 != V_27 )
F_26 ( & V_7 -> V_28 ) ;
#endif
if ( V_21 && V_21 -> V_29 == NULL )
V_21 = NULL ;
V_7 -> V_29 ( V_7 ) ;
if ( V_21 )
F_27 ( V_21 ) ;
}
struct V_6 * F_28 ( struct V_30 * V_30 )
{
return V_6 [ F_29 ( V_30 -> V_31 . V_32 -> V_33 ) ] ;
}
static inline bool F_30 ( enum V_34 V_35 )
{
return V_35 == V_36 ||
V_35 == V_37 ||
V_35 == V_38 ;
}
void F_31 ( struct V_39 * V_40 )
{
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
}
int F_32 ( struct V_39 * V_40 , enum V_34 * V_41 ,
enum V_34 V_42 )
{
if ( ! F_30 ( V_42 ) )
return - V_43 ;
if ( * V_41 == V_42 )
return 0 ;
F_33 ( & V_40 -> V_44 [ V_42 ] ) ;
if ( F_30 ( * V_41 ) )
F_34 ( & V_40 -> V_44 [ * V_41 ] ) ;
* V_41 = V_42 ;
return 0 ;
}
void F_35 ( struct V_39 * V_40 , enum V_34 * V_41 )
{
F_32 ( V_40 , V_41 , V_45 ) ;
}
void F_36 ( struct V_39 * V_40 , enum V_34 V_41 )
{
if ( F_30 ( V_41 ) )
F_34 ( & V_40 -> V_44 [ V_41 ] ) ;
}
enum V_34 F_37 ( struct V_39 * V_40 )
{
if ( F_38 ( & V_40 -> V_44 [ V_38 ] ) > 0 )
return V_38 ;
if ( F_38 ( & V_40 -> V_44 [ V_37 ] ) > 0 )
return V_37 ;
if ( F_38 ( & V_40 -> V_44 [ V_36 ] ) > 0 )
return V_36 ;
return V_46 ;
}
int F_39 ( struct V_39 * V_40 , enum V_34 V_41 )
{
return ( V_41 < F_37 ( V_40 ) ) ? - V_47 : 0 ;
}
static T_1 F_40 ( struct V_30 * V_48 , char T_2 * V_5 ,
T_3 V_49 , T_4 * V_50 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( ! V_7 -> V_53 -> V_54 )
return - V_43 ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) &&
F_42 ( V_7 -> V_57 ) )
return - V_58 ;
if ( F_43 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_54 ( V_48 , V_5 , V_49 , V_50 ) ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_23 ( V_7 -> V_57 ) ;
return V_51 ;
}
static T_1 F_44 ( struct V_30 * V_48 , const char T_2 * V_5 ,
T_3 V_49 , T_4 * V_50 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( ! V_7 -> V_53 -> V_59 )
return - V_43 ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) &&
F_42 ( V_7 -> V_57 ) )
return - V_58 ;
if ( F_43 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_59 ( V_48 , V_5 , V_49 , V_50 ) ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_23 ( V_7 -> V_57 ) ;
return V_51 ;
}
static unsigned int F_45 ( struct V_30 * V_48 , struct V_60 * V_61 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = V_62 | V_63 ;
if ( ! V_7 -> V_53 -> V_61 )
return V_64 ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_21 ( V_7 -> V_57 ) ;
if ( F_43 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_61 ( V_48 , V_61 ) ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_23 ( V_7 -> V_57 ) ;
return V_51 ;
}
static long F_46 ( struct V_30 * V_48 , unsigned int V_65 , unsigned long V_66 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( V_7 -> V_53 -> V_67 ) {
bool V_68 = false ;
if ( V_7 -> V_57 ) {
V_68 = ! F_47 ( V_65 ) ||
! F_41 ( F_48 ( V_65 ) , V_7 -> V_69 ) ;
if ( V_68 && F_42 ( V_7 -> V_57 ) )
return - V_58 ;
}
if ( F_43 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_67 ( V_48 , V_65 , V_66 ) ;
if ( V_68 )
F_23 ( V_7 -> V_57 ) ;
} else if ( V_7 -> V_53 -> V_70 ) {
static F_49 ( V_71 ) ;
struct V_72 * V_73 = V_7 -> V_21 ?
& V_7 -> V_21 -> V_74 : & V_71 ;
if ( V_65 != V_75 && F_42 ( V_73 ) )
return - V_58 ;
if ( F_43 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_70 ( V_48 , V_65 , V_66 ) ;
if ( V_65 != V_75 )
F_23 ( V_73 ) ;
} else
V_51 = - V_76 ;
return V_51 ;
}
static unsigned long F_50 ( struct V_30 * V_48 ,
unsigned long V_77 , unsigned long V_78 , unsigned long V_79 ,
unsigned long V_56 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
if ( ! V_7 -> V_53 -> V_80 )
return - V_81 ;
if ( ! F_43 ( V_7 ) )
return - V_52 ;
return V_7 -> V_53 -> V_80 ( V_48 , V_77 , V_78 , V_79 , V_56 ) ;
}
static int F_51 ( struct V_30 * V_48 , struct V_82 * V_83 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( ! V_7 -> V_53 -> V_84 )
return V_51 ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) &&
F_42 ( V_7 -> V_57 ) )
return - V_58 ;
if ( F_43 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_84 ( V_48 , V_83 ) ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_23 ( V_7 -> V_57 ) ;
return V_51 ;
}
static int F_52 ( struct V_85 * V_85 , struct V_30 * V_48 )
{
struct V_6 * V_7 ;
int V_51 = 0 ;
F_21 ( & V_22 ) ;
V_7 = F_28 ( V_48 ) ;
if ( V_7 == NULL || ! F_43 ( V_7 ) ) {
F_23 ( & V_22 ) ;
return - V_52 ;
}
F_16 ( V_7 ) ;
F_23 ( & V_22 ) ;
if ( V_7 -> V_53 -> V_86 ) {
if ( F_41 ( V_55 , & V_7 -> V_56 ) &&
F_42 ( V_7 -> V_57 ) ) {
V_51 = - V_58 ;
goto V_87;
}
if ( F_43 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_86 ( V_48 ) ;
else
V_51 = - V_52 ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_23 ( V_7 -> V_57 ) ;
}
V_87:
if ( V_51 )
F_18 ( V_7 ) ;
return V_51 ;
}
static int F_53 ( struct V_85 * V_85 , struct V_30 * V_48 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = 0 ;
if ( V_7 -> V_53 -> V_29 ) {
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_21 ( V_7 -> V_57 ) ;
V_7 -> V_53 -> V_29 ( V_48 ) ;
if ( F_41 ( V_55 , & V_7 -> V_56 ) )
F_23 ( V_7 -> V_57 ) ;
}
F_18 ( V_7 ) ;
return V_51 ;
}
static int F_54 ( struct V_6 * V_7 )
{
static F_55 ( V_88 , V_89 ) ;
int V_90 ;
if ( V_7 -> V_91 == NULL )
return 0 ;
F_56 ( V_88 , V_89 ) ;
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ ) {
if ( V_6 [ V_90 ] != NULL &&
V_6 [ V_90 ] -> V_91 == V_7 -> V_91 ) {
F_6 ( V_6 [ V_90 ] -> V_8 , V_88 ) ;
}
}
return F_57 ( V_88 , V_89 ) ;
}
static void F_58 ( struct V_6 * V_7 )
{
F_55 ( V_92 , V_93 ) ;
const struct V_94 * V_95 = V_7 -> V_96 ;
F_56 ( V_92 , V_93 ) ;
F_59 ( V_95 , V_97 , V_98 ) ;
if ( V_95 -> V_99 ||
F_41 ( V_100 , & V_7 -> V_56 ) )
F_6 ( F_48 ( V_101 ) , V_92 ) ;
if ( V_95 -> V_102 ||
F_41 ( V_100 , & V_7 -> V_56 ) )
F_6 ( F_48 ( V_103 ) , V_92 ) ;
if ( V_95 -> V_104 ||
V_95 -> V_105 ||
V_95 -> V_106 ||
V_95 -> V_107 ||
V_95 -> V_108 ||
V_95 -> V_109 )
F_6 ( F_48 ( V_110 ) , V_92 ) ;
if ( V_95 -> V_111 ||
V_95 -> V_112 ||
V_95 -> V_113 ||
V_95 -> V_114 ||
V_95 -> V_115 ||
V_95 -> V_116 ||
V_95 -> V_117 ||
V_95 -> V_118 ||
V_95 -> V_119 ||
V_95 -> V_120 ||
V_95 -> V_121 )
F_6 ( F_48 ( V_122 ) , V_92 ) ;
if ( V_95 -> V_123 ||
V_95 -> V_124 ||
V_95 -> V_125 ||
V_95 -> V_126 ||
V_95 -> V_127 ||
V_95 -> V_128 ||
V_95 -> V_129 ||
V_95 -> V_130 ||
V_95 -> V_131 ||
V_95 -> V_132 ||
V_95 -> V_133 )
F_6 ( F_48 ( V_134 ) , V_92 ) ;
if ( V_95 -> V_135 ||
V_95 -> V_136 ||
V_95 -> V_137 ||
V_95 -> V_138 ||
V_95 -> V_139 ||
V_95 -> V_140 ||
V_95 -> V_141 ||
V_95 -> V_142 ||
V_95 -> V_143 ||
V_95 -> V_144 ||
V_95 -> V_145 )
F_6 ( F_48 ( V_146 ) , V_92 ) ;
F_59 ( V_95 , V_147 , V_148 ) ;
F_59 ( V_95 , V_149 , V_150 ) ;
F_59 ( V_95 , V_151 , V_152 ) ;
F_59 ( V_95 , V_75 , V_153 ) ;
F_59 ( V_95 , V_154 , V_155 ) ;
F_59 ( V_95 , V_156 , V_157 ) ;
F_59 ( V_95 , V_158 , V_159 ) ;
F_59 ( V_95 , V_160 , V_161 ) ;
F_59 ( V_95 , V_162 , V_163 ) ;
if ( V_7 -> V_164 )
F_6 ( F_48 ( V_165 ) , V_92 ) ;
if ( V_95 -> V_166 || V_7 -> V_167 )
F_6 ( F_48 ( V_168 ) , V_92 ) ;
F_59 ( V_95 , V_169 , V_170 ) ;
F_59 ( V_95 , V_171 , V_172 ) ;
F_59 ( V_95 , V_173 , V_174 ) ;
F_59 ( V_95 , V_175 , V_176 ) ;
F_59 ( V_95 , V_177 , V_178 ) ;
F_59 ( V_95 , V_179 , V_180 ) ;
F_59 ( V_95 , V_181 , V_182 ) ;
F_59 ( V_95 , V_183 , V_184 ) ;
if ( V_7 -> V_185 || V_95 -> V_186 )
F_6 ( F_48 ( V_187 ) , V_92 ) ;
if ( V_7 -> V_185 || V_95 -> V_188 || V_95 -> V_189 )
F_6 ( F_48 ( V_190 ) , V_92 ) ;
if ( V_7 -> V_185 || V_95 -> V_191 || V_95 -> V_192 )
F_6 ( F_48 ( V_193 ) , V_92 ) ;
if ( V_7 -> V_185 || V_95 -> V_189 )
F_6 ( F_48 ( V_194 ) , V_92 ) ;
if ( V_7 -> V_185 || V_95 -> V_192 )
F_6 ( F_48 ( V_195 ) , V_92 ) ;
if ( V_7 -> V_185 || V_95 -> V_196 )
F_6 ( F_48 ( V_197 ) , V_92 ) ;
if ( V_7 -> V_185 || V_95 -> V_198 )
F_6 ( F_48 ( V_199 ) , V_92 ) ;
F_59 ( V_95 , V_200 , V_201 ) ;
F_59 ( V_95 , V_202 , V_203 ) ;
F_59 ( V_95 , V_204 , V_205 ) ;
F_59 ( V_95 , V_206 , V_207 ) ;
F_59 ( V_95 , V_208 , V_209 ) ;
F_59 ( V_95 , V_210 , V_211 ) ;
F_59 ( V_95 , V_212 , V_213 ) ;
F_59 ( V_95 , V_214 , V_215 ) ;
if ( V_95 -> V_216 || V_95 -> V_217 )
F_6 ( F_48 ( V_218 ) , V_92 ) ;
if ( V_95 -> V_219 || V_95 -> V_220 )
F_6 ( F_48 ( V_221 ) , V_92 ) ;
F_59 ( V_95 , V_222 , V_217 ) ;
F_59 ( V_95 , V_223 , V_220 ) ;
if ( V_95 -> V_224 || V_95 -> V_217 )
F_6 ( F_48 ( V_225 ) , V_92 ) ;
F_59 ( V_95 , V_226 , V_227 ) ;
F_59 ( V_95 , V_228 , V_229 ) ;
F_59 ( V_95 , V_230 , V_231 ) ;
F_59 ( V_95 , V_232 , V_233 ) ;
F_59 ( V_95 , V_234 , V_235 ) ;
F_59 ( V_95 , V_236 , V_237 ) ;
F_59 ( V_95 , V_238 , V_239 ) ;
if ( V_95 -> V_240 || V_7 -> V_10 == V_241 )
F_6 ( F_48 ( V_242 ) , V_92 ) ;
F_59 ( V_95 , V_243 , V_244 ) ;
F_59 ( V_95 , V_245 , V_246 ) ;
F_59 ( V_95 , V_247 , V_248 ) ;
F_59 ( V_95 , V_249 , V_250 ) ;
F_59 ( V_95 , V_251 , V_252 ) ;
F_59 ( V_95 , V_253 , V_254 ) ;
F_59 ( V_95 , V_255 , V_256 ) ;
#ifdef F_60
F_59 ( V_95 , V_257 , V_258 ) ;
F_59 ( V_95 , V_259 , V_260 ) ;
#endif
F_59 ( V_95 , V_261 , V_262 ) ;
F_59 ( V_95 , V_263 , V_264 ) ;
F_59 ( V_95 , V_265 , V_266 ) ;
F_59 ( V_95 , V_267 , V_268 ) ;
F_59 ( V_95 , V_269 , V_270 ) ;
F_59 ( V_95 , V_271 , V_272 ) ;
F_59 ( V_95 , V_273 , V_274 ) ;
F_59 ( V_95 , V_275 , V_276 ) ;
F_59 ( V_95 , V_277 , V_278 ) ;
F_59 ( V_95 , V_279 , V_280 ) ;
F_59 ( V_95 , V_281 , V_282 ) ;
F_59 ( V_95 , V_283 , V_284 ) ;
F_59 ( V_95 , V_285 , V_286 ) ;
F_59 ( V_95 , V_287 , V_288 ) ;
F_59 ( V_95 , V_289 , V_288 ) ;
F_59 ( V_95 , V_290 , V_291 ) ;
F_59 ( V_95 , V_292 , V_293 ) ;
F_59 ( V_95 , V_294 , V_295 ) ;
F_61 ( V_7 -> V_92 , V_92 , V_7 -> V_92 ,
V_93 ) ;
}
int F_62 ( struct V_6 * V_7 , int type , int V_296 ,
int V_297 , struct V_298 * V_299 )
{
int V_90 = 0 ;
int V_51 ;
int V_300 = 0 ;
int V_301 = V_89 ;
const char * V_302 ;
V_7 -> V_23 = - 1 ;
if ( F_22 ( ! V_7 -> V_29 ) )
return - V_43 ;
F_63 ( & V_7 -> V_303 ) ;
F_64 ( & V_7 -> V_304 ) ;
switch ( type ) {
case V_241 :
V_302 = L_3 ;
break;
case V_305 :
V_302 = L_4 ;
break;
case V_12 :
V_302 = L_5 ;
break;
case V_27 :
V_302 = L_6 ;
break;
default:
F_65 ( V_306 L_7 ,
V_307 , type ) ;
return - V_43 ;
}
V_7 -> V_10 = type ;
V_7 -> V_24 = NULL ;
if ( V_7 -> V_21 ) {
if ( V_7 -> V_21 -> V_19 )
V_7 -> V_91 = V_7 -> V_21 -> V_19 ;
if ( V_7 -> V_185 == NULL )
V_7 -> V_185 = V_7 -> V_21 -> V_185 ;
if ( V_7 -> V_35 == NULL )
V_7 -> V_35 = & V_7 -> V_21 -> V_35 ;
}
#ifdef F_66
switch ( type ) {
case V_241 :
V_300 = 0 ;
V_301 = 64 ;
break;
case V_12 :
V_300 = 64 ;
V_301 = 64 ;
break;
case V_305 :
V_300 = 224 ;
V_301 = 32 ;
break;
default:
V_300 = 128 ;
V_301 = 64 ;
break;
}
#endif
F_21 ( & V_22 ) ;
V_296 = F_9 ( V_7 , V_296 == - 1 ? 0 : V_296 , V_301 ) ;
if ( V_296 == V_301 )
V_296 = F_9 ( V_7 , 0 , V_301 ) ;
if ( V_296 == V_301 ) {
F_65 ( V_306 L_8 ) ;
F_23 ( & V_22 ) ;
return - V_308 ;
}
#ifdef F_66
V_90 = V_296 ;
#else
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ )
if ( V_6 [ V_90 ] == NULL )
break;
if ( V_90 == V_89 ) {
F_23 ( & V_22 ) ;
F_65 ( V_306 L_9 ) ;
return - V_308 ;
}
#endif
V_7 -> V_23 = V_90 + V_300 ;
V_7 -> V_15 = V_296 ;
F_5 ( V_7 ) ;
F_22 ( V_6 [ V_7 -> V_23 ] != NULL ) ;
V_7 -> V_8 = F_54 ( V_7 ) ;
F_23 ( & V_22 ) ;
if ( V_7 -> V_57 == NULL )
F_22 ( F_67 ( V_55 , & V_7 -> V_56 ) ) ;
if ( V_7 -> V_96 )
F_58 ( V_7 ) ;
V_7 -> V_24 = F_68 () ;
if ( V_7 -> V_24 == NULL ) {
V_51 = - V_309 ;
goto V_310;
}
V_7 -> V_24 -> V_95 = & V_311 ;
V_7 -> V_24 -> V_299 = V_299 ;
V_51 = F_69 ( V_7 -> V_24 , F_70 ( V_312 , V_7 -> V_23 ) , 1 ) ;
if ( V_51 < 0 ) {
F_65 ( V_306 L_10 , V_307 ) ;
F_14 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
goto V_310;
}
V_7 -> V_19 . V_313 = & V_314 ;
V_7 -> V_19 . V_315 = F_70 ( V_312 , V_7 -> V_23 ) ;
if ( V_7 -> V_91 )
V_7 -> V_19 . V_91 = V_7 -> V_91 ;
F_71 ( & V_7 -> V_19 , L_11 , V_302 , V_7 -> V_15 ) ;
V_51 = F_72 ( & V_7 -> V_19 ) ;
if ( V_51 < 0 ) {
F_65 ( V_306 L_12 , V_307 ) ;
goto V_310;
}
V_7 -> V_19 . V_29 = F_20 ;
if ( V_296 != - 1 && V_296 != V_7 -> V_15 && V_297 )
F_65 ( V_316 L_13 , V_307 ,
V_302 , V_296 , F_73 ( V_7 ) ) ;
if ( V_7 -> V_21 )
F_74 ( V_7 -> V_21 ) ;
#if F_25 ( V_25 )
if ( V_7 -> V_21 && V_7 -> V_21 -> V_26 &&
V_7 -> V_10 != V_27 ) {
V_7 -> V_28 . type = V_317 ;
V_7 -> V_28 . V_9 = V_7 -> V_9 ;
V_7 -> V_28 . V_318 . V_319 . V_320 = V_312 ;
V_7 -> V_28 . V_318 . V_319 . V_23 = V_7 -> V_23 ;
V_51 = F_75 ( V_7 -> V_21 -> V_26 ,
& V_7 -> V_28 ) ;
if ( V_51 < 0 )
F_65 ( V_316
L_14 ,
V_307 ) ;
}
#endif
F_6 ( V_321 , & V_7 -> V_56 ) ;
F_21 ( & V_22 ) ;
V_6 [ V_7 -> V_23 ] = V_7 ;
F_23 ( & V_22 ) ;
return 0 ;
V_310:
F_21 ( & V_22 ) ;
if ( V_7 -> V_24 )
F_24 ( V_7 -> V_24 ) ;
F_7 ( V_7 ) ;
F_23 ( & V_22 ) ;
V_7 -> V_23 = - 1 ;
return V_51 ;
}
void F_76 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_43 ( V_7 ) )
return;
F_21 ( & V_22 ) ;
F_8 ( V_321 , & V_7 -> V_56 ) ;
F_23 ( & V_22 ) ;
F_77 ( & V_7 -> V_19 ) ;
}
static int T_5 F_78 ( void )
{
T_6 V_19 = F_70 ( V_312 , 0 ) ;
int V_51 ;
F_65 ( V_322 L_15 ) ;
V_51 = F_79 ( V_19 , V_89 , V_323 ) ;
if ( V_51 < 0 ) {
F_65 ( V_316 L_16 ,
V_312 ) ;
return V_51 ;
}
V_51 = F_80 ( & V_314 ) ;
if ( V_51 < 0 ) {
F_81 ( V_19 , V_89 ) ;
F_65 ( V_316 L_17 ) ;
return - V_324 ;
}
return 0 ;
}
static void T_7 F_82 ( void )
{
T_6 V_19 = F_70 ( V_312 , 0 ) ;
F_83 ( & V_314 ) ;
F_81 ( V_19 , V_89 ) ;
}
