static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_5 , V_6 ) ;
T_1 V_7 ;
int V_8 ;
F_3 ( V_9 != 0 ) ;
F_3 ( V_10 != sizeof( V_4 -> V_11 ) ) ;
V_8 = F_4 ( V_2 , V_12 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
goto V_13;
if ( V_7 < V_6 ) {
V_8 = - V_14 ;
goto V_13;
}
V_4 -> V_15 = F_5 ( V_5 , V_16 ) ;
V_4 -> type = F_5 ( V_5 , V_17 ) ;
V_4 -> V_18 =
F_5 ( V_5 , V_19 ) ;
V_4 -> V_20 = F_5 ( V_5 , V_21 ) ;
V_4 -> V_22 = F_5 ( V_5 , V_23 ) ;
V_4 -> V_24 = F_5 ( V_5 , V_25 ) ;
memcpy ( V_4 -> V_11 , F_6 ( V_5 , V_26 ) ,
sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_27 = F_5 ( V_5 , V_28 ) ;
V_4 -> V_29 = F_5 ( V_5 , V_30 ) ;
memcpy ( V_4 -> V_31 , F_6 ( V_5 , V_32 ) ,
sizeof( V_4 -> V_31 ) ) ;
return 0 ;
V_13:
F_7 ( V_2 , V_33 , V_2 -> V_34 , L_1 , V_35 , V_8 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_36 ,
T_2 V_15 , T_2 V_37 ,
T_2 V_38 )
{
F_2 ( V_39 , V_40 ) ;
int V_8 ;
F_3 ( V_41 != 0 ) ;
F_9 ( V_39 , V_42 , V_36 ) ;
F_9 ( V_39 , V_43 , V_15 ) ;
F_9 ( V_39 , V_44 , V_37 ) ;
F_9 ( V_39 , V_45 , V_38 ) ;
V_8 = F_4 ( V_2 , V_46 , V_39 , sizeof( V_39 ) ,
NULL , 0 , NULL ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 , T_3 * V_47 )
{
F_2 ( V_5 , V_48 ) ;
T_1 V_7 ;
int V_8 ;
V_8 = F_4 ( V_2 , V_49 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
goto V_13;
if ( V_7 < ( V_50 +
V_51 ) ) {
V_8 = - V_14 ;
goto V_13;
}
* V_47 = F_11 ( V_5 , V_52 ) ;
return 0 ;
V_13:
F_7 ( V_2 , V_33 , V_2 -> V_34 , L_1 , V_35 , V_8 ) ;
return V_8 ;
}
static int F_12 ( struct V_53 * V_34 ,
int V_54 , int V_55 , T_4 V_56 )
{
struct V_1 * V_2 = F_13 ( V_34 ) ;
F_2 ( V_39 , V_57 ) ;
F_2 ( V_5 , V_58 ) ;
T_1 V_7 ;
int V_8 ;
F_9 ( V_39 , V_59 , V_2 -> V_60 ) ;
F_9 ( V_39 , V_61 , V_54 ) ;
F_9 ( V_39 , V_62 , V_55 ) ;
F_9 ( V_39 , V_63 , V_56 ) ;
V_8 = F_4 ( V_2 , V_64 , V_39 , sizeof( V_39 ) ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
return V_8 ;
if ( F_5 ( V_5 , V_65 ) !=
V_66 )
return - V_14 ;
return ( T_4 ) F_5 ( V_5 , V_67 ) ;
}
static int F_14 ( struct V_53 * V_34 ,
int V_54 , int V_55 , T_4 V_56 , T_4 V_68 )
{
struct V_1 * V_2 = F_13 ( V_34 ) ;
F_2 ( V_39 , V_69 ) ;
F_2 ( V_5 , V_70 ) ;
T_1 V_7 ;
int V_8 ;
F_9 ( V_39 , V_71 , V_2 -> V_60 ) ;
F_9 ( V_39 , V_72 , V_54 ) ;
F_9 ( V_39 , V_73 , V_55 ) ;
F_9 ( V_39 , V_74 , V_56 ) ;
F_9 ( V_39 , V_75 , V_68 ) ;
V_8 = F_4 ( V_2 , V_76 , V_39 , sizeof( V_39 ) ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
return V_8 ;
if ( F_5 ( V_5 , V_77 ) !=
V_66 )
return - V_14 ;
return 0 ;
}
static T_2 F_15 ( T_2 V_27 , T_2 V_78 )
{
T_2 V_79 = 0 ;
switch ( V_27 ) {
case V_80 :
V_79 |= V_81 ;
if ( V_78 & ( 1 << V_82 ) )
V_79 |= V_83 ;
if ( V_78 & ( 1 << V_84 ) )
V_79 |= V_85 ;
if ( V_78 & ( 1 << V_86 ) )
V_79 |= V_87 ;
break;
case V_88 :
case V_89 :
case V_90 :
V_79 |= V_91 ;
if ( V_78 & ( 1 << V_82 ) )
V_79 |= V_92 ;
if ( V_78 & ( 1 << V_84 ) )
V_79 |= V_93 ;
if ( V_78 & ( 1 << V_86 ) )
V_79 |= V_94 ;
break;
case V_95 :
V_79 |= V_96 ;
if ( V_78 & ( 1 << V_97 ) )
V_79 |= V_98 ;
if ( V_78 & ( 1 << V_99 ) )
V_79 |= V_100 ;
if ( V_78 & ( 1 << V_101 ) )
V_79 |= V_102 ;
if ( V_78 & ( 1 << V_103 ) )
V_79 |= V_104 ;
if ( V_78 & ( 1 << V_105 ) )
V_79 |= V_106 ;
if ( V_78 & ( 1 << V_82 ) )
V_79 |= V_92 ;
if ( V_78 & ( 1 << V_84 ) )
V_79 |= V_93 ;
break;
}
if ( V_78 & ( 1 << V_107 ) )
V_79 |= V_108 ;
if ( V_78 & ( 1 << V_109 ) )
V_79 |= V_110 ;
if ( V_78 & ( 1 << V_111 ) )
V_79 |= V_112 ;
return V_79 ;
}
static T_2 F_16 ( T_2 V_78 )
{
T_2 V_79 = 0 ;
if ( V_78 & V_98 )
V_79 |= ( 1 << V_97 ) ;
if ( V_78 & V_100 )
V_79 |= ( 1 << V_99 ) ;
if ( V_78 & V_102 )
V_79 |= ( 1 << V_101 ) ;
if ( V_78 & V_104 )
V_79 |= ( 1 << V_103 ) ;
if ( V_78 & V_106 )
V_79 |= ( 1 << V_105 ) ;
if ( V_78 & ( V_92 | V_83 ) )
V_79 |= ( 1 << V_82 ) ;
if ( V_78 & ( V_93 | V_85 ) )
V_79 |= ( 1 << V_84 ) ;
if ( V_78 & ( V_94 | V_87 ) )
V_79 |= ( 1 << V_86 ) ;
if ( V_78 & V_108 )
V_79 |= ( 1 << V_107 ) ;
if ( V_78 & V_110 )
V_79 |= ( 1 << V_109 ) ;
if ( V_78 & V_112 )
V_79 |= ( 1 << V_111 ) ;
return V_79 ;
}
static T_2 F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
enum V_115 V_116 , V_117 ;
T_2 V_15 ;
V_117 = 0 ;
if ( V_113 -> V_15 & ( 1 << V_118 ) )
V_117 |= V_119 ;
if ( V_113 -> V_15 & ( 1 << V_120 ) )
V_117 |= V_121 ;
if ( V_113 -> V_15 & ( 1 << V_122 ) )
V_117 |= V_123 ;
V_116 = V_2 -> V_124 & V_117 ;
V_15 = 0 ;
if ( V_116 & V_119 )
V_15 |= ( 1 << V_125 ) ;
if ( V_116 & V_121 )
V_15 |= ( 1 << V_126 ) ;
if ( V_116 & V_123 )
V_15 |= ( 1 << V_127 ) ;
return V_15 ;
}
static T_2 F_18 ( T_2 V_27 )
{
switch ( V_27 ) {
case V_128 :
case V_129 :
case V_80 :
return V_130 ;
case V_88 :
case V_89 :
case V_90 :
return V_131 ;
case V_95 :
return V_132 ;
default:
return V_130 ;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
T_2 V_135 , T_2 V_15 , T_2 V_136 )
{
switch ( V_136 ) {
case V_137 :
F_20 ( 1 ) ;
V_134 -> V_138 = V_139 | V_140 | V_141 ;
break;
case V_142 :
V_134 -> V_138 = V_140 | V_141 ;
break;
case V_143 :
V_134 -> V_138 = V_141 ;
break;
default:
F_20 ( 1 ) ;
case V_144 :
V_134 -> V_138 = 0 ;
break;
}
V_134 -> V_145 = ! ! ( V_15 & ( 1 << V_146 ) ) ;
V_134 -> V_147 = ! ! ( V_15 & ( 1 << V_148 ) ) ;
V_134 -> V_135 = V_135 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_114 ;
F_2 ( V_5 , V_149 ) ;
T_2 V_150 ;
int V_8 ;
V_114 = F_22 ( sizeof( * V_114 ) , V_151 ) ;
if ( V_114 == NULL )
return - V_152 ;
V_8 = F_1 ( V_2 , V_114 ) ;
if ( V_8 != 0 )
goto V_13;
F_3 ( V_153 != 0 ) ;
V_8 = F_4 ( V_2 , V_154 , NULL , 0 ,
V_5 , sizeof( V_5 ) , NULL ) ;
if ( V_8 )
goto V_13;
V_2 -> V_114 = V_114 ;
V_2 -> V_155 = V_114 -> type ;
V_2 -> V_60 = V_114 -> V_20 ;
V_2 -> V_156 . V_54 = V_114 -> V_22 ;
V_2 -> V_156 . V_157 = V_114 -> V_29 & ~ ( 1 << V_158 ) ;
V_2 -> V_156 . V_159 = 0 ;
if ( V_114 -> V_29 & ( 1 << V_158 ) )
V_2 -> V_156 . V_159 |= V_160 ;
if ( V_114 -> V_29 & ~ ( 1 << V_158 ) )
V_2 -> V_156 . V_159 |= V_161 | V_162 ;
V_150 = F_5 ( V_5 , V_163 ) ;
if ( V_150 & ( 1 << V_111 ) )
V_2 -> V_164 =
F_15 ( V_114 -> V_27 , V_150 ) ;
else
V_114 -> V_165 = V_150 ;
F_3 ( V_166 != V_167 ) ;
F_3 ( V_168 != V_169 ) ;
F_3 ( V_170 != V_171 ) ;
F_3 ( V_172 != V_173 ) ;
F_3 ( V_174 != V_175 ) ;
F_3 ( V_176 != V_177 ) ;
F_3 ( V_178 != V_179 ) ;
F_3 ( V_180 != V_181 ) ;
F_3 ( V_182 != V_183 ) ;
F_3 ( V_184 != V_185 ) ;
F_3 ( V_186 != V_187 ) ;
F_3 ( V_188 != V_189 ) ;
F_3 ( V_190 != V_191 ) ;
F_3 ( V_192 != V_193 ) ;
F_3 ( V_194 != V_195 ) ;
F_3 ( V_196 != V_197 ) ;
F_3 ( V_198 != V_199 ) ;
F_3 ( V_200 != V_201 ) ;
F_3 ( V_202 != V_203 ) ;
F_3 ( V_204 != V_205 ) ;
F_3 ( V_206 != V_207 ) ;
F_3 ( V_208 != V_209 ) ;
F_3 ( V_210 != V_211 ) ;
F_3 ( V_212 != V_213 ) ;
F_3 ( V_214 != V_215 ) ;
F_3 ( V_216 != V_217 ) ;
F_3 ( V_218 != V_219 ) ;
V_8 = F_10 ( V_2 , & V_2 -> V_47 ) ;
if ( V_8 != 0 )
goto V_13;
V_2 -> V_47 &= ~ ( 1 << V_166 ) ;
F_19 (
V_2 , & V_2 -> V_134 ,
F_5 ( V_5 , V_220 ) ,
F_5 ( V_5 , V_221 ) ,
F_5 ( V_5 , V_222 ) ) ;
V_2 -> V_223 = V_141 | V_140 ;
if ( V_114 -> V_18 & ( 1 << V_111 ) )
V_2 -> V_223 |= V_139 ;
F_23 ( V_2 , V_2 -> V_223 ) ;
return 0 ;
V_13:
F_24 ( V_114 ) ;
return V_8 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
T_2 V_150 = ( V_2 -> V_164 ?
F_16 ( V_2 -> V_164 ) :
V_113 -> V_165 ) ;
return F_8 ( V_2 , V_150 , F_17 ( V_2 ) ,
V_2 -> V_37 , 0 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_224 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
T_2 V_225 ;
if ( ~ V_113 -> V_18 & ( 1 << V_111 ) )
return;
if ( V_2 -> V_223 & V_139 )
return;
V_225 = 0 ;
if ( V_224 & ( 1 << V_107 ) )
V_225 |= V_226 ;
if ( V_224 & ( 1 << V_109 ) )
V_225 |= V_227 ;
if ( ( V_2 -> V_223 & V_140 ) && V_225 == V_227 )
F_7 ( V_2 , V_228 , V_2 -> V_34 ,
L_2 ) ;
}
static bool F_27 ( struct V_1 * V_2 )
{
struct V_133 V_229 = V_2 -> V_134 ;
F_2 ( V_5 , V_149 ) ;
int V_8 ;
F_20 ( ! F_28 ( & V_2 -> V_230 ) ) ;
F_3 ( V_153 != 0 ) ;
V_8 = F_4 ( V_2 , V_154 , NULL , 0 ,
V_5 , sizeof( V_5 ) , NULL ) ;
if ( V_8 )
V_2 -> V_134 . V_145 = false ;
else
F_19 (
V_2 , & V_2 -> V_134 ,
F_5 ( V_5 , V_220 ) ,
F_5 ( V_5 , V_221 ) ,
F_5 ( V_5 , V_222 ) ) ;
return ! F_29 ( & V_2 -> V_134 , & V_229 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_114 = V_2 -> V_114 ;
V_2 -> V_114 = NULL ;
F_24 ( V_114 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_231 * V_232 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
F_2 ( V_5 , V_149 ) ;
int V_8 ;
T_2 V_117 , V_233 , V_234 ;
V_117 = F_15 ( V_113 -> V_27 , V_113 -> V_18 ) ;
V_233 = V_2 -> V_164 ;
V_232 -> V_235 . V_135 = V_2 -> V_134 . V_135 ;
V_232 -> V_235 . V_236 = V_2 -> V_134 . V_147 ;
V_232 -> V_235 . V_22 = F_18 ( V_113 -> V_27 ) ;
V_232 -> V_235 . V_237 = V_113 -> V_22 ;
V_232 -> V_235 . V_238 = ! ! ( V_2 -> V_164 & V_239 ) ;
V_232 -> V_235 . V_240 = ( V_2 -> V_156 . V_159 &
( V_161 | V_160 ) ) ;
F_32 ( V_232 -> V_241 . V_117 ,
V_117 ) ;
F_32 ( V_232 -> V_241 . V_233 ,
V_233 ) ;
F_3 ( V_153 != 0 ) ;
V_8 = F_4 ( V_2 , V_154 , NULL , 0 ,
V_5 , sizeof( V_5 ) , NULL ) ;
if ( V_8 )
return;
V_234 =
F_15 ( V_113 -> V_27 ,
F_5 ( V_5 , V_242 ) ) ;
F_32 ( V_232 -> V_241 . V_234 ,
V_234 ) ;
}
static int
F_33 ( struct V_1 * V_2 ,
const struct V_231 * V_232 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
T_2 V_150 ;
int V_8 ;
T_2 V_233 ;
F_34 ( & V_233 ,
V_232 -> V_241 . V_233 ) ;
if ( V_232 -> V_235 . V_238 ) {
V_150 = ( F_16 ( V_233 ) |
1 << V_111 ) ;
} else if ( V_232 -> V_235 . V_236 ) {
switch ( V_232 -> V_235 . V_135 ) {
case 10 : V_150 = 1 << V_99 ; break;
case 100 : V_150 = 1 << V_103 ; break;
case 1000 : V_150 = 1 << V_82 ; break;
case 10000 : V_150 = 1 << V_84 ; break;
case 40000 : V_150 = 1 << V_86 ; break;
default: return - V_243 ;
}
} else {
switch ( V_232 -> V_235 . V_135 ) {
case 10 : V_150 = 1 << V_97 ; break;
case 100 : V_150 = 1 << V_101 ; break;
case 1000 : V_150 = 1 << V_105 ; break;
default: return - V_243 ;
}
}
V_8 = F_8 ( V_2 , V_150 , F_17 ( V_2 ) ,
V_2 -> V_37 , 0 ) ;
if ( V_8 )
return V_8 ;
if ( V_232 -> V_235 . V_238 ) {
F_35 (
V_2 , V_233 | V_239 ) ;
V_113 -> V_165 = 0 ;
} else {
F_35 ( V_2 , 0 ) ;
V_113 -> V_165 = V_150 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_2 ( V_5 , V_244 ) ;
T_1 V_7 ;
int V_8 ;
F_3 ( V_245 != 0 ) ;
V_8 = F_4 ( V_2 , V_246 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
return V_8 ;
if ( V_7 < V_244 )
return - V_14 ;
if ( F_5 ( V_5 , V_247 ) != V_248 )
return - V_243 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_249 ,
int * V_250 )
{
unsigned int V_251 , V_252 , V_253 = 0 ;
T_1 V_7 ;
T_2 V_254 ;
F_2 ( V_39 , V_255 ) ;
F_2 ( V_5 , V_256 ) ;
T_5 * V_257 ;
int V_8 ;
F_3 ( V_258 != 0 ) ;
F_9 ( V_39 , V_259 , V_249 ) ;
V_8 = F_4 ( V_2 , V_260 ,
V_39 , V_255 , NULL , 0 , NULL ) ;
if ( V_8 )
goto V_261;
for ( V_251 = 0 ; V_251 < 100 ; ++ V_251 ) {
F_3 ( V_262 != 0 ) ;
V_8 = F_4 ( V_2 , V_263 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
goto V_261;
V_254 = F_5 ( V_5 , V_264 ) ;
if ( V_254 != V_265 )
goto V_266;
F_38 ( 100 ) ;
}
V_8 = - V_267 ;
goto V_261;
V_266:
V_250 [ V_253 ++ ] = ( V_254 == V_268 ) ? 1 : - 1 ;
if ( V_2 -> V_155 == V_269 &&
( V_249 == V_270 ||
V_249 == V_271 ) ) {
V_257 = F_6 ( V_5 , V_272 ) ;
if ( V_254 == V_268 &&
V_7 >= V_256 ) {
for ( V_252 = 0 ; V_252 < 8 ; V_252 ++ ) {
V_250 [ V_253 + V_252 ] =
F_39 ( ( ( V_273 * ) V_257 ) [ V_252 ] ,
V_274 ) ;
}
}
V_253 += 8 ;
}
V_8 = V_253 ;
V_261:
return V_8 ;
}
static int F_40 ( struct V_1 * V_2 , int * V_250 ,
unsigned V_15 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
T_2 V_116 ;
int V_8 ;
if ( V_113 -> V_15 & ( 1 << V_275 ) ) {
V_8 = F_37 ( V_2 , V_276 , V_250 ) ;
if ( V_8 < 0 )
return V_8 ;
V_250 += V_8 ;
}
V_116 = 0 ;
if ( V_113 -> V_15 & ( 1 << V_277 ) ) {
if ( ( V_15 & V_278 ) &&
( V_113 -> V_15 &
( 1 << V_279 ) ) )
V_116 = V_271 ;
else
V_116 = V_270 ;
} else if ( V_113 -> V_15 &
( 1 << V_279 ) )
V_116 = V_271 ;
if ( V_116 != 0 ) {
V_8 = F_37 ( V_2 , V_116 , V_250 ) ;
if ( V_8 < 0 )
return V_8 ;
V_250 += V_8 ;
}
return 0 ;
}
static const char * F_41 ( struct V_1 * V_2 ,
unsigned int V_280 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
if ( V_113 -> V_15 & ( 1 << V_275 ) ) {
if ( V_280 == 0 )
return L_3 ;
-- V_280 ;
}
if ( V_113 -> V_15 & ( ( 1 << V_277 ) |
( 1 << V_279 ) ) ) {
if ( V_280 == 0 )
return L_4 ;
-- V_280 ;
if ( V_2 -> V_155 == V_269 ) {
if ( V_280 < F_42 ( V_281 ) )
return V_281 [ V_280 ] ;
V_280 -= F_42 ( V_281 ) ;
}
}
return NULL ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_282 * V_283 , T_5 * V_284 )
{
F_2 ( V_5 , V_285 ) ;
F_2 ( V_39 , V_286 ) ;
T_1 V_7 ;
int V_8 ;
unsigned int V_287 ;
unsigned int V_288 = V_283 -> V_289 ;
unsigned int V_290 ;
unsigned int V_291 ;
unsigned int V_292 ;
T_5 * V_293 = V_284 ;
F_3 ( V_294 * V_295 != V_296 ) ;
V_291 = V_283 -> V_297 % V_294 ;
V_290 = V_283 -> V_297 / V_294 ;
while ( V_288 && ( V_290 < V_295 ) ) {
F_9 ( V_39 , V_298 , V_290 ) ;
V_8 = F_4 ( V_2 , V_299 ,
V_39 , sizeof( V_39 ) ,
V_5 , sizeof( V_5 ) ,
& V_7 ) ;
if ( V_8 )
return V_8 ;
if ( V_7 < ( V_300 +
V_294 ) )
return - V_14 ;
V_287 = F_5 ( V_5 ,
V_301 ) ;
if ( V_287 != V_294 )
return - V_14 ;
V_287 -= V_291 ;
V_292 = ( V_288 < V_287 ) ?
V_288 : V_287 ;
memcpy ( V_293 ,
F_6 ( V_5 , V_302 ) + V_291 ,
V_292 ) ;
V_288 -= V_292 ;
V_293 += V_292 ;
V_291 = 0 ;
V_290 ++ ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_303 * V_304 )
{
struct V_3 * V_113 = V_2 -> V_114 ;
switch ( V_113 -> V_27 ) {
case V_89 :
V_304 -> type = V_305 ;
V_304 -> V_306 = V_296 ;
return 0 ;
default:
return - V_307 ;
}
}
T_2 F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_114 = V_2 -> V_114 ;
return V_114 -> V_18 ;
}
void F_46 ( struct V_1 * V_2 , T_6 * V_308 )
{
T_2 V_15 , V_136 , V_135 , V_224 ;
V_135 = F_47 ( * V_308 , V_309 ) ;
F_48 ( V_135 >= F_42 ( V_310 ) ) ;
V_135 = V_310 [ V_135 ] ;
V_15 = F_47 ( * V_308 , V_311 ) ;
V_136 = F_47 ( * V_308 , V_312 ) ;
V_224 = F_47 ( * V_308 , V_313 ) ;
F_19 ( V_2 , & V_2 -> V_134 , V_135 , V_15 , V_136 ) ;
F_26 ( V_2 , V_224 ) ;
F_49 ( V_2 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
T_2 V_136 ;
F_2 ( V_314 , V_315 ) ;
F_3 ( V_316 != 0 ) ;
F_51 ( F_6 ( V_314 , V_317 ) ,
V_2 -> V_34 -> V_318 ) ;
F_9 ( V_314 , V_319 ,
F_52 ( V_2 -> V_34 -> V_320 ) ) ;
F_9 ( V_314 , V_321 , 0 ) ;
F_53 ( V_314 , V_322 ,
V_323 , V_2 -> V_324 ) ;
switch ( V_2 -> V_223 ) {
case V_141 | V_140 :
V_136 = V_142 ;
break;
case V_141 :
V_136 = V_143 ;
break;
default:
V_136 = V_144 ;
break;
}
if ( V_2 -> V_223 & V_139 )
V_136 = V_137 ;
if ( V_2 -> V_325 )
V_136 = V_144 ;
F_9 ( V_314 , V_326 , V_136 ) ;
return F_4 ( V_2 , V_327 , V_314 , sizeof( V_314 ) ,
NULL , 0 , NULL ) ;
}
bool F_54 ( struct V_1 * V_2 )
{
F_2 ( V_5 , V_149 ) ;
T_1 V_328 ;
int V_8 ;
F_3 ( V_153 != 0 ) ;
V_8 = F_4 ( V_2 , V_154 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_328 ) ;
if ( V_8 )
return true ;
return F_5 ( V_5 , V_329 ) != 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
enum V_330 V_331 , int V_332 )
{
F_2 ( V_39 , V_333 ) ;
int V_8 ;
int V_334 = V_331 == V_335 ? 0 : 1 ;
int V_336 = V_331 == V_337 ? 1 : 0 ;
int V_338 = V_331 == V_337 ? 1000 : 0 ;
T_7 V_339 = V_2 -> V_340 . V_339 ;
T_2 V_341 = V_331 != V_342 ?
V_343 * sizeof( T_3 ) : 0 ;
F_3 ( V_344 != 0 ) ;
F_56 ( V_39 , V_345 , V_339 ) ;
F_57 ( V_39 , V_346 ,
V_347 , ! ! V_336 ,
V_348 , V_332 ,
V_349 , V_334 ,
V_350 , V_336 ,
V_351 , 0 ,
V_352 , 1 ,
V_353 , V_338 ) ;
F_9 ( V_39 , V_354 , V_341 ) ;
if ( F_58 ( V_2 ) >= V_355 ) {
struct V_356 * V_357 = V_2 -> V_357 ;
F_9 ( V_39 , V_358 , V_357 -> V_359 ) ;
}
V_8 = F_59 ( V_2 , V_360 , V_39 , sizeof( V_39 ) ,
NULL , 0 , NULL ) ;
if ( V_8 && ( V_8 != - V_361 || F_60 ( & V_2 -> V_362 ) ) )
F_61 ( V_2 , V_360 , sizeof( V_39 ) ,
NULL , 0 , V_8 ) ;
return V_8 ;
}
void F_62 ( struct V_1 * V_2 )
{
T_8 * V_363 = V_2 -> V_340 . V_56 ;
V_363 [ V_364 ] = V_365 ;
F_55 ( V_2 , V_337 , 0 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_55 ( V_2 , V_342 , 0 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
T_8 * V_363 = V_2 -> V_340 . V_56 ;
int V_366 = V_367 ;
V_363 [ V_364 ] = V_365 ;
F_55 ( V_2 , V_335 , 0 ) ;
while ( V_363 [ V_364 ] ==
V_365 &&
V_366 -- != 0 )
F_65 ( V_368 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_369 = & V_370 ;
V_2 -> V_156 . V_159 = V_161 | V_162 ;
V_2 -> V_156 . V_371 = F_12 ;
V_2 -> V_156 . V_372 = F_14 ;
V_8 = V_2 -> V_369 -> V_373 ( V_2 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_67 ( V_2 , & V_2 -> V_340 ,
V_343 * sizeof( T_3 ) , V_151 ) ;
if ( V_8 )
return V_8 ;
F_68 ( V_2 , V_373 , V_2 -> V_34 ,
L_5 ,
( T_3 ) V_2 -> V_340 . V_339 ,
V_2 -> V_340 . V_56 ,
( T_3 ) F_69 ( V_2 -> V_340 . V_56 ) ) ;
F_55 ( V_2 , V_342 , 1 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 )
{
V_2 -> V_369 -> remove ( V_2 ) ;
F_71 ( V_2 , & V_2 -> V_340 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
F_2 ( V_5 , V_374 ) ;
int V_8 ;
V_8 = F_4 ( V_2 , V_375 , NULL , 0 ,
V_5 , sizeof( V_5 ) , NULL ) ;
if ( V_8 )
return V_8 ;
return F_5 ( V_5 , V_376 ) ;
}
