static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 . V_3 + V_1 ) ;
}
static inline void F_3 ( T_1 V_4 , T_1 V_1 )
{
F_4 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static void F_5 ( int V_5 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_7 ) ;
V_6 &= ( ~ V_8 ) ;
V_6 |= ( V_5 & V_8 ) ;
F_3 ( V_6 , V_7 ) ;
}
static void F_6 ( int V_5 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_7 ) ;
V_6 &= ( ~ ( V_9 ) ) ;
V_6 |= ( ( V_5 << V_10 ) & V_9 ) ;
F_3 ( V_6 , V_7 ) ;
}
static void F_7 ( void )
{
F_3 ( V_2 . V_11 . V_12 . V_13 , V_14 ) ;
F_3 ( V_2 . V_11 . V_12 . V_15 , V_16 ) ;
F_3 ( V_2 . V_11 . V_12 . V_17 , V_18 ) ;
F_3 ( V_2 . V_11 . V_12 . V_19 , V_20 ) ;
F_3 ( V_2 . V_11 . V_21 , V_22 ) ;
}
static int F_8 ( void )
{
int V_23 ;
F_9 ( V_2 . V_24 , L_1 ) ;
for ( V_23 = 0 ; V_23 <= V_25 ; V_23 += 4 )
F_3 ( 0 , V_23 ) ;
F_3 ( V_26 , V_27 ) ;
F_3 ( V_28 , V_29 ) ;
F_3 ( V_30 , V_31 ) ;
V_2 . V_11 . V_12 . V_13 = V_32 ;
V_2 . V_11 . V_12 . V_17 = V_32 ;
V_2 . V_11 . V_12 . V_15 = V_32 ;
V_2 . V_11 . V_12 . V_19 = V_32 ;
F_7 () ;
F_3 ( V_33 , V_34 ) ;
F_3 ( V_35 , V_36 ) ;
if ( F_10 ( V_37 ) ) {
F_9 ( V_2 . V_24 , L_2 ) ;
return - V_38 ;
}
if ( F_11 ( V_39 , 1 ) < 0 ) {
F_9 ( V_2 . V_24 , L_3 ) ;
return - V_38 ;
}
F_9 ( V_2 . V_24 , L_4 ) ;
return 0 ;
}
static int F_12 ( struct V_40 * V_40 )
{
return F_8 () ;
}
static int F_13 ( struct V_40 * V_40 )
{
F_11 ( V_39 , 0 ) ;
return 0 ;
}
static void F_14 ( struct V_41 * V_42 ,
enum V_43 V_44 , int V_45 )
{
int V_46 , V_47 ;
int V_48 , V_49 ;
int V_50 = 0 ;
F_9 ( V_2 . V_24 , L_5 ) ;
V_46 = V_42 -> V_51 << ( V_45 - 1 ) ;
V_47 = ( ( V_42 -> V_52 ) << ( V_45 - 1 ) ) - 1 ;
F_3 ( V_46 , V_53 ) ;
F_3 ( V_47 , V_54 ) ;
V_48 = V_42 -> V_55 ;
if ( V_44 == V_56 ) {
V_49 = ( V_42 -> V_57 >> 1 ) - 1 ;
V_48 >>= 1 ;
V_48 += 1 ;
F_3 ( V_48 , V_58 ) ;
} else {
V_48 += 1 ;
V_49 = V_42 -> V_57 - 1 ;
V_50 = V_48 + ( V_42 -> V_57 / 2 ) ;
F_3 ( V_48 , V_58 ) ;
F_3 ( V_50 , V_59 ) ;
}
F_3 ( V_48 & V_60 , V_61 ) ;
F_3 ( V_48 & V_62 , V_63 ) ;
F_3 ( V_49 & V_64 , V_65 ) ;
F_9 ( V_2 . V_24 , L_6 ) ;
}
static int F_15 ( struct V_66 * V_67 )
{
if ( V_67 -> V_68 < V_69 ||
V_67 -> V_68 > V_70 ) {
F_9 ( V_2 . V_24 , L_7 ) ;
return - V_71 ;
}
if ( V_67 -> V_72 < V_73 ||
V_67 -> V_72 > V_74 ) {
F_9 ( V_2 . V_24 , L_8 ) ;
return - V_71 ;
}
if ( V_67 -> V_75 < V_76 ||
V_67 -> V_75 > V_77 ) {
F_9 ( V_2 . V_24 , L_9 ) ;
return - V_71 ;
}
if ( ( V_67 -> V_78 < 0 ) ||
( V_67 -> V_78 > V_79 ) ) {
F_9 ( V_2 . V_24 ,
L_10 ) ;
return - V_71 ;
}
if ( V_67 -> V_80 < V_81 ||
V_67 -> V_80 > V_82 ) {
F_9 ( V_2 . V_24 , L_11 ) ;
return - V_71 ;
}
if ( V_67 -> V_83 . V_84 ) {
if ( V_67 -> V_83 . V_85 < V_86 ||
V_67 -> V_83 . V_85 > V_87 ) {
F_9 ( V_2 . V_24 , L_12 ) ;
return - V_71 ;
}
}
if ( V_67 -> V_88 . V_89 ) {
if ( V_67 -> V_88 . V_90 < V_91 ||
V_67 -> V_88 . V_90 > V_92 ) {
F_9 ( V_2 . V_24 ,
L_13 ) ;
return - V_71 ;
}
if ( V_67 -> V_88 . V_93 < V_94 ||
V_67 -> V_88 . V_93 > V_95 ) {
F_9 ( V_2 . V_24 ,
L_14 ) ;
return - V_71 ;
}
}
return 0 ;
}
static int F_16 ( void T_2 * V_96 )
{
struct V_66 V_97 ;
int V_98 ;
if ( V_2 . V_99 != V_100 )
return - V_71 ;
V_98 = F_17 ( & V_97 , V_96 , sizeof( V_97 ) ) ;
if ( V_98 ) {
F_9 ( V_2 . V_24 , L_15
L_16 , V_98 ) ;
return - V_38 ;
}
if ( ! F_15 ( & V_97 ) ) {
memcpy ( & V_2 . V_11 . V_101 ,
& V_97 ,
sizeof( V_97 ) ) ;
return 0 ;
}
return - V_71 ;
}
static void F_18 ( void )
{
struct V_102 * V_96 = & V_2 . V_103 ;
T_1 V_6 ;
F_9 ( V_2 . V_24 , L_17 ) ;
F_8 () ;
V_6 = ( ( ( V_96 -> V_104 & V_105 ) <<
V_106 ) |
( ( V_96 -> V_44 & V_107 ) <<
V_108 ) ) ;
if ( V_96 -> V_109 ) {
F_3 ( V_110 , V_111 ) ;
V_6 |= V_112 ;
} else {
V_6 |= ( ( ( V_96 -> V_113 & V_114 ) <<
V_115 ) |
( ( V_96 -> V_116 & V_117 ) <<
V_118 ) |
( ( V_96 -> V_119 & V_120 ) <<
V_121 ) ) ;
}
V_6 |= V_122 ;
F_3 ( V_6 , V_27 ) ;
F_14 ( & V_96 -> V_123 , V_96 -> V_44 , 2 ) ;
V_6 = ( V_96 -> V_124 << V_125 ) ;
V_6 |= V_126 | V_127 ;
F_3 ( V_6 , V_128 ) ;
F_3 ( ( ( V_96 -> V_123 . V_52 * 2 + 31 ) >> 5 ) , V_129 ) ;
if ( V_96 -> V_130 == V_131 ) {
F_3 ( V_132 , V_133 ) ;
}
F_9 ( V_2 . V_24 , L_18 ) ;
}
static void F_19 ( struct V_134 * V_135 )
{
T_1 V_4 ;
if ( ! V_135 -> V_89 ) {
F_3 ( V_135 -> V_136 & V_137 , V_138 ) ;
F_3 ( 0x0000 , V_139 ) ;
return;
}
V_4 = ( V_135 -> V_140 & V_141 ) |
( ( V_135 -> V_90 & V_142 ) <<
V_143 ) | V_144 ;
F_3 ( V_4 , V_139 ) ;
V_4 = ( V_135 -> V_93 & V_145 )
<< V_146 ;
F_3 ( V_4 , V_138 ) ;
}
static void F_20 ( struct V_147 * V_148 )
{
T_1 V_4 ;
V_4 = ( V_148 -> V_149 & V_150 ) |
( ( V_148 -> V_151 & V_150 ) <<
V_152 ) ;
F_3 ( V_4 , V_153 ) ;
V_4 = ( ( V_148 -> V_154 & V_150 ) <<
V_155 ) |
( ( V_148 -> V_156 & V_150 ) <<
V_157 ) ;
F_3 ( V_4 , V_158 ) ;
}
int F_21 ( int V_159 , struct V_160 * V_161 )
{
#define F_22 1000
T_1 V_4 , V_162 = F_22 ;
F_3 ( V_161 -> V_163 [ V_159 ] , V_164 ) ;
F_3 ( V_161 -> V_165 [ V_159 ] , V_166 ) ;
F_3 ( V_161 -> V_167 [ V_159 ] , V_168 ) ;
F_3 ( V_161 -> V_169 [ V_159 ] , V_170 ) ;
F_3 ( V_161 -> V_171 [ V_159 ] , V_172 ) ;
V_4 = F_1 ( V_173 ) | V_174 ;
F_3 ( V_4 , V_173 ) ;
while ( F_1 ( V_173 ) & V_174 )
V_162 -- ;
if ( V_162 ) {
F_23 ( V_2 . V_24 , L_19 ) ;
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_160 * V_161 )
{
T_1 V_4 ;
int V_23 ;
V_4 = V_161 -> V_175 & V_176 ;
if ( ! V_161 -> V_177 ) {
F_3 ( V_4 , V_178 ) ;
return 0 ;
}
if ( V_161 -> V_179 > V_180 )
return - V_71 ;
V_4 |= V_181 ;
V_4 |= ( V_161 -> V_182 . V_183 & V_184 ) <<
V_185 ;
V_4 |= ( V_161 -> V_182 . V_186 & V_187 ) <<
V_188 ;
V_4 |= ( V_161 -> V_182 . V_189 & V_190 ) <<
V_191 ;
F_3 ( V_4 , V_178 ) ;
V_4 = V_192 << V_193 ;
for ( V_23 = 0 ; V_23 < V_161 -> V_179 ; V_23 ++ ) {
if ( V_23 != 0 )
V_4 = V_194 ;
F_3 ( V_4 , V_173 ) ;
if ( F_21 ( V_23 , V_161 ) < 0 )
return - V_38 ;
}
F_3 ( V_161 -> V_195 & V_196 , V_197 ) ;
V_4 = F_1 ( V_178 ) | ( V_198 <<
V_199 ) ;
F_3 ( V_4 , V_178 ) ;
return 0 ;
}
static void F_25 ( struct V_200 * V_201 )
{
T_1 V_202 = 0 , V_203 ;
int V_23 ;
if ( ! V_201 -> V_84 )
return;
F_3 ( V_204 , V_205 ) ;
for ( V_23 = 0 ; V_23 < V_206 ; V_23 ++ ) {
if ( ( V_23 % 2 ) == 0 ) {
V_202 = ( V_201 -> V_207 [ V_23 ] . integer &
V_208 )
<< V_209 ;
V_202 |= ( ( ( V_201 -> V_207 [ V_23 ] . V_210 &
V_211 ) *
V_212 ) / 100 ) ;
} else {
V_203 = ( V_201 -> V_207 [ V_23 ] . integer &
V_208 )
<< V_209 ;
V_203 |= ( ( ( V_201 -> V_207 [ V_23 ] . V_210 &
V_211 ) *
V_212 ) / 100 ) ;
V_203 <<= V_213 ;
V_203 |= V_202 ;
F_3 ( V_203 , ( V_214 + ( ( V_23 - 1 ) << 1 ) ) ) ;
}
}
}
static void F_26 ( struct V_215 * V_216 ,
struct V_215 * V_217 )
{
T_1 V_4 ;
V_4 = ( V_216 -> V_218 | ( V_216 -> V_219 << 2 ) | ( V_216 -> V_220 << 4 ) |
( V_216 -> V_221 << 6 ) | ( V_217 -> V_218 << 8 ) | ( V_217 -> V_219 << 10 ) |
( V_217 -> V_220 << 12 ) | ( V_217 -> V_221 << 14 ) ) ;
F_3 ( V_4 , V_222 ) ;
}
static int F_27 ( void )
{
struct V_223 * V_96 = & V_2 . V_11 ;
struct V_66 * V_101 =
& V_2 . V_11 . V_101 ;
unsigned int V_4 ;
F_9 ( V_2 . V_24 , L_20 ) ;
F_8 () ;
F_3 ( V_224 | V_225 |
V_226 | V_227 |
V_228 | V_126 , V_128 ) ;
V_4 = ( V_229 | V_230 | V_231 |
V_232 ) ;
V_4 |= ( ( ( V_96 -> V_119 & V_120 ) << V_121 ) |
( ( V_96 -> V_116 & V_117 ) << V_118 ) |
( ( V_96 -> V_113 & V_114 ) << V_115 ) |
( ( V_96 -> V_44 & V_107 ) << V_108 ) |
( ( V_96 -> V_104 & V_233 ) << V_234 ) ) ;
if ( ( V_101 -> V_80 == V_82 ) ||
V_101 -> V_83 . V_84 )
V_4 |= V_122 ;
if ( V_101 -> V_235 )
V_4 |= ( V_101 -> V_235 & V_236 ) <<
V_237 ;
V_4 |= ( V_101 -> V_68 & V_238 ) <<
V_239 ;
F_3 ( V_4 , V_27 ) ;
F_9 ( V_2 . V_24 , L_21 , V_4 ) ;
F_3 ( ( V_101 -> V_78 ) & V_79 , V_240 ) ;
V_4 = V_241 << V_242 |
V_243 ;
if ( V_101 -> V_83 . V_84 ) {
V_4 |= ( V_244 |
( ( V_101 -> V_83 . V_85 &
V_245 ) <<
V_242 ) ) ;
}
V_4 |= ( ( V_101 -> V_72 << V_246 ) |
( V_101 -> V_75 << V_247 ) ) ;
F_3 ( V_4 , V_248 ) ;
F_9 ( V_2 . V_24 , L_22 , V_4 ) ;
F_14 ( & V_96 -> V_123 , V_96 -> V_44 , 1 ) ;
F_19 ( & V_101 -> V_88 ) ;
F_20 ( & V_101 -> V_249 ) ;
if ( F_24 ( & V_101 -> V_250 ) < 0 )
return - V_38 ;
F_25 ( & V_101 -> V_201 ) ;
F_26 ( & V_101 -> V_251 ,
& V_101 -> V_252 ) ;
F_7 () ;
F_9 ( V_2 . V_24 , L_23 , V_4 ) ;
V_4 = ( V_101 -> V_253 . V_254 & V_255 ) <<
V_256 ;
V_4 |= ( V_101 -> V_253 . V_257 & V_255 ) <<
V_258 ;
F_3 ( V_4 , V_259 ) ;
V_4 = ( V_96 -> V_260 & V_261 ) <<
V_262 ;
if ( ( V_101 -> V_80 == V_82 ) ||
V_101 -> V_83 . V_84 ) {
V_4 |= ( ( ( V_96 -> V_123 . V_52 ) + 31 ) >> 5 ) &
V_263 ;
F_9 ( V_2 . V_24 , L_24 ,
( ( ( V_96 -> V_123 . V_52 ) + 31 ) >> 5 ) &
V_263 ) ;
} else {
V_4 |= ( ( ( V_96 -> V_123 . V_52 * 2 ) + 31 ) >> 5 ) &
V_263 ;
F_9 ( V_2 . V_24 , L_24 ,
( ( ( V_96 -> V_123 . V_52 * 2 ) + 31 ) >> 5 ) &
V_263 ) ;
}
F_3 ( V_4 , V_129 ) ;
if ( V_96 -> V_44 == V_56 ) {
if ( V_96 -> V_264 ) {
F_3 ( V_265 , V_133 ) ;
F_9 ( V_2 . V_24 , L_25 ,
V_265 ) ;
} else {
F_3 ( V_266 , V_133 ) ;
F_9 ( V_2 . V_24 , L_25 ,
V_266 ) ;
}
} else if ( V_96 -> V_44 == V_267 ) {
if ( V_96 -> V_264 ) {
F_3 ( V_268 , V_133 ) ;
F_9 ( V_2 . V_24 , L_25 ,
V_268 ) ;
} else {
F_3 ( V_269 , V_133 ) ;
F_9 ( V_2 . V_24 , L_25 ,
V_269 ) ;
}
}
F_9 ( V_2 . V_24 , L_26 ) ;
return 0 ;
}
static int F_28 ( void )
{
if ( V_2 . V_99 == V_100 )
return F_27 () ;
else
F_18 () ;
return 0 ;
}
static int F_29 ( enum V_270 V_130 )
{
if ( V_2 . V_99 == V_100 )
V_2 . V_11 . V_130 = V_130 ;
else
V_2 . V_103 . V_130 = V_130 ;
return 0 ;
}
static enum V_270 F_30 ( void )
{
if ( V_2 . V_99 == V_100 )
return V_2 . V_11 . V_130 ;
return V_2 . V_103 . V_130 ;
}
static int F_31 ( T_1 * V_271 , int V_23 )
{
int V_272 = - V_71 ;
if ( V_2 . V_99 == V_100 ) {
if ( V_23 < F_32 ( V_273 ) ) {
* V_271 = V_273 [ V_23 ] ;
V_272 = 0 ;
}
} else {
if ( V_23 < F_32 ( V_274 ) ) {
* V_271 = V_274 [ V_23 ] ;
V_272 = 0 ;
}
}
return V_272 ;
}
static int F_33 ( T_1 V_275 )
{
struct V_276 * V_83 = & V_2 . V_11 . V_101 . V_83 ;
if ( V_2 . V_99 == V_100 ) {
V_2 . V_11 . V_104 = V_277 ;
if ( V_275 == V_278 )
V_83 -> V_84 = 1 ;
else if ( V_275 != V_279 )
return - V_71 ;
} else {
if ( V_275 == V_280 )
V_2 . V_103 . V_124 = V_281 ;
else if ( V_275 == V_282 )
V_2 . V_103 . V_124 = V_283 ;
else
return - V_71 ;
}
return 0 ;
}
static T_1 F_34 ( void )
{
struct V_276 * V_83 = & V_2 . V_11 . V_101 . V_83 ;
T_1 V_275 ;
if ( V_2 . V_99 == V_100 )
if ( V_83 -> V_84 )
V_275 = V_278 ;
else
V_275 = V_279 ;
else {
if ( V_2 . V_103 . V_124 == V_281 )
V_275 = V_280 ;
else
V_275 = V_282 ;
}
return V_275 ;
}
static int F_35 ( struct V_41 * V_123 )
{
if ( V_2 . V_99 == V_100 )
V_2 . V_11 . V_123 = * V_123 ;
else
V_2 . V_103 . V_123 = * V_123 ;
return 0 ;
}
static void F_36 ( struct V_41 * V_123 )
{
if ( V_2 . V_99 == V_100 )
* V_123 = V_2 . V_11 . V_123 ;
else
* V_123 = V_2 . V_103 . V_123 ;
}
static unsigned int F_37 ( void )
{
struct V_66 * V_101 =
& V_2 . V_11 . V_101 ;
unsigned int V_284 ;
if ( V_2 . V_99 == V_100 ) {
if ( ( V_101 -> V_83 . V_84 ) ||
( V_101 -> V_80 == V_82 ) )
V_284 = V_2 . V_11 . V_123 . V_52 ;
else
V_284 = V_2 . V_11 . V_123 . V_52 * 2 ;
} else
V_284 = V_2 . V_103 . V_123 . V_52 * 2 ;
return F_38 ( V_284 , 32 ) ;
}
static int F_39 ( enum V_43 V_44 )
{
if ( V_2 . V_99 == V_100 )
V_2 . V_11 . V_44 = V_44 ;
else
V_2 . V_103 . V_44 = V_44 ;
return 0 ;
}
static enum V_43 F_40 ( void )
{
if ( V_2 . V_99 == V_100 )
return V_2 . V_11 . V_44 ;
else
return V_2 . V_103 . V_44 ;
}
static int F_41 ( void )
{
return ( F_1 ( V_27 ) >> 15 ) & 1 ;
}
static inline void F_42 ( unsigned long V_285 )
{
F_3 ( ( V_285 >> 21 ) & 0x007f , V_286 ) ;
F_3 ( ( V_285 >> 5 ) & 0x0ffff , V_287 ) ;
}
static int F_43 ( struct V_288 * V_96 )
{
V_2 . V_99 = V_96 -> V_99 ;
switch ( V_96 -> V_99 ) {
case V_289 :
case V_290 :
case V_291 :
V_2 . V_103 . V_119 = V_96 -> V_292 ;
V_2 . V_103 . V_116 = V_96 -> V_293 ;
break;
default:
return - V_71 ;
}
return 0 ;
}
static int F_44 ( struct V_294 * V_295 )
{
void (* F_45)( void );
struct V_296 * V_297 ;
int V_298 = 0 ;
V_298 = F_46 ( & V_299 ) ;
if ( V_298 < 0 )
return V_298 ;
V_297 = F_47 ( V_295 , V_300 , 0 ) ;
if ( ! V_297 ) {
V_298 = - V_301 ;
goto V_302;
}
V_297 = F_48 ( V_297 -> V_303 , F_49 ( V_297 ) , V_297 -> V_304 ) ;
if ( ! V_297 ) {
V_298 = - V_305 ;
goto V_302;
}
V_2 . V_3 = F_50 ( V_297 -> V_303 , F_49 ( V_297 ) ) ;
if ( ! V_2 . V_3 ) {
V_298 = - V_306 ;
goto V_307;
}
if ( NULL == V_295 -> V_24 . V_308 ) {
V_298 = - V_301 ;
goto V_309;
}
F_45 = V_295 -> V_24 . V_308 ;
F_45 () ;
V_2 . V_24 = & V_295 -> V_24 ;
F_51 ( V_310 L_27 , V_299 . V_304 ) ;
return 0 ;
V_309:
F_52 ( V_2 . V_3 ) ;
V_307:
F_53 ( V_297 -> V_303 , F_49 ( V_297 ) ) ;
V_302:
F_54 ( & V_299 ) ;
return V_298 ;
}
static int F_55 ( struct V_294 * V_295 )
{
struct V_296 * V_297 ;
F_52 ( V_2 . V_3 ) ;
V_297 = F_47 ( V_295 , V_300 , 0 ) ;
if ( V_297 )
F_53 ( V_297 -> V_303 , F_49 ( V_297 ) ) ;
F_54 ( & V_299 ) ;
return 0 ;
}
