static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 , V_5 ;
int V_6 = 0 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ;
V_7 ++ ) {
F_2 ( V_2 , V_9 , V_3 ) ;
F_2 ( V_2 , V_9 ,
V_3 | V_10 ) ;
V_4 = F_3 ( V_2 , V_11 ) ;
F_2 ( V_2 , V_9 ,
V_3 | V_12 ) ;
V_5 = F_3 ( V_2 , V_11 ) ;
V_6 += ( ( V_4 << 8 ) | ( V_5 << 16 ) ) ;
}
return V_6 / V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_13 , V_14 , V_15 , V_16 ;
V_13 = F_1 ( V_2 ,
V_17 ) ;
V_14 = F_1 ( V_2 ,
V_18 ) ;
V_15 = - V_13 ;
V_16 = - V_14 ;
V_3 = ( V_15 & V_19 ) >> 8 ;
F_2 ( V_2 , V_20 , V_3 ) ;
V_3 = ( V_15 & V_21 ) >> 16 ;
F_2 ( V_2 , V_22 , V_3 ) ;
V_3 = ( V_16 & V_19 ) >> 8 ;
F_2 ( V_2 , V_23 , V_3 ) ;
V_3 = ( V_16 & V_21 ) >> 16 ;
F_2 ( V_2 , V_24 , V_3 ) ;
F_5 ( V_2 , V_25 ,
V_26 | V_27 ,
V_26 | V_27 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_28 ;
F_5 ( V_2 , V_25 , V_29 ,
V_29 ) ;
do {
V_28 = F_3 ( V_2 , V_25 ) ;
} while ( V_28 & V_29 );
if ( V_28 & V_30 ) {
F_7 ( V_2 -> V_31 ,
L_1 ) ;
F_5 ( V_2 , V_25 ,
V_26 | V_27 ,
0 ) ;
} else {
F_5 ( V_2 , V_25 ,
V_26 | V_27 ,
V_26 | V_27 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_34 , V_35 ;
T_1 V_36 , V_37 ;
T_1 V_38 , V_39 ;
V_34 = F_3 ( V_2 , V_40 ) ;
V_35 = F_3 ( V_2 , V_41 ) ;
V_36 = F_3 ( V_2 , V_42 ) ;
V_37 = F_3 ( V_2 , V_43 ) ;
V_38 = F_3 ( V_2 , V_44 ) ;
V_39 = F_3 ( V_2 , V_45 ) ;
F_5 ( V_2 , V_40 , V_46 ,
V_46 ) ;
F_5 ( V_2 , V_41 , V_46 ,
V_46 ) ;
F_5 ( V_2 , V_42 ,
V_47 |
V_48 ,
V_47 |
V_48 ) ;
F_5 ( V_2 , V_43 ,
V_49 |
V_50 ,
V_49 |
V_50 ) ;
F_5 ( V_2 , V_44 , V_51 ,
V_51 ) ;
F_5 ( V_2 , V_45 , V_51 ,
V_51 ) ;
if ( V_33 -> V_52 )
F_6 ( V_2 ) ;
else
F_4 ( V_2 ) ;
F_2 ( V_2 , V_42 , V_36 ) ;
F_2 ( V_2 , V_43 , V_37 ) ;
F_2 ( V_2 , V_40 , V_34 ) ;
F_2 ( V_2 , V_41 , V_35 ) ;
F_2 ( V_2 , V_44 , V_38 ) ;
F_2 ( V_2 , V_45 , V_39 ) ;
}
static int F_10 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_11 ( V_54 ) ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 ;
V_57 = F_12 ( V_54 , V_56 ) ;
if ( ( ! V_57 ) && ( V_33 -> V_58 ) )
F_8 ( V_2 ) ;
return V_57 ;
}
static int F_13 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_11 ( V_54 ) ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
if ( V_56 -> V_59 . integer . V_59 [ 0 ] ||
V_56 -> V_59 . integer . V_59 [ 1 ] ) {
if ( ! V_33 -> V_58 ) {
F_8 ( V_2 ) ;
V_33 -> V_58 = true ;
}
} else {
V_33 -> V_58 = false ;
}
return F_14 ( V_54 , V_56 ) ;
}
static int F_15 ( struct V_60 * V_61 ,
struct V_53 * V_54 , int V_62 )
{
struct V_1 * V_2 = F_16 ( V_61 -> V_63 ) ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_64 , V_65 ;
int V_66 = 0 ;
bool V_67 = false ;
switch ( V_62 ) {
case V_68 :
if ( V_33 -> V_69 )
F_5 ( V_2 , V_70 ,
V_71 ,
V_71 ) ;
F_5 ( V_2 , V_72 ,
V_73 , 0 ) ;
V_64 = F_3 ( V_2 , V_74 ) ;
if ( ! ( V_64 & V_75 ) )
return 0 ;
do {
V_65 = F_3 ( V_2 , V_76 ) ;
if ( V_65 & V_77 ) {
V_67 = true ;
} else {
++ V_66 ;
F_17 ( 50 ) ;
}
} while ( ( V_66 < V_78 ) & ( ! V_67 ) );
if ( ! V_67 )
F_7 ( V_2 -> V_31 , L_2 ) ;
return 0 ;
case V_79 :
F_5 ( V_2 , V_72 ,
V_73 ,
V_73 ) ;
if ( V_33 -> V_69 )
F_5 ( V_2 , V_70 ,
V_71 , 0 ) ;
return 0 ;
default:
return - V_80 ;
}
}
static bool F_18 ( struct V_81 * V_31 , unsigned int V_82 )
{
switch ( V_82 ) {
case V_83 :
case V_76 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_25 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_11 :
return 1 ;
default:
return 0 ;
}
}
static int F_19 ( struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
T_1 V_107 = 0 ;
T_1 V_108 ;
switch ( F_20 ( V_104 ) ) {
case 16 :
V_107 |= V_109 ;
break;
case 20 :
V_107 |= V_110 ;
break;
case 24 :
V_107 |= V_111 ;
break;
case 32 :
V_107 |= V_112 ;
break;
default:
return - V_80 ;
}
switch ( F_21 ( V_104 ) ) {
case 8000 :
V_108 = V_113 ;
break;
case 11025 :
V_108 = V_114 ;
break;
case 12000 :
V_108 = V_115 ;
break;
case 16000 :
V_108 = V_116 ;
break;
case 22050 :
V_108 = V_117 ;
break;
case 32000 :
V_108 = V_118 ;
break;
case 44100 :
V_108 = V_119 ;
break;
case 48000 :
V_108 = V_120 ;
break;
case 88200 :
V_108 = V_121 ;
break;
case 96000 :
V_108 = V_122 ;
break;
default:
return - V_80 ;
}
F_5 ( V_2 , V_123 , V_124 ,
V_107 ) ;
F_2 ( V_2 , V_125 , V_108 ) ;
return 0 ;
}
static int F_22 ( struct V_105 * V_126 , unsigned int V_127 )
{
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_128 = 0 , V_107 = 0 ;
switch ( V_127 & V_129 ) {
case V_130 :
V_33 -> V_69 = true ;
break;
case V_131 :
V_33 -> V_69 = false ;
break;
default:
return - V_80 ;
}
switch ( V_127 & V_132 ) {
case V_133 :
break;
case V_134 :
V_128 |= V_135 ;
break;
case V_136 :
V_128 |= V_137 ;
break;
case V_138 :
V_128 |= V_135 | V_137 ;
break;
default:
return - V_80 ;
}
switch ( V_127 & V_139 ) {
case V_140 :
V_107 |= V_141 ;
break;
case V_142 :
V_107 |= V_143 ;
break;
case V_144 :
V_107 |= V_145 ;
break;
default:
return - V_80 ;
}
V_128 |= V_146 ;
F_2 ( V_2 , V_70 , V_128 ) ;
F_5 ( V_2 , V_123 , V_147 ,
V_107 ) ;
return 0 ;
}
static int F_23 ( struct V_105 * V_106 , int V_148 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
if ( V_148 ) {
F_5 ( V_2 , V_149 ,
V_51 , V_51 ) ;
F_5 ( V_2 , V_150 ,
V_51 , V_51 ) ;
} else {
F_5 ( V_2 , V_149 ,
V_51 , 0 ) ;
F_5 ( V_2 , V_150 ,
V_51 , 0 ) ;
}
return 0 ;
}
static int F_24 ( struct V_105 * V_126 ,
int V_151 , unsigned int V_152 , int V_153 )
{
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 = 0 ;
if ( ( V_33 -> V_154 == V_151 ) && ( V_33 -> V_155 == V_152 ) )
return 0 ;
if ( ( ( V_152 < 5000000 ) && ( V_152 != 32768 ) ) || ( V_152 > 54000000 ) ) {
F_25 ( V_126 -> V_31 , L_3 ,
V_152 ) ;
return - V_80 ;
}
switch ( V_151 ) {
case V_156 :
V_33 -> V_157 = false ;
break;
case V_158 :
V_33 -> V_157 = true ;
break;
default:
F_25 ( V_126 -> V_31 , L_4 , V_151 ) ;
return - V_80 ;
}
V_33 -> V_154 = V_151 ;
if ( V_33 -> V_159 ) {
V_152 = F_26 ( V_33 -> V_159 , V_152 ) ;
V_57 = F_27 ( V_33 -> V_159 , V_152 ) ;
if ( V_57 ) {
F_25 ( V_126 -> V_31 , L_5 ,
V_152 ) ;
return V_57 ;
}
}
V_33 -> V_155 = V_152 ;
return 0 ;
}
static int F_28 ( struct V_105 * V_126 , int V_160 ,
int V_161 , unsigned int V_162 , unsigned int V_163 )
{
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_32 * V_33 = F_9 ( V_2 ) ;
T_1 V_64 , V_164 , V_165 ;
T_1 V_166 , V_167 , V_168 ;
T_2 V_169 ;
T_3 V_170 ;
F_2 ( V_2 , V_74 , 0 ) ;
V_64 = 0 ;
if ( V_33 -> V_155 == 32768 ) {
V_164 = V_171 ;
V_165 = V_172 ;
V_169 = 3750000 ;
V_64 |= V_173 ;
} else {
if ( V_33 -> V_155 < 5000000 ) {
goto V_174;
} else if ( V_33 -> V_155 <= 9000000 ) {
V_164 = V_175 ;
V_165 = V_176 ;
} else if ( V_33 -> V_155 <= 18000000 ) {
V_164 = V_171 ;
V_165 = V_172 ;
} else if ( V_33 -> V_155 <= 36000000 ) {
V_164 = V_177 ;
V_165 = V_178 ;
} else if ( V_33 -> V_155 <= 54000000 ) {
V_164 = V_179 ;
V_165 = V_180 ;
} else {
goto V_174;
}
V_169 = ( V_33 -> V_155 / V_165 ) ;
}
V_64 |= V_164 ;
if ( V_161 == V_181 ) {
F_2 ( V_2 , V_74 , V_64 ) ;
return 0 ;
}
if ( ! V_33 -> V_69 && V_33 -> V_182 ) {
V_163 = V_183 ;
V_64 |= V_75 ;
}
if ( V_33 -> V_157 )
V_64 |= V_184 ;
V_168 = V_163 / V_169 ;
V_170 = ( T_3 ) ( V_163 % V_169 ) * 8192ULL ;
F_29 ( V_170 , V_169 ) ;
V_166 = ( V_170 >> V_185 ) & V_186 ;
V_167 = ( V_170 ) & V_186 ;
F_2 ( V_2 , V_187 , V_166 ) ;
F_2 ( V_2 , V_188 , V_167 ) ;
F_2 ( V_2 , V_189 , V_168 ) ;
V_64 |= V_190 ;
F_2 ( V_2 , V_74 , V_64 ) ;
return 0 ;
V_174:
F_25 ( V_126 -> V_31 , L_6 ,
V_33 -> V_155 ) ;
return - V_80 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_191 V_192 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
int V_57 ;
switch ( V_192 ) {
case V_193 :
case V_194 :
break;
case V_195 :
if ( F_31 ( V_2 ) == V_196 ) {
if ( V_33 -> V_159 ) {
V_57 = F_32 ( V_33 -> V_159 ) ;
if ( V_57 ) {
F_25 ( V_2 -> V_31 ,
L_7 ) ;
return V_57 ;
}
}
F_5 ( V_2 , V_197 ,
V_198 | V_199 ,
V_198 | V_199 ) ;
}
break;
case V_196 :
F_5 ( V_2 , V_197 ,
V_198 | V_199 , 0 ) ;
if ( V_33 -> V_159 )
F_33 ( V_33 -> V_159 ) ;
break;
}
return 0 ;
}
static enum V_200
F_34 ( struct V_1 * V_2 , T_2 V_201 )
{
switch ( V_201 ) {
case 1600 :
return V_202 ;
case 2200 :
return V_203 ;
case 2500 :
return V_204 ;
case 3000 :
return V_205 ;
default:
F_7 ( V_2 -> V_31 , L_8 ) ;
return V_203 ;
}
}
static enum V_206
F_35 ( struct V_1 * V_2 , const char * V_207 )
{
if ( ! strcmp ( V_207 , L_9 ) ) {
return V_208 ;
} else if ( ! strcmp ( V_207 , L_10 ) ) {
return V_209 ;
} else {
F_7 ( V_2 -> V_31 , L_11 ) ;
return V_208 ;
}
}
static enum V_210
F_36 ( struct V_1 * V_2 , const char * V_207 )
{
if ( ! strcmp ( V_207 , L_12 ) ) {
return V_211 ;
} else if ( ! strcmp ( V_207 , L_13 ) ) {
return V_212 ;
} else {
F_7 ( V_2 -> V_31 , L_14 ) ;
return V_211 ;
}
}
static enum V_213
F_37 ( struct V_1 * V_2 , T_2 V_201 )
{
switch ( V_201 ) {
case 1500000 :
return V_214 ;
case 3000000 :
return V_215 ;
default:
F_7 ( V_2 -> V_31 , L_15 ) ;
return V_214 ;
}
}
static struct V_216
* F_38 ( struct V_1 * V_2 )
{
struct V_217 * V_218 = V_2 -> V_31 -> V_219 ;
struct V_216 * V_220 ;
const char * V_221 ;
T_2 V_222 ;
V_220 = F_39 ( V_2 -> V_31 , sizeof( * V_220 ) , V_223 ) ;
if ( ! V_220 ) {
F_7 ( V_2 -> V_31 , L_16 ) ;
return NULL ;
}
if ( F_40 ( V_218 , L_17 , & V_222 ) >= 0 )
V_220 -> V_224 = F_34 ( V_2 , V_222 ) ;
else
V_220 -> V_224 = V_203 ;
if ( F_40 ( V_218 , L_18 , & V_222 ) >= 0 )
V_220 -> V_225 = F_34 ( V_2 , V_222 ) ;
else
V_220 -> V_225 = V_203 ;
if ( ! F_41 ( V_218 , L_19 , & V_221 ) )
V_220 -> V_226 = F_35 ( V_2 , V_221 ) ;
else
V_220 -> V_226 = V_208 ;
if ( ! F_41 ( V_218 , L_20 , & V_221 ) )
V_220 -> V_227 =
F_36 ( V_2 , V_221 ) ;
else
V_220 -> V_227 = V_211 ;
if ( F_40 ( V_218 , L_21 , & V_222 ) >= 0 )
V_220 -> V_228 = F_37 ( V_2 , V_222 ) ;
else
V_220 -> V_228 = V_215 ;
return V_220 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_9 ( V_2 ) ;
F_5 ( V_2 , V_25 ,
V_229 , 0 ) ;
V_33 -> V_52 = true ;
V_33 -> V_182 = true ;
F_5 ( V_2 , V_72 , V_73 ,
V_73 ) ;
F_5 ( V_2 , V_230 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_232 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_233 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_234 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_40 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_41 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_149 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_150 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_235 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_236 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_237 ,
V_231 , V_231 ) ;
F_5 ( V_2 , V_233 ,
V_238 , V_238 ) ;
F_5 ( V_2 , V_234 ,
V_238 , V_238 ) ;
F_5 ( V_2 , V_239 ,
V_240 , V_240 ) ;
F_5 ( V_2 , V_241 ,
V_240 , V_240 ) ;
F_5 ( V_2 , V_235 ,
V_242 , V_242 ) ;
F_5 ( V_2 , V_236 ,
V_242 , V_242 ) ;
F_5 ( V_2 , V_237 ,
V_243 , V_243 ) ;
if ( V_2 -> V_31 -> V_219 )
V_33 -> V_220 = F_38 ( V_2 ) ;
else
V_33 -> V_220 = F_43 ( V_2 -> V_31 ) ;
if ( V_33 -> V_220 ) {
struct V_216 * V_220 = V_33 -> V_220 ;
T_1 V_244 = 0 , V_245 = 0 ;
switch ( V_220 -> V_224 ) {
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_244 |= ( V_220 -> V_224 <<
V_246 ) ;
break;
}
switch ( V_220 -> V_225 ) {
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_244 |= ( V_220 -> V_225 <<
V_247 ) ;
break;
}
F_5 ( V_2 , V_248 ,
V_249 |
V_250 , V_244 ) ;
switch ( V_220 -> V_226 ) {
case V_209 :
case V_208 :
V_245 |= ( V_220 -> V_226 <<
V_251 ) ;
break;
}
switch ( V_220 -> V_227 ) {
case V_211 :
case V_212 :
V_245 |= ( V_220 -> V_227 <<
V_252 ) ;
break;
}
switch ( V_220 -> V_228 ) {
case V_215 :
case V_214 :
V_245 |= ( V_220 -> V_228 <<
V_253 ) ;
break;
}
F_5 ( V_2 , V_254 ,
V_255 |
V_256 |
V_257 , V_245 ) ;
}
V_33 -> V_159 = F_44 ( V_2 -> V_31 , L_22 ) ;
if ( F_45 ( V_33 -> V_159 ) ) {
if ( F_46 ( V_33 -> V_159 ) != - V_258 )
return F_46 ( V_33 -> V_159 ) ;
else
V_33 -> V_159 = NULL ;
}
return 0 ;
}
static int F_47 ( struct V_259 * V_260 ,
const struct V_261 * V_262 )
{
struct V_32 * V_33 ;
int V_57 ;
V_33 = F_39 ( & V_260 -> V_31 , sizeof( struct V_32 ) ,
V_223 ) ;
if ( ! V_33 )
return - V_263 ;
F_48 ( V_260 , V_33 ) ;
V_33 -> V_264 = F_49 ( V_260 , & V_265 ) ;
if ( F_45 ( V_33 -> V_264 ) ) {
V_57 = F_46 ( V_33 -> V_264 ) ;
F_25 ( & V_260 -> V_31 , L_23 , V_57 ) ;
return V_57 ;
}
V_57 = F_50 ( & V_260 -> V_31 ,
& V_266 , & V_267 , 1 ) ;
if ( V_57 < 0 ) {
F_25 ( & V_260 -> V_31 , L_24 ,
V_57 ) ;
}
return V_57 ;
}
static int F_51 ( struct V_259 * V_268 )
{
F_52 ( & V_268 -> V_31 ) ;
return 0 ;
}
