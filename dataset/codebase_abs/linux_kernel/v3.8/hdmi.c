static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline unsigned long F_4 ( struct V_1 * V_6 ,
unsigned long V_7 )
{
return F_5 ( V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static inline void F_6 ( struct V_1 * V_6 , unsigned long V_9 ,
unsigned long V_7 )
{
F_7 ( V_9 , V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static const struct V_10 *
F_8 ( unsigned int V_11 , unsigned int V_12 )
{
const struct V_10 * V_13 ;
switch ( V_11 ) {
case 32000 :
V_13 = V_14 ;
break;
case 44100 :
V_13 = V_15 ;
break;
case 48000 :
V_13 = V_16 ;
break;
case 88200 :
V_13 = V_17 ;
break;
case 96000 :
V_13 = V_18 ;
break;
case 176400 :
V_13 = V_19 ;
break;
case 192000 :
V_13 = V_20 ;
break;
default:
return NULL ;
}
while ( V_13 -> V_12 ) {
if ( V_13 -> V_12 == V_12 )
return V_13 ;
V_13 ++ ;
}
return NULL ;
}
static void F_9 ( struct V_1 * V_6 )
{
const unsigned int V_21 [] = {
32000 , 44100 , 48000 , 88200 , 96000 , 176400 , 192000
} ;
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < F_10 ( V_21 ) ; V_22 ++ ) {
unsigned int V_23 = V_21 [ V_22 ] ;
unsigned int V_24 ;
unsigned long V_25 ;
unsigned int V_26 ;
if ( V_23 > 96000 )
V_26 = 2 ;
else if ( V_23 > 480000 )
V_26 = 6 ;
else
V_26 = 9 ;
V_24 = ( 8 * V_27 ) / ( V_23 * 128 ) ;
V_25 = F_11 ( V_24 - V_26 ) |
F_12 ( V_24 + V_26 ) ;
F_6 ( V_6 , V_25 , F_13 ( V_22 ) ) ;
}
}
static int F_14 ( struct V_1 * V_6 , unsigned int V_12 )
{
struct V_28 * V_29 = V_6 -> V_30 -> V_31 ;
const struct V_10 * V_32 ;
unsigned int V_33 = 0 ;
unsigned long V_25 ;
switch ( V_6 -> V_34 ) {
case V_35 :
V_25 = V_36 ;
break;
case V_37 :
V_25 = V_38 ;
break;
default:
V_25 = V_39 ;
break;
}
if ( F_15 ( V_29 , L_1 ) ) {
V_25 |= F_16 ( 6 ) |
F_17 ( 0xc0 ) ;
F_6 ( V_6 , V_25 , V_40 ) ;
} else {
V_25 |= V_41 ;
F_6 ( V_6 , V_25 , V_42 ) ;
V_25 = F_16 ( 6 ) |
F_17 ( 0xc0 ) ;
F_6 ( V_6 , V_25 , V_40 ) ;
}
V_32 = F_8 ( V_6 -> V_11 , V_12 ) ;
if ( ! V_32 ) {
F_18 ( V_6 -> V_30 , L_2 ,
V_6 -> V_11 , V_12 ) ;
return - V_43 ;
}
F_6 ( V_6 , 0 , V_44 ) ;
V_25 = V_45 | V_46 |
F_19 ( V_32 -> V_47 - 1 ) ;
F_6 ( V_6 , V_25 , V_48 ) ;
F_6 ( V_6 , F_20 ( V_32 -> V_47 ) | V_49 ,
V_50 ) ;
V_25 = F_21 ( V_32 -> V_51 ) ;
F_6 ( V_6 , V_25 , V_52 ) ;
V_25 = V_53 | V_54 | F_22 ( 1 ) ;
F_6 ( V_6 , V_25 , V_55 ) ;
V_25 = F_4 ( V_6 , V_48 ) ;
V_25 &= ~ V_45 ;
F_6 ( V_6 , V_25 , V_48 ) ;
if ( F_15 ( V_29 , L_1 ) ) {
switch ( V_6 -> V_11 ) {
case 32000 :
V_33 = V_56 ;
break;
case 44100 :
V_33 = V_57 ;
break;
case 48000 :
V_33 = V_58 ;
break;
case 88200 :
V_33 = V_59 ;
break;
case 96000 :
V_33 = V_60 ;
break;
case 176400 :
V_33 = V_61 ;
break;
case 192000 :
V_33 = V_62 ;
break;
}
F_6 ( V_6 , V_32 -> V_63 , V_33 ) ;
}
F_9 ( V_6 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_6 ,
unsigned int V_33 , T_1 type ,
T_1 V_64 , void * V_65 , T_2 V_66 )
{
unsigned long V_25 ;
T_1 * V_67 = V_65 ;
T_3 V_68 [ 2 ] ;
T_2 V_22 ;
T_1 V_69 ;
V_69 = type + V_64 + V_66 - 1 ;
for ( V_22 = 1 ; V_22 < V_66 ; V_22 ++ )
V_69 += V_67 [ V_22 ] ;
V_67 [ 0 ] = 0x100 - V_69 ;
V_25 = F_24 ( type ) |
F_25 ( V_64 ) |
F_26 ( V_66 - 1 ) ;
F_6 ( V_6 , V_25 , V_33 ) ;
if ( V_33 == V_70 )
V_66 = 6 ;
for ( V_22 = 0 ; V_22 < V_66 ; V_22 ++ ) {
T_2 V_71 = V_22 % 7 ;
if ( V_71 == 0 )
memset ( V_68 , 0x0 , sizeof( V_68 ) ) ;
( ( T_1 * ) V_68 ) [ V_71 ] = V_67 [ V_22 ] ;
if ( V_71 == 6 || ( V_22 + 1 == V_66 ) ) {
unsigned int V_7 = V_33 + 1 + ( V_22 / 7 ) * 2 ;
F_6 ( V_6 , V_68 [ 0 ] , V_7 ) ;
F_6 ( V_6 , V_68 [ 1 ] , V_7 + 1 ) ;
}
}
}
static void F_27 ( struct V_1 * V_6 ,
struct V_72 * V_73 )
{
struct V_74 V_75 ;
unsigned int V_76 ;
unsigned int V_77 = 16 ;
unsigned int V_78 = 9 ;
if ( V_6 -> V_79 ) {
F_6 ( V_6 , 0 ,
V_80 ) ;
return;
}
V_76 = V_73 -> V_81 - V_73 -> V_82 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_83 = V_84 ;
switch ( V_73 -> V_85 ) {
case 480 :
if ( V_73 -> V_82 == 640 ) {
V_75 . V_86 = V_87 ;
V_75 . V_88 = 1 ;
} else {
V_75 . V_86 = V_89 ;
V_75 . V_88 = 3 ;
}
break;
case 576 :
if ( ( ( V_77 * 10 ) / V_78 ) > 14 ) {
V_75 . V_86 = V_89 ;
V_75 . V_88 = 18 ;
} else {
V_75 . V_86 = V_87 ;
V_75 . V_88 = 17 ;
}
break;
case 720 :
case 1470 :
V_75 . V_86 = V_89 ;
if ( V_76 == 110 )
V_75 . V_88 = 4 ;
else
V_75 . V_88 = 19 ;
break;
case 1080 :
case 2205 :
V_75 . V_86 = V_89 ;
switch ( V_76 ) {
case 88 :
V_75 . V_88 = 16 ;
break;
case 528 :
V_75 . V_88 = 31 ;
break;
default:
V_75 . V_88 = 32 ;
break;
}
break;
default:
V_75 . V_86 = V_89 ;
V_75 . V_88 = 0 ;
break;
}
F_23 ( V_6 , V_90 ,
V_91 , V_92 ,
& V_75 , sizeof( V_75 ) ) ;
F_6 ( V_6 , V_93 ,
V_80 ) ;
}
static void F_28 ( struct V_1 * V_6 )
{
struct V_94 V_75 ;
if ( V_6 -> V_79 ) {
F_6 ( V_6 , 0 ,
V_95 ) ;
return;
}
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_96 = V_97 ;
F_23 ( V_6 ,
V_70 ,
V_98 ,
V_99 ,
& V_75 , sizeof( V_75 ) ) ;
F_6 ( V_6 , V_93 ,
V_95 ) ;
}
static void F_29 ( struct V_1 * V_6 )
{
struct V_100 V_75 ;
unsigned long V_25 ;
if ( ! V_6 -> V_101 ) {
V_25 = F_4 ( V_6 , V_102 ) ;
V_25 &= ~ V_103 ;
F_6 ( V_6 , V_25 , V_102 ) ;
return;
}
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_104 = 0x03 ;
V_75 . V_105 = 0x0c ;
V_75 . V_106 = 0x00 ;
V_75 . V_107 = 2 ;
if ( 1 ) {
V_75 . V_108 = 0 ;
} else {
V_75 . V_108 = 8 ;
V_75 . V_109 = 0 ;
}
F_23 ( V_6 , V_110 ,
V_111 ,
V_112 , & V_75 , 6 ) ;
V_25 = F_4 ( V_6 , V_102 ) ;
V_25 |= V_103 ;
F_6 ( V_6 , V_25 , V_102 ) ;
}
static void F_30 ( struct V_1 * V_6 ,
const struct V_113 * V_114 )
{
unsigned long V_25 ;
F_6 ( V_6 , V_114 -> V_115 , V_116 ) ;
F_6 ( V_6 , V_114 -> V_117 , V_118 ) ;
F_6 ( V_6 , V_114 -> V_119 , V_120 ) ;
V_25 = V_114 -> V_121 | V_122 ;
F_6 ( V_6 , V_25 , V_123 ) ;
}
static int F_31 ( struct V_4 * V_5 )
{
unsigned int V_124 , V_76 , V_125 , V_22 , V_126 ;
struct V_127 * V_128 = F_32 ( V_5 -> V_129 . V_130 ) ;
struct V_72 * V_73 = & V_128 -> V_131 . V_73 ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_28 * V_29 = V_6 -> V_30 -> V_31 ;
unsigned int V_132 , V_133 , V_12 ;
const struct V_113 * V_114 ;
unsigned int V_134 ;
unsigned long V_25 ;
int V_135 = 1000 ;
int V_136 ;
V_12 = V_73 -> clock * 1000 ;
V_124 = V_73 -> V_137 - V_73 -> V_81 ;
V_125 = V_73 -> V_138 - V_73 -> V_137 ;
V_76 = V_73 -> V_81 - V_73 -> V_82 ;
V_136 = F_33 ( V_6 -> V_139 ) ;
if ( V_136 < 0 ) {
F_18 ( V_6 -> V_30 , L_3 , V_136 ) ;
return V_136 ;
}
V_136 = F_33 ( V_6 -> V_140 ) ;
if ( V_136 < 0 ) {
F_18 ( V_6 -> V_30 , L_4 , V_136 ) ;
return V_136 ;
}
V_136 = F_34 ( V_5 , V_6 -> V_141 , V_12 * 2 ) ;
if ( V_136 < 0 ) {
F_18 ( V_6 -> V_30 , L_5 , V_136 ) ;
return V_136 ;
}
V_136 = F_35 ( V_6 -> V_141 , V_12 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_36 ( V_6 -> V_141 ) ;
if ( V_136 < 0 ) {
F_18 ( V_6 -> V_30 , L_6 , V_136 ) ;
return V_136 ;
}
F_37 ( V_6 -> V_141 ) ;
F_38 ( 1000 , 2000 ) ;
F_39 ( V_6 -> V_141 ) ;
F_40 ( V_128 , F_41 ( 1 ) ,
V_142 ) ;
F_40 ( V_128 , V_143 | V_144 ,
V_145 ) ;
V_132 = 1 + V_124 + V_125 - 10 ;
F_40 ( V_128 , V_146 , V_147 ) ;
V_25 = V_148 | V_149 | V_150 |
V_151 ;
F_40 ( V_128 , V_25 , V_152 ) ;
V_25 = F_42 ( V_132 ) | F_43 ( V_132 + 8 ) ;
F_40 ( V_128 , V_25 , V_153 ) ;
V_25 = F_44 ( 0x210 ) | F_45 ( 0x200 ) |
V_154 ;
F_6 ( V_6 , V_25 , V_155 ) ;
if ( V_128 -> V_156 )
V_25 = V_157 ;
else
V_25 = V_158 ;
if ( ( V_73 -> V_82 == 720 ) && ( ( V_73 -> V_85 == 480 ) ||
( V_73 -> V_85 == 576 ) ) )
F_6 ( V_6 ,
V_25 | V_159 ,
V_160 ) ;
else
F_6 ( V_6 ,
V_25 | V_161 ,
V_160 ) ;
V_133 = F_46 ( V_6 -> V_141 ) / 1000000 * 4 ;
V_25 = F_47 ( V_133 >> 2 ) | F_48 ( V_133 ) ;
F_6 ( V_6 , V_25 , V_162 ) ;
if ( ! V_6 -> V_79 ) {
V_136 = F_14 ( V_6 , V_12 ) ;
if ( V_136 < 0 )
V_6 -> V_79 = true ;
}
if ( F_15 ( V_29 , L_7 ) ) {
}
V_126 = V_163 ;
V_25 = F_49 ( V_126 ) ;
V_25 |= F_50 ( ( V_124 + V_125 +
V_76 - V_126 - 18 ) / 32 ) ;
if ( ! V_6 -> V_79 )
V_25 |= V_164 ;
F_6 ( V_6 , V_25 , V_165 ) ;
if ( V_6 -> V_79 )
F_6 ( V_6 , 0x0 ,
V_102 ) ;
else
F_6 ( V_6 , V_166 ,
V_102 ) ;
F_27 ( V_6 , V_73 ) ;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
if ( F_15 ( V_29 , L_1 ) ) {
V_134 = F_10 ( V_167 ) ;
V_114 = V_167 ;
} else {
V_134 = F_10 ( V_168 ) ;
V_114 = V_168 ;
}
for ( V_22 = 0 ; V_22 < V_134 ; V_22 ++ ) {
if ( V_12 <= V_114 [ V_22 ] . V_12 ) {
F_30 ( V_6 , & V_114 [ V_22 ] ) ;
break;
}
}
F_6 ( V_6 ,
F_51 ( 0 ) |
F_52 ( 0 ) |
F_53 ( 8 ) |
F_54 ( 8 ) ,
V_169 ) ;
V_25 = F_55 ( 1 ) |
V_170 |
V_171 |
V_172 |
V_173 |
V_174 ;
F_6 ( V_6 , V_25 , F_56 ( 0 ) ) ;
F_6 ( V_6 , V_25 , F_56 ( 8 ) ) ;
V_25 = 0x1c800 ;
V_25 &= ~ F_57 ( ~ 0 ) ;
V_25 |= F_57 ( 2 ) ;
F_6 ( V_6 , V_25 , V_175 ) ;
F_40 ( V_128 , V_176 , V_177 ) ;
F_40 ( V_128 , V_178 << 8 , V_179 ) ;
F_40 ( V_128 , V_178 , V_179 ) ;
F_6 ( V_6 ,
V_180 |
V_181 |
V_182 |
V_183 ,
V_184 ) ;
F_6 ( V_6 ,
V_180 |
V_181 |
V_182 |
V_185 ,
V_184 ) ;
do {
F_58 ( -- V_135 < 0 ) ;
V_25 = F_4 ( V_6 , V_184 ) ;
} while ( V_25 & V_186 );
V_25 = V_187 |
V_188 |
V_189 |
V_190 |
V_191 ;
if ( V_73 -> V_192 & V_193 )
V_25 |= V_194 ;
if ( V_73 -> V_192 & V_195 )
V_25 |= V_196 ;
if ( V_73 -> V_192 & V_197 )
V_25 |= V_198 ;
if ( V_73 -> V_192 & V_199 )
V_25 |= V_200 ;
F_6 ( V_6 , V_25 , V_201 ) ;
V_25 = V_202 | V_203 ;
F_6 ( V_6 , V_25 , V_204 ) ;
F_6 ( V_6 , 0 , V_205 ) ;
F_6 ( V_6 , V_206 , V_205 ) ;
F_6 ( V_6 , V_25 | V_207 ,
V_204 ) ;
F_6 ( V_6 , 0 , V_205 ) ;
F_40 ( V_128 , V_208 , V_209 ) ;
V_25 = V_210 | V_211 | V_212 | V_213 |
V_214 | V_215 | V_216 ;
F_40 ( V_128 , V_25 , V_217 ) ;
V_25 = V_218 ;
F_40 ( V_128 , V_25 , V_177 ) ;
F_40 ( V_128 , V_178 << 8 , V_179 ) ;
F_40 ( V_128 , V_178 , V_179 ) ;
return 0 ;
}
static int F_59 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_37 ( V_6 -> V_141 ) ;
F_60 ( V_6 -> V_141 ) ;
F_61 ( V_6 -> V_140 ) ;
F_61 ( V_6 -> V_139 ) ;
return 0 ;
}
static int F_62 ( struct V_4 * V_5 ,
struct V_141 * V_141 , unsigned long V_12 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_141 * V_131 ;
int V_136 ;
V_136 = F_63 ( V_141 , V_6 -> V_219 ) ;
if ( V_136 < 0 ) {
F_18 ( V_5 -> V_30 , L_8 , V_136 ) ;
return V_136 ;
}
V_131 = F_64 ( V_6 -> V_219 ) ;
V_136 = F_35 ( V_131 , V_12 * 2 ) ;
if ( V_136 < 0 )
F_18 ( V_5 -> V_30 ,
L_9 ,
V_12 * 2 ) ;
return 0 ;
}
static int F_65 ( struct V_4 * V_5 ,
struct V_72 * V_73 ,
enum V_220 * V_221 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_12 = V_73 -> clock * 1000 ;
struct V_141 * V_222 ;
long V_136 ;
V_222 = F_64 ( V_6 -> V_219 ) ;
V_136 = F_66 ( V_222 , V_12 * 4 ) ;
if ( V_136 < 0 )
* V_221 = V_223 ;
else
* V_221 = V_224 ;
return 0 ;
}
static int F_67 ( struct V_225 * V_226 , void * V_65 )
{
struct V_227 * V_29 = V_226 -> V_228 ;
struct V_1 * V_6 = V_29 -> V_229 -> V_65 ;
#define F_68 ( T_4 ) \
seq_printf(s, "%-56s %#05x %08lx\n", #name, name, \
tegra_hdmi_readl(hdmi, name))
F_68 ( V_230 ) ;
F_68 ( V_205 ) ;
F_68 ( V_204 ) ;
F_68 ( V_201 ) ;
F_68 ( V_231 ) ;
F_68 ( V_232 ) ;
F_68 ( V_233 ) ;
F_68 ( V_234 ) ;
F_68 ( V_235 ) ;
F_68 ( V_236 ) ;
F_68 ( V_237 ) ;
F_68 ( V_238 ) ;
F_68 ( V_239 ) ;
F_68 ( V_240 ) ;
F_68 ( V_241 ) ;
F_68 ( V_242 ) ;
F_68 ( V_243 ) ;
F_68 ( V_244 ) ;
F_68 ( V_245 ) ;
F_68 ( V_246 ) ;
F_68 ( V_247 ) ;
F_68 ( V_248 ) ;
F_68 ( V_249 ) ;
F_68 ( V_250 ) ;
F_68 ( V_251 ) ;
F_68 ( V_252 ) ;
F_68 ( V_253 ) ;
F_68 ( V_254 ) ;
F_68 ( V_255 ) ;
F_68 ( V_256 ) ;
F_68 ( V_95 ) ;
F_68 ( V_257 ) ;
F_68 ( V_70 ) ;
F_68 ( V_258 ) ;
F_68 ( V_259 ) ;
F_68 ( V_80 ) ;
F_68 ( V_260 ) ;
F_68 ( V_90 ) ;
F_68 ( V_261 ) ;
F_68 ( V_262 ) ;
F_68 ( V_263 ) ;
F_68 ( V_264 ) ;
F_68 ( V_102 ) ;
F_68 ( V_265 ) ;
F_68 ( V_110 ) ;
F_68 ( V_266 ) ;
F_68 ( V_267 ) ;
F_68 ( V_268 ) ;
F_68 ( V_269 ) ;
F_68 ( V_270 ) ;
F_68 ( V_271 ) ;
F_68 ( V_272 ) ;
F_68 ( V_273 ) ;
F_68 ( V_44 ) ;
F_68 ( V_274 ) ;
F_68 ( V_275 ) ;
F_68 ( V_52 ) ;
F_68 ( V_50 ) ;
F_68 ( V_276 ) ;
F_68 ( V_277 ) ;
F_68 ( V_278 ) ;
F_68 ( V_279 ) ;
F_68 ( V_280 ) ;
F_68 ( V_281 ) ;
F_68 ( V_282 ) ;
F_68 ( V_283 ) ;
F_68 ( V_284 ) ;
F_68 ( V_285 ) ;
F_68 ( V_165 ) ;
F_68 ( V_286 ) ;
F_68 ( V_155 ) ;
F_68 ( V_287 ) ;
F_68 ( V_288 ) ;
F_68 ( V_289 ) ;
F_68 ( V_290 ) ;
F_68 ( V_291 ) ;
F_68 ( V_292 ) ;
F_68 ( V_293 ) ;
F_68 ( V_294 ) ;
F_68 ( V_55 ) ;
F_68 ( V_295 ) ;
F_68 ( V_296 ) ;
F_68 ( V_297 ) ;
F_68 ( V_298 ) ;
F_68 ( V_184 ) ;
F_68 ( V_299 ) ;
F_68 ( V_116 ) ;
F_68 ( V_118 ) ;
F_68 ( V_300 ) ;
F_68 ( V_175 ) ;
F_68 ( V_301 ) ;
F_68 ( V_302 ) ;
F_68 ( V_303 ) ;
F_68 ( V_304 ) ;
F_68 ( V_169 ) ;
F_68 ( F_56 ( 0 ) ) ;
F_68 ( F_56 ( 1 ) ) ;
F_68 ( F_56 ( 2 ) ) ;
F_68 ( F_56 ( 3 ) ) ;
F_68 ( F_56 ( 4 ) ) ;
F_68 ( F_56 ( 5 ) ) ;
F_68 ( F_56 ( 6 ) ) ;
F_68 ( F_56 ( 7 ) ) ;
F_68 ( F_56 ( 8 ) ) ;
F_68 ( F_56 ( 9 ) ) ;
F_68 ( F_56 ( 10 ) ) ;
F_68 ( F_56 ( 11 ) ) ;
F_68 ( F_56 ( 12 ) ) ;
F_68 ( F_56 ( 13 ) ) ;
F_68 ( F_56 ( 14 ) ) ;
F_68 ( F_56 ( 15 ) ) ;
F_68 ( V_305 ) ;
F_68 ( V_306 ) ;
F_68 ( V_307 ) ;
F_68 ( V_308 ) ;
F_68 ( V_309 ) ;
F_68 ( V_310 ) ;
F_68 ( V_311 ) ;
F_68 ( V_312 ) ;
F_68 ( V_313 ) ;
F_68 ( V_314 ) ;
F_68 ( V_315 ) ;
F_68 ( V_316 ) ;
F_68 ( V_123 ) ;
F_68 ( V_317 ) ;
F_68 ( V_318 ) ;
F_68 ( V_319 ) ;
F_68 ( F_13 ( 0 ) ) ;
F_68 ( F_13 ( 1 ) ) ;
F_68 ( F_13 ( 2 ) ) ;
F_68 ( F_13 ( 3 ) ) ;
F_68 ( F_13 ( 4 ) ) ;
F_68 ( F_13 ( 5 ) ) ;
F_68 ( F_13 ( 6 ) ) ;
F_68 ( V_320 ) ;
F_68 ( V_321 ) ;
F_68 ( V_40 ) ;
F_68 ( V_48 ) ;
F_68 ( V_322 ) ;
F_68 ( V_162 ) ;
F_68 ( V_323 ) ;
F_68 ( V_160 ) ;
F_68 ( V_324 ) ;
F_68 ( V_120 ) ;
F_68 ( V_325 ) ;
F_68 ( V_326 ) ;
F_68 ( V_327 ) ;
F_68 ( V_328 ) ;
F_68 ( V_329 ) ;
F_68 ( V_330 ) ;
F_68 ( V_331 ) ;
F_68 ( V_332 ) ;
F_68 ( V_333 ) ;
F_68 ( V_334 ) ;
F_68 ( V_42 ) ;
F_68 ( V_335 ) ;
F_68 ( V_336 ) ;
#undef F_68
return 0 ;
}
static int F_69 ( struct V_1 * V_6 ,
struct V_337 * V_338 )
{
unsigned int V_22 ;
int V_136 ;
V_6 -> V_339 = F_70 ( L_10 , V_338 -> V_340 ) ;
if ( ! V_6 -> V_339 )
return - V_341 ;
V_6 -> V_342 = F_71 ( V_342 , sizeof( V_342 ) ,
V_343 ) ;
if ( ! V_6 -> V_342 ) {
V_136 = - V_341 ;
goto remove;
}
for ( V_22 = 0 ; V_22 < F_10 ( V_342 ) ; V_22 ++ )
V_6 -> V_342 [ V_22 ] . V_65 = V_6 ;
V_136 = F_72 ( V_6 -> V_342 ,
F_10 ( V_342 ) ,
V_6 -> V_339 , V_338 ) ;
if ( V_136 < 0 )
goto free;
V_6 -> V_338 = V_338 ;
return 0 ;
free:
F_73 ( V_6 -> V_342 ) ;
V_6 -> V_342 = NULL ;
remove:
F_74 ( V_6 -> V_339 ) ;
V_6 -> V_339 = NULL ;
return V_136 ;
}
static int F_75 ( struct V_1 * V_6 )
{
F_76 ( V_6 -> V_342 , F_10 ( V_342 ) ,
V_6 -> V_338 ) ;
V_6 -> V_338 = NULL ;
F_73 ( V_6 -> V_342 ) ;
V_6 -> V_342 = NULL ;
F_74 ( V_6 -> V_339 ) ;
V_6 -> V_339 = NULL ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_344 * V_345 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_136 ;
V_6 -> V_5 . type = V_346 ;
V_6 -> V_5 . V_30 = V_3 -> V_30 ;
V_6 -> V_5 . V_347 = & V_348 ;
V_136 = F_78 ( V_345 , & V_6 -> V_5 ) ;
if ( V_136 < 0 ) {
F_18 ( V_3 -> V_30 , L_11 , V_136 ) ;
return V_136 ;
}
if ( F_79 ( V_349 ) ) {
V_136 = F_69 ( V_6 , V_345 -> V_350 ) ;
if ( V_136 < 0 )
F_18 ( V_3 -> V_30 , L_12 , V_136 ) ;
}
return 0 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_136 ;
if ( F_79 ( V_349 ) ) {
V_136 = F_75 ( V_6 ) ;
if ( V_136 < 0 )
F_18 ( V_3 -> V_30 , L_13 ,
V_136 ) ;
}
V_136 = F_81 ( & V_6 -> V_5 ) ;
if ( V_136 < 0 ) {
F_18 ( V_3 -> V_30 , L_14 , V_136 ) ;
return V_136 ;
}
V_136 = F_82 ( & V_6 -> V_5 ) ;
if ( V_136 < 0 ) {
F_18 ( V_3 -> V_30 , L_15 , V_136 ) ;
return V_136 ;
}
return 0 ;
}
static int F_83 ( struct V_351 * V_352 )
{
struct V_353 * V_353 = F_84 ( V_352 -> V_30 . V_222 ) ;
struct V_1 * V_6 ;
struct V_354 * V_8 ;
int V_136 ;
V_6 = F_85 ( & V_352 -> V_30 , sizeof( * V_6 ) , V_343 ) ;
if ( ! V_6 )
return - V_341 ;
V_6 -> V_30 = & V_352 -> V_30 ;
V_6 -> V_34 = AUTO ;
V_6 -> V_11 = 44100 ;
V_6 -> V_101 = false ;
V_6 -> V_79 = false ;
V_6 -> V_141 = F_86 ( & V_352 -> V_30 , NULL ) ;
if ( F_87 ( V_6 -> V_141 ) ) {
F_18 ( & V_352 -> V_30 , L_16 ) ;
return F_88 ( V_6 -> V_141 ) ;
}
V_136 = F_89 ( V_6 -> V_141 ) ;
if ( V_136 < 0 )
return V_136 ;
V_6 -> V_219 = F_86 ( & V_352 -> V_30 , L_17 ) ;
if ( F_87 ( V_6 -> V_219 ) )
return F_88 ( V_6 -> V_219 ) ;
V_136 = F_89 ( V_6 -> V_219 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_63 ( V_6 -> V_141 , V_6 -> V_219 ) ;
if ( V_136 < 0 ) {
F_18 ( & V_352 -> V_30 , L_18 , V_136 ) ;
return V_136 ;
}
V_6 -> V_139 = F_90 ( & V_352 -> V_30 , L_19 ) ;
if ( F_87 ( V_6 -> V_139 ) ) {
F_18 ( & V_352 -> V_30 , L_20 ) ;
return F_88 ( V_6 -> V_139 ) ;
}
V_6 -> V_140 = F_90 ( & V_352 -> V_30 , L_21 ) ;
if ( F_87 ( V_6 -> V_140 ) ) {
F_18 ( & V_352 -> V_30 , L_22 ) ;
return F_88 ( V_6 -> V_140 ) ;
}
V_6 -> V_5 . V_30 = & V_352 -> V_30 ;
V_136 = F_91 ( & V_6 -> V_5 ) ;
if ( V_136 < 0 )
return V_136 ;
V_8 = F_92 ( V_352 , V_355 , 0 ) ;
if ( ! V_8 )
return - V_356 ;
V_6 -> V_8 = F_93 ( & V_352 -> V_30 , V_8 ) ;
if ( ! V_6 -> V_8 )
return - V_357 ;
V_136 = F_94 ( V_352 , 0 ) ;
if ( V_136 < 0 )
return V_136 ;
V_6 -> V_358 = V_136 ;
V_6 -> V_3 . V_347 = & V_359 ;
F_95 ( & V_6 -> V_3 . V_360 ) ;
V_6 -> V_3 . V_30 = & V_352 -> V_30 ;
V_136 = F_96 ( V_353 , & V_6 -> V_3 ) ;
if ( V_136 < 0 ) {
F_18 ( & V_352 -> V_30 , L_23 ,
V_136 ) ;
return V_136 ;
}
F_97 ( V_352 , V_6 ) ;
return 0 ;
}
static int F_98 ( struct V_351 * V_352 )
{
struct V_353 * V_353 = F_84 ( V_352 -> V_30 . V_222 ) ;
struct V_1 * V_6 = F_99 ( V_352 ) ;
int V_136 ;
V_136 = F_100 ( V_353 , & V_6 -> V_3 ) ;
if ( V_136 < 0 ) {
F_18 ( & V_352 -> V_30 , L_24 ,
V_136 ) ;
return V_136 ;
}
F_101 ( V_6 -> V_219 ) ;
F_101 ( V_6 -> V_141 ) ;
return 0 ;
}
