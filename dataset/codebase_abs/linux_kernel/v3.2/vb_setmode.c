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
if ( ( V_3 -> V_147 & V_148 ) || ( V_3 -> V_147 & V_149 ) )
V_3 -> V_150 = V_151 ;
else
V_3 -> V_150 = V_152 ;
if ( ( V_1 == V_153 ) || ( V_1 == V_154 ) )
V_3 -> V_155 = V_156 ;
V_3 -> V_157 = V_158 ;
V_3 -> V_159 = V_160 ;
V_3 -> V_161 = & V_162 ;
if ( V_1 >= V_163 )
V_3 -> V_164 = & V_165 ;
if ( V_1 == V_154 ) {
V_3 -> V_19
= (struct V_20 * ) V_166 ;
V_3 -> V_52 = V_167 ;
V_3 -> V_164 = & V_168 ;
V_3 -> V_169 = & V_170 ;
V_3 -> V_171 = & V_172 ;
V_3 -> V_173 = V_174 ;
V_3 -> V_175 = V_176 ;
V_3 -> V_177 = & V_178 ;
V_3 -> V_179 = & V_180 ;
}
if ( V_1 >= V_163 ) {
V_3 -> V_181 = & V_182 ;
V_3 -> V_183 = & V_184 ;
V_3 -> V_185 = & V_186 ;
V_3 -> V_187 = & V_188 ;
V_3 -> V_189 = & V_190 ;
}
}
static unsigned char F_2 ( unsigned short V_191 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned char V_193 ;
if ( V_191 <= 0x13 )
V_193 = V_3 -> V_4 [ V_192 ] . V_194 ;
else {
if ( V_3 -> V_195 <= 0x02 )
V_193 = 0x1B ;
else
V_193 = 0x0F ;
}
return V_193 ;
}
static void F_3 ( unsigned short V_191 ,
unsigned short V_196 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned char V_197 , V_198 ;
unsigned short V_199 , V_200 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
F_4 ( V_3 -> V_203 , 0x00 , 0x03 ) ;
V_197 = V_3 -> V_7 [ V_196 ] . V_204 [ 0 ] ;
V_199 = V_205 ;
if ( V_3 -> V_48 & V_205 ) {
V_197 |= 0x01 ;
} else {
if ( V_3 -> V_48 & ( V_206 | V_207 ) ) {
if ( V_3 -> V_48 & V_208 )
V_197 |= 0x01 ;
}
}
V_197 |= 0x20 ;
F_4 ( V_3 -> V_203 , 0x01 , V_197 ) ;
for ( V_199 = 02 ; V_199 <= 04 ; V_199 ++ ) {
V_198 = V_3 -> V_7 [ V_196 ] . V_204 [ V_199 - 1 ] ;
F_4 ( V_3 -> V_203 , V_199 , V_198 ) ;
}
}
static void F_5 ( unsigned short V_196 ,
struct V_2 * V_3 )
{
unsigned char V_209 ;
V_209 = V_3 -> V_7 [ V_196 ] . V_210 ;
F_6 ( V_209 , V_3 -> V_211 ) ;
}
static void F_7 ( struct V_212 * V_213 ,
unsigned short V_196 ,
struct V_2 * V_3 )
{
unsigned char V_214 ;
unsigned short V_199 ;
V_214 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x11 ) ;
V_214 &= 0x7f ;
F_4 ( V_3 -> V_215 , 0x11 , V_214 ) ;
for ( V_199 = 0 ; V_199 <= 0x18 ; V_199 ++ ) {
V_214 = V_3 -> V_7 [ V_196 ] . V_216 [ V_199 ] ;
F_4 ( V_3 -> V_215 , V_199 , V_214 ) ;
}
}
static void F_9 ( unsigned short V_191 ,
unsigned short V_196 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned char V_217 ;
unsigned short V_199 , V_200 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
for ( V_199 = 0 ; V_199 <= 0x13 ; V_199 ++ ) {
V_217 = V_3 -> V_7 [ V_196 ] . V_218 [ V_199 ] ;
if ( V_200 & V_219 ) {
if ( V_199 == 0x13 ) {
if ( V_3 -> V_48 & V_205 ) {
V_217 = 0 ;
} else {
if ( V_3 -> V_48 & ( V_206
| V_207 ) ) {
if ( V_3 -> V_48 &
V_208 )
V_217 = 0 ;
}
}
}
}
F_10 ( V_3 -> V_220 ) ;
F_6 ( V_199 , V_3 -> V_221 ) ;
F_6 ( V_217 , V_3 -> V_221 ) ;
}
F_10 ( V_3 -> V_220 ) ;
F_6 ( 0x14 , V_3 -> V_221 ) ;
F_6 ( 0x00 , V_3 -> V_221 ) ;
F_10 ( V_3 -> V_220 ) ;
F_6 ( 0x20 , V_3 -> V_221 ) ;
}
static void F_11 ( unsigned short V_196 ,
struct V_2 * V_3 )
{
unsigned char V_222 ;
unsigned short V_199 ;
for ( V_199 = 0 ; V_199 <= 0x08 ; V_199 ++ ) {
V_222 = V_3 -> V_7 [ V_196 ] . V_223 [ V_199 ] ;
F_4 ( V_3 -> V_224 , V_199 , V_222 ) ;
}
if ( V_3 -> V_195 > V_225 ) {
V_222 = ( unsigned char ) F_8 ( V_3 -> V_224 , 0x05 ) ;
V_222 &= 0xBF ;
F_4 ( V_3 -> V_224 , 0x05 , V_222 ) ;
}
}
static void F_12 ( struct V_2 * V_3 )
{
unsigned short V_199 ;
for ( V_199 = 0x0A ; V_199 <= 0x0E ; V_199 ++ )
F_4 ( V_3 -> V_203 , V_199 , 0x00 ) ;
}
static unsigned char F_13 ( struct V_2 * V_3 )
{
F_14 ( V_3 -> V_203 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_203 , 0x2B , V_3 -> V_25 [ 0 ] . V_226 ) ;
F_4 ( V_3 -> V_203 , 0x2C , V_3 -> V_25 [ 0 ] . V_227 ) ;
F_14 ( V_3 -> V_203 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_203 , 0x2B , V_3 -> V_25 [ 1 ] . V_226 ) ;
F_4 ( V_3 -> V_203 , 0x2C , V_3 -> V_25 [ 1 ] . V_227 ) ;
F_15 ( V_3 -> V_203 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_16 ( unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 , unsigned short * V_199 ,
struct V_2 * V_3 )
{
unsigned short V_229 , V_230 , V_231 , V_200 , V_232 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
V_230 = V_3 -> V_13 [ V_228 + ( * V_199 ) ] . V_234 ;
V_229 = 0 ;
if ( V_3 -> V_235 == 0 ) {
if ( V_3 -> V_48 & V_236 ) {
V_229 |= V_237 ;
if ( V_3 -> V_147 & V_238 )
V_229 |= V_239 ;
}
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_229 |= V_240 ;
if ( V_3 -> V_45 != V_241 ) {
if ( V_3 -> V_45 != V_242 ) {
if ( V_3 -> V_47 &
V_243 ) {
if ( V_231 >= 9 ) {
V_229 = 0 ;
return 0 ;
}
}
}
}
}
if ( V_3 -> V_48 & V_244 ) {
if ( ( V_3 -> V_147 & V_148 ) &&
( V_3 -> V_245 == V_246 ) ) {
V_229 |= V_247 ;
if ( V_3 -> V_48 & V_208 ) {
if ( V_231 == 4 )
return 0 ;
if ( V_231 == 3 )
return 0 ;
if ( V_231 > 7 )
return 0 ;
}
} else {
V_229 |= V_248 ;
if ( V_3 -> V_48 & V_208 ) {
if ( V_231 == 4 )
return 0 ;
if ( V_231 == 3 ) {
if ( V_3 -> V_249
& V_250 )
return 0 ;
}
if ( V_231 > 7 )
return 0 ;
}
}
} else {
if ( V_3 -> V_48 & ( V_251 |
V_252 |
V_253 |
V_254 |
V_244 ) ) {
V_229 |= V_255 ;
if ( V_3 -> V_147 & ( V_256 | V_257
| V_148 | V_149
| V_238 ) ) {
V_229 |= V_258 ;
}
if ( ! ( V_3 -> V_48 & V_259 ) ) {
if ( V_200 & V_260 ) {
if ( V_3 -> V_48 &
V_208 ) {
if ( ! ( V_3 -> V_48 &
V_261 ) ) {
return 0 ;
}
}
}
}
}
}
} else {
if ( V_3 -> V_48 & V_207 ) {
V_229 |= V_240 ;
if ( V_231 > 0x08 )
return 0 ;
if ( V_3 -> V_45 < V_262 ) {
if ( V_231 > 0x07 )
return 0 ;
if ( V_231 == 0x04 )
return 0 ;
}
}
}
for (; V_3 -> V_13 [ V_228 + ( * V_199 ) ] . V_234 ==
V_230 ; ( * V_199 ) -- ) {
V_232 = V_3 -> V_13 [ V_228 + ( * V_199 ) ] .
V_263 ;
if ( V_232 & V_229 )
return 1 ;
if ( ( * V_199 ) == 0 )
break;
}
for ( ( * V_199 ) = 0 ; ; ( * V_199 ) ++ ) {
V_232 = V_3 -> V_13 [ V_228 + ( * V_199 ) ] .
V_263 ;
if ( V_3 -> V_13 [ V_228 + ( * V_199 ) ] . V_234
!= V_230 ) {
return 0 ;
}
if ( V_232 & V_229 )
return 1 ;
}
return 1 ;
}
static void F_17 ( unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_264 , V_265 ;
V_264 = V_3 -> V_13 [ V_228 ] . V_263 >> 8 ;
V_264 &= 0xC0 ;
V_265 = 0x2F ;
V_265 |= V_264 ;
F_6 ( V_265 , V_3 -> V_211 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_212 * V_213 )
{
unsigned char V_266 , V_267 , V_268 ;
unsigned short V_199 , V_269 ;
V_266 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x11 ) ;
V_266 &= 0x7F ;
F_4 ( V_3 -> V_215 , 0x11 , V_266 ) ;
V_266 = V_3 -> V_138 [ 0 ] . V_266 [ 0 ] ;
F_4 ( V_3 -> V_215 , 0 , V_266 ) ;
for ( V_199 = 0x01 ; V_199 <= 0x04 ; V_199 ++ ) {
V_266 = V_3 -> V_138 [ 0 ] . V_266 [ V_199 ] ;
F_4 ( V_3 -> V_215 , ( unsigned short ) ( V_199 + 1 ) , V_266 ) ;
}
for ( V_199 = 0x05 ; V_199 <= 0x06 ; V_199 ++ ) {
V_266 = V_3 -> V_138 [ 0 ] . V_266 [ V_199 ] ;
F_4 ( V_3 -> V_203 , ( unsigned short ) ( V_199 + 6 ) , V_266 ) ;
}
V_269 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x0e ) ;
V_269 &= 0x1F ;
V_266 = V_3 -> V_138 [ 0 ] . V_266 [ 7 ] ;
V_266 &= 0xE0 ;
V_266 |= V_269 ;
F_4 ( V_3 -> V_203 , 0x0e , V_266 ) ;
if ( V_213 -> V_270 >= V_163 ) {
V_266 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x04 ) ;
V_266 = V_266 - 1 ;
F_4 ( V_3 -> V_215 , 0x04 , V_266 ) ;
V_266 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x05 ) ;
V_267 = V_266 ;
V_267 &= 0xE0 ;
V_266 &= 0x1F ;
if ( V_266 == 0 ) {
V_268 = V_266 ;
V_266 = ( unsigned char ) F_8 ( V_3 -> V_203 ,
0x0c ) ;
V_266 &= 0xFB ;
F_4 ( V_3 -> V_203 , 0x0c , V_266 ) ;
V_266 = V_268 ;
}
V_266 = V_266 - 1 ;
V_266 |= V_267 ;
F_4 ( V_3 -> V_215 , 0x05 , V_266 ) ;
V_266 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x0e ) ;
V_266 = V_266 >> 5 ;
V_266 = V_266 + 3 ;
if ( V_266 > 7 )
V_266 = V_266 - 7 ;
V_266 = V_266 << 5 ;
F_14 ( V_3 -> V_203 , 0x0e , ~ 0xE0 , V_266 ) ;
}
}
static void F_19 ( unsigned short V_192 ,
unsigned short V_191 ,
struct V_2 * V_3 )
{
unsigned char V_266 ;
unsigned short V_199 , V_269 ;
for ( V_199 = 0x00 ; V_199 <= 0x01 ; V_199 ++ ) {
V_266 = V_3 -> V_141 [ 0 ] . V_266 [ V_199 ] ;
F_4 ( V_3 -> V_215 , ( unsigned short ) ( V_199 + 6 ) , V_266 ) ;
}
for ( V_199 = 0x02 ; V_199 <= 0x03 ; V_199 ++ ) {
V_266 = V_3 -> V_141 [ 0 ] . V_266 [ V_199 ] ;
F_4 ( V_3 -> V_215 , ( unsigned short ) ( V_199 + 0x0e ) , V_266 ) ;
}
for ( V_199 = 0x04 ; V_199 <= 0x05 ; V_199 ++ ) {
V_266 = V_3 -> V_141 [ 0 ] . V_266 [ V_199 ] ;
F_4 ( V_3 -> V_215 , ( unsigned short ) ( V_199 + 0x11 ) , V_266 ) ;
}
V_269 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x0a ) ;
V_269 &= 0xC0 ;
V_266 = V_3 -> V_141 [ 0 ] . V_266 [ 6 ] ;
V_266 &= 0x3F ;
V_266 |= V_269 ;
F_4 ( V_3 -> V_203 , 0x0a , V_266 ) ;
V_266 = V_3 -> V_141 [ 0 ] . V_266 [ 6 ] ;
V_266 &= 0x80 ;
V_266 = V_266 >> 2 ;
if ( V_191 <= 0x13 )
V_199 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_199 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_199 &= V_271 ;
if ( V_199 )
V_266 |= 0x80 ;
V_269 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x09 ) ;
V_269 &= 0x5F ;
V_266 |= V_269 ;
F_4 ( V_3 -> V_215 , 0x09 , V_266 ) ;
}
static void F_20 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 ,
struct V_212 * V_213 )
{
unsigned char V_193 , V_266 ;
unsigned short V_199 ;
V_193 = V_3 -> V_13 [ V_228 ] . V_272 ;
V_193 = V_193 & V_273 ;
V_266 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x11 ) ;
V_266 &= 0x7F ;
F_4 ( V_3 -> V_215 , 0x11 , V_266 ) ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ )
V_3 -> V_138 [ 0 ] . V_266 [ V_199 ]
= V_3 -> V_16 [ V_193 ] . V_274 [ V_199 ] ;
for ( V_199 = 0 ; V_199 < 7 ; V_199 ++ )
V_3 -> V_141 [ 0 ] . V_266 [ V_199 ]
= V_3 -> V_16 [ V_193 ] . V_274 [ V_199 + 8 ] ;
F_18 ( V_3 , V_213 ) ;
F_19 ( V_192 , V_191 , V_3 ) ;
if ( V_3 -> V_195 > 0x03 )
F_4 ( V_3 -> V_215 , 0x14 , 0x4F ) ;
}
static void F_21 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned char V_196 , V_193 , V_275 , V_276 , V_277 , V_278 ;
unsigned short V_279 , V_280 , V_281 ;
if ( V_191 <= 0x13 ) {
V_196 = F_2 ( V_191 , V_192 , V_3 ) ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 4 ] ;
F_4 ( V_3 -> V_203 , 0x2E , V_275 ) ;
V_276 = V_3 -> V_7 [ V_196 ] . V_216 [ 5 ] ;
V_276 &= 0x1F ;
V_277 = V_275 ;
V_277 &= 0xE0 ;
V_278 = V_277 | V_276 ;
if ( V_276 < ( V_275 & 0x1F ) )
V_278 |= 0x20 ;
V_278 <<= 2 ;
F_4 ( V_3 -> V_203 , 0x2F , V_278 ) ;
F_14 ( V_3 -> V_203 , 0x30 , 0xE3 , 00 ) ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 16 ] ;
V_276 = V_275 ;
V_275 &= 0x01 ;
F_22 ( V_3 -> V_203 , 0x33 , V_275 ) ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 7 ] ;
V_278 = V_276 >> 1 ;
V_277 = V_275 & 0x04 ;
V_277 <<= 5 ;
V_278 |= V_277 ;
F_4 ( V_3 -> V_203 , 0x34 , V_278 ) ;
V_279 = V_277 << 1 ;
V_279 |= V_276 ;
V_275 &= 0x80 ;
V_280 = V_275 << 2 ;
V_279 |= V_280 ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 17 ] ;
V_275 &= 0x0F ;
V_280 = V_279 & 0x3F0 ;
V_280 |= V_275 ;
V_281 = V_279 & 0x0F ;
if ( V_275 < V_281 )
V_280 |= 0x10 ;
V_280 &= 0xFF ;
V_275 = ( unsigned char ) V_280 ;
V_275 <<= 2 ;
V_279 &= 0x600 ;
V_279 >>= 9 ;
V_276 = ( unsigned char ) V_279 ;
V_275 |= V_276 ;
V_275 &= 0x7F ;
F_4 ( V_3 -> V_203 , 0x3F , V_275 ) ;
} else {
V_193 = V_3 -> V_13 [ V_228 ] . V_272 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 3 ] ;
V_277 = V_275 ;
F_4 ( V_3 -> V_203 , 0x2E , V_275 ) ;
V_278 = V_3 -> V_16 [ V_193 ] . V_274 [ 5 ] ;
V_278 &= 0xC0 ;
V_279 = V_278 ;
V_279 <<= 2 ;
V_279 |= V_275 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 4 ] ;
V_275 &= 0x1F ;
V_276 = V_3 -> V_16 [ V_193 ] . V_274 [ 6 ] ;
V_276 &= 0x04 ;
V_276 <<= 3 ;
V_275 |= V_276 ;
V_280 = V_279 & 0x3C0 ;
V_280 |= V_275 ;
V_277 &= 0x3F ;
if ( V_275 < V_277 )
V_280 |= 0x40 ;
V_280 &= 0xFF ;
V_275 = ( unsigned char ) V_280 ;
V_275 <<= 2 ;
V_278 >>= 6 ;
V_275 |= V_278 ;
F_4 ( V_3 -> V_203 , 0x2F , V_275 ) ;
F_14 ( V_3 -> V_203 , 0x30 , 0xE3 , 00 ) ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 10 ] ;
V_276 = V_275 ;
V_275 &= 0x01 ;
F_22 ( V_3 -> V_203 , 0x33 , V_275 ) ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 9 ] ;
V_277 = V_276 >> 1 ;
V_278 = V_275 & 0x04 ;
V_278 <<= 5 ;
V_277 |= V_278 ;
F_4 ( V_3 -> V_203 , 0x34 , V_277 ) ;
V_279 = V_278 ;
V_279 <<= 1 ;
V_279 |= V_276 ;
V_275 &= 0x80 ;
V_280 = V_275 << 2 ;
V_279 |= V_280 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 14 ] ;
V_275 &= 0x08 ;
V_280 = V_275 ;
V_280 <<= 7 ;
V_279 |= V_280 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 11 ] ;
V_275 &= 0x0F ;
V_276 = V_3 -> V_16 [ V_193 ] . V_274 [ 14 ] ;
V_276 &= 0x20 ;
V_276 >>= 1 ;
V_275 |= V_276 ;
V_280 = V_279 & 0x7E0 ;
V_280 |= V_275 ;
V_281 = V_279 & 0x1F ;
if ( V_275 < V_281 )
V_280 |= 0x20 ;
V_280 &= 0xFF ;
V_275 = ( unsigned char ) V_280 ;
V_275 <<= 2 ;
V_279 &= 0x600 ;
V_279 >>= 9 ;
V_276 = ( unsigned char ) V_279 ;
V_275 |= V_276 ;
V_275 &= 0x7F ;
F_4 ( V_3 -> V_203 , 0x3F , V_275 ) ;
}
}
static void F_23 ( unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_196 , V_193 , V_275 , V_276 , V_277 , V_278 ;
if ( V_191 <= 0x13 ) {
V_196 = F_2 ( V_191 , V_192 , V_3 ) ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 4 ] ;
F_4 ( V_3 -> V_203 , 0x2E , V_275 ) ;
V_276 = V_3 -> V_7 [ V_196 ] . V_216 [ 5 ] ;
V_276 &= 0x1F ;
V_277 = V_275 ;
V_277 &= 0xE0 ;
V_278 = V_277 | V_276 ;
if ( V_276 < ( V_275 & 0x1F ) )
V_278 |= 0x20 ;
V_278 <<= 2 ;
F_4 ( V_3 -> V_203 , 0x2F , V_278 ) ;
F_14 ( V_3 -> V_203 , 0x30 , 0xE3 , 00 ) ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 16 ] ;
F_4 ( V_3 -> V_203 , 0x34 , V_275 ) ;
V_277 = V_275 ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 7 ] ;
V_276 = V_275 ;
V_275 &= 0x04 ;
V_275 >>= 2 ;
F_14 ( V_3 -> V_203 , 0x35 , ~ 0x01 , V_275 ) ;
V_277 |= ( V_275 << 8 ) ;
V_277 |= ( V_276 & 0x80 ) << 2 ;
V_275 = V_3 -> V_7 [ V_196 ] . V_216 [ 17 ] ;
V_275 &= 0x0F ;
V_276 = V_277 ;
V_276 &= 0x3F0 ;
V_276 |= V_275 ;
if ( V_275 <= ( V_277 & 0x0F ) )
V_276 |= 0x10 ;
V_275 = ( unsigned char ) V_276 & 0xFF ;
V_275 <<= 2 ;
V_277 = ( V_277 & 0x600 ) >> 8 ;
F_14 ( V_3 -> V_203 , 0x3F , ~ 0xFC , V_275 ) ;
F_14 ( V_3 -> V_203 , 0x35 , ~ 0x06 , V_277 ) ;
} else {
V_193 = V_3 -> V_13 [ V_228 ] . V_272 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 3 ] ;
V_276 = V_275 ;
F_4 ( V_3 -> V_203 , 0x2E , V_275 ) ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 5 ] ;
V_275 &= 0xC0 ;
V_276 |= ( V_275 << 2 ) ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 4 ] ;
V_275 &= 0x1F ;
V_277 = V_275 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 6 ] ;
V_275 &= 0x04 ;
V_275 <<= 3 ;
V_277 |= V_275 ;
V_276 = V_276 & 0x3C0 ;
V_276 |= V_277 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 3 ] ;
V_275 &= 0x3F ;
if ( V_277 <= V_275 )
V_276 += 0x40 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 5 ] ;
V_275 &= 0xC0 ;
V_275 >>= 6 ;
V_275 |= ( ( V_276 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_203 , 0x2F , V_275 ) ;
F_14 ( V_3 -> V_203 , 0x30 , 0xE3 , 00 ) ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 10 ] ;
F_4 ( V_3 -> V_203 , 0x34 , V_275 ) ;
V_277 = V_275 ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 9 ] ;
V_276 = V_275 ;
V_275 = V_275 & 0x04 ;
V_275 >>= 2 ;
F_14 ( V_3 -> V_203 , 0x35 , ~ 0x01 , V_275 ) ;
V_277 |= ( V_275 << 8 ) ;
V_277 |= ( ( V_276 & 0x80 ) << 2 ) ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 14 ] ;
V_275 &= 0x08 ;
V_277 |= ( V_275 << 7 ) ;
V_275 = V_3 -> V_16 [ V_193 ] . V_274 [ 11 ] ;
V_275 &= 0x0F ;
V_276 = V_3 -> V_16 [ V_193 ] . V_274 [ 14 ] ;
V_276 &= 0x20 ;
V_276 >>= 1 ;
V_275 |= V_276 ;
V_276 = V_277 ;
V_276 &= 0x7E0 ;
V_276 |= V_275 ;
if ( V_276 <= V_277 )
V_276 |= 0x20 ;
V_275 = ( V_276 << 2 ) & 0xFF ;
F_14 ( V_3 -> V_203 , 0x3F , ~ 0xFC , V_275 ) ;
V_275 = V_277 >> 8 ;
F_14 ( V_3 -> V_203 , 0x35 , ~ 0x07 , V_275 ) ;
}
}
static void F_24 ( int V_282 ,
struct V_2 * V_3 ,
unsigned short V_228 ,
unsigned short V_191 )
{
unsigned short V_283 , V_284 , V_285 ;
unsigned short V_286 ;
V_286 = V_3 -> V_287 ;
F_4 ( V_3 -> V_215 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_215 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_215 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_215 , 0x47 , 0x00 ) ;
if ( V_282 == V_154 ) {
V_284 = F_8 ( V_3 -> V_215 , 0x37 ) ;
if ( ( V_284 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_215 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_215 , 0x47 , 0x13 ) ;
}
}
if ( ( ( * V_3 -> V_181 ) & 0xC0 ) == 0xC0 ) {
F_4 ( V_3 -> V_215 , 0x2E , * V_3 -> V_183 ) ;
F_4 ( V_3 -> V_215 , 0x2F , * V_3 -> V_185 ) ;
F_4 ( V_3 -> V_215 , 0x46 , * V_3 -> V_187 ) ;
F_4 ( V_3 -> V_215 , 0x47 , * V_3 -> V_189 ) ;
}
if ( V_282 == V_154 ) {
F_25 ( V_3 ) ;
} else {
V_284 = F_8 ( V_3 -> V_215 , 0x37 ) ;
if ( V_284 & 0x01 ) {
F_22 ( V_3 -> V_203 , 0x06 , 0x40 ) ;
F_22 ( V_3 -> V_203 , 0x09 , 0x40 ) ;
}
}
F_22 ( V_3 -> V_203 , 0x1E , 0x01 ) ;
F_15 ( V_3 -> V_203 , 0x30 , ~ 0x20 ) ;
F_15 ( V_3 -> V_203 , 0x35 , ~ 0x80 ) ;
if ( V_191 <= 0x13 ) {
V_285 = ( unsigned char ) F_10 ( V_286 ) ;
if ( V_285 & 0x40 )
F_22 ( V_3 -> V_203 , 0x30 , 0x20 ) ;
if ( V_285 & 0x80 )
F_22 ( V_3 -> V_203 , 0x35 , 0x80 ) ;
} else {
V_283 = V_3 -> V_13 [ V_228 ] . V_263 ;
if ( V_283 & 0x4000 )
F_22 ( V_3 -> V_203 , 0x30 , 0x20 ) ;
if ( V_283 & 0x8000 )
F_22 ( V_3 -> V_203 , 0x35 , 0x80 ) ;
}
}
static void F_26 ( unsigned short V_191 ,
struct V_2 * V_3 ,
unsigned short V_228 )
{
int V_199 , V_193 = - 1 ;
F_15 ( V_3 -> V_215 , 0x11 , 0x7F ) ;
if ( V_191 <= 0x13 ) {
for ( V_199 = 0 ; V_199 < 12 ; V_199 ++ ) {
if ( V_191 == V_3 -> V_144 [ V_199 ] . V_234 )
V_193 = V_199 ;
}
} else {
if ( V_191 == 0x2E &&
( V_3 -> V_13 [ V_228 ] . V_272 ==
V_288 ) )
V_193 = 12 ;
else if ( V_191 == 0x2E &&
( V_3 -> V_13 [ V_228 ] .
V_272 == V_289 ) )
V_193 = 13 ;
else if ( V_191 == 0x2F )
V_193 = 14 ;
else if ( V_191 == 0x50 )
V_193 = 15 ;
else if ( V_191 == 0x59 )
V_193 = 16 ;
}
if ( V_193 != - 1 ) {
F_4 ( V_3 -> V_215 , 0x02 ,
V_3 -> V_144 [ V_193 ] . V_290 ) ;
F_4 ( V_3 -> V_215 , 0x03 ,
V_3 -> V_144 [ V_193 ] . V_291 ) ;
F_4 ( V_3 -> V_215 , 0x15 ,
V_3 -> V_144 [ V_193 ] . V_292 ) ;
F_4 ( V_3 -> V_215 , 0x16 ,
V_3 -> V_144 [ V_193 ] . V_293 ) ;
}
}
static void F_27 ( struct V_212 * V_213 ,
unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_294 , V_229 , V_230 , V_295 , V_265 , V_200 ;
unsigned char V_266 ;
V_294 = F_28 ( V_191 , V_192 , V_3 ) ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_229 = V_3 -> V_33 [ V_294 ] . V_296 ;
V_230 = V_3 -> V_33 [ V_294 ] . V_297 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_229 = V_3 -> V_36 [ V_294 ] . V_296 ;
V_230 = V_3 -> V_36 [ V_294 ] . V_297 ;
}
if ( V_200 & V_298 )
V_229 = V_229 >> 1 ;
if ( V_191 > 0x13 ) {
if ( V_200 & V_298 )
V_229 = V_229 << 1 ;
V_265 = V_3 -> V_13 [ V_228 ] . V_263 ;
if ( V_265 & V_299 )
V_230 = V_230 >> 1 ;
if ( V_200 & V_271 )
V_230 = V_230 << 1 ;
}
V_295 = 8 ;
V_229 /= V_295 ;
V_229 -= 1 ;
V_230 -= 1 ;
V_295 = V_229 ;
V_265 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x11 ) ;
V_266 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x11 ) ;
V_266 &= 0x7F ;
F_4 ( V_3 -> V_215 , 0x11 , V_266 ) ;
F_4 ( V_3 -> V_215 , 0x01 , ( unsigned short ) ( V_295 & 0xff ) ) ;
F_14 ( V_3 -> V_215 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_295 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_215 , 0x12 , ( unsigned short ) ( V_230 & 0xff ) ) ;
V_229 = 0 ;
V_230 = V_230 >> 8 ;
if ( V_230 & 0x01 )
V_229 |= 0x02 ;
if ( V_230 & 0x02 )
V_229 |= 0x40 ;
F_14 ( V_3 -> V_215 , 0x07 , ~ 0x42 , V_229 ) ;
V_266 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x07 ) ;
V_266 &= 0xFF ;
V_229 = 0 ;
if ( V_230 & 0x04 )
V_229 |= 0x02 ;
F_14 ( V_3 -> V_215 , 0x0a , ~ 0x02 , V_229 ) ;
F_4 ( V_3 -> V_215 , 0x11 , V_265 ) ;
}
unsigned short F_28 ( unsigned short V_191 ,
unsigned short V_192 , struct V_2 * V_3 )
{
unsigned short V_294 ;
if ( V_191 <= 0x13 )
V_294 = V_3 -> V_4 [ V_192 ] . V_300 ;
else
V_294 = V_3 -> V_10 [ V_192 ] . V_233 ;
return V_294 ;
}
static void F_29 ( unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_265 , V_301 , V_302 , V_303 , V_199 , V_304 ;
V_265 = V_3 -> V_10 [ V_192 ] . V_305 ;
V_265 = V_265 >> 8 ;
V_265 = V_3 -> V_31 [ V_265 ] ;
V_303 = V_3 -> V_13 [ V_228 ] . V_263 ;
V_303 &= V_299 ;
if ( V_303 )
V_265 = V_265 << 1 ;
V_303 = V_3 -> V_195 - V_306 ;
switch ( V_303 ) {
case 0 :
V_303 = 1 ;
break;
case 1 :
V_303 = 2 ;
break;
case 2 :
V_303 = 4 ;
break;
case 3 :
V_303 = 4 ;
break;
case 4 :
V_303 = 6 ;
break;
case 5 :
V_303 = 8 ;
break;
default:
break;
}
if ( ( V_191 >= 0x26 ) && ( V_191 <= 0x28 ) )
V_265 = V_265 * V_303 + V_303 / 2 ;
else
V_265 *= V_303 ;
V_304 = V_265 ;
V_303 = V_265 ;
V_265 = V_265 >> 8 ;
V_265 &= 0x0F ;
V_199 = F_8 ( V_3 -> V_203 , 0x0E ) ;
V_199 &= 0xF0 ;
V_199 |= V_265 ;
F_4 ( V_3 -> V_203 , 0x0E , V_199 ) ;
V_265 = ( unsigned char ) V_303 ;
V_265 &= 0xFF ;
F_4 ( V_3 -> V_215 , 0x13 , V_265 ) ;
V_303 = V_3 -> V_13 [ V_228 ] . V_263 ;
V_303 &= V_299 ;
if ( V_303 )
V_304 >>= 1 ;
V_304 = V_304 << 5 ;
V_301 = ( V_304 & 0xff00 ) >> 8 ;
V_302 = V_304 & 0x00ff ;
if ( V_302 == 0 )
V_301 += 1 ;
else
V_301 += 2 ;
if ( V_213 -> V_270 >= V_163 )
if ( ( V_191 == 0x4A ) | ( V_191 == 0x49 ) )
V_301 -= 1 ;
F_4 ( V_3 -> V_203 , 0x10 , V_301 ) ;
}
static unsigned short F_30 ( unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_307 [ 4 ] = { V_308 + 2 ,
V_308 + 2 ,
V_308 + 2 ,
V_308 + 2 } ;
unsigned short V_309 [ 4 ] = { V_310 + 5 ,
V_310 + 5 ,
V_310 + 5 ,
V_310 + 5 } ;
unsigned short V_311 [ 4 ] = { V_312 , V_312 , V_312 , V_312 } ;
unsigned short V_313 [ 4 ] = { V_308 + 2 ,
V_308 + 2 ,
V_308 + 2 ,
V_308 + 2 } ;
unsigned short V_314 [ 4 ] = { V_308 + 2 ,
V_308 + 2 ,
V_308 + 2 ,
V_308 + 2 } ;
unsigned short V_315 , V_316 ;
unsigned short V_200 , V_231 ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_231 = V_3 -> V_4 [ V_192 ] . V_300 ;
V_315 = V_3 -> V_4 [ V_192 ] . V_317 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
V_315 = V_3 -> V_13 [ V_228 ] .
V_318 ;
}
if ( V_3 -> V_235 == 0 ) {
V_315 = V_315 >> 6 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
if ( V_3 -> V_45 != V_262 )
V_316 = V_309 [ V_315 ] ;
else
V_316 = V_307 [ V_315 ] ;
} else {
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_48 & V_244 ) {
if ( V_3 -> V_249 & V_319 ) {
V_316 = V_320 ;
V_316 += 25 ;
} else {
V_316 = V_321 ;
V_316 += 25 ;
}
if ( V_3 -> V_249 & V_250 ) {
if ( V_200 & V_219 ) {
V_316 =
V_322 ;
V_316 += 25 ;
} else {
V_316 =
V_323 ;
V_316 += 25 ;
}
}
if ( V_3 -> V_147 & V_148 ) {
if ( ! ( V_3 -> V_245 ==
V_246 ) ) {
V_316 =
V_324 ;
if ( ! ( V_3 -> V_245
==
V_325 ) ) {
V_316 =
V_326 ;
if ( ! ( V_3 -> V_245
== V_327 ) ) {
V_316
= V_328 ;
if ( ! ( V_3 -> V_249
& V_319 ) )
V_316
= V_329 ;
}
}
}
}
} else {
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_249 &
V_319 ) {
V_316 = V_330 ;
V_316 += 25 ;
} else {
V_316 = V_331 ;
V_316 += 25 ;
}
}
}
} else {
V_316 = ( unsigned char ) F_10 (
( V_3 -> V_332 + 0x02 ) ) ;
V_316 = ( ( V_316 >> 2 ) & 0x03 ) ;
if ( V_191 > 0x13 ) {
V_316 =
V_3 -> V_13 [
V_228 ] .
V_333 ;
V_316 &= V_273 ;
}
}
}
} else {
if ( V_191 <= 0x13 )
V_316 = V_315 ;
else
V_316 = V_315 ;
V_316 = V_316 >> 6 ;
if ( ( V_3 -> V_45 == V_334 ) ||
( V_3 -> V_45 == V_335 ) )
V_316 = V_311 [ V_316 ] ;
else if ( ( V_3 -> V_45 == V_262 ) ||
( V_3 -> V_45 == V_336 ) )
V_316 = V_313 [ V_316 ] ;
else
V_316 = V_314 [ V_316 ] ;
}
return V_316 ;
}
static void F_31 ( unsigned short V_191 ,
unsigned short V_192 ,
struct V_212 * V_213 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned char V_193 , V_266 ;
unsigned short V_337 ;
if ( V_3 -> V_235 == 1 ) {
V_193 = V_3 -> V_13 [ V_228 ] . V_333 ;
V_266 = F_8 ( V_3 -> V_203 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_203 , 0x31 , V_266 ) ;
F_4 ( V_3 -> V_203 , 0x2B ,
V_3 -> V_25 [ V_193 ] . V_226 ) ;
F_4 ( V_3 -> V_203 , 0x2C ,
V_3 -> V_25 [ V_193 ] . V_227 ) ;
F_4 ( V_3 -> V_203 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) && ( V_3 -> V_48
& V_205 ) ) {
V_337 = F_30 ( V_191 , V_192 ,
V_228 , V_213 ,
V_3 ) ;
V_266 = F_8 ( V_3 -> V_203 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_203 , 0x31 , V_266 ) ;
V_266 = V_3 -> V_28 [ V_337 ] . V_338 ;
F_4 ( V_3 -> V_203 , 0x2B , V_266 ) ;
V_266 = V_3 -> V_28 [ V_337 ] . V_339 ;
F_4 ( V_3 -> V_203 , 0x2C , V_266 ) ;
F_4 ( V_3 -> V_203 , 0x2D , 0x01 ) ;
} else {
V_193 = V_3 -> V_13 [ V_228 ] . V_333 ;
V_266 = F_8 ( V_3 -> V_203 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_203 , 0x31 , V_266 ) ;
F_4 ( V_3 -> V_203 , 0x2B ,
V_3 -> V_25 [ V_193 ] . V_226 ) ;
F_4 ( V_3 -> V_203 , 0x2C ,
V_3 -> V_25 [ V_193 ] . V_227 ) ;
F_4 ( V_3 -> V_203 , 0x2D , 0x01 ) ;
}
if ( V_213 -> V_270 >= V_163 ) {
if ( V_3 -> V_10 [ V_192 ] . V_202 &
V_298 ) {
V_266 = F_8 ( V_3 -> V_203 , 0x2B ) ;
F_4 ( V_3 -> V_203 , 0x2B , V_266 ) ;
V_266 = F_8 ( V_3 -> V_203 , 0x2C ) ;
V_193 = V_266 ;
V_193 &= 0xE0 ;
V_266 &= 0x1F ;
V_266 = V_266 << 1 ;
V_266 += 1 ;
V_266 |= V_193 ;
F_4 ( V_3 -> V_203 , 0x2C , V_266 ) ;
}
}
}
static void F_32 ( unsigned short V_191 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_266 ;
V_266 = F_8 ( V_3 -> V_203 , 0x3D ) ;
V_266 &= 0xfe ;
F_4 ( V_3 -> V_203 , 0x3D , V_266 ) ;
if ( V_191 > 0x13 ) {
F_4 ( V_3 -> V_203 , 0x08 , 0x34 ) ;
V_266 = F_8 ( V_3 -> V_203 , 0x09 ) ;
V_266 &= 0xC0 ;
F_4 ( V_3 -> V_203 , 0x09 , V_266 | 0x30 ) ;
V_266 = F_8 ( V_3 -> V_203 , 0x3D ) ;
V_266 |= 0x01 ;
F_4 ( V_3 -> V_203 , 0x3D , V_266 ) ;
} else {
if ( V_213 -> V_270 == V_154 ) {
F_4 ( V_3 -> V_203 , 0x08 , 0x0E ) ;
V_266 = F_8 ( V_3 -> V_203 , 0x09 ) ;
V_266 &= 0xC0 ;
F_4 ( V_3 -> V_203 , 0x09 , V_266 | 0x20 ) ;
} else {
F_4 ( V_3 -> V_203 , 0x08 , 0xAE ) ;
V_266 = F_8 ( V_3 -> V_203 , 0x09 ) ;
V_266 &= 0xF0 ;
F_4 ( V_3 -> V_203 , 0x09 , V_266 ) ;
}
}
if ( V_213 -> V_270 == V_153 )
F_33 ( V_3 ) ;
}
static void F_34 ( struct V_212 * V_213 ,
unsigned short V_191 , unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_266 , V_340 = 0 ;
short V_341 ;
unsigned char V_193 ;
if ( V_191 <= 0x13 )
V_341 = 0 ;
else {
V_193 = V_3 -> V_13 [ V_228 ] . V_333 ;
V_193 &= V_273 ;
V_341 = V_3 -> V_25 [ V_193 ] . CLOCK ;
}
V_266 = F_8 ( V_3 -> V_203 , 0x32 ) ;
V_266 &= 0xf3 ;
if ( V_341 >= 200 )
V_266 |= 0x0c ;
if ( V_213 -> V_270 >= V_163 )
V_266 &= ~ 0x04 ;
F_4 ( V_3 -> V_203 , 0x32 , V_266 ) ;
if ( V_213 -> V_270 < V_163 ) {
V_266 = F_8 ( V_3 -> V_203 , 0x1F ) ;
V_266 &= 0xE7 ;
if ( V_341 < 200 )
V_266 |= 0x10 ;
F_4 ( V_3 -> V_203 , 0x1F , V_266 ) ;
}
V_340 = 0x00 ;
F_14 ( V_3 -> V_203 , 0x07 , 0xFC , V_340 ) ;
if ( V_213 -> V_270 >= V_154 )
F_14 ( V_3 -> V_203 , 0x40 , 0xFC , V_340 & 0x03 ) ;
}
static void F_35 ( struct V_212 * V_213 ,
unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_266 , V_340 , V_342 , V_232 = 0 , V_200 , V_294 ,
V_343 ;
if ( V_191 > 0x13 ) {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_232 = V_3 -> V_13 [ V_228 ] .
V_263 ;
} else
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
if ( F_8 ( V_3 -> V_215 , 0x31 ) & 0x01 )
F_14 ( V_3 -> V_203 , 0x1F , 0x3F , 0x00 ) ;
if ( V_191 > 0x13 )
V_266 = V_232 ;
else
V_266 = 0 ;
V_340 = 0 ;
if ( V_191 > 0x13 ) {
if ( V_3 -> V_195 > 0x02 ) {
V_340 |= 0x02 ;
V_342 = V_3 -> V_195 - V_225 ;
V_342 = V_342 << 2 ;
V_340 |= V_342 ;
}
}
V_266 &= V_299 ;
if ( V_266 )
V_340 |= 0x20 ;
F_14 ( V_3 -> V_203 , 0x06 , ~ 0x3F , V_340 ) ;
V_294 = F_28 ( V_191 , V_192 , V_3 ) ;
if ( V_191 <= 0x13 )
V_343 = V_3 -> V_33 [ V_294 ] . V_296 ;
else
V_343 = V_3 -> V_36 [ V_294 ] . V_296 ;
V_266 = 0x0000 ;
if ( V_232 & V_299 ) {
if ( V_343 == 1024 )
V_266 = 0x0035 ;
else if ( V_343 == 1280 )
V_266 = 0x0048 ;
}
V_340 = V_266 & 0x00FF ;
F_14 ( V_3 -> V_215 , 0x19 , 0xFF , V_340 ) ;
V_340 = ( V_266 & 0xFF00 ) >> 8 ;
F_14 ( V_3 -> V_215 , 0x19 , 0xFC , V_340 ) ;
if ( V_200 & V_298 )
F_14 ( V_3 -> V_203 , 0x01 , 0xF7 , 0x08 ) ;
V_340 = 0 ;
if ( V_200 & V_344 )
V_340 |= 0x08 ;
if ( V_191 > 0x13 ) {
if ( V_3 -> V_195 == V_306 )
V_340 |= 0x40 ;
}
F_14 ( V_3 -> V_203 , 0x0F , ~ 0x48 , V_340 ) ;
V_266 = 0x60 ;
if ( V_3 -> V_195 != V_345 ) {
V_266 = V_266 ^ 0x60 ;
if ( V_3 -> V_195 != V_306 )
V_266 = V_266 ^ 0xA0 ;
}
F_14 ( V_3 -> V_203 , 0x21 , 0x1F , V_266 ) ;
F_34 ( V_213 , V_191 , V_228 ,
V_3 ) ;
V_266 = F_8 ( V_3 -> V_215 , 0x31 ) ;
if ( V_213 -> V_270 == V_154 ) {
if ( V_266 & 0x40 )
V_266 = 0x2c ;
else
V_266 = 0x6c ;
F_4 ( V_3 -> V_215 , 0x52 , V_266 ) ;
F_22 ( V_3 -> V_215 , 0x51 , 0x10 ) ;
} else if ( V_213 -> V_270 >= V_163 ) {
if ( V_266 & 0x40 )
V_266 = 0x33 ;
else
V_266 = 0x73 ;
F_4 ( V_3 -> V_215 , 0x52 , V_266 ) ;
F_4 ( V_3 -> V_215 , 0x51 , 0x02 ) ;
} else {
if ( V_266 & 0x40 )
V_266 = 0x2c ;
else
V_266 = 0x6c ;
F_4 ( V_3 -> V_215 , 0x52 , V_266 ) ;
}
}
static void F_36 ( unsigned short V_346 ,
unsigned short V_301 ,
unsigned short V_302 ,
unsigned short V_347 ,
struct V_2 * V_3 )
{
unsigned short V_265 , V_348 , V_349 ;
V_348 = V_301 ;
V_349 = V_302 ;
if ( V_346 != 0 ) {
V_265 = V_348 ;
V_348 = V_347 ;
V_347 = V_265 ;
if ( V_346 == 1 ) {
V_265 = V_349 ;
V_349 = V_347 ;
V_347 = V_265 ;
} else {
V_265 = V_349 ;
V_349 = V_348 ;
V_348 = V_265 ;
}
}
F_6 ( ( unsigned short ) V_347 , V_3 -> V_350 ) ;
F_6 ( ( unsigned short ) V_348 , V_3 -> V_350 ) ;
F_6 ( ( unsigned short ) V_349 , V_3 -> V_350 ) ;
}
static void F_37 ( unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_266 , V_340 , time , V_199 , V_269 , V_351 , V_352 , V_353 , V_354 , V_355 , V_356 , V_357 , V_346 , V_302 ,
V_301 , V_347 ;
const unsigned short * V_358 = NULL ;
if ( V_191 <= 0x13 )
V_266 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_266 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_266 &= V_359 ;
time = 64 ;
if ( V_266 == 0x00 )
V_358 = V_360 ;
else if ( V_266 == 0x08 )
V_358 = V_361 ;
else if ( V_266 == 0x10 )
V_358 = V_362 ;
else if ( V_266 == 0x18 ) {
time = 256 ;
V_358 = V_363 ;
}
if ( time == 256 )
V_269 = 16 ;
else
V_269 = time ;
F_6 ( 0xFF , V_3 -> V_364 ) ;
F_6 ( 0x00 , V_3 -> V_365 ) ;
for ( V_199 = 0 ; V_199 < V_269 ; V_199 ++ ) {
V_266 = V_358 [ V_199 ] ;
for ( V_351 = 0 ; V_351 < 3 ; V_351 ++ ) {
V_340 = 0 ;
if ( V_266 & 0x01 )
V_340 = 0x2A ;
if ( V_266 & 0x02 )
V_340 += 0x15 ;
F_6 ( V_340 , V_3 -> V_350 ) ;
V_266 = V_266 >> 2 ;
}
}
if ( time == 256 ) {
for ( V_199 = 16 ; V_199 < 32 ; V_199 ++ ) {
V_266 = V_358 [ V_199 ] ;
for ( V_351 = 0 ; V_351 < 3 ; V_351 ++ )
F_6 ( V_266 , V_3 -> V_350 ) ;
}
V_355 = 32 ;
for ( V_352 = 0 ; V_352 < 9 ; V_352 ++ ) {
V_356 = V_355 ;
V_357 = V_355 + 0x04 ;
V_346 = 0 ;
for ( V_353 = 0 ; V_353 < 3 ; V_353 ++ ) {
for ( V_354 = 0 ; V_354 < 5 ; V_354 ++ ) {
V_347 = V_358 [ V_355 ] ;
V_301 = V_358 [ V_356 ] ;
V_302 = V_358 [ V_357 ] ;
V_355 ++ ;
F_36 ( V_346 , V_301 , V_302 , V_347 , V_3 ) ;
}
V_355 -= 2 ;
for ( V_354 = 0 ; V_354 < 3 ; V_354 ++ ) {
V_347 = V_358 [ V_357 ] ;
V_301 = V_358 [ V_356 ] ;
V_302 = V_358 [ V_355 ] ;
V_355 -- ;
F_36 ( V_346 , V_301 , V_302 , V_347 , V_3 ) ;
}
V_346 ++ ;
}
V_355 += 5 ;
}
}
}
static void F_38 ( unsigned short V_191 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_294 , V_343 , V_366 , V_200 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_300 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_233 ;
if ( V_191 <= 0x13 )
V_294 = V_3 -> V_4 [ V_192 ] . V_300 ;
else
V_294 = V_3 -> V_10 [ V_192 ] . V_233 ;
if ( V_191 <= 0x13 ) {
V_343 = V_3 -> V_33 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_33 [ V_294 ] . V_297 ;
} else {
V_343 = V_3 -> V_36 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_36 [ V_294 ] . V_297 ;
}
if ( V_191 > 0x13 ) {
if ( V_200 & V_298 )
V_343 = V_343 << 1 ;
if ( V_200 & V_271 )
V_366 = V_366 << 1 ;
}
if ( V_343 == 720 )
V_343 = 640 ;
V_3 -> V_367 = V_343 ;
V_3 -> V_368 = V_343 ;
V_3 -> V_369 = V_366 ;
V_3 -> V_370 = V_366 ;
}
static void * F_39 ( unsigned short V_371 , unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_199 , V_372 , V_295 , V_230 , V_373 , V_200 , V_358 ;
struct V_374 * V_375 = NULL ;
V_230 = V_371 ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_373 = V_3 -> V_4 [ V_192 ] . V_317 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_373 = V_3 -> V_13 [ V_228 ] . V_318 ;
}
V_373 = V_373 & 0x0f ;
if ( V_230 <= 1 ) {
if ( V_191 <= 0x13 ) {
V_373 = V_3 -> V_4 [ V_192 ] . V_317 ;
} else {
V_373 = V_3 -> V_13 [ V_228 ] .
V_318 ;
}
if ( V_3 -> V_48 & V_205 ) {
if ( V_191 <= 0x13 )
V_373 = V_3 -> V_4 [ V_192 ] .
V_376 ;
else
V_373 = V_3 -> V_13 [
V_228 ] .
V_377 ;
}
if ( V_230 & 0x01 )
V_373 = ( V_373 >> 4 ) ;
V_373 = ( V_373 & 0x0f ) ;
}
V_295 = V_378 [ V_230 ] ;
if ( V_3 -> V_47 & V_379 ) {
if ( ( V_230 == 5 ) || ( V_230 ) == 7 )
V_295 = V_380 ;
else if ( ( V_230 == 3 ) || ( V_230 == 8 ) )
V_295 = V_381 ;
}
switch ( V_230 ) {
case 0 :
case 1 :
V_375 = V_382 ;
break;
case 2 :
V_375 = V_383 ;
break;
case 3 :
V_375 = V_384 ;
break;
case 4 :
V_375 = V_385 ;
break;
case 5 :
V_375 = V_386 ;
break;
case 6 :
V_375 = V_387 ;
break;
case 7 :
case 8 :
case 9 :
V_375 = NULL ;
break;
default:
break;
}
if ( V_375 == NULL )
return NULL ;
V_358 = V_230 ;
V_199 = 0 ;
while ( V_375 [ V_199 ] . V_388 != 0xff ) {
V_372 = V_3 -> V_45 ;
if ( V_230 & 0x0080 ) {
V_230 &= ( ~ 0x0080 ) ;
V_372 = V_3 -> V_46 ;
}
if ( V_3 -> V_47 & V_379 )
V_372 &= ( ~ V_389 ) ;
if ( V_375 [ V_199 ] . V_388 == V_372 ) {
V_230 = V_375 [ V_199 ] . V_390 ;
V_372 = V_3 -> V_47 ;
if ( V_191 <= 0x13 )
V_372 |= V_391 ;
if ( V_200 & V_298 )
V_372 |= V_392 ;
V_230 &= V_372 ;
if ( V_230 == V_375 [ V_199 ] . V_393 )
break;
}
V_199 ++ ;
}
if ( V_358 == 0 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_395 [ V_373 ] ;
break;
case 1 :
return & V_396 [ V_373 ] ;
break;
case 2 :
return & V_397 [ V_373 ] ;
break;
case 3 :
return & V_398 [ V_373 ] ;
break;
case 4 :
return & V_399 [ V_373 ] ;
break;
case 5 :
return & V_400 [ V_373 ] ;
break;
case 6 :
return & V_401 [ V_373 ] ;
break;
case 7 :
return & V_402 [ V_373 ] ;
break;
case 8 :
return & V_403 [ V_373 ] ;
break;
case 9 :
return & V_404 [ V_373 ] ;
break;
case 10 :
return & V_405 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 1 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_406 [ V_373 ] ;
break;
case 1 :
return & V_407 [ V_373 ] ;
break;
case 2 :
return & V_408 [ V_373 ] ;
break;
case 3 :
return & V_409 [ V_373 ] ;
break;
case 4 :
return & V_410 [ V_373 ] ;
break;
case 5 :
return & V_411 [ V_373 ] ;
break;
case 6 :
return & V_412 [ V_373 ] ;
break;
case 7 :
return & V_413 [ V_373 ] ;
break;
case 8 :
return & V_414 [ V_373 ] ;
break;
case 9 :
return & V_415 [ V_373 ] ;
break;
case 10 :
return & V_416 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 2 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_417 [ V_373 ] ;
break;
case 1 :
return & V_418 [ V_373 ] ;
break;
case 2 :
return & V_419 [ V_373 ] ;
break;
case 3 :
return & V_420 [ V_373 ] ;
break;
case 4 :
return & V_421 [ V_373 ] ;
break;
case 5 :
return & V_422 [ V_373 ] ;
break;
case 6 :
return & V_423 [ V_373 ] ;
break;
case 7 :
return & V_424 [ V_373 ] ;
break;
case 8 :
return & V_425 [ V_373 ] ;
break;
case 9 :
return & V_426 [ V_373 ] ;
break;
case 10 :
return & V_427 [ V_373 ] ;
break;
case 11 :
return & V_428 [ V_373 ] ;
break;
case 12 :
return & V_429 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 3 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_430 [ V_373 ] ;
break;
case 1 :
return & V_431 [ V_373 ] ;
break;
case 2 :
return & V_432 [ V_373 ] ;
break;
case 3 :
return & V_433 [ V_373 ] ;
break;
case 4 :
return & V_434 [ V_373 ] ;
break;
case 5 :
return & V_435 [ V_373 ] ;
break;
case 6 :
return & V_436 [ V_373 ] ;
break;
case 7 :
return & V_437 [ V_373 ] ;
break;
case 8 :
return & V_438 [ V_373 ] ;
break;
case 9 :
return & V_439 [ V_373 ] ;
break;
case 10 :
return & V_440 [ V_373 ] ;
break;
case 11 :
return & V_441 [ V_373 ] ;
break;
case 12 :
return & V_442 [ V_373 ] ;
break;
case 13 :
return & V_443 [ V_373 ] ;
break;
case 14 :
return & V_444 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 4 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_445 [ V_373 ] ;
break;
case 1 :
return & V_446 [ V_373 ] ;
break;
case 2 :
return & V_447 [ V_373 ] ;
break;
case 3 :
return & V_448 [ V_373 ] ;
break;
case 4 :
return & V_449 [ V_373 ] ;
break;
case 5 :
return & V_450 [ V_373 ] ;
break;
case 6 :
case 7 :
return & V_451 [ V_373 ] ;
break;
case 8 :
return & V_452 [ V_373 ] ;
break;
case 9 :
return & V_453 [ V_373 ] ;
break;
case 10 :
return & V_454 [ V_373 ] ;
break;
case 11 :
return & V_455 [ V_373 ] ;
break;
case 12 :
return & V_456 [ V_373 ] ;
break;
case 13 :
return & V_456 [ V_373 ] ;
break;
case 14 :
return & V_457 [ V_373 ] ;
break;
case 15 :
case 16 :
return & V_458 [ V_373 ] ;
break;
case 17 :
return & V_459 [ V_373 ] ;
break;
case 18 :
return & V_460 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 5 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_461 [ V_373 ] ;
break;
case 1 :
return & V_462 [ V_373 ] ;
break;
case 2 :
return & V_463 [ V_373 ] ;
break;
case 3 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_464 [ V_373 ] ;
else
return & V_465 [ V_373 ] ;
break;
case 4 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_466 [ V_373 ] ;
else
return & V_467 [ V_373 ] ;
break;
case 5 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_468 [ V_373 ] ;
else
return & V_469 [ V_373 ] ;
break;
case 6 :
case 7 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_470 [ V_373 ] ;
else
return & V_471 [ V_373 ] ;
break;
case 8 :
return & V_472 [ V_373 ] ;
break;
case 9 :
return & V_473 [ V_373 ] ;
break;
case 10 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_474 [ V_373 ] ;
else
return & V_475 [ V_373 ] ;
break;
case 11 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_476 [ V_373 ] ;
else
return & V_477 [ V_373 ] ;
break;
case 12 :
return & V_478 [ V_373 ] ;
break;
case 13 :
case 14 :
return & V_479 [ V_373 ] ;
break;
case 15 :
return & V_480 [ V_373 ] ;
break;
case 16 :
case 17 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_481 [ V_373 ] ;
else
return & V_482 [ V_373 ] ;
break;
case 18 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_483 [ V_373 ] ;
else
return & V_484 [ V_373 ] ;
break;
case 19 :
return & V_485 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 6 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_486 [ V_373 ] ;
break;
case 1 :
return & V_487 [ V_373 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void * F_40 ( unsigned short V_371 , unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_199 , V_372 , V_230 , V_373 , V_200 , V_358 ;
struct V_488 * V_375 = NULL ;
V_230 = V_371 ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_373 = V_3 -> V_4 [ V_192 ] . V_317 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_373 = V_3 -> V_13 [ V_228 ] . V_318 ;
}
V_373 = V_373 & 0x3f ;
V_358 = V_230 ;
switch ( V_230 ) {
case 0 :
V_375 = NULL ;
break;
case 1 :
V_375 = NULL ;
break;
case 2 :
case 6 :
V_375 = V_489 ;
break;
case 3 :
V_375 = NULL ;
break;
case 4 :
V_375 = V_490 ;
break;
case 5 :
V_375 = NULL ;
break;
default:
break;
}
if ( V_375 == NULL )
return NULL ;
V_372 = V_3 -> V_49 ;
if ( V_3 -> V_48 & V_208 )
V_372 = V_372 | V_491 ;
if ( V_200 & V_298 )
V_372 = V_372 | V_492 ;
V_199 = 0 ;
while ( V_375 [ V_199 ] . V_390 != 0xffff ) {
if ( ( V_372 & V_375 [ V_199 ] . V_390 ) == V_375 [ V_199 ] . V_393 )
break;
V_199 ++ ;
}
if ( V_358 == 0x00 ) {
} else if ( V_358 == 0x01 ) {
} else if ( V_358 == 0x04 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_493 [ V_373 ] ;
break;
case 1 :
return & V_494 [ V_373 ] ;
break;
case 2 :
return & V_495 [ V_373 ] ;
break;
case 3 :
return & V_496 [ V_373 ] ;
break;
case 4 :
return & V_497 [ V_373 ] ;
break;
case 5 :
return & V_498 [ V_373 ] ;
break;
case 6 :
return & V_499 [ V_373 ] ;
break;
case 7 :
return & V_500 [ V_373 ] ;
break;
case 8 :
return & V_501 [ V_373 ] ;
break;
case 9 :
return & V_502 [ V_373 ] ;
break;
case 10 :
return & V_503 [ V_373 ] ;
break;
case 11 :
return & V_504 [ V_373 ] ;
break;
case 12 :
return & V_494 [ V_373 ] ;
break;
case 13 :
return & V_505 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 0x02 ) {
switch ( V_375 [ V_199 ] . V_394 ) {
case 0 :
return & V_506 [ V_373 ] ;
break;
case 1 :
return & V_507 [ V_373 ] ;
break;
case 2 :
return & V_508 [ V_373 ] ;
break;
case 3 :
return & V_509 [ V_373 ] ;
break;
default:
break;
}
} else if ( V_358 == 0x06 ) {
}
return NULL ;
}
static void F_41 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_230 ;
struct V_510 * V_511 = NULL ;
V_230 = 2 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_511 = (struct V_510 * ) F_39 ( V_230 ,
V_191 , V_192 , V_228 ,
V_3 ) ;
V_3 -> V_512 = V_511 -> V_512 ;
V_3 -> V_513 = V_511 -> V_513 ;
V_3 -> V_514 = V_511 -> V_515 ;
V_3 -> V_516 = V_511 -> V_517 ;
}
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
if ( ! ( V_3 -> V_47 & ( V_518
| V_379 ) ) ) {
if ( ( V_3 -> V_45 == V_262 ) ||
( V_3 -> V_45 == V_336 ) ) {
V_3 -> V_368 = 1024 ;
V_3 -> V_370 = 768 ;
} else if ( ( V_3 -> V_45 == V_241 ) ||
( V_3 -> V_45 == V_519 ) ) {
V_3 -> V_368 = 1280 ;
V_3 -> V_370 = 1024 ;
} else if ( V_3 -> V_45 == V_520 ) {
V_3 -> V_368 = 1400 ;
V_3 -> V_370 = 1050 ;
} else {
V_3 -> V_368 = 1600 ;
V_3 -> V_370 = 1200 ;
}
}
}
}
static void F_42 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned char V_193 ;
unsigned short V_230 , V_199 ;
struct V_521 * V_511 = NULL ;
struct V_522 * V_523 = NULL ;
if ( V_191 <= 0x13 )
V_193 = V_3 -> V_4 [ V_192 ] . V_317 ;
else
V_193 = V_3 -> V_13 [ V_228 ] . V_318 ;
V_193 = V_193 & V_273 ;
V_230 = 0 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_511 = (struct V_521 * )
F_39 ( V_230 , V_191 ,
V_192 ,
V_228 ,
V_3 ) ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ )
V_3 -> V_138 [ 0 ] . V_266 [ V_199 ] = V_511 [ 0 ] . V_524 [ V_199 ] ;
}
F_18 ( V_3 , V_213 ) ;
V_230 = 1 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_523 = (struct V_522 * )
F_39 (
V_230 ,
V_191 ,
V_192 ,
V_228 ,
V_3 ) ;
for ( V_199 = 0 ; V_199 < 7 ; V_199 ++ )
V_3 -> V_141 [ 0 ] . V_266 [ V_199 ] = V_523 [ 0 ] . V_524 [ V_199 ] ;
}
F_19 ( V_192 , V_191 , V_3 ) ;
}
static unsigned short F_43 ( struct V_2 * V_3 )
{
unsigned char V_373 , V_197 , V_525 , V_199 ;
V_197 = F_8 ( V_3 -> V_215 , 0x36 ) ;
V_373 = V_197 & 0x0F ;
V_197 = V_197 & 0xF0 ;
V_199 = 0 ;
V_525 = V_3 -> V_150 [ V_199 ] . V_526 ;
while ( V_525 != 0xFF ) {
if ( V_525 & 0x80 ) {
V_373 = V_197 ;
V_525 = V_525 & ~ ( 0x80 ) ;
}
if ( V_373 == V_525 )
break;
V_199 ++ ;
V_525 = V_3 -> V_150 [ V_199 ] . V_526 ;
}
return V_199 ;
}
static unsigned short F_44 ( struct V_2 * V_3 )
{
unsigned short V_197 , V_373 , V_525 , V_199 ;
V_373 = V_3 -> V_45 ;
V_197 = V_3 -> V_46 ;
V_199 = 0 ;
V_525 = V_3 -> V_150 [ V_199 ] . V_526 ;
while ( V_525 != 0xFF ) {
if ( ( V_525 & 0x80 ) && ( V_525 != 0x80 ) ) {
V_373 = V_197 ;
V_525 &= ~ 0x80 ;
}
if ( V_373 == V_525 )
break;
V_199 ++ ;
V_525 = V_3 -> V_150 [ V_199 ] . V_526 ;
}
if ( V_525 == 0xFF ) {
V_3 -> V_45 = V_262 ;
V_3 -> V_46 = 0 ;
V_199 = 0 ;
}
return V_199 ;
}
static void F_45 ( unsigned short * V_527 ,
unsigned short * V_528 ,
struct V_2 * V_3 )
{
unsigned short V_529 ;
V_529 = F_43 ( V_3 ) ;
* V_527 = V_3 -> V_150 [ V_529 ] . V_530 ;
* V_528 = V_3 -> V_150 [ V_529 ] . V_531 ;
return;
}
static void F_46 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_230 , V_229 , V_295 , V_372 , V_532 , V_533 , V_200 ;
unsigned long V_265 , V_534 , V_303 , V_535 , V_536 ;
struct V_537 * V_511 = NULL ;
struct V_538 * V_523 = NULL ;
if ( V_191 > 0x13 )
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
else
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_230 = 3 ;
if ( V_3 -> V_47 & V_379 )
V_523 =
(struct V_538 * )
F_39 (
V_230 ,
V_191 ,
V_192 ,
V_228 ,
V_3 ) ;
else
V_511 =
(struct V_537 * )
F_39 (
V_230 ,
V_191 ,
V_192 ,
V_228 ,
V_3 ) ;
F_45 ( & V_229 , & V_230 , V_3 ) ;
V_532 = V_230 ;
V_533 = V_229 ;
if ( ( V_3 -> V_45 == V_262 ) ||
( V_3 -> V_45 == V_336 ) ) {
V_229 = 1024 ;
V_230 = 768 ;
} else if ( ( V_3 -> V_45 == V_241 ) ||
( V_3 -> V_45 == V_519 ) ) {
V_229 = 1280 ;
V_230 = 1024 ;
} else if ( V_3 -> V_45 == V_520 ) {
V_229 = 1400 ;
V_230 = 1050 ;
} else {
V_229 = 1600 ;
V_230 = 1200 ;
}
if ( V_3 -> V_47 & V_518 ) {
V_3 -> V_368 = V_229 ;
V_3 -> V_370 = V_230 ;
V_3 -> V_367 = V_229 ;
V_3 -> V_369 = V_230 ;
}
V_229 = V_3 -> V_514 ;
if ( V_3 -> V_47 & V_379 )
V_230 = V_523 -> V_539 ;
else
V_230 = V_511 -> V_539 ;
V_295 = V_3 -> V_368 ;
V_230 = V_230 & 0x0fff ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
F_4 ( V_3 -> V_540 , 0x1A , V_230 & 0x07 ) ;
V_295 = V_295 >> 3 ;
V_230 = V_230 >> 3 ;
F_4 ( V_3 -> V_540 , 0x16 ,
( unsigned short ) ( V_230 & 0xff ) ) ;
F_4 ( V_3 -> V_540 , 0x17 ,
( unsigned short ) ( V_295 & 0xff ) ) ;
V_229 = V_3 -> V_514 ;
if ( V_3 -> V_47 & V_379 )
V_230 = V_523 -> V_541 ;
else
V_230 = V_511 -> V_541 ;
V_295 = V_533 ;
if ( V_3 -> V_47 & V_379 )
V_295 = V_523 -> V_542 ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
V_229 = V_230 & 0x07 ;
V_229 = V_229 >> 5 ;
V_295 = V_295 >> 3 ;
V_230 = V_230 >> 3 ;
V_295 &= 0x1f ;
V_229 |= V_295 ;
F_4 ( V_3 -> V_540 , 0x15 , V_229 ) ;
F_4 ( V_3 -> V_540 , 0x14 ,
( unsigned short ) ( V_230 & 0xff ) ) ;
V_229 = V_3 -> V_516 ;
if ( V_3 -> V_47 & V_379 )
V_230 = V_523 -> V_543 ;
else
V_230 = V_511 -> V_543 ;
V_295 = V_3 -> V_370 ;
V_230 = V_230 & 0x0fff ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
F_4 ( V_3 -> V_540 , 0x1b ,
( unsigned short ) ( V_230 & 0xff ) ) ;
F_4 ( V_3 -> V_540 , 0x1c ,
( unsigned short ) ( V_295 & 0xff ) ) ;
V_230 = ( V_230 >> 8 ) & 0x07 ;
V_295 = ( V_295 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_540 , 0x1d ,
( unsigned short ) ( ( V_295 << 3 )
| V_230 ) ) ;
V_229 = V_3 -> V_516 ;
if ( V_3 -> V_47 & V_379 )
V_230 = V_523 -> V_544 ;
else
V_230 = V_511 -> V_544 ;
V_295 = V_532 ;
if ( V_3 -> V_47 & V_379 )
V_295 = V_523 -> V_545 ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
F_4 ( V_3 -> V_540 , 0x18 ,
( unsigned short ) ( V_230 & 0xff ) ) ;
F_14 ( V_3 -> V_540 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_295 & 0x0f ) ) ;
V_229 = ( ( V_230 >> 8 ) & 0x07 ) << 3 ;
V_230 = V_3 -> V_369 ;
if ( V_230 != V_3 -> V_370 )
V_229 |= 0x40 ;
if ( V_3 -> V_47 & V_546 )
V_229 |= 0x40 ;
F_14 ( V_3 -> V_540 , 0x1a , 0x07 ,
V_229 ) ;
V_295 = V_3 -> V_513 ;
V_230 = V_3 -> V_370 ;
V_229 = V_3 -> V_369 ;
V_295 -= V_229 ;
V_265 = V_229 ;
V_534 = ( V_265 << 18 ) / V_230 ;
V_372 = ( unsigned short ) ( ( V_265 << 18 ) % V_230 ) ;
if ( V_372 != 0 )
V_534 += 1 ;
V_303 = V_534 ;
V_536 = V_303 ;
F_4 ( V_3 -> V_540 , 0x37 ,
( unsigned short ) ( V_303 & 0xff ) ) ;
F_4 ( V_3 -> V_540 , 0x36 ,
( unsigned short ) ( ( V_303 >> 8 ) & 0xff ) ) ;
V_230 = ( unsigned short ) ( V_303 >> 16 ) ;
V_229 = V_230 & 0x03 ;
V_230 = V_3 -> V_369 ;
if ( V_230 == V_3 -> V_370 )
V_229 |= 0x04 ;
F_4 ( V_3 -> V_540 , 0x35 , V_229 ) ;
if ( V_3 -> V_147 & V_238 ) {
V_303 = V_536 ;
F_4 ( V_3 -> V_547 ,
0x3c ,
( unsigned short ) ( V_303 & 0xff ) ) ;
F_4 ( V_3 -> V_547 ,
0x3b ,
( unsigned short ) ( ( V_303 >> 8 ) &
0xff ) ) ;
V_230 = ( unsigned short ) ( V_303 >> 16 ) ;
F_14 ( V_3 -> V_547 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_230 &
0xff ) << 6 ) ) ;
V_295 = V_3 -> V_369 ;
if ( V_295 == V_3 -> V_370 )
F_14 ( V_3 -> V_547 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_14 ( V_3 -> V_547 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_295 = V_3 -> V_367 ;
V_230 = V_3 -> V_368 ;
V_534 = V_295 << 16 ;
V_229 = ( unsigned short ) ( V_534 / V_230 ) ;
if ( ( V_230 & 0xffff ) == ( V_295 & 0xffff ) )
V_229 = 65535 ;
V_535 = V_229 ;
V_534 = V_3 -> V_367 << 16 ;
V_534 /= V_535 ;
V_535 = V_535 << 16 ;
V_534 -= 1 ;
V_535 = ( V_535 & 0xffff0000 ) + ( V_534 & 0xffff ) ;
V_229 = ( unsigned short ) ( V_535 & 0xff ) ;
F_4 ( V_3 -> V_540 , 0x1f , V_229 ) ;
V_534 = V_3 -> V_369 << 18 ;
V_534 = V_534 / V_536 ;
V_230 = ( unsigned short ) ( V_534 & 0xffff ) ;
if ( V_3 -> V_45 == V_262 )
V_230 -= 1 ;
V_229 = ( ( V_230 >> 8 ) & 0xff ) << 3 ;
V_229 |= ( unsigned short ) ( ( V_535 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_540 , 0x20 ,
( unsigned short ) ( V_229 & 0xff ) ) ;
F_4 ( V_3 -> V_540 , 0x21 ,
( unsigned short ) ( V_230 & 0xff ) ) ;
V_535 = V_535 >> 16 ;
if ( V_200 & V_298 )
V_535 = V_535 >> 1 ;
F_4 ( V_3 -> V_540 , 0x22 ,
( unsigned short ) ( ( V_535 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_540 , 0x23 ,
( unsigned short ) ( V_535 & 0xff ) ) ;
}
static void F_47 ( unsigned char * V_548 , unsigned char * V_549 ,
struct V_2 * V_3 )
{
unsigned short V_193 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_193 = F_44 ( V_3 ) ;
if ( V_3 -> V_48 & V_207 ) {
* V_548 = V_3 -> V_150 [ V_193 ] . V_550 ;
* V_549 = V_3 -> V_150 [ V_193 ] . V_551 ;
} else {
* V_548 = V_3 -> V_150 [ V_193 ] . V_552 ;
* V_549 = V_3 -> V_150 [ V_193 ] . V_553 ;
}
}
return;
}
static unsigned char F_48 ( unsigned short V_228 ,
unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_193 , V_200 ;
unsigned char V_373 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
if ( ( V_3 -> V_249 & V_554 ) &&
( ! ( V_3 -> V_47 & V_379 ) ) ) {
V_193 = F_43 ( V_3 ) ;
V_373 = V_3 -> V_150 [ V_193 ] . V_555 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) )
return V_373 ;
if ( V_3 -> V_147 &
( V_256 |
V_257 |
V_148 |
V_149 |
V_238 ) ) {
if ( V_3 -> V_48 & V_244 ) {
V_373 = V_320 ;
if ( ! ( V_3 -> V_49 & V_319 ) )
V_373 = V_321 ;
if ( V_3 -> V_49 & V_250 ) {
V_373 = V_322 ;
if ( ! ( V_200 & V_219 ) )
V_373 = V_323 ;
}
return V_373 ;
}
if ( V_3 -> V_49 & V_556 ) {
V_373 = V_324 ;
return V_373 ;
}
if ( V_3 -> V_49 & V_557 ) {
V_373 = V_326 ;
return V_373 ;
}
V_373 = V_558 ;
if ( ! ( V_3 -> V_49 & V_559 ) ) {
V_373 = V_330 ;
if ( ! ( V_3 -> V_49 & V_319 ) )
V_373 = V_331 ;
}
if ( V_3 -> V_48 & V_206 )
return V_373 ;
}
}
V_373 = ( unsigned char ) F_10 ( ( V_3 -> V_332 + 0x02 ) ) ;
V_373 = V_373 >> 2 ;
V_373 &= 0x03 ;
if ( ( V_3 -> V_47 & V_379 ) && ( V_200 & V_219 ) )
V_373 = V_373 ^ V_373 ;
if ( V_191 <= 0x13 )
return V_373 ;
V_373 = V_3 -> V_13 [ V_228 ] . V_333 ;
return V_373 ;
}
static void F_49 ( unsigned char V_373 , unsigned char * V_548 ,
unsigned char * V_549 , struct V_2 * V_3 )
{
if ( V_3 -> V_147 & ( V_560 | V_256 | V_257
| V_148 | V_149 | V_238 ) ) {
if ( ( ! ( V_3 -> V_48 & V_205 ) ) && ( V_3 -> V_249
& V_554 ) ) {
* V_548 = ( unsigned char ) V_30 [ V_373 ] . V_226 ;
* V_549 = V_30 [ V_373 ] . V_227 ;
}
} else {
* V_548 = V_27 [ V_373 ] . V_226 ;
* V_549 = V_27 [ V_373 ] . V_227 ;
}
}
static void F_50 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned char V_548 , V_549 , V_373 ;
int V_199 ;
V_373 = F_48 ( V_228 , V_191 , V_192 ,
V_3 ) ;
F_49 ( V_373 , & V_548 , & V_549 , V_3 ) ;
F_47 ( & V_548 , & V_549 , V_3 ) ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
F_14 ( V_3 -> V_215 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_199 ) ) ;
if ( ( ! ( V_3 -> V_48 & V_205 ) )
&& ( ! ( V_3 -> V_48 & V_208 ) ) ) {
F_4 ( V_3 -> V_203 , 0x2e , V_548 ) ;
F_4 ( V_3 -> V_203 , 0x2f , V_549 ) ;
} else {
F_4 ( V_3 -> V_203 , 0x2b , V_548 ) ;
F_4 ( V_3 -> V_203 , 0x2c , V_549 ) ;
}
}
}
static void F_51 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_561 , V_562 , V_265 , V_525 , V_229 ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
V_561 = 0 ;
V_562 = 0 ;
V_265 = F_8 ( V_3 -> V_203 , 0x01 ) ;
if ( ! ( V_265 & 0x20 ) ) {
V_265 = F_8 ( V_3 -> V_215 , 0x17 ) ;
if ( V_265 & 0x80 ) {
V_265 = F_8 ( V_3 -> V_215 , 0x53 ) ;
if ( ! ( V_265 & 0x40 ) )
V_561 |= V_563 ;
}
}
V_265 = F_8 ( V_3 -> V_540 , 0x2e ) ;
V_265 &= 0x0f ;
if ( ! ( V_265 == 0x08 ) ) {
V_229 = F_8 ( V_3 -> V_540 , 0x13 ) ;
if ( V_229 & 0x04 )
V_561 = V_561 | V_564 ;
V_265 &= 0x05 ;
if ( ! ( V_561 & V_564 ) )
if ( V_265 == 0x01 )
V_561 |= V_565 ;
if ( V_265 == 0x04 )
V_561 |= V_564 ;
if ( V_265 == 0x05 ) {
V_265 = F_8 ( V_3 -> V_566 , 0x00 ) ;
if ( ! ( V_265 & 0x08 ) )
V_562 |= V_567 ;
if ( ! ( V_265 & 0x04 ) )
V_562 |= V_568 ;
if ( V_265 & 0x02 )
V_562 |= V_569 ;
if ( V_3 -> V_48 & V_244 ) {
if ( V_265 & 0x01 )
V_562 |= V_570 ;
}
if ( V_3 -> V_48 & V_254 ) {
V_265 = F_8 (
V_3 -> V_566 ,
0x4d ) ;
if ( V_265 & 0x10 )
V_562 |= V_571 ;
}
if ( V_562 != 0 )
V_561 |= V_572 ;
}
}
V_265 = F_8 ( V_3 -> V_215 , 0x3d ) ;
if ( V_561 & V_564 ) {
if ( ( V_3 -> V_249 & V_573 ) ) {
if ( V_265 & V_572 )
V_561 |= V_572 ;
}
}
V_265 = V_561 ;
V_525 = ~ V_574 ;
F_14 ( V_3 -> V_215 , 0x3d , V_525 , V_265 ) ;
if ( ! ( V_3 -> V_249 & V_573 ) )
F_4 ( V_3 -> V_215 , 0x3e , V_562 ) ;
} else {
return;
}
}
void F_52 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
V_3 -> V_575 = V_213 -> V_270 ;
}
void F_53 ( struct V_2 * V_3 )
{
unsigned short V_576 , V_230 , V_197 ;
if ( V_3 -> V_235 == 0 ) {
V_230 = V_257 ;
V_576 = F_8 ( V_3 -> V_547 , 0x00 ) ;
if ( V_576 != 0x02 ) {
V_230 = V_560 ;
V_576 = F_8 ( V_3 -> V_547 , 0x01 ) ;
if ( V_576 >= 0xB0 ) {
V_230 = V_256 ;
if ( V_576 >= 0xC0 ) {
V_230 = V_238 ;
if ( V_576 >= 0xD0 ) {
V_230 = V_148 ;
if ( V_576 >= 0xE0 ) {
V_230 = V_149 ;
V_197 = F_8 (
V_3 -> V_547 ,
0x39 ) ;
if ( V_197 != 0xFF )
V_230 =
V_238 ;
}
}
}
if ( V_230 & ( V_256 | V_257 ) ) {
V_576 = F_8 (
V_3 -> V_547 ,
0x23 ) ;
if ( ! ( V_576 & 0x02 ) )
V_230 = V_230 | V_577 ;
}
}
}
V_3 -> V_147 = V_230 ;
}
}
void F_54 ( unsigned short V_191 , unsigned short V_192 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_229 , V_578 , V_230 , V_265 , V_200 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_3 -> V_249 = 0 ;
V_3 -> V_195 = V_200 & V_579 ;
V_230 = 0 ;
if ( V_3 -> V_147 & 0xFFFF ) {
V_265 = F_8 ( V_3 -> V_215 , 0x30 ) ;
V_230 = V_230 | V_265 ;
V_265 = F_8 ( V_3 -> V_215 , 0x31 ) ;
V_578 = V_265 ;
V_578 = V_578 << 8 ;
V_229 = V_265 << 8 ;
V_230 = V_230 | V_229 ;
V_265 = ( V_580 | V_254 | V_205
| V_208 | V_581 ) ;
V_265 = 0xFFFF ^ V_265 ;
V_230 &= V_265 ;
V_265 = F_8 ( V_3 -> V_215 , 0x38 ) ;
if ( V_3 -> V_582 == 1 ) {
if ( ( V_3 -> V_575 >= V_163 )
|| ( V_3 -> V_575 >= V_583 ) ) {
if ( V_3 -> V_235 == 0 ) {
if ( V_3 -> V_147 &
( V_257 |
V_148 |
V_149 |
V_238 ) ) {
if ( V_265 & V_584 ) {
V_230 |=
V_580 ;
if ( V_265 & V_585 )
V_230 |=
V_205 ;
}
}
}
}
}
if ( V_3 -> V_586 == 1 ) {
if ( ( ( V_3 -> V_235 == 0 ) &&
( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) ||
( V_3 -> V_147 & V_238 ) ) ) ) {
if ( V_265 & V_587 ) {
if ( V_3 -> V_588 == 1 ) {
V_265 = F_8 (
V_3 -> V_215 ,
0x35 ) ;
V_265 &= V_589 ;
V_230 |= V_244 ;
if ( V_265 != V_590 ) {
V_230 &=
( ~ V_244 ) ;
V_230 |=
V_254 ;
}
}
}
}
}
V_229 = V_578 ;
if ( V_3 -> V_235 == 0 ) {
if ( V_3 -> V_586 == 1 ) {
if ( V_3 -> V_588 == 1 )
V_265 = 0x09FC ;
else
V_265 = 0x097C ;
} else {
if ( V_3 -> V_588 == 1 )
V_265 = 0x01FC ;
else
V_265 = 0x017C ;
}
} else {
V_265 = V_207 ;
}
if ( ! ( V_230 & V_265 ) ) {
V_229 |= V_581 ;
V_230 = 0 ;
}
if ( V_3 -> V_582 == 1 ) {
if ( ! ( V_3 -> V_147 & V_577 ) ) {
if ( V_230 & V_205 ) {
if ( V_230 & V_591 )
V_230 &= ( ~ ( V_207 |
V_236 |
V_592 ) ) ;
else
V_230 &= ( ~ ( V_207 |
V_236 |
V_206 |
V_592 ) ) ;
}
}
}
if ( ! ( V_230 & ( V_592 | V_591 ) ) ) {
if ( V_3 -> V_593 == 1 ) {
if ( V_230 & V_236 ) {
V_230 &= ( 0xFF00 |
V_236 |
V_592 |
V_591 ) ;
V_230 &= ( 0x00FF | ( ~ V_254 ) ) ;
}
} else {
V_230 &= ( ~ ( V_236 |
V_207 |
V_206 ) ) ;
}
}
if ( ! ( V_3 -> V_147 & V_577 ) ) {
if ( V_230 & V_207 ) {
V_230 &= ( 0xFF00 |
V_207 |
V_592 |
V_591 ) ;
V_230 &= ( 0x00FF | ( ~ V_254 ) ) ;
}
}
if ( V_230 & V_253 ) {
V_230 &= ( 0xFF00 |
V_253 |
V_592 |
V_591 ) ;
V_230 &= ( 0x00FF | ( ~ V_254 ) ) ;
}
if ( V_3 -> V_586 == 1 ) {
if ( V_230 & V_254 )
V_230 &= ( 0xFF00 |
V_592 |
V_591 ) ;
}
if ( V_3 -> V_588 == 1 ) {
if ( V_230 & V_244 )
V_230 &= ( 0xFF00 |
V_244 |
V_592 |
V_591 ) ;
}
if ( V_229 & V_581 ) {
if ( ! ( V_230 & ( V_592 | V_591 ) ) )
V_230 = V_581 ;
}
if ( ! ( V_230 & V_581 ) ) {
if ( ( ! ( V_230 & V_594 ) ) ||
( ! ( V_200 & V_595 ) ) ) {
if ( V_3 -> V_582 == 1 ) {
if ( ! ( V_230 & V_205 ) )
V_230 |= ( V_208 |
V_591 ) ;
}
}
if ( ( V_230 & V_208 ) &&
( V_230 & V_205 ) ) {
V_230 ^= ( V_207 |
V_205 |
V_580 ) ;
V_3 -> V_249 |= V_573 ;
}
}
}
V_3 -> V_48 = V_230 ;
}
void F_55 ( unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_265 , V_230 = 0 , V_231 = 0 , V_200 , V_596 ;
V_230 = 0 ;
V_231 = 0 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] .
V_201 ;
V_231 = V_3 -> V_4 [ V_192 ] .
V_300 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] .
V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] .
V_233 ;
}
if ( V_3 -> V_48 & V_206 ) {
V_265 = F_8 ( V_3 -> V_215 , 0x35 ) ;
V_230 = V_265 ;
if ( V_230 & V_259 ) {
V_230 &= ( V_597 |
V_598 |
V_599 |
V_259 ) ;
if ( V_230 & V_598 )
V_230 &= ~ V_259 ;
} else
V_230 &= ( V_597 |
V_600 |
V_259 ) ;
}
if ( V_3 -> V_235 == 0 ) {
if ( V_3 -> V_48 & V_253 )
V_230 |= V_259 ;
}
if ( V_3 -> V_586 == 1 ) {
if ( V_3 -> V_48 & V_254 ) {
V_596 = F_8 ( V_3 -> V_215 , 0x35 ) ;
V_596 &= V_589 ;
if ( V_596 == V_601 )
V_230 |= V_602 ;
if ( V_596 == V_603 )
V_230 = V_230 | V_557 ;
if ( V_596 == V_604 )
V_230 = V_230 | V_556 ;
}
}
if ( V_3 -> V_588 == 1 ) {
if ( V_3 -> V_48 & V_244 )
V_230 = V_230 | V_605 | V_259 ;
}
if ( V_3 -> V_235 == 0 ) {
if ( ( V_3 -> V_48 & V_208 ) &&
( ! ( V_3 -> V_48 & V_261 ) ) )
V_230 |= V_250 ;
if ( ! ( V_230 & V_259 ) &&
( V_200 > 13 ) &&
( V_231 == 8 ) )
V_230 |= V_559 ;
V_230 |= V_319 ;
if ( V_3 -> V_48 & V_244 ) {
if ( V_3 -> V_48 & V_208 )
V_230 &= ( ~ V_319 ) ;
} else {
if ( V_230 &
( V_557 | V_556 ) )
V_230 &= ( ~ V_319 ) ;
else if ( ! ( V_3 -> V_147 &
( V_256 |
V_257 |
V_148 |
V_149 |
V_238 ) ) ) {
if ( V_230 & V_250 )
V_230 &= ( ~ V_319 ) ;
}
}
}
}
V_3 -> V_49 = V_230 ;
}
unsigned char F_56 ( unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_265 , V_229 , V_230 , V_200 , V_231 = 0 , V_606 ;
V_3 -> V_45 = 0 ;
V_3 -> V_46 = 0 ;
V_3 -> V_47 = 0 ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
}
V_265 = F_8 ( V_3 -> V_215 , 0x36 ) ;
V_230 = V_265 & 0x0F ;
if ( V_230 == 0 )
V_230 = V_262 ;
if ( ( V_230 == V_262 ) || ( V_230 == V_241 ) ) {
if ( V_3 -> V_48 & V_594 ) {
V_229 = F_8 ( V_3 -> V_215 , 0x33 ) ;
if ( V_3 -> V_48 & V_205 )
V_229 &= 0x0F ;
else
V_229 = V_229 >> 4 ;
if ( ( V_231 == 6 ) || ( V_231 == 9 ) ) {
if ( V_229 >= 3 )
V_230 |= V_607 ;
} else if ( ( V_231 == 7 ) || ( V_231 == 8 ) ) {
if ( V_229 >= 4 )
V_230 |= V_607 ;
}
}
}
V_3 -> V_45 = V_230 ;
if ( ! ( V_3 -> V_48 & ( V_207 | V_205 ) ) )
return 0 ;
V_230 = 0 ;
V_265 = F_8 ( V_3 -> V_215 , 0x37 ) ;
V_265 &= ( V_608 | V_243 | V_609 | V_610 ) ;
V_230 |= V_265 ;
V_606 = F_44 ( V_3 ) ;
V_229 = V_3 -> V_150 [ V_606 ] . V_611 ;
if ( V_3 -> V_235 == 0 ) {
if ( ( ( V_3 -> V_147 & V_149 ) || ( V_3 -> V_147
& V_238 ) ) && ( V_229 & V_612 ) ) {
V_230 |= V_613 ;
}
}
if ( V_3 -> V_235 == 0 ) {
if ( ( V_3 -> V_45 == V_520 ) && ( V_3 -> V_48
& V_207 ) && ( V_191 > 0x13 ) && ( V_231
== 9 ) && ( ! ( V_230 & V_379 ) ) )
V_230 |= V_518 ;
}
if ( V_3 -> V_614 == 1 ) {
if ( V_200 & V_298 ) {
if ( ! ( V_230 & V_518 ) ) {
V_230 |= V_546 ;
} else {
if ( V_191 > 0x13 ) {
if ( V_3 -> V_45
== V_262 ) {
if ( V_231 == 4 ) {
V_230 |= V_546 ;
}
}
}
}
}
}
if ( V_3 -> V_48 & V_208 ) {
if ( V_3 -> V_48 & V_261 )
V_230 |= V_615 ;
} else {
V_230 |= V_615 ;
}
V_3 -> V_47 = V_230 ;
if ( V_3 -> V_235 == 0 ) {
if ( V_229 & ( V_616 | V_617 ) ) {
if ( V_3 -> V_48 & V_208 ) {
if ( ! ( V_229 & V_616 ) ) {
if ( V_191 <= 0x13 ) {
V_3 -> V_48 &=
~ ( V_591 |
V_208 |
V_207 ) ;
V_3 -> V_48 |=
V_205 |
V_580 ;
}
}
}
}
}
return 1 ;
}
unsigned char F_57 ( unsigned short V_191 ,
unsigned short * V_192 , struct V_2 * V_3 )
{
if ( V_191 <= 5 )
V_191 |= 1 ;
if ( V_191 <= 0x13 ) {
for ( * V_192 = 0 ; ; ( * V_192 ) ++ ) {
if ( V_3 -> V_4 [ * V_192 ] . V_618 ==
V_191 )
break;
if ( V_3 -> V_4 [ * V_192 ] . V_618 ==
0xFF )
return 0 ;
}
if ( V_191 == 0x07 )
( * V_192 ) ++ ;
if ( V_191 <= 3 )
( * V_192 ) += 2 ;
} else {
for ( * V_192 = 0 ; ; ( * V_192 ) ++ ) {
if ( V_3 -> V_10 [ * V_192 ] . V_619 ==
V_191 )
break;
if ( V_3 -> V_10 [ * V_192 ] . V_619 ==
0xFF )
return 0 ;
}
}
return 1 ;
}
static unsigned char F_58 ( unsigned char V_620 )
{
unsigned char V_621 = 0 ;
unsigned char V_199 = 0 ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ ) {
V_621 = V_621 << 1 ;
V_621 |= ( V_620 >> V_199 ) & 1 ;
}
return V_621 ;
}
static unsigned char F_59 ( struct V_2 * V_3 )
{
unsigned char V_622 , V_265 ;
V_622 = F_8 ( V_3 -> V_215 , 0x4A ) ;
F_15 ( V_3 -> V_215 , 0x4A , ~ 0x23 ) ;
V_265 = F_8 ( V_3 -> V_215 , 0x48 ) ;
V_265 = F_58 ( V_265 ) ;
V_265 &= 0x23 ;
F_4 ( V_3 -> V_215 , 0x4A , V_622 ) ;
return V_265 ;
}
static unsigned char F_60 ( struct V_2 * V_3 )
{
unsigned char V_622 , V_623 , V_265 ;
V_622 = F_8 ( V_3 -> V_215 , 0x4A ) ;
F_15 ( V_3 -> V_215 , 0x4A , ~ 0x0C ) ;
V_265 = F_8 ( V_3 -> V_215 , 0x48 ) ;
V_265 &= 0x0C ;
V_265 >>= 2 ;
F_4 ( V_3 -> V_215 , 0x4A , V_622 ) ;
V_623 = F_8 ( V_3 -> V_215 , 0xB4 ) ;
V_265 |= ( ( V_623 & 0x04 ) << 3 ) ;
return V_265 ;
}
void F_61 ( struct V_212 * V_624 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_203 , 0x01 , 0xDF , 0x00 ) ;
if ( V_624 -> V_270 == V_153 ) {
if ( V_3 -> V_235 == 1 ) {
if ( ! ( F_59 ( V_3 ) & 0x1 ) ) {
F_62 ( 0x01 , 0x01 , V_3 ) ;
F_63 ( 2 , V_3 ) ;
}
if ( ! ( F_59 ( V_3 ) & 0x20 ) )
F_62 ( 0x20 , 0x20 , V_3 ) ;
F_63 ( 3 , V_3 ) ;
F_62 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_62 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_624 -> V_270 == V_154 ) {
if ( V_3 -> V_235 == 1 ) {
if ( ! ( F_60 ( V_3 ) & 0x1 ) ) {
F_64 ( 0x01 , 0x01 , V_3 ) ;
F_63 ( 2 , V_3 ) ;
}
if ( ! ( F_60 ( V_3 ) & 0x20 ) )
F_64 ( 0x20 , 0x20 , V_3 ) ;
F_63 ( 3 , V_3 ) ;
F_64 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_64 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_65 ( struct V_212 * V_624 ,
struct V_2 * V_3 )
{
if ( V_624 -> V_270 == V_153 ) {
if ( V_3 -> V_235 == 1 ) {
F_62 ( 0x02 , 0x00 , V_3 ) ;
F_63 ( 3 , V_3 ) ;
} else {
F_62 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_624 -> V_270 == V_154 ) {
if ( ( F_60 ( V_3 ) & 0x2 ) ) {
F_64 ( 0x02 , 0x00 , V_3 ) ;
F_63 ( 3 , V_3 ) ;
}
if ( V_3 -> V_235 == 0 )
F_64 ( 0x20 , 0x00 , V_3 ) ;
}
F_14 ( V_3 -> V_203 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
while ( ( F_10 ( V_3 -> V_220 ) & 0x01 ) )
break;
while ( ! ( F_10 ( V_3 -> V_220 ) & 0x01 ) )
break;
}
static void F_67 ( struct V_2 * V_3 )
{
F_22 ( V_3 -> V_540 , 0x01 , 0x40 ) ;
}
static void F_68 ( unsigned short V_191 ,
struct V_2 * V_3 )
{
unsigned short V_534 , V_303 ;
F_4 ( V_3 -> V_215 , 0x34 , V_191 ) ;
V_534 = ( V_3 -> V_48 & V_208 ) >> 8 ;
V_303 = ~ ( V_208 >> 8 ) ;
F_14 ( V_3 -> V_215 , 0x31 , V_303 , V_534 ) ;
}
static void F_69 ( unsigned short V_191 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_343 , V_366 , V_200 , V_294 ;
V_294 = F_28 ( V_191 , V_192 , V_3 ) ;
if ( V_191 <= 0x13 ) {
V_343 = V_3 -> V_33 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_33 [ V_294 ] . V_297 ;
} else {
V_343 = V_3 -> V_36 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_36 [ V_294 ] . V_297 ;
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
if ( V_200 & V_298 )
V_343 *= 2 ;
if ( V_200 & V_271 )
V_366 *= 2 ;
}
if ( V_3 -> V_48 & V_207 ) {
if ( V_3 -> V_235 == 0 ) {
if ( V_3 -> V_45 == V_625 ) {
if ( ! ( V_3 -> V_47 & V_615 ) ) {
if ( V_366 == 1024 )
V_366 = 1056 ;
}
}
if ( V_3 -> V_45 == V_241 ) {
if ( V_366 == 400 )
V_366 = 405 ;
else if ( V_366 == 350 )
V_366 = 360 ;
if ( V_3 -> V_47 & V_615 ) {
if ( V_366 == 360 )
V_366 = 375 ;
}
}
if ( V_3 -> V_45 == V_262 ) {
if ( ! ( V_3 -> V_47 & V_615 ) ) {
if ( ! ( V_3 -> V_47
& V_243 ) ) {
if ( V_366 == 350 )
V_366 = 357 ;
else if ( V_366 == 400 )
V_366 = 420 ;
else if ( V_366 == 480 )
V_366 = 525 ;
}
}
}
}
if ( V_343 == 720 )
V_343 = 640 ;
}
V_3 -> V_367 = V_343 ;
V_3 -> V_368 = V_343 ;
V_3 -> V_369 = V_366 ;
V_3 -> V_370 = V_366 ;
}
static unsigned char F_70 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_48 & ( V_207 | V_205 ) ) &&
( V_3 -> V_47 & V_613 ) )
return 1 ;
return 0 ;
}
static void F_71 ( unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_229 , V_230 , V_534 , V_303 , V_200 = 0 , V_295 ,
V_196 , V_626 ;
V_3 -> V_627 = 1 ;
V_3 -> V_628 = 1 ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_196 = F_2 ( V_191 , V_192 , V_3 ) ;
V_229 = V_3 -> V_7 [ V_196 ] . V_216 [ 0 ] ;
V_230 = V_3 -> V_7 [ V_196 ] . V_216 [ 6 ] ;
V_534 = V_3 -> V_7 [ V_196 ] . V_216 [ 7 ] ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_626 = V_3 -> V_13 [ V_228 ] .
V_272 ;
V_626 &= V_273 ;
V_534 = ( unsigned short ) V_3 ->
V_16 [ V_626 ] . V_274 [ 0 ] ;
V_303 = ( unsigned short ) V_3 ->
V_16 [ V_626 ] . V_274 [ 5 ] ;
V_229 = ( V_534 & 0xFF ) | ( ( V_303 & 0x03 ) << 8 ) ;
V_230 = ( unsigned short ) V_3 ->
V_16 [ V_626 ] . V_274 [ 8 ] ;
V_295 = ( unsigned short ) V_3 ->
V_16 [ V_626 ] . V_274 [ 14 ] << 8 ;
V_295 &= 0x0100 ;
V_295 = V_295 << 2 ;
V_230 |= V_295 ;
V_534 = ( unsigned short ) V_3 ->
V_16 [ V_626 ] . V_274 [ 9 ] ;
}
if ( V_534 & 0x01 )
V_230 |= 0x0100 ;
if ( V_534 & 0x20 )
V_230 |= 0x0200 ;
V_229 += 5 ;
if ( V_200 & V_219 )
V_229 *= 8 ;
else
V_229 *= 9 ;
V_3 -> V_512 = V_229 ;
V_3 -> V_514 = V_229 ;
V_230 ++ ;
V_3 -> V_513 = V_230 ;
V_3 -> V_516 = V_230 ;
}
static void F_72 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_229 = 0 , V_230 , V_200 , V_231 ;
struct V_629 * V_511 = NULL ;
struct V_630 * V_631 = NULL ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_231 = V_3 -> V_4 [ V_192 ] . V_300 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
}
V_3 -> V_632 = 0 ;
V_3 -> V_633 = 50 ;
if ( V_3 -> V_48 & V_236 ) {
F_71 ( V_191 , V_192 , V_228 ,
V_3 ) ;
return;
}
V_230 = 4 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_511 = (struct V_629 * ) F_39 ( V_230 ,
V_191 , V_192 , V_228 ,
V_3 ) ;
V_3 -> V_627 = V_511 -> V_627 ;
V_3 -> V_628 = V_511 -> V_628 ;
V_3 -> V_512 = V_511 -> V_512 ;
V_3 -> V_513 = V_511 -> V_513 ;
V_3 -> V_514 = V_511 -> V_515 ;
V_3 -> V_516 = V_511 -> V_517 ;
if ( V_3 -> V_45 == V_262 ) {
V_229 = 1024 ;
V_230 = 768 ;
if ( ! ( V_3 -> V_47 & V_615 ) ) {
if ( V_3 -> V_369 == 357 )
V_230 = 527 ;
else if ( V_3 -> V_369 == 420 )
V_230 = 620 ;
else if ( V_3 -> V_369 == 525 )
V_230 = 775 ;
else if ( V_3 -> V_369 == 600 )
V_230 = 775 ;
else
V_230 = 768 ;
} else
V_230 = 768 ;
} else if ( V_3 -> V_45 == V_336 ) {
V_229 = 1024 ;
V_230 = 768 ;
} else if ( V_3 -> V_45 == V_241 ) {
V_229 = 1280 ;
if ( V_3 -> V_369 == 360 )
V_230 = 768 ;
else if ( V_3 -> V_369 == 375 )
V_230 = 800 ;
else if ( V_3 -> V_369 == 405 )
V_230 = 864 ;
else
V_230 = 1024 ;
} else if ( V_3 -> V_45 == V_519 ) {
V_229 = 1280 ;
V_230 = 1024 ;
} else if ( V_3 -> V_45 == V_242 ) {
V_229 = 1280 ;
if ( V_3 -> V_369 == 350 )
V_230 = 700 ;
else if ( V_3 -> V_369 == 400 )
V_230 = 800 ;
else if ( V_3 -> V_369 == 1024 )
V_230 = 960 ;
else
V_230 = 960 ;
} else if ( V_3 -> V_45 == V_520 ) {
V_229 = 1400 ;
V_230 = 1050 ;
if ( V_3 -> V_369 == 1024 ) {
V_229 = 1280 ;
V_230 = 1024 ;
}
} else if ( V_3 -> V_45 == V_625 ) {
V_229 = 1600 ;
V_230 = 1200 ;
if ( ! ( V_3 -> V_47 & V_615 ) ) {
if ( V_3 -> V_369 == 350 )
V_230 = 875 ;
else if ( V_3 -> V_369 == 400 )
V_230 = 1000 ;
}
}
if ( V_3 -> V_47 & V_243 ) {
V_229 = V_3 -> V_367 ;
V_230 = V_3 -> V_369 ;
}
V_3 -> V_368 = V_229 ;
V_3 -> V_370 = V_230 ;
return;
}
if ( V_3 -> V_48 & ( V_206 ) ) {
V_230 = 4 ;
V_631 = (struct V_630 * ) F_40 ( V_230 ,
V_191 , V_192 , V_228 ,
V_3 ) ;
V_3 -> V_627 = V_631 -> V_627 ;
V_3 -> V_628 = V_631 -> V_628 ;
V_3 -> V_512 = V_631 -> V_512 ;
V_3 -> V_513 = V_631 -> V_513 ;
V_3 -> V_368 = V_631 -> V_634 ;
V_3 -> V_370 = V_631 -> V_635 ;
V_3 -> V_633 = V_631 -> V_633 ;
V_3 -> V_632 = V_631 -> V_636 ;
if ( V_3 -> V_48 & V_244 ) {
if ( V_231 == 0x08 )
V_3 -> V_632 = 0x40 ;
else if ( V_231 == 0x09 )
V_3 -> V_632 = 0x40 ;
else if ( V_231 == 0x12 )
V_3 -> V_632 = 0x40 ;
if ( V_3 -> V_369 == 350 )
V_3 -> V_49 |= V_250 ;
V_229 = V_637 ;
V_230 = V_638 ;
if ( V_3 -> V_48 & V_208 ) {
if ( V_3 -> V_49 & V_250 ) {
V_229 = V_639 ;
V_230 = V_640 ;
if ( ! ( V_200 & V_219 ) ) {
V_229 = V_641 ;
V_230 = V_642 ;
}
}
}
} else if ( V_3 -> V_48 & V_254 ) {
if ( V_3 -> V_49 & V_556 ) {
V_229 = V_643 ;
V_230 = V_644 ;
}
if ( V_3 -> V_49 & V_557 ) {
V_229 = V_645 ;
V_230 = V_646 ;
} else if ( V_3 -> V_49 & V_602 ) {
V_229 = V_647 ;
V_230 = V_648 ;
if ( V_3 -> V_49 & V_559 )
V_229 = V_649 ;
}
} else {
V_229 = V_650 ;
V_230 = V_651 ;
if ( ! ( V_3 -> V_49 & V_259 ) ) {
V_229 = V_652 ;
V_230 = V_653 ;
if ( V_3 -> V_49 & V_559 )
V_229 = V_649 ;
}
}
V_3 -> V_514 = V_229 ;
V_3 -> V_516 = V_230 ;
return;
}
}
static void F_73 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned char V_548 , V_549 , V_373 ;
V_373 = F_48 ( V_228 , V_191 , V_192 ,
V_3 ) ;
F_49 ( V_373 , & V_548 , & V_549 , V_3 ) ;
F_47 ( & V_548 , & V_549 , V_3 ) ;
if ( V_3 -> V_147 & V_560 ) {
F_4 ( V_3 -> V_547 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_547 , 0x0B , V_549 ) ;
F_4 ( V_3 -> V_547 , 0x0A , V_548 ) ;
} else {
F_4 ( V_3 -> V_547 , 0x0A , V_548 ) ;
F_4 ( V_3 -> V_547 , 0x0B , V_549 ) ;
}
F_4 ( V_3 -> V_547 , 0x00 , 0x12 ) ;
if ( V_3 -> V_48 & V_236 )
F_22 ( V_3 -> V_547 , 0x12 , 0x28 ) ;
else
F_22 ( V_3 -> V_547 , 0x12 , 0x08 ) ;
}
static unsigned short F_74 ( unsigned short V_191 ,
unsigned short V_192 , struct V_2 * V_3 )
{
unsigned short V_654 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_193 ;
unsigned short V_200 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_193 = ( V_200 & V_579 ) - V_306 ;
if ( V_193 < 0 )
V_193 = 0 ;
return V_654 [ V_193 ] ;
}
static unsigned short F_75 ( unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_265 , V_655 , V_656 , V_193 , V_232 ,
V_654 [] = { 0x01 , 0x02 , 0x04 } ;
V_656 = V_3 -> V_10 [ V_192 ] . V_305 ;
if ( V_191 <= 0x14 )
V_232 = 0 ;
else
V_232 = V_3 ->
V_13 [ V_228 ] . V_263 ;
V_193 = ( V_656 >> 8 ) & 0xFF ;
V_265 = V_3 -> V_31 [ V_193 ] ;
if ( V_232 & V_299 )
V_265 = V_265 << 1 ;
V_655 = F_74 ( V_191 , V_192 , V_3 ) ;
if ( ( V_191 >= 0x7C ) && ( V_191 <= 0x7E ) ) {
V_265 = V_191 - 0x7C ;
V_655 = V_654 [ V_265 ] ;
V_265 = 0x6B ;
if ( V_232 & V_299 )
V_265 = V_265 << 1 ;
return V_265 * V_655 ;
} else {
return V_265 * V_655 ;
}
}
static void F_76 ( unsigned short V_191 ,
unsigned short V_192 ,
unsigned short V_228 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_657 ;
unsigned char V_265 ;
if ( V_3 -> V_48 & V_208 )
return;
V_657 = F_75 ( V_191 , V_192 , V_228 ,
V_213 , V_3 ) ;
V_265 = ( unsigned char ) ( V_657 & 0xFF ) ;
F_4 ( V_3 -> V_540 , 0x07 , V_265 ) ;
V_265 = ( unsigned char ) ( ( V_657 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_540 , 0x09 , V_265 ) ;
V_265 = ( unsigned char ) ( ( ( V_657 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_540 , 0x03 , V_265 ) ;
}
static void F_77 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_540 , 0x01 , 0x3B ) ;
F_14 ( V_3 -> V_540 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_78 ( unsigned short V_191 , unsigned short V_192 ,
struct V_212 * V_213 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_295 = 0 , V_626 = 0 , V_231 = 0 ;
if ( V_191 > 0x13 ) {
V_626 = V_3 ->
V_13 [ V_228 ] . V_272 ;
V_626 &= V_273 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
}
F_76 ( V_191 , V_192 , V_228 ,
V_213 , V_3 ) ;
F_77 ( V_3 ) ;
for ( V_295 = 4 ; V_295 < 7 ; V_295 ++ )
F_4 ( V_3 -> V_540 , V_295 , 0x0 ) ;
F_4 ( V_3 -> V_540 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_540 , 0x02 , 0x44 ) ;
}
static void F_79 ( unsigned short V_191 , unsigned short V_192 ,
struct V_212 * V_213 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_265 = 0 , V_229 = 0 , V_230 = 0 , V_295 = 0 ,
V_658 = 0 , V_626 = 0 , V_200 , V_231 = 0 ;
if ( V_191 > 0x13 ) {
V_626 = V_3 ->
V_13 [ V_228 ] . V_272 ;
V_626 &= V_273 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
}
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
if ( V_200 & V_298 ) {
V_265 = ( V_3 -> V_512 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_540 , 0x08 , V_265 ) ;
V_265 = ( ( ( V_3 -> V_512 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_14 ( V_3 -> V_540 , 0x09 , ~ 0x0F0 , V_265 ) ;
V_265 = ( V_3 -> V_367 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_540 , 0x0A , V_265 ) ;
V_295 = ( ( V_3 -> V_512 - V_3 -> V_367 ) / 2 ) >> 2 ;
V_658 = V_3 -> V_367 / 2 + 16 ;
V_295 = V_295 >> 1 ;
V_230 = V_658 + V_295 ;
V_295 += V_230 ;
if ( V_3 -> V_48 & V_236 ) {
V_230 = V_3 -> V_16 [ V_626 ] . V_274 [ 4 ] ;
V_230 |= ( ( V_3 ->
V_16 [ V_626 ] . V_274 [ 14 ] &
0xC0 ) << 2 ) ;
V_230 = ( V_230 - 3 ) << 3 ;
V_295 = V_3 -> V_16 [ V_626 ] . V_274 [ 5 ] ;
V_295 &= 0x1F ;
V_265 = V_3 -> V_16 [ V_626 ] . V_274 [ 15 ] ;
V_265 = ( V_265 & 0x04 ) << ( 5 - 2 ) ;
V_295 = ( ( V_295 | V_265 ) - 3 ) << 3 ;
}
V_230 += 4 ;
V_295 += 4 ;
if ( V_295 > ( V_3 -> V_512 / 2 ) )
V_295 = V_3 -> V_512 / 2 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0B , V_265 ) ;
} else {
V_265 = ( V_3 -> V_512 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_540 , 0x08 , V_265 ) ;
V_265 = ( ( ( V_3 -> V_512 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_14 ( V_3 -> V_540 , 0x09 , ~ 0x0F0 , V_265 ) ;
V_265 = ( V_3 -> V_367 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_540 , 0x0A , V_265 ) ;
V_295 = ( V_3 -> V_512 - V_3 -> V_367 ) >> 2 ;
V_658 = V_3 -> V_367 + 16 ;
V_295 = V_295 >> 1 ;
V_230 = V_658 + V_295 ;
V_295 += V_230 ;
if ( V_3 -> V_48 & V_236 ) {
V_230 = V_3 -> V_16 [ V_626 ] . V_274 [ 3 ] ;
V_230 |= ( ( V_3 ->
V_16 [ V_626 ] . V_274 [ 5 ] &
0xC0 ) << 2 ) ;
V_230 = ( V_230 - 3 ) << 3 ;
V_295 = V_3 -> V_16 [ V_626 ] . V_274 [ 4 ] ;
V_295 &= 0x1F ;
V_265 = V_3 -> V_16 [ V_626 ] . V_274 [ 6 ] ;
V_265 = ( V_265 & 0x04 ) << ( 5 - 2 ) ;
V_295 = ( ( V_295 | V_265 ) - 3 ) << 3 ;
V_230 += 16 ;
V_295 += 16 ;
}
if ( V_295 > V_3 -> V_512 )
V_295 = V_3 -> V_512 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0B , V_265 ) ;
}
V_229 = ( V_229 & 0x00FF ) | ( V_230 & 0xFF00 ) ;
V_230 = V_658 ;
V_230 = ( V_230 & 0x00FF ) | ( ( V_230 & 0xFF00 ) << 4 ) ;
V_229 |= ( V_230 & 0xFF00 ) ;
V_265 = ( V_229 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_540 , 0x0C , V_265 ) ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0D , V_265 ) ;
V_295 = ( V_3 -> V_513 - 1 ) ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0E , V_265 ) ;
V_230 = V_3 -> V_369 - 1 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0F , V_265 ) ;
V_265 = ( ( V_230 & 0xFF00 ) << 3 ) >> 8 ;
V_265 |= ( ( V_295 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_540 , 0x12 , V_265 ) ;
V_229 = V_3 -> V_369 ;
V_230 = V_3 -> V_369 ;
V_295 = V_3 -> V_513 ;
V_230 = ( V_3 -> V_513 + V_3 -> V_369 ) >> 1 ;
V_295 = ( ( V_3 -> V_513 - V_3 -> V_369 ) >> 4 ) + V_230 + 1 ;
if ( V_3 -> V_48 & V_236 ) {
V_230 = V_3 -> V_16 [ V_626 ] . V_274 [ 10 ] ;
V_265 = V_3 -> V_16 [ V_626 ] . V_274 [ 9 ] ;
if ( V_265 & 0x04 )
V_230 |= 0x0100 ;
if ( V_265 & 0x080 )
V_230 |= 0x0200 ;
V_265 = V_3 -> V_16 [ V_626 ] . V_274 [ 14 ] ;
if ( V_265 & 0x08 )
V_230 |= 0x0400 ;
V_265 = V_3 -> V_16 [ V_626 ] . V_274 [ 11 ] ;
V_295 = ( V_295 & 0xFF00 ) | ( V_265 & 0x00FF ) ;
}
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x10 , V_265 ) ;
V_265 = ( ( V_230 & 0xFF00 ) >> 8 ) << 4 ;
V_265 = ( ( V_295 & 0x000F ) | ( V_265 ) ) ;
F_4 ( V_3 -> V_540 , 0x11 , V_265 ) ;
V_229 = 0 ;
if ( V_200 & V_271 )
V_229 |= 0x80 ;
if ( V_200 & V_298 )
V_229 |= 0x40 ;
F_14 ( V_3 -> V_540 , 0x2C , ~ 0x0C0 , V_229 ) ;
}
static unsigned short F_80 ( struct V_2 * V_3 )
{
unsigned long V_229 , V_230 ;
V_230 = ( ( V_3 -> V_513 - V_3 -> V_369 ) * V_3 -> V_627 )
& 0xFFFF ;
V_229 = ( V_3 -> V_516 - V_3 -> V_370 ) * V_3 -> V_628 ;
V_229 = ( V_229 * V_3 -> V_514 ) / V_230 ;
return ( unsigned short ) V_229 ;
}
static void F_81 ( unsigned short V_191 , unsigned short V_192 ,
struct V_212 * V_213 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_532 , V_533 , V_229 , V_230 = 0 , V_295 , V_265 , V_231 ,
V_200 , V_626 ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_231 = V_3 -> V_4 [ V_192 ] . V_300 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
V_626 = V_3 ->
V_13 [ V_228 ] . V_272 ;
V_626 &= V_273 ;
}
if ( ! ( V_3 -> V_48 & V_208 ) )
return;
V_265 = 0xFF ;
F_4 ( V_3 -> V_540 , 0x03 , V_265 ) ;
V_295 = 0x08 ;
if ( V_3 -> V_147 & ( V_148 | V_149 | V_238 ) )
V_200 |= V_219 ;
V_229 = V_3 -> V_367 ;
if ( V_200 & V_298 )
V_229 = V_229 >> 1 ;
V_229 = ( V_229 / V_295 ) - 1 ;
V_230 |= ( ( V_229 & 0x00FF ) << 8 ) ;
V_265 = V_229 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x04 , V_265 ) ;
V_265 = ( V_230 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_48 & V_206 ) {
if ( ! ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) )
V_265 += 2 ;
if ( V_3 -> V_48 & V_244 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_245 == V_246 ) {
if ( V_231 == 7 )
V_265 -= 2 ;
}
} else if ( V_231 == 7 ) {
V_265 -= 2 ;
}
}
}
F_4 ( V_3 -> V_540 , 0x05 , V_265 ) ;
F_4 ( V_3 -> V_540 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_48 & V_581 ) ) {
if ( V_3 -> V_48 & V_206 )
V_229 = V_3 -> V_512 ;
else
V_229 = F_80 ( V_3 ) ;
}
if ( V_229 >= V_3 -> V_512 )
V_229 = V_3 -> V_512 ;
if ( V_200 & V_298 )
V_229 = V_229 >> 1 ;
V_229 = ( V_229 / V_295 ) - 5 ;
V_295 = V_229 ;
if ( V_3 -> V_48 & V_244 ) {
V_265 = ( V_230 & 0x00FF ) - 1 ;
if ( ! ( V_200 & V_298 ) ) {
V_265 -= 6 ;
if ( V_3 -> V_49 & V_250 ) {
V_265 -= 4 ;
if ( V_191 > 0x13 )
V_265 -= 10 ;
}
}
} else {
V_230 = ( V_230 & 0xFF00 ) >> 8 ;
V_295 = ( V_295 + V_230 ) >> 1 ;
V_265 = ( V_295 & 0x00FF ) + 2 ;
if ( V_3 -> V_48 & V_206 ) {
V_265 -= 1 ;
if ( ! ( V_200 & V_298 ) ) {
if ( ( V_200 & V_219 ) ) {
V_265 += 4 ;
if ( V_3 -> V_367 >= 800 )
V_265 -= 6 ;
}
}
} else {
if ( ! ( V_200 & V_298 ) ) {
V_265 -= 4 ;
if ( V_3 -> V_45 != V_242 ) {
if ( V_3 -> V_367 >= 800 ) {
V_265 -= 7 ;
if ( V_3 -> V_195 ==
V_306 ) {
if ( V_3 -> V_369 ==
1024 ) {
V_265 += 15 ;
if ( V_3 -> V_45 != V_241 ) {
V_265 +=
7 ;
}
}
}
if ( V_3 -> V_367 >= 1280 ) {
if ( V_3 -> V_45
!= V_242 ) {
if ( V_3 -> V_47
& V_243 ) {
V_265
+= 28 ;
}
}
}
}
}
}
}
}
F_4 ( V_3 -> V_540 , 0x07 , V_265 ) ;
F_4 ( V_3 -> V_540 , 0x08 , 0 ) ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_49 & V_250 ) {
if ( ( V_191 == 0x06 ) || ( V_191 == 0x10 ) || ( V_191
== 0x11 ) || ( V_191 == 0x13 ) || ( V_191
== 0x0F ) ) {
F_4 ( V_3 -> V_540 , 0x07 , 0x5b ) ;
F_4 ( V_3 -> V_540 , 0x08 , 0x03 ) ;
}
if ( ( V_191 == 0x00 ) || ( V_191 == 0x01 ) ) {
if ( V_3 -> V_49 & V_659 ) {
F_4 ( V_3 -> V_540 ,
0x07 , 0x2A ) ;
F_4 ( V_3 -> V_540 ,
0x08 , 0x61 ) ;
} else {
F_4 ( V_3 -> V_540 ,
0x07 , 0x2A ) ;
F_4 ( V_3 -> V_540 ,
0x08 , 0x41 ) ;
F_4 ( V_3 -> V_540 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_191 == 0x02 ) || ( V_191 == 0x03 ) || ( V_191
== 0x07 ) ) {
if ( V_3 -> V_49 & V_659 ) {
F_4 ( V_3 -> V_540 ,
0x07 , 0x54 ) ;
F_4 ( V_3 -> V_540 ,
0x08 , 0x00 ) ;
} else {
F_4 ( V_3 -> V_540 ,
0x07 , 0x55 ) ;
F_4 ( V_3 -> V_540 ,
0x08 , 0x00 ) ;
F_4 ( V_3 -> V_540 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_191 == 0x04 ) || ( V_191 == 0x05 ) || ( V_191
== 0x0D ) || ( V_191 == 0x50 ) ) {
if ( V_3 -> V_49 & V_659 ) {
F_4 ( V_3 -> V_540 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_540 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_540 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_540 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_540 , 0x18 , 0x03 ) ;
F_14 ( V_3 -> V_540 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_540 , 0x09 , 0xFF ) ;
V_230 = V_3 -> V_513 ;
V_532 = V_230 ;
V_295 = 0x121 ;
V_230 = V_3 -> V_369 ;
if ( V_230 == 357 )
V_230 = 350 ;
if ( V_230 == 360 )
V_230 = 350 ;
if ( V_230 == 375 )
V_230 = 350 ;
if ( V_230 == 405 )
V_230 = 400 ;
if ( V_230 == 525 )
V_230 = 480 ;
V_533 = V_230 ;
if ( V_3 -> V_48 & V_207 ) {
if ( V_3 -> V_45 == V_262 ) {
if ( ! ( V_3 -> V_47 & V_615 ) ) {
if ( V_230 == 350 )
V_230 += 5 ;
if ( V_230 == 480 )
V_230 += 5 ;
}
}
}
V_230 -- ;
V_265 = V_230 & 0x00FF ;
V_230 -- ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x10 , V_265 ) ;
V_230 = V_533 ;
V_230 -- ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0E , V_265 ) ;
if ( V_230 & 0x0100 )
V_295 |= 0x0002 ;
V_229 = 0x000B ;
if ( V_200 & V_271 )
V_229 |= 0x08000 ;
if ( V_230 & 0x0200 )
V_295 |= 0x0040 ;
V_265 = ( V_229 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_540 , 0x0B , V_265 ) ;
if ( V_230 & 0x0400 )
V_295 |= 0x0600 ;
F_4 ( V_3 -> V_540 , 0x11 , 0x00 ) ;
V_229 = V_532 ;
V_229 -= V_230 ;
V_229 = V_229 >> 2 ;
V_532 = V_229 ;
if ( V_231 != 0x09 ) {
V_229 = V_229 << 1 ;
V_230 += V_229 ;
}
if ( V_3 -> V_48 & V_244 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_605 ) {
V_230 -= 10 ;
} else {
if ( V_3 -> V_49 & V_250 ) {
if ( V_3 -> V_49 & V_259 ) {
if ( V_3 -> V_147 &
V_148 ) {
if ( ! ( V_3 -> V_49 &
( V_557 |
V_556 |
V_605 ) ) )
V_230 += 40 ;
} else {
V_230 += 40 ;
}
}
}
}
} else {
V_230 -= 10 ;
}
} else {
if ( V_3 -> V_49 & V_250 ) {
if ( V_3 -> V_49 & V_259 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( ! ( V_3 -> V_49 &
( V_557 |
V_556 |
V_605 ) ) )
V_230 += 40 ;
} else {
V_230 += 40 ;
}
}
}
}
V_229 = V_532 ;
V_229 = V_229 >> 2 ;
V_229 ++ ;
V_229 += V_230 ;
V_532 = V_229 ;
if ( ( V_3 -> V_49 & V_259 ) ) {
if ( V_230 <= 513 ) {
if ( V_229 >= 513 )
V_230 = 513 ;
}
}
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0C , V_265 ) ;
V_230 -- ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x10 , V_265 ) ;
if ( V_230 & 0x0100 )
V_295 |= 0x0008 ;
if ( V_230 & 0x0200 )
F_14 ( V_3 -> V_540 , 0x0B , 0x0FF , 0x20 ) ;
V_230 ++ ;
if ( V_230 & 0x0100 )
V_295 |= 0x0004 ;
if ( V_230 & 0x0200 )
V_295 |= 0x0080 ;
if ( V_230 & 0x0400 )
V_295 |= 0x0C00 ;
V_230 = V_532 ;
V_265 = V_230 & 0x00FF ;
V_265 &= 0x0F ;
F_4 ( V_3 -> V_540 , 0x0D , V_265 ) ;
if ( V_230 & 0x0010 )
V_295 |= 0x2000 ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_540 , 0x0A , V_265 ) ;
V_265 = ( V_295 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_540 , 0x17 , V_265 ) ;
V_229 = V_200 ;
V_265 = ( V_229 & 0xFF00 ) >> 8 ;
V_265 = ( V_265 >> 1 ) & 0x09 ;
if ( V_3 -> V_147 & ( V_148 | V_149 | V_238 ) )
V_265 |= 0x01 ;
F_4 ( V_3 -> V_540 , 0x16 , V_265 ) ;
F_4 ( V_3 -> V_540 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_540 , 0x12 , 0 ) ;
if ( V_3 -> V_47 & V_660 )
V_265 = 0x80 ;
else
V_265 = 0x00 ;
F_4 ( V_3 -> V_540 , 0x1A , V_265 ) ;
return;
}
static void F_82 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_199 , V_269 , V_229 , V_230 , V_295 , V_265 , V_532 , V_533 ,
V_200 , V_231 , V_661 ;
unsigned char * V_662 ;
unsigned long V_663 , V_664 , V_665 , V_303 , V_666 ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_231 = V_3 -> V_4 [ V_192 ] . V_300 ;
V_661 = V_3 -> V_4 [ V_192 ] . V_317 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
V_661 = V_3 -> V_13 [ V_228 ] .
V_318 ;
}
V_229 = 0 ;
if ( ! ( V_3 -> V_48 & V_251 ) )
V_229 |= 0x0800 ;
if ( ! ( V_3 -> V_48 & V_252 ) )
V_229 |= 0x0400 ;
if ( V_3 -> V_48 & V_253 )
V_229 |= 0x0200 ;
if ( ! ( V_3 -> V_49 & V_259 ) )
V_229 |= 0x1000 ;
if ( V_3 -> V_48 & V_244 )
V_229 |= 0x0100 ;
if ( V_3 -> V_49 & ( V_557 | V_556 ) )
V_229 &= 0xfe00 ;
V_229 = ( V_229 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_566 , 0x0 , V_229 ) ;
V_662 = V_3 -> V_110 ;
if ( V_3 -> V_49 & V_259 )
V_662 = V_3 -> V_112 ;
if ( V_3 -> V_48 & V_244 ) {
V_662 = V_3 -> V_114 ;
if ( V_3 -> V_48 & V_208 )
V_662 = V_3 -> V_118 ;
if ( V_3 -> V_249 & V_250 )
V_662 = V_3 -> V_116 ;
if ( ! ( V_200 & V_219 ) )
V_662 = V_3 -> V_120 ;
}
if ( V_3 -> V_48 & V_254 ) {
if ( V_3 -> V_49 & V_602 )
V_662 = V_3 -> V_126 ;
if ( V_3 -> V_49 & V_557 )
V_662 = V_3 -> V_124 ;
if ( V_3 -> V_49 & V_556 )
V_662 = V_3 -> V_122 ;
}
for ( V_199 = 0x01 , V_269 = 0 ; V_199 <= 0x2D ; V_199 ++ , V_269 ++ )
F_4 ( V_3 -> V_566 , V_199 , V_662 [ V_269 ] ) ;
for ( V_199 = 0x39 ; V_199 <= 0x45 ; V_199 ++ , V_269 ++ )
F_4 ( V_3 -> V_566 , V_199 , V_662 [ V_269 ] ) ;
if ( V_3 -> V_48 & V_206 )
F_14 ( V_3 -> V_566 , 0x3A , 0x1F , 0x00 ) ;
V_265 = V_3 -> V_632 ;
V_265 &= 0x80 ;
F_14 ( V_3 -> V_566 , 0x0A , 0xFF , V_265 ) ;
if ( V_3 -> V_48 & V_244 )
V_229 = 950 ;
if ( V_3 -> V_49 & V_259 )
V_229 = 520 ;
else
V_229 = 440 ;
if ( V_3 -> V_370 <= V_229 ) {
V_229 -= V_3 -> V_370 ;
V_229 = V_229 >> 2 ;
V_229 = ( V_229 & 0x00FF ) | ( ( V_229 & 0x00FF ) << 8 ) ;
V_532 = V_229 ;
V_265 = ( V_229 & 0xFF00 ) >> 8 ;
V_265 += ( unsigned short ) V_662 [ 0 ] ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
if ( V_3 -> V_48 & ( V_251
| V_252 | V_253
| V_254 ) ) {
V_295 = V_3 -> V_367 ;
if ( V_295 >= 1024 ) {
V_265 = 0x17 ;
if ( V_3 -> V_49 & V_259 )
V_265 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_566 , 0x01 , V_265 ) ;
V_229 = V_532 ;
V_265 = ( V_229 & 0xFF00 ) >> 8 ;
V_265 += V_662 [ 1 ] ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
if ( ( V_3 -> V_48 & ( V_251
| V_252 | V_253
| V_254 ) ) ) {
V_295 = V_3 -> V_367 ;
if ( V_295 >= 1024 ) {
V_265 = 0x1D ;
if ( V_3 -> V_49 & V_259 )
V_265 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_566 , 0x02 , V_265 ) ;
}
V_295 = V_3 -> V_514 ;
if ( F_70 ( V_3 ) )
V_295 = V_295 >> 1 ;
V_295 -= 2 ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x1B , V_265 ) ;
V_265 = ( V_295 & 0xFF00 ) >> 8 ;
F_14 ( V_3 -> V_566 , 0x1D , ~ 0x0F , V_265 ) ;
V_295 = V_3 -> V_514 >> 1 ;
V_532 = V_295 ;
V_295 += 7 ;
if ( V_3 -> V_48 & V_244 )
V_295 -= 4 ;
V_265 = V_295 & 0x00FF ;
V_265 = V_265 << 4 ;
F_14 ( V_3 -> V_566 , 0x22 , 0x0F , V_265 ) ;
V_230 = V_662 [ V_269 ] | ( ( V_662 [ V_269 + 1 ] ) << 8 ) ;
V_230 += V_295 ;
V_533 = V_230 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x24 , V_265 ) ;
V_265 = ( V_230 & 0xFF00 ) >> 8 ;
V_265 = V_265 << 4 ;
F_14 ( V_3 -> V_566 , 0x25 , 0x0F , V_265 ) ;
V_230 = V_533 ;
V_230 = V_230 + 8 ;
if ( V_3 -> V_48 & V_244 ) {
V_230 = V_230 - 4 ;
V_295 = V_230 ;
}
V_265 = ( V_230 & 0x00FF ) << 4 ;
F_14 ( V_3 -> V_566 , 0x29 , 0x0F , V_265 ) ;
V_269 += 2 ;
V_295 += ( V_662 [ V_269 ] | ( ( V_662 [ V_269 + 1 ] ) << 8 ) ) ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x27 , V_265 ) ;
V_265 = ( ( V_295 & 0xFF00 ) >> 8 ) << 4 ;
F_14 ( V_3 -> V_566 , 0x28 , 0x0F , V_265 ) ;
V_295 += 8 ;
if ( V_3 -> V_48 & V_244 )
V_295 -= 4 ;
V_265 = V_295 & 0xFF ;
V_265 = V_265 << 4 ;
F_14 ( V_3 -> V_566 , 0x2A , 0x0F , V_265 ) ;
V_295 = V_532 ;
V_269 += 2 ;
V_265 = V_662 [ V_269 ] | ( ( V_662 [ V_269 + 1 ] ) << 8 ) ;
V_295 -= V_265 ;
V_265 = V_295 & 0x00FF ;
V_265 = V_265 << 4 ;
F_14 ( V_3 -> V_566 , 0x2D , 0x0F , V_265 ) ;
V_295 -= 11 ;
if ( ! ( V_3 -> V_48 & V_206 ) ) {
V_229 = F_80 ( V_3 ) ;
V_295 = V_229 - 1 ;
}
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x2E , V_265 ) ;
V_230 = V_3 -> V_370 ;
if ( V_3 -> V_369 == 360 )
V_230 = 746 ;
if ( V_3 -> V_369 == 375 )
V_230 = 746 ;
if ( V_3 -> V_369 == 405 )
V_230 = 853 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_147 &
( V_148 | V_149 | V_238 ) ) {
if ( ! ( V_3 -> V_49 &
( V_557 | V_556 ) ) )
V_230 = V_230 >> 1 ;
} else
V_230 = V_230 >> 1 ;
}
V_230 -= 2 ;
V_265 = V_230 & 0x00FF ;
if ( V_3 -> V_48 & V_244 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_605 ) {
if ( V_3 -> V_48 & V_208 ) {
if ( V_191 == 0x2f )
V_265 += 1 ;
}
}
} else {
if ( V_3 -> V_48 & V_208 ) {
if ( V_191 == 0x2f )
V_265 += 1 ;
}
}
}
F_4 ( V_3 -> V_566 , 0x2F , V_265 ) ;
V_265 = ( V_295 & 0xFF00 ) >> 8 ;
V_265 |= ( ( V_230 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_48 & V_244 ) ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_605 ) {
V_265 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_252 ) )
V_265 |= 0x20 ;
}
} else {
V_265 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_252 ) )
V_265 |= 0x20 ;
}
}
F_4 ( V_3 -> V_566 , 0x30 , V_265 ) ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
V_230 = V_3 -> V_370 ;
V_295 = V_230 - 2 ;
if ( V_3 -> V_48 & V_206 ) {
if ( ! ( V_3 -> V_49 & ( V_557
| V_556 ) ) )
V_230 = V_230 >> 1 ;
}
if ( V_3 -> V_147 & ( V_149 | V_238 ) ) {
V_265 = 0 ;
if ( V_295 & 0x0400 )
V_265 |= 0x20 ;
if ( V_230 & 0x0400 )
V_265 |= 0x40 ;
F_4 ( V_3 -> V_547 , 0x10 , V_265 ) ;
}
V_265 = ( ( ( V_230 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_566 , 0x46 , V_265 ) ;
V_265 = ( V_230 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x47 , V_265 ) ;
}
V_230 = V_230 & 0x00FF ;
if ( ! ( V_200 & V_298 ) ) {
V_295 = V_3 -> V_367 ;
if ( V_295 >= V_3 -> V_368 ) {
V_230 |= 0x2000 ;
V_229 &= 0x00FF ;
}
}
V_295 = 0x0101 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_367 >= 1024 ) {
V_295 = 0x1920 ;
if ( V_3 -> V_367 >= 1280 ) {
V_295 = 0x1420 ;
V_230 = V_230 & 0xDFFF ;
}
}
}
if ( ! ( V_230 & 0x2000 ) ) {
if ( V_200 & V_298 )
V_295 = ( V_295 & 0xFF00 ) | ( ( V_295 & 0x00FF ) << 1 ) ;
V_532 = V_230 ;
V_664 = V_3 -> V_367 ;
V_665 = ( V_295 & 0xFF00 ) >> 8 ;
V_663 = V_664 * V_665 ;
V_666 = V_295 & 0x00FF ;
V_663 = V_663 / V_666 ;
V_666 = 8 * 1024 ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
V_666 = V_666 * 8 ;
}
V_663 = V_663 * V_666 ;
V_666 = V_3 -> V_368 ;
V_303 = V_663 % V_666 ;
V_664 = V_663 / V_666 ;
if ( V_303 != 0 )
V_664 += 1 ;
V_229 = ( unsigned short ) V_664 ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
V_295 = ( ( V_229 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_230 = V_532 ;
V_230 = ( unsigned short ) ( ( ( V_664 & 0x0000FF00 ) & 0x1F00 )
| ( V_230 & 0x00FF ) ) ;
V_229 = ( unsigned short ) ( ( ( V_664 & 0x000000FF ) << 8 )
| ( V_229 & 0x00FF ) ) ;
V_265 = ( V_229 & 0xFF00 ) >> 8 ;
} else {
V_265 = ( V_229 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_566 , 0x44 , V_265 ) ;
V_265 = ( V_230 & 0xFF00 ) >> 8 ;
F_14 ( V_3 -> V_566 , 0x45 , ~ 0x03F , V_265 ) ;
V_265 = V_295 & 0x00FF ;
if ( V_230 & 0x2000 )
V_265 = 0 ;
if ( ! ( V_3 -> V_48 & V_207 ) )
V_265 |= 0x18 ;
F_14 ( V_3 -> V_566 , 0x46 , ~ 0x1F , V_265 ) ;
if ( V_3 -> V_49 & V_259 ) {
V_230 = 0x0382 ;
V_295 = 0x007e ;
} else {
V_230 = 0x0369 ;
V_295 = 0x0061 ;
}
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x4b , V_265 ) ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x4c , V_265 ) ;
V_265 = ( ( V_295 & 0xFF00 ) >> 8 ) & 0x03 ;
V_265 = V_265 << 2 ;
V_265 |= ( ( V_230 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_48 & V_254 ) {
V_265 |= 0x10 ;
if ( V_3 -> V_49 & V_557 )
V_265 |= 0x20 ;
if ( V_3 -> V_49 & V_556 )
V_265 |= 0x60 ;
}
F_4 ( V_3 -> V_566 , 0x4d , V_265 ) ;
V_265 = F_8 ( V_3 -> V_566 , 0x43 ) ;
F_4 ( V_3 -> V_566 , 0x43 , ( unsigned short ) ( V_265 - 3 ) ) ;
if ( ! ( V_3 -> V_49 & ( V_557 | V_556 ) ) ) {
if ( V_3 -> V_49 & V_559 ) {
V_662 = V_667 ;
for ( V_199 = 0x1c , V_269 = 0 ; V_199 <= 0x30 ; V_199 ++ , V_269 ++ ) {
F_4 ( V_3 -> V_566 , V_199 ,
V_662 [ V_269 ] ) ;
}
F_4 ( V_3 -> V_566 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_147 & V_238 ) {
if ( V_3 -> V_49 & V_598 )
F_14 ( V_3 -> V_566 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_49 & V_598 ) {
V_229 = ( unsigned char ) F_8 ( V_3 -> V_566 ,
0x01 ) ;
V_229 -- ;
F_15 ( V_3 -> V_566 , 0x01 , V_229 ) ;
F_15 ( V_3 -> V_566 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_48 & V_244 ) {
if ( ! ( V_3 -> V_48 & V_208 ) )
F_4 ( V_3 -> V_566 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_48 & V_206 )
return;
}
static void F_83 ( unsigned short V_191 , unsigned short V_192 ,
struct V_212 * V_213 ,
unsigned short V_228 ,
struct V_2 * V_3 )
{
unsigned short V_532 , V_533 , V_658 , V_229 , V_230 , V_295 , V_265 ,
V_197 , V_668 , V_562 , V_231 , V_200 , V_626 ;
struct V_669 * V_670 = NULL ;
if ( V_191 <= 0x13 ) {
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
V_231 = V_3 -> V_4 [ V_192 ] . V_300 ;
} else {
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_231 = V_3 -> V_10 [ V_192 ] . V_233 ;
V_626 = V_3 -> V_13 [ V_228 ] .
V_272 ;
V_626 &= V_273 ;
}
if ( ! ( V_3 -> V_48 & V_207 ) )
return;
V_230 = V_3 -> V_368 ;
if ( F_70 ( V_3 ) )
V_230 = V_230 >> 1 ;
V_230 -= 1 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x2C , V_265 ) ;
V_265 = ( V_230 & 0xFF00 ) >> 8 ;
V_265 = V_265 << 4 ;
F_14 ( V_3 -> V_566 , 0x2B , 0x0F , V_265 ) ;
V_265 = 0x01 ;
if ( V_3 -> V_45 == V_241 ) {
if ( V_3 -> V_195 == V_306 ) {
if ( V_3 -> V_367 >= 1024 ) {
V_265 = 0x02 ;
if ( V_3 -> V_47 & V_615 )
V_265 = 0x01 ;
}
}
}
F_4 ( V_3 -> V_566 , 0x0B , V_265 ) ;
V_230 = V_3 -> V_370 ;
V_532 = V_230 ;
V_230 -- ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x03 , V_265 ) ;
V_265 = ( ( V_230 & 0xFF00 ) >> 8 ) & 0x07 ;
F_14 ( V_3 -> V_566 , 0x0C , ~ 0x07 , V_265 ) ;
V_295 = V_3 -> V_516 - 1 ;
V_533 = V_295 + 1 ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x19 , V_265 ) ;
V_265 = ( V_295 & 0xFF00 ) >> 8 ;
V_265 = V_265 << 5 ;
F_4 ( V_3 -> V_566 , 0x1A , V_265 ) ;
F_14 ( V_3 -> V_566 , 0x09 , 0xF0 , 0x00 ) ;
F_14 ( V_3 -> V_566 , 0x0A , 0xF0 , 0x00 ) ;
F_14 ( V_3 -> V_566 , 0x17 , 0xFB , 0x00 ) ;
F_14 ( V_3 -> V_566 , 0x18 , 0xDF , 0x00 ) ;
V_230 = 5 ;
V_670 = (struct V_669 * ) F_39 ( V_230 , V_191 ,
V_192 , V_228 , V_3 ) ;
V_197 = V_3 -> V_45 ;
V_197 &= V_389 ;
if ( ( V_197 == V_262 ) || ( V_197 == V_336 ) ) {
V_230 = 1024 ;
V_295 = 768 ;
} else if ( ( V_197 == V_241 ) ||
( V_197 == V_519 ) ) {
V_230 = 1280 ;
V_295 = 1024 ;
} else if ( V_197 == V_520 ) {
V_230 = 1400 ;
V_295 = 1050 ;
} else {
V_230 = 1600 ;
V_295 = 1200 ;
}
if ( V_3 -> V_47 & V_379 ) {
V_230 = V_3 -> V_368 ;
V_295 = V_3 -> V_370 ;
}
V_658 = V_230 ;
V_229 = V_3 -> V_516 ;
V_3 -> V_539 = V_670 -> V_539 ;
V_3 -> V_541 = V_670 -> V_541 ;
V_3 -> V_543 = V_670 -> V_543 ;
V_3 -> V_544 = V_670 -> V_544 ;
V_230 = V_3 -> V_543 ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x05 , V_265 ) ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x06 , V_265 ) ;
V_562 = ( ( V_295 & 0xFF00 ) >> 8 ) & 0x07 ;
V_668 = ( ( V_230 & 0xFF00 ) >> 8 ) & 0x07 ;
V_197 = V_562 ;
V_197 = V_197 << 3 ;
V_197 |= V_668 ;
F_4 ( V_3 -> V_566 , 0x02 , V_197 ) ;
F_45 ( & V_229 , & V_230 , V_3 ) ;
V_295 = V_230 ;
V_229 = V_3 -> V_516 ;
V_230 = V_3 -> V_544 ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x04 , V_265 ) ;
V_265 = ( V_230 & 0xFF00 ) >> 8 ;
V_265 = V_265 << 4 ;
V_265 |= ( V_295 & 0x000F ) ;
F_4 ( V_3 -> V_566 , 0x01 , V_265 ) ;
V_295 = V_658 ;
V_229 = V_3 -> V_514 ;
V_230 = V_3 -> V_539 ;
V_230 &= 0x0FFF ;
if ( F_70 ( V_3 ) ) {
V_229 = V_229 >> 1 ;
V_230 = V_230 >> 1 ;
V_295 = V_295 >> 1 ;
}
if ( V_3 -> V_147 & V_149 )
V_230 += 1 ;
if ( V_3 -> V_147 & V_238 )
V_230 += 1 ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x1F , V_265 ) ;
V_265 = ( ( V_230 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_566 , 0x20 , V_265 ) ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x23 , V_265 ) ;
V_265 = ( V_295 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_566 , 0x25 , V_265 ) ;
F_45 ( & V_229 , & V_230 , V_3 ) ;
V_295 = V_229 ;
V_229 = V_3 -> V_514 ;
V_230 = V_3 -> V_541 ;
if ( F_70 ( V_3 ) ) {
V_229 = V_229 >> 1 ;
V_230 = V_230 >> 1 ;
V_295 = V_295 >> 1 ;
}
if ( V_3 -> V_147 & V_149 )
V_230 += 1 ;
V_295 += V_230 ;
if ( V_295 >= V_229 )
V_295 -= V_229 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x1C , V_265 ) ;
V_265 = ( V_230 & 0xFF00 ) >> 8 ;
V_265 = V_265 << 4 ;
F_14 ( V_3 -> V_566 , 0x1D , ~ 0x0F0 , V_265 ) ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_566 , 0x21 , V_265 ) ;
if ( ! ( V_3 -> V_47 & V_615 ) ) {
if ( V_3 -> V_369 == 525 ) {
if ( V_3 -> V_147 & ( V_256 | V_257
| V_148 | V_149
| V_238 ) ) {
V_265 = 0xC6 ;
} else
V_265 = 0xC4 ;
F_4 ( V_3 -> V_566 , 0x2f , V_265 ) ;
F_4 ( V_3 -> V_566 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_369 == 420 ) {
if ( V_3 -> V_147 & ( V_256 | V_257
| V_148 | V_149
| V_238 ) ) {
V_265 = 0x4F ;
} else
V_265 = 0x4E ;
F_4 ( V_3 -> V_566 , 0x2f , V_265 ) ;
}
}
}
static struct V_671 * F_84 ( unsigned short V_295 ,
struct V_2 * V_3 )
{
unsigned short V_229 , V_230 , V_199 ;
struct V_671 * V_672 ;
if ( V_295 == 0 ) {
V_229 = V_3 -> V_367 ;
V_230 = V_3 -> V_368 ;
} else {
V_229 = V_3 -> V_369 ;
V_230 = V_3 -> V_370 ;
}
if ( V_229 <= V_230 )
return & V_673 [ 0 ] ;
else
V_672 = V_674 ;
if ( V_3 -> V_49 & V_259 )
V_672 = V_675 ;
if ( V_3 -> V_48 & V_254 ) {
if ( ( V_3 -> V_49 & V_602 ) ||
( V_3 -> V_49 & V_557 ) )
V_672 = V_674 ;
if ( V_3 -> V_49 & V_556 )
V_672 = V_676 ;
}
if ( V_3 -> V_48 & V_244 )
V_672 = V_673 ;
V_199 = 0 ;
while ( V_672 [ V_199 ] . V_677 != 0xFFFF ) {
if ( V_672 [ V_199 ] . V_677 == V_229 )
break;
V_199 ++ ;
}
return & V_672 [ V_199 ] ;
}
static void F_85 ( struct V_2 * V_3 )
{
unsigned short V_199 , V_269 ;
struct V_671 * V_672 ;
if ( ! ( V_3 -> V_147 & V_238 ) )
return;
V_672 = F_84 ( 0 , V_3 ) ;
for ( V_199 = 0x80 , V_269 = 0 ; V_199 <= 0xBF ; V_199 ++ , V_269 ++ )
F_4 ( V_3 -> V_566 , V_199 , V_672 -> V_524 [ V_269 ] ) ;
if ( ( V_3 -> V_48 & V_206 ) &&
( ! ( V_3 -> V_48 & V_244 ) ) ) {
V_672 = F_84 ( 1 , V_3 ) ;
for ( V_199 = 0xC0 , V_269 = 0 ; V_199 < 0xFF ; V_199 ++ , V_269 ++ )
F_4 ( V_3 -> V_566 ,
V_199 ,
V_672 -> V_524 [ V_269 ] ) ;
}
if ( ( V_3 -> V_48 & V_206 ) &&
( ! ( V_3 -> V_48 & V_244 ) ) )
F_14 ( V_3 -> V_566 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_14 ( V_3 -> V_566 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_86 ( unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_199 ;
unsigned char * V_375 ;
unsigned short V_200 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
F_4 ( V_3 -> V_678 , 0x00 , 0x00 ) ;
if ( V_3 -> V_49 & V_259 ) {
F_4 ( V_3 -> V_678 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_678 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_678 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_678 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_48 & V_206 ) )
return;
if ( V_3 -> V_49 & V_598 ) {
F_4 ( V_3 -> V_678 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_678 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_678 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_48 & V_244 ) || ( V_3 -> V_48
& V_254 ) ) {
if ( V_3 -> V_49 & V_602 )
return;
V_375 = V_3 -> V_128 ;
if ( V_3 -> V_249 & V_250 ) {
V_375 = V_3 -> V_130 ;
if ( ! ( V_200 & V_219 ) )
V_375 = V_3 -> V_132 ;
}
if ( V_3 -> V_49 & V_557 )
V_375 = V_3 -> V_134 ;
if ( V_3 -> V_49 & V_556 )
V_375 = V_3 -> V_136 ;
for ( V_199 = 0 ; V_199 <= 0x3E ; V_199 ++ )
F_4 ( V_3 -> V_678 , V_199 , V_375 [ V_199 ] ) ;
if ( V_3 -> V_147 & V_238 ) {
if ( V_3 -> V_49 & V_557 )
F_4 ( V_3 -> V_678 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_87 ( unsigned short V_191 , unsigned short V_192 ,
unsigned short V_228 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_229 , V_295 , V_230 , V_200 , V_265 , V_303 ;
unsigned long V_665 , V_664 , V_679 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
V_265 = V_3 -> V_628 ;
F_4 ( V_3 -> V_547 , 0x13 , V_265 ) ;
V_230 = V_3 -> V_627 ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_547 , 0x14 , V_265 ) ;
V_303 = ( ( V_230 & 0xFF00 ) >> 8 ) << 7 ;
V_295 = V_3 -> V_512 - 1 ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_547 , 0x16 , V_265 ) ;
V_265 = ( ( V_295 & 0xFF00 ) >> 8 ) << 3 ;
V_303 |= V_265 ;
V_295 = V_3 -> V_513 - 1 ;
if ( ! ( V_3 -> V_48 & V_206 ) )
V_295 -= 5 ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_547 , 0x17 , V_265 ) ;
V_265 = V_303 | ( ( V_295 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_547 , 0x15 , V_265 ) ;
F_22 ( V_3 -> V_547 , 0x0D , 0x08 ) ;
V_295 = V_3 -> V_48 ;
V_230 = V_3 -> V_367 ;
if ( V_200 & V_298 )
V_230 = V_230 >> 1 ;
if ( F_70 ( V_3 ) )
V_230 = V_230 >> 1 ;
if ( V_295 & V_244 ) {
V_265 = 0 ;
if ( V_230 <= 1024 )
V_265 = 0xA0 ;
if ( V_230 == 1280 )
V_265 = 0xC0 ;
} else if ( V_295 & V_206 ) {
V_265 = 0xA0 ;
if ( V_230 <= 800 )
V_265 = 0x80 ;
} else {
V_265 = 0x80 ;
if ( V_3 -> V_48 & V_207 ) {
V_265 = 0 ;
if ( V_230 > 800 )
V_265 = 0x60 ;
}
}
if ( V_3 -> V_49 & ( V_557 | V_556 ) ) {
V_265 = 0x00 ;
if ( V_3 -> V_367 == 1280 )
V_265 = 0x40 ;
if ( V_3 -> V_367 == 1024 )
V_265 = 0x20 ;
}
F_14 ( V_3 -> V_547 , 0x0E , ~ 0xEF , V_265 ) ;
V_665 = V_3 -> V_370 ;
if ( V_295 & V_244 ) {
if ( ! ( V_265 & 0xE000 ) )
V_230 = V_230 >> 1 ;
}
V_295 = V_3 -> V_633 ;
V_265 = V_295 & 0x00FF ;
F_4 ( V_3 -> V_547 , 0x18 , V_265 ) ;
V_664 = V_3 -> V_369 ;
V_295 |= 0x04000 ;
if ( V_664 <= V_665 ) {
V_295 = ( V_295 & ( ~ 0x4000 ) ) ;
V_664 = V_3 -> V_369 ;
} else {
V_664 -= V_665 ;
}
V_679 = ( V_664 * 256 * 1024 ) % V_665 ;
V_664 = ( V_664 * 256 * 1024 ) / V_665 ;
V_665 = V_664 ;
if ( V_679 != 0 )
V_665 ++ ;
V_265 = ( unsigned short ) ( V_665 & 0x000000FF ) ;
F_4 ( V_3 -> V_547 , 0x1B , V_265 ) ;
V_265 = ( unsigned short ) ( ( V_665 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_547 , 0x1A , V_265 ) ;
V_230 = ( unsigned short ) ( V_665 >> 16 ) ;
V_265 = V_230 & 0x00FF ;
V_265 = V_265 << 4 ;
V_265 |= ( ( V_295 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_547 , 0x19 , V_265 ) ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
V_265 = 0x0028 ;
F_4 ( V_3 -> V_547 , 0x1C , V_265 ) ;
V_229 = V_3 -> V_367 ;
if ( V_200 & V_298 )
V_229 = V_229 >> 1 ;
if ( F_70 ( V_3 ) )
V_229 = V_229 >> 1 ;
if ( V_3 -> V_48 & V_207 ) {
if ( V_229 > 800 )
V_229 -= 800 ;
} else {
if ( V_3 -> V_367 > 800 ) {
if ( V_3 -> V_367 == 1024 )
V_229 = ( V_229 * 25 / 32 ) - 1 ;
else
V_229 = ( V_229 * 20 / 32 ) - 1 ;
}
}
V_229 -= 1 ;
V_265 = ( V_229 & 0xFF00 ) >> 8 ;
V_265 = ( ( V_265 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_547 , 0x1E , V_265 ) ;
V_265 = ( V_229 & 0x00FF ) ;
F_4 ( V_3 -> V_547 , 0x1D , V_265 ) ;
if ( V_3 -> V_48 & ( V_206 | V_244 ) ) {
if ( V_3 -> V_367 > 800 )
F_22 ( V_3 -> V_547 , 0x1E , 0x08 ) ;
}
V_265 = 0x0036 ;
if ( V_3 -> V_48 & V_206 ) {
if ( ! ( V_3 -> V_49 & ( V_559
| V_557 | V_556
| V_605 ) ) ) {
V_265 |= 0x0001 ;
if ( ( V_3 -> V_48 & V_208 )
&& ( ! ( V_3 -> V_49
& V_250 ) ) )
V_265 &= ( ~ 0x0001 ) ;
}
}
F_14 ( V_3 -> V_547 , 0x1F , 0x00C0 , V_265 ) ;
V_230 = V_3 -> V_514 ;
if ( F_70 ( V_3 ) )
V_230 = V_230 >> 1 ;
V_230 = ( V_230 >> 1 ) - 2 ;
V_265 = ( ( V_230 & 0x0700 ) >> 8 ) << 3 ;
F_14 ( V_3 -> V_547 , 0x21 , 0x00C0 , V_265 ) ;
V_265 = V_230 & 0x00FF ;
F_4 ( V_3 -> V_547 , 0x22 , V_265 ) ;
}
if ( V_3 -> V_680 == 0 )
F_73 ( V_191 , V_192 , V_228 ,
V_3 ) ;
}
static void F_88 ( struct V_2 * V_3 )
{
F_14 ( V_3 -> V_203 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_89 ( unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_681 , V_682 ;
V_681 = V_3 -> V_683 ;
V_682 = V_3 -> V_683 + 1 ;
if ( V_3 -> V_195 == V_225 ) {
if ( ! ( V_3 -> V_48 & ( V_208 | V_684
| V_685 ) ) ) {
F_88 ( V_3 ) ;
}
}
return;
}
static void F_90 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_215 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_91 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_215 , 0x63 , 0xBF , 0x00 ) ;
}
void F_62 ( unsigned short V_668 , unsigned short V_525 ,
struct V_2 * V_3 )
{
unsigned char V_622 , V_265 ;
V_622 = F_8 ( V_3 -> V_215 , 0x4A ) ;
V_668 &= 0x23 ;
V_525 &= 0x23 ;
F_15 ( V_3 -> V_215 , 0x4A , ~ V_668 ) ;
if ( V_668 & 0x20 ) {
V_265 = ( V_525 >> 4 ) & 0x02 ;
F_14 ( V_3 -> V_215 , 0xB4 , ~ 0x02 , V_265 ) ;
}
V_265 = F_8 ( V_3 -> V_215 , 0x48 ) ;
V_265 = F_58 ( V_265 ) ;
V_265 &= ~ V_668 ;
V_265 |= V_525 ;
F_4 ( V_3 -> V_215 , 0x48 , V_265 ) ;
}
void F_64 ( unsigned short V_668 , unsigned short V_525 ,
struct V_2 * V_3 )
{
unsigned char V_622 , V_265 ;
unsigned short V_686 , V_687 ;
V_686 = V_668 ;
V_687 = V_525 ;
V_686 &= 0x20 ;
V_687 &= 0x20 ;
V_686 >>= 3 ;
V_687 >>= 3 ;
if ( V_668 & 0x20 ) {
V_265 = ( V_525 >> 4 ) & 0x02 ;
F_14 ( V_3 -> V_215 , 0xB4 , ~ 0x02 , V_265 ) ;
}
F_14 ( V_3 -> V_215 , 0xB4 , ~ V_686 , V_687 ) ;
V_622 = F_8 ( V_3 -> V_215 , 0x4A ) ;
V_668 &= 0x03 ;
V_525 &= 0x03 ;
V_668 <<= 2 ;
V_525 <<= 2 ;
F_15 ( V_3 -> V_215 , 0x4A , ~ V_668 ) ;
F_14 ( V_3 -> V_215 , 0x48 , ~ V_668 , V_525 ) ;
}
unsigned short F_92 ( struct V_2 * V_3 )
{
unsigned short V_193 ;
V_193 = F_8 ( V_3 -> V_215 , 0x36 ) ;
if ( V_193 < sizeof( V_156 )
/ sizeof( struct V_688 ) )
return V_193 ;
return 0 ;
}
void F_63 ( unsigned short V_525 ,
struct V_2 * V_3 )
{
unsigned short V_193 ;
V_193 = F_92 ( V_3 ) ;
if ( V_525 == 1 )
F_93 ( V_3 -> V_155 [ V_193 ] . V_689 ) ;
if ( V_525 == 2 )
F_93 ( V_3 -> V_155 [ V_193 ] . V_690 ) ;
if ( V_525 == 3 )
F_93 ( V_3 -> V_155 [ V_193 ] . V_691 ) ;
if ( V_525 == 4 )
F_93 ( V_3 -> V_155 [ V_193 ] . V_692 ) ;
}
unsigned char F_94 ( unsigned short V_191 ,
unsigned short V_192 , struct V_2 * V_3 )
{
unsigned short V_343 , V_366 , V_655 , V_200 , V_294 ,
V_693 ;
V_294 = F_28 ( V_191 , V_192 , V_3 ) ;
if ( V_191 <= 0x13 ) {
V_343 = V_3 -> V_33 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_33 [ V_294 ] . V_297 ;
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
} else {
V_343 = V_3 -> V_36 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_36 [ V_294 ] . V_297 ;
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
}
if ( ! ( V_200 & V_219 ) ) {
V_343 /= 9 ;
V_343 *= 8 ;
}
if ( V_191 > 0x13 ) {
if ( ( V_191 > 0x13 ) && ( V_200 & V_298 ) )
V_343 *= 2 ;
if ( ( V_191 > 0x13 ) && ( V_200 & V_271 ) )
V_366 *= 2 ;
}
V_693 = F_92 ( V_3 ) ;
if ( V_343 > ( V_3 -> V_155 [ V_693 ] . V_694 ) )
return 0 ;
if ( V_366 > ( V_3 -> V_155 [ V_693 ] . V_695 ) )
return 0 ;
if ( V_191 > 0x13 ) {
if ( ( V_343 != ( V_3 -> V_155 [ V_693 ] .
V_694 ) ) ||
( V_366 != ( V_3 -> V_155 [ V_693 ] .
V_695 ) ) ) {
V_655 = F_74 ( V_191 ,
V_192 ,
V_3 ) ;
if ( V_655 > 2 )
return 0 ;
}
}
return 1 ;
}
void F_33 ( struct V_2 * V_3 )
{
unsigned char V_265 ;
V_265 = F_8 ( V_3 -> V_215 , 0x37 ) ;
V_265 = ( V_265 & 1 ) << 6 ;
F_14 ( V_3 -> V_203 , 0x06 , ~ 0x40 , V_265 ) ;
F_14 ( V_3 -> V_203 , 0x09 , ~ 0xc0 , V_265 | 0x80 ) ;
}
void F_25 ( struct V_2 * V_3 )
{
unsigned char V_265 ;
V_265 = F_8 ( V_3 -> V_215 , 0x37 ) ;
V_265 = ( V_265 & 3 ) << 6 ;
F_14 ( V_3 -> V_203 , 0x06 , ~ 0xc0 , V_265 & 0x80 ) ;
F_14 ( V_3 -> V_203 , 0x09 , ~ 0xc0 , V_265 | 0x80 ) ;
}
static void F_95 ( int V_282 ,
unsigned short V_191 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned char V_265 , V_209 ;
unsigned short V_343 , V_366 , V_200 , V_294 , V_693 ;
unsigned short V_696 , V_697 , V_698 , V_699 , V_700 ;
unsigned short V_701 , V_702 , V_703 , V_704 , V_705 ;
unsigned short V_706 ;
V_693 = F_92 ( V_3 ) ;
V_265 = ( unsigned char ) ( ( V_3 -> V_155 [ V_693 ] .
V_707 &
( V_708 << 8 ) ) >> 8 ) ;
V_265 &= V_708 ;
V_209 = ( unsigned char ) F_10 ( V_3 -> V_287 ) ;
F_6 ( ( V_209 & 0x3F ) | V_265 , V_3 -> V_211 ) ;
V_265 = ( unsigned char ) ( V_3 -> V_155 [ V_693 ] .
V_707 & V_708 ) ;
F_14 ( V_3 -> V_203 , 0x35 , ~ 0x80 , V_265 & 0x80 ) ;
F_14 ( V_3 -> V_203 , 0x30 , ~ 0x20 , ( V_265 & 0x40 ) >> 1 ) ;
if ( V_282 == V_154 )
F_25 ( V_3 ) ;
else
F_33 ( V_3 ) ;
V_294 = F_28 ( V_191 , V_192 , V_3 ) ;
if ( V_191 <= 0x13 ) {
V_343 = V_3 -> V_33 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_33 [ V_294 ] . V_297 ;
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
} else {
V_343 = V_3 -> V_36 [ V_294 ] . V_296 ;
V_366 = V_3 -> V_36 [ V_294 ] . V_297 ;
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
}
if ( ! ( V_200 & V_219 ) )
V_343 = V_343 * 8 / 9 ;
V_696 = V_3 -> V_155 [ V_693 ] . V_696 ;
V_697 = V_343 + ( V_3 -> V_155 [ V_693 ] . V_694
- V_343 ) / 2 ;
if ( ( V_191 <= 0x13 ) && ( V_200 & V_298 ) )
V_697 -= V_343 / 4 ;
if ( V_697 > V_696 )
V_697 -= V_696 ;
V_698 = V_697 + V_3 -> V_155 [ V_693 ] . V_709 ;
if ( V_698 > V_696 )
V_698 -= V_696 ;
V_699 = V_698 + V_3 -> V_155 [ V_693 ] . V_710 ;
if ( V_699 > V_696 )
V_699 -= V_696 ;
V_700 = V_697 + V_696
- V_3 -> V_155 [ V_693 ] . V_694 ;
V_701 = V_3 -> V_155 [ V_693 ] . V_701 ;
V_702 = V_366 + ( V_3 -> V_155 [ V_693 ] . V_695
- V_366 ) / 2 ;
if ( ( V_191 > 0x13 ) && ( V_200 & V_271 ) )
V_702 += V_366 / 2 ;
if ( V_702 > V_701 )
V_702 -= V_701 ;
V_703 = V_702 + V_3 -> V_155 [ V_693 ] . V_711 ;
if ( V_703 > V_701 )
V_703 -= V_701 ;
V_704 = V_703 + V_3 -> V_155 [ V_693 ] .
V_712 ;
if ( V_704 > V_701 )
V_704 -= V_701 ;
V_705 = V_702 + V_701
- V_3 -> V_155 [ V_693 ] . V_695 ;
V_265 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x11 ) ;
F_4 ( V_3 -> V_215 , 0x11 , V_265 & 0x7f ) ;
if ( ! ( V_200 & V_219 ) )
F_22 ( V_3 -> V_203 , 0x1 , 0x1 ) ;
V_706 = ( V_696 >> 3 ) - 5 ;
F_14 ( V_3 -> V_203 , 0x0B , ~ 0x03 , ( V_706 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_215 , 0x0 , ( V_706 & 0xFF ) ) ;
V_706 = ( V_697 >> 3 ) - 1 ;
F_14 ( V_3 -> V_203 , 0x0B , ~ 0x30 , ( V_706 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_215 , 0x2 , ( V_706 & 0xFF ) ) ;
V_706 = ( V_700 >> 3 ) - 1 ;
F_14 ( V_3 -> V_203 , 0x0C , ~ 0x03 , ( V_706 & 0xC0 ) >> 6 ) ;
F_14 ( V_3 -> V_215 , 0x05 , ~ 0x80 , ( V_706 & 0x20 ) << 2 ) ;
F_14 ( V_3 -> V_215 , 0x03 , ~ 0x1F , V_706 & 0x1F ) ;
V_706 = ( V_698 >> 3 ) + 2 ;
F_14 ( V_3 -> V_203 , 0x0B , ~ 0xC0 , ( V_706 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_215 , 0x4 , ( V_706 & 0xFF ) ) ;
V_706 -- ;
F_14 ( V_3 -> V_203 , 0x2F , ~ 0x03 , ( V_706 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_203 , 0x2E , ( V_706 & 0xFF ) ) ;
V_706 = ( V_699 >> 3 ) + 2 ;
F_14 ( V_3 -> V_203 , 0x0C , ~ 0x04 , ( V_706 & 0x20 ) >> 3 ) ;
F_14 ( V_3 -> V_215 , 0x05 , ~ 0x1F , V_706 & 0x1F ) ;
V_706 -- ;
F_14 ( V_3 -> V_203 , 0x2F , ~ 0xFC , V_706 << 2 ) ;
V_706 = V_701 - 2 ;
F_14 ( V_3 -> V_203 , 0x0A , ~ 0x01 , ( V_706 & 0x400 ) >> 10 ) ;
F_14 ( V_3 -> V_215 , 0x07 , ~ 0x20 , ( V_706 & 0x200 ) >> 4 ) ;
F_14 ( V_3 -> V_215 , 0x07 , ~ 0x01 , ( V_706 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_215 , 0x06 , ( V_706 & 0xFF ) ) ;
V_706 = V_702 - 1 ;
F_14 ( V_3 -> V_203 , 0x0A , ~ 0x04 , ( V_706 & 0x400 ) >> 8 ) ;
F_14 ( V_3 -> V_215 , 0x09 , ~ 0x20 , ( V_706 & 0x200 ) >> 4 ) ;
F_14 ( V_3 -> V_215 , 0x07 , ~ 0x08 , ( V_706 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_215 , 0x15 , ( V_706 & 0xFF ) ) ;
V_706 = V_705 - 1 ;
F_14 ( V_3 -> V_203 , 0x0A , ~ 0x10 , ( V_706 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_215 , 0x16 , ( V_706 & 0xFF ) ) ;
V_706 = V_703 - 1 ;
F_14 ( V_3 -> V_203 , 0x0A , ~ 0x08 , ( V_706 & 0x400 ) >> 7 ) ;
F_14 ( V_3 -> V_215 , 0x07 , ~ 0x80 , ( V_706 & 0x200 ) >> 2 ) ;
F_14 ( V_3 -> V_215 , 0x07 , ~ 0x04 , ( V_706 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_215 , 0x10 , ( V_706 & 0xFF ) ) ;
if ( V_282 == V_154 ) {
F_14 ( V_3 -> V_203 , 0x35 , ~ 0x07 ,
( V_706 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_203 , 0x34 , V_706 & 0xFF ) ;
} else {
F_14 ( V_3 -> V_203 , 0x3F , ~ 0x03 ,
( V_706 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_203 , 0x34 , ( V_706 >> 1 ) & 0xFF ) ;
F_14 ( V_3 -> V_215 , 0x33 , ~ 0x01 , V_706 & 0x01 ) ;
}
V_706 = V_704 - 1 ;
F_14 ( V_3 -> V_203 , 0x0A , ~ 0x20 , ( V_706 & 0x10 ) << 1 ) ;
F_14 ( V_3 -> V_215 , 0x11 , ~ 0x0F , V_706 & 0x0F ) ;
if ( V_282 == V_154 )
F_14 ( V_3 -> V_203 , 0x3F , ~ 0xFC ,
( V_706 << 2 ) & 0xFC ) ;
else
F_14 ( V_3 -> V_203 , 0x3F , ~ 0xFC ,
( V_706 << 2 ) & 0x7C ) ;
for ( V_265 = 0 , V_706 = 0 ; V_265 < 3 ; V_265 ++ ) {
F_14 ( V_3 -> V_203 , 0x31 , ~ 0x30 , V_706 ) ;
F_4 ( V_3 -> V_203 ,
0x2B ,
V_3 -> V_155 [ V_693 ] .
V_713 ) ;
F_4 ( V_3 -> V_203 ,
0x2C ,
V_3 -> V_155 [ V_693 ] .
V_714 ) ;
V_706 += 0x10 ;
}
if ( ! ( V_200 & V_219 ) ) {
F_10 ( V_3 -> V_220 ) ;
F_6 ( 0x13 , V_3 -> V_221 ) ;
F_6 ( 0x00 , V_3 -> V_221 ) ;
F_10 ( V_3 -> V_220 ) ;
F_6 ( 0x20 , V_3 -> V_221 ) ;
F_10 ( V_3 -> V_220 ) ;
}
}
static unsigned char F_96 ( struct V_2 * V_3 )
{
unsigned short V_229 ;
V_229 = V_3 -> V_48 ;
if ( V_229 & V_580 )
return 0 ;
else if ( V_229 & ( V_581 | V_592 | V_591 ) )
return 1 ;
return 0 ;
}
static unsigned char F_97 ( struct V_2 * V_3 )
{
unsigned short V_230 , V_197 ;
V_230 = V_3 -> V_249 & ( V_715 | V_716 ) ;
V_197 = ~ ( ( unsigned short ) F_8 ( V_3 -> V_540 , 0x2E ) ) ;
if ( V_230 & ( V_717 | V_715 ) ) {
if ( ! ( V_197 & 0x08 ) )
return 0 ;
}
if ( ! ( V_230 & ( V_718 | V_716 ) ) )
return 0 ;
if ( V_197 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_98 ( struct V_2 * V_3 )
{
unsigned short V_230 , V_197 ;
V_230 = V_3 -> V_249 & ( V_717 | V_718 ) ;
V_197 = ~ ( ( unsigned short ) F_8 ( V_3 -> V_540 , 0x2E ) ) ;
if ( V_230 & ( V_717 | V_715 ) ) {
if ( ! ( V_197 & 0x08 ) )
return 0 ;
}
if ( ! ( V_230 & ( V_718 | V_716 ) ) )
return 0 ;
if ( V_197 & 0x01 )
return 1 ;
return 0 ;
}
void F_99 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_197 = 0 ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
V_197 = 0x3F ;
if ( ! ( V_3 -> V_48 &
( V_581 | V_591 ) ) ) {
if ( V_3 -> V_48 & V_205 ) {
if ( V_3 -> V_48 & V_580 ) {
V_197 = 0x7F ;
if ( ! ( V_3 -> V_48 & V_205 ) )
V_197 = 0xBF ;
if ( V_3 -> V_249 & V_716 )
V_197 &= 0xBF ;
if ( V_3 -> V_249 & V_715 )
V_197 &= 0x7F ;
}
}
}
F_15 ( V_3 -> V_547 , 0x1F , V_197 ) ;
if ( V_3 -> V_147 & ( V_149 | V_238 ) ) {
if ( ( ( V_3 -> V_48 & ( V_207 | V_205 ) ) )
|| ( F_97 ( V_3 ) )
|| ( F_96 ( V_3 ) ) )
F_22 ( V_3 -> V_547 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_249 & V_715 ) || ( V_3 -> V_48
& ( V_581 | V_205
| V_591 ) ) ) {
if ( V_3 -> V_249 & V_719 )
F_90 ( V_213 , V_3 ) ;
F_65 ( V_213 , V_3 ) ;
}
if ( V_3 -> V_48 & V_205 ) {
if ( ( V_3 -> V_249 & V_715 ) || ( V_3 -> V_48
& V_205 ) )
F_15 ( V_3 -> V_540 , 0x1e , 0xdf ) ;
}
F_15 ( V_3 -> V_203 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_48 & ( V_591 | V_580 ) ) )
F_15 ( V_3 -> V_566 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_249 & V_716 ) ||
( V_3 -> V_48 &
( V_581 | V_591 ) ) ||
( ( ! ( V_3 -> V_48 & V_205 ) ) &&
( V_3 -> V_48 &
( V_236 | V_207 | V_206 ) ) ) )
F_22 ( V_3 -> V_540 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_249 & V_716 ) ||
( V_3 -> V_48 &
( V_581 | V_591 ) ) ||
( ! ( V_3 -> V_48 & V_205 ) ) ||
( V_3 -> V_48 &
( V_236 | V_207 | V_206 ) ) ) {
V_197 = F_8 ( V_3 -> V_540 , 0x00 ) ;
F_22 ( V_3 -> V_540 , 0x00 , 0x10 ) ;
F_15 ( V_3 -> V_540 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_540 , 0x00 , V_197 ) ;
}
} else {
if ( V_3 -> V_48 & ( V_207 | V_206 ) ) {
F_22 ( V_3 -> V_540 , 0x00 , 0x80 ) ;
F_15 ( V_3 -> V_540 , 0x1E , 0xDF ) ;
F_15 ( V_3 -> V_203 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_48 & ( V_581 | V_205
| V_591 ) )
F_65 ( V_213 , V_3 ) ;
}
}
static unsigned short F_100 ( struct V_2 * V_3 )
{
unsigned short V_230 = 0 ;
if ( V_3 -> V_49 & V_259 )
V_230 = 2 ;
if ( V_3 -> V_49 & V_605 )
V_230 = 4 ;
if ( V_3 -> V_49 & V_602 )
V_230 = 6 ;
if ( V_3 -> V_49 & V_557 )
V_230 = 8 ;
if ( V_3 -> V_49 & V_556 )
V_230 = 10 ;
if ( V_3 -> V_49 & V_250 )
V_230 ++ ;
return V_230 ;
}
static void F_101 ( unsigned short * V_230 , unsigned char * V_561 ,
unsigned char * V_562 , struct V_2 * V_3 )
{
* V_230 = 0 ;
* V_561 = 0 ;
* V_562 = 0 ;
if ( V_3 -> V_49 & V_259 )
* V_230 = 1 ;
if ( V_3 -> V_49 & V_598 )
* V_230 = 2 ;
if ( V_3 -> V_49 & V_599 )
* V_230 = 3 ;
if ( V_3 -> V_49 & V_559 ) {
* V_230 = 4 ;
if ( V_3 -> V_49 & V_598 )
* V_230 = 5 ;
}
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
if ( ( ! ( V_3 -> V_48 & V_208 ) ) || ( V_3 -> V_49
& V_250 ) ) {
* V_230 += 8 ;
* V_561 += 1 ;
}
}
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) )
( * V_562 ) ++ ;
}
static void F_102 ( struct V_2 * V_3 )
{
unsigned short V_193 ;
unsigned char V_197 , V_525 , V_668 ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
if ( V_3 -> V_48 & ( V_207 | V_205
| V_206 | V_236 ) ) {
V_525 = 0 ;
V_668 = 0 ;
V_193 = F_100 ( V_3 ) ;
V_525 = V_3 -> V_157 [ V_193 ] ;
if ( V_3 -> V_147 & ( V_256 | V_257
| V_148 | V_149
| V_238 ) )
V_525 = V_3 -> V_159 [ V_193 ] ;
if ( V_3 -> V_48 & V_580 )
V_525 = V_525 >> 4 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_193 = F_43 ( V_3 ) ;
V_668 = V_3 -> V_150 [ V_193 ] .
V_720 ;
if ( ! ( V_3 -> V_48 & V_205 ) )
V_525 = V_668 ;
}
V_525 &= 0x0F ;
V_668 &= 0xF0 ;
V_197 = F_8 ( V_3 -> V_540 , 0x2D ) ;
if ( V_3 -> V_48 & ( V_236 | V_207
| V_206 ) ) {
V_197 &= 0xF0 ;
V_197 |= V_525 ;
}
if ( V_3 -> V_48 & V_205 ) {
V_197 &= 0x0F ;
V_197 |= V_668 ;
}
F_4 ( V_3 -> V_540 , 0x2D , V_197 ) ;
}
} else if ( V_3 -> V_235 == 1 ) {
V_525 = 0 ;
V_668 = 0 ;
if ( V_3 -> V_48 & V_207 ) {
V_197 = V_3 -> V_150 [
F_43 ( V_3 ) ] .
V_720 ;
V_197 &= 0x0f ;
V_197 = V_197 << 4 ;
F_14 ( V_3 -> V_540 , 0x2D , 0x0f ,
V_197 ) ;
}
}
}
static void F_103 ( unsigned short V_295 ,
struct V_2 * V_3 )
{
unsigned short V_265 ;
V_265 = F_8 ( V_3 -> V_215 , 0x37 ) ;
if ( V_265 & V_660 ) {
F_14 ( V_3 -> V_540 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_295 & 0x00C0 ) ) ) ;
F_14 ( V_3 -> V_540 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_14 ( V_3 -> V_540 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_295 & 0x00C0 ) ) ) ;
F_14 ( V_3 -> V_540 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_104 ( unsigned short V_295 ,
struct V_2 * V_3 )
{
if ( V_295 & V_721 )
F_14 ( V_3 -> V_566 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_295 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_14 ( V_3 -> V_566 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_295 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_105 ( struct V_2 * V_3 )
{
unsigned short V_193 ;
V_193 = F_43 ( V_3 ) ;
F_15 ( V_3 -> V_547 , 0x30 , 0x8F ) ;
F_106 ( V_3 ) ;
F_22 ( V_3 -> V_547 , 0x30 , 0x20 ) ;
F_106 ( V_3 ) ;
F_4 ( V_3 -> V_547 , 0x31 ,
V_3 -> V_150 [ V_193 ] . V_722 ) ;
F_4 ( V_3 -> V_547 , 0x32 ,
V_3 -> V_150 [ V_193 ] . V_723 ) ;
F_4 ( V_3 -> V_547 , 0x33 ,
V_3 -> V_150 [ V_193 ] . V_724 ) ;
F_4 ( V_3 -> V_547 , 0x34 ,
V_3 -> V_150 [ V_193 ] . V_725 ) ;
F_106 ( V_3 ) ;
F_22 ( V_3 -> V_547 , 0x30 , 0x40 ) ;
}
static void F_107 ( struct V_2 * V_3 )
{
unsigned short V_295 ;
V_295 = V_3 -> V_150 [ F_43 ( V_3 ) ] . V_611 ;
if ( V_3 -> V_147 &
( V_256 |
V_257 |
V_148 |
V_149 |
V_238 ) ) {
if ( V_3 -> V_147 &
( V_148 | V_149 | V_238 ) ) {
F_4 ( V_3 -> V_547 , 0x24 ,
( unsigned char ) ( V_295 & 0x1F ) ) ;
}
F_14 ( V_3 -> V_547 , 0x0D ,
~ ( ( V_726 | V_727 ) >> 8 ) ,
( unsigned short ) ( ( V_295 & ( V_726
| V_727 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
if ( V_3 -> V_48 & V_207 )
F_104 ( V_295 , V_3 ) ;
else if ( V_3 -> V_48 & V_205 )
F_103 ( V_295 , V_3 ) ;
if ( V_3 -> V_147 & ( V_149 | V_238 ) ) {
if ( V_295 & V_728 )
F_105 ( V_3 ) ;
}
} else {
F_103 ( V_295 , V_3 ) ;
}
}
static void F_108 ( unsigned short V_191 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_230 , V_193 ;
unsigned char V_197 ;
if ( V_3 -> V_49 & ( V_557 | V_556 ) )
return;
V_230 = F_100 ( V_3 ) ;
V_230 &= 0xFE ;
if ( V_191 <= 0x13 )
V_193 = V_3 -> V_4 [ V_192 ] . V_729 ;
else
V_193 = V_3 -> V_10 [ V_192 ] . V_730 ;
V_230 += V_193 ;
V_197 = V_731 [ V_230 ] ;
V_197 = V_197 << 4 ;
F_14 ( V_3 -> V_566 , 0x0A , 0x8F , V_197 ) ;
}
static void F_109 ( unsigned short V_191 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_230 , V_193 ;
unsigned char V_197 ;
V_230 = F_100 ( V_3 ) ;
V_230 &= 0xFE ;
if ( V_191 <= 0x13 )
V_193 = V_3 -> V_4 [ V_192 ] . V_732 ;
else
V_193 = V_3 -> V_10 [ V_192 ] . V_733 ;
V_230 += V_193 ;
V_197 = V_734 [ V_230 ] ;
V_197 = V_197 << 5 ;
F_14 ( V_3 -> V_566 , 0x3A , 0x1F , V_197 ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
unsigned short V_230 ;
unsigned char V_561 , V_562 ;
unsigned long V_735 ;
F_101 ( & V_230 , & V_561 , & V_562 , V_3 ) ;
V_735 = V_736 [ V_230 ] ;
F_4 ( V_3 -> V_566 , 0x31 , ( unsigned short ) ( V_735
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_566 , 0x32 , ( unsigned short ) ( ( V_735
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_566 , 0x33 , ( unsigned short ) ( ( V_735
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_566 , 0x34 , ( unsigned short ) ( ( V_735
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_111 ( unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_230 , V_193 ;
unsigned char V_561 , V_562 , V_373 , * V_737 ;
F_101 ( & V_230 , & V_561 , & V_562 , V_3 ) ;
switch ( V_230 ) {
case 0x00 :
case 0x04 :
V_737 = V_738 ;
break;
case 0x01 :
V_737 = V_739 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_737 = V_740 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_737 = V_741 ;
break;
default:
return;
}
if ( V_191 <= 0x13 )
V_373 = V_3 -> V_4 [ V_192 ] .
V_742 ;
else
V_373 = V_3 -> V_10 [ V_192 ] .
V_743 ;
if ( V_561 == 0 )
V_193 = V_373 * 4 ;
else
V_193 = V_373 * 7 ;
if ( ( V_561 == 0 ) && ( V_562 == 1 ) ) {
F_4 ( V_3 -> V_566 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_566 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_566 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_566 , 0x38 , V_737 [ V_193 ++ ] ) ;
} else {
F_4 ( V_3 -> V_566 , 0x35 , V_737 [ V_193 ++ ] ) ;
F_4 ( V_3 -> V_566 , 0x36 , V_737 [ V_193 ++ ] ) ;
F_4 ( V_3 -> V_566 , 0x37 , V_737 [ V_193 ++ ] ) ;
F_4 ( V_3 -> V_566 , 0x38 , V_737 [ V_193 ++ ] ) ;
}
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
F_4 ( V_3 -> V_566 , 0x48 , V_737 [ V_193 ++ ] ) ;
F_4 ( V_3 -> V_566 , 0x49 , V_737 [ V_193 ++ ] ) ;
F_4 ( V_3 -> V_566 , 0x4A , V_737 [ V_193 ++ ] ) ;
}
}
static void F_112 ( unsigned short V_191 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
F_102 ( V_3 ) ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) )
F_107 ( V_3 ) ;
if ( V_3 -> V_48 & V_206 ) {
F_110 ( V_3 ) ;
F_111 ( V_191 , V_192 , V_3 ) ;
F_108 ( V_191 , V_192 , V_3 ) ;
if ( V_3 -> V_147 & V_560 )
F_109 ( V_191 , V_192 , V_3 ) ;
}
}
void F_113 ( unsigned short V_191 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_525 ;
short V_561 ;
unsigned char V_197 ;
V_197 = 0 ;
if ( ! ( V_3 -> V_48 & V_581 ) ) {
V_197 = F_8 ( V_3 -> V_540 , 0x00 ) ;
V_197 &= ~ 0x10 ;
V_197 |= 0x40 ;
if ( V_3 -> V_48 & ( V_236 | V_206
| V_207 ) ) {
V_197 = 0x40 ;
if ( V_191 > 0x13 ) {
V_561 = V_3 -> V_195 ;
V_561 -= V_225 ;
if ( V_561 >= 0 ) {
V_197 = ( 0x008 >> V_561 ) ;
if ( V_197 == 0 )
V_197 = 1 ;
V_197 |= 0x040 ;
}
}
if ( V_3 -> V_48 & V_208 )
V_197 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_540 , 0x00 , V_197 ) ;
V_197 = 0x08 ;
V_525 = 0xf0 ;
if ( V_3 -> V_48 & V_581 ) {
F_14 ( V_3 -> V_540 , 0x2e , V_525 , V_197 ) ;
} else {
V_197 = 0x00 ;
V_525 = 0xff ;
if ( V_3 -> V_48 & ( V_236 | V_206
| V_207 | V_205 ) ) {
if ( ( V_3 -> V_48 & V_205 ) &&
( ! ( V_3 -> V_48 & V_591 ) ) ) {
V_525 &= 0xf7 ;
V_197 |= 0x01 ;
F_14 ( V_3 -> V_540 , 0x2e ,
V_525 , V_197 ) ;
} else {
if ( V_3 -> V_48 & V_205 ) {
V_525 &= 0xf7 ;
V_197 |= 0x01 ;
}
if ( V_3 -> V_48 &
( V_236 |
V_206 |
V_207 ) ) {
V_525 &= 0xf8 ;
V_197 = 0x01 ;
if ( ! ( V_3 -> V_48 & V_208 ) )
V_197 |= 0x02 ;
if ( ! ( V_3 -> V_48 &
V_236 ) ) {
V_197 = V_197 ^ 0x05 ;
if ( ! ( V_3 -> V_48 &
V_207 ) )
V_197 = V_197 ^ 0x01 ;
}
if ( ! ( V_3 -> V_48 &
V_580 ) )
V_197 |= 0x08 ;
F_14 ( V_3 -> V_540 ,
0x2e , V_525 , V_197 ) ;
} else {
F_14 ( V_3 -> V_540 ,
0x2e , V_525 , V_197 ) ;
}
}
} else {
F_14 ( V_3 -> V_540 , 0x2e , V_525 ,
V_197 ) ;
}
}
if ( V_3 -> V_48 & ( V_236 | V_206 | V_207
| V_205 ) ) {
V_197 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_195 == V_225 ) && ( ! ( V_3 -> V_48
& V_208 ) ) ) {
V_197 |= 0x010 ;
}
V_197 |= 0x080 ;
if ( V_3 -> V_48 & V_206 ) {
V_197 |= 0x020 ;
if ( V_191 > 0x13 ) {
if ( V_3 -> V_48 & V_594 )
V_197 = V_197 ^ 0x20 ;
}
}
F_14 ( V_3 -> V_547 , 0x0D , ~ 0x0BF , V_197 ) ;
V_197 = 0 ;
if ( V_3 -> V_47 & V_613 )
V_197 |= 0x40 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_49 & V_319 )
V_197 |= 0x40 ;
}
if ( ( V_3 -> V_45 == V_241 )
|| ( V_3 -> V_45 == V_519 ) )
V_197 |= 0x80 ;
if ( V_3 -> V_45 == V_242 )
V_197 |= 0x80 ;
F_4 ( V_3 -> V_547 , 0x0C , V_197 ) ;
}
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
V_197 = 0 ;
V_525 = 0xfb ;
if ( V_3 -> V_48 & V_580 ) {
V_525 = 0xff ;
if ( V_3 -> V_48 & V_205 )
V_197 |= 0x04 ;
}
F_14 ( V_3 -> V_540 , 0x13 , V_525 , V_197 ) ;
V_197 = 0x00 ;
V_525 = 0xcf ;
if ( ! ( V_3 -> V_48 & V_581 ) ) {
if ( V_3 -> V_48 & V_580 )
V_197 |= 0x30 ;
}
F_14 ( V_3 -> V_540 , 0x2c , V_525 , V_197 ) ;
V_197 = 0 ;
V_525 = 0x3f ;
if ( ! ( V_3 -> V_48 & V_581 ) ) {
if ( V_3 -> V_48 & V_580 )
V_197 |= 0xc0 ;
}
F_14 ( V_3 -> V_547 , 0x21 , V_525 , V_197 ) ;
}
V_197 = 0 ;
V_525 = 0x7f ;
if ( ! ( V_3 -> V_48 & V_205 ) ) {
V_525 = 0xff ;
if ( ! ( V_3 -> V_48 & V_580 ) )
V_197 |= 0x80 ;
}
F_14 ( V_3 -> V_547 , 0x23 , V_525 , V_197 ) ;
if ( V_3 -> V_147 & ( V_149 | V_238 ) ) {
if ( V_3 -> V_47 & V_613 ) {
F_22 ( V_3 -> V_547 , 0x27 , 0x20 ) ;
F_22 ( V_3 -> V_547 , 0x34 , 0x10 ) ;
}
}
}
static void F_114 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_230 ;
V_230 = 0 ;
if ( V_3 -> V_48 & V_205 )
V_230 = 0x08A0 ;
}
void F_115 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_540 , 0x2f , 0xFF , 0x01 ) ;
}
void F_116 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
F_14 ( V_3 -> V_540 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_117 ( struct V_2 * V_3 )
{
unsigned short V_576 ;
if ( V_3 -> V_235 == 1 ) {
return 1 ;
} else {
V_576 = F_8 ( V_3 -> V_547 , 0x00 ) ;
if ( ( V_576 == 1 ) || ( V_576 == 2 ) )
return 1 ;
else
return 0 ;
}
}
void F_106 ( struct V_2 * V_3 )
{
unsigned short V_199 ;
V_199 = F_8 ( V_3 -> V_203 , 0x1F ) ;
if ( ! ( V_199 & 0xC0 ) ) {
for ( V_199 = 0 ; V_199 < 0xFFFF ; V_199 ++ ) {
if ( ! ( F_10 ( V_3 -> V_220 ) & 0x08 ) )
break;
}
for ( V_199 = 0 ; V_199 < 0xFFFF ; V_199 ++ ) {
if ( ( F_10 ( V_3 -> V_220 ) & 0x08 ) )
break;
}
}
}
static void F_118 ( struct V_2 * V_3 )
{
unsigned short V_373 , V_265 , V_199 , V_269 ;
return;
if ( ! ( V_3 -> V_48 & V_206 ) ) {
V_265 = 0 ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
for ( V_269 = 0 ; V_269 < 100 ; V_269 ++ ) {
V_373 = F_10 ( V_3 -> V_220 ) ;
if ( V_265 & 0x01 ) {
if ( ( V_373 & 0x08 ) )
continue;
if ( ! ( V_373 & 0x08 ) )
break;
} else {
if ( ! ( V_373 & 0x08 ) )
continue;
if ( ( V_373 & 0x08 ) )
break;
}
}
V_265 = V_265 ^ 0x01 ;
}
} else {
F_106 ( V_3 ) ;
}
return;
}
unsigned short F_119 ( struct V_212 * V_624 ,
unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
short V_744 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_745 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_228 , V_199 , V_200 , V_193 , V_265 ;
if ( V_191 <= 0x13 )
V_200 = V_3 -> V_4 [ V_192 ] . V_201 ;
else
V_200 = V_3 -> V_10 [ V_192 ] . V_202 ;
if ( V_191 < 0x14 )
return 0xFFFF ;
V_193 = F_8 ( V_3 -> V_215 , 0x33 ) ;
V_193 = V_193 >> V_3 -> V_746 ;
V_193 &= 0x0F ;
if ( V_3 -> V_47 & V_243 )
V_193 = 0 ;
if ( V_193 > 0 )
V_193 -- ;
if ( V_3 -> V_249 & V_554 ) {
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
if ( V_3 -> V_235 == 0 ) {
if ( V_3 -> V_147 & ( V_256 | V_257
| V_148 | V_149
| V_238 ) )
V_265 = V_745 [
V_3 -> V_45 & 0x0F ] ;
else
V_265 = V_744 [
V_3 -> V_45 & 0x0F ] ;
if ( V_193 > V_265 )
V_193 = V_265 ;
} else {
V_193 = 0 ;
}
}
}
V_228 = V_3 -> V_10 [ V_192 ] . V_747 ;
V_191 = V_3 -> V_13 [ V_228 ] . V_234 ;
if ( V_624 -> V_270 >= V_163 ) {
if ( ( V_3 -> V_13 [ V_228 ] . V_748 == 800 ) &&
( V_3 -> V_13 [ V_228 ] . V_749 == 600 ) ) {
V_193 ++ ;
}
if ( ( V_3 -> V_13 [ V_228 ] . V_748 == 1024 ) &&
( V_3 -> V_13 [ V_228 ] . V_749 == 768 ) ) {
V_193 ++ ;
}
if ( ( V_3 -> V_13 [ V_228 ] . V_748 == 1280 ) &&
( V_3 -> V_13 [ V_228 ] . V_749 == 1024 ) ) {
V_193 ++ ;
}
}
V_199 = 0 ;
do {
if ( V_3 -> V_13 [ V_228 + V_199 ] .
V_234 != V_191 )
break;
V_265 = V_3 -> V_13 [ V_228 + V_199 ] .
V_263 ;
V_265 &= V_579 ;
if ( V_265 < V_3 -> V_195 )
break;
V_199 ++ ;
V_193 -- ;
} while ( V_193 != 0xFFFF );
if ( ! ( V_3 -> V_48 & V_236 ) ) {
if ( V_3 -> V_48 & V_208 ) {
V_265 = V_3 -> V_13 [ V_228 + V_199 - 1 ] .
V_263 ;
if ( V_265 & V_299 )
V_199 ++ ;
}
}
V_199 -- ;
if ( ( V_3 -> V_249 & V_554 ) ) {
V_265 = F_16 ( V_191 , V_192 ,
V_228 , & V_199 , V_3 ) ;
}
return V_228 + V_199 ;
}
static void F_120 ( unsigned short V_191 , unsigned short V_192 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_228 ;
V_3 -> V_249 |= V_554 ;
V_228 = F_119 ( V_213 , V_191 ,
V_192 , V_3 ) ;
F_38 ( V_191 , V_192 , V_3 ) ;
F_41 ( V_191 , V_192 , V_228 , V_3 ) ;
F_42 ( V_191 , V_192 , V_228 ,
V_213 , V_3 ) ;
F_46 ( V_191 , V_192 , V_228 , V_3 ) ;
F_50 ( V_191 , V_192 , V_228 , V_3 ) ;
}
unsigned char F_121 ( unsigned short V_191 ,
struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_230 , V_192 , V_228 ;
V_230 = V_3 -> V_48 ;
V_3 -> V_249 |= V_554 ;
F_57 ( V_191 , & V_192 , V_3 ) ;
V_3 -> V_746 = 4 ;
V_228 = F_119 ( V_213 , V_191 ,
V_192 , V_3 ) ;
F_68 ( V_191 , V_3 ) ;
F_69 ( V_191 , V_192 , V_3 ) ;
F_72 ( V_191 , V_192 , V_228 , V_3 ) ;
F_78 ( V_191 , V_192 , V_213 ,
V_228 , V_3 ) ;
F_79 ( V_191 , V_192 , V_213 ,
V_228 , V_3 ) ;
F_81 ( V_191 , V_192 , V_213 ,
V_228 , V_3 ) ;
F_82 ( V_191 , V_192 , V_228 ,
V_213 , V_3 ) ;
F_83 ( V_191 , V_192 , V_213 ,
V_228 , V_3 ) ;
F_85 ( V_3 ) ;
F_86 ( V_191 , V_192 , V_3 ) ;
F_87 ( V_191 , V_192 , V_228 ,
V_213 , V_3 ) ;
F_73 ( V_191 , V_192 , V_228 , V_3 ) ;
F_89 ( V_191 , V_192 , V_3 ) ;
F_67 ( V_3 ) ;
return 1 ;
}
void F_122 ( struct V_2 * V_3 )
{
unsigned char V_750 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_751 = 0 , V_752 = 0 , V_753 = 0 , V_754 = 0 ;
unsigned char V_755 , V_756 , V_757 ;
unsigned short V_265 ;
unsigned char V_758 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_199 ;
F_4 ( V_3 -> V_203 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_215 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_215 , 0x53 , ( unsigned char ) ( F_8 (
V_3 -> V_215 , 0x53 ) | 0x02 ) ) ;
V_757 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x31 ) ;
V_756 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x63 ) ;
V_751 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x01 ) ;
F_4 ( V_3 -> V_203 , 0x01 , ( unsigned char ) ( V_751 & 0xDF ) ) ;
F_4 ( V_3 -> V_215 , 0x63 , ( unsigned char ) ( V_756 & 0xBF ) ) ;
V_755 = ( unsigned char ) F_8 ( V_3 -> V_215 , 0x17 ) ;
F_4 ( V_3 -> V_215 , 0x17 , ( unsigned char ) ( V_755 | 0x80 ) ) ;
V_752 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x1F ) ;
F_4 ( V_3 -> V_203 , 0x1F , ( unsigned char ) ( V_752 | 0x04 ) ) ;
V_753 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x07 ) ;
F_4 ( V_3 -> V_203 , 0x07 , ( unsigned char ) ( V_753 & 0xFB ) ) ;
V_754 = ( unsigned char ) F_8 ( V_3 -> V_203 , 0x06 ) ;
F_4 ( V_3 -> V_203 , 0x06 , ( unsigned char ) ( V_754 & 0xC3 ) ) ;
F_4 ( V_3 -> V_215 , 0x11 , 0x00 ) ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ )
F_4 ( V_3 -> V_215 , ( unsigned short ) V_199 , V_750 [ V_199 ] ) ;
for ( V_199 = 8 ; V_199 < 11 ; V_199 ++ )
F_4 ( V_3 -> V_215 , ( unsigned short ) ( V_199 + 8 ) ,
V_750 [ V_199 ] ) ;
for ( V_199 = 11 ; V_199 < 13 ; V_199 ++ )
F_4 ( V_3 -> V_215 , ( unsigned short ) ( V_199 + 4 ) ,
V_750 [ V_199 ] ) ;
for ( V_199 = 13 ; V_199 < 16 ; V_199 ++ )
F_4 ( V_3 -> V_203 , ( unsigned short ) ( V_199 - 3 ) ,
V_750 [ V_199 ] ) ;
F_4 ( V_3 -> V_203 , 0x0E , ( unsigned char ) ( V_750 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_203 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_203 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_203 , 0x2C , 0xE1 ) ;
F_6 ( 0x00 , V_3 -> V_365 ) ;
for ( V_199 = 0 ; V_199 < 256 ; V_199 ++ ) {
F_6 ( ( unsigned char ) V_758 [ 0 ] , ( V_3 -> V_365 + 1 ) ) ;
F_6 ( ( unsigned char ) V_758 [ 1 ] , ( V_3 -> V_365 + 1 ) ) ;
F_6 ( ( unsigned char ) V_758 [ 2 ] , ( V_3 -> V_365 + 1 ) ) ;
}
F_118 ( V_3 ) ;
F_118 ( V_3 ) ;
F_118 ( V_3 ) ;
F_93 ( 1 ) ;
F_66 ( V_3 ) ;
V_265 = F_10 ( V_3 -> V_211 ) ;
if ( V_265 & 0x10 )
F_14 ( V_3 -> V_215 , 0x32 , 0xDF , 0x20 ) ;
else
F_14 ( V_3 -> V_215 , 0x32 , 0xDF , 0x00 ) ;
F_6 ( 0x00 , V_3 -> V_365 ) ;
for ( V_199 = 0 ; V_199 < 256 ; V_199 ++ ) {
F_6 ( 0 , ( V_3 -> V_365 + 1 ) ) ;
F_6 ( 0 , ( V_3 -> V_365 + 1 ) ) ;
F_6 ( 0 , ( V_3 -> V_365 + 1 ) ) ;
}
F_4 ( V_3 -> V_203 , 0x01 , V_751 ) ;
F_4 ( V_3 -> V_215 , 0x63 , V_756 ) ;
F_4 ( V_3 -> V_203 , 0x31 , V_757 ) ;
F_4 ( V_3 -> V_215 , 0x53 , ( unsigned char ) ( F_8 (
V_3 -> V_215 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_203 , 0x1F , ( unsigned char ) V_752 ) ;
}
void F_123 ( struct V_212 * V_213 ,
struct V_2 * V_3 )
{
unsigned short V_197 ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
if ( ! ( V_3 -> V_249 & V_715 ) ) {
if ( V_3 -> V_249 & V_717 ) {
F_4 ( V_3 -> V_540 , 0x1E , 0x20 ) ;
} else {
if ( V_3 -> V_48 & V_580 ) {
F_4 ( V_3 -> V_540 ,
0x1E , 0x20 ) ;
}
}
}
if ( ! ( V_3 -> V_249 & V_716 ) ) {
if ( ( V_3 -> V_249 & V_718 ) || ( V_3 -> V_48
& ( V_207 | V_206
| V_236 ) ) ) {
V_197 = ( unsigned char ) F_8 (
V_3 -> V_203 , 0x32 ) ;
V_197 &= 0xDF ;
if ( V_3 -> V_48 & V_208 ) {
if ( ! ( V_3 -> V_48 &
V_236 ) )
V_197 |= 0x20 ;
}
F_4 ( V_3 -> V_203 , 0x32 , V_197 ) ;
F_22 ( V_3 -> V_203 , 0x1E , 0x20 ) ;
V_197 = ( unsigned char ) F_8 (
V_3 -> V_540 , 0x2E ) ;
if ( ! ( V_197 & 0x80 ) )
F_22 ( V_3 -> V_540 ,
0x2E , 0x80 ) ;
F_15 ( V_3 -> V_540 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_249 & ( V_717 | V_718 ) )
|| ( ! ( V_3 -> V_48 & V_581 ) ) ) {
F_14 ( V_3 -> V_566 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_147 & ( V_149 | V_238 ) ) {
if ( ! F_97 ( V_3 ) ) {
if ( F_98 ( V_3 ) ||
( V_3 -> V_48 &
( V_207 | V_205 ) ) )
F_15 (
V_3 -> V_547 ,
0x2A ,
0x7F ) ;
}
F_15 ( V_3 -> V_547 , 0x30 , 0x7F ) ;
}
}
V_197 = 0x00 ;
if ( ! ( V_3 -> V_48 & V_581 ) ) {
V_197 = 0xc0 ;
if ( ! ( V_3 -> V_48 & V_591 ) ) {
if ( V_3 -> V_48 & V_205 ) {
if ( V_3 -> V_48 &
V_580 ) {
V_197 = V_197 & 0x40 ;
if ( V_3 -> V_48 &
V_205 )
V_197 = V_197 ^ 0xC0 ;
if ( V_3 -> V_249 &
V_716 )
V_197 &= 0xBF ;
if ( V_3 -> V_249 &
V_715 )
V_197 &= 0x7F ;
if ( V_3 -> V_249 &
V_718 )
V_197 |= 0x40 ;
if ( V_3 -> V_249 &
V_717 )
V_197 |= 0x80 ;
}
}
}
}
F_22 ( V_3 -> V_547 , 0x1F , V_197 ) ;
if ( ! ( V_3 -> V_249 & V_715 ) ) {
F_118 ( V_3 ) ;
if ( ! ( V_3 -> V_249 & V_719 ) ) {
F_91 ( V_213 ,
V_3 ) ;
F_61 ( V_213 , V_3 ) ;
F_118 ( V_3 ) ;
}
}
}
else {
if ( V_3 -> V_48 & ( V_206 | V_207
| V_205 ) )
F_22 ( V_3 -> V_540 , 0x1E , 0x20 ) ;
V_197 = ( unsigned char ) F_8 ( V_3 -> V_540 ,
0x2E ) ;
if ( ! ( V_197 & 0x80 ) )
F_22 ( V_3 -> V_540 , 0x2E , 0x80 ) ;
F_15 ( V_3 -> V_540 , 0x00 , 0x7F ) ;
F_61 ( V_213 , V_3 ) ;
}
}
static void F_124 ( struct V_212 * V_213 ,
unsigned short V_191 , unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_196 , V_228 , V_285 , V_265 ;
unsigned short V_759 = V_3 -> V_287 ;
V_196 = F_2 ( V_191 , V_192 , V_3 ) ;
F_3 ( V_191 , V_196 , V_192 , V_3 ) ;
F_5 ( V_196 , V_3 ) ;
F_7 ( V_213 , V_196 , V_3 ) ;
F_9 ( V_191 , V_196 , V_192 , V_3 ) ;
F_11 ( V_196 , V_3 ) ;
F_12 ( V_3 ) ;
if ( V_213 -> V_270 == V_154 ) {
if ( V_3 -> V_235 == 0 )
F_13 ( V_3 ) ;
}
V_265 = ~ V_554 ;
V_3 -> V_249 &= V_265 ;
V_3 -> V_746 = 0 ;
if ( V_3 -> V_147 & ( V_256 | V_257 | V_148
| V_149 | V_238 ) ) {
if ( V_3 -> V_48 & ( V_591 | V_205
| V_208 ) ) {
V_3 -> V_249 |= V_554 ;
}
}
V_228 = F_119 ( V_213 , V_191 ,
V_192 , V_3 ) ;
if ( V_228 != 0xFFFF ) {
F_17 ( V_228 , V_3 ) ;
F_20 ( V_191 , V_192 , V_228 ,
V_3 , V_213 ) ;
F_27 ( V_213 , V_191 , V_192 ,
V_228 , V_3 ) ;
F_29 ( V_191 , V_192 , V_228 ,
V_213 , V_3 ) ;
F_31 ( V_191 , V_192 , V_213 ,
V_228 , V_3 ) ;
}
if ( ( V_213 -> V_270 >= V_163 ) &&
( V_213 -> V_270 < V_154 ) ) {
if ( ( V_191 == 0x00 ) | ( V_191 == 0x01 ) ) {
F_4 ( V_3 -> V_203 , 0x2B , 0x4E ) ;
F_4 ( V_3 -> V_203 , 0x2C , 0xE9 ) ;
V_285 = ( unsigned char ) F_10 ( V_759 ) ;
F_6 ( ( V_285 |= 0x0C ) , V_759 ) ;
} else if ( ( V_191 == 0x04 ) | ( V_191 == 0x05 ) | ( V_191
== 0x0D ) ) {
F_4 ( V_3 -> V_203 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_203 , 0x2C , 0xE3 ) ;
V_285 = ( unsigned char ) F_10 ( V_759 ) ;
F_6 ( ( V_285 |= 0x0C ) , V_759 ) ;
}
}
if ( V_213 -> V_270 >= V_153 ) {
V_265 = F_8 ( V_3 -> V_215 , 0x38 ) ;
if ( V_265 & 0xA0 ) {
if ( V_213 -> V_270 == V_154 )
F_23 ( V_191 , V_192 ,
V_228 , V_3 ) ;
else
F_21 ( V_191 , V_192 ,
V_228 , V_3 ) ;
F_26 ( V_191 , V_3 ,
V_228 ) ;
F_24 ( V_213 -> V_270 ,
V_3 , V_228 , V_191 ) ;
if ( V_3 -> V_235 == 1 )
F_95 ( V_213 -> V_270 ,
V_191 , V_192 , V_3 ) ;
}
}
V_3 -> V_249 &= ( ~ V_554 ) ;
F_32 ( V_191 , V_213 , V_3 ) ;
F_35 ( V_213 , V_191 , V_192 ,
V_228 , V_3 ) ;
F_37 ( V_191 , V_192 , V_3 ) ;
}
unsigned char F_125 ( struct V_212 * V_213 ,
unsigned short V_191 )
{
unsigned short V_192 ;
struct V_2 V_760 ;
struct V_2 * V_3 = & V_760 ;
V_3 -> V_761 = V_213 -> V_762 ;
V_3 -> V_763 = ( unsigned long ) V_213 -> V_764 ;
V_3 -> V_235 = 0 ;
V_3 -> V_582 = 1 ;
if ( V_213 -> V_270 >= V_163 ) {
V_3 -> V_586 = 0 ;
V_3 -> V_588 = 0 ;
V_3 -> V_593 = 0 ;
V_3 -> V_147 = 0 ;
} else {
V_3 -> V_586 = 1 ;
V_3 -> V_588 = 1 ;
V_3 -> V_593 = 1 ;
}
V_3 -> V_203 = V_3 -> V_763 + 0x14 ;
V_3 -> V_215 = V_3 -> V_763 + 0x24 ;
V_3 -> V_221 = V_3 -> V_763 + 0x10 ;
V_3 -> V_224 = V_3 -> V_763 + 0x1e ;
V_3 -> V_211 = V_3 -> V_763 + 0x12 ;
V_3 -> V_287 = V_3 -> V_763 + 0x1C ;
V_3 -> V_332 = V_3 -> V_763 + 0x1a ;
V_3 -> V_364 = V_3 -> V_763 + 0x16 ;
V_3 -> V_765 = V_3 -> V_763 + 0x17 ;
V_3 -> V_365 = V_3 -> V_763 + 0x18 ;
V_3 -> V_350 = V_3 -> V_763 + 0x19 ;
V_3 -> V_220 = V_3 -> V_763 + 0x2A ;
V_3 -> V_766 = V_3 -> V_763 + V_767 ;
V_3 -> V_540 = V_3 -> V_763 + V_768 ;
V_3 -> V_566 = V_3 -> V_763 + V_769 ;
V_3 -> V_678 = V_3 -> V_763 + V_770 ;
V_3 -> V_547 = V_3 -> V_763 + V_771 ;
V_3 -> V_683 = V_3 -> V_763 + V_771 + 2 ;
if ( V_213 -> V_270 == V_153 ) {
if ( ( F_8 ( V_3 -> V_215 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_235 = 1 ;
}
if ( V_213 -> V_270 == V_154 ) {
if ( ( F_8 ( V_3 -> V_215 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_8 ( V_3 -> V_215 , 0x30 ) & 0x20 )
V_3 -> V_235 = 1 ;
}
}
if ( V_213 -> V_270 < V_163 )
F_53 ( V_3 ) ;
F_1 ( V_213 -> V_270 , V_3 ) ;
if ( V_191 & 0x80 ) {
V_191 = V_191 & 0x7F ;
}
F_4 ( V_3 -> V_203 , 0x05 , 0x86 ) ;
if ( V_213 -> V_270 < V_163 )
F_115 ( V_213 , V_3 ) ;
F_57 ( V_191 , & V_192 , V_3 ) ;
F_52 ( V_213 , V_3 ) ;
if ( V_213 -> V_270 < V_163 ) {
F_54 ( V_191 , V_192 , V_213 , V_3 ) ;
F_55 ( V_191 , V_192 , V_3 ) ;
F_56 ( V_191 , V_192 , V_3 ) ;
F_99 ( V_213 , V_3 ) ;
if ( V_3 -> V_48 & ( V_591 | V_205 ) ) {
F_124 ( V_213 , V_191 ,
V_192 , V_3 ) ;
if ( V_3 -> V_48 & V_205 ) {
F_120 ( V_191 , V_192 ,
V_213 , V_3 ) ;
}
} else {
if ( ! ( V_3 -> V_48 & V_592 ) ) {
F_124 ( V_213 , V_191 ,
V_192 , V_3 ) ;
if ( V_3 -> V_48 & V_205 ) {
F_120 ( V_191 , V_192 ,
V_213 ,
V_3 ) ;
}
}
}
if ( V_3 -> V_48 & ( V_591 | V_592 ) ) {
switch ( V_213 -> V_772 ) {
case V_773 :
F_121 ( V_191 , V_213 ,
V_3 ) ;
break;
case V_774 :
F_121 ( V_191 , V_213 ,
V_3 ) ;
break;
default:
break;
}
}
F_113 ( V_191 , V_213 , V_3 ) ;
F_112 ( V_191 , V_192 , V_3 ) ;
F_114 ( V_213 , V_3 ) ;
F_123 ( V_213 , V_3 ) ;
}
else {
if ( V_3 -> V_235 == 1 )
if ( ! F_94 ( V_191 ,
V_192 ,
V_3 ) )
return 0 ;
if ( V_191 <= 0x13 ) {
V_3 -> V_195 = V_3 -> V_4 [ V_192 ] .
V_201 & V_579 ;
} else {
V_3 -> V_195 = V_3 -> V_10 [ V_192 ] .
V_202 & V_579 ;
}
V_3 -> V_249 = 0 ;
V_3 -> V_48 = V_581 ;
F_65 ( V_213 , V_3 ) ;
F_124 ( V_213 , V_191 , V_192 ,
V_3 ) ;
F_61 ( V_213 , V_3 ) ;
}
F_51 ( V_213 , V_3 ) ;
if ( V_213 -> V_270 < V_163 ) {
F_116 ( V_213 , V_3 ) ;
}
return 1 ;
}
