static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 [ V_6 ] ;
T_2 V_7 ;
int V_8 ;
F_2 ( V_9 != 0 ) ;
F_2 ( V_10 != sizeof( V_4 -> V_11 ) ) ;
V_8 = F_3 ( V_2 , V_12 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
goto V_13;
if ( V_7 < V_6 ) {
V_8 = - V_14 ;
goto V_13;
}
V_4 -> V_15 = F_4 ( V_5 , V_16 ) ;
V_4 -> type = F_4 ( V_5 , V_17 ) ;
V_4 -> V_18 =
F_4 ( V_5 , V_19 ) ;
V_4 -> V_20 = F_4 ( V_5 , V_21 ) ;
V_4 -> V_22 = F_4 ( V_5 , V_23 ) ;
V_4 -> V_24 = F_4 ( V_5 , V_25 ) ;
memcpy ( V_4 -> V_11 , F_5 ( V_5 , V_26 ) ,
sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_27 = F_4 ( V_5 , V_28 ) ;
V_4 -> V_29 = F_4 ( V_5 , V_30 ) ;
memcpy ( V_4 -> V_31 , F_5 ( V_5 , V_32 ) ,
sizeof( V_4 -> V_31 ) ) ;
return 0 ;
V_13:
F_6 ( V_2 , V_33 , V_2 -> V_34 , L_1 , V_35 , V_8 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , T_3 V_36 ,
T_3 V_15 , T_3 V_37 ,
T_3 V_38 )
{
T_1 V_39 [ V_40 ] ;
int V_8 ;
F_2 ( V_41 != 0 ) ;
F_8 ( V_39 , V_42 , V_36 ) ;
F_8 ( V_39 , V_43 , V_15 ) ;
F_8 ( V_39 , V_44 , V_37 ) ;
F_8 ( V_39 , V_45 , V_38 ) ;
V_8 = F_3 ( V_2 , V_46 , V_39 , sizeof( V_39 ) ,
NULL , 0 , NULL ) ;
if ( V_8 )
goto V_13;
return 0 ;
V_13:
F_6 ( V_2 , V_33 , V_2 -> V_34 , L_1 , V_35 , V_8 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , T_4 * V_47 )
{
T_1 V_5 [ V_48 ] ;
T_2 V_7 ;
int V_8 ;
V_8 = F_3 ( V_2 , V_49 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
goto V_13;
if ( V_7 < V_48 ) {
V_8 = - V_14 ;
goto V_13;
}
* V_47 = F_10 ( V_5 , V_50 ) ;
return 0 ;
V_13:
F_6 ( V_2 , V_33 , V_2 -> V_34 , L_1 , V_35 , V_8 ) ;
return V_8 ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_51 ,
unsigned int V_52 , unsigned int V_53 , T_5 V_54 ,
T_5 * V_55 , T_3 * V_56 )
{
T_1 V_39 [ V_57 ] ;
T_1 V_5 [ V_58 ] ;
T_2 V_7 ;
int V_8 ;
F_8 ( V_39 , V_59 , V_51 ) ;
F_8 ( V_39 , V_60 , V_52 ) ;
F_8 ( V_39 , V_61 , V_53 ) ;
F_8 ( V_39 , V_62 , V_54 ) ;
V_8 = F_3 ( V_2 , V_63 , V_39 , sizeof( V_39 ) ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
goto V_13;
* V_55 = ( T_5 ) F_4 ( V_5 , V_64 ) ;
* V_56 = F_4 ( V_5 , V_65 ) ;
return 0 ;
V_13:
F_6 ( V_2 , V_33 , V_2 -> V_34 , L_1 , V_35 , V_8 ) ;
return V_8 ;
}
int F_12 ( struct V_1 * V_2 , unsigned int V_51 ,
unsigned int V_52 , unsigned int V_53 , T_5 V_54 ,
T_5 V_66 , T_3 * V_56 )
{
T_1 V_39 [ V_67 ] ;
T_1 V_5 [ V_68 ] ;
T_2 V_7 ;
int V_8 ;
F_8 ( V_39 , V_69 , V_51 ) ;
F_8 ( V_39 , V_70 , V_52 ) ;
F_8 ( V_39 , V_71 , V_53 ) ;
F_8 ( V_39 , V_72 , V_54 ) ;
F_8 ( V_39 , V_73 , V_66 ) ;
V_8 = F_3 ( V_2 , V_74 , V_39 , sizeof( V_39 ) ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
goto V_13;
* V_56 = F_4 ( V_5 , V_75 ) ;
return 0 ;
V_13:
F_6 ( V_2 , V_33 , V_2 -> V_34 , L_1 , V_35 , V_8 ) ;
return V_8 ;
}
static T_3 F_13 ( T_3 V_27 , T_3 V_76 )
{
T_3 V_77 = 0 ;
switch ( V_27 ) {
case V_78 :
V_77 |= V_79 ;
if ( V_76 & ( 1 << V_80 ) )
V_77 |= V_81 ;
if ( V_76 & ( 1 << V_82 ) )
V_77 |= V_83 ;
break;
case V_84 :
case V_85 :
V_77 |= V_86 ;
break;
case V_87 :
V_77 |= V_88 ;
if ( V_76 & ( 1 << V_89 ) )
V_77 |= V_90 ;
if ( V_76 & ( 1 << V_91 ) )
V_77 |= V_92 ;
if ( V_76 & ( 1 << V_93 ) )
V_77 |= V_94 ;
if ( V_76 & ( 1 << V_95 ) )
V_77 |= V_96 ;
if ( V_76 & ( 1 << V_97 ) )
V_77 |= V_98 ;
if ( V_76 & ( 1 << V_80 ) )
V_77 |= V_99 ;
if ( V_76 & ( 1 << V_82 ) )
V_77 |= V_100 ;
break;
}
if ( V_76 & ( 1 << V_101 ) )
V_77 |= V_102 ;
if ( V_76 & ( 1 << V_103 ) )
V_77 |= V_104 ;
if ( V_76 & ( 1 << V_105 ) )
V_77 |= V_106 ;
return V_77 ;
}
static T_3 F_14 ( T_3 V_76 )
{
T_3 V_77 = 0 ;
if ( V_76 & V_90 )
V_77 |= ( 1 << V_89 ) ;
if ( V_76 & V_92 )
V_77 |= ( 1 << V_91 ) ;
if ( V_76 & V_94 )
V_77 |= ( 1 << V_93 ) ;
if ( V_76 & V_96 )
V_77 |= ( 1 << V_95 ) ;
if ( V_76 & V_98 )
V_77 |= ( 1 << V_97 ) ;
if ( V_76 & ( V_99 | V_81 ) )
V_77 |= ( 1 << V_80 ) ;
if ( V_76 & ( V_100 | V_83 ) )
V_77 |= ( 1 << V_82 ) ;
if ( V_76 & V_102 )
V_77 |= ( 1 << V_101 ) ;
if ( V_76 & V_104 )
V_77 |= ( 1 << V_103 ) ;
if ( V_76 & V_106 )
V_77 |= ( 1 << V_105 ) ;
return V_77 ;
}
static T_3 F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_107 = V_2 -> V_108 ;
enum V_109 V_110 , V_111 ;
T_3 V_15 ;
V_111 = 0 ;
if ( V_107 -> V_15 & ( 1 << V_112 ) )
V_111 |= V_113 ;
if ( V_107 -> V_15 & ( 1 << V_114 ) )
V_111 |= V_115 ;
if ( V_107 -> V_15 & ( 1 << V_116 ) )
V_111 |= V_117 ;
V_110 = V_2 -> V_118 & V_111 ;
V_15 = 0 ;
if ( V_110 & V_113 )
V_15 |= ( 1 << V_119 ) ;
if ( V_110 & V_115 )
V_15 |= ( 1 << V_120 ) ;
if ( V_110 & V_117 )
V_15 |= ( 1 << V_121 ) ;
return V_15 ;
}
static T_3 F_16 ( T_3 V_27 )
{
switch ( V_27 ) {
case V_122 :
case V_123 :
case V_78 :
return V_124 ;
case V_84 :
case V_85 :
return V_125 ;
case V_87 :
return V_126 ;
default:
return V_124 ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_108 ;
T_1 V_5 [ V_127 ] ;
T_3 V_128 ;
int V_8 ;
V_108 = F_18 ( sizeof( * V_108 ) , V_129 ) ;
if ( V_108 == NULL )
return - V_130 ;
V_8 = F_1 ( V_2 , V_108 ) ;
if ( V_8 != 0 )
goto V_13;
F_2 ( V_131 != 0 ) ;
V_8 = F_3 ( V_2 , V_132 , NULL , 0 ,
V_5 , sizeof( V_5 ) , NULL ) ;
if ( V_8 )
goto V_13;
V_2 -> V_108 = V_108 ;
V_2 -> V_133 = V_108 -> type ;
V_2 -> V_134 = V_108 -> V_20 ;
V_2 -> V_135 . V_52 = V_108 -> V_22 ;
V_2 -> V_135 . V_136 = V_108 -> V_29 & ~ ( 1 << V_137 ) ;
V_2 -> V_135 . V_138 = 0 ;
if ( V_108 -> V_29 & ( 1 << V_137 ) )
V_2 -> V_135 . V_138 |= V_139 ;
if ( V_108 -> V_29 & ~ ( 1 << V_137 ) )
V_2 -> V_135 . V_138 |= V_140 | V_141 ;
V_128 = F_4 ( V_5 , V_142 ) ;
if ( V_128 & ( 1 << V_105 ) )
V_2 -> V_143 =
F_13 ( V_108 -> V_27 , V_128 ) ;
else
V_108 -> V_144 = V_128 ;
F_2 ( V_145 != V_146 ) ;
F_2 ( V_147 != V_148 ) ;
F_2 ( V_149 != V_150 ) ;
F_2 ( V_151 != V_152 ) ;
F_2 ( V_153 != V_154 ) ;
F_2 ( V_155 != V_156 ) ;
F_2 ( V_157 != V_158 ) ;
F_2 ( V_159 != V_160 ) ;
F_2 ( V_161 != V_162 ) ;
F_2 ( V_163 != V_164 ) ;
F_2 ( V_165 != V_166 ) ;
F_2 ( V_167 != V_168 ) ;
F_2 ( V_169 != V_170 ) ;
F_2 ( V_171 != V_172 ) ;
F_2 ( V_173 != V_174 ) ;
F_2 ( V_175 != V_176 ) ;
F_2 ( V_177 != V_178 ) ;
F_2 ( V_179 != V_180 ) ;
F_2 ( V_181 != V_182 ) ;
F_2 ( V_183 != V_184 ) ;
F_2 ( V_185 != V_186 ) ;
F_2 ( V_187 != V_188 ) ;
F_2 ( V_189 != V_190 ) ;
F_2 ( V_191 != V_192 ) ;
F_2 ( V_193 != V_194 ) ;
F_2 ( V_195 != V_196 ) ;
F_2 ( V_197 != V_198 ) ;
V_8 = F_9 ( V_2 , & V_2 -> V_47 ) ;
if ( V_8 != 0 )
goto V_13;
V_2 -> V_47 &= ~ ( 1 << V_145 ) ;
F_19 (
V_2 , & V_2 -> V_199 ,
F_4 ( V_5 , V_200 ) ,
F_4 ( V_5 , V_201 ) ,
F_4 ( V_5 , V_202 ) ) ;
V_2 -> V_203 = V_204 | V_205 ;
if ( V_108 -> V_18 & ( 1 << V_105 ) )
V_2 -> V_203 |= V_206 ;
F_20 ( V_2 , V_2 -> V_203 ) ;
return 0 ;
V_13:
F_21 ( V_108 ) ;
return V_8 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_107 = V_2 -> V_108 ;
T_3 V_128 = ( V_2 -> V_143 ?
F_14 ( V_2 -> V_143 ) :
V_107 -> V_144 ) ;
return F_7 ( V_2 , V_128 , F_15 ( V_2 ) ,
V_2 -> V_37 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_207 * V_199 ,
T_3 V_208 , T_3 V_15 , T_3 V_209 )
{
switch ( V_209 ) {
case V_210 :
F_23 ( 1 ) ;
V_199 -> V_211 = V_206 | V_205 | V_204 ;
break;
case V_212 :
V_199 -> V_211 = V_205 | V_204 ;
break;
case V_213 :
V_199 -> V_211 = V_204 ;
break;
default:
F_23 ( 1 ) ;
case V_214 :
V_199 -> V_211 = 0 ;
break;
}
V_199 -> V_215 = ! ! ( V_15 & ( 1 << V_216 ) ) ;
V_199 -> V_217 = ! ! ( V_15 & ( 1 << V_218 ) ) ;
V_199 -> V_208 = V_208 ;
}
void F_24 ( struct V_1 * V_2 , T_3 V_219 )
{
struct V_3 * V_107 = V_2 -> V_108 ;
T_3 V_220 ;
if ( ~ V_107 -> V_18 & ( 1 << V_105 ) )
return;
if ( V_2 -> V_203 & V_206 )
return;
V_220 = 0 ;
if ( V_219 & ( 1 << V_101 ) )
V_220 |= V_221 ;
if ( V_219 & ( 1 << V_103 ) )
V_220 |= V_222 ;
if ( ( V_2 -> V_203 & V_205 ) && V_220 == V_222 )
F_6 ( V_2 , V_223 , V_2 -> V_34 ,
L_2 ) ;
}
static bool F_25 ( struct V_1 * V_2 )
{
struct V_207 V_224 = V_2 -> V_199 ;
T_1 V_5 [ V_127 ] ;
int V_8 ;
F_23 ( ! F_26 ( & V_2 -> V_225 ) ) ;
F_2 ( V_131 != 0 ) ;
V_8 = F_3 ( V_2 , V_132 , NULL , 0 ,
V_5 , sizeof( V_5 ) , NULL ) ;
if ( V_8 ) {
F_6 ( V_2 , V_33 , V_2 -> V_34 , L_1 ,
V_35 , V_8 ) ;
V_2 -> V_199 . V_215 = false ;
} else {
F_19 (
V_2 , & V_2 -> V_199 ,
F_4 ( V_5 , V_200 ) ,
F_4 ( V_5 , V_201 ) ,
F_4 ( V_5 , V_202 ) ) ;
}
return ! F_27 ( & V_2 -> V_199 , & V_224 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_108 = V_2 -> V_108 ;
V_2 -> V_108 = NULL ;
F_21 ( V_108 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_226 * V_227 )
{
struct V_3 * V_107 = V_2 -> V_108 ;
T_1 V_5 [ V_127 ] ;
int V_8 ;
V_227 -> V_111 =
F_13 ( V_107 -> V_27 , V_107 -> V_18 ) ;
V_227 -> V_228 = V_2 -> V_143 ;
F_30 ( V_227 , V_2 -> V_199 . V_208 ) ;
V_227 -> V_229 = V_2 -> V_199 . V_217 ;
V_227 -> V_22 = F_16 ( V_107 -> V_27 ) ;
V_227 -> V_230 = V_107 -> V_22 ;
V_227 -> V_231 = V_232 ;
V_227 -> V_233 = ! ! ( V_2 -> V_143 & V_234 ) ;
V_227 -> V_235 = ( V_2 -> V_135 . V_138 &
( V_140 | V_139 ) ) ;
F_2 ( V_131 != 0 ) ;
V_8 = F_3 ( V_2 , V_132 , NULL , 0 ,
V_5 , sizeof( V_5 ) , NULL ) ;
if ( V_8 ) {
F_6 ( V_2 , V_33 , V_2 -> V_34 , L_1 ,
V_35 , V_8 ) ;
return;
}
V_227 -> V_236 =
F_13 ( V_107 -> V_27 ,
F_4 ( V_5 , V_237 ) ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_226 * V_227 )
{
struct V_3 * V_107 = V_2 -> V_108 ;
T_3 V_128 ;
int V_8 ;
if ( V_227 -> V_233 ) {
V_128 = ( F_14 ( V_227 -> V_228 ) |
1 << V_105 ) ;
} else if ( V_227 -> V_229 ) {
switch ( F_32 ( V_227 ) ) {
case 10 : V_128 = 1 << V_91 ; break;
case 100 : V_128 = 1 << V_95 ; break;
case 1000 : V_128 = 1 << V_80 ; break;
case 10000 : V_128 = 1 << V_82 ; break;
default: return - V_238 ;
}
} else {
switch ( F_32 ( V_227 ) ) {
case 10 : V_128 = 1 << V_89 ; break;
case 100 : V_128 = 1 << V_93 ; break;
case 1000 : V_128 = 1 << V_97 ; break;
default: return - V_238 ;
}
}
V_8 = F_7 ( V_2 , V_128 , F_15 ( V_2 ) ,
V_2 -> V_37 , 0 ) ;
if ( V_8 )
return V_8 ;
if ( V_227 -> V_233 ) {
F_33 (
V_2 , V_227 -> V_228 | V_234 ) ;
V_107 -> V_144 = 0 ;
} else {
F_33 ( V_2 , 0 ) ;
V_107 -> V_144 = V_128 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 V_5 [ V_239 ] ;
T_2 V_7 ;
int V_8 ;
F_2 ( V_240 != 0 ) ;
V_8 = F_3 ( V_2 , V_241 , NULL , 0 ,
V_5 , sizeof( V_5 ) , & V_7 ) ;
if ( V_8 )
return V_8 ;
if ( V_7 < V_239 )
return - V_14 ;
if ( F_4 ( V_5 , V_242 ) != V_243 )
return - V_238 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_244 ,
int * V_245 )
{
unsigned int V_246 , V_247 , V_248 = 0 ;
T_2 V_7 ;
T_3 V_249 ;
T_1 * V_250 , * V_251 ;
int V_8 ;
V_250 = F_18 ( 0x100 , V_129 ) ;
if ( V_250 == NULL )
return - V_130 ;
F_2 ( V_252 != 0 ) ;
F_8 ( V_250 , V_253 , V_244 ) ;
V_8 = F_3 ( V_2 , V_254 , V_250 , V_255 ,
NULL , 0 , NULL ) ;
if ( V_8 )
goto V_256;
for ( V_246 = 0 ; V_246 < 100 ; ++ V_246 ) {
F_2 ( V_257 != 0 ) ;
V_8 = F_3 ( V_2 , V_258 , NULL , 0 ,
V_250 , 0x100 , & V_7 ) ;
if ( V_8 )
goto V_256;
V_249 = F_4 ( V_250 , V_259 ) ;
if ( V_249 != V_260 )
goto V_261;
F_36 ( 100 ) ;
}
V_8 = - V_262 ;
goto V_256;
V_261:
V_245 [ V_248 ++ ] = ( V_249 == V_263 ) ? 1 : - 1 ;
if ( V_2 -> V_133 == V_264 &&
( V_244 == V_265 ||
V_244 == V_266 ) ) {
V_251 = F_5 ( V_250 , V_267 ) ;
if ( V_249 == V_263 &&
V_7 >= V_268 ) {
for ( V_247 = 0 ; V_247 < 8 ; V_247 ++ ) {
V_245 [ V_248 + V_247 ] =
F_37 ( ( ( V_269 * ) V_251 ) [ V_247 ] ,
V_270 ) ;
}
}
V_248 += 8 ;
}
V_8 = V_248 ;
V_256:
F_21 ( V_250 ) ;
return V_8 ;
}
static int F_38 ( struct V_1 * V_2 , int * V_245 ,
unsigned V_15 )
{
struct V_3 * V_107 = V_2 -> V_108 ;
T_3 V_110 ;
int V_8 ;
if ( V_107 -> V_15 & ( 1 << V_271 ) ) {
V_8 = F_35 ( V_2 , V_272 , V_245 ) ;
if ( V_8 < 0 )
return V_8 ;
V_245 += V_8 ;
}
V_110 = 0 ;
if ( V_107 -> V_15 & ( 1 << V_273 ) ) {
if ( ( V_15 & V_274 ) &&
( V_107 -> V_15 &
( 1 << V_275 ) ) )
V_110 = V_266 ;
else
V_110 = V_265 ;
} else if ( V_107 -> V_15 &
( 1 << V_275 ) )
V_110 = V_266 ;
if ( V_110 != 0 ) {
V_8 = F_35 ( V_2 , V_110 , V_245 ) ;
if ( V_8 < 0 )
return V_8 ;
V_245 += V_8 ;
}
return 0 ;
}
static const char * F_39 ( struct V_1 * V_2 ,
unsigned int V_276 )
{
struct V_3 * V_107 = V_2 -> V_108 ;
if ( V_107 -> V_15 & ( 1 << V_271 ) ) {
if ( V_276 == 0 )
return L_3 ;
-- V_276 ;
}
if ( V_107 -> V_15 & ( ( 1 << V_273 ) |
( 1 << V_275 ) ) ) {
if ( V_276 == 0 )
return L_4 ;
-- V_276 ;
if ( V_2 -> V_133 == V_264 ) {
if ( V_276 < F_40 ( V_277 ) )
return V_277 [ V_276 ] ;
V_276 -= F_40 ( V_277 ) ;
}
}
return NULL ;
}
