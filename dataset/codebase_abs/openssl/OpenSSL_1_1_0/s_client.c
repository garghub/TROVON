static void F_1 ( void )
{
V_1 = V_2 ;
V_2 = 0 ;
}
static int F_2 ( void )
{
int V_3 = V_2 ;
V_2 = V_1 ;
return V_3 ;
}
static void F_3 ( T_1 * V_4 )
{
int V_3 ;
do {
V_3 = F_4 ( V_4 ) ;
if ( V_3 < 0 ) {
switch ( F_5 ( V_4 , V_3 ) ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
continue;
}
V_3 = 0 ;
}
} while ( V_3 < 0 );
}
static unsigned int F_6 ( T_1 * V_4 , const char * V_9 , char * V_10 ,
unsigned int V_11 ,
unsigned char * V_12 ,
unsigned int V_13 )
{
int V_3 ;
long V_14 ;
unsigned char * V_15 ;
if ( V_16 )
F_7 ( V_17 , L_1 ) ;
if ( ! V_9 ) {
if ( V_16 )
F_7 ( V_17 ,
L_2 ) ;
} else if ( V_16 )
F_7 ( V_17 , L_3 , V_9 ) ;
V_3 = F_8 ( V_10 , V_11 , L_4 , V_18 ) ;
if ( V_3 < 0 || ( unsigned int ) V_3 > V_11 )
goto V_19;
if ( V_16 )
F_7 ( V_17 , L_5 , V_10 ,
V_3 ) ;
V_15 = F_9 ( V_20 , & V_14 ) ;
if ( V_15 == NULL ) {
F_7 ( V_21 , L_6 ,
V_20 ) ;
return 0 ;
}
if ( V_14 > V_13 ) {
F_7 ( V_21 ,
L_7 ,
V_13 , V_14 ) ;
F_10 ( V_15 ) ;
return 0 ;
}
memcpy ( V_12 , V_15 , V_14 ) ;
F_10 ( V_15 ) ;
if ( V_16 )
F_7 ( V_17 , L_8 , V_14 ) ;
return V_14 ;
V_19:
if ( V_16 )
F_7 ( V_21 , L_9 ) ;
return 0 ;
}
static int F_11 ( T_1 * V_22 , int * V_23 , void * V_24 )
{
T_2 * V_25 = ( T_2 * ) V_24 ;
const char * V_26 = F_12 ( V_22 , V_27 ) ;
if ( F_13 ( V_22 ) != - 1 )
V_25 -> V_28 = ! F_14 ( V_22 ) && V_26 != NULL ;
else
F_7 ( V_21 , L_10 ) ;
return V_29 ;
}
static int F_15 ( const T_3 * V_30 , const T_3 * V_31 )
{
T_4 * V_32 = F_16 () ;
T_3 * V_25 = F_17 () ;
T_3 * V_33 = F_17 () ;
int V_3 =
V_31 != NULL && V_30 != NULL && V_32 != NULL && F_18 ( V_30 ) &&
F_19 ( V_30 , V_34 , V_32 , NULL ) == 1 &&
V_25 != NULL && F_20 ( V_25 , V_30 ) &&
F_19 ( V_25 , V_34 , V_32 , NULL ) == 1 &&
V_33 != NULL &&
F_21 ( V_33 , V_31 , V_25 , V_30 , V_32 ) &&
F_22 ( V_33 , 1 ) && F_23 ( V_33 , V_30 ) == 0 ;
F_24 ( V_33 ) ;
F_24 ( V_25 ) ;
F_25 ( V_32 ) ;
return V_3 ;
}
static int F_26 ( T_1 * V_22 , void * V_24 )
{
T_5 * V_35 = ( T_5 * ) V_24 ;
T_3 * V_30 = NULL , * V_31 = NULL ;
if ( ( ( V_30 = F_27 ( V_22 ) ) == NULL ) || ( ( V_31 = F_28 ( V_22 ) ) == NULL ) )
return 0 ;
if ( V_35 -> V_36 || V_35 -> V_37 || V_35 -> V_38 == 1 ) {
F_7 ( V_21 , L_11 ) ;
F_7 ( V_21 , L_12 ) ;
F_29 ( V_21 , V_30 ) ;
F_7 ( V_21 , L_13 ) ;
F_29 ( V_21 , V_31 ) ;
F_7 ( V_21 , L_14 ) ;
}
if ( F_30 ( V_31 , V_30 ) )
return 1 ;
if ( V_35 -> V_38 == 1 ) {
if ( V_35 -> V_36 )
F_7 ( V_21 ,
L_15 ) ;
if ( F_31 ( V_31 ) <= V_39 && F_15 ( V_30 , V_31 ) )
return 1 ;
}
F_7 ( V_21 , L_16 ) ;
return 0 ;
}
static char * F_32 ( T_1 * V_22 , void * V_24 )
{
T_5 * V_35 = ( T_5 * ) V_24 ;
char * V_40 = F_33 ( V_41 + 1 , L_17 ) ;
T_6 V_42 ;
int V_43 ;
V_42 . V_44 = ( char * ) V_35 -> V_45 ;
V_42 . V_46 = L_18 ;
if ( ( V_43 = F_34 ( V_40 , V_41 , 0 , & V_42 ) ) < 0 ) {
F_7 ( V_21 , L_19 ) ;
F_10 ( V_40 ) ;
return NULL ;
}
* ( V_40 + V_43 ) = '\0' ;
return V_40 ;
}
static int F_35 ( T_1 * V_22 , unsigned char * * V_47 , unsigned char * V_48 ,
const unsigned char * V_49 , unsigned int V_50 ,
void * V_24 )
{
T_7 * V_51 = V_24 ;
if ( ! V_52 ) {
unsigned V_53 ;
F_7 ( V_17 , L_20 ) ;
for ( V_53 = 0 ; V_53 < V_50 ; ) {
if ( V_53 )
F_36 ( V_17 , L_21 , 2 ) ;
F_36 ( V_17 , & V_49 [ V_53 + 1 ] , V_49 [ V_53 ] ) ;
V_53 += V_49 [ V_53 ] + 1 ;
}
F_36 ( V_17 , L_14 , 1 ) ;
}
V_51 -> V_54 =
F_37 ( V_47 , V_48 , V_49 , V_50 , V_51 -> V_55 , V_51 -> V_56 ) ;
return V_29 ;
}
static int F_38 ( T_1 * V_22 , unsigned int V_57 ,
const unsigned char * V_49 , T_8 V_50 ,
int * V_58 , void * V_24 )
{
char V_59 [ 100 ] ;
unsigned char V_60 [ 4 + 65536 ] ;
V_60 [ 0 ] = V_57 >> 8 ;
V_60 [ 1 ] = V_57 & 0xFF ;
V_60 [ 2 ] = V_50 >> 8 ;
V_60 [ 3 ] = V_50 & 0xFF ;
memcpy ( V_60 + 4 , V_49 , V_50 ) ;
F_8 ( V_59 , sizeof( V_59 ) , L_22 ,
V_57 ) ;
F_39 ( V_17 , V_59 , L_23 , V_60 , 4 + V_50 ) ;
return 1 ;
}
static T_9 F_40 ( const char * * V_61 , void * V_62 )
{
unsigned char * * V_47 = ( unsigned char * * ) V_62 ;
const char * V_49 = * V_61 ;
unsigned char * V_3 = F_33 ( strlen ( V_49 ) / 2 , L_24 ) ;
unsigned char * V_63 = V_3 ;
T_10 V_64 ;
int V_65 = 0 ;
if ( V_3 == NULL )
return - 1 ;
for ( V_64 = 0 ; * V_49 ; ++ V_49 ) {
int V_66 ;
if ( isspace ( F_41 ( * V_49 ) ) )
continue;
V_66 = F_42 ( * V_49 ) ;
if ( V_66 < 0 ) {
F_10 ( V_3 ) ;
return 0 ;
}
V_64 |= ( char ) V_66 ;
if ( ( V_65 ^= 1 ) == 0 ) {
* V_63 ++ = V_64 ;
V_64 = 0 ;
} else {
V_64 <<= 4 ;
}
}
if ( V_65 != 0 ) {
F_10 ( V_3 ) ;
return 0 ;
}
* V_61 = V_49 ;
return V_63 - ( * V_47 = V_3 ) ;
}
static T_9 F_43 ( const char * * V_61 , void * V_47 )
{
T_10 * V_62 = ( T_10 * ) V_47 ;
const char * V_49 = * V_61 ;
char * V_67 ;
long V_68 ;
int V_69 ;
F_1 () ;
V_68 = strtol ( V_49 , & V_67 , 10 ) ;
V_69 = F_2 () ;
if ( ( ( V_68 == V_70 || V_68 == V_71 ) && V_69 == V_72 ) ||
V_67 == V_49 || ! isspace ( F_41 ( * V_67 ) ) ||
V_68 != ( * V_62 = ( T_10 ) V_68 ) ) {
return - 1 ;
}
for ( V_49 = V_67 ; isspace ( F_41 ( * V_49 ) ) ; ++ V_49 )
continue;
* V_61 = V_49 ;
return 1 ;
}
static int F_44 ( T_1 * V_73 , const char * V_74 )
{
static T_10 V_75 ;
static T_10 V_76 ;
static T_10 V_77 ;
static unsigned char * V_55 ;
static struct V_78 V_79 [] = {
{ & V_75 , L_25 , F_43 } ,
{ & V_76 , L_26 , F_43 } ,
{ & V_77 , L_27 , F_43 } ,
{ & V_55 , L_28 , F_40 } ,
{ NULL , }
} ;
struct V_78 * V_80 ;
int V_3 ;
const char * V_63 = V_74 ;
T_9 V_56 = 0 ;
for ( V_80 = V_79 ; V_80 -> V_81 ; ++ V_80 ) {
if ( ( V_56 = V_80 -> V_82 ( & V_63 , V_80 -> V_81 ) ) <= 0 ) {
F_7 ( V_21 , L_29 ,
V_83 , V_80 -> V_84 , V_74 ) ;
return 0 ;
}
}
V_3 = F_45 ( V_73 , V_75 , V_76 , V_77 , V_55 , V_56 ) ;
F_10 ( V_55 ) ;
if ( V_3 == 0 ) {
F_46 ( V_21 ) ;
F_7 ( V_21 , L_30 ,
V_83 , V_74 ) ;
return 0 ;
}
if ( V_3 < 0 ) {
F_46 ( V_21 ) ;
F_7 ( V_21 , L_31 ,
V_83 , V_74 ) ;
return 0 ;
}
return V_3 ;
}
static void F_47 ( char * * V_85 , const char * V_86 )
{
F_10 ( * V_85 ) ;
* V_85 = NULL ;
if ( V_86 != NULL )
* V_85 = F_48 ( V_86 ) ;
}
int F_49 ( int V_87 , char * * V_88 )
{
T_11 * V_89 ;
T_12 * V_15 = NULL ;
T_1 * V_73 = NULL ;
T_13 * V_51 = NULL ;
F_50 ( V_90 ) * V_91 = NULL ;
V_90 * V_92 = NULL ;
T_14 * V_93 = NULL ;
T_15 * V_94 = NULL ;
T_16 * V_95 = NULL ;
F_50 ( V_96 ) * V_97 = NULL ;
char * V_98 = NULL ;
F_50 ( V_96 ) * V_99 = NULL ;
int V_100 = 0 ;
F_50 ( V_101 ) * V_102 = NULL ;
const T_17 * V_103 = F_51 () ;
const char * V_104 = NULL , * V_105 = NULL ;
char * V_106 = NULL , * V_107 = NULL ;
char * V_108 = NULL , * V_109 = NULL , * V_110 = NULL ;
char * V_111 = NULL , * V_112 = NULL , * V_113 = NULL ;
char * V_114 = NULL , * V_115 = NULL , * V_116 = NULL ;
char * V_117 = F_48 ( V_118 ) ;
char * V_119 = NULL ;
char * V_120 = NULL , * V_40 = NULL , * V_121 = NULL , * V_122 = NULL ;
char * V_123 = NULL , * V_124 = NULL , * V_125 = NULL , * V_25 ;
char * V_126 = NULL ;
const char * V_127 = L_32 ;
struct V_128 V_129 , * V_130 ;
T_18 V_131 , V_132 ;
int V_133 = 0 , V_134 = 0 ;
int V_135 = 0 , V_136 , V_137 , V_138 = V_139 ;
int V_140 = V_139 , V_141 = 0 , V_142 = 1 , V_143 = 0 ;
int V_144 = 0 ;
int V_145 = 0 ;
int V_146 = 0 , V_147 = V_148 , V_149 = 0 ;
int V_3 = 1 , V_150 = 1 , V_53 , V_151 = 0 , V_22 = - 1 , V_152 , V_153 , V_154 = 0 ;
int V_155 , V_156 , V_157 = 1 ;
int V_158 = V_159 , V_160 = V_161 ;
int V_162 = V_163 , V_164 = V_139 , V_165 = 0 ;
int V_166 , V_167 , V_168 , V_169 , V_170 , V_171 ;
int V_172 = 0 ;
int V_173 = 0 ;
int V_174 = 0 ;
long V_175 = 0 ;
T_19 V_176 ;
#ifndef F_52
int V_177 = 0 ;
long V_178 = 0 ;
#endif
#ifndef F_53
T_20 * V_179 = NULL ;
#endif
T_20 * V_69 = NULL ;
#if F_54 ( V_180 ) || F_54 ( V_181 )
struct V_128 V_182 ;
#endif
char * V_183 = NULL ;
const char * V_184 = NULL ;
T_2 V_185 = { NULL , 0 } ;
const char * V_186 = NULL ;
#define F_55 100
unsigned short V_187 [ F_55 ] ;
int V_188 = 0 , V_189 = 0 , V_56 ;
#ifndef F_56
const char * V_190 = NULL ;
#endif
#ifndef F_57
char * V_191 = NULL ;
int V_192 = 0 ;
T_5 V_35 = { NULL , NULL , 0 , 0 , 0 , 1024 } ;
#endif
#ifndef F_58
char * V_193 = NULL ;
int V_194 = 0 ;
#endif
int V_195 = 0 , V_196 = 0 , V_197 = 0 , V_198 = 0 ;
int V_199 = 0 ;
unsigned int V_200 = 0 ;
unsigned int V_201 = 0 ;
enum { V_202 , V_203 , V_204 } V_205 = V_204 ;
int V_206 = 0 ;
int V_207 = 0 , V_208 = 0 , V_209 = 0 , V_210 = 0 ;
int V_211 = 0 , V_212 = 0 ;
T_11 * V_213 = NULL ;
F_59 ( & V_131 ) ;
F_59 ( & V_132 ) ;
#if F_54 ( V_214 )
# if V_214 ( V_215 )
F_60 ( & V_131 , sizeof( V_131 ) ) ;
F_60 ( & V_132 , sizeof( V_132 ) ) ;
# endif
#endif
V_83 = F_61 ( V_88 [ 0 ] ) ;
V_52 = 0 ;
V_16 = 0 ;
V_216 = 0 ;
V_207 = 0 ;
V_93 = F_62 () ;
V_95 = F_63 () ;
if ( V_93 == NULL || V_95 == NULL ) {
F_7 ( V_21 , L_33 , V_83 ) ;
goto V_217;
}
V_106 = F_33 ( V_218 , L_34 ) ;
V_107 = F_33 ( V_218 , L_35 ) ;
V_108 = F_33 ( V_218 , L_36 ) ;
F_64 ( V_95 , V_219 | V_220 ) ;
V_83 = F_65 ( V_87 , V_88 , V_221 ) ;
while ( ( V_176 = F_66 () ) != V_222 ) {
if ( V_205 == V_203 && F_67 ( V_176 ) ) {
F_7 ( V_21 ,
L_37 ,
V_83 ) ;
goto V_217;
}
if ( V_205 == V_202 && F_68 ( V_176 ) ) {
F_7 ( V_21 ,
L_38 ,
V_83 ) ;
goto V_217;
}
if ( F_69 ( V_176 ) && ++ V_197 > 1 ) {
F_7 ( V_21 , L_39 ) ;
goto V_217;
}
if ( F_70 ( V_176 ) )
V_198 ++ ;
if ( V_197 == 1 && V_198 ) {
F_7 ( V_21 ,
L_40 ) ;
goto V_217;
}
switch ( V_176 ) {
case V_222 :
case V_223 :
V_224:
F_7 ( V_21 , L_41 , V_83 ) ;
goto V_217;
case V_225 :
F_71 ( V_221 ) ;
V_3 = 0 ;
goto V_217;
case V_226 :
V_205 = V_202 ;
V_158 = V_227 ;
V_206 ++ ;
break;
#ifdef F_72
case V_228 :
V_205 = V_202 ;
V_158 = F_72 ;
V_206 ++ ;
break;
#endif
case V_229 :
V_205 = V_202 ;
F_47 ( & V_116 , F_73 () ) ;
break;
case V_230 :
V_205 = V_202 ;
F_47 ( & V_117 , F_73 () ) ;
break;
case V_231 :
V_205 = V_202 ;
F_47 ( & V_110 , F_73 () ) ;
break;
case V_232 :
V_109 = F_73 () ;
V_162 = V_233 ;
break;
#ifdef F_74
case V_234 :
V_205 = V_203 ;
V_158 = F_74 ;
F_47 ( & V_116 , F_73 () ) ;
break;
#endif
case V_235 :
V_126 = F_73 () ;
break;
case V_236 :
V_127 = F_73 () ;
break;
case V_237 :
V_147 = V_238 ;
V_239 . V_240 = atoi ( F_73 () ) ;
if ( ! V_52 )
F_7 ( V_21 , L_42 , V_239 . V_240 ) ;
break;
case V_241 :
V_111 = F_73 () ;
break;
case V_242 :
V_125 = F_73 () ;
break;
case V_243 :
V_165 = 1 ;
break;
case V_244 :
V_124 = F_73 () ;
break;
case V_245 :
V_123 = F_73 () ;
break;
case V_246 :
if ( ! F_75 ( F_73 () , V_247 , & V_138 ) )
goto V_224;
break;
case V_248 :
if ( ! F_75 ( F_73 () , V_247 , & V_164 ) )
goto V_224;
break;
case V_249 :
V_239 . V_250 = 1 ;
break;
case V_251 :
V_239 . V_252 = 1 ;
break;
case V_253 :
V_210 = V_239 . V_252 = V_52 = 1 ;
break;
case V_254 :
if ( V_97 == NULL )
V_97 = F_76 () ;
if ( V_97 == NULL
|| ! F_77 ( V_97 , F_78 () )
|| ! F_77 ( V_97 , F_73 () ) ) {
F_7 ( V_21 , L_43 , V_83 ) ;
goto V_217;
}
break;
case V_255 :
if ( ! F_79 ( V_176 , V_93 ) )
goto V_217;
V_149 ++ ;
break;
case V_256 :
if ( ! F_80 ( V_176 , & V_94 ) )
goto V_217;
break;
case V_257 :
V_144 = 1 ;
break;
case V_258 :
V_141 = 1 ;
break;
case V_259 :
V_52 = V_209 = 1 ;
break;
case V_260 :
V_207 = 1 ;
break;
case V_261 :
V_157 = 0 ;
break;
case V_262 :
V_69 = F_81 ( F_73 () , 1 ) ;
break;
case V_263 :
#ifndef F_53
V_179 = F_82 ( F_73 () ) ;
if ( V_179 == NULL ) {
F_7 ( V_21 , L_44 ) ;
goto V_224;
}
#endif
break;
case V_264 :
V_119 = F_73 () ;
break;
case V_265 :
V_209 = 1 ;
break;
case V_266 :
V_209 = 0 ;
break;
case V_267 :
V_16 = 1 ;
break;
case V_268 :
V_211 = 1 ;
break;
case V_269 :
V_212 = 1 ;
break;
case V_270 :
#ifdef F_83
F_84 () ;
#endif
break;
case V_271 :
V_208 = 1 ;
break;
case V_272 :
V_213 = F_85 ( F_73 () , L_45 ) ;
break;
case V_273 :
#ifndef F_86
V_208 = 2 ;
#endif
break;
case V_274 :
V_145 = 1 ;
break;
case V_275 :
V_145 = 2 ;
break;
case V_276 :
V_216 = 1 ;
break;
case V_277 :
V_151 = 1 ;
break;
case V_278 :
V_154 = 1 ;
break;
#ifndef F_87
case V_279 :
V_18 = F_73 () ;
break;
case V_280 :
for ( V_25 = V_20 = F_73 () ; * V_25 ; V_25 ++ ) {
if ( isxdigit ( F_41 ( * V_25 ) ) )
continue;
F_7 ( V_21 , L_46 , V_20 ) ;
goto V_217;
}
break;
#endif
#ifndef F_57
case V_281 :
V_35 . V_282 = F_73 () ;
if ( V_195 < V_283 )
V_195 = V_283 ;
break;
case V_284 :
V_191 = F_73 () ;
if ( V_195 < V_283 )
V_195 = V_283 ;
break;
case V_285 :
V_35 . V_286 = atoi ( F_73 () ) ;
F_7 ( V_21 , L_47 ,
V_35 . V_286 ) ;
if ( V_195 < V_283 )
V_195 = V_283 ;
break;
case V_287 :
V_192 = 1 ;
if ( V_195 < V_283 )
V_195 = V_283 ;
break;
case V_288 :
V_35 . V_38 = 1 ;
if ( V_195 < V_283 )
V_195 = V_283 ;
break;
#endif
case V_289 :
V_186 = F_73 () ;
break;
case V_290 :
V_195 = V_291 ;
V_196 = V_291 ;
break;
case V_292 :
V_195 = V_293 ;
V_196 = V_293 ;
break;
case V_294 :
V_195 = V_295 ;
V_196 = V_295 ;
break;
case V_296 :
V_195 = V_283 ;
V_196 = V_283 ;
break;
case V_297 :
#ifndef F_52
V_103 = F_88 () ;
V_160 = V_298 ;
#endif
break;
case V_299 :
#ifndef F_89
V_103 = F_88 () ;
V_195 = V_300 ;
V_196 = V_300 ;
V_160 = V_298 ;
#endif
break;
case V_301 :
#ifndef F_90
V_103 = F_88 () ;
V_195 = V_302 ;
V_196 = V_302 ;
V_160 = V_298 ;
#endif
break;
case V_303 :
#ifndef F_52
V_177 = 1 ;
#endif
break;
case V_304 :
#ifndef F_52
V_178 = atol ( F_73 () ) ;
#endif
break;
case V_305 :
V_174 = 1 ;
break;
case V_306 :
if ( ! F_75 ( F_73 () , V_247 , & V_140 ) )
goto V_224;
break;
case V_307 :
V_120 = F_73 () ;
break;
case V_308 :
V_113 = F_73 () ;
break;
case V_309 :
V_112 = F_73 () ;
break;
case V_310 :
V_146 = 5 ;
break;
case V_311 :
V_104 = F_73 () ;
break;
case V_312 :
V_133 = 1 ;
break;
case V_313 :
V_114 = F_73 () ;
break;
case V_314 :
V_121 = F_73 () ;
break;
case V_315 :
V_135 = 1 ;
break;
case V_316 :
V_105 = F_73 () ;
break;
case V_317 :
V_134 = 1 ;
break;
#ifndef F_58
case V_318 :
V_194 = 0 ;
break;
case V_319 :
V_194 = 1 ;
break;
case V_320 :
V_193 = F_73 () ;
break;
#endif
case V_321 :
V_115 = F_73 () ;
break;
case V_322 :
V_122 = F_73 () ;
break;
case V_323 :
V_98 = F_73 () ;
break;
case V_324 :
if ( V_99 == NULL )
V_99 = F_76 () ;
if ( V_99 == NULL ||
! F_77 ( V_99 , F_73 () ) ) {
F_7 ( V_21 , L_43 , V_83 ) ;
goto V_217;
}
break;
case V_325 :
V_100 = 1 ;
break;
case V_326 :
#ifndef F_56
V_190 = F_73 () ;
#endif
break;
case V_327 :
V_184 = F_73 () ;
break;
case V_328 :
V_25 = F_73 () ;
V_56 = strlen ( V_25 ) ;
for ( V_189 = 0 , V_53 = 0 ; V_53 <= V_56 ; ++ V_53 ) {
if ( V_53 == V_56 || V_25 [ V_53 ] == ',' ) {
V_187 [ V_188 ] = atoi ( V_25 + V_189 ) ;
if ( ++ V_188 == F_55 )
break;
V_189 = V_53 + 1 ;
}
}
break;
case V_329 :
if ( ! F_91 ( F_73 () , V_330 , & V_162 ) )
goto V_217;
break;
case V_331 :
V_183 = F_73 () ;
break;
case V_332 :
V_333 = F_73 () ;
break;
case V_334 :
V_335 = F_73 () ;
break;
case V_336 :
V_337 = atoi ( F_73 () ) ;
break;
case V_338 :
V_199 = 1 ;
break;
case V_339 :
V_200 = atoi ( F_73 () ) ;
if ( V_200 == 0 ) {
V_200 = V_340 + 1 ;
}
break;
case V_341 :
V_201 = atoi ( F_73 () ) ;
break;
case V_342 :
V_173 = atoi ( F_73 () ) ;
break;
}
}
if ( V_206 >= 2 ) {
F_7 ( V_21 , L_48 , V_83 ) ;
goto V_224;
}
V_87 = F_92 () ;
if ( V_87 != 0 )
goto V_224;
if ( V_109 ) {
int V_343 ;
char * V_344 = V_116 , * V_345 = V_117 ;
if ( V_110 == NULL ) {
F_7 ( V_21 , L_49 , V_83 ) ;
goto V_224;
}
V_343 = F_93 ( V_109 , & V_116 , & V_117 , V_346 ) ;
if ( V_344 != V_116 )
F_10 ( V_344 ) ;
if ( V_345 != V_117 )
F_10 ( V_345 ) ;
if ( ! V_343 ) {
F_7 ( V_21 ,
L_50 , V_83 ) ;
goto V_217;
}
} else {
int V_343 = 1 ;
char * V_344 = V_116 , * V_345 = V_117 ;
if ( V_110 != NULL )
V_343 = F_93 ( V_110 , & V_116 , & V_117 ,
V_346 ) ;
if ( V_344 != V_116 )
F_10 ( V_344 ) ;
if ( V_345 != V_117 )
F_10 ( V_345 ) ;
if ( ! V_343 ) {
F_7 ( V_21 ,
L_51 ,
V_83 ) ;
goto V_217;
}
}
if ( V_158 == F_74 && V_160 != V_161 ) {
F_7 ( V_21 ,
L_52 ) ;
goto V_217;
}
if ( V_200 > V_340 ) {
F_7 ( V_21 , L_53 ) ;
goto V_217;
}
if ( V_201 > V_347 ) {
F_7 ( V_21 , L_54 ) ;
goto V_217;
}
#if ! F_54 ( F_56 )
V_348 . V_54 = - 1 ;
if ( V_190 ) {
V_348 . V_55 =
F_94 ( & V_348 . V_56 , V_190 ) ;
if ( V_348 . V_55 == NULL ) {
F_7 ( V_21 , L_55 ) ;
goto V_217;
}
} else
V_348 . V_55 = NULL ;
#endif
if ( ! F_95 ( V_120 , NULL , & V_40 , NULL ) ) {
F_7 ( V_21 , L_56 ) ;
goto V_217;
}
if ( V_112 == NULL )
V_112 = V_111 ;
if ( V_112 ) {
V_15 = F_96 ( V_112 , V_140 , 0 , V_40 , V_69 ,
L_57 ) ;
if ( V_15 == NULL ) {
F_46 ( V_21 ) ;
goto V_217;
}
}
if ( V_111 ) {
V_92 = F_97 ( V_111 , V_138 , L_58 ) ;
if ( V_92 == NULL ) {
F_46 ( V_21 ) ;
goto V_217;
}
}
if ( V_113 ) {
if ( ! F_98 ( V_113 , & V_91 , V_139 , NULL ,
L_59 ) )
goto V_217;
}
if ( V_125 ) {
V_101 * V_349 ;
V_349 = F_99 ( V_125 , V_164 ) ;
if ( V_349 == NULL ) {
F_100 ( V_21 , L_60 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
V_102 = F_101 () ;
if ( V_102 == NULL || ! F_102 ( V_102 , V_349 ) ) {
F_100 ( V_21 , L_61 ) ;
F_46 ( V_21 ) ;
F_103 ( V_349 ) ;
goto V_217;
}
}
if ( ! F_104 ( & V_94 ) )
goto V_217;
if ( ! F_105 ( NULL , 1 ) && V_119 == NULL
&& ! F_106 () ) {
F_7 ( V_21 ,
L_62 ) ;
}
if ( V_119 != NULL ) {
V_175 = F_107 ( V_119 ) ;
F_7 ( V_21 , L_63 , V_175 ) ;
}
if ( V_17 == NULL ) {
if ( V_52 && ! V_16 ) {
V_17 = F_108 ( F_109 () ) ;
if ( V_208 && ! V_213 )
V_213 = F_110 ( V_350 ) ;
} else if ( V_17 == NULL )
V_17 = F_110 ( V_350 ) ;
}
#ifndef F_57
if ( ! F_95 ( V_191 , NULL , & V_35 . V_45 , NULL ) ) {
F_7 ( V_21 , L_56 ) ;
goto V_217;
}
#endif
V_51 = F_111 ( V_103 ) ;
if ( V_51 == NULL ) {
F_46 ( V_21 ) ;
goto V_217;
}
if ( V_145 )
F_112 ( V_51 , V_145 ) ;
if ( V_186 ) {
if ( F_113 ( V_51 , V_186 ) == 0 ) {
F_7 ( V_21 , L_64 ,
V_186 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
}
if ( F_114 ( V_51 , V_195 ) == 0 )
goto V_217;
if ( F_115 ( V_51 , V_196 ) == 0 )
goto V_217;
if ( V_149 && ! F_116 ( V_51 , V_93 ) ) {
F_7 ( V_21 , L_65 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
if ( V_199 ) {
F_117 ( V_51 , V_351 ) ;
}
if ( V_200 > 0 ) {
F_118 ( V_51 , V_200 ) ;
}
if ( V_201 > 0 ) {
F_119 ( V_51 , V_201 ) ;
}
if ( V_173 > 0 ) {
F_120 ( V_51 , V_173 ) ;
}
if ( ! F_121 ( V_95 , V_97 , V_51 ) )
goto V_217;
if ( ! F_122 ( V_51 , V_121 , V_122 , V_114 , V_115 ,
V_102 , V_165 ) ) {
F_7 ( V_21 , L_66 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
#ifndef F_53
if ( V_179 ) {
if ( ! F_123 ( V_51 , V_179 ) ) {
F_100 ( V_21 , L_67 ) ;
F_46 ( V_21 ) ;
F_124 ( V_179 ) ;
goto V_217;
}
F_124 ( V_179 ) ;
}
#endif
#ifndef F_87
if ( V_20 != NULL ) {
if ( V_16 )
F_7 ( V_17 , L_68 ) ;
F_125 ( V_51 , F_6 ) ;
}
#endif
#ifndef F_126
if ( V_333 != NULL ) {
if ( F_127 ( V_51 , V_333 ) != 0 ) {
F_7 ( V_21 , L_69 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
}
#endif
if ( V_94 )
F_128 ( V_51 , V_94 ) ;
#if ! F_54 ( F_56 )
if ( V_348 . V_55 )
F_129 ( V_51 , F_35 , & V_348 ) ;
#endif
if ( V_184 ) {
T_8 V_352 ;
unsigned char * V_353 = F_94 ( & V_352 , V_184 ) ;
if ( V_353 == NULL ) {
F_7 ( V_21 , L_70 ) ;
goto V_217;
}
if ( F_130 ( V_51 , V_353 , V_352 ) != 0 ) {
F_7 ( V_21 , L_71 ) ;
goto V_217;
}
F_10 ( V_353 ) ;
}
for ( V_53 = 0 ; V_53 < V_188 ; V_53 ++ ) {
if ( ! F_131 ( V_51 ,
V_187 [ V_53 ] ,
NULL , NULL , NULL ,
F_38 , NULL ) ) {
F_7 ( V_21 ,
L_72 ,
V_187 [ V_53 ] ) ;
}
}
if ( V_154 )
F_132 ( V_51 , V_354 ) ;
#ifndef F_58
if ( V_194 &&
! F_133 ( V_51 , V_355 ) ) {
F_46 ( V_21 ) ;
goto V_217;
}
if ( ! F_134 ( V_51 , V_193 ) ) {
if ( V_194 ) {
F_46 ( V_21 ) ;
goto V_217;
}
F_135 () ;
}
#endif
F_136 ( V_51 , V_147 , V_356 ) ;
if ( ! F_137 ( V_51 , V_105 , V_104 , V_134 , V_133 ) ) {
F_46 ( V_21 ) ;
goto V_217;
}
F_138 ( V_51 , V_102 , V_165 ) ;
if ( ! F_139 ( V_51 , V_92 , V_15 , V_91 , V_135 ) )
goto V_217;
if ( V_183 != NULL ) {
V_185 . V_357 = V_21 ;
F_140 ( V_51 , F_11 ) ;
F_141 ( V_51 , & V_185 ) ;
}
# ifndef F_57
if ( V_35 . V_282 ) {
if ( ! V_192 && ! F_142 ( V_51 , V_35 . V_282 ) ) {
F_7 ( V_21 , L_73 ) ;
goto V_217;
}
V_35 . V_37 = V_208 ;
V_35 . V_36 = V_16 ;
F_143 ( V_51 , & V_35 ) ;
F_144 ( V_51 , F_32 ) ;
F_145 ( V_51 , V_35 . V_286 ) ;
if ( V_208 || V_16 || V_35 . V_38 == 0 )
F_146 ( V_51 ,
F_26 ) ;
}
# endif
if ( V_98 != NULL ) {
if ( F_147 ( V_51 ) <= 0 ) {
F_7 ( V_21 ,
L_74 ,
V_83 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
}
V_73 = F_148 ( V_51 ) ;
if ( V_123 ) {
T_21 * V_358 ;
T_11 * V_359 = F_85 ( V_123 , L_75 ) ;
if ( ! V_359 ) {
F_7 ( V_21 , L_76 , V_123 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
V_358 = F_149 ( V_359 , NULL , 0 , NULL ) ;
F_150 ( V_359 ) ;
if ( ! V_358 ) {
F_7 ( V_21 , L_76 , V_123 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
if ( ! F_151 ( V_73 , V_358 ) ) {
F_7 ( V_21 , L_77 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
F_152 ( V_358 ) ;
}
if ( V_174 )
F_153 ( V_73 , V_360 ) ;
if ( V_183 != NULL ) {
if ( ! F_154 ( V_73 , V_183 ) ) {
F_7 ( V_21 , L_78 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
}
if ( V_98 != NULL ) {
if ( F_155 ( V_73 , V_98 ) <= 0 ) {
F_7 ( V_21 , L_79
L_80 , V_83 ) ;
F_46 ( V_21 ) ;
goto V_217;
}
if ( V_99 == NULL ) {
F_7 ( V_21 , L_81
L_82 , V_83 ) ;
goto V_217;
}
if ( F_156 ( V_73 , V_99 ) <= 0 ) {
F_7 ( V_21 , L_83
L_84 , V_83 ) ;
goto V_217;
}
if ( V_100 )
F_157 ( V_73 , V_361 ) ;
} else if ( V_99 != NULL ) {
F_7 ( V_21 , L_85
L_86 , V_83 ) ;
goto V_217;
}
V_362:
if ( F_158 ( & V_22 , V_116 , V_117 , V_158 , V_160 ) == 0 ) {
F_7 ( V_21 , L_87 , F_159 () ) ;
F_160 ( V_22 ) ;
goto V_217;
}
F_7 ( V_17 , L_88 , V_22 ) ;
if ( V_207 ) {
if ( ! F_161 ( V_22 , 1 ) ) {
F_46 ( V_21 ) ;
goto V_217;
}
F_7 ( V_17 , L_89 ) ;
}
#ifndef F_52
if ( V_160 == V_298 ) {
union V_363 V_364 ;
V_89 = F_162 ( V_22 , V_365 ) ;
if ( ( V_364 . V_366 = F_163 () ) == NULL ) {
F_7 ( V_21 , L_90 ) ;
F_160 ( V_22 ) ;
goto V_217;
}
if ( ! F_164 ( V_22 , V_367 , & V_364 ) ) {
F_7 ( V_21 , L_91 ,
F_159 () ) ;
F_165 ( V_364 . V_366 ) ;
F_160 ( V_22 ) ;
goto V_217;
}
( void ) F_166 ( V_89 , V_364 . V_366 ) ;
F_165 ( V_364 . V_366 ) ;
V_364 . V_366 = NULL ;
if ( V_177 ) {
V_129 . V_368 = 0 ;
V_129 . V_369 = V_370 ;
F_167 ( V_89 , V_371 , 0 , & V_129 ) ;
V_129 . V_368 = 0 ;
V_129 . V_369 = V_372 ;
F_167 ( V_89 , V_373 , 0 , & V_129 ) ;
}
if ( V_178 ) {
if ( V_178 < F_168 ( V_73 ) ) {
F_7 ( V_21 , L_92 ,
F_168 ( V_73 ) ) ;
F_150 ( V_89 ) ;
goto V_374;
}
F_169 ( V_73 , V_375 ) ;
if ( ! F_170 ( V_73 , V_178 ) ) {
F_7 ( V_21 , L_93 ) ;
F_150 ( V_89 ) ;
goto V_374;
}
} else
F_167 ( V_89 , V_376 , 0 , NULL ) ;
} else
#endif
V_89 = F_171 ( V_22 , V_365 ) ;
if ( V_151 ) {
T_11 * V_377 ;
V_377 = F_108 ( F_172 () ) ;
V_89 = F_173 ( V_377 , V_89 ) ;
}
if ( V_16 ) {
F_174 ( V_89 , V_378 ) ;
F_175 ( V_89 , ( char * ) V_17 ) ;
}
if ( V_208 ) {
#ifndef F_86
if ( V_208 == 2 )
F_176 ( V_73 , V_379 ) ;
else
#endif
F_176 ( V_73 , V_380 ) ;
F_177 ( V_73 , V_213 ? V_213 : V_17 ) ;
}
if ( V_211 ) {
F_178 ( V_73 , V_381 ) ;
F_179 ( V_73 , V_17 ) ;
}
#ifndef F_180
if ( V_212 ) {
F_181 ( V_73 , V_382 ) ;
F_182 ( V_51 , V_383 ) ;
F_183 ( V_51 , V_17 ) ;
}
#endif
F_184 ( V_73 , V_89 , V_89 ) ;
F_185 ( V_73 ) ;
V_153 = F_186 ( V_73 ) + 1 ;
V_167 = 1 ;
V_166 = 0 ;
V_170 = 0 ;
V_169 = 1 ;
V_168 = 1 ;
V_136 = 0 ;
V_137 = 0 ;
V_155 = 0 ;
V_156 = 0 ;
switch ( ( V_384 ) V_162 ) {
case V_163 :
break;
case V_385 :
{
int V_386 = 0 ;
T_11 * V_387 = F_108 ( F_187 () ) ;
F_173 ( V_387 , V_89 ) ;
do {
V_143 = F_188 ( V_387 , V_108 , V_218 ) ;
}
while ( V_143 > 3 && V_108 [ 3 ] == '-' );
F_7 ( V_387 , L_94 , V_127 ) ;
( void ) F_189 ( V_387 ) ;
do {
V_143 = F_188 ( V_387 , V_108 , V_218 ) ;
if ( strstr ( V_108 , L_95 ) )
V_386 = 1 ;
}
while ( V_143 > 3 && V_108 [ 3 ] == '-' );
( void ) F_189 ( V_387 ) ;
F_190 ( V_387 ) ;
F_150 ( V_387 ) ;
if ( ! V_386 )
F_7 ( V_21 ,
L_96
L_97 ) ;
F_7 ( V_89 , L_98 ) ;
F_191 ( V_89 , V_107 , V_218 ) ;
}
break;
case V_388 :
{
F_191 ( V_89 , V_108 , V_218 ) ;
F_7 ( V_89 , L_99 ) ;
V_143 = F_191 ( V_89 , V_107 , V_218 ) ;
if ( V_143 < 0 ) {
F_7 ( V_21 , L_100 ) ;
goto V_217;
}
}
break;
case V_389 :
{
int V_386 = 0 ;
T_11 * V_387 = F_108 ( F_187 () ) ;
F_173 ( V_387 , V_89 ) ;
F_188 ( V_387 , V_108 , V_218 ) ;
F_7 ( V_387 , L_101 ) ;
( void ) F_189 ( V_387 ) ;
do {
V_143 = F_188 ( V_387 , V_108 , V_218 ) ;
if ( strstr ( V_108 , L_95 ) )
V_386 = 1 ;
}
while ( V_143 > 3 && V_108 [ 0 ] != '.' );
( void ) F_189 ( V_387 ) ;
F_190 ( V_387 ) ;
F_150 ( V_387 ) ;
if ( ! V_386 )
F_7 ( V_21 ,
L_102
L_97 ) ;
F_7 ( V_89 , L_103 ) ;
F_191 ( V_89 , V_107 , V_218 ) ;
}
break;
case V_390 :
{
T_11 * V_387 = F_108 ( F_187 () ) ;
F_173 ( V_387 , V_89 ) ;
do {
V_143 = F_188 ( V_387 , V_108 , V_218 ) ;
}
while ( V_143 > 3 && V_108 [ 3 ] == '-' );
( void ) F_189 ( V_387 ) ;
F_190 ( V_387 ) ;
F_150 ( V_387 ) ;
F_7 ( V_89 , L_104 ) ;
F_191 ( V_89 , V_107 , V_218 ) ;
}
break;
case V_391 :
case V_392 :
{
int V_393 = 0 ;
F_7 ( V_89 , L_105
L_106
L_107 ,
V_162 == V_391 ? L_108 : L_109 ,
V_126 ? V_126 : V_116 ) ;
V_393 = F_191 ( V_89 , V_108 , V_218 ) ;
V_108 [ V_393 ] = 0 ;
while ( ! strstr
( V_108 , L_110 )
&& ! strstr ( V_108 ,
L_111 ) )
{
V_393 = F_191 ( V_89 , V_108 , V_218 ) ;
if ( V_393 <= 0 )
goto V_374;
V_108 [ V_393 ] = 0 ;
}
F_7 ( V_89 ,
L_112 ) ;
V_393 = F_191 ( V_89 , V_107 , V_218 ) ;
V_107 [ V_393 ] = 0 ;
if ( ! strstr ( V_107 , L_113 ) )
goto V_374;
V_108 [ 0 ] = 0 ;
}
break;
case V_394 :
{
static const unsigned char V_395 [] = {
255 , 253 , 46
} ;
static const unsigned char V_396 [] = {
255 , 251 , 46
} ;
static const unsigned char V_397 [] = {
255 , 250 , 46 , 1 , 255 , 240
} ;
int V_398 ;
V_398 = F_191 ( V_89 , V_108 , V_218 ) ;
if ( V_398 != 3 || memcmp ( V_108 , V_395 , 3 ) != 0 )
goto V_374;
F_36 ( V_89 , V_396 , 3 ) ;
F_36 ( V_89 , V_397 , 6 ) ;
( void ) F_189 ( V_89 ) ;
V_398 = F_191 ( V_89 , V_108 , V_218 ) ;
if ( V_398 != 6 || memcmp ( V_108 , V_397 , 6 ) != 0 )
goto V_374;
}
break;
case V_233 :
{
int V_386 = 0 ;
T_11 * V_387 = F_108 ( F_187 () ) ;
F_173 ( V_387 , V_89 ) ;
F_7 ( V_387 , L_114 , V_110 ) ;
( void ) F_189 ( V_387 ) ;
do {
V_143 = F_188 ( V_387 , V_108 , V_218 ) ;
if ( strstr ( V_108 , L_115 ) != NULL
&& strstr ( V_108 , L_116 ) != NULL )
V_386 ++ ;
} while ( V_143 > 3 && V_386 == 0 );
( void ) F_189 ( V_387 ) ;
F_190 ( V_387 ) ;
F_150 ( V_387 ) ;
if ( ! V_386 ) {
F_7 ( V_21 , L_117 , V_83 ) ;
goto V_374;
}
}
break;
case V_399 :
{
int V_400 ;
T_11 * V_387 = F_108 ( F_187 () ) ;
F_173 ( V_387 , V_89 ) ;
F_7 ( V_387 , L_98 ) ;
( void ) F_189 ( V_387 ) ;
V_153 = F_186 ( V_73 ) + 1 ;
do {
V_400 = 0 ;
F_59 ( & V_131 ) ;
F_192 ( F_186 ( V_73 ) , & V_131 ) ;
V_129 . V_368 = V_401 ;
V_129 . V_369 = 0 ;
if ( ! F_193 ( V_387 )
&& ! F_194 ( V_387 )
&& ! F_194 ( V_89 )
&& F_195 ( V_153 , ( void * ) & V_131 , NULL , NULL ,
& V_129 ) < 1 ) {
F_7 ( V_21 ,
L_118 ,
V_401 ) ;
break;
}
V_143 = F_188 ( V_387 , V_108 , V_218 ) ;
if ( V_143 < 1 || sscanf ( V_108 , L_119 , & V_400 ) != 1 )
break;
if ( ( V_400 == 451 || V_400 == 421 )
&& strstr ( V_108 , L_95 ) != NULL ) {
F_7 ( V_21 , L_120 , V_108 ) ;
break;
}
if ( V_400 == 691 ) {
F_7 ( V_21 , L_121 ) ;
F_46 ( V_21 ) ;
break;
}
} while ( V_400 != 670 );
( void ) F_189 ( V_387 ) ;
F_190 ( V_387 ) ;
F_150 ( V_387 ) ;
if ( V_400 != 670 ) {
F_7 ( V_21 , L_122 ) ;
V_3 = 1 ;
goto V_374;
}
}
}
for (; ; ) {
F_59 ( & V_131 ) ;
F_59 ( & V_132 ) ;
if ( ( F_196 ( V_73 ) == V_300 ) &&
F_197 ( V_73 , & V_129 ) )
V_130 = & V_129 ;
else
V_130 = NULL ;
if ( F_198 ( V_73 ) && ! F_199 ( V_73 ) ) {
V_150 = 1 ;
V_170 = 0 ;
} else {
V_170 = 1 ;
if ( V_150 ) {
V_150 = 0 ;
if ( V_183 != NULL && ! F_14 ( V_73 ) ) {
F_7 ( V_17 ,
L_123 ,
V_185 . V_28 ? L_23 : L_124 ) ;
}
if ( V_124 ) {
T_11 * V_359 = F_85 ( V_124 , L_45 ) ;
if ( V_359 ) {
F_200 ( V_359 , F_201 ( V_73 ) ) ;
F_150 ( V_359 ) ;
} else
F_7 ( V_21 , L_125 ,
V_124 ) ;
}
if ( V_210 ) {
F_100 ( V_21 , L_126 ) ;
F_202 ( V_73 ) ;
}
F_203 ( V_17 , V_73 , V_142 ) ;
if ( V_142 > 0 )
V_142 -- ;
if ( V_162 ) {
F_36 ( V_21 , V_108 , V_143 ) ;
if ( ! V_146 )
V_162 = V_163 ;
}
if ( V_146 ) {
V_146 -- ;
F_7 ( V_17 ,
L_127 ) ;
F_3 ( V_73 ) ;
F_185 ( V_73 ) ;
F_160 ( F_186 ( V_73 ) ) ;
goto V_362;
}
}
}
V_171 = V_169 && F_204 ( V_73 ) ;
if ( ! V_171 ) {
#if ! F_54 ( V_180 ) && ! F_54 ( V_181 )
if ( V_170 ) {
if ( V_167 && ! V_172 )
F_192 ( fileno ( V_402 ) , & V_131 ) ;
if ( V_166 )
F_192 ( fileno ( stdout ) , & V_132 ) ;
}
if ( V_169 )
F_192 ( F_186 ( V_73 ) , & V_131 ) ;
if ( V_168 )
F_192 ( F_186 ( V_73 ) , & V_132 ) ;
#else
if ( ! V_170 || ! V_166 ) {
if ( V_169 )
F_192 ( F_186 ( V_73 ) , & V_131 ) ;
if ( V_168 )
F_192 ( F_186 ( V_73 ) , & V_132 ) ;
}
#endif
#if F_54 ( V_180 ) || F_54 ( V_181 )
V_53 = 0 ;
if ( ! V_166 ) {
if ( V_167 ) {
V_182 . V_368 = 1 ;
V_182 . V_369 = 0 ;
V_53 = F_195 ( V_153 , ( void * ) & V_131 , ( void * ) & V_132 ,
NULL , & V_182 ) ;
if ( ! V_53 && ( ! F_205 () || ! V_167 ) )
continue;
} else
V_53 = F_195 ( V_153 , ( void * ) & V_131 , ( void * ) & V_132 ,
NULL , V_130 ) ;
}
#else
V_53 = F_195 ( V_153 , ( void * ) & V_131 , ( void * ) & V_132 ,
NULL , V_130 ) ;
#endif
if ( V_53 < 0 ) {
F_7 ( V_21 , L_128 ,
F_159 () ) ;
goto V_374;
}
}
if ( ( F_196 ( V_73 ) == V_300 )
&& F_206 ( V_73 ) > 0 ) {
F_7 ( V_21 , L_129 ) ;
}
if ( ! V_171 && F_207 ( F_186 ( V_73 ) , & V_132 ) ) {
V_152 = F_208 ( V_73 , & ( V_106 [ V_137 ] ) , ( unsigned int ) V_136 ) ;
switch ( F_5 ( V_73 , V_152 ) ) {
case V_403 :
V_137 += V_152 ;
V_136 -= V_152 ;
if ( V_152 <= 0 )
goto V_217;
if ( V_136 <= 0 ) {
V_167 = 1 ;
V_168 = 0 ;
} else {
V_167 = 0 ;
V_168 = 1 ;
}
break;
case V_6 :
F_7 ( V_17 , L_130 ) ;
V_168 = 1 ;
V_167 = 0 ;
break;
case V_7 :
F_7 ( V_17 , L_131 ) ;
F_209 ( V_73 ) ;
V_168 = 1 ;
V_167 = 0 ;
break;
case V_5 :
F_7 ( V_17 , L_132 ) ;
V_166 = 0 ;
V_169 = 1 ;
V_168 = 0 ;
break;
case V_404 :
F_7 ( V_17 , L_133 ) ;
break;
case V_405 :
if ( V_136 != 0 ) {
F_7 ( V_17 , L_134 ) ;
V_3 = 0 ;
goto V_374;
} else {
V_167 = 1 ;
V_168 = 0 ;
break;
}
case V_406 :
if ( ( V_152 != 0 ) || ( V_136 != 0 ) ) {
F_7 ( V_21 , L_135 ,
F_159 () ) ;
goto V_374;
} else {
V_167 = 1 ;
V_168 = 0 ;
}
break;
case V_8 :
case V_407 :
F_46 ( V_21 ) ;
goto V_374;
}
}
#if F_54 ( V_180 ) || F_54 ( V_181 )
else if ( ! V_171 && V_166 )
#else
else if ( ! V_171 && F_207 ( fileno ( stdout ) , & V_132 ) )
#endif
{
#ifdef F_210
F_211 ( & ( V_107 [ V_156 ] ) , & ( V_107 [ V_156 ] ) , V_155 ) ;
#endif
V_53 = F_212 ( & ( V_107 [ V_156 ] ) , V_155 ) ;
if ( V_53 <= 0 ) {
F_7 ( V_17 , L_136 ) ;
V_3 = 0 ;
goto V_374;
}
V_155 -= V_53 ; ;
V_156 += V_53 ;
if ( V_155 <= 0 ) {
V_169 = 1 ;
V_166 = 0 ;
}
} else if ( V_171 || F_207 ( F_186 ( V_73 ) , & V_131 ) ) {
#ifdef F_213
{
static int V_408 ;
if ( ++ V_408 == 52 ) {
F_214 ( V_73 ) ;
V_408 = 0 ;
}
}
#endif
V_152 = F_215 ( V_73 , V_107 , 1024 ) ;
switch ( F_5 ( V_73 , V_152 ) ) {
case V_403 :
if ( V_152 <= 0 )
goto V_217;
V_156 = 0 ;
V_155 = V_152 ;
V_169 = 0 ;
V_166 = 1 ;
break;
case V_7 :
F_7 ( V_17 , L_137 ) ;
F_209 ( V_73 ) ;
V_166 = 0 ;
V_169 = 1 ;
if ( ( V_167 == 0 ) && ( V_168 == 0 ) )
V_168 = 1 ;
break;
case V_6 :
F_7 ( V_17 , L_138 ) ;
V_168 = 1 ;
V_167 = 0 ;
break;
case V_5 :
F_7 ( V_17 , L_139 ) ;
V_166 = 0 ;
V_169 = 1 ;
if ( ( V_167 == 0 ) && ( V_168 == 0 ) )
V_168 = 1 ;
break;
case V_404 :
F_7 ( V_17 , L_140 ) ;
break;
case V_406 :
V_3 = F_159 () ;
if ( V_210 )
F_100 ( V_21 , L_141 ) ;
else
F_7 ( V_21 , L_142 , V_3 ) ;
goto V_374;
case V_405 :
F_7 ( V_17 , L_143 ) ;
V_3 = 0 ;
goto V_374;
case V_8 :
case V_407 :
F_46 ( V_21 ) ;
goto V_374;
}
}
#if F_54 ( V_181 )
else if ( F_205 () )
#else
else if ( F_207 ( fileno ( V_402 ) , & V_131 ) )
#endif
{
if ( V_141 ) {
int V_409 , V_410 ;
V_53 = F_216 ( V_106 , V_218 / 2 ) ;
V_410 = 0 ;
for ( V_409 = 0 ; V_409 < V_53 ; V_409 ++ )
if ( V_106 [ V_409 ] == '\n' )
V_410 ++ ;
for ( V_409 = V_53 - 1 ; V_409 >= 0 ; V_409 -- ) {
V_106 [ V_409 + V_410 ] = V_106 [ V_409 ] ;
if ( V_106 [ V_409 ] == '\n' ) {
V_410 -- ;
V_53 ++ ;
V_106 [ V_409 + V_410 ] = '\r' ;
}
}
assert ( V_410 == 0 ) ;
} else
V_53 = F_216 ( V_106 , V_218 ) ;
if ( V_53 == 0 )
V_172 = 1 ;
if ( ( ! V_209 ) && ( ( V_53 <= 0 ) || ( V_106 [ 0 ] == 'Q' && V_157 ) ) ) {
F_7 ( V_21 , L_136 ) ;
V_3 = 0 ;
goto V_374;
}
if ( ( ! V_209 ) && ( V_106 [ 0 ] == 'R' && V_157 ) ) {
F_7 ( V_21 , L_144 ) ;
F_214 ( V_73 ) ;
V_136 = 0 ;
}
#ifndef F_217
else if ( ( ! V_209 ) && ( V_106 [ 0 ] == 'B' && V_157 ) ) {
F_7 ( V_21 , L_145 ) ;
F_218 ( V_73 ) ;
V_136 = 0 ;
}
#endif
else {
V_136 = V_53 ;
V_137 = 0 ;
#ifdef F_210
F_219 ( V_106 , V_106 , V_53 ) ;
#endif
}
V_168 = 1 ;
V_167 = 0 ;
}
}
V_3 = 0 ;
V_374:
if ( V_150 )
F_203 ( V_17 , V_73 , V_142 ) ;
F_3 ( V_73 ) ;
#if F_54 ( V_180 )
F_220 ( 50 ) ;
#endif
F_160 ( F_186 ( V_73 ) ) ;
V_217:
if ( V_73 != NULL ) {
if ( V_144 != 0 )
F_203 ( V_17 , V_73 , 1 ) ;
F_221 ( V_73 ) ;
}
#if ! F_54 ( F_56 )
F_10 ( V_348 . V_55 ) ;
#endif
F_222 ( V_51 ) ;
F_223 ( V_92 ) ;
F_224 ( V_102 , F_103 ) ;
F_225 ( V_15 ) ;
F_226 ( V_91 , F_223 ) ;
F_10 ( V_40 ) ;
#ifndef F_57
F_10 ( V_35 . V_45 ) ;
#endif
F_10 ( V_116 ) ;
F_10 ( V_117 ) ;
F_227 ( V_93 ) ;
F_228 ( V_94 ) ;
F_229 ( V_97 ) ;
F_229 ( V_99 ) ;
F_230 ( V_95 ) ;
F_231 ( V_106 , V_218 ) ;
F_231 ( V_107 , V_218 ) ;
F_231 ( V_108 , V_218 ) ;
F_150 ( V_17 ) ;
V_17 = NULL ;
F_150 ( V_213 ) ;
V_213 = NULL ;
return ( V_3 ) ;
}
static void F_203 ( T_11 * V_411 , T_1 * V_22 , int V_412 )
{
V_90 * V_413 = NULL ;
char V_414 [ V_415 ] ;
F_50 ( V_90 ) * V_416 ;
F_50 ( V_417 ) * V_418 ;
const T_22 * V_419 ;
V_417 * V_420 ;
int V_53 ;
#ifndef F_232
const T_23 * V_421 , * V_422 ;
#endif
unsigned char * V_423 ;
#ifndef F_58
const T_13 * V_51 = F_233 ( V_22 ) ;
#endif
if ( V_412 ) {
int V_424 = 0 ;
V_416 = F_234 ( V_22 ) ;
if ( V_416 != NULL ) {
V_424 = 1 ;
F_7 ( V_411 , L_146 ) ;
for ( V_53 = 0 ; V_53 < F_235 ( V_416 ) ; V_53 ++ ) {
F_236 ( F_237 ( F_238 ( V_416 , V_53 ) ) ,
V_414 , sizeof V_414 ) ;
F_7 ( V_411 , L_147 , V_53 , V_414 ) ;
F_236 ( F_239 ( F_238 ( V_416 , V_53 ) ) ,
V_414 , sizeof V_414 ) ;
F_7 ( V_411 , L_148 , V_414 ) ;
if ( V_216 )
F_240 ( V_411 , F_238 ( V_416 , V_53 ) ) ;
}
}
F_7 ( V_411 , L_149 ) ;
V_413 = F_241 ( V_22 ) ;
if ( V_413 != NULL ) {
F_7 ( V_411 , L_150 ) ;
if ( ! ( V_216 && V_424 ) )
F_240 ( V_411 , V_413 ) ;
F_236 ( F_237 ( V_413 ) , V_414 , sizeof V_414 ) ;
F_7 ( V_411 , L_151 , V_414 ) ;
F_236 ( F_239 ( V_413 ) , V_414 , sizeof V_414 ) ;
F_7 ( V_411 , L_152 , V_414 ) ;
} else
F_7 ( V_411 , L_153 ) ;
V_418 = F_242 ( V_22 ) ;
if ( ( V_418 != NULL ) && ( F_243 ( V_418 ) > 0 ) ) {
F_7 ( V_411 , L_154 ) ;
for ( V_53 = 0 ; V_53 < F_243 ( V_418 ) ; V_53 ++ ) {
V_420 = F_244 ( V_418 , V_53 ) ;
F_236 ( V_420 , V_414 , sizeof( V_414 ) ) ;
F_36 ( V_411 , V_414 , strlen ( V_414 ) ) ;
F_36 ( V_411 , L_14 , 1 ) ;
}
} else {
F_7 ( V_411 , L_155 ) ;
}
F_245 ( V_411 , V_22 ) ;
F_246 ( V_411 , V_22 ) ;
#ifndef F_58
if ( V_413 != NULL && ! F_14 ( V_22 ) && F_247 ( V_22 ) ) {
const F_50 ( V_425 ) * V_426 = F_248 ( V_22 ) ;
int V_427 = V_426 != NULL ? F_249 ( V_426 ) : 0 ;
F_7 ( V_411 , L_156 , V_427 ) ;
if ( V_427 > 0 ) {
const T_24 * V_428 = F_250 ( V_51 ) ;
F_7 ( V_411 , L_149 ) ;
for ( V_53 = 0 ; V_53 < V_427 ; ++ V_53 ) {
V_425 * V_429 = F_251 ( V_426 , V_53 ) ;
F_7 ( V_411 , L_157 ,
F_252 ( V_429 ) ) ;
F_253 ( V_429 , V_411 , 0 , V_428 ) ;
if ( V_53 < V_427 - 1 )
F_7 ( V_411 , L_158 ) ;
}
F_7 ( V_411 , L_14 ) ;
}
}
#endif
F_7 ( V_411 ,
L_159 V_430
L_160 V_430 L_161 ,
F_254 ( F_255 ( V_22 ) ) ,
F_256 ( F_257 ( V_22 ) ) ) ;
}
F_258 ( V_22 , V_411 ) ;
F_7 ( V_411 , ( F_14 ( V_22 ) ? L_162 : L_163 ) ) ;
V_419 = F_259 ( V_22 ) ;
F_7 ( V_411 , L_164 ,
F_260 ( V_419 ) , F_261 ( V_419 ) ) ;
if ( V_413 != NULL ) {
T_12 * V_431 ;
V_431 = F_262 ( V_413 ) ;
F_7 ( V_411 , L_165 ,
F_263 ( V_431 ) ) ;
}
F_7 ( V_411 , L_166 ,
F_264 ( V_22 ) ? L_23 : L_167 ) ;
#ifndef F_232
V_421 = F_265 ( V_22 ) ;
V_422 = F_266 ( V_22 ) ;
F_7 ( V_411 , L_168 ,
V_421 ? F_267 ( V_421 ) : L_169 ) ;
F_7 ( V_411 , L_170 ,
V_422 ? F_267 ( V_422 ) : L_169 ) ;
#endif
#ifdef F_268
{
int V_432 ;
union V_363 V_433 ;
V_432 = F_186 ( V_22 ) ;
if ( ( V_433 . V_366 = F_163 () ) != NULL
&& F_164 ( V_432 , V_367 , & V_433 ) ) {
F_7 ( V_17 , L_171 ,
F_269 ( F_270 ( V_433 . V_366 ) ) ) ;
}
F_165 ( V_433 . V_366 ) ;
}
#endif
#if ! F_54 ( F_56 )
if ( V_348 . V_54 != - 1 ) {
const unsigned char * V_434 ;
unsigned int V_435 ;
F_271 ( V_22 , & V_434 , & V_435 ) ;
F_7 ( V_411 , L_172 , V_348 . V_54 ) ;
F_36 ( V_411 , V_434 , V_435 ) ;
F_36 ( V_411 , L_14 , 1 ) ;
}
#endif
{
const unsigned char * V_434 ;
unsigned int V_435 ;
F_272 ( V_22 , & V_434 , & V_435 ) ;
if ( V_435 > 0 ) {
F_7 ( V_411 , L_173 ) ;
F_36 ( V_411 , V_434 , V_435 ) ;
F_36 ( V_411 , L_14 , 1 ) ;
} else
F_7 ( V_411 , L_174 ) ;
}
#ifndef F_126
{
T_25 * V_436 =
F_273 ( V_22 ) ;
if ( V_436 )
F_7 ( V_411 , L_175 ,
V_436 -> V_84 ) ;
}
#endif
F_274 ( V_411 , F_201 ( V_22 ) ) ;
if ( F_201 ( V_22 ) != NULL && V_335 != NULL ) {
F_7 ( V_411 , L_176 ) ;
F_7 ( V_411 , L_177 , V_335 ) ;
F_7 ( V_411 , L_178 , V_337 ) ;
V_423 = F_33 ( V_337 , L_179 ) ;
if ( ! F_275 ( V_22 , V_423 ,
V_337 ,
V_335 ,
strlen ( V_335 ) ,
NULL , 0 , 0 ) ) {
F_7 ( V_411 , L_180 ) ;
} else {
F_7 ( V_411 , L_181 ) ;
for ( V_53 = 0 ; V_53 < V_337 ; V_53 ++ )
F_7 ( V_411 , L_182 , V_423 [ V_53 ] ) ;
F_7 ( V_411 , L_14 ) ;
}
F_10 ( V_423 ) ;
}
F_7 ( V_411 , L_149 ) ;
F_223 ( V_413 ) ;
( void ) F_189 ( V_411 ) ;
}
static int V_383 ( T_1 * V_22 , void * V_24 )
{
const unsigned char * V_25 ;
int V_56 ;
T_26 * V_437 ;
V_56 = F_276 ( V_22 , & V_25 ) ;
F_100 ( V_24 , L_183 ) ;
if ( ! V_25 ) {
F_100 ( V_24 , L_184 ) ;
return 1 ;
}
V_437 = F_277 ( NULL , & V_25 , V_56 ) ;
if ( ! V_437 ) {
F_100 ( V_24 , L_185 ) ;
F_278 ( V_24 , ( char * ) V_25 , V_56 , 4 ) ;
return 0 ;
}
F_100 ( V_24 , L_186 ) ;
F_279 ( V_24 , V_437 , 0 ) ;
F_100 ( V_24 , L_187 ) ;
F_280 ( V_437 ) ;
return 1 ;
}
