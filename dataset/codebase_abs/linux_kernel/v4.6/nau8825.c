static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 ... V_11 :
case V_12 ... V_13 :
case V_14 ... V_15 :
case V_16 ... V_17 :
case V_18 ... V_19 :
case V_20 :
case V_21 ... V_22 :
case V_23 :
case V_24 ... V_25 :
case V_26 ... V_27 :
case V_28 ... V_29 :
case V_30 ... V_31 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_32 ... V_5 :
case V_6 ... V_7 :
case V_8 :
case V_33 ... V_9 :
case V_10 ... V_11 :
case V_12 ... V_13 :
case V_14 ... V_15 :
case V_16 :
case V_18 ... V_19 :
case V_20 :
case V_23 :
case V_24 ... V_25 :
case V_26 ... V_27 :
case V_28 ... V_29 :
case V_30 ... V_34 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_32 :
case V_35 :
case V_33 :
case V_36 :
case V_17 :
case V_21 :
case V_22 :
case V_37 :
case V_31 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_43 * V_44 = F_5 ( V_39 -> V_45 ) ;
struct V_46 * V_46 = F_6 ( V_44 ) ;
switch ( V_42 ) {
case V_47 :
F_7 ( 10 ) ;
F_8 ( V_46 -> V_48 , V_34 ,
V_49 , V_49 ) ;
break;
case V_50 :
F_8 ( V_46 -> V_48 , V_34 ,
V_49 , 0 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_9 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_43 * V_44 = F_5 ( V_39 -> V_45 ) ;
struct V_46 * V_46 = F_6 ( V_44 ) ;
switch ( V_42 ) {
case V_52 :
F_8 ( V_46 -> V_48 , V_23 ,
V_53 , 0 ) ;
break;
case V_54 :
F_8 ( V_46 -> V_48 , V_23 ,
V_53 , V_53 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_10 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_43 * V_44 = V_60 -> V_44 ;
struct V_46 * V_46 = F_6 ( V_44 ) ;
unsigned int V_61 = 0 ;
switch ( F_11 ( V_58 ) ) {
case 16 :
V_61 |= V_62 ;
break;
case 20 :
V_61 |= V_63 ;
break;
case 24 :
V_61 |= V_64 ;
break;
case 32 :
V_61 |= V_65 ;
break;
default:
return - V_51 ;
}
F_8 ( V_46 -> V_48 , V_66 ,
V_67 , V_61 ) ;
return 0 ;
}
static int F_12 ( struct V_59 * V_68 , unsigned int V_69 )
{
struct V_43 * V_44 = V_68 -> V_44 ;
struct V_46 * V_46 = F_6 ( V_44 ) ;
unsigned int V_70 = 0 , V_71 = 0 ;
switch ( V_69 & V_72 ) {
case V_73 :
V_71 |= V_74 ;
break;
case V_75 :
break;
default:
return - V_51 ;
}
switch ( V_69 & V_76 ) {
case V_77 :
break;
case V_78 :
V_70 |= V_79 ;
break;
default:
return - V_51 ;
}
switch ( V_69 & V_80 ) {
case V_81 :
V_70 |= V_82 ;
break;
case V_83 :
V_70 |= V_84 ;
break;
case V_85 :
V_70 |= V_86 ;
break;
case V_87 :
V_70 |= V_88 ;
break;
case V_89 :
V_70 |= V_88 ;
V_70 |= V_90 ;
break;
default:
return - V_51 ;
}
F_8 ( V_46 -> V_48 , V_66 ,
V_67 | V_91 |
V_92 | V_93 ,
V_70 ) ;
F_8 ( V_46 -> V_48 , V_94 ,
V_95 , V_71 ) ;
return 0 ;
}
int F_13 ( struct V_43 * V_44 ,
struct V_96 * V_97 )
{
struct V_46 * V_46 = F_6 ( V_44 ) ;
struct V_48 * V_48 = V_46 -> V_48 ;
V_46 -> V_97 = V_97 ;
F_8 ( V_48 , V_6 ,
V_98 | V_99 | V_100 ,
V_98 | V_99 | V_100 ) ;
F_8 ( V_48 , V_8 ,
V_101 | V_102 , 0 ) ;
return 0 ;
}
static bool F_14 ( struct V_48 * V_48 )
{
int V_103 ;
F_15 ( V_48 , V_21 , & V_103 ) ;
return ! ( V_103 & V_104 ) ;
}
static void F_16 ( struct V_48 * V_48 )
{
F_8 ( V_48 , V_94 ,
V_95 , V_74 ) ;
F_8 ( V_48 , V_94 ,
V_95 , V_105 ) ;
F_8 ( V_48 , V_7 ,
V_106 , V_106 ) ;
F_8 ( V_48 , V_7 ,
V_106 , 0 ) ;
}
static void F_17 ( struct V_46 * V_46 )
{
struct V_107 * V_45 = V_46 -> V_45 ;
struct V_48 * V_48 = V_46 -> V_48 ;
F_18 ( V_45 , L_1 ) ;
F_18 ( V_45 , L_2 ) ;
F_8 ( V_48 , V_27 ,
V_108 | V_109 , 0 ) ;
F_8 ( V_48 , V_6 , 0xf , 0xf ) ;
F_19 ( V_45 ) ;
}
static int F_20 ( int V_110 )
{
int V_111 = 0 ;
if ( V_110 & F_21 ( 0 ) )
V_111 |= V_112 ;
if ( V_110 & F_21 ( 1 ) )
V_111 |= V_113 ;
if ( V_110 & F_21 ( 2 ) )
V_111 |= V_114 ;
if ( V_110 & F_21 ( 3 ) )
V_111 |= V_115 ;
if ( V_110 & F_21 ( 4 ) )
V_111 |= V_116 ;
if ( V_110 & F_21 ( 5 ) )
V_111 |= V_117 ;
return V_111 ;
}
static int F_22 ( struct V_46 * V_46 )
{
struct V_48 * V_48 = V_46 -> V_48 ;
struct V_107 * V_45 = V_46 -> V_45 ;
int V_118 , V_119 ;
int type = 0 ;
F_15 ( V_48 , V_31 , & V_118 ) ;
V_119 = ( V_118 >> 10 ) & 3 ;
switch ( V_119 ) {
case 0 :
type = V_120 ;
break;
case 1 :
F_23 ( V_46 -> V_2 , L_3 ) ;
type = V_121 ;
F_8 ( V_48 , V_6 , 3 << 2 ,
1 << 2 ) ;
F_8 ( V_48 , V_27 ,
V_108 | V_109 ,
V_109 ) ;
F_8 ( V_48 , V_122 ,
V_123 ,
V_124 ) ;
F_24 ( V_45 , L_2 ) ;
F_24 ( V_45 , L_1 ) ;
F_19 ( V_45 ) ;
break;
case 2 :
case 3 :
F_23 ( V_46 -> V_2 , L_4 ) ;
type = V_121 ;
F_8 ( V_48 , V_6 , 3 << 2 ,
2 << 2 ) ;
F_8 ( V_48 , V_27 ,
V_108 | V_109 ,
V_108 ) ;
F_8 ( V_48 , V_122 ,
V_123 ,
V_125 ) ;
F_24 ( V_45 , L_2 ) ;
F_24 ( V_45 , L_1 ) ;
F_19 ( V_45 ) ;
break;
}
return type ;
}
static T_1 F_25 ( int V_126 , void * V_127 )
{
struct V_46 * V_46 = (struct V_46 * ) V_127 ;
struct V_48 * V_48 = V_46 -> V_48 ;
int V_128 , V_129 = 0 , V_42 = 0 , V_130 = 0 ;
if ( F_15 ( V_48 , V_35 , & V_128 ) ) {
F_26 ( V_46 -> V_2 , L_5 ) ;
return V_131 ;
}
if ( ( V_128 & V_132 ) ==
V_133 ) {
F_17 ( V_46 ) ;
V_130 |= V_121 ;
V_129 = V_132 ;
} else if ( V_128 & V_134 ) {
int V_135 ;
F_15 ( V_48 , V_33 ,
& V_135 ) ;
V_46 -> V_136 = F_20 (
V_135 >> 8 ) ;
V_42 |= V_46 -> V_136 ;
V_130 |= V_137 ;
V_129 = V_134 ;
} else if ( V_128 & V_138 ) {
V_130 = V_137 ;
V_129 = V_138 ;
} else if ( V_128 & V_139 ) {
if ( F_14 ( V_48 ) ) {
V_42 |= F_22 ( V_46 ) ;
} else {
F_27 ( V_46 -> V_2 , L_6 ) ;
F_17 ( V_46 ) ;
}
V_130 |= V_121 ;
V_129 = V_139 ;
}
if ( ! V_129 )
V_129 = V_128 ;
F_28 ( V_48 , V_33 , V_129 ) ;
if ( V_130 )
F_29 ( V_46 -> V_97 , V_42 , V_130 ) ;
return V_140 ;
}
static void F_30 ( struct V_46 * V_46 )
{
struct V_48 * V_48 = V_46 -> V_48 ;
F_8 ( V_48 , V_122 ,
V_141 ,
V_46 -> V_142 << V_143 ) ;
F_8 ( V_48 , V_122 ,
V_144 ,
V_46 -> V_145 << V_146 ) ;
F_8 ( V_48 , V_122 ,
V_147 ,
V_46 -> V_148 << V_149 ) ;
F_8 ( V_48 , V_9 ,
V_150 ,
( V_46 -> V_151 - 1 ) << V_152 ) ;
F_8 ( V_48 , V_9 ,
V_153 ,
V_46 -> V_154 << V_155 ) ;
F_8 ( V_48 , V_9 ,
V_156 ,
V_46 -> V_157 << V_158 ) ;
F_28 ( V_48 , V_10 ,
( V_46 -> V_159 [ 0 ] << 8 ) | V_46 -> V_159 [ 1 ] ) ;
F_28 ( V_48 , V_160 ,
( V_46 -> V_159 [ 2 ] << 8 ) | V_46 -> V_159 [ 3 ] ) ;
F_28 ( V_48 , V_161 ,
( V_46 -> V_159 [ 4 ] << 8 ) | V_46 -> V_159 [ 5 ] ) ;
F_28 ( V_48 , V_162 ,
( V_46 -> V_159 [ 6 ] << 8 ) | V_46 -> V_159 [ 7 ] ) ;
F_8 ( V_48 , V_8 ,
V_163 | V_164 ,
0 ) ;
}
static void F_31 ( struct V_46 * V_46 )
{
struct V_48 * V_48 = V_46 -> V_48 ;
F_28 ( V_48 , V_165 , 0x0001 ) ;
F_8 ( V_46 -> V_48 , V_23 ,
V_166 , V_166 ) ;
F_8 ( V_46 -> V_48 , V_28 ,
V_167 , V_167 ) ;
F_8 ( V_48 , V_23 ,
V_168 ,
V_46 -> V_169 << V_170 ) ;
F_8 ( V_48 , V_28 ,
V_171 | V_172 |
V_173 | V_174 ,
V_171 | V_172 |
V_173 | V_174 ) ;
F_8 ( V_48 , V_175 ,
V_176 ,
V_46 -> V_177 ? 0 : V_176 ) ;
F_8 ( V_48 , V_175 ,
V_178 ,
V_46 -> V_179 ? 0 : V_178 ) ;
F_8 ( V_48 , V_175 ,
V_180 ,
V_46 -> V_181 ? V_180 : 0 ) ;
F_8 ( V_48 , V_7 ,
V_182 ,
V_46 -> V_183 ? 0 : V_182 ) ;
F_8 ( V_48 , V_7 ,
V_184 ,
V_46 -> V_185 << V_186 ) ;
F_8 ( V_48 , V_7 ,
V_187 ,
V_46 -> V_188 << V_189 ) ;
F_8 ( V_48 , V_8 , 0x7ff , 0x7ff ) ;
F_8 ( V_48 , V_27 ,
V_190 , V_46 -> V_191 ) ;
if ( V_46 -> V_151 )
F_30 ( V_46 ) ;
F_8 ( V_48 , V_192 ,
V_193 , V_194 ) ;
F_8 ( V_48 , V_195 ,
V_196 , V_197 ) ;
F_8 ( V_48 , V_34 ,
V_198 | V_199 ,
V_198 | V_199 ) ;
F_8 ( V_46 -> V_48 , V_23 ,
V_53 , V_53 ) ;
F_8 ( V_48 , V_195 ,
V_200 , V_200 ) ;
F_8 ( V_48 , V_25 ,
V_201 |
V_202 | V_203 ,
V_201 |
V_202 | V_203 ) ;
F_8 ( V_48 , V_18 ,
V_204 ,
0x20 << V_205 ) ;
F_8 ( V_48 , V_206 ,
V_207 | V_208 ,
( 0x2 << V_209 ) |
( 0x3 << V_210 ) ) ;
}
static int F_32 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = F_6 ( V_44 ) ;
struct V_107 * V_45 = F_33 ( V_44 ) ;
V_46 -> V_45 = V_45 ;
F_24 ( V_45 , L_7 ) ;
F_19 ( V_45 ) ;
F_28 ( V_46 -> V_48 , V_211 , 0 ) ;
F_16 ( V_46 -> V_48 ) ;
return 0 ;
}
static int F_34 ( unsigned int V_212 , unsigned int V_213 ,
struct V_214 * V_215 )
{
T_2 V_216 ;
unsigned int V_217 , V_218 ;
for ( V_218 = 0 ; V_218 < F_35 ( V_219 ) ; V_218 ++ ) {
V_217 = V_212 / V_219 [ V_218 ] . V_220 ;
if ( V_217 <= V_221 )
break;
}
if ( V_218 == F_35 ( V_219 ) )
return - V_51 ;
V_215 -> V_222 = V_219 [ V_218 ] . V_223 ;
for ( V_218 = 0 ; V_218 < F_35 ( V_224 ) ; V_218 ++ ) {
if ( V_217 >= V_224 [ V_218 ] . V_220 )
break;
}
if ( V_218 == F_35 ( V_224 ) )
return - V_51 ;
V_215 -> V_225 = V_224 [ V_218 ] . V_223 ;
for ( V_218 = 0 ; V_218 < F_35 ( V_226 ) ; V_218 ++ ) {
V_216 = 256 * V_213 * 2 * V_226 [ V_218 ] . V_220 ;
if ( V_227 < V_216 && V_216 < V_228 )
break;
}
if ( V_218 == F_35 ( V_226 ) )
return - V_51 ;
V_215 -> V_229 = V_226 [ V_218 ] . V_223 ;
V_216 = F_36 ( V_216 << 16 , V_217 * V_215 -> V_225 ) ;
V_215 -> V_230 = ( V_216 >> 16 ) & 0x3FF ;
V_215 -> V_231 = V_216 & 0xFFFF ;
return 0 ;
}
static void F_37 ( struct V_46 * V_46 ,
struct V_214 * V_215 )
{
F_8 ( V_46 -> V_48 , V_232 ,
V_233 , V_215 -> V_229 ) ;
F_8 ( V_46 -> V_48 , V_234 ,
V_235 , V_215 -> V_225 ) ;
F_28 ( V_46 -> V_48 , V_236 , V_215 -> V_231 ) ;
F_8 ( V_46 -> V_48 , V_237 ,
V_238 , V_215 -> V_230 ) ;
F_8 ( V_46 -> V_48 , V_239 ,
V_240 , V_215 -> V_222 ) ;
F_8 ( V_46 -> V_48 , V_241 ,
V_242 , 0x0000 ) ;
F_8 ( V_46 -> V_48 , V_243 ,
V_244 , V_245 ) ;
}
static int F_38 ( struct V_43 * V_44 , int V_246 , int V_247 ,
unsigned int V_248 , unsigned int V_249 )
{
struct V_46 * V_46 = F_6 ( V_44 ) ;
struct V_214 V_215 ;
int V_250 , V_213 ;
V_213 = V_249 / 256 ;
V_250 = F_34 ( V_248 , V_213 , & V_215 ) ;
if ( V_250 < 0 ) {
F_26 ( V_44 -> V_2 , L_8 , V_248 ) ;
return V_250 ;
}
F_23 ( V_44 -> V_2 , L_9 ,
V_215 . V_229 , V_215 . V_225 , V_215 . V_231 ,
V_215 . V_230 , V_215 . V_222 ) ;
F_37 ( V_46 , & V_215 ) ;
F_39 ( 2 ) ;
F_8 ( V_46 -> V_48 , V_232 ,
V_251 , V_252 ) ;
return 0 ;
}
static int F_40 ( struct V_46 * V_46 , int V_253 ,
unsigned int V_254 )
{
struct V_48 * V_48 = V_46 -> V_48 ;
int V_250 ;
switch ( V_253 ) {
case V_255 :
F_8 ( V_48 , V_232 ,
V_251 , V_256 ) ;
F_8 ( V_48 , V_243 , V_257 , 0 ) ;
if ( ! V_46 -> V_258 )
break;
if ( ! V_46 -> V_259 ) {
V_250 = F_41 ( V_46 -> V_258 ) ;
if ( V_250 ) {
F_26 ( V_46 -> V_2 , L_10 ) ;
return V_250 ;
}
}
if ( V_46 -> V_259 != V_254 ) {
V_46 -> V_259 = V_254 ;
V_254 = F_42 ( V_46 -> V_258 , V_254 ) ;
V_250 = F_43 ( V_46 -> V_258 , V_254 ) ;
if ( V_250 ) {
F_26 ( V_46 -> V_2 , L_11 ) ;
return V_250 ;
}
}
break;
case V_260 :
F_8 ( V_48 , V_243 , V_257 ,
V_257 ) ;
F_8 ( V_48 , V_232 ,
V_251 , V_252 ) ;
if ( V_46 -> V_259 ) {
F_44 ( V_46 -> V_258 ) ;
V_46 -> V_259 = 0 ;
}
break;
default:
F_26 ( V_46 -> V_2 , L_12 , V_253 ) ;
return - V_51 ;
}
F_23 ( V_46 -> V_2 , L_13 , V_254 ,
V_253 ) ;
return 0 ;
}
static int F_45 ( struct V_43 * V_44 , int V_253 ,
int V_247 , unsigned int V_254 , int V_261 )
{
struct V_46 * V_46 = F_6 ( V_44 ) ;
return F_40 ( V_46 , V_253 , V_254 ) ;
}
static int F_46 ( struct V_43 * V_44 ,
enum V_262 V_263 )
{
struct V_46 * V_46 = F_6 ( V_44 ) ;
int V_250 ;
switch ( V_263 ) {
case V_264 :
break;
case V_265 :
break;
case V_266 :
if ( F_47 ( V_44 ) == V_267 ) {
if ( V_46 -> V_259 ) {
V_250 = F_41 ( V_46 -> V_258 ) ;
if ( V_250 ) {
F_26 ( V_46 -> V_2 , L_10 ) ;
return V_250 ;
}
}
}
break;
case V_267 :
if ( V_46 -> V_259 )
F_44 ( V_46 -> V_258 ) ;
break;
}
return 0 ;
}
static int F_48 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = F_6 ( V_44 ) ;
F_49 ( V_46 -> V_126 ) ;
F_50 ( V_46 -> V_48 , true ) ;
F_51 ( V_46 -> V_48 ) ;
return 0 ;
}
static int F_52 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = F_6 ( V_44 ) ;
F_50 ( V_46 -> V_48 , false ) ;
F_53 ( V_46 -> V_48 ) ;
if ( ! F_14 ( V_46 -> V_48 ) ) {
F_17 ( V_46 ) ;
F_29 ( V_46 -> V_97 , 0 , V_121 ) ;
}
F_54 ( V_46 -> V_126 ) ;
F_16 ( V_46 -> V_48 ) ;
return 0 ;
}
static void F_55 ( struct V_48 * V_48 )
{
F_28 ( V_48 , V_32 , 0x00 ) ;
F_28 ( V_48 , V_32 , 0x00 ) ;
}
static void F_56 ( struct V_46 * V_46 )
{
int V_218 ;
struct V_1 * V_2 = V_46 -> V_2 ;
F_23 ( V_2 , L_14 , V_46 -> V_177 ) ;
F_23 ( V_2 , L_15 , V_46 -> V_179 ) ;
F_23 ( V_2 , L_16 , V_46 -> V_181 ) ;
F_23 ( V_2 , L_17 , V_46 -> V_183 ) ;
F_23 ( V_2 , L_18 , V_46 -> V_191 ) ;
F_23 ( V_2 , L_19 , V_46 -> V_169 ) ;
F_23 ( V_2 , L_20 , V_46 -> V_151 ) ;
for ( V_218 = 0 ; V_218 < V_46 -> V_151 ; V_218 ++ )
F_23 ( V_2 , L_21 , V_218 ,
V_46 -> V_159 [ V_218 ] ) ;
F_23 ( V_2 , L_22 , V_46 -> V_154 ) ;
F_23 ( V_2 , L_23 , V_46 -> V_142 ) ;
F_23 ( V_2 , L_24 , V_46 -> V_145 ) ;
F_23 ( V_2 , L_25 , V_46 -> V_148 ) ;
F_23 ( V_2 , L_26 , V_46 -> V_157 ) ;
F_23 ( V_2 , L_27 ,
V_46 -> V_185 ) ;
F_23 ( V_2 , L_28 ,
V_46 -> V_188 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_46 * V_46 ) {
V_46 -> V_177 = F_58 ( V_2 ,
L_29 ) ;
V_46 -> V_179 = F_58 ( V_2 ,
L_30 ) ;
V_46 -> V_181 = F_58 ( V_2 ,
L_31 ) ;
F_59 ( V_2 , L_32 ,
& V_46 -> V_183 ) ;
F_59 ( V_2 , L_33 ,
& V_46 -> V_191 ) ;
F_59 ( V_2 , L_34 ,
& V_46 -> V_169 ) ;
F_59 ( V_2 , L_35 ,
& V_46 -> V_151 ) ;
F_60 ( V_2 , L_36 ,
V_46 -> V_159 , V_46 -> V_151 ) ;
F_59 ( V_2 , L_37 ,
& V_46 -> V_154 ) ;
F_59 ( V_2 , L_38 ,
& V_46 -> V_142 ) ;
F_59 ( V_2 , L_39 ,
& V_46 -> V_145 ) ;
F_59 ( V_2 , L_40 ,
& V_46 -> V_148 ) ;
F_59 ( V_2 , L_41 ,
& V_46 -> V_157 ) ;
F_59 ( V_2 , L_42 ,
& V_46 -> V_185 ) ;
F_59 ( V_2 , L_43 ,
& V_46 -> V_188 ) ;
V_46 -> V_258 = F_61 ( V_2 , L_44 ) ;
if ( F_62 ( V_46 -> V_258 ) == - V_268 ) {
return - V_268 ;
} else if ( F_62 ( V_46 -> V_258 ) == - V_269 ) {
V_46 -> V_258 = NULL ;
F_63 ( V_2 , L_45 ) ;
} else if ( F_64 ( V_46 -> V_258 ) ) {
return - V_51 ;
}
return 0 ;
}
static int F_65 ( struct V_46 * V_46 )
{
struct V_48 * V_48 = V_46 -> V_48 ;
int V_250 ;
F_8 ( V_48 , V_8 ,
V_270 , V_270 ) ;
F_40 ( V_46 , V_260 , 0 ) ;
F_8 ( V_48 , V_4 ,
V_271 , V_271 ) ;
V_250 = F_66 ( V_46 -> V_2 , V_46 -> V_126 , NULL ,
F_25 , V_272 | V_273 ,
L_46 , V_46 ) ;
if ( V_250 ) {
F_26 ( V_46 -> V_2 , L_47 ,
V_46 -> V_126 , V_250 ) ;
return V_250 ;
}
return 0 ;
}
static int F_67 ( struct V_274 * V_275 ,
const struct V_276 * V_277 )
{
struct V_1 * V_2 = & V_275 -> V_2 ;
struct V_46 * V_46 = F_68 ( & V_275 -> V_2 ) ;
int V_250 , V_110 ;
if ( ! V_46 ) {
V_46 = F_69 ( V_2 , sizeof( * V_46 ) , V_278 ) ;
if ( ! V_46 )
return - V_279 ;
V_250 = F_57 ( V_2 , V_46 ) ;
if ( V_250 )
return V_250 ;
}
F_70 ( V_275 , V_46 ) ;
V_46 -> V_48 = F_71 ( V_275 , & V_280 ) ;
if ( F_64 ( V_46 -> V_48 ) )
return F_62 ( V_46 -> V_48 ) ;
V_46 -> V_2 = V_2 ;
V_46 -> V_126 = V_275 -> V_126 ;
F_56 ( V_46 ) ;
F_55 ( V_46 -> V_48 ) ;
V_250 = F_15 ( V_46 -> V_48 , V_21 , & V_110 ) ;
if ( V_250 < 0 ) {
F_26 ( V_2 , L_48 ,
V_250 ) ;
return V_250 ;
}
if ( ( V_110 & V_281 ) !=
V_282 ) {
F_26 ( V_2 , L_49 ) ;
return - V_283 ;
}
F_31 ( V_46 ) ;
if ( V_275 -> V_126 )
F_65 ( V_46 ) ;
return F_72 ( & V_275 -> V_2 , & V_284 ,
& V_285 , 1 ) ;
}
static int F_73 ( struct V_274 * V_286 )
{
F_74 ( & V_286 -> V_2 ) ;
return 0 ;
}
