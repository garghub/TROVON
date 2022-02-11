static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 ,
struct V_5 * * V_6 ,
struct V_7 * * V_8 )
{
int V_9 ;
if ( ! V_4 [ V_10 ] )
return - V_11 ;
V_9 = F_2 ( V_4 [ V_10 ] ) ;
* V_8 = F_3 ( V_2 , V_9 ) ;
if ( ! * V_8 )
return - V_12 ;
* V_6 = F_4 ( V_2 , V_9 ) ;
if ( F_5 ( * V_6 ) ) {
F_6 ( * V_8 ) ;
return F_7 ( * V_6 ) ;
}
return 0 ;
}
static int F_8 ( struct V_13 * V_14 )
{
int V_15 ;
V_15 = F_9 ( V_14 -> V_16 , V_17 + V_18 . V_19 ,
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
static int F_10 ( struct V_23 * V_24 ,
struct V_13 * V_14 ,
struct V_5 * * V_6 ,
struct V_7 * * V_8 )
{
int V_25 = V_14 -> args [ 0 ] ;
int V_26 ;
if ( ! V_25 )
V_25 = F_8 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
V_14 -> args [ 0 ] = V_25 ;
F_11 () ;
* V_8 = F_12 ( F_13 ( V_24 -> V_27 ) , V_25 ) ;
if ( ! * V_8 ) {
V_26 = - V_12 ;
goto V_28;
}
* V_6 = F_4 ( F_13 ( V_24 -> V_27 ) , V_25 ) ;
if ( F_5 ( * V_6 ) ) {
V_26 = F_7 ( * V_6 ) ;
goto V_28;
}
return 0 ;
V_28:
F_14 () ;
return V_26 ;
}
static void F_15 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
F_14 () ;
}
static bool F_17 ( const struct V_3 * V_29 )
{
const T_1 * V_30 ;
int V_31 ;
if ( ! V_29 )
return true ;
V_30 = F_18 ( V_29 ) ;
V_31 = F_19 ( V_29 ) ;
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
static inline void * F_20 ( struct V_23 * V_24 , T_2 V_33 , T_2 V_34 ,
int V_35 , T_1 V_36 )
{
return F_21 ( V_24 , V_33 , V_34 , & V_18 , V_35 , V_36 ) ;
}
static int F_22 ( struct V_23 * V_37 ,
struct V_38 * V_39 )
{
if ( F_23 ( V_37 , V_40 ,
V_39 -> V_41 ) )
goto V_42;
if ( ( V_39 -> V_35 & V_43 ) &&
F_24 ( V_37 , V_44 ) )
goto V_42;
if ( ( V_39 -> V_35 & V_45 ) &&
F_24 ( V_37 , V_46 ) )
goto V_42;
if ( ( V_39 -> V_35 & V_47 ) &&
F_24 ( V_37 , V_48 ) )
goto V_42;
if ( ( V_39 -> V_35 & V_49 ) &&
F_24 ( V_37 , V_50 ) )
goto V_42;
if ( F_23 ( V_37 , V_51 ,
F_25 ( V_39 -> V_52 ) ) )
goto V_42;
return 0 ;
V_42:
return - V_53 ;
}
static int F_26 ( struct V_3 * V_54 , struct V_55 * V_56 )
{
struct V_3 * V_57 [ V_58 + 1 ] ;
int V_26 = F_27 ( V_57 , V_58 , V_54 ,
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
V_56 -> V_67 = F_28 ( V_57 [ V_66 ] ) ;
if ( V_57 [ V_68 ] ) {
V_56 -> V_69 . V_54 = F_18 ( V_57 [ V_68 ] ) ;
V_56 -> V_69 . V_70 = F_19 ( V_57 [ V_68 ] ) ;
}
if ( V_57 [ V_71 ] ) {
V_56 -> V_69 . V_34 = F_18 ( V_57 [ V_71 ] ) ;
V_56 -> V_69 . V_72 = F_19 ( V_57 [ V_71 ] ) ;
}
if ( V_57 [ V_73 ] )
V_56 -> V_69 . V_74 = F_2 ( V_57 [ V_73 ] ) ;
if ( V_57 [ V_75 ] ) {
V_56 -> type = F_2 ( V_57 [ V_75 ] ) ;
if ( V_56 -> type < 0 || V_56 -> type >= V_76 )
return - V_11 ;
}
if ( V_57 [ V_77 ] ) {
struct V_3 * V_78 [ V_79 ] ;
V_26 = F_27 ( V_78 , V_79 - 1 ,
V_57 [ V_77 ] ,
V_80 ) ;
if ( V_26 )
return V_26 ;
V_56 -> V_64 = V_78 [ V_81 ] ;
V_56 -> V_65 = V_78 [ V_82 ] ;
}
return 0 ;
}
static int F_29 ( struct V_83 * V_84 , struct V_55 * V_56 )
{
if ( V_84 -> V_4 [ V_85 ] ) {
V_56 -> V_69 . V_54 = F_18 ( V_84 -> V_4 [ V_85 ] ) ;
V_56 -> V_69 . V_70 = F_19 ( V_84 -> V_4 [ V_85 ] ) ;
}
if ( V_84 -> V_4 [ V_86 ] ) {
V_56 -> V_69 . V_34 = F_18 ( V_84 -> V_4 [ V_86 ] ) ;
V_56 -> V_69 . V_72 = F_19 ( V_84 -> V_4 [ V_86 ] ) ;
}
if ( V_84 -> V_4 [ V_87 ] )
V_56 -> V_67 = F_28 ( V_84 -> V_4 [ V_87 ] ) ;
if ( V_84 -> V_4 [ V_88 ] )
V_56 -> V_69 . V_74 = F_2 ( V_84 -> V_4 [ V_88 ] ) ;
V_56 -> V_60 = ! ! V_84 -> V_4 [ V_89 ] ;
V_56 -> V_62 = ! ! V_84 -> V_4 [ V_90 ] ;
if ( V_56 -> V_60 ) {
V_56 -> V_64 = true ;
V_56 -> V_65 = true ;
}
if ( V_56 -> V_62 )
V_56 -> V_65 = true ;
if ( V_84 -> V_4 [ V_91 ] ) {
V_56 -> type = F_2 ( V_84 -> V_4 [ V_91 ] ) ;
if ( V_56 -> type < 0 || V_56 -> type >= V_76 )
return - V_11 ;
}
if ( V_84 -> V_4 [ V_92 ] ) {
struct V_3 * V_78 [ V_79 ] ;
int V_26 = F_27 (
V_78 , V_79 - 1 ,
V_84 -> V_4 [ V_92 ] ,
V_80 ) ;
if ( V_26 )
return V_26 ;
V_56 -> V_64 = V_78 [ V_81 ] ;
V_56 -> V_65 = V_78 [ V_82 ] ;
}
return 0 ;
}
static int F_30 ( struct V_83 * V_84 , struct V_55 * V_56 )
{
int V_26 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> V_67 = - 1 ;
V_56 -> type = - 1 ;
if ( V_84 -> V_4 [ V_93 ] )
V_26 = F_26 ( V_84 -> V_4 [ V_93 ] , V_56 ) ;
else
V_26 = F_29 ( V_84 , V_56 ) ;
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
static struct V_94 *
F_31 ( struct V_5 * V_6 ,
struct V_3 * V_95 )
{
struct V_55 V_96 ;
struct V_3 * V_54 ;
struct V_94 * V_97 ;
int V_98 , V_26 , V_60 = 0 ;
V_97 = F_32 ( sizeof( * V_97 ) , V_99 ) ;
if ( ! V_97 )
return F_33 ( - V_100 ) ;
V_97 -> V_60 = - 1 ;
V_97 -> V_62 = - 1 ;
F_34 (key, keys, rem) {
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_67 = - 1 ;
V_26 = F_26 ( V_54 , & V_96 ) ;
if ( V_26 )
goto error;
V_26 = - V_11 ;
if ( ! V_96 . V_69 . V_54 )
goto error;
if ( V_96 . V_67 < 0 || V_96 . V_67 > 4 )
goto error;
if ( V_96 . V_60 ) {
if ( V_60 )
goto error;
V_60 = 1 ;
V_97 -> V_60 = V_96 . V_67 ;
if ( ! V_96 . V_64 || ! V_96 . V_65 )
goto error;
} else if ( V_96 . V_62 )
goto error;
V_26 = F_35 ( V_6 , & V_96 . V_69 ,
V_96 . V_67 , false , NULL ) ;
if ( V_26 )
goto error;
V_97 -> V_101 [ V_96 . V_67 ] . V_74 = V_96 . V_69 . V_74 ;
V_97 -> V_101 [ V_96 . V_67 ] . V_70 = V_96 . V_69 . V_70 ;
V_97 -> V_101 [ V_96 . V_67 ] . V_54 = V_97 -> V_102 [ V_96 . V_67 ] ;
memcpy ( V_97 -> V_102 [ V_96 . V_67 ] , V_96 . V_69 . V_54 , V_96 . V_69 . V_70 ) ;
}
return V_97 ;
error:
F_36 ( V_97 ) ;
return F_33 ( V_26 ) ;
}
static int F_37 ( struct V_103 * V_104 )
{
F_38 ( V_104 ) ;
switch ( V_104 -> V_105 ) {
case V_106 :
case V_107 :
case V_108 :
case V_109 :
break;
case V_110 :
if ( ! V_104 -> V_111 )
return - V_112 ;
break;
case V_113 :
case V_114 :
if ( V_104 -> V_115 != V_116 )
return - V_112 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_39 ( struct V_23 * V_37 , T_2 V_29 , T_3 V_117 )
{
struct V_3 * V_118 = F_40 ( V_37 , V_29 ) ;
int V_119 ;
if ( ! V_118 )
goto V_42;
V_119 = 0 ;
while ( V_117 ) {
if ( ( V_117 & 1 ) && F_24 ( V_37 , V_119 ) )
goto V_42;
V_117 >>= 1 ;
V_119 ++ ;
}
F_41 ( V_37 , V_118 ) ;
return 0 ;
V_42:
return - V_53 ;
}
static int F_42 ( struct V_120 * V_120 ,
struct V_23 * V_37 )
{
struct V_3 * V_121 ;
int V_119 , V_122 ;
V_121 = F_40 ( V_37 ,
V_123 ) ;
if ( ! V_121 )
goto V_42;
for ( V_119 = 0 ; V_119 < V_120 -> V_124 ; V_119 ++ ) {
const struct V_125 * V_126 ;
struct V_3 * V_127 , * V_128 ;
V_126 = & V_120 -> V_129 [ V_119 ] ;
V_127 = F_40 ( V_37 , V_119 + 1 ) ;
if ( ! V_127 )
goto V_42;
V_128 = F_40 ( V_37 , V_130 ) ;
if ( ! V_128 )
goto V_42;
for ( V_122 = 0 ; V_122 < V_126 -> V_131 ; V_122 ++ ) {
struct V_3 * V_132 ;
V_132 = F_40 ( V_37 , V_122 + 1 ) ;
if ( ! V_132 )
goto V_42;
if ( F_23 ( V_37 , V_133 ,
V_126 -> V_134 [ V_122 ] . V_135 ) )
goto V_42;
if ( F_39 ( V_37 , V_136 ,
V_126 -> V_134 [ V_122 ] . V_137 ) )
goto V_42;
F_41 ( V_37 , V_132 ) ;
}
F_41 ( V_37 , V_128 ) ;
if ( V_126 -> V_138 &&
F_24 ( V_37 , V_139 ) )
goto V_42;
if ( F_23 ( V_37 , V_140 ,
V_126 -> V_141 ) ||
F_23 ( V_37 , V_142 ,
V_126 -> V_143 ) )
goto V_42;
F_41 ( V_37 , V_127 ) ;
}
F_41 ( V_37 , V_121 ) ;
return 0 ;
V_42:
return - V_53 ;
}
static int F_43 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 , int V_35 ,
struct V_5 * V_8 )
{
void * V_144 ;
struct V_3 * V_145 , * V_146 ;
struct V_3 * V_147 , * V_148 ;
struct V_3 * V_149 , * V_150 ;
struct V_3 * V_151 ;
enum V_152 V_153 ;
struct V_38 * V_39 ;
struct V_154 * V_155 ;
int V_119 ;
const struct V_156 * V_157 =
V_8 -> V_120 . V_157 ;
V_144 = F_20 ( V_37 , V_33 , V_34 , V_35 , V_158 ) ;
if ( ! V_144 )
return - 1 ;
if ( F_23 ( V_37 , V_159 , V_8 -> V_160 ) ||
F_44 ( V_37 , V_161 , F_45 ( & V_8 -> V_120 ) ) ||
F_23 ( V_37 , V_162 ,
V_163 ) ||
F_46 ( V_37 , V_164 ,
V_8 -> V_120 . V_165 ) ||
F_46 ( V_37 , V_166 ,
V_8 -> V_120 . V_167 ) ||
F_23 ( V_37 , V_168 ,
V_8 -> V_120 . V_169 ) ||
F_23 ( V_37 , V_170 ,
V_8 -> V_120 . V_171 ) ||
F_46 ( V_37 , V_172 ,
V_8 -> V_120 . V_173 ) ||
F_46 ( V_37 , V_174 ,
V_8 -> V_120 . V_175 ) ||
F_46 ( V_37 , V_176 ,
V_8 -> V_120 . V_177 ) ||
F_47 ( V_37 , V_178 ,
V_8 -> V_120 . V_179 ) ||
F_47 ( V_37 , V_180 ,
V_8 -> V_120 . V_181 ) ||
F_46 ( V_37 , V_182 ,
V_8 -> V_120 . V_183 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_184 ) &&
F_24 ( V_37 , V_185 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_186 ) &&
F_24 ( V_37 , V_187 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_188 ) &&
F_24 ( V_37 , V_189 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_190 ) &&
F_24 ( V_37 , V_191 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_192 ) &&
F_24 ( V_37 , V_193 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_194 ) &&
F_24 ( V_37 , V_195 ) )
goto V_42;
if ( F_48 ( V_37 , V_196 ,
sizeof( T_2 ) * V_8 -> V_120 . V_197 ,
V_8 -> V_120 . V_198 ) )
goto V_42;
if ( F_46 ( V_37 , V_199 ,
V_8 -> V_120 . V_200 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_201 ) &&
F_24 ( V_37 , V_202 ) )
goto V_42;
if ( F_23 ( V_37 , V_203 ,
V_8 -> V_120 . V_204 ) ||
F_23 ( V_37 , V_205 ,
V_8 -> V_120 . V_206 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_207 ) &&
F_23 ( V_37 , V_208 ,
V_8 -> V_120 . V_209 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_204 ||
V_8 -> V_120 . V_206 ) && V_8 -> V_210 -> V_211 ) {
T_2 V_212 = 0 , V_213 = 0 ;
int V_15 ;
V_15 = V_8 -> V_210 -> V_211 ( & V_8 -> V_120 , & V_212 , & V_213 ) ;
if ( ! V_15 ) {
if ( F_23 ( V_37 , V_214 ,
V_212 ) ||
F_23 ( V_37 , V_215 ,
V_213 ) )
goto V_42;
}
}
if ( F_39 ( V_37 , V_216 ,
V_8 -> V_120 . V_217 ) )
goto V_42;
V_145 = F_40 ( V_37 , V_218 ) ;
if ( ! V_145 )
goto V_42;
for ( V_153 = 0 ; V_153 < V_219 ; V_153 ++ ) {
if ( ! V_8 -> V_120 . V_220 [ V_153 ] )
continue;
V_146 = F_40 ( V_37 , V_153 ) ;
if ( ! V_146 )
goto V_42;
if ( V_8 -> V_120 . V_220 [ V_153 ] -> V_221 . V_222 &&
( F_48 ( V_37 , V_223 ,
sizeof( V_8 -> V_120 . V_220 [ V_153 ] -> V_221 . V_224 ) ,
& V_8 -> V_120 . V_220 [ V_153 ] -> V_221 . V_224 ) ||
F_47 ( V_37 , V_225 ,
V_8 -> V_120 . V_220 [ V_153 ] -> V_221 . V_226 ) ||
F_46 ( V_37 , V_227 ,
V_8 -> V_120 . V_220 [ V_153 ] -> V_221 . V_228 ) ||
F_46 ( V_37 , V_229 ,
V_8 -> V_120 . V_220 [ V_153 ] -> V_221 . V_230 ) ) )
goto V_42;
V_147 = F_40 ( V_37 , V_231 ) ;
if ( ! V_147 )
goto V_42;
for ( V_119 = 0 ; V_119 < V_8 -> V_120 . V_220 [ V_153 ] -> V_232 ; V_119 ++ ) {
V_148 = F_40 ( V_37 , V_119 ) ;
if ( ! V_148 )
goto V_42;
V_39 = & V_8 -> V_120 . V_220 [ V_153 ] -> V_233 [ V_119 ] ;
if ( F_22 ( V_37 , V_39 ) )
goto V_42;
F_41 ( V_37 , V_148 ) ;
}
F_41 ( V_37 , V_147 ) ;
V_149 = F_40 ( V_37 , V_234 ) ;
if ( ! V_149 )
goto V_42;
for ( V_119 = 0 ; V_119 < V_8 -> V_120 . V_220 [ V_153 ] -> V_235 ; V_119 ++ ) {
V_150 = F_40 ( V_37 , V_119 ) ;
if ( ! V_150 )
goto V_42;
V_155 = & V_8 -> V_120 . V_220 [ V_153 ] -> V_236 [ V_119 ] ;
if ( F_23 ( V_37 , V_237 ,
V_155 -> V_238 ) )
goto V_42;
if ( ( V_155 -> V_35 & V_239 ) &&
F_24 ( V_37 ,
V_240 ) )
goto V_42;
F_41 ( V_37 , V_150 ) ;
}
F_41 ( V_37 , V_149 ) ;
F_41 ( V_37 , V_146 ) ;
}
F_41 ( V_37 , V_145 ) ;
V_151 = F_40 ( V_37 , V_241 ) ;
if ( ! V_151 )
goto V_42;
V_119 = 0 ;
#define F_49 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_49 ( V_242 , V_243 ) ;
F_49 ( V_244 , V_245 ) ;
F_49 ( V_246 , V_247 ) ;
F_49 ( V_248 , V_249 ) ;
F_49 ( V_250 , V_251 ) ;
F_49 ( V_252 , V_253 ) ;
F_49 ( V_254 , V_255 ) ;
F_49 ( V_256 , V_257 ) ;
F_49 ( V_258 , V_259 ) ;
F_49 ( V_260 , V_261 ) ;
F_49 ( V_262 , V_263 ) ;
F_49 ( V_264 , V_265 ) ;
F_49 ( V_266 , V_267 ) ;
F_49 ( V_268 , V_269 ) ;
F_49 ( V_270 , V_271 ) ;
F_49 ( V_272 , V_273 ) ;
F_49 ( V_274 , V_275 ) ;
if ( V_8 -> V_120 . V_35 & V_276 )
F_49 ( V_277 , V_278 ) ;
F_49 ( V_279 , V_280 ) ;
F_49 ( V_281 , V_282 ) ;
F_49 ( V_283 , V_284 ) ;
if ( V_8 -> V_120 . V_35 & V_285 ) {
V_119 ++ ;
if ( F_23 ( V_37 , V_119 , V_286 ) )
goto V_42;
}
F_49 ( V_287 , V_288 ) ;
F_49 ( V_289 , V_290 ) ;
if ( V_8 -> V_120 . V_35 & V_192 ) {
F_49 ( V_291 , V_292 ) ;
F_49 ( V_293 , V_294 ) ;
}
if ( V_8 -> V_120 . V_35 & V_295 )
F_49 ( V_296 , V_297 ) ;
F_49 ( V_298 , V_299 ) ;
F_49 ( V_300 , V_301 ) ;
if ( V_8 -> V_120 . V_35 & V_302 ) {
V_119 ++ ;
if ( F_23 ( V_37 , V_119 , V_303 ) )
goto V_42;
}
#ifdef F_50
F_49 ( V_304 , V_305 ) ;
#endif
#undef F_49
if ( V_8 -> V_210 -> V_306 || V_8 -> V_210 -> V_258 ) {
V_119 ++ ;
if ( F_23 ( V_37 , V_119 , V_307 ) )
goto V_42;
}
if ( V_8 -> V_210 -> V_308 || V_8 -> V_210 -> V_262 ) {
V_119 ++ ;
if ( F_23 ( V_37 , V_119 , V_309 ) )
goto V_42;
}
F_41 ( V_37 , V_151 ) ;
if ( V_8 -> V_210 -> V_277 &&
( V_8 -> V_120 . V_35 & V_276 ) &&
F_23 ( V_37 , V_310 ,
V_8 -> V_120 . V_311 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_312 ) &&
F_24 ( V_37 , V_313 ) )
goto V_42;
if ( V_157 ) {
T_3 V_314 ;
struct V_3 * V_315 , * V_316 ;
enum V_317 V_318 ;
V_316 = F_40 ( V_37 , V_319 ) ;
if ( ! V_316 )
goto V_42;
for ( V_318 = 0 ; V_318 < V_320 ; V_318 ++ ) {
V_315 = F_40 ( V_37 , V_318 ) ;
if ( ! V_315 )
goto V_42;
V_119 = 0 ;
V_314 = V_157 [ V_318 ] . V_321 ;
while ( V_314 ) {
if ( ( V_314 & 1 ) &&
F_47 ( V_37 , V_322 ,
( V_119 << 4 ) | V_323 ) )
goto V_42;
V_314 >>= 1 ;
V_119 ++ ;
}
F_41 ( V_37 , V_315 ) ;
}
F_41 ( V_37 , V_316 ) ;
V_316 = F_40 ( V_37 , V_324 ) ;
if ( ! V_316 )
goto V_42;
for ( V_318 = 0 ; V_318 < V_320 ; V_318 ++ ) {
V_315 = F_40 ( V_37 , V_318 ) ;
if ( ! V_315 )
goto V_42;
V_119 = 0 ;
V_314 = V_157 [ V_318 ] . V_325 ;
while ( V_314 ) {
if ( ( V_314 & 1 ) &&
F_47 ( V_37 , V_322 ,
( V_119 << 4 ) | V_323 ) )
goto V_42;
V_314 >>= 1 ;
V_119 ++ ;
}
F_41 ( V_37 , V_315 ) ;
}
F_41 ( V_37 , V_316 ) ;
}
if ( V_8 -> V_120 . V_326 . V_35 || V_8 -> V_120 . V_326 . V_327 ) {
struct V_3 * V_328 ;
V_328 = F_40 ( V_37 ,
V_329 ) ;
if ( ! V_328 )
goto V_42;
if ( ( ( V_8 -> V_120 . V_326 . V_35 & V_330 ) &&
F_24 ( V_37 , V_331 ) ) ||
( ( V_8 -> V_120 . V_326 . V_35 & V_332 ) &&
F_24 ( V_37 , V_333 ) ) ||
( ( V_8 -> V_120 . V_326 . V_35 & V_334 ) &&
F_24 ( V_37 , V_335 ) ) ||
( ( V_8 -> V_120 . V_326 . V_35 & V_336 ) &&
F_24 ( V_37 , V_337 ) ) ||
( ( V_8 -> V_120 . V_326 . V_35 & V_338 ) &&
F_24 ( V_37 , V_339 ) ) ||
( ( V_8 -> V_120 . V_326 . V_35 & V_340 ) &&
F_24 ( V_37 , V_341 ) ) ||
( ( V_8 -> V_120 . V_326 . V_35 & V_342 ) &&
F_24 ( V_37 , V_343 ) ) ||
( ( V_8 -> V_120 . V_326 . V_35 & V_344 ) &&
F_24 ( V_37 , V_345 ) ) )
goto V_42;
if ( V_8 -> V_120 . V_326 . V_327 ) {
struct V_346 V_347 = {
. V_348 = V_8 -> V_120 . V_326 . V_327 ,
. V_349 =
V_8 -> V_120 . V_326 . V_350 ,
. V_351 =
V_8 -> V_120 . V_326 . V_352 ,
} ;
if ( F_48 ( V_37 , V_353 ,
sizeof( V_347 ) , & V_347 ) )
goto V_42;
}
F_41 ( V_37 , V_328 ) ;
}
if ( F_39 ( V_37 , V_354 ,
V_8 -> V_120 . V_355 ) )
goto V_42;
if ( F_42 ( & V_8 -> V_120 , V_37 ) )
goto V_42;
if ( ( V_8 -> V_120 . V_35 & V_356 ) &&
F_23 ( V_37 , V_357 ,
V_8 -> V_120 . V_358 ) )
goto V_42;
if ( F_23 ( V_37 , V_359 ,
V_8 -> V_120 . V_360 ) )
goto V_42;
if ( V_8 -> V_120 . V_361 &&
F_48 ( V_37 , V_362 ,
sizeof( * V_8 -> V_120 . V_361 ) ,
V_8 -> V_120 . V_361 ) )
goto V_42;
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
static int F_53 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_67 = 0 ;
int V_364 = V_14 -> args [ 0 ] ;
struct V_5 * V_8 ;
F_54 ( & V_365 ) ;
F_55 (dev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_8 -> V_120 ) , F_13 ( V_24 -> V_27 ) ) )
continue;
if ( ++ V_67 <= V_364 )
continue;
if ( F_43 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_366 , V_367 ,
V_8 ) < 0 ) {
V_67 -- ;
break;
}
}
F_59 ( & V_365 ) ;
V_14 -> args [ 0 ] = V_67 ;
return V_24 -> V_31 ;
}
static int F_60 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_23 * V_37 ;
struct V_5 * V_8 = V_84 -> V_368 [ 0 ] ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
if ( F_43 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 , V_8 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_84 ) ;
}
static int F_64 ( struct V_3 * V_57 [] ,
struct V_372 * V_373 )
{
if ( ! V_57 [ V_374 ] || ! V_57 [ V_375 ] ||
! V_57 [ V_376 ] || ! V_57 [ V_377 ] ||
! V_57 [ V_378 ] )
return - V_11 ;
V_373 -> V_379 = F_28 ( V_57 [ V_374 ] ) ;
V_373 -> V_380 = F_65 ( V_57 [ V_375 ] ) ;
V_373 -> V_381 = F_65 ( V_57 [ V_376 ] ) ;
V_373 -> V_382 = F_65 ( V_57 [ V_377 ] ) ;
V_373 -> V_383 = F_28 ( V_57 [ V_378 ] ) ;
if ( V_373 -> V_379 >= V_384 )
return - V_11 ;
return 0 ;
}
static bool F_66 ( struct V_103 * V_104 )
{
return ! V_104 ||
V_104 -> V_105 == V_106 ||
V_104 -> V_105 == V_385 ||
V_104 -> V_105 == V_109 ||
V_104 -> V_105 == V_386 ||
V_104 -> V_105 == V_108 ;
}
static bool F_67 ( struct V_83 * V_84 ,
enum V_387 * V_388 )
{
enum V_387 V_389 ;
if ( ! V_84 -> V_4 [ V_390 ] )
return false ;
V_389 = F_2 ( V_84 -> V_4 [ V_390 ] ) ;
if ( V_389 != V_391 &&
V_389 != V_392 &&
V_389 != V_393 &&
V_389 != V_394 )
return false ;
if ( V_388 )
* V_388 = V_389 ;
return true ;
}
static int F_68 ( struct V_5 * V_6 ,
struct V_103 * V_104 ,
struct V_83 * V_84 )
{
enum V_387 V_388 = V_391 ;
T_2 V_395 ;
int V_97 ;
if ( ! V_84 -> V_4 [ V_396 ] )
return - V_11 ;
if ( ! F_66 ( V_104 ) )
return - V_397 ;
if ( V_84 -> V_4 [ V_390 ] &&
! F_67 ( V_84 , & V_388 ) )
return - V_11 ;
V_395 = F_2 ( V_84 -> V_4 [ V_396 ] ) ;
F_54 ( & V_6 -> V_398 ) ;
if ( V_104 ) {
F_69 ( V_104 ) ;
V_97 = F_70 ( V_6 , V_104 , V_395 , V_388 ) ;
F_71 ( V_104 ) ;
} else {
V_97 = F_70 ( V_6 , NULL , V_395 , V_388 ) ;
}
F_59 ( & V_6 -> V_398 ) ;
return V_97 ;
}
static int F_72 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_399 = V_84 -> V_368 [ 1 ] ;
return F_68 ( V_6 , V_399 -> V_400 , V_84 ) ;
}
static int F_73 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
const T_1 * V_401 ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( F_74 ( V_8 ) )
return - V_403 ;
if ( ! V_6 -> V_210 -> V_289 )
return - V_397 ;
if ( V_104 -> V_105 != V_385 )
return - V_397 ;
V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
return V_6 -> V_210 -> V_289 ( V_104 -> V_120 , V_8 , V_401 ) ;
}
static int F_75 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 ;
struct V_7 * V_399 = NULL ;
struct V_103 * V_104 ;
int V_97 = 0 , V_404 = 0 ;
struct V_3 * V_405 ;
T_2 V_406 ;
T_1 V_165 = 0 , V_167 = 0 ;
T_2 V_169 = 0 , V_171 = 0 ;
T_1 V_173 = 0 ;
F_54 ( & V_365 ) ;
if ( V_84 -> V_4 [ V_10 ] ) {
int V_9 = F_2 ( V_84 -> V_4 [ V_10 ] ) ;
V_399 = F_3 ( F_76 ( V_84 ) , V_9 ) ;
if ( V_399 && V_399 -> V_400 ) {
V_6 = F_77 ( V_399 -> V_400 -> V_120 ) ;
F_54 ( & V_6 -> V_407 ) ;
} else
V_399 = NULL ;
}
if ( ! V_399 ) {
V_6 = F_78 ( V_84 ) ;
if ( F_5 ( V_6 ) ) {
F_59 ( & V_365 ) ;
return F_7 ( V_6 ) ;
}
V_104 = NULL ;
V_399 = NULL ;
V_97 = 0 ;
F_54 ( & V_6 -> V_407 ) ;
} else if ( F_74 ( V_399 ) &&
F_66 ( V_399 -> V_400 ) )
V_104 = V_399 -> V_400 ;
else
V_104 = NULL ;
if ( V_84 -> V_4 [ V_161 ] )
V_97 = F_79 (
V_6 , F_18 ( V_84 -> V_4 [ V_161 ] ) ) ;
F_59 ( & V_365 ) ;
if ( V_97 )
goto V_408;
if ( V_84 -> V_4 [ V_409 ] ) {
struct V_372 V_373 ;
struct V_3 * V_57 [ V_410 + 1 ] ;
if ( ! V_6 -> V_210 -> V_411 ) {
V_97 = - V_397 ;
goto V_408;
}
if ( ! V_399 ) {
V_97 = - V_11 ;
goto V_408;
}
if ( V_399 -> V_400 -> V_105 != V_106 &&
V_399 -> V_400 -> V_105 != V_108 ) {
V_97 = - V_11 ;
goto V_408;
}
if ( ! F_74 ( V_399 ) ) {
V_97 = - V_412 ;
goto V_408;
}
F_34 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_80 ( V_57 , V_410 ,
F_18 ( V_405 ) ,
F_19 ( V_405 ) ,
V_413 ) ;
V_97 = F_64 ( V_57 , & V_373 ) ;
if ( V_97 )
goto V_408;
V_97 = V_6 -> V_210 -> V_411 ( & V_6 -> V_120 ,
V_399 ,
& V_373 ) ;
if ( V_97 )
goto V_408;
}
}
if ( V_84 -> V_4 [ V_396 ] ) {
V_97 = F_68 ( V_6 , V_104 , V_84 ) ;
if ( V_97 )
goto V_408;
}
if ( V_84 -> V_4 [ V_414 ] ) {
enum V_415 type ;
int V_67 , V_416 = 0 ;
if ( ! V_6 -> V_210 -> V_417 ) {
V_97 = - V_397 ;
goto V_408;
}
V_67 = V_414 ;
type = F_2 ( V_84 -> V_4 [ V_67 ] ) ;
if ( ! V_84 -> V_4 [ V_418 ] &&
( type != V_419 ) ) {
V_97 = - V_11 ;
goto V_408;
}
if ( type != V_419 ) {
V_67 = V_418 ;
V_416 = F_2 ( V_84 -> V_4 [ V_67 ] ) ;
}
V_97 = V_6 -> V_210 -> V_417 ( & V_6 -> V_120 , type , V_416 ) ;
if ( V_97 )
goto V_408;
}
if ( V_84 -> V_4 [ V_214 ] &&
V_84 -> V_4 [ V_215 ] ) {
T_2 V_212 , V_213 ;
if ( ( ! V_6 -> V_120 . V_204 &&
! V_6 -> V_120 . V_206 ) ||
! V_6 -> V_210 -> V_420 ) {
V_97 = - V_397 ;
goto V_408;
}
V_212 = F_2 ( V_84 -> V_4 [ V_214 ] ) ;
V_213 = F_2 ( V_84 -> V_4 [ V_215 ] ) ;
if ( ( ~ V_212 && ( V_212 & ~ V_6 -> V_120 . V_204 ) ) ||
( ~ V_213 && ( V_213 & ~ V_6 -> V_120 . V_206 ) ) ) {
V_97 = - V_11 ;
goto V_408;
}
V_212 = V_212 & V_6 -> V_120 . V_204 ;
V_213 = V_213 & V_6 -> V_120 . V_206 ;
V_97 = V_6 -> V_210 -> V_420 ( & V_6 -> V_120 , V_212 , V_213 ) ;
if ( V_97 )
goto V_408;
}
V_406 = 0 ;
if ( V_84 -> V_4 [ V_164 ] ) {
V_165 = F_28 (
V_84 -> V_4 [ V_164 ] ) ;
if ( V_165 == 0 ) {
V_97 = - V_11 ;
goto V_408;
}
V_406 |= V_421 ;
}
if ( V_84 -> V_4 [ V_166 ] ) {
V_167 = F_28 (
V_84 -> V_4 [ V_166 ] ) ;
if ( V_167 == 0 ) {
V_97 = - V_11 ;
goto V_408;
}
V_406 |= V_422 ;
}
if ( V_84 -> V_4 [ V_168 ] ) {
V_169 = F_2 (
V_84 -> V_4 [ V_168 ] ) ;
if ( V_169 < 256 ) {
V_97 = - V_11 ;
goto V_408;
}
if ( V_169 != ( T_2 ) - 1 ) {
V_169 &= ~ 0x1 ;
}
V_406 |= V_423 ;
}
if ( V_84 -> V_4 [ V_170 ] ) {
V_171 = F_2 (
V_84 -> V_4 [ V_170 ] ) ;
V_406 |= V_424 ;
}
if ( V_84 -> V_4 [ V_172 ] ) {
V_173 = F_28 (
V_84 -> V_4 [ V_172 ] ) ;
V_406 |= V_425 ;
}
if ( V_406 ) {
T_1 V_426 , V_427 ;
T_2 V_428 , V_429 ;
T_1 V_430 ;
if ( ! V_6 -> V_210 -> V_431 ) {
V_97 = - V_397 ;
goto V_408;
}
V_426 = V_6 -> V_120 . V_165 ;
V_427 = V_6 -> V_120 . V_167 ;
V_428 = V_6 -> V_120 . V_169 ;
V_429 = V_6 -> V_120 . V_171 ;
V_430 = V_6 -> V_120 . V_173 ;
if ( V_406 & V_421 )
V_6 -> V_120 . V_165 = V_165 ;
if ( V_406 & V_422 )
V_6 -> V_120 . V_167 = V_167 ;
if ( V_406 & V_423 )
V_6 -> V_120 . V_169 = V_169 ;
if ( V_406 & V_424 )
V_6 -> V_120 . V_171 = V_171 ;
if ( V_406 & V_425 )
V_6 -> V_120 . V_173 = V_173 ;
V_97 = V_6 -> V_210 -> V_431 ( & V_6 -> V_120 , V_406 ) ;
if ( V_97 ) {
V_6 -> V_120 . V_165 = V_426 ;
V_6 -> V_120 . V_167 = V_427 ;
V_6 -> V_120 . V_169 = V_428 ;
V_6 -> V_120 . V_171 = V_429 ;
V_6 -> V_120 . V_173 = V_430 ;
}
}
V_408:
F_59 ( & V_6 -> V_407 ) ;
if ( V_399 )
F_6 ( V_399 ) ;
return V_97 ;
}
static int F_81 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 , int V_35 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
void * V_144 ;
V_144 = F_20 ( V_37 , V_33 , V_34 , V_35 , V_432 ) ;
if ( ! V_144 )
return - 1 ;
if ( F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_44 ( V_37 , V_433 , V_8 -> V_434 ) ||
F_23 ( V_37 , V_435 ,
V_8 -> V_400 -> V_105 ) ||
F_23 ( V_37 , V_162 ,
V_6 -> V_436 ^
( V_163 << 2 ) ) )
goto V_42;
if ( V_6 -> V_210 -> V_437 ) {
struct V_38 * V_39 ;
enum V_387 V_388 ;
V_39 = V_6 -> V_210 -> V_437 ( & V_6 -> V_120 , & V_388 ) ;
if ( V_39 &&
( F_23 ( V_37 , V_396 ,
V_39 -> V_41 ) ||
F_23 ( V_37 , V_390 ,
V_388 ) ) )
goto V_42;
}
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
static int F_82 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
int V_438 = 0 ;
int V_439 = 0 ;
int V_440 = V_14 -> args [ 0 ] ;
int V_441 = V_14 -> args [ 1 ] ;
struct V_5 * V_6 ;
struct V_103 * V_104 ;
F_54 ( & V_365 ) ;
F_55 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_56 ( F_57 ( & V_6 -> V_120 ) , F_13 ( V_24 -> V_27 ) ) )
continue;
if ( V_438 < V_440 ) {
V_438 ++ ;
continue;
}
V_439 = 0 ;
F_54 ( & V_6 -> V_398 ) ;
F_55 (wdev, &rdev->netdev_list, list) {
if ( V_439 < V_441 ) {
V_439 ++ ;
continue;
}
if ( F_81 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_366 , V_367 ,
V_6 , V_104 -> V_399 ) < 0 ) {
F_59 ( & V_6 -> V_398 ) ;
goto V_442;
}
V_439 ++ ;
}
F_59 ( & V_6 -> V_398 ) ;
V_438 ++ ;
}
V_442:
F_59 ( & V_365 ) ;
V_14 -> args [ 0 ] = V_438 ;
V_14 -> args [ 1 ] = V_439 ;
return V_24 -> V_31 ;
}
static int F_83 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_23 * V_37 ;
struct V_5 * V_8 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_399 = V_84 -> V_368 [ 1 ] ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
if ( F_81 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_8 , V_399 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_84 ) ;
}
static int F_84 ( struct V_3 * V_443 , T_2 * V_444 )
{
struct V_3 * V_35 [ V_445 + 1 ] ;
int V_446 ;
* V_444 = 0 ;
if ( ! V_443 )
return - V_11 ;
if ( F_27 ( V_35 , V_445 ,
V_443 , V_447 ) )
return - V_11 ;
for ( V_446 = 1 ; V_446 <= V_445 ; V_446 ++ )
if ( V_35 [ V_446 ] )
* V_444 |= ( 1 << V_446 ) ;
return 0 ;
}
static int F_85 ( struct V_5 * V_6 ,
struct V_7 * V_399 , T_1 V_448 ,
enum V_317 V_105 )
{
if ( ! V_448 ) {
if ( V_399 && ( V_399 -> V_449 & V_450 ) )
return - V_403 ;
return 0 ;
}
switch ( V_105 ) {
case V_107 :
if ( V_6 -> V_120 . V_35 & V_451 )
return 0 ;
break;
case V_113 :
if ( V_6 -> V_120 . V_35 & V_452 )
return 0 ;
break;
default:
break;
}
return - V_397 ;
}
static int F_86 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_453 V_101 ;
int V_26 ;
enum V_317 V_454 , V_455 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_2 V_456 , * V_35 = NULL ;
bool V_457 = false ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_454 = V_455 = V_8 -> V_400 -> V_105 ;
if ( V_84 -> V_4 [ V_435 ] ) {
V_455 = F_2 ( V_84 -> V_4 [ V_435 ] ) ;
if ( V_454 != V_455 )
V_457 = true ;
if ( V_455 > V_458 )
return - V_11 ;
}
if ( V_84 -> V_4 [ V_459 ] ) {
struct V_103 * V_104 = V_8 -> V_400 ;
if ( V_455 != V_109 )
return - V_11 ;
if ( F_74 ( V_8 ) )
return - V_403 ;
F_69 ( V_104 ) ;
F_87 ( V_460 !=
V_461 ) ;
V_104 -> V_462 =
F_19 ( V_84 -> V_4 [ V_459 ] ) ;
memcpy ( V_104 -> V_463 , F_18 ( V_84 -> V_4 [ V_459 ] ) ,
V_104 -> V_462 ) ;
F_71 ( V_104 ) ;
}
if ( V_84 -> V_4 [ V_464 ] ) {
V_101 . V_448 = ! ! F_28 ( V_84 -> V_4 [ V_464 ] ) ;
V_457 = true ;
V_26 = F_85 ( V_6 , V_8 , V_101 . V_448 , V_455 ) ;
if ( V_26 )
return V_26 ;
} else {
V_101 . V_448 = - 1 ;
}
if ( V_84 -> V_4 [ V_465 ] ) {
if ( V_455 != V_386 )
return - V_11 ;
V_26 = F_84 ( V_84 -> V_4 [ V_465 ] ,
& V_456 ) ;
if ( V_26 )
return V_26 ;
V_35 = & V_456 ;
V_457 = true ;
}
if ( V_457 )
V_26 = F_88 ( V_6 , V_8 , V_455 , V_35 , & V_101 ) ;
else
V_26 = 0 ;
if ( ! V_26 && V_101 . V_448 != - 1 )
V_8 -> V_400 -> V_448 = V_101 . V_448 ;
return V_26 ;
}
static int F_89 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_453 V_101 ;
struct V_7 * V_8 ;
int V_26 ;
enum V_317 type = V_466 ;
T_2 V_35 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
if ( ! V_84 -> V_4 [ V_433 ] )
return - V_11 ;
if ( V_84 -> V_4 [ V_435 ] ) {
type = F_2 ( V_84 -> V_4 [ V_435 ] ) ;
if ( type > V_458 )
return - V_11 ;
}
if ( ! V_6 -> V_210 -> V_242 ||
! ( V_6 -> V_120 . V_217 & ( 1 << type ) ) )
return - V_397 ;
if ( V_84 -> V_4 [ V_464 ] ) {
V_101 . V_448 = ! ! F_28 ( V_84 -> V_4 [ V_464 ] ) ;
V_26 = F_85 ( V_6 , NULL , V_101 . V_448 , type ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_84 ( type == V_386 ?
V_84 -> V_4 [ V_465 ] : NULL ,
& V_35 ) ;
V_8 = V_6 -> V_210 -> V_242 ( & V_6 -> V_120 ,
F_18 ( V_84 -> V_4 [ V_433 ] ) ,
type , V_26 ? NULL : & V_35 , & V_101 ) ;
if ( F_5 ( V_8 ) )
return F_7 ( V_8 ) ;
if ( type == V_109 &&
V_84 -> V_4 [ V_459 ] ) {
struct V_103 * V_104 = V_8 -> V_400 ;
F_69 ( V_104 ) ;
F_87 ( V_460 !=
V_461 ) ;
V_104 -> V_462 =
F_19 ( V_84 -> V_4 [ V_459 ] ) ;
memcpy ( V_104 -> V_463 , F_18 ( V_84 -> V_4 [ V_459 ] ) ,
V_104 -> V_462 ) ;
F_71 ( V_104 ) ;
}
return 0 ;
}
static int F_90 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
if ( ! V_6 -> V_210 -> V_467 )
return - V_397 ;
return V_6 -> V_210 -> V_467 ( & V_6 -> V_120 , V_8 ) ;
}
static int F_91 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_3 V_468 ;
if ( ! V_84 -> V_4 [ V_469 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_300 )
return - V_397 ;
V_468 = F_65 ( V_84 -> V_4 [ V_469 ] ) ;
return V_6 -> V_210 -> V_300 ( & V_6 -> V_120 , V_8 , V_468 ) ;
}
static void F_92 ( void * V_126 , struct V_470 * V_101 )
{
struct V_3 * V_54 ;
struct V_471 * V_472 = V_126 ;
if ( ( V_101 -> V_54 &&
F_48 ( V_472 -> V_37 , V_85 ,
V_101 -> V_70 , V_101 -> V_54 ) ) ||
( V_101 -> V_34 &&
F_48 ( V_472 -> V_37 , V_86 ,
V_101 -> V_72 , V_101 -> V_34 ) ) ||
( V_101 -> V_74 &&
F_23 ( V_472 -> V_37 , V_88 ,
V_101 -> V_74 ) ) )
goto V_42;
V_54 = F_40 ( V_472 -> V_37 , V_93 ) ;
if ( ! V_54 )
goto V_42;
if ( ( V_101 -> V_54 &&
F_48 ( V_472 -> V_37 , V_68 ,
V_101 -> V_70 , V_101 -> V_54 ) ) ||
( V_101 -> V_34 &&
F_48 ( V_472 -> V_37 , V_71 ,
V_101 -> V_72 , V_101 -> V_34 ) ) ||
( V_101 -> V_74 &&
F_23 ( V_472 -> V_37 , V_73 ,
V_101 -> V_74 ) ) )
goto V_42;
if ( F_46 ( V_472 -> V_37 , V_87 , V_472 -> V_67 ) )
goto V_42;
F_41 ( V_472 -> V_37 , V_54 ) ;
return;
V_42:
V_472 -> error = 1 ;
}
static int F_93 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 V_473 = 0 ;
const T_1 * V_474 = NULL ;
bool V_475 ;
struct V_471 V_472 = {
. error = 0 ,
} ;
void * V_144 ;
struct V_23 * V_37 ;
if ( V_84 -> V_4 [ V_87 ] )
V_473 = F_28 ( V_84 -> V_4 [ V_87 ] ) ;
if ( V_473 > 5 )
return - V_11 ;
if ( V_84 -> V_4 [ V_402 ] )
V_474 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_475 = ! ! V_474 ;
if ( V_84 -> V_4 [ V_91 ] ) {
T_2 V_476 = F_2 ( V_84 -> V_4 [ V_91 ] ) ;
if ( V_476 >= V_76 )
return - V_11 ;
if ( V_476 != V_477 &&
V_476 != V_478 )
return - V_11 ;
V_475 = V_476 == V_478 ;
}
if ( ! V_6 -> V_210 -> V_479 )
return - V_397 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_480 ) ;
if ( F_5 ( V_144 ) )
return F_7 ( V_144 ) ;
V_472 . V_37 = V_37 ;
V_472 . V_67 = V_473 ;
if ( F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_46 ( V_37 , V_87 , V_473 ) )
goto V_42;
if ( V_474 &&
F_48 ( V_37 , V_402 , V_481 , V_474 ) )
goto V_42;
if ( V_475 && V_474 &&
! ( V_6 -> V_120 . V_35 & V_184 ) )
return - V_482 ;
V_26 = V_6 -> V_210 -> V_479 ( & V_6 -> V_120 , V_8 , V_473 , V_475 ,
V_474 , & V_472 , F_92 ) ;
if ( V_26 )
goto V_483;
if ( V_472 . error )
goto V_42;
F_51 ( V_37 , V_144 ) ;
return F_63 ( V_37 , V_84 ) ;
V_42:
V_26 = - V_53 ;
V_483:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_94 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_55 V_54 ;
int V_26 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
V_26 = F_30 ( V_84 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 < 0 )
return - V_11 ;
if ( ! V_54 . V_60 && ! V_54 . V_62 )
return - V_11 ;
F_69 ( V_8 -> V_400 ) ;
if ( V_54 . V_60 ) {
if ( ! V_6 -> V_210 -> V_484 ) {
V_26 = - V_397 ;
goto V_442;
}
V_26 = F_37 ( V_8 -> V_400 ) ;
if ( V_26 )
goto V_442;
V_26 = V_6 -> V_210 -> V_484 ( & V_6 -> V_120 , V_8 , V_54 . V_67 ,
V_54 . V_64 , V_54 . V_65 ) ;
if ( V_26 )
goto V_442;
#ifdef F_95
V_8 -> V_400 -> V_485 . V_486 = V_54 . V_67 ;
#endif
} else {
if ( V_54 . V_64 || ! V_54 . V_65 ) {
V_26 = - V_11 ;
goto V_442;
}
if ( ! V_6 -> V_210 -> V_487 ) {
V_26 = - V_397 ;
goto V_442;
}
V_26 = F_37 ( V_8 -> V_400 ) ;
if ( V_26 )
goto V_442;
V_26 = V_6 -> V_210 -> V_487 ( & V_6 -> V_120 ,
V_8 , V_54 . V_67 ) ;
if ( V_26 )
goto V_442;
#ifdef F_95
V_8 -> V_400 -> V_485 . V_488 = V_54 . V_67 ;
#endif
}
V_442:
F_71 ( V_8 -> V_400 ) ;
return V_26 ;
}
static int F_96 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_55 V_54 ;
const T_1 * V_474 = NULL ;
V_26 = F_30 ( V_84 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_54 . V_69 . V_54 )
return - V_11 ;
if ( V_84 -> V_4 [ V_402 ] )
V_474 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_474 )
V_54 . type = V_478 ;
else
V_54 . type = V_477 ;
}
if ( V_54 . type != V_478 &&
V_54 . type != V_477 )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_246 )
return - V_397 ;
if ( F_35 ( V_6 , & V_54 . V_69 , V_54 . V_67 ,
V_54 . type == V_478 ,
V_474 ) )
return - V_11 ;
F_69 ( V_8 -> V_400 ) ;
V_26 = F_37 ( V_8 -> V_400 ) ;
if ( ! V_26 )
V_26 = V_6 -> V_210 -> V_246 ( & V_6 -> V_120 , V_8 , V_54 . V_67 ,
V_54 . type == V_478 ,
V_474 , & V_54 . V_69 ) ;
F_71 ( V_8 -> V_400 ) ;
return V_26 ;
}
static int F_97 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 * V_474 = NULL ;
struct V_55 V_54 ;
V_26 = F_30 ( V_84 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_84 -> V_4 [ V_402 ] )
V_474 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( V_54 . type == - 1 ) {
if ( V_474 )
V_54 . type = V_478 ;
else
V_54 . type = V_477 ;
}
if ( V_54 . type != V_478 &&
V_54 . type != V_477 )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_489 )
return - V_397 ;
F_69 ( V_8 -> V_400 ) ;
V_26 = F_37 ( V_8 -> V_400 ) ;
if ( V_54 . type == V_478 && V_474 &&
! ( V_6 -> V_120 . V_35 & V_184 ) )
V_26 = - V_482 ;
if ( ! V_26 )
V_26 = V_6 -> V_210 -> V_489 ( & V_6 -> V_120 , V_8 , V_54 . V_67 ,
V_54 . type == V_478 ,
V_474 ) ;
#ifdef F_95
if ( ! V_26 ) {
if ( V_54 . V_67 == V_8 -> V_400 -> V_485 . V_486 )
V_8 -> V_400 -> V_485 . V_486 = - 1 ;
else if ( V_54 . V_67 == V_8 -> V_400 -> V_485 . V_488 )
V_8 -> V_400 -> V_485 . V_488 = - 1 ;
}
#endif
F_71 ( V_8 -> V_400 ) ;
return V_26 ;
}
static int F_98 ( struct V_83 * V_84 ,
struct V_490 * V_491 )
{
bool V_492 = false ;
if ( ! F_17 ( V_84 -> V_4 [ V_493 ] ) ||
! F_17 ( V_84 -> V_4 [ V_494 ] ) ||
! F_17 ( V_84 -> V_4 [ V_495 ] ) ||
! F_17 ( V_84 -> V_4 [ V_496 ] ) )
return - V_11 ;
memset ( V_491 , 0 , sizeof( * V_491 ) ) ;
if ( V_84 -> V_4 [ V_497 ] ) {
V_491 -> V_498 = F_18 ( V_84 -> V_4 [ V_497 ] ) ;
V_491 -> V_499 = F_19 ( V_84 -> V_4 [ V_497 ] ) ;
if ( ! V_491 -> V_499 )
return - V_11 ;
V_492 = true ;
}
if ( V_84 -> V_4 [ V_493 ] ) {
V_491 -> V_500 = F_18 ( V_84 -> V_4 [ V_493 ] ) ;
V_491 -> V_501 =
F_19 ( V_84 -> V_4 [ V_493 ] ) ;
V_492 = true ;
}
if ( ! V_492 )
return - V_11 ;
if ( V_84 -> V_4 [ V_494 ] ) {
V_491 -> V_502 = F_18 ( V_84 -> V_4 [ V_494 ] ) ;
V_491 -> V_503 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
}
if ( V_84 -> V_4 [ V_495 ] ) {
V_491 -> V_504 =
F_18 ( V_84 -> V_4 [ V_495 ] ) ;
V_491 -> V_505 =
F_19 ( V_84 -> V_4 [ V_495 ] ) ;
}
if ( V_84 -> V_4 [ V_496 ] ) {
V_491 -> V_506 =
F_18 ( V_84 -> V_4 [ V_496 ] ) ;
V_491 -> V_507 =
F_19 ( V_84 -> V_4 [ V_496 ] ) ;
}
if ( V_84 -> V_4 [ V_508 ] ) {
V_491 -> V_509 =
F_18 ( V_84 -> V_4 [ V_508 ] ) ;
V_491 -> V_510 =
F_19 ( V_84 -> V_4 [ V_508 ] ) ;
}
return 0 ;
}
static int F_99 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_511 V_101 ;
int V_26 ;
if ( V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_397 ;
if ( ! V_6 -> V_210 -> V_248 )
return - V_397 ;
if ( V_104 -> V_512 )
return - V_513 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
if ( ! V_84 -> V_4 [ V_514 ] ||
! V_84 -> V_4 [ V_515 ] ||
! V_84 -> V_4 [ V_497 ] )
return - V_11 ;
V_26 = F_98 ( V_84 , & V_101 . V_516 ) ;
if ( V_26 )
return V_26 ;
V_101 . V_512 =
F_2 ( V_84 -> V_4 [ V_514 ] ) ;
V_101 . V_517 =
F_2 ( V_84 -> V_4 [ V_515 ] ) ;
V_26 = F_100 ( V_6 , V_101 . V_512 ) ;
if ( V_26 )
return V_26 ;
if ( V_84 -> V_4 [ V_518 ] ) {
V_101 . V_463 = F_18 ( V_84 -> V_4 [ V_518 ] ) ;
V_101 . V_519 =
F_19 ( V_84 -> V_4 [ V_518 ] ) ;
if ( V_101 . V_519 == 0 ||
V_101 . V_519 > V_460 )
return - V_11 ;
}
if ( V_84 -> V_4 [ V_520 ] ) {
V_101 . V_521 = F_2 (
V_84 -> V_4 [ V_520 ] ) ;
if ( V_101 . V_521 != V_522 &&
V_101 . V_521 != V_523 &&
V_101 . V_521 != V_524 )
return - V_11 ;
}
V_101 . V_525 = ! ! V_84 -> V_4 [ V_526 ] ;
if ( V_84 -> V_4 [ V_527 ] ) {
V_101 . V_528 = F_2 (
V_84 -> V_4 [ V_527 ] ) ;
if ( ! F_101 ( V_101 . V_528 ) )
return - V_11 ;
} else
V_101 . V_528 = V_529 ;
V_26 = F_102 ( V_6 , V_84 , & V_101 . V_530 ,
V_531 ) ;
if ( V_26 )
return V_26 ;
if ( V_84 -> V_4 [ V_532 ] ) {
if ( ! ( V_6 -> V_120 . V_360 & V_533 ) )
return - V_397 ;
V_101 . V_534 = F_65 (
V_84 -> V_4 [ V_532 ] ) ;
}
V_26 = V_6 -> V_210 -> V_248 ( & V_6 -> V_120 , V_8 , & V_101 ) ;
if ( ! V_26 )
V_104 -> V_512 = V_101 . V_512 ;
return V_26 ;
}
static int F_103 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_490 V_101 ;
int V_26 ;
if ( V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_397 ;
if ( ! V_6 -> V_210 -> V_535 )
return - V_397 ;
if ( ! V_104 -> V_512 )
return - V_11 ;
V_26 = F_98 ( V_84 , & V_101 ) ;
if ( V_26 )
return V_26 ;
return V_6 -> V_210 -> V_535 ( & V_6 -> V_120 , V_8 , & V_101 ) ;
}
static int F_104 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
int V_26 ;
if ( ! V_6 -> V_210 -> V_536 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_397 ;
if ( ! V_104 -> V_512 )
return - V_482 ;
V_26 = V_6 -> V_210 -> V_536 ( & V_6 -> V_120 , V_8 ) ;
if ( ! V_26 )
V_104 -> V_512 = 0 ;
return V_26 ;
}
static int F_105 ( struct V_83 * V_84 ,
enum V_317 V_105 ,
struct V_537 * V_101 )
{
struct V_3 * V_35 [ V_538 + 1 ] ;
struct V_3 * V_443 ;
int V_446 ;
V_443 = V_84 -> V_4 [ V_539 ] ;
if ( V_443 ) {
struct V_540 * V_541 ;
V_541 = F_18 ( V_443 ) ;
V_101 -> V_542 = V_541 -> V_543 ;
V_101 -> V_544 = V_541 -> V_545 ;
if ( ( V_101 -> V_542 |
V_101 -> V_544 ) & F_106 ( V_546 ) )
return - V_11 ;
return 0 ;
}
V_443 = V_84 -> V_4 [ V_547 ] ;
if ( ! V_443 )
return 0 ;
if ( F_27 ( V_35 , V_538 ,
V_443 , V_548 ) )
return - V_11 ;
switch ( V_105 ) {
case V_106 :
case V_107 :
case V_108 :
V_101 -> V_542 = F_106 ( V_549 ) |
F_106 ( V_550 ) |
F_106 ( V_551 ) |
F_106 ( V_552 ) ;
break;
case V_114 :
case V_113 :
V_101 -> V_542 = F_106 ( V_549 ) |
F_106 ( V_553 ) ;
break;
case V_109 :
V_101 -> V_542 = F_106 ( V_554 ) |
F_106 ( V_552 ) |
F_106 ( V_549 ) ;
default:
return - V_11 ;
}
for ( V_446 = 1 ; V_446 <= V_538 ; V_446 ++ ) {
if ( V_35 [ V_446 ] ) {
V_101 -> V_544 |= ( 1 << V_446 ) ;
if ( V_446 > V_555 )
return - V_11 ;
}
}
return 0 ;
}
static bool F_107 ( struct V_23 * V_37 , struct V_556 * V_84 ,
int V_29 )
{
struct V_3 * V_155 ;
T_3 V_238 ;
V_155 = F_40 ( V_37 , V_29 ) ;
if ( ! V_155 )
goto V_42;
V_238 = F_108 ( V_84 ) ;
if ( ( V_238 > 0 &&
F_47 ( V_37 , V_557 , V_238 ) ) ||
( ( V_84 -> V_35 & V_558 ) &&
F_46 ( V_37 , V_559 , V_84 -> V_224 ) ) ||
( ( V_84 -> V_35 & V_560 ) &&
F_24 ( V_37 , V_561 ) ) ||
( ( V_84 -> V_35 & V_562 ) &&
F_24 ( V_37 , V_563 ) ) )
goto V_42;
F_41 ( V_37 , V_155 ) ;
return true ;
V_42:
return false ;
}
static int F_109 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
const T_1 * V_474 , struct V_564 * V_565 )
{
void * V_144 ;
struct V_3 * V_566 , * V_567 ;
V_144 = F_20 ( V_37 , V_33 , V_34 , V_35 , V_568 ) ;
if ( ! V_144 )
return - 1 ;
if ( F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_474 ) ||
F_23 ( V_37 , V_162 , V_565 -> V_569 ) )
goto V_42;
V_566 = F_40 ( V_37 , V_570 ) ;
if ( ! V_566 )
goto V_42;
if ( ( V_565 -> V_571 & V_572 ) &&
F_23 ( V_37 , V_573 ,
V_565 -> V_574 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_575 ) &&
F_23 ( V_37 , V_576 ,
V_565 -> V_577 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_578 ) &&
F_23 ( V_37 , V_579 ,
V_565 -> V_580 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_581 ) &&
F_23 ( V_37 , V_582 ,
V_565 -> V_583 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_584 ) &&
F_47 ( V_37 , V_585 , V_565 -> V_586 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_587 ) &&
F_47 ( V_37 , V_588 , V_565 -> V_589 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_590 ) &&
F_46 ( V_37 , V_591 ,
V_565 -> V_592 ) )
goto V_42;
switch ( V_6 -> V_120 . V_593 ) {
case V_594 :
if ( ( V_565 -> V_571 & V_595 ) &&
F_46 ( V_37 , V_596 ,
V_565 -> signal ) )
goto V_42;
if ( ( V_565 -> V_571 & V_597 ) &&
F_46 ( V_37 , V_598 ,
V_565 -> V_599 ) )
goto V_42;
break;
default:
break;
}
if ( V_565 -> V_571 & V_600 ) {
if ( ! F_107 ( V_37 , & V_565 -> V_601 ,
V_602 ) )
goto V_42;
}
if ( V_565 -> V_571 & V_603 ) {
if ( ! F_107 ( V_37 , & V_565 -> V_604 ,
V_605 ) )
goto V_42;
}
if ( ( V_565 -> V_571 & V_606 ) &&
F_23 ( V_37 , V_607 ,
V_565 -> V_608 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_609 ) &&
F_23 ( V_37 , V_610 ,
V_565 -> V_611 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_612 ) &&
F_23 ( V_37 , V_613 ,
V_565 -> V_614 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_615 ) &&
F_23 ( V_37 , V_616 ,
V_565 -> V_617 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_618 ) &&
F_23 ( V_37 , V_619 ,
V_565 -> V_620 ) )
goto V_42;
if ( V_565 -> V_571 & V_621 ) {
V_567 = F_40 ( V_37 , V_622 ) ;
if ( ! V_567 )
goto V_42;
if ( ( ( V_565 -> V_567 . V_35 & V_623 ) &&
F_24 ( V_37 , V_624 ) ) ||
( ( V_565 -> V_567 . V_35 & V_625 ) &&
F_24 ( V_37 , V_626 ) ) ||
( ( V_565 -> V_567 . V_35 & V_627 ) &&
F_24 ( V_37 , V_628 ) ) ||
F_46 ( V_37 , V_629 ,
V_565 -> V_567 . V_517 ) ||
F_47 ( V_37 , V_630 ,
V_565 -> V_567 . V_512 ) )
goto V_42;
F_41 ( V_37 , V_567 ) ;
}
if ( ( V_565 -> V_571 & V_631 ) &&
F_48 ( V_37 , V_632 ,
sizeof( struct V_540 ) ,
& V_565 -> V_541 ) )
goto V_42;
if ( ( V_565 -> V_571 & V_633 ) &&
F_110 ( V_37 , V_634 ,
V_565 -> V_635 ) )
goto V_42;
F_41 ( V_37 , V_566 ) ;
if ( ( V_565 -> V_571 & V_636 ) &&
F_48 ( V_37 , V_494 , V_565 -> V_637 ,
V_565 -> V_638 ) )
goto V_42;
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
static int F_111 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_564 V_565 ;
struct V_5 * V_8 ;
struct V_7 * V_399 ;
T_1 V_474 [ V_481 ] ;
int V_639 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_10 ( V_24 , V_14 , & V_8 , & V_399 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_8 -> V_210 -> V_640 ) {
V_26 = - V_397 ;
goto V_641;
}
while ( 1 ) {
memset ( & V_565 , 0 , sizeof( V_565 ) ) ;
V_26 = V_8 -> V_210 -> V_640 ( & V_8 -> V_120 , V_399 , V_639 ,
V_474 , & V_565 ) ;
if ( V_26 == - V_482 )
break;
if ( V_26 )
goto V_641;
if ( F_109 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_366 , V_367 ,
V_8 , V_399 , V_474 ,
& V_565 ) < 0 )
goto V_442;
V_639 ++ ;
}
V_442:
V_14 -> args [ 1 ] = V_639 ;
V_26 = V_24 -> V_31 ;
V_641:
F_15 ( V_8 ) ;
return V_26 ;
}
static int F_112 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_564 V_565 ;
struct V_23 * V_37 ;
T_1 * V_474 = NULL ;
int V_26 ;
memset ( & V_565 , 0 , sizeof( V_565 ) ) ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
V_474 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( ! V_6 -> V_210 -> V_642 )
return - V_397 ;
V_26 = V_6 -> V_210 -> V_642 ( & V_6 -> V_120 , V_8 , V_474 , & V_565 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
if ( F_109 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_6 , V_8 , V_474 , & V_565 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_84 ) ;
}
static struct V_7 * F_113 ( struct V_83 * V_84 ,
struct V_5 * V_6 )
{
struct V_3 * V_643 = V_84 -> V_4 [ V_644 ] ;
struct V_7 * V_645 ;
int V_646 ;
if ( ! V_643 )
return NULL ;
V_645 = F_3 ( F_76 ( V_84 ) , F_2 ( V_643 ) ) ;
if ( ! V_645 )
return F_33 ( - V_12 ) ;
if ( ! V_645 -> V_400 || V_645 -> V_400 -> V_120 != & V_6 -> V_120 ) {
V_646 = - V_11 ;
goto error;
}
if ( ! F_74 ( V_645 ) ) {
V_646 = - V_412 ;
goto error;
}
return V_645 ;
error:
F_6 ( V_645 ) ;
return F_33 ( V_646 ) ;
}
static int F_114 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_537 V_101 ;
T_1 * V_474 = NULL ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_647 = - 1 ;
V_101 . V_592 = - 1 ;
if ( V_84 -> V_4 [ V_648 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
V_474 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( V_84 -> V_4 [ V_649 ] ) {
V_101 . V_650 =
F_18 ( V_84 -> V_4 [ V_649 ] ) ;
V_101 . V_651 =
F_19 ( V_84 -> V_4 [ V_649 ] ) ;
}
if ( V_84 -> V_4 [ V_652 ] )
V_101 . V_647 =
F_65 ( V_84 -> V_4 [ V_652 ] ) ;
if ( V_84 -> V_4 [ V_653 ] )
V_101 . V_654 =
F_18 ( V_84 -> V_4 [ V_653 ] ) ;
if ( ! V_6 -> V_210 -> V_655 )
return - V_397 ;
if ( F_105 ( V_84 , V_8 -> V_400 -> V_105 , & V_101 ) )
return - V_11 ;
if ( V_84 -> V_4 [ V_656 ] )
V_101 . V_657 =
F_28 ( V_84 -> V_4 [ V_656 ] ) ;
if ( V_84 -> V_4 [ V_658 ] )
V_101 . V_592 =
F_28 ( V_84 -> V_4 [ V_658 ] ) ;
switch ( V_8 -> V_400 -> V_105 ) {
case V_106 :
case V_107 :
case V_108 :
if ( V_101 . V_657 )
return - V_11 ;
if ( V_101 . V_544 & F_106 ( V_553 ) )
return - V_11 ;
V_101 . V_542 &= ~ F_106 ( V_553 ) ;
if ( V_101 . V_542 &
~ ( F_106 ( V_549 ) |
F_106 ( V_550 ) |
F_106 ( V_551 ) |
F_106 ( V_552 ) ) )
return - V_11 ;
V_101 . V_659 = F_113 ( V_84 , V_6 ) ;
if ( F_5 ( V_101 . V_659 ) )
return F_7 ( V_101 . V_659 ) ;
break;
case V_114 :
case V_113 :
V_101 . V_542 &= ~ F_106 ( V_553 ) ;
case V_110 :
if ( V_101 . V_657 )
return - V_11 ;
if ( V_101 . V_654 )
return - V_11 ;
if ( V_101 . V_647 >= 0 )
return - V_11 ;
if ( V_101 . V_542 & ~ F_106 ( V_549 ) )
return - V_11 ;
break;
case V_109 :
if ( V_101 . V_659 )
return - V_11 ;
if ( V_101 . V_654 )
return - V_11 ;
if ( V_101 . V_647 >= 0 )
return - V_11 ;
if ( V_101 . V_542 &
~ ( F_106 ( V_554 ) |
F_106 ( V_552 ) |
F_106 ( V_549 ) ) )
return - V_11 ;
break;
default:
return - V_397 ;
}
V_26 = V_6 -> V_210 -> V_655 ( & V_6 -> V_120 , V_8 , V_474 , & V_101 ) ;
if ( V_101 . V_659 )
F_6 ( V_101 . V_659 ) ;
return V_26 ;
}
static int F_115 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_537 V_101 ;
T_1 * V_474 = NULL ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_652 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_649 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_648 ] )
return - V_11 ;
V_474 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_101 . V_650 =
F_18 ( V_84 -> V_4 [ V_649 ] ) ;
V_101 . V_651 =
F_19 ( V_84 -> V_4 [ V_649 ] ) ;
V_101 . V_647 =
F_65 ( V_84 -> V_4 [ V_652 ] ) ;
V_101 . V_660 = F_65 ( V_84 -> V_4 [ V_648 ] ) ;
if ( ! V_101 . V_660 || V_101 . V_660 > V_661 )
return - V_11 ;
if ( V_84 -> V_4 [ V_653 ] )
V_101 . V_654 =
F_18 ( V_84 -> V_4 [ V_653 ] ) ;
if ( V_84 -> V_4 [ V_656 ] )
V_101 . V_657 =
F_28 ( V_84 -> V_4 [ V_656 ] ) ;
if ( ! V_6 -> V_210 -> V_250 )
return - V_397 ;
if ( F_105 ( V_84 , V_8 -> V_400 -> V_105 , & V_101 ) )
return - V_11 ;
switch ( V_8 -> V_400 -> V_105 ) {
case V_106 :
case V_107 :
case V_108 :
if ( ( V_6 -> V_120 . V_35 & V_188 ) &&
( V_101 . V_544 & F_106 ( V_551 ) ) &&
V_84 -> V_4 [ V_662 ] ) {
struct V_3 * V_57 [ V_663 + 1 ] ;
struct V_3 * V_443 ;
V_443 = V_84 -> V_4 [ V_662 ] ;
V_26 = F_27 ( V_57 , V_663 , V_443 ,
V_664 ) ;
if ( V_26 )
return V_26 ;
if ( V_57 [ V_665 ] )
V_101 . V_666 =
F_28 ( V_57 [ V_665 ] ) ;
if ( V_101 . V_666 &
~ V_667 )
return - V_11 ;
if ( V_57 [ V_668 ] )
V_101 . V_669 =
F_28 ( V_57 [ V_668 ] ) ;
if ( V_101 . V_669 &
~ V_670 )
return - V_11 ;
V_101 . V_671 |= V_672 ;
}
if ( V_101 . V_544 & F_106 ( V_553 ) )
return - V_11 ;
V_101 . V_542 &= ~ F_106 ( V_553 ) ;
V_101 . V_659 = F_113 ( V_84 , V_6 ) ;
if ( F_5 ( V_101 . V_659 ) )
return F_7 ( V_101 . V_659 ) ;
break;
case V_109 :
if ( V_101 . V_544 & F_106 ( V_553 ) )
return - V_11 ;
break;
case V_113 :
if ( ! ( V_101 . V_544 & F_106 ( V_553 ) ) )
return - V_11 ;
if ( ! ( V_6 -> V_120 . V_35 & V_192 ) )
return - V_397 ;
if ( ! ( V_6 -> V_120 . V_35 & V_194 ) )
return - V_397 ;
break;
default:
return - V_397 ;
}
V_26 = V_6 -> V_210 -> V_250 ( & V_6 -> V_120 , V_8 , V_474 , & V_101 ) ;
if ( V_101 . V_659 )
F_6 ( V_101 . V_659 ) ;
return V_26 ;
}
static int F_116 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 * V_474 = NULL ;
if ( V_84 -> V_4 [ V_402 ] )
V_474 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_107 &&
V_8 -> V_400 -> V_105 != V_109 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_673 )
return - V_397 ;
return V_6 -> V_210 -> V_673 ( & V_6 -> V_120 , V_8 , V_474 ) ;
}
static int F_117 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_7 * V_8 ,
T_1 * V_674 , T_1 * V_675 ,
struct V_676 * V_677 )
{
void * V_144 ;
struct V_3 * V_678 ;
V_144 = F_20 ( V_37 , V_33 , V_34 , V_35 , V_568 ) ;
if ( ! V_144 )
return - 1 ;
if ( F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_674 ) ||
F_48 ( V_37 , V_679 , V_481 , V_675 ) ||
F_23 ( V_37 , V_162 , V_677 -> V_569 ) )
goto V_42;
V_678 = F_40 ( V_37 , V_680 ) ;
if ( ! V_678 )
goto V_42;
if ( ( V_677 -> V_571 & V_681 ) &&
F_23 ( V_37 , V_682 ,
V_677 -> V_683 ) )
goto V_42;
if ( ( ( V_677 -> V_571 & V_684 ) &&
F_23 ( V_37 , V_685 , V_677 -> V_686 ) ) ||
( ( V_677 -> V_571 & V_687 ) &&
F_23 ( V_37 , V_688 ,
V_677 -> V_689 ) ) ||
( ( V_677 -> V_571 & V_690 ) &&
F_23 ( V_37 , V_691 ,
V_677 -> V_692 ) ) ||
( ( V_677 -> V_571 & V_693 ) &&
F_46 ( V_37 , V_694 ,
V_677 -> V_35 ) ) ||
( ( V_677 -> V_571 & V_695 ) &&
F_23 ( V_37 , V_696 ,
V_677 -> V_697 ) ) ||
( ( V_677 -> V_571 & V_698 ) &&
F_46 ( V_37 , V_699 ,
V_677 -> V_700 ) ) )
goto V_42;
F_41 ( V_37 , V_678 ) ;
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
static int F_118 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_676 V_677 ;
struct V_5 * V_8 ;
struct V_7 * V_399 ;
T_1 V_674 [ V_481 ] ;
T_1 V_675 [ V_481 ] ;
int V_701 = V_14 -> args [ 1 ] ;
int V_26 ;
V_26 = F_10 ( V_24 , V_14 , & V_8 , & V_399 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_8 -> V_210 -> V_702 ) {
V_26 = - V_397 ;
goto V_641;
}
if ( V_399 -> V_400 -> V_105 != V_109 ) {
V_26 = - V_397 ;
goto V_641;
}
while ( 1 ) {
V_26 = V_8 -> V_210 -> V_702 ( & V_8 -> V_120 , V_399 , V_701 ,
V_674 , V_675 , & V_677 ) ;
if ( V_26 == - V_482 )
break;
if ( V_26 )
goto V_641;
if ( F_117 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_366 , V_367 ,
V_399 , V_674 , V_675 ,
& V_677 ) < 0 )
goto V_442;
V_701 ++ ;
}
V_442:
V_14 -> args [ 1 ] = V_701 ;
V_26 = V_24 -> V_31 ;
V_641:
F_15 ( V_8 ) ;
return V_26 ;
}
static int F_119 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_676 V_677 ;
struct V_23 * V_37 ;
T_1 * V_674 = NULL ;
T_1 V_675 [ V_481 ] ;
memset ( & V_677 , 0 , sizeof( V_677 ) ) ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
V_674 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( ! V_6 -> V_210 -> V_703 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_109 )
return - V_397 ;
V_26 = V_6 -> V_210 -> V_703 ( & V_6 -> V_120 , V_8 , V_674 , V_675 , & V_677 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
if ( F_117 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_8 , V_674 , V_675 , & V_677 ) < 0 ) {
F_62 ( V_37 ) ;
return - V_53 ;
}
return F_63 ( V_37 , V_84 ) ;
}
static int F_120 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 * V_674 = NULL ;
T_1 * V_675 = NULL ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_679 ] )
return - V_11 ;
V_674 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_675 = F_18 ( V_84 -> V_4 [ V_679 ] ) ;
if ( ! V_6 -> V_210 -> V_704 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_109 )
return - V_397 ;
return V_6 -> V_210 -> V_704 ( & V_6 -> V_120 , V_8 , V_674 , V_675 ) ;
}
static int F_121 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 * V_674 = NULL ;
T_1 * V_675 = NULL ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_679 ] )
return - V_11 ;
V_674 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_675 = F_18 ( V_84 -> V_4 [ V_679 ] ) ;
if ( ! V_6 -> V_210 -> V_252 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_109 )
return - V_397 ;
return V_6 -> V_210 -> V_252 ( & V_6 -> V_120 , V_8 , V_674 , V_675 ) ;
}
static int F_122 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 * V_674 = NULL ;
if ( V_84 -> V_4 [ V_402 ] )
V_674 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( ! V_6 -> V_210 -> V_705 )
return - V_397 ;
return V_6 -> V_210 -> V_705 ( & V_6 -> V_120 , V_8 , V_674 ) ;
}
static int F_123 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_706 V_101 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_707 = - 1 ;
V_101 . V_708 = - 1 ;
V_101 . V_709 = - 1 ;
V_101 . V_710 = - 1 ;
V_101 . V_711 = - 1 ;
if ( V_84 -> V_4 [ V_712 ] )
V_101 . V_707 =
F_28 ( V_84 -> V_4 [ V_712 ] ) ;
if ( V_84 -> V_4 [ V_713 ] )
V_101 . V_708 =
F_28 ( V_84 -> V_4 [ V_713 ] ) ;
if ( V_84 -> V_4 [ V_714 ] )
V_101 . V_709 =
F_28 ( V_84 -> V_4 [ V_714 ] ) ;
if ( V_84 -> V_4 [ V_715 ] ) {
V_101 . V_716 =
F_18 ( V_84 -> V_4 [ V_715 ] ) ;
V_101 . V_717 =
F_19 ( V_84 -> V_4 [ V_715 ] ) ;
}
if ( V_84 -> V_4 [ V_718 ] )
V_101 . V_710 = ! ! F_28 ( V_84 -> V_4 [ V_718 ] ) ;
if ( V_84 -> V_4 [ V_719 ] )
V_101 . V_711 =
F_65 ( V_84 -> V_4 [ V_719 ] ) ;
if ( ! V_6 -> V_210 -> V_256 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_397 ;
return V_6 -> V_210 -> V_256 ( & V_6 -> V_120 , V_8 , & V_101 ) ;
}
static int F_124 ( struct V_3 * V_57 [] ,
struct V_720 * V_721 )
{
struct V_722 * V_723 = & V_721 -> V_723 ;
struct V_724 * V_725 = & V_721 -> V_725 ;
if ( ! V_57 [ V_726 ] )
return - V_11 ;
if ( ! V_57 [ V_727 ] )
return - V_11 ;
if ( ! V_57 [ V_728 ] )
return - V_11 ;
if ( ! V_57 [ V_729 ] )
return - V_11 ;
if ( ! V_57 [ V_730 ] )
return - V_11 ;
V_721 -> V_35 = F_2 ( V_57 [ V_726 ] ) ;
V_723 -> V_731 =
F_2 ( V_57 [ V_727 ] ) ;
V_723 -> V_732 =
F_2 ( V_57 [ V_728 ] ) ;
V_723 -> V_733 =
F_2 ( V_57 [ V_729 ] ) ;
V_725 -> V_734 =
F_2 ( V_57 [ V_730 ] ) ;
if ( V_57 [ V_735 ] )
V_725 -> V_736 =
F_2 ( V_57 [ V_735 ] ) ;
return 0 ;
}
static int F_125 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
int V_737 ;
char * V_102 = NULL ;
F_54 ( & V_365 ) ;
if ( F_126 ( ! V_738 ) ) {
F_59 ( & V_365 ) ;
return - V_739 ;
}
F_59 ( & V_365 ) ;
if ( ! V_84 -> V_4 [ V_740 ] )
return - V_11 ;
V_102 = F_18 ( V_84 -> V_4 [ V_740 ] ) ;
V_737 = F_127 ( V_102 ) ;
return V_737 ;
}
static int F_128 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_741 V_742 ;
int V_26 = 0 ;
void * V_144 ;
struct V_3 * V_678 ;
struct V_23 * V_37 ;
if ( V_104 -> V_105 != V_109 )
return - V_397 ;
if ( ! V_6 -> V_210 -> V_743 )
return - V_397 ;
F_69 ( V_104 ) ;
if ( ! V_104 -> V_744 )
memcpy ( & V_742 , & V_745 , sizeof( V_742 ) ) ;
else
V_26 = V_6 -> V_210 -> V_743 ( & V_6 -> V_120 , V_8 ,
& V_742 ) ;
F_71 ( V_104 ) ;
if ( V_26 )
return V_26 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_746 ) ;
if ( ! V_144 )
goto V_442;
V_678 = F_40 ( V_37 , V_747 ) ;
if ( ! V_678 )
goto V_42;
if ( F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_47 ( V_37 , V_748 ,
V_742 . V_749 ) ||
F_47 ( V_37 , V_750 ,
V_742 . V_751 ) ||
F_47 ( V_37 , V_752 ,
V_742 . V_753 ) ||
F_47 ( V_37 , V_754 ,
V_742 . V_755 ) ||
F_46 ( V_37 , V_756 ,
V_742 . V_757 ) ||
F_46 ( V_37 , V_758 ,
V_742 . V_759 ) ||
F_46 ( V_37 , V_760 ,
V_742 . V_761 ) ||
F_46 ( V_37 , V_762 ,
V_742 . V_763 ) ||
F_23 ( V_37 , V_764 ,
V_742 . V_765 ) ||
F_46 ( V_37 , V_766 ,
V_742 . V_767 ) ||
F_23 ( V_37 , V_768 ,
V_742 . V_769 ) ||
F_47 ( V_37 , V_770 ,
V_742 . V_771 ) ||
F_23 ( V_37 , V_772 ,
V_742 . V_773 ) ||
F_47 ( V_37 , V_774 ,
V_742 . V_775 ) ||
F_47 ( V_37 , V_776 ,
V_742 . V_777 ) ||
F_47 ( V_37 , V_778 ,
V_742 . V_779 ) ||
F_46 ( V_37 , V_780 ,
V_742 . V_781 ) ||
F_47 ( V_37 , V_782 ,
V_742 . V_783 ) ||
F_46 ( V_37 , V_784 ,
V_742 . V_785 ) ||
F_46 ( V_37 , V_786 ,
V_742 . V_787 ) ||
F_23 ( V_37 , V_788 ,
V_742 . V_789 ) ||
F_23 ( V_37 , V_790 ,
V_742 . V_711 ) )
goto V_42;
F_41 ( V_37 , V_678 ) ;
F_51 ( V_37 , V_144 ) ;
return F_63 ( V_37 , V_84 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
V_442:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_129 ( struct V_83 * V_84 ,
struct V_741 * V_791 ,
T_2 * V_792 )
{
struct V_3 * V_57 [ V_793 + 1 ] ;
T_2 V_543 = 0 ;
#define F_130 ( T_6 , V_791 , T_7 , V_543 , T_8 , T_9 ) \
do {\
if (table[attr_num]) {\
cfg->param = nla_fn(table[attr_num]); \
mask |= (1 << (attr_num - 1)); \
} \
} while (0);\
if (!info->attrs[NL80211_ATTR_MESH_CONFIG])
return - V_11 ;
if ( F_27 ( V_57 , V_793 ,
V_84 -> V_4 [ V_747 ] ,
V_794 ) )
return - V_11 ;
F_87 ( V_793 > 32 ) ;
F_130 ( V_57 , V_791 , V_749 ,
V_543 , V_748 , F_65 ) ;
F_130 ( V_57 , V_791 , V_751 ,
V_543 , V_750 , F_65 ) ;
F_130 ( V_57 , V_791 , V_753 ,
V_543 , V_752 , F_65 ) ;
F_130 ( V_57 , V_791 , V_755 ,
V_543 , V_754 , F_65 ) ;
F_130 ( V_57 , V_791 , V_757 ,
V_543 , V_756 , F_28 ) ;
F_130 ( V_57 , V_791 , V_759 ,
V_543 , V_758 , F_28 ) ;
F_130 ( V_57 , V_791 , V_761 ,
V_543 , V_760 , F_28 ) ;
F_130 ( V_57 , V_791 , V_763 ,
V_543 , V_762 , F_28 ) ;
F_130 ( V_57 , V_791 , V_765 ,
V_543 , V_764 ,
F_2 ) ;
F_130 ( V_57 , V_791 , V_767 ,
V_543 , V_766 ,
F_28 ) ;
F_130 ( V_57 , V_791 , V_769 ,
V_543 , V_768 , F_2 ) ;
F_130 ( V_57 , V_791 , V_771 ,
V_543 , V_770 ,
F_65 ) ;
F_130 ( V_57 , V_791 , V_773 ,
V_543 , V_772 ,
F_2 ) ;
F_130 ( V_57 , V_791 , V_775 ,
V_543 , V_774 ,
F_65 ) ;
F_130 ( V_57 , V_791 , V_777 ,
V_543 , V_776 ,
F_65 ) ;
F_130 ( V_57 , V_791 ,
V_779 ,
V_543 , V_778 ,
F_65 ) ;
F_130 ( V_57 , V_791 ,
V_781 , V_543 ,
V_780 ,
F_28 ) ;
F_130 ( V_57 , V_791 ,
V_783 , V_543 ,
V_782 ,
F_65 ) ;
F_130 ( V_57 , V_791 ,
V_785 , V_543 ,
V_784 ,
F_28 ) ;
F_130 ( V_57 , V_791 , V_787 ,
V_543 , V_786 , F_28 ) ;
F_130 ( V_57 , V_791 , V_789 ,
V_543 , V_788 , F_2 ) ;
F_130 ( V_57 , V_791 , V_711 ,
V_543 , V_790 , F_65 ) ;
if ( V_792 )
* V_792 = V_543 ;
return 0 ;
#undef F_130
}
static int F_131 ( struct V_83 * V_84 ,
struct V_795 * V_796 )
{
struct V_3 * V_57 [ V_797 + 1 ] ;
if ( ! V_84 -> V_4 [ V_798 ] )
return - V_11 ;
if ( F_27 ( V_57 , V_797 ,
V_84 -> V_4 [ V_798 ] ,
V_799 ) )
return - V_11 ;
if ( V_57 [ V_800 ] )
V_796 -> V_801 =
( F_28 ( V_57 [ V_800 ] ) ) ?
V_802 :
V_803 ;
if ( V_57 [ V_804 ] )
V_796 -> V_805 =
( F_28 ( V_57 [ V_804 ] ) ) ?
V_806 :
V_807 ;
if ( V_57 [ V_808 ] )
V_796 -> V_809 =
( F_28 ( V_57 [ V_808 ] ) ) ?
V_810 :
V_811 ;
if ( V_57 [ V_812 ] ) {
struct V_3 * V_813 =
V_57 [ V_812 ] ;
if ( ! F_17 ( V_813 ) )
return - V_11 ;
V_796 -> V_814 = F_18 ( V_813 ) ;
V_796 -> V_815 = F_19 ( V_813 ) ;
}
V_796 -> V_816 = F_132 ( V_57 [ V_817 ] ) ;
V_796 -> V_818 = F_132 ( V_57 [ V_819 ] ) ;
return 0 ;
}
static int F_133 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_741 V_791 ;
T_2 V_543 ;
int V_26 ;
if ( V_104 -> V_105 != V_109 )
return - V_397 ;
if ( ! V_6 -> V_210 -> V_254 )
return - V_397 ;
V_26 = F_129 ( V_84 , & V_791 , & V_543 ) ;
if ( V_26 )
return V_26 ;
F_69 ( V_104 ) ;
if ( ! V_104 -> V_744 )
V_26 = - V_112 ;
if ( ! V_26 )
V_26 = V_6 -> V_210 -> V_254 ( & V_6 -> V_120 , V_8 ,
V_543 , & V_791 ) ;
F_71 ( V_104 ) ;
return V_26 ;
}
static int F_134 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_23 * V_37 ;
void * V_144 = NULL ;
struct V_3 * V_820 ;
unsigned int V_119 ;
int V_26 = - V_11 ;
F_54 ( & V_365 ) ;
if ( ! V_738 )
goto V_442;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 ) {
V_26 = - V_53 ;
goto V_442;
}
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_821 ) ;
if ( ! V_144 )
goto V_822;
if ( F_44 ( V_37 , V_740 ,
V_738 -> V_823 ) ||
( V_738 -> V_824 &&
F_46 ( V_37 , V_825 ,
V_738 -> V_824 ) ) )
goto V_42;
V_820 = F_40 ( V_37 , V_826 ) ;
if ( ! V_820 )
goto V_42;
for ( V_119 = 0 ; V_119 < V_738 -> V_827 ; V_119 ++ ) {
struct V_3 * V_828 ;
const struct V_720 * V_721 ;
const struct V_722 * V_723 ;
const struct V_724 * V_725 ;
V_721 = & V_738 -> V_829 [ V_119 ] ;
V_723 = & V_721 -> V_723 ;
V_725 = & V_721 -> V_725 ;
V_828 = F_40 ( V_37 , V_119 ) ;
if ( ! V_828 )
goto V_42;
if ( F_23 ( V_37 , V_726 ,
V_721 -> V_35 ) ||
F_23 ( V_37 , V_727 ,
V_723 -> V_731 ) ||
F_23 ( V_37 , V_728 ,
V_723 -> V_732 ) ||
F_23 ( V_37 , V_729 ,
V_723 -> V_733 ) ||
F_23 ( V_37 , V_735 ,
V_725 -> V_736 ) ||
F_23 ( V_37 , V_730 ,
V_725 -> V_734 ) )
goto V_42;
F_41 ( V_37 , V_828 ) ;
}
F_41 ( V_37 , V_820 ) ;
F_51 ( V_37 , V_144 ) ;
V_26 = F_63 ( V_37 , V_84 ) ;
goto V_442;
V_42:
F_52 ( V_37 , V_144 ) ;
V_822:
F_62 ( V_37 ) ;
V_26 = - V_363 ;
V_442:
F_59 ( & V_365 ) ;
return V_26 ;
}
static int F_135 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_3 * V_57 [ V_830 + 1 ] ;
struct V_3 * V_828 ;
char * V_823 = NULL ;
int V_831 = 0 , V_737 = 0 ;
T_2 V_832 = 0 , V_833 = 0 , V_834 ;
T_1 V_824 = 0 ;
struct V_835 * V_836 = NULL ;
if ( ! V_84 -> V_4 [ V_740 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_826 ] )
return - V_11 ;
V_823 = F_18 ( V_84 -> V_4 [ V_740 ] ) ;
if ( V_84 -> V_4 [ V_825 ] )
V_824 = F_28 ( V_84 -> V_4 [ V_825 ] ) ;
F_34 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_832 ++ ;
if ( V_832 > V_837 )
return - V_11 ;
}
F_54 ( & V_365 ) ;
if ( ! F_136 ( V_823 ) ) {
V_737 = - V_11 ;
goto V_838;
}
V_834 = sizeof( struct V_835 ) +
( V_832 * sizeof( struct V_720 ) ) ;
V_836 = F_32 ( V_834 , V_99 ) ;
if ( ! V_836 ) {
V_737 = - V_100 ;
goto V_838;
}
V_836 -> V_827 = V_832 ;
V_836 -> V_823 [ 0 ] = V_823 [ 0 ] ;
V_836 -> V_823 [ 1 ] = V_823 [ 1 ] ;
if ( F_137 ( V_824 ) )
V_836 -> V_824 = V_824 ;
F_34 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_80 ( V_57 , V_830 ,
F_18 ( V_828 ) , F_19 ( V_828 ) ,
V_839 ) ;
V_737 = F_124 ( V_57 , & V_836 -> V_829 [ V_833 ] ) ;
if ( V_737 )
goto V_838;
V_833 ++ ;
if ( V_833 > V_837 ) {
V_737 = - V_11 ;
goto V_838;
}
}
F_138 ( V_833 != V_832 ) ;
V_737 = F_139 ( V_836 ) ;
F_59 ( & V_365 ) ;
return V_737 ;
V_838:
F_59 ( & V_365 ) ;
F_36 ( V_836 ) ;
return V_737 ;
}
static int F_140 ( struct V_3 * V_840 )
{
struct V_3 * V_841 , * V_842 ;
int V_232 = 0 , V_843 , V_844 ;
F_34 (attr1, freqs, tmp1) {
V_232 ++ ;
F_34 (attr2, freqs, tmp2)
if ( V_841 != V_842 &&
F_2 ( V_841 ) == F_2 ( V_842 ) )
return 0 ;
}
return V_232 ;
}
static int F_141 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_845 * V_846 ;
struct V_3 * V_29 ;
struct V_120 * V_120 ;
int V_26 , V_389 , V_847 = 0 , V_232 , V_119 ;
T_10 V_815 ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
V_120 = & V_6 -> V_120 ;
if ( ! V_6 -> V_210 -> V_848 )
return - V_397 ;
if ( V_6 -> V_849 )
return - V_403 ;
if ( V_84 -> V_4 [ V_850 ] ) {
V_232 = F_140 (
V_84 -> V_4 [ V_850 ] ) ;
if ( ! V_232 )
return - V_11 ;
} else {
enum V_152 V_153 ;
V_232 = 0 ;
for ( V_153 = 0 ; V_153 < V_219 ; V_153 ++ )
if ( V_120 -> V_220 [ V_153 ] )
V_232 += V_120 -> V_220 [ V_153 ] -> V_232 ;
}
if ( V_84 -> V_4 [ V_851 ] )
F_34 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_847 ++ ;
if ( V_847 > V_120 -> V_175 )
return - V_11 ;
if ( V_84 -> V_4 [ V_494 ] )
V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
else
V_815 = 0 ;
if ( V_815 > V_120 -> V_179 )
return - V_11 ;
V_846 = F_32 ( sizeof( * V_846 )
+ sizeof( * V_846 -> V_852 ) * V_847
+ sizeof( * V_846 -> V_233 ) * V_232
+ V_815 , V_99 ) ;
if ( ! V_846 )
return - V_100 ;
if ( V_847 )
V_846 -> V_852 = ( void * ) & V_846 -> V_233 [ V_232 ] ;
V_846 -> V_847 = V_847 ;
if ( V_815 ) {
if ( V_846 -> V_852 )
V_846 -> V_814 = ( void * ) ( V_846 -> V_852 + V_847 ) ;
else
V_846 -> V_814 = ( void * ) ( V_846 -> V_233 + V_232 ) ;
}
V_119 = 0 ;
if ( V_84 -> V_4 [ V_850 ] ) {
F_34 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_38 * V_39 ;
V_39 = F_142 ( V_120 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_853;
}
if ( V_39 -> V_35 & V_43 )
continue;
V_846 -> V_233 [ V_119 ] = V_39 ;
V_119 ++ ;
}
} else {
enum V_152 V_153 ;
for ( V_153 = 0 ; V_153 < V_219 ; V_153 ++ ) {
int V_122 ;
if ( ! V_120 -> V_220 [ V_153 ] )
continue;
for ( V_122 = 0 ; V_122 < V_120 -> V_220 [ V_153 ] -> V_232 ; V_122 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_120 -> V_220 [ V_153 ] -> V_233 [ V_122 ] ;
if ( V_39 -> V_35 & V_43 )
continue;
V_846 -> V_233 [ V_119 ] = V_39 ;
V_119 ++ ;
}
}
}
if ( ! V_119 ) {
V_26 = - V_11 ;
goto V_853;
}
V_846 -> V_232 = V_119 ;
V_119 = 0 ;
if ( V_84 -> V_4 [ V_851 ] ) {
F_34 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_19 ( V_29 ) > V_460 ) {
V_26 = - V_11 ;
goto V_853;
}
V_846 -> V_852 [ V_119 ] . V_519 = F_19 ( V_29 ) ;
memcpy ( V_846 -> V_852 [ V_119 ] . V_463 , F_18 ( V_29 ) , F_19 ( V_29 ) ) ;
V_119 ++ ;
}
}
if ( V_84 -> V_4 [ V_494 ] ) {
V_846 -> V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
memcpy ( ( void * ) V_846 -> V_814 ,
F_18 ( V_84 -> V_4 [ V_494 ] ) ,
V_846 -> V_815 ) ;
}
for ( V_119 = 0 ; V_119 < V_219 ; V_119 ++ )
if ( V_120 -> V_220 [ V_119 ] )
V_846 -> V_854 [ V_119 ] =
( 1 << V_120 -> V_220 [ V_119 ] -> V_235 ) - 1 ;
if ( V_84 -> V_4 [ V_855 ] ) {
F_34 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_152 V_153 = F_143 ( V_29 ) ;
if ( V_153 < 0 || V_153 >= V_219 ) {
V_26 = - V_11 ;
goto V_853;
}
V_26 = F_144 ( V_120 -> V_220 [ V_153 ] ,
F_18 ( V_29 ) ,
F_19 ( V_29 ) ,
& V_846 -> V_854 [ V_153 ] ) ;
if ( V_26 )
goto V_853;
}
}
V_846 -> V_856 =
F_132 ( V_84 -> V_4 [ V_857 ] ) ;
V_846 -> V_8 = V_8 ;
V_846 -> V_120 = & V_6 -> V_120 ;
V_6 -> V_849 = V_846 ;
V_26 = V_6 -> V_210 -> V_848 ( & V_6 -> V_120 , V_8 , V_846 ) ;
if ( ! V_26 ) {
F_145 ( V_6 , V_8 ) ;
F_146 ( V_8 ) ;
} else {
V_853:
V_6 -> V_849 = NULL ;
F_36 ( V_846 ) ;
}
return V_26 ;
}
static int F_147 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_858 * V_846 ;
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_3 * V_29 ;
struct V_120 * V_120 ;
int V_26 , V_389 , V_847 = 0 , V_859 = 0 , V_232 , V_119 ;
T_2 V_860 ;
enum V_152 V_153 ;
T_10 V_815 ;
struct V_3 * V_57 [ V_861 + 1 ] ;
if ( ! ( V_6 -> V_120 . V_35 & V_295 ) ||
! V_6 -> V_210 -> V_296 )
return - V_397 ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_862 ] )
return - V_11 ;
V_860 = F_2 ( V_84 -> V_4 [ V_862 ] ) ;
if ( V_860 == 0 )
return - V_11 ;
V_120 = & V_6 -> V_120 ;
if ( V_84 -> V_4 [ V_850 ] ) {
V_232 = F_140 (
V_84 -> V_4 [ V_850 ] ) ;
if ( ! V_232 )
return - V_11 ;
} else {
V_232 = 0 ;
for ( V_153 = 0 ; V_153 < V_219 ; V_153 ++ )
if ( V_120 -> V_220 [ V_153 ] )
V_232 += V_120 -> V_220 [ V_153 ] -> V_232 ;
}
if ( V_84 -> V_4 [ V_851 ] )
F_34 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_847 ++ ;
if ( V_847 > V_120 -> V_177 )
return - V_11 ;
if ( V_84 -> V_4 [ V_863 ] )
F_34 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_859 ++ ;
if ( V_859 > V_120 -> V_183 )
return - V_11 ;
if ( V_84 -> V_4 [ V_494 ] )
V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
else
V_815 = 0 ;
if ( V_815 > V_120 -> V_181 )
return - V_11 ;
F_54 ( & V_6 -> V_864 ) ;
if ( V_6 -> V_865 ) {
V_26 = - V_739 ;
goto V_442;
}
V_846 = F_32 ( sizeof( * V_846 )
+ sizeof( * V_846 -> V_852 ) * V_847
+ sizeof( * V_846 -> V_866 ) * V_859
+ sizeof( * V_846 -> V_233 ) * V_232
+ V_815 , V_99 ) ;
if ( ! V_846 ) {
V_26 = - V_100 ;
goto V_442;
}
if ( V_847 )
V_846 -> V_852 = ( void * ) & V_846 -> V_233 [ V_232 ] ;
V_846 -> V_847 = V_847 ;
if ( V_815 ) {
if ( V_846 -> V_852 )
V_846 -> V_814 = ( void * ) ( V_846 -> V_852 + V_847 ) ;
else
V_846 -> V_814 = ( void * ) ( V_846 -> V_233 + V_232 ) ;
}
if ( V_859 ) {
if ( V_846 -> V_814 )
V_846 -> V_866 = ( void * ) ( V_846 -> V_814 + V_815 ) ;
else if ( V_846 -> V_852 )
V_846 -> V_866 =
( void * ) ( V_846 -> V_852 + V_847 ) ;
else
V_846 -> V_866 =
( void * ) ( V_846 -> V_233 + V_232 ) ;
}
V_846 -> V_859 = V_859 ;
V_119 = 0 ;
if ( V_84 -> V_4 [ V_850 ] ) {
F_34 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_38 * V_39 ;
V_39 = F_142 ( V_120 , F_2 ( V_29 ) ) ;
if ( ! V_39 ) {
V_26 = - V_11 ;
goto V_853;
}
if ( V_39 -> V_35 & V_43 )
continue;
V_846 -> V_233 [ V_119 ] = V_39 ;
V_119 ++ ;
}
} else {
for ( V_153 = 0 ; V_153 < V_219 ; V_153 ++ ) {
int V_122 ;
if ( ! V_120 -> V_220 [ V_153 ] )
continue;
for ( V_122 = 0 ; V_122 < V_120 -> V_220 [ V_153 ] -> V_232 ; V_122 ++ ) {
struct V_38 * V_39 ;
V_39 = & V_120 -> V_220 [ V_153 ] -> V_233 [ V_122 ] ;
if ( V_39 -> V_35 & V_43 )
continue;
V_846 -> V_233 [ V_119 ] = V_39 ;
V_119 ++ ;
}
}
}
if ( ! V_119 ) {
V_26 = - V_11 ;
goto V_853;
}
V_846 -> V_232 = V_119 ;
V_119 = 0 ;
if ( V_84 -> V_4 [ V_851 ] ) {
F_34 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_19 ( V_29 ) > V_460 ) {
V_26 = - V_11 ;
goto V_853;
}
V_846 -> V_852 [ V_119 ] . V_519 = F_19 ( V_29 ) ;
memcpy ( V_846 -> V_852 [ V_119 ] . V_463 , F_18 ( V_29 ) ,
F_19 ( V_29 ) ) ;
V_119 ++ ;
}
}
V_119 = 0 ;
if ( V_84 -> V_4 [ V_863 ] ) {
F_34 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_3 * V_463 ;
F_80 ( V_57 , V_861 ,
F_18 ( V_29 ) , F_19 ( V_29 ) ,
V_867 ) ;
V_463 = V_57 [ V_868 ] ;
if ( V_463 ) {
if ( F_19 ( V_463 ) > V_460 ) {
V_26 = - V_11 ;
goto V_853;
}
memcpy ( V_846 -> V_866 [ V_119 ] . V_463 . V_463 ,
F_18 ( V_463 ) , F_19 ( V_463 ) ) ;
V_846 -> V_866 [ V_119 ] . V_463 . V_519 =
F_19 ( V_463 ) ;
}
V_119 ++ ;
}
}
if ( V_84 -> V_4 [ V_494 ] ) {
V_846 -> V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
memcpy ( ( void * ) V_846 -> V_814 ,
F_18 ( V_84 -> V_4 [ V_494 ] ) ,
V_846 -> V_815 ) ;
}
V_846 -> V_8 = V_8 ;
V_846 -> V_120 = & V_6 -> V_120 ;
V_846 -> V_860 = V_860 ;
V_26 = V_6 -> V_210 -> V_296 ( & V_6 -> V_120 , V_8 , V_846 ) ;
if ( ! V_26 ) {
V_6 -> V_865 = V_846 ;
F_148 ( V_6 , V_8 ,
V_869 ) ;
goto V_442;
}
V_853:
F_36 ( V_846 ) ;
V_442:
F_59 ( & V_6 -> V_864 ) ;
return V_26 ;
}
static int F_149 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
if ( ! ( V_6 -> V_120 . V_35 & V_295 ) ||
! V_6 -> V_210 -> V_870 )
return - V_397 ;
F_54 ( & V_6 -> V_864 ) ;
V_26 = F_150 ( V_6 , false ) ;
F_59 ( & V_6 -> V_864 ) ;
return V_26 ;
}
static int F_151 ( struct V_23 * V_37 , struct V_13 * V_14 ,
T_2 V_34 , int V_35 ,
struct V_5 * V_6 ,
struct V_103 * V_104 ,
struct V_871 * V_872 )
{
struct V_873 * V_15 = & V_872 -> V_874 ;
void * V_144 ;
struct V_3 * V_875 ;
F_38 ( V_104 ) ;
V_144 = F_20 ( V_37 , F_58 ( V_14 -> V_24 ) . V_33 , V_34 , V_35 ,
V_876 ) ;
if ( ! V_144 )
return - 1 ;
F_152 ( V_14 , V_144 , & V_18 ) ;
if ( F_23 ( V_37 , V_162 , V_6 -> V_877 ) ||
F_23 ( V_37 , V_10 , V_104 -> V_399 -> V_9 ) )
goto V_42;
V_875 = F_40 ( V_37 , V_878 ) ;
if ( ! V_875 )
goto V_42;
if ( ( ! F_153 ( V_15 -> V_401 ) &&
F_48 ( V_37 , V_879 , V_481 , V_15 -> V_401 ) ) ||
( V_15 -> V_880 && V_15 -> V_881 &&
F_48 ( V_37 , V_882 ,
V_15 -> V_881 ,
V_15 -> V_880 ) ) ||
( V_15 -> V_502 && V_15 -> V_883 &&
V_15 -> V_502 != V_15 -> V_880 &&
F_48 ( V_37 , V_884 ,
V_15 -> V_883 , V_15 -> V_502 ) ) )
goto V_42;
if ( V_15 -> V_885 &&
F_110 ( V_37 , V_886 , V_15 -> V_885 ) )
goto V_42;
if ( V_15 -> V_512 &&
F_47 ( V_37 , V_887 , V_15 -> V_512 ) )
goto V_42;
if ( F_47 ( V_37 , V_888 , V_15 -> V_889 ) ||
F_23 ( V_37 , V_890 , V_15 -> V_891 -> V_41 ) ||
F_23 ( V_37 , V_892 ,
F_154 ( V_893 - V_872 -> V_894 ) ) )
goto V_42;
switch ( V_6 -> V_120 . V_593 ) {
case V_594 :
if ( F_23 ( V_37 , V_895 , V_15 -> signal ) )
goto V_42;
break;
case V_896 :
if ( F_46 ( V_37 , V_897 , V_15 -> signal ) )
goto V_42;
break;
default:
break;
}
switch ( V_104 -> V_105 ) {
case V_114 :
case V_113 :
if ( V_872 == V_104 -> V_111 &&
F_23 ( V_37 , V_898 ,
V_899 ) )
goto V_42;
break;
case V_110 :
if ( V_872 == V_104 -> V_111 &&
F_23 ( V_37 , V_898 ,
V_900 ) )
goto V_42;
break;
default:
break;
}
F_41 ( V_37 , V_875 ) ;
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
static int F_155 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_871 * V_848 ;
struct V_103 * V_104 ;
int V_364 = V_14 -> args [ 1 ] , V_67 = 0 ;
int V_26 ;
V_26 = F_10 ( V_24 , V_14 , & V_6 , & V_8 ) ;
if ( V_26 )
return V_26 ;
V_104 = V_8 -> V_400 ;
F_69 ( V_104 ) ;
F_156 ( & V_6 -> V_901 ) ;
F_157 ( V_6 ) ;
V_14 -> V_34 = V_6 -> V_877 ;
F_55 (scan, &rdev->bss_list, list) {
if ( ++ V_67 <= V_364 )
continue;
if ( F_151 ( V_24 , V_14 ,
V_14 -> V_16 -> V_366 , V_367 ,
V_6 , V_104 , V_848 ) < 0 ) {
V_67 -- ;
break;
}
}
F_158 ( & V_6 -> V_901 ) ;
F_71 ( V_104 ) ;
V_14 -> args [ 1 ] = V_67 ;
F_15 ( V_6 ) ;
return V_24 -> V_31 ;
}
static int F_159 ( struct V_23 * V_37 , T_2 V_33 , T_2 V_34 ,
int V_35 , struct V_7 * V_8 ,
struct V_902 * V_903 )
{
void * V_144 ;
struct V_3 * V_904 ;
V_144 = F_20 ( V_37 , V_33 , V_34 , V_35 ,
V_905 ) ;
if ( ! V_144 )
return - V_100 ;
if ( F_23 ( V_37 , V_10 , V_8 -> V_9 ) )
goto V_42;
V_904 = F_40 ( V_37 , V_906 ) ;
if ( ! V_904 )
goto V_42;
if ( F_23 ( V_37 , V_907 ,
V_903 -> V_891 -> V_41 ) )
goto V_42;
if ( ( V_903 -> V_571 & V_908 ) &&
F_46 ( V_37 , V_909 , V_903 -> V_910 ) )
goto V_42;
if ( ( V_903 -> V_571 & V_911 ) &&
F_24 ( V_37 , V_912 ) )
goto V_42;
if ( ( V_903 -> V_571 & V_913 ) &&
F_110 ( V_37 , V_914 ,
V_903 -> V_915 ) )
goto V_42;
if ( ( V_903 -> V_571 & V_916 ) &&
F_110 ( V_37 , V_917 ,
V_903 -> V_918 ) )
goto V_42;
if ( ( V_903 -> V_571 & V_919 ) &&
F_110 ( V_37 , V_920 ,
V_903 -> V_921 ) )
goto V_42;
if ( ( V_903 -> V_571 & V_922 ) &&
F_110 ( V_37 , V_923 ,
V_903 -> V_924 ) )
goto V_42;
if ( ( V_903 -> V_571 & V_925 ) &&
F_110 ( V_37 , V_926 ,
V_903 -> V_927 ) )
goto V_42;
F_41 ( V_37 , V_904 ) ;
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
static int F_160 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_902 V_903 ;
struct V_5 * V_8 ;
struct V_7 * V_399 ;
int V_928 = V_14 -> args [ 1 ] ;
int V_15 ;
V_15 = F_10 ( V_24 , V_14 , & V_8 , & V_399 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_8 -> V_210 -> V_929 ) {
V_15 = - V_397 ;
goto V_641;
}
while ( 1 ) {
struct V_38 * V_39 ;
V_15 = V_8 -> V_210 -> V_929 ( & V_8 -> V_120 , V_399 , V_928 ,
& V_903 ) ;
if ( V_15 == - V_482 )
break;
if ( V_15 )
goto V_641;
if ( ! V_903 . V_891 ) {
V_15 = - V_11 ;
goto V_442;
}
V_39 = F_142 ( & V_8 -> V_120 ,
V_903 . V_891 -> V_41 ) ;
if ( ! V_39 || V_39 -> V_35 & V_43 ) {
V_928 ++ ;
continue;
}
if ( F_159 ( V_24 ,
F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_366 , V_367 ,
V_399 ,
& V_903 ) < 0 )
goto V_442;
V_928 ++ ;
}
V_442:
V_14 -> args [ 1 ] = V_928 ;
V_15 = V_24 -> V_31 ;
V_641:
F_15 ( V_8 ) ;
return V_15 ;
}
static bool F_101 ( enum V_930 V_528 )
{
return V_528 <= V_931 ;
}
static bool F_161 ( T_2 V_932 )
{
return ! ( V_932 & ~ ( V_933 |
V_934 ) ) ;
}
static int F_162 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_38 * V_39 ;
const T_1 * V_401 , * V_463 , * V_814 = NULL ;
int V_26 , V_519 , V_815 = 0 ;
enum V_930 V_528 ;
struct V_55 V_54 ;
bool V_935 ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_527 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_518 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_396 ] )
return - V_11 ;
V_26 = F_30 ( V_84 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 . V_67 >= 0 ) {
if ( V_54 . type != - 1 && V_54 . type != V_477 )
return - V_11 ;
if ( ! V_54 . V_69 . V_54 || ! V_54 . V_69 . V_70 )
return - V_11 ;
if ( ( V_54 . V_69 . V_74 != V_936 ||
V_54 . V_69 . V_70 != V_937 ) &&
( V_54 . V_69 . V_74 != V_938 ||
V_54 . V_69 . V_70 != V_939 ) )
return - V_11 ;
if ( V_54 . V_67 > 4 )
return - V_11 ;
} else {
V_54 . V_69 . V_70 = 0 ;
V_54 . V_69 . V_54 = NULL ;
}
if ( V_54 . V_67 >= 0 ) {
int V_119 ;
bool V_940 = false ;
for ( V_119 = 0 ; V_119 < V_6 -> V_120 . V_197 ; V_119 ++ ) {
if ( V_54 . V_69 . V_74 == V_6 -> V_120 . V_198 [ V_119 ] ) {
V_940 = true ;
break;
}
}
if ( ! V_940 )
return - V_11 ;
}
if ( ! V_6 -> V_210 -> V_258 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_39 = F_142 ( & V_6 -> V_120 ,
F_2 ( V_84 -> V_4 [ V_396 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_43 ) )
return - V_11 ;
V_463 = F_18 ( V_84 -> V_4 [ V_518 ] ) ;
V_519 = F_19 ( V_84 -> V_4 [ V_518 ] ) ;
if ( V_84 -> V_4 [ V_494 ] ) {
V_814 = F_18 ( V_84 -> V_4 [ V_494 ] ) ;
V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
}
V_528 = F_2 ( V_84 -> V_4 [ V_527 ] ) ;
if ( ! F_101 ( V_528 ) )
return - V_11 ;
V_935 = ! ! V_84 -> V_4 [ V_941 ] ;
if ( V_935 )
return 0 ;
return F_163 ( V_6 , V_8 , V_39 , V_528 , V_401 ,
V_463 , V_519 , V_814 , V_815 ,
V_54 . V_69 . V_54 , V_54 . V_69 . V_70 , V_54 . V_67 ) ;
}
static int F_102 ( struct V_5 * V_6 ,
struct V_83 * V_84 ,
struct V_942 * V_943 ,
int V_944 )
{
memset ( V_943 , 0 , sizeof( * V_943 ) ) ;
V_943 -> V_945 = V_84 -> V_4 [ V_946 ] ;
if ( V_84 -> V_4 [ V_202 ] ) {
T_3 V_947 ;
V_947 = F_65 (
V_84 -> V_4 [ V_202 ] ) ;
V_943 -> V_948 = F_164 ( V_947 ) ;
if ( ! ( V_6 -> V_120 . V_35 & V_201 ) &&
V_947 != V_949 )
return - V_11 ;
if ( V_84 -> V_4 [ V_950 ] )
V_943 -> V_951 = true ;
} else
V_943 -> V_948 = F_164 ( V_949 ) ;
if ( V_84 -> V_4 [ V_952 ] ) {
void * V_102 ;
int V_31 , V_119 ;
V_102 = F_18 ( V_84 -> V_4 [ V_952 ] ) ;
V_31 = F_19 ( V_84 -> V_4 [ V_952 ] ) ;
V_943 -> V_953 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
if ( V_943 -> V_953 > V_944 )
return - V_11 ;
memcpy ( V_943 -> V_954 , V_102 , V_31 ) ;
for ( V_119 = 0 ; V_119 < V_943 -> V_953 ; V_119 ++ )
if ( ! F_165 (
& V_6 -> V_120 ,
V_943 -> V_954 [ V_119 ] ) )
return - V_11 ;
}
if ( V_84 -> V_4 [ V_955 ] ) {
V_943 -> V_956 =
F_2 ( V_84 -> V_4 [ V_955 ] ) ;
if ( ! F_165 ( & V_6 -> V_120 ,
V_943 -> V_956 ) )
return - V_11 ;
}
if ( V_84 -> V_4 [ V_957 ] ) {
V_943 -> V_932 =
F_2 ( V_84 -> V_4 [ V_957 ] ) ;
if ( ! F_161 ( V_943 -> V_932 ) )
return - V_11 ;
}
if ( V_84 -> V_4 [ V_958 ] ) {
void * V_102 ;
int V_31 ;
V_102 = F_18 ( V_84 -> V_4 [ V_958 ] ) ;
V_31 = F_19 ( V_84 -> V_4 [ V_958 ] ) ;
V_943 -> V_959 = V_31 / sizeof( T_2 ) ;
if ( V_31 % sizeof( T_2 ) )
return - V_11 ;
if ( V_943 -> V_959 > V_960 )
return - V_11 ;
memcpy ( V_943 -> V_961 , V_102 , V_31 ) ;
}
return 0 ;
}
static int F_166 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_942 V_530 ;
struct V_38 * V_39 ;
const T_1 * V_401 , * V_463 , * V_814 = NULL , * V_962 = NULL ;
int V_26 , V_519 , V_815 = 0 ;
bool V_963 = false ;
T_2 V_35 = 0 ;
struct V_964 * V_654 = NULL ;
struct V_964 * V_965 = NULL ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_402 ] ||
! V_84 -> V_4 [ V_518 ] ||
! V_84 -> V_4 [ V_396 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_260 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_39 = F_142 ( & V_6 -> V_120 ,
F_2 ( V_84 -> V_4 [ V_396 ] ) ) ;
if ( ! V_39 || ( V_39 -> V_35 & V_43 ) )
return - V_11 ;
V_463 = F_18 ( V_84 -> V_4 [ V_518 ] ) ;
V_519 = F_19 ( V_84 -> V_4 [ V_518 ] ) ;
if ( V_84 -> V_4 [ V_494 ] ) {
V_814 = F_18 ( V_84 -> V_4 [ V_494 ] ) ;
V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
}
if ( V_84 -> V_4 [ V_966 ] ) {
enum V_967 V_968 =
F_2 ( V_84 -> V_4 [ V_966 ] ) ;
if ( V_968 == V_969 )
V_963 = true ;
else if ( V_968 != V_970 )
return - V_11 ;
}
if ( V_84 -> V_4 [ V_971 ] )
V_962 = F_18 ( V_84 -> V_4 [ V_971 ] ) ;
if ( F_132 ( V_84 -> V_4 [ V_972 ] ) )
V_35 |= V_973 ;
if ( V_84 -> V_4 [ V_362 ] )
V_965 =
F_18 ( V_84 -> V_4 [ V_362 ] ) ;
if ( V_84 -> V_4 [ V_653 ] ) {
if ( ! V_965 )
return - V_11 ;
V_654 = F_18 ( V_84 -> V_4 [ V_653 ] ) ;
}
V_26 = F_102 ( V_6 , V_84 , & V_530 , 1 ) ;
if ( ! V_26 )
V_26 = F_167 ( V_6 , V_8 , V_39 , V_401 , V_962 ,
V_463 , V_519 , V_814 , V_815 , V_963 ,
& V_530 , V_35 , V_654 ,
V_965 ) ;
return V_26 ;
}
static int F_168 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
const T_1 * V_814 = NULL , * V_401 ;
int V_815 = 0 ;
T_3 V_974 ;
bool V_935 ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_975 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_262 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_974 = F_65 ( V_84 -> V_4 [ V_975 ] ) ;
if ( V_974 == 0 ) {
return - V_11 ;
}
if ( V_84 -> V_4 [ V_494 ] ) {
V_814 = F_18 ( V_84 -> V_4 [ V_494 ] ) ;
V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
}
V_935 = ! ! V_84 -> V_4 [ V_941 ] ;
return F_169 ( V_6 , V_8 , V_401 , V_814 , V_815 , V_974 ,
V_935 ) ;
}
static int F_170 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
const T_1 * V_814 = NULL , * V_401 ;
int V_815 = 0 ;
T_3 V_974 ;
bool V_935 ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_975 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_264 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_974 = F_65 ( V_84 -> V_4 [ V_975 ] ) ;
if ( V_974 == 0 ) {
return - V_11 ;
}
if ( V_84 -> V_4 [ V_494 ] ) {
V_814 = F_18 ( V_84 -> V_4 [ V_494 ] ) ;
V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
}
V_935 = ! ! V_84 -> V_4 [ V_941 ] ;
return F_171 ( V_6 , V_8 , V_401 , V_814 , V_815 , V_974 ,
V_935 ) ;
}
static bool
F_172 ( struct V_5 * V_6 ,
int V_976 [ V_219 ] ,
int V_977 )
{
struct V_120 * V_120 = & V_6 -> V_120 ;
bool V_978 = false ;
int V_153 , V_119 ;
for ( V_153 = 0 ; V_153 < V_219 ; V_153 ++ ) {
struct V_979 * V_980 ;
V_980 = V_120 -> V_220 [ V_153 ] ;
if ( ! V_980 )
continue;
for ( V_119 = 0 ; V_119 < V_980 -> V_235 ; V_119 ++ ) {
if ( V_980 -> V_236 [ V_119 ] . V_238 == V_977 ) {
V_976 [ V_153 ] = V_119 + 1 ;
V_978 = true ;
break;
}
}
}
return V_978 ;
}
static int F_173 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_981 V_982 ;
struct V_120 * V_120 ;
struct V_94 * V_983 = NULL ;
int V_26 ;
memset ( & V_982 , 0 , sizeof( V_982 ) ) ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_396 ] ||
! V_84 -> V_4 [ V_518 ] ||
! F_19 ( V_84 -> V_4 [ V_518 ] ) )
return - V_11 ;
V_982 . V_512 = 100 ;
if ( V_84 -> V_4 [ V_514 ] ) {
V_982 . V_512 =
F_2 ( V_84 -> V_4 [ V_514 ] ) ;
if ( V_982 . V_512 < 1 || V_982 . V_512 > 10000 )
return - V_11 ;
}
if ( ! V_6 -> V_210 -> V_266 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_110 )
return - V_397 ;
V_120 = & V_6 -> V_120 ;
if ( V_84 -> V_4 [ V_402 ] ) {
V_982 . V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( ! F_174 ( V_982 . V_401 ) )
return - V_11 ;
}
V_982 . V_463 = F_18 ( V_84 -> V_4 [ V_518 ] ) ;
V_982 . V_519 = F_19 ( V_84 -> V_4 [ V_518 ] ) ;
if ( V_84 -> V_4 [ V_494 ] ) {
V_982 . V_814 = F_18 ( V_84 -> V_4 [ V_494 ] ) ;
V_982 . V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
}
if ( V_84 -> V_4 [ V_390 ] ) {
enum V_387 V_388 ;
if ( ! F_67 ( V_84 , & V_388 ) )
return - V_11 ;
if ( V_388 != V_391 &&
! ( V_120 -> V_360 & V_984 ) )
return - V_11 ;
V_982 . V_388 = V_388 ;
} else {
V_982 . V_388 = V_391 ;
}
V_982 . V_891 = F_175 ( V_6 ,
F_2 ( V_84 -> V_4 [ V_396 ] ) ,
V_982 . V_388 ) ;
if ( ! V_982 . V_891 ||
V_982 . V_891 -> V_35 & V_47 ||
V_982 . V_891 -> V_35 & V_43 )
return - V_11 ;
if ( ( V_982 . V_388 == V_393 ||
V_982 . V_388 == V_394 ) &&
! F_176 ( & V_6 -> V_120 , V_982 . V_891 ,
V_982 . V_388 ) )
return - V_11 ;
V_982 . V_985 = ! ! V_84 -> V_4 [ V_986 ] ;
V_982 . V_525 = ! ! V_84 -> V_4 [ V_526 ] ;
if ( V_84 -> V_4 [ V_715 ] ) {
T_1 * V_854 =
F_18 ( V_84 -> V_4 [ V_715 ] ) ;
int V_987 =
F_19 ( V_84 -> V_4 [ V_715 ] ) ;
struct V_979 * V_980 =
V_120 -> V_220 [ V_982 . V_891 -> V_153 ] ;
V_26 = F_144 ( V_980 , V_854 , V_987 ,
& V_982 . V_716 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_84 -> V_4 [ V_988 ] &&
! F_172 ( V_6 , V_982 . V_976 ,
F_2 ( V_84 -> V_4 [ V_988 ] ) ) )
return - V_11 ;
if ( V_982 . V_525 && V_84 -> V_4 [ V_989 ] ) {
V_983 = F_31 ( V_6 ,
V_84 -> V_4 [ V_989 ] ) ;
if ( F_5 ( V_983 ) )
return F_7 ( V_983 ) ;
}
V_982 . V_945 =
F_132 ( V_84 -> V_4 [ V_946 ] ) ;
V_26 = F_177 ( V_6 , V_8 , & V_982 , V_983 ) ;
if ( V_26 )
F_36 ( V_983 ) ;
return V_26 ;
}
static int F_178 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
if ( ! V_6 -> V_210 -> V_990 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_110 )
return - V_397 ;
return F_179 ( V_6 , V_8 , false ) ;
}
static int F_180 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int V_26 ;
if ( ! V_84 -> V_4 [ V_991 ] )
return - V_11 ;
V_26 = - V_397 ;
if ( V_6 -> V_210 -> V_304 ) {
V_6 -> V_992 = V_84 ;
V_26 = V_6 -> V_210 -> V_304 ( & V_6 -> V_120 ,
F_18 ( V_84 -> V_4 [ V_991 ] ) ,
F_19 ( V_84 -> V_4 [ V_991 ] ) ) ;
V_6 -> V_992 = NULL ;
}
return V_26 ;
}
static int F_181 ( struct V_23 * V_24 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 ;
int V_26 ;
long V_993 ;
void * V_102 = NULL ;
int V_994 = 0 ;
if ( V_14 -> args [ 0 ] ) {
V_993 = V_14 -> args [ 0 ] - 1 ;
} else {
V_26 = F_9 ( V_14 -> V_16 , V_17 + V_18 . V_19 ,
V_18 . V_20 , V_18 . V_21 ,
V_22 ) ;
if ( V_26 )
return V_26 ;
if ( V_18 . V_20 [ V_159 ] ) {
V_993 = F_2 (
V_18 . V_20 [ V_159 ] ) ;
} else {
struct V_7 * V_399 ;
V_26 = F_1 ( F_13 ( V_24 -> V_27 ) ,
V_18 . V_20 ,
& V_6 , & V_399 ) ;
if ( V_26 )
return V_26 ;
F_6 ( V_399 ) ;
V_993 = V_6 -> V_160 ;
F_16 ( V_6 ) ;
}
if ( V_18 . V_20 [ V_991 ] )
V_14 -> args [ 1 ] =
( long ) V_18 . V_20 [ V_991 ] ;
}
if ( V_14 -> args [ 1 ] ) {
V_102 = F_18 ( ( void * ) V_14 -> args [ 1 ] ) ;
V_994 = F_19 ( ( void * ) V_14 -> args [ 1 ] ) ;
}
F_54 ( & V_365 ) ;
V_6 = F_182 ( V_993 ) ;
if ( ! V_6 ) {
F_59 ( & V_365 ) ;
return - V_482 ;
}
F_183 ( V_6 ) ;
F_59 ( & V_365 ) ;
if ( ! V_6 -> V_210 -> V_995 ) {
V_26 = - V_397 ;
goto V_641;
}
while ( 1 ) {
void * V_144 = F_20 ( V_24 , F_58 ( V_14 -> V_24 ) . V_33 ,
V_14 -> V_16 -> V_366 , V_367 ,
V_996 ) ;
struct V_3 * V_997 ;
if ( F_23 ( V_24 , V_159 , V_993 ) ) {
F_52 ( V_24 , V_144 ) ;
break;
}
V_997 = F_40 ( V_24 , V_991 ) ;
if ( ! V_997 ) {
F_52 ( V_24 , V_144 ) ;
break;
}
V_26 = V_6 -> V_210 -> V_995 ( & V_6 -> V_120 , V_24 , V_14 ,
V_102 , V_994 ) ;
F_41 ( V_24 , V_997 ) ;
if ( V_26 == - V_53 || V_26 == - V_482 ) {
F_52 ( V_24 , V_144 ) ;
break;
} else if ( V_26 ) {
F_52 ( V_24 , V_144 ) ;
goto V_641;
}
F_51 ( V_24 , V_144 ) ;
}
V_26 = V_24 -> V_31 ;
V_14 -> args [ 0 ] = V_993 + 1 ;
V_641:
F_16 ( V_6 ) ;
return V_26 ;
}
static struct V_23 *
F_184 ( struct V_5 * V_6 ,
int V_998 , T_2 V_33 , T_2 V_34 , T_11 V_999 )
{
struct V_23 * V_24 ;
void * V_144 ;
struct V_3 * V_102 ;
V_24 = F_61 ( V_998 + 100 , V_999 ) ;
if ( ! V_24 )
return NULL ;
V_144 = F_20 ( V_24 , V_33 , V_34 , 0 , V_996 ) ;
if ( ! V_144 ) {
F_185 ( V_24 ) ;
return NULL ;
}
if ( F_23 ( V_24 , V_159 , V_6 -> V_160 ) )
goto V_42;
V_102 = F_40 ( V_24 , V_991 ) ;
( ( void * * ) V_24 -> V_14 ) [ 0 ] = V_6 ;
( ( void * * ) V_24 -> V_14 ) [ 1 ] = V_144 ;
( ( void * * ) V_24 -> V_14 ) [ 2 ] = V_102 ;
return V_24 ;
V_42:
F_185 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_186 ( struct V_120 * V_120 ,
int V_998 )
{
struct V_5 * V_6 = F_77 ( V_120 ) ;
if ( F_187 ( ! V_6 -> V_992 ) )
return NULL ;
return F_184 ( V_6 , V_998 ,
V_6 -> V_992 -> V_370 ,
V_6 -> V_992 -> V_371 ,
V_99 ) ;
}
int F_188 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = ( ( void * * ) V_24 -> V_14 ) [ 0 ] ;
void * V_144 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_3 * V_102 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
if ( F_187 ( ! V_6 -> V_992 ) ) {
F_185 ( V_24 ) ;
return - V_11 ;
}
F_41 ( V_24 , V_102 ) ;
F_51 ( V_24 , V_144 ) ;
return F_63 ( V_24 , V_6 -> V_992 ) ;
}
struct V_23 * F_189 ( struct V_120 * V_120 ,
int V_998 , T_11 V_999 )
{
struct V_5 * V_6 = F_77 ( V_120 ) ;
return F_184 ( V_6 , V_998 , 0 , 0 , V_999 ) ;
}
void F_190 ( struct V_23 * V_24 , T_11 V_999 )
{
void * V_144 = ( ( void * * ) V_24 -> V_14 ) [ 1 ] ;
struct V_3 * V_102 = ( ( void * * ) V_24 -> V_14 ) [ 2 ] ;
F_41 ( V_24 , V_102 ) ;
F_51 ( V_24 , V_144 ) ;
F_191 ( V_24 , 0 , V_1000 . V_1001 , V_999 ) ;
}
static int F_192 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_1002 V_306 ;
struct V_120 * V_120 ;
struct V_94 * V_983 = NULL ;
int V_26 ;
memset ( & V_306 , 0 , sizeof( V_306 ) ) ;
if ( ! F_17 ( V_84 -> V_4 [ V_494 ] ) )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_518 ] ||
! F_19 ( V_84 -> V_4 [ V_518 ] ) )
return - V_11 ;
if ( V_84 -> V_4 [ V_527 ] ) {
V_306 . V_528 =
F_2 ( V_84 -> V_4 [ V_527 ] ) ;
if ( ! F_101 ( V_306 . V_528 ) )
return - V_11 ;
} else
V_306 . V_528 = V_529 ;
V_306 . V_525 = V_84 -> V_4 [ V_526 ] ;
V_26 = F_102 ( V_6 , V_84 , & V_306 . V_530 ,
V_531 ) ;
if ( V_26 )
return V_26 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
V_120 = & V_6 -> V_120 ;
V_306 . V_1003 = - 1 ;
if ( V_84 -> V_4 [ V_1004 ] &&
( V_120 -> V_35 & V_190 ) ) {
V_306 . V_1003 =
F_65 ( V_84 -> V_4 [ V_1004 ] ) ;
}
if ( V_84 -> V_4 [ V_402 ] )
V_306 . V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_306 . V_463 = F_18 ( V_84 -> V_4 [ V_518 ] ) ;
V_306 . V_519 = F_19 ( V_84 -> V_4 [ V_518 ] ) ;
if ( V_84 -> V_4 [ V_494 ] ) {
V_306 . V_814 = F_18 ( V_84 -> V_4 [ V_494 ] ) ;
V_306 . V_815 = F_19 ( V_84 -> V_4 [ V_494 ] ) ;
}
if ( V_84 -> V_4 [ V_396 ] ) {
V_306 . V_891 =
F_142 ( V_120 ,
F_2 ( V_84 -> V_4 [ V_396 ] ) ) ;
if ( ! V_306 . V_891 ||
V_306 . V_891 -> V_35 & V_43 )
return - V_11 ;
}
if ( V_306 . V_525 && V_84 -> V_4 [ V_989 ] ) {
V_983 = F_31 ( V_6 ,
V_84 -> V_4 [ V_989 ] ) ;
if ( F_5 ( V_983 ) )
return F_7 ( V_983 ) ;
}
if ( F_132 ( V_84 -> V_4 [ V_972 ] ) )
V_306 . V_35 |= V_973 ;
if ( V_84 -> V_4 [ V_362 ] )
memcpy ( & V_306 . V_965 ,
F_18 ( V_84 -> V_4 [ V_362 ] ) ,
sizeof( V_306 . V_965 ) ) ;
if ( V_84 -> V_4 [ V_653 ] ) {
if ( ! V_84 -> V_4 [ V_362 ] )
return - V_11 ;
memcpy ( & V_306 . V_654 ,
F_18 ( V_84 -> V_4 [ V_653 ] ) ,
sizeof( V_306 . V_654 ) ) ;
}
V_26 = F_193 ( V_6 , V_8 , & V_306 , V_983 ) ;
if ( V_26 )
F_36 ( V_983 ) ;
return V_26 ;
}
static int F_194 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_3 V_1005 ;
if ( ! V_84 -> V_4 [ V_975 ] )
V_1005 = V_1006 ;
else
V_1005 = F_65 ( V_84 -> V_4 [ V_975 ] ) ;
if ( V_1005 == 0 )
return - V_11 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
return F_195 ( V_6 , V_8 , V_1005 , true ) ;
}
static int F_196 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_1 * V_1 ;
int V_26 ;
T_2 V_33 ;
if ( ! V_84 -> V_4 [ V_1007 ] )
return - V_11 ;
V_33 = F_2 ( V_84 -> V_4 [ V_1007 ] ) ;
V_1 = F_197 ( V_33 ) ;
if ( F_5 ( V_1 ) )
return F_7 ( V_1 ) ;
V_26 = 0 ;
if ( ! F_56 ( F_57 ( & V_6 -> V_120 ) , V_1 ) )
V_26 = F_198 ( V_6 , V_1 ) ;
F_199 ( V_1 ) ;
return V_26 ;
}
static int F_200 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
int (* F_201)( struct V_120 * V_120 , struct V_7 * V_8 ,
struct V_1008 * V_1009 ) = NULL ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_1008 V_1009 ;
memset ( & V_1009 , 0 , sizeof( struct V_1008 ) ) ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_84 -> V_4 [ V_1010 ] )
return - V_11 ;
V_1009 . V_1011 = F_18 ( V_84 -> V_4 [ V_1010 ] ) ;
V_1009 . V_401 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
switch ( V_84 -> V_1012 -> V_36 ) {
case V_1013 :
F_201 = V_6 -> V_210 -> V_270 ;
break;
case V_1014 :
F_201 = V_6 -> V_210 -> V_272 ;
break;
default:
F_187 ( 1 ) ;
break;
}
if ( ! F_201 )
return - V_397 ;
return F_201 ( & V_6 -> V_120 , V_8 , & V_1009 ) ;
}
static int F_202 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_114 )
return - V_397 ;
if ( ! V_6 -> V_210 -> V_274 )
return - V_397 ;
return V_6 -> V_210 -> V_274 ( & V_6 -> V_120 , V_8 ) ;
}
static int F_203 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 V_1015 , V_1016 ;
T_3 V_1017 ;
T_1 * V_1018 ;
if ( ! ( V_6 -> V_120 . V_35 & V_192 ) ||
! V_6 -> V_210 -> V_291 )
return - V_397 ;
if ( ! V_84 -> V_4 [ V_1019 ] ||
! V_84 -> V_4 [ V_1020 ] ||
! V_84 -> V_4 [ V_1021 ] ||
! V_84 -> V_4 [ V_494 ] ||
! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
V_1018 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_1015 = F_28 ( V_84 -> V_4 [ V_1019 ] ) ;
V_1017 = F_65 ( V_84 -> V_4 [ V_1020 ] ) ;
V_1016 = F_28 ( V_84 -> V_4 [ V_1021 ] ) ;
return V_6 -> V_210 -> V_291 ( & V_6 -> V_120 , V_8 , V_1018 , V_1015 ,
V_1016 , V_1017 ,
F_18 ( V_84 -> V_4 [ V_494 ] ) ,
F_19 ( V_84 -> V_4 [ V_494 ] ) ) ;
}
static int F_204 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
enum V_1022 V_1023 ;
T_1 * V_1018 ;
if ( ! ( V_6 -> V_120 . V_35 & V_192 ) ||
! V_6 -> V_210 -> V_293 )
return - V_397 ;
if ( ! V_84 -> V_4 [ V_1024 ] ||
! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
V_1023 = F_28 ( V_84 -> V_4 [ V_1024 ] ) ;
V_1018 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
return V_6 -> V_210 -> V_293 ( & V_6 -> V_120 , V_8 , V_1018 , V_1023 ) ;
}
static int F_205 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_38 * V_39 ;
struct V_23 * V_37 ;
void * V_144 ;
T_12 V_472 ;
enum V_387 V_388 = V_391 ;
T_2 V_395 , V_1025 ;
int V_26 ;
if ( ! V_84 -> V_4 [ V_396 ] ||
! V_84 -> V_4 [ V_1026 ] )
return - V_11 ;
V_1025 = F_2 ( V_84 -> V_4 [ V_1026 ] ) ;
if ( ! V_1025 || ! F_206 ( V_1025 ) ||
V_1025 > V_6 -> V_120 . V_311 )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_277 ||
! ( V_6 -> V_120 . V_35 & V_276 ) )
return - V_397 ;
if ( V_84 -> V_4 [ V_390 ] &&
! F_67 ( V_84 , & V_388 ) )
return - V_11 ;
V_395 = F_2 ( V_84 -> V_4 [ V_396 ] ) ;
V_39 = F_175 ( V_6 , V_395 , V_388 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_1027 ) ;
if ( F_5 ( V_144 ) ) {
V_26 = F_7 ( V_144 ) ;
goto V_483;
}
V_26 = V_6 -> V_210 -> V_277 ( & V_6 -> V_120 , V_8 , V_39 ,
V_388 , V_1025 , & V_472 ) ;
if ( V_26 )
goto V_483;
if ( F_110 ( V_37 , V_1028 , V_472 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
return F_63 ( V_37 , V_84 ) ;
V_42:
V_26 = - V_53 ;
V_483:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_207 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_12 V_472 ;
if ( ! V_84 -> V_4 [ V_1028 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_1029 )
return - V_397 ;
V_472 = F_208 ( V_84 -> V_4 [ V_1028 ] ) ;
return V_6 -> V_210 -> V_1029 ( & V_6 -> V_120 , V_8 , V_472 ) ;
}
static T_2 F_209 ( struct V_979 * V_980 ,
T_1 * V_854 , T_1 V_1030 )
{
T_1 V_119 ;
T_2 V_543 = 0 ;
for ( V_119 = 0 ; V_119 < V_1030 ; V_119 ++ ) {
int V_155 = ( V_854 [ V_119 ] & 0x7f ) * 5 ;
int V_1031 ;
for ( V_1031 = 0 ; V_1031 < V_980 -> V_235 ; V_1031 ++ ) {
struct V_154 * V_1032 =
& V_980 -> V_236 [ V_1031 ] ;
if ( V_155 == V_1032 -> V_238 ) {
V_543 |= 1 << V_1031 ;
break;
}
}
if ( V_1031 == V_980 -> V_235 )
return 0 ;
}
return V_543 ;
}
static bool F_210 ( struct V_979 * V_980 ,
T_1 * V_854 , T_1 V_1030 ,
T_1 V_224 [ V_1033 ] )
{
T_1 V_119 ;
memset ( V_224 , 0 , V_1033 ) ;
for ( V_119 = 0 ; V_119 < V_1030 ; V_119 ++ ) {
int V_1031 , V_1034 ;
V_1031 = V_854 [ V_119 ] / 8 ;
V_1034 = F_106 ( V_854 [ V_119 ] % 8 ) ;
if ( ( V_1031 < 0 ) || ( V_1031 >= V_1033 ) )
return false ;
if ( V_980 -> V_221 . V_224 . V_1035 [ V_1031 ] & V_1034 )
V_224 [ V_1031 ] |= V_1034 ;
else
return false ;
}
return true ;
}
static int F_211 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_3 * V_57 [ V_1036 + 1 ] ;
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_1037 V_543 ;
int V_98 , V_119 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_3 * V_1038 ;
struct V_979 * V_980 ;
if ( V_84 -> V_4 [ V_1039 ] == NULL )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_279 )
return - V_397 ;
memset ( & V_543 , 0 , sizeof( V_543 ) ) ;
for ( V_119 = 0 ; V_119 < V_219 ; V_119 ++ ) {
V_980 = V_6 -> V_120 . V_220 [ V_119 ] ;
V_543 . V_1040 [ V_119 ] . V_1041 =
V_980 ? ( 1 << V_980 -> V_235 ) - 1 : 0 ;
if ( V_980 )
memcpy ( V_543 . V_1040 [ V_119 ] . V_224 ,
V_980 -> V_221 . V_224 . V_1035 ,
sizeof( V_543 . V_1040 [ V_119 ] . V_224 ) ) ;
else
memset ( V_543 . V_1040 [ V_119 ] . V_224 , 0 ,
sizeof( V_543 . V_1040 [ V_119 ] . V_224 ) ) ;
}
F_87 ( V_1042 > V_1033 * 8 ) ;
F_34 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_152 V_153 = F_143 ( V_1038 ) ;
if ( V_153 < 0 || V_153 >= V_219 )
return - V_11 ;
V_980 = V_6 -> V_120 . V_220 [ V_153 ] ;
if ( V_980 == NULL )
return - V_11 ;
F_80 ( V_57 , V_1036 , F_18 ( V_1038 ) ,
F_19 ( V_1038 ) , V_1043 ) ;
if ( V_57 [ V_1044 ] ) {
V_543 . V_1040 [ V_153 ] . V_1041 = F_209 (
V_980 ,
F_18 ( V_57 [ V_1044 ] ) ,
F_19 ( V_57 [ V_1044 ] ) ) ;
if ( ( V_543 . V_1040 [ V_153 ] . V_1041 == 0 ) &&
F_19 ( V_57 [ V_1044 ] ) )
return - V_11 ;
}
if ( V_57 [ V_1045 ] ) {
if ( ! F_210 (
V_980 ,
F_18 ( V_57 [ V_1045 ] ) ,
F_19 ( V_57 [ V_1045 ] ) ,
V_543 . V_1040 [ V_153 ] . V_224 ) )
return - V_11 ;
}
if ( V_543 . V_1040 [ V_153 ] . V_1041 == 0 ) {
if ( ! V_6 -> V_120 . V_220 [ V_153 ] -> V_221 . V_222 )
return - V_11 ;
for ( V_119 = 0 ; V_119 < V_1033 ; V_119 ++ )
if ( V_543 . V_1040 [ V_153 ] . V_224 [ V_119 ] )
break;
if ( V_119 == V_1033 )
return - V_11 ;
}
}
return V_6 -> V_210 -> V_279 ( & V_6 -> V_120 , V_8 , NULL , & V_543 ) ;
}
static int F_212 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_3 V_1046 = V_323 | V_1047 ;
if ( ! V_84 -> V_4 [ V_1048 ] )
return - V_11 ;
if ( V_84 -> V_4 [ V_322 ] )
V_1046 = F_65 ( V_84 -> V_4 [ V_322 ] ) ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_110 &&
V_8 -> V_400 -> V_105 != V_114 &&
V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_107 &&
V_8 -> V_400 -> V_105 != V_109 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_397 ;
if ( ! V_6 -> V_210 -> V_281 )
return - V_397 ;
return F_213 ( V_8 -> V_400 , V_84 -> V_370 ,
V_1046 ,
F_18 ( V_84 -> V_4 [ V_1048 ] ) ,
F_19 ( V_84 -> V_4 [ V_1048 ] ) ) ;
}
static int F_214 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_38 * V_39 ;
enum V_387 V_388 = V_391 ;
bool V_1049 = false ;
T_2 V_395 ;
int V_26 ;
void * V_144 = NULL ;
T_12 V_472 ;
struct V_23 * V_37 = NULL ;
unsigned int V_1050 = 0 ;
bool V_1051 , V_856 , V_1052 ;
V_1052 = V_84 -> V_4 [ V_1053 ] ;
if ( ! V_84 -> V_4 [ V_1054 ] ||
! V_84 -> V_4 [ V_396 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_281 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_110 &&
V_8 -> V_400 -> V_105 != V_114 &&
V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_107 &&
V_8 -> V_400 -> V_105 != V_109 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_397 ;
if ( V_84 -> V_4 [ V_1026 ] ) {
if ( ! ( V_6 -> V_120 . V_35 & V_312 ) )
return - V_11 ;
V_1050 = F_2 ( V_84 -> V_4 [ V_1026 ] ) ;
}
if ( V_84 -> V_4 [ V_390 ] ) {
if ( ! F_67 ( V_84 , & V_388 ) )
return - V_11 ;
V_1049 = true ;
}
V_1051 = V_84 -> V_4 [ V_313 ] ;
if ( V_1051 && ! ( V_6 -> V_120 . V_35 & V_312 ) )
return - V_11 ;
V_856 = F_132 ( V_84 -> V_4 [ V_857 ] ) ;
V_395 = F_2 ( V_84 -> V_4 [ V_396 ] ) ;
V_39 = F_175 ( V_6 , V_395 , V_388 ) ;
if ( V_39 == NULL )
return - V_11 ;
if ( ! V_1052 ) {
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_1055 ) ;
if ( F_5 ( V_144 ) ) {
V_26 = F_7 ( V_144 ) ;
goto V_483;
}
}
V_26 = F_215 ( V_6 , V_8 , V_39 , V_1051 , V_388 ,
V_1049 , V_1050 ,
F_18 ( V_84 -> V_4 [ V_1054 ] ) ,
F_19 ( V_84 -> V_4 [ V_1054 ] ) ,
V_856 , V_1052 , & V_472 ) ;
if ( V_26 )
goto V_483;
if ( V_37 ) {
if ( F_110 ( V_37 , V_1028 , V_472 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
return F_63 ( V_37 , V_84 ) ;
}
return 0 ;
V_42:
V_26 = - V_53 ;
V_483:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_216 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_12 V_472 ;
if ( ! V_84 -> V_4 [ V_1028 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_283 )
return - V_397 ;
if ( V_8 -> V_400 -> V_105 != V_113 &&
V_8 -> V_400 -> V_105 != V_110 &&
V_8 -> V_400 -> V_105 != V_114 &&
V_8 -> V_400 -> V_105 != V_106 &&
V_8 -> V_400 -> V_105 != V_107 &&
V_8 -> V_400 -> V_105 != V_108 )
return - V_397 ;
V_472 = F_208 ( V_84 -> V_4 [ V_1028 ] ) ;
return V_6 -> V_210 -> V_283 ( & V_6 -> V_120 , V_8 , V_472 ) ;
}
static int F_217 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_103 * V_104 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
T_1 V_1056 ;
bool V_1057 ;
int V_26 ;
if ( ! V_84 -> V_4 [ V_1058 ] )
return - V_11 ;
V_1056 = F_2 ( V_84 -> V_4 [ V_1058 ] ) ;
if ( V_1056 != V_1059 && V_1056 != V_1060 )
return - V_11 ;
V_104 = V_8 -> V_400 ;
if ( ! V_6 -> V_210 -> V_1061 )
return - V_397 ;
V_1057 = ( V_1056 == V_1060 ) ? true : false ;
if ( V_1057 == V_104 -> V_1062 )
return 0 ;
V_26 = V_6 -> V_210 -> V_1061 ( V_104 -> V_120 , V_8 , V_1057 ,
V_104 -> V_1063 ) ;
if ( ! V_26 )
V_104 -> V_1062 = V_1057 ;
return V_26 ;
}
static int F_218 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
enum V_1064 V_1056 ;
struct V_103 * V_104 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_23 * V_37 ;
void * V_144 ;
int V_26 ;
V_104 = V_8 -> V_400 ;
if ( ! V_6 -> V_210 -> V_1061 )
return - V_397 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_1065 ) ;
if ( ! V_144 ) {
V_26 = - V_53 ;
goto V_483;
}
if ( V_104 -> V_1062 )
V_1056 = V_1060 ;
else
V_1056 = V_1059 ;
if ( F_23 ( V_37 , V_1058 , V_1056 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
return F_63 ( V_37 , V_84 ) ;
V_42:
V_26 = - V_53 ;
V_483:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_219 ( struct V_83 * V_84 ,
T_13 V_1066 , T_2 V_1067 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_103 * V_104 ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
if ( V_1066 > 0 )
return - V_11 ;
V_104 = V_8 -> V_400 ;
if ( ! V_6 -> V_210 -> V_1068 )
return - V_397 ;
if ( V_104 -> V_105 != V_113 &&
V_104 -> V_105 != V_114 )
return - V_397 ;
return V_6 -> V_210 -> V_1068 ( V_104 -> V_120 , V_8 ,
V_1066 , V_1067 ) ;
}
static int F_220 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_3 * V_4 [ V_1069 + 1 ] ;
struct V_3 * V_1070 ;
int V_26 ;
V_1070 = V_84 -> V_4 [ V_1071 ] ;
if ( ! V_1070 ) {
V_26 = - V_11 ;
goto V_442;
}
V_26 = F_27 ( V_4 , V_1069 , V_1070 ,
V_1072 ) ;
if ( V_26 )
goto V_442;
if ( V_4 [ V_1073 ] &&
V_4 [ V_1074 ] ) {
T_13 V_1066 ;
T_2 V_1067 ;
V_1066 = F_2 ( V_4 [ V_1073 ] ) ;
V_1067 = F_2 ( V_4 [ V_1074 ] ) ;
V_26 = F_219 ( V_84 , V_1066 , V_1067 ) ;
} else
V_26 = - V_11 ;
V_442:
return V_26 ;
}
static int F_221 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_741 V_791 ;
struct V_795 V_796 ;
int V_26 ;
memcpy ( & V_791 , & V_745 , sizeof( V_791 ) ) ;
memcpy ( & V_796 , & V_1075 , sizeof( V_796 ) ) ;
if ( V_84 -> V_4 [ V_747 ] ) {
V_26 = F_129 ( V_84 , & V_791 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_84 -> V_4 [ V_459 ] ||
! F_19 ( V_84 -> V_4 [ V_459 ] ) )
return - V_11 ;
V_796 . V_1076 = F_18 ( V_84 -> V_4 [ V_459 ] ) ;
V_796 . V_744 = F_19 ( V_84 -> V_4 [ V_459 ] ) ;
if ( V_84 -> V_4 [ V_988 ] &&
! F_172 ( V_6 , V_796 . V_976 ,
F_2 ( V_84 -> V_4 [ V_988 ] ) ) )
return - V_11 ;
if ( V_84 -> V_4 [ V_798 ] ) {
V_26 = F_131 ( V_84 , & V_796 ) ;
if ( V_26 )
return V_26 ;
}
return F_222 ( V_6 , V_8 , & V_796 , & V_791 ) ;
}
static int F_223 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
return F_224 ( V_6 , V_8 ) ;
}
static int F_225 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_23 * V_37 ;
void * V_144 ;
if ( ! V_6 -> V_120 . V_326 . V_35 && ! V_6 -> V_120 . V_326 . V_327 )
return - V_397 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_1077 ) ;
if ( ! V_144 )
goto V_42;
if ( V_6 -> V_326 ) {
struct V_3 * V_328 ;
V_328 = F_40 ( V_37 , V_1078 ) ;
if ( ! V_328 )
goto V_42;
if ( ( V_6 -> V_326 -> V_1079 &&
F_24 ( V_37 , V_331 ) ) ||
( V_6 -> V_326 -> V_308 &&
F_24 ( V_37 , V_333 ) ) ||
( V_6 -> V_326 -> V_1080 &&
F_24 ( V_37 , V_335 ) ) ||
( V_6 -> V_326 -> V_1081 &&
F_24 ( V_37 , V_339 ) ) ||
( V_6 -> V_326 -> V_1082 &&
F_24 ( V_37 , V_341 ) ) ||
( V_6 -> V_326 -> V_1083 &&
F_24 ( V_37 , V_343 ) ) ||
( V_6 -> V_326 -> V_1084 &&
F_24 ( V_37 , V_345 ) ) )
goto V_42;
if ( V_6 -> V_326 -> V_327 ) {
struct V_3 * V_1085 , * V_1086 ;
int V_119 , V_1087 ;
V_1085 = F_40 ( V_37 ,
V_353 ) ;
if ( ! V_1085 )
goto V_42;
for ( V_119 = 0 ; V_119 < V_6 -> V_326 -> V_327 ; V_119 ++ ) {
V_1086 = F_40 ( V_37 , V_119 + 1 ) ;
if ( ! V_1086 )
goto V_42;
V_1087 = V_6 -> V_326 -> V_1088 [ V_119 ] . V_1089 ;
if ( F_48 ( V_37 , V_1090 ,
F_226 ( V_1087 , 8 ) ,
V_6 -> V_326 -> V_1088 [ V_119 ] . V_543 ) ||
F_48 ( V_37 , V_1091 ,
V_1087 ,
V_6 -> V_326 -> V_1088 [ V_119 ] . V_1092 ) )
goto V_42;
F_41 ( V_37 , V_1086 ) ;
}
F_41 ( V_37 , V_1085 ) ;
}
F_41 ( V_37 , V_328 ) ;
}
F_51 ( V_37 , V_144 ) ;
return F_63 ( V_37 , V_84 ) ;
V_42:
F_62 ( V_37 ) ;
return - V_53 ;
}
static int F_227 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_3 * V_57 [ V_1093 ] ;
struct V_1094 V_1095 = {} ;
struct V_1094 V_1096 = {} ;
struct V_1097 * V_326 = & V_6 -> V_120 . V_326 ;
int V_26 , V_119 ;
bool V_1098 = V_6 -> V_326 ;
if ( ! V_6 -> V_120 . V_326 . V_35 && ! V_6 -> V_120 . V_326 . V_327 )
return - V_397 ;
if ( ! V_84 -> V_4 [ V_1078 ] )
goto V_1095;
V_26 = F_80 ( V_57 , V_1099 ,
F_18 ( V_84 -> V_4 [ V_1078 ] ) ,
F_19 ( V_84 -> V_4 [ V_1078 ] ) ,
V_1100 ) ;
if ( V_26 )
return V_26 ;
if ( V_57 [ V_331 ] ) {
if ( ! ( V_326 -> V_35 & V_330 ) )
return - V_11 ;
V_1096 . V_1079 = true ;
}
if ( V_57 [ V_333 ] ) {
if ( ! ( V_326 -> V_35 & V_332 ) )
return - V_11 ;
V_1096 . V_308 = true ;
}
if ( V_57 [ V_335 ] ) {
if ( ! ( V_326 -> V_35 & V_334 ) )
return - V_11 ;
V_1096 . V_1080 = true ;
}
if ( V_57 [ V_337 ] )
return - V_11 ;
if ( V_57 [ V_339 ] ) {
if ( ! ( V_326 -> V_35 & V_338 ) )
return - V_11 ;
V_1096 . V_1081 = true ;
}
if ( V_57 [ V_341 ] ) {
if ( ! ( V_326 -> V_35 & V_340 ) )
return - V_11 ;
V_1096 . V_1082 = true ;
}
if ( V_57 [ V_343 ] ) {
if ( ! ( V_326 -> V_35 & V_342 ) )
return - V_11 ;
V_1096 . V_1083 = true ;
}
if ( V_57 [ V_345 ] ) {
if ( ! ( V_326 -> V_35 & V_344 ) )
return - V_11 ;
V_1096 . V_1084 = true ;
}
if ( V_57 [ V_353 ] ) {
struct V_3 * V_347 ;
int V_327 = 0 ;
int V_98 , V_1087 , V_1101 ;
struct V_3 * V_1102 [ V_1103 ] ;
F_34 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_327 ++ ;
if ( V_327 > V_326 -> V_327 )
return - V_11 ;
V_1096 . V_1088 = F_228 ( V_327 ,
sizeof( V_1096 . V_1088 [ 0 ] ) ,
V_99 ) ;
if ( ! V_1096 . V_1088 )
return - V_100 ;
V_1096 . V_327 = V_327 ;
V_119 = 0 ;
F_34 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_80 ( V_1102 , V_1104 ,
F_18 ( V_347 ) , F_19 ( V_347 ) , NULL ) ;
V_26 = - V_11 ;
if ( ! V_1102 [ V_1090 ] ||
! V_1102 [ V_1091 ] )
goto error;
V_1087 = F_19 ( V_1102 [ V_1091 ] ) ;
V_1101 = F_226 ( V_1087 , 8 ) ;
if ( F_19 ( V_1102 [ V_1090 ] ) !=
V_1101 )
goto error;
if ( V_1087 > V_326 -> V_352 ||
V_1087 < V_326 -> V_350 )
goto error;
V_1096 . V_1088 [ V_119 ] . V_543 =
F_229 ( V_1101 + V_1087 , V_99 ) ;
if ( ! V_1096 . V_1088 [ V_119 ] . V_543 ) {
V_26 = - V_100 ;
goto error;
}
V_1096 . V_1088 [ V_119 ] . V_1092 =
V_1096 . V_1088 [ V_119 ] . V_543 + V_1101 ;
memcpy ( V_1096 . V_1088 [ V_119 ] . V_543 ,
F_18 ( V_1102 [ V_1090 ] ) ,
V_1101 ) ;
V_1096 . V_1088 [ V_119 ] . V_1089 = V_1087 ;
memcpy ( V_1096 . V_1088 [ V_119 ] . V_1092 ,
F_18 ( V_1102 [ V_1091 ] ) ,
V_1087 ) ;
V_119 ++ ;
}
}
if ( memcmp ( & V_1096 , & V_1095 , sizeof( V_1096 ) ) ) {
struct V_1094 * V_1105 ;
V_1105 = F_230 ( & V_1096 , sizeof( V_1096 ) ,
V_99 ) ;
if ( ! V_1105 ) {
V_26 = - V_100 ;
goto error;
}
F_231 ( V_6 ) ;
V_6 -> V_326 = V_1105 ;
} else {
V_1095:
F_231 ( V_6 ) ;
V_6 -> V_326 = NULL ;
}
if ( V_6 -> V_210 -> V_1106 && V_1098 != ! ! V_6 -> V_326 )
V_6 -> V_210 -> V_1106 ( & V_6 -> V_120 , V_6 -> V_326 ) ;
return 0 ;
error:
for ( V_119 = 0 ; V_119 < V_1096 . V_327 ; V_119 ++ )
F_36 ( V_1096 . V_1088 [ V_119 ] . V_543 ) ;
F_36 ( V_1096 . V_1088 ) ;
return V_26 ;
}
static int F_232 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_3 * V_57 [ V_1107 ] ;
struct V_1108 V_1109 ;
int V_26 ;
if ( ! V_84 -> V_4 [ V_1110 ] )
return - V_11 ;
V_26 = F_80 ( V_57 , V_1111 ,
F_18 ( V_84 -> V_4 [ V_1110 ] ) ,
F_19 ( V_84 -> V_4 [ V_1110 ] ) ,
V_1112 ) ;
if ( V_26 )
return V_26 ;
if ( F_19 ( V_57 [ V_1113 ] ) != V_1114 )
return - V_1115 ;
if ( F_19 ( V_57 [ V_1116 ] ) != V_1117 )
return - V_1115 ;
if ( F_19 ( V_57 [ V_1118 ] ) != V_1119 )
return - V_1115 ;
memcpy ( V_1109 . V_1120 , F_18 ( V_57 [ V_1116 ] ) ,
V_1117 ) ;
memcpy ( V_1109 . V_1121 , F_18 ( V_57 [ V_1118 ] ) ,
V_1119 ) ;
memcpy ( V_1109 . V_1122 ,
F_18 ( V_57 [ V_1113 ] ) ,
V_1114 ) ;
F_69 ( V_104 ) ;
if ( ! V_104 -> V_111 ) {
V_26 = - V_1123 ;
goto V_442;
}
if ( ! V_6 -> V_210 -> V_1124 ) {
V_26 = - V_397 ;
goto V_442;
}
V_26 = V_6 -> V_210 -> V_1124 ( & V_6 -> V_120 , V_8 , & V_1109 ) ;
V_442:
F_71 ( V_104 ) ;
return V_26 ;
}
static int F_233 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
if ( V_104 -> V_105 != V_106 &&
V_104 -> V_105 != V_108 )
return - V_11 ;
if ( V_104 -> V_1125 )
return - V_403 ;
V_104 -> V_1125 = V_84 -> V_370 ;
return 0 ;
}
static int F_234 ( struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
struct V_7 * V_8 = V_84 -> V_368 [ 1 ] ;
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_23 * V_37 ;
void * V_144 ;
const T_1 * V_1126 ;
T_12 V_472 ;
int V_26 ;
if ( V_104 -> V_105 != V_106 &&
V_104 -> V_105 != V_108 )
return - V_397 ;
if ( ! V_84 -> V_4 [ V_402 ] )
return - V_11 ;
if ( ! V_6 -> V_210 -> V_298 )
return - V_397 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , V_84 -> V_370 , V_84 -> V_371 , 0 ,
V_1127 ) ;
if ( F_5 ( V_144 ) ) {
V_26 = F_7 ( V_144 ) ;
goto V_483;
}
V_1126 = F_18 ( V_84 -> V_4 [ V_402 ] ) ;
V_26 = V_6 -> V_210 -> V_298 ( & V_6 -> V_120 , V_8 , V_1126 , & V_472 ) ;
if ( V_26 )
goto V_483;
if ( F_110 ( V_37 , V_1028 , V_472 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
return F_63 ( V_37 , V_84 ) ;
V_42:
V_26 = - V_53 ;
V_483:
F_62 ( V_37 ) ;
return V_26 ;
}
static int F_235 ( struct V_23 * V_24 , struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_368 [ 0 ] ;
if ( ! ( V_6 -> V_120 . V_35 & V_302 ) )
return - V_397 ;
if ( V_6 -> V_1128 )
return - V_403 ;
V_6 -> V_1128 = V_84 -> V_370 ;
return 0 ;
}
static int F_236 ( struct V_1129 * V_210 , struct V_23 * V_24 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_26 ;
bool V_1130 = V_210 -> V_1131 & V_1132 ;
if ( V_1130 )
F_11 () ;
if ( V_210 -> V_1131 & V_1133 ) {
V_6 = F_237 ( V_84 ) ;
if ( F_5 ( V_6 ) ) {
if ( V_1130 )
F_14 () ;
return F_7 ( V_6 ) ;
}
V_84 -> V_368 [ 0 ] = V_6 ;
} else if ( V_210 -> V_1131 & V_1134 ) {
V_26 = F_1 ( F_76 ( V_84 ) , V_84 -> V_4 ,
& V_6 , & V_8 ) ;
if ( V_26 ) {
if ( V_1130 )
F_14 () ;
return V_26 ;
}
if ( V_210 -> V_1131 & V_1135 &&
! F_74 ( V_8 ) ) {
F_16 ( V_6 ) ;
F_6 ( V_8 ) ;
if ( V_1130 )
F_14 () ;
return - V_412 ;
}
V_84 -> V_368 [ 0 ] = V_6 ;
V_84 -> V_368 [ 1 ] = V_8 ;
}
return 0 ;
}
static void F_238 ( struct V_1129 * V_210 , struct V_23 * V_24 ,
struct V_83 * V_84 )
{
if ( V_84 -> V_368 [ 0 ] )
F_16 ( V_84 -> V_368 [ 0 ] ) ;
if ( V_84 -> V_368 [ 1 ] )
F_6 ( V_84 -> V_368 [ 1 ] ) ;
if ( V_210 -> V_1131 & V_1132 )
F_14 () ;
}
void F_239 ( struct V_5 * V_6 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return;
if ( F_43 ( V_37 , 0 , 0 , 0 , V_6 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1136 . V_1001 , V_99 ) ;
}
static int F_241 ( struct V_23 * V_37 ,
struct V_5 * V_6 )
{
struct V_845 * V_1137 = V_6 -> V_849 ;
struct V_3 * V_1138 ;
int V_119 ;
F_242 ( V_6 ) ;
if ( F_187 ( ! V_1137 ) )
return 0 ;
V_1138 = F_40 ( V_37 , V_851 ) ;
if ( ! V_1138 )
goto V_42;
for ( V_119 = 0 ; V_119 < V_1137 -> V_847 ; V_119 ++ ) {
if ( F_48 ( V_37 , V_119 , V_1137 -> V_852 [ V_119 ] . V_519 , V_1137 -> V_852 [ V_119 ] . V_463 ) )
goto V_42;
}
F_41 ( V_37 , V_1138 ) ;
V_1138 = F_40 ( V_37 , V_850 ) ;
if ( ! V_1138 )
goto V_42;
for ( V_119 = 0 ; V_119 < V_1137 -> V_232 ; V_119 ++ ) {
if ( F_23 ( V_37 , V_119 , V_1137 -> V_233 [ V_119 ] -> V_41 ) )
goto V_42;
}
F_41 ( V_37 , V_1138 ) ;
if ( V_1137 -> V_814 &&
F_48 ( V_37 , V_494 , V_1137 -> V_815 , V_1137 -> V_814 ) )
goto V_42;
return 0 ;
V_42:
return - V_53 ;
}
static int F_243 ( struct V_23 * V_37 ,
struct V_5 * V_6 ,
struct V_7 * V_399 ,
T_2 V_33 , T_2 V_34 , int V_35 ,
T_2 V_36 )
{
void * V_144 ;
V_144 = F_20 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_144 )
return - 1 ;
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) )
goto V_42;
F_241 ( V_37 , V_6 ) ;
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
static int
F_244 ( struct V_23 * V_37 ,
struct V_5 * V_6 ,
struct V_7 * V_399 ,
T_2 V_33 , T_2 V_34 , int V_35 , T_2 V_36 )
{
void * V_144 ;
V_144 = F_20 ( V_37 , V_33 , V_34 , V_35 , V_36 ) ;
if ( ! V_144 )
return - 1 ;
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) )
goto V_42;
return F_51 ( V_37 , V_144 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
return - V_363 ;
}
void F_145 ( struct V_5 * V_6 ,
struct V_7 * V_399 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1139 , V_99 ) ;
if ( ! V_37 )
return;
if ( F_243 ( V_37 , V_6 , V_399 , 0 , 0 , 0 ,
V_1140 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1141 . V_1001 , V_99 ) ;
}
void F_245 ( struct V_5 * V_6 ,
struct V_7 * V_399 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return;
if ( F_243 ( V_37 , V_6 , V_399 , 0 , 0 , 0 ,
V_876 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1141 . V_1001 , V_99 ) ;
}
void F_246 ( struct V_5 * V_6 ,
struct V_7 * V_399 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return;
if ( F_243 ( V_37 , V_6 , V_399 , 0 , 0 , 0 ,
V_1142 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1141 . V_1001 , V_99 ) ;
}
void F_247 ( struct V_5 * V_6 ,
struct V_7 * V_399 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return;
if ( F_244 ( V_37 , V_6 , V_399 , 0 , 0 , 0 ,
V_1143 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1141 . V_1001 , V_99 ) ;
}
void F_148 ( struct V_5 * V_6 ,
struct V_7 * V_399 , T_2 V_36 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1139 , V_99 ) ;
if ( ! V_37 )
return;
if ( F_244 ( V_37 , V_6 , V_399 , 0 , 0 , 0 , V_36 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1141 . V_1001 , V_99 ) ;
}
void F_248 ( struct V_1144 * V_846 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_99 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1145 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_46 ( V_37 , V_1146 , V_846 -> V_1147 ) )
goto V_42;
if ( V_846 -> V_823 [ 0 ] == '0' && V_846 -> V_823 [ 1 ] == '0' ) {
if ( F_46 ( V_37 , V_1148 ,
V_1149 ) )
goto V_42;
} else if ( V_846 -> V_823 [ 0 ] == '9' && V_846 -> V_823 [ 1 ] == '9' ) {
if ( F_46 ( V_37 , V_1148 ,
V_1150 ) )
goto V_42;
} else if ( ( V_846 -> V_823 [ 0 ] == '9' && V_846 -> V_823 [ 1 ] == '8' ) ||
V_846 -> V_1151 ) {
if ( F_46 ( V_37 , V_1148 ,
V_1152 ) )
goto V_42;
} else {
if ( F_46 ( V_37 , V_1148 ,
V_1153 ) ||
F_44 ( V_37 , V_740 ,
V_846 -> V_823 ) )
goto V_42;
}
if ( F_249 ( V_846 -> V_160 ) &&
F_23 ( V_37 , V_159 , V_846 -> V_160 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_250 () ;
F_251 ( V_37 , 0 , V_1154 . V_1001 ,
V_1155 ) ;
F_252 () ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
static void F_253 ( struct V_5 * V_6 ,
struct V_7 * V_399 ,
const T_1 * V_1156 , T_10 V_31 ,
enum V_1157 V_36 , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_48 ( V_37 , V_1054 , V_31 , V_1156 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_254 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1156 ,
T_10 V_31 , T_11 V_999 )
{
F_253 ( V_6 , V_399 , V_1156 , V_31 ,
V_1159 , V_999 ) ;
}
void F_255 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1156 ,
T_10 V_31 , T_11 V_999 )
{
F_253 ( V_6 , V_399 , V_1156 , V_31 ,
V_1160 , V_999 ) ;
}
void F_256 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1156 ,
T_10 V_31 , T_11 V_999 )
{
F_253 ( V_6 , V_399 , V_1156 , V_31 ,
V_1161 , V_999 ) ;
}
void F_257 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1156 ,
T_10 V_31 , T_11 V_999 )
{
F_253 ( V_6 , V_399 , V_1156 , V_31 ,
V_1162 , V_999 ) ;
}
void F_258 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1156 ,
T_10 V_31 , T_11 V_999 )
{
F_253 ( V_6 , V_399 , V_1156 , V_31 ,
V_1163 , V_999 ) ;
}
void F_259 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1156 ,
T_10 V_31 , T_11 V_999 )
{
F_253 ( V_6 , V_399 , V_1156 , V_31 ,
V_1164 , V_999 ) ;
}
static void F_260 ( struct V_5 * V_6 ,
struct V_7 * V_399 , int V_36 ,
const T_1 * V_1126 , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_24 ( V_37 , V_1165 ) ||
F_48 ( V_37 , V_402 , V_481 , V_1126 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_261 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1126 ,
T_11 V_999 )
{
F_260 ( V_6 , V_399 , V_1159 ,
V_1126 , V_999 ) ;
}
void F_262 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1126 ,
T_11 V_999 )
{
F_260 ( V_6 , V_399 , V_1160 ,
V_1126 , V_999 ) ;
}
void F_263 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_401 ,
const T_1 * V_1166 , T_10 V_1167 ,
const T_1 * V_1168 , T_10 V_1169 ,
T_3 V_1170 , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_307 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
( V_401 && F_48 ( V_37 , V_402 , V_481 , V_401 ) ) ||
F_47 ( V_37 , V_1020 , V_1170 ) ||
( V_1166 &&
F_48 ( V_37 , V_1171 , V_1167 , V_1166 ) ) ||
( V_1168 &&
F_48 ( V_37 , V_1172 , V_1169 , V_1168 ) ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_264 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_401 ,
const T_1 * V_1166 , T_10 V_1167 ,
const T_1 * V_1168 , T_10 V_1169 , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1173 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_401 ) ||
( V_1166 &&
F_48 ( V_37 , V_1171 , V_1167 , V_1166 ) ) ||
( V_1168 &&
F_48 ( V_37 , V_1172 , V_1169 , V_1168 ) ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_265 ( struct V_5 * V_6 ,
struct V_7 * V_399 , T_3 V_1005 ,
const T_1 * V_814 , T_10 V_815 , bool V_1174 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_99 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_309 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
( V_1174 && V_1005 &&
F_47 ( V_37 , V_975 , V_1005 ) ) ||
( V_1174 &&
F_24 ( V_37 , V_1175 ) ) ||
( V_814 && F_48 ( V_37 , V_494 , V_815 , V_814 ) ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_99 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_266 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_401 ,
T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1176 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_401 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_267 ( struct V_5 * V_6 ,
struct V_7 * V_399 ,
const T_1 * V_1177 , const T_1 * V_814 , T_1 V_815 ,
T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1178 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_1177 ) ||
( V_815 && V_814 &&
F_48 ( V_37 , V_494 , V_815 , V_814 ) ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_268 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1126 ,
enum V_1179 V_1180 , int V_1181 ,
const T_1 * V_1182 , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1183 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
( V_1126 && F_48 ( V_37 , V_402 , V_481 , V_1126 ) ) ||
F_23 ( V_37 , V_91 , V_1180 ) ||
( V_1181 != - 1 &&
F_46 ( V_37 , V_87 , V_1181 ) ) ||
( V_1182 && F_48 ( V_37 , V_86 , 6 , V_1182 ) ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_269 ( struct V_120 * V_120 ,
struct V_38 * V_1184 ,
struct V_38 * V_1185 )
{
struct V_23 * V_37 ;
void * V_144 ;
struct V_3 * V_148 ;
V_37 = F_61 ( V_369 , V_1155 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1186 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , F_270 ( V_120 ) ) )
goto V_42;
V_148 = F_40 ( V_37 , V_1187 ) ;
if ( ! V_148 )
goto V_42;
if ( F_22 ( V_37 , V_1184 ) )
goto V_42;
F_41 ( V_37 , V_148 ) ;
V_148 = F_40 ( V_37 , V_1188 ) ;
if ( ! V_148 )
goto V_42;
if ( F_22 ( V_37 , V_1185 ) )
goto V_42;
F_41 ( V_37 , V_148 ) ;
F_51 ( V_37 , V_144 ) ;
F_250 () ;
F_251 ( V_37 , 0 , V_1154 . V_1001 ,
V_1155 ) ;
F_252 () ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
static void F_271 (
int V_36 , struct V_5 * V_6 ,
struct V_7 * V_399 , T_12 V_472 ,
struct V_38 * V_39 ,
enum V_387 V_388 ,
unsigned int V_1025 , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_23 ( V_37 , V_396 , V_39 -> V_41 ) ||
F_23 ( V_37 , V_390 , V_388 ) ||
F_110 ( V_37 , V_1028 , V_472 ) )
goto V_42;
if ( V_36 == V_1027 &&
F_23 ( V_37 , V_1026 , V_1025 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_272 ( struct V_5 * V_6 ,
struct V_7 * V_399 , T_12 V_472 ,
struct V_38 * V_39 ,
enum V_387 V_388 ,
unsigned int V_1025 , T_11 V_999 )
{
F_271 ( V_1027 ,
V_6 , V_399 , V_472 , V_39 ,
V_388 , V_1025 , V_999 ) ;
}
void F_273 (
struct V_5 * V_6 , struct V_7 * V_399 ,
T_12 V_472 , struct V_38 * V_39 ,
enum V_387 V_388 , T_11 V_999 )
{
F_271 ( V_1189 ,
V_6 , V_399 , V_472 , V_39 ,
V_388 , 0 , V_999 ) ;
}
void F_274 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const T_1 * V_474 ,
struct V_564 * V_565 , T_11 V_999 )
{
struct V_23 * V_37 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
if ( F_109 ( V_37 , 0 , 0 , 0 ,
V_6 , V_8 , V_474 , V_565 ) < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
}
void F_275 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const T_1 * V_474 ,
T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1190 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_474 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
static bool F_276 ( struct V_7 * V_8 , T_1 V_36 ,
const T_1 * V_1126 , T_11 V_999 )
{
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_5 * V_6 = F_77 ( V_104 -> V_120 ) ;
struct V_23 * V_37 ;
void * V_144 ;
int V_26 ;
T_2 V_1191 = F_277 ( V_104 -> V_1125 ) ;
if ( ! V_1191 )
return false ;
V_37 = F_61 ( 100 , V_999 ) ;
if ( ! V_37 )
return true ;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_36 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return true ;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_1126 ) )
goto V_42;
V_26 = F_51 ( V_37 , V_144 ) ;
if ( V_26 < 0 ) {
F_62 ( V_37 ) ;
return true ;
}
F_278 ( F_57 ( & V_6 -> V_120 ) , V_37 , V_1191 ) ;
return true ;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
return true ;
}
bool F_279 ( struct V_7 * V_8 , const T_1 * V_1126 , T_11 V_999 )
{
return F_276 ( V_8 , V_1192 ,
V_1126 , V_999 ) ;
}
bool F_280 ( struct V_7 * V_8 ,
const T_1 * V_1126 , T_11 V_999 )
{
return F_276 ( V_8 ,
V_1193 ,
V_1126 , V_999 ) ;
}
int F_281 ( struct V_5 * V_6 ,
struct V_7 * V_399 , T_2 V_1191 ,
int V_395 , int V_1194 ,
const T_1 * V_1156 , T_10 V_31 , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return - V_100 ;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1055 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return - V_100 ;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_23 ( V_37 , V_396 , V_395 ) ||
( V_1194 &&
F_23 ( V_37 , V_1195 , V_1194 ) ) ||
F_48 ( V_37 , V_1054 , V_31 , V_1156 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
return F_278 ( F_57 ( & V_6 -> V_120 ) , V_37 , V_1191 ) ;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
return - V_53 ;
}
void F_282 ( struct V_5 * V_6 ,
struct V_7 * V_399 , T_12 V_472 ,
const T_1 * V_1156 , T_10 V_31 , bool V_1196 ,
T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_369 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1197 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_48 ( V_37 , V_1054 , V_31 , V_1156 ) ||
F_110 ( V_37 , V_1028 , V_472 ) ||
( V_1196 && F_24 ( V_37 , V_1198 ) ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_191 ( V_37 , 0 , V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void
F_283 ( struct V_5 * V_6 ,
struct V_7 * V_399 ,
enum V_1199 V_1200 ,
T_11 V_999 )
{
struct V_23 * V_37 ;
struct V_3 * V_678 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1201 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) )
goto V_42;
V_678 = F_40 ( V_37 , V_1071 ) ;
if ( ! V_678 )
goto V_42;
if ( F_23 ( V_37 , V_1202 ,
V_1200 ) )
goto V_42;
F_41 ( V_37 , V_678 ) ;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_284 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_401 ,
const T_1 * V_1122 , T_11 V_999 )
{
struct V_23 * V_37 ;
struct V_3 * V_1203 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1204 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_401 ) )
goto V_42;
V_1203 = F_40 ( V_37 , V_1110 ) ;
if ( ! V_1203 )
goto V_42;
if ( F_48 ( V_37 , V_1113 ,
V_1114 , V_1122 ) )
goto V_42;
F_41 ( V_37 , V_1203 ) ;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_285 ( struct V_5 * V_6 ,
struct V_7 * V_399 , int V_1205 ,
const T_1 * V_401 , bool V_1206 , T_11 V_999 )
{
struct V_23 * V_37 ;
struct V_3 * V_29 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1207 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) )
goto V_42;
V_29 = F_40 ( V_37 , V_1208 ) ;
if ( ! V_29 )
goto V_42;
if ( F_23 ( V_37 , V_1209 , V_1205 ) ||
F_48 ( V_37 , V_1210 , V_481 , V_401 ) ||
( V_1206 &&
F_24 ( V_37 , V_1211 ) ) )
goto V_42;
F_41 ( V_37 , V_29 ) ;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_286 ( struct V_5 * V_6 ,
struct V_7 * V_399 , int V_395 ,
enum V_387 type , T_11 V_999 )
{
struct V_23 * V_37 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1212 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_23 ( V_37 , V_396 , V_395 ) ||
F_23 ( V_37 , V_390 , type ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void
F_287 ( struct V_5 * V_6 ,
struct V_7 * V_399 , const T_1 * V_1018 ,
T_2 V_1213 , T_11 V_999 )
{
struct V_23 * V_37 ;
struct V_3 * V_678 ;
void * V_144 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1201 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_399 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_1018 ) )
goto V_42;
V_678 = F_40 ( V_37 , V_1071 ) ;
if ( ! V_678 )
goto V_42;
if ( F_23 ( V_37 , V_1214 , V_1213 ) )
goto V_42;
F_41 ( V_37 , V_678 ) ;
F_51 ( V_37 , V_144 ) ;
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_288 ( struct V_7 * V_8 , const T_1 * V_1126 ,
T_12 V_472 , bool V_1215 , T_11 V_999 )
{
struct V_103 * V_104 = V_8 -> V_400 ;
struct V_5 * V_6 = F_77 ( V_104 -> V_120 ) ;
struct V_23 * V_37 ;
void * V_144 ;
int V_26 ;
V_37 = F_61 ( V_1139 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1127 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
F_23 ( V_37 , V_10 , V_8 -> V_9 ) ||
F_48 ( V_37 , V_402 , V_481 , V_1126 ) ||
F_110 ( V_37 , V_1028 , V_472 ) ||
( V_1215 && F_24 ( V_37 , V_1198 ) ) )
goto V_42;
V_26 = F_51 ( V_37 , V_144 ) ;
if ( V_26 < 0 ) {
F_62 ( V_37 ) ;
return;
}
F_240 ( F_57 ( & V_6 -> V_120 ) , V_37 , 0 ,
V_1158 . V_1001 , V_999 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
void F_289 ( struct V_120 * V_120 ,
const T_1 * V_1216 , T_10 V_31 ,
int V_395 , int V_1194 , T_11 V_999 )
{
struct V_5 * V_6 = F_77 ( V_120 ) ;
struct V_23 * V_37 ;
void * V_144 ;
T_2 V_1191 = F_277 ( V_6 -> V_1128 ) ;
if ( ! V_1191 )
return;
V_37 = F_61 ( V_31 + 100 , V_999 ) ;
if ( ! V_37 )
return;
V_144 = F_20 ( V_37 , 0 , 0 , 0 , V_1055 ) ;
if ( ! V_144 ) {
F_62 ( V_37 ) ;
return;
}
if ( F_23 ( V_37 , V_159 , V_6 -> V_160 ) ||
( V_395 &&
F_23 ( V_37 , V_396 , V_395 ) ) ||
( V_1194 &&
F_23 ( V_37 , V_1195 , V_1194 ) ) ||
F_48 ( V_37 , V_1054 , V_31 , V_1216 ) )
goto V_42;
F_51 ( V_37 , V_144 ) ;
F_278 ( F_57 ( & V_6 -> V_120 ) , V_37 , V_1191 ) ;
return;
V_42:
F_52 ( V_37 , V_144 ) ;
F_62 ( V_37 ) ;
}
static int F_290 ( struct V_1217 * V_1218 ,
unsigned long V_1057 ,
void * V_1219 )
{
struct V_1220 * V_1221 = V_1219 ;
struct V_5 * V_6 ;
struct V_103 * V_104 ;
if ( V_1057 != V_1222 )
return V_1223 ;
F_250 () ;
F_291 (rdev, &cfg80211_rdev_list, list) {
F_291 (wdev, &rdev->netdev_list, list)
F_292 ( V_104 , V_1221 -> V_33 ) ;
if ( V_6 -> V_1128 == V_1221 -> V_33 )
V_6 -> V_1128 = 0 ;
}
F_252 () ;
return V_1223 ;
}
int F_293 ( void )
{
int V_26 ;
V_26 = F_294 ( & V_18 ,
V_1224 , F_295 ( V_1224 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_296 ( & V_18 , & V_1136 ) ;
if ( V_26 )
goto V_1225;
V_26 = F_296 ( & V_18 , & V_1141 ) ;
if ( V_26 )
goto V_1225;
V_26 = F_296 ( & V_18 , & V_1154 ) ;
if ( V_26 )
goto V_1225;
V_26 = F_296 ( & V_18 , & V_1158 ) ;
if ( V_26 )
goto V_1225;
#ifdef F_50
V_26 = F_296 ( & V_18 , & V_1000 ) ;
if ( V_26 )
goto V_1225;
#endif
V_26 = F_297 ( & V_1226 ) ;
if ( V_26 )
goto V_1225;
return 0 ;
V_1225:
F_298 ( & V_18 ) ;
return V_26 ;
}
void F_299 ( void )
{
F_300 ( & V_1226 ) ;
F_298 ( & V_18 ) ;
}
