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
struct V_84 * V_85 = ( void * ) V_83 -> V_86 ;
F_5 ( V_78 , L_2
L_3 ,
F_6 ( V_85 -> V_87 ) ,
F_1 ( V_85 -> V_88 ) ,
V_85 -> V_88 ,
F_7 ( V_85 -> V_89 ) ,
F_6 ( V_85 -> V_90 ) ) ;
return 0 ;
}
static int F_8 ( struct V_77 * V_78 , struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_91 * V_92 = ( void * ) V_83 -> V_86 ;
struct V_93 * V_94 = & V_78 -> V_95 [ V_96 ] ;
struct V_97 * V_98 = ( void * ) & V_94 -> V_99 ;
if ( ! F_9 ( V_100 , & V_78 -> V_101 ) )
return 0 ;
if ( ! F_6 ( V_92 -> V_101 ) && V_92 -> V_102 == V_78 -> V_103 ) {
V_98 -> V_102 = V_92 -> V_102 ;
V_94 -> V_104 . V_102 = V_92 -> V_102 ;
F_10 ( V_78 , L_4 ,
F_7 ( V_92 -> V_102 ) ) ;
F_11 ( V_78 , true ) ;
} else {
F_5 ( V_78 , L_5 ,
F_7 ( V_92 -> V_102 ) ) ;
F_11 ( V_78 , false ) ;
}
return 0 ;
}
static int F_12 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_105 * V_106 = ( void * ) V_83 -> V_86 ;
if ( ! V_106 -> V_107 ) {
F_10 ( V_78 ,
L_6 ) ;
return 0 ;
}
memcpy ( & V_78 -> V_108 , V_106 , sizeof( * V_106 ) ) ;
V_78 -> V_109 |= V_110 ;
return 0 ;
}
static int F_13 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
#ifdef F_14
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_111 * V_112 = ( void * ) V_83 -> V_86 ;
F_15 ( V_78 , L_7 ,
V_112 -> V_113 , V_112 -> V_114 ) ;
#endif
return 0 ;
}
static int F_16 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
T_2 T_3 V_115 =
F_6 ( V_83 -> V_116 ) & V_117 ;
F_17 ( V_78 , L_8
L_9 , V_115 ,
F_1 ( V_83 -> V_118 . V_1 ) ) ;
F_18 ( V_78 , V_119 , V_83 -> V_86 , V_115 ) ;
return 0 ;
}
static int F_19 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_120 * V_121 = ( void * ) V_83 -> V_86 ;
#ifdef F_14
T_4 V_101 = F_7 ( V_121 -> V_122 . V_101 . V_101 ) ;
T_1 V_123 = F_20 ( V_121 -> V_122 . V_124 ) ;
F_15 ( V_78 , L_10
L_11 ,
V_101 & V_125 ,
V_121 -> V_122 . V_126 ,
F_6 ( V_121 -> V_127 ) ,
F_6 ( V_121 -> V_128 ) ,
F_6 ( V_121 -> V_129 ) , V_123 ) ;
#endif
V_78 -> V_130 = F_6 ( V_121 -> V_127 ) ;
return 0 ;
}
static bool F_21 ( struct V_77 * V_78 ,
struct V_131 * V_132 )
{
int V_133 , V_134 , V_135 ;
struct V_131 * V_136 ;
if ( V_78 -> V_137 )
return true ;
F_22 ( & V_78 -> V_138 . V_139 ) ;
V_136 = & V_78 -> V_138 . V_140 ;
V_133 = F_6 ( V_132 -> V_141 ) -
F_6 ( V_136 -> V_141 ) ;
V_134 = F_6 ( V_132 -> V_142 ) -
F_6 ( V_136 -> V_142 ) ;
if ( V_133 <= 0 || V_134 <= 0 )
return true ;
V_135 = F_6 ( V_132 -> V_143 . V_144 ) -
F_6 ( V_136 -> V_143 . V_144 ) ;
if ( ( V_133 * 100 / V_134 ) < V_145 &&
V_135 > V_146 ) {
F_17 ( V_78 ,
L_12 ,
V_133 , V_134 , V_135 ) ;
#ifdef F_23
F_17 ( V_78 , L_13 ,
V_78 -> V_147 . V_140 . V_148 ) ;
F_17 ( V_78 ,
L_14 ,
V_78 -> V_147 . V_140 . V_149 ) ;
#endif
if ( V_135 >= V_150 )
return false ;
}
return true ;
}
static bool F_24 ( struct V_77 * V_78 ,
struct V_151 * V_152 ,
struct V_153 * V_154 ,
unsigned int V_155 )
{
int V_156 ;
int V_157 = V_78 -> V_158 ;
if ( V_157 == V_159 ) {
F_17 ( V_78 , L_15 ) ;
return true ;
}
V_156 = F_6 ( V_152 -> V_160 ) -
F_6 ( V_78 -> V_138 . V_161 . V_160 ) +
F_6 ( V_154 -> V_160 ) -
F_6 ( V_78 -> V_138 . V_162 . V_160 ) ;
if ( V_156 <= 0 )
return true ;
if ( ( V_156 * 100 / V_155 ) > V_157 ) {
F_17 ( V_78 ,
L_16 ,
V_157 , V_156 , V_155 ) ;
return false ;
}
return true ;
}
static void F_25 ( struct V_77 * V_78 ,
struct V_151 * V_152 ,
struct V_153 * V_154 ,
struct V_131 * V_140 ,
unsigned long V_163 )
{
unsigned int V_155 ;
if ( F_9 ( V_164 , & V_78 -> V_101 ) )
return;
V_155 = F_26 ( V_163 - V_78 -> V_165 ) ;
if ( ! F_27 ( V_78 ) )
return;
if ( V_155 < 99 )
return;
if ( V_166 . V_167 && ! F_21 ( V_78 , V_140 ) ) {
F_5 ( V_78 , L_17 ) ;
if ( ! F_28 ( V_78 , V_168 , false ) )
return;
}
if ( V_166 . V_169 &&
! F_24 ( V_78 , V_152 , V_154 , V_155 ) )
F_28 ( V_78 , V_170 , false ) ;
}
static void F_29 ( struct V_77 * V_78 )
{
struct V_171 * V_172 ;
int V_173 = 0 ;
int V_174 = 0 ;
int V_175 , V_176 , V_177 ;
int V_178 ;
V_172 = & V_78 -> V_138 . V_179 ;
V_175 =
F_6 ( V_172 -> V_180 ) & V_181 ;
V_176 =
F_6 ( V_172 -> V_182 ) & V_181 ;
V_177 =
F_6 ( V_172 -> V_183 ) & V_181 ;
if ( V_175 ) {
V_174 += V_175 ;
V_173 ++ ;
}
if ( V_176 ) {
V_174 += V_176 ;
V_173 ++ ;
}
if ( V_177 ) {
V_174 += V_177 ;
V_173 ++ ;
}
if ( V_173 )
V_178 = ( V_174 / V_173 ) - 107 ;
else
V_178 = V_184 ;
F_30 ( V_78 , L_18 ,
V_175 , V_176 , V_177 ,
V_178 ) ;
}
static void F_31 ( T_5 * V_185 , T_5 * V_132 , T_5 * V_156 ,
T_5 * V_186 , T_5 * V_187 , int V_188 )
{
int V_189 ;
for ( V_189 = 0 ;
V_189 < V_188 / sizeof( T_5 ) ;
V_189 ++ , V_185 ++ , V_132 ++ , V_156 ++ , V_186 ++ , V_187 ++ ) {
if ( F_6 ( * V_132 ) > F_6 ( * V_185 ) ) {
* V_156 = F_32 (
F_6 ( * V_132 ) - F_6 ( * V_185 ) ) ;
F_33 ( V_187 , F_6 ( * V_156 ) ) ;
if ( F_6 ( * V_156 ) > F_6 ( * V_186 ) )
* V_186 = * V_156 ;
}
}
}
static void
F_34 ( struct V_77 * V_78 ,
struct V_190 * V_191 ,
struct V_171 * V_179 ,
struct V_151 * V_161 ,
struct V_153 * V_162 ,
struct V_151 * V_192 ,
struct V_131 * V_140 ,
struct V_193 * V_194 )
{
#define F_35 ( T_6 ) \
accum_stats((__le32 *)&priv->statistics._name, \
(__le32 *)_name, \
(__le32 *)&priv->delta_stats._name, \
(__le32 *)&priv->max_delta_stats._name, \
(__le32 *)&priv->accum_stats._name, \
sizeof(*_name));
F_35 ( V_191 ) ;
F_35 ( V_179 ) ;
F_35 ( V_161 ) ;
F_35 ( V_162 ) ;
F_35 ( V_192 ) ;
F_35 ( V_140 ) ;
if ( V_194 )
F_35 ( V_194 ) ;
#undef F_35
}
static inline void
F_34 ( struct V_77 * V_78 ,
struct V_190 * V_191 ,
struct V_171 * V_179 ,
struct V_151 * V_161 ,
struct V_153 * V_162 ,
struct V_151 * V_192 ,
struct V_131 * V_140 ,
struct V_193 * V_194 )
{
}
static int F_36 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
unsigned long V_163 = V_195 ;
const int V_196 = 60 ;
int V_197 ;
struct V_82 * V_83 = F_4 ( V_80 ) ;
T_2 V_115 = F_6 ( V_83 -> V_116 ) & V_117 ;
T_5 * V_198 ;
struct V_190 * V_191 ;
struct V_171 * V_179 ;
struct V_151 * V_161 ;
struct V_153 * V_162 ;
struct V_151 * V_192 ;
struct V_131 * V_140 ;
struct V_193 * V_194 ;
V_115 -= sizeof( struct V_199 ) ;
F_15 ( V_78 , L_19 ,
V_115 ) ;
F_37 ( & V_78 -> V_138 . V_139 ) ;
if ( V_115 == sizeof( struct V_200 ) ) {
struct V_200 * V_201 ;
V_201 = ( void * ) & V_83 -> V_86 ;
V_198 = & V_201 -> V_198 ;
V_191 = & V_201 -> V_202 . V_191 ;
V_179 = & V_201 -> V_203 . V_202 . V_191 ;
V_161 = & V_201 -> V_203 . V_204 ;
V_162 = & V_201 -> V_203 . V_205 ;
V_192 = & V_201 -> V_203 . V_206 ;
V_140 = & V_201 -> V_140 ;
V_194 = & V_201 -> V_202 . V_207 ;
#ifdef F_23
V_78 -> V_138 . V_208 = V_201 -> V_203 . V_202 . V_208 ;
F_33 ( & V_78 -> V_138 . V_209 ,
F_6 ( V_201 -> V_203 . V_202 . V_208 ) ) ;
#endif
} else if ( V_115 == sizeof( struct V_210 ) ) {
struct V_210 * V_201 ;
V_201 = ( void * ) & V_83 -> V_86 ;
V_198 = & V_201 -> V_198 ;
V_191 = & V_201 -> V_202 . V_191 ;
V_179 = & V_201 -> V_203 . V_202 ;
V_161 = & V_201 -> V_203 . V_204 ;
V_162 = & V_201 -> V_203 . V_205 ;
V_192 = & V_201 -> V_203 . V_206 ;
V_140 = & V_201 -> V_140 ;
V_194 = NULL ;
} else {
F_38 ( 1 , L_20 ,
V_115 , sizeof( struct V_200 ) ,
sizeof( struct V_210 ) ) ;
F_39 ( & V_78 -> V_138 . V_139 ) ;
return 0 ;
}
V_197 = V_191 -> V_211 != V_78 -> V_138 . V_191 . V_211 ||
( * V_198 & V_212 ) !=
( V_78 -> V_138 . V_198 & V_212 ) ;
F_34 ( V_78 , V_191 , V_179 , V_161 ,
V_162 , V_192 , V_140 , V_194 ) ;
F_25 ( V_78 , V_161 , V_162 , V_140 , V_163 ) ;
V_78 -> V_138 . V_198 = * V_198 ;
memcpy ( & V_78 -> V_138 . V_191 , V_191 , sizeof( * V_191 ) ) ;
memcpy ( & V_78 -> V_138 . V_179 , V_179 , sizeof( * V_179 ) ) ;
memcpy ( & V_78 -> V_138 . V_161 , V_161 , sizeof( * V_161 ) ) ;
memcpy ( & V_78 -> V_138 . V_162 , V_162 , sizeof( * V_162 ) ) ;
memcpy ( & V_78 -> V_138 . V_192 , V_192 , sizeof( * V_192 ) ) ;
memcpy ( & V_78 -> V_138 . V_140 , V_140 , sizeof( * V_140 ) ) ;
#ifdef F_23
if ( V_194 )
memcpy ( & V_78 -> V_138 . V_194 , V_194 ,
sizeof( * V_194 ) ) ;
#endif
V_78 -> V_165 = V_163 ;
F_40 ( V_213 , & V_78 -> V_101 ) ;
F_41 ( & V_78 -> V_214 , V_195 +
F_42 ( V_196 * 1000 ) ) ;
if ( F_43 ( ! F_9 ( V_215 , & V_78 -> V_101 ) ) &&
( V_83 -> V_118 . V_1 == V_41 ) ) {
F_29 ( V_78 ) ;
F_44 ( V_78 -> V_216 , & V_78 -> V_217 ) ;
}
if ( F_45 ( V_78 ) -> V_218 -> V_211 && V_197 )
F_45 ( V_78 ) -> V_218 -> V_211 ( V_78 ) ;
F_39 ( & V_78 -> V_138 . V_139 ) ;
return 0 ;
}
static int F_46 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_210 * V_201 = ( void * ) V_83 -> V_86 ;
if ( F_6 ( V_201 -> V_198 ) & V_219 ) {
#ifdef F_23
memset ( & V_78 -> F_31 , 0 ,
sizeof( V_78 -> F_31 ) ) ;
memset ( & V_78 -> V_147 , 0 ,
sizeof( V_78 -> V_147 ) ) ;
memset ( & V_78 -> V_220 , 0 ,
sizeof( V_78 -> V_220 ) ) ;
#endif
F_15 ( V_78 , L_21 ) ;
}
F_36 ( V_78 , V_80 , V_1 ) ;
return 0 ;
}
static int F_47 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_221 * V_222 = ( void * ) V_83 -> V_86 ;
T_2 V_223 = F_6 ( V_222 -> V_223 ) ;
unsigned long V_101 = V_78 -> V_101 ;
F_48 ( V_78 , L_22 ,
( V_223 & V_224 ) ? L_23 : L_24 ,
( V_223 & V_225 ) ? L_23 : L_24 ,
( V_223 & V_226 ) ?
L_25 : L_26 ) ;
if ( V_223 & ( V_225 | V_224 |
V_226 ) ) {
F_49 ( F_50 ( V_78 ) , V_227 ,
V_228 ) ;
F_51 ( F_50 ( V_78 ) , V_229 ,
V_230 ) ;
if ( ! ( V_223 & V_231 ) ) {
F_49 ( F_50 ( V_78 ) , V_232 ,
V_228 ) ;
F_51 ( F_50 ( V_78 ) , V_229 ,
V_230 ) ;
}
if ( V_223 & V_226 )
F_52 ( V_78 ) ;
}
if ( ! ( V_223 & V_226 ) )
F_53 ( V_78 ) ;
if ( V_223 & V_224 )
F_40 ( V_233 , & V_78 -> V_101 ) ;
else
F_54 ( V_233 , & V_78 -> V_101 ) ;
if ( ! ( V_223 & V_231 ) )
F_55 ( V_78 ) ;
if ( ( F_9 ( V_233 , & V_101 ) !=
F_9 ( V_233 , & V_78 -> V_101 ) ) )
F_56 ( V_78 -> V_234 -> V_235 ,
F_9 ( V_233 , & V_78 -> V_101 ) ) ;
else
F_57 ( & F_50 ( V_78 ) -> V_236 ) ;
return 0 ;
}
static int F_58 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_237 * V_238 = ( void * ) V_83 -> V_86 ;
if ( F_6 ( V_238 -> V_239 ) >
V_78 -> V_240 ) {
F_30 ( V_78 ,
L_27 ,
F_6 ( V_238 -> V_239 ) ,
F_6 ( V_238 -> V_241 ) ,
F_6 ( V_238 -> V_242 ) ,
F_6 ( V_238 -> V_243 ) ) ;
if ( ! F_9 ( V_215 , & V_78 -> V_101 ) )
F_59 ( V_78 ) ;
}
return 0 ;
}
static int F_60 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
V_78 -> V_244 = true ;
memcpy ( & V_78 -> V_245 , V_83 -> V_86 ,
sizeof( struct V_246 ) ) ;
return 0 ;
}
static int F_61 ( struct V_77 * V_78 ,
struct V_247 * V_118 ,
T_2 V_248 ,
struct V_249 * V_201 )
{
T_4 V_250 = F_7 ( V_118 -> V_251 ) ;
if ( V_78 -> V_95 [ V_96 ] . V_99 . V_252 &
V_253 )
return 0 ;
if ( ! ( V_250 & V_254 ) )
return 0 ;
F_15 ( V_78 , L_28 , V_248 ) ;
switch ( V_248 & V_255 ) {
case V_256 :
if ( ( V_248 & V_257 ) ==
V_258 )
break;
case V_259 :
if ( ( V_248 & V_257 ) ==
V_260 ) {
F_15 ( V_78 , L_29 ) ;
return - 1 ;
}
case V_261 :
if ( ( V_248 & V_257 ) ==
V_262 ) {
F_15 ( V_78 , L_30 ) ;
V_201 -> V_198 |= V_263 ;
}
break;
default:
break;
}
return 0 ;
}
static void F_62 ( struct V_77 * V_78 ,
struct V_247 * V_118 ,
T_4 V_115 ,
T_2 V_264 ,
struct V_79 * V_80 ,
struct V_249 * V_201 )
{
struct V_265 * V_266 ;
T_7 V_250 = V_118 -> V_251 ;
struct V_93 * V_94 ;
unsigned int V_267 , V_268 ;
if ( F_43 ( ! V_78 -> V_269 ) ) {
F_63 ( V_78 ,
L_31 ) ;
return;
}
if ( ! V_166 . V_270 &&
F_61 ( V_78 , V_118 , V_264 , V_201 ) )
return;
V_266 = F_64 ( 128 , V_271 ) ;
if ( ! V_266 ) {
F_5 ( V_78 , L_32 ) ;
return;
}
V_267 = F_65 (unsigned int, len, skb_tailroom(skb)) ;
memcpy ( F_66 ( V_266 , V_267 ) , V_118 , V_267 ) ;
V_268 = V_115 - V_267 ;
if ( V_268 ) {
int V_272 = ( void * ) V_118 + V_267 - F_4 ( V_80 ) ;
F_67 ( V_266 , 0 , F_68 ( V_80 ) , V_272 ,
V_268 , V_80 -> V_273 ) ;
}
F_69 ( V_78 , false , V_250 , V_115 ) ;
if ( F_43 ( F_70 ( V_250 ) && V_78 -> V_274 ) ) {
F_71 (priv, ctx) {
if ( F_72 ( V_118 -> V_275 ,
V_94 -> V_99 . V_276 ) )
continue;
F_73 ( V_78 ) ;
}
}
memcpy ( F_74 ( V_266 ) , V_201 , sizeof( * V_201 ) ) ;
F_75 ( V_78 -> V_234 , V_266 ) ;
}
static T_2 F_76 ( struct V_77 * V_78 , T_2 V_277 )
{
T_2 V_278 = 0 ;
if ( ( V_277 & V_279 ) ==
V_279 )
V_278 |= ( V_279 |
V_280 ) ;
V_278 |= ( V_277 & V_255 ) ;
if ( ( V_277 & V_255 ) ==
V_281 )
return V_278 ;
if ( ( V_277 & V_255 ) ==
V_282 )
return V_278 ;
if ( ( V_277 & V_283 ) !=
V_283 )
return V_278 ;
switch ( V_277 & V_255 ) {
case V_261 :
if ( ! ( V_277 & V_284 ) )
V_278 |= V_260 ;
else
V_278 |= V_262 ;
break;
case V_256 :
if ( ! ( V_277 & V_285 ) ) {
V_278 |= V_258 ;
break;
}
default:
if ( ! ( V_277 & V_286 ) )
V_278 |= V_260 ;
else
V_278 |= V_262 ;
break;
}
F_15 ( V_78 , L_33 ,
V_277 , V_278 ) ;
return V_278 ;
}
static int F_77 ( struct V_77 * V_78 ,
struct V_246 * V_287 )
{
struct V_288 * V_289 =
(struct V_288 * ) V_287 -> V_290 ;
T_2 V_291 , V_292 , V_293 , V_294 , V_295 ;
T_1 V_296 ;
V_291 = F_6 ( V_289 -> V_297 [ V_298 ] ) ;
V_296 = ( V_291 & V_299 ) >> V_300 ;
V_291 = F_6 ( V_289 -> V_297 [ V_301 ] ) ;
V_292 = ( V_291 & V_302 ) >>
V_303 ;
V_293 = ( V_291 & V_304 ) >>
V_305 ;
V_291 = F_6 ( V_289 -> V_297 [ V_306 ] ) ;
V_294 = ( V_291 & V_307 ) >>
V_308 ;
V_295 = F_78 ( T_2 , V_292 , V_293 ) ;
V_295 = F_78 ( T_2 , V_295 , V_294 ) ;
F_79 ( V_78 , L_34 ,
V_292 , V_293 , V_294 , V_295 , V_296 ) ;
return V_295 - V_296 - V_309 ;
}
static int F_80 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_247 * V_310 ;
struct V_249 V_311 ;
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_246 * V_312 ;
T_5 V_313 ;
struct V_314 * V_315 ;
T_2 V_115 ;
T_2 V_264 ;
T_2 V_124 ;
if ( V_83 -> V_118 . V_1 == V_50 ) {
V_312 = (struct V_246 * ) V_83 -> V_86 ;
V_310 = (struct V_247 * ) ( V_83 -> V_86 + sizeof( * V_312 )
+ V_312 -> V_316 ) ;
V_115 = F_7 ( V_312 -> V_317 ) ;
V_313 = * ( T_5 * ) ( V_83 -> V_86 + sizeof( * V_312 ) +
V_312 -> V_316 + V_115 ) ;
V_264 = F_6 ( V_313 ) ;
} else {
if ( ! V_78 -> V_244 ) {
F_5 ( V_78 , L_35 ) ;
return 0 ;
}
V_312 = & V_78 -> V_245 ;
V_315 = (struct V_314 * ) V_83 -> V_86 ;
V_310 = (struct V_247 * ) ( V_83 -> V_86 + sizeof( * V_315 ) ) ;
V_115 = F_7 ( V_315 -> V_317 ) ;
V_313 = * ( T_5 * ) ( V_83 -> V_86 + sizeof( * V_315 ) + V_115 ) ;
V_264 = F_76 ( V_78 ,
F_6 ( V_313 ) ) ;
}
if ( ( F_43 ( V_312 -> V_316 > 20 ) ) ) {
F_81 ( V_78 , L_36 ,
V_312 -> V_316 ) ;
return 0 ;
}
if ( ! ( V_313 & V_318 ) ||
! ( V_313 & V_319 ) ) {
F_15 ( V_78 , L_37 ,
F_6 ( V_313 ) ) ;
return 0 ;
}
V_124 = F_6 ( V_312 -> V_124 ) ;
V_311 . V_320 = F_82 ( V_312 -> V_321 ) ;
V_311 . V_322 = ( V_312 -> V_323 & V_324 ) ?
V_325 : V_326 ;
V_311 . V_327 =
F_83 ( F_7 ( V_312 -> V_102 ) ,
V_311 . V_322 ) ;
V_311 . V_328 =
F_84 ( V_124 , V_311 . V_322 ) ;
V_311 . V_198 = 0 ;
V_78 -> V_329 = F_6 ( V_312 -> V_330 ) ;
V_311 . signal = F_77 ( V_78 , V_312 ) ;
F_85 ( V_78 , V_115 , V_310 ) ;
F_86 ( V_78 , L_38 ,
V_311 . signal , ( unsigned long long ) V_311 . V_320 ) ;
V_311 . V_331 =
( F_7 ( V_312 -> V_323 ) & V_332 )
>> V_333 ;
if ( V_312 -> V_323 & V_334 )
V_311 . V_198 |= V_335 ;
if ( V_124 & V_336 )
V_311 . V_198 |= V_337 ;
if ( V_124 & V_338 )
V_311 . V_198 |= V_339 ;
if ( V_124 & V_340 )
V_311 . V_198 |= V_341 ;
F_62 ( V_78 , V_310 , V_115 , V_264 ,
V_80 , & V_311 ) ;
return 0 ;
}
static int F_87 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_342 * V_343 , * V_344 ;
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_345 * V_346 = ( void * ) V_83 -> V_86 ;
V_344 = F_88 ( V_78 -> V_347 , true ) ;
if ( V_346 -> V_348 ) {
T_2 V_115 = F_7 ( V_346 -> V_349 . V_350 ) ;
T_2 V_351 = V_115 ;
V_115 += 1 + 1 + 3 + 1 ;
V_115 += 1 + 2 ;
V_351 += 1 + 2 ;
V_343 = F_89 ( sizeof( * V_343 ) + V_115 , V_271 ) ;
if ( V_343 ) {
V_343 -> V_350 = V_115 ;
V_343 -> V_86 [ 0 ] = V_352 ;
V_343 -> V_86 [ 1 ] = V_115 - 2 ;
V_343 -> V_86 [ 2 ] = ( V_353 >> 16 ) & 0xff ;
V_343 -> V_86 [ 3 ] = ( V_353 >> 8 ) & 0xff ;
V_343 -> V_86 [ 4 ] = ( V_353 >> 0 ) & 0xff ;
V_343 -> V_86 [ 5 ] = V_354 ;
memcpy ( & V_343 -> V_86 [ 6 ] , & V_346 -> V_349 ,
V_351 ) ;
}
} else
V_343 = NULL ;
F_90 ( V_78 -> V_347 , V_343 ) ;
if ( V_344 )
F_91 ( V_344 , V_355 ) ;
return 0 ;
}
void F_92 ( struct V_77 * V_78 )
{
int (* * F_93)( struct V_77 * V_78 , struct V_79 * V_80 ,
struct V_81 * V_1 );
F_93 = V_78 -> V_356 ;
F_93 [ V_3 ] = F_3 ;
F_93 [ V_22 ] = F_8 ;
F_93 [ V_24 ] =
F_12 ;
F_93 [ V_26 ] = F_13 ;
F_93 [ V_27 ] =
F_16 ;
F_93 [ V_33 ] = F_19 ;
F_93 [ V_9 ] = V_357 ;
F_93 [ V_68 ] = F_87 ;
F_93 [ V_40 ] = F_46 ;
F_93 [ V_41 ] = F_36 ;
F_94 ( V_78 ) ;
F_93 [ V_43 ] = F_47 ;
F_93 [ V_44 ] =
F_58 ;
F_93 [ V_48 ] = F_60 ;
F_93 [ V_49 ] = F_80 ;
F_93 [ V_51 ] =
V_358 ;
V_78 -> V_356 [ V_53 ] =
V_359 ;
V_78 -> V_356 [ V_14 ] = V_360 ;
F_95 ( & V_78 -> V_361 ) ;
if ( F_45 ( V_78 ) -> V_362 )
F_96 ( V_78 ) ;
}
int F_97 ( struct V_363 * V_364 , struct V_79 * V_80 ,
struct V_81 * V_1 )
{
struct V_82 * V_83 = F_4 ( V_80 ) ;
struct V_77 * V_78 = F_98 ( V_364 ) ;
void (* F_99)( struct V_77 * ,
struct V_79 * );
int V_365 = 0 ;
F_100 ( & V_78 -> V_361 , V_83 ) ;
F_99 = F_101 ( V_78 -> F_99 ) ;
if ( F_99 )
F_99 ( V_78 , V_80 ) ;
if ( V_78 -> V_366 != V_367 ) {
if ( V_78 -> V_356 [ V_83 -> V_118 . V_1 ] ) {
V_78 -> V_368 [ V_83 -> V_118 . V_1 ] ++ ;
V_365 = V_78 -> V_356 [ V_83 -> V_118 . V_1 ] ( V_78 , V_80 , V_1 ) ;
} else {
F_15 ( V_78 ,
L_39 ,
F_1 ( V_83 -> V_118 . V_1 ) , V_83 -> V_118 . V_1 ) ;
}
}
return V_365 ;
}
