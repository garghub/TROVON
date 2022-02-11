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
F_2 ( V_76 ) ;
default:
return L_1 ;
}
}
static int F_3 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
F_5 ( V_78 , L_2
L_3 ,
F_6 ( V_83 -> V_84 . V_85 . V_86 ) ,
F_1 ( V_83 -> V_84 . V_85 . V_87 ) ,
V_83 -> V_84 . V_85 . V_87 ,
F_7 ( V_83 -> V_84 . V_85 . V_88 ) ,
F_6 ( V_83 -> V_84 . V_85 . V_89 ) ) ;
return 0 ;
}
static int F_8 ( struct V_77 * V_78 , struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_90 * V_91 = & ( V_83 -> V_84 . V_92 ) ;
struct V_93 * V_94 = & V_78 -> V_95 [ V_96 ] ;
struct V_97 * V_98 = ( void * ) & V_94 -> V_99 ;
if ( ! F_9 ( V_100 , & V_78 -> V_101 -> V_102 ) )
return 0 ;
if ( ! F_6 ( V_91 -> V_102 ) && V_91 -> V_103 == V_78 -> V_104 ) {
V_98 -> V_103 = V_91 -> V_103 ;
V_94 -> V_105 . V_103 = V_91 -> V_103 ;
F_10 ( V_78 , L_4 ,
F_7 ( V_91 -> V_103 ) ) ;
F_11 ( V_78 , true ) ;
} else {
F_5 ( V_78 , L_5 ,
F_7 ( V_91 -> V_103 ) ) ;
F_11 ( V_78 , false ) ;
}
return 0 ;
}
static int F_12 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_106 * V_107 = & ( V_83 -> V_84 . V_108 ) ;
if ( ! V_107 -> V_109 ) {
F_10 ( V_78 ,
L_6 ) ;
return 0 ;
}
memcpy ( & V_78 -> V_110 , V_107 , sizeof( * V_107 ) ) ;
V_78 -> V_111 |= V_112 ;
return 0 ;
}
static int F_13 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
#ifdef F_14
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_113 * V_114 = & ( V_83 -> V_84 . V_115 ) ;
F_15 ( V_78 , L_7 ,
V_114 -> V_116 , V_114 -> V_117 ) ;
#endif
return 0 ;
}
static int F_16 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
T_2 T_3 V_118 =
F_6 ( V_83 -> V_119 ) & V_120 ;
F_17 ( V_78 , L_8
L_9 , V_118 ,
F_1 ( V_83 -> V_121 . V_1 ) ) ;
F_18 ( V_78 , V_122 , V_83 -> V_84 . V_123 , V_118 ) ;
return 0 ;
}
static int F_19 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_124 * V_125 = ( void * ) V_83 -> V_84 . V_123 ;
#ifdef F_14
T_4 V_102 = F_7 ( V_125 -> V_126 . V_102 . V_102 ) ;
T_1 V_127 = F_20 ( V_125 -> V_126 . V_128 ) ;
F_15 ( V_78 , L_10
L_11 ,
V_102 & V_129 ,
V_125 -> V_126 . V_130 ,
F_6 ( V_125 -> V_131 ) ,
F_6 ( V_125 -> V_132 ) ,
F_6 ( V_125 -> V_133 ) , V_127 ) ;
#endif
V_78 -> V_134 = F_6 ( V_125 -> V_131 ) ;
return 0 ;
}
static bool F_21 ( struct V_77 * V_78 ,
struct V_135 * V_136 )
{
int V_137 , V_138 , V_139 ;
struct V_135 * V_140 ;
if ( V_78 -> V_141 )
return true ;
V_140 = & V_78 -> V_142 . V_143 ;
V_137 = F_6 ( V_136 -> V_144 ) -
F_6 ( V_140 -> V_144 ) ;
V_138 = F_6 ( V_136 -> V_145 ) -
F_6 ( V_140 -> V_145 ) ;
if ( V_137 <= 0 || V_138 <= 0 )
return true ;
V_139 = F_6 ( V_136 -> V_146 . V_147 ) -
F_6 ( V_140 -> V_146 . V_147 ) ;
if ( ( V_137 * 100 / V_138 ) < V_148 &&
V_139 > V_149 ) {
F_17 ( V_78 ,
L_12 ,
V_137 , V_138 , V_139 ) ;
#ifdef F_22
F_17 ( V_78 , L_13 ,
V_78 -> V_150 . V_143 . V_151 ) ;
F_17 ( V_78 ,
L_14 ,
V_78 -> V_150 . V_143 . V_152 ) ;
#endif
if ( V_139 >= V_153 )
return false ;
}
return true ;
}
static bool F_23 ( struct V_77 * V_78 ,
struct V_154 * V_155 ,
struct V_156 * V_157 ,
unsigned int V_158 )
{
int V_159 ;
int V_160 = F_24 ( V_78 ) -> V_161 -> V_162 ;
if ( V_160 == V_163 ) {
F_17 ( V_78 , L_15 ) ;
return true ;
}
V_159 = F_6 ( V_155 -> V_164 ) -
F_6 ( V_78 -> V_142 . V_165 . V_164 ) +
F_6 ( V_157 -> V_164 ) -
F_6 ( V_78 -> V_142 . V_166 . V_164 ) ;
if ( V_159 <= 0 )
return true ;
if ( ( V_159 * 100 / V_158 ) > V_160 ) {
F_17 ( V_78 ,
L_16 ,
V_160 , V_159 , V_158 ) ;
return false ;
}
return true ;
}
static void F_25 ( struct V_77 * V_78 ,
struct V_154 * V_155 ,
struct V_156 * V_157 ,
struct V_135 * V_143 ,
unsigned long V_167 )
{
unsigned int V_158 ;
if ( F_9 ( V_168 , & V_78 -> V_101 -> V_102 ) )
return;
V_158 = F_26 ( V_167 - V_78 -> V_169 ) ;
if ( ! F_27 ( V_78 ) )
return;
if ( V_158 < 99 )
return;
if ( V_170 . V_171 && ! F_21 ( V_78 , V_143 ) ) {
F_5 ( V_78 , L_17 ) ;
if ( ! F_28 ( V_78 , V_172 , false ) )
return;
}
if ( V_170 . V_173 &&
! F_23 ( V_78 , V_155 , V_157 , V_158 ) )
F_28 ( V_78 , V_174 , false ) ;
}
static void F_29 ( struct V_77 * V_78 )
{
struct V_175 * V_176 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 , V_180 , V_181 ;
int V_182 ;
V_176 = & V_78 -> V_142 . V_183 ;
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
F_30 ( V_78 , L_18 ,
V_179 , V_180 , V_181 ,
V_182 ) ;
}
static void F_31 ( T_5 * V_189 , T_5 * V_136 , T_5 * V_159 ,
T_5 * V_190 , T_5 * V_191 , int V_192 )
{
int V_193 ;
for ( V_193 = 0 ;
V_193 < V_192 / sizeof( T_5 ) ;
V_193 ++ , V_189 ++ , V_136 ++ , V_159 ++ , V_190 ++ , V_191 ++ ) {
if ( F_6 ( * V_136 ) > F_6 ( * V_189 ) ) {
* V_159 = F_32 (
F_6 ( * V_136 ) - F_6 ( * V_189 ) ) ;
F_33 ( V_191 , F_6 ( * V_159 ) ) ;
if ( F_6 ( * V_159 ) > F_6 ( * V_190 ) )
* V_190 = * V_159 ;
}
}
}
static void
F_34 ( struct V_77 * V_78 ,
struct V_194 * V_195 ,
struct V_175 * V_183 ,
struct V_154 * V_165 ,
struct V_156 * V_166 ,
struct V_154 * V_196 ,
struct V_135 * V_143 ,
struct V_197 * V_198 )
{
#define F_35 ( T_6 ) \
accum_stats((__le32 *)&priv->statistics._name, \
(__le32 *)_name, \
(__le32 *)&priv->delta_stats._name, \
(__le32 *)&priv->max_delta_stats._name, \
(__le32 *)&priv->accum_stats._name, \
sizeof(*_name));
F_35 ( V_195 ) ;
F_35 ( V_183 ) ;
F_35 ( V_165 ) ;
F_35 ( V_166 ) ;
F_35 ( V_196 ) ;
F_35 ( V_143 ) ;
if ( V_198 )
F_35 ( V_198 ) ;
#undef F_35
}
static inline void
F_34 ( struct V_77 * V_78 ,
struct V_194 * V_195 ,
struct V_175 * V_183 ,
struct V_154 * V_165 ,
struct V_156 * V_166 ,
struct V_154 * V_196 ,
struct V_135 * V_143 ,
struct V_197 * V_198 )
{
}
static int F_36 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
unsigned long V_167 = V_199 ;
const int V_200 = 60 ;
int V_201 ;
struct V_82 * V_83 = F_4 ( V_80 ) ;
T_2 V_118 = F_6 ( V_83 -> V_119 ) & V_120 ;
T_5 * V_202 ;
struct V_194 * V_195 ;
struct V_175 * V_183 ;
struct V_154 * V_165 ;
struct V_156 * V_166 ;
struct V_154 * V_196 ;
struct V_135 * V_143 ;
struct V_197 * V_198 ;
V_118 -= sizeof( struct V_203 ) ;
F_15 ( V_78 , L_19 ,
V_118 ) ;
if ( V_118 == sizeof( struct V_204 ) ) {
struct V_204 * V_205 ;
V_205 = & V_83 -> V_84 . V_206 ;
V_202 = & V_205 -> V_202 ;
V_195 = & V_205 -> V_207 . V_195 ;
V_183 = & V_205 -> V_208 . V_207 . V_195 ;
V_165 = & V_205 -> V_208 . V_209 ;
V_166 = & V_205 -> V_208 . V_210 ;
V_196 = & V_205 -> V_208 . V_211 ;
V_143 = & V_205 -> V_143 ;
V_198 = & V_205 -> V_207 . V_212 ;
#ifdef F_22
V_78 -> V_142 . V_213 = V_205 -> V_208 . V_207 . V_213 ;
F_33 ( & V_78 -> V_142 . V_214 ,
F_6 ( V_205 -> V_208 . V_207 . V_213 ) ) ;
#endif
} else if ( V_118 == sizeof( struct V_215 ) ) {
struct V_215 * V_205 ;
V_205 = & V_83 -> V_84 . V_205 ;
V_202 = & V_205 -> V_202 ;
V_195 = & V_205 -> V_207 . V_195 ;
V_183 = & V_205 -> V_208 . V_207 ;
V_165 = & V_205 -> V_208 . V_209 ;
V_166 = & V_205 -> V_208 . V_210 ;
V_196 = & V_205 -> V_208 . V_211 ;
V_143 = & V_205 -> V_143 ;
V_198 = NULL ;
} else {
F_37 ( 1 , L_20 ,
V_118 , sizeof( struct V_204 ) ,
sizeof( struct V_215 ) ) ;
return 0 ;
}
V_201 = V_195 -> V_216 != V_78 -> V_142 . V_195 . V_216 ||
( * V_202 & V_217 ) !=
( V_78 -> V_142 . V_202 & V_217 ) ;
F_34 ( V_78 , V_195 , V_183 , V_165 ,
V_166 , V_196 , V_143 , V_198 ) ;
F_25 ( V_78 , V_165 , V_166 , V_143 , V_167 ) ;
V_78 -> V_142 . V_202 = * V_202 ;
memcpy ( & V_78 -> V_142 . V_195 , V_195 , sizeof( * V_195 ) ) ;
memcpy ( & V_78 -> V_142 . V_183 , V_183 , sizeof( * V_183 ) ) ;
memcpy ( & V_78 -> V_142 . V_165 , V_165 , sizeof( * V_165 ) ) ;
memcpy ( & V_78 -> V_142 . V_166 , V_166 , sizeof( * V_166 ) ) ;
memcpy ( & V_78 -> V_142 . V_196 , V_196 , sizeof( * V_196 ) ) ;
memcpy ( & V_78 -> V_142 . V_143 , V_143 , sizeof( * V_143 ) ) ;
#ifdef F_22
if ( V_198 )
memcpy ( & V_78 -> V_142 . V_198 , V_198 ,
sizeof( * V_198 ) ) ;
#endif
V_78 -> V_169 = V_167 ;
F_38 ( V_218 , & V_78 -> V_101 -> V_102 ) ;
F_39 ( & V_78 -> V_219 , V_199 +
F_40 ( V_200 * 1000 ) ) ;
if ( F_41 ( ! F_9 ( V_220 , & V_78 -> V_101 -> V_102 ) ) &&
( V_83 -> V_121 . V_1 == V_41 ) ) {
F_29 ( V_78 ) ;
F_42 ( V_78 -> V_101 -> V_221 , & V_78 -> V_222 ) ;
}
if ( F_24 ( V_78 ) -> V_223 -> V_216 && V_201 )
F_24 ( V_78 ) -> V_223 -> V_216 ( V_78 ) ;
return 0 ;
}
static int F_43 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
if ( F_6 ( V_83 -> V_84 . V_205 . V_202 ) & V_224 ) {
#ifdef F_22
memset ( & V_78 -> F_31 , 0 ,
sizeof( V_78 -> F_31 ) ) ;
memset ( & V_78 -> V_150 , 0 ,
sizeof( V_78 -> V_150 ) ) ;
memset ( & V_78 -> V_225 , 0 ,
sizeof( V_78 -> V_225 ) ) ;
#endif
F_15 ( V_78 , L_21 ) ;
}
F_36 ( V_78 , V_80 , V_1 ) ;
return 0 ;
}
static int F_44 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
T_2 V_226 = F_6 ( V_83 -> V_84 . V_227 . V_226 ) ;
unsigned long V_102 = V_78 -> V_101 -> V_102 ;
F_45 ( V_78 , L_22 ,
( V_226 & V_228 ) ? L_23 : L_24 ,
( V_226 & V_229 ) ? L_23 : L_24 ,
( V_226 & V_230 ) ?
L_25 : L_26 ) ;
if ( V_226 & ( V_229 | V_228 |
V_230 ) ) {
F_46 ( F_47 ( V_78 ) , V_231 ,
V_232 ) ;
F_48 ( F_47 ( V_78 ) , V_233 ,
V_234 ) ;
if ( ! ( V_226 & V_235 ) ) {
F_46 ( F_47 ( V_78 ) , V_236 ,
V_232 ) ;
F_48 ( F_47 ( V_78 ) , V_233 ,
V_234 ) ;
}
if ( V_226 & V_230 )
F_49 ( V_78 ) ;
}
if ( ! ( V_226 & V_230 ) )
F_50 ( V_78 ) ;
if ( V_226 & V_228 )
F_38 ( V_237 , & V_78 -> V_101 -> V_102 ) ;
else
F_51 ( V_237 , & V_78 -> V_101 -> V_102 ) ;
if ( ! ( V_226 & V_235 ) )
F_52 ( V_78 ) ;
if ( ( F_9 ( V_237 , & V_102 ) !=
F_9 ( V_237 , & V_78 -> V_101 -> V_102 ) ) )
F_53 ( V_78 -> V_238 -> V_239 ,
F_9 ( V_237 , & V_78 -> V_101 -> V_102 ) ) ;
else
F_54 ( & V_78 -> V_101 -> V_240 ) ;
return 0 ;
}
static int F_55 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_241 * V_242 ;
V_242 = & V_83 -> V_84 . V_242 ;
if ( F_6 ( V_242 -> V_243 ) >
V_78 -> V_244 ) {
F_30 ( V_78 ,
L_27 ,
F_6 ( V_242 -> V_243 ) ,
F_6 ( V_242 -> V_245 ) ,
F_6 ( V_242 -> V_246 ) ,
F_6 ( V_242 -> V_247 ) ) ;
if ( ! F_9 ( V_220 , & V_78 -> V_101 -> V_102 ) )
F_56 ( V_78 ) ;
}
return 0 ;
}
static int F_57 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
V_78 -> V_248 = true ;
memcpy ( & V_78 -> V_249 , V_83 -> V_84 . V_123 ,
sizeof( struct V_250 ) ) ;
return 0 ;
}
static int F_58 ( struct V_77 * V_78 ,
struct V_251 * V_121 ,
T_2 V_252 ,
struct V_253 * V_205 )
{
T_4 V_254 = F_7 ( V_121 -> V_255 ) ;
if ( V_78 -> V_95 [ V_96 ] . V_99 . V_256 &
V_257 )
return 0 ;
if ( ! ( V_254 & V_258 ) )
return 0 ;
F_15 ( V_78 , L_28 , V_252 ) ;
switch ( V_252 & V_259 ) {
case V_260 :
if ( ( V_252 & V_261 ) ==
V_262 )
break;
case V_263 :
if ( ( V_252 & V_261 ) ==
V_264 ) {
F_15 ( V_78 , L_29 ) ;
return - 1 ;
}
case V_265 :
if ( ( V_252 & V_261 ) ==
V_266 ) {
F_15 ( V_78 , L_30 ) ;
V_205 -> V_202 |= V_267 ;
}
break;
default:
break;
}
return 0 ;
}
static void F_59 ( struct V_77 * V_78 ,
struct V_251 * V_121 ,
T_4 V_118 ,
T_2 V_268 ,
struct V_79 * V_80 ,
struct V_253 * V_205 )
{
struct V_269 * V_270 ;
T_7 V_254 = V_121 -> V_255 ;
struct V_93 * V_94 ;
if ( F_41 ( ! V_78 -> V_271 ) ) {
F_60 ( V_78 ,
L_31 ) ;
return;
}
if ( ! V_170 . V_272 &&
F_58 ( V_78 , V_121 , V_268 , V_205 ) )
return;
V_270 = F_61 ( 128 ) ;
if ( ! V_270 ) {
F_5 ( V_78 , L_32 ) ;
return;
}
F_62 ( V_270 , 0 , V_80 -> V_273 , ( void * ) V_121 - F_4 ( V_80 ) , V_118 ) ;
F_63 ( V_78 , false , V_254 , V_118 ) ;
if ( F_41 ( F_64 ( V_254 ) ) ) {
F_65 (priv, ctx) {
if ( ! V_94 -> V_274 )
continue;
if ( F_66 ( V_121 -> V_275 ,
V_94 -> V_99 . V_276 ) )
continue;
V_94 -> V_274 = false ;
F_67 ( F_68 ( V_78 ) , V_94 -> V_277 ,
L_33 ) ;
}
}
memcpy ( F_69 ( V_270 ) , V_205 , sizeof( * V_205 ) ) ;
F_70 ( V_78 -> V_238 , V_270 ) ;
V_80 -> V_273 = NULL ;
}
static T_2 F_71 ( struct V_77 * V_78 , T_2 V_278 )
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
F_15 ( V_78 , L_34 ,
V_278 , V_279 ) ;
return V_279 ;
}
static int F_72 ( struct V_77 * V_78 ,
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
V_296 = F_73 ( T_2 , V_293 , V_294 ) ;
V_296 = F_73 ( T_2 , V_296 , V_295 ) ;
F_74 ( V_78 , L_35 ,
V_293 , V_294 , V_295 , V_296 , V_297 ) ;
return V_296 - V_297 - V_310 ;
}
static int F_75 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_251 * V_311 ;
struct V_253 V_312 ;
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_250 * V_313 ;
T_5 V_314 ;
struct V_315 * V_316 ;
T_2 V_118 ;
T_2 V_268 ;
T_2 V_128 ;
if ( V_83 -> V_121 . V_1 == V_50 ) {
V_313 = (struct V_250 * ) V_83 -> V_84 . V_123 ;
V_311 = (struct V_251 * ) ( V_83 -> V_84 . V_123 + sizeof( * V_313 )
+ V_313 -> V_317 ) ;
V_118 = F_7 ( V_313 -> V_318 ) ;
V_314 = * ( T_5 * ) ( V_83 -> V_84 . V_123 + sizeof( * V_313 ) +
V_313 -> V_317 + V_118 ) ;
V_268 = F_6 ( V_314 ) ;
} else {
if ( ! V_78 -> V_248 ) {
F_5 ( V_78 , L_36 ) ;
return 0 ;
}
V_313 = & V_78 -> V_249 ;
V_316 = (struct V_315 * ) V_83 -> V_84 . V_123 ;
V_311 = (struct V_251 * ) ( V_83 -> V_84 . V_123 + sizeof( * V_316 ) ) ;
V_118 = F_7 ( V_316 -> V_318 ) ;
V_314 = * ( T_5 * ) ( V_83 -> V_84 . V_123 + sizeof( * V_316 ) + V_118 ) ;
V_268 = F_71 ( V_78 ,
F_6 ( V_314 ) ) ;
}
if ( ( F_41 ( V_313 -> V_317 > 20 ) ) ) {
F_76 ( V_78 , L_37 ,
V_313 -> V_317 ) ;
return 0 ;
}
if ( ! ( V_314 & V_319 ) ||
! ( V_314 & V_320 ) ) {
F_15 ( V_78 , L_38 ,
F_6 ( V_314 ) ) ;
return 0 ;
}
V_128 = F_6 ( V_313 -> V_128 ) ;
V_312 . V_321 = F_77 ( V_313 -> V_322 ) ;
V_312 . V_323 = ( V_313 -> V_324 & V_325 ) ?
V_326 : V_327 ;
V_312 . V_328 =
F_78 ( F_7 ( V_313 -> V_103 ) ,
V_312 . V_323 ) ;
V_312 . V_329 =
F_79 ( V_128 , V_312 . V_323 ) ;
V_312 . V_202 = 0 ;
V_78 -> V_330 = F_6 ( V_313 -> V_331 ) ;
V_312 . signal = F_72 ( V_78 , V_313 ) ;
F_80 ( V_78 , V_118 , V_311 ) ;
F_81 ( V_78 , L_39 ,
V_312 . signal , ( unsigned long long ) V_312 . V_321 ) ;
V_312 . V_332 =
( F_7 ( V_313 -> V_324 ) & V_333 )
>> V_334 ;
if ( V_313 -> V_324 & V_335 )
V_312 . V_202 |= V_336 ;
if ( V_128 & V_337 )
V_312 . V_202 |= V_338 ;
if ( V_128 & V_339 )
V_312 . V_202 |= V_340 ;
if ( V_128 & V_341 )
V_312 . V_202 |= V_342 ;
F_59 ( V_78 , V_311 , V_118 , V_268 ,
V_80 , & V_312 ) ;
return 0 ;
}
static int F_82 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_343 * V_344 , * V_345 ;
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_346 * V_347 = ( void * ) V_83 -> V_84 . V_123 ;
V_345 = F_83 ( V_78 -> V_348 , true ) ;
if ( V_347 -> V_349 ) {
T_2 V_118 = F_7 ( V_347 -> V_350 . V_351 ) ;
T_2 V_352 = V_118 ;
V_118 += 1 + 1 + 3 + 1 ;
V_118 += 1 + 2 ;
V_352 += 1 + 2 ;
V_344 = F_84 ( sizeof( * V_344 ) + V_118 , V_353 ) ;
if ( V_344 ) {
V_344 -> V_351 = V_118 ;
V_344 -> V_354 [ 0 ] = V_355 ;
V_344 -> V_354 [ 1 ] = V_118 - 2 ;
V_344 -> V_354 [ 2 ] = ( V_356 >> 16 ) & 0xff ;
V_344 -> V_354 [ 3 ] = ( V_356 >> 8 ) & 0xff ;
V_344 -> V_354 [ 4 ] = ( V_356 >> 0 ) & 0xff ;
V_344 -> V_354 [ 5 ] = V_357 ;
memcpy ( & V_344 -> V_354 [ 6 ] , & V_347 -> V_350 ,
V_352 ) ;
}
} else
V_344 = NULL ;
F_85 ( V_78 -> V_348 , V_344 ) ;
if ( V_345 )
F_86 ( V_345 , V_358 ) ;
return 0 ;
}
void F_87 ( struct V_77 * V_78 )
{
int (* * F_88)( struct V_77 * V_78 , struct V_79 * V_80 ,
struct V_81 * V_1 );
F_88 = V_78 -> V_359 ;
F_88 [ V_3 ] = F_3 ;
F_88 [ V_22 ] = F_8 ;
F_88 [ V_24 ] =
F_12 ;
F_88 [ V_26 ] = F_13 ;
F_88 [ V_27 ] =
F_16 ;
F_88 [ V_33 ] = F_19 ;
F_88 [ V_9 ] = V_360 ;
F_88 [ V_68 ] = F_82 ;
F_88 [ V_40 ] = F_43 ;
F_88 [ V_41 ] = F_36 ;
F_89 ( V_78 ) ;
F_88 [ V_43 ] = F_44 ;
F_88 [ V_44 ] =
F_55 ;
F_88 [ V_48 ] = F_57 ;
F_88 [ V_49 ] = F_75 ;
F_88 [ V_51 ] =
V_361 ;
V_78 -> V_359 [ V_53 ] =
V_362 ;
V_78 -> V_359 [ V_14 ] = V_363 ;
F_90 ( & V_78 -> V_101 -> V_364 ) ;
F_91 ( & V_78 -> V_101 -> V_365 ) ;
F_92 ( & V_78 -> V_101 -> V_366 ) ;
if ( F_24 ( V_78 ) -> V_223 -> V_367 )
F_24 ( V_78 ) -> V_223 -> V_367 ( V_78 ) ;
}
int F_93 ( struct V_77 * V_78 , struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
int V_368 = 0 ;
if ( ! F_94 ( & V_78 -> V_101 -> V_365 ) ) {
struct V_369 * V_370 ;
F_95 ( & V_78 -> V_101 -> V_364 ) ;
F_96 (w, &priv->shrd->notif_waits, list) {
if ( V_370 -> V_1 != V_83 -> V_121 . V_1 )
continue;
F_15 ( V_78 ,
L_40 ,
F_1 ( V_83 -> V_121 . V_1 ) ,
V_83 -> V_121 . V_1 ) ;
V_370 -> V_371 = true ;
if ( V_370 -> V_372 )
V_370 -> V_372 ( F_68 ( V_78 ) , V_83 , V_370 -> V_373 ) ;
}
F_97 ( & V_78 -> V_101 -> V_364 ) ;
F_98 ( & V_78 -> V_101 -> V_366 ) ;
}
if ( V_78 -> V_374 )
V_78 -> V_374 ( V_78 , V_80 ) ;
if ( V_78 -> V_359 [ V_83 -> V_121 . V_1 ] ) {
V_78 -> V_375 [ V_83 -> V_121 . V_1 ] ++ ;
V_368 = V_78 -> V_359 [ V_83 -> V_121 . V_1 ] ( V_78 , V_80 , V_1 ) ;
} else {
F_15 ( V_78 ,
L_41 ,
F_1 ( V_83 -> V_121 . V_1 ) , V_83 -> V_121 . V_1 ) ;
}
return V_368 ;
}
