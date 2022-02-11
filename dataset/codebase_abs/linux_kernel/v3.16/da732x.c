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
case 16 :
V_84 |= V_89 ;
break;
case 20 :
V_84 |= V_90 ;
break;
case 24 :
V_84 |= V_91 ;
break;
case 32 :
V_84 |= V_92 ;
break;
default:
return - V_18 ;
}
switch ( F_14 ( V_81 ) ) {
case 8000 :
V_86 = V_93 ;
break;
case 11025 :
V_86 = V_94 ;
break;
case 12000 :
V_86 = V_95 ;
break;
case 16000 :
V_86 = V_96 ;
break;
case 22050 :
V_86 = V_97 ;
break;
case 24000 :
V_86 = V_98 ;
break;
case 32000 :
V_86 = V_99 ;
break;
case 44100 :
V_86 = V_100 ;
break;
case 48000 :
V_86 = V_101 ;
break;
case 88100 :
V_86 = V_102 ;
break;
case 96000 :
V_86 = V_103 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_85 , V_104 , V_84 ) ;
F_7 ( V_2 , V_105 , V_106 , V_86 ) ;
return 0 ;
}
static int F_15 ( struct V_82 * V_83 , T_1 V_107 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
T_1 V_108 , V_109 ;
T_1 V_110 , V_111 ;
T_1 V_112 , V_113 ;
switch ( V_83 -> V_114 ) {
case V_115 :
V_110 = V_116 ;
V_112 = V_117 ;
V_109 = V_118 | V_119 |
V_120 ;
break;
case V_121 :
V_110 = V_122 ;
V_112 = V_123 ;
V_109 = V_124 | V_119 |
V_120 ;
break;
default:
return - V_18 ;
}
switch ( V_107 & V_125 ) {
case V_126 :
V_111 = V_127 ;
V_108 = V_128 | V_129 ;
break;
case V_130 :
V_111 = V_131 ;
V_108 = V_132 ;
break;
default:
return - V_18 ;
}
switch ( V_107 & V_133 ) {
case V_134 :
V_113 = V_135 ;
break;
case V_136 :
V_113 = V_137 ;
break;
case V_138 :
V_113 = V_139 ;
break;
case V_140 :
V_113 = V_141 ;
break;
default:
return - V_18 ;
}
switch ( V_107 & V_133 ) {
case V_140 :
switch ( V_107 & V_142 ) {
case V_143 :
break;
case V_144 :
V_113 |= V_145 ;
break;
default:
return - V_18 ;
}
break;
case V_134 :
case V_136 :
case V_138 :
switch ( V_107 & V_142 ) {
case V_143 :
break;
case V_146 :
V_113 |= V_145 | V_147 ;
break;
case V_144 :
V_113 |= V_145 ;
break;
case V_148 :
V_113 |= V_147 ;
break;
default:
return - V_18 ;
}
break;
default:
return - V_18 ;
}
F_2 ( V_2 , V_149 , V_108 ) ;
F_7 ( V_2 , V_110 , V_150 , V_111 ) ;
F_7 ( V_2 , V_112 , V_145 |
V_147 | V_151 , V_113 ) ;
F_2 ( V_2 , V_152 , V_109 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_153 ,
int V_154 , unsigned int V_155 ,
unsigned int V_156 )
{
struct V_157 * V_158 = F_17 ( V_2 ) ;
int V_159 , V_160 ;
T_2 V_161 , V_162 , V_163 ;
T_3 V_164 ;
if ( V_156 == 0 ) {
F_7 ( V_2 , V_19 ,
V_165 , 0 ) ;
V_158 -> V_166 = false ;
return 0 ;
}
if ( V_158 -> V_166 )
return - V_167 ;
if ( V_154 == V_168 ) {
switch ( V_158 -> V_3 ) {
case 11290000 :
case 12288000 :
case 22580000 :
case 24576000 :
case 45160000 :
case 49152000 :
F_2 ( V_2 , V_19 ,
V_169 ) ;
return 0 ;
default:
F_18 ( V_2 -> V_170 ,
L_2 ) ;
return - V_18 ;
}
}
V_160 = F_1 ( V_2 , V_158 -> V_3 ) ;
if ( V_160 < 0 )
return V_160 ;
V_159 = ( V_158 -> V_3 / V_160 ) ;
V_163 = V_156 / V_159 ;
V_164 = ( T_3 ) ( V_156 % V_159 ) * 8192ULL ;
F_19 ( V_164 , V_159 ) ;
V_162 = ( V_164 >> V_171 ) & V_172 ;
V_161 = ( V_164 ) & V_172 ;
F_2 ( V_2 , V_173 , V_161 ) ;
F_2 ( V_2 , V_174 , V_162 ) ;
F_2 ( V_2 , V_175 , V_163 ) ;
F_7 ( V_2 , V_19 , V_165 ,
V_165 ) ;
V_158 -> V_166 = true ;
return 0 ;
}
static int F_20 ( struct V_82 * V_83 , int V_176 ,
unsigned int V_177 , int V_178 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_157 * V_158 = F_17 ( V_2 ) ;
V_158 -> V_3 = V_177 ;
return 0 ;
}
static bool F_21 ( struct V_179 * V_170 , unsigned int V_48 )
{
switch ( V_48 ) {
case V_180 :
case V_181 :
return true ;
default:
return false ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_182 [ V_183 ] ;
T_2 V_184 [ V_183 ] ;
T_2 V_185 = V_186 ;
F_2 ( V_2 , V_187 ,
V_188 ) ;
F_2 ( V_2 , V_189 ,
V_188 ) ;
F_2 ( V_2 , V_180 ,
V_190 |
V_191 ) ;
F_2 ( V_2 , V_181 ,
V_190 |
V_191 ) ;
F_23 ( V_192 ) ;
V_184 [ V_193 ] = ( F_9 ( V_2 , V_180 ) &
V_194 ) ;
V_184 [ V_195 ] = ( F_9 ( V_2 , V_181 ) &
V_194 ) ;
V_182 [ V_193 ] = V_184 [ V_193 ] << V_196 ;
V_182 [ V_195 ] = V_184 [ V_195 ] << V_196 ;
do {
V_182 [ V_193 ] |= V_185 ;
V_182 [ V_195 ] |= V_185 ;
F_2 ( V_2 , V_187 ,
~ V_182 [ V_193 ] & V_197 ) ;
F_2 ( V_2 , V_189 ,
~ V_182 [ V_195 ] & V_197 ) ;
F_23 ( V_192 ) ;
if ( ( F_9 ( V_2 , V_180 ) &
V_194 ) ^ V_184 [ V_193 ] )
V_182 [ V_193 ] &= ~ V_185 ;
if ( ( F_9 ( V_2 , V_181 ) &
V_194 ) ^ V_184 [ V_195 ] )
V_182 [ V_195 ] &= ~ V_185 ;
V_185 >>= 1 ;
} while ( V_185 );
F_2 ( V_2 , V_187 ,
~ V_182 [ V_193 ] & V_197 ) ;
F_2 ( V_2 , V_189 ,
~ V_182 [ V_195 ] & V_197 ) ;
F_2 ( V_2 , V_180 ,
V_191 ) ;
F_2 ( V_2 , V_181 ,
V_191 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_182 [ V_198 ] ;
T_2 V_184 [ V_198 ] ;
T_2 V_185 = V_199 ;
V_182 [ V_200 ] = V_201 ;
V_182 [ V_202 ] = V_201 ;
F_2 ( V_2 , V_203 , V_201 ) ;
F_2 ( V_2 , V_204 , V_201 ) ;
F_2 ( V_2 , V_205 ,
V_206 | V_207 ) ;
F_2 ( V_2 , V_208 ,
V_206 | V_207 ) ;
F_23 ( V_192 ) ;
V_184 [ V_200 ] = F_9 ( V_2 , V_205 ) &
V_209 ;
V_184 [ V_202 ] = F_9 ( V_2 , V_208 ) &
V_209 ;
F_2 ( V_2 , V_205 , V_206 |
( V_184 [ V_200 ] >> V_210 ) |
V_207 ) ;
F_2 ( V_2 , V_208 , V_206 |
( V_184 [ V_202 ] >> V_210 ) |
V_207 ) ;
do {
V_182 [ V_200 ] |= V_185 ;
V_182 [ V_202 ] |= V_185 ;
F_2 ( V_2 , V_203 ,
V_182 [ V_200 ] ) ;
F_2 ( V_2 , V_204 ,
V_182 [ V_202 ] ) ;
F_23 ( V_192 ) ;
if ( ( F_9 ( V_2 , V_205 ) &
V_209 ) ^ V_184 [ V_200 ] )
V_182 [ V_200 ] &= ~ V_185 ;
if ( ( F_9 ( V_2 , V_208 ) &
V_209 ) ^ V_184 [ V_202 ] )
V_182 [ V_202 ] &= ~ V_185 ;
V_185 >>= 1 ;
} while ( V_185 );
F_2 ( V_2 , V_203 , V_182 [ V_200 ] ) ;
F_2 ( V_2 , V_204 , V_182 [ V_202 ] ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_211 , V_212 |
V_213 | V_214 ) ;
F_2 ( V_2 , V_215 , V_216 |
V_217 | V_218 | V_219 |
V_220 | V_221 ) ;
F_2 ( V_2 , V_205 , V_222 |
V_223 | V_207 ) ;
F_2 ( V_2 , V_208 , V_207 |
V_223 | V_222 ) ;
F_22 ( V_2 ) ;
F_24 ( V_2 ) ;
F_2 ( V_2 , V_215 , V_224 ) ;
F_2 ( V_2 , V_205 , V_225 ) ;
F_2 ( V_2 , V_208 , V_225 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_226 V_227 )
{
struct V_157 * V_158 = F_17 ( V_2 ) ;
switch ( V_227 ) {
case V_228 :
F_7 ( V_2 , V_229 ,
V_230 ,
V_231 ) ;
break;
case V_232 :
break;
case V_233 :
if ( V_2 -> V_234 . V_235 == V_236 ) {
F_2 ( V_2 , V_237 ,
V_238 ) ;
F_2 ( V_2 , V_229 ,
V_239 ) ;
F_27 ( V_240 ) ;
F_2 ( V_2 , V_237 ,
V_241 ) ;
F_2 ( V_2 , V_242 ,
V_243 ) ;
F_2 ( V_2 , V_244 ,
V_245 ) ;
F_2 ( V_2 , V_246 ,
V_247 |
V_248 |
V_249 ) ;
F_2 ( V_2 , V_250 ,
V_251 ) ;
F_3 ( V_2 , V_21 ) ;
F_2 ( V_2 , V_252 ,
V_253 | V_254 ) ;
F_2 ( V_2 , V_255 ,
V_256 |
V_257 |
V_258 |
V_259 |
V_260 |
V_261 |
V_262 |
V_263 ) ;
F_2 ( V_2 , V_264 ,
V_265 | V_266 |
V_267 | V_268 |
V_269 ) ;
F_25 ( V_2 ) ;
F_28 ( V_158 -> V_270 , false ) ;
F_29 ( V_158 -> V_270 ) ;
} else {
F_7 ( V_2 , V_229 ,
V_230 ,
V_271 ) ;
F_7 ( V_2 , V_19 ,
V_165 , 0 ) ;
V_158 -> V_166 = false ;
}
break;
case V_236 :
F_28 ( V_158 -> V_270 , true ) ;
F_3 ( V_2 , V_36 ) ;
F_7 ( V_2 , V_229 , V_239 ,
V_272 ) ;
V_158 -> V_166 = false ;
break;
}
V_2 -> V_234 . V_235 = V_227 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_157 * V_158 = F_17 ( V_2 ) ;
struct V_273 * V_234 = & V_2 -> V_234 ;
V_158 -> V_2 = V_2 ;
V_234 -> V_274 = false ;
F_26 ( V_2 , V_233 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_26 ( V_2 , V_236 ) ;
return 0 ;
}
static int F_32 ( struct V_275 * V_276 ,
const struct V_277 * V_114 )
{
struct V_157 * V_158 ;
unsigned int V_48 ;
int V_5 ;
V_158 = F_33 ( & V_276 -> V_170 , sizeof( struct V_157 ) ,
V_278 ) ;
if ( ! V_158 )
return - V_279 ;
F_34 ( V_276 , V_158 ) ;
V_158 -> V_270 = F_35 ( V_276 , & V_280 ) ;
if ( F_36 ( V_158 -> V_270 ) ) {
V_5 = F_37 ( V_158 -> V_270 ) ;
F_18 ( & V_276 -> V_170 , L_3 ) ;
goto V_281;
}
V_5 = F_38 ( V_158 -> V_270 , V_282 , & V_48 ) ;
if ( V_5 < 0 ) {
F_18 ( & V_276 -> V_170 , L_4 , V_5 ) ;
goto V_281;
}
F_39 ( & V_276 -> V_170 , L_5 ,
( V_48 & V_283 ) >> 4 ,
( V_48 & V_284 ) ) ;
V_5 = F_40 ( & V_276 -> V_170 , & V_285 ,
V_286 , F_41 ( V_286 ) ) ;
if ( V_5 != 0 )
F_18 ( & V_276 -> V_170 , L_6 ) ;
V_281:
return V_5 ;
}
static int F_42 ( struct V_275 * V_287 )
{
F_43 ( & V_287 -> V_170 ) ;
return 0 ;
}
