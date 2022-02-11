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
F_24 ( V_6 , V_80 , F_35 ( 10 , V_81 ) ) ;
F_6 ( V_6 , V_84 ,
V_86 ) ;
}
static void F_36 ( struct V_1 * V_6 )
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
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . type = V_72 ;
V_79 . V_92 = 0x01 ;
V_79 . V_93 = 6 ;
V_79 . V_66 [ 0 ] = 0x03 ;
V_79 . V_66 [ 1 ] = 0x0c ;
V_79 . V_66 [ 2 ] = 0x00 ;
V_79 . V_66 [ 3 ] = 0x02 << 5 ;
if ( 1 ) {
V_79 . V_66 [ 4 ] = 0x00 << 4 ;
} else {
V_79 . V_66 [ 4 ] = 0x08 << 4 ;
V_79 . V_66 [ 5 ] = 0x00 << 4 ;
}
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
V_25 = V_95 -> V_102 | V_103 ;
F_6 ( V_6 , V_25 , V_104 ) ;
}
static int F_39 ( struct V_4 * V_5 )
{
unsigned int V_105 , V_106 , V_107 , V_22 , V_108 ;
struct V_109 * V_110 = F_40 ( V_5 -> V_111 . V_112 ) ;
struct V_76 * V_77 = & V_110 -> V_113 . V_77 ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_28 * V_29 = V_6 -> V_30 -> V_31 ;
unsigned int V_114 , V_115 , V_12 ;
const struct V_94 * V_95 ;
unsigned int V_116 ;
unsigned long V_25 ;
int V_117 = 1000 ;
int V_81 ;
V_12 = V_77 -> clock * 1000 ;
V_105 = V_77 -> V_118 - V_77 -> V_119 ;
V_107 = V_77 -> V_120 - V_77 -> V_118 ;
V_106 = V_77 -> V_119 - V_77 -> V_121 ;
V_81 = F_41 ( V_6 -> V_122 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_9 , V_81 ) ;
return V_81 ;
}
V_81 = F_41 ( V_6 -> V_123 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_10 , V_81 ) ;
return V_81 ;
}
V_81 = F_42 ( V_5 , V_6 -> V_124 , V_12 * 2 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_11 , V_81 ) ;
return V_81 ;
}
V_81 = F_43 ( V_6 -> V_124 , V_12 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_44 ( V_6 -> V_124 ) ;
if ( V_81 < 0 ) {
F_18 ( V_6 -> V_30 , L_12 , V_81 ) ;
return V_81 ;
}
F_45 ( V_6 -> V_124 ) ;
F_46 ( 1000 , 2000 ) ;
F_47 ( V_6 -> V_124 ) ;
F_48 ( V_110 , F_49 ( 1 ) ,
V_125 ) ;
F_48 ( V_110 , V_126 | V_127 ,
V_128 ) ;
V_114 = 1 + V_105 + V_107 - 10 ;
F_48 ( V_110 , V_129 , V_130 ) ;
V_25 = V_131 | V_132 | V_133 |
V_134 ;
F_48 ( V_110 , V_25 , V_135 ) ;
V_25 = F_50 ( V_114 ) | F_51 ( V_114 + 8 ) ;
F_48 ( V_110 , V_25 , V_136 ) ;
V_25 = F_52 ( 0x210 ) | F_53 ( 0x200 ) |
V_137 ;
F_6 ( V_6 , V_25 , V_138 ) ;
if ( V_110 -> V_139 )
V_25 = V_140 ;
else
V_25 = V_141 ;
if ( ( V_77 -> V_121 == 720 ) && ( ( V_77 -> V_142 == 480 ) ||
( V_77 -> V_142 == 576 ) ) )
F_6 ( V_6 ,
V_25 | V_143 ,
V_144 ) ;
else
F_6 ( V_6 ,
V_25 | V_145 ,
V_144 ) ;
V_115 = F_54 ( V_6 -> V_124 ) / 1000000 * 4 ;
V_25 = F_55 ( V_115 >> 2 ) | F_56 ( V_115 ) ;
F_6 ( V_6 , V_25 , V_146 ) ;
if ( ! V_6 -> V_82 ) {
V_81 = F_14 ( V_6 , V_12 ) ;
if ( V_81 < 0 )
V_6 -> V_82 = true ;
}
if ( F_15 ( V_29 , L_13 ) ) {
}
V_108 = V_147 ;
V_25 = F_57 ( V_108 ) ;
V_25 |= F_58 ( ( V_105 + V_107 +
V_106 - V_108 - 18 ) / 32 ) ;
if ( ! V_6 -> V_82 )
V_25 |= V_148 ;
F_6 ( V_6 , V_25 , V_149 ) ;
if ( V_6 -> V_82 )
F_6 ( V_6 , 0x0 ,
V_90 ) ;
else
F_6 ( V_6 , V_150 ,
V_90 ) ;
F_29 ( V_6 , V_77 ) ;
F_32 ( V_6 ) ;
F_36 ( V_6 ) ;
if ( F_15 ( V_29 , L_1 ) ) {
V_116 = F_10 ( V_151 ) ;
V_95 = V_151 ;
} else {
V_116 = F_10 ( V_152 ) ;
V_95 = V_152 ;
}
for ( V_22 = 0 ; V_22 < V_116 ; V_22 ++ ) {
if ( V_12 <= V_95 [ V_22 ] . V_12 ) {
F_38 ( V_6 , & V_95 [ V_22 ] ) ;
break;
}
}
F_6 ( V_6 ,
F_59 ( 0 ) |
F_60 ( 0 ) |
F_61 ( 8 ) |
F_62 ( 8 ) ,
V_153 ) ;
V_25 = F_63 ( 1 ) |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 ;
F_6 ( V_6 , V_25 , F_64 ( 0 ) ) ;
F_6 ( V_6 , V_25 , F_64 ( 8 ) ) ;
V_25 = 0x1c800 ;
V_25 &= ~ F_65 ( ~ 0 ) ;
V_25 |= F_65 ( 2 ) ;
F_6 ( V_6 , V_25 , V_159 ) ;
F_48 ( V_110 , V_160 , V_161 ) ;
F_48 ( V_110 , V_162 << 8 , V_163 ) ;
F_48 ( V_110 , V_162 , V_163 ) ;
F_6 ( V_6 ,
V_164 |
V_165 |
V_166 |
V_167 ,
V_168 ) ;
F_6 ( V_6 ,
V_164 |
V_165 |
V_166 |
V_169 ,
V_168 ) ;
do {
F_66 ( -- V_117 < 0 ) ;
V_25 = F_4 ( V_6 , V_168 ) ;
} while ( V_25 & V_170 );
V_25 = V_171 |
V_172 |
V_173 |
V_174 |
V_175 ;
if ( V_77 -> V_176 & V_177 )
V_25 |= V_178 ;
if ( V_77 -> V_176 & V_179 )
V_25 |= V_180 ;
if ( V_77 -> V_176 & V_181 )
V_25 |= V_182 ;
if ( V_77 -> V_176 & V_183 )
V_25 |= V_184 ;
F_6 ( V_6 , V_25 , V_185 ) ;
V_25 = V_186 | V_187 ;
F_6 ( V_6 , V_25 , V_188 ) ;
F_6 ( V_6 , 0 , V_189 ) ;
F_6 ( V_6 , V_190 , V_189 ) ;
F_6 ( V_6 , V_25 | V_191 ,
V_188 ) ;
F_6 ( V_6 , 0 , V_189 ) ;
F_48 ( V_110 , V_192 , V_193 ) ;
V_25 = V_194 | V_195 | V_196 | V_197 |
V_198 | V_199 | V_200 ;
F_48 ( V_110 , V_25 , V_201 ) ;
V_25 = V_202 ;
F_48 ( V_110 , V_25 , V_161 ) ;
F_48 ( V_110 , V_162 << 8 , V_163 ) ;
F_48 ( V_110 , V_162 , V_163 ) ;
return 0 ;
}
static int F_67 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_45 ( V_6 -> V_124 ) ;
F_68 ( V_6 -> V_124 ) ;
F_69 ( V_6 -> V_123 ) ;
F_69 ( V_6 -> V_122 ) ;
return 0 ;
}
static int F_70 ( struct V_4 * V_5 ,
struct V_124 * V_124 , unsigned long V_12 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_124 * V_113 ;
int V_81 ;
V_81 = F_71 ( V_124 , V_6 -> V_203 ) ;
if ( V_81 < 0 ) {
F_18 ( V_5 -> V_30 , L_14 , V_81 ) ;
return V_81 ;
}
V_113 = F_72 ( V_6 -> V_203 ) ;
V_81 = F_43 ( V_113 , V_12 * 2 ) ;
if ( V_81 < 0 )
F_18 ( V_5 -> V_30 ,
L_15 ,
V_12 * 2 ) ;
return 0 ;
}
static int F_73 ( struct V_4 * V_5 ,
struct V_76 * V_77 ,
enum V_204 * V_205 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_12 = V_77 -> clock * 1000 ;
struct V_124 * V_206 ;
long V_81 ;
V_206 = F_72 ( V_6 -> V_203 ) ;
V_81 = F_74 ( V_206 , V_12 * 4 ) ;
if ( V_81 < 0 )
* V_205 = V_207 ;
else
* V_205 = V_208 ;
return 0 ;
}
static int F_75 ( struct V_209 * V_210 , void * V_66 )
{
struct V_211 * V_29 = V_210 -> V_212 ;
struct V_1 * V_6 = V_29 -> V_213 -> V_66 ;
#define F_76 ( T_4 ) \
seq_printf(s, "%-56s %#05x %08lx\n", #name, name, \
tegra_hdmi_readl(hdmi, name))
F_76 ( V_214 ) ;
F_76 ( V_189 ) ;
F_76 ( V_188 ) ;
F_76 ( V_185 ) ;
F_76 ( V_215 ) ;
F_76 ( V_216 ) ;
F_76 ( V_217 ) ;
F_76 ( V_218 ) ;
F_76 ( V_219 ) ;
F_76 ( V_220 ) ;
F_76 ( V_221 ) ;
F_76 ( V_222 ) ;
F_76 ( V_223 ) ;
F_76 ( V_224 ) ;
F_76 ( V_225 ) ;
F_76 ( V_226 ) ;
F_76 ( V_227 ) ;
F_76 ( V_228 ) ;
F_76 ( V_229 ) ;
F_76 ( V_230 ) ;
F_76 ( V_231 ) ;
F_76 ( V_232 ) ;
F_76 ( V_233 ) ;
F_76 ( V_234 ) ;
F_76 ( V_235 ) ;
F_76 ( V_236 ) ;
F_76 ( V_237 ) ;
F_76 ( V_238 ) ;
F_76 ( V_239 ) ;
F_76 ( V_240 ) ;
F_76 ( V_86 ) ;
F_76 ( V_241 ) ;
F_76 ( V_71 ) ;
F_76 ( V_242 ) ;
F_76 ( V_243 ) ;
F_76 ( V_83 ) ;
F_76 ( V_244 ) ;
F_76 ( V_69 ) ;
F_76 ( V_245 ) ;
F_76 ( V_246 ) ;
F_76 ( V_247 ) ;
F_76 ( V_248 ) ;
F_76 ( V_90 ) ;
F_76 ( V_249 ) ;
F_76 ( V_73 ) ;
F_76 ( V_250 ) ;
F_76 ( V_251 ) ;
F_76 ( V_252 ) ;
F_76 ( V_253 ) ;
F_76 ( V_254 ) ;
F_76 ( V_255 ) ;
F_76 ( V_256 ) ;
F_76 ( V_257 ) ;
F_76 ( V_44 ) ;
F_76 ( V_258 ) ;
F_76 ( V_259 ) ;
F_76 ( V_52 ) ;
F_76 ( V_50 ) ;
F_76 ( V_260 ) ;
F_76 ( V_261 ) ;
F_76 ( V_262 ) ;
F_76 ( V_263 ) ;
F_76 ( V_264 ) ;
F_76 ( V_265 ) ;
F_76 ( V_266 ) ;
F_76 ( V_267 ) ;
F_76 ( V_268 ) ;
F_76 ( V_269 ) ;
F_76 ( V_149 ) ;
F_76 ( V_270 ) ;
F_76 ( V_138 ) ;
F_76 ( V_271 ) ;
F_76 ( V_272 ) ;
F_76 ( V_273 ) ;
F_76 ( V_274 ) ;
F_76 ( V_275 ) ;
F_76 ( V_276 ) ;
F_76 ( V_277 ) ;
F_76 ( V_278 ) ;
F_76 ( V_55 ) ;
F_76 ( V_279 ) ;
F_76 ( V_280 ) ;
F_76 ( V_281 ) ;
F_76 ( V_282 ) ;
F_76 ( V_168 ) ;
F_76 ( V_283 ) ;
F_76 ( V_97 ) ;
F_76 ( V_99 ) ;
F_76 ( V_284 ) ;
F_76 ( V_159 ) ;
F_76 ( V_285 ) ;
F_76 ( V_286 ) ;
F_76 ( V_287 ) ;
F_76 ( V_288 ) ;
F_76 ( V_153 ) ;
F_76 ( F_64 ( 0 ) ) ;
F_76 ( F_64 ( 1 ) ) ;
F_76 ( F_64 ( 2 ) ) ;
F_76 ( F_64 ( 3 ) ) ;
F_76 ( F_64 ( 4 ) ) ;
F_76 ( F_64 ( 5 ) ) ;
F_76 ( F_64 ( 6 ) ) ;
F_76 ( F_64 ( 7 ) ) ;
F_76 ( F_64 ( 8 ) ) ;
F_76 ( F_64 ( 9 ) ) ;
F_76 ( F_64 ( 10 ) ) ;
F_76 ( F_64 ( 11 ) ) ;
F_76 ( F_64 ( 12 ) ) ;
F_76 ( F_64 ( 13 ) ) ;
F_76 ( F_64 ( 14 ) ) ;
F_76 ( F_64 ( 15 ) ) ;
F_76 ( V_289 ) ;
F_76 ( V_290 ) ;
F_76 ( V_291 ) ;
F_76 ( V_292 ) ;
F_76 ( V_293 ) ;
F_76 ( V_294 ) ;
F_76 ( V_295 ) ;
F_76 ( V_296 ) ;
F_76 ( V_297 ) ;
F_76 ( V_298 ) ;
F_76 ( V_299 ) ;
F_76 ( V_300 ) ;
F_76 ( V_104 ) ;
F_76 ( V_301 ) ;
F_76 ( V_302 ) ;
F_76 ( V_303 ) ;
F_76 ( F_13 ( 0 ) ) ;
F_76 ( F_13 ( 1 ) ) ;
F_76 ( F_13 ( 2 ) ) ;
F_76 ( F_13 ( 3 ) ) ;
F_76 ( F_13 ( 4 ) ) ;
F_76 ( F_13 ( 5 ) ) ;
F_76 ( F_13 ( 6 ) ) ;
F_76 ( V_304 ) ;
F_76 ( V_305 ) ;
F_76 ( V_40 ) ;
F_76 ( V_48 ) ;
F_76 ( V_306 ) ;
F_76 ( V_146 ) ;
F_76 ( V_307 ) ;
F_76 ( V_144 ) ;
F_76 ( V_308 ) ;
F_76 ( V_101 ) ;
F_76 ( V_309 ) ;
F_76 ( V_310 ) ;
F_76 ( V_311 ) ;
F_76 ( V_312 ) ;
F_76 ( V_313 ) ;
F_76 ( V_314 ) ;
F_76 ( V_315 ) ;
F_76 ( V_316 ) ;
F_76 ( V_317 ) ;
F_76 ( V_318 ) ;
F_76 ( V_42 ) ;
F_76 ( V_319 ) ;
F_76 ( V_320 ) ;
#undef F_76
return 0 ;
}
static int F_77 ( struct V_1 * V_6 ,
struct V_321 * V_322 )
{
unsigned int V_22 ;
int V_81 ;
V_6 -> V_323 = F_78 ( L_16 , V_322 -> V_324 ) ;
if ( ! V_6 -> V_323 )
return - V_325 ;
V_6 -> V_326 = F_79 ( V_326 , sizeof( V_326 ) ,
V_327 ) ;
if ( ! V_6 -> V_326 ) {
V_81 = - V_325 ;
goto remove;
}
for ( V_22 = 0 ; V_22 < F_10 ( V_326 ) ; V_22 ++ )
V_6 -> V_326 [ V_22 ] . V_66 = V_6 ;
V_81 = F_80 ( V_6 -> V_326 ,
F_10 ( V_326 ) ,
V_6 -> V_323 , V_322 ) ;
if ( V_81 < 0 )
goto free;
V_6 -> V_322 = V_322 ;
return 0 ;
free:
F_81 ( V_6 -> V_326 ) ;
V_6 -> V_326 = NULL ;
remove:
F_82 ( V_6 -> V_323 ) ;
V_6 -> V_323 = NULL ;
return V_81 ;
}
static int F_83 ( struct V_1 * V_6 )
{
F_84 ( V_6 -> V_326 , F_10 ( V_326 ) ,
V_6 -> V_322 ) ;
V_6 -> V_322 = NULL ;
F_81 ( V_6 -> V_326 ) ;
V_6 -> V_326 = NULL ;
F_82 ( V_6 -> V_323 ) ;
V_6 -> V_323 = NULL ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_328 * V_329 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_81 ;
V_6 -> V_5 . type = V_330 ;
V_6 -> V_5 . V_30 = V_3 -> V_30 ;
V_6 -> V_5 . V_331 = & V_332 ;
V_81 = F_86 ( V_329 , & V_6 -> V_5 ) ;
if ( V_81 < 0 ) {
F_18 ( V_3 -> V_30 , L_17 , V_81 ) ;
return V_81 ;
}
if ( F_87 ( V_333 ) ) {
V_81 = F_77 ( V_6 , V_329 -> V_334 ) ;
if ( V_81 < 0 )
F_18 ( V_3 -> V_30 , L_18 , V_81 ) ;
}
return 0 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_81 ;
if ( F_87 ( V_333 ) ) {
V_81 = F_83 ( V_6 ) ;
if ( V_81 < 0 )
F_18 ( V_3 -> V_30 , L_19 ,
V_81 ) ;
}
V_81 = F_89 ( & V_6 -> V_5 ) ;
if ( V_81 < 0 ) {
F_18 ( V_3 -> V_30 , L_20 , V_81 ) ;
return V_81 ;
}
V_81 = F_90 ( & V_6 -> V_5 ) ;
if ( V_81 < 0 ) {
F_18 ( V_3 -> V_30 , L_21 , V_81 ) ;
return V_81 ;
}
return 0 ;
}
static int F_91 ( struct V_335 * V_336 )
{
struct V_337 * V_338 = F_92 ( V_336 -> V_30 . V_206 ) ;
struct V_1 * V_6 ;
struct V_339 * V_8 ;
int V_81 ;
V_6 = F_93 ( & V_336 -> V_30 , sizeof( * V_6 ) , V_327 ) ;
if ( ! V_6 )
return - V_325 ;
V_6 -> V_30 = & V_336 -> V_30 ;
V_6 -> V_34 = AUTO ;
V_6 -> V_11 = 44100 ;
V_6 -> V_89 = false ;
V_6 -> V_82 = false ;
V_6 -> V_124 = F_94 ( & V_336 -> V_30 , NULL ) ;
if ( F_95 ( V_6 -> V_124 ) ) {
F_18 ( & V_336 -> V_30 , L_22 ) ;
return F_96 ( V_6 -> V_124 ) ;
}
V_81 = F_97 ( V_6 -> V_124 ) ;
if ( V_81 < 0 )
return V_81 ;
V_6 -> V_203 = F_94 ( & V_336 -> V_30 , L_23 ) ;
if ( F_95 ( V_6 -> V_203 ) )
return F_96 ( V_6 -> V_203 ) ;
V_81 = F_97 ( V_6 -> V_203 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_71 ( V_6 -> V_124 , V_6 -> V_203 ) ;
if ( V_81 < 0 ) {
F_18 ( & V_336 -> V_30 , L_24 , V_81 ) ;
return V_81 ;
}
V_6 -> V_122 = F_98 ( & V_336 -> V_30 , L_25 ) ;
if ( F_95 ( V_6 -> V_122 ) ) {
F_18 ( & V_336 -> V_30 , L_26 ) ;
return F_96 ( V_6 -> V_122 ) ;
}
V_6 -> V_123 = F_98 ( & V_336 -> V_30 , L_27 ) ;
if ( F_95 ( V_6 -> V_123 ) ) {
F_18 ( & V_336 -> V_30 , L_28 ) ;
return F_96 ( V_6 -> V_123 ) ;
}
V_6 -> V_5 . V_30 = & V_336 -> V_30 ;
V_81 = F_99 ( & V_6 -> V_5 ) ;
if ( V_81 < 0 )
return V_81 ;
V_8 = F_100 ( V_336 , V_340 , 0 ) ;
if ( ! V_8 )
return - V_341 ;
V_6 -> V_8 = F_101 ( & V_336 -> V_30 , V_8 ) ;
if ( F_95 ( V_6 -> V_8 ) )
return F_96 ( V_6 -> V_8 ) ;
V_81 = F_102 ( V_336 , 0 ) ;
if ( V_81 < 0 )
return V_81 ;
V_6 -> V_342 = V_81 ;
V_6 -> V_3 . V_331 = & V_343 ;
F_103 ( & V_6 -> V_3 . V_344 ) ;
V_6 -> V_3 . V_30 = & V_336 -> V_30 ;
V_81 = F_104 ( V_338 , & V_6 -> V_3 ) ;
if ( V_81 < 0 ) {
F_18 ( & V_336 -> V_30 , L_29 ,
V_81 ) ;
return V_81 ;
}
F_105 ( V_336 , V_6 ) ;
return 0 ;
}
static int F_106 ( struct V_335 * V_336 )
{
struct V_337 * V_338 = F_92 ( V_336 -> V_30 . V_206 ) ;
struct V_1 * V_6 = F_107 ( V_336 ) ;
int V_81 ;
V_81 = F_108 ( V_338 , & V_6 -> V_3 ) ;
if ( V_81 < 0 ) {
F_18 ( & V_336 -> V_30 , L_30 ,
V_81 ) ;
return V_81 ;
}
F_109 ( V_6 -> V_203 ) ;
F_109 ( V_6 -> V_124 ) ;
return 0 ;
}
