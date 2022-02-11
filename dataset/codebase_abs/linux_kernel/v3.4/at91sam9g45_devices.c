void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
struct V_2 * V_3 =
F_3 ( NULL , L_1 ) ;
if ( V_3 )
F_4 ( V_3 ) ;
else
#endif
F_5 ( & V_4 ) ;
}
void T_1 F_1 ( void ) {}
void T_1 F_6 ( struct V_5 * V_6 )
{
int V_7 ;
if ( ! V_6 )
return;
for ( V_7 = 0 ; V_7 < V_6 -> V_8 ; V_7 ++ ) {
if ( F_7 ( V_6 -> V_9 [ V_7 ] ) )
F_8 ( V_6 -> V_9 [ V_7 ] ,
V_6 -> V_10 [ V_7 ] ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_8 ; V_7 ++ ) {
if ( F_7 ( V_6 -> V_11 [ V_7 ] ) )
F_9 ( V_6 -> V_11 [ V_7 ] , 1 ) ;
}
V_12 = * V_6 ;
F_5 ( & V_13 ) ;
}
void T_1 F_6 ( struct V_5 * V_6 ) {}
void T_1 F_10 ( struct V_5 * V_6 )
{
int V_7 ;
if ( ! V_6 )
return;
for ( V_7 = 0 ; V_7 < V_6 -> V_8 ; V_7 ++ ) {
if ( F_7 ( V_6 -> V_9 [ V_7 ] ) )
F_8 ( V_6 -> V_9 [ V_7 ] ,
V_6 -> V_10 [ V_7 ] ) ;
}
V_14 = * V_6 ;
F_5 ( & V_15 ) ;
}
void T_1 F_10 ( struct V_5 * V_6 ) {}
void T_1 F_11 ( struct V_16 * V_6 )
{
V_17 . V_18 . V_9 = - V_19 ;
V_17 . V_18 . V_20 = F_12 ( V_21 ) ;
memcpy ( V_17 . V_22 , V_21 , sizeof( V_21 ) ) ;
if ( V_6 && F_7 ( V_6 -> V_9 ) ) {
F_9 ( V_6 -> V_9 , 0 ) ;
F_13 ( V_6 -> V_9 , 1 ) ;
V_17 . V_18 . V_9 = V_6 -> V_9 ;
}
F_5 ( & V_23 ) ;
}
void T_1 F_11 ( struct V_16 * V_6 ) {}
void T_1 F_14 ( struct V_24 * V_6 )
{
if ( ! V_6 )
return;
if ( F_7 ( V_6 -> V_25 ) ) {
F_9 ( V_6 -> V_25 , 0 ) ;
F_13 ( V_6 -> V_25 , 1 ) ;
}
F_15 ( V_26 , 0 ) ;
F_15 ( V_27 , 0 ) ;
F_15 ( V_28 , 0 ) ;
F_15 ( V_29 , 0 ) ;
F_15 ( V_30 , 0 ) ;
F_15 ( V_31 , 0 ) ;
F_15 ( V_32 , 0 ) ;
F_15 ( V_33 , 0 ) ;
F_15 ( V_34 , 0 ) ;
F_15 ( V_35 , 0 ) ;
if ( ! V_6 -> V_36 ) {
F_16 ( V_37 , 0 ) ;
F_16 ( V_38 , 0 ) ;
F_16 ( V_39 , 0 ) ;
F_16 ( V_40 , 0 ) ;
F_16 ( V_41 , 0 ) ;
F_16 ( V_42 , 0 ) ;
F_16 ( V_43 , 0 ) ;
F_16 ( V_44 , 0 ) ;
}
V_45 = * V_6 ;
F_5 ( & V_46 ) ;
}
void T_1 F_14 ( struct V_24 * V_6 ) {}
void T_1 F_17 ( short V_47 , struct V_48 * V_6 )
{
if ( ! V_6 )
return;
if ( ! V_6 -> V_49 [ 0 ] . V_50 )
return;
#if F_2 ( V_51 ) || F_2 ( V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
V_56 = F_18 ( sizeof( struct V_55 ) , V_57 ) ;
V_54 = & V_56 -> V_58 ;
V_54 -> V_59 = & V_4 . V_60 ;
V_54 -> V_61 = V_62
| V_63 | V_64 ;
V_54 -> V_65 = V_66 | V_67 ;
if ( V_47 == 0 )
V_54 -> V_61 |= F_19 ( V_68 )
| F_20 ( V_68 ) ;
else
V_54 -> V_61 |= F_19 ( V_69 )
| F_20 ( V_69 ) ;
V_6 -> V_70 = V_56 ;
}
#endif
if ( F_7 ( V_6 -> V_49 [ 0 ] . V_71 ) ) {
F_9 ( V_6 -> V_49 [ 0 ] . V_71 , 1 ) ;
F_13 ( V_6 -> V_49 [ 0 ] . V_71 , 1 ) ;
}
if ( F_7 ( V_6 -> V_49 [ 0 ] . V_72 ) )
F_9 ( V_6 -> V_49 [ 0 ] . V_72 , 1 ) ;
if ( V_47 == 0 ) {
F_15 ( V_73 , 0 ) ;
F_15 ( V_74 , 1 ) ;
F_15 ( V_75 , 1 ) ;
if ( V_6 -> V_49 [ 0 ] . V_50 == 4 ) {
F_15 ( V_76 , 1 ) ;
F_15 ( V_77 , 1 ) ;
F_15 ( V_78 , 1 ) ;
if ( V_6 -> V_49 [ 0 ] . V_50 == 8 ) {
F_15 ( V_42 , 1 ) ;
F_15 ( V_43 , 1 ) ;
F_15 ( V_39 , 1 ) ;
F_15 ( V_40 , 1 ) ;
}
}
V_79 = * V_6 ;
F_5 ( & V_80 ) ;
} else {
F_15 ( V_81 , 0 ) ;
F_15 ( V_82 , 1 ) ;
F_15 ( V_83 , 1 ) ;
if ( V_6 -> V_49 [ 0 ] . V_50 == 4 ) {
F_15 ( V_84 , 1 ) ;
F_15 ( V_85 , 1 ) ;
F_15 ( V_86 , 1 ) ;
if ( V_6 -> V_49 [ 0 ] . V_50 == 8 ) {
F_15 ( V_44 , 1 ) ;
F_15 ( V_41 , 1 ) ;
F_15 ( V_37 , 1 ) ;
F_15 ( V_38 , 1 ) ;
}
}
V_87 = * V_6 ;
F_5 ( & V_88 ) ;
}
}
void T_1 F_17 ( short V_47 , struct V_48 * V_6 ) {}
void T_1 F_21 ( struct V_89 * V_6 )
{
unsigned long V_90 ;
if ( ! V_6 )
return;
V_90 = F_22 ( V_91 ) ;
F_23 ( V_91 , V_90 | V_92 ) ;
if ( F_7 ( V_6 -> V_93 ) )
F_8 ( V_6 -> V_93 , 1 ) ;
if ( F_7 ( V_6 -> V_94 ) )
F_9 ( V_6 -> V_94 , 1 ) ;
if ( F_7 ( V_6 -> V_95 ) )
F_9 ( V_6 -> V_95 , 1 ) ;
V_96 = * V_6 ;
F_5 ( & V_97 ) ;
}
void T_1 F_21 ( struct V_89 * V_6 ) {}
void T_1 F_24 ( short V_98 , struct V_99 * V_100 , int V_101 )
{
F_25 ( V_98 , V_100 , V_101 ) ;
if ( V_98 == 0 ) {
F_26 ( V_102 , 1 ) ;
F_27 ( V_102 , 1 ) ;
F_26 ( V_103 , 1 ) ;
F_27 ( V_103 , 1 ) ;
F_5 ( & V_104 ) ;
} else {
F_26 ( V_105 , 1 ) ;
F_27 ( V_105 , 1 ) ;
F_26 ( V_106 , 1 ) ;
F_27 ( V_106 , 1 ) ;
F_5 ( & V_107 ) ;
}
}
void T_1 F_24 ( short V_98 , struct V_99 * V_100 , int V_101 )
{
F_25 ( V_98 , V_100 , V_101 ) ;
if ( V_98 == 0 ) {
F_15 ( V_102 , 0 ) ;
F_27 ( V_102 , 1 ) ;
F_15 ( V_103 , 0 ) ;
F_27 ( V_103 , 1 ) ;
F_5 ( & V_104 ) ;
} else {
F_15 ( V_105 , 0 ) ;
F_27 ( V_105 , 1 ) ;
F_15 ( V_106 , 0 ) ;
F_27 ( V_106 , 1 ) ;
F_5 ( & V_107 ) ;
}
}
void T_1 F_24 ( short V_98 , struct V_99 * V_100 , int V_101 ) {}
void T_1 F_28 ( struct V_108 * V_100 , int V_101 )
{
int V_7 ;
unsigned long V_109 ;
short V_110 = 0 ;
short V_111 = 0 ;
for ( V_7 = 0 ; V_7 < V_101 ; V_7 ++ ) {
if ( V_100 [ V_7 ] . V_112 )
V_109 = ( unsigned long ) V_100 [ V_7 ] . V_112 ;
else if ( V_100 [ V_7 ] . V_113 == 0 )
V_109 = V_114 [ V_100 [ V_7 ] . V_115 ] ;
else
V_109 = V_116 [ V_100 [ V_7 ] . V_115 ] ;
if ( ! F_7 ( V_109 ) )
continue;
if ( V_100 [ V_7 ] . V_113 == 0 )
V_110 = 1 ;
else
V_111 = 1 ;
F_8 ( V_109 , 1 ) ;
V_100 [ V_7 ] . V_112 = ( void * ) V_109 ;
}
F_29 ( V_100 , V_101 ) ;
if ( V_110 ) {
F_15 ( V_117 , 0 ) ;
F_15 ( V_118 , 0 ) ;
F_15 ( V_119 , 0 ) ;
F_5 ( & V_120 ) ;
}
if ( V_111 ) {
F_15 ( V_121 , 0 ) ;
F_15 ( V_122 , 0 ) ;
F_15 ( V_123 , 0 ) ;
F_5 ( & V_124 ) ;
}
}
void T_1 F_28 ( struct V_108 * V_100 , int V_101 ) {}
void T_1 F_30 ( struct V_125 * V_6 )
{
if ( ! V_6 )
return;
F_15 ( V_126 , 0 ) ;
F_15 ( V_127 , 0 ) ;
F_15 ( V_128 , 0 ) ;
F_15 ( V_129 , 0 ) ;
if ( F_7 ( V_6 -> V_130 ) )
F_8 ( V_6 -> V_130 , 0 ) ;
V_131 = * V_6 ;
F_5 ( & V_132 ) ;
}
void T_1 F_30 ( struct V_125 * V_6 ) {}
void T_1 F_31 ( struct V_133 * V_6 ,
bool V_134 )
{
struct V_135 * V_136 ;
struct V_135 * V_137 ;
if ( ! V_6 )
return;
V_138 = * V_6 ;
F_15 ( V_139 , 0 ) ;
F_15 ( V_140 , 0 ) ;
F_15 ( V_141 , 0 ) ;
F_15 ( V_142 , 0 ) ;
F_15 ( V_143 , 0 ) ;
F_15 ( V_144 , 0 ) ;
F_15 ( V_145 , 0 ) ;
F_15 ( V_146 , 0 ) ;
F_15 ( V_147 , 0 ) ;
F_15 ( V_148 , 0 ) ;
F_15 ( V_149 , 0 ) ;
F_16 ( V_150 , 0 ) ;
F_16 ( V_151 , 0 ) ;
F_16 ( V_105 , 0 ) ;
F_16 ( V_106 , 0 ) ;
F_5 ( & V_152 ) ;
if ( V_134 ) {
F_16 ( V_153 , 0 ) ;
V_136 = F_32 ( NULL , L_2 ) ;
V_137 = F_32 ( NULL , L_3 ) ;
F_33 ( F_34 ( V_136 ) || F_34 ( V_137 ) ) ;
if ( F_35 ( V_136 , V_137 ) ) {
F_36 ( L_4 ) ;
} else {
V_154 [ 0 ] . V_135 = V_136 ;
F_37 ( V_154 ,
F_12 ( V_154 ) ) ;
}
F_38 ( V_136 ) ;
F_38 ( V_137 ) ;
}
}
void T_1 F_31 ( struct V_133 * V_6 ,
bool V_134 ) {}
void T_1 F_39 ( struct V_155 * V_6 )
{
if ( ! V_6 )
return;
F_15 ( V_156 , 0 ) ;
F_15 ( V_157 , 0 ) ;
F_15 ( V_158 , 0 ) ;
F_15 ( V_159 , 0 ) ;
F_15 ( V_160 , 0 ) ;
F_15 ( V_161 , 0 ) ;
F_15 ( V_162 , 0 ) ;
F_15 ( V_163 , 0 ) ;
F_15 ( V_164 , 0 ) ;
F_15 ( V_165 , 0 ) ;
F_15 ( V_166 , 0 ) ;
F_15 ( V_167 , 0 ) ;
F_15 ( V_168 , 0 ) ;
F_15 ( V_169 , 0 ) ;
F_15 ( V_170 , 0 ) ;
F_15 ( V_171 , 0 ) ;
F_15 ( V_172 , 0 ) ;
F_15 ( V_173 , 0 ) ;
F_15 ( V_174 , 0 ) ;
F_15 ( V_175 , 0 ) ;
F_15 ( V_176 , 0 ) ;
F_15 ( V_177 , 0 ) ;
F_15 ( V_178 , 0 ) ;
F_15 ( V_179 , 0 ) ;
F_15 ( V_180 , 0 ) ;
F_15 ( V_181 , 0 ) ;
F_15 ( V_182 , 0 ) ;
F_15 ( V_183 , 0 ) ;
F_15 ( V_184 , 0 ) ;
F_15 ( V_185 , 0 ) ;
V_186 = * V_6 ;
F_5 ( & V_187 ) ;
}
void T_1 F_39 ( struct V_155 * V_6 ) {}
static void T_1 F_40 ( void )
{
#if F_2 ( V_1 )
struct V_2 * V_188 ;
V_188 = F_41 ( NULL , V_189 ) ;
if ( V_188 ) {
F_4 ( V_188 ) ;
return;
}
#endif
F_5 ( & V_190 ) ;
F_5 ( & V_191 ) ;
}
static void T_1 F_40 ( void ) { }
static void T_1 F_42 ( void )
{
F_5 ( & V_192 ) ;
}
static void T_1 F_42 ( void ) {}
void T_1 F_43 ( struct V_193 * V_6 )
{
if ( ! V_6 )
return;
F_9 ( V_194 , 0 ) ;
F_9 ( V_195 , 0 ) ;
F_9 ( V_196 , 0 ) ;
F_9 ( V_197 , 0 ) ;
V_198 = * V_6 ;
F_5 ( & V_199 ) ;
}
void T_1 F_43 ( struct V_193 * V_6 ) {}
static void T_1 F_44 ( void )
{
V_200 . V_201 = L_5 ;
V_200 . V_202 = 2 ;
V_203 [ 1 ] . V_204 = V_205 +
4 * V_206 ;
V_203 [ 1 ] . V_207 = V_203 [ 1 ] . V_204 + 3 ;
}
static void T_1 F_44 ( void )
{
V_200 . V_202 = 1 ;
}
static void T_1 F_45 ( void )
{
F_44 () ;
F_5 ( & V_200 ) ;
}
static void T_1 F_46 ( void )
{
F_5 ( & V_208 ) ;
}
static void T_1 F_46 ( void ) {}
static void T_1 F_47 ( void )
{
F_5 ( & V_209 ) ;
}
static void T_1 F_47 ( void ) {}
void T_1 F_48 ( T_2 V_210 )
{
if ( V_210 & ( 1 << V_211 ) )
F_16 ( V_212 , 1 ) ;
if ( V_210 & ( 1 << V_213 ) )
F_16 ( V_214 , 1 ) ;
if ( V_210 & ( 1 << V_215 ) )
F_16 ( V_216 , 1 ) ;
if ( V_210 & ( 1 << V_217 ) )
F_16 ( V_218 , 1 ) ;
V_219 = V_210 ;
F_5 ( & V_220 ) ;
}
void T_1 F_48 ( T_2 V_210 ) {}
static inline void F_49 ( unsigned V_221 )
{
if ( V_221 & V_222 )
F_15 ( V_223 , 1 ) ;
if ( V_221 & V_224 )
F_15 ( V_218 , 1 ) ;
if ( V_221 & V_225 )
F_15 ( V_226 , 1 ) ;
if ( V_221 & V_227 )
F_15 ( V_228 , 1 ) ;
if ( V_221 & V_229 )
F_15 ( V_230 , 1 ) ;
if ( V_221 & V_231 )
F_15 ( V_232 , 1 ) ;
}
static inline void F_50 ( unsigned V_221 )
{
if ( V_221 & V_222 )
F_15 ( V_233 , 1 ) ;
if ( V_221 & V_224 )
F_15 ( V_234 , 1 ) ;
if ( V_221 & V_225 )
F_15 ( V_235 , 1 ) ;
if ( V_221 & V_227 )
F_15 ( V_236 , 1 ) ;
if ( V_221 & V_229 )
F_15 ( V_237 , 1 ) ;
if ( V_221 & V_231 )
F_15 ( V_238 , 1 ) ;
}
void T_1 F_51 ( unsigned V_239 , unsigned V_221 )
{
struct V_240 * V_241 ;
switch ( V_239 ) {
case V_242 :
V_241 = & V_243 ;
F_49 ( V_221 ) ;
break;
case V_244 :
V_241 = & V_245 ;
F_50 ( V_221 ) ;
break;
default:
return;
}
F_5 ( V_241 ) ;
}
void T_1 F_51 ( unsigned V_239 , unsigned V_221 ) {}
static inline void F_52 ( void )
{
F_15 ( V_246 , 0 ) ;
F_15 ( V_247 , 1 ) ;
}
static inline void F_53 ( unsigned V_221 )
{
F_15 ( V_248 , 1 ) ;
F_15 ( V_249 , 0 ) ;
if ( V_221 & V_250 )
F_16 ( V_251 , 0 ) ;
if ( V_221 & V_252 )
F_16 ( V_122 , 0 ) ;
}
static inline void F_54 ( unsigned V_221 )
{
F_15 ( V_253 , 1 ) ;
F_15 ( V_254 , 0 ) ;
if ( V_221 & V_250 )
F_15 ( V_255 , 0 ) ;
if ( V_221 & V_252 )
F_15 ( V_256 , 0 ) ;
}
static inline void F_55 ( unsigned V_221 )
{
F_15 ( V_257 , 1 ) ;
F_15 ( V_258 , 0 ) ;
if ( V_221 & V_250 )
F_16 ( V_259 , 0 ) ;
if ( V_221 & V_252 )
F_16 ( V_260 , 0 ) ;
}
static inline void F_56 ( unsigned V_221 )
{
F_15 ( V_150 , 1 ) ;
F_15 ( V_151 , 0 ) ;
if ( V_221 & V_250 )
F_16 ( V_83 , 0 ) ;
if ( V_221 & V_252 )
F_16 ( V_84 , 0 ) ;
}
void T_1 F_57 ( unsigned V_239 , unsigned V_261 , unsigned V_221 )
{
struct V_240 * V_241 ;
struct V_262 * V_18 ;
switch ( V_239 ) {
case 0 :
V_241 = & V_263 ;
F_52 () ;
break;
case V_264 :
V_241 = & V_265 ;
F_53 ( V_221 ) ;
break;
case V_266 :
V_241 = & V_267 ;
F_54 ( V_221 ) ;
break;
case V_268 :
V_241 = & V_269 ;
F_55 ( V_221 ) ;
break;
case V_270 :
V_241 = & V_271 ;
F_56 ( V_221 ) ;
break;
default:
return;
}
V_18 = V_241 -> V_60 . V_272 ;
V_18 -> V_273 = V_261 ;
if ( V_261 < V_274 )
V_275 [ V_261 ] = V_241 ;
}
void T_1 F_58 ( unsigned V_261 )
{
if ( V_261 < V_274 ) {
V_276 = V_275 [ V_261 ] ;
F_59 ( V_275 [ V_261 ] -> V_239 ) ;
}
}
void T_1 F_60 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_274 ; V_7 ++ ) {
if ( V_275 [ V_7 ] )
F_5 ( V_275 [ V_7 ] ) ;
}
if ( ! V_276 )
F_61 ( V_277 L_6 ) ;
}
void T_1 F_57 ( unsigned V_239 , unsigned V_261 , unsigned V_221 ) {}
void T_1 F_58 ( unsigned V_261 ) {}
void T_1 F_60 ( void ) {}
static int T_1 F_62 ( void )
{
F_1 () ;
F_42 () ;
F_45 () ;
F_46 () ;
F_47 () ;
F_40 () ;
return 0 ;
}
