static void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_8 | V_9 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_8 | V_9 ) ;
}
static void
F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_10 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_10 ) ;
}
static void
F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_11 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_11 ) ;
}
static void
F_7 ( struct V_1 * V_2 ,
const void * V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const T_2 * V_13 = V_12 ;
F_8 ( V_5 , V_6 , V_7 ,
V_14 ,
* V_13 << V_15 ) ;
}
static void
F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_16 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_16 ) ;
}
static void
F_10 ( struct V_1 * V_2 , const void * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_18 * V_19 = V_17 ;
F_11 ( V_5 , ( V_19 -> V_20 == 1 ? 0 : V_21 ) |
( V_19 -> V_22 == 1 ? 0 : V_23 ) |
( V_19 -> V_24 << V_25 ) ,
V_6 , V_26 ) ;
}
static void
F_12 ( struct V_1 * V_2 , const void * V_27 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_28 * V_29 = V_27 ;
unsigned int V_30 ;
F_11 ( V_5 , V_29 -> V_31 , V_6 , V_32 ) ;
F_11 ( V_5 , V_33 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
F_11 ( V_5 , V_29 -> V_36 [ V_30 ] ,
V_6 , V_37 ) ;
}
}
static void
F_13 ( struct V_1 * V_2 , const void * V_38 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_39 * V_40 = V_38 ;
F_11 ( V_5 , V_40 -> V_41 [ 0 ] ,
V_6 , V_42 ) ;
F_11 ( V_5 , V_40 -> V_41 [ 1 ] ,
V_6 , V_43 ) ;
F_11 ( V_5 , V_40 -> V_41 [ 2 ] ,
V_6 , V_44 ) ;
F_11 ( V_5 , V_40 -> V_41 [ 3 ] ,
V_6 , V_45 ) ;
F_8 ( V_5 , V_6 , V_7 ,
V_46 ,
V_40 -> V_47 ? V_46 : 0 ) ;
}
static void
F_14 ( struct V_1 * V_2 , const void * V_48 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_49 * V_50 = V_48 ;
unsigned int V_30 ;
F_8 ( V_5 , V_6 , V_7 ,
V_51 ,
V_50 -> V_52 << V_53 ) ;
F_11 ( V_5 ,
( V_50 -> V_54 << V_55 ) |
( V_50 -> V_56 << V_57 ) ,
V_6 , V_58 ) ;
F_11 ( V_5 , V_59 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_60 ; V_30 ++ ) {
F_11 ( V_5 , V_50 -> V_36 [ V_30 ] ,
V_6 , V_37 ) ;
}
}
static void
F_15 ( struct V_1 * V_2 , const void * V_61 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_62 * V_63 = V_61 ;
unsigned int V_30 ;
F_11 ( V_5 , V_64 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ )
F_11 ( V_5 , V_63 -> V_66 [ V_30 ] , V_6 ,
V_37 ) ;
F_11 ( V_5 , V_67 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ )
F_11 ( V_5 , V_63 -> V_68 [ V_30 ] , V_6 ,
V_37 ) ;
F_11 ( V_5 , V_69 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ )
F_11 ( V_5 , V_63 -> V_70 [ V_30 ] , V_6 ,
V_37 ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
const void * V_71 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_72 * V_73 = V_71 ;
unsigned int V_30 ;
F_11 ( V_5 , V_74 ,
V_6 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_75 ; V_30 ++ ) {
F_11 ( V_5 , V_73 -> V_36 [ V_30 ] ,
V_6 , V_37 ) ;
}
}
static void
F_17 ( struct V_1 * V_2 ,
const void * V_76 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_77 * V_78 = V_76 ;
F_11 ( V_5 ,
V_78 -> V_79 | ( V_78 -> V_24 << V_80 ) |
( V_78 -> V_81 << V_82 ) ,
V_6 , V_83 ) ;
}
static void
F_18 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_84 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_84 ) ;
}
static void
F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_85 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_85 ) ;
}
static void
F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_86 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_86 ) ;
}
static void
F_21 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_87 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_87 ) ;
}
static void
F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_88 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_88 ) ;
}
static void
F_23 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_5 , V_6 , V_7 ,
V_89 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_89 ) ;
}
static void
F_24 ( struct V_1 * V_2 , const void * V_90 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_91 * V_92 = V_90 ;
T_2 V_93 ;
F_11 ( V_5 , V_92 -> V_94 , V_6 , V_95 ) ;
V_93 = V_92 -> V_96 << V_97 ;
V_93 |= V_92 -> V_98 << V_99 ;
V_93 |= V_92 -> V_100 << V_101 ;
V_93 |= V_92 -> V_102 << V_103 ;
F_11 ( V_5 , V_93 , V_6 , V_104 ) ;
F_11 ( V_5 ,
V_105 << V_106 |
V_107 << V_108 |
V_105 << V_109 |
V_107 << V_110 |
V_111 << V_112 |
V_113 << V_114 |
V_111 << V_115 |
V_113 << V_116 |
V_105 << V_117 |
V_107 << V_118 |
V_105 << V_119 |
V_107 << V_120 |
V_111 << V_121 |
V_113 << V_122 |
V_111 << V_123 |
V_113 << V_124 ,
V_6 , V_125 ) ;
}
static void
F_25 ( struct V_1 * V_2 , const void * V_126 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_127 * V_128 = V_126 ;
F_11 ( V_5 , ( V_128 -> V_70 << V_129 ) |
( V_128 -> V_68 << V_130 ) |
( V_128 -> V_66 << V_131 ) ,
V_6 , V_132 ) ;
}
static void
F_26 ( struct V_1 * V_2 , const void * V_133 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_134 * V_135 = V_133 ;
T_2 V_93 ;
V_93 = ( V_135 -> V_136 [ 0 ] [ 0 ] & 0xfff ) << V_137 ;
V_93 |= ( V_135 -> V_136 [ 0 ] [ 1 ] & 0xfff ) << V_138 ;
F_11 ( V_5 , V_93 , V_6 , V_139 ) ;
V_93 = ( V_135 -> V_136 [ 0 ] [ 2 ] & 0xfff ) << V_140 ;
V_93 |= ( V_135 -> V_136 [ 1 ] [ 0 ] & 0xfff ) << V_141 ;
F_11 ( V_5 , V_93 , V_6 , V_142 ) ;
V_93 = ( V_135 -> V_136 [ 1 ] [ 1 ] & 0xfff ) << V_143 ;
V_93 |= ( V_135 -> V_136 [ 1 ] [ 2 ] & 0xfff ) << V_144 ;
F_11 ( V_5 , V_93 , V_6 , V_145 ) ;
V_93 = ( V_135 -> V_136 [ 2 ] [ 0 ] & 0xfff ) << V_146 ;
V_93 |= ( V_135 -> V_136 [ 2 ] [ 1 ] & 0xfff ) << V_147 ;
F_11 ( V_5 , V_93 , V_6 , V_148 ) ;
V_93 = ( V_135 -> V_136 [ 2 ] [ 2 ] & 0xfff ) << V_149 ;
F_11 ( V_5 , V_93 , V_6 , V_150 ) ;
V_93 = ( V_135 -> V_151 [ 0 ] & 0x3ff ) << V_152 ;
V_93 |= ( V_135 -> V_151 [ 1 ] & 0x3ff ) << V_153 ;
F_11 ( V_5 , V_93 , V_6 , V_154 ) ;
V_93 = ( V_135 -> V_151 [ 2 ] & 0x3ff ) << V_155 ;
F_11 ( V_5 , V_93 , V_6 , V_156 ) ;
}
static void
F_27 ( struct V_1 * V_2 , const void * V_157 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_158 * V_159 = V_157 ;
T_2 V_93 ;
V_93 = ( V_159 -> V_136 [ 0 ] [ 0 ] & 0x3ff ) << V_160 ;
V_93 |= ( V_159 -> V_136 [ 0 ] [ 1 ] & 0x3ff ) << V_161 ;
V_93 |= ( V_159 -> V_136 [ 0 ] [ 2 ] & 0x3ff ) << V_162 ;
F_11 ( V_5 , V_93 , V_6 , V_163 ) ;
V_93 = ( V_159 -> V_136 [ 1 ] [ 0 ] & 0x3ff ) << V_164 ;
V_93 |= ( V_159 -> V_136 [ 1 ] [ 1 ] & 0x3ff ) << V_165 ;
V_93 |= ( V_159 -> V_136 [ 1 ] [ 2 ] & 0x3ff ) << V_166 ;
F_11 ( V_5 , V_93 , V_6 , V_167 ) ;
V_93 = ( V_159 -> V_136 [ 2 ] [ 0 ] & 0x3ff ) << V_168 ;
V_93 |= ( V_159 -> V_136 [ 2 ] [ 1 ] & 0x3ff ) << V_169 ;
V_93 |= ( V_159 -> V_136 [ 2 ] [ 2 ] & 0x3ff ) << V_170 ;
F_11 ( V_5 , V_93 , V_6 , V_171 ) ;
V_93 = ( V_159 -> V_151 [ 0 ] & 0xff ) << V_172 ;
V_93 |= ( V_159 -> V_151 [ 1 ] & 0xff ) << V_173 ;
V_93 |= ( V_159 -> V_151 [ 2 ] & 0xff ) << V_174 ;
F_11 ( V_5 , V_93 , V_6 , V_175 ) ;
}
static void
F_28 ( struct V_1 * V_2 , T_1 V_176 )
{
struct V_177 * V_178 = & V_2 -> V_178 ;
if ( V_178 -> V_176 != ( V_176 * V_179 ) ) {
V_178 -> V_176 = V_176 * V_179 ;
V_2 -> V_180 |= V_181 ;
}
}
static void
F_29 ( struct V_1 * V_2 , const void * V_178 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_8 ( V_5 , V_6 , V_182 ,
0xff << V_183 ,
* ( T_1 * ) V_178 << V_183 ) ;
}
static void
F_30 ( struct V_1 * V_2 , T_1 V_184 )
{
struct V_177 * V_178 = & V_2 -> V_178 ;
if ( V_178 -> V_184 != ( V_184 * V_185 ) ) {
V_178 -> V_184 = V_184 * V_185 ;
V_2 -> V_180 |= V_186 ;
}
}
static void
F_31 ( struct V_1 * V_2 , const void * V_178 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_8 ( V_5 , V_6 , V_182 ,
0xff << V_187 ,
* ( T_1 * ) V_178 << V_187 ) ;
}
static void
F_32 ( struct V_1 * V_2 , const void * V_188 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_189 * V_190 = V_188 ;
F_11 ( V_5 ,
V_190 -> V_191 << V_192 |
V_190 -> V_193 << V_194 |
V_190 -> V_195 << V_196 |
V_190 -> V_197 << V_198 ,
V_6 , V_199 ) ;
}
static T_2
F_33 ( struct V_177 * V_178 , void * * V_200 ,
struct V_201 * V_202 ,
void T_3 * * V_203 , T_2 V_204 )
{
#define F_34 ( T_4 , T_5 , T_6 ) \
if (cfgs && cfg) { \
*(cfg) = (cfgs)->field; \
}
switch ( V_204 ) {
case V_205 :
* V_200 = & V_178 -> V_19 ;
F_34 (configs, config, hmed)
return sizeof( V_178 -> V_19 ) ;
case V_206 :
* V_200 = & V_178 -> V_29 ;
F_34 (configs, config, nf)
return sizeof( V_178 -> V_29 ) ;
break;
case V_207 :
* V_200 = & V_178 -> V_50 ;
F_34 (configs, config, cfa)
return sizeof( V_178 -> V_50 ) ;
case V_208 :
* V_200 = & V_178 -> V_209 ;
F_34 (configs, config, luma)
return sizeof( V_178 -> V_209 ) ;
case V_210 :
* V_200 = & V_178 -> V_76 ;
F_34 (configs, config, csup)
return sizeof( V_178 -> V_76 ) ;
case V_211 :
* V_200 = & V_178 -> V_40 ;
F_34 (configs, config, dcor)
return sizeof( V_178 -> V_40 ) ;
case V_212 :
* V_200 = & V_178 -> V_213 ;
F_34 (configs, config, blkadj)
return sizeof( V_178 -> V_213 ) ;
case V_214 :
* V_200 = & V_178 -> V_188 ;
F_34 (configs, config, yclimit)
return sizeof( V_178 -> V_188 ) ;
case V_215 :
* V_200 = & V_178 -> V_133 ;
F_34 (configs, config, rgb2rgb)
return sizeof( V_178 -> V_133 ) ;
case V_216 :
* V_200 = & V_178 -> V_217 ;
F_34 (configs, config, csc)
return sizeof( V_178 -> V_217 ) ;
case V_218 :
* V_200 = & V_178 -> V_92 ;
F_34 (configs, config, wbal)
return sizeof( V_178 -> V_92 ) ;
case V_219 :
* V_200 = & V_178 -> gamma ;
F_34 (configs, config, gamma)
return sizeof( V_178 -> gamma ) ;
case V_181 :
* V_200 = & V_178 -> V_176 ;
return 0 ;
case V_186 :
* V_200 = & V_178 -> V_184 ;
return 0 ;
default:
* V_200 = NULL ;
* V_203 = NULL ;
break;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_201 * T_5 )
{
struct V_177 * V_178 ;
struct V_220 * V_221 ;
int V_30 , V_204 , V_222 = 0 ;
V_178 = & V_2 -> V_178 ;
if ( V_2 -> V_223 != V_224 ) {
unsigned long V_225 ;
F_36 ( & V_2 -> V_226 , V_225 ) ;
V_2 -> V_227 = 1 ;
F_37 ( & V_2 -> V_226 , V_225 ) ;
}
for ( V_30 = 0 ; V_30 < F_38 ( V_228 ) ; V_30 ++ ) {
V_221 = & V_228 [ V_30 ] ;
V_204 = 0 ;
if ( ! ( T_5 -> V_180 & V_221 -> V_229 ) )
continue;
V_204 = T_5 -> V_230 & V_221 -> V_229 ;
if ( V_204 ) {
void * V_231 = NULL , T_3 * V_232 = NULL ;
unsigned long V_233 = 0 ;
V_233 = F_33 ( V_178 , & V_231 , T_5 , & V_232 ,
V_204 ) ;
if ( V_231 && V_232 && V_233 ) {
if ( F_39 ( V_231 , V_232 , V_233 ) ) {
V_222 = - V_234 ;
break;
}
}
V_178 -> V_235 |= V_221 -> V_236 ;
} else {
V_178 -> V_235 &= ~ V_221 -> V_236 ;
}
V_2 -> V_180 |= V_221 -> V_236 ;
}
V_2 -> V_227 = 0 ;
return V_222 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_177 * V_178 = & V_2 -> V_178 ;
struct V_220 * V_221 ;
int V_30 , V_204 ;
void * V_237 ;
for ( V_30 = 0 ; V_30 < F_38 ( V_228 ) ; V_30 ++ ) {
V_221 = & V_228 [ V_30 ] ;
if ( ! ( V_2 -> V_180 & V_221 -> V_236 ) )
continue;
V_204 = V_178 -> V_235 & V_221 -> V_236 ;
if ( V_204 ) {
if ( V_221 -> V_203 ) {
F_33 ( V_178 , & V_237 , NULL ,
NULL , V_204 ) ;
V_221 -> V_203 ( V_2 , V_237 ) ;
}
if ( V_221 -> V_3 )
V_221 -> V_3 ( V_2 , 1 ) ;
} else
if ( V_221 -> V_3 )
V_221 -> V_3 ( V_2 , 0 ) ;
V_2 -> V_180 &= ~ V_221 -> V_236 ;
}
}
static void
F_41 ( struct V_1 * V_2 ,
enum V_238 V_239 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
enum V_240 V_241 ;
switch ( V_239 ) {
case V_242 :
V_241 = V_243 ;
break;
case V_244 :
V_241 = V_245 ;
break;
default:
return;
}
F_8 ( V_5 , V_6 , V_7 ,
V_246 ,
V_241 << V_247 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_1 V_248 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_249 = 0 ;
if ( V_2 -> V_178 . V_50 . V_52 == V_250 )
V_249 = V_251 << V_252 |
V_253 << V_254 |
V_248 ;
else if ( V_2 -> V_178 . V_50 . V_52 == V_255 )
V_249 = V_256 << V_252 |
V_257 << V_254 |
V_248 ;
F_11 ( V_5 , V_249 , V_6 , V_258 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_177 * V_178 = & V_2 -> V_178 ;
unsigned int V_259 = V_2 -> V_260 . V_261 ;
unsigned int V_262 = V_2 -> V_260 . V_261 + V_2 -> V_260 . V_263 - 1 ;
unsigned int V_264 = V_2 -> V_260 . V_265 ;
unsigned int V_266 = V_2 -> V_260 . V_265 + V_2 -> V_260 . V_267 - 1 ;
if ( V_178 -> V_235 & V_207 ) {
V_259 -= 2 ;
V_262 += 2 ;
V_264 -= 2 ;
V_266 += 2 ;
}
if ( V_178 -> V_235 & ( V_211 | V_206 ) ) {
V_259 -= 2 ;
V_262 += 2 ;
V_264 -= 2 ;
V_266 += 2 ;
}
if ( V_178 -> V_235 & V_205 ) {
V_259 -= 2 ;
V_262 += 2 ;
}
if ( V_178 -> V_235 & ( V_210 | V_208 ) )
V_259 -= 2 ;
F_11 ( V_5 , ( V_259 << V_268 ) | V_262 ,
V_6 , V_269 ) ;
F_11 ( V_5 , ( V_264 << V_270 ) | V_266 ,
V_6 , V_271 ) ;
}
static void
F_44 ( struct V_1 * V_2 , T_2 V_151 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_151 & 0xffff , V_6 ,
V_272 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_273 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_273 , V_6 , V_274 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
T_2 V_151 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_151 & 0xffff , V_6 ,
V_275 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_2 V_273 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( V_5 , V_273 , V_6 , V_276 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_277 * V_278 = F_49 ( & V_2 -> V_279 . V_280 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_281 * V_282 = & V_2 -> V_283 [ V_284 ] ;
unsigned long V_285 = V_278 -> V_285 ;
struct V_286 * V_287 ;
unsigned int V_288 ;
unsigned int V_289 ;
unsigned int V_290 ;
unsigned int V_291 ;
unsigned int V_292 ;
unsigned int V_293 ;
if ( V_2 -> V_294 != V_295 ) {
F_4 ( V_5 , V_296 , V_297 ,
V_298 ) ;
return;
}
V_290 = F_50 ( ( V_299 ) V_285 / 2 * 256 + V_278 -> V_300 - 1 ,
V_278 -> V_300 ) ;
V_291 = F_51 ( V_290 , 32 ) ;
V_287 = & V_278 -> V_301 ;
V_289 = F_51 ( V_282 -> V_263 * 2 , 256 ) * V_282 -> V_267 ;
V_288 = F_50 ( ( V_299 ) V_285 * V_287 -> V_302 ,
V_287 -> V_303 ) ;
V_290 = V_288 / V_289 ;
V_292 = V_290 / 32 ;
V_293 = F_52 ( V_291 , V_292 ) ;
F_53 ( V_5 -> V_304 , L_1 , V_305 , V_293 ) ;
F_8 ( V_5 , V_296 , V_297 ,
V_298 ,
V_293 << V_306 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_55 ( V_5 , V_6 , V_7 )
& V_307 ;
}
void F_56 ( struct V_4 * V_5 )
{
V_5 -> V_308 . V_180 = V_309 - 1 ;
F_40 ( & V_5 -> V_308 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_53 ( V_5 -> V_304 , L_2 ) ;
F_58 ( V_5 , V_310 ) ;
F_58 ( V_5 , V_311 ) ;
F_58 ( V_5 , V_312 ) ;
F_58 ( V_5 , V_313 ) ;
F_58 ( V_5 , V_314 ) ;
F_58 ( V_5 , V_315 ) ;
F_58 ( V_5 , V_316 ) ;
F_58 ( V_5 , V_317 ) ;
F_58 ( V_5 , V_318 ) ;
F_58 ( V_5 , V_319 ) ;
F_58 ( V_5 , V_320 ) ;
F_58 ( V_5 , V_321 ) ;
F_58 ( V_5 , V_322 ) ;
F_58 ( V_5 , V_323 ) ;
F_58 ( V_5 , V_324 ) ;
F_58 ( V_5 , V_325 ) ;
F_58 ( V_5 , V_326 ) ;
F_58 ( V_5 , V_327 ) ;
F_58 ( V_5 , V_328 ) ;
F_58 ( V_5 , V_329 ) ;
F_58 ( V_5 , V_330 ) ;
F_58 ( V_5 , V_331 ) ;
F_58 ( V_5 , V_332 ) ;
F_58 ( V_5 , V_333 ) ;
F_58 ( V_5 , V_334 ) ;
F_58 ( V_5 , V_335 ) ;
F_58 ( V_5 , V_336 ) ;
F_58 ( V_5 , V_337 ) ;
F_58 ( V_5 , V_338 ) ;
F_58 ( V_5 , V_339 ) ;
F_58 ( V_5 , V_340 ) ;
F_58 ( V_5 , V_341 ) ;
F_58 ( V_5 , V_342 ) ;
F_58 ( V_5 , V_343 ) ;
F_58 ( V_5 , V_344 ) ;
F_58 ( V_5 , V_345 ) ;
F_53 ( V_5 -> V_304 , L_3 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_177 * V_178 = & V_2 -> V_178 ;
int V_30 = 0 ;
V_178 -> V_176 = V_346 * V_179 ;
V_178 -> V_184 = V_347 * V_185 ;
V_178 -> V_50 . V_52 = V_250 ;
memcpy ( V_178 -> V_50 . V_36 , V_348 ,
sizeof( V_178 -> V_50 . V_36 ) ) ;
V_178 -> V_50 . V_56 = V_349 ;
V_178 -> V_50 . V_54 = V_350 ;
V_178 -> V_76 . V_79 = V_351 ;
V_178 -> V_76 . V_24 = V_352 ;
V_178 -> V_76 . V_81 = 0 ;
memcpy ( V_178 -> V_209 . V_36 , V_353 ,
sizeof( V_178 -> V_209 . V_36 ) ) ;
V_178 -> V_29 . V_31 = V_354 ;
memcpy ( V_178 -> V_29 . V_36 , V_355 , sizeof( V_178 -> V_29 . V_36 ) ) ;
V_178 -> V_40 . V_47 = 1 ;
for ( V_30 = 0 ; V_30 < V_356 ; V_30 ++ )
V_178 -> V_40 . V_41 [ V_30 ] = V_357 ;
memcpy ( V_178 -> gamma . V_70 , V_358 , sizeof( V_178 -> gamma . V_70 ) ) ;
memcpy ( V_178 -> gamma . V_68 , V_358 , sizeof( V_178 -> gamma . V_68 ) ) ;
memcpy ( V_178 -> gamma . V_66 , V_358 , sizeof( V_178 -> gamma . V_66 ) ) ;
V_178 -> V_92 . V_94 = V_359 ;
V_178 -> V_92 . V_96 = V_360 ;
V_178 -> V_92 . V_98 = V_360 ;
V_178 -> V_92 . V_100 = V_360 ;
V_178 -> V_92 . V_102 = V_360 ;
V_178 -> V_213 . V_66 = V_361 ;
V_178 -> V_213 . V_68 = V_362 ;
V_178 -> V_213 . V_70 = V_363 ;
V_178 -> V_133 = V_364 ;
V_178 -> V_217 = V_365 ;
V_178 -> V_188 . V_195 = V_366 ;
V_178 -> V_188 . V_191 = V_367 ;
V_178 -> V_188 . V_197 = V_366 ;
V_178 -> V_188 . V_193 = V_367 ;
V_178 -> V_235 = V_207 | V_211 | V_206
| V_219 | V_212 | V_214
| V_215 | V_216 | V_218
| V_186 | V_181 ;
V_2 -> V_180 = V_309 - 1 ;
}
static unsigned int F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_368 ) {
case V_369 :
return V_370 ;
case V_371 :
default:
return V_372 ;
case V_373 :
return V_374 ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_281 * V_52 ;
F_40 ( V_2 ) ;
if ( V_2 -> V_375 & V_376 )
F_3 ( V_5 , V_6 , V_7 ,
V_377 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_377 ) ;
if ( V_2 -> V_375 & V_378 )
F_3 ( V_5 , V_6 , V_7 ,
V_379 ) ;
else
F_4 ( V_5 , V_6 , V_7 ,
V_379 ) ;
V_52 = & V_2 -> V_283 [ V_284 ] ;
F_48 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( V_2 -> V_294 == V_380 )
F_44 ( V_2 , 0 ) ;
else
F_44 ( V_2 ,
F_62 ( V_52 -> V_263 , 0x20 ) * 2 ) ;
V_52 = & V_2 -> V_283 [ V_381 ] ;
if ( V_2 -> V_375 & V_376 )
F_46 ( V_2 ,
F_62 ( V_52 -> V_263 , 0x10 ) * 2 ) ;
F_42 ( V_2 , 0 ) ;
F_41 ( V_2 , V_52 -> V_382 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_2 -> V_294 == V_295 )
F_3 ( V_5 , V_6 , V_7 ,
V_383 ) ;
F_3 ( V_5 , V_6 , V_7 ,
V_384 | V_385 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_223 == V_386 &&
V_2 -> V_387 . V_388 & V_389 ) {
F_63 ( V_2 ) ;
F_65 ( & V_2 -> V_387 ) ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_277 * V_278 = F_49 ( & V_2 -> V_279 . V_280 ) ;
struct V_390 * V_391 ;
int V_392 = 0 ;
if ( V_2 -> V_294 == V_295 ) {
V_391 = F_67 ( & V_2 -> V_393 ) ;
if ( V_391 != NULL )
F_45 ( V_2 , V_391 -> V_394 ) ;
V_278 -> V_223 |= V_395 ;
}
if ( V_2 -> V_375 & V_376 ) {
V_391 = F_67 ( & V_2 -> V_387 ) ;
if ( V_391 != NULL ) {
F_47 ( V_2 , V_391 -> V_394 ) ;
V_392 = 1 ;
}
V_278 -> V_223 |= V_396 ;
}
switch ( V_2 -> V_223 ) {
case V_397 :
if ( F_68 ( V_278 ) )
F_69 ( V_278 ,
V_397 ) ;
break;
case V_386 :
if ( V_392 )
F_63 ( V_2 ) ;
break;
case V_224 :
default:
return;
}
}
void F_70 ( struct V_1 * V_2 )
{
unsigned long V_225 ;
if ( F_71 ( & V_2 -> V_398 , & V_2 -> V_399 ) )
return;
F_36 ( & V_2 -> V_226 , V_225 ) ;
if ( V_2 -> V_227 )
goto V_400;
F_40 ( V_2 ) ;
F_43 ( V_2 ) ;
V_400:
F_37 ( & V_2 -> V_226 , V_225 ) ;
if ( V_2 -> V_294 == V_295 ||
V_2 -> V_375 & V_376 )
F_66 ( V_2 ) ;
else if ( V_2 -> V_223 == V_386 )
F_63 ( V_2 ) ;
}
static int F_72 ( struct V_401 * V_402 ,
struct V_390 * V_391 )
{
struct V_1 * V_2 = & V_402 -> V_5 -> V_308 ;
if ( V_402 -> type == V_403 )
F_45 ( V_2 , V_391 -> V_394 ) ;
if ( V_402 -> type == V_404 )
F_47 ( V_2 , V_391 -> V_394 ) ;
return 0 ;
}
static int F_73 ( struct V_405 * V_406 )
{
struct V_1 * V_2 =
F_74 ( V_406 -> V_407 , struct V_1 , V_408 ) ;
switch ( V_406 -> V_409 ) {
case V_410 :
F_30 ( V_2 , V_406 -> V_93 ) ;
break;
case V_411 :
F_28 ( V_2 , V_406 -> V_93 ) ;
break;
}
return 0 ;
}
static long F_75 ( struct V_412 * V_413 , unsigned int V_414 , void * V_415 )
{
struct V_1 * V_2 = F_76 ( V_413 ) ;
switch ( V_414 ) {
case V_416 :
return F_35 ( V_2 , V_415 ) ;
default:
return - V_417 ;
}
}
static int F_77 ( struct V_412 * V_413 , int V_3 )
{
struct V_1 * V_2 = F_76 ( V_413 ) ;
struct V_401 * V_387 = & V_2 -> V_387 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_418 * V_304 = F_78 ( V_2 ) ;
unsigned long V_225 ;
if ( V_2 -> V_223 == V_224 ) {
if ( V_3 == V_224 )
return 0 ;
F_79 ( V_5 , V_419 ) ;
F_61 ( V_2 ) ;
F_80 ( & V_2 -> V_399 , 0 ) ;
F_57 ( V_2 ) ;
}
switch ( V_3 ) {
case V_386 :
if ( V_2 -> V_375 & V_376 )
F_81 ( V_5 , V_420 ) ;
if ( V_387 -> V_388 & V_389 ||
! ( V_2 -> V_375 & V_376 ) )
F_63 ( V_2 ) ;
F_65 ( V_387 ) ;
break;
case V_397 :
if ( V_2 -> V_294 == V_295 )
F_81 ( V_5 , V_421 ) ;
if ( V_2 -> V_375 & V_376 )
F_81 ( V_5 , V_420 ) ;
F_63 ( V_2 ) ;
break;
case V_224 :
if ( F_82 ( & V_413 -> V_280 , & V_2 -> V_398 ,
& V_2 -> V_399 ) )
F_53 ( V_304 , L_4 , V_413 -> V_422 ) ;
F_36 ( & V_2 -> V_226 , V_225 ) ;
F_83 ( V_5 , V_421 ) ;
F_83 ( V_5 , V_420 ) ;
F_84 ( V_5 , V_419 ) ;
F_37 ( & V_2 -> V_226 , V_225 ) ;
F_65 ( V_387 ) ;
break;
}
V_2 -> V_223 = V_3 ;
return 0 ;
}
static struct V_281 *
F_85 ( struct V_1 * V_2 , struct V_423 * V_424 ,
unsigned int V_425 , enum V_426 V_427 )
{
if ( V_427 == V_428 )
return F_86 ( V_424 , V_425 ) ;
else
return & V_2 -> V_283 [ V_425 ] ;
}
static struct V_429 *
F_87 ( struct V_1 * V_2 , struct V_423 * V_424 ,
enum V_426 V_427 )
{
if ( V_427 == V_428 )
return F_88 ( V_424 , V_284 ) ;
else
return & V_2 -> V_260 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_423 * V_424 , unsigned int V_425 ,
struct V_281 * V_430 ,
enum V_426 V_427 )
{
enum V_238 V_239 ;
struct V_429 * V_260 ;
unsigned int V_30 ;
switch ( V_425 ) {
case V_284 :
if ( V_2 -> V_294 == V_295 ) {
V_430 -> V_263 = F_90 ( T_2 , V_430 -> V_263 , V_431 ,
F_60 ( V_2 ) ) ;
V_430 -> V_267 = F_90 ( T_2 , V_430 -> V_267 ,
V_432 ,
V_433 ) ;
}
V_430 -> V_434 = V_435 ;
for ( V_30 = 0 ; V_30 < F_38 ( V_436 ) ; V_30 ++ ) {
if ( V_430 -> V_382 == V_436 [ V_30 ] )
break;
}
if ( V_30 >= F_38 ( V_436 ) )
V_430 -> V_382 = V_437 ;
break;
case V_381 :
V_239 = V_430 -> V_382 ;
* V_430 = * F_85 ( V_2 , V_424 , V_284 , V_427 ) ;
switch ( V_239 ) {
case V_242 :
case V_244 :
V_430 -> V_382 = V_239 ;
break;
default:
V_430 -> V_382 = V_242 ;
break;
}
V_260 = F_87 ( V_2 , V_424 , V_427 ) ;
V_430 -> V_263 = V_260 -> V_263 ;
V_430 -> V_267 = V_260 -> V_267 ;
V_430 -> V_434 = V_438 ;
break;
}
V_430 -> T_6 = V_439 ;
}
static void F_91 ( struct V_1 * V_2 ,
const struct V_281 * V_440 ,
struct V_429 * V_260 )
{
unsigned int V_261 = V_441 ;
unsigned int V_442 = V_440 -> V_263 - V_443 ;
unsigned int V_265 = V_444 ;
unsigned int V_445 = V_440 -> V_267 - V_446 ;
if ( V_2 -> V_294 == V_380 ) {
V_261 += 2 ;
V_442 -= 2 ;
}
V_260 -> V_261 &= ~ 1 ;
V_260 -> V_265 &= ~ 1 ;
V_260 -> V_261 = F_90 ( T_2 , V_260 -> V_261 , V_261 , V_442 - V_447 ) ;
V_260 -> V_265 = F_90 ( T_2 , V_260 -> V_265 , V_265 , V_445 - V_448 ) ;
V_260 -> V_263 = F_90 ( T_2 , V_260 -> V_263 , V_447 ,
V_442 - V_260 -> V_261 ) ;
V_260 -> V_267 = F_90 ( T_2 , V_260 -> V_267 , V_448 ,
V_445 - V_260 -> V_265 ) ;
}
static int F_92 ( struct V_412 * V_413 ,
struct V_423 * V_424 ,
struct V_449 * V_382 )
{
switch ( V_382 -> V_425 ) {
case V_284 :
if ( V_382 -> V_450 >= F_38 ( V_436 ) )
return - V_451 ;
V_382 -> V_382 = V_436 [ V_382 -> V_450 ] ;
break;
case V_381 :
if ( V_382 -> V_450 >= F_38 ( V_452 ) )
return - V_451 ;
V_382 -> V_382 = V_452 [ V_382 -> V_450 ] ;
break;
default:
return - V_451 ;
}
return 0 ;
}
static int F_93 ( struct V_412 * V_413 ,
struct V_423 * V_424 ,
struct V_453 * V_454 )
{
struct V_1 * V_2 = F_76 ( V_413 ) ;
struct V_281 V_52 ;
if ( V_454 -> V_450 != 0 )
return - V_451 ;
V_52 . V_382 = V_454 -> V_382 ;
V_52 . V_263 = 1 ;
V_52 . V_267 = 1 ;
F_89 ( V_2 , V_424 , V_454 -> V_425 , & V_52 , V_428 ) ;
V_454 -> V_455 = V_52 . V_263 ;
V_454 -> V_456 = V_52 . V_267 ;
if ( V_52 . V_382 != V_454 -> V_382 )
return - V_451 ;
V_52 . V_382 = V_454 -> V_382 ;
V_52 . V_263 = - 1 ;
V_52 . V_267 = - 1 ;
F_89 ( V_2 , V_424 , V_454 -> V_425 , & V_52 , V_428 ) ;
V_454 -> V_457 = V_52 . V_263 ;
V_454 -> V_458 = V_52 . V_267 ;
return 0 ;
}
static int F_94 ( struct V_412 * V_413 , struct V_423 * V_424 ,
struct V_459 * V_260 )
{
struct V_1 * V_2 = F_76 ( V_413 ) ;
if ( V_260 -> V_425 != V_284 )
return - V_451 ;
V_260 -> V_460 = * F_87 ( V_2 , V_424 , V_260 -> V_427 ) ;
return 0 ;
}
static int F_95 ( struct V_412 * V_413 , struct V_423 * V_424 ,
struct V_459 * V_260 )
{
struct V_1 * V_2 = F_76 ( V_413 ) ;
struct V_281 * V_52 ;
if ( V_260 -> V_425 != V_284 )
return - V_451 ;
if ( V_2 -> V_223 != V_224 )
return - V_461 ;
V_52 = F_85 ( V_2 , V_424 , V_284 , V_260 -> V_427 ) ;
F_91 ( V_2 , V_52 , & V_260 -> V_460 ) ;
* F_87 ( V_2 , V_424 , V_260 -> V_427 ) = V_260 -> V_460 ;
V_52 = F_85 ( V_2 , V_424 , V_381 , V_260 -> V_427 ) ;
F_89 ( V_2 , V_424 , V_381 , V_52 , V_260 -> V_427 ) ;
return 0 ;
}
static int F_96 ( struct V_412 * V_413 , struct V_423 * V_424 ,
struct V_462 * V_430 )
{
struct V_1 * V_2 = F_76 ( V_413 ) ;
struct V_281 * V_52 ;
V_52 = F_85 ( V_2 , V_424 , V_430 -> V_425 , V_430 -> V_427 ) ;
if ( V_52 == NULL )
return - V_451 ;
V_430 -> V_52 = * V_52 ;
return 0 ;
}
static int F_97 ( struct V_412 * V_413 , struct V_423 * V_424 ,
struct V_462 * V_430 )
{
struct V_1 * V_2 = F_76 ( V_413 ) ;
struct V_281 * V_52 ;
struct V_429 * V_260 ;
V_52 = F_85 ( V_2 , V_424 , V_430 -> V_425 , V_430 -> V_427 ) ;
if ( V_52 == NULL )
return - V_451 ;
F_89 ( V_2 , V_424 , V_430 -> V_425 , & V_430 -> V_52 , V_430 -> V_427 ) ;
* V_52 = V_430 -> V_52 ;
if ( V_430 -> V_425 == V_284 ) {
V_260 = F_87 ( V_2 , V_424 , V_430 -> V_427 ) ;
V_260 -> V_261 = 0 ;
V_260 -> V_265 = 0 ;
V_260 -> V_263 = V_430 -> V_52 . V_263 ;
V_260 -> V_267 = V_430 -> V_52 . V_267 ;
F_91 ( V_2 , & V_430 -> V_52 , V_260 ) ;
V_52 = F_85 ( V_2 , V_424 , V_381 ,
V_430 -> V_427 ) ;
F_89 ( V_2 , V_424 , V_381 , V_52 ,
V_430 -> V_427 ) ;
}
return 0 ;
}
static int F_98 ( struct V_412 * V_413 ,
struct V_423 * V_424 )
{
struct V_462 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_425 = V_284 ;
V_52 . V_427 = V_424 ? V_428 : V_463 ;
V_52 . V_52 . V_382 = V_437 ;
V_52 . V_52 . V_263 = 4096 ;
V_52 . V_52 . V_267 = 4096 ;
F_97 ( V_413 , V_424 , & V_52 ) ;
return 0 ;
}
static int F_99 ( struct V_464 * V_280 ,
const struct V_465 * V_466 ,
const struct V_465 * V_467 , T_2 V_225 )
{
struct V_412 * V_413 = F_100 ( V_280 ) ;
struct V_1 * V_2 = F_76 ( V_413 ) ;
switch ( V_466 -> V_450 | F_101 ( V_467 -> V_280 ) ) {
case V_284 | V_468 :
if ( V_225 & V_469 ) {
if ( V_2 -> V_294 == V_380 )
return - V_461 ;
V_2 -> V_294 = V_295 ;
} else {
if ( V_2 -> V_294 == V_295 )
V_2 -> V_294 = V_470 ;
}
break;
case V_284 | V_471 :
if ( V_225 & V_469 ) {
if ( V_2 -> V_294 == V_295 )
return - V_461 ;
V_2 -> V_294 = V_380 ;
} else {
if ( V_2 -> V_294 == V_380 )
V_2 -> V_294 = V_470 ;
}
break;
case V_381 | V_468 :
if ( V_225 & V_469 ) {
if ( V_2 -> V_375 & ~ V_376 )
return - V_461 ;
V_2 -> V_375 |= V_376 ;
} else {
V_2 -> V_375 &= ~ V_376 ;
}
break;
case V_381 | V_471 :
if ( V_225 & V_469 ) {
if ( V_2 -> V_375 & ~ V_378 )
return - V_461 ;
V_2 -> V_375 |= V_378 ;
} else {
V_2 -> V_375 &= ~ V_378 ;
}
break;
default:
return - V_451 ;
}
return 0 ;
}
void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_279 ) ;
F_104 ( & V_2 -> V_393 ) ;
F_104 ( & V_2 -> V_387 ) ;
}
int F_105 ( struct V_1 * V_2 ,
struct V_472 * V_473 )
{
int V_474 ;
V_474 = F_106 ( V_473 , & V_2 -> V_279 ) ;
if ( V_474 < 0 )
goto error;
V_474 = F_107 ( & V_2 -> V_393 , V_473 ) ;
if ( V_474 < 0 )
goto error;
V_474 = F_107 ( & V_2 -> V_387 , V_473 ) ;
if ( V_474 < 0 )
goto error;
return 0 ;
error:
F_102 ( V_2 ) ;
return V_474 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_412 * V_413 = & V_2 -> V_279 ;
struct V_465 * V_475 = V_2 -> V_475 ;
struct V_464 * V_476 = & V_413 -> V_280 ;
int V_474 ;
V_2 -> V_294 = V_470 ;
F_109 ( V_413 , & V_477 ) ;
V_413 -> V_478 = & V_479 ;
F_110 ( V_413 -> V_422 , L_5 , sizeof( V_413 -> V_422 ) ) ;
V_413 -> V_480 = 1 << 16 ;
F_111 ( V_413 , V_2 ) ;
V_413 -> V_225 |= V_481 ;
F_112 ( & V_2 -> V_408 , 2 ) ;
F_113 ( & V_2 -> V_408 , & V_482 , V_410 ,
V_483 , V_484 ,
V_485 , V_347 ) ;
F_113 ( & V_2 -> V_408 , & V_482 , V_411 ,
V_486 , V_487 ,
V_488 , V_346 ) ;
F_114 ( & V_2 -> V_408 ) ;
V_413 -> V_489 = & V_2 -> V_408 ;
V_475 [ V_284 ] . V_225 = V_490 ;
V_475 [ V_381 ] . V_225 = V_491 ;
V_476 -> V_492 = & V_493 ;
V_474 = F_115 ( V_476 , V_494 , V_475 , 0 ) ;
if ( V_474 < 0 )
return V_474 ;
F_98 ( V_413 , NULL ) ;
V_2 -> V_393 . type = V_403 ;
V_2 -> V_393 . V_492 = & V_495 ;
V_2 -> V_393 . V_5 = F_2 ( V_2 ) ;
V_2 -> V_393 . V_496 = F_116 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_393 . V_497 = 64 ;
V_2 -> V_387 . type = V_404 ;
V_2 -> V_387 . V_492 = & V_495 ;
V_2 -> V_387 . V_5 = F_2 ( V_2 ) ;
V_2 -> V_387 . V_496 = F_116 ( 4096 * 4096 ) * 2 * 3 ;
V_2 -> V_387 . V_497 = 32 ;
V_474 = F_117 ( & V_2 -> V_393 , L_6 ) ;
if ( V_474 < 0 )
goto V_498;
V_474 = F_117 ( & V_2 -> V_387 , L_6 ) ;
if ( V_474 < 0 )
goto V_499;
V_474 = F_118 ( & V_2 -> V_393 . V_402 . V_280 , 0 ,
& V_2 -> V_279 . V_280 , V_284 , 0 ) ;
if ( V_474 < 0 )
goto V_500;
V_474 = F_118 ( & V_2 -> V_279 . V_280 , V_381 ,
& V_2 -> V_387 . V_402 . V_280 , 0 , 0 ) ;
if ( V_474 < 0 )
goto V_500;
return 0 ;
V_500:
F_119 ( & V_2 -> V_387 ) ;
V_499:
F_119 ( & V_2 -> V_393 ) ;
V_498:
F_120 ( & V_2 -> V_279 . V_280 ) ;
return V_474 ;
}
int F_121 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_308 ;
F_122 ( & V_2 -> V_226 ) ;
F_123 ( & V_2 -> V_398 ) ;
F_59 ( V_2 ) ;
return F_108 ( V_2 ) ;
}
void F_124 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_308 ;
F_125 ( & V_2 -> V_408 ) ;
F_119 ( & V_2 -> V_393 ) ;
F_119 ( & V_2 -> V_387 ) ;
F_120 ( & V_2 -> V_279 . V_280 ) ;
}
