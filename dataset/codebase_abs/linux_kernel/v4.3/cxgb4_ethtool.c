static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( V_2 ) -> V_3 = V_4 ;
}
static int F_4 ( struct V_1 * V_2 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
return F_5 ( V_7 ) +
F_5 ( V_8 ) +
F_5 ( V_9 ) +
F_5 ( V_10 ) ;
default:
return - V_11 ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
return F_7 ( V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return V_14 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_12 * V_12 = F_2 ( V_2 ) ;
T_1 V_17 ;
F_10 ( V_16 -> V_18 , V_19 , sizeof( V_16 -> V_18 ) ) ;
F_10 ( V_16 -> V_20 , V_21 ,
sizeof( V_16 -> V_20 ) ) ;
F_10 ( V_16 -> V_22 , F_11 ( V_12 -> V_23 ) ,
sizeof( V_16 -> V_22 ) ) ;
if ( V_12 -> V_24 . V_25 )
snprintf ( V_16 -> V_26 , sizeof( V_16 -> V_26 ) ,
L_1 ,
F_12 ( V_12 -> V_24 . V_25 ) ,
F_13 ( V_12 -> V_24 . V_25 ) ,
F_14 ( V_12 -> V_24 . V_25 ) ,
F_15 ( V_12 -> V_24 . V_25 ) ,
F_12 ( V_12 -> V_24 . V_27 ) ,
F_13 ( V_12 -> V_24 . V_27 ) ,
F_14 ( V_12 -> V_24 . V_27 ) ,
F_15 ( V_12 -> V_24 . V_27 ) ) ;
if ( ! F_16 ( V_12 , & V_17 ) )
snprintf ( V_16 -> V_28 , sizeof( V_16 -> V_28 ) ,
L_2 ,
F_12 ( V_17 ) ,
F_13 ( V_17 ) ,
F_14 ( V_17 ) ,
F_15 ( V_17 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_29 , T_2 * V_30 )
{
if ( V_29 == V_6 ) {
memcpy ( V_30 , V_7 , sizeof( V_7 ) ) ;
V_30 += sizeof( V_7 ) ;
memcpy ( V_30 , V_8 ,
sizeof( V_8 ) ) ;
V_30 += sizeof( V_8 ) ;
memcpy ( V_30 , V_9 ,
sizeof( V_9 ) ) ;
V_30 += sizeof( V_9 ) ;
memcpy ( V_30 , V_10 ,
sizeof( V_10 ) ) ;
}
}
static void F_18 ( const struct V_12 * V_13 ,
const struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_35 ;
const struct V_36 * V_37 = & V_13 -> V_38 . V_39 [ V_32 -> V_40 ] ;
const struct V_41 * V_42 = & V_13 -> V_38 . V_43 [ V_32 -> V_40 ] ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
for ( V_35 = 0 ; V_35 < V_32 -> V_44 ; V_35 ++ , V_42 ++ , V_37 ++ ) {
V_34 -> V_45 += V_37 -> V_45 ;
V_34 -> V_46 += V_37 -> V_47 ;
V_34 -> V_48 += V_42 -> V_49 . V_50 ;
V_34 -> V_51 += V_42 -> V_49 . V_51 ;
V_34 -> V_52 += V_37 -> V_52 ;
V_34 -> V_53 += V_42 -> V_49 . V_54 ;
V_34 -> V_55 += V_42 -> V_49 . V_56 ;
}
}
static void F_19 ( struct V_12 * V_13 , struct V_57 * V_34 )
{
struct V_58 V_59 , V_60 ;
struct V_61 V_62 ;
struct V_63 V_64 ;
struct V_65 V_66 ;
T_3 V_67 , V_68 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
F_20 ( & V_13 -> V_69 ) ;
F_21 ( V_13 , & V_59 , & V_60 ) ;
F_22 ( V_13 , & V_62 ) ;
F_23 ( V_13 , & V_66 ) ;
F_24 ( V_13 , & V_64 ) ;
F_25 ( & V_13 -> V_69 ) ;
V_34 -> V_70 = V_13 -> V_71 . V_70 ;
V_34 -> V_72 = V_13 -> V_71 . V_72 ;
V_34 -> V_73 = V_13 -> V_71 . V_73 ;
V_34 -> V_74 = V_59 . V_75 ;
V_34 -> V_76 = V_59 . V_77 ;
V_34 -> V_78 = V_59 . V_79 ;
V_34 -> V_80 = V_59 . V_81 ;
V_34 -> V_82 = V_60 . V_75 ;
V_34 -> V_83 = V_60 . V_77 ;
V_34 -> V_84 = V_60 . V_79 ;
V_34 -> V_85 = V_60 . V_81 ;
if ( F_26 ( V_13 ) ) {
V_34 -> V_86 = V_66 . V_86 ;
V_34 -> V_87 = V_66 . V_87 ;
V_34 -> V_88 = V_66 . V_88 ;
V_34 -> V_89 = V_62 . V_89 ;
V_34 -> V_90 = V_62 . V_90 ;
}
V_34 -> V_91 = V_64 . V_91 ;
V_34 -> V_92 = V_64 . V_92 ;
if ( ! F_27 ( V_13 -> V_24 . V_93 ) ) {
int V_94 ;
V_94 = F_28 ( V_13 , V_95 ) ;
if ( F_29 ( V_94 ) == 7 ) {
V_68 = F_28 ( V_13 , V_96 ) ;
V_67 = F_28 ( V_13 , V_97 ) ;
V_34 -> V_98 = V_67 - V_68 ;
V_34 -> V_99 = V_68 ;
}
}
}
static void F_30 ( struct V_12 * V_13 , struct V_100 * V_34 ,
T_2 V_35 )
{
struct V_101 V_102 ;
struct V_63 V_64 ;
struct V_103 V_104 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
F_20 ( & V_13 -> V_69 ) ;
F_31 ( V_13 , & V_102 ) ;
F_24 ( V_13 , & V_64 ) ;
F_32 ( V_13 , V_35 , & V_104 ) ;
F_25 ( & V_13 -> V_69 ) ;
V_34 -> V_105 = V_102 . V_106 [ V_35 ] ;
V_34 -> V_107 = V_102 . V_108 [ V_35 ] ;
V_34 -> V_109 = V_64 . V_109 [ V_35 ] ;
V_34 -> V_110 = V_64 . V_110 [ V_35 ] ;
V_34 -> V_111 = V_64 . V_111 [ V_35 ] ;
V_34 -> V_112 = V_64 . V_112 [ V_35 ] ;
V_34 -> V_113 = V_64 . V_113 [ V_35 ] ;
V_34 -> V_114 = V_64 . V_114 [ V_35 ] ;
V_34 -> V_115 = V_64 . V_115 [ V_35 ] ;
V_34 -> V_116 = V_64 . V_116 [ V_35 ] ;
V_34 -> V_117 = V_104 . V_117 ;
V_34 -> V_118 = V_104 . V_118 ;
V_34 -> V_119 = V_104 . V_119 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_120 * V_49 ,
T_3 * V_30 )
{
struct V_31 * V_121 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_121 -> V_12 ;
struct V_122 V_34 ;
int V_35 ;
T_3 * V_123 ;
F_35 ( V_12 , V_121 -> V_124 ,
(struct V_125 * ) V_30 ,
& V_121 -> V_126 ) ;
V_30 += sizeof( struct V_125 ) / sizeof( T_3 ) ;
F_18 ( V_12 , V_121 , (struct V_33 * ) V_30 ) ;
V_30 += sizeof( struct V_33 ) / sizeof( T_3 ) ;
F_19 ( V_12 , (struct V_57 * ) V_30 ) ;
V_30 += sizeof( struct V_57 ) / sizeof( T_3 ) ;
* V_30 ++ = ( T_3 ) V_121 -> V_127 ;
F_30 ( V_12 , (struct V_100 * ) V_30 ,
V_121 -> V_127 ) ;
V_30 += sizeof( struct V_100 ) / sizeof( T_3 ) ;
* V_30 ++ = ( T_3 ) V_121 -> V_127 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
F_36 ( V_12 , V_121 -> V_127 , & V_34 ) ;
V_123 = & V_34 . V_87 ;
for ( V_35 = 0 ; V_35 < F_5 ( V_10 ) - 1 ; V_35 ++ )
* V_30 ++ = ( unsigned long long ) * V_123 ++ ;
}
static void F_37 ( struct V_1 * V_2 , struct V_128 * V_129 ,
void * V_130 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
T_4 V_131 ;
V_131 = F_7 ( V_13 ) ;
V_129 -> V_20 = F_38 ( V_13 ) ;
F_39 ( V_13 , V_130 , V_131 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_34 ( V_2 ) ;
if ( ! F_41 ( V_2 ) )
return - V_132 ;
if ( V_32 -> V_133 . V_134 != V_135 )
return - V_136 ;
F_42 ( V_32 -> V_12 , V_32 -> V_12 -> V_137 , V_32 -> V_124 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
enum V_138 V_139 )
{
unsigned int V_4 ;
struct V_12 * V_13 = F_2 ( V_2 ) ;
if ( V_139 == V_140 )
V_4 = 0xffff ;
else if ( V_139 == V_141 )
V_4 = 0 ;
else
return - V_136 ;
return F_44 ( V_13 , V_13 -> V_137 , F_45 ( V_2 ) -> V_142 , V_4 ) ;
}
static unsigned int F_46 ( enum V_143 type , unsigned int V_144 )
{
unsigned int V_94 = 0 ;
if ( type == V_145 || type == V_146 ||
type == V_147 ) {
V_94 |= V_148 ;
if ( V_144 & V_149 )
V_94 |= V_150 ;
if ( V_144 & V_151 )
V_94 |= V_152 ;
if ( V_144 & V_153 )
V_94 |= V_154 ;
} else if ( type == V_155 || type == V_156 ) {
V_94 |= V_157 ;
if ( V_144 & V_151 )
V_94 |= V_158 ;
if ( V_144 & V_153 )
V_94 |= V_159 ;
} else if ( type == V_160 ) {
V_94 |= V_157 | V_161 ;
} else if ( type == V_162 ) {
V_94 |= V_157 | V_163 |
V_161 | V_158 ;
} else if ( type == V_164 ) {
V_94 |= V_157 | V_163 |
V_161 | V_158 |
V_159 ;
} else if ( type == V_165 ||
type == V_166 ||
type == V_167 ||
type == V_168 ||
type == V_169 ) {
V_94 |= V_170 ;
if ( V_144 & V_151 )
V_94 |= V_152 ;
if ( V_144 & V_153 )
V_94 |= V_154 ;
} else if ( type == V_171 ||
type == V_172 ) {
V_94 |= V_173 ;
V_94 |= V_170 ;
}
if ( V_144 & V_174 )
V_94 |= V_175 ;
return V_94 ;
}
static unsigned int F_47 ( unsigned int V_144 )
{
unsigned int V_94 = 0 ;
if ( V_144 & V_176 )
V_94 |= V_149 ;
if ( V_144 & V_177 )
V_94 |= V_151 ;
if ( V_144 & V_178 )
V_94 |= V_153 ;
if ( V_144 & V_179 )
V_94 |= V_180 ;
return V_94 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_181 * V_182 )
{
const struct V_31 * V_32 = F_34 ( V_2 ) ;
if ( V_32 -> V_183 == V_145 ||
V_32 -> V_183 == V_146 ||
V_32 -> V_183 == V_147 ) {
V_182 -> V_184 = V_185 ;
} else if ( V_32 -> V_183 == V_165 ||
V_32 -> V_183 == V_166 ) {
V_182 -> V_184 = V_186 ;
} else if ( V_32 -> V_183 == V_167 ||
V_32 -> V_183 == V_168 ||
V_32 -> V_183 == V_169 ||
V_32 -> V_183 == V_172 ) {
if ( V_32 -> V_187 == V_188 ||
V_32 -> V_187 == V_189 ||
V_32 -> V_187 == V_190 ||
V_32 -> V_187 == V_191 )
V_182 -> V_184 = V_186 ;
else if ( V_32 -> V_187 == V_192 ||
V_32 -> V_187 == V_193 )
V_182 -> V_184 = V_194 ;
else
V_182 -> V_184 = V_195 ;
} else {
V_182 -> V_184 = V_195 ;
}
if ( V_32 -> V_196 >= 0 ) {
V_182 -> V_197 = V_32 -> V_196 ;
V_182 -> V_198 = V_199 ;
V_182 -> V_200 = V_32 -> V_183 == V_145 ?
V_201 : V_202 ;
} else {
V_182 -> V_197 = 0 ;
V_182 -> V_198 = V_203 ;
V_182 -> V_200 = 0 ;
}
V_182 -> V_204 = F_46 ( V_32 -> V_183 , V_32 -> V_133 . V_204 ) ;
V_182 -> V_205 = F_46 ( V_32 -> V_183 ,
V_32 -> V_133 . V_205 ) ;
F_49 ( V_182 ,
F_50 ( V_2 ) ? V_32 -> V_133 . V_206 : 0 ) ;
V_182 -> V_207 = V_208 ;
V_182 -> V_134 = V_32 -> V_133 . V_134 ;
V_182 -> V_209 = 0 ;
V_182 -> V_210 = 0 ;
return 0 ;
}
static unsigned int F_51 ( int V_206 )
{
if ( V_206 == 100 )
return V_149 ;
if ( V_206 == 1000 )
return V_151 ;
if ( V_206 == 10000 )
return V_153 ;
if ( V_206 == 40000 )
return V_180 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_181 * V_182 )
{
unsigned int V_211 ;
struct V_31 * V_32 = F_34 ( V_2 ) ;
struct V_212 * V_213 = & V_32 -> V_133 ;
T_1 V_206 = F_53 ( V_182 ) ;
if ( V_182 -> V_207 != V_208 )
return - V_136 ;
if ( ! ( V_213 -> V_204 & V_174 ) ) {
if ( V_182 -> V_134 == V_214 &&
( V_213 -> V_204 & F_51 ( V_206 ) ) )
return 0 ;
return - V_136 ;
}
if ( V_182 -> V_134 == V_214 ) {
V_211 = F_51 ( V_206 ) ;
if ( ! ( V_213 -> V_204 & V_211 ) ||
( V_206 == 1000 ) ||
( V_206 == 10000 ) ||
( V_206 == 40000 ) )
return - V_136 ;
V_213 -> V_215 = V_211 ;
V_213 -> V_205 = 0 ;
} else {
V_211 = F_47 ( V_182 -> V_205 ) ;
if ( ! ( V_213 -> V_204 & V_211 ) )
return - V_136 ;
V_213 -> V_215 = 0 ;
V_213 -> V_205 = V_211 | V_174 ;
}
V_213 -> V_134 = V_182 -> V_134 ;
if ( F_41 ( V_2 ) )
return F_54 ( V_32 -> V_12 , V_32 -> V_12 -> V_137 , V_32 -> V_124 ,
V_213 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_31 * V_32 = F_34 ( V_2 ) ;
V_217 -> V_134 = ( V_32 -> V_133 . V_218 & V_219 ) != 0 ;
V_217 -> V_220 = ( V_32 -> V_133 . V_221 & V_222 ) != 0 ;
V_217 -> V_223 = ( V_32 -> V_133 . V_221 & V_224 ) != 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_31 * V_32 = F_34 ( V_2 ) ;
struct V_212 * V_213 = & V_32 -> V_133 ;
if ( V_217 -> V_134 == V_214 )
V_213 -> V_218 = 0 ;
else if ( V_213 -> V_204 & V_174 )
V_213 -> V_218 = V_219 ;
else
return - V_136 ;
if ( V_217 -> V_220 )
V_213 -> V_218 |= V_222 ;
if ( V_217 -> V_223 )
V_213 -> V_218 |= V_224 ;
if ( F_41 ( V_2 ) )
return F_54 ( V_32 -> V_12 , V_32 -> V_12 -> V_137 , V_32 -> V_124 ,
V_213 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_225 * V_226 )
{
const struct V_31 * V_121 = F_34 ( V_2 ) ;
const struct V_38 * V_34 = & V_121 -> V_12 -> V_38 ;
V_226 -> V_227 = V_228 ;
V_226 -> V_229 = V_230 ;
V_226 -> V_231 = 0 ;
V_226 -> V_232 = V_233 ;
V_226 -> V_234 = V_34 -> V_43 [ V_121 -> V_40 ] . V_235 . V_236 - 8 ;
V_226 -> V_237 = V_34 -> V_43 [ V_121 -> V_40 ] . V_238 . V_236 ;
V_226 -> V_239 = 0 ;
V_226 -> V_240 = V_34 -> V_39 [ V_121 -> V_40 ] . V_241 . V_236 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_225 * V_226 )
{
int V_35 ;
const struct V_31 * V_121 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_121 -> V_12 ;
struct V_38 * V_34 = & V_12 -> V_38 ;
if ( V_226 -> V_234 > V_228 || V_226 -> V_239 ||
V_226 -> V_240 > V_233 ||
V_226 -> V_237 > V_230 ||
V_226 -> V_237 < V_242 ||
V_226 -> V_234 < V_243 || V_226 -> V_240 < V_244 )
return - V_136 ;
if ( V_12 -> V_245 & V_246 )
return - V_247 ;
for ( V_35 = 0 ; V_35 < V_121 -> V_44 ; ++ V_35 ) {
V_34 -> V_39 [ V_121 -> V_40 + V_35 ] . V_241 . V_236 = V_226 -> V_240 ;
V_34 -> V_43 [ V_121 -> V_40 + V_35 ] . V_235 . V_236 = V_226 -> V_234 + 8 ;
V_34 -> V_43 [ V_121 -> V_40 + V_35 ] . V_238 . V_236 = V_226 -> V_237 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
unsigned int V_248 , unsigned int V_249 )
{
int V_35 , V_250 ;
struct V_31 * V_121 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_121 -> V_12 ;
struct V_41 * V_241 = & V_13 -> V_38 . V_43 [ V_121 -> V_40 ] ;
for ( V_35 = 0 ; V_35 < V_121 -> V_44 ; V_35 ++ , V_241 ++ ) {
V_250 = F_60 ( & V_241 -> V_238 , V_248 , V_249 ) ;
if ( V_250 )
return V_250 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int V_251 )
{
int V_35 ;
struct V_31 * V_121 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_121 -> V_12 ;
struct V_41 * V_241 = & V_13 -> V_38 . V_43 [ V_121 -> V_40 ] ;
for ( V_35 = 0 ; V_35 < V_121 -> V_44 ; V_35 ++ , V_241 ++ )
V_241 -> V_238 . V_251 = V_251 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_31 * V_121 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_121 -> V_12 ;
struct V_41 * V_241 = & V_13 -> V_38 . V_43 [ V_121 -> V_40 ] ;
return V_241 -> V_238 . V_251 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_252 * V_253 )
{
F_61 ( V_2 , V_253 -> V_254 ) ;
return F_59 ( V_2 , V_253 -> V_255 ,
V_253 -> V_256 ) ;
}
static int F_64 ( struct V_1 * V_2 , struct V_252 * V_253 )
{
const struct V_31 * V_121 = F_34 ( V_2 ) ;
const struct V_12 * V_13 = V_121 -> V_12 ;
const struct V_257 * V_258 = & V_13 -> V_38 . V_43 [ V_121 -> V_40 ] . V_238 ;
V_253 -> V_255 = F_65 ( V_13 , V_258 ) ;
V_253 -> V_256 = ( V_258 -> V_259 & V_260 ) ?
V_13 -> V_38 . V_261 [ V_258 -> V_262 ] : 0 ;
V_253 -> V_254 = F_62 ( V_2 ) ;
return 0 ;
}
static int F_66 ( unsigned int V_263 , unsigned int V_264 , unsigned int V_265 )
{
V_264 *= V_265 ;
if ( V_263 < 1024 )
return V_263 + ( 31 << 10 ) ;
if ( V_263 < 1024 + V_264 )
return 31744 - V_264 + V_263 - 1024 ;
if ( V_263 < V_14 )
return V_263 - 1024 - V_264 ;
return - V_136 ;
}
static int F_67 ( struct V_12 * V_13 , unsigned int V_263 , T_1 * V_94 )
{
int V_266 = F_66 ( V_263 , V_13 -> V_137 , V_267 ) ;
if ( V_266 >= 0 )
V_266 = F_68 ( V_13 -> V_23 , V_266 , sizeof( T_1 ) , V_94 ) ;
return V_266 < 0 ? V_266 : 0 ;
}
static int F_69 ( struct V_12 * V_13 , unsigned int V_263 , T_1 V_94 )
{
int V_266 = F_66 ( V_263 , V_13 -> V_137 , V_267 ) ;
if ( V_266 >= 0 )
V_266 = F_70 ( V_13 -> V_23 , V_266 , sizeof( T_1 ) , & V_94 ) ;
return V_266 < 0 ? V_266 : 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_268 * V_226 ,
T_2 * V_30 )
{
int V_35 , V_250 = 0 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
T_2 * V_130 = F_72 ( V_14 , V_269 ) ;
if ( ! V_130 )
return - V_270 ;
V_226 -> V_271 = V_272 ;
for ( V_35 = V_226 -> V_273 & ~ 3 ; ! V_250 && V_35 < V_226 -> V_273 + V_226 -> V_274 ; V_35 += 4 )
V_250 = F_67 ( V_12 , V_35 , ( T_1 * ) & V_130 [ V_35 ] ) ;
if ( ! V_250 )
memcpy ( V_30 , V_130 + V_226 -> V_273 , V_226 -> V_274 ) ;
F_73 ( V_130 ) ;
return V_250 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_268 * V_275 ,
T_2 * V_30 )
{
T_2 * V_130 ;
int V_250 = 0 ;
T_1 V_276 , V_277 , * V_32 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
if ( V_275 -> V_271 != V_272 )
return - V_136 ;
V_276 = V_275 -> V_273 & ~ 3 ;
V_277 = ( V_275 -> V_274 + ( V_275 -> V_273 & 3 ) + 3 ) & ~ 3 ;
if ( V_12 -> V_137 > 0 ) {
T_1 V_278 = 1024 + V_12 -> V_137 * V_267 ;
if ( V_276 < V_278 ||
V_276 + V_277 > V_278 + V_267 )
return - V_279 ;
}
if ( V_276 != V_275 -> V_273 || V_277 != V_275 -> V_274 ) {
V_130 = F_72 ( V_277 , V_269 ) ;
if ( ! V_130 )
return - V_270 ;
V_250 = F_67 ( V_12 , V_276 , ( T_1 * ) V_130 ) ;
if ( ! V_250 && V_277 > 4 )
V_250 = F_67 ( V_12 ,
V_276 + V_277 - 4 ,
( T_1 * ) & V_130 [ V_277 - 4 ] ) ;
if ( V_250 )
goto V_280;
memcpy ( V_130 + ( V_275 -> V_273 & 3 ) , V_30 , V_275 -> V_274 ) ;
} else {
V_130 = V_30 ;
}
V_250 = F_75 ( V_12 , false ) ;
if ( V_250 )
goto V_280;
for ( V_32 = ( T_1 * ) V_130 ; ! V_250 && V_277 ; V_277 -= 4 , V_32 ++ ) {
V_250 = F_69 ( V_12 , V_276 , * V_32 ) ;
V_276 += 4 ;
}
if ( ! V_250 )
V_250 = F_75 ( V_12 , true ) ;
V_280:
if ( V_130 != V_30 )
F_73 ( V_130 ) ;
return V_250 ;
}
static int F_76 ( struct V_1 * V_281 , struct V_282 * V_283 )
{
int V_284 ;
const struct V_285 * V_286 ;
struct V_12 * V_13 = F_2 ( V_281 ) ;
unsigned int V_287 = V_288 + 1 ;
T_1 V_289 ;
unsigned int V_290 ;
T_2 V_291 = 0 ;
V_289 = F_28 ( V_13 , V_292 ) ;
V_290 = F_77 ( V_289 ) ;
if ( V_289 & V_293 )
V_291 = 1 ;
if ( V_291 && ( V_290 != V_13 -> V_137 ) ) {
F_78 ( V_13 -> V_294 ,
L_3 ) ;
return - V_11 ;
}
V_283 -> V_30 [ sizeof( V_283 -> V_30 ) - 1 ] = '\0' ;
V_284 = F_79 ( & V_286 , V_283 -> V_30 , V_13 -> V_294 ) ;
if ( V_284 < 0 )
return V_284 ;
if ( V_13 -> V_245 & V_246 )
V_287 = V_13 -> V_287 ;
V_284 = F_80 ( V_13 , V_287 , V_286 -> V_30 , V_286 -> V_236 , 1 ) ;
F_81 ( V_286 ) ;
if ( ! V_284 )
F_82 ( V_13 -> V_294 ,
L_4 , V_283 -> V_30 ) ;
return V_284 ;
}
static T_1 F_83 ( struct V_1 * V_2 )
{
const struct V_31 * V_121 = F_34 ( V_2 ) ;
return V_121 -> V_295 ;
}
static int F_84 ( struct V_1 * V_2 , T_1 * V_32 , T_2 * V_296 , T_2 * V_297 )
{
const struct V_31 * V_121 = F_34 ( V_2 ) ;
unsigned int V_298 = V_121 -> V_295 ;
if ( V_297 )
* V_297 = V_299 ;
if ( ! V_32 )
return 0 ;
while ( V_298 -- )
V_32 [ V_298 ] = V_121 -> V_300 [ V_298 ] ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , const T_1 * V_32 , const T_2 * V_296 ,
const T_2 V_297 )
{
unsigned int V_35 ;
struct V_31 * V_121 = F_34 ( V_2 ) ;
if ( V_296 ||
( V_297 != V_301 && V_297 != V_299 ) )
return - V_11 ;
if ( ! V_32 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_121 -> V_295 ; V_35 ++ )
V_121 -> V_300 [ V_35 ] = V_32 [ V_35 ] ;
if ( V_121 -> V_12 -> V_245 & V_246 )
return F_86 ( V_121 , V_121 -> V_300 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_302 * V_16 ,
T_1 * V_303 )
{
const struct V_31 * V_121 = F_34 ( V_2 ) ;
switch ( V_16 -> V_182 ) {
case V_304 : {
unsigned int V_94 = V_121 -> V_305 ;
V_16 -> V_30 = 0 ;
switch ( V_16 -> V_306 ) {
case V_307 :
if ( V_94 & V_308 )
V_16 -> V_30 = V_309 | V_310 |
V_311 | V_312 ;
else if ( V_94 & V_313 )
V_16 -> V_30 = V_309 | V_310 ;
break;
case V_314 :
if ( ( V_94 & V_308 ) &&
( V_94 & V_315 ) )
V_16 -> V_30 = V_309 | V_310 |
V_311 | V_312 ;
else if ( V_94 & V_313 )
V_16 -> V_30 = V_309 | V_310 ;
break;
case V_316 :
case V_317 :
case V_318 :
if ( V_94 & V_313 )
V_16 -> V_30 = V_309 | V_310 ;
break;
case V_319 :
if ( V_94 & V_320 )
V_16 -> V_30 = V_309 | V_310 |
V_311 | V_312 ;
else if ( V_94 & V_321 )
V_16 -> V_30 = V_309 | V_310 ;
break;
case V_322 :
if ( ( V_94 & V_320 ) &&
( V_94 & V_315 ) )
V_16 -> V_30 = V_309 | V_310 |
V_311 | V_312 ;
else if ( V_94 & V_321 )
V_16 -> V_30 = V_309 | V_310 ;
break;
case V_323 :
case V_324 :
case V_325 :
if ( V_94 & V_321 )
V_16 -> V_30 = V_309 | V_310 ;
break;
}
return 0 ;
}
case V_326 :
V_16 -> V_30 = V_121 -> V_44 ;
return 0 ;
}
return - V_11 ;
}
void F_88 ( struct V_1 * V_281 )
{
V_281 -> V_327 = & V_328 ;
}
