static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
int V_5 ;
if ( V_3 < V_6 ) {
V_4 = V_7 ;
V_5 = V_8 ;
} else if ( ( V_3 >= V_6 ) &&
( V_3 < V_9 ) ) {
V_4 = V_10 ;
V_5 = V_11 ;
} else if ( ( V_3 >= V_9 ) &&
( V_3 < V_12 ) ) {
V_4 = V_13 ;
V_5 = V_14 ;
} else if ( ( V_3 >= V_12 ) &&
( V_3 <= V_15 ) ) {
V_4 = V_16 ;
V_5 = V_17 ;
} else {
return - V_18 ;
}
F_2 ( V_2 , V_19 , V_4 ) ;
return V_5 ;
}
static void F_3 ( struct V_1 * V_2 , int V_20 )
{
switch ( V_20 ) {
case V_21 :
F_2 ( V_2 , V_22 , V_23 ) ;
F_2 ( V_2 , V_24 , V_25 |
V_26 | V_27 ) ;
F_2 ( V_2 , V_28 , V_29 |
V_30 ) ;
F_2 ( V_2 , V_31 ,
V_32 | V_33 ) ;
F_2 ( V_2 , V_34 , V_35 ) ;
break;
case V_36 :
F_2 ( V_2 , V_22 , V_37 ) ;
F_2 ( V_2 , V_24 , V_38 ) ;
F_2 ( V_2 , V_28 , V_39 ) ;
break;
default:
F_4 ( V_40 L_1 ) ;
break;
}
}
static int F_5 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
struct V_45 * V_46 = (struct V_45 * ) V_42 -> V_47 ;
unsigned int V_48 = V_46 -> V_48 ;
unsigned int V_49 = V_44 -> V_50 . integer . V_50 [ 0 ] ;
unsigned int V_51 ;
switch ( V_49 ) {
case V_52 :
V_51 = V_53 ;
break;
case V_54 :
V_51 = V_55 ;
break;
case V_56 :
V_51 = V_57 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_48 , V_58 , V_51 ) ;
return 0 ;
}
static int F_8 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
struct V_45 * V_46 = (struct V_45 * ) V_42 -> V_47 ;
unsigned int V_48 = V_46 -> V_48 ;
int V_4 ;
V_4 = F_9 ( V_2 , V_48 ) & V_58 ;
switch ( V_4 ) {
case V_55 :
V_44 -> V_50 . integer . V_50 [ 0 ] = V_54 ;
break;
case V_57 :
V_44 -> V_50 . integer . V_50 [ 0 ] = V_56 ;
break;
default:
V_44 -> V_50 . integer . V_50 [ 0 ] = V_52 ;
break;
}
return 0 ;
}
static int F_10 ( struct V_59 * V_60 ,
struct V_41 * V_42 , int V_61 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
switch ( V_61 ) {
case V_62 :
switch ( V_60 -> V_48 ) {
case V_63 :
F_7 ( V_2 , V_64 ,
V_65 ,
V_65 ) ;
break;
case V_66 :
F_7 ( V_2 , V_64 ,
V_67 ,
V_67 ) ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_60 -> V_48 , V_68 ,
V_69 ) ;
F_7 ( V_2 , V_60 -> V_48 , V_70 ,
V_71 ) ;
break;
case V_72 :
F_7 ( V_2 , V_60 -> V_48 , V_70 ,
V_73 ) ;
F_7 ( V_2 , V_60 -> V_48 , V_68 ,
V_74 ) ;
switch ( V_60 -> V_48 ) {
case V_63 :
F_7 ( V_2 , V_64 ,
V_65 , 0 ) ;
break;
case V_66 :
F_7 ( V_2 , V_64 ,
V_67 , 0 ) ;
break;
default:
return - V_18 ;
}
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_59 * V_60 ,
struct V_41 * V_42 , int V_61 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
switch ( V_61 ) {
case V_62 :
F_7 ( V_2 , V_60 -> V_48 ,
( 1 << V_60 -> V_75 ) | V_76 ,
( 1 << V_60 -> V_75 ) | V_76 ) ;
break;
case V_72 :
F_7 ( V_2 , V_60 -> V_48 ,
( 1 << V_60 -> V_75 ) | V_76 ,
( 1 << V_60 -> V_75 ) | V_77 ) ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_12 ( struct V_78 * V_79 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
T_1 V_84 = 0 ;
T_1 V_85 ;
T_1 V_86 ;
V_85 = V_83 -> V_87 -> V_88 ;
switch ( F_13 ( V_81 ) ) {
case V_89 :
V_84 |= V_90 ;
break;
case V_91 :
V_84 |= V_92 ;
break;
case V_93 :
V_84 |= V_94 ;
break;
case V_95 :
V_84 |= V_96 ;
break;
default:
return - V_18 ;
}
switch ( F_14 ( V_81 ) ) {
case 8000 :
V_86 = V_97 ;
break;
case 11025 :
V_86 = V_98 ;
break;
case 12000 :
V_86 = V_99 ;
break;
case 16000 :
V_86 = V_100 ;
break;
case 22050 :
V_86 = V_101 ;
break;
case 24000 :
V_86 = V_102 ;
break;
case 32000 :
V_86 = V_103 ;
break;
case 44100 :
V_86 = V_104 ;
break;
case 48000 :
V_86 = V_105 ;
break;
case 88100 :
V_86 = V_106 ;
break;
case 96000 :
V_86 = V_107 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_85 , V_108 , V_84 ) ;
F_7 ( V_2 , V_109 , V_110 , V_86 ) ;
return 0 ;
}
static int F_15 ( struct V_82 * V_83 , T_1 V_111 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
T_1 V_112 , V_113 ;
T_1 V_114 , V_115 ;
T_1 V_116 , V_117 ;
switch ( V_83 -> V_118 ) {
case V_119 :
V_114 = V_120 ;
V_116 = V_121 ;
V_113 = V_122 | V_123 |
V_124 ;
break;
case V_125 :
V_114 = V_126 ;
V_116 = V_127 ;
V_113 = V_128 | V_123 |
V_124 ;
break;
default:
return - V_18 ;
}
switch ( V_111 & V_129 ) {
case V_130 :
V_115 = V_131 ;
V_112 = V_132 | V_133 ;
break;
case V_134 :
V_115 = V_135 ;
V_112 = V_136 ;
break;
default:
return - V_18 ;
}
switch ( V_111 & V_137 ) {
case V_138 :
V_117 = V_139 ;
break;
case V_140 :
V_117 = V_141 ;
break;
case V_142 :
V_117 = V_143 ;
break;
case V_144 :
V_117 = V_145 ;
break;
default:
return - V_18 ;
}
switch ( V_111 & V_137 ) {
case V_144 :
switch ( V_111 & V_146 ) {
case V_147 :
break;
case V_148 :
V_117 |= V_149 ;
break;
default:
return - V_18 ;
}
break;
case V_138 :
case V_140 :
case V_142 :
switch ( V_111 & V_146 ) {
case V_147 :
break;
case V_150 :
V_117 |= V_149 | V_151 ;
break;
case V_148 :
V_117 |= V_149 ;
break;
case V_152 :
V_117 |= V_151 ;
break;
default:
return - V_18 ;
}
break;
default:
return - V_18 ;
}
F_2 ( V_2 , V_153 , V_112 ) ;
F_7 ( V_2 , V_114 , V_154 , V_115 ) ;
F_7 ( V_2 , V_116 , V_149 |
V_151 | V_155 , V_117 ) ;
F_2 ( V_2 , V_156 , V_113 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_157 ,
int V_158 , unsigned int V_159 ,
unsigned int V_160 )
{
struct V_161 * V_162 = F_17 ( V_2 ) ;
int V_163 , V_164 ;
T_2 V_165 , V_166 , V_167 ;
T_3 V_168 ;
if ( V_160 == 0 ) {
F_7 ( V_2 , V_19 ,
V_169 , 0 ) ;
V_162 -> V_170 = false ;
return 0 ;
}
if ( V_162 -> V_170 )
return - V_171 ;
if ( V_158 == V_172 ) {
switch ( V_162 -> V_3 ) {
case 11290000 :
case 12288000 :
case 22580000 :
case 24576000 :
case 45160000 :
case 49152000 :
F_2 ( V_2 , V_19 ,
V_173 ) ;
return 0 ;
default:
F_18 ( V_2 -> V_174 ,
L_2 ) ;
return - V_18 ;
}
}
V_164 = F_1 ( V_2 , V_162 -> V_3 ) ;
if ( V_164 < 0 )
return V_164 ;
V_163 = ( V_162 -> V_3 / V_164 ) ;
V_167 = V_160 / V_163 ;
V_168 = ( T_3 ) ( V_160 % V_163 ) * 8192ULL ;
F_19 ( V_168 , V_163 ) ;
V_166 = ( V_168 >> V_175 ) & V_176 ;
V_165 = ( V_168 ) & V_176 ;
F_2 ( V_2 , V_177 , V_165 ) ;
F_2 ( V_2 , V_178 , V_166 ) ;
F_2 ( V_2 , V_179 , V_167 ) ;
F_7 ( V_2 , V_19 , V_169 ,
V_169 ) ;
V_162 -> V_170 = true ;
return 0 ;
}
static int F_20 ( struct V_82 * V_83 , int V_180 ,
unsigned int V_181 , int V_182 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_161 * V_162 = F_17 ( V_2 ) ;
V_162 -> V_3 = V_181 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_183 [ V_184 ] ;
T_2 V_185 [ V_184 ] ;
T_2 V_186 = V_187 ;
F_2 ( V_2 , V_188 ,
V_189 ) ;
F_2 ( V_2 , V_190 ,
V_189 ) ;
F_2 ( V_2 , V_191 ,
V_192 |
V_193 ) ;
F_2 ( V_2 , V_194 ,
V_192 |
V_193 ) ;
F_22 ( V_195 ) ;
V_185 [ V_196 ] = ( V_2 -> V_197 ( V_2 , V_191 ) &
V_198 ) ;
V_185 [ V_199 ] = ( V_2 -> V_197 ( V_2 , V_194 ) &
V_198 ) ;
V_183 [ V_196 ] = V_185 [ V_196 ] << V_200 ;
V_183 [ V_199 ] = V_185 [ V_199 ] << V_200 ;
do {
V_183 [ V_196 ] |= V_186 ;
V_183 [ V_199 ] |= V_186 ;
F_2 ( V_2 , V_188 ,
~ V_183 [ V_196 ] & V_201 ) ;
F_2 ( V_2 , V_190 ,
~ V_183 [ V_199 ] & V_201 ) ;
F_22 ( V_195 ) ;
if ( ( V_2 -> V_197 ( V_2 , V_191 ) &
V_198 ) ^ V_185 [ V_196 ] )
V_183 [ V_196 ] &= ~ V_186 ;
if ( ( V_2 -> V_197 ( V_2 , V_194 ) &
V_198 ) ^ V_185 [ V_199 ] )
V_183 [ V_199 ] &= ~ V_186 ;
V_186 >>= 1 ;
} while ( V_186 );
F_2 ( V_2 , V_188 ,
~ V_183 [ V_196 ] & V_201 ) ;
F_2 ( V_2 , V_190 ,
~ V_183 [ V_199 ] & V_201 ) ;
F_2 ( V_2 , V_191 ,
V_193 ) ;
F_2 ( V_2 , V_194 ,
V_193 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_2 V_183 [ V_202 ] ;
T_2 V_185 [ V_202 ] ;
T_2 V_186 = V_203 ;
V_183 [ V_204 ] = V_205 ;
V_183 [ V_206 ] = V_205 ;
F_2 ( V_2 , V_207 , V_205 ) ;
F_2 ( V_2 , V_208 , V_205 ) ;
F_2 ( V_2 , V_209 ,
V_210 | V_211 ) ;
F_2 ( V_2 , V_212 ,
V_210 | V_211 ) ;
F_22 ( V_195 ) ;
V_185 [ V_204 ] = V_2 -> V_197 ( V_2 , V_209 ) &
V_213 ;
V_185 [ V_206 ] = V_2 -> V_197 ( V_2 , V_212 ) &
V_213 ;
F_2 ( V_2 , V_209 , V_210 |
( V_185 [ V_204 ] >> V_214 ) |
V_211 ) ;
F_2 ( V_2 , V_212 , V_210 |
( V_185 [ V_206 ] >> V_214 ) |
V_211 ) ;
do {
V_183 [ V_204 ] |= V_186 ;
V_183 [ V_206 ] |= V_186 ;
F_2 ( V_2 , V_207 ,
V_183 [ V_204 ] ) ;
F_2 ( V_2 , V_208 ,
V_183 [ V_206 ] ) ;
F_22 ( V_195 ) ;
if ( ( V_2 -> V_197 ( V_2 , V_209 ) &
V_213 ) ^ V_185 [ V_204 ] )
V_183 [ V_204 ] &= ~ V_186 ;
if ( ( V_2 -> V_197 ( V_2 , V_212 ) &
V_213 ) ^ V_185 [ V_206 ] )
V_183 [ V_206 ] &= ~ V_186 ;
V_186 >>= 1 ;
} while ( V_186 );
F_2 ( V_2 , V_207 , V_183 [ V_204 ] ) ;
F_2 ( V_2 , V_208 , V_183 [ V_206 ] ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_215 , V_216 |
V_217 | V_218 ) ;
F_2 ( V_2 , V_219 , V_220 |
V_221 | V_222 | V_223 |
V_224 | V_225 ) ;
F_2 ( V_2 , V_209 , V_226 |
V_227 | V_211 ) ;
F_2 ( V_2 , V_212 , V_211 |
V_227 | V_226 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_2 ( V_2 , V_219 , V_228 ) ;
F_2 ( V_2 , V_209 , V_229 ) ;
F_2 ( V_2 , V_212 , V_229 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_230 V_231 )
{
struct V_161 * V_162 = F_17 ( V_2 ) ;
switch ( V_231 ) {
case V_232 :
F_7 ( V_2 , V_233 ,
V_234 ,
V_235 ) ;
break;
case V_236 :
break;
case V_237 :
if ( V_2 -> V_238 . V_239 == V_240 ) {
F_2 ( V_2 , V_241 ,
V_242 ) ;
F_2 ( V_2 , V_233 ,
V_243 ) ;
F_26 ( V_244 ) ;
F_2 ( V_2 , V_241 ,
V_245 ) ;
F_2 ( V_2 , V_246 ,
V_247 ) ;
F_2 ( V_2 , V_248 ,
V_249 ) ;
F_2 ( V_2 , V_250 ,
V_251 |
V_252 |
V_253 ) ;
F_2 ( V_2 , V_254 ,
V_255 ) ;
F_3 ( V_2 , V_21 ) ;
F_2 ( V_2 , V_256 ,
V_257 | V_258 ) ;
F_2 ( V_2 , V_259 ,
V_260 |
V_261 |
V_262 |
V_263 |
V_264 |
V_265 |
V_266 |
V_267 ) ;
F_2 ( V_2 , V_268 ,
V_269 | V_270 |
V_271 | V_272 |
V_273 ) ;
F_24 ( V_2 ) ;
F_27 ( V_2 -> V_274 , false ) ;
F_28 ( V_2 -> V_274 ) ;
} else {
F_7 ( V_2 , V_233 ,
V_234 ,
V_275 ) ;
F_7 ( V_2 , V_19 ,
V_169 , 0 ) ;
V_162 -> V_170 = false ;
}
break;
case V_240 :
F_27 ( V_2 -> V_274 , true ) ;
F_3 ( V_2 , V_36 ) ;
F_7 ( V_2 , V_233 , V_243 ,
V_276 ) ;
V_162 -> V_170 = false ;
break;
}
V_2 -> V_238 . V_239 = V_231 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_161 * V_162 = F_17 ( V_2 ) ;
struct V_277 * V_238 = & V_2 -> V_238 ;
int V_5 = 0 ;
V_162 -> V_2 = V_2 ;
V_238 -> V_278 = false ;
V_2 -> V_274 = V_162 -> V_279 ;
V_5 = F_30 ( V_2 , 8 , 8 , V_280 ) ;
if ( V_5 != 0 ) {
F_18 ( V_2 -> V_174 , L_3 ) ;
goto V_281;
}
F_25 ( V_2 , V_237 ) ;
V_281:
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_240 ) ;
return 0 ;
}
static int F_32 ( struct V_282 * V_283 ,
const struct V_284 * V_118 )
{
struct V_161 * V_162 ;
unsigned int V_48 ;
int V_5 ;
V_162 = F_33 ( & V_283 -> V_174 , sizeof( struct V_161 ) ,
V_285 ) ;
if ( ! V_162 )
return - V_286 ;
F_34 ( V_283 , V_162 ) ;
V_162 -> V_279 = F_35 ( V_283 , & V_287 ) ;
if ( F_36 ( V_162 -> V_279 ) ) {
V_5 = F_37 ( V_162 -> V_279 ) ;
F_18 ( & V_283 -> V_174 , L_4 ) ;
goto V_281;
}
V_5 = F_38 ( V_162 -> V_279 , V_288 , & V_48 ) ;
if ( V_5 < 0 ) {
F_18 ( & V_283 -> V_174 , L_5 , V_5 ) ;
goto V_281;
}
F_39 ( & V_283 -> V_174 , L_6 ,
( V_48 & V_289 ) , ( V_48 & V_290 ) ) ;
V_5 = F_40 ( & V_283 -> V_174 , & V_291 ,
V_292 , F_41 ( V_292 ) ) ;
if ( V_5 != 0 )
F_18 ( & V_283 -> V_174 , L_3 ) ;
V_281:
return V_5 ;
}
static int F_42 ( struct V_282 * V_293 )
{
F_43 ( & V_293 -> V_174 ) ;
return 0 ;
}
