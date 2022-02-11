static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_5 ) {
case V_11 :
F_4 ( V_7 , V_12 ,
V_13 ,
V_10 -> V_14 << V_15 ) ;
break;
case V_16 :
F_4 ( V_7 , V_12 ,
V_13 , 0 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
const T_1 V_17 = V_18 | V_19 ;
switch ( V_5 ) {
case V_11 :
F_4 ( V_7 , V_20 ,
V_21 , V_21 ) ;
F_6 ( 400 ) ;
break;
case V_16 :
if ( ( F_7 ( V_7 , V_20 ) &
V_17 ) != V_17 ) {
F_4 ( V_7 , V_20 ,
V_21 , 0 ) ;
F_6 ( 400 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_22 * V_23 )
{
V_23 -> type = V_24 ;
V_23 -> V_25 = 2 ;
V_23 -> V_26 . integer . V_27 = 0 ;
V_23 -> V_26 . integer . V_28 = 0xfc - 0x3c ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
int V_31 ;
int V_32 ;
int V_33 ;
V_31 = F_7 ( V_7 , V_34 ) ;
V_32 = ( V_31 & V_35 ) >> V_36 ;
V_33 = ( V_31 & V_37 ) >> V_38 ;
V_32 = F_11 ( V_32 , 0x3c , 0xfc ) ;
V_33 = F_11 ( V_33 , 0x3c , 0xfc ) ;
V_32 = 0xfc - V_32 ;
V_33 = 0xfc - V_33 ;
V_30 -> V_26 . integer . V_26 [ 0 ] = V_32 ;
V_30 -> V_26 . integer . V_26 [ 1 ] = V_33 ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
int V_31 ;
int V_32 ;
int V_33 ;
V_32 = V_30 -> V_26 . integer . V_26 [ 0 ] ;
V_33 = V_30 -> V_26 . integer . V_26 [ 1 ] ;
V_32 = F_11 ( V_32 , 0 , 0xfc - 0x3c ) ;
V_33 = F_11 ( V_33 , 0 , 0xfc - 0x3c ) ;
V_32 = 0xfc - V_32 ;
V_33 = 0xfc - V_33 ;
V_31 = V_32 << V_36 |
V_33 << V_38 ;
F_13 ( V_7 , V_34 , V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
int V_39 , V_40 ;
T_2 V_31 = F_7 ( V_7 , V_41 ) ;
if ( ! V_31 ) {
V_30 -> V_26 . integer . V_26 [ 0 ] = 96 ;
V_30 -> V_26 . integer . V_26 [ 1 ] = 96 ;
return 0 ;
}
for ( V_40 = 0 ; V_42 [ V_40 ] > V_31 ; V_40 ++ )
;
V_39 = V_40 ;
V_30 -> V_26 . integer . V_26 [ 0 ] = V_39 ;
V_30 -> V_26 . integer . V_26 [ 1 ] = V_39 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_10 ( V_4 ) ;
int V_39 ;
T_2 V_31 ;
V_39 = ( int ) V_30 -> V_26 . integer . V_26 [ 0 ] ;
if ( V_39 < 0 || V_39 > 96 )
return - V_43 ;
V_31 = V_42 [ V_39 ] ;
F_13 ( V_7 , V_41 , V_31 ) ;
return 0 ;
}
static int F_16 ( struct V_44 * V_45 , int V_46 )
{
struct V_6 * V_7 = V_45 -> V_7 ;
T_2 V_47 = V_48 | V_49 ;
F_4 ( V_7 , V_50 ,
V_47 , V_46 ? V_47 : 0 ) ;
return 0 ;
}
static int F_17 ( struct V_44 * V_45 , unsigned int V_51 )
{
struct V_6 * V_7 = V_45 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
T_2 V_52 = 0 ;
V_10 -> V_53 = 0 ;
switch ( V_51 & V_54 ) {
case V_55 :
break;
case V_56 :
V_52 |= V_57 ;
V_10 -> V_53 = 1 ;
break;
default:
return - V_43 ;
}
switch ( V_51 & V_58 ) {
case V_59 :
V_52 |= V_60 << V_61 ;
break;
case V_62 :
V_52 |= V_60 << V_61 ;
V_52 |= V_63 ;
break;
case V_64 :
V_52 |= V_65 << V_61 ;
break;
case V_66 :
V_52 |= V_67 << V_61 ;
V_52 |= V_68 ;
break;
case V_69 :
V_52 |= V_65 << V_61 ;
V_52 |= V_63 ;
break;
default:
return - V_43 ;
}
V_10 -> V_51 = V_51 & V_58 ;
switch ( V_51 & V_70 ) {
case V_71 :
break;
case V_72 :
V_52 |= V_73 ;
break;
default:
return - V_43 ;
}
F_13 ( V_7 , V_74 , V_52 ) ;
return 0 ;
}
static int F_18 ( struct V_44 * V_45 ,
int V_75 , unsigned int V_76 , int V_77 )
{
struct V_6 * V_7 = V_45 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_75 ) {
case V_78 :
V_10 -> V_79 = V_76 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , int V_80 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_81 = 0 ;
int V_82 ;
switch ( V_80 ) {
case 8000 :
case 16000 :
V_82 = 32000 ;
break;
case 11025 :
case 22050 :
V_82 = 44100 ;
break;
default:
V_82 = V_80 ;
break;
}
switch ( V_82 / V_80 ) {
case 4 :
V_81 |= V_83 << V_84 ;
break;
case 2 :
V_81 |= V_85 << V_84 ;
break;
case 1 :
V_81 |= V_86 << V_84 ;
break;
default:
return - V_43 ;
}
switch ( V_82 ) {
case 32000 :
V_81 |= V_87 << V_88 ;
break;
case 44100 :
V_81 |= V_89 << V_88 ;
break;
case 48000 :
V_81 |= V_90 << V_88 ;
break;
case 96000 :
V_81 |= V_91 << V_88 ;
break;
default:
F_20 ( V_7 -> V_92 , L_1 ,
V_80 ) ;
return - V_43 ;
}
switch ( V_10 -> V_79 / V_80 ) {
case 256 :
V_81 |= V_93 <<
V_94 ;
break;
case 384 :
V_81 |= V_95 <<
V_94 ;
break;
case 512 :
V_81 |= V_96 <<
V_94 ;
break;
default:
if ( V_10 -> V_53 ) {
V_81 |= V_97 <<
V_94 ;
} else {
F_20 ( V_7 -> V_92 ,
L_2 ) ;
F_20 ( V_7 -> V_92 , L_3
L_4 ,
V_10 -> V_79 / V_80 ) ;
return - V_43 ;
}
}
if ( ( V_81 & V_98 ) == V_97 ) {
T_3 V_99 , V_100 ;
int V_101 ;
int V_102 ;
unsigned int V_103 , V_104 , V_105 ;
if ( V_10 -> V_79 > 17000000 ) {
V_101 = 1 ;
V_103 = V_10 -> V_79 / 2 ;
} else {
V_101 = 0 ;
V_103 = V_10 -> V_79 ;
}
if ( V_82 == 44100 )
V_99 = 180633600 ;
else
V_99 = 196608000 ;
V_100 = F_21 ( V_99 , V_103 ) ;
V_104 = V_99 ;
V_100 *= 2048 ;
F_21 ( V_100 , V_103 ) ;
V_105 = V_100 ;
V_102 = V_104 << V_106 |
V_105 << V_107 ;
F_13 ( V_7 , V_108 , V_102 ) ;
if ( V_101 )
F_4 ( V_7 ,
V_109 ,
V_110 ,
V_110 ) ;
else
F_4 ( V_7 ,
V_109 ,
V_110 ,
0 ) ;
F_4 ( V_7 , V_20 ,
V_111 | V_112 ,
V_111 | V_112 ) ;
F_13 ( V_7 , V_113 , V_81 ) ;
} else {
F_13 ( V_7 , V_113 , V_81 ) ;
F_4 ( V_7 , V_20 ,
V_111 | V_112 ,
0 ) ;
}
return 0 ;
}
static int F_22 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
struct V_44 * V_118 )
{
struct V_6 * V_7 = V_118 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_119 = F_23 ( V_117 ) ;
int V_120 = 0 ;
int V_121 ;
int V_122 ;
if ( ! V_10 -> V_79 ) {
F_20 ( V_7 -> V_92 , L_5 , V_123 ) ;
return - V_124 ;
}
if ( V_115 -> V_125 == V_126 )
V_121 = V_127 ;
else
V_121 = V_128 ;
F_4 ( V_7 , V_20 , V_121 ,
V_119 == 1 ? 0 : V_121 ) ;
V_122 = F_19 ( V_7 , F_24 ( V_117 ) ) ;
if ( V_122 )
return V_122 ;
switch ( F_25 ( V_117 ) ) {
case 16 :
if ( V_10 -> V_51 == V_66 )
return - V_43 ;
V_120 |= V_129 << V_130 ;
V_120 |= V_131 <<
V_132 ;
break;
case 20 :
V_120 |= V_133 << V_130 ;
V_120 |= V_134 <<
V_132 ;
break;
case 24 :
V_120 |= V_135 << V_130 ;
V_120 |= V_134 <<
V_132 ;
break;
case 32 :
if ( V_10 -> V_51 == V_66 )
return - V_43 ;
V_120 |= V_136 << V_130 ;
V_120 |= V_134 <<
V_132 ;
break;
default:
return - V_43 ;
}
F_4 ( V_7 , V_74 ,
V_137 | V_138 ,
V_120 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
enum V_139 V_140 )
{
switch ( V_140 ) {
case V_141 :
case V_142 :
case V_143 :
F_4 ( V_7 , V_20 ,
V_144 ,
V_144 ) ;
break;
case V_145 :
F_4 ( V_7 , V_20 ,
V_144 , 0 ) ;
break;
}
return 0 ;
}
static bool F_27 ( struct V_146 * V_92 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_147 :
case V_50 :
case V_148 :
return true ;
}
return false ;
}
static bool F_28 ( struct V_146 * V_92 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_147 :
case V_149 :
case V_113 :
case V_74 :
case V_150 :
case V_50 :
case V_34 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_12 :
case V_157 :
case V_158 :
case V_20 :
case V_108 :
case V_109 :
case V_148 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_41 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
return true ;
default:
return false ;
}
}
static int F_29 ( struct V_6 * V_7 )
{
int V_188 ;
int V_189 ;
int V_190 ;
T_2 V_191 ;
T_2 V_192 ;
int V_193 ;
int V_194 ;
int V_195 ;
int V_196 ;
T_4 V_40 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_189 = F_30 ( V_10 -> V_197 [ V_198 ] . V_199 ) ;
V_190 = F_30 ( V_10 -> V_197 [ V_200 ] . V_199 ) ;
V_188 = ( V_10 -> V_201 > V_202 )
? F_30 ( V_10 -> V_197 [ V_202 ] . V_199 )
: V_203 ;
V_189 = V_189 / 1000 ;
V_190 = V_190 / 1000 ;
V_188 = V_188 / 1000 ;
if ( V_189 <= 0 || V_190 <= 0 || V_188 < 0 ) {
F_20 ( V_7 -> V_92 , L_6 ) ;
return - V_43 ;
}
if ( V_189 > 3600 || V_190 > 3600 || V_188 > 1980 ) {
F_20 ( V_7 -> V_92 ,
L_7 ,
V_189 , V_190 , V_188 ) ;
return - V_43 ;
}
V_191 = F_7 ( V_7 , V_20 ) ;
V_191 |= V_127 |
V_128 |
V_144 ;
V_192 = F_7 ( V_7 , V_155 ) ;
if ( V_190 < 3100 && V_189 < 3100 ) {
F_4 ( V_7 , V_109 ,
V_204 ,
V_204 ) ;
V_191 |= V_205 ;
} else if ( V_190 >= 3100 && V_189 >= 3100 ) {
V_191 &= ~ V_205 ;
V_192 |= V_206 ;
V_192 |= V_207 <<
V_208 ;
}
F_13 ( V_7 , V_155 , V_192 ) ;
F_13 ( V_7 , V_20 , V_191 ) ;
V_193 = V_189 / 2 ;
if ( V_193 <= V_209 )
V_193 = 0 ;
else if ( V_193 >= V_209 + V_210 *
( V_211 >> V_212 ) )
V_193 = V_211 >> V_212 ;
else
V_193 = ( V_193 - V_209 ) / V_210 ;
F_4 ( V_7 , V_156 ,
V_211 , V_193 << V_212 ) ;
V_194 = V_190 / 2 ;
if ( V_194 <= V_213 )
V_194 = 0 ;
else if ( V_194 >= V_213 +
V_214 * V_215 )
V_194 = V_215 ;
else
V_194 = ( V_194 - V_213 ) /
V_214 ;
F_4 ( V_7 , V_157 ,
V_216 |
V_217 ,
V_194 << V_218 |
V_219 <<
V_220 ) ;
V_195 = ( V_193 * 100 ) / V_194 ;
V_196 = 0 ;
for ( V_40 = 0 ; V_40 < F_31 ( V_221 ) ; V_40 ++ ) {
if ( V_195 >= V_221 [ V_40 ] )
V_196 = V_40 ;
else
break;
}
F_4 ( V_7 , V_158 ,
V_222 |
V_223 ,
V_196 << V_224 |
V_196 << V_225 ) ;
return 0 ;
}
static int F_32 ( struct V_226 * V_227 )
{
int V_122 ;
int V_40 ;
int V_228 = 0 ;
struct V_229 * V_188 ;
struct V_9 * V_10 = F_33 ( V_227 ) ;
for ( V_40 = 0 ; V_40 < F_31 ( V_10 -> V_197 ) ; V_40 ++ )
V_10 -> V_197 [ V_40 ] . V_230 = V_231 [ V_40 ] ;
V_188 = F_34 ( & V_227 -> V_92 , L_8 ) ;
if ( F_35 ( V_188 ) ) {
if ( F_36 ( V_188 ) == - V_232 )
return - V_232 ;
} else {
V_228 = 1 ;
F_37 ( V_188 ) ;
}
V_10 -> V_201 = F_31 ( V_10 -> V_197 )
- 1 + V_228 ;
V_122 = F_38 ( & V_227 -> V_92 , V_10 -> V_201 ,
V_10 -> V_197 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_39 ( V_10 -> V_201 ,
V_10 -> V_197 ) ;
if ( ! V_122 )
F_40 ( 10 , 20 ) ;
else
F_41 ( V_10 -> V_201 ,
V_10 -> V_197 ) ;
return V_122 ;
}
static int F_42 ( struct V_6 * V_7 )
{
int V_122 ;
T_2 V_31 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_122 = F_29 ( V_7 ) ;
if ( V_122 )
goto V_233;
F_4 ( V_7 , V_156 ,
V_234 , 1 ) ;
F_13 ( V_7 , V_159 , 0 ) ;
F_13 ( V_7 , V_150 ,
V_235 << V_236 ) ;
F_13 ( V_7 , V_149 ,
V_237 | V_238 ) ;
F_13 ( V_7 , V_50 ,
V_239 |
V_49 |
V_48 ) ;
V_31 = ( ( V_10 -> V_240 ) << V_241 | 0x5f ) ;
F_13 ( V_7 , V_151 , V_31 ) ;
F_13 ( V_7 , V_154 ,
V_242 |
V_243 ) ;
F_4 ( V_7 , V_12 ,
V_13 ,
V_10 -> V_14 << V_15 ) ;
F_4 ( V_7 , V_12 ,
V_244 ,
V_10 -> V_245 << V_246 ) ;
F_13 ( V_7 , V_161 , 0 ) ;
return 0 ;
V_233:
return V_122 ;
}
static int F_43 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_44 ( struct V_226 * V_227 )
{
struct V_9 * V_10 = F_33 ( V_227 ) ;
int V_40 , V_122 , V_247 , V_248 ;
for ( V_40 = 0 ; V_40 < F_31 ( V_249 ) ; V_40 ++ ) {
V_247 = V_249 [ V_40 ] . V_250 ;
V_248 = V_249 [ V_40 ] . V_31 ;
V_122 = F_45 ( V_10 -> V_251 , V_248 , V_247 ) ;
if ( V_122 )
F_20 ( & V_227 -> V_92 ,
L_9 ,
V_123 , V_122 , V_248 , V_247 ) ;
}
}
static int F_46 ( struct V_226 * V_227 ,
const struct V_252 * V_253 )
{
struct V_9 * V_10 ;
int V_122 , V_31 , V_254 ;
struct V_255 * V_256 = V_227 -> V_92 . V_257 ;
T_1 V_26 ;
T_2 V_191 ;
V_10 = F_47 ( & V_227 -> V_92 , sizeof( * V_10 ) , V_258 ) ;
if ( ! V_10 )
return - V_259 ;
F_48 ( V_227 , V_10 ) ;
V_122 = F_32 ( V_227 ) ;
if ( V_122 )
return V_122 ;
V_10 -> V_251 = F_49 ( V_227 , & V_260 ) ;
if ( F_35 ( V_10 -> V_251 ) ) {
V_122 = F_36 ( V_10 -> V_251 ) ;
F_20 ( & V_227 -> V_92 , L_10 , V_122 ) ;
goto V_261;
}
V_10 -> V_262 = F_50 ( & V_227 -> V_92 , NULL ) ;
if ( F_35 ( V_10 -> V_262 ) ) {
V_122 = F_36 ( V_10 -> V_262 ) ;
F_20 ( & V_227 -> V_92 , L_11 , V_122 ) ;
if ( V_122 == - V_263 )
V_122 = - V_232 ;
goto V_261;
}
V_122 = F_51 ( V_10 -> V_262 ) ;
if ( V_122 ) {
F_20 ( & V_227 -> V_92 , L_12 , V_122 ) ;
goto V_261;
}
F_52 ( 1 ) ;
V_122 = F_53 ( V_10 -> V_251 , V_147 , & V_31 ) ;
if ( V_122 ) {
F_20 ( & V_227 -> V_92 , L_13 , V_122 ) ;
goto V_264;
}
if ( ( ( V_31 & V_265 ) >> V_266 ) !=
V_267 ) {
F_20 ( & V_227 -> V_92 ,
L_14 , V_31 ) ;
V_122 = - V_268 ;
goto V_264;
}
V_254 = ( V_31 & V_269 ) >> V_270 ;
F_54 ( & V_227 -> V_92 , L_15 , V_254 ) ;
V_10 -> V_271 = V_254 ;
V_122 = F_45 ( V_10 -> V_251 ,
V_113 ,
V_272 ) ;
if ( V_122 )
F_20 ( & V_227 -> V_92 ,
L_16 , V_122 ) ;
V_191 = V_273 ;
if ( V_10 -> V_201 <= V_202 ) {
V_122 = F_55 ( V_10 -> V_251 ,
V_155 ,
V_274 ,
V_275 ) ;
if ( V_122 )
F_20 ( & V_227 -> V_92 ,
L_17 , V_122 ) ;
V_191 |= V_276 ;
F_54 ( & V_227 -> V_92 ,
L_18 ) ;
} else {
V_191 &= ~ ( V_277
| V_278 ) ;
F_56 ( & V_227 -> V_92 , L_19 ) ;
}
V_122 = F_45 ( V_10 -> V_251 , V_20 , V_191 ) ;
if ( V_122 )
F_20 ( & V_227 -> V_92 ,
L_20 ,
V_122 , V_191 ) ;
if ( V_256 ) {
if ( ! F_57 ( V_256 ,
L_21 , & V_26 ) ) {
switch ( V_26 ) {
case V_279 :
V_10 -> V_14 = 0 ;
break;
case V_280 :
V_10 -> V_14 = 1 ;
break;
case V_281 :
V_10 -> V_14 = 2 ;
break;
case V_282 :
V_10 -> V_14 = 3 ;
break;
default:
V_10 -> V_14 = 2 ;
F_20 ( & V_227 -> V_92 ,
L_22 ) ;
}
} else {
V_10 -> V_14 = 2 ;
}
if ( ! F_57 ( V_256 ,
L_23 , & V_26 ) ) {
if ( ( V_26 >= 1250 ) && ( V_26 <= 3000 ) )
V_10 -> V_245 = ( V_26 / 250 ) - 5 ;
else {
V_10 -> V_245 = 0 ;
F_20 ( & V_227 -> V_92 ,
L_24 ) ;
}
} else {
V_10 -> V_245 = 0 ;
}
}
V_10 -> V_240 = V_283 ;
if ( ! F_57 ( V_256 , L_25 , & V_26 ) ) {
if ( V_26 > V_284 )
V_26 = V_283 ;
V_10 -> V_240 = V_26 ;
}
F_44 ( V_227 ) ;
V_122 = F_58 ( & V_227 -> V_92 ,
& V_285 , & V_286 , 1 ) ;
if ( V_122 )
goto V_264;
return 0 ;
V_264:
F_59 ( V_10 -> V_262 ) ;
V_261:
F_60 ( V_10 -> V_201 , V_10 -> V_197 ) ;
F_41 ( V_10 -> V_201 , V_10 -> V_197 ) ;
return V_122 ;
}
static int F_61 ( struct V_226 * V_227 )
{
struct V_9 * V_10 = F_33 ( V_227 ) ;
F_62 ( & V_227 -> V_92 ) ;
F_59 ( V_10 -> V_262 ) ;
F_60 ( V_10 -> V_201 , V_10 -> V_197 ) ;
F_41 ( V_10 -> V_201 , V_10 -> V_197 ) ;
return 0 ;
}
