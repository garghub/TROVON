int F_1 ( T_1 V_1 )
{
return ( V_1 >= V_2 ) &&
( V_1 < V_3 ) ;
}
int F_2 ( struct V_4 * V_5 )
{
struct V_6 V_7 ;
T_2 V_8 ;
if ( F_3 ( F_4 ( V_9 , & V_5 -> V_10 ) ,
L_1 ) )
return - V_11 ;
V_7 . V_12 = ( V_13 ) ( 2 * V_5 -> V_14 ) ;
if ( V_7 . V_12 > V_5 -> V_15 -> V_16 ) {
V_7 . V_12 =
V_5 -> V_15 -> V_16 ;
}
V_7 . V_17 = V_18 ;
V_7 . V_19 = V_20 ;
if ( F_5 ( V_5 -> V_21 -> V_22 ) == 1 )
V_8 = V_23 ;
else
V_8 = V_24 ;
return F_6 ( V_5 , V_8 , V_25 ,
sizeof( V_7 ) , & V_7 ) ;
}
void F_7 ( struct V_4 * V_5 )
{
F_8 ( & V_5 -> V_26 . V_27 ) ;
V_5 -> V_28 = F_9 ( V_5 -> V_26 . V_29 . V_28 ) ;
F_10 ( V_5 ) ;
}
int F_11 ( T_1 V_30 , enum V_31 V_32 )
{
int V_33 = 0 ;
int V_34 = 0 ;
if ( V_30 & V_35 ) {
V_33 = ( V_30 & 0xff ) ;
return V_33 ;
} else {
if ( V_32 == V_36 )
V_34 = V_37 ;
for ( V_33 = V_34 ; V_33 < V_38 ; V_33 ++ )
if ( V_39 [ V_33 ] . V_40 == ( V_30 & 0xFF ) )
return V_33 - V_34 ;
}
return - 1 ;
}
int F_12 ( struct V_4 * V_5 ,
struct V_41 * V_42 , bool V_43 )
{
struct V_44 * V_45 = ( void * ) V_42 -> V_46 ;
if ( V_43 )
return F_13 ( V_5 , V_45 -> V_47 ,
V_42 -> V_48 . V_49 ,
& V_45 -> V_50 ) ;
return F_14 ( V_5 , V_45 -> V_50 ,
V_42 -> V_48 . V_49 ) ;
}
int F_15 ( struct V_4 * V_5 , T_3 V_51 )
{
struct V_52 V_53 ;
struct V_54 V_55 = {
. V_56 = V_57 ,
. V_58 = { sizeof( struct V_52 ) , } ,
. V_17 = V_25 ,
. V_59 = { & V_53 , } ,
} ;
F_16 () ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
if ( V_51 & F_17 ( V_60 ) )
V_53 . V_61 = V_62 | V_63 |
V_64 | V_65 |
V_66 ;
if ( ( V_51 & F_17 ( V_67 ) ) &&
( V_5 -> V_68 != F_17 ( V_60 ) ) )
V_53 . V_61 |= V_69 |
V_70 | V_71 |
V_72 | V_73 |
V_74 ;
if ( V_5 -> V_15 -> V_75 & V_76 )
V_53 . V_61 |= V_77 ;
F_18 ( V_5 , L_2 ,
V_53 . V_61 ) ;
V_53 . V_51 = F_19 ( V_51 ) ;
return F_20 ( V_5 , & V_55 ) ;
}
void F_21 ( struct V_4 * V_5 , T_3 V_51 )
{
F_22 ( & V_5 -> V_78 ) ;
F_23 ( V_5 -> V_79 ) ;
if ( F_15 ( V_5 , V_80 ) ) {
F_24 ( V_5 , L_3 ) ;
goto V_81;
}
F_18 ( V_5 , L_4 ) ;
F_25 ( V_5 -> V_82 ) ;
V_81:
F_26 ( V_5 -> V_79 ) ;
F_27 ( & V_5 -> V_78 ) ;
}
void F_28 ( struct V_4 * V_5 )
{
struct V_83 V_84 = {
. V_85 = V_86 ,
. V_87 = V_88 ,
. V_89 = V_90 ,
. V_91 = V_92 ,
} ;
struct V_93 V_94 ;
struct V_95 V_96 ;
int V_97 ;
F_29 ( sizeof( V_98 ) !=
sizeof( V_84 . V_99 ) ) ;
if ( V_5 -> V_100 -> V_101 ) {
if ( V_5 -> V_100 -> V_101 -> V_102 ) {
V_96 . V_103 = F_30 (
V_5 -> V_100 -> V_101 -> V_104 ) ;
V_96 . V_105 = 0 ;
V_96 . V_106 = 0 ;
} else {
F_31 ( V_5 -> V_100 -> V_101 -> V_104 & ~ 0xFF ) ;
V_94 . V_103 =
V_5 -> V_100 -> V_101 -> V_104 ;
V_94 . V_105 = 0 ;
V_94 . V_106 = 0 ;
}
} else {
F_24 ( V_5 , L_5 ) ;
return;
}
V_84 . V_107 = V_5 -> V_107 ;
V_84 . V_108 = V_5 -> V_108 ;
if ( V_5 -> V_109 )
V_84 . V_110 = V_111 ;
V_84 . V_112 = V_5 -> V_113 ;
if ( ! V_114 . V_115 ||
V_5 -> V_116 == V_117 ) {
V_84 . V_17 = V_118 ;
} else {
V_84 . V_17 = V_119 <<
V_120 ;
if ( ! V_5 -> V_121 )
V_84 . V_17 |= V_122 ;
else
V_84 . V_17 &= ~ V_122 ;
if ( V_5 -> V_123 )
V_84 . V_17 |= V_124 ;
F_32 ( V_5 , L_6 , V_84 . V_17 ) ;
}
V_5 -> V_125 = V_84 . V_17 ;
if ( V_5 -> V_126 )
memcpy ( V_84 . V_99 , V_127 ,
sizeof( V_127 ) ) ;
else
memcpy ( V_84 . V_99 , V_98 ,
sizeof( V_98 ) ) ;
F_32 ( V_5 , L_7 ,
V_84 . V_17 ? L_8 : L_9 ,
V_5 -> V_126 ?
L_10 : L_11 ) ;
if ( V_5 -> V_100 -> V_101 -> V_102 ) {
memcpy ( & V_96 . V_84 , & V_84 ,
sizeof( V_84 ) ) ;
V_97 = F_6 ( V_5 , V_128 ,
V_25 , sizeof( V_96 ) , & V_96 ) ;
} else {
memcpy ( & V_94 . V_84 , & V_84 ,
sizeof( V_84 ) ) ;
V_97 = F_6 ( V_5 , V_128 ,
V_25 , sizeof( V_94 ) , & V_94 ) ;
}
if ( V_97 )
F_24 ( V_5 , L_12 ) ;
}
void F_33 ( struct V_4 * V_5 , bool V_129 )
{
struct V_130 * V_47 , * V_131 = NULL ;
bool V_132 = false ;
F_8 ( & V_5 -> V_78 ) ;
if ( V_129 ) {
F_34 (priv, ctx) {
if ( V_47 -> V_42 && V_47 -> V_42 -> type == V_133 &&
F_35 ( V_47 ) ) {
V_132 = true ;
break;
}
}
}
if ( ! V_129 || V_132 ) {
if ( V_5 -> V_134 ) {
V_47 = V_5 -> V_134 ;
F_36 ( V_47 -> V_42 ) ;
V_5 -> V_134 = NULL ;
}
return;
}
F_34 (priv, ctx) {
if ( V_47 -> V_42 && V_47 -> V_42 -> type == V_135 &&
F_35 ( V_47 ) ) {
V_131 = V_47 ;
break;
}
}
if ( V_131 == V_5 -> V_134 )
return;
if ( V_5 -> V_134 ) {
V_47 = V_5 -> V_134 ;
if ( V_47 -> V_42 )
F_36 ( V_47 -> V_42 ) ;
}
V_5 -> V_134 = V_131 ;
if ( ! V_131 )
return;
F_37 ( V_131 -> V_42 ,
V_136 ,
V_137 ) ;
}
static bool F_38 ( struct V_138 * V_139 )
{
return V_140 & V_139 -> V_141 >>
V_142 ;
}
static void F_39 ( struct V_143 * V_144 )
{
struct V_4 * V_5 =
F_40 ( V_144 , struct V_4 , V_145 ) ;
struct V_130 * V_47 ;
int V_146 = - 1 ;
if ( V_5 -> V_125 == V_118 ) {
return;
}
F_32 ( V_5 , L_13 ,
V_5 -> V_147 ) ;
switch ( V_5 -> V_147 ) {
case V_148 :
if ( V_5 -> V_149 )
V_146 = V_150 ;
else
V_146 = V_151 ;
break;
case V_152 :
V_146 = V_150 ;
break;
case V_153 :
case V_154 :
V_146 = V_155 ;
break;
default:
F_24 ( V_5 , L_14 ,
V_5 -> V_147 ) ;
break;
}
F_22 ( & V_5 -> V_78 ) ;
if ( F_4 ( V_9 , & V_5 -> V_10 ) )
goto V_156;
F_41 ( V_5 ) ;
if ( V_146 != - 1 ) {
V_5 -> V_157 . V_158 = V_146 ;
F_34 (priv, ctx) {
if ( V_47 -> V_42 && V_47 -> V_42 -> type == V_135 )
F_42 ( V_47 -> V_42 , V_146 ) ;
}
}
F_43 ( V_5 ) ;
V_156:
F_27 ( & V_5 -> V_78 ) ;
}
void F_43 ( struct V_4 * V_5 )
{
if ( V_5 -> V_159 &&
V_5 -> V_147 == V_154 )
F_33 ( V_5 , true ) ;
else
F_33 ( V_5 , false ) ;
}
static void F_44 ( struct V_4 * V_5 ,
struct V_138 * V_139 )
{
F_32 ( V_5 , L_15
L_16 ,
( V_160 & V_139 -> V_161 ) >>
V_162 ,
( V_163 & V_139 -> V_161 ) >>
V_164 ,
( V_165 & V_139 -> V_161 ) >>
V_166 ) ;
F_32 ( V_5 , L_17
L_18 ,
( V_167 & V_139 -> V_168 ) >>
V_169 ,
( V_170 & V_139 -> V_168 ) >>
V_171 ,
( V_172 & V_139 -> V_168 ) >>
V_173 ,
( V_174 & V_139 -> V_168 ) >>
V_175 ) ;
F_32 ( V_5 , L_19
L_20 ,
( V_140 & V_139 -> V_141 ) >>
V_142 ,
( V_176 & V_139 -> V_141 ) >>
V_177 ,
( V_178 & V_139 -> V_141 ) >>
V_179 ,
( V_180 & V_139 -> V_141 ) >>
V_181 ,
( V_182 & V_139 -> V_141 ) >>
V_183 ,
( V_184 & V_139 -> V_141 ) >>
V_185 ) ;
F_32 ( V_5 , L_21 ,
( V_186 & V_139 -> V_187 ) >>
V_188 ) ;
F_32 ( V_5 , L_22
L_23 ,
( V_189 & V_139 -> V_190 ) >>
V_191 ,
( V_192 & V_139 -> V_190 ) >>
V_193 ,
( V_194 & V_139 -> V_190 ) >>
V_195 ) ;
F_32 ( V_5 , L_24 ,
( V_196 & V_139 -> V_197 ) >>
V_198 ,
( V_199 & V_139 -> V_197 ) >>
V_200 ) ;
F_32 ( V_5 , L_25
L_26 ,
( V_201 & V_139 -> V_202 ) >>
V_203 ,
( V_204 & V_139 -> V_202 ) >>
V_205 ,
( V_206 & V_139 -> V_202 ) >>
V_207 ,
( V_208 & V_139 -> V_202 ) >>
V_209 ) ;
}
static bool F_45 ( struct V_4 * V_5 ,
struct V_138 * V_139 )
{
bool V_210 = false ;
T_2 V_211 = V_212 ;
static const T_4 V_213 [ 3 ] = {
V_214 ,
V_215 ,
V_216 } ;
static const T_4 V_217 [ 3 ] = {
V_218 ,
V_215 ,
V_216 } ;
if ( ! V_5 -> V_109 )
V_211 = ( V_140 & V_139 -> V_141 )
? V_219 : V_220 ;
if ( V_5 -> V_107 != V_213 [ V_211 ] ||
V_5 -> V_108 != V_217 [ V_211 ] ) {
V_5 -> V_113 |= V_221 ;
V_5 -> V_107 = V_213 [ V_211 ] ;
V_5 -> V_113 |= V_222 ;
V_5 -> V_108 = V_217 [ V_211 ] ;
V_210 = true ;
}
return V_210 ;
}
static bool F_46 ( struct V_4 * V_5 ,
struct V_138 * V_139 )
{
bool V_210 = false ;
struct V_130 * V_47 = & V_5 -> V_223 [ V_60 ] ;
int V_224 ;
if ( ! V_47 -> V_42 || ( V_47 -> V_42 -> type != V_135 ) ) {
F_18 ( V_5 , L_27 ) ;
return false ;
}
V_224 = F_47 ( V_47 -> V_42 ) ;
if ( ! V_224 ) {
F_32 ( V_5 , L_28 ) ;
return V_210 ;
}
if ( ! V_5 -> V_109 &&
! F_48 ( V_5 , V_67 ) &&
( V_224 > V_225 ) &&
( V_139 -> V_141 & ( V_180 |
V_184 ) ) &&
! ( V_139 -> V_141 & ( V_140 |
V_176 | V_178 ) ) ) {
V_5 -> V_109 = true ;
V_5 -> V_113 |= V_226 ;
V_210 = true ;
} else if ( V_5 -> V_109 &&
( F_48 ( V_5 , V_67 ) ||
( V_224 < V_227 ) ||
( V_139 -> V_141 & ( V_140 |
V_176 | V_178 ) ) ||
! ( V_139 -> V_141 & ( V_180 |
V_184 ) ) ) ) {
V_5 -> V_109 = false ;
V_5 -> V_113 |= V_226 ;
V_210 = true ;
}
return V_210 ;
}
int F_49 ( struct V_4 * V_5 ,
struct V_228 * V_229 ,
struct V_230 * V_55 )
{
struct V_231 * V_232 = F_50 ( V_229 ) ;
struct V_233 * V_234 = ( void * ) V_232 -> V_59 ;
struct V_138 * V_139 = & V_234 -> V_235 ;
if ( V_5 -> V_125 == V_118 ) {
return 0 ;
}
F_32 ( V_5 , L_29 ) ;
F_32 ( V_5 , L_30 , V_234 -> V_149 ) ;
F_32 ( V_5 , L_31 , V_234 -> V_147 ) ;
F_32 ( V_5 , L_32 ,
V_234 -> V_236 ) ;
F_44 ( V_5 , V_139 ) ;
V_5 -> V_237 = V_5 -> V_147 ;
V_5 -> V_159 = F_38 ( V_139 ) ;
if ( V_5 -> V_116 != V_117 ) {
if ( V_5 -> V_149 != V_234 -> V_149 ||
V_5 -> V_237 != V_234 -> V_147 ) {
if ( V_234 -> V_149 ) {
if ( ! V_5 -> V_123 )
V_5 -> V_147 =
V_153 ;
else
V_5 -> V_147 =
V_234 -> V_147 ;
} else {
V_5 -> V_147 =
V_148 ;
}
V_5 -> V_149 = V_234 -> V_149 ;
F_51 ( V_5 -> V_238 ,
& V_5 -> V_145 ) ;
}
}
if ( F_46 ( V_5 , V_139 ) ||
F_45 ( V_5 , V_139 ) )
F_51 ( V_5 -> V_238 , & V_5 -> V_239 ) ;
V_5 -> V_236 = V_234 -> V_236 ;
return 0 ;
}
void F_52 ( struct V_4 * V_5 )
{
V_5 -> V_240 [ V_241 ] =
F_49 ;
}
void F_53 ( struct V_4 * V_5 )
{
F_54 ( & V_5 -> V_145 ,
F_39 ) ;
}
void F_55 ( struct V_4 * V_5 )
{
F_56 ( & V_5 -> V_145 ) ;
}
static bool F_57 ( struct V_4 * V_5 )
{
return V_5 -> V_157 . V_158 == V_155 ||
V_5 -> V_157 . V_242 ;
}
static int F_58 ( struct V_4 * V_5 )
{
if ( V_5 -> V_100 -> V_101 &&
V_5 -> V_100 -> V_101 -> V_243 &&
( V_5 -> V_126 ||
V_5 -> V_147 >= V_153 ) ) {
return V_244 ;
}
if ( F_57 ( V_5 ) )
return V_244 ;
else
return V_245 ;
}
static int F_59 ( struct V_4 * V_5 , int V_246 )
{
switch ( V_5 -> V_157 . V_158 ) {
case V_155 :
case V_150 :
return V_247 ;
case V_151 :
case V_248 :
return V_246 ;
default:
F_60 ( 1 , L_33 ,
V_5 -> V_157 . V_158 ) ;
return V_246 ;
}
}
static T_2 F_61 ( T_1 V_249 )
{
T_2 V_250 ;
V_250 = ( V_249 & F_17 ( 0 ) ) >> 0 ;
V_250 += ( V_249 & F_17 ( 1 ) ) >> 1 ;
V_250 += ( V_249 & F_17 ( 2 ) ) >> 2 ;
V_250 += ( V_249 & F_17 ( 3 ) ) >> 3 ;
return V_250 ;
}
void F_62 ( struct V_4 * V_5 , struct V_130 * V_47 )
{
bool V_251 = F_57 ( V_5 ) ;
bool V_252 = ! F_4 ( V_253 , & V_5 -> V_10 ) ;
T_2 V_254 , V_255 , V_256 ;
T_1 V_257 ;
T_3 V_258 ;
if ( V_5 -> V_259 . V_257 )
V_257 = V_5 -> V_259 . V_257 ;
else
V_257 = V_5 -> V_15 -> V_260 ;
if ( V_5 -> V_100 -> V_101 &&
V_5 -> V_100 -> V_101 -> V_243 &&
( V_5 -> V_126 ||
V_5 -> V_147 >= V_153 ) ) {
V_257 = F_63 ( V_257 ) ;
}
V_258 = V_257 << V_261 ;
V_255 = F_58 ( V_5 ) ;
V_254 = F_59 ( V_5 , V_255 ) ;
V_256 = F_61 ( V_257 ) ;
if ( V_256 < V_255 )
V_255 = V_256 ;
if ( V_256 < V_254 )
V_254 = V_256 ;
V_258 |= V_255 << V_262 ;
V_258 |= V_254 << V_263 ;
V_47 -> V_264 . V_258 = F_19 ( V_258 ) ;
if ( ! V_251 && ( V_255 >= V_244 ) && V_252 )
V_47 -> V_264 . V_258 |= V_265 ;
else
V_47 -> V_264 . V_258 &= ~ V_265 ;
F_64 ( V_5 , L_34 ,
V_47 -> V_264 . V_258 ,
V_255 , V_254 ) ;
F_31 ( V_255 == 0 || V_254 == 0 ||
V_255 < V_254 ) ;
}
T_2 F_65 ( struct V_4 * V_5 , T_2 V_266 , T_2 V_112 )
{
int V_267 ;
T_2 V_268 = V_266 ;
if ( V_5 -> V_32 == V_269 &&
V_5 -> V_147 >= V_153 )
return 0 ;
for ( V_267 = 0 ; V_267 < V_270 - 1 ; V_267 ++ ) {
V_268 = ( V_268 + 1 ) < V_270 ? V_268 + 1 : 0 ;
if ( V_112 & F_17 ( V_268 ) )
return V_268 ;
}
return V_266 ;
}
static void F_66 ( T_3 * V_271 , T_5 * V_156 )
{
int V_267 ;
for ( V_267 = 0 ; V_267 < V_272 ; V_267 ++ )
V_156 [ V_267 ] = F_19 ( V_271 [ V_267 ] ) ;
}
static void F_67 ( struct V_273 * V_79 ,
struct V_41 * V_42 ,
struct V_274 * V_275 ,
struct V_276 * V_277 ,
void * V_278 )
{
struct V_4 * V_5 = F_68 ( V_79 ) ;
struct V_279 * V_59 = V_278 ;
struct V_130 * V_47 = V_59 -> V_47 ;
struct V_280 * V_280 , * V_281 = NULL ;
struct V_282 * V_282 , * V_283 = NULL ;
struct V_284 * V_285 ;
T_2 * V_286 ;
struct V_287 V_288 ;
T_1 V_289 = 0 ;
T_3 V_271 [ V_272 ] ;
int V_97 , V_267 ;
F_22 ( & V_5 -> V_78 ) ;
if ( ( V_277 -> V_290 == V_291 ||
V_277 -> V_290 == V_292 ) &&
! V_275 && ! V_47 -> V_293 )
V_97 = F_69 ( V_5 , V_47 , V_277 ) ;
else
V_97 = F_70 ( V_5 , V_47 , V_277 , V_275 ) ;
if ( V_97 ) {
F_24 ( V_5 , L_35 ) ;
V_59 -> error = true ;
}
switch ( V_277 -> V_290 ) {
case V_294 :
if ( V_275 ) {
V_282 = V_59 -> V_295 -> V_296 . V_297 . V_298 ;
V_283 = & V_59 -> V_295 -> V_296 . V_297 . V_299 ;
V_285 = V_59 -> V_297 -> V_300 ;
F_71 ( V_277 , & V_288 ) ;
V_283 -> V_301 = F_19 ( V_288 . V_297 . V_301 ) ;
V_283 -> V_302 = F_30 ( V_288 . V_297 . V_302 ) ;
F_72 ( V_277 , V_288 . V_297 . V_302 , V_271 ) ;
F_66 ( V_271 , V_59 -> V_297 -> V_303 . V_271 ) ;
memcpy ( V_59 -> V_297 -> V_304 . V_303 ,
& V_277 -> V_277 [ V_305 ] ,
V_306 ) ;
V_286 = V_59 -> V_297 -> V_304 . V_307 ;
} else {
V_282 =
V_59 -> V_295 -> V_296 . V_297 . V_308 ;
V_285 = V_59 -> V_297 -> V_309 ;
V_286 = V_59 -> V_297 -> V_304 . V_310 ;
}
for ( V_267 = 0 ; V_267 < V_311 ; V_267 ++ ) {
F_73 ( V_277 , V_267 , & V_288 ) ;
V_282 [ V_267 ] . V_301 = F_19 ( V_288 . V_297 . V_301 ) ;
V_282 [ V_267 ] . V_302 = F_30 ( V_288 . V_297 . V_302 ) ;
if ( V_288 . V_297 . V_302 > V_289 )
V_289 = V_288 . V_297 . V_302 ;
}
F_74 ( V_277 , V_59 -> V_49 , V_289 , V_271 ) ;
F_66 ( V_271 , V_285 [ 0 ] . V_271 ) ;
F_74 ( V_277 , V_59 -> V_49 ,
V_289 + 1 , V_271 ) ;
F_66 ( V_271 , V_285 [ 1 ] . V_271 ) ;
memcpy ( V_286 ,
& V_277 -> V_277 [ V_312 ] ,
V_306 ) ;
V_59 -> V_313 = true ;
V_59 -> V_314 = true ;
break;
case V_315 :
if ( V_275 ) {
T_2 * V_316 = V_288 . V_317 . V_316 ;
V_280 = V_59 -> V_295 -> V_296 . V_318 . V_298 ;
V_281 = & V_59 -> V_295 -> V_296 . V_318 . V_299 ;
F_71 ( V_277 , & V_288 ) ;
V_281 -> V_316 = F_75 (
( V_319 ) V_316 [ 5 ] |
( ( V_319 ) V_316 [ 4 ] << 8 ) |
( ( V_319 ) V_316 [ 3 ] << 16 ) |
( ( V_319 ) V_316 [ 2 ] << 24 ) |
( ( V_319 ) V_316 [ 1 ] << 32 ) |
( ( V_319 ) V_316 [ 0 ] << 40 ) ) ;
} else
V_280 = V_59 -> V_295 -> V_296 . V_318 . V_308 ;
for ( V_267 = 0 ; V_267 < V_311 ; V_267 ++ ) {
T_2 * V_316 = V_288 . V_317 . V_316 ;
F_73 ( V_277 , V_267 , & V_288 ) ;
V_280 -> V_316 = F_75 (
( V_319 ) V_316 [ 5 ] |
( ( V_319 ) V_316 [ 4 ] << 8 ) |
( ( V_319 ) V_316 [ 3 ] << 16 ) |
( ( V_319 ) V_316 [ 2 ] << 24 ) |
( ( V_319 ) V_316 [ 1 ] << 32 ) |
( ( V_319 ) V_316 [ 0 ] << 40 ) ) ;
}
V_59 -> V_314 = true ;
break;
}
F_27 ( & V_5 -> V_78 ) ;
}
int F_76 ( struct V_4 * V_5 ,
struct V_320 * V_321 )
{
struct V_322 * V_323 ;
struct V_54 V_55 = {
. V_56 = V_324 ,
. V_325 [ 0 ] = V_326 ,
. V_17 = V_25 ,
} ;
int V_267 , V_327 ;
if ( ! V_321 -> V_328 )
return 0 ;
V_55 . V_58 [ 0 ] = sizeof( * V_323 ) +
V_321 -> V_328 * sizeof( struct V_329 ) ;
V_323 = F_77 ( V_55 . V_58 [ 0 ] , V_330 ) ;
if ( ! V_323 )
return - V_331 ;
V_323 -> V_328 = F_30 ( V_321 -> V_328 ) ;
for ( V_267 = 0 ; V_267 < V_321 -> V_328 ; V_267 ++ ) {
int V_332 = F_78 ( V_321 -> V_333 [ V_267 ] . V_334 , 8 ) ;
memcpy ( & V_323 -> V_333 [ V_267 ] . V_335 ,
V_321 -> V_333 [ V_267 ] . V_335 , V_332 ) ;
memcpy ( & V_323 -> V_333 [ V_267 ] . V_336 ,
V_321 -> V_333 [ V_267 ] . V_336 ,
V_321 -> V_333 [ V_267 ] . V_334 ) ;
V_323 -> V_333 [ V_267 ] . V_337 = V_332 ;
V_323 -> V_333 [ V_267 ] . V_338 =
V_321 -> V_333 [ V_267 ] . V_334 ;
}
V_55 . V_59 [ 0 ] = V_323 ;
V_327 = F_20 ( V_5 , & V_55 ) ;
F_79 ( V_323 ) ;
return V_327 ;
}
int F_80 ( struct V_4 * V_5 , struct V_320 * V_321 )
{
struct V_339 V_340 ;
struct V_341 V_342 ;
struct V_130 * V_47 = & V_5 -> V_223 [ V_60 ] ;
struct V_343 V_344 ;
struct V_345 V_346 = {} ;
struct V_347 V_348 = {} ;
struct V_279 V_349 = {
. V_47 = V_47 ,
. V_49 = V_47 -> V_350 . V_351 ,
. V_314 = false ,
. V_297 = & V_346 ,
. V_313 = false ,
} ;
int V_97 , V_267 ;
T_3 V_288 ;
V_349 . V_295 = F_81 ( sizeof( * V_349 . V_295 ) , V_330 ) ;
if ( ! V_349 . V_295 )
return - V_331 ;
memset ( & V_340 , 0 , sizeof( V_340 ) ) ;
V_288 = F_82 ( V_5 -> V_352 ) & V_353 ;
V_340 . V_354 = F_19 ( V_288 ) ;
for ( V_267 = 0 ; V_267 < V_355 ; V_267 ++ ) {
V_288 = V_5 -> V_356 [ V_357 ] [ V_267 ] . V_358 ;
V_288 -= 0x10 ;
V_340 . V_359 [ V_267 ] = F_19 ( V_288 ) ;
}
if ( V_321 -> V_360 )
V_340 . V_361 |=
F_30 ( V_362 |
V_363 ) ;
if ( V_321 -> V_364 )
V_340 . V_361 |=
F_30 ( V_365 ) ;
if ( V_321 -> V_366 )
V_340 . V_361 |=
F_30 ( V_367 ) ;
if ( V_321 -> V_368 )
V_340 . V_361 |=
F_30 ( V_369 ) ;
if ( V_321 -> V_370 )
V_340 . V_361 |=
F_30 ( V_371 ) ;
if ( V_321 -> V_328 )
V_340 . V_361 |=
F_30 ( V_372 ) ;
if ( V_321 -> V_373 )
V_348 . V_374 |=
F_30 ( V_375 ) ;
F_83 ( V_5 , 200 ) ;
memcpy ( & V_342 , & V_47 -> V_350 , sizeof( V_342 ) ) ;
V_5 -> V_376 = false ;
F_84 ( V_5 -> V_82 ) ;
V_5 -> V_321 = true ;
V_97 = F_85 ( V_5 , V_377 ) ;
if ( V_97 )
goto V_156;
V_97 = F_86 ( V_5 ) ;
if ( V_97 )
goto V_156;
memcpy ( & V_47 -> V_264 , & V_342 , sizeof( V_342 ) ) ;
V_97 = F_87 ( V_5 , V_47 ) ;
if ( V_97 )
goto V_156;
V_97 = F_88 ( V_5 , true ) ;
if ( V_97 )
goto V_156;
if ( ! V_114 . V_378 ) {
V_5 -> V_379 = 0 ;
V_47 -> V_293 = 0 ;
F_27 ( & V_5 -> V_78 ) ;
F_89 ( V_5 -> V_79 , V_47 -> V_42 ,
F_67 ,
& V_349 ) ;
F_22 ( & V_5 -> V_78 ) ;
if ( V_349 . error ) {
V_97 = - V_380 ;
goto V_156;
}
if ( V_349 . V_314 ) {
struct V_54 V_381 = {
. V_56 = V_382 ,
. V_17 = V_25 ,
. V_59 [ 0 ] = V_349 . V_295 ,
. V_325 [ 0 ] = V_326 ,
. V_58 [ 0 ] = sizeof( * V_349 . V_295 ) ,
} ;
V_97 = F_20 ( V_5 , & V_381 ) ;
if ( V_97 )
goto V_156;
}
if ( V_349 . V_313 ) {
V_97 = F_6 ( V_5 ,
V_383 ,
V_25 , sizeof( V_346 ) ,
& V_346 ) ;
if ( V_97 )
goto V_156;
}
if ( V_5 -> V_384 ) {
memset ( & V_344 , 0 , sizeof( V_344 ) ) ;
memcpy ( V_344 . V_385 , V_5 -> V_385 , V_386 ) ;
V_344 . V_387 = F_19 ( V_386 ) ;
memcpy ( V_344 . V_388 , V_5 -> V_388 , V_389 ) ;
V_344 . V_390 = F_19 ( V_389 ) ;
V_344 . V_391 = V_5 -> V_391 ;
V_97 = F_6 ( V_5 ,
V_392 ,
V_25 , sizeof( V_344 ) ,
& V_344 ) ;
if ( V_97 )
goto V_156;
}
}
V_97 = F_6 ( V_5 , V_393 , V_25 ,
sizeof( V_348 ) , & V_348 ) ;
if ( V_97 )
goto V_156;
V_97 = F_6 ( V_5 , V_394 ,
V_25 , sizeof( V_340 ) ,
& V_340 ) ;
if ( V_97 )
goto V_156;
V_97 = F_76 ( V_5 , V_321 ) ;
V_156:
F_79 ( V_349 . V_295 ) ;
return V_97 ;
}
int F_20 ( struct V_4 * V_5 , struct V_54 * V_55 )
{
if ( F_90 ( V_5 ) || F_91 ( V_5 ) ) {
F_92 ( V_5 , L_36 ,
F_90 ( V_5 ) ? L_37 : L_38 ) ;
return - V_380 ;
}
if ( F_4 ( V_395 , & V_5 -> V_10 ) ) {
F_24 ( V_5 , L_39 ,
F_93 ( V_55 -> V_56 ) ) ;
return - V_380 ;
}
if ( ! ( V_55 -> V_17 & V_396 ) )
F_8 ( & V_5 -> V_78 ) ;
if ( V_5 -> V_397 == V_398 &&
! ( V_55 -> V_17 & V_399 ) ) {
F_94 ( V_5 , L_40 ) ;
return - V_380 ;
}
return F_95 ( V_5 -> V_82 , V_55 ) ;
}
int F_6 ( struct V_4 * V_5 , T_2 V_56 ,
T_1 V_17 , T_3 V_58 , const void * V_59 )
{
struct V_54 V_55 = {
. V_56 = V_56 ,
. V_58 = { V_58 , } ,
. V_59 = { V_59 , } ,
. V_17 = V_17 ,
} ;
return F_20 ( V_5 , & V_55 ) ;
}
