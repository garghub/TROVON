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
V_3 = V_20 ;
V_4 = sizeof( struct V_21 ) * V_8 ;
V_4 += sizeof( unsigned long ) * F_2 ( V_6 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_5 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_7 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_3 ) ;
V_4 += sizeof( unsigned long ) * F_2 ( V_8 ) ;
V_4 += sizeof( struct V_22 * * ) * V_6 ;
V_2 -> V_23 = F_3 ( V_4 , V_24 ) ;
if ( ! V_2 -> V_23 )
return - V_25 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_26 = V_3 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_27 = (struct V_21 * ) V_2 -> V_23 ;
V_10 = V_2 -> V_23 + ( sizeof( struct V_21 ) * V_8 ) ;
V_2 -> V_28 = V_29 |
V_30 | V_31 ;
V_2 -> V_32 = V_10 ;
V_2 -> V_33 = & V_2 -> V_32 [ F_2 ( V_6 ) ] ;
V_2 -> V_34 = & V_2 -> V_33 [ F_2 ( V_7 ) ] ;
V_2 -> V_35 = & V_2 -> V_34 [ F_2 ( V_5 ) ] ;
V_2 -> V_36 = & V_2 -> V_35 [ F_2 ( V_3 ) ] ;
V_2 -> V_37 = (struct V_22 * * ) ( & V_2 -> V_36 [ F_2 ( V_8 ) ] ) ;
F_4 ( 0 , V_2 -> V_34 ) ;
F_4 ( 0 , V_2 -> V_32 ) ;
F_4 ( 0 , V_2 -> V_33 ) ;
F_4 ( 0 , V_2 -> V_35 ) ;
F_4 ( 0 , V_2 -> V_36 ) ;
F_4 ( 1 , V_2 -> V_32 ) ;
F_4 ( 1 , V_2 -> V_33 ) ;
F_4 ( 1 , V_2 -> V_35 ) ;
F_4 ( 2 , V_2 -> V_33 ) ;
F_4 ( 2 , V_2 -> V_35 ) ;
F_5 ( & V_2 -> V_38 ) ;
F_5 ( & V_2 -> V_39 ) ;
V_9 = 24 - F_6 ( F_7 ( V_2 -> V_5 ) , 14 ) ;
V_2 -> V_40 = ~ ( ( ( 1 << V_9 ) - 1 ) << ( 32 - V_9 ) ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_41 * V_42 , bool V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 = & V_2 -> V_11 ;
T_1 V_48 = 0 ;
struct V_49 V_50 ;
int V_51 ;
do {
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_51 = V_47 -> V_52 -> V_53 ( V_42 , & V_50 ) ;
if ( V_51 )
break;
V_45 = (struct V_44 * ) ( unsigned long ) V_50 . V_54 ;
if ( V_50 . error )
F_9 ( L_1 ,
V_50 . V_55 , V_50 . V_56 , V_50 . V_57 ) ;
if ( V_45 ) {
V_45 -> V_58 . V_56 = V_50 . V_56 ;
V_45 -> V_58 . V_57 = V_50 . V_57 ;
V_45 -> V_58 . V_59 = V_50 . V_59 ;
V_45 -> V_58 . error = V_50 . error ;
if ( V_45 -> V_60 ) {
V_45 -> V_61 = true ;
F_10 ( & V_45 -> V_62 ) ;
F_11 ( & V_2 -> V_63 , V_45 ) ;
} else {
if ( V_45 -> V_64 )
V_45 -> V_64 ( V_45 , 1 ) ;
F_11 ( & V_2 -> V_63 , V_45 ) ;
}
}
V_48 ++ ;
} while ( 1 );
if ( V_43 && V_48 ) {
F_12 ( V_47 ) ;
V_47 -> V_52 -> V_65 ( V_42 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_41 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 ;
if ( V_68 -> V_70 . V_71 )
V_68 -> V_70 . V_71 ( & V_68 -> V_70 ,
V_68 -> V_70 . V_72 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_46 * V_47 = (struct V_46 * ) & V_2 -> V_11 ;
enum V_73 V_74 ;
T_1 V_75 ;
do {
V_74 = F_15 ( V_47 , V_42 , & V_75 ) ;
if ( V_74 == V_76 )
break;
if ( V_74 ) {
F_9 ( L_2 , V_74 ) ;
break;
}
if ( V_75 ) {
F_9 ( L_3 , V_75 ) ;
break;
}
} while ( 1 );
V_47 -> V_52 -> V_65 ( V_42 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_46 * V_47 = & V_2 -> V_11 ;
struct V_79 * V_80 ;
struct V_41 * V_42 ;
bool V_43 = true ;
V_80 = & V_78 -> V_80 ;
do {
V_42 = V_47 -> V_81 -> V_82 ( V_47 , V_80 ) ;
if ( ! V_42 )
break;
if ( V_42 -> V_83 == V_84 )
F_8 ( V_2 , V_42 , V_43 ) ;
else if ( V_42 -> V_83 == V_85 )
F_13 ( V_2 , V_42 ) ;
else if ( ( V_42 -> V_83 == V_86 ) ||
( V_42 -> V_83 == V_87 ) )
F_14 ( V_2 , V_42 ) ;
} while ( 1 );
}
void F_17 ( struct V_22 * V_88 ,
T_2 V_89 ,
T_2 V_90 ,
T_2 V_91 ,
T_2 V_92 )
{
struct V_93 V_50 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_94 = V_89 ;
V_50 . V_95 = V_90 ;
V_50 . V_96 = true ;
V_50 . V_97 = true ;
V_50 . V_98 = true ;
V_50 . V_99 = true ;
V_50 . V_92 = V_92 ;
if ( V_91 & V_100 )
V_50 . V_98 = false ;
if ( V_91 & V_101 )
V_50 . V_99 = false ;
if ( V_88 -> V_102 . V_103 && ( V_89 == V_104 ) )
V_50 . V_105 = true ;
V_88 -> V_106 = V_89 ;
F_18 ( V_88 -> V_2 , V_88 , & V_50 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_11 ;
struct V_107 * V_108 = & V_2 -> V_108 ;
struct V_109 * V_110 = & V_108 -> V_110 ;
struct V_111 V_112 ;
struct V_111 * V_50 = & V_112 ;
int V_51 ;
struct V_22 * V_88 = NULL ;
struct V_41 * V_42 = NULL ;
struct V_67 * V_66 = NULL ;
struct V_113 * V_114 = NULL ;
struct V_115 * V_116 = NULL ;
unsigned long V_117 ;
T_1 V_118 = 0 ;
if ( ! V_110 -> V_119 )
return;
do {
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_51 = V_47 -> V_120 -> V_121 ( V_110 , V_50 ) ;
if ( V_51 )
break;
V_118 ++ ;
F_20 ( V_47 , V_122 ,
L_4 ,
V_123 , V_50 -> V_124 , V_50 -> V_114 , V_50 -> V_125 ) ;
if ( V_50 -> V_114 ) {
F_21 ( & V_2 -> V_39 , V_117 ) ;
V_88 = V_2 -> V_37 [ V_50 -> V_125 ] ;
if ( ! V_88 ) {
F_22 ( & V_2 -> V_39 , V_117 ) ;
F_20 ( V_47 , V_122 ,
L_5 ,
V_123 , V_50 -> V_125 ) ;
continue;
}
F_23 ( & V_88 -> V_126 ) ;
F_22 ( & V_2 -> V_39 , V_117 ) ;
V_114 = & V_88 -> V_102 ;
F_21 ( & V_88 -> V_127 , V_117 ) ;
V_88 -> V_128 = V_50 -> V_129 ;
V_88 -> V_106 = V_50 -> V_130 ;
V_88 -> V_131 = V_50 -> V_124 ;
F_22 ( & V_88 -> V_127 , V_117 ) ;
V_116 = & V_88 -> V_116 ;
V_116 -> V_132 = true ;
} else {
if ( V_50 -> V_124 != V_133 )
continue;
}
switch ( V_50 -> V_124 ) {
case V_134 :
if ( V_114 -> V_103 )
continue;
if ( F_24 ( & V_88 -> V_135 ) == 1 ) {
V_88 -> V_128 = V_136 ;
if ( ( V_88 -> V_128 == V_136 ) &&
( V_88 -> V_137 == V_138 ) ) {
F_17 ( V_88 ,
V_139 , 0 , 0 , 0 ) ;
F_25 ( V_88 ) ;
}
V_88 -> V_140 -> V_141 ( V_88 -> V_140 ) ;
F_26 ( V_88 -> V_142 ,
(struct V_143 * ) V_88 ,
V_144 , 1 , 0 ) ;
}
break;
case V_145 :
if ( V_114 -> V_103 )
F_27 ( V_114 , 0 ) ;
else
F_25 ( V_88 ) ;
break;
case V_146 :
F_17 ( V_88 , V_104 , 1 , 0 , 0 ) ;
F_25 ( V_88 ) ;
break;
case V_147 :
if ( F_28 ( & V_88 -> V_135 ) )
continue;
F_25 ( V_88 ) ;
break;
case V_148 :
F_29 ( V_47 , & V_88 -> V_102 , false ) ;
break;
case V_149 :
F_30 ( V_114 ) ;
break;
case V_150 :
F_31 ( V_114 , V_50 ) ;
break;
case V_133 :
F_9 ( L_6 ,
V_50 -> V_124 ) ;
V_42 = (struct V_41 * ) ( unsigned long ) V_50 -> V_151 ;
V_66 = (struct V_67 * ) V_42 -> V_69 ;
if ( V_66 -> V_70 . V_152 ) {
struct V_153 V_154 ;
V_154 . V_155 = V_66 -> V_70 . V_155 ;
V_154 . V_156 = V_157 ;
V_154 . V_158 . V_42 = & V_66 -> V_70 ;
V_66 -> V_70 . V_152 ( & V_154 , V_66 -> V_70 . V_72 ) ;
}
break;
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
case V_182 :
V_116 -> V_132 = false ;
default:
if ( ! V_50 -> V_183 && V_116 -> V_132 ) {
V_116 -> V_184 = V_50 -> V_185 ;
V_116 -> V_186 = false ;
V_116 -> V_187 = false ;
V_51 = V_47 -> V_188 -> V_189 ( & V_88 -> V_102 ,
V_88 -> V_190 . V_191 ,
V_116 ) ;
}
F_32 ( V_114 , V_50 ) ;
break;
}
if ( V_50 -> V_114 )
F_33 ( & V_88 -> V_126 ) ;
} while ( 1 );
if ( V_118 )
V_47 -> V_120 -> V_192 ( V_47 , V_118 ) ;
}
int F_34 ( struct V_1 * V_2 , T_3 V_193 , bool V_194 )
{
struct V_195 * V_50 ;
enum V_73 V_74 ;
struct V_44 * V_45 ;
struct V_196 * V_197 ;
V_45 = F_35 ( & V_2 -> V_63 , V_194 ) ;
if ( ! V_45 )
return - V_25 ;
V_197 = & V_45 -> V_50 ;
V_50 = & V_197 -> V_198 . V_199 . V_200 . V_50 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_201 = V_194 ;
V_50 -> V_202 = F_36 ( V_193 ) ;
V_197 -> V_203 = V_204 ;
V_197 -> V_205 = 1 ;
V_197 -> V_198 . V_199 . V_200 . V_63 = & V_2 -> V_63 . V_206 ;
V_197 -> V_198 . V_199 . V_200 . V_54 = ( V_207 ) V_45 ;
V_74 = F_37 ( V_2 , V_45 ) ;
if ( V_74 )
F_9 ( L_7 ) ;
return V_74 ;
}
void F_38 ( struct V_1 * V_2 ,
unsigned char * V_208 ,
T_1 * V_209 ,
bool V_210 ,
T_1 V_211 )
{
struct V_212 * V_50 ;
struct V_44 * V_45 ;
struct V_196 * V_197 ;
int V_213 ;
V_213 = F_39 ( V_2 , V_209 , V_210 , V_208 , V_211 ) ;
if ( V_213 == - 1 )
return;
V_45 = F_35 ( & V_2 -> V_63 , false ) ;
if ( ! V_45 )
return;
V_197 = & V_45 -> V_50 ;
if ( V_211 == V_214 ) {
V_197 -> V_203 = V_215 ;
V_50 = & V_197 -> V_198 . V_199 . V_216 . V_50 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_213 = F_36 ( ( T_3 ) V_213 ) ;
V_50 -> V_217 = true ;
F_40 ( V_50 -> V_208 , V_208 ) ;
V_197 -> V_198 . V_199 . V_216 . V_54 = ( V_207 ) V_45 ;
V_197 -> V_198 . V_199 . V_216 . V_63 = & V_2 -> V_63 . V_206 ;
} else {
V_197 -> V_203 = V_218 ;
V_197 -> V_198 . V_199 . V_219 . V_54 = ( V_207 ) V_45 ;
V_197 -> V_198 . V_199 . V_219 . V_63 = & V_2 -> V_63 . V_206 ;
V_197 -> V_198 . V_199 . V_219 . V_213 = V_213 ;
}
V_197 -> V_198 . V_199 . V_216 . V_63 = & V_2 -> V_63 . V_206 ;
V_197 -> V_198 . V_199 . V_216 . V_54 = ( V_207 ) V_45 ;
V_197 -> V_205 = 1 ;
if ( F_37 ( V_2 , V_45 ) )
F_9 ( L_8 ) ;
}
static void F_41 ( struct V_44 * V_45 , T_1 V_220 )
{
F_42 ( V_45 -> V_221 , V_220 ) ;
}
enum V_73 F_43 ( struct V_1 * V_2 ,
struct V_222 * V_223 ,
enum V_224 V_225 ,
enum V_226 V_227 ,
void * V_228 ,
bool V_229 )
{
struct V_230 * V_50 ;
struct V_46 * V_47 = & V_2 -> V_11 ;
struct V_231 * V_232 = & V_2 -> V_232 ;
enum V_73 V_74 ;
struct V_233 * V_234 = & V_2 -> V_63 ;
struct V_44 * V_45 ;
struct V_196 * V_197 ;
V_45 = F_35 ( V_234 , V_229 ) ;
if ( ! V_45 )
return V_235 ;
V_197 = & V_45 -> V_50 ;
V_50 = & V_197 -> V_198 . V_199 . V_236 . V_50 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_232 = & V_2 -> V_232 ;
V_50 -> V_237 = V_227 ;
V_50 -> V_238 = V_225 ;
if ( V_223 -> V_239 != 0xFFFF ) {
V_50 -> V_240 = true ;
V_50 -> V_239 = F_36 ( V_223 -> V_239 ) ;
} else {
V_50 -> V_240 = false ;
}
V_50 -> V_241 = V_223 -> V_210 ;
V_50 -> V_242 = V_223 -> V_242 ;
F_40 ( V_50 -> V_208 , V_2 -> V_243 -> V_244 ) ;
V_50 -> V_245 = F_44 ( V_232 -> V_246 -> V_247 ) ;
V_50 -> V_248 = F_36 ( V_223 -> V_249 ) ;
V_50 -> V_250 [ 0 ] = F_44 ( V_223 -> V_251 [ 0 ] ) ;
V_50 -> V_250 [ 1 ] = F_44 ( V_223 -> V_251 [ 1 ] ) ;
V_50 -> V_250 [ 2 ] = F_44 ( V_223 -> V_251 [ 2 ] ) ;
V_50 -> V_250 [ 3 ] = F_44 ( V_223 -> V_251 [ 3 ] ) ;
if ( V_225 == V_252 ) {
V_50 -> V_253 = F_36 ( V_223 -> V_254 ) ;
V_50 -> V_255 [ 0 ] = F_44 ( V_223 -> V_256 [ 0 ] ) ;
V_50 -> V_255 [ 1 ] = F_44 ( V_223 -> V_256 [ 1 ] ) ;
V_50 -> V_255 [ 2 ] = F_44 ( V_223 -> V_256 [ 2 ] ) ;
V_50 -> V_255 [ 3 ] = F_44 ( V_223 -> V_256 [ 3 ] ) ;
}
if ( V_228 ) {
V_45 -> V_64 = F_41 ;
V_45 -> V_221 = ( void * ) V_228 ;
}
if ( V_50 -> V_241 )
F_20 ( V_47 , V_257 ,
L_9 ,
V_123 , ( ! V_227 ) ? L_10 : L_11 ,
V_50 -> V_250 ,
V_50 -> V_248 , V_50 -> V_208 , V_223 -> V_239 ) ;
else
F_20 ( V_47 , V_257 ,
L_12 ,
V_123 , ( ! V_227 ) ? L_10 : L_11 ,
V_50 -> V_250 ,
V_50 -> V_248 , V_50 -> V_208 , V_223 -> V_239 ) ;
V_197 -> V_198 . V_199 . V_236 . V_63 = & V_2 -> V_63 . V_206 ;
V_197 -> V_198 . V_199 . V_236 . V_54 = ( V_207 ) V_45 ;
V_197 -> V_203 = V_258 ;
V_197 -> V_205 = 1 ;
V_74 = F_37 ( V_2 , V_45 ) ;
if ( V_74 )
F_9 ( L_13 ) ;
return V_74 ;
}
enum V_73 F_45 ( struct V_1 * V_2 ,
struct V_113 * V_114 ,
struct V_259 * V_50 ,
bool V_229 )
{
enum V_73 V_74 ;
struct V_259 * V_260 ;
struct V_44 * V_45 ;
struct V_196 * V_197 ;
struct V_22 * V_88 = (struct V_22 * ) V_114 -> V_261 ;
V_45 = F_35 ( & V_2 -> V_63 , V_229 ) ;
if ( ! V_45 )
return V_235 ;
V_197 = & V_45 -> V_50 ;
V_260 = & V_45 -> V_50 . V_198 . V_199 . V_262 . V_50 ;
memcpy ( V_260 , V_50 , sizeof( * V_260 ) ) ;
V_197 -> V_203 = V_263 ;
V_197 -> V_205 = 1 ;
V_197 -> V_198 . V_199 . V_262 . V_114 = V_114 ;
V_197 -> V_198 . V_199 . V_262 . V_54 = ( V_207 ) V_45 ;
V_74 = F_37 ( V_2 , V_45 ) ;
if ( V_74 ) {
F_9 ( L_14 ) ;
F_46 ( & V_88 -> V_264 ) ;
F_46 ( & V_88 -> V_265 ) ;
return V_74 ;
}
if ( ! V_45 -> V_58 . V_56 ) {
switch ( V_45 -> V_58 . V_57 ) {
case V_266 :
F_46 ( & V_88 -> V_264 ) ;
break;
case V_267 :
F_46 ( & V_88 -> V_265 ) ;
break;
case V_268 :
break;
default:
F_46 ( & V_88 -> V_264 ) ;
F_46 ( & V_88 -> V_265 ) ;
break;
}
}
return 0 ;
}
enum V_73 F_47 ( struct V_1 * V_2 ,
struct V_269 * V_50 ,
bool V_229 )
{
enum V_73 V_74 ;
struct V_269 * V_260 ;
struct V_44 * V_45 ;
struct V_196 * V_197 ;
if ( ( V_2 -> V_270 < V_271 ) && V_229 )
V_229 = false ;
V_45 = F_35 ( & V_2 -> V_63 , V_229 ) ;
if ( ! V_45 )
return V_235 ;
V_197 = & V_45 -> V_50 ;
V_260 = & V_45 -> V_50 . V_198 . V_199 . V_272 . V_50 ;
memcpy ( V_260 , V_50 , sizeof( * V_260 ) ) ;
V_197 -> V_203 = V_273 ;
V_197 -> V_205 = 1 ;
V_197 -> V_198 . V_199 . V_272 . V_63 = & V_2 -> V_63 . V_206 ;
V_197 -> V_198 . V_199 . V_272 . V_54 = ( V_207 ) V_45 ;
V_74 = F_37 ( V_2 , V_45 ) ;
if ( V_74 )
F_9 ( L_15 ) ;
return V_74 ;
}
static enum V_274 F_48 ( enum V_275 V_276 )
{
switch ( V_276 ) {
case V_277 :
return V_278 ;
case V_279 :
return V_280 ;
case V_281 :
return V_282 ;
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
case V_287 :
return V_288 ;
case V_289 :
default:
return V_290 ;
}
}
static void F_49 ( struct V_259 * V_291 ,
T_3 * V_292 ,
T_3 * V_293 ,
enum V_275 V_276 )
{
* V_292 = ( T_3 ) F_48 ( V_276 ) ;
* V_293 = V_294 ;
V_291 -> V_295 = true ;
}
void F_50 ( struct V_1 * V_2 , struct V_22 * V_88 )
{
struct V_259 V_50 ;
struct V_259 * V_291 = & V_50 ;
struct V_113 * V_114 = & V_88 -> V_102 ;
memset ( V_291 , 0 , sizeof( * V_291 ) ) ;
V_50 . V_183 = true ;
V_50 . V_296 = true ;
if ( V_114 -> V_103 ) {
F_49 ( V_291 , & V_291 -> V_297 ,
& V_291 -> V_298 , V_114 -> V_299 ) ;
F_49 ( V_291 , & V_291 -> V_300 ,
& V_291 -> V_301 , V_114 -> V_299 ) ;
}
( void ) F_45 ( V_2 , & V_88 -> V_102 , & V_50 , true ) ;
}
