void F_1 ( unsigned char V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = (struct V_5 * ) V_6 ;
V_3 -> V_7 = (struct V_8 * ) V_9 ;
V_3 -> V_10 = (struct V_11 * ) V_12 ;
V_3 -> V_13 = (struct V_14 * ) V_15 ;
V_3 -> V_16
= (struct V_17 * ) V_18 ;
V_3 -> V_19 = (struct V_20 * ) V_21 ;
V_3 -> V_22 = (struct V_23 * ) V_24 ;
V_3 -> V_25 = (struct V_26 * ) V_27 ;
V_3 -> V_28 = (struct V_29 * ) V_30 ;
V_3 -> V_31 = V_32 ;
V_3 -> V_33 = (struct V_34 * ) V_35 ;
V_3 -> V_36
= (struct V_37 * ) V_38 ;
V_3 -> V_39 = & V_40 ;
V_3 -> V_41 = & V_42 ;
V_3 -> V_43 = & V_44 ;
V_3 -> V_45 = 0 ;
V_3 -> V_46 = 0 ;
V_3 -> V_47 = 0 ;
V_3 -> V_48 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = V_51 ;
V_3 -> V_52 = V_53 ;
V_3 -> V_54 = V_55 ;
V_3 -> V_56 = & V_57 ;
V_3 -> V_58 = & V_59 ;
V_3 -> V_60 = V_61 ;
V_3 -> V_62 = V_63 ;
V_3 -> V_64 = V_65 ;
V_3 -> V_66 = V_67 ;
V_3 -> V_68 = V_69 ;
V_3 -> V_70 = V_71 ;
V_3 -> V_72 = & V_73 ;
V_3 -> V_74 = & V_75 ;
V_3 -> V_76 = V_77 ;
V_3 -> V_78 = & V_79 ;
V_3 -> V_80 = & V_81 ;
V_3 -> V_82 = & V_83 ;
V_3 -> V_84 = & V_85 ;
V_3 -> V_86 = & V_87 ;
V_3 -> V_88 = & V_89 ;
V_3 -> V_90 = & V_91 ;
V_3 -> V_92 = & V_93 ;
V_3 -> V_94 = & V_95 ;
V_3 -> V_96 = & V_97 ;
V_3 -> V_98 = & V_99 ;
V_3 -> V_100 = & V_101 ;
V_3 -> V_102 = & V_103 ;
V_3 -> V_104 = & V_105 ;
V_3 -> V_106 = & V_107 ;
V_3 -> V_108 = & V_109 ;
V_3 -> V_110 = V_111 ;
V_3 -> V_112 = V_113 ;
V_3 -> V_114 = V_115 ;
V_3 -> V_116 = V_117 ;
V_3 -> V_118 = V_119 ;
V_3 -> V_120 = V_121 ;
V_3 -> V_122 = V_123 ;
V_3 -> V_124 = V_125 ;
V_3 -> V_126 = V_127 ;
V_3 -> V_128 = V_129 ;
V_3 -> V_130 = V_131 ;
V_3 -> V_132 = V_133 ;
V_3 -> V_134 = V_135 ;
V_3 -> V_136 = V_137 ;
V_3 -> V_138 = (struct V_139 * ) V_140 ;
V_3 -> V_141 = (struct V_142 * ) V_143 ;
V_3 -> V_144 = (struct V_145 * ) V_146 ;
V_3 -> V_147 = V_148 ;
V_3 -> V_149 = V_150 ;
V_3 -> V_151 = V_152 ;
V_3 -> V_153 = V_154 ;
if ( ( V_3 -> V_155 & V_156 ) || ( V_3 -> V_155 & V_157 ) )
V_3 -> V_158 = V_159 ;
else
V_3 -> V_158 = V_160 ;
if ( ( V_1 == V_161 ) || ( V_1 == V_162 ) )
V_3 -> V_163 = V_164 ;
V_3 -> V_165 = V_166 ;
V_3 -> V_167 = V_168 ;
V_3 -> V_169 = & V_170 ;
if ( V_1 >= V_171 )
V_3 -> V_172 = & V_173 ;
if ( V_1 == V_162 ) {
V_3 -> V_19
= (struct V_20 * ) V_174 ;
V_3 -> V_52 = V_175 ;
V_3 -> V_172 = & V_176 ;
V_3 -> V_177 = & V_178 ;
V_3 -> V_179 = & V_180 ;
V_3 -> V_181 = V_182 ;
V_3 -> V_183 = V_184 ;
V_3 -> V_185 = & V_186 ;
V_3 -> V_187 = & V_188 ;
}
if ( V_1 >= V_171 ) {
V_3 -> V_189 = & V_190 ;
V_3 -> V_191 = & V_192 ;
V_3 -> V_193 = & V_194 ;
V_3 -> V_195 = & V_196 ;
V_3 -> V_197 = & V_198 ;
}
}
static unsigned char F_2 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned char V_201 ;
if ( V_199 <= 0x13 )
V_201 = V_3 -> V_4 [ V_200 ] . V_202 ;
else {
if ( V_3 -> V_203 <= 0x02 )
V_201 = 0x1B ;
else
V_201 = 0x0F ;
}
return V_201 ;
}
static void F_3 ( unsigned short V_199 ,
unsigned short V_204 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned char V_205 , V_206 ;
unsigned short V_207 , V_208 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
F_4 ( V_3 -> V_211 , 0x00 , 0x03 ) ;
V_205 = V_3 -> V_7 [ V_204 ] . V_212 [ 0 ] ;
V_207 = V_213 ;
if ( V_3 -> V_48 & V_213 ) {
V_205 |= 0x01 ;
} else {
if ( V_3 -> V_48 & ( V_214 | V_215 ) ) {
if ( V_3 -> V_48 & V_216 )
V_205 |= 0x01 ;
}
}
V_205 |= 0x20 ;
F_4 ( V_3 -> V_211 , 0x01 , V_205 ) ;
for ( V_207 = 02 ; V_207 <= 04 ; V_207 ++ ) {
V_206 = V_3 -> V_7 [ V_204 ] . V_212 [ V_207 - 1 ] ;
F_4 ( V_3 -> V_211 , V_207 , V_206 ) ;
}
}
static void F_5 ( unsigned short V_204 ,
struct V_2 * V_3 )
{
unsigned char V_217 ;
V_217 = V_3 -> V_7 [ V_204 ] . V_218 ;
F_6 ( V_217 , V_3 -> V_219 ) ;
}
static void F_7 ( struct V_220 * V_221 ,
unsigned short V_204 ,
struct V_2 * V_3 )
{
unsigned char V_222 ;
unsigned short V_207 ;
V_222 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x11 ) ;
V_222 &= 0x7f ;
F_4 ( V_3 -> V_223 , 0x11 , V_222 ) ;
for ( V_207 = 0 ; V_207 <= 0x18 ; V_207 ++ ) {
V_222 = V_3 -> V_7 [ V_204 ] . V_224 [ V_207 ] ;
F_4 ( V_3 -> V_223 , V_207 , V_222 ) ;
}
}
static void F_9 ( unsigned short V_199 ,
unsigned short V_204 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned char V_225 ;
unsigned short V_207 , V_208 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
for ( V_207 = 0 ; V_207 <= 0x13 ; V_207 ++ ) {
V_225 = V_3 -> V_7 [ V_204 ] . V_226 [ V_207 ] ;
if ( V_208 & V_227 ) {
if ( V_207 == 0x13 ) {
if ( V_3 -> V_48 & V_213 ) {
V_225 = 0 ;
} else {
if ( V_3 -> V_48 & ( V_214
| V_215 ) ) {
if ( V_3 -> V_48 &
V_216 )
V_225 = 0 ;
}
}
}
}
F_10 ( V_3 -> V_228 ) ;
F_6 ( V_207 , V_3 -> V_229 ) ;
F_6 ( V_225 , V_3 -> V_229 ) ;
}
F_10 ( V_3 -> V_228 ) ;
F_6 ( 0x14 , V_3 -> V_229 ) ;
F_6 ( 0x00 , V_3 -> V_229 ) ;
F_10 ( V_3 -> V_228 ) ;
F_6 ( 0x20 , V_3 -> V_229 ) ;
}
static void F_11 ( unsigned short V_204 ,
struct V_2 * V_3 )
{
unsigned char V_230 ;
unsigned short V_207 ;
for ( V_207 = 0 ; V_207 <= 0x08 ; V_207 ++ ) {
V_230 = V_3 -> V_7 [ V_204 ] . V_231 [ V_207 ] ;
F_4 ( V_3 -> V_232 , V_207 , V_230 ) ;
}
if ( V_3 -> V_203 > V_233 ) {
V_230 = ( unsigned char ) F_8 ( V_3 -> V_232 , 0x05 ) ;
V_230 &= 0xBF ;
F_4 ( V_3 -> V_232 , 0x05 , V_230 ) ;
}
}
static void F_12 ( struct V_2 * V_3 )
{
unsigned short V_207 ;
for ( V_207 = 0x0A ; V_207 <= 0x0E ; V_207 ++ )
F_4 ( V_3 -> V_211 , V_207 , 0x00 ) ;
}
static unsigned char F_13 ( struct V_2 * V_3 )
{
F_14 ( V_3 -> V_211 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_211 , 0x2B , V_3 -> V_25 [ 0 ] . V_234 ) ;
F_4 ( V_3 -> V_211 , 0x2C , V_3 -> V_25 [ 0 ] . V_235 ) ;
F_14 ( V_3 -> V_211 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_211 , 0x2B , V_3 -> V_25 [ 1 ] . V_234 ) ;
F_4 ( V_3 -> V_211 , 0x2C , V_3 -> V_25 [ 1 ] . V_235 ) ;
F_15 ( V_3 -> V_211 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_16 ( unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 , unsigned short * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_237 , V_238 , V_239 , V_208 , V_240 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
V_238 = V_3 -> V_13 [ V_236 + ( * V_207 ) ] . V_242 ;
V_237 = 0 ;
if ( V_3 -> V_243 == 0 ) {
if ( V_3 -> V_48 & V_244 ) {
V_237 |= V_245 ;
if ( V_3 -> V_155 & V_246 )
V_237 |= V_247 ;
}
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
V_237 |= V_248 ;
if ( V_3 -> V_45 != V_249 ) {
if ( V_3 -> V_45 != V_250 ) {
if ( V_3 -> V_47 &
V_251 ) {
if ( V_239 >= 9 ) {
V_237 = 0 ;
return 0 ;
}
}
}
}
}
if ( V_3 -> V_48 & V_252 ) {
if ( ( V_3 -> V_155 & V_156 ) &&
( V_3 -> V_253 == V_254 ) ) {
V_237 |= V_255 ;
if ( V_3 -> V_48 & V_216 ) {
if ( V_239 == 4 )
return 0 ;
if ( V_239 == 3 )
return 0 ;
if ( V_239 > 7 )
return 0 ;
}
} else {
V_237 |= V_256 ;
if ( V_3 -> V_48 & V_216 ) {
if ( V_239 == 4 )
return 0 ;
if ( V_239 == 3 ) {
if ( V_3 -> V_257
& V_258 )
return 0 ;
}
if ( V_239 > 7 )
return 0 ;
}
}
} else {
if ( V_3 -> V_48 & ( V_259 |
V_260 |
V_261 |
V_262 |
V_252 ) ) {
V_237 |= V_263 ;
if ( V_3 -> V_155 & ( V_264 | V_265
| V_156 | V_157
| V_246 ) ) {
V_237 |= V_266 ;
}
if ( ! ( V_3 -> V_48 & V_267 ) ) {
if ( V_208 & V_268 ) {
if ( V_3 -> V_48 &
V_216 ) {
if ( ! ( V_3 -> V_48 &
V_269 ) ) {
return 0 ;
}
}
}
}
}
}
} else {
if ( V_3 -> V_270 == 1 ) {
if ( V_3 -> V_48 & V_214 )
V_237 |= V_271 ;
}
if ( V_3 -> V_48 & V_215 ) {
V_237 |= V_248 ;
if ( V_239 > 0x08 )
return 0 ;
if ( V_3 -> V_45 < V_272 ) {
if ( V_239 > 0x07 )
return 0 ;
if ( V_239 == 0x04 )
return 0 ;
}
}
}
for (; V_3 -> V_13 [ V_236 + ( * V_207 ) ] . V_242 ==
V_238 ; ( * V_207 ) -- ) {
V_240 = V_3 -> V_13 [ V_236 + ( * V_207 ) ] .
V_273 ;
if ( V_240 & V_237 )
return 1 ;
if ( ( * V_207 ) == 0 )
break;
}
for ( ( * V_207 ) = 0 ; ; ( * V_207 ) ++ ) {
V_240 = V_3 -> V_13 [ V_236 + ( * V_207 ) ] .
V_273 ;
if ( V_3 -> V_13 [ V_236 + ( * V_207 ) ] . V_242
!= V_238 ) {
return 0 ;
}
if ( V_240 & V_237 )
return 1 ;
}
return 1 ;
}
static void F_17 ( unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_274 , V_275 ;
V_274 = V_3 -> V_13 [ V_236 ] . V_273 >> 8 ;
V_274 &= 0xC0 ;
V_275 = 0x2F ;
V_275 |= V_274 ;
F_6 ( V_275 , V_3 -> V_219 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_220 * V_221 )
{
unsigned char V_276 , V_277 , V_278 ;
unsigned short V_207 , V_279 ;
V_276 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x11 ) ;
V_276 &= 0x7F ;
F_4 ( V_3 -> V_223 , 0x11 , V_276 ) ;
V_276 = V_3 -> V_138 [ 0 ] . V_276 [ 0 ] ;
F_4 ( V_3 -> V_223 , 0 , V_276 ) ;
for ( V_207 = 0x01 ; V_207 <= 0x04 ; V_207 ++ ) {
V_276 = V_3 -> V_138 [ 0 ] . V_276 [ V_207 ] ;
F_4 ( V_3 -> V_223 , ( unsigned short ) ( V_207 + 1 ) , V_276 ) ;
}
for ( V_207 = 0x05 ; V_207 <= 0x06 ; V_207 ++ ) {
V_276 = V_3 -> V_138 [ 0 ] . V_276 [ V_207 ] ;
F_4 ( V_3 -> V_211 , ( unsigned short ) ( V_207 + 6 ) , V_276 ) ;
}
V_279 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x0e ) ;
V_279 &= 0x1F ;
V_276 = V_3 -> V_138 [ 0 ] . V_276 [ 7 ] ;
V_276 &= 0xE0 ;
V_276 |= V_279 ;
F_4 ( V_3 -> V_211 , 0x0e , V_276 ) ;
if ( V_221 -> V_280 >= V_171 ) {
V_276 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x04 ) ;
V_276 = V_276 - 1 ;
F_4 ( V_3 -> V_223 , 0x04 , V_276 ) ;
V_276 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x05 ) ;
V_277 = V_276 ;
V_277 &= 0xE0 ;
V_276 &= 0x1F ;
if ( V_276 == 0 ) {
V_278 = V_276 ;
V_276 = ( unsigned char ) F_8 ( V_3 -> V_211 ,
0x0c ) ;
V_276 &= 0xFB ;
F_4 ( V_3 -> V_211 , 0x0c , V_276 ) ;
V_276 = V_278 ;
}
V_276 = V_276 - 1 ;
V_276 |= V_277 ;
F_4 ( V_3 -> V_223 , 0x05 , V_276 ) ;
V_276 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x0e ) ;
V_276 = V_276 >> 5 ;
V_276 = V_276 + 3 ;
if ( V_276 > 7 )
V_276 = V_276 - 7 ;
V_276 = V_276 << 5 ;
F_14 ( V_3 -> V_211 , 0x0e , ~ 0xE0 , V_276 ) ;
}
}
static void F_19 ( unsigned short V_200 ,
unsigned short V_199 ,
struct V_2 * V_3 )
{
unsigned char V_276 ;
unsigned short V_207 , V_279 ;
for ( V_207 = 0x00 ; V_207 <= 0x01 ; V_207 ++ ) {
V_276 = V_3 -> V_141 [ 0 ] . V_276 [ V_207 ] ;
F_4 ( V_3 -> V_223 , ( unsigned short ) ( V_207 + 6 ) , V_276 ) ;
}
for ( V_207 = 0x02 ; V_207 <= 0x03 ; V_207 ++ ) {
V_276 = V_3 -> V_141 [ 0 ] . V_276 [ V_207 ] ;
F_4 ( V_3 -> V_223 , ( unsigned short ) ( V_207 + 0x0e ) , V_276 ) ;
}
for ( V_207 = 0x04 ; V_207 <= 0x05 ; V_207 ++ ) {
V_276 = V_3 -> V_141 [ 0 ] . V_276 [ V_207 ] ;
F_4 ( V_3 -> V_223 , ( unsigned short ) ( V_207 + 0x11 ) , V_276 ) ;
}
V_279 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x0a ) ;
V_279 &= 0xC0 ;
V_276 = V_3 -> V_141 [ 0 ] . V_276 [ 6 ] ;
V_276 &= 0x3F ;
V_276 |= V_279 ;
F_4 ( V_3 -> V_211 , 0x0a , V_276 ) ;
V_276 = V_3 -> V_141 [ 0 ] . V_276 [ 6 ] ;
V_276 &= 0x80 ;
V_276 = V_276 >> 2 ;
if ( V_199 <= 0x13 )
V_207 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_207 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_207 &= V_281 ;
if ( V_207 )
V_276 |= 0x80 ;
V_279 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x09 ) ;
V_279 &= 0x5F ;
V_276 |= V_279 ;
F_4 ( V_3 -> V_223 , 0x09 , V_276 ) ;
}
static void F_20 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 ,
struct V_220 * V_221 )
{
unsigned char V_201 , V_276 ;
unsigned short V_207 ;
V_201 = V_3 -> V_13 [ V_236 ] . V_282 ;
V_201 = V_201 & V_283 ;
V_276 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x11 ) ;
V_276 &= 0x7F ;
F_4 ( V_3 -> V_223 , 0x11 , V_276 ) ;
for ( V_207 = 0 ; V_207 < 8 ; V_207 ++ )
V_3 -> V_138 [ 0 ] . V_276 [ V_207 ]
= V_3 -> V_16 [ V_201 ] . V_284 [ V_207 ] ;
for ( V_207 = 0 ; V_207 < 7 ; V_207 ++ )
V_3 -> V_141 [ 0 ] . V_276 [ V_207 ]
= V_3 -> V_16 [ V_201 ] . V_284 [ V_207 + 8 ] ;
F_18 ( V_3 , V_221 ) ;
F_19 ( V_200 , V_199 , V_3 ) ;
if ( V_3 -> V_203 > 0x03 )
F_4 ( V_3 -> V_223 , 0x14 , 0x4F ) ;
}
static void F_21 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned char V_204 , V_201 , V_285 , V_286 , V_287 , V_288 ;
unsigned short V_289 , V_290 , V_291 ;
if ( V_199 <= 0x13 ) {
V_204 = F_2 ( V_199 , V_200 , V_3 ) ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 4 ] ;
F_4 ( V_3 -> V_211 , 0x2E , V_285 ) ;
V_286 = V_3 -> V_7 [ V_204 ] . V_224 [ 5 ] ;
V_286 &= 0x1F ;
V_287 = V_285 ;
V_287 &= 0xE0 ;
V_288 = V_287 | V_286 ;
if ( V_286 < ( V_285 & 0x1F ) )
V_288 |= 0x20 ;
V_288 <<= 2 ;
F_4 ( V_3 -> V_211 , 0x2F , V_288 ) ;
F_14 ( V_3 -> V_211 , 0x30 , 0xE3 , 00 ) ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 16 ] ;
V_286 = V_285 ;
V_285 &= 0x01 ;
F_22 ( V_3 -> V_211 , 0x33 , V_285 ) ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 7 ] ;
V_288 = V_286 >> 1 ;
V_287 = V_285 & 0x04 ;
V_287 <<= 5 ;
V_288 |= V_287 ;
F_4 ( V_3 -> V_211 , 0x34 , V_288 ) ;
V_289 = V_287 << 1 ;
V_289 |= V_286 ;
V_285 &= 0x80 ;
V_290 = V_285 << 2 ;
V_289 |= V_290 ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 17 ] ;
V_285 &= 0x0F ;
V_290 = V_289 & 0x3F0 ;
V_290 |= V_285 ;
V_291 = V_289 & 0x0F ;
if ( V_285 < V_291 )
V_290 |= 0x10 ;
V_290 &= 0xFF ;
V_285 = ( unsigned char ) V_290 ;
V_285 <<= 2 ;
V_289 &= 0x600 ;
V_289 >>= 9 ;
V_286 = ( unsigned char ) V_289 ;
V_285 |= V_286 ;
V_285 &= 0x7F ;
F_4 ( V_3 -> V_211 , 0x3F , V_285 ) ;
} else {
V_201 = V_3 -> V_13 [ V_236 ] . V_282 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 3 ] ;
V_287 = V_285 ;
F_4 ( V_3 -> V_211 , 0x2E , V_285 ) ;
V_288 = V_3 -> V_16 [ V_201 ] . V_284 [ 5 ] ;
V_288 &= 0xC0 ;
V_289 = V_288 ;
V_289 <<= 2 ;
V_289 |= V_285 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 4 ] ;
V_285 &= 0x1F ;
V_286 = V_3 -> V_16 [ V_201 ] . V_284 [ 6 ] ;
V_286 &= 0x04 ;
V_286 <<= 3 ;
V_285 |= V_286 ;
V_290 = V_289 & 0x3C0 ;
V_290 |= V_285 ;
V_287 &= 0x3F ;
if ( V_285 < V_287 )
V_290 |= 0x40 ;
V_290 &= 0xFF ;
V_285 = ( unsigned char ) V_290 ;
V_285 <<= 2 ;
V_288 >>= 6 ;
V_285 |= V_288 ;
F_4 ( V_3 -> V_211 , 0x2F , V_285 ) ;
F_14 ( V_3 -> V_211 , 0x30 , 0xE3 , 00 ) ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 10 ] ;
V_286 = V_285 ;
V_285 &= 0x01 ;
F_22 ( V_3 -> V_211 , 0x33 , V_285 ) ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 9 ] ;
V_287 = V_286 >> 1 ;
V_288 = V_285 & 0x04 ;
V_288 <<= 5 ;
V_287 |= V_288 ;
F_4 ( V_3 -> V_211 , 0x34 , V_287 ) ;
V_289 = V_288 ;
V_289 <<= 1 ;
V_289 |= V_286 ;
V_285 &= 0x80 ;
V_290 = V_285 << 2 ;
V_289 |= V_290 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 14 ] ;
V_285 &= 0x08 ;
V_290 = V_285 ;
V_290 <<= 7 ;
V_289 |= V_290 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 11 ] ;
V_285 &= 0x0F ;
V_286 = V_3 -> V_16 [ V_201 ] . V_284 [ 14 ] ;
V_286 &= 0x20 ;
V_286 >>= 1 ;
V_285 |= V_286 ;
V_290 = V_289 & 0x7E0 ;
V_290 |= V_285 ;
V_291 = V_289 & 0x1F ;
if ( V_285 < V_291 )
V_290 |= 0x20 ;
V_290 &= 0xFF ;
V_285 = ( unsigned char ) V_290 ;
V_285 <<= 2 ;
V_289 &= 0x600 ;
V_289 >>= 9 ;
V_286 = ( unsigned char ) V_289 ;
V_285 |= V_286 ;
V_285 &= 0x7F ;
F_4 ( V_3 -> V_211 , 0x3F , V_285 ) ;
}
}
static void F_23 ( unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_204 , V_201 , V_285 , V_286 , V_287 , V_288 ;
if ( V_199 <= 0x13 ) {
V_204 = F_2 ( V_199 , V_200 , V_3 ) ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 4 ] ;
F_4 ( V_3 -> V_211 , 0x2E , V_285 ) ;
V_286 = V_3 -> V_7 [ V_204 ] . V_224 [ 5 ] ;
V_286 &= 0x1F ;
V_287 = V_285 ;
V_287 &= 0xE0 ;
V_288 = V_287 | V_286 ;
if ( V_286 < ( V_285 & 0x1F ) )
V_288 |= 0x20 ;
V_288 <<= 2 ;
F_4 ( V_3 -> V_211 , 0x2F , V_288 ) ;
F_14 ( V_3 -> V_211 , 0x30 , 0xE3 , 00 ) ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 16 ] ;
F_4 ( V_3 -> V_211 , 0x34 , V_285 ) ;
V_287 = V_285 ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 7 ] ;
V_286 = V_285 ;
V_285 &= 0x04 ;
V_285 >>= 2 ;
F_14 ( V_3 -> V_211 , 0x35 , ~ 0x01 , V_285 ) ;
V_287 |= ( V_285 << 8 ) ;
V_287 |= ( V_286 & 0x80 ) << 2 ;
V_285 = V_3 -> V_7 [ V_204 ] . V_224 [ 17 ] ;
V_285 &= 0x0F ;
V_286 = V_287 ;
V_286 &= 0x3F0 ;
V_286 |= V_285 ;
if ( V_285 <= ( V_287 & 0x0F ) )
V_286 |= 0x10 ;
V_285 = ( unsigned char ) V_286 & 0xFF ;
V_285 <<= 2 ;
V_287 = ( V_287 & 0x600 ) >> 8 ;
F_14 ( V_3 -> V_211 , 0x3F , ~ 0xFC , V_285 ) ;
F_14 ( V_3 -> V_211 , 0x35 , ~ 0x06 , V_287 ) ;
} else {
V_201 = V_3 -> V_13 [ V_236 ] . V_282 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 3 ] ;
V_286 = V_285 ;
F_4 ( V_3 -> V_211 , 0x2E , V_285 ) ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 5 ] ;
V_285 &= 0xC0 ;
V_286 |= ( V_285 << 2 ) ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 4 ] ;
V_285 &= 0x1F ;
V_287 = V_285 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 6 ] ;
V_285 &= 0x04 ;
V_285 <<= 3 ;
V_287 |= V_285 ;
V_286 = V_286 & 0x3C0 ;
V_286 |= V_287 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 3 ] ;
V_285 &= 0x3F ;
if ( V_287 <= V_285 )
V_286 += 0x40 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 5 ] ;
V_285 &= 0xC0 ;
V_285 >>= 6 ;
V_285 |= ( ( V_286 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_211 , 0x2F , V_285 ) ;
F_14 ( V_3 -> V_211 , 0x30 , 0xE3 , 00 ) ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 10 ] ;
F_4 ( V_3 -> V_211 , 0x34 , V_285 ) ;
V_287 = V_285 ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 9 ] ;
V_286 = V_285 ;
V_285 = V_285 & 0x04 ;
V_285 >>= 2 ;
F_14 ( V_3 -> V_211 , 0x35 , ~ 0x01 , V_285 ) ;
V_287 |= ( V_285 << 8 ) ;
V_287 |= ( ( V_286 & 0x80 ) << 2 ) ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 14 ] ;
V_285 &= 0x08 ;
V_287 |= ( V_285 << 7 ) ;
V_285 = V_3 -> V_16 [ V_201 ] . V_284 [ 11 ] ;
V_285 &= 0x0F ;
V_286 = V_3 -> V_16 [ V_201 ] . V_284 [ 14 ] ;
V_286 &= 0x20 ;
V_286 >>= 1 ;
V_285 |= V_286 ;
V_286 = V_287 ;
V_286 &= 0x7E0 ;
V_286 |= V_285 ;
if ( V_286 <= V_287 )
V_286 |= 0x20 ;
V_285 = ( V_286 << 2 ) & 0xFF ;
F_14 ( V_3 -> V_211 , 0x3F , ~ 0xFC , V_285 ) ;
V_285 = V_287 >> 8 ;
F_14 ( V_3 -> V_211 , 0x35 , ~ 0x07 , V_285 ) ;
}
}
static void F_24 ( struct V_2 * V_3 ,
unsigned short V_236 , unsigned short V_199 )
{
unsigned short V_292 , V_293 , V_294 ;
unsigned short V_295 ;
V_295 = V_3 -> V_296 ;
F_4 ( V_3 -> V_223 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_223 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_223 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_223 , 0x47 , 0x00 ) ;
if ( ( ( * V_3 -> V_189 ) & 0xC0 ) == 0xC0 ) {
F_4 ( V_3 -> V_223 , 0x2E , * V_3 -> V_191 ) ;
F_4 ( V_3 -> V_223 , 0x2F , * V_3 -> V_193 ) ;
F_4 ( V_3 -> V_223 , 0x46 , * V_3 -> V_195 ) ;
F_4 ( V_3 -> V_223 , 0x47 , * V_3 -> V_197 ) ;
}
V_293 = F_8 ( V_3 -> V_223 , 0x37 ) ;
if ( V_293 & 0x01 ) {
F_22 ( V_3 -> V_211 , 0x06 , 0x40 ) ;
F_22 ( V_3 -> V_211 , 0x09 , 0x40 ) ;
}
F_22 ( V_3 -> V_211 , 0x1E , 0x01 ) ;
F_15 ( V_3 -> V_211 , 0x30 , ~ 0x20 ) ;
F_15 ( V_3 -> V_211 , 0x35 , ~ 0x80 ) ;
if ( V_199 <= 0x13 ) {
V_294 = ( unsigned char ) F_10 ( V_295 ) ;
if ( V_294 & 0x40 )
F_22 ( V_3 -> V_211 , 0x30 , 0x20 ) ;
if ( V_294 & 0x80 )
F_22 ( V_3 -> V_211 , 0x35 , 0x80 ) ;
} else {
V_292 = V_3 -> V_13 [ V_236 ] . V_273 ;
if ( V_292 & 0x4000 )
F_22 ( V_3 -> V_211 , 0x30 , 0x20 ) ;
if ( V_292 & 0x8000 )
F_22 ( V_3 -> V_211 , 0x35 , 0x80 ) ;
}
}
static void F_25 ( struct V_2 * V_3 ,
unsigned short V_236 ,
unsigned short V_199 )
{
unsigned short V_292 , V_293 , V_294 ;
unsigned short V_295 ;
V_295 = V_3 -> V_296 ;
F_4 ( V_3 -> V_223 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_223 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_223 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_223 , 0x47 , 0x00 ) ;
V_293 = F_8 ( V_3 -> V_223 , 0x37 ) ;
if ( ( V_293 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_223 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_223 , 0x47 , 0x13 ) ;
}
if ( ( ( * V_3 -> V_189 ) & 0xC0 ) == 0xC0 ) {
F_4 ( V_3 -> V_223 , 0x2E , * V_3 -> V_191 ) ;
F_4 ( V_3 -> V_223 , 0x2F , * V_3 -> V_193 ) ;
F_4 ( V_3 -> V_223 , 0x46 , * V_3 -> V_195 ) ;
F_4 ( V_3 -> V_223 , 0x47 , * V_3 -> V_197 ) ;
}
F_26 ( V_3 ) ;
F_22 ( V_3 -> V_211 , 0x1E , 0x01 ) ;
F_15 ( V_3 -> V_211 , 0x30 , ~ 0x20 ) ;
F_15 ( V_3 -> V_211 , 0x35 , ~ 0x80 ) ;
if ( V_199 <= 0x13 ) {
V_294 = ( unsigned char ) F_10 ( V_295 ) ;
if ( V_294 & 0x40 )
F_22 ( V_3 -> V_211 , 0x30 , 0x20 ) ;
if ( V_294 & 0x80 )
F_22 ( V_3 -> V_211 , 0x35 , 0x80 ) ;
} else {
V_292 = V_3 -> V_13 [ V_236 ] . V_273 ;
if ( V_292 & 0x4000 )
F_22 ( V_3 -> V_211 , 0x30 , 0x20 ) ;
if ( V_292 & 0x8000 )
F_22 ( V_3 -> V_211 , 0x35 , 0x80 ) ;
}
}
static void F_27 ( unsigned short V_199 ,
struct V_2 * V_3 ,
unsigned short V_236 )
{
int V_207 , V_201 = - 1 ;
F_15 ( V_3 -> V_223 , 0x11 , 0x7F ) ;
if ( V_199 <= 0x13 ) {
for ( V_207 = 0 ; V_207 < 12 ; V_207 ++ ) {
if ( V_199 == V_3 -> V_144 [ V_207 ] . V_242 )
V_201 = V_207 ;
}
} else {
if ( V_199 == 0x2E &&
( V_3 -> V_13 [ V_236 ] . V_282 ==
V_297 ) )
V_201 = 12 ;
else if ( V_199 == 0x2E &&
( V_3 -> V_13 [ V_236 ] .
V_282 == V_298 ) )
V_201 = 13 ;
else if ( V_199 == 0x2F )
V_201 = 14 ;
else if ( V_199 == 0x50 )
V_201 = 15 ;
else if ( V_199 == 0x59 )
V_201 = 16 ;
}
if ( V_201 != - 1 ) {
F_4 ( V_3 -> V_223 , 0x02 ,
V_3 -> V_144 [ V_201 ] . V_299 ) ;
F_4 ( V_3 -> V_223 , 0x03 ,
V_3 -> V_144 [ V_201 ] . V_300 ) ;
F_4 ( V_3 -> V_223 , 0x15 ,
V_3 -> V_144 [ V_201 ] . V_301 ) ;
F_4 ( V_3 -> V_223 , 0x16 ,
V_3 -> V_144 [ V_201 ] . V_302 ) ;
}
}
static void F_28 ( struct V_220 * V_221 ,
unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_303 , V_237 , V_238 , V_304 , V_275 , V_208 ;
unsigned char V_276 ;
V_303 = F_29 ( V_199 , V_200 , V_3 ) ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_237 = V_3 -> V_33 [ V_303 ] . V_305 ;
V_238 = V_3 -> V_33 [ V_303 ] . V_306 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_237 = V_3 -> V_36 [ V_303 ] . V_305 ;
V_238 = V_3 -> V_36 [ V_303 ] . V_306 ;
}
if ( V_208 & V_307 )
V_237 = V_237 >> 1 ;
if ( V_199 > 0x13 ) {
if ( V_208 & V_307 )
V_237 = V_237 << 1 ;
V_275 = V_3 -> V_13 [ V_236 ] . V_273 ;
if ( V_275 & V_308 )
V_238 = V_238 >> 1 ;
if ( V_208 & V_281 )
V_238 = V_238 << 1 ;
}
V_304 = 8 ;
V_237 /= V_304 ;
V_237 -= 1 ;
V_238 -= 1 ;
V_304 = V_237 ;
V_275 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x11 ) ;
V_276 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x11 ) ;
V_276 &= 0x7F ;
F_4 ( V_3 -> V_223 , 0x11 , V_276 ) ;
F_4 ( V_3 -> V_223 , 0x01 , ( unsigned short ) ( V_304 & 0xff ) ) ;
F_14 ( V_3 -> V_223 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_304 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_223 , 0x12 , ( unsigned short ) ( V_238 & 0xff ) ) ;
V_237 = 0 ;
V_238 = V_238 >> 8 ;
if ( V_238 & 0x01 )
V_237 |= 0x02 ;
if ( V_238 & 0x02 )
V_237 |= 0x40 ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x42 , V_237 ) ;
V_276 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x07 ) ;
V_276 &= 0xFF ;
V_237 = 0 ;
if ( V_238 & 0x04 )
V_237 |= 0x02 ;
F_14 ( V_3 -> V_223 , 0x0a , ~ 0x02 , V_237 ) ;
F_4 ( V_3 -> V_223 , 0x11 , V_275 ) ;
}
unsigned short F_29 ( unsigned short V_199 ,
unsigned short V_200 , struct V_2 * V_3 )
{
unsigned short V_303 ;
if ( V_199 <= 0x13 )
V_303 = V_3 -> V_4 [ V_200 ] . V_309 ;
else
V_303 = V_3 -> V_10 [ V_200 ] . V_241 ;
return V_303 ;
}
static void F_30 ( unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_275 , V_310 , V_311 , V_312 , V_207 , V_313 ;
V_275 = V_3 -> V_10 [ V_200 ] . V_314 ;
V_275 = V_275 >> 8 ;
V_275 = V_3 -> V_31 [ V_275 ] ;
V_312 = V_3 -> V_13 [ V_236 ] . V_273 ;
V_312 &= V_308 ;
if ( V_312 )
V_275 = V_275 << 1 ;
V_312 = V_3 -> V_203 - V_315 ;
switch ( V_312 ) {
case 0 :
V_312 = 1 ;
break;
case 1 :
V_312 = 2 ;
break;
case 2 :
V_312 = 4 ;
break;
case 3 :
V_312 = 4 ;
break;
case 4 :
V_312 = 6 ;
break;
case 5 :
V_312 = 8 ;
break;
default:
break;
}
if ( ( V_199 >= 0x26 ) && ( V_199 <= 0x28 ) )
V_275 = V_275 * V_312 + V_312 / 2 ;
else
V_275 *= V_312 ;
V_313 = V_275 ;
V_312 = V_275 ;
V_275 = V_275 >> 8 ;
V_275 &= 0x0F ;
V_207 = F_8 ( V_3 -> V_211 , 0x0E ) ;
V_207 &= 0xF0 ;
V_207 |= V_275 ;
F_4 ( V_3 -> V_211 , 0x0E , V_207 ) ;
V_275 = ( unsigned char ) V_312 ;
V_275 &= 0xFF ;
F_4 ( V_3 -> V_223 , 0x13 , V_275 ) ;
V_312 = V_3 -> V_13 [ V_236 ] . V_273 ;
V_312 &= V_308 ;
if ( V_312 )
V_313 >>= 1 ;
V_313 = V_313 << 5 ;
V_310 = ( V_313 & 0xff00 ) >> 8 ;
V_311 = V_313 & 0x00ff ;
if ( V_311 == 0 )
V_310 += 1 ;
else
V_310 += 2 ;
if ( V_221 -> V_280 >= V_171 )
if ( ( V_199 == 0x4A ) | ( V_199 == 0x49 ) )
V_310 -= 1 ;
F_4 ( V_3 -> V_211 , 0x10 , V_310 ) ;
}
static unsigned short F_31 ( unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_238 ;
unsigned short V_316 [ 4 ] = { V_317 + 2 ,
V_317 + 2 ,
V_317 + 2 ,
V_317 + 2 } ;
unsigned short V_318 [ 4 ] = { V_319 + 5 ,
V_319 + 5 ,
V_319 + 5 ,
V_319 + 5 } ;
unsigned short V_320 [ 4 ] = { V_321 , V_321 , V_321 , V_321 } ;
unsigned short V_322 [ 4 ] = { V_317 + 2 ,
V_317 + 2 ,
V_317 + 2 ,
V_317 + 2 } ;
unsigned short V_323 [ 4 ] = { V_317 + 2 ,
V_317 + 2 ,
V_317 + 2 ,
V_317 + 2 } ;
unsigned short V_324 , V_325 ;
unsigned short V_208 , V_239 ;
unsigned char * V_326 = NULL ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_239 = V_3 -> V_4 [ V_200 ] . V_309 ;
V_324 = V_3 -> V_4 [ V_200 ] . V_327 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
V_324 = V_3 -> V_13 [ V_236 ] .
V_328 ;
}
if ( V_3 -> V_243 == 0 ) {
V_324 = V_324 >> 6 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
if ( V_3 -> V_45 != V_272 )
V_325 = V_318 [ V_324 ] ;
else
V_325 = V_316 [ V_324 ] ;
} else {
if ( V_3 -> V_48 & V_214 ) {
if ( V_3 -> V_48 & V_252 ) {
if ( V_3 -> V_257 & V_329 ) {
V_325 = V_330 ;
V_325 += 25 ;
} else {
V_325 = V_331 ;
V_325 += 25 ;
}
if ( V_3 -> V_257 & V_258 ) {
if ( V_208 & V_227 ) {
V_325 =
V_332 ;
V_325 += 25 ;
} else {
V_325 =
V_333 ;
V_325 += 25 ;
}
}
if ( V_3 -> V_155 & V_156 ) {
if ( ! ( V_3 -> V_253 ==
V_254 ) ) {
V_325 =
V_334 ;
if ( ! ( V_3 -> V_253
==
V_335 ) ) {
V_325 =
V_336 ;
if ( ! ( V_3 -> V_253
== V_337 ) ) {
V_325
= V_338 ;
if ( ! ( V_3 -> V_257
& V_329 ) )
V_325
= V_339 ;
}
}
}
}
} else {
if ( V_3 -> V_48 & V_214 ) {
if ( V_3 -> V_257 &
V_329 ) {
V_325 = V_340 ;
V_325 += 25 ;
} else {
V_325 = V_341 ;
V_325 += 25 ;
}
}
}
} else {
V_325 = ( unsigned char ) F_10 (
( V_3 -> V_342 + 0x02 ) ) ;
V_325 = ( ( V_325 >> 2 ) & 0x03 ) ;
if ( V_199 > 0x13 ) {
V_325 =
V_3 -> V_13 [
V_236 ] .
V_343 ;
V_325 &= V_283 ;
}
}
}
} else {
if ( V_199 <= 0x13 )
V_325 = V_324 ;
else
V_325 = V_324 ;
if ( V_3 -> V_270 == 1 ) {
if ( ! ( V_3 -> V_48 & V_215 ) ) {
V_325 &= 0x1f ;
V_238 = 0 ;
if ( V_3 -> V_48 & V_267 )
V_238 += 2 ;
if ( V_3 -> V_48 & V_344 )
V_238 += 1 ;
switch ( V_238 ) {
case 0 :
V_326 = V_3 -> V_147 ;
break;
case 1 :
V_326 = V_3 -> V_149 ;
break;
case 2 :
V_326 = V_3 -> V_151 ;
break;
case 3 :
V_326 = V_3 -> V_153 ;
break;
default:
break;
}
V_325 = V_326 [ V_325 ] ;
}
} else {
V_325 = V_325 >> 6 ;
if ( ( V_3 -> V_45 == V_345 ) ||
( V_3 -> V_45 == V_346 ) )
V_325 = V_320 [ V_325 ] ;
else if ( ( V_3 -> V_45 == V_272 ) ||
( V_3 -> V_45 == V_347 ) )
V_325 = V_322 [ V_325 ] ;
else
V_325 = V_323 [ V_325 ] ;
}
}
return V_325 ;
}
static void F_32 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_220 * V_221 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned char V_201 , V_276 ;
unsigned short V_348 ;
if ( V_3 -> V_243 == 1 ) {
V_201 = V_3 -> V_13 [ V_236 ] . V_343 ;
V_276 = F_8 ( V_3 -> V_211 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_211 , 0x31 , V_276 ) ;
F_4 ( V_3 -> V_211 , 0x2B ,
V_3 -> V_25 [ V_201 ] . V_234 ) ;
F_4 ( V_3 -> V_211 , 0x2C ,
V_3 -> V_25 [ V_201 ] . V_235 ) ;
F_4 ( V_3 -> V_211 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) && ( V_3 -> V_48
& V_213 ) ) {
V_348 = F_31 ( V_199 , V_200 ,
V_236 , V_221 ,
V_3 ) ;
V_276 = F_8 ( V_3 -> V_211 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_211 , 0x31 , V_276 ) ;
V_276 = V_3 -> V_28 [ V_348 ] . V_349 ;
F_4 ( V_3 -> V_211 , 0x2B , V_276 ) ;
V_276 = V_3 -> V_28 [ V_348 ] . V_350 ;
F_4 ( V_3 -> V_211 , 0x2C , V_276 ) ;
F_4 ( V_3 -> V_211 , 0x2D , 0x01 ) ;
} else {
V_201 = V_3 -> V_13 [ V_236 ] . V_343 ;
V_276 = F_8 ( V_3 -> V_211 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_211 , 0x31 , V_276 ) ;
F_4 ( V_3 -> V_211 , 0x2B ,
V_3 -> V_25 [ V_201 ] . V_234 ) ;
F_4 ( V_3 -> V_211 , 0x2C ,
V_3 -> V_25 [ V_201 ] . V_235 ) ;
F_4 ( V_3 -> V_211 , 0x2D , 0x01 ) ;
}
if ( V_221 -> V_280 >= V_171 ) {
if ( V_3 -> V_10 [ V_200 ] . V_210 &
V_307 ) {
V_276 = F_8 ( V_3 -> V_211 , 0x2B ) ;
F_4 ( V_3 -> V_211 , 0x2B , V_276 ) ;
V_276 = F_8 ( V_3 -> V_211 , 0x2C ) ;
V_201 = V_276 ;
V_201 &= 0xE0 ;
V_276 &= 0x1F ;
V_276 = V_276 << 1 ;
V_276 += 1 ;
V_276 |= V_201 ;
F_4 ( V_3 -> V_211 , 0x2C , V_276 ) ;
}
}
}
static void F_33 ( unsigned short V_199 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_276 ;
V_276 = F_8 ( V_3 -> V_211 , 0x3D ) ;
V_276 &= 0xfe ;
F_4 ( V_3 -> V_211 , 0x3D , V_276 ) ;
if ( V_199 > 0x13 ) {
F_4 ( V_3 -> V_211 , 0x08 , 0x34 ) ;
V_276 = F_8 ( V_3 -> V_211 , 0x09 ) ;
V_276 &= 0xC0 ;
F_4 ( V_3 -> V_211 , 0x09 , V_276 | 0x30 ) ;
V_276 = F_8 ( V_3 -> V_211 , 0x3D ) ;
V_276 |= 0x01 ;
F_4 ( V_3 -> V_211 , 0x3D , V_276 ) ;
} else {
if ( V_221 -> V_280 == V_162 ) {
F_4 ( V_3 -> V_211 , 0x08 , 0x0E ) ;
V_276 = F_8 ( V_3 -> V_211 , 0x09 ) ;
V_276 &= 0xC0 ;
F_4 ( V_3 -> V_211 , 0x09 , V_276 | 0x20 ) ;
} else {
F_4 ( V_3 -> V_211 , 0x08 , 0xAE ) ;
V_276 = F_8 ( V_3 -> V_211 , 0x09 ) ;
V_276 &= 0xF0 ;
F_4 ( V_3 -> V_211 , 0x09 , V_276 ) ;
}
}
if ( V_221 -> V_280 == V_161 )
F_34 ( V_3 ) ;
}
static void F_35 ( struct V_220 * V_221 ,
unsigned short V_199 , unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_276 , V_351 = 0 ;
short V_352 ;
unsigned char V_201 ;
if ( V_199 <= 0x13 )
V_352 = 0 ;
else {
V_201 = V_3 -> V_13 [ V_236 ] . V_343 ;
V_201 &= V_283 ;
V_352 = V_3 -> V_25 [ V_201 ] . CLOCK ;
}
V_276 = F_8 ( V_3 -> V_211 , 0x32 ) ;
V_276 &= 0xf3 ;
if ( V_352 >= 200 )
V_276 |= 0x0c ;
if ( V_221 -> V_280 >= V_171 )
V_276 &= ~ 0x04 ;
F_4 ( V_3 -> V_211 , 0x32 , V_276 ) ;
if ( V_221 -> V_280 < V_171 ) {
V_276 = F_8 ( V_3 -> V_211 , 0x1F ) ;
V_276 &= 0xE7 ;
if ( V_352 < 200 )
V_276 |= 0x10 ;
F_4 ( V_3 -> V_211 , 0x1F , V_276 ) ;
}
V_351 = 0x00 ;
F_14 ( V_3 -> V_211 , 0x07 , 0xFC , V_351 ) ;
if ( V_221 -> V_280 >= V_162 )
F_14 ( V_3 -> V_211 , 0x40 , 0xFC , V_351 & 0x03 ) ;
}
static void F_36 ( struct V_220 * V_221 ,
unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_276 , V_351 , V_353 , V_240 = 0 , V_208 , V_303 ,
V_354 ;
if ( V_199 > 0x13 ) {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_240 = V_3 -> V_13 [ V_236 ] .
V_273 ;
} else
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
if ( F_8 ( V_3 -> V_223 , 0x31 ) & 0x01 )
F_14 ( V_3 -> V_211 , 0x1F , 0x3F , 0x00 ) ;
if ( V_199 > 0x13 )
V_276 = V_240 ;
else
V_276 = 0 ;
V_351 = 0 ;
if ( V_199 > 0x13 ) {
if ( V_3 -> V_203 > 0x02 ) {
V_351 |= 0x02 ;
V_353 = V_3 -> V_203 - V_233 ;
V_353 = V_353 << 2 ;
V_351 |= V_353 ;
}
}
V_276 &= V_308 ;
if ( V_276 )
V_351 |= 0x20 ;
F_14 ( V_3 -> V_211 , 0x06 , ~ 0x3F , V_351 ) ;
V_303 = F_29 ( V_199 , V_200 , V_3 ) ;
if ( V_199 <= 0x13 )
V_354 = V_3 -> V_33 [ V_303 ] . V_305 ;
else
V_354 = V_3 -> V_36 [ V_303 ] . V_305 ;
V_276 = 0x0000 ;
if ( V_240 & V_308 ) {
if ( V_354 == 1024 )
V_276 = 0x0035 ;
else if ( V_354 == 1280 )
V_276 = 0x0048 ;
}
V_351 = V_276 & 0x00FF ;
F_14 ( V_3 -> V_223 , 0x19 , 0xFF , V_351 ) ;
V_351 = ( V_276 & 0xFF00 ) >> 8 ;
F_14 ( V_3 -> V_223 , 0x19 , 0xFC , V_351 ) ;
if ( V_208 & V_307 )
F_14 ( V_3 -> V_211 , 0x01 , 0xF7 , 0x08 ) ;
V_351 = 0 ;
if ( V_208 & V_355 )
V_351 |= 0x08 ;
if ( V_199 > 0x13 ) {
if ( V_3 -> V_203 == V_315 )
V_351 |= 0x40 ;
}
F_14 ( V_3 -> V_211 , 0x0F , ~ 0x48 , V_351 ) ;
V_276 = 0x60 ;
if ( V_3 -> V_203 != V_356 ) {
V_276 = V_276 ^ 0x60 ;
if ( V_3 -> V_203 != V_315 )
V_276 = V_276 ^ 0xA0 ;
}
F_14 ( V_3 -> V_211 , 0x21 , 0x1F , V_276 ) ;
F_35 ( V_221 , V_199 , V_236 ,
V_3 ) ;
V_276 = F_8 ( V_3 -> V_223 , 0x31 ) ;
if ( V_221 -> V_280 == V_162 ) {
if ( V_276 & 0x40 )
V_276 = 0x2c ;
else
V_276 = 0x6c ;
F_4 ( V_3 -> V_223 , 0x52 , V_276 ) ;
F_22 ( V_3 -> V_223 , 0x51 , 0x10 ) ;
} else if ( V_221 -> V_280 >= V_171 ) {
if ( V_276 & 0x40 )
V_276 = 0x33 ;
else
V_276 = 0x73 ;
F_4 ( V_3 -> V_223 , 0x52 , V_276 ) ;
F_4 ( V_3 -> V_223 , 0x51 , 0x02 ) ;
} else {
if ( V_276 & 0x40 )
V_276 = 0x2c ;
else
V_276 = 0x6c ;
F_4 ( V_3 -> V_223 , 0x52 , V_276 ) ;
}
}
static void F_37 ( unsigned short V_357 ,
unsigned short V_310 ,
unsigned short V_311 ,
unsigned short V_358 ,
struct V_2 * V_3 )
{
unsigned short V_275 , V_359 , V_360 ;
V_359 = V_310 ;
V_360 = V_311 ;
if ( V_357 != 0 ) {
V_275 = V_359 ;
V_359 = V_358 ;
V_358 = V_275 ;
if ( V_357 == 1 ) {
V_275 = V_360 ;
V_360 = V_358 ;
V_358 = V_275 ;
} else {
V_275 = V_360 ;
V_360 = V_359 ;
V_359 = V_275 ;
}
}
F_6 ( ( unsigned short ) V_358 , V_3 -> V_361 ) ;
F_6 ( ( unsigned short ) V_359 , V_3 -> V_361 ) ;
F_6 ( ( unsigned short ) V_360 , V_3 -> V_361 ) ;
}
static void F_38 ( unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_276 , V_351 , time , V_207 , V_279 , V_362 , V_363 , V_364 , V_365 , V_366 , V_367 , V_368 , V_357 , V_311 ,
V_310 , V_358 , * V_369 = NULL ;
if ( V_199 <= 0x13 )
V_276 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_276 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_276 &= V_370 ;
time = 64 ;
if ( V_276 == 0x00 )
V_369 = V_371 ;
else if ( V_276 == 0x08 )
V_369 = V_372 ;
else if ( V_276 == 0x10 )
V_369 = V_373 ;
else if ( V_276 == 0x18 ) {
time = 256 ;
V_369 = V_374 ;
}
if ( time == 256 )
V_279 = 16 ;
else
V_279 = time ;
F_6 ( 0xFF , V_3 -> V_375 ) ;
F_6 ( 0x00 , V_3 -> V_376 ) ;
for ( V_207 = 0 ; V_207 < V_279 ; V_207 ++ ) {
V_276 = V_369 [ V_207 ] ;
for ( V_362 = 0 ; V_362 < 3 ; V_362 ++ ) {
V_351 = 0 ;
if ( V_276 & 0x01 )
V_351 = 0x2A ;
if ( V_276 & 0x02 )
V_351 += 0x15 ;
F_6 ( V_351 , V_3 -> V_361 ) ;
V_276 = V_276 >> 2 ;
}
}
if ( time == 256 ) {
for ( V_207 = 16 ; V_207 < 32 ; V_207 ++ ) {
V_276 = V_369 [ V_207 ] ;
for ( V_362 = 0 ; V_362 < 3 ; V_362 ++ )
F_6 ( V_276 , V_3 -> V_361 ) ;
}
V_366 = 32 ;
for ( V_363 = 0 ; V_363 < 9 ; V_363 ++ ) {
V_367 = V_366 ;
V_368 = V_366 + 0x04 ;
V_357 = 0 ;
for ( V_364 = 0 ; V_364 < 3 ; V_364 ++ ) {
for ( V_365 = 0 ; V_365 < 5 ; V_365 ++ ) {
V_358 = V_369 [ V_366 ] ;
V_310 = V_369 [ V_367 ] ;
V_311 = V_369 [ V_368 ] ;
V_366 ++ ;
F_37 ( V_357 , V_310 , V_311 , V_358 , V_3 ) ;
}
V_366 -= 2 ;
for ( V_365 = 0 ; V_365 < 3 ; V_365 ++ ) {
V_358 = V_369 [ V_368 ] ;
V_310 = V_369 [ V_367 ] ;
V_311 = V_369 [ V_366 ] ;
V_366 -- ;
F_37 ( V_357 , V_310 , V_311 , V_358 , V_3 ) ;
}
V_357 ++ ;
}
V_366 += 5 ;
}
}
}
static void F_39 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_303 , V_354 , V_377 , V_208 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_309 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_241 ;
if ( V_199 <= 0x13 )
V_303 = V_3 -> V_4 [ V_200 ] . V_309 ;
else
V_303 = V_3 -> V_10 [ V_200 ] . V_241 ;
if ( V_199 <= 0x13 ) {
V_354 = V_3 -> V_33 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_33 [ V_303 ] . V_306 ;
} else {
V_354 = V_3 -> V_36 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_36 [ V_303 ] . V_306 ;
}
if ( V_199 > 0x13 ) {
if ( V_208 & V_307 )
V_354 = V_354 << 1 ;
if ( V_208 & V_281 )
V_377 = V_377 << 1 ;
}
if ( V_354 == 720 )
V_354 = 640 ;
V_3 -> V_378 = V_354 ;
V_3 -> V_379 = V_354 ;
V_3 -> V_380 = V_377 ;
V_3 -> V_381 = V_377 ;
}
static void * F_40 ( unsigned short V_382 , unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_207 , V_383 , V_304 , V_238 , V_384 , V_208 , V_369 ;
struct V_385 * V_386 = NULL ;
V_238 = V_382 ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_384 = V_3 -> V_4 [ V_200 ] . V_327 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_384 = V_3 -> V_13 [ V_236 ] . V_328 ;
}
V_384 = V_384 & 0x0f ;
if ( V_238 <= 1 ) {
if ( V_199 <= 0x13 ) {
V_384 = V_3 -> V_4 [ V_200 ] . V_327 ;
} else {
V_384 = V_3 -> V_13 [ V_236 ] .
V_328 ;
}
if ( V_3 -> V_48 & V_213 ) {
if ( V_199 <= 0x13 )
V_384 = V_3 -> V_4 [ V_200 ] .
V_387 ;
else
V_384 = V_3 -> V_13 [
V_236 ] .
V_388 ;
}
if ( V_238 & 0x01 )
V_384 = ( V_384 >> 4 ) ;
V_384 = ( V_384 & 0x0f ) ;
}
V_304 = V_389 [ V_238 ] ;
if ( V_3 -> V_47 & V_390 ) {
if ( ( V_238 == 5 ) || ( V_238 ) == 7 )
V_304 = V_391 ;
else if ( ( V_238 == 3 ) || ( V_238 == 8 ) )
V_304 = V_392 ;
}
switch ( V_238 ) {
case 0 :
V_386 = V_393 ;
break;
case 1 :
V_386 = V_394 ;
break;
case 2 :
V_386 = V_395 ;
break;
case 3 :
V_386 = V_396 ;
break;
case 4 :
V_386 = V_397 ;
break;
case 5 :
V_386 = V_398 ;
break;
case 6 :
V_386 = V_399 ;
break;
case 7 :
case 8 :
case 9 :
V_386 = NULL ;
break;
default:
break;
}
if ( V_386 == NULL )
return NULL ;
V_369 = V_238 ;
V_207 = 0 ;
while ( V_386 [ V_207 ] . V_400 != 0xff ) {
V_383 = V_3 -> V_45 ;
if ( V_238 & 0x0080 ) {
V_238 &= ( ~ 0x0080 ) ;
V_383 = V_3 -> V_46 ;
}
if ( V_3 -> V_47 & V_390 )
V_383 &= ( ~ V_401 ) ;
if ( V_386 [ V_207 ] . V_400 == V_383 ) {
V_238 = V_386 [ V_207 ] . V_402 ;
V_383 = V_3 -> V_47 ;
if ( V_199 <= 0x13 )
V_383 |= V_403 ;
if ( V_208 & V_307 )
V_383 |= V_404 ;
V_238 &= V_383 ;
if ( V_238 == V_386 [ V_207 ] . V_405 )
break;
}
V_207 ++ ;
}
if ( V_369 == 0 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_407 [ V_384 ] ;
break;
case 1 :
return & V_408 [ V_384 ] ;
break;
case 2 :
return & V_409 [ V_384 ] ;
break;
case 3 :
return & V_410 [ V_384 ] ;
break;
case 4 :
return & V_411 [ V_384 ] ;
break;
case 5 :
return & V_412 [ V_384 ] ;
break;
case 6 :
return & V_413 [ V_384 ] ;
break;
case 7 :
return & V_414 [ V_384 ] ;
break;
case 8 :
return & V_415 [ V_384 ] ;
break;
case 9 :
return & V_416 [ V_384 ] ;
break;
case 10 :
return & V_417 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 1 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_418 [ V_384 ] ;
break;
case 1 :
return & V_419 [ V_384 ] ;
break;
case 2 :
return & V_420 [ V_384 ] ;
break;
case 3 :
return & V_421 [ V_384 ] ;
break;
case 4 :
return & V_422 [ V_384 ] ;
break;
case 5 :
return & V_423 [ V_384 ] ;
break;
case 6 :
return & V_424 [ V_384 ] ;
break;
case 7 :
return & V_425 [ V_384 ] ;
break;
case 8 :
return & V_426 [ V_384 ] ;
break;
case 9 :
return & V_427 [ V_384 ] ;
break;
case 10 :
return & V_428 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 2 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_429 [ V_384 ] ;
break;
case 1 :
return & V_430 [ V_384 ] ;
break;
case 2 :
return & V_431 [ V_384 ] ;
break;
case 3 :
return & V_432 [ V_384 ] ;
break;
case 4 :
return & V_433 [ V_384 ] ;
break;
case 5 :
return & V_434 [ V_384 ] ;
break;
case 6 :
return & V_435 [ V_384 ] ;
break;
case 7 :
return & V_436 [ V_384 ] ;
break;
case 8 :
return & V_437 [ V_384 ] ;
break;
case 9 :
return & V_438 [ V_384 ] ;
break;
case 10 :
return & V_439 [ V_384 ] ;
break;
case 11 :
return & V_440 [ V_384 ] ;
break;
case 12 :
return & V_441 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 3 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_442 [ V_384 ] ;
break;
case 1 :
return & V_443 [ V_384 ] ;
break;
case 2 :
return & V_444 [ V_384 ] ;
break;
case 3 :
return & V_445 [ V_384 ] ;
break;
case 4 :
return & V_446 [ V_384 ] ;
break;
case 5 :
return & V_447 [ V_384 ] ;
break;
case 6 :
return & V_448 [ V_384 ] ;
break;
case 7 :
return & V_449 [ V_384 ] ;
break;
case 8 :
return & V_450 [ V_384 ] ;
break;
case 9 :
return & V_451 [ V_384 ] ;
break;
case 10 :
return & V_452 [ V_384 ] ;
break;
case 11 :
return & V_453 [ V_384 ] ;
break;
case 12 :
return & V_454 [ V_384 ] ;
break;
case 13 :
return & V_455 [ V_384 ] ;
break;
case 14 :
return & V_456 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 4 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_457 [ V_384 ] ;
break;
case 1 :
return & V_458 [ V_384 ] ;
break;
case 2 :
return & V_459 [ V_384 ] ;
break;
case 3 :
return & V_460 [ V_384 ] ;
break;
case 4 :
return & V_461 [ V_384 ] ;
break;
case 5 :
return & V_462 [ V_384 ] ;
break;
case 6 :
return & V_463 [ V_384 ] ;
break;
case 7 :
return & V_464 [ V_384 ] ;
break;
case 8 :
return & V_465 [ V_384 ] ;
break;
case 9 :
return & V_466 [ V_384 ] ;
break;
case 10 :
return & V_467 [ V_384 ] ;
break;
case 11 :
return & V_468 [ V_384 ] ;
break;
case 12 :
return & V_469 [ V_384 ] ;
break;
case 13 :
return & V_469 [ V_384 ] ;
break;
case 14 :
return & V_470 [ V_384 ] ;
break;
case 15 :
return & V_471 [ V_384 ] ;
break;
case 16 :
return & V_472 [ V_384 ] ;
break;
case 17 :
return & V_473 [ V_384 ] ;
break;
case 18 :
return & V_474 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 5 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_475 [ V_384 ] ;
break;
case 1 :
return & V_476 [ V_384 ] ;
break;
case 2 :
return & V_477 [ V_384 ] ;
break;
case 3 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_478 [ V_384 ] ;
else
return & V_479 [ V_384 ] ;
break;
case 4 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_480 [ V_384 ] ;
else
return & V_481 [ V_384 ] ;
break;
case 5 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_482 [ V_384 ] ;
else
return & V_483 [ V_384 ] ;
break;
case 6 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_484 [ V_384 ] ;
else
return & V_485 [ V_384 ] ;
break;
case 7 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_486 [ V_384 ] ;
else
return & V_487 [ V_384 ] ;
break;
case 8 :
return & V_488 [ V_384 ] ;
break;
case 9 :
return & V_489 [ V_384 ] ;
break;
case 10 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_490 [ V_384 ] ;
else
return & V_491 [ V_384 ] ;
break;
case 11 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_492 [ V_384 ] ;
else
return & V_493 [ V_384 ] ;
break;
case 12 :
return & V_494 [ V_384 ] ;
break;
case 13 :
return & V_495 [ V_384 ] ;
break;
case 14 :
return & V_496 [ V_384 ] ;
break;
case 15 :
return & V_497 [ V_384 ] ;
break;
case 16 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_498 [ V_384 ] ;
else
return & V_499 [ V_384 ] ;
break;
case 17 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_500 [ V_384 ] ;
else
return & V_501 [ V_384 ] ;
break;
case 18 :
if ( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) )
return & V_502 [ V_384 ] ;
else
return & V_503 [ V_384 ] ;
break;
case 19 :
return & V_504 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 6 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_505 [ V_384 ] ;
break;
case 1 :
return & V_506 [ V_384 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void * F_41 ( unsigned short V_382 , unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_207 , V_383 , V_238 , V_384 , V_208 , V_369 ;
struct V_507 * V_386 = NULL ;
V_238 = V_382 ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_384 = V_3 -> V_4 [ V_200 ] . V_327 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_384 = V_3 -> V_13 [ V_236 ] . V_328 ;
}
V_384 = V_384 & 0x3f ;
V_369 = V_238 ;
switch ( V_238 ) {
case 0 :
V_386 = NULL ;
if ( V_3 -> V_508 == 1 )
V_386 = V_509 ;
break;
case 1 :
V_386 = NULL ;
if ( V_3 -> V_508 == 1 )
V_386 = V_509 ;
break;
case 2 :
V_386 = V_510 ;
break;
case 3 :
V_386 = NULL ;
break;
case 4 :
V_386 = V_511 ;
break;
case 5 :
V_386 = NULL ;
break;
case 6 :
V_386 = V_512 ;
break;
default:
break;
}
if ( V_386 == NULL )
return NULL ;
V_383 = V_3 -> V_49 ;
if ( V_3 -> V_48 & V_216 )
V_383 = V_383 | V_513 ;
if ( V_208 & V_307 )
V_383 = V_383 | V_514 ;
V_207 = 0 ;
while ( V_386 [ V_207 ] . V_402 != 0xffff ) {
if ( ( V_383 & V_386 [ V_207 ] . V_402 ) == V_386 [ V_207 ] . V_405 )
break;
V_207 ++ ;
}
if ( V_369 == 0x00 ) {
} else if ( V_369 == 0x01 ) {
} else if ( V_369 == 0x04 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_515 [ V_384 ] ;
break;
case 1 :
return & V_516 [ V_384 ] ;
break;
case 2 :
return & V_517 [ V_384 ] ;
break;
case 3 :
return & V_518 [ V_384 ] ;
break;
case 4 :
return & V_519 [ V_384 ] ;
break;
case 5 :
return & V_520 [ V_384 ] ;
break;
case 6 :
return & V_521 [ V_384 ] ;
break;
case 7 :
return & V_522 [ V_384 ] ;
break;
case 8 :
return & V_523 [ V_384 ] ;
break;
case 9 :
return & V_524 [ V_384 ] ;
break;
case 10 :
return & V_525 [ V_384 ] ;
break;
case 11 :
return & V_526 [ V_384 ] ;
break;
case 12 :
return & V_516 [ V_384 ] ;
break;
case 13 :
return & V_527 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 0x02 ) {
switch ( V_386 [ V_207 ] . V_406 ) {
case 0 :
return & V_528 [ V_384 ] ;
break;
case 1 :
return & V_529 [ V_384 ] ;
break;
case 2 :
return & V_530 [ V_384 ] ;
break;
case 3 :
return & V_531 [ V_384 ] ;
break;
default:
break;
}
} else if ( V_369 == 0x06 ) {
}
return NULL ;
}
static void F_42 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_238 ;
struct V_532 * V_533 = NULL ;
struct V_534 * V_535 = NULL ;
V_238 = 2 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
V_533 = (struct V_532 * ) F_40 ( V_238 ,
V_199 , V_200 , V_236 ,
V_3 ) ;
V_3 -> V_536 = V_533 -> V_536 ;
V_3 -> V_537 = V_533 -> V_537 ;
V_3 -> V_538 = V_533 -> V_539 ;
V_3 -> V_540 = V_533 -> V_541 ;
}
if ( V_3 -> V_542 == 1 ) {
if ( V_3 -> V_48 & V_214 ) {
V_535 = (struct V_534 * ) F_41 (
V_238 , V_199 , V_200 ,
V_236 , V_3 ) ;
V_3 -> V_536 = V_535 -> V_536 ;
V_3 -> V_537 = V_535 -> V_537 ;
V_3 -> V_538 = V_535 -> V_539 ;
V_3 -> V_540 = V_535 -> V_541 ;
}
}
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
if ( ! ( V_3 -> V_47 & ( V_543
| V_390 ) ) ) {
if ( ( V_3 -> V_45 == V_272 ) ||
( V_3 -> V_45 == V_347 ) ) {
V_3 -> V_379 = 1024 ;
V_3 -> V_381 = 768 ;
} else if ( ( V_3 -> V_45 == V_249 ) ||
( V_3 -> V_45 == V_544 ) ) {
V_3 -> V_379 = 1280 ;
V_3 -> V_381 = 1024 ;
} else if ( V_3 -> V_45 == V_545 ) {
V_3 -> V_379 = 1400 ;
V_3 -> V_381 = 1050 ;
} else {
V_3 -> V_379 = 1600 ;
V_3 -> V_381 = 1200 ;
}
}
}
}
static void F_43 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned char V_201 ;
unsigned short V_238 , V_207 ;
struct V_546 * V_533 = NULL ;
struct V_547 * V_548 = NULL ;
struct V_549 * V_550 = NULL ;
struct V_551 * V_552 = NULL ;
if ( V_199 <= 0x13 )
V_201 = V_3 -> V_4 [ V_200 ] . V_327 ;
else
V_201 = V_3 -> V_13 [ V_236 ] . V_328 ;
V_201 = V_201 & V_283 ;
if ( ( V_3 -> V_553 == 0 ) ||
( ( V_3 -> V_553 == 1 ) &&
( ! ( V_3 -> V_47 & V_390 ) ) ) ) {
V_238 = 0 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
V_533 = (struct V_546 * )
F_40 ( V_238 , V_199 ,
V_200 ,
V_236 ,
V_3 ) ;
for ( V_207 = 0 ; V_207 < 8 ; V_207 ++ )
V_3 -> V_138 [ 0 ] . V_276 [ V_207 ] = V_533 [ 0 ] . V_554 [ V_207 ] ;
}
if ( V_3 -> V_508 == 1 ) {
if ( V_3 -> V_48 & V_214 ) {
V_550 =
(struct V_549 * )
F_41 (
V_238 ,
V_199 ,
V_200 ,
V_236 ,
V_3 ) ;
for ( V_207 = 0 ; V_207 < 8 ; V_207 ++ )
V_3 -> V_138 [ 0 ] . V_276 [ V_207 ] =
V_550 [ 0 ] . V_276 [ V_207 ] ;
}
}
F_18 ( V_3 , V_221 ) ;
if ( V_3 -> V_508 == 1 ) {
F_4 ( V_3 -> V_211 , 0x2E ,
V_550 [ 0 ] . V_276 [ 8 ] ) ;
F_4 ( V_3 -> V_211 , 0x2F ,
V_550 [ 0 ] . V_276 [ 9 ] ) ;
}
V_238 = 1 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
V_548 = (struct V_547 * )
F_40 (
V_238 ,
V_199 ,
V_200 ,
V_236 ,
V_3 ) ;
for ( V_207 = 0 ; V_207 < 7 ; V_207 ++ )
V_3 -> V_141 [ 0 ] . V_276 [ V_207 ] = V_548 [ 0 ] . V_554 [ V_207 ] ;
}
if ( V_3 -> V_508 == 1 ) {
if ( V_3 -> V_48 & V_214 ) {
V_552 =
(struct V_551 * )
F_41 (
V_238 ,
V_199 ,
V_200 ,
V_236 ,
V_3 ) ;
for ( V_207 = 0 ; V_207 < 7 ; V_207 ++ )
V_3 -> V_141 [ 0 ] . V_276 [ V_207 ] =
V_552 [ 0 ] . V_276 [ V_207 ] ;
}
}
F_19 ( V_200 , V_199 , V_3 ) ;
if ( V_3 -> V_508 == 1 ) {
F_14 ( V_3 -> V_211 , 0x33 , ~ 0x01 ,
V_552 [ 0 ] . V_276 [ 7 ] & 0x01 ) ;
F_4 ( V_3 -> V_211 , 0x34 ,
V_552 [ 0 ] . V_276 [ 8 ] ) ;
F_4 ( V_3 -> V_211 , 0x3F ,
V_552 [ 0 ] . V_276 [ 9 ] ) ;
}
}
}
static unsigned short F_44 ( struct V_2 * V_3 )
{
unsigned char V_384 , V_205 , V_555 , V_207 ;
V_205 = F_8 ( V_3 -> V_223 , 0x36 ) ;
V_384 = V_205 & 0x0F ;
V_205 = V_205 & 0xF0 ;
V_207 = 0 ;
V_555 = V_3 -> V_158 [ V_207 ] . V_556 ;
while ( V_555 != 0xFF ) {
if ( V_555 & 0x80 ) {
V_384 = V_205 ;
V_555 = V_555 & ~ ( 0x80 ) ;
}
if ( V_384 == V_555 )
break;
V_207 ++ ;
V_555 = V_3 -> V_158 [ V_207 ] . V_556 ;
}
return V_207 ;
}
static unsigned short F_45 ( struct V_2 * V_3 )
{
unsigned short V_205 , V_384 , V_555 , V_207 ;
V_384 = V_3 -> V_45 ;
V_205 = V_3 -> V_46 ;
V_207 = 0 ;
V_555 = V_3 -> V_158 [ V_207 ] . V_556 ;
while ( V_555 != 0xFF ) {
if ( ( V_555 & 0x80 ) && ( V_555 != 0x80 ) ) {
V_384 = V_205 ;
V_555 &= ~ 0x80 ;
}
if ( V_384 == V_555 )
break;
V_207 ++ ;
V_555 = V_3 -> V_158 [ V_207 ] . V_556 ;
}
if ( V_555 == 0xFF ) {
V_3 -> V_45 = V_272 ;
V_3 -> V_46 = 0 ;
V_207 = 0 ;
}
return V_207 ;
}
static void F_46 ( unsigned short * V_557 ,
unsigned short * V_558 ,
struct V_2 * V_3 )
{
unsigned short V_559 ;
V_559 = F_44 ( V_3 ) ;
* V_557 = V_3 -> V_158 [ V_559 ] . V_560 ;
* V_558 = V_3 -> V_158 [ V_559 ] . V_561 ;
return;
}
static void F_47 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_238 , V_237 , V_304 , V_383 , V_562 , V_563 , V_208 ;
unsigned long V_275 , V_564 , V_312 , V_565 , V_566 ;
struct V_567 * V_533 = NULL ;
struct V_568 * V_548 = NULL ;
if ( V_199 > 0x13 )
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
else
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
if ( ! ( V_3 -> V_257 & V_569 ) ) {
if ( ( V_3 -> V_542 == 0 ) || ( V_3 -> V_48
& ( V_215 | V_213 ) ) ) {
if ( V_3 -> V_570 == 1 ) {
V_238 = 8 ;
V_533 = (struct V_567 * )
F_40 ( V_238 ,
V_199 ,
V_200 ,
V_236 ,
V_3 ) ;
}
if ( ( V_3 -> V_570 == 0 ) ||
( V_533 == NULL ) ) {
V_238 = 3 ;
if ( V_3 -> V_47 & V_390 )
V_548 =
(struct V_568 * )
F_40 (
V_238 ,
V_199 ,
V_200 ,
V_236 ,
V_3 ) ;
else
V_533 =
(struct V_567 * )
F_40 (
V_238 ,
V_199 ,
V_200 ,
V_236 ,
V_3 ) ;
}
F_46 ( & V_237 , & V_238 , V_3 ) ;
V_562 = V_238 ;
V_563 = V_237 ;
if ( ( V_3 -> V_45 == V_272 ) ||
( V_3 -> V_45 == V_347 ) ) {
V_237 = 1024 ;
V_238 = 768 ;
} else if ( ( V_3 -> V_45 == V_249 ) ||
( V_3 -> V_45 == V_544 ) ) {
V_237 = 1280 ;
V_238 = 1024 ;
} else if ( V_3 -> V_45 == V_545 ) {
V_237 = 1400 ;
V_238 = 1050 ;
} else {
V_237 = 1600 ;
V_238 = 1200 ;
}
if ( V_3 -> V_47 & V_543 ) {
V_3 -> V_379 = V_237 ;
V_3 -> V_381 = V_238 ;
V_3 -> V_378 = V_237 ;
V_3 -> V_380 = V_238 ;
}
if ( ( V_3 -> V_553 == 1 ) &&
( V_3 -> V_47 & V_390 ) ) {
V_237 = V_3 -> V_379 ;
V_238 = V_3 -> V_381 ;
}
V_237 = V_3 -> V_538 ;
if ( V_3 -> V_47 & V_390 )
V_238 = V_548 -> V_571 ;
else
V_238 = V_533 -> V_571 ;
V_304 = V_3 -> V_379 ;
V_238 = V_238 & 0x0fff ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
F_4 ( V_3 -> V_572 , 0x1A , V_238 & 0x07 ) ;
V_304 = V_304 >> 3 ;
V_238 = V_238 >> 3 ;
F_4 ( V_3 -> V_572 , 0x16 ,
( unsigned short ) ( V_238 & 0xff ) ) ;
F_4 ( V_3 -> V_572 , 0x17 ,
( unsigned short ) ( V_304 & 0xff ) ) ;
V_237 = V_3 -> V_538 ;
if ( V_3 -> V_47 & V_390 )
V_238 = V_548 -> V_573 ;
else
V_238 = V_533 -> V_573 ;
V_304 = V_563 ;
if ( V_3 -> V_47 & V_390 )
V_304 = V_548 -> V_574 ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
V_237 = V_238 & 0x07 ;
V_237 = V_237 >> 5 ;
V_304 = V_304 >> 3 ;
V_238 = V_238 >> 3 ;
V_304 &= 0x1f ;
V_237 |= V_304 ;
F_4 ( V_3 -> V_572 , 0x15 , V_237 ) ;
F_4 ( V_3 -> V_572 , 0x14 ,
( unsigned short ) ( V_238 & 0xff ) ) ;
V_237 = V_3 -> V_540 ;
if ( V_3 -> V_47 & V_390 )
V_238 = V_548 -> V_575 ;
else
V_238 = V_533 -> V_575 ;
V_304 = V_3 -> V_381 ;
V_238 = V_238 & 0x0fff ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
F_4 ( V_3 -> V_572 , 0x1b ,
( unsigned short ) ( V_238 & 0xff ) ) ;
F_4 ( V_3 -> V_572 , 0x1c ,
( unsigned short ) ( V_304 & 0xff ) ) ;
V_238 = ( V_238 >> 8 ) & 0x07 ;
V_304 = ( V_304 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_572 , 0x1d ,
( unsigned short ) ( ( V_304 << 3 )
| V_238 ) ) ;
V_237 = V_3 -> V_540 ;
if ( V_3 -> V_47 & V_390 )
V_238 = V_548 -> V_576 ;
else
V_238 = V_533 -> V_576 ;
V_304 = V_562 ;
if ( V_3 -> V_47 & V_390 )
V_304 = V_548 -> V_577 ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
F_4 ( V_3 -> V_572 , 0x18 ,
( unsigned short ) ( V_238 & 0xff ) ) ;
F_14 ( V_3 -> V_572 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_304 & 0x0f ) ) ;
V_237 = ( ( V_238 >> 8 ) & 0x07 ) << 3 ;
V_238 = V_3 -> V_380 ;
if ( V_238 != V_3 -> V_381 )
V_237 |= 0x40 ;
if ( V_3 -> V_47 & V_578 )
V_237 |= 0x40 ;
F_14 ( V_3 -> V_572 , 0x1a , 0x07 ,
V_237 ) ;
V_304 = V_3 -> V_537 ;
V_238 = V_3 -> V_381 ;
V_237 = V_3 -> V_380 ;
V_304 -= V_237 ;
V_275 = V_237 ;
V_564 = ( V_275 << 18 ) / V_238 ;
V_383 = ( unsigned short ) ( ( V_275 << 18 ) % V_238 ) ;
if ( V_383 != 0 )
V_564 += 1 ;
V_312 = V_564 ;
V_566 = V_312 ;
F_4 ( V_3 -> V_572 , 0x37 ,
( unsigned short ) ( V_312 & 0xff ) ) ;
F_4 ( V_3 -> V_572 , 0x36 ,
( unsigned short ) ( ( V_312 >> 8 ) & 0xff ) ) ;
V_238 = ( unsigned short ) ( V_312 >> 16 ) ;
V_237 = V_238 & 0x03 ;
V_238 = V_3 -> V_380 ;
if ( V_238 == V_3 -> V_381 )
V_237 |= 0x04 ;
F_4 ( V_3 -> V_572 , 0x35 , V_237 ) ;
if ( V_3 -> V_155 & V_246 ) {
V_312 = V_566 ;
F_4 ( V_3 -> V_579 ,
0x3c ,
( unsigned short ) ( V_312 & 0xff ) ) ;
F_4 ( V_3 -> V_579 ,
0x3b ,
( unsigned short ) ( ( V_312 >> 8 ) &
0xff ) ) ;
V_238 = ( unsigned short ) ( V_312 >> 16 ) ;
F_14 ( V_3 -> V_579 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_238 &
0xff ) << 6 ) ) ;
V_304 = V_3 -> V_380 ;
if ( V_304 == V_3 -> V_381 )
F_14 ( V_3 -> V_579 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_14 ( V_3 -> V_579 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_304 = V_3 -> V_378 ;
V_238 = V_3 -> V_379 ;
V_564 = V_304 << 16 ;
V_237 = ( unsigned short ) ( V_564 / V_238 ) ;
if ( ( V_238 & 0xffff ) == ( V_304 & 0xffff ) )
V_237 = 65535 ;
V_565 = V_237 ;
V_564 = V_3 -> V_378 << 16 ;
V_564 /= V_565 ;
V_565 = V_565 << 16 ;
V_564 -= 1 ;
V_565 = ( V_565 & 0xffff0000 ) + ( V_564 & 0xffff ) ;
V_237 = ( unsigned short ) ( V_565 & 0xff ) ;
F_4 ( V_3 -> V_572 , 0x1f , V_237 ) ;
V_564 = V_3 -> V_380 << 18 ;
V_564 = V_564 / V_566 ;
V_238 = ( unsigned short ) ( V_564 & 0xffff ) ;
if ( V_3 -> V_45 == V_272 )
V_238 -= 1 ;
V_237 = ( ( V_238 >> 8 ) & 0xff ) << 3 ;
V_237 |= ( unsigned short ) ( ( V_565 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_572 , 0x20 ,
( unsigned short ) ( V_237 & 0xff ) ) ;
F_4 ( V_3 -> V_572 , 0x21 ,
( unsigned short ) ( V_238 & 0xff ) ) ;
V_565 = V_565 >> 16 ;
if ( V_208 & V_307 )
V_565 = V_565 >> 1 ;
F_4 ( V_3 -> V_572 , 0x22 ,
( unsigned short ) ( ( V_565 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_572 , 0x23 ,
( unsigned short ) ( V_565 & 0xff ) ) ;
}
}
}
static void F_48 ( unsigned char * V_580 , unsigned char * V_581 ,
struct V_2 * V_3 )
{
unsigned short V_201 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
if ( V_3 -> V_553 == 1 ) {
if ( V_3 -> V_47 & V_390 )
return;
}
V_201 = F_45 ( V_3 ) ;
if ( V_3 -> V_48 & V_215 ) {
* V_580 = V_3 -> V_158 [ V_201 ] . V_582 ;
* V_581 = V_3 -> V_158 [ V_201 ] . V_583 ;
} else {
* V_580 = V_3 -> V_158 [ V_201 ] . V_584 ;
* V_581 = V_3 -> V_158 [ V_201 ] . V_585 ;
}
}
return;
}
static unsigned char F_49 ( unsigned short V_236 ,
unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_201 , V_208 ;
unsigned short V_238 ;
unsigned char V_384 ;
unsigned char * V_326 = NULL ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
if ( ( V_3 -> V_257 & V_586 ) &&
( ! ( V_3 -> V_47 & V_390 ) ) ) {
V_201 = F_44 ( V_3 ) ;
V_384 = V_3 -> V_158 [ V_201 ] . V_587 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) )
return V_384 ;
if ( V_3 -> V_155 &
( V_264 |
V_265 |
V_156 |
V_157 |
V_246 ) ) {
if ( V_3 -> V_48 & V_252 ) {
V_384 = V_330 ;
if ( ! ( V_3 -> V_49 & V_329 ) )
V_384 = V_331 ;
if ( V_3 -> V_49 & V_258 ) {
V_384 = V_332 ;
if ( ! ( V_208 & V_227 ) )
V_384 = V_333 ;
}
return V_384 ;
}
if ( V_3 -> V_49 & V_588 ) {
V_384 = V_334 ;
return V_384 ;
}
if ( V_3 -> V_49 & V_589 ) {
V_384 = V_336 ;
return V_384 ;
}
V_384 = V_590 ;
if ( ! ( V_3 -> V_49 & V_591 ) ) {
V_384 = V_340 ;
if ( ! ( V_3 -> V_49 & V_329 ) )
V_384 = V_341 ;
}
if ( V_3 -> V_48 & V_214 )
return V_384 ;
}
}
if ( ( V_3 -> V_508 == 1 ) &&
( V_3 -> V_155 & V_592 ) ) {
if ( ( V_3 -> V_48 & V_214 ) ) {
if ( V_199 <= 0x13 ) {
V_384 = V_3 -> V_4 [ V_200 ] .
V_327 ;
} else {
V_384 = V_3 -> V_13 [
V_236 ] . V_328 ;
}
V_384 = V_384 & 0x0F ;
V_238 = 0 ;
if ( V_3 -> V_49 & V_267 )
V_238 = V_238 + 2 ;
if ( V_3 -> V_49 & V_344 )
V_238 ++ ;
if ( V_3 -> V_508 == 1 ) {
switch ( V_238 ) {
case 0 :
V_326 = V_593 ;
break;
case 1 :
V_326 = V_594 ;
break;
case 2 :
V_326 = V_595 ;
break;
case 3 :
V_326 = V_596 ;
break;
default:
break;
}
}
V_384 = V_326 [ V_384 ] ;
return V_384 ;
}
}
V_384 = ( unsigned char ) F_10 ( ( V_3 -> V_342 + 0x02 ) ) ;
V_384 = V_384 >> 2 ;
V_384 &= 0x03 ;
if ( ( V_3 -> V_47 & V_390 ) && ( V_208 & V_227 ) )
V_384 = V_384 ^ V_384 ;
if ( V_199 <= 0x13 )
return V_384 ;
V_384 = V_3 -> V_13 [ V_236 ] . V_343 ;
return V_384 ;
}
static void F_50 ( unsigned char V_384 , unsigned char * V_580 ,
unsigned char * V_581 , struct V_2 * V_3 )
{
if ( V_3 -> V_508 == 1 ) {
* V_580 = ( unsigned char ) V_597 [ V_384 ] . V_234 ;
* V_581 = ( unsigned char ) V_597 [ V_384 ] . V_235 ;
} else if ( V_3 -> V_155 & ( V_598 | V_264 | V_265
| V_156 | V_157 | V_246 ) ) {
if ( ( ! ( V_3 -> V_48 & V_213 ) ) && ( V_3 -> V_257
& V_586 ) ) {
* V_580 = ( unsigned char ) V_30 [ V_384 ] . V_234 ;
* V_581 = V_30 [ V_384 ] . V_235 ;
}
} else {
* V_580 = V_27 [ V_384 ] . V_234 ;
* V_581 = V_27 [ V_384 ] . V_235 ;
}
}
static void F_51 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned char V_580 , V_581 , V_384 ;
int V_207 ;
V_384 = F_49 ( V_236 , V_199 , V_200 ,
V_3 ) ;
F_50 ( V_384 , & V_580 , & V_581 , V_3 ) ;
F_48 ( & V_580 , & V_581 , V_3 ) ;
for ( V_207 = 0 ; V_207 < 4 ; V_207 ++ ) {
F_14 ( V_3 -> V_223 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_207 ) ) ;
if ( V_3 -> V_508 == 1 ) {
F_4 ( V_3 -> V_211 , 0x2b , V_580 ) ;
F_4 ( V_3 -> V_211 , 0x2c , V_581 ) ;
} else if ( ( ! ( V_3 -> V_48 & V_213 ) )
&& ( ! ( V_3 -> V_48 & V_216 ) ) ) {
F_4 ( V_3 -> V_211 , 0x2e , V_580 ) ;
F_4 ( V_3 -> V_211 , 0x2f , V_581 ) ;
} else {
F_4 ( V_3 -> V_211 , 0x2b , V_580 ) ;
F_4 ( V_3 -> V_211 , 0x2c , V_581 ) ;
}
}
}
static void F_52 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_599 , V_600 , V_275 , V_555 , V_237 ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
V_599 = 0 ;
V_600 = 0 ;
V_275 = F_8 ( V_3 -> V_211 , 0x01 ) ;
if ( ! ( V_275 & 0x20 ) ) {
V_275 = F_8 ( V_3 -> V_223 , 0x17 ) ;
if ( V_275 & 0x80 ) {
V_275 = F_8 ( V_3 -> V_223 , 0x53 ) ;
if ( ! ( V_275 & 0x40 ) )
V_599 |= V_601 ;
}
}
V_275 = F_8 ( V_3 -> V_572 , 0x2e ) ;
V_275 &= 0x0f ;
if ( ! ( V_275 == 0x08 ) ) {
V_237 = F_8 ( V_3 -> V_572 , 0x13 ) ;
if ( V_237 & 0x04 )
V_599 = V_599 | V_602 ;
V_275 &= 0x05 ;
if ( ! ( V_599 & V_602 ) )
if ( V_275 == 0x01 )
V_599 |= V_603 ;
if ( V_275 == 0x04 )
V_599 |= V_602 ;
if ( V_275 == 0x05 ) {
V_275 = F_8 ( V_3 -> V_604 , 0x00 ) ;
if ( ! ( V_275 & 0x08 ) )
V_600 |= V_605 ;
if ( ! ( V_275 & 0x04 ) )
V_600 |= V_606 ;
if ( V_275 & 0x02 )
V_600 |= V_607 ;
if ( V_3 -> V_48 & V_252 ) {
if ( V_275 & 0x01 )
V_600 |= V_608 ;
}
if ( V_3 -> V_48 & V_262 ) {
V_275 = F_8 (
V_3 -> V_604 ,
0x4d ) ;
if ( V_275 & 0x10 )
V_600 |= V_609 ;
}
if ( V_600 != 0 )
V_599 |= V_610 ;
}
}
V_275 = F_8 ( V_3 -> V_223 , 0x3d ) ;
if ( V_599 & V_602 ) {
if ( ( V_3 -> V_257 & V_611 ) ) {
if ( V_275 & V_610 )
V_599 |= V_610 ;
}
}
V_275 = V_599 ;
V_555 = ~ V_612 ;
F_14 ( V_3 -> V_223 , 0x3d , V_555 , V_275 ) ;
if ( ! ( V_3 -> V_257 & V_611 ) )
F_4 ( V_3 -> V_223 , 0x3e , V_600 ) ;
} else {
return;
}
}
void F_53 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
V_3 -> V_613 = V_221 -> V_280 ;
}
void F_54 ( struct V_2 * V_3 )
{
unsigned short V_614 , V_238 , V_205 ;
if ( V_3 -> V_508 == 1 ) {
V_3 -> V_155 = V_592 ;
return;
}
if ( V_3 -> V_243 == 0 ) {
V_238 = V_265 ;
V_614 = F_8 ( V_3 -> V_579 , 0x00 ) ;
if ( V_614 != 0x02 ) {
V_238 = V_598 ;
V_614 = F_8 ( V_3 -> V_579 , 0x01 ) ;
if ( V_614 >= 0xB0 ) {
V_238 = V_264 ;
if ( V_614 >= 0xC0 ) {
V_238 = V_246 ;
if ( V_614 >= 0xD0 ) {
V_238 = V_156 ;
if ( V_614 >= 0xE0 ) {
V_238 = V_157 ;
V_205 = F_8 (
V_3 -> V_579 ,
0x39 ) ;
if ( V_205 != 0xFF )
V_238 =
V_246 ;
}
}
}
if ( V_238 & ( V_264 | V_265 ) ) {
V_614 = F_8 (
V_3 -> V_579 ,
0x23 ) ;
if ( ! ( V_614 & 0x02 ) )
V_238 = V_238 | V_615 ;
}
}
}
V_3 -> V_155 = V_238 ;
}
}
void F_55 ( unsigned short V_199 , unsigned short V_200 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_237 , V_616 , V_238 , V_275 , V_208 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_3 -> V_257 = 0 ;
V_3 -> V_203 = V_208 & V_617 ;
V_238 = 0 ;
if ( V_3 -> V_155 & 0xFFFF ) {
V_275 = F_8 ( V_3 -> V_223 , 0x30 ) ;
V_238 = V_238 | V_275 ;
V_275 = F_8 ( V_3 -> V_223 , 0x31 ) ;
V_616 = V_275 ;
V_616 = V_616 << 8 ;
V_237 = V_275 << 8 ;
V_238 = V_238 | V_237 ;
V_275 = ( V_618 | V_262 | V_213
| V_216 | V_619 ) ;
V_275 = 0xFFFF ^ V_275 ;
V_238 &= V_275 ;
V_275 = F_8 ( V_3 -> V_223 , 0x38 ) ;
if ( V_3 -> V_620 == 1 ) {
if ( ( V_3 -> V_613 >= V_171 )
|| ( V_3 -> V_613 >= V_621 ) ) {
if ( V_3 -> V_243 == 0 ) {
if ( V_3 -> V_155 &
( V_265 |
V_156 |
V_157 |
V_246 ) ) {
if ( V_275 & V_622 ) {
V_238 |=
V_618 ;
if ( V_275 & V_623 )
V_238 |=
V_213 ;
}
}
} else if ( V_3 -> V_542 == 1 ) {
if ( V_3 -> V_155 & V_624 ) {
if ( V_275 & V_622 ) {
V_238 |=
V_618 ;
if ( V_275 & V_623 )
V_238 |=
V_213 ;
}
}
}
}
}
if ( V_3 -> V_625 == 1 ) {
if ( ( ( V_3 -> V_243 == 0 ) &&
( ( V_3 -> V_155 & V_156 ) ||
( V_3 -> V_155 & V_157 ) ||
( V_3 -> V_155 & V_246 ) ) ) ||
( ( V_3 -> V_542 == 1 ) &&
( V_3 -> V_155 & V_624 ) ) ||
( ( V_3 -> V_508 == 1 ) &&
( V_3 -> V_155 & V_592 ) ) ) {
if ( V_275 & V_626 ) {
if ( V_3 -> V_627 == 1 ) {
V_275 = F_8 (
V_3 -> V_223 ,
0x35 ) ;
V_275 &= V_628 ;
V_238 |= V_252 ;
if ( V_275 != V_629 ) {
V_238 &=
( ~ V_252 ) ;
V_238 |=
V_262 ;
}
}
}
}
}
V_237 = V_616 ;
if ( V_3 -> V_243 == 0 ) {
if ( V_3 -> V_625 == 1 ) {
if ( V_3 -> V_627 == 1 )
V_275 = 0x09FC ;
else
V_275 = 0x097C ;
} else {
if ( V_3 -> V_627 == 1 )
V_275 = 0x01FC ;
else
V_275 = 0x017C ;
}
} else {
if ( V_3 -> V_542 == 1 )
V_275 = ( V_214 |
V_215 |
V_213 ) ;
else if ( V_3 -> V_508 == 1 )
V_275 = V_214 ;
else
V_275 = V_215 ;
}
if ( ! ( V_238 & V_275 ) ) {
V_237 |= V_619 ;
V_238 = 0 ;
}
if ( V_3 -> V_620 == 1 ) {
if ( ! ( V_3 -> V_155 & V_615 ) ) {
if ( V_238 & V_213 ) {
if ( V_238 & V_630 )
V_238 &= ( ~ ( V_215 |
V_244 |
V_631 ) ) ;
else
V_238 &= ( ~ ( V_215 |
V_244 |
V_214 |
V_631 ) ) ;
}
}
}
if ( ! ( V_238 & ( V_631 | V_630 ) ) ) {
if ( V_3 -> V_632 == 1 ) {
if ( V_238 & V_244 ) {
V_238 &= ( 0xFF00 |
V_244 |
V_631 |
V_630 ) ;
V_238 &= ( 0x00FF | ( ~ V_262 ) ) ;
}
} else {
V_238 &= ( ~ ( V_244 |
V_215 |
V_214 ) ) ;
}
}
if ( ! ( V_3 -> V_155 & V_615 ) ) {
if ( V_238 & V_215 ) {
V_238 &= ( 0xFF00 |
V_215 |
V_631 |
V_630 ) ;
V_238 &= ( 0x00FF | ( ~ V_262 ) ) ;
}
}
if ( V_238 & V_261 ) {
V_238 &= ( 0xFF00 |
V_261 |
V_631 |
V_630 ) ;
V_238 &= ( 0x00FF | ( ~ V_262 ) ) ;
}
if ( V_3 -> V_625 == 1 ) {
if ( V_238 & V_262 )
V_238 &= ( 0xFF00 |
V_631 |
V_630 ) ;
}
if ( V_3 -> V_627 == 1 ) {
if ( V_238 & V_252 )
V_238 &= ( 0xFF00 |
V_252 |
V_631 |
V_630 ) ;
}
if ( V_237 & V_619 ) {
if ( ! ( V_238 & ( V_631 | V_630 ) ) )
V_238 = V_619 ;
}
if ( ! ( V_238 & V_619 ) ) {
if ( ( ! ( V_238 & V_633 ) ) ||
( ! ( V_208 & V_634 ) ) ) {
if ( V_3 -> V_620 == 1 ) {
if ( ! ( V_238 & V_213 ) )
V_238 |= ( V_216 |
V_630 ) ;
}
if ( V_3 -> V_635 == 1 ) {
if ( ( ( V_221 -> V_280 ==
V_621 ) &&
( V_3 -> V_613 == V_621 ) ) ||
( ( V_221 -> V_280 ==
V_636 ) &&
( V_3 -> V_613 == V_636 ) ) ||
( ( V_221 -> V_280 ==
V_637 ) &&
( V_3 -> V_613 == V_637 ) ) ||
( ( V_221 -> V_280 ==
V_638 ) &&
( V_3 -> V_613 == V_638 ) ) ) {
if ( V_199 <= 13 ) {
if ( ! ( V_238 &
V_244 ) ) {
V_238 &=
( 0x00FF |
( ~ V_216 ) ) ;
V_3 -> V_257
|= V_639 ;
}
}
}
}
}
if ( ( V_238 & V_216 ) &&
( V_238 & V_213 ) ) {
V_238 ^= ( V_215 |
V_213 |
V_618 ) ;
V_3 -> V_257 |= V_611 ;
}
}
}
V_3 -> V_48 = V_238 ;
}
void F_56 ( unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_275 , V_238 = 0 , V_239 = 0 , V_208 , V_640 ;
V_238 = 0 ;
V_239 = 0 ;
if ( V_3 -> V_48 & V_214 ) {
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] .
V_209 ;
V_239 = V_3 -> V_4 [ V_200 ] .
V_309 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] .
V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] .
V_241 ;
}
if ( V_3 -> V_48 & V_214 ) {
V_275 = F_8 ( V_3 -> V_223 , 0x35 ) ;
V_238 = V_275 ;
if ( V_238 & V_267 ) {
V_238 &= ( V_344 |
V_641 |
V_642 |
V_267 ) ;
if ( V_238 & V_641 )
V_238 &= ~ V_267 ;
} else
V_238 &= ( V_344 |
V_643 |
V_267 ) ;
}
if ( V_3 -> V_542 == 1 ) {
V_238 = F_8 ( V_3 -> V_223 , 0x35 ) ;
if ( V_238 & V_644 )
V_238 |= V_344 ;
}
if ( V_3 -> V_508 == 1 ) {
V_238 = F_8 ( V_3 -> V_223 , 0x35 ) ;
if ( V_238 & V_644 )
V_238 |= V_344 ;
}
if ( V_3 -> V_243 == 0 ) {
if ( V_3 -> V_48 & V_261 )
V_238 |= V_267 ;
}
if ( V_3 -> V_625 == 1 ) {
if ( V_3 -> V_48 & V_262 ) {
V_640 = F_8 ( V_3 -> V_223 , 0x35 ) ;
V_640 &= V_628 ;
if ( V_640 == V_645 )
V_238 |= V_646 ;
if ( V_640 == V_647 )
V_238 = V_238 | V_589 ;
if ( V_640 == V_648 )
V_238 = V_238 | V_588 ;
}
}
if ( V_3 -> V_627 == 1 ) {
if ( V_3 -> V_48 & V_252 )
V_238 = V_238 | V_649 | V_267 ;
}
if ( V_3 -> V_243 == 0 ) {
if ( ( V_3 -> V_48 & V_216 ) &&
( ! ( V_3 -> V_48 & V_269 ) ) )
V_238 |= V_258 ;
if ( ! ( V_238 & V_267 ) &&
( V_208 > 13 ) &&
( V_239 == 8 ) )
V_238 |= V_591 ;
V_238 |= V_329 ;
if ( V_3 -> V_48 & V_252 ) {
if ( V_3 -> V_48 & V_216 )
V_238 &= ( ~ V_329 ) ;
} else {
if ( V_238 &
( V_589 | V_588 ) )
V_238 &= ( ~ V_329 ) ;
else if ( ! ( V_3 -> V_155 &
( V_264 |
V_265 |
V_156 |
V_157 |
V_246 ) ) ) {
if ( V_238 & V_258 )
V_238 &= ( ~ V_329 ) ;
}
}
}
}
V_3 -> V_49 = V_238 ;
}
unsigned char F_57 ( unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_275 , V_237 , V_238 , V_208 , V_239 = 0 , V_650 ;
V_3 -> V_45 = 0 ;
V_3 -> V_46 = 0 ;
V_3 -> V_47 = 0 ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
}
V_275 = F_8 ( V_3 -> V_223 , 0x36 ) ;
V_238 = V_275 & 0x0F ;
if ( V_238 == 0 )
V_238 = V_272 ;
if ( ( V_238 == V_272 ) || ( V_238 == V_249 ) ) {
if ( V_3 -> V_48 & V_633 ) {
V_237 = F_8 ( V_3 -> V_223 , 0x33 ) ;
if ( V_3 -> V_48 & V_213 )
V_237 &= 0x0F ;
else
V_237 = V_237 >> 4 ;
if ( ( V_239 == 6 ) || ( V_239 == 9 ) ) {
if ( V_237 >= 3 )
V_238 |= V_651 ;
} else if ( ( V_239 == 7 ) || ( V_239 == 8 ) ) {
if ( V_237 >= 4 )
V_238 |= V_651 ;
}
}
}
V_3 -> V_45 = V_238 ;
if ( V_3 -> V_570 == 1 )
V_3 -> V_46 = ( V_275 & 0xf0 ) >> 4 ;
if ( ! ( V_3 -> V_48 & ( V_215 | V_213 ) ) )
return 0 ;
V_238 = 0 ;
V_275 = F_8 ( V_3 -> V_223 , 0x37 ) ;
V_275 &= ( V_652 | V_251 | V_653 | V_654 ) ;
if ( ( V_3 -> V_553 == 1 ) && ( V_275 & V_251 ) )
V_275 &= ~ V_390 ;
V_238 |= V_275 ;
V_650 = F_45 ( V_3 ) ;
V_237 = V_3 -> V_158 [ V_650 ] . V_655 ;
if ( V_3 -> V_243 == 0 ) {
if ( ( ( V_3 -> V_155 & V_157 ) || ( V_3 -> V_155
& V_246 ) ) && ( V_237 & V_656 ) ) {
V_238 |= V_657 ;
}
}
if ( V_3 -> V_542 == 1 ) {
if ( V_237 & V_656 )
V_238 |= V_657 ;
}
if ( V_3 -> V_243 == 0 ) {
if ( ( V_3 -> V_45 == V_545 ) && ( V_3 -> V_48
& V_215 ) && ( V_199 > 0x13 ) && ( V_239
== 9 ) && ( ! ( V_238 & V_390 ) ) )
V_238 |= V_543 ;
}
if ( V_3 -> V_658 == 1 ) {
if ( V_208 & V_307 ) {
if ( ! ( V_238 & V_543 ) ) {
V_238 |= V_578 ;
} else {
if ( V_199 > 0x13 ) {
if ( V_3 -> V_45
== V_272 ) {
if ( V_239 == 4 ) {
V_238 |= V_578 ;
}
}
}
}
}
}
if ( V_3 -> V_48 & V_216 ) {
if ( V_3 -> V_48 & V_269 )
V_238 |= V_659 ;
} else {
V_238 |= V_659 ;
}
V_3 -> V_47 = V_238 ;
if ( V_3 -> V_660 == 1 ) {
if ( V_3 -> V_47 & V_654 ) {
if ( ( V_3 -> V_155 & V_157 ) ||
( V_3 -> V_155 & V_246 ) ) {
if ( ! ( V_237 & V_661 ) )
V_3 -> V_47 &= ~ V_654 ;
}
}
}
if ( V_3 -> V_243 == 0 ) {
if ( V_237 & ( V_662 | V_663 ) ) {
if ( V_3 -> V_48 & V_216 ) {
if ( ! ( V_237 & V_662 ) ) {
if ( V_199 <= 0x13 ) {
V_3 -> V_48 &=
~ ( V_630 |
V_216 |
V_215 ) ;
V_3 -> V_48 |=
V_213 |
V_618 ;
}
}
}
}
}
return 1 ;
}
unsigned char F_58 ( unsigned short V_199 ,
unsigned short * V_200 , struct V_2 * V_3 )
{
if ( V_199 <= 5 )
V_199 |= 1 ;
if ( V_199 <= 0x13 ) {
for ( * V_200 = 0 ; ; ( * V_200 ) ++ ) {
if ( V_3 -> V_4 [ * V_200 ] . V_664 ==
V_199 )
break;
if ( V_3 -> V_4 [ * V_200 ] . V_664 ==
0xFF )
return 0 ;
}
if ( V_199 == 0x07 )
( * V_200 ) ++ ;
if ( V_199 <= 3 )
( * V_200 ) += 2 ;
} else {
for ( * V_200 = 0 ; ; ( * V_200 ) ++ ) {
if ( V_3 -> V_10 [ * V_200 ] . V_665 ==
V_199 )
break;
if ( V_3 -> V_10 [ * V_200 ] . V_665 ==
0xFF )
return 0 ;
}
}
return 1 ;
}
static unsigned char F_59 ( unsigned char V_666 )
{
unsigned char V_667 = 0 ;
unsigned char V_207 = 0 ;
for ( V_207 = 0 ; V_207 < 8 ; V_207 ++ ) {
V_667 = V_667 << 1 ;
V_667 |= ( V_666 >> V_207 ) & 1 ;
}
return V_667 ;
}
static unsigned char F_60 ( struct V_2 * V_3 )
{
unsigned char V_668 , V_275 ;
V_668 = F_8 ( V_3 -> V_223 , 0x4A ) ;
F_15 ( V_3 -> V_223 , 0x4A , ~ 0x23 ) ;
V_275 = F_8 ( V_3 -> V_223 , 0x48 ) ;
V_275 = F_59 ( V_275 ) ;
V_275 &= 0x23 ;
F_4 ( V_3 -> V_223 , 0x4A , V_668 ) ;
return V_275 ;
}
static unsigned char F_61 ( struct V_2 * V_3 )
{
unsigned char V_668 , V_669 , V_275 ;
V_668 = F_8 ( V_3 -> V_223 , 0x4A ) ;
F_15 ( V_3 -> V_223 , 0x4A , ~ 0x0C ) ;
V_275 = F_8 ( V_3 -> V_223 , 0x48 ) ;
V_275 &= 0x0C ;
V_275 >>= 2 ;
F_4 ( V_3 -> V_223 , 0x4A , V_668 ) ;
V_669 = F_8 ( V_3 -> V_223 , 0xB4 ) ;
V_275 |= ( ( V_669 & 0x04 ) << 3 ) ;
return V_275 ;
}
void F_62 ( struct V_220 * V_670 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_211 , 0x01 , 0xDF , 0x00 ) ;
if ( V_670 -> V_280 == V_161 ) {
if ( V_3 -> V_243 == 1 ) {
if ( ! ( F_60 ( V_3 ) & 0x1 ) ) {
F_63 ( 0x01 , 0x01 , V_3 ) ;
F_64 ( 2 , V_3 ) ;
}
if ( ! ( F_60 ( V_3 ) & 0x20 ) )
F_63 ( 0x20 , 0x20 , V_3 ) ;
F_64 ( 3 , V_3 ) ;
F_63 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_63 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_3 -> V_508 == 1 ) {
}
if ( V_670 -> V_280 == V_162 ) {
if ( V_3 -> V_243 == 1 ) {
if ( ! ( F_61 ( V_3 ) & 0x1 ) ) {
F_65 ( 0x01 , 0x01 , V_3 ) ;
F_64 ( 2 , V_3 ) ;
}
if ( ! ( F_61 ( V_3 ) & 0x20 ) )
F_65 ( 0x20 , 0x20 , V_3 ) ;
F_64 ( 3 , V_3 ) ;
F_65 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_65 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_66 ( struct V_220 * V_670 ,
struct V_2 * V_3 )
{
if ( V_670 -> V_280 == V_161 ) {
if ( V_3 -> V_243 == 1 ) {
F_63 ( 0x02 , 0x00 , V_3 ) ;
F_64 ( 3 , V_3 ) ;
} else {
F_63 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_3 -> V_508 == 1 ) {
{
}
}
if ( V_670 -> V_280 == V_162 ) {
if ( ( F_61 ( V_3 ) & 0x2 ) ) {
F_65 ( 0x02 , 0x00 , V_3 ) ;
F_64 ( 3 , V_3 ) ;
}
if ( V_3 -> V_243 == 0 )
F_65 ( 0x20 , 0x00 , V_3 ) ;
}
F_14 ( V_3 -> V_211 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_67 ( struct V_2 * V_3 )
{
while ( ( F_10 ( V_3 -> V_228 ) & 0x01 ) )
break;
while ( ! ( F_10 ( V_3 -> V_228 ) & 0x01 ) )
break;
}
static void F_68 ( struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_257 & V_569 ) )
F_22 ( V_3 -> V_572 , 0x01 , 0x40 ) ;
}
static void F_69 ( unsigned short V_199 ,
struct V_2 * V_3 )
{
unsigned short V_564 , V_312 ;
F_4 ( V_3 -> V_223 , 0x34 , V_199 ) ;
V_564 = ( V_3 -> V_48 & V_216 ) >> 8 ;
V_312 = ~ ( V_216 >> 8 ) ;
F_14 ( V_3 -> V_223 , 0x31 , V_312 , V_564 ) ;
}
static void F_70 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_354 , V_377 , V_208 , V_303 ;
V_303 = F_29 ( V_199 , V_200 , V_3 ) ;
if ( V_199 <= 0x13 ) {
V_354 = V_3 -> V_33 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_33 [ V_303 ] . V_306 ;
} else {
V_354 = V_3 -> V_36 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_36 [ V_303 ] . V_306 ;
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
if ( V_208 & V_307 )
V_354 *= 2 ;
if ( V_208 & V_281 )
V_377 *= 2 ;
}
if ( V_3 -> V_48 & V_215 ) {
if ( V_3 -> V_243 == 0 ) {
if ( V_3 -> V_45 == V_671 ) {
if ( ! ( V_3 -> V_47 & V_659 ) ) {
if ( V_377 == 1024 )
V_377 = 1056 ;
}
}
if ( V_3 -> V_45 == V_249 ) {
if ( V_377 == 400 )
V_377 = 405 ;
else if ( V_377 == 350 )
V_377 = 360 ;
if ( V_3 -> V_47 & V_659 ) {
if ( V_377 == 360 )
V_377 = 375 ;
}
}
if ( V_3 -> V_45 == V_272 ) {
if ( ! ( V_3 -> V_47 & V_659 ) ) {
if ( ! ( V_3 -> V_47
& V_251 ) ) {
if ( V_377 == 350 )
V_377 = 357 ;
else if ( V_377 == 400 )
V_377 = 420 ;
else if ( V_377 == 480 )
V_377 = 525 ;
}
}
}
}
if ( V_354 == 720 )
V_354 = 640 ;
}
V_3 -> V_378 = V_354 ;
V_3 -> V_379 = V_354 ;
V_3 -> V_380 = V_377 ;
V_3 -> V_381 = V_377 ;
}
static unsigned char F_71 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_48 & ( V_215 | V_213 ) ) &&
( V_3 -> V_47 & V_657 ) )
return 1 ;
return 0 ;
}
static void F_72 ( unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_237 , V_238 , V_564 , V_312 , V_208 = 0 , V_304 ,
V_204 , V_672 ;
V_3 -> V_673 = 1 ;
V_3 -> V_674 = 1 ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_204 = F_2 ( V_199 , V_200 , V_3 ) ;
V_237 = V_3 -> V_7 [ V_204 ] . V_224 [ 0 ] ;
V_238 = V_3 -> V_7 [ V_204 ] . V_224 [ 6 ] ;
V_564 = V_3 -> V_7 [ V_204 ] . V_224 [ 7 ] ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_672 = V_3 -> V_13 [ V_236 ] .
V_282 ;
V_672 &= V_283 ;
V_564 = ( unsigned short ) V_3 ->
V_16 [ V_672 ] . V_284 [ 0 ] ;
V_312 = ( unsigned short ) V_3 ->
V_16 [ V_672 ] . V_284 [ 5 ] ;
V_237 = ( V_564 & 0xFF ) | ( ( V_312 & 0x03 ) << 8 ) ;
V_238 = ( unsigned short ) V_3 ->
V_16 [ V_672 ] . V_284 [ 8 ] ;
V_304 = ( unsigned short ) V_3 ->
V_16 [ V_672 ] . V_284 [ 14 ] << 8 ;
V_304 &= 0x0100 ;
V_304 = V_304 << 2 ;
V_238 |= V_304 ;
V_564 = ( unsigned short ) V_3 ->
V_16 [ V_672 ] . V_284 [ 9 ] ;
}
if ( V_564 & 0x01 )
V_238 |= 0x0100 ;
if ( V_564 & 0x20 )
V_238 |= 0x0200 ;
V_237 += 5 ;
if ( V_208 & V_227 )
V_237 *= 8 ;
else
V_237 *= 9 ;
V_3 -> V_536 = V_237 ;
V_3 -> V_538 = V_237 ;
V_238 ++ ;
V_3 -> V_537 = V_238 ;
V_3 -> V_540 = V_238 ;
}
static void F_73 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_237 = 0 , V_238 , V_208 , V_239 ;
struct V_675 * V_533 = NULL ;
struct V_676 * V_535 = NULL ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_239 = V_3 -> V_4 [ V_200 ] . V_309 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
}
V_3 -> V_677 = 0 ;
V_3 -> V_678 = 50 ;
if ( V_3 -> V_48 & V_244 ) {
F_72 ( V_199 , V_200 , V_236 ,
V_3 ) ;
return;
}
V_238 = 4 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
V_533 = (struct V_675 * ) F_40 ( V_238 ,
V_199 , V_200 , V_236 ,
V_3 ) ;
V_3 -> V_673 = V_533 -> V_673 ;
V_3 -> V_674 = V_533 -> V_674 ;
V_3 -> V_536 = V_533 -> V_536 ;
V_3 -> V_537 = V_533 -> V_537 ;
V_3 -> V_538 = V_533 -> V_539 ;
V_3 -> V_540 = V_533 -> V_541 ;
if ( V_3 -> V_45 == V_272 ) {
V_237 = 1024 ;
V_238 = 768 ;
if ( ! ( V_3 -> V_47 & V_659 ) ) {
if ( V_3 -> V_380 == 357 )
V_238 = 527 ;
else if ( V_3 -> V_380 == 420 )
V_238 = 620 ;
else if ( V_3 -> V_380 == 525 )
V_238 = 775 ;
else if ( V_3 -> V_380 == 600 )
V_238 = 775 ;
else
V_238 = 768 ;
} else
V_238 = 768 ;
} else if ( V_3 -> V_45 == V_347 ) {
V_237 = 1024 ;
V_238 = 768 ;
} else if ( V_3 -> V_45 == V_249 ) {
V_237 = 1280 ;
if ( V_3 -> V_380 == 360 )
V_238 = 768 ;
else if ( V_3 -> V_380 == 375 )
V_238 = 800 ;
else if ( V_3 -> V_380 == 405 )
V_238 = 864 ;
else
V_238 = 1024 ;
} else if ( V_3 -> V_45 == V_544 ) {
V_237 = 1280 ;
V_238 = 1024 ;
} else if ( V_3 -> V_45 == V_250 ) {
V_237 = 1280 ;
if ( V_3 -> V_380 == 350 )
V_238 = 700 ;
else if ( V_3 -> V_380 == 400 )
V_238 = 800 ;
else if ( V_3 -> V_380 == 1024 )
V_238 = 960 ;
else
V_238 = 960 ;
} else if ( V_3 -> V_45 == V_545 ) {
V_237 = 1400 ;
V_238 = 1050 ;
if ( V_3 -> V_380 == 1024 ) {
V_237 = 1280 ;
V_238 = 1024 ;
}
} else if ( V_3 -> V_45 == V_671 ) {
V_237 = 1600 ;
V_238 = 1200 ;
if ( ! ( V_3 -> V_47 & V_659 ) ) {
if ( V_3 -> V_380 == 350 )
V_238 = 875 ;
else if ( V_3 -> V_380 == 400 )
V_238 = 1000 ;
}
}
if ( V_3 -> V_47 & V_251 ) {
V_237 = V_3 -> V_378 ;
V_238 = V_3 -> V_380 ;
}
V_3 -> V_379 = V_237 ;
V_3 -> V_381 = V_238 ;
return;
}
if ( V_3 -> V_48 & ( V_214 ) ) {
V_238 = 4 ;
V_535 = (struct V_676 * ) F_41 ( V_238 ,
V_199 , V_200 , V_236 ,
V_3 ) ;
V_3 -> V_673 = V_535 -> V_673 ;
V_3 -> V_674 = V_535 -> V_674 ;
V_3 -> V_536 = V_535 -> V_536 ;
V_3 -> V_537 = V_535 -> V_537 ;
V_3 -> V_379 = V_535 -> V_679 ;
V_3 -> V_381 = V_535 -> V_680 ;
V_3 -> V_678 = V_535 -> V_678 ;
V_3 -> V_677 = V_535 -> V_681 ;
if ( V_3 -> V_48 & V_252 ) {
if ( V_239 == 0x08 )
V_3 -> V_677 = 0x40 ;
else if ( V_239 == 0x09 )
V_3 -> V_677 = 0x40 ;
else if ( V_239 == 0x12 )
V_3 -> V_677 = 0x40 ;
if ( V_3 -> V_380 == 350 )
V_3 -> V_49 |= V_258 ;
V_237 = V_682 ;
V_238 = V_683 ;
if ( V_3 -> V_48 & V_216 ) {
if ( V_3 -> V_49 & V_258 ) {
V_237 = V_684 ;
V_238 = V_685 ;
if ( ! ( V_208 & V_227 ) ) {
V_237 = V_686 ;
V_238 = V_687 ;
}
}
}
} else if ( V_3 -> V_48 & V_262 ) {
if ( V_3 -> V_49 & V_588 ) {
V_237 = V_688 ;
V_238 = V_689 ;
}
if ( V_3 -> V_49 & V_589 ) {
V_237 = V_690 ;
V_238 = V_691 ;
} else if ( V_3 -> V_49 & V_646 ) {
V_237 = V_692 ;
V_238 = V_693 ;
if ( V_3 -> V_49 & V_591 )
V_237 = V_694 ;
}
} else {
V_237 = V_695 ;
V_238 = V_696 ;
if ( ! ( V_3 -> V_49 & V_267 ) ) {
V_237 = V_697 ;
V_238 = V_698 ;
if ( V_3 -> V_49 & V_591 )
V_237 = V_694 ;
}
}
V_3 -> V_538 = V_237 ;
V_3 -> V_540 = V_238 ;
return;
}
}
static void F_74 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned char V_580 , V_581 , V_384 ;
V_384 = F_49 ( V_236 , V_199 , V_200 ,
V_3 ) ;
F_50 ( V_384 , & V_580 , & V_581 , V_3 ) ;
F_48 ( & V_580 , & V_581 , V_3 ) ;
if ( V_3 -> V_155 & V_598 ) {
F_4 ( V_3 -> V_579 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_579 , 0x0B , V_581 ) ;
F_4 ( V_3 -> V_579 , 0x0A , V_580 ) ;
} else {
F_4 ( V_3 -> V_579 , 0x0A , V_580 ) ;
F_4 ( V_3 -> V_579 , 0x0B , V_581 ) ;
}
F_4 ( V_3 -> V_579 , 0x00 , 0x12 ) ;
if ( V_3 -> V_48 & V_244 )
F_22 ( V_3 -> V_579 , 0x12 , 0x28 ) ;
else
F_22 ( V_3 -> V_579 , 0x12 , 0x08 ) ;
}
static unsigned short F_75 ( unsigned short V_199 ,
unsigned short V_200 , struct V_2 * V_3 )
{
unsigned short V_699 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_201 ;
unsigned short V_208 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_201 = ( V_208 & V_617 ) - V_315 ;
if ( V_201 < 0 )
V_201 = 0 ;
return V_699 [ V_201 ] ;
}
static unsigned short F_76 ( unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_275 , V_700 , V_701 , V_201 , V_240 ,
V_699 [] = { 0x01 , 0x02 , 0x04 } ;
V_701 = V_3 -> V_10 [ V_200 ] . V_314 ;
if ( V_199 <= 0x14 )
V_240 = 0 ;
else
V_240 = V_3 ->
V_13 [ V_236 ] . V_273 ;
V_201 = ( V_701 >> 8 ) & 0xFF ;
V_275 = V_3 -> V_31 [ V_201 ] ;
if ( V_240 & V_308 )
V_275 = V_275 << 1 ;
V_700 = F_75 ( V_199 , V_200 , V_3 ) ;
if ( ( V_199 >= 0x7C ) && ( V_199 <= 0x7E ) ) {
V_275 = V_199 - 0x7C ;
V_700 = V_699 [ V_275 ] ;
V_275 = 0x6B ;
if ( V_240 & V_308 )
V_275 = V_275 << 1 ;
return V_275 * V_700 ;
} else {
return V_275 * V_700 ;
}
}
static void F_77 ( unsigned short V_199 ,
unsigned short V_200 ,
unsigned short V_236 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_702 ;
unsigned char V_275 ;
if ( V_3 -> V_48 & V_216 )
return;
V_702 = F_76 ( V_199 , V_200 , V_236 ,
V_221 , V_3 ) ;
V_275 = ( unsigned char ) ( V_702 & 0xFF ) ;
F_4 ( V_3 -> V_572 , 0x07 , V_275 ) ;
V_275 = ( unsigned char ) ( ( V_702 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_572 , 0x09 , V_275 ) ;
V_275 = ( unsigned char ) ( ( ( V_702 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_572 , 0x03 , V_275 ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_572 , 0x01 , 0x3B ) ;
F_14 ( V_3 -> V_572 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_79 ( unsigned short V_199 , unsigned short V_200 ,
struct V_220 * V_221 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_304 = 0 , V_672 = 0 , V_239 = 0 ;
if ( V_199 > 0x13 ) {
V_672 = V_3 ->
V_13 [ V_236 ] . V_282 ;
V_672 &= V_283 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
}
F_77 ( V_199 , V_200 , V_236 ,
V_221 , V_3 ) ;
F_78 ( V_3 ) ;
for ( V_304 = 4 ; V_304 < 7 ; V_304 ++ )
F_4 ( V_3 -> V_572 , V_304 , 0x0 ) ;
F_4 ( V_3 -> V_572 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_572 , 0x02 , 0x44 ) ;
}
static void F_80 ( unsigned short V_199 , unsigned short V_200 ,
struct V_220 * V_221 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_275 = 0 , V_237 = 0 , V_238 = 0 , V_304 = 0 ,
V_703 = 0 , V_672 = 0 , V_208 , V_239 = 0 ;
if ( V_199 > 0x13 ) {
V_672 = V_3 ->
V_13 [ V_236 ] . V_282 ;
V_672 &= V_283 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
}
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
if ( V_208 & V_307 ) {
V_275 = ( V_3 -> V_536 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_572 , 0x08 , V_275 ) ;
V_275 = ( ( ( V_3 -> V_536 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_14 ( V_3 -> V_572 , 0x09 , ~ 0x0F0 , V_275 ) ;
V_275 = ( V_3 -> V_378 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_572 , 0x0A , V_275 ) ;
V_304 = ( ( V_3 -> V_536 - V_3 -> V_378 ) / 2 ) >> 2 ;
V_703 = V_3 -> V_378 / 2 + 16 ;
V_304 = V_304 >> 1 ;
V_238 = V_703 + V_304 ;
V_304 += V_238 ;
if ( V_3 -> V_48 & V_244 ) {
V_238 = V_3 -> V_16 [ V_672 ] . V_284 [ 4 ] ;
V_238 |= ( ( V_3 ->
V_16 [ V_672 ] . V_284 [ 14 ] &
0xC0 ) << 2 ) ;
V_238 = ( V_238 - 3 ) << 3 ;
V_304 = V_3 -> V_16 [ V_672 ] . V_284 [ 5 ] ;
V_304 &= 0x1F ;
V_275 = V_3 -> V_16 [ V_672 ] . V_284 [ 15 ] ;
V_275 = ( V_275 & 0x04 ) << ( 5 - 2 ) ;
V_304 = ( ( V_304 | V_275 ) - 3 ) << 3 ;
}
V_238 += 4 ;
V_304 += 4 ;
if ( V_304 > ( V_3 -> V_536 / 2 ) )
V_304 = V_3 -> V_536 / 2 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x0B , V_275 ) ;
} else {
V_275 = ( V_3 -> V_536 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_572 , 0x08 , V_275 ) ;
V_275 = ( ( ( V_3 -> V_536 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_14 ( V_3 -> V_572 , 0x09 , ~ 0x0F0 , V_275 ) ;
V_275 = ( V_3 -> V_378 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_572 , 0x0A , V_275 ) ;
V_304 = ( V_3 -> V_536 - V_3 -> V_378 ) >> 2 ;
V_703 = V_3 -> V_378 + 16 ;
V_304 = V_304 >> 1 ;
V_238 = V_703 + V_304 ;
V_304 += V_238 ;
if ( V_3 -> V_48 & V_244 ) {
V_238 = V_3 -> V_16 [ V_672 ] . V_284 [ 3 ] ;
V_238 |= ( ( V_3 ->
V_16 [ V_672 ] . V_284 [ 5 ] &
0xC0 ) << 2 ) ;
V_238 = ( V_238 - 3 ) << 3 ;
V_304 = V_3 -> V_16 [ V_672 ] . V_284 [ 4 ] ;
V_304 &= 0x1F ;
V_275 = V_3 -> V_16 [ V_672 ] . V_284 [ 6 ] ;
V_275 = ( V_275 & 0x04 ) << ( 5 - 2 ) ;
V_304 = ( ( V_304 | V_275 ) - 3 ) << 3 ;
V_238 += 16 ;
V_304 += 16 ;
}
if ( V_304 > V_3 -> V_536 )
V_304 = V_3 -> V_536 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x0B , V_275 ) ;
}
V_237 = ( V_237 & 0x00FF ) | ( V_238 & 0xFF00 ) ;
V_238 = V_703 ;
V_238 = ( V_238 & 0x00FF ) | ( ( V_238 & 0xFF00 ) << 4 ) ;
V_237 |= ( V_238 & 0xFF00 ) ;
V_275 = ( V_237 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_572 , 0x0C , V_275 ) ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x0D , V_275 ) ;
V_304 = ( V_3 -> V_537 - 1 ) ;
V_275 = V_304 & 0x00FF ;
if ( V_3 -> V_270 == 1 ) {
if ( V_3 -> V_48 & 0x0C )
V_275 -- ;
}
F_4 ( V_3 -> V_572 , 0x0E , V_275 ) ;
V_238 = V_3 -> V_380 - 1 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x0F , V_275 ) ;
V_275 = ( ( V_238 & 0xFF00 ) << 3 ) >> 8 ;
V_275 |= ( ( V_304 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_572 , 0x12 , V_275 ) ;
V_237 = V_3 -> V_380 ;
V_238 = V_3 -> V_380 ;
V_304 = V_3 -> V_537 ;
V_238 = ( V_3 -> V_537 + V_3 -> V_380 ) >> 1 ;
V_304 = ( ( V_3 -> V_537 - V_3 -> V_380 ) >> 4 ) + V_238 + 1 ;
if ( V_3 -> V_48 & V_244 ) {
V_238 = V_3 -> V_16 [ V_672 ] . V_284 [ 10 ] ;
V_275 = V_3 -> V_16 [ V_672 ] . V_284 [ 9 ] ;
if ( V_275 & 0x04 )
V_238 |= 0x0100 ;
if ( V_275 & 0x080 )
V_238 |= 0x0200 ;
V_275 = V_3 -> V_16 [ V_672 ] . V_284 [ 14 ] ;
if ( V_275 & 0x08 )
V_238 |= 0x0400 ;
V_275 = V_3 -> V_16 [ V_672 ] . V_284 [ 11 ] ;
V_304 = ( V_304 & 0xFF00 ) | ( V_275 & 0x00FF ) ;
}
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x10 , V_275 ) ;
V_275 = ( ( V_238 & 0xFF00 ) >> 8 ) << 4 ;
V_275 = ( ( V_304 & 0x000F ) | ( V_275 ) ) ;
F_4 ( V_3 -> V_572 , 0x11 , V_275 ) ;
V_237 = 0 ;
if ( V_208 & V_281 )
V_237 |= 0x80 ;
if ( V_208 & V_307 )
V_237 |= 0x40 ;
F_14 ( V_3 -> V_572 , 0x2C , ~ 0x0C0 , V_237 ) ;
}
static unsigned short F_81 ( struct V_2 * V_3 )
{
unsigned long V_237 , V_238 ;
V_238 = ( ( V_3 -> V_537 - V_3 -> V_380 ) * V_3 -> V_673 )
& 0xFFFF ;
V_237 = ( V_3 -> V_540 - V_3 -> V_381 ) * V_3 -> V_674 ;
V_237 = ( V_237 * V_3 -> V_538 ) / V_238 ;
return ( unsigned short ) V_237 ;
}
static void F_82 ( unsigned short V_199 , unsigned short V_200 ,
struct V_220 * V_221 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_562 , V_563 , V_237 , V_238 = 0 , V_304 , V_275 , V_239 ,
V_208 , V_672 ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_239 = V_3 -> V_4 [ V_200 ] . V_309 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
V_672 = V_3 ->
V_13 [ V_236 ] . V_282 ;
V_672 &= V_283 ;
}
if ( ! ( V_3 -> V_48 & V_216 ) )
return;
V_275 = 0xFF ;
F_4 ( V_3 -> V_572 , 0x03 , V_275 ) ;
V_304 = 0x08 ;
if ( V_3 -> V_155 & ( V_156 | V_157 | V_246 ) )
V_208 |= V_227 ;
V_237 = V_3 -> V_378 ;
if ( V_208 & V_307 )
V_237 = V_237 >> 1 ;
V_237 = ( V_237 / V_304 ) - 1 ;
V_238 |= ( ( V_237 & 0x00FF ) << 8 ) ;
V_275 = V_237 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x04 , V_275 ) ;
V_275 = ( V_238 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_48 & V_214 ) {
if ( ! ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) )
V_275 += 2 ;
if ( V_3 -> V_48 & V_252 ) {
if ( V_3 -> V_155 & V_156 ) {
if ( V_3 -> V_253 == V_254 ) {
if ( V_239 == 7 )
V_275 -= 2 ;
}
} else if ( V_239 == 7 ) {
V_275 -= 2 ;
}
}
}
F_4 ( V_3 -> V_572 , 0x05 , V_275 ) ;
F_4 ( V_3 -> V_572 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_48 & V_619 ) ) {
if ( V_3 -> V_48 & V_214 )
V_237 = V_3 -> V_536 ;
else
V_237 = F_81 ( V_3 ) ;
}
if ( V_237 >= V_3 -> V_536 )
V_237 = V_3 -> V_536 ;
if ( V_208 & V_307 )
V_237 = V_237 >> 1 ;
V_237 = ( V_237 / V_304 ) - 5 ;
V_304 = V_237 ;
if ( V_3 -> V_48 & V_252 ) {
V_275 = ( V_238 & 0x00FF ) - 1 ;
if ( ! ( V_208 & V_307 ) ) {
V_275 -= 6 ;
if ( V_3 -> V_49 & V_258 ) {
V_275 -= 4 ;
if ( V_199 > 0x13 )
V_275 -= 10 ;
}
}
} else {
V_238 = ( V_238 & 0xFF00 ) >> 8 ;
V_304 = ( V_304 + V_238 ) >> 1 ;
V_275 = ( V_304 & 0x00FF ) + 2 ;
if ( V_3 -> V_48 & V_214 ) {
V_275 -= 1 ;
if ( ! ( V_208 & V_307 ) ) {
if ( ( V_208 & V_227 ) ) {
V_275 += 4 ;
if ( V_3 -> V_378 >= 800 )
V_275 -= 6 ;
}
}
} else {
if ( ! ( V_208 & V_307 ) ) {
V_275 -= 4 ;
if ( V_3 -> V_45 != V_250 ) {
if ( V_3 -> V_378 >= 800 ) {
V_275 -= 7 ;
if ( V_3 -> V_203 ==
V_315 ) {
if ( V_3 -> V_380 ==
1024 ) {
V_275 += 15 ;
if ( V_3 -> V_45 != V_249 ) {
V_275 +=
7 ;
}
}
}
if ( V_3 -> V_378 >= 1280 ) {
if ( V_3 -> V_45
!= V_250 ) {
if ( V_3 -> V_47
& V_251 ) {
V_275
+= 28 ;
}
}
}
}
}
}
}
}
F_4 ( V_3 -> V_572 , 0x07 , V_275 ) ;
F_4 ( V_3 -> V_572 , 0x08 , 0 ) ;
if ( V_3 -> V_48 & V_214 ) {
if ( V_3 -> V_49 & V_258 ) {
if ( ( V_199 == 0x06 ) || ( V_199 == 0x10 ) || ( V_199
== 0x11 ) || ( V_199 == 0x13 ) || ( V_199
== 0x0F ) ) {
F_4 ( V_3 -> V_572 , 0x07 , 0x5b ) ;
F_4 ( V_3 -> V_572 , 0x08 , 0x03 ) ;
}
if ( ( V_199 == 0x00 ) || ( V_199 == 0x01 ) ) {
if ( V_3 -> V_49 & V_704 ) {
F_4 ( V_3 -> V_572 ,
0x07 , 0x2A ) ;
F_4 ( V_3 -> V_572 ,
0x08 , 0x61 ) ;
} else {
F_4 ( V_3 -> V_572 ,
0x07 , 0x2A ) ;
F_4 ( V_3 -> V_572 ,
0x08 , 0x41 ) ;
F_4 ( V_3 -> V_572 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_199 == 0x02 ) || ( V_199 == 0x03 ) || ( V_199
== 0x07 ) ) {
if ( V_3 -> V_49 & V_704 ) {
F_4 ( V_3 -> V_572 ,
0x07 , 0x54 ) ;
F_4 ( V_3 -> V_572 ,
0x08 , 0x00 ) ;
} else {
F_4 ( V_3 -> V_572 ,
0x07 , 0x55 ) ;
F_4 ( V_3 -> V_572 ,
0x08 , 0x00 ) ;
F_4 ( V_3 -> V_572 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_199 == 0x04 ) || ( V_199 == 0x05 ) || ( V_199
== 0x0D ) || ( V_199 == 0x50 ) ) {
if ( V_3 -> V_49 & V_704 ) {
F_4 ( V_3 -> V_572 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_572 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_572 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_572 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_572 , 0x18 , 0x03 ) ;
F_14 ( V_3 -> V_572 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_572 , 0x09 , 0xFF ) ;
V_238 = V_3 -> V_537 ;
V_562 = V_238 ;
V_304 = 0x121 ;
V_238 = V_3 -> V_380 ;
if ( V_238 == 357 )
V_238 = 350 ;
if ( V_238 == 360 )
V_238 = 350 ;
if ( V_238 == 375 )
V_238 = 350 ;
if ( V_238 == 405 )
V_238 = 400 ;
if ( V_238 == 525 )
V_238 = 480 ;
V_563 = V_238 ;
if ( V_3 -> V_48 & V_215 ) {
if ( V_3 -> V_45 == V_272 ) {
if ( ! ( V_3 -> V_47 & V_659 ) ) {
if ( V_238 == 350 )
V_238 += 5 ;
if ( V_238 == 480 )
V_238 += 5 ;
}
}
}
V_238 -- ;
V_275 = V_238 & 0x00FF ;
V_238 -- ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x10 , V_275 ) ;
V_238 = V_563 ;
V_238 -- ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x0E , V_275 ) ;
if ( V_238 & 0x0100 )
V_304 |= 0x0002 ;
V_237 = 0x000B ;
if ( V_208 & V_281 )
V_237 |= 0x08000 ;
if ( V_238 & 0x0200 )
V_304 |= 0x0040 ;
V_275 = ( V_237 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_572 , 0x0B , V_275 ) ;
if ( V_238 & 0x0400 )
V_304 |= 0x0600 ;
F_4 ( V_3 -> V_572 , 0x11 , 0x00 ) ;
V_237 = V_562 ;
V_237 -= V_238 ;
V_237 = V_237 >> 2 ;
V_562 = V_237 ;
if ( V_239 != 0x09 ) {
V_237 = V_237 << 1 ;
V_238 += V_237 ;
}
if ( V_3 -> V_48 & V_252 ) {
if ( V_3 -> V_155 & V_156 ) {
if ( V_3 -> V_49 & V_649 ) {
V_238 -= 10 ;
} else {
if ( V_3 -> V_49 & V_258 ) {
if ( V_3 -> V_49 & V_267 ) {
if ( V_3 -> V_155 &
V_156 ) {
if ( ! ( V_3 -> V_49 &
( V_589 |
V_588 |
V_649 ) ) )
V_238 += 40 ;
} else {
V_238 += 40 ;
}
}
}
}
} else {
V_238 -= 10 ;
}
} else {
if ( V_3 -> V_49 & V_258 ) {
if ( V_3 -> V_49 & V_267 ) {
if ( V_3 -> V_155 & V_156 ) {
if ( ! ( V_3 -> V_49 &
( V_589 |
V_588 |
V_649 ) ) )
V_238 += 40 ;
} else {
V_238 += 40 ;
}
}
}
}
V_237 = V_562 ;
V_237 = V_237 >> 2 ;
V_237 ++ ;
V_237 += V_238 ;
V_562 = V_237 ;
if ( ( V_3 -> V_49 & V_267 ) ) {
if ( V_238 <= 513 ) {
if ( V_237 >= 513 )
V_238 = 513 ;
}
}
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x0C , V_275 ) ;
V_238 -- ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x10 , V_275 ) ;
if ( V_238 & 0x0100 )
V_304 |= 0x0008 ;
if ( V_238 & 0x0200 )
F_14 ( V_3 -> V_572 , 0x0B , 0x0FF , 0x20 ) ;
V_238 ++ ;
if ( V_238 & 0x0100 )
V_304 |= 0x0004 ;
if ( V_238 & 0x0200 )
V_304 |= 0x0080 ;
if ( V_238 & 0x0400 )
V_304 |= 0x0C00 ;
V_238 = V_562 ;
V_275 = V_238 & 0x00FF ;
V_275 &= 0x0F ;
F_4 ( V_3 -> V_572 , 0x0D , V_275 ) ;
if ( V_238 & 0x0010 )
V_304 |= 0x2000 ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_572 , 0x0A , V_275 ) ;
V_275 = ( V_304 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_572 , 0x17 , V_275 ) ;
V_237 = V_208 ;
V_275 = ( V_237 & 0xFF00 ) >> 8 ;
V_275 = ( V_275 >> 1 ) & 0x09 ;
if ( V_3 -> V_155 & ( V_156 | V_157 | V_246 ) )
V_275 |= 0x01 ;
F_4 ( V_3 -> V_572 , 0x16 , V_275 ) ;
F_4 ( V_3 -> V_572 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_572 , 0x12 , 0 ) ;
if ( V_3 -> V_47 & V_705 )
V_275 = 0x80 ;
else
V_275 = 0x00 ;
F_4 ( V_3 -> V_572 , 0x1A , V_275 ) ;
return;
}
static void F_83 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_207 , V_279 , V_237 , V_238 , V_304 , V_275 , V_562 , V_563 ,
V_208 , V_239 , V_706 ;
unsigned char * V_707 ;
unsigned long V_708 , V_709 , V_710 , V_312 , V_711 ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_239 = V_3 -> V_4 [ V_200 ] . V_309 ;
V_706 = V_3 -> V_4 [ V_200 ] . V_327 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
V_706 = V_3 -> V_13 [ V_236 ] .
V_328 ;
}
V_237 = 0 ;
if ( ! ( V_3 -> V_48 & V_259 ) )
V_237 |= 0x0800 ;
if ( ! ( V_3 -> V_48 & V_260 ) )
V_237 |= 0x0400 ;
if ( V_3 -> V_48 & V_261 )
V_237 |= 0x0200 ;
if ( ! ( V_3 -> V_49 & V_267 ) )
V_237 |= 0x1000 ;
if ( V_3 -> V_48 & V_252 )
V_237 |= 0x0100 ;
if ( V_3 -> V_49 & ( V_589 | V_588 ) )
V_237 &= 0xfe00 ;
V_237 = ( V_237 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_604 , 0x0 , V_237 ) ;
V_707 = V_3 -> V_110 ;
if ( V_3 -> V_49 & V_267 )
V_707 = V_3 -> V_112 ;
if ( V_3 -> V_48 & V_252 ) {
V_707 = V_3 -> V_114 ;
if ( V_3 -> V_48 & V_216 )
V_707 = V_3 -> V_118 ;
if ( V_3 -> V_257 & V_258 )
V_707 = V_3 -> V_116 ;
if ( ! ( V_208 & V_227 ) )
V_707 = V_3 -> V_120 ;
}
if ( V_3 -> V_48 & V_262 ) {
if ( V_3 -> V_49 & V_646 )
V_707 = V_3 -> V_126 ;
if ( V_3 -> V_49 & V_589 )
V_707 = V_3 -> V_124 ;
if ( V_3 -> V_49 & V_588 )
V_707 = V_3 -> V_122 ;
}
for ( V_207 = 0x01 , V_279 = 0 ; V_207 <= 0x2D ; V_207 ++ , V_279 ++ )
F_4 ( V_3 -> V_604 , V_207 , V_707 [ V_279 ] ) ;
for ( V_207 = 0x39 ; V_207 <= 0x45 ; V_207 ++ , V_279 ++ )
F_4 ( V_3 -> V_604 , V_207 , V_707 [ V_279 ] ) ;
if ( V_3 -> V_48 & V_214 )
F_14 ( V_3 -> V_604 , 0x3A , 0x1F , 0x00 ) ;
V_275 = V_3 -> V_677 ;
V_275 &= 0x80 ;
F_14 ( V_3 -> V_604 , 0x0A , 0xFF , V_275 ) ;
if ( V_3 -> V_48 & V_252 )
V_237 = 950 ;
if ( V_3 -> V_49 & V_267 )
V_237 = 520 ;
else
V_237 = 440 ;
if ( V_3 -> V_381 <= V_237 ) {
V_237 -= V_3 -> V_381 ;
V_237 = V_237 >> 2 ;
V_237 = ( V_237 & 0x00FF ) | ( ( V_237 & 0x00FF ) << 8 ) ;
V_562 = V_237 ;
V_275 = ( V_237 & 0xFF00 ) >> 8 ;
V_275 += ( unsigned short ) V_707 [ 0 ] ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
if ( V_3 -> V_48 & ( V_259
| V_260 | V_261
| V_262 ) ) {
V_304 = V_3 -> V_378 ;
if ( V_304 >= 1024 ) {
V_275 = 0x17 ;
if ( V_3 -> V_49 & V_267 )
V_275 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_604 , 0x01 , V_275 ) ;
V_237 = V_562 ;
V_275 = ( V_237 & 0xFF00 ) >> 8 ;
V_275 += V_707 [ 1 ] ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
if ( ( V_3 -> V_48 & ( V_259
| V_260 | V_261
| V_262 ) ) ) {
V_304 = V_3 -> V_378 ;
if ( V_304 >= 1024 ) {
V_275 = 0x1D ;
if ( V_3 -> V_49 & V_267 )
V_275 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_604 , 0x02 , V_275 ) ;
}
V_304 = V_3 -> V_538 ;
if ( F_71 ( V_3 ) )
V_304 = V_304 >> 1 ;
V_304 -= 2 ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x1B , V_275 ) ;
V_275 = ( V_304 & 0xFF00 ) >> 8 ;
F_14 ( V_3 -> V_604 , 0x1D , ~ 0x0F , V_275 ) ;
V_304 = V_3 -> V_538 >> 1 ;
V_562 = V_304 ;
V_304 += 7 ;
if ( V_3 -> V_48 & V_252 )
V_304 -= 4 ;
V_275 = V_304 & 0x00FF ;
V_275 = V_275 << 4 ;
F_14 ( V_3 -> V_604 , 0x22 , 0x0F , V_275 ) ;
V_238 = V_707 [ V_279 ] | ( ( V_707 [ V_279 + 1 ] ) << 8 ) ;
V_238 += V_304 ;
V_563 = V_238 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x24 , V_275 ) ;
V_275 = ( V_238 & 0xFF00 ) >> 8 ;
V_275 = V_275 << 4 ;
F_14 ( V_3 -> V_604 , 0x25 , 0x0F , V_275 ) ;
V_238 = V_563 ;
V_238 = V_238 + 8 ;
if ( V_3 -> V_48 & V_252 ) {
V_238 = V_238 - 4 ;
V_304 = V_238 ;
}
V_275 = ( V_238 & 0x00FF ) << 4 ;
F_14 ( V_3 -> V_604 , 0x29 , 0x0F , V_275 ) ;
V_279 += 2 ;
V_304 += ( V_707 [ V_279 ] | ( ( V_707 [ V_279 + 1 ] ) << 8 ) ) ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x27 , V_275 ) ;
V_275 = ( ( V_304 & 0xFF00 ) >> 8 ) << 4 ;
F_14 ( V_3 -> V_604 , 0x28 , 0x0F , V_275 ) ;
V_304 += 8 ;
if ( V_3 -> V_48 & V_252 )
V_304 -= 4 ;
V_275 = V_304 & 0xFF ;
V_275 = V_275 << 4 ;
F_14 ( V_3 -> V_604 , 0x2A , 0x0F , V_275 ) ;
V_304 = V_562 ;
V_279 += 2 ;
V_275 = V_707 [ V_279 ] | ( ( V_707 [ V_279 + 1 ] ) << 8 ) ;
V_304 -= V_275 ;
V_275 = V_304 & 0x00FF ;
V_275 = V_275 << 4 ;
F_14 ( V_3 -> V_604 , 0x2D , 0x0F , V_275 ) ;
V_304 -= 11 ;
if ( ! ( V_3 -> V_48 & V_214 ) ) {
V_237 = F_81 ( V_3 ) ;
V_304 = V_237 - 1 ;
}
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x2E , V_275 ) ;
V_238 = V_3 -> V_381 ;
if ( V_3 -> V_380 == 360 )
V_238 = 746 ;
if ( V_3 -> V_380 == 375 )
V_238 = 746 ;
if ( V_3 -> V_380 == 405 )
V_238 = 853 ;
if ( V_3 -> V_48 & V_214 ) {
if ( V_3 -> V_155 &
( V_156 | V_157 | V_246 ) ) {
if ( ! ( V_3 -> V_49 &
( V_589 | V_588 ) ) )
V_238 = V_238 >> 1 ;
} else
V_238 = V_238 >> 1 ;
}
V_238 -= 2 ;
V_275 = V_238 & 0x00FF ;
if ( V_3 -> V_48 & V_252 ) {
if ( V_3 -> V_155 & V_156 ) {
if ( V_3 -> V_49 & V_649 ) {
if ( V_3 -> V_48 & V_216 ) {
if ( V_199 == 0x2f )
V_275 += 1 ;
}
}
} else {
if ( V_3 -> V_48 & V_216 ) {
if ( V_199 == 0x2f )
V_275 += 1 ;
}
}
}
F_4 ( V_3 -> V_604 , 0x2F , V_275 ) ;
V_275 = ( V_304 & 0xFF00 ) >> 8 ;
V_275 |= ( ( V_238 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_48 & V_252 ) ) {
if ( V_3 -> V_155 & V_156 ) {
if ( V_3 -> V_49 & V_649 ) {
V_275 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_260 ) )
V_275 |= 0x20 ;
}
} else {
V_275 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_260 ) )
V_275 |= 0x20 ;
}
}
F_4 ( V_3 -> V_604 , 0x30 , V_275 ) ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
V_238 = V_3 -> V_381 ;
V_304 = V_238 - 2 ;
if ( V_3 -> V_48 & V_214 ) {
if ( ! ( V_3 -> V_49 & ( V_589
| V_588 ) ) )
V_238 = V_238 >> 1 ;
}
if ( V_3 -> V_155 & ( V_157 | V_246 ) ) {
V_275 = 0 ;
if ( V_304 & 0x0400 )
V_275 |= 0x20 ;
if ( V_238 & 0x0400 )
V_275 |= 0x40 ;
F_4 ( V_3 -> V_579 , 0x10 , V_275 ) ;
}
V_275 = ( ( ( V_238 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_604 , 0x46 , V_275 ) ;
V_275 = ( V_238 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x47 , V_275 ) ;
}
V_238 = V_238 & 0x00FF ;
if ( ! ( V_208 & V_307 ) ) {
V_304 = V_3 -> V_378 ;
if ( V_304 >= V_3 -> V_379 ) {
V_238 |= 0x2000 ;
V_237 &= 0x00FF ;
}
}
V_304 = 0x0101 ;
if ( V_3 -> V_48 & V_214 ) {
if ( V_3 -> V_378 >= 1024 ) {
V_304 = 0x1920 ;
if ( V_3 -> V_378 >= 1280 ) {
V_304 = 0x1420 ;
V_238 = V_238 & 0xDFFF ;
}
}
}
if ( ! ( V_238 & 0x2000 ) ) {
if ( V_208 & V_307 )
V_304 = ( V_304 & 0xFF00 ) | ( ( V_304 & 0x00FF ) << 1 ) ;
V_562 = V_238 ;
V_709 = V_3 -> V_378 ;
V_710 = ( V_304 & 0xFF00 ) >> 8 ;
V_708 = V_709 * V_710 ;
V_711 = V_304 & 0x00FF ;
V_708 = V_708 / V_711 ;
V_711 = 8 * 1024 ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
V_711 = V_711 * 8 ;
}
V_708 = V_708 * V_711 ;
V_711 = V_3 -> V_379 ;
V_312 = V_708 % V_711 ;
V_709 = V_708 / V_711 ;
if ( V_312 != 0 )
V_709 += 1 ;
V_237 = ( unsigned short ) V_709 ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
V_304 = ( ( V_237 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_238 = V_562 ;
V_238 = ( unsigned short ) ( ( ( V_709 & 0x0000FF00 ) & 0x1F00 )
| ( V_238 & 0x00FF ) ) ;
V_237 = ( unsigned short ) ( ( ( V_709 & 0x000000FF ) << 8 )
| ( V_237 & 0x00FF ) ) ;
V_275 = ( V_237 & 0xFF00 ) >> 8 ;
} else {
V_275 = ( V_237 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_604 , 0x44 , V_275 ) ;
V_275 = ( V_238 & 0xFF00 ) >> 8 ;
F_14 ( V_3 -> V_604 , 0x45 , ~ 0x03F , V_275 ) ;
V_275 = V_304 & 0x00FF ;
if ( V_238 & 0x2000 )
V_275 = 0 ;
if ( ! ( V_3 -> V_48 & V_215 ) )
V_275 |= 0x18 ;
F_14 ( V_3 -> V_604 , 0x46 , ~ 0x1F , V_275 ) ;
if ( V_3 -> V_49 & V_267 ) {
V_238 = 0x0382 ;
V_304 = 0x007e ;
} else {
V_238 = 0x0369 ;
V_304 = 0x0061 ;
}
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x4b , V_275 ) ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x4c , V_275 ) ;
V_275 = ( ( V_304 & 0xFF00 ) >> 8 ) & 0x03 ;
V_275 = V_275 << 2 ;
V_275 |= ( ( V_238 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_48 & V_262 ) {
V_275 |= 0x10 ;
if ( V_3 -> V_49 & V_589 )
V_275 |= 0x20 ;
if ( V_3 -> V_49 & V_588 )
V_275 |= 0x60 ;
}
F_4 ( V_3 -> V_604 , 0x4d , V_275 ) ;
V_275 = F_8 ( V_3 -> V_604 , 0x43 ) ;
F_4 ( V_3 -> V_604 , 0x43 , ( unsigned short ) ( V_275 - 3 ) ) ;
if ( ! ( V_3 -> V_49 & ( V_589 | V_588 ) ) ) {
if ( V_3 -> V_49 & V_591 ) {
V_707 = V_712 ;
for ( V_207 = 0x1c , V_279 = 0 ; V_207 <= 0x30 ; V_207 ++ , V_279 ++ ) {
F_4 ( V_3 -> V_604 , V_207 ,
V_707 [ V_279 ] ) ;
}
F_4 ( V_3 -> V_604 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_155 & V_246 ) {
if ( V_3 -> V_49 & V_641 )
F_14 ( V_3 -> V_604 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_49 & V_641 ) {
V_237 = ( unsigned char ) F_8 ( V_3 -> V_604 ,
0x01 ) ;
V_237 -- ;
F_15 ( V_3 -> V_604 , 0x01 , V_237 ) ;
F_15 ( V_3 -> V_604 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_48 & V_252 ) {
if ( ! ( V_3 -> V_48 & V_216 ) )
F_4 ( V_3 -> V_604 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_48 & V_214 )
return;
}
static void F_84 ( unsigned short V_199 , unsigned short V_200 ,
struct V_220 * V_221 ,
unsigned short V_236 ,
struct V_2 * V_3 )
{
unsigned short V_562 , V_563 , V_703 , V_237 , V_238 , V_304 , V_275 ,
V_205 , V_713 , V_600 , V_239 , V_208 , V_672 ;
struct V_714 * V_715 = NULL ;
if ( V_199 <= 0x13 ) {
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
V_239 = V_3 -> V_4 [ V_200 ] . V_309 ;
} else {
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_239 = V_3 -> V_10 [ V_200 ] . V_241 ;
V_672 = V_3 -> V_13 [ V_236 ] .
V_282 ;
V_672 &= V_283 ;
}
if ( ! ( V_3 -> V_48 & V_215 ) )
return;
V_238 = V_3 -> V_379 ;
if ( F_71 ( V_3 ) )
V_238 = V_238 >> 1 ;
V_238 -= 1 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x2C , V_275 ) ;
V_275 = ( V_238 & 0xFF00 ) >> 8 ;
V_275 = V_275 << 4 ;
F_14 ( V_3 -> V_604 , 0x2B , 0x0F , V_275 ) ;
V_275 = 0x01 ;
if ( V_3 -> V_45 == V_249 ) {
if ( V_3 -> V_203 == V_315 ) {
if ( V_3 -> V_378 >= 1024 ) {
V_275 = 0x02 ;
if ( V_3 -> V_47 & V_659 )
V_275 = 0x01 ;
}
}
}
F_4 ( V_3 -> V_604 , 0x0B , V_275 ) ;
V_238 = V_3 -> V_381 ;
V_562 = V_238 ;
V_238 -- ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x03 , V_275 ) ;
V_275 = ( ( V_238 & 0xFF00 ) >> 8 ) & 0x07 ;
F_14 ( V_3 -> V_604 , 0x0C , ~ 0x07 , V_275 ) ;
V_304 = V_3 -> V_540 - 1 ;
V_563 = V_304 + 1 ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x19 , V_275 ) ;
V_275 = ( V_304 & 0xFF00 ) >> 8 ;
V_275 = V_275 << 5 ;
F_4 ( V_3 -> V_604 , 0x1A , V_275 ) ;
F_14 ( V_3 -> V_604 , 0x09 , 0xF0 , 0x00 ) ;
F_14 ( V_3 -> V_604 , 0x0A , 0xF0 , 0x00 ) ;
F_14 ( V_3 -> V_604 , 0x17 , 0xFB , 0x00 ) ;
F_14 ( V_3 -> V_604 , 0x18 , 0xDF , 0x00 ) ;
V_238 = 5 ;
V_715 = (struct V_714 * ) F_40 ( V_238 , V_199 ,
V_200 , V_236 , V_3 ) ;
V_205 = V_3 -> V_45 ;
V_205 &= V_401 ;
if ( ( V_205 == V_272 ) || ( V_205 == V_347 ) ) {
V_238 = 1024 ;
V_304 = 768 ;
} else if ( ( V_205 == V_249 ) ||
( V_205 == V_544 ) ) {
V_238 = 1280 ;
V_304 = 1024 ;
} else if ( V_205 == V_545 ) {
V_238 = 1400 ;
V_304 = 1050 ;
} else {
V_238 = 1600 ;
V_304 = 1200 ;
}
if ( V_3 -> V_47 & V_390 ) {
V_238 = V_3 -> V_379 ;
V_304 = V_3 -> V_381 ;
}
V_703 = V_238 ;
V_237 = V_3 -> V_540 ;
V_3 -> V_571 = V_715 -> V_571 ;
V_3 -> V_573 = V_715 -> V_573 ;
V_3 -> V_575 = V_715 -> V_575 ;
V_3 -> V_576 = V_715 -> V_576 ;
V_238 = V_3 -> V_575 ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x05 , V_275 ) ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x06 , V_275 ) ;
V_600 = ( ( V_304 & 0xFF00 ) >> 8 ) & 0x07 ;
V_713 = ( ( V_238 & 0xFF00 ) >> 8 ) & 0x07 ;
V_205 = V_600 ;
V_205 = V_205 << 3 ;
V_205 |= V_713 ;
F_4 ( V_3 -> V_604 , 0x02 , V_205 ) ;
F_46 ( & V_237 , & V_238 , V_3 ) ;
V_304 = V_238 ;
V_237 = V_3 -> V_540 ;
V_238 = V_3 -> V_576 ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x04 , V_275 ) ;
V_275 = ( V_238 & 0xFF00 ) >> 8 ;
V_275 = V_275 << 4 ;
V_275 |= ( V_304 & 0x000F ) ;
F_4 ( V_3 -> V_604 , 0x01 , V_275 ) ;
V_304 = V_703 ;
V_237 = V_3 -> V_538 ;
V_238 = V_3 -> V_571 ;
V_238 &= 0x0FFF ;
if ( F_71 ( V_3 ) ) {
V_237 = V_237 >> 1 ;
V_238 = V_238 >> 1 ;
V_304 = V_304 >> 1 ;
}
if ( V_3 -> V_155 & V_157 )
V_238 += 1 ;
if ( V_3 -> V_155 & V_246 )
V_238 += 1 ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x1F , V_275 ) ;
V_275 = ( ( V_238 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_604 , 0x20 , V_275 ) ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x23 , V_275 ) ;
V_275 = ( V_304 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_604 , 0x25 , V_275 ) ;
F_46 ( & V_237 , & V_238 , V_3 ) ;
V_304 = V_237 ;
V_237 = V_3 -> V_538 ;
V_238 = V_3 -> V_573 ;
if ( F_71 ( V_3 ) ) {
V_237 = V_237 >> 1 ;
V_238 = V_238 >> 1 ;
V_304 = V_304 >> 1 ;
}
if ( V_3 -> V_155 & V_157 )
V_238 += 1 ;
V_304 += V_238 ;
if ( V_304 >= V_237 )
V_304 -= V_237 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x1C , V_275 ) ;
V_275 = ( V_238 & 0xFF00 ) >> 8 ;
V_275 = V_275 << 4 ;
F_14 ( V_3 -> V_604 , 0x1D , ~ 0x0F0 , V_275 ) ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_604 , 0x21 , V_275 ) ;
if ( ! ( V_3 -> V_47 & V_659 ) ) {
if ( V_3 -> V_380 == 525 ) {
if ( V_3 -> V_155 & ( V_264 | V_265
| V_156 | V_157
| V_246 ) ) {
V_275 = 0xC6 ;
} else
V_275 = 0xC4 ;
F_4 ( V_3 -> V_604 , 0x2f , V_275 ) ;
F_4 ( V_3 -> V_604 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_380 == 420 ) {
if ( V_3 -> V_155 & ( V_264 | V_265
| V_156 | V_157
| V_246 ) ) {
V_275 = 0x4F ;
} else
V_275 = 0x4E ;
F_4 ( V_3 -> V_604 , 0x2f , V_275 ) ;
}
}
}
static struct V_716 * F_85 ( unsigned short V_304 ,
struct V_2 * V_3 )
{
unsigned short V_237 , V_238 , V_207 ;
struct V_716 * V_717 ;
if ( V_304 == 0 ) {
V_237 = V_3 -> V_378 ;
V_238 = V_3 -> V_379 ;
} else {
V_237 = V_3 -> V_380 ;
V_238 = V_3 -> V_381 ;
}
if ( V_237 < V_238 )
return & V_718 [ 0 ] ;
else if ( V_237 == V_238 )
return & V_719 [ 0 ] ;
else
V_717 = V_720 ;
if ( V_3 -> V_49 & V_267 )
V_717 = V_721 ;
if ( V_3 -> V_48 & V_262 ) {
if ( V_3 -> V_49 & V_646 )
V_717 = V_722 ;
if ( V_3 -> V_49 & V_589 )
V_717 = V_723 ;
if ( V_3 -> V_49 & V_588 )
V_717 = V_724 ;
}
if ( V_3 -> V_48 & V_252 )
V_717 = V_725 ;
V_207 = 0 ;
while ( V_717 [ V_207 ] . V_726 != 0xFFFF ) {
if ( V_717 [ V_207 ] . V_726 == V_237 )
break;
V_207 ++ ;
}
return & V_717 [ V_207 ] ;
}
static void F_86 ( struct V_2 * V_3 )
{
unsigned short V_207 , V_279 ;
struct V_716 * V_717 ;
if ( ! ( V_3 -> V_155 & V_246 ) )
return;
#ifndef F_87
F_15 ( V_3 -> V_604 , 0x4E , 0xEB ) ;
#else
V_717 = F_85 ( 0 , V_3 ) ;
for ( V_207 = 0x80 , V_279 = 0 ; V_207 <= 0xBF ; V_207 ++ , V_279 ++ )
F_4 ( V_3 -> V_604 , V_207 , V_717 -> V_554 [ V_279 ] ) ;
if ( ( V_3 -> V_48 & V_214 ) &&
( ! ( V_3 -> V_48 & V_252 ) ) ) {
V_717 = F_85 ( 1 , V_3 ) ;
for ( V_207 = 0xC0 , V_279 = 0 ; V_207 < 0xFF ; V_207 ++ , V_279 ++ )
F_4 ( V_3 -> V_604 ,
V_207 ,
V_717 -> V_554 [ V_279 ] ) ;
}
if ( ( V_3 -> V_48 & V_214 ) &&
( ! ( V_3 -> V_48 & V_252 ) ) )
F_14 ( V_3 -> V_604 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_14 ( V_3 -> V_604 , 0x4E , ~ 0x14 , 0x10 ) ;
#endif
}
static void F_88 ( unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_207 ;
unsigned char * V_386 ;
unsigned short V_208 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
F_4 ( V_3 -> V_727 , 0x00 , 0x00 ) ;
if ( V_3 -> V_49 & V_267 ) {
F_4 ( V_3 -> V_727 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_727 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_727 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_727 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_48 & V_214 ) )
return;
if ( V_3 -> V_49 & V_641 ) {
F_4 ( V_3 -> V_727 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_727 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_727 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_48 & V_252 ) || ( V_3 -> V_48
& V_262 ) ) {
if ( V_3 -> V_49 & V_646 )
return;
V_386 = V_3 -> V_128 ;
if ( V_3 -> V_257 & V_258 ) {
V_386 = V_3 -> V_130 ;
if ( ! ( V_208 & V_227 ) )
V_386 = V_3 -> V_132 ;
}
if ( V_3 -> V_49 & V_589 )
V_386 = V_3 -> V_134 ;
if ( V_3 -> V_49 & V_588 )
V_386 = V_3 -> V_136 ;
for ( V_207 = 0 ; V_207 <= 0x3E ; V_207 ++ )
F_4 ( V_3 -> V_727 , V_207 , V_386 [ V_207 ] ) ;
if ( V_3 -> V_155 & V_246 ) {
if ( V_3 -> V_49 & V_589 )
F_4 ( V_3 -> V_727 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_89 ( unsigned short V_199 , unsigned short V_200 ,
unsigned short V_236 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_237 , V_304 , V_238 , V_208 , V_275 , V_312 ;
unsigned long V_710 , V_709 , V_728 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
V_275 = V_3 -> V_674 ;
F_4 ( V_3 -> V_579 , 0x13 , V_275 ) ;
V_238 = V_3 -> V_673 ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_579 , 0x14 , V_275 ) ;
V_312 = ( ( V_238 & 0xFF00 ) >> 8 ) << 7 ;
V_304 = V_3 -> V_536 - 1 ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_579 , 0x16 , V_275 ) ;
V_275 = ( ( V_304 & 0xFF00 ) >> 8 ) << 3 ;
V_312 |= V_275 ;
V_304 = V_3 -> V_537 - 1 ;
if ( ! ( V_3 -> V_48 & V_214 ) )
V_304 -= 5 ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_579 , 0x17 , V_275 ) ;
V_275 = V_312 | ( ( V_304 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_579 , 0x15 , V_275 ) ;
F_22 ( V_3 -> V_579 , 0x0D , 0x08 ) ;
V_304 = V_3 -> V_48 ;
V_238 = V_3 -> V_378 ;
if ( V_208 & V_307 )
V_238 = V_238 >> 1 ;
if ( F_71 ( V_3 ) )
V_238 = V_238 >> 1 ;
if ( V_304 & V_252 ) {
V_275 = 0 ;
if ( V_238 <= 1024 )
V_275 = 0xA0 ;
if ( V_238 == 1280 )
V_275 = 0xC0 ;
} else if ( V_304 & V_214 ) {
V_275 = 0xA0 ;
if ( V_238 <= 800 )
V_275 = 0x80 ;
} else {
V_275 = 0x80 ;
if ( V_3 -> V_48 & V_215 ) {
V_275 = 0 ;
if ( V_238 > 800 )
V_275 = 0x60 ;
}
}
if ( V_3 -> V_49 & ( V_589 | V_588 ) ) {
V_275 = 0x00 ;
if ( V_3 -> V_378 == 1280 )
V_275 = 0x40 ;
if ( V_3 -> V_378 == 1024 )
V_275 = 0x20 ;
}
F_14 ( V_3 -> V_579 , 0x0E , ~ 0xEF , V_275 ) ;
V_710 = V_3 -> V_381 ;
if ( V_304 & V_252 ) {
if ( ! ( V_275 & 0xE000 ) )
V_238 = V_238 >> 1 ;
}
V_304 = V_3 -> V_678 ;
V_275 = V_304 & 0x00FF ;
F_4 ( V_3 -> V_579 , 0x18 , V_275 ) ;
V_709 = V_3 -> V_380 ;
V_304 |= 0x04000 ;
if ( V_709 <= V_710 ) {
V_304 = ( V_304 & ( ~ 0x4000 ) ) ;
V_709 = V_3 -> V_380 ;
} else {
V_709 -= V_710 ;
}
V_728 = ( V_709 * 256 * 1024 ) % V_710 ;
V_709 = ( V_709 * 256 * 1024 ) / V_710 ;
V_710 = V_709 ;
if ( V_728 != 0 )
V_710 ++ ;
V_275 = ( unsigned short ) ( V_710 & 0x000000FF ) ;
F_4 ( V_3 -> V_579 , 0x1B , V_275 ) ;
V_275 = ( unsigned short ) ( ( V_710 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_579 , 0x1A , V_275 ) ;
V_238 = ( unsigned short ) ( V_710 >> 16 ) ;
V_275 = V_238 & 0x00FF ;
V_275 = V_275 << 4 ;
V_275 |= ( ( V_304 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_579 , 0x19 , V_275 ) ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
V_275 = 0x0028 ;
F_4 ( V_3 -> V_579 , 0x1C , V_275 ) ;
V_237 = V_3 -> V_378 ;
if ( V_208 & V_307 )
V_237 = V_237 >> 1 ;
if ( F_71 ( V_3 ) )
V_237 = V_237 >> 1 ;
if ( V_3 -> V_48 & V_215 ) {
if ( V_237 > 800 )
V_237 -= 800 ;
} else {
if ( V_3 -> V_378 > 800 ) {
if ( V_3 -> V_378 == 1024 )
V_237 = ( V_237 * 25 / 32 ) - 1 ;
else
V_237 = ( V_237 * 20 / 32 ) - 1 ;
}
}
V_237 -= 1 ;
V_275 = ( V_237 & 0xFF00 ) >> 8 ;
V_275 = ( ( V_275 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_579 , 0x1E , V_275 ) ;
V_275 = ( V_237 & 0x00FF ) ;
F_4 ( V_3 -> V_579 , 0x1D , V_275 ) ;
if ( V_3 -> V_48 & ( V_214 | V_252 ) ) {
if ( V_3 -> V_378 > 800 )
F_22 ( V_3 -> V_579 , 0x1E , 0x08 ) ;
}
V_275 = 0x0036 ;
if ( V_3 -> V_48 & V_214 ) {
if ( ! ( V_3 -> V_49 & ( V_591
| V_589 | V_588
| V_649 ) ) ) {
V_275 |= 0x0001 ;
if ( ( V_3 -> V_48 & V_216 )
&& ( ! ( V_3 -> V_49
& V_258 ) ) )
V_275 &= ( ~ 0x0001 ) ;
}
}
F_14 ( V_3 -> V_579 , 0x1F , 0x00C0 , V_275 ) ;
V_238 = V_3 -> V_538 ;
if ( F_71 ( V_3 ) )
V_238 = V_238 >> 1 ;
V_238 = ( V_238 >> 1 ) - 2 ;
V_275 = ( ( V_238 & 0x0700 ) >> 8 ) << 3 ;
F_14 ( V_3 -> V_579 , 0x21 , 0x00C0 , V_275 ) ;
V_275 = V_238 & 0x00FF ;
F_4 ( V_3 -> V_579 , 0x22 , V_275 ) ;
}
if ( V_3 -> V_729 == 0 )
F_74 ( V_199 , V_200 , V_236 ,
V_3 ) ;
}
static void F_90 ( struct V_2 * V_3 )
{
F_14 ( V_3 -> V_211 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_91 ( unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_730 , V_731 ;
V_730 = V_3 -> V_732 ;
V_731 = V_3 -> V_732 + 1 ;
if ( V_3 -> V_203 == V_233 ) {
if ( ! ( V_3 -> V_48 & ( V_216 | V_733
| V_734 ) ) ) {
F_90 ( V_3 ) ;
}
}
return;
}
static void F_92 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_223 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_93 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_223 , 0x63 , 0xBF , 0x00 ) ;
}
void F_63 ( unsigned short V_713 , unsigned short V_555 ,
struct V_2 * V_3 )
{
unsigned char V_668 , V_275 ;
V_668 = F_8 ( V_3 -> V_223 , 0x4A ) ;
V_713 &= 0x23 ;
V_555 &= 0x23 ;
F_15 ( V_3 -> V_223 , 0x4A , ~ V_713 ) ;
if ( V_713 & 0x20 ) {
V_275 = ( V_555 >> 4 ) & 0x02 ;
F_14 ( V_3 -> V_223 , 0xB4 , ~ 0x02 , V_275 ) ;
}
V_275 = F_8 ( V_3 -> V_223 , 0x48 ) ;
V_275 = F_59 ( V_275 ) ;
V_275 &= ~ V_713 ;
V_275 |= V_555 ;
F_4 ( V_3 -> V_223 , 0x48 , V_275 ) ;
}
void F_65 ( unsigned short V_713 , unsigned short V_555 ,
struct V_2 * V_3 )
{
unsigned char V_668 , V_275 ;
unsigned short V_735 , V_736 ;
V_735 = V_713 ;
V_736 = V_555 ;
V_735 &= 0x20 ;
V_736 &= 0x20 ;
V_735 >>= 3 ;
V_736 >>= 3 ;
if ( V_713 & 0x20 ) {
V_275 = ( V_555 >> 4 ) & 0x02 ;
F_14 ( V_3 -> V_223 , 0xB4 , ~ 0x02 , V_275 ) ;
}
F_14 ( V_3 -> V_223 , 0xB4 , ~ V_735 , V_736 ) ;
V_668 = F_8 ( V_3 -> V_223 , 0x4A ) ;
V_713 &= 0x03 ;
V_555 &= 0x03 ;
V_713 <<= 2 ;
V_555 <<= 2 ;
F_15 ( V_3 -> V_223 , 0x4A , ~ V_713 ) ;
F_14 ( V_3 -> V_223 , 0x48 , ~ V_713 , V_555 ) ;
}
unsigned short F_94 ( struct V_2 * V_3 )
{
unsigned short V_201 ;
V_201 = F_8 ( V_3 -> V_223 , 0x36 ) ;
if ( V_201 < sizeof( V_164 )
/ sizeof( struct V_737 ) )
return V_201 ;
return 0 ;
}
void F_64 ( unsigned short V_555 ,
struct V_2 * V_3 )
{
unsigned short V_201 ;
V_201 = F_94 ( V_3 ) ;
if ( V_555 == 1 )
F_95 ( V_3 -> V_163 [ V_201 ] . V_738 ) ;
if ( V_555 == 2 )
F_95 ( V_3 -> V_163 [ V_201 ] . V_739 ) ;
if ( V_555 == 3 )
F_95 ( V_3 -> V_163 [ V_201 ] . V_740 ) ;
if ( V_555 == 4 )
F_95 ( V_3 -> V_163 [ V_201 ] . V_741 ) ;
}
unsigned char F_96 ( unsigned short V_199 ,
unsigned short V_200 , struct V_2 * V_3 )
{
unsigned short V_354 , V_377 , V_700 , V_208 , V_303 ,
V_742 ;
V_303 = F_29 ( V_199 , V_200 , V_3 ) ;
if ( V_199 <= 0x13 ) {
V_354 = V_3 -> V_33 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_33 [ V_303 ] . V_306 ;
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
} else {
V_354 = V_3 -> V_36 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_36 [ V_303 ] . V_306 ;
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
}
if ( ! ( V_208 & V_227 ) ) {
V_354 /= 9 ;
V_354 *= 8 ;
}
if ( V_199 > 0x13 ) {
if ( ( V_199 > 0x13 ) && ( V_208 & V_307 ) )
V_354 *= 2 ;
if ( ( V_199 > 0x13 ) && ( V_208 & V_281 ) )
V_377 *= 2 ;
}
V_742 = F_94 ( V_3 ) ;
if ( V_354 > ( V_3 -> V_163 [ V_742 ] . V_743 ) )
return 0 ;
if ( V_377 > ( V_3 -> V_163 [ V_742 ] . V_744 ) )
return 0 ;
if ( V_199 > 0x13 ) {
if ( ( V_354 != ( V_3 -> V_163 [ V_742 ] .
V_743 ) ) ||
( V_377 != ( V_3 -> V_163 [ V_742 ] .
V_744 ) ) ) {
V_700 = F_75 ( V_199 ,
V_200 ,
V_3 ) ;
if ( V_700 > 2 )
return 0 ;
}
}
return 1 ;
}
void F_34 ( struct V_2 * V_3 )
{
unsigned char V_275 ;
V_275 = F_8 ( V_3 -> V_223 , 0x37 ) ;
V_275 = ( V_275 & 1 ) << 6 ;
F_14 ( V_3 -> V_211 , 0x06 , ~ 0x40 , V_275 ) ;
F_14 ( V_3 -> V_211 , 0x09 , ~ 0xc0 , V_275 | 0x80 ) ;
}
void F_26 ( struct V_2 * V_3 )
{
unsigned char V_275 ;
V_275 = F_8 ( V_3 -> V_223 , 0x37 ) ;
V_275 = ( V_275 & 3 ) << 6 ;
F_14 ( V_3 -> V_211 , 0x06 , ~ 0xc0 , V_275 & 0x80 ) ;
F_14 ( V_3 -> V_211 , 0x09 , ~ 0xc0 , V_275 | 0x80 ) ;
}
static void F_97 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned char V_275 , V_217 ;
unsigned short V_354 , V_377 , V_208 , V_303 , V_742 ;
unsigned short V_745 , V_746 , V_747 , V_748 , V_749 ;
unsigned short V_750 , V_751 , V_752 , V_753 , V_754 ;
unsigned short V_755 ;
V_742 = F_94 ( V_3 ) ;
V_275 = ( unsigned char ) ( ( V_3 -> V_163 [ V_742 ] .
V_756 &
( V_757 << 8 ) ) >> 8 ) ;
V_275 &= V_757 ;
V_217 = ( unsigned char ) F_10 ( V_3 -> V_296 ) ;
F_6 ( ( V_217 & 0x3F ) | V_275 , V_3 -> V_219 ) ;
V_275 = ( unsigned char ) ( V_3 -> V_163 [ V_742 ] .
V_756 & V_757 ) ;
F_14 ( V_3 -> V_211 , 0x35 , ~ 0x80 , V_275 & 0x80 ) ;
F_14 ( V_3 -> V_211 , 0x30 , ~ 0x20 , ( V_275 & 0x40 ) >> 1 ) ;
F_34 ( V_3 ) ;
V_303 = F_29 ( V_199 , V_200 , V_3 ) ;
if ( V_199 <= 0x13 ) {
V_354 = V_3 -> V_33 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_33 [ V_303 ] . V_306 ;
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
} else {
V_354 = V_3 -> V_36 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_36 [ V_303 ] . V_306 ;
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
}
if ( ! ( V_208 & V_227 ) )
V_354 = V_354 * 8 / 9 ;
V_745 = V_3 -> V_163 [ V_742 ] . V_745 ;
V_746 = V_354 + ( V_3 -> V_163 [ V_742 ] . V_743
- V_354 ) / 2 ;
if ( ( V_199 <= 0x13 ) && ( V_208 & V_307 ) )
V_746 -= V_354 / 4 ;
if ( V_746 > V_745 )
V_746 -= V_745 ;
V_747 = V_746 + V_3 -> V_163 [ V_742 ] . V_758 ;
if ( V_747 > V_745 )
V_747 -= V_745 ;
V_748 = V_747 + V_3 -> V_163 [ V_742 ] . V_759 ;
if ( V_748 > V_745 )
V_748 -= V_745 ;
V_749 = V_746 + V_745
- V_3 -> V_163 [ V_742 ] . V_743 ;
V_750 = V_3 -> V_163 [ V_742 ] . V_750 ;
V_751 = V_377 + ( V_3 -> V_163 [ V_742 ] . V_744
- V_377 ) / 2 ;
if ( ( V_199 > 0x13 ) && ( V_208 & V_281 ) )
V_751 += V_377 / 2 ;
if ( V_751 > V_750 )
V_751 -= V_750 ;
V_752 = V_751 + V_3 -> V_163 [ V_742 ] . V_760 ;
if ( V_752 > V_750 )
V_752 -= V_750 ;
V_753 = V_752 + V_3 -> V_163 [ V_742 ] . V_761 ;
if ( V_753 > V_750 )
V_753 -= V_750 ;
V_754 = V_751 + V_750
- V_3 -> V_163 [ V_742 ] . V_744 ;
V_275 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x11 ) ;
F_4 ( V_3 -> V_223 , 0x11 , V_275 & 0x7f ) ;
if ( ! ( V_208 & V_227 ) )
F_22 ( V_3 -> V_211 , 0x1 , 0x1 ) ;
V_755 = ( V_745 >> 3 ) - 5 ;
F_14 ( V_3 -> V_211 , 0x0B , ~ 0x03 , ( V_755 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_223 , 0x0 , ( V_755 & 0xFF ) ) ;
V_755 = ( V_746 >> 3 ) - 1 ;
F_14 ( V_3 -> V_211 , 0x0B , ~ 0x30 , ( V_755 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_223 , 0x2 , ( V_755 & 0xFF ) ) ;
V_755 = ( V_749 >> 3 ) - 1 ;
F_14 ( V_3 -> V_211 , 0x0C , ~ 0x03 , ( V_755 & 0xC0 ) >> 6 ) ;
F_14 ( V_3 -> V_223 , 0x05 , ~ 0x80 , ( V_755 & 0x20 ) << 2 ) ;
F_14 ( V_3 -> V_223 , 0x03 , ~ 0x1F , V_755 & 0x1F ) ;
V_755 = ( V_747 >> 3 ) + 2 ;
F_14 ( V_3 -> V_211 , 0x0B , ~ 0xC0 , ( V_755 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_223 , 0x4 , ( V_755 & 0xFF ) ) ;
V_755 -- ;
F_14 ( V_3 -> V_211 , 0x2F , ~ 0x03 , ( V_755 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_211 , 0x2E , ( V_755 & 0xFF ) ) ;
V_755 = ( V_748 >> 3 ) + 2 ;
F_14 ( V_3 -> V_211 , 0x0C , ~ 0x04 , ( V_755 & 0x20 ) >> 3 ) ;
F_14 ( V_3 -> V_223 , 0x05 , ~ 0x1F , V_755 & 0x1F ) ;
V_755 -- ;
F_14 ( V_3 -> V_211 , 0x2F , ~ 0xFC , V_755 << 2 ) ;
V_755 = V_750 - 2 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x01 , ( V_755 & 0x400 ) >> 10 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x20 , ( V_755 & 0x200 ) >> 4 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x01 , ( V_755 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_223 , 0x06 , ( V_755 & 0xFF ) ) ;
V_755 = V_751 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x04 , ( V_755 & 0x400 ) >> 8 ) ;
F_14 ( V_3 -> V_223 , 0x09 , ~ 0x20 , ( V_755 & 0x200 ) >> 4 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x08 , ( V_755 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_223 , 0x15 , ( V_755 & 0xFF ) ) ;
V_755 = V_754 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x10 , ( V_755 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_223 , 0x16 , ( V_755 & 0xFF ) ) ;
V_755 = V_752 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x08 , ( V_755 & 0x400 ) >> 7 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x80 , ( V_755 & 0x200 ) >> 2 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x04 , ( V_755 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_223 , 0x10 , ( V_755 & 0xFF ) ) ;
F_14 ( V_3 -> V_211 , 0x3F , ~ 0x03 , ( V_755 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_211 , 0x34 , ( V_755 >> 1 ) & 0xFF ) ;
F_14 ( V_3 -> V_223 , 0x33 , ~ 0x01 , V_755 & 0x01 ) ;
V_755 = V_753 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x20 , ( V_755 & 0x10 ) << 1 ) ;
F_14 ( V_3 -> V_223 , 0x11 , ~ 0x0F , V_755 & 0x0F ) ;
F_14 ( V_3 -> V_211 , 0x3F , ~ 0xFC , ( V_755 << 2 ) & 0x7C ) ;
for ( V_275 = 0 , V_755 = 0 ; V_275 < 3 ; V_275 ++ ) {
F_14 ( V_3 -> V_211 , 0x31 , ~ 0x30 , V_755 ) ;
F_4 ( V_3 -> V_211 ,
0x2B ,
V_3 -> V_163 [ V_742 ] .
V_762 ) ;
F_4 ( V_3 -> V_211 ,
0x2C ,
V_3 -> V_163 [ V_742 ] .
V_763 ) ;
V_755 += 0x10 ;
}
if ( ! ( V_208 & V_227 ) ) {
F_10 ( V_3 -> V_228 ) ;
F_6 ( 0x13 , V_3 -> V_229 ) ;
F_6 ( 0x00 , V_3 -> V_229 ) ;
F_10 ( V_3 -> V_228 ) ;
F_6 ( 0x20 , V_3 -> V_229 ) ;
F_10 ( V_3 -> V_228 ) ;
}
}
static void F_98 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned char V_275 , V_217 ;
unsigned short V_354 , V_377 , V_208 , V_303 , V_742 ;
unsigned short V_745 , V_746 , V_747 , V_748 , V_749 ;
unsigned short V_750 , V_751 , V_752 , V_753 , V_754 ;
unsigned short V_755 ;
V_742 = F_94 ( V_3 ) ;
V_275 = ( unsigned char ) ( ( V_3 -> V_163 [ V_742 ] .
V_756 &
( V_757 << 8 ) ) >> 8 ) ;
V_275 &= V_757 ;
V_217 = ( unsigned char ) F_10 ( V_3 -> V_296 ) ;
F_6 ( ( V_217 & 0x3F ) | V_275 , V_3 -> V_219 ) ;
V_275 = ( unsigned char ) ( V_3 -> V_163 [ V_742 ] .
V_756 & V_757 ) ;
F_14 ( V_3 -> V_211 , 0x35 , ~ 0x80 , V_275 & 0x80 ) ;
F_14 ( V_3 -> V_211 , 0x30 , ~ 0x20 , ( V_275 & 0x40 ) >> 1 ) ;
F_26 ( V_3 ) ;
V_303 = F_29 ( V_199 , V_200 , V_3 ) ;
if ( V_199 <= 0x13 ) {
V_354 = V_3 -> V_33 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_33 [ V_303 ] . V_306 ;
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
} else {
V_354 = V_3 -> V_36 [ V_303 ] . V_305 ;
V_377 = V_3 -> V_36 [ V_303 ] . V_306 ;
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
}
if ( ! ( V_208 & V_227 ) )
V_354 = V_354 * 8 / 9 ;
V_745 = V_3 -> V_163 [ V_742 ] . V_745 ;
V_746 = V_354 + ( V_3 -> V_163 [ V_742 ] . V_743
- V_354 ) / 2 ;
if ( ( V_199 <= 0x13 ) && ( V_208 & V_307 ) )
V_746 -= V_354 / 4 ;
if ( V_746 > V_745 )
V_746 -= V_745 ;
V_747 = V_746 + V_3 -> V_163 [ V_742 ] . V_758 ;
if ( V_747 > V_745 )
V_747 -= V_745 ;
V_748 = V_747 + V_3 -> V_163 [ V_742 ] . V_759 ;
if ( V_748 > V_745 )
V_748 -= V_745 ;
V_749 = V_746 + V_745
- V_3 -> V_163 [ V_742 ] . V_743 ;
V_750 = V_3 -> V_163 [ V_742 ] . V_750 ;
V_751 = V_377 + ( V_3 -> V_163 [ V_742 ] . V_744
- V_377 ) / 2 ;
if ( ( V_199 > 0x13 ) && ( V_208 & V_281 ) )
V_751 += V_377 / 2 ;
if ( V_751 > V_750 )
V_751 -= V_750 ;
V_752 = V_751 + V_3 -> V_163 [ V_742 ] . V_760 ;
if ( V_752 > V_750 )
V_752 -= V_750 ;
V_753 = V_752 + V_3 -> V_163 [ V_742 ] .
V_761 ;
if ( V_753 > V_750 )
V_753 -= V_750 ;
V_754 = V_751 + V_750
- V_3 -> V_163 [ V_742 ] . V_744 ;
V_275 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x11 ) ;
F_4 ( V_3 -> V_223 , 0x11 , V_275 & 0x7f ) ;
if ( ! ( V_208 & V_227 ) )
F_22 ( V_3 -> V_211 , 0x1 , 0x1 ) ;
V_755 = ( V_745 >> 3 ) - 5 ;
F_14 ( V_3 -> V_211 , 0x0B , ~ 0x03 , ( V_755 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_223 , 0x0 , ( V_755 & 0xFF ) ) ;
V_755 = ( V_746 >> 3 ) - 1 ;
F_14 ( V_3 -> V_211 , 0x0B , ~ 0x30 , ( V_755 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_223 , 0x2 , ( V_755 & 0xFF ) ) ;
V_755 = ( V_749 >> 3 ) - 1 ;
F_14 ( V_3 -> V_211 , 0x0C , ~ 0x03 , ( V_755 & 0xC0 ) >> 6 ) ;
F_14 ( V_3 -> V_223 , 0x05 , ~ 0x80 , ( V_755 & 0x20 ) << 2 ) ;
F_14 ( V_3 -> V_223 , 0x03 , ~ 0x1F , V_755 & 0x1F ) ;
V_755 = ( V_747 >> 3 ) + 2 ;
F_14 ( V_3 -> V_211 , 0x0B , ~ 0xC0 , ( V_755 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_223 , 0x4 , ( V_755 & 0xFF ) ) ;
V_755 -- ;
F_14 ( V_3 -> V_211 , 0x2F , ~ 0x03 , ( V_755 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_211 , 0x2E , ( V_755 & 0xFF ) ) ;
V_755 = ( V_748 >> 3 ) + 2 ;
F_14 ( V_3 -> V_211 , 0x0C , ~ 0x04 , ( V_755 & 0x20 ) >> 3 ) ;
F_14 ( V_3 -> V_223 , 0x05 , ~ 0x1F , V_755 & 0x1F ) ;
V_755 -- ;
F_14 ( V_3 -> V_211 , 0x2F , ~ 0xFC , V_755 << 2 ) ;
V_755 = V_750 - 2 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x01 , ( V_755 & 0x400 ) >> 10 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x20 , ( V_755 & 0x200 ) >> 4 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x01 , ( V_755 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_223 , 0x06 , ( V_755 & 0xFF ) ) ;
V_755 = V_751 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x04 , ( V_755 & 0x400 ) >> 8 ) ;
F_14 ( V_3 -> V_223 , 0x09 , ~ 0x20 , ( V_755 & 0x200 ) >> 4 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x08 , ( V_755 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_223 , 0x15 , ( V_755 & 0xFF ) ) ;
V_755 = V_754 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x10 , ( V_755 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_223 , 0x16 , ( V_755 & 0xFF ) ) ;
V_755 = V_752 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x08 , ( V_755 & 0x400 ) >> 7 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x80 , ( V_755 & 0x200 ) >> 2 ) ;
F_14 ( V_3 -> V_223 , 0x07 , ~ 0x04 , ( V_755 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_223 , 0x10 , ( V_755 & 0xFF ) ) ;
F_14 ( V_3 -> V_211 , 0x35 , ~ 0x07 , ( V_755 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_211 , 0x34 , V_755 & 0xFF ) ;
V_755 = V_753 - 1 ;
F_14 ( V_3 -> V_211 , 0x0A , ~ 0x20 , ( V_755 & 0x10 ) << 1 ) ;
F_14 ( V_3 -> V_223 , 0x11 , ~ 0x0F , V_755 & 0x0F ) ;
F_14 ( V_3 -> V_211 , 0x3F , ~ 0xFC , ( V_755 << 2 ) & 0xFC ) ;
for ( V_275 = 0 , V_755 = 0 ; V_275 < 3 ; V_275 ++ ) {
F_14 ( V_3 -> V_211 , 0x31 , ~ 0x30 , V_755 ) ;
F_4 ( V_3 -> V_211 ,
0x2B ,
V_3 -> V_163 [ V_742 ] .
V_762 ) ;
F_4 ( V_3 -> V_211 ,
0x2C ,
V_3 -> V_163 [ V_742 ] .
V_763 ) ;
V_755 += 0x10 ;
}
if ( ! ( V_208 & V_227 ) ) {
F_10 ( V_3 -> V_228 ) ;
F_6 ( 0x13 , V_3 -> V_229 ) ;
F_6 ( 0x00 , V_3 -> V_229 ) ;
F_10 ( V_3 -> V_228 ) ;
F_6 ( 0x20 , V_3 -> V_229 ) ;
F_10 ( V_3 -> V_228 ) ;
}
}
static unsigned char F_99 ( struct V_2 * V_3 )
{
unsigned short V_237 ;
V_237 = V_3 -> V_48 ;
if ( V_237 & V_618 )
return 0 ;
else if ( V_237 & ( V_619 | V_631 | V_630 ) )
return 1 ;
return 0 ;
}
static unsigned char F_100 ( struct V_2 * V_3 )
{
unsigned short V_238 , V_205 ;
V_238 = V_3 -> V_257 & ( V_764 | V_765 ) ;
V_205 = ~ ( ( unsigned short ) F_8 ( V_3 -> V_572 , 0x2E ) ) ;
if ( V_238 & ( V_766 | V_764 ) ) {
if ( ! ( V_205 & 0x08 ) )
return 0 ;
}
if ( ! ( V_238 & ( V_767 | V_765 ) ) )
return 0 ;
if ( V_205 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_101 ( struct V_2 * V_3 )
{
unsigned short V_238 , V_205 ;
V_238 = V_3 -> V_257 & ( V_766 | V_767 ) ;
V_205 = ~ ( ( unsigned short ) F_8 ( V_3 -> V_572 , 0x2E ) ) ;
if ( V_238 & ( V_766 | V_764 ) ) {
if ( ! ( V_205 & 0x08 ) )
return 0 ;
}
if ( ! ( V_238 & ( V_767 | V_765 ) ) )
return 0 ;
if ( V_205 & 0x01 )
return 1 ;
return 0 ;
}
void F_102 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_205 = 0 ;
if ( V_3 -> V_257 == V_569 )
return;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
V_205 = 0x3F ;
if ( ! ( V_3 -> V_48 &
( V_619 | V_630 ) ) ) {
if ( V_3 -> V_48 & V_213 ) {
if ( V_3 -> V_48 & V_618 ) {
V_205 = 0x7F ;
if ( ! ( V_3 -> V_48 & V_213 ) )
V_205 = 0xBF ;
if ( V_3 -> V_257 & V_765 )
V_205 &= 0xBF ;
if ( V_3 -> V_257 & V_764 )
V_205 &= 0x7F ;
}
}
}
F_15 ( V_3 -> V_579 , 0x1F , V_205 ) ;
if ( V_3 -> V_155 & ( V_157 | V_246 ) ) {
if ( ( ( V_3 -> V_48 & ( V_215 | V_213 ) ) )
|| ( F_100 ( V_3 ) )
|| ( F_99 ( V_3 ) ) )
F_22 ( V_3 -> V_579 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_257 & V_764 ) || ( V_3 -> V_48
& ( V_619 | V_213
| V_630 ) ) ) {
if ( V_3 -> V_257 & V_768 )
F_92 ( V_221 , V_3 ) ;
F_66 ( V_221 , V_3 ) ;
}
if ( V_3 -> V_48 & V_213 ) {
if ( ( V_3 -> V_257 & V_764 ) || ( V_3 -> V_48
& V_213 ) )
F_15 ( V_3 -> V_572 , 0x1e , 0xdf ) ;
}
F_15 ( V_3 -> V_211 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_48 & ( V_630 | V_618 ) ) )
F_15 ( V_3 -> V_604 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_257 & V_765 ) ||
( V_3 -> V_48 &
( V_619 | V_630 ) ) ||
( ( ! ( V_3 -> V_48 & V_213 ) ) &&
( V_3 -> V_48 &
( V_244 | V_215 | V_214 ) ) ) )
F_22 ( V_3 -> V_572 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_257 & V_765 ) ||
( V_3 -> V_48 &
( V_619 | V_630 ) ) ||
( ! ( V_3 -> V_48 & V_213 ) ) ||
( V_3 -> V_48 &
( V_244 | V_215 | V_214 ) ) ) {
V_205 = F_8 ( V_3 -> V_572 , 0x00 ) ;
F_22 ( V_3 -> V_572 , 0x00 , 0x10 ) ;
F_15 ( V_3 -> V_572 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_572 , 0x00 , V_205 ) ;
}
} else {
if ( V_3 -> V_48 & ( V_215 | V_214 ) ) {
F_22 ( V_3 -> V_572 , 0x00 , 0x80 ) ;
F_15 ( V_3 -> V_572 , 0x1E , 0xDF ) ;
F_15 ( V_3 -> V_211 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_48 & ( V_619 | V_213
| V_630 ) )
F_66 ( V_221 , V_3 ) ;
}
}
static unsigned short F_103 ( struct V_2 * V_3 )
{
unsigned short V_238 = 0 ;
if ( V_3 -> V_49 & V_267 )
V_238 = 2 ;
if ( V_3 -> V_49 & V_649 )
V_238 = 4 ;
if ( V_3 -> V_49 & V_646 )
V_238 = 6 ;
if ( V_3 -> V_49 & V_589 )
V_238 = 8 ;
if ( V_3 -> V_49 & V_588 )
V_238 = 10 ;
if ( V_3 -> V_49 & V_258 )
V_238 ++ ;
return V_238 ;
}
static void F_104 ( unsigned short * V_238 , unsigned char * V_599 ,
unsigned char * V_600 , struct V_2 * V_3 )
{
* V_238 = 0 ;
* V_599 = 0 ;
* V_600 = 0 ;
if ( V_3 -> V_49 & V_267 )
* V_238 = 1 ;
if ( V_3 -> V_49 & V_641 )
* V_238 = 2 ;
if ( V_3 -> V_49 & V_642 )
* V_238 = 3 ;
if ( V_3 -> V_49 & V_591 ) {
* V_238 = 4 ;
if ( V_3 -> V_49 & V_641 )
* V_238 = 5 ;
}
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
if ( ( ! ( V_3 -> V_48 & V_216 ) ) || ( V_3 -> V_49
& V_258 ) ) {
* V_238 += 8 ;
* V_599 += 1 ;
}
}
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) )
( * V_600 ) ++ ;
}
static void F_105 ( struct V_2 * V_3 )
{
unsigned short V_201 ;
unsigned char V_205 , V_555 , V_713 ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
if ( V_3 -> V_48 & ( V_215 | V_213
| V_214 | V_244 ) ) {
V_555 = 0 ;
V_713 = 0 ;
V_201 = F_103 ( V_3 ) ;
V_555 = V_3 -> V_165 [ V_201 ] ;
if ( V_3 -> V_155 & ( V_264 | V_265
| V_156 | V_157
| V_246 ) )
V_555 = V_3 -> V_167 [ V_201 ] ;
if ( V_3 -> V_48 & V_618 )
V_555 = V_555 >> 4 ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
V_201 = F_44 ( V_3 ) ;
V_713 = V_3 -> V_158 [ V_201 ] .
V_769 ;
if ( ! ( V_3 -> V_48 & V_213 ) )
V_555 = V_713 ;
}
V_555 &= 0x0F ;
V_713 &= 0xF0 ;
V_205 = F_8 ( V_3 -> V_572 , 0x2D ) ;
if ( V_3 -> V_48 & ( V_244 | V_215
| V_214 ) ) {
V_205 &= 0xF0 ;
V_205 |= V_555 ;
}
if ( V_3 -> V_48 & V_213 ) {
V_205 &= 0x0F ;
V_205 |= V_713 ;
}
F_4 ( V_3 -> V_572 , 0x2D , V_205 ) ;
}
} else if ( V_3 -> V_243 == 1 ) {
V_555 = 0 ;
V_713 = 0 ;
if ( V_3 -> V_48 & V_215 ) {
V_205 = V_3 -> V_158 [
F_44 ( V_3 ) ] .
V_769 ;
V_205 &= 0x0f ;
V_205 = V_205 << 4 ;
F_14 ( V_3 -> V_572 , 0x2D , 0x0f ,
V_205 ) ;
}
}
}
static void F_106 ( unsigned short V_304 ,
struct V_2 * V_3 )
{
unsigned short V_275 ;
V_275 = F_8 ( V_3 -> V_223 , 0x37 ) ;
if ( V_275 & V_705 ) {
F_14 ( V_3 -> V_572 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_304 & 0x00C0 ) ) ) ;
F_14 ( V_3 -> V_572 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_14 ( V_3 -> V_572 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_304 & 0x00C0 ) ) ) ;
F_14 ( V_3 -> V_572 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_107 ( unsigned short V_304 ,
struct V_2 * V_3 )
{
if ( V_304 & V_770 )
F_14 ( V_3 -> V_604 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_304 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_14 ( V_3 -> V_604 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_304 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_108 ( struct V_2 * V_3 )
{
unsigned short V_201 ;
V_201 = F_44 ( V_3 ) ;
F_15 ( V_3 -> V_579 , 0x30 , 0x8F ) ;
F_109 ( V_3 ) ;
F_22 ( V_3 -> V_579 , 0x30 , 0x20 ) ;
F_109 ( V_3 ) ;
F_4 ( V_3 -> V_579 , 0x31 ,
V_3 -> V_158 [ V_201 ] . V_771 ) ;
F_4 ( V_3 -> V_579 , 0x32 ,
V_3 -> V_158 [ V_201 ] . V_772 ) ;
F_4 ( V_3 -> V_579 , 0x33 ,
V_3 -> V_158 [ V_201 ] . V_773 ) ;
F_4 ( V_3 -> V_579 , 0x34 ,
V_3 -> V_158 [ V_201 ] . V_774 ) ;
F_109 ( V_3 ) ;
F_22 ( V_3 -> V_579 , 0x30 , 0x40 ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
unsigned short V_304 ;
V_304 = V_3 -> V_158 [ F_44 ( V_3 ) ] . V_655 ;
if ( V_3 -> V_155 &
( V_264 |
V_265 |
V_156 |
V_157 |
V_246 ) ) {
if ( V_3 -> V_155 &
( V_156 | V_157 | V_246 ) ) {
F_4 ( V_3 -> V_579 , 0x24 ,
( unsigned char ) ( V_304 & 0x1F ) ) ;
}
F_14 ( V_3 -> V_579 , 0x0D ,
~ ( ( V_775 | V_776 ) >> 8 ) ,
( unsigned short ) ( ( V_304 & ( V_775
| V_776 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
if ( V_3 -> V_48 & V_215 )
F_107 ( V_304 , V_3 ) ;
else if ( V_3 -> V_48 & V_213 )
F_106 ( V_304 , V_3 ) ;
if ( V_3 -> V_155 & ( V_157 | V_246 ) ) {
if ( V_304 & V_777 )
F_108 ( V_3 ) ;
}
} else {
F_106 ( V_304 , V_3 ) ;
}
}
static void F_111 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_238 , V_201 ;
unsigned char V_205 ;
if ( V_3 -> V_49 & ( V_589 | V_588 ) )
return;
V_238 = F_103 ( V_3 ) ;
V_238 &= 0xFE ;
if ( V_199 <= 0x13 )
V_201 = V_3 -> V_4 [ V_200 ] . V_778 ;
else
V_201 = V_3 -> V_10 [ V_200 ] . V_779 ;
V_238 += V_201 ;
V_205 = V_780 [ V_238 ] ;
V_205 = V_205 << 4 ;
F_14 ( V_3 -> V_604 , 0x0A , 0x8F , V_205 ) ;
}
static void F_112 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_238 , V_201 ;
unsigned char V_205 ;
V_238 = F_103 ( V_3 ) ;
V_238 &= 0xFE ;
if ( V_199 <= 0x13 )
V_201 = V_3 -> V_4 [ V_200 ] . V_781 ;
else
V_201 = V_3 -> V_10 [ V_200 ] . V_782 ;
V_238 += V_201 ;
V_205 = V_783 [ V_238 ] ;
V_205 = V_205 << 5 ;
F_14 ( V_3 -> V_604 , 0x3A , 0x1F , V_205 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
unsigned short V_238 ;
unsigned char V_599 , V_600 ;
unsigned long V_784 ;
F_104 ( & V_238 , & V_599 , & V_600 , V_3 ) ;
V_784 = V_785 [ V_238 ] ;
F_4 ( V_3 -> V_604 , 0x31 , ( unsigned short ) ( V_784
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_604 , 0x32 , ( unsigned short ) ( ( V_784
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_604 , 0x33 , ( unsigned short ) ( ( V_784
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_604 , 0x34 , ( unsigned short ) ( ( V_784
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_114 ( unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_238 , V_201 ;
unsigned char V_599 , V_600 , V_384 , * V_786 ;
F_104 ( & V_238 , & V_599 , & V_600 , V_3 ) ;
switch ( V_238 ) {
case 0x00 :
case 0x04 :
V_786 = V_787 ;
break;
case 0x01 :
V_786 = V_788 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
V_786 = V_789 ;
break;
case 0x03 :
V_786 = V_790 ;
break;
case 0x08 :
case 0x0C :
V_786 = V_791 ;
break;
case 0x0A :
V_786 = V_792 ;
break;
case 0x0B :
V_786 = V_793 ;
break;
case 0x09 :
V_786 = V_794 ;
break;
default:
return;
}
if ( V_199 <= 0x13 )
V_384 = V_3 -> V_4 [ V_200 ] .
V_795 ;
else
V_384 = V_3 -> V_10 [ V_200 ] .
V_796 ;
if ( V_599 == 0 )
V_201 = V_384 * 4 ;
else
V_201 = V_384 * 7 ;
if ( ( V_599 == 0 ) && ( V_600 == 1 ) ) {
F_4 ( V_3 -> V_604 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_604 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_604 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_604 , 0x38 , V_786 [ V_201 ++ ] ) ;
} else {
F_4 ( V_3 -> V_604 , 0x35 , V_786 [ V_201 ++ ] ) ;
F_4 ( V_3 -> V_604 , 0x36 , V_786 [ V_201 ++ ] ) ;
F_4 ( V_3 -> V_604 , 0x37 , V_786 [ V_201 ++ ] ) ;
F_4 ( V_3 -> V_604 , 0x38 , V_786 [ V_201 ++ ] ) ;
}
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
F_4 ( V_3 -> V_604 , 0x48 , V_786 [ V_201 ++ ] ) ;
F_4 ( V_3 -> V_604 , 0x49 , V_786 [ V_201 ++ ] ) ;
F_4 ( V_3 -> V_604 , 0x4A , V_786 [ V_201 ++ ] ) ;
}
}
static void F_115 ( unsigned short V_199 ,
unsigned short V_200 ,
struct V_2 * V_3 )
{
if ( V_3 -> V_257 & V_569 )
return;
F_105 ( V_3 ) ;
if ( V_3 -> V_48 & ( V_215 | V_213 ) )
F_110 ( V_3 ) ;
if ( V_3 -> V_48 & V_214 ) {
F_113 ( V_3 ) ;
F_114 ( V_199 , V_200 , V_3 ) ;
F_111 ( V_199 , V_200 , V_3 ) ;
if ( V_3 -> V_155 & V_598 )
F_112 ( V_199 , V_200 , V_3 ) ;
}
}
void F_116 ( unsigned short V_199 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_555 ;
short V_599 ;
unsigned char V_205 ;
V_205 = 0 ;
if ( ! ( V_3 -> V_48 & V_619 ) ) {
V_205 = F_8 ( V_3 -> V_572 , 0x00 ) ;
V_205 &= ~ 0x10 ;
V_205 |= 0x40 ;
if ( V_3 -> V_48 & ( V_244 | V_214
| V_215 ) ) {
V_205 = 0x40 ;
if ( V_199 > 0x13 ) {
V_599 = V_3 -> V_203 ;
V_599 -= V_233 ;
if ( V_599 >= 0 ) {
V_205 = ( 0x008 >> V_599 ) ;
if ( V_205 == 0 )
V_205 = 1 ;
V_205 |= 0x040 ;
}
}
if ( V_3 -> V_48 & V_216 )
V_205 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_572 , 0x00 , V_205 ) ;
V_205 = 0x08 ;
V_555 = 0xf0 ;
if ( V_3 -> V_48 & V_619 ) {
F_14 ( V_3 -> V_572 , 0x2e , V_555 , V_205 ) ;
} else {
V_205 = 0x00 ;
V_555 = 0xff ;
if ( V_3 -> V_48 & ( V_244 | V_214
| V_215 | V_213 ) ) {
if ( ( V_3 -> V_48 & V_213 ) &&
( ! ( V_3 -> V_48 & V_630 ) ) ) {
V_555 &= 0xf7 ;
V_205 |= 0x01 ;
F_14 ( V_3 -> V_572 , 0x2e ,
V_555 , V_205 ) ;
} else {
if ( V_3 -> V_48 & V_213 ) {
V_555 &= 0xf7 ;
V_205 |= 0x01 ;
}
if ( V_3 -> V_48 &
( V_244 |
V_214 |
V_215 ) ) {
V_555 &= 0xf8 ;
V_205 = 0x01 ;
if ( ! ( V_3 -> V_48 & V_216 ) )
V_205 |= 0x02 ;
if ( ! ( V_3 -> V_48 &
V_244 ) ) {
V_205 = V_205 ^ 0x05 ;
if ( ! ( V_3 -> V_48 &
V_215 ) )
V_205 = V_205 ^ 0x01 ;
}
if ( ! ( V_3 -> V_48 &
V_618 ) )
V_205 |= 0x08 ;
F_14 ( V_3 -> V_572 ,
0x2e , V_555 , V_205 ) ;
} else {
F_14 ( V_3 -> V_572 ,
0x2e , V_555 , V_205 ) ;
}
}
} else {
F_14 ( V_3 -> V_572 , 0x2e , V_555 ,
V_205 ) ;
}
}
if ( V_3 -> V_48 & ( V_244 | V_214 | V_215
| V_213 ) ) {
V_205 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_203 == V_233 ) && ( ! ( V_3 -> V_48
& V_216 ) ) ) {
V_205 |= 0x010 ;
}
V_205 |= 0x080 ;
if ( V_3 -> V_48 & V_214 ) {
V_205 |= 0x020 ;
if ( V_199 > 0x13 ) {
if ( V_3 -> V_48 & V_633 )
V_205 = V_205 ^ 0x20 ;
}
}
F_14 ( V_3 -> V_579 , 0x0D , ~ 0x0BF , V_205 ) ;
V_205 = 0 ;
if ( V_3 -> V_47 & V_657 )
V_205 |= 0x40 ;
if ( V_3 -> V_48 & V_214 ) {
if ( V_3 -> V_49 & V_329 )
V_205 |= 0x40 ;
}
if ( ( V_3 -> V_45 == V_249 )
|| ( V_3 -> V_45 == V_544 ) )
V_205 |= 0x80 ;
if ( V_3 -> V_45 == V_250 )
V_205 |= 0x80 ;
F_4 ( V_3 -> V_579 , 0x0C , V_205 ) ;
}
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
V_205 = 0 ;
V_555 = 0xfb ;
if ( V_3 -> V_48 & V_618 ) {
V_555 = 0xff ;
if ( V_3 -> V_48 & V_213 )
V_205 |= 0x04 ;
}
F_14 ( V_3 -> V_572 , 0x13 , V_555 , V_205 ) ;
V_205 = 0x00 ;
V_555 = 0xcf ;
if ( ! ( V_3 -> V_48 & V_619 ) ) {
if ( V_3 -> V_48 & V_618 )
V_205 |= 0x30 ;
}
F_14 ( V_3 -> V_572 , 0x2c , V_555 , V_205 ) ;
V_205 = 0 ;
V_555 = 0x3f ;
if ( ! ( V_3 -> V_48 & V_619 ) ) {
if ( V_3 -> V_48 & V_618 )
V_205 |= 0xc0 ;
}
F_14 ( V_3 -> V_579 , 0x21 , V_555 , V_205 ) ;
}
V_205 = 0 ;
V_555 = 0x7f ;
if ( ! ( V_3 -> V_48 & V_213 ) ) {
V_555 = 0xff ;
if ( ! ( V_3 -> V_48 & V_618 ) )
V_205 |= 0x80 ;
}
F_14 ( V_3 -> V_579 , 0x23 , V_555 , V_205 ) ;
if ( V_3 -> V_155 & ( V_157 | V_246 ) ) {
if ( V_3 -> V_47 & V_657 ) {
F_22 ( V_3 -> V_579 , 0x27 , 0x20 ) ;
F_22 ( V_3 -> V_579 , 0x34 , 0x10 ) ;
}
}
}
static void F_117 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_238 ;
V_238 = 0 ;
if ( V_3 -> V_48 & V_213 )
V_238 = 0x08A0 ;
}
void F_118 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_238 ;
V_238 = 0 ;
}
void F_119 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_572 , 0x2f , 0xFF , 0x01 ) ;
}
void F_120 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_572 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_121 ( struct V_2 * V_3 )
{
unsigned short V_614 ;
if ( V_3 -> V_243 == 1 ) {
return 1 ;
} else {
V_614 = F_8 ( V_3 -> V_579 , 0x00 ) ;
if ( ( V_614 == 1 ) || ( V_614 == 2 ) )
return 1 ;
else
return 0 ;
}
}
void F_109 ( struct V_2 * V_3 )
{
unsigned short V_207 ;
V_207 = F_8 ( V_3 -> V_211 , 0x1F ) ;
if ( ! ( V_207 & 0xC0 ) ) {
for ( V_207 = 0 ; V_207 < 0xFFFF ; V_207 ++ ) {
if ( ! ( F_10 ( V_3 -> V_228 ) & 0x08 ) )
break;
}
for ( V_207 = 0 ; V_207 < 0xFFFF ; V_207 ++ ) {
if ( ( F_10 ( V_3 -> V_228 ) & 0x08 ) )
break;
}
}
}
static void F_122 ( struct V_2 * V_3 )
{
unsigned short V_384 , V_275 , V_207 , V_279 ;
return;
if ( ! ( V_3 -> V_48 & V_214 ) ) {
V_275 = 0 ;
for ( V_207 = 0 ; V_207 < 3 ; V_207 ++ ) {
for ( V_279 = 0 ; V_279 < 100 ; V_279 ++ ) {
V_384 = F_10 ( V_3 -> V_228 ) ;
if ( V_275 & 0x01 ) {
if ( ( V_384 & 0x08 ) )
continue;
if ( ! ( V_384 & 0x08 ) )
break;
} else {
if ( ! ( V_384 & 0x08 ) )
continue;
if ( ( V_384 & 0x08 ) )
break;
}
}
V_275 = V_275 ^ 0x01 ;
}
} else {
F_109 ( V_3 ) ;
}
return;
}
unsigned short F_123 ( struct V_220 * V_670 ,
unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
short V_797 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_798 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_236 , V_207 , V_208 , V_201 , V_275 ;
if ( V_199 <= 0x13 )
V_208 = V_3 -> V_4 [ V_200 ] . V_209 ;
else
V_208 = V_3 -> V_10 [ V_200 ] . V_210 ;
if ( V_3 -> V_270 == 1 ) {
if ( V_3 -> V_48 & V_214 ) {
if ( V_208 & V_307 )
return 0 ;
}
}
if ( V_199 < 0x14 )
return 0xFFFF ;
V_201 = F_8 ( V_3 -> V_223 , 0x33 ) ;
V_201 = V_201 >> V_3 -> V_799 ;
V_201 &= 0x0F ;
if ( V_3 -> V_47 & V_251 )
V_201 = 0 ;
if ( V_201 > 0 )
V_201 -- ;
if ( V_3 -> V_257 & V_586 ) {
if ( V_3 -> V_270 == 1 ) {
if ( V_3 -> V_48 & V_214 )
V_201 = 0 ;
}
if ( V_3 -> V_48 & ( V_215 | V_213 ) ) {
if ( V_3 -> V_243 == 0 ) {
if ( V_3 -> V_155 & ( V_264 | V_265
| V_156 | V_157
| V_246 ) )
V_275 = V_798 [
V_3 -> V_45 & 0x0F ] ;
else
V_275 = V_797 [
V_3 -> V_45 & 0x0F ] ;
if ( V_201 > V_275 )
V_201 = V_275 ;
} else {
V_201 = 0 ;
}
}
}
V_236 = V_3 -> V_10 [ V_200 ] . V_800 ;
V_199 = V_3 -> V_13 [ V_236 ] . V_242 ;
if ( V_670 -> V_280 >= V_171 ) {
if ( ( V_3 -> V_13 [ V_236 ] . V_801 == 800 ) &&
( V_3 -> V_13 [ V_236 ] . V_802 == 600 ) ) {
V_201 ++ ;
}
if ( ( V_3 -> V_13 [ V_236 ] . V_801 == 1024 ) &&
( V_3 -> V_13 [ V_236 ] . V_802 == 768 ) ) {
V_201 ++ ;
}
if ( ( V_3 -> V_13 [ V_236 ] . V_801 == 1280 ) &&
( V_3 -> V_13 [ V_236 ] . V_802 == 1024 ) ) {
V_201 ++ ;
}
}
V_207 = 0 ;
do {
if ( V_3 -> V_13 [ V_236 + V_207 ] .
V_242 != V_199 )
break;
V_275 = V_3 -> V_13 [ V_236 + V_207 ] .
V_273 ;
V_275 &= V_617 ;
if ( V_275 < V_3 -> V_203 )
break;
V_207 ++ ;
V_201 -- ;
} while ( V_201 != 0xFFFF );
if ( ! ( V_3 -> V_48 & V_244 ) ) {
if ( V_3 -> V_48 & V_216 ) {
V_275 = V_3 -> V_13 [ V_236 + V_207 - 1 ] .
V_273 ;
if ( V_275 & V_308 )
V_207 ++ ;
}
}
V_207 -- ;
if ( ( V_3 -> V_257 & V_586 ) ) {
V_275 = F_16 ( V_199 , V_200 ,
V_236 , & V_207 , V_3 ) ;
}
return V_236 + V_207 ;
}
static void F_124 ( unsigned short V_199 , unsigned short V_200 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_236 ;
V_3 -> V_257 |= V_586 ;
V_236 = F_123 ( V_221 , V_199 ,
V_200 , V_3 ) ;
F_39 ( V_199 , V_200 , V_3 ) ;
F_42 ( V_199 , V_200 , V_236 , V_3 ) ;
F_43 ( V_199 , V_200 , V_236 ,
V_221 , V_3 ) ;
F_47 ( V_199 , V_200 , V_236 , V_3 ) ;
F_51 ( V_199 , V_200 , V_236 , V_3 ) ;
}
unsigned char F_125 ( unsigned short V_199 ,
struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_238 , V_200 , V_236 ;
V_238 = V_3 -> V_48 ;
V_3 -> V_257 |= V_586 ;
F_58 ( V_199 , & V_200 , V_3 ) ;
V_3 -> V_799 = 4 ;
V_236 = F_123 ( V_221 , V_199 ,
V_200 , V_3 ) ;
F_69 ( V_199 , V_3 ) ;
F_70 ( V_199 , V_200 , V_3 ) ;
F_73 ( V_199 , V_200 , V_236 , V_3 ) ;
F_79 ( V_199 , V_200 , V_221 ,
V_236 , V_3 ) ;
F_80 ( V_199 , V_200 , V_221 ,
V_236 , V_3 ) ;
F_82 ( V_199 , V_200 , V_221 ,
V_236 , V_3 ) ;
F_83 ( V_199 , V_200 , V_236 ,
V_221 , V_3 ) ;
F_84 ( V_199 , V_200 , V_221 ,
V_236 , V_3 ) ;
F_86 ( V_3 ) ;
F_88 ( V_199 , V_200 , V_3 ) ;
F_89 ( V_199 , V_200 , V_236 ,
V_221 , V_3 ) ;
F_74 ( V_199 , V_200 , V_236 , V_3 ) ;
F_91 ( V_199 , V_200 , V_3 ) ;
F_68 ( V_3 ) ;
return 1 ;
}
void F_126 ( struct V_2 * V_3 )
{
unsigned char V_803 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_804 = 0 , V_805 = 0 , V_806 = 0 , V_807 = 0 ;
unsigned char V_808 , V_809 , V_810 ;
unsigned short V_275 ;
unsigned char V_811 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_207 ;
F_4 ( V_3 -> V_211 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_223 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_223 , 0x53 , ( unsigned char ) ( F_8 (
V_3 -> V_223 , 0x53 ) | 0x02 ) ) ;
V_810 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x31 ) ;
V_809 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x63 ) ;
V_804 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x01 ) ;
F_4 ( V_3 -> V_211 , 0x01 , ( unsigned char ) ( V_804 & 0xDF ) ) ;
F_4 ( V_3 -> V_223 , 0x63 , ( unsigned char ) ( V_809 & 0xBF ) ) ;
V_808 = ( unsigned char ) F_8 ( V_3 -> V_223 , 0x17 ) ;
F_4 ( V_3 -> V_223 , 0x17 , ( unsigned char ) ( V_808 | 0x80 ) ) ;
V_805 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x1F ) ;
F_4 ( V_3 -> V_211 , 0x1F , ( unsigned char ) ( V_805 | 0x04 ) ) ;
V_806 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x07 ) ;
F_4 ( V_3 -> V_211 , 0x07 , ( unsigned char ) ( V_806 & 0xFB ) ) ;
V_807 = ( unsigned char ) F_8 ( V_3 -> V_211 , 0x06 ) ;
F_4 ( V_3 -> V_211 , 0x06 , ( unsigned char ) ( V_807 & 0xC3 ) ) ;
F_4 ( V_3 -> V_223 , 0x11 , 0x00 ) ;
for ( V_207 = 0 ; V_207 < 8 ; V_207 ++ )
F_4 ( V_3 -> V_223 , ( unsigned short ) V_207 , V_803 [ V_207 ] ) ;
for ( V_207 = 8 ; V_207 < 11 ; V_207 ++ )
F_4 ( V_3 -> V_223 , ( unsigned short ) ( V_207 + 8 ) ,
V_803 [ V_207 ] ) ;
for ( V_207 = 11 ; V_207 < 13 ; V_207 ++ )
F_4 ( V_3 -> V_223 , ( unsigned short ) ( V_207 + 4 ) ,
V_803 [ V_207 ] ) ;
for ( V_207 = 13 ; V_207 < 16 ; V_207 ++ )
F_4 ( V_3 -> V_211 , ( unsigned short ) ( V_207 - 3 ) ,
V_803 [ V_207 ] ) ;
F_4 ( V_3 -> V_211 , 0x0E , ( unsigned char ) ( V_803 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_211 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_211 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_211 , 0x2C , 0xE1 ) ;
F_6 ( 0x00 , V_3 -> V_376 ) ;
for ( V_207 = 0 ; V_207 < 256 ; V_207 ++ ) {
F_6 ( ( unsigned char ) V_811 [ 0 ] , ( V_3 -> V_376 + 1 ) ) ;
F_6 ( ( unsigned char ) V_811 [ 1 ] , ( V_3 -> V_376 + 1 ) ) ;
F_6 ( ( unsigned char ) V_811 [ 2 ] , ( V_3 -> V_376 + 1 ) ) ;
}
F_122 ( V_3 ) ;
F_122 ( V_3 ) ;
F_122 ( V_3 ) ;
F_95 ( 1 ) ;
F_67 ( V_3 ) ;
V_275 = F_10 ( V_3 -> V_219 ) ;
if ( V_275 & 0x10 )
F_14 ( V_3 -> V_223 , 0x32 , 0xDF , 0x20 ) ;
else
F_14 ( V_3 -> V_223 , 0x32 , 0xDF , 0x00 ) ;
F_6 ( 0x00 , V_3 -> V_376 ) ;
for ( V_207 = 0 ; V_207 < 256 ; V_207 ++ ) {
F_6 ( 0 , ( V_3 -> V_376 + 1 ) ) ;
F_6 ( 0 , ( V_3 -> V_376 + 1 ) ) ;
F_6 ( 0 , ( V_3 -> V_376 + 1 ) ) ;
}
F_4 ( V_3 -> V_211 , 0x01 , V_804 ) ;
F_4 ( V_3 -> V_223 , 0x63 , V_809 ) ;
F_4 ( V_3 -> V_211 , 0x31 , V_810 ) ;
F_4 ( V_3 -> V_223 , 0x53 , ( unsigned char ) ( F_8 (
V_3 -> V_223 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_211 , 0x1F , ( unsigned char ) V_805 ) ;
}
void F_127 ( struct V_220 * V_221 ,
struct V_2 * V_3 )
{
unsigned short V_205 ;
if ( V_3 -> V_257 == V_569 ) {
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
F_62 ( V_221 , V_3 ) ;
return;
} else
return;
}
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
if ( ! ( V_3 -> V_257 & V_764 ) ) {
if ( V_3 -> V_257 & V_766 ) {
F_4 ( V_3 -> V_572 , 0x1E , 0x20 ) ;
} else {
if ( V_3 -> V_48 & V_618 ) {
F_4 ( V_3 -> V_572 ,
0x1E , 0x20 ) ;
}
}
}
if ( ! ( V_3 -> V_257 & V_765 ) ) {
if ( ( V_3 -> V_257 & V_767 ) || ( V_3 -> V_48
& ( V_215 | V_214
| V_244 ) ) ) {
V_205 = ( unsigned char ) F_8 (
V_3 -> V_211 , 0x32 ) ;
V_205 &= 0xDF ;
if ( V_3 -> V_48 & V_216 ) {
if ( ! ( V_3 -> V_48 &
V_244 ) )
V_205 |= 0x20 ;
}
F_4 ( V_3 -> V_211 , 0x32 , V_205 ) ;
F_22 ( V_3 -> V_211 , 0x1E , 0x20 ) ;
V_205 = ( unsigned char ) F_8 (
V_3 -> V_572 , 0x2E ) ;
if ( ! ( V_205 & 0x80 ) )
F_22 ( V_3 -> V_572 ,
0x2E , 0x80 ) ;
F_15 ( V_3 -> V_572 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_257 & ( V_766 | V_767 ) )
|| ( ! ( V_3 -> V_48 & V_619 ) ) ) {
F_14 ( V_3 -> V_604 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_155 & ( V_157 | V_246 ) ) {
if ( ! F_100 ( V_3 ) ) {
if ( F_101 ( V_3 ) ||
( V_3 -> V_48 &
( V_215 | V_213 ) ) )
F_15 (
V_3 -> V_579 ,
0x2A ,
0x7F ) ;
}
F_15 ( V_3 -> V_579 , 0x30 , 0x7F ) ;
}
}
V_205 = 0x00 ;
if ( ! ( V_3 -> V_48 & V_619 ) ) {
V_205 = 0xc0 ;
if ( ! ( V_3 -> V_48 & V_630 ) ) {
if ( V_3 -> V_48 & V_213 ) {
if ( V_3 -> V_48 &
V_618 ) {
V_205 = V_205 & 0x40 ;
if ( V_3 -> V_48 &
V_213 )
V_205 = V_205 ^ 0xC0 ;
if ( V_3 -> V_257 &
V_765 )
V_205 &= 0xBF ;
if ( V_3 -> V_257 &
V_764 )
V_205 &= 0x7F ;
if ( V_3 -> V_257 &
V_767 )
V_205 |= 0x40 ;
if ( V_3 -> V_257 &
V_766 )
V_205 |= 0x80 ;
}
}
}
}
F_22 ( V_3 -> V_579 , 0x1F , V_205 ) ;
if ( V_3 -> V_257 & V_569 ) {
F_62 ( V_221 , V_3 ) ;
return;
}
if ( ! ( V_3 -> V_257 & V_764 ) ) {
F_122 ( V_3 ) ;
if ( ! ( V_3 -> V_257 & V_768 ) ) {
F_93 ( V_221 ,
V_3 ) ;
F_62 ( V_221 , V_3 ) ;
F_122 ( V_3 ) ;
}
}
}
else {
if ( V_3 -> V_48 & ( V_214 | V_215
| V_213 ) )
F_22 ( V_3 -> V_572 , 0x1E , 0x20 ) ;
V_205 = ( unsigned char ) F_8 ( V_3 -> V_572 ,
0x2E ) ;
if ( ! ( V_205 & 0x80 ) )
F_22 ( V_3 -> V_572 , 0x2E , 0x80 ) ;
F_15 ( V_3 -> V_572 , 0x00 , 0x7F ) ;
F_62 ( V_221 , V_3 ) ;
}
}
static void F_128 ( struct V_220 * V_221 ,
unsigned short V_199 , unsigned short V_200 ,
struct V_2 * V_3 )
{
unsigned short V_204 , V_236 , V_294 , V_275 ;
unsigned short V_812 = V_3 -> V_296 ;
V_204 = F_2 ( V_199 , V_200 , V_3 ) ;
F_3 ( V_199 , V_204 , V_200 , V_3 ) ;
F_5 ( V_204 , V_3 ) ;
F_7 ( V_221 , V_204 , V_3 ) ;
F_9 ( V_199 , V_204 , V_200 , V_3 ) ;
F_11 ( V_204 , V_3 ) ;
F_12 ( V_3 ) ;
if ( V_221 -> V_280 == V_162 ) {
if ( V_3 -> V_243 == 0 )
F_13 ( V_3 ) ;
}
V_275 = ~ V_586 ;
V_3 -> V_257 &= V_275 ;
V_3 -> V_799 = 0 ;
if ( V_3 -> V_155 & ( V_264 | V_265 | V_156
| V_157 | V_246 ) ) {
if ( V_3 -> V_48 & ( V_630 | V_213
| V_216 ) ) {
V_3 -> V_257 |= V_586 ;
}
}
V_236 = F_123 ( V_221 , V_199 ,
V_200 , V_3 ) ;
if ( V_236 != 0xFFFF ) {
F_17 ( V_236 , V_3 ) ;
F_20 ( V_199 , V_200 , V_236 ,
V_3 , V_221 ) ;
F_28 ( V_221 , V_199 , V_200 ,
V_236 , V_3 ) ;
F_30 ( V_199 , V_200 , V_236 ,
V_221 , V_3 ) ;
F_32 ( V_199 , V_200 , V_221 ,
V_236 , V_3 ) ;
}
if ( ( V_221 -> V_280 >= V_171 ) &&
( V_221 -> V_280 < V_162 ) ) {
if ( ( V_199 == 0x00 ) | ( V_199 == 0x01 ) ) {
F_4 ( V_3 -> V_211 , 0x2B , 0x4E ) ;
F_4 ( V_3 -> V_211 , 0x2C , 0xE9 ) ;
V_294 = ( unsigned char ) F_10 ( V_812 ) ;
F_6 ( ( V_294 |= 0x0C ) , V_812 ) ;
} else if ( ( V_199 == 0x04 ) | ( V_199 == 0x05 ) | ( V_199
== 0x0D ) ) {
F_4 ( V_3 -> V_211 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_211 , 0x2C , 0xE3 ) ;
V_294 = ( unsigned char ) F_10 ( V_812 ) ;
F_6 ( ( V_294 |= 0x0C ) , V_812 ) ;
}
}
if ( V_221 -> V_280 >= V_161 ) {
V_275 = F_8 ( V_3 -> V_223 , 0x38 ) ;
if ( V_275 & 0xA0 ) {
if ( V_221 -> V_280 == V_162 )
F_23 ( V_199 , V_200 ,
V_236 , V_3 ) ;
else
F_21 ( V_199 , V_200 ,
V_236 , V_3 ) ;
F_27 ( V_199 , V_3 ,
V_236 ) ;
if ( V_221 -> V_280 == V_162 )
F_25 ( V_3 , V_236 ,
V_199 ) ;
else
F_24 ( V_3 , V_236 ,
V_199 ) ;
if ( V_3 -> V_243 == 1 ) {
if ( V_221 -> V_280 == V_162 )
F_98 ( V_199 ,
V_200 , V_3 ) ;
else
F_97 ( V_199 ,
V_200 , V_3 ) ;
}
}
}
V_3 -> V_257 &= ( ~ V_586 ) ;
F_33 ( V_199 , V_221 , V_3 ) ;
F_36 ( V_221 , V_199 , V_200 ,
V_236 , V_3 ) ;
F_38 ( V_199 , V_200 , V_3 ) ;
}
unsigned char F_129 ( struct V_220 * V_221 ,
unsigned short V_199 )
{
unsigned short V_200 ;
struct V_2 V_813 ;
struct V_2 * V_3 = & V_813 ;
V_3 -> V_814 = V_221 -> V_815 ;
V_3 -> V_816 = ( unsigned long ) V_221 -> V_817 ;
V_3 -> V_243 = 0 ;
V_3 -> V_270 = 0 ;
V_3 -> V_620 = 1 ;
V_3 -> V_542 = 0 ;
V_3 -> V_508 = 0 ;
V_3 -> V_635 = 0 ;
V_3 -> V_553 = 0 ;
V_3 -> V_570 = 0 ;
V_3 -> V_660 = 0 ;
if ( V_221 -> V_280 >= V_171 ) {
V_3 -> V_625 = 0 ;
V_3 -> V_627 = 0 ;
V_3 -> V_632 = 0 ;
V_3 -> V_155 = 0 ;
} else {
V_3 -> V_625 = 1 ;
V_3 -> V_627 = 1 ;
V_3 -> V_632 = 1 ;
}
V_3 -> V_211 = V_3 -> V_816 + 0x14 ;
V_3 -> V_223 = V_3 -> V_816 + 0x24 ;
V_3 -> V_229 = V_3 -> V_816 + 0x10 ;
V_3 -> V_232 = V_3 -> V_816 + 0x1e ;
V_3 -> V_219 = V_3 -> V_816 + 0x12 ;
V_3 -> V_296 = V_3 -> V_816 + 0x1C ;
V_3 -> V_342 = V_3 -> V_816 + 0x1a ;
V_3 -> V_375 = V_3 -> V_816 + 0x16 ;
V_3 -> V_818 = V_3 -> V_816 + 0x17 ;
V_3 -> V_376 = V_3 -> V_816 + 0x18 ;
V_3 -> V_361 = V_3 -> V_816 + 0x19 ;
V_3 -> V_228 = V_3 -> V_816 + 0x2A ;
V_3 -> V_819 = V_3 -> V_816 + V_820 ;
V_3 -> V_572 = V_3 -> V_816 + V_821 ;
V_3 -> V_604 = V_3 -> V_816 + V_822 ;
V_3 -> V_727 = V_3 -> V_816 + V_823 ;
V_3 -> V_579 = V_3 -> V_816 + V_824 ;
V_3 -> V_732 = V_3 -> V_816 + V_824 + 2 ;
if ( V_221 -> V_280 == V_161 ) {
if ( ( F_8 ( V_3 -> V_223 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_243 = 1 ;
}
if ( V_221 -> V_280 == V_162 ) {
if ( ( F_8 ( V_3 -> V_223 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_8 ( V_3 -> V_223 , 0x30 ) & 0x20 )
V_3 -> V_243 = 1 ;
}
}
if ( V_221 -> V_280 < V_171 )
F_54 ( V_3 ) ;
F_1 ( V_221 -> V_280 , V_3 ) ;
if ( V_199 & 0x80 ) {
V_199 = V_199 & 0x7F ;
}
F_4 ( V_3 -> V_211 , 0x05 , 0x86 ) ;
if ( V_221 -> V_280 < V_171 )
F_119 ( V_221 , V_3 ) ;
F_58 ( V_199 , & V_200 , V_3 ) ;
F_53 ( V_221 , V_3 ) ;
if ( V_221 -> V_280 < V_171 ) {
F_55 ( V_199 , V_200 , V_221 , V_3 ) ;
F_56 ( V_199 , V_200 , V_3 ) ;
F_57 ( V_199 , V_200 , V_3 ) ;
F_102 ( V_221 , V_3 ) ;
if ( V_3 -> V_48 & ( V_630 | V_213 ) ) {
F_128 ( V_221 , V_199 ,
V_200 , V_3 ) ;
if ( V_3 -> V_48 & V_213 ) {
F_124 ( V_199 , V_200 ,
V_221 , V_3 ) ;
}
} else {
if ( ! ( V_3 -> V_48 & V_631 ) ) {
F_128 ( V_221 , V_199 ,
V_200 , V_3 ) ;
if ( V_3 -> V_48 & V_213 ) {
F_124 ( V_199 , V_200 ,
V_221 ,
V_3 ) ;
}
}
}
if ( V_3 -> V_48 & ( V_630 | V_631 ) ) {
switch ( V_221 -> V_825 ) {
case V_826 :
F_125 ( V_199 , V_221 ,
V_3 ) ;
break;
case V_827 :
F_125 ( V_199 , V_221 ,
V_3 ) ;
break;
default:
break;
}
}
F_116 ( V_199 , V_221 , V_3 ) ;
F_115 ( V_199 , V_200 , V_3 ) ;
F_117 ( V_221 , V_3 ) ;
F_127 ( V_221 , V_3 ) ;
}
else {
if ( V_3 -> V_243 == 1 )
if ( ! F_96 ( V_199 ,
V_200 ,
V_3 ) )
return 0 ;
if ( V_199 <= 0x13 ) {
V_3 -> V_203 = V_3 -> V_4 [ V_200 ] .
V_209 & V_617 ;
} else {
V_3 -> V_203 = V_3 -> V_10 [ V_200 ] .
V_210 & V_617 ;
}
V_3 -> V_257 = 0 ;
if ( V_3 -> V_508 != 1 )
V_3 -> V_48 = V_619 ;
F_66 ( V_221 , V_3 ) ;
F_128 ( V_221 , V_199 , V_200 ,
V_3 ) ;
F_62 ( V_221 , V_3 ) ;
}
F_52 ( V_221 , V_3 ) ;
if ( V_221 -> V_280 < V_171 ) {
F_120 ( V_221 , V_3 ) ;
}
return 1 ;
}
