static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * * V_6 )
{
struct V_7 * * V_8 = V_2 -> V_8 ;
int V_9 ;
if ( ! V_8 [ V_10 ] )
return - V_11 ;
V_9 = F_2 ( V_8 [ V_10 ] ) ;
* V_6 = F_3 ( F_4 ( V_2 ) , V_9 ) ;
if ( ! * V_6 )
return - V_12 ;
* V_4 = F_5 ( F_4 ( V_2 ) , V_9 ) ;
if ( F_6 ( * V_4 ) ) {
F_7 ( * V_6 ) ;
return F_8 ( * V_4 ) ;
}
return 0 ;
}
static int F_9 ( struct V_13 * V_14 )
{
int V_15 ;
V_15 = F_10 ( V_14 -> V_16 , V_17 + V_18 . V_19 ,
V_18 . V_20 , V_18 . V_21 ,
V_22 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_18 . V_20 [ V_10 ] )
return - V_11 ;
V_15 = F_2 ( V_18 . V_20 [ V_10 ] ) ;
if ( ! V_15 )
return - V_11 ;
return V_15 ;
}
static int F_11 ( struct V_23 * V_24 ,
struct V_13 * V_14 ,
struct V_3 * * V_4 ,
struct V_5 * * V_6 )
{
int V_25 = V_14 -> args [ 0 ] ;
int V_26 ;
if ( ! V_25 )
V_25 = F_9 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
V_14 -> args [ 0 ] = V_25 ;
F_12 () ;
* V_6 = F_13 ( F_14 ( V_24 -> V_27 ) , V_25 ) ;
if ( ! * V_6 ) {
V_26 = - V_12 ;
goto V_28;
}
* V_4 = F_5 ( F_14 ( V_24 -> V_27 ) , V_25 ) ;
if ( F_6 ( * V_4 ) ) {
V_26 = F_8 ( * V_4 ) ;
goto V_28;
}
return 0 ;
V_28:
F_15 () ;
return V_26 ;
}
static void F_16 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
F_15 () ;
}
static bool F_18 ( const struct V_7 * V_29 )
{
const T_1 * V_30 ;
int V_31 ;
if ( ! V_29 )
return true ;
V_30 = F_19 ( V_29 ) ;
V_31 = F_20 ( V_29 ) ;
while ( V_31 ) {
T_1 V_32 ;
if ( V_31 < 2 )
return false ;
V_31 -= 2 ;
V_32 = V_30 [ 1 ] ;
if ( V_32 > V_31 )
return false ;
V_31 -= V_32 ;
V_30 += 2 + V_32 ;
}
return true ;
}
static inline void * F_21 ( struct V_23 * V_24 , T_2 V_33 , T_2 V_34 ,
int V_35 , T_1 V_36 )
{
return F_22 ( V_24 , V_33 , V_34 , & V_18 , V_35 , V_36 ) ;
}
static int F_23 ( struct V_23 * V_37 ,
struct V_38 * V_39 )
{
F_24 ( V_37 , V_40 ,
V_39 -> V_41 ) ;
if ( V_39 -> V_35 & V_42 )
F_25 ( V_37 , V_43 ) ;
if ( V_39 -> V_35 & V_44 )
F_25 ( V_37 , V_45 ) ;
if ( V_39 -> V_35 & V_46 )
F_25 ( V_37 , V_47 ) ;
if ( V_39 -> V_35 & V_48 )
F_25 ( V_37 , V_49 ) ;
F_24 ( V_37 , V_50 ,
F_26 ( V_39 -> V_51 ) ) ;
return 0 ;
V_52:
return - V_53 ;
}
static int F_27 ( struct V_7 * V_54 , struct V_55 * V_56 )
{
struct V_7 * V_57 [ V_58 + 1 ] ;
int V_26 = F_28 ( V_57 , V_58 , V_54 ,
V_59 ) ;
if ( V_26 )
return V_26 ;
V_56 -> V_60 = ! ! V_57 [ V_61 ] ;
V_56 -> V_62 = ! ! V_57 [ V_63 ] ;
if ( V_56 -> V_60 ) {
V_56 -> V_64 = true ;
V_56 -> V_65 = true ;
}
if ( V_56 -> V_62 )
V_56 -> V_65 = true ;
if ( V_57 [ V_66 ] )
V_56 -> V_67 = F_29 ( V_57 [ V_66 ] ) ;
if ( V_57 [ V_68 ] ) {
V_56 -> V_69 . V_54 = F_19 ( V_57 [ V_68 ] ) ;
V_56 -> V_69 . V_70 = F_20 ( V_57 [ V_68 ] ) ;
}
if ( V_57 [ V_71 ] ) {
V_56 -> V_69 . V_34 = F_19 ( V_57 [ V_71 ] ) ;
V_56 -> V_69 . V_72 = F_20 ( V_57 [ V_71 ] ) ;
}
if ( V_57 [ V_73 ] )
V_56 -> V_69 . V_74 = F_2 ( V_57 [ V_73 ] ) ;
if ( V_57 [ V_75 ] ) {
V_56 -> type = F_2 ( V_57 [ V_75 ] ) ;
if ( V_56 -> type < 0 || V_56 -> type >= V_76 )
return - V_11 ;
}
if ( V_57 [ V_77 ] ) {
struct V_7 * V_78 [ V_79 ] ;
int V_26 = F_28 ( V_78 ,
V_79 - 1 ,
V_57 [ V_77 ] ,
V_80 ) ;
if ( V_26 )
return V_26 ;
V_56 -> V_64 = V_78 [ V_81 ] ;
V_56 -> V_65 = V_78 [ V_82 ] ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
if ( V_2 -> V_8 [ V_83 ] ) {
V_56 -> V_69 . V_54 = F_19 ( V_2 -> V_8 [ V_83 ] ) ;
V_56 -> V_69 . V_70 = F_20 ( V_2 -> V_8 [ V_83 ] ) ;
}
if ( V_2 -> V_8 [ V_84 ] ) {
V_56 -> V_69 . V_34 = F_19 ( V_2 -> V_8 [ V_84 ] ) ;
V_56 -> V_69 . V_72 = F_20 ( V_2 -> V_8 [ V_84 ] ) ;
}
if ( V_2 -> V_8 [ V_85 ] )
V_56 -> V_67 = F_29 ( V_2 -> V_8 [ V_85 ] ) ;
if ( V_2 -> V_8 [ V_86 ] )
V_56 -> V_69 . V_74 = F_2 ( V_2 -> V_8 [ V_86 ] ) ;
V_56 -> V_60 = ! ! V_2 -> V_8 [ V_87 ] ;
V_56 -> V_62 = ! ! V_2 -> V_8 [ V_88 ] ;
if ( V_56 -> V_60 ) {
V_56 -> V_64 = true ;
V_56 -> V_65 = true ;
}
if ( V_56 -> V_62 )
V_56 -> V_65 = true ;
if ( V_2 -> V_8 [ V_89 ] ) {
V_56 -> type = F_2 ( V_2 -> V_8 [ V_89 ] ) ;
if ( V_56 -> type < 0 || V_56 -> type >= V_76 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_90 ] ) {
struct V_7 * V_78 [ V_79 ] ;
int V_26 = F_28 (
V_78 , V_79 - 1 ,
V_2 -> V_8 [ V_90 ] ,
V_80 ) ;
if ( V_26 )
return V_26 ;
V_56 -> V_64 = V_78 [ V_81 ] ;
V_56 -> V_65 = V_78 [ V_82 ] ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
int V_26 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> V_67 = - 1 ;
V_56 -> type = - 1 ;
if ( V_2 -> V_8 [ V_91 ] )
V_26 = F_27 ( V_2 -> V_8 [ V_91 ] , V_56 ) ;
else
V_26 = F_30 ( V_2 , V_56 ) ;
if ( V_26 )
return V_26 ;
if ( V_56 -> V_60 && V_56 -> V_62 )
return - V_11 ;
if ( V_56 -> V_62 ) {
if ( V_56 -> V_64 || ! V_56 -> V_65 )
return - V_11 ;
}
if ( V_56 -> V_67 != - 1 ) {
if ( V_56 -> V_62 ) {
if ( V_56 -> V_67 < 4 || V_56 -> V_67 > 5 )
return - V_11 ;
} else if ( V_56 -> V_60 ) {
if ( V_56 -> V_67 < 0 || V_56 -> V_67 > 3 )
return - V_11 ;
} else {
if ( V_56 -> V_67 < 0 || V_56 -> V_67 > 5 )
return - V_11 ;
}
}
return 0 ;
}
static struct V_92 *
F_32 ( struct V_3 * V_4 ,
struct V_7 * V_93 )
{
struct V_55 V_94 ;
struct V_7 * V_54 ;
struct V_92 * V_95 ;
int V_96 , V_26 , V_60 = 0 ;
V_95 = F_33 ( sizeof( * V_95 ) , V_97 ) ;
if ( ! V_95 )
return F_34 ( - V_98 ) ;
V_95 -> V_60 = - 1 ;
V_95 -> V_62 = - 1 ;
F_35 (key, keys, rem) {
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_67 = - 1 ;
V_26 = F_27 ( V_54 , & V_94 ) ;
if ( V_26 )
goto error;
V_26 = - V_11 ;
if ( ! V_94 . V_69 . V_54 )
goto error;
if ( V_94 . V_67 < 0 || V_94 . V_67 > 4 )
goto error;
if ( V_94 . V_60 ) {
if ( V_60 )
goto error;
V_60 = 1 ;
V_95 -> V_60 = V_94 . V_67 ;
if ( ! V_94 . V_64 || ! V_94 . V_65 )
goto error;
} else if ( V_94 . V_62 )
goto error;
V_26 = F_36 ( V_4 , & V_94 . V_69 ,
V_94 . V_67 , false , NULL ) ;
if ( V_26 )
goto error;
V_95 -> V_99 [ V_94 . V_67 ] . V_74 = V_94 . V_69 . V_74 ;
V_95 -> V_99 [ V_94 . V_67 ] . V_70 = V_94 . V_69 . V_70 ;
V_95 -> V_99 [ V_94 . V_67 ] . V_54 = V_95 -> V_100 [ V_94 . V_67 ] ;
memcpy ( V_95 -> V_100 [ V_94 . V_67 ] , V_94 . V_69 . V_54 , V_94 . V_69 . V_70 ) ;
}
return V_95 ;
error:
F_37 ( V_95 ) ;
return F_34 ( V_26 ) ;
}
static int F_38 ( struct V_101 * V_102 )
{
F_39 ( V_102 ) ;
switch ( V_102 -> V_103 ) {
case V_104 :
case V_105 :
case V_106 :
case V_107 :
break;
case V_108 :
if ( ! V_102 -> V_109 )
return - V_110 ;
break;
case V_111 :
case V_112 :
if ( V_102 -> V_113 != V_114 )
return - V_110 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_40 ( struct V_23 * V_37 , T_2 V_29 , T_3 V_115 )
{
struct V_7 * V_116 = F_41 ( V_37 , V_29 ) ;
int V_117 ;
if ( ! V_116 )
goto V_52;
V_117 = 0 ;
while ( V_115 ) {
if ( V_115 & 1 )
F_25 ( V_37 , V_117 ) ;
V_115 >>= 1 ;
V_117 ++ ;
}
F_42 ( V_37 , V_116 ) ;
return 0 ;
V_52:
return - V_53 ;
}
static int F_43 ( struct V_118 * V_118 ,
struct V_23 * V_37 )
{
struct V_7 * V_119 ;
int V_117 , V_120 ;
V_119 = F_41 ( V_37 ,
V_121 ) ;
if ( ! V_119 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_118 -> V_122 ; V_117 ++ ) {
const struct V_123 * V_124 ;
struct V_7 * V_125 , * V_126 ;
V_124 = & V_118 -> V_127 [ V_117 ] ;
V_125 = F_41 ( V_37 , V_117 + 1 ) ;
if ( ! V_125 )
goto V_52;
V_126 = F_41 ( V_37 , V_128 ) ;
if ( ! V_126 )
goto V_52;
for ( V_120 = 0 ; V_120 < V_124 -> V_129 ; V_120 ++ ) {
struct V_7 * V_130 ;
V_130 = F_41 ( V_37 , V_120 + 1 ) ;
if ( ! V_130 )
goto V_52;
F_24 ( V_37 , V_131 ,
V_124 -> V_132 [ V_120 ] . V_133 ) ;
if ( F_40 ( V_37 , V_134 ,
V_124 -> V_132 [ V_120 ] . V_135 ) )
goto V_52;
F_42 ( V_37 , V_130 ) ;
}
F_42 ( V_37 , V_126 ) ;
if ( V_124 -> V_136 )
F_25 ( V_37 ,
V_137 ) ;
F_24 ( V_37 , V_138 ,
V_124 -> V_139 ) ;
F_24 ( V_37 , V_140 ,
V_124 -> V_141 ) ;
F_42 ( V_37 , V_125 ) ;
}
F_42 ( V_37 , V_119 ) ;
return 0 ;
V_52:
return - V_53 ;
}
static int F_44 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 , int V_35 ,
struct V_3 * V_6 )
{
void * V_142 ;
struct V_7 * V_143 , * V_144 ;
struct V_7 * V_145 , * V_146 ;
struct V_7 * V_147 , * V_148 ;
struct V_7 * V_149 ;
enum V_150 V_151 ;
struct V_38 * V_39 ;
struct V_152 * V_153 ;
int V_117 ;
const struct V_154 * V_155 =
V_6 -> V_118 . V_155 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_156 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_157 , V_6 -> V_158 ) ;
F_45 ( V_37 , V_159 , F_46 ( & V_6 -> V_118 ) ) ;
F_24 ( V_37 , V_160 ,
V_161 ) ;
F_47 ( V_37 , V_162 ,
V_6 -> V_118 . V_163 ) ;
F_47 ( V_37 , V_164 ,
V_6 -> V_118 . V_165 ) ;
F_24 ( V_37 , V_166 ,
V_6 -> V_118 . V_167 ) ;
F_24 ( V_37 , V_168 ,
V_6 -> V_118 . V_169 ) ;
F_47 ( V_37 , V_170 ,
V_6 -> V_118 . V_171 ) ;
F_47 ( V_37 , V_172 ,
V_6 -> V_118 . V_173 ) ;
F_47 ( V_37 , V_174 ,
V_6 -> V_118 . V_175 ) ;
F_48 ( V_37 , V_176 ,
V_6 -> V_118 . V_177 ) ;
F_48 ( V_37 , V_178 ,
V_6 -> V_118 . V_179 ) ;
F_47 ( V_37 , V_180 ,
V_6 -> V_118 . V_181 ) ;
if ( V_6 -> V_118 . V_35 & V_182 )
F_25 ( V_37 , V_183 ) ;
if ( V_6 -> V_118 . V_35 & V_184 )
F_25 ( V_37 , V_185 ) ;
if ( V_6 -> V_118 . V_35 & V_186 )
F_25 ( V_37 , V_187 ) ;
if ( V_6 -> V_118 . V_35 & V_188 )
F_25 ( V_37 , V_189 ) ;
if ( V_6 -> V_118 . V_35 & V_190 )
F_25 ( V_37 , V_191 ) ;
if ( V_6 -> V_118 . V_35 & V_192 )
F_25 ( V_37 , V_193 ) ;
F_49 ( V_37 , V_194 ,
sizeof( T_2 ) * V_6 -> V_118 . V_195 ,
V_6 -> V_118 . V_196 ) ;
F_47 ( V_37 , V_197 ,
V_6 -> V_118 . V_198 ) ;
if ( V_6 -> V_118 . V_35 & V_199 )
F_25 ( V_37 , V_200 ) ;
F_24 ( V_37 , V_201 ,
V_6 -> V_118 . V_202 ) ;
F_24 ( V_37 , V_203 ,
V_6 -> V_118 . V_204 ) ;
if ( ( V_6 -> V_118 . V_202 ||
V_6 -> V_118 . V_204 ) && V_6 -> V_205 -> V_206 ) {
T_2 V_207 = 0 , V_208 = 0 ;
int V_15 ;
V_15 = V_6 -> V_205 -> V_206 ( & V_6 -> V_118 , & V_207 , & V_208 ) ;
if ( ! V_15 ) {
F_24 ( V_37 , V_209 , V_207 ) ;
F_24 ( V_37 , V_210 , V_208 ) ;
}
}
if ( F_40 ( V_37 , V_211 ,
V_6 -> V_118 . V_212 ) )
goto V_52;
V_143 = F_41 ( V_37 , V_213 ) ;
if ( ! V_143 )
goto V_52;
for ( V_151 = 0 ; V_151 < V_214 ; V_151 ++ ) {
if ( ! V_6 -> V_118 . V_215 [ V_151 ] )
continue;
V_144 = F_41 ( V_37 , V_151 ) ;
if ( ! V_144 )
goto V_52;
if ( V_6 -> V_118 . V_215 [ V_151 ] -> V_216 . V_217 ) {
F_49 ( V_37 , V_218 ,
sizeof( V_6 -> V_118 . V_215 [ V_151 ] -> V_216 . V_219 ) ,
& V_6 -> V_118 . V_215 [ V_151 ] -> V_216 . V_219 ) ;
F_48 ( V_37 , V_220 ,
V_6 -> V_118 . V_215 [ V_151 ] -> V_216 . V_221 ) ;
F_47 ( V_37 , V_222 ,
V_6 -> V_118 . V_215 [ V_151 ] -> V_216 . V_223 ) ;
F_47 ( V_37 , V_224 ,
V_6 -> V_118 . V_215 [ V_151 ] -> V_216 . V_225 ) ;
}
V_145 = F_41 ( V_37 , V_226 ) ;
if ( ! V_145 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_6 -> V_118 . V_215 [ V_151 ] -> V_227 ; V_117 ++ ) {
V_146 = F_41 ( V_37 , V_117 ) ;
if ( ! V_146 )
goto V_52;
V_39 = & V_6 -> V_118 . V_215 [ V_151 ] -> V_228 [ V_117 ] ;
if ( F_23 ( V_37 , V_39 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
}
F_42 ( V_37 , V_145 ) ;
V_147 = F_41 ( V_37 , V_229 ) ;
if ( ! V_147 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_6 -> V_118 . V_215 [ V_151 ] -> V_230 ; V_117 ++ ) {
V_148 = F_41 ( V_37 , V_117 ) ;
if ( ! V_148 )
goto V_52;
V_153 = & V_6 -> V_118 . V_215 [ V_151 ] -> V_231 [ V_117 ] ;
F_24 ( V_37 , V_232 ,
V_153 -> V_233 ) ;
if ( V_153 -> V_35 & V_234 )
F_25 ( V_37 ,
V_235 ) ;
F_42 ( V_37 , V_148 ) ;
}
F_42 ( V_37 , V_147 ) ;
F_42 ( V_37 , V_144 ) ;
}
F_42 ( V_37 , V_143 ) ;
V_149 = F_41 ( V_37 , V_236 ) ;
if ( ! V_149 )
goto V_52;
V_117 = 0 ;
#define F_50 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
NLA_PUT_U32(msg, i, NL80211_CMD_ ## n); \
} \
} while (0)
F_50 ( V_237 , V_238 ) ;
F_50 ( V_239 , V_240 ) ;
F_50 ( V_241 , V_242 ) ;
F_50 ( V_243 , V_244 ) ;
F_50 ( V_245 , V_246 ) ;
F_50 ( V_247 , V_248 ) ;
F_50 ( V_249 , V_250 ) ;
F_50 ( V_251 , V_252 ) ;
F_50 ( V_253 , V_254 ) ;
F_50 ( V_255 , V_256 ) ;
F_50 ( V_257 , V_258 ) ;
F_50 ( V_259 , V_260 ) ;
F_50 ( V_261 , V_262 ) ;
F_50 ( V_263 , V_264 ) ;
F_50 ( V_265 , V_266 ) ;
F_50 ( V_267 , V_268 ) ;
F_50 ( V_269 , V_270 ) ;
F_50 ( V_271 , V_272 ) ;
F_50 ( V_273 , V_274 ) ;
F_50 ( V_275 , V_276 ) ;
F_50 ( V_277 , V_278 ) ;
if ( V_6 -> V_118 . V_35 & V_279 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_280 ) ;
}
F_50 ( V_281 , V_282 ) ;
F_50 ( V_283 , V_284 ) ;
if ( V_6 -> V_118 . V_35 & V_190 ) {
F_50 ( V_285 , V_286 ) ;
F_50 ( V_287 , V_288 ) ;
}
if ( V_6 -> V_118 . V_35 & V_289 )
F_50 ( V_290 , V_291 ) ;
#undef F_50
if ( V_6 -> V_205 -> V_292 || V_6 -> V_205 -> V_253 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_293 ) ;
}
if ( V_6 -> V_205 -> V_294 || V_6 -> V_205 -> V_257 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_295 ) ;
}
F_42 ( V_37 , V_149 ) ;
if ( V_6 -> V_205 -> V_271 )
F_24 ( V_37 , V_296 ,
V_6 -> V_118 . V_297 ) ;
if ( V_6 -> V_205 -> V_277 )
F_25 ( V_37 , V_298 ) ;
if ( V_155 ) {
T_3 V_299 ;
struct V_7 * V_300 , * V_301 ;
enum V_302 V_303 ;
V_301 = F_41 ( V_37 , V_304 ) ;
if ( ! V_301 )
goto V_52;
for ( V_303 = 0 ; V_303 < V_305 ; V_303 ++ ) {
V_300 = F_41 ( V_37 , V_303 ) ;
if ( ! V_300 )
goto V_52;
V_117 = 0 ;
V_299 = V_155 [ V_303 ] . V_306 ;
while ( V_299 ) {
if ( V_299 & 1 )
F_48 ( V_37 , V_307 ,
( V_117 << 4 ) | V_308 ) ;
V_299 >>= 1 ;
V_117 ++ ;
}
F_42 ( V_37 , V_300 ) ;
}
F_42 ( V_37 , V_301 ) ;
V_301 = F_41 ( V_37 , V_309 ) ;
if ( ! V_301 )
goto V_52;
for ( V_303 = 0 ; V_303 < V_305 ; V_303 ++ ) {
V_300 = F_41 ( V_37 , V_303 ) ;
if ( ! V_300 )
goto V_52;
V_117 = 0 ;
V_299 = V_155 [ V_303 ] . V_310 ;
while ( V_299 ) {
if ( V_299 & 1 )
F_48 ( V_37 , V_307 ,
( V_117 << 4 ) | V_308 ) ;
V_299 >>= 1 ;
V_117 ++ ;
}
F_42 ( V_37 , V_300 ) ;
}
F_42 ( V_37 , V_301 ) ;
}
if ( V_6 -> V_118 . V_311 . V_35 || V_6 -> V_118 . V_311 . V_312 ) {
struct V_7 * V_313 ;
V_313 = F_41 ( V_37 ,
V_314 ) ;
if ( ! V_313 )
goto V_52;
if ( V_6 -> V_118 . V_311 . V_35 & V_315 )
F_25 ( V_37 , V_316 ) ;
if ( V_6 -> V_118 . V_311 . V_35 & V_317 )
F_25 ( V_37 , V_318 ) ;
if ( V_6 -> V_118 . V_311 . V_35 & V_319 )
F_25 ( V_37 , V_320 ) ;
if ( V_6 -> V_118 . V_311 . V_35 & V_321 )
F_25 ( V_37 , V_322 ) ;
if ( V_6 -> V_118 . V_311 . V_35 & V_323 )
F_25 ( V_37 , V_324 ) ;
if ( V_6 -> V_118 . V_311 . V_35 & V_325 )
F_25 ( V_37 , V_326 ) ;
if ( V_6 -> V_118 . V_311 . V_35 & V_327 )
F_25 ( V_37 , V_328 ) ;
if ( V_6 -> V_118 . V_311 . V_35 & V_329 )
F_25 ( V_37 , V_330 ) ;
if ( V_6 -> V_118 . V_311 . V_312 ) {
struct V_331 V_332 = {
. V_333 = V_6 -> V_118 . V_311 . V_312 ,
. V_334 =
V_6 -> V_118 . V_311 . V_335 ,
. V_336 =
V_6 -> V_118 . V_311 . V_337 ,
} ;
F_49 ( V_37 , V_338 ,
sizeof( V_332 ) , & V_332 ) ;
}
F_42 ( V_37 , V_313 ) ;
}
if ( F_40 ( V_37 , V_339 ,
V_6 -> V_118 . V_340 ) )
goto V_52;
if ( F_43 ( & V_6 -> V_118 , V_37 ) )
goto V_52;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
static int F_53 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_67 = 0 ;
int V_342 = V_14 -> args [ 0 ] ;
struct V_3 * V_6 ;
F_54 ( & V_343 ) ;
F_55 (dev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_6 -> V_118 ) , F_14 ( V_24 -> V_27 ) ) )
continue;
if ( ++ V_67 <= V_342 )
continue;
if ( F_44 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_344 , V_345 ,
V_6 ) < 0 ) {
V_67 -- ;
break;
}
}
F_59 ( & V_343 ) ;
V_14 -> args [ 0 ] = V_67 ;
return V_24 -> V_31 ;
}
static int F_60 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
struct V_3 * V_6 = V_2 -> V_346 [ 0 ] ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_44 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 , V_6 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_64 ( struct V_7 * V_57 [] ,
struct V_350 * V_351 )
{
if ( ! V_57 [ V_352 ] || ! V_57 [ V_353 ] ||
! V_57 [ V_354 ] || ! V_57 [ V_355 ] ||
! V_57 [ V_356 ] )
return - V_11 ;
V_351 -> V_357 = F_29 ( V_57 [ V_352 ] ) ;
V_351 -> V_358 = F_65 ( V_57 [ V_353 ] ) ;
V_351 -> V_359 = F_65 ( V_57 [ V_354 ] ) ;
V_351 -> V_360 = F_65 ( V_57 [ V_355 ] ) ;
V_351 -> V_361 = F_29 ( V_57 [ V_356 ] ) ;
return 0 ;
}
static bool F_66 ( struct V_101 * V_102 )
{
return ! V_102 ||
V_102 -> V_103 == V_104 ||
V_102 -> V_103 == V_362 ||
V_102 -> V_103 == V_107 ||
V_102 -> V_103 == V_363 ||
V_102 -> V_103 == V_106 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_1 * V_2 )
{
enum V_364 V_365 = V_366 ;
T_2 V_367 ;
int V_95 ;
if ( ! V_2 -> V_8 [ V_368 ] )
return - V_11 ;
if ( ! F_66 ( V_102 ) )
return - V_369 ;
if ( V_2 -> V_8 [ V_370 ] ) {
V_365 = F_2 ( V_2 -> V_8 [
V_370 ] ) ;
if ( V_365 != V_366 &&
V_365 != V_371 &&
V_365 != V_372 &&
V_365 != V_373 )
return - V_11 ;
}
V_367 = F_2 ( V_2 -> V_8 [ V_368 ] ) ;
F_54 ( & V_4 -> V_374 ) ;
if ( V_102 ) {
F_68 ( V_102 ) ;
V_95 = F_69 ( V_4 , V_102 , V_367 , V_365 ) ;
F_70 ( V_102 ) ;
} else {
V_95 = F_69 ( V_4 , NULL , V_367 , V_365 ) ;
}
F_59 ( & V_4 -> V_374 ) ;
return V_95 ;
}
static int F_71 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_375 = V_2 -> V_346 [ 1 ] ;
return F_67 ( V_4 , V_375 -> V_376 , V_2 ) ;
}
static int F_72 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_376 ;
const T_1 * V_377 ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( F_73 ( V_6 ) )
return - V_379 ;
if ( ! V_4 -> V_205 -> V_283 )
return - V_369 ;
if ( V_102 -> V_103 != V_362 )
return - V_369 ;
V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
return V_4 -> V_205 -> V_283 ( V_102 -> V_118 , V_6 , V_377 ) ;
}
static int F_74 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_375 = NULL ;
struct V_101 * V_102 ;
int V_95 = 0 , V_380 = 0 ;
struct V_7 * V_381 ;
T_2 V_382 ;
T_1 V_163 = 0 , V_165 = 0 ;
T_2 V_167 = 0 , V_169 = 0 ;
T_1 V_171 = 0 ;
F_54 ( & V_343 ) ;
if ( V_2 -> V_8 [ V_10 ] ) {
int V_9 = F_2 ( V_2 -> V_8 [ V_10 ] ) ;
V_375 = F_3 ( F_4 ( V_2 ) , V_9 ) ;
if ( V_375 && V_375 -> V_376 ) {
V_4 = F_75 ( V_375 -> V_376 -> V_118 ) ;
F_54 ( & V_4 -> V_383 ) ;
} else
V_375 = NULL ;
}
if ( ! V_375 ) {
V_4 = F_76 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_59 ( & V_343 ) ;
return F_8 ( V_4 ) ;
}
V_102 = NULL ;
V_375 = NULL ;
V_95 = 0 ;
F_54 ( & V_4 -> V_383 ) ;
} else if ( F_73 ( V_375 ) &&
F_66 ( V_375 -> V_376 ) )
V_102 = V_375 -> V_376 ;
else
V_102 = NULL ;
if ( V_2 -> V_8 [ V_159 ] )
V_95 = F_77 (
V_4 , F_19 ( V_2 -> V_8 [ V_159 ] ) ) ;
F_59 ( & V_343 ) ;
if ( V_95 )
goto V_384;
if ( V_2 -> V_8 [ V_385 ] ) {
struct V_350 V_351 ;
struct V_7 * V_57 [ V_386 + 1 ] ;
if ( ! V_4 -> V_205 -> V_387 ) {
V_95 = - V_369 ;
goto V_384;
}
if ( ! V_375 ) {
V_95 = - V_11 ;
goto V_384;
}
if ( V_375 -> V_376 -> V_103 != V_104 &&
V_375 -> V_376 -> V_103 != V_106 ) {
V_95 = - V_11 ;
goto V_384;
}
F_35 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_78 ( V_57 , V_386 ,
F_19 ( V_381 ) ,
F_20 ( V_381 ) ,
V_388 ) ;
V_95 = F_64 ( V_57 , & V_351 ) ;
if ( V_95 )
goto V_384;
V_95 = V_4 -> V_205 -> V_387 ( & V_4 -> V_118 ,
V_375 ,
& V_351 ) ;
if ( V_95 )
goto V_384;
}
}
if ( V_2 -> V_8 [ V_368 ] ) {
V_95 = F_67 ( V_4 , V_102 , V_2 ) ;
if ( V_95 )
goto V_384;
}
if ( V_2 -> V_8 [ V_389 ] ) {
enum V_390 type ;
int V_67 , V_391 = 0 ;
if ( ! V_4 -> V_205 -> V_392 ) {
V_95 = - V_369 ;
goto V_384;
}
V_67 = V_389 ;
type = F_2 ( V_2 -> V_8 [ V_67 ] ) ;
if ( ! V_2 -> V_8 [ V_393 ] &&
( type != V_394 ) ) {
V_95 = - V_11 ;
goto V_384;
}
if ( type != V_394 ) {
V_67 = V_393 ;
V_391 = F_2 ( V_2 -> V_8 [ V_67 ] ) ;
}
V_95 = V_4 -> V_205 -> V_392 ( & V_4 -> V_118 , type , V_391 ) ;
if ( V_95 )
goto V_384;
}
if ( V_2 -> V_8 [ V_209 ] &&
V_2 -> V_8 [ V_210 ] ) {
T_2 V_207 , V_208 ;
if ( ( ! V_4 -> V_118 . V_202 &&
! V_4 -> V_118 . V_204 ) ||
! V_4 -> V_205 -> V_395 ) {
V_95 = - V_369 ;
goto V_384;
}
V_207 = F_2 ( V_2 -> V_8 [ V_209 ] ) ;
V_208 = F_2 ( V_2 -> V_8 [ V_210 ] ) ;
if ( ( ~ V_207 && ( V_207 & ~ V_4 -> V_118 . V_202 ) ) ||
( ~ V_208 && ( V_208 & ~ V_4 -> V_118 . V_204 ) ) ) {
V_95 = - V_11 ;
goto V_384;
}
V_207 = V_207 & V_4 -> V_118 . V_202 ;
V_208 = V_208 & V_4 -> V_118 . V_204 ;
V_95 = V_4 -> V_205 -> V_395 ( & V_4 -> V_118 , V_207 , V_208 ) ;
if ( V_95 )
goto V_384;
}
V_382 = 0 ;
if ( V_2 -> V_8 [ V_162 ] ) {
V_163 = F_29 (
V_2 -> V_8 [ V_162 ] ) ;
if ( V_163 == 0 ) {
V_95 = - V_11 ;
goto V_384;
}
V_382 |= V_396 ;
}
if ( V_2 -> V_8 [ V_164 ] ) {
V_165 = F_29 (
V_2 -> V_8 [ V_164 ] ) ;
if ( V_165 == 0 ) {
V_95 = - V_11 ;
goto V_384;
}
V_382 |= V_397 ;
}
if ( V_2 -> V_8 [ V_166 ] ) {
V_167 = F_2 (
V_2 -> V_8 [ V_166 ] ) ;
if ( V_167 < 256 ) {
V_95 = - V_11 ;
goto V_384;
}
if ( V_167 != ( T_2 ) - 1 ) {
V_167 &= ~ 0x1 ;
}
V_382 |= V_398 ;
}
if ( V_2 -> V_8 [ V_168 ] ) {
V_169 = F_2 (
V_2 -> V_8 [ V_168 ] ) ;
V_382 |= V_399 ;
}
if ( V_2 -> V_8 [ V_170 ] ) {
V_171 = F_29 (
V_2 -> V_8 [ V_170 ] ) ;
V_382 |= V_400 ;
}
if ( V_382 ) {
T_1 V_401 , V_402 ;
T_2 V_403 , V_404 ;
T_1 V_405 ;
if ( ! V_4 -> V_205 -> V_406 ) {
V_95 = - V_369 ;
goto V_384;
}
V_401 = V_4 -> V_118 . V_163 ;
V_402 = V_4 -> V_118 . V_165 ;
V_403 = V_4 -> V_118 . V_167 ;
V_404 = V_4 -> V_118 . V_169 ;
V_405 = V_4 -> V_118 . V_171 ;
if ( V_382 & V_396 )
V_4 -> V_118 . V_163 = V_163 ;
if ( V_382 & V_397 )
V_4 -> V_118 . V_165 = V_165 ;
if ( V_382 & V_398 )
V_4 -> V_118 . V_167 = V_167 ;
if ( V_382 & V_399 )
V_4 -> V_118 . V_169 = V_169 ;
if ( V_382 & V_400 )
V_4 -> V_118 . V_171 = V_171 ;
V_95 = V_4 -> V_205 -> V_406 ( & V_4 -> V_118 , V_382 ) ;
if ( V_95 ) {
V_4 -> V_118 . V_163 = V_401 ;
V_4 -> V_118 . V_165 = V_402 ;
V_4 -> V_118 . V_167 = V_403 ;
V_4 -> V_118 . V_169 = V_404 ;
V_4 -> V_118 . V_171 = V_405 ;
}
}
V_384:
F_59 ( & V_4 -> V_383 ) ;
if ( V_375 )
F_7 ( V_375 ) ;
return V_95 ;
}
static int F_79 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 , int V_35 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_407 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_45 ( V_37 , V_408 , V_6 -> V_409 ) ;
F_24 ( V_37 , V_410 , V_6 -> V_376 -> V_103 ) ;
F_24 ( V_37 , V_160 ,
V_4 -> V_411 ^
( V_161 << 2 ) ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
static int F_80 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_412 = 0 ;
int V_413 = 0 ;
int V_414 = V_14 -> args [ 0 ] ;
int V_415 = V_14 -> args [ 1 ] ;
struct V_3 * V_4 ;
struct V_101 * V_102 ;
F_54 ( & V_343 ) ;
F_55 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_4 -> V_118 ) , F_14 ( V_24 -> V_27 ) ) )
continue;
if ( V_412 < V_414 ) {
V_412 ++ ;
continue;
}
V_413 = 0 ;
F_54 ( & V_4 -> V_374 ) ;
F_55 (wdev, &rdev->netdev_list, list) {
if ( V_413 < V_415 ) {
V_413 ++ ;
continue;
}
if ( F_79 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_344 , V_345 ,
V_4 , V_102 -> V_375 ) < 0 ) {
F_59 ( & V_4 -> V_374 ) ;
goto V_416;
}
V_413 ++ ;
}
F_59 ( & V_4 -> V_374 ) ;
V_412 ++ ;
}
V_416:
F_59 ( & V_343 ) ;
V_14 -> args [ 0 ] = V_412 ;
V_14 -> args [ 1 ] = V_413 ;
return V_24 -> V_31 ;
}
static int F_81 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
struct V_3 * V_6 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_375 = V_2 -> V_346 [ 1 ] ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_79 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_6 , V_375 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_82 ( struct V_7 * V_417 , T_2 * V_418 )
{
struct V_7 * V_35 [ V_419 + 1 ] ;
int V_420 ;
* V_418 = 0 ;
if ( ! V_417 )
return - V_11 ;
if ( F_28 ( V_35 , V_419 ,
V_417 , V_421 ) )
return - V_11 ;
for ( V_420 = 1 ; V_420 <= V_419 ; V_420 ++ )
if ( V_35 [ V_420 ] )
* V_418 |= ( 1 << V_420 ) ;
return 0 ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_5 * V_375 , T_1 V_422 ,
enum V_302 V_103 )
{
if ( ! V_422 ) {
if ( V_375 && ( V_375 -> V_423 & V_424 ) )
return - V_379 ;
return 0 ;
}
switch ( V_103 ) {
case V_105 :
if ( V_4 -> V_118 . V_35 & V_425 )
return 0 ;
break;
case V_111 :
if ( V_4 -> V_118 . V_35 & V_426 )
return 0 ;
break;
default:
break;
}
return - V_369 ;
}
static int F_84 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_427 V_99 ;
int V_26 ;
enum V_302 V_428 , V_429 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_2 V_430 , * V_35 = NULL ;
bool V_431 = false ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_428 = V_429 = V_6 -> V_376 -> V_103 ;
if ( V_2 -> V_8 [ V_410 ] ) {
V_429 = F_2 ( V_2 -> V_8 [ V_410 ] ) ;
if ( V_428 != V_429 )
V_431 = true ;
if ( V_429 > V_432 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_433 ] ) {
struct V_101 * V_102 = V_6 -> V_376 ;
if ( V_429 != V_107 )
return - V_11 ;
if ( F_73 ( V_6 ) )
return - V_379 ;
F_68 ( V_102 ) ;
F_85 ( V_434 !=
V_435 ) ;
V_102 -> V_436 =
F_20 ( V_2 -> V_8 [ V_433 ] ) ;
memcpy ( V_102 -> V_437 , F_19 ( V_2 -> V_8 [ V_433 ] ) ,
V_102 -> V_436 ) ;
F_70 ( V_102 ) ;
}
if ( V_2 -> V_8 [ V_438 ] ) {
V_99 . V_422 = ! ! F_29 ( V_2 -> V_8 [ V_438 ] ) ;
V_431 = true ;
V_26 = F_83 ( V_4 , V_6 , V_99 . V_422 , V_429 ) ;
if ( V_26 )
return V_26 ;
} else {
V_99 . V_422 = - 1 ;
}
if ( V_2 -> V_8 [ V_439 ] ) {
if ( V_429 != V_363 )
return - V_11 ;
V_26 = F_82 ( V_2 -> V_8 [ V_439 ] ,
& V_430 ) ;
if ( V_26 )
return V_26 ;
V_35 = & V_430 ;
V_431 = true ;
}
if ( V_431 )
V_26 = F_86 ( V_4 , V_6 , V_429 , V_35 , & V_99 ) ;
else
V_26 = 0 ;
if ( ! V_26 && V_99 . V_422 != - 1 )
V_6 -> V_376 -> V_422 = V_99 . V_422 ;
return V_26 ;
}
static int F_87 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_427 V_99 ;
struct V_5 * V_6 ;
int V_26 ;
enum V_302 type = V_440 ;
T_2 V_35 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( ! V_2 -> V_8 [ V_408 ] )
return - V_11 ;
if ( V_2 -> V_8 [ V_410 ] ) {
type = F_2 ( V_2 -> V_8 [ V_410 ] ) ;
if ( type > V_432 )
return - V_11 ;
}
if ( ! V_4 -> V_205 -> V_237 ||
! ( V_4 -> V_118 . V_212 & ( 1 << type ) ) )
return - V_369 ;
if ( V_2 -> V_8 [ V_438 ] ) {
V_99 . V_422 = ! ! F_29 ( V_2 -> V_8 [ V_438 ] ) ;
V_26 = F_83 ( V_4 , NULL , V_99 . V_422 , type ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_82 ( type == V_363 ?
V_2 -> V_8 [ V_439 ] : NULL ,
& V_35 ) ;
V_6 = V_4 -> V_205 -> V_237 ( & V_4 -> V_118 ,
F_19 ( V_2 -> V_8 [ V_408 ] ) ,
type , V_26 ? NULL : & V_35 , & V_99 ) ;
if ( F_6 ( V_6 ) )
return F_8 ( V_6 ) ;
if ( type == V_107 &&
V_2 -> V_8 [ V_433 ] ) {
struct V_101 * V_102 = V_6 -> V_376 ;
F_68 ( V_102 ) ;
F_85 ( V_434 !=
V_435 ) ;
V_102 -> V_436 =
F_20 ( V_2 -> V_8 [ V_433 ] ) ;
memcpy ( V_102 -> V_437 , F_19 ( V_2 -> V_8 [ V_433 ] ) ,
V_102 -> V_436 ) ;
F_70 ( V_102 ) ;
}
return 0 ;
}
static int F_88 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
if ( ! V_4 -> V_205 -> V_441 )
return - V_369 ;
return V_4 -> V_205 -> V_441 ( & V_4 -> V_118 , V_6 ) ;
}
static void F_89 ( void * V_124 , struct V_442 * V_99 )
{
struct V_7 * V_54 ;
struct V_443 * V_444 = V_124 ;
if ( V_99 -> V_54 )
F_49 ( V_444 -> V_37 , V_83 ,
V_99 -> V_70 , V_99 -> V_54 ) ;
if ( V_99 -> V_34 )
F_49 ( V_444 -> V_37 , V_84 ,
V_99 -> V_72 , V_99 -> V_34 ) ;
if ( V_99 -> V_74 )
F_24 ( V_444 -> V_37 , V_86 ,
V_99 -> V_74 ) ;
V_54 = F_41 ( V_444 -> V_37 , V_91 ) ;
if ( ! V_54 )
goto V_52;
if ( V_99 -> V_54 )
F_49 ( V_444 -> V_37 , V_68 ,
V_99 -> V_70 , V_99 -> V_54 ) ;
if ( V_99 -> V_34 )
F_49 ( V_444 -> V_37 , V_71 ,
V_99 -> V_72 , V_99 -> V_34 ) ;
if ( V_99 -> V_74 )
F_24 ( V_444 -> V_37 , V_73 ,
V_99 -> V_74 ) ;
F_47 ( V_444 -> V_37 , V_85 , V_444 -> V_67 ) ;
F_42 ( V_444 -> V_37 , V_54 ) ;
return;
V_52:
V_444 -> error = 1 ;
}
static int F_90 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 V_445 = 0 ;
const T_1 * V_446 = NULL ;
bool V_447 ;
struct V_443 V_444 = {
. error = 0 ,
} ;
void * V_142 ;
struct V_23 * V_37 ;
if ( V_2 -> V_8 [ V_85 ] )
V_445 = F_29 ( V_2 -> V_8 [ V_85 ] ) ;
if ( V_445 > 5 )
return - V_11 ;
if ( V_2 -> V_8 [ V_378 ] )
V_446 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_447 = ! ! V_446 ;
if ( V_2 -> V_8 [ V_89 ] ) {
T_2 V_448 = F_2 ( V_2 -> V_8 [ V_89 ] ) ;
if ( V_448 >= V_76 )
return - V_11 ;
if ( V_448 != V_449 &&
V_448 != V_450 )
return - V_11 ;
V_447 = V_448 == V_450 ;
}
if ( ! V_4 -> V_205 -> V_451 )
return - V_369 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_452 ) ;
if ( F_6 ( V_142 ) )
return F_8 ( V_142 ) ;
V_444 . V_37 = V_37 ;
V_444 . V_67 = V_445 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_47 ( V_37 , V_85 , V_445 ) ;
if ( V_446 )
F_49 ( V_37 , V_378 , V_453 , V_446 ) ;
if ( V_447 && V_446 &&
! ( V_4 -> V_118 . V_35 & V_182 ) )
return - V_454 ;
V_26 = V_4 -> V_205 -> V_451 ( & V_4 -> V_118 , V_6 , V_445 , V_447 ,
V_446 , & V_444 , F_89 ) ;
if ( V_26 )
goto V_455;
if ( V_444 . error )
goto V_52;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_455:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_55 V_54 ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 < 0 )
return - V_11 ;
if ( ! V_54 . V_60 && ! V_54 . V_62 )
return - V_11 ;
F_68 ( V_6 -> V_376 ) ;
if ( V_54 . V_60 ) {
if ( ! V_4 -> V_205 -> V_456 ) {
V_26 = - V_369 ;
goto V_416;
}
V_26 = F_38 ( V_6 -> V_376 ) ;
if ( V_26 )
goto V_416;
V_26 = V_4 -> V_205 -> V_456 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . V_64 , V_54 . V_65 ) ;
if ( V_26 )
goto V_416;
#ifdef F_92
V_6 -> V_376 -> V_457 . V_458 = V_54 . V_67 ;
#endif
} else {
if ( V_54 . V_64 || ! V_54 . V_65 ) {
V_26 = - V_11 ;
goto V_416;
}
if ( ! V_4 -> V_205 -> V_459 ) {
V_26 = - V_369 ;
goto V_416;
}
V_26 = F_38 ( V_6 -> V_376 ) ;
if ( V_26 )
goto V_416;
V_26 = V_4 -> V_205 -> V_459 ( & V_4 -> V_118 ,
V_6 , V_54 . V_67 ) ;
if ( V_26 )
goto V_416;
#ifdef F_92
V_6 -> V_376 -> V_457 . V_460 = V_54 . V_67 ;
#endif
}
V_416:
F_70 ( V_6 -> V_376 ) ;
return V_26 ;
}
static int F_93 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_55 V_54 ;
const T_1 * V_446 = NULL ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_54 . V_69 . V_54 )
return - V_11 ;
if ( V_2 -> V_8 [ V_378 ] )
V_446 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_446 )
V_54 . type = V_450 ;
else
V_54 . type = V_449 ;
}
if ( V_54 . type != V_450 &&
V_54 . type != V_449 )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_241 )
return - V_369 ;
if ( F_36 ( V_4 , & V_54 . V_69 , V_54 . V_67 ,
V_54 . type == V_450 ,
V_446 ) )
return - V_11 ;
F_68 ( V_6 -> V_376 ) ;
V_26 = F_38 ( V_6 -> V_376 ) ;
if ( ! V_26 )
V_26 = V_4 -> V_205 -> V_241 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . type == V_450 ,
V_446 , & V_54 . V_69 ) ;
F_70 ( V_6 -> V_376 ) ;
return V_26 ;
}
static int F_94 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 * V_446 = NULL ;
struct V_55 V_54 ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_2 -> V_8 [ V_378 ] )
V_446 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_446 )
V_54 . type = V_450 ;
else
V_54 . type = V_449 ;
}
if ( V_54 . type != V_450 &&
V_54 . type != V_449 )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_461 )
return - V_369 ;
F_68 ( V_6 -> V_376 ) ;
V_26 = F_38 ( V_6 -> V_376 ) ;
if ( V_54 . type == V_450 && V_446 &&
! ( V_4 -> V_118 . V_35 & V_182 ) )
V_26 = - V_454 ;
if ( ! V_26 )
V_26 = V_4 -> V_205 -> V_461 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . type == V_450 ,
V_446 ) ;
#ifdef F_92
if ( ! V_26 ) {
if ( V_54 . V_67 == V_6 -> V_376 -> V_457 . V_458 )
V_6 -> V_376 -> V_457 . V_458 = - 1 ;
else if ( V_54 . V_67 == V_6 -> V_376 -> V_457 . V_460 )
V_6 -> V_376 -> V_457 . V_460 = - 1 ;
}
#endif
F_70 ( V_6 -> V_376 ) ;
return V_26 ;
}
static int F_95 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
int (* F_96)( struct V_118 * V_118 , struct V_5 * V_6 ,
struct V_462 * V_2 );
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_376 ;
struct V_462 V_99 ;
int V_463 = 0 , V_26 ;
if ( ! F_18 ( V_2 -> V_8 [ V_464 ] ) ||
! F_18 ( V_2 -> V_8 [ V_465 ] ) ||
! F_18 ( V_2 -> V_8 [ V_466 ] ) ||
! F_18 ( V_2 -> V_8 [ V_467 ] ) )
return - V_11 ;
if ( V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_106 )
return - V_369 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
switch ( V_2 -> V_468 -> V_36 ) {
case V_469 :
if ( ! V_2 -> V_8 [ V_470 ] ||
! V_2 -> V_8 [ V_471 ] ||
! V_2 -> V_8 [ V_472 ] )
return - V_11 ;
V_99 . V_473 =
F_2 ( V_2 -> V_8 [ V_470 ] ) ;
V_99 . V_474 =
F_2 ( V_2 -> V_8 [ V_471 ] ) ;
V_26 = F_97 ( V_4 , V_99 . V_473 ) ;
if ( V_26 )
return V_26 ;
if ( V_2 -> V_8 [ V_475 ] ) {
V_99 . V_437 = F_19 ( V_2 -> V_8 [ V_475 ] ) ;
V_99 . V_476 =
F_20 ( V_2 -> V_8 [ V_475 ] ) ;
if ( V_99 . V_476 == 0 ||
V_99 . V_476 > V_434 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_477 ] ) {
V_99 . V_478 = F_2 (
V_2 -> V_8 [ V_477 ] ) ;
if ( V_99 . V_478 !=
V_479 &&
V_99 . V_478 !=
V_480 &&
V_99 . V_478 !=
V_481 )
return - V_11 ;
}
V_99 . V_482 = ! ! V_2 -> V_8 [ V_483 ] ;
if ( V_2 -> V_8 [ V_484 ] ) {
V_99 . V_485 = F_2 (
V_2 -> V_8 [ V_484 ] ) ;
if ( ! F_98 ( V_99 . V_485 ) )
return - V_11 ;
} else
V_99 . V_485 = V_486 ;
V_26 = F_99 ( V_4 , V_2 , & V_99 . V_487 ,
V_488 ) ;
if ( V_26 )
return V_26 ;
F_96 = V_4 -> V_205 -> V_243 ;
break;
case V_489 :
F_96 = V_4 -> V_205 -> V_490 ;
break;
default:
F_100 ( 1 ) ;
return - V_369 ;
}
if ( ! F_96 )
return - V_369 ;
if ( V_2 -> V_8 [ V_472 ] ) {
V_99 . V_491 = F_19 ( V_2 -> V_8 [ V_472 ] ) ;
V_99 . V_492 =
F_20 ( V_2 -> V_8 [ V_472 ] ) ;
V_463 = 1 ;
}
if ( V_2 -> V_8 [ V_464 ] ) {
V_99 . V_493 = F_19 ( V_2 -> V_8 [ V_464 ] ) ;
V_99 . V_494 =
F_20 ( V_2 -> V_8 [ V_464 ] ) ;
V_463 = 1 ;
}
if ( ! V_463 )
return - V_11 ;
if ( V_2 -> V_8 [ V_465 ] ) {
V_99 . V_495 = F_19 ( V_2 -> V_8 [ V_465 ] ) ;
V_99 . V_496 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
}
if ( V_2 -> V_8 [ V_466 ] ) {
V_99 . V_497 =
F_19 ( V_2 -> V_8 [ V_466 ] ) ;
V_99 . V_498 =
F_20 ( V_2 -> V_8 [ V_466 ] ) ;
}
if ( V_2 -> V_8 [ V_467 ] ) {
V_99 . V_499 =
F_19 ( V_2 -> V_8 [ V_467 ] ) ;
V_99 . V_500 =
F_20 ( V_2 -> V_8 [ V_467 ] ) ;
}
V_26 = F_96 ( & V_4 -> V_118 , V_6 , & V_99 ) ;
if ( ! V_26 && V_99 . V_473 )
V_102 -> V_501 = V_99 . V_473 ;
return V_26 ;
}
static int F_101 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_376 ;
int V_26 ;
if ( ! V_4 -> V_205 -> V_502 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_106 )
return - V_369 ;
V_26 = V_4 -> V_205 -> V_502 ( & V_4 -> V_118 , V_6 ) ;
if ( ! V_26 )
V_102 -> V_501 = 0 ;
return V_26 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_503 * V_99 )
{
struct V_7 * V_35 [ V_504 + 1 ] ;
struct V_7 * V_417 ;
int V_420 ;
V_417 = V_2 -> V_8 [ V_505 ] ;
if ( V_417 ) {
struct V_506 * V_507 ;
V_507 = F_19 ( V_417 ) ;
V_99 -> V_508 = V_507 -> V_509 ;
V_99 -> V_510 = V_507 -> V_511 ;
if ( ( V_99 -> V_508 |
V_99 -> V_510 ) & F_103 ( V_512 ) )
return - V_11 ;
return 0 ;
}
V_417 = V_2 -> V_8 [ V_513 ] ;
if ( ! V_417 )
return 0 ;
if ( F_28 ( V_35 , V_504 ,
V_417 , V_514 ) )
return - V_11 ;
V_99 -> V_508 = ( 1 << V_515 ) - 1 ;
V_99 -> V_508 &= ~ 1 ;
for ( V_420 = 1 ; V_420 <= V_504 ; V_420 ++ )
if ( V_35 [ V_420 ] )
V_99 -> V_510 |= ( 1 << V_420 ) ;
return 0 ;
}
static bool F_104 ( struct V_23 * V_37 , struct V_516 * V_2 ,
int V_29 )
{
struct V_7 * V_153 ;
T_3 V_233 ;
V_153 = F_41 ( V_37 , V_29 ) ;
if ( ! V_153 )
goto V_52;
V_233 = F_105 ( V_2 ) ;
if ( V_233 > 0 )
F_48 ( V_37 , V_517 , V_233 ) ;
if ( V_2 -> V_35 & V_518 )
F_47 ( V_37 , V_519 , V_2 -> V_219 ) ;
if ( V_2 -> V_35 & V_520 )
F_25 ( V_37 , V_521 ) ;
if ( V_2 -> V_35 & V_522 )
F_25 ( V_37 , V_523 ) ;
F_42 ( V_37 , V_153 ) ;
return true ;
V_52:
return false ;
}
static int F_106 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
const T_1 * V_446 , struct V_524 * V_525 )
{
void * V_142 ;
struct V_7 * V_526 , * V_527 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_528 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_446 ) ;
F_24 ( V_37 , V_160 , V_525 -> V_529 ) ;
V_526 = F_41 ( V_37 , V_530 ) ;
if ( ! V_526 )
goto V_52;
if ( V_525 -> V_531 & V_532 )
F_24 ( V_37 , V_533 ,
V_525 -> V_534 ) ;
if ( V_525 -> V_531 & V_535 )
F_24 ( V_37 , V_536 ,
V_525 -> V_537 ) ;
if ( V_525 -> V_531 & V_538 )
F_24 ( V_37 , V_539 ,
V_525 -> V_540 ) ;
if ( V_525 -> V_531 & V_541 )
F_24 ( V_37 , V_542 ,
V_525 -> V_543 ) ;
if ( V_525 -> V_531 & V_544 )
F_48 ( V_37 , V_545 ,
V_525 -> V_546 ) ;
if ( V_525 -> V_531 & V_547 )
F_48 ( V_37 , V_548 ,
V_525 -> V_549 ) ;
if ( V_525 -> V_531 & V_550 )
F_47 ( V_37 , V_551 ,
V_525 -> V_552 ) ;
if ( V_525 -> V_531 & V_553 )
F_47 ( V_37 , V_554 ,
V_525 -> signal ) ;
if ( V_525 -> V_531 & V_555 )
F_47 ( V_37 , V_556 ,
V_525 -> V_557 ) ;
if ( V_525 -> V_531 & V_558 ) {
if ( ! F_104 ( V_37 , & V_525 -> V_559 ,
V_560 ) )
goto V_52;
}
if ( V_525 -> V_531 & V_561 ) {
if ( ! F_104 ( V_37 , & V_525 -> V_562 ,
V_563 ) )
goto V_52;
}
if ( V_525 -> V_531 & V_564 )
F_24 ( V_37 , V_565 ,
V_525 -> V_566 ) ;
if ( V_525 -> V_531 & V_567 )
F_24 ( V_37 , V_568 ,
V_525 -> V_569 ) ;
if ( V_525 -> V_531 & V_570 )
F_24 ( V_37 , V_571 ,
V_525 -> V_572 ) ;
if ( V_525 -> V_531 & V_573 )
F_24 ( V_37 , V_574 ,
V_525 -> V_575 ) ;
if ( V_525 -> V_531 & V_576 ) {
V_527 = F_41 ( V_37 , V_577 ) ;
if ( ! V_527 )
goto V_52;
if ( V_525 -> V_527 . V_35 & V_578 )
F_25 ( V_37 , V_579 ) ;
if ( V_525 -> V_527 . V_35 & V_580 )
F_25 ( V_37 , V_581 ) ;
if ( V_525 -> V_527 . V_35 & V_582 )
F_25 ( V_37 ,
V_583 ) ;
F_47 ( V_37 , V_584 ,
V_525 -> V_527 . V_474 ) ;
F_48 ( V_37 , V_585 ,
V_525 -> V_527 . V_501 ) ;
F_42 ( V_37 , V_527 ) ;
}
if ( V_525 -> V_531 & V_586 )
F_49 ( V_37 , V_587 ,
sizeof( struct V_506 ) ,
& V_525 -> V_507 ) ;
F_42 ( V_37 , V_526 ) ;
if ( V_525 -> V_531 & V_588 )
F_49 ( V_37 , V_465 , V_525 -> V_589 ,
V_525 -> V_590 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
static int F_107 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_524 V_525 ;
struct V_3 * V_6 ;
struct V_5 * V_375 ;
T_1 V_446 [ V_453 ] ;
int V_591 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_6 , & V_375 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_6 -> V_205 -> V_592 ) {
V_26 = - V_369 ;
goto V_593;
}
while ( 1 ) {
memset ( & V_525 , 0 , sizeof( V_525 ) ) ;
V_26 = V_6 -> V_205 -> V_592 ( & V_6 -> V_118 , V_375 , V_591 ,
V_446 , & V_525 ) ;
if ( V_26 == - V_454 )
break;
if ( V_26 )
goto V_593;
if ( F_106 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_344 , V_345 ,
V_375 , V_446 ,
& V_525 ) < 0 )
goto V_416;
V_591 ++ ;
}
V_416:
V_14 -> args [ 1 ] = V_591 ;
V_26 = V_24 -> V_31 ;
V_593:
F_16 ( V_6 ) ;
return V_26 ;
}
static int F_108 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_524 V_525 ;
struct V_23 * V_37 ;
T_1 * V_446 = NULL ;
int V_26 ;
memset ( & V_525 , 0 , sizeof( V_525 ) ) ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
V_446 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( ! V_4 -> V_205 -> V_594 )
return - V_369 ;
V_26 = V_4 -> V_205 -> V_594 ( & V_4 -> V_118 , V_6 , V_446 , & V_525 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_106 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_6 , V_446 , & V_525 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_595 )
{
struct V_7 * V_596 = V_2 -> V_8 [ V_597 ] ;
* V_595 = NULL ;
if ( V_596 ) {
* V_595 = F_3 ( F_4 ( V_2 ) ,
F_2 ( V_596 ) ) ;
if ( ! * V_595 )
return - V_12 ;
if ( ! ( * V_595 ) -> V_376 )
return - V_11 ;
if ( ( * V_595 ) -> V_376 -> V_118 != & V_4 -> V_118 )
return - V_11 ;
if ( ! F_73 ( * V_595 ) )
return - V_598 ;
}
return 0 ;
}
static int F_110 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_503 V_99 ;
T_1 * V_446 = NULL ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_599 = - 1 ;
V_99 . V_552 = - 1 ;
if ( V_2 -> V_8 [ V_600 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
V_446 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( V_2 -> V_8 [ V_601 ] ) {
V_99 . V_602 =
F_19 ( V_2 -> V_8 [ V_601 ] ) ;
V_99 . V_603 =
F_20 ( V_2 -> V_8 [ V_601 ] ) ;
}
if ( V_2 -> V_8 [ V_604 ] )
V_99 . V_599 =
F_65 ( V_2 -> V_8 [ V_604 ] ) ;
if ( V_2 -> V_8 [ V_605 ] )
V_99 . V_606 =
F_19 ( V_2 -> V_8 [ V_605 ] ) ;
if ( F_102 ( V_2 , & V_99 ) )
return - V_11 ;
if ( V_2 -> V_8 [ V_607 ] )
V_99 . V_608 =
F_29 ( V_2 -> V_8 [ V_607 ] ) ;
if ( V_2 -> V_8 [ V_609 ] )
V_99 . V_552 =
F_29 ( V_2 -> V_8 [ V_609 ] ) ;
V_26 = F_109 ( V_2 , V_4 , & V_99 . V_595 ) ;
if ( V_26 )
goto V_416;
V_26 = 0 ;
switch ( V_6 -> V_376 -> V_103 ) {
case V_104 :
case V_105 :
case V_106 :
if ( V_99 . V_608 )
V_26 = - V_11 ;
break;
case V_112 :
case V_111 :
if ( V_99 . V_608 )
V_26 = - V_11 ;
if ( V_99 . V_595 )
V_26 = - V_11 ;
if ( V_99 . V_602 &&
! ( V_99 . V_510 & F_103 ( V_610 ) ) )
V_26 = - V_11 ;
if ( V_99 . V_606 )
V_26 = - V_11 ;
if ( V_99 . V_599 >= 0 )
V_26 = - V_11 ;
if ( V_99 . V_508 &
~ ( F_103 ( V_611 ) |
F_103 ( V_610 ) ) )
V_26 = - V_11 ;
if ( ! ( V_99 . V_510 & F_103 ( V_610 ) ) &&
( V_99 . V_508 & F_103 ( V_610 ) ) )
V_26 = - V_11 ;
break;
case V_107 :
if ( V_99 . V_595 )
V_26 = - V_11 ;
if ( V_99 . V_606 )
V_26 = - V_11 ;
if ( V_99 . V_599 >= 0 )
V_26 = - V_11 ;
if ( V_99 . V_508 &
~ ( F_103 ( V_612 ) |
F_103 ( V_613 ) |
F_103 ( V_611 ) ) )
V_26 = - V_11 ;
break;
default:
V_26 = - V_11 ;
}
if ( V_26 )
goto V_416;
if ( ! V_4 -> V_205 -> V_614 ) {
V_26 = - V_369 ;
goto V_416;
}
V_26 = V_4 -> V_205 -> V_614 ( & V_4 -> V_118 , V_6 , V_446 , & V_99 ) ;
V_416:
if ( V_99 . V_595 )
F_7 ( V_99 . V_595 ) ;
return V_26 ;
}
static int F_111 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_503 V_99 ;
T_1 * V_446 = NULL ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_604 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_601 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_600 ] )
return - V_11 ;
V_446 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_99 . V_602 =
F_19 ( V_2 -> V_8 [ V_601 ] ) ;
V_99 . V_603 =
F_20 ( V_2 -> V_8 [ V_601 ] ) ;
V_99 . V_599 =
F_65 ( V_2 -> V_8 [ V_604 ] ) ;
V_99 . V_615 = F_65 ( V_2 -> V_8 [ V_600 ] ) ;
if ( ! V_99 . V_615 || V_99 . V_615 > V_616 )
return - V_11 ;
if ( V_2 -> V_8 [ V_605 ] )
V_99 . V_606 =
F_19 ( V_2 -> V_8 [ V_605 ] ) ;
if ( V_2 -> V_8 [ V_607 ] )
V_99 . V_608 =
F_29 ( V_2 -> V_8 [ V_607 ] ) ;
if ( F_102 ( V_2 , & V_99 ) )
return - V_11 ;
if ( ( V_4 -> V_118 . V_35 & V_186 ) &&
( V_99 . V_510 & F_103 ( V_617 ) ) &&
V_2 -> V_8 [ V_618 ] ) {
struct V_7 * V_57 [ V_619 + 1 ] ;
struct V_7 * V_417 ;
V_417 = V_2 -> V_8 [ V_618 ] ;
V_26 = F_28 ( V_57 , V_619 , V_417 ,
V_620 ) ;
if ( V_26 )
return V_26 ;
if ( V_57 [ V_621 ] )
V_99 . V_622 =
F_29 ( V_57 [ V_621 ] ) ;
if ( V_99 . V_622 & ~ V_623 )
return - V_11 ;
if ( V_57 [ V_624 ] )
V_99 . V_625 =
F_29 ( V_57 [ V_624 ] ) ;
if ( V_99 . V_625 & ~ V_626 )
return - V_11 ;
V_99 . V_627 |= V_628 ;
}
if ( V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_105 &&
V_6 -> V_376 -> V_103 != V_107 &&
V_6 -> V_376 -> V_103 != V_106 &&
V_6 -> V_376 -> V_103 != V_111 )
return - V_11 ;
if ( V_6 -> V_376 -> V_103 == V_111 &&
! ( ( V_99 . V_510 & F_103 ( V_610 ) ) &&
( V_4 -> V_118 . V_35 & V_190 ) &&
( V_4 -> V_118 . V_35 & V_192 ) ) )
return - V_11 ;
V_26 = F_109 ( V_2 , V_4 , & V_99 . V_595 ) ;
if ( V_26 )
goto V_416;
V_26 = 0 ;
if ( ! V_4 -> V_205 -> V_245 ) {
V_26 = - V_369 ;
goto V_416;
}
V_26 = V_4 -> V_205 -> V_245 ( & V_4 -> V_118 , V_6 , V_446 , & V_99 ) ;
V_416:
if ( V_99 . V_595 )
F_7 ( V_99 . V_595 ) ;
return V_26 ;
}
static int F_112 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 * V_446 = NULL ;
if ( V_2 -> V_8 [ V_378 ] )
V_446 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_105 &&
V_6 -> V_376 -> V_103 != V_107 &&
V_6 -> V_376 -> V_103 != V_106 )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_629 )
return - V_369 ;
return V_4 -> V_205 -> V_629 ( & V_4 -> V_118 , V_6 , V_446 ) ;
}
static int F_113 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
T_1 * V_630 , T_1 * V_631 ,
struct V_632 * V_633 )
{
void * V_142 ;
struct V_7 * V_634 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_528 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_630 ) ;
F_49 ( V_37 , V_635 , V_453 , V_631 ) ;
F_24 ( V_37 , V_160 , V_633 -> V_529 ) ;
V_634 = F_41 ( V_37 , V_636 ) ;
if ( ! V_634 )
goto V_52;
if ( V_633 -> V_531 & V_637 )
F_24 ( V_37 , V_638 ,
V_633 -> V_639 ) ;
if ( V_633 -> V_531 & V_640 )
F_24 ( V_37 , V_641 ,
V_633 -> V_642 ) ;
if ( V_633 -> V_531 & V_643 )
F_24 ( V_37 , V_644 ,
V_633 -> V_645 ) ;
if ( V_633 -> V_531 & V_646 )
F_24 ( V_37 , V_647 ,
V_633 -> V_648 ) ;
if ( V_633 -> V_531 & V_649 )
F_47 ( V_37 , V_650 ,
V_633 -> V_35 ) ;
if ( V_633 -> V_531 & V_651 )
F_24 ( V_37 , V_652 ,
V_633 -> V_653 ) ;
if ( V_633 -> V_531 & V_654 )
F_47 ( V_37 , V_655 ,
V_633 -> V_656 ) ;
F_42 ( V_37 , V_634 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
static int F_114 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_632 V_633 ;
struct V_3 * V_6 ;
struct V_5 * V_375 ;
T_1 V_630 [ V_453 ] ;
T_1 V_631 [ V_453 ] ;
int V_657 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_6 , & V_375 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_6 -> V_205 -> V_658 ) {
V_26 = - V_369 ;
goto V_593;
}
if ( V_375 -> V_376 -> V_103 != V_107 ) {
V_26 = - V_369 ;
goto V_593;
}
while ( 1 ) {
V_26 = V_6 -> V_205 -> V_658 ( & V_6 -> V_118 , V_375 , V_657 ,
V_630 , V_631 , & V_633 ) ;
if ( V_26 == - V_454 )
break;
if ( V_26 )
goto V_593;
if ( F_113 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_344 , V_345 ,
V_375 , V_630 , V_631 ,
& V_633 ) < 0 )
goto V_416;
V_657 ++ ;
}
V_416:
V_14 -> args [ 1 ] = V_657 ;
V_26 = V_24 -> V_31 ;
V_593:
F_16 ( V_6 ) ;
return V_26 ;
}
static int F_115 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_632 V_633 ;
struct V_23 * V_37 ;
T_1 * V_630 = NULL ;
T_1 V_631 [ V_453 ] ;
memset ( & V_633 , 0 , sizeof( V_633 ) ) ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
V_630 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( ! V_4 -> V_205 -> V_659 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_107 )
return - V_369 ;
V_26 = V_4 -> V_205 -> V_659 ( & V_4 -> V_118 , V_6 , V_630 , V_631 , & V_633 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_113 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_6 , V_630 , V_631 , & V_633 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_116 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 * V_630 = NULL ;
T_1 * V_631 = NULL ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_635 ] )
return - V_11 ;
V_630 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_631 = F_19 ( V_2 -> V_8 [ V_635 ] ) ;
if ( ! V_4 -> V_205 -> V_660 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_107 )
return - V_369 ;
return V_4 -> V_205 -> V_660 ( & V_4 -> V_118 , V_6 , V_630 , V_631 ) ;
}
static int F_117 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 * V_630 = NULL ;
T_1 * V_631 = NULL ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_635 ] )
return - V_11 ;
V_630 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_631 = F_19 ( V_2 -> V_8 [ V_635 ] ) ;
if ( ! V_4 -> V_205 -> V_247 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_107 )
return - V_369 ;
return V_4 -> V_205 -> V_247 ( & V_4 -> V_118 , V_6 , V_630 , V_631 ) ;
}
static int F_118 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 * V_630 = NULL ;
if ( V_2 -> V_8 [ V_378 ] )
V_630 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( ! V_4 -> V_205 -> V_661 )
return - V_369 ;
return V_4 -> V_205 -> V_661 ( & V_4 -> V_118 , V_6 , V_630 ) ;
}
static int F_119 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_662 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_663 = - 1 ;
V_99 . V_664 = - 1 ;
V_99 . V_665 = - 1 ;
V_99 . V_666 = - 1 ;
V_99 . V_667 = - 1 ;
if ( V_2 -> V_8 [ V_668 ] )
V_99 . V_663 =
F_29 ( V_2 -> V_8 [ V_668 ] ) ;
if ( V_2 -> V_8 [ V_669 ] )
V_99 . V_664 =
F_29 ( V_2 -> V_8 [ V_669 ] ) ;
if ( V_2 -> V_8 [ V_670 ] )
V_99 . V_665 =
F_29 ( V_2 -> V_8 [ V_670 ] ) ;
if ( V_2 -> V_8 [ V_671 ] ) {
V_99 . V_672 =
F_19 ( V_2 -> V_8 [ V_671 ] ) ;
V_99 . V_673 =
F_20 ( V_2 -> V_8 [ V_671 ] ) ;
}
if ( V_2 -> V_8 [ V_674 ] )
V_99 . V_666 = ! ! F_29 ( V_2 -> V_8 [ V_674 ] ) ;
if ( V_2 -> V_8 [ V_675 ] )
V_99 . V_667 =
F_65 ( V_2 -> V_8 [ V_675 ] ) ;
if ( ! V_4 -> V_205 -> V_251 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_106 )
return - V_369 ;
return V_4 -> V_205 -> V_251 ( & V_4 -> V_118 , V_6 , & V_99 ) ;
}
static int F_120 ( struct V_7 * V_57 [] ,
struct V_676 * V_677 )
{
struct V_678 * V_679 = & V_677 -> V_679 ;
struct V_680 * V_681 = & V_677 -> V_681 ;
if ( ! V_57 [ V_682 ] )
return - V_11 ;
if ( ! V_57 [ V_683 ] )
return - V_11 ;
if ( ! V_57 [ V_684 ] )
return - V_11 ;
if ( ! V_57 [ V_685 ] )
return - V_11 ;
if ( ! V_57 [ V_686 ] )
return - V_11 ;
V_677 -> V_35 = F_2 ( V_57 [ V_682 ] ) ;
V_679 -> V_687 =
F_2 ( V_57 [ V_683 ] ) ;
V_679 -> V_688 =
F_2 ( V_57 [ V_684 ] ) ;
V_679 -> V_689 =
F_2 ( V_57 [ V_685 ] ) ;
V_681 -> V_690 =
F_2 ( V_57 [ V_686 ] ) ;
if ( V_57 [ V_691 ] )
V_681 -> V_692 =
F_2 ( V_57 [ V_691 ] ) ;
return 0 ;
}
static int F_121 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
int V_693 ;
char * V_100 = NULL ;
F_54 ( & V_343 ) ;
if ( F_122 ( ! V_694 ) ) {
F_59 ( & V_343 ) ;
return - V_695 ;
}
F_59 ( & V_343 ) ;
if ( ! V_2 -> V_8 [ V_696 ] )
return - V_11 ;
V_100 = F_19 ( V_2 -> V_8 [ V_696 ] ) ;
V_693 = F_123 ( V_100 ) ;
return V_693 ;
}
static int F_124 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_376 ;
struct V_697 V_698 ;
int V_26 = 0 ;
void * V_142 ;
struct V_7 * V_634 ;
struct V_23 * V_37 ;
if ( V_102 -> V_103 != V_107 )
return - V_369 ;
if ( ! V_4 -> V_205 -> V_699 )
return - V_369 ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_700 )
memcpy ( & V_698 , & V_701 , sizeof( V_698 ) ) ;
else
V_26 = V_4 -> V_205 -> V_699 ( & V_4 -> V_118 , V_6 ,
& V_698 ) ;
F_70 ( V_102 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_702 ) ;
if ( ! V_142 )
goto V_416;
V_634 = F_41 ( V_37 , V_703 ) ;
if ( ! V_634 )
goto V_52;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_48 ( V_37 , V_704 ,
V_698 . V_705 ) ;
F_48 ( V_37 , V_706 ,
V_698 . V_707 ) ;
F_48 ( V_37 , V_708 ,
V_698 . V_709 ) ;
F_48 ( V_37 , V_710 ,
V_698 . V_711 ) ;
F_47 ( V_37 , V_712 ,
V_698 . V_713 ) ;
F_47 ( V_37 , V_714 ,
V_698 . V_715 ) ;
F_47 ( V_37 , V_716 ,
V_698 . V_717 ) ;
F_47 ( V_37 , V_718 ,
V_698 . V_719 ) ;
F_47 ( V_37 , V_720 ,
V_698 . V_721 ) ;
F_24 ( V_37 , V_722 ,
V_698 . V_723 ) ;
F_48 ( V_37 , V_724 ,
V_698 . V_725 ) ;
F_24 ( V_37 , V_726 ,
V_698 . V_727 ) ;
F_48 ( V_37 , V_728 ,
V_698 . V_729 ) ;
F_48 ( V_37 , V_730 ,
V_698 . V_731 ) ;
F_47 ( V_37 , V_732 ,
V_698 . V_733 ) ;
F_48 ( V_37 , V_734 ,
V_698 . V_735 ) ;
F_47 ( V_37 , V_736 ,
V_698 . V_737 ) ;
F_42 ( V_37 , V_634 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
V_416:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_697 * V_738 ,
T_2 * V_739 )
{
struct V_7 * V_57 [ V_740 + 1 ] ;
T_2 V_509 = 0 ;
#define F_126 ( T_6 , V_738 , T_7 , V_509 , T_8 , T_9 ) \
do {\
if (table[attr_num]) {\
cfg->param = nla_fn(table[attr_num]); \
mask |= (1 << (attr_num - 1)); \
} \
} while (0);\
if (!info->attrs[NL80211_ATTR_MESH_CONFIG])
return - V_11 ;
if ( F_28 ( V_57 , V_740 ,
V_2 -> V_8 [ V_703 ] ,
V_741 ) )
return - V_11 ;
F_85 ( V_740 > 32 ) ;
F_126 ( V_57 , V_738 , V_705 ,
V_509 , V_704 , F_65 ) ;
F_126 ( V_57 , V_738 , V_707 ,
V_509 , V_706 , F_65 ) ;
F_126 ( V_57 , V_738 , V_709 ,
V_509 , V_708 , F_65 ) ;
F_126 ( V_57 , V_738 , V_711 ,
V_509 , V_710 , F_65 ) ;
F_126 ( V_57 , V_738 , V_713 ,
V_509 , V_712 , F_29 ) ;
F_126 ( V_57 , V_738 , V_715 ,
V_509 , V_714 , F_29 ) ;
F_126 ( V_57 , V_738 , V_717 ,
V_509 , V_716 , F_29 ) ;
F_126 ( V_57 , V_738 , V_719 ,
V_509 , V_718 , F_29 ) ;
F_126 ( V_57 , V_738 , V_721 ,
V_509 , V_720 ,
F_29 ) ;
F_126 ( V_57 , V_738 , V_723 ,
V_509 , V_722 , F_2 ) ;
F_126 ( V_57 , V_738 , V_725 ,
V_509 , V_724 ,
F_65 ) ;
F_126 ( V_57 , V_738 , V_727 ,
V_509 , V_726 ,
F_2 ) ;
F_126 ( V_57 , V_738 , V_729 ,
V_509 , V_728 ,
F_65 ) ;
F_126 ( V_57 , V_738 ,
V_731 ,
V_509 , V_730 ,
F_65 ) ;
F_126 ( V_57 , V_738 ,
V_733 , V_509 ,
V_732 ,
F_29 ) ;
F_126 ( V_57 , V_738 ,
V_735 , V_509 ,
V_734 ,
F_65 ) ;
F_126 ( V_57 , V_738 ,
V_737 , V_509 ,
V_736 ,
F_29 ) ;
if ( V_739 )
* V_739 = V_509 ;
return 0 ;
#undef F_126
}
static int F_127 ( struct V_1 * V_2 ,
struct V_742 * V_743 )
{
struct V_7 * V_57 [ V_744 + 1 ] ;
if ( ! V_2 -> V_8 [ V_745 ] )
return - V_11 ;
if ( F_28 ( V_57 , V_744 ,
V_2 -> V_8 [ V_745 ] ,
V_746 ) )
return - V_11 ;
if ( V_57 [ V_747 ] )
V_743 -> V_748 =
( F_29 ( V_57 [ V_747 ] ) ) ?
V_749 :
V_750 ;
if ( V_57 [ V_751 ] )
V_743 -> V_752 =
( F_29 ( V_57 [ V_751 ] ) ) ?
V_753 :
V_754 ;
if ( V_57 [ V_755 ] ) {
struct V_7 * V_756 =
V_57 [ V_755 ] ;
if ( ! F_18 ( V_756 ) )
return - V_11 ;
V_743 -> V_757 = F_19 ( V_756 ) ;
V_743 -> V_758 = F_20 ( V_756 ) ;
}
V_743 -> V_759 = F_128 ( V_57 [ V_760 ] ) ;
V_743 -> V_761 = F_128 ( V_57 [ V_762 ] ) ;
return 0 ;
}
static int F_129 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_376 ;
struct V_697 V_738 ;
T_2 V_509 ;
int V_26 ;
if ( V_102 -> V_103 != V_107 )
return - V_369 ;
if ( ! V_4 -> V_205 -> V_249 )
return - V_369 ;
V_26 = F_125 ( V_2 , & V_738 , & V_509 ) ;
if ( V_26 )
return V_26 ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_700 )
V_26 = - V_110 ;
if ( ! V_26 )
V_26 = V_4 -> V_205 -> V_249 ( & V_4 -> V_118 , V_6 ,
V_509 , & V_738 ) ;
F_70 ( V_102 ) ;
return V_26 ;
}
static int F_130 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
void * V_142 = NULL ;
struct V_7 * V_763 ;
unsigned int V_117 ;
int V_26 = - V_11 ;
F_54 ( & V_343 ) ;
if ( ! V_694 )
goto V_416;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 ) {
V_26 = - V_53 ;
goto V_416;
}
V_142 = F_21 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_764 ) ;
if ( ! V_142 )
goto V_765;
F_45 ( V_37 , V_696 ,
V_694 -> V_766 ) ;
V_763 = F_41 ( V_37 , V_767 ) ;
if ( ! V_763 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_694 -> V_768 ; V_117 ++ ) {
struct V_7 * V_769 ;
const struct V_676 * V_677 ;
const struct V_678 * V_679 ;
const struct V_680 * V_681 ;
V_677 = & V_694 -> V_770 [ V_117 ] ;
V_679 = & V_677 -> V_679 ;
V_681 = & V_677 -> V_681 ;
V_769 = F_41 ( V_37 , V_117 ) ;
if ( ! V_769 )
goto V_52;
F_24 ( V_37 , V_682 ,
V_677 -> V_35 ) ;
F_24 ( V_37 , V_683 ,
V_679 -> V_687 ) ;
F_24 ( V_37 , V_684 ,
V_679 -> V_688 ) ;
F_24 ( V_37 , V_685 ,
V_679 -> V_689 ) ;
F_24 ( V_37 , V_691 ,
V_681 -> V_692 ) ;
F_24 ( V_37 , V_686 ,
V_681 -> V_690 ) ;
F_42 ( V_37 , V_769 ) ;
}
F_42 ( V_37 , V_763 ) ;
F_51 ( V_37 , V_142 ) ;
V_26 = F_63 ( V_37 , V_2 ) ;
goto V_416;
V_52:
F_52 ( V_37 , V_142 ) ;
V_765:
F_62 ( V_37 ) ;
V_26 = - V_341 ;
V_416:
F_59 ( & V_343 ) ;
return V_26 ;
}
static int F_131 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_7 * V_57 [ V_771 + 1 ] ;
struct V_7 * V_769 ;
char * V_766 = NULL ;
int V_772 = 0 , V_693 = 0 ;
T_2 V_773 = 0 , V_774 = 0 , V_775 ;
struct V_776 * V_777 = NULL ;
if ( ! V_2 -> V_8 [ V_696 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_767 ] )
return - V_11 ;
V_766 = F_19 ( V_2 -> V_8 [ V_696 ] ) ;
F_35 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_773 ++ ;
if ( V_773 > V_778 )
return - V_11 ;
}
F_54 ( & V_343 ) ;
if ( ! F_132 ( V_766 ) ) {
V_693 = - V_11 ;
goto V_779;
}
V_775 = sizeof( struct V_776 ) +
( V_773 * sizeof( struct V_676 ) ) ;
V_777 = F_33 ( V_775 , V_97 ) ;
if ( ! V_777 ) {
V_693 = - V_98 ;
goto V_779;
}
V_777 -> V_768 = V_773 ;
V_777 -> V_766 [ 0 ] = V_766 [ 0 ] ;
V_777 -> V_766 [ 1 ] = V_766 [ 1 ] ;
F_35 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_78 ( V_57 , V_771 ,
F_19 ( V_769 ) , F_20 ( V_769 ) ,
V_780 ) ;
V_693 = F_120 ( V_57 , & V_777 -> V_770 [ V_774 ] ) ;
if ( V_693 )
goto V_779;
V_774 ++ ;
if ( V_774 > V_778 ) {
V_693 = - V_11 ;
goto V_779;
}
}
F_133 ( V_774 != V_773 ) ;
V_693 = F_134 ( V_777 ) ;
F_59 ( & V_343 ) ;
return V_693 ;
V_779:
F_59 ( & V_343 ) ;
F_37 ( V_777 ) ;
return V_693 ;
}
static int F_135 ( struct V_7 * V_781 )
{
struct V_7 * V_782 , * V_783 ;
int V_227 = 0 , V_784 , V_785 ;
F_35 (attr1, freqs, tmp1) {
V_227 ++ ;
F_35 (attr2, freqs, tmp2)
if ( V_782 != V_783 &&
F_2 ( V_782 ) == F_2 ( V_783 ) )
return 0 ;
}
return V_227 ;
}
static int F_136 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_786 * V_787 ;
struct V_7 * V_29 ;
struct V_118 * V_118 ;
int V_26 , V_788 , V_789 = 0 , V_227 , V_117 ;
T_10 V_758 ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
V_118 = & V_4 -> V_118 ;
if ( ! V_4 -> V_205 -> V_790 )
return - V_369 ;
if ( V_4 -> V_791 )
return - V_379 ;
if ( V_2 -> V_8 [ V_792 ] ) {
V_227 = F_135 (
V_2 -> V_8 [ V_792 ] ) ;
if ( ! V_227 )
return - V_11 ;
} else {
enum V_150 V_151 ;
V_227 = 0 ;
for ( V_151 = 0 ; V_151 < V_214 ; V_151 ++ )
if ( V_118 -> V_215 [ V_151 ] )
V_227 += V_118 -> V_215 [ V_151 ] -> V_227 ;
}
if ( V_2 -> V_8 [ V_793 ] )
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_789 ++ ;
if ( V_789 > V_118 -> V_173 )
return - V_11 ;
if ( V_2 -> V_8 [ V_465 ] )
V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
else
V_758 = 0 ;
if ( V_758 > V_118 -> V_177 )
return - V_11 ;
V_787 = F_33 ( sizeof( * V_787 )
+ sizeof( * V_787 -> V_794 ) * V_789
+ sizeof( * V_787 -> V_228 ) * V_227
+ V_758 , V_97 ) ;
if ( ! V_787 )
return - V_98 ;
if ( V_789 )
V_787 -> V_794 = ( void * ) & V_787 -> V_228 [ V_227 ] ;
V_787 -> V_789 = V_789 ;
if ( V_758 ) {
if ( V_787 -> V_794 )
V_787 -> V_757 = ( void * ) ( V_787 -> V_794 + V_789 ) ;
else
V_787 -> V_757 = ( void * ) ( V_787 -> V_228 + V_227 ) ;
}
V_117 = 0 ;
if ( V_2 -> V_8 [ V_792 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_38 * V_39 ;
V_39 = F_137 ( V_118 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_795;
}
if ( V_39 -> V_35 & V_42 )
continue;
V_787 -> V_228 [ V_117 ] = V_39 ;
V_117 ++ ;
}
} else {
enum V_150 V_151 ;
for ( V_151 = 0 ; V_151 < V_214 ; V_151 ++ ) {
int V_120 ;
if ( ! V_118 -> V_215 [ V_151 ] )
continue;
for ( V_120 = 0 ; V_120 < V_118 -> V_215 [ V_151 ] -> V_227 ; V_120 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_118 -> V_215 [ V_151 ] -> V_228 [ V_120 ] ;
if ( V_39 -> V_35 & V_42 )
continue;
V_787 -> V_228 [ V_117 ] = V_39 ;
V_117 ++ ;
}
}
}
if ( ! V_117 ) {
V_26 = - V_11 ;
goto V_795;
}
V_787 -> V_227 = V_117 ;
V_117 = 0 ;
if ( V_2 -> V_8 [ V_793 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_20 ( V_29 ) > V_434 ) {
V_26 = - V_11 ;
goto V_795;
}
V_787 -> V_794 [ V_117 ] . V_476 = F_20 ( V_29 ) ;
memcpy ( V_787 -> V_794 [ V_117 ] . V_437 , F_19 ( V_29 ) , F_20 ( V_29 ) ) ;
V_117 ++ ;
}
}
if ( V_2 -> V_8 [ V_465 ] ) {
V_787 -> V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
memcpy ( ( void * ) V_787 -> V_757 ,
F_19 ( V_2 -> V_8 [ V_465 ] ) ,
V_787 -> V_758 ) ;
}
for ( V_117 = 0 ; V_117 < V_214 ; V_117 ++ )
if ( V_118 -> V_215 [ V_117 ] )
V_787 -> V_796 [ V_117 ] =
( 1 << V_118 -> V_215 [ V_117 ] -> V_230 ) - 1 ;
if ( V_2 -> V_8 [ V_797 ] ) {
F_35 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_150 V_151 = F_138 ( V_29 ) ;
if ( V_151 < 0 || V_151 >= V_214 ) {
V_26 = - V_11 ;
goto V_795;
}
V_26 = F_139 ( V_118 -> V_215 [ V_151 ] ,
F_19 ( V_29 ) ,
F_20 ( V_29 ) ,
& V_787 -> V_796 [ V_151 ] ) ;
if ( V_26 )
goto V_795;
}
}
V_787 -> V_798 =
F_128 ( V_2 -> V_8 [ V_799 ] ) ;
V_787 -> V_6 = V_6 ;
V_787 -> V_118 = & V_4 -> V_118 ;
V_4 -> V_791 = V_787 ;
V_26 = V_4 -> V_205 -> V_790 ( & V_4 -> V_118 , V_6 , V_787 ) ;
if ( ! V_26 ) {
F_140 ( V_4 , V_6 ) ;
F_141 ( V_6 ) ;
} else {
V_795:
V_4 -> V_791 = NULL ;
F_37 ( V_787 ) ;
}
return V_26 ;
}
static int F_142 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_800 * V_787 ;
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_7 * V_29 ;
struct V_118 * V_118 ;
int V_26 , V_788 , V_789 = 0 , V_801 = 0 , V_227 , V_117 ;
T_2 V_473 ;
enum V_150 V_151 ;
T_10 V_758 ;
struct V_7 * V_57 [ V_802 + 1 ] ;
if ( ! ( V_4 -> V_118 . V_35 & V_289 ) ||
! V_4 -> V_205 -> V_290 )
return - V_369 ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_803 ] )
return - V_11 ;
V_473 = F_2 ( V_2 -> V_8 [ V_803 ] ) ;
if ( V_473 == 0 )
return - V_11 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_792 ] ) {
V_227 = F_135 (
V_2 -> V_8 [ V_792 ] ) ;
if ( ! V_227 )
return - V_11 ;
} else {
V_227 = 0 ;
for ( V_151 = 0 ; V_151 < V_214 ; V_151 ++ )
if ( V_118 -> V_215 [ V_151 ] )
V_227 += V_118 -> V_215 [ V_151 ] -> V_227 ;
}
if ( V_2 -> V_8 [ V_793 ] )
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_789 ++ ;
if ( V_789 > V_118 -> V_175 )
return - V_11 ;
if ( V_2 -> V_8 [ V_804 ] )
F_35 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_801 ++ ;
if ( V_801 > V_118 -> V_181 )
return - V_11 ;
if ( V_2 -> V_8 [ V_465 ] )
V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
else
V_758 = 0 ;
if ( V_758 > V_118 -> V_179 )
return - V_11 ;
F_54 ( & V_4 -> V_805 ) ;
if ( V_4 -> V_806 ) {
V_26 = - V_695 ;
goto V_416;
}
V_787 = F_33 ( sizeof( * V_787 )
+ sizeof( * V_787 -> V_794 ) * V_789
+ sizeof( * V_787 -> V_807 ) * V_801
+ sizeof( * V_787 -> V_228 ) * V_227
+ V_758 , V_97 ) ;
if ( ! V_787 ) {
V_26 = - V_98 ;
goto V_416;
}
if ( V_789 )
V_787 -> V_794 = ( void * ) & V_787 -> V_228 [ V_227 ] ;
V_787 -> V_789 = V_789 ;
if ( V_758 ) {
if ( V_787 -> V_794 )
V_787 -> V_757 = ( void * ) ( V_787 -> V_794 + V_789 ) ;
else
V_787 -> V_757 = ( void * ) ( V_787 -> V_228 + V_227 ) ;
}
if ( V_801 ) {
if ( V_787 -> V_757 )
V_787 -> V_807 = ( void * ) ( V_787 -> V_757 + V_758 ) ;
else if ( V_787 -> V_794 )
V_787 -> V_807 =
( void * ) ( V_787 -> V_794 + V_789 ) ;
else
V_787 -> V_807 =
( void * ) ( V_787 -> V_228 + V_227 ) ;
}
V_787 -> V_801 = V_801 ;
V_117 = 0 ;
if ( V_2 -> V_8 [ V_792 ] ) {
F_35 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_38 * V_39 ;
V_39 = F_137 ( V_118 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_795;
}
if ( V_39 -> V_35 & V_42 )
continue;
V_787 -> V_228 [ V_117 ] = V_39 ;
V_117 ++ ;
}
} else {
for ( V_151 = 0 ; V_151 < V_214 ; V_151 ++ ) {
int V_120 ;
if ( ! V_118 -> V_215 [ V_151 ] )
continue;
for ( V_120 = 0 ; V_120 < V_118 -> V_215 [ V_151 ] -> V_227 ; V_120 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_118 -> V_215 [ V_151 ] -> V_228 [ V_120 ] ;
if ( V_39 -> V_35 & V_42 )
continue;
V_787 -> V_228 [ V_117 ] = V_39 ;
V_117 ++ ;
}
}
}
if ( ! V_117 ) {
V_26 = - V_11 ;
goto V_795;
}
V_787 -> V_227 = V_117 ;
V_117 = 0 ;
if ( V_2 -> V_8 [ V_793 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_20 ( V_29 ) > V_434 ) {
V_26 = - V_11 ;
goto V_795;
}
V_787 -> V_794 [ V_117 ] . V_476 = F_20 ( V_29 ) ;
memcpy ( V_787 -> V_794 [ V_117 ] . V_437 , F_19 ( V_29 ) ,
F_20 ( V_29 ) ) ;
V_117 ++ ;
}
}
V_117 = 0 ;
if ( V_2 -> V_8 [ V_804 ] ) {
F_35 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_7 * V_437 ;
F_78 ( V_57 , V_802 ,
F_19 ( V_29 ) , F_20 ( V_29 ) ,
V_808 ) ;
V_437 = V_57 [ V_809 ] ;
if ( V_437 ) {
if ( F_20 ( V_437 ) > V_434 ) {
V_26 = - V_11 ;
goto V_795;
}
memcpy ( V_787 -> V_807 [ V_117 ] . V_437 . V_437 ,
F_19 ( V_437 ) , F_20 ( V_437 ) ) ;
V_787 -> V_807 [ V_117 ] . V_437 . V_476 =
F_20 ( V_437 ) ;
}
V_117 ++ ;
}
}
if ( V_2 -> V_8 [ V_465 ] ) {
V_787 -> V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
memcpy ( ( void * ) V_787 -> V_757 ,
F_19 ( V_2 -> V_8 [ V_465 ] ) ,
V_787 -> V_758 ) ;
}
V_787 -> V_6 = V_6 ;
V_787 -> V_118 = & V_4 -> V_118 ;
V_787 -> V_473 = V_473 ;
V_26 = V_4 -> V_205 -> V_290 ( & V_4 -> V_118 , V_6 , V_787 ) ;
if ( ! V_26 ) {
V_4 -> V_806 = V_787 ;
F_143 ( V_4 , V_6 ,
V_810 ) ;
goto V_416;
}
V_795:
F_37 ( V_787 ) ;
V_416:
F_59 ( & V_4 -> V_805 ) ;
return V_26 ;
}
static int F_144 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
if ( ! ( V_4 -> V_118 . V_35 & V_289 ) ||
! V_4 -> V_205 -> V_811 )
return - V_369 ;
F_54 ( & V_4 -> V_805 ) ;
V_26 = F_145 ( V_4 , false ) ;
F_59 ( & V_4 -> V_805 ) ;
return V_26 ;
}
static int F_146 ( struct V_23 * V_37 , struct V_13 * V_14 ,
T_2 V_34 , int V_35 ,
struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_812 * V_813 )
{
struct V_814 * V_15 = & V_813 -> V_815 ;
void * V_142 ;
struct V_7 * V_816 ;
int V_117 ;
F_39 ( V_102 ) ;
V_142 = F_21 ( V_37 , F_58 ( V_14 -> V_24 ) . V_33 , V_34 , V_35 ,
V_817 ) ;
if ( ! V_142 )
return - 1 ;
F_147 ( V_14 , V_142 , & V_18 ) ;
F_24 ( V_37 , V_160 , V_4 -> V_818 ) ;
F_24 ( V_37 , V_10 , V_102 -> V_375 -> V_9 ) ;
V_816 = F_41 ( V_37 , V_819 ) ;
if ( ! V_816 )
goto V_52;
if ( ! F_148 ( V_15 -> V_377 ) )
F_49 ( V_37 , V_820 , V_453 , V_15 -> V_377 ) ;
if ( V_15 -> V_821 && V_15 -> V_822 )
F_49 ( V_37 , V_823 ,
V_15 -> V_822 ,
V_15 -> V_821 ) ;
if ( V_15 -> V_495 && V_15 -> V_824 &&
V_15 -> V_495 != V_15 -> V_821 )
F_49 ( V_37 , V_825 ,
V_15 -> V_824 , V_15 -> V_495 ) ;
if ( V_15 -> V_826 )
F_149 ( V_37 , V_827 , V_15 -> V_826 ) ;
if ( V_15 -> V_501 )
F_48 ( V_37 , V_828 , V_15 -> V_501 ) ;
F_48 ( V_37 , V_829 , V_15 -> V_830 ) ;
F_24 ( V_37 , V_831 , V_15 -> V_832 -> V_41 ) ;
F_24 ( V_37 , V_833 ,
F_150 ( V_834 - V_813 -> V_835 ) ) ;
switch ( V_4 -> V_118 . V_836 ) {
case V_837 :
F_24 ( V_37 , V_838 , V_15 -> signal ) ;
break;
case V_839 :
F_47 ( V_37 , V_840 , V_15 -> signal ) ;
break;
default:
break;
}
switch ( V_102 -> V_103 ) {
case V_112 :
case V_111 :
if ( V_813 == V_102 -> V_109 )
F_24 ( V_37 , V_841 ,
V_842 ) ;
else for ( V_117 = 0 ; V_117 < V_843 ; V_117 ++ ) {
if ( V_813 != V_102 -> V_844 [ V_117 ] )
continue;
F_24 ( V_37 , V_841 ,
V_845 ) ;
break;
}
break;
case V_108 :
if ( V_813 == V_102 -> V_109 )
F_24 ( V_37 , V_841 ,
V_846 ) ;
break;
default:
break;
}
F_42 ( V_37 , V_816 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
static int F_151 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_812 * V_790 ;
struct V_101 * V_102 ;
int V_342 = V_14 -> args [ 1 ] , V_67 = 0 ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_4 , & V_6 ) ;
if ( V_26 )
return V_26 ;
V_102 = V_6 -> V_376 ;
F_68 ( V_102 ) ;
F_152 ( & V_4 -> V_847 ) ;
F_153 ( V_4 ) ;
V_14 -> V_34 = V_4 -> V_818 ;
F_55 (scan, &rdev->bss_list, list) {
if ( ++ V_67 <= V_342 )
continue;
if ( F_146 ( V_24 , V_14 ,
V_14 -> V_16 -> V_344 , V_345 ,
V_4 , V_102 , V_790 ) < 0 ) {
V_67 -- ;
break;
}
}
F_154 ( & V_4 -> V_847 ) ;
F_70 ( V_102 ) ;
V_14 -> args [ 1 ] = V_67 ;
F_16 ( V_4 ) ;
return V_24 -> V_31 ;
}
static int F_155 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
struct V_848 * V_849 )
{
void * V_142 ;
struct V_7 * V_850 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 ,
V_851 ) ;
if ( ! V_142 )
return - V_98 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
V_850 = F_41 ( V_37 , V_852 ) ;
if ( ! V_850 )
goto V_52;
F_24 ( V_37 , V_853 ,
V_849 -> V_832 -> V_41 ) ;
if ( V_849 -> V_531 & V_854 )
F_47 ( V_37 , V_855 ,
V_849 -> V_856 ) ;
if ( V_849 -> V_531 & V_857 )
F_25 ( V_37 , V_858 ) ;
if ( V_849 -> V_531 & V_859 )
F_149 ( V_37 , V_860 ,
V_849 -> V_861 ) ;
if ( V_849 -> V_531 & V_862 )
F_149 ( V_37 , V_863 ,
V_849 -> V_864 ) ;
if ( V_849 -> V_531 & V_865 )
F_149 ( V_37 , V_866 ,
V_849 -> V_867 ) ;
if ( V_849 -> V_531 & V_868 )
F_149 ( V_37 , V_869 ,
V_849 -> V_870 ) ;
if ( V_849 -> V_531 & V_871 )
F_149 ( V_37 , V_872 ,
V_849 -> V_873 ) ;
F_42 ( V_37 , V_850 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
static int F_156 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_848 V_849 ;
struct V_3 * V_6 ;
struct V_5 * V_375 ;
int V_874 = V_14 -> args [ 1 ] ;
int V_15 ;
V_15 = F_11 ( V_24 , V_14 , & V_6 , & V_375 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_6 -> V_205 -> V_875 ) {
V_15 = - V_369 ;
goto V_593;
}
while ( 1 ) {
struct V_38 * V_39 ;
V_15 = V_6 -> V_205 -> V_875 ( & V_6 -> V_118 , V_375 , V_874 ,
& V_849 ) ;
if ( V_15 == - V_454 )
break;
if ( V_15 )
goto V_593;
if ( ! V_849 . V_832 ) {
V_15 = - V_11 ;
goto V_416;
}
V_39 = F_137 ( & V_6 -> V_118 ,
V_849 . V_832 -> V_41 ) ;
if ( ! V_39 || V_39 -> V_35 & V_42 ) {
V_874 ++ ;
continue;
}
if ( F_155 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_344 , V_345 ,
V_375 ,
& V_849 ) < 0 )
goto V_416;
V_874 ++ ;
}
V_416:
V_14 -> args [ 1 ] = V_874 ;
V_15 = V_24 -> V_31 ;
V_593:
F_16 ( V_6 ) ;
return V_15 ;
}
static bool F_98 ( enum V_876 V_485 )
{
return V_485 <= V_877 ;
}
static bool F_157 ( T_2 V_878 )
{
return ! ( V_878 & ~ ( V_879 |
V_880 ) ) ;
}
static int F_158 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_38 * V_39 ;
const T_1 * V_377 , * V_437 , * V_757 = NULL ;
int V_26 , V_476 , V_758 = 0 ;
enum V_876 V_485 ;
struct V_55 V_54 ;
bool V_881 ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_484 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_475 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_368 ] )
return - V_11 ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 >= 0 ) {
if ( V_54 . type != - 1 && V_54 . type != V_449 )
return - V_11 ;
if ( ! V_54 . V_69 . V_54 || ! V_54 . V_69 . V_70 )
return - V_11 ;
if ( ( V_54 . V_69 . V_74 != V_882 ||
V_54 . V_69 . V_70 != V_883 ) &&
( V_54 . V_69 . V_74 != V_884 ||
V_54 . V_69 . V_70 != V_885 ) )
return - V_11 ;
if ( V_54 . V_67 > 4 )
return - V_11 ;
} else {
V_54 . V_69 . V_70 = 0 ;
V_54 . V_69 . V_54 = NULL ;
}
if ( V_54 . V_67 >= 0 ) {
int V_117 ;
bool V_886 = false ;
for ( V_117 = 0 ; V_117 < V_4 -> V_118 . V_195 ; V_117 ++ ) {
if ( V_54 . V_69 . V_74 == V_4 -> V_118 . V_196 [ V_117 ] ) {
V_886 = true ;
break;
}
}
if ( ! V_886 )
return - V_11 ;
}
if ( ! V_4 -> V_205 -> V_253 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_39 = F_137 ( & V_4 -> V_118 ,
F_2 ( V_2 -> V_8 [ V_368 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_42 ) )
return - V_11 ;
V_437 = F_19 ( V_2 -> V_8 [ V_475 ] ) ;
V_476 = F_20 ( V_2 -> V_8 [ V_475 ] ) ;
if ( V_2 -> V_8 [ V_465 ] ) {
V_757 = F_19 ( V_2 -> V_8 [ V_465 ] ) ;
V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
}
V_485 = F_2 ( V_2 -> V_8 [ V_484 ] ) ;
if ( ! F_98 ( V_485 ) )
return - V_11 ;
V_881 = ! ! V_2 -> V_8 [ V_887 ] ;
return F_159 ( V_4 , V_6 , V_39 , V_485 , V_377 ,
V_437 , V_476 , V_757 , V_758 ,
V_54 . V_69 . V_54 , V_54 . V_69 . V_70 , V_54 . V_67 ,
V_881 ) ;
}
static int F_99 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_888 * V_889 ,
int V_890 )
{
memset ( V_889 , 0 , sizeof( * V_889 ) ) ;
V_889 -> V_891 = V_2 -> V_8 [ V_892 ] ;
if ( V_2 -> V_8 [ V_200 ] ) {
T_3 V_893 ;
V_893 = F_65 (
V_2 -> V_8 [ V_200 ] ) ;
V_889 -> V_894 = F_160 ( V_893 ) ;
if ( ! ( V_4 -> V_118 . V_35 & V_199 ) &&
V_893 != V_895 )
return - V_11 ;
if ( V_2 -> V_8 [ V_896 ] )
V_889 -> V_897 = true ;
} else
V_889 -> V_894 = F_160 ( V_895 ) ;
if ( V_2 -> V_8 [ V_898 ] ) {
void * V_100 ;
int V_31 , V_117 ;
V_100 = F_19 ( V_2 -> V_8 [ V_898 ] ) ;
V_31 = F_20 ( V_2 -> V_8 [ V_898 ] ) ;
V_889 -> V_899 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
if ( V_889 -> V_899 > V_890 )
return - V_11 ;
memcpy ( V_889 -> V_900 , V_100 , V_31 ) ;
for ( V_117 = 0 ; V_117 < V_889 -> V_899 ; V_117 ++ )
if ( ! F_161 (
& V_4 -> V_118 ,
V_889 -> V_900 [ V_117 ] ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_901 ] ) {
V_889 -> V_902 =
F_2 ( V_2 -> V_8 [ V_901 ] ) ;
if ( ! F_161 ( & V_4 -> V_118 ,
V_889 -> V_902 ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_903 ] ) {
V_889 -> V_878 =
F_2 ( V_2 -> V_8 [ V_903 ] ) ;
if ( ! F_157 ( V_889 -> V_878 ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_904 ] ) {
void * V_100 ;
int V_31 ;
V_100 = F_19 ( V_2 -> V_8 [ V_904 ] ) ;
V_31 = F_20 ( V_2 -> V_8 [ V_904 ] ) ;
V_889 -> V_905 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
if ( V_889 -> V_905 > V_906 )
return - V_11 ;
memcpy ( V_889 -> V_907 , V_100 , V_31 ) ;
}
return 0 ;
}
static int F_162 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_888 V_487 ;
struct V_38 * V_39 ;
const T_1 * V_377 , * V_437 , * V_757 = NULL , * V_908 = NULL ;
int V_26 , V_476 , V_758 = 0 ;
bool V_909 = false ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_378 ] ||
! V_2 -> V_8 [ V_475 ] ||
! V_2 -> V_8 [ V_368 ] )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_255 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_39 = F_137 ( & V_4 -> V_118 ,
F_2 ( V_2 -> V_8 [ V_368 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_42 ) )
return - V_11 ;
V_437 = F_19 ( V_2 -> V_8 [ V_475 ] ) ;
V_476 = F_20 ( V_2 -> V_8 [ V_475 ] ) ;
if ( V_2 -> V_8 [ V_465 ] ) {
V_757 = F_19 ( V_2 -> V_8 [ V_465 ] ) ;
V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
}
if ( V_2 -> V_8 [ V_910 ] ) {
enum V_911 V_912 =
F_2 ( V_2 -> V_8 [ V_910 ] ) ;
if ( V_912 == V_913 )
V_909 = true ;
else if ( V_912 != V_914 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_915 ] )
V_908 = F_19 ( V_2 -> V_8 [ V_915 ] ) ;
V_26 = F_99 ( V_4 , V_2 , & V_487 , 1 ) ;
if ( ! V_26 )
V_26 = F_163 ( V_4 , V_6 , V_39 , V_377 , V_908 ,
V_437 , V_476 , V_757 , V_758 , V_909 ,
& V_487 ) ;
return V_26 ;
}
static int F_164 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
const T_1 * V_757 = NULL , * V_377 ;
int V_758 = 0 ;
T_3 V_916 ;
bool V_881 ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_917 ] )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_257 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_916 = F_65 ( V_2 -> V_8 [ V_917 ] ) ;
if ( V_916 == 0 ) {
return - V_11 ;
}
if ( V_2 -> V_8 [ V_465 ] ) {
V_757 = F_19 ( V_2 -> V_8 [ V_465 ] ) ;
V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
}
V_881 = ! ! V_2 -> V_8 [ V_887 ] ;
return F_165 ( V_4 , V_6 , V_377 , V_757 , V_758 , V_916 ,
V_881 ) ;
}
static int F_166 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
const T_1 * V_757 = NULL , * V_377 ;
int V_758 = 0 ;
T_3 V_916 ;
bool V_881 ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_917 ] )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_259 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_916 = F_65 ( V_2 -> V_8 [ V_917 ] ) ;
if ( V_916 == 0 ) {
return - V_11 ;
}
if ( V_2 -> V_8 [ V_465 ] ) {
V_757 = F_19 ( V_2 -> V_8 [ V_465 ] ) ;
V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
}
V_881 = ! ! V_2 -> V_8 [ V_887 ] ;
return F_167 ( V_4 , V_6 , V_377 , V_757 , V_758 , V_916 ,
V_881 ) ;
}
static bool
F_168 ( struct V_3 * V_4 ,
int V_918 [ V_214 ] ,
int V_919 )
{
struct V_118 * V_118 = & V_4 -> V_118 ;
bool V_920 = false ;
int V_151 , V_117 ;
for ( V_151 = 0 ; V_151 < V_214 ; V_151 ++ ) {
struct V_921 * V_922 ;
V_922 = V_118 -> V_215 [ V_151 ] ;
if ( ! V_922 )
continue;
for ( V_117 = 0 ; V_117 < V_922 -> V_230 ; V_117 ++ ) {
if ( V_922 -> V_231 [ V_117 ] . V_233 == V_919 ) {
V_918 [ V_151 ] = V_117 + 1 ;
V_920 = true ;
break;
}
}
}
return V_920 ;
}
static int F_169 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_923 V_924 ;
struct V_118 * V_118 ;
struct V_92 * V_925 = NULL ;
int V_26 ;
memset ( & V_924 , 0 , sizeof( V_924 ) ) ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_368 ] ||
! V_2 -> V_8 [ V_475 ] ||
! F_20 ( V_2 -> V_8 [ V_475 ] ) )
return - V_11 ;
V_924 . V_501 = 100 ;
if ( V_2 -> V_8 [ V_470 ] ) {
V_924 . V_501 =
F_2 ( V_2 -> V_8 [ V_470 ] ) ;
if ( V_924 . V_501 < 1 || V_924 . V_501 > 10000 )
return - V_11 ;
}
if ( ! V_4 -> V_205 -> V_261 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_108 )
return - V_369 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_378 ] ) {
V_924 . V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( ! F_170 ( V_924 . V_377 ) )
return - V_11 ;
}
V_924 . V_437 = F_19 ( V_2 -> V_8 [ V_475 ] ) ;
V_924 . V_476 = F_20 ( V_2 -> V_8 [ V_475 ] ) ;
if ( V_2 -> V_8 [ V_465 ] ) {
V_924 . V_757 = F_19 ( V_2 -> V_8 [ V_465 ] ) ;
V_924 . V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
}
V_924 . V_832 = F_137 ( V_118 ,
F_2 ( V_2 -> V_8 [ V_368 ] ) ) ;
if ( ! V_924 . V_832 ||
V_924 . V_832 -> V_35 & V_46 ||
V_924 . V_832 -> V_35 & V_42 )
return - V_11 ;
V_924 . V_926 = ! ! V_2 -> V_8 [ V_927 ] ;
V_924 . V_482 = ! ! V_2 -> V_8 [ V_483 ] ;
if ( V_2 -> V_8 [ V_671 ] ) {
T_1 * V_796 =
F_19 ( V_2 -> V_8 [ V_671 ] ) ;
int V_928 =
F_20 ( V_2 -> V_8 [ V_671 ] ) ;
struct V_921 * V_922 =
V_118 -> V_215 [ V_924 . V_832 -> V_151 ] ;
int V_26 ;
V_26 = F_139 ( V_922 , V_796 , V_928 ,
& V_924 . V_672 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_2 -> V_8 [ V_929 ] &&
! F_168 ( V_4 , V_924 . V_918 ,
F_2 ( V_2 -> V_8 [ V_929 ] ) ) )
return - V_11 ;
if ( V_924 . V_482 && V_2 -> V_8 [ V_930 ] ) {
V_925 = F_32 ( V_4 ,
V_2 -> V_8 [ V_930 ] ) ;
if ( F_6 ( V_925 ) )
return F_8 ( V_925 ) ;
}
V_26 = F_171 ( V_4 , V_6 , & V_924 , V_925 ) ;
if ( V_26 )
F_37 ( V_925 ) ;
return V_26 ;
}
static int F_172 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
if ( ! V_4 -> V_205 -> V_931 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_108 )
return - V_369 ;
return F_173 ( V_4 , V_6 , false ) ;
}
static int F_174 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_932 ] )
return - V_11 ;
V_26 = - V_369 ;
if ( V_4 -> V_205 -> V_933 ) {
V_4 -> V_934 = V_2 ;
V_26 = V_4 -> V_205 -> V_933 ( & V_4 -> V_118 ,
F_19 ( V_2 -> V_8 [ V_932 ] ) ,
F_20 ( V_2 -> V_8 [ V_932 ] ) ) ;
V_4 -> V_934 = NULL ;
}
return V_26 ;
}
static int F_175 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_3 * V_6 ;
int V_26 ;
long V_935 ;
void * V_100 = NULL ;
int V_936 = 0 ;
if ( V_14 -> args [ 0 ] ) {
V_935 = V_14 -> args [ 0 ] - 1 ;
} else {
V_26 = F_10 ( V_14 -> V_16 , V_17 + V_18 . V_19 ,
V_18 . V_20 , V_18 . V_21 ,
V_22 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_18 . V_20 [ V_157 ] )
return - V_11 ;
V_935 = F_2 ( V_18 . V_20 [ V_157 ] ) ;
if ( V_18 . V_20 [ V_932 ] )
V_14 -> args [ 1 ] =
( long ) V_18 . V_20 [ V_932 ] ;
}
if ( V_14 -> args [ 1 ] ) {
V_100 = F_19 ( ( void * ) V_14 -> args [ 1 ] ) ;
V_936 = F_20 ( ( void * ) V_14 -> args [ 1 ] ) ;
}
F_54 ( & V_343 ) ;
V_6 = F_176 ( V_935 ) ;
if ( ! V_6 ) {
F_59 ( & V_343 ) ;
return - V_454 ;
}
F_177 ( V_6 ) ;
F_59 ( & V_343 ) ;
if ( ! V_6 -> V_205 -> V_937 ) {
V_26 = - V_369 ;
goto V_593;
}
while ( 1 ) {
void * V_142 = F_21 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_344 , V_345 ,
V_938 ) ;
struct V_7 * V_939 ;
if ( F_178 ( V_24 , V_157 , V_6 -> V_158 ) < 0 ) {
F_52 ( V_24 , V_142 ) ;
break;
}
V_939 = F_41 ( V_24 , V_932 ) ;
if ( ! V_939 ) {
F_52 ( V_24 , V_142 ) ;
break;
}
V_26 = V_6 -> V_205 -> V_937 ( & V_6 -> V_118 , V_24 , V_14 ,
V_100 , V_936 ) ;
F_42 ( V_24 , V_939 ) ;
if ( V_26 == - V_53 || V_26 == - V_454 ) {
F_52 ( V_24 , V_142 ) ;
break;
} else if ( V_26 ) {
F_52 ( V_24 , V_142 ) ;
goto V_593;
}
F_51 ( V_24 , V_142 ) ;
}
V_26 = V_24 -> V_31 ;
V_14 -> args [ 0 ] = V_935 + 1 ;
V_593:
F_17 ( V_6 ) ;
return V_26 ;
}
static struct V_23 *
F_179 ( struct V_3 * V_4 ,
int V_940 , T_2 V_33 , T_2 V_34 , T_11 V_941 )
{
struct V_23 * V_24 ;
void * V_142 ;
struct V_7 * V_100 ;
V_24 = F_61 ( V_940 + 100 , V_941 ) ;
if ( ! V_24 )
return NULL ;
V_142 = F_21 ( V_24 , V_33 , V_34 , 0 , V_938 ) ;
if ( ! V_142 ) {
F_180 ( V_24 ) ;
return NULL ;
}
F_24 ( V_24 , V_157 , V_4 -> V_158 ) ;
V_100 = F_41 ( V_24 , V_932 ) ;
( ( void * * ) V_24 -> V_14 ) [ 0 ] = V_4 ;
( ( void * * ) V_24 -> V_14 ) [ 1 ] = V_142 ;
( ( void * * ) V_24 -> V_14 ) [ 2 ] = V_100 ;
return V_24 ;
V_52:
F_180 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_181 ( struct V_118 * V_118 ,
int V_940 )
{
struct V_3 * V_4 = F_75 ( V_118 ) ;
if ( F_100 ( ! V_4 -> V_934 ) )
return NULL ;
return F_179 ( V_4 , V_940 ,
V_4 -> V_934 -> V_348 ,
V_4 -> V_934 -> V_349 ,
V_97 ) ;
}
int F_182 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = ( ( void * * ) V_24 -> V_14 ) [ 0 ] ;
void * V_142 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_7 * V_100 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
if ( F_100 ( ! V_4 -> V_934 ) ) {
F_180 ( V_24 ) ;
return - V_11 ;
}
F_42 ( V_24 , V_100 ) ;
F_51 ( V_24 , V_142 ) ;
return F_63 ( V_24 , V_4 -> V_934 ) ;
}
struct V_23 * F_183 ( struct V_118 * V_118 ,
int V_940 , T_11 V_941 )
{
struct V_3 * V_4 = F_75 ( V_118 ) ;
return F_179 ( V_4 , V_940 , 0 , 0 , V_941 ) ;
}
void F_184 ( struct V_23 * V_24 , T_11 V_941 )
{
void * V_142 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_7 * V_100 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
F_42 ( V_24 , V_100 ) ;
F_51 ( V_24 , V_142 ) ;
F_185 ( V_24 , 0 , V_942 . V_943 , V_941 ) ;
}
static int F_186 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_944 V_292 ;
struct V_118 * V_118 ;
struct V_92 * V_925 = NULL ;
int V_26 ;
memset ( & V_292 , 0 , sizeof( V_292 ) ) ;
if ( ! F_18 ( V_2 -> V_8 [ V_465 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_475 ] ||
! F_20 ( V_2 -> V_8 [ V_475 ] ) )
return - V_11 ;
if ( V_2 -> V_8 [ V_484 ] ) {
V_292 . V_485 =
F_2 ( V_2 -> V_8 [ V_484 ] ) ;
if ( ! F_98 ( V_292 . V_485 ) )
return - V_11 ;
} else
V_292 . V_485 = V_486 ;
V_292 . V_482 = V_2 -> V_8 [ V_483 ] ;
V_26 = F_99 ( V_4 , V_2 , & V_292 . V_487 ,
V_488 ) ;
if ( V_26 )
return V_26 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_378 ] )
V_292 . V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_292 . V_437 = F_19 ( V_2 -> V_8 [ V_475 ] ) ;
V_292 . V_476 = F_20 ( V_2 -> V_8 [ V_475 ] ) ;
if ( V_2 -> V_8 [ V_465 ] ) {
V_292 . V_757 = F_19 ( V_2 -> V_8 [ V_465 ] ) ;
V_292 . V_758 = F_20 ( V_2 -> V_8 [ V_465 ] ) ;
}
if ( V_2 -> V_8 [ V_368 ] ) {
V_292 . V_832 =
F_137 ( V_118 ,
F_2 ( V_2 -> V_8 [ V_368 ] ) ) ;
if ( ! V_292 . V_832 ||
V_292 . V_832 -> V_35 & V_42 )
return - V_11 ;
}
if ( V_292 . V_482 && V_2 -> V_8 [ V_930 ] ) {
V_925 = F_32 ( V_4 ,
V_2 -> V_8 [ V_930 ] ) ;
if ( F_6 ( V_925 ) )
return F_8 ( V_925 ) ;
}
V_26 = F_187 ( V_4 , V_6 , & V_292 , V_925 ) ;
if ( V_26 )
F_37 ( V_925 ) ;
return V_26 ;
}
static int F_188 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_3 V_945 ;
if ( ! V_2 -> V_8 [ V_917 ] )
V_945 = V_946 ;
else
V_945 = F_65 ( V_2 -> V_8 [ V_917 ] ) ;
if ( V_945 == 0 )
return - V_11 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
return F_189 ( V_4 , V_6 , V_945 , true ) ;
}
static int F_190 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_947 * V_947 ;
int V_26 ;
T_2 V_33 ;
if ( ! V_2 -> V_8 [ V_948 ] )
return - V_11 ;
V_33 = F_2 ( V_2 -> V_8 [ V_948 ] ) ;
V_947 = F_191 ( V_33 ) ;
if ( F_6 ( V_947 ) )
return F_8 ( V_947 ) ;
V_26 = 0 ;
if ( ! F_56 ( F_57 ( & V_4 -> V_118 ) , V_947 ) )
V_26 = F_192 ( V_4 , V_947 ) ;
F_193 ( V_947 ) ;
return V_26 ;
}
static int F_194 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
int (* F_195)( struct V_118 * V_118 , struct V_5 * V_6 ,
struct V_949 * V_950 ) = NULL ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_949 V_950 ;
memset ( & V_950 , 0 , sizeof( struct V_949 ) ) ;
if ( ! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_951 ] )
return - V_11 ;
V_950 . V_952 = F_19 ( V_2 -> V_8 [ V_951 ] ) ;
V_950 . V_377 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
switch ( V_2 -> V_468 -> V_36 ) {
case V_953 :
F_195 = V_4 -> V_205 -> V_265 ;
break;
case V_954 :
F_195 = V_4 -> V_205 -> V_267 ;
break;
default:
F_100 ( 1 ) ;
break;
}
if ( ! F_195 )
return - V_369 ;
return F_195 ( & V_4 -> V_118 , V_6 , & V_950 ) ;
}
static int F_196 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_112 )
return - V_369 ;
if ( ! V_4 -> V_205 -> V_269 )
return - V_369 ;
return V_4 -> V_205 -> V_269 ( & V_4 -> V_118 , V_6 ) ;
}
static int F_197 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 V_955 , V_956 ;
T_3 V_957 ;
T_1 * V_958 ;
if ( ! ( V_4 -> V_118 . V_35 & V_190 ) ||
! V_4 -> V_205 -> V_285 )
return - V_369 ;
if ( ! V_2 -> V_8 [ V_959 ] ||
! V_2 -> V_8 [ V_960 ] ||
! V_2 -> V_8 [ V_961 ] ||
! V_2 -> V_8 [ V_465 ] ||
! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
V_958 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
V_955 = F_29 ( V_2 -> V_8 [ V_959 ] ) ;
V_957 = F_65 ( V_2 -> V_8 [ V_960 ] ) ;
V_956 = F_29 ( V_2 -> V_8 [ V_961 ] ) ;
return V_4 -> V_205 -> V_285 ( & V_4 -> V_118 , V_6 , V_958 , V_955 ,
V_956 , V_957 ,
F_19 ( V_2 -> V_8 [ V_465 ] ) ,
F_20 ( V_2 -> V_8 [ V_465 ] ) ) ;
}
static int F_198 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
enum V_962 V_963 ;
T_1 * V_958 ;
if ( ! ( V_4 -> V_118 . V_35 & V_190 ) ||
! V_4 -> V_205 -> V_287 )
return - V_369 ;
if ( ! V_2 -> V_8 [ V_964 ] ||
! V_2 -> V_8 [ V_378 ] )
return - V_11 ;
V_963 = F_29 ( V_2 -> V_8 [ V_964 ] ) ;
V_958 = F_19 ( V_2 -> V_8 [ V_378 ] ) ;
return V_4 -> V_205 -> V_287 ( & V_4 -> V_118 , V_6 , V_958 , V_963 ) ;
}
static int F_199 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_38 * V_39 ;
struct V_23 * V_37 ;
void * V_142 ;
T_12 V_444 ;
enum V_364 V_365 = V_366 ;
T_2 V_367 , V_965 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_368 ] ||
! V_2 -> V_8 [ V_966 ] )
return - V_11 ;
V_965 = F_2 ( V_2 -> V_8 [ V_966 ] ) ;
if ( ! V_965 || ! F_200 ( V_965 ) ||
V_965 > V_4 -> V_118 . V_297 )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_271 )
return - V_369 ;
if ( V_2 -> V_8 [ V_370 ] ) {
V_365 = F_2 (
V_2 -> V_8 [ V_370 ] ) ;
if ( V_365 != V_366 &&
V_365 != V_371 &&
V_365 != V_372 &&
V_365 != V_373 )
return - V_11 ;
}
V_367 = F_2 ( V_2 -> V_8 [ V_368 ] ) ;
V_39 = F_201 ( V_4 , V_367 , V_365 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_967 ) ;
if ( F_6 ( V_142 ) ) {
V_26 = F_8 ( V_142 ) ;
goto V_455;
}
V_26 = V_4 -> V_205 -> V_271 ( & V_4 -> V_118 , V_6 , V_39 ,
V_365 , V_965 , & V_444 ) ;
if ( V_26 )
goto V_455;
F_149 ( V_37 , V_968 , V_444 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_455:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_202 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_12 V_444 ;
if ( ! V_2 -> V_8 [ V_968 ] )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_969 )
return - V_369 ;
V_444 = F_203 ( V_2 -> V_8 [ V_968 ] ) ;
return V_4 -> V_205 -> V_969 ( & V_4 -> V_118 , V_6 , V_444 ) ;
}
static T_2 F_204 ( struct V_921 * V_922 ,
T_1 * V_796 , T_1 V_970 )
{
T_1 V_117 ;
T_2 V_509 = 0 ;
for ( V_117 = 0 ; V_117 < V_970 ; V_117 ++ ) {
int V_153 = ( V_796 [ V_117 ] & 0x7f ) * 5 ;
int V_971 ;
for ( V_971 = 0 ; V_971 < V_922 -> V_230 ; V_971 ++ ) {
struct V_152 * V_972 =
& V_922 -> V_231 [ V_971 ] ;
if ( V_153 == V_972 -> V_233 ) {
V_509 |= 1 << V_971 ;
break;
}
}
if ( V_971 == V_922 -> V_230 )
return 0 ;
}
return V_509 ;
}
static int F_205 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_7 * V_57 [ V_973 + 1 ] ;
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_974 V_509 ;
int V_96 , V_117 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_7 * V_975 ;
struct V_921 * V_922 ;
if ( V_2 -> V_8 [ V_976 ] == NULL )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_273 )
return - V_369 ;
memset ( & V_509 , 0 , sizeof( V_509 ) ) ;
for ( V_117 = 0 ; V_117 < V_214 ; V_117 ++ ) {
V_922 = V_4 -> V_118 . V_215 [ V_117 ] ;
V_509 . V_977 [ V_117 ] . V_978 =
V_922 ? ( 1 << V_922 -> V_230 ) - 1 : 0 ;
}
F_35 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_150 V_151 = F_138 ( V_975 ) ;
if ( V_151 < 0 || V_151 >= V_214 )
return - V_11 ;
V_922 = V_4 -> V_118 . V_215 [ V_151 ] ;
if ( V_922 == NULL )
return - V_11 ;
F_78 ( V_57 , V_973 , F_19 ( V_975 ) ,
F_20 ( V_975 ) , V_979 ) ;
if ( V_57 [ V_980 ] ) {
V_509 . V_977 [ V_151 ] . V_978 = F_204 (
V_922 ,
F_19 ( V_57 [ V_980 ] ) ,
F_20 ( V_57 [ V_980 ] ) ) ;
if ( V_509 . V_977 [ V_151 ] . V_978 == 0 )
return - V_11 ;
}
}
return V_4 -> V_205 -> V_273 ( & V_4 -> V_118 , V_6 , NULL , & V_509 ) ;
}
static int F_206 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_3 V_981 = V_308 | V_982 ;
if ( ! V_2 -> V_8 [ V_983 ] )
return - V_11 ;
if ( V_2 -> V_8 [ V_307 ] )
V_981 = F_65 ( V_2 -> V_8 [ V_307 ] ) ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_108 &&
V_6 -> V_376 -> V_103 != V_112 &&
V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_105 &&
V_6 -> V_376 -> V_103 != V_107 &&
V_6 -> V_376 -> V_103 != V_106 )
return - V_369 ;
if ( ! V_4 -> V_205 -> V_275 )
return - V_369 ;
return F_207 ( V_6 -> V_376 , V_2 -> V_348 ,
V_981 ,
F_19 ( V_2 -> V_8 [ V_983 ] ) ,
F_20 ( V_2 -> V_8 [ V_983 ] ) ) ;
}
static int F_208 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_38 * V_39 ;
enum V_364 V_365 = V_366 ;
bool V_984 = false ;
T_2 V_367 ;
int V_26 ;
void * V_142 ;
T_12 V_444 ;
struct V_23 * V_37 ;
unsigned int V_985 = 0 ;
bool V_986 ;
bool V_798 ;
if ( ! V_2 -> V_8 [ V_987 ] ||
! V_2 -> V_8 [ V_368 ] )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_275 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_108 &&
V_6 -> V_376 -> V_103 != V_112 &&
V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_105 &&
V_6 -> V_376 -> V_103 != V_107 &&
V_6 -> V_376 -> V_103 != V_106 )
return - V_369 ;
if ( V_2 -> V_8 [ V_966 ] ) {
if ( ! V_4 -> V_205 -> V_277 )
return - V_11 ;
V_985 = F_2 ( V_2 -> V_8 [ V_966 ] ) ;
}
if ( V_2 -> V_8 [ V_370 ] ) {
V_365 = F_2 (
V_2 -> V_8 [ V_370 ] ) ;
if ( V_365 != V_366 &&
V_365 != V_371 &&
V_365 != V_372 &&
V_365 != V_373 )
return - V_11 ;
V_984 = true ;
}
V_986 = V_2 -> V_8 [ V_298 ] ;
V_798 = F_128 ( V_2 -> V_8 [ V_799 ] ) ;
V_367 = F_2 ( V_2 -> V_8 [ V_368 ] ) ;
V_39 = F_201 ( V_4 , V_367 , V_365 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_988 ) ;
if ( F_6 ( V_142 ) ) {
V_26 = F_8 ( V_142 ) ;
goto V_455;
}
V_26 = F_209 ( V_4 , V_6 , V_39 , V_986 , V_365 ,
V_984 , V_985 ,
F_19 ( V_2 -> V_8 [ V_987 ] ) ,
F_20 ( V_2 -> V_8 [ V_987 ] ) ,
V_798 , & V_444 ) ;
if ( V_26 )
goto V_455;
F_149 ( V_37 , V_968 , V_444 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_455:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_210 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_12 V_444 ;
if ( ! V_2 -> V_8 [ V_968 ] )
return - V_11 ;
if ( ! V_4 -> V_205 -> V_277 )
return - V_369 ;
if ( V_6 -> V_376 -> V_103 != V_111 &&
V_6 -> V_376 -> V_103 != V_108 &&
V_6 -> V_376 -> V_103 != V_112 &&
V_6 -> V_376 -> V_103 != V_104 &&
V_6 -> V_376 -> V_103 != V_105 &&
V_6 -> V_376 -> V_103 != V_106 )
return - V_369 ;
V_444 = F_203 ( V_2 -> V_8 [ V_968 ] ) ;
return V_4 -> V_205 -> V_277 ( & V_4 -> V_118 , V_6 , V_444 ) ;
}
static int F_211 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
T_1 V_989 ;
bool V_990 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_991 ] )
return - V_11 ;
V_989 = F_2 ( V_2 -> V_8 [ V_991 ] ) ;
if ( V_989 != V_992 && V_989 != V_993 )
return - V_11 ;
V_102 = V_6 -> V_376 ;
if ( ! V_4 -> V_205 -> V_994 )
return - V_369 ;
V_990 = ( V_989 == V_993 ) ? true : false ;
if ( V_990 == V_102 -> V_995 )
return 0 ;
V_26 = V_4 -> V_205 -> V_994 ( V_102 -> V_118 , V_6 , V_990 ,
V_102 -> V_996 ) ;
if ( ! V_26 )
V_102 -> V_995 = V_990 ;
return V_26 ;
}
static int F_212 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
enum V_997 V_989 ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_23 * V_37 ;
void * V_142 ;
int V_26 ;
V_102 = V_6 -> V_376 ;
if ( ! V_4 -> V_205 -> V_994 )
return - V_369 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_998 ) ;
if ( ! V_142 ) {
V_26 = - V_53 ;
goto V_455;
}
if ( V_102 -> V_995 )
V_989 = V_993 ;
else
V_989 = V_992 ;
F_24 ( V_37 , V_991 , V_989 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_455:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_213 ( struct V_1 * V_2 ,
T_13 V_999 , T_2 V_1000 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
if ( V_999 > 0 )
return - V_11 ;
V_102 = V_6 -> V_376 ;
if ( ! V_4 -> V_205 -> V_1001 )
return - V_369 ;
if ( V_102 -> V_103 != V_111 &&
V_102 -> V_103 != V_112 )
return - V_369 ;
return V_4 -> V_205 -> V_1001 ( V_102 -> V_118 , V_6 ,
V_999 , V_1000 ) ;
}
static int F_214 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_7 * V_8 [ V_1002 + 1 ] ;
struct V_7 * V_1003 ;
int V_26 ;
V_1003 = V_2 -> V_8 [ V_1004 ] ;
if ( ! V_1003 ) {
V_26 = - V_11 ;
goto V_416;
}
V_26 = F_28 ( V_8 , V_1002 , V_1003 ,
V_1005 ) ;
if ( V_26 )
goto V_416;
if ( V_8 [ V_1006 ] &&
V_8 [ V_1007 ] ) {
T_13 V_999 ;
T_2 V_1000 ;
V_999 = F_2 ( V_8 [ V_1006 ] ) ;
V_1000 = F_2 ( V_8 [ V_1007 ] ) ;
V_26 = F_213 ( V_2 , V_999 , V_1000 ) ;
} else
V_26 = - V_11 ;
V_416:
return V_26 ;
}
static int F_215 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_697 V_738 ;
struct V_742 V_743 ;
int V_26 ;
memcpy ( & V_738 , & V_701 , sizeof( V_738 ) ) ;
memcpy ( & V_743 , & V_1008 , sizeof( V_743 ) ) ;
if ( V_2 -> V_8 [ V_703 ] ) {
V_26 = F_125 ( V_2 , & V_738 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_2 -> V_8 [ V_433 ] ||
! F_20 ( V_2 -> V_8 [ V_433 ] ) )
return - V_11 ;
V_743 . V_1009 = F_19 ( V_2 -> V_8 [ V_433 ] ) ;
V_743 . V_700 = F_20 ( V_2 -> V_8 [ V_433 ] ) ;
if ( V_2 -> V_8 [ V_745 ] ) {
V_26 = F_127 ( V_2 , & V_743 ) ;
if ( V_26 )
return V_26 ;
}
return F_216 ( V_4 , V_6 , & V_743 , & V_738 ) ;
}
static int F_217 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
return F_218 ( V_4 , V_6 ) ;
}
static int F_219 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_23 * V_37 ;
void * V_142 ;
if ( ! V_4 -> V_118 . V_311 . V_35 && ! V_4 -> V_118 . V_311 . V_312 )
return - V_369 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_348 , V_2 -> V_349 , 0 ,
V_1010 ) ;
if ( ! V_142 )
goto V_52;
if ( V_4 -> V_311 ) {
struct V_7 * V_313 ;
V_313 = F_41 ( V_37 , V_1011 ) ;
if ( ! V_313 )
goto V_52;
if ( V_4 -> V_311 -> V_1012 )
F_25 ( V_37 , V_316 ) ;
if ( V_4 -> V_311 -> V_294 )
F_25 ( V_37 , V_318 ) ;
if ( V_4 -> V_311 -> V_1013 )
F_25 ( V_37 , V_320 ) ;
if ( V_4 -> V_311 -> V_1014 )
F_25 ( V_37 , V_324 ) ;
if ( V_4 -> V_311 -> V_1015 )
F_25 ( V_37 , V_326 ) ;
if ( V_4 -> V_311 -> V_1016 )
F_25 ( V_37 , V_328 ) ;
if ( V_4 -> V_311 -> V_1017 )
F_25 ( V_37 , V_330 ) ;
if ( V_4 -> V_311 -> V_312 ) {
struct V_7 * V_1018 , * V_1019 ;
int V_117 , V_1020 ;
V_1018 = F_41 ( V_37 ,
V_338 ) ;
if ( ! V_1018 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_4 -> V_311 -> V_312 ; V_117 ++ ) {
V_1019 = F_41 ( V_37 , V_117 + 1 ) ;
if ( ! V_1019 )
goto V_52;
V_1020 = V_4 -> V_311 -> V_1021 [ V_117 ] . V_1022 ;
F_49 ( V_37 , V_1023 ,
F_220 ( V_1020 , 8 ) ,
V_4 -> V_311 -> V_1021 [ V_117 ] . V_509 ) ;
F_49 ( V_37 , V_1024 ,
V_1020 ,
V_4 -> V_311 -> V_1021 [ V_117 ] . V_1025 ) ;
F_42 ( V_37 , V_1019 ) ;
}
F_42 ( V_37 , V_1018 ) ;
}
F_42 ( V_37 , V_313 ) ;
}
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_221 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_7 * V_57 [ V_1026 ] ;
struct V_1027 V_1028 = {} ;
struct V_1027 V_1029 = {} ;
struct V_1030 * V_311 = & V_4 -> V_118 . V_311 ;
int V_26 , V_117 ;
if ( ! V_4 -> V_118 . V_311 . V_35 && ! V_4 -> V_118 . V_311 . V_312 )
return - V_369 ;
if ( ! V_2 -> V_8 [ V_1011 ] )
goto V_1028;
V_26 = F_78 ( V_57 , V_1031 ,
F_19 ( V_2 -> V_8 [ V_1011 ] ) ,
F_20 ( V_2 -> V_8 [ V_1011 ] ) ,
V_1032 ) ;
if ( V_26 )
return V_26 ;
if ( V_57 [ V_316 ] ) {
if ( ! ( V_311 -> V_35 & V_315 ) )
return - V_11 ;
V_1029 . V_1012 = true ;
}
if ( V_57 [ V_318 ] ) {
if ( ! ( V_311 -> V_35 & V_317 ) )
return - V_11 ;
V_1029 . V_294 = true ;
}
if ( V_57 [ V_320 ] ) {
if ( ! ( V_311 -> V_35 & V_319 ) )
return - V_11 ;
V_1029 . V_1013 = true ;
}
if ( V_57 [ V_322 ] )
return - V_11 ;
if ( V_57 [ V_324 ] ) {
if ( ! ( V_311 -> V_35 & V_323 ) )
return - V_11 ;
V_1029 . V_1014 = true ;
}
if ( V_57 [ V_326 ] ) {
if ( ! ( V_311 -> V_35 & V_325 ) )
return - V_11 ;
V_1029 . V_1015 = true ;
}
if ( V_57 [ V_328 ] ) {
if ( ! ( V_311 -> V_35 & V_327 ) )
return - V_11 ;
V_1029 . V_1016 = true ;
}
if ( V_57 [ V_330 ] ) {
if ( ! ( V_311 -> V_35 & V_329 ) )
return - V_11 ;
V_1029 . V_1017 = true ;
}
if ( V_57 [ V_338 ] ) {
struct V_7 * V_332 ;
int V_312 = 0 ;
int V_96 , V_1020 , V_1033 ;
struct V_7 * V_1034 [ V_1035 ] ;
F_35 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_312 ++ ;
if ( V_312 > V_311 -> V_312 )
return - V_11 ;
V_1029 . V_1021 = F_222 ( V_312 ,
sizeof( V_1029 . V_1021 [ 0 ] ) ,
V_97 ) ;
if ( ! V_1029 . V_1021 )
return - V_98 ;
V_1029 . V_312 = V_312 ;
V_117 = 0 ;
F_35 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_78 ( V_1034 , V_1036 ,
F_19 ( V_332 ) , F_20 ( V_332 ) , NULL ) ;
V_26 = - V_11 ;
if ( ! V_1034 [ V_1023 ] ||
! V_1034 [ V_1024 ] )
goto error;
V_1020 = F_20 ( V_1034 [ V_1024 ] ) ;
V_1033 = F_220 ( V_1020 , 8 ) ;
if ( F_20 ( V_1034 [ V_1023 ] ) !=
V_1033 )
goto error;
if ( V_1020 > V_311 -> V_337 ||
V_1020 < V_311 -> V_335 )
goto error;
V_1029 . V_1021 [ V_117 ] . V_509 =
F_223 ( V_1033 + V_1020 , V_97 ) ;
if ( ! V_1029 . V_1021 [ V_117 ] . V_509 ) {
V_26 = - V_98 ;
goto error;
}
V_1029 . V_1021 [ V_117 ] . V_1025 =
V_1029 . V_1021 [ V_117 ] . V_509 + V_1033 ;
memcpy ( V_1029 . V_1021 [ V_117 ] . V_509 ,
F_19 ( V_1034 [ V_1023 ] ) ,
V_1033 ) ;
V_1029 . V_1021 [ V_117 ] . V_1022 = V_1020 ;
memcpy ( V_1029 . V_1021 [ V_117 ] . V_1025 ,
F_19 ( V_1034 [ V_1024 ] ) ,
V_1020 ) ;
V_117 ++ ;
}
}
if ( memcmp ( & V_1029 , & V_1028 , sizeof( V_1029 ) ) ) {
struct V_1027 * V_1037 ;
V_1037 = F_224 ( & V_1029 , sizeof( V_1029 ) ,
V_97 ) ;
if ( ! V_1037 ) {
V_26 = - V_98 ;
goto error;
}
F_225 ( V_4 ) ;
V_4 -> V_311 = V_1037 ;
} else {
V_1028:
F_225 ( V_4 ) ;
V_4 -> V_311 = NULL ;
}
return 0 ;
error:
for ( V_117 = 0 ; V_117 < V_1029 . V_312 ; V_117 ++ )
F_37 ( V_1029 . V_1021 [ V_117 ] . V_509 ) ;
F_37 ( V_1029 . V_1021 ) ;
return V_26 ;
}
static int F_226 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_346 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_346 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_376 ;
struct V_7 * V_57 [ V_1038 ] ;
struct V_1039 V_1040 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_1041 ] )
return - V_11 ;
V_26 = F_78 ( V_57 , V_1042 ,
F_19 ( V_2 -> V_8 [ V_1041 ] ) ,
F_20 ( V_2 -> V_8 [ V_1041 ] ) ,
V_1043 ) ;
if ( V_26 )
return V_26 ;
if ( F_20 ( V_57 [ V_1044 ] ) != V_1045 )
return - V_1046 ;
if ( F_20 ( V_57 [ V_1047 ] ) != V_1048 )
return - V_1046 ;
if ( F_20 ( V_57 [ V_1049 ] ) != V_1050 )
return - V_1046 ;
memcpy ( V_1040 . V_1051 , F_19 ( V_57 [ V_1047 ] ) ,
V_1048 ) ;
memcpy ( V_1040 . V_1052 , F_19 ( V_57 [ V_1049 ] ) ,
V_1050 ) ;
memcpy ( V_1040 . V_1053 ,
F_19 ( V_57 [ V_1044 ] ) ,
V_1045 ) ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_109 ) {
V_26 = - V_1054 ;
goto V_416;
}
if ( ! V_4 -> V_205 -> V_1055 ) {
V_26 = - V_369 ;
goto V_416;
}
V_26 = V_4 -> V_205 -> V_1055 ( & V_4 -> V_118 , V_6 , & V_1040 ) ;
V_416:
F_70 ( V_102 ) ;
return V_26 ;
}
static int F_227 ( struct V_1056 * V_205 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_26 ;
bool V_1057 = V_205 -> V_1058 & V_1059 ;
if ( V_1057 )
F_12 () ;
if ( V_205 -> V_1058 & V_1060 ) {
V_4 = F_228 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
if ( V_1057 )
F_15 () ;
return F_8 ( V_4 ) ;
}
V_2 -> V_346 [ 0 ] = V_4 ;
} else if ( V_205 -> V_1058 & V_1061 ) {
V_26 = F_1 ( V_2 , & V_4 , & V_6 ) ;
if ( V_26 ) {
if ( V_1057 )
F_15 () ;
return V_26 ;
}
if ( V_205 -> V_1058 & V_1062 &&
! F_73 ( V_6 ) ) {
F_17 ( V_4 ) ;
F_7 ( V_6 ) ;
if ( V_1057 )
F_15 () ;
return - V_598 ;
}
V_2 -> V_346 [ 0 ] = V_4 ;
V_2 -> V_346 [ 1 ] = V_6 ;
}
return 0 ;
}
static void F_229 ( struct V_1056 * V_205 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_346 [ 0 ] )
F_17 ( V_2 -> V_346 [ 0 ] ) ;
if ( V_2 -> V_346 [ 1 ] )
F_7 ( V_2 -> V_346 [ 1 ] ) ;
if ( V_205 -> V_1058 & V_1059 )
F_15 () ;
}
void F_230 ( struct V_3 * V_4 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_44 ( V_37 , 0 , 0 , 0 , V_4 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1063 . V_943 , V_97 ) ;
}
static int F_232 ( struct V_23 * V_37 ,
struct V_3 * V_4 )
{
struct V_786 * V_1064 = V_4 -> V_791 ;
struct V_7 * V_1065 ;
int V_117 ;
F_233 ( V_4 ) ;
if ( F_100 ( ! V_1064 ) )
return 0 ;
V_1065 = F_41 ( V_37 , V_793 ) ;
if ( ! V_1065 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_1064 -> V_789 ; V_117 ++ )
F_49 ( V_37 , V_117 , V_1064 -> V_794 [ V_117 ] . V_476 , V_1064 -> V_794 [ V_117 ] . V_437 ) ;
F_42 ( V_37 , V_1065 ) ;
V_1065 = F_41 ( V_37 , V_792 ) ;
if ( ! V_1065 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_1064 -> V_227 ; V_117 ++ )
F_24 ( V_37 , V_117 , V_1064 -> V_228 [ V_117 ] -> V_41 ) ;
F_42 ( V_37 , V_1065 ) ;
if ( V_1064 -> V_757 )
F_49 ( V_37 , V_465 , V_1064 -> V_758 , V_1064 -> V_757 ) ;
return 0 ;
V_52:
return - V_53 ;
}
static int F_234 ( struct V_23 * V_37 ,
struct V_3 * V_4 ,
struct V_5 * V_375 ,
T_2 V_33 , T_2 V_34 , int V_35 ,
T_2 V_36 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_232 ( V_37 , V_4 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
static int
F_235 ( struct V_23 * V_37 ,
struct V_3 * V_4 ,
struct V_5 * V_375 ,
T_2 V_33 , T_2 V_34 , int V_35 , T_2 V_36 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_341 ;
}
void F_140 ( struct V_3 * V_4 ,
struct V_5 * V_375 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1066 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_234 ( V_37 , V_4 , V_375 , 0 , 0 , 0 ,
V_1067 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1068 . V_943 , V_97 ) ;
}
void F_236 ( struct V_3 * V_4 ,
struct V_5 * V_375 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_234 ( V_37 , V_4 , V_375 , 0 , 0 , 0 ,
V_817 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1068 . V_943 , V_97 ) ;
}
void F_237 ( struct V_3 * V_4 ,
struct V_5 * V_375 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_234 ( V_37 , V_4 , V_375 , 0 , 0 , 0 ,
V_1069 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1068 . V_943 , V_97 ) ;
}
void F_238 ( struct V_3 * V_4 ,
struct V_5 * V_375 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_235 ( V_37 , V_4 , V_375 , 0 , 0 , 0 ,
V_1070 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1068 . V_943 , V_97 ) ;
}
void F_143 ( struct V_3 * V_4 ,
struct V_5 * V_375 , T_2 V_36 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1066 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_235 ( V_37 , V_4 , V_375 , 0 , 0 , 0 , V_36 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1068 . V_943 , V_97 ) ;
}
void F_239 ( struct V_1071 * V_787 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_97 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1072 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_47 ( V_37 , V_1073 , V_787 -> V_1074 ) ;
if ( V_787 -> V_766 [ 0 ] == '0' && V_787 -> V_766 [ 1 ] == '0' )
F_47 ( V_37 , V_1075 ,
V_1076 ) ;
else if ( V_787 -> V_766 [ 0 ] == '9' && V_787 -> V_766 [ 1 ] == '9' )
F_47 ( V_37 , V_1075 ,
V_1077 ) ;
else if ( ( V_787 -> V_766 [ 0 ] == '9' && V_787 -> V_766 [ 1 ] == '8' ) ||
V_787 -> V_1078 )
F_47 ( V_37 , V_1075 ,
V_1079 ) ;
else {
F_47 ( V_37 , V_1075 ,
V_1080 ) ;
F_45 ( V_37 , V_696 , V_787 -> V_766 ) ;
}
if ( F_240 ( V_787 -> V_158 ) )
F_24 ( V_37 , V_157 , V_787 -> V_158 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_241 () ;
F_242 ( V_37 , 0 , V_1081 . V_943 ,
V_1082 ) ;
F_243 () ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static void F_244 ( struct V_3 * V_4 ,
struct V_5 * V_375 ,
const T_1 * V_1083 , T_10 V_31 ,
enum V_1084 V_36 , T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_49 ( V_37 , V_987 , V_31 , V_1083 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_245 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1083 ,
T_10 V_31 , T_11 V_941 )
{
F_244 ( V_4 , V_375 , V_1083 , V_31 ,
V_1086 , V_941 ) ;
}
void F_246 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1083 ,
T_10 V_31 , T_11 V_941 )
{
F_244 ( V_4 , V_375 , V_1083 , V_31 ,
V_1087 , V_941 ) ;
}
void F_247 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1083 ,
T_10 V_31 , T_11 V_941 )
{
F_244 ( V_4 , V_375 , V_1083 , V_31 ,
V_1088 , V_941 ) ;
}
void F_248 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1083 ,
T_10 V_31 , T_11 V_941 )
{
F_244 ( V_4 , V_375 , V_1083 , V_31 ,
V_1089 , V_941 ) ;
}
void F_249 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1083 ,
T_10 V_31 , T_11 V_941 )
{
F_244 ( V_4 , V_375 , V_1083 , V_31 ,
V_1090 , V_941 ) ;
}
void F_250 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1083 ,
T_10 V_31 , T_11 V_941 )
{
F_244 ( V_4 , V_375 , V_1083 , V_31 ,
V_1091 , V_941 ) ;
}
static void F_251 ( struct V_3 * V_4 ,
struct V_5 * V_375 , int V_36 ,
const T_1 * V_1092 , T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_25 ( V_37 , V_1093 ) ;
F_49 ( V_37 , V_378 , V_453 , V_1092 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_252 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1092 ,
T_11 V_941 )
{
F_251 ( V_4 , V_375 , V_1086 ,
V_1092 , V_941 ) ;
}
void F_253 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1092 ,
T_11 V_941 )
{
F_251 ( V_4 , V_375 , V_1087 ,
V_1092 , V_941 ) ;
}
void F_254 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_377 ,
const T_1 * V_1094 , T_10 V_1095 ,
const T_1 * V_1096 , T_10 V_1097 ,
T_3 V_1098 , T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_293 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
if ( V_377 )
F_49 ( V_37 , V_378 , V_453 , V_377 ) ;
F_48 ( V_37 , V_960 , V_1098 ) ;
if ( V_1094 )
F_49 ( V_37 , V_1099 , V_1095 , V_1094 ) ;
if ( V_1096 )
F_49 ( V_37 , V_1100 , V_1097 , V_1096 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_255 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_377 ,
const T_1 * V_1094 , T_10 V_1095 ,
const T_1 * V_1096 , T_10 V_1097 , T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1101 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_377 ) ;
if ( V_1094 )
F_49 ( V_37 , V_1099 , V_1095 , V_1094 ) ;
if ( V_1096 )
F_49 ( V_37 , V_1100 , V_1097 , V_1096 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_256 ( struct V_3 * V_4 ,
struct V_5 * V_375 , T_3 V_945 ,
const T_1 * V_757 , T_10 V_758 , bool V_1102 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_97 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_295 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
if ( V_1102 && V_945 )
F_48 ( V_37 , V_917 , V_945 ) ;
if ( V_1102 )
F_25 ( V_37 , V_1103 ) ;
if ( V_757 )
F_49 ( V_37 , V_465 , V_758 , V_757 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_97 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_257 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_377 ,
T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1104 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_377 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_258 ( struct V_3 * V_4 ,
struct V_5 * V_375 ,
const T_1 * V_1105 , const T_1 * V_757 , T_1 V_758 ,
T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1106 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_1105 ) ;
if ( V_758 && V_757 )
F_49 ( V_37 , V_465 , V_758 , V_757 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_259 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_1092 ,
enum V_1107 V_1108 , int V_1109 ,
const T_1 * V_1110 , T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1111 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
if ( V_1092 )
F_49 ( V_37 , V_378 , V_453 , V_1092 ) ;
F_24 ( V_37 , V_89 , V_1108 ) ;
if ( V_1109 != - 1 )
F_47 ( V_37 , V_85 , V_1109 ) ;
if ( V_1110 )
F_49 ( V_37 , V_84 , 6 , V_1110 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_260 ( struct V_118 * V_118 ,
struct V_38 * V_1112 ,
struct V_38 * V_1113 )
{
struct V_23 * V_37 ;
void * V_142 ;
struct V_7 * V_146 ;
V_37 = F_61 ( V_347 , V_1082 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1114 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , F_261 ( V_118 ) ) ;
V_146 = F_41 ( V_37 , V_1115 ) ;
if ( ! V_146 )
goto V_52;
if ( F_23 ( V_37 , V_1112 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
V_146 = F_41 ( V_37 , V_1116 ) ;
if ( ! V_146 )
goto V_52;
if ( F_23 ( V_37 , V_1113 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_241 () ;
F_242 ( V_37 , 0 , V_1081 . V_943 ,
V_1082 ) ;
F_243 () ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static void F_262 (
int V_36 , struct V_3 * V_4 ,
struct V_5 * V_375 , T_12 V_444 ,
struct V_38 * V_39 ,
enum V_364 V_365 ,
unsigned int V_965 , T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_24 ( V_37 , V_368 , V_39 -> V_41 ) ;
F_24 ( V_37 , V_370 , V_365 ) ;
F_149 ( V_37 , V_968 , V_444 ) ;
if ( V_36 == V_967 )
F_24 ( V_37 , V_966 , V_965 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_263 ( struct V_3 * V_4 ,
struct V_5 * V_375 , T_12 V_444 ,
struct V_38 * V_39 ,
enum V_364 V_365 ,
unsigned int V_965 , T_11 V_941 )
{
F_262 ( V_967 ,
V_4 , V_375 , V_444 , V_39 ,
V_365 , V_965 , V_941 ) ;
}
void F_264 (
struct V_3 * V_4 , struct V_5 * V_375 ,
T_12 V_444 , struct V_38 * V_39 ,
enum V_364 V_365 , T_11 V_941 )
{
F_262 ( V_1117 ,
V_4 , V_375 , V_444 , V_39 ,
V_365 , 0 , V_941 ) ;
}
void F_265 ( struct V_3 * V_4 ,
struct V_5 * V_6 , const T_1 * V_446 ,
struct V_524 * V_525 , T_11 V_941 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
if ( F_106 ( V_37 , 0 , 0 , 0 , V_6 , V_446 , V_525 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
}
void F_266 ( struct V_3 * V_4 ,
struct V_5 * V_6 , const T_1 * V_446 ,
T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1118 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_446 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
int F_267 ( struct V_3 * V_4 ,
struct V_5 * V_375 , T_2 V_1119 ,
int V_367 , const T_1 * V_1083 , T_10 V_31 , T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
int V_26 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_988 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return - V_98 ;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_24 ( V_37 , V_368 , V_367 ) ;
F_49 ( V_37 , V_987 , V_31 , V_1083 ) ;
V_26 = F_51 ( V_37 , V_142 ) ;
if ( V_26 < 0 ) {
F_62 ( V_37 ) ;
return V_26 ;
}
V_26 = F_268 ( F_57 ( & V_4 -> V_118 ) , V_37 , V_1119 ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
return - V_53 ;
}
void F_269 ( struct V_3 * V_4 ,
struct V_5 * V_375 , T_12 V_444 ,
const T_1 * V_1083 , T_10 V_31 , bool V_1120 ,
T_11 V_941 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_347 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1121 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_49 ( V_37 , V_987 , V_31 , V_1083 ) ;
F_149 ( V_37 , V_968 , V_444 ) ;
if ( V_1120 )
F_25 ( V_37 , V_1122 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_185 ( V_37 , 0 , V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void
F_270 ( struct V_3 * V_4 ,
struct V_5 * V_375 ,
enum V_1123 V_1124 ,
T_11 V_941 )
{
struct V_23 * V_37 ;
struct V_7 * V_634 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1125 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
V_634 = F_41 ( V_37 , V_1004 ) ;
if ( ! V_634 )
goto V_52;
F_24 ( V_37 , V_1126 ,
V_1124 ) ;
F_42 ( V_37 , V_634 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_271 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_377 ,
const T_1 * V_1053 , T_11 V_941 )
{
struct V_23 * V_37 ;
struct V_7 * V_1127 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1128 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_377 ) ;
V_1127 = F_41 ( V_37 , V_1041 ) ;
if ( ! V_1127 )
goto V_52;
F_49 ( V_37 , V_1044 ,
V_1045 , V_1053 ) ;
F_42 ( V_37 , V_1127 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_272 ( struct V_3 * V_4 ,
struct V_5 * V_375 , int V_1129 ,
const T_1 * V_377 , bool V_1130 , T_11 V_941 )
{
struct V_23 * V_37 ;
struct V_7 * V_29 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1131 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
V_29 = F_41 ( V_37 , V_1132 ) ;
if ( ! V_29 )
goto V_52;
F_24 ( V_37 , V_1133 , V_1129 ) ;
F_49 ( V_37 , V_1134 , V_453 , V_377 ) ;
if ( V_1130 )
F_25 ( V_37 , V_1135 ) ;
F_42 ( V_37 , V_29 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void
F_273 ( struct V_3 * V_4 ,
struct V_5 * V_375 , const T_1 * V_958 ,
T_2 V_1136 , T_11 V_941 )
{
struct V_23 * V_37 ;
struct V_7 * V_634 ;
void * V_142 ;
V_37 = F_61 ( V_1066 , V_941 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1125 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_375 -> V_9 ) ;
F_49 ( V_37 , V_378 , V_453 , V_958 ) ;
V_634 = F_41 ( V_37 , V_1004 ) ;
if ( ! V_634 )
goto V_52;
F_24 ( V_37 , V_1137 , V_1136 ) ;
F_42 ( V_37 , V_634 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_231 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1085 . V_943 , V_941 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static int F_274 ( struct V_1138 * V_1139 ,
unsigned long V_990 ,
void * V_1140 )
{
struct V_1141 * V_1142 = V_1140 ;
struct V_3 * V_4 ;
struct V_101 * V_102 ;
if ( V_990 != V_1143 )
return V_1144 ;
F_241 () ;
F_275 (rdev, &cfg80211_rdev_list, list)
F_275 (wdev, &rdev->netdev_list, list)
F_276 ( V_102 , V_1142 -> V_33 ) ;
F_243 () ;
return V_1144 ;
}
int F_277 ( void )
{
int V_26 ;
V_26 = F_278 ( & V_18 ,
V_1145 , F_279 ( V_1145 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_280 ( & V_18 , & V_1063 ) ;
if ( V_26 )
goto V_1146;
V_26 = F_280 ( & V_18 , & V_1068 ) ;
if ( V_26 )
goto V_1146;
V_26 = F_280 ( & V_18 , & V_1081 ) ;
if ( V_26 )
goto V_1146;
V_26 = F_280 ( & V_18 , & V_1085 ) ;
if ( V_26 )
goto V_1146;
#ifdef F_281
V_26 = F_280 ( & V_18 , & V_942 ) ;
if ( V_26 )
goto V_1146;
#endif
V_26 = F_282 ( & V_1147 ) ;
if ( V_26 )
goto V_1146;
return 0 ;
V_1146:
F_283 ( & V_18 ) ;
return V_26 ;
}
void F_284 ( void )
{
F_285 ( & V_1147 ) ;
F_283 ( & V_18 ) ;
}
