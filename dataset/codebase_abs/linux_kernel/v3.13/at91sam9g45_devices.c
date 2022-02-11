void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void T_1 F_1 ( void ) {}
void T_1 F_3 ( struct V_2 * V_3 )
{
int V_4 ;
if ( ! V_3 )
return;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
if ( F_4 ( V_3 -> V_6 [ V_4 ] ) )
F_5 ( V_3 -> V_6 [ V_4 ] ,
V_3 -> V_7 [ V_4 ] ) ;
}
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
if ( F_4 ( V_3 -> V_8 [ V_4 ] ) )
F_6 ( V_3 -> V_8 [ V_4 ] , 1 ) ;
}
V_9 = * V_3 ;
F_2 ( & V_10 ) ;
}
void T_1 F_3 ( struct V_2 * V_3 ) {}
void T_1 F_7 ( struct V_2 * V_3 )
{
int V_4 ;
if ( ! V_3 )
return;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
if ( F_4 ( V_3 -> V_6 [ V_4 ] ) )
F_5 ( V_3 -> V_6 [ V_4 ] ,
V_3 -> V_7 [ V_4 ] ) ;
}
V_11 = * V_3 ;
F_2 ( & V_12 ) ;
}
void T_1 F_7 ( struct V_2 * V_3 ) {}
void T_1 F_8 ( struct V_13 * V_3 )
{
V_14 . V_15 . V_6 = - V_16 ;
V_14 . V_15 . V_17 = F_9 ( V_18 ) ;
memcpy ( V_14 . V_19 , V_18 , sizeof( V_18 ) ) ;
if ( V_3 && F_4 ( V_3 -> V_6 ) ) {
F_6 ( V_3 -> V_6 , 0 ) ;
F_10 ( V_3 -> V_6 , 1 ) ;
V_14 . V_15 . V_6 = V_3 -> V_6 ;
}
F_2 ( & V_20 ) ;
}
void T_1 F_8 ( struct V_13 * V_3 ) {}
void T_1 F_11 ( struct V_21 * V_3 )
{
if ( ! V_3 )
return;
if ( F_4 ( V_3 -> V_22 ) ) {
F_6 ( V_3 -> V_22 , 0 ) ;
F_10 ( V_3 -> V_22 , 1 ) ;
}
F_12 ( V_23 , 0 ) ;
F_12 ( V_24 , 0 ) ;
F_12 ( V_25 , 0 ) ;
F_12 ( V_26 , 0 ) ;
F_12 ( V_27 , 0 ) ;
F_12 ( V_28 , 0 ) ;
F_12 ( V_29 , 0 ) ;
F_12 ( V_30 , 0 ) ;
F_12 ( V_31 , 0 ) ;
F_12 ( V_32 , 0 ) ;
if ( ! V_3 -> V_33 ) {
F_13 ( V_34 , 0 ) ;
F_13 ( V_35 , 0 ) ;
F_13 ( V_36 , 0 ) ;
F_13 ( V_37 , 0 ) ;
F_13 ( V_38 , 0 ) ;
F_13 ( V_39 , 0 ) ;
F_13 ( V_40 , 0 ) ;
F_13 ( V_41 , 0 ) ;
}
V_42 = * V_3 ;
F_2 ( & V_43 ) ;
}
void T_1 F_11 ( struct V_21 * V_3 ) {}
void T_1 F_14 ( short V_44 , struct V_45 * V_3 )
{
if ( ! V_3 )
return;
if ( ! V_3 -> V_46 [ 0 ] . V_47 )
return;
#if F_15 ( V_48 ) || F_15 ( V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_53 = F_16 ( sizeof( struct V_52 ) , V_54 ) ;
V_51 = & V_53 -> V_55 ;
V_51 -> V_56 = & V_1 . V_57 ;
V_51 -> V_58 = V_59
| V_60 | V_61 ;
if ( V_44 == 0 )
V_51 -> V_58 |= F_17 ( V_62 )
| F_18 ( V_62 ) ;
else
V_51 -> V_58 |= F_17 ( V_63 )
| F_18 ( V_63 ) ;
V_3 -> V_64 = V_53 ;
}
#endif
if ( F_4 ( V_3 -> V_46 [ 0 ] . V_65 ) ) {
F_6 ( V_3 -> V_46 [ 0 ] . V_65 , 1 ) ;
F_10 ( V_3 -> V_46 [ 0 ] . V_65 , 1 ) ;
}
if ( F_4 ( V_3 -> V_46 [ 0 ] . V_66 ) )
F_6 ( V_3 -> V_46 [ 0 ] . V_66 , 1 ) ;
if ( V_44 == 0 ) {
F_12 ( V_67 , 0 ) ;
F_12 ( V_68 , 1 ) ;
F_12 ( V_69 , 1 ) ;
if ( V_3 -> V_46 [ 0 ] . V_47 == 4 ) {
F_12 ( V_70 , 1 ) ;
F_12 ( V_71 , 1 ) ;
F_12 ( V_72 , 1 ) ;
if ( V_3 -> V_46 [ 0 ] . V_47 == 8 ) {
F_12 ( V_39 , 1 ) ;
F_12 ( V_40 , 1 ) ;
F_12 ( V_36 , 1 ) ;
F_12 ( V_37 , 1 ) ;
}
}
V_73 = * V_3 ;
F_2 ( & V_74 ) ;
} else {
F_12 ( V_75 , 0 ) ;
F_12 ( V_76 , 1 ) ;
F_12 ( V_77 , 1 ) ;
if ( V_3 -> V_46 [ 0 ] . V_47 == 4 ) {
F_12 ( V_78 , 1 ) ;
F_12 ( V_79 , 1 ) ;
F_12 ( V_80 , 1 ) ;
if ( V_3 -> V_46 [ 0 ] . V_47 == 8 ) {
F_12 ( V_41 , 1 ) ;
F_12 ( V_38 , 1 ) ;
F_12 ( V_34 , 1 ) ;
F_12 ( V_35 , 1 ) ;
}
}
V_81 = * V_3 ;
F_2 ( & V_82 ) ;
}
}
void T_1 F_14 ( short V_44 , struct V_45 * V_3 ) {}
void T_1 F_19 ( struct V_83 * V_3 )
{
unsigned long V_84 ;
if ( ! V_3 )
return;
V_84 = F_20 ( V_85 ) ;
F_21 ( V_85 , V_84 | V_86 ) ;
if ( F_4 ( V_3 -> V_87 ) )
F_5 ( V_3 -> V_87 , 1 ) ;
if ( F_4 ( V_3 -> V_88 ) )
F_6 ( V_3 -> V_88 , 1 ) ;
if ( F_4 ( V_3 -> V_89 ) )
F_6 ( V_3 -> V_89 , 1 ) ;
V_90 = * V_3 ;
F_2 ( & V_91 ) ;
}
void T_1 F_19 ( struct V_83 * V_3 ) {}
void T_1 F_22 ( short V_92 , struct V_93 * V_94 , int V_95 )
{
F_23 ( V_92 , V_94 , V_95 ) ;
if ( V_92 == 0 ) {
F_24 ( V_96 , 1 ) ;
F_25 ( V_96 , 1 ) ;
F_24 ( V_97 , 1 ) ;
F_25 ( V_97 , 1 ) ;
F_2 ( & V_98 ) ;
} else {
F_24 ( V_99 , 1 ) ;
F_25 ( V_99 , 1 ) ;
F_24 ( V_100 , 1 ) ;
F_25 ( V_100 , 1 ) ;
F_2 ( & V_101 ) ;
}
}
void T_1 F_22 ( short V_92 , struct V_93 * V_94 , int V_95 )
{
F_23 ( V_92 , V_94 , V_95 ) ;
if ( V_92 == 0 ) {
F_12 ( V_96 , 0 ) ;
F_12 ( V_97 , 0 ) ;
F_2 ( & V_98 ) ;
} else {
F_12 ( V_99 , 0 ) ;
F_12 ( V_100 , 0 ) ;
F_2 ( & V_101 ) ;
}
}
void T_1 F_22 ( short V_92 , struct V_93 * V_94 , int V_95 ) {}
void T_1 F_26 ( struct V_102 * V_94 , int V_95 )
{
int V_4 ;
unsigned long V_103 ;
short V_104 = 0 ;
short V_105 = 0 ;
for ( V_4 = 0 ; V_4 < V_95 ; V_4 ++ ) {
if ( V_94 [ V_4 ] . V_106 )
V_103 = ( unsigned long ) V_94 [ V_4 ] . V_106 ;
else if ( V_94 [ V_4 ] . V_107 == 0 )
V_103 = V_108 [ V_94 [ V_4 ] . V_109 ] ;
else
V_103 = V_110 [ V_94 [ V_4 ] . V_109 ] ;
if ( ! F_4 ( V_103 ) )
continue;
if ( V_94 [ V_4 ] . V_107 == 0 )
V_104 = 1 ;
else
V_105 = 1 ;
F_5 ( V_103 , 1 ) ;
V_94 [ V_4 ] . V_106 = ( void * ) V_103 ;
}
F_27 ( V_94 , V_95 ) ;
if ( V_104 ) {
F_12 ( V_111 , 0 ) ;
F_12 ( V_112 , 0 ) ;
F_12 ( V_113 , 0 ) ;
F_2 ( & V_114 ) ;
}
if ( V_105 ) {
F_12 ( V_115 , 0 ) ;
F_12 ( V_116 , 0 ) ;
F_12 ( V_117 , 0 ) ;
F_2 ( & V_118 ) ;
}
}
void T_1 F_26 ( struct V_102 * V_94 , int V_95 ) {}
void T_1 F_28 ( struct V_119 * V_3 )
{
if ( ! V_3 )
return;
F_12 ( V_120 , 0 ) ;
F_12 ( V_121 , 0 ) ;
F_12 ( V_122 , 0 ) ;
F_12 ( V_123 , 0 ) ;
if ( F_4 ( V_3 -> V_124 ) )
F_5 ( V_3 -> V_124 , 0 ) ;
V_125 = * V_3 ;
F_2 ( & V_126 ) ;
}
void T_1 F_28 ( struct V_119 * V_3 ) {}
void T_1 F_29 ( struct V_127 * V_3 ,
bool V_128 )
{
struct V_129 * V_130 ;
struct V_129 * V_131 ;
if ( ! V_3 )
return;
V_132 = * V_3 ;
F_12 ( V_133 , 0 ) ;
F_12 ( V_134 , 0 ) ;
F_12 ( V_135 , 0 ) ;
F_12 ( V_136 , 0 ) ;
F_12 ( V_137 , 0 ) ;
F_12 ( V_138 , 0 ) ;
F_12 ( V_139 , 0 ) ;
F_12 ( V_140 , 0 ) ;
F_12 ( V_141 , 0 ) ;
F_12 ( V_142 , 0 ) ;
F_12 ( V_143 , 0 ) ;
F_13 ( V_144 , 0 ) ;
F_13 ( V_145 , 0 ) ;
F_13 ( V_99 , 0 ) ;
F_13 ( V_100 , 0 ) ;
F_2 ( & V_146 ) ;
if ( V_128 ) {
F_13 ( V_147 , 0 ) ;
V_130 = F_30 ( NULL , L_1 ) ;
V_131 = F_30 ( NULL , L_2 ) ;
F_31 ( F_32 ( V_130 ) || F_32 ( V_131 ) ) ;
if ( F_33 ( V_130 , V_131 ) ) {
F_34 ( L_3 ) ;
} else {
V_148 [ 0 ] . V_129 = V_130 ;
F_35 ( V_148 ,
F_9 ( V_148 ) ) ;
}
F_36 ( V_130 ) ;
F_36 ( V_131 ) ;
}
}
void T_1 F_29 ( struct V_127 * V_3 ,
bool V_128 ) {}
void T_1 F_37 ( struct V_149 * V_3 )
{
if ( ! V_3 )
return;
if ( F_38 () )
V_150 . V_151 = L_4 ;
else
V_150 . V_151 = L_5 ;
F_12 ( V_152 , 0 ) ;
F_12 ( V_153 , 0 ) ;
F_12 ( V_154 , 0 ) ;
F_12 ( V_155 , 0 ) ;
F_12 ( V_156 , 0 ) ;
F_12 ( V_157 , 0 ) ;
F_12 ( V_158 , 0 ) ;
F_12 ( V_159 , 0 ) ;
F_12 ( V_160 , 0 ) ;
F_12 ( V_161 , 0 ) ;
F_12 ( V_162 , 0 ) ;
F_12 ( V_163 , 0 ) ;
F_12 ( V_164 , 0 ) ;
F_12 ( V_165 , 0 ) ;
F_12 ( V_166 , 0 ) ;
F_12 ( V_167 , 0 ) ;
F_12 ( V_168 , 0 ) ;
F_12 ( V_169 , 0 ) ;
F_12 ( V_170 , 0 ) ;
F_12 ( V_171 , 0 ) ;
F_12 ( V_172 , 0 ) ;
F_12 ( V_173 , 0 ) ;
F_12 ( V_174 , 0 ) ;
F_12 ( V_175 , 0 ) ;
F_12 ( V_176 , 0 ) ;
F_12 ( V_177 , 0 ) ;
F_12 ( V_178 , 0 ) ;
F_12 ( V_179 , 0 ) ;
F_12 ( V_180 , 0 ) ;
F_12 ( V_181 , 0 ) ;
V_182 = * V_3 ;
F_2 ( & V_150 ) ;
}
void T_1 F_37 ( struct V_149 * V_3 ) {}
static void T_1 F_39 ( void )
{
F_2 ( & V_183 ) ;
F_2 ( & V_184 ) ;
}
static void T_1 F_39 ( void ) { }
static void T_1 F_40 ( void )
{
F_2 ( & V_185 ) ;
}
static void T_1 F_40 ( void ) {}
void T_1 F_41 ( struct V_186 * V_3 )
{
if ( ! V_3 )
return;
F_6 ( V_187 , 0 ) ;
F_6 ( V_188 , 0 ) ;
F_6 ( V_189 , 0 ) ;
F_6 ( V_190 , 0 ) ;
V_191 = * V_3 ;
F_2 ( & V_192 ) ;
}
void T_1 F_41 ( struct V_186 * V_3 ) {}
void T_1 F_42 ( struct V_193 * V_3 )
{
if ( ! V_3 )
return;
if ( F_43 ( 0 , & V_3 -> V_194 ) )
F_6 ( V_187 , 0 ) ;
if ( F_43 ( 1 , & V_3 -> V_194 ) )
F_6 ( V_188 , 0 ) ;
if ( F_43 ( 2 , & V_3 -> V_194 ) )
F_6 ( V_189 , 0 ) ;
if ( F_43 ( 3 , & V_3 -> V_194 ) )
F_6 ( V_190 , 0 ) ;
if ( F_43 ( 4 , & V_3 -> V_194 ) )
F_6 ( V_195 , 0 ) ;
if ( F_43 ( 5 , & V_3 -> V_194 ) )
F_6 ( V_196 , 0 ) ;
if ( F_43 ( 6 , & V_3 -> V_194 ) )
F_6 ( V_197 , 0 ) ;
if ( F_43 ( 7 , & V_3 -> V_194 ) )
F_6 ( V_198 , 0 ) ;
if ( V_3 -> V_199 )
F_12 ( V_200 , 0 ) ;
V_3 -> V_201 = 8 ;
V_3 -> V_202 = 40 ;
V_3 -> V_203 = & V_204 ;
V_3 -> V_205 = 4 ;
V_3 -> V_206 = V_207 ;
V_208 = * V_3 ;
F_2 ( & V_209 ) ;
}
void T_1 F_42 ( struct V_193 * V_3 ) {}
static void T_1 F_44 ( void )
{
V_210 . V_151 = L_6 ;
V_210 . V_211 = 3 ;
V_212 [ 1 ] . V_213 = V_214 +
4 * V_215 ;
V_212 [ 1 ] . V_216 = V_212 [ 1 ] . V_213 + 3 ;
V_212 [ 2 ] . V_213 = V_217 + V_218 ;
V_212 [ 2 ] . V_216 = V_217 + V_218 ;
}
static void T_1 F_44 ( void )
{
V_210 . V_211 = 1 ;
}
static void T_1 F_45 ( void )
{
F_44 () ;
F_2 ( & V_210 ) ;
}
static void T_1 F_46 ( void )
{
F_2 ( & V_219 ) ;
}
static void T_1 F_46 ( void ) {}
static void T_1 F_47 ( void )
{
F_2 ( & V_220 ) ;
}
static void T_1 F_47 ( void ) {}
void T_1 F_48 ( T_2 V_221 )
{
if ( V_221 & ( 1 << V_222 ) )
F_13 ( V_195 , 1 ) ;
if ( V_221 & ( 1 << V_223 ) )
F_13 ( V_224 , 1 ) ;
if ( V_221 & ( 1 << V_225 ) )
F_13 ( V_197 , 1 ) ;
if ( V_221 & ( 1 << V_226 ) )
F_13 ( V_227 , 1 ) ;
V_228 = V_221 ;
F_2 ( & V_229 ) ;
}
void T_1 F_48 ( T_2 V_221 ) {}
static inline void F_49 ( unsigned V_230 )
{
if ( V_230 & V_231 )
F_12 ( V_232 , 1 ) ;
if ( V_230 & V_233 )
F_12 ( V_227 , 1 ) ;
if ( V_230 & V_234 )
F_12 ( V_235 , 1 ) ;
if ( V_230 & V_236 )
F_12 ( V_237 , 1 ) ;
if ( V_230 & V_238 )
F_12 ( V_239 , 1 ) ;
if ( V_230 & V_240 )
F_12 ( V_241 , 1 ) ;
}
static inline void F_50 ( unsigned V_230 )
{
if ( V_230 & V_231 )
F_12 ( V_242 , 1 ) ;
if ( V_230 & V_233 )
F_12 ( V_243 , 1 ) ;
if ( V_230 & V_234 )
F_12 ( V_244 , 1 ) ;
if ( V_230 & V_236 )
F_12 ( V_245 , 1 ) ;
if ( V_230 & V_238 )
F_12 ( V_246 , 1 ) ;
if ( V_230 & V_240 )
F_12 ( V_247 , 1 ) ;
}
void T_1 F_51 ( unsigned V_248 , unsigned V_230 )
{
struct V_249 * V_250 ;
switch ( V_248 ) {
case V_251 :
V_250 = & V_252 ;
F_49 ( V_230 ) ;
break;
case V_253 :
V_250 = & V_254 ;
F_50 ( V_230 ) ;
break;
default:
return;
}
F_2 ( V_250 ) ;
}
void T_1 F_51 ( unsigned V_248 , unsigned V_230 ) {}
static inline void F_52 ( void )
{
F_12 ( V_255 , 0 ) ;
F_12 ( V_256 , 1 ) ;
}
static inline void F_53 ( unsigned V_230 )
{
F_12 ( V_257 , 1 ) ;
F_12 ( V_258 , 0 ) ;
if ( V_230 & V_259 )
F_13 ( V_260 , 0 ) ;
if ( V_230 & V_261 )
F_13 ( V_116 , 0 ) ;
}
static inline void F_54 ( unsigned V_230 )
{
F_12 ( V_262 , 1 ) ;
F_12 ( V_263 , 0 ) ;
if ( V_230 & V_259 )
F_12 ( V_264 , 0 ) ;
if ( V_230 & V_261 )
F_12 ( V_265 , 0 ) ;
}
static inline void F_55 ( unsigned V_230 )
{
F_12 ( V_266 , 1 ) ;
F_12 ( V_267 , 0 ) ;
if ( V_230 & V_259 )
F_13 ( V_268 , 0 ) ;
if ( V_230 & V_261 )
F_13 ( V_269 , 0 ) ;
}
static inline void F_56 ( unsigned V_230 )
{
F_12 ( V_144 , 1 ) ;
F_12 ( V_145 , 0 ) ;
if ( V_230 & V_259 )
F_13 ( V_77 , 0 ) ;
if ( V_230 & V_261 )
F_13 ( V_78 , 0 ) ;
}
void T_1 F_57 ( unsigned V_248 , unsigned V_270 , unsigned V_230 )
{
struct V_249 * V_250 ;
struct V_271 * V_15 ;
switch ( V_248 ) {
case 0 :
V_250 = & V_272 ;
F_52 () ;
break;
case V_273 :
V_250 = & V_274 ;
F_53 ( V_230 ) ;
break;
case V_275 :
V_250 = & V_276 ;
F_54 ( V_230 ) ;
break;
case V_277 :
V_250 = & V_278 ;
F_55 ( V_230 ) ;
break;
case V_279 :
V_250 = & V_280 ;
F_56 ( V_230 ) ;
break;
default:
return;
}
V_15 = V_250 -> V_57 . V_281 ;
V_15 -> V_282 = V_270 ;
if ( V_270 < V_283 )
V_284 [ V_270 ] = V_250 ;
}
void T_1 F_58 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_283 ; V_4 ++ ) {
if ( V_284 [ V_4 ] )
F_2 ( V_284 [ V_4 ] ) ;
}
}
void T_1 F_57 ( unsigned V_248 , unsigned V_270 , unsigned V_230 ) {}
void T_1 F_58 ( void ) {}
static void T_1 F_59 ( void )
{
F_2 ( & V_285 ) ;
}
static void T_1 F_59 ( void ) {}
static void T_1 F_60 ( void )
{
F_2 ( & V_286 ) ;
}
static void T_1 F_60 ( void ) {}
static void T_1 F_61 ( void )
{
struct V_50 * V_51 ;
V_51 = & V_53 . V_287 ;
V_51 -> V_56 = & V_1 . V_57 ;
V_51 -> V_58 = V_288 | V_60 |
F_17 ( V_289 ) ;
V_51 = & V_53 . V_290 ;
V_51 -> V_56 = & V_1 . V_57 ;
V_51 -> V_58 = V_288 | V_61 |
F_18 ( V_291 ) ;
V_292 . V_64 = & V_53 ;
F_2 ( & V_293 ) ;
}
static void T_1 F_61 ( void ) {}
static int T_1 F_62 ( void )
{
if ( F_63 () )
return 0 ;
F_1 () ;
F_40 () ;
F_45 () ;
F_46 () ;
F_47 () ;
F_39 () ;
F_59 () ;
F_60 () ;
F_61 () ;
return 0 ;
}
