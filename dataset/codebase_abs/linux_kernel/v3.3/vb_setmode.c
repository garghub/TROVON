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
V_3 -> V_153 = V_154 ;
V_3 -> V_155 = V_156 ;
V_3 -> V_157 = & V_158 ;
if ( V_1 >= V_159 )
V_3 -> V_160 = & V_161 ;
if ( V_1 == V_162 ) {
V_3 -> V_19
= (struct V_20 * ) V_163 ;
V_3 -> V_52 = V_164 ;
V_3 -> V_160 = & V_165 ;
V_3 -> V_166 = & V_167 ;
V_3 -> V_168 = & V_169 ;
V_3 -> V_170 = V_171 ;
V_3 -> V_172 = V_173 ;
V_3 -> V_174 = & V_175 ;
V_3 -> V_176 = & V_177 ;
}
if ( V_1 >= V_159 ) {
V_3 -> V_178 = & V_179 ;
V_3 -> V_180 = & V_181 ;
V_3 -> V_182 = & V_183 ;
V_3 -> V_184 = & V_185 ;
V_3 -> V_186 = & V_187 ;
}
}
static unsigned char F_2 ( unsigned short V_188 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned char V_190 ;
if ( V_188 <= 0x13 )
V_190 = V_3 -> V_4 [ V_189 ] . V_191 ;
else {
if ( V_3 -> V_192 <= 0x02 )
V_190 = 0x1B ;
else
V_190 = 0x0F ;
}
return V_190 ;
}
static void F_3 ( unsigned short V_188 ,
unsigned short V_193 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned char V_194 , V_195 ;
unsigned short V_196 , V_197 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
F_4 ( V_3 -> V_200 , 0x00 , 0x03 ) ;
V_194 = V_3 -> V_7 [ V_193 ] . V_201 [ 0 ] ;
V_196 = V_202 ;
if ( V_3 -> V_48 & V_202 ) {
V_194 |= 0x01 ;
} else {
if ( V_3 -> V_48 & ( V_203 | V_204 ) ) {
if ( V_3 -> V_48 & V_205 )
V_194 |= 0x01 ;
}
}
V_194 |= 0x20 ;
F_4 ( V_3 -> V_200 , 0x01 , V_194 ) ;
for ( V_196 = 02 ; V_196 <= 04 ; V_196 ++ ) {
V_195 = V_3 -> V_7 [ V_193 ] . V_201 [ V_196 - 1 ] ;
F_4 ( V_3 -> V_200 , V_196 , V_195 ) ;
}
}
static void F_5 ( struct V_206 * V_207 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned char V_208 ;
unsigned short V_196 ;
V_208 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x11 ) ;
V_208 &= 0x7f ;
F_4 ( V_3 -> V_209 , 0x11 , V_208 ) ;
for ( V_196 = 0 ; V_196 <= 0x18 ; V_196 ++ ) {
V_208 = V_3 -> V_7 [ V_193 ] . V_210 [ V_196 ] ;
F_4 ( V_3 -> V_209 , V_196 , V_208 ) ;
}
}
static void F_7 ( unsigned short V_188 ,
unsigned short V_193 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned char V_211 ;
unsigned short V_196 , V_197 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
for ( V_196 = 0 ; V_196 <= 0x13 ; V_196 ++ ) {
V_211 = V_3 -> V_7 [ V_193 ] . V_212 [ V_196 ] ;
if ( V_197 & V_213 ) {
if ( V_196 == 0x13 ) {
if ( V_3 -> V_48 & V_202 ) {
V_211 = 0 ;
} else {
if ( V_3 -> V_48 & ( V_203
| V_204 ) ) {
if ( V_3 -> V_48 &
V_205 )
V_211 = 0 ;
}
}
}
}
F_8 ( V_3 -> V_214 ) ;
F_9 ( V_196 , V_3 -> V_215 ) ;
F_9 ( V_211 , V_3 -> V_215 ) ;
}
F_8 ( V_3 -> V_214 ) ;
F_9 ( 0x14 , V_3 -> V_215 ) ;
F_9 ( 0x00 , V_3 -> V_215 ) ;
F_8 ( V_3 -> V_214 ) ;
F_9 ( 0x20 , V_3 -> V_215 ) ;
}
static void F_10 ( unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned char V_216 ;
unsigned short V_196 ;
for ( V_196 = 0 ; V_196 <= 0x08 ; V_196 ++ ) {
V_216 = V_3 -> V_7 [ V_193 ] . V_217 [ V_196 ] ;
F_4 ( V_3 -> V_218 , V_196 , V_216 ) ;
}
if ( V_3 -> V_192 > V_219 ) {
V_216 = ( unsigned char ) F_6 ( V_3 -> V_218 , 0x05 ) ;
V_216 &= 0xBF ;
F_4 ( V_3 -> V_218 , 0x05 , V_216 ) ;
}
}
static void F_11 ( struct V_2 * V_3 )
{
unsigned short V_196 ;
for ( V_196 = 0x0A ; V_196 <= 0x0E ; V_196 ++ )
F_4 ( V_3 -> V_200 , V_196 , 0x00 ) ;
}
static unsigned char F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 -> V_200 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_200 , 0x2B , V_3 -> V_25 [ 0 ] . V_220 ) ;
F_4 ( V_3 -> V_200 , 0x2C , V_3 -> V_25 [ 0 ] . V_221 ) ;
F_13 ( V_3 -> V_200 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_200 , 0x2B , V_3 -> V_25 [ 1 ] . V_220 ) ;
F_4 ( V_3 -> V_200 , 0x2C , V_3 -> V_25 [ 1 ] . V_221 ) ;
F_14 ( V_3 -> V_200 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_15 ( unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 , unsigned short * V_196 ,
struct V_2 * V_3 )
{
unsigned short V_223 , V_224 , V_225 , V_197 , V_226 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
V_224 = V_3 -> V_13 [ V_222 + ( * V_196 ) ] . V_228 ;
V_223 = 0 ;
if ( V_3 -> V_229 == 0 ) {
if ( V_3 -> V_48 & V_230 ) {
V_223 |= V_231 ;
if ( V_3 -> V_147 & V_232 )
V_223 |= V_233 ;
}
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
V_223 |= V_234 ;
if ( V_3 -> V_45 != V_235 ) {
if ( V_3 -> V_45 != V_236 ) {
if ( V_3 -> V_47 &
V_237 ) {
if ( V_225 >= 9 ) {
V_223 = 0 ;
return 0 ;
}
}
}
}
}
if ( V_3 -> V_48 & V_238 ) {
if ( ( V_3 -> V_147 & V_148 ) &&
( V_3 -> V_239 == V_240 ) ) {
V_223 |= V_241 ;
if ( V_3 -> V_48 & V_205 ) {
if ( V_225 == 4 )
return 0 ;
if ( V_225 == 3 )
return 0 ;
if ( V_225 > 7 )
return 0 ;
}
} else {
V_223 |= V_242 ;
if ( V_3 -> V_48 & V_205 ) {
if ( V_225 == 4 )
return 0 ;
if ( V_225 == 3 ) {
if ( V_3 -> V_243
& V_244 )
return 0 ;
}
if ( V_225 > 7 )
return 0 ;
}
}
} else {
if ( V_3 -> V_48 & ( V_245 |
V_246 |
V_247 |
V_248 |
V_238 ) ) {
V_223 |= V_249 ;
if ( V_3 -> V_147 & ( V_250 | V_251
| V_148 | V_149
| V_232 ) ) {
V_223 |= V_252 ;
}
if ( ! ( V_3 -> V_48 & V_253 ) ) {
if ( V_197 & V_254 ) {
if ( V_3 -> V_48 &
V_205 ) {
if ( ! ( V_3 -> V_48 &
V_255 ) ) {
return 0 ;
}
}
}
}
}
}
} else {
if ( V_3 -> V_48 & V_204 ) {
V_223 |= V_234 ;
if ( V_225 > 0x08 )
return 0 ;
if ( V_3 -> V_45 < V_256 ) {
if ( V_225 > 0x07 )
return 0 ;
if ( V_225 == 0x04 )
return 0 ;
}
}
}
for (; V_3 -> V_13 [ V_222 + ( * V_196 ) ] . V_228 ==
V_224 ; ( * V_196 ) -- ) {
V_226 = V_3 -> V_13 [ V_222 + ( * V_196 ) ] .
V_257 ;
if ( V_226 & V_223 )
return 1 ;
if ( ( * V_196 ) == 0 )
break;
}
for ( ( * V_196 ) = 0 ; ; ( * V_196 ) ++ ) {
V_226 = V_3 -> V_13 [ V_222 + ( * V_196 ) ] .
V_257 ;
if ( V_3 -> V_13 [ V_222 + ( * V_196 ) ] . V_228
!= V_224 ) {
return 0 ;
}
if ( V_226 & V_223 )
return 1 ;
}
return 1 ;
}
static void F_16 ( unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_258 , V_259 ;
V_258 = V_3 -> V_13 [ V_222 ] . V_257 >> 8 ;
V_258 &= 0xC0 ;
V_259 = 0x2F ;
V_259 |= V_258 ;
F_9 ( V_259 , V_3 -> V_260 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_206 * V_207 )
{
unsigned char V_261 , V_262 , V_263 ;
unsigned short V_196 , V_264 ;
V_261 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x11 ) ;
V_261 &= 0x7F ;
F_4 ( V_3 -> V_209 , 0x11 , V_261 ) ;
V_261 = V_3 -> V_138 [ 0 ] . V_261 [ 0 ] ;
F_4 ( V_3 -> V_209 , 0 , V_261 ) ;
for ( V_196 = 0x01 ; V_196 <= 0x04 ; V_196 ++ ) {
V_261 = V_3 -> V_138 [ 0 ] . V_261 [ V_196 ] ;
F_4 ( V_3 -> V_209 , ( unsigned short ) ( V_196 + 1 ) , V_261 ) ;
}
for ( V_196 = 0x05 ; V_196 <= 0x06 ; V_196 ++ ) {
V_261 = V_3 -> V_138 [ 0 ] . V_261 [ V_196 ] ;
F_4 ( V_3 -> V_200 , ( unsigned short ) ( V_196 + 6 ) , V_261 ) ;
}
V_264 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x0e ) ;
V_264 &= 0x1F ;
V_261 = V_3 -> V_138 [ 0 ] . V_261 [ 7 ] ;
V_261 &= 0xE0 ;
V_261 |= V_264 ;
F_4 ( V_3 -> V_200 , 0x0e , V_261 ) ;
if ( V_207 -> V_265 >= V_159 ) {
V_261 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x04 ) ;
V_261 = V_261 - 1 ;
F_4 ( V_3 -> V_209 , 0x04 , V_261 ) ;
V_261 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x05 ) ;
V_262 = V_261 ;
V_262 &= 0xE0 ;
V_261 &= 0x1F ;
if ( V_261 == 0 ) {
V_263 = V_261 ;
V_261 = ( unsigned char ) F_6 ( V_3 -> V_200 ,
0x0c ) ;
V_261 &= 0xFB ;
F_4 ( V_3 -> V_200 , 0x0c , V_261 ) ;
V_261 = V_263 ;
}
V_261 = V_261 - 1 ;
V_261 |= V_262 ;
F_4 ( V_3 -> V_209 , 0x05 , V_261 ) ;
V_261 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x0e ) ;
V_261 = V_261 >> 5 ;
V_261 = V_261 + 3 ;
if ( V_261 > 7 )
V_261 = V_261 - 7 ;
V_261 = V_261 << 5 ;
F_13 ( V_3 -> V_200 , 0x0e , ~ 0xE0 , V_261 ) ;
}
}
static void F_18 ( unsigned short V_189 ,
unsigned short V_188 ,
struct V_2 * V_3 )
{
unsigned char V_261 ;
unsigned short V_196 , V_264 ;
for ( V_196 = 0x00 ; V_196 <= 0x01 ; V_196 ++ ) {
V_261 = V_3 -> V_141 [ 0 ] . V_261 [ V_196 ] ;
F_4 ( V_3 -> V_209 , ( unsigned short ) ( V_196 + 6 ) , V_261 ) ;
}
for ( V_196 = 0x02 ; V_196 <= 0x03 ; V_196 ++ ) {
V_261 = V_3 -> V_141 [ 0 ] . V_261 [ V_196 ] ;
F_4 ( V_3 -> V_209 , ( unsigned short ) ( V_196 + 0x0e ) , V_261 ) ;
}
for ( V_196 = 0x04 ; V_196 <= 0x05 ; V_196 ++ ) {
V_261 = V_3 -> V_141 [ 0 ] . V_261 [ V_196 ] ;
F_4 ( V_3 -> V_209 , ( unsigned short ) ( V_196 + 0x11 ) , V_261 ) ;
}
V_264 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x0a ) ;
V_264 &= 0xC0 ;
V_261 = V_3 -> V_141 [ 0 ] . V_261 [ 6 ] ;
V_261 &= 0x3F ;
V_261 |= V_264 ;
F_4 ( V_3 -> V_200 , 0x0a , V_261 ) ;
V_261 = V_3 -> V_141 [ 0 ] . V_261 [ 6 ] ;
V_261 &= 0x80 ;
V_261 = V_261 >> 2 ;
if ( V_188 <= 0x13 )
V_196 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_196 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_196 &= V_266 ;
if ( V_196 )
V_261 |= 0x80 ;
V_264 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x09 ) ;
V_264 &= 0x5F ;
V_261 |= V_264 ;
F_4 ( V_3 -> V_209 , 0x09 , V_261 ) ;
}
static void F_19 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 ,
struct V_206 * V_207 )
{
unsigned char V_190 , V_261 ;
unsigned short V_196 ;
V_190 = V_3 -> V_13 [ V_222 ] . V_267 ;
V_190 = V_190 & V_268 ;
V_261 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x11 ) ;
V_261 &= 0x7F ;
F_4 ( V_3 -> V_209 , 0x11 , V_261 ) ;
for ( V_196 = 0 ; V_196 < 8 ; V_196 ++ )
V_3 -> V_138 [ 0 ] . V_261 [ V_196 ]
= V_3 -> V_16 [ V_190 ] . V_269 [ V_196 ] ;
for ( V_196 = 0 ; V_196 < 7 ; V_196 ++ )
V_3 -> V_141 [ 0 ] . V_261 [ V_196 ]
= V_3 -> V_16 [ V_190 ] . V_269 [ V_196 + 8 ] ;
F_17 ( V_3 , V_207 ) ;
F_18 ( V_189 , V_188 , V_3 ) ;
if ( V_3 -> V_192 > 0x03 )
F_4 ( V_3 -> V_209 , 0x14 , 0x4F ) ;
}
static void F_20 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned char V_193 , V_190 , V_270 , V_271 , V_272 , V_273 ;
unsigned short V_274 , V_275 , V_276 ;
if ( V_188 <= 0x13 ) {
V_193 = F_2 ( V_188 , V_189 , V_3 ) ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 4 ] ;
F_4 ( V_3 -> V_200 , 0x2E , V_270 ) ;
V_271 = V_3 -> V_7 [ V_193 ] . V_210 [ 5 ] ;
V_271 &= 0x1F ;
V_272 = V_270 ;
V_272 &= 0xE0 ;
V_273 = V_272 | V_271 ;
if ( V_271 < ( V_270 & 0x1F ) )
V_273 |= 0x20 ;
V_273 <<= 2 ;
F_4 ( V_3 -> V_200 , 0x2F , V_273 ) ;
F_13 ( V_3 -> V_200 , 0x30 , 0xE3 , 00 ) ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 16 ] ;
V_271 = V_270 ;
V_270 &= 0x01 ;
F_21 ( V_3 -> V_200 , 0x33 , V_270 ) ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 7 ] ;
V_273 = V_271 >> 1 ;
V_272 = V_270 & 0x04 ;
V_272 <<= 5 ;
V_273 |= V_272 ;
F_4 ( V_3 -> V_200 , 0x34 , V_273 ) ;
V_274 = V_272 << 1 ;
V_274 |= V_271 ;
V_270 &= 0x80 ;
V_275 = V_270 << 2 ;
V_274 |= V_275 ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 17 ] ;
V_270 &= 0x0F ;
V_275 = V_274 & 0x3F0 ;
V_275 |= V_270 ;
V_276 = V_274 & 0x0F ;
if ( V_270 < V_276 )
V_275 |= 0x10 ;
V_275 &= 0xFF ;
V_270 = ( unsigned char ) V_275 ;
V_270 <<= 2 ;
V_274 &= 0x600 ;
V_274 >>= 9 ;
V_271 = ( unsigned char ) V_274 ;
V_270 |= V_271 ;
V_270 &= 0x7F ;
F_4 ( V_3 -> V_200 , 0x3F , V_270 ) ;
} else {
V_190 = V_3 -> V_13 [ V_222 ] . V_267 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 3 ] ;
V_272 = V_270 ;
F_4 ( V_3 -> V_200 , 0x2E , V_270 ) ;
V_273 = V_3 -> V_16 [ V_190 ] . V_269 [ 5 ] ;
V_273 &= 0xC0 ;
V_274 = V_273 ;
V_274 <<= 2 ;
V_274 |= V_270 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 4 ] ;
V_270 &= 0x1F ;
V_271 = V_3 -> V_16 [ V_190 ] . V_269 [ 6 ] ;
V_271 &= 0x04 ;
V_271 <<= 3 ;
V_270 |= V_271 ;
V_275 = V_274 & 0x3C0 ;
V_275 |= V_270 ;
V_272 &= 0x3F ;
if ( V_270 < V_272 )
V_275 |= 0x40 ;
V_275 &= 0xFF ;
V_270 = ( unsigned char ) V_275 ;
V_270 <<= 2 ;
V_273 >>= 6 ;
V_270 |= V_273 ;
F_4 ( V_3 -> V_200 , 0x2F , V_270 ) ;
F_13 ( V_3 -> V_200 , 0x30 , 0xE3 , 00 ) ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 10 ] ;
V_271 = V_270 ;
V_270 &= 0x01 ;
F_21 ( V_3 -> V_200 , 0x33 , V_270 ) ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 9 ] ;
V_272 = V_271 >> 1 ;
V_273 = V_270 & 0x04 ;
V_273 <<= 5 ;
V_272 |= V_273 ;
F_4 ( V_3 -> V_200 , 0x34 , V_272 ) ;
V_274 = V_273 ;
V_274 <<= 1 ;
V_274 |= V_271 ;
V_270 &= 0x80 ;
V_275 = V_270 << 2 ;
V_274 |= V_275 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 14 ] ;
V_270 &= 0x08 ;
V_275 = V_270 ;
V_275 <<= 7 ;
V_274 |= V_275 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 11 ] ;
V_270 &= 0x0F ;
V_271 = V_3 -> V_16 [ V_190 ] . V_269 [ 14 ] ;
V_271 &= 0x20 ;
V_271 >>= 1 ;
V_270 |= V_271 ;
V_275 = V_274 & 0x7E0 ;
V_275 |= V_270 ;
V_276 = V_274 & 0x1F ;
if ( V_270 < V_276 )
V_275 |= 0x20 ;
V_275 &= 0xFF ;
V_270 = ( unsigned char ) V_275 ;
V_270 <<= 2 ;
V_274 &= 0x600 ;
V_274 >>= 9 ;
V_271 = ( unsigned char ) V_274 ;
V_270 |= V_271 ;
V_270 &= 0x7F ;
F_4 ( V_3 -> V_200 , 0x3F , V_270 ) ;
}
}
static void F_22 ( unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_193 , V_190 , V_270 , V_271 , V_272 , V_273 ;
if ( V_188 <= 0x13 ) {
V_193 = F_2 ( V_188 , V_189 , V_3 ) ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 4 ] ;
F_4 ( V_3 -> V_200 , 0x2E , V_270 ) ;
V_271 = V_3 -> V_7 [ V_193 ] . V_210 [ 5 ] ;
V_271 &= 0x1F ;
V_272 = V_270 ;
V_272 &= 0xE0 ;
V_273 = V_272 | V_271 ;
if ( V_271 < ( V_270 & 0x1F ) )
V_273 |= 0x20 ;
V_273 <<= 2 ;
F_4 ( V_3 -> V_200 , 0x2F , V_273 ) ;
F_13 ( V_3 -> V_200 , 0x30 , 0xE3 , 00 ) ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 16 ] ;
F_4 ( V_3 -> V_200 , 0x34 , V_270 ) ;
V_272 = V_270 ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 7 ] ;
V_271 = V_270 ;
V_270 &= 0x04 ;
V_270 >>= 2 ;
F_13 ( V_3 -> V_200 , 0x35 , ~ 0x01 , V_270 ) ;
V_272 |= ( V_270 << 8 ) ;
V_272 |= ( V_271 & 0x80 ) << 2 ;
V_270 = V_3 -> V_7 [ V_193 ] . V_210 [ 17 ] ;
V_270 &= 0x0F ;
V_271 = V_272 ;
V_271 &= 0x3F0 ;
V_271 |= V_270 ;
if ( V_270 <= ( V_272 & 0x0F ) )
V_271 |= 0x10 ;
V_270 = ( unsigned char ) V_271 & 0xFF ;
V_270 <<= 2 ;
V_272 = ( V_272 & 0x600 ) >> 8 ;
F_13 ( V_3 -> V_200 , 0x3F , ~ 0xFC , V_270 ) ;
F_13 ( V_3 -> V_200 , 0x35 , ~ 0x06 , V_272 ) ;
} else {
V_190 = V_3 -> V_13 [ V_222 ] . V_267 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 3 ] ;
V_271 = V_270 ;
F_4 ( V_3 -> V_200 , 0x2E , V_270 ) ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 5 ] ;
V_270 &= 0xC0 ;
V_271 |= ( V_270 << 2 ) ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 4 ] ;
V_270 &= 0x1F ;
V_272 = V_270 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 6 ] ;
V_270 &= 0x04 ;
V_270 <<= 3 ;
V_272 |= V_270 ;
V_271 = V_271 & 0x3C0 ;
V_271 |= V_272 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 3 ] ;
V_270 &= 0x3F ;
if ( V_272 <= V_270 )
V_271 += 0x40 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 5 ] ;
V_270 &= 0xC0 ;
V_270 >>= 6 ;
V_270 |= ( ( V_271 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_200 , 0x2F , V_270 ) ;
F_13 ( V_3 -> V_200 , 0x30 , 0xE3 , 00 ) ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 10 ] ;
F_4 ( V_3 -> V_200 , 0x34 , V_270 ) ;
V_272 = V_270 ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 9 ] ;
V_271 = V_270 ;
V_270 = V_270 & 0x04 ;
V_270 >>= 2 ;
F_13 ( V_3 -> V_200 , 0x35 , ~ 0x01 , V_270 ) ;
V_272 |= ( V_270 << 8 ) ;
V_272 |= ( ( V_271 & 0x80 ) << 2 ) ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 14 ] ;
V_270 &= 0x08 ;
V_272 |= ( V_270 << 7 ) ;
V_270 = V_3 -> V_16 [ V_190 ] . V_269 [ 11 ] ;
V_270 &= 0x0F ;
V_271 = V_3 -> V_16 [ V_190 ] . V_269 [ 14 ] ;
V_271 &= 0x20 ;
V_271 >>= 1 ;
V_270 |= V_271 ;
V_271 = V_272 ;
V_271 &= 0x7E0 ;
V_271 |= V_270 ;
if ( V_271 <= V_272 )
V_271 |= 0x20 ;
V_270 = ( V_271 << 2 ) & 0xFF ;
F_13 ( V_3 -> V_200 , 0x3F , ~ 0xFC , V_270 ) ;
V_270 = V_272 >> 8 ;
F_13 ( V_3 -> V_200 , 0x35 , ~ 0x07 , V_270 ) ;
}
}
static void F_23 ( struct V_2 * V_3 )
{
unsigned char V_259 ;
V_259 = F_6 ( V_3 -> V_209 , 0x37 ) ;
V_259 = ( V_259 & 3 ) << 6 ;
F_13 ( V_3 -> V_200 , 0x06 , ~ 0xc0 , V_259 & 0x80 ) ;
F_13 ( V_3 -> V_200 , 0x09 , ~ 0xc0 , V_259 | 0x80 ) ;
}
static void F_24 ( int V_277 ,
struct V_2 * V_3 ,
unsigned short V_222 ,
unsigned short V_188 )
{
unsigned short V_278 , V_279 , V_280 ;
unsigned short V_281 ;
V_281 = V_3 -> V_282 ;
F_4 ( V_3 -> V_209 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_209 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_209 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_209 , 0x47 , 0x00 ) ;
if ( V_277 == V_162 ) {
V_279 = F_6 ( V_3 -> V_209 , 0x37 ) ;
if ( ( V_279 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_209 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_209 , 0x47 , 0x13 ) ;
}
}
if ( ( ( * V_3 -> V_178 ) & 0xC0 ) == 0xC0 ) {
F_4 ( V_3 -> V_209 , 0x2E , * V_3 -> V_180 ) ;
F_4 ( V_3 -> V_209 , 0x2F , * V_3 -> V_182 ) ;
F_4 ( V_3 -> V_209 , 0x46 , * V_3 -> V_184 ) ;
F_4 ( V_3 -> V_209 , 0x47 , * V_3 -> V_186 ) ;
}
if ( V_277 == V_162 ) {
F_23 ( V_3 ) ;
} else {
V_279 = F_6 ( V_3 -> V_209 , 0x37 ) ;
if ( V_279 & 0x01 ) {
F_21 ( V_3 -> V_200 , 0x06 , 0x40 ) ;
F_21 ( V_3 -> V_200 , 0x09 , 0x40 ) ;
}
}
F_21 ( V_3 -> V_200 , 0x1E , 0x01 ) ;
F_14 ( V_3 -> V_200 , 0x30 , ~ 0x20 ) ;
F_14 ( V_3 -> V_200 , 0x35 , ~ 0x80 ) ;
if ( V_188 <= 0x13 ) {
V_280 = ( unsigned char ) F_8 ( V_281 ) ;
if ( V_280 & 0x40 )
F_21 ( V_3 -> V_200 , 0x30 , 0x20 ) ;
if ( V_280 & 0x80 )
F_21 ( V_3 -> V_200 , 0x35 , 0x80 ) ;
} else {
V_278 = V_3 -> V_13 [ V_222 ] . V_257 ;
if ( V_278 & 0x4000 )
F_21 ( V_3 -> V_200 , 0x30 , 0x20 ) ;
if ( V_278 & 0x8000 )
F_21 ( V_3 -> V_200 , 0x35 , 0x80 ) ;
}
}
static void F_25 ( unsigned short V_188 ,
struct V_2 * V_3 ,
unsigned short V_222 )
{
int V_196 , V_190 = - 1 ;
F_14 ( V_3 -> V_209 , 0x11 , 0x7F ) ;
if ( V_188 <= 0x13 ) {
for ( V_196 = 0 ; V_196 < 12 ; V_196 ++ ) {
if ( V_188 == V_3 -> V_144 [ V_196 ] . V_228 )
V_190 = V_196 ;
}
} else {
if ( V_188 == 0x2E &&
( V_3 -> V_13 [ V_222 ] . V_267 ==
V_283 ) )
V_190 = 12 ;
else if ( V_188 == 0x2E &&
( V_3 -> V_13 [ V_222 ] .
V_267 == V_284 ) )
V_190 = 13 ;
else if ( V_188 == 0x2F )
V_190 = 14 ;
else if ( V_188 == 0x50 )
V_190 = 15 ;
else if ( V_188 == 0x59 )
V_190 = 16 ;
}
if ( V_190 != - 1 ) {
F_4 ( V_3 -> V_209 , 0x02 ,
V_3 -> V_144 [ V_190 ] . V_285 ) ;
F_4 ( V_3 -> V_209 , 0x03 ,
V_3 -> V_144 [ V_190 ] . V_286 ) ;
F_4 ( V_3 -> V_209 , 0x15 ,
V_3 -> V_144 [ V_190 ] . V_287 ) ;
F_4 ( V_3 -> V_209 , 0x16 ,
V_3 -> V_144 [ V_190 ] . V_288 ) ;
}
}
static unsigned short F_26 ( unsigned short V_188 ,
unsigned short V_189 , struct V_2 * V_3 )
{
unsigned short V_289 ;
if ( V_188 <= 0x13 )
V_289 = V_3 -> V_4 [ V_189 ] . V_290 ;
else
V_289 = V_3 -> V_10 [ V_189 ] . V_227 ;
return V_289 ;
}
static void F_27 ( struct V_206 * V_207 ,
unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_289 , V_223 , V_224 , V_291 , V_259 , V_197 ;
unsigned char V_261 ;
V_289 = F_26 ( V_188 , V_189 , V_3 ) ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_223 = V_3 -> V_33 [ V_289 ] . V_292 ;
V_224 = V_3 -> V_33 [ V_289 ] . V_293 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_223 = V_3 -> V_36 [ V_289 ] . V_292 ;
V_224 = V_3 -> V_36 [ V_289 ] . V_293 ;
}
if ( V_197 & V_294 )
V_223 = V_223 >> 1 ;
if ( V_188 > 0x13 ) {
if ( V_197 & V_294 )
V_223 = V_223 << 1 ;
V_259 = V_3 -> V_13 [ V_222 ] . V_257 ;
if ( V_259 & V_295 )
V_224 = V_224 >> 1 ;
if ( V_197 & V_266 )
V_224 = V_224 << 1 ;
}
V_291 = 8 ;
V_223 /= V_291 ;
V_223 -= 1 ;
V_224 -= 1 ;
V_291 = V_223 ;
V_259 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x11 ) ;
V_261 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x11 ) ;
V_261 &= 0x7F ;
F_4 ( V_3 -> V_209 , 0x11 , V_261 ) ;
F_4 ( V_3 -> V_209 , 0x01 , ( unsigned short ) ( V_291 & 0xff ) ) ;
F_13 ( V_3 -> V_209 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_291 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_209 , 0x12 , ( unsigned short ) ( V_224 & 0xff ) ) ;
V_223 = 0 ;
V_224 = V_224 >> 8 ;
if ( V_224 & 0x01 )
V_223 |= 0x02 ;
if ( V_224 & 0x02 )
V_223 |= 0x40 ;
F_13 ( V_3 -> V_209 , 0x07 , ~ 0x42 , V_223 ) ;
V_261 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x07 ) ;
V_261 &= 0xFF ;
V_223 = 0 ;
if ( V_224 & 0x04 )
V_223 |= 0x02 ;
F_13 ( V_3 -> V_209 , 0x0a , ~ 0x02 , V_223 ) ;
F_4 ( V_3 -> V_209 , 0x11 , V_259 ) ;
}
static void F_28 ( unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_259 , V_296 , V_297 , V_298 , V_196 , V_299 ;
V_259 = V_3 -> V_10 [ V_189 ] . V_300 ;
V_259 = V_259 >> 8 ;
V_259 = V_3 -> V_31 [ V_259 ] ;
V_298 = V_3 -> V_13 [ V_222 ] . V_257 ;
V_298 &= V_295 ;
if ( V_298 )
V_259 = V_259 << 1 ;
V_298 = V_3 -> V_192 - V_301 ;
switch ( V_298 ) {
case 0 :
V_298 = 1 ;
break;
case 1 :
V_298 = 2 ;
break;
case 2 :
V_298 = 4 ;
break;
case 3 :
V_298 = 4 ;
break;
case 4 :
V_298 = 6 ;
break;
case 5 :
V_298 = 8 ;
break;
default:
break;
}
if ( ( V_188 >= 0x26 ) && ( V_188 <= 0x28 ) )
V_259 = V_259 * V_298 + V_298 / 2 ;
else
V_259 *= V_298 ;
V_299 = V_259 ;
V_298 = V_259 ;
V_259 = V_259 >> 8 ;
V_259 &= 0x0F ;
V_196 = F_6 ( V_3 -> V_200 , 0x0E ) ;
V_196 &= 0xF0 ;
V_196 |= V_259 ;
F_4 ( V_3 -> V_200 , 0x0E , V_196 ) ;
V_259 = ( unsigned char ) V_298 ;
V_259 &= 0xFF ;
F_4 ( V_3 -> V_209 , 0x13 , V_259 ) ;
V_298 = V_3 -> V_13 [ V_222 ] . V_257 ;
V_298 &= V_295 ;
if ( V_298 )
V_299 >>= 1 ;
V_299 = V_299 << 5 ;
V_296 = ( V_299 & 0xff00 ) >> 8 ;
V_297 = V_299 & 0x00ff ;
if ( V_297 == 0 )
V_296 += 1 ;
else
V_296 += 2 ;
if ( V_207 -> V_265 >= V_159 )
if ( ( V_188 == 0x4A ) | ( V_188 == 0x49 ) )
V_296 -= 1 ;
F_4 ( V_3 -> V_200 , 0x10 , V_296 ) ;
}
static unsigned short F_29 ( unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_302 [ 4 ] = { V_303 + 2 ,
V_303 + 2 ,
V_303 + 2 ,
V_303 + 2 } ;
unsigned short V_304 [ 4 ] = { V_305 + 5 ,
V_305 + 5 ,
V_305 + 5 ,
V_305 + 5 } ;
unsigned short V_306 [ 4 ] = { V_307 , V_307 , V_307 , V_307 } ;
unsigned short V_308 [ 4 ] = { V_303 + 2 ,
V_303 + 2 ,
V_303 + 2 ,
V_303 + 2 } ;
unsigned short V_309 [ 4 ] = { V_303 + 2 ,
V_303 + 2 ,
V_303 + 2 ,
V_303 + 2 } ;
unsigned short V_310 , V_311 ;
unsigned short V_197 , V_225 ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_225 = V_3 -> V_4 [ V_189 ] . V_290 ;
V_310 = V_3 -> V_4 [ V_189 ] . V_312 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
V_310 = V_3 -> V_13 [ V_222 ] .
V_313 ;
}
if ( V_3 -> V_229 == 0 ) {
V_310 = V_310 >> 6 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
if ( V_3 -> V_45 != V_256 )
V_311 = V_304 [ V_310 ] ;
else
V_311 = V_302 [ V_310 ] ;
} else if ( V_3 -> V_48 & V_238 ) {
if ( V_3 -> V_243 & V_314 ) {
V_311 = V_315 ;
V_311 += 25 ;
} else {
V_311 = V_316 ;
V_311 += 25 ;
}
if ( V_3 -> V_243 & V_244 ) {
if ( V_197 & V_213 ) {
V_311 = V_317 ;
V_311 += 25 ;
} else {
V_311 = V_318 ;
V_311 += 25 ;
}
}
if ( ( V_3 -> V_147 & V_148 ) &&
! ( V_3 -> V_239 == V_240 ) ) {
if ( V_3 -> V_239 == V_319 )
V_311 = V_320 ;
else if ( V_3 -> V_239 == V_321 )
V_311 = V_322 ;
else if ( V_3 -> V_243 & V_314 )
V_311 = V_323 ;
else
V_311 = V_324 ;
}
} else if ( V_3 -> V_48 & V_203 ) {
if ( V_3 -> V_243 & V_314 ) {
V_311 = V_325 ;
V_311 += 25 ;
} else {
V_311 = V_326 ;
V_311 += 25 ;
}
} else {
V_311 = ( unsigned char ) F_8 ( ( V_3 -> V_327 + 0x02 ) ) ;
V_311 = ( ( V_311 >> 2 ) & 0x03 ) ;
if ( V_188 > 0x13 ) {
V_311 = V_3 -> V_13 [
V_222 ] .
V_328 ;
V_311 &= V_268 ;
}
}
} else {
if ( V_188 <= 0x13 )
V_311 = V_310 ;
else
V_311 = V_310 ;
V_311 = V_311 >> 6 ;
if ( ( V_3 -> V_45 == V_329 ) ||
( V_3 -> V_45 == V_330 ) )
V_311 = V_306 [ V_311 ] ;
else if ( ( V_3 -> V_45 == V_256 ) ||
( V_3 -> V_45 == V_331 ) )
V_311 = V_308 [ V_311 ] ;
else
V_311 = V_309 [ V_311 ] ;
}
return V_311 ;
}
static void F_30 ( unsigned short V_188 ,
unsigned short V_189 ,
struct V_206 * V_207 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned char V_190 , V_261 ;
unsigned short V_332 ;
if ( V_3 -> V_229 == 1 ) {
V_190 = V_3 -> V_13 [ V_222 ] . V_328 ;
V_261 = F_6 ( V_3 -> V_200 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_200 , 0x31 , V_261 ) ;
F_4 ( V_3 -> V_200 , 0x2B ,
V_3 -> V_25 [ V_190 ] . V_220 ) ;
F_4 ( V_3 -> V_200 , 0x2C ,
V_3 -> V_25 [ V_190 ] . V_221 ) ;
F_4 ( V_3 -> V_200 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) && ( V_3 -> V_48
& V_202 ) ) {
V_332 = F_29 ( V_188 , V_189 ,
V_222 , V_207 ,
V_3 ) ;
V_261 = F_6 ( V_3 -> V_200 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_200 , 0x31 , V_261 ) ;
V_261 = V_3 -> V_28 [ V_332 ] . V_333 ;
F_4 ( V_3 -> V_200 , 0x2B , V_261 ) ;
V_261 = V_3 -> V_28 [ V_332 ] . V_334 ;
F_4 ( V_3 -> V_200 , 0x2C , V_261 ) ;
F_4 ( V_3 -> V_200 , 0x2D , 0x01 ) ;
} else {
V_190 = V_3 -> V_13 [ V_222 ] . V_328 ;
V_261 = F_6 ( V_3 -> V_200 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_200 , 0x31 , V_261 ) ;
F_4 ( V_3 -> V_200 , 0x2B ,
V_3 -> V_25 [ V_190 ] . V_220 ) ;
F_4 ( V_3 -> V_200 , 0x2C ,
V_3 -> V_25 [ V_190 ] . V_221 ) ;
F_4 ( V_3 -> V_200 , 0x2D , 0x01 ) ;
}
if ( V_207 -> V_265 >= V_159 ) {
if ( V_3 -> V_10 [ V_189 ] . V_199 &
V_294 ) {
V_261 = F_6 ( V_3 -> V_200 , 0x2B ) ;
F_4 ( V_3 -> V_200 , 0x2B , V_261 ) ;
V_261 = F_6 ( V_3 -> V_200 , 0x2C ) ;
V_190 = V_261 ;
V_190 &= 0xE0 ;
V_261 &= 0x1F ;
V_261 = V_261 << 1 ;
V_261 += 1 ;
V_261 |= V_190 ;
F_4 ( V_3 -> V_200 , 0x2C , V_261 ) ;
}
}
}
static void F_31 ( struct V_2 * V_3 )
{
unsigned char V_259 ;
V_259 = F_6 ( V_3 -> V_209 , 0x37 ) ;
V_259 = ( V_259 & 1 ) << 6 ;
F_13 ( V_3 -> V_200 , 0x06 , ~ 0x40 , V_259 ) ;
F_13 ( V_3 -> V_200 , 0x09 , ~ 0xc0 , V_259 | 0x80 ) ;
}
static void F_32 ( unsigned short V_188 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_261 ;
V_261 = F_6 ( V_3 -> V_200 , 0x3D ) ;
V_261 &= 0xfe ;
F_4 ( V_3 -> V_200 , 0x3D , V_261 ) ;
if ( V_188 > 0x13 ) {
F_4 ( V_3 -> V_200 , 0x08 , 0x34 ) ;
V_261 = F_6 ( V_3 -> V_200 , 0x09 ) ;
V_261 &= 0xC0 ;
F_4 ( V_3 -> V_200 , 0x09 , V_261 | 0x30 ) ;
V_261 = F_6 ( V_3 -> V_200 , 0x3D ) ;
V_261 |= 0x01 ;
F_4 ( V_3 -> V_200 , 0x3D , V_261 ) ;
} else {
if ( V_207 -> V_265 == V_162 ) {
F_4 ( V_3 -> V_200 , 0x08 , 0x0E ) ;
V_261 = F_6 ( V_3 -> V_200 , 0x09 ) ;
V_261 &= 0xC0 ;
F_4 ( V_3 -> V_200 , 0x09 , V_261 | 0x20 ) ;
} else {
F_4 ( V_3 -> V_200 , 0x08 , 0xAE ) ;
V_261 = F_6 ( V_3 -> V_200 , 0x09 ) ;
V_261 &= 0xF0 ;
F_4 ( V_3 -> V_200 , 0x09 , V_261 ) ;
}
}
if ( V_207 -> V_265 == V_335 )
F_31 ( V_3 ) ;
}
static void F_33 ( struct V_206 * V_207 ,
unsigned short V_188 , unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_261 , V_336 = 0 ;
short V_337 ;
unsigned char V_190 ;
if ( V_188 <= 0x13 )
V_337 = 0 ;
else {
V_190 = V_3 -> V_13 [ V_222 ] . V_328 ;
V_190 &= V_268 ;
V_337 = V_3 -> V_25 [ V_190 ] . CLOCK ;
}
V_261 = F_6 ( V_3 -> V_200 , 0x32 ) ;
V_261 &= 0xf3 ;
if ( V_337 >= 200 )
V_261 |= 0x0c ;
if ( V_207 -> V_265 >= V_159 )
V_261 &= ~ 0x04 ;
F_4 ( V_3 -> V_200 , 0x32 , V_261 ) ;
if ( V_207 -> V_265 < V_159 ) {
V_261 = F_6 ( V_3 -> V_200 , 0x1F ) ;
V_261 &= 0xE7 ;
if ( V_337 < 200 )
V_261 |= 0x10 ;
F_4 ( V_3 -> V_200 , 0x1F , V_261 ) ;
}
V_336 = 0x00 ;
F_13 ( V_3 -> V_200 , 0x07 , 0xFC , V_336 ) ;
if ( V_207 -> V_265 >= V_162 )
F_13 ( V_3 -> V_200 , 0x40 , 0xFC , V_336 & 0x03 ) ;
}
static void F_34 ( struct V_206 * V_207 ,
unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_261 , V_336 , V_338 , V_226 = 0 , V_197 , V_289 ,
V_339 ;
if ( V_188 > 0x13 ) {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_226 = V_3 -> V_13 [ V_222 ] .
V_257 ;
} else
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
if ( F_6 ( V_3 -> V_209 , 0x31 ) & 0x01 )
F_13 ( V_3 -> V_200 , 0x1F , 0x3F , 0x00 ) ;
if ( V_188 > 0x13 )
V_261 = V_226 ;
else
V_261 = 0 ;
V_336 = 0 ;
if ( V_188 > 0x13 ) {
if ( V_3 -> V_192 > 0x02 ) {
V_336 |= 0x02 ;
V_338 = V_3 -> V_192 - V_219 ;
V_338 = V_338 << 2 ;
V_336 |= V_338 ;
}
}
V_261 &= V_295 ;
if ( V_261 )
V_336 |= 0x20 ;
F_13 ( V_3 -> V_200 , 0x06 , ~ 0x3F , V_336 ) ;
V_289 = F_26 ( V_188 , V_189 , V_3 ) ;
if ( V_188 <= 0x13 )
V_339 = V_3 -> V_33 [ V_289 ] . V_292 ;
else
V_339 = V_3 -> V_36 [ V_289 ] . V_292 ;
V_261 = 0x0000 ;
if ( V_226 & V_295 ) {
if ( V_339 == 1024 )
V_261 = 0x0035 ;
else if ( V_339 == 1280 )
V_261 = 0x0048 ;
}
V_336 = V_261 & 0x00FF ;
F_13 ( V_3 -> V_209 , 0x19 , 0xFF , V_336 ) ;
V_336 = ( V_261 & 0xFF00 ) >> 8 ;
F_13 ( V_3 -> V_209 , 0x19 , 0xFC , V_336 ) ;
if ( V_197 & V_294 )
F_13 ( V_3 -> V_200 , 0x01 , 0xF7 , 0x08 ) ;
V_336 = 0 ;
if ( V_197 & V_340 )
V_336 |= 0x08 ;
if ( V_188 > 0x13 ) {
if ( V_3 -> V_192 == V_301 )
V_336 |= 0x40 ;
}
F_13 ( V_3 -> V_200 , 0x0F , ~ 0x48 , V_336 ) ;
V_261 = 0x60 ;
if ( V_3 -> V_192 != V_341 ) {
V_261 = V_261 ^ 0x60 ;
if ( V_3 -> V_192 != V_301 )
V_261 = V_261 ^ 0xA0 ;
}
F_13 ( V_3 -> V_200 , 0x21 , 0x1F , V_261 ) ;
F_33 ( V_207 , V_188 , V_222 ,
V_3 ) ;
V_261 = F_6 ( V_3 -> V_209 , 0x31 ) ;
if ( V_207 -> V_265 == V_162 ) {
if ( V_261 & 0x40 )
V_261 = 0x2c ;
else
V_261 = 0x6c ;
F_4 ( V_3 -> V_209 , 0x52 , V_261 ) ;
F_21 ( V_3 -> V_209 , 0x51 , 0x10 ) ;
} else if ( V_207 -> V_265 >= V_159 ) {
if ( V_261 & 0x40 )
V_261 = 0x33 ;
else
V_261 = 0x73 ;
F_4 ( V_3 -> V_209 , 0x52 , V_261 ) ;
F_4 ( V_3 -> V_209 , 0x51 , 0x02 ) ;
} else {
if ( V_261 & 0x40 )
V_261 = 0x2c ;
else
V_261 = 0x6c ;
F_4 ( V_3 -> V_209 , 0x52 , V_261 ) ;
}
}
static void F_35 ( unsigned short V_342 ,
unsigned short V_296 ,
unsigned short V_297 ,
unsigned short V_343 ,
struct V_2 * V_3 )
{
unsigned short V_259 , V_344 , V_345 ;
V_344 = V_296 ;
V_345 = V_297 ;
if ( V_342 != 0 ) {
V_259 = V_344 ;
V_344 = V_343 ;
V_343 = V_259 ;
if ( V_342 == 1 ) {
V_259 = V_345 ;
V_345 = V_343 ;
V_343 = V_259 ;
} else {
V_259 = V_345 ;
V_345 = V_344 ;
V_344 = V_259 ;
}
}
F_9 ( ( unsigned short ) V_343 , V_3 -> V_346 ) ;
F_9 ( ( unsigned short ) V_344 , V_3 -> V_346 ) ;
F_9 ( ( unsigned short ) V_345 , V_3 -> V_346 ) ;
}
static void F_36 ( unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_261 , V_336 , time , V_196 , V_264 , V_347 , V_348 , V_349 , V_350 , V_351 , V_352 , V_353 , V_342 , V_297 ,
V_296 , V_343 ;
const unsigned short * V_354 = NULL ;
if ( V_188 <= 0x13 )
V_261 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_261 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_261 &= V_355 ;
time = 64 ;
if ( V_261 == 0x00 )
V_354 = V_356 ;
else if ( V_261 == 0x08 )
V_354 = V_357 ;
else if ( V_261 == 0x10 )
V_354 = V_358 ;
else if ( V_261 == 0x18 ) {
time = 256 ;
V_354 = V_359 ;
}
if ( time == 256 )
V_264 = 16 ;
else
V_264 = time ;
F_9 ( 0xFF , V_3 -> V_360 ) ;
F_9 ( 0x00 , V_3 -> V_361 ) ;
for ( V_196 = 0 ; V_196 < V_264 ; V_196 ++ ) {
V_261 = V_354 [ V_196 ] ;
for ( V_347 = 0 ; V_347 < 3 ; V_347 ++ ) {
V_336 = 0 ;
if ( V_261 & 0x01 )
V_336 = 0x2A ;
if ( V_261 & 0x02 )
V_336 += 0x15 ;
F_9 ( V_336 , V_3 -> V_346 ) ;
V_261 = V_261 >> 2 ;
}
}
if ( time == 256 ) {
for ( V_196 = 16 ; V_196 < 32 ; V_196 ++ ) {
V_261 = V_354 [ V_196 ] ;
for ( V_347 = 0 ; V_347 < 3 ; V_347 ++ )
F_9 ( V_261 , V_3 -> V_346 ) ;
}
V_351 = 32 ;
for ( V_348 = 0 ; V_348 < 9 ; V_348 ++ ) {
V_352 = V_351 ;
V_353 = V_351 + 0x04 ;
V_342 = 0 ;
for ( V_349 = 0 ; V_349 < 3 ; V_349 ++ ) {
for ( V_350 = 0 ; V_350 < 5 ; V_350 ++ ) {
V_343 = V_354 [ V_351 ] ;
V_296 = V_354 [ V_352 ] ;
V_297 = V_354 [ V_353 ] ;
V_351 ++ ;
F_35 ( V_342 , V_296 , V_297 , V_343 , V_3 ) ;
}
V_351 -= 2 ;
for ( V_350 = 0 ; V_350 < 3 ; V_350 ++ ) {
V_343 = V_354 [ V_353 ] ;
V_296 = V_354 [ V_352 ] ;
V_297 = V_354 [ V_351 ] ;
V_351 -- ;
F_35 ( V_342 , V_296 , V_297 , V_343 , V_3 ) ;
}
V_342 ++ ;
}
V_351 += 5 ;
}
}
}
static void F_37 ( unsigned short V_188 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_289 , V_339 , V_362 , V_197 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_290 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_227 ;
if ( V_188 <= 0x13 )
V_289 = V_3 -> V_4 [ V_189 ] . V_290 ;
else
V_289 = V_3 -> V_10 [ V_189 ] . V_227 ;
if ( V_188 <= 0x13 ) {
V_339 = V_3 -> V_33 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_33 [ V_289 ] . V_293 ;
} else {
V_339 = V_3 -> V_36 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_36 [ V_289 ] . V_293 ;
}
if ( V_188 > 0x13 ) {
if ( V_197 & V_294 )
V_339 = V_339 << 1 ;
if ( V_197 & V_266 )
V_362 = V_362 << 1 ;
}
if ( V_339 == 720 )
V_339 = 640 ;
V_3 -> V_363 = V_339 ;
V_3 -> V_364 = V_339 ;
V_3 -> V_365 = V_362 ;
V_3 -> V_366 = V_362 ;
}
static void * F_38 ( unsigned short V_367 , unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_196 , V_368 , V_291 , V_224 , V_369 , V_197 , V_354 ;
struct V_370 * V_371 = NULL ;
V_224 = V_367 ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_369 = V_3 -> V_4 [ V_189 ] . V_312 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_369 = V_3 -> V_13 [ V_222 ] . V_313 ;
}
V_369 = V_369 & 0x0f ;
if ( V_224 <= 1 ) {
if ( V_188 <= 0x13 ) {
V_369 = V_3 -> V_4 [ V_189 ] . V_312 ;
} else {
V_369 = V_3 -> V_13 [ V_222 ] .
V_313 ;
}
if ( V_3 -> V_48 & V_202 ) {
if ( V_188 <= 0x13 )
V_369 = V_3 -> V_4 [ V_189 ] .
V_372 ;
else
V_369 = V_3 -> V_13 [
V_222 ] .
V_373 ;
}
if ( V_224 & 0x01 )
V_369 = ( V_369 >> 4 ) ;
V_369 = ( V_369 & 0x0f ) ;
}
V_291 = V_374 [ V_224 ] ;
if ( V_3 -> V_47 & V_375 ) {
if ( ( V_224 == 5 ) || ( V_224 ) == 7 )
V_291 = V_376 ;
else if ( ( V_224 == 3 ) || ( V_224 == 8 ) )
V_291 = V_377 ;
}
switch ( V_224 ) {
case 0 :
case 1 :
V_371 = V_378 ;
break;
case 2 :
V_371 = V_379 ;
break;
case 3 :
V_371 = V_380 ;
break;
case 4 :
V_371 = V_381 ;
break;
case 5 :
V_371 = V_382 ;
break;
case 6 :
V_371 = V_383 ;
break;
case 7 :
case 8 :
case 9 :
V_371 = NULL ;
break;
default:
break;
}
if ( V_371 == NULL )
return NULL ;
V_354 = V_224 ;
V_196 = 0 ;
while ( V_371 [ V_196 ] . V_384 != 0xff ) {
V_368 = V_3 -> V_45 ;
if ( V_224 & 0x0080 ) {
V_224 &= ( ~ 0x0080 ) ;
V_368 = V_3 -> V_46 ;
}
if ( V_3 -> V_47 & V_375 )
V_368 &= ( ~ V_385 ) ;
if ( V_371 [ V_196 ] . V_384 == V_368 ) {
V_224 = V_371 [ V_196 ] . V_386 ;
V_368 = V_3 -> V_47 ;
if ( V_188 <= 0x13 )
V_368 |= V_387 ;
if ( V_197 & V_294 )
V_368 |= V_388 ;
V_224 &= V_368 ;
if ( V_224 == V_371 [ V_196 ] . V_389 )
break;
}
V_196 ++ ;
}
if ( V_354 == 0 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_391 [ V_369 ] ;
break;
case 1 :
return & V_392 [ V_369 ] ;
break;
case 2 :
return & V_393 [ V_369 ] ;
break;
case 3 :
return & V_394 [ V_369 ] ;
break;
case 4 :
return & V_395 [ V_369 ] ;
break;
case 5 :
return & V_396 [ V_369 ] ;
break;
case 6 :
return & V_397 [ V_369 ] ;
break;
case 7 :
return & V_398 [ V_369 ] ;
break;
case 8 :
return & V_399 [ V_369 ] ;
break;
case 9 :
return & V_400 [ V_369 ] ;
break;
case 10 :
return & V_401 [ V_369 ] ;
break;
default:
break;
}
} else if ( V_354 == 1 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_402 [ V_369 ] ;
break;
case 1 :
return & V_403 [ V_369 ] ;
break;
case 2 :
return & V_404 [ V_369 ] ;
break;
case 3 :
return & V_405 [ V_369 ] ;
break;
case 4 :
return & V_406 [ V_369 ] ;
break;
case 5 :
return & V_407 [ V_369 ] ;
break;
case 6 :
return & V_408 [ V_369 ] ;
break;
case 7 :
return & V_409 [ V_369 ] ;
break;
case 8 :
return & V_410 [ V_369 ] ;
break;
case 9 :
return & V_411 [ V_369 ] ;
break;
case 10 :
return & V_412 [ V_369 ] ;
break;
default:
break;
}
} else if ( V_354 == 2 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_413 [ V_369 ] ;
break;
case 1 :
return & V_414 [ V_369 ] ;
break;
case 2 :
return & V_415 [ V_369 ] ;
break;
case 3 :
return & V_416 [ V_369 ] ;
break;
case 4 :
return & V_417 [ V_369 ] ;
break;
case 5 :
return & V_418 [ V_369 ] ;
break;
case 6 :
return & V_419 [ V_369 ] ;
break;
case 7 :
return & V_420 [ V_369 ] ;
break;
case 8 :
return & V_421 [ V_369 ] ;
break;
case 9 :
return & V_422 [ V_369 ] ;
break;
case 10 :
return & V_423 [ V_369 ] ;
break;
case 11 :
return & V_424 [ V_369 ] ;
break;
case 12 :
return & V_425 [ V_369 ] ;
break;
default:
break;
}
} else if ( V_354 == 3 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_426 [ V_369 ] ;
break;
case 1 :
return & V_427 [ V_369 ] ;
break;
case 2 :
return & V_428 [ V_369 ] ;
break;
case 3 :
return & V_429 [ V_369 ] ;
break;
case 4 :
return & V_430 [ V_369 ] ;
break;
case 5 :
return & V_431 [ V_369 ] ;
break;
case 6 :
return & V_432 [ V_369 ] ;
break;
case 7 :
return & V_433 [ V_369 ] ;
break;
case 8 :
return & V_434 [ V_369 ] ;
break;
case 9 :
return & V_435 [ V_369 ] ;
break;
case 10 :
return & V_436 [ V_369 ] ;
break;
case 11 :
return & V_437 [ V_369 ] ;
break;
case 12 :
return & V_438 [ V_369 ] ;
break;
case 13 :
return & V_439 [ V_369 ] ;
break;
case 14 :
return & V_440 [ V_369 ] ;
break;
default:
break;
}
} else if ( V_354 == 4 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_441 [ V_369 ] ;
break;
case 1 :
return & V_442 [ V_369 ] ;
break;
case 2 :
return & V_443 [ V_369 ] ;
break;
case 3 :
return & V_444 [ V_369 ] ;
break;
case 4 :
return & V_445 [ V_369 ] ;
break;
case 5 :
return & V_446 [ V_369 ] ;
break;
case 6 :
case 7 :
return & V_447 [ V_369 ] ;
break;
case 8 :
return & V_448 [ V_369 ] ;
break;
case 9 :
return & V_449 [ V_369 ] ;
break;
case 10 :
return & V_450 [ V_369 ] ;
break;
case 11 :
return & V_451 [ V_369 ] ;
break;
case 12 :
return & V_452 [ V_369 ] ;
break;
case 13 :
return & V_452 [ V_369 ] ;
break;
case 14 :
return & V_453 [ V_369 ] ;
break;
case 15 :
case 16 :
return & V_454 [ V_369 ] ;
break;
case 17 :
return & V_455 [ V_369 ] ;
break;
case 18 :
return & V_456 [ V_369 ] ;
break;
default:
break;
}
} else if ( V_354 == 5 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_457 [ V_369 ] ;
break;
case 1 :
return & V_458 [ V_369 ] ;
break;
case 2 :
return & V_459 [ V_369 ] ;
break;
case 3 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_460 [ V_369 ] ;
else
return & V_461 [ V_369 ] ;
break;
case 4 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_462 [ V_369 ] ;
else
return & V_463 [ V_369 ] ;
break;
case 5 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_464 [ V_369 ] ;
else
return & V_465 [ V_369 ] ;
break;
case 6 :
case 7 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_466 [ V_369 ] ;
else
return & V_467 [ V_369 ] ;
break;
case 8 :
return & V_468 [ V_369 ] ;
break;
case 9 :
return & V_469 [ V_369 ] ;
break;
case 10 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_470 [ V_369 ] ;
else
return & V_471 [ V_369 ] ;
break;
case 11 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_472 [ V_369 ] ;
else
return & V_473 [ V_369 ] ;
break;
case 12 :
return & V_474 [ V_369 ] ;
break;
case 13 :
case 14 :
return & V_475 [ V_369 ] ;
break;
case 15 :
return & V_476 [ V_369 ] ;
break;
case 16 :
case 17 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_477 [ V_369 ] ;
else
return & V_478 [ V_369 ] ;
break;
case 18 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_479 [ V_369 ] ;
else
return & V_480 [ V_369 ] ;
break;
case 19 :
return & V_481 [ V_369 ] ;
break;
default:
break;
}
} else if ( V_354 == 6 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_482 [ V_369 ] ;
break;
case 1 :
return & V_483 [ V_369 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void * F_39 ( unsigned short V_367 , unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_196 , V_368 , V_224 , V_369 , V_197 , V_354 ;
struct V_484 * V_371 = NULL ;
V_224 = V_367 ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_369 = V_3 -> V_4 [ V_189 ] . V_312 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_369 = V_3 -> V_13 [ V_222 ] . V_313 ;
}
V_369 = V_369 & 0x3f ;
V_354 = V_224 ;
switch ( V_224 ) {
case 0 :
V_371 = NULL ;
break;
case 1 :
V_371 = NULL ;
break;
case 2 :
case 6 :
V_371 = V_485 ;
break;
case 3 :
V_371 = NULL ;
break;
case 4 :
V_371 = V_486 ;
break;
case 5 :
V_371 = NULL ;
break;
default:
break;
}
if ( V_371 == NULL )
return NULL ;
V_368 = V_3 -> V_49 ;
if ( V_3 -> V_48 & V_205 )
V_368 = V_368 | V_487 ;
if ( V_197 & V_294 )
V_368 = V_368 | V_488 ;
V_196 = 0 ;
while ( V_371 [ V_196 ] . V_386 != 0xffff ) {
if ( ( V_368 & V_371 [ V_196 ] . V_386 ) == V_371 [ V_196 ] . V_389 )
break;
V_196 ++ ;
}
if ( V_354 == 0x04 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_489 [ V_369 ] ;
break;
case 1 :
return & V_490 [ V_369 ] ;
break;
case 2 :
return & V_491 [ V_369 ] ;
break;
case 3 :
return & V_492 [ V_369 ] ;
break;
case 4 :
return & V_493 [ V_369 ] ;
break;
case 5 :
return & V_494 [ V_369 ] ;
break;
case 6 :
return & V_495 [ V_369 ] ;
break;
case 7 :
return & V_496 [ V_369 ] ;
break;
case 8 :
return & V_497 [ V_369 ] ;
break;
case 9 :
return & V_498 [ V_369 ] ;
break;
case 10 :
return & V_499 [ V_369 ] ;
break;
case 11 :
return & V_500 [ V_369 ] ;
break;
case 12 :
return & V_490 [ V_369 ] ;
break;
case 13 :
return & V_501 [ V_369 ] ;
break;
default:
break;
}
} else if ( V_354 == 0x02 ) {
switch ( V_371 [ V_196 ] . V_390 ) {
case 0 :
return & V_502 [ V_369 ] ;
break;
case 1 :
return & V_503 [ V_369 ] ;
break;
case 2 :
return & V_504 [ V_369 ] ;
break;
case 3 :
return & V_505 [ V_369 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void F_40 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_224 ;
struct V_506 * V_507 = NULL ;
V_224 = 2 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
V_507 = (struct V_506 * ) F_38 ( V_224 ,
V_188 , V_189 , V_222 ,
V_3 ) ;
V_3 -> V_508 = V_507 -> V_508 ;
V_3 -> V_509 = V_507 -> V_509 ;
V_3 -> V_510 = V_507 -> V_511 ;
V_3 -> V_512 = V_507 -> V_513 ;
}
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
if ( ! ( V_3 -> V_47 & ( V_514
| V_375 ) ) ) {
if ( ( V_3 -> V_45 == V_256 ) ||
( V_3 -> V_45 == V_331 ) ) {
V_3 -> V_364 = 1024 ;
V_3 -> V_366 = 768 ;
} else if ( ( V_3 -> V_45 == V_235 ) ||
( V_3 -> V_45 == V_515 ) ) {
V_3 -> V_364 = 1280 ;
V_3 -> V_366 = 1024 ;
} else if ( V_3 -> V_45 == V_516 ) {
V_3 -> V_364 = 1400 ;
V_3 -> V_366 = 1050 ;
} else {
V_3 -> V_364 = 1600 ;
V_3 -> V_366 = 1200 ;
}
}
}
}
static void F_41 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned char V_190 ;
unsigned short V_224 , V_196 ;
struct V_517 * V_507 = NULL ;
struct V_518 * V_519 = NULL ;
if ( V_188 <= 0x13 )
V_190 = V_3 -> V_4 [ V_189 ] . V_312 ;
else
V_190 = V_3 -> V_13 [ V_222 ] . V_313 ;
V_190 = V_190 & V_268 ;
V_224 = 0 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
V_507 = (struct V_517 * )
F_38 ( V_224 , V_188 ,
V_189 ,
V_222 ,
V_3 ) ;
for ( V_196 = 0 ; V_196 < 8 ; V_196 ++ )
V_3 -> V_138 [ 0 ] . V_261 [ V_196 ] = V_507 [ 0 ] . V_520 [ V_196 ] ;
}
F_17 ( V_3 , V_207 ) ;
V_224 = 1 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
V_519 = (struct V_518 * )
F_38 (
V_224 ,
V_188 ,
V_189 ,
V_222 ,
V_3 ) ;
for ( V_196 = 0 ; V_196 < 7 ; V_196 ++ )
V_3 -> V_141 [ 0 ] . V_261 [ V_196 ] = V_519 [ 0 ] . V_520 [ V_196 ] ;
}
F_18 ( V_189 , V_188 , V_3 ) ;
}
static unsigned short F_42 ( struct V_2 * V_3 )
{
unsigned char V_369 , V_194 , V_521 , V_196 ;
V_194 = F_6 ( V_3 -> V_209 , 0x36 ) ;
V_369 = V_194 & 0x0F ;
V_194 = V_194 & 0xF0 ;
V_196 = 0 ;
V_521 = V_3 -> V_150 [ V_196 ] . V_522 ;
while ( V_521 != 0xFF ) {
if ( V_521 & 0x80 ) {
V_369 = V_194 ;
V_521 = V_521 & ~ ( 0x80 ) ;
}
if ( V_369 == V_521 )
break;
V_196 ++ ;
V_521 = V_3 -> V_150 [ V_196 ] . V_522 ;
}
return V_196 ;
}
static unsigned short F_43 ( struct V_2 * V_3 )
{
unsigned short V_194 , V_369 , V_521 , V_196 ;
V_369 = V_3 -> V_45 ;
V_194 = V_3 -> V_46 ;
V_196 = 0 ;
V_521 = V_3 -> V_150 [ V_196 ] . V_522 ;
while ( V_521 != 0xFF ) {
if ( ( V_521 & 0x80 ) && ( V_521 != 0x80 ) ) {
V_369 = V_194 ;
V_521 &= ~ 0x80 ;
}
if ( V_369 == V_521 )
break;
V_196 ++ ;
V_521 = V_3 -> V_150 [ V_196 ] . V_522 ;
}
if ( V_521 == 0xFF ) {
V_3 -> V_45 = V_256 ;
V_3 -> V_46 = 0 ;
V_196 = 0 ;
}
return V_196 ;
}
static void F_44 ( unsigned short * V_523 ,
unsigned short * V_524 ,
struct V_2 * V_3 )
{
unsigned short V_525 ;
V_525 = F_42 ( V_3 ) ;
* V_523 = V_3 -> V_150 [ V_525 ] . V_526 ;
* V_524 = V_3 -> V_150 [ V_525 ] . V_527 ;
return;
}
static void F_45 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_224 , V_223 , V_291 , V_368 , V_528 , V_529 , V_197 ;
unsigned long V_259 , V_530 , V_298 , V_531 , V_532 ;
struct V_533 * V_507 = NULL ;
struct V_534 * V_519 = NULL ;
if ( V_188 > 0x13 )
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
else
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_224 = 3 ;
if ( V_3 -> V_47 & V_375 )
V_519 =
(struct V_534 * )
F_38 (
V_224 ,
V_188 ,
V_189 ,
V_222 ,
V_3 ) ;
else
V_507 =
(struct V_533 * )
F_38 (
V_224 ,
V_188 ,
V_189 ,
V_222 ,
V_3 ) ;
F_44 ( & V_223 , & V_224 , V_3 ) ;
V_528 = V_224 ;
V_529 = V_223 ;
if ( ( V_3 -> V_45 == V_256 ) ||
( V_3 -> V_45 == V_331 ) ) {
V_223 = 1024 ;
V_224 = 768 ;
} else if ( ( V_3 -> V_45 == V_235 ) ||
( V_3 -> V_45 == V_515 ) ) {
V_223 = 1280 ;
V_224 = 1024 ;
} else if ( V_3 -> V_45 == V_516 ) {
V_223 = 1400 ;
V_224 = 1050 ;
} else {
V_223 = 1600 ;
V_224 = 1200 ;
}
if ( V_3 -> V_47 & V_514 ) {
V_3 -> V_364 = V_223 ;
V_3 -> V_366 = V_224 ;
V_3 -> V_363 = V_223 ;
V_3 -> V_365 = V_224 ;
}
V_223 = V_3 -> V_510 ;
if ( V_3 -> V_47 & V_375 )
V_224 = V_519 -> V_535 ;
else
V_224 = V_507 -> V_535 ;
V_291 = V_3 -> V_364 ;
V_224 = V_224 & 0x0fff ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
F_4 ( V_3 -> V_536 , 0x1A , V_224 & 0x07 ) ;
V_291 = V_291 >> 3 ;
V_224 = V_224 >> 3 ;
F_4 ( V_3 -> V_536 , 0x16 ,
( unsigned short ) ( V_224 & 0xff ) ) ;
F_4 ( V_3 -> V_536 , 0x17 ,
( unsigned short ) ( V_291 & 0xff ) ) ;
V_223 = V_3 -> V_510 ;
if ( V_3 -> V_47 & V_375 )
V_224 = V_519 -> V_537 ;
else
V_224 = V_507 -> V_537 ;
V_291 = V_529 ;
if ( V_3 -> V_47 & V_375 )
V_291 = V_519 -> V_538 ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
V_223 = V_224 & 0x07 ;
V_223 = V_223 >> 5 ;
V_291 = V_291 >> 3 ;
V_224 = V_224 >> 3 ;
V_291 &= 0x1f ;
V_223 |= V_291 ;
F_4 ( V_3 -> V_536 , 0x15 , V_223 ) ;
F_4 ( V_3 -> V_536 , 0x14 ,
( unsigned short ) ( V_224 & 0xff ) ) ;
V_223 = V_3 -> V_512 ;
if ( V_3 -> V_47 & V_375 )
V_224 = V_519 -> V_539 ;
else
V_224 = V_507 -> V_539 ;
V_291 = V_3 -> V_366 ;
V_224 = V_224 & 0x0fff ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
F_4 ( V_3 -> V_536 , 0x1b ,
( unsigned short ) ( V_224 & 0xff ) ) ;
F_4 ( V_3 -> V_536 , 0x1c ,
( unsigned short ) ( V_291 & 0xff ) ) ;
V_224 = ( V_224 >> 8 ) & 0x07 ;
V_291 = ( V_291 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_536 , 0x1d ,
( unsigned short ) ( ( V_291 << 3 )
| V_224 ) ) ;
V_223 = V_3 -> V_512 ;
if ( V_3 -> V_47 & V_375 )
V_224 = V_519 -> V_540 ;
else
V_224 = V_507 -> V_540 ;
V_291 = V_528 ;
if ( V_3 -> V_47 & V_375 )
V_291 = V_519 -> V_541 ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
F_4 ( V_3 -> V_536 , 0x18 ,
( unsigned short ) ( V_224 & 0xff ) ) ;
F_13 ( V_3 -> V_536 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_291 & 0x0f ) ) ;
V_223 = ( ( V_224 >> 8 ) & 0x07 ) << 3 ;
V_224 = V_3 -> V_365 ;
if ( V_224 != V_3 -> V_366 )
V_223 |= 0x40 ;
if ( V_3 -> V_47 & V_542 )
V_223 |= 0x40 ;
F_13 ( V_3 -> V_536 , 0x1a , 0x07 ,
V_223 ) ;
V_291 = V_3 -> V_509 ;
V_224 = V_3 -> V_366 ;
V_223 = V_3 -> V_365 ;
V_291 -= V_223 ;
V_259 = V_223 ;
V_530 = ( V_259 << 18 ) / V_224 ;
V_368 = ( unsigned short ) ( ( V_259 << 18 ) % V_224 ) ;
if ( V_368 != 0 )
V_530 += 1 ;
V_298 = V_530 ;
V_532 = V_298 ;
F_4 ( V_3 -> V_536 , 0x37 ,
( unsigned short ) ( V_298 & 0xff ) ) ;
F_4 ( V_3 -> V_536 , 0x36 ,
( unsigned short ) ( ( V_298 >> 8 ) & 0xff ) ) ;
V_224 = ( unsigned short ) ( V_298 >> 16 ) ;
V_223 = V_224 & 0x03 ;
V_224 = V_3 -> V_365 ;
if ( V_224 == V_3 -> V_366 )
V_223 |= 0x04 ;
F_4 ( V_3 -> V_536 , 0x35 , V_223 ) ;
if ( V_3 -> V_147 & V_232 ) {
V_298 = V_532 ;
F_4 ( V_3 -> V_543 ,
0x3c ,
( unsigned short ) ( V_298 & 0xff ) ) ;
F_4 ( V_3 -> V_543 ,
0x3b ,
( unsigned short ) ( ( V_298 >> 8 ) &
0xff ) ) ;
V_224 = ( unsigned short ) ( V_298 >> 16 ) ;
F_13 ( V_3 -> V_543 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_224 &
0xff ) << 6 ) ) ;
V_291 = V_3 -> V_365 ;
if ( V_291 == V_3 -> V_366 )
F_13 ( V_3 -> V_543 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_13 ( V_3 -> V_543 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_291 = V_3 -> V_363 ;
V_224 = V_3 -> V_364 ;
V_530 = V_291 << 16 ;
V_223 = ( unsigned short ) ( V_530 / V_224 ) ;
if ( ( V_224 & 0xffff ) == ( V_291 & 0xffff ) )
V_223 = 65535 ;
V_531 = V_223 ;
V_530 = V_3 -> V_363 << 16 ;
V_530 /= V_531 ;
V_531 = V_531 << 16 ;
V_530 -= 1 ;
V_531 = ( V_531 & 0xffff0000 ) + ( V_530 & 0xffff ) ;
V_223 = ( unsigned short ) ( V_531 & 0xff ) ;
F_4 ( V_3 -> V_536 , 0x1f , V_223 ) ;
V_530 = V_3 -> V_365 << 18 ;
V_530 = V_530 / V_532 ;
V_224 = ( unsigned short ) ( V_530 & 0xffff ) ;
if ( V_3 -> V_45 == V_256 )
V_224 -= 1 ;
V_223 = ( ( V_224 >> 8 ) & 0xff ) << 3 ;
V_223 |= ( unsigned short ) ( ( V_531 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_536 , 0x20 ,
( unsigned short ) ( V_223 & 0xff ) ) ;
F_4 ( V_3 -> V_536 , 0x21 ,
( unsigned short ) ( V_224 & 0xff ) ) ;
V_531 = V_531 >> 16 ;
if ( V_197 & V_294 )
V_531 = V_531 >> 1 ;
F_4 ( V_3 -> V_536 , 0x22 ,
( unsigned short ) ( ( V_531 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_536 , 0x23 ,
( unsigned short ) ( V_531 & 0xff ) ) ;
}
static void F_46 ( unsigned char * V_544 , unsigned char * V_545 ,
struct V_2 * V_3 )
{
unsigned short V_190 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
V_190 = F_43 ( V_3 ) ;
if ( V_3 -> V_48 & V_204 ) {
* V_544 = V_3 -> V_150 [ V_190 ] . V_546 ;
* V_545 = V_3 -> V_150 [ V_190 ] . V_547 ;
} else {
* V_544 = V_3 -> V_150 [ V_190 ] . V_548 ;
* V_545 = V_3 -> V_150 [ V_190 ] . V_549 ;
}
}
return;
}
static unsigned char F_47 ( unsigned short V_222 ,
unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_190 , V_197 ;
unsigned char V_369 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
if ( ( V_3 -> V_243 & V_550 ) &&
( ! ( V_3 -> V_47 & V_375 ) ) ) {
V_190 = F_42 ( V_3 ) ;
V_369 = V_3 -> V_150 [ V_190 ] . V_551 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) )
return V_369 ;
if ( V_3 -> V_147 &
( V_250 |
V_251 |
V_148 |
V_149 |
V_232 ) ) {
if ( V_3 -> V_48 & V_238 ) {
V_369 = V_315 ;
if ( ! ( V_3 -> V_49 & V_314 ) )
V_369 = V_316 ;
if ( V_3 -> V_49 & V_244 ) {
V_369 = V_317 ;
if ( ! ( V_197 & V_213 ) )
V_369 = V_318 ;
}
return V_369 ;
}
if ( V_3 -> V_49 & V_552 ) {
V_369 = V_320 ;
return V_369 ;
}
if ( V_3 -> V_49 & V_553 ) {
V_369 = V_322 ;
return V_369 ;
}
V_369 = V_554 ;
if ( ! ( V_3 -> V_49 & V_555 ) ) {
V_369 = V_325 ;
if ( ! ( V_3 -> V_49 & V_314 ) )
V_369 = V_326 ;
}
if ( V_3 -> V_48 & V_203 )
return V_369 ;
}
}
V_369 = ( unsigned char ) F_8 ( ( V_3 -> V_327 + 0x02 ) ) ;
V_369 = V_369 >> 2 ;
V_369 &= 0x03 ;
if ( ( V_3 -> V_47 & V_375 ) && ( V_197 & V_213 ) )
V_369 = V_369 ^ V_369 ;
if ( V_188 <= 0x13 )
return V_369 ;
V_369 = V_3 -> V_13 [ V_222 ] . V_328 ;
return V_369 ;
}
static void F_48 ( unsigned char V_369 , unsigned char * V_544 ,
unsigned char * V_545 , struct V_2 * V_3 )
{
if ( V_3 -> V_147 & ( V_556 | V_250 | V_251
| V_148 | V_149 | V_232 ) ) {
if ( ( ! ( V_3 -> V_48 & V_202 ) ) && ( V_3 -> V_243
& V_550 ) ) {
* V_544 = ( unsigned char ) V_30 [ V_369 ] . V_220 ;
* V_545 = V_30 [ V_369 ] . V_221 ;
}
} else {
* V_544 = V_27 [ V_369 ] . V_220 ;
* V_545 = V_27 [ V_369 ] . V_221 ;
}
}
static void F_49 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned char V_544 , V_545 , V_369 ;
int V_196 ;
V_369 = F_47 ( V_222 , V_188 , V_189 ,
V_3 ) ;
F_48 ( V_369 , & V_544 , & V_545 , V_3 ) ;
F_46 ( & V_544 , & V_545 , V_3 ) ;
for ( V_196 = 0 ; V_196 < 4 ; V_196 ++ ) {
F_13 ( V_3 -> V_209 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_196 ) ) ;
if ( ( ! ( V_3 -> V_48 & V_202 ) )
&& ( ! ( V_3 -> V_48 & V_205 ) ) ) {
F_4 ( V_3 -> V_200 , 0x2e , V_544 ) ;
F_4 ( V_3 -> V_200 , 0x2f , V_545 ) ;
} else {
F_4 ( V_3 -> V_200 , 0x2b , V_544 ) ;
F_4 ( V_3 -> V_200 , 0x2c , V_545 ) ;
}
}
}
static void F_50 ( struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_557 , V_558 , V_259 , V_521 , V_223 ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
V_557 = 0 ;
V_558 = 0 ;
V_259 = F_6 ( V_3 -> V_200 , 0x01 ) ;
if ( ! ( V_259 & 0x20 ) ) {
V_259 = F_6 ( V_3 -> V_209 , 0x17 ) ;
if ( V_259 & 0x80 ) {
V_259 = F_6 ( V_3 -> V_209 , 0x53 ) ;
if ( ! ( V_259 & 0x40 ) )
V_557 |= V_559 ;
}
}
V_259 = F_6 ( V_3 -> V_536 , 0x2e ) ;
V_259 &= 0x0f ;
if ( ! ( V_259 == 0x08 ) ) {
V_223 = F_6 ( V_3 -> V_536 , 0x13 ) ;
if ( V_223 & 0x04 )
V_557 = V_557 | V_560 ;
V_259 &= 0x05 ;
if ( ! ( V_557 & V_560 ) )
if ( V_259 == 0x01 )
V_557 |= V_561 ;
if ( V_259 == 0x04 )
V_557 |= V_560 ;
if ( V_259 == 0x05 ) {
V_259 = F_6 ( V_3 -> V_562 , 0x00 ) ;
if ( ! ( V_259 & 0x08 ) )
V_558 |= V_563 ;
if ( ! ( V_259 & 0x04 ) )
V_558 |= V_564 ;
if ( V_259 & 0x02 )
V_558 |= V_565 ;
if ( V_3 -> V_48 & V_238 ) {
if ( V_259 & 0x01 )
V_558 |= V_566 ;
}
if ( V_3 -> V_48 & V_248 ) {
V_259 = F_6 (
V_3 -> V_562 ,
0x4d ) ;
if ( V_259 & 0x10 )
V_558 |= V_567 ;
}
if ( V_558 != 0 )
V_557 |= V_568 ;
}
}
V_259 = F_6 ( V_3 -> V_209 , 0x3d ) ;
if ( V_557 & V_560 ) {
if ( ( V_3 -> V_243 & V_569 ) ) {
if ( V_259 & V_568 )
V_557 |= V_568 ;
}
}
V_259 = V_557 ;
V_521 = ~ V_570 ;
F_13 ( V_3 -> V_209 , 0x3d , V_521 , V_259 ) ;
if ( ! ( V_3 -> V_243 & V_569 ) )
F_4 ( V_3 -> V_209 , 0x3e , V_558 ) ;
} else {
return;
}
}
void F_51 ( struct V_2 * V_3 )
{
unsigned short V_571 , V_224 , V_194 ;
if ( V_3 -> V_229 == 0 ) {
V_224 = V_251 ;
V_571 = F_6 ( V_3 -> V_543 , 0x00 ) ;
if ( V_571 != 0x02 ) {
V_224 = V_556 ;
V_571 = F_6 ( V_3 -> V_543 , 0x01 ) ;
if ( V_571 >= 0xB0 ) {
V_224 = V_250 ;
if ( V_571 >= 0xC0 ) {
V_224 = V_232 ;
if ( V_571 >= 0xD0 ) {
V_224 = V_148 ;
if ( V_571 >= 0xE0 ) {
V_224 = V_149 ;
V_194 = F_6 (
V_3 -> V_543 ,
0x39 ) ;
if ( V_194 != 0xFF )
V_224 =
V_232 ;
}
}
}
if ( V_224 & ( V_250 | V_251 ) ) {
V_571 = F_6 (
V_3 -> V_543 ,
0x23 ) ;
if ( ! ( V_571 & 0x02 ) )
V_224 = V_224 | V_572 ;
}
}
}
V_3 -> V_147 = V_224 ;
}
}
static void F_52 ( unsigned short V_188 , unsigned short V_189 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_223 , V_573 , V_224 , V_259 , V_197 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_3 -> V_243 = 0 ;
V_3 -> V_192 = V_197 & V_574 ;
V_224 = 0 ;
if ( V_3 -> V_147 & 0xFFFF ) {
V_259 = F_6 ( V_3 -> V_209 , 0x30 ) ;
V_224 = V_224 | V_259 ;
V_259 = F_6 ( V_3 -> V_209 , 0x31 ) ;
V_573 = V_259 ;
V_573 = V_573 << 8 ;
V_223 = V_259 << 8 ;
V_224 = V_224 | V_223 ;
V_259 = ( V_575 | V_248 | V_202
| V_205 | V_576 ) ;
V_259 = 0xFFFF ^ V_259 ;
V_224 &= V_259 ;
V_259 = F_6 ( V_3 -> V_209 , 0x38 ) ;
if ( V_3 -> V_577 == 1 ) {
if ( ( V_207 -> V_265 >= V_159 ) ||
( V_207 -> V_265 >= V_578 ) ) {
if ( V_3 -> V_229 == 0 ) {
if ( V_3 -> V_147 &
( V_251 |
V_148 |
V_149 |
V_232 ) ) {
if ( V_259 & V_579 ) {
V_224 |=
V_575 ;
if ( V_259 & V_580 )
V_224 |=
V_202 ;
}
}
}
}
}
if ( V_3 -> V_581 == 1 ) {
if ( ( ( V_3 -> V_229 == 0 ) &&
( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) ||
( V_3 -> V_147 & V_232 ) ) ) ) {
if ( V_259 & V_582 ) {
if ( V_3 -> V_583 == 1 ) {
V_259 = F_6 (
V_3 -> V_209 ,
0x35 ) ;
V_259 &= V_584 ;
V_224 |= V_238 ;
if ( V_259 != V_585 ) {
V_224 &=
( ~ V_238 ) ;
V_224 |=
V_248 ;
}
}
}
}
}
V_223 = V_573 ;
if ( V_3 -> V_229 == 0 ) {
if ( V_3 -> V_581 == 1 ) {
if ( V_3 -> V_583 == 1 )
V_259 = 0x09FC ;
else
V_259 = 0x097C ;
} else {
if ( V_3 -> V_583 == 1 )
V_259 = 0x01FC ;
else
V_259 = 0x017C ;
}
} else {
V_259 = V_204 ;
}
if ( ! ( V_224 & V_259 ) ) {
V_223 |= V_576 ;
V_224 = 0 ;
}
if ( V_3 -> V_577 == 1 ) {
if ( ! ( V_3 -> V_147 & V_572 ) ) {
if ( V_224 & V_202 ) {
if ( V_224 & V_586 )
V_224 &= ( ~ ( V_204 |
V_230 |
V_587 ) ) ;
else
V_224 &= ( ~ ( V_204 |
V_230 |
V_203 |
V_587 ) ) ;
}
}
}
if ( ! ( V_224 & ( V_587 | V_586 ) ) ) {
if ( V_3 -> V_588 == 1 ) {
if ( V_224 & V_230 ) {
V_224 &= ( 0xFF00 |
V_230 |
V_587 |
V_586 ) ;
V_224 &= ( 0x00FF | ( ~ V_248 ) ) ;
}
} else {
V_224 &= ( ~ ( V_230 |
V_204 |
V_203 ) ) ;
}
}
if ( ! ( V_3 -> V_147 & V_572 ) ) {
if ( V_224 & V_204 ) {
V_224 &= ( 0xFF00 |
V_204 |
V_587 |
V_586 ) ;
V_224 &= ( 0x00FF | ( ~ V_248 ) ) ;
}
}
if ( V_224 & V_247 ) {
V_224 &= ( 0xFF00 |
V_247 |
V_587 |
V_586 ) ;
V_224 &= ( 0x00FF | ( ~ V_248 ) ) ;
}
if ( V_3 -> V_581 == 1 ) {
if ( V_224 & V_248 )
V_224 &= ( 0xFF00 |
V_587 |
V_586 ) ;
}
if ( V_3 -> V_583 == 1 ) {
if ( V_224 & V_238 )
V_224 &= ( 0xFF00 |
V_238 |
V_587 |
V_586 ) ;
}
if ( V_223 & V_576 ) {
if ( ! ( V_224 & ( V_587 | V_586 ) ) )
V_224 = V_576 ;
}
if ( ! ( V_224 & V_576 ) ) {
if ( ( ! ( V_224 & V_589 ) ) ||
( ! ( V_197 & V_590 ) ) ) {
if ( V_3 -> V_577 == 1 ) {
if ( ! ( V_224 & V_202 ) )
V_224 |= ( V_205 |
V_586 ) ;
}
}
if ( ( V_224 & V_205 ) &&
( V_224 & V_202 ) ) {
V_224 ^= ( V_204 |
V_202 |
V_575 ) ;
V_3 -> V_243 |= V_569 ;
}
}
}
V_3 -> V_48 = V_224 ;
}
static void F_53 ( unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_259 , V_224 = 0 , V_225 = 0 , V_197 , V_591 ;
V_224 = 0 ;
V_225 = 0 ;
if ( V_3 -> V_48 & V_203 ) {
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] .
V_198 ;
V_225 = V_3 -> V_4 [ V_189 ] .
V_290 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] .
V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] .
V_227 ;
}
if ( V_3 -> V_48 & V_203 ) {
V_259 = F_6 ( V_3 -> V_209 , 0x35 ) ;
V_224 = V_259 ;
if ( V_224 & V_253 ) {
V_224 &= ( V_592 |
V_593 |
V_594 |
V_253 ) ;
if ( V_224 & V_593 )
V_224 &= ~ V_253 ;
} else
V_224 &= ( V_592 |
V_595 |
V_253 ) ;
}
if ( V_3 -> V_229 == 0 ) {
if ( V_3 -> V_48 & V_247 )
V_224 |= V_253 ;
}
if ( V_3 -> V_581 == 1 ) {
if ( V_3 -> V_48 & V_248 ) {
V_591 = F_6 ( V_3 -> V_209 , 0x35 ) ;
V_591 &= V_584 ;
if ( V_591 == V_596 )
V_224 |= V_597 ;
if ( V_591 == V_598 )
V_224 = V_224 | V_553 ;
if ( V_591 == V_599 )
V_224 = V_224 | V_552 ;
}
}
if ( V_3 -> V_583 == 1 ) {
if ( V_3 -> V_48 & V_238 )
V_224 = V_224 | V_600 | V_253 ;
}
if ( V_3 -> V_229 == 0 ) {
if ( ( V_3 -> V_48 & V_205 ) &&
( ! ( V_3 -> V_48 & V_255 ) ) )
V_224 |= V_244 ;
if ( ! ( V_224 & V_253 ) &&
( V_197 > 13 ) &&
( V_225 == 8 ) )
V_224 |= V_555 ;
V_224 |= V_314 ;
if ( V_3 -> V_48 & V_238 ) {
if ( V_3 -> V_48 & V_205 )
V_224 &= ( ~ V_314 ) ;
} else {
if ( V_224 &
( V_553 | V_552 ) )
V_224 &= ( ~ V_314 ) ;
else if ( ! ( V_3 -> V_147 &
( V_250 |
V_251 |
V_148 |
V_149 |
V_232 ) ) ) {
if ( V_224 & V_244 )
V_224 &= ( ~ V_314 ) ;
}
}
}
}
V_3 -> V_49 = V_224 ;
}
static unsigned char F_54 ( unsigned short V_188 ,
unsigned short V_189 , struct V_2 * V_3 )
{
unsigned short V_259 , V_223 , V_224 , V_197 , V_225 = 0 , V_601 ;
V_3 -> V_45 = 0 ;
V_3 -> V_46 = 0 ;
V_3 -> V_47 = 0 ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
}
V_259 = F_6 ( V_3 -> V_209 , 0x36 ) ;
V_224 = V_259 & 0x0F ;
if ( V_224 == 0 )
V_224 = V_256 ;
if ( ( V_224 == V_256 ) || ( V_224 == V_235 ) ) {
if ( V_3 -> V_48 & V_589 ) {
V_223 = F_6 ( V_3 -> V_209 , 0x33 ) ;
if ( V_3 -> V_48 & V_202 )
V_223 &= 0x0F ;
else
V_223 = V_223 >> 4 ;
if ( ( V_225 == 6 ) || ( V_225 == 9 ) ) {
if ( V_223 >= 3 )
V_224 |= V_602 ;
} else if ( ( V_225 == 7 ) || ( V_225 == 8 ) ) {
if ( V_223 >= 4 )
V_224 |= V_602 ;
}
}
}
V_3 -> V_45 = V_224 ;
if ( ! ( V_3 -> V_48 & ( V_204 | V_202 ) ) )
return 0 ;
V_224 = 0 ;
V_259 = F_6 ( V_3 -> V_209 , 0x37 ) ;
V_259 &= ( V_603 | V_237 | V_604 | V_605 ) ;
V_224 |= V_259 ;
V_601 = F_43 ( V_3 ) ;
V_223 = V_3 -> V_150 [ V_601 ] . V_606 ;
if ( V_3 -> V_229 == 0 ) {
if ( ( ( V_3 -> V_147 & V_149 ) || ( V_3 -> V_147
& V_232 ) ) && ( V_223 & V_607 ) ) {
V_224 |= V_608 ;
}
}
if ( V_3 -> V_229 == 0 ) {
if ( ( V_3 -> V_45 == V_516 ) && ( V_3 -> V_48
& V_204 ) && ( V_188 > 0x13 ) && ( V_225
== 9 ) && ( ! ( V_224 & V_375 ) ) )
V_224 |= V_514 ;
}
if ( V_3 -> V_609 == 1 ) {
if ( V_197 & V_294 ) {
if ( ! ( V_224 & V_514 ) ) {
V_224 |= V_542 ;
} else {
if ( V_188 > 0x13 ) {
if ( V_3 -> V_45
== V_256 ) {
if ( V_225 == 4 ) {
V_224 |= V_542 ;
}
}
}
}
}
}
if ( V_3 -> V_48 & V_205 ) {
if ( V_3 -> V_48 & V_255 )
V_224 |= V_610 ;
} else {
V_224 |= V_610 ;
}
V_3 -> V_47 = V_224 ;
if ( V_3 -> V_229 == 0 ) {
if ( V_223 & ( V_611 | V_612 ) ) {
if ( V_3 -> V_48 & V_205 ) {
if ( ! ( V_223 & V_611 ) ) {
if ( V_188 <= 0x13 ) {
V_3 -> V_48 &=
~ ( V_586 |
V_205 |
V_204 ) ;
V_3 -> V_48 |=
V_202 |
V_575 ;
}
}
}
}
}
return 1 ;
}
unsigned char F_55 ( unsigned short V_188 ,
unsigned short * V_189 , struct V_2 * V_3 )
{
if ( V_188 <= 5 )
V_188 |= 1 ;
if ( V_188 <= 0x13 ) {
for ( * V_189 = 0 ; ; ( * V_189 ) ++ ) {
if ( V_3 -> V_4 [ * V_189 ] . V_613 ==
V_188 )
break;
if ( V_3 -> V_4 [ * V_189 ] . V_613 ==
0xFF )
return 0 ;
}
if ( V_188 == 0x07 )
( * V_189 ) ++ ;
if ( V_188 <= 3 )
( * V_189 ) += 2 ;
} else {
for ( * V_189 = 0 ; ; ( * V_189 ) ++ ) {
if ( V_3 -> V_10 [ * V_189 ] . V_614 ==
V_188 )
break;
if ( V_3 -> V_10 [ * V_189 ] . V_614 ==
0xFF )
return 0 ;
}
}
return 1 ;
}
static unsigned char F_56 ( unsigned char V_615 )
{
unsigned char V_616 = 0 ;
unsigned char V_196 = 0 ;
for ( V_196 = 0 ; V_196 < 8 ; V_196 ++ ) {
V_616 = V_616 << 1 ;
V_616 |= ( V_615 >> V_196 ) & 1 ;
}
return V_616 ;
}
static unsigned char F_57 ( struct V_2 * V_3 )
{
unsigned char V_617 , V_259 ;
V_617 = F_6 ( V_3 -> V_209 , 0x4A ) ;
F_14 ( V_3 -> V_209 , 0x4A , ~ 0x23 ) ;
V_259 = F_6 ( V_3 -> V_209 , 0x48 ) ;
V_259 = F_56 ( V_259 ) ;
V_259 &= 0x23 ;
F_4 ( V_3 -> V_209 , 0x4A , V_617 ) ;
return V_259 ;
}
static unsigned char F_58 ( struct V_2 * V_3 )
{
unsigned char V_617 , V_618 , V_259 ;
V_617 = F_6 ( V_3 -> V_209 , 0x4A ) ;
F_14 ( V_3 -> V_209 , 0x4A , ~ 0x0C ) ;
V_259 = F_6 ( V_3 -> V_209 , 0x48 ) ;
V_259 &= 0x0C ;
V_259 >>= 2 ;
F_4 ( V_3 -> V_209 , 0x4A , V_617 ) ;
V_618 = F_6 ( V_3 -> V_209 , 0xB4 ) ;
V_259 |= ( ( V_618 & 0x04 ) << 3 ) ;
return V_259 ;
}
static void F_59 ( unsigned short V_619 , unsigned short V_521 ,
struct V_2 * V_3 )
{
unsigned char V_617 , V_259 ;
V_617 = F_6 ( V_3 -> V_209 , 0x4A ) ;
V_619 &= 0x23 ;
V_521 &= 0x23 ;
F_14 ( V_3 -> V_209 , 0x4A , ~ V_619 ) ;
if ( V_619 & 0x20 ) {
V_259 = ( V_521 >> 4 ) & 0x02 ;
F_13 ( V_3 -> V_209 , 0xB4 , ~ 0x02 , V_259 ) ;
}
V_259 = F_6 ( V_3 -> V_209 , 0x48 ) ;
V_259 = F_56 ( V_259 ) ;
V_259 &= ~ V_619 ;
V_259 |= V_521 ;
F_4 ( V_3 -> V_209 , 0x48 , V_259 ) ;
}
static void F_60 ( unsigned short V_619 , unsigned short V_521 ,
struct V_2 * V_3 )
{
unsigned char V_617 , V_259 ;
unsigned short V_620 , V_621 ;
V_620 = V_619 ;
V_621 = V_521 ;
V_620 &= 0x20 ;
V_621 &= 0x20 ;
V_620 >>= 3 ;
V_621 >>= 3 ;
if ( V_619 & 0x20 ) {
V_259 = ( V_521 >> 4 ) & 0x02 ;
F_13 ( V_3 -> V_209 , 0xB4 , ~ 0x02 , V_259 ) ;
}
F_13 ( V_3 -> V_209 , 0xB4 , ~ V_620 , V_621 ) ;
V_617 = F_6 ( V_3 -> V_209 , 0x4A ) ;
V_619 &= 0x03 ;
V_521 &= 0x03 ;
V_619 <<= 2 ;
V_521 <<= 2 ;
F_14 ( V_3 -> V_209 , 0x4A , ~ V_619 ) ;
F_13 ( V_3 -> V_209 , 0x48 , ~ V_619 , V_521 ) ;
}
static void F_61 ( struct V_622 * V_623 ,
unsigned short V_521 ,
struct V_2 * V_3 )
{
if ( V_521 == 1 )
F_62 ( V_623 -> V_624 . V_625 ) ;
if ( V_521 == 2 )
F_62 ( V_623 -> V_624 . V_626 ) ;
if ( V_521 == 3 )
F_62 ( V_623 -> V_624 . V_627 ) ;
if ( V_521 == 4 )
F_62 ( V_623 -> V_624 . V_628 ) ;
}
static void F_63 ( struct V_622 * V_623 ,
struct V_206 * V_629 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_200 , 0x01 , 0xDF , 0x00 ) ;
if ( V_629 -> V_265 == V_335 ) {
if ( V_3 -> V_229 == 1 ) {
if ( ! ( F_57 ( V_3 ) & 0x1 ) ) {
F_59 ( 0x01 , 0x01 , V_3 ) ;
F_61 ( V_623 , 2 , V_3 ) ;
}
if ( ! ( F_57 ( V_3 ) & 0x20 ) )
F_59 ( 0x20 , 0x20 , V_3 ) ;
F_61 ( V_623 , 3 , V_3 ) ;
F_59 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_59 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_629 -> V_265 == V_162 ) {
if ( V_3 -> V_229 == 1 ) {
if ( ! ( F_58 ( V_3 ) & 0x1 ) ) {
F_60 ( 0x01 , 0x01 , V_3 ) ;
F_61 ( V_623 , 2 , V_3 ) ;
}
if ( ! ( F_58 ( V_3 ) & 0x20 ) )
F_60 ( 0x20 , 0x20 , V_3 ) ;
F_61 ( V_623 , 3 , V_3 ) ;
F_60 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_60 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_64 ( struct V_622 * V_623 ,
struct V_206 * V_629 ,
struct V_2 * V_3 )
{
if ( V_629 -> V_265 == V_335 ) {
if ( V_3 -> V_229 == 1 ) {
F_59 ( 0x02 , 0x00 , V_3 ) ;
F_61 ( V_623 , 3 , V_3 ) ;
} else {
F_59 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_629 -> V_265 == V_162 ) {
if ( ( F_58 ( V_3 ) & 0x2 ) ) {
F_60 ( 0x02 , 0x00 , V_3 ) ;
F_61 ( V_623 , 3 , V_3 ) ;
}
if ( V_3 -> V_229 == 0 )
F_60 ( 0x20 , 0x00 , V_3 ) ;
}
F_13 ( V_3 -> V_200 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
while ( ( F_8 ( V_3 -> V_214 ) & 0x01 ) )
break;
while ( ! ( F_8 ( V_3 -> V_214 ) & 0x01 ) )
break;
}
static void F_66 ( struct V_2 * V_3 )
{
F_21 ( V_3 -> V_536 , 0x01 , 0x40 ) ;
}
static void F_67 ( unsigned short V_188 ,
struct V_2 * V_3 )
{
unsigned short V_530 , V_298 ;
F_4 ( V_3 -> V_209 , 0x34 , V_188 ) ;
V_530 = ( V_3 -> V_48 & V_205 ) >> 8 ;
V_298 = ~ ( V_205 >> 8 ) ;
F_13 ( V_3 -> V_209 , 0x31 , V_298 , V_530 ) ;
}
static void F_68 ( unsigned short V_188 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_339 , V_362 , V_197 , V_289 ;
V_289 = F_26 ( V_188 , V_189 , V_3 ) ;
if ( V_188 <= 0x13 ) {
V_339 = V_3 -> V_33 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_33 [ V_289 ] . V_293 ;
} else {
V_339 = V_3 -> V_36 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_36 [ V_289 ] . V_293 ;
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
if ( V_197 & V_294 )
V_339 *= 2 ;
if ( V_197 & V_266 )
V_362 *= 2 ;
}
if ( V_3 -> V_48 & V_204 ) {
if ( V_3 -> V_229 == 0 ) {
if ( V_3 -> V_45 == V_630 ) {
if ( ! ( V_3 -> V_47 & V_610 ) ) {
if ( V_362 == 1024 )
V_362 = 1056 ;
}
}
if ( V_3 -> V_45 == V_235 ) {
if ( V_362 == 400 )
V_362 = 405 ;
else if ( V_362 == 350 )
V_362 = 360 ;
if ( V_3 -> V_47 & V_610 ) {
if ( V_362 == 360 )
V_362 = 375 ;
}
}
if ( V_3 -> V_45 == V_256 ) {
if ( ! ( V_3 -> V_47 & V_610 ) ) {
if ( ! ( V_3 -> V_47
& V_237 ) ) {
if ( V_362 == 350 )
V_362 = 357 ;
else if ( V_362 == 400 )
V_362 = 420 ;
else if ( V_362 == 480 )
V_362 = 525 ;
}
}
}
}
if ( V_339 == 720 )
V_339 = 640 ;
}
V_3 -> V_363 = V_339 ;
V_3 -> V_364 = V_339 ;
V_3 -> V_365 = V_362 ;
V_3 -> V_366 = V_362 ;
}
static unsigned char F_69 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_48 & ( V_204 | V_202 ) ) &&
( V_3 -> V_47 & V_608 ) )
return 1 ;
return 0 ;
}
static void F_70 ( unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_223 , V_224 , V_530 , V_298 , V_197 = 0 , V_291 ,
V_193 , V_631 ;
V_3 -> V_632 = 1 ;
V_3 -> V_633 = 1 ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_193 = F_2 ( V_188 , V_189 , V_3 ) ;
V_223 = V_3 -> V_7 [ V_193 ] . V_210 [ 0 ] ;
V_224 = V_3 -> V_7 [ V_193 ] . V_210 [ 6 ] ;
V_530 = V_3 -> V_7 [ V_193 ] . V_210 [ 7 ] ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_631 = V_3 -> V_13 [ V_222 ] .
V_267 ;
V_631 &= V_268 ;
V_530 = ( unsigned short ) V_3 ->
V_16 [ V_631 ] . V_269 [ 0 ] ;
V_298 = ( unsigned short ) V_3 ->
V_16 [ V_631 ] . V_269 [ 5 ] ;
V_223 = ( V_530 & 0xFF ) | ( ( V_298 & 0x03 ) << 8 ) ;
V_224 = ( unsigned short ) V_3 ->
V_16 [ V_631 ] . V_269 [ 8 ] ;
V_291 = ( unsigned short ) V_3 ->
V_16 [ V_631 ] . V_269 [ 14 ] << 8 ;
V_291 &= 0x0100 ;
V_291 = V_291 << 2 ;
V_224 |= V_291 ;
V_530 = ( unsigned short ) V_3 ->
V_16 [ V_631 ] . V_269 [ 9 ] ;
}
if ( V_530 & 0x01 )
V_224 |= 0x0100 ;
if ( V_530 & 0x20 )
V_224 |= 0x0200 ;
V_223 += 5 ;
if ( V_197 & V_213 )
V_223 *= 8 ;
else
V_223 *= 9 ;
V_3 -> V_508 = V_223 ;
V_3 -> V_510 = V_223 ;
V_224 ++ ;
V_3 -> V_509 = V_224 ;
V_3 -> V_512 = V_224 ;
}
static void F_71 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_223 = 0 , V_224 , V_197 , V_225 ;
struct V_634 * V_507 = NULL ;
struct V_635 * V_636 = NULL ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_225 = V_3 -> V_4 [ V_189 ] . V_290 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
}
V_3 -> V_637 = 0 ;
V_3 -> V_638 = 50 ;
if ( V_3 -> V_48 & V_230 ) {
F_70 ( V_188 , V_189 , V_222 ,
V_3 ) ;
return;
}
V_224 = 4 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
V_507 = (struct V_634 * ) F_38 ( V_224 ,
V_188 , V_189 , V_222 ,
V_3 ) ;
V_3 -> V_632 = V_507 -> V_632 ;
V_3 -> V_633 = V_507 -> V_633 ;
V_3 -> V_508 = V_507 -> V_508 ;
V_3 -> V_509 = V_507 -> V_509 ;
V_3 -> V_510 = V_507 -> V_511 ;
V_3 -> V_512 = V_507 -> V_513 ;
if ( V_3 -> V_45 == V_256 ) {
V_223 = 1024 ;
V_224 = 768 ;
if ( ! ( V_3 -> V_47 & V_610 ) ) {
if ( V_3 -> V_365 == 357 )
V_224 = 527 ;
else if ( V_3 -> V_365 == 420 )
V_224 = 620 ;
else if ( V_3 -> V_365 == 525 )
V_224 = 775 ;
else if ( V_3 -> V_365 == 600 )
V_224 = 775 ;
else
V_224 = 768 ;
} else
V_224 = 768 ;
} else if ( V_3 -> V_45 == V_331 ) {
V_223 = 1024 ;
V_224 = 768 ;
} else if ( V_3 -> V_45 == V_235 ) {
V_223 = 1280 ;
if ( V_3 -> V_365 == 360 )
V_224 = 768 ;
else if ( V_3 -> V_365 == 375 )
V_224 = 800 ;
else if ( V_3 -> V_365 == 405 )
V_224 = 864 ;
else
V_224 = 1024 ;
} else if ( V_3 -> V_45 == V_515 ) {
V_223 = 1280 ;
V_224 = 1024 ;
} else if ( V_3 -> V_45 == V_236 ) {
V_223 = 1280 ;
if ( V_3 -> V_365 == 350 )
V_224 = 700 ;
else if ( V_3 -> V_365 == 400 )
V_224 = 800 ;
else if ( V_3 -> V_365 == 1024 )
V_224 = 960 ;
else
V_224 = 960 ;
} else if ( V_3 -> V_45 == V_516 ) {
V_223 = 1400 ;
V_224 = 1050 ;
if ( V_3 -> V_365 == 1024 ) {
V_223 = 1280 ;
V_224 = 1024 ;
}
} else if ( V_3 -> V_45 == V_630 ) {
V_223 = 1600 ;
V_224 = 1200 ;
if ( ! ( V_3 -> V_47 & V_610 ) ) {
if ( V_3 -> V_365 == 350 )
V_224 = 875 ;
else if ( V_3 -> V_365 == 400 )
V_224 = 1000 ;
}
}
if ( V_3 -> V_47 & V_237 ) {
V_223 = V_3 -> V_363 ;
V_224 = V_3 -> V_365 ;
}
V_3 -> V_364 = V_223 ;
V_3 -> V_366 = V_224 ;
return;
}
if ( V_3 -> V_48 & ( V_203 ) ) {
V_224 = 4 ;
V_636 = (struct V_635 * ) F_39 ( V_224 ,
V_188 , V_189 , V_222 ,
V_3 ) ;
V_3 -> V_632 = V_636 -> V_632 ;
V_3 -> V_633 = V_636 -> V_633 ;
V_3 -> V_508 = V_636 -> V_508 ;
V_3 -> V_509 = V_636 -> V_509 ;
V_3 -> V_364 = V_636 -> V_639 ;
V_3 -> V_366 = V_636 -> V_640 ;
V_3 -> V_638 = V_636 -> V_638 ;
V_3 -> V_637 = V_636 -> V_641 ;
if ( V_3 -> V_48 & V_238 ) {
if ( V_225 == 0x08 )
V_3 -> V_637 = 0x40 ;
else if ( V_225 == 0x09 )
V_3 -> V_637 = 0x40 ;
else if ( V_225 == 0x12 )
V_3 -> V_637 = 0x40 ;
if ( V_3 -> V_365 == 350 )
V_3 -> V_49 |= V_244 ;
V_223 = V_642 ;
V_224 = V_643 ;
if ( V_3 -> V_48 & V_205 ) {
if ( V_3 -> V_49 & V_244 ) {
V_223 = V_644 ;
V_224 = V_645 ;
if ( ! ( V_197 & V_213 ) ) {
V_223 = V_646 ;
V_224 = V_647 ;
}
}
}
} else if ( V_3 -> V_48 & V_248 ) {
if ( V_3 -> V_49 & V_552 ) {
V_223 = V_648 ;
V_224 = V_649 ;
}
if ( V_3 -> V_49 & V_553 ) {
V_223 = V_650 ;
V_224 = V_651 ;
} else if ( V_3 -> V_49 & V_597 ) {
V_223 = V_652 ;
V_224 = V_653 ;
if ( V_3 -> V_49 & V_555 )
V_223 = V_654 ;
}
} else {
V_223 = V_655 ;
V_224 = V_656 ;
if ( ! ( V_3 -> V_49 & V_253 ) ) {
V_223 = V_657 ;
V_224 = V_658 ;
if ( V_3 -> V_49 & V_555 )
V_223 = V_654 ;
}
}
V_3 -> V_510 = V_223 ;
V_3 -> V_512 = V_224 ;
return;
}
}
static void F_72 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned char V_544 , V_545 , V_369 ;
V_369 = F_47 ( V_222 , V_188 , V_189 ,
V_3 ) ;
F_48 ( V_369 , & V_544 , & V_545 , V_3 ) ;
F_46 ( & V_544 , & V_545 , V_3 ) ;
if ( V_3 -> V_147 & V_556 ) {
F_4 ( V_3 -> V_543 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_543 , 0x0B , V_545 ) ;
F_4 ( V_3 -> V_543 , 0x0A , V_544 ) ;
} else {
F_4 ( V_3 -> V_543 , 0x0A , V_544 ) ;
F_4 ( V_3 -> V_543 , 0x0B , V_545 ) ;
}
F_4 ( V_3 -> V_543 , 0x00 , 0x12 ) ;
if ( V_3 -> V_48 & V_230 )
F_21 ( V_3 -> V_543 , 0x12 , 0x28 ) ;
else
F_21 ( V_3 -> V_543 , 0x12 , 0x08 ) ;
}
static unsigned short F_73 ( unsigned short V_188 ,
unsigned short V_189 , struct V_2 * V_3 )
{
unsigned short V_659 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_190 ;
unsigned short V_197 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_190 = ( V_197 & V_574 ) - V_301 ;
if ( V_190 < 0 )
V_190 = 0 ;
return V_659 [ V_190 ] ;
}
static unsigned short F_74 ( unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_259 , V_660 , V_661 , V_190 , V_226 ,
V_659 [] = { 0x01 , 0x02 , 0x04 } ;
V_661 = V_3 -> V_10 [ V_189 ] . V_300 ;
if ( V_188 <= 0x14 )
V_226 = 0 ;
else
V_226 = V_3 ->
V_13 [ V_222 ] . V_257 ;
V_190 = ( V_661 >> 8 ) & 0xFF ;
V_259 = V_3 -> V_31 [ V_190 ] ;
if ( V_226 & V_295 )
V_259 = V_259 << 1 ;
V_660 = F_73 ( V_188 , V_189 , V_3 ) ;
if ( ( V_188 >= 0x7C ) && ( V_188 <= 0x7E ) ) {
V_259 = V_188 - 0x7C ;
V_660 = V_659 [ V_259 ] ;
V_259 = 0x6B ;
if ( V_226 & V_295 )
V_259 = V_259 << 1 ;
return V_259 * V_660 ;
} else {
return V_259 * V_660 ;
}
}
static void F_75 ( unsigned short V_188 ,
unsigned short V_189 ,
unsigned short V_222 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_662 ;
unsigned char V_259 ;
if ( V_3 -> V_48 & V_205 )
return;
V_662 = F_74 ( V_188 , V_189 , V_222 ,
V_207 , V_3 ) ;
V_259 = ( unsigned char ) ( V_662 & 0xFF ) ;
F_4 ( V_3 -> V_536 , 0x07 , V_259 ) ;
V_259 = ( unsigned char ) ( ( V_662 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_536 , 0x09 , V_259 ) ;
V_259 = ( unsigned char ) ( ( ( V_662 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_536 , 0x03 , V_259 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_536 , 0x01 , 0x3B ) ;
F_13 ( V_3 -> V_536 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_77 ( unsigned short V_188 , unsigned short V_189 ,
struct V_206 * V_207 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_291 = 0 , V_631 = 0 , V_225 = 0 ;
if ( V_188 > 0x13 ) {
V_631 = V_3 ->
V_13 [ V_222 ] . V_267 ;
V_631 &= V_268 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
}
F_75 ( V_188 , V_189 , V_222 ,
V_207 , V_3 ) ;
F_76 ( V_3 ) ;
for ( V_291 = 4 ; V_291 < 7 ; V_291 ++ )
F_4 ( V_3 -> V_536 , V_291 , 0x0 ) ;
F_4 ( V_3 -> V_536 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_536 , 0x02 , 0x44 ) ;
}
static void F_78 ( unsigned short V_188 , unsigned short V_189 ,
struct V_206 * V_207 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_259 = 0 , V_223 = 0 , V_224 = 0 , V_291 = 0 ,
V_663 = 0 , V_631 = 0 , V_197 , V_225 = 0 ;
if ( V_188 > 0x13 ) {
V_631 = V_3 ->
V_13 [ V_222 ] . V_267 ;
V_631 &= V_268 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
}
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
if ( V_197 & V_294 ) {
V_259 = ( V_3 -> V_508 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_536 , 0x08 , V_259 ) ;
V_259 = ( ( ( V_3 -> V_508 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_13 ( V_3 -> V_536 , 0x09 , ~ 0x0F0 , V_259 ) ;
V_259 = ( V_3 -> V_363 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_536 , 0x0A , V_259 ) ;
V_291 = ( ( V_3 -> V_508 - V_3 -> V_363 ) / 2 ) >> 2 ;
V_663 = V_3 -> V_363 / 2 + 16 ;
V_291 = V_291 >> 1 ;
V_224 = V_663 + V_291 ;
V_291 += V_224 ;
if ( V_3 -> V_48 & V_230 ) {
V_224 = V_3 -> V_16 [ V_631 ] . V_269 [ 4 ] ;
V_224 |= ( ( V_3 ->
V_16 [ V_631 ] . V_269 [ 14 ] &
0xC0 ) << 2 ) ;
V_224 = ( V_224 - 3 ) << 3 ;
V_291 = V_3 -> V_16 [ V_631 ] . V_269 [ 5 ] ;
V_291 &= 0x1F ;
V_259 = V_3 -> V_16 [ V_631 ] . V_269 [ 15 ] ;
V_259 = ( V_259 & 0x04 ) << ( 5 - 2 ) ;
V_291 = ( ( V_291 | V_259 ) - 3 ) << 3 ;
}
V_224 += 4 ;
V_291 += 4 ;
if ( V_291 > ( V_3 -> V_508 / 2 ) )
V_291 = V_3 -> V_508 / 2 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0B , V_259 ) ;
} else {
V_259 = ( V_3 -> V_508 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_536 , 0x08 , V_259 ) ;
V_259 = ( ( ( V_3 -> V_508 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_13 ( V_3 -> V_536 , 0x09 , ~ 0x0F0 , V_259 ) ;
V_259 = ( V_3 -> V_363 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_536 , 0x0A , V_259 ) ;
V_291 = ( V_3 -> V_508 - V_3 -> V_363 ) >> 2 ;
V_663 = V_3 -> V_363 + 16 ;
V_291 = V_291 >> 1 ;
V_224 = V_663 + V_291 ;
V_291 += V_224 ;
if ( V_3 -> V_48 & V_230 ) {
V_224 = V_3 -> V_16 [ V_631 ] . V_269 [ 3 ] ;
V_224 |= ( ( V_3 ->
V_16 [ V_631 ] . V_269 [ 5 ] &
0xC0 ) << 2 ) ;
V_224 = ( V_224 - 3 ) << 3 ;
V_291 = V_3 -> V_16 [ V_631 ] . V_269 [ 4 ] ;
V_291 &= 0x1F ;
V_259 = V_3 -> V_16 [ V_631 ] . V_269 [ 6 ] ;
V_259 = ( V_259 & 0x04 ) << ( 5 - 2 ) ;
V_291 = ( ( V_291 | V_259 ) - 3 ) << 3 ;
V_224 += 16 ;
V_291 += 16 ;
}
if ( V_291 > V_3 -> V_508 )
V_291 = V_3 -> V_508 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0B , V_259 ) ;
}
V_223 = ( V_223 & 0x00FF ) | ( V_224 & 0xFF00 ) ;
V_224 = V_663 ;
V_224 = ( V_224 & 0x00FF ) | ( ( V_224 & 0xFF00 ) << 4 ) ;
V_223 |= ( V_224 & 0xFF00 ) ;
V_259 = ( V_223 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_536 , 0x0C , V_259 ) ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0D , V_259 ) ;
V_291 = ( V_3 -> V_509 - 1 ) ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0E , V_259 ) ;
V_224 = V_3 -> V_365 - 1 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0F , V_259 ) ;
V_259 = ( ( V_224 & 0xFF00 ) << 3 ) >> 8 ;
V_259 |= ( ( V_291 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_536 , 0x12 , V_259 ) ;
V_223 = V_3 -> V_365 ;
V_224 = V_3 -> V_365 ;
V_291 = V_3 -> V_509 ;
V_224 = ( V_3 -> V_509 + V_3 -> V_365 ) >> 1 ;
V_291 = ( ( V_3 -> V_509 - V_3 -> V_365 ) >> 4 ) + V_224 + 1 ;
if ( V_3 -> V_48 & V_230 ) {
V_224 = V_3 -> V_16 [ V_631 ] . V_269 [ 10 ] ;
V_259 = V_3 -> V_16 [ V_631 ] . V_269 [ 9 ] ;
if ( V_259 & 0x04 )
V_224 |= 0x0100 ;
if ( V_259 & 0x080 )
V_224 |= 0x0200 ;
V_259 = V_3 -> V_16 [ V_631 ] . V_269 [ 14 ] ;
if ( V_259 & 0x08 )
V_224 |= 0x0400 ;
V_259 = V_3 -> V_16 [ V_631 ] . V_269 [ 11 ] ;
V_291 = ( V_291 & 0xFF00 ) | ( V_259 & 0x00FF ) ;
}
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x10 , V_259 ) ;
V_259 = ( ( V_224 & 0xFF00 ) >> 8 ) << 4 ;
V_259 = ( ( V_291 & 0x000F ) | ( V_259 ) ) ;
F_4 ( V_3 -> V_536 , 0x11 , V_259 ) ;
V_223 = 0 ;
if ( V_197 & V_266 )
V_223 |= 0x80 ;
if ( V_197 & V_294 )
V_223 |= 0x40 ;
F_13 ( V_3 -> V_536 , 0x2C , ~ 0x0C0 , V_223 ) ;
}
static unsigned short F_79 ( struct V_2 * V_3 )
{
unsigned long V_223 , V_224 ;
V_224 = ( ( V_3 -> V_509 - V_3 -> V_365 ) * V_3 -> V_632 )
& 0xFFFF ;
V_223 = ( V_3 -> V_512 - V_3 -> V_366 ) * V_3 -> V_633 ;
V_223 = ( V_223 * V_3 -> V_510 ) / V_224 ;
return ( unsigned short ) V_223 ;
}
static void F_80 ( unsigned short V_188 , unsigned short V_189 ,
struct V_206 * V_207 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_528 , V_529 , V_223 , V_224 = 0 , V_291 , V_259 , V_225 ,
V_197 , V_631 ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_225 = V_3 -> V_4 [ V_189 ] . V_290 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
V_631 = V_3 ->
V_13 [ V_222 ] . V_267 ;
V_631 &= V_268 ;
}
if ( ! ( V_3 -> V_48 & V_205 ) )
return;
V_259 = 0xFF ;
F_4 ( V_3 -> V_536 , 0x03 , V_259 ) ;
V_291 = 0x08 ;
if ( V_3 -> V_147 & ( V_148 | V_149 | V_232 ) )
V_197 |= V_213 ;
V_223 = V_3 -> V_363 ;
if ( V_197 & V_294 )
V_223 = V_223 >> 1 ;
V_223 = ( V_223 / V_291 ) - 1 ;
V_224 |= ( ( V_223 & 0x00FF ) << 8 ) ;
V_259 = V_223 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x04 , V_259 ) ;
V_259 = ( V_224 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_48 & V_203 ) {
if ( ! ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) )
V_259 += 2 ;
if ( V_3 -> V_48 & V_238 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_239 == V_240 ) {
if ( V_225 == 7 )
V_259 -= 2 ;
}
} else if ( V_225 == 7 ) {
V_259 -= 2 ;
}
}
}
F_4 ( V_3 -> V_536 , 0x05 , V_259 ) ;
F_4 ( V_3 -> V_536 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_48 & V_576 ) ) {
if ( V_3 -> V_48 & V_203 )
V_223 = V_3 -> V_508 ;
else
V_223 = F_79 ( V_3 ) ;
}
if ( V_223 >= V_3 -> V_508 )
V_223 = V_3 -> V_508 ;
if ( V_197 & V_294 )
V_223 = V_223 >> 1 ;
V_223 = ( V_223 / V_291 ) - 5 ;
V_291 = V_223 ;
if ( V_3 -> V_48 & V_238 ) {
V_259 = ( V_224 & 0x00FF ) - 1 ;
if ( ! ( V_197 & V_294 ) ) {
V_259 -= 6 ;
if ( V_3 -> V_49 & V_244 ) {
V_259 -= 4 ;
if ( V_188 > 0x13 )
V_259 -= 10 ;
}
}
} else {
V_224 = ( V_224 & 0xFF00 ) >> 8 ;
V_291 = ( V_291 + V_224 ) >> 1 ;
V_259 = ( V_291 & 0x00FF ) + 2 ;
if ( V_3 -> V_48 & V_203 ) {
V_259 -= 1 ;
if ( ! ( V_197 & V_294 ) ) {
if ( ( V_197 & V_213 ) ) {
V_259 += 4 ;
if ( V_3 -> V_363 >= 800 )
V_259 -= 6 ;
}
}
} else if ( ! ( V_197 & V_294 ) ) {
V_259 -= 4 ;
if ( V_3 -> V_45 != V_236 &&
V_3 -> V_363 >= 800 ) {
V_259 -= 7 ;
if ( V_3 -> V_192 == V_301 &&
V_3 -> V_365 == 1024 ) {
V_259 += 15 ;
if ( V_3 -> V_45 !=
V_235 )
V_259 += 7 ;
}
if ( V_3 -> V_363 >= 1280 &&
V_3 -> V_45 != V_236 &&
( V_3 -> V_47 & V_237 ) )
V_259 += 28 ;
}
}
}
F_4 ( V_3 -> V_536 , 0x07 , V_259 ) ;
F_4 ( V_3 -> V_536 , 0x08 , 0 ) ;
if ( V_3 -> V_48 & V_203 ) {
if ( V_3 -> V_49 & V_244 ) {
if ( ( V_188 == 0x06 ) || ( V_188 == 0x10 ) || ( V_188
== 0x11 ) || ( V_188 == 0x13 ) || ( V_188
== 0x0F ) ) {
F_4 ( V_3 -> V_536 , 0x07 , 0x5b ) ;
F_4 ( V_3 -> V_536 , 0x08 , 0x03 ) ;
}
if ( ( V_188 == 0x00 ) || ( V_188 == 0x01 ) ) {
if ( V_3 -> V_49 & V_664 ) {
F_4 ( V_3 -> V_536 ,
0x07 , 0x2A ) ;
F_4 ( V_3 -> V_536 ,
0x08 , 0x61 ) ;
} else {
F_4 ( V_3 -> V_536 ,
0x07 , 0x2A ) ;
F_4 ( V_3 -> V_536 ,
0x08 , 0x41 ) ;
F_4 ( V_3 -> V_536 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_188 == 0x02 ) || ( V_188 == 0x03 ) || ( V_188
== 0x07 ) ) {
if ( V_3 -> V_49 & V_664 ) {
F_4 ( V_3 -> V_536 ,
0x07 , 0x54 ) ;
F_4 ( V_3 -> V_536 ,
0x08 , 0x00 ) ;
} else {
F_4 ( V_3 -> V_536 ,
0x07 , 0x55 ) ;
F_4 ( V_3 -> V_536 ,
0x08 , 0x00 ) ;
F_4 ( V_3 -> V_536 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_188 == 0x04 ) || ( V_188 == 0x05 ) || ( V_188
== 0x0D ) || ( V_188 == 0x50 ) ) {
if ( V_3 -> V_49 & V_664 ) {
F_4 ( V_3 -> V_536 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_536 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_536 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_536 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_536 , 0x18 , 0x03 ) ;
F_13 ( V_3 -> V_536 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_536 , 0x09 , 0xFF ) ;
V_224 = V_3 -> V_509 ;
V_528 = V_224 ;
V_291 = 0x121 ;
V_224 = V_3 -> V_365 ;
if ( V_224 == 357 )
V_224 = 350 ;
if ( V_224 == 360 )
V_224 = 350 ;
if ( V_224 == 375 )
V_224 = 350 ;
if ( V_224 == 405 )
V_224 = 400 ;
if ( V_224 == 525 )
V_224 = 480 ;
V_529 = V_224 ;
if ( V_3 -> V_48 & V_204 ) {
if ( V_3 -> V_45 == V_256 ) {
if ( ! ( V_3 -> V_47 & V_610 ) ) {
if ( V_224 == 350 )
V_224 += 5 ;
if ( V_224 == 480 )
V_224 += 5 ;
}
}
}
V_224 -- ;
V_259 = V_224 & 0x00FF ;
V_224 -- ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x10 , V_259 ) ;
V_224 = V_529 ;
V_224 -- ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0E , V_259 ) ;
if ( V_224 & 0x0100 )
V_291 |= 0x0002 ;
V_223 = 0x000B ;
if ( V_197 & V_266 )
V_223 |= 0x08000 ;
if ( V_224 & 0x0200 )
V_291 |= 0x0040 ;
V_259 = ( V_223 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_536 , 0x0B , V_259 ) ;
if ( V_224 & 0x0400 )
V_291 |= 0x0600 ;
F_4 ( V_3 -> V_536 , 0x11 , 0x00 ) ;
V_223 = V_528 ;
V_223 -= V_224 ;
V_223 = V_223 >> 2 ;
V_528 = V_223 ;
if ( V_225 != 0x09 ) {
V_223 = V_223 << 1 ;
V_224 += V_223 ;
}
if ( V_3 -> V_48 & V_238 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_600 ) {
V_224 -= 10 ;
} else {
if ( V_3 -> V_49 & V_244 ) {
if ( V_3 -> V_49 & V_253 ) {
if ( V_3 -> V_147 &
V_148 ) {
if ( ! ( V_3 -> V_49 &
( V_553 |
V_552 |
V_600 ) ) )
V_224 += 40 ;
} else {
V_224 += 40 ;
}
}
}
}
} else {
V_224 -= 10 ;
}
} else {
if ( V_3 -> V_49 & V_244 ) {
if ( V_3 -> V_49 & V_253 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( ! ( V_3 -> V_49 &
( V_553 |
V_552 |
V_600 ) ) )
V_224 += 40 ;
} else {
V_224 += 40 ;
}
}
}
}
V_223 = V_528 ;
V_223 = V_223 >> 2 ;
V_223 ++ ;
V_223 += V_224 ;
V_528 = V_223 ;
if ( ( V_3 -> V_49 & V_253 ) ) {
if ( V_224 <= 513 ) {
if ( V_223 >= 513 )
V_224 = 513 ;
}
}
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0C , V_259 ) ;
V_224 -- ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x10 , V_259 ) ;
if ( V_224 & 0x0100 )
V_291 |= 0x0008 ;
if ( V_224 & 0x0200 )
F_13 ( V_3 -> V_536 , 0x0B , 0x0FF , 0x20 ) ;
V_224 ++ ;
if ( V_224 & 0x0100 )
V_291 |= 0x0004 ;
if ( V_224 & 0x0200 )
V_291 |= 0x0080 ;
if ( V_224 & 0x0400 )
V_291 |= 0x0C00 ;
V_224 = V_528 ;
V_259 = V_224 & 0x00FF ;
V_259 &= 0x0F ;
F_4 ( V_3 -> V_536 , 0x0D , V_259 ) ;
if ( V_224 & 0x0010 )
V_291 |= 0x2000 ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_536 , 0x0A , V_259 ) ;
V_259 = ( V_291 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_536 , 0x17 , V_259 ) ;
V_223 = V_197 ;
V_259 = ( V_223 & 0xFF00 ) >> 8 ;
V_259 = ( V_259 >> 1 ) & 0x09 ;
if ( V_3 -> V_147 & ( V_148 | V_149 | V_232 ) )
V_259 |= 0x01 ;
F_4 ( V_3 -> V_536 , 0x16 , V_259 ) ;
F_4 ( V_3 -> V_536 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_536 , 0x12 , 0 ) ;
if ( V_3 -> V_47 & V_665 )
V_259 = 0x80 ;
else
V_259 = 0x00 ;
F_4 ( V_3 -> V_536 , 0x1A , V_259 ) ;
return;
}
static void F_81 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_196 , V_264 , V_223 , V_224 , V_291 , V_259 , V_528 , V_529 ,
V_197 , V_225 , V_666 ;
unsigned char * V_667 ;
unsigned long V_668 , V_669 , V_670 , V_298 , V_671 ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_225 = V_3 -> V_4 [ V_189 ] . V_290 ;
V_666 = V_3 -> V_4 [ V_189 ] . V_312 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
V_666 = V_3 -> V_13 [ V_222 ] .
V_313 ;
}
V_223 = 0 ;
if ( ! ( V_3 -> V_48 & V_245 ) )
V_223 |= 0x0800 ;
if ( ! ( V_3 -> V_48 & V_246 ) )
V_223 |= 0x0400 ;
if ( V_3 -> V_48 & V_247 )
V_223 |= 0x0200 ;
if ( ! ( V_3 -> V_49 & V_253 ) )
V_223 |= 0x1000 ;
if ( V_3 -> V_48 & V_238 )
V_223 |= 0x0100 ;
if ( V_3 -> V_49 & ( V_553 | V_552 ) )
V_223 &= 0xfe00 ;
V_223 = ( V_223 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_562 , 0x0 , V_223 ) ;
V_667 = V_3 -> V_110 ;
if ( V_3 -> V_49 & V_253 )
V_667 = V_3 -> V_112 ;
if ( V_3 -> V_48 & V_238 ) {
V_667 = V_3 -> V_114 ;
if ( V_3 -> V_48 & V_205 )
V_667 = V_3 -> V_118 ;
if ( V_3 -> V_243 & V_244 )
V_667 = V_3 -> V_116 ;
if ( ! ( V_197 & V_213 ) )
V_667 = V_3 -> V_120 ;
}
if ( V_3 -> V_48 & V_248 ) {
if ( V_3 -> V_49 & V_597 )
V_667 = V_3 -> V_126 ;
if ( V_3 -> V_49 & V_553 )
V_667 = V_3 -> V_124 ;
if ( V_3 -> V_49 & V_552 )
V_667 = V_3 -> V_122 ;
}
for ( V_196 = 0x01 , V_264 = 0 ; V_196 <= 0x2D ; V_196 ++ , V_264 ++ )
F_4 ( V_3 -> V_562 , V_196 , V_667 [ V_264 ] ) ;
for ( V_196 = 0x39 ; V_196 <= 0x45 ; V_196 ++ , V_264 ++ )
F_4 ( V_3 -> V_562 , V_196 , V_667 [ V_264 ] ) ;
if ( V_3 -> V_48 & V_203 )
F_13 ( V_3 -> V_562 , 0x3A , 0x1F , 0x00 ) ;
V_259 = V_3 -> V_637 ;
V_259 &= 0x80 ;
F_13 ( V_3 -> V_562 , 0x0A , 0xFF , V_259 ) ;
if ( V_3 -> V_48 & V_238 )
V_223 = 950 ;
if ( V_3 -> V_49 & V_253 )
V_223 = 520 ;
else
V_223 = 440 ;
if ( V_3 -> V_366 <= V_223 ) {
V_223 -= V_3 -> V_366 ;
V_223 = V_223 >> 2 ;
V_223 = ( V_223 & 0x00FF ) | ( ( V_223 & 0x00FF ) << 8 ) ;
V_528 = V_223 ;
V_259 = ( V_223 & 0xFF00 ) >> 8 ;
V_259 += ( unsigned short ) V_667 [ 0 ] ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
if ( V_3 -> V_48 & ( V_245
| V_246 | V_247
| V_248 ) ) {
V_291 = V_3 -> V_363 ;
if ( V_291 >= 1024 ) {
V_259 = 0x17 ;
if ( V_3 -> V_49 & V_253 )
V_259 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_562 , 0x01 , V_259 ) ;
V_223 = V_528 ;
V_259 = ( V_223 & 0xFF00 ) >> 8 ;
V_259 += V_667 [ 1 ] ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
if ( ( V_3 -> V_48 & ( V_245
| V_246 | V_247
| V_248 ) ) ) {
V_291 = V_3 -> V_363 ;
if ( V_291 >= 1024 ) {
V_259 = 0x1D ;
if ( V_3 -> V_49 & V_253 )
V_259 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_562 , 0x02 , V_259 ) ;
}
V_291 = V_3 -> V_510 ;
if ( F_69 ( V_3 ) )
V_291 = V_291 >> 1 ;
V_291 -= 2 ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x1B , V_259 ) ;
V_259 = ( V_291 & 0xFF00 ) >> 8 ;
F_13 ( V_3 -> V_562 , 0x1D , ~ 0x0F , V_259 ) ;
V_291 = V_3 -> V_510 >> 1 ;
V_528 = V_291 ;
V_291 += 7 ;
if ( V_3 -> V_48 & V_238 )
V_291 -= 4 ;
V_259 = V_291 & 0x00FF ;
V_259 = V_259 << 4 ;
F_13 ( V_3 -> V_562 , 0x22 , 0x0F , V_259 ) ;
V_224 = V_667 [ V_264 ] | ( ( V_667 [ V_264 + 1 ] ) << 8 ) ;
V_224 += V_291 ;
V_529 = V_224 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x24 , V_259 ) ;
V_259 = ( V_224 & 0xFF00 ) >> 8 ;
V_259 = V_259 << 4 ;
F_13 ( V_3 -> V_562 , 0x25 , 0x0F , V_259 ) ;
V_224 = V_529 ;
V_224 = V_224 + 8 ;
if ( V_3 -> V_48 & V_238 ) {
V_224 = V_224 - 4 ;
V_291 = V_224 ;
}
V_259 = ( V_224 & 0x00FF ) << 4 ;
F_13 ( V_3 -> V_562 , 0x29 , 0x0F , V_259 ) ;
V_264 += 2 ;
V_291 += ( V_667 [ V_264 ] | ( ( V_667 [ V_264 + 1 ] ) << 8 ) ) ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x27 , V_259 ) ;
V_259 = ( ( V_291 & 0xFF00 ) >> 8 ) << 4 ;
F_13 ( V_3 -> V_562 , 0x28 , 0x0F , V_259 ) ;
V_291 += 8 ;
if ( V_3 -> V_48 & V_238 )
V_291 -= 4 ;
V_259 = V_291 & 0xFF ;
V_259 = V_259 << 4 ;
F_13 ( V_3 -> V_562 , 0x2A , 0x0F , V_259 ) ;
V_291 = V_528 ;
V_264 += 2 ;
V_259 = V_667 [ V_264 ] | ( ( V_667 [ V_264 + 1 ] ) << 8 ) ;
V_291 -= V_259 ;
V_259 = V_291 & 0x00FF ;
V_259 = V_259 << 4 ;
F_13 ( V_3 -> V_562 , 0x2D , 0x0F , V_259 ) ;
V_291 -= 11 ;
if ( ! ( V_3 -> V_48 & V_203 ) ) {
V_223 = F_79 ( V_3 ) ;
V_291 = V_223 - 1 ;
}
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x2E , V_259 ) ;
V_224 = V_3 -> V_366 ;
if ( V_3 -> V_365 == 360 )
V_224 = 746 ;
if ( V_3 -> V_365 == 375 )
V_224 = 746 ;
if ( V_3 -> V_365 == 405 )
V_224 = 853 ;
if ( V_3 -> V_48 & V_203 ) {
if ( V_3 -> V_147 &
( V_148 | V_149 | V_232 ) ) {
if ( ! ( V_3 -> V_49 &
( V_553 | V_552 ) ) )
V_224 = V_224 >> 1 ;
} else
V_224 = V_224 >> 1 ;
}
V_224 -= 2 ;
V_259 = V_224 & 0x00FF ;
if ( V_3 -> V_48 & V_238 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_600 ) {
if ( V_3 -> V_48 & V_205 ) {
if ( V_188 == 0x2f )
V_259 += 1 ;
}
}
} else {
if ( V_3 -> V_48 & V_205 ) {
if ( V_188 == 0x2f )
V_259 += 1 ;
}
}
}
F_4 ( V_3 -> V_562 , 0x2F , V_259 ) ;
V_259 = ( V_291 & 0xFF00 ) >> 8 ;
V_259 |= ( ( V_224 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_48 & V_238 ) ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_600 ) {
V_259 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_246 ) )
V_259 |= 0x20 ;
}
} else {
V_259 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_246 ) )
V_259 |= 0x20 ;
}
}
F_4 ( V_3 -> V_562 , 0x30 , V_259 ) ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
V_224 = V_3 -> V_366 ;
V_291 = V_224 - 2 ;
if ( V_3 -> V_48 & V_203 ) {
if ( ! ( V_3 -> V_49 & ( V_553
| V_552 ) ) )
V_224 = V_224 >> 1 ;
}
if ( V_3 -> V_147 & ( V_149 | V_232 ) ) {
V_259 = 0 ;
if ( V_291 & 0x0400 )
V_259 |= 0x20 ;
if ( V_224 & 0x0400 )
V_259 |= 0x40 ;
F_4 ( V_3 -> V_543 , 0x10 , V_259 ) ;
}
V_259 = ( ( ( V_224 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_562 , 0x46 , V_259 ) ;
V_259 = ( V_224 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x47 , V_259 ) ;
}
V_224 = V_224 & 0x00FF ;
if ( ! ( V_197 & V_294 ) ) {
V_291 = V_3 -> V_363 ;
if ( V_291 >= V_3 -> V_364 ) {
V_224 |= 0x2000 ;
V_223 &= 0x00FF ;
}
}
V_291 = 0x0101 ;
if ( V_3 -> V_48 & V_203 ) {
if ( V_3 -> V_363 >= 1024 ) {
V_291 = 0x1920 ;
if ( V_3 -> V_363 >= 1280 ) {
V_291 = 0x1420 ;
V_224 = V_224 & 0xDFFF ;
}
}
}
if ( ! ( V_224 & 0x2000 ) ) {
if ( V_197 & V_294 )
V_291 = ( V_291 & 0xFF00 ) | ( ( V_291 & 0x00FF ) << 1 ) ;
V_528 = V_224 ;
V_669 = V_3 -> V_363 ;
V_670 = ( V_291 & 0xFF00 ) >> 8 ;
V_668 = V_669 * V_670 ;
V_671 = V_291 & 0x00FF ;
V_668 = V_668 / V_671 ;
V_671 = 8 * 1024 ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
V_671 = V_671 * 8 ;
}
V_668 = V_668 * V_671 ;
V_671 = V_3 -> V_364 ;
V_298 = V_668 % V_671 ;
V_669 = V_668 / V_671 ;
if ( V_298 != 0 )
V_669 += 1 ;
V_223 = ( unsigned short ) V_669 ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
V_291 = ( ( V_223 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_224 = V_528 ;
V_224 = ( unsigned short ) ( ( ( V_669 & 0x0000FF00 ) & 0x1F00 )
| ( V_224 & 0x00FF ) ) ;
V_223 = ( unsigned short ) ( ( ( V_669 & 0x000000FF ) << 8 )
| ( V_223 & 0x00FF ) ) ;
V_259 = ( V_223 & 0xFF00 ) >> 8 ;
} else {
V_259 = ( V_223 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_562 , 0x44 , V_259 ) ;
V_259 = ( V_224 & 0xFF00 ) >> 8 ;
F_13 ( V_3 -> V_562 , 0x45 , ~ 0x03F , V_259 ) ;
V_259 = V_291 & 0x00FF ;
if ( V_224 & 0x2000 )
V_259 = 0 ;
if ( ! ( V_3 -> V_48 & V_204 ) )
V_259 |= 0x18 ;
F_13 ( V_3 -> V_562 , 0x46 , ~ 0x1F , V_259 ) ;
if ( V_3 -> V_49 & V_253 ) {
V_224 = 0x0382 ;
V_291 = 0x007e ;
} else {
V_224 = 0x0369 ;
V_291 = 0x0061 ;
}
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x4b , V_259 ) ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x4c , V_259 ) ;
V_259 = ( ( V_291 & 0xFF00 ) >> 8 ) & 0x03 ;
V_259 = V_259 << 2 ;
V_259 |= ( ( V_224 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_48 & V_248 ) {
V_259 |= 0x10 ;
if ( V_3 -> V_49 & V_553 )
V_259 |= 0x20 ;
if ( V_3 -> V_49 & V_552 )
V_259 |= 0x60 ;
}
F_4 ( V_3 -> V_562 , 0x4d , V_259 ) ;
V_259 = F_6 ( V_3 -> V_562 , 0x43 ) ;
F_4 ( V_3 -> V_562 , 0x43 , ( unsigned short ) ( V_259 - 3 ) ) ;
if ( ! ( V_3 -> V_49 & ( V_553 | V_552 ) ) ) {
if ( V_3 -> V_49 & V_555 ) {
V_667 = V_672 ;
for ( V_196 = 0x1c , V_264 = 0 ; V_196 <= 0x30 ; V_196 ++ , V_264 ++ ) {
F_4 ( V_3 -> V_562 , V_196 ,
V_667 [ V_264 ] ) ;
}
F_4 ( V_3 -> V_562 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_147 & V_232 ) {
if ( V_3 -> V_49 & V_593 )
F_13 ( V_3 -> V_562 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_49 & V_593 ) {
V_223 = ( unsigned char ) F_6 ( V_3 -> V_562 ,
0x01 ) ;
V_223 -- ;
F_14 ( V_3 -> V_562 , 0x01 , V_223 ) ;
F_14 ( V_3 -> V_562 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_48 & V_238 ) {
if ( ! ( V_3 -> V_48 & V_205 ) )
F_4 ( V_3 -> V_562 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_48 & V_203 )
return;
}
static void F_82 ( unsigned short V_188 , unsigned short V_189 ,
struct V_206 * V_207 ,
unsigned short V_222 ,
struct V_2 * V_3 )
{
unsigned short V_528 , V_529 , V_663 , V_223 , V_224 , V_291 , V_259 ,
V_194 , V_619 , V_558 , V_225 , V_197 , V_631 ;
struct V_673 * V_674 = NULL ;
if ( V_188 <= 0x13 ) {
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
V_225 = V_3 -> V_4 [ V_189 ] . V_290 ;
} else {
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_225 = V_3 -> V_10 [ V_189 ] . V_227 ;
V_631 = V_3 -> V_13 [ V_222 ] .
V_267 ;
V_631 &= V_268 ;
}
if ( ! ( V_3 -> V_48 & V_204 ) )
return;
V_224 = V_3 -> V_364 ;
if ( F_69 ( V_3 ) )
V_224 = V_224 >> 1 ;
V_224 -= 1 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x2C , V_259 ) ;
V_259 = ( V_224 & 0xFF00 ) >> 8 ;
V_259 = V_259 << 4 ;
F_13 ( V_3 -> V_562 , 0x2B , 0x0F , V_259 ) ;
V_259 = 0x01 ;
if ( V_3 -> V_45 == V_235 ) {
if ( V_3 -> V_192 == V_301 ) {
if ( V_3 -> V_363 >= 1024 ) {
V_259 = 0x02 ;
if ( V_3 -> V_47 & V_610 )
V_259 = 0x01 ;
}
}
}
F_4 ( V_3 -> V_562 , 0x0B , V_259 ) ;
V_224 = V_3 -> V_366 ;
V_528 = V_224 ;
V_224 -- ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x03 , V_259 ) ;
V_259 = ( ( V_224 & 0xFF00 ) >> 8 ) & 0x07 ;
F_13 ( V_3 -> V_562 , 0x0C , ~ 0x07 , V_259 ) ;
V_291 = V_3 -> V_512 - 1 ;
V_529 = V_291 + 1 ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x19 , V_259 ) ;
V_259 = ( V_291 & 0xFF00 ) >> 8 ;
V_259 = V_259 << 5 ;
F_4 ( V_3 -> V_562 , 0x1A , V_259 ) ;
F_13 ( V_3 -> V_562 , 0x09 , 0xF0 , 0x00 ) ;
F_13 ( V_3 -> V_562 , 0x0A , 0xF0 , 0x00 ) ;
F_13 ( V_3 -> V_562 , 0x17 , 0xFB , 0x00 ) ;
F_13 ( V_3 -> V_562 , 0x18 , 0xDF , 0x00 ) ;
V_224 = 5 ;
V_674 = (struct V_673 * ) F_38 ( V_224 , V_188 ,
V_189 , V_222 , V_3 ) ;
V_194 = V_3 -> V_45 ;
V_194 &= V_385 ;
if ( ( V_194 == V_256 ) || ( V_194 == V_331 ) ) {
V_224 = 1024 ;
V_291 = 768 ;
} else if ( ( V_194 == V_235 ) ||
( V_194 == V_515 ) ) {
V_224 = 1280 ;
V_291 = 1024 ;
} else if ( V_194 == V_516 ) {
V_224 = 1400 ;
V_291 = 1050 ;
} else {
V_224 = 1600 ;
V_291 = 1200 ;
}
if ( V_3 -> V_47 & V_375 ) {
V_224 = V_3 -> V_364 ;
V_291 = V_3 -> V_366 ;
}
V_663 = V_224 ;
V_223 = V_3 -> V_512 ;
V_3 -> V_535 = V_674 -> V_535 ;
V_3 -> V_537 = V_674 -> V_537 ;
V_3 -> V_539 = V_674 -> V_539 ;
V_3 -> V_540 = V_674 -> V_540 ;
V_224 = V_3 -> V_539 ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x05 , V_259 ) ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x06 , V_259 ) ;
V_558 = ( ( V_291 & 0xFF00 ) >> 8 ) & 0x07 ;
V_619 = ( ( V_224 & 0xFF00 ) >> 8 ) & 0x07 ;
V_194 = V_558 ;
V_194 = V_194 << 3 ;
V_194 |= V_619 ;
F_4 ( V_3 -> V_562 , 0x02 , V_194 ) ;
F_44 ( & V_223 , & V_224 , V_3 ) ;
V_291 = V_224 ;
V_223 = V_3 -> V_512 ;
V_224 = V_3 -> V_540 ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x04 , V_259 ) ;
V_259 = ( V_224 & 0xFF00 ) >> 8 ;
V_259 = V_259 << 4 ;
V_259 |= ( V_291 & 0x000F ) ;
F_4 ( V_3 -> V_562 , 0x01 , V_259 ) ;
V_291 = V_663 ;
V_223 = V_3 -> V_510 ;
V_224 = V_3 -> V_535 ;
V_224 &= 0x0FFF ;
if ( F_69 ( V_3 ) ) {
V_223 = V_223 >> 1 ;
V_224 = V_224 >> 1 ;
V_291 = V_291 >> 1 ;
}
if ( V_3 -> V_147 & V_149 )
V_224 += 1 ;
if ( V_3 -> V_147 & V_232 )
V_224 += 1 ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x1F , V_259 ) ;
V_259 = ( ( V_224 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_562 , 0x20 , V_259 ) ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x23 , V_259 ) ;
V_259 = ( V_291 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_562 , 0x25 , V_259 ) ;
F_44 ( & V_223 , & V_224 , V_3 ) ;
V_291 = V_223 ;
V_223 = V_3 -> V_510 ;
V_224 = V_3 -> V_537 ;
if ( F_69 ( V_3 ) ) {
V_223 = V_223 >> 1 ;
V_224 = V_224 >> 1 ;
V_291 = V_291 >> 1 ;
}
if ( V_3 -> V_147 & V_149 )
V_224 += 1 ;
V_291 += V_224 ;
if ( V_291 >= V_223 )
V_291 -= V_223 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x1C , V_259 ) ;
V_259 = ( V_224 & 0xFF00 ) >> 8 ;
V_259 = V_259 << 4 ;
F_13 ( V_3 -> V_562 , 0x1D , ~ 0x0F0 , V_259 ) ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_562 , 0x21 , V_259 ) ;
if ( ! ( V_3 -> V_47 & V_610 ) ) {
if ( V_3 -> V_365 == 525 ) {
if ( V_3 -> V_147 & ( V_250 | V_251
| V_148 | V_149
| V_232 ) ) {
V_259 = 0xC6 ;
} else
V_259 = 0xC4 ;
F_4 ( V_3 -> V_562 , 0x2f , V_259 ) ;
F_4 ( V_3 -> V_562 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_365 == 420 ) {
if ( V_3 -> V_147 & ( V_250 | V_251
| V_148 | V_149
| V_232 ) ) {
V_259 = 0x4F ;
} else
V_259 = 0x4E ;
F_4 ( V_3 -> V_562 , 0x2f , V_259 ) ;
}
}
}
static struct V_675 * F_83 ( unsigned short V_291 ,
struct V_2 * V_3 )
{
unsigned short V_223 , V_224 , V_196 ;
struct V_675 * V_676 ;
if ( V_291 == 0 ) {
V_223 = V_3 -> V_363 ;
V_224 = V_3 -> V_364 ;
} else {
V_223 = V_3 -> V_365 ;
V_224 = V_3 -> V_366 ;
}
if ( V_223 <= V_224 )
return & V_677 [ 0 ] ;
else
V_676 = V_678 ;
if ( V_3 -> V_49 & V_253 )
V_676 = V_679 ;
if ( V_3 -> V_48 & V_248 ) {
if ( ( V_3 -> V_49 & V_597 ) ||
( V_3 -> V_49 & V_553 ) )
V_676 = V_678 ;
if ( V_3 -> V_49 & V_552 )
V_676 = V_680 ;
}
if ( V_3 -> V_48 & V_238 )
V_676 = V_677 ;
V_196 = 0 ;
while ( V_676 [ V_196 ] . V_681 != 0xFFFF ) {
if ( V_676 [ V_196 ] . V_681 == V_223 )
break;
V_196 ++ ;
}
return & V_676 [ V_196 ] ;
}
static void F_84 ( struct V_2 * V_3 )
{
unsigned short V_196 , V_264 ;
struct V_675 * V_676 ;
if ( ! ( V_3 -> V_147 & V_232 ) )
return;
V_676 = F_83 ( 0 , V_3 ) ;
for ( V_196 = 0x80 , V_264 = 0 ; V_196 <= 0xBF ; V_196 ++ , V_264 ++ )
F_4 ( V_3 -> V_562 , V_196 , V_676 -> V_520 [ V_264 ] ) ;
if ( ( V_3 -> V_48 & V_203 ) &&
( ! ( V_3 -> V_48 & V_238 ) ) ) {
V_676 = F_83 ( 1 , V_3 ) ;
for ( V_196 = 0xC0 , V_264 = 0 ; V_196 < 0xFF ; V_196 ++ , V_264 ++ )
F_4 ( V_3 -> V_562 ,
V_196 ,
V_676 -> V_520 [ V_264 ] ) ;
}
if ( ( V_3 -> V_48 & V_203 ) &&
( ! ( V_3 -> V_48 & V_238 ) ) )
F_13 ( V_3 -> V_562 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_13 ( V_3 -> V_562 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_85 ( unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_196 ;
unsigned char * V_371 ;
unsigned short V_197 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
F_4 ( V_3 -> V_682 , 0x00 , 0x00 ) ;
if ( V_3 -> V_49 & V_253 ) {
F_4 ( V_3 -> V_682 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_682 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_682 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_682 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_48 & V_203 ) )
return;
if ( V_3 -> V_49 & V_593 ) {
F_4 ( V_3 -> V_682 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_682 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_682 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_48 & V_238 ) || ( V_3 -> V_48
& V_248 ) ) {
if ( V_3 -> V_49 & V_597 )
return;
V_371 = V_3 -> V_128 ;
if ( V_3 -> V_243 & V_244 ) {
V_371 = V_3 -> V_130 ;
if ( ! ( V_197 & V_213 ) )
V_371 = V_3 -> V_132 ;
}
if ( V_3 -> V_49 & V_553 )
V_371 = V_3 -> V_134 ;
if ( V_3 -> V_49 & V_552 )
V_371 = V_3 -> V_136 ;
for ( V_196 = 0 ; V_196 <= 0x3E ; V_196 ++ )
F_4 ( V_3 -> V_682 , V_196 , V_371 [ V_196 ] ) ;
if ( V_3 -> V_147 & V_232 ) {
if ( V_3 -> V_49 & V_553 )
F_4 ( V_3 -> V_682 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_86 ( unsigned short V_188 , unsigned short V_189 ,
unsigned short V_222 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_223 , V_291 , V_224 , V_197 , V_259 , V_298 ;
unsigned long V_670 , V_669 , V_683 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
V_259 = V_3 -> V_633 ;
F_4 ( V_3 -> V_543 , 0x13 , V_259 ) ;
V_224 = V_3 -> V_632 ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_543 , 0x14 , V_259 ) ;
V_298 = ( ( V_224 & 0xFF00 ) >> 8 ) << 7 ;
V_291 = V_3 -> V_508 - 1 ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_543 , 0x16 , V_259 ) ;
V_259 = ( ( V_291 & 0xFF00 ) >> 8 ) << 3 ;
V_298 |= V_259 ;
V_291 = V_3 -> V_509 - 1 ;
if ( ! ( V_3 -> V_48 & V_203 ) )
V_291 -= 5 ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_543 , 0x17 , V_259 ) ;
V_259 = V_298 | ( ( V_291 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_543 , 0x15 , V_259 ) ;
F_21 ( V_3 -> V_543 , 0x0D , 0x08 ) ;
V_291 = V_3 -> V_48 ;
V_224 = V_3 -> V_363 ;
if ( V_197 & V_294 )
V_224 = V_224 >> 1 ;
if ( F_69 ( V_3 ) )
V_224 = V_224 >> 1 ;
if ( V_291 & V_238 ) {
V_259 = 0 ;
if ( V_224 <= 1024 )
V_259 = 0xA0 ;
if ( V_224 == 1280 )
V_259 = 0xC0 ;
} else if ( V_291 & V_203 ) {
V_259 = 0xA0 ;
if ( V_224 <= 800 )
V_259 = 0x80 ;
} else {
V_259 = 0x80 ;
if ( V_3 -> V_48 & V_204 ) {
V_259 = 0 ;
if ( V_224 > 800 )
V_259 = 0x60 ;
}
}
if ( V_3 -> V_49 & ( V_553 | V_552 ) ) {
V_259 = 0x00 ;
if ( V_3 -> V_363 == 1280 )
V_259 = 0x40 ;
if ( V_3 -> V_363 == 1024 )
V_259 = 0x20 ;
}
F_13 ( V_3 -> V_543 , 0x0E , ~ 0xEF , V_259 ) ;
V_670 = V_3 -> V_366 ;
if ( V_291 & V_238 ) {
if ( ! ( V_259 & 0xE000 ) )
V_224 = V_224 >> 1 ;
}
V_291 = V_3 -> V_638 ;
V_259 = V_291 & 0x00FF ;
F_4 ( V_3 -> V_543 , 0x18 , V_259 ) ;
V_669 = V_3 -> V_365 ;
V_291 |= 0x04000 ;
if ( V_669 <= V_670 ) {
V_291 = ( V_291 & ( ~ 0x4000 ) ) ;
V_669 = V_3 -> V_365 ;
} else {
V_669 -= V_670 ;
}
V_683 = ( V_669 * 256 * 1024 ) % V_670 ;
V_669 = ( V_669 * 256 * 1024 ) / V_670 ;
V_670 = V_669 ;
if ( V_683 != 0 )
V_670 ++ ;
V_259 = ( unsigned short ) ( V_670 & 0x000000FF ) ;
F_4 ( V_3 -> V_543 , 0x1B , V_259 ) ;
V_259 = ( unsigned short ) ( ( V_670 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_543 , 0x1A , V_259 ) ;
V_224 = ( unsigned short ) ( V_670 >> 16 ) ;
V_259 = V_224 & 0x00FF ;
V_259 = V_259 << 4 ;
V_259 |= ( ( V_291 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_543 , 0x19 , V_259 ) ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
V_259 = 0x0028 ;
F_4 ( V_3 -> V_543 , 0x1C , V_259 ) ;
V_223 = V_3 -> V_363 ;
if ( V_197 & V_294 )
V_223 = V_223 >> 1 ;
if ( F_69 ( V_3 ) )
V_223 = V_223 >> 1 ;
if ( V_3 -> V_48 & V_204 ) {
if ( V_223 > 800 )
V_223 -= 800 ;
} else {
if ( V_3 -> V_363 > 800 ) {
if ( V_3 -> V_363 == 1024 )
V_223 = ( V_223 * 25 / 32 ) - 1 ;
else
V_223 = ( V_223 * 20 / 32 ) - 1 ;
}
}
V_223 -= 1 ;
V_259 = ( V_223 & 0xFF00 ) >> 8 ;
V_259 = ( ( V_259 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_543 , 0x1E , V_259 ) ;
V_259 = ( V_223 & 0x00FF ) ;
F_4 ( V_3 -> V_543 , 0x1D , V_259 ) ;
if ( V_3 -> V_48 & ( V_203 | V_238 ) ) {
if ( V_3 -> V_363 > 800 )
F_21 ( V_3 -> V_543 , 0x1E , 0x08 ) ;
}
V_259 = 0x0036 ;
if ( V_3 -> V_48 & V_203 ) {
if ( ! ( V_3 -> V_49 & ( V_555
| V_553 | V_552
| V_600 ) ) ) {
V_259 |= 0x0001 ;
if ( ( V_3 -> V_48 & V_205 )
&& ( ! ( V_3 -> V_49
& V_244 ) ) )
V_259 &= ( ~ 0x0001 ) ;
}
}
F_13 ( V_3 -> V_543 , 0x1F , 0x00C0 , V_259 ) ;
V_224 = V_3 -> V_510 ;
if ( F_69 ( V_3 ) )
V_224 = V_224 >> 1 ;
V_224 = ( V_224 >> 1 ) - 2 ;
V_259 = ( ( V_224 & 0x0700 ) >> 8 ) << 3 ;
F_13 ( V_3 -> V_543 , 0x21 , 0x00C0 , V_259 ) ;
V_259 = V_224 & 0x00FF ;
F_4 ( V_3 -> V_543 , 0x22 , V_259 ) ;
}
if ( V_3 -> V_684 == 0 )
F_72 ( V_188 , V_189 , V_222 ,
V_3 ) ;
}
static void F_87 ( struct V_2 * V_3 )
{
F_13 ( V_3 -> V_200 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_88 ( unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_685 , V_686 ;
V_685 = V_3 -> V_687 ;
V_686 = V_3 -> V_687 + 1 ;
if ( V_3 -> V_192 == V_219 ) {
if ( ! ( V_3 -> V_48 & ( V_205 | V_688
| V_689 ) ) ) {
F_87 ( V_3 ) ;
}
}
return;
}
static void F_89 ( struct V_206 * V_207 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_209 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_90 ( struct V_206 * V_207 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_209 , 0x63 , 0xBF , 0x00 ) ;
}
static unsigned char F_91 ( struct V_622 * V_623 ,
unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_339 , V_362 , V_660 , V_197 , V_289 ;
V_289 = F_26 ( V_188 , V_189 , V_3 ) ;
if ( V_188 <= 0x13 ) {
V_339 = V_3 -> V_33 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_33 [ V_289 ] . V_293 ;
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
} else {
V_339 = V_3 -> V_36 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_36 [ V_289 ] . V_293 ;
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
}
if ( ! ( V_197 & V_213 ) ) {
V_339 /= 9 ;
V_339 *= 8 ;
}
if ( V_188 > 0x13 ) {
if ( ( V_188 > 0x13 ) && ( V_197 & V_294 ) )
V_339 *= 2 ;
if ( ( V_188 > 0x13 ) && ( V_197 & V_266 ) )
V_362 *= 2 ;
}
if ( V_339 > V_623 -> V_624 . V_690 )
return 0 ;
if ( V_362 > V_623 -> V_624 . V_691 )
return 0 ;
if ( V_188 > 0x13 ) {
if ( V_339 != V_623 -> V_624 . V_690 ||
V_362 != V_623 -> V_624 . V_691 ) {
V_660 = F_73 ( V_188 ,
V_189 ,
V_3 ) ;
if ( V_660 > 2 )
return 0 ;
}
}
return 1 ;
}
static void F_92 ( struct V_622 * V_623 ,
int V_277 ,
unsigned short V_188 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned char V_259 , V_692 ;
unsigned short V_339 , V_362 , V_197 , V_289 ;
unsigned short V_693 , V_694 , V_695 , V_696 , V_697 ;
unsigned short V_698 , V_699 , V_700 , V_701 , V_702 ;
unsigned short V_703 ;
V_259 = ( unsigned char ) ( ( V_623 -> V_624 . V_704 &
( V_705 << 8 ) ) >> 8 ) ;
V_259 &= V_705 ;
V_692 = ( unsigned char ) F_8 ( V_3 -> V_282 ) ;
F_9 ( ( V_692 & 0x3F ) | V_259 , V_3 -> V_260 ) ;
V_259 = V_623 -> V_624 . V_704 & V_705 ;
F_13 ( V_3 -> V_200 , 0x35 , ~ 0x80 , V_259 & 0x80 ) ;
F_13 ( V_3 -> V_200 , 0x30 , ~ 0x20 , ( V_259 & 0x40 ) >> 1 ) ;
if ( V_277 == V_162 )
F_23 ( V_3 ) ;
else
F_31 ( V_3 ) ;
V_289 = F_26 ( V_188 , V_189 , V_3 ) ;
if ( V_188 <= 0x13 ) {
V_339 = V_3 -> V_33 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_33 [ V_289 ] . V_293 ;
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
} else {
V_339 = V_3 -> V_36 [ V_289 ] . V_292 ;
V_362 = V_3 -> V_36 [ V_289 ] . V_293 ;
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
}
if ( ! ( V_197 & V_213 ) )
V_339 = V_339 * 8 / 9 ;
V_693 = V_623 -> V_624 . V_693 ;
V_694 = V_339 + ( V_623 -> V_624 . V_690 - V_339 ) / 2 ;
if ( ( V_188 <= 0x13 ) && ( V_197 & V_294 ) )
V_694 -= V_339 / 4 ;
if ( V_694 > V_693 )
V_694 -= V_693 ;
V_695 = V_694 + V_623 -> V_624 . V_706 ;
if ( V_695 > V_693 )
V_695 -= V_693 ;
V_696 = V_695 + V_623 -> V_624 . V_707 ;
if ( V_696 > V_693 )
V_696 -= V_693 ;
V_697 = V_694 + V_693 - V_623 -> V_624 . V_690 ;
V_698 = V_623 -> V_624 . V_698 ;
V_699 = V_362 + ( V_623 -> V_624 . V_691 - V_362 ) / 2 ;
if ( ( V_188 > 0x13 ) && ( V_197 & V_266 ) )
V_699 += V_362 / 2 ;
if ( V_699 > V_698 )
V_699 -= V_698 ;
V_700 = V_699 + V_623 -> V_624 . V_708 ;
if ( V_700 > V_698 )
V_700 -= V_698 ;
V_701 = V_700 + V_623 -> V_624 . V_709 ;
if ( V_701 > V_698 )
V_701 -= V_698 ;
V_702 = V_699 + V_698 - V_623 -> V_624 . V_691 ;
V_259 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x11 ) ;
F_4 ( V_3 -> V_209 , 0x11 , V_259 & 0x7f ) ;
if ( ! ( V_197 & V_213 ) )
F_21 ( V_3 -> V_200 , 0x1 , 0x1 ) ;
V_703 = ( V_693 >> 3 ) - 5 ;
F_13 ( V_3 -> V_200 , 0x0B , ~ 0x03 , ( V_703 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_209 , 0x0 , ( V_703 & 0xFF ) ) ;
V_703 = ( V_694 >> 3 ) - 1 ;
F_13 ( V_3 -> V_200 , 0x0B , ~ 0x30 , ( V_703 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_209 , 0x2 , ( V_703 & 0xFF ) ) ;
V_703 = ( V_697 >> 3 ) - 1 ;
F_13 ( V_3 -> V_200 , 0x0C , ~ 0x03 , ( V_703 & 0xC0 ) >> 6 ) ;
F_13 ( V_3 -> V_209 , 0x05 , ~ 0x80 , ( V_703 & 0x20 ) << 2 ) ;
F_13 ( V_3 -> V_209 , 0x03 , ~ 0x1F , V_703 & 0x1F ) ;
V_703 = ( V_695 >> 3 ) + 2 ;
F_13 ( V_3 -> V_200 , 0x0B , ~ 0xC0 , ( V_703 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_209 , 0x4 , ( V_703 & 0xFF ) ) ;
V_703 -- ;
F_13 ( V_3 -> V_200 , 0x2F , ~ 0x03 , ( V_703 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_200 , 0x2E , ( V_703 & 0xFF ) ) ;
V_703 = ( V_696 >> 3 ) + 2 ;
F_13 ( V_3 -> V_200 , 0x0C , ~ 0x04 , ( V_703 & 0x20 ) >> 3 ) ;
F_13 ( V_3 -> V_209 , 0x05 , ~ 0x1F , V_703 & 0x1F ) ;
V_703 -- ;
F_13 ( V_3 -> V_200 , 0x2F , ~ 0xFC , V_703 << 2 ) ;
V_703 = V_698 - 2 ;
F_13 ( V_3 -> V_200 , 0x0A , ~ 0x01 , ( V_703 & 0x400 ) >> 10 ) ;
F_13 ( V_3 -> V_209 , 0x07 , ~ 0x20 , ( V_703 & 0x200 ) >> 4 ) ;
F_13 ( V_3 -> V_209 , 0x07 , ~ 0x01 , ( V_703 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_209 , 0x06 , ( V_703 & 0xFF ) ) ;
V_703 = V_699 - 1 ;
F_13 ( V_3 -> V_200 , 0x0A , ~ 0x04 , ( V_703 & 0x400 ) >> 8 ) ;
F_13 ( V_3 -> V_209 , 0x09 , ~ 0x20 , ( V_703 & 0x200 ) >> 4 ) ;
F_13 ( V_3 -> V_209 , 0x07 , ~ 0x08 , ( V_703 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_209 , 0x15 , ( V_703 & 0xFF ) ) ;
V_703 = V_702 - 1 ;
F_13 ( V_3 -> V_200 , 0x0A , ~ 0x10 , ( V_703 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_209 , 0x16 , ( V_703 & 0xFF ) ) ;
V_703 = V_700 - 1 ;
F_13 ( V_3 -> V_200 , 0x0A , ~ 0x08 , ( V_703 & 0x400 ) >> 7 ) ;
F_13 ( V_3 -> V_209 , 0x07 , ~ 0x80 , ( V_703 & 0x200 ) >> 2 ) ;
F_13 ( V_3 -> V_209 , 0x07 , ~ 0x04 , ( V_703 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_209 , 0x10 , ( V_703 & 0xFF ) ) ;
if ( V_277 == V_162 ) {
F_13 ( V_3 -> V_200 , 0x35 , ~ 0x07 ,
( V_703 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_200 , 0x34 , V_703 & 0xFF ) ;
} else {
F_13 ( V_3 -> V_200 , 0x3F , ~ 0x03 ,
( V_703 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_200 , 0x34 , ( V_703 >> 1 ) & 0xFF ) ;
F_13 ( V_3 -> V_209 , 0x33 , ~ 0x01 , V_703 & 0x01 ) ;
}
V_703 = V_701 - 1 ;
F_13 ( V_3 -> V_200 , 0x0A , ~ 0x20 , ( V_703 & 0x10 ) << 1 ) ;
F_13 ( V_3 -> V_209 , 0x11 , ~ 0x0F , V_703 & 0x0F ) ;
if ( V_277 == V_162 )
F_13 ( V_3 -> V_200 , 0x3F , ~ 0xFC ,
( V_703 << 2 ) & 0xFC ) ;
else
F_13 ( V_3 -> V_200 , 0x3F , ~ 0xFC ,
( V_703 << 2 ) & 0x7C ) ;
for ( V_259 = 0 , V_703 = 0 ; V_259 < 3 ; V_259 ++ ) {
F_13 ( V_3 -> V_200 , 0x31 , ~ 0x30 , V_703 ) ;
F_4 ( V_3 -> V_200 ,
0x2B , V_623 -> V_624 . V_710 ) ;
F_4 ( V_3 -> V_200 ,
0x2C , V_623 -> V_624 . V_711 ) ;
V_703 += 0x10 ;
}
if ( ! ( V_197 & V_213 ) ) {
F_8 ( V_3 -> V_214 ) ;
F_9 ( 0x13 , V_3 -> V_215 ) ;
F_9 ( 0x00 , V_3 -> V_215 ) ;
F_8 ( V_3 -> V_214 ) ;
F_9 ( 0x20 , V_3 -> V_215 ) ;
F_8 ( V_3 -> V_214 ) ;
}
}
static unsigned char F_93 ( struct V_2 * V_3 )
{
unsigned short V_223 ;
V_223 = V_3 -> V_48 ;
if ( V_223 & V_575 )
return 0 ;
else if ( V_223 & ( V_576 | V_587 | V_586 ) )
return 1 ;
return 0 ;
}
static unsigned char F_94 ( struct V_2 * V_3 )
{
unsigned short V_224 , V_194 ;
V_224 = V_3 -> V_243 & ( V_712 | V_713 ) ;
V_194 = ~ ( ( unsigned short ) F_6 ( V_3 -> V_536 , 0x2E ) ) ;
if ( V_224 & ( V_714 | V_712 ) ) {
if ( ! ( V_194 & 0x08 ) )
return 0 ;
}
if ( ! ( V_224 & ( V_715 | V_713 ) ) )
return 0 ;
if ( V_194 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_95 ( struct V_2 * V_3 )
{
unsigned short V_224 , V_194 ;
V_224 = V_3 -> V_243 & ( V_714 | V_715 ) ;
V_194 = ~ ( ( unsigned short ) F_6 ( V_3 -> V_536 , 0x2E ) ) ;
if ( V_224 & ( V_714 | V_712 ) ) {
if ( ! ( V_194 & 0x08 ) )
return 0 ;
}
if ( ! ( V_224 & ( V_715 | V_713 ) ) )
return 0 ;
if ( V_194 & 0x01 )
return 1 ;
return 0 ;
}
static void F_96 ( struct V_622 * V_623 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_194 = 0 ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
V_194 = 0x3F ;
if ( ! ( V_3 -> V_48 &
( V_576 | V_586 ) ) ) {
if ( V_3 -> V_48 & V_202 ) {
if ( V_3 -> V_48 & V_575 ) {
V_194 = 0x7F ;
if ( ! ( V_3 -> V_48 & V_202 ) )
V_194 = 0xBF ;
if ( V_3 -> V_243 & V_713 )
V_194 &= 0xBF ;
if ( V_3 -> V_243 & V_712 )
V_194 &= 0x7F ;
}
}
}
F_14 ( V_3 -> V_543 , 0x1F , V_194 ) ;
if ( V_3 -> V_147 & ( V_149 | V_232 ) ) {
if ( ( ( V_3 -> V_48 & ( V_204 | V_202 ) ) )
|| ( F_94 ( V_3 ) )
|| ( F_93 ( V_3 ) ) )
F_21 ( V_3 -> V_543 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_243 & V_712 ) || ( V_3 -> V_48
& ( V_576 | V_202
| V_586 ) ) ) {
if ( V_3 -> V_243 & V_716 )
F_89 ( V_207 , V_3 ) ;
F_64 ( V_623 , V_207 , V_3 ) ;
}
if ( V_3 -> V_48 & V_202 ) {
if ( ( V_3 -> V_243 & V_712 ) || ( V_3 -> V_48
& V_202 ) )
F_14 ( V_3 -> V_536 , 0x1e , 0xdf ) ;
}
F_14 ( V_3 -> V_200 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_48 & ( V_586 | V_575 ) ) )
F_14 ( V_3 -> V_562 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_243 & V_713 ) ||
( V_3 -> V_48 &
( V_576 | V_586 ) ) ||
( ( ! ( V_3 -> V_48 & V_202 ) ) &&
( V_3 -> V_48 &
( V_230 | V_204 | V_203 ) ) ) )
F_21 ( V_3 -> V_536 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_243 & V_713 ) ||
( V_3 -> V_48 &
( V_576 | V_586 ) ) ||
( ! ( V_3 -> V_48 & V_202 ) ) ||
( V_3 -> V_48 &
( V_230 | V_204 | V_203 ) ) ) {
V_194 = F_6 ( V_3 -> V_536 , 0x00 ) ;
F_21 ( V_3 -> V_536 , 0x00 , 0x10 ) ;
F_14 ( V_3 -> V_536 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_536 , 0x00 , V_194 ) ;
}
} else {
if ( V_3 -> V_48 & ( V_204 | V_203 ) ) {
F_21 ( V_3 -> V_536 , 0x00 , 0x80 ) ;
F_14 ( V_3 -> V_536 , 0x1E , 0xDF ) ;
F_14 ( V_3 -> V_200 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_48 & ( V_576 | V_202
| V_586 ) )
F_64 ( V_623 , V_207 , V_3 ) ;
}
}
static unsigned short F_97 ( struct V_2 * V_3 )
{
unsigned short V_224 = 0 ;
if ( V_3 -> V_49 & V_253 )
V_224 = 2 ;
if ( V_3 -> V_49 & V_600 )
V_224 = 4 ;
if ( V_3 -> V_49 & V_597 )
V_224 = 6 ;
if ( V_3 -> V_49 & V_553 )
V_224 = 8 ;
if ( V_3 -> V_49 & V_552 )
V_224 = 10 ;
if ( V_3 -> V_49 & V_244 )
V_224 ++ ;
return V_224 ;
}
static void F_98 ( unsigned short * V_224 , unsigned char * V_557 ,
unsigned char * V_558 , struct V_2 * V_3 )
{
* V_224 = 0 ;
* V_557 = 0 ;
* V_558 = 0 ;
if ( V_3 -> V_49 & V_253 )
* V_224 = 1 ;
if ( V_3 -> V_49 & V_593 )
* V_224 = 2 ;
if ( V_3 -> V_49 & V_594 )
* V_224 = 3 ;
if ( V_3 -> V_49 & V_555 ) {
* V_224 = 4 ;
if ( V_3 -> V_49 & V_593 )
* V_224 = 5 ;
}
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
if ( ( ! ( V_3 -> V_48 & V_205 ) ) || ( V_3 -> V_49
& V_244 ) ) {
* V_224 += 8 ;
* V_557 += 1 ;
}
}
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) )
( * V_558 ) ++ ;
}
static void F_99 ( struct V_2 * V_3 )
{
unsigned short V_190 ;
unsigned char V_194 , V_521 , V_619 ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
if ( V_3 -> V_48 & ( V_204 | V_202
| V_203 | V_230 ) ) {
V_521 = 0 ;
V_619 = 0 ;
V_190 = F_97 ( V_3 ) ;
V_521 = V_3 -> V_153 [ V_190 ] ;
if ( V_3 -> V_147 & ( V_250 | V_251
| V_148 | V_149
| V_232 ) )
V_521 = V_3 -> V_155 [ V_190 ] ;
if ( V_3 -> V_48 & V_575 )
V_521 = V_521 >> 4 ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
V_190 = F_42 ( V_3 ) ;
V_619 = V_3 -> V_150 [ V_190 ] .
V_717 ;
if ( ! ( V_3 -> V_48 & V_202 ) )
V_521 = V_619 ;
}
V_521 &= 0x0F ;
V_619 &= 0xF0 ;
V_194 = F_6 ( V_3 -> V_536 , 0x2D ) ;
if ( V_3 -> V_48 & ( V_230 | V_204
| V_203 ) ) {
V_194 &= 0xF0 ;
V_194 |= V_521 ;
}
if ( V_3 -> V_48 & V_202 ) {
V_194 &= 0x0F ;
V_194 |= V_619 ;
}
F_4 ( V_3 -> V_536 , 0x2D , V_194 ) ;
}
} else if ( V_3 -> V_229 == 1 ) {
V_521 = 0 ;
V_619 = 0 ;
if ( V_3 -> V_48 & V_204 ) {
V_194 = V_3 -> V_150 [
F_42 ( V_3 ) ] .
V_717 ;
V_194 &= 0x0f ;
V_194 = V_194 << 4 ;
F_13 ( V_3 -> V_536 , 0x2D , 0x0f ,
V_194 ) ;
}
}
}
static void F_100 ( unsigned short V_291 ,
struct V_2 * V_3 )
{
unsigned short V_259 ;
V_259 = F_6 ( V_3 -> V_209 , 0x37 ) ;
if ( V_259 & V_665 ) {
F_13 ( V_3 -> V_536 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_291 & 0x00C0 ) ) ) ;
F_13 ( V_3 -> V_536 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_13 ( V_3 -> V_536 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_291 & 0x00C0 ) ) ) ;
F_13 ( V_3 -> V_536 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_101 ( unsigned short V_291 ,
struct V_2 * V_3 )
{
if ( V_291 & V_718 )
F_13 ( V_3 -> V_562 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_291 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_13 ( V_3 -> V_562 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_291 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
unsigned short V_196 ;
V_196 = F_6 ( V_3 -> V_200 , 0x1F ) ;
if ( ! ( V_196 & 0xC0 ) ) {
for ( V_196 = 0 ; V_196 < 0xFFFF ; V_196 ++ ) {
if ( ! ( F_8 ( V_3 -> V_214 ) & 0x08 ) )
break;
}
for ( V_196 = 0 ; V_196 < 0xFFFF ; V_196 ++ ) {
if ( ( F_8 ( V_3 -> V_214 ) & 0x08 ) )
break;
}
}
}
static void F_103 ( struct V_2 * V_3 )
{
unsigned short V_190 ;
V_190 = F_42 ( V_3 ) ;
F_14 ( V_3 -> V_543 , 0x30 , 0x8F ) ;
F_102 ( V_3 ) ;
F_21 ( V_3 -> V_543 , 0x30 , 0x20 ) ;
F_102 ( V_3 ) ;
F_4 ( V_3 -> V_543 , 0x31 ,
V_3 -> V_150 [ V_190 ] . V_719 ) ;
F_4 ( V_3 -> V_543 , 0x32 ,
V_3 -> V_150 [ V_190 ] . V_720 ) ;
F_4 ( V_3 -> V_543 , 0x33 ,
V_3 -> V_150 [ V_190 ] . V_721 ) ;
F_4 ( V_3 -> V_543 , 0x34 ,
V_3 -> V_150 [ V_190 ] . V_722 ) ;
F_102 ( V_3 ) ;
F_21 ( V_3 -> V_543 , 0x30 , 0x40 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
unsigned short V_291 ;
V_291 = V_3 -> V_150 [ F_42 ( V_3 ) ] . V_606 ;
if ( V_3 -> V_147 &
( V_250 |
V_251 |
V_148 |
V_149 |
V_232 ) ) {
if ( V_3 -> V_147 &
( V_148 | V_149 | V_232 ) ) {
F_4 ( V_3 -> V_543 , 0x24 ,
( unsigned char ) ( V_291 & 0x1F ) ) ;
}
F_13 ( V_3 -> V_543 , 0x0D ,
~ ( ( V_723 | V_724 ) >> 8 ) ,
( unsigned short ) ( ( V_291 & ( V_723
| V_724 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
if ( V_3 -> V_48 & V_204 )
F_101 ( V_291 , V_3 ) ;
else if ( V_3 -> V_48 & V_202 )
F_100 ( V_291 , V_3 ) ;
if ( V_3 -> V_147 & ( V_149 | V_232 ) ) {
if ( V_291 & V_725 )
F_103 ( V_3 ) ;
}
} else {
F_100 ( V_291 , V_3 ) ;
}
}
static void F_105 ( unsigned short V_188 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_224 , V_190 ;
unsigned char V_194 ;
if ( V_3 -> V_49 & ( V_553 | V_552 ) )
return;
V_224 = F_97 ( V_3 ) ;
V_224 &= 0xFE ;
if ( V_188 <= 0x13 )
V_190 = V_3 -> V_4 [ V_189 ] . V_726 ;
else
V_190 = V_3 -> V_10 [ V_189 ] . V_727 ;
V_224 += V_190 ;
V_194 = V_728 [ V_224 ] ;
V_194 = V_194 << 4 ;
F_13 ( V_3 -> V_562 , 0x0A , 0x8F , V_194 ) ;
}
static void F_106 ( unsigned short V_188 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_224 , V_190 ;
unsigned char V_194 ;
V_224 = F_97 ( V_3 ) ;
V_224 &= 0xFE ;
if ( V_188 <= 0x13 )
V_190 = V_3 -> V_4 [ V_189 ] . V_729 ;
else
V_190 = V_3 -> V_10 [ V_189 ] . V_730 ;
V_224 += V_190 ;
V_194 = V_731 [ V_224 ] ;
V_194 = V_194 << 5 ;
F_13 ( V_3 -> V_562 , 0x3A , 0x1F , V_194 ) ;
}
static void F_107 ( struct V_2 * V_3 )
{
unsigned short V_224 ;
unsigned char V_557 , V_558 ;
unsigned long V_732 ;
F_98 ( & V_224 , & V_557 , & V_558 , V_3 ) ;
V_732 = V_733 [ V_224 ] ;
F_4 ( V_3 -> V_562 , 0x31 , ( unsigned short ) ( V_732
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_562 , 0x32 , ( unsigned short ) ( ( V_732
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_562 , 0x33 , ( unsigned short ) ( ( V_732
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_562 , 0x34 , ( unsigned short ) ( ( V_732
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_108 ( unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_224 , V_190 ;
unsigned char V_557 , V_558 , V_369 , * V_734 ;
F_98 ( & V_224 , & V_557 , & V_558 , V_3 ) ;
switch ( V_224 ) {
case 0x00 :
case 0x04 :
V_734 = V_735 ;
break;
case 0x01 :
V_734 = V_736 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_734 = V_737 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_734 = V_738 ;
break;
default:
return;
}
if ( V_188 <= 0x13 )
V_369 = V_3 -> V_4 [ V_189 ] .
V_739 ;
else
V_369 = V_3 -> V_10 [ V_189 ] .
V_740 ;
if ( V_557 == 0 )
V_190 = V_369 * 4 ;
else
V_190 = V_369 * 7 ;
if ( ( V_557 == 0 ) && ( V_558 == 1 ) ) {
F_4 ( V_3 -> V_562 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_562 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_562 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_562 , 0x38 , V_734 [ V_190 ++ ] ) ;
} else {
F_4 ( V_3 -> V_562 , 0x35 , V_734 [ V_190 ++ ] ) ;
F_4 ( V_3 -> V_562 , 0x36 , V_734 [ V_190 ++ ] ) ;
F_4 ( V_3 -> V_562 , 0x37 , V_734 [ V_190 ++ ] ) ;
F_4 ( V_3 -> V_562 , 0x38 , V_734 [ V_190 ++ ] ) ;
}
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
F_4 ( V_3 -> V_562 , 0x48 , V_734 [ V_190 ++ ] ) ;
F_4 ( V_3 -> V_562 , 0x49 , V_734 [ V_190 ++ ] ) ;
F_4 ( V_3 -> V_562 , 0x4A , V_734 [ V_190 ++ ] ) ;
}
}
static void F_109 ( unsigned short V_188 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
F_99 ( V_3 ) ;
if ( V_3 -> V_48 & ( V_204 | V_202 ) )
F_104 ( V_3 ) ;
if ( V_3 -> V_48 & V_203 ) {
F_107 ( V_3 ) ;
F_108 ( V_188 , V_189 , V_3 ) ;
F_105 ( V_188 , V_189 , V_3 ) ;
if ( V_3 -> V_147 & V_556 )
F_106 ( V_188 , V_189 , V_3 ) ;
}
}
static void F_110 ( unsigned short V_188 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_521 ;
short V_557 ;
unsigned char V_194 ;
V_194 = 0 ;
if ( ! ( V_3 -> V_48 & V_576 ) ) {
V_194 = F_6 ( V_3 -> V_536 , 0x00 ) ;
V_194 &= ~ 0x10 ;
V_194 |= 0x40 ;
if ( V_3 -> V_48 & ( V_230 | V_203
| V_204 ) ) {
V_194 = 0x40 ;
if ( V_188 > 0x13 ) {
V_557 = V_3 -> V_192 ;
V_557 -= V_219 ;
if ( V_557 >= 0 ) {
V_194 = ( 0x008 >> V_557 ) ;
if ( V_194 == 0 )
V_194 = 1 ;
V_194 |= 0x040 ;
}
}
if ( V_3 -> V_48 & V_205 )
V_194 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_536 , 0x00 , V_194 ) ;
V_194 = 0x08 ;
V_521 = 0xf0 ;
if ( V_3 -> V_48 & V_576 ) {
F_13 ( V_3 -> V_536 , 0x2e , V_521 , V_194 ) ;
} else {
V_194 = 0x00 ;
V_521 = 0xff ;
if ( V_3 -> V_48 & ( V_230 | V_203
| V_204 | V_202 ) ) {
if ( ( V_3 -> V_48 & V_202 ) &&
( ! ( V_3 -> V_48 & V_586 ) ) ) {
V_521 &= 0xf7 ;
V_194 |= 0x01 ;
F_13 ( V_3 -> V_536 , 0x2e ,
V_521 , V_194 ) ;
} else {
if ( V_3 -> V_48 & V_202 ) {
V_521 &= 0xf7 ;
V_194 |= 0x01 ;
}
if ( V_3 -> V_48 &
( V_230 |
V_203 |
V_204 ) ) {
V_521 &= 0xf8 ;
V_194 = 0x01 ;
if ( ! ( V_3 -> V_48 & V_205 ) )
V_194 |= 0x02 ;
if ( ! ( V_3 -> V_48 &
V_230 ) ) {
V_194 = V_194 ^ 0x05 ;
if ( ! ( V_3 -> V_48 &
V_204 ) )
V_194 = V_194 ^ 0x01 ;
}
if ( ! ( V_3 -> V_48 &
V_575 ) )
V_194 |= 0x08 ;
F_13 ( V_3 -> V_536 ,
0x2e , V_521 , V_194 ) ;
} else {
F_13 ( V_3 -> V_536 ,
0x2e , V_521 , V_194 ) ;
}
}
} else {
F_13 ( V_3 -> V_536 , 0x2e , V_521 ,
V_194 ) ;
}
}
if ( V_3 -> V_48 & ( V_230 | V_203 | V_204
| V_202 ) ) {
V_194 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_192 == V_219 ) && ( ! ( V_3 -> V_48
& V_205 ) ) ) {
V_194 |= 0x010 ;
}
V_194 |= 0x080 ;
if ( V_3 -> V_48 & V_203 ) {
V_194 |= 0x020 ;
if ( V_188 > 0x13 ) {
if ( V_3 -> V_48 & V_589 )
V_194 = V_194 ^ 0x20 ;
}
}
F_13 ( V_3 -> V_543 , 0x0D , ~ 0x0BF , V_194 ) ;
V_194 = 0 ;
if ( V_3 -> V_47 & V_608 )
V_194 |= 0x40 ;
if ( V_3 -> V_48 & V_203 ) {
if ( V_3 -> V_49 & V_314 )
V_194 |= 0x40 ;
}
if ( ( V_3 -> V_45 == V_235 )
|| ( V_3 -> V_45 == V_515 ) )
V_194 |= 0x80 ;
if ( V_3 -> V_45 == V_236 )
V_194 |= 0x80 ;
F_4 ( V_3 -> V_543 , 0x0C , V_194 ) ;
}
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
V_194 = 0 ;
V_521 = 0xfb ;
if ( V_3 -> V_48 & V_575 ) {
V_521 = 0xff ;
if ( V_3 -> V_48 & V_202 )
V_194 |= 0x04 ;
}
F_13 ( V_3 -> V_536 , 0x13 , V_521 , V_194 ) ;
V_194 = 0x00 ;
V_521 = 0xcf ;
if ( ! ( V_3 -> V_48 & V_576 ) ) {
if ( V_3 -> V_48 & V_575 )
V_194 |= 0x30 ;
}
F_13 ( V_3 -> V_536 , 0x2c , V_521 , V_194 ) ;
V_194 = 0 ;
V_521 = 0x3f ;
if ( ! ( V_3 -> V_48 & V_576 ) ) {
if ( V_3 -> V_48 & V_575 )
V_194 |= 0xc0 ;
}
F_13 ( V_3 -> V_543 , 0x21 , V_521 , V_194 ) ;
}
V_194 = 0 ;
V_521 = 0x7f ;
if ( ! ( V_3 -> V_48 & V_202 ) ) {
V_521 = 0xff ;
if ( ! ( V_3 -> V_48 & V_575 ) )
V_194 |= 0x80 ;
}
F_13 ( V_3 -> V_543 , 0x23 , V_521 , V_194 ) ;
if ( V_3 -> V_147 & ( V_149 | V_232 ) ) {
if ( V_3 -> V_47 & V_608 ) {
F_21 ( V_3 -> V_543 , 0x27 , 0x20 ) ;
F_21 ( V_3 -> V_543 , 0x34 , 0x10 ) ;
}
}
}
static void F_111 ( struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_224 ;
V_224 = 0 ;
if ( V_3 -> V_48 & V_202 )
V_224 = 0x08A0 ;
}
void F_112 ( struct V_206 * V_207 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_536 , 0x2f , 0xFF , 0x01 ) ;
}
void F_113 ( struct V_206 * V_207 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_536 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_114 ( struct V_2 * V_3 )
{
unsigned short V_571 ;
if ( V_3 -> V_229 == 1 ) {
return 1 ;
} else {
V_571 = F_6 ( V_3 -> V_543 , 0x00 ) ;
if ( ( V_571 == 1 ) || ( V_571 == 2 ) )
return 1 ;
else
return 0 ;
}
}
unsigned short F_115 ( struct V_206 * V_629 ,
unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
short V_741 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_742 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_222 , V_196 , V_197 , V_190 , V_259 ;
if ( V_188 <= 0x13 )
V_197 = V_3 -> V_4 [ V_189 ] . V_198 ;
else
V_197 = V_3 -> V_10 [ V_189 ] . V_199 ;
if ( V_188 < 0x14 )
return 0xFFFF ;
V_190 = F_6 ( V_3 -> V_209 , 0x33 ) ;
V_190 = V_190 >> V_3 -> V_743 ;
V_190 &= 0x0F ;
if ( V_3 -> V_47 & V_237 )
V_190 = 0 ;
if ( V_190 > 0 )
V_190 -- ;
if ( V_3 -> V_243 & V_550 ) {
if ( V_3 -> V_48 & ( V_204 | V_202 ) ) {
if ( V_3 -> V_229 == 0 ) {
if ( V_3 -> V_147 & ( V_250 | V_251
| V_148 | V_149
| V_232 ) )
V_259 = V_742 [
V_3 -> V_45 & 0x0F ] ;
else
V_259 = V_741 [
V_3 -> V_45 & 0x0F ] ;
if ( V_190 > V_259 )
V_190 = V_259 ;
} else {
V_190 = 0 ;
}
}
}
V_222 = V_3 -> V_10 [ V_189 ] . V_744 ;
V_188 = V_3 -> V_13 [ V_222 ] . V_228 ;
if ( V_629 -> V_265 >= V_159 ) {
if ( ( V_3 -> V_13 [ V_222 ] . V_745 == 800 ) &&
( V_3 -> V_13 [ V_222 ] . V_746 == 600 ) ) {
V_190 ++ ;
}
if ( ( V_3 -> V_13 [ V_222 ] . V_745 == 1024 ) &&
( V_3 -> V_13 [ V_222 ] . V_746 == 768 ) ) {
V_190 ++ ;
}
if ( ( V_3 -> V_13 [ V_222 ] . V_745 == 1280 ) &&
( V_3 -> V_13 [ V_222 ] . V_746 == 1024 ) ) {
V_190 ++ ;
}
}
V_196 = 0 ;
do {
if ( V_3 -> V_13 [ V_222 + V_196 ] .
V_228 != V_188 )
break;
V_259 = V_3 -> V_13 [ V_222 + V_196 ] .
V_257 ;
V_259 &= V_574 ;
if ( V_259 < V_3 -> V_192 )
break;
V_196 ++ ;
V_190 -- ;
} while ( V_190 != 0xFFFF );
if ( ! ( V_3 -> V_48 & V_230 ) ) {
if ( V_3 -> V_48 & V_205 ) {
V_259 = V_3 -> V_13 [ V_222 + V_196 - 1 ] .
V_257 ;
if ( V_259 & V_295 )
V_196 ++ ;
}
}
V_196 -- ;
if ( ( V_3 -> V_243 & V_550 ) ) {
V_259 = F_15 ( V_188 , V_189 ,
V_222 , & V_196 , V_3 ) ;
}
return V_222 + V_196 ;
}
static void F_116 ( unsigned short V_188 , unsigned short V_189 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_222 ;
V_3 -> V_243 |= V_550 ;
V_222 = F_115 ( V_207 , V_188 ,
V_189 , V_3 ) ;
F_37 ( V_188 , V_189 , V_3 ) ;
F_40 ( V_188 , V_189 , V_222 , V_3 ) ;
F_41 ( V_188 , V_189 , V_222 ,
V_207 , V_3 ) ;
F_45 ( V_188 , V_189 , V_222 , V_3 ) ;
F_49 ( V_188 , V_189 , V_222 , V_3 ) ;
}
static unsigned char F_117 ( unsigned short V_188 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_224 , V_189 , V_222 ;
V_224 = V_3 -> V_48 ;
V_3 -> V_243 |= V_550 ;
F_55 ( V_188 , & V_189 , V_3 ) ;
V_3 -> V_743 = 4 ;
V_222 = F_115 ( V_207 , V_188 ,
V_189 , V_3 ) ;
F_67 ( V_188 , V_3 ) ;
F_68 ( V_188 , V_189 , V_3 ) ;
F_71 ( V_188 , V_189 , V_222 , V_3 ) ;
F_77 ( V_188 , V_189 , V_207 ,
V_222 , V_3 ) ;
F_78 ( V_188 , V_189 , V_207 ,
V_222 , V_3 ) ;
F_80 ( V_188 , V_189 , V_207 ,
V_222 , V_3 ) ;
F_81 ( V_188 , V_189 , V_222 ,
V_207 , V_3 ) ;
F_82 ( V_188 , V_189 , V_207 ,
V_222 , V_3 ) ;
F_84 ( V_3 ) ;
F_85 ( V_188 , V_189 , V_3 ) ;
F_86 ( V_188 , V_189 , V_222 ,
V_207 , V_3 ) ;
F_72 ( V_188 , V_189 , V_222 , V_3 ) ;
F_88 ( V_188 , V_189 , V_3 ) ;
F_66 ( V_3 ) ;
return 1 ;
}
void F_118 ( struct V_2 * V_3 )
{
unsigned char V_747 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_748 = 0 , V_749 = 0 , V_750 = 0 , V_751 = 0 ;
unsigned char V_752 , V_753 , V_754 ;
unsigned short V_259 ;
unsigned char V_755 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_196 ;
F_4 ( V_3 -> V_200 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_209 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_209 , 0x53 , ( unsigned char ) ( F_6 (
V_3 -> V_209 , 0x53 ) | 0x02 ) ) ;
V_754 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x31 ) ;
V_753 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x63 ) ;
V_748 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x01 ) ;
F_4 ( V_3 -> V_200 , 0x01 , ( unsigned char ) ( V_748 & 0xDF ) ) ;
F_4 ( V_3 -> V_209 , 0x63 , ( unsigned char ) ( V_753 & 0xBF ) ) ;
V_752 = ( unsigned char ) F_6 ( V_3 -> V_209 , 0x17 ) ;
F_4 ( V_3 -> V_209 , 0x17 , ( unsigned char ) ( V_752 | 0x80 ) ) ;
V_749 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x1F ) ;
F_4 ( V_3 -> V_200 , 0x1F , ( unsigned char ) ( V_749 | 0x04 ) ) ;
V_750 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x07 ) ;
F_4 ( V_3 -> V_200 , 0x07 , ( unsigned char ) ( V_750 & 0xFB ) ) ;
V_751 = ( unsigned char ) F_6 ( V_3 -> V_200 , 0x06 ) ;
F_4 ( V_3 -> V_200 , 0x06 , ( unsigned char ) ( V_751 & 0xC3 ) ) ;
F_4 ( V_3 -> V_209 , 0x11 , 0x00 ) ;
for ( V_196 = 0 ; V_196 < 8 ; V_196 ++ )
F_4 ( V_3 -> V_209 , ( unsigned short ) V_196 , V_747 [ V_196 ] ) ;
for ( V_196 = 8 ; V_196 < 11 ; V_196 ++ )
F_4 ( V_3 -> V_209 , ( unsigned short ) ( V_196 + 8 ) ,
V_747 [ V_196 ] ) ;
for ( V_196 = 11 ; V_196 < 13 ; V_196 ++ )
F_4 ( V_3 -> V_209 , ( unsigned short ) ( V_196 + 4 ) ,
V_747 [ V_196 ] ) ;
for ( V_196 = 13 ; V_196 < 16 ; V_196 ++ )
F_4 ( V_3 -> V_200 , ( unsigned short ) ( V_196 - 3 ) ,
V_747 [ V_196 ] ) ;
F_4 ( V_3 -> V_200 , 0x0E , ( unsigned char ) ( V_747 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_200 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_200 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_200 , 0x2C , 0xE1 ) ;
F_9 ( 0x00 , V_3 -> V_361 ) ;
for ( V_196 = 0 ; V_196 < 256 ; V_196 ++ ) {
F_9 ( ( unsigned char ) V_755 [ 0 ] , ( V_3 -> V_361 + 1 ) ) ;
F_9 ( ( unsigned char ) V_755 [ 1 ] , ( V_3 -> V_361 + 1 ) ) ;
F_9 ( ( unsigned char ) V_755 [ 2 ] , ( V_3 -> V_361 + 1 ) ) ;
}
F_62 ( 1 ) ;
F_65 ( V_3 ) ;
V_259 = F_8 ( V_3 -> V_260 ) ;
if ( V_259 & 0x10 )
F_13 ( V_3 -> V_209 , 0x32 , 0xDF , 0x20 ) ;
else
F_13 ( V_3 -> V_209 , 0x32 , 0xDF , 0x00 ) ;
F_9 ( 0x00 , V_3 -> V_361 ) ;
for ( V_196 = 0 ; V_196 < 256 ; V_196 ++ ) {
F_9 ( 0 , ( V_3 -> V_361 + 1 ) ) ;
F_9 ( 0 , ( V_3 -> V_361 + 1 ) ) ;
F_9 ( 0 , ( V_3 -> V_361 + 1 ) ) ;
}
F_4 ( V_3 -> V_200 , 0x01 , V_748 ) ;
F_4 ( V_3 -> V_209 , 0x63 , V_753 ) ;
F_4 ( V_3 -> V_200 , 0x31 , V_754 ) ;
F_4 ( V_3 -> V_209 , 0x53 , ( unsigned char ) ( F_6 (
V_3 -> V_209 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_200 , 0x1F , ( unsigned char ) V_749 ) ;
}
static void F_119 ( struct V_622 * V_623 ,
struct V_206 * V_207 ,
struct V_2 * V_3 )
{
unsigned short V_194 ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
if ( ! ( V_3 -> V_243 & V_712 ) ) {
if ( V_3 -> V_243 & V_714 ) {
F_4 ( V_3 -> V_536 , 0x1E , 0x20 ) ;
} else {
if ( V_3 -> V_48 & V_575 ) {
F_4 ( V_3 -> V_536 ,
0x1E , 0x20 ) ;
}
}
}
if ( ! ( V_3 -> V_243 & V_713 ) ) {
if ( ( V_3 -> V_243 & V_715 ) || ( V_3 -> V_48
& ( V_204 | V_203
| V_230 ) ) ) {
V_194 = ( unsigned char ) F_6 (
V_3 -> V_200 , 0x32 ) ;
V_194 &= 0xDF ;
if ( V_3 -> V_48 & V_205 ) {
if ( ! ( V_3 -> V_48 &
V_230 ) )
V_194 |= 0x20 ;
}
F_4 ( V_3 -> V_200 , 0x32 , V_194 ) ;
F_21 ( V_3 -> V_200 , 0x1E , 0x20 ) ;
V_194 = ( unsigned char ) F_6 (
V_3 -> V_536 , 0x2E ) ;
if ( ! ( V_194 & 0x80 ) )
F_21 ( V_3 -> V_536 ,
0x2E , 0x80 ) ;
F_14 ( V_3 -> V_536 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_243 & ( V_714 | V_715 ) )
|| ( ! ( V_3 -> V_48 & V_576 ) ) ) {
F_13 ( V_3 -> V_562 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_147 & ( V_149 | V_232 ) ) {
if ( ! F_94 ( V_3 ) ) {
if ( F_95 ( V_3 ) ||
( V_3 -> V_48 &
( V_204 | V_202 ) ) )
F_14 (
V_3 -> V_543 ,
0x2A ,
0x7F ) ;
}
F_14 ( V_3 -> V_543 , 0x30 , 0x7F ) ;
}
}
V_194 = 0x00 ;
if ( ! ( V_3 -> V_48 & V_576 ) ) {
V_194 = 0xc0 ;
if ( ! ( V_3 -> V_48 & V_586 ) ) {
if ( V_3 -> V_48 & V_202 ) {
if ( V_3 -> V_48 &
V_575 ) {
V_194 = V_194 & 0x40 ;
if ( V_3 -> V_48 &
V_202 )
V_194 = V_194 ^ 0xC0 ;
if ( V_3 -> V_243 &
V_713 )
V_194 &= 0xBF ;
if ( V_3 -> V_243 &
V_712 )
V_194 &= 0x7F ;
if ( V_3 -> V_243 &
V_715 )
V_194 |= 0x40 ;
if ( V_3 -> V_243 &
V_714 )
V_194 |= 0x80 ;
}
}
}
}
F_21 ( V_3 -> V_543 , 0x1F , V_194 ) ;
if ( ! ( V_3 -> V_243 & V_712 ) ) {
if ( ! ( V_3 -> V_243 & V_716 ) ) {
F_90 ( V_207 ,
V_3 ) ;
F_63 ( V_623 , V_207 ,
V_3 ) ;
}
}
}
else {
if ( V_3 -> V_48 & ( V_203 | V_204
| V_202 ) )
F_21 ( V_3 -> V_536 , 0x1E , 0x20 ) ;
V_194 = ( unsigned char ) F_6 ( V_3 -> V_536 ,
0x2E ) ;
if ( ! ( V_194 & 0x80 ) )
F_21 ( V_3 -> V_536 , 0x2E , 0x80 ) ;
F_14 ( V_3 -> V_536 , 0x00 , 0x7F ) ;
F_63 ( V_623 , V_207 , V_3 ) ;
}
}
static void F_120 ( struct V_622 * V_623 ,
struct V_206 * V_207 ,
unsigned short V_188 , unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_193 , V_222 , V_280 , V_259 ;
unsigned short V_756 = V_3 -> V_282 ;
V_193 = F_2 ( V_188 , V_189 , V_3 ) ;
F_3 ( V_188 , V_193 , V_189 , V_3 ) ;
F_9 ( V_3 -> V_7 [ V_193 ] . V_757 , V_3 -> V_260 ) ;
F_5 ( V_207 , V_193 , V_3 ) ;
F_7 ( V_188 , V_193 , V_189 , V_3 ) ;
F_10 ( V_193 , V_3 ) ;
F_11 ( V_3 ) ;
if ( V_207 -> V_265 == V_162 ) {
if ( V_3 -> V_229 == 0 )
F_12 ( V_3 ) ;
}
V_259 = ~ V_550 ;
V_3 -> V_243 &= V_259 ;
V_3 -> V_743 = 0 ;
if ( V_3 -> V_147 & ( V_250 | V_251 | V_148
| V_149 | V_232 ) ) {
if ( V_3 -> V_48 & ( V_586 | V_202
| V_205 ) ) {
V_3 -> V_243 |= V_550 ;
}
}
V_222 = F_115 ( V_207 , V_188 ,
V_189 , V_3 ) ;
if ( V_222 != 0xFFFF ) {
F_16 ( V_222 , V_3 ) ;
F_19 ( V_188 , V_189 , V_222 ,
V_3 , V_207 ) ;
F_27 ( V_207 , V_188 , V_189 ,
V_222 , V_3 ) ;
F_28 ( V_188 , V_189 , V_222 ,
V_207 , V_3 ) ;
F_30 ( V_188 , V_189 , V_207 ,
V_222 , V_3 ) ;
}
if ( ( V_207 -> V_265 >= V_159 ) &&
( V_207 -> V_265 < V_162 ) ) {
if ( ( V_188 == 0x00 ) | ( V_188 == 0x01 ) ) {
F_4 ( V_3 -> V_200 , 0x2B , 0x4E ) ;
F_4 ( V_3 -> V_200 , 0x2C , 0xE9 ) ;
V_280 = ( unsigned char ) F_8 ( V_756 ) ;
F_9 ( ( V_280 |= 0x0C ) , V_756 ) ;
} else if ( ( V_188 == 0x04 ) | ( V_188 == 0x05 ) | ( V_188
== 0x0D ) ) {
F_4 ( V_3 -> V_200 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_200 , 0x2C , 0xE3 ) ;
V_280 = ( unsigned char ) F_8 ( V_756 ) ;
F_9 ( ( V_280 |= 0x0C ) , V_756 ) ;
}
}
if ( V_207 -> V_265 >= V_335 ) {
V_259 = F_6 ( V_3 -> V_209 , 0x38 ) ;
if ( V_259 & 0xA0 ) {
if ( V_207 -> V_265 == V_162 )
F_22 ( V_188 , V_189 ,
V_222 , V_3 ) ;
else
F_20 ( V_188 , V_189 ,
V_222 , V_3 ) ;
F_25 ( V_188 , V_3 ,
V_222 ) ;
F_24 ( V_207 -> V_265 ,
V_3 , V_222 , V_188 ) ;
if ( V_3 -> V_229 == 1 )
F_92 ( V_623 ,
V_207 -> V_265 ,
V_188 , V_189 , V_3 ) ;
}
}
V_3 -> V_243 &= ( ~ V_550 ) ;
F_32 ( V_188 , V_207 , V_3 ) ;
F_34 ( V_207 , V_188 , V_189 ,
V_222 , V_3 ) ;
F_36 ( V_188 , V_189 , V_3 ) ;
}
unsigned char F_121 ( struct V_622 * V_623 ,
struct V_206 * V_207 ,
unsigned short V_188 )
{
unsigned short V_189 ;
struct V_2 V_758 ;
struct V_2 * V_3 = & V_758 ;
V_3 -> V_759 = ( unsigned long ) V_207 -> V_760 ;
V_3 -> V_229 = 0 ;
V_3 -> V_577 = 1 ;
if ( V_207 -> V_265 >= V_159 ) {
V_3 -> V_581 = 0 ;
V_3 -> V_583 = 0 ;
V_3 -> V_588 = 0 ;
V_3 -> V_147 = 0 ;
} else {
V_3 -> V_581 = 1 ;
V_3 -> V_583 = 1 ;
V_3 -> V_588 = 1 ;
}
V_3 -> V_200 = V_3 -> V_759 + 0x14 ;
V_3 -> V_209 = V_3 -> V_759 + 0x24 ;
V_3 -> V_215 = V_3 -> V_759 + 0x10 ;
V_3 -> V_218 = V_3 -> V_759 + 0x1e ;
V_3 -> V_260 = V_3 -> V_759 + 0x12 ;
V_3 -> V_282 = V_3 -> V_759 + 0x1C ;
V_3 -> V_327 = V_3 -> V_759 + 0x1a ;
V_3 -> V_360 = V_3 -> V_759 + 0x16 ;
V_3 -> V_761 = V_3 -> V_759 + 0x17 ;
V_3 -> V_361 = V_3 -> V_759 + 0x18 ;
V_3 -> V_346 = V_3 -> V_759 + 0x19 ;
V_3 -> V_214 = V_3 -> V_759 + 0x2A ;
V_3 -> V_762 = V_3 -> V_759 + V_763 ;
V_3 -> V_536 = V_3 -> V_759 + V_764 ;
V_3 -> V_562 = V_3 -> V_759 + V_765 ;
V_3 -> V_682 = V_3 -> V_759 + V_766 ;
V_3 -> V_543 = V_3 -> V_759 + V_767 ;
V_3 -> V_687 = V_3 -> V_759 + V_767 + 2 ;
if ( V_207 -> V_265 == V_335 ) {
if ( ( F_6 ( V_3 -> V_209 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_229 = 1 ;
}
if ( V_207 -> V_265 == V_162 ) {
if ( ( F_6 ( V_3 -> V_209 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_6 ( V_3 -> V_209 , 0x30 ) & 0x20 )
V_3 -> V_229 = 1 ;
}
}
if ( V_207 -> V_265 < V_159 )
F_51 ( V_3 ) ;
F_1 ( V_207 -> V_265 , V_3 ) ;
if ( V_188 & 0x80 )
V_188 = V_188 & 0x7F ;
F_4 ( V_3 -> V_200 , 0x05 , 0x86 ) ;
if ( V_207 -> V_265 < V_159 )
F_112 ( V_207 , V_3 ) ;
F_55 ( V_188 , & V_189 , V_3 ) ;
if ( V_207 -> V_265 < V_159 ) {
F_52 ( V_188 , V_189 , V_207 , V_3 ) ;
F_53 ( V_188 , V_189 , V_3 ) ;
F_54 ( V_188 , V_189 , V_3 ) ;
F_96 ( V_623 , V_207 , V_3 ) ;
if ( V_3 -> V_48 & ( V_586 | V_202 ) ) {
F_120 ( V_623 , V_207 , V_188 ,
V_189 , V_3 ) ;
if ( V_3 -> V_48 & V_202 ) {
F_116 ( V_188 , V_189 ,
V_207 , V_3 ) ;
}
} else {
if ( ! ( V_3 -> V_48 & V_587 ) ) {
F_120 ( V_623 ,
V_207 , V_188 ,
V_189 , V_3 ) ;
if ( V_3 -> V_48 & V_202 ) {
F_116 ( V_188 , V_189 ,
V_207 ,
V_3 ) ;
}
}
}
if ( V_3 -> V_48 & ( V_586 | V_587 ) ) {
switch ( V_207 -> V_768 ) {
case V_769 :
F_117 ( V_188 , V_207 ,
V_3 ) ;
break;
case V_770 :
F_117 ( V_188 , V_207 ,
V_3 ) ;
break;
default:
break;
}
}
F_110 ( V_188 , V_207 , V_3 ) ;
F_109 ( V_188 , V_189 , V_3 ) ;
F_111 ( V_207 , V_3 ) ;
F_119 ( V_623 , V_207 , V_3 ) ;
}
else {
if ( V_3 -> V_229 == 1 )
if ( ! F_91 ( V_623 , V_188 ,
V_189 ,
V_3 ) )
return 0 ;
if ( V_188 <= 0x13 ) {
V_3 -> V_192 = V_3 -> V_4 [ V_189 ] .
V_198 & V_574 ;
} else {
V_3 -> V_192 = V_3 -> V_10 [ V_189 ] .
V_199 & V_574 ;
}
V_3 -> V_243 = 0 ;
V_3 -> V_48 = V_576 ;
F_64 ( V_623 , V_207 , V_3 ) ;
F_120 ( V_623 , V_207 , V_188 ,
V_189 , V_3 ) ;
F_63 ( V_623 , V_207 , V_3 ) ;
}
F_50 ( V_207 , V_3 ) ;
if ( V_207 -> V_265 < V_159 ) {
F_113 ( V_207 , V_3 ) ;
}
return 1 ;
}
