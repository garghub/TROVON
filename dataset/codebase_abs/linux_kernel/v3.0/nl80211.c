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
F_48 ( V_37 , V_174 ,
V_6 -> V_118 . V_175 ) ;
if ( V_6 -> V_118 . V_35 & V_176 )
F_25 ( V_37 , V_177 ) ;
if ( V_6 -> V_118 . V_35 & V_178 )
F_25 ( V_37 , V_179 ) ;
F_49 ( V_37 , V_180 ,
sizeof( T_2 ) * V_6 -> V_118 . V_181 ,
V_6 -> V_118 . V_182 ) ;
F_47 ( V_37 , V_183 ,
V_6 -> V_118 . V_184 ) ;
if ( V_6 -> V_118 . V_35 & V_185 )
F_25 ( V_37 , V_186 ) ;
F_24 ( V_37 , V_187 ,
V_6 -> V_118 . V_188 ) ;
F_24 ( V_37 , V_189 ,
V_6 -> V_118 . V_190 ) ;
if ( ( V_6 -> V_118 . V_188 ||
V_6 -> V_118 . V_190 ) && V_6 -> V_191 -> V_192 ) {
T_2 V_193 = 0 , V_194 = 0 ;
int V_15 ;
V_15 = V_6 -> V_191 -> V_192 ( & V_6 -> V_118 , & V_193 , & V_194 ) ;
if ( ! V_15 ) {
F_24 ( V_37 , V_195 , V_193 ) ;
F_24 ( V_37 , V_196 , V_194 ) ;
}
}
if ( F_40 ( V_37 , V_197 ,
V_6 -> V_118 . V_198 ) )
goto V_52;
V_143 = F_41 ( V_37 , V_199 ) ;
if ( ! V_143 )
goto V_52;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
if ( ! V_6 -> V_118 . V_201 [ V_151 ] )
continue;
V_144 = F_41 ( V_37 , V_151 ) ;
if ( ! V_144 )
goto V_52;
if ( V_6 -> V_118 . V_201 [ V_151 ] -> V_202 . V_203 ) {
F_49 ( V_37 , V_204 ,
sizeof( V_6 -> V_118 . V_201 [ V_151 ] -> V_202 . V_205 ) ,
& V_6 -> V_118 . V_201 [ V_151 ] -> V_202 . V_205 ) ;
F_48 ( V_37 , V_206 ,
V_6 -> V_118 . V_201 [ V_151 ] -> V_202 . V_207 ) ;
F_47 ( V_37 , V_208 ,
V_6 -> V_118 . V_201 [ V_151 ] -> V_202 . V_209 ) ;
F_47 ( V_37 , V_210 ,
V_6 -> V_118 . V_201 [ V_151 ] -> V_202 . V_211 ) ;
}
V_145 = F_41 ( V_37 , V_212 ) ;
if ( ! V_145 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_6 -> V_118 . V_201 [ V_151 ] -> V_213 ; V_117 ++ ) {
V_146 = F_41 ( V_37 , V_117 ) ;
if ( ! V_146 )
goto V_52;
V_39 = & V_6 -> V_118 . V_201 [ V_151 ] -> V_214 [ V_117 ] ;
if ( F_23 ( V_37 , V_39 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
}
F_42 ( V_37 , V_145 ) ;
V_147 = F_41 ( V_37 , V_215 ) ;
if ( ! V_147 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_6 -> V_118 . V_201 [ V_151 ] -> V_216 ; V_117 ++ ) {
V_148 = F_41 ( V_37 , V_117 ) ;
if ( ! V_148 )
goto V_52;
V_153 = & V_6 -> V_118 . V_201 [ V_151 ] -> V_217 [ V_117 ] ;
F_24 ( V_37 , V_218 ,
V_153 -> V_219 ) ;
if ( V_153 -> V_35 & V_220 )
F_25 ( V_37 ,
V_221 ) ;
F_42 ( V_37 , V_148 ) ;
}
F_42 ( V_37 , V_147 ) ;
F_42 ( V_37 , V_144 ) ;
}
F_42 ( V_37 , V_143 ) ;
V_149 = F_41 ( V_37 , V_222 ) ;
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
F_50 ( V_223 , V_224 ) ;
F_50 ( V_225 , V_226 ) ;
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
if ( V_6 -> V_118 . V_35 & V_265 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_266 ) ;
}
F_50 ( V_267 , V_268 ) ;
F_50 ( V_269 , V_270 ) ;
if ( V_6 -> V_118 . V_35 & V_271 )
F_50 ( V_272 , V_273 ) ;
#undef F_50
if ( V_6 -> V_191 -> V_274 || V_6 -> V_191 -> V_239 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_275 ) ;
}
if ( V_6 -> V_191 -> V_276 || V_6 -> V_191 -> V_243 ) {
V_117 ++ ;
F_24 ( V_37 , V_117 , V_277 ) ;
}
F_42 ( V_37 , V_149 ) ;
if ( V_6 -> V_191 -> V_257 )
F_24 ( V_37 , V_278 ,
V_6 -> V_118 . V_279 ) ;
if ( V_6 -> V_191 -> V_261 )
F_25 ( V_37 , V_280 ) ;
if ( V_155 ) {
T_3 V_281 ;
struct V_7 * V_282 , * V_283 ;
enum V_284 V_285 ;
V_283 = F_41 ( V_37 , V_286 ) ;
if ( ! V_283 )
goto V_52;
for ( V_285 = 0 ; V_285 < V_287 ; V_285 ++ ) {
V_282 = F_41 ( V_37 , V_285 ) ;
if ( ! V_282 )
goto V_52;
V_117 = 0 ;
V_281 = V_155 [ V_285 ] . V_288 ;
while ( V_281 ) {
if ( V_281 & 1 )
F_48 ( V_37 , V_289 ,
( V_117 << 4 ) | V_290 ) ;
V_281 >>= 1 ;
V_117 ++ ;
}
F_42 ( V_37 , V_282 ) ;
}
F_42 ( V_37 , V_283 ) ;
V_283 = F_41 ( V_37 , V_291 ) ;
if ( ! V_283 )
goto V_52;
for ( V_285 = 0 ; V_285 < V_287 ; V_285 ++ ) {
V_282 = F_41 ( V_37 , V_285 ) ;
if ( ! V_282 )
goto V_52;
V_117 = 0 ;
V_281 = V_155 [ V_285 ] . V_292 ;
while ( V_281 ) {
if ( V_281 & 1 )
F_48 ( V_37 , V_289 ,
( V_117 << 4 ) | V_290 ) ;
V_281 >>= 1 ;
V_117 ++ ;
}
F_42 ( V_37 , V_282 ) ;
}
F_42 ( V_37 , V_283 ) ;
}
if ( V_6 -> V_118 . V_293 . V_35 || V_6 -> V_118 . V_293 . V_294 ) {
struct V_7 * V_295 ;
V_295 = F_41 ( V_37 ,
V_296 ) ;
if ( ! V_295 )
goto V_52;
if ( V_6 -> V_118 . V_293 . V_35 & V_297 )
F_25 ( V_37 , V_298 ) ;
if ( V_6 -> V_118 . V_293 . V_35 & V_299 )
F_25 ( V_37 , V_300 ) ;
if ( V_6 -> V_118 . V_293 . V_35 & V_301 )
F_25 ( V_37 , V_302 ) ;
if ( V_6 -> V_118 . V_293 . V_294 ) {
struct V_303 V_304 = {
. V_305 = V_6 -> V_118 . V_293 . V_294 ,
. V_306 =
V_6 -> V_118 . V_293 . V_307 ,
. V_308 =
V_6 -> V_118 . V_293 . V_309 ,
} ;
F_49 ( V_37 , V_310 ,
sizeof( V_304 ) , & V_304 ) ;
}
F_42 ( V_37 , V_295 ) ;
}
if ( F_40 ( V_37 , V_311 ,
V_6 -> V_118 . V_312 ) )
goto V_52;
if ( F_43 ( & V_6 -> V_118 , V_37 ) )
goto V_52;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
static int F_53 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_67 = 0 ;
int V_314 = V_14 -> args [ 0 ] ;
struct V_3 * V_6 ;
F_54 ( & V_315 ) ;
F_55 (dev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_6 -> V_118 ) , F_14 ( V_24 -> V_27 ) ) )
continue;
if ( ++ V_67 <= V_314 )
continue;
if ( F_44 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_316 , V_317 ,
V_6 ) < 0 ) {
V_67 -- ;
break;
}
}
F_59 ( & V_315 ) ;
V_14 -> args [ 0 ] = V_67 ;
return V_24 -> V_31 ;
}
static int F_60 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
struct V_3 * V_6 = V_2 -> V_318 [ 0 ] ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_44 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 , V_6 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_64 ( struct V_7 * V_57 [] ,
struct V_322 * V_323 )
{
if ( ! V_57 [ V_324 ] || ! V_57 [ V_325 ] ||
! V_57 [ V_326 ] || ! V_57 [ V_327 ] ||
! V_57 [ V_328 ] )
return - V_11 ;
V_323 -> V_329 = F_29 ( V_57 [ V_324 ] ) ;
V_323 -> V_330 = F_65 ( V_57 [ V_325 ] ) ;
V_323 -> V_331 = F_65 ( V_57 [ V_326 ] ) ;
V_323 -> V_332 = F_65 ( V_57 [ V_327 ] ) ;
V_323 -> V_333 = F_29 ( V_57 [ V_328 ] ) ;
return 0 ;
}
static bool F_66 ( struct V_101 * V_102 )
{
return ! V_102 ||
V_102 -> V_103 == V_104 ||
V_102 -> V_103 == V_334 ||
V_102 -> V_103 == V_107 ||
V_102 -> V_103 == V_335 ||
V_102 -> V_103 == V_106 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_1 * V_2 )
{
enum V_336 V_337 = V_338 ;
T_2 V_339 ;
int V_95 ;
if ( ! V_2 -> V_8 [ V_340 ] )
return - V_11 ;
if ( ! F_66 ( V_102 ) )
return - V_341 ;
if ( V_2 -> V_8 [ V_342 ] ) {
V_337 = F_2 ( V_2 -> V_8 [
V_342 ] ) ;
if ( V_337 != V_338 &&
V_337 != V_343 &&
V_337 != V_344 &&
V_337 != V_345 )
return - V_11 ;
}
V_339 = F_2 ( V_2 -> V_8 [ V_340 ] ) ;
F_54 ( & V_4 -> V_346 ) ;
if ( V_102 ) {
F_68 ( V_102 ) ;
V_95 = F_69 ( V_4 , V_102 , V_339 , V_337 ) ;
F_70 ( V_102 ) ;
} else {
V_95 = F_69 ( V_4 , NULL , V_339 , V_337 ) ;
}
F_59 ( & V_4 -> V_346 ) ;
return V_95 ;
}
static int F_71 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_347 = V_2 -> V_318 [ 1 ] ;
return F_67 ( V_4 , V_347 -> V_348 , V_2 ) ;
}
static int F_72 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_348 ;
const T_1 * V_349 ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( F_73 ( V_6 ) )
return - V_351 ;
if ( ! V_4 -> V_191 -> V_269 )
return - V_341 ;
if ( V_102 -> V_103 != V_334 )
return - V_341 ;
V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
return V_4 -> V_191 -> V_269 ( V_102 -> V_118 , V_6 , V_349 ) ;
}
static int F_74 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_347 = NULL ;
struct V_101 * V_102 ;
int V_95 = 0 , V_352 = 0 ;
struct V_7 * V_353 ;
T_2 V_354 ;
T_1 V_163 = 0 , V_165 = 0 ;
T_2 V_167 = 0 , V_169 = 0 ;
T_1 V_171 = 0 ;
F_54 ( & V_315 ) ;
if ( V_2 -> V_8 [ V_10 ] ) {
int V_9 = F_2 ( V_2 -> V_8 [ V_10 ] ) ;
V_347 = F_3 ( F_4 ( V_2 ) , V_9 ) ;
if ( V_347 && V_347 -> V_348 ) {
V_4 = F_75 ( V_347 -> V_348 -> V_118 ) ;
F_54 ( & V_4 -> V_355 ) ;
} else
V_347 = NULL ;
}
if ( ! V_347 ) {
V_4 = F_76 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_59 ( & V_315 ) ;
return F_8 ( V_4 ) ;
}
V_102 = NULL ;
V_347 = NULL ;
V_95 = 0 ;
F_54 ( & V_4 -> V_355 ) ;
} else if ( F_73 ( V_347 ) &&
F_66 ( V_347 -> V_348 ) )
V_102 = V_347 -> V_348 ;
else
V_102 = NULL ;
if ( V_2 -> V_8 [ V_159 ] )
V_95 = F_77 (
V_4 , F_19 ( V_2 -> V_8 [ V_159 ] ) ) ;
F_59 ( & V_315 ) ;
if ( V_95 )
goto V_356;
if ( V_2 -> V_8 [ V_357 ] ) {
struct V_322 V_323 ;
struct V_7 * V_57 [ V_358 + 1 ] ;
if ( ! V_4 -> V_191 -> V_359 ) {
V_95 = - V_341 ;
goto V_356;
}
F_35 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_78 ( V_57 , V_358 ,
F_19 ( V_353 ) ,
F_20 ( V_353 ) ,
V_360 ) ;
V_95 = F_64 ( V_57 , & V_323 ) ;
if ( V_95 )
goto V_356;
V_95 = V_4 -> V_191 -> V_359 ( & V_4 -> V_118 ,
& V_323 ) ;
if ( V_95 )
goto V_356;
}
}
if ( V_2 -> V_8 [ V_340 ] ) {
V_95 = F_67 ( V_4 , V_102 , V_2 ) ;
if ( V_95 )
goto V_356;
}
if ( V_2 -> V_8 [ V_361 ] ) {
enum V_362 type ;
int V_67 , V_363 = 0 ;
if ( ! V_4 -> V_191 -> V_364 ) {
V_95 = - V_341 ;
goto V_356;
}
V_67 = V_361 ;
type = F_2 ( V_2 -> V_8 [ V_67 ] ) ;
if ( ! V_2 -> V_8 [ V_365 ] &&
( type != V_366 ) ) {
V_95 = - V_11 ;
goto V_356;
}
if ( type != V_366 ) {
V_67 = V_365 ;
V_363 = F_2 ( V_2 -> V_8 [ V_67 ] ) ;
}
V_95 = V_4 -> V_191 -> V_364 ( & V_4 -> V_118 , type , V_363 ) ;
if ( V_95 )
goto V_356;
}
if ( V_2 -> V_8 [ V_195 ] &&
V_2 -> V_8 [ V_196 ] ) {
T_2 V_193 , V_194 ;
if ( ( ! V_4 -> V_118 . V_188 &&
! V_4 -> V_118 . V_190 ) ||
! V_4 -> V_191 -> V_367 ) {
V_95 = - V_341 ;
goto V_356;
}
V_193 = F_2 ( V_2 -> V_8 [ V_195 ] ) ;
V_194 = F_2 ( V_2 -> V_8 [ V_196 ] ) ;
if ( ( ~ V_193 && ( V_193 & ~ V_4 -> V_118 . V_188 ) ) ||
( ~ V_194 && ( V_194 & ~ V_4 -> V_118 . V_190 ) ) ) {
V_95 = - V_11 ;
goto V_356;
}
V_193 = V_193 & V_4 -> V_118 . V_188 ;
V_194 = V_194 & V_4 -> V_118 . V_190 ;
V_95 = V_4 -> V_191 -> V_367 ( & V_4 -> V_118 , V_193 , V_194 ) ;
if ( V_95 )
goto V_356;
}
V_354 = 0 ;
if ( V_2 -> V_8 [ V_162 ] ) {
V_163 = F_29 (
V_2 -> V_8 [ V_162 ] ) ;
if ( V_163 == 0 ) {
V_95 = - V_11 ;
goto V_356;
}
V_354 |= V_368 ;
}
if ( V_2 -> V_8 [ V_164 ] ) {
V_165 = F_29 (
V_2 -> V_8 [ V_164 ] ) ;
if ( V_165 == 0 ) {
V_95 = - V_11 ;
goto V_356;
}
V_354 |= V_369 ;
}
if ( V_2 -> V_8 [ V_166 ] ) {
V_167 = F_2 (
V_2 -> V_8 [ V_166 ] ) ;
if ( V_167 < 256 ) {
V_95 = - V_11 ;
goto V_356;
}
if ( V_167 != ( T_2 ) - 1 ) {
V_167 &= ~ 0x1 ;
}
V_354 |= V_370 ;
}
if ( V_2 -> V_8 [ V_168 ] ) {
V_169 = F_2 (
V_2 -> V_8 [ V_168 ] ) ;
V_354 |= V_371 ;
}
if ( V_2 -> V_8 [ V_170 ] ) {
V_171 = F_29 (
V_2 -> V_8 [ V_170 ] ) ;
V_354 |= V_372 ;
}
if ( V_354 ) {
T_1 V_373 , V_374 ;
T_2 V_375 , V_376 ;
T_1 V_377 ;
if ( ! V_4 -> V_191 -> V_378 ) {
V_95 = - V_341 ;
goto V_356;
}
V_373 = V_4 -> V_118 . V_163 ;
V_374 = V_4 -> V_118 . V_165 ;
V_375 = V_4 -> V_118 . V_167 ;
V_376 = V_4 -> V_118 . V_169 ;
V_377 = V_4 -> V_118 . V_171 ;
if ( V_354 & V_368 )
V_4 -> V_118 . V_163 = V_163 ;
if ( V_354 & V_369 )
V_4 -> V_118 . V_165 = V_165 ;
if ( V_354 & V_370 )
V_4 -> V_118 . V_167 = V_167 ;
if ( V_354 & V_371 )
V_4 -> V_118 . V_169 = V_169 ;
if ( V_354 & V_372 )
V_4 -> V_118 . V_171 = V_171 ;
V_95 = V_4 -> V_191 -> V_378 ( & V_4 -> V_118 , V_354 ) ;
if ( V_95 ) {
V_4 -> V_118 . V_163 = V_373 ;
V_4 -> V_118 . V_165 = V_374 ;
V_4 -> V_118 . V_167 = V_375 ;
V_4 -> V_118 . V_169 = V_376 ;
V_4 -> V_118 . V_171 = V_377 ;
}
}
V_356:
F_59 ( & V_4 -> V_355 ) ;
if ( V_347 )
F_7 ( V_347 ) ;
return V_95 ;
}
static int F_79 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 , int V_35 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_379 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_45 ( V_37 , V_380 , V_6 -> V_381 ) ;
F_24 ( V_37 , V_382 , V_6 -> V_348 -> V_103 ) ;
F_24 ( V_37 , V_160 ,
V_4 -> V_383 ^
( V_161 << 2 ) ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
static int F_80 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_384 = 0 ;
int V_385 = 0 ;
int V_386 = V_14 -> args [ 0 ] ;
int V_387 = V_14 -> args [ 1 ] ;
struct V_3 * V_4 ;
struct V_101 * V_102 ;
F_54 ( & V_315 ) ;
F_55 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_4 -> V_118 ) , F_14 ( V_24 -> V_27 ) ) )
continue;
if ( V_384 < V_386 ) {
V_384 ++ ;
continue;
}
V_385 = 0 ;
F_54 ( & V_4 -> V_346 ) ;
F_55 (wdev, &rdev->netdev_list, list) {
if ( V_385 < V_387 ) {
V_385 ++ ;
continue;
}
if ( F_79 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_316 , V_317 ,
V_4 , V_102 -> V_347 ) < 0 ) {
F_59 ( & V_4 -> V_346 ) ;
goto V_388;
}
V_385 ++ ;
}
F_59 ( & V_4 -> V_346 ) ;
V_384 ++ ;
}
V_388:
F_59 ( & V_315 ) ;
V_14 -> args [ 0 ] = V_384 ;
V_14 -> args [ 1 ] = V_385 ;
return V_24 -> V_31 ;
}
static int F_81 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
struct V_3 * V_6 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_347 = V_2 -> V_318 [ 1 ] ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_79 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_6 , V_347 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_82 ( struct V_7 * V_389 , T_2 * V_390 )
{
struct V_7 * V_35 [ V_391 + 1 ] ;
int V_392 ;
* V_390 = 0 ;
if ( ! V_389 )
return - V_11 ;
if ( F_28 ( V_35 , V_391 ,
V_389 , V_393 ) )
return - V_11 ;
for ( V_392 = 1 ; V_392 <= V_391 ; V_392 ++ )
if ( V_35 [ V_392 ] )
* V_390 |= ( 1 << V_392 ) ;
return 0 ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_5 * V_347 , T_1 V_394 ,
enum V_284 V_103 )
{
if ( ! V_394 ) {
if ( V_347 && ( V_347 -> V_395 & V_396 ) )
return - V_351 ;
return 0 ;
}
switch ( V_103 ) {
case V_105 :
if ( V_4 -> V_118 . V_35 & V_397 )
return 0 ;
break;
case V_111 :
if ( V_4 -> V_118 . V_35 & V_398 )
return 0 ;
break;
default:
break;
}
return - V_341 ;
}
static int F_84 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_399 V_99 ;
int V_26 ;
enum V_284 V_400 , V_401 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_2 V_402 , * V_35 = NULL ;
bool V_403 = false ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_400 = V_401 = V_6 -> V_348 -> V_103 ;
if ( V_2 -> V_8 [ V_382 ] ) {
V_401 = F_2 ( V_2 -> V_8 [ V_382 ] ) ;
if ( V_400 != V_401 )
V_403 = true ;
if ( V_401 > V_404 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_405 ] ) {
struct V_101 * V_102 = V_6 -> V_348 ;
if ( V_401 != V_107 )
return - V_11 ;
if ( F_73 ( V_6 ) )
return - V_351 ;
F_68 ( V_102 ) ;
F_85 ( V_406 !=
V_407 ) ;
V_102 -> V_408 =
F_20 ( V_2 -> V_8 [ V_405 ] ) ;
memcpy ( V_102 -> V_409 , F_19 ( V_2 -> V_8 [ V_405 ] ) ,
V_102 -> V_408 ) ;
F_70 ( V_102 ) ;
}
if ( V_2 -> V_8 [ V_410 ] ) {
V_99 . V_394 = ! ! F_29 ( V_2 -> V_8 [ V_410 ] ) ;
V_403 = true ;
V_26 = F_83 ( V_4 , V_6 , V_99 . V_394 , V_401 ) ;
if ( V_26 )
return V_26 ;
} else {
V_99 . V_394 = - 1 ;
}
if ( V_2 -> V_8 [ V_411 ] ) {
if ( V_401 != V_335 )
return - V_11 ;
V_26 = F_82 ( V_2 -> V_8 [ V_411 ] ,
& V_402 ) ;
if ( V_26 )
return V_26 ;
V_35 = & V_402 ;
V_403 = true ;
}
if ( V_403 )
V_26 = F_86 ( V_4 , V_6 , V_401 , V_35 , & V_99 ) ;
else
V_26 = 0 ;
if ( ! V_26 && V_99 . V_394 != - 1 )
V_6 -> V_348 -> V_394 = V_99 . V_394 ;
return V_26 ;
}
static int F_87 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_399 V_99 ;
struct V_5 * V_6 ;
int V_26 ;
enum V_284 type = V_412 ;
T_2 V_35 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( ! V_2 -> V_8 [ V_380 ] )
return - V_11 ;
if ( V_2 -> V_8 [ V_382 ] ) {
type = F_2 ( V_2 -> V_8 [ V_382 ] ) ;
if ( type > V_404 )
return - V_11 ;
}
if ( ! V_4 -> V_191 -> V_223 ||
! ( V_4 -> V_118 . V_198 & ( 1 << type ) ) )
return - V_341 ;
if ( V_2 -> V_8 [ V_410 ] ) {
V_99 . V_394 = ! ! F_29 ( V_2 -> V_8 [ V_410 ] ) ;
V_26 = F_83 ( V_4 , NULL , V_99 . V_394 , type ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_82 ( type == V_335 ?
V_2 -> V_8 [ V_411 ] : NULL ,
& V_35 ) ;
V_6 = V_4 -> V_191 -> V_223 ( & V_4 -> V_118 ,
F_19 ( V_2 -> V_8 [ V_380 ] ) ,
type , V_26 ? NULL : & V_35 , & V_99 ) ;
if ( F_6 ( V_6 ) )
return F_8 ( V_6 ) ;
if ( type == V_107 &&
V_2 -> V_8 [ V_405 ] ) {
struct V_101 * V_102 = V_6 -> V_348 ;
F_68 ( V_102 ) ;
F_85 ( V_406 !=
V_407 ) ;
V_102 -> V_408 =
F_20 ( V_2 -> V_8 [ V_405 ] ) ;
memcpy ( V_102 -> V_409 , F_19 ( V_2 -> V_8 [ V_405 ] ) ,
V_102 -> V_408 ) ;
F_70 ( V_102 ) ;
}
return 0 ;
}
static int F_88 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
if ( ! V_4 -> V_191 -> V_413 )
return - V_341 ;
return V_4 -> V_191 -> V_413 ( & V_4 -> V_118 , V_6 ) ;
}
static void F_89 ( void * V_124 , struct V_414 * V_99 )
{
struct V_7 * V_54 ;
struct V_415 * V_416 = V_124 ;
if ( V_99 -> V_54 )
F_49 ( V_416 -> V_37 , V_83 ,
V_99 -> V_70 , V_99 -> V_54 ) ;
if ( V_99 -> V_34 )
F_49 ( V_416 -> V_37 , V_84 ,
V_99 -> V_72 , V_99 -> V_34 ) ;
if ( V_99 -> V_74 )
F_24 ( V_416 -> V_37 , V_86 ,
V_99 -> V_74 ) ;
V_54 = F_41 ( V_416 -> V_37 , V_91 ) ;
if ( ! V_54 )
goto V_52;
if ( V_99 -> V_54 )
F_49 ( V_416 -> V_37 , V_68 ,
V_99 -> V_70 , V_99 -> V_54 ) ;
if ( V_99 -> V_34 )
F_49 ( V_416 -> V_37 , V_71 ,
V_99 -> V_72 , V_99 -> V_34 ) ;
if ( V_99 -> V_74 )
F_24 ( V_416 -> V_37 , V_73 ,
V_99 -> V_74 ) ;
F_47 ( V_416 -> V_37 , V_85 , V_416 -> V_67 ) ;
F_42 ( V_416 -> V_37 , V_54 ) ;
return;
V_52:
V_416 -> error = 1 ;
}
static int F_90 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_1 V_417 = 0 ;
const T_1 * V_418 = NULL ;
bool V_419 ;
struct V_415 V_416 = {
. error = 0 ,
} ;
void * V_142 ;
struct V_23 * V_37 ;
if ( V_2 -> V_8 [ V_85 ] )
V_417 = F_29 ( V_2 -> V_8 [ V_85 ] ) ;
if ( V_417 > 5 )
return - V_11 ;
if ( V_2 -> V_8 [ V_350 ] )
V_418 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_419 = ! ! V_418 ;
if ( V_2 -> V_8 [ V_89 ] ) {
T_2 V_420 = F_2 ( V_2 -> V_8 [ V_89 ] ) ;
if ( V_420 >= V_76 )
return - V_11 ;
if ( V_420 != V_421 &&
V_420 != V_422 )
return - V_11 ;
V_419 = V_420 == V_422 ;
}
if ( ! V_4 -> V_191 -> V_423 )
return - V_341 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_424 ) ;
if ( F_6 ( V_142 ) )
return F_8 ( V_142 ) ;
V_416 . V_37 = V_37 ;
V_416 . V_67 = V_417 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_47 ( V_37 , V_85 , V_417 ) ;
if ( V_418 )
F_49 ( V_37 , V_350 , V_425 , V_418 ) ;
if ( V_419 && V_418 &&
! ( V_4 -> V_118 . V_35 & V_176 ) )
return - V_426 ;
V_26 = V_4 -> V_191 -> V_423 ( & V_4 -> V_118 , V_6 , V_417 , V_419 ,
V_418 , & V_416 , F_89 ) ;
if ( V_26 )
goto V_427;
if ( V_416 . error )
goto V_52;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_427:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_55 V_54 ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 < 0 )
return - V_11 ;
if ( ! V_54 . V_60 && ! V_54 . V_62 )
return - V_11 ;
F_68 ( V_6 -> V_348 ) ;
if ( V_54 . V_60 ) {
if ( ! V_4 -> V_191 -> V_428 ) {
V_26 = - V_341 ;
goto V_388;
}
V_26 = F_38 ( V_6 -> V_348 ) ;
if ( V_26 )
goto V_388;
V_26 = V_4 -> V_191 -> V_428 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . V_64 , V_54 . V_65 ) ;
if ( V_26 )
goto V_388;
#ifdef F_92
V_6 -> V_348 -> V_429 . V_430 = V_54 . V_67 ;
#endif
} else {
if ( V_54 . V_64 || ! V_54 . V_65 ) {
V_26 = - V_11 ;
goto V_388;
}
if ( ! V_4 -> V_191 -> V_431 ) {
V_26 = - V_341 ;
goto V_388;
}
V_26 = F_38 ( V_6 -> V_348 ) ;
if ( V_26 )
goto V_388;
V_26 = V_4 -> V_191 -> V_431 ( & V_4 -> V_118 ,
V_6 , V_54 . V_67 ) ;
if ( V_26 )
goto V_388;
#ifdef F_92
V_6 -> V_348 -> V_429 . V_432 = V_54 . V_67 ;
#endif
}
V_388:
F_70 ( V_6 -> V_348 ) ;
return V_26 ;
}
static int F_93 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_55 V_54 ;
const T_1 * V_418 = NULL ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_54 . V_69 . V_54 )
return - V_11 ;
if ( V_2 -> V_8 [ V_350 ] )
V_418 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_418 )
V_54 . type = V_422 ;
else
V_54 . type = V_421 ;
}
if ( V_54 . type != V_422 &&
V_54 . type != V_421 )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_227 )
return - V_341 ;
if ( F_36 ( V_4 , & V_54 . V_69 , V_54 . V_67 ,
V_54 . type == V_422 ,
V_418 ) )
return - V_11 ;
F_68 ( V_6 -> V_348 ) ;
V_26 = F_38 ( V_6 -> V_348 ) ;
if ( ! V_26 )
V_26 = V_4 -> V_191 -> V_227 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . type == V_422 ,
V_418 , & V_54 . V_69 ) ;
F_70 ( V_6 -> V_348 ) ;
return V_26 ;
}
static int F_94 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_1 * V_418 = NULL ;
struct V_55 V_54 ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_2 -> V_8 [ V_350 ] )
V_418 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_418 )
V_54 . type = V_422 ;
else
V_54 . type = V_421 ;
}
if ( V_54 . type != V_422 &&
V_54 . type != V_421 )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_433 )
return - V_341 ;
F_68 ( V_6 -> V_348 ) ;
V_26 = F_38 ( V_6 -> V_348 ) ;
if ( V_54 . type == V_422 && V_418 &&
! ( V_4 -> V_118 . V_35 & V_176 ) )
V_26 = - V_426 ;
if ( ! V_26 )
V_26 = V_4 -> V_191 -> V_433 ( & V_4 -> V_118 , V_6 , V_54 . V_67 ,
V_54 . type == V_422 ,
V_418 ) ;
#ifdef F_92
if ( ! V_26 ) {
if ( V_54 . V_67 == V_6 -> V_348 -> V_429 . V_430 )
V_6 -> V_348 -> V_429 . V_430 = - 1 ;
else if ( V_54 . V_67 == V_6 -> V_348 -> V_429 . V_432 )
V_6 -> V_348 -> V_429 . V_432 = - 1 ;
}
#endif
F_70 ( V_6 -> V_348 ) ;
return V_26 ;
}
static int F_95 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
int (* F_96)( struct V_118 * V_118 , struct V_5 * V_6 ,
struct V_434 * V_2 );
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_348 ;
struct V_434 V_99 ;
int V_435 = 0 , V_26 ;
if ( ! F_18 ( V_2 -> V_8 [ V_436 ] ) )
return - V_11 ;
if ( V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_341 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
switch ( V_2 -> V_437 -> V_36 ) {
case V_438 :
if ( ! V_2 -> V_8 [ V_439 ] ||
! V_2 -> V_8 [ V_440 ] ||
! V_2 -> V_8 [ V_441 ] )
return - V_11 ;
V_99 . V_442 =
F_2 ( V_2 -> V_8 [ V_439 ] ) ;
V_99 . V_443 =
F_2 ( V_2 -> V_8 [ V_440 ] ) ;
V_26 = F_97 ( V_4 , V_99 . V_442 ) ;
if ( V_26 )
return V_26 ;
F_96 = V_4 -> V_191 -> V_229 ;
break;
case V_444 :
F_96 = V_4 -> V_191 -> V_445 ;
break;
default:
F_98 ( 1 ) ;
return - V_341 ;
}
if ( ! F_96 )
return - V_341 ;
if ( V_2 -> V_8 [ V_441 ] ) {
V_99 . V_446 = F_19 ( V_2 -> V_8 [ V_441 ] ) ;
V_99 . V_447 =
F_20 ( V_2 -> V_8 [ V_441 ] ) ;
V_435 = 1 ;
}
if ( V_2 -> V_8 [ V_436 ] ) {
V_99 . V_448 = F_19 ( V_2 -> V_8 [ V_436 ] ) ;
V_99 . V_449 =
F_20 ( V_2 -> V_8 [ V_436 ] ) ;
V_435 = 1 ;
}
if ( ! V_435 )
return - V_11 ;
V_26 = F_96 ( & V_4 -> V_118 , V_6 , & V_99 ) ;
if ( ! V_26 && V_99 . V_442 )
V_102 -> V_450 = V_99 . V_442 ;
return V_26 ;
}
static int F_99 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_348 ;
int V_26 ;
if ( ! V_4 -> V_191 -> V_451 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_341 ;
V_26 = V_4 -> V_191 -> V_451 ( & V_4 -> V_118 , V_6 ) ;
if ( ! V_26 )
V_102 -> V_450 = 0 ;
return V_26 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_452 * V_99 )
{
struct V_7 * V_35 [ V_453 + 1 ] ;
struct V_7 * V_389 ;
int V_392 ;
V_389 = V_2 -> V_8 [ V_454 ] ;
if ( V_389 ) {
struct V_455 * V_456 ;
V_456 = F_19 ( V_389 ) ;
V_99 -> V_457 = V_456 -> V_458 ;
V_99 -> V_459 = V_456 -> V_460 ;
if ( ( V_99 -> V_457 |
V_99 -> V_459 ) & F_101 ( V_461 ) )
return - V_11 ;
return 0 ;
}
V_389 = V_2 -> V_8 [ V_462 ] ;
if ( ! V_389 )
return 0 ;
if ( F_28 ( V_35 , V_453 ,
V_389 , V_463 ) )
return - V_11 ;
V_99 -> V_457 = ( 1 << V_464 ) - 1 ;
V_99 -> V_457 &= ~ 1 ;
for ( V_392 = 1 ; V_392 <= V_453 ; V_392 ++ )
if ( V_35 [ V_392 ] )
V_99 -> V_459 |= ( 1 << V_392 ) ;
return 0 ;
}
static bool F_102 ( struct V_23 * V_37 , struct V_465 * V_2 ,
int V_29 )
{
struct V_7 * V_153 ;
T_3 V_219 ;
V_153 = F_41 ( V_37 , V_29 ) ;
if ( ! V_153 )
goto V_52;
V_219 = F_103 ( V_2 ) ;
if ( V_219 > 0 )
F_48 ( V_37 , V_466 , V_219 ) ;
if ( V_2 -> V_35 & V_467 )
F_47 ( V_37 , V_468 , V_2 -> V_205 ) ;
if ( V_2 -> V_35 & V_469 )
F_25 ( V_37 , V_470 ) ;
if ( V_2 -> V_35 & V_471 )
F_25 ( V_37 , V_472 ) ;
F_42 ( V_37 , V_153 ) ;
return true ;
V_52:
return false ;
}
static int F_104 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
const T_1 * V_418 , struct V_473 * V_474 )
{
void * V_142 ;
struct V_7 * V_475 , * V_476 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_477 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_350 , V_425 , V_418 ) ;
F_24 ( V_37 , V_160 , V_474 -> V_478 ) ;
V_475 = F_41 ( V_37 , V_479 ) ;
if ( ! V_475 )
goto V_52;
if ( V_474 -> V_480 & V_481 )
F_24 ( V_37 , V_482 ,
V_474 -> V_483 ) ;
if ( V_474 -> V_480 & V_484 )
F_24 ( V_37 , V_485 ,
V_474 -> V_486 ) ;
if ( V_474 -> V_480 & V_487 )
F_24 ( V_37 , V_488 ,
V_474 -> V_489 ) ;
if ( V_474 -> V_480 & V_490 )
F_24 ( V_37 , V_491 ,
V_474 -> V_492 ) ;
if ( V_474 -> V_480 & V_493 )
F_48 ( V_37 , V_494 ,
V_474 -> V_495 ) ;
if ( V_474 -> V_480 & V_496 )
F_48 ( V_37 , V_497 ,
V_474 -> V_498 ) ;
if ( V_474 -> V_480 & V_499 )
F_47 ( V_37 , V_500 ,
V_474 -> V_501 ) ;
if ( V_474 -> V_480 & V_502 )
F_47 ( V_37 , V_503 ,
V_474 -> signal ) ;
if ( V_474 -> V_480 & V_504 )
F_47 ( V_37 , V_505 ,
V_474 -> V_506 ) ;
if ( V_474 -> V_480 & V_507 ) {
if ( ! F_102 ( V_37 , & V_474 -> V_508 ,
V_509 ) )
goto V_52;
}
if ( V_474 -> V_480 & V_510 ) {
if ( ! F_102 ( V_37 , & V_474 -> V_511 ,
V_512 ) )
goto V_52;
}
if ( V_474 -> V_480 & V_513 )
F_24 ( V_37 , V_514 ,
V_474 -> V_515 ) ;
if ( V_474 -> V_480 & V_516 )
F_24 ( V_37 , V_517 ,
V_474 -> V_518 ) ;
if ( V_474 -> V_480 & V_519 )
F_24 ( V_37 , V_520 ,
V_474 -> V_521 ) ;
if ( V_474 -> V_480 & V_522 )
F_24 ( V_37 , V_523 ,
V_474 -> V_524 ) ;
if ( V_474 -> V_480 & V_525 ) {
V_476 = F_41 ( V_37 , V_526 ) ;
if ( ! V_476 )
goto V_52;
if ( V_474 -> V_476 . V_35 & V_527 )
F_25 ( V_37 , V_528 ) ;
if ( V_474 -> V_476 . V_35 & V_529 )
F_25 ( V_37 , V_530 ) ;
if ( V_474 -> V_476 . V_35 & V_531 )
F_25 ( V_37 ,
V_532 ) ;
F_47 ( V_37 , V_533 ,
V_474 -> V_476 . V_443 ) ;
F_48 ( V_37 , V_534 ,
V_474 -> V_476 . V_450 ) ;
F_42 ( V_37 , V_476 ) ;
}
F_42 ( V_37 , V_475 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
static int F_105 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_473 V_474 ;
struct V_3 * V_6 ;
struct V_5 * V_347 ;
T_1 V_418 [ V_425 ] ;
int V_535 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_6 , & V_347 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_6 -> V_191 -> V_536 ) {
V_26 = - V_341 ;
goto V_537;
}
while ( 1 ) {
V_26 = V_6 -> V_191 -> V_536 ( & V_6 -> V_118 , V_347 , V_535 ,
V_418 , & V_474 ) ;
if ( V_26 == - V_426 )
break;
if ( V_26 )
goto V_537;
if ( F_104 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_316 , V_317 ,
V_347 , V_418 ,
& V_474 ) < 0 )
goto V_388;
V_535 ++ ;
}
V_388:
V_14 -> args [ 1 ] = V_535 ;
V_26 = V_24 -> V_31 ;
V_537:
F_16 ( V_6 ) ;
return V_26 ;
}
static int F_106 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_473 V_474 ;
struct V_23 * V_37 ;
T_1 * V_418 = NULL ;
int V_26 ;
memset ( & V_474 , 0 , sizeof( V_474 ) ) ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
V_418 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( ! V_4 -> V_191 -> V_538 )
return - V_341 ;
V_26 = V_4 -> V_191 -> V_538 ( & V_4 -> V_118 , V_6 , V_418 , & V_474 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_104 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_6 , V_418 , & V_474 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_539 )
{
struct V_7 * V_540 = V_2 -> V_8 [ V_541 ] ;
* V_539 = NULL ;
if ( V_540 ) {
* V_539 = F_3 ( F_4 ( V_2 ) ,
F_2 ( V_540 ) ) ;
if ( ! * V_539 )
return - V_12 ;
if ( ! ( * V_539 ) -> V_348 )
return - V_11 ;
if ( ( * V_539 ) -> V_348 -> V_118 != & V_4 -> V_118 )
return - V_11 ;
if ( ! F_73 ( * V_539 ) )
return - V_542 ;
}
return 0 ;
}
static int F_108 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_452 V_99 ;
T_1 * V_418 = NULL ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_543 = - 1 ;
V_99 . V_501 = - 1 ;
if ( V_2 -> V_8 [ V_544 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
V_418 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( V_2 -> V_8 [ V_545 ] ) {
V_99 . V_546 =
F_19 ( V_2 -> V_8 [ V_545 ] ) ;
V_99 . V_547 =
F_20 ( V_2 -> V_8 [ V_545 ] ) ;
}
if ( V_2 -> V_8 [ V_548 ] )
V_99 . V_543 =
F_65 ( V_2 -> V_8 [ V_548 ] ) ;
if ( V_2 -> V_8 [ V_549 ] )
V_99 . V_550 =
F_19 ( V_2 -> V_8 [ V_549 ] ) ;
if ( F_100 ( V_2 , & V_99 ) )
return - V_11 ;
if ( V_2 -> V_8 [ V_551 ] )
V_99 . V_552 =
F_29 ( V_2 -> V_8 [ V_551 ] ) ;
if ( V_2 -> V_8 [ V_553 ] )
V_99 . V_501 =
F_29 ( V_2 -> V_8 [ V_553 ] ) ;
V_26 = F_107 ( V_2 , V_4 , & V_99 . V_539 ) ;
if ( V_26 )
goto V_388;
V_26 = 0 ;
switch ( V_6 -> V_348 -> V_103 ) {
case V_104 :
case V_105 :
case V_106 :
if ( V_99 . V_552 )
V_26 = - V_11 ;
break;
case V_112 :
case V_111 :
if ( V_99 . V_552 )
V_26 = - V_11 ;
if ( V_99 . V_539 )
V_26 = - V_11 ;
if ( V_99 . V_546 )
V_26 = - V_11 ;
if ( V_99 . V_550 )
V_26 = - V_11 ;
if ( V_99 . V_543 >= 0 )
V_26 = - V_11 ;
if ( V_99 . V_457 & ~ F_101 ( V_554 ) )
V_26 = - V_11 ;
break;
case V_107 :
if ( V_99 . V_539 )
V_26 = - V_11 ;
if ( V_99 . V_550 )
V_26 = - V_11 ;
if ( V_99 . V_543 >= 0 )
V_26 = - V_11 ;
if ( V_99 . V_457 &
~ ( F_101 ( V_555 ) |
F_101 ( V_556 ) |
F_101 ( V_554 ) ) )
V_26 = - V_11 ;
break;
default:
V_26 = - V_11 ;
}
if ( V_26 )
goto V_388;
if ( ! V_4 -> V_191 -> V_557 ) {
V_26 = - V_341 ;
goto V_388;
}
V_26 = V_4 -> V_191 -> V_557 ( & V_4 -> V_118 , V_6 , V_418 , & V_99 ) ;
V_388:
if ( V_99 . V_539 )
F_7 ( V_99 . V_539 ) ;
return V_26 ;
}
static int F_109 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_452 V_99 ;
T_1 * V_418 = NULL ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_548 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_545 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_544 ] )
return - V_11 ;
V_418 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_99 . V_546 =
F_19 ( V_2 -> V_8 [ V_545 ] ) ;
V_99 . V_547 =
F_20 ( V_2 -> V_8 [ V_545 ] ) ;
V_99 . V_543 =
F_65 ( V_2 -> V_8 [ V_548 ] ) ;
V_99 . V_558 = F_65 ( V_2 -> V_8 [ V_544 ] ) ;
if ( ! V_99 . V_558 || V_99 . V_558 > V_559 )
return - V_11 ;
if ( V_2 -> V_8 [ V_549 ] )
V_99 . V_550 =
F_19 ( V_2 -> V_8 [ V_549 ] ) ;
if ( V_2 -> V_8 [ V_551 ] )
V_99 . V_552 =
F_29 ( V_2 -> V_8 [ V_551 ] ) ;
if ( F_100 ( V_2 , & V_99 ) )
return - V_11 ;
if ( V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_105 &&
V_6 -> V_348 -> V_103 != V_107 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_11 ;
V_26 = F_107 ( V_2 , V_4 , & V_99 . V_539 ) ;
if ( V_26 )
goto V_388;
V_26 = 0 ;
if ( ! V_4 -> V_191 -> V_231 ) {
V_26 = - V_341 ;
goto V_388;
}
V_26 = V_4 -> V_191 -> V_231 ( & V_4 -> V_118 , V_6 , V_418 , & V_99 ) ;
V_388:
if ( V_99 . V_539 )
F_7 ( V_99 . V_539 ) ;
return V_26 ;
}
static int F_110 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_1 * V_418 = NULL ;
if ( V_2 -> V_8 [ V_350 ] )
V_418 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_105 &&
V_6 -> V_348 -> V_103 != V_107 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_560 )
return - V_341 ;
return V_4 -> V_191 -> V_560 ( & V_4 -> V_118 , V_6 , V_418 ) ;
}
static int F_111 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
T_1 * V_561 , T_1 * V_562 ,
struct V_563 * V_564 )
{
void * V_142 ;
struct V_7 * V_565 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_477 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_350 , V_425 , V_561 ) ;
F_49 ( V_37 , V_566 , V_425 , V_562 ) ;
F_24 ( V_37 , V_160 , V_564 -> V_478 ) ;
V_565 = F_41 ( V_37 , V_567 ) ;
if ( ! V_565 )
goto V_52;
if ( V_564 -> V_480 & V_568 )
F_24 ( V_37 , V_569 ,
V_564 -> V_570 ) ;
if ( V_564 -> V_480 & V_571 )
F_24 ( V_37 , V_572 ,
V_564 -> V_573 ) ;
if ( V_564 -> V_480 & V_574 )
F_24 ( V_37 , V_575 ,
V_564 -> V_576 ) ;
if ( V_564 -> V_480 & V_577 )
F_24 ( V_37 , V_578 ,
V_564 -> V_579 ) ;
if ( V_564 -> V_480 & V_580 )
F_47 ( V_37 , V_581 ,
V_564 -> V_35 ) ;
if ( V_564 -> V_480 & V_582 )
F_24 ( V_37 , V_583 ,
V_564 -> V_584 ) ;
if ( V_564 -> V_480 & V_585 )
F_47 ( V_37 , V_586 ,
V_564 -> V_587 ) ;
F_42 ( V_37 , V_565 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
static int F_112 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_563 V_564 ;
struct V_3 * V_6 ;
struct V_5 * V_347 ;
T_1 V_561 [ V_425 ] ;
T_1 V_562 [ V_425 ] ;
int V_588 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_6 , & V_347 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_6 -> V_191 -> V_589 ) {
V_26 = - V_341 ;
goto V_537;
}
if ( V_347 -> V_348 -> V_103 != V_107 ) {
V_26 = - V_341 ;
goto V_537;
}
while ( 1 ) {
V_26 = V_6 -> V_191 -> V_589 ( & V_6 -> V_118 , V_347 , V_588 ,
V_561 , V_562 , & V_564 ) ;
if ( V_26 == - V_426 )
break;
if ( V_26 )
goto V_537;
if ( F_111 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_316 , V_317 ,
V_347 , V_561 , V_562 ,
& V_564 ) < 0 )
goto V_388;
V_588 ++ ;
}
V_388:
V_14 -> args [ 1 ] = V_588 ;
V_26 = V_24 -> V_31 ;
V_537:
F_16 ( V_6 ) ;
return V_26 ;
}
static int F_113 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_563 V_564 ;
struct V_23 * V_37 ;
T_1 * V_561 = NULL ;
T_1 V_562 [ V_425 ] ;
memset ( & V_564 , 0 , sizeof( V_564 ) ) ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
V_561 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( ! V_4 -> V_191 -> V_590 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_107 )
return - V_341 ;
V_26 = V_4 -> V_191 -> V_590 ( & V_4 -> V_118 , V_6 , V_561 , V_562 , & V_564 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
if ( F_111 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_6 , V_561 , V_562 , & V_564 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_2 ) ;
}
static int F_114 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_1 * V_561 = NULL ;
T_1 * V_562 = NULL ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_566 ] )
return - V_11 ;
V_561 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_562 = F_19 ( V_2 -> V_8 [ V_566 ] ) ;
if ( ! V_4 -> V_191 -> V_591 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_107 )
return - V_341 ;
return V_4 -> V_191 -> V_591 ( & V_4 -> V_118 , V_6 , V_561 , V_562 ) ;
}
static int F_115 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_1 * V_561 = NULL ;
T_1 * V_562 = NULL ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_566 ] )
return - V_11 ;
V_561 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_562 = F_19 ( V_2 -> V_8 [ V_566 ] ) ;
if ( ! V_4 -> V_191 -> V_233 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_107 )
return - V_341 ;
return V_4 -> V_191 -> V_233 ( & V_4 -> V_118 , V_6 , V_561 , V_562 ) ;
}
static int F_116 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_1 * V_561 = NULL ;
if ( V_2 -> V_8 [ V_350 ] )
V_561 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( ! V_4 -> V_191 -> V_592 )
return - V_341 ;
return V_4 -> V_191 -> V_592 ( & V_4 -> V_118 , V_6 , V_561 ) ;
}
static int F_117 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_593 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_594 = - 1 ;
V_99 . V_595 = - 1 ;
V_99 . V_596 = - 1 ;
V_99 . V_597 = - 1 ;
V_99 . V_598 = - 1 ;
if ( V_2 -> V_8 [ V_599 ] )
V_99 . V_594 =
F_29 ( V_2 -> V_8 [ V_599 ] ) ;
if ( V_2 -> V_8 [ V_600 ] )
V_99 . V_595 =
F_29 ( V_2 -> V_8 [ V_600 ] ) ;
if ( V_2 -> V_8 [ V_601 ] )
V_99 . V_596 =
F_29 ( V_2 -> V_8 [ V_601 ] ) ;
if ( V_2 -> V_8 [ V_602 ] ) {
V_99 . V_603 =
F_19 ( V_2 -> V_8 [ V_602 ] ) ;
V_99 . V_604 =
F_20 ( V_2 -> V_8 [ V_602 ] ) ;
}
if ( V_2 -> V_8 [ V_605 ] )
V_99 . V_597 = ! ! F_29 ( V_2 -> V_8 [ V_605 ] ) ;
if ( V_2 -> V_8 [ V_606 ] )
V_99 . V_598 =
F_65 ( V_2 -> V_8 [ V_606 ] ) ;
if ( ! V_4 -> V_191 -> V_237 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_341 ;
return V_4 -> V_191 -> V_237 ( & V_4 -> V_118 , V_6 , & V_99 ) ;
}
static int F_118 ( struct V_7 * V_57 [] ,
struct V_607 * V_608 )
{
struct V_609 * V_610 = & V_608 -> V_610 ;
struct V_611 * V_612 = & V_608 -> V_612 ;
if ( ! V_57 [ V_613 ] )
return - V_11 ;
if ( ! V_57 [ V_614 ] )
return - V_11 ;
if ( ! V_57 [ V_615 ] )
return - V_11 ;
if ( ! V_57 [ V_616 ] )
return - V_11 ;
if ( ! V_57 [ V_617 ] )
return - V_11 ;
V_608 -> V_35 = F_2 ( V_57 [ V_613 ] ) ;
V_610 -> V_618 =
F_2 ( V_57 [ V_614 ] ) ;
V_610 -> V_619 =
F_2 ( V_57 [ V_615 ] ) ;
V_610 -> V_620 =
F_2 ( V_57 [ V_616 ] ) ;
V_612 -> V_621 =
F_2 ( V_57 [ V_617 ] ) ;
if ( V_57 [ V_622 ] )
V_612 -> V_623 =
F_2 ( V_57 [ V_622 ] ) ;
return 0 ;
}
static int F_119 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
int V_624 ;
char * V_100 = NULL ;
F_54 ( & V_315 ) ;
if ( F_120 ( ! V_625 ) ) {
F_59 ( & V_315 ) ;
return - V_626 ;
}
F_59 ( & V_315 ) ;
if ( ! V_2 -> V_8 [ V_627 ] )
return - V_11 ;
V_100 = F_19 ( V_2 -> V_8 [ V_627 ] ) ;
V_624 = F_121 ( V_100 ) ;
return V_624 ;
}
static int F_122 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_348 ;
struct V_628 V_629 ;
int V_26 = 0 ;
void * V_142 ;
struct V_7 * V_565 ;
struct V_23 * V_37 ;
if ( V_102 -> V_103 != V_107 )
return - V_341 ;
if ( ! V_4 -> V_191 -> V_630 )
return - V_341 ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_631 )
memcpy ( & V_629 , & V_632 , sizeof( V_629 ) ) ;
else
V_26 = V_4 -> V_191 -> V_630 ( & V_4 -> V_118 , V_6 ,
& V_629 ) ;
F_70 ( V_102 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_633 ) ;
if ( ! V_142 )
goto V_388;
V_565 = F_41 ( V_37 , V_634 ) ;
if ( ! V_565 )
goto V_52;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_48 ( V_37 , V_635 ,
V_629 . V_636 ) ;
F_48 ( V_37 , V_637 ,
V_629 . V_638 ) ;
F_48 ( V_37 , V_639 ,
V_629 . V_640 ) ;
F_48 ( V_37 , V_641 ,
V_629 . V_642 ) ;
F_47 ( V_37 , V_643 ,
V_629 . V_644 ) ;
F_47 ( V_37 , V_645 ,
V_629 . V_646 ) ;
F_47 ( V_37 , V_647 ,
V_629 . V_648 ) ;
F_47 ( V_37 , V_649 ,
V_629 . V_650 ) ;
F_47 ( V_37 , V_651 ,
V_629 . V_652 ) ;
F_24 ( V_37 , V_653 ,
V_629 . V_654 ) ;
F_48 ( V_37 , V_655 ,
V_629 . V_656 ) ;
F_24 ( V_37 , V_657 ,
V_629 . V_658 ) ;
F_48 ( V_37 , V_659 ,
V_629 . V_660 ) ;
F_48 ( V_37 , V_661 ,
V_629 . V_662 ) ;
F_47 ( V_37 , V_663 ,
V_629 . V_664 ) ;
F_42 ( V_37 , V_565 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
V_388:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_628 * V_665 ,
T_2 * V_666 )
{
struct V_7 * V_57 [ V_667 + 1 ] ;
T_2 V_458 = 0 ;
#define F_124 ( T_6 , V_665 , T_7 , V_458 , T_8 , T_9 ) \
do {\
if (table[attr_num]) {\
cfg->param = nla_fn(table[attr_num]); \
mask |= (1 << (attr_num - 1)); \
} \
} while (0);\
if (!info->attrs[NL80211_ATTR_MESH_CONFIG])
return - V_11 ;
if ( F_28 ( V_57 , V_667 ,
V_2 -> V_8 [ V_634 ] ,
V_668 ) )
return - V_11 ;
F_85 ( V_667 > 32 ) ;
F_124 ( V_57 , V_665 , V_636 ,
V_458 , V_635 , F_65 ) ;
F_124 ( V_57 , V_665 , V_638 ,
V_458 , V_637 , F_65 ) ;
F_124 ( V_57 , V_665 , V_640 ,
V_458 , V_639 , F_65 ) ;
F_124 ( V_57 , V_665 , V_642 ,
V_458 , V_641 , F_65 ) ;
F_124 ( V_57 , V_665 , V_644 ,
V_458 , V_643 , F_29 ) ;
F_124 ( V_57 , V_665 , V_646 ,
V_458 , V_645 , F_29 ) ;
F_124 ( V_57 , V_665 , V_648 ,
V_458 , V_647 , F_29 ) ;
F_124 ( V_57 , V_665 , V_650 ,
V_458 , V_649 , F_29 ) ;
F_124 ( V_57 , V_665 , V_652 ,
V_458 , V_651 ,
F_29 ) ;
F_124 ( V_57 , V_665 , V_654 ,
V_458 , V_653 , F_2 ) ;
F_124 ( V_57 , V_665 , V_656 ,
V_458 , V_655 ,
F_65 ) ;
F_124 ( V_57 , V_665 , V_658 ,
V_458 , V_657 ,
F_2 ) ;
F_124 ( V_57 , V_665 , V_660 ,
V_458 , V_659 ,
F_65 ) ;
F_124 ( V_57 , V_665 ,
V_662 ,
V_458 , V_661 ,
F_65 ) ;
F_124 ( V_57 , V_665 ,
V_664 , V_458 ,
V_663 ,
F_29 ) ;
if ( V_666 )
* V_666 = V_458 ;
return 0 ;
#undef F_124
}
static int F_125 ( struct V_1 * V_2 ,
struct V_669 * V_670 )
{
struct V_7 * V_57 [ V_671 + 1 ] ;
if ( ! V_2 -> V_8 [ V_672 ] )
return - V_11 ;
if ( F_28 ( V_57 , V_671 ,
V_2 -> V_8 [ V_672 ] ,
V_673 ) )
return - V_11 ;
if ( V_57 [ V_674 ] )
V_670 -> V_675 =
( F_29 ( V_57 [ V_674 ] ) ) ?
V_676 :
V_677 ;
if ( V_57 [ V_678 ] )
V_670 -> V_679 =
( F_29 ( V_57 [ V_678 ] ) ) ?
V_680 :
V_681 ;
if ( V_57 [ V_682 ] ) {
struct V_7 * V_683 =
V_57 [ V_682 ] ;
if ( ! F_18 ( V_683 ) )
return - V_11 ;
V_670 -> V_684 = F_19 ( V_683 ) ;
V_670 -> V_685 = F_20 ( V_683 ) ;
}
V_670 -> V_686 = F_126 ( V_57 [ V_687 ] ) ;
V_670 -> V_688 = F_126 ( V_57 [ V_689 ] ) ;
return 0 ;
}
static int F_127 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_101 * V_102 = V_6 -> V_348 ;
struct V_628 V_665 ;
T_2 V_458 ;
int V_26 ;
if ( V_102 -> V_103 != V_107 )
return - V_341 ;
if ( ! V_4 -> V_191 -> V_235 )
return - V_341 ;
V_26 = F_123 ( V_2 , & V_665 , & V_458 ) ;
if ( V_26 )
return V_26 ;
F_68 ( V_102 ) ;
if ( ! V_102 -> V_631 )
V_26 = - V_110 ;
if ( ! V_26 )
V_26 = V_4 -> V_191 -> V_235 ( & V_4 -> V_118 , V_6 ,
V_458 , & V_665 ) ;
F_70 ( V_102 ) ;
return V_26 ;
}
static int F_128 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_23 * V_37 ;
void * V_142 = NULL ;
struct V_7 * V_690 ;
unsigned int V_117 ;
int V_26 = - V_11 ;
F_54 ( & V_315 ) ;
if ( ! V_625 )
goto V_388;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 ) {
V_26 = - V_53 ;
goto V_388;
}
V_142 = F_21 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_691 ) ;
if ( ! V_142 )
goto V_692;
F_45 ( V_37 , V_627 ,
V_625 -> V_693 ) ;
V_690 = F_41 ( V_37 , V_694 ) ;
if ( ! V_690 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_625 -> V_695 ; V_117 ++ ) {
struct V_7 * V_696 ;
const struct V_607 * V_608 ;
const struct V_609 * V_610 ;
const struct V_611 * V_612 ;
V_608 = & V_625 -> V_697 [ V_117 ] ;
V_610 = & V_608 -> V_610 ;
V_612 = & V_608 -> V_612 ;
V_696 = F_41 ( V_37 , V_117 ) ;
if ( ! V_696 )
goto V_52;
F_24 ( V_37 , V_613 ,
V_608 -> V_35 ) ;
F_24 ( V_37 , V_614 ,
V_610 -> V_618 ) ;
F_24 ( V_37 , V_615 ,
V_610 -> V_619 ) ;
F_24 ( V_37 , V_616 ,
V_610 -> V_620 ) ;
F_24 ( V_37 , V_622 ,
V_612 -> V_623 ) ;
F_24 ( V_37 , V_617 ,
V_612 -> V_621 ) ;
F_42 ( V_37 , V_696 ) ;
}
F_42 ( V_37 , V_690 ) ;
F_51 ( V_37 , V_142 ) ;
V_26 = F_63 ( V_37 , V_2 ) ;
goto V_388;
V_52:
F_52 ( V_37 , V_142 ) ;
V_692:
F_62 ( V_37 ) ;
V_26 = - V_313 ;
V_388:
F_59 ( & V_315 ) ;
return V_26 ;
}
static int F_129 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_7 * V_57 [ V_698 + 1 ] ;
struct V_7 * V_696 ;
char * V_693 = NULL ;
int V_699 = 0 , V_624 = 0 ;
T_2 V_700 = 0 , V_701 = 0 , V_702 ;
struct V_703 * V_704 = NULL ;
if ( ! V_2 -> V_8 [ V_627 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_694 ] )
return - V_11 ;
V_693 = F_19 ( V_2 -> V_8 [ V_627 ] ) ;
F_35 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_700 ++ ;
if ( V_700 > V_705 )
return - V_11 ;
}
F_54 ( & V_315 ) ;
if ( ! F_130 ( V_693 ) ) {
V_624 = - V_11 ;
goto V_706;
}
V_702 = sizeof( struct V_703 ) +
( V_700 * sizeof( struct V_607 ) ) ;
V_704 = F_33 ( V_702 , V_97 ) ;
if ( ! V_704 ) {
V_624 = - V_98 ;
goto V_706;
}
V_704 -> V_695 = V_700 ;
V_704 -> V_693 [ 0 ] = V_693 [ 0 ] ;
V_704 -> V_693 [ 1 ] = V_693 [ 1 ] ;
F_35 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_78 ( V_57 , V_698 ,
F_19 ( V_696 ) , F_20 ( V_696 ) ,
V_707 ) ;
V_624 = F_118 ( V_57 , & V_704 -> V_697 [ V_701 ] ) ;
if ( V_624 )
goto V_706;
V_701 ++ ;
if ( V_701 > V_705 ) {
V_624 = - V_11 ;
goto V_706;
}
}
F_131 ( V_701 != V_700 ) ;
V_624 = F_132 ( V_704 ) ;
F_59 ( & V_315 ) ;
return V_624 ;
V_706:
F_59 ( & V_315 ) ;
F_37 ( V_704 ) ;
return V_624 ;
}
static int F_133 ( struct V_7 * V_708 )
{
struct V_7 * V_709 , * V_710 ;
int V_213 = 0 , V_711 , V_712 ;
F_35 (attr1, freqs, tmp1) {
V_213 ++ ;
F_35 (attr2, freqs, tmp2)
if ( V_709 != V_710 &&
F_2 ( V_709 ) == F_2 ( V_710 ) )
return 0 ;
}
return V_213 ;
}
static int F_134 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_713 * V_714 ;
struct V_7 * V_29 ;
struct V_118 * V_118 ;
int V_26 , V_715 , V_716 = 0 , V_213 , V_117 ;
enum V_150 V_151 ;
T_10 V_685 ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
V_118 = & V_4 -> V_118 ;
if ( ! V_4 -> V_191 -> V_718 )
return - V_341 ;
if ( V_4 -> V_719 )
return - V_351 ;
if ( V_2 -> V_8 [ V_720 ] ) {
V_213 = F_133 (
V_2 -> V_8 [ V_720 ] ) ;
if ( ! V_213 )
return - V_11 ;
} else {
V_213 = 0 ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ )
if ( V_118 -> V_201 [ V_151 ] )
V_213 += V_118 -> V_201 [ V_151 ] -> V_213 ;
}
if ( V_2 -> V_8 [ V_721 ] )
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_716 ++ ;
if ( V_716 > V_118 -> V_173 )
return - V_11 ;
if ( V_2 -> V_8 [ V_717 ] )
V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
else
V_685 = 0 ;
if ( V_685 > V_118 -> V_175 )
return - V_11 ;
V_714 = F_33 ( sizeof( * V_714 )
+ sizeof( * V_714 -> V_722 ) * V_716
+ sizeof( * V_714 -> V_214 ) * V_213
+ V_685 , V_97 ) ;
if ( ! V_714 )
return - V_98 ;
if ( V_716 )
V_714 -> V_722 = ( void * ) & V_714 -> V_214 [ V_213 ] ;
V_714 -> V_716 = V_716 ;
if ( V_685 ) {
if ( V_714 -> V_722 )
V_714 -> V_684 = ( void * ) ( V_714 -> V_722 + V_716 ) ;
else
V_714 -> V_684 = ( void * ) ( V_714 -> V_214 + V_213 ) ;
}
V_117 = 0 ;
if ( V_2 -> V_8 [ V_720 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_38 * V_39 ;
V_39 = F_135 ( V_118 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_723;
}
if ( V_39 -> V_35 & V_42 )
continue;
V_714 -> V_214 [ V_117 ] = V_39 ;
V_117 ++ ;
}
} else {
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
int V_120 ;
if ( ! V_118 -> V_201 [ V_151 ] )
continue;
for ( V_120 = 0 ; V_120 < V_118 -> V_201 [ V_151 ] -> V_213 ; V_120 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_118 -> V_201 [ V_151 ] -> V_214 [ V_120 ] ;
if ( V_39 -> V_35 & V_42 )
continue;
V_714 -> V_214 [ V_117 ] = V_39 ;
V_117 ++ ;
}
}
}
if ( ! V_117 ) {
V_26 = - V_11 ;
goto V_723;
}
V_714 -> V_213 = V_117 ;
V_117 = 0 ;
if ( V_2 -> V_8 [ V_721 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_20 ( V_29 ) > V_406 ) {
V_26 = - V_11 ;
goto V_723;
}
V_714 -> V_722 [ V_117 ] . V_724 = F_20 ( V_29 ) ;
memcpy ( V_714 -> V_722 [ V_117 ] . V_409 , F_19 ( V_29 ) , F_20 ( V_29 ) ) ;
V_117 ++ ;
}
}
if ( V_2 -> V_8 [ V_717 ] ) {
V_714 -> V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
memcpy ( ( void * ) V_714 -> V_684 ,
F_19 ( V_2 -> V_8 [ V_717 ] ) ,
V_714 -> V_685 ) ;
}
V_714 -> V_6 = V_6 ;
V_714 -> V_118 = & V_4 -> V_118 ;
V_4 -> V_719 = V_714 ;
V_26 = V_4 -> V_191 -> V_718 ( & V_4 -> V_118 , V_6 , V_714 ) ;
if ( ! V_26 ) {
F_136 ( V_4 , V_6 ) ;
F_137 ( V_6 ) ;
} else {
V_723:
V_4 -> V_719 = NULL ;
F_37 ( V_714 ) ;
}
return V_26 ;
}
static int F_138 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_725 * V_714 ;
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_7 * V_29 ;
struct V_118 * V_118 ;
int V_26 , V_715 , V_716 = 0 , V_213 , V_117 ;
T_2 V_442 ;
enum V_150 V_151 ;
T_10 V_685 ;
if ( ! ( V_4 -> V_118 . V_35 & V_271 ) ||
! V_4 -> V_191 -> V_272 )
return - V_341 ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_726 ] )
return - V_11 ;
V_442 = F_2 ( V_2 -> V_8 [ V_726 ] ) ;
if ( V_442 == 0 )
return - V_11 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_720 ] ) {
V_213 = F_133 (
V_2 -> V_8 [ V_720 ] ) ;
if ( ! V_213 )
return - V_11 ;
} else {
V_213 = 0 ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ )
if ( V_118 -> V_201 [ V_151 ] )
V_213 += V_118 -> V_201 [ V_151 ] -> V_213 ;
}
if ( V_2 -> V_8 [ V_721 ] )
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_716 ++ ;
if ( V_716 > V_118 -> V_173 )
return - V_11 ;
if ( V_2 -> V_8 [ V_717 ] )
V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
else
V_685 = 0 ;
if ( V_685 > V_118 -> V_175 )
return - V_11 ;
F_54 ( & V_4 -> V_727 ) ;
if ( V_4 -> V_728 ) {
V_26 = - V_626 ;
goto V_388;
}
V_714 = F_33 ( sizeof( * V_714 )
+ sizeof( * V_714 -> V_722 ) * V_716
+ sizeof( * V_714 -> V_214 ) * V_213
+ V_685 , V_97 ) ;
if ( ! V_714 ) {
V_26 = - V_98 ;
goto V_388;
}
if ( V_716 )
V_714 -> V_722 = ( void * ) & V_714 -> V_214 [ V_213 ] ;
V_714 -> V_716 = V_716 ;
if ( V_685 ) {
if ( V_714 -> V_722 )
V_714 -> V_684 = ( void * ) ( V_714 -> V_722 + V_716 ) ;
else
V_714 -> V_684 = ( void * ) ( V_714 -> V_214 + V_213 ) ;
}
V_117 = 0 ;
if ( V_2 -> V_8 [ V_720 ] ) {
F_35 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_38 * V_39 ;
V_39 = F_135 ( V_118 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_723;
}
if ( V_39 -> V_35 & V_42 )
continue;
V_714 -> V_214 [ V_117 ] = V_39 ;
V_117 ++ ;
}
} else {
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
int V_120 ;
if ( ! V_118 -> V_201 [ V_151 ] )
continue;
for ( V_120 = 0 ; V_120 < V_118 -> V_201 [ V_151 ] -> V_213 ; V_120 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_118 -> V_201 [ V_151 ] -> V_214 [ V_120 ] ;
if ( V_39 -> V_35 & V_42 )
continue;
V_714 -> V_214 [ V_117 ] = V_39 ;
V_117 ++ ;
}
}
}
if ( ! V_117 ) {
V_26 = - V_11 ;
goto V_723;
}
V_714 -> V_213 = V_117 ;
V_117 = 0 ;
if ( V_2 -> V_8 [ V_721 ] ) {
F_35 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_20 ( V_29 ) > V_406 ) {
V_26 = - V_11 ;
goto V_723;
}
V_714 -> V_722 [ V_117 ] . V_724 = F_20 ( V_29 ) ;
memcpy ( V_714 -> V_722 [ V_117 ] . V_409 , F_19 ( V_29 ) ,
F_20 ( V_29 ) ) ;
V_117 ++ ;
}
}
if ( V_2 -> V_8 [ V_717 ] ) {
V_714 -> V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
memcpy ( ( void * ) V_714 -> V_684 ,
F_19 ( V_2 -> V_8 [ V_717 ] ) ,
V_714 -> V_685 ) ;
}
V_714 -> V_6 = V_6 ;
V_714 -> V_118 = & V_4 -> V_118 ;
V_714 -> V_442 = V_442 ;
V_26 = V_4 -> V_191 -> V_272 ( & V_4 -> V_118 , V_6 , V_714 ) ;
if ( ! V_26 ) {
V_4 -> V_728 = V_714 ;
F_139 ( V_4 , V_6 ,
V_729 ) ;
goto V_388;
}
V_723:
F_37 ( V_714 ) ;
V_388:
F_59 ( & V_4 -> V_727 ) ;
return V_26 ;
}
static int F_140 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
if ( ! ( V_4 -> V_118 . V_35 & V_271 ) ||
! V_4 -> V_191 -> V_730 )
return - V_341 ;
F_54 ( & V_4 -> V_727 ) ;
V_26 = F_141 ( V_4 , false ) ;
F_59 ( & V_4 -> V_727 ) ;
return V_26 ;
}
static int F_142 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 , int V_35 ,
struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_731 * V_732 )
{
struct V_733 * V_15 = & V_732 -> V_734 ;
void * V_142 ;
struct V_7 * V_735 ;
int V_117 ;
F_39 ( V_102 ) ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 ,
V_736 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_160 , V_4 -> V_737 ) ;
F_24 ( V_37 , V_10 , V_102 -> V_347 -> V_9 ) ;
V_735 = F_41 ( V_37 , V_738 ) ;
if ( ! V_735 )
goto V_52;
if ( ! F_143 ( V_15 -> V_349 ) )
F_49 ( V_37 , V_739 , V_425 , V_15 -> V_349 ) ;
if ( V_15 -> V_740 && V_15 -> V_741 )
F_49 ( V_37 , V_742 ,
V_15 -> V_741 ,
V_15 -> V_740 ) ;
if ( V_15 -> V_743 && V_15 -> V_744 &&
V_15 -> V_743 != V_15 -> V_740 )
F_49 ( V_37 , V_745 ,
V_15 -> V_744 , V_15 -> V_743 ) ;
if ( V_15 -> V_746 )
F_144 ( V_37 , V_747 , V_15 -> V_746 ) ;
if ( V_15 -> V_450 )
F_48 ( V_37 , V_748 , V_15 -> V_450 ) ;
F_48 ( V_37 , V_749 , V_15 -> V_750 ) ;
F_24 ( V_37 , V_751 , V_15 -> V_752 -> V_41 ) ;
F_24 ( V_37 , V_753 ,
F_145 ( V_754 - V_732 -> V_755 ) ) ;
switch ( V_4 -> V_118 . V_756 ) {
case V_757 :
F_24 ( V_37 , V_758 , V_15 -> signal ) ;
break;
case V_759 :
F_47 ( V_37 , V_760 , V_15 -> signal ) ;
break;
default:
break;
}
switch ( V_102 -> V_103 ) {
case V_112 :
case V_111 :
if ( V_732 == V_102 -> V_109 )
F_24 ( V_37 , V_761 ,
V_762 ) ;
else for ( V_117 = 0 ; V_117 < V_763 ; V_117 ++ ) {
if ( V_732 != V_102 -> V_764 [ V_117 ] )
continue;
F_24 ( V_37 , V_761 ,
V_765 ) ;
break;
}
break;
case V_108 :
if ( V_732 == V_102 -> V_109 )
F_24 ( V_37 , V_761 ,
V_766 ) ;
break;
default:
break;
}
F_42 ( V_37 , V_735 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
static int F_146 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_731 * V_718 ;
struct V_101 * V_102 ;
int V_314 = V_14 -> args [ 1 ] , V_67 = 0 ;
int V_26 ;
V_26 = F_11 ( V_24 , V_14 , & V_4 , & V_6 ) ;
if ( V_26 )
return V_26 ;
V_102 = V_6 -> V_348 ;
F_68 ( V_102 ) ;
F_147 ( & V_4 -> V_767 ) ;
F_148 ( V_4 ) ;
F_55 (scan, &rdev->bss_list, list) {
if ( ++ V_67 <= V_314 )
continue;
if ( F_142 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_316 , V_317 ,
V_4 , V_102 , V_718 ) < 0 ) {
V_67 -- ;
break;
}
}
F_149 ( & V_4 -> V_767 ) ;
F_70 ( V_102 ) ;
V_14 -> args [ 1 ] = V_67 ;
F_16 ( V_4 ) ;
return V_24 -> V_31 ;
}
static int F_150 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_5 * V_6 ,
struct V_768 * V_769 )
{
void * V_142 ;
struct V_7 * V_770 ;
if ( ! V_769 -> V_752 )
return - V_11 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 ,
V_771 ) ;
if ( ! V_142 )
return - V_98 ;
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
V_770 = F_41 ( V_37 , V_772 ) ;
if ( ! V_770 )
goto V_52;
F_24 ( V_37 , V_773 ,
V_769 -> V_752 -> V_41 ) ;
if ( V_769 -> V_480 & V_774 )
F_47 ( V_37 , V_775 ,
V_769 -> V_776 ) ;
if ( V_769 -> V_480 & V_777 )
F_25 ( V_37 , V_778 ) ;
if ( V_769 -> V_480 & V_779 )
F_144 ( V_37 , V_780 ,
V_769 -> V_781 ) ;
if ( V_769 -> V_480 & V_782 )
F_144 ( V_37 , V_783 ,
V_769 -> V_784 ) ;
if ( V_769 -> V_480 & V_785 )
F_144 ( V_37 , V_786 ,
V_769 -> V_787 ) ;
if ( V_769 -> V_480 & V_788 )
F_144 ( V_37 , V_789 ,
V_769 -> V_790 ) ;
if ( V_769 -> V_480 & V_791 )
F_144 ( V_37 , V_792 ,
V_769 -> V_793 ) ;
F_42 ( V_37 , V_770 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
static int F_151 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_768 V_769 ;
struct V_3 * V_6 ;
struct V_5 * V_347 ;
int V_794 = V_14 -> args [ 1 ] ;
int V_15 ;
V_15 = F_11 ( V_24 , V_14 , & V_6 , & V_347 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_6 -> V_191 -> V_795 ) {
V_15 = - V_341 ;
goto V_537;
}
while ( 1 ) {
V_15 = V_6 -> V_191 -> V_795 ( & V_6 -> V_118 , V_347 , V_794 ,
& V_769 ) ;
if ( V_15 == - V_426 )
break;
if ( V_15 )
goto V_537;
if ( F_150 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_316 , V_317 ,
V_347 ,
& V_769 ) < 0 )
goto V_388;
V_794 ++ ;
}
V_388:
V_14 -> args [ 1 ] = V_794 ;
V_15 = V_24 -> V_31 ;
V_537:
F_16 ( V_6 ) ;
return V_15 ;
}
static bool F_152 ( enum V_796 V_797 )
{
return V_797 <= V_798 ;
}
static bool F_153 ( T_2 V_799 )
{
return ! ( V_799 & ~ ( V_800 |
V_801 ) ) ;
}
static bool F_154 ( T_2 V_802 )
{
return V_802 == V_803 ||
V_802 == V_804 ;
}
static bool F_155 ( T_2 V_74 )
{
return V_74 == V_805 ||
V_74 == V_806 ||
V_74 == V_807 ||
V_74 == V_808 ||
V_74 == V_809 ;
}
static int F_156 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_38 * V_39 ;
const T_1 * V_349 , * V_409 , * V_684 = NULL ;
int V_26 , V_724 , V_685 = 0 ;
enum V_796 V_797 ;
struct V_55 V_54 ;
bool V_810 ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_811 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_812 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_340 ] )
return - V_11 ;
V_26 = F_31 ( V_2 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 >= 0 ) {
if ( V_54 . type != - 1 && V_54 . type != V_421 )
return - V_11 ;
if ( ! V_54 . V_69 . V_54 || ! V_54 . V_69 . V_70 )
return - V_11 ;
if ( ( V_54 . V_69 . V_74 != V_805 ||
V_54 . V_69 . V_70 != V_813 ) &&
( V_54 . V_69 . V_74 != V_806 ||
V_54 . V_69 . V_70 != V_814 ) )
return - V_11 ;
if ( V_54 . V_67 > 4 )
return - V_11 ;
} else {
V_54 . V_69 . V_70 = 0 ;
V_54 . V_69 . V_54 = NULL ;
}
if ( V_54 . V_67 >= 0 ) {
int V_117 ;
bool V_815 = false ;
for ( V_117 = 0 ; V_117 < V_4 -> V_118 . V_181 ; V_117 ++ ) {
if ( V_54 . V_69 . V_74 == V_4 -> V_118 . V_182 [ V_117 ] ) {
V_815 = true ;
break;
}
}
if ( ! V_815 )
return - V_11 ;
}
if ( ! V_4 -> V_191 -> V_239 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_39 = F_135 ( & V_4 -> V_118 ,
F_2 ( V_2 -> V_8 [ V_340 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_42 ) )
return - V_11 ;
V_409 = F_19 ( V_2 -> V_8 [ V_812 ] ) ;
V_724 = F_20 ( V_2 -> V_8 [ V_812 ] ) ;
if ( V_2 -> V_8 [ V_717 ] ) {
V_684 = F_19 ( V_2 -> V_8 [ V_717 ] ) ;
V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
}
V_797 = F_2 ( V_2 -> V_8 [ V_811 ] ) ;
if ( ! F_152 ( V_797 ) )
return - V_11 ;
V_810 = ! ! V_2 -> V_8 [ V_816 ] ;
return F_157 ( V_4 , V_6 , V_39 , V_797 , V_349 ,
V_409 , V_724 , V_684 , V_685 ,
V_54 . V_69 . V_54 , V_54 . V_69 . V_70 , V_54 . V_67 ,
V_810 ) ;
}
static int F_158 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_817 * V_818 ,
int V_819 )
{
memset ( V_818 , 0 , sizeof( * V_818 ) ) ;
V_818 -> V_820 = V_2 -> V_8 [ V_821 ] ;
if ( V_2 -> V_8 [ V_186 ] ) {
T_3 V_822 ;
V_822 = F_65 (
V_2 -> V_8 [ V_186 ] ) ;
V_818 -> V_823 = F_159 ( V_822 ) ;
if ( ! ( V_4 -> V_118 . V_35 & V_185 ) &&
V_822 != V_824 )
return - V_11 ;
if ( V_2 -> V_8 [ V_825 ] )
V_818 -> V_826 = true ;
} else
V_818 -> V_823 = F_159 ( V_824 ) ;
if ( V_2 -> V_8 [ V_827 ] ) {
void * V_100 ;
int V_31 , V_117 ;
V_100 = F_19 ( V_2 -> V_8 [ V_827 ] ) ;
V_31 = F_20 ( V_2 -> V_8 [ V_827 ] ) ;
V_818 -> V_828 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
if ( V_818 -> V_828 > V_819 )
return - V_11 ;
memcpy ( V_818 -> V_829 , V_100 , V_31 ) ;
for ( V_117 = 0 ; V_117 < V_818 -> V_828 ; V_117 ++ )
if ( ! F_155 (
V_818 -> V_829 [ V_117 ] ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_830 ] ) {
V_818 -> V_831 =
F_2 ( V_2 -> V_8 [ V_830 ] ) ;
if ( ! F_155 ( V_818 -> V_831 ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_832 ] ) {
V_818 -> V_799 =
F_2 ( V_2 -> V_8 [ V_832 ] ) ;
if ( ! F_153 ( V_818 -> V_799 ) )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_833 ] ) {
void * V_100 ;
int V_31 , V_117 ;
V_100 = F_19 ( V_2 -> V_8 [ V_833 ] ) ;
V_31 = F_20 ( V_2 -> V_8 [ V_833 ] ) ;
V_818 -> V_834 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
memcpy ( V_818 -> V_835 , V_100 , V_31 ) ;
for ( V_117 = 0 ; V_117 < V_818 -> V_828 ; V_117 ++ )
if ( ! F_154 ( V_818 -> V_835 [ V_117 ] ) )
return - V_11 ;
}
return 0 ;
}
static int F_160 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_817 V_836 ;
struct V_38 * V_39 ;
const T_1 * V_349 , * V_409 , * V_684 = NULL , * V_837 = NULL ;
int V_26 , V_724 , V_685 = 0 ;
bool V_838 = false ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_350 ] ||
! V_2 -> V_8 [ V_812 ] ||
! V_2 -> V_8 [ V_340 ] )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_241 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_39 = F_135 ( & V_4 -> V_118 ,
F_2 ( V_2 -> V_8 [ V_340 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_42 ) )
return - V_11 ;
V_409 = F_19 ( V_2 -> V_8 [ V_812 ] ) ;
V_724 = F_20 ( V_2 -> V_8 [ V_812 ] ) ;
if ( V_2 -> V_8 [ V_717 ] ) {
V_684 = F_19 ( V_2 -> V_8 [ V_717 ] ) ;
V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
}
if ( V_2 -> V_8 [ V_839 ] ) {
enum V_840 V_841 =
F_2 ( V_2 -> V_8 [ V_839 ] ) ;
if ( V_841 == V_842 )
V_838 = true ;
else if ( V_841 != V_843 )
return - V_11 ;
}
if ( V_2 -> V_8 [ V_844 ] )
V_837 = F_19 ( V_2 -> V_8 [ V_844 ] ) ;
V_26 = F_158 ( V_4 , V_2 , & V_836 , 1 ) ;
if ( ! V_26 )
V_26 = F_161 ( V_4 , V_6 , V_39 , V_349 , V_837 ,
V_409 , V_724 , V_684 , V_685 , V_838 ,
& V_836 ) ;
return V_26 ;
}
static int F_162 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
const T_1 * V_684 = NULL , * V_349 ;
int V_685 = 0 ;
T_3 V_845 ;
bool V_810 ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_846 ] )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_243 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_845 = F_65 ( V_2 -> V_8 [ V_846 ] ) ;
if ( V_845 == 0 ) {
return - V_11 ;
}
if ( V_2 -> V_8 [ V_717 ] ) {
V_684 = F_19 ( V_2 -> V_8 [ V_717 ] ) ;
V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
}
V_810 = ! ! V_2 -> V_8 [ V_816 ] ;
return F_163 ( V_4 , V_6 , V_349 , V_684 , V_685 , V_845 ,
V_810 ) ;
}
static int F_164 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
const T_1 * V_684 = NULL , * V_349 ;
int V_685 = 0 ;
T_3 V_845 ;
bool V_810 ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_846 ] )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_245 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_845 = F_65 ( V_2 -> V_8 [ V_846 ] ) ;
if ( V_845 == 0 ) {
return - V_11 ;
}
if ( V_2 -> V_8 [ V_717 ] ) {
V_684 = F_19 ( V_2 -> V_8 [ V_717 ] ) ;
V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
}
V_810 = ! ! V_2 -> V_8 [ V_816 ] ;
return F_165 ( V_4 , V_6 , V_349 , V_684 , V_685 , V_845 ,
V_810 ) ;
}
static bool
F_166 ( struct V_3 * V_4 ,
int V_847 [ V_200 ] ,
int V_848 )
{
struct V_118 * V_118 = & V_4 -> V_118 ;
bool V_849 = false ;
int V_151 , V_117 ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
struct V_850 * V_851 ;
V_851 = V_118 -> V_201 [ V_151 ] ;
if ( ! V_851 )
continue;
for ( V_117 = 0 ; V_117 < V_851 -> V_216 ; V_117 ++ ) {
if ( V_851 -> V_217 [ V_117 ] . V_219 == V_848 ) {
V_847 [ V_151 ] = V_117 + 1 ;
V_849 = true ;
break;
}
}
}
return V_849 ;
}
static int F_167 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_852 V_853 ;
struct V_118 * V_118 ;
struct V_92 * V_854 = NULL ;
int V_26 ;
memset ( & V_853 , 0 , sizeof( V_853 ) ) ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_340 ] ||
! V_2 -> V_8 [ V_812 ] ||
! F_20 ( V_2 -> V_8 [ V_812 ] ) )
return - V_11 ;
V_853 . V_450 = 100 ;
if ( V_2 -> V_8 [ V_439 ] ) {
V_853 . V_450 =
F_2 ( V_2 -> V_8 [ V_439 ] ) ;
if ( V_853 . V_450 < 1 || V_853 . V_450 > 10000 )
return - V_11 ;
}
if ( ! V_4 -> V_191 -> V_247 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_108 )
return - V_341 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_350 ] )
V_853 . V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_853 . V_409 = F_19 ( V_2 -> V_8 [ V_812 ] ) ;
V_853 . V_724 = F_20 ( V_2 -> V_8 [ V_812 ] ) ;
if ( V_2 -> V_8 [ V_717 ] ) {
V_853 . V_684 = F_19 ( V_2 -> V_8 [ V_717 ] ) ;
V_853 . V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
}
V_853 . V_752 = F_135 ( V_118 ,
F_2 ( V_2 -> V_8 [ V_340 ] ) ) ;
if ( ! V_853 . V_752 ||
V_853 . V_752 -> V_35 & V_46 ||
V_853 . V_752 -> V_35 & V_42 )
return - V_11 ;
V_853 . V_855 = ! ! V_2 -> V_8 [ V_856 ] ;
V_853 . V_857 = ! ! V_2 -> V_8 [ V_858 ] ;
if ( V_2 -> V_8 [ V_602 ] ) {
T_1 * V_859 =
F_19 ( V_2 -> V_8 [ V_602 ] ) ;
int V_860 =
F_20 ( V_2 -> V_8 [ V_602 ] ) ;
struct V_850 * V_851 =
V_118 -> V_201 [ V_853 . V_752 -> V_151 ] ;
int V_117 , V_120 ;
if ( V_860 == 0 )
return - V_11 ;
for ( V_117 = 0 ; V_117 < V_860 ; V_117 ++ ) {
int V_153 = ( V_859 [ V_117 ] & 0x7f ) * 5 ;
bool V_849 = false ;
for ( V_120 = 0 ; V_120 < V_851 -> V_216 ; V_120 ++ ) {
if ( V_851 -> V_217 [ V_120 ] . V_219 == V_153 ) {
V_849 = true ;
V_853 . V_603 |= F_101 ( V_120 ) ;
break;
}
}
if ( ! V_849 )
return - V_11 ;
}
}
if ( V_2 -> V_8 [ V_861 ] &&
! F_166 ( V_4 , V_853 . V_847 ,
F_2 ( V_2 -> V_8 [ V_861 ] ) ) )
return - V_11 ;
if ( V_853 . V_857 && V_2 -> V_8 [ V_862 ] ) {
V_854 = F_32 ( V_4 ,
V_2 -> V_8 [ V_862 ] ) ;
if ( F_6 ( V_854 ) )
return F_8 ( V_854 ) ;
}
V_26 = F_168 ( V_4 , V_6 , & V_853 , V_854 ) ;
if ( V_26 )
F_37 ( V_854 ) ;
return V_26 ;
}
static int F_169 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
if ( ! V_4 -> V_191 -> V_863 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_108 )
return - V_341 ;
return F_170 ( V_4 , V_6 , false ) ;
}
static int F_171 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_864 ] )
return - V_11 ;
V_26 = - V_341 ;
if ( V_4 -> V_191 -> V_865 ) {
V_4 -> V_866 = V_2 ;
V_26 = V_4 -> V_191 -> V_865 ( & V_4 -> V_118 ,
F_19 ( V_2 -> V_8 [ V_864 ] ) ,
F_20 ( V_2 -> V_8 [ V_864 ] ) ) ;
V_4 -> V_866 = NULL ;
}
return V_26 ;
}
static struct V_23 *
F_172 ( struct V_3 * V_4 ,
int V_867 , T_2 V_33 , T_2 V_34 , T_11 V_868 )
{
struct V_23 * V_24 ;
void * V_142 ;
struct V_7 * V_100 ;
V_24 = F_61 ( V_867 + 100 , V_868 ) ;
if ( ! V_24 )
return NULL ;
V_142 = F_21 ( V_24 , V_33 , V_34 , 0 , V_869 ) ;
if ( ! V_142 ) {
F_173 ( V_24 ) ;
return NULL ;
}
F_24 ( V_24 , V_157 , V_4 -> V_158 ) ;
V_100 = F_41 ( V_24 , V_864 ) ;
( ( void * * ) V_24 -> V_14 ) [ 0 ] = V_4 ;
( ( void * * ) V_24 -> V_14 ) [ 1 ] = V_142 ;
( ( void * * ) V_24 -> V_14 ) [ 2 ] = V_100 ;
return V_24 ;
V_52:
F_173 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_174 ( struct V_118 * V_118 ,
int V_867 )
{
struct V_3 * V_4 = F_75 ( V_118 ) ;
if ( F_98 ( ! V_4 -> V_866 ) )
return NULL ;
return F_172 ( V_4 , V_867 ,
V_4 -> V_866 -> V_320 ,
V_4 -> V_866 -> V_321 ,
V_97 ) ;
}
int F_175 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = ( ( void * * ) V_24 -> V_14 ) [ 0 ] ;
void * V_142 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_7 * V_100 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
if ( F_98 ( ! V_4 -> V_866 ) ) {
F_173 ( V_24 ) ;
return - V_11 ;
}
F_42 ( V_24 , V_100 ) ;
F_51 ( V_24 , V_142 ) ;
return F_63 ( V_24 , V_4 -> V_866 ) ;
}
struct V_23 * F_176 ( struct V_118 * V_118 ,
int V_867 , T_11 V_868 )
{
struct V_3 * V_4 = F_75 ( V_118 ) ;
return F_172 ( V_4 , V_867 , 0 , 0 , V_868 ) ;
}
void F_177 ( struct V_23 * V_24 , T_11 V_868 )
{
void * V_142 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_7 * V_100 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
F_42 ( V_24 , V_100 ) ;
F_51 ( V_24 , V_142 ) ;
F_178 ( V_24 , 0 , V_870 . V_871 , V_868 ) ;
}
static int F_179 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_872 V_274 ;
struct V_118 * V_118 ;
struct V_92 * V_854 = NULL ;
int V_26 ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
if ( ! F_18 ( V_2 -> V_8 [ V_717 ] ) )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_812 ] ||
! F_20 ( V_2 -> V_8 [ V_812 ] ) )
return - V_11 ;
if ( V_2 -> V_8 [ V_811 ] ) {
V_274 . V_797 =
F_2 ( V_2 -> V_8 [ V_811 ] ) ;
if ( ! F_152 ( V_274 . V_797 ) )
return - V_11 ;
} else
V_274 . V_797 = V_873 ;
V_274 . V_857 = V_2 -> V_8 [ V_858 ] ;
V_26 = F_158 ( V_4 , V_2 , & V_274 . V_836 ,
V_874 ) ;
if ( V_26 )
return V_26 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
V_118 = & V_4 -> V_118 ;
if ( V_2 -> V_8 [ V_350 ] )
V_274 . V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
V_274 . V_409 = F_19 ( V_2 -> V_8 [ V_812 ] ) ;
V_274 . V_724 = F_20 ( V_2 -> V_8 [ V_812 ] ) ;
if ( V_2 -> V_8 [ V_717 ] ) {
V_274 . V_684 = F_19 ( V_2 -> V_8 [ V_717 ] ) ;
V_274 . V_685 = F_20 ( V_2 -> V_8 [ V_717 ] ) ;
}
if ( V_2 -> V_8 [ V_340 ] ) {
V_274 . V_752 =
F_135 ( V_118 ,
F_2 ( V_2 -> V_8 [ V_340 ] ) ) ;
if ( ! V_274 . V_752 ||
V_274 . V_752 -> V_35 & V_42 )
return - V_11 ;
}
if ( V_274 . V_857 && V_2 -> V_8 [ V_862 ] ) {
V_854 = F_32 ( V_4 ,
V_2 -> V_8 [ V_862 ] ) ;
if ( F_6 ( V_854 ) )
return F_8 ( V_854 ) ;
}
V_26 = F_180 ( V_4 , V_6 , & V_274 , V_854 ) ;
if ( V_26 )
F_37 ( V_854 ) ;
return V_26 ;
}
static int F_181 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_3 V_875 ;
if ( ! V_2 -> V_8 [ V_846 ] )
V_875 = V_876 ;
else
V_875 = F_65 ( V_2 -> V_8 [ V_846 ] ) ;
if ( V_875 == 0 )
return - V_11 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
return F_182 ( V_4 , V_6 , V_875 , true ) ;
}
static int F_183 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_877 * V_877 ;
int V_26 ;
T_2 V_33 ;
if ( ! V_2 -> V_8 [ V_878 ] )
return - V_11 ;
V_33 = F_2 ( V_2 -> V_8 [ V_878 ] ) ;
V_877 = F_184 ( V_33 ) ;
if ( F_6 ( V_877 ) )
return F_8 ( V_877 ) ;
V_26 = 0 ;
if ( ! F_56 ( F_57 ( & V_4 -> V_118 ) , V_877 ) )
V_26 = F_185 ( V_4 , V_877 ) ;
F_186 ( V_877 ) ;
return V_26 ;
}
static int F_187 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
int (* F_188)( struct V_118 * V_118 , struct V_5 * V_6 ,
struct V_879 * V_880 ) = NULL ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_879 V_880 ;
memset ( & V_880 , 0 , sizeof( struct V_879 ) ) ;
if ( ! V_2 -> V_8 [ V_350 ] )
return - V_11 ;
if ( ! V_2 -> V_8 [ V_881 ] )
return - V_11 ;
V_880 . V_882 = F_19 ( V_2 -> V_8 [ V_881 ] ) ;
V_880 . V_349 = F_19 ( V_2 -> V_8 [ V_350 ] ) ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
switch ( V_2 -> V_437 -> V_36 ) {
case V_883 :
F_188 = V_4 -> V_191 -> V_251 ;
break;
case V_884 :
F_188 = V_4 -> V_191 -> V_253 ;
break;
default:
F_98 ( 1 ) ;
break;
}
if ( ! F_188 )
return - V_341 ;
return F_188 ( & V_4 -> V_118 , V_6 , & V_880 ) ;
}
static int F_189 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_112 )
return - V_341 ;
if ( ! V_4 -> V_191 -> V_255 )
return - V_341 ;
return V_4 -> V_191 -> V_255 ( & V_4 -> V_118 , V_6 ) ;
}
static int F_190 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_38 * V_39 ;
struct V_23 * V_37 ;
void * V_142 ;
T_12 V_416 ;
enum V_336 V_337 = V_338 ;
T_2 V_339 , V_885 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_340 ] ||
! V_2 -> V_8 [ V_886 ] )
return - V_11 ;
V_885 = F_2 ( V_2 -> V_8 [ V_886 ] ) ;
if ( ! V_885 || ! F_191 ( V_885 ) ||
V_885 > V_4 -> V_118 . V_279 )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_257 )
return - V_341 ;
if ( V_2 -> V_8 [ V_342 ] ) {
V_337 = F_2 (
V_2 -> V_8 [ V_342 ] ) ;
if ( V_337 != V_338 &&
V_337 != V_343 &&
V_337 != V_344 &&
V_337 != V_345 )
return - V_11 ;
}
V_339 = F_2 ( V_2 -> V_8 [ V_340 ] ) ;
V_39 = F_192 ( V_4 , V_339 , V_337 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_887 ) ;
if ( F_6 ( V_142 ) ) {
V_26 = F_8 ( V_142 ) ;
goto V_427;
}
V_26 = V_4 -> V_191 -> V_257 ( & V_4 -> V_118 , V_6 , V_39 ,
V_337 , V_885 , & V_416 ) ;
if ( V_26 )
goto V_427;
F_144 ( V_37 , V_888 , V_416 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_427:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_193 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_12 V_416 ;
if ( ! V_2 -> V_8 [ V_888 ] )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_889 )
return - V_341 ;
V_416 = F_194 ( V_2 -> V_8 [ V_888 ] ) ;
return V_4 -> V_191 -> V_889 ( & V_4 -> V_118 , V_6 , V_416 ) ;
}
static T_2 F_195 ( struct V_850 * V_851 ,
T_1 * V_859 , T_1 V_890 )
{
T_1 V_117 ;
T_2 V_458 = 0 ;
for ( V_117 = 0 ; V_117 < V_890 ; V_117 ++ ) {
int V_153 = ( V_859 [ V_117 ] & 0x7f ) * 5 ;
int V_891 ;
for ( V_891 = 0 ; V_891 < V_851 -> V_216 ; V_891 ++ ) {
struct V_152 * V_892 =
& V_851 -> V_217 [ V_891 ] ;
if ( V_153 == V_892 -> V_219 ) {
V_458 |= 1 << V_891 ;
break;
}
}
if ( V_891 == V_851 -> V_216 )
return 0 ;
}
return V_458 ;
}
static int F_196 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_7 * V_57 [ V_893 + 1 ] ;
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_894 V_458 ;
int V_96 , V_117 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_7 * V_895 ;
struct V_850 * V_851 ;
if ( V_2 -> V_8 [ V_896 ] == NULL )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_259 )
return - V_341 ;
memset ( & V_458 , 0 , sizeof( V_458 ) ) ;
for ( V_117 = 0 ; V_117 < V_200 ; V_117 ++ ) {
V_851 = V_4 -> V_118 . V_201 [ V_117 ] ;
V_458 . V_897 [ V_117 ] . V_898 =
V_851 ? ( 1 << V_851 -> V_216 ) - 1 : 0 ;
}
F_35 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_150 V_151 = F_197 ( V_895 ) ;
if ( V_151 < 0 || V_151 >= V_200 )
return - V_11 ;
V_851 = V_4 -> V_118 . V_201 [ V_151 ] ;
if ( V_851 == NULL )
return - V_11 ;
F_78 ( V_57 , V_893 , F_19 ( V_895 ) ,
F_20 ( V_895 ) , V_899 ) ;
if ( V_57 [ V_900 ] ) {
V_458 . V_897 [ V_151 ] . V_898 = F_195 (
V_851 ,
F_19 ( V_57 [ V_900 ] ) ,
F_20 ( V_57 [ V_900 ] ) ) ;
if ( V_458 . V_897 [ V_151 ] . V_898 == 0 )
return - V_11 ;
}
}
return V_4 -> V_191 -> V_259 ( & V_4 -> V_118 , V_6 , NULL , & V_458 ) ;
}
static int F_198 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_3 V_901 = V_290 | V_902 ;
if ( ! V_2 -> V_8 [ V_903 ] )
return - V_11 ;
if ( V_2 -> V_8 [ V_289 ] )
V_901 = F_65 ( V_2 -> V_8 [ V_289 ] ) ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_108 &&
V_6 -> V_348 -> V_103 != V_112 &&
V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_105 &&
V_6 -> V_348 -> V_103 != V_107 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_341 ;
if ( ! V_4 -> V_191 -> V_261 )
return - V_341 ;
return F_199 ( V_6 -> V_348 , V_2 -> V_320 ,
V_901 ,
F_19 ( V_2 -> V_8 [ V_903 ] ) ,
F_20 ( V_2 -> V_8 [ V_903 ] ) ) ;
}
static int F_200 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_38 * V_39 ;
enum V_336 V_337 = V_338 ;
bool V_904 = false ;
T_2 V_339 ;
int V_26 ;
void * V_142 ;
T_12 V_416 ;
struct V_23 * V_37 ;
unsigned int V_905 = 0 ;
bool V_906 ;
if ( ! V_2 -> V_8 [ V_907 ] ||
! V_2 -> V_8 [ V_340 ] )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_261 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_108 &&
V_6 -> V_348 -> V_103 != V_112 &&
V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_105 &&
V_6 -> V_348 -> V_103 != V_107 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_341 ;
if ( V_2 -> V_8 [ V_886 ] ) {
if ( ! V_4 -> V_191 -> V_263 )
return - V_11 ;
V_905 = F_2 ( V_2 -> V_8 [ V_886 ] ) ;
}
if ( V_2 -> V_8 [ V_342 ] ) {
V_337 = F_2 (
V_2 -> V_8 [ V_342 ] ) ;
if ( V_337 != V_338 &&
V_337 != V_343 &&
V_337 != V_344 &&
V_337 != V_345 )
return - V_11 ;
V_904 = true ;
}
V_906 = V_2 -> V_8 [ V_280 ] ;
V_339 = F_2 ( V_2 -> V_8 [ V_340 ] ) ;
V_39 = F_192 ( V_4 , V_339 , V_337 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_908 ) ;
if ( F_6 ( V_142 ) ) {
V_26 = F_8 ( V_142 ) ;
goto V_427;
}
V_26 = F_201 ( V_4 , V_6 , V_39 , V_906 , V_337 ,
V_904 , V_905 ,
F_19 ( V_2 -> V_8 [ V_907 ] ) ,
F_20 ( V_2 -> V_8 [ V_907 ] ) ,
& V_416 ) ;
if ( V_26 )
goto V_427;
F_144 ( V_37 , V_888 , V_416 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_427:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_202 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_12 V_416 ;
if ( ! V_2 -> V_8 [ V_888 ] )
return - V_11 ;
if ( ! V_4 -> V_191 -> V_263 )
return - V_341 ;
if ( V_6 -> V_348 -> V_103 != V_111 &&
V_6 -> V_348 -> V_103 != V_108 &&
V_6 -> V_348 -> V_103 != V_112 &&
V_6 -> V_348 -> V_103 != V_104 &&
V_6 -> V_348 -> V_103 != V_105 &&
V_6 -> V_348 -> V_103 != V_106 )
return - V_341 ;
V_416 = F_194 ( V_2 -> V_8 [ V_888 ] ) ;
return V_4 -> V_191 -> V_263 ( & V_4 -> V_118 , V_6 , V_416 ) ;
}
static int F_203 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
T_1 V_909 ;
bool V_910 ;
int V_26 ;
if ( ! V_2 -> V_8 [ V_911 ] )
return - V_11 ;
V_909 = F_2 ( V_2 -> V_8 [ V_911 ] ) ;
if ( V_909 != V_912 && V_909 != V_913 )
return - V_11 ;
V_102 = V_6 -> V_348 ;
if ( ! V_4 -> V_191 -> V_914 )
return - V_341 ;
V_910 = ( V_909 == V_913 ) ? true : false ;
if ( V_910 == V_102 -> V_915 )
return 0 ;
V_26 = V_4 -> V_191 -> V_914 ( V_102 -> V_118 , V_6 , V_910 ,
V_102 -> V_916 ) ;
if ( ! V_26 )
V_102 -> V_915 = V_910 ;
return V_26 ;
}
static int F_204 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
enum V_917 V_909 ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_23 * V_37 ;
void * V_142 ;
int V_26 ;
V_102 = V_6 -> V_348 ;
if ( ! V_4 -> V_191 -> V_914 )
return - V_341 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_918 ) ;
if ( ! V_142 ) {
V_26 = - V_53 ;
goto V_427;
}
if ( V_102 -> V_915 )
V_909 = V_913 ;
else
V_909 = V_912 ;
F_24 ( V_37 , V_911 , V_909 ) ;
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
V_26 = - V_53 ;
V_427:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_205 ( struct V_1 * V_2 ,
T_13 V_919 , T_2 V_920 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_101 * V_102 ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
if ( V_919 > 0 )
return - V_11 ;
V_102 = V_6 -> V_348 ;
if ( ! V_4 -> V_191 -> V_921 )
return - V_341 ;
if ( V_102 -> V_103 != V_111 &&
V_102 -> V_103 != V_112 )
return - V_341 ;
return V_4 -> V_191 -> V_921 ( V_102 -> V_118 , V_6 ,
V_919 , V_920 ) ;
}
static int F_206 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_7 * V_8 [ V_922 + 1 ] ;
struct V_7 * V_923 ;
int V_26 ;
V_923 = V_2 -> V_8 [ V_924 ] ;
if ( ! V_923 ) {
V_26 = - V_11 ;
goto V_388;
}
V_26 = F_28 ( V_8 , V_922 , V_923 ,
V_925 ) ;
if ( V_26 )
goto V_388;
if ( V_8 [ V_926 ] &&
V_8 [ V_927 ] ) {
T_13 V_919 ;
T_2 V_920 ;
V_919 = F_2 ( V_8 [ V_926 ] ) ;
V_920 = F_2 ( V_8 [ V_927 ] ) ;
V_26 = F_205 ( V_2 , V_919 , V_920 ) ;
} else
V_26 = - V_11 ;
V_388:
return V_26 ;
}
static int F_207 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
struct V_628 V_665 ;
struct V_669 V_670 ;
int V_26 ;
memcpy ( & V_665 , & V_632 , sizeof( V_665 ) ) ;
memcpy ( & V_670 , & V_928 , sizeof( V_670 ) ) ;
if ( V_2 -> V_8 [ V_634 ] ) {
V_26 = F_123 ( V_2 , & V_665 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_2 -> V_8 [ V_405 ] ||
! F_20 ( V_2 -> V_8 [ V_405 ] ) )
return - V_11 ;
V_670 . V_929 = F_19 ( V_2 -> V_8 [ V_405 ] ) ;
V_670 . V_631 = F_20 ( V_2 -> V_8 [ V_405 ] ) ;
if ( V_2 -> V_8 [ V_672 ] ) {
V_26 = F_125 ( V_2 , & V_670 ) ;
if ( V_26 )
return V_26 ;
}
return F_208 ( V_4 , V_6 , & V_670 , & V_665 ) ;
}
static int F_209 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_5 * V_6 = V_2 -> V_318 [ 1 ] ;
return F_210 ( V_4 , V_6 ) ;
}
static int F_211 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_23 * V_37 ;
void * V_142 ;
if ( ! V_4 -> V_118 . V_293 . V_35 && ! V_4 -> V_118 . V_293 . V_294 )
return - V_341 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , V_2 -> V_320 , V_2 -> V_321 , 0 ,
V_930 ) ;
if ( ! V_142 )
goto V_52;
if ( V_4 -> V_293 ) {
struct V_7 * V_295 ;
V_295 = F_41 ( V_37 , V_931 ) ;
if ( ! V_295 )
goto V_52;
if ( V_4 -> V_293 -> V_932 )
F_25 ( V_37 , V_298 ) ;
if ( V_4 -> V_293 -> V_276 )
F_25 ( V_37 , V_300 ) ;
if ( V_4 -> V_293 -> V_933 )
F_25 ( V_37 , V_302 ) ;
if ( V_4 -> V_293 -> V_294 ) {
struct V_7 * V_934 , * V_935 ;
int V_117 , V_936 ;
V_934 = F_41 ( V_37 ,
V_310 ) ;
if ( ! V_934 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_4 -> V_293 -> V_294 ; V_117 ++ ) {
V_935 = F_41 ( V_37 , V_117 + 1 ) ;
if ( ! V_935 )
goto V_52;
V_936 = V_4 -> V_293 -> V_937 [ V_117 ] . V_938 ;
F_49 ( V_37 , V_939 ,
F_212 ( V_936 , 8 ) ,
V_4 -> V_293 -> V_937 [ V_117 ] . V_458 ) ;
F_49 ( V_37 , V_940 ,
V_936 ,
V_4 -> V_293 -> V_937 [ V_117 ] . V_941 ) ;
F_42 ( V_37 , V_935 ) ;
}
F_42 ( V_37 , V_934 ) ;
}
F_42 ( V_37 , V_295 ) ;
}
F_51 ( V_37 , V_142 ) ;
return F_63 ( V_37 , V_2 ) ;
V_52:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_213 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_318 [ 0 ] ;
struct V_7 * V_57 [ V_942 ] ;
struct V_943 V_944 = {} ;
struct V_943 V_945 = {} ;
struct V_946 * V_293 = & V_4 -> V_118 . V_293 ;
int V_26 , V_117 ;
if ( ! V_4 -> V_118 . V_293 . V_35 && ! V_4 -> V_118 . V_293 . V_294 )
return - V_341 ;
if ( ! V_2 -> V_8 [ V_931 ] )
goto V_944;
V_26 = F_78 ( V_57 , V_947 ,
F_19 ( V_2 -> V_8 [ V_931 ] ) ,
F_20 ( V_2 -> V_8 [ V_931 ] ) ,
V_948 ) ;
if ( V_26 )
return V_26 ;
if ( V_57 [ V_298 ] ) {
if ( ! ( V_293 -> V_35 & V_297 ) )
return - V_11 ;
V_945 . V_932 = true ;
}
if ( V_57 [ V_300 ] ) {
if ( ! ( V_293 -> V_35 & V_299 ) )
return - V_11 ;
V_945 . V_276 = true ;
}
if ( V_57 [ V_302 ] ) {
if ( ! ( V_293 -> V_35 & V_301 ) )
return - V_11 ;
V_945 . V_933 = true ;
}
if ( V_57 [ V_310 ] ) {
struct V_7 * V_304 ;
int V_294 = 0 ;
int V_96 , V_936 , V_949 ;
struct V_7 * V_950 [ V_951 ] ;
F_35 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_294 ++ ;
if ( V_294 > V_293 -> V_294 )
return - V_11 ;
V_945 . V_937 = F_214 ( V_294 ,
sizeof( V_945 . V_937 [ 0 ] ) ,
V_97 ) ;
if ( ! V_945 . V_937 )
return - V_98 ;
V_945 . V_294 = V_294 ;
V_117 = 0 ;
F_35 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_78 ( V_950 , V_952 ,
F_19 ( V_304 ) , F_20 ( V_304 ) , NULL ) ;
V_26 = - V_11 ;
if ( ! V_950 [ V_939 ] ||
! V_950 [ V_940 ] )
goto error;
V_936 = F_20 ( V_950 [ V_940 ] ) ;
V_949 = F_212 ( V_936 , 8 ) ;
if ( F_20 ( V_950 [ V_939 ] ) !=
V_949 )
goto error;
if ( V_936 > V_293 -> V_309 ||
V_936 < V_293 -> V_307 )
goto error;
V_945 . V_937 [ V_117 ] . V_458 =
F_215 ( V_949 + V_936 , V_97 ) ;
if ( ! V_945 . V_937 [ V_117 ] . V_458 ) {
V_26 = - V_98 ;
goto error;
}
V_945 . V_937 [ V_117 ] . V_941 =
V_945 . V_937 [ V_117 ] . V_458 + V_949 ;
memcpy ( V_945 . V_937 [ V_117 ] . V_458 ,
F_19 ( V_950 [ V_939 ] ) ,
V_949 ) ;
V_945 . V_937 [ V_117 ] . V_938 = V_936 ;
memcpy ( V_945 . V_937 [ V_117 ] . V_941 ,
F_19 ( V_950 [ V_940 ] ) ,
V_936 ) ;
V_117 ++ ;
}
}
if ( memcmp ( & V_945 , & V_944 , sizeof( V_945 ) ) ) {
struct V_943 * V_953 ;
V_953 = F_216 ( & V_945 , sizeof( V_945 ) ,
V_97 ) ;
if ( ! V_953 ) {
V_26 = - V_98 ;
goto error;
}
F_217 ( V_4 ) ;
V_4 -> V_293 = V_953 ;
} else {
V_944:
F_217 ( V_4 ) ;
V_4 -> V_293 = NULL ;
}
return 0 ;
error:
for ( V_117 = 0 ; V_117 < V_945 . V_294 ; V_117 ++ )
F_37 ( V_945 . V_937 [ V_117 ] . V_458 ) ;
F_37 ( V_945 . V_937 ) ;
return V_26 ;
}
static int F_218 ( struct V_954 * V_191 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_26 ;
bool V_955 = V_191 -> V_956 & V_957 ;
if ( V_955 )
F_12 () ;
if ( V_191 -> V_956 & V_958 ) {
V_4 = F_219 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
if ( V_955 )
F_15 () ;
return F_8 ( V_4 ) ;
}
V_2 -> V_318 [ 0 ] = V_4 ;
} else if ( V_191 -> V_956 & V_959 ) {
V_26 = F_1 ( V_2 , & V_4 , & V_6 ) ;
if ( V_26 ) {
if ( V_955 )
F_15 () ;
return V_26 ;
}
if ( V_191 -> V_956 & V_960 &&
! F_73 ( V_6 ) ) {
F_17 ( V_4 ) ;
F_7 ( V_6 ) ;
if ( V_955 )
F_15 () ;
return - V_542 ;
}
V_2 -> V_318 [ 0 ] = V_4 ;
V_2 -> V_318 [ 1 ] = V_6 ;
}
return 0 ;
}
static void F_220 ( struct V_954 * V_191 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_318 [ 0 ] )
F_17 ( V_2 -> V_318 [ 0 ] ) ;
if ( V_2 -> V_318 [ 1 ] )
F_7 ( V_2 -> V_318 [ 1 ] ) ;
if ( V_191 -> V_956 & V_957 )
F_15 () ;
}
void F_221 ( struct V_3 * V_4 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_44 ( V_37 , 0 , 0 , 0 , V_4 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_961 . V_871 , V_97 ) ;
}
static int F_223 ( struct V_23 * V_37 ,
struct V_3 * V_4 )
{
struct V_713 * V_962 = V_4 -> V_719 ;
struct V_7 * V_963 ;
int V_117 ;
F_224 ( V_4 ) ;
if ( F_98 ( ! V_962 ) )
return 0 ;
V_963 = F_41 ( V_37 , V_721 ) ;
if ( ! V_963 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_962 -> V_716 ; V_117 ++ )
F_49 ( V_37 , V_117 , V_962 -> V_722 [ V_117 ] . V_724 , V_962 -> V_722 [ V_117 ] . V_409 ) ;
F_42 ( V_37 , V_963 ) ;
V_963 = F_41 ( V_37 , V_720 ) ;
if ( ! V_963 )
goto V_52;
for ( V_117 = 0 ; V_117 < V_962 -> V_213 ; V_117 ++ )
F_24 ( V_37 , V_117 , V_962 -> V_214 [ V_117 ] -> V_41 ) ;
F_42 ( V_37 , V_963 ) ;
if ( V_962 -> V_684 )
F_49 ( V_37 , V_717 , V_962 -> V_685 , V_962 -> V_684 ) ;
return 0 ;
V_52:
return - V_53 ;
}
static int F_225 ( struct V_23 * V_37 ,
struct V_3 * V_4 ,
struct V_5 * V_347 ,
T_2 V_33 , T_2 V_34 , int V_35 ,
T_2 V_36 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_223 ( V_37 , V_4 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
static int
F_226 ( struct V_23 * V_37 ,
struct V_3 * V_4 ,
struct V_5 * V_347 ,
T_2 V_33 , T_2 V_34 , int V_35 , T_2 V_36 )
{
void * V_142 ;
V_142 = F_21 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_142 )
return - 1 ;
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
return F_51 ( V_37 , V_142 ) ;
V_52:
F_52 ( V_37 , V_142 ) ;
return - V_313 ;
}
void F_136 ( struct V_3 * V_4 ,
struct V_5 * V_347 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_964 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_225 ( V_37 , V_4 , V_347 , 0 , 0 , 0 ,
V_965 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_966 . V_871 , V_97 ) ;
}
void F_227 ( struct V_3 * V_4 ,
struct V_5 * V_347 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_225 ( V_37 , V_4 , V_347 , 0 , 0 , 0 ,
V_736 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_966 . V_871 , V_97 ) ;
}
void F_228 ( struct V_3 * V_4 ,
struct V_5 * V_347 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_225 ( V_37 , V_4 , V_347 , 0 , 0 , 0 ,
V_967 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_966 . V_871 , V_97 ) ;
}
void F_229 ( struct V_3 * V_4 ,
struct V_5 * V_347 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_226 ( V_37 , V_4 , V_347 , 0 , 0 , 0 ,
V_968 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_966 . V_871 , V_97 ) ;
}
void F_139 ( struct V_3 * V_4 ,
struct V_5 * V_347 , T_2 V_36 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_964 , V_97 ) ;
if ( ! V_37 )
return;
if ( F_226 ( V_37 , V_4 , V_347 , 0 , 0 , 0 , V_36 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_966 . V_871 , V_97 ) ;
}
void F_230 ( struct V_969 * V_714 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_97 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_970 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_47 ( V_37 , V_971 , V_714 -> V_972 ) ;
if ( V_714 -> V_693 [ 0 ] == '0' && V_714 -> V_693 [ 1 ] == '0' )
F_47 ( V_37 , V_973 ,
V_974 ) ;
else if ( V_714 -> V_693 [ 0 ] == '9' && V_714 -> V_693 [ 1 ] == '9' )
F_47 ( V_37 , V_973 ,
V_975 ) ;
else if ( ( V_714 -> V_693 [ 0 ] == '9' && V_714 -> V_693 [ 1 ] == '8' ) ||
V_714 -> V_976 )
F_47 ( V_37 , V_973 ,
V_977 ) ;
else {
F_47 ( V_37 , V_973 ,
V_978 ) ;
F_45 ( V_37 , V_627 , V_714 -> V_693 ) ;
}
if ( F_231 ( V_714 -> V_158 ) )
F_24 ( V_37 , V_157 , V_714 -> V_158 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_232 () ;
F_233 ( V_37 , 0 , V_979 . V_871 ,
V_980 ) ;
F_234 () ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static void F_235 ( struct V_3 * V_4 ,
struct V_5 * V_347 ,
const T_1 * V_981 , T_10 V_31 ,
enum V_982 V_36 , T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_49 ( V_37 , V_907 , V_31 , V_981 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_236 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_981 ,
T_10 V_31 , T_11 V_868 )
{
F_235 ( V_4 , V_347 , V_981 , V_31 ,
V_984 , V_868 ) ;
}
void F_237 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_981 ,
T_10 V_31 , T_11 V_868 )
{
F_235 ( V_4 , V_347 , V_981 , V_31 ,
V_985 , V_868 ) ;
}
void F_238 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_981 ,
T_10 V_31 , T_11 V_868 )
{
F_235 ( V_4 , V_347 , V_981 , V_31 ,
V_986 , V_868 ) ;
}
void F_239 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_981 ,
T_10 V_31 , T_11 V_868 )
{
F_235 ( V_4 , V_347 , V_981 , V_31 ,
V_987 , V_868 ) ;
}
void F_240 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_981 ,
T_10 V_31 , T_11 V_868 )
{
F_235 ( V_4 , V_347 , V_981 , V_31 ,
V_988 , V_868 ) ;
}
void F_241 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_981 ,
T_10 V_31 , T_11 V_868 )
{
F_235 ( V_4 , V_347 , V_981 , V_31 ,
V_989 , V_868 ) ;
}
static void F_242 ( struct V_3 * V_4 ,
struct V_5 * V_347 , int V_36 ,
const T_1 * V_990 , T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_25 ( V_37 , V_991 ) ;
F_49 ( V_37 , V_350 , V_425 , V_990 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_243 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_990 ,
T_11 V_868 )
{
F_242 ( V_4 , V_347 , V_984 ,
V_990 , V_868 ) ;
}
void F_244 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_990 ,
T_11 V_868 )
{
F_242 ( V_4 , V_347 , V_985 ,
V_990 , V_868 ) ;
}
void F_245 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_349 ,
const T_1 * V_992 , T_10 V_993 ,
const T_1 * V_994 , T_10 V_995 ,
T_3 V_996 , T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_964 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_275 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
if ( V_349 )
F_49 ( V_37 , V_350 , V_425 , V_349 ) ;
F_48 ( V_37 , V_997 , V_996 ) ;
if ( V_992 )
F_49 ( V_37 , V_998 , V_993 , V_992 ) ;
if ( V_994 )
F_49 ( V_37 , V_999 , V_995 , V_994 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_246 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_349 ,
const T_1 * V_992 , T_10 V_993 ,
const T_1 * V_994 , T_10 V_995 , T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_964 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1000 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_49 ( V_37 , V_350 , V_425 , V_349 ) ;
if ( V_992 )
F_49 ( V_37 , V_998 , V_993 , V_992 ) ;
if ( V_994 )
F_49 ( V_37 , V_999 , V_995 , V_994 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_247 ( struct V_3 * V_4 ,
struct V_5 * V_347 , T_3 V_875 ,
const T_1 * V_684 , T_10 V_685 , bool V_1001 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_964 , V_97 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_277 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
if ( V_1001 && V_875 )
F_48 ( V_37 , V_846 , V_875 ) ;
if ( V_1001 )
F_25 ( V_37 , V_1002 ) ;
if ( V_684 )
F_49 ( V_37 , V_717 , V_685 , V_684 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_97 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_248 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_349 ,
T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1003 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_49 ( V_37 , V_350 , V_425 , V_349 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_249 ( struct V_3 * V_4 ,
struct V_5 * V_347 ,
const T_1 * V_1004 , const T_1 * V_684 , T_1 V_685 ,
T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1005 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_49 ( V_37 , V_350 , V_425 , V_1004 ) ;
if ( V_685 && V_684 )
F_49 ( V_37 , V_717 , V_685 , V_684 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_250 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_990 ,
enum V_1006 V_1007 , int V_1008 ,
const T_1 * V_1009 , T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1010 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
if ( V_990 )
F_49 ( V_37 , V_350 , V_425 , V_990 ) ;
F_24 ( V_37 , V_89 , V_1007 ) ;
if ( V_1008 != - 1 )
F_47 ( V_37 , V_85 , V_1008 ) ;
if ( V_1009 )
F_49 ( V_37 , V_84 , 6 , V_1009 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_251 ( struct V_118 * V_118 ,
struct V_38 * V_1011 ,
struct V_38 * V_1012 )
{
struct V_23 * V_37 ;
void * V_142 ;
struct V_7 * V_146 ;
V_37 = F_61 ( V_319 , V_980 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1013 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , F_252 ( V_118 ) ) ;
V_146 = F_41 ( V_37 , V_1014 ) ;
if ( ! V_146 )
goto V_52;
if ( F_23 ( V_37 , V_1011 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
V_146 = F_41 ( V_37 , V_1015 ) ;
if ( ! V_146 )
goto V_52;
if ( F_23 ( V_37 , V_1012 ) )
goto V_52;
F_42 ( V_37 , V_146 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_232 () ;
F_233 ( V_37 , 0 , V_979 . V_871 ,
V_980 ) ;
F_234 () ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static void F_253 (
int V_36 , struct V_3 * V_4 ,
struct V_5 * V_347 , T_12 V_416 ,
struct V_38 * V_39 ,
enum V_336 V_337 ,
unsigned int V_885 , T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_24 ( V_37 , V_340 , V_39 -> V_41 ) ;
F_24 ( V_37 , V_342 , V_337 ) ;
F_144 ( V_37 , V_888 , V_416 ) ;
if ( V_36 == V_887 )
F_24 ( V_37 , V_886 , V_885 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void F_254 ( struct V_3 * V_4 ,
struct V_5 * V_347 , T_12 V_416 ,
struct V_38 * V_39 ,
enum V_336 V_337 ,
unsigned int V_885 , T_11 V_868 )
{
F_253 ( V_887 ,
V_4 , V_347 , V_416 , V_39 ,
V_337 , V_885 , V_868 ) ;
}
void F_255 (
struct V_3 * V_4 , struct V_5 * V_347 ,
T_12 V_416 , struct V_38 * V_39 ,
enum V_336 V_337 , T_11 V_868 )
{
F_253 ( V_1016 ,
V_4 , V_347 , V_416 , V_39 ,
V_337 , 0 , V_868 ) ;
}
void F_256 ( struct V_3 * V_4 ,
struct V_5 * V_6 , const T_1 * V_418 ,
struct V_473 * V_474 , T_11 V_868 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_964 , V_868 ) ;
if ( ! V_37 )
return;
if ( F_104 ( V_37 , 0 , 0 , 0 , V_6 , V_418 , V_474 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
}
void F_257 ( struct V_3 * V_4 ,
struct V_5 * V_6 , const T_1 * V_418 ,
T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_964 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1017 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_10 , V_6 -> V_9 ) ;
F_49 ( V_37 , V_350 , V_425 , V_418 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
int F_258 ( struct V_3 * V_4 ,
struct V_5 * V_347 , T_2 V_1018 ,
int V_339 , const T_1 * V_981 , T_10 V_31 , T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
int V_26 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return - V_98 ;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_908 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return - V_98 ;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_24 ( V_37 , V_340 , V_339 ) ;
F_49 ( V_37 , V_907 , V_31 , V_981 ) ;
V_26 = F_51 ( V_37 , V_142 ) ;
if ( V_26 < 0 ) {
F_62 ( V_37 ) ;
return V_26 ;
}
V_26 = F_259 ( F_57 ( & V_4 -> V_118 ) , V_37 , V_1018 ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
return - V_53 ;
}
void F_260 ( struct V_3 * V_4 ,
struct V_5 * V_347 , T_12 V_416 ,
const T_1 * V_981 , T_10 V_31 , bool V_1019 ,
T_11 V_868 )
{
struct V_23 * V_37 ;
void * V_142 ;
V_37 = F_61 ( V_319 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1020 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_49 ( V_37 , V_907 , V_31 , V_981 ) ;
F_144 ( V_37 , V_888 , V_416 ) ;
if ( V_1019 )
F_25 ( V_37 , V_1021 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_178 ( V_37 , 0 , V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void
F_261 ( struct V_3 * V_4 ,
struct V_5 * V_347 ,
enum V_1022 V_1023 ,
T_11 V_868 )
{
struct V_23 * V_37 ;
struct V_7 * V_565 ;
void * V_142 ;
V_37 = F_61 ( V_964 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1024 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
V_565 = F_41 ( V_37 , V_924 ) ;
if ( ! V_565 )
goto V_52;
F_24 ( V_37 , V_1025 ,
V_1023 ) ;
F_42 ( V_37 , V_565 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
void
F_262 ( struct V_3 * V_4 ,
struct V_5 * V_347 , const T_1 * V_1026 ,
T_2 V_1027 , T_11 V_868 )
{
struct V_23 * V_37 ;
struct V_7 * V_565 ;
void * V_142 ;
V_37 = F_61 ( V_964 , V_868 ) ;
if ( ! V_37 )
return;
V_142 = F_21 ( V_37 , 0 , 0 , 0 , V_1024 ) ;
if ( ! V_142 ) {
F_62 ( V_37 ) ;
return;
}
F_24 ( V_37 , V_157 , V_4 -> V_158 ) ;
F_24 ( V_37 , V_10 , V_347 -> V_9 ) ;
F_49 ( V_37 , V_350 , V_425 , V_1026 ) ;
V_565 = F_41 ( V_37 , V_924 ) ;
if ( ! V_565 )
goto V_52;
F_24 ( V_37 , V_1028 , V_1027 ) ;
F_42 ( V_37 , V_565 ) ;
if ( F_51 ( V_37 , V_142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_222 ( F_57 ( & V_4 -> V_118 ) , V_37 , 0 ,
V_983 . V_871 , V_868 ) ;
return;
V_52:
F_52 ( V_37 , V_142 ) ;
F_62 ( V_37 ) ;
}
static int F_263 ( struct V_1029 * V_1030 ,
unsigned long V_910 ,
void * V_1031 )
{
struct V_1032 * V_1033 = V_1031 ;
struct V_3 * V_4 ;
struct V_101 * V_102 ;
if ( V_910 != V_1034 )
return V_1035 ;
F_232 () ;
F_264 (rdev, &cfg80211_rdev_list, list)
F_264 (wdev, &rdev->netdev_list, list)
F_265 ( V_102 , V_1033 -> V_33 ) ;
F_234 () ;
return V_1035 ;
}
int F_266 ( void )
{
int V_26 ;
V_26 = F_267 ( & V_18 ,
V_1036 , F_268 ( V_1036 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_269 ( & V_18 , & V_961 ) ;
if ( V_26 )
goto V_1037;
V_26 = F_269 ( & V_18 , & V_966 ) ;
if ( V_26 )
goto V_1037;
V_26 = F_269 ( & V_18 , & V_979 ) ;
if ( V_26 )
goto V_1037;
V_26 = F_269 ( & V_18 , & V_983 ) ;
if ( V_26 )
goto V_1037;
#ifdef F_270
V_26 = F_269 ( & V_18 , & V_870 ) ;
if ( V_26 )
goto V_1037;
#endif
V_26 = F_271 ( & V_1038 ) ;
if ( V_26 )
goto V_1037;
return 0 ;
V_1037:
F_272 ( & V_18 ) ;
return V_26 ;
}
void F_273 ( void )
{
F_274 ( & V_1038 ) ;
F_272 ( & V_18 ) ;
}
