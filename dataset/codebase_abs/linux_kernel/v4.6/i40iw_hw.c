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
V_9 = 24 - F_6 ( V_2 -> V_5 ) ;
V_2 -> V_38 = ~ ( ( ( 1 << V_9 ) - 1 ) << ( 32 - V_9 ) ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_39 * V_40 , bool V_41 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 = & V_2 -> V_11 ;
T_1 V_46 = 0 ;
struct V_47 V_48 ;
int V_49 ;
do {
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_49 = V_45 -> V_50 -> V_51 ( V_40 , & V_48 ) ;
if ( V_49 )
break;
V_43 = (struct V_42 * ) ( unsigned long ) V_48 . V_52 ;
if ( V_48 . error )
F_8 ( L_1 ,
V_48 . V_53 , V_48 . V_54 , V_48 . V_55 ) ;
if ( V_43 ) {
V_43 -> V_56 . V_54 = V_48 . V_54 ;
V_43 -> V_56 . V_55 = V_48 . V_55 ;
V_43 -> V_56 . V_57 = V_48 . V_57 ;
V_43 -> V_56 . error = V_48 . error ;
if ( V_43 -> V_58 ) {
V_43 -> V_59 = true ;
F_9 ( & V_43 -> V_60 ) ;
F_10 ( & V_2 -> V_61 , V_43 ) ;
} else {
if ( V_43 -> V_62 )
V_43 -> V_62 ( V_43 , 1 ) ;
F_10 ( & V_2 -> V_61 , V_43 ) ;
}
}
V_46 ++ ;
} while ( 1 );
if ( V_41 && V_46 ) {
F_11 ( V_45 ) ;
V_45 -> V_50 -> V_63 ( V_40 ) ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_39 * V_64 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
if ( V_66 -> V_68 . V_69 )
V_66 -> V_68 . V_69 ( & V_66 -> V_68 ,
V_66 -> V_68 . V_70 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_44 * V_45 = (struct V_44 * ) & V_2 -> V_11 ;
enum V_71 V_72 ;
T_1 V_73 ;
do {
V_72 = F_14 ( V_45 , V_40 , & V_73 ) ;
if ( V_72 == V_74 )
break;
if ( V_72 ) {
F_8 ( L_2 , V_72 ) ;
break;
}
if ( V_73 ) {
F_8 ( L_3 , V_73 ) ;
break;
}
} while ( 1 );
V_45 -> V_50 -> V_63 ( V_40 ) ;
}
void F_15 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_44 * V_45 = & V_2 -> V_11 ;
struct V_77 * V_78 ;
struct V_39 * V_40 ;
bool V_41 = true ;
V_78 = & V_76 -> V_78 ;
do {
V_40 = V_45 -> V_79 -> V_80 ( V_45 , V_78 ) ;
if ( ! V_40 )
break;
if ( V_40 -> V_81 == V_82 )
F_7 ( V_2 , V_40 , V_41 ) ;
else if ( V_40 -> V_81 == V_83 )
F_12 ( V_2 , V_40 ) ;
else if ( ( V_40 -> V_81 == V_84 ) ||
( V_40 -> V_81 == V_85 ) )
F_13 ( V_2 , V_40 ) ;
} while ( 1 );
}
void F_16 ( struct V_21 * V_86 ,
T_2 V_87 ,
T_2 V_88 ,
T_2 V_89 ,
T_2 V_90 )
{
struct V_91 V_48 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_92 = V_87 ;
V_48 . V_93 = V_88 ;
V_48 . V_94 = true ;
V_48 . V_95 = true ;
V_48 . V_96 = true ;
V_48 . V_97 = true ;
V_48 . V_90 = V_90 ;
if ( V_89 & V_98 )
V_48 . V_96 = false ;
if ( V_89 & V_99 )
V_48 . V_97 = false ;
if ( V_86 -> V_100 . V_101 && ( V_87 == V_102 ) )
V_48 . V_103 = true ;
F_17 ( V_86 -> V_2 , V_86 , & V_48 , 0 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = & V_2 -> V_11 ;
struct V_104 * V_105 = & V_2 -> V_105 ;
struct V_106 * V_107 = & V_105 -> V_107 ;
struct V_108 V_109 ;
struct V_108 * V_48 = & V_109 ;
int V_49 ;
struct V_21 * V_86 = NULL ;
struct V_39 * V_40 = NULL ;
struct V_65 * V_64 = NULL ;
struct V_110 * V_111 = NULL ;
struct V_112 * V_113 = NULL ;
unsigned long V_114 ;
T_1 V_115 = 0 ;
if ( ! V_107 -> V_116 )
return;
do {
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_49 = V_45 -> V_117 -> V_118 ( V_107 , V_48 ) ;
if ( V_49 )
break;
V_115 ++ ;
F_19 ( V_45 , V_119 ,
L_4 ,
V_120 , V_48 -> V_121 , V_48 -> V_111 , V_48 -> V_122 ) ;
if ( V_48 -> V_111 ) {
V_86 = V_2 -> V_36 [ V_48 -> V_122 ] ;
if ( ! V_86 ) {
F_8 ( L_5 , V_48 -> V_122 ) ;
continue;
}
V_111 = & V_86 -> V_100 ;
F_20 ( & V_86 -> V_123 , V_114 ) ;
V_86 -> V_124 = V_48 -> V_125 ;
V_86 -> V_126 = V_48 -> V_127 ;
V_86 -> V_128 = V_48 -> V_121 ;
F_21 ( & V_86 -> V_123 , V_114 ) ;
V_113 = & V_86 -> V_113 ;
V_113 -> V_129 = true ;
} else {
if ( V_48 -> V_121 != V_130 )
continue;
}
switch ( V_48 -> V_121 ) {
case V_131 :
if ( V_111 -> V_101 )
continue;
if ( F_22 ( & V_86 -> V_132 ) == 1 ) {
V_86 -> V_124 = V_133 ;
if ( ( V_86 -> V_124 == V_133 ) &&
( V_86 -> V_134 == V_135 ) ) {
F_16 ( V_86 ,
V_136 , 0 , 0 , 0 ) ;
F_23 ( V_86 ) ;
}
V_86 -> V_137 -> V_138 ( V_86 -> V_137 ) ;
F_24 ( V_86 -> V_139 ,
(struct V_140 * ) V_86 ,
V_141 , 1 , 0 ) ;
}
break;
case V_142 :
if ( V_111 -> V_101 )
F_25 ( V_111 , 0 ) ;
else
F_23 ( V_86 ) ;
break;
case V_143 :
F_16 ( V_86 , V_102 , 1 , 0 , 0 ) ;
F_23 ( V_86 ) ;
break;
case V_144 :
if ( F_26 ( & V_86 -> V_132 ) )
continue;
F_23 ( V_86 ) ;
break;
case V_145 :
F_27 ( V_111 ) ;
break;
case V_146 :
F_28 ( V_111 , V_48 ) ;
break;
case V_130 :
F_8 ( L_6 ,
V_48 -> V_121 ) ;
V_40 = (struct V_39 * ) ( unsigned long ) V_48 -> V_147 ;
V_64 = (struct V_65 * ) V_40 -> V_67 ;
if ( V_64 -> V_68 . V_148 ) {
struct V_149 V_150 ;
V_150 . V_151 = V_64 -> V_68 . V_151 ;
V_150 . V_152 = V_153 ;
V_150 . V_154 . V_40 = & V_64 -> V_68 ;
V_64 -> V_68 . V_148 ( & V_150 , V_64 -> V_68 . V_70 ) ;
}
break;
case V_155 :
case V_156 :
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
V_113 -> V_129 = false ;
default:
if ( ! V_48 -> V_180 && V_113 -> V_129 ) {
V_113 -> V_181 = V_48 -> V_182 ;
V_113 -> V_183 = false ;
V_113 -> V_184 = false ;
V_49 = V_45 -> V_185 -> V_186 ( & V_86 -> V_100 ,
V_86 -> V_187 . V_188 ,
V_113 ) ;
}
F_29 ( V_111 , V_48 ) ;
break;
}
} while ( 1 );
if ( V_115 )
V_45 -> V_117 -> V_189 ( V_45 , V_115 ) ;
}
int F_30 ( struct V_1 * V_2 , T_3 V_190 , bool V_191 )
{
struct V_192 * V_48 ;
enum V_71 V_72 ;
struct V_42 * V_43 ;
struct V_193 * V_194 ;
V_43 = F_31 ( & V_2 -> V_61 , V_191 ) ;
if ( ! V_43 )
return - V_24 ;
V_194 = & V_43 -> V_48 ;
V_48 = & V_194 -> V_195 . V_196 . V_197 . V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_198 = V_191 ;
V_48 -> V_199 = F_32 ( V_190 ) ;
V_194 -> V_200 = V_201 ;
V_194 -> V_202 = 1 ;
V_194 -> V_195 . V_196 . V_197 . V_61 = & V_2 -> V_61 . V_203 ;
V_194 -> V_195 . V_196 . V_197 . V_52 = ( V_204 ) V_43 ;
V_72 = F_33 ( V_2 , V_43 ) ;
if ( V_72 )
F_8 ( L_7 ) ;
return V_72 ;
}
void F_34 ( struct V_1 * V_2 ,
unsigned char * V_205 ,
T_4 * V_206 ,
bool V_207 ,
T_1 V_208 )
{
struct V_209 * V_48 ;
struct V_42 * V_43 ;
struct V_193 * V_194 ;
int V_210 ;
V_210 = F_35 ( V_2 , V_206 , V_207 , V_205 , V_208 ) ;
if ( V_210 == - 1 )
return;
V_43 = F_31 ( & V_2 -> V_61 , false ) ;
if ( ! V_43 )
return;
V_194 = & V_43 -> V_48 ;
if ( V_208 == V_211 ) {
V_194 -> V_200 = V_212 ;
V_48 = & V_194 -> V_195 . V_196 . V_213 . V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_210 = F_36 ( V_210 ) ;
V_48 -> V_214 = true ;
F_37 ( V_48 -> V_205 , V_205 ) ;
V_194 -> V_195 . V_196 . V_213 . V_52 = ( V_204 ) V_43 ;
V_194 -> V_195 . V_196 . V_213 . V_61 = & V_2 -> V_61 . V_203 ;
} else {
V_194 -> V_200 = V_215 ;
V_194 -> V_195 . V_196 . V_216 . V_52 = ( V_204 ) V_43 ;
V_194 -> V_195 . V_196 . V_216 . V_61 = & V_2 -> V_61 . V_203 ;
V_194 -> V_195 . V_196 . V_216 . V_210 = V_210 ;
}
V_194 -> V_195 . V_196 . V_213 . V_61 = & V_2 -> V_61 . V_203 ;
V_194 -> V_195 . V_196 . V_213 . V_52 = ( V_204 ) V_43 ;
V_194 -> V_202 = 1 ;
if ( F_33 ( V_2 , V_43 ) )
F_8 ( L_8 ) ;
}
static void F_38 ( struct V_42 * V_43 , T_1 V_217 )
{
F_39 ( V_43 -> V_218 , V_217 ) ;
}
enum V_71 F_40 ( struct V_1 * V_2 ,
struct V_219 * V_220 ,
enum V_221 V_222 ,
enum V_223 V_224 ,
void * V_225 ,
bool V_226 )
{
struct V_227 * V_48 ;
struct V_44 * V_45 = & V_2 -> V_11 ;
enum V_71 V_72 ;
struct V_228 * V_229 = & V_2 -> V_61 ;
struct V_42 * V_43 ;
struct V_193 * V_194 ;
V_43 = F_31 ( V_229 , V_226 ) ;
if ( ! V_43 )
return V_230 ;
V_194 = & V_43 -> V_48 ;
V_48 = & V_194 -> V_195 . V_196 . V_231 . V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_232 = V_224 ;
V_48 -> V_233 = V_222 ;
if ( V_220 -> V_234 != 0xFFFF ) {
V_48 -> V_235 = true ;
V_48 -> V_234 = F_32 ( V_220 -> V_234 ) ;
} else {
V_48 -> V_235 = false ;
}
V_48 -> V_236 = V_220 -> V_207 ;
F_37 ( V_48 -> V_205 , V_2 -> V_237 -> V_238 ) ;
V_48 -> V_239 = F_36 ( V_45 -> V_240 -> V_241 ) ;
V_48 -> V_242 = F_32 ( V_220 -> V_243 ) ;
V_48 -> V_244 [ 0 ] = F_36 ( V_220 -> V_245 [ 0 ] ) ;
V_48 -> V_244 [ 1 ] = F_36 ( V_220 -> V_245 [ 1 ] ) ;
V_48 -> V_244 [ 2 ] = F_36 ( V_220 -> V_245 [ 2 ] ) ;
V_48 -> V_244 [ 3 ] = F_36 ( V_220 -> V_245 [ 3 ] ) ;
if ( V_222 == V_246 ) {
V_48 -> V_247 = F_32 ( V_220 -> V_248 ) ;
V_48 -> V_249 [ 0 ] = F_36 ( V_220 -> V_250 [ 0 ] ) ;
V_48 -> V_249 [ 1 ] = F_36 ( V_220 -> V_250 [ 1 ] ) ;
V_48 -> V_249 [ 2 ] = F_36 ( V_220 -> V_250 [ 2 ] ) ;
V_48 -> V_249 [ 3 ] = F_36 ( V_220 -> V_250 [ 3 ] ) ;
}
if ( V_225 ) {
V_43 -> V_62 = F_38 ;
V_43 -> V_218 = ( void * ) V_225 ;
}
if ( V_48 -> V_236 )
F_19 ( V_45 , V_251 ,
L_9 ,
V_120 , ( ! V_224 ) ? L_10 : L_11 ,
V_48 -> V_244 ,
V_48 -> V_242 , V_48 -> V_205 , V_220 -> V_234 ) ;
else
F_19 ( V_45 , V_251 ,
L_12 ,
V_120 , ( ! V_224 ) ? L_10 : L_11 ,
V_48 -> V_244 ,
V_48 -> V_242 , V_48 -> V_205 , V_220 -> V_234 ) ;
V_194 -> V_195 . V_196 . V_231 . V_61 = & V_2 -> V_61 . V_203 ;
V_194 -> V_195 . V_196 . V_231 . V_52 = ( V_204 ) V_43 ;
V_194 -> V_200 = V_252 ;
V_194 -> V_202 = 1 ;
V_72 = F_33 ( V_2 , V_43 ) ;
if ( V_72 )
F_8 ( L_13 ) ;
return V_72 ;
}
enum V_71 F_41 ( struct V_1 * V_2 ,
struct V_110 * V_111 ,
struct V_253 * V_48 ,
bool V_226 )
{
enum V_71 V_72 ;
struct V_253 * V_254 ;
struct V_42 * V_43 ;
struct V_193 * V_194 ;
V_43 = F_31 ( & V_2 -> V_61 , V_226 ) ;
if ( ! V_43 )
return V_230 ;
V_194 = & V_43 -> V_48 ;
V_254 = & V_43 -> V_48 . V_195 . V_196 . V_255 . V_48 ;
memcpy ( V_254 , V_48 , sizeof( * V_254 ) ) ;
V_194 -> V_200 = V_256 ;
V_194 -> V_202 = 1 ;
V_194 -> V_195 . V_196 . V_255 . V_111 = V_111 ;
V_194 -> V_195 . V_196 . V_255 . V_52 = ( V_204 ) V_43 ;
V_72 = F_33 ( V_2 , V_43 ) ;
if ( V_72 )
F_8 ( L_14 ) ;
return V_72 ;
}
enum V_71 F_42 ( struct V_1 * V_2 ,
struct V_257 * V_48 ,
bool V_226 )
{
enum V_71 V_72 ;
struct V_257 * V_254 ;
struct V_42 * V_43 ;
struct V_193 * V_194 ;
if ( ( V_2 -> V_258 < V_259 ) && V_226 )
V_226 = false ;
V_43 = F_31 ( & V_2 -> V_61 , V_226 ) ;
if ( ! V_43 )
return V_230 ;
V_194 = & V_43 -> V_48 ;
V_254 = & V_43 -> V_48 . V_195 . V_196 . V_260 . V_48 ;
memcpy ( V_254 , V_48 , sizeof( * V_254 ) ) ;
V_194 -> V_200 = V_261 ;
V_194 -> V_202 = 1 ;
V_194 -> V_195 . V_196 . V_260 . V_61 = & V_2 -> V_61 . V_203 ;
V_194 -> V_195 . V_196 . V_260 . V_52 = ( V_204 ) V_43 ;
V_72 = F_33 ( V_2 , V_43 ) ;
if ( V_72 )
F_8 ( L_15 ) ;
return V_72 ;
}
static enum V_262 F_43 ( enum V_263 V_264 )
{
switch ( V_264 ) {
case V_265 :
return V_266 ;
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
default:
return V_278 ;
}
}
static void F_44 ( struct V_253 * V_279 ,
T_3 * V_280 ,
T_3 * V_281 ,
enum V_263 V_264 )
{
* V_280 = ( T_3 ) F_43 ( V_264 ) ;
* V_281 = V_282 ;
V_279 -> V_283 = true ;
}
void F_45 ( struct V_1 * V_2 , struct V_21 * V_86 )
{
struct V_253 V_48 ;
struct V_253 * V_279 = & V_48 ;
struct V_110 * V_111 = & V_86 -> V_100 ;
memset ( V_279 , 0 , sizeof( * V_279 ) ) ;
V_48 . V_180 = true ;
V_48 . V_284 = true ;
if ( V_111 -> V_101 ) {
F_44 ( V_279 , & V_279 -> V_285 ,
& V_279 -> V_286 , V_111 -> V_287 ) ;
F_44 ( V_279 , & V_279 -> V_288 ,
& V_279 -> V_289 , V_111 -> V_287 ) ;
}
( void ) F_41 ( V_2 , & V_86 -> V_100 , & V_48 , true ) ;
}
