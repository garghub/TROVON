static inline bool F_1 ( void ) { return false ; }
void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_6 == NULL )
goto V_7;
if ( F_3 ( V_4 ) )
F_4 ( V_4 , false ) ;
if ( F_5 ( V_2 ) ) {
F_6 ( V_2 -> V_2 ) ;
F_7 ( V_2 -> V_2 ) ;
}
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
V_7:
F_11 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_12 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
V_4 = F_13 ( sizeof( struct V_3 ) , V_11 ) ;
if ( V_4 == NULL ) {
return - V_12 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( ( V_13 != 0 ) &&
F_1 () &&
( F_14 () ||
F_15 () ) &&
( ( V_8 & V_14 ) == 0 ) )
V_8 |= V_15 ;
V_9 = F_16 ( V_4 , V_2 , V_2 -> V_16 , V_8 ) ;
if ( V_9 ) {
F_17 ( & V_2 -> V_16 -> V_2 , L_1 ) ;
goto V_17;
}
if ( ! V_9 ) {
V_10 = F_18 ( V_4 ) ;
if ( V_10 )
F_19 ( & V_2 -> V_16 -> V_2 ,
L_2 ) ;
}
F_20 ( V_4 ) ;
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_5 ( V_2 ) ) {
F_23 ( V_2 -> V_2 ) ;
F_24 ( V_2 -> V_2 , 5000 ) ;
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_2 -> V_2 ) ;
F_27 ( V_2 -> V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
}
if ( F_3 ( V_4 ) )
F_29 ( V_4 , true ) ;
V_17:
if ( V_9 ) {
if ( V_4 -> V_6 && F_5 ( V_2 ) )
F_30 ( V_2 -> V_2 ) ;
F_2 ( V_2 ) ;
}
return V_9 ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_3 * V_4 )
{
switch ( V_21 -> V_22 ) {
case V_23 :
V_19 -> V_24 = V_4 -> V_25 . V_26 ;
V_19 -> V_27 = V_4 -> V_25 . V_28 ;
break;
case V_29 :
V_19 -> V_24 = V_4 -> V_30 . V_26 ;
V_19 -> V_27 = 0 ;
break;
case V_31 :
V_19 -> V_24 = V_4 -> V_32 . V_26 ;
V_19 -> V_27 = 0 ;
break;
case V_33 :
V_19 -> V_24 = V_4 -> V_34 . V_35 ;
V_19 -> V_27 = V_4 -> V_34 . V_36 ;
break;
case V_37 :
V_19 -> V_24 = V_4 -> V_34 . V_38 ;
V_19 -> V_27 = V_4 -> V_34 . V_39 ;
break;
case V_40 :
V_19 -> V_24 = V_4 -> V_34 . V_41 ;
V_19 -> V_27 = V_4 -> V_34 . V_42 ;
break;
case V_43 :
V_19 -> V_24 = V_4 -> V_34 . V_44 ;
V_19 -> V_27 = V_4 -> V_34 . V_45 ;
break;
case V_46 :
if ( V_21 -> V_47 == 0 ) {
V_19 -> V_24 = V_4 -> V_34 . V_48 ;
V_19 -> V_27 = V_4 -> V_34 . V_49 ;
} else if ( V_21 -> V_47 == 1 ) {
V_19 -> V_24 = V_4 -> V_34 . V_50 ;
V_19 -> V_27 = V_4 -> V_34 . V_51 ;
} else
return - V_52 ;
break;
case V_53 :
V_19 -> V_24 = V_4 -> V_54 . V_26 ;
V_19 -> V_27 = 0 ;
break;
case V_55 :
if ( V_21 -> V_47 >= V_4 -> V_56 . V_57 )
return - V_52 ;
V_19 -> V_24 = V_4 -> V_56 . V_58 [ V_21 -> V_47 ] . V_26 ;
V_19 -> V_27 = V_4 -> V_56 . V_58 [ V_21 -> V_47 ] . V_59 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , void * V_60 , struct V_61 * V_62 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_63 * V_64 = V_60 ;
struct V_65 * V_66 = & V_4 -> V_67 ;
void T_1 * V_17 = ( void T_1 * ) ( long ) V_64 -> V_68 ;
T_2 V_69 = V_64 -> V_70 ;
struct V_71 * V_72 ;
T_2 V_73 = 0 ;
T_3 V_74 = 0 ;
int V_75 , V_76 ;
if ( ! V_64 -> V_70 || ! V_64 -> V_68 )
return - V_52 ;
switch ( V_64 -> V_77 ) {
case V_78 :
V_73 = V_4 -> V_79 ;
return F_33 ( V_17 , & V_73 , F_34 ( V_69 , 4u ) ) ? - V_80 : 0 ;
case V_81 :
for ( V_75 = 0 , V_76 = 0 ; V_75 < V_4 -> V_67 . V_82 ; V_75 ++ ) {
V_72 = (struct V_71 * ) V_66 -> V_83 [ V_75 ] ;
if ( V_72 && V_72 -> V_84 . V_85 == V_64 -> V_86 . V_85 ) {
struct V_87 * V_87 = F_35 ( V_72 ) ;
V_73 = V_87 -> V_88 ;
V_76 = 1 ;
break;
}
}
if ( ! V_76 ) {
F_36 ( L_3 , V_64 -> V_86 . V_85 ) ;
return - V_52 ;
}
return F_33 ( V_17 , & V_73 , F_34 ( V_69 , 4u ) ) ? - V_80 : 0 ;
case V_89 : {
struct V_90 V_91 = {} ;
enum V_92 type ;
T_2 V_93 = 0 ;
T_2 V_94 = 0 ;
T_2 V_95 = 0 ;
if ( V_64 -> V_96 . V_97 >= V_98 )
return - V_52 ;
switch ( V_64 -> V_96 . type ) {
case V_99 :
type = V_100 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_34 . V_101 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_34 . V_102 [ V_75 ] . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 8 ;
break;
case V_105 :
type = V_100 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_34 . V_106 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_34 . V_107 [ V_75 ] . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 8 ;
break;
case V_108 :
type = V_109 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_56 . V_57 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_56 . V_58 [ V_75 ] . V_110 . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 1 ;
break;
case V_111 :
type = V_112 ;
V_93 = V_4 -> V_30 . V_110 . V_103 ? 1 : 0 ;
V_94 = V_104 ;
V_95 = 16 ;
break;
case V_113 :
type = V_114 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_25 . V_115 ; V_75 ++ )
V_93 |= ( ( V_4 -> V_25 . V_110 [ V_75 ] . V_103 ? 1 : 0 ) << V_75 ) ;
V_94 = V_104 ;
V_95 = 1 ;
break;
default:
return - V_52 ;
}
for ( V_75 = 0 ; V_75 < V_4 -> V_116 ; V_75 ++ ) {
if ( V_4 -> V_117 [ V_75 ] . V_118 -> type == type &&
V_4 -> V_117 [ V_75 ] . V_119 . V_120 ) {
V_91 . V_121 = V_4 -> V_117 [ V_75 ] . V_118 -> V_122 ;
V_91 . V_123 = V_4 -> V_117 [ V_75 ] . V_118 -> V_124 ;
V_91 . V_125 = 0 ;
V_91 . V_126 = V_93 ;
V_91 . V_94 = V_94 ;
V_91 . V_95 = V_95 ;
break;
}
}
return F_33 ( V_17 , & V_91 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_91 ) ) ) ? - V_80 : 0 ;
}
case V_128 : {
enum V_92 type ;
T_2 V_129 = 0 ;
switch ( V_64 -> V_96 . type ) {
case V_99 :
type = V_100 ;
break;
case V_105 :
type = V_100 ;
break;
case V_108 :
type = V_109 ;
break;
case V_111 :
type = V_112 ;
break;
case V_113 :
type = V_114 ;
break;
default:
return - V_52 ;
}
for ( V_75 = 0 ; V_75 < V_4 -> V_116 ; V_75 ++ )
if ( V_4 -> V_117 [ V_75 ] . V_118 -> type == type &&
V_4 -> V_117 [ V_75 ] . V_119 . V_120 &&
V_129 < V_98 )
V_129 ++ ;
return F_33 ( V_17 , & V_129 , F_34 ( V_69 , 4u ) ) ? - V_80 : 0 ;
}
case V_130 :
V_74 = F_37 ( V_4 ) ;
return F_33 ( V_17 , & V_74 , F_34 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_131 : {
struct V_18 V_19 ;
int V_132 ;
if ( V_64 -> V_21 . V_97 != 0 )
return - V_52 ;
V_132 = F_31 ( & V_19 , & V_64 -> V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
return F_33 ( V_17 , & V_19 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_19 ) ) ) ? - V_80 : 0 ;
}
case V_133 :
V_74 = F_38 ( & V_4 -> V_134 ) ;
return F_33 ( V_17 , & V_74 , F_34 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_135 :
V_74 = F_38 ( & V_4 -> V_136 ) ;
return F_33 ( V_17 , & V_74 , F_34 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_137 :
V_74 = F_38 ( & V_4 -> V_138 ) ;
return F_33 ( V_17 , & V_74 , F_34 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_139 :
V_74 = F_38 ( & V_4 -> V_140 ) ;
return F_33 ( V_17 , & V_74 , F_34 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_141 :
V_74 = F_38 ( & V_4 -> V_142 ) ;
return F_33 ( V_17 , & V_74 , F_34 ( V_69 , 8u ) ) ? - V_80 : 0 ;
case V_143 : {
struct V_144 V_145 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_146 = V_4 -> V_147 . V_148 . V_149 >> V_150 ;
V_145 . V_151 = V_4 -> V_147 . V_148 . V_152 >> V_150 ;
V_145 . V_153 = V_4 -> V_147 . V_148 . V_154 >> V_150 ;
V_145 . V_155 = V_4 -> V_147 . V_156 . V_149 >> V_157 ;
V_145 . V_158 = V_4 -> V_147 . V_156 . V_152 >> V_157 ;
V_145 . V_159 = V_4 -> V_147 . V_160 . V_149 >> V_161 ;
V_145 . V_162 = V_4 -> V_147 . V_160 . V_152 >> V_161 ;
return F_33 ( V_17 , & V_145 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_145 ) ) ) ? - V_80 : 0 ;
}
case V_163 : {
struct V_164 V_165 ;
V_165 . V_166 = V_4 -> V_32 . V_167 ;
V_165 . V_166 -= V_4 -> V_168 ;
V_165 . V_169 = V_4 -> V_32 . V_170 ;
V_165 . V_169 -= ( V_4 -> V_168 - V_4 -> V_171 ) ;
V_165 . V_172 = V_4 -> V_32 . V_172 ;
V_165 . V_172 -= V_4 -> V_173 ;
return F_33 ( V_17 , & V_165 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_165 ) ) ) ? - V_80 : 0 ;
}
case V_174 : {
struct V_175 V_148 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_148 . V_176 . V_177 = V_4 -> V_32 . V_167 ;
V_148 . V_176 . V_178 =
V_4 -> V_32 . V_167 - V_4 -> V_168 ;
V_148 . V_176 . V_179 = F_38 ( & V_4 -> V_138 ) ;
V_148 . V_176 . V_180 = V_148 . V_176 . V_178 * 3 / 4 ;
V_148 . V_181 . V_177 =
V_4 -> V_32 . V_170 ;
V_148 . V_181 . V_178 =
V_4 -> V_32 . V_170 -
( V_4 -> V_168 - V_4 -> V_171 ) ;
V_148 . V_181 . V_179 =
F_38 ( & V_4 -> V_140 ) ;
V_148 . V_181 . V_180 =
V_148 . V_181 . V_178 * 3 / 4 ;
V_148 . V_182 . V_177 = V_4 -> V_32 . V_172 ;
V_148 . V_182 . V_178 =
V_4 -> V_32 . V_172 - V_4 -> V_173 ;
V_148 . V_182 . V_179 = F_38 ( & V_4 -> V_142 ) ;
V_148 . V_182 . V_180 = V_148 . V_182 . V_178 * 3 / 4 ;
return F_33 ( V_17 , & V_148 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_148 ) ) )
? - V_80 : 0 ;
}
case V_183 : {
unsigned V_184 , V_185 ;
T_2 * V_186 ;
unsigned V_187 = ( V_64 -> V_188 . V_58 >>
V_189 ) &
V_190 ;
unsigned V_191 = ( V_64 -> V_188 . V_58 >>
V_192 ) &
V_193 ;
if ( V_187 == V_190 )
V_187 = 0xffffffff ;
if ( V_191 == V_193 )
V_191 = 0xffffffff ;
V_186 = F_39 ( V_64 -> V_188 . V_129 , sizeof( * V_186 ) , V_11 ) ;
if ( ! V_186 )
return - V_12 ;
V_185 = V_64 -> V_188 . V_129 * sizeof( * V_186 ) ;
for ( V_75 = 0 ; V_75 < V_64 -> V_188 . V_129 ; V_75 ++ )
if ( F_40 ( V_4 , V_187 , V_191 ,
V_64 -> V_188 . V_194 + V_75 ,
& V_186 [ V_75 ] ) ) {
F_36 ( L_4 ,
V_64 -> V_188 . V_194 + V_75 ) ;
F_11 ( V_186 ) ;
return - V_80 ;
}
V_184 = F_33 ( V_17 , V_186 , F_34 ( V_69 , V_185 ) ) ;
F_11 ( V_186 ) ;
return V_184 ? - V_80 : 0 ;
}
case V_195 : {
struct V_196 V_197 = {} ;
V_197 . V_198 = V_2 -> V_16 -> V_199 ;
V_197 . V_200 = V_4 -> V_201 ;
V_197 . V_202 = V_4 -> V_203 ;
V_197 . V_204 = V_2 -> V_16 -> V_205 ;
V_197 . V_206 = V_4 -> V_206 ;
V_197 . V_207 = V_4 -> V_34 . V_208 . V_209 ;
V_197 . V_210 = V_4 -> V_34 . V_208 . V_211 ;
V_197 . V_212 = F_41 ( V_4 ) * 10 ;
if ( V_4 -> V_54 . V_213 ) {
V_197 . V_214 = F_42 ( V_4 , false ) * 10 ;
V_197 . V_215 = F_43 ( V_4 , false ) * 10 ;
} else {
V_197 . V_214 = V_4 -> V_54 . V_216 * 10 ;
V_197 . V_215 = V_4 -> V_54 . V_217 * 10 ;
}
V_197 . V_218 = V_4 -> V_34 . V_208 . V_219 ;
V_197 . V_220 = V_4 -> V_34 . V_208 . V_221 *
V_4 -> V_34 . V_208 . V_209 ;
V_197 . V_222 = V_4 -> V_34 . V_208 . V_223 ;
V_197 . V_224 = 0 ;
V_197 . V_225 = 0 ;
if ( V_4 -> V_8 & V_14 )
V_197 . V_225 |= V_226 ;
if ( F_3 ( V_4 ) )
V_197 . V_225 |= V_227 ;
V_197 . V_228 = V_229 ;
V_197 . V_230 = ( T_3 ) V_4 -> V_231 . V_232 * V_104 ;
V_197 . V_233 = F_44 ( ( int ) V_234 , V_104 ) ;
V_197 . V_235 = ( 1 << V_236 ) *
V_104 ;
V_197 . V_237 = V_104 ;
V_197 . V_238 = V_4 -> V_34 . V_239 . V_240 ;
V_197 . V_241 = V_4 -> V_34 . V_239 . V_242 ;
V_197 . V_243 = V_4 -> V_34 . V_243 ;
memcpy ( & V_197 . V_244 [ 0 ] , & V_4 -> V_34 . V_239 . V_245 [ 0 ] ,
sizeof( V_4 -> V_34 . V_239 . V_245 ) ) ;
V_197 . V_246 = V_4 -> V_32 . V_246 ;
V_197 . V_247 = V_4 -> V_32 . V_248 ;
V_197 . V_249 = V_4 -> V_25 . V_250 ;
return F_33 ( V_17 , & V_197 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_197 ) ) ) ? - V_80 : 0 ;
}
case V_251 : {
unsigned V_75 ;
struct V_252 V_253 = {} ;
struct V_254 * V_255 ;
for ( V_75 = 0 ; V_75 < V_256 ; V_75 ++ ) {
V_255 = F_45 ( V_4 , V_75 ) ;
if ( V_255 ) {
V_253 . V_257 [ V_75 ] . V_258 = V_255 -> V_258 ;
V_253 . V_257 [ V_75 ] . V_259 = V_255 -> V_259 ;
V_253 . V_257 [ V_75 ] . V_260 = V_255 -> V_261 ;
V_253 . V_262 ++ ;
}
}
return F_33 ( V_17 , & V_253 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_253 ) ) ) ? - V_80 : 0 ;
}
case V_263 : {
T_2 V_264 = V_4 -> V_264 ;
switch ( V_64 -> V_265 . type ) {
case V_266 :
return F_33 ( V_17 , & V_264 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_264 ) ) )
? - V_80 : 0 ;
case V_267 : {
T_4 * V_268 ;
T_2 V_269 = V_64 -> V_265 . V_270 ;
if ( V_269 >= V_264 )
return - V_52 ;
V_268 = V_4 -> V_268 + V_269 ;
return F_33 ( V_17 , V_268 ,
F_34 ( ( V_127 ) V_69 , ( V_127 ) ( V_264 - V_269 ) ) )
? - V_80 : 0 ;
}
default:
F_36 ( L_5 ,
V_64 -> V_265 . type ) ;
return - V_52 ;
}
}
case V_271 : {
struct V_272 V_273 ;
switch ( V_64 -> V_96 . type ) {
case V_111 :
if ( V_4 -> V_274 < V_275 ) {
V_273 . V_276 = V_4 -> V_30 . V_277 ;
V_273 . V_278 = F_46 ( V_4 ) ;
return F_33 ( V_17 , & V_273 ,
F_34 ( ( V_127 ) V_69 , sizeof( V_273 ) ) ) ? - V_80 : 0 ;
} else {
return - V_279 ;
}
break;
default:
return - V_52 ;
}
}
default:
F_36 ( L_5 , V_64 -> V_77 ) ;
return - V_52 ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_48 ( V_4 ) ;
F_49 () ;
}
int F_50 ( struct V_1 * V_2 , struct V_61 * V_280 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_281 * V_282 ;
int V_9 ;
V_280 -> V_283 = NULL ;
V_9 = F_6 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_282 = F_13 ( sizeof( * V_282 ) , V_11 ) ;
if ( F_51 ( ! V_282 ) ) {
V_9 = - V_12 ;
goto V_284;
}
V_9 = F_52 ( V_4 , & V_282 -> V_285 ) ;
if ( V_9 ) {
F_11 ( V_282 ) ;
goto V_284;
}
if ( F_3 ( V_4 ) ) {
V_9 = F_53 ( V_4 , & V_282 -> V_285 ) ;
if ( V_9 )
goto V_284;
}
F_54 ( & V_282 -> V_286 ) ;
F_55 ( & V_282 -> V_287 ) ;
F_56 ( & V_282 -> V_288 ) ;
V_280 -> V_283 = V_282 ;
V_284:
F_27 ( V_2 -> V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
return V_9 ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_61 * V_280 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_281 * V_282 = V_280 -> V_283 ;
struct V_289 * V_290 ;
int V_273 ;
if ( ! V_282 )
return;
F_58 ( & V_282 -> V_288 ) ;
F_59 ( V_4 , V_280 ) ;
F_60 ( V_4 , V_280 ) ;
if ( F_3 ( V_4 ) ) {
F_61 ( F_62 ( V_4 -> V_291 . V_292 , false ) ) ;
F_63 ( V_4 , V_282 -> V_285 . V_293 ) ;
V_282 -> V_285 . V_293 = NULL ;
F_64 ( V_4 -> V_291 . V_292 ) ;
}
F_65 ( V_4 , & V_282 -> V_285 ) ;
F_66 (&fpriv->bo_list_handles, list, handle)
F_67 ( V_290 ) ;
F_68 ( & V_282 -> V_287 ) ;
F_69 ( & V_282 -> V_286 ) ;
F_11 ( V_282 ) ;
V_280 -> V_283 = NULL ;
F_27 ( V_2 -> V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
}
void F_70 ( struct V_1 * V_2 ,
struct V_61 * V_280 )
{
F_6 ( V_2 -> V_2 ) ;
}
T_5 F_71 ( struct V_1 * V_2 , unsigned int V_294 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_295 , V_296 , V_297 ;
T_5 V_129 ;
if ( V_294 >= V_4 -> V_67 . V_82 ) {
F_72 ( L_6 , V_294 ) ;
return - V_52 ;
}
if ( V_4 -> V_67 . V_83 [ V_294 ] ) {
do {
V_129 = F_73 ( V_4 , V_294 ) ;
V_297 = F_74 (
V_2 , V_294 , V_298 ,
& V_295 , & V_296 , NULL , NULL ,
& V_4 -> V_67 . V_83 [ V_294 ] -> V_84 . V_299 ) ;
} while ( V_129 != F_73 ( V_4 , V_294 ) );
if ( ( ( V_297 & ( V_300 | V_301 ) ) !=
( V_300 | V_301 ) ) ) {
F_75 ( L_7 , V_297 ) ;
} else {
F_75 ( L_8 ,
V_294 , V_295 ) ;
if ( V_295 >= 0 )
V_129 ++ ;
}
} else {
V_129 = F_73 ( V_4 , V_294 ) ;
F_75 ( L_9 ) ;
}
return V_129 ;
}
int F_76 ( struct V_1 * V_2 , unsigned int V_294 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_302 = F_77 ( V_4 , V_294 ) ;
return F_78 ( V_4 , & V_4 -> V_303 , V_302 ) ;
}
void F_79 ( struct V_1 * V_2 , unsigned int V_294 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_302 = F_77 ( V_4 , V_294 ) ;
F_80 ( V_4 , & V_4 -> V_303 , V_302 ) ;
}
int F_81 ( struct V_1 * V_2 , unsigned int V_294 ,
int * V_304 ,
struct V_305 * V_306 ,
unsigned V_8 )
{
struct V_71 * V_72 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_294 >= V_2 -> V_307 ) {
F_72 ( L_6 , V_294 ) ;
return - V_52 ;
}
V_72 = & V_4 -> V_67 . V_83 [ V_294 ] -> V_84 ;
if ( ! V_72 ) {
F_72 ( L_10 , V_294 ) ;
return - V_52 ;
}
return F_82 ( V_2 , V_294 , V_304 ,
V_306 , V_8 ,
& V_72 -> V_299 ) ;
}
static int F_83 ( struct V_308 * V_309 , void * V_60 )
{
struct V_310 * V_311 = (struct V_310 * ) V_309 -> V_312 ;
struct V_1 * V_2 = V_311 -> V_124 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_132 , V_75 ;
V_21 . V_22 = V_23 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_11 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_29 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_12 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_31 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_13 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_33 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_14 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_37 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_15 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_40 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_16 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_43 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_17 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_46 ;
V_21 . V_47 = 0 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_18 ,
V_19 . V_27 , V_19 . V_24 ) ;
if ( V_4 -> V_274 == V_313 ||
( V_4 -> V_274 > V_314 && V_4 -> V_274 != V_315 ) ) {
V_21 . V_47 = 1 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_19 ,
V_19 . V_27 , V_19 . V_24 ) ;
}
V_21 . V_22 = V_53 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_20 ,
V_19 . V_27 , V_19 . V_24 ) ;
V_21 . V_22 = V_55 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_56 . V_57 ; V_75 ++ ) {
V_21 . V_47 = V_75 ;
V_132 = F_31 ( & V_19 , & V_21 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_84 ( V_309 , L_21 ,
V_75 , V_19 . V_27 , V_19 . V_24 ) ;
}
return 0 ;
}
int F_85 ( struct V_3 * V_4 )
{
#if F_86 ( V_316 )
return F_87 ( V_4 , V_317 ,
F_88 ( V_317 ) ) ;
#else
return 0 ;
#endif
}
