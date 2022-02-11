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
} else
V_52 = - V_72 ;
return V_52 ;
}
static unsigned long F_53 ( struct V_34 * V_49 ,
unsigned long V_73 , unsigned long V_10 , unsigned long V_74 ,
unsigned long V_75 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 ;
if ( ! V_7 -> V_54 -> V_76 )
return - V_77 ;
if ( ! F_45 ( V_7 ) )
return - V_53 ;
V_52 = V_7 -> V_54 -> V_76 ( V_49 , V_73 , V_10 , V_74 , V_75 ) ;
if ( V_7 -> V_9 & V_56 )
F_46 ( V_58 L_6 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_54 ( struct V_34 * V_49 , struct V_78 * V_79 )
{
struct V_6 * V_7 = F_31 ( V_49 ) ;
int V_52 = - V_53 ;
if ( ! V_7 -> V_54 -> V_80 )
return - V_53 ;
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_80 ( V_49 , V_79 ) ;
if ( V_7 -> V_9 & V_56 )
F_46 ( V_58 L_7 ,
F_47 ( V_7 ) , V_52 ) ;
return V_52 ;
}
static int F_55 ( struct V_81 * V_81 , struct V_34 * V_49 )
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
if ( V_7 -> V_54 -> V_82 ) {
if ( F_45 ( V_7 ) )
V_52 = V_7 -> V_54 -> V_82 ( V_49 ) ;
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
static int F_56 ( struct V_81 * V_81 , struct V_34 * V_49 )
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
static F_58 ( V_83 , V_84 ) ;
int V_85 ;
F_59 ( V_83 , V_84 ) ;
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ ) {
if ( V_6 [ V_85 ] != NULL &&
V_6 [ V_85 ] -> V_25 == V_7 -> V_25 ) {
F_9 ( V_6 [ V_85 ] -> V_8 , V_83 ) ;
}
}
return F_60 ( V_83 , V_84 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_58 ( V_86 , V_87 ) ;
const struct V_88 * V_89 = V_7 -> V_90 ;
bool V_91 = V_7 -> V_14 == V_92 ;
bool V_93 = V_7 -> V_14 == V_94 ;
bool V_95 = V_7 -> V_14 == V_16 ;
bool V_96 = V_7 -> V_14 == V_97 ;
bool V_98 = V_7 -> V_99 != V_100 ;
bool V_101 = V_7 -> V_99 != V_102 ;
F_59 ( V_86 , V_87 ) ;
F_62 ( V_89 , V_103 , V_104 ) ;
F_9 ( F_63 ( V_105 ) , V_86 ) ;
F_9 ( F_63 ( V_106 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_108 )
F_9 ( F_63 ( V_109 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_110 )
F_9 ( F_63 ( V_111 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_112 || V_89 -> V_113 )
F_9 ( F_63 ( V_114 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_115 || V_89 -> V_116 )
F_9 ( F_63 ( V_117 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_113 )
F_9 ( F_63 ( V_118 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_116 )
F_9 ( F_63 ( V_119 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_120 )
F_9 ( F_63 ( V_121 ) , V_86 ) ;
if ( V_7 -> V_107 || V_89 -> V_122 )
F_9 ( F_63 ( V_123 ) , V_86 ) ;
F_62 ( V_89 , V_124 , V_125 ) ;
F_62 ( V_89 , V_126 , V_127 ) ;
F_62 ( V_89 , V_128 , V_129 ) ;
#ifdef F_64
F_9 ( F_63 ( V_130 ) , V_86 ) ;
F_9 ( F_63 ( V_131 ) , V_86 ) ;
F_9 ( F_63 ( V_132 ) , V_86 ) ;
#endif
F_62 ( V_89 , V_133 , V_134 ) ;
F_62 ( V_89 , V_135 , V_134 ) ;
F_62 ( V_89 , V_136 , V_137 ) ;
if ( V_89 -> V_138 || V_89 -> V_139 || V_89 -> V_140 )
F_9 ( F_63 ( V_141 ) , V_86 ) ;
if ( V_91 ) {
if ( ( V_98 && ( V_89 -> V_142 ||
V_89 -> V_143 ||
V_89 -> V_144 ) ) ||
( V_101 && ( V_89 -> V_145 ||
V_89 -> V_146 ) ) )
F_9 ( F_63 ( V_147 ) , V_86 ) ;
if ( ( V_98 && ( V_89 -> V_148 ||
V_89 -> V_149 ||
V_89 -> V_150 ) ) ||
( V_101 && ( V_89 -> V_151 ||
V_89 -> V_152 ||
V_89 -> V_153 ) ) )
F_9 ( F_63 ( V_154 ) , V_86 ) ;
if ( ( V_98 && ( V_89 -> V_155 ||
V_89 -> V_156 ||
V_89 -> V_157 ) ) ||
( V_101 && ( V_89 -> V_158 ||
V_89 -> V_159 ||
V_89 -> V_160 ) ) )
F_9 ( F_63 ( V_161 ) , V_86 ) ;
if ( ( V_98 && ( V_89 -> V_162 ||
V_89 -> V_163 ||
V_89 -> V_164 ) ) ||
( V_101 && ( V_89 -> V_165 ||
V_89 -> V_166 ||
V_89 -> V_167 ) ) )
F_9 ( F_63 ( V_168 ) , V_86 ) ;
F_62 ( V_89 , V_169 , V_170 ) ;
F_62 ( V_89 , V_171 , V_172 ) ;
F_62 ( V_89 , V_173 , V_174 ) ;
F_62 ( V_89 , V_175 , V_176 ) ;
F_62 ( V_89 , V_177 , V_178 ) ;
F_62 ( V_89 , V_179 , V_180 ) ;
F_62 ( V_89 , V_181 , V_182 ) ;
F_62 ( V_89 , V_183 , V_184 ) ;
F_62 ( V_89 , V_185 , V_186 ) ;
F_62 ( V_89 , V_187 , V_188 ) ;
F_62 ( V_89 , V_189 , V_190 ) ;
F_62 ( V_89 , V_191 , V_192 ) ;
if ( V_89 -> V_193 || V_89 -> V_194 )
F_9 ( F_63 ( V_195 ) , V_86 ) ;
if ( V_89 -> V_196 || V_89 -> V_197 )
F_9 ( F_63 ( V_198 ) , V_86 ) ;
F_62 ( V_89 , V_199 , V_194 ) ;
F_62 ( V_89 , V_200 , V_197 ) ;
if ( V_89 -> V_201 || V_89 -> V_194 )
F_9 ( F_63 ( V_202 ) , V_86 ) ;
} else if ( V_93 ) {
if ( ( V_98 && ( V_89 -> V_203 ||
V_89 -> V_204 ) ) ||
( V_101 && ( V_89 -> V_205 ||
V_89 -> V_206 ) ) )
F_9 ( F_63 ( V_154 ) , V_86 ) ;
if ( ( V_98 && ( V_89 -> V_207 ||
V_89 -> V_208 ) ) ||
( V_101 && ( V_89 -> V_209 ||
V_89 -> V_210 ) ) )
F_9 ( F_63 ( V_161 ) , V_86 ) ;
if ( ( V_98 && ( V_89 -> V_211 ||
V_89 -> V_212 ) ) ||
( V_101 && ( V_89 -> V_213 ||
V_89 -> V_214 ) ) )
F_9 ( F_63 ( V_168 ) , V_86 ) ;
F_62 ( V_89 , V_215 , V_216 ) ;
} else if ( V_96 ) {
if ( V_89 -> V_217 )
F_9 ( F_63 ( V_147 ) , V_86 ) ;
if ( V_89 -> V_218 )
F_9 ( F_63 ( V_154 ) , V_86 ) ;
if ( V_89 -> V_219 )
F_9 ( F_63 ( V_161 ) , V_86 ) ;
if ( V_89 -> V_220 )
F_9 ( F_63 ( V_168 ) , V_86 ) ;
}
if ( V_91 || V_93 || V_96 ) {
F_62 ( V_89 , V_221 , V_222 ) ;
F_62 ( V_89 , V_223 , V_224 ) ;
F_62 ( V_89 , V_225 , V_226 ) ;
F_62 ( V_89 , V_227 , V_228 ) ;
F_62 ( V_89 , V_229 , V_230 ) ;
F_62 ( V_89 , V_231 , V_232 ) ;
F_62 ( V_89 , V_233 , V_234 ) ;
F_62 ( V_89 , V_235 , V_236 ) ;
F_62 ( V_89 , V_237 , V_238 ) ;
}
if ( V_91 || V_93 ) {
if ( V_89 -> V_239 )
F_9 ( F_63 ( V_240 ) , V_86 ) ;
F_62 ( V_89 , V_241 , V_239 ) ;
F_62 ( V_89 , V_242 , V_243 ) ;
if ( V_98 ) {
F_62 ( V_89 , V_244 , V_245 ) ;
F_62 ( V_89 , V_246 , V_247 ) ;
F_62 ( V_89 , V_248 , V_249 ) ;
F_62 ( V_89 , V_250 , V_251 ) ;
F_62 ( V_89 , V_252 , V_253 ) ;
F_62 ( V_89 , V_254 , V_255 ) ;
F_62 ( V_89 , V_256 , V_257 ) ;
F_62 ( V_89 , V_258 , V_259 ) ;
F_62 ( V_89 , V_260 , V_261 ) ;
}
if ( V_101 ) {
F_62 ( V_89 , V_262 , V_263 ) ;
F_62 ( V_89 , V_264 , V_265 ) ;
F_62 ( V_89 , V_266 , V_267 ) ;
F_62 ( V_89 , V_268 , V_269 ) ;
F_62 ( V_89 , V_270 , V_271 ) ;
F_62 ( V_89 , V_272 , V_273 ) ;
}
if ( V_89 -> V_274 || ( V_7 -> V_14 == V_92 &&
V_89 -> V_243 ) )
F_9 ( F_63 ( V_275 ) , V_86 ) ;
F_62 ( V_89 , V_276 , V_277 ) ;
F_62 ( V_89 , V_278 , V_279 ) ;
F_62 ( V_89 , V_280 , V_281 ) ;
F_62 ( V_89 , V_282 , V_283 ) ;
F_62 ( V_89 , V_284 , V_285 ) ;
F_62 ( V_89 , V_286 , V_287 ) ;
}
if ( V_101 && ( V_95 || V_96 ) ) {
F_62 ( V_89 , V_288 , V_140 ) ;
F_62 ( V_89 , V_289 , V_290 ) ;
}
if ( V_98 ) {
F_62 ( V_89 , V_291 , V_139 ) ;
F_62 ( V_89 , V_292 , V_293 ) ;
F_62 ( V_89 , V_294 , V_295 ) ;
}
F_65 ( V_7 -> V_86 , V_86 , V_7 -> V_86 ,
V_87 ) ;
}
int F_66 ( struct V_6 * V_7 , int type , int V_296 ,
int V_297 , struct V_298 * V_299 )
{
int V_85 = 0 ;
int V_52 ;
int V_300 = 0 ;
int V_301 = V_84 ;
const char * V_302 ;
V_7 -> V_27 = - 1 ;
if ( F_25 ( ! V_7 -> V_33 ) )
return - V_44 ;
if ( F_25 ( ! V_7 -> V_25 ) )
return - V_44 ;
F_67 ( & V_7 -> V_303 ) ;
F_68 ( & V_7 -> V_304 ) ;
switch ( type ) {
case V_92 :
V_302 = L_10 ;
break;
case V_94 :
V_302 = L_11 ;
break;
case V_16 :
V_302 = L_12 ;
break;
case V_31 :
V_302 = L_13 ;
break;
case V_97 :
V_302 = L_14 ;
break;
default:
F_46 ( V_305 L_15 ,
V_306 , type ) ;
return - V_44 ;
}
V_7 -> V_14 = type ;
V_7 -> V_28 = NULL ;
if ( V_7 -> V_307 == NULL )
V_7 -> V_307 = V_7 -> V_25 -> V_23 ;
if ( V_7 -> V_107 == NULL )
V_7 -> V_107 = V_7 -> V_25 -> V_107 ;
if ( V_7 -> V_36 == NULL )
V_7 -> V_36 = & V_7 -> V_25 -> V_36 ;
#ifdef F_69
switch ( type ) {
case V_92 :
V_300 = 0 ;
V_301 = 64 ;
break;
case V_16 :
V_300 = 64 ;
V_301 = 64 ;
break;
case V_94 :
V_300 = 224 ;
V_301 = 32 ;
break;
default:
V_300 = 128 ;
V_301 = 64 ;
break;
}
#endif
F_24 ( & V_26 ) ;
V_296 = F_12 ( V_7 , V_296 == - 1 ? 0 : V_296 , V_301 ) ;
if ( V_296 == V_301 )
V_296 = F_12 ( V_7 , 0 , V_301 ) ;
if ( V_296 == V_301 ) {
F_46 ( V_305 L_16 ) ;
F_26 ( & V_26 ) ;
return - V_308 ;
}
#ifdef F_69
V_85 = V_296 ;
#else
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ )
if ( V_6 [ V_85 ] == NULL )
break;
if ( V_85 == V_84 ) {
F_26 ( & V_26 ) ;
F_46 ( V_305 L_17 ) ;
return - V_308 ;
}
#endif
V_7 -> V_27 = V_85 + V_300 ;
V_7 -> V_19 = V_296 ;
F_8 ( V_7 ) ;
F_25 ( V_6 [ V_7 -> V_27 ] != NULL ) ;
V_7 -> V_8 = F_57 ( V_7 ) ;
V_6 [ V_7 -> V_27 ] = V_7 ;
F_26 ( & V_26 ) ;
if ( V_7 -> V_90 )
F_61 ( V_7 ) ;
V_7 -> V_28 = F_70 () ;
if ( V_7 -> V_28 == NULL ) {
V_52 = - V_309 ;
goto V_310;
}
V_7 -> V_28 -> V_89 = & V_311 ;
V_7 -> V_28 -> V_299 = V_299 ;
V_52 = F_71 ( V_7 -> V_28 , F_72 ( V_312 , V_7 -> V_27 ) , 1 ) ;
if ( V_52 < 0 ) {
F_46 ( V_305 L_18 , V_306 ) ;
F_17 ( V_7 -> V_28 ) ;
V_7 -> V_28 = NULL ;
goto V_310;
}
V_7 -> V_23 . V_313 = & V_314 ;
V_7 -> V_23 . V_315 = F_72 ( V_312 , V_7 -> V_27 ) ;
V_7 -> V_23 . V_316 = V_7 -> V_307 ;
F_73 ( & V_7 -> V_23 , L_19 , V_302 , V_7 -> V_19 ) ;
V_52 = F_74 ( & V_7 -> V_23 ) ;
if ( V_52 < 0 ) {
F_46 ( V_305 L_20 , V_306 ) ;
goto V_310;
}
V_7 -> V_23 . V_33 = F_23 ;
if ( V_296 != - 1 && V_296 != V_7 -> V_19 && V_297 )
F_46 ( V_317 L_21 , V_306 ,
V_302 , V_296 , F_47 ( V_7 ) ) ;
F_75 ( V_7 -> V_25 ) ;
#if F_28 ( V_29 )
if ( V_7 -> V_25 -> V_30 &&
V_7 -> V_14 != V_31 ) {
V_7 -> V_32 . type = V_318 ;
V_7 -> V_32 . V_13 = V_7 -> V_13 ;
V_7 -> V_32 . V_319 . V_23 . V_320 = V_312 ;
V_7 -> V_32 . V_319 . V_23 . V_27 = V_7 -> V_27 ;
V_52 = F_76 ( V_7 -> V_25 -> V_30 ,
& V_7 -> V_32 ) ;
if ( V_52 < 0 )
F_46 ( V_317
L_22 ,
V_306 ) ;
}
#endif
F_9 ( V_321 , & V_7 -> V_75 ) ;
return 0 ;
V_310:
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
F_11 ( V_321 , & V_7 -> V_75 ) ;
F_26 ( & V_26 ) ;
F_78 ( & V_7 -> V_23 ) ;
}
static int T_6 F_79 ( void )
{
T_7 V_23 = F_72 ( V_312 , 0 ) ;
int V_52 ;
F_46 ( V_322 L_23 ) ;
V_52 = F_80 ( V_23 , V_84 , V_323 ) ;
if ( V_52 < 0 ) {
F_46 ( V_317 L_24 ,
V_312 ) ;
return V_52 ;
}
V_52 = F_81 ( & V_314 ) ;
if ( V_52 < 0 ) {
F_82 ( V_23 , V_84 ) ;
F_46 ( V_317 L_25 ) ;
return - V_324 ;
}
return 0 ;
}
static void T_8 F_83 ( void )
{
T_7 V_23 = F_72 ( V_312 , 0 ) ;
F_84 ( & V_314 ) ;
F_82 ( V_23 , V_84 ) ;
}
