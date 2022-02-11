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
static inline unsigned long F_23 ( const T_1 * V_64 , T_2 V_65 )
{
unsigned long V_25 = 0 ;
T_2 V_22 ;
for ( V_22 = V_65 ; V_22 > 0 ; V_22 -- )
V_25 = ( V_25 << 8 ) | V_64 [ V_22 - 1 ] ;
return V_25 ;
}
static void F_24 ( struct V_1 * V_6 , const void * V_66 ,
T_2 V_65 )
{
const T_1 * V_64 = V_66 ;
unsigned long V_33 ;
unsigned long V_25 ;
T_2 V_22 , V_67 ;
switch ( V_64 [ 0 ] ) {
case V_68 :
V_33 = V_69 ;
break;
case V_70 :
V_33 = V_71 ;
break;
case V_72 :
V_33 = V_73 ;
break;
default:
F_18 ( V_6 -> V_30 , L_3 ,
V_64 [ 0 ] ) ;
return;
}
V_25 = F_25 ( V_64 [ 0 ] ) |
F_26 ( V_64 [ 1 ] ) |
F_27 ( V_64 [ 2 ] ) ;
F_6 ( V_6 , V_25 , V_33 ) ;
V_33 ++ ;
for ( V_22 = 3 , V_67 = 0 ; V_22 < V_65 ; V_22 += 7 , V_67 += 8 ) {
T_2 V_74 = V_65 - V_22 , V_75 = F_28 ( T_2 , V_74 , 4 ) ;
V_25 = F_23 ( & V_64 [ V_22 ] , V_75 ) ;
F_6 ( V_6 , V_25 , V_33 ++ ) ;
V_75 = F_28 ( T_2 , V_74 - V_75 , 3 ) ;
V_25 = F_23 ( & V_64 [ V_22 + 4 ] , V_75 ) ;
F_6 ( V_6 , V_25 , V_33 ++ ) ;
}
}
static void F_29 ( struct V_1 * V_6 ,
struct V_76 * V_77 )
{
struct V_78 V_79 ;
T_1 V_80 [ 17 ] ;
T_3 V_81 ;
if ( V_6 -> V_82 ) {
F_6 ( V_6 , 0 ,
V_83 ) ;
return;
}
V_81 = F_30 ( & V_79 , V_77 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_4 , V_81 ) ;
return;
}
V_81 = F_31 ( & V_79 , V_80 , sizeof( V_80 ) ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_5 , V_81 ) ;
return;
}
F_24 ( V_6 , V_80 , V_81 ) ;
F_6 ( V_6 , V_84 ,
V_83 ) ;
}
static void F_32 ( struct V_1 * V_6 )
{
struct V_85 V_79 ;
T_1 V_80 [ 14 ] ;
T_3 V_81 ;
if ( V_6 -> V_82 ) {
F_6 ( V_6 , 0 ,
V_86 ) ;
return;
}
V_81 = F_33 ( & V_79 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_6 ,
V_81 ) ;
return;
}
V_79 . V_87 = 2 ;
V_81 = F_34 ( & V_79 , V_80 , sizeof( V_80 ) ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_7 ,
V_81 ) ;
return;
}
F_24 ( V_6 , V_80 , F_28 ( T_2 , 10 , V_81 ) ) ;
F_6 ( V_6 , V_84 ,
V_86 ) ;
}
static void F_35 ( struct V_1 * V_6 )
{
struct V_88 V_79 ;
unsigned long V_25 ;
T_1 V_80 [ 10 ] ;
T_3 V_81 ;
if ( ! V_6 -> V_89 ) {
V_25 = F_4 ( V_6 , V_90 ) ;
V_25 &= ~ V_91 ;
F_6 ( V_6 , V_25 , V_90 ) ;
return;
}
F_36 ( & V_79 ) ;
V_79 . V_92 = V_93 ;
V_81 = F_37 ( & V_79 , V_80 , sizeof( V_80 ) ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_8 ,
V_81 ) ;
return;
}
F_24 ( V_6 , V_80 , V_81 ) ;
V_25 = F_4 ( V_6 , V_90 ) ;
V_25 |= V_91 ;
F_6 ( V_6 , V_25 , V_90 ) ;
}
static void F_38 ( struct V_1 * V_6 ,
const struct V_94 * V_95 )
{
unsigned long V_25 ;
F_6 ( V_6 , V_95 -> V_96 , V_97 ) ;
F_6 ( V_6 , V_95 -> V_98 , V_99 ) ;
F_6 ( V_6 , V_95 -> V_100 , V_101 ) ;
F_6 ( V_6 , V_95 -> V_102 ,
V_103 ) ;
V_25 = F_4 ( V_6 , V_6 -> V_32 -> V_104 ) ;
V_25 |= V_6 -> V_32 -> V_105 ;
F_6 ( V_6 , V_25 , V_6 -> V_32 -> V_104 ) ;
if ( V_6 -> V_32 -> V_106 )
F_6 ( V_6 , V_95 -> V_107 ,
V_108 ) ;
}
static bool F_39 ( struct V_4 * V_5 )
{
struct V_109 * V_109 ;
if ( ! V_5 -> V_110 . V_111 )
return false ;
V_109 = (struct V_109 * ) V_5 -> V_110 . V_111 -> V_66 ;
return F_40 ( V_109 ) ;
}
static int F_41 ( struct V_4 * V_5 )
{
unsigned int V_112 , V_113 , V_114 , V_22 , V_115 ;
struct V_116 * V_117 = F_42 ( V_5 -> V_118 . V_119 ) ;
struct V_76 * V_77 = & V_117 -> V_120 . V_77 ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_28 * V_29 = V_6 -> V_30 -> V_31 ;
unsigned int V_121 , V_122 , V_12 ;
unsigned long V_25 ;
int V_123 = 1000 ;
int V_81 ;
V_6 -> V_82 = ! F_39 ( V_5 ) ;
V_12 = V_77 -> clock * 1000 ;
V_112 = V_77 -> V_124 - V_77 -> V_125 ;
V_114 = V_77 -> V_126 - V_77 -> V_124 ;
V_113 = V_77 -> V_125 - V_77 -> V_127 ;
V_81 = F_43 ( V_6 -> V_128 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_9 , V_81 ) ;
return V_81 ;
}
V_81 = F_44 ( V_5 , V_6 -> V_129 , V_12 * 2 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_10 , V_81 ) ;
return V_81 ;
}
V_81 = F_45 ( V_6 -> V_129 , V_12 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_46 ( V_6 -> V_129 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_11 , V_81 ) ;
return V_81 ;
}
F_47 ( V_6 -> V_129 ) ;
F_48 ( 1000 , 2000 ) ;
F_49 ( V_6 -> V_129 ) ;
F_50 ( V_117 , F_51 ( 1 ) ,
V_130 ) ;
F_50 ( V_117 , V_131 | V_132 ,
V_133 ) ;
V_121 = 1 + V_112 + V_114 - 10 ;
F_50 ( V_117 , V_134 , V_135 ) ;
V_25 = V_136 | V_137 | V_138 |
V_139 ;
F_50 ( V_117 , V_25 , V_140 ) ;
V_25 = F_52 ( V_121 ) | F_53 ( V_121 + 8 ) ;
F_50 ( V_117 , V_25 , V_141 ) ;
V_25 = F_54 ( 0x210 ) | F_55 ( 0x200 ) |
V_142 ;
F_6 ( V_6 , V_25 , V_143 ) ;
if ( V_117 -> V_144 )
V_25 = V_145 ;
else
V_25 = V_146 ;
if ( ( V_77 -> V_127 == 720 ) && ( ( V_77 -> V_147 == 480 ) ||
( V_77 -> V_147 == 576 ) ) )
F_6 ( V_6 ,
V_25 | V_148 ,
V_149 ) ;
else
F_6 ( V_6 ,
V_25 | V_150 ,
V_149 ) ;
V_122 = F_56 ( V_6 -> V_129 ) / 1000000 * 4 ;
V_25 = F_57 ( V_122 >> 2 ) | F_58 ( V_122 ) ;
F_6 ( V_6 , V_25 , V_151 ) ;
if ( ! V_6 -> V_82 ) {
V_81 = F_14 ( V_6 , V_12 ) ;
if ( V_81 < 0 )
V_6 -> V_82 = true ;
}
if ( F_15 ( V_29 , L_12 ) ) {
}
V_115 = V_152 ;
V_25 = F_59 ( V_115 ) ;
V_25 |= F_60 ( ( V_112 + V_114 +
V_113 - V_115 - 18 ) / 32 ) ;
if ( ! V_6 -> V_82 )
V_25 |= V_153 ;
F_6 ( V_6 , V_25 , V_154 ) ;
if ( V_6 -> V_82 )
F_6 ( V_6 , 0x0 ,
V_90 ) ;
else
F_6 ( V_6 , V_155 ,
V_90 ) ;
F_29 ( V_6 , V_77 ) ;
F_32 ( V_6 ) ;
F_35 ( V_6 ) ;
for ( V_22 = 0 ; V_22 < V_6 -> V_32 -> V_156 ; V_22 ++ ) {
if ( V_12 <= V_6 -> V_32 -> V_95 [ V_22 ] . V_12 ) {
F_38 ( V_6 , & V_6 -> V_32 -> V_95 [ V_22 ] ) ;
break;
}
}
F_6 ( V_6 ,
F_61 ( 0 ) |
F_62 ( 0 ) |
F_63 ( 8 ) |
F_64 ( 8 ) ,
V_157 ) ;
V_25 = F_65 ( 1 ) |
V_158 |
V_159 |
V_160 |
V_161 |
V_162 ;
F_6 ( V_6 , V_25 , F_66 ( 0 ) ) ;
F_6 ( V_6 , V_25 , F_66 ( 8 ) ) ;
V_25 = 0x1c800 ;
V_25 &= ~ F_67 ( ~ 0 ) ;
V_25 |= F_67 ( 2 ) ;
F_6 ( V_6 , V_25 , V_163 ) ;
F_50 ( V_117 , V_164 , V_165 ) ;
F_50 ( V_117 , V_166 << 8 , V_167 ) ;
F_50 ( V_117 , V_166 , V_167 ) ;
F_6 ( V_6 ,
V_168 |
V_169 |
V_170 |
V_171 ,
V_172 ) ;
F_6 ( V_6 ,
V_168 |
V_169 |
V_170 |
V_173 ,
V_172 ) ;
do {
F_68 ( -- V_123 < 0 ) ;
V_25 = F_4 ( V_6 , V_172 ) ;
} while ( V_25 & V_174 );
V_25 = V_175 |
V_176 |
V_177 |
V_178 |
V_179 ;
if ( V_77 -> V_180 & V_181 )
V_25 |= V_182 ;
if ( V_77 -> V_180 & V_183 )
V_25 |= V_184 ;
if ( V_77 -> V_180 & V_185 )
V_25 |= V_186 ;
if ( V_77 -> V_180 & V_187 )
V_25 |= V_188 ;
F_6 ( V_6 , V_25 , V_189 ) ;
V_25 = V_190 | V_191 ;
F_6 ( V_6 , V_25 , V_192 ) ;
F_6 ( V_6 , 0 , V_193 ) ;
F_6 ( V_6 , V_194 , V_193 ) ;
F_6 ( V_6 , V_25 | V_195 ,
V_192 ) ;
F_6 ( V_6 , 0 , V_193 ) ;
F_50 ( V_117 , V_196 , V_197 ) ;
V_25 = V_198 | V_199 | V_200 | V_201 |
V_202 | V_203 | V_204 ;
F_50 ( V_117 , V_25 , V_205 ) ;
V_25 = V_206 ;
F_50 ( V_117 , V_25 , V_165 ) ;
F_50 ( V_117 , V_166 << 8 , V_167 ) ;
F_50 ( V_117 , V_166 , V_167 ) ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_47 ( V_6 -> V_129 ) ;
F_70 ( V_6 -> V_129 ) ;
F_71 ( V_6 -> V_128 ) ;
return 0 ;
}
static int F_72 ( struct V_4 * V_5 ,
struct V_129 * V_129 , unsigned long V_12 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_129 * V_120 ;
int V_81 ;
V_81 = F_73 ( V_129 , V_6 -> V_207 ) ;
if ( V_81 < 0 ) {
F_18 ( V_5 -> V_30 , L_13 , V_81 ) ;
return V_81 ;
}
V_120 = F_74 ( V_6 -> V_207 ) ;
V_81 = F_45 ( V_120 , V_12 * 2 ) ;
if ( V_81 < 0 )
F_18 ( V_5 -> V_30 ,
L_14 ,
V_12 * 2 ) ;
return 0 ;
}
static int F_75 ( struct V_4 * V_5 ,
struct V_76 * V_77 ,
enum V_208 * V_209 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_12 = V_77 -> clock * 1000 ;
struct V_129 * V_210 ;
long V_81 ;
V_210 = F_74 ( V_6 -> V_207 ) ;
V_81 = F_76 ( V_210 , V_12 * 4 ) ;
if ( V_81 < 0 )
* V_209 = V_211 ;
else
* V_209 = V_212 ;
return 0 ;
}
static int F_77 ( struct V_213 * V_214 , void * V_66 )
{
struct V_215 * V_29 = V_214 -> V_216 ;
struct V_1 * V_6 = V_29 -> V_217 -> V_66 ;
int V_81 ;
V_81 = F_46 ( V_6 -> V_129 ) ;
if ( V_81 )
return V_81 ;
#define F_78 ( T_4 ) \
seq_printf(s, "%-56s %#05x %08lx\n", #name, name, \
tegra_hdmi_readl(hdmi, name))
F_78 ( V_218 ) ;
F_78 ( V_193 ) ;
F_78 ( V_192 ) ;
F_78 ( V_189 ) ;
F_78 ( V_219 ) ;
F_78 ( V_220 ) ;
F_78 ( V_221 ) ;
F_78 ( V_222 ) ;
F_78 ( V_223 ) ;
F_78 ( V_224 ) ;
F_78 ( V_225 ) ;
F_78 ( V_226 ) ;
F_78 ( V_227 ) ;
F_78 ( V_228 ) ;
F_78 ( V_229 ) ;
F_78 ( V_230 ) ;
F_78 ( V_231 ) ;
F_78 ( V_232 ) ;
F_78 ( V_233 ) ;
F_78 ( V_234 ) ;
F_78 ( V_235 ) ;
F_78 ( V_236 ) ;
F_78 ( V_237 ) ;
F_78 ( V_238 ) ;
F_78 ( V_239 ) ;
F_78 ( V_240 ) ;
F_78 ( V_241 ) ;
F_78 ( V_242 ) ;
F_78 ( V_243 ) ;
F_78 ( V_244 ) ;
F_78 ( V_86 ) ;
F_78 ( V_245 ) ;
F_78 ( V_71 ) ;
F_78 ( V_246 ) ;
F_78 ( V_247 ) ;
F_78 ( V_83 ) ;
F_78 ( V_248 ) ;
F_78 ( V_69 ) ;
F_78 ( V_249 ) ;
F_78 ( V_250 ) ;
F_78 ( V_251 ) ;
F_78 ( V_252 ) ;
F_78 ( V_90 ) ;
F_78 ( V_253 ) ;
F_78 ( V_73 ) ;
F_78 ( V_254 ) ;
F_78 ( V_255 ) ;
F_78 ( V_256 ) ;
F_78 ( V_257 ) ;
F_78 ( V_258 ) ;
F_78 ( V_259 ) ;
F_78 ( V_260 ) ;
F_78 ( V_261 ) ;
F_78 ( V_44 ) ;
F_78 ( V_262 ) ;
F_78 ( V_263 ) ;
F_78 ( V_52 ) ;
F_78 ( V_50 ) ;
F_78 ( V_264 ) ;
F_78 ( V_265 ) ;
F_78 ( V_266 ) ;
F_78 ( V_267 ) ;
F_78 ( V_268 ) ;
F_78 ( V_269 ) ;
F_78 ( V_270 ) ;
F_78 ( V_271 ) ;
F_78 ( V_272 ) ;
F_78 ( V_273 ) ;
F_78 ( V_154 ) ;
F_78 ( V_274 ) ;
F_78 ( V_143 ) ;
F_78 ( V_275 ) ;
F_78 ( V_276 ) ;
F_78 ( V_277 ) ;
F_78 ( V_278 ) ;
F_78 ( V_279 ) ;
F_78 ( V_280 ) ;
F_78 ( V_281 ) ;
F_78 ( V_282 ) ;
F_78 ( V_55 ) ;
F_78 ( V_283 ) ;
F_78 ( V_284 ) ;
F_78 ( V_285 ) ;
F_78 ( V_286 ) ;
F_78 ( V_172 ) ;
F_78 ( V_287 ) ;
F_78 ( V_97 ) ;
F_78 ( V_99 ) ;
F_78 ( V_288 ) ;
F_78 ( V_163 ) ;
F_78 ( V_289 ) ;
F_78 ( V_290 ) ;
F_78 ( V_291 ) ;
F_78 ( V_292 ) ;
F_78 ( V_157 ) ;
F_78 ( F_66 ( 0 ) ) ;
F_78 ( F_66 ( 1 ) ) ;
F_78 ( F_66 ( 2 ) ) ;
F_78 ( F_66 ( 3 ) ) ;
F_78 ( F_66 ( 4 ) ) ;
F_78 ( F_66 ( 5 ) ) ;
F_78 ( F_66 ( 6 ) ) ;
F_78 ( F_66 ( 7 ) ) ;
F_78 ( F_66 ( 8 ) ) ;
F_78 ( F_66 ( 9 ) ) ;
F_78 ( F_66 ( 10 ) ) ;
F_78 ( F_66 ( 11 ) ) ;
F_78 ( F_66 ( 12 ) ) ;
F_78 ( F_66 ( 13 ) ) ;
F_78 ( F_66 ( 14 ) ) ;
F_78 ( F_66 ( 15 ) ) ;
F_78 ( V_293 ) ;
F_78 ( V_294 ) ;
F_78 ( V_295 ) ;
F_78 ( V_296 ) ;
F_78 ( V_297 ) ;
F_78 ( V_298 ) ;
F_78 ( V_299 ) ;
F_78 ( V_300 ) ;
F_78 ( V_301 ) ;
F_78 ( V_302 ) ;
F_78 ( V_303 ) ;
F_78 ( V_304 ) ;
F_78 ( V_103 ) ;
F_78 ( V_305 ) ;
F_78 ( V_306 ) ;
F_78 ( V_307 ) ;
F_78 ( F_13 ( 0 ) ) ;
F_78 ( F_13 ( 1 ) ) ;
F_78 ( F_13 ( 2 ) ) ;
F_78 ( F_13 ( 3 ) ) ;
F_78 ( F_13 ( 4 ) ) ;
F_78 ( F_13 ( 5 ) ) ;
F_78 ( F_13 ( 6 ) ) ;
F_78 ( V_308 ) ;
F_78 ( V_309 ) ;
F_78 ( V_40 ) ;
F_78 ( V_48 ) ;
F_78 ( V_310 ) ;
F_78 ( V_151 ) ;
F_78 ( V_311 ) ;
F_78 ( V_149 ) ;
F_78 ( V_312 ) ;
F_78 ( V_101 ) ;
F_78 ( V_313 ) ;
F_78 ( V_314 ) ;
F_78 ( V_315 ) ;
F_78 ( V_316 ) ;
F_78 ( V_317 ) ;
F_78 ( V_318 ) ;
F_78 ( V_319 ) ;
F_78 ( V_320 ) ;
F_78 ( V_321 ) ;
F_78 ( V_322 ) ;
F_78 ( V_42 ) ;
F_78 ( V_323 ) ;
F_78 ( V_324 ) ;
F_78 ( V_108 ) ;
#undef F_78
F_70 ( V_6 -> V_129 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_6 ,
struct V_325 * V_326 )
{
unsigned int V_22 ;
int V_81 ;
V_6 -> V_327 = F_80 ( L_15 , V_326 -> V_328 ) ;
if ( ! V_6 -> V_327 )
return - V_329 ;
V_6 -> V_330 = F_81 ( V_330 , sizeof( V_330 ) ,
V_331 ) ;
if ( ! V_6 -> V_330 ) {
V_81 = - V_329 ;
goto remove;
}
for ( V_22 = 0 ; V_22 < F_10 ( V_330 ) ; V_22 ++ )
V_6 -> V_330 [ V_22 ] . V_66 = V_6 ;
V_81 = F_82 ( V_6 -> V_330 ,
F_10 ( V_330 ) ,
V_6 -> V_327 , V_326 ) ;
if ( V_81 < 0 )
goto free;
V_6 -> V_326 = V_326 ;
return 0 ;
free:
F_83 ( V_6 -> V_330 ) ;
V_6 -> V_330 = NULL ;
remove:
F_84 ( V_6 -> V_327 ) ;
V_6 -> V_327 = NULL ;
return V_81 ;
}
static int F_85 ( struct V_1 * V_6 )
{
F_86 ( V_6 -> V_330 , F_10 ( V_330 ) ,
V_6 -> V_326 ) ;
V_6 -> V_326 = NULL ;
F_83 ( V_6 -> V_330 ) ;
V_6 -> V_330 = NULL ;
F_84 ( V_6 -> V_327 ) ;
V_6 -> V_327 = NULL ;
return 0 ;
}
static int F_87 ( struct V_2 * V_3 )
{
struct V_332 * V_333 = F_88 ( V_3 -> V_210 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_81 ;
V_81 = F_43 ( V_6 -> V_334 ) ;
if ( V_81 < 0 ) {
F_18 ( V_3 -> V_30 , L_16 ,
V_81 ) ;
return V_81 ;
}
V_6 -> V_5 . type = V_335 ;
V_6 -> V_5 . V_30 = V_3 -> V_30 ;
V_6 -> V_5 . V_336 = & V_337 ;
V_81 = F_89 ( V_333 -> V_338 , & V_6 -> V_5 ) ;
if ( V_81 < 0 ) {
F_18 ( V_3 -> V_30 , L_17 , V_81 ) ;
return V_81 ;
}
if ( F_90 ( V_339 ) ) {
V_81 = F_79 ( V_6 , V_333 -> V_338 -> V_340 ) ;
if ( V_81 < 0 )
F_18 ( V_3 -> V_30 , L_18 , V_81 ) ;
}
return 0 ;
}
static int F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_81 ;
if ( F_90 ( V_339 ) ) {
V_81 = F_85 ( V_6 ) ;
if ( V_81 < 0 )
F_18 ( V_3 -> V_30 , L_19 ,
V_81 ) ;
}
V_81 = F_92 ( & V_6 -> V_5 ) ;
if ( V_81 < 0 ) {
F_18 ( V_3 -> V_30 , L_20 , V_81 ) ;
return V_81 ;
}
V_81 = F_93 ( & V_6 -> V_5 ) ;
if ( V_81 < 0 ) {
F_18 ( V_3 -> V_30 , L_21 , V_81 ) ;
return V_81 ;
}
F_71 ( V_6 -> V_334 ) ;
return 0 ;
}
static int F_94 ( struct V_341 * V_342 )
{
const struct V_343 * V_344 ;
struct V_1 * V_6 ;
struct V_345 * V_8 ;
int V_81 ;
V_344 = F_95 ( V_346 , V_342 -> V_30 . V_31 ) ;
if ( ! V_344 )
return - V_347 ;
V_6 = F_96 ( & V_342 -> V_30 , sizeof( * V_6 ) , V_331 ) ;
if ( ! V_6 )
return - V_329 ;
V_6 -> V_32 = V_344 -> V_66 ;
V_6 -> V_30 = & V_342 -> V_30 ;
V_6 -> V_34 = AUTO ;
V_6 -> V_11 = 44100 ;
V_6 -> V_89 = false ;
V_6 -> V_82 = false ;
V_6 -> V_129 = F_97 ( & V_342 -> V_30 , NULL ) ;
if ( F_98 ( V_6 -> V_129 ) ) {
F_18 ( & V_342 -> V_30 , L_22 ) ;
return F_99 ( V_6 -> V_129 ) ;
}
V_81 = F_100 ( V_6 -> V_129 ) ;
if ( V_81 < 0 )
return V_81 ;
V_6 -> V_207 = F_97 ( & V_342 -> V_30 , L_23 ) ;
if ( F_98 ( V_6 -> V_207 ) )
return F_99 ( V_6 -> V_207 ) ;
V_81 = F_100 ( V_6 -> V_207 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_73 ( V_6 -> V_129 , V_6 -> V_207 ) ;
if ( V_81 < 0 ) {
F_18 ( & V_342 -> V_30 , L_24 , V_81 ) ;
return V_81 ;
}
V_6 -> V_334 = F_101 ( & V_342 -> V_30 , L_25 ) ;
if ( F_98 ( V_6 -> V_334 ) ) {
F_18 ( & V_342 -> V_30 , L_26 ) ;
return F_99 ( V_6 -> V_334 ) ;
}
V_6 -> V_128 = F_101 ( & V_342 -> V_30 , L_27 ) ;
if ( F_98 ( V_6 -> V_128 ) ) {
F_18 ( & V_342 -> V_30 , L_28 ) ;
return F_99 ( V_6 -> V_128 ) ;
}
V_6 -> V_5 . V_30 = & V_342 -> V_30 ;
V_81 = F_102 ( & V_6 -> V_5 ) ;
if ( V_81 < 0 )
return V_81 ;
V_8 = F_103 ( V_342 , V_348 , 0 ) ;
if ( ! V_8 )
return - V_349 ;
V_6 -> V_8 = F_104 ( & V_342 -> V_30 , V_8 ) ;
if ( F_98 ( V_6 -> V_8 ) )
return F_99 ( V_6 -> V_8 ) ;
V_81 = F_105 ( V_342 , 0 ) ;
if ( V_81 < 0 )
return V_81 ;
V_6 -> V_350 = V_81 ;
F_106 ( & V_6 -> V_3 . V_351 ) ;
V_6 -> V_3 . V_336 = & V_352 ;
V_6 -> V_3 . V_30 = & V_342 -> V_30 ;
V_81 = F_107 ( & V_6 -> V_3 ) ;
if ( V_81 < 0 ) {
F_18 ( & V_342 -> V_30 , L_29 ,
V_81 ) ;
return V_81 ;
}
F_108 ( V_342 , V_6 ) ;
return 0 ;
}
static int F_109 ( struct V_341 * V_342 )
{
struct V_1 * V_6 = F_110 ( V_342 ) ;
int V_81 ;
V_81 = F_111 ( & V_6 -> V_3 ) ;
if ( V_81 < 0 ) {
F_18 ( & V_342 -> V_30 , L_30 ,
V_81 ) ;
return V_81 ;
}
V_81 = F_112 ( & V_6 -> V_5 ) ;
if ( V_81 < 0 ) {
F_18 ( & V_342 -> V_30 , L_31 , V_81 ) ;
return V_81 ;
}
F_113 ( V_6 -> V_207 ) ;
F_113 ( V_6 -> V_129 ) ;
return 0 ;
}
