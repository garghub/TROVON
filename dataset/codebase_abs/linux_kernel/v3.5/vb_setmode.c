void F_1 ( unsigned char V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = (struct V_5 * ) & V_6 ;
V_3 -> V_7 = (struct V_8 * ) V_9 ;
V_3 -> V_10 = (struct V_11 * ) V_12 ;
V_3 -> V_13
= (struct V_14 * ) V_15 ;
V_3 -> V_16 = (struct V_17 * ) V_18 ;
V_3 -> V_19 = (struct V_20 * ) V_21 ;
V_3 -> V_22 = (struct V_23 * ) V_24 ;
V_3 -> V_25 = (struct V_26 * ) V_27 ;
V_3 -> V_28 = V_29 ;
V_3 -> V_30 = (struct V_31 * ) V_32 ;
V_3 -> V_33
= (struct V_34 * ) V_35 ;
V_3 -> V_36 = & V_37 ;
V_3 -> V_38 = & V_39 ;
V_3 -> V_40 = & V_41 ;
V_3 -> V_42 = 0 ;
V_3 -> V_43 = 0 ;
V_3 -> V_44 = 0 ;
V_3 -> V_45 = 0 ;
V_3 -> V_46 = 0 ;
V_3 -> V_47 = V_48 ;
V_3 -> V_49 = V_50 ;
V_3 -> V_51 = V_52 ;
V_3 -> V_53 = & V_54 ;
V_3 -> V_55 = & V_56 ;
V_3 -> V_57 = V_58 ;
V_3 -> V_59 = V_60 ;
V_3 -> V_61 = V_62 ;
V_3 -> V_63 = V_64 ;
V_3 -> V_65 = V_66 ;
V_3 -> V_67 = V_68 ;
V_3 -> V_69 = & V_70 ;
V_3 -> V_71 = & V_72 ;
V_3 -> V_73 = V_74 ;
V_3 -> V_75 = & V_76 ;
V_3 -> V_77 = & V_78 ;
V_3 -> V_79 = & V_80 ;
V_3 -> V_81 = & V_82 ;
V_3 -> V_83 = & V_84 ;
V_3 -> V_85 = & V_86 ;
V_3 -> V_87 = & V_88 ;
V_3 -> V_89 = & V_90 ;
V_3 -> V_91 = & V_92 ;
V_3 -> V_93 = & V_94 ;
V_3 -> V_95 = & V_96 ;
V_3 -> V_97 = & V_98 ;
V_3 -> V_99 = & V_100 ;
V_3 -> V_101 = & V_102 ;
V_3 -> V_103 = & V_104 ;
V_3 -> V_105 = & V_106 ;
V_3 -> V_107 = V_108 ;
V_3 -> V_109 = V_110 ;
V_3 -> V_111 = V_112 ;
V_3 -> V_113 = V_114 ;
V_3 -> V_115 = V_116 ;
V_3 -> V_117 = V_118 ;
V_3 -> V_119 = V_120 ;
V_3 -> V_121 = V_122 ;
V_3 -> V_123 = V_124 ;
V_3 -> V_125 = V_126 ;
V_3 -> V_127 = V_128 ;
V_3 -> V_129 = V_130 ;
V_3 -> V_131 = V_132 ;
V_3 -> V_133 = V_134 ;
V_3 -> V_135 = (struct V_136 * ) V_137 ;
V_3 -> V_138 = (struct V_139 * ) V_140 ;
V_3 -> V_141 = (struct V_142 * ) V_143 ;
if ( ( V_3 -> V_144 & V_145 ) || ( V_3 -> V_144 & V_146 ) )
V_3 -> V_147 = V_148 ;
else
V_3 -> V_147 = V_149 ;
V_3 -> V_150 = V_151 ;
V_3 -> V_152 = V_153 ;
V_3 -> V_154 = & V_155 ;
if ( V_1 >= V_156 )
V_3 -> V_157 = & V_158 ;
if ( V_1 == V_159 ) {
unsigned char V_160 ;
V_3 -> V_16
= (struct V_17 * ) V_161 ;
V_3 -> V_49 = V_162 ;
V_3 -> V_157 = & V_163 ;
V_3 -> V_164 = & V_165 ;
V_3 -> V_166 = & V_167 ;
V_3 -> V_168 = V_169 ;
V_3 -> V_170 = V_171 ;
V_3 -> V_172 = & V_173 ;
V_3 -> V_174 = & V_175 ;
V_3 -> V_47 = V_176 ;
V_160 = F_2 ( V_3 -> V_177 , 0x3B ) ;
if ( ( ( V_160 & 0x88 ) == 0x80 ) || ( ( V_160 & 0x88 ) == 0x08 ) )
V_3 -> V_157 = & V_178 ;
}
if ( V_1 >= V_156 ) {
V_3 -> V_179 = & V_180 ;
V_3 -> V_181 = & V_182 ;
V_3 -> V_183 = & V_184 ;
V_3 -> V_185 = & V_186 ;
V_3 -> V_187 = & V_188 ;
}
}
static void F_3 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned char V_191 , V_192 ;
unsigned short V_193 , V_194 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
F_4 ( V_3 -> V_177 , 0x00 , 0x03 ) ;
V_191 = V_3 -> V_4 -> V_196 [ 0 ] ;
V_193 = V_197 ;
if ( V_3 -> V_45 & V_197 ) {
V_191 |= 0x01 ;
} else {
if ( V_3 -> V_45 & ( V_198 | V_199 ) ) {
if ( V_3 -> V_45 & V_200 )
V_191 |= 0x01 ;
}
}
V_191 |= 0x20 ;
F_4 ( V_3 -> V_177 , 0x01 , V_191 ) ;
for ( V_193 = 02 ; V_193 <= 04 ; V_193 ++ ) {
V_192 = V_3 -> V_4 -> V_196 [ V_193 - 1 ] ;
F_4 ( V_3 -> V_177 , V_193 , V_192 ) ;
}
}
static void F_5 ( struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned char V_203 ;
unsigned short V_193 ;
V_203 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x11 ) ;
V_203 &= 0x7f ;
F_4 ( V_3 -> V_204 , 0x11 , V_203 ) ;
for ( V_193 = 0 ; V_193 <= 0x18 ; V_193 ++ ) {
V_203 = V_3 -> V_4 -> V_205 [ V_193 ] ;
F_4 ( V_3 -> V_204 , V_193 , V_203 ) ;
}
}
static void F_6 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned char V_206 ;
unsigned short V_193 , V_194 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
for ( V_193 = 0 ; V_193 <= 0x13 ; V_193 ++ ) {
V_206 = V_3 -> V_4 -> V_207 [ V_193 ] ;
if ( V_194 & V_208 ) {
if ( V_193 == 0x13 ) {
if ( V_3 -> V_45 & V_197 ) {
V_206 = 0 ;
} else {
if ( V_3 -> V_45 & ( V_198
| V_199 ) ) {
if ( V_3 -> V_45 &
V_200 )
V_206 = 0 ;
}
}
}
}
F_7 ( V_3 -> V_209 ) ;
F_8 ( V_193 , V_3 -> V_210 ) ;
F_8 ( V_206 , V_3 -> V_210 ) ;
}
F_7 ( V_3 -> V_209 ) ;
F_8 ( 0x14 , V_3 -> V_210 ) ;
F_8 ( 0x00 , V_3 -> V_210 ) ;
F_7 ( V_3 -> V_209 ) ;
F_8 ( 0x20 , V_3 -> V_210 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
unsigned char V_211 ;
unsigned short V_193 ;
for ( V_193 = 0 ; V_193 <= 0x08 ; V_193 ++ ) {
V_211 = V_3 -> V_4 -> V_212 [ V_193 ] ;
F_4 ( V_3 -> V_213 , V_193 , V_211 ) ;
}
if ( V_3 -> V_214 > V_215 ) {
V_211 = ( unsigned char ) F_2 ( V_3 -> V_213 , 0x05 ) ;
V_211 &= 0xBF ;
F_4 ( V_3 -> V_213 , 0x05 , V_211 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
unsigned short V_193 ;
for ( V_193 = 0x0A ; V_193 <= 0x0E ; V_193 ++ )
F_4 ( V_3 -> V_177 , V_193 , 0x00 ) ;
}
static unsigned char F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_177 , 0x31 , ~ 0x30 , 0x20 ) ;
F_4 ( V_3 -> V_177 , 0x2B , V_3 -> V_22 [ 0 ] . V_216 ) ;
F_4 ( V_3 -> V_177 , 0x2C , V_3 -> V_22 [ 0 ] . V_217 ) ;
F_12 ( V_3 -> V_177 , 0x31 , ~ 0x30 , 0x10 ) ;
F_4 ( V_3 -> V_177 , 0x2B , V_3 -> V_22 [ 1 ] . V_216 ) ;
F_4 ( V_3 -> V_177 , 0x2C , V_3 -> V_22 [ 1 ] . V_217 ) ;
F_13 ( V_3 -> V_177 , 0x31 , ~ 0x30 ) ;
return 0 ;
}
static unsigned char F_14 ( unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 , unsigned short * V_193 ,
struct V_2 * V_3 )
{
unsigned short V_219 , V_220 , V_221 , V_194 , V_222 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_220 = V_3 -> V_10 [ V_218 + ( * V_193 ) ] . V_224 ;
V_219 = 0 ;
if ( V_3 -> V_225 == 0 ) {
if ( V_3 -> V_45 & V_226 ) {
V_219 |= V_227 ;
if ( V_3 -> V_144 & V_228 )
V_219 |= V_229 ;
}
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
V_219 |= V_230 ;
if ( V_3 -> V_42 != V_231 ) {
if ( V_3 -> V_42 != V_232 ) {
if ( V_3 -> V_44 &
V_233 ) {
if ( V_221 >= 9 ) {
V_219 = 0 ;
return 0 ;
}
}
}
}
}
if ( V_3 -> V_45 & V_234 ) {
if ( ( V_3 -> V_144 & V_145 ) &&
( V_3 -> V_235 == V_236 ) ) {
V_219 |= V_237 ;
if ( V_3 -> V_45 & V_200 ) {
if ( V_221 == 4 )
return 0 ;
if ( V_221 == 3 )
return 0 ;
if ( V_221 > 7 )
return 0 ;
}
} else {
V_219 |= V_238 ;
if ( V_3 -> V_45 & V_200 ) {
if ( V_221 == 4 )
return 0 ;
if ( V_221 == 3 ) {
if ( V_3 -> V_239
& V_240 )
return 0 ;
}
if ( V_221 > 7 )
return 0 ;
}
}
} else {
if ( V_3 -> V_45 & ( V_241 |
V_242 |
V_243 |
V_244 |
V_234 ) ) {
V_219 |= V_245 ;
if ( V_3 -> V_144 & ( V_246 | V_247
| V_145 | V_146
| V_228 ) ) {
V_219 |= V_248 ;
}
if ( ! ( V_3 -> V_45 & V_249 ) ) {
if ( V_194 & V_250 ) {
if ( V_3 -> V_45 &
V_200 ) {
if ( ! ( V_3 -> V_45 &
V_251 ) ) {
return 0 ;
}
}
}
}
}
}
} else {
if ( V_3 -> V_45 & V_199 ) {
V_219 |= V_230 ;
if ( V_221 > 0x08 )
return 0 ;
if ( V_3 -> V_42 < V_252 ) {
if ( V_221 > 0x07 )
return 0 ;
if ( V_221 == 0x04 )
return 0 ;
}
}
}
for (; V_3 -> V_10 [ V_218 + ( * V_193 ) ] . V_224 ==
V_220 ; ( * V_193 ) -- ) {
V_222 = V_3 -> V_10 [ V_218 + ( * V_193 ) ] .
V_253 ;
if ( V_222 & V_219 )
return 1 ;
if ( ( * V_193 ) == 0 )
break;
}
for ( ( * V_193 ) = 0 ; ; ( * V_193 ) ++ ) {
V_222 = V_3 -> V_10 [ V_218 + ( * V_193 ) ] .
V_253 ;
if ( V_3 -> V_10 [ V_218 + ( * V_193 ) ] . V_224
!= V_220 ) {
return 0 ;
}
if ( V_222 & V_219 )
return 1 ;
}
return 1 ;
}
static void F_15 ( unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_254 , V_160 ;
V_254 = V_3 -> V_10 [ V_218 ] . V_253 >> 8 ;
V_254 &= 0xC0 ;
V_160 = 0x2F ;
V_160 |= V_254 ;
F_8 ( V_160 , V_3 -> V_255 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_201 * V_202 )
{
unsigned char V_256 , V_257 , V_258 ;
unsigned short V_193 , V_259 ;
V_256 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x11 ) ;
V_256 &= 0x7F ;
F_4 ( V_3 -> V_204 , 0x11 , V_256 ) ;
V_256 = V_3 -> V_135 [ 0 ] . V_256 [ 0 ] ;
F_4 ( V_3 -> V_204 , 0 , V_256 ) ;
for ( V_193 = 0x01 ; V_193 <= 0x04 ; V_193 ++ ) {
V_256 = V_3 -> V_135 [ 0 ] . V_256 [ V_193 ] ;
F_4 ( V_3 -> V_204 , ( unsigned short ) ( V_193 + 1 ) , V_256 ) ;
}
for ( V_193 = 0x05 ; V_193 <= 0x06 ; V_193 ++ ) {
V_256 = V_3 -> V_135 [ 0 ] . V_256 [ V_193 ] ;
F_4 ( V_3 -> V_177 , ( unsigned short ) ( V_193 + 6 ) , V_256 ) ;
}
V_259 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x0e ) ;
V_259 &= 0x1F ;
V_256 = V_3 -> V_135 [ 0 ] . V_256 [ 7 ] ;
V_256 &= 0xE0 ;
V_256 |= V_259 ;
F_4 ( V_3 -> V_177 , 0x0e , V_256 ) ;
if ( V_202 -> V_260 >= V_156 ) {
V_256 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x04 ) ;
V_256 = V_256 - 1 ;
F_4 ( V_3 -> V_204 , 0x04 , V_256 ) ;
V_256 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x05 ) ;
V_257 = V_256 ;
V_257 &= 0xE0 ;
V_256 &= 0x1F ;
if ( V_256 == 0 ) {
V_258 = V_256 ;
V_256 = ( unsigned char ) F_2 ( V_3 -> V_177 ,
0x0c ) ;
V_256 &= 0xFB ;
F_4 ( V_3 -> V_177 , 0x0c , V_256 ) ;
V_256 = V_258 ;
}
V_256 = V_256 - 1 ;
V_256 |= V_257 ;
F_4 ( V_3 -> V_204 , 0x05 , V_256 ) ;
V_256 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x0e ) ;
V_256 = V_256 >> 5 ;
V_256 = V_256 + 3 ;
if ( V_256 > 7 )
V_256 = V_256 - 7 ;
V_256 = V_256 << 5 ;
F_12 ( V_3 -> V_177 , 0x0e , ~ 0xE0 , V_256 ) ;
}
}
static void F_17 ( unsigned short V_190 ,
unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned char V_256 ;
unsigned short V_193 , V_259 ;
for ( V_193 = 0x00 ; V_193 <= 0x01 ; V_193 ++ ) {
V_256 = V_3 -> V_138 [ 0 ] . V_256 [ V_193 ] ;
F_4 ( V_3 -> V_204 , ( unsigned short ) ( V_193 + 6 ) , V_256 ) ;
}
for ( V_193 = 0x02 ; V_193 <= 0x03 ; V_193 ++ ) {
V_256 = V_3 -> V_138 [ 0 ] . V_256 [ V_193 ] ;
F_4 ( V_3 -> V_204 , ( unsigned short ) ( V_193 + 0x0e ) , V_256 ) ;
}
for ( V_193 = 0x04 ; V_193 <= 0x05 ; V_193 ++ ) {
V_256 = V_3 -> V_138 [ 0 ] . V_256 [ V_193 ] ;
F_4 ( V_3 -> V_204 , ( unsigned short ) ( V_193 + 0x11 ) , V_256 ) ;
}
V_259 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x0a ) ;
V_259 &= 0xC0 ;
V_256 = V_3 -> V_138 [ 0 ] . V_256 [ 6 ] ;
V_256 &= 0x3F ;
V_256 |= V_259 ;
F_4 ( V_3 -> V_177 , 0x0a , V_256 ) ;
V_256 = V_3 -> V_138 [ 0 ] . V_256 [ 6 ] ;
V_256 &= 0x80 ;
V_256 = V_256 >> 2 ;
V_193 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_193 &= V_261 ;
if ( V_193 )
V_256 |= 0x80 ;
V_259 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x09 ) ;
V_259 &= 0x5F ;
V_256 |= V_259 ;
F_4 ( V_3 -> V_204 , 0x09 , V_256 ) ;
}
static void F_18 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 ,
struct V_201 * V_202 )
{
unsigned char V_262 , V_256 ;
unsigned short V_193 ;
V_262 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_262 = V_262 & V_264 ;
V_256 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x11 ) ;
V_256 &= 0x7F ;
F_4 ( V_3 -> V_204 , 0x11 , V_256 ) ;
for ( V_193 = 0 ; V_193 < 8 ; V_193 ++ )
V_3 -> V_135 [ 0 ] . V_256 [ V_193 ]
= V_3 -> V_13 [ V_262 ] . V_265 [ V_193 ] ;
for ( V_193 = 0 ; V_193 < 7 ; V_193 ++ )
V_3 -> V_138 [ 0 ] . V_256 [ V_193 ]
= V_3 -> V_13 [ V_262 ] . V_265 [ V_193 + 8 ] ;
F_16 ( V_3 , V_202 ) ;
F_17 ( V_190 , V_189 , V_3 ) ;
if ( V_3 -> V_214 > 0x03 )
F_4 ( V_3 -> V_204 , 0x14 , 0x4F ) ;
}
static void F_19 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned char V_262 , V_266 , V_267 , V_268 , V_269 ;
unsigned short V_270 , V_271 , V_272 ;
V_262 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 3 ] ;
V_268 = V_266 ;
F_4 ( V_3 -> V_177 , 0x2E , V_266 ) ;
V_269 = V_3 -> V_13 [ V_262 ] . V_265 [ 5 ] ;
V_269 &= 0xC0 ;
V_270 = V_269 ;
V_270 <<= 2 ;
V_270 |= V_266 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 4 ] ;
V_266 &= 0x1F ;
V_267 = V_3 -> V_13 [ V_262 ] . V_265 [ 6 ] ;
V_267 &= 0x04 ;
V_267 <<= 3 ;
V_266 |= V_267 ;
V_271 = V_270 & 0x3C0 ;
V_271 |= V_266 ;
V_268 &= 0x3F ;
if ( V_266 < V_268 )
V_271 |= 0x40 ;
V_271 &= 0xFF ;
V_266 = ( unsigned char ) V_271 ;
V_266 <<= 2 ;
V_269 >>= 6 ;
V_266 |= V_269 ;
F_4 ( V_3 -> V_177 , 0x2F , V_266 ) ;
F_12 ( V_3 -> V_177 , 0x30 , 0xE3 , 00 ) ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 10 ] ;
V_267 = V_266 ;
V_266 &= 0x01 ;
F_20 ( V_3 -> V_177 , 0x33 , V_266 ) ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 9 ] ;
V_268 = V_267 >> 1 ;
V_269 = V_266 & 0x04 ;
V_269 <<= 5 ;
V_268 |= V_269 ;
F_4 ( V_3 -> V_177 , 0x34 , V_268 ) ;
V_270 = V_269 ;
V_270 <<= 1 ;
V_270 |= V_267 ;
V_266 &= 0x80 ;
V_271 = V_266 << 2 ;
V_270 |= V_271 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 14 ] ;
V_266 &= 0x08 ;
V_271 = V_266 ;
V_271 <<= 7 ;
V_270 |= V_271 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 11 ] ;
V_266 &= 0x0F ;
V_267 = V_3 -> V_13 [ V_262 ] . V_265 [ 14 ] ;
V_267 &= 0x20 ;
V_267 >>= 1 ;
V_266 |= V_267 ;
V_271 = V_270 & 0x7E0 ;
V_271 |= V_266 ;
V_272 = V_270 & 0x1F ;
if ( V_266 < V_272 )
V_271 |= 0x20 ;
V_271 &= 0xFF ;
V_266 = ( unsigned char ) V_271 ;
V_266 <<= 2 ;
V_270 &= 0x600 ;
V_270 >>= 9 ;
V_267 = ( unsigned char ) V_270 ;
V_266 |= V_267 ;
V_266 &= 0x7F ;
F_4 ( V_3 -> V_177 , 0x3F , V_266 ) ;
}
static void F_21 ( unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_262 , V_266 , V_267 , V_268 ;
V_262 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 3 ] ;
V_267 = V_266 ;
F_4 ( V_3 -> V_177 , 0x2E , V_266 ) ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 5 ] ;
V_266 &= 0xC0 ;
V_267 |= ( V_266 << 2 ) ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 4 ] ;
V_266 &= 0x1F ;
V_268 = V_266 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 6 ] ;
V_266 &= 0x04 ;
V_266 <<= 3 ;
V_268 |= V_266 ;
V_267 = V_267 & 0x3C0 ;
V_267 |= V_268 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 3 ] ;
V_266 &= 0x3F ;
if ( V_268 <= V_266 )
V_267 += 0x40 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 5 ] ;
V_266 &= 0xC0 ;
V_266 >>= 6 ;
V_266 |= ( ( V_267 << 2 ) & 0xFF ) ;
F_4 ( V_3 -> V_177 , 0x2F , V_266 ) ;
F_12 ( V_3 -> V_177 , 0x30 , 0xE3 , 00 ) ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 10 ] ;
F_4 ( V_3 -> V_177 , 0x34 , V_266 ) ;
V_268 = V_266 ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 9 ] ;
V_267 = V_266 ;
V_266 = V_266 & 0x04 ;
V_266 >>= 2 ;
F_12 ( V_3 -> V_177 , 0x35 , ~ 0x01 , V_266 ) ;
V_268 |= ( V_266 << 8 ) ;
V_268 |= ( ( V_267 & 0x80 ) << 2 ) ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 14 ] ;
V_266 &= 0x08 ;
V_268 |= ( V_266 << 7 ) ;
V_266 = V_3 -> V_13 [ V_262 ] . V_265 [ 11 ] ;
V_266 &= 0x0F ;
V_267 = V_3 -> V_13 [ V_262 ] . V_265 [ 14 ] ;
V_267 &= 0x20 ;
V_267 >>= 1 ;
V_266 |= V_267 ;
V_267 = V_268 ;
V_267 &= 0x7E0 ;
V_267 |= V_266 ;
if ( V_267 <= V_268 )
V_267 |= 0x20 ;
V_266 = ( V_267 << 2 ) & 0xFF ;
F_12 ( V_3 -> V_177 , 0x3F , ~ 0xFC , V_266 ) ;
V_266 = V_268 >> 8 ;
F_12 ( V_3 -> V_177 , 0x35 , ~ 0x07 , V_266 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned char V_160 ;
V_160 = F_2 ( V_3 -> V_204 , 0x37 ) ;
V_160 = ( V_160 & 3 ) << 6 ;
F_12 ( V_3 -> V_177 , 0x06 , ~ 0xc0 , V_160 & 0x80 ) ;
F_12 ( V_3 -> V_177 , 0x09 , ~ 0xc0 , V_160 | 0x80 ) ;
}
static void F_23 ( int V_273 ,
struct V_2 * V_3 ,
unsigned short V_218 ,
unsigned short V_189 )
{
unsigned short V_274 , V_275 ;
unsigned short V_276 ;
V_276 = V_3 -> V_277 ;
F_4 ( V_3 -> V_204 , 0x2E , 0x00 ) ;
F_4 ( V_3 -> V_204 , 0x2F , 0x00 ) ;
F_4 ( V_3 -> V_204 , 0x46 , 0x00 ) ;
F_4 ( V_3 -> V_204 , 0x47 , 0x00 ) ;
if ( V_273 == V_159 ) {
V_275 = F_2 ( V_3 -> V_204 , 0x37 ) ;
if ( ( V_275 & 0x03 ) == 0 ) {
F_4 ( V_3 -> V_204 , 0x46 , 0x13 ) ;
F_4 ( V_3 -> V_204 , 0x47 , 0x13 ) ;
}
}
if ( ( ( * V_3 -> V_179 ) & 0xC0 ) == 0xC0 ) {
F_4 ( V_3 -> V_204 , 0x2E , * V_3 -> V_181 ) ;
F_4 ( V_3 -> V_204 , 0x2F , * V_3 -> V_183 ) ;
F_4 ( V_3 -> V_204 , 0x46 , * V_3 -> V_185 ) ;
F_4 ( V_3 -> V_204 , 0x47 , * V_3 -> V_187 ) ;
}
if ( V_273 == V_159 ) {
F_22 ( V_3 ) ;
} else {
V_275 = F_2 ( V_3 -> V_204 , 0x37 ) ;
if ( V_275 & 0x01 ) {
F_20 ( V_3 -> V_177 , 0x06 , 0x40 ) ;
F_20 ( V_3 -> V_177 , 0x09 , 0x40 ) ;
}
}
F_20 ( V_3 -> V_177 , 0x1E , 0x01 ) ;
F_13 ( V_3 -> V_177 , 0x30 , ~ 0x20 ) ;
F_13 ( V_3 -> V_177 , 0x35 , ~ 0x80 ) ;
V_274 = V_3 -> V_10 [ V_218 ] . V_253 ;
if ( V_274 & 0x4000 )
F_20 ( V_3 -> V_177 , 0x30 , 0x20 ) ;
if ( V_274 & 0x8000 )
F_20 ( V_3 -> V_177 , 0x35 , 0x80 ) ;
}
static void F_24 ( unsigned short V_189 ,
struct V_2 * V_3 ,
unsigned short V_218 )
{
int V_262 = - 1 ;
F_13 ( V_3 -> V_204 , 0x11 , 0x7F ) ;
if ( V_189 == 0x2E &&
( V_3 -> V_10 [ V_218 ] . V_263 ==
V_278 ) )
V_262 = 12 ;
else if ( V_189 == 0x2E && ( V_3 -> V_10 [ V_218 ] .
V_263 == V_279 ) )
V_262 = 13 ;
else if ( V_189 == 0x2F )
V_262 = 14 ;
else if ( V_189 == 0x50 )
V_262 = 15 ;
else if ( V_189 == 0x59 )
V_262 = 16 ;
if ( V_262 != - 1 ) {
F_4 ( V_3 -> V_204 , 0x02 ,
V_3 -> V_141 [ V_262 ] . V_280 ) ;
F_4 ( V_3 -> V_204 , 0x03 ,
V_3 -> V_141 [ V_262 ] . V_281 ) ;
F_4 ( V_3 -> V_204 , 0x15 ,
V_3 -> V_141 [ V_262 ] . V_282 ) ;
F_4 ( V_3 -> V_204 , 0x16 ,
V_3 -> V_141 [ V_262 ] . V_283 ) ;
}
}
static void F_25 ( struct V_201 * V_202 ,
unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_284 , V_219 , V_220 , V_285 , V_160 , V_194 ;
unsigned char V_256 ;
V_284 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_219 = V_3 -> V_33 [ V_284 ] . V_286 ;
V_220 = V_3 -> V_33 [ V_284 ] . V_287 ;
if ( V_194 & V_288 )
V_219 = V_219 >> 1 ;
if ( V_194 & V_288 )
V_219 = V_219 << 1 ;
V_160 = V_3 -> V_10 [ V_218 ] . V_253 ;
if ( V_160 & V_289 )
V_220 = V_220 >> 1 ;
if ( V_194 & V_261 )
V_220 = V_220 << 1 ;
V_285 = 8 ;
V_219 /= V_285 ;
V_219 -= 1 ;
V_220 -= 1 ;
V_285 = V_219 ;
V_160 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x11 ) ;
V_256 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x11 ) ;
V_256 &= 0x7F ;
F_4 ( V_3 -> V_204 , 0x11 , V_256 ) ;
F_4 ( V_3 -> V_204 , 0x01 , ( unsigned short ) ( V_285 & 0xff ) ) ;
F_12 ( V_3 -> V_204 , 0x0b , ~ 0x0c ,
( unsigned short ) ( ( V_285 & 0x0ff00 ) >> 10 ) ) ;
F_4 ( V_3 -> V_204 , 0x12 , ( unsigned short ) ( V_220 & 0xff ) ) ;
V_219 = 0 ;
V_220 = V_220 >> 8 ;
if ( V_220 & 0x01 )
V_219 |= 0x02 ;
if ( V_220 & 0x02 )
V_219 |= 0x40 ;
F_12 ( V_3 -> V_204 , 0x07 , ~ 0x42 , V_219 ) ;
V_256 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x07 ) ;
V_256 &= 0xFF ;
V_219 = 0 ;
if ( V_220 & 0x04 )
V_219 |= 0x02 ;
F_12 ( V_3 -> V_204 , 0x0a , ~ 0x02 , V_219 ) ;
F_4 ( V_3 -> V_204 , 0x11 , V_160 ) ;
}
static void F_26 ( unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_160 , V_290 , V_291 , V_292 , V_193 , V_293 ;
V_160 = V_3 -> V_7 [ V_190 ] . V_294 ;
V_160 = V_160 >> 8 ;
V_160 = V_3 -> V_28 [ V_160 ] ;
V_292 = V_3 -> V_10 [ V_218 ] . V_253 ;
V_292 &= V_289 ;
if ( V_292 )
V_160 = V_160 << 1 ;
V_292 = V_3 -> V_214 - V_295 ;
switch ( V_292 ) {
case 0 :
V_292 = 1 ;
break;
case 1 :
V_292 = 2 ;
break;
case 2 :
V_292 = 4 ;
break;
case 3 :
V_292 = 4 ;
break;
case 4 :
V_292 = 6 ;
break;
case 5 :
V_292 = 8 ;
break;
default:
break;
}
if ( ( V_189 >= 0x26 ) && ( V_189 <= 0x28 ) )
V_160 = V_160 * V_292 + V_292 / 2 ;
else
V_160 *= V_292 ;
V_293 = V_160 ;
V_292 = V_160 ;
V_160 = V_160 >> 8 ;
V_160 &= 0x0F ;
V_193 = F_2 ( V_3 -> V_177 , 0x0E ) ;
V_193 &= 0xF0 ;
V_193 |= V_160 ;
F_4 ( V_3 -> V_177 , 0x0E , V_193 ) ;
V_160 = ( unsigned char ) V_292 ;
V_160 &= 0xFF ;
F_4 ( V_3 -> V_204 , 0x13 , V_160 ) ;
V_292 = V_3 -> V_10 [ V_218 ] . V_253 ;
V_292 &= V_289 ;
if ( V_292 )
V_293 >>= 1 ;
V_293 = V_293 << 5 ;
V_290 = ( V_293 & 0xff00 ) >> 8 ;
V_291 = V_293 & 0x00ff ;
if ( V_291 == 0 )
V_290 += 1 ;
else
V_290 += 2 ;
if ( V_202 -> V_260 >= V_156 )
if ( ( V_189 == 0x4A ) | ( V_189 == 0x49 ) )
V_290 -= 1 ;
F_4 ( V_3 -> V_177 , 0x10 , V_290 ) ;
}
static unsigned short F_27 ( unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_296 [ 4 ] = { V_297 + 2 ,
V_297 + 2 ,
V_297 + 2 ,
V_297 + 2 } ;
unsigned short V_298 [ 4 ] = { V_299 + 5 ,
V_299 + 5 ,
V_299 + 5 ,
V_299 + 5 } ;
unsigned short V_300 [ 4 ] = { V_301 , V_301 , V_301 , V_301 } ;
unsigned short V_302 [ 4 ] = { V_297 + 2 ,
V_297 + 2 ,
V_297 + 2 ,
V_297 + 2 } ;
unsigned short V_303 [ 4 ] = { V_297 + 2 ,
V_297 + 2 ,
V_297 + 2 ,
V_297 + 2 } ;
unsigned short V_304 , V_305 ;
unsigned short V_194 , V_221 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_304 = V_3 -> V_10 [ V_218 ] . V_306 ;
if ( V_3 -> V_225 == 0 ) {
V_304 = V_304 >> 6 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
if ( V_3 -> V_42 != V_252 )
V_305 = V_298 [ V_304 ] ;
else
V_305 = V_296 [ V_304 ] ;
} else if ( V_3 -> V_45 & V_234 ) {
if ( V_3 -> V_239 & V_307 ) {
V_305 = V_308 + V_309 ;
V_305 += 25 ;
} else {
V_305 = V_308 + V_310 ;
V_305 += 25 ;
}
if ( V_3 -> V_239 & V_240 ) {
if ( V_194 & V_208 ) {
V_305 = V_308 + V_311 ;
V_305 += 25 ;
} else {
V_305 = V_308 + V_312 ;
V_305 += 25 ;
}
}
if ( ( V_3 -> V_144 & V_145 ) &&
! ( V_3 -> V_235 == V_236 ) ) {
if ( V_3 -> V_235 == V_313 )
V_305 = V_314 ;
else if ( V_3 -> V_235 == V_315 )
V_305 = V_316 ;
else if ( V_3 -> V_239 & V_307 )
V_305 = V_317 ;
else
V_305 = V_318 ;
}
} else if ( V_3 -> V_45 & V_198 ) {
if ( V_3 -> V_239 & V_307 ) {
V_305 = V_308 + V_319 ;
V_305 += 25 ;
} else {
V_305 = V_308 + V_320 ;
V_305 += 25 ;
}
} else {
V_305 = V_3 -> V_10 [ V_218 ] .
V_321 ;
V_305 &= V_264 ;
}
} else {
V_305 = V_304 ;
V_305 = V_305 >> 6 ;
if ( ( V_3 -> V_42 == V_322 ) ||
( V_3 -> V_42 == V_323 ) )
V_305 = V_300 [ V_305 ] ;
else if ( ( V_3 -> V_42 == V_252 ) ||
( V_3 -> V_42 == V_324 ) )
V_305 = V_302 [ V_305 ] ;
else
V_305 = V_303 [ V_305 ] ;
}
return V_305 ;
}
static void F_28 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_201 * V_202 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned char V_262 , V_256 ;
unsigned short V_325 ;
if ( V_3 -> V_225 == 1 ) {
V_262 = V_3 -> V_10 [ V_218 ] . V_321 ;
V_256 = F_2 ( V_3 -> V_177 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_177 , 0x31 , V_256 ) ;
F_4 ( V_3 -> V_177 , 0x2B ,
V_3 -> V_22 [ V_262 ] . V_216 ) ;
F_4 ( V_3 -> V_177 , 0x2C ,
V_3 -> V_22 [ V_262 ] . V_217 ) ;
F_4 ( V_3 -> V_177 , 0x2D , 0x01 ) ;
} else if ( ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) && ( V_3 -> V_45
& V_197 ) ) {
V_325 = F_27 ( V_189 , V_190 ,
V_218 , V_202 ,
V_3 ) ;
V_256 = F_2 ( V_3 -> V_177 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_177 , 0x31 , V_256 ) ;
V_256 = V_3 -> V_25 [ V_325 ] . V_326 ;
F_4 ( V_3 -> V_177 , 0x2B , V_256 ) ;
V_256 = V_3 -> V_25 [ V_325 ] . V_327 ;
F_4 ( V_3 -> V_177 , 0x2C , V_256 ) ;
F_4 ( V_3 -> V_177 , 0x2D , 0x01 ) ;
} else {
V_262 = V_3 -> V_10 [ V_218 ] . V_321 ;
V_256 = F_2 ( V_3 -> V_177 , 0x31 ) & 0xCF ;
F_4 ( V_3 -> V_177 , 0x31 , V_256 ) ;
F_4 ( V_3 -> V_177 , 0x2B ,
V_3 -> V_22 [ V_262 ] . V_216 ) ;
F_4 ( V_3 -> V_177 , 0x2C ,
V_3 -> V_22 [ V_262 ] . V_217 ) ;
F_4 ( V_3 -> V_177 , 0x2D , 0x01 ) ;
}
if ( V_202 -> V_260 >= V_156 ) {
if ( V_3 -> V_7 [ V_190 ] . V_195 &
V_288 ) {
V_256 = F_2 ( V_3 -> V_177 , 0x2B ) ;
F_4 ( V_3 -> V_177 , 0x2B , V_256 ) ;
V_256 = F_2 ( V_3 -> V_177 , 0x2C ) ;
V_262 = V_256 ;
V_262 &= 0xE0 ;
V_256 &= 0x1F ;
V_256 = V_256 << 1 ;
V_256 += 1 ;
V_256 |= V_262 ;
F_4 ( V_3 -> V_177 , 0x2C , V_256 ) ;
}
}
}
static void F_29 ( struct V_2 * V_3 )
{
unsigned char V_160 ;
V_160 = F_2 ( V_3 -> V_204 , 0x37 ) ;
V_160 = ( V_160 & 1 ) << 6 ;
F_12 ( V_3 -> V_177 , 0x06 , ~ 0x40 , V_160 ) ;
F_12 ( V_3 -> V_177 , 0x09 , ~ 0xc0 , V_160 | 0x80 ) ;
}
static void F_30 ( unsigned short V_189 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_256 ;
V_256 = F_2 ( V_3 -> V_177 , 0x3D ) ;
V_256 &= 0xfe ;
F_4 ( V_3 -> V_177 , 0x3D , V_256 ) ;
F_4 ( V_3 -> V_177 , 0x08 , 0x34 ) ;
V_256 = F_2 ( V_3 -> V_177 , 0x09 ) ;
V_256 &= 0xC0 ;
F_4 ( V_3 -> V_177 , 0x09 , V_256 | 0x30 ) ;
V_256 = F_2 ( V_3 -> V_177 , 0x3D ) ;
V_256 |= 0x01 ;
F_4 ( V_3 -> V_177 , 0x3D , V_256 ) ;
if ( V_202 -> V_260 == V_328 )
F_29 ( V_3 ) ;
}
static void F_31 ( struct V_201 * V_202 ,
unsigned short V_189 , unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_256 , V_329 = 0 ;
short V_330 ;
unsigned char V_262 ;
V_262 = V_3 -> V_10 [ V_218 ] . V_321 ;
V_262 &= V_264 ;
V_330 = V_3 -> V_22 [ V_262 ] . CLOCK ;
V_256 = F_2 ( V_3 -> V_177 , 0x32 ) ;
V_256 &= 0xf3 ;
if ( V_330 >= 200 )
V_256 |= 0x0c ;
if ( V_202 -> V_260 >= V_156 )
V_256 &= ~ 0x04 ;
F_4 ( V_3 -> V_177 , 0x32 , V_256 ) ;
if ( V_202 -> V_260 < V_156 ) {
V_256 = F_2 ( V_3 -> V_177 , 0x1F ) ;
V_256 &= 0xE7 ;
if ( V_330 < 200 )
V_256 |= 0x10 ;
F_4 ( V_3 -> V_177 , 0x1F , V_256 ) ;
}
V_329 = 0x00 ;
F_12 ( V_3 -> V_177 , 0x07 , 0xFC , V_329 ) ;
if ( V_202 -> V_260 >= V_159 )
F_12 ( V_3 -> V_177 , 0x40 , 0xFC , V_329 & 0x03 ) ;
}
static void F_32 ( struct V_201 * V_202 ,
unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_256 , V_329 , V_331 , V_222 = 0 , V_194 , V_284 ,
V_332 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_222 = V_3 -> V_10 [ V_218 ] . V_253 ;
if ( F_2 ( V_3 -> V_204 , 0x31 ) & 0x01 )
F_12 ( V_3 -> V_177 , 0x1F , 0x3F , 0x00 ) ;
V_256 = V_222 ;
V_329 = 0 ;
V_329 |= 0x02 ;
V_331 = V_3 -> V_214 - V_215 ;
V_331 = V_331 << 2 ;
V_329 |= V_331 ;
V_256 &= V_289 ;
if ( V_256 )
V_329 |= 0x20 ;
F_12 ( V_3 -> V_177 , 0x06 , ~ 0x3F , V_329 ) ;
V_284 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_332 = V_3 -> V_33 [ V_284 ] . V_286 ;
V_256 = 0x0000 ;
if ( V_222 & V_289 ) {
if ( V_332 == 1024 )
V_256 = 0x0035 ;
else if ( V_332 == 1280 )
V_256 = 0x0048 ;
}
V_329 = V_256 & 0x00FF ;
F_12 ( V_3 -> V_204 , 0x19 , 0xFF , V_329 ) ;
V_329 = ( V_256 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_204 , 0x19 , 0xFC , V_329 ) ;
if ( V_194 & V_288 )
F_12 ( V_3 -> V_177 , 0x01 , 0xF7 , 0x08 ) ;
V_329 = 0 ;
if ( V_194 & V_333 )
V_329 |= 0x08 ;
F_12 ( V_3 -> V_177 , 0x0F , ~ 0x48 , V_329 ) ;
V_256 = 0x60 ;
V_256 = V_256 ^ 0x60 ;
V_256 = V_256 ^ 0xA0 ;
F_12 ( V_3 -> V_177 , 0x21 , 0x1F , V_256 ) ;
F_31 ( V_202 , V_189 , V_218 ,
V_3 ) ;
V_256 = F_2 ( V_3 -> V_204 , 0x31 ) ;
if ( V_202 -> V_260 == V_159 ) {
if ( V_256 & 0x40 )
V_256 = 0x2c ;
else
V_256 = 0x6c ;
F_4 ( V_3 -> V_204 , 0x52 , V_256 ) ;
F_20 ( V_3 -> V_204 , 0x51 , 0x10 ) ;
} else if ( V_202 -> V_260 >= V_156 ) {
if ( V_256 & 0x40 )
V_256 = 0x33 ;
else
V_256 = 0x73 ;
F_4 ( V_3 -> V_204 , 0x52 , V_256 ) ;
F_4 ( V_3 -> V_204 , 0x51 , 0x02 ) ;
} else {
if ( V_256 & 0x40 )
V_256 = 0x2c ;
else
V_256 = 0x6c ;
F_4 ( V_3 -> V_204 , 0x52 , V_256 ) ;
}
}
static void F_33 ( unsigned short V_334 ,
unsigned short V_290 ,
unsigned short V_291 ,
unsigned short V_335 ,
struct V_2 * V_3 )
{
unsigned short V_160 , V_336 , V_337 ;
V_336 = V_290 ;
V_337 = V_291 ;
if ( V_334 != 0 ) {
V_160 = V_336 ;
V_336 = V_335 ;
V_335 = V_160 ;
if ( V_334 == 1 ) {
V_160 = V_337 ;
V_337 = V_335 ;
V_335 = V_160 ;
} else {
V_160 = V_337 ;
V_337 = V_336 ;
V_336 = V_160 ;
}
}
F_8 ( ( unsigned short ) V_335 , V_3 -> V_338 ) ;
F_8 ( ( unsigned short ) V_336 , V_3 -> V_338 ) ;
F_8 ( ( unsigned short ) V_337 , V_3 -> V_338 ) ;
}
static void F_34 ( unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_256 , V_329 , V_193 , V_339 , V_340 , V_341 , V_342 , V_343 , V_344 , V_345 , V_334 , V_291 , V_290 , V_335 ;
const unsigned short * V_346 = V_347 ;
F_8 ( 0xFF , V_3 -> V_348 ) ;
F_8 ( 0x00 , V_3 -> V_349 ) ;
for ( V_193 = 0 ; V_193 < 16 ; V_193 ++ ) {
V_256 = V_346 [ V_193 ] ;
for ( V_339 = 0 ; V_339 < 3 ; V_339 ++ ) {
V_329 = 0 ;
if ( V_256 & 0x01 )
V_329 = 0x2A ;
if ( V_256 & 0x02 )
V_329 += 0x15 ;
F_8 ( V_329 , V_3 -> V_338 ) ;
V_256 = V_256 >> 2 ;
}
}
for ( V_193 = 16 ; V_193 < 32 ; V_193 ++ ) {
V_256 = V_346 [ V_193 ] ;
for ( V_339 = 0 ; V_339 < 3 ; V_339 ++ )
F_8 ( V_256 , V_3 -> V_338 ) ;
}
V_343 = 32 ;
for ( V_340 = 0 ; V_340 < 9 ; V_340 ++ ) {
V_344 = V_343 ;
V_345 = V_343 + 0x04 ;
V_334 = 0 ;
for ( V_341 = 0 ; V_341 < 3 ; V_341 ++ ) {
for ( V_342 = 0 ; V_342 < 5 ; V_342 ++ ) {
V_335 = V_346 [ V_343 ] ;
V_290 = V_346 [ V_344 ] ;
V_291 = V_346 [ V_345 ] ;
V_343 ++ ;
F_33 ( V_334 , V_290 , V_291 , V_335 , V_3 ) ;
}
V_343 -= 2 ;
for ( V_342 = 0 ; V_342 < 3 ; V_342 ++ ) {
V_335 = V_346 [ V_345 ] ;
V_290 = V_346 [ V_344 ] ;
V_291 = V_346 [ V_343 ] ;
V_343 -- ;
F_33 ( V_334 , V_290 , V_291 , V_335 , V_3 ) ;
}
V_334 ++ ;
}
V_343 += 5 ;
}
}
static void F_35 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_284 , V_332 , V_350 , V_194 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_284 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_332 = V_3 -> V_33 [ V_284 ] . V_286 ;
V_350 = V_3 -> V_33 [ V_284 ] . V_287 ;
if ( V_194 & V_288 )
V_332 = V_332 << 1 ;
if ( V_194 & V_261 )
V_350 = V_350 << 1 ;
if ( V_332 == 720 )
V_332 = 640 ;
V_3 -> V_351 = V_332 ;
V_3 -> V_352 = V_332 ;
V_3 -> V_353 = V_350 ;
V_3 -> V_354 = V_350 ;
}
static void * F_36 ( unsigned short V_355 , unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_193 , V_356 , V_285 , V_220 , V_357 , V_194 , V_346 ;
struct V_358 * V_359 = NULL ;
V_220 = V_355 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_357 = V_3 -> V_10 [ V_218 ] . V_306 ;
V_357 = V_357 & 0x0f ;
if ( V_220 <= 1 ) {
V_357 = V_3 -> V_10 [ V_218 ] . V_306 ;
if ( V_3 -> V_45 & V_197 ) {
V_357 = V_3 -> V_10 [ V_218 ] .
V_360 ;
}
if ( V_220 & 0x01 )
V_357 = ( V_357 >> 4 ) ;
V_357 = ( V_357 & 0x0f ) ;
}
V_285 = V_361 [ V_220 ] ;
if ( V_3 -> V_44 & V_362 ) {
if ( ( V_220 == 5 ) || ( V_220 ) == 7 )
V_285 = V_363 ;
else if ( ( V_220 == 3 ) || ( V_220 == 8 ) )
V_285 = V_364 ;
}
switch ( V_220 ) {
case 0 :
case 1 :
V_359 = V_365 ;
break;
case 2 :
V_359 = V_366 ;
break;
case 3 :
V_359 = V_367 ;
break;
case 4 :
V_359 = V_368 ;
break;
case 5 :
V_359 = V_369 ;
break;
case 6 :
V_359 = V_370 ;
break;
case 7 :
case 8 :
case 9 :
V_359 = NULL ;
break;
default:
break;
}
if ( V_359 == NULL )
return NULL ;
V_346 = V_220 ;
V_193 = 0 ;
while ( V_359 [ V_193 ] . V_371 != 0xff ) {
V_356 = V_3 -> V_42 ;
if ( V_220 & 0x0080 ) {
V_220 &= ( ~ 0x0080 ) ;
V_356 = V_3 -> V_43 ;
}
if ( V_3 -> V_44 & V_362 )
V_356 &= ( ~ V_372 ) ;
if ( V_359 [ V_193 ] . V_371 == V_356 ) {
V_220 = V_359 [ V_193 ] . V_373 ;
V_356 = V_3 -> V_44 ;
if ( V_194 & V_288 )
V_356 |= V_374 ;
V_220 &= V_356 ;
if ( V_220 == V_359 [ V_193 ] . V_375 )
break;
}
V_193 ++ ;
}
if ( V_346 == 0 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_377 [ V_357 ] ;
break;
case 1 :
return & V_378 [ V_357 ] ;
break;
case 2 :
return & V_379 [ V_357 ] ;
break;
case 3 :
return & V_380 [ V_357 ] ;
break;
case 4 :
return & V_381 [ V_357 ] ;
break;
case 5 :
return & V_382 [ V_357 ] ;
break;
case 6 :
return & V_383 [ V_357 ] ;
break;
case 7 :
return & V_384 [ V_357 ] ;
break;
case 8 :
return & V_385 [ V_357 ] ;
break;
case 9 :
return & V_386 [ V_357 ] ;
break;
case 10 :
return & V_387 [ V_357 ] ;
break;
default:
break;
}
} else if ( V_346 == 1 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_388 [ V_357 ] ;
break;
case 1 :
return & V_389 [ V_357 ] ;
break;
case 2 :
return & V_390 [ V_357 ] ;
break;
case 3 :
return & V_391 [ V_357 ] ;
break;
case 4 :
return & V_392 [ V_357 ] ;
break;
case 5 :
return & V_393 [ V_357 ] ;
break;
case 6 :
return & V_394 [ V_357 ] ;
break;
case 7 :
return & V_395 [ V_357 ] ;
break;
case 8 :
return & V_396 [ V_357 ] ;
break;
case 9 :
return & V_397 [ V_357 ] ;
break;
case 10 :
return & V_398 [ V_357 ] ;
break;
default:
break;
}
} else if ( V_346 == 2 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_399 [ V_357 ] ;
break;
case 1 :
return & V_400 [ V_357 ] ;
break;
case 2 :
return & V_401 [ V_357 ] ;
break;
case 3 :
return & V_402 [ V_357 ] ;
break;
case 4 :
return & V_403 [ V_357 ] ;
break;
case 5 :
return & V_404 [ V_357 ] ;
break;
case 6 :
return & V_405 [ V_357 ] ;
break;
case 7 :
return & V_406 [ V_357 ] ;
break;
case 8 :
return & V_407 [ V_357 ] ;
break;
case 9 :
return & V_408 [ V_357 ] ;
break;
case 10 :
return & V_409 [ V_357 ] ;
break;
case 11 :
return & V_410 [ V_357 ] ;
break;
case 12 :
return & V_411 [ V_357 ] ;
break;
default:
break;
}
} else if ( V_346 == 3 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_412 [ V_357 ] ;
break;
case 1 :
return & V_413 [ V_357 ] ;
break;
case 2 :
return & V_414 [ V_357 ] ;
break;
case 3 :
return & V_415 [ V_357 ] ;
break;
case 4 :
return & V_416 [ V_357 ] ;
break;
case 5 :
return & V_417 [ V_357 ] ;
break;
case 6 :
return & V_418 [ V_357 ] ;
break;
case 7 :
return & V_419 [ V_357 ] ;
break;
case 8 :
return & V_420 [ V_357 ] ;
break;
case 9 :
return & V_421 [ V_357 ] ;
break;
case 10 :
return & V_422 [ V_357 ] ;
break;
case 11 :
return & V_423 [ V_357 ] ;
break;
case 12 :
return & V_424 [ V_357 ] ;
break;
case 13 :
return & V_425 [ V_357 ] ;
break;
case 14 :
return & V_426 [ V_357 ] ;
break;
default:
break;
}
} else if ( V_346 == 4 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_427 [ V_357 ] ;
break;
case 1 :
return & V_428 [ V_357 ] ;
break;
case 2 :
return & V_429 [ V_357 ] ;
break;
case 3 :
return & V_430 [ V_357 ] ;
break;
case 4 :
return & V_431 [ V_357 ] ;
break;
case 5 :
return & V_432 [ V_357 ] ;
break;
case 6 :
case 7 :
return & V_433 [ V_357 ] ;
break;
case 8 :
return & V_434 [ V_357 ] ;
break;
case 9 :
return & V_435 [ V_357 ] ;
break;
case 10 :
return & V_436 [ V_357 ] ;
break;
case 11 :
return & V_437 [ V_357 ] ;
break;
case 12 :
return & V_438 [ V_357 ] ;
break;
case 13 :
return & V_438 [ V_357 ] ;
break;
case 14 :
return & V_439 [ V_357 ] ;
break;
case 15 :
case 16 :
return & V_440 [ V_357 ] ;
break;
case 17 :
return & V_441 [ V_357 ] ;
break;
case 18 :
return & V_442 [ V_357 ] ;
break;
default:
break;
}
} else if ( V_346 == 5 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_443 [ V_357 ] ;
break;
case 1 :
return & V_444 [ V_357 ] ;
break;
case 2 :
return & V_445 [ V_357 ] ;
break;
case 3 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_446 [ V_357 ] ;
else
return & V_447 [ V_357 ] ;
break;
case 4 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_448 [ V_357 ] ;
else
return & V_449 [ V_357 ] ;
break;
case 5 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_450 [ V_357 ] ;
else
return & V_451 [ V_357 ] ;
break;
case 6 :
case 7 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_452 [ V_357 ] ;
else
return & V_453 [ V_357 ] ;
break;
case 8 :
return & V_454 [ V_357 ] ;
break;
case 9 :
return & V_455 [ V_357 ] ;
break;
case 10 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_456 [ V_357 ] ;
else
return & V_457 [ V_357 ] ;
break;
case 11 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_458 [ V_357 ] ;
else
return & V_459 [ V_357 ] ;
break;
case 12 :
return & V_460 [ V_357 ] ;
break;
case 13 :
case 14 :
return & V_461 [ V_357 ] ;
break;
case 15 :
return & V_462 [ V_357 ] ;
break;
case 16 :
case 17 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_463 [ V_357 ] ;
else
return & V_464 [ V_357 ] ;
break;
case 18 :
if ( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) )
return & V_465 [ V_357 ] ;
else
return & V_466 [ V_357 ] ;
break;
case 19 :
return & V_467 [ V_357 ] ;
break;
default:
break;
}
} else if ( V_346 == 6 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_468 [ V_357 ] ;
break;
case 1 :
return & V_469 [ V_357 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void * F_37 ( unsigned short V_355 , unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_193 , V_356 , V_220 , V_357 , V_194 , V_346 ;
struct V_470 * V_359 = NULL ;
V_220 = V_355 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_357 = V_3 -> V_10 [ V_218 ] . V_306 ;
V_357 = V_357 & 0x3f ;
V_346 = V_220 ;
switch ( V_220 ) {
case 0 :
V_359 = NULL ;
break;
case 1 :
V_359 = NULL ;
break;
case 2 :
case 6 :
V_359 = V_471 ;
break;
case 3 :
V_359 = NULL ;
break;
case 4 :
V_359 = V_472 ;
break;
case 5 :
V_359 = NULL ;
break;
default:
break;
}
if ( V_359 == NULL )
return NULL ;
V_356 = V_3 -> V_46 ;
if ( V_3 -> V_45 & V_200 )
V_356 = V_356 | V_473 ;
if ( V_194 & V_288 )
V_356 = V_356 | V_474 ;
V_193 = 0 ;
while ( V_359 [ V_193 ] . V_373 != 0xffff ) {
if ( ( V_356 & V_359 [ V_193 ] . V_373 ) == V_359 [ V_193 ] . V_375 )
break;
V_193 ++ ;
}
if ( V_346 == 0x04 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_475 [ V_357 ] ;
break;
case 1 :
return & V_476 [ V_357 ] ;
break;
case 2 :
return & V_477 [ V_357 ] ;
break;
case 3 :
return & V_478 [ V_357 ] ;
break;
case 4 :
return & V_479 [ V_357 ] ;
break;
case 5 :
return & V_480 [ V_357 ] ;
break;
case 6 :
return & V_481 [ V_357 ] ;
break;
case 7 :
return & V_482 [ V_357 ] ;
break;
case 8 :
return & V_483 [ V_357 ] ;
break;
case 9 :
return & V_484 [ V_357 ] ;
break;
case 10 :
return & V_485 [ V_357 ] ;
break;
case 11 :
return & V_486 [ V_357 ] ;
break;
case 12 :
return & V_476 [ V_357 ] ;
break;
case 13 :
return & V_487 [ V_357 ] ;
break;
default:
break;
}
} else if ( V_346 == 0x02 ) {
switch ( V_359 [ V_193 ] . V_376 ) {
case 0 :
return & V_488 [ V_357 ] ;
break;
case 1 :
return & V_489 [ V_357 ] ;
break;
case 2 :
return & V_490 [ V_357 ] ;
break;
case 3 :
return & V_491 [ V_357 ] ;
break;
default:
break;
}
}
return NULL ;
}
static void F_38 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_220 ;
struct V_492 * V_493 = NULL ;
V_220 = 2 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
V_493 = (struct V_492 * ) F_36 ( V_220 ,
V_189 , V_190 , V_218 ,
V_3 ) ;
V_3 -> V_494 = V_493 -> V_494 ;
V_3 -> V_495 = V_493 -> V_495 ;
V_3 -> V_496 = V_493 -> V_497 ;
V_3 -> V_498 = V_493 -> V_499 ;
}
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
if ( ! ( V_3 -> V_44 & ( V_500
| V_362 ) ) ) {
if ( ( V_3 -> V_42 == V_252 ) ||
( V_3 -> V_42 == V_324 ) ) {
V_3 -> V_352 = 1024 ;
V_3 -> V_354 = 768 ;
} else if ( ( V_3 -> V_42 == V_231 ) ||
( V_3 -> V_42 == V_501 ) ) {
V_3 -> V_352 = 1280 ;
V_3 -> V_354 = 1024 ;
} else if ( V_3 -> V_42 == V_502 ) {
V_3 -> V_352 = 1400 ;
V_3 -> V_354 = 1050 ;
} else {
V_3 -> V_352 = 1600 ;
V_3 -> V_354 = 1200 ;
}
}
}
}
static void F_39 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned char V_262 ;
unsigned short V_220 , V_193 ;
struct V_503 * V_493 = NULL ;
struct V_504 * V_505 = NULL ;
V_262 = V_3 -> V_10 [ V_218 ] . V_306 ;
V_262 = V_262 & V_264 ;
V_220 = 0 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
V_493 = (struct V_503 * )
F_36 ( V_220 , V_189 ,
V_190 ,
V_218 ,
V_3 ) ;
for ( V_193 = 0 ; V_193 < 8 ; V_193 ++ )
V_3 -> V_135 [ 0 ] . V_256 [ V_193 ] = V_493 [ 0 ] . V_506 [ V_193 ] ;
}
F_16 ( V_3 , V_202 ) ;
V_220 = 1 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
V_505 = (struct V_504 * )
F_36 (
V_220 ,
V_189 ,
V_190 ,
V_218 ,
V_3 ) ;
for ( V_193 = 0 ; V_193 < 7 ; V_193 ++ )
V_3 -> V_138 [ 0 ] . V_256 [ V_193 ] = V_505 [ 0 ] . V_506 [ V_193 ] ;
}
F_17 ( V_190 , V_189 , V_3 ) ;
}
static unsigned short F_40 ( struct V_2 * V_3 )
{
unsigned char V_357 , V_191 , V_507 , V_193 ;
V_191 = F_2 ( V_3 -> V_204 , 0x36 ) ;
V_357 = V_191 & 0x0F ;
V_191 = V_191 & 0xF0 ;
V_193 = 0 ;
V_507 = V_3 -> V_147 [ V_193 ] . V_508 ;
while ( V_507 != 0xFF ) {
if ( V_507 & 0x80 ) {
V_357 = V_191 ;
V_507 = V_507 & ~ ( 0x80 ) ;
}
if ( V_357 == V_507 )
break;
V_193 ++ ;
V_507 = V_3 -> V_147 [ V_193 ] . V_508 ;
}
return V_193 ;
}
static unsigned short F_41 ( struct V_2 * V_3 )
{
unsigned short V_191 , V_357 , V_507 , V_193 ;
V_357 = V_3 -> V_42 ;
V_191 = V_3 -> V_43 ;
V_193 = 0 ;
V_507 = V_3 -> V_147 [ V_193 ] . V_508 ;
while ( V_507 != 0xFF ) {
if ( ( V_507 & 0x80 ) && ( V_507 != 0x80 ) ) {
V_357 = V_191 ;
V_507 &= ~ 0x80 ;
}
if ( V_357 == V_507 )
break;
V_193 ++ ;
V_507 = V_3 -> V_147 [ V_193 ] . V_508 ;
}
if ( V_507 == 0xFF ) {
V_3 -> V_42 = V_252 ;
V_3 -> V_43 = 0 ;
V_193 = 0 ;
}
return V_193 ;
}
static void F_42 ( unsigned short * V_509 ,
unsigned short * V_510 ,
struct V_2 * V_3 )
{
unsigned short V_511 ;
V_511 = F_40 ( V_3 ) ;
* V_509 = V_3 -> V_147 [ V_511 ] . V_512 ;
* V_510 = V_3 -> V_147 [ V_511 ] . V_513 ;
return;
}
static void F_43 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_220 , V_219 , V_285 , V_356 , V_514 , V_515 , V_194 ;
unsigned long V_160 , V_516 , V_292 , V_517 , V_518 ;
struct V_519 * V_493 = NULL ;
struct V_520 * V_505 = NULL ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_220 = 3 ;
if ( V_3 -> V_44 & V_362 )
V_505 =
(struct V_520 * )
F_36 (
V_220 ,
V_189 ,
V_190 ,
V_218 ,
V_3 ) ;
else
V_493 =
(struct V_519 * )
F_36 (
V_220 ,
V_189 ,
V_190 ,
V_218 ,
V_3 ) ;
F_42 ( & V_219 , & V_220 , V_3 ) ;
V_514 = V_220 ;
V_515 = V_219 ;
if ( ( V_3 -> V_42 == V_252 ) ||
( V_3 -> V_42 == V_324 ) ) {
V_219 = 1024 ;
V_220 = 768 ;
} else if ( ( V_3 -> V_42 == V_231 ) ||
( V_3 -> V_42 == V_501 ) ) {
V_219 = 1280 ;
V_220 = 1024 ;
} else if ( V_3 -> V_42 == V_502 ) {
V_219 = 1400 ;
V_220 = 1050 ;
} else {
V_219 = 1600 ;
V_220 = 1200 ;
}
if ( V_3 -> V_44 & V_500 ) {
V_3 -> V_352 = V_219 ;
V_3 -> V_354 = V_220 ;
V_3 -> V_351 = V_219 ;
V_3 -> V_353 = V_220 ;
}
V_219 = V_3 -> V_496 ;
if ( V_3 -> V_44 & V_362 )
V_220 = V_505 -> V_521 ;
else
V_220 = V_493 -> V_521 ;
V_285 = V_3 -> V_352 ;
V_220 = V_220 & 0x0fff ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
F_4 ( V_3 -> V_522 , 0x1A , V_220 & 0x07 ) ;
V_285 = V_285 >> 3 ;
V_220 = V_220 >> 3 ;
F_4 ( V_3 -> V_522 , 0x16 ,
( unsigned short ) ( V_220 & 0xff ) ) ;
F_4 ( V_3 -> V_522 , 0x17 ,
( unsigned short ) ( V_285 & 0xff ) ) ;
V_219 = V_3 -> V_496 ;
if ( V_3 -> V_44 & V_362 )
V_220 = V_505 -> V_523 ;
else
V_220 = V_493 -> V_523 ;
V_285 = V_515 ;
if ( V_3 -> V_44 & V_362 )
V_285 = V_505 -> V_524 ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
V_219 = V_220 & 0x07 ;
V_219 = V_219 >> 5 ;
V_285 = V_285 >> 3 ;
V_220 = V_220 >> 3 ;
V_285 &= 0x1f ;
V_219 |= V_285 ;
F_4 ( V_3 -> V_522 , 0x15 , V_219 ) ;
F_4 ( V_3 -> V_522 , 0x14 ,
( unsigned short ) ( V_220 & 0xff ) ) ;
V_219 = V_3 -> V_498 ;
if ( V_3 -> V_44 & V_362 )
V_220 = V_505 -> V_525 ;
else
V_220 = V_493 -> V_525 ;
V_285 = V_3 -> V_354 ;
V_220 = V_220 & 0x0fff ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
F_4 ( V_3 -> V_522 , 0x1b ,
( unsigned short ) ( V_220 & 0xff ) ) ;
F_4 ( V_3 -> V_522 , 0x1c ,
( unsigned short ) ( V_285 & 0xff ) ) ;
V_220 = ( V_220 >> 8 ) & 0x07 ;
V_285 = ( V_285 >> 8 ) & 0x07 ;
F_4 ( V_3 -> V_522 , 0x1d ,
( unsigned short ) ( ( V_285 << 3 )
| V_220 ) ) ;
V_219 = V_3 -> V_498 ;
if ( V_3 -> V_44 & V_362 )
V_220 = V_505 -> V_526 ;
else
V_220 = V_493 -> V_526 ;
V_285 = V_514 ;
if ( V_3 -> V_44 & V_362 )
V_285 = V_505 -> V_527 ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
F_4 ( V_3 -> V_522 , 0x18 ,
( unsigned short ) ( V_220 & 0xff ) ) ;
F_12 ( V_3 -> V_522 , 0x19 , ~ 0x0f ,
( unsigned short ) ( V_285 & 0x0f ) ) ;
V_219 = ( ( V_220 >> 8 ) & 0x07 ) << 3 ;
V_220 = V_3 -> V_353 ;
if ( V_220 != V_3 -> V_354 )
V_219 |= 0x40 ;
if ( V_3 -> V_44 & V_528 )
V_219 |= 0x40 ;
F_12 ( V_3 -> V_522 , 0x1a , 0x07 ,
V_219 ) ;
V_285 = V_3 -> V_495 ;
V_220 = V_3 -> V_354 ;
V_219 = V_3 -> V_353 ;
V_285 -= V_219 ;
V_160 = V_219 ;
V_516 = ( V_160 << 18 ) / V_220 ;
V_356 = ( unsigned short ) ( ( V_160 << 18 ) % V_220 ) ;
if ( V_356 != 0 )
V_516 += 1 ;
V_292 = V_516 ;
V_518 = V_292 ;
F_4 ( V_3 -> V_522 , 0x37 ,
( unsigned short ) ( V_292 & 0xff ) ) ;
F_4 ( V_3 -> V_522 , 0x36 ,
( unsigned short ) ( ( V_292 >> 8 ) & 0xff ) ) ;
V_220 = ( unsigned short ) ( V_292 >> 16 ) ;
V_219 = V_220 & 0x03 ;
V_220 = V_3 -> V_353 ;
if ( V_220 == V_3 -> V_354 )
V_219 |= 0x04 ;
F_4 ( V_3 -> V_522 , 0x35 , V_219 ) ;
if ( V_3 -> V_144 & V_228 ) {
V_292 = V_518 ;
F_4 ( V_3 -> V_529 ,
0x3c ,
( unsigned short ) ( V_292 & 0xff ) ) ;
F_4 ( V_3 -> V_529 ,
0x3b ,
( unsigned short ) ( ( V_292 >> 8 ) &
0xff ) ) ;
V_220 = ( unsigned short ) ( V_292 >> 16 ) ;
F_12 ( V_3 -> V_529 , 0x3a ,
~ 0xc0 ,
( unsigned short ) ( ( V_220 &
0xff ) << 6 ) ) ;
V_285 = V_3 -> V_353 ;
if ( V_285 == V_3 -> V_354 )
F_12 ( V_3 -> V_529 ,
0x30 , ~ 0x0c , 0x00 ) ;
else
F_12 ( V_3 -> V_529 ,
0x30 , ~ 0x0c , 0x08 ) ;
}
V_285 = V_3 -> V_351 ;
V_220 = V_3 -> V_352 ;
V_516 = V_285 << 16 ;
V_219 = ( unsigned short ) ( V_516 / V_220 ) ;
if ( ( V_220 & 0xffff ) == ( V_285 & 0xffff ) )
V_219 = 65535 ;
V_517 = V_219 ;
V_516 = V_3 -> V_351 << 16 ;
V_516 /= V_517 ;
V_517 = V_517 << 16 ;
V_516 -= 1 ;
V_517 = ( V_517 & 0xffff0000 ) + ( V_516 & 0xffff ) ;
V_219 = ( unsigned short ) ( V_517 & 0xff ) ;
F_4 ( V_3 -> V_522 , 0x1f , V_219 ) ;
V_516 = V_3 -> V_353 << 18 ;
V_516 = V_516 / V_518 ;
V_220 = ( unsigned short ) ( V_516 & 0xffff ) ;
if ( V_3 -> V_42 == V_252 )
V_220 -= 1 ;
V_219 = ( ( V_220 >> 8 ) & 0xff ) << 3 ;
V_219 |= ( unsigned short ) ( ( V_517 >> 8 ) & 0x07 ) ;
F_4 ( V_3 -> V_522 , 0x20 ,
( unsigned short ) ( V_219 & 0xff ) ) ;
F_4 ( V_3 -> V_522 , 0x21 ,
( unsigned short ) ( V_220 & 0xff ) ) ;
V_517 = V_517 >> 16 ;
if ( V_194 & V_288 )
V_517 = V_517 >> 1 ;
F_4 ( V_3 -> V_522 , 0x22 ,
( unsigned short ) ( ( V_517 >> 8 ) & 0xff ) ) ;
F_4 ( V_3 -> V_522 , 0x23 ,
( unsigned short ) ( V_517 & 0xff ) ) ;
}
static void F_44 ( unsigned char * V_530 , unsigned char * V_531 ,
struct V_2 * V_3 )
{
unsigned short V_262 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
V_262 = F_41 ( V_3 ) ;
if ( V_3 -> V_45 & V_199 ) {
* V_530 = V_3 -> V_147 [ V_262 ] . V_532 ;
* V_531 = V_3 -> V_147 [ V_262 ] . V_533 ;
} else {
* V_530 = V_3 -> V_147 [ V_262 ] . V_534 ;
* V_531 = V_3 -> V_147 [ V_262 ] . V_535 ;
}
}
return;
}
static unsigned char F_45 ( unsigned short V_218 ,
unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_262 , V_194 ;
unsigned char V_357 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
if ( ( V_3 -> V_239 & V_536 ) &&
( ! ( V_3 -> V_44 & V_362 ) ) ) {
V_262 = F_40 ( V_3 ) ;
V_357 = V_3 -> V_147 [ V_262 ] . V_537 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) )
return V_357 ;
if ( V_3 -> V_144 &
( V_246 |
V_247 |
V_145 |
V_146 |
V_228 ) ) {
if ( V_3 -> V_45 & V_234 ) {
V_357 = V_308 + V_309 ;
if ( ! ( V_3 -> V_46 & V_307 ) )
V_357 = V_308 + V_310 ;
if ( V_3 -> V_46 & V_240 ) {
V_357 = V_308 + V_311 ;
if ( ! ( V_194 & V_208 ) )
V_357 = V_308 + V_312 ;
}
return V_357 ;
}
if ( V_3 -> V_46 & V_538 ) {
V_357 = V_314 ;
return V_357 ;
}
if ( V_3 -> V_46 & V_539 ) {
V_357 = V_316 ;
return V_357 ;
}
V_357 = V_540 ;
if ( ! ( V_3 -> V_46 & V_541 ) ) {
V_357 = V_308 + V_319 ;
if ( ! ( V_3 -> V_46 & V_307 ) )
V_357 = V_308 + V_320 ;
}
if ( V_3 -> V_45 & V_198 )
return V_357 ;
}
}
V_357 = ( unsigned char ) F_7 ( ( V_3 -> V_542 + 0x02 ) ) ;
V_357 = V_357 >> 2 ;
V_357 &= 0x03 ;
if ( ( V_3 -> V_44 & V_362 ) && ( V_194 & V_208 ) )
V_357 = V_357 ^ V_357 ;
V_357 = V_3 -> V_10 [ V_218 ] . V_321 ;
return V_357 ;
}
static void F_46 ( unsigned char V_357 , unsigned char * V_530 ,
unsigned char * V_531 , struct V_2 * V_3 )
{
if ( V_3 -> V_144 & ( V_543 | V_246 | V_247
| V_145 | V_146 | V_228 ) ) {
if ( ( ! ( V_3 -> V_45 & V_197 ) ) && ( V_3 -> V_239
& V_536 ) ) {
* V_530 = ( unsigned char ) V_27 [ V_357 ] . V_216 ;
* V_531 = V_27 [ V_357 ] . V_217 ;
}
} else {
* V_530 = V_24 [ V_357 ] . V_216 ;
* V_531 = V_24 [ V_357 ] . V_217 ;
}
}
static void F_47 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned char V_530 , V_531 , V_357 ;
int V_193 ;
V_357 = F_45 ( V_218 , V_189 , V_190 ,
V_3 ) ;
F_46 ( V_357 , & V_530 , & V_531 , V_3 ) ;
F_44 ( & V_530 , & V_531 , V_3 ) ;
for ( V_193 = 0 ; V_193 < 4 ; V_193 ++ ) {
F_12 ( V_3 -> V_204 , 0x31 , ~ 0x30 ,
( unsigned short ) ( 0x10 * V_193 ) ) ;
if ( ( ! ( V_3 -> V_45 & V_197 ) )
&& ( ! ( V_3 -> V_45 & V_200 ) ) ) {
F_4 ( V_3 -> V_177 , 0x2e , V_530 ) ;
F_4 ( V_3 -> V_177 , 0x2f , V_531 ) ;
} else {
F_4 ( V_3 -> V_177 , 0x2b , V_530 ) ;
F_4 ( V_3 -> V_177 , 0x2c , V_531 ) ;
}
}
}
static void F_48 ( struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_544 , V_545 , V_160 , V_507 , V_219 ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
V_544 = 0 ;
V_545 = 0 ;
V_160 = F_2 ( V_3 -> V_177 , 0x01 ) ;
if ( ! ( V_160 & 0x20 ) ) {
V_160 = F_2 ( V_3 -> V_204 , 0x17 ) ;
if ( V_160 & 0x80 ) {
V_160 = F_2 ( V_3 -> V_204 , 0x53 ) ;
if ( ! ( V_160 & 0x40 ) )
V_544 |= V_546 ;
}
}
V_160 = F_2 ( V_3 -> V_522 , 0x2e ) ;
V_160 &= 0x0f ;
if ( ! ( V_160 == 0x08 ) ) {
V_219 = F_2 ( V_3 -> V_522 , 0x13 ) ;
if ( V_219 & 0x04 )
V_544 = V_544 | V_547 ;
V_160 &= 0x05 ;
if ( ! ( V_544 & V_547 ) )
if ( V_160 == 0x01 )
V_544 |= V_548 ;
if ( V_160 == 0x04 )
V_544 |= V_547 ;
if ( V_160 == 0x05 ) {
V_160 = F_2 ( V_3 -> V_549 , 0x00 ) ;
if ( ! ( V_160 & 0x08 ) )
V_545 |= V_550 ;
if ( ! ( V_160 & 0x04 ) )
V_545 |= V_551 ;
if ( V_160 & 0x02 )
V_545 |= V_552 ;
if ( V_3 -> V_45 & V_234 ) {
if ( V_160 & 0x01 )
V_545 |= V_553 ;
}
if ( V_3 -> V_45 & V_244 ) {
V_160 = F_2 (
V_3 -> V_549 ,
0x4d ) ;
if ( V_160 & 0x10 )
V_545 |= V_554 ;
}
if ( V_545 != 0 )
V_544 |= V_555 ;
}
}
V_160 = F_2 ( V_3 -> V_204 , 0x3d ) ;
if ( V_544 & V_547 ) {
if ( ( V_3 -> V_239 & V_556 ) ) {
if ( V_160 & V_555 )
V_544 |= V_555 ;
}
}
V_160 = V_544 ;
V_507 = ~ V_557 ;
F_12 ( V_3 -> V_204 , 0x3d , V_507 , V_160 ) ;
if ( ! ( V_3 -> V_239 & V_556 ) )
F_4 ( V_3 -> V_204 , 0x3e , V_545 ) ;
} else {
return;
}
}
void F_49 ( struct V_2 * V_3 )
{
unsigned short V_558 , V_220 , V_191 ;
if ( V_3 -> V_225 == 0 ) {
V_220 = V_247 ;
V_558 = F_2 ( V_3 -> V_529 , 0x00 ) ;
if ( V_558 != 0x02 ) {
V_220 = V_543 ;
V_558 = F_2 ( V_3 -> V_529 , 0x01 ) ;
if ( V_558 >= 0xB0 ) {
V_220 = V_246 ;
if ( V_558 >= 0xC0 ) {
V_220 = V_228 ;
if ( V_558 >= 0xD0 ) {
V_220 = V_145 ;
if ( V_558 >= 0xE0 ) {
V_220 = V_146 ;
V_191 = F_2 (
V_3 -> V_529 ,
0x39 ) ;
if ( V_191 != 0xFF )
V_220 =
V_228 ;
}
}
}
if ( V_220 & ( V_246 | V_247 ) ) {
V_558 = F_2 (
V_3 -> V_529 ,
0x23 ) ;
if ( ! ( V_558 & 0x02 ) )
V_220 = V_220 | V_559 ;
}
}
}
V_3 -> V_144 = V_220 ;
}
}
static void F_50 ( unsigned short V_189 , unsigned short V_190 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_219 , V_560 , V_220 , V_160 , V_194 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_3 -> V_239 = 0 ;
V_3 -> V_214 = V_194 & V_561 ;
V_220 = 0 ;
if ( V_3 -> V_144 & 0xFFFF ) {
V_160 = F_2 ( V_3 -> V_204 , 0x30 ) ;
V_220 = V_220 | V_160 ;
V_160 = F_2 ( V_3 -> V_204 , 0x31 ) ;
V_560 = V_160 ;
V_560 = V_560 << 8 ;
V_219 = V_160 << 8 ;
V_220 = V_220 | V_219 ;
V_160 = ( V_562 | V_244 | V_197
| V_200 | V_563 ) ;
V_160 = 0xFFFF ^ V_160 ;
V_220 &= V_160 ;
V_160 = F_2 ( V_3 -> V_204 , 0x38 ) ;
if ( V_3 -> V_564 == 1 ) {
if ( ( V_202 -> V_260 >= V_156 ) ||
( V_202 -> V_260 >= V_565 ) ) {
if ( V_3 -> V_225 == 0 ) {
if ( V_3 -> V_144 &
( V_247 |
V_145 |
V_146 |
V_228 ) ) {
if ( V_160 & V_566 ) {
V_220 |=
V_562 ;
if ( V_160 & V_567 )
V_220 |=
V_197 ;
}
}
}
}
}
if ( V_3 -> V_568 == 1 ) {
if ( ( ( V_3 -> V_225 == 0 ) &&
( ( V_3 -> V_144 & V_145 ) ||
( V_3 -> V_144 & V_146 ) ||
( V_3 -> V_144 & V_228 ) ) ) ) {
if ( V_160 & V_569 ) {
if ( V_3 -> V_570 == 1 ) {
V_160 = F_2 (
V_3 -> V_204 ,
0x35 ) ;
V_160 &= V_571 ;
V_220 |= V_234 ;
if ( V_160 != V_572 ) {
V_220 &=
( ~ V_234 ) ;
V_220 |=
V_244 ;
}
}
}
}
}
V_219 = V_560 ;
if ( V_3 -> V_225 == 0 ) {
if ( V_3 -> V_568 == 1 ) {
if ( V_3 -> V_570 == 1 )
V_160 = 0x09FC ;
else
V_160 = 0x097C ;
} else {
if ( V_3 -> V_570 == 1 )
V_160 = 0x01FC ;
else
V_160 = 0x017C ;
}
} else {
V_160 = V_199 ;
}
if ( ! ( V_220 & V_160 ) ) {
V_219 |= V_563 ;
V_220 = 0 ;
}
if ( V_3 -> V_564 == 1 ) {
if ( ! ( V_3 -> V_144 & V_559 ) ) {
if ( V_220 & V_197 ) {
if ( V_220 & V_573 )
V_220 &= ( ~ ( V_199 |
V_226 |
V_574 ) ) ;
else
V_220 &= ( ~ ( V_199 |
V_226 |
V_198 |
V_574 ) ) ;
}
}
}
if ( ! ( V_220 & ( V_574 | V_573 ) ) ) {
if ( V_3 -> V_575 == 1 ) {
if ( V_220 & V_226 ) {
V_220 &= ( 0xFF00 |
V_226 |
V_574 |
V_573 ) ;
V_220 &= ( 0x00FF | ( ~ V_244 ) ) ;
}
} else {
V_220 &= ( ~ ( V_226 |
V_199 |
V_198 ) ) ;
}
}
if ( ! ( V_3 -> V_144 & V_559 ) ) {
if ( V_220 & V_199 ) {
V_220 &= ( 0xFF00 |
V_199 |
V_574 |
V_573 ) ;
V_220 &= ( 0x00FF | ( ~ V_244 ) ) ;
}
}
if ( V_220 & V_243 ) {
V_220 &= ( 0xFF00 |
V_243 |
V_574 |
V_573 ) ;
V_220 &= ( 0x00FF | ( ~ V_244 ) ) ;
}
if ( V_3 -> V_568 == 1 ) {
if ( V_220 & V_244 )
V_220 &= ( 0xFF00 |
V_574 |
V_573 ) ;
}
if ( V_3 -> V_570 == 1 ) {
if ( V_220 & V_234 )
V_220 &= ( 0xFF00 |
V_234 |
V_574 |
V_573 ) ;
}
if ( V_219 & V_563 ) {
if ( ! ( V_220 & ( V_574 | V_573 ) ) )
V_220 = V_563 ;
}
if ( ! ( V_220 & V_563 ) ) {
if ( ( ! ( V_220 & V_576 ) ) ||
( ! ( V_194 & V_577 ) ) ) {
if ( V_3 -> V_564 == 1 ) {
if ( ! ( V_220 & V_197 ) )
V_220 |= ( V_200 |
V_573 ) ;
}
}
if ( ( V_220 & V_200 ) &&
( V_220 & V_197 ) ) {
V_220 ^= ( V_199 |
V_197 |
V_562 ) ;
V_3 -> V_239 |= V_556 ;
}
}
}
V_3 -> V_45 = V_220 ;
}
static void F_51 ( unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_160 , V_220 = 0 , V_221 = 0 , V_194 , V_578 ;
V_220 = 0 ;
V_221 = 0 ;
if ( V_3 -> V_45 & V_198 ) {
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
if ( V_3 -> V_45 & V_198 ) {
V_160 = F_2 ( V_3 -> V_204 , 0x35 ) ;
V_220 = V_160 ;
if ( V_220 & V_249 ) {
V_220 &= ( V_579 |
V_580 |
V_581 |
V_249 ) ;
if ( V_220 & V_580 )
V_220 &= ~ V_249 ;
} else
V_220 &= ( V_579 |
V_582 |
V_249 ) ;
}
if ( V_3 -> V_225 == 0 ) {
if ( V_3 -> V_45 & V_243 )
V_220 |= V_249 ;
}
if ( V_3 -> V_568 == 1 ) {
if ( V_3 -> V_45 & V_244 ) {
V_578 = F_2 ( V_3 -> V_204 , 0x35 ) ;
V_578 &= V_571 ;
if ( V_578 == V_583 )
V_220 |= V_584 ;
if ( V_578 == V_585 )
V_220 = V_220 | V_539 ;
if ( V_578 == V_586 )
V_220 = V_220 | V_538 ;
}
}
if ( V_3 -> V_570 == 1 ) {
if ( V_3 -> V_45 & V_234 )
V_220 = V_220 | V_587 | V_249 ;
}
if ( V_3 -> V_225 == 0 ) {
if ( ( V_3 -> V_45 & V_200 ) &&
( ! ( V_3 -> V_45 & V_251 ) ) )
V_220 |= V_240 ;
if ( ! ( V_220 & V_249 ) &&
( V_194 > 13 ) &&
( V_221 == 8 ) )
V_220 |= V_541 ;
V_220 |= V_307 ;
if ( V_3 -> V_45 & V_234 ) {
if ( V_3 -> V_45 & V_200 )
V_220 &= ( ~ V_307 ) ;
} else {
if ( V_220 &
( V_539 | V_538 ) )
V_220 &= ( ~ V_307 ) ;
else if ( ! ( V_3 -> V_144 &
( V_246 |
V_247 |
V_145 |
V_146 |
V_228 ) ) ) {
if ( V_220 & V_240 )
V_220 &= ( ~ V_307 ) ;
}
}
}
}
V_3 -> V_46 = V_220 ;
}
static unsigned char F_52 ( unsigned short V_189 ,
unsigned short V_190 , struct V_2 * V_3 )
{
unsigned short V_160 , V_219 , V_220 , V_194 , V_221 = 0 , V_588 ;
V_3 -> V_42 = 0 ;
V_3 -> V_43 = 0 ;
V_3 -> V_44 = 0 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_160 = F_2 ( V_3 -> V_204 , 0x36 ) ;
V_220 = V_160 & 0x0F ;
if ( V_220 == 0 )
V_220 = V_252 ;
if ( ( V_220 == V_252 ) || ( V_220 == V_231 ) ) {
if ( V_3 -> V_45 & V_576 ) {
V_219 = F_2 ( V_3 -> V_204 , 0x33 ) ;
if ( V_3 -> V_45 & V_197 )
V_219 &= 0x0F ;
else
V_219 = V_219 >> 4 ;
if ( ( V_221 == 6 ) || ( V_221 == 9 ) ) {
if ( V_219 >= 3 )
V_220 |= V_589 ;
} else if ( ( V_221 == 7 ) || ( V_221 == 8 ) ) {
if ( V_219 >= 4 )
V_220 |= V_589 ;
}
}
}
V_3 -> V_42 = V_220 ;
if ( ! ( V_3 -> V_45 & ( V_199 | V_197 ) ) )
return 0 ;
V_220 = 0 ;
V_160 = F_2 ( V_3 -> V_204 , 0x37 ) ;
V_160 &= ( V_590 | V_233 | V_591 | V_592 ) ;
V_220 |= V_160 ;
V_588 = F_41 ( V_3 ) ;
V_219 = V_3 -> V_147 [ V_588 ] . V_593 ;
if ( V_3 -> V_225 == 0 ) {
if ( ( ( V_3 -> V_144 & V_146 ) || ( V_3 -> V_144
& V_228 ) ) && ( V_219 & V_594 ) ) {
V_220 |= V_595 ;
}
}
if ( V_3 -> V_225 == 0 ) {
if ( ( V_3 -> V_42 == V_502 ) && ( V_3 -> V_45
& V_199 ) && ( V_221 == 9 ) &&
( ! ( V_220 & V_362 ) ) )
V_220 |= V_500 ;
}
if ( V_3 -> V_596 == 1 ) {
if ( V_194 & V_288 ) {
if ( ! ( V_220 & V_500 ) ) {
V_220 |= V_528 ;
} else {
if ( V_3 -> V_42 == V_252 ) {
if ( V_221 == 4 ) {
V_220 |= V_528 ;
}
}
}
}
}
if ( V_3 -> V_45 & V_200 ) {
if ( V_3 -> V_45 & V_251 )
V_220 |= V_597 ;
} else {
V_220 |= V_597 ;
}
V_3 -> V_44 = V_220 ;
return 1 ;
}
unsigned char F_53 ( unsigned short V_189 ,
unsigned short * V_190 , struct V_2 * V_3 )
{
for ( * V_190 = 0 ; ; ( * V_190 ) ++ ) {
if ( V_3 -> V_7 [ * V_190 ] . V_598 == V_189 )
break;
if ( V_3 -> V_7 [ * V_190 ] . V_598 == 0xFF )
return 0 ;
}
return 1 ;
}
static unsigned char F_54 ( unsigned char V_599 )
{
unsigned char V_600 = 0 ;
unsigned char V_193 = 0 ;
for ( V_193 = 0 ; V_193 < 8 ; V_193 ++ ) {
V_600 = V_600 << 1 ;
V_600 |= ( V_599 >> V_193 ) & 1 ;
}
return V_600 ;
}
static unsigned char F_55 ( struct V_2 * V_3 )
{
unsigned char V_601 , V_160 ;
V_601 = F_2 ( V_3 -> V_204 , 0x4A ) ;
F_13 ( V_3 -> V_204 , 0x4A , ~ 0x23 ) ;
V_160 = F_2 ( V_3 -> V_204 , 0x48 ) ;
V_160 = F_54 ( V_160 ) ;
V_160 &= 0x23 ;
F_4 ( V_3 -> V_204 , 0x4A , V_601 ) ;
return V_160 ;
}
static unsigned char F_56 ( struct V_2 * V_3 )
{
unsigned char V_601 , V_602 , V_160 ;
V_601 = F_2 ( V_3 -> V_204 , 0x4A ) ;
F_13 ( V_3 -> V_204 , 0x4A , ~ 0x0C ) ;
V_160 = F_2 ( V_3 -> V_204 , 0x48 ) ;
V_160 &= 0x0C ;
V_160 >>= 2 ;
F_4 ( V_3 -> V_204 , 0x4A , V_601 ) ;
V_602 = F_2 ( V_3 -> V_204 , 0xB4 ) ;
V_160 |= ( ( V_602 & 0x04 ) << 3 ) ;
return V_160 ;
}
static void F_57 ( unsigned short V_603 , unsigned short V_507 ,
struct V_2 * V_3 )
{
unsigned char V_601 , V_160 ;
V_601 = F_2 ( V_3 -> V_204 , 0x4A ) ;
V_603 &= 0x23 ;
V_507 &= 0x23 ;
F_13 ( V_3 -> V_204 , 0x4A , ~ V_603 ) ;
if ( V_603 & 0x20 ) {
V_160 = ( V_507 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_204 , 0xB4 , ~ 0x02 , V_160 ) ;
}
V_160 = F_2 ( V_3 -> V_204 , 0x48 ) ;
V_160 = F_54 ( V_160 ) ;
V_160 &= ~ V_603 ;
V_160 |= V_507 ;
F_4 ( V_3 -> V_204 , 0x48 , V_160 ) ;
}
static void F_58 ( unsigned short V_603 , unsigned short V_507 ,
struct V_2 * V_3 )
{
unsigned char V_601 , V_160 ;
unsigned short V_604 , V_605 ;
V_604 = V_603 ;
V_605 = V_507 ;
V_604 &= 0x20 ;
V_605 &= 0x20 ;
V_604 >>= 3 ;
V_605 >>= 3 ;
if ( V_603 & 0x20 ) {
V_160 = ( V_507 >> 4 ) & 0x02 ;
F_12 ( V_3 -> V_204 , 0xB4 , ~ 0x02 , V_160 ) ;
}
F_12 ( V_3 -> V_204 , 0xB4 , ~ V_604 , V_605 ) ;
V_601 = F_2 ( V_3 -> V_204 , 0x4A ) ;
V_603 &= 0x03 ;
V_507 &= 0x03 ;
V_603 <<= 2 ;
V_507 <<= 2 ;
F_13 ( V_3 -> V_204 , 0x4A , ~ V_603 ) ;
F_12 ( V_3 -> V_204 , 0x48 , ~ V_603 , V_507 ) ;
}
static void F_59 ( struct V_606 * V_607 ,
unsigned short V_507 ,
struct V_2 * V_3 )
{
if ( V_507 == 1 )
F_60 ( V_607 -> V_608 . V_609 ) ;
if ( V_507 == 2 )
F_60 ( V_607 -> V_608 . V_610 ) ;
if ( V_507 == 3 )
F_60 ( V_607 -> V_608 . V_611 ) ;
if ( V_507 == 4 )
F_60 ( V_607 -> V_608 . V_612 ) ;
}
static void F_61 ( struct V_606 * V_607 ,
struct V_201 * V_613 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_177 , 0x01 , 0xDF , 0x00 ) ;
if ( V_613 -> V_260 == V_328 ) {
if ( V_3 -> V_225 == 1 ) {
if ( ! ( F_55 ( V_3 ) & 0x1 ) ) {
F_57 ( 0x01 , 0x01 , V_3 ) ;
F_59 ( V_607 , 2 , V_3 ) ;
}
if ( ! ( F_55 ( V_3 ) & 0x20 ) )
F_57 ( 0x20 , 0x20 , V_3 ) ;
F_59 ( V_607 , 3 , V_3 ) ;
F_57 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_57 ( 0x20 , 0x20 , V_3 ) ;
}
}
if ( V_613 -> V_260 == V_159 ) {
if ( V_3 -> V_225 == 1 ) {
if ( ! ( F_56 ( V_3 ) & 0x1 ) ) {
F_58 ( 0x01 , 0x01 , V_3 ) ;
F_59 ( V_607 , 2 , V_3 ) ;
}
if ( ! ( F_56 ( V_3 ) & 0x20 ) )
F_58 ( 0x20 , 0x20 , V_3 ) ;
F_59 ( V_607 , 3 , V_3 ) ;
F_58 ( 0x02 , 0x02 , V_3 ) ;
} else {
F_58 ( 0x20 , 0x20 , V_3 ) ;
}
}
}
void F_62 ( struct V_606 * V_607 ,
struct V_201 * V_613 ,
struct V_2 * V_3 )
{
if ( V_613 -> V_260 == V_328 ) {
if ( V_3 -> V_225 == 1 ) {
F_57 ( 0x02 , 0x00 , V_3 ) ;
F_59 ( V_607 , 3 , V_3 ) ;
} else {
F_57 ( 0x20 , 0x00 , V_3 ) ;
}
}
if ( V_613 -> V_260 == V_159 ) {
if ( ( F_56 ( V_3 ) & 0x2 ) ) {
F_58 ( 0x02 , 0x00 , V_3 ) ;
F_59 ( V_607 , 3 , V_3 ) ;
}
if ( V_3 -> V_225 == 0 )
F_58 ( 0x20 , 0x00 , V_3 ) ;
}
F_12 ( V_3 -> V_177 , 0x01 , 0xDF , 0x20 ) ;
}
static void F_63 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 -> V_209 ) & 0x01 ) )
break;
while ( ! ( F_7 ( V_3 -> V_209 ) & 0x01 ) )
break;
}
static void F_64 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_522 , 0x01 , 0x40 ) ;
}
static void F_65 ( unsigned short V_189 ,
struct V_2 * V_3 )
{
unsigned short V_516 , V_292 ;
F_4 ( V_3 -> V_204 , 0x34 , V_189 ) ;
V_516 = ( V_3 -> V_45 & V_200 ) >> 8 ;
V_292 = ~ ( V_200 >> 8 ) ;
F_12 ( V_3 -> V_204 , 0x31 , V_292 , V_516 ) ;
}
static void F_66 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_332 , V_350 , V_194 , V_284 ;
V_284 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_332 = V_3 -> V_33 [ V_284 ] . V_286 ;
V_350 = V_3 -> V_33 [ V_284 ] . V_287 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
if ( V_194 & V_288 )
V_332 *= 2 ;
if ( V_194 & V_261 )
V_350 *= 2 ;
if ( V_3 -> V_45 & V_199 ) {
if ( V_3 -> V_225 == 0 ) {
if ( V_3 -> V_42 == V_614 ) {
if ( ! ( V_3 -> V_44 & V_597 ) ) {
if ( V_350 == 1024 )
V_350 = 1056 ;
}
}
if ( V_3 -> V_42 == V_231 ) {
if ( V_350 == 400 )
V_350 = 405 ;
else if ( V_350 == 350 )
V_350 = 360 ;
if ( V_3 -> V_44 & V_597 ) {
if ( V_350 == 360 )
V_350 = 375 ;
}
}
if ( V_3 -> V_42 == V_252 ) {
if ( ! ( V_3 -> V_44 & V_597 ) ) {
if ( ! ( V_3 -> V_44
& V_233 ) ) {
if ( V_350 == 350 )
V_350 = 357 ;
else if ( V_350 == 400 )
V_350 = 420 ;
else if ( V_350 == 480 )
V_350 = 525 ;
}
}
}
}
if ( V_332 == 720 )
V_332 = 640 ;
}
V_3 -> V_351 = V_332 ;
V_3 -> V_352 = V_332 ;
V_3 -> V_353 = V_350 ;
V_3 -> V_354 = V_350 ;
}
static unsigned char F_67 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_45 & ( V_199 | V_197 ) ) &&
( V_3 -> V_44 & V_595 ) )
return 1 ;
return 0 ;
}
static void F_68 ( unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_219 , V_220 , V_516 , V_292 , V_194 = 0 , V_285 ,
V_615 ;
V_3 -> V_616 = 1 ;
V_3 -> V_617 = 1 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_615 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_615 &= V_264 ;
V_516 = ( unsigned short ) V_3 -> V_13 [ V_615 ] . V_265 [ 0 ] ;
V_292 = ( unsigned short ) V_3 -> V_13 [ V_615 ] . V_265 [ 5 ] ;
V_219 = ( V_516 & 0xFF ) | ( ( V_292 & 0x03 ) << 8 ) ;
V_220 = ( unsigned short ) V_3 -> V_13 [ V_615 ] . V_265 [ 8 ] ;
V_285 = ( unsigned short )
V_3 -> V_13 [ V_615 ] . V_265 [ 14 ] << 8 ;
V_285 &= 0x0100 ;
V_285 = V_285 << 2 ;
V_220 |= V_285 ;
V_516 = ( unsigned short ) V_3 -> V_13 [ V_615 ] . V_265 [ 9 ] ;
if ( V_516 & 0x01 )
V_220 |= 0x0100 ;
if ( V_516 & 0x20 )
V_220 |= 0x0200 ;
V_219 += 5 ;
if ( V_194 & V_208 )
V_219 *= 8 ;
else
V_219 *= 9 ;
V_3 -> V_494 = V_219 ;
V_3 -> V_496 = V_219 ;
V_220 ++ ;
V_3 -> V_495 = V_220 ;
V_3 -> V_498 = V_220 ;
}
static void F_69 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_219 = 0 , V_220 , V_194 , V_221 ;
struct V_618 * V_493 = NULL ;
struct V_619 * V_620 = NULL ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_3 -> V_621 = 0 ;
V_3 -> V_622 = 50 ;
if ( V_3 -> V_45 & V_226 ) {
F_68 ( V_189 , V_190 , V_218 ,
V_3 ) ;
return;
}
V_220 = 4 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
V_493 = (struct V_618 * ) F_36 ( V_220 ,
V_189 , V_190 , V_218 ,
V_3 ) ;
V_3 -> V_616 = V_493 -> V_616 ;
V_3 -> V_617 = V_493 -> V_617 ;
V_3 -> V_494 = V_493 -> V_494 ;
V_3 -> V_495 = V_493 -> V_495 ;
V_3 -> V_496 = V_493 -> V_497 ;
V_3 -> V_498 = V_493 -> V_499 ;
if ( V_3 -> V_42 == V_252 ) {
V_219 = 1024 ;
V_220 = 768 ;
if ( ! ( V_3 -> V_44 & V_597 ) ) {
if ( V_3 -> V_353 == 357 )
V_220 = 527 ;
else if ( V_3 -> V_353 == 420 )
V_220 = 620 ;
else if ( V_3 -> V_353 == 525 )
V_220 = 775 ;
else if ( V_3 -> V_353 == 600 )
V_220 = 775 ;
else
V_220 = 768 ;
} else
V_220 = 768 ;
} else if ( V_3 -> V_42 == V_324 ) {
V_219 = 1024 ;
V_220 = 768 ;
} else if ( V_3 -> V_42 == V_231 ) {
V_219 = 1280 ;
if ( V_3 -> V_353 == 360 )
V_220 = 768 ;
else if ( V_3 -> V_353 == 375 )
V_220 = 800 ;
else if ( V_3 -> V_353 == 405 )
V_220 = 864 ;
else
V_220 = 1024 ;
} else if ( V_3 -> V_42 == V_501 ) {
V_219 = 1280 ;
V_220 = 1024 ;
} else if ( V_3 -> V_42 == V_232 ) {
V_219 = 1280 ;
if ( V_3 -> V_353 == 350 )
V_220 = 700 ;
else if ( V_3 -> V_353 == 400 )
V_220 = 800 ;
else if ( V_3 -> V_353 == 1024 )
V_220 = 960 ;
else
V_220 = 960 ;
} else if ( V_3 -> V_42 == V_502 ) {
V_219 = 1400 ;
V_220 = 1050 ;
if ( V_3 -> V_353 == 1024 ) {
V_219 = 1280 ;
V_220 = 1024 ;
}
} else if ( V_3 -> V_42 == V_614 ) {
V_219 = 1600 ;
V_220 = 1200 ;
if ( ! ( V_3 -> V_44 & V_597 ) ) {
if ( V_3 -> V_353 == 350 )
V_220 = 875 ;
else if ( V_3 -> V_353 == 400 )
V_220 = 1000 ;
}
}
if ( V_3 -> V_44 & V_233 ) {
V_219 = V_3 -> V_351 ;
V_220 = V_3 -> V_353 ;
}
V_3 -> V_352 = V_219 ;
V_3 -> V_354 = V_220 ;
return;
}
if ( V_3 -> V_45 & ( V_198 ) ) {
V_220 = 4 ;
V_620 = (struct V_619 * ) F_37 ( V_220 ,
V_189 , V_190 , V_218 ,
V_3 ) ;
V_3 -> V_616 = V_620 -> V_616 ;
V_3 -> V_617 = V_620 -> V_617 ;
V_3 -> V_494 = V_620 -> V_494 ;
V_3 -> V_495 = V_620 -> V_495 ;
V_3 -> V_352 = V_620 -> V_623 ;
V_3 -> V_354 = V_620 -> V_624 ;
V_3 -> V_622 = V_620 -> V_622 ;
V_3 -> V_621 = V_620 -> V_625 ;
if ( V_3 -> V_45 & V_234 ) {
if ( V_221 == 0x08 )
V_3 -> V_621 = 0x40 ;
else if ( V_221 == 0x09 )
V_3 -> V_621 = 0x40 ;
else if ( V_221 == 0x12 )
V_3 -> V_621 = 0x40 ;
if ( V_3 -> V_353 == 350 )
V_3 -> V_46 |= V_240 ;
V_219 = V_626 ;
V_220 = V_627 ;
if ( V_3 -> V_45 & V_200 ) {
if ( V_3 -> V_46 & V_240 ) {
V_219 = V_628 ;
V_220 = V_629 ;
if ( ! ( V_194 & V_208 ) ) {
V_219 = V_630 ;
V_220 = V_631 ;
}
}
}
} else if ( V_3 -> V_45 & V_244 ) {
if ( V_3 -> V_46 & V_538 ) {
V_219 = V_632 ;
V_220 = V_633 ;
}
if ( V_3 -> V_46 & V_539 ) {
V_219 = V_634 ;
V_220 = V_635 ;
} else if ( V_3 -> V_46 & V_584 ) {
V_219 = V_636 ;
V_220 = V_637 ;
if ( V_3 -> V_46 & V_541 )
V_219 = V_638 ;
}
} else {
V_219 = V_639 ;
V_220 = V_640 ;
if ( ! ( V_3 -> V_46 & V_249 ) ) {
V_219 = V_641 ;
V_220 = V_642 ;
if ( V_3 -> V_46 & V_541 )
V_219 = V_638 ;
}
}
V_3 -> V_496 = V_219 ;
V_3 -> V_498 = V_220 ;
return;
}
}
static void F_70 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned char V_530 , V_531 , V_357 ;
V_357 = F_45 ( V_218 , V_189 , V_190 ,
V_3 ) ;
F_46 ( V_357 , & V_530 , & V_531 , V_3 ) ;
F_44 ( & V_530 , & V_531 , V_3 ) ;
if ( V_3 -> V_144 & V_543 ) {
F_4 ( V_3 -> V_529 , 0x0A , 0x10 ) ;
F_4 ( V_3 -> V_529 , 0x0B , V_531 ) ;
F_4 ( V_3 -> V_529 , 0x0A , V_530 ) ;
} else {
F_4 ( V_3 -> V_529 , 0x0A , V_530 ) ;
F_4 ( V_3 -> V_529 , 0x0B , V_531 ) ;
}
F_4 ( V_3 -> V_529 , 0x00 , 0x12 ) ;
if ( V_3 -> V_45 & V_226 )
F_20 ( V_3 -> V_529 , 0x12 , 0x28 ) ;
else
F_20 ( V_3 -> V_529 , 0x12 , 0x08 ) ;
}
static unsigned short F_71 ( unsigned short V_189 ,
unsigned short V_190 , struct V_2 * V_3 )
{
unsigned short V_643 [ 6 ] = { 1 , 2 , 4 , 4 , 6 , 8 } ;
short V_262 ;
unsigned short V_194 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_262 = ( V_194 & V_561 ) - V_295 ;
if ( V_262 < 0 )
V_262 = 0 ;
return V_643 [ V_262 ] ;
}
static unsigned short F_72 ( unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_160 , V_644 , V_645 , V_262 , V_222 ,
V_643 [] = { 0x01 , 0x02 , 0x04 } ;
V_645 = V_3 -> V_7 [ V_190 ] . V_294 ;
V_222 = V_3 -> V_10 [ V_218 ] . V_253 ;
V_262 = ( V_645 >> 8 ) & 0xFF ;
V_160 = V_3 -> V_28 [ V_262 ] ;
if ( V_222 & V_289 )
V_160 = V_160 << 1 ;
V_644 = F_71 ( V_189 , V_190 , V_3 ) ;
if ( ( V_189 >= 0x7C ) && ( V_189 <= 0x7E ) ) {
V_160 = V_189 - 0x7C ;
V_644 = V_643 [ V_160 ] ;
V_160 = 0x6B ;
if ( V_222 & V_289 )
V_160 = V_160 << 1 ;
return V_160 * V_644 ;
} else {
return V_160 * V_644 ;
}
}
static void F_73 ( unsigned short V_189 ,
unsigned short V_190 ,
unsigned short V_218 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_646 ;
unsigned char V_160 ;
if ( V_3 -> V_45 & V_200 )
return;
V_646 = F_72 ( V_189 , V_190 , V_218 ,
V_202 , V_3 ) ;
V_160 = ( unsigned char ) ( V_646 & 0xFF ) ;
F_4 ( V_3 -> V_522 , 0x07 , V_160 ) ;
V_160 = ( unsigned char ) ( ( V_646 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_522 , 0x09 , V_160 ) ;
V_160 = ( unsigned char ) ( ( ( V_646 >> 3 ) & 0xFF ) + 1 ) ;
F_4 ( V_3 -> V_522 , 0x03 , V_160 ) ;
}
static void F_74 ( struct V_2 * V_3 )
{
F_4 ( V_3 -> V_522 , 0x01 , 0x3B ) ;
F_12 ( V_3 -> V_522 , 0x02 , ~ ( 0x3F ) , 0x04 ) ;
}
static void F_75 ( unsigned short V_189 , unsigned short V_190 ,
struct V_201 * V_202 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_285 = 0 , V_615 = 0 , V_221 = 0 ;
V_615 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_615 &= V_264 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
F_73 ( V_189 , V_190 , V_218 ,
V_202 , V_3 ) ;
F_74 ( V_3 ) ;
for ( V_285 = 4 ; V_285 < 7 ; V_285 ++ )
F_4 ( V_3 -> V_522 , V_285 , 0x0 ) ;
F_4 ( V_3 -> V_522 , 0x50 , 0x00 ) ;
F_4 ( V_3 -> V_522 , 0x02 , 0x44 ) ;
}
static void F_76 ( unsigned short V_189 , unsigned short V_190 ,
struct V_201 * V_202 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_160 = 0 , V_219 = 0 , V_220 = 0 , V_285 = 0 ,
V_647 = 0 , V_615 = 0 , V_194 , V_221 = 0 ;
V_615 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_615 &= V_264 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
if ( V_194 & V_288 ) {
V_160 = ( V_3 -> V_494 / 2 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_522 , 0x08 , V_160 ) ;
V_160 = ( ( ( V_3 -> V_494 / 2 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_522 , 0x09 , ~ 0x0F0 , V_160 ) ;
V_160 = ( V_3 -> V_351 / 2 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_522 , 0x0A , V_160 ) ;
V_285 = ( ( V_3 -> V_494 - V_3 -> V_351 ) / 2 ) >> 2 ;
V_647 = V_3 -> V_351 / 2 + 16 ;
V_285 = V_285 >> 1 ;
V_220 = V_647 + V_285 ;
V_285 += V_220 ;
if ( V_3 -> V_45 & V_226 ) {
V_220 = V_3 -> V_13 [ V_615 ] . V_265 [ 4 ] ;
V_220 |= ( ( V_3 ->
V_13 [ V_615 ] . V_265 [ 14 ] &
0xC0 ) << 2 ) ;
V_220 = ( V_220 - 3 ) << 3 ;
V_285 = V_3 -> V_13 [ V_615 ] . V_265 [ 5 ] ;
V_285 &= 0x1F ;
V_160 = V_3 -> V_13 [ V_615 ] . V_265 [ 15 ] ;
V_160 = ( V_160 & 0x04 ) << ( 5 - 2 ) ;
V_285 = ( ( V_285 | V_160 ) - 3 ) << 3 ;
}
V_220 += 4 ;
V_285 += 4 ;
if ( V_285 > ( V_3 -> V_494 / 2 ) )
V_285 = V_3 -> V_494 / 2 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0B , V_160 ) ;
} else {
V_160 = ( V_3 -> V_494 - 1 ) & 0x0FF ;
F_4 ( V_3 -> V_522 , 0x08 , V_160 ) ;
V_160 = ( ( ( V_3 -> V_494 - 1 ) & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_522 , 0x09 , ~ 0x0F0 , V_160 ) ;
V_160 = ( V_3 -> V_351 + 16 ) & 0x0FF ;
F_4 ( V_3 -> V_522 , 0x0A , V_160 ) ;
V_285 = ( V_3 -> V_494 - V_3 -> V_351 ) >> 2 ;
V_647 = V_3 -> V_351 + 16 ;
V_285 = V_285 >> 1 ;
V_220 = V_647 + V_285 ;
V_285 += V_220 ;
if ( V_3 -> V_45 & V_226 ) {
V_220 = V_3 -> V_13 [ V_615 ] . V_265 [ 3 ] ;
V_220 |= ( ( V_3 ->
V_13 [ V_615 ] . V_265 [ 5 ] &
0xC0 ) << 2 ) ;
V_220 = ( V_220 - 3 ) << 3 ;
V_285 = V_3 -> V_13 [ V_615 ] . V_265 [ 4 ] ;
V_285 &= 0x1F ;
V_160 = V_3 -> V_13 [ V_615 ] . V_265 [ 6 ] ;
V_160 = ( V_160 & 0x04 ) << ( 5 - 2 ) ;
V_285 = ( ( V_285 | V_160 ) - 3 ) << 3 ;
V_220 += 16 ;
V_285 += 16 ;
}
if ( V_285 > V_3 -> V_494 )
V_285 = V_3 -> V_494 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0B , V_160 ) ;
}
V_219 = ( V_219 & 0x00FF ) | ( V_220 & 0xFF00 ) ;
V_220 = V_647 ;
V_220 = ( V_220 & 0x00FF ) | ( ( V_220 & 0xFF00 ) << 4 ) ;
V_219 |= ( V_220 & 0xFF00 ) ;
V_160 = ( V_219 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_522 , 0x0C , V_160 ) ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0D , V_160 ) ;
V_285 = ( V_3 -> V_495 - 1 ) ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0E , V_160 ) ;
V_220 = V_3 -> V_353 - 1 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0F , V_160 ) ;
V_160 = ( ( V_220 & 0xFF00 ) << 3 ) >> 8 ;
V_160 |= ( ( V_285 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_522 , 0x12 , V_160 ) ;
V_219 = V_3 -> V_353 ;
V_220 = V_3 -> V_353 ;
V_285 = V_3 -> V_495 ;
V_220 = ( V_3 -> V_495 + V_3 -> V_353 ) >> 1 ;
V_285 = ( ( V_3 -> V_495 - V_3 -> V_353 ) >> 4 ) + V_220 + 1 ;
if ( V_3 -> V_45 & V_226 ) {
V_220 = V_3 -> V_13 [ V_615 ] . V_265 [ 10 ] ;
V_160 = V_3 -> V_13 [ V_615 ] . V_265 [ 9 ] ;
if ( V_160 & 0x04 )
V_220 |= 0x0100 ;
if ( V_160 & 0x080 )
V_220 |= 0x0200 ;
V_160 = V_3 -> V_13 [ V_615 ] . V_265 [ 14 ] ;
if ( V_160 & 0x08 )
V_220 |= 0x0400 ;
V_160 = V_3 -> V_13 [ V_615 ] . V_265 [ 11 ] ;
V_285 = ( V_285 & 0xFF00 ) | ( V_160 & 0x00FF ) ;
}
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x10 , V_160 ) ;
V_160 = ( ( V_220 & 0xFF00 ) >> 8 ) << 4 ;
V_160 = ( ( V_285 & 0x000F ) | ( V_160 ) ) ;
F_4 ( V_3 -> V_522 , 0x11 , V_160 ) ;
V_219 = 0 ;
if ( V_194 & V_261 )
V_219 |= 0x80 ;
if ( V_194 & V_288 )
V_219 |= 0x40 ;
F_12 ( V_3 -> V_522 , 0x2C , ~ 0x0C0 , V_219 ) ;
}
static unsigned short F_77 ( struct V_2 * V_3 )
{
unsigned long V_219 , V_220 ;
V_220 = ( ( V_3 -> V_495 - V_3 -> V_353 ) * V_3 -> V_616 )
& 0xFFFF ;
V_219 = ( V_3 -> V_498 - V_3 -> V_354 ) * V_3 -> V_617 ;
V_219 = ( V_219 * V_3 -> V_496 ) / V_220 ;
return ( unsigned short ) V_219 ;
}
static void F_78 ( unsigned short V_189 , unsigned short V_190 ,
struct V_201 * V_202 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_514 , V_515 , V_219 , V_220 = 0 , V_285 , V_160 , V_221 ,
V_194 , V_615 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_615 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_615 &= V_264 ;
if ( ! ( V_3 -> V_45 & V_200 ) )
return;
V_160 = 0xFF ;
F_4 ( V_3 -> V_522 , 0x03 , V_160 ) ;
V_285 = 0x08 ;
if ( V_3 -> V_144 & ( V_145 | V_146 | V_228 ) )
V_194 |= V_208 ;
V_219 = V_3 -> V_351 ;
if ( V_194 & V_288 )
V_219 = V_219 >> 1 ;
V_219 = ( V_219 / V_285 ) - 1 ;
V_220 |= ( ( V_219 & 0x00FF ) << 8 ) ;
V_160 = V_219 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x04 , V_160 ) ;
V_160 = ( V_220 & 0xFF00 ) >> 8 ;
if ( V_3 -> V_45 & V_198 ) {
if ( ! ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) )
V_160 += 2 ;
if ( V_3 -> V_45 & V_234 ) {
if ( V_3 -> V_144 & V_145 ) {
if ( V_3 -> V_235 == V_236 ) {
if ( V_221 == 7 )
V_160 -= 2 ;
}
} else if ( V_221 == 7 ) {
V_160 -= 2 ;
}
}
}
F_4 ( V_3 -> V_522 , 0x05 , V_160 ) ;
F_4 ( V_3 -> V_522 , 0x06 , 0x03 ) ;
if ( ! ( V_3 -> V_45 & V_563 ) ) {
if ( V_3 -> V_45 & V_198 )
V_219 = V_3 -> V_494 ;
else
V_219 = F_77 ( V_3 ) ;
}
if ( V_219 >= V_3 -> V_494 )
V_219 = V_3 -> V_494 ;
if ( V_194 & V_288 )
V_219 = V_219 >> 1 ;
V_219 = ( V_219 / V_285 ) - 5 ;
V_285 = V_219 ;
if ( V_3 -> V_45 & V_234 ) {
V_160 = ( V_220 & 0x00FF ) - 1 ;
if ( ! ( V_194 & V_288 ) ) {
V_160 -= 6 ;
if ( V_3 -> V_46 & V_240 ) {
V_160 -= 4 ;
V_160 -= 10 ;
}
}
} else {
V_220 = ( V_220 & 0xFF00 ) >> 8 ;
V_285 = ( V_285 + V_220 ) >> 1 ;
V_160 = ( V_285 & 0x00FF ) + 2 ;
if ( V_3 -> V_45 & V_198 ) {
V_160 -= 1 ;
if ( ! ( V_194 & V_288 ) ) {
if ( ( V_194 & V_208 ) ) {
V_160 += 4 ;
if ( V_3 -> V_351 >= 800 )
V_160 -= 6 ;
}
}
} else if ( ! ( V_194 & V_288 ) ) {
V_160 -= 4 ;
if ( V_3 -> V_42 != V_232 &&
V_3 -> V_351 >= 800 ) {
V_160 -= 7 ;
if ( V_3 -> V_351 >= 1280 &&
V_3 -> V_42 != V_232 &&
( V_3 -> V_44 & V_233 ) )
V_160 += 28 ;
}
}
}
F_4 ( V_3 -> V_522 , 0x07 , V_160 ) ;
F_4 ( V_3 -> V_522 , 0x08 , 0 ) ;
if ( V_3 -> V_45 & V_198 ) {
if ( V_3 -> V_46 & V_240 ) {
if ( V_189 == 0x50 ) {
if ( V_3 -> V_46 & V_648 ) {
F_4 ( V_3 -> V_522 ,
0x07 , 0x30 ) ;
F_4 ( V_3 -> V_522 ,
0x08 , 0x03 ) ;
} else {
F_4 ( V_3 -> V_522 ,
0x07 , 0x2f ) ;
F_4 ( V_3 -> V_522 ,
0x08 , 0x02 ) ;
}
}
}
}
F_4 ( V_3 -> V_522 , 0x18 , 0x03 ) ;
F_12 ( V_3 -> V_522 , 0x19 , 0xF0 , 0x00 ) ;
F_4 ( V_3 -> V_522 , 0x09 , 0xFF ) ;
V_220 = V_3 -> V_495 ;
V_514 = V_220 ;
V_285 = 0x121 ;
V_220 = V_3 -> V_353 ;
if ( V_220 == 357 )
V_220 = 350 ;
if ( V_220 == 360 )
V_220 = 350 ;
if ( V_220 == 375 )
V_220 = 350 ;
if ( V_220 == 405 )
V_220 = 400 ;
if ( V_220 == 525 )
V_220 = 480 ;
V_515 = V_220 ;
if ( V_3 -> V_45 & V_199 ) {
if ( V_3 -> V_42 == V_252 ) {
if ( ! ( V_3 -> V_44 & V_597 ) ) {
if ( V_220 == 350 )
V_220 += 5 ;
if ( V_220 == 480 )
V_220 += 5 ;
}
}
}
V_220 -- ;
V_160 = V_220 & 0x00FF ;
V_220 -- ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x10 , V_160 ) ;
V_220 = V_515 ;
V_220 -- ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0E , V_160 ) ;
if ( V_220 & 0x0100 )
V_285 |= 0x0002 ;
V_219 = 0x000B ;
if ( V_194 & V_261 )
V_219 |= 0x08000 ;
if ( V_220 & 0x0200 )
V_285 |= 0x0040 ;
V_160 = ( V_219 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_522 , 0x0B , V_160 ) ;
if ( V_220 & 0x0400 )
V_285 |= 0x0600 ;
F_4 ( V_3 -> V_522 , 0x11 , 0x00 ) ;
V_219 = V_514 ;
V_219 -= V_220 ;
V_219 = V_219 >> 2 ;
V_514 = V_219 ;
if ( V_221 != 0x09 ) {
V_219 = V_219 << 1 ;
V_220 += V_219 ;
}
if ( V_3 -> V_45 & V_234 ) {
if ( V_3 -> V_144 & V_145 ) {
if ( V_3 -> V_46 & V_587 ) {
V_220 -= 10 ;
} else {
if ( V_3 -> V_46 & V_240 ) {
if ( V_3 -> V_46 & V_249 ) {
if ( V_3 -> V_144 &
V_145 ) {
if ( ! ( V_3 -> V_46 &
( V_539 |
V_538 |
V_587 ) ) )
V_220 += 40 ;
} else {
V_220 += 40 ;
}
}
}
}
} else {
V_220 -= 10 ;
}
} else {
if ( V_3 -> V_46 & V_240 ) {
if ( V_3 -> V_46 & V_249 ) {
if ( V_3 -> V_144 & V_145 ) {
if ( ! ( V_3 -> V_46 &
( V_539 |
V_538 |
V_587 ) ) )
V_220 += 40 ;
} else {
V_220 += 40 ;
}
}
}
}
V_219 = V_514 ;
V_219 = V_219 >> 2 ;
V_219 ++ ;
V_219 += V_220 ;
V_514 = V_219 ;
if ( ( V_3 -> V_46 & V_249 ) ) {
if ( V_220 <= 513 ) {
if ( V_219 >= 513 )
V_220 = 513 ;
}
}
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0C , V_160 ) ;
V_220 -- ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x10 , V_160 ) ;
if ( V_220 & 0x0100 )
V_285 |= 0x0008 ;
if ( V_220 & 0x0200 )
F_12 ( V_3 -> V_522 , 0x0B , 0x0FF , 0x20 ) ;
V_220 ++ ;
if ( V_220 & 0x0100 )
V_285 |= 0x0004 ;
if ( V_220 & 0x0200 )
V_285 |= 0x0080 ;
if ( V_220 & 0x0400 )
V_285 |= 0x0C00 ;
V_220 = V_514 ;
V_160 = V_220 & 0x00FF ;
V_160 &= 0x0F ;
F_4 ( V_3 -> V_522 , 0x0D , V_160 ) ;
if ( V_220 & 0x0010 )
V_285 |= 0x2000 ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_522 , 0x0A , V_160 ) ;
V_160 = ( V_285 & 0x0FF00 ) >> 8 ;
F_4 ( V_3 -> V_522 , 0x17 , V_160 ) ;
V_219 = V_194 ;
V_160 = ( V_219 & 0xFF00 ) >> 8 ;
V_160 = ( V_160 >> 1 ) & 0x09 ;
if ( V_3 -> V_144 & ( V_145 | V_146 | V_228 ) )
V_160 |= 0x01 ;
F_4 ( V_3 -> V_522 , 0x16 , V_160 ) ;
F_4 ( V_3 -> V_522 , 0x0F , 0 ) ;
F_4 ( V_3 -> V_522 , 0x12 , 0 ) ;
if ( V_3 -> V_44 & V_649 )
V_160 = 0x80 ;
else
V_160 = 0x00 ;
F_4 ( V_3 -> V_522 , 0x1A , V_160 ) ;
return;
}
static void F_79 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_193 , V_259 , V_219 , V_220 , V_285 , V_160 , V_514 , V_515 ,
V_194 , V_221 , V_650 ;
unsigned char * V_651 ;
unsigned long V_652 , V_653 , V_654 , V_292 , V_655 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_650 = V_3 -> V_10 [ V_218 ] . V_306 ;
V_219 = 0 ;
if ( ! ( V_3 -> V_45 & V_241 ) )
V_219 |= 0x0800 ;
if ( ! ( V_3 -> V_45 & V_242 ) )
V_219 |= 0x0400 ;
if ( V_3 -> V_45 & V_243 )
V_219 |= 0x0200 ;
if ( ! ( V_3 -> V_46 & V_249 ) )
V_219 |= 0x1000 ;
if ( V_3 -> V_45 & V_234 )
V_219 |= 0x0100 ;
if ( V_3 -> V_46 & ( V_539 | V_538 ) )
V_219 &= 0xfe00 ;
V_219 = ( V_219 & 0xff00 ) >> 8 ;
F_4 ( V_3 -> V_549 , 0x0 , V_219 ) ;
V_651 = V_3 -> V_107 ;
if ( V_3 -> V_46 & V_249 )
V_651 = V_3 -> V_109 ;
if ( V_3 -> V_45 & V_234 ) {
V_651 = V_3 -> V_111 ;
if ( V_3 -> V_45 & V_200 )
V_651 = V_3 -> V_115 ;
if ( V_3 -> V_239 & V_240 )
V_651 = V_3 -> V_113 ;
if ( ! ( V_194 & V_208 ) )
V_651 = V_3 -> V_117 ;
}
if ( V_3 -> V_45 & V_244 ) {
if ( V_3 -> V_46 & V_584 )
V_651 = V_3 -> V_123 ;
if ( V_3 -> V_46 & V_539 )
V_651 = V_3 -> V_121 ;
if ( V_3 -> V_46 & V_538 )
V_651 = V_3 -> V_119 ;
}
for ( V_193 = 0x01 , V_259 = 0 ; V_193 <= 0x2D ; V_193 ++ , V_259 ++ )
F_4 ( V_3 -> V_549 , V_193 , V_651 [ V_259 ] ) ;
for ( V_193 = 0x39 ; V_193 <= 0x45 ; V_193 ++ , V_259 ++ )
F_4 ( V_3 -> V_549 , V_193 , V_651 [ V_259 ] ) ;
if ( V_3 -> V_45 & V_198 )
F_12 ( V_3 -> V_549 , 0x3A , 0x1F , 0x00 ) ;
V_160 = V_3 -> V_621 ;
V_160 &= 0x80 ;
F_12 ( V_3 -> V_549 , 0x0A , 0xFF , V_160 ) ;
if ( V_3 -> V_45 & V_234 )
V_219 = 950 ;
if ( V_3 -> V_46 & V_249 )
V_219 = 520 ;
else
V_219 = 440 ;
if ( V_3 -> V_354 <= V_219 ) {
V_219 -= V_3 -> V_354 ;
V_219 = V_219 >> 2 ;
V_219 = ( V_219 & 0x00FF ) | ( ( V_219 & 0x00FF ) << 8 ) ;
V_514 = V_219 ;
V_160 = ( V_219 & 0xFF00 ) >> 8 ;
V_160 += ( unsigned short ) V_651 [ 0 ] ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
if ( V_3 -> V_45 & ( V_241
| V_242 | V_243
| V_244 ) ) {
V_285 = V_3 -> V_351 ;
if ( V_285 >= 1024 ) {
V_160 = 0x17 ;
if ( V_3 -> V_46 & V_249 )
V_160 = 0x19 ;
}
}
}
F_4 ( V_3 -> V_549 , 0x01 , V_160 ) ;
V_219 = V_514 ;
V_160 = ( V_219 & 0xFF00 ) >> 8 ;
V_160 += V_651 [ 1 ] ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
if ( ( V_3 -> V_45 & ( V_241
| V_242 | V_243
| V_244 ) ) ) {
V_285 = V_3 -> V_351 ;
if ( V_285 >= 1024 ) {
V_160 = 0x1D ;
if ( V_3 -> V_46 & V_249 )
V_160 = 0x52 ;
}
}
}
F_4 ( V_3 -> V_549 , 0x02 , V_160 ) ;
}
V_285 = V_3 -> V_496 ;
if ( F_67 ( V_3 ) )
V_285 = V_285 >> 1 ;
V_285 -= 2 ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x1B , V_160 ) ;
V_160 = ( V_285 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_549 , 0x1D , ~ 0x0F , V_160 ) ;
V_285 = V_3 -> V_496 >> 1 ;
V_514 = V_285 ;
V_285 += 7 ;
if ( V_3 -> V_45 & V_234 )
V_285 -= 4 ;
V_160 = V_285 & 0x00FF ;
V_160 = V_160 << 4 ;
F_12 ( V_3 -> V_549 , 0x22 , 0x0F , V_160 ) ;
V_220 = V_651 [ V_259 ] | ( ( V_651 [ V_259 + 1 ] ) << 8 ) ;
V_220 += V_285 ;
V_515 = V_220 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x24 , V_160 ) ;
V_160 = ( V_220 & 0xFF00 ) >> 8 ;
V_160 = V_160 << 4 ;
F_12 ( V_3 -> V_549 , 0x25 , 0x0F , V_160 ) ;
V_220 = V_515 ;
V_220 = V_220 + 8 ;
if ( V_3 -> V_45 & V_234 ) {
V_220 = V_220 - 4 ;
V_285 = V_220 ;
}
V_160 = ( V_220 & 0x00FF ) << 4 ;
F_12 ( V_3 -> V_549 , 0x29 , 0x0F , V_160 ) ;
V_259 += 2 ;
V_285 += ( V_651 [ V_259 ] | ( ( V_651 [ V_259 + 1 ] ) << 8 ) ) ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x27 , V_160 ) ;
V_160 = ( ( V_285 & 0xFF00 ) >> 8 ) << 4 ;
F_12 ( V_3 -> V_549 , 0x28 , 0x0F , V_160 ) ;
V_285 += 8 ;
if ( V_3 -> V_45 & V_234 )
V_285 -= 4 ;
V_160 = V_285 & 0xFF ;
V_160 = V_160 << 4 ;
F_12 ( V_3 -> V_549 , 0x2A , 0x0F , V_160 ) ;
V_285 = V_514 ;
V_259 += 2 ;
V_160 = V_651 [ V_259 ] | ( ( V_651 [ V_259 + 1 ] ) << 8 ) ;
V_285 -= V_160 ;
V_160 = V_285 & 0x00FF ;
V_160 = V_160 << 4 ;
F_12 ( V_3 -> V_549 , 0x2D , 0x0F , V_160 ) ;
V_285 -= 11 ;
if ( ! ( V_3 -> V_45 & V_198 ) ) {
V_219 = F_77 ( V_3 ) ;
V_285 = V_219 - 1 ;
}
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x2E , V_160 ) ;
V_220 = V_3 -> V_354 ;
if ( V_3 -> V_353 == 360 )
V_220 = 746 ;
if ( V_3 -> V_353 == 375 )
V_220 = 746 ;
if ( V_3 -> V_353 == 405 )
V_220 = 853 ;
if ( V_3 -> V_45 & V_198 ) {
if ( V_3 -> V_144 &
( V_145 | V_146 | V_228 ) ) {
if ( ! ( V_3 -> V_46 &
( V_539 | V_538 ) ) )
V_220 = V_220 >> 1 ;
} else
V_220 = V_220 >> 1 ;
}
V_220 -= 2 ;
V_160 = V_220 & 0x00FF ;
if ( V_3 -> V_45 & V_234 ) {
if ( V_3 -> V_144 & V_145 ) {
if ( V_3 -> V_46 & V_587 ) {
if ( V_3 -> V_45 & V_200 ) {
if ( V_189 == 0x2f )
V_160 += 1 ;
}
}
} else {
if ( V_3 -> V_45 & V_200 ) {
if ( V_189 == 0x2f )
V_160 += 1 ;
}
}
}
F_4 ( V_3 -> V_549 , 0x2F , V_160 ) ;
V_160 = ( V_285 & 0xFF00 ) >> 8 ;
V_160 |= ( ( V_220 & 0xFF00 ) >> 8 ) << 6 ;
if ( ! ( V_3 -> V_45 & V_234 ) ) {
if ( V_3 -> V_144 & V_145 ) {
if ( V_3 -> V_46 & V_587 ) {
V_160 |= 0x10 ;
if ( ! ( V_3 -> V_45 & V_242 ) )
V_160 |= 0x20 ;
}
} else {
V_160 |= 0x10 ;
if ( ! ( V_3 -> V_45 & V_242 ) )
V_160 |= 0x20 ;
}
}
F_4 ( V_3 -> V_549 , 0x30 , V_160 ) ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
V_220 = V_3 -> V_354 ;
V_285 = V_220 - 2 ;
if ( V_3 -> V_45 & V_198 ) {
if ( ! ( V_3 -> V_46 & ( V_539
| V_538 ) ) )
V_220 = V_220 >> 1 ;
}
if ( V_3 -> V_144 & ( V_146 | V_228 ) ) {
V_160 = 0 ;
if ( V_285 & 0x0400 )
V_160 |= 0x20 ;
if ( V_220 & 0x0400 )
V_160 |= 0x40 ;
F_4 ( V_3 -> V_529 , 0x10 , V_160 ) ;
}
V_160 = ( ( ( V_220 - 3 ) & 0x0300 ) >> 8 ) << 5 ;
F_4 ( V_3 -> V_549 , 0x46 , V_160 ) ;
V_160 = ( V_220 - 3 ) & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x47 , V_160 ) ;
}
V_220 = V_220 & 0x00FF ;
if ( ! ( V_194 & V_288 ) ) {
V_285 = V_3 -> V_351 ;
if ( V_285 >= V_3 -> V_352 ) {
V_220 |= 0x2000 ;
V_219 &= 0x00FF ;
}
}
V_285 = 0x0101 ;
if ( V_3 -> V_45 & V_198 ) {
if ( V_3 -> V_351 >= 1024 ) {
V_285 = 0x1920 ;
if ( V_3 -> V_351 >= 1280 ) {
V_285 = 0x1420 ;
V_220 = V_220 & 0xDFFF ;
}
}
}
if ( ! ( V_220 & 0x2000 ) ) {
if ( V_194 & V_288 )
V_285 = ( V_285 & 0xFF00 ) | ( ( V_285 & 0x00FF ) << 1 ) ;
V_514 = V_220 ;
V_653 = V_3 -> V_351 ;
V_654 = ( V_285 & 0xFF00 ) >> 8 ;
V_652 = V_653 * V_654 ;
V_655 = V_285 & 0x00FF ;
V_652 = V_652 / V_655 ;
V_655 = 8 * 1024 ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
V_655 = V_655 * 8 ;
}
V_652 = V_652 * V_655 ;
V_655 = V_3 -> V_352 ;
V_292 = V_652 % V_655 ;
V_653 = V_652 / V_655 ;
if ( V_292 != 0 )
V_653 += 1 ;
V_219 = ( unsigned short ) V_653 ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
V_285 = ( ( V_219 & 0xFF00 ) >> 5 ) >> 8 ;
}
V_220 = V_514 ;
V_220 = ( unsigned short ) ( ( ( V_653 & 0x0000FF00 ) & 0x1F00 )
| ( V_220 & 0x00FF ) ) ;
V_219 = ( unsigned short ) ( ( ( V_653 & 0x000000FF ) << 8 )
| ( V_219 & 0x00FF ) ) ;
V_160 = ( V_219 & 0xFF00 ) >> 8 ;
} else {
V_160 = ( V_219 & 0x00FF ) >> 8 ;
}
F_4 ( V_3 -> V_549 , 0x44 , V_160 ) ;
V_160 = ( V_220 & 0xFF00 ) >> 8 ;
F_12 ( V_3 -> V_549 , 0x45 , ~ 0x03F , V_160 ) ;
V_160 = V_285 & 0x00FF ;
if ( V_220 & 0x2000 )
V_160 = 0 ;
if ( ! ( V_3 -> V_45 & V_199 ) )
V_160 |= 0x18 ;
F_12 ( V_3 -> V_549 , 0x46 , ~ 0x1F , V_160 ) ;
if ( V_3 -> V_46 & V_249 ) {
V_220 = 0x0382 ;
V_285 = 0x007e ;
} else {
V_220 = 0x0369 ;
V_285 = 0x0061 ;
}
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x4b , V_160 ) ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x4c , V_160 ) ;
V_160 = ( ( V_285 & 0xFF00 ) >> 8 ) & 0x03 ;
V_160 = V_160 << 2 ;
V_160 |= ( ( V_220 & 0xFF00 ) >> 8 ) & 0x03 ;
if ( V_3 -> V_45 & V_244 ) {
V_160 |= 0x10 ;
if ( V_3 -> V_46 & V_539 )
V_160 |= 0x20 ;
if ( V_3 -> V_46 & V_538 )
V_160 |= 0x60 ;
}
F_4 ( V_3 -> V_549 , 0x4d , V_160 ) ;
V_160 = F_2 ( V_3 -> V_549 , 0x43 ) ;
F_4 ( V_3 -> V_549 , 0x43 , ( unsigned short ) ( V_160 - 3 ) ) ;
if ( ! ( V_3 -> V_46 & ( V_539 | V_538 ) ) ) {
if ( V_3 -> V_46 & V_541 ) {
V_651 = V_656 ;
for ( V_193 = 0x1c , V_259 = 0 ; V_193 <= 0x30 ; V_193 ++ , V_259 ++ ) {
F_4 ( V_3 -> V_549 , V_193 ,
V_651 [ V_259 ] ) ;
}
F_4 ( V_3 -> V_549 , 0x43 , 0x72 ) ;
}
}
if ( V_3 -> V_144 & V_228 ) {
if ( V_3 -> V_46 & V_580 )
F_12 ( V_3 -> V_549 , 0x4E , ~ 0x08 ,
0x08 ) ;
}
if ( V_3 -> V_46 & V_580 ) {
V_219 = ( unsigned char ) F_2 ( V_3 -> V_549 ,
0x01 ) ;
V_219 -- ;
F_13 ( V_3 -> V_549 , 0x01 , V_219 ) ;
F_13 ( V_3 -> V_549 , 0x00 , 0xEF ) ;
}
if ( V_3 -> V_45 & V_234 ) {
if ( ! ( V_3 -> V_45 & V_200 ) )
F_4 ( V_3 -> V_549 , 0x0B , 0x00 ) ;
}
if ( V_3 -> V_45 & V_198 )
return;
}
static void F_80 ( unsigned short V_189 , unsigned short V_190 ,
struct V_201 * V_202 ,
unsigned short V_218 ,
struct V_2 * V_3 )
{
unsigned short V_514 , V_515 , V_647 , V_219 , V_220 , V_285 , V_160 ,
V_191 , V_603 , V_545 , V_221 , V_194 , V_615 ;
struct V_519 * V_657 = NULL ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_221 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_615 = V_3 -> V_10 [ V_218 ] . V_263 ;
V_615 &= V_264 ;
if ( ! ( V_3 -> V_45 & V_199 ) )
return;
V_220 = V_3 -> V_352 ;
if ( F_67 ( V_3 ) )
V_220 = V_220 >> 1 ;
V_220 -= 1 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x2C , V_160 ) ;
V_160 = ( V_220 & 0xFF00 ) >> 8 ;
V_160 = V_160 << 4 ;
F_12 ( V_3 -> V_549 , 0x2B , 0x0F , V_160 ) ;
V_160 = 0x01 ;
F_4 ( V_3 -> V_549 , 0x0B , V_160 ) ;
V_220 = V_3 -> V_354 ;
V_514 = V_220 ;
V_220 -- ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x03 , V_160 ) ;
V_160 = ( ( V_220 & 0xFF00 ) >> 8 ) & 0x07 ;
F_12 ( V_3 -> V_549 , 0x0C , ~ 0x07 , V_160 ) ;
V_285 = V_3 -> V_498 - 1 ;
V_515 = V_285 + 1 ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x19 , V_160 ) ;
V_160 = ( V_285 & 0xFF00 ) >> 8 ;
V_160 = V_160 << 5 ;
F_4 ( V_3 -> V_549 , 0x1A , V_160 ) ;
F_12 ( V_3 -> V_549 , 0x09 , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_549 , 0x0A , 0xF0 , 0x00 ) ;
F_12 ( V_3 -> V_549 , 0x17 , 0xFB , 0x00 ) ;
F_12 ( V_3 -> V_549 , 0x18 , 0xDF , 0x00 ) ;
V_220 = 5 ;
V_657 = (struct V_519 * ) F_36 ( V_220 , V_189 ,
V_190 , V_218 , V_3 ) ;
V_191 = V_3 -> V_42 ;
V_191 &= V_372 ;
if ( ( V_191 == V_252 ) || ( V_191 == V_324 ) ) {
V_220 = 1024 ;
V_285 = 768 ;
} else if ( ( V_191 == V_231 ) ||
( V_191 == V_501 ) ) {
V_220 = 1280 ;
V_285 = 1024 ;
} else if ( V_191 == V_502 ) {
V_220 = 1400 ;
V_285 = 1050 ;
} else {
V_220 = 1600 ;
V_285 = 1200 ;
}
if ( V_3 -> V_44 & V_362 ) {
V_220 = V_3 -> V_352 ;
V_285 = V_3 -> V_354 ;
}
V_647 = V_220 ;
V_219 = V_3 -> V_498 ;
V_3 -> V_521 = V_657 -> V_521 ;
V_3 -> V_523 = V_657 -> V_523 ;
V_3 -> V_525 = V_657 -> V_525 ;
V_3 -> V_526 = V_657 -> V_526 ;
V_220 = V_3 -> V_525 ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x05 , V_160 ) ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x06 , V_160 ) ;
V_545 = ( ( V_285 & 0xFF00 ) >> 8 ) & 0x07 ;
V_603 = ( ( V_220 & 0xFF00 ) >> 8 ) & 0x07 ;
V_191 = V_545 ;
V_191 = V_191 << 3 ;
V_191 |= V_603 ;
F_4 ( V_3 -> V_549 , 0x02 , V_191 ) ;
F_42 ( & V_219 , & V_220 , V_3 ) ;
V_285 = V_220 ;
V_219 = V_3 -> V_498 ;
V_220 = V_3 -> V_526 ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x04 , V_160 ) ;
V_160 = ( V_220 & 0xFF00 ) >> 8 ;
V_160 = V_160 << 4 ;
V_160 |= ( V_285 & 0x000F ) ;
F_4 ( V_3 -> V_549 , 0x01 , V_160 ) ;
V_285 = V_647 ;
V_219 = V_3 -> V_496 ;
V_220 = V_3 -> V_521 ;
V_220 &= 0x0FFF ;
if ( F_67 ( V_3 ) ) {
V_219 = V_219 >> 1 ;
V_220 = V_220 >> 1 ;
V_285 = V_285 >> 1 ;
}
if ( V_3 -> V_144 & V_146 )
V_220 += 1 ;
if ( V_3 -> V_144 & V_228 )
V_220 += 1 ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x1F , V_160 ) ;
V_160 = ( ( V_220 & 0xFF00 ) >> 8 ) << 4 ;
F_4 ( V_3 -> V_549 , 0x20 , V_160 ) ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x23 , V_160 ) ;
V_160 = ( V_285 & 0xFF00 ) >> 8 ;
F_4 ( V_3 -> V_549 , 0x25 , V_160 ) ;
F_42 ( & V_219 , & V_220 , V_3 ) ;
V_285 = V_219 ;
V_219 = V_3 -> V_496 ;
V_220 = V_3 -> V_523 ;
if ( F_67 ( V_3 ) ) {
V_219 = V_219 >> 1 ;
V_220 = V_220 >> 1 ;
V_285 = V_285 >> 1 ;
}
if ( V_3 -> V_144 & V_146 )
V_220 += 1 ;
V_285 += V_220 ;
if ( V_285 >= V_219 )
V_285 -= V_219 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x1C , V_160 ) ;
V_160 = ( V_220 & 0xFF00 ) >> 8 ;
V_160 = V_160 << 4 ;
F_12 ( V_3 -> V_549 , 0x1D , ~ 0x0F0 , V_160 ) ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_549 , 0x21 , V_160 ) ;
if ( ! ( V_3 -> V_44 & V_597 ) ) {
if ( V_3 -> V_353 == 525 ) {
if ( V_3 -> V_144 & ( V_246 | V_247
| V_145 | V_146
| V_228 ) ) {
V_160 = 0xC6 ;
} else
V_160 = 0xC4 ;
F_4 ( V_3 -> V_549 , 0x2f , V_160 ) ;
F_4 ( V_3 -> V_549 , 0x30 , 0xB3 ) ;
}
if ( V_3 -> V_353 == 420 ) {
if ( V_3 -> V_144 & ( V_246 | V_247
| V_145 | V_146
| V_228 ) ) {
V_160 = 0x4F ;
} else
V_160 = 0x4E ;
F_4 ( V_3 -> V_549 , 0x2f , V_160 ) ;
}
}
}
static struct V_658 * F_81 ( unsigned short V_285 ,
struct V_2 * V_3 )
{
unsigned short V_219 , V_220 , V_193 ;
struct V_658 * V_659 ;
if ( V_285 == 0 ) {
V_219 = V_3 -> V_351 ;
V_220 = V_3 -> V_352 ;
} else {
V_219 = V_3 -> V_353 ;
V_220 = V_3 -> V_354 ;
}
if ( V_219 <= V_220 )
return & V_660 [ 0 ] ;
else
V_659 = V_661 ;
if ( V_3 -> V_46 & V_249 )
V_659 = V_662 ;
if ( V_3 -> V_45 & V_244 ) {
if ( ( V_3 -> V_46 & V_584 ) ||
( V_3 -> V_46 & V_539 ) )
V_659 = V_661 ;
if ( V_3 -> V_46 & V_538 )
V_659 = V_663 ;
}
if ( V_3 -> V_45 & V_234 )
V_659 = V_660 ;
V_193 = 0 ;
while ( V_659 [ V_193 ] . V_664 != 0xFFFF ) {
if ( V_659 [ V_193 ] . V_664 == V_219 )
break;
V_193 ++ ;
}
return & V_659 [ V_193 ] ;
}
static void F_82 ( struct V_2 * V_3 )
{
unsigned short V_193 , V_259 ;
struct V_658 * V_659 ;
if ( ! ( V_3 -> V_144 & V_228 ) )
return;
V_659 = F_81 ( 0 , V_3 ) ;
for ( V_193 = 0x80 , V_259 = 0 ; V_193 <= 0xBF ; V_193 ++ , V_259 ++ )
F_4 ( V_3 -> V_549 , V_193 , V_659 -> V_506 [ V_259 ] ) ;
if ( ( V_3 -> V_45 & V_198 ) &&
( ! ( V_3 -> V_45 & V_234 ) ) ) {
V_659 = F_81 ( 1 , V_3 ) ;
for ( V_193 = 0xC0 , V_259 = 0 ; V_193 < 0xFF ; V_193 ++ , V_259 ++ )
F_4 ( V_3 -> V_549 ,
V_193 ,
V_659 -> V_506 [ V_259 ] ) ;
}
if ( ( V_3 -> V_45 & V_198 ) &&
( ! ( V_3 -> V_45 & V_234 ) ) )
F_12 ( V_3 -> V_549 , 0x4E , ~ 0x14 , 0x04 ) ;
else
F_12 ( V_3 -> V_549 , 0x4E , ~ 0x14 , 0x10 ) ;
}
static void F_83 ( unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_193 ;
unsigned char * V_359 ;
unsigned short V_194 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
F_4 ( V_3 -> V_665 , 0x00 , 0x00 ) ;
if ( V_3 -> V_46 & V_249 ) {
F_4 ( V_3 -> V_665 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_665 , 0x14 , 0xC8 ) ;
} else {
F_4 ( V_3 -> V_665 , 0x13 , 0xF5 ) ;
F_4 ( V_3 -> V_665 , 0x14 , 0xB7 ) ;
}
if ( ! ( V_3 -> V_45 & V_198 ) )
return;
if ( V_3 -> V_46 & V_580 ) {
F_4 ( V_3 -> V_665 , 0x13 , 0xFA ) ;
F_4 ( V_3 -> V_665 , 0x14 , 0xC8 ) ;
F_4 ( V_3 -> V_665 , 0x3D , 0xA8 ) ;
}
if ( ( V_3 -> V_45 & V_234 ) || ( V_3 -> V_45
& V_244 ) ) {
if ( V_3 -> V_46 & V_584 )
return;
V_359 = V_3 -> V_125 ;
if ( V_3 -> V_239 & V_240 ) {
V_359 = V_3 -> V_127 ;
if ( ! ( V_194 & V_208 ) )
V_359 = V_3 -> V_129 ;
}
if ( V_3 -> V_46 & V_539 )
V_359 = V_3 -> V_131 ;
if ( V_3 -> V_46 & V_538 )
V_359 = V_3 -> V_133 ;
for ( V_193 = 0 ; V_193 <= 0x3E ; V_193 ++ )
F_4 ( V_3 -> V_665 , V_193 , V_359 [ V_193 ] ) ;
if ( V_3 -> V_144 & V_228 ) {
if ( V_3 -> V_46 & V_539 )
F_4 ( V_3 -> V_665 , 0x28 , 0x3f ) ;
}
}
return;
}
static void F_84 ( unsigned short V_189 , unsigned short V_190 ,
unsigned short V_218 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_219 , V_285 , V_220 , V_194 , V_160 , V_292 ;
unsigned long V_654 , V_653 , V_666 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_160 = V_3 -> V_617 ;
F_4 ( V_3 -> V_529 , 0x13 , V_160 ) ;
V_220 = V_3 -> V_616 ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_529 , 0x14 , V_160 ) ;
V_292 = ( ( V_220 & 0xFF00 ) >> 8 ) << 7 ;
V_285 = V_3 -> V_494 - 1 ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_529 , 0x16 , V_160 ) ;
V_160 = ( ( V_285 & 0xFF00 ) >> 8 ) << 3 ;
V_292 |= V_160 ;
V_285 = V_3 -> V_495 - 1 ;
if ( ! ( V_3 -> V_45 & V_198 ) )
V_285 -= 5 ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_529 , 0x17 , V_160 ) ;
V_160 = V_292 | ( ( V_285 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_529 , 0x15 , V_160 ) ;
F_20 ( V_3 -> V_529 , 0x0D , 0x08 ) ;
V_285 = V_3 -> V_45 ;
V_220 = V_3 -> V_351 ;
if ( V_194 & V_288 )
V_220 = V_220 >> 1 ;
if ( F_67 ( V_3 ) )
V_220 = V_220 >> 1 ;
if ( V_285 & V_234 ) {
V_160 = 0 ;
if ( V_220 <= 1024 )
V_160 = 0xA0 ;
if ( V_220 == 1280 )
V_160 = 0xC0 ;
} else if ( V_285 & V_198 ) {
V_160 = 0xA0 ;
if ( V_220 <= 800 )
V_160 = 0x80 ;
} else {
V_160 = 0x80 ;
if ( V_3 -> V_45 & V_199 ) {
V_160 = 0 ;
if ( V_220 > 800 )
V_160 = 0x60 ;
}
}
if ( V_3 -> V_46 & ( V_539 | V_538 ) ) {
V_160 = 0x00 ;
if ( V_3 -> V_351 == 1280 )
V_160 = 0x40 ;
if ( V_3 -> V_351 == 1024 )
V_160 = 0x20 ;
}
F_12 ( V_3 -> V_529 , 0x0E , ~ 0xEF , V_160 ) ;
V_654 = V_3 -> V_354 ;
if ( V_285 & V_234 ) {
if ( ! ( V_160 & 0xE000 ) )
V_220 = V_220 >> 1 ;
}
V_285 = V_3 -> V_622 ;
V_160 = V_285 & 0x00FF ;
F_4 ( V_3 -> V_529 , 0x18 , V_160 ) ;
V_653 = V_3 -> V_353 ;
V_285 |= 0x04000 ;
if ( V_653 <= V_654 ) {
V_285 = ( V_285 & ( ~ 0x4000 ) ) ;
V_653 = V_3 -> V_353 ;
} else {
V_653 -= V_654 ;
}
V_666 = ( V_653 * 256 * 1024 ) % V_654 ;
V_653 = ( V_653 * 256 * 1024 ) / V_654 ;
V_654 = V_653 ;
if ( V_666 != 0 )
V_654 ++ ;
V_160 = ( unsigned short ) ( V_654 & 0x000000FF ) ;
F_4 ( V_3 -> V_529 , 0x1B , V_160 ) ;
V_160 = ( unsigned short ) ( ( V_654 & 0x0000FF00 ) >> 8 ) ;
F_4 ( V_3 -> V_529 , 0x1A , V_160 ) ;
V_220 = ( unsigned short ) ( V_654 >> 16 ) ;
V_160 = V_220 & 0x00FF ;
V_160 = V_160 << 4 ;
V_160 |= ( ( V_285 & 0xFF00 ) >> 8 ) ;
F_4 ( V_3 -> V_529 , 0x19 , V_160 ) ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
V_160 = 0x0028 ;
F_4 ( V_3 -> V_529 , 0x1C , V_160 ) ;
V_219 = V_3 -> V_351 ;
if ( V_194 & V_288 )
V_219 = V_219 >> 1 ;
if ( F_67 ( V_3 ) )
V_219 = V_219 >> 1 ;
if ( V_3 -> V_45 & V_199 ) {
if ( V_219 > 800 )
V_219 -= 800 ;
} else {
if ( V_3 -> V_351 > 800 ) {
if ( V_3 -> V_351 == 1024 )
V_219 = ( V_219 * 25 / 32 ) - 1 ;
else
V_219 = ( V_219 * 20 / 32 ) - 1 ;
}
}
V_219 -= 1 ;
V_160 = ( V_219 & 0xFF00 ) >> 8 ;
V_160 = ( ( V_160 & 0x0003 ) << 4 ) ;
F_4 ( V_3 -> V_529 , 0x1E , V_160 ) ;
V_160 = ( V_219 & 0x00FF ) ;
F_4 ( V_3 -> V_529 , 0x1D , V_160 ) ;
if ( V_3 -> V_45 & ( V_198 | V_234 ) ) {
if ( V_3 -> V_351 > 800 )
F_20 ( V_3 -> V_529 , 0x1E , 0x08 ) ;
}
V_160 = 0x0036 ;
if ( V_3 -> V_45 & V_198 ) {
if ( ! ( V_3 -> V_46 & ( V_541
| V_539 | V_538
| V_587 ) ) ) {
V_160 |= 0x0001 ;
if ( ( V_3 -> V_45 & V_200 )
&& ( ! ( V_3 -> V_46
& V_240 ) ) )
V_160 &= ( ~ 0x0001 ) ;
}
}
F_12 ( V_3 -> V_529 , 0x1F , 0x00C0 , V_160 ) ;
V_220 = V_3 -> V_496 ;
if ( F_67 ( V_3 ) )
V_220 = V_220 >> 1 ;
V_220 = ( V_220 >> 1 ) - 2 ;
V_160 = ( ( V_220 & 0x0700 ) >> 8 ) << 3 ;
F_12 ( V_3 -> V_529 , 0x21 , 0x00C0 , V_160 ) ;
V_160 = V_220 & 0x00FF ;
F_4 ( V_3 -> V_529 , 0x22 , V_160 ) ;
}
if ( V_3 -> V_667 == 0 )
F_70 ( V_189 , V_190 , V_218 ,
V_3 ) ;
}
static void F_85 ( struct V_2 * V_3 )
{
F_12 ( V_3 -> V_177 , 0x1E , 0xFF , 0x20 ) ;
}
static void F_86 ( unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_668 , V_669 ;
V_668 = V_3 -> V_670 ;
V_669 = V_3 -> V_670 + 1 ;
if ( V_3 -> V_214 == V_215 ) {
if ( ! ( V_3 -> V_45 & ( V_200 | V_671
| V_563 ) ) ) {
F_85 ( V_3 ) ;
}
}
return;
}
static void F_87 ( struct V_201 * V_202 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_204 , 0x63 , 0xBF , 0x40 ) ;
}
static void F_88 ( struct V_201 * V_202 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_204 , 0x63 , 0xBF , 0x00 ) ;
}
static unsigned char F_89 ( struct V_606 * V_607 ,
unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_332 , V_350 , V_644 , V_194 , V_284 ;
V_284 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_332 = V_3 -> V_33 [ V_284 ] . V_286 ;
V_350 = V_3 -> V_33 [ V_284 ] . V_287 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
if ( ! ( V_194 & V_208 ) ) {
V_332 /= 9 ;
V_332 *= 8 ;
}
if ( ( V_189 > 0x13 ) && ( V_194 & V_288 ) )
V_332 *= 2 ;
if ( ( V_189 > 0x13 ) && ( V_194 & V_261 ) )
V_350 *= 2 ;
if ( V_332 > V_607 -> V_608 . V_672 )
return 0 ;
if ( V_350 > V_607 -> V_608 . V_673 )
return 0 ;
if ( V_332 != V_607 -> V_608 . V_672 ||
V_350 != V_607 -> V_608 . V_673 ) {
V_644 = F_71 ( V_189 , V_190 , V_3 ) ;
if ( V_644 > 2 )
return 0 ;
}
return 1 ;
}
static void F_90 ( struct V_606 * V_607 ,
int V_273 ,
unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned char V_160 , V_674 ;
unsigned short V_332 , V_350 , V_194 , V_284 ;
unsigned short V_675 , V_676 , V_677 , V_678 , V_679 ;
unsigned short V_680 , V_681 , V_682 , V_683 , V_684 ;
unsigned short V_685 ;
V_160 = ( unsigned char ) ( ( V_607 -> V_608 . V_686 &
( V_687 << 8 ) ) >> 8 ) ;
V_160 &= V_687 ;
V_674 = ( unsigned char ) F_7 ( V_3 -> V_277 ) ;
F_8 ( ( V_674 & 0x3F ) | V_160 , V_3 -> V_255 ) ;
V_160 = V_607 -> V_608 . V_686 & V_687 ;
F_12 ( V_3 -> V_177 , 0x35 , ~ 0x80 , V_160 & 0x80 ) ;
F_12 ( V_3 -> V_177 , 0x30 , ~ 0x20 , ( V_160 & 0x40 ) >> 1 ) ;
if ( V_273 == V_159 )
F_22 ( V_3 ) ;
else
F_29 ( V_3 ) ;
V_284 = V_3 -> V_7 [ V_190 ] . V_223 ;
V_332 = V_3 -> V_33 [ V_284 ] . V_286 ;
V_350 = V_3 -> V_33 [ V_284 ] . V_287 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
if ( ! ( V_194 & V_208 ) )
V_332 = V_332 * 8 / 9 ;
V_675 = V_607 -> V_608 . V_675 ;
V_676 = V_332 + ( V_607 -> V_608 . V_672 - V_332 ) / 2 ;
if ( V_676 > V_675 )
V_676 -= V_675 ;
V_677 = V_676 + V_607 -> V_608 . V_688 ;
if ( V_677 > V_675 )
V_677 -= V_675 ;
V_678 = V_677 + V_607 -> V_608 . V_689 ;
if ( V_678 > V_675 )
V_678 -= V_675 ;
V_679 = V_676 + V_675 - V_607 -> V_608 . V_672 ;
V_680 = V_607 -> V_608 . V_680 ;
V_681 = V_350 + ( V_607 -> V_608 . V_673 - V_350 ) / 2 ;
if ( V_194 & V_261 )
V_681 += V_350 / 2 ;
if ( V_681 > V_680 )
V_681 -= V_680 ;
V_682 = V_681 + V_607 -> V_608 . V_690 ;
if ( V_682 > V_680 )
V_682 -= V_680 ;
V_683 = V_682 + V_607 -> V_608 . V_691 ;
if ( V_683 > V_680 )
V_683 -= V_680 ;
V_684 = V_681 + V_680 - V_607 -> V_608 . V_673 ;
V_160 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x11 ) ;
F_4 ( V_3 -> V_204 , 0x11 , V_160 & 0x7f ) ;
if ( ! ( V_194 & V_208 ) )
F_20 ( V_3 -> V_177 , 0x1 , 0x1 ) ;
V_685 = ( V_675 >> 3 ) - 5 ;
F_12 ( V_3 -> V_177 , 0x0B , ~ 0x03 , ( V_685 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_204 , 0x0 , ( V_685 & 0xFF ) ) ;
V_685 = ( V_676 >> 3 ) - 1 ;
F_12 ( V_3 -> V_177 , 0x0B , ~ 0x30 , ( V_685 & 0x300 ) >> 4 ) ;
F_4 ( V_3 -> V_204 , 0x2 , ( V_685 & 0xFF ) ) ;
V_685 = ( V_679 >> 3 ) - 1 ;
F_12 ( V_3 -> V_177 , 0x0C , ~ 0x03 , ( V_685 & 0xC0 ) >> 6 ) ;
F_12 ( V_3 -> V_204 , 0x05 , ~ 0x80 , ( V_685 & 0x20 ) << 2 ) ;
F_12 ( V_3 -> V_204 , 0x03 , ~ 0x1F , V_685 & 0x1F ) ;
V_685 = ( V_677 >> 3 ) + 2 ;
F_12 ( V_3 -> V_177 , 0x0B , ~ 0xC0 , ( V_685 & 0x300 ) >> 2 ) ;
F_4 ( V_3 -> V_204 , 0x4 , ( V_685 & 0xFF ) ) ;
V_685 -- ;
F_12 ( V_3 -> V_177 , 0x2F , ~ 0x03 , ( V_685 & 0x300 ) >> 8 ) ;
F_4 ( V_3 -> V_177 , 0x2E , ( V_685 & 0xFF ) ) ;
V_685 = ( V_678 >> 3 ) + 2 ;
F_12 ( V_3 -> V_177 , 0x0C , ~ 0x04 , ( V_685 & 0x20 ) >> 3 ) ;
F_12 ( V_3 -> V_204 , 0x05 , ~ 0x1F , V_685 & 0x1F ) ;
V_685 -- ;
F_12 ( V_3 -> V_177 , 0x2F , ~ 0xFC , V_685 << 2 ) ;
V_685 = V_680 - 2 ;
F_12 ( V_3 -> V_177 , 0x0A , ~ 0x01 , ( V_685 & 0x400 ) >> 10 ) ;
F_12 ( V_3 -> V_204 , 0x07 , ~ 0x20 , ( V_685 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_204 , 0x07 , ~ 0x01 , ( V_685 & 0x100 ) >> 8 ) ;
F_4 ( V_3 -> V_204 , 0x06 , ( V_685 & 0xFF ) ) ;
V_685 = V_681 - 1 ;
F_12 ( V_3 -> V_177 , 0x0A , ~ 0x04 , ( V_685 & 0x400 ) >> 8 ) ;
F_12 ( V_3 -> V_204 , 0x09 , ~ 0x20 , ( V_685 & 0x200 ) >> 4 ) ;
F_12 ( V_3 -> V_204 , 0x07 , ~ 0x08 , ( V_685 & 0x100 ) >> 5 ) ;
F_4 ( V_3 -> V_204 , 0x15 , ( V_685 & 0xFF ) ) ;
V_685 = V_684 - 1 ;
F_12 ( V_3 -> V_177 , 0x0A , ~ 0x10 , ( V_685 & 0x100 ) >> 4 ) ;
F_4 ( V_3 -> V_204 , 0x16 , ( V_685 & 0xFF ) ) ;
V_685 = V_682 - 1 ;
F_12 ( V_3 -> V_177 , 0x0A , ~ 0x08 , ( V_685 & 0x400 ) >> 7 ) ;
F_12 ( V_3 -> V_204 , 0x07 , ~ 0x80 , ( V_685 & 0x200 ) >> 2 ) ;
F_12 ( V_3 -> V_204 , 0x07 , ~ 0x04 , ( V_685 & 0x100 ) >> 6 ) ;
F_4 ( V_3 -> V_204 , 0x10 , ( V_685 & 0xFF ) ) ;
if ( V_273 == V_159 ) {
F_12 ( V_3 -> V_177 , 0x35 , ~ 0x07 ,
( V_685 & 0x700 ) >> 8 ) ;
F_4 ( V_3 -> V_177 , 0x34 , V_685 & 0xFF ) ;
} else {
F_12 ( V_3 -> V_177 , 0x3F , ~ 0x03 ,
( V_685 & 0x600 ) >> 9 ) ;
F_4 ( V_3 -> V_177 , 0x34 , ( V_685 >> 1 ) & 0xFF ) ;
F_12 ( V_3 -> V_204 , 0x33 , ~ 0x01 , V_685 & 0x01 ) ;
}
V_685 = V_683 - 1 ;
F_12 ( V_3 -> V_177 , 0x0A , ~ 0x20 , ( V_685 & 0x10 ) << 1 ) ;
F_12 ( V_3 -> V_204 , 0x11 , ~ 0x0F , V_685 & 0x0F ) ;
if ( V_273 == V_159 )
F_12 ( V_3 -> V_177 , 0x3F , ~ 0xFC ,
( V_685 << 2 ) & 0xFC ) ;
else
F_12 ( V_3 -> V_177 , 0x3F , ~ 0xFC ,
( V_685 << 2 ) & 0x7C ) ;
for ( V_160 = 0 , V_685 = 0 ; V_160 < 3 ; V_160 ++ ) {
F_12 ( V_3 -> V_177 , 0x31 , ~ 0x30 , V_685 ) ;
F_4 ( V_3 -> V_177 ,
0x2B , V_607 -> V_608 . V_692 ) ;
F_4 ( V_3 -> V_177 ,
0x2C , V_607 -> V_608 . V_693 ) ;
V_685 += 0x10 ;
}
if ( ! ( V_194 & V_208 ) ) {
F_7 ( V_3 -> V_209 ) ;
F_8 ( 0x13 , V_3 -> V_210 ) ;
F_8 ( 0x00 , V_3 -> V_210 ) ;
F_7 ( V_3 -> V_209 ) ;
F_8 ( 0x20 , V_3 -> V_210 ) ;
F_7 ( V_3 -> V_209 ) ;
}
}
static unsigned char F_91 ( struct V_2 * V_3 )
{
unsigned short V_219 ;
V_219 = V_3 -> V_45 ;
if ( V_219 & V_562 )
return 0 ;
else if ( V_219 & ( V_563 | V_574 | V_573 ) )
return 1 ;
return 0 ;
}
static unsigned char F_92 ( struct V_2 * V_3 )
{
unsigned short V_220 , V_191 ;
V_220 = V_3 -> V_239 & ( V_694 | V_695 ) ;
V_191 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_522 , 0x2E ) ) ;
if ( V_220 & ( V_696 | V_694 ) ) {
if ( ! ( V_191 & 0x08 ) )
return 0 ;
}
if ( ! ( V_220 & ( V_697 | V_695 ) ) )
return 0 ;
if ( V_191 & 0x01 )
return 1 ;
return 0 ;
}
static unsigned char F_93 ( struct V_2 * V_3 )
{
unsigned short V_220 , V_191 ;
V_220 = V_3 -> V_239 & ( V_696 | V_697 ) ;
V_191 = ~ ( ( unsigned short ) F_2 ( V_3 -> V_522 , 0x2E ) ) ;
if ( V_220 & ( V_696 | V_694 ) ) {
if ( ! ( V_191 & 0x08 ) )
return 0 ;
}
if ( ! ( V_220 & ( V_697 | V_695 ) ) )
return 0 ;
if ( V_191 & 0x01 )
return 1 ;
return 0 ;
}
static void F_94 ( struct V_606 * V_607 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_191 = 0 ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
V_191 = 0x3F ;
if ( ! ( V_3 -> V_45 &
( V_563 | V_573 ) ) ) {
if ( V_3 -> V_45 & V_197 ) {
if ( V_3 -> V_45 & V_562 ) {
V_191 = 0x7F ;
if ( ! ( V_3 -> V_45 & V_197 ) )
V_191 = 0xBF ;
if ( V_3 -> V_239 & V_695 )
V_191 &= 0xBF ;
if ( V_3 -> V_239 & V_694 )
V_191 &= 0x7F ;
}
}
}
F_13 ( V_3 -> V_529 , 0x1F , V_191 ) ;
if ( V_3 -> V_144 & ( V_146 | V_228 ) ) {
if ( ( ( V_3 -> V_45 & ( V_199 | V_197 ) ) )
|| ( F_92 ( V_3 ) )
|| ( F_91 ( V_3 ) ) )
F_20 ( V_3 -> V_529 , 0x30 , 0x80 ) ;
}
if ( ( V_3 -> V_239 & V_694 ) || ( V_3 -> V_45
& ( V_563 | V_197
| V_573 ) ) ) {
if ( V_3 -> V_239 & V_698 )
F_87 ( V_202 , V_3 ) ;
F_62 ( V_607 , V_202 , V_3 ) ;
}
if ( V_3 -> V_45 & V_197 ) {
if ( ( V_3 -> V_239 & V_694 ) || ( V_3 -> V_45
& V_197 ) )
F_13 ( V_3 -> V_522 , 0x1e , 0xdf ) ;
}
F_13 ( V_3 -> V_177 , 0x32 , 0xdf ) ;
if ( ( V_3 -> V_45 & ( V_573 | V_562 ) ) )
F_13 ( V_3 -> V_549 , 0x00 , 0xdf ) ;
if ( ( V_3 -> V_239 & V_695 ) ||
( V_3 -> V_45 &
( V_563 | V_573 ) ) ||
( ( ! ( V_3 -> V_45 & V_197 ) ) &&
( V_3 -> V_45 &
( V_226 | V_199 | V_198 ) ) ) )
F_20 ( V_3 -> V_522 , 0x00 , 0x80 ) ;
if ( ( V_3 -> V_239 & V_695 ) ||
( V_3 -> V_45 &
( V_563 | V_573 ) ) ||
( ! ( V_3 -> V_45 & V_197 ) ) ||
( V_3 -> V_45 &
( V_226 | V_199 | V_198 ) ) ) {
V_191 = F_2 ( V_3 -> V_522 , 0x00 ) ;
F_20 ( V_3 -> V_522 , 0x00 , 0x10 ) ;
F_13 ( V_3 -> V_522 , 0x1E , 0xDF ) ;
F_4 ( V_3 -> V_522 , 0x00 , V_191 ) ;
}
} else {
if ( V_3 -> V_45 & ( V_199 | V_198 ) ) {
F_20 ( V_3 -> V_522 , 0x00 , 0x80 ) ;
F_13 ( V_3 -> V_522 , 0x1E , 0xDF ) ;
F_13 ( V_3 -> V_177 , 0x32 , 0xDF ) ;
}
if ( V_3 -> V_45 & ( V_563 | V_197
| V_573 ) )
F_62 ( V_607 , V_202 , V_3 ) ;
}
}
static unsigned short F_95 ( struct V_2 * V_3 )
{
unsigned short V_220 = 0 ;
if ( V_3 -> V_46 & V_249 )
V_220 = 2 ;
if ( V_3 -> V_46 & V_587 )
V_220 = 4 ;
if ( V_3 -> V_46 & V_584 )
V_220 = 6 ;
if ( V_3 -> V_46 & V_539 )
V_220 = 8 ;
if ( V_3 -> V_46 & V_538 )
V_220 = 10 ;
if ( V_3 -> V_46 & V_240 )
V_220 ++ ;
return V_220 ;
}
static void F_96 ( unsigned short * V_220 , unsigned char * V_544 ,
unsigned char * V_545 , struct V_2 * V_3 )
{
* V_220 = 0 ;
* V_544 = 0 ;
* V_545 = 0 ;
if ( V_3 -> V_46 & V_249 )
* V_220 = 1 ;
if ( V_3 -> V_46 & V_580 )
* V_220 = 2 ;
if ( V_3 -> V_46 & V_581 )
* V_220 = 3 ;
if ( V_3 -> V_46 & V_541 ) {
* V_220 = 4 ;
if ( V_3 -> V_46 & V_580 )
* V_220 = 5 ;
}
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
if ( ( ! ( V_3 -> V_45 & V_200 ) ) || ( V_3 -> V_46
& V_240 ) ) {
* V_220 += 8 ;
* V_544 += 1 ;
}
}
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) )
( * V_545 ) ++ ;
}
static void F_97 ( struct V_2 * V_3 )
{
unsigned short V_262 ;
unsigned char V_191 , V_507 , V_603 ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
if ( V_3 -> V_45 & ( V_199 | V_197
| V_198 | V_226 ) ) {
V_507 = 0 ;
V_603 = 0 ;
V_262 = F_95 ( V_3 ) ;
V_507 = V_3 -> V_150 [ V_262 ] ;
if ( V_3 -> V_144 & ( V_246 | V_247
| V_145 | V_146
| V_228 ) )
V_507 = V_3 -> V_152 [ V_262 ] ;
if ( V_3 -> V_45 & V_562 )
V_507 = V_507 >> 4 ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
V_262 = F_40 ( V_3 ) ;
V_603 = V_3 -> V_147 [ V_262 ] .
V_699 ;
if ( ! ( V_3 -> V_45 & V_197 ) )
V_507 = V_603 ;
}
V_507 &= 0x0F ;
V_603 &= 0xF0 ;
V_191 = F_2 ( V_3 -> V_522 , 0x2D ) ;
if ( V_3 -> V_45 & ( V_226 | V_199
| V_198 ) ) {
V_191 &= 0xF0 ;
V_191 |= V_507 ;
}
if ( V_3 -> V_45 & V_197 ) {
V_191 &= 0x0F ;
V_191 |= V_603 ;
}
F_4 ( V_3 -> V_522 , 0x2D , V_191 ) ;
}
} else if ( V_3 -> V_225 == 1 ) {
V_507 = 0 ;
V_603 = 0 ;
if ( V_3 -> V_45 & V_199 ) {
V_191 = V_3 -> V_147 [
F_40 ( V_3 ) ] .
V_699 ;
V_191 &= 0x0f ;
V_191 = V_191 << 4 ;
F_12 ( V_3 -> V_522 , 0x2D , 0x0f ,
V_191 ) ;
}
}
}
static void F_98 ( unsigned short V_285 ,
struct V_2 * V_3 )
{
unsigned short V_160 ;
V_160 = F_2 ( V_3 -> V_204 , 0x37 ) ;
if ( V_160 & V_649 ) {
F_12 ( V_3 -> V_522 , 0x19 , 0x0F ,
( unsigned short ) ( 0x20 | ( V_285 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_522 , 0x1A , 0x7F , 0x80 ) ;
} else {
F_12 ( V_3 -> V_522 , 0x19 , 0x0F ,
( unsigned short ) ( 0x30 | ( V_285 & 0x00C0 ) ) ) ;
F_12 ( V_3 -> V_522 , 0x1A , 0x7F , 0x00 ) ;
}
}
static void F_99 ( unsigned short V_285 ,
struct V_2 * V_3 )
{
if ( V_285 & V_700 )
F_12 ( V_3 -> V_549 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_285 & 0x00ff ) >> 6 )
| 0x0c ) ) ;
else
F_12 ( V_3 -> V_549 , 0x1A , 0xE0 ,
( unsigned short ) ( ( ( V_285 & 0x00ff ) >> 6 )
| 0x18 ) ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
unsigned short V_193 ;
V_193 = F_2 ( V_3 -> V_177 , 0x1F ) ;
if ( ! ( V_193 & 0xC0 ) ) {
for ( V_193 = 0 ; V_193 < 0xFFFF ; V_193 ++ ) {
if ( ! ( F_7 ( V_3 -> V_209 ) & 0x08 ) )
break;
}
for ( V_193 = 0 ; V_193 < 0xFFFF ; V_193 ++ ) {
if ( ( F_7 ( V_3 -> V_209 ) & 0x08 ) )
break;
}
}
}
static void F_101 ( struct V_2 * V_3 )
{
unsigned short V_262 ;
V_262 = F_40 ( V_3 ) ;
F_13 ( V_3 -> V_529 , 0x30 , 0x8F ) ;
F_100 ( V_3 ) ;
F_20 ( V_3 -> V_529 , 0x30 , 0x20 ) ;
F_100 ( V_3 ) ;
F_4 ( V_3 -> V_529 , 0x31 ,
V_3 -> V_147 [ V_262 ] . V_701 ) ;
F_4 ( V_3 -> V_529 , 0x32 ,
V_3 -> V_147 [ V_262 ] . V_702 ) ;
F_4 ( V_3 -> V_529 , 0x33 ,
V_3 -> V_147 [ V_262 ] . V_703 ) ;
F_4 ( V_3 -> V_529 , 0x34 ,
V_3 -> V_147 [ V_262 ] . V_704 ) ;
F_100 ( V_3 ) ;
F_20 ( V_3 -> V_529 , 0x30 , 0x40 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
unsigned short V_285 ;
V_285 = V_3 -> V_147 [ F_40 ( V_3 ) ] . V_593 ;
if ( V_3 -> V_144 &
( V_246 |
V_247 |
V_145 |
V_146 |
V_228 ) ) {
if ( V_3 -> V_144 &
( V_145 | V_146 | V_228 ) ) {
F_4 ( V_3 -> V_529 , 0x24 ,
( unsigned char ) ( V_285 & 0x1F ) ) ;
}
F_12 ( V_3 -> V_529 , 0x0D ,
~ ( ( V_705 | V_706 ) >> 8 ) ,
( unsigned short ) ( ( V_285 & ( V_705
| V_706 ) ) >> 8 ) ) ;
}
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
if ( V_3 -> V_45 & V_199 )
F_99 ( V_285 , V_3 ) ;
else if ( V_3 -> V_45 & V_197 )
F_98 ( V_285 , V_3 ) ;
if ( V_3 -> V_144 & ( V_146 | V_228 ) ) {
if ( V_285 & V_707 )
F_101 ( V_3 ) ;
}
} else {
F_98 ( V_285 , V_3 ) ;
}
}
static void F_103 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_220 ;
unsigned char V_191 ;
if ( V_3 -> V_46 & ( V_539 | V_538 ) )
return;
V_220 = F_95 ( V_3 ) ;
V_220 &= 0xFE ;
V_191 = V_708 [ V_220 ] ;
V_191 = V_191 << 4 ;
F_12 ( V_3 -> V_549 , 0x0A , 0x8F , V_191 ) ;
}
static void F_104 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_220 ;
unsigned char V_191 ;
V_220 = F_95 ( V_3 ) ;
V_220 &= 0xFE ;
V_191 = V_709 [ V_220 ] ;
V_191 = V_191 << 5 ;
F_12 ( V_3 -> V_549 , 0x3A , 0x1F , V_191 ) ;
}
static void F_105 ( struct V_2 * V_3 )
{
unsigned short V_220 ;
unsigned char V_544 , V_545 ;
unsigned long V_710 ;
F_96 ( & V_220 , & V_544 , & V_545 , V_3 ) ;
V_710 = V_711 [ V_220 ] ;
F_4 ( V_3 -> V_549 , 0x31 , ( unsigned short ) ( V_710
& 0x000000FF ) ) ;
F_4 ( V_3 -> V_549 , 0x32 , ( unsigned short ) ( ( V_710
& 0x0000FF00 ) >> 8 ) ) ;
F_4 ( V_3 -> V_549 , 0x33 , ( unsigned short ) ( ( V_710
& 0x00FF0000 ) >> 16 ) ) ;
F_4 ( V_3 -> V_549 , 0x34 , ( unsigned short ) ( ( V_710
& 0xFF000000 ) >> 24 ) ) ;
}
static void F_106 ( unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_220 , V_262 ;
unsigned char V_544 , V_545 , V_357 , * V_712 ;
F_96 ( & V_220 , & V_544 , & V_545 , V_3 ) ;
switch ( V_220 ) {
case 0x00 :
case 0x04 :
V_712 = V_713 ;
break;
case 0x01 :
V_712 = V_714 ;
break;
case 0x02 :
case 0x05 :
case 0x0D :
case 0x03 :
V_712 = V_715 ;
break;
case 0x08 :
case 0x0C :
case 0x0A :
case 0x0B :
case 0x09 :
V_712 = V_716 ;
break;
default:
return;
}
V_357 = V_3 -> V_7 [ V_190 ] . V_717 ;
if ( V_544 == 0 )
V_262 = V_357 * 4 ;
else
V_262 = V_357 * 7 ;
if ( ( V_544 == 0 ) && ( V_545 == 1 ) ) {
F_4 ( V_3 -> V_549 , 0x35 , 0 ) ;
F_4 ( V_3 -> V_549 , 0x36 , 0 ) ;
F_4 ( V_3 -> V_549 , 0x37 , 0 ) ;
F_4 ( V_3 -> V_549 , 0x38 , V_712 [ V_262 ++ ] ) ;
} else {
F_4 ( V_3 -> V_549 , 0x35 , V_712 [ V_262 ++ ] ) ;
F_4 ( V_3 -> V_549 , 0x36 , V_712 [ V_262 ++ ] ) ;
F_4 ( V_3 -> V_549 , 0x37 , V_712 [ V_262 ++ ] ) ;
F_4 ( V_3 -> V_549 , 0x38 , V_712 [ V_262 ++ ] ) ;
}
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
F_4 ( V_3 -> V_549 , 0x48 , V_712 [ V_262 ++ ] ) ;
F_4 ( V_3 -> V_549 , 0x49 , V_712 [ V_262 ++ ] ) ;
F_4 ( V_3 -> V_549 , 0x4A , V_712 [ V_262 ++ ] ) ;
}
}
static void F_107 ( unsigned short V_189 ,
unsigned short V_190 ,
struct V_2 * V_3 )
{
F_97 ( V_3 ) ;
if ( V_3 -> V_45 & ( V_199 | V_197 ) )
F_102 ( V_3 ) ;
if ( V_3 -> V_45 & V_198 ) {
F_105 ( V_3 ) ;
F_106 ( V_189 , V_190 , V_3 ) ;
F_103 ( V_189 , V_190 , V_3 ) ;
if ( V_3 -> V_144 & V_543 )
F_104 ( V_189 , V_190 , V_3 ) ;
}
}
static void F_108 ( unsigned short V_189 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_507 ;
short V_544 ;
unsigned char V_191 ;
V_191 = 0 ;
if ( ! ( V_3 -> V_45 & V_563 ) ) {
V_191 = F_2 ( V_3 -> V_522 , 0x00 ) ;
V_191 &= ~ 0x10 ;
V_191 |= 0x40 ;
if ( V_3 -> V_45 & ( V_226 | V_198
| V_199 ) ) {
V_191 = 0x40 ;
V_544 = V_3 -> V_214 ;
V_544 -= V_215 ;
if ( V_544 >= 0 ) {
V_191 = ( 0x008 >> V_544 ) ;
if ( V_191 == 0 )
V_191 = 1 ;
V_191 |= 0x040 ;
}
if ( V_3 -> V_45 & V_200 )
V_191 ^= 0x50 ;
}
}
F_4 ( V_3 -> V_522 , 0x00 , V_191 ) ;
V_191 = 0x08 ;
V_507 = 0xf0 ;
if ( V_3 -> V_45 & V_563 ) {
F_12 ( V_3 -> V_522 , 0x2e , V_507 , V_191 ) ;
} else {
V_191 = 0x00 ;
V_507 = 0xff ;
if ( V_3 -> V_45 & ( V_226 | V_198
| V_199 | V_197 ) ) {
if ( ( V_3 -> V_45 & V_197 ) &&
( ! ( V_3 -> V_45 & V_573 ) ) ) {
V_507 &= 0xf7 ;
V_191 |= 0x01 ;
F_12 ( V_3 -> V_522 , 0x2e ,
V_507 , V_191 ) ;
} else {
if ( V_3 -> V_45 & V_197 ) {
V_507 &= 0xf7 ;
V_191 |= 0x01 ;
}
if ( V_3 -> V_45 &
( V_226 |
V_198 |
V_199 ) ) {
V_507 &= 0xf8 ;
V_191 = 0x01 ;
if ( ! ( V_3 -> V_45 & V_200 ) )
V_191 |= 0x02 ;
if ( ! ( V_3 -> V_45 &
V_226 ) ) {
V_191 = V_191 ^ 0x05 ;
if ( ! ( V_3 -> V_45 &
V_199 ) )
V_191 = V_191 ^ 0x01 ;
}
if ( ! ( V_3 -> V_45 &
V_562 ) )
V_191 |= 0x08 ;
F_12 ( V_3 -> V_522 ,
0x2e , V_507 , V_191 ) ;
} else {
F_12 ( V_3 -> V_522 ,
0x2e , V_507 , V_191 ) ;
}
}
} else {
F_12 ( V_3 -> V_522 , 0x2e , V_507 ,
V_191 ) ;
}
}
if ( V_3 -> V_45 & ( V_226 | V_198 | V_199
| V_197 ) ) {
V_191 &= ( ~ 0x08 ) ;
if ( ( V_3 -> V_214 == V_215 ) && ( ! ( V_3 -> V_45
& V_200 ) ) ) {
V_191 |= 0x010 ;
}
V_191 |= 0x080 ;
if ( V_3 -> V_45 & V_198 ) {
V_191 |= 0x020 ;
if ( V_3 -> V_45 & V_576 )
V_191 = V_191 ^ 0x20 ;
}
F_12 ( V_3 -> V_529 , 0x0D , ~ 0x0BF , V_191 ) ;
V_191 = 0 ;
if ( V_3 -> V_44 & V_595 )
V_191 |= 0x40 ;
if ( V_3 -> V_45 & V_198 ) {
if ( V_3 -> V_46 & V_307 )
V_191 |= 0x40 ;
}
if ( ( V_3 -> V_42 == V_231 )
|| ( V_3 -> V_42 == V_501 ) )
V_191 |= 0x80 ;
if ( V_3 -> V_42 == V_232 )
V_191 |= 0x80 ;
F_4 ( V_3 -> V_529 , 0x0C , V_191 ) ;
}
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
V_191 = 0 ;
V_507 = 0xfb ;
if ( V_3 -> V_45 & V_562 ) {
V_507 = 0xff ;
if ( V_3 -> V_45 & V_197 )
V_191 |= 0x04 ;
}
F_12 ( V_3 -> V_522 , 0x13 , V_507 , V_191 ) ;
V_191 = 0x00 ;
V_507 = 0xcf ;
if ( ! ( V_3 -> V_45 & V_563 ) ) {
if ( V_3 -> V_45 & V_562 )
V_191 |= 0x30 ;
}
F_12 ( V_3 -> V_522 , 0x2c , V_507 , V_191 ) ;
V_191 = 0 ;
V_507 = 0x3f ;
if ( ! ( V_3 -> V_45 & V_563 ) ) {
if ( V_3 -> V_45 & V_562 )
V_191 |= 0xc0 ;
}
F_12 ( V_3 -> V_529 , 0x21 , V_507 , V_191 ) ;
}
V_191 = 0 ;
V_507 = 0x7f ;
if ( ! ( V_3 -> V_45 & V_197 ) ) {
V_507 = 0xff ;
if ( ! ( V_3 -> V_45 & V_562 ) )
V_191 |= 0x80 ;
}
F_12 ( V_3 -> V_529 , 0x23 , V_507 , V_191 ) ;
if ( V_3 -> V_144 & ( V_146 | V_228 ) ) {
if ( V_3 -> V_44 & V_595 ) {
F_20 ( V_3 -> V_529 , 0x27 , 0x20 ) ;
F_20 ( V_3 -> V_529 , 0x34 , 0x10 ) ;
}
}
}
static void F_109 ( struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_220 ;
V_220 = 0 ;
if ( V_3 -> V_45 & V_197 )
V_220 = 0x08A0 ;
}
void F_110 ( struct V_201 * V_202 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_522 , 0x2f , 0xFF , 0x01 ) ;
}
void F_111 ( struct V_201 * V_202 ,
struct V_2 * V_3 )
{
F_12 ( V_3 -> V_522 , 0x2F , 0xFE , 0x00 ) ;
}
unsigned char F_112 ( struct V_2 * V_3 )
{
unsigned short V_558 ;
if ( V_3 -> V_225 == 1 ) {
return 1 ;
} else {
V_558 = F_2 ( V_3 -> V_529 , 0x00 ) ;
if ( ( V_558 == 1 ) || ( V_558 == 2 ) )
return 1 ;
else
return 0 ;
}
}
unsigned short F_113 ( struct V_201 * V_613 ,
unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
short V_718 [] = { 0x00 , 0x00 , 0x03 , 0x01 } ,
V_719 [] = { 0x00 , 0x00 , 0x03 , 0x01 , 0x01 ,
0x01 , 0x01 } ;
unsigned short V_218 , V_193 , V_194 , V_262 , V_160 ;
V_194 = V_3 -> V_7 [ V_190 ] . V_195 ;
V_262 = F_2 ( V_3 -> V_204 , 0x33 ) ;
V_262 = V_262 >> V_3 -> V_720 ;
V_262 &= 0x0F ;
if ( V_3 -> V_44 & V_233 )
V_262 = 0 ;
if ( V_262 > 0 )
V_262 -- ;
if ( V_3 -> V_239 & V_536 ) {
if ( V_3 -> V_45 & ( V_199 | V_197 ) ) {
if ( V_3 -> V_225 == 0 ) {
if ( V_3 -> V_144 & ( V_246 | V_247
| V_145 | V_146
| V_228 ) )
V_160 = V_719 [
V_3 -> V_42 & 0x0F ] ;
else
V_160 = V_718 [
V_3 -> V_42 & 0x0F ] ;
if ( V_262 > V_160 )
V_262 = V_160 ;
} else {
V_262 = 0 ;
}
}
}
V_218 = V_3 -> V_7 [ V_190 ] . V_721 ;
V_189 = V_3 -> V_10 [ V_218 ] . V_224 ;
if ( V_613 -> V_260 >= V_156 ) {
if ( ( V_3 -> V_10 [ V_218 ] . V_722 == 800 ) &&
( V_3 -> V_10 [ V_218 ] . V_723 == 600 ) ) {
V_262 ++ ;
}
if ( ( V_3 -> V_10 [ V_218 ] . V_722 == 1024 ) &&
( V_3 -> V_10 [ V_218 ] . V_723 == 768 ) ) {
V_262 ++ ;
}
if ( ( V_3 -> V_10 [ V_218 ] . V_722 == 1280 ) &&
( V_3 -> V_10 [ V_218 ] . V_723 == 1024 ) ) {
V_262 ++ ;
}
}
V_193 = 0 ;
do {
if ( V_3 -> V_10 [ V_218 + V_193 ] .
V_224 != V_189 )
break;
V_160 = V_3 -> V_10 [ V_218 + V_193 ] .
V_253 ;
V_160 &= V_561 ;
if ( V_160 < V_3 -> V_214 )
break;
V_193 ++ ;
V_262 -- ;
} while ( V_262 != 0xFFFF );
if ( ! ( V_3 -> V_45 & V_226 ) ) {
if ( V_3 -> V_45 & V_200 ) {
V_160 = V_3 -> V_10 [ V_218 + V_193 - 1 ] .
V_253 ;
if ( V_160 & V_289 )
V_193 ++ ;
}
}
V_193 -- ;
if ( ( V_3 -> V_239 & V_536 ) ) {
V_160 = F_14 ( V_189 , V_190 ,
V_218 , & V_193 , V_3 ) ;
}
return V_218 + V_193 ;
}
static void F_114 ( unsigned short V_189 , unsigned short V_190 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_218 ;
V_3 -> V_239 |= V_536 ;
V_218 = F_113 ( V_202 , V_189 ,
V_190 , V_3 ) ;
F_35 ( V_189 , V_190 , V_3 ) ;
F_38 ( V_189 , V_190 , V_218 , V_3 ) ;
F_39 ( V_189 , V_190 , V_218 ,
V_202 , V_3 ) ;
F_43 ( V_189 , V_190 , V_218 , V_3 ) ;
F_47 ( V_189 , V_190 , V_218 , V_3 ) ;
}
static unsigned char F_115 ( unsigned short V_189 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_220 , V_190 , V_218 ;
V_220 = V_3 -> V_45 ;
V_3 -> V_239 |= V_536 ;
F_53 ( V_189 , & V_190 , V_3 ) ;
V_3 -> V_720 = 4 ;
V_218 = F_113 ( V_202 , V_189 ,
V_190 , V_3 ) ;
F_65 ( V_189 , V_3 ) ;
F_66 ( V_189 , V_190 , V_3 ) ;
F_69 ( V_189 , V_190 , V_218 , V_3 ) ;
F_75 ( V_189 , V_190 , V_202 ,
V_218 , V_3 ) ;
F_76 ( V_189 , V_190 , V_202 ,
V_218 , V_3 ) ;
F_78 ( V_189 , V_190 , V_202 ,
V_218 , V_3 ) ;
F_79 ( V_189 , V_190 , V_218 ,
V_202 , V_3 ) ;
F_80 ( V_189 , V_190 , V_202 ,
V_218 , V_3 ) ;
F_82 ( V_3 ) ;
F_83 ( V_189 , V_190 , V_3 ) ;
F_84 ( V_189 , V_190 , V_218 ,
V_202 , V_3 ) ;
F_70 ( V_189 , V_190 , V_218 , V_3 ) ;
F_86 ( V_189 , V_190 , V_3 ) ;
F_64 ( V_3 ) ;
return 1 ;
}
void F_116 ( struct V_2 * V_3 )
{
unsigned char V_724 [ 17 ] = { 0x5F , 0x4F , 0x50 , 0x82 , 0x55 , 0x81 ,
0x0B , 0x3E , 0xE9 , 0x0B , 0xDF , 0xE7 , 0x04 , 0x00 , 0x00 ,
0x05 , 0x00 } ;
unsigned char V_725 = 0 , V_726 = 0 , V_727 = 0 , V_728 = 0 ;
unsigned char V_729 , V_730 , V_731 ;
unsigned short V_160 ;
unsigned char V_732 [ 3 ] = { 0x0F , 0x0F , 0x0F } ;
int V_193 ;
F_4 ( V_3 -> V_177 , 0x05 , 0x86 ) ;
F_4 ( V_3 -> V_204 , 0x57 , 0x4A ) ;
F_4 ( V_3 -> V_204 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_204 , 0x53 ) | 0x02 ) ) ;
V_731 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x31 ) ;
V_730 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x63 ) ;
V_725 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x01 ) ;
F_4 ( V_3 -> V_177 , 0x01 , ( unsigned char ) ( V_725 & 0xDF ) ) ;
F_4 ( V_3 -> V_204 , 0x63 , ( unsigned char ) ( V_730 & 0xBF ) ) ;
V_729 = ( unsigned char ) F_2 ( V_3 -> V_204 , 0x17 ) ;
F_4 ( V_3 -> V_204 , 0x17 , ( unsigned char ) ( V_729 | 0x80 ) ) ;
V_726 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x1F ) ;
F_4 ( V_3 -> V_177 , 0x1F , ( unsigned char ) ( V_726 | 0x04 ) ) ;
V_727 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x07 ) ;
F_4 ( V_3 -> V_177 , 0x07 , ( unsigned char ) ( V_727 & 0xFB ) ) ;
V_728 = ( unsigned char ) F_2 ( V_3 -> V_177 , 0x06 ) ;
F_4 ( V_3 -> V_177 , 0x06 , ( unsigned char ) ( V_728 & 0xC3 ) ) ;
F_4 ( V_3 -> V_204 , 0x11 , 0x00 ) ;
for ( V_193 = 0 ; V_193 < 8 ; V_193 ++ )
F_4 ( V_3 -> V_204 , ( unsigned short ) V_193 , V_724 [ V_193 ] ) ;
for ( V_193 = 8 ; V_193 < 11 ; V_193 ++ )
F_4 ( V_3 -> V_204 , ( unsigned short ) ( V_193 + 8 ) ,
V_724 [ V_193 ] ) ;
for ( V_193 = 11 ; V_193 < 13 ; V_193 ++ )
F_4 ( V_3 -> V_204 , ( unsigned short ) ( V_193 + 4 ) ,
V_724 [ V_193 ] ) ;
for ( V_193 = 13 ; V_193 < 16 ; V_193 ++ )
F_4 ( V_3 -> V_177 , ( unsigned short ) ( V_193 - 3 ) ,
V_724 [ V_193 ] ) ;
F_4 ( V_3 -> V_177 , 0x0E , ( unsigned char ) ( V_724 [ 16 ]
& 0xE0 ) ) ;
F_4 ( V_3 -> V_177 , 0x31 , 0x00 ) ;
F_4 ( V_3 -> V_177 , 0x2B , 0x1B ) ;
F_4 ( V_3 -> V_177 , 0x2C , 0xE1 ) ;
F_8 ( 0x00 , V_3 -> V_349 ) ;
for ( V_193 = 0 ; V_193 < 256 ; V_193 ++ ) {
F_8 ( ( unsigned char ) V_732 [ 0 ] , ( V_3 -> V_349 + 1 ) ) ;
F_8 ( ( unsigned char ) V_732 [ 1 ] , ( V_3 -> V_349 + 1 ) ) ;
F_8 ( ( unsigned char ) V_732 [ 2 ] , ( V_3 -> V_349 + 1 ) ) ;
}
F_60 ( 1 ) ;
F_63 ( V_3 ) ;
V_160 = F_7 ( V_3 -> V_255 ) ;
if ( V_160 & 0x10 )
F_12 ( V_3 -> V_204 , 0x32 , 0xDF , 0x20 ) ;
else
F_12 ( V_3 -> V_204 , 0x32 , 0xDF , 0x00 ) ;
F_8 ( 0x00 , V_3 -> V_349 ) ;
for ( V_193 = 0 ; V_193 < 256 ; V_193 ++ ) {
F_8 ( 0 , ( V_3 -> V_349 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_349 + 1 ) ) ;
F_8 ( 0 , ( V_3 -> V_349 + 1 ) ) ;
}
F_4 ( V_3 -> V_177 , 0x01 , V_725 ) ;
F_4 ( V_3 -> V_204 , 0x63 , V_730 ) ;
F_4 ( V_3 -> V_177 , 0x31 , V_731 ) ;
F_4 ( V_3 -> V_204 , 0x53 , ( unsigned char ) ( F_2 (
V_3 -> V_204 , 0x53 ) & 0xFD ) ) ;
F_4 ( V_3 -> V_177 , 0x1F , ( unsigned char ) V_726 ) ;
}
static void F_117 ( struct V_606 * V_607 ,
struct V_201 * V_202 ,
struct V_2 * V_3 )
{
unsigned short V_191 ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
if ( ! ( V_3 -> V_239 & V_694 ) ) {
if ( V_3 -> V_239 & V_696 ) {
F_4 ( V_3 -> V_522 , 0x1E , 0x20 ) ;
} else {
if ( V_3 -> V_45 & V_562 ) {
F_4 ( V_3 -> V_522 ,
0x1E , 0x20 ) ;
}
}
}
if ( ! ( V_3 -> V_239 & V_695 ) ) {
if ( ( V_3 -> V_239 & V_697 ) || ( V_3 -> V_45
& ( V_199 | V_198
| V_226 ) ) ) {
V_191 = ( unsigned char ) F_2 (
V_3 -> V_177 , 0x32 ) ;
V_191 &= 0xDF ;
if ( V_3 -> V_45 & V_200 ) {
if ( ! ( V_3 -> V_45 &
V_226 ) )
V_191 |= 0x20 ;
}
F_4 ( V_3 -> V_177 , 0x32 , V_191 ) ;
F_20 ( V_3 -> V_177 , 0x1E , 0x20 ) ;
V_191 = ( unsigned char ) F_2 (
V_3 -> V_522 , 0x2E ) ;
if ( ! ( V_191 & 0x80 ) )
F_20 ( V_3 -> V_522 ,
0x2E , 0x80 ) ;
F_13 ( V_3 -> V_522 , 0x00 , 0x7F ) ;
}
}
if ( ( V_3 -> V_239 & ( V_696 | V_697 ) )
|| ( ! ( V_3 -> V_45 & V_563 ) ) ) {
F_12 ( V_3 -> V_549 , 0x00 , ~ 0xE0 ,
0x20 ) ;
if ( V_3 -> V_144 & ( V_146 | V_228 ) ) {
if ( ! F_92 ( V_3 ) ) {
if ( F_93 ( V_3 ) ||
( V_3 -> V_45 &
( V_199 | V_197 ) ) )
F_13 (
V_3 -> V_529 ,
0x2A ,
0x7F ) ;
}
F_13 ( V_3 -> V_529 , 0x30 , 0x7F ) ;
}
}
V_191 = 0x00 ;
if ( ! ( V_3 -> V_45 & V_563 ) ) {
V_191 = 0xc0 ;
if ( ! ( V_3 -> V_45 & V_573 ) ) {
if ( V_3 -> V_45 & V_197 ) {
if ( V_3 -> V_45 &
V_562 ) {
V_191 = V_191 & 0x40 ;
if ( V_3 -> V_45 &
V_197 )
V_191 = V_191 ^ 0xC0 ;
if ( V_3 -> V_239 &
V_695 )
V_191 &= 0xBF ;
if ( V_3 -> V_239 &
V_694 )
V_191 &= 0x7F ;
if ( V_3 -> V_239 &
V_697 )
V_191 |= 0x40 ;
if ( V_3 -> V_239 &
V_696 )
V_191 |= 0x80 ;
}
}
}
}
F_20 ( V_3 -> V_529 , 0x1F , V_191 ) ;
if ( ! ( V_3 -> V_239 & V_694 ) ) {
if ( ! ( V_3 -> V_239 & V_698 ) ) {
F_88 ( V_202 ,
V_3 ) ;
F_61 ( V_607 , V_202 ,
V_3 ) ;
}
}
}
else {
if ( V_3 -> V_45 & ( V_198 | V_199
| V_197 ) )
F_20 ( V_3 -> V_522 , 0x1E , 0x20 ) ;
V_191 = ( unsigned char ) F_2 ( V_3 -> V_522 ,
0x2E ) ;
if ( ! ( V_191 & 0x80 ) )
F_20 ( V_3 -> V_522 , 0x2E , 0x80 ) ;
F_13 ( V_3 -> V_522 , 0x00 , 0x7F ) ;
F_61 ( V_607 , V_202 , V_3 ) ;
}
}
static void F_118 ( struct V_606 * V_607 ,
struct V_201 * V_202 ,
unsigned short V_189 , unsigned short V_190 ,
struct V_2 * V_3 )
{
unsigned short V_218 , V_160 ;
F_3 ( V_189 , V_190 , V_3 ) ;
F_8 ( V_3 -> V_4 -> V_733 , V_3 -> V_255 ) ;
F_5 ( V_202 , V_3 ) ;
F_6 ( V_189 , V_190 , V_3 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
if ( V_202 -> V_260 == V_159 ) {
if ( V_3 -> V_225 == 0 )
F_11 ( V_3 ) ;
}
V_160 = ~ V_536 ;
V_3 -> V_239 &= V_160 ;
V_3 -> V_720 = 0 ;
if ( V_3 -> V_144 & ( V_246 | V_247 | V_145
| V_146 | V_228 ) ) {
if ( V_3 -> V_45 & ( V_573 | V_197
| V_200 ) ) {
V_3 -> V_239 |= V_536 ;
}
}
V_218 = F_113 ( V_202 , V_189 ,
V_190 , V_3 ) ;
if ( V_218 != 0xFFFF ) {
F_15 ( V_218 , V_3 ) ;
F_18 ( V_189 , V_190 , V_218 ,
V_3 , V_202 ) ;
F_25 ( V_202 , V_189 , V_190 ,
V_218 , V_3 ) ;
F_26 ( V_189 , V_190 , V_218 ,
V_202 , V_3 ) ;
F_28 ( V_189 , V_190 , V_202 ,
V_218 , V_3 ) ;
}
if ( V_202 -> V_260 >= V_328 ) {
V_160 = F_2 ( V_3 -> V_204 , 0x38 ) ;
if ( V_160 & 0xA0 ) {
if ( V_202 -> V_260 == V_159 )
F_21 ( V_189 , V_190 ,
V_218 , V_3 ) ;
else
F_19 ( V_189 , V_190 ,
V_218 , V_3 ) ;
F_24 ( V_189 , V_3 ,
V_218 ) ;
F_23 ( V_202 -> V_260 ,
V_3 , V_218 , V_189 ) ;
if ( V_3 -> V_225 == 1 )
F_90 ( V_607 ,
V_202 -> V_260 ,
V_189 , V_190 , V_3 ) ;
}
}
V_3 -> V_239 &= ( ~ V_536 ) ;
F_30 ( V_189 , V_202 , V_3 ) ;
F_32 ( V_202 , V_189 , V_190 ,
V_218 , V_3 ) ;
F_34 ( V_189 , V_190 , V_3 ) ;
}
unsigned char F_119 ( struct V_606 * V_607 ,
struct V_201 * V_202 ,
unsigned short V_189 )
{
unsigned short V_190 ;
struct V_2 V_734 ;
struct V_2 * V_3 = & V_734 ;
V_3 -> V_735 = V_607 -> V_736 ;
V_3 -> V_225 = 0 ;
V_3 -> V_564 = 1 ;
if ( V_202 -> V_260 >= V_156 ) {
V_3 -> V_568 = 0 ;
V_3 -> V_570 = 0 ;
V_3 -> V_575 = 0 ;
V_3 -> V_144 = 0 ;
} else {
V_3 -> V_568 = 1 ;
V_3 -> V_570 = 1 ;
V_3 -> V_575 = 1 ;
}
V_3 -> V_177 = V_3 -> V_735 + 0x14 ;
V_3 -> V_204 = V_3 -> V_735 + 0x24 ;
V_3 -> V_210 = V_3 -> V_735 + 0x10 ;
V_3 -> V_213 = V_3 -> V_735 + 0x1e ;
V_3 -> V_255 = V_3 -> V_735 + 0x12 ;
V_3 -> V_277 = V_3 -> V_735 + 0x1C ;
V_3 -> V_542 = V_3 -> V_735 + 0x1a ;
V_3 -> V_348 = V_3 -> V_735 + 0x16 ;
V_3 -> V_737 = V_3 -> V_735 + 0x17 ;
V_3 -> V_349 = V_3 -> V_735 + 0x18 ;
V_3 -> V_338 = V_3 -> V_735 + 0x19 ;
V_3 -> V_209 = V_3 -> V_735 + 0x2A ;
V_3 -> V_738 = V_3 -> V_735 + V_739 ;
V_3 -> V_522 = V_3 -> V_735 + V_740 ;
V_3 -> V_549 = V_3 -> V_735 + V_741 ;
V_3 -> V_665 = V_3 -> V_735 + V_742 ;
V_3 -> V_529 = V_3 -> V_735 + V_743 ;
V_3 -> V_670 = V_3 -> V_735 + V_743 + 2 ;
if ( V_202 -> V_260 == V_328 ) {
if ( ( F_2 ( V_3 -> V_204 , 0x38 ) & 0xE0 ) == 0xC0 )
V_3 -> V_225 = 1 ;
}
if ( V_202 -> V_260 == V_159 ) {
if ( ( F_2 ( V_3 -> V_204 , 0x38 ) & 0xE0 ) == 0xC0 ) {
if ( F_2 ( V_3 -> V_204 , 0x30 ) & 0x20 )
V_3 -> V_225 = 1 ;
}
}
if ( V_202 -> V_260 < V_156 )
F_49 ( V_3 ) ;
F_1 ( V_202 -> V_260 , V_3 ) ;
if ( V_189 & 0x80 )
V_189 = V_189 & 0x7F ;
F_4 ( V_3 -> V_177 , 0x05 , 0x86 ) ;
if ( V_202 -> V_260 < V_156 )
F_110 ( V_202 , V_3 ) ;
F_53 ( V_189 , & V_190 , V_3 ) ;
if ( V_202 -> V_260 < V_156 ) {
F_50 ( V_189 , V_190 , V_202 , V_3 ) ;
F_51 ( V_189 , V_190 , V_3 ) ;
F_52 ( V_189 , V_190 , V_3 ) ;
F_94 ( V_607 , V_202 , V_3 ) ;
if ( V_3 -> V_45 & ( V_573 | V_197 ) ) {
F_118 ( V_607 , V_202 , V_189 ,
V_190 , V_3 ) ;
if ( V_3 -> V_45 & V_197 ) {
F_114 ( V_189 , V_190 ,
V_202 , V_3 ) ;
}
} else {
if ( ! ( V_3 -> V_45 & V_574 ) ) {
F_118 ( V_607 ,
V_202 , V_189 ,
V_190 , V_3 ) ;
if ( V_3 -> V_45 & V_197 ) {
F_114 ( V_189 , V_190 ,
V_202 ,
V_3 ) ;
}
}
}
if ( V_3 -> V_45 & ( V_573 | V_574 ) ) {
switch ( V_202 -> V_744 ) {
case V_745 :
F_115 ( V_189 , V_202 ,
V_3 ) ;
break;
case V_746 :
F_115 ( V_189 , V_202 ,
V_3 ) ;
break;
default:
break;
}
}
F_108 ( V_189 , V_202 , V_3 ) ;
F_107 ( V_189 , V_190 , V_3 ) ;
F_109 ( V_202 , V_3 ) ;
F_117 ( V_607 , V_202 , V_3 ) ;
}
else {
if ( V_3 -> V_225 == 1 )
if ( ! F_89 ( V_607 , V_189 ,
V_190 ,
V_3 ) )
return 0 ;
V_3 -> V_214 = V_3 -> V_7 [ V_190 ] .
V_195 & V_561 ;
V_3 -> V_239 = 0 ;
V_3 -> V_45 = V_563 ;
F_62 ( V_607 , V_202 , V_3 ) ;
F_118 ( V_607 , V_202 , V_189 ,
V_190 , V_3 ) ;
F_61 ( V_607 , V_202 , V_3 ) ;
}
F_48 ( V_202 , V_3 ) ;
if ( V_202 -> V_260 < V_156 ) {
F_111 ( V_202 , V_3 ) ;
}
return 1 ;
}
