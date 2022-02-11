static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> error ;
V_2 -> error = 0 ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_4 , T_2 * V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_2 V_11 = V_4 ;
struct V_12 V_13 [] = {
{
. V_4 = V_14 [ V_4 >> 8 ] ,
. V_15 = V_10 -> V_15 ,
. V_6 = 1 ,
. V_5 = & V_11
} ,
{
. V_4 = V_14 [ V_4 >> 8 ] ,
. V_15 = V_10 -> V_15 | V_16 ,
. V_6 = V_6 ,
. V_5 = V_5
} ,
} ;
int V_3 ;
if ( V_2 -> error )
return;
V_3 = F_4 ( V_10 -> V_17 , V_13 , 2 ) ;
F_5 ( V_8 , L_1 , V_4 , V_6 , V_5 , V_3 ) ;
if ( V_3 != 2 ) {
F_6 ( V_8 , L_2 ,
V_4 , V_6 , V_3 ) ;
V_2 -> error = V_3 < 0 ? V_3 : - V_18 ;
}
}
static T_2 F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
T_2 V_3 ;
F_2 ( V_2 , V_4 , & V_3 , 1 ) ;
return V_3 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_4 , const T_2 * V_5 ,
int V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_2 V_11 [ 2 ] ;
struct V_12 V_13 = {
. V_4 = V_14 [ V_4 >> 8 ] ,
. V_15 = V_10 -> V_15 ,
. V_6 = V_6 + 1 ,
} ;
int V_3 ;
if ( V_2 -> error )
return;
if ( V_6 > 1 ) {
V_13 . V_5 = F_9 ( V_6 + 1 , V_19 ) ;
if ( ! V_13 . V_5 ) {
V_2 -> error = - V_20 ;
return;
}
memcpy ( V_13 . V_5 + 1 , V_5 , V_6 ) ;
} else {
V_13 . V_5 = V_11 ;
V_13 . V_5 [ 1 ] = * V_5 ;
}
V_13 . V_5 [ 0 ] = V_4 ;
V_3 = F_4 ( V_10 -> V_17 , & V_13 , 1 ) ;
F_5 ( V_8 , L_3 , V_4 , V_6 , V_5 , V_3 ) ;
if ( V_3 != 1 ) {
F_6 ( V_8 , L_4 ,
V_4 , V_6 , V_5 , V_3 ) ;
V_2 -> error = V_3 ? : - V_18 ;
}
if ( V_6 > 1 )
F_10 ( V_13 . V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 , const T_1 * V_21 , int V_6 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 += 2 )
F_12 ( V_2 , V_21 [ V_22 ] , V_21 [ V_22 + 1 ] ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_23 , T_2 V_24 )
{
V_24 = ( V_24 & V_23 ) | ( F_7 ( V_2 , V_4 ) & ~ V_23 ) ;
F_12 ( V_2 , V_4 , V_24 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_25 * V_13 , * V_26 ;
F_15 (msg, n, &ctx->mt_queue, node) {
F_16 ( & V_13 -> V_27 ) ;
F_10 ( V_13 ) ;
}
V_2 -> V_28 = V_29 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_25 * V_13 ;
if ( V_2 -> error )
return;
if ( V_2 -> V_28 == V_30 || F_18 ( & V_2 -> V_31 ) )
return;
if ( V_2 -> V_28 == V_32 ) {
V_2 -> V_28 = V_29 ;
V_13 = F_19 ( & V_2 -> V_31 , struct V_25 ,
V_27 ) ;
if ( V_13 -> V_33 )
V_13 -> V_33 ( V_2 , V_13 ) ;
F_16 ( & V_13 -> V_27 ) ;
F_10 ( V_13 ) ;
}
if ( V_2 -> V_28 != V_29 || F_18 ( & V_2 -> V_31 ) )
return;
V_2 -> V_28 = V_30 ;
V_13 = F_19 ( & V_2 -> V_31 , struct V_25 , V_27 ) ;
if ( V_13 -> V_34 )
V_13 -> V_34 ( V_2 , V_13 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_25 * V_13 )
{
switch ( V_13 -> V_35 [ 0 ] ) {
case V_36 :
case V_37 :
F_8 ( V_2 , V_38 , V_13 -> V_35 + 1 , 2 ) ;
F_12 ( V_2 , V_39 ,
V_40 ) ;
break;
case V_41 :
F_8 ( V_2 , V_38 , V_13 -> V_35 , 3 ) ;
F_12 ( V_2 , V_39 ,
V_42 ) ;
break;
default:
F_6 ( V_2 -> V_8 , L_5 , V_43 ,
V_13 -> V_35 [ 0 ] ) ;
}
}
static struct V_25 * F_21 ( struct V_1 * V_2 )
{
struct V_25 * V_13 = F_22 ( sizeof( * V_13 ) , V_19 ) ;
if ( ! V_13 )
V_2 -> error = - V_20 ;
else
F_23 ( & V_13 -> V_27 , & V_2 -> V_31 ) ;
return V_13 ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_44 , T_2 V_45 , T_2 V_46 )
{
struct V_25 * V_13 = F_21 ( V_2 ) ;
if ( ! V_13 )
return;
V_13 -> V_35 [ 0 ] = V_44 ;
V_13 -> V_35 [ 1 ] = V_45 ;
V_13 -> V_35 [ 2 ] = V_46 ;
V_13 -> V_34 = F_20 ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_35 , T_2 V_24 )
{
F_24 ( V_2 , V_36 , V_35 , V_24 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_23 )
{
F_24 ( V_2 , V_37 , V_47 , V_23 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_44 , T_2 V_11 )
{
F_24 ( V_2 , V_41 , V_44 , V_11 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_48 )
{
F_27 ( V_2 , V_49 , V_48 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_25 * V_13 )
{
T_2 V_50 = V_51
| V_52
| V_53 ;
if ( V_13 -> V_35 [ 0 ] == V_54 )
V_50 |= V_55 ;
F_30 ( V_2 ,
V_56 , V_57 ,
V_58 , V_50 ,
V_59 , V_60
) ;
}
static void F_31 ( T_2 * V_61 , T_2 * V_62 , int V_63 )
{
while ( -- V_63 >= 0 ) {
* V_62 ^= * V_61 ;
* V_61 ++ ^= * V_62 ++ ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
static const char * const V_64 [] = {
[ V_65 ] = L_6 ,
[ V_66 ] = L_7 ,
[ V_67 ] = L_8
} ;
T_2 V_68 [ V_69 ] ;
char V_70 [ 20 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_2 ( V_2 , V_71 , V_68 , V_69 ) ;
if ( V_2 -> error < 0 )
return;
F_33 ( V_8 , L_9 , V_69 , V_68 ) ;
F_33 ( V_8 , L_10 ,
V_68 [ V_72 ] / 16 ,
V_68 [ V_72 ] % 16 , V_68 [ V_73 ] ,
V_68 [ V_74 ] , V_68 [ V_75 ] ,
V_68 [ V_76 ] ) ;
F_31 ( V_2 -> V_77 , V_68 , V_69 ) ;
if ( ! ( V_68 [ V_78 ] & V_79 ) )
return;
F_34 ( V_2 ) ;
if ( ! V_2 -> V_80 ) {
F_6 ( V_2 -> V_8 , L_11 ) ;
F_35 ( V_2 ) ;
return;
}
if ( F_36 ( V_2 -> V_80 ) )
V_2 -> V_81 = V_66 ;
else
V_2 -> V_81 = V_67 ;
F_37 ( V_2 -> V_80 , V_70 , F_38 ( V_70 ) ) ;
F_33 ( V_8 , L_12 ,
V_64 [ V_2 -> V_81 ] , V_70 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_71 , V_2 -> V_82 ,
V_83 ) ;
F_25 ( V_2 , F_42 ( V_84 ) ,
V_85 | V_86 ) ;
F_28 ( V_2 , V_87 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_25 * V_13 )
{
T_2 V_50 = V_51
| V_52
| V_53 ;
if ( V_13 -> V_35 [ 0 ] == V_54 )
V_50 |= V_55 ;
F_30 ( V_2 ,
V_56 , V_57 | V_88
| V_89 ,
V_58 , V_50 ,
V_90 , 0
) ;
if ( V_13 -> V_35 [ 0 ] == V_54 )
F_41 ( V_2 ) ;
else
F_32 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 , bool V_82 )
{
struct V_25 * V_13 = F_21 ( V_2 ) ;
if ( ! V_13 )
return;
V_13 -> V_35 [ 0 ] = V_82 ? V_54 : V_91 ;
V_13 -> V_34 = F_29 ;
V_13 -> V_33 = F_43 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_2 V_92 , V_93 , V_94 , V_95 ;
int V_96 , V_22 ;
int V_97 = V_98 ;
T_2 * V_80 ;
F_7 ( V_2 , V_99 ) ;
V_92 = F_7 ( V_2 , V_100 ) ;
V_93 = F_7 ( V_2 , V_101 ) ;
F_30 ( V_2 ,
V_56 , 0 ,
V_58 , V_52 ,
V_102 , 0x71 ,
V_103 , V_104 ,
V_100 , V_92 | V_105 ,
) ;
for ( V_22 = 0 ; V_22 < 256 ; ++ V_22 ) {
T_2 V_106 = F_7 ( V_2 , V_107 ) ;
if ( ! ( V_106 & V_108 ) )
break;
F_12 ( V_2 , V_107 ,
V_109 ) ;
}
F_12 ( V_2 , V_110 , 0x50 << 1 ) ;
V_80 = F_9 ( V_98 , V_19 ) ;
if ( ! V_80 ) {
V_2 -> error = - V_20 ;
return;
}
#define F_45 16
for ( V_96 = 0 ; V_96 < V_97 ; V_96 += F_45 ) {
F_7 ( V_2 , V_107 ) ;
F_30 ( V_2 ,
V_101 , V_93 | V_111 ,
V_101 , V_93 | V_112 ,
V_107 , V_109
) ;
F_30 ( V_2 ,
V_113 , V_96 >> 8 ,
V_114 , V_96 & 0xff ,
V_115 , F_45 ,
V_116 , 0 ,
V_101 , V_93 | V_117
) ;
do {
V_94 = F_7 ( V_2 , V_118 ) ;
V_95 = F_7 ( V_2 , V_99 ) ;
if ( V_94 & V_119 )
break;
if ( ! ( V_95 & V_120 ) ) {
F_10 ( V_80 ) ;
V_80 = NULL ;
goto V_121;
}
} while ( 1 );
F_7 ( V_2 , V_107 ) ;
while ( F_7 ( V_2 , V_122 ) < F_45 )
F_46 ( 10 , 20 ) ;
F_2 ( V_2 , V_123 , V_80 + V_96 , F_45 ) ;
if ( V_96 + F_45 == V_98 ) {
T_2 V_124 = ( (struct V_80 * ) V_80 ) -> V_125 ;
if ( V_124 ) {
T_2 * V_126 ;
V_97 += V_124 * V_98 ;
V_126 = F_47 ( V_80 , V_97 , V_19 ) ;
if ( ! V_126 ) {
F_10 ( V_80 ) ;
V_2 -> error = - V_20 ;
return;
}
V_80 = V_126 ;
}
}
if ( V_96 + F_45 == V_97 )
F_12 ( V_2 , V_118 , V_94 ) ;
}
F_12 ( V_2 , V_100 , V_92 ) ;
V_121:
F_10 ( V_2 -> V_80 ) ;
V_2 -> V_80 = (struct V_80 * ) V_80 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_127 , V_128 | V_129
| V_130 , 0xff ) ;
F_48 ( V_2 ,
V_131 , 0x00 ,
V_132 , 0xFF ,
V_133 , 0xFF ,
V_134 , 0x06
) ;
F_13 ( V_2 , V_135 ,
V_136 , 0xff ) ;
F_48 ( V_2 ,
V_58 , V_52
| V_53 ,
V_90 , 0 ,
) ;
F_8 ( V_2 , V_137 , ( T_2 * ) V_2 -> V_80 ,
( V_2 -> V_80 -> V_125 + 1 ) * V_98 ) ;
F_48 ( V_2 ,
V_58 , V_138
| V_52
| V_53 ,
V_139 , V_140 ,
V_56 , 0
) ;
}
static void F_49 ( struct V_1 * V_2 )
{
static const struct {
unsigned int V_141 ;
T_2 div ;
T_2 V_142 ;
} V_143 [] = {
{ 19200 , 0x04 , 0x53 } ,
{ 20000 , 0x04 , 0x62 } ,
{ 24000 , 0x05 , 0x75 } ,
{ 30000 , 0x06 , 0x92 } ,
{ 38400 , 0x0c , 0xbc } ,
} ;
unsigned long V_141 = F_50 ( V_2 -> V_144 ) / 1000 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_38 ( V_143 ) - 1 ; ++ V_22 )
if ( V_141 <= V_143 [ V_22 ] . V_141 )
break;
if ( V_141 != V_143 [ V_22 ] . V_141 )
F_6 ( V_2 -> V_8 , L_13 ,
V_141 , V_143 [ V_22 ] . V_141 ) ;
F_12 ( V_2 , V_145 , V_143 [ V_22 ] . div ) ;
F_12 ( V_2 , V_146 , V_143 [ V_22 ] . V_142 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_52 ( F_38 ( V_2 -> V_147 ) , V_2 -> V_147 ) ;
if ( V_3 )
return V_3 ;
F_46 ( 10000 , 20000 ) ;
return F_53 ( V_2 -> V_144 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_144 ) ;
F_56 ( V_2 -> V_148 , 1 ) ;
return F_57 ( F_38 ( V_2 -> V_147 ) , V_2 -> V_147 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_46 ( 10000 , 20000 ) ;
F_56 ( V_2 -> V_148 , 0 ) ;
F_46 ( 5000 , 20000 ) ;
F_56 ( V_2 -> V_148 , 1 ) ;
F_46 ( 10000 , 20000 ) ;
F_56 ( V_2 -> V_148 , 0 ) ;
F_59 ( 300 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_48 ( V_2 ,
V_149 , V_150
| V_151 ,
V_149 , V_151
) ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_152 != V_153 ) {
F_48 ( V_2 ,
V_154 , 0x0 ,
V_155 , V_156
| V_157
| V_158
) ;
} else {
F_48 ( V_2 ,
V_154 , V_159 ,
V_155 , V_156
| V_158
) ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
T_2 V_160 ( V_24 ) ;
F_48 ( V_2 ,
V_161 , 0 ,
V_162 , 0 ,
V_163 , 0 ,
V_164 , ~ 0 ,
) ;
switch ( V_2 -> V_81 ) {
case V_67 :
V_24 = V_165
| V_166 ;
break;
case V_66 :
V_24 = V_165
| V_166
| V_167 ;
break;
default:
return;
}
F_12 ( V_2 , V_168 , V_24 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_48 ( V_2 ,
V_169 , V_170
| V_171 ,
V_172 , V_173
| V_174 ,
V_175 , 0 ,
V_176 , 0x1 ,
V_177 , 0xa0 ,
V_178 , F_64 ( V_179 , V_180 ) ,
V_181 , F_64 ( V_179 , V_180 ) ,
) ;
F_25 ( V_2 , F_65 ( V_182 ) ,
V_183 |
V_184 ) ;
F_61 ( V_2 ) ;
F_12 ( V_2 , V_168 , V_167 ) ;
F_8 ( V_2 , V_185 , V_2 -> V_186 ,
F_38 ( V_2 -> V_186 ) ) ;
F_12 ( V_2 , V_132 , 0xa1 , 0x2 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_152 < V_187 )
F_62 ( V_2 ) ;
switch ( V_2 -> V_81 ) {
case V_66 :
F_63 ( V_2 ) ;
break;
case V_67 :
default:
break;
}
}
static void F_67 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_58 , V_138 , 0 ) ;
F_48 ( V_2 ,
V_188 , V_189 ,
V_190 , 0
) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_191 ,
V_192
| V_193 , ~ 0 ) ;
F_48 ( V_2 ,
V_188 , V_189
| V_194 ,
) ;
}
static void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_195 )
return;
F_48 ( V_2 ,
V_196 , 100 ,
V_197 , V_198
) ;
V_2 -> V_195 = 1 ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_195 )
return;
F_48 ( V_2 ,
V_199 , 0 ,
V_197 , 0
) ;
V_2 -> V_195 = 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_48 ( V_2 ,
V_200 , V_201
| V_202 | V_203
| V_204 | V_205
| V_206 ,
V_207 , V_208
| V_209
| V_210
) ;
F_68 ( V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_48 ( V_2 ,
V_211 , V_212
| V_213 ,
V_214 , F_72 ( V_215 , V_216 ) ,
V_217 , V_218
| V_219
| V_220
| V_221
| V_222
| V_223 ,
V_155 , V_156
| V_157
| V_158 ,
V_224 , V_225
| V_226 ,
V_227 , V_228 ,
V_229 , 0xA2 ,
V_230 , 0x03 ,
V_231 , 0x35 ,
V_232 , 0x02 ,
V_233 , 0x02 ,
V_234 , 0x03 ,
V_235 , 0xFF ,
V_127 , V_236 | V_237
| V_238 | V_239 ,
V_240 , V_241
| V_242 ,
V_243 , V_244
| V_245 ,
V_246 , V_247
| V_248
| V_249
| V_250
| V_251
| V_252
| V_253
) ;
}
static void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_152 == V_187 )
F_48 ( V_2 ,
V_254 , V_255 ,
V_256 ,
V_257
) ;
else
F_48 ( V_2 ,
V_162 , 0x00 ,
V_256 , 0x00 ,
V_258 , 0xFF ,
V_259 , 0xFF ,
V_254 , V_255
| V_260
) ;
}
static void F_74 ( struct V_1 * V_2 )
{
static const T_2 V_77 [ V_69 ] = {
[ V_72 ] = V_261 ,
[ V_78 ] = V_262 | V_263 ,
[ V_73 ] = 0x01 ,
[ V_74 ] = 0x41 ,
[ V_264 ] = V_265
| V_266
| V_267 ,
[ V_268 ] = V_269 ,
[ V_270 ] = V_271 ,
[ V_272 ] = V_273 ,
[ V_274 ] = 0x0f ,
[ V_275 ] = V_276
| V_277
| V_278 ,
[ V_279 ] = V_280 ,
[ V_281 ] = V_282 ,
} ;
static const T_2 V_283 [ V_83 ] = {
[ V_284 ] = V_285
| V_286 ,
[ V_287 ] = V_288
| V_289 | V_290 ,
[ V_291 ] = V_292 ,
[ V_293 ] = V_294 ,
} ;
F_8 ( V_2 , V_295 , V_77 , F_38 ( V_77 ) ) ;
F_8 ( V_2 , V_296 , V_283 , F_38 ( V_283 ) ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_48 ( V_2 ,
V_214 , F_72 ( V_297 , V_216 ) ,
V_298 ,
V_299 ,
) ;
F_73 ( V_2 ) ;
F_67 ( V_2 ) ;
F_48 ( V_2 ,
V_58 , V_52 ,
V_211 , V_212
| V_300 ,
V_301 , 0x90 ,
V_302 , 0x01 ,
V_303 , 0x11 ,
V_304 , 0x87 ,
V_305 , 0xE8 ,
V_306 , 0x04 ,
) ;
F_13 ( V_2 , V_100 , V_105 , 0 ) ;
F_48 ( V_2 ,
V_307 , 0x76 ,
V_308 , V_309 ,
V_310 , 79 ,
) ;
F_74 ( V_2 ) ;
F_48 ( V_2 ,
V_311 , 100 ,
V_199 , 0x03 ,
V_312 , 0x00 ,
V_196 , 100 ,
V_313 , 0x1D ,
) ;
F_70 ( V_2 ) ;
F_48 ( V_2 ,
V_314 , 0x00 ,
V_315 , 0x10 ,
V_316 , 0x18 ,
V_317 , 0x07 ,
V_318 , 0xF8 ,
V_319 , 0x61 ,
V_320 , 0x46 ,
V_321 , 0x15 ,
V_322 , 0x01 ,
V_323 , V_324 ,
V_325 , 0x2D ,
V_326 , 0xF9 ,
V_327 , 0x27 ,
) ;
F_69 ( V_2 ) ;
F_25 ( V_2 , F_65 ( V_328 ) , 0 ) ;
F_25 ( V_2 , F_65 ( V_329 ) ,
V_330 | V_331
| V_332 ) ;
F_26 ( V_2 , F_76 ( V_333 ) , V_334 ) ;
}
static void F_77 ( struct V_1 * V_2 , enum V_335 V_152 )
{
if ( V_2 -> V_152 == V_152 )
return;
V_2 -> V_152 = V_152 ;
switch ( V_152 ) {
case V_153 :
F_48 ( V_2 ,
V_298 , 0x02 ,
V_227 , V_336 ,
V_127 , V_236 | V_237
| V_238 ,
V_240 , 0
) ;
break;
case V_187 :
F_48 ( V_2 ,
V_227 , V_228 ,
V_337 , 0x40 ,
V_338 , 0x07
) ;
break;
case V_339 :
break;
default:
F_6 ( V_2 -> V_8 , L_14 , V_43 , V_152 ) ;
break;
}
F_61 ( V_2 ) ;
if ( V_152 != V_153 )
return;
F_48 ( V_2 ,
V_224 , 0xBC ,
V_229 , 0xBB ,
V_231 , 0x48 ,
V_232 , 0x39 ,
V_230 , 0x2A ,
V_233 , 0x2A ,
V_234 , 0x08
) ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
F_62 ( V_2 ) ;
F_59 ( 50 ) ;
F_60 ( V_2 ) ;
F_77 ( V_2 , V_339 ) ;
F_48 ( V_2 ,
V_337 , 0x40 ,
V_340 , 0x84 ,
V_341 , 0x00 ,
V_337 , 0x40 ,
V_342 , 0x07 ,
V_155 , V_156
| V_157
| V_158 ,
V_224 , V_225
| V_226 ,
V_229 , 0xBB ,
V_231 , 0x48 ,
V_232 , 0x3F ,
V_230 , 0x2F ,
V_233 , 0x2A ,
V_234 , 0x03
) ;
F_67 ( V_2 ) ;
F_48 ( V_2 ,
V_227 , V_228 ,
V_338 , 0x07 ,
V_214 , F_72 ( V_297 , V_216 ) ,
V_343 , 0x00 ,
V_211 , V_212
| V_300 ,
V_344 , 0x00 ,
V_327 , 0x27 ,
V_345 , 0x25 ,
V_346 , ( T_2 ) ~ V_223 ,
V_217 , V_223 ,
V_347 , 0xff ,
V_200 , 0x00 ,
V_348 , 0xff ,
V_207 , 0x00 ,
V_349 , 0xff ,
V_240 , 0x00 ,
V_350 , 0xff ,
V_351 , 0x00 ,
V_352 , 0xff ,
V_246 , 0x00 ,
V_353 , 0xff ,
V_243 , 0x00 ,
V_354 , 0xff ,
V_355 , 0x00 ,
V_356 , 0xff ,
V_256 , 0x00 ,
V_357 , 0xff ,
V_190 , 0x00 ,
V_164 , 0xff ,
V_161 , 0x00 ,
V_258 , 0xff ,
V_162 , 0x00 ,
V_358 , 0xff ,
V_56 , 0x00 ,
V_118 , 0xff ,
V_359 , 0x00 ,
V_360 , 0xff ,
V_139 , 0x00 ,
V_361 , 0xff ,
V_362 , 0x00 ,
) ;
memset ( V_2 -> V_363 , 0 , sizeof( V_2 -> V_363 ) ) ;
memset ( V_2 -> V_364 , 0 , sizeof( V_2 -> V_364 ) ) ;
memset ( V_2 -> V_77 , 0 , sizeof( V_2 -> V_77 ) ) ;
memset ( V_2 -> V_82 , 0 , sizeof( V_2 -> V_82 ) ) ;
V_2 -> V_365 = 0 ;
V_2 -> V_81 = V_65 ;
F_10 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
F_14 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_48 ( V_2 ,
V_214 , F_72 ( V_297 , V_216 ) ,
V_298 ,
V_299
) ;
F_78 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_346 ) ;
if ( V_363 & V_366 )
F_35 ( V_2 ) ;
if ( V_363 & V_223 ) {
T_2 V_367 = F_7 ( V_2 , V_368 ) ;
if ( ( V_367 & V_369 ) == V_370 ) {
F_71 ( V_2 ) ;
} else {
F_48 ( V_2 ,
V_211 , V_212
| V_371
| V_300 ,
V_217 , V_223
| V_221
| V_222
| V_220
) ;
}
}
if ( V_363 & V_219 )
F_75 ( V_2 ) ;
F_12 ( V_2 , V_346 , V_363 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_348 ) ;
if ( V_363 & V_209 )
F_5 ( V_2 -> V_8 , L_15 ) ;
F_12 ( V_2 , V_348 , V_363 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_363 [ V_372 ] & V_330 ) {
F_77 ( V_2 , V_153 ) ;
F_73 ( V_2 ) ;
F_12 ( V_2 , V_56 , V_57
| V_88 | V_89 ) ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_363 [ V_373 ] & V_184 ) {
F_25 ( V_2 , F_65 ( V_182 ) ,
V_183
| V_184 ) ;
F_44 ( V_2 , false ) ;
} else {
F_25 ( V_2 , F_65 ( V_182 ) ,
V_183 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
T_2 V_374 [ V_375 ] , V_376 [ V_377 ] ;
F_2 ( V_2 , V_378 , V_374 , V_375 ) ;
F_2 ( V_2 , V_379 , V_376 , V_377 ) ;
F_31 ( V_2 -> V_363 , V_374 , V_375 ) ;
F_31 ( V_2 -> V_364 , V_376 , V_377 ) ;
if ( V_374 [ V_372 ] & V_330 )
F_81 ( V_2 ) ;
if ( V_374 [ V_373 ] & V_184 )
F_82 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
T_2 V_380 [ V_381 ] ;
F_2 ( V_2 , V_382 , V_380 , V_381 ) ;
F_8 ( V_2 , V_382 , V_380 , V_381 ) ;
}
static struct V_25 * F_85 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( F_18 ( & V_2 -> V_31 ) ) {
F_6 ( V_8 , L_16 ) ;
return NULL ;
}
return F_19 ( & V_2 -> V_31 , struct V_25 , V_27 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_25 * V_13 = F_85 ( V_2 ) ;
if ( ! V_13 )
return;
V_13 -> V_3 = F_7 ( V_2 , V_383 ) ;
V_2 -> V_28 = V_32 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_25 * V_13 = F_85 ( V_2 ) ;
T_2 V_5 [ 2 ] ;
if ( ! V_13 )
return;
F_2 ( V_2 , V_384 , V_5 , 2 ) ;
switch ( V_5 [ 0 ] ) {
case V_385 :
V_13 -> V_3 = V_5 [ 1 ] ;
V_2 -> V_28 = V_32 ;
break;
default:
F_6 ( V_2 -> V_8 , L_17 ,
V_43 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_352 ) ;
if ( V_363 & ~ V_248 )
F_12 ( V_2 , V_352 , V_363 & ~ V_248 ) ;
if ( V_363 & V_248 ) {
T_2 V_386 = F_7 ( V_2 , V_99 ) ;
if ( ( V_386 ^ V_2 -> V_365 ) & V_387 ) {
F_12 ( V_2 , V_352 , V_248 ) ;
} else {
V_363 ^= V_387 ;
V_386 ^= V_387 ;
}
V_2 -> V_365 = V_386 ;
}
if ( V_363 & V_249 )
F_83 ( V_2 ) ;
if ( V_363 & V_252 )
F_84 ( V_2 ) ;
if ( V_363 & V_247 )
F_86 ( V_2 ) ;
if ( V_363 & V_250 )
F_87 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_349 ) ;
F_12 ( V_2 , V_349 , V_363 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_353 ) ;
F_12 ( V_2 , V_353 , V_363 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_358 ) ;
F_12 ( V_2 , V_358 , V_363 ) ;
if ( V_363 & V_57 )
V_2 -> V_28 = V_32 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_48 ( V_2 ,
V_190 , V_388 | V_389 ,
V_168 , V_167 ,
) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_191 ,
V_192 |
V_193 ) ;
F_62 ( V_2 ) ;
F_12 ( V_2 , V_190 , 0 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_360 ) ;
if ( V_363 & V_140 ) {
T_2 V_390 = F_7 ( V_2 , V_191 ) ;
if ( V_390 & V_391 )
F_92 ( V_2 ) ;
else
F_93 ( V_2 ) ;
}
F_12 ( V_2 , V_360 , V_363 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
T_2 V_392 [ 11 ] ;
F_12 ( V_2 , V_169 ,
V_170 |
V_393 ) ;
F_2 ( V_2 , V_394 , V_392 ,
F_38 ( V_392 ) ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_169 , V_170 ) ;
F_2 ( V_2 , V_394 , V_2 -> V_186 ,
F_38 ( V_2 -> V_186 ) ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
T_2 V_363 = F_7 ( V_2 , V_357 )
& ( V_389 | V_388 ) ;
F_12 ( V_2 , V_357 , V_363 ) ;
if ( V_363 & V_389 )
F_95 ( V_2 ) ;
if ( V_363 & V_388 )
F_96 ( V_2 ) ;
if ( V_363 & ( V_389 | V_388 ) )
F_66 ( V_2 ) ;
}
static bool F_98 ( unsigned int V_395 , const T_2 * V_4 )
{
return 1 & ( V_4 [ V_395 / V_396 ] >> ( V_395 % V_396 ) ) ;
}
static T_3 F_99 ( int V_47 , void * V_11 )
{
static const struct {
int V_397 ;
void (* F_100)( struct V_1 * V_2 );
} V_398 [] = {
{ V_399 , F_79 } ,
{ V_400 , F_80 } ,
{ V_401 , F_89 } ,
{ V_402 , F_88 } ,
{ V_403 , F_90 } ,
{ V_404 , F_91 } ,
{ V_405 , F_94 } ,
{ V_406 , F_97 } ,
} ;
struct V_1 * V_2 = V_11 ;
T_2 V_407 [ V_408 ] ;
int V_22 , V_3 ;
F_101 ( & V_2 -> V_409 ) ;
F_2 ( V_2 , V_410 , V_407 , F_38 ( V_407 ) ) ;
for ( V_22 = 0 ; V_22 < F_38 ( V_398 ) ; ++ V_22 )
if ( F_98 ( V_398 [ V_22 ] . V_397 , V_407 ) )
V_398 [ V_22 ] . F_100 ( V_2 ) ;
F_17 ( V_2 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_2 -> V_8 , L_18 , V_3 ) ;
F_35 ( V_2 ) ;
}
F_102 ( & V_2 -> V_409 ) ;
return V_411 ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_2 V_412 [ 5 ] ;
int V_3 ;
V_3 = F_51 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_8 , L_19 , V_3 ) ;
return;
}
F_58 ( V_2 ) ;
F_2 ( V_2 , V_413 , V_412 , F_38 ( V_412 ) ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_8 , L_20 , V_3 ) ;
return;
}
F_33 ( V_8 , L_21 , V_412 [ 1 ] , V_412 [ 0 ] ,
V_412 [ 3 ] , V_412 [ 2 ] , V_412 [ 4 ] ) ;
F_12 ( V_2 , V_127 ,
V_236 | V_237 | V_238 ) ;
F_49 ( V_2 ) ;
F_78 ( V_2 ) ;
F_48 ( V_2 ,
V_414 , V_415
| V_416 ,
V_417 , V_418 ,
V_127 , V_236 | V_237 | V_238 ,
) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_8 , L_20 , V_3 ) ;
return;
}
F_104 ( F_3 ( V_2 -> V_8 ) -> V_47 ) ;
}
static inline struct V_1 * F_105 ( struct V_419 * V_420 )
{
return F_106 ( V_420 , struct V_1 , V_420 ) ;
}
static bool F_107 ( struct V_419 * V_420 ,
const struct V_421 * V_152 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = F_105 ( V_420 ) ;
bool V_3 = false ;
int V_423 = 74250 ;
F_101 ( & V_2 -> V_409 ) ;
if ( V_152 -> V_15 & V_424 )
goto V_425;
if ( V_2 -> V_77 [ V_264 ] & V_266 )
V_423 = 300000 ;
V_3 = V_152 -> clock <= V_423 ;
V_425:
F_102 ( & V_2 -> V_409 ) ;
return V_3 ;
}
static int F_108 ( struct V_9 * V_10 ,
const struct V_426 * V_427 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_109 ( V_8 , sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_8 = V_8 ;
F_110 ( & V_2 -> V_409 ) ;
F_111 ( & V_2 -> V_31 ) ;
V_2 -> V_144 = F_112 ( V_8 , L_22 ) ;
if ( F_113 ( V_2 -> V_144 ) ) {
F_6 ( V_8 , L_23 ) ;
return F_114 ( V_2 -> V_144 ) ;
}
if ( ! V_10 -> V_47 ) {
F_6 ( V_8 , L_24 ) ;
return - V_428 ;
}
F_115 ( V_10 -> V_47 , V_429 ) ;
V_3 = F_116 ( V_8 , V_10 -> V_47 , NULL ,
F_99 ,
V_430 | V_431 ,
L_25 , V_2 ) ;
V_2 -> V_148 = F_117 ( V_8 , L_26 , V_432 ) ;
if ( F_113 ( V_2 -> V_148 ) ) {
F_6 ( V_8 , L_27 ) ;
return F_114 ( V_2 -> V_148 ) ;
}
V_2 -> V_147 [ 0 ] . V_433 = L_28 ;
V_2 -> V_147 [ 1 ] . V_433 = L_29 ;
V_3 = F_118 ( V_8 , 2 , V_2 -> V_147 ) ;
if ( V_3 )
return V_3 ;
F_119 ( V_10 , V_2 ) ;
V_2 -> V_420 . V_434 = & V_435 ;
V_2 -> V_420 . V_436 = V_8 -> V_436 ;
F_120 ( & V_2 -> V_420 ) ;
F_103 ( V_2 ) ;
return 0 ;
}
static int F_121 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_122 ( V_10 ) ;
F_123 ( F_3 ( V_2 -> V_8 ) -> V_47 ) ;
F_124 ( & V_2 -> V_420 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
