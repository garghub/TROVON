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
if ( V_6 -> V_118 . V_35 & V_180 )
F_25 ( V_37 , V_181 ) ;
if ( V_6 -> V_118 . V_35 & V_182 )
F_25 ( V_37 , V_183 ) ;
F_49 ( V_37 , V_184 ,
sizeof( T_2 ) * V_6 -> V_118 . V_185 ,
V_6 -> V_118 . V_186 ) ;
F_47 ( V_37 , V_187 ,
V_6 -> V_118 . V_188 ) ;
if ( V_6 -> V_118 . V_35 & V_189 )
F_25 ( V_37 , V_190 ) ;
F_24 ( V_37 , V_191 ,
V_6 -> V_118 . V_192 ) ;
F_24 ( V_37 , V_193 ,
V_6 -> V_118 . V_194 ) ;
if ( ( V_6 -> V_118 . V_192 ||
V_6 -> V_118 . V_194 ) && V_6 -> V_195 -> V_196 ) {
T_2 V_197 = 0 , V_198 = 0 ;
int V_15 ;
V_15 = V_6 -> V_195 -> V_196 ( & V_6 -> V_118 , & V_197 , & V_198 ) ;
if ( ! V_15 ) {
F_24 ( V_37 , V_199 , V_197 ) ;
F_24 ( V_37 , V_200 , V_198 ) ;
}
}
if ( F_40 ( V_37 , V_201 ,
V_6 -> V_118 . V_202 ) )
goto V_52;
V_143 = F_41 ( V_37 , V_203 ) ;
if ( ! V_143 )
goto V_52;
for ( V_151 = 0 ; V_151 < V_204 ; V_151 ++ ) {
if ( ! V_6 -> V_118 . V_205 [ V_151 ] )
continue;
V_144 = F_41 ( V_37 , V_151 ) ;
if ( ! V_144 )
goto V_52;
if ( V_6 -> V_118 . V_205 [ V_151 ] -> V_206 . V_207 ) {
F_49 ( V_37 , V_208 ,
sizeof( V_6 -> V_118 . V_205 [ V_151 ] -> V_206 . V_209 ) ,
& V_6 -> V_118 . V_205 [ V_151 ] -> V_206 . V_209 ) ;
F_48 ( V_37 , V_210 ,
V_6 -> V_118 . V_205 [ V_151 ] -> V_206 . V_211 ) ;
F_47 ( V_37 , V_212 ,
V_6 -> V_118 . V_205 [ V_151 ] -> V_206 . V_213 ) ;
F_47 ( V_37 , V_214 ,
V_6 -> V_118 . V_205 [ V_151 ] -> V_206 . V_215 ) ;
}
V_145 = F_41 ( V_37 , V_216 ) ;
if ( ! V_145 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_6 -> V_118 . V_205 [ V_151 ] -> V_217 ; V_117 ++ ) {
V_146 = F_41 ( V_37 , V_117 ) ;
if ( ! V_146 )
goto V_52;
V_39 = & V_6 -> V_118 . V_205 [ V_151 ] -> V_218 [ V_117 ] ;
if ( F_23 ( V_37 , V_39 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
}
F_42 ( V_37 , V_145 ) ;
V_147 = F_41 ( V_37 , V_219 ) ;
if ( ! V_147 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_6 -> V_118 . V_205 [ V_151 ] -> V_220 ; V_117 ++ ) {
V_148 = F_41 ( V_37 , V_117 ) ;
if ( ! V_148 )
goto V_52;
V_153 = & V_6 -> V_118 . V_205 [ V_151 ] -> V_221 [ V_117 ] ;
F_24 ( V_37 , V_222 ,
V_153 -> V_223 ) ;
if ( V_153 -> V_35 & V_224 )
F_25 ( V_37 ,
V_225 ) ;
F_42 ( V_37 , V_148 ) ;
}
F_42 ( V_37 , V_147 ) ;
F_42 ( V_37 , V_144 ) ;
}
F_42 ( V_37 , V_143 ) ;
V_149 = F_41 ( V_37 , V_226 ) ;
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
F_50 ( V_227 , V_228 ) ;
F_50 ( V_229 , V_230 ) ;
F_50 ( V_231 , V_232 ) ;
F_50 ( V_233 , V_234 ) ;
F_50 ( V_235 , V_236 ) ;
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
if ( V_6 -> V_118 . V_35 & V_269 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_270 ) ;
}
F_50 ( V_271 , V_272 ) ;
F_50 ( V_273 , V_274 ) ;
if ( V_6 -> V_118 . V_35 & V_275 )
F_50 ( V_276 , V_277 ) ;
#undef F_50
if ( V_6 -> V_195 -> V_278 || V_6 -> V_195 -> V_243 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_279 ) ;
}
if ( V_6 -> V_195 -> V_280 || V_6 -> V_195 -> V_247 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_281 ) ;
}
F_42 ( V_37 , V_149 ) ;
if ( V_6 -> V_195 -> V_261 )
F_24 ( V_37 , V_282 ,
V_6 -> V_118 . V_283 ) ;
if ( V_6 -> V_195 -> V_265 )
F_25 ( V_37 , V_284 ) ;
if ( V_155 ) {
T_3 V_285 ;
struct V_7 * V_286 , * V_287 ;
enum V_288 V_289 ;
V_287 = F_41 ( V_37 , V_290 ) ;
if ( ! V_287 )
goto V_52;
for ( V_289 = 0 ; V_289 < V_291 ; V_289 ++ ) {
V_286 = F_41 ( V_37 , V_289 ) ;
if ( ! V_286 )
goto V_52;
V_117 = 0 ;
V_285 = V_155 [ V_289 ] . V_292 ;
while ( V_285 ) {
if ( V_285 & 1 )
F_48 ( V_37 , V_293 ,
( V_117 << 4 ) | V_294 ) ;
V_285 >>= 1 ;
V_117 ++ ;
}
F_42 ( V_37 , V_286 ) ;
}
F_42 ( V_37 , V_287 ) ;
V_287 = F_41 ( V_37 , V_295 ) ;
if ( ! V_287 )
goto V_52;
for ( V_289 = 0 ; V_289 < V_291 ; V_289 ++ ) {
V_286 = F_41 ( V_37 , V_289 ) ;
if ( ! V_286 )
goto V_52;
V_117 = 0 ;
V_285 = V_155 [ V_289 ] . V_296 ;
while ( V_285 ) {
if ( V_285 & 1 )
F_48 ( V_37 , V_293 ,
( V_117 << 4 ) | V_294 ) ;
V_285 >>= 1 ;
V_117 ++ ;
}
F_42 ( V_37 , V_286 ) ;
}
F_42 ( V_37 , V_287 ) ;
}
if ( V_6 -> V_118 . V_297 . V_35 || V_6 -> V_118 . V_297 . V_298 ) {
struct V_7 * V_299 ;
V_299 = F_41 ( V_37 ,
V_300 ) ;
if ( ! V_299 )
goto V_52;
if ( V_6 -> V_118 . V_297 . V_35 & V_301 )
F_25 ( V_37 , V_302 ) ;
if ( V_6 -> V_118 . V_297 . V_35 & V_303 )
F_25 ( V_37 , V_304 ) ;
if ( V_6 -> V_118 . V_297 . V_35 & V_305 )
F_25 ( V_37 , V_306 ) ;
if ( V_6 -> V_118 . V_297 . V_35 & V_307 )
F_25 ( V_37 , V_308 ) ;
if ( V_6 -> V_118 . V_297 . V_35 & V_309 )
F_25 ( V_37 , V_310 ) ;
if ( V_6 -> V_118 . V_297 . V_35 & V_311 )
F_25 ( V_37 , V_312 ) ;
if ( V_6 -> V_118 . V_297 . V_35 & V_313 )
F_25 ( V_37 , V_314 ) ;
if ( V_6 -> V_118 . V_297 . V_35 & V_315 )
F_25 ( V_37 , V_316 ) ;
if ( V_6 -> V_118 . V_297 . V_298 ) {
struct V_317 V_318 = {
. V_319 = V_6 -> V_118 . V_297 . V_298 ,
. V_320 =
V_6 -> V_118 . V_297 . V_321 ,
. V_322 =
V_6 -> V_118 . V_297 . V_323 ,
} ;
F_49 ( V_37 , V_324 ,
sizeof( V_318 ) , & V_318 ) ;
}
F_42 ( V_37 , V_299 ) ;
}
if ( F_40 ( V_37 , V_325 ,
V_6 -> V_118 . V_326 ) )
goto V_52;
if ( F_43 ( & V_6 -> V_118 , V_37 ) )
goto V_52;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
static int F_53 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_67 = 0 ;
int V_328 = V_14 -> args [ 0 ] ;
struct V_3 * V_6 ;
F_54 ( & V_329 ) ;
F_55 (dev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_6 -> V_118 ) , F_14 ( V_24 -> V_27 ) ) )
continue;
if ( ++ V_67 <= V_328 )
continue;
if ( F_44 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_330 , V_331 ,
V_6 ) < 0 ) {
V_67 -- ;
break;
}
}
F_59 ( & V_329 ) ;
V_14 -> args [ 0 ] = V_67 ;
return V_24 -> V_31 ;
}
static int F_60 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
struct V_3 * V_6 = V_2 -> V_332 [ 0 ] ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_44 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 , V_6 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_64 ( struct V_7 * V_57 [] ,
struct V_336 * V_337 )
{
if ( ! V_57 [ V_338 ] || ! V_57 [ V_339 ] ||
! V_57 [ V_340 ] || ! V_57 [ V_341 ] ||
! V_57 [ V_342 ] )
return - V_11 ;
V_337 -> V_343 = F_29 ( V_57 [ V_338 ] ) ;
V_337 -> V_344 = F_65 ( V_57 [ V_339 ] ) ;
V_337 -> V_345 = F_65 ( V_57 [ V_340 ] ) ;
V_337 -> V_346 = F_65 ( V_57 [ V_341 ] ) ;
V_337 -> V_347 = F_29 ( V_57 [ V_342 ] ) ;
return 0 ;
}
static bool F_66 ( struct V_101 * V_102 )
{
return ! V_102 ||
V_102 -> V_103 == V_104 ||
V_102 -> V_103 == V_348 ||
V_102 -> V_103 == V_107 ||
V_102 -> V_103 == V_349 ||
V_102 -> V_103 == V_106 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_1 * V_2 )
{
enum V_350 V_351 = V_352 ;
T_2 V_353 ;
int V_95 ;
if ( ! V_2 -> V_8 [ V_354 ] )
return - V_11 ;
if ( ! F_66 ( V_102 ) )
return - V_355 ;
if ( V_2 -> V_8 [ V_356 ] ) {
V_351 = F_2 ( V_2 -> V_8 [
V_356 ] ) ;
if ( V_351 != V_352 &&
V_351 != V_357 &&
V_351 != V_358 &&
V_351 != V_359 )
return - V_11 ;
}
V_353 = F_2 ( V_2 -> V_8 [ V_354 ] ) ;
F_54 ( & V_4 -> V_360 ) ;
if ( V_102 ) {
F_68 ( V_102 ) ;
V_95 = F_69 ( V_4 , V_102 , V_353 , V_351 ) ;
F_70 ( V_102 ) ;
} else {
V_95 = F_69 ( V_4 , NULL , V_353 , V_351 ) ;
}
F_59 ( & V_4 -> V_360 ) ;
return V_95 ;
}
static int F_71 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_361 = V_2 -> V_332 [ 1 ] ;
return F_67 ( V_4 , V_361 -> V_362 , V_2 ) ;
}
static int F_72 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_362 ;
const T_1 * V_363 ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( F_73 ( V_6 ) )
return - V_365 ;
if ( ! V_4 -> V_195 -> V_273 )
return - V_355 ;
if ( V_102 -> V_103 != V_348 )
return - V_355 ;
V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
return V_4 -> V_195 -> V_273 ( V_102 -> V_118 , V_6 , V_363 ) ;
}
static int F_74 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_361 = NULL ;
struct V_101 * V_102 ;
int V_95 = 0 , V_366 = 0 ;
struct V_7 * V_367 ;
T_2 V_368 ;
T_1 V_163 = 0 , V_165 = 0 ;
T_2 V_167 = 0 , V_169 = 0 ;
T_1 V_171 = 0 ;
F_54 ( & V_329 ) ;
if ( V_2 -> V_8 [ V_10 ] ) {
int V_9 = F_2 ( V_2 -> V_8 [ V_10 ] ) ;
V_361 = F_3 ( F_4 ( V_2 ) , V_9 ) ;
if ( V_361 && V_361 -> V_362 ) {
V_4 = F_75 ( V_361 -> V_362 -> V_118 ) ;
F_54 ( & V_4 -> V_369 ) ;
} else
V_361 = NULL ;
}
if ( ! V_361 ) {
V_4 = F_76 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_59 ( & V_329 ) ;
return F_8 ( V_4 ) ;
}
V_102 = NULL ;
V_361 = NULL ;
V_95 = 0 ;
F_54 ( & V_4 -> V_369 ) ;
} else if ( F_73 ( V_361 ) &&
F_66 ( V_361 -> V_362 ) )
V_102 = V_361 -> V_362 ;
else
V_102 = NULL ;
if ( V_2 -> V_8 [ V_159 ] )
V_95 = F_77 (
V_4 , F_19 ( V_2 -> V_8 [ V_159 ] ) ) ;
F_59 ( & V_329 ) ;
if ( V_95 )
goto V_370;
if ( V_2 -> V_8 [ V_371 ] ) {
struct V_336 V_337 ;
struct V_7 * V_57 [ V_372 + 1 ] ;
if ( ! V_4 -> V_195 -> V_373 ) {
V_95 = - V_355 ;
goto V_370;
}
F_35 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_78 ( V_57 , V_372 ,
F_19 ( V_367 ) ,
F_20 ( V_367 ) ,
V_374 ) ;
V_95 = F_64 ( V_57 , & V_337 ) ;
if ( V_95 )
goto V_370;
V_95 = V_4 -> V_195 -> V_373 ( & V_4 -> V_118 ,
& V_337 ) ;
if ( V_95 )
goto V_370;
}
}
if ( V_2 -> V_8 [ V_354 ] ) {
V_95 = F_67 ( V_4 , V_102 , V_2 ) ;
if ( V_95 )
goto V_370;
}
if ( V_2 -> V_8 [ V_375 ] ) {
enum V_376 type ;
int V_67 , V_377 = 0 ;
if ( ! V_4 -> V_195 -> V_378 ) {
V_95 = - V_355 ;
goto V_370;
}
V_67 = V_375 ;
type = F_2 ( V_2 -> V_8 [ V_67 ] ) ;
if ( ! V_2 -> V_8 [ V_379 ] &&
( type != V_380 ) ) {
V_95 = - V_11 ;
goto V_370;
}
if ( type != V_380 ) {
V_67 = V_379 ;
V_377 = F_2 ( V_2 -> V_8 [ V_67 ] ) ;
}
V_95 = V_4 -> V_195 -> V_378 ( & V_4 -> V_118 , type , V_377 ) ;
if ( V_95 )
goto V_370;
}
if ( V_2 -> V_8 [ V_199 ] &&
V_2 -> V_8 [ V_200 ] ) {
T_2 V_197 , V_198 ;
if ( ( ! V_4 -> V_118 . V_192 &&
! V_4 -> V_118 . V_194 ) ||
! V_4 -> V_195 -> V_381 ) {
V_95 = - V_355 ;
goto V_370;
}
V_197 = F_2 ( V_2 -> V_8 [ V_199 ] ) ;
V_198 = F_2 ( V_2 -> V_8 [ V_200 ] ) ;
if ( ( ~ V_197 && ( V_197 & ~ V_4 -> V_118 . V_192 ) ) ||
( ~ V_198 && ( V_198 & ~ V_4 -> V_118 . V_194 ) ) ) {
V_95 = - V_11 ;
goto V_370;
}
V_197 = V_197 & V_4 -> V_118 . V_192 ;
V_198 = V_198 & V_4 -> V_118 . V_194 ;
V_95 = V_4 -> V_195 -> V_381 ( & V_4 -> V_118 , V_197 , V_198 ) ;
if ( V_95 )
goto V_370;
}
V_368 = 0 ;
if ( V_2 -> V_8 [ V_162 ] ) {
V_163 = F_29 (
V_2 -> V_8 [ V_162 ] ) ;
if ( V_163 == 0 ) {
V_95 = - V_11 ;
goto V_370;
}
V_368 |= V_382 ;
}
if ( V_2 -> V_8 [ V_164 ] ) {
V_165 = F_29 (
V_2 -> V_8 [ V_164 ] ) ;
if ( V_165 == 0 ) {
V_95 = - V_11 ;
goto V_370;
}
V_368 |= V_383 ;
}
if ( V_2 -> V_8 [ V_166 ] ) {
V_167 = F_2 (
V_2 -> V_8 [ V_166 ] ) ;
if ( V_167 < 256 ) {
V_95 = - V_11 ;
goto V_370;
}
if ( V_167 != ( T_2 ) - 1 ) {
V_167 &= ~ 0x1 ;
}
V_368 |= V_384 ;
}
if ( V_2 -> V_8 [ V_168 ] ) {
V_169 = F_2 (
V_2 -> V_8 [ V_168 ] ) ;
V_368 |= V_385 ;
}
if ( V_2 -> V_8 [ V_170 ] ) {
V_171 = F_29 (
V_2 -> V_8 [ V_170 ] ) ;
V_368 |= V_386 ;
}
if ( V_368 ) {
T_1 V_387 , V_388 ;
T_2 V_389 , V_390 ;
T_1 V_391 ;
if ( ! V_4 -> V_195 -> V_392 ) {
V_95 = - V_355 ;
goto V_370;
}
V_387 = V_4 -> V_118 . V_163 ;
V_388 = V_4 -> V_118 . V_165 ;
V_389 = V_4 -> V_118 . V_167 ;
V_390 = V_4 -> V_118 . V_169 ;
V_391 = V_4 -> V_118 . V_171 ;
if ( V_368 & V_382 )
V_4 -> V_118 . V_163 = V_163 ;
if ( V_368 & V_383 )
V_4 -> V_118 . V_165 = V_165 ;
if ( V_368 & V_384 )
V_4 -> V_118 . V_167 = V_167 ;
if ( V_368 & V_385 )
V_4 -> V_118 . V_169 = V_169 ;
if ( V_368 & V_386 )
V_4 -> V_118 . V_171 = V_171 ;
V_95 = V_4 -> V_195 -> V_392 ( & V_4 -> V_118 , V_368 ) ;
if ( V_95 ) {
V_4 -> V_118 . V_163 = V_387 ;
V_4 -> V_118 . V_165 = V_388 ;
V_4 -> V_118 . V_167 = V_389 ;
V_4 -> V_118 . V_169 = V_390 ;
V_4 -> V_118 . V_171 = V_391 ;
}
}
V_370:
F_59 ( & V_4 -> V_369 ) ;
if ( V_361 )
F_7 ( V_361 ) ;
return V_95 ;
}
static int F_79 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 , int V_35 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_393 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_45 ( V_37 , V_394 , V_6 -> V_395 ) ;
F_24 ( V_37 , V_396 , V_6 -> V_362 -> V_103 ) ;
F_24 ( V_37 , V_160 ,
V_4 -> V_397 ^
( V_161 << 2 ) ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
static int F_80 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_398 = 0 ;
int V_399 = 0 ;
int V_400 = V_14 -> args [ 0 ] ;
int V_401 = V_14 -> args [ 1 ] ;
struct V_3 * V_4 ;
struct V_101 * V_102 ;
F_54 ( & V_329 ) ;
F_55 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_4 -> V_118 ) , F_14 ( V_24 -> V_27 ) ) )
continue;
if ( V_398 < V_400 ) {
V_398 ++ ;
continue;
}
V_399 = 0 ;
F_54 ( & V_4 -> V_360 ) ;
F_55 (wdev, &rdev->netdev_list, list) {
if ( V_399 < V_401 ) {
V_399 ++ ;
continue;
}
if ( F_79 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_330 , V_331 ,
V_4 , V_102 -> V_361 ) < 0 ) {
F_59 ( & V_4 -> V_360 ) ;
goto V_402;
}
V_399 ++ ;
}
F_59 ( & V_4 -> V_360 ) ;
V_398 ++ ;
}
V_402:
F_59 ( & V_329 ) ;
V_14 -> args [ 0 ] = V_398 ;
V_14 -> args [ 1 ] = V_399 ;
return V_24 -> V_31 ;
}
static int F_81 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
struct V_3 * V_6 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_361 = V_2 -> V_332 [ 1 ] ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_79 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_6 , V_361 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_82 ( struct V_7 * V_403 , T_2 * V_404 )
{
struct V_7 * V_35 [ V_405 + 1 ] ;
int V_406 ;
* V_404 = 0 ;
if ( ! V_403 )
return - V_11 ;
if ( F_28 ( V_35 , V_405 ,
V_403 , V_407 ) )
return - V_11 ;
for ( V_406 = 1 ; V_406 <= V_405 ; V_406 ++ )
if ( V_35 [ V_406 ] )
* V_404 |= ( 1 << V_406 ) ;
return 0 ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_5 * V_361 , T_1 V_408 ,
enum V_288 V_103 )
{
if ( ! V_408 ) {
if ( V_361 && ( V_361 -> V_409 & V_410 ) )
return - V_365 ;
return 0 ;
}
switch ( V_103 ) {
case V_105 :
if ( V_4 -> V_118 . V_35 & V_411 )
return 0 ;
break;
case V_111 :
if ( V_4 -> V_118 . V_35 & V_412 )
return 0 ;
break;
default:
break;
}
return - V_355 ;
}
static int F_84 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_413 V_99 ;
int V_26 ;
enum V_288 V_414 , V_415 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_2 V_416 , * V_35 = NULL ;
bool V_417 = false ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_414 = V_415 = V_6 -> V_362 -> V_103 ;
if ( V_2 -> V_8 [ V_396 ] ) {
V_415 = F_2 ( V_2 -> V_8 [ V_396 ] ) ;
if ( V_414 != V_415 )
V_417 = true ;
if ( V_415 > V_418 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_419 ] ) {
struct V_101 * V_102 = V_6 -> V_362 ;
if ( V_415 != V_107 )
return - V_11 ;
if ( F_73 ( V_6 ) )
return - V_365 ;
F_68 ( V_102 ) ;
F_85 ( V_420 !=
V_421 ) ;
V_102 -> V_422 =
F_20 ( V_2 -> V_8 [ V_419 ] ) ;
memcpy ( V_102 -> V_423 , F_19 ( V_2 -> V_8 [ V_419 ] ) ,
V_102 -> V_422 ) ;
F_70 ( V_102 ) ;
}
if ( V_2 -> V_8 [ V_424 ] ) {
V_99 . V_408 = ! ! F_29 ( V_2 -> V_8 [ V_424 ] ) ;
V_417 = true ;
V_26 = F_83 ( V_4 , V_6 , V_99 . V_408 , V_415 ) ;
if ( V_26 )
return V_26 ;
} else {
V_99 . V_408 = - 1 ;
}
if ( V_2 -> V_8 [ V_425 ] ) {
if ( V_415 != V_349 )
return - V_11 ;
V_26 = F_82 ( V_2 -> V_8 [ V_425 ] ,
& V_416 ) ;
if ( V_26 )
return V_26 ;
V_35 = & V_416 ;
V_417 = true ;
}
if ( V_417 )
V_26 = F_86 ( V_4 , V_6 , V_415 , V_35 , & V_99 ) ;
else
V_26 = 0 ;
if ( ! V_26 && V_99 . V_408 != - 1 )
V_6 -> V_362 -> V_408 = V_99 . V_408 ;
return V_26 ;
}
static int F_87 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_413 V_99 ;
struct V_5 * V_6 ;
int V_26 ;
enum V_288 type = V_426 ;
T_2 V_35 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( ! V_2 -> V_8 [ V_394 ] )
return - V_11 ;
if ( V_2 -> V_8 [ V_396 ] ) {
type = F_2 ( V_2 -> V_8 [ V_396 ] ) ;
if ( type > V_418 )
return - V_11 ;
}
if ( ! V_4 -> V_195 -> V_227 ||
! ( V_4 -> V_118 . V_202 & ( 1 << type ) ) )
return - V_355 ;
if ( V_2 -> V_8 [ V_424 ] ) {
V_99 . V_408 = ! ! F_29 ( V_2 -> V_8 [ V_424 ] ) ;
V_26 = F_83 ( V_4 , NULL , V_99 . V_408 , type ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_82 ( type == V_349 ?
V_2 -> V_8 [ V_425 ] : NULL ,
& V_35 ) ;
V_6 = V_4 -> V_195 -> V_227 ( & V_4 -> V_118 ,
F_19 ( V_2 -> V_8 [ V_394 ] ) ,
type , V_26 ? NULL : & V_35 , & V_99 ) ;
if ( F_6 ( V_6 ) )
return F_8 ( V_6 ) ;
if ( type == V_107 &&
V_2 -> V_8 [ V_419 ] ) {
struct V_101 * V_102 = V_6 -> V_362 ;
F_68 ( V_102 ) ;
F_85 ( V_420 !=
V_421 ) ;
V_102 -> V_422 =
F_20 ( V_2 -> V_8 [ V_419 ] ) ;
memcpy ( V_102 -> V_423 , F_19 ( V_2 -> V_8 [ V_419 ] ) ,
V_102 -> V_422 ) ;
F_70 ( V_102 ) ;
}
return 0 ;
}
static int F_88 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
if ( ! V_4 -> V_195 -> V_427 )
return - V_355 ;
return V_4 -> V_195 -> V_427 ( & V_4 -> V_118 , V_6 ) ;
}
static void F_89 ( void * V_124 , struct V_428 * V_99 )
{
struct V_7 * V_54 ;
struct V_429 * V_430 = V_124 ;
if ( V_99 -> V_54 )
F_49 ( V_430 -> V_37 , V_83 ,
V_99 -> V_70 , V_99 -> V_54 ) ;
if ( V_99 -> V_34 )
F_49 ( V_430 -> V_37 , V_84 ,
V_99 -> V_72 , V_99 -> V_34 ) ;
if ( V_99 -> V_74 )
F_24 ( V_430 -> V_37 , V_86 ,
V_99 -> V_74 ) ;
V_54 = F_41 ( V_430 -> V_37 , V_91 ) ;
if ( ! V_54 )
goto V_52;
if ( V_99 -> V_54 )
F_49 ( V_430 -> V_37 , V_68 ,
V_99 -> V_70 , V_99 -> V_54 ) ;
if ( V_99 -> V_34 )
F_49 ( V_430 -> V_37 , V_71 ,
V_99 -> V_72 , V_99 -> V_34 ) ;
if ( V_99 -> V_74 )
F_24 ( V_430 -> V_37 , V_73 ,
V_99 -> V_74 ) ;
F_47 ( V_430 -> V_37 , V_85 , V_430 -> V_67 ) ;
F_42 ( V_430 -> V_37 , V_54 ) ;
return;
V_52:
V_430 -> error = 1 ;
}
static int F_90 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_1 V_431 = 0 ;
const T_1 * V_432 = NULL ;
bool V_433 ;
struct V_429 V_430 = {
. error = 0 ,
} ;
void * V_142 ;
struct V_23 * V_37 ;
if ( V_2 -> V_8 [ V_85 ] )
V_431 = F_29 ( V_2 -> V_8 [ V_85 ] ) ;
if ( V_431 > 5 )
return - V_11 ;
if ( V_2 -> V_8 [ V_364 ] )
V_432 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_433 = ! ! V_432 ;
if ( V_2 -> V_8 [ V_89 ] ) {
T_2 V_434 = F_2 ( V_2 -> V_8 [ V_89 ] ) ;
if ( V_434 >= V_76 )
return - V_11 ;
if ( V_434 != V_435 &&
V_434 != V_436 )
return - V_11 ;
V_433 = V_434 == V_436 ;
}
if ( ! V_4 -> V_195 -> V_437 )
return - V_355 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_438 ) ;
if ( F_6 ( V_142 ) )
return F_8 ( V_142 ) ;
V_430 . V_37 = V_37 ;
V_430 . V_67 = V_431 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_47 ( V_37 , V_85 , V_431 ) ;
if ( V_432 )
F_49 ( V_37 , V_364 , V_439 , V_432 ) ;
if ( V_433 && V_432 &&
! ( V_4 -> V_118 . V_35 & V_180 ) )
return - V_440 ;
V_26 = V_4 -> V_195 -> V_437 ( & V_4 -> V_118 , V_6 , V_431 , V_433 ,
V_432 , & V_430 , F_89 ) ;
if ( V_26 )
goto V_441;
if ( V_430 . error )
goto V_52;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_441:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_55 V_54 ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 < 0 )
return - V_11 ;
if ( ! V_54 . V_60 && ! V_54 . V_62 )
return - V_11 ;
F_68 ( V_6 -> V_362 ) ;
if ( V_54 . V_60 ) {
if ( ! V_4 -> V_195 -> V_442 ) {
V_26 = - V_355 ;
goto V_402;
}
V_26 = F_38 ( V_6 -> V_362 ) ;
if ( V_26 )
goto V_402;
V_26 = V_4 -> V_195 -> V_442 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . V_64 , V_54 . V_65 ) ;
if ( V_26 )
goto V_402;
#ifdef F_92
V_6 -> V_362 -> V_443 . V_444 = V_54 . V_67 ;
#endif
} else {
if ( V_54 . V_64 || ! V_54 . V_65 ) {
V_26 = - V_11 ;
goto V_402;
}
if ( ! V_4 -> V_195 -> V_445 ) {
V_26 = - V_355 ;
goto V_402;
}
V_26 = F_38 ( V_6 -> V_362 ) ;
if ( V_26 )
goto V_402;
V_26 = V_4 -> V_195 -> V_445 ( & V_4 -> V_118 ,
V_6 , V_54 . V_67 ) ;
if ( V_26 )
goto V_402;
#ifdef F_92
V_6 -> V_362 -> V_443 . V_446 = V_54 . V_67 ;
#endif
}
V_402:
F_70 ( V_6 -> V_362 ) ;
return V_26 ;
}
static int F_93 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_55 V_54 ;
const T_1 * V_432 = NULL ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_54 . V_69 . V_54 )
return - V_11 ;
if ( V_2 -> V_8 [ V_364 ] )
V_432 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_432 )
V_54 . type = V_436 ;
else
V_54 . type = V_435 ;
}
if ( V_54 . type != V_436 &&
V_54 . type != V_435 )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_231 )
return - V_355 ;
if ( F_36 ( V_4 , & V_54 . V_69 , V_54 . V_67 ,
V_54 . type == V_436 ,
V_432 ) )
return - V_11 ;
F_68 ( V_6 -> V_362 ) ;
V_26 = F_38 ( V_6 -> V_362 ) ;
if ( ! V_26 )
V_26 = V_4 -> V_195 -> V_231 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . type == V_436 ,
V_432 , & V_54 . V_69 ) ;
F_70 ( V_6 -> V_362 ) ;
return V_26 ;
}
static int F_94 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_1 * V_432 = NULL ;
struct V_55 V_54 ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_2 -> V_8 [ V_364 ] )
V_432 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_432 )
V_54 . type = V_436 ;
else
V_54 . type = V_435 ;
}
if ( V_54 . type != V_436 &&
V_54 . type != V_435 )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_447 )
return - V_355 ;
F_68 ( V_6 -> V_362 ) ;
V_26 = F_38 ( V_6 -> V_362 ) ;
if ( V_54 . type == V_436 && V_432 &&
! ( V_4 -> V_118 . V_35 & V_180 ) )
V_26 = - V_440 ;
if ( ! V_26 )
V_26 = V_4 -> V_195 -> V_447 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . type == V_436 ,
V_432 ) ;
#ifdef F_92
if ( ! V_26 ) {
if ( V_54 . V_67 == V_6 -> V_362 -> V_443 . V_444 )
V_6 -> V_362 -> V_443 . V_444 = - 1 ;
else if ( V_54 . V_67 == V_6 -> V_362 -> V_443 . V_446 )
V_6 -> V_362 -> V_443 . V_446 = - 1 ;
}
#endif
F_70 ( V_6 -> V_362 ) ;
return V_26 ;
}
static int F_95 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
int (* F_96)( struct V_118 * V_118 , struct V_5 * V_6 ,
struct V_448 * V_2 );
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_362 ;
struct V_448 V_99 ;
int V_449 = 0 , V_26 ;
if ( ! F_18 ( V_2 -> V_8 [ V_450 ] ) )
return - V_11 ;
if ( V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_355 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
switch ( V_2 -> V_451 -> V_36 ) {
case V_452 :
if ( ! V_2 -> V_8 [ V_453 ] ||
! V_2 -> V_8 [ V_454 ] ||
! V_2 -> V_8 [ V_455 ] )
return - V_11 ;
V_99 . V_456 =
F_2 ( V_2 -> V_8 [ V_453 ] ) ;
V_99 . V_457 =
F_2 ( V_2 -> V_8 [ V_454 ] ) ;
V_26 = F_97 ( V_4 , V_99 . V_456 ) ;
if ( V_26 )
return V_26 ;
F_96 = V_4 -> V_195 -> V_233 ;
break;
case V_458 :
F_96 = V_4 -> V_195 -> V_459 ;
break;
default:
F_98 ( 1 ) ;
return - V_355 ;
}
if ( ! F_96 )
return - V_355 ;
if ( V_2 -> V_8 [ V_455 ] ) {
V_99 . V_460 = F_19 ( V_2 -> V_8 [ V_455 ] ) ;
V_99 . V_461 =
F_20 ( V_2 -> V_8 [ V_455 ] ) ;
V_449 = 1 ;
}
if ( V_2 -> V_8 [ V_450 ] ) {
V_99 . V_462 = F_19 ( V_2 -> V_8 [ V_450 ] ) ;
V_99 . V_463 =
F_20 ( V_2 -> V_8 [ V_450 ] ) ;
V_449 = 1 ;
}
if ( ! V_449 )
return - V_11 ;
V_26 = F_96 ( & V_4 -> V_118 , V_6 , & V_99 ) ;
if ( ! V_26 && V_99 . V_456 )
V_102 -> V_464 = V_99 . V_456 ;
return V_26 ;
}
static int F_99 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_362 ;
int V_26 ;
if ( ! V_4 -> V_195 -> V_465 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_355 ;
V_26 = V_4 -> V_195 -> V_465 ( & V_4 -> V_118 , V_6 ) ;
if ( ! V_26 )
V_102 -> V_464 = 0 ;
return V_26 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_466 * V_99 )
{
struct V_7 * V_35 [ V_467 + 1 ] ;
struct V_7 * V_403 ;
int V_406 ;
V_403 = V_2 -> V_8 [ V_468 ] ;
if ( V_403 ) {
struct V_469 * V_470 ;
V_470 = F_19 ( V_403 ) ;
V_99 -> V_471 = V_470 -> V_472 ;
V_99 -> V_473 = V_470 -> V_474 ;
if ( ( V_99 -> V_471 |
V_99 -> V_473 ) & F_101 ( V_475 ) )
return - V_11 ;
return 0 ;
}
V_403 = V_2 -> V_8 [ V_476 ] ;
if ( ! V_403 )
return 0 ;
if ( F_28 ( V_35 , V_467 ,
V_403 , V_477 ) )
return - V_11 ;
V_99 -> V_471 = ( 1 << V_478 ) - 1 ;
V_99 -> V_471 &= ~ 1 ;
for ( V_406 = 1 ; V_406 <= V_467 ; V_406 ++ )
if ( V_35 [ V_406 ] )
V_99 -> V_473 |= ( 1 << V_406 ) ;
return 0 ;
}
static bool F_102 ( struct V_23 * V_37 , struct V_479 * V_2 ,
int V_29 )
{
struct V_7 * V_153 ;
T_3 V_223 ;
V_153 = F_41 ( V_37 , V_29 ) ;
if ( ! V_153 )
goto V_52;
V_223 = F_103 ( V_2 ) ;
if ( V_223 > 0 )
F_48 ( V_37 , V_480 , V_223 ) ;
if ( V_2 -> V_35 & V_481 )
F_47 ( V_37 , V_482 , V_2 -> V_209 ) ;
if ( V_2 -> V_35 & V_483 )
F_25 ( V_37 , V_484 ) ;
if ( V_2 -> V_35 & V_485 )
F_25 ( V_37 , V_486 ) ;
F_42 ( V_37 , V_153 ) ;
return true ;
V_52:
return false ;
}
static int F_104 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
const T_1 * V_432 , struct V_487 * V_488 )
{
void * V_142 ;
struct V_7 * V_489 , * V_490 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_491 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_432 ) ;
F_24 ( V_37 , V_160 , V_488 -> V_492 ) ;
V_489 = F_41 ( V_37 , V_493 ) ;
if ( ! V_489 )
goto V_52;
if ( V_488 -> V_494 & V_495 )
F_24 ( V_37 , V_496 ,
V_488 -> V_497 ) ;
if ( V_488 -> V_494 & V_498 )
F_24 ( V_37 , V_499 ,
V_488 -> V_500 ) ;
if ( V_488 -> V_494 & V_501 )
F_24 ( V_37 , V_502 ,
V_488 -> V_503 ) ;
if ( V_488 -> V_494 & V_504 )
F_24 ( V_37 , V_505 ,
V_488 -> V_506 ) ;
if ( V_488 -> V_494 & V_507 )
F_48 ( V_37 , V_508 ,
V_488 -> V_509 ) ;
if ( V_488 -> V_494 & V_510 )
F_48 ( V_37 , V_511 ,
V_488 -> V_512 ) ;
if ( V_488 -> V_494 & V_513 )
F_47 ( V_37 , V_514 ,
V_488 -> V_515 ) ;
if ( V_488 -> V_494 & V_516 )
F_47 ( V_37 , V_517 ,
V_488 -> signal ) ;
if ( V_488 -> V_494 & V_518 )
F_47 ( V_37 , V_519 ,
V_488 -> V_520 ) ;
if ( V_488 -> V_494 & V_521 ) {
if ( ! F_102 ( V_37 , & V_488 -> V_522 ,
V_523 ) )
goto V_52;
}
if ( V_488 -> V_494 & V_524 ) {
if ( ! F_102 ( V_37 , & V_488 -> V_525 ,
V_526 ) )
goto V_52;
}
if ( V_488 -> V_494 & V_527 )
F_24 ( V_37 , V_528 ,
V_488 -> V_529 ) ;
if ( V_488 -> V_494 & V_530 )
F_24 ( V_37 , V_531 ,
V_488 -> V_532 ) ;
if ( V_488 -> V_494 & V_533 )
F_24 ( V_37 , V_534 ,
V_488 -> V_535 ) ;
if ( V_488 -> V_494 & V_536 )
F_24 ( V_37 , V_537 ,
V_488 -> V_538 ) ;
if ( V_488 -> V_494 & V_539 ) {
V_490 = F_41 ( V_37 , V_540 ) ;
if ( ! V_490 )
goto V_52;
if ( V_488 -> V_490 . V_35 & V_541 )
F_25 ( V_37 , V_542 ) ;
if ( V_488 -> V_490 . V_35 & V_543 )
F_25 ( V_37 , V_544 ) ;
if ( V_488 -> V_490 . V_35 & V_545 )
F_25 ( V_37 ,
V_546 ) ;
F_47 ( V_37 , V_547 ,
V_488 -> V_490 . V_457 ) ;
F_48 ( V_37 , V_548 ,
V_488 -> V_490 . V_464 ) ;
F_42 ( V_37 , V_490 ) ;
}
F_42 ( V_37 , V_489 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
static int F_105 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_487 V_488 ;
struct V_3 * V_6 ;
struct V_5 * V_361 ;
T_1 V_432 [ V_439 ] ;
int V_549 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_6 , & V_361 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_6 -> V_195 -> V_550 ) {
V_26 = - V_355 ;
goto V_551;
}
while ( 1 ) {
V_26 = V_6 -> V_195 -> V_550 ( & V_6 -> V_118 , V_361 , V_549 ,
V_432 , & V_488 ) ;
if ( V_26 == - V_440 )
break;
if ( V_26 )
goto V_551;
if ( F_104 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_330 , V_331 ,
V_361 , V_432 ,
& V_488 ) < 0 )
goto V_402;
V_549 ++ ;
}
V_402:
V_14 -> args [ 1 ] = V_549 ;
V_26 = V_24 -> V_31 ;
V_551:
F_16 ( V_6 ) ;
return V_26 ;
}
static int F_106 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_487 V_488 ;
struct V_23 * V_37 ;
T_1 * V_432 = NULL ;
int V_26 ;
memset ( & V_488 , 0 , sizeof( V_488 ) ) ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
V_432 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( ! V_4 -> V_195 -> V_552 )
return - V_355 ;
V_26 = V_4 -> V_195 -> V_552 ( & V_4 -> V_118 , V_6 , V_432 , & V_488 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_104 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_6 , V_432 , & V_488 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_553 )
{
struct V_7 * V_554 = V_2 -> V_8 [ V_555 ] ;
* V_553 = NULL ;
if ( V_554 ) {
* V_553 = F_3 ( F_4 ( V_2 ) ,
F_2 ( V_554 ) ) ;
if ( ! * V_553 )
return - V_12 ;
if ( ! ( * V_553 ) -> V_362 )
return - V_11 ;
if ( ( * V_553 ) -> V_362 -> V_118 != & V_4 -> V_118 )
return - V_11 ;
if ( ! F_73 ( * V_553 ) )
return - V_556 ;
}
return 0 ;
}
static int F_108 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_466 V_99 ;
T_1 * V_432 = NULL ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_557 = - 1 ;
V_99 . V_515 = - 1 ;
if ( V_2 -> V_8 [ V_558 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
V_432 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( V_2 -> V_8 [ V_559 ] ) {
V_99 . V_560 =
F_19 ( V_2 -> V_8 [ V_559 ] ) ;
V_99 . V_561 =
F_20 ( V_2 -> V_8 [ V_559 ] ) ;
}
if ( V_2 -> V_8 [ V_562 ] )
V_99 . V_557 =
F_65 ( V_2 -> V_8 [ V_562 ] ) ;
if ( V_2 -> V_8 [ V_563 ] )
V_99 . V_564 =
F_19 ( V_2 -> V_8 [ V_563 ] ) ;
if ( F_100 ( V_2 , & V_99 ) )
return - V_11 ;
if ( V_2 -> V_8 [ V_565 ] )
V_99 . V_566 =
F_29 ( V_2 -> V_8 [ V_565 ] ) ;
if ( V_2 -> V_8 [ V_567 ] )
V_99 . V_515 =
F_29 ( V_2 -> V_8 [ V_567 ] ) ;
V_26 = F_107 ( V_2 , V_4 , & V_99 . V_553 ) ;
if ( V_26 )
goto V_402;
V_26 = 0 ;
switch ( V_6 -> V_362 -> V_103 ) {
case V_104 :
case V_105 :
case V_106 :
if ( V_99 . V_566 )
V_26 = - V_11 ;
break;
case V_112 :
case V_111 :
if ( V_99 . V_566 )
V_26 = - V_11 ;
if ( V_99 . V_553 )
V_26 = - V_11 ;
if ( V_99 . V_560 )
V_26 = - V_11 ;
if ( V_99 . V_564 )
V_26 = - V_11 ;
if ( V_99 . V_557 >= 0 )
V_26 = - V_11 ;
if ( V_99 . V_471 & ~ F_101 ( V_568 ) )
V_26 = - V_11 ;
break;
case V_107 :
if ( V_99 . V_553 )
V_26 = - V_11 ;
if ( V_99 . V_564 )
V_26 = - V_11 ;
if ( V_99 . V_557 >= 0 )
V_26 = - V_11 ;
if ( V_99 . V_471 &
~ ( F_101 ( V_569 ) |
F_101 ( V_570 ) |
F_101 ( V_568 ) ) )
V_26 = - V_11 ;
break;
default:
V_26 = - V_11 ;
}
if ( V_26 )
goto V_402;
if ( ! V_4 -> V_195 -> V_571 ) {
V_26 = - V_355 ;
goto V_402;
}
V_26 = V_4 -> V_195 -> V_571 ( & V_4 -> V_118 , V_6 , V_432 , & V_99 ) ;
V_402:
if ( V_99 . V_553 )
F_7 ( V_99 . V_553 ) ;
return V_26 ;
}
static int F_109 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_466 V_99 ;
T_1 * V_432 = NULL ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_562 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_559 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_558 ] )
return - V_11 ;
V_432 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_99 . V_560 =
F_19 ( V_2 -> V_8 [ V_559 ] ) ;
V_99 . V_561 =
F_20 ( V_2 -> V_8 [ V_559 ] ) ;
V_99 . V_557 =
F_65 ( V_2 -> V_8 [ V_562 ] ) ;
V_99 . V_572 = F_65 ( V_2 -> V_8 [ V_558 ] ) ;
if ( ! V_99 . V_572 || V_99 . V_572 > V_573 )
return - V_11 ;
if ( V_2 -> V_8 [ V_563 ] )
V_99 . V_564 =
F_19 ( V_2 -> V_8 [ V_563 ] ) ;
if ( V_2 -> V_8 [ V_565 ] )
V_99 . V_566 =
F_29 ( V_2 -> V_8 [ V_565 ] ) ;
if ( F_100 ( V_2 , & V_99 ) )
return - V_11 ;
if ( V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_105 &&
V_6 -> V_362 -> V_103 != V_107 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_11 ;
V_26 = F_107 ( V_2 , V_4 , & V_99 . V_553 ) ;
if ( V_26 )
goto V_402;
V_26 = 0 ;
if ( ! V_4 -> V_195 -> V_235 ) {
V_26 = - V_355 ;
goto V_402;
}
V_26 = V_4 -> V_195 -> V_235 ( & V_4 -> V_118 , V_6 , V_432 , & V_99 ) ;
V_402:
if ( V_99 . V_553 )
F_7 ( V_99 . V_553 ) ;
return V_26 ;
}
static int F_110 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_1 * V_432 = NULL ;
if ( V_2 -> V_8 [ V_364 ] )
V_432 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_105 &&
V_6 -> V_362 -> V_103 != V_107 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_574 )
return - V_355 ;
return V_4 -> V_195 -> V_574 ( & V_4 -> V_118 , V_6 , V_432 ) ;
}
static int F_111 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
T_1 * V_575 , T_1 * V_576 ,
struct V_577 * V_578 )
{
void * V_142 ;
struct V_7 * V_579 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_491 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_575 ) ;
F_49 ( V_37 , V_580 , V_439 , V_576 ) ;
F_24 ( V_37 , V_160 , V_578 -> V_492 ) ;
V_579 = F_41 ( V_37 , V_581 ) ;
if ( ! V_579 )
goto V_52;
if ( V_578 -> V_494 & V_582 )
F_24 ( V_37 , V_583 ,
V_578 -> V_584 ) ;
if ( V_578 -> V_494 & V_585 )
F_24 ( V_37 , V_586 ,
V_578 -> V_587 ) ;
if ( V_578 -> V_494 & V_588 )
F_24 ( V_37 , V_589 ,
V_578 -> V_590 ) ;
if ( V_578 -> V_494 & V_591 )
F_24 ( V_37 , V_592 ,
V_578 -> V_593 ) ;
if ( V_578 -> V_494 & V_594 )
F_47 ( V_37 , V_595 ,
V_578 -> V_35 ) ;
if ( V_578 -> V_494 & V_596 )
F_24 ( V_37 , V_597 ,
V_578 -> V_598 ) ;
if ( V_578 -> V_494 & V_599 )
F_47 ( V_37 , V_600 ,
V_578 -> V_601 ) ;
F_42 ( V_37 , V_579 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
static int F_112 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_577 V_578 ;
struct V_3 * V_6 ;
struct V_5 * V_361 ;
T_1 V_575 [ V_439 ] ;
T_1 V_576 [ V_439 ] ;
int V_602 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_6 , & V_361 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_6 -> V_195 -> V_603 ) {
V_26 = - V_355 ;
goto V_551;
}
if ( V_361 -> V_362 -> V_103 != V_107 ) {
V_26 = - V_355 ;
goto V_551;
}
while ( 1 ) {
V_26 = V_6 -> V_195 -> V_603 ( & V_6 -> V_118 , V_361 , V_602 ,
V_575 , V_576 , & V_578 ) ;
if ( V_26 == - V_440 )
break;
if ( V_26 )
goto V_551;
if ( F_111 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_330 , V_331 ,
V_361 , V_575 , V_576 ,
& V_578 ) < 0 )
goto V_402;
V_602 ++ ;
}
V_402:
V_14 -> args [ 1 ] = V_602 ;
V_26 = V_24 -> V_31 ;
V_551:
F_16 ( V_6 ) ;
return V_26 ;
}
static int F_113 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_577 V_578 ;
struct V_23 * V_37 ;
T_1 * V_575 = NULL ;
T_1 V_576 [ V_439 ] ;
memset ( & V_578 , 0 , sizeof( V_578 ) ) ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
V_575 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( ! V_4 -> V_195 -> V_604 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_107 )
return - V_355 ;
V_26 = V_4 -> V_195 -> V_604 ( & V_4 -> V_118 , V_6 , V_575 , V_576 , & V_578 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_111 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_6 , V_575 , V_576 , & V_578 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_114 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_1 * V_575 = NULL ;
T_1 * V_576 = NULL ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_580 ] )
return - V_11 ;
V_575 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_576 = F_19 ( V_2 -> V_8 [ V_580 ] ) ;
if ( ! V_4 -> V_195 -> V_605 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_107 )
return - V_355 ;
return V_4 -> V_195 -> V_605 ( & V_4 -> V_118 , V_6 , V_575 , V_576 ) ;
}
static int F_115 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_1 * V_575 = NULL ;
T_1 * V_576 = NULL ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_580 ] )
return - V_11 ;
V_575 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_576 = F_19 ( V_2 -> V_8 [ V_580 ] ) ;
if ( ! V_4 -> V_195 -> V_237 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_107 )
return - V_355 ;
return V_4 -> V_195 -> V_237 ( & V_4 -> V_118 , V_6 , V_575 , V_576 ) ;
}
static int F_116 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_1 * V_575 = NULL ;
if ( V_2 -> V_8 [ V_364 ] )
V_575 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( ! V_4 -> V_195 -> V_606 )
return - V_355 ;
return V_4 -> V_195 -> V_606 ( & V_4 -> V_118 , V_6 , V_575 ) ;
}
static int F_117 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_607 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_608 = - 1 ;
V_99 . V_609 = - 1 ;
V_99 . V_610 = - 1 ;
V_99 . V_611 = - 1 ;
V_99 . V_612 = - 1 ;
if ( V_2 -> V_8 [ V_613 ] )
V_99 . V_608 =
F_29 ( V_2 -> V_8 [ V_613 ] ) ;
if ( V_2 -> V_8 [ V_614 ] )
V_99 . V_609 =
F_29 ( V_2 -> V_8 [ V_614 ] ) ;
if ( V_2 -> V_8 [ V_615 ] )
V_99 . V_610 =
F_29 ( V_2 -> V_8 [ V_615 ] ) ;
if ( V_2 -> V_8 [ V_616 ] ) {
V_99 . V_617 =
F_19 ( V_2 -> V_8 [ V_616 ] ) ;
V_99 . V_618 =
F_20 ( V_2 -> V_8 [ V_616 ] ) ;
}
if ( V_2 -> V_8 [ V_619 ] )
V_99 . V_611 = ! ! F_29 ( V_2 -> V_8 [ V_619 ] ) ;
if ( V_2 -> V_8 [ V_620 ] )
V_99 . V_612 =
F_65 ( V_2 -> V_8 [ V_620 ] ) ;
if ( ! V_4 -> V_195 -> V_241 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_355 ;
return V_4 -> V_195 -> V_241 ( & V_4 -> V_118 , V_6 , & V_99 ) ;
}
static int F_118 ( struct V_7 * V_57 [] ,
struct V_621 * V_622 )
{
struct V_623 * V_624 = & V_622 -> V_624 ;
struct V_625 * V_626 = & V_622 -> V_626 ;
if ( ! V_57 [ V_627 ] )
return - V_11 ;
if ( ! V_57 [ V_628 ] )
return - V_11 ;
if ( ! V_57 [ V_629 ] )
return - V_11 ;
if ( ! V_57 [ V_630 ] )
return - V_11 ;
if ( ! V_57 [ V_631 ] )
return - V_11 ;
V_622 -> V_35 = F_2 ( V_57 [ V_627 ] ) ;
V_624 -> V_632 =
F_2 ( V_57 [ V_628 ] ) ;
V_624 -> V_633 =
F_2 ( V_57 [ V_629 ] ) ;
V_624 -> V_634 =
F_2 ( V_57 [ V_630 ] ) ;
V_626 -> V_635 =
F_2 ( V_57 [ V_631 ] ) ;
if ( V_57 [ V_636 ] )
V_626 -> V_637 =
F_2 ( V_57 [ V_636 ] ) ;
return 0 ;
}
static int F_119 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
int V_638 ;
char * V_100 = NULL ;
F_54 ( & V_329 ) ;
if ( F_120 ( ! V_639 ) ) {
F_59 ( & V_329 ) ;
return - V_640 ;
}
F_59 ( & V_329 ) ;
if ( ! V_2 -> V_8 [ V_641 ] )
return - V_11 ;
V_100 = F_19 ( V_2 -> V_8 [ V_641 ] ) ;
V_638 = F_121 ( V_100 ) ;
return V_638 ;
}
static int F_122 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_362 ;
struct V_642 V_643 ;
int V_26 = 0 ;
void * V_142 ;
struct V_7 * V_579 ;
struct V_23 * V_37 ;
if ( V_102 -> V_103 != V_107 )
return - V_355 ;
if ( ! V_4 -> V_195 -> V_644 )
return - V_355 ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_645 )
memcpy ( & V_643 , & V_646 , sizeof( V_643 ) ) ;
else
V_26 = V_4 -> V_195 -> V_644 ( & V_4 -> V_118 , V_6 ,
& V_643 ) ;
F_70 ( V_102 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_647 ) ;
if ( ! V_142 )
goto V_402;
V_579 = F_41 ( V_37 , V_648 ) ;
if ( ! V_579 )
goto V_52;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_48 ( V_37 , V_649 ,
V_643 . V_650 ) ;
F_48 ( V_37 , V_651 ,
V_643 . V_652 ) ;
F_48 ( V_37 , V_653 ,
V_643 . V_654 ) ;
F_48 ( V_37 , V_655 ,
V_643 . V_656 ) ;
F_47 ( V_37 , V_657 ,
V_643 . V_658 ) ;
F_47 ( V_37 , V_659 ,
V_643 . V_660 ) ;
F_47 ( V_37 , V_661 ,
V_643 . V_662 ) ;
F_47 ( V_37 , V_663 ,
V_643 . V_664 ) ;
F_47 ( V_37 , V_665 ,
V_643 . V_666 ) ;
F_24 ( V_37 , V_667 ,
V_643 . V_668 ) ;
F_48 ( V_37 , V_669 ,
V_643 . V_670 ) ;
F_24 ( V_37 , V_671 ,
V_643 . V_672 ) ;
F_48 ( V_37 , V_673 ,
V_643 . V_674 ) ;
F_48 ( V_37 , V_675 ,
V_643 . V_676 ) ;
F_47 ( V_37 , V_677 ,
V_643 . V_678 ) ;
F_42 ( V_37 , V_579 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
V_402:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_642 * V_679 ,
T_2 * V_680 )
{
struct V_7 * V_57 [ V_681 + 1 ] ;
T_2 V_472 = 0 ;
#define F_124 ( T_6 , V_679 , T_7 , V_472 , T_8 , T_9 ) \
do {\
if (table[attr_num]) {\
cfg->param = nla_fn(table[attr_num]); \
mask |= (1 << (attr_num - 1)); \
} \
} while (0);\
if (!info->attrs[NL80211_ATTR_MESH_CONFIG])
return - V_11 ;
if ( F_28 ( V_57 , V_681 ,
V_2 -> V_8 [ V_648 ] ,
V_682 ) )
return - V_11 ;
F_85 ( V_681 > 32 ) ;
F_124 ( V_57 , V_679 , V_650 ,
V_472 , V_649 , F_65 ) ;
F_124 ( V_57 , V_679 , V_652 ,
V_472 , V_651 , F_65 ) ;
F_124 ( V_57 , V_679 , V_654 ,
V_472 , V_653 , F_65 ) ;
F_124 ( V_57 , V_679 , V_656 ,
V_472 , V_655 , F_65 ) ;
F_124 ( V_57 , V_679 , V_658 ,
V_472 , V_657 , F_29 ) ;
F_124 ( V_57 , V_679 , V_660 ,
V_472 , V_659 , F_29 ) ;
F_124 ( V_57 , V_679 , V_662 ,
V_472 , V_661 , F_29 ) ;
F_124 ( V_57 , V_679 , V_664 ,
V_472 , V_663 , F_29 ) ;
F_124 ( V_57 , V_679 , V_666 ,
V_472 , V_665 ,
F_29 ) ;
F_124 ( V_57 , V_679 , V_668 ,
V_472 , V_667 , F_2 ) ;
F_124 ( V_57 , V_679 , V_670 ,
V_472 , V_669 ,
F_65 ) ;
F_124 ( V_57 , V_679 , V_672 ,
V_472 , V_671 ,
F_2 ) ;
F_124 ( V_57 , V_679 , V_674 ,
V_472 , V_673 ,
F_65 ) ;
F_124 ( V_57 , V_679 ,
V_676 ,
V_472 , V_675 ,
F_65 ) ;
F_124 ( V_57 , V_679 ,
V_678 , V_472 ,
V_677 ,
F_29 ) ;
if ( V_680 )
* V_680 = V_472 ;
return 0 ;
#undef F_124
}
static int F_125 ( struct V_1 * V_2 ,
struct V_683 * V_684 )
{
struct V_7 * V_57 [ V_685 + 1 ] ;
if ( ! V_2 -> V_8 [ V_686 ] )
return - V_11 ;
if ( F_28 ( V_57 , V_685 ,
V_2 -> V_8 [ V_686 ] ,
V_687 ) )
return - V_11 ;
if ( V_57 [ V_688 ] )
V_684 -> V_689 =
( F_29 ( V_57 [ V_688 ] ) ) ?
V_690 :
V_691 ;
if ( V_57 [ V_692 ] )
V_684 -> V_693 =
( F_29 ( V_57 [ V_692 ] ) ) ?
V_694 :
V_695 ;
if ( V_57 [ V_696 ] ) {
struct V_7 * V_697 =
V_57 [ V_696 ] ;
if ( ! F_18 ( V_697 ) )
return - V_11 ;
V_684 -> V_698 = F_19 ( V_697 ) ;
V_684 -> V_699 = F_20 ( V_697 ) ;
}
V_684 -> V_700 = F_126 ( V_57 [ V_701 ] ) ;
V_684 -> V_702 = F_126 ( V_57 [ V_703 ] ) ;
return 0 ;
}
static int F_127 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_362 ;
struct V_642 V_679 ;
T_2 V_472 ;
int V_26 ;
if ( V_102 -> V_103 != V_107 )
return - V_355 ;
if ( ! V_4 -> V_195 -> V_239 )
return - V_355 ;
V_26 = F_123 ( V_2 , & V_679 , & V_472 ) ;
if ( V_26 )
return V_26 ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_645 )
V_26 = - V_110 ;
if ( ! V_26 )
V_26 = V_4 -> V_195 -> V_239 ( & V_4 -> V_118 , V_6 ,
V_472 , & V_679 ) ;
F_70 ( V_102 ) ;
return V_26 ;
}
static int F_128 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
void * V_142 = NULL ;
struct V_7 * V_704 ;
unsigned int V_117 ;
int V_26 = - V_11 ;
F_54 ( & V_329 ) ;
if ( ! V_639 )
goto V_402;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 ) {
V_26 = - V_53 ;
goto V_402;
}
V_142 = F_21 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_705 ) ;
if ( ! V_142 )
goto V_706;
F_45 ( V_37 , V_641 ,
V_639 -> V_707 ) ;
V_704 = F_41 ( V_37 , V_708 ) ;
if ( ! V_704 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_639 -> V_709 ; V_117 ++ ) {
struct V_7 * V_710 ;
const struct V_621 * V_622 ;
const struct V_623 * V_624 ;
const struct V_625 * V_626 ;
V_622 = & V_639 -> V_711 [ V_117 ] ;
V_624 = & V_622 -> V_624 ;
V_626 = & V_622 -> V_626 ;
V_710 = F_41 ( V_37 , V_117 ) ;
if ( ! V_710 )
goto V_52;
F_24 ( V_37 , V_627 ,
V_622 -> V_35 ) ;
F_24 ( V_37 , V_628 ,
V_624 -> V_632 ) ;
F_24 ( V_37 , V_629 ,
V_624 -> V_633 ) ;
F_24 ( V_37 , V_630 ,
V_624 -> V_634 ) ;
F_24 ( V_37 , V_636 ,
V_626 -> V_637 ) ;
F_24 ( V_37 , V_631 ,
V_626 -> V_635 ) ;
F_42 ( V_37 , V_710 ) ;
}
F_42 ( V_37 , V_704 ) ;
F_51 ( V_37 , V_142 ) ;
V_26 = F_63 ( V_37 , V_2 ) ;
goto V_402;
V_52:
F_52 ( V_37 , V_142 ) ;
V_706:
F_62 ( V_37 ) ;
V_26 = - V_327 ;
V_402:
F_59 ( & V_329 ) ;
return V_26 ;
}
static int F_129 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_7 * V_57 [ V_712 + 1 ] ;
struct V_7 * V_710 ;
char * V_707 = NULL ;
int V_713 = 0 , V_638 = 0 ;
T_2 V_714 = 0 , V_715 = 0 , V_716 ;
struct V_717 * V_718 = NULL ;
if ( ! V_2 -> V_8 [ V_641 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_708 ] )
return - V_11 ;
V_707 = F_19 ( V_2 -> V_8 [ V_641 ] ) ;
F_35 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_714 ++ ;
if ( V_714 > V_719 )
return - V_11 ;
}
F_54 ( & V_329 ) ;
if ( ! F_130 ( V_707 ) ) {
V_638 = - V_11 ;
goto V_720;
}
V_716 = sizeof( struct V_717 ) +
( V_714 * sizeof( struct V_621 ) ) ;
V_718 = F_33 ( V_716 , V_97 ) ;
if ( ! V_718 ) {
V_638 = - V_98 ;
goto V_720;
}
V_718 -> V_709 = V_714 ;
V_718 -> V_707 [ 0 ] = V_707 [ 0 ] ;
V_718 -> V_707 [ 1 ] = V_707 [ 1 ] ;
F_35 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_78 ( V_57 , V_712 ,
F_19 ( V_710 ) , F_20 ( V_710 ) ,
V_721 ) ;
V_638 = F_118 ( V_57 , & V_718 -> V_711 [ V_715 ] ) ;
if ( V_638 )
goto V_720;
V_715 ++ ;
if ( V_715 > V_719 ) {
V_638 = - V_11 ;
goto V_720;
}
}
F_131 ( V_715 != V_714 ) ;
V_638 = F_132 ( V_718 ) ;
F_59 ( & V_329 ) ;
return V_638 ;
V_720:
F_59 ( & V_329 ) ;
F_37 ( V_718 ) ;
return V_638 ;
}
static int F_133 ( struct V_7 * V_722 )
{
struct V_7 * V_723 , * V_724 ;
int V_217 = 0 , V_725 , V_726 ;
F_35 (attr1, freqs, tmp1) {
V_217 ++ ;
F_35 (attr2, freqs, tmp2)
if ( V_723 != V_724 &&
F_2 ( V_723 ) == F_2 ( V_724 ) )
return 0 ;
}
return V_217 ;
}
static int F_134 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_727 * V_728 ;
struct V_7 * V_29 ;
struct V_118 * V_118 ;
int V_26 , V_729 , V_730 = 0 , V_217 , V_117 ;
T_10 V_699 ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
V_118 = & V_4 -> V_118 ;
if ( ! V_4 -> V_195 -> V_732 )
return - V_355 ;
if ( V_4 -> V_733 )
return - V_365 ;
if ( V_2 -> V_8 [ V_734 ] ) {
V_217 = F_133 (
V_2 -> V_8 [ V_734 ] ) ;
if ( ! V_217 )
return - V_11 ;
} else {
enum V_150 V_151 ;
V_217 = 0 ;
for ( V_151 = 0 ; V_151 < V_204 ; V_151 ++ )
if ( V_118 -> V_205 [ V_151 ] )
V_217 += V_118 -> V_205 [ V_151 ] -> V_217 ;
}
if ( V_2 -> V_8 [ V_735 ] )
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_730 ++ ;
if ( V_730 > V_118 -> V_173 )
return - V_11 ;
if ( V_2 -> V_8 [ V_731 ] )
V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
else
V_699 = 0 ;
if ( V_699 > V_118 -> V_177 )
return - V_11 ;
V_728 = F_33 ( sizeof( * V_728 )
+ sizeof( * V_728 -> V_736 ) * V_730
+ sizeof( * V_728 -> V_218 ) * V_217
+ V_699 , V_97 ) ;
if ( ! V_728 )
return - V_98 ;
if ( V_730 )
V_728 -> V_736 = ( void * ) & V_728 -> V_218 [ V_217 ] ;
V_728 -> V_730 = V_730 ;
if ( V_699 ) {
if ( V_728 -> V_736 )
V_728 -> V_698 = ( void * ) ( V_728 -> V_736 + V_730 ) ;
else
V_728 -> V_698 = ( void * ) ( V_728 -> V_218 + V_217 ) ;
}
V_117 = 0 ;
if ( V_2 -> V_8 [ V_734 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_38 * V_39 ;
V_39 = F_135 ( V_118 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_737;
}
if ( V_39 -> V_35 & V_42 )
continue;
V_728 -> V_218 [ V_117 ] = V_39 ;
V_117 ++ ;
}
} else {
enum V_150 V_151 ;
for ( V_151 = 0 ; V_151 < V_204 ; V_151 ++ ) {
int V_120 ;
if ( ! V_118 -> V_205 [ V_151 ] )
continue;
for ( V_120 = 0 ; V_120 < V_118 -> V_205 [ V_151 ] -> V_217 ; V_120 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_118 -> V_205 [ V_151 ] -> V_218 [ V_120 ] ;
if ( V_39 -> V_35 & V_42 )
continue;
V_728 -> V_218 [ V_117 ] = V_39 ;
V_117 ++ ;
}
}
}
if ( ! V_117 ) {
V_26 = - V_11 ;
goto V_737;
}
V_728 -> V_217 = V_117 ;
V_117 = 0 ;
if ( V_2 -> V_8 [ V_735 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_20 ( V_29 ) > V_420 ) {
V_26 = - V_11 ;
goto V_737;
}
V_728 -> V_736 [ V_117 ] . V_738 = F_20 ( V_29 ) ;
memcpy ( V_728 -> V_736 [ V_117 ] . V_423 , F_19 ( V_29 ) , F_20 ( V_29 ) ) ;
V_117 ++ ;
}
}
if ( V_2 -> V_8 [ V_731 ] ) {
V_728 -> V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
memcpy ( ( void * ) V_728 -> V_698 ,
F_19 ( V_2 -> V_8 [ V_731 ] ) ,
V_728 -> V_699 ) ;
}
for ( V_117 = 0 ; V_117 < V_204 ; V_117 ++ )
if ( V_118 -> V_205 [ V_117 ] )
V_728 -> V_739 [ V_117 ] =
( 1 << V_118 -> V_205 [ V_117 ] -> V_220 ) - 1 ;
if ( V_2 -> V_8 [ V_740 ] ) {
F_35 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_150 V_151 = F_136 ( V_29 ) ;
if ( V_151 < 0 || V_151 >= V_204 ) {
V_26 = - V_11 ;
goto V_737;
}
V_26 = F_137 ( V_118 -> V_205 [ V_151 ] ,
F_19 ( V_29 ) ,
F_20 ( V_29 ) ,
& V_728 -> V_739 [ V_151 ] ) ;
if ( V_26 )
goto V_737;
}
}
V_728 -> V_6 = V_6 ;
V_728 -> V_118 = & V_4 -> V_118 ;
V_4 -> V_733 = V_728 ;
V_26 = V_4 -> V_195 -> V_732 ( & V_4 -> V_118 , V_6 , V_728 ) ;
if ( ! V_26 ) {
F_138 ( V_4 , V_6 ) ;
F_139 ( V_6 ) ;
} else {
V_737:
V_4 -> V_733 = NULL ;
F_37 ( V_728 ) ;
}
return V_26 ;
}
static int F_140 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_741 * V_728 ;
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_7 * V_29 ;
struct V_118 * V_118 ;
int V_26 , V_729 , V_730 = 0 , V_217 , V_117 ;
T_2 V_456 ;
enum V_150 V_151 ;
T_10 V_699 ;
if ( ! ( V_4 -> V_118 . V_35 & V_275 ) ||
! V_4 -> V_195 -> V_276 )
return - V_355 ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_742 ] )
return - V_11 ;
V_456 = F_2 ( V_2 -> V_8 [ V_742 ] ) ;
if ( V_456 == 0 )
return - V_11 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_734 ] ) {
V_217 = F_133 (
V_2 -> V_8 [ V_734 ] ) ;
if ( ! V_217 )
return - V_11 ;
} else {
V_217 = 0 ;
for ( V_151 = 0 ; V_151 < V_204 ; V_151 ++ )
if ( V_118 -> V_205 [ V_151 ] )
V_217 += V_118 -> V_205 [ V_151 ] -> V_217 ;
}
if ( V_2 -> V_8 [ V_735 ] )
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_730 ++ ;
if ( V_730 > V_118 -> V_175 )
return - V_11 ;
if ( V_2 -> V_8 [ V_731 ] )
V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
else
V_699 = 0 ;
if ( V_699 > V_118 -> V_179 )
return - V_11 ;
F_54 ( & V_4 -> V_743 ) ;
if ( V_4 -> V_744 ) {
V_26 = - V_640 ;
goto V_402;
}
V_728 = F_33 ( sizeof( * V_728 )
+ sizeof( * V_728 -> V_736 ) * V_730
+ sizeof( * V_728 -> V_218 ) * V_217
+ V_699 , V_97 ) ;
if ( ! V_728 ) {
V_26 = - V_98 ;
goto V_402;
}
if ( V_730 )
V_728 -> V_736 = ( void * ) & V_728 -> V_218 [ V_217 ] ;
V_728 -> V_730 = V_730 ;
if ( V_699 ) {
if ( V_728 -> V_736 )
V_728 -> V_698 = ( void * ) ( V_728 -> V_736 + V_730 ) ;
else
V_728 -> V_698 = ( void * ) ( V_728 -> V_218 + V_217 ) ;
}
V_117 = 0 ;
if ( V_2 -> V_8 [ V_734 ] ) {
F_35 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_38 * V_39 ;
V_39 = F_135 ( V_118 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_737;
}
if ( V_39 -> V_35 & V_42 )
continue;
V_728 -> V_218 [ V_117 ] = V_39 ;
V_117 ++ ;
}
} else {
for ( V_151 = 0 ; V_151 < V_204 ; V_151 ++ ) {
int V_120 ;
if ( ! V_118 -> V_205 [ V_151 ] )
continue;
for ( V_120 = 0 ; V_120 < V_118 -> V_205 [ V_151 ] -> V_217 ; V_120 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_118 -> V_205 [ V_151 ] -> V_218 [ V_120 ] ;
if ( V_39 -> V_35 & V_42 )
continue;
V_728 -> V_218 [ V_117 ] = V_39 ;
V_117 ++ ;
}
}
}
if ( ! V_117 ) {
V_26 = - V_11 ;
goto V_737;
}
V_728 -> V_217 = V_117 ;
V_117 = 0 ;
if ( V_2 -> V_8 [ V_735 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_20 ( V_29 ) > V_420 ) {
V_26 = - V_11 ;
goto V_737;
}
V_728 -> V_736 [ V_117 ] . V_738 = F_20 ( V_29 ) ;
memcpy ( V_728 -> V_736 [ V_117 ] . V_423 , F_19 ( V_29 ) ,
F_20 ( V_29 ) ) ;
V_117 ++ ;
}
}
if ( V_2 -> V_8 [ V_731 ] ) {
V_728 -> V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
memcpy ( ( void * ) V_728 -> V_698 ,
F_19 ( V_2 -> V_8 [ V_731 ] ) ,
V_728 -> V_699 ) ;
}
V_728 -> V_6 = V_6 ;
V_728 -> V_118 = & V_4 -> V_118 ;
V_728 -> V_456 = V_456 ;
V_26 = V_4 -> V_195 -> V_276 ( & V_4 -> V_118 , V_6 , V_728 ) ;
if ( ! V_26 ) {
V_4 -> V_744 = V_728 ;
F_141 ( V_4 , V_6 ,
V_745 ) ;
goto V_402;
}
V_737:
F_37 ( V_728 ) ;
V_402:
F_59 ( & V_4 -> V_743 ) ;
return V_26 ;
}
static int F_142 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
if ( ! ( V_4 -> V_118 . V_35 & V_275 ) ||
! V_4 -> V_195 -> V_746 )
return - V_355 ;
F_54 ( & V_4 -> V_743 ) ;
V_26 = F_143 ( V_4 , false ) ;
F_59 ( & V_4 -> V_743 ) ;
return V_26 ;
}
static int F_144 ( struct V_23 * V_37 , struct V_13 * V_14 ,
T_2 V_34 , int V_35 ,
struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_747 * V_748 )
{
struct V_749 * V_15 = & V_748 -> V_750 ;
void * V_142 ;
struct V_7 * V_751 ;
int V_117 ;
F_39 ( V_102 ) ;
V_142 = F_21 ( V_37 , F_58 ( V_14 -> V_24 ) . V_33 , V_34 , V_35 ,
V_752 ) ;
if ( ! V_142 )
return - 1 ;
F_145 ( V_14 , V_142 , & V_18 ) ;
F_24 ( V_37 , V_160 , V_4 -> V_753 ) ;
F_24 ( V_37 , V_10 , V_102 -> V_361 -> V_9 ) ;
V_751 = F_41 ( V_37 , V_754 ) ;
if ( ! V_751 )
goto V_52;
if ( ! F_146 ( V_15 -> V_363 ) )
F_49 ( V_37 , V_755 , V_439 , V_15 -> V_363 ) ;
if ( V_15 -> V_756 && V_15 -> V_757 )
F_49 ( V_37 , V_758 ,
V_15 -> V_757 ,
V_15 -> V_756 ) ;
if ( V_15 -> V_759 && V_15 -> V_760 &&
V_15 -> V_759 != V_15 -> V_756 )
F_49 ( V_37 , V_761 ,
V_15 -> V_760 , V_15 -> V_759 ) ;
if ( V_15 -> V_762 )
F_147 ( V_37 , V_763 , V_15 -> V_762 ) ;
if ( V_15 -> V_464 )
F_48 ( V_37 , V_764 , V_15 -> V_464 ) ;
F_48 ( V_37 , V_765 , V_15 -> V_766 ) ;
F_24 ( V_37 , V_767 , V_15 -> V_768 -> V_41 ) ;
F_24 ( V_37 , V_769 ,
F_148 ( V_770 - V_748 -> V_771 ) ) ;
switch ( V_4 -> V_118 . V_772 ) {
case V_773 :
F_24 ( V_37 , V_774 , V_15 -> signal ) ;
break;
case V_775 :
F_47 ( V_37 , V_776 , V_15 -> signal ) ;
break;
default:
break;
}
switch ( V_102 -> V_103 ) {
case V_112 :
case V_111 :
if ( V_748 == V_102 -> V_109 )
F_24 ( V_37 , V_777 ,
V_778 ) ;
else for ( V_117 = 0 ; V_117 < V_779 ; V_117 ++ ) {
if ( V_748 != V_102 -> V_780 [ V_117 ] )
continue;
F_24 ( V_37 , V_777 ,
V_781 ) ;
break;
}
break;
case V_108 :
if ( V_748 == V_102 -> V_109 )
F_24 ( V_37 , V_777 ,
V_782 ) ;
break;
default:
break;
}
F_42 ( V_37 , V_751 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
static int F_149 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_747 * V_732 ;
struct V_101 * V_102 ;
int V_328 = V_14 -> args [ 1 ] , V_67 = 0 ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_4 , & V_6 ) ;
if ( V_26 )
return V_26 ;
V_102 = V_6 -> V_362 ;
F_68 ( V_102 ) ;
F_150 ( & V_4 -> V_783 ) ;
F_151 ( V_4 ) ;
V_14 -> V_34 = V_4 -> V_753 ;
F_55 (scan, &rdev->bss_list, list) {
if ( ++ V_67 <= V_328 )
continue;
if ( F_144 ( V_24 , V_14 ,
V_14 -> V_16 -> V_330 , V_331 ,
V_4 , V_102 , V_732 ) < 0 ) {
V_67 -- ;
break;
}
}
F_152 ( & V_4 -> V_783 ) ;
F_70 ( V_102 ) ;
V_14 -> args [ 1 ] = V_67 ;
F_16 ( V_4 ) ;
return V_24 -> V_31 ;
}
static int F_153 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
struct V_784 * V_785 )
{
void * V_142 ;
struct V_7 * V_786 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 ,
V_787 ) ;
if ( ! V_142 )
return - V_98 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
V_786 = F_41 ( V_37 , V_788 ) ;
if ( ! V_786 )
goto V_52;
F_24 ( V_37 , V_789 ,
V_785 -> V_768 -> V_41 ) ;
if ( V_785 -> V_494 & V_790 )
F_47 ( V_37 , V_791 ,
V_785 -> V_792 ) ;
if ( V_785 -> V_494 & V_793 )
F_25 ( V_37 , V_794 ) ;
if ( V_785 -> V_494 & V_795 )
F_147 ( V_37 , V_796 ,
V_785 -> V_797 ) ;
if ( V_785 -> V_494 & V_798 )
F_147 ( V_37 , V_799 ,
V_785 -> V_800 ) ;
if ( V_785 -> V_494 & V_801 )
F_147 ( V_37 , V_802 ,
V_785 -> V_803 ) ;
if ( V_785 -> V_494 & V_804 )
F_147 ( V_37 , V_805 ,
V_785 -> V_806 ) ;
if ( V_785 -> V_494 & V_807 )
F_147 ( V_37 , V_808 ,
V_785 -> V_809 ) ;
F_42 ( V_37 , V_786 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
static int F_154 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_784 V_785 ;
struct V_3 * V_6 ;
struct V_5 * V_361 ;
int V_810 = V_14 -> args [ 1 ] ;
int V_15 ;
V_15 = F_11 ( V_24 , V_14 , & V_6 , & V_361 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_6 -> V_195 -> V_811 ) {
V_15 = - V_355 ;
goto V_551;
}
while ( 1 ) {
struct V_38 * V_39 ;
V_15 = V_6 -> V_195 -> V_811 ( & V_6 -> V_118 , V_361 , V_810 ,
& V_785 ) ;
if ( V_15 == - V_440 )
break;
if ( V_15 )
goto V_551;
if ( ! V_785 . V_768 ) {
V_15 = - V_11 ;
goto V_402;
}
V_39 = F_135 ( & V_6 -> V_118 ,
V_785 . V_768 -> V_41 ) ;
if ( ! V_39 || V_39 -> V_35 & V_42 ) {
V_810 ++ ;
continue;
}
if ( F_153 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_330 , V_331 ,
V_361 ,
& V_785 ) < 0 )
goto V_402;
V_810 ++ ;
}
V_402:
V_14 -> args [ 1 ] = V_810 ;
V_15 = V_24 -> V_31 ;
V_551:
F_16 ( V_6 ) ;
return V_15 ;
}
static bool F_155 ( enum V_812 V_813 )
{
return V_813 <= V_814 ;
}
static bool F_156 ( T_2 V_815 )
{
return ! ( V_815 & ~ ( V_816 |
V_817 ) ) ;
}
static bool F_157 ( T_2 V_818 )
{
return V_818 == V_819 ||
V_818 == V_820 ;
}
static bool F_158 ( T_2 V_74 )
{
return V_74 == V_821 ||
V_74 == V_822 ||
V_74 == V_823 ||
V_74 == V_824 ||
V_74 == V_825 ;
}
static int F_159 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_38 * V_39 ;
const T_1 * V_363 , * V_423 , * V_698 = NULL ;
int V_26 , V_738 , V_699 = 0 ;
enum V_812 V_813 ;
struct V_55 V_54 ;
bool V_826 ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_827 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_828 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_354 ] )
return - V_11 ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 >= 0 ) {
if ( V_54 . type != - 1 && V_54 . type != V_435 )
return - V_11 ;
if ( ! V_54 . V_69 . V_54 || ! V_54 . V_69 . V_70 )
return - V_11 ;
if ( ( V_54 . V_69 . V_74 != V_821 ||
V_54 . V_69 . V_70 != V_829 ) &&
( V_54 . V_69 . V_74 != V_822 ||
V_54 . V_69 . V_70 != V_830 ) )
return - V_11 ;
if ( V_54 . V_67 > 4 )
return - V_11 ;
} else {
V_54 . V_69 . V_70 = 0 ;
V_54 . V_69 . V_54 = NULL ;
}
if ( V_54 . V_67 >= 0 ) {
int V_117 ;
bool V_831 = false ;
for ( V_117 = 0 ; V_117 < V_4 -> V_118 . V_185 ; V_117 ++ ) {
if ( V_54 . V_69 . V_74 == V_4 -> V_118 . V_186 [ V_117 ] ) {
V_831 = true ;
break;
}
}
if ( ! V_831 )
return - V_11 ;
}
if ( ! V_4 -> V_195 -> V_243 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_39 = F_135 ( & V_4 -> V_118 ,
F_2 ( V_2 -> V_8 [ V_354 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_42 ) )
return - V_11 ;
V_423 = F_19 ( V_2 -> V_8 [ V_828 ] ) ;
V_738 = F_20 ( V_2 -> V_8 [ V_828 ] ) ;
if ( V_2 -> V_8 [ V_731 ] ) {
V_698 = F_19 ( V_2 -> V_8 [ V_731 ] ) ;
V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
}
V_813 = F_2 ( V_2 -> V_8 [ V_827 ] ) ;
if ( ! F_155 ( V_813 ) )
return - V_11 ;
V_826 = ! ! V_2 -> V_8 [ V_832 ] ;
return F_160 ( V_4 , V_6 , V_39 , V_813 , V_363 ,
V_423 , V_738 , V_698 , V_699 ,
V_54 . V_69 . V_54 , V_54 . V_69 . V_70 , V_54 . V_67 ,
V_826 ) ;
}
static int F_161 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_833 * V_834 ,
int V_835 )
{
memset ( V_834 , 0 , sizeof( * V_834 ) ) ;
V_834 -> V_836 = V_2 -> V_8 [ V_837 ] ;
if ( V_2 -> V_8 [ V_190 ] ) {
T_3 V_838 ;
V_838 = F_65 (
V_2 -> V_8 [ V_190 ] ) ;
V_834 -> V_839 = F_162 ( V_838 ) ;
if ( ! ( V_4 -> V_118 . V_35 & V_189 ) &&
V_838 != V_840 )
return - V_11 ;
if ( V_2 -> V_8 [ V_841 ] )
V_834 -> V_842 = true ;
} else
V_834 -> V_839 = F_162 ( V_840 ) ;
if ( V_2 -> V_8 [ V_843 ] ) {
void * V_100 ;
int V_31 , V_117 ;
V_100 = F_19 ( V_2 -> V_8 [ V_843 ] ) ;
V_31 = F_20 ( V_2 -> V_8 [ V_843 ] ) ;
V_834 -> V_844 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
if ( V_834 -> V_844 > V_835 )
return - V_11 ;
memcpy ( V_834 -> V_845 , V_100 , V_31 ) ;
for ( V_117 = 0 ; V_117 < V_834 -> V_844 ; V_117 ++ )
if ( ! F_158 (
V_834 -> V_845 [ V_117 ] ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_846 ] ) {
V_834 -> V_847 =
F_2 ( V_2 -> V_8 [ V_846 ] ) ;
if ( ! F_158 ( V_834 -> V_847 ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_848 ] ) {
V_834 -> V_815 =
F_2 ( V_2 -> V_8 [ V_848 ] ) ;
if ( ! F_156 ( V_834 -> V_815 ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_849 ] ) {
void * V_100 ;
int V_31 , V_117 ;
V_100 = F_19 ( V_2 -> V_8 [ V_849 ] ) ;
V_31 = F_20 ( V_2 -> V_8 [ V_849 ] ) ;
V_834 -> V_850 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
if ( V_834 -> V_850 > V_851 )
return - V_11 ;
memcpy ( V_834 -> V_852 , V_100 , V_31 ) ;
for ( V_117 = 0 ; V_117 < V_834 -> V_850 ; V_117 ++ )
if ( ! F_157 ( V_834 -> V_852 [ V_117 ] ) )
return - V_11 ;
}
return 0 ;
}
static int F_163 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_833 V_853 ;
struct V_38 * V_39 ;
const T_1 * V_363 , * V_423 , * V_698 = NULL , * V_854 = NULL ;
int V_26 , V_738 , V_699 = 0 ;
bool V_855 = false ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_364 ] ||
! V_2 -> V_8 [ V_828 ] ||
! V_2 -> V_8 [ V_354 ] )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_245 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_39 = F_135 ( & V_4 -> V_118 ,
F_2 ( V_2 -> V_8 [ V_354 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_42 ) )
return - V_11 ;
V_423 = F_19 ( V_2 -> V_8 [ V_828 ] ) ;
V_738 = F_20 ( V_2 -> V_8 [ V_828 ] ) ;
if ( V_2 -> V_8 [ V_731 ] ) {
V_698 = F_19 ( V_2 -> V_8 [ V_731 ] ) ;
V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
}
if ( V_2 -> V_8 [ V_856 ] ) {
enum V_857 V_858 =
F_2 ( V_2 -> V_8 [ V_856 ] ) ;
if ( V_858 == V_859 )
V_855 = true ;
else if ( V_858 != V_860 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_861 ] )
V_854 = F_19 ( V_2 -> V_8 [ V_861 ] ) ;
V_26 = F_161 ( V_4 , V_2 , & V_853 , 1 ) ;
if ( ! V_26 )
V_26 = F_164 ( V_4 , V_6 , V_39 , V_363 , V_854 ,
V_423 , V_738 , V_698 , V_699 , V_855 ,
& V_853 ) ;
return V_26 ;
}
static int F_165 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
const T_1 * V_698 = NULL , * V_363 ;
int V_699 = 0 ;
T_3 V_862 ;
bool V_826 ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_863 ] )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_247 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_862 = F_65 ( V_2 -> V_8 [ V_863 ] ) ;
if ( V_862 == 0 ) {
return - V_11 ;
}
if ( V_2 -> V_8 [ V_731 ] ) {
V_698 = F_19 ( V_2 -> V_8 [ V_731 ] ) ;
V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
}
V_826 = ! ! V_2 -> V_8 [ V_832 ] ;
return F_166 ( V_4 , V_6 , V_363 , V_698 , V_699 , V_862 ,
V_826 ) ;
}
static int F_167 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
const T_1 * V_698 = NULL , * V_363 ;
int V_699 = 0 ;
T_3 V_862 ;
bool V_826 ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_863 ] )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_249 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_862 = F_65 ( V_2 -> V_8 [ V_863 ] ) ;
if ( V_862 == 0 ) {
return - V_11 ;
}
if ( V_2 -> V_8 [ V_731 ] ) {
V_698 = F_19 ( V_2 -> V_8 [ V_731 ] ) ;
V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
}
V_826 = ! ! V_2 -> V_8 [ V_832 ] ;
return F_168 ( V_4 , V_6 , V_363 , V_698 , V_699 , V_862 ,
V_826 ) ;
}
static bool
F_169 ( struct V_3 * V_4 ,
int V_864 [ V_204 ] ,
int V_865 )
{
struct V_118 * V_118 = & V_4 -> V_118 ;
bool V_866 = false ;
int V_151 , V_117 ;
for ( V_151 = 0 ; V_151 < V_204 ; V_151 ++ ) {
struct V_867 * V_868 ;
V_868 = V_118 -> V_205 [ V_151 ] ;
if ( ! V_868 )
continue;
for ( V_117 = 0 ; V_117 < V_868 -> V_220 ; V_117 ++ ) {
if ( V_868 -> V_221 [ V_117 ] . V_223 == V_865 ) {
V_864 [ V_151 ] = V_117 + 1 ;
V_866 = true ;
break;
}
}
}
return V_866 ;
}
static int F_170 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_869 V_870 ;
struct V_118 * V_118 ;
struct V_92 * V_871 = NULL ;
int V_26 ;
memset ( & V_870 , 0 , sizeof( V_870 ) ) ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_354 ] ||
! V_2 -> V_8 [ V_828 ] ||
! F_20 ( V_2 -> V_8 [ V_828 ] ) )
return - V_11 ;
V_870 . V_464 = 100 ;
if ( V_2 -> V_8 [ V_453 ] ) {
V_870 . V_464 =
F_2 ( V_2 -> V_8 [ V_453 ] ) ;
if ( V_870 . V_464 < 1 || V_870 . V_464 > 10000 )
return - V_11 ;
}
if ( ! V_4 -> V_195 -> V_251 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_108 )
return - V_355 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_364 ] )
V_870 . V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_870 . V_423 = F_19 ( V_2 -> V_8 [ V_828 ] ) ;
V_870 . V_738 = F_20 ( V_2 -> V_8 [ V_828 ] ) ;
if ( V_2 -> V_8 [ V_731 ] ) {
V_870 . V_698 = F_19 ( V_2 -> V_8 [ V_731 ] ) ;
V_870 . V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
}
V_870 . V_768 = F_135 ( V_118 ,
F_2 ( V_2 -> V_8 [ V_354 ] ) ) ;
if ( ! V_870 . V_768 ||
V_870 . V_768 -> V_35 & V_46 ||
V_870 . V_768 -> V_35 & V_42 )
return - V_11 ;
V_870 . V_872 = ! ! V_2 -> V_8 [ V_873 ] ;
V_870 . V_874 = ! ! V_2 -> V_8 [ V_875 ] ;
if ( V_2 -> V_8 [ V_616 ] ) {
T_1 * V_739 =
F_19 ( V_2 -> V_8 [ V_616 ] ) ;
int V_876 =
F_20 ( V_2 -> V_8 [ V_616 ] ) ;
struct V_867 * V_868 =
V_118 -> V_205 [ V_870 . V_768 -> V_151 ] ;
int V_26 ;
V_26 = F_137 ( V_868 , V_739 , V_876 ,
& V_870 . V_617 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_2 -> V_8 [ V_877 ] &&
! F_169 ( V_4 , V_870 . V_864 ,
F_2 ( V_2 -> V_8 [ V_877 ] ) ) )
return - V_11 ;
if ( V_870 . V_874 && V_2 -> V_8 [ V_878 ] ) {
V_871 = F_32 ( V_4 ,
V_2 -> V_8 [ V_878 ] ) ;
if ( F_6 ( V_871 ) )
return F_8 ( V_871 ) ;
}
V_26 = F_171 ( V_4 , V_6 , & V_870 , V_871 ) ;
if ( V_26 )
F_37 ( V_871 ) ;
return V_26 ;
}
static int F_172 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
if ( ! V_4 -> V_195 -> V_879 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_108 )
return - V_355 ;
return F_173 ( V_4 , V_6 , false ) ;
}
static int F_174 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_880 ] )
return - V_11 ;
V_26 = - V_355 ;
if ( V_4 -> V_195 -> V_881 ) {
V_4 -> V_882 = V_2 ;
V_26 = V_4 -> V_195 -> V_881 ( & V_4 -> V_118 ,
F_19 ( V_2 -> V_8 [ V_880 ] ) ,
F_20 ( V_2 -> V_8 [ V_880 ] ) ) ;
V_4 -> V_882 = NULL ;
}
return V_26 ;
}
static int F_175 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_3 * V_6 ;
int V_26 ;
long V_883 ;
void * V_100 = NULL ;
int V_884 = 0 ;
if ( V_14 -> args [ 0 ] ) {
V_883 = V_14 -> args [ 0 ] - 1 ;
} else {
V_26 = F_10 ( V_14 -> V_16 , V_17 + V_18 . V_19 ,
V_18 . V_20 , V_18 . V_21 ,
V_22 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_18 . V_20 [ V_157 ] )
return - V_11 ;
V_883 = F_2 ( V_18 . V_20 [ V_157 ] ) ;
if ( V_18 . V_20 [ V_880 ] )
V_14 -> args [ 1 ] =
( long ) V_18 . V_20 [ V_880 ] ;
}
if ( V_14 -> args [ 1 ] ) {
V_100 = F_19 ( ( void * ) V_14 -> args [ 1 ] ) ;
V_884 = F_20 ( ( void * ) V_14 -> args [ 1 ] ) ;
}
F_54 ( & V_329 ) ;
V_6 = F_176 ( V_883 ) ;
if ( ! V_6 ) {
F_59 ( & V_329 ) ;
return - V_440 ;
}
F_177 ( V_6 ) ;
F_59 ( & V_329 ) ;
if ( ! V_6 -> V_195 -> V_885 ) {
V_26 = - V_355 ;
goto V_551;
}
while ( 1 ) {
void * V_142 = F_21 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_330 , V_331 ,
V_886 ) ;
struct V_7 * V_887 ;
if ( F_178 ( V_24 , V_157 , V_6 -> V_158 ) < 0 ) {
F_52 ( V_24 , V_142 ) ;
break;
}
V_887 = F_41 ( V_24 , V_880 ) ;
if ( ! V_887 ) {
F_52 ( V_24 , V_142 ) ;
break;
}
V_26 = V_6 -> V_195 -> V_885 ( & V_6 -> V_118 , V_24 , V_14 ,
V_100 , V_884 ) ;
F_42 ( V_24 , V_887 ) ;
if ( V_26 == - V_53 || V_26 == - V_440 ) {
F_52 ( V_24 , V_142 ) ;
break;
} else if ( V_26 ) {
F_52 ( V_24 , V_142 ) ;
goto V_551;
}
F_51 ( V_24 , V_142 ) ;
}
V_26 = V_24 -> V_31 ;
V_14 -> args [ 0 ] = V_883 + 1 ;
V_551:
F_17 ( V_6 ) ;
return V_26 ;
}
static struct V_23 *
F_179 ( struct V_3 * V_4 ,
int V_888 , T_2 V_33 , T_2 V_34 , T_11 V_889 )
{
struct V_23 * V_24 ;
void * V_142 ;
struct V_7 * V_100 ;
V_24 = F_61 ( V_888 + 100 , V_889 ) ;
if ( ! V_24 )
return NULL ;
V_142 = F_21 ( V_24 , V_33 , V_34 , 0 , V_886 ) ;
if ( ! V_142 ) {
F_180 ( V_24 ) ;
return NULL ;
}
F_24 ( V_24 , V_157 , V_4 -> V_158 ) ;
V_100 = F_41 ( V_24 , V_880 ) ;
( ( void * * ) V_24 -> V_14 ) [ 0 ] = V_4 ;
( ( void * * ) V_24 -> V_14 ) [ 1 ] = V_142 ;
( ( void * * ) V_24 -> V_14 ) [ 2 ] = V_100 ;
return V_24 ;
V_52:
F_180 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_181 ( struct V_118 * V_118 ,
int V_888 )
{
struct V_3 * V_4 = F_75 ( V_118 ) ;
if ( F_98 ( ! V_4 -> V_882 ) )
return NULL ;
return F_179 ( V_4 , V_888 ,
V_4 -> V_882 -> V_334 ,
V_4 -> V_882 -> V_335 ,
V_97 ) ;
}
int F_182 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = ( ( void * * ) V_24 -> V_14 ) [ 0 ] ;
void * V_142 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_7 * V_100 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
if ( F_98 ( ! V_4 -> V_882 ) ) {
F_180 ( V_24 ) ;
return - V_11 ;
}
F_42 ( V_24 , V_100 ) ;
F_51 ( V_24 , V_142 ) ;
return F_63 ( V_24 , V_4 -> V_882 ) ;
}
struct V_23 * F_183 ( struct V_118 * V_118 ,
int V_888 , T_11 V_889 )
{
struct V_3 * V_4 = F_75 ( V_118 ) ;
return F_179 ( V_4 , V_888 , 0 , 0 , V_889 ) ;
}
void F_184 ( struct V_23 * V_24 , T_11 V_889 )
{
void * V_142 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_7 * V_100 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
F_42 ( V_24 , V_100 ) ;
F_51 ( V_24 , V_142 ) ;
F_185 ( V_24 , 0 , V_890 . V_891 , V_889 ) ;
}
static int F_186 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_892 V_278 ;
struct V_118 * V_118 ;
struct V_92 * V_871 = NULL ;
int V_26 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
if ( ! F_18 ( V_2 -> V_8 [ V_731 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_828 ] ||
! F_20 ( V_2 -> V_8 [ V_828 ] ) )
return - V_11 ;
if ( V_2 -> V_8 [ V_827 ] ) {
V_278 . V_813 =
F_2 ( V_2 -> V_8 [ V_827 ] ) ;
if ( ! F_155 ( V_278 . V_813 ) )
return - V_11 ;
} else
V_278 . V_813 = V_893 ;
V_278 . V_874 = V_2 -> V_8 [ V_875 ] ;
V_26 = F_161 ( V_4 , V_2 , & V_278 . V_853 ,
V_894 ) ;
if ( V_26 )
return V_26 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_364 ] )
V_278 . V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
V_278 . V_423 = F_19 ( V_2 -> V_8 [ V_828 ] ) ;
V_278 . V_738 = F_20 ( V_2 -> V_8 [ V_828 ] ) ;
if ( V_2 -> V_8 [ V_731 ] ) {
V_278 . V_698 = F_19 ( V_2 -> V_8 [ V_731 ] ) ;
V_278 . V_699 = F_20 ( V_2 -> V_8 [ V_731 ] ) ;
}
if ( V_2 -> V_8 [ V_354 ] ) {
V_278 . V_768 =
F_135 ( V_118 ,
F_2 ( V_2 -> V_8 [ V_354 ] ) ) ;
if ( ! V_278 . V_768 ||
V_278 . V_768 -> V_35 & V_42 )
return - V_11 ;
}
if ( V_278 . V_874 && V_2 -> V_8 [ V_878 ] ) {
V_871 = F_32 ( V_4 ,
V_2 -> V_8 [ V_878 ] ) ;
if ( F_6 ( V_871 ) )
return F_8 ( V_871 ) ;
}
V_26 = F_187 ( V_4 , V_6 , & V_278 , V_871 ) ;
if ( V_26 )
F_37 ( V_871 ) ;
return V_26 ;
}
static int F_188 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_3 V_895 ;
if ( ! V_2 -> V_8 [ V_863 ] )
V_895 = V_896 ;
else
V_895 = F_65 ( V_2 -> V_8 [ V_863 ] ) ;
if ( V_895 == 0 )
return - V_11 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
return F_189 ( V_4 , V_6 , V_895 , true ) ;
}
static int F_190 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_897 * V_897 ;
int V_26 ;
T_2 V_33 ;
if ( ! V_2 -> V_8 [ V_898 ] )
return - V_11 ;
V_33 = F_2 ( V_2 -> V_8 [ V_898 ] ) ;
V_897 = F_191 ( V_33 ) ;
if ( F_6 ( V_897 ) )
return F_8 ( V_897 ) ;
V_26 = 0 ;
if ( ! F_56 ( F_57 ( & V_4 -> V_118 ) , V_897 ) )
V_26 = F_192 ( V_4 , V_897 ) ;
F_193 ( V_897 ) ;
return V_26 ;
}
static int F_194 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
int (* F_195)( struct V_118 * V_118 , struct V_5 * V_6 ,
struct V_899 * V_900 ) = NULL ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_899 V_900 ;
memset ( & V_900 , 0 , sizeof( struct V_899 ) ) ;
if ( ! V_2 -> V_8 [ V_364 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_901 ] )
return - V_11 ;
V_900 . V_902 = F_19 ( V_2 -> V_8 [ V_901 ] ) ;
V_900 . V_363 = F_19 ( V_2 -> V_8 [ V_364 ] ) ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
switch ( V_2 -> V_451 -> V_36 ) {
case V_903 :
F_195 = V_4 -> V_195 -> V_255 ;
break;
case V_904 :
F_195 = V_4 -> V_195 -> V_257 ;
break;
default:
F_98 ( 1 ) ;
break;
}
if ( ! F_195 )
return - V_355 ;
return F_195 ( & V_4 -> V_118 , V_6 , & V_900 ) ;
}
static int F_196 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_112 )
return - V_355 ;
if ( ! V_4 -> V_195 -> V_259 )
return - V_355 ;
return V_4 -> V_195 -> V_259 ( & V_4 -> V_118 , V_6 ) ;
}
static int F_197 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_38 * V_39 ;
struct V_23 * V_37 ;
void * V_142 ;
T_12 V_430 ;
enum V_350 V_351 = V_352 ;
T_2 V_353 , V_905 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_354 ] ||
! V_2 -> V_8 [ V_906 ] )
return - V_11 ;
V_905 = F_2 ( V_2 -> V_8 [ V_906 ] ) ;
if ( ! V_905 || ! F_198 ( V_905 ) ||
V_905 > V_4 -> V_118 . V_283 )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_261 )
return - V_355 ;
if ( V_2 -> V_8 [ V_356 ] ) {
V_351 = F_2 (
V_2 -> V_8 [ V_356 ] ) ;
if ( V_351 != V_352 &&
V_351 != V_357 &&
V_351 != V_358 &&
V_351 != V_359 )
return - V_11 ;
}
V_353 = F_2 ( V_2 -> V_8 [ V_354 ] ) ;
V_39 = F_199 ( V_4 , V_353 , V_351 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_907 ) ;
if ( F_6 ( V_142 ) ) {
V_26 = F_8 ( V_142 ) ;
goto V_441;
}
V_26 = V_4 -> V_195 -> V_261 ( & V_4 -> V_118 , V_6 , V_39 ,
V_351 , V_905 , & V_430 ) ;
if ( V_26 )
goto V_441;
F_147 ( V_37 , V_908 , V_430 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_441:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_200 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_12 V_430 ;
if ( ! V_2 -> V_8 [ V_908 ] )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_909 )
return - V_355 ;
V_430 = F_201 ( V_2 -> V_8 [ V_908 ] ) ;
return V_4 -> V_195 -> V_909 ( & V_4 -> V_118 , V_6 , V_430 ) ;
}
static T_2 F_202 ( struct V_867 * V_868 ,
T_1 * V_739 , T_1 V_910 )
{
T_1 V_117 ;
T_2 V_472 = 0 ;
for ( V_117 = 0 ; V_117 < V_910 ; V_117 ++ ) {
int V_153 = ( V_739 [ V_117 ] & 0x7f ) * 5 ;
int V_911 ;
for ( V_911 = 0 ; V_911 < V_868 -> V_220 ; V_911 ++ ) {
struct V_152 * V_912 =
& V_868 -> V_221 [ V_911 ] ;
if ( V_153 == V_912 -> V_223 ) {
V_472 |= 1 << V_911 ;
break;
}
}
if ( V_911 == V_868 -> V_220 )
return 0 ;
}
return V_472 ;
}
static int F_203 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_7 * V_57 [ V_913 + 1 ] ;
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_914 V_472 ;
int V_96 , V_117 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_7 * V_915 ;
struct V_867 * V_868 ;
if ( V_2 -> V_8 [ V_916 ] == NULL )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_263 )
return - V_355 ;
memset ( & V_472 , 0 , sizeof( V_472 ) ) ;
for ( V_117 = 0 ; V_117 < V_204 ; V_117 ++ ) {
V_868 = V_4 -> V_118 . V_205 [ V_117 ] ;
V_472 . V_917 [ V_117 ] . V_918 =
V_868 ? ( 1 << V_868 -> V_220 ) - 1 : 0 ;
}
F_35 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_150 V_151 = F_136 ( V_915 ) ;
if ( V_151 < 0 || V_151 >= V_204 )
return - V_11 ;
V_868 = V_4 -> V_118 . V_205 [ V_151 ] ;
if ( V_868 == NULL )
return - V_11 ;
F_78 ( V_57 , V_913 , F_19 ( V_915 ) ,
F_20 ( V_915 ) , V_919 ) ;
if ( V_57 [ V_920 ] ) {
V_472 . V_917 [ V_151 ] . V_918 = F_202 (
V_868 ,
F_19 ( V_57 [ V_920 ] ) ,
F_20 ( V_57 [ V_920 ] ) ) ;
if ( V_472 . V_917 [ V_151 ] . V_918 == 0 )
return - V_11 ;
}
}
return V_4 -> V_195 -> V_263 ( & V_4 -> V_118 , V_6 , NULL , & V_472 ) ;
}
static int F_204 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_3 V_921 = V_294 | V_922 ;
if ( ! V_2 -> V_8 [ V_923 ] )
return - V_11 ;
if ( V_2 -> V_8 [ V_293 ] )
V_921 = F_65 ( V_2 -> V_8 [ V_293 ] ) ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_108 &&
V_6 -> V_362 -> V_103 != V_112 &&
V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_105 &&
V_6 -> V_362 -> V_103 != V_107 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_355 ;
if ( ! V_4 -> V_195 -> V_265 )
return - V_355 ;
return F_205 ( V_6 -> V_362 , V_2 -> V_334 ,
V_921 ,
F_19 ( V_2 -> V_8 [ V_923 ] ) ,
F_20 ( V_2 -> V_8 [ V_923 ] ) ) ;
}
static int F_206 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_38 * V_39 ;
enum V_350 V_351 = V_352 ;
bool V_924 = false ;
T_2 V_353 ;
int V_26 ;
void * V_142 ;
T_12 V_430 ;
struct V_23 * V_37 ;
unsigned int V_925 = 0 ;
bool V_926 ;
if ( ! V_2 -> V_8 [ V_927 ] ||
! V_2 -> V_8 [ V_354 ] )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_265 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_108 &&
V_6 -> V_362 -> V_103 != V_112 &&
V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_105 &&
V_6 -> V_362 -> V_103 != V_107 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_355 ;
if ( V_2 -> V_8 [ V_906 ] ) {
if ( ! V_4 -> V_195 -> V_267 )
return - V_11 ;
V_925 = F_2 ( V_2 -> V_8 [ V_906 ] ) ;
}
if ( V_2 -> V_8 [ V_356 ] ) {
V_351 = F_2 (
V_2 -> V_8 [ V_356 ] ) ;
if ( V_351 != V_352 &&
V_351 != V_357 &&
V_351 != V_358 &&
V_351 != V_359 )
return - V_11 ;
V_924 = true ;
}
V_926 = V_2 -> V_8 [ V_284 ] ;
V_353 = F_2 ( V_2 -> V_8 [ V_354 ] ) ;
V_39 = F_199 ( V_4 , V_353 , V_351 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_928 ) ;
if ( F_6 ( V_142 ) ) {
V_26 = F_8 ( V_142 ) ;
goto V_441;
}
V_26 = F_207 ( V_4 , V_6 , V_39 , V_926 , V_351 ,
V_924 , V_925 ,
F_19 ( V_2 -> V_8 [ V_927 ] ) ,
F_20 ( V_2 -> V_8 [ V_927 ] ) ,
& V_430 ) ;
if ( V_26 )
goto V_441;
F_147 ( V_37 , V_908 , V_430 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_441:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_208 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_12 V_430 ;
if ( ! V_2 -> V_8 [ V_908 ] )
return - V_11 ;
if ( ! V_4 -> V_195 -> V_267 )
return - V_355 ;
if ( V_6 -> V_362 -> V_103 != V_111 &&
V_6 -> V_362 -> V_103 != V_108 &&
V_6 -> V_362 -> V_103 != V_112 &&
V_6 -> V_362 -> V_103 != V_104 &&
V_6 -> V_362 -> V_103 != V_105 &&
V_6 -> V_362 -> V_103 != V_106 )
return - V_355 ;
V_430 = F_201 ( V_2 -> V_8 [ V_908 ] ) ;
return V_4 -> V_195 -> V_267 ( & V_4 -> V_118 , V_6 , V_430 ) ;
}
static int F_209 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
T_1 V_929 ;
bool V_930 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_931 ] )
return - V_11 ;
V_929 = F_2 ( V_2 -> V_8 [ V_931 ] ) ;
if ( V_929 != V_932 && V_929 != V_933 )
return - V_11 ;
V_102 = V_6 -> V_362 ;
if ( ! V_4 -> V_195 -> V_934 )
return - V_355 ;
V_930 = ( V_929 == V_933 ) ? true : false ;
if ( V_930 == V_102 -> V_935 )
return 0 ;
V_26 = V_4 -> V_195 -> V_934 ( V_102 -> V_118 , V_6 , V_930 ,
V_102 -> V_936 ) ;
if ( ! V_26 )
V_102 -> V_935 = V_930 ;
return V_26 ;
}
static int F_210 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
enum V_937 V_929 ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_23 * V_37 ;
void * V_142 ;
int V_26 ;
V_102 = V_6 -> V_362 ;
if ( ! V_4 -> V_195 -> V_934 )
return - V_355 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_938 ) ;
if ( ! V_142 ) {
V_26 = - V_53 ;
goto V_441;
}
if ( V_102 -> V_935 )
V_929 = V_933 ;
else
V_929 = V_932 ;
F_24 ( V_37 , V_931 , V_929 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_441:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_211 ( struct V_1 * V_2 ,
T_13 V_939 , T_2 V_940 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
if ( V_939 > 0 )
return - V_11 ;
V_102 = V_6 -> V_362 ;
if ( ! V_4 -> V_195 -> V_941 )
return - V_355 ;
if ( V_102 -> V_103 != V_111 &&
V_102 -> V_103 != V_112 )
return - V_355 ;
return V_4 -> V_195 -> V_941 ( V_102 -> V_118 , V_6 ,
V_939 , V_940 ) ;
}
static int F_212 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_7 * V_8 [ V_942 + 1 ] ;
struct V_7 * V_943 ;
int V_26 ;
V_943 = V_2 -> V_8 [ V_944 ] ;
if ( ! V_943 ) {
V_26 = - V_11 ;
goto V_402;
}
V_26 = F_28 ( V_8 , V_942 , V_943 ,
V_945 ) ;
if ( V_26 )
goto V_402;
if ( V_8 [ V_946 ] &&
V_8 [ V_947 ] ) {
T_13 V_939 ;
T_2 V_940 ;
V_939 = F_2 ( V_8 [ V_946 ] ) ;
V_940 = F_2 ( V_8 [ V_947 ] ) ;
V_26 = F_211 ( V_2 , V_939 , V_940 ) ;
} else
V_26 = - V_11 ;
V_402:
return V_26 ;
}
static int F_213 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_642 V_679 ;
struct V_683 V_684 ;
int V_26 ;
memcpy ( & V_679 , & V_646 , sizeof( V_679 ) ) ;
memcpy ( & V_684 , & V_948 , sizeof( V_684 ) ) ;
if ( V_2 -> V_8 [ V_648 ] ) {
V_26 = F_123 ( V_2 , & V_679 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_2 -> V_8 [ V_419 ] ||
! F_20 ( V_2 -> V_8 [ V_419 ] ) )
return - V_11 ;
V_684 . V_949 = F_19 ( V_2 -> V_8 [ V_419 ] ) ;
V_684 . V_645 = F_20 ( V_2 -> V_8 [ V_419 ] ) ;
if ( V_2 -> V_8 [ V_686 ] ) {
V_26 = F_125 ( V_2 , & V_684 ) ;
if ( V_26 )
return V_26 ;
}
return F_214 ( V_4 , V_6 , & V_684 , & V_679 ) ;
}
static int F_215 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
return F_216 ( V_4 , V_6 ) ;
}
static int F_217 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_23 * V_37 ;
void * V_142 ;
if ( ! V_4 -> V_118 . V_297 . V_35 && ! V_4 -> V_118 . V_297 . V_298 )
return - V_355 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_334 , V_2 -> V_335 , 0 ,
V_950 ) ;
if ( ! V_142 )
goto V_52;
if ( V_4 -> V_297 ) {
struct V_7 * V_299 ;
V_299 = F_41 ( V_37 , V_951 ) ;
if ( ! V_299 )
goto V_52;
if ( V_4 -> V_297 -> V_952 )
F_25 ( V_37 , V_302 ) ;
if ( V_4 -> V_297 -> V_280 )
F_25 ( V_37 , V_304 ) ;
if ( V_4 -> V_297 -> V_953 )
F_25 ( V_37 , V_306 ) ;
if ( V_4 -> V_297 -> V_954 )
F_25 ( V_37 , V_310 ) ;
if ( V_4 -> V_297 -> V_955 )
F_25 ( V_37 , V_312 ) ;
if ( V_4 -> V_297 -> V_956 )
F_25 ( V_37 , V_314 ) ;
if ( V_4 -> V_297 -> V_957 )
F_25 ( V_37 , V_316 ) ;
if ( V_4 -> V_297 -> V_298 ) {
struct V_7 * V_958 , * V_959 ;
int V_117 , V_960 ;
V_958 = F_41 ( V_37 ,
V_324 ) ;
if ( ! V_958 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_4 -> V_297 -> V_298 ; V_117 ++ ) {
V_959 = F_41 ( V_37 , V_117 + 1 ) ;
if ( ! V_959 )
goto V_52;
V_960 = V_4 -> V_297 -> V_961 [ V_117 ] . V_962 ;
F_49 ( V_37 , V_963 ,
F_218 ( V_960 , 8 ) ,
V_4 -> V_297 -> V_961 [ V_117 ] . V_472 ) ;
F_49 ( V_37 , V_964 ,
V_960 ,
V_4 -> V_297 -> V_961 [ V_117 ] . V_965 ) ;
F_42 ( V_37 , V_959 ) ;
}
F_42 ( V_37 , V_958 ) ;
}
F_42 ( V_37 , V_299 ) ;
}
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_219 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_7 * V_57 [ V_966 ] ;
struct V_967 V_968 = {} ;
struct V_967 V_969 = {} ;
struct V_970 * V_297 = & V_4 -> V_118 . V_297 ;
int V_26 , V_117 ;
if ( ! V_4 -> V_118 . V_297 . V_35 && ! V_4 -> V_118 . V_297 . V_298 )
return - V_355 ;
if ( ! V_2 -> V_8 [ V_951 ] )
goto V_968;
V_26 = F_78 ( V_57 , V_971 ,
F_19 ( V_2 -> V_8 [ V_951 ] ) ,
F_20 ( V_2 -> V_8 [ V_951 ] ) ,
V_972 ) ;
if ( V_26 )
return V_26 ;
if ( V_57 [ V_302 ] ) {
if ( ! ( V_297 -> V_35 & V_301 ) )
return - V_11 ;
V_969 . V_952 = true ;
}
if ( V_57 [ V_304 ] ) {
if ( ! ( V_297 -> V_35 & V_303 ) )
return - V_11 ;
V_969 . V_280 = true ;
}
if ( V_57 [ V_306 ] ) {
if ( ! ( V_297 -> V_35 & V_305 ) )
return - V_11 ;
V_969 . V_953 = true ;
}
if ( V_57 [ V_308 ] )
return - V_11 ;
if ( V_57 [ V_310 ] ) {
if ( ! ( V_297 -> V_35 & V_309 ) )
return - V_11 ;
V_969 . V_954 = true ;
}
if ( V_57 [ V_312 ] ) {
if ( ! ( V_297 -> V_35 & V_311 ) )
return - V_11 ;
V_969 . V_955 = true ;
}
if ( V_57 [ V_314 ] ) {
if ( ! ( V_297 -> V_35 & V_313 ) )
return - V_11 ;
V_969 . V_956 = true ;
}
if ( V_57 [ V_316 ] ) {
if ( ! ( V_297 -> V_35 & V_315 ) )
return - V_11 ;
V_969 . V_957 = true ;
}
if ( V_57 [ V_324 ] ) {
struct V_7 * V_318 ;
int V_298 = 0 ;
int V_96 , V_960 , V_973 ;
struct V_7 * V_974 [ V_975 ] ;
F_35 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_298 ++ ;
if ( V_298 > V_297 -> V_298 )
return - V_11 ;
V_969 . V_961 = F_220 ( V_298 ,
sizeof( V_969 . V_961 [ 0 ] ) ,
V_97 ) ;
if ( ! V_969 . V_961 )
return - V_98 ;
V_969 . V_298 = V_298 ;
V_117 = 0 ;
F_35 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_78 ( V_974 , V_976 ,
F_19 ( V_318 ) , F_20 ( V_318 ) , NULL ) ;
V_26 = - V_11 ;
if ( ! V_974 [ V_963 ] ||
! V_974 [ V_964 ] )
goto error;
V_960 = F_20 ( V_974 [ V_964 ] ) ;
V_973 = F_218 ( V_960 , 8 ) ;
if ( F_20 ( V_974 [ V_963 ] ) !=
V_973 )
goto error;
if ( V_960 > V_297 -> V_323 ||
V_960 < V_297 -> V_321 )
goto error;
V_969 . V_961 [ V_117 ] . V_472 =
F_221 ( V_973 + V_960 , V_97 ) ;
if ( ! V_969 . V_961 [ V_117 ] . V_472 ) {
V_26 = - V_98 ;
goto error;
}
V_969 . V_961 [ V_117 ] . V_965 =
V_969 . V_961 [ V_117 ] . V_472 + V_973 ;
memcpy ( V_969 . V_961 [ V_117 ] . V_472 ,
F_19 ( V_974 [ V_963 ] ) ,
V_973 ) ;
V_969 . V_961 [ V_117 ] . V_962 = V_960 ;
memcpy ( V_969 . V_961 [ V_117 ] . V_965 ,
F_19 ( V_974 [ V_964 ] ) ,
V_960 ) ;
V_117 ++ ;
}
}
if ( memcmp ( & V_969 , & V_968 , sizeof( V_969 ) ) ) {
struct V_967 * V_977 ;
V_977 = F_222 ( & V_969 , sizeof( V_969 ) ,
V_97 ) ;
if ( ! V_977 ) {
V_26 = - V_98 ;
goto error;
}
F_223 ( V_4 ) ;
V_4 -> V_297 = V_977 ;
} else {
V_968:
F_223 ( V_4 ) ;
V_4 -> V_297 = NULL ;
}
return 0 ;
error:
for ( V_117 = 0 ; V_117 < V_969 . V_298 ; V_117 ++ )
F_37 ( V_969 . V_961 [ V_117 ] . V_472 ) ;
F_37 ( V_969 . V_961 ) ;
return V_26 ;
}
static int F_224 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_332 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_332 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_362 ;
struct V_7 * V_57 [ V_978 ] ;
struct V_979 V_980 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_981 ] )
return - V_11 ;
V_26 = F_78 ( V_57 , V_982 ,
F_19 ( V_2 -> V_8 [ V_981 ] ) ,
F_20 ( V_2 -> V_8 [ V_981 ] ) ,
V_983 ) ;
if ( V_26 )
return V_26 ;
if ( F_20 ( V_57 [ V_984 ] ) != V_985 )
return - V_986 ;
if ( F_20 ( V_57 [ V_987 ] ) != V_988 )
return - V_986 ;
if ( F_20 ( V_57 [ V_989 ] ) != V_990 )
return - V_986 ;
memcpy ( V_980 . V_991 , F_19 ( V_57 [ V_987 ] ) ,
V_988 ) ;
memcpy ( V_980 . V_992 , F_19 ( V_57 [ V_989 ] ) ,
V_990 ) ;
memcpy ( V_980 . V_993 ,
F_19 ( V_57 [ V_984 ] ) ,
V_985 ) ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_109 ) {
V_26 = - V_994 ;
goto V_402;
}
if ( ! V_4 -> V_195 -> V_995 ) {
V_26 = - V_355 ;
goto V_402;
}
V_26 = V_4 -> V_195 -> V_995 ( & V_4 -> V_118 , V_6 , & V_980 ) ;
V_402:
F_70 ( V_102 ) ;
return V_26 ;
}
static int F_225 ( struct V_996 * V_195 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_26 ;
bool V_997 = V_195 -> V_998 & V_999 ;
if ( V_997 )
F_12 () ;
if ( V_195 -> V_998 & V_1000 ) {
V_4 = F_226 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
if ( V_997 )
F_15 () ;
return F_8 ( V_4 ) ;
}
V_2 -> V_332 [ 0 ] = V_4 ;
} else if ( V_195 -> V_998 & V_1001 ) {
V_26 = F_1 ( V_2 , & V_4 , & V_6 ) ;
if ( V_26 ) {
if ( V_997 )
F_15 () ;
return V_26 ;
}
if ( V_195 -> V_998 & V_1002 &&
! F_73 ( V_6 ) ) {
F_17 ( V_4 ) ;
F_7 ( V_6 ) ;
if ( V_997 )
F_15 () ;
return - V_556 ;
}
V_2 -> V_332 [ 0 ] = V_4 ;
V_2 -> V_332 [ 1 ] = V_6 ;
}
return 0 ;
}
static void F_227 ( struct V_996 * V_195 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_332 [ 0 ] )
F_17 ( V_2 -> V_332 [ 0 ] ) ;
if ( V_2 -> V_332 [ 1 ] )
F_7 ( V_2 -> V_332 [ 1 ] ) ;
if ( V_195 -> V_998 & V_999 )
F_15 () ;
}
void F_228 ( struct V_3 * V_4 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_44 ( V_37 , 0 , 0 , 0 , V_4 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1003 . V_891 , V_97 ) ;
}
static int F_230 ( struct V_23 * V_37 ,
struct V_3 * V_4 )
{
struct V_727 * V_1004 = V_4 -> V_733 ;
struct V_7 * V_1005 ;
int V_117 ;
F_231 ( V_4 ) ;
if ( F_98 ( ! V_1004 ) )
return 0 ;
V_1005 = F_41 ( V_37 , V_735 ) ;
if ( ! V_1005 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_1004 -> V_730 ; V_117 ++ )
F_49 ( V_37 , V_117 , V_1004 -> V_736 [ V_117 ] . V_738 , V_1004 -> V_736 [ V_117 ] . V_423 ) ;
F_42 ( V_37 , V_1005 ) ;
V_1005 = F_41 ( V_37 , V_734 ) ;
if ( ! V_1005 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_1004 -> V_217 ; V_117 ++ )
F_24 ( V_37 , V_117 , V_1004 -> V_218 [ V_117 ] -> V_41 ) ;
F_42 ( V_37 , V_1005 ) ;
if ( V_1004 -> V_698 )
F_49 ( V_37 , V_731 , V_1004 -> V_699 , V_1004 -> V_698 ) ;
return 0 ;
V_52:
return - V_53 ;
}
static int F_232 ( struct V_23 * V_37 ,
struct V_3 * V_4 ,
struct V_5 * V_361 ,
T_2 V_33 , T_2 V_34 , int V_35 ,
T_2 V_36 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_230 ( V_37 , V_4 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
static int
F_233 ( struct V_23 * V_37 ,
struct V_3 * V_4 ,
struct V_5 * V_361 ,
T_2 V_33 , T_2 V_34 , int V_35 , T_2 V_36 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_327 ;
}
void F_138 ( struct V_3 * V_4 ,
struct V_5 * V_361 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1006 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_232 ( V_37 , V_4 , V_361 , 0 , 0 , 0 ,
V_1007 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1008 . V_891 , V_97 ) ;
}
void F_234 ( struct V_3 * V_4 ,
struct V_5 * V_361 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_232 ( V_37 , V_4 , V_361 , 0 , 0 , 0 ,
V_752 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1008 . V_891 , V_97 ) ;
}
void F_235 ( struct V_3 * V_4 ,
struct V_5 * V_361 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_232 ( V_37 , V_4 , V_361 , 0 , 0 , 0 ,
V_1009 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1008 . V_891 , V_97 ) ;
}
void F_236 ( struct V_3 * V_4 ,
struct V_5 * V_361 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_233 ( V_37 , V_4 , V_361 , 0 , 0 , 0 ,
V_1010 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1008 . V_891 , V_97 ) ;
}
void F_141 ( struct V_3 * V_4 ,
struct V_5 * V_361 , T_2 V_36 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1006 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_233 ( V_37 , V_4 , V_361 , 0 , 0 , 0 , V_36 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1008 . V_891 , V_97 ) ;
}
void F_237 ( struct V_1011 * V_728 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_97 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1012 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_47 ( V_37 , V_1013 , V_728 -> V_1014 ) ;
if ( V_728 -> V_707 [ 0 ] == '0' && V_728 -> V_707 [ 1 ] == '0' )
F_47 ( V_37 , V_1015 ,
V_1016 ) ;
else if ( V_728 -> V_707 [ 0 ] == '9' && V_728 -> V_707 [ 1 ] == '9' )
F_47 ( V_37 , V_1015 ,
V_1017 ) ;
else if ( ( V_728 -> V_707 [ 0 ] == '9' && V_728 -> V_707 [ 1 ] == '8' ) ||
V_728 -> V_1018 )
F_47 ( V_37 , V_1015 ,
V_1019 ) ;
else {
F_47 ( V_37 , V_1015 ,
V_1020 ) ;
F_45 ( V_37 , V_641 , V_728 -> V_707 ) ;
}
if ( F_238 ( V_728 -> V_158 ) )
F_24 ( V_37 , V_157 , V_728 -> V_158 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_239 () ;
F_240 ( V_37 , 0 , V_1021 . V_891 ,
V_1022 ) ;
F_241 () ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static void F_242 ( struct V_3 * V_4 ,
struct V_5 * V_361 ,
const T_1 * V_1023 , T_10 V_31 ,
enum V_1024 V_36 , T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_49 ( V_37 , V_927 , V_31 , V_1023 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_243 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1023 ,
T_10 V_31 , T_11 V_889 )
{
F_242 ( V_4 , V_361 , V_1023 , V_31 ,
V_1026 , V_889 ) ;
}
void F_244 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1023 ,
T_10 V_31 , T_11 V_889 )
{
F_242 ( V_4 , V_361 , V_1023 , V_31 ,
V_1027 , V_889 ) ;
}
void F_245 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1023 ,
T_10 V_31 , T_11 V_889 )
{
F_242 ( V_4 , V_361 , V_1023 , V_31 ,
V_1028 , V_889 ) ;
}
void F_246 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1023 ,
T_10 V_31 , T_11 V_889 )
{
F_242 ( V_4 , V_361 , V_1023 , V_31 ,
V_1029 , V_889 ) ;
}
void F_247 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1023 ,
T_10 V_31 , T_11 V_889 )
{
F_242 ( V_4 , V_361 , V_1023 , V_31 ,
V_1030 , V_889 ) ;
}
void F_248 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1023 ,
T_10 V_31 , T_11 V_889 )
{
F_242 ( V_4 , V_361 , V_1023 , V_31 ,
V_1031 , V_889 ) ;
}
static void F_249 ( struct V_3 * V_4 ,
struct V_5 * V_361 , int V_36 ,
const T_1 * V_1032 , T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_25 ( V_37 , V_1033 ) ;
F_49 ( V_37 , V_364 , V_439 , V_1032 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_250 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1032 ,
T_11 V_889 )
{
F_249 ( V_4 , V_361 , V_1026 ,
V_1032 , V_889 ) ;
}
void F_251 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1032 ,
T_11 V_889 )
{
F_249 ( V_4 , V_361 , V_1027 ,
V_1032 , V_889 ) ;
}
void F_252 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_363 ,
const T_1 * V_1034 , T_10 V_1035 ,
const T_1 * V_1036 , T_10 V_1037 ,
T_3 V_1038 , T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1006 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_279 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
if ( V_363 )
F_49 ( V_37 , V_364 , V_439 , V_363 ) ;
F_48 ( V_37 , V_1039 , V_1038 ) ;
if ( V_1034 )
F_49 ( V_37 , V_1040 , V_1035 , V_1034 ) ;
if ( V_1036 )
F_49 ( V_37 , V_1041 , V_1037 , V_1036 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_253 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_363 ,
const T_1 * V_1034 , T_10 V_1035 ,
const T_1 * V_1036 , T_10 V_1037 , T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1006 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1042 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_363 ) ;
if ( V_1034 )
F_49 ( V_37 , V_1040 , V_1035 , V_1034 ) ;
if ( V_1036 )
F_49 ( V_37 , V_1041 , V_1037 , V_1036 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_254 ( struct V_3 * V_4 ,
struct V_5 * V_361 , T_3 V_895 ,
const T_1 * V_698 , T_10 V_699 , bool V_1043 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1006 , V_97 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_281 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
if ( V_1043 && V_895 )
F_48 ( V_37 , V_863 , V_895 ) ;
if ( V_1043 )
F_25 ( V_37 , V_1044 ) ;
if ( V_698 )
F_49 ( V_37 , V_731 , V_699 , V_698 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_97 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_255 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_363 ,
T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1045 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_363 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_256 ( struct V_3 * V_4 ,
struct V_5 * V_361 ,
const T_1 * V_1046 , const T_1 * V_698 , T_1 V_699 ,
T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1047 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_1046 ) ;
if ( V_699 && V_698 )
F_49 ( V_37 , V_731 , V_699 , V_698 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_257 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1032 ,
enum V_1048 V_1049 , int V_1050 ,
const T_1 * V_1051 , T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1052 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
if ( V_1032 )
F_49 ( V_37 , V_364 , V_439 , V_1032 ) ;
F_24 ( V_37 , V_89 , V_1049 ) ;
if ( V_1050 != - 1 )
F_47 ( V_37 , V_85 , V_1050 ) ;
if ( V_1051 )
F_49 ( V_37 , V_84 , 6 , V_1051 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_258 ( struct V_118 * V_118 ,
struct V_38 * V_1053 ,
struct V_38 * V_1054 )
{
struct V_23 * V_37 ;
void * V_142 ;
struct V_7 * V_146 ;
V_37 = F_61 ( V_333 , V_1022 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1055 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , F_259 ( V_118 ) ) ;
V_146 = F_41 ( V_37 , V_1056 ) ;
if ( ! V_146 )
goto V_52;
if ( F_23 ( V_37 , V_1053 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
V_146 = F_41 ( V_37 , V_1057 ) ;
if ( ! V_146 )
goto V_52;
if ( F_23 ( V_37 , V_1054 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_239 () ;
F_240 ( V_37 , 0 , V_1021 . V_891 ,
V_1022 ) ;
F_241 () ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static void F_260 (
int V_36 , struct V_3 * V_4 ,
struct V_5 * V_361 , T_12 V_430 ,
struct V_38 * V_39 ,
enum V_350 V_351 ,
unsigned int V_905 , T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_24 ( V_37 , V_354 , V_39 -> V_41 ) ;
F_24 ( V_37 , V_356 , V_351 ) ;
F_147 ( V_37 , V_908 , V_430 ) ;
if ( V_36 == V_907 )
F_24 ( V_37 , V_906 , V_905 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_261 ( struct V_3 * V_4 ,
struct V_5 * V_361 , T_12 V_430 ,
struct V_38 * V_39 ,
enum V_350 V_351 ,
unsigned int V_905 , T_11 V_889 )
{
F_260 ( V_907 ,
V_4 , V_361 , V_430 , V_39 ,
V_351 , V_905 , V_889 ) ;
}
void F_262 (
struct V_3 * V_4 , struct V_5 * V_361 ,
T_12 V_430 , struct V_38 * V_39 ,
enum V_350 V_351 , T_11 V_889 )
{
F_260 ( V_1058 ,
V_4 , V_361 , V_430 , V_39 ,
V_351 , 0 , V_889 ) ;
}
void F_263 ( struct V_3 * V_4 ,
struct V_5 * V_6 , const T_1 * V_432 ,
struct V_487 * V_488 , T_11 V_889 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1006 , V_889 ) ;
if ( ! V_37 )
return;
if ( F_104 ( V_37 , 0 , 0 , 0 , V_6 , V_432 , V_488 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
}
void F_264 ( struct V_3 * V_4 ,
struct V_5 * V_6 , const T_1 * V_432 ,
T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_1006 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1059 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_432 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
int F_265 ( struct V_3 * V_4 ,
struct V_5 * V_361 , T_2 V_1060 ,
int V_353 , const T_1 * V_1023 , T_10 V_31 , T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
int V_26 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_928 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return - V_98 ;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_24 ( V_37 , V_354 , V_353 ) ;
F_49 ( V_37 , V_927 , V_31 , V_1023 ) ;
V_26 = F_51 ( V_37 , V_142 ) ;
if ( V_26 < 0 ) {
F_62 ( V_37 ) ;
return V_26 ;
}
V_26 = F_266 ( F_57 ( & V_4 -> V_118 ) , V_37 , V_1060 ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
return - V_53 ;
}
void F_267 ( struct V_3 * V_4 ,
struct V_5 * V_361 , T_12 V_430 ,
const T_1 * V_1023 , T_10 V_31 , bool V_1061 ,
T_11 V_889 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_333 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1062 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_49 ( V_37 , V_927 , V_31 , V_1023 ) ;
F_147 ( V_37 , V_908 , V_430 ) ;
if ( V_1061 )
F_25 ( V_37 , V_1063 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_185 ( V_37 , 0 , V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void
F_268 ( struct V_3 * V_4 ,
struct V_5 * V_361 ,
enum V_1064 V_1065 ,
T_11 V_889 )
{
struct V_23 * V_37 ;
struct V_7 * V_579 ;
void * V_142 ;
V_37 = F_61 ( V_1006 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1066 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
V_579 = F_41 ( V_37 , V_944 ) ;
if ( ! V_579 )
goto V_52;
F_24 ( V_37 , V_1067 ,
V_1065 ) ;
F_42 ( V_37 , V_579 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_269 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_363 ,
const T_1 * V_993 , T_11 V_889 )
{
struct V_23 * V_37 ;
struct V_7 * V_1068 ;
void * V_142 ;
V_37 = F_61 ( V_1006 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1069 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_363 ) ;
V_1068 = F_41 ( V_37 , V_981 ) ;
if ( ! V_1068 )
goto V_52;
F_49 ( V_37 , V_984 ,
V_985 , V_993 ) ;
F_42 ( V_37 , V_1068 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void
F_270 ( struct V_3 * V_4 ,
struct V_5 * V_361 , const T_1 * V_1070 ,
T_2 V_1071 , T_11 V_889 )
{
struct V_23 * V_37 ;
struct V_7 * V_579 ;
void * V_142 ;
V_37 = F_61 ( V_1006 , V_889 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1066 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_361 -> V_9 ) ;
F_49 ( V_37 , V_364 , V_439 , V_1070 ) ;
V_579 = F_41 ( V_37 , V_944 ) ;
if ( ! V_579 )
goto V_52;
F_24 ( V_37 , V_1072 , V_1071 ) ;
F_42 ( V_37 , V_579 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_229 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_1025 . V_891 , V_889 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static int F_271 ( struct V_1073 * V_1074 ,
unsigned long V_930 ,
void * V_1075 )
{
struct V_1076 * V_1077 = V_1075 ;
struct V_3 * V_4 ;
struct V_101 * V_102 ;
if ( V_930 != V_1078 )
return V_1079 ;
F_239 () ;
F_272 (rdev, &cfg80211_rdev_list, list)
F_272 (wdev, &rdev->netdev_list, list)
F_273 ( V_102 , V_1077 -> V_33 ) ;
F_241 () ;
return V_1079 ;
}
int F_274 ( void )
{
int V_26 ;
V_26 = F_275 ( & V_18 ,
V_1080 , F_276 ( V_1080 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_277 ( & V_18 , & V_1003 ) ;
if ( V_26 )
goto V_1081;
V_26 = F_277 ( & V_18 , & V_1008 ) ;
if ( V_26 )
goto V_1081;
V_26 = F_277 ( & V_18 , & V_1021 ) ;
if ( V_26 )
goto V_1081;
V_26 = F_277 ( & V_18 , & V_1025 ) ;
if ( V_26 )
goto V_1081;
#ifdef F_278
V_26 = F_277 ( & V_18 , & V_890 ) ;
if ( V_26 )
goto V_1081;
#endif
V_26 = F_279 ( & V_1082 ) ;
if ( V_26 )
goto V_1081;
return 0 ;
V_1081:
F_280 ( & V_18 ) ;
return V_26 ;
}
void F_281 ( void )
{
F_282 ( & V_1082 ) ;
F_280 ( & V_18 ) ;
}
