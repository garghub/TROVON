static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
switch ( V_5 ) {
case V_9 :
F_3 ( V_2 -> V_8 , V_10 ,
V_11 ,
V_7 -> V_12 << V_13 ) ;
break;
case V_14 :
F_3 ( V_2 -> V_8 , V_10 ,
V_11 , 0 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
const T_1 V_15 = V_16 | V_17 ;
switch ( V_5 ) {
case V_9 :
F_3 ( V_2 -> V_8 , V_18 ,
V_19 , V_19 ) ;
break;
case V_14 :
if ( ( F_5 ( V_2 -> V_8 , V_18 ) &
V_15 ) != V_15 ) {
F_3 ( V_2 -> V_8 , V_18 ,
V_19 , 0 ) ;
F_6 ( 400 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
V_21 -> type = V_22 ;
V_21 -> V_23 = 2 ;
V_21 -> V_24 . integer . V_25 = 0 ;
V_21 -> V_24 . integer . V_26 = 0xfc - 0x3c ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_27 * V_28 )
{
struct V_29 * V_8 = F_9 ( V_4 ) ;
int V_30 ;
int V_31 ;
int V_32 ;
V_30 = F_5 ( V_8 , V_33 ) ;
V_31 = ( V_30 & V_34 ) >> V_35 ;
V_32 = ( V_30 & V_36 ) >> V_37 ;
V_31 = F_10 ( V_31 , 0x3c , 0xfc ) ;
V_32 = F_10 ( V_32 , 0x3c , 0xfc ) ;
V_31 = 0xfc - V_31 ;
V_32 = 0xfc - V_32 ;
V_28 -> V_24 . integer . V_24 [ 0 ] = V_31 ;
V_28 -> V_24 . integer . V_24 [ 1 ] = V_32 ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_27 * V_28 )
{
struct V_29 * V_8 = F_9 ( V_4 ) ;
int V_30 ;
int V_31 ;
int V_32 ;
V_31 = V_28 -> V_24 . integer . V_24 [ 0 ] ;
V_32 = V_28 -> V_24 . integer . V_24 [ 1 ] ;
V_31 = F_10 ( V_31 , 0 , 0xfc - 0x3c ) ;
V_32 = F_10 ( V_32 , 0 , 0xfc - 0x3c ) ;
V_31 = 0xfc - V_31 ;
V_32 = 0xfc - V_32 ;
V_30 = V_31 << V_35 |
V_32 << V_37 ;
F_12 ( V_8 , V_33 , V_30 ) ;
return 0 ;
}
static int F_13 ( struct V_38 * V_39 , int V_40 )
{
struct V_29 * V_8 = V_39 -> V_8 ;
T_2 V_41 = V_42 | V_43 ;
F_3 ( V_8 , V_44 ,
V_41 , V_40 ? V_41 : 0 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 , unsigned int V_45 )
{
struct V_29 * V_8 = V_39 -> V_8 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
T_2 V_46 = 0 ;
V_7 -> V_47 = 0 ;
switch ( V_45 & V_48 ) {
case V_49 :
break;
case V_50 :
V_46 |= V_51 ;
V_7 -> V_47 = 1 ;
break;
default:
return - V_52 ;
}
switch ( V_45 & V_53 ) {
case V_54 :
V_46 |= V_55 << V_56 ;
break;
case V_57 :
V_46 |= V_55 << V_56 ;
V_46 |= V_58 ;
break;
case V_59 :
V_46 |= V_60 << V_56 ;
break;
case V_61 :
V_46 |= V_62 << V_56 ;
V_46 |= V_63 ;
break;
case V_64 :
V_46 |= V_60 << V_56 ;
V_46 |= V_58 ;
break;
default:
return - V_52 ;
}
V_7 -> V_45 = V_45 & V_53 ;
switch ( V_45 & V_65 ) {
case V_66 :
break;
case V_67 :
V_46 |= V_68 ;
break;
default:
return - V_52 ;
}
F_12 ( V_8 , V_69 , V_46 ) ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 ,
int V_70 , unsigned int V_71 , int V_72 )
{
struct V_29 * V_8 = V_39 -> V_8 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
switch ( V_70 ) {
case V_73 :
V_7 -> V_74 = V_71 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_16 ( struct V_29 * V_8 , int V_75 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_76 = 0 ;
int V_77 ;
switch ( V_75 ) {
case 8000 :
case 16000 :
V_77 = 32000 ;
break;
case 11025 :
case 22050 :
V_77 = 44100 ;
break;
default:
V_77 = V_75 ;
break;
}
switch ( V_77 / V_75 ) {
case 4 :
V_76 |= V_78 << V_79 ;
break;
case 2 :
V_76 |= V_80 << V_79 ;
break;
case 1 :
V_76 |= V_81 << V_79 ;
break;
default:
return - V_52 ;
}
switch ( V_77 ) {
case 32000 :
V_76 |= V_82 << V_83 ;
break;
case 44100 :
V_76 |= V_84 << V_83 ;
break;
case 48000 :
V_76 |= V_85 << V_83 ;
break;
case 96000 :
V_76 |= V_86 << V_83 ;
break;
default:
F_17 ( V_8 -> V_87 , L_1 ,
V_75 ) ;
return - V_52 ;
}
switch ( V_7 -> V_74 / V_75 ) {
case 256 :
V_76 |= V_88 <<
V_89 ;
break;
case 384 :
V_76 |= V_90 <<
V_89 ;
break;
case 512 :
V_76 |= V_91 <<
V_89 ;
break;
default:
if ( V_7 -> V_47 ) {
V_76 |= V_92 <<
V_89 ;
} else {
F_17 ( V_8 -> V_87 ,
L_2 ) ;
F_17 ( V_8 -> V_87 , L_3
L_4 ,
V_7 -> V_74 / V_75 ) ;
return - V_52 ;
}
}
if ( ( V_76 & V_93 ) == V_92 ) {
T_3 V_94 , V_95 ;
int V_96 ;
int V_97 ;
unsigned int V_98 , V_99 , V_100 ;
if ( V_7 -> V_74 > 17000000 ) {
V_96 = 1 ;
V_98 = V_7 -> V_74 / 2 ;
} else {
V_96 = 0 ;
V_98 = V_7 -> V_74 ;
}
if ( V_77 == 44100 )
V_94 = 180633600 ;
else
V_94 = 196608000 ;
V_95 = F_18 ( V_94 , V_98 ) ;
V_99 = V_94 ;
V_95 *= 2048 ;
F_18 ( V_95 , V_98 ) ;
V_100 = V_95 ;
V_97 = V_99 << V_101 |
V_100 << V_102 ;
F_12 ( V_8 , V_103 , V_97 ) ;
if ( V_96 )
F_3 ( V_8 ,
V_104 ,
V_105 ,
V_105 ) ;
else
F_3 ( V_8 ,
V_104 ,
V_105 ,
0 ) ;
F_3 ( V_8 , V_18 ,
V_106 | V_107 ,
V_106 | V_107 ) ;
F_12 ( V_8 , V_108 , V_76 ) ;
} else {
F_12 ( V_8 , V_108 , V_76 ) ;
F_3 ( V_8 , V_18 ,
V_106 | V_107 ,
0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_109 * V_110 ,
struct V_111 * V_112 ,
struct V_38 * V_113 )
{
struct V_29 * V_8 = V_113 -> V_8 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_114 = F_20 ( V_112 ) ;
int V_115 = 0 ;
int V_116 ;
int V_117 ;
if ( ! V_7 -> V_74 ) {
F_17 ( V_8 -> V_87 , L_5 , V_118 ) ;
return - V_119 ;
}
if ( V_110 -> V_120 == V_121 )
V_116 = V_122 ;
else
V_116 = V_123 ;
F_3 ( V_8 , V_18 , V_116 ,
V_114 == 1 ? 0 : V_116 ) ;
V_117 = F_16 ( V_8 , F_21 ( V_112 ) ) ;
if ( V_117 )
return V_117 ;
switch ( F_22 ( V_112 ) ) {
case 16 :
if ( V_7 -> V_45 == V_61 )
return - V_52 ;
V_115 |= V_124 << V_125 ;
V_115 |= V_126 <<
V_127 ;
break;
case 20 :
V_115 |= V_128 << V_125 ;
V_115 |= V_129 <<
V_127 ;
break;
case 24 :
V_115 |= V_130 << V_125 ;
V_115 |= V_129 <<
V_127 ;
break;
case 32 :
if ( V_7 -> V_45 == V_61 )
return - V_52 ;
V_115 |= V_131 << V_125 ;
V_115 |= V_129 <<
V_127 ;
break;
default:
return - V_52 ;
}
F_3 ( V_8 , V_69 ,
V_132 | V_133 ,
V_115 ) ;
return 0 ;
}
static int F_23 ( struct V_134 * V_87 )
{
struct V_135 * V_136 = F_24 ( V_87 ) ;
return V_136 -> V_137 ;
}
static int F_25 ( struct V_134 * V_87 )
{
struct V_135 * V_136 = F_24 ( V_87 ) ;
struct V_29 * V_8 = (struct V_29 * ) V_136 -> V_138 ;
int V_30 ;
if ( F_23 ( V_87 ) )
return 0 ;
V_30 = ( 1600 - V_136 -> V_139 / 1000 ) / 50 ;
V_30 = F_10 ( V_30 , 0x0 , 0xf ) ;
V_136 -> V_139 = ( 1600 - V_30 * 50 ) * 1000 ;
F_3 ( V_8 , V_140 ,
V_141 , V_30 ) ;
F_3 ( V_8 , V_18 ,
V_142 ,
V_142 ) ;
F_3 ( V_8 , V_18 ,
V_143 ,
0 ) ;
V_136 -> V_137 = 1 ;
return 0 ;
}
static int F_26 ( struct V_134 * V_87 )
{
struct V_135 * V_136 = F_24 ( V_87 ) ;
struct V_29 * V_8 = (struct V_29 * ) V_136 -> V_138 ;
F_3 ( V_8 , V_18 ,
V_142 ,
0 ) ;
F_3 ( V_8 , V_140 ,
V_141 , 0 ) ;
V_136 -> V_137 = 0 ;
return 0 ;
}
static int F_27 ( struct V_134 * V_87 )
{
struct V_135 * V_136 = F_24 ( V_87 ) ;
return V_136 -> V_139 ;
}
static int F_28 ( struct V_29 * V_8 ,
struct V_144 * V_145 ,
int V_139 )
{
struct V_135 * V_136 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
struct V_146 V_147 = { } ;
V_136 = F_29 ( sizeof( struct V_135 ) , V_148 ) ;
if ( ! V_136 )
return - V_149 ;
V_136 -> V_150 . V_151 = F_30 ( F_31 ( V_8 -> V_87 ) , V_148 ) ;
if ( ! V_136 -> V_150 . V_151 ) {
F_32 ( V_136 ) ;
F_17 ( V_8 -> V_87 , L_6 ) ;
return - V_149 ;
}
V_136 -> V_150 . type = V_152 ;
V_136 -> V_150 . V_153 = V_154 ;
V_136 -> V_150 . V_155 = & V_156 ;
V_136 -> V_150 . V_157 = 1 ;
V_136 -> V_138 = V_8 ;
V_136 -> V_139 = V_139 ;
V_147 . V_87 = V_8 -> V_87 ;
V_147 . V_158 = V_136 ;
V_147 . V_145 = V_145 ;
V_136 -> V_87 = F_33 ( & V_136 -> V_150 , & V_147 ) ;
if ( F_34 ( V_136 -> V_87 ) ) {
int V_117 = F_35 ( V_136 -> V_87 ) ;
F_17 ( V_8 -> V_87 , L_7 ) ;
F_32 ( V_136 -> V_150 . V_151 ) ;
F_32 ( V_136 ) ;
return V_117 ;
}
V_7 -> V_136 = V_136 ;
return 0 ;
}
static int F_36 ( struct V_29 * V_8 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
struct V_135 * V_136 = V_7 -> V_136 ;
if ( ! V_136 )
return 0 ;
F_37 ( V_136 -> V_87 ) ;
F_32 ( V_136 -> V_150 . V_151 ) ;
F_32 ( V_136 ) ;
return 0 ;
}
static int F_28 ( struct V_29 * V_8 ,
struct V_144 * V_145 ,
int V_139 )
{
F_17 ( V_8 -> V_87 , L_8 ) ;
return - V_52 ;
}
static int F_36 ( struct V_29 * V_8 )
{
return 0 ;
}
static int F_38 ( struct V_29 * V_8 ,
enum V_159 V_160 )
{
int V_117 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
switch ( V_160 ) {
case V_161 :
case V_162 :
break;
case V_163 :
if ( V_8 -> V_164 . V_165 == V_166 ) {
V_117 = F_39 (
F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
if ( V_117 )
return V_117 ;
F_41 ( 10 ) ;
F_42 ( V_7 -> V_168 , false ) ;
V_117 = F_43 ( V_7 -> V_168 ) ;
if ( V_117 != 0 ) {
F_17 ( V_8 -> V_87 ,
L_9 , V_117 ) ;
F_42 ( V_7 -> V_168 , true ) ;
F_44 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
return V_117 ;
}
}
break;
case V_166 :
F_42 ( V_7 -> V_168 , true ) ;
F_44 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
break;
}
V_8 -> V_164 . V_165 = V_160 ;
return 0 ;
}
static bool F_45 ( struct V_169 * V_87 , unsigned int V_30 )
{
switch ( V_30 ) {
case V_170 :
case V_44 :
case V_171 :
return true ;
}
return false ;
}
static bool F_46 ( struct V_169 * V_87 , unsigned int V_30 )
{
switch ( V_30 ) {
case V_170 :
case V_172 :
case V_108 :
case V_69 :
case V_173 :
case V_44 :
case V_33 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_140 :
case V_178 :
case V_10 :
case V_179 :
case V_180 :
case V_18 :
case V_103 :
case V_104 :
case V_171 :
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
case V_210 :
return true ;
default:
return false ;
}
}
static int F_47 ( struct V_29 * V_8 )
{
int V_211 ;
int V_212 ;
int V_213 ;
T_2 V_214 ;
T_2 V_215 ;
int V_216 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
V_212 = F_48 ( V_7 -> V_167 [ V_217 ] . V_218 ) ;
V_213 = F_48 ( V_7 -> V_167 [ V_219 ] . V_218 ) ;
V_211 = F_48 ( V_7 -> V_167 [ V_220 ] . V_218 ) ;
V_212 = V_212 / 1000 ;
V_213 = V_213 / 1000 ;
V_211 = V_211 / 1000 ;
if ( V_212 <= 0 || V_213 <= 0 || V_211 < 0 ) {
F_17 ( V_8 -> V_87 , L_10 ) ;
return - V_52 ;
}
if ( V_212 > 3600 || V_213 > 3600 || V_211 > 1980 ) {
F_17 ( V_8 -> V_87 ,
L_11 ,
V_212 , V_213 , V_211 ) ;
return - V_52 ;
}
V_214 = F_5 ( V_8 , V_18 ) ;
V_214 |= V_122 |
V_123 |
V_221 ;
V_215 = F_5 ( V_8 , V_140 ) ;
if ( V_213 < 3100 && V_212 < 3100 ) {
F_3 ( V_8 , V_104 ,
V_222 ,
V_222 ) ;
V_214 |= V_223 ;
} else if ( V_213 >= 3100 && V_212 >= 3100 ) {
F_3 ( V_8 , V_18 ,
V_223 , 0 ) ;
V_215 |= V_224 ;
V_215 |= V_225 <<
V_226 ;
}
F_12 ( V_8 , V_140 , V_215 ) ;
F_12 ( V_8 , V_18 , V_214 ) ;
F_3 ( V_8 , V_140 ,
V_141 , 0x8 ) ;
if ( V_214 & V_142 )
F_3 ( V_8 , V_18 ,
V_143 ,
0 ) ;
else
F_3 ( V_8 , V_18 ,
V_143 |
V_227 ,
0 ) ;
V_216 = V_212 / 2 ;
if ( V_216 <= V_228 )
V_216 = 0 ;
else if ( V_216 >= V_228 + V_229 *
( V_230 >> V_231 ) )
V_216 = V_230 >> V_231 ;
else
V_216 = ( V_216 - V_228 ) / V_229 ;
F_3 ( V_8 , V_178 ,
V_230 , V_216 << V_231 ) ;
V_216 = V_213 / 2 ;
if ( V_216 <= V_232 )
V_216 = 0 ;
else if ( V_216 >= V_232 +
V_233 * V_234 )
V_216 = V_234 ;
else
V_216 = ( V_216 - V_232 ) /
V_233 ;
F_3 ( V_8 , V_179 ,
V_235 |
V_236 ,
V_216 << V_237 |
V_238 <<
V_239 ) ;
return 0 ;
}
static int F_49 ( struct V_29 * V_8 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_117 ;
V_117 = F_28 ( V_8 , & V_240 , V_241 ) ;
if ( V_117 ) {
F_17 ( V_8 -> V_87 ,
L_12 , V_117 ) ;
return V_117 ;
}
V_7 -> V_167 [ V_220 ] . V_242 = V_243 ;
F_50 ( V_8 -> V_87 , L_13 ) ;
return 0 ;
}
static int F_51 ( struct V_29 * V_8 )
{
int V_117 ;
int V_244 ;
int V_245 = 0 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
struct V_246 * V_211 ;
for ( V_244 = 0 ; V_244 < F_40 ( V_7 -> V_167 ) ; V_244 ++ )
V_7 -> V_167 [ V_244 ] . V_242 = V_247 [ V_244 ] ;
if ( V_7 -> V_248 < 0x11 ) {
V_211 = F_52 ( V_8 -> V_87 , L_14 ) ;
if ( F_34 ( V_211 ) ) {
if ( F_35 ( V_211 ) == - V_249 )
return - V_249 ;
} else {
V_245 = 1 ;
F_53 ( V_211 ) ;
}
}
if ( ! V_245 ) {
V_117 = F_49 ( V_8 ) ;
if ( V_117 )
return V_117 ;
}
V_117 = F_54 ( V_8 -> V_87 , F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
if ( V_117 )
goto V_250;
V_117 = F_39 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
if ( V_117 )
goto V_251;
F_41 ( 10 ) ;
return 0 ;
V_251:
F_55 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
V_250:
if ( ! V_245 )
F_36 ( V_8 ) ;
return V_117 ;
}
static int F_56 ( struct V_29 * V_8 )
{
int V_117 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
V_117 = F_51 ( V_8 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_47 ( V_8 ) ;
if ( V_117 )
goto V_252;
F_3 ( V_8 , V_178 ,
V_253 , 1 ) ;
F_12 ( V_8 , V_181 , 0 ) ;
F_12 ( V_8 , V_173 ,
V_254 << V_255 ) ;
F_12 ( V_8 , V_172 ,
V_256 | V_257 ) ;
F_12 ( V_8 , V_44 ,
V_258 |
V_43 |
V_42 ) ;
F_12 ( V_8 , V_174 , 0x015f ) ;
F_12 ( V_8 , V_177 ,
V_259 |
V_260 ) ;
F_3 ( V_8 , V_10 ,
V_11 ,
V_7 -> V_12 << V_13 ) ;
F_3 ( V_8 , V_10 ,
V_11 ,
V_7 -> V_261 << V_13 ) ;
F_12 ( V_8 , V_183 , 0 ) ;
return 0 ;
V_252:
F_44 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
F_55 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
F_36 ( V_8 ) ;
return V_117 ;
}
static int F_57 ( struct V_29 * V_8 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
F_44 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
F_55 ( F_40 ( V_7 -> V_167 ) ,
V_7 -> V_167 ) ;
F_36 ( V_8 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 )
{
int V_244 , V_117 , V_262 , V_263 ;
for ( V_244 = 0 ; V_244 < F_40 ( V_264 ) ; V_244 ++ ) {
V_262 = V_264 [ V_244 ] . V_265 ;
V_263 = V_264 [ V_244 ] . V_30 ;
V_117 = F_59 ( V_7 -> V_168 , V_263 , V_262 ) ;
if ( V_117 )
return V_117 ;
}
return 0 ;
}
static int F_60 ( struct V_266 * V_267 ,
const struct V_268 * V_269 )
{
struct V_6 * V_7 ;
int V_117 , V_30 , V_270 ;
struct V_271 * V_272 = V_267 -> V_87 . V_273 ;
T_1 V_24 ;
V_7 = F_61 ( & V_267 -> V_87 , sizeof( * V_7 ) , V_148 ) ;
if ( ! V_7 )
return - V_149 ;
V_7 -> V_168 = F_62 ( V_267 , & V_274 ) ;
if ( F_34 ( V_7 -> V_168 ) ) {
V_117 = F_35 ( V_7 -> V_168 ) ;
F_17 ( & V_267 -> V_87 , L_15 , V_117 ) ;
return V_117 ;
}
V_7 -> V_275 = F_63 ( & V_267 -> V_87 , NULL ) ;
if ( F_34 ( V_7 -> V_275 ) ) {
V_117 = F_35 ( V_7 -> V_275 ) ;
F_17 ( & V_267 -> V_87 , L_16 , V_117 ) ;
if ( V_117 == - V_276 )
return - V_249 ;
return V_117 ;
}
V_117 = F_64 ( V_7 -> V_275 ) ;
if ( V_117 )
return V_117 ;
F_41 ( 1 ) ;
V_117 = F_65 ( V_7 -> V_168 , V_170 , & V_30 ) ;
if ( V_117 )
goto V_277;
if ( ( ( V_30 & V_278 ) >> V_279 ) !=
V_280 ) {
F_17 ( & V_267 -> V_87 ,
L_17 , V_30 ) ;
V_117 = - V_281 ;
goto V_277;
}
V_270 = ( V_30 & V_282 ) >> V_283 ;
F_50 ( & V_267 -> V_87 , L_18 , V_270 ) ;
V_7 -> V_248 = V_270 ;
if ( V_272 ) {
if ( ! F_66 ( V_272 ,
L_19 , & V_24 ) ) {
switch ( V_24 ) {
case V_284 :
V_7 -> V_12 = 0 ;
break;
case V_285 :
V_7 -> V_12 = 1 ;
break;
case V_286 :
V_7 -> V_12 = 2 ;
break;
case V_287 :
V_7 -> V_12 = 3 ;
break;
default:
V_7 -> V_12 = 2 ;
F_17 ( & V_267 -> V_87 ,
L_20 ) ;
}
} else {
V_7 -> V_12 = 2 ;
}
if ( ! F_66 ( V_272 ,
L_21 , & V_24 ) ) {
if ( ( V_24 >= 1250 ) && ( V_24 <= 3000 ) )
V_7 -> V_261 = ( V_24 / 250 ) - 5 ;
else {
V_7 -> V_261 = 0 ;
F_17 ( & V_267 -> V_87 ,
L_20 ) ;
}
} else {
V_7 -> V_261 = 0 ;
}
}
F_67 ( V_267 , V_7 ) ;
V_117 = F_58 ( V_7 ) ;
if ( V_117 )
goto V_277;
V_117 = F_68 ( & V_267 -> V_87 ,
& V_288 , & V_289 , 1 ) ;
if ( V_117 )
goto V_277;
return 0 ;
V_277:
F_69 ( V_7 -> V_275 ) ;
return V_117 ;
}
static int F_70 ( struct V_266 * V_267 )
{
struct V_6 * V_7 = F_71 ( V_267 ) ;
F_72 ( & V_267 -> V_87 ) ;
F_69 ( V_7 -> V_275 ) ;
return 0 ;
}
