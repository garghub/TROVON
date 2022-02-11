T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
if ( V_2 -> V_4 == V_5 ) {
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
V_2 -> V_20 . type = V_21 ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
V_2 -> V_20 . type = V_26 ;
break;
case V_27 :
V_2 -> V_20 . type = V_28 ;
break;
case V_29 :
case V_30 :
case V_31 :
V_2 -> V_20 . type = V_32 ;
break;
default:
V_2 -> V_20 . type = V_33 ;
break;
}
} else {
V_3 = V_34 ;
}
F_2 ( V_2 , L_1 ,
V_2 -> V_20 . type , V_3 ) ;
return V_3 ;
}
const char * F_3 ( struct V_1 * V_2 , enum V_35 V_36 )
{
switch ( V_36 ) {
case V_37 :
return L_2 ;
case V_38 :
return L_3 ;
case V_39 :
return L_4 ;
case V_40 :
return L_5 ;
case V_41 :
return L_6 ;
case V_42 :
return L_7 ;
case V_43 :
return L_8 ;
case V_44 :
return L_9 ;
case V_45 :
return L_10 ;
case V_46 :
return L_11 ;
case V_47 :
return L_12 ;
case V_48 :
return L_13 ;
case V_49 :
return L_14 ;
case V_50 :
return L_15 ;
case V_51 :
return L_16 ;
case V_52 :
return L_17 ;
case V_53 :
return L_18 ;
case V_54 :
return L_19 ;
case V_55 :
return L_20 ;
case V_56 :
return L_21 ;
case V_57 :
return L_22 ;
case V_58 :
return L_23 ;
case V_59 :
return L_24 ;
}
snprintf ( V_2 -> V_60 , sizeof( V_2 -> V_60 ) , L_25 , V_36 ) ;
return V_2 -> V_60 ;
}
const char * F_4 ( struct V_1 * V_2 , T_1 V_61 )
{
switch ( V_61 ) {
case 0 :
return L_2 ;
case V_62 :
return L_26 ;
case V_63 :
return L_27 ;
case V_64 :
return L_28 ;
case V_65 :
return L_29 ;
case V_66 :
return L_30 ;
case V_67 :
return L_31 ;
case V_68 :
return L_32 ;
case V_69 :
return L_33 ;
case V_70 :
return L_34 ;
case V_71 :
return L_35 ;
case V_34 :
return L_36 ;
case V_72 :
return L_37 ;
case V_73 :
return L_38 ;
case V_74 :
return L_39 ;
case V_75 :
return L_40 ;
case V_76 :
return L_41 ;
case V_77 :
return L_42 ;
case V_78 :
return L_43 ;
case V_79 :
return L_44 ;
case V_80 :
return L_45 ;
case V_81 :
return L_46 ;
case V_82 :
return L_47 ;
case V_83 :
return L_48 ;
case V_84 :
return L_49 ;
case V_85 :
return L_50 ;
case V_86 :
return L_51 ;
case V_87 :
return L_52 ;
case V_88 :
return L_53 ;
case V_89 :
return L_54 ;
case V_90 :
return L_55 ;
case V_91 :
return L_56 ;
case V_92 :
return L_57 ;
case V_93 :
return L_58 ;
case V_94 :
return L_59 ;
case V_95 :
return L_60 ;
case V_96 :
return L_61 ;
case V_97 :
return L_62 ;
case V_98 :
return L_63 ;
case V_99 :
return L_64 ;
case V_100 :
return L_65 ;
case V_101 :
return L_66 ;
case V_102 :
return L_67 ;
case V_103 :
return L_68 ;
case V_104 :
return L_69 ;
case V_105 :
return L_70 ;
case V_106 :
return L_71 ;
case V_107 :
return L_72 ;
case V_108 :
return L_73 ;
case V_109 :
return L_74 ;
case V_110 :
return L_75 ;
case V_111 :
return L_76 ;
case V_112 :
return L_77 ;
case V_113 :
return L_78 ;
case V_114 :
return L_79 ;
case V_115 :
return L_80 ;
case V_116 :
return L_81 ;
case V_117 :
return L_82 ;
case V_118 :
return L_83 ;
case V_119 :
return L_84 ;
case V_120 :
return L_85 ;
case V_121 :
return L_86 ;
case V_122 :
return L_87 ;
case V_123 :
return L_88 ;
case V_124 :
return L_89 ;
case V_125 :
return L_90 ;
}
snprintf ( V_2 -> V_60 , sizeof( V_2 -> V_60 ) , L_25 , V_61 ) ;
return V_2 -> V_60 ;
}
void F_5 ( struct V_1 * V_2 , enum V_126 V_127 , void * V_128 ,
void * V_129 , T_2 V_130 )
{
struct V_131 * V_132 = (struct V_131 * ) V_128 ;
T_3 * V_133 = ( T_3 * ) V_129 ;
if ( ( ! ( V_127 & V_2 -> V_134 ) ) || ( V_128 == NULL ) )
return;
F_6 ( V_2 , V_127 ,
L_91 ,
F_7 ( V_132 -> V_135 ) ,
F_7 ( V_132 -> V_136 ) ,
F_7 ( V_132 -> V_137 ) ,
F_7 ( V_132 -> V_138 ) ) ;
F_6 ( V_2 , V_127 , L_92 ,
F_8 ( V_132 -> V_139 ) ,
F_8 ( V_132 -> V_140 ) ) ;
F_6 ( V_2 , V_127 , L_93 ,
F_8 ( V_132 -> V_141 . V_142 . V_143 ) ,
F_8 ( V_132 -> V_141 . V_142 . V_144 ) ) ;
F_6 ( V_2 , V_127 , L_94 ,
F_8 ( V_132 -> V_141 . V_145 . V_146 ) ,
F_8 ( V_132 -> V_141 . V_145 . V_147 ) ) ;
if ( ( V_129 != NULL ) && ( V_132 -> V_137 != 0 ) ) {
T_2 V_148 = F_7 ( V_132 -> V_137 ) ;
F_6 ( V_2 , V_127 , L_95 ) ;
if ( V_130 < V_148 )
V_148 = V_130 ;
if ( V_2 -> V_134 & V_127 ) {
char V_149 [ 20 ] ;
snprintf ( V_149 , 20 ,
L_96 ,
V_2 -> V_150 . V_151 ,
V_2 -> V_150 . V_152 ,
V_2 -> V_150 . V_153 ) ;
F_9 ( V_154 , V_149 , V_155 ,
16 , 1 , V_133 , V_148 , false ) ;
}
}
}
bool F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_156 . V_157 . V_148 )
return ! ! ( F_11 ( V_2 , V_2 -> V_156 . V_157 . V_148 ) &
V_158 ) ;
else
return false ;
}
T_1 F_12 ( struct V_1 * V_2 ,
bool V_159 )
{
struct V_131 V_128 ;
struct V_160 * V_161 =
(struct V_160 * ) & V_128 . V_141 . V_162 ;
T_1 V_3 ;
F_13 ( & V_128 ,
V_163 ) ;
if ( V_159 )
V_161 -> V_164 = F_14 ( V_165 ) ;
V_3 = F_15 ( V_2 , & V_128 , NULL , 0 , NULL ) ;
return V_3 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
T_2 V_166 , bool V_167 ,
T_3 * V_168 , T_2 V_169 ,
bool V_170 )
{
T_1 V_3 ;
struct V_131 V_128 ;
struct V_171 * V_172 =
(struct V_171 * ) & V_128 . V_141 . V_162 ;
if ( V_170 )
F_13 ( & V_128 ,
V_173 ) ;
else
F_13 ( & V_128 ,
V_174 ) ;
V_128 . V_136 |= F_17 ( ( T_2 ) V_175 ) ;
V_128 . V_136 |= F_17 ( ( T_2 ) V_176 ) ;
V_172 -> V_166 =
F_17 ( ( T_2 ) ( ( V_166 <<
V_177 ) &
V_178 ) ) ;
V_172 -> V_166 |= F_17 ( ( T_2 ) V_179 ) ;
if ( V_167 )
V_172 -> V_136 |= F_17 ( ( T_2 )
( ( V_180 <<
V_181 ) &
V_182 ) ) ;
else
V_172 -> V_136 |= F_17 ( ( T_2 )
( ( V_183 <<
V_181 ) &
V_182 ) ) ;
V_3 = F_15 ( V_2 , & V_128 , V_168 , V_169 , NULL ) ;
return V_3 ;
}
T_1 F_18 ( struct V_1 * V_2 , T_2 V_166 ,
bool V_167 , T_3 * V_168 , T_2 V_169 )
{
return F_16 ( V_2 , V_166 , V_167 , V_168 , V_169 ,
false ) ;
}
T_1 F_19 ( struct V_1 * V_2 , T_2 V_166 ,
bool V_167 , T_3 * V_168 , T_2 V_169 )
{
return F_16 ( V_2 , V_166 , V_167 , V_168 , V_169 , true ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
T_2 V_166 ,
struct V_184 * V_185 ,
bool V_170 )
{
T_1 V_3 ;
struct V_131 V_128 ;
struct V_186 * V_172 =
(struct V_186 * ) & V_128 . V_141 . V_162 ;
T_2 V_187 = sizeof( struct V_184 ) ;
if ( V_170 )
F_13 ( & V_128 ,
V_188 ) ;
else
F_13 ( & V_128 ,
V_189 ) ;
V_128 . V_136 |= F_17 ( ( T_2 ) V_175 ) ;
V_128 . V_136 |= F_17 ( ( T_2 ) V_176 ) ;
V_172 -> V_166 =
F_17 ( ( T_2 ) ( ( V_166 <<
V_190 ) &
V_191 ) ) ;
V_172 -> V_166 |= F_17 ( ( T_2 ) V_192 ) ;
V_3 = F_15 ( V_2 , & V_128 , V_185 , V_187 , NULL ) ;
return V_3 ;
}
T_1 F_21 ( struct V_1 * V_2 ,
T_2 V_166 ,
struct V_184 * V_185 )
{
return F_20 ( V_2 , V_166 , V_185 , false ) ;
}
T_1 F_22 ( struct V_1 * V_2 ,
T_2 V_166 ,
struct V_184 * V_185 )
{
return F_20 ( V_2 , V_166 , V_185 , true ) ;
}
T_1 F_23 ( struct V_1 * V_2 ,
T_4 V_193 , T_4 * V_194 ,
struct V_195 * V_196 )
{
struct V_131 V_128 ;
struct V_197 * V_172 =
(struct V_197 * ) & V_128 . V_141 . V_162 ;
T_1 V_3 ;
if ( ! V_194 )
return V_66 ;
F_13 ( & V_128 ,
V_198 ) ;
V_172 -> V_199 = F_14 ( V_193 ) ;
V_3 = F_15 ( V_2 , & V_128 , NULL , 0 , V_196 ) ;
if ( V_3 == 0 )
* V_194 = F_8 ( V_172 -> V_200 ) ;
return V_3 ;
}
T_4 F_24 ( struct V_1 * V_2 , T_4 V_193 )
{
T_1 V_3 = 0 ;
bool V_201 ;
int V_202 = 5 ;
T_4 V_203 = 0 ;
V_201 = ( ( ( V_2 -> V_156 . V_204 == 1 ) &&
( V_2 -> V_156 . V_205 < 5 ) ) ||
( V_2 -> V_20 . type == V_26 ) ) ;
if ( ! V_201 ) {
V_206:
V_3 = F_23 ( V_2 , V_193 ,
& V_203 , NULL ) ;
if ( V_2 -> V_156 . V_207 == V_45 && V_202 ) {
F_25 ( 1000 , 2000 ) ;
V_202 -- ;
goto V_206;
}
}
if ( V_3 || V_201 )
V_203 = F_11 ( V_2 , V_193 ) ;
return V_203 ;
}
T_1 F_26 ( struct V_1 * V_2 ,
T_4 V_193 , T_4 V_194 ,
struct V_195 * V_196 )
{
struct V_131 V_128 ;
struct V_197 * V_161 =
(struct V_197 * ) & V_128 . V_141 . V_162 ;
T_1 V_3 ;
F_13 ( & V_128 ,
V_208 ) ;
V_161 -> V_199 = F_14 ( V_193 ) ;
V_161 -> V_200 = F_14 ( V_194 ) ;
V_3 = F_15 ( V_2 , & V_128 , NULL , 0 , V_196 ) ;
return V_3 ;
}
void F_27 ( struct V_1 * V_2 , T_4 V_193 , T_4 V_194 )
{
T_1 V_3 = 0 ;
bool V_201 ;
int V_202 = 5 ;
V_201 = ( ( ( V_2 -> V_156 . V_204 == 1 ) &&
( V_2 -> V_156 . V_205 < 5 ) ) ||
( V_2 -> V_20 . type == V_26 ) ) ;
if ( ! V_201 ) {
V_206:
V_3 = F_26 ( V_2 , V_193 ,
V_194 , NULL ) ;
if ( V_2 -> V_156 . V_207 == V_45 && V_202 ) {
F_25 ( 1000 , 2000 ) ;
V_202 -- ;
goto V_206;
}
}
if ( V_3 || V_201 )
F_28 ( V_2 , V_193 , V_194 ) ;
}
T_1 F_29 ( struct V_1 * V_2 ,
enum V_209 V_210 ,
T_1 V_211 ,
T_3 * V_212 , T_2 V_213 ,
struct V_195 * V_196 )
{
struct V_131 V_128 ;
struct V_195 V_214 ;
T_1 V_3 ;
F_13 ( & V_128 , V_215 ) ;
V_128 . V_136 |= F_17 ( ( T_2 ) V_216 ) ;
V_128 . V_139 = F_14 ( V_210 ) ;
V_128 . V_140 = F_14 ( V_211 ) ;
if ( V_213 ) {
V_128 . V_136 |= F_17 ( ( T_2 ) ( V_175
| V_176 ) ) ;
if ( V_213 > V_217 )
V_128 . V_136 |= F_17 ( ( T_2 ) V_218 ) ;
V_128 . V_137 = F_17 ( V_213 ) ;
}
if ( ! V_196 ) {
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . V_219 = true ;
V_196 = & V_214 ;
}
V_3 = F_15 ( V_2 , & V_128 , V_212 , V_213 , V_196 ) ;
return V_3 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_220 * V_212 )
{
struct V_221 * V_222 ;
int V_223 ;
V_222 = & V_212 -> V_222 [ 0 ] ;
V_2 -> V_224 . V_225 = V_212 -> V_225 ;
V_2 -> V_224 . V_226 = V_212 -> V_227 ;
V_2 -> V_224 . V_228 = V_212 -> V_227 ;
V_2 -> V_224 . V_229 = V_212 -> V_230 ;
V_2 -> V_224 . V_231 = V_212 -> V_232 &
V_233 ;
V_2 -> V_224 . V_234 = 0 ;
for ( V_223 = 0 ; V_223 < V_212 -> V_225 ; V_223 ++ ) {
if ( V_222 -> V_235 == V_236 ) {
F_31 ( V_2 -> V_20 . V_237 ,
V_222 -> V_238 ) ;
F_31 ( V_2 -> V_20 . V_239 ,
V_222 -> V_238 ) ;
}
V_222 ++ ;
}
}
T_1 F_32 ( struct V_1 * V_2 )
{
return F_29 ( V_2 , V_240 ,
0 , NULL , 0 , NULL ) ;
}
enum
V_241 F_33 ( struct V_1 * V_2 , void * V_242 ,
T_2 V_243 , T_4 V_244 ,
T_4 * V_245 , T_4 * V_246 ,
struct V_195 * V_196 )
{
struct V_131 V_128 ;
struct V_247 * V_161 =
(struct V_247 * )
& V_128 . V_141 . V_162 ;
struct V_248 * V_249 ;
T_1 V_3 ;
F_13 ( & V_128 ,
V_250 ) ;
V_128 . V_136 |= F_17 ( V_175 | V_176 ) ;
if ( V_243 > V_217 )
V_128 . V_136 |= F_17 ( ( T_2 ) V_218 ) ;
V_128 . V_137 = F_17 ( V_243 ) ;
V_161 -> V_251 = F_14 ( V_244 ) ;
V_3 = F_15 ( V_2 , & V_128 , V_242 , V_243 , V_196 ) ;
if ( ! V_3 ) {
V_249 = (struct V_248 * ) & V_128 . V_141 . V_162 ;
if ( V_245 )
* V_245 = F_8 ( V_249 -> V_245 ) ;
if ( V_246 )
* V_246 = F_8 ( V_249 -> V_246 ) ;
}
return V_3 ;
}
enum
V_241 F_34 ( struct V_1 * V_2 , void * V_242 ,
T_2 V_243 , T_3 V_136 ,
struct V_195 * V_196 )
{
struct V_131 V_128 ;
struct V_252 * V_161 =
(struct V_252 * ) & V_128 . V_141 . V_162 ;
T_1 V_3 ;
F_13 ( & V_128 ,
V_253 ) ;
V_128 . V_136 |= F_17 ( ( T_2 ) V_175 ) ;
if ( V_243 > V_217 )
V_128 . V_136 |= F_17 ( ( T_2 ) V_218 ) ;
V_128 . V_137 = F_17 ( V_243 ) ;
V_161 -> V_136 = V_136 ;
V_3 = F_15 ( V_2 , & V_128 , V_242 , V_243 , V_196 ) ;
return V_3 ;
}
struct V_254 *
F_35 ( T_4 V_255 ,
struct V_256 * V_257 )
{
struct V_254 * V_258 ;
T_4 V_223 ;
for ( V_223 = 0 ; V_223 < V_257 -> V_259 ; V_223 ++ ) {
V_258 =
(struct V_254 * ) ( ( T_3 * ) V_257 +
V_257 -> V_260 [ V_223 ] ) ;
if ( V_258 -> type == V_255 )
return V_258 ;
}
return NULL ;
}
enum V_241
F_36 ( struct V_1 * V_2 , struct V_261 * V_262 ,
T_4 V_244 )
{
T_1 V_3 = 0 ;
struct V_263 * V_264 ;
struct V_265 * V_266 = NULL ;
T_4 V_267 ;
T_4 V_268 ;
T_4 * V_269 ;
T_4 V_270 = 0 ;
T_4 V_271 = 0 , V_272 = 0 ;
T_4 V_223 ;
if ( ! V_244 ) {
F_6 ( V_2 , V_273 , L_97 ) ;
return V_124 ;
}
V_267 = V_262 -> V_274 ;
for ( V_223 = 0 ; V_223 < V_267 ; V_223 ++ ) {
V_268 = V_262 -> V_275 [ V_223 ] . V_268 ;
if ( ( V_268 >> 16 ) == V_5 )
if ( V_2 -> V_6 == ( V_268 & 0xFFFF ) )
break;
}
if ( V_223 == V_267 ) {
F_6 ( V_2 , V_273 , L_98 ) ;
return V_34 ;
}
V_269 = ( T_4 * ) & V_262 -> V_275 [ V_267 ] ;
V_264 = (struct V_263 * ) & V_269 [ V_269 [ 0 ] + 1 ] ;
for ( V_223 = 0 ; V_223 < V_264 -> V_276 ; V_223 ++ ) {
V_266 = (struct V_265 * ) ( ( T_3 * ) V_262 +
V_264 -> V_277 [ V_223 ] ) ;
if ( V_266 -> V_278 . type != V_279 )
continue;
V_270 = V_266 -> V_278 . V_280 +
sizeof( struct V_265 ) ;
V_3 = F_33 ( V_2 , ( void * ) V_266 , ( T_2 ) V_270 ,
V_244 , & V_271 , & V_272 , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , V_273 ,
L_99 ,
V_271 , V_272 ) ;
break;
}
}
return V_3 ;
}
enum V_241
F_37 ( struct V_1 * V_2 ,
struct V_261 * V_262 ,
T_3 * V_281 , T_4 V_244 )
{
T_1 V_3 = 0 ;
struct V_265 * V_266 = NULL ;
struct V_282 * V_283 ;
T_4 V_271 = 0 , V_272 = 0 ;
V_266 = (struct V_265 * ) V_281 ;
V_266 -> V_284 = 1 ;
V_266 -> V_285 = sizeof( struct V_265 ) +
sizeof( struct V_282 ) ;
V_266 -> V_278 . type = V_286 ;
V_266 -> V_278 . V_271 = sizeof( struct V_265 ) ;
V_266 -> V_278 . V_280 = sizeof( struct V_282 ) ;
V_283 = (struct V_282 * ) ( V_281 +
V_266 -> V_278 . V_271 ) ;
V_283 -> V_244 = V_244 ;
V_283 -> V_287 = V_262 -> V_287 ;
V_283 -> V_288 = V_289 ;
memcpy ( V_283 -> V_290 , V_262 -> V_290 , V_291 ) ;
V_3 = F_33 ( V_2 , ( void * ) V_266 , V_266 -> V_285 ,
V_244 , & V_271 , & V_272 , NULL ) ;
return V_3 ;
}
