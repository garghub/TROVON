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
unsigned char V_163 ;
V_3 -> V_19
= (struct V_20 * ) V_164 ;
V_3 -> V_52 = V_165 ;
V_3 -> V_160 = & V_166 ;
V_3 -> V_167 = & V_168 ;
V_3 -> V_169 = & V_170 ;
V_3 -> V_171 = V_172 ;
V_3 -> V_173 = V_174 ;
V_3 -> V_175 = & V_176 ;
V_3 -> V_177 = & V_178 ;
V_3 -> V_50 = V_179 ;
V_163 = F_2 ( V_3 -> V_180 , 0x3B ) ;
if ( ( ( V_163 & 0x88 ) == 0x80 ) || ( ( V_163 & 0x88 ) == 0x08 ) )
V_3 -> V_160 = & V_181 ;
}
if ( V_1 >= V_159 ) {
V_3 -> V_182 = & V_183 ;
V_3 -> V_184 = & V_185 ;
V_3 -> V_186 = & V_187 ;
V_3 -> V_188 = & V_189 ;
V_3 -> V_190 = & V_191 ;
}
}
static unsigned char F_3 ( unsigned short V_192 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned char V_194 ;
if ( V_192 <= 0x13 )
V_194 = V_3 -> V_4 [ V_193 ] . V_195 ;
else {
if ( V_3 -> V_196 <= 0x02 )
V_194 = 0x1B ;
else
V_194 = 0x0F ;
}
return V_194 ;
}
static void F_4 ( unsigned short V_192 ,
unsigned short V_197 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned char V_198 , V_199 ;
unsigned short V_200 , V_201 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
F_5 ( V_3 -> V_180 , 0x00 , 0x03 ) ;
V_198 = V_3 -> V_7 [ V_197 ] . V_204 [ 0 ] ;
V_200 = V_205 ;
if ( V_3 -> V_48 & V_205 ) {
V_198 |= 0x01 ;
} else {
if ( V_3 -> V_48 & ( V_206 | V_207 ) ) {
if ( V_3 -> V_48 & V_208 )
V_198 |= 0x01 ;
}
}
V_198 |= 0x20 ;
F_5 ( V_3 -> V_180 , 0x01 , V_198 ) ;
for ( V_200 = 02 ; V_200 <= 04 ; V_200 ++ ) {
V_199 = V_3 -> V_7 [ V_197 ] . V_204 [ V_200 - 1 ] ;
F_5 ( V_3 -> V_180 , V_200 , V_199 ) ;
}
}
static void F_6 ( struct V_209 * V_210 ,
unsigned short V_197 ,
struct V_2 * V_3 )
{
unsigned char V_211 ;
unsigned short V_200 ;
V_211 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x11 ) ;
V_211 &= 0x7f ;
F_5 ( V_3 -> V_212 , 0x11 , V_211 ) ;
for ( V_200 = 0 ; V_200 <= 0x18 ; V_200 ++ ) {
V_211 = V_3 -> V_7 [ V_197 ] . V_213 [ V_200 ] ;
F_5 ( V_3 -> V_212 , V_200 , V_211 ) ;
}
}
static void F_7 ( unsigned short V_192 ,
unsigned short V_197 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned char V_214 ;
unsigned short V_200 , V_201 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
for ( V_200 = 0 ; V_200 <= 0x13 ; V_200 ++ ) {
V_214 = V_3 -> V_7 [ V_197 ] . V_215 [ V_200 ] ;
if ( V_201 & V_216 ) {
if ( V_200 == 0x13 ) {
if ( V_3 -> V_48 & V_205 ) {
V_214 = 0 ;
} else {
if ( V_3 -> V_48 & ( V_206
| V_207 ) ) {
if ( V_3 -> V_48 &
V_208 )
V_214 = 0 ;
}
}
}
}
F_8 ( V_3 -> V_217 ) ;
F_9 ( V_200 , V_3 -> V_218 ) ;
F_9 ( V_214 , V_3 -> V_218 ) ;
}
F_8 ( V_3 -> V_217 ) ;
F_9 ( 0x14 , V_3 -> V_218 ) ;
F_9 ( 0x00 , V_3 -> V_218 ) ;
F_8 ( V_3 -> V_217 ) ;
F_9 ( 0x20 , V_3 -> V_218 ) ;
}
static void F_10 ( unsigned short V_197 ,
struct V_2 * V_3 )
{
unsigned char V_219 ;
unsigned short V_200 ;
for ( V_200 = 0 ; V_200 <= 0x08 ; V_200 ++ ) {
V_219 = V_3 -> V_7 [ V_197 ] . V_220 [ V_200 ] ;
F_5 ( V_3 -> V_221 , V_200 , V_219 ) ;
}
if ( V_3 -> V_196 > V_222 ) {
V_219 = ( unsigned char ) F_2 ( V_3 -> V_221 , 0x05 ) ;
V_219 &= 0xBF ;
F_5 ( V_3 -> V_221 , 0x05 , V_219 ) ;
}
}
static void F_11 ( struct V_2 * V_3 )
{
unsigned short V_200 ;
for ( V_200 = 0x0A ; V_200 <= 0x0E ; V_200 ++ )
F_5 ( V_3 -> V_180 , V_200 , 0x00 ) ;
}
static unsigned char F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 -> V_180 , 0x31 , ~ 0x30 , 0x20 ) ;
F_5 ( V_3 -> V_180 , 0x2B , V_3 -> V_25 [ 0 ] . V_223 ) ;
F_5 ( V_3 -> V_180 , 0x2C , V_3 -> V_25 [ 0 ] . V_224 ) ;
F_13 ( V_3 -> V_180 , 0x31 , ~ 0x30 , 0x10 ) ;
F_5 ( V_3 -> V_180 , 0x2B , V_3 -> V_25 [ 1 ] . V_223 ) ;
F_5 ( V_3 -> V_180 , 0x2C , V_3 -> V_25 [ 1 ] . V_224 ) ;
F_14 ( V_3 -> V_180 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_15 ( unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 , unsigned short * V_200 ,
struct V_2 * V_3 )
{
unsigned short V_226 , V_227 , V_228 , V_201 , V_229 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
V_227 = V_3 -> V_13 [ V_225 + ( * V_200 ) ] . V_231 ;
V_226 = 0 ;
if ( V_3 -> V_232 == 0 ) {
if ( V_3 -> V_48 & V_233 ) {
V_226 |= V_234 ;
if ( V_3 -> V_147 & V_235 )
V_226 |= V_236 ;
}
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_226 |= V_237 ;
if ( V_3 -> V_45 != V_238 ) {
if ( V_3 -> V_45 != V_239 ) {
if ( V_3 -> V_47 &
V_240 ) {
if ( V_228 >= 9 ) {
V_226 = 0 ;
return 0 ;
}
}
}
}
}
if ( V_3 -> V_48 & V_241 ) {
if ( ( V_3 -> V_147 & V_148 ) &&
( V_3 -> V_242 == V_243 ) ) {
V_226 |= V_244 ;
if ( V_3 -> V_48 & V_208 ) {
if ( V_228 == 4 )
return 0 ;
if ( V_228 == 3 )
return 0 ;
if ( V_228 > 7 )
return 0 ;
}
} else {
V_226 |= V_245 ;
if ( V_3 -> V_48 & V_208 ) {
if ( V_228 == 4 )
return 0 ;
if ( V_228 == 3 ) {
if ( V_3 -> V_246
& V_247 )
return 0 ;
}
if ( V_228 > 7 )
return 0 ;
}
}
} else {
if ( V_3 -> V_48 & ( V_248 |
V_249 |
V_250 |
V_251 |
V_241 ) ) {
V_226 |= V_252 ;
if ( V_3 -> V_147 & ( V_253 | V_254
| V_148 | V_149
| V_235 ) ) {
V_226 |= V_255 ;
}
if ( ! ( V_3 -> V_48 & V_256 ) ) {
if ( V_201 & V_257 ) {
if ( V_3 -> V_48 &
V_208 ) {
if ( ! ( V_3 -> V_48 &
V_258 ) ) {
return 0 ;
}
}
}
}
}
}
} else {
if ( V_3 -> V_48 & V_207 ) {
V_226 |= V_237 ;
if ( V_228 > 0x08 )
return 0 ;
if ( V_3 -> V_45 < V_259 ) {
if ( V_228 > 0x07 )
return 0 ;
if ( V_228 == 0x04 )
return 0 ;
}
}
}
for (; V_3 -> V_13 [ V_225 + ( * V_200 ) ] . V_231 ==
V_227 ; ( * V_200 ) -- ) {
V_229 = V_3 -> V_13 [ V_225 + ( * V_200 ) ] .
V_260 ;
if ( V_229 & V_226 )
return 1 ;
if ( ( * V_200 ) == 0 )
break;
}
for ( ( * V_200 ) = 0 ; ; ( * V_200 ) ++ ) {
V_229 = V_3 -> V_13 [ V_225 + ( * V_200 ) ] .
V_260 ;
if ( V_3 -> V_13 [ V_225 + ( * V_200 ) ] . V_231
!= V_227 ) {
return 0 ;
}
if ( V_229 & V_226 )
return 1 ;
}
return 1 ;
}
static void F_16 ( unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_261 , V_163 ;
V_261 = V_3 -> V_13 [ V_225 ] . V_260 >> 8 ;
V_261 &= 0xC0 ;
V_163 = 0x2F ;
V_163 |= V_261 ;
F_9 ( V_163 , V_3 -> V_262 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_209 * V_210 )
{
unsigned char V_263 , V_264 , V_265 ;
unsigned short V_200 , V_266 ;
V_263 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x11 ) ;
V_263 &= 0x7F ;
F_5 ( V_3 -> V_212 , 0x11 , V_263 ) ;
V_263 = V_3 -> V_138 [ 0 ] . V_263 [ 0 ] ;
F_5 ( V_3 -> V_212 , 0 , V_263 ) ;
for ( V_200 = 0x01 ; V_200 <= 0x04 ; V_200 ++ ) {
V_263 = V_3 -> V_138 [ 0 ] . V_263 [ V_200 ] ;
F_5 ( V_3 -> V_212 , ( unsigned short ) ( V_200 + 1 ) , V_263 ) ;
}
for ( V_200 = 0x05 ; V_200 <= 0x06 ; V_200 ++ ) {
V_263 = V_3 -> V_138 [ 0 ] . V_263 [ V_200 ] ;
F_5 ( V_3 -> V_180 , ( unsigned short ) ( V_200 + 6 ) , V_263 ) ;
}
V_266 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x0e ) ;
V_266 &= 0x1F ;
V_263 = V_3 -> V_138 [ 0 ] . V_263 [ 7 ] ;
V_263 &= 0xE0 ;
V_263 |= V_266 ;
F_5 ( V_3 -> V_180 , 0x0e , V_263 ) ;
if ( V_210 -> V_267 >= V_159 ) {
V_263 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x04 ) ;
V_263 = V_263 - 1 ;
F_5 ( V_3 -> V_212 , 0x04 , V_263 ) ;
V_263 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x05 ) ;
V_264 = V_263 ;
V_264 &= 0xE0 ;
V_263 &= 0x1F ;
if ( V_263 == 0 ) {
V_265 = V_263 ;
V_263 = ( unsigned char ) F_2 ( V_3 -> V_180 ,
0x0c ) ;
V_263 &= 0xFB ;
F_5 ( V_3 -> V_180 , 0x0c , V_263 ) ;
V_263 = V_265 ;
}
V_263 = V_263 - 1 ;
V_263 |= V_264 ;
F_5 ( V_3 -> V_212 , 0x05 , V_263 ) ;
V_263 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x0e ) ;
V_263 = V_263 >> 5 ;
V_263 = V_263 + 3 ;
if ( V_263 > 7 )
V_263 = V_263 - 7 ;
V_263 = V_263 << 5 ;
F_13 ( V_3 -> V_180 , 0x0e , ~ 0xE0 , V_263 ) ;
}
}
static void F_18 ( unsigned short V_193 ,
unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned char V_263 ;
unsigned short V_200 , V_266 ;
for ( V_200 = 0x00 ; V_200 <= 0x01 ; V_200 ++ ) {
V_263 = V_3 -> V_141 [ 0 ] . V_263 [ V_200 ] ;
F_5 ( V_3 -> V_212 , ( unsigned short ) ( V_200 + 6 ) , V_263 ) ;
}
for ( V_200 = 0x02 ; V_200 <= 0x03 ; V_200 ++ ) {
V_263 = V_3 -> V_141 [ 0 ] . V_263 [ V_200 ] ;
F_5 ( V_3 -> V_212 , ( unsigned short ) ( V_200 + 0x0e ) , V_263 ) ;
}
for ( V_200 = 0x04 ; V_200 <= 0x05 ; V_200 ++ ) {
V_263 = V_3 -> V_141 [ 0 ] . V_263 [ V_200 ] ;
F_5 ( V_3 -> V_212 , ( unsigned short ) ( V_200 + 0x11 ) , V_263 ) ;
}
V_266 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x0a ) ;
V_266 &= 0xC0 ;
V_263 = V_3 -> V_141 [ 0 ] . V_263 [ 6 ] ;
V_263 &= 0x3F ;
V_263 |= V_266 ;
F_5 ( V_3 -> V_180 , 0x0a , V_263 ) ;
V_263 = V_3 -> V_141 [ 0 ] . V_263 [ 6 ] ;
V_263 &= 0x80 ;
V_263 = V_263 >> 2 ;
if ( V_192 <= 0x13 )
V_200 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_200 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_200 &= V_268 ;
if ( V_200 )
V_263 |= 0x80 ;
V_266 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x09 ) ;
V_266 &= 0x5F ;
V_263 |= V_266 ;
F_5 ( V_3 -> V_212 , 0x09 , V_263 ) ;
}
static void F_19 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 ,
struct V_209 * V_210 )
{
unsigned char V_194 , V_263 ;
unsigned short V_200 ;
V_194 = V_3 -> V_13 [ V_225 ] . V_269 ;
V_194 = V_194 & V_270 ;
V_263 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x11 ) ;
V_263 &= 0x7F ;
F_5 ( V_3 -> V_212 , 0x11 , V_263 ) ;
for ( V_200 = 0 ; V_200 < 8 ; V_200 ++ )
V_3 -> V_138 [ 0 ] . V_263 [ V_200 ]
= V_3 -> V_16 [ V_194 ] . V_271 [ V_200 ] ;
for ( V_200 = 0 ; V_200 < 7 ; V_200 ++ )
V_3 -> V_141 [ 0 ] . V_263 [ V_200 ]
= V_3 -> V_16 [ V_194 ] . V_271 [ V_200 + 8 ] ;
F_17 ( V_3 , V_210 ) ;
F_18 ( V_193 , V_192 , V_3 ) ;
if ( V_3 -> V_196 > 0x03 )
F_5 ( V_3 -> V_212 , 0x14 , 0x4F ) ;
}
static void F_20 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned char V_197 , V_194 , V_272 , V_273 , V_274 , V_275 ;
unsigned short V_276 , V_277 , V_278 ;
if ( V_192 <= 0x13 ) {
V_197 = F_3 ( V_192 , V_193 , V_3 ) ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 4 ] ;
F_5 ( V_3 -> V_180 , 0x2E , V_272 ) ;
V_273 = V_3 -> V_7 [ V_197 ] . V_213 [ 5 ] ;
V_273 &= 0x1F ;
V_274 = V_272 ;
V_274 &= 0xE0 ;
V_275 = V_274 | V_273 ;
if ( V_273 < ( V_272 & 0x1F ) )
V_275 |= 0x20 ;
V_275 <<= 2 ;
F_5 ( V_3 -> V_180 , 0x2F , V_275 ) ;
F_13 ( V_3 -> V_180 , 0x30 , 0xE3 , 00 ) ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 16 ] ;
V_273 = V_272 ;
V_272 &= 0x01 ;
F_21 ( V_3 -> V_180 , 0x33 , V_272 ) ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 7 ] ;
V_275 = V_273 >> 1 ;
V_274 = V_272 & 0x04 ;
V_274 <<= 5 ;
V_275 |= V_274 ;
F_5 ( V_3 -> V_180 , 0x34 , V_275 ) ;
V_276 = V_274 << 1 ;
V_276 |= V_273 ;
V_272 &= 0x80 ;
V_277 = V_272 << 2 ;
V_276 |= V_277 ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 17 ] ;
V_272 &= 0x0F ;
V_277 = V_276 & 0x3F0 ;
V_277 |= V_272 ;
V_278 = V_276 & 0x0F ;
if ( V_272 < V_278 )
V_277 |= 0x10 ;
V_277 &= 0xFF ;
V_272 = ( unsigned char ) V_277 ;
V_272 <<= 2 ;
V_276 &= 0x600 ;
V_276 >>= 9 ;
V_273 = ( unsigned char ) V_276 ;
V_272 |= V_273 ;
V_272 &= 0x7F ;
F_5 ( V_3 -> V_180 , 0x3F , V_272 ) ;
} else {
V_194 = V_3 -> V_13 [ V_225 ] . V_269 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 3 ] ;
V_274 = V_272 ;
F_5 ( V_3 -> V_180 , 0x2E , V_272 ) ;
V_275 = V_3 -> V_16 [ V_194 ] . V_271 [ 5 ] ;
V_275 &= 0xC0 ;
V_276 = V_275 ;
V_276 <<= 2 ;
V_276 |= V_272 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 4 ] ;
V_272 &= 0x1F ;
V_273 = V_3 -> V_16 [ V_194 ] . V_271 [ 6 ] ;
V_273 &= 0x04 ;
V_273 <<= 3 ;
V_272 |= V_273 ;
V_277 = V_276 & 0x3C0 ;
V_277 |= V_272 ;
V_274 &= 0x3F ;
if ( V_272 < V_274 )
V_277 |= 0x40 ;
V_277 &= 0xFF ;
V_272 = ( unsigned char ) V_277 ;
V_272 <<= 2 ;
V_275 >>= 6 ;
V_272 |= V_275 ;
F_5 ( V_3 -> V_180 , 0x2F , V_272 ) ;
F_13 ( V_3 -> V_180 , 0x30 , 0xE3 , 00 ) ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 10 ] ;
V_273 = V_272 ;
V_272 &= 0x01 ;
F_21 ( V_3 -> V_180 , 0x33 , V_272 ) ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 9 ] ;
V_274 = V_273 >> 1 ;
V_275 = V_272 & 0x04 ;
V_275 <<= 5 ;
V_274 |= V_275 ;
F_5 ( V_3 -> V_180 , 0x34 , V_274 ) ;
V_276 = V_275 ;
V_276 <<= 1 ;
V_276 |= V_273 ;
V_272 &= 0x80 ;
V_277 = V_272 << 2 ;
V_276 |= V_277 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 14 ] ;
V_272 &= 0x08 ;
V_277 = V_272 ;
V_277 <<= 7 ;
V_276 |= V_277 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 11 ] ;
V_272 &= 0x0F ;
V_273 = V_3 -> V_16 [ V_194 ] . V_271 [ 14 ] ;
V_273 &= 0x20 ;
V_273 >>= 1 ;
V_272 |= V_273 ;
V_277 = V_276 & 0x7E0 ;
V_277 |= V_272 ;
V_278 = V_276 & 0x1F ;
if ( V_272 < V_278 )
V_277 |= 0x20 ;
V_277 &= 0xFF ;
V_272 = ( unsigned char ) V_277 ;
V_272 <<= 2 ;
V_276 &= 0x600 ;
V_276 >>= 9 ;
V_273 = ( unsigned char ) V_276 ;
V_272 |= V_273 ;
V_272 &= 0x7F ;
F_5 ( V_3 -> V_180 , 0x3F , V_272 ) ;
}
}
static void F_22 ( unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_197 , V_194 , V_272 , V_273 , V_274 , V_275 ;
if ( V_192 <= 0x13 ) {
V_197 = F_3 ( V_192 , V_193 , V_3 ) ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 4 ] ;
F_5 ( V_3 -> V_180 , 0x2E , V_272 ) ;
V_273 = V_3 -> V_7 [ V_197 ] . V_213 [ 5 ] ;
V_273 &= 0x1F ;
V_274 = V_272 ;
V_274 &= 0xE0 ;
V_275 = V_274 | V_273 ;
if ( V_273 < ( V_272 & 0x1F ) )
V_275 |= 0x20 ;
V_275 <<= 2 ;
F_5 ( V_3 -> V_180 , 0x2F , V_275 ) ;
F_13 ( V_3 -> V_180 , 0x30 , 0xE3 , 00 ) ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 16 ] ;
F_5 ( V_3 -> V_180 , 0x34 , V_272 ) ;
V_274 = V_272 ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 7 ] ;
V_273 = V_272 ;
V_272 &= 0x04 ;
V_272 >>= 2 ;
F_13 ( V_3 -> V_180 , 0x35 , ~ 0x01 , V_272 ) ;
V_274 |= ( V_272 << 8 ) ;
V_274 |= ( V_273 & 0x80 ) << 2 ;
V_272 = V_3 -> V_7 [ V_197 ] . V_213 [ 17 ] ;
V_272 &= 0x0F ;
V_273 = V_274 ;
V_273 &= 0x3F0 ;
V_273 |= V_272 ;
if ( V_272 <= ( V_274 & 0x0F ) )
V_273 |= 0x10 ;
V_272 = ( unsigned char ) V_273 & 0xFF ;
V_272 <<= 2 ;
V_274 = ( V_274 & 0x600 ) >> 8 ;
F_13 ( V_3 -> V_180 , 0x3F , ~ 0xFC , V_272 ) ;
F_13 ( V_3 -> V_180 , 0x35 , ~ 0x06 , V_274 ) ;
} else {
V_194 = V_3 -> V_13 [ V_225 ] . V_269 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 3 ] ;
V_273 = V_272 ;
F_5 ( V_3 -> V_180 , 0x2E , V_272 ) ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 5 ] ;
V_272 &= 0xC0 ;
V_273 |= ( V_272 << 2 ) ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 4 ] ;
V_272 &= 0x1F ;
V_274 = V_272 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 6 ] ;
V_272 &= 0x04 ;
V_272 <<= 3 ;
V_274 |= V_272 ;
V_273 = V_273 & 0x3C0 ;
V_273 |= V_274 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 3 ] ;
V_272 &= 0x3F ;
if ( V_274 <= V_272 )
V_273 += 0x40 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 5 ] ;
V_272 &= 0xC0 ;
V_272 >>= 6 ;
V_272 |= ( ( V_273 << 2 ) & 0xFF ) ;
F_5 ( V_3 -> V_180 , 0x2F , V_272 ) ;
F_13 ( V_3 -> V_180 , 0x30 , 0xE3 , 00 ) ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 10 ] ;
F_5 ( V_3 -> V_180 , 0x34 , V_272 ) ;
V_274 = V_272 ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 9 ] ;
V_273 = V_272 ;
V_272 = V_272 & 0x04 ;
V_272 >>= 2 ;
F_13 ( V_3 -> V_180 , 0x35 , ~ 0x01 , V_272 ) ;
V_274 |= ( V_272 << 8 ) ;
V_274 |= ( ( V_273 & 0x80 ) << 2 ) ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 14 ] ;
V_272 &= 0x08 ;
V_274 |= ( V_272 << 7 ) ;
V_272 = V_3 -> V_16 [ V_194 ] . V_271 [ 11 ] ;
V_272 &= 0x0F ;
V_273 = V_3 -> V_16 [ V_194 ] . V_271 [ 14 ] ;
V_273 &= 0x20 ;
V_273 >>= 1 ;
V_272 |= V_273 ;
V_273 = V_274 ;
V_273 &= 0x7E0 ;
V_273 |= V_272 ;
if ( V_273 <= V_274 )
V_273 |= 0x20 ;
V_272 = ( V_273 << 2 ) & 0xFF ;
F_13 ( V_3 -> V_180 , 0x3F , ~ 0xFC , V_272 ) ;
V_272 = V_274 >> 8 ;
F_13 ( V_3 -> V_180 , 0x35 , ~ 0x07 , V_272 ) ;
}
}
static void F_23 ( struct V_2 * V_3 )
{
unsigned char V_163 ;
V_163 = F_2 ( V_3 -> V_212 , 0x37 ) ;
V_163 = ( V_163 & 3 ) << 6 ;
F_13 ( V_3 -> V_180 , 0x06 , ~ 0xc0 , V_163 & 0x80 ) ;
F_13 ( V_3 -> V_180 , 0x09 , ~ 0xc0 , V_163 | 0x80 ) ;
}
static void F_24 ( int V_279 ,
struct V_2 * V_3 ,
unsigned short V_225 ,
unsigned short V_192 )
{
unsigned short V_280 , V_281 , V_282 ;
unsigned short V_283 ;
V_283 = V_3 -> V_284 ;
F_5 ( V_3 -> V_212 , 0x2E , 0x00 ) ;
F_5 ( V_3 -> V_212 , 0x2F , 0x00 ) ;
F_5 ( V_3 -> V_212 , 0x46 , 0x00 ) ;
F_5 ( V_3 -> V_212 , 0x47 , 0x00 ) ;
if ( V_279 == V_162 ) {
V_281 = F_2 ( V_3 -> V_212 , 0x37 ) ;
if ( ( V_281 & 0x03 ) == 0 ) {
F_5 ( V_3 -> V_212 , 0x46 , 0x13 ) ;
F_5 ( V_3 -> V_212 , 0x47 , 0x13 ) ;
}
}
if ( ( ( * V_3 -> V_182 ) & 0xC0 ) == 0xC0 ) {
F_5 ( V_3 -> V_212 , 0x2E , * V_3 -> V_184 ) ;
F_5 ( V_3 -> V_212 , 0x2F , * V_3 -> V_186 ) ;
F_5 ( V_3 -> V_212 , 0x46 , * V_3 -> V_188 ) ;
F_5 ( V_3 -> V_212 , 0x47 , * V_3 -> V_190 ) ;
}
if ( V_279 == V_162 ) {
F_23 ( V_3 ) ;
} else {
V_281 = F_2 ( V_3 -> V_212 , 0x37 ) ;
if ( V_281 & 0x01 ) {
F_21 ( V_3 -> V_180 , 0x06 , 0x40 ) ;
F_21 ( V_3 -> V_180 , 0x09 , 0x40 ) ;
}
}
F_21 ( V_3 -> V_180 , 0x1E , 0x01 ) ;
F_14 ( V_3 -> V_180 , 0x30 , ~ 0x20 ) ;
F_14 ( V_3 -> V_180 , 0x35 , ~ 0x80 ) ;
if ( V_192 <= 0x13 ) {
V_282 = ( unsigned char ) F_8 ( V_283 ) ;
if ( V_282 & 0x40 )
F_21 ( V_3 -> V_180 , 0x30 , 0x20 ) ;
if ( V_282 & 0x80 )
F_21 ( V_3 -> V_180 , 0x35 , 0x80 ) ;
} else {
V_280 = V_3 -> V_13 [ V_225 ] . V_260 ;
if ( V_280 & 0x4000 )
F_21 ( V_3 -> V_180 , 0x30 , 0x20 ) ;
if ( V_280 & 0x8000 )
F_21 ( V_3 -> V_180 , 0x35 , 0x80 ) ;
}
}
static void F_25 ( unsigned short V_192 ,
struct V_2 * V_3 ,
unsigned short V_225 )
{
int V_200 , V_194 = - 1 ;
F_14 ( V_3 -> V_212 , 0x11 , 0x7F ) ;
if ( V_192 <= 0x13 ) {
for ( V_200 = 0 ; V_200 < 12 ; V_200 ++ ) {
if ( V_192 == V_3 -> V_144 [ V_200 ] . V_231 )
V_194 = V_200 ;
}
} else {
if ( V_192 == 0x2E &&
( V_3 -> V_13 [ V_225 ] . V_269 ==
V_285 ) )
V_194 = 12 ;
else if ( V_192 == 0x2E &&
( V_3 -> V_13 [ V_225 ] .
V_269 == V_286 ) )
V_194 = 13 ;
else if ( V_192 == 0x2F )
V_194 = 14 ;
else if ( V_192 == 0x50 )
V_194 = 15 ;
else if ( V_192 == 0x59 )
V_194 = 16 ;
}
if ( V_194 != - 1 ) {
F_5 ( V_3 -> V_212 , 0x02 ,
V_3 -> V_144 [ V_194 ] . V_287 ) ;
F_5 ( V_3 -> V_212 , 0x03 ,
V_3 -> V_144 [ V_194 ] . V_288 ) ;
F_5 ( V_3 -> V_212 , 0x15 ,
V_3 -> V_144 [ V_194 ] . V_289 ) ;
F_5 ( V_3 -> V_212 , 0x16 ,
V_3 -> V_144 [ V_194 ] . V_290 ) ;
}
}
static unsigned short F_26 ( unsigned short V_192 ,
unsigned short V_193 , struct V_2 * V_3 )
{
unsigned short V_291 ;
if ( V_192 <= 0x13 )
V_291 = V_3 -> V_4 [ V_193 ] . V_292 ;
else
V_291 = V_3 -> V_10 [ V_193 ] . V_230 ;
return V_291 ;
}
static void F_27 ( struct V_209 * V_210 ,
unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_291 , V_226 , V_227 , V_293 , V_163 , V_201 ;
unsigned char V_263 ;
V_291 = F_26 ( V_192 , V_193 , V_3 ) ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_226 = V_3 -> V_33 [ V_291 ] . V_294 ;
V_227 = V_3 -> V_33 [ V_291 ] . V_295 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_226 = V_3 -> V_36 [ V_291 ] . V_294 ;
V_227 = V_3 -> V_36 [ V_291 ] . V_295 ;
}
if ( V_201 & V_296 )
V_226 = V_226 >> 1 ;
if ( V_192 > 0x13 ) {
if ( V_201 & V_296 )
V_226 = V_226 << 1 ;
V_163 = V_3 -> V_13 [ V_225 ] . V_260 ;
if ( V_163 & V_297 )
V_227 = V_227 >> 1 ;
if ( V_201 & V_268 )
V_227 = V_227 << 1 ;
}
V_293 = 8 ;
V_226 /= V_293 ;
V_226 -= 1 ;
V_227 -= 1 ;
V_293 = V_226 ;
V_163 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x11 ) ;
V_263 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x11 ) ;
V_263 &= 0x7F ;
F_5 ( V_3 -> V_212 , 0x11 , V_263 ) ;
F_5 ( V_3 -> V_212 , 0x01 , ( unsigned short ) ( V_293 & 0xff ) ) ;
F_13 ( V_3 -> V_212 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_293 & 0x0ff00 ) >> 10 ) ) ;
F_5 ( V_3 -> V_212 , 0x12 , ( unsigned short ) ( V_227 & 0xff ) ) ;
V_226 = 0 ;
V_227 = V_227 >> 8 ;
if ( V_227 & 0x01 )
V_226 |= 0x02 ;
if ( V_227 & 0x02 )
V_226 |= 0x40 ;
F_13 ( V_3 -> V_212 , 0x07 , ~ 0x42 , V_226 ) ;
V_263 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x07 ) ;
V_263 &= 0xFF ;
V_226 = 0 ;
if ( V_227 & 0x04 )
V_226 |= 0x02 ;
F_13 ( V_3 -> V_212 , 0x0a , ~ 0x02 , V_226 ) ;
F_5 ( V_3 -> V_212 , 0x11 , V_163 ) ;
}
static void F_28 ( unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_163 , V_298 , V_299 , V_300 , V_200 , V_301 ;
V_163 = V_3 -> V_10 [ V_193 ] . V_302 ;
V_163 = V_163 >> 8 ;
V_163 = V_3 -> V_31 [ V_163 ] ;
V_300 = V_3 -> V_13 [ V_225 ] . V_260 ;
V_300 &= V_297 ;
if ( V_300 )
V_163 = V_163 << 1 ;
V_300 = V_3 -> V_196 - V_303 ;
switch ( V_300 ) {
case 0 :
V_300 = 1 ;
break;
case 1 :
V_300 = 2 ;
break;
case 2 :
V_300 = 4 ;
break;
case 3 :
V_300 = 4 ;
break;
case 4 :
V_300 = 6 ;
break;
case 5 :
V_300 = 8 ;
break;
default:
break;
}
if ( ( V_192 >= 0x26 ) && ( V_192 <= 0x28 ) )
V_163 = V_163 * V_300 + V_300 / 2 ;
else
V_163 *= V_300 ;
V_301 = V_163 ;
V_300 = V_163 ;
V_163 = V_163 >> 8 ;
V_163 &= 0x0F ;
V_200 = F_2 ( V_3 -> V_180 , 0x0E ) ;
V_200 &= 0xF0 ;
V_200 |= V_163 ;
F_5 ( V_3 -> V_180 , 0x0E , V_200 ) ;
V_163 = ( unsigned char ) V_300 ;
V_163 &= 0xFF ;
F_5 ( V_3 -> V_212 , 0x13 , V_163 ) ;
V_300 = V_3 -> V_13 [ V_225 ] . V_260 ;
V_300 &= V_297 ;
if ( V_300 )
V_301 >>= 1 ;
V_301 = V_301 << 5 ;
V_298 = ( V_301 & 0xff00 ) >> 8 ;
V_299 = V_301 & 0x00ff ;
if ( V_299 == 0 )
V_298 += 1 ;
else
V_298 += 2 ;
if ( V_210 -> V_267 >= V_159 )
if ( ( V_192 == 0x4A ) | ( V_192 == 0x49 ) )
V_298 -= 1 ;
F_5 ( V_3 -> V_180 , 0x10 , V_298 ) ;
}
static unsigned short F_29 ( unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_304 [ 4 ] = { V_305 + 2 ,
V_305 + 2 ,
V_305 + 2 ,
V_305 + 2 } ;
unsigned short V_306 [ 4 ] = { V_307 + 5 ,
V_307 + 5 ,
V_307 + 5 ,
V_307 + 5 } ;
unsigned short V_308 [ 4 ] = { V_309 , V_309 , V_309 , V_309 } ;
unsigned short V_310 [ 4 ] = { V_305 + 2 ,
V_305 + 2 ,
V_305 + 2 ,
V_305 + 2 } ;
unsigned short V_311 [ 4 ] = { V_305 + 2 ,
V_305 + 2 ,
V_305 + 2 ,
V_305 + 2 } ;
unsigned short V_312 , V_313 ;
unsigned short V_201 , V_228 ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_228 = V_3 -> V_4 [ V_193 ] . V_292 ;
V_312 = V_3 -> V_4 [ V_193 ] . V_314 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
V_312 = V_3 -> V_13 [ V_225 ] .
V_315 ;
}
if ( V_3 -> V_232 == 0 ) {
V_312 = V_312 >> 6 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
if ( V_3 -> V_45 != V_259 )
V_313 = V_306 [ V_312 ] ;
else
V_313 = V_304 [ V_312 ] ;
} else if ( V_3 -> V_48 & V_241 ) {
if ( V_3 -> V_246 & V_316 ) {
V_313 = V_317 + V_318 ;
V_313 += 25 ;
} else {
V_313 = V_317 + V_319 ;
V_313 += 25 ;
}
if ( V_3 -> V_246 & V_247 ) {
if ( V_201 & V_216 ) {
V_313 = V_317 + V_320 ;
V_313 += 25 ;
} else {
V_313 = V_317 + V_321 ;
V_313 += 25 ;
}
}
if ( ( V_3 -> V_147 & V_148 ) &&
! ( V_3 -> V_242 == V_243 ) ) {
if ( V_3 -> V_242 == V_322 )
V_313 = V_323 ;
else if ( V_3 -> V_242 == V_324 )
V_313 = V_325 ;
else if ( V_3 -> V_246 & V_316 )
V_313 = V_326 ;
else
V_313 = V_327 ;
}
} else if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_246 & V_316 ) {
V_313 = V_317 + V_328 ;
V_313 += 25 ;
} else {
V_313 = V_317 + V_329 ;
V_313 += 25 ;
}
} else {
V_313 = ( unsigned char ) F_8 ( ( V_3 -> V_330 + 0x02 ) ) ;
V_313 = ( ( V_313 >> 2 ) & 0x03 ) ;
if ( V_192 > 0x13 ) {
V_313 = V_3 -> V_13 [
V_225 ] .
V_331 ;
V_313 &= V_270 ;
}
}
} else {
if ( V_192 <= 0x13 )
V_313 = V_312 ;
else
V_313 = V_312 ;
V_313 = V_313 >> 6 ;
if ( ( V_3 -> V_45 == V_332 ) ||
( V_3 -> V_45 == V_333 ) )
V_313 = V_308 [ V_313 ] ;
else if ( ( V_3 -> V_45 == V_259 ) ||
( V_3 -> V_45 == V_334 ) )
V_313 = V_310 [ V_313 ] ;
else
V_313 = V_311 [ V_313 ] ;
}
return V_313 ;
}
static void F_30 ( unsigned short V_192 ,
unsigned short V_193 ,
struct V_209 * V_210 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned char V_194 , V_263 ;
unsigned short V_335 ;
if ( V_3 -> V_232 == 1 ) {
V_194 = V_3 -> V_13 [ V_225 ] . V_331 ;
V_263 = F_2 ( V_3 -> V_180 , 0x31 ) & 0xCF ;
F_5 ( V_3 -> V_180 , 0x31 , V_263 ) ;
F_5 ( V_3 -> V_180 , 0x2B ,
V_3 -> V_25 [ V_194 ] . V_223 ) ;
F_5 ( V_3 -> V_180 , 0x2C ,
V_3 -> V_25 [ V_194 ] . V_224 ) ;
F_5 ( V_3 -> V_180 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) && ( V_3 -> V_48
& V_205 ) ) {
V_335 = F_29 ( V_192 , V_193 ,
V_225 , V_210 ,
V_3 ) ;
V_263 = F_2 ( V_3 -> V_180 , 0x31 ) & 0xCF ;
F_5 ( V_3 -> V_180 , 0x31 , V_263 ) ;
V_263 = V_3 -> V_28 [ V_335 ] . V_336 ;
F_5 ( V_3 -> V_180 , 0x2B , V_263 ) ;
V_263 = V_3 -> V_28 [ V_335 ] . V_337 ;
F_5 ( V_3 -> V_180 , 0x2C , V_263 ) ;
F_5 ( V_3 -> V_180 , 0x2D , 0x01 ) ;
} else {
V_194 = V_3 -> V_13 [ V_225 ] . V_331 ;
V_263 = F_2 ( V_3 -> V_180 , 0x31 ) & 0xCF ;
F_5 ( V_3 -> V_180 , 0x31 , V_263 ) ;
F_5 ( V_3 -> V_180 , 0x2B ,
V_3 -> V_25 [ V_194 ] . V_223 ) ;
F_5 ( V_3 -> V_180 , 0x2C ,
V_3 -> V_25 [ V_194 ] . V_224 ) ;
F_5 ( V_3 -> V_180 , 0x2D , 0x01 ) ;
}
if ( V_210 -> V_267 >= V_159 ) {
if ( V_3 -> V_10 [ V_193 ] . V_203 &
V_296 ) {
V_263 = F_2 ( V_3 -> V_180 , 0x2B ) ;
F_5 ( V_3 -> V_180 , 0x2B , V_263 ) ;
V_263 = F_2 ( V_3 -> V_180 , 0x2C ) ;
V_194 = V_263 ;
V_194 &= 0xE0 ;
V_263 &= 0x1F ;
V_263 = V_263 << 1 ;
V_263 += 1 ;
V_263 |= V_194 ;
F_5 ( V_3 -> V_180 , 0x2C , V_263 ) ;
}
}
}
static void F_31 ( struct V_2 * V_3 )
{
unsigned char V_163 ;
V_163 = F_2 ( V_3 -> V_212 , 0x37 ) ;
V_163 = ( V_163 & 1 ) << 6 ;
F_13 ( V_3 -> V_180 , 0x06 , ~ 0x40 , V_163 ) ;
F_13 ( V_3 -> V_180 , 0x09 , ~ 0xc0 , V_163 | 0x80 ) ;
}
static void F_32 ( unsigned short V_192 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_263 ;
V_263 = F_2 ( V_3 -> V_180 , 0x3D ) ;
V_263 &= 0xfe ;
F_5 ( V_3 -> V_180 , 0x3D , V_263 ) ;
if ( V_192 > 0x13 ) {
F_5 ( V_3 -> V_180 , 0x08 , 0x34 ) ;
V_263 = F_2 ( V_3 -> V_180 , 0x09 ) ;
V_263 &= 0xC0 ;
F_5 ( V_3 -> V_180 , 0x09 , V_263 | 0x30 ) ;
V_263 = F_2 ( V_3 -> V_180 , 0x3D ) ;
V_263 |= 0x01 ;
F_5 ( V_3 -> V_180 , 0x3D , V_263 ) ;
} else {
if ( V_210 -> V_267 == V_162 ) {
F_5 ( V_3 -> V_180 , 0x08 , 0x0E ) ;
V_263 = F_2 ( V_3 -> V_180 , 0x09 ) ;
V_263 &= 0xC0 ;
F_5 ( V_3 -> V_180 , 0x09 , V_263 | 0x20 ) ;
} else {
F_5 ( V_3 -> V_180 , 0x08 , 0xAE ) ;
V_263 = F_2 ( V_3 -> V_180 , 0x09 ) ;
V_263 &= 0xF0 ;
F_5 ( V_3 -> V_180 , 0x09 , V_263 ) ;
}
}
if ( V_210 -> V_267 == V_338 )
F_31 ( V_3 ) ;
}
static void F_33 ( struct V_209 * V_210 ,
unsigned short V_192 , unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_263 , V_339 = 0 ;
short V_340 ;
unsigned char V_194 ;
if ( V_192 <= 0x13 )
V_340 = 0 ;
else {
V_194 = V_3 -> V_13 [ V_225 ] . V_331 ;
V_194 &= V_270 ;
V_340 = V_3 -> V_25 [ V_194 ] . CLOCK ;
}
V_263 = F_2 ( V_3 -> V_180 , 0x32 ) ;
V_263 &= 0xf3 ;
if ( V_340 >= 200 )
V_263 |= 0x0c ;
if ( V_210 -> V_267 >= V_159 )
V_263 &= ~ 0x04 ;
F_5 ( V_3 -> V_180 , 0x32 , V_263 ) ;
if ( V_210 -> V_267 < V_159 ) {
V_263 = F_2 ( V_3 -> V_180 , 0x1F ) ;
V_263 &= 0xE7 ;
if ( V_340 < 200 )
V_263 |= 0x10 ;
F_5 ( V_3 -> V_180 , 0x1F , V_263 ) ;
}
V_339 = 0x00 ;
F_13 ( V_3 -> V_180 , 0x07 , 0xFC , V_339 ) ;
if ( V_210 -> V_267 >= V_162 )
F_13 ( V_3 -> V_180 , 0x40 , 0xFC , V_339 & 0x03 ) ;
}
static void F_34 ( struct V_209 * V_210 ,
unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_263 , V_339 , V_341 , V_229 = 0 , V_201 , V_291 ,
V_342 ;
if ( V_192 > 0x13 ) {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_229 = V_3 -> V_13 [ V_225 ] .
V_260 ;
} else
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
if ( F_2 ( V_3 -> V_212 , 0x31 ) & 0x01 )
F_13 ( V_3 -> V_180 , 0x1F , 0x3F , 0x00 ) ;
if ( V_192 > 0x13 )
V_263 = V_229 ;
else
V_263 = 0 ;
V_339 = 0 ;
if ( V_192 > 0x13 ) {
if ( V_3 -> V_196 > 0x02 ) {
V_339 |= 0x02 ;
V_341 = V_3 -> V_196 - V_222 ;
V_341 = V_341 << 2 ;
V_339 |= V_341 ;
}
}
V_263 &= V_297 ;
if ( V_263 )
V_339 |= 0x20 ;
F_13 ( V_3 -> V_180 , 0x06 , ~ 0x3F , V_339 ) ;
V_291 = F_26 ( V_192 , V_193 , V_3 ) ;
if ( V_192 <= 0x13 )
V_342 = V_3 -> V_33 [ V_291 ] . V_294 ;
else
V_342 = V_3 -> V_36 [ V_291 ] . V_294 ;
V_263 = 0x0000 ;
if ( V_229 & V_297 ) {
if ( V_342 == 1024 )
V_263 = 0x0035 ;
else if ( V_342 == 1280 )
V_263 = 0x0048 ;
}
V_339 = V_263 & 0x00FF ;
F_13 ( V_3 -> V_212 , 0x19 , 0xFF , V_339 ) ;
V_339 = ( V_263 & 0xFF00 ) >> 8 ;
F_13 ( V_3 -> V_212 , 0x19 , 0xFC , V_339 ) ;
if ( V_201 & V_296 )
F_13 ( V_3 -> V_180 , 0x01 , 0xF7 , 0x08 ) ;
V_339 = 0 ;
if ( V_201 & V_343 )
V_339 |= 0x08 ;
if ( V_192 > 0x13 ) {
if ( V_3 -> V_196 == V_303 )
V_339 |= 0x40 ;
}
F_13 ( V_3 -> V_180 , 0x0F , ~ 0x48 , V_339 ) ;
V_263 = 0x60 ;
if ( V_3 -> V_196 != V_344 ) {
V_263 = V_263 ^ 0x60 ;
if ( V_3 -> V_196 != V_303 )
V_263 = V_263 ^ 0xA0 ;
}
F_13 ( V_3 -> V_180 , 0x21 , 0x1F , V_263 ) ;
F_33 ( V_210 , V_192 , V_225 ,
V_3 ) ;
V_263 = F_2 ( V_3 -> V_212 , 0x31 ) ;
if ( V_210 -> V_267 == V_162 ) {
if ( V_263 & 0x40 )
V_263 = 0x2c ;
else
V_263 = 0x6c ;
F_5 ( V_3 -> V_212 , 0x52 , V_263 ) ;
F_21 ( V_3 -> V_212 , 0x51 , 0x10 ) ;
} else if ( V_210 -> V_267 >= V_159 ) {
if ( V_263 & 0x40 )
V_263 = 0x33 ;
else
V_263 = 0x73 ;
F_5 ( V_3 -> V_212 , 0x52 , V_263 ) ;
F_5 ( V_3 -> V_212 , 0x51 , 0x02 ) ;
} else {
if ( V_263 & 0x40 )
V_263 = 0x2c ;
else
V_263 = 0x6c ;
F_5 ( V_3 -> V_212 , 0x52 , V_263 ) ;
}
}
static void F_35 ( unsigned short V_345 ,
unsigned short V_298 ,
unsigned short V_299 ,
unsigned short V_346 ,
struct V_2 * V_3 )
{
unsigned short V_163 , V_347 , V_348 ;
V_347 = V_298 ;
V_348 = V_299 ;
if ( V_345 != 0 ) {
V_163 = V_347 ;
V_347 = V_346 ;
V_346 = V_163 ;
if ( V_345 == 1 ) {
V_163 = V_348 ;
V_348 = V_346 ;
V_346 = V_163 ;
} else {
V_163 = V_348 ;
V_348 = V_347 ;
V_347 = V_163 ;
}
}
F_9 ( ( unsigned short ) V_346 , V_3 -> V_349 ) ;
F_9 ( ( unsigned short ) V_347 , V_3 -> V_349 ) ;
F_9 ( ( unsigned short ) V_348 , V_3 -> V_349 ) ;
}
static void F_36 ( unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_263 , V_339 , time , V_200 , V_266 , V_350 , V_351 , V_352 , V_353 , V_354 , V_355 , V_356 , V_345 , V_299 ,
V_298 , V_346 ;
const unsigned short * V_357 = NULL ;
if ( V_192 <= 0x13 )
V_263 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_263 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_263 &= V_358 ;
time = 64 ;
if ( V_263 == 0x00 )
V_357 = V_359 ;
else if ( V_263 == 0x08 )
V_357 = V_360 ;
else if ( V_263 == 0x10 )
V_357 = V_361 ;
else if ( V_263 == 0x18 ) {
time = 256 ;
V_357 = V_362 ;
}
if ( time == 256 )
V_266 = 16 ;
else
V_266 = time ;
F_9 ( 0xFF , V_3 -> V_363 ) ;
F_9 ( 0x00 , V_3 -> V_364 ) ;
for ( V_200 = 0 ; V_200 < V_266 ; V_200 ++ ) {
V_263 = V_357 [ V_200 ] ;
for ( V_350 = 0 ; V_350 < 3 ; V_350 ++ ) {
V_339 = 0 ;
if ( V_263 & 0x01 )
V_339 = 0x2A ;
if ( V_263 & 0x02 )
V_339 += 0x15 ;
F_9 ( V_339 , V_3 -> V_349 ) ;
V_263 = V_263 >> 2 ;
}
}
if ( time == 256 ) {
for ( V_200 = 16 ; V_200 < 32 ; V_200 ++ ) {
V_263 = V_357 [ V_200 ] ;
for ( V_350 = 0 ; V_350 < 3 ; V_350 ++ )
F_9 ( V_263 , V_3 -> V_349 ) ;
}
V_354 = 32 ;
for ( V_351 = 0 ; V_351 < 9 ; V_351 ++ ) {
V_355 = V_354 ;
V_356 = V_354 + 0x04 ;
V_345 = 0 ;
for ( V_352 = 0 ; V_352 < 3 ; V_352 ++ ) {
for ( V_353 = 0 ; V_353 < 5 ; V_353 ++ ) {
V_346 = V_357 [ V_354 ] ;
V_298 = V_357 [ V_355 ] ;
V_299 = V_357 [ V_356 ] ;
V_354 ++ ;
F_35 ( V_345 , V_298 , V_299 , V_346 , V_3 ) ;
}
V_354 -= 2 ;
for ( V_353 = 0 ; V_353 < 3 ; V_353 ++ ) {
V_346 = V_357 [ V_356 ] ;
V_298 = V_357 [ V_355 ] ;
V_299 = V_357 [ V_354 ] ;
V_354 -- ;
F_35 ( V_345 , V_298 , V_299 , V_346 , V_3 ) ;
}
V_345 ++ ;
}
V_354 += 5 ;
}
}
}
static void F_37 ( unsigned short V_192 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_291 , V_342 , V_365 , V_201 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_292 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_230 ;
if ( V_192 <= 0x13 )
V_291 = V_3 -> V_4 [ V_193 ] . V_292 ;
else
V_291 = V_3 -> V_10 [ V_193 ] . V_230 ;
if ( V_192 <= 0x13 ) {
V_342 = V_3 -> V_33 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_33 [ V_291 ] . V_295 ;
} else {
V_342 = V_3 -> V_36 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_36 [ V_291 ] . V_295 ;
}
if ( V_192 > 0x13 ) {
if ( V_201 & V_296 )
V_342 = V_342 << 1 ;
if ( V_201 & V_268 )
V_365 = V_365 << 1 ;
}
if ( V_342 == 720 )
V_342 = 640 ;
V_3 -> V_366 = V_342 ;
V_3 -> V_367 = V_342 ;
V_3 -> V_368 = V_365 ;
V_3 -> V_369 = V_365 ;
}
static void * F_38 ( unsigned short V_370 , unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_200 , V_371 , V_293 , V_227 , V_372 , V_201 , V_357 ;
struct V_373 * V_374 = NULL ;
V_227 = V_370 ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_372 = V_3 -> V_4 [ V_193 ] . V_314 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_372 = V_3 -> V_13 [ V_225 ] . V_315 ;
}
V_372 = V_372 & 0x0f ;
if ( V_227 <= 1 ) {
if ( V_192 <= 0x13 ) {
V_372 = V_3 -> V_4 [ V_193 ] . V_314 ;
} else {
V_372 = V_3 -> V_13 [ V_225 ] .
V_315 ;
}
if ( V_3 -> V_48 & V_205 ) {
if ( V_192 <= 0x13 )
V_372 = V_3 -> V_4 [ V_193 ] .
V_375 ;
else
V_372 = V_3 -> V_13 [
V_225 ] .
V_376 ;
}
if ( V_227 & 0x01 )
V_372 = ( V_372 >> 4 ) ;
V_372 = ( V_372 & 0x0f ) ;
}
V_293 = V_377 [ V_227 ] ;
if ( V_3 -> V_47 & V_378 ) {
if ( ( V_227 == 5 ) || ( V_227 ) == 7 )
V_293 = V_379 ;
else if ( ( V_227 == 3 ) || ( V_227 == 8 ) )
V_293 = V_380 ;
}
switch ( V_227 ) {
case 0 :
case 1 :
V_374 = V_381 ;
break;
case 2 :
V_374 = V_382 ;
break;
case 3 :
V_374 = V_383 ;
break;
case 4 :
V_374 = V_384 ;
break;
case 5 :
V_374 = V_385 ;
break;
case 6 :
V_374 = V_386 ;
break;
case 7 :
case 8 :
case 9 :
V_374 = NULL ;
break;
default:
break;
}
if ( V_374 == NULL )
return NULL ;
V_357 = V_227 ;
V_200 = 0 ;
while ( V_374 [ V_200 ] . V_387 != 0xff ) {
V_371 = V_3 -> V_45 ;
if ( V_227 & 0x0080 ) {
V_227 &= ( ~ 0x0080 ) ;
V_371 = V_3 -> V_46 ;
}
if ( V_3 -> V_47 & V_378 )
V_371 &= ( ~ V_388 ) ;
if ( V_374 [ V_200 ] . V_387 == V_371 ) {
V_227 = V_374 [ V_200 ] . V_389 ;
V_371 = V_3 -> V_47 ;
if ( V_192 <= 0x13 )
V_371 |= V_390 ;
if ( V_201 & V_296 )
V_371 |= V_391 ;
V_227 &= V_371 ;
if ( V_227 == V_374 [ V_200 ] . V_392 )
break;
}
V_200 ++ ;
}
if ( V_357 == 0 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_394 [ V_372 ] ;
break;
case 1 :
return & V_395 [ V_372 ] ;
break;
case 2 :
return & V_396 [ V_372 ] ;
break;
case 3 :
return & V_397 [ V_372 ] ;
break;
case 4 :
return & V_398 [ V_372 ] ;
break;
case 5 :
return & V_399 [ V_372 ] ;
break;
case 6 :
return & V_400 [ V_372 ] ;
break;
case 7 :
return & V_401 [ V_372 ] ;
break;
case 8 :
return & V_402 [ V_372 ] ;
break;
case 9 :
return & V_403 [ V_372 ] ;
break;
case 10 :
return & V_404 [ V_372 ] ;
break;
default:
break;
}
} else if ( V_357 == 1 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_405 [ V_372 ] ;
break;
case 1 :
return & V_406 [ V_372 ] ;
break;
case 2 :
return & V_407 [ V_372 ] ;
break;
case 3 :
return & V_408 [ V_372 ] ;
break;
case 4 :
return & V_409 [ V_372 ] ;
break;
case 5 :
return & V_410 [ V_372 ] ;
break;
case 6 :
return & V_411 [ V_372 ] ;
break;
case 7 :
return & V_412 [ V_372 ] ;
break;
case 8 :
return & V_413 [ V_372 ] ;
break;
case 9 :
return & V_414 [ V_372 ] ;
break;
case 10 :
return & V_415 [ V_372 ] ;
break;
default:
break;
}
} else if ( V_357 == 2 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_416 [ V_372 ] ;
break;
case 1 :
return & V_417 [ V_372 ] ;
break;
case 2 :
return & V_418 [ V_372 ] ;
break;
case 3 :
return & V_419 [ V_372 ] ;
break;
case 4 :
return & V_420 [ V_372 ] ;
break;
case 5 :
return & V_421 [ V_372 ] ;
break;
case 6 :
return & V_422 [ V_372 ] ;
break;
case 7 :
return & V_423 [ V_372 ] ;
break;
case 8 :
return & V_424 [ V_372 ] ;
break;
case 9 :
return & V_425 [ V_372 ] ;
break;
case 10 :
return & V_426 [ V_372 ] ;
break;
case 11 :
return & V_427 [ V_372 ] ;
break;
case 12 :
return & V_428 [ V_372 ] ;
break;
default:
break;
}
} else if ( V_357 == 3 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_429 [ V_372 ] ;
break;
case 1 :
return & V_430 [ V_372 ] ;
break;
case 2 :
return & V_431 [ V_372 ] ;
break;
case 3 :
return & V_432 [ V_372 ] ;
break;
case 4 :
return & V_433 [ V_372 ] ;
break;
case 5 :
return & V_434 [ V_372 ] ;
break;
case 6 :
return & V_435 [ V_372 ] ;
break;
case 7 :
return & V_436 [ V_372 ] ;
break;
case 8 :
return & V_437 [ V_372 ] ;
break;
case 9 :
return & V_438 [ V_372 ] ;
break;
case 10 :
return & V_439 [ V_372 ] ;
break;
case 11 :
return & V_440 [ V_372 ] ;
break;
case 12 :
return & V_441 [ V_372 ] ;
break;
case 13 :
return & V_442 [ V_372 ] ;
break;
case 14 :
return & V_443 [ V_372 ] ;
break;
default:
break;
}
} else if ( V_357 == 4 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_444 [ V_372 ] ;
break;
case 1 :
return & V_445 [ V_372 ] ;
break;
case 2 :
return & V_446 [ V_372 ] ;
break;
case 3 :
return & V_447 [ V_372 ] ;
break;
case 4 :
return & V_448 [ V_372 ] ;
break;
case 5 :
return & V_449 [ V_372 ] ;
break;
case 6 :
case 7 :
return & V_450 [ V_372 ] ;
break;
case 8 :
return & V_451 [ V_372 ] ;
break;
case 9 :
return & V_452 [ V_372 ] ;
break;
case 10 :
return & V_453 [ V_372 ] ;
break;
case 11 :
return & V_454 [ V_372 ] ;
break;
case 12 :
return & V_455 [ V_372 ] ;
break;
case 13 :
return & V_455 [ V_372 ] ;
break;
case 14 :
return & V_456 [ V_372 ] ;
break;
case 15 :
case 16 :
return & V_457 [ V_372 ] ;
break;
case 17 :
return & V_458 [ V_372 ] ;
break;
case 18 :
return & V_459 [ V_372 ] ;
break;
default:
break;
}
} else if ( V_357 == 5 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_460 [ V_372 ] ;
break;
case 1 :
return & V_461 [ V_372 ] ;
break;
case 2 :
return & V_462 [ V_372 ] ;
break;
case 3 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_463 [ V_372 ] ;
else
return & V_464 [ V_372 ] ;
break;
case 4 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_465 [ V_372 ] ;
else
return & V_466 [ V_372 ] ;
break;
case 5 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_467 [ V_372 ] ;
else
return & V_468 [ V_372 ] ;
break;
case 6 :
case 7 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_469 [ V_372 ] ;
else
return & V_470 [ V_372 ] ;
break;
case 8 :
return & V_471 [ V_372 ] ;
break;
case 9 :
return & V_472 [ V_372 ] ;
break;
case 10 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_473 [ V_372 ] ;
else
return & V_474 [ V_372 ] ;
break;
case 11 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_475 [ V_372 ] ;
else
return & V_476 [ V_372 ] ;
break;
case 12 :
return & V_477 [ V_372 ] ;
break;
case 13 :
case 14 :
return & V_478 [ V_372 ] ;
break;
case 15 :
return & V_479 [ V_372 ] ;
break;
case 16 :
case 17 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_480 [ V_372 ] ;
else
return & V_481 [ V_372 ] ;
break;
case 18 :
if ( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) )
return & V_482 [ V_372 ] ;
else
return & V_483 [ V_372 ] ;
break;
case 19 :
return & V_484 [ V_372 ] ;
break;
default:
break;
}
} else if ( V_357 == 6 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_485 [ V_372 ] ;
break;
case 1 :
return & V_486 [ V_372 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void * F_39 ( unsigned short V_370 , unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_200 , V_371 , V_227 , V_372 , V_201 , V_357 ;
struct V_487 * V_374 = NULL ;
V_227 = V_370 ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_372 = V_3 -> V_4 [ V_193 ] . V_314 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_372 = V_3 -> V_13 [ V_225 ] . V_315 ;
}
V_372 = V_372 & 0x3f ;
V_357 = V_227 ;
switch ( V_227 ) {
case 0 :
V_374 = NULL ;
break;
case 1 :
V_374 = NULL ;
break;
case 2 :
case 6 :
V_374 = V_488 ;
break;
case 3 :
V_374 = NULL ;
break;
case 4 :
V_374 = V_489 ;
break;
case 5 :
V_374 = NULL ;
break;
default:
break;
}
if ( V_374 == NULL )
return NULL ;
V_371 = V_3 -> V_49 ;
if ( V_3 -> V_48 & V_208 )
V_371 = V_371 | V_490 ;
if ( V_201 & V_296 )
V_371 = V_371 | V_491 ;
V_200 = 0 ;
while ( V_374 [ V_200 ] . V_389 != 0xffff ) {
if ( ( V_371 & V_374 [ V_200 ] . V_389 ) == V_374 [ V_200 ] . V_392 )
break;
V_200 ++ ;
}
if ( V_357 == 0x04 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_492 [ V_372 ] ;
break;
case 1 :
return & V_493 [ V_372 ] ;
break;
case 2 :
return & V_494 [ V_372 ] ;
break;
case 3 :
return & V_495 [ V_372 ] ;
break;
case 4 :
return & V_496 [ V_372 ] ;
break;
case 5 :
return & V_497 [ V_372 ] ;
break;
case 6 :
return & V_498 [ V_372 ] ;
break;
case 7 :
return & V_499 [ V_372 ] ;
break;
case 8 :
return & V_500 [ V_372 ] ;
break;
case 9 :
return & V_501 [ V_372 ] ;
break;
case 10 :
return & V_502 [ V_372 ] ;
break;
case 11 :
return & V_503 [ V_372 ] ;
break;
case 12 :
return & V_493 [ V_372 ] ;
break;
case 13 :
return & V_504 [ V_372 ] ;
break;
default:
break;
}
} else if ( V_357 == 0x02 ) {
switch ( V_374 [ V_200 ] . V_393 ) {
case 0 :
return & V_505 [ V_372 ] ;
break;
case 1 :
return & V_506 [ V_372 ] ;
break;
case 2 :
return & V_507 [ V_372 ] ;
break;
case 3 :
return & V_508 [ V_372 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void F_40 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_227 ;
struct V_509 * V_510 = NULL ;
V_227 = 2 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_510 = (struct V_509 * ) F_38 ( V_227 ,
V_192 , V_193 , V_225 ,
V_3 ) ;
V_3 -> V_511 = V_510 -> V_511 ;
V_3 -> V_512 = V_510 -> V_512 ;
V_3 -> V_513 = V_510 -> V_514 ;
V_3 -> V_515 = V_510 -> V_516 ;
}
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
if ( ! ( V_3 -> V_47 & ( V_517
| V_378 ) ) ) {
if ( ( V_3 -> V_45 == V_259 ) ||
( V_3 -> V_45 == V_334 ) ) {
V_3 -> V_367 = 1024 ;
V_3 -> V_369 = 768 ;
} else if ( ( V_3 -> V_45 == V_238 ) ||
( V_3 -> V_45 == V_518 ) ) {
V_3 -> V_367 = 1280 ;
V_3 -> V_369 = 1024 ;
} else if ( V_3 -> V_45 == V_519 ) {
V_3 -> V_367 = 1400 ;
V_3 -> V_369 = 1050 ;
} else {
V_3 -> V_367 = 1600 ;
V_3 -> V_369 = 1200 ;
}
}
}
}
static void F_41 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned char V_194 ;
unsigned short V_227 , V_200 ;
struct V_520 * V_510 = NULL ;
struct V_521 * V_522 = NULL ;
if ( V_192 <= 0x13 )
V_194 = V_3 -> V_4 [ V_193 ] . V_314 ;
else
V_194 = V_3 -> V_13 [ V_225 ] . V_315 ;
V_194 = V_194 & V_270 ;
V_227 = 0 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_510 = (struct V_520 * )
F_38 ( V_227 , V_192 ,
V_193 ,
V_225 ,
V_3 ) ;
for ( V_200 = 0 ; V_200 < 8 ; V_200 ++ )
V_3 -> V_138 [ 0 ] . V_263 [ V_200 ] = V_510 [ 0 ] . V_523 [ V_200 ] ;
}
F_17 ( V_3 , V_210 ) ;
V_227 = 1 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_522 = (struct V_521 * )
F_38 (
V_227 ,
V_192 ,
V_193 ,
V_225 ,
V_3 ) ;
for ( V_200 = 0 ; V_200 < 7 ; V_200 ++ )
V_3 -> V_141 [ 0 ] . V_263 [ V_200 ] = V_522 [ 0 ] . V_523 [ V_200 ] ;
}
F_18 ( V_193 , V_192 , V_3 ) ;
}
static unsigned short F_42 ( struct V_2 * V_3 )
{
unsigned char V_372 , V_198 , V_524 , V_200 ;
V_198 = F_2 ( V_3 -> V_212 , 0x36 ) ;
V_372 = V_198 & 0x0F ;
V_198 = V_198 & 0xF0 ;
V_200 = 0 ;
V_524 = V_3 -> V_150 [ V_200 ] . V_525 ;
while ( V_524 != 0xFF ) {
if ( V_524 & 0x80 ) {
V_372 = V_198 ;
V_524 = V_524 & ~ ( 0x80 ) ;
}
if ( V_372 == V_524 )
break;
V_200 ++ ;
V_524 = V_3 -> V_150 [ V_200 ] . V_525 ;
}
return V_200 ;
}
static unsigned short F_43 ( struct V_2 * V_3 )
{
unsigned short V_198 , V_372 , V_524 , V_200 ;
V_372 = V_3 -> V_45 ;
V_198 = V_3 -> V_46 ;
V_200 = 0 ;
V_524 = V_3 -> V_150 [ V_200 ] . V_525 ;
while ( V_524 != 0xFF ) {
if ( ( V_524 & 0x80 ) && ( V_524 != 0x80 ) ) {
V_372 = V_198 ;
V_524 &= ~ 0x80 ;
}
if ( V_372 == V_524 )
break;
V_200 ++ ;
V_524 = V_3 -> V_150 [ V_200 ] . V_525 ;
}
if ( V_524 == 0xFF ) {
V_3 -> V_45 = V_259 ;
V_3 -> V_46 = 0 ;
V_200 = 0 ;
}
return V_200 ;
}
static void F_44 ( unsigned short * V_526 ,
unsigned short * V_527 ,
struct V_2 * V_3 )
{
unsigned short V_528 ;
V_528 = F_42 ( V_3 ) ;
* V_526 = V_3 -> V_150 [ V_528 ] . V_529 ;
* V_527 = V_3 -> V_150 [ V_528 ] . V_530 ;
return;
}
static void F_45 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_227 , V_226 , V_293 , V_371 , V_531 , V_532 , V_201 ;
unsigned long V_163 , V_533 , V_300 , V_534 , V_535 ;
struct V_536 * V_510 = NULL ;
struct V_537 * V_522 = NULL ;
if ( V_192 > 0x13 )
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
else
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_227 = 3 ;
if ( V_3 -> V_47 & V_378 )
V_522 =
(struct V_537 * )
F_38 (
V_227 ,
V_192 ,
V_193 ,
V_225 ,
V_3 ) ;
else
V_510 =
(struct V_536 * )
F_38 (
V_227 ,
V_192 ,
V_193 ,
V_225 ,
V_3 ) ;
F_44 ( & V_226 , & V_227 , V_3 ) ;
V_531 = V_227 ;
V_532 = V_226 ;
if ( ( V_3 -> V_45 == V_259 ) ||
( V_3 -> V_45 == V_334 ) ) {
V_226 = 1024 ;
V_227 = 768 ;
} else if ( ( V_3 -> V_45 == V_238 ) ||
( V_3 -> V_45 == V_518 ) ) {
V_226 = 1280 ;
V_227 = 1024 ;
} else if ( V_3 -> V_45 == V_519 ) {
V_226 = 1400 ;
V_227 = 1050 ;
} else {
V_226 = 1600 ;
V_227 = 1200 ;
}
if ( V_3 -> V_47 & V_517 ) {
V_3 -> V_367 = V_226 ;
V_3 -> V_369 = V_227 ;
V_3 -> V_366 = V_226 ;
V_3 -> V_368 = V_227 ;
}
V_226 = V_3 -> V_513 ;
if ( V_3 -> V_47 & V_378 )
V_227 = V_522 -> V_538 ;
else
V_227 = V_510 -> V_538 ;
V_293 = V_3 -> V_367 ;
V_227 = V_227 & 0x0fff ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
F_5 ( V_3 -> V_539 , 0x1A , V_227 & 0x07 ) ;
V_293 = V_293 >> 3 ;
V_227 = V_227 >> 3 ;
F_5 ( V_3 -> V_539 , 0x16 ,
( unsigned short ) ( V_227 & 0xff ) ) ;
F_5 ( V_3 -> V_539 , 0x17 ,
( unsigned short ) ( V_293 & 0xff ) ) ;
V_226 = V_3 -> V_513 ;
if ( V_3 -> V_47 & V_378 )
V_227 = V_522 -> V_540 ;
else
V_227 = V_510 -> V_540 ;
V_293 = V_532 ;
if ( V_3 -> V_47 & V_378 )
V_293 = V_522 -> V_541 ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
V_226 = V_227 & 0x07 ;
V_226 = V_226 >> 5 ;
V_293 = V_293 >> 3 ;
V_227 = V_227 >> 3 ;
V_293 &= 0x1f ;
V_226 |= V_293 ;
F_5 ( V_3 -> V_539 , 0x15 , V_226 ) ;
F_5 ( V_3 -> V_539 , 0x14 ,
( unsigned short ) ( V_227 & 0xff ) ) ;
V_226 = V_3 -> V_515 ;
if ( V_3 -> V_47 & V_378 )
V_227 = V_522 -> V_542 ;
else
V_227 = V_510 -> V_542 ;
V_293 = V_3 -> V_369 ;
V_227 = V_227 & 0x0fff ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
F_5 ( V_3 -> V_539 , 0x1b ,
( unsigned short ) ( V_227 & 0xff ) ) ;
F_5 ( V_3 -> V_539 , 0x1c ,
( unsigned short ) ( V_293 & 0xff ) ) ;
V_227 = ( V_227 >> 8 ) & 0x07 ;
V_293 = ( V_293 >> 8 ) & 0x07 ;
F_5 ( V_3 -> V_539 , 0x1d ,
( unsigned short ) ( ( V_293 << 3 )
| V_227 ) ) ;
V_226 = V_3 -> V_515 ;
if ( V_3 -> V_47 & V_378 )
V_227 = V_522 -> V_543 ;
else
V_227 = V_510 -> V_543 ;
V_293 = V_531 ;
if ( V_3 -> V_47 & V_378 )
V_293 = V_522 -> V_544 ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
F_5 ( V_3 -> V_539 , 0x18 ,
( unsigned short ) ( V_227 & 0xff ) ) ;
F_13 ( V_3 -> V_539 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_293 & 0x0f ) ) ;
V_226 = ( ( V_227 >> 8 ) & 0x07 ) << 3 ;
V_227 = V_3 -> V_368 ;
if ( V_227 != V_3 -> V_369 )
V_226 |= 0x40 ;
if ( V_3 -> V_47 & V_545 )
V_226 |= 0x40 ;
F_13 ( V_3 -> V_539 , 0x1a , 0x07 ,
V_226 ) ;
V_293 = V_3 -> V_512 ;
V_227 = V_3 -> V_369 ;
V_226 = V_3 -> V_368 ;
V_293 -= V_226 ;
V_163 = V_226 ;
V_533 = ( V_163 << 18 ) / V_227 ;
V_371 = ( unsigned short ) ( ( V_163 << 18 ) % V_227 ) ;
if ( V_371 != 0 )
V_533 += 1 ;
V_300 = V_533 ;
V_535 = V_300 ;
F_5 ( V_3 -> V_539 , 0x37 ,
( unsigned short ) ( V_300 & 0xff ) ) ;
F_5 ( V_3 -> V_539 , 0x36 ,
( unsigned short ) ( ( V_300 >> 8 ) & 0xff ) ) ;
V_227 = ( unsigned short ) ( V_300 >> 16 ) ;
V_226 = V_227 & 0x03 ;
V_227 = V_3 -> V_368 ;
if ( V_227 == V_3 -> V_369 )
V_226 |= 0x04 ;
F_5 ( V_3 -> V_539 , 0x35 , V_226 ) ;
if ( V_3 -> V_147 & V_235 ) {
V_300 = V_535 ;
F_5 ( V_3 -> V_546 ,
0x3c ,
( unsigned short ) ( V_300 & 0xff ) ) ;
F_5 ( V_3 -> V_546 ,
0x3b ,
( unsigned short ) ( ( V_300 >> 8 ) &
0xff ) ) ;
V_227 = ( unsigned short ) ( V_300 >> 16 ) ;
F_13 ( V_3 -> V_546 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_227 &
0xff ) << 6 ) ) ;
V_293 = V_3 -> V_368 ;
if ( V_293 == V_3 -> V_369 )
F_13 ( V_3 -> V_546 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_13 ( V_3 -> V_546 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_293 = V_3 -> V_366 ;
V_227 = V_3 -> V_367 ;
V_533 = V_293 << 16 ;
V_226 = ( unsigned short ) ( V_533 / V_227 ) ;
if ( ( V_227 & 0xffff ) == ( V_293 & 0xffff ) )
V_226 = 65535 ;
V_534 = V_226 ;
V_533 = V_3 -> V_366 << 16 ;
V_533 /= V_534 ;
V_534 = V_534 << 16 ;
V_533 -= 1 ;
V_534 = ( V_534 & 0xffff0000 ) + ( V_533 & 0xffff ) ;
V_226 = ( unsigned short ) ( V_534 & 0xff ) ;
F_5 ( V_3 -> V_539 , 0x1f , V_226 ) ;
V_533 = V_3 -> V_368 << 18 ;
V_533 = V_533 / V_535 ;
V_227 = ( unsigned short ) ( V_533 & 0xffff ) ;
if ( V_3 -> V_45 == V_259 )
V_227 -= 1 ;
V_226 = ( ( V_227 >> 8 ) & 0xff ) << 3 ;
V_226 |= ( unsigned short ) ( ( V_534 >> 8 ) & 0x07 ) ;
F_5 ( V_3 -> V_539 , 0x20 ,
( unsigned short ) ( V_226 & 0xff ) ) ;
F_5 ( V_3 -> V_539 , 0x21 ,
( unsigned short ) ( V_227 & 0xff ) ) ;
V_534 = V_534 >> 16 ;
if ( V_201 & V_296 )
V_534 = V_534 >> 1 ;
F_5 ( V_3 -> V_539 , 0x22 ,
( unsigned short ) ( ( V_534 >> 8 ) & 0xff ) ) ;
F_5 ( V_3 -> V_539 , 0x23 ,
( unsigned short ) ( V_534 & 0xff ) ) ;
}
static void F_46 ( unsigned char * V_547 , unsigned char * V_548 ,
struct V_2 * V_3 )
{
unsigned short V_194 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_194 = F_43 ( V_3 ) ;
if ( V_3 -> V_48 & V_207 ) {
* V_547 = V_3 -> V_150 [ V_194 ] . V_549 ;
* V_548 = V_3 -> V_150 [ V_194 ] . V_550 ;
} else {
* V_547 = V_3 -> V_150 [ V_194 ] . V_551 ;
* V_548 = V_3 -> V_150 [ V_194 ] . V_552 ;
}
}
return;
}
static unsigned char F_47 ( unsigned short V_225 ,
unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_194 , V_201 ;
unsigned char V_372 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
if ( ( V_3 -> V_246 & V_553 ) &&
( ! ( V_3 -> V_47 & V_378 ) ) ) {
V_194 = F_42 ( V_3 ) ;
V_372 = V_3 -> V_150 [ V_194 ] . V_554 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) )
return V_372 ;
if ( V_3 -> V_147 &
( V_253 |
V_254 |
V_148 |
V_149 |
V_235 ) ) {
if ( V_3 -> V_48 & V_241 ) {
V_372 = V_317 + V_318 ;
if ( ! ( V_3 -> V_49 & V_316 ) )
V_372 = V_317 + V_319 ;
if ( V_3 -> V_49 & V_247 ) {
V_372 = V_317 + V_320 ;
if ( ! ( V_201 & V_216 ) )
V_372 = V_317 + V_321 ;
}
return V_372 ;
}
if ( V_3 -> V_49 & V_555 ) {
V_372 = V_323 ;
return V_372 ;
}
if ( V_3 -> V_49 & V_556 ) {
V_372 = V_325 ;
return V_372 ;
}
V_372 = V_557 ;
if ( ! ( V_3 -> V_49 & V_558 ) ) {
V_372 = V_317 + V_328 ;
if ( ! ( V_3 -> V_49 & V_316 ) )
V_372 = V_317 + V_329 ;
}
if ( V_3 -> V_48 & V_206 )
return V_372 ;
}
}
V_372 = ( unsigned char ) F_8 ( ( V_3 -> V_330 + 0x02 ) ) ;
V_372 = V_372 >> 2 ;
V_372 &= 0x03 ;
if ( ( V_3 -> V_47 & V_378 ) && ( V_201 & V_216 ) )
V_372 = V_372 ^ V_372 ;
if ( V_192 <= 0x13 )
return V_372 ;
V_372 = V_3 -> V_13 [ V_225 ] . V_331 ;
return V_372 ;
}
static void F_48 ( unsigned char V_372 , unsigned char * V_547 ,
unsigned char * V_548 , struct V_2 * V_3 )
{
if ( V_3 -> V_147 & ( V_559 | V_253 | V_254
| V_148 | V_149 | V_235 ) ) {
if ( ( ! ( V_3 -> V_48 & V_205 ) ) && ( V_3 -> V_246
& V_553 ) ) {
* V_547 = ( unsigned char ) V_30 [ V_372 ] . V_223 ;
* V_548 = V_30 [ V_372 ] . V_224 ;
}
} else {
* V_547 = V_27 [ V_372 ] . V_223 ;
* V_548 = V_27 [ V_372 ] . V_224 ;
}
}
static void F_49 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned char V_547 , V_548 , V_372 ;
int V_200 ;
V_372 = F_47 ( V_225 , V_192 , V_193 ,
V_3 ) ;
F_48 ( V_372 , & V_547 , & V_548 , V_3 ) ;
F_46 ( & V_547 , & V_548 , V_3 ) ;
for ( V_200 = 0 ; V_200 < 4 ; V_200 ++ ) {
F_13 ( V_3 -> V_212 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_200 ) ) ;
if ( ( ! ( V_3 -> V_48 & V_205 ) )
&& ( ! ( V_3 -> V_48 & V_208 ) ) ) {
F_5 ( V_3 -> V_180 , 0x2e , V_547 ) ;
F_5 ( V_3 -> V_180 , 0x2f , V_548 ) ;
} else {
F_5 ( V_3 -> V_180 , 0x2b , V_547 ) ;
F_5 ( V_3 -> V_180 , 0x2c , V_548 ) ;
}
}
}
static void F_50 ( struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_560 , V_561 , V_163 , V_524 , V_226 ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
V_560 = 0 ;
V_561 = 0 ;
V_163 = F_2 ( V_3 -> V_180 , 0x01 ) ;
if ( ! ( V_163 & 0x20 ) ) {
V_163 = F_2 ( V_3 -> V_212 , 0x17 ) ;
if ( V_163 & 0x80 ) {
V_163 = F_2 ( V_3 -> V_212 , 0x53 ) ;
if ( ! ( V_163 & 0x40 ) )
V_560 |= V_562 ;
}
}
V_163 = F_2 ( V_3 -> V_539 , 0x2e ) ;
V_163 &= 0x0f ;
if ( ! ( V_163 == 0x08 ) ) {
V_226 = F_2 ( V_3 -> V_539 , 0x13 ) ;
if ( V_226 & 0x04 )
V_560 = V_560 | V_563 ;
V_163 &= 0x05 ;
if ( ! ( V_560 & V_563 ) )
if ( V_163 == 0x01 )
V_560 |= V_564 ;
if ( V_163 == 0x04 )
V_560 |= V_563 ;
if ( V_163 == 0x05 ) {
V_163 = F_2 ( V_3 -> V_565 , 0x00 ) ;
if ( ! ( V_163 & 0x08 ) )
V_561 |= V_566 ;
if ( ! ( V_163 & 0x04 ) )
V_561 |= V_567 ;
if ( V_163 & 0x02 )
V_561 |= V_568 ;
if ( V_3 -> V_48 & V_241 ) {
if ( V_163 & 0x01 )
V_561 |= V_569 ;
}
if ( V_3 -> V_48 & V_251 ) {
V_163 = F_2 (
V_3 -> V_565 ,
0x4d ) ;
if ( V_163 & 0x10 )
V_561 |= V_570 ;
}
if ( V_561 != 0 )
V_560 |= V_571 ;
}
}
V_163 = F_2 ( V_3 -> V_212 , 0x3d ) ;
if ( V_560 & V_563 ) {
if ( ( V_3 -> V_246 & V_572 ) ) {
if ( V_163 & V_571 )
V_560 |= V_571 ;
}
}
V_163 = V_560 ;
V_524 = ~ V_573 ;
F_13 ( V_3 -> V_212 , 0x3d , V_524 , V_163 ) ;
if ( ! ( V_3 -> V_246 & V_572 ) )
F_5 ( V_3 -> V_212 , 0x3e , V_561 ) ;
} else {
return;
}
}
void F_51 ( struct V_2 * V_3 )
{
unsigned short V_574 , V_227 , V_198 ;
if ( V_3 -> V_232 == 0 ) {
V_227 = V_254 ;
V_574 = F_2 ( V_3 -> V_546 , 0x00 ) ;
if ( V_574 != 0x02 ) {
V_227 = V_559 ;
V_574 = F_2 ( V_3 -> V_546 , 0x01 ) ;
if ( V_574 >= 0xB0 ) {
V_227 = V_253 ;
if ( V_574 >= 0xC0 ) {
V_227 = V_235 ;
if ( V_574 >= 0xD0 ) {
V_227 = V_148 ;
if ( V_574 >= 0xE0 ) {
V_227 = V_149 ;
V_198 = F_2 (
V_3 -> V_546 ,
0x39 ) ;
if ( V_198 != 0xFF )
V_227 =
V_235 ;
}
}
}
if ( V_227 & ( V_253 | V_254 ) ) {
V_574 = F_2 (
V_3 -> V_546 ,
0x23 ) ;
if ( ! ( V_574 & 0x02 ) )
V_227 = V_227 | V_575 ;
}
}
}
V_3 -> V_147 = V_227 ;
}
}
static void F_52 ( unsigned short V_192 , unsigned short V_193 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_226 , V_576 , V_227 , V_163 , V_201 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_3 -> V_246 = 0 ;
V_3 -> V_196 = V_201 & V_577 ;
V_227 = 0 ;
if ( V_3 -> V_147 & 0xFFFF ) {
V_163 = F_2 ( V_3 -> V_212 , 0x30 ) ;
V_227 = V_227 | V_163 ;
V_163 = F_2 ( V_3 -> V_212 , 0x31 ) ;
V_576 = V_163 ;
V_576 = V_576 << 8 ;
V_226 = V_163 << 8 ;
V_227 = V_227 | V_226 ;
V_163 = ( V_578 | V_251 | V_205
| V_208 | V_579 ) ;
V_163 = 0xFFFF ^ V_163 ;
V_227 &= V_163 ;
V_163 = F_2 ( V_3 -> V_212 , 0x38 ) ;
if ( V_3 -> V_580 == 1 ) {
if ( ( V_210 -> V_267 >= V_159 ) ||
( V_210 -> V_267 >= V_581 ) ) {
if ( V_3 -> V_232 == 0 ) {
if ( V_3 -> V_147 &
( V_254 |
V_148 |
V_149 |
V_235 ) ) {
if ( V_163 & V_582 ) {
V_227 |=
V_578 ;
if ( V_163 & V_583 )
V_227 |=
V_205 ;
}
}
}
}
}
if ( V_3 -> V_584 == 1 ) {
if ( ( ( V_3 -> V_232 == 0 ) &&
( ( V_3 -> V_147 & V_148 ) ||
( V_3 -> V_147 & V_149 ) ||
( V_3 -> V_147 & V_235 ) ) ) ) {
if ( V_163 & V_585 ) {
if ( V_3 -> V_586 == 1 ) {
V_163 = F_2 (
V_3 -> V_212 ,
0x35 ) ;
V_163 &= V_587 ;
V_227 |= V_241 ;
if ( V_163 != V_588 ) {
V_227 &=
( ~ V_241 ) ;
V_227 |=
V_251 ;
}
}
}
}
}
V_226 = V_576 ;
if ( V_3 -> V_232 == 0 ) {
if ( V_3 -> V_584 == 1 ) {
if ( V_3 -> V_586 == 1 )
V_163 = 0x09FC ;
else
V_163 = 0x097C ;
} else {
if ( V_3 -> V_586 == 1 )
V_163 = 0x01FC ;
else
V_163 = 0x017C ;
}
} else {
V_163 = V_207 ;
}
if ( ! ( V_227 & V_163 ) ) {
V_226 |= V_579 ;
V_227 = 0 ;
}
if ( V_3 -> V_580 == 1 ) {
if ( ! ( V_3 -> V_147 & V_575 ) ) {
if ( V_227 & V_205 ) {
if ( V_227 & V_589 )
V_227 &= ( ~ ( V_207 |
V_233 |
V_590 ) ) ;
else
V_227 &= ( ~ ( V_207 |
V_233 |
V_206 |
V_590 ) ) ;
}
}
}
if ( ! ( V_227 & ( V_590 | V_589 ) ) ) {
if ( V_3 -> V_591 == 1 ) {
if ( V_227 & V_233 ) {
V_227 &= ( 0xFF00 |
V_233 |
V_590 |
V_589 ) ;
V_227 &= ( 0x00FF | ( ~ V_251 ) ) ;
}
} else {
V_227 &= ( ~ ( V_233 |
V_207 |
V_206 ) ) ;
}
}
if ( ! ( V_3 -> V_147 & V_575 ) ) {
if ( V_227 & V_207 ) {
V_227 &= ( 0xFF00 |
V_207 |
V_590 |
V_589 ) ;
V_227 &= ( 0x00FF | ( ~ V_251 ) ) ;
}
}
if ( V_227 & V_250 ) {
V_227 &= ( 0xFF00 |
V_250 |
V_590 |
V_589 ) ;
V_227 &= ( 0x00FF | ( ~ V_251 ) ) ;
}
if ( V_3 -> V_584 == 1 ) {
if ( V_227 & V_251 )
V_227 &= ( 0xFF00 |
V_590 |
V_589 ) ;
}
if ( V_3 -> V_586 == 1 ) {
if ( V_227 & V_241 )
V_227 &= ( 0xFF00 |
V_241 |
V_590 |
V_589 ) ;
}
if ( V_226 & V_579 ) {
if ( ! ( V_227 & ( V_590 | V_589 ) ) )
V_227 = V_579 ;
}
if ( ! ( V_227 & V_579 ) ) {
if ( ( ! ( V_227 & V_592 ) ) ||
( ! ( V_201 & V_593 ) ) ) {
if ( V_3 -> V_580 == 1 ) {
if ( ! ( V_227 & V_205 ) )
V_227 |= ( V_208 |
V_589 ) ;
}
}
if ( ( V_227 & V_208 ) &&
( V_227 & V_205 ) ) {
V_227 ^= ( V_207 |
V_205 |
V_578 ) ;
V_3 -> V_246 |= V_572 ;
}
}
}
V_3 -> V_48 = V_227 ;
}
static void F_53 ( unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_163 , V_227 = 0 , V_228 = 0 , V_201 , V_594 ;
V_227 = 0 ;
V_228 = 0 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] .
V_202 ;
V_228 = V_3 -> V_4 [ V_193 ] .
V_292 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] .
V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] .
V_230 ;
}
if ( V_3 -> V_48 & V_206 ) {
V_163 = F_2 ( V_3 -> V_212 , 0x35 ) ;
V_227 = V_163 ;
if ( V_227 & V_256 ) {
V_227 &= ( V_595 |
V_596 |
V_597 |
V_256 ) ;
if ( V_227 & V_596 )
V_227 &= ~ V_256 ;
} else
V_227 &= ( V_595 |
V_598 |
V_256 ) ;
}
if ( V_3 -> V_232 == 0 ) {
if ( V_3 -> V_48 & V_250 )
V_227 |= V_256 ;
}
if ( V_3 -> V_584 == 1 ) {
if ( V_3 -> V_48 & V_251 ) {
V_594 = F_2 ( V_3 -> V_212 , 0x35 ) ;
V_594 &= V_587 ;
if ( V_594 == V_599 )
V_227 |= V_600 ;
if ( V_594 == V_601 )
V_227 = V_227 | V_556 ;
if ( V_594 == V_602 )
V_227 = V_227 | V_555 ;
}
}
if ( V_3 -> V_586 == 1 ) {
if ( V_3 -> V_48 & V_241 )
V_227 = V_227 | V_603 | V_256 ;
}
if ( V_3 -> V_232 == 0 ) {
if ( ( V_3 -> V_48 & V_208 ) &&
( ! ( V_3 -> V_48 & V_258 ) ) )
V_227 |= V_247 ;
if ( ! ( V_227 & V_256 ) &&
( V_201 > 13 ) &&
( V_228 == 8 ) )
V_227 |= V_558 ;
V_227 |= V_316 ;
if ( V_3 -> V_48 & V_241 ) {
if ( V_3 -> V_48 & V_208 )
V_227 &= ( ~ V_316 ) ;
} else {
if ( V_227 &
( V_556 | V_555 ) )
V_227 &= ( ~ V_316 ) ;
else if ( ! ( V_3 -> V_147 &
( V_253 |
V_254 |
V_148 |
V_149 |
V_235 ) ) ) {
if ( V_227 & V_247 )
V_227 &= ( ~ V_316 ) ;
}
}
}
}
V_3 -> V_49 = V_227 ;
}
static unsigned char F_54 ( unsigned short V_192 ,
unsigned short V_193 , struct V_2 * V_3 )
{
unsigned short V_163 , V_226 , V_227 , V_201 , V_228 = 0 , V_604 ;
V_3 -> V_45 = 0 ;
V_3 -> V_46 = 0 ;
V_3 -> V_47 = 0 ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
}
V_163 = F_2 ( V_3 -> V_212 , 0x36 ) ;
V_227 = V_163 & 0x0F ;
if ( V_227 == 0 )
V_227 = V_259 ;
if ( ( V_227 == V_259 ) || ( V_227 == V_238 ) ) {
if ( V_3 -> V_48 & V_592 ) {
V_226 = F_2 ( V_3 -> V_212 , 0x33 ) ;
if ( V_3 -> V_48 & V_205 )
V_226 &= 0x0F ;
else
V_226 = V_226 >> 4 ;
if ( ( V_228 == 6 ) || ( V_228 == 9 ) ) {
if ( V_226 >= 3 )
V_227 |= V_605 ;
} else if ( ( V_228 == 7 ) || ( V_228 == 8 ) ) {
if ( V_226 >= 4 )
V_227 |= V_605 ;
}
}
}
V_3 -> V_45 = V_227 ;
if ( ! ( V_3 -> V_48 & ( V_207 | V_205 ) ) )
return 0 ;
V_227 = 0 ;
V_163 = F_2 ( V_3 -> V_212 , 0x37 ) ;
V_163 &= ( V_606 | V_240 | V_607 | V_608 ) ;
V_227 |= V_163 ;
V_604 = F_43 ( V_3 ) ;
V_226 = V_3 -> V_150 [ V_604 ] . V_609 ;
if ( V_3 -> V_232 == 0 ) {
if ( ( ( V_3 -> V_147 & V_149 ) || ( V_3 -> V_147
& V_235 ) ) && ( V_226 & V_610 ) ) {
V_227 |= V_611 ;
}
}
if ( V_3 -> V_232 == 0 ) {
if ( ( V_3 -> V_45 == V_519 ) && ( V_3 -> V_48
& V_207 ) && ( V_192 > 0x13 ) && ( V_228
== 9 ) && ( ! ( V_227 & V_378 ) ) )
V_227 |= V_517 ;
}
if ( V_3 -> V_612 == 1 ) {
if ( V_201 & V_296 ) {
if ( ! ( V_227 & V_517 ) ) {
V_227 |= V_545 ;
} else {
if ( V_192 > 0x13 ) {
if ( V_3 -> V_45
== V_259 ) {
if ( V_228 == 4 ) {
V_227 |= V_545 ;
}
}
}
}
}
}
if ( V_3 -> V_48 & V_208 ) {
if ( V_3 -> V_48 & V_258 )
V_227 |= V_613 ;
} else {
V_227 |= V_613 ;
}
V_3 -> V_47 = V_227 ;
if ( V_3 -> V_232 == 0 ) {
if ( V_226 & ( V_614 | V_615 ) ) {
if ( V_3 -> V_48 & V_208 ) {
if ( ! ( V_226 & V_614 ) ) {
if ( V_192 <= 0x13 ) {
V_3 -> V_48 &=
~ ( V_589 |
V_208 |
V_207 ) ;
V_3 -> V_48 |=
V_205 |
V_578 ;
}
}
}
}
}
return 1 ;
}
unsigned char F_55 ( unsigned short V_192 ,
unsigned short * V_193 , struct V_2 * V_3 )
{
if ( V_192 <= 5 )
V_192 |= 1 ;
if ( V_192 <= 0x13 ) {
for ( * V_193 = 0 ; ; ( * V_193 ) ++ ) {
if ( V_3 -> V_4 [ * V_193 ] . V_616 ==
V_192 )
break;
if ( V_3 -> V_4 [ * V_193 ] . V_616 ==
0xFF )
return 0 ;
}
if ( V_192 == 0x07 )
( * V_193 ) ++ ;
if ( V_192 <= 3 )
( * V_193 ) += 2 ;
} else {
for ( * V_193 = 0 ; ; ( * V_193 ) ++ ) {
if ( V_3 -> V_10 [ * V_193 ] . V_617 ==
V_192 )
break;
if ( V_3 -> V_10 [ * V_193 ] . V_617 ==
0xFF )
return 0 ;
}
}
return 1 ;
}
static unsigned char F_56 ( unsigned char V_618 )
{
unsigned char V_619 = 0 ;
unsigned char V_200 = 0 ;
for ( V_200 = 0 ; V_200 < 8 ; V_200 ++ ) {
V_619 = V_619 << 1 ;
V_619 |= ( V_618 >> V_200 ) & 1 ;
}
return V_619 ;
}
static unsigned char F_57 ( struct V_2 * V_3 )
{
unsigned char V_620 , V_163 ;
V_620 = F_2 ( V_3 -> V_212 , 0x4A ) ;
F_14 ( V_3 -> V_212 , 0x4A , ~ 0x23 ) ;
V_163 = F_2 ( V_3 -> V_212 , 0x48 ) ;
V_163 = F_56 ( V_163 ) ;
V_163 &= 0x23 ;
F_5 ( V_3 -> V_212 , 0x4A , V_620 ) ;
return V_163 ;
}
static unsigned char F_58 ( struct V_2 * V_3 )
{
unsigned char V_620 , V_621 , V_163 ;
V_620 = F_2 ( V_3 -> V_212 , 0x4A ) ;
F_14 ( V_3 -> V_212 , 0x4A , ~ 0x0C ) ;
V_163 = F_2 ( V_3 -> V_212 , 0x48 ) ;
V_163 &= 0x0C ;
V_163 >>= 2 ;
F_5 ( V_3 -> V_212 , 0x4A , V_620 ) ;
V_621 = F_2 ( V_3 -> V_212 , 0xB4 ) ;
V_163 |= ( ( V_621 & 0x04 ) << 3 ) ;
return V_163 ;
}
static void F_59 ( unsigned short V_622 , unsigned short V_524 ,
struct V_2 * V_3 )
{
unsigned char V_620 , V_163 ;
V_620 = F_2 ( V_3 -> V_212 , 0x4A ) ;
V_622 &= 0x23 ;
V_524 &= 0x23 ;
F_14 ( V_3 -> V_212 , 0x4A , ~ V_622 ) ;
if ( V_622 & 0x20 ) {
V_163 = ( V_524 >> 4 ) & 0x02 ;
F_13 ( V_3 -> V_212 , 0xB4 , ~ 0x02 , V_163 ) ;
}
V_163 = F_2 ( V_3 -> V_212 , 0x48 ) ;
V_163 = F_56 ( V_163 ) ;
V_163 &= ~ V_622 ;
V_163 |= V_524 ;
F_5 ( V_3 -> V_212 , 0x48 , V_163 ) ;
}
static void F_60 ( unsigned short V_622 , unsigned short V_524 ,
struct V_2 * V_3 )
{
unsigned char V_620 , V_163 ;
unsigned short V_623 , V_624 ;
V_623 = V_622 ;
V_624 = V_524 ;
V_623 &= 0x20 ;
V_624 &= 0x20 ;
V_623 >>= 3 ;
V_624 >>= 3 ;
if ( V_622 & 0x20 ) {
V_163 = ( V_524 >> 4 ) & 0x02 ;
F_13 ( V_3 -> V_212 , 0xB4 , ~ 0x02 , V_163 ) ;
}
F_13 ( V_3 -> V_212 , 0xB4 , ~ V_623 , V_624 ) ;
V_620 = F_2 ( V_3 -> V_212 , 0x4A ) ;
V_622 &= 0x03 ;
V_524 &= 0x03 ;
V_622 <<= 2 ;
V_524 <<= 2 ;
F_14 ( V_3 -> V_212 , 0x4A , ~ V_622 ) ;
F_13 ( V_3 -> V_212 , 0x48 , ~ V_622 , V_524 ) ;
}
static void F_61 ( struct V_625 * V_626 ,
unsigned short V_524 ,
struct V_2 * V_3 )
{
if ( V_524 == 1 )
F_62 ( V_626 -> V_627 . V_628 ) ;
if ( V_524 == 2 )
F_62 ( V_626 -> V_627 . V_629 ) ;
if ( V_524 == 3 )
F_62 ( V_626 -> V_627 . V_630 ) ;
if ( V_524 == 4 )
F_62 ( V_626 -> V_627 . V_631 ) ;
}
static void F_63 ( struct V_625 * V_626 ,
struct V_209 * V_632 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_180 , 0x01 , 0xDF , 0x00 ) ;
if ( V_632 -> V_267 == V_338 ) {
if ( V_3 -> V_232 == 1 ) {
if ( ! ( F_57 ( V_3 ) & 0x1 ) ) {
F_59 ( 0x01 , 0x01 , V_3 ) ;
F_61 ( V_626 , 2 , V_3 ) ;
}
if ( ! ( F_57 ( V_3 ) & 0x20 ) )
F_59 ( 0x20 , 0x20 , V_3 ) ;
F_61 ( V_626 , 3 , V_3 ) ;
F_59 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_59 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_632 -> V_267 == V_162 ) {
if ( V_3 -> V_232 == 1 ) {
if ( ! ( F_58 ( V_3 ) & 0x1 ) ) {
F_60 ( 0x01 , 0x01 , V_3 ) ;
F_61 ( V_626 , 2 , V_3 ) ;
}
if ( ! ( F_58 ( V_3 ) & 0x20 ) )
F_60 ( 0x20 , 0x20 , V_3 ) ;
F_61 ( V_626 , 3 , V_3 ) ;
F_60 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_60 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_64 ( struct V_625 * V_626 ,
struct V_209 * V_632 ,
struct V_2 * V_3 )
{
if ( V_632 -> V_267 == V_338 ) {
if ( V_3 -> V_232 == 1 ) {
F_59 ( 0x02 , 0x00 , V_3 ) ;
F_61 ( V_626 , 3 , V_3 ) ;
} else {
F_59 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_632 -> V_267 == V_162 ) {
if ( ( F_58 ( V_3 ) & 0x2 ) ) {
F_60 ( 0x02 , 0x00 , V_3 ) ;
F_61 ( V_626 , 3 , V_3 ) ;
}
if ( V_3 -> V_232 == 0 )
F_60 ( 0x20 , 0x00 , V_3 ) ;
}
F_13 ( V_3 -> V_180 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
while ( ( F_8 ( V_3 -> V_217 ) & 0x01 ) )
break;
while ( ! ( F_8 ( V_3 -> V_217 ) & 0x01 ) )
break;
}
static void F_66 ( struct V_2 * V_3 )
{
F_21 ( V_3 -> V_539 , 0x01 , 0x40 ) ;
}
static void F_67 ( unsigned short V_192 ,
struct V_2 * V_3 )
{
unsigned short V_533 , V_300 ;
F_5 ( V_3 -> V_212 , 0x34 , V_192 ) ;
V_533 = ( V_3 -> V_48 & V_208 ) >> 8 ;
V_300 = ~ ( V_208 >> 8 ) ;
F_13 ( V_3 -> V_212 , 0x31 , V_300 , V_533 ) ;
}
static void F_68 ( unsigned short V_192 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_342 , V_365 , V_201 , V_291 ;
V_291 = F_26 ( V_192 , V_193 , V_3 ) ;
if ( V_192 <= 0x13 ) {
V_342 = V_3 -> V_33 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_33 [ V_291 ] . V_295 ;
} else {
V_342 = V_3 -> V_36 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_36 [ V_291 ] . V_295 ;
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
if ( V_201 & V_296 )
V_342 *= 2 ;
if ( V_201 & V_268 )
V_365 *= 2 ;
}
if ( V_3 -> V_48 & V_207 ) {
if ( V_3 -> V_232 == 0 ) {
if ( V_3 -> V_45 == V_633 ) {
if ( ! ( V_3 -> V_47 & V_613 ) ) {
if ( V_365 == 1024 )
V_365 = 1056 ;
}
}
if ( V_3 -> V_45 == V_238 ) {
if ( V_365 == 400 )
V_365 = 405 ;
else if ( V_365 == 350 )
V_365 = 360 ;
if ( V_3 -> V_47 & V_613 ) {
if ( V_365 == 360 )
V_365 = 375 ;
}
}
if ( V_3 -> V_45 == V_259 ) {
if ( ! ( V_3 -> V_47 & V_613 ) ) {
if ( ! ( V_3 -> V_47
& V_240 ) ) {
if ( V_365 == 350 )
V_365 = 357 ;
else if ( V_365 == 400 )
V_365 = 420 ;
else if ( V_365 == 480 )
V_365 = 525 ;
}
}
}
}
if ( V_342 == 720 )
V_342 = 640 ;
}
V_3 -> V_366 = V_342 ;
V_3 -> V_367 = V_342 ;
V_3 -> V_368 = V_365 ;
V_3 -> V_369 = V_365 ;
}
static unsigned char F_69 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_48 & ( V_207 | V_205 ) ) &&
( V_3 -> V_47 & V_611 ) )
return 1 ;
return 0 ;
}
static void F_70 ( unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_226 , V_227 , V_533 , V_300 , V_201 = 0 , V_293 ,
V_197 , V_634 ;
V_3 -> V_635 = 1 ;
V_3 -> V_636 = 1 ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_197 = F_3 ( V_192 , V_193 , V_3 ) ;
V_226 = V_3 -> V_7 [ V_197 ] . V_213 [ 0 ] ;
V_227 = V_3 -> V_7 [ V_197 ] . V_213 [ 6 ] ;
V_533 = V_3 -> V_7 [ V_197 ] . V_213 [ 7 ] ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_634 = V_3 -> V_13 [ V_225 ] .
V_269 ;
V_634 &= V_270 ;
V_533 = ( unsigned short ) V_3 ->
V_16 [ V_634 ] . V_271 [ 0 ] ;
V_300 = ( unsigned short ) V_3 ->
V_16 [ V_634 ] . V_271 [ 5 ] ;
V_226 = ( V_533 & 0xFF ) | ( ( V_300 & 0x03 ) << 8 ) ;
V_227 = ( unsigned short ) V_3 ->
V_16 [ V_634 ] . V_271 [ 8 ] ;
V_293 = ( unsigned short ) V_3 ->
V_16 [ V_634 ] . V_271 [ 14 ] << 8 ;
V_293 &= 0x0100 ;
V_293 = V_293 << 2 ;
V_227 |= V_293 ;
V_533 = ( unsigned short ) V_3 ->
V_16 [ V_634 ] . V_271 [ 9 ] ;
}
if ( V_533 & 0x01 )
V_227 |= 0x0100 ;
if ( V_533 & 0x20 )
V_227 |= 0x0200 ;
V_226 += 5 ;
if ( V_201 & V_216 )
V_226 *= 8 ;
else
V_226 *= 9 ;
V_3 -> V_511 = V_226 ;
V_3 -> V_513 = V_226 ;
V_227 ++ ;
V_3 -> V_512 = V_227 ;
V_3 -> V_515 = V_227 ;
}
static void F_71 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_226 = 0 , V_227 , V_201 , V_228 ;
struct V_637 * V_510 = NULL ;
struct V_638 * V_639 = NULL ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_228 = V_3 -> V_4 [ V_193 ] . V_292 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
}
V_3 -> V_640 = 0 ;
V_3 -> V_641 = 50 ;
if ( V_3 -> V_48 & V_233 ) {
F_70 ( V_192 , V_193 , V_225 ,
V_3 ) ;
return;
}
V_227 = 4 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_510 = (struct V_637 * ) F_38 ( V_227 ,
V_192 , V_193 , V_225 ,
V_3 ) ;
V_3 -> V_635 = V_510 -> V_635 ;
V_3 -> V_636 = V_510 -> V_636 ;
V_3 -> V_511 = V_510 -> V_511 ;
V_3 -> V_512 = V_510 -> V_512 ;
V_3 -> V_513 = V_510 -> V_514 ;
V_3 -> V_515 = V_510 -> V_516 ;
if ( V_3 -> V_45 == V_259 ) {
V_226 = 1024 ;
V_227 = 768 ;
if ( ! ( V_3 -> V_47 & V_613 ) ) {
if ( V_3 -> V_368 == 357 )
V_227 = 527 ;
else if ( V_3 -> V_368 == 420 )
V_227 = 620 ;
else if ( V_3 -> V_368 == 525 )
V_227 = 775 ;
else if ( V_3 -> V_368 == 600 )
V_227 = 775 ;
else
V_227 = 768 ;
} else
V_227 = 768 ;
} else if ( V_3 -> V_45 == V_334 ) {
V_226 = 1024 ;
V_227 = 768 ;
} else if ( V_3 -> V_45 == V_238 ) {
V_226 = 1280 ;
if ( V_3 -> V_368 == 360 )
V_227 = 768 ;
else if ( V_3 -> V_368 == 375 )
V_227 = 800 ;
else if ( V_3 -> V_368 == 405 )
V_227 = 864 ;
else
V_227 = 1024 ;
} else if ( V_3 -> V_45 == V_518 ) {
V_226 = 1280 ;
V_227 = 1024 ;
} else if ( V_3 -> V_45 == V_239 ) {
V_226 = 1280 ;
if ( V_3 -> V_368 == 350 )
V_227 = 700 ;
else if ( V_3 -> V_368 == 400 )
V_227 = 800 ;
else if ( V_3 -> V_368 == 1024 )
V_227 = 960 ;
else
V_227 = 960 ;
} else if ( V_3 -> V_45 == V_519 ) {
V_226 = 1400 ;
V_227 = 1050 ;
if ( V_3 -> V_368 == 1024 ) {
V_226 = 1280 ;
V_227 = 1024 ;
}
} else if ( V_3 -> V_45 == V_633 ) {
V_226 = 1600 ;
V_227 = 1200 ;
if ( ! ( V_3 -> V_47 & V_613 ) ) {
if ( V_3 -> V_368 == 350 )
V_227 = 875 ;
else if ( V_3 -> V_368 == 400 )
V_227 = 1000 ;
}
}
if ( V_3 -> V_47 & V_240 ) {
V_226 = V_3 -> V_366 ;
V_227 = V_3 -> V_368 ;
}
V_3 -> V_367 = V_226 ;
V_3 -> V_369 = V_227 ;
return;
}
if ( V_3 -> V_48 & ( V_206 ) ) {
V_227 = 4 ;
V_639 = (struct V_638 * ) F_39 ( V_227 ,
V_192 , V_193 , V_225 ,
V_3 ) ;
V_3 -> V_635 = V_639 -> V_635 ;
V_3 -> V_636 = V_639 -> V_636 ;
V_3 -> V_511 = V_639 -> V_511 ;
V_3 -> V_512 = V_639 -> V_512 ;
V_3 -> V_367 = V_639 -> V_642 ;
V_3 -> V_369 = V_639 -> V_643 ;
V_3 -> V_641 = V_639 -> V_641 ;
V_3 -> V_640 = V_639 -> V_644 ;
if ( V_3 -> V_48 & V_241 ) {
if ( V_228 == 0x08 )
V_3 -> V_640 = 0x40 ;
else if ( V_228 == 0x09 )
V_3 -> V_640 = 0x40 ;
else if ( V_228 == 0x12 )
V_3 -> V_640 = 0x40 ;
if ( V_3 -> V_368 == 350 )
V_3 -> V_49 |= V_247 ;
V_226 = V_645 ;
V_227 = V_646 ;
if ( V_3 -> V_48 & V_208 ) {
if ( V_3 -> V_49 & V_247 ) {
V_226 = V_647 ;
V_227 = V_648 ;
if ( ! ( V_201 & V_216 ) ) {
V_226 = V_649 ;
V_227 = V_650 ;
}
}
}
} else if ( V_3 -> V_48 & V_251 ) {
if ( V_3 -> V_49 & V_555 ) {
V_226 = V_651 ;
V_227 = V_652 ;
}
if ( V_3 -> V_49 & V_556 ) {
V_226 = V_653 ;
V_227 = V_654 ;
} else if ( V_3 -> V_49 & V_600 ) {
V_226 = V_655 ;
V_227 = V_656 ;
if ( V_3 -> V_49 & V_558 )
V_226 = V_657 ;
}
} else {
V_226 = V_658 ;
V_227 = V_659 ;
if ( ! ( V_3 -> V_49 & V_256 ) ) {
V_226 = V_660 ;
V_227 = V_661 ;
if ( V_3 -> V_49 & V_558 )
V_226 = V_657 ;
}
}
V_3 -> V_513 = V_226 ;
V_3 -> V_515 = V_227 ;
return;
}
}
static void F_72 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned char V_547 , V_548 , V_372 ;
V_372 = F_47 ( V_225 , V_192 , V_193 ,
V_3 ) ;
F_48 ( V_372 , & V_547 , & V_548 , V_3 ) ;
F_46 ( & V_547 , & V_548 , V_3 ) ;
if ( V_3 -> V_147 & V_559 ) {
F_5 ( V_3 -> V_546 , 0x0A , 0x10 ) ;
F_5 ( V_3 -> V_546 , 0x0B , V_548 ) ;
F_5 ( V_3 -> V_546 , 0x0A , V_547 ) ;
} else {
F_5 ( V_3 -> V_546 , 0x0A , V_547 ) ;
F_5 ( V_3 -> V_546 , 0x0B , V_548 ) ;
}
F_5 ( V_3 -> V_546 , 0x00 , 0x12 ) ;
if ( V_3 -> V_48 & V_233 )
F_21 ( V_3 -> V_546 , 0x12 , 0x28 ) ;
else
F_21 ( V_3 -> V_546 , 0x12 , 0x08 ) ;
}
static unsigned short F_73 ( unsigned short V_192 ,
unsigned short V_193 , struct V_2 * V_3 )
{
unsigned short V_662 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_194 ;
unsigned short V_201 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_194 = ( V_201 & V_577 ) - V_303 ;
if ( V_194 < 0 )
V_194 = 0 ;
return V_662 [ V_194 ] ;
}
static unsigned short F_74 ( unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_163 , V_663 , V_664 , V_194 , V_229 ,
V_662 [] = { 0x01 , 0x02 , 0x04 } ;
V_664 = V_3 -> V_10 [ V_193 ] . V_302 ;
if ( V_192 <= 0x14 )
V_229 = 0 ;
else
V_229 = V_3 ->
V_13 [ V_225 ] . V_260 ;
V_194 = ( V_664 >> 8 ) & 0xFF ;
V_163 = V_3 -> V_31 [ V_194 ] ;
if ( V_229 & V_297 )
V_163 = V_163 << 1 ;
V_663 = F_73 ( V_192 , V_193 , V_3 ) ;
if ( ( V_192 >= 0x7C ) && ( V_192 <= 0x7E ) ) {
V_163 = V_192 - 0x7C ;
V_663 = V_662 [ V_163 ] ;
V_163 = 0x6B ;
if ( V_229 & V_297 )
V_163 = V_163 << 1 ;
return V_163 * V_663 ;
} else {
return V_163 * V_663 ;
}
}
static void F_75 ( unsigned short V_192 ,
unsigned short V_193 ,
unsigned short V_225 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_665 ;
unsigned char V_163 ;
if ( V_3 -> V_48 & V_208 )
return;
V_665 = F_74 ( V_192 , V_193 , V_225 ,
V_210 , V_3 ) ;
V_163 = ( unsigned char ) ( V_665 & 0xFF ) ;
F_5 ( V_3 -> V_539 , 0x07 , V_163 ) ;
V_163 = ( unsigned char ) ( ( V_665 & 0xFF00 ) >> 8 ) ;
F_5 ( V_3 -> V_539 , 0x09 , V_163 ) ;
V_163 = ( unsigned char ) ( ( ( V_665 >> 3 ) & 0xFF ) + 1 ) ;
F_5 ( V_3 -> V_539 , 0x03 , V_163 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
F_5 ( V_3 -> V_539 , 0x01 , 0x3B ) ;
F_13 ( V_3 -> V_539 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_77 ( unsigned short V_192 , unsigned short V_193 ,
struct V_209 * V_210 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_293 = 0 , V_634 = 0 , V_228 = 0 ;
if ( V_192 > 0x13 ) {
V_634 = V_3 ->
V_13 [ V_225 ] . V_269 ;
V_634 &= V_270 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
}
F_75 ( V_192 , V_193 , V_225 ,
V_210 , V_3 ) ;
F_76 ( V_3 ) ;
for ( V_293 = 4 ; V_293 < 7 ; V_293 ++ )
F_5 ( V_3 -> V_539 , V_293 , 0x0 ) ;
F_5 ( V_3 -> V_539 , 0x50 , 0x00 ) ;
F_5 ( V_3 -> V_539 , 0x02 , 0x44 ) ;
}
static void F_78 ( unsigned short V_192 , unsigned short V_193 ,
struct V_209 * V_210 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_163 = 0 , V_226 = 0 , V_227 = 0 , V_293 = 0 ,
V_666 = 0 , V_634 = 0 , V_201 , V_228 = 0 ;
if ( V_192 > 0x13 ) {
V_634 = V_3 ->
V_13 [ V_225 ] . V_269 ;
V_634 &= V_270 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
}
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
if ( V_201 & V_296 ) {
V_163 = ( V_3 -> V_511 / 2 - 1 ) & 0x0FF ;
F_5 ( V_3 -> V_539 , 0x08 , V_163 ) ;
V_163 = ( ( ( V_3 -> V_511 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_13 ( V_3 -> V_539 , 0x09 , ~ 0x0F0 , V_163 ) ;
V_163 = ( V_3 -> V_366 / 2 + 16 ) & 0x0FF ;
F_5 ( V_3 -> V_539 , 0x0A , V_163 ) ;
V_293 = ( ( V_3 -> V_511 - V_3 -> V_366 ) / 2 ) >> 2 ;
V_666 = V_3 -> V_366 / 2 + 16 ;
V_293 = V_293 >> 1 ;
V_227 = V_666 + V_293 ;
V_293 += V_227 ;
if ( V_3 -> V_48 & V_233 ) {
V_227 = V_3 -> V_16 [ V_634 ] . V_271 [ 4 ] ;
V_227 |= ( ( V_3 ->
V_16 [ V_634 ] . V_271 [ 14 ] &
0xC0 ) << 2 ) ;
V_227 = ( V_227 - 3 ) << 3 ;
V_293 = V_3 -> V_16 [ V_634 ] . V_271 [ 5 ] ;
V_293 &= 0x1F ;
V_163 = V_3 -> V_16 [ V_634 ] . V_271 [ 15 ] ;
V_163 = ( V_163 & 0x04 ) << ( 5 - 2 ) ;
V_293 = ( ( V_293 | V_163 ) - 3 ) << 3 ;
}
V_227 += 4 ;
V_293 += 4 ;
if ( V_293 > ( V_3 -> V_511 / 2 ) )
V_293 = V_3 -> V_511 / 2 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0B , V_163 ) ;
} else {
V_163 = ( V_3 -> V_511 - 1 ) & 0x0FF ;
F_5 ( V_3 -> V_539 , 0x08 , V_163 ) ;
V_163 = ( ( ( V_3 -> V_511 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_13 ( V_3 -> V_539 , 0x09 , ~ 0x0F0 , V_163 ) ;
V_163 = ( V_3 -> V_366 + 16 ) & 0x0FF ;
F_5 ( V_3 -> V_539 , 0x0A , V_163 ) ;
V_293 = ( V_3 -> V_511 - V_3 -> V_366 ) >> 2 ;
V_666 = V_3 -> V_366 + 16 ;
V_293 = V_293 >> 1 ;
V_227 = V_666 + V_293 ;
V_293 += V_227 ;
if ( V_3 -> V_48 & V_233 ) {
V_227 = V_3 -> V_16 [ V_634 ] . V_271 [ 3 ] ;
V_227 |= ( ( V_3 ->
V_16 [ V_634 ] . V_271 [ 5 ] &
0xC0 ) << 2 ) ;
V_227 = ( V_227 - 3 ) << 3 ;
V_293 = V_3 -> V_16 [ V_634 ] . V_271 [ 4 ] ;
V_293 &= 0x1F ;
V_163 = V_3 -> V_16 [ V_634 ] . V_271 [ 6 ] ;
V_163 = ( V_163 & 0x04 ) << ( 5 - 2 ) ;
V_293 = ( ( V_293 | V_163 ) - 3 ) << 3 ;
V_227 += 16 ;
V_293 += 16 ;
}
if ( V_293 > V_3 -> V_511 )
V_293 = V_3 -> V_511 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0B , V_163 ) ;
}
V_226 = ( V_226 & 0x00FF ) | ( V_227 & 0xFF00 ) ;
V_227 = V_666 ;
V_227 = ( V_227 & 0x00FF ) | ( ( V_227 & 0xFF00 ) << 4 ) ;
V_226 |= ( V_227 & 0xFF00 ) ;
V_163 = ( V_226 & 0xFF00 ) >> 8 ;
F_5 ( V_3 -> V_539 , 0x0C , V_163 ) ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0D , V_163 ) ;
V_293 = ( V_3 -> V_512 - 1 ) ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0E , V_163 ) ;
V_227 = V_3 -> V_368 - 1 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0F , V_163 ) ;
V_163 = ( ( V_227 & 0xFF00 ) << 3 ) >> 8 ;
V_163 |= ( ( V_293 & 0xFF00 ) >> 8 ) ;
F_5 ( V_3 -> V_539 , 0x12 , V_163 ) ;
V_226 = V_3 -> V_368 ;
V_227 = V_3 -> V_368 ;
V_293 = V_3 -> V_512 ;
V_227 = ( V_3 -> V_512 + V_3 -> V_368 ) >> 1 ;
V_293 = ( ( V_3 -> V_512 - V_3 -> V_368 ) >> 4 ) + V_227 + 1 ;
if ( V_3 -> V_48 & V_233 ) {
V_227 = V_3 -> V_16 [ V_634 ] . V_271 [ 10 ] ;
V_163 = V_3 -> V_16 [ V_634 ] . V_271 [ 9 ] ;
if ( V_163 & 0x04 )
V_227 |= 0x0100 ;
if ( V_163 & 0x080 )
V_227 |= 0x0200 ;
V_163 = V_3 -> V_16 [ V_634 ] . V_271 [ 14 ] ;
if ( V_163 & 0x08 )
V_227 |= 0x0400 ;
V_163 = V_3 -> V_16 [ V_634 ] . V_271 [ 11 ] ;
V_293 = ( V_293 & 0xFF00 ) | ( V_163 & 0x00FF ) ;
}
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x10 , V_163 ) ;
V_163 = ( ( V_227 & 0xFF00 ) >> 8 ) << 4 ;
V_163 = ( ( V_293 & 0x000F ) | ( V_163 ) ) ;
F_5 ( V_3 -> V_539 , 0x11 , V_163 ) ;
V_226 = 0 ;
if ( V_201 & V_268 )
V_226 |= 0x80 ;
if ( V_201 & V_296 )
V_226 |= 0x40 ;
F_13 ( V_3 -> V_539 , 0x2C , ~ 0x0C0 , V_226 ) ;
}
static unsigned short F_79 ( struct V_2 * V_3 )
{
unsigned long V_226 , V_227 ;
V_227 = ( ( V_3 -> V_512 - V_3 -> V_368 ) * V_3 -> V_635 )
& 0xFFFF ;
V_226 = ( V_3 -> V_515 - V_3 -> V_369 ) * V_3 -> V_636 ;
V_226 = ( V_226 * V_3 -> V_513 ) / V_227 ;
return ( unsigned short ) V_226 ;
}
static void F_80 ( unsigned short V_192 , unsigned short V_193 ,
struct V_209 * V_210 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_531 , V_532 , V_226 , V_227 = 0 , V_293 , V_163 , V_228 ,
V_201 , V_634 ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_228 = V_3 -> V_4 [ V_193 ] . V_292 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
V_634 = V_3 ->
V_13 [ V_225 ] . V_269 ;
V_634 &= V_270 ;
}
if ( ! ( V_3 -> V_48 & V_208 ) )
return;
V_163 = 0xFF ;
F_5 ( V_3 -> V_539 , 0x03 , V_163 ) ;
V_293 = 0x08 ;
if ( V_3 -> V_147 & ( V_148 | V_149 | V_235 ) )
V_201 |= V_216 ;
V_226 = V_3 -> V_366 ;
if ( V_201 & V_296 )
V_226 = V_226 >> 1 ;
V_226 = ( V_226 / V_293 ) - 1 ;
V_227 |= ( ( V_226 & 0x00FF ) << 8 ) ;
V_163 = V_226 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x04 , V_163 ) ;
V_163 = ( V_227 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_48 & V_206 ) {
if ( ! ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) )
V_163 += 2 ;
if ( V_3 -> V_48 & V_241 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_242 == V_243 ) {
if ( V_228 == 7 )
V_163 -= 2 ;
}
} else if ( V_228 == 7 ) {
V_163 -= 2 ;
}
}
}
F_5 ( V_3 -> V_539 , 0x05 , V_163 ) ;
F_5 ( V_3 -> V_539 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_48 & V_579 ) ) {
if ( V_3 -> V_48 & V_206 )
V_226 = V_3 -> V_511 ;
else
V_226 = F_79 ( V_3 ) ;
}
if ( V_226 >= V_3 -> V_511 )
V_226 = V_3 -> V_511 ;
if ( V_201 & V_296 )
V_226 = V_226 >> 1 ;
V_226 = ( V_226 / V_293 ) - 5 ;
V_293 = V_226 ;
if ( V_3 -> V_48 & V_241 ) {
V_163 = ( V_227 & 0x00FF ) - 1 ;
if ( ! ( V_201 & V_296 ) ) {
V_163 -= 6 ;
if ( V_3 -> V_49 & V_247 ) {
V_163 -= 4 ;
if ( V_192 > 0x13 )
V_163 -= 10 ;
}
}
} else {
V_227 = ( V_227 & 0xFF00 ) >> 8 ;
V_293 = ( V_293 + V_227 ) >> 1 ;
V_163 = ( V_293 & 0x00FF ) + 2 ;
if ( V_3 -> V_48 & V_206 ) {
V_163 -= 1 ;
if ( ! ( V_201 & V_296 ) ) {
if ( ( V_201 & V_216 ) ) {
V_163 += 4 ;
if ( V_3 -> V_366 >= 800 )
V_163 -= 6 ;
}
}
} else if ( ! ( V_201 & V_296 ) ) {
V_163 -= 4 ;
if ( V_3 -> V_45 != V_239 &&
V_3 -> V_366 >= 800 ) {
V_163 -= 7 ;
if ( V_3 -> V_196 == V_303 &&
V_3 -> V_368 == 1024 ) {
V_163 += 15 ;
if ( V_3 -> V_45 !=
V_238 )
V_163 += 7 ;
}
if ( V_3 -> V_366 >= 1280 &&
V_3 -> V_45 != V_239 &&
( V_3 -> V_47 & V_240 ) )
V_163 += 28 ;
}
}
}
F_5 ( V_3 -> V_539 , 0x07 , V_163 ) ;
F_5 ( V_3 -> V_539 , 0x08 , 0 ) ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_49 & V_247 ) {
if ( ( V_192 == 0x06 ) || ( V_192 == 0x10 ) || ( V_192
== 0x11 ) || ( V_192 == 0x13 ) || ( V_192
== 0x0F ) ) {
F_5 ( V_3 -> V_539 , 0x07 , 0x5b ) ;
F_5 ( V_3 -> V_539 , 0x08 , 0x03 ) ;
}
if ( ( V_192 == 0x00 ) || ( V_192 == 0x01 ) ) {
if ( V_3 -> V_49 & V_667 ) {
F_5 ( V_3 -> V_539 ,
0x07 , 0x2A ) ;
F_5 ( V_3 -> V_539 ,
0x08 , 0x61 ) ;
} else {
F_5 ( V_3 -> V_539 ,
0x07 , 0x2A ) ;
F_5 ( V_3 -> V_539 ,
0x08 , 0x41 ) ;
F_5 ( V_3 -> V_539 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_192 == 0x02 ) || ( V_192 == 0x03 ) || ( V_192
== 0x07 ) ) {
if ( V_3 -> V_49 & V_667 ) {
F_5 ( V_3 -> V_539 ,
0x07 , 0x54 ) ;
F_5 ( V_3 -> V_539 ,
0x08 , 0x00 ) ;
} else {
F_5 ( V_3 -> V_539 ,
0x07 , 0x55 ) ;
F_5 ( V_3 -> V_539 ,
0x08 , 0x00 ) ;
F_5 ( V_3 -> V_539 ,
0x0C , 0xF0 ) ;
}
}
if ( ( V_192 == 0x04 ) || ( V_192 == 0x05 ) || ( V_192
== 0x0D ) || ( V_192 == 0x50 ) ) {
if ( V_3 -> V_49 & V_667 ) {
F_5 ( V_3 -> V_539 ,
0x07 , 0x30 ) ;
F_5 ( V_3 -> V_539 ,
0x08 , 0x03 ) ;
} else {
F_5 ( V_3 -> V_539 ,
0x07 , 0x2f ) ;
F_5 ( V_3 -> V_539 ,
0x08 , 0x02 ) ;
}
}
}
}
F_5 ( V_3 -> V_539 , 0x18 , 0x03 ) ;
F_13 ( V_3 -> V_539 , 0x19 , 0xF0 , 0x00 ) ;
F_5 ( V_3 -> V_539 , 0x09 , 0xFF ) ;
V_227 = V_3 -> V_512 ;
V_531 = V_227 ;
V_293 = 0x121 ;
V_227 = V_3 -> V_368 ;
if ( V_227 == 357 )
V_227 = 350 ;
if ( V_227 == 360 )
V_227 = 350 ;
if ( V_227 == 375 )
V_227 = 350 ;
if ( V_227 == 405 )
V_227 = 400 ;
if ( V_227 == 525 )
V_227 = 480 ;
V_532 = V_227 ;
if ( V_3 -> V_48 & V_207 ) {
if ( V_3 -> V_45 == V_259 ) {
if ( ! ( V_3 -> V_47 & V_613 ) ) {
if ( V_227 == 350 )
V_227 += 5 ;
if ( V_227 == 480 )
V_227 += 5 ;
}
}
}
V_227 -- ;
V_163 = V_227 & 0x00FF ;
V_227 -- ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x10 , V_163 ) ;
V_227 = V_532 ;
V_227 -- ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0E , V_163 ) ;
if ( V_227 & 0x0100 )
V_293 |= 0x0002 ;
V_226 = 0x000B ;
if ( V_201 & V_268 )
V_226 |= 0x08000 ;
if ( V_227 & 0x0200 )
V_293 |= 0x0040 ;
V_163 = ( V_226 & 0xFF00 ) >> 8 ;
F_5 ( V_3 -> V_539 , 0x0B , V_163 ) ;
if ( V_227 & 0x0400 )
V_293 |= 0x0600 ;
F_5 ( V_3 -> V_539 , 0x11 , 0x00 ) ;
V_226 = V_531 ;
V_226 -= V_227 ;
V_226 = V_226 >> 2 ;
V_531 = V_226 ;
if ( V_228 != 0x09 ) {
V_226 = V_226 << 1 ;
V_227 += V_226 ;
}
if ( V_3 -> V_48 & V_241 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_603 ) {
V_227 -= 10 ;
} else {
if ( V_3 -> V_49 & V_247 ) {
if ( V_3 -> V_49 & V_256 ) {
if ( V_3 -> V_147 &
V_148 ) {
if ( ! ( V_3 -> V_49 &
( V_556 |
V_555 |
V_603 ) ) )
V_227 += 40 ;
} else {
V_227 += 40 ;
}
}
}
}
} else {
V_227 -= 10 ;
}
} else {
if ( V_3 -> V_49 & V_247 ) {
if ( V_3 -> V_49 & V_256 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( ! ( V_3 -> V_49 &
( V_556 |
V_555 |
V_603 ) ) )
V_227 += 40 ;
} else {
V_227 += 40 ;
}
}
}
}
V_226 = V_531 ;
V_226 = V_226 >> 2 ;
V_226 ++ ;
V_226 += V_227 ;
V_531 = V_226 ;
if ( ( V_3 -> V_49 & V_256 ) ) {
if ( V_227 <= 513 ) {
if ( V_226 >= 513 )
V_227 = 513 ;
}
}
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0C , V_163 ) ;
V_227 -- ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x10 , V_163 ) ;
if ( V_227 & 0x0100 )
V_293 |= 0x0008 ;
if ( V_227 & 0x0200 )
F_13 ( V_3 -> V_539 , 0x0B , 0x0FF , 0x20 ) ;
V_227 ++ ;
if ( V_227 & 0x0100 )
V_293 |= 0x0004 ;
if ( V_227 & 0x0200 )
V_293 |= 0x0080 ;
if ( V_227 & 0x0400 )
V_293 |= 0x0C00 ;
V_227 = V_531 ;
V_163 = V_227 & 0x00FF ;
V_163 &= 0x0F ;
F_5 ( V_3 -> V_539 , 0x0D , V_163 ) ;
if ( V_227 & 0x0010 )
V_293 |= 0x2000 ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_539 , 0x0A , V_163 ) ;
V_163 = ( V_293 & 0x0FF00 ) >> 8 ;
F_5 ( V_3 -> V_539 , 0x17 , V_163 ) ;
V_226 = V_201 ;
V_163 = ( V_226 & 0xFF00 ) >> 8 ;
V_163 = ( V_163 >> 1 ) & 0x09 ;
if ( V_3 -> V_147 & ( V_148 | V_149 | V_235 ) )
V_163 |= 0x01 ;
F_5 ( V_3 -> V_539 , 0x16 , V_163 ) ;
F_5 ( V_3 -> V_539 , 0x0F , 0 ) ;
F_5 ( V_3 -> V_539 , 0x12 , 0 ) ;
if ( V_3 -> V_47 & V_668 )
V_163 = 0x80 ;
else
V_163 = 0x00 ;
F_5 ( V_3 -> V_539 , 0x1A , V_163 ) ;
return;
}
static void F_81 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_200 , V_266 , V_226 , V_227 , V_293 , V_163 , V_531 , V_532 ,
V_201 , V_228 , V_669 ;
unsigned char * V_670 ;
unsigned long V_671 , V_672 , V_673 , V_300 , V_674 ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_228 = V_3 -> V_4 [ V_193 ] . V_292 ;
V_669 = V_3 -> V_4 [ V_193 ] . V_314 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
V_669 = V_3 -> V_13 [ V_225 ] .
V_315 ;
}
V_226 = 0 ;
if ( ! ( V_3 -> V_48 & V_248 ) )
V_226 |= 0x0800 ;
if ( ! ( V_3 -> V_48 & V_249 ) )
V_226 |= 0x0400 ;
if ( V_3 -> V_48 & V_250 )
V_226 |= 0x0200 ;
if ( ! ( V_3 -> V_49 & V_256 ) )
V_226 |= 0x1000 ;
if ( V_3 -> V_48 & V_241 )
V_226 |= 0x0100 ;
if ( V_3 -> V_49 & ( V_556 | V_555 ) )
V_226 &= 0xfe00 ;
V_226 = ( V_226 & 0xff00 ) >> 8 ;
F_5 ( V_3 -> V_565 , 0x0 , V_226 ) ;
V_670 = V_3 -> V_110 ;
if ( V_3 -> V_49 & V_256 )
V_670 = V_3 -> V_112 ;
if ( V_3 -> V_48 & V_241 ) {
V_670 = V_3 -> V_114 ;
if ( V_3 -> V_48 & V_208 )
V_670 = V_3 -> V_118 ;
if ( V_3 -> V_246 & V_247 )
V_670 = V_3 -> V_116 ;
if ( ! ( V_201 & V_216 ) )
V_670 = V_3 -> V_120 ;
}
if ( V_3 -> V_48 & V_251 ) {
if ( V_3 -> V_49 & V_600 )
V_670 = V_3 -> V_126 ;
if ( V_3 -> V_49 & V_556 )
V_670 = V_3 -> V_124 ;
if ( V_3 -> V_49 & V_555 )
V_670 = V_3 -> V_122 ;
}
for ( V_200 = 0x01 , V_266 = 0 ; V_200 <= 0x2D ; V_200 ++ , V_266 ++ )
F_5 ( V_3 -> V_565 , V_200 , V_670 [ V_266 ] ) ;
for ( V_200 = 0x39 ; V_200 <= 0x45 ; V_200 ++ , V_266 ++ )
F_5 ( V_3 -> V_565 , V_200 , V_670 [ V_266 ] ) ;
if ( V_3 -> V_48 & V_206 )
F_13 ( V_3 -> V_565 , 0x3A , 0x1F , 0x00 ) ;
V_163 = V_3 -> V_640 ;
V_163 &= 0x80 ;
F_13 ( V_3 -> V_565 , 0x0A , 0xFF , V_163 ) ;
if ( V_3 -> V_48 & V_241 )
V_226 = 950 ;
if ( V_3 -> V_49 & V_256 )
V_226 = 520 ;
else
V_226 = 440 ;
if ( V_3 -> V_369 <= V_226 ) {
V_226 -= V_3 -> V_369 ;
V_226 = V_226 >> 2 ;
V_226 = ( V_226 & 0x00FF ) | ( ( V_226 & 0x00FF ) << 8 ) ;
V_531 = V_226 ;
V_163 = ( V_226 & 0xFF00 ) >> 8 ;
V_163 += ( unsigned short ) V_670 [ 0 ] ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
if ( V_3 -> V_48 & ( V_248
| V_249 | V_250
| V_251 ) ) {
V_293 = V_3 -> V_366 ;
if ( V_293 >= 1024 ) {
V_163 = 0x17 ;
if ( V_3 -> V_49 & V_256 )
V_163 = 0x19 ;
}
}
}
F_5 ( V_3 -> V_565 , 0x01 , V_163 ) ;
V_226 = V_531 ;
V_163 = ( V_226 & 0xFF00 ) >> 8 ;
V_163 += V_670 [ 1 ] ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
if ( ( V_3 -> V_48 & ( V_248
| V_249 | V_250
| V_251 ) ) ) {
V_293 = V_3 -> V_366 ;
if ( V_293 >= 1024 ) {
V_163 = 0x1D ;
if ( V_3 -> V_49 & V_256 )
V_163 = 0x52 ;
}
}
}
F_5 ( V_3 -> V_565 , 0x02 , V_163 ) ;
}
V_293 = V_3 -> V_513 ;
if ( F_69 ( V_3 ) )
V_293 = V_293 >> 1 ;
V_293 -= 2 ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x1B , V_163 ) ;
V_163 = ( V_293 & 0xFF00 ) >> 8 ;
F_13 ( V_3 -> V_565 , 0x1D , ~ 0x0F , V_163 ) ;
V_293 = V_3 -> V_513 >> 1 ;
V_531 = V_293 ;
V_293 += 7 ;
if ( V_3 -> V_48 & V_241 )
V_293 -= 4 ;
V_163 = V_293 & 0x00FF ;
V_163 = V_163 << 4 ;
F_13 ( V_3 -> V_565 , 0x22 , 0x0F , V_163 ) ;
V_227 = V_670 [ V_266 ] | ( ( V_670 [ V_266 + 1 ] ) << 8 ) ;
V_227 += V_293 ;
V_532 = V_227 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x24 , V_163 ) ;
V_163 = ( V_227 & 0xFF00 ) >> 8 ;
V_163 = V_163 << 4 ;
F_13 ( V_3 -> V_565 , 0x25 , 0x0F , V_163 ) ;
V_227 = V_532 ;
V_227 = V_227 + 8 ;
if ( V_3 -> V_48 & V_241 ) {
V_227 = V_227 - 4 ;
V_293 = V_227 ;
}
V_163 = ( V_227 & 0x00FF ) << 4 ;
F_13 ( V_3 -> V_565 , 0x29 , 0x0F , V_163 ) ;
V_266 += 2 ;
V_293 += ( V_670 [ V_266 ] | ( ( V_670 [ V_266 + 1 ] ) << 8 ) ) ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x27 , V_163 ) ;
V_163 = ( ( V_293 & 0xFF00 ) >> 8 ) << 4 ;
F_13 ( V_3 -> V_565 , 0x28 , 0x0F , V_163 ) ;
V_293 += 8 ;
if ( V_3 -> V_48 & V_241 )
V_293 -= 4 ;
V_163 = V_293 & 0xFF ;
V_163 = V_163 << 4 ;
F_13 ( V_3 -> V_565 , 0x2A , 0x0F , V_163 ) ;
V_293 = V_531 ;
V_266 += 2 ;
V_163 = V_670 [ V_266 ] | ( ( V_670 [ V_266 + 1 ] ) << 8 ) ;
V_293 -= V_163 ;
V_163 = V_293 & 0x00FF ;
V_163 = V_163 << 4 ;
F_13 ( V_3 -> V_565 , 0x2D , 0x0F , V_163 ) ;
V_293 -= 11 ;
if ( ! ( V_3 -> V_48 & V_206 ) ) {
V_226 = F_79 ( V_3 ) ;
V_293 = V_226 - 1 ;
}
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x2E , V_163 ) ;
V_227 = V_3 -> V_369 ;
if ( V_3 -> V_368 == 360 )
V_227 = 746 ;
if ( V_3 -> V_368 == 375 )
V_227 = 746 ;
if ( V_3 -> V_368 == 405 )
V_227 = 853 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_147 &
( V_148 | V_149 | V_235 ) ) {
if ( ! ( V_3 -> V_49 &
( V_556 | V_555 ) ) )
V_227 = V_227 >> 1 ;
} else
V_227 = V_227 >> 1 ;
}
V_227 -= 2 ;
V_163 = V_227 & 0x00FF ;
if ( V_3 -> V_48 & V_241 ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_603 ) {
if ( V_3 -> V_48 & V_208 ) {
if ( V_192 == 0x2f )
V_163 += 1 ;
}
}
} else {
if ( V_3 -> V_48 & V_208 ) {
if ( V_192 == 0x2f )
V_163 += 1 ;
}
}
}
F_5 ( V_3 -> V_565 , 0x2F , V_163 ) ;
V_163 = ( V_293 & 0xFF00 ) >> 8 ;
V_163 |= ( ( V_227 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_48 & V_241 ) ) {
if ( V_3 -> V_147 & V_148 ) {
if ( V_3 -> V_49 & V_603 ) {
V_163 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_249 ) )
V_163 |= 0x20 ;
}
} else {
V_163 |= 0x10 ;
if ( ! ( V_3 -> V_48 & V_249 ) )
V_163 |= 0x20 ;
}
}
F_5 ( V_3 -> V_565 , 0x30 , V_163 ) ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
V_227 = V_3 -> V_369 ;
V_293 = V_227 - 2 ;
if ( V_3 -> V_48 & V_206 ) {
if ( ! ( V_3 -> V_49 & ( V_556
| V_555 ) ) )
V_227 = V_227 >> 1 ;
}
if ( V_3 -> V_147 & ( V_149 | V_235 ) ) {
V_163 = 0 ;
if ( V_293 & 0x0400 )
V_163 |= 0x20 ;
if ( V_227 & 0x0400 )
V_163 |= 0x40 ;
F_5 ( V_3 -> V_546 , 0x10 , V_163 ) ;
}
V_163 = ( ( ( V_227 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_5 ( V_3 -> V_565 , 0x46 , V_163 ) ;
V_163 = ( V_227 - 3 ) & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x47 , V_163 ) ;
}
V_227 = V_227 & 0x00FF ;
if ( ! ( V_201 & V_296 ) ) {
V_293 = V_3 -> V_366 ;
if ( V_293 >= V_3 -> V_367 ) {
V_227 |= 0x2000 ;
V_226 &= 0x00FF ;
}
}
V_293 = 0x0101 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_366 >= 1024 ) {
V_293 = 0x1920 ;
if ( V_3 -> V_366 >= 1280 ) {
V_293 = 0x1420 ;
V_227 = V_227 & 0xDFFF ;
}
}
}
if ( ! ( V_227 & 0x2000 ) ) {
if ( V_201 & V_296 )
V_293 = ( V_293 & 0xFF00 ) | ( ( V_293 & 0x00FF ) << 1 ) ;
V_531 = V_227 ;
V_672 = V_3 -> V_366 ;
V_673 = ( V_293 & 0xFF00 ) >> 8 ;
V_671 = V_672 * V_673 ;
V_674 = V_293 & 0x00FF ;
V_671 = V_671 / V_674 ;
V_674 = 8 * 1024 ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
V_674 = V_674 * 8 ;
}
V_671 = V_671 * V_674 ;
V_674 = V_3 -> V_367 ;
V_300 = V_671 % V_674 ;
V_672 = V_671 / V_674 ;
if ( V_300 != 0 )
V_672 += 1 ;
V_226 = ( unsigned short ) V_672 ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
V_293 = ( ( V_226 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_227 = V_531 ;
V_227 = ( unsigned short ) ( ( ( V_672 & 0x0000FF00 ) & 0x1F00 )
| ( V_227 & 0x00FF ) ) ;
V_226 = ( unsigned short ) ( ( ( V_672 & 0x000000FF ) << 8 )
| ( V_226 & 0x00FF ) ) ;
V_163 = ( V_226 & 0xFF00 ) >> 8 ;
} else {
V_163 = ( V_226 & 0x00FF ) >> 8 ;
}
F_5 ( V_3 -> V_565 , 0x44 , V_163 ) ;
V_163 = ( V_227 & 0xFF00 ) >> 8 ;
F_13 ( V_3 -> V_565 , 0x45 , ~ 0x03F , V_163 ) ;
V_163 = V_293 & 0x00FF ;
if ( V_227 & 0x2000 )
V_163 = 0 ;
if ( ! ( V_3 -> V_48 & V_207 ) )
V_163 |= 0x18 ;
F_13 ( V_3 -> V_565 , 0x46 , ~ 0x1F , V_163 ) ;
if ( V_3 -> V_49 & V_256 ) {
V_227 = 0x0382 ;
V_293 = 0x007e ;
} else {
V_227 = 0x0369 ;
V_293 = 0x0061 ;
}
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x4b , V_163 ) ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x4c , V_163 ) ;
V_163 = ( ( V_293 & 0xFF00 ) >> 8 ) & 0x03 ;
V_163 = V_163 << 2 ;
V_163 |= ( ( V_227 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_48 & V_251 ) {
V_163 |= 0x10 ;
if ( V_3 -> V_49 & V_556 )
V_163 |= 0x20 ;
if ( V_3 -> V_49 & V_555 )
V_163 |= 0x60 ;
}
F_5 ( V_3 -> V_565 , 0x4d , V_163 ) ;
V_163 = F_2 ( V_3 -> V_565 , 0x43 ) ;
F_5 ( V_3 -> V_565 , 0x43 , ( unsigned short ) ( V_163 - 3 ) ) ;
if ( ! ( V_3 -> V_49 & ( V_556 | V_555 ) ) ) {
if ( V_3 -> V_49 & V_558 ) {
V_670 = V_675 ;
for ( V_200 = 0x1c , V_266 = 0 ; V_200 <= 0x30 ; V_200 ++ , V_266 ++ ) {
F_5 ( V_3 -> V_565 , V_200 ,
V_670 [ V_266 ] ) ;
}
F_5 ( V_3 -> V_565 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_147 & V_235 ) {
if ( V_3 -> V_49 & V_596 )
F_13 ( V_3 -> V_565 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_49 & V_596 ) {
V_226 = ( unsigned char ) F_2 ( V_3 -> V_565 ,
0x01 ) ;
V_226 -- ;
F_14 ( V_3 -> V_565 , 0x01 , V_226 ) ;
F_14 ( V_3 -> V_565 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_48 & V_241 ) {
if ( ! ( V_3 -> V_48 & V_208 ) )
F_5 ( V_3 -> V_565 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_48 & V_206 )
return;
}
static void F_82 ( unsigned short V_192 , unsigned short V_193 ,
struct V_209 * V_210 ,
unsigned short V_225 ,
struct V_2 * V_3 )
{
unsigned short V_531 , V_532 , V_666 , V_226 , V_227 , V_293 , V_163 ,
V_198 , V_622 , V_561 , V_228 , V_201 , V_634 ;
struct V_676 * V_677 = NULL ;
if ( V_192 <= 0x13 ) {
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
V_228 = V_3 -> V_4 [ V_193 ] . V_292 ;
} else {
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_228 = V_3 -> V_10 [ V_193 ] . V_230 ;
V_634 = V_3 -> V_13 [ V_225 ] .
V_269 ;
V_634 &= V_270 ;
}
if ( ! ( V_3 -> V_48 & V_207 ) )
return;
V_227 = V_3 -> V_367 ;
if ( F_69 ( V_3 ) )
V_227 = V_227 >> 1 ;
V_227 -= 1 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x2C , V_163 ) ;
V_163 = ( V_227 & 0xFF00 ) >> 8 ;
V_163 = V_163 << 4 ;
F_13 ( V_3 -> V_565 , 0x2B , 0x0F , V_163 ) ;
V_163 = 0x01 ;
if ( V_3 -> V_45 == V_238 ) {
if ( V_3 -> V_196 == V_303 ) {
if ( V_3 -> V_366 >= 1024 ) {
V_163 = 0x02 ;
if ( V_3 -> V_47 & V_613 )
V_163 = 0x01 ;
}
}
}
F_5 ( V_3 -> V_565 , 0x0B , V_163 ) ;
V_227 = V_3 -> V_369 ;
V_531 = V_227 ;
V_227 -- ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x03 , V_163 ) ;
V_163 = ( ( V_227 & 0xFF00 ) >> 8 ) & 0x07 ;
F_13 ( V_3 -> V_565 , 0x0C , ~ 0x07 , V_163 ) ;
V_293 = V_3 -> V_515 - 1 ;
V_532 = V_293 + 1 ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x19 , V_163 ) ;
V_163 = ( V_293 & 0xFF00 ) >> 8 ;
V_163 = V_163 << 5 ;
F_5 ( V_3 -> V_565 , 0x1A , V_163 ) ;
F_13 ( V_3 -> V_565 , 0x09 , 0xF0 , 0x00 ) ;
F_13 ( V_3 -> V_565 , 0x0A , 0xF0 , 0x00 ) ;
F_13 ( V_3 -> V_565 , 0x17 , 0xFB , 0x00 ) ;
F_13 ( V_3 -> V_565 , 0x18 , 0xDF , 0x00 ) ;
V_227 = 5 ;
V_677 = (struct V_676 * ) F_38 ( V_227 , V_192 ,
V_193 , V_225 , V_3 ) ;
V_198 = V_3 -> V_45 ;
V_198 &= V_388 ;
if ( ( V_198 == V_259 ) || ( V_198 == V_334 ) ) {
V_227 = 1024 ;
V_293 = 768 ;
} else if ( ( V_198 == V_238 ) ||
( V_198 == V_518 ) ) {
V_227 = 1280 ;
V_293 = 1024 ;
} else if ( V_198 == V_519 ) {
V_227 = 1400 ;
V_293 = 1050 ;
} else {
V_227 = 1600 ;
V_293 = 1200 ;
}
if ( V_3 -> V_47 & V_378 ) {
V_227 = V_3 -> V_367 ;
V_293 = V_3 -> V_369 ;
}
V_666 = V_227 ;
V_226 = V_3 -> V_515 ;
V_3 -> V_538 = V_677 -> V_538 ;
V_3 -> V_540 = V_677 -> V_540 ;
V_3 -> V_542 = V_677 -> V_542 ;
V_3 -> V_543 = V_677 -> V_543 ;
V_227 = V_3 -> V_542 ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x05 , V_163 ) ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x06 , V_163 ) ;
V_561 = ( ( V_293 & 0xFF00 ) >> 8 ) & 0x07 ;
V_622 = ( ( V_227 & 0xFF00 ) >> 8 ) & 0x07 ;
V_198 = V_561 ;
V_198 = V_198 << 3 ;
V_198 |= V_622 ;
F_5 ( V_3 -> V_565 , 0x02 , V_198 ) ;
F_44 ( & V_226 , & V_227 , V_3 ) ;
V_293 = V_227 ;
V_226 = V_3 -> V_515 ;
V_227 = V_3 -> V_543 ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x04 , V_163 ) ;
V_163 = ( V_227 & 0xFF00 ) >> 8 ;
V_163 = V_163 << 4 ;
V_163 |= ( V_293 & 0x000F ) ;
F_5 ( V_3 -> V_565 , 0x01 , V_163 ) ;
V_293 = V_666 ;
V_226 = V_3 -> V_513 ;
V_227 = V_3 -> V_538 ;
V_227 &= 0x0FFF ;
if ( F_69 ( V_3 ) ) {
V_226 = V_226 >> 1 ;
V_227 = V_227 >> 1 ;
V_293 = V_293 >> 1 ;
}
if ( V_3 -> V_147 & V_149 )
V_227 += 1 ;
if ( V_3 -> V_147 & V_235 )
V_227 += 1 ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x1F , V_163 ) ;
V_163 = ( ( V_227 & 0xFF00 ) >> 8 ) << 4 ;
F_5 ( V_3 -> V_565 , 0x20 , V_163 ) ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x23 , V_163 ) ;
V_163 = ( V_293 & 0xFF00 ) >> 8 ;
F_5 ( V_3 -> V_565 , 0x25 , V_163 ) ;
F_44 ( & V_226 , & V_227 , V_3 ) ;
V_293 = V_226 ;
V_226 = V_3 -> V_513 ;
V_227 = V_3 -> V_540 ;
if ( F_69 ( V_3 ) ) {
V_226 = V_226 >> 1 ;
V_227 = V_227 >> 1 ;
V_293 = V_293 >> 1 ;
}
if ( V_3 -> V_147 & V_149 )
V_227 += 1 ;
V_293 += V_227 ;
if ( V_293 >= V_226 )
V_293 -= V_226 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x1C , V_163 ) ;
V_163 = ( V_227 & 0xFF00 ) >> 8 ;
V_163 = V_163 << 4 ;
F_13 ( V_3 -> V_565 , 0x1D , ~ 0x0F0 , V_163 ) ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_565 , 0x21 , V_163 ) ;
if ( ! ( V_3 -> V_47 & V_613 ) ) {
if ( V_3 -> V_368 == 525 ) {
if ( V_3 -> V_147 & ( V_253 | V_254
| V_148 | V_149
| V_235 ) ) {
V_163 = 0xC6 ;
} else
V_163 = 0xC4 ;
F_5 ( V_3 -> V_565 , 0x2f , V_163 ) ;
F_5 ( V_3 -> V_565 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_368 == 420 ) {
if ( V_3 -> V_147 & ( V_253 | V_254
| V_148 | V_149
| V_235 ) ) {
V_163 = 0x4F ;
} else
V_163 = 0x4E ;
F_5 ( V_3 -> V_565 , 0x2f , V_163 ) ;
}
}
}
static struct V_678 * F_83 ( unsigned short V_293 ,
struct V_2 * V_3 )
{
unsigned short V_226 , V_227 , V_200 ;
struct V_678 * V_679 ;
if ( V_293 == 0 ) {
V_226 = V_3 -> V_366 ;
V_227 = V_3 -> V_367 ;
} else {
V_226 = V_3 -> V_368 ;
V_227 = V_3 -> V_369 ;
}
if ( V_226 <= V_227 )
return & V_680 [ 0 ] ;
else
V_679 = V_681 ;
if ( V_3 -> V_49 & V_256 )
V_679 = V_682 ;
if ( V_3 -> V_48 & V_251 ) {
if ( ( V_3 -> V_49 & V_600 ) ||
( V_3 -> V_49 & V_556 ) )
V_679 = V_681 ;
if ( V_3 -> V_49 & V_555 )
V_679 = V_683 ;
}
if ( V_3 -> V_48 & V_241 )
V_679 = V_680 ;
V_200 = 0 ;
while ( V_679 [ V_200 ] . V_684 != 0xFFFF ) {
if ( V_679 [ V_200 ] . V_684 == V_226 )
break;
V_200 ++ ;
}
return & V_679 [ V_200 ] ;
}
static void F_84 ( struct V_2 * V_3 )
{
unsigned short V_200 , V_266 ;
struct V_678 * V_679 ;
if ( ! ( V_3 -> V_147 & V_235 ) )
return;
V_679 = F_83 ( 0 , V_3 ) ;
for ( V_200 = 0x80 , V_266 = 0 ; V_200 <= 0xBF ; V_200 ++ , V_266 ++ )
F_5 ( V_3 -> V_565 , V_200 , V_679 -> V_523 [ V_266 ] ) ;
if ( ( V_3 -> V_48 & V_206 ) &&
( ! ( V_3 -> V_48 & V_241 ) ) ) {
V_679 = F_83 ( 1 , V_3 ) ;
for ( V_200 = 0xC0 , V_266 = 0 ; V_200 < 0xFF ; V_200 ++ , V_266 ++ )
F_5 ( V_3 -> V_565 ,
V_200 ,
V_679 -> V_523 [ V_266 ] ) ;
}
if ( ( V_3 -> V_48 & V_206 ) &&
( ! ( V_3 -> V_48 & V_241 ) ) )
F_13 ( V_3 -> V_565 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_13 ( V_3 -> V_565 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_85 ( unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_200 ;
unsigned char * V_374 ;
unsigned short V_201 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
F_5 ( V_3 -> V_685 , 0x00 , 0x00 ) ;
if ( V_3 -> V_49 & V_256 ) {
F_5 ( V_3 -> V_685 , 0x13 , 0xFA ) ;
F_5 ( V_3 -> V_685 , 0x14 , 0xC8 ) ;
} else {
F_5 ( V_3 -> V_685 , 0x13 , 0xF5 ) ;
F_5 ( V_3 -> V_685 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_48 & V_206 ) )
return;
if ( V_3 -> V_49 & V_596 ) {
F_5 ( V_3 -> V_685 , 0x13 , 0xFA ) ;
F_5 ( V_3 -> V_685 , 0x14 , 0xC8 ) ;
F_5 ( V_3 -> V_685 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_48 & V_241 ) || ( V_3 -> V_48
& V_251 ) ) {
if ( V_3 -> V_49 & V_600 )
return;
V_374 = V_3 -> V_128 ;
if ( V_3 -> V_246 & V_247 ) {
V_374 = V_3 -> V_130 ;
if ( ! ( V_201 & V_216 ) )
V_374 = V_3 -> V_132 ;
}
if ( V_3 -> V_49 & V_556 )
V_374 = V_3 -> V_134 ;
if ( V_3 -> V_49 & V_555 )
V_374 = V_3 -> V_136 ;
for ( V_200 = 0 ; V_200 <= 0x3E ; V_200 ++ )
F_5 ( V_3 -> V_685 , V_200 , V_374 [ V_200 ] ) ;
if ( V_3 -> V_147 & V_235 ) {
if ( V_3 -> V_49 & V_556 )
F_5 ( V_3 -> V_685 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_86 ( unsigned short V_192 , unsigned short V_193 ,
unsigned short V_225 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_226 , V_293 , V_227 , V_201 , V_163 , V_300 ;
unsigned long V_673 , V_672 , V_686 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
V_163 = V_3 -> V_636 ;
F_5 ( V_3 -> V_546 , 0x13 , V_163 ) ;
V_227 = V_3 -> V_635 ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_546 , 0x14 , V_163 ) ;
V_300 = ( ( V_227 & 0xFF00 ) >> 8 ) << 7 ;
V_293 = V_3 -> V_511 - 1 ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_546 , 0x16 , V_163 ) ;
V_163 = ( ( V_293 & 0xFF00 ) >> 8 ) << 3 ;
V_300 |= V_163 ;
V_293 = V_3 -> V_512 - 1 ;
if ( ! ( V_3 -> V_48 & V_206 ) )
V_293 -= 5 ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_546 , 0x17 , V_163 ) ;
V_163 = V_300 | ( ( V_293 & 0xFF00 ) >> 8 ) ;
F_5 ( V_3 -> V_546 , 0x15 , V_163 ) ;
F_21 ( V_3 -> V_546 , 0x0D , 0x08 ) ;
V_293 = V_3 -> V_48 ;
V_227 = V_3 -> V_366 ;
if ( V_201 & V_296 )
V_227 = V_227 >> 1 ;
if ( F_69 ( V_3 ) )
V_227 = V_227 >> 1 ;
if ( V_293 & V_241 ) {
V_163 = 0 ;
if ( V_227 <= 1024 )
V_163 = 0xA0 ;
if ( V_227 == 1280 )
V_163 = 0xC0 ;
} else if ( V_293 & V_206 ) {
V_163 = 0xA0 ;
if ( V_227 <= 800 )
V_163 = 0x80 ;
} else {
V_163 = 0x80 ;
if ( V_3 -> V_48 & V_207 ) {
V_163 = 0 ;
if ( V_227 > 800 )
V_163 = 0x60 ;
}
}
if ( V_3 -> V_49 & ( V_556 | V_555 ) ) {
V_163 = 0x00 ;
if ( V_3 -> V_366 == 1280 )
V_163 = 0x40 ;
if ( V_3 -> V_366 == 1024 )
V_163 = 0x20 ;
}
F_13 ( V_3 -> V_546 , 0x0E , ~ 0xEF , V_163 ) ;
V_673 = V_3 -> V_369 ;
if ( V_293 & V_241 ) {
if ( ! ( V_163 & 0xE000 ) )
V_227 = V_227 >> 1 ;
}
V_293 = V_3 -> V_641 ;
V_163 = V_293 & 0x00FF ;
F_5 ( V_3 -> V_546 , 0x18 , V_163 ) ;
V_672 = V_3 -> V_368 ;
V_293 |= 0x04000 ;
if ( V_672 <= V_673 ) {
V_293 = ( V_293 & ( ~ 0x4000 ) ) ;
V_672 = V_3 -> V_368 ;
} else {
V_672 -= V_673 ;
}
V_686 = ( V_672 * 256 * 1024 ) % V_673 ;
V_672 = ( V_672 * 256 * 1024 ) / V_673 ;
V_673 = V_672 ;
if ( V_686 != 0 )
V_673 ++ ;
V_163 = ( unsigned short ) ( V_673 & 0x000000FF ) ;
F_5 ( V_3 -> V_546 , 0x1B , V_163 ) ;
V_163 = ( unsigned short ) ( ( V_673 & 0x0000FF00 ) >> 8 ) ;
F_5 ( V_3 -> V_546 , 0x1A , V_163 ) ;
V_227 = ( unsigned short ) ( V_673 >> 16 ) ;
V_163 = V_227 & 0x00FF ;
V_163 = V_163 << 4 ;
V_163 |= ( ( V_293 & 0xFF00 ) >> 8 ) ;
F_5 ( V_3 -> V_546 , 0x19 , V_163 ) ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
V_163 = 0x0028 ;
F_5 ( V_3 -> V_546 , 0x1C , V_163 ) ;
V_226 = V_3 -> V_366 ;
if ( V_201 & V_296 )
V_226 = V_226 >> 1 ;
if ( F_69 ( V_3 ) )
V_226 = V_226 >> 1 ;
if ( V_3 -> V_48 & V_207 ) {
if ( V_226 > 800 )
V_226 -= 800 ;
} else {
if ( V_3 -> V_366 > 800 ) {
if ( V_3 -> V_366 == 1024 )
V_226 = ( V_226 * 25 / 32 ) - 1 ;
else
V_226 = ( V_226 * 20 / 32 ) - 1 ;
}
}
V_226 -= 1 ;
V_163 = ( V_226 & 0xFF00 ) >> 8 ;
V_163 = ( ( V_163 & 0x0003 ) << 4 ) ;
F_5 ( V_3 -> V_546 , 0x1E , V_163 ) ;
V_163 = ( V_226 & 0x00FF ) ;
F_5 ( V_3 -> V_546 , 0x1D , V_163 ) ;
if ( V_3 -> V_48 & ( V_206 | V_241 ) ) {
if ( V_3 -> V_366 > 800 )
F_21 ( V_3 -> V_546 , 0x1E , 0x08 ) ;
}
V_163 = 0x0036 ;
if ( V_3 -> V_48 & V_206 ) {
if ( ! ( V_3 -> V_49 & ( V_558
| V_556 | V_555
| V_603 ) ) ) {
V_163 |= 0x0001 ;
if ( ( V_3 -> V_48 & V_208 )
&& ( ! ( V_3 -> V_49
& V_247 ) ) )
V_163 &= ( ~ 0x0001 ) ;
}
}
F_13 ( V_3 -> V_546 , 0x1F , 0x00C0 , V_163 ) ;
V_227 = V_3 -> V_513 ;
if ( F_69 ( V_3 ) )
V_227 = V_227 >> 1 ;
V_227 = ( V_227 >> 1 ) - 2 ;
V_163 = ( ( V_227 & 0x0700 ) >> 8 ) << 3 ;
F_13 ( V_3 -> V_546 , 0x21 , 0x00C0 , V_163 ) ;
V_163 = V_227 & 0x00FF ;
F_5 ( V_3 -> V_546 , 0x22 , V_163 ) ;
}
if ( V_3 -> V_687 == 0 )
F_72 ( V_192 , V_193 , V_225 ,
V_3 ) ;
}
static void F_87 ( struct V_2 * V_3 )
{
F_13 ( V_3 -> V_180 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_88 ( unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_688 , V_689 ;
V_688 = V_3 -> V_690 ;
V_689 = V_3 -> V_690 + 1 ;
if ( V_3 -> V_196 == V_222 ) {
if ( ! ( V_3 -> V_48 & ( V_208 | V_691
| V_579 ) ) ) {
F_87 ( V_3 ) ;
}
}
return;
}
static void F_89 ( struct V_209 * V_210 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_212 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_90 ( struct V_209 * V_210 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_212 , 0x63 , 0xBF , 0x00 ) ;
}
static unsigned char F_91 ( struct V_625 * V_626 ,
unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_342 , V_365 , V_663 , V_201 , V_291 ;
V_291 = F_26 ( V_192 , V_193 , V_3 ) ;
if ( V_192 <= 0x13 ) {
V_342 = V_3 -> V_33 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_33 [ V_291 ] . V_295 ;
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
} else {
V_342 = V_3 -> V_36 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_36 [ V_291 ] . V_295 ;
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
}
if ( ! ( V_201 & V_216 ) ) {
V_342 /= 9 ;
V_342 *= 8 ;
}
if ( V_192 > 0x13 ) {
if ( ( V_192 > 0x13 ) && ( V_201 & V_296 ) )
V_342 *= 2 ;
if ( ( V_192 > 0x13 ) && ( V_201 & V_268 ) )
V_365 *= 2 ;
}
if ( V_342 > V_626 -> V_627 . V_692 )
return 0 ;
if ( V_365 > V_626 -> V_627 . V_693 )
return 0 ;
if ( V_192 > 0x13 ) {
if ( V_342 != V_626 -> V_627 . V_692 ||
V_365 != V_626 -> V_627 . V_693 ) {
V_663 = F_73 ( V_192 ,
V_193 ,
V_3 ) ;
if ( V_663 > 2 )
return 0 ;
}
}
return 1 ;
}
static void F_92 ( struct V_625 * V_626 ,
int V_279 ,
unsigned short V_192 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned char V_163 , V_694 ;
unsigned short V_342 , V_365 , V_201 , V_291 ;
unsigned short V_695 , V_696 , V_697 , V_698 , V_699 ;
unsigned short V_700 , V_701 , V_702 , V_703 , V_704 ;
unsigned short V_705 ;
V_163 = ( unsigned char ) ( ( V_626 -> V_627 . V_706 &
( V_707 << 8 ) ) >> 8 ) ;
V_163 &= V_707 ;
V_694 = ( unsigned char ) F_8 ( V_3 -> V_284 ) ;
F_9 ( ( V_694 & 0x3F ) | V_163 , V_3 -> V_262 ) ;
V_163 = V_626 -> V_627 . V_706 & V_707 ;
F_13 ( V_3 -> V_180 , 0x35 , ~ 0x80 , V_163 & 0x80 ) ;
F_13 ( V_3 -> V_180 , 0x30 , ~ 0x20 , ( V_163 & 0x40 ) >> 1 ) ;
if ( V_279 == V_162 )
F_23 ( V_3 ) ;
else
F_31 ( V_3 ) ;
V_291 = F_26 ( V_192 , V_193 , V_3 ) ;
if ( V_192 <= 0x13 ) {
V_342 = V_3 -> V_33 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_33 [ V_291 ] . V_295 ;
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
} else {
V_342 = V_3 -> V_36 [ V_291 ] . V_294 ;
V_365 = V_3 -> V_36 [ V_291 ] . V_295 ;
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
}
if ( ! ( V_201 & V_216 ) )
V_342 = V_342 * 8 / 9 ;
V_695 = V_626 -> V_627 . V_695 ;
V_696 = V_342 + ( V_626 -> V_627 . V_692 - V_342 ) / 2 ;
if ( ( V_192 <= 0x13 ) && ( V_201 & V_296 ) )
V_696 -= V_342 / 4 ;
if ( V_696 > V_695 )
V_696 -= V_695 ;
V_697 = V_696 + V_626 -> V_627 . V_708 ;
if ( V_697 > V_695 )
V_697 -= V_695 ;
V_698 = V_697 + V_626 -> V_627 . V_709 ;
if ( V_698 > V_695 )
V_698 -= V_695 ;
V_699 = V_696 + V_695 - V_626 -> V_627 . V_692 ;
V_700 = V_626 -> V_627 . V_700 ;
V_701 = V_365 + ( V_626 -> V_627 . V_693 - V_365 ) / 2 ;
if ( ( V_192 > 0x13 ) && ( V_201 & V_268 ) )
V_701 += V_365 / 2 ;
if ( V_701 > V_700 )
V_701 -= V_700 ;
V_702 = V_701 + V_626 -> V_627 . V_710 ;
if ( V_702 > V_700 )
V_702 -= V_700 ;
V_703 = V_702 + V_626 -> V_627 . V_711 ;
if ( V_703 > V_700 )
V_703 -= V_700 ;
V_704 = V_701 + V_700 - V_626 -> V_627 . V_693 ;
V_163 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x11 ) ;
F_5 ( V_3 -> V_212 , 0x11 , V_163 & 0x7f ) ;
if ( ! ( V_201 & V_216 ) )
F_21 ( V_3 -> V_180 , 0x1 , 0x1 ) ;
V_705 = ( V_695 >> 3 ) - 5 ;
F_13 ( V_3 -> V_180 , 0x0B , ~ 0x03 , ( V_705 & 0x300 ) >> 8 ) ;
F_5 ( V_3 -> V_212 , 0x0 , ( V_705 & 0xFF ) ) ;
V_705 = ( V_696 >> 3 ) - 1 ;
F_13 ( V_3 -> V_180 , 0x0B , ~ 0x30 , ( V_705 & 0x300 ) >> 4 ) ;
F_5 ( V_3 -> V_212 , 0x2 , ( V_705 & 0xFF ) ) ;
V_705 = ( V_699 >> 3 ) - 1 ;
F_13 ( V_3 -> V_180 , 0x0C , ~ 0x03 , ( V_705 & 0xC0 ) >> 6 ) ;
F_13 ( V_3 -> V_212 , 0x05 , ~ 0x80 , ( V_705 & 0x20 ) << 2 ) ;
F_13 ( V_3 -> V_212 , 0x03 , ~ 0x1F , V_705 & 0x1F ) ;
V_705 = ( V_697 >> 3 ) + 2 ;
F_13 ( V_3 -> V_180 , 0x0B , ~ 0xC0 , ( V_705 & 0x300 ) >> 2 ) ;
F_5 ( V_3 -> V_212 , 0x4 , ( V_705 & 0xFF ) ) ;
V_705 -- ;
F_13 ( V_3 -> V_180 , 0x2F , ~ 0x03 , ( V_705 & 0x300 ) >> 8 ) ;
F_5 ( V_3 -> V_180 , 0x2E , ( V_705 & 0xFF ) ) ;
V_705 = ( V_698 >> 3 ) + 2 ;
F_13 ( V_3 -> V_180 , 0x0C , ~ 0x04 , ( V_705 & 0x20 ) >> 3 ) ;
F_13 ( V_3 -> V_212 , 0x05 , ~ 0x1F , V_705 & 0x1F ) ;
V_705 -- ;
F_13 ( V_3 -> V_180 , 0x2F , ~ 0xFC , V_705 << 2 ) ;
V_705 = V_700 - 2 ;
F_13 ( V_3 -> V_180 , 0x0A , ~ 0x01 , ( V_705 & 0x400 ) >> 10 ) ;
F_13 ( V_3 -> V_212 , 0x07 , ~ 0x20 , ( V_705 & 0x200 ) >> 4 ) ;
F_13 ( V_3 -> V_212 , 0x07 , ~ 0x01 , ( V_705 & 0x100 ) >> 8 ) ;
F_5 ( V_3 -> V_212 , 0x06 , ( V_705 & 0xFF ) ) ;
V_705 = V_701 - 1 ;
F_13 ( V_3 -> V_180 , 0x0A , ~ 0x04 , ( V_705 & 0x400 ) >> 8 ) ;
F_13 ( V_3 -> V_212 , 0x09 , ~ 0x20 , ( V_705 & 0x200 ) >> 4 ) ;
F_13 ( V_3 -> V_212 , 0x07 , ~ 0x08 , ( V_705 & 0x100 ) >> 5 ) ;
F_5 ( V_3 -> V_212 , 0x15 , ( V_705 & 0xFF ) ) ;
V_705 = V_704 - 1 ;
F_13 ( V_3 -> V_180 , 0x0A , ~ 0x10 , ( V_705 & 0x100 ) >> 4 ) ;
F_5 ( V_3 -> V_212 , 0x16 , ( V_705 & 0xFF ) ) ;
V_705 = V_702 - 1 ;
F_13 ( V_3 -> V_180 , 0x0A , ~ 0x08 , ( V_705 & 0x400 ) >> 7 ) ;
F_13 ( V_3 -> V_212 , 0x07 , ~ 0x80 , ( V_705 & 0x200 ) >> 2 ) ;
F_13 ( V_3 -> V_212 , 0x07 , ~ 0x04 , ( V_705 & 0x100 ) >> 6 ) ;
F_5 ( V_3 -> V_212 , 0x10 , ( V_705 & 0xFF ) ) ;
if ( V_279 == V_162 ) {
F_13 ( V_3 -> V_180 , 0x35 , ~ 0x07 ,
( V_705 & 0x700 ) >> 8 ) ;
F_5 ( V_3 -> V_180 , 0x34 , V_705 & 0xFF ) ;
} else {
F_13 ( V_3 -> V_180 , 0x3F , ~ 0x03 ,
( V_705 & 0x600 ) >> 9 ) ;
F_5 ( V_3 -> V_180 , 0x34 , ( V_705 >> 1 ) & 0xFF ) ;
F_13 ( V_3 -> V_212 , 0x33 , ~ 0x01 , V_705 & 0x01 ) ;
}
V_705 = V_703 - 1 ;
F_13 ( V_3 -> V_180 , 0x0A , ~ 0x20 , ( V_705 & 0x10 ) << 1 ) ;
F_13 ( V_3 -> V_212 , 0x11 , ~ 0x0F , V_705 & 0x0F ) ;
if ( V_279 == V_162 )
F_13 ( V_3 -> V_180 , 0x3F , ~ 0xFC ,
( V_705 << 2 ) & 0xFC ) ;
else
F_13 ( V_3 -> V_180 , 0x3F , ~ 0xFC ,
( V_705 << 2 ) & 0x7C ) ;
for ( V_163 = 0 , V_705 = 0 ; V_163 < 3 ; V_163 ++ ) {
F_13 ( V_3 -> V_180 , 0x31 , ~ 0x30 , V_705 ) ;
F_5 ( V_3 -> V_180 ,
0x2B , V_626 -> V_627 . V_712 ) ;
F_5 ( V_3 -> V_180 ,
0x2C , V_626 -> V_627 . V_713 ) ;
V_705 += 0x10 ;
}
if ( ! ( V_201 & V_216 ) ) {
F_8 ( V_3 -> V_217 ) ;
F_9 ( 0x13 , V_3 -> V_218 ) ;
F_9 ( 0x00 , V_3 -> V_218 ) ;
F_8 ( V_3 -> V_217 ) ;
F_9 ( 0x20 , V_3 -> V_218 ) ;
F_8 ( V_3 -> V_217 ) ;
}
}
static unsigned char F_93 ( struct V_2 * V_3 )
{
unsigned short V_226 ;
V_226 = V_3 -> V_48 ;
if ( V_226 & V_578 )
return 0 ;
else if ( V_226 & ( V_579 | V_590 | V_589 ) )
return 1 ;
return 0 ;
}
static unsigned char F_94 ( struct V_2 * V_3 )
{
unsigned short V_227 , V_198 ;
V_227 = V_3 -> V_246 & ( V_714 | V_715 ) ;
V_198 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_539 , 0x2E ) ) ;
if ( V_227 & ( V_716 | V_714 ) ) {
if ( ! ( V_198 & 0x08 ) )
return 0 ;
}
if ( ! ( V_227 & ( V_717 | V_715 ) ) )
return 0 ;
if ( V_198 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_95 ( struct V_2 * V_3 )
{
unsigned short V_227 , V_198 ;
V_227 = V_3 -> V_246 & ( V_716 | V_717 ) ;
V_198 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_539 , 0x2E ) ) ;
if ( V_227 & ( V_716 | V_714 ) ) {
if ( ! ( V_198 & 0x08 ) )
return 0 ;
}
if ( ! ( V_227 & ( V_717 | V_715 ) ) )
return 0 ;
if ( V_198 & 0x01 )
return 1 ;
return 0 ;
}
static void F_96 ( struct V_625 * V_626 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_198 = 0 ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
V_198 = 0x3F ;
if ( ! ( V_3 -> V_48 &
( V_579 | V_589 ) ) ) {
if ( V_3 -> V_48 & V_205 ) {
if ( V_3 -> V_48 & V_578 ) {
V_198 = 0x7F ;
if ( ! ( V_3 -> V_48 & V_205 ) )
V_198 = 0xBF ;
if ( V_3 -> V_246 & V_715 )
V_198 &= 0xBF ;
if ( V_3 -> V_246 & V_714 )
V_198 &= 0x7F ;
}
}
}
F_14 ( V_3 -> V_546 , 0x1F , V_198 ) ;
if ( V_3 -> V_147 & ( V_149 | V_235 ) ) {
if ( ( ( V_3 -> V_48 & ( V_207 | V_205 ) ) )
|| ( F_94 ( V_3 ) )
|| ( F_93 ( V_3 ) ) )
F_21 ( V_3 -> V_546 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_246 & V_714 ) || ( V_3 -> V_48
& ( V_579 | V_205
| V_589 ) ) ) {
if ( V_3 -> V_246 & V_718 )
F_89 ( V_210 , V_3 ) ;
F_64 ( V_626 , V_210 , V_3 ) ;
}
if ( V_3 -> V_48 & V_205 ) {
if ( ( V_3 -> V_246 & V_714 ) || ( V_3 -> V_48
& V_205 ) )
F_14 ( V_3 -> V_539 , 0x1e , 0xdf ) ;
}
F_14 ( V_3 -> V_180 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_48 & ( V_589 | V_578 ) ) )
F_14 ( V_3 -> V_565 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_246 & V_715 ) ||
( V_3 -> V_48 &
( V_579 | V_589 ) ) ||
( ( ! ( V_3 -> V_48 & V_205 ) ) &&
( V_3 -> V_48 &
( V_233 | V_207 | V_206 ) ) ) )
F_21 ( V_3 -> V_539 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_246 & V_715 ) ||
( V_3 -> V_48 &
( V_579 | V_589 ) ) ||
( ! ( V_3 -> V_48 & V_205 ) ) ||
( V_3 -> V_48 &
( V_233 | V_207 | V_206 ) ) ) {
V_198 = F_2 ( V_3 -> V_539 , 0x00 ) ;
F_21 ( V_3 -> V_539 , 0x00 , 0x10 ) ;
F_14 ( V_3 -> V_539 , 0x1E , 0xDF ) ;
F_5 ( V_3 -> V_539 , 0x00 , V_198 ) ;
}
} else {
if ( V_3 -> V_48 & ( V_207 | V_206 ) ) {
F_21 ( V_3 -> V_539 , 0x00 , 0x80 ) ;
F_14 ( V_3 -> V_539 , 0x1E , 0xDF ) ;
F_14 ( V_3 -> V_180 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_48 & ( V_579 | V_205
| V_589 ) )
F_64 ( V_626 , V_210 , V_3 ) ;
}
}
static unsigned short F_97 ( struct V_2 * V_3 )
{
unsigned short V_227 = 0 ;
if ( V_3 -> V_49 & V_256 )
V_227 = 2 ;
if ( V_3 -> V_49 & V_603 )
V_227 = 4 ;
if ( V_3 -> V_49 & V_600 )
V_227 = 6 ;
if ( V_3 -> V_49 & V_556 )
V_227 = 8 ;
if ( V_3 -> V_49 & V_555 )
V_227 = 10 ;
if ( V_3 -> V_49 & V_247 )
V_227 ++ ;
return V_227 ;
}
static void F_98 ( unsigned short * V_227 , unsigned char * V_560 ,
unsigned char * V_561 , struct V_2 * V_3 )
{
* V_227 = 0 ;
* V_560 = 0 ;
* V_561 = 0 ;
if ( V_3 -> V_49 & V_256 )
* V_227 = 1 ;
if ( V_3 -> V_49 & V_596 )
* V_227 = 2 ;
if ( V_3 -> V_49 & V_597 )
* V_227 = 3 ;
if ( V_3 -> V_49 & V_558 ) {
* V_227 = 4 ;
if ( V_3 -> V_49 & V_596 )
* V_227 = 5 ;
}
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
if ( ( ! ( V_3 -> V_48 & V_208 ) ) || ( V_3 -> V_49
& V_247 ) ) {
* V_227 += 8 ;
* V_560 += 1 ;
}
}
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) )
( * V_561 ) ++ ;
}
static void F_99 ( struct V_2 * V_3 )
{
unsigned short V_194 ;
unsigned char V_198 , V_524 , V_622 ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
if ( V_3 -> V_48 & ( V_207 | V_205
| V_206 | V_233 ) ) {
V_524 = 0 ;
V_622 = 0 ;
V_194 = F_97 ( V_3 ) ;
V_524 = V_3 -> V_153 [ V_194 ] ;
if ( V_3 -> V_147 & ( V_253 | V_254
| V_148 | V_149
| V_235 ) )
V_524 = V_3 -> V_155 [ V_194 ] ;
if ( V_3 -> V_48 & V_578 )
V_524 = V_524 >> 4 ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
V_194 = F_42 ( V_3 ) ;
V_622 = V_3 -> V_150 [ V_194 ] .
V_719 ;
if ( ! ( V_3 -> V_48 & V_205 ) )
V_524 = V_622 ;
}
V_524 &= 0x0F ;
V_622 &= 0xF0 ;
V_198 = F_2 ( V_3 -> V_539 , 0x2D ) ;
if ( V_3 -> V_48 & ( V_233 | V_207
| V_206 ) ) {
V_198 &= 0xF0 ;
V_198 |= V_524 ;
}
if ( V_3 -> V_48 & V_205 ) {
V_198 &= 0x0F ;
V_198 |= V_622 ;
}
F_5 ( V_3 -> V_539 , 0x2D , V_198 ) ;
}
} else if ( V_3 -> V_232 == 1 ) {
V_524 = 0 ;
V_622 = 0 ;
if ( V_3 -> V_48 & V_207 ) {
V_198 = V_3 -> V_150 [
F_42 ( V_3 ) ] .
V_719 ;
V_198 &= 0x0f ;
V_198 = V_198 << 4 ;
F_13 ( V_3 -> V_539 , 0x2D , 0x0f ,
V_198 ) ;
}
}
}
static void F_100 ( unsigned short V_293 ,
struct V_2 * V_3 )
{
unsigned short V_163 ;
V_163 = F_2 ( V_3 -> V_212 , 0x37 ) ;
if ( V_163 & V_668 ) {
F_13 ( V_3 -> V_539 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_293 & 0x00C0 ) ) ) ;
F_13 ( V_3 -> V_539 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_13 ( V_3 -> V_539 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_293 & 0x00C0 ) ) ) ;
F_13 ( V_3 -> V_539 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_101 ( unsigned short V_293 ,
struct V_2 * V_3 )
{
if ( V_293 & V_720 )
F_13 ( V_3 -> V_565 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_293 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_13 ( V_3 -> V_565 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_293 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
unsigned short V_200 ;
V_200 = F_2 ( V_3 -> V_180 , 0x1F ) ;
if ( ! ( V_200 & 0xC0 ) ) {
for ( V_200 = 0 ; V_200 < 0xFFFF ; V_200 ++ ) {
if ( ! ( F_8 ( V_3 -> V_217 ) & 0x08 ) )
break;
}
for ( V_200 = 0 ; V_200 < 0xFFFF ; V_200 ++ ) {
if ( ( F_8 ( V_3 -> V_217 ) & 0x08 ) )
break;
}
}
}
static void F_103 ( struct V_2 * V_3 )
{
unsigned short V_194 ;
V_194 = F_42 ( V_3 ) ;
F_14 ( V_3 -> V_546 , 0x30 , 0x8F ) ;
F_102 ( V_3 ) ;
F_21 ( V_3 -> V_546 , 0x30 , 0x20 ) ;
F_102 ( V_3 ) ;
F_5 ( V_3 -> V_546 , 0x31 ,
V_3 -> V_150 [ V_194 ] . V_721 ) ;
F_5 ( V_3 -> V_546 , 0x32 ,
V_3 -> V_150 [ V_194 ] . V_722 ) ;
F_5 ( V_3 -> V_546 , 0x33 ,
V_3 -> V_150 [ V_194 ] . V_723 ) ;
F_5 ( V_3 -> V_546 , 0x34 ,
V_3 -> V_150 [ V_194 ] . V_724 ) ;
F_102 ( V_3 ) ;
F_21 ( V_3 -> V_546 , 0x30 , 0x40 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
unsigned short V_293 ;
V_293 = V_3 -> V_150 [ F_42 ( V_3 ) ] . V_609 ;
if ( V_3 -> V_147 &
( V_253 |
V_254 |
V_148 |
V_149 |
V_235 ) ) {
if ( V_3 -> V_147 &
( V_148 | V_149 | V_235 ) ) {
F_5 ( V_3 -> V_546 , 0x24 ,
( unsigned char ) ( V_293 & 0x1F ) ) ;
}
F_13 ( V_3 -> V_546 , 0x0D ,
~ ( ( V_725 | V_726 ) >> 8 ) ,
( unsigned short ) ( ( V_293 & ( V_725
| V_726 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
if ( V_3 -> V_48 & V_207 )
F_101 ( V_293 , V_3 ) ;
else if ( V_3 -> V_48 & V_205 )
F_100 ( V_293 , V_3 ) ;
if ( V_3 -> V_147 & ( V_149 | V_235 ) ) {
if ( V_293 & V_727 )
F_103 ( V_3 ) ;
}
} else {
F_100 ( V_293 , V_3 ) ;
}
}
static void F_105 ( unsigned short V_192 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_227 , V_194 ;
unsigned char V_198 ;
if ( V_3 -> V_49 & ( V_556 | V_555 ) )
return;
V_227 = F_97 ( V_3 ) ;
V_227 &= 0xFE ;
if ( V_192 <= 0x13 )
V_194 = V_3 -> V_4 [ V_193 ] . V_728 ;
else
V_194 = V_3 -> V_10 [ V_193 ] . V_729 ;
V_227 += V_194 ;
V_198 = V_730 [ V_227 ] ;
V_198 = V_198 << 4 ;
F_13 ( V_3 -> V_565 , 0x0A , 0x8F , V_198 ) ;
}
static void F_106 ( unsigned short V_192 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_227 , V_194 ;
unsigned char V_198 ;
V_227 = F_97 ( V_3 ) ;
V_227 &= 0xFE ;
if ( V_192 <= 0x13 )
V_194 = V_3 -> V_4 [ V_193 ] . V_731 ;
else
V_194 = V_3 -> V_10 [ V_193 ] . V_732 ;
V_227 += V_194 ;
V_198 = V_733 [ V_227 ] ;
V_198 = V_198 << 5 ;
F_13 ( V_3 -> V_565 , 0x3A , 0x1F , V_198 ) ;
}
static void F_107 ( struct V_2 * V_3 )
{
unsigned short V_227 ;
unsigned char V_560 , V_561 ;
unsigned long V_734 ;
F_98 ( & V_227 , & V_560 , & V_561 , V_3 ) ;
V_734 = V_735 [ V_227 ] ;
F_5 ( V_3 -> V_565 , 0x31 , ( unsigned short ) ( V_734
& 0x000000FF ) ) ;
F_5 ( V_3 -> V_565 , 0x32 , ( unsigned short ) ( ( V_734
& 0x0000FF00 ) >> 8 ) ) ;
F_5 ( V_3 -> V_565 , 0x33 , ( unsigned short ) ( ( V_734
& 0x00FF0000 ) >> 16 ) ) ;
F_5 ( V_3 -> V_565 , 0x34 , ( unsigned short ) ( ( V_734
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_108 ( unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_227 , V_194 ;
unsigned char V_560 , V_561 , V_372 , * V_736 ;
F_98 ( & V_227 , & V_560 , & V_561 , V_3 ) ;
switch ( V_227 ) {
case 0x00 :
case 0x04 :
V_736 = V_737 ;
break;
case 0x01 :
V_736 = V_738 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_736 = V_739 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_736 = V_740 ;
break;
default:
return;
}
if ( V_192 <= 0x13 )
V_372 = V_3 -> V_4 [ V_193 ] .
V_741 ;
else
V_372 = V_3 -> V_10 [ V_193 ] .
V_742 ;
if ( V_560 == 0 )
V_194 = V_372 * 4 ;
else
V_194 = V_372 * 7 ;
if ( ( V_560 == 0 ) && ( V_561 == 1 ) ) {
F_5 ( V_3 -> V_565 , 0x35 , 0 ) ;
F_5 ( V_3 -> V_565 , 0x36 , 0 ) ;
F_5 ( V_3 -> V_565 , 0x37 , 0 ) ;
F_5 ( V_3 -> V_565 , 0x38 , V_736 [ V_194 ++ ] ) ;
} else {
F_5 ( V_3 -> V_565 , 0x35 , V_736 [ V_194 ++ ] ) ;
F_5 ( V_3 -> V_565 , 0x36 , V_736 [ V_194 ++ ] ) ;
F_5 ( V_3 -> V_565 , 0x37 , V_736 [ V_194 ++ ] ) ;
F_5 ( V_3 -> V_565 , 0x38 , V_736 [ V_194 ++ ] ) ;
}
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
F_5 ( V_3 -> V_565 , 0x48 , V_736 [ V_194 ++ ] ) ;
F_5 ( V_3 -> V_565 , 0x49 , V_736 [ V_194 ++ ] ) ;
F_5 ( V_3 -> V_565 , 0x4A , V_736 [ V_194 ++ ] ) ;
}
}
static void F_109 ( unsigned short V_192 ,
unsigned short V_193 ,
struct V_2 * V_3 )
{
F_99 ( V_3 ) ;
if ( V_3 -> V_48 & ( V_207 | V_205 ) )
F_104 ( V_3 ) ;
if ( V_3 -> V_48 & V_206 ) {
F_107 ( V_3 ) ;
F_108 ( V_192 , V_193 , V_3 ) ;
F_105 ( V_192 , V_193 , V_3 ) ;
if ( V_3 -> V_147 & V_559 )
F_106 ( V_192 , V_193 , V_3 ) ;
}
}
static void F_110 ( unsigned short V_192 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_524 ;
short V_560 ;
unsigned char V_198 ;
V_198 = 0 ;
if ( ! ( V_3 -> V_48 & V_579 ) ) {
V_198 = F_2 ( V_3 -> V_539 , 0x00 ) ;
V_198 &= ~ 0x10 ;
V_198 |= 0x40 ;
if ( V_3 -> V_48 & ( V_233 | V_206
| V_207 ) ) {
V_198 = 0x40 ;
if ( V_192 > 0x13 ) {
V_560 = V_3 -> V_196 ;
V_560 -= V_222 ;
if ( V_560 >= 0 ) {
V_198 = ( 0x008 >> V_560 ) ;
if ( V_198 == 0 )
V_198 = 1 ;
V_198 |= 0x040 ;
}
}
if ( V_3 -> V_48 & V_208 )
V_198 ^= 0x50 ;
}
}
F_5 ( V_3 -> V_539 , 0x00 , V_198 ) ;
V_198 = 0x08 ;
V_524 = 0xf0 ;
if ( V_3 -> V_48 & V_579 ) {
F_13 ( V_3 -> V_539 , 0x2e , V_524 , V_198 ) ;
} else {
V_198 = 0x00 ;
V_524 = 0xff ;
if ( V_3 -> V_48 & ( V_233 | V_206
| V_207 | V_205 ) ) {
if ( ( V_3 -> V_48 & V_205 ) &&
( ! ( V_3 -> V_48 & V_589 ) ) ) {
V_524 &= 0xf7 ;
V_198 |= 0x01 ;
F_13 ( V_3 -> V_539 , 0x2e ,
V_524 , V_198 ) ;
} else {
if ( V_3 -> V_48 & V_205 ) {
V_524 &= 0xf7 ;
V_198 |= 0x01 ;
}
if ( V_3 -> V_48 &
( V_233 |
V_206 |
V_207 ) ) {
V_524 &= 0xf8 ;
V_198 = 0x01 ;
if ( ! ( V_3 -> V_48 & V_208 ) )
V_198 |= 0x02 ;
if ( ! ( V_3 -> V_48 &
V_233 ) ) {
V_198 = V_198 ^ 0x05 ;
if ( ! ( V_3 -> V_48 &
V_207 ) )
V_198 = V_198 ^ 0x01 ;
}
if ( ! ( V_3 -> V_48 &
V_578 ) )
V_198 |= 0x08 ;
F_13 ( V_3 -> V_539 ,
0x2e , V_524 , V_198 ) ;
} else {
F_13 ( V_3 -> V_539 ,
0x2e , V_524 , V_198 ) ;
}
}
} else {
F_13 ( V_3 -> V_539 , 0x2e , V_524 ,
V_198 ) ;
}
}
if ( V_3 -> V_48 & ( V_233 | V_206 | V_207
| V_205 ) ) {
V_198 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_196 == V_222 ) && ( ! ( V_3 -> V_48
& V_208 ) ) ) {
V_198 |= 0x010 ;
}
V_198 |= 0x080 ;
if ( V_3 -> V_48 & V_206 ) {
V_198 |= 0x020 ;
if ( V_192 > 0x13 ) {
if ( V_3 -> V_48 & V_592 )
V_198 = V_198 ^ 0x20 ;
}
}
F_13 ( V_3 -> V_546 , 0x0D , ~ 0x0BF , V_198 ) ;
V_198 = 0 ;
if ( V_3 -> V_47 & V_611 )
V_198 |= 0x40 ;
if ( V_3 -> V_48 & V_206 ) {
if ( V_3 -> V_49 & V_316 )
V_198 |= 0x40 ;
}
if ( ( V_3 -> V_45 == V_238 )
|| ( V_3 -> V_45 == V_518 ) )
V_198 |= 0x80 ;
if ( V_3 -> V_45 == V_239 )
V_198 |= 0x80 ;
F_5 ( V_3 -> V_546 , 0x0C , V_198 ) ;
}
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
V_198 = 0 ;
V_524 = 0xfb ;
if ( V_3 -> V_48 & V_578 ) {
V_524 = 0xff ;
if ( V_3 -> V_48 & V_205 )
V_198 |= 0x04 ;
}
F_13 ( V_3 -> V_539 , 0x13 , V_524 , V_198 ) ;
V_198 = 0x00 ;
V_524 = 0xcf ;
if ( ! ( V_3 -> V_48 & V_579 ) ) {
if ( V_3 -> V_48 & V_578 )
V_198 |= 0x30 ;
}
F_13 ( V_3 -> V_539 , 0x2c , V_524 , V_198 ) ;
V_198 = 0 ;
V_524 = 0x3f ;
if ( ! ( V_3 -> V_48 & V_579 ) ) {
if ( V_3 -> V_48 & V_578 )
V_198 |= 0xc0 ;
}
F_13 ( V_3 -> V_546 , 0x21 , V_524 , V_198 ) ;
}
V_198 = 0 ;
V_524 = 0x7f ;
if ( ! ( V_3 -> V_48 & V_205 ) ) {
V_524 = 0xff ;
if ( ! ( V_3 -> V_48 & V_578 ) )
V_198 |= 0x80 ;
}
F_13 ( V_3 -> V_546 , 0x23 , V_524 , V_198 ) ;
if ( V_3 -> V_147 & ( V_149 | V_235 ) ) {
if ( V_3 -> V_47 & V_611 ) {
F_21 ( V_3 -> V_546 , 0x27 , 0x20 ) ;
F_21 ( V_3 -> V_546 , 0x34 , 0x10 ) ;
}
}
}
static void F_111 ( struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_227 ;
V_227 = 0 ;
if ( V_3 -> V_48 & V_205 )
V_227 = 0x08A0 ;
}
void F_112 ( struct V_209 * V_210 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_539 , 0x2f , 0xFF , 0x01 ) ;
}
void F_113 ( struct V_209 * V_210 ,
struct V_2 * V_3 )
{
F_13 ( V_3 -> V_539 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_114 ( struct V_2 * V_3 )
{
unsigned short V_574 ;
if ( V_3 -> V_232 == 1 ) {
return 1 ;
} else {
V_574 = F_2 ( V_3 -> V_546 , 0x00 ) ;
if ( ( V_574 == 1 ) || ( V_574 == 2 ) )
return 1 ;
else
return 0 ;
}
}
unsigned short F_115 ( struct V_209 * V_632 ,
unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
short V_743 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_744 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_225 , V_200 , V_201 , V_194 , V_163 ;
if ( V_192 <= 0x13 )
V_201 = V_3 -> V_4 [ V_193 ] . V_202 ;
else
V_201 = V_3 -> V_10 [ V_193 ] . V_203 ;
if ( V_192 < 0x14 )
return 0xFFFF ;
V_194 = F_2 ( V_3 -> V_212 , 0x33 ) ;
V_194 = V_194 >> V_3 -> V_745 ;
V_194 &= 0x0F ;
if ( V_3 -> V_47 & V_240 )
V_194 = 0 ;
if ( V_194 > 0 )
V_194 -- ;
if ( V_3 -> V_246 & V_553 ) {
if ( V_3 -> V_48 & ( V_207 | V_205 ) ) {
if ( V_3 -> V_232 == 0 ) {
if ( V_3 -> V_147 & ( V_253 | V_254
| V_148 | V_149
| V_235 ) )
V_163 = V_744 [
V_3 -> V_45 & 0x0F ] ;
else
V_163 = V_743 [
V_3 -> V_45 & 0x0F ] ;
if ( V_194 > V_163 )
V_194 = V_163 ;
} else {
V_194 = 0 ;
}
}
}
V_225 = V_3 -> V_10 [ V_193 ] . V_746 ;
V_192 = V_3 -> V_13 [ V_225 ] . V_231 ;
if ( V_632 -> V_267 >= V_159 ) {
if ( ( V_3 -> V_13 [ V_225 ] . V_747 == 800 ) &&
( V_3 -> V_13 [ V_225 ] . V_748 == 600 ) ) {
V_194 ++ ;
}
if ( ( V_3 -> V_13 [ V_225 ] . V_747 == 1024 ) &&
( V_3 -> V_13 [ V_225 ] . V_748 == 768 ) ) {
V_194 ++ ;
}
if ( ( V_3 -> V_13 [ V_225 ] . V_747 == 1280 ) &&
( V_3 -> V_13 [ V_225 ] . V_748 == 1024 ) ) {
V_194 ++ ;
}
}
V_200 = 0 ;
do {
if ( V_3 -> V_13 [ V_225 + V_200 ] .
V_231 != V_192 )
break;
V_163 = V_3 -> V_13 [ V_225 + V_200 ] .
V_260 ;
V_163 &= V_577 ;
if ( V_163 < V_3 -> V_196 )
break;
V_200 ++ ;
V_194 -- ;
} while ( V_194 != 0xFFFF );
if ( ! ( V_3 -> V_48 & V_233 ) ) {
if ( V_3 -> V_48 & V_208 ) {
V_163 = V_3 -> V_13 [ V_225 + V_200 - 1 ] .
V_260 ;
if ( V_163 & V_297 )
V_200 ++ ;
}
}
V_200 -- ;
if ( ( V_3 -> V_246 & V_553 ) ) {
V_163 = F_15 ( V_192 , V_193 ,
V_225 , & V_200 , V_3 ) ;
}
return V_225 + V_200 ;
}
static void F_116 ( unsigned short V_192 , unsigned short V_193 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_225 ;
V_3 -> V_246 |= V_553 ;
V_225 = F_115 ( V_210 , V_192 ,
V_193 , V_3 ) ;
F_37 ( V_192 , V_193 , V_3 ) ;
F_40 ( V_192 , V_193 , V_225 , V_3 ) ;
F_41 ( V_192 , V_193 , V_225 ,
V_210 , V_3 ) ;
F_45 ( V_192 , V_193 , V_225 , V_3 ) ;
F_49 ( V_192 , V_193 , V_225 , V_3 ) ;
}
static unsigned char F_117 ( unsigned short V_192 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_227 , V_193 , V_225 ;
V_227 = V_3 -> V_48 ;
V_3 -> V_246 |= V_553 ;
F_55 ( V_192 , & V_193 , V_3 ) ;
V_3 -> V_745 = 4 ;
V_225 = F_115 ( V_210 , V_192 ,
V_193 , V_3 ) ;
F_67 ( V_192 , V_3 ) ;
F_68 ( V_192 , V_193 , V_3 ) ;
F_71 ( V_192 , V_193 , V_225 , V_3 ) ;
F_77 ( V_192 , V_193 , V_210 ,
V_225 , V_3 ) ;
F_78 ( V_192 , V_193 , V_210 ,
V_225 , V_3 ) ;
F_80 ( V_192 , V_193 , V_210 ,
V_225 , V_3 ) ;
F_81 ( V_192 , V_193 , V_225 ,
V_210 , V_3 ) ;
F_82 ( V_192 , V_193 , V_210 ,
V_225 , V_3 ) ;
F_84 ( V_3 ) ;
F_85 ( V_192 , V_193 , V_3 ) ;
F_86 ( V_192 , V_193 , V_225 ,
V_210 , V_3 ) ;
F_72 ( V_192 , V_193 , V_225 , V_3 ) ;
F_88 ( V_192 , V_193 , V_3 ) ;
F_66 ( V_3 ) ;
return 1 ;
}
void F_118 ( struct V_2 * V_3 )
{
unsigned char V_749 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_750 = 0 , V_751 = 0 , V_752 = 0 , V_753 = 0 ;
unsigned char V_754 , V_755 , V_756 ;
unsigned short V_163 ;
unsigned char V_757 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_200 ;
F_5 ( V_3 -> V_180 , 0x05 , 0x86 ) ;
F_5 ( V_3 -> V_212 , 0x57 , 0x4A ) ;
F_5 ( V_3 -> V_212 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_212 , 0x53 ) | 0x02 ) ) ;
V_756 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x31 ) ;
V_755 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x63 ) ;
V_750 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x01 ) ;
F_5 ( V_3 -> V_180 , 0x01 , ( unsigned char ) ( V_750 & 0xDF ) ) ;
F_5 ( V_3 -> V_212 , 0x63 , ( unsigned char ) ( V_755 & 0xBF ) ) ;
V_754 = ( unsigned char ) F_2 ( V_3 -> V_212 , 0x17 ) ;
F_5 ( V_3 -> V_212 , 0x17 , ( unsigned char ) ( V_754 | 0x80 ) ) ;
V_751 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x1F ) ;
F_5 ( V_3 -> V_180 , 0x1F , ( unsigned char ) ( V_751 | 0x04 ) ) ;
V_752 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x07 ) ;
F_5 ( V_3 -> V_180 , 0x07 , ( unsigned char ) ( V_752 & 0xFB ) ) ;
V_753 = ( unsigned char ) F_2 ( V_3 -> V_180 , 0x06 ) ;
F_5 ( V_3 -> V_180 , 0x06 , ( unsigned char ) ( V_753 & 0xC3 ) ) ;
F_5 ( V_3 -> V_212 , 0x11 , 0x00 ) ;
for ( V_200 = 0 ; V_200 < 8 ; V_200 ++ )
F_5 ( V_3 -> V_212 , ( unsigned short ) V_200 , V_749 [ V_200 ] ) ;
for ( V_200 = 8 ; V_200 < 11 ; V_200 ++ )
F_5 ( V_3 -> V_212 , ( unsigned short ) ( V_200 + 8 ) ,
V_749 [ V_200 ] ) ;
for ( V_200 = 11 ; V_200 < 13 ; V_200 ++ )
F_5 ( V_3 -> V_212 , ( unsigned short ) ( V_200 + 4 ) ,
V_749 [ V_200 ] ) ;
for ( V_200 = 13 ; V_200 < 16 ; V_200 ++ )
F_5 ( V_3 -> V_180 , ( unsigned short ) ( V_200 - 3 ) ,
V_749 [ V_200 ] ) ;
F_5 ( V_3 -> V_180 , 0x0E , ( unsigned char ) ( V_749 [ 16 ]
& 0xE0 ) ) ;
F_5 ( V_3 -> V_180 , 0x31 , 0x00 ) ;
F_5 ( V_3 -> V_180 , 0x2B , 0x1B ) ;
F_5 ( V_3 -> V_180 , 0x2C , 0xE1 ) ;
F_9 ( 0x00 , V_3 -> V_364 ) ;
for ( V_200 = 0 ; V_200 < 256 ; V_200 ++ ) {
F_9 ( ( unsigned char ) V_757 [ 0 ] , ( V_3 -> V_364 + 1 ) ) ;
F_9 ( ( unsigned char ) V_757 [ 1 ] , ( V_3 -> V_364 + 1 ) ) ;
F_9 ( ( unsigned char ) V_757 [ 2 ] , ( V_3 -> V_364 + 1 ) ) ;
}
F_62 ( 1 ) ;
F_65 ( V_3 ) ;
V_163 = F_8 ( V_3 -> V_262 ) ;
if ( V_163 & 0x10 )
F_13 ( V_3 -> V_212 , 0x32 , 0xDF , 0x20 ) ;
else
F_13 ( V_3 -> V_212 , 0x32 , 0xDF , 0x00 ) ;
F_9 ( 0x00 , V_3 -> V_364 ) ;
for ( V_200 = 0 ; V_200 < 256 ; V_200 ++ ) {
F_9 ( 0 , ( V_3 -> V_364 + 1 ) ) ;
F_9 ( 0 , ( V_3 -> V_364 + 1 ) ) ;
F_9 ( 0 , ( V_3 -> V_364 + 1 ) ) ;
}
F_5 ( V_3 -> V_180 , 0x01 , V_750 ) ;
F_5 ( V_3 -> V_212 , 0x63 , V_755 ) ;
F_5 ( V_3 -> V_180 , 0x31 , V_756 ) ;
F_5 ( V_3 -> V_212 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_212 , 0x53 ) & 0xFD ) ) ;
F_5 ( V_3 -> V_180 , 0x1F , ( unsigned char ) V_751 ) ;
}
static void F_119 ( struct V_625 * V_626 ,
struct V_209 * V_210 ,
struct V_2 * V_3 )
{
unsigned short V_198 ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
if ( ! ( V_3 -> V_246 & V_714 ) ) {
if ( V_3 -> V_246 & V_716 ) {
F_5 ( V_3 -> V_539 , 0x1E , 0x20 ) ;
} else {
if ( V_3 -> V_48 & V_578 ) {
F_5 ( V_3 -> V_539 ,
0x1E , 0x20 ) ;
}
}
}
if ( ! ( V_3 -> V_246 & V_715 ) ) {
if ( ( V_3 -> V_246 & V_717 ) || ( V_3 -> V_48
& ( V_207 | V_206
| V_233 ) ) ) {
V_198 = ( unsigned char ) F_2 (
V_3 -> V_180 , 0x32 ) ;
V_198 &= 0xDF ;
if ( V_3 -> V_48 & V_208 ) {
if ( ! ( V_3 -> V_48 &
V_233 ) )
V_198 |= 0x20 ;
}
F_5 ( V_3 -> V_180 , 0x32 , V_198 ) ;
F_21 ( V_3 -> V_180 , 0x1E , 0x20 ) ;
V_198 = ( unsigned char ) F_2 (
V_3 -> V_539 , 0x2E ) ;
if ( ! ( V_198 & 0x80 ) )
F_21 ( V_3 -> V_539 ,
0x2E , 0x80 ) ;
F_14 ( V_3 -> V_539 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_246 & ( V_716 | V_717 ) )
|| ( ! ( V_3 -> V_48 & V_579 ) ) ) {
F_13 ( V_3 -> V_565 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_147 & ( V_149 | V_235 ) ) {
if ( ! F_94 ( V_3 ) ) {
if ( F_95 ( V_3 ) ||
( V_3 -> V_48 &
( V_207 | V_205 ) ) )
F_14 (
V_3 -> V_546 ,
0x2A ,
0x7F ) ;
}
F_14 ( V_3 -> V_546 , 0x30 , 0x7F ) ;
}
}
V_198 = 0x00 ;
if ( ! ( V_3 -> V_48 & V_579 ) ) {
V_198 = 0xc0 ;
if ( ! ( V_3 -> V_48 & V_589 ) ) {
if ( V_3 -> V_48 & V_205 ) {
if ( V_3 -> V_48 &
V_578 ) {
V_198 = V_198 & 0x40 ;
if ( V_3 -> V_48 &
V_205 )
V_198 = V_198 ^ 0xC0 ;
if ( V_3 -> V_246 &
V_715 )
V_198 &= 0xBF ;
if ( V_3 -> V_246 &
V_714 )
V_198 &= 0x7F ;
if ( V_3 -> V_246 &
V_717 )
V_198 |= 0x40 ;
if ( V_3 -> V_246 &
V_716 )
V_198 |= 0x80 ;
}
}
}
}
F_21 ( V_3 -> V_546 , 0x1F , V_198 ) ;
if ( ! ( V_3 -> V_246 & V_714 ) ) {
if ( ! ( V_3 -> V_246 & V_718 ) ) {
F_90 ( V_210 ,
V_3 ) ;
F_63 ( V_626 , V_210 ,
V_3 ) ;
}
}
}
else {
if ( V_3 -> V_48 & ( V_206 | V_207
| V_205 ) )
F_21 ( V_3 -> V_539 , 0x1E , 0x20 ) ;
V_198 = ( unsigned char ) F_2 ( V_3 -> V_539 ,
0x2E ) ;
if ( ! ( V_198 & 0x80 ) )
F_21 ( V_3 -> V_539 , 0x2E , 0x80 ) ;
F_14 ( V_3 -> V_539 , 0x00 , 0x7F ) ;
F_63 ( V_626 , V_210 , V_3 ) ;
}
}
static void F_120 ( struct V_625 * V_626 ,
struct V_209 * V_210 ,
unsigned short V_192 , unsigned short V_193 ,
struct V_2 * V_3 )
{
unsigned short V_197 , V_225 , V_282 , V_163 ;
unsigned short V_758 = V_3 -> V_284 ;
V_197 = F_3 ( V_192 , V_193 , V_3 ) ;
F_4 ( V_192 , V_197 , V_193 , V_3 ) ;
F_9 ( V_3 -> V_7 [ V_197 ] . V_759 , V_3 -> V_262 ) ;
F_6 ( V_210 , V_197 , V_3 ) ;
F_7 ( V_192 , V_197 , V_193 , V_3 ) ;
F_10 ( V_197 , V_3 ) ;
F_11 ( V_3 ) ;
if ( V_210 -> V_267 == V_162 ) {
if ( V_3 -> V_232 == 0 )
F_12 ( V_3 ) ;
}
V_163 = ~ V_553 ;
V_3 -> V_246 &= V_163 ;
V_3 -> V_745 = 0 ;
if ( V_3 -> V_147 & ( V_253 | V_254 | V_148
| V_149 | V_235 ) ) {
if ( V_3 -> V_48 & ( V_589 | V_205
| V_208 ) ) {
V_3 -> V_246 |= V_553 ;
}
}
V_225 = F_115 ( V_210 , V_192 ,
V_193 , V_3 ) ;
if ( V_225 != 0xFFFF ) {
F_16 ( V_225 , V_3 ) ;
F_19 ( V_192 , V_193 , V_225 ,
V_3 , V_210 ) ;
F_27 ( V_210 , V_192 , V_193 ,
V_225 , V_3 ) ;
F_28 ( V_192 , V_193 , V_225 ,
V_210 , V_3 ) ;
F_30 ( V_192 , V_193 , V_210 ,
V_225 , V_3 ) ;
}
if ( ( V_210 -> V_267 >= V_159 ) &&
( V_210 -> V_267 < V_162 ) ) {
if ( ( V_192 == 0x00 ) | ( V_192 == 0x01 ) ) {
F_5 ( V_3 -> V_180 , 0x2B , 0x4E ) ;
F_5 ( V_3 -> V_180 , 0x2C , 0xE9 ) ;
V_282 = ( unsigned char ) F_8 ( V_758 ) ;
F_9 ( ( V_282 |= 0x0C ) , V_758 ) ;
} else if ( ( V_192 == 0x04 ) | ( V_192 == 0x05 ) | ( V_192
== 0x0D ) ) {
F_5 ( V_3 -> V_180 , 0x2B , 0x1B ) ;
F_5 ( V_3 -> V_180 , 0x2C , 0xE3 ) ;
V_282 = ( unsigned char ) F_8 ( V_758 ) ;
F_9 ( ( V_282 |= 0x0C ) , V_758 ) ;
}
}
if ( V_210 -> V_267 >= V_338 ) {
V_163 = F_2 ( V_3 -> V_212 , 0x38 ) ;
if ( V_163 & 0xA0 ) {
if ( V_210 -> V_267 == V_162 )
F_22 ( V_192 , V_193 ,
V_225 , V_3 ) ;
else
F_20 ( V_192 , V_193 ,
V_225 , V_3 ) ;
F_25 ( V_192 , V_3 ,
V_225 ) ;
F_24 ( V_210 -> V_267 ,
V_3 , V_225 , V_192 ) ;
if ( V_3 -> V_232 == 1 )
F_92 ( V_626 ,
V_210 -> V_267 ,
V_192 , V_193 , V_3 ) ;
}
}
V_3 -> V_246 &= ( ~ V_553 ) ;
F_32 ( V_192 , V_210 , V_3 ) ;
F_34 ( V_210 , V_192 , V_193 ,
V_225 , V_3 ) ;
F_36 ( V_192 , V_193 , V_3 ) ;
}
unsigned char F_121 ( struct V_625 * V_626 ,
struct V_209 * V_210 ,
unsigned short V_192 )
{
unsigned short V_193 ;
struct V_2 V_760 ;
struct V_2 * V_3 = & V_760 ;
V_3 -> V_761 = ( unsigned long ) V_210 -> V_762 ;
V_3 -> V_232 = 0 ;
V_3 -> V_580 = 1 ;
if ( V_210 -> V_267 >= V_159 ) {
V_3 -> V_584 = 0 ;
V_3 -> V_586 = 0 ;
V_3 -> V_591 = 0 ;
V_3 -> V_147 = 0 ;
} else {
V_3 -> V_584 = 1 ;
V_3 -> V_586 = 1 ;
V_3 -> V_591 = 1 ;
}
V_3 -> V_180 = V_3 -> V_761 + 0x14 ;
V_3 -> V_212 = V_3 -> V_761 + 0x24 ;
V_3 -> V_218 = V_3 -> V_761 + 0x10 ;
V_3 -> V_221 = V_3 -> V_761 + 0x1e ;
V_3 -> V_262 = V_3 -> V_761 + 0x12 ;
V_3 -> V_284 = V_3 -> V_761 + 0x1C ;
V_3 -> V_330 = V_3 -> V_761 + 0x1a ;
V_3 -> V_363 = V_3 -> V_761 + 0x16 ;
V_3 -> V_763 = V_3 -> V_761 + 0x17 ;
V_3 -> V_364 = V_3 -> V_761 + 0x18 ;
V_3 -> V_349 = V_3 -> V_761 + 0x19 ;
V_3 -> V_217 = V_3 -> V_761 + 0x2A ;
V_3 -> V_764 = V_3 -> V_761 + V_765 ;
V_3 -> V_539 = V_3 -> V_761 + V_766 ;
V_3 -> V_565 = V_3 -> V_761 + V_767 ;
V_3 -> V_685 = V_3 -> V_761 + V_768 ;
V_3 -> V_546 = V_3 -> V_761 + V_769 ;
V_3 -> V_690 = V_3 -> V_761 + V_769 + 2 ;
if ( V_210 -> V_267 == V_338 ) {
if ( ( F_2 ( V_3 -> V_212 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_232 = 1 ;
}
if ( V_210 -> V_267 == V_162 ) {
if ( ( F_2 ( V_3 -> V_212 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_2 ( V_3 -> V_212 , 0x30 ) & 0x20 )
V_3 -> V_232 = 1 ;
}
}
if ( V_210 -> V_267 < V_159 )
F_51 ( V_3 ) ;
F_1 ( V_210 -> V_267 , V_3 ) ;
if ( V_192 & 0x80 )
V_192 = V_192 & 0x7F ;
F_5 ( V_3 -> V_180 , 0x05 , 0x86 ) ;
if ( V_210 -> V_267 < V_159 )
F_112 ( V_210 , V_3 ) ;
F_55 ( V_192 , & V_193 , V_3 ) ;
if ( V_210 -> V_267 < V_159 ) {
F_52 ( V_192 , V_193 , V_210 , V_3 ) ;
F_53 ( V_192 , V_193 , V_3 ) ;
F_54 ( V_192 , V_193 , V_3 ) ;
F_96 ( V_626 , V_210 , V_3 ) ;
if ( V_3 -> V_48 & ( V_589 | V_205 ) ) {
F_120 ( V_626 , V_210 , V_192 ,
V_193 , V_3 ) ;
if ( V_3 -> V_48 & V_205 ) {
F_116 ( V_192 , V_193 ,
V_210 , V_3 ) ;
}
} else {
if ( ! ( V_3 -> V_48 & V_590 ) ) {
F_120 ( V_626 ,
V_210 , V_192 ,
V_193 , V_3 ) ;
if ( V_3 -> V_48 & V_205 ) {
F_116 ( V_192 , V_193 ,
V_210 ,
V_3 ) ;
}
}
}
if ( V_3 -> V_48 & ( V_589 | V_590 ) ) {
switch ( V_210 -> V_770 ) {
case V_771 :
F_117 ( V_192 , V_210 ,
V_3 ) ;
break;
case V_772 :
F_117 ( V_192 , V_210 ,
V_3 ) ;
break;
default:
break;
}
}
F_110 ( V_192 , V_210 , V_3 ) ;
F_109 ( V_192 , V_193 , V_3 ) ;
F_111 ( V_210 , V_3 ) ;
F_119 ( V_626 , V_210 , V_3 ) ;
}
else {
if ( V_3 -> V_232 == 1 )
if ( ! F_91 ( V_626 , V_192 ,
V_193 ,
V_3 ) )
return 0 ;
if ( V_192 <= 0x13 ) {
V_3 -> V_196 = V_3 -> V_4 [ V_193 ] .
V_202 & V_577 ;
} else {
V_3 -> V_196 = V_3 -> V_10 [ V_193 ] .
V_203 & V_577 ;
}
V_3 -> V_246 = 0 ;
V_3 -> V_48 = V_579 ;
F_64 ( V_626 , V_210 , V_3 ) ;
F_120 ( V_626 , V_210 , V_192 ,
V_193 , V_3 ) ;
F_63 ( V_626 , V_210 , V_3 ) ;
}
F_50 ( V_210 , V_3 ) ;
if ( V_210 -> V_267 < V_159 ) {
F_113 ( V_210 , V_3 ) ;
}
return 1 ;
}
