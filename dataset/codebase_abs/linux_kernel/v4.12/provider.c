static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
return F_2 ( - V_8 ) ;
}
static int F_3 ( struct V_1 * V_9 )
{
return - V_8 ;
}
static int F_4 ( struct V_10 * V_11 , union V_12 * V_13 , T_1 V_14 )
{
return - V_8 ;
}
static int F_5 ( struct V_10 * V_11 , union V_12 * V_13 , T_1 V_14 )
{
return - V_8 ;
}
static int F_6 ( struct V_15 * V_16 , int V_17 ,
T_2 V_18 , const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_23 * V_24 ,
T_3 V_25 ,
struct V_23 * V_26 ,
T_3 * V_27 ,
T_1 * V_28 )
{
return - V_8 ;
}
void F_7 ( struct V_29 * V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 , * V_36 ;
V_31 = F_8 ( V_29 , struct V_30 , V_29 ) ;
V_33 = F_9 ( V_31 -> V_37 . V_38 ) ;
F_10 ( L_1 , V_39 , V_31 ) ;
F_11 (mm, tmp, &ucontext->mmaps, entry)
F_12 ( V_35 ) ;
F_13 ( & V_33 -> V_40 , & V_31 -> V_41 ) ;
F_12 ( V_31 ) ;
}
static int F_14 ( struct V_42 * V_43 )
{
struct V_30 * V_31 = F_15 ( V_43 ) ;
F_10 ( L_2 , V_39 , V_43 ) ;
F_16 ( V_31 ) ;
return 0 ;
}
static struct V_42 * F_17 ( struct V_15 * V_16 ,
struct V_6 * V_7 )
{
struct V_30 * V_43 ;
struct V_32 * V_33 = F_9 ( V_16 ) ;
struct V_44 V_45 ;
int V_46 = 0 ;
struct V_34 * V_35 = NULL ;
F_10 ( L_3 , V_39 , V_16 ) ;
V_43 = F_18 ( sizeof( * V_43 ) , V_47 ) ;
if ( ! V_43 ) {
V_46 = - V_48 ;
goto V_49;
}
F_19 ( & V_33 -> V_40 , & V_43 -> V_41 ) ;
F_20 ( & V_43 -> V_50 ) ;
F_21 ( & V_43 -> V_51 ) ;
F_22 ( & V_43 -> V_29 ) ;
if ( V_7 -> V_52 < sizeof( V_45 ) - sizeof( V_45 . V_53 ) ) {
F_23 ( L_4 ) ;
V_33 -> V_40 . V_54 |= V_55 ;
} else {
V_35 = F_24 ( sizeof( * V_35 ) , V_47 ) ;
if ( ! V_35 ) {
V_46 = - V_48 ;
goto V_56;
}
V_45 . V_57 = V_58 ;
F_25 ( & V_43 -> V_51 ) ;
V_45 . V_59 = V_43 -> V_60 ;
V_43 -> V_60 += V_58 ;
F_26 ( & V_43 -> V_51 ) ;
V_46 = F_27 ( V_7 , & V_45 ,
sizeof( V_45 ) - sizeof( V_45 . V_53 ) ) ;
if ( V_46 )
goto V_61;
V_35 -> V_60 = V_45 . V_59 ;
V_35 -> V_62 = F_28 ( V_33 -> V_40 . V_63 ) ;
V_35 -> V_64 = V_58 ;
F_29 ( V_43 , V_35 ) ;
}
return & V_43 -> V_37 ;
V_61:
F_12 ( V_35 ) ;
V_56:
F_12 ( V_43 ) ;
V_49:
return F_2 ( V_46 ) ;
}
static int F_30 ( struct V_42 * V_43 , struct V_65 * V_66 )
{
int V_64 = V_66 -> V_67 - V_66 -> V_68 ;
T_4 V_60 = V_66 -> V_69 << V_70 ;
struct V_71 * V_40 ;
int V_46 = 0 ;
struct V_34 * V_35 ;
struct V_30 * V_31 ;
T_5 V_62 ;
F_10 ( L_5 , V_39 , V_66 -> V_69 ,
V_60 , V_64 ) ;
if ( V_66 -> V_68 & ( V_58 - 1 ) )
return - V_72 ;
V_40 = & ( F_9 ( V_43 -> V_38 ) -> V_40 ) ;
V_31 = F_15 ( V_43 ) ;
V_35 = F_31 ( V_31 , V_60 , V_64 ) ;
if ( ! V_35 )
return - V_72 ;
V_62 = V_35 -> V_62 ;
F_12 ( V_35 ) ;
if ( ( V_62 >= F_32 ( V_40 -> V_73 . V_74 , 0 ) ) &&
( V_62 < ( F_32 ( V_40 -> V_73 . V_74 , 0 ) +
F_33 ( V_40 -> V_73 . V_74 , 0 ) ) ) ) {
V_66 -> V_75 = F_34 ( V_66 -> V_75 ) ;
V_46 = F_35 ( V_66 , V_66 -> V_68 ,
V_62 >> V_70 ,
V_64 , V_66 -> V_75 ) ;
} else if ( ( V_62 >= F_32 ( V_40 -> V_73 . V_74 , 2 ) ) &&
( V_62 < ( F_32 ( V_40 -> V_73 . V_74 , 2 ) +
F_33 ( V_40 -> V_73 . V_74 , 2 ) ) ) ) {
if ( V_62 >= V_40 -> V_76 )
V_66 -> V_75 = F_36 ( V_66 -> V_75 ) ;
else {
if ( ! F_37 ( V_40 -> V_73 . V_77 ) )
V_66 -> V_75 =
F_36 ( V_66 -> V_75 ) ;
else
V_66 -> V_75 =
F_34 ( V_66 -> V_75 ) ;
}
V_46 = F_35 ( V_66 , V_66 -> V_68 ,
V_62 >> V_70 ,
V_64 , V_66 -> V_75 ) ;
} else {
V_46 = F_38 ( V_66 , V_66 -> V_68 ,
V_62 >> V_70 ,
V_64 , V_66 -> V_75 ) ;
}
return V_46 ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
struct V_78 * V_79 ;
V_79 = F_40 ( V_3 ) ;
V_33 = V_79 -> V_33 ;
F_10 ( L_6 , V_39 , V_3 , V_79 -> V_80 ) ;
F_41 ( & V_33 -> V_40 . V_81 . V_82 , V_79 -> V_80 ) ;
F_42 ( & V_33 -> V_40 . V_83 . V_84 ) ;
V_33 -> V_40 . V_83 . V_3 . V_85 -- ;
F_43 ( & V_33 -> V_40 . V_83 . V_84 ) ;
F_12 ( V_79 ) ;
return 0 ;
}
static struct V_2 * F_44 ( struct V_15 * V_16 ,
struct V_42 * V_43 ,
struct V_6 * V_7 )
{
struct V_78 * V_79 ;
T_4 V_80 ;
struct V_32 * V_33 ;
F_10 ( L_3 , V_39 , V_16 ) ;
V_33 = (struct V_32 * ) V_16 ;
V_80 = F_45 ( & V_33 -> V_40 . V_81 . V_82 ) ;
if ( ! V_80 )
return F_2 ( - V_72 ) ;
V_79 = F_18 ( sizeof( * V_79 ) , V_47 ) ;
if ( ! V_79 ) {
F_41 ( & V_33 -> V_40 . V_81 . V_82 , V_80 ) ;
return F_2 ( - V_48 ) ;
}
V_79 -> V_80 = V_80 ;
V_79 -> V_33 = V_33 ;
if ( V_43 ) {
if ( F_27 ( V_7 , & V_79 -> V_80 , sizeof( T_4 ) ) ) {
F_39 ( & V_79 -> V_86 ) ;
return F_2 ( - V_87 ) ;
}
}
F_42 ( & V_33 -> V_40 . V_83 . V_84 ) ;
V_33 -> V_40 . V_83 . V_3 . V_85 ++ ;
if ( V_33 -> V_40 . V_83 . V_3 . V_85 > V_33 -> V_40 . V_83 . V_3 . V_88 )
V_33 -> V_40 . V_83 . V_3 . V_88 = V_33 -> V_40 . V_83 . V_3 . V_85 ;
F_43 ( & V_33 -> V_40 . V_83 . V_84 ) ;
F_10 ( L_7 , V_39 , V_80 , V_79 ) ;
return & V_79 -> V_86 ;
}
static int F_46 ( struct V_15 * V_16 , T_2 V_89 , T_1 V_90 ,
T_1 * V_91 )
{
F_10 ( L_3 , V_39 , V_16 ) ;
* V_91 = 0 ;
return 0 ;
}
static int F_47 ( struct V_15 * V_16 , T_2 V_89 , int V_90 ,
union V_12 * V_13 )
{
struct V_32 * V_92 ;
F_10 ( L_8 ,
V_39 , V_16 , V_89 , V_90 , V_13 ) ;
V_92 = F_9 ( V_16 ) ;
F_48 ( V_89 == 0 ) ;
memset ( & ( V_13 -> V_93 [ 0 ] ) , 0 , sizeof( V_13 -> V_93 ) ) ;
memcpy ( & ( V_13 -> V_93 [ 0 ] ) , V_92 -> V_40 . V_73 . V_94 [ V_89 - 1 ] -> V_95 , 6 ) ;
return 0 ;
}
static int F_49 ( struct V_15 * V_16 , struct V_96 * V_97 ,
struct V_6 * V_98 )
{
struct V_32 * V_92 ;
F_10 ( L_3 , V_39 , V_16 ) ;
if ( V_98 -> V_99 || V_98 -> V_52 )
return - V_72 ;
V_92 = F_9 ( V_16 ) ;
memset ( V_97 , 0 , sizeof *V_97 ) ;
memcpy ( & V_97 -> V_100 , V_92 -> V_40 . V_73 . V_94 [ 0 ] -> V_95 , 6 ) ;
V_97 -> V_101 = F_50 ( V_92 -> V_40 . V_73 . V_77 ) ;
V_97 -> V_102 = V_92 -> V_40 . V_73 . V_103 ;
V_97 -> V_104 = V_92 -> V_104 ;
V_97 -> V_105 = V_106 ;
V_97 -> V_107 = ( T_4 ) V_92 -> V_40 . V_73 . V_74 -> V_108 ;
V_97 -> V_109 = ( T_4 ) V_92 -> V_40 . V_73 . V_74 -> V_38 ;
V_97 -> V_110 = V_111 ;
V_97 -> V_112 = V_92 -> V_40 . V_73 . V_113 -> V_114 . V_115 / 2 ;
V_97 -> V_116 = V_92 -> V_40 . V_117 . V_118 ;
V_97 -> V_119 = V_120 ;
V_97 -> V_121 = 1 ;
V_97 -> V_122 = V_92 -> V_40 . V_73 . V_123 ;
V_97 -> V_124 = F_51 ( V_92 -> V_40 . V_73 . V_125 ,
V_126 ) ;
V_97 -> V_127 = V_97 -> V_124 ;
V_97 -> V_128 = V_92 -> V_40 . V_73 . V_113 -> V_114 . V_115 ;
V_97 -> V_129 = V_92 -> V_40 . V_117 . V_130 ;
V_97 -> V_131 = F_52 ( & V_92 -> V_40 ) ;
V_97 -> V_132 = V_133 ;
V_97 -> V_134 = 0 ;
V_97 -> V_135 =
F_53 ( V_92 -> V_40 . V_73 . V_136 && V_137 ) ;
return 0 ;
}
static int F_54 ( struct V_15 * V_16 , T_2 V_89 ,
struct V_138 * V_97 )
{
struct V_32 * V_92 ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
F_10 ( L_3 , V_39 , V_16 ) ;
V_92 = F_9 ( V_16 ) ;
V_140 = V_92 -> V_40 . V_73 . V_94 [ V_89 - 1 ] ;
V_97 -> V_143 = V_144 ;
V_97 -> V_145 = F_55 ( V_140 -> V_146 ) ;
if ( ! F_56 ( V_140 ) )
V_97 -> V_147 = V_148 ;
else {
V_142 = F_57 ( V_140 ) ;
if ( V_142 ) {
if ( V_142 -> V_149 )
V_97 -> V_147 = V_150 ;
else
V_97 -> V_147 = V_151 ;
F_58 ( V_142 ) ;
} else
V_97 -> V_147 = V_151 ;
}
V_97 -> V_152 =
V_153 |
V_154 |
V_155 |
V_156 |
V_157 | V_158 ;
V_97 -> V_159 = 1 ;
V_97 -> V_160 = 1 ;
V_97 -> V_161 = 2 ;
V_97 -> V_162 = V_163 ;
V_97 -> V_164 = - 1 ;
return 0 ;
}
static T_6 F_59 ( struct V_38 * V_92 , struct V_165 * V_166 ,
char * V_167 )
{
struct V_32 * V_32 = F_8 ( V_92 , struct V_32 ,
V_16 . V_92 ) ;
F_10 ( L_9 , V_39 , V_92 ) ;
return sprintf ( V_167 , L_10 ,
F_50 ( V_32 -> V_40 . V_73 . V_77 ) ) ;
}
static T_6 F_60 ( struct V_38 * V_92 , struct V_165 * V_166 ,
char * V_167 )
{
struct V_32 * V_32 = F_8 ( V_92 , struct V_32 ,
V_16 . V_92 ) ;
struct V_168 V_169 ;
struct V_139 * V_170 = V_32 -> V_40 . V_73 . V_94 [ 0 ] ;
F_10 ( L_9 , V_39 , V_92 ) ;
V_170 -> V_171 -> V_172 ( V_170 , & V_169 ) ;
return sprintf ( V_167 , L_11 , V_169 . V_173 ) ;
}
static T_6 F_61 ( struct V_38 * V_92 , struct V_165 * V_166 ,
char * V_167 )
{
struct V_32 * V_32 = F_8 ( V_92 , struct V_32 ,
V_16 . V_92 ) ;
F_10 ( L_9 , V_39 , V_92 ) ;
return sprintf ( V_167 , L_12 , V_32 -> V_40 . V_73 . V_74 -> V_108 ,
V_32 -> V_40 . V_73 . V_74 -> V_38 ) ;
}
static struct V_174 * F_62 ( struct V_15 * V_16 ,
T_2 V_18 )
{
F_63 ( F_64 ( V_175 ) != V_176 ) ;
if ( V_18 != 0 )
return NULL ;
return F_65 ( V_175 , V_176 ,
V_177 ) ;
}
static int F_66 ( struct V_15 * V_16 ,
struct V_174 * V_83 ,
T_2 V_89 , int V_90 )
{
struct V_178 V_179 , V_180 ;
struct V_32 * V_32 = F_9 ( V_16 ) ;
F_67 ( V_32 -> V_40 . V_73 . V_74 , & V_179 , & V_180 ) ;
V_83 -> V_181 [ V_182 ] = V_179 . V_183 ;
V_83 -> V_181 [ V_184 ] = V_179 . V_185 ;
V_83 -> V_181 [ V_186 ] = V_179 . V_187 ;
V_83 -> V_181 [ V_188 ] = V_179 . V_189 ;
V_83 -> V_181 [ V_190 ] = V_180 . V_183 ;
V_83 -> V_181 [ V_191 ] = V_180 . V_185 ;
V_83 -> V_181 [ V_192 ] = V_180 . V_187 ;
V_83 -> V_181 [ V_193 ] = V_180 . V_189 ;
return V_83 -> V_194 ;
}
static int F_68 ( struct V_15 * V_16 , T_2 V_18 ,
struct V_195 * V_196 )
{
struct V_138 V_166 ;
int V_49 ;
V_196 -> V_197 = V_198 ;
V_49 = F_69 ( V_16 , V_18 , & V_166 ) ;
if ( V_49 )
return V_49 ;
V_196 -> V_160 = V_166 . V_160 ;
V_196 -> V_159 = V_166 . V_159 ;
return 0 ;
}
static void F_70 ( struct V_15 * V_92 , char * V_199 ,
T_3 V_200 )
{
struct V_32 * V_32 = F_8 ( V_92 , struct V_32 ,
V_16 ) ;
F_10 ( L_9 , V_39 , V_92 ) ;
snprintf ( V_199 , V_200 , L_13 ,
F_71 ( V_32 -> V_40 . V_73 . V_103 ) ,
F_72 ( V_32 -> V_40 . V_73 . V_103 ) ,
F_73 ( V_32 -> V_40 . V_73 . V_103 ) ,
F_74 ( V_32 -> V_40 . V_73 . V_103 ) ) ;
}
int F_75 ( struct V_32 * V_92 )
{
int V_46 ;
int V_201 ;
F_10 ( L_14 , V_39 , V_92 ) ;
F_48 ( ! V_92 -> V_40 . V_73 . V_94 [ 0 ] ) ;
F_76 ( V_92 -> V_16 . V_202 , L_15 , V_203 ) ;
memset ( & V_92 -> V_16 . V_204 , 0 , sizeof( V_92 -> V_16 . V_204 ) ) ;
memcpy ( & V_92 -> V_16 . V_204 , V_92 -> V_40 . V_73 . V_94 [ 0 ] -> V_95 , 6 ) ;
V_92 -> V_16 . V_205 = V_206 ;
V_92 -> V_104 = V_207 | V_208 ;
if ( V_209 )
V_92 -> V_104 |= V_210 ;
V_92 -> V_16 . V_211 = 0 ;
V_92 -> V_16 . V_212 =
( 1ull << V_213 ) |
( 1ull << V_214 ) |
( 1ull << V_215 ) |
( 1ull << V_216 ) |
( 1ull << V_217 ) |
( 1ull << V_218 ) |
( 1ull << V_219 ) |
( 1ull << V_220 ) |
( 1ull << V_221 ) |
( 1ull << V_222 ) |
( 1ull << V_223 ) |
( 1ull << V_224 ) |
( 1ull << V_225 ) |
( 1ull << V_226 ) |
( 1ull << V_227 ) |
( 1ull << V_228 ) |
( 1ull << V_229 ) |
( 1ull << V_230 ) ;
V_92 -> V_16 . V_231 = V_232 ;
F_63 ( sizeof( V_233 ) > V_234 ) ;
memcpy ( V_92 -> V_16 . V_235 , V_233 , sizeof( V_233 ) ) ;
V_92 -> V_16 . V_236 = V_92 -> V_40 . V_73 . V_237 ;
V_92 -> V_16 . V_238 = V_92 -> V_40 . V_73 . V_239 ;
V_92 -> V_16 . V_92 . V_240 = & V_92 -> V_40 . V_73 . V_74 -> V_92 ;
V_92 -> V_16 . V_241 = F_49 ;
V_92 -> V_16 . V_242 = F_54 ;
V_92 -> V_16 . V_243 = F_46 ;
V_92 -> V_16 . V_244 = F_47 ;
V_92 -> V_16 . V_245 = F_17 ;
V_92 -> V_16 . V_246 = F_14 ;
V_92 -> V_16 . V_247 = F_30 ;
V_92 -> V_16 . V_248 = F_44 ;
V_92 -> V_16 . V_249 = F_39 ;
V_92 -> V_16 . V_250 = F_1 ;
V_92 -> V_16 . V_251 = F_3 ;
V_92 -> V_16 . V_252 = V_253 ;
V_92 -> V_16 . V_254 = V_255 ;
V_92 -> V_16 . V_256 = V_257 ;
V_92 -> V_16 . V_258 = V_259 ;
V_92 -> V_16 . V_260 = V_261 ;
V_92 -> V_16 . V_262 = V_263 ;
V_92 -> V_16 . V_264 = V_265 ;
V_92 -> V_16 . V_266 = V_267 ;
V_92 -> V_16 . V_268 = V_269 ;
V_92 -> V_16 . V_270 = V_271 ;
V_92 -> V_16 . V_272 = V_273 ;
V_92 -> V_16 . V_274 = V_275 ;
V_92 -> V_16 . V_276 = V_277 ;
V_92 -> V_16 . V_278 = V_279 ;
V_92 -> V_16 . V_280 = V_281 ;
V_92 -> V_16 . V_282 = F_4 ;
V_92 -> V_16 . V_283 = F_5 ;
V_92 -> V_16 . V_284 = F_6 ;
V_92 -> V_16 . V_285 = V_286 ;
V_92 -> V_16 . V_287 = V_288 ;
V_92 -> V_16 . V_289 = V_290 ;
V_92 -> V_16 . V_291 = F_62 ;
V_92 -> V_16 . V_292 = F_66 ;
V_92 -> V_16 . V_293 = V_294 ;
V_92 -> V_16 . V_295 = F_68 ;
V_92 -> V_16 . F_70 = F_70 ;
V_92 -> V_16 . V_296 = F_24 ( sizeof( struct V_297 ) , V_47 ) ;
if ( ! V_92 -> V_16 . V_296 )
return - V_48 ;
V_92 -> V_16 . V_296 -> V_298 = V_299 ;
V_92 -> V_16 . V_296 -> V_300 = V_301 ;
V_92 -> V_16 . V_296 -> V_302 = V_303 ;
V_92 -> V_16 . V_296 -> V_304 = V_305 ;
V_92 -> V_16 . V_296 -> V_306 = V_307 ;
V_92 -> V_16 . V_296 -> V_308 = V_309 ;
V_92 -> V_16 . V_296 -> V_310 = V_311 ;
V_92 -> V_16 . V_296 -> V_312 = V_313 ;
memcpy ( V_92 -> V_16 . V_296 -> V_314 , V_92 -> V_40 . V_73 . V_94 [ 0 ] -> V_202 ,
sizeof( V_92 -> V_16 . V_296 -> V_314 ) ) ;
V_46 = F_77 ( & V_92 -> V_16 , NULL ) ;
if ( V_46 )
goto V_315;
for ( V_201 = 0 ; V_201 < F_64 ( V_316 ) ; ++ V_201 ) {
V_46 = F_78 ( & V_92 -> V_16 . V_92 ,
V_316 [ V_201 ] ) ;
if ( V_46 )
goto V_317;
}
return 0 ;
V_317:
F_79 ( & V_92 -> V_16 ) ;
V_315:
F_12 ( V_92 -> V_16 . V_296 ) ;
return V_46 ;
}
void F_80 ( struct V_32 * V_92 )
{
int V_201 ;
F_10 ( L_14 , V_39 , V_92 ) ;
for ( V_201 = 0 ; V_201 < F_64 ( V_316 ) ; ++ V_201 )
F_81 ( & V_92 -> V_16 . V_92 ,
V_316 [ V_201 ] ) ;
F_79 ( & V_92 -> V_16 ) ;
F_12 ( V_92 -> V_16 . V_296 ) ;
return;
}
