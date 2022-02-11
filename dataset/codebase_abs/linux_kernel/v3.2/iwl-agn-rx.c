const char * F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
F_2 ( V_19 ) ;
F_2 ( V_20 ) ;
F_2 ( V_21 ) ;
F_2 ( V_22 ) ;
F_2 ( V_23 ) ;
F_2 ( V_24 ) ;
F_2 ( V_25 ) ;
F_2 ( V_26 ) ;
F_2 ( V_27 ) ;
F_2 ( V_28 ) ;
F_2 ( V_29 ) ;
F_2 ( V_30 ) ;
F_2 ( V_31 ) ;
F_2 ( V_32 ) ;
F_2 ( V_33 ) ;
F_2 ( V_34 ) ;
F_2 ( V_35 ) ;
F_2 ( V_36 ) ;
F_2 ( V_37 ) ;
F_2 ( V_38 ) ;
F_2 ( V_39 ) ;
F_2 ( V_40 ) ;
F_2 ( V_41 ) ;
F_2 ( V_42 ) ;
F_2 ( V_43 ) ;
F_2 ( V_44 ) ;
F_2 ( V_45 ) ;
F_2 ( V_46 ) ;
F_2 ( V_47 ) ;
F_2 ( V_48 ) ;
F_2 ( V_49 ) ;
F_2 ( V_50 ) ;
F_2 ( V_51 ) ;
F_2 ( V_52 ) ;
F_2 ( V_53 ) ;
F_2 ( V_54 ) ;
F_2 ( V_55 ) ;
F_2 ( V_56 ) ;
F_2 ( V_57 ) ;
F_2 ( V_58 ) ;
F_2 ( V_59 ) ;
F_2 ( V_60 ) ;
F_2 ( V_61 ) ;
F_2 ( V_62 ) ;
F_2 ( V_63 ) ;
F_2 ( V_64 ) ;
F_2 ( V_65 ) ;
F_2 ( V_66 ) ;
F_2 ( V_67 ) ;
F_2 ( V_68 ) ;
F_2 ( V_69 ) ;
F_2 ( V_70 ) ;
F_2 ( V_71 ) ;
F_2 ( V_72 ) ;
F_2 ( V_73 ) ;
F_2 ( V_74 ) ;
F_2 ( V_75 ) ;
default:
return L_1 ;
}
}
static int F_3 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
F_5 ( V_77 , L_2
L_3 ,
F_6 ( V_82 -> V_83 . V_84 . V_85 ) ,
F_1 ( V_82 -> V_83 . V_84 . V_86 ) ,
V_82 -> V_83 . V_84 . V_86 ,
F_7 ( V_82 -> V_83 . V_84 . V_87 ) ,
F_6 ( V_82 -> V_83 . V_84 . V_88 ) ) ;
return 0 ;
}
static int F_8 ( struct V_76 * V_77 , struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
struct V_89 * V_90 = & ( V_82 -> V_83 . V_91 ) ;
struct V_92 * V_93 = & V_77 -> V_94 [ V_95 ] ;
struct V_96 * V_97 = ( void * ) & V_93 -> V_98 ;
if ( ! F_9 ( V_99 , & V_77 -> V_100 -> V_101 ) )
return 0 ;
if ( ! F_6 ( V_90 -> V_101 ) && V_90 -> V_102 == V_77 -> V_103 ) {
V_97 -> V_102 = V_90 -> V_102 ;
V_93 -> V_104 . V_102 = V_90 -> V_102 ;
F_10 ( V_77 , L_4 ,
F_7 ( V_90 -> V_102 ) ) ;
F_11 ( V_77 , true ) ;
} else {
F_5 ( V_77 , L_5 ,
F_7 ( V_90 -> V_102 ) ) ;
F_11 ( V_77 , false ) ;
}
return 0 ;
}
static int F_12 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
struct V_105 * V_106 = & ( V_82 -> V_83 . V_107 ) ;
if ( ! V_106 -> V_108 ) {
F_10 ( V_77 ,
L_6 ) ;
return 0 ;
}
memcpy ( & V_77 -> V_109 , V_106 , sizeof( * V_106 ) ) ;
V_77 -> V_110 |= V_111 ;
return 0 ;
}
static int F_13 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
#ifdef F_14
struct V_81 * V_82 = F_4 ( V_79 ) ;
struct V_112 * V_113 = & ( V_82 -> V_83 . V_114 ) ;
F_15 ( V_77 , L_7 ,
V_113 -> V_115 , V_113 -> V_116 ) ;
#endif
return 0 ;
}
static int F_16 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
T_2 T_3 V_117 =
F_6 ( V_82 -> V_118 ) & V_119 ;
F_17 ( V_77 , L_8
L_9 , V_117 ,
F_1 ( V_82 -> V_120 . V_1 ) ) ;
F_18 ( V_77 , V_121 , V_82 -> V_83 . V_122 , V_117 ) ;
return 0 ;
}
static int F_19 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
struct V_123 * V_124 = ( void * ) V_82 -> V_83 . V_122 ;
#ifdef F_14
T_4 V_101 = F_7 ( V_124 -> V_125 . V_101 . V_101 ) ;
T_1 V_126 = F_20 ( V_124 -> V_125 . V_127 ) ;
F_15 ( V_77 , L_10
L_11 ,
V_101 & V_128 ,
V_124 -> V_125 . V_129 ,
F_6 ( V_124 -> V_130 ) ,
F_6 ( V_124 -> V_131 ) ,
F_6 ( V_124 -> V_132 ) , V_126 ) ;
#endif
V_77 -> V_133 = F_6 ( V_124 -> V_130 ) ;
return 0 ;
}
static bool F_21 ( struct V_76 * V_77 ,
struct V_134 * V_135 )
{
int V_136 , V_137 , V_138 ;
struct V_134 * V_139 ;
if ( V_77 -> V_140 )
return true ;
V_139 = & V_77 -> V_141 . V_142 ;
V_136 = F_6 ( V_135 -> V_143 ) -
F_6 ( V_139 -> V_143 ) ;
V_137 = F_6 ( V_135 -> V_144 ) -
F_6 ( V_139 -> V_144 ) ;
if ( V_136 <= 0 || V_137 <= 0 )
return true ;
V_138 = F_6 ( V_135 -> V_145 . V_146 ) -
F_6 ( V_139 -> V_145 . V_146 ) ;
if ( ( V_136 * 100 / V_137 ) < V_147 &&
V_138 > V_148 ) {
F_17 ( V_77 ,
L_12 ,
V_136 , V_137 , V_138 ) ;
#ifdef F_22
F_17 ( V_77 , L_13 ,
V_77 -> V_149 . V_142 . V_150 ) ;
F_17 ( V_77 ,
L_14 ,
V_77 -> V_149 . V_142 . V_151 ) ;
#endif
if ( V_138 >= V_152 )
return false ;
}
return true ;
}
static bool F_23 ( struct V_76 * V_77 ,
struct V_153 * V_154 ,
struct V_155 * V_156 ,
unsigned int V_157 )
{
int V_158 ;
int V_159 = V_77 -> V_160 -> V_161 -> V_162 ;
if ( V_159 == V_163 ) {
F_17 ( V_77 , L_15 ) ;
return true ;
}
V_158 = F_6 ( V_154 -> V_164 ) -
F_6 ( V_77 -> V_141 . V_165 . V_164 ) +
F_6 ( V_156 -> V_164 ) -
F_6 ( V_77 -> V_141 . V_166 . V_164 ) ;
if ( V_158 <= 0 )
return true ;
if ( ( V_158 * 100 / V_157 ) > V_159 ) {
F_17 ( V_77 ,
L_16 ,
V_159 , V_158 , V_157 ) ;
return false ;
}
return true ;
}
static void F_24 ( struct V_76 * V_77 ,
struct V_153 * V_154 ,
struct V_155 * V_156 ,
struct V_134 * V_142 ,
unsigned long V_167 )
{
unsigned int V_157 ;
if ( F_9 ( V_168 , & V_77 -> V_100 -> V_101 ) )
return;
V_157 = F_25 ( V_167 - V_77 -> V_169 ) ;
if ( ! F_26 ( V_77 ) )
return;
if ( V_157 < 99 )
return;
if ( V_170 . V_171 && ! F_21 ( V_77 , V_142 ) ) {
F_5 ( V_77 , L_17 ) ;
if ( ! F_27 ( V_77 , V_172 , false ) )
return;
}
if ( V_170 . V_173 &&
! F_23 ( V_77 , V_154 , V_156 , V_157 ) )
F_27 ( V_77 , V_174 , false ) ;
}
static void F_28 ( struct V_76 * V_77 )
{
struct V_175 * V_176 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 , V_180 , V_181 ;
int V_182 ;
V_176 = & V_77 -> V_141 . V_183 ;
V_179 =
F_6 ( V_176 -> V_184 ) & V_185 ;
V_180 =
F_6 ( V_176 -> V_186 ) & V_185 ;
V_181 =
F_6 ( V_176 -> V_187 ) & V_185 ;
if ( V_179 ) {
V_178 += V_179 ;
V_177 ++ ;
}
if ( V_180 ) {
V_178 += V_180 ;
V_177 ++ ;
}
if ( V_181 ) {
V_178 += V_181 ;
V_177 ++ ;
}
if ( V_177 )
V_182 = ( V_178 / V_177 ) - 107 ;
else
V_182 = V_188 ;
F_29 ( V_77 , L_18 ,
V_179 , V_180 , V_181 ,
V_182 ) ;
}
static void F_30 ( T_5 * V_189 , T_5 * V_135 , T_5 * V_158 ,
T_5 * V_190 , T_5 * V_191 , int V_192 )
{
int V_193 ;
for ( V_193 = 0 ;
V_193 < V_192 / sizeof( T_5 ) ;
V_193 ++ , V_189 ++ , V_135 ++ , V_158 ++ , V_190 ++ , V_191 ++ ) {
if ( F_6 ( * V_135 ) > F_6 ( * V_189 ) ) {
* V_158 = F_31 (
F_6 ( * V_135 ) - F_6 ( * V_189 ) ) ;
F_32 ( V_191 , F_6 ( * V_158 ) ) ;
if ( F_6 ( * V_158 ) > F_6 ( * V_190 ) )
* V_190 = * V_158 ;
}
}
}
static void
F_33 ( struct V_76 * V_77 ,
struct V_194 * V_195 ,
struct V_175 * V_183 ,
struct V_153 * V_165 ,
struct V_155 * V_166 ,
struct V_153 * V_196 ,
struct V_134 * V_142 ,
struct V_197 * V_198 )
{
#define F_34 ( T_6 ) \
accum_stats((__le32 *)&priv->statistics._name, \
(__le32 *)_name, \
(__le32 *)&priv->delta_stats._name, \
(__le32 *)&priv->max_delta_stats._name, \
(__le32 *)&priv->accum_stats._name, \
sizeof(*_name));
F_34 ( V_195 ) ;
F_34 ( V_183 ) ;
F_34 ( V_165 ) ;
F_34 ( V_166 ) ;
F_34 ( V_196 ) ;
F_34 ( V_142 ) ;
if ( V_198 )
F_34 ( V_198 ) ;
#undef F_34
}
static inline void
F_33 ( struct V_76 * V_77 ,
struct V_194 * V_195 ,
struct V_175 * V_183 ,
struct V_153 * V_165 ,
struct V_155 * V_166 ,
struct V_153 * V_196 ,
struct V_134 * V_142 ,
struct V_197 * V_198 )
{
}
static int F_35 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
unsigned long V_167 = V_199 ;
const int V_200 = 60 ;
int V_201 ;
struct V_81 * V_82 = F_4 ( V_79 ) ;
T_2 V_117 = F_6 ( V_82 -> V_118 ) & V_119 ;
T_5 * V_202 ;
struct V_194 * V_195 ;
struct V_175 * V_183 ;
struct V_153 * V_165 ;
struct V_155 * V_166 ;
struct V_153 * V_196 ;
struct V_134 * V_142 ;
struct V_197 * V_198 ;
V_117 -= sizeof( struct V_203 ) ;
F_15 ( V_77 , L_19 ,
V_117 ) ;
if ( V_117 == sizeof( struct V_204 ) ) {
struct V_204 * V_205 ;
V_205 = & V_82 -> V_83 . V_206 ;
V_202 = & V_205 -> V_202 ;
V_195 = & V_205 -> V_207 . V_195 ;
V_183 = & V_205 -> V_208 . V_207 . V_195 ;
V_165 = & V_205 -> V_208 . V_209 ;
V_166 = & V_205 -> V_208 . V_210 ;
V_196 = & V_205 -> V_208 . V_211 ;
V_142 = & V_205 -> V_142 ;
V_198 = & V_205 -> V_207 . V_212 ;
#ifdef F_22
V_77 -> V_141 . V_213 = V_205 -> V_208 . V_207 . V_213 ;
F_32 ( & V_77 -> V_141 . V_214 ,
F_6 ( V_205 -> V_208 . V_207 . V_213 ) ) ;
#endif
} else if ( V_117 == sizeof( struct V_215 ) ) {
struct V_215 * V_205 ;
V_205 = & V_82 -> V_83 . V_205 ;
V_202 = & V_205 -> V_202 ;
V_195 = & V_205 -> V_207 . V_195 ;
V_183 = & V_205 -> V_208 . V_207 ;
V_165 = & V_205 -> V_208 . V_209 ;
V_166 = & V_205 -> V_208 . V_210 ;
V_196 = & V_205 -> V_208 . V_211 ;
V_142 = & V_205 -> V_142 ;
V_198 = NULL ;
} else {
F_36 ( 1 , L_20 ,
V_117 , sizeof( struct V_204 ) ,
sizeof( struct V_215 ) ) ;
return 0 ;
}
V_201 = V_195 -> V_216 != V_77 -> V_141 . V_195 . V_216 ||
( * V_202 & V_217 ) !=
( V_77 -> V_141 . V_202 & V_217 ) ;
F_33 ( V_77 , V_195 , V_183 , V_165 ,
V_166 , V_196 , V_142 , V_198 ) ;
F_24 ( V_77 , V_165 , V_166 , V_142 , V_167 ) ;
V_77 -> V_141 . V_202 = * V_202 ;
memcpy ( & V_77 -> V_141 . V_195 , V_195 , sizeof( * V_195 ) ) ;
memcpy ( & V_77 -> V_141 . V_183 , V_183 , sizeof( * V_183 ) ) ;
memcpy ( & V_77 -> V_141 . V_165 , V_165 , sizeof( * V_165 ) ) ;
memcpy ( & V_77 -> V_141 . V_166 , V_166 , sizeof( * V_166 ) ) ;
memcpy ( & V_77 -> V_141 . V_196 , V_196 , sizeof( * V_196 ) ) ;
memcpy ( & V_77 -> V_141 . V_142 , V_142 , sizeof( * V_142 ) ) ;
#ifdef F_22
if ( V_198 )
memcpy ( & V_77 -> V_141 . V_198 , V_198 ,
sizeof( * V_198 ) ) ;
#endif
V_77 -> V_169 = V_167 ;
F_37 ( V_218 , & V_77 -> V_100 -> V_101 ) ;
F_38 ( & V_77 -> V_219 , V_199 +
F_39 ( V_200 * 1000 ) ) ;
if ( F_40 ( ! F_9 ( V_220 , & V_77 -> V_100 -> V_101 ) ) &&
( V_82 -> V_120 . V_1 == V_41 ) ) {
F_28 ( V_77 ) ;
F_41 ( V_77 -> V_100 -> V_221 , & V_77 -> V_222 ) ;
}
if ( V_77 -> V_160 -> V_223 -> V_216 && V_201 )
V_77 -> V_160 -> V_223 -> V_216 ( V_77 ) ;
return 0 ;
}
static int F_42 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
if ( F_6 ( V_82 -> V_83 . V_205 . V_202 ) & V_224 ) {
#ifdef F_22
memset ( & V_77 -> F_30 , 0 ,
sizeof( V_77 -> F_30 ) ) ;
memset ( & V_77 -> V_149 , 0 ,
sizeof( V_77 -> V_149 ) ) ;
memset ( & V_77 -> V_225 , 0 ,
sizeof( V_77 -> V_225 ) ) ;
#endif
F_15 ( V_77 , L_21 ) ;
}
F_35 ( V_77 , V_79 , V_1 ) ;
return 0 ;
}
static int F_43 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
T_2 V_226 = F_6 ( V_82 -> V_83 . V_227 . V_226 ) ;
unsigned long V_101 = V_77 -> V_100 -> V_101 ;
F_44 ( V_77 , L_22 ,
( V_226 & V_228 ) ? L_23 : L_24 ,
( V_226 & V_229 ) ? L_23 : L_24 ,
( V_226 & V_230 ) ?
L_25 : L_26 ) ;
if ( V_226 & ( V_229 | V_228 |
V_230 ) ) {
F_45 ( F_46 ( V_77 ) , V_231 ,
V_232 ) ;
F_47 ( F_46 ( V_77 ) , V_233 ,
V_234 ) ;
if ( ! ( V_226 & V_235 ) ) {
F_45 ( F_46 ( V_77 ) , V_236 ,
V_232 ) ;
F_47 ( F_46 ( V_77 ) , V_233 ,
V_234 ) ;
}
if ( V_226 & V_230 )
F_48 ( V_77 ) ;
}
if ( ! ( V_226 & V_230 ) )
F_49 ( V_77 ) ;
if ( V_226 & V_228 )
F_37 ( V_237 , & V_77 -> V_100 -> V_101 ) ;
else
F_50 ( V_237 , & V_77 -> V_100 -> V_101 ) ;
if ( ! ( V_226 & V_235 ) )
F_51 ( V_77 ) ;
if ( ( F_9 ( V_237 , & V_101 ) !=
F_9 ( V_237 , & V_77 -> V_100 -> V_101 ) ) )
F_52 ( V_77 -> V_238 -> V_239 ,
F_9 ( V_237 , & V_77 -> V_100 -> V_101 ) ) ;
else
F_53 ( & V_77 -> V_100 -> V_240 ) ;
return 0 ;
}
static int F_54 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
struct V_241 * V_242 ;
V_242 = & V_82 -> V_83 . V_242 ;
if ( F_6 ( V_242 -> V_243 ) >
V_77 -> V_244 ) {
F_29 ( V_77 ,
L_27 ,
F_6 ( V_242 -> V_243 ) ,
F_6 ( V_242 -> V_245 ) ,
F_6 ( V_242 -> V_246 ) ,
F_6 ( V_242 -> V_247 ) ) ;
if ( ! F_9 ( V_220 , & V_77 -> V_100 -> V_101 ) )
F_55 ( V_77 ) ;
}
return 0 ;
}
static int F_56 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
V_77 -> V_248 = true ;
memcpy ( & V_77 -> V_249 , V_82 -> V_83 . V_122 ,
sizeof( struct V_250 ) ) ;
return 0 ;
}
static int F_57 ( struct V_76 * V_77 ,
struct V_251 * V_120 ,
T_2 V_252 ,
struct V_253 * V_205 )
{
T_4 V_254 = F_7 ( V_120 -> V_255 ) ;
if ( V_77 -> V_94 [ V_95 ] . V_98 . V_256 &
V_257 )
return 0 ;
if ( ! ( V_254 & V_258 ) )
return 0 ;
F_15 ( V_77 , L_28 , V_252 ) ;
switch ( V_252 & V_259 ) {
case V_260 :
if ( ( V_252 & V_261 ) ==
V_262 )
break;
case V_263 :
if ( ( V_252 & V_261 ) ==
V_264 ) {
F_15 ( V_77 , L_29 ) ;
return - 1 ;
}
case V_265 :
if ( ( V_252 & V_261 ) ==
V_266 ) {
F_15 ( V_77 , L_30 ) ;
V_205 -> V_202 |= V_267 ;
}
break;
default:
break;
}
return 0 ;
}
static void F_58 ( struct V_76 * V_77 ,
struct V_251 * V_120 ,
T_4 V_117 ,
T_2 V_268 ,
struct V_78 * V_79 ,
struct V_253 * V_205 )
{
struct V_269 * V_270 ;
T_7 V_254 = V_120 -> V_255 ;
struct V_92 * V_93 ;
if ( F_40 ( ! V_77 -> V_271 ) ) {
F_59 ( V_77 ,
L_31 ) ;
return;
}
if ( ! V_170 . V_272 &&
F_57 ( V_77 , V_120 , V_268 , V_205 ) )
return;
V_270 = F_60 ( 128 ) ;
if ( ! V_270 ) {
F_5 ( V_77 , L_32 ) ;
return;
}
F_61 ( V_270 , 0 , V_79 -> V_273 , ( void * ) V_120 - F_4 ( V_79 ) , V_117 ) ;
F_62 ( V_77 , false , V_254 , V_117 ) ;
if ( F_40 ( F_63 ( V_254 ) ) ) {
F_64 (priv, ctx) {
if ( ! V_93 -> V_274 )
continue;
if ( F_65 ( V_120 -> V_275 ,
V_93 -> V_98 . V_276 ) )
continue;
V_93 -> V_274 = false ;
F_66 ( F_67 ( V_77 ) , V_93 -> V_277 ) ;
}
}
memcpy ( F_68 ( V_270 ) , V_205 , sizeof( * V_205 ) ) ;
F_69 ( V_77 -> V_238 , V_270 ) ;
V_79 -> V_273 = NULL ;
}
static T_2 F_70 ( struct V_76 * V_77 , T_2 V_278 )
{
T_2 V_279 = 0 ;
if ( ( V_278 & V_280 ) ==
V_280 )
V_279 |= ( V_280 |
V_281 ) ;
V_279 |= ( V_278 & V_259 ) ;
if ( ( V_278 & V_259 ) ==
V_282 )
return V_279 ;
if ( ( V_278 & V_259 ) ==
V_283 )
return V_279 ;
if ( ( V_278 & V_284 ) !=
V_284 )
return V_279 ;
switch ( V_278 & V_259 ) {
case V_265 :
if ( ! ( V_278 & V_285 ) )
V_279 |= V_264 ;
else
V_279 |= V_266 ;
break;
case V_260 :
if ( ! ( V_278 & V_286 ) ) {
V_279 |= V_262 ;
break;
}
default:
if ( ! ( V_278 & V_287 ) )
V_279 |= V_264 ;
else
V_279 |= V_266 ;
break;
}
F_15 ( V_77 , L_33 ,
V_278 , V_279 ) ;
return V_279 ;
}
static int F_71 ( struct V_76 * V_77 ,
struct V_250 * V_288 )
{
struct V_289 * V_290 =
(struct V_289 * ) V_288 -> V_291 ;
T_2 V_292 , V_293 , V_294 , V_295 , V_296 ;
T_1 V_297 ;
V_292 = F_6 ( V_290 -> V_298 [ V_299 ] ) ;
V_297 = ( V_292 & V_300 ) >> V_301 ;
V_292 = F_6 ( V_290 -> V_298 [ V_302 ] ) ;
V_293 = ( V_292 & V_303 ) >>
V_304 ;
V_294 = ( V_292 & V_305 ) >>
V_306 ;
V_292 = F_6 ( V_290 -> V_298 [ V_307 ] ) ;
V_295 = ( V_292 & V_308 ) >>
V_309 ;
V_296 = F_72 ( T_2 , V_293 , V_294 ) ;
V_296 = F_72 ( T_2 , V_296 , V_295 ) ;
F_73 ( V_77 , L_34 ,
V_293 , V_294 , V_295 , V_296 , V_297 ) ;
return V_296 - V_297 - V_310 ;
}
static int F_74 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_251 * V_311 ;
struct V_253 V_312 ;
struct V_81 * V_82 = F_4 ( V_79 ) ;
struct V_250 * V_313 ;
T_5 V_314 ;
struct V_315 * V_316 ;
T_2 V_117 ;
T_2 V_268 ;
T_2 V_127 ;
if ( V_82 -> V_120 . V_1 == V_50 ) {
V_313 = (struct V_250 * ) V_82 -> V_83 . V_122 ;
V_311 = (struct V_251 * ) ( V_82 -> V_83 . V_122 + sizeof( * V_313 )
+ V_313 -> V_317 ) ;
V_117 = F_7 ( V_313 -> V_318 ) ;
V_314 = * ( T_5 * ) ( V_82 -> V_83 . V_122 + sizeof( * V_313 ) +
V_313 -> V_317 + V_117 ) ;
V_268 = F_6 ( V_314 ) ;
} else {
if ( ! V_77 -> V_248 ) {
F_5 ( V_77 , L_35 ) ;
return 0 ;
}
V_313 = & V_77 -> V_249 ;
V_316 = (struct V_315 * ) V_82 -> V_83 . V_122 ;
V_311 = (struct V_251 * ) ( V_82 -> V_83 . V_122 + sizeof( * V_316 ) ) ;
V_117 = F_7 ( V_316 -> V_318 ) ;
V_314 = * ( T_5 * ) ( V_82 -> V_83 . V_122 + sizeof( * V_316 ) + V_117 ) ;
V_268 = F_70 ( V_77 ,
F_6 ( V_314 ) ) ;
}
if ( ( F_40 ( V_313 -> V_317 > 20 ) ) ) {
F_75 ( V_77 , L_36 ,
V_313 -> V_317 ) ;
return 0 ;
}
if ( ! ( V_314 & V_319 ) ||
! ( V_314 & V_320 ) ) {
F_15 ( V_77 , L_37 ,
F_6 ( V_314 ) ) ;
return 0 ;
}
V_127 = F_6 ( V_313 -> V_127 ) ;
V_312 . V_321 = F_76 ( V_313 -> V_322 ) ;
V_312 . V_323 = ( V_313 -> V_324 & V_325 ) ?
V_326 : V_327 ;
V_312 . V_328 =
F_77 ( F_7 ( V_313 -> V_102 ) ,
V_312 . V_323 ) ;
V_312 . V_329 =
F_78 ( V_127 , V_312 . V_323 ) ;
V_312 . V_202 = 0 ;
V_77 -> V_330 = F_6 ( V_313 -> V_331 ) ;
V_312 . signal = F_71 ( V_77 , V_313 ) ;
F_79 ( V_77 , V_117 , V_311 ) ;
F_80 ( V_77 , L_38 ,
V_312 . signal , ( unsigned long long ) V_312 . V_321 ) ;
V_312 . V_332 =
( F_7 ( V_313 -> V_324 ) & V_333 )
>> V_334 ;
if ( V_313 -> V_324 & V_335 )
V_312 . V_202 |= V_336 ;
if ( V_127 & V_337 )
V_312 . V_202 |= V_338 ;
if ( V_127 & V_339 )
V_312 . V_202 |= V_340 ;
if ( V_127 & V_341 )
V_312 . V_202 |= V_342 ;
F_58 ( V_77 , V_311 , V_117 , V_268 ,
V_79 , & V_312 ) ;
return 0 ;
}
void F_81 ( struct V_76 * V_77 )
{
int (* * F_82)( struct V_76 * V_77 , struct V_78 * V_79 ,
struct V_80 * V_1 );
F_82 = V_77 -> V_343 ;
F_82 [ V_3 ] = F_3 ;
F_82 [ V_22 ] = F_8 ;
F_82 [ V_24 ] =
F_12 ;
F_82 [ V_26 ] = F_13 ;
F_82 [ V_27 ] =
F_16 ;
F_82 [ V_33 ] = F_19 ;
F_82 [ V_9 ] = V_344 ;
F_82 [ V_40 ] = F_42 ;
F_82 [ V_41 ] = F_35 ;
F_83 ( V_77 ) ;
F_82 [ V_43 ] = F_43 ;
F_82 [ V_44 ] =
F_54 ;
F_82 [ V_48 ] = F_56 ;
F_82 [ V_49 ] = F_74 ;
F_82 [ V_51 ] =
V_345 ;
V_77 -> V_343 [ V_53 ] =
V_346 ;
V_77 -> V_343 [ V_14 ] = V_347 ;
F_84 ( & V_77 -> V_348 ) ;
F_85 ( & V_77 -> V_349 ) ;
F_86 ( & V_77 -> V_350 ) ;
if ( V_77 -> V_160 -> V_223 -> V_351 )
V_77 -> V_160 -> V_223 -> V_351 ( V_77 ) ;
}
int F_87 ( struct V_76 * V_77 , struct V_78 * V_79 ,
struct V_80 * V_1 )
{
struct V_81 * V_82 = F_4 ( V_79 ) ;
int V_352 = 0 ;
if ( ! F_88 ( & V_77 -> V_349 ) ) {
struct V_353 * V_354 ;
F_89 ( & V_77 -> V_348 ) ;
F_90 (w, &priv->notif_waits, list) {
if ( V_354 -> V_1 != V_82 -> V_120 . V_1 )
continue;
F_15 ( V_77 ,
L_39 ,
F_1 ( V_82 -> V_120 . V_1 ) ,
V_82 -> V_120 . V_1 ) ;
V_354 -> V_355 = true ;
if ( V_354 -> V_356 )
V_354 -> V_356 ( V_77 , V_82 , V_354 -> V_357 ) ;
}
F_91 ( & V_77 -> V_348 ) ;
F_92 ( & V_77 -> V_350 ) ;
}
if ( V_77 -> V_358 )
V_77 -> V_358 ( V_77 , V_79 ) ;
if ( V_77 -> V_343 [ V_82 -> V_120 . V_1 ] ) {
V_77 -> V_359 [ V_82 -> V_120 . V_1 ] ++ ;
V_352 = V_77 -> V_343 [ V_82 -> V_120 . V_1 ] ( V_77 , V_79 , V_1 ) ;
} else {
F_15 ( V_77 ,
L_40 ,
F_1 ( V_82 -> V_120 . V_1 ) , V_82 -> V_120 . V_1 ) ;
}
return V_352 ;
}
