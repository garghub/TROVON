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
V_16 -> V_24 = F_6 ( V_2 ) ;
if ( ! V_12 -> V_25 . V_26 )
strcpy ( V_16 -> V_27 , L_1 ) ;
else
snprintf ( V_16 -> V_27 , sizeof( V_16 -> V_27 ) ,
L_2 ,
F_12 ( V_12 -> V_25 . V_26 ) ,
F_13 ( V_12 -> V_25 . V_26 ) ,
F_14 ( V_12 -> V_25 . V_26 ) ,
F_15 ( V_12 -> V_25 . V_26 ) ,
F_12 ( V_12 -> V_25 . V_28 ) ,
F_13 ( V_12 -> V_25 . V_28 ) ,
F_14 ( V_12 -> V_25 . V_28 ) ,
F_15 ( V_12 -> V_25 . V_28 ) ) ;
if ( ! F_16 ( V_12 , & V_17 ) )
snprintf ( V_16 -> V_29 , sizeof( V_16 -> V_29 ) ,
L_3 ,
F_12 ( V_17 ) ,
F_13 ( V_17 ) ,
F_14 ( V_17 ) ,
F_15 ( V_17 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_30 , T_2 * V_31 )
{
if ( V_30 == V_6 ) {
memcpy ( V_31 , V_7 , sizeof( V_7 ) ) ;
V_31 += sizeof( V_7 ) ;
memcpy ( V_31 , V_8 ,
sizeof( V_8 ) ) ;
V_31 += sizeof( V_8 ) ;
memcpy ( V_31 , V_9 ,
sizeof( V_9 ) ) ;
V_31 += sizeof( V_9 ) ;
memcpy ( V_31 , V_10 ,
sizeof( V_10 ) ) ;
}
}
static void F_18 ( const struct V_12 * V_13 ,
const struct V_32 * V_33 ,
struct V_34 * V_35 )
{
int V_36 ;
const struct V_37 * V_38 = & V_13 -> V_39 . V_40 [ V_33 -> V_41 ] ;
const struct V_42 * V_43 = & V_13 -> V_39 . V_44 [ V_33 -> V_41 ] ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
for ( V_36 = 0 ; V_36 < V_33 -> V_45 ; V_36 ++ , V_43 ++ , V_38 ++ ) {
V_35 -> V_46 += V_38 -> V_46 ;
V_35 -> V_47 += V_38 -> V_48 ;
V_35 -> V_49 += V_43 -> V_50 . V_51 ;
V_35 -> V_52 += V_43 -> V_50 . V_52 ;
V_35 -> V_53 += V_38 -> V_53 ;
V_35 -> V_54 += V_43 -> V_50 . V_55 ;
V_35 -> V_56 += V_43 -> V_50 . V_57 ;
}
}
static void F_19 ( struct V_12 * V_13 , struct V_58 * V_35 )
{
struct V_59 V_60 , V_61 ;
struct V_62 V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
T_3 V_68 , V_69 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
F_20 ( & V_13 -> V_70 ) ;
F_21 ( V_13 , & V_60 , & V_61 ) ;
F_22 ( V_13 , & V_63 ) ;
F_23 ( V_13 , & V_67 ) ;
F_24 ( V_13 , & V_65 ) ;
F_25 ( & V_13 -> V_70 ) ;
V_35 -> V_71 = V_13 -> V_72 . V_71 ;
V_35 -> V_73 = V_13 -> V_72 . V_73 ;
V_35 -> V_74 = V_13 -> V_72 . V_74 ;
V_35 -> V_75 = V_60 . V_76 ;
V_35 -> V_77 = V_60 . V_78 ;
V_35 -> V_79 = V_60 . V_80 ;
V_35 -> V_81 = V_60 . V_82 ;
V_35 -> V_83 = V_61 . V_76 ;
V_35 -> V_84 = V_61 . V_78 ;
V_35 -> V_85 = V_61 . V_80 ;
V_35 -> V_86 = V_61 . V_82 ;
if ( F_26 ( V_13 ) ) {
V_35 -> V_87 = V_67 . V_87 ;
V_35 -> V_88 = V_67 . V_88 ;
V_35 -> V_89 = V_67 . V_89 ;
V_35 -> V_90 = V_63 . V_90 ;
V_35 -> V_91 = V_63 . V_91 ;
}
V_35 -> V_92 = V_65 . V_92 ;
V_35 -> V_93 = V_65 . V_93 ;
if ( ! F_27 ( V_13 -> V_25 . V_94 ) ) {
int V_95 ;
V_95 = F_28 ( V_13 , V_96 ) ;
if ( F_29 ( V_95 ) == 7 ) {
V_69 = F_28 ( V_13 , V_97 ) ;
V_68 = F_28 ( V_13 , V_98 ) ;
V_35 -> V_99 = V_68 - V_69 ;
V_35 -> V_100 = V_69 ;
}
}
}
static void F_30 ( struct V_12 * V_13 , struct V_101 * V_35 ,
T_2 V_36 )
{
struct V_102 V_103 ;
struct V_64 V_65 ;
struct V_104 V_105 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
F_20 ( & V_13 -> V_70 ) ;
F_31 ( V_13 , & V_103 ) ;
F_24 ( V_13 , & V_65 ) ;
F_32 ( V_13 , V_36 , & V_105 ) ;
F_25 ( & V_13 -> V_70 ) ;
V_35 -> V_106 = V_103 . V_107 [ V_36 ] ;
V_35 -> V_108 = V_103 . V_109 [ V_36 ] ;
V_35 -> V_110 = V_65 . V_110 [ V_36 ] ;
V_35 -> V_111 = V_65 . V_111 [ V_36 ] ;
V_35 -> V_112 = V_65 . V_112 [ V_36 ] ;
V_35 -> V_113 = V_65 . V_113 [ V_36 ] ;
V_35 -> V_114 = V_65 . V_114 [ V_36 ] ;
V_35 -> V_115 = V_65 . V_115 [ V_36 ] ;
V_35 -> V_116 = V_65 . V_116 [ V_36 ] ;
V_35 -> V_117 = V_65 . V_117 [ V_36 ] ;
V_35 -> V_118 = V_105 . V_118 ;
V_35 -> V_119 = V_105 . V_119 ;
V_35 -> V_120 = V_105 . V_120 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_121 * V_50 ,
T_3 * V_31 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
struct V_123 V_35 ;
int V_36 ;
T_3 * V_124 ;
F_35 ( V_12 , V_122 -> V_125 ,
(struct V_126 * ) V_31 ,
& V_122 -> V_127 ) ;
V_31 += sizeof( struct V_126 ) / sizeof( T_3 ) ;
F_18 ( V_12 , V_122 , (struct V_34 * ) V_31 ) ;
V_31 += sizeof( struct V_34 ) / sizeof( T_3 ) ;
F_19 ( V_12 , (struct V_58 * ) V_31 ) ;
V_31 += sizeof( struct V_58 ) / sizeof( T_3 ) ;
* V_31 ++ = ( T_3 ) V_122 -> V_128 ;
F_30 ( V_12 , (struct V_101 * ) V_31 ,
V_122 -> V_128 ) ;
V_31 += sizeof( struct V_101 ) / sizeof( T_3 ) ;
* V_31 ++ = ( T_3 ) V_122 -> V_128 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_36 ( V_12 , V_122 -> V_128 , & V_35 ) ;
V_124 = & V_35 . V_88 ;
for ( V_36 = 0 ; V_36 < F_5 ( V_10 ) - 1 ; V_36 ++ )
* V_31 ++ = ( unsigned long long ) * V_124 ++ ;
}
static void F_37 ( struct V_1 * V_2 , struct V_129 * V_130 ,
void * V_131 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
T_4 V_132 ;
V_132 = F_7 ( V_13 ) ;
V_130 -> V_20 = F_38 ( V_13 ) ;
F_39 ( V_13 , V_131 , V_132 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
if ( ! F_41 ( V_2 ) )
return - V_133 ;
if ( V_33 -> V_134 . V_135 != V_136 )
return - V_137 ;
F_42 ( V_33 -> V_12 , V_33 -> V_12 -> V_138 , V_33 -> V_125 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
enum V_139 V_140 )
{
unsigned int V_4 ;
struct V_12 * V_13 = F_2 ( V_2 ) ;
if ( V_140 == V_141 )
V_4 = 0xffff ;
else if ( V_140 == V_142 )
V_4 = 0 ;
else
return - V_137 ;
return F_44 ( V_13 , V_13 -> V_138 , F_45 ( V_2 ) -> V_143 , V_4 ) ;
}
static unsigned int F_46 ( enum V_144 type , unsigned int V_145 )
{
unsigned int V_95 = 0 ;
if ( type == V_146 || type == V_147 ||
type == V_148 ) {
V_95 |= V_149 ;
if ( V_145 & V_150 )
V_95 |= V_151 ;
if ( V_145 & V_152 )
V_95 |= V_153 ;
if ( V_145 & V_154 )
V_95 |= V_155 ;
} else if ( type == V_156 || type == V_157 ) {
V_95 |= V_158 ;
if ( V_145 & V_152 )
V_95 |= V_159 ;
if ( V_145 & V_154 )
V_95 |= V_160 ;
} else if ( type == V_161 ) {
V_95 |= V_158 | V_162 ;
} else if ( type == V_163 ) {
V_95 |= V_158 | V_164 |
V_162 | V_159 ;
} else if ( type == V_165 ) {
V_95 |= V_158 | V_164 |
V_162 | V_159 |
V_160 ;
} else if ( type == V_166 ||
type == V_167 ||
type == V_168 ||
type == V_169 ||
type == V_170 ) {
V_95 |= V_171 ;
if ( V_145 & V_152 )
V_95 |= V_153 ;
if ( V_145 & V_154 )
V_95 |= V_155 ;
} else if ( type == V_172 ||
type == V_173 ) {
V_95 |= V_174 ;
V_95 |= V_171 ;
}
if ( V_145 & V_175 )
V_95 |= V_176 ;
return V_95 ;
}
static unsigned int F_47 ( unsigned int V_145 )
{
unsigned int V_95 = 0 ;
if ( V_145 & V_177 )
V_95 |= V_150 ;
if ( V_145 & V_178 )
V_95 |= V_152 ;
if ( V_145 & V_179 )
V_95 |= V_154 ;
if ( V_145 & V_180 )
V_95 |= V_181 ;
return V_95 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_182 * V_183 )
{
const struct V_32 * V_33 = F_34 ( V_2 ) ;
if ( V_33 -> V_184 == V_146 ||
V_33 -> V_184 == V_147 ||
V_33 -> V_184 == V_148 ) {
V_183 -> V_185 = V_186 ;
} else if ( V_33 -> V_184 == V_166 ||
V_33 -> V_184 == V_167 ) {
V_183 -> V_185 = V_187 ;
} else if ( V_33 -> V_184 == V_168 ||
V_33 -> V_184 == V_169 ||
V_33 -> V_184 == V_170 ||
V_33 -> V_184 == V_173 ) {
if ( V_33 -> V_188 == V_189 ||
V_33 -> V_188 == V_190 ||
V_33 -> V_188 == V_191 ||
V_33 -> V_188 == V_192 )
V_183 -> V_185 = V_187 ;
else if ( V_33 -> V_188 == V_193 ||
V_33 -> V_188 == V_194 )
V_183 -> V_185 = V_195 ;
else
V_183 -> V_185 = V_196 ;
} else {
V_183 -> V_185 = V_196 ;
}
if ( V_33 -> V_197 >= 0 ) {
V_183 -> V_198 = V_33 -> V_197 ;
V_183 -> V_199 = V_200 ;
V_183 -> V_201 = V_33 -> V_184 == V_146 ?
V_202 : V_203 ;
} else {
V_183 -> V_198 = 0 ;
V_183 -> V_199 = V_204 ;
V_183 -> V_201 = 0 ;
}
V_183 -> V_205 = F_46 ( V_33 -> V_184 , V_33 -> V_134 . V_205 ) ;
V_183 -> V_206 = F_46 ( V_33 -> V_184 ,
V_33 -> V_134 . V_206 ) ;
F_49 ( V_183 ,
F_50 ( V_2 ) ? V_33 -> V_134 . V_207 : 0 ) ;
V_183 -> V_208 = V_209 ;
V_183 -> V_135 = V_33 -> V_134 . V_135 ;
V_183 -> V_210 = 0 ;
V_183 -> V_211 = 0 ;
return 0 ;
}
static unsigned int F_51 ( int V_207 )
{
if ( V_207 == 100 )
return V_150 ;
if ( V_207 == 1000 )
return V_152 ;
if ( V_207 == 10000 )
return V_154 ;
if ( V_207 == 40000 )
return V_181 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_182 * V_183 )
{
unsigned int V_212 ;
struct V_32 * V_33 = F_34 ( V_2 ) ;
struct V_213 * V_214 = & V_33 -> V_134 ;
T_1 V_207 = F_53 ( V_183 ) ;
struct V_213 V_215 ;
int V_216 ;
if ( V_183 -> V_208 != V_209 )
return - V_137 ;
if ( ! ( V_214 -> V_205 & V_175 ) ) {
if ( V_183 -> V_135 == V_217 &&
( V_214 -> V_205 & F_51 ( V_207 ) ) )
return 0 ;
return - V_137 ;
}
V_215 = * V_214 ;
if ( V_183 -> V_135 == V_217 ) {
V_212 = F_51 ( V_207 ) ;
if ( ! ( V_214 -> V_205 & V_212 ) )
return - V_137 ;
V_214 -> V_218 = V_212 ;
V_214 -> V_206 = 0 ;
} else {
V_212 = F_47 ( V_183 -> V_206 ) ;
if ( ! ( V_214 -> V_205 & V_212 ) )
return - V_137 ;
V_214 -> V_218 = 0 ;
V_214 -> V_206 = V_212 | V_175 ;
}
V_214 -> V_135 = V_183 -> V_135 ;
V_216 = F_54 ( V_33 -> V_12 , V_33 -> V_12 -> V_219 , V_33 -> V_125 , V_214 ) ;
if ( V_216 )
* V_214 = V_215 ;
return V_216 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_220 * V_221 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
V_221 -> V_135 = ( V_33 -> V_134 . V_222 & V_223 ) != 0 ;
V_221 -> V_224 = ( V_33 -> V_134 . V_225 & V_226 ) != 0 ;
V_221 -> V_227 = ( V_33 -> V_134 . V_225 & V_228 ) != 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_220 * V_221 )
{
struct V_32 * V_33 = F_34 ( V_2 ) ;
struct V_213 * V_214 = & V_33 -> V_134 ;
if ( V_221 -> V_135 == V_217 )
V_214 -> V_222 = 0 ;
else if ( V_214 -> V_205 & V_175 )
V_214 -> V_222 = V_223 ;
else
return - V_137 ;
if ( V_221 -> V_224 )
V_214 -> V_222 |= V_226 ;
if ( V_221 -> V_227 )
V_214 -> V_222 |= V_228 ;
if ( F_41 ( V_2 ) )
return F_54 ( V_33 -> V_12 , V_33 -> V_12 -> V_219 , V_33 -> V_125 ,
V_214 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_229 * V_230 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_39 * V_35 = & V_122 -> V_12 -> V_39 ;
V_230 -> V_231 = V_232 ;
V_230 -> V_233 = V_234 ;
V_230 -> V_235 = 0 ;
V_230 -> V_236 = V_237 ;
V_230 -> V_238 = V_35 -> V_44 [ V_122 -> V_41 ] . V_239 . V_240 - 8 ;
V_230 -> V_241 = V_35 -> V_44 [ V_122 -> V_41 ] . V_242 . V_240 ;
V_230 -> V_243 = 0 ;
V_230 -> V_244 = V_35 -> V_40 [ V_122 -> V_41 ] . V_245 . V_240 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_229 * V_230 )
{
int V_36 ;
const struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_12 = V_122 -> V_12 ;
struct V_39 * V_35 = & V_12 -> V_39 ;
if ( V_230 -> V_238 > V_232 || V_230 -> V_243 ||
V_230 -> V_244 > V_237 ||
V_230 -> V_241 > V_234 ||
V_230 -> V_241 < V_246 ||
V_230 -> V_238 < V_247 || V_230 -> V_244 < V_248 )
return - V_137 ;
if ( V_12 -> V_249 & V_250 )
return - V_251 ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; ++ V_36 ) {
V_35 -> V_40 [ V_122 -> V_41 + V_36 ] . V_245 . V_240 = V_230 -> V_244 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_239 . V_240 = V_230 -> V_238 + 8 ;
V_35 -> V_44 [ V_122 -> V_41 + V_36 ] . V_242 . V_240 = V_230 -> V_241 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
unsigned int V_252 , unsigned int V_253 )
{
int V_36 , V_254 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_245 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_245 ++ ) {
V_254 = F_60 ( & V_245 -> V_242 , V_252 , V_253 ) ;
if ( V_254 )
return V_254 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int V_255 )
{
int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_245 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
for ( V_36 = 0 ; V_36 < V_122 -> V_45 ; V_36 ++ , V_245 ++ )
V_245 -> V_242 . V_255 = V_255 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_32 * V_122 = F_34 ( V_2 ) ;
struct V_12 * V_13 = V_122 -> V_12 ;
struct V_42 * V_245 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] ;
return V_245 -> V_242 . V_255 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_256 * V_257 )
{
F_61 ( V_2 , V_257 -> V_258 ) ;
return F_59 ( V_2 , V_257 -> V_259 ,
V_257 -> V_260 ) ;
}
static int F_64 ( struct V_1 * V_2 , struct V_256 * V_257 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
const struct V_12 * V_13 = V_122 -> V_12 ;
const struct V_261 * V_262 = & V_13 -> V_39 . V_44 [ V_122 -> V_41 ] . V_242 ;
V_257 -> V_259 = F_65 ( V_13 , V_262 ) ;
V_257 -> V_260 = ( V_262 -> V_263 & V_264 ) ?
V_13 -> V_39 . V_265 [ V_262 -> V_266 ] : 0 ;
V_257 -> V_258 = F_62 ( V_2 ) ;
return 0 ;
}
static int F_66 ( unsigned int V_267 , unsigned int V_268 , unsigned int V_269 )
{
V_268 *= V_269 ;
if ( V_267 < 1024 )
return V_267 + ( 31 << 10 ) ;
if ( V_267 < 1024 + V_268 )
return 31744 - V_268 + V_267 - 1024 ;
if ( V_267 < V_14 )
return V_267 - 1024 - V_268 ;
return - V_137 ;
}
static int F_67 ( struct V_12 * V_13 , unsigned int V_267 , T_1 * V_95 )
{
int V_270 = F_66 ( V_267 , V_13 -> V_138 , V_271 ) ;
if ( V_270 >= 0 )
V_270 = F_68 ( V_13 -> V_23 , V_270 , sizeof( T_1 ) , V_95 ) ;
return V_270 < 0 ? V_270 : 0 ;
}
static int F_69 ( struct V_12 * V_13 , unsigned int V_267 , T_1 V_95 )
{
int V_270 = F_66 ( V_267 , V_13 -> V_138 , V_271 ) ;
if ( V_270 >= 0 )
V_270 = F_70 ( V_13 -> V_23 , V_270 , sizeof( T_1 ) , & V_95 ) ;
return V_270 < 0 ? V_270 : 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_272 * V_230 ,
T_2 * V_31 )
{
int V_36 , V_254 = 0 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
T_2 * V_131 = F_72 ( V_14 ) ;
if ( ! V_131 )
return - V_273 ;
V_230 -> V_274 = V_275 ;
for ( V_36 = V_230 -> V_276 & ~ 3 ; ! V_254 && V_36 < V_230 -> V_276 + V_230 -> V_277 ; V_36 += 4 )
V_254 = F_67 ( V_12 , V_36 , ( T_1 * ) & V_131 [ V_36 ] ) ;
if ( ! V_254 )
memcpy ( V_31 , V_131 + V_230 -> V_276 , V_230 -> V_277 ) ;
F_73 ( V_131 ) ;
return V_254 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_272 * V_278 ,
T_2 * V_31 )
{
T_2 * V_131 ;
int V_254 = 0 ;
T_1 V_279 , V_280 , * V_33 ;
struct V_12 * V_12 = F_2 ( V_2 ) ;
if ( V_278 -> V_274 != V_275 )
return - V_137 ;
V_279 = V_278 -> V_276 & ~ 3 ;
V_280 = ( V_278 -> V_277 + ( V_278 -> V_276 & 3 ) + 3 ) & ~ 3 ;
if ( V_12 -> V_138 > 0 ) {
T_1 V_281 = 1024 + V_12 -> V_138 * V_271 ;
if ( V_279 < V_281 ||
V_279 + V_280 > V_281 + V_271 )
return - V_282 ;
}
if ( V_279 != V_278 -> V_276 || V_280 != V_278 -> V_277 ) {
V_131 = F_72 ( V_280 ) ;
if ( ! V_131 )
return - V_273 ;
V_254 = F_67 ( V_12 , V_279 , ( T_1 * ) V_131 ) ;
if ( ! V_254 && V_280 > 4 )
V_254 = F_67 ( V_12 ,
V_279 + V_280 - 4 ,
( T_1 * ) & V_131 [ V_280 - 4 ] ) ;
if ( V_254 )
goto V_283;
memcpy ( V_131 + ( V_278 -> V_276 & 3 ) , V_31 , V_278 -> V_277 ) ;
} else {
V_131 = V_31 ;
}
V_254 = F_75 ( V_12 , false ) ;
if ( V_254 )
goto V_283;
for ( V_33 = ( T_1 * ) V_131 ; ! V_254 && V_280 ; V_280 -= 4 , V_33 ++ ) {
V_254 = F_69 ( V_12 , V_279 , * V_33 ) ;
V_279 += 4 ;
}
if ( ! V_254 )
V_254 = F_75 ( V_12 , true ) ;
V_283:
if ( V_131 != V_31 )
F_73 ( V_131 ) ;
return V_254 ;
}
static int F_76 ( struct V_1 * V_284 , struct V_285 * V_286 )
{
int V_216 ;
const struct V_287 * V_288 ;
struct V_12 * V_13 = F_2 ( V_284 ) ;
unsigned int V_219 = V_289 + 1 ;
T_1 V_290 ;
unsigned int V_291 ;
T_2 V_292 = 0 ;
V_290 = F_28 ( V_13 , V_293 ) ;
V_291 = F_77 ( V_290 ) ;
if ( V_290 & V_294 )
V_292 = 1 ;
if ( V_292 && ( V_291 != V_13 -> V_138 ) ) {
F_78 ( V_13 -> V_295 ,
L_4 ) ;
return - V_11 ;
}
V_286 -> V_31 [ sizeof( V_286 -> V_31 ) - 1 ] = '\0' ;
V_216 = F_79 ( & V_288 , V_286 -> V_31 , V_13 -> V_295 ) ;
if ( V_216 < 0 )
return V_216 ;
if ( V_13 -> V_249 & V_250 )
V_219 = V_13 -> V_219 ;
V_216 = F_80 ( V_13 , V_219 , V_288 -> V_31 , V_288 -> V_240 , 1 ) ;
F_81 ( V_288 ) ;
if ( ! V_216 )
F_82 ( V_13 -> V_295 ,
L_5 , V_286 -> V_31 ) ;
return V_216 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_296 * V_297 )
{
V_297 -> V_298 = V_299 |
V_300 |
V_301 ;
V_297 -> V_298 |= V_302 |
V_303 ;
V_297 -> V_304 = - 1 ;
return 0 ;
}
static T_1 F_84 ( struct V_1 * V_2 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
return V_122 -> V_305 ;
}
static int F_85 ( struct V_1 * V_2 , T_1 * V_33 , T_2 * V_306 , T_2 * V_307 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
unsigned int V_308 = V_122 -> V_305 ;
if ( V_307 )
* V_307 = V_309 ;
if ( ! V_33 )
return 0 ;
while ( V_308 -- )
V_33 [ V_308 ] = V_122 -> V_310 [ V_308 ] ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , const T_1 * V_33 , const T_2 * V_306 ,
const T_2 V_307 )
{
unsigned int V_36 ;
struct V_32 * V_122 = F_34 ( V_2 ) ;
if ( V_306 ||
( V_307 != V_311 && V_307 != V_309 ) )
return - V_11 ;
if ( ! V_33 )
return 0 ;
if ( V_122 -> V_12 -> V_249 & V_250 ) {
for ( V_36 = 0 ; V_36 < V_122 -> V_305 ; V_36 ++ )
V_122 -> V_310 [ V_36 ] = V_33 [ V_36 ] ;
return F_87 ( V_122 , V_122 -> V_310 ) ;
}
return - V_282 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_312 * V_16 ,
T_1 * V_313 )
{
const struct V_32 * V_122 = F_34 ( V_2 ) ;
switch ( V_16 -> V_183 ) {
case V_314 : {
unsigned int V_95 = V_122 -> V_315 ;
V_16 -> V_31 = 0 ;
switch ( V_16 -> V_316 ) {
case V_317 :
if ( V_95 & V_318 )
V_16 -> V_31 = V_319 | V_320 |
V_321 | V_322 ;
else if ( V_95 & V_323 )
V_16 -> V_31 = V_319 | V_320 ;
break;
case V_324 :
if ( ( V_95 & V_318 ) &&
( V_95 & V_325 ) )
V_16 -> V_31 = V_319 | V_320 |
V_321 | V_322 ;
else if ( V_95 & V_323 )
V_16 -> V_31 = V_319 | V_320 ;
break;
case V_326 :
case V_327 :
case V_328 :
if ( V_95 & V_323 )
V_16 -> V_31 = V_319 | V_320 ;
break;
case V_329 :
if ( V_95 & V_330 )
V_16 -> V_31 = V_319 | V_320 |
V_321 | V_322 ;
else if ( V_95 & V_331 )
V_16 -> V_31 = V_319 | V_320 ;
break;
case V_332 :
if ( ( V_95 & V_330 ) &&
( V_95 & V_325 ) )
V_16 -> V_31 = V_319 | V_320 |
V_321 | V_322 ;
else if ( V_95 & V_331 )
V_16 -> V_31 = V_319 | V_320 ;
break;
case V_333 :
case V_334 :
case V_335 :
if ( V_95 & V_331 )
V_16 -> V_31 = V_319 | V_320 ;
break;
}
return 0 ;
}
case V_336 :
V_16 -> V_31 = V_122 -> V_45 ;
return 0 ;
}
return - V_11 ;
}
void F_89 ( struct V_1 * V_284 )
{
V_284 -> V_337 = & V_338 ;
}
