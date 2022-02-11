T_1 F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
T_1 V_6 ;
T_1 V_7 ;
T_1 V_8 ;
T_1 V_9 ;
void * V_10 ;
V_6 = V_2 -> V_11 . V_12 -> V_13 [ V_14 ] . V_15 ;
V_7 = V_2 -> V_11 . V_12 -> V_13 [ V_16 ] . V_15 ;
V_5 = V_2 -> V_11 . V_12 -> V_13 [ V_17 ] . V_15 ;
V_8 = V_2 -> V_11 . V_12 -> V_13 [ V_18 ] . V_15 ;
V_2 -> V_19 = 0xFFFFF ;
V_3 = V_6 * 4 ;
V_4 = sizeof( struct V_20 ) * V_8 ;
V_4 += sizeof( unsigned long ) * F_2 ( V_6 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_5 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_7 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_3 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_8 ) ;
V_4 += sizeof( struct V_21 * * ) * V_6 ;
V_2 -> V_22 = F_3 ( V_4 , V_23 ) ;
if ( ! V_2 -> V_22 )
return - V_24 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_25 = V_3 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_26 = (struct V_20 * ) V_2 -> V_22 ;
V_10 = V_2 -> V_22 + ( sizeof( struct V_20 ) * V_8 ) ;
V_2 -> V_27 = V_28 |
V_29 | V_30 ;
V_2 -> V_31 = V_10 ;
V_2 -> V_32 = & V_2 -> V_31 [ F_2 ( V_6 ) ] ;
V_2 -> V_33 = & V_2 -> V_32 [ F_2 ( V_7 ) ] ;
V_2 -> V_34 = & V_2 -> V_33 [ F_2 ( V_5 ) ] ;
V_2 -> V_35 = & V_2 -> V_34 [ F_2 ( V_3 ) ] ;
V_2 -> V_36 = (struct V_21 * * ) ( & V_2 -> V_35 [ F_2 ( V_8 ) ] ) ;
F_4 ( 0 , V_2 -> V_33 ) ;
F_4 ( 0 , V_2 -> V_31 ) ;
F_4 ( 0 , V_2 -> V_32 ) ;
F_4 ( 0 , V_2 -> V_34 ) ;
F_4 ( 0 , V_2 -> V_35 ) ;
F_4 ( 1 , V_2 -> V_31 ) ;
F_4 ( 1 , V_2 -> V_32 ) ;
F_4 ( 1 , V_2 -> V_34 ) ;
F_4 ( 2 , V_2 -> V_32 ) ;
F_4 ( 2 , V_2 -> V_34 ) ;
F_5 ( & V_2 -> V_37 ) ;
F_5 ( & V_2 -> V_38 ) ;
V_9 = 24 - F_6 ( F_7 ( V_2 -> V_5 ) , 14 ) ;
V_2 -> V_39 = ~ ( ( ( 1 << V_9 ) - 1 ) << ( 32 - V_9 ) ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_40 * V_41 , bool V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 = & V_2 -> V_11 ;
T_1 V_47 = 0 ;
struct V_48 V_49 ;
int V_50 ;
do {
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_50 = V_46 -> V_51 -> V_52 ( V_41 , & V_49 ) ;
if ( V_50 )
break;
V_44 = (struct V_43 * ) ( unsigned long ) V_49 . V_53 ;
if ( V_49 . error )
F_9 ( L_1 ,
V_49 . V_54 , V_49 . V_55 , V_49 . V_56 ) ;
if ( V_44 ) {
V_44 -> V_57 . V_55 = V_49 . V_55 ;
V_44 -> V_57 . V_56 = V_49 . V_56 ;
V_44 -> V_57 . V_58 = V_49 . V_58 ;
V_44 -> V_57 . error = V_49 . error ;
if ( V_44 -> V_59 ) {
V_44 -> V_60 = true ;
F_10 ( & V_44 -> V_61 ) ;
F_11 ( & V_2 -> V_62 , V_44 ) ;
} else {
if ( V_44 -> V_63 )
V_44 -> V_63 ( V_44 , 1 ) ;
F_11 ( & V_2 -> V_62 , V_44 ) ;
}
}
V_47 ++ ;
} while ( 1 );
if ( V_42 && V_47 ) {
F_12 ( V_46 ) ;
V_46 -> V_51 -> V_64 ( V_41 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_40 * V_65 )
{
struct V_66 * V_67 = V_65 -> V_68 ;
if ( V_67 -> V_69 . V_70 )
V_67 -> V_69 . V_70 ( & V_67 -> V_69 ,
V_67 -> V_69 . V_71 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_45 * V_46 = (struct V_45 * ) & V_2 -> V_11 ;
enum V_72 V_73 ;
T_1 V_74 ;
do {
V_73 = F_15 ( V_46 , V_41 , & V_74 ) ;
if ( V_73 == V_75 )
break;
if ( V_73 ) {
F_9 ( L_2 , V_73 ) ;
break;
}
if ( V_74 ) {
F_9 ( L_3 , V_74 ) ;
break;
}
} while ( 1 );
V_46 -> V_51 -> V_64 ( V_41 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_45 * V_46 = & V_2 -> V_11 ;
struct V_78 * V_79 ;
struct V_40 * V_41 ;
bool V_42 = true ;
V_79 = & V_77 -> V_79 ;
do {
V_41 = V_46 -> V_80 -> V_81 ( V_46 , V_79 ) ;
if ( ! V_41 )
break;
if ( V_41 -> V_82 == V_83 )
F_8 ( V_2 , V_41 , V_42 ) ;
else if ( V_41 -> V_82 == V_84 )
F_13 ( V_2 , V_41 ) ;
else if ( ( V_41 -> V_82 == V_85 ) ||
( V_41 -> V_82 == V_86 ) )
F_14 ( V_2 , V_41 ) ;
} while ( 1 );
}
void F_17 ( struct V_21 * V_87 ,
T_2 V_88 ,
T_2 V_89 ,
T_2 V_90 ,
T_2 V_91 )
{
struct V_92 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_93 = V_88 ;
V_49 . V_94 = V_89 ;
V_49 . V_95 = true ;
V_49 . V_96 = true ;
V_49 . V_97 = true ;
V_49 . V_98 = true ;
V_49 . V_91 = V_91 ;
if ( V_90 & V_99 )
V_49 . V_97 = false ;
if ( V_90 & V_100 )
V_49 . V_98 = false ;
if ( V_87 -> V_101 . V_102 && ( V_88 == V_103 ) )
V_49 . V_104 = true ;
V_87 -> V_105 = V_88 ;
F_18 ( V_87 -> V_2 , V_87 , & V_49 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = & V_2 -> V_11 ;
struct V_106 * V_107 = & V_2 -> V_107 ;
struct V_108 * V_109 = & V_107 -> V_109 ;
struct V_110 V_111 ;
struct V_110 * V_49 = & V_111 ;
int V_50 ;
struct V_21 * V_87 = NULL ;
struct V_40 * V_41 = NULL ;
struct V_66 * V_65 = NULL ;
struct V_112 * V_113 = NULL ;
struct V_114 * V_115 = NULL ;
unsigned long V_116 ;
T_1 V_117 = 0 ;
if ( ! V_109 -> V_118 )
return;
do {
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_50 = V_46 -> V_119 -> V_120 ( V_109 , V_49 ) ;
if ( V_50 )
break;
V_117 ++ ;
F_20 ( V_46 , V_121 ,
L_4 ,
V_122 , V_49 -> V_123 , V_49 -> V_113 , V_49 -> V_124 ) ;
if ( V_49 -> V_113 ) {
F_21 ( & V_2 -> V_38 , V_116 ) ;
V_87 = V_2 -> V_36 [ V_49 -> V_124 ] ;
if ( ! V_87 ) {
F_22 ( & V_2 -> V_38 , V_116 ) ;
F_9 ( L_5 , V_49 -> V_124 ) ;
continue;
}
F_23 ( & V_87 -> V_125 ) ;
F_22 ( & V_2 -> V_38 , V_116 ) ;
V_113 = & V_87 -> V_101 ;
F_21 ( & V_87 -> V_126 , V_116 ) ;
V_87 -> V_127 = V_49 -> V_128 ;
V_87 -> V_105 = V_49 -> V_129 ;
V_87 -> V_130 = V_49 -> V_123 ;
F_22 ( & V_87 -> V_126 , V_116 ) ;
V_115 = & V_87 -> V_115 ;
V_115 -> V_131 = true ;
} else {
if ( V_49 -> V_123 != V_132 )
continue;
}
switch ( V_49 -> V_123 ) {
case V_133 :
if ( V_113 -> V_102 )
continue;
if ( F_24 ( & V_87 -> V_134 ) == 1 ) {
V_87 -> V_127 = V_135 ;
if ( ( V_87 -> V_127 == V_135 ) &&
( V_87 -> V_136 == V_137 ) ) {
F_17 ( V_87 ,
V_138 , 0 , 0 , 0 ) ;
F_25 ( V_87 ) ;
}
V_87 -> V_139 -> V_140 ( V_87 -> V_139 ) ;
F_26 ( V_87 -> V_141 ,
(struct V_142 * ) V_87 ,
V_143 , 1 , 0 ) ;
}
break;
case V_144 :
if ( V_113 -> V_102 )
F_27 ( V_113 , 0 ) ;
else
F_25 ( V_87 ) ;
break;
case V_145 :
F_17 ( V_87 , V_103 , 1 , 0 , 0 ) ;
F_25 ( V_87 ) ;
break;
case V_146 :
if ( F_28 ( & V_87 -> V_134 ) )
continue;
F_25 ( V_87 ) ;
break;
case V_147 :
F_29 ( V_113 ) ;
break;
case V_148 :
F_30 ( V_113 , V_49 ) ;
break;
case V_132 :
F_9 ( L_6 ,
V_49 -> V_123 ) ;
V_41 = (struct V_40 * ) ( unsigned long ) V_49 -> V_149 ;
V_65 = (struct V_66 * ) V_41 -> V_68 ;
if ( V_65 -> V_69 . V_150 ) {
struct V_151 V_152 ;
V_152 . V_153 = V_65 -> V_69 . V_153 ;
V_152 . V_154 = V_155 ;
V_152 . V_156 . V_41 = & V_65 -> V_69 ;
V_65 -> V_69 . V_150 ( & V_152 , V_65 -> V_69 . V_71 ) ;
}
break;
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_115 -> V_131 = false ;
default:
if ( ! V_49 -> V_182 && V_115 -> V_131 ) {
V_115 -> V_183 = V_49 -> V_184 ;
V_115 -> V_185 = false ;
V_115 -> V_186 = false ;
V_50 = V_46 -> V_187 -> V_188 ( & V_87 -> V_101 ,
V_87 -> V_189 . V_190 ,
V_115 ) ;
}
F_31 ( V_113 , V_49 ) ;
break;
}
if ( V_49 -> V_113 )
F_32 ( & V_87 -> V_125 ) ;
} while ( 1 );
if ( V_117 )
V_46 -> V_119 -> V_191 ( V_46 , V_117 ) ;
}
int F_33 ( struct V_1 * V_2 , T_3 V_192 , bool V_193 )
{
struct V_194 * V_49 ;
enum V_72 V_73 ;
struct V_43 * V_44 ;
struct V_195 * V_196 ;
V_44 = F_34 ( & V_2 -> V_62 , V_193 ) ;
if ( ! V_44 )
return - V_24 ;
V_196 = & V_44 -> V_49 ;
V_49 = & V_196 -> V_197 . V_198 . V_199 . V_49 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_200 = V_193 ;
V_49 -> V_201 = F_35 ( V_192 ) ;
V_196 -> V_202 = V_203 ;
V_196 -> V_204 = 1 ;
V_196 -> V_197 . V_198 . V_199 . V_62 = & V_2 -> V_62 . V_205 ;
V_196 -> V_197 . V_198 . V_199 . V_53 = ( V_206 ) V_44 ;
V_73 = F_36 ( V_2 , V_44 ) ;
if ( V_73 )
F_9 ( L_7 ) ;
return V_73 ;
}
void F_37 ( struct V_1 * V_2 ,
unsigned char * V_207 ,
T_1 * V_208 ,
bool V_209 ,
T_1 V_210 )
{
struct V_211 * V_49 ;
struct V_43 * V_44 ;
struct V_195 * V_196 ;
int V_212 ;
V_212 = F_38 ( V_2 , V_208 , V_209 , V_207 , V_210 ) ;
if ( V_212 == - 1 )
return;
V_44 = F_34 ( & V_2 -> V_62 , false ) ;
if ( ! V_44 )
return;
V_196 = & V_44 -> V_49 ;
if ( V_210 == V_213 ) {
V_196 -> V_202 = V_214 ;
V_49 = & V_196 -> V_197 . V_198 . V_215 . V_49 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_212 = F_35 ( ( T_3 ) V_212 ) ;
V_49 -> V_216 = true ;
F_39 ( V_49 -> V_207 , V_207 ) ;
V_196 -> V_197 . V_198 . V_215 . V_53 = ( V_206 ) V_44 ;
V_196 -> V_197 . V_198 . V_215 . V_62 = & V_2 -> V_62 . V_205 ;
} else {
V_196 -> V_202 = V_217 ;
V_196 -> V_197 . V_198 . V_218 . V_53 = ( V_206 ) V_44 ;
V_196 -> V_197 . V_198 . V_218 . V_62 = & V_2 -> V_62 . V_205 ;
V_196 -> V_197 . V_198 . V_218 . V_212 = V_212 ;
}
V_196 -> V_197 . V_198 . V_215 . V_62 = & V_2 -> V_62 . V_205 ;
V_196 -> V_197 . V_198 . V_215 . V_53 = ( V_206 ) V_44 ;
V_196 -> V_204 = 1 ;
if ( F_36 ( V_2 , V_44 ) )
F_9 ( L_8 ) ;
}
static void F_40 ( struct V_43 * V_44 , T_1 V_219 )
{
F_41 ( V_44 -> V_220 , V_219 ) ;
}
enum V_72 F_42 ( struct V_1 * V_2 ,
struct V_221 * V_222 ,
enum V_223 V_224 ,
enum V_225 V_226 ,
void * V_227 ,
bool V_228 )
{
struct V_229 * V_49 ;
struct V_45 * V_46 = & V_2 -> V_11 ;
enum V_72 V_73 ;
struct V_230 * V_231 = & V_2 -> V_62 ;
struct V_43 * V_44 ;
struct V_195 * V_196 ;
V_44 = F_34 ( V_231 , V_228 ) ;
if ( ! V_44 )
return V_232 ;
V_196 = & V_44 -> V_49 ;
V_49 = & V_196 -> V_197 . V_198 . V_233 . V_49 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_234 = V_226 ;
V_49 -> V_235 = V_224 ;
if ( V_222 -> V_236 != 0xFFFF ) {
V_49 -> V_237 = true ;
V_49 -> V_236 = F_35 ( V_222 -> V_236 ) ;
} else {
V_49 -> V_237 = false ;
}
V_49 -> V_238 = V_222 -> V_209 ;
F_39 ( V_49 -> V_207 , V_2 -> V_239 -> V_240 ) ;
V_49 -> V_241 = F_43 ( V_46 -> V_242 -> V_243 ) ;
V_49 -> V_244 = F_35 ( V_222 -> V_245 ) ;
V_49 -> V_246 [ 0 ] = F_43 ( V_222 -> V_247 [ 0 ] ) ;
V_49 -> V_246 [ 1 ] = F_43 ( V_222 -> V_247 [ 1 ] ) ;
V_49 -> V_246 [ 2 ] = F_43 ( V_222 -> V_247 [ 2 ] ) ;
V_49 -> V_246 [ 3 ] = F_43 ( V_222 -> V_247 [ 3 ] ) ;
if ( V_224 == V_248 ) {
V_49 -> V_249 = F_35 ( V_222 -> V_250 ) ;
V_49 -> V_251 [ 0 ] = F_43 ( V_222 -> V_252 [ 0 ] ) ;
V_49 -> V_251 [ 1 ] = F_43 ( V_222 -> V_252 [ 1 ] ) ;
V_49 -> V_251 [ 2 ] = F_43 ( V_222 -> V_252 [ 2 ] ) ;
V_49 -> V_251 [ 3 ] = F_43 ( V_222 -> V_252 [ 3 ] ) ;
}
if ( V_227 ) {
V_44 -> V_63 = F_40 ;
V_44 -> V_220 = ( void * ) V_227 ;
}
if ( V_49 -> V_238 )
F_20 ( V_46 , V_253 ,
L_9 ,
V_122 , ( ! V_226 ) ? L_10 : L_11 ,
V_49 -> V_246 ,
V_49 -> V_244 , V_49 -> V_207 , V_222 -> V_236 ) ;
else
F_20 ( V_46 , V_253 ,
L_12 ,
V_122 , ( ! V_226 ) ? L_10 : L_11 ,
V_49 -> V_246 ,
V_49 -> V_244 , V_49 -> V_207 , V_222 -> V_236 ) ;
V_196 -> V_197 . V_198 . V_233 . V_62 = & V_2 -> V_62 . V_205 ;
V_196 -> V_197 . V_198 . V_233 . V_53 = ( V_206 ) V_44 ;
V_196 -> V_202 = V_254 ;
V_196 -> V_204 = 1 ;
V_73 = F_36 ( V_2 , V_44 ) ;
if ( V_73 )
F_9 ( L_13 ) ;
return V_73 ;
}
enum V_72 F_44 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
struct V_255 * V_49 ,
bool V_228 )
{
enum V_72 V_73 ;
struct V_255 * V_256 ;
struct V_43 * V_44 ;
struct V_195 * V_196 ;
V_44 = F_34 ( & V_2 -> V_62 , V_228 ) ;
if ( ! V_44 )
return V_232 ;
V_196 = & V_44 -> V_49 ;
V_256 = & V_44 -> V_49 . V_197 . V_198 . V_257 . V_49 ;
memcpy ( V_256 , V_49 , sizeof( * V_256 ) ) ;
V_196 -> V_202 = V_258 ;
V_196 -> V_204 = 1 ;
V_196 -> V_197 . V_198 . V_257 . V_113 = V_113 ;
V_196 -> V_197 . V_198 . V_257 . V_53 = ( V_206 ) V_44 ;
V_73 = F_36 ( V_2 , V_44 ) ;
if ( V_73 )
F_9 ( L_14 ) ;
return V_73 ;
}
enum V_72 F_45 ( struct V_1 * V_2 ,
struct V_259 * V_49 ,
bool V_228 )
{
enum V_72 V_73 ;
struct V_259 * V_256 ;
struct V_43 * V_44 ;
struct V_195 * V_196 ;
if ( ( V_2 -> V_260 < V_261 ) && V_228 )
V_228 = false ;
V_44 = F_34 ( & V_2 -> V_62 , V_228 ) ;
if ( ! V_44 )
return V_232 ;
V_196 = & V_44 -> V_49 ;
V_256 = & V_44 -> V_49 . V_197 . V_198 . V_262 . V_49 ;
memcpy ( V_256 , V_49 , sizeof( * V_256 ) ) ;
V_196 -> V_202 = V_263 ;
V_196 -> V_204 = 1 ;
V_196 -> V_197 . V_198 . V_262 . V_62 = & V_2 -> V_62 . V_205 ;
V_196 -> V_197 . V_198 . V_262 . V_53 = ( V_206 ) V_44 ;
V_73 = F_36 ( V_2 , V_44 ) ;
if ( V_73 )
F_9 ( L_15 ) ;
return V_73 ;
}
static enum V_264 F_46 ( enum V_265 V_266 )
{
switch ( V_266 ) {
case V_267 :
return V_268 ;
case V_269 :
return V_270 ;
case V_271 :
return V_272 ;
case V_273 :
return V_274 ;
case V_275 :
return V_276 ;
case V_277 :
return V_278 ;
case V_279 :
default:
return V_280 ;
}
}
static void F_47 ( struct V_255 * V_281 ,
T_3 * V_282 ,
T_3 * V_283 ,
enum V_265 V_266 )
{
* V_282 = ( T_3 ) F_46 ( V_266 ) ;
* V_283 = V_284 ;
V_281 -> V_285 = true ;
}
void F_48 ( struct V_1 * V_2 , struct V_21 * V_87 )
{
struct V_255 V_49 ;
struct V_255 * V_281 = & V_49 ;
struct V_112 * V_113 = & V_87 -> V_101 ;
memset ( V_281 , 0 , sizeof( * V_281 ) ) ;
V_49 . V_182 = true ;
V_49 . V_286 = true ;
if ( V_113 -> V_102 ) {
F_47 ( V_281 , & V_281 -> V_287 ,
& V_281 -> V_288 , V_113 -> V_289 ) ;
F_47 ( V_281 , & V_281 -> V_290 ,
& V_281 -> V_291 , V_113 -> V_289 ) ;
}
( void ) F_44 ( V_2 , & V_87 -> V_101 , & V_49 , true ) ;
}
