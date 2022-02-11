static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
F_2 ( V_2 -> V_7 , V_8 ,
V_9 ,
V_10 << V_11 ) ;
break;
case V_12 :
F_2 ( V_2 -> V_7 , V_8 ,
V_9 , 0 ) ;
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
const T_1 V_13 = V_14 | V_15 ;
switch ( V_5 ) {
case V_6 :
F_2 ( V_2 -> V_7 , V_16 ,
V_17 , V_17 ) ;
break;
case V_12 :
if ( ( F_4 ( V_2 -> V_7 , V_16 ) &
V_13 ) != V_13 ) {
F_2 ( V_2 -> V_7 , V_16 ,
V_17 , 0 ) ;
F_5 ( 400 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_18 * V_19 )
{
V_19 -> type = V_20 ;
V_19 -> V_21 = 2 ;
V_19 -> V_22 . integer . V_23 = 0 ;
V_19 -> V_22 . integer . V_24 = 0xfc - 0x3c ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_25 * V_26 )
{
struct V_27 * V_7 = F_8 ( V_4 ) ;
int V_28 ;
int V_29 ;
int V_30 ;
V_28 = F_4 ( V_7 , V_31 ) ;
V_29 = ( V_28 & V_32 ) >> V_33 ;
V_30 = ( V_28 & V_34 ) >> V_35 ;
V_29 = F_9 ( V_29 , 0x3c , 0xfc ) ;
V_30 = F_9 ( V_30 , 0x3c , 0xfc ) ;
V_29 = 0xfc - V_29 ;
V_30 = 0xfc - V_30 ;
V_26 -> V_22 . integer . V_22 [ 0 ] = V_29 ;
V_26 -> V_22 . integer . V_22 [ 1 ] = V_30 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_25 * V_26 )
{
struct V_27 * V_7 = F_8 ( V_4 ) ;
int V_28 ;
int V_29 ;
int V_30 ;
V_29 = V_26 -> V_22 . integer . V_22 [ 0 ] ;
V_30 = V_26 -> V_22 . integer . V_22 [ 1 ] ;
V_29 = F_9 ( V_29 , 0 , 0xfc - 0x3c ) ;
V_30 = F_9 ( V_30 , 0 , 0xfc - 0x3c ) ;
V_29 = 0xfc - V_29 ;
V_30 = 0xfc - V_30 ;
V_28 = V_29 << V_33 |
V_30 << V_35 ;
F_11 ( V_7 , V_31 , V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_36 * V_37 , int V_38 )
{
struct V_27 * V_7 = V_37 -> V_7 ;
T_2 V_39 = V_40 | V_41 ;
F_2 ( V_7 , V_42 ,
V_39 , V_38 ? V_39 : 0 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 , unsigned int V_43 )
{
struct V_27 * V_7 = V_37 -> V_7 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
T_2 V_46 = 0 ;
V_45 -> V_47 = 0 ;
switch ( V_43 & V_48 ) {
case V_49 :
break;
case V_50 :
V_46 |= V_51 ;
V_45 -> V_47 = 1 ;
break;
default:
return - V_52 ;
}
switch ( V_43 & V_53 ) {
case V_54 :
V_46 |= V_55 ;
break;
case V_56 :
V_46 |= V_55 ;
V_46 |= V_57 ;
break;
case V_58 :
V_46 |= V_59 ;
break;
case V_60 :
V_46 |= V_61 ;
V_46 |= V_62 ;
break;
case V_63 :
V_46 |= V_59 ;
V_46 |= V_57 ;
break;
default:
return - V_52 ;
}
V_45 -> V_43 = V_43 & V_53 ;
switch ( V_43 & V_64 ) {
case V_65 :
break;
case V_66 :
V_46 |= V_67 ;
break;
default:
return - V_52 ;
}
F_11 ( V_7 , V_68 , V_46 ) ;
return 0 ;
}
static int F_15 ( struct V_36 * V_37 ,
int V_69 , unsigned int V_70 , int V_71 )
{
struct V_27 * V_7 = V_37 -> V_7 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
switch ( V_69 ) {
case V_72 :
V_45 -> V_73 = V_70 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_16 ( struct V_27 * V_7 , int V_74 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
int V_75 = 0 ;
int V_76 ;
switch ( V_74 ) {
case 8000 :
case 16000 :
V_76 = 32000 ;
break;
case 11025 :
case 22050 :
V_76 = 44100 ;
break;
default:
V_76 = V_74 ;
break;
}
switch ( V_76 / V_74 ) {
case 4 :
V_75 |= V_77 << V_78 ;
break;
case 2 :
V_75 |= V_79 << V_78 ;
break;
case 1 :
V_75 |= V_80 << V_78 ;
break;
default:
return - V_52 ;
}
switch ( V_76 ) {
case 32000 :
V_75 |= V_81 << V_82 ;
break;
case 44100 :
V_75 |= V_83 << V_82 ;
break;
case 48000 :
V_75 |= V_84 << V_82 ;
break;
case 96000 :
V_75 |= V_85 << V_82 ;
break;
default:
F_17 ( V_7 -> V_86 , L_1 ,
V_74 ) ;
return - V_52 ;
}
switch ( V_45 -> V_73 / V_76 ) {
case 256 :
V_75 |= V_87 <<
V_88 ;
break;
case 384 :
V_75 |= V_89 <<
V_88 ;
break;
case 512 :
V_75 |= V_90 <<
V_88 ;
break;
default:
if ( V_45 -> V_47 ) {
V_75 |= V_91 <<
V_88 ;
} else {
F_17 ( V_7 -> V_86 ,
L_2 ) ;
F_17 ( V_7 -> V_86 , L_3
L_4 ,
V_45 -> V_73 / V_76 ) ;
return - V_52 ;
}
}
if ( ( V_75 & V_92 ) == V_91 ) {
T_3 V_93 , V_94 ;
int V_95 ;
int V_96 ;
unsigned int V_97 , V_98 , V_99 ;
if ( V_45 -> V_73 > 17000000 ) {
V_95 = 1 ;
V_97 = V_45 -> V_73 / 2 ;
} else {
V_95 = 0 ;
V_97 = V_45 -> V_73 ;
}
if ( V_76 == 44100 )
V_93 = 180633600 ;
else
V_93 = 196608000 ;
V_94 = F_18 ( V_93 , V_97 ) ;
V_98 = V_93 ;
V_94 *= 2048 ;
F_18 ( V_94 , V_97 ) ;
V_99 = V_94 ;
V_96 = V_98 << V_100 |
V_99 << V_101 ;
F_11 ( V_7 , V_102 , V_96 ) ;
if ( V_95 )
F_2 ( V_7 ,
V_103 ,
V_104 ,
V_104 ) ;
else
F_2 ( V_7 ,
V_103 ,
V_104 ,
0 ) ;
F_2 ( V_7 , V_16 ,
V_105 | V_106 ,
V_105 | V_106 ) ;
F_11 ( V_7 , V_107 , V_75 ) ;
} else {
F_11 ( V_7 , V_107 , V_75 ) ;
F_2 ( V_7 , V_16 ,
V_105 | V_106 ,
0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_108 * V_109 ,
struct V_110 * V_111 ,
struct V_36 * V_112 )
{
struct V_27 * V_7 = V_112 -> V_7 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
int V_113 = F_20 ( V_111 ) ;
int V_114 = 0 ;
int V_115 ;
int V_116 ;
if ( ! V_45 -> V_73 ) {
F_17 ( V_7 -> V_86 , L_5 , V_117 ) ;
return - V_118 ;
}
if ( V_109 -> V_119 == V_120 )
V_115 = V_121 ;
else
V_115 = V_122 ;
F_2 ( V_7 , V_16 , V_115 ,
V_113 == 1 ? 0 : V_115 ) ;
V_116 = F_16 ( V_7 , F_21 ( V_111 ) ) ;
if ( V_116 )
return V_116 ;
switch ( F_22 ( V_111 ) ) {
case 16 :
if ( V_45 -> V_43 == V_60 )
return - V_52 ;
V_114 |= V_123 << V_124 ;
V_114 |= V_125 <<
V_126 ;
break;
case 20 :
V_114 |= V_127 << V_124 ;
V_114 |= V_128 <<
V_126 ;
break;
case 24 :
V_114 |= V_129 << V_124 ;
V_114 |= V_128 <<
V_126 ;
break;
case 32 :
if ( V_45 -> V_43 == V_60 )
return - V_52 ;
V_114 |= V_130 << V_124 ;
V_114 |= V_128 <<
V_126 ;
break;
default:
return - V_52 ;
}
F_2 ( V_7 , V_68 ,
V_131 | V_132 ,
V_114 ) ;
return 0 ;
}
static int F_23 ( struct V_133 * V_86 )
{
struct V_134 * V_135 = F_24 ( V_86 ) ;
return V_135 -> V_136 ;
}
static int F_25 ( struct V_133 * V_86 )
{
struct V_134 * V_135 = F_24 ( V_86 ) ;
struct V_27 * V_7 = (struct V_27 * ) V_135 -> V_137 ;
int V_28 ;
if ( F_23 ( V_86 ) )
return 0 ;
V_28 = ( 1600 - V_135 -> V_138 / 1000 ) / 50 ;
V_28 = F_9 ( V_28 , 0x0 , 0xf ) ;
V_135 -> V_138 = ( 1600 - V_28 * 50 ) * 1000 ;
F_2 ( V_7 , V_139 ,
V_140 , V_28 ) ;
F_2 ( V_7 , V_16 ,
V_141 ,
V_141 ) ;
F_2 ( V_7 , V_16 ,
V_142 ,
0 ) ;
V_135 -> V_136 = 1 ;
return 0 ;
}
static int F_26 ( struct V_133 * V_86 )
{
struct V_134 * V_135 = F_24 ( V_86 ) ;
struct V_27 * V_7 = (struct V_27 * ) V_135 -> V_137 ;
F_2 ( V_7 , V_16 ,
V_141 ,
0 ) ;
F_2 ( V_7 , V_139 ,
V_140 , 0 ) ;
V_135 -> V_136 = 0 ;
return 0 ;
}
static int F_27 ( struct V_133 * V_86 )
{
struct V_134 * V_135 = F_24 ( V_86 ) ;
return V_135 -> V_138 ;
}
static int F_28 ( struct V_27 * V_7 ,
struct V_143 * V_144 ,
int V_138 )
{
struct V_134 * V_135 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
struct V_145 V_146 = { } ;
V_135 = F_29 ( sizeof( struct V_134 ) , V_147 ) ;
if ( ! V_135 )
return - V_148 ;
V_135 -> V_149 . V_150 = F_30 ( F_31 ( V_7 -> V_86 ) , V_147 ) ;
if ( ! V_135 -> V_149 . V_150 ) {
F_32 ( V_135 ) ;
F_17 ( V_7 -> V_86 , L_6 ) ;
return - V_148 ;
}
V_135 -> V_149 . type = V_151 ;
V_135 -> V_149 . V_152 = V_153 ;
V_135 -> V_149 . V_154 = & V_155 ;
V_135 -> V_149 . V_156 = 1 ;
V_135 -> V_137 = V_7 ;
V_135 -> V_138 = V_138 ;
V_146 . V_86 = V_7 -> V_86 ;
V_146 . V_157 = V_135 ;
V_146 . V_144 = V_144 ;
V_135 -> V_86 = F_33 ( & V_135 -> V_149 , & V_146 ) ;
if ( F_34 ( V_135 -> V_86 ) ) {
int V_116 = F_35 ( V_135 -> V_86 ) ;
F_17 ( V_7 -> V_86 , L_7 ) ;
F_32 ( V_135 -> V_149 . V_150 ) ;
F_32 ( V_135 ) ;
return V_116 ;
}
V_45 -> V_135 = V_135 ;
return 0 ;
}
static int F_36 ( struct V_27 * V_7 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
struct V_134 * V_135 = V_45 -> V_135 ;
if ( ! V_135 )
return 0 ;
F_37 ( V_135 -> V_86 ) ;
F_32 ( V_135 -> V_149 . V_150 ) ;
F_32 ( V_135 ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_7 ,
struct V_143 * V_144 ,
int V_138 )
{
F_17 ( V_7 -> V_86 , L_8 ) ;
return - V_52 ;
}
static int F_36 ( struct V_27 * V_7 )
{
return 0 ;
}
static int F_38 ( struct V_27 * V_7 ,
enum V_158 V_159 )
{
int V_116 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
switch ( V_159 ) {
case V_160 :
case V_161 :
break;
case V_162 :
if ( V_7 -> V_163 . V_164 == V_165 ) {
V_116 = F_39 (
F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
if ( V_116 )
return V_116 ;
F_41 ( 10 ) ;
F_42 ( V_45 -> V_167 , false ) ;
V_116 = F_43 ( V_45 -> V_167 ) ;
if ( V_116 != 0 ) {
F_17 ( V_7 -> V_86 ,
L_9 , V_116 ) ;
F_42 ( V_45 -> V_167 , true ) ;
F_44 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
return V_116 ;
}
}
break;
case V_165 :
F_42 ( V_45 -> V_167 , true ) ;
F_44 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
break;
}
V_7 -> V_163 . V_164 = V_159 ;
return 0 ;
}
static bool F_45 ( struct V_168 * V_86 , unsigned int V_28 )
{
switch ( V_28 ) {
case V_169 :
case V_42 :
case V_170 :
return true ;
}
return false ;
}
static bool F_46 ( struct V_168 * V_86 , unsigned int V_28 )
{
switch ( V_28 ) {
case V_169 :
case V_171 :
case V_107 :
case V_68 :
case V_172 :
case V_42 :
case V_31 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_139 :
case V_177 :
case V_8 :
case V_178 :
case V_179 :
case V_16 :
case V_102 :
case V_103 :
case V_170 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
return true ;
default:
return false ;
}
}
static int F_47 ( struct V_27 * V_7 )
{
int V_210 ;
int V_211 ;
int V_212 ;
T_2 V_213 ;
T_2 V_214 ;
int V_215 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
V_211 = F_48 ( V_45 -> V_166 [ V_216 ] . V_217 ) ;
V_212 = F_48 ( V_45 -> V_166 [ V_218 ] . V_217 ) ;
V_210 = F_48 ( V_45 -> V_166 [ V_219 ] . V_217 ) ;
V_211 = V_211 / 1000 ;
V_212 = V_212 / 1000 ;
V_210 = V_210 / 1000 ;
if ( V_211 <= 0 || V_212 <= 0 || V_210 < 0 ) {
F_17 ( V_7 -> V_86 , L_10 ) ;
return - V_52 ;
}
if ( V_211 > 3600 || V_212 > 3600 || V_210 > 1980 ) {
F_17 ( V_7 -> V_86 ,
L_11 ,
V_211 , V_212 , V_210 ) ;
return - V_52 ;
}
V_213 = F_4 ( V_7 , V_16 ) ;
V_213 |= V_121 |
V_122 |
V_220 ;
V_214 = F_4 ( V_7 , V_139 ) ;
if ( V_212 < 3100 && V_211 < 3100 ) {
F_2 ( V_7 , V_103 ,
V_221 ,
V_221 ) ;
V_213 |= V_222 ;
} else if ( V_212 >= 3100 && V_211 >= 3100 ) {
F_2 ( V_7 , V_16 ,
V_222 , 0 ) ;
V_214 |= V_223 ;
V_214 |= V_224 <<
V_225 ;
}
F_11 ( V_7 , V_139 , V_214 ) ;
F_11 ( V_7 , V_16 , V_213 ) ;
F_2 ( V_7 , V_139 ,
V_140 , 0x8 ) ;
if ( V_213 & V_141 )
F_2 ( V_7 , V_16 ,
V_142 ,
0 ) ;
else
F_2 ( V_7 , V_16 ,
V_142 |
V_226 ,
0 ) ;
V_215 = V_211 / 2 ;
if ( V_215 <= V_227 )
V_215 = 0 ;
else if ( V_215 >= V_227 + V_228 *
( V_229 >> V_230 ) )
V_215 = V_229 >> V_230 ;
else
V_215 = ( V_215 - V_227 ) / V_228 ;
F_2 ( V_7 , V_177 ,
V_229 , V_215 << V_230 ) ;
V_215 = V_212 / 2 ;
if ( V_215 <= V_231 )
V_215 = 0 ;
else if ( V_215 >= V_231 +
V_232 * V_233 )
V_215 = V_233 ;
else
V_215 = ( V_215 - V_231 ) /
V_232 ;
F_2 ( V_7 , V_178 ,
V_234 |
V_235 ,
V_215 << V_236 |
V_237 <<
V_238 ) ;
return 0 ;
}
static int F_49 ( struct V_27 * V_7 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
int V_116 ;
V_116 = F_28 ( V_7 , & V_239 , V_240 ) ;
if ( V_116 ) {
F_17 ( V_7 -> V_86 ,
L_12 , V_116 ) ;
return V_116 ;
}
V_45 -> V_166 [ V_219 ] . V_241 = V_242 ;
F_50 ( V_7 -> V_86 , L_13 ) ;
return 0 ;
}
static int F_51 ( struct V_27 * V_7 )
{
int V_116 ;
int V_243 ;
int V_244 = 0 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
struct V_245 * V_210 ;
for ( V_243 = 0 ; V_243 < F_40 ( V_45 -> V_166 ) ; V_243 ++ )
V_45 -> V_166 [ V_243 ] . V_241 = V_246 [ V_243 ] ;
if ( V_45 -> V_247 < 0x11 ) {
V_210 = F_52 ( V_7 -> V_86 , L_14 ) ;
if ( F_34 ( V_210 ) ) {
if ( F_35 ( V_210 ) == - V_248 )
return - V_248 ;
} else {
V_244 = 1 ;
F_53 ( V_210 ) ;
}
}
if ( ! V_244 ) {
V_116 = F_49 ( V_7 ) ;
if ( V_116 )
return V_116 ;
}
V_116 = F_54 ( V_7 -> V_86 , F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
if ( V_116 )
goto V_249;
V_116 = F_39 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
if ( V_116 )
goto V_250;
F_41 ( 10 ) ;
return 0 ;
V_250:
F_55 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
V_249:
if ( ! V_244 )
F_36 ( V_7 ) ;
return V_116 ;
}
static int F_56 ( struct V_27 * V_7 )
{
int V_116 ;
struct V_44 * V_45 = F_14 ( V_7 ) ;
V_116 = F_51 ( V_7 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_47 ( V_7 ) ;
if ( V_116 )
goto V_251;
F_2 ( V_7 , V_177 ,
V_252 , 1 ) ;
F_11 ( V_7 , V_180 , 0 ) ;
F_11 ( V_7 , V_172 ,
V_253 << V_254 ) ;
F_11 ( V_7 , V_171 ,
V_255 | V_256 ) ;
F_11 ( V_7 , V_42 ,
V_257 |
V_41 |
V_40 ) ;
F_11 ( V_7 , V_173 , 0x015f ) ;
F_11 ( V_7 , V_176 ,
V_258 |
V_259 ) ;
F_11 ( V_7 , V_8 , 2 ) ;
F_11 ( V_7 , V_182 , 0 ) ;
return 0 ;
V_251:
F_44 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
F_55 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
F_36 ( V_7 ) ;
return V_116 ;
}
static int F_57 ( struct V_27 * V_7 )
{
struct V_44 * V_45 = F_14 ( V_7 ) ;
F_44 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
F_55 ( F_40 ( V_45 -> V_166 ) ,
V_45 -> V_166 ) ;
F_36 ( V_7 ) ;
return 0 ;
}
static int F_58 ( struct V_44 * V_45 )
{
int V_243 , V_116 , V_260 , V_261 ;
for ( V_243 = 0 ; V_243 < F_40 ( V_262 ) ; V_243 ++ ) {
V_260 = V_262 [ V_243 ] . V_263 ;
V_261 = V_262 [ V_243 ] . V_28 ;
V_116 = F_59 ( V_45 -> V_167 , V_261 , V_260 ) ;
if ( V_116 )
return V_116 ;
}
return 0 ;
}
static int F_60 ( struct V_264 * V_265 ,
const struct V_266 * V_267 )
{
struct V_44 * V_45 ;
int V_116 , V_28 , V_268 ;
unsigned int V_269 ;
V_45 = F_61 ( & V_265 -> V_86 , sizeof( struct V_44 ) ,
V_147 ) ;
if ( ! V_45 )
return - V_148 ;
V_45 -> V_167 = F_62 ( V_265 , & V_270 ) ;
if ( F_34 ( V_45 -> V_167 ) ) {
V_116 = F_35 ( V_45 -> V_167 ) ;
F_17 ( & V_265 -> V_86 , L_15 , V_116 ) ;
return V_116 ;
}
V_45 -> V_269 = F_63 ( & V_265 -> V_86 , NULL ) ;
if ( F_34 ( V_45 -> V_269 ) ) {
V_116 = F_35 ( V_45 -> V_269 ) ;
F_17 ( & V_265 -> V_86 , L_16 , V_116 ) ;
if ( V_116 == - V_271 )
return - V_248 ;
return V_116 ;
}
V_269 = F_64 ( V_45 -> V_269 ) ;
if ( V_269 < 8000000 || V_269 > 27000000 ) {
F_17 ( & V_265 -> V_86 , L_17 ,
V_269 / 1000000 , V_269 / 1000 % 1000 ) ;
return - V_52 ;
}
V_116 = F_65 ( V_45 -> V_269 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_66 ( V_45 -> V_167 , V_169 , & V_28 ) ;
if ( V_116 )
goto V_272;
if ( ( ( V_28 & V_273 ) >> V_274 ) !=
V_275 ) {
F_17 ( & V_265 -> V_86 ,
L_18 , V_28 ) ;
V_116 = - V_276 ;
goto V_272;
}
V_268 = ( V_28 & V_277 ) >> V_278 ;
F_50 ( & V_265 -> V_86 , L_19 , V_268 ) ;
V_45 -> V_247 = V_268 ;
F_67 ( V_265 , V_45 ) ;
V_116 = F_58 ( V_45 ) ;
if ( V_116 )
goto V_272;
V_116 = F_68 ( & V_265 -> V_86 ,
& V_279 , & V_280 , 1 ) ;
if ( V_116 )
goto V_272;
return 0 ;
V_272:
F_69 ( V_45 -> V_269 ) ;
return V_116 ;
}
static int F_70 ( struct V_264 * V_265 )
{
struct V_44 * V_45 = F_71 ( V_265 ) ;
F_72 ( & V_265 -> V_86 ) ;
F_69 ( V_45 -> V_269 ) ;
return 0 ;
}
