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
static int F_14 ( struct V_39 * V_40 , int V_41 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
T_2 V_42 = V_43 | V_44 ;
F_4 ( V_7 , V_45 ,
V_42 , V_41 ? V_42 : 0 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 , unsigned int V_46 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
T_2 V_47 = 0 ;
V_10 -> V_48 = 0 ;
switch ( V_46 & V_49 ) {
case V_50 :
break;
case V_51 :
V_47 |= V_52 ;
V_10 -> V_48 = 1 ;
break;
default:
return - V_53 ;
}
switch ( V_46 & V_54 ) {
case V_55 :
V_47 |= V_56 << V_57 ;
break;
case V_58 :
V_47 |= V_56 << V_57 ;
V_47 |= V_59 ;
break;
case V_60 :
V_47 |= V_61 << V_57 ;
break;
case V_62 :
V_47 |= V_63 << V_57 ;
V_47 |= V_64 ;
break;
case V_65 :
V_47 |= V_61 << V_57 ;
V_47 |= V_59 ;
break;
default:
return - V_53 ;
}
V_10 -> V_46 = V_46 & V_54 ;
switch ( V_46 & V_66 ) {
case V_67 :
break;
case V_68 :
V_47 |= V_69 ;
break;
default:
return - V_53 ;
}
F_13 ( V_7 , V_70 , V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_39 * V_40 ,
int V_71 , unsigned int V_72 , int V_73 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_71 ) {
case V_74 :
V_10 -> V_75 = V_72 ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , int V_76 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_77 = 0 ;
int V_78 ;
switch ( V_76 ) {
case 8000 :
case 16000 :
V_78 = 32000 ;
break;
case 11025 :
case 22050 :
V_78 = 44100 ;
break;
default:
V_78 = V_76 ;
break;
}
switch ( V_78 / V_76 ) {
case 4 :
V_77 |= V_79 << V_80 ;
break;
case 2 :
V_77 |= V_81 << V_80 ;
break;
case 1 :
V_77 |= V_82 << V_80 ;
break;
default:
return - V_53 ;
}
switch ( V_78 ) {
case 32000 :
V_77 |= V_83 << V_84 ;
break;
case 44100 :
V_77 |= V_85 << V_84 ;
break;
case 48000 :
V_77 |= V_86 << V_84 ;
break;
case 96000 :
V_77 |= V_87 << V_84 ;
break;
default:
F_18 ( V_7 -> V_88 , L_1 ,
V_76 ) ;
return - V_53 ;
}
switch ( V_10 -> V_75 / V_76 ) {
case 256 :
V_77 |= V_89 <<
V_90 ;
break;
case 384 :
V_77 |= V_91 <<
V_90 ;
break;
case 512 :
V_77 |= V_92 <<
V_90 ;
break;
default:
if ( V_10 -> V_48 ) {
V_77 |= V_93 <<
V_90 ;
} else {
F_18 ( V_7 -> V_88 ,
L_2 ) ;
F_18 ( V_7 -> V_88 , L_3
L_4 ,
V_10 -> V_75 / V_76 ) ;
return - V_53 ;
}
}
if ( ( V_77 & V_94 ) == V_93 ) {
T_3 V_95 , V_96 ;
int V_97 ;
int V_98 ;
unsigned int V_99 , V_100 , V_101 ;
if ( V_10 -> V_75 > 17000000 ) {
V_97 = 1 ;
V_99 = V_10 -> V_75 / 2 ;
} else {
V_97 = 0 ;
V_99 = V_10 -> V_75 ;
}
if ( V_78 == 44100 )
V_95 = 180633600 ;
else
V_95 = 196608000 ;
V_96 = F_19 ( V_95 , V_99 ) ;
V_100 = V_95 ;
V_96 *= 2048 ;
F_19 ( V_96 , V_99 ) ;
V_101 = V_96 ;
V_98 = V_100 << V_102 |
V_101 << V_103 ;
F_13 ( V_7 , V_104 , V_98 ) ;
if ( V_97 )
F_4 ( V_7 ,
V_105 ,
V_106 ,
V_106 ) ;
else
F_4 ( V_7 ,
V_105 ,
V_106 ,
0 ) ;
F_4 ( V_7 , V_20 ,
V_107 | V_108 ,
V_107 | V_108 ) ;
F_13 ( V_7 , V_109 , V_77 ) ;
} else {
F_13 ( V_7 , V_109 , V_77 ) ;
F_4 ( V_7 , V_20 ,
V_107 | V_108 ,
0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_110 * V_111 ,
struct V_112 * V_113 ,
struct V_39 * V_114 )
{
struct V_6 * V_7 = V_114 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_115 = F_21 ( V_113 ) ;
int V_116 = 0 ;
int V_117 ;
int V_118 ;
if ( ! V_10 -> V_75 ) {
F_18 ( V_7 -> V_88 , L_5 , V_119 ) ;
return - V_120 ;
}
if ( V_111 -> V_121 == V_122 )
V_117 = V_123 ;
else
V_117 = V_124 ;
F_4 ( V_7 , V_20 , V_117 ,
V_115 == 1 ? 0 : V_117 ) ;
V_118 = F_17 ( V_7 , F_22 ( V_113 ) ) ;
if ( V_118 )
return V_118 ;
switch ( F_23 ( V_113 ) ) {
case 16 :
if ( V_10 -> V_46 == V_62 )
return - V_53 ;
V_116 |= V_125 << V_126 ;
V_116 |= V_127 <<
V_128 ;
break;
case 20 :
V_116 |= V_129 << V_126 ;
V_116 |= V_130 <<
V_128 ;
break;
case 24 :
V_116 |= V_131 << V_126 ;
V_116 |= V_130 <<
V_128 ;
break;
case 32 :
if ( V_10 -> V_46 == V_62 )
return - V_53 ;
V_116 |= V_132 << V_126 ;
V_116 |= V_130 <<
V_128 ;
break;
default:
return - V_53 ;
}
F_4 ( V_7 , V_70 ,
V_133 | V_134 ,
V_116 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
enum V_135 V_136 )
{
switch ( V_136 ) {
case V_137 :
case V_138 :
case V_139 :
F_4 ( V_7 , V_20 ,
V_140 ,
V_140 ) ;
break;
case V_141 :
F_4 ( V_7 , V_20 ,
V_140 , 0 ) ;
break;
}
return 0 ;
}
static bool F_25 ( struct V_142 * V_88 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_143 :
case V_45 :
case V_144 :
return true ;
}
return false ;
}
static bool F_26 ( struct V_142 * V_88 , unsigned int V_31 )
{
switch ( V_31 ) {
case V_143 :
case V_145 :
case V_109 :
case V_70 :
case V_146 :
case V_45 :
case V_34 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_12 :
case V_153 :
case V_154 :
case V_20 :
case V_104 :
case V_105 :
case V_144 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
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
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
return true ;
default:
return false ;
}
}
static int F_27 ( struct V_6 * V_7 )
{
int V_185 ;
int V_186 ;
int V_187 ;
T_2 V_188 ;
T_2 V_189 ;
int V_190 ;
int V_191 ;
int V_192 ;
int V_193 ;
T_4 V_194 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_186 = F_28 ( V_10 -> V_195 [ V_196 ] . V_197 ) ;
V_187 = F_28 ( V_10 -> V_195 [ V_198 ] . V_197 ) ;
V_185 = ( V_10 -> V_199 > V_200 )
? F_28 ( V_10 -> V_195 [ V_200 ] . V_197 )
: V_201 ;
V_186 = V_186 / 1000 ;
V_187 = V_187 / 1000 ;
V_185 = V_185 / 1000 ;
if ( V_186 <= 0 || V_187 <= 0 || V_185 < 0 ) {
F_18 ( V_7 -> V_88 , L_6 ) ;
return - V_53 ;
}
if ( V_186 > 3600 || V_187 > 3600 || V_185 > 1980 ) {
F_18 ( V_7 -> V_88 ,
L_7 ,
V_186 , V_187 , V_185 ) ;
return - V_53 ;
}
V_188 = F_7 ( V_7 , V_20 ) ;
V_188 |= V_123 |
V_124 |
V_140 ;
V_189 = F_7 ( V_7 , V_151 ) ;
if ( V_187 < 3100 && V_186 < 3100 ) {
F_4 ( V_7 , V_105 ,
V_202 ,
V_202 ) ;
V_188 |= V_203 ;
} else if ( V_187 >= 3100 && V_186 >= 3100 ) {
V_188 &= ~ V_203 ;
V_189 |= V_204 ;
V_189 |= V_205 <<
V_206 ;
}
F_13 ( V_7 , V_151 , V_189 ) ;
F_13 ( V_7 , V_20 , V_188 ) ;
V_190 = V_186 / 2 ;
if ( V_190 <= V_207 )
V_190 = 0 ;
else if ( V_190 >= V_207 + V_208 *
( V_209 >> V_210 ) )
V_190 = V_209 >> V_210 ;
else
V_190 = ( V_190 - V_207 ) / V_208 ;
F_4 ( V_7 , V_152 ,
V_209 , V_190 << V_210 ) ;
V_191 = V_187 / 2 ;
if ( V_191 <= V_211 )
V_191 = 0 ;
else if ( V_191 >= V_211 +
V_212 * V_213 )
V_191 = V_213 ;
else
V_191 = ( V_191 - V_211 ) /
V_212 ;
F_4 ( V_7 , V_153 ,
V_214 |
V_215 ,
V_191 << V_216 |
V_217 <<
V_218 ) ;
V_192 = ( V_190 * 100 ) / V_191 ;
V_193 = 0 ;
for ( V_194 = 0 ; V_194 < F_29 ( V_219 ) ; V_194 ++ ) {
if ( V_192 >= V_219 [ V_194 ] )
V_193 = V_194 ;
else
break;
}
F_4 ( V_7 , V_154 ,
V_220 |
V_221 ,
V_193 << V_222 |
V_193 << V_223 ) ;
return 0 ;
}
static int F_30 ( struct V_224 * V_225 )
{
int V_118 ;
int V_194 ;
int V_226 = 0 ;
struct V_227 * V_185 ;
struct V_9 * V_10 = F_31 ( V_225 ) ;
for ( V_194 = 0 ; V_194 < F_29 ( V_10 -> V_195 ) ; V_194 ++ )
V_10 -> V_195 [ V_194 ] . V_228 = V_229 [ V_194 ] ;
V_185 = F_32 ( & V_225 -> V_88 , L_8 ) ;
if ( F_33 ( V_185 ) ) {
if ( F_34 ( V_185 ) == - V_230 )
return - V_230 ;
} else {
V_226 = 1 ;
F_35 ( V_185 ) ;
}
V_10 -> V_199 = F_29 ( V_10 -> V_195 )
- 1 + V_226 ;
V_118 = F_36 ( & V_225 -> V_88 , V_10 -> V_199 ,
V_10 -> V_195 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_37 ( V_10 -> V_199 ,
V_10 -> V_195 ) ;
if ( ! V_118 )
F_38 ( 10 , 20 ) ;
else
F_39 ( V_10 -> V_199 ,
V_10 -> V_195 ) ;
return V_118 ;
}
static int F_40 ( struct V_6 * V_7 )
{
int V_118 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_118 = F_27 ( V_7 ) ;
if ( V_118 )
goto V_231;
F_4 ( V_7 , V_152 ,
V_232 , 1 ) ;
F_13 ( V_7 , V_155 , 0 ) ;
F_13 ( V_7 , V_146 ,
V_233 << V_234 ) ;
F_13 ( V_7 , V_145 ,
V_235 | V_236 ) ;
F_13 ( V_7 , V_45 ,
V_237 |
V_44 |
V_43 ) ;
F_13 ( V_7 , V_147 , 0x015f ) ;
F_13 ( V_7 , V_150 ,
V_238 |
V_239 ) ;
F_4 ( V_7 , V_12 ,
V_13 ,
V_10 -> V_14 << V_15 ) ;
F_4 ( V_7 , V_12 ,
V_240 ,
V_10 -> V_241 << V_242 ) ;
F_13 ( V_7 , V_157 , 0 ) ;
return 0 ;
V_231:
return V_118 ;
}
static int F_41 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_42 ( struct V_224 * V_225 )
{
struct V_9 * V_10 = F_31 ( V_225 ) ;
int V_194 , V_118 , V_243 , V_244 ;
for ( V_194 = 0 ; V_194 < F_29 ( V_245 ) ; V_194 ++ ) {
V_243 = V_245 [ V_194 ] . V_246 ;
V_244 = V_245 [ V_194 ] . V_31 ;
V_118 = F_43 ( V_10 -> V_247 , V_244 , V_243 ) ;
if ( V_118 )
F_18 ( & V_225 -> V_88 ,
L_9 ,
V_119 , V_118 , V_244 , V_243 ) ;
}
}
static int F_44 ( struct V_224 * V_225 ,
const struct V_248 * V_249 )
{
struct V_9 * V_10 ;
int V_118 , V_31 , V_250 ;
struct V_251 * V_252 = V_225 -> V_88 . V_253 ;
T_1 V_26 ;
T_2 V_188 ;
V_10 = F_45 ( & V_225 -> V_88 , sizeof( * V_10 ) , V_254 ) ;
if ( ! V_10 )
return - V_255 ;
F_46 ( V_225 , V_10 ) ;
V_118 = F_30 ( V_225 ) ;
if ( V_118 )
return V_118 ;
V_10 -> V_247 = F_47 ( V_225 , & V_256 ) ;
if ( F_33 ( V_10 -> V_247 ) ) {
V_118 = F_34 ( V_10 -> V_247 ) ;
F_18 ( & V_225 -> V_88 , L_10 , V_118 ) ;
goto V_257;
}
V_10 -> V_258 = F_48 ( & V_225 -> V_88 , NULL ) ;
if ( F_33 ( V_10 -> V_258 ) ) {
V_118 = F_34 ( V_10 -> V_258 ) ;
F_18 ( & V_225 -> V_88 , L_11 , V_118 ) ;
if ( V_118 == - V_259 )
V_118 = - V_230 ;
goto V_257;
}
V_118 = F_49 ( V_10 -> V_258 ) ;
if ( V_118 ) {
F_18 ( & V_225 -> V_88 , L_12 , V_118 ) ;
goto V_257;
}
F_50 ( 1 ) ;
V_118 = F_51 ( V_10 -> V_247 , V_143 , & V_31 ) ;
if ( V_118 ) {
F_18 ( & V_225 -> V_88 , L_13 , V_118 ) ;
goto V_260;
}
if ( ( ( V_31 & V_261 ) >> V_262 ) !=
V_263 ) {
F_18 ( & V_225 -> V_88 ,
L_14 , V_31 ) ;
V_118 = - V_264 ;
goto V_260;
}
V_250 = ( V_31 & V_265 ) >> V_266 ;
F_52 ( & V_225 -> V_88 , L_15 , V_250 ) ;
V_10 -> V_267 = V_250 ;
V_118 = F_43 ( V_10 -> V_247 ,
V_109 ,
V_268 ) ;
if ( V_118 )
F_18 ( & V_225 -> V_88 ,
L_16 , V_118 ) ;
V_188 = V_269 ;
if ( V_10 -> V_199 <= V_200 ) {
V_118 = F_53 ( V_10 -> V_247 ,
V_151 ,
V_270 ,
V_271 ) ;
if ( V_118 )
F_18 ( & V_225 -> V_88 ,
L_17 , V_118 ) ;
V_188 |= V_272 ;
F_52 ( & V_225 -> V_88 ,
L_18 ) ;
} else {
V_188 &= ~ ( V_273
| V_274 ) ;
F_54 ( & V_225 -> V_88 , L_19 ) ;
}
V_118 = F_43 ( V_10 -> V_247 , V_20 , V_188 ) ;
if ( V_118 )
F_18 ( & V_225 -> V_88 ,
L_20 ,
V_118 , V_188 ) ;
if ( V_252 ) {
if ( ! F_55 ( V_252 ,
L_21 , & V_26 ) ) {
switch ( V_26 ) {
case V_275 :
V_10 -> V_14 = 0 ;
break;
case V_276 :
V_10 -> V_14 = 1 ;
break;
case V_277 :
V_10 -> V_14 = 2 ;
break;
case V_278 :
V_10 -> V_14 = 3 ;
break;
default:
V_10 -> V_14 = 2 ;
F_18 ( & V_225 -> V_88 ,
L_22 ) ;
}
} else {
V_10 -> V_14 = 2 ;
}
if ( ! F_55 ( V_252 ,
L_23 , & V_26 ) ) {
if ( ( V_26 >= 1250 ) && ( V_26 <= 3000 ) )
V_10 -> V_241 = ( V_26 / 250 ) - 5 ;
else {
V_10 -> V_241 = 0 ;
F_18 ( & V_225 -> V_88 ,
L_24 ) ;
}
} else {
V_10 -> V_241 = 0 ;
}
}
F_42 ( V_225 ) ;
V_118 = F_56 ( & V_225 -> V_88 ,
& V_279 , & V_280 , 1 ) ;
if ( V_118 )
goto V_260;
return 0 ;
V_260:
F_57 ( V_10 -> V_258 ) ;
V_257:
F_58 ( V_10 -> V_199 , V_10 -> V_195 ) ;
F_39 ( V_10 -> V_199 , V_10 -> V_195 ) ;
return V_118 ;
}
static int F_59 ( struct V_224 * V_225 )
{
struct V_9 * V_10 = F_31 ( V_225 ) ;
F_60 ( & V_225 -> V_88 ) ;
F_57 ( V_10 -> V_258 ) ;
F_58 ( V_10 -> V_199 , V_10 -> V_195 ) ;
F_39 ( V_10 -> V_199 , V_10 -> V_195 ) ;
return 0 ;
}
