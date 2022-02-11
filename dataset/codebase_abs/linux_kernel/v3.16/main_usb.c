static void
F_1 ( struct V_1 * V_2 ) {
T_1 V_3 [ V_4 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_5 [ V_4 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_1 V_6 [ V_4 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0xF8 } ;
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
memcpy ( V_2 -> V_5 , V_5 , V_4 ) ;
memcpy ( V_2 -> V_6 , V_6 , V_4 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = V_32 ;
if ( V_2 -> V_31 < V_33 ) V_2 -> V_34 = true ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = V_2 -> V_35 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = false ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_44 ;
struct V_45 * V_46 = & V_2 -> V_47 ;
struct V_48 * V_49 = & V_2 -> V_50 ;
T_1 V_3 [ V_4 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_5 [ V_4 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_1 V_6 [ V_4 ]
= { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0xf8 } ;
T_1 V_51 ;
int V_52 ;
int V_53 = V_54 ;
T_1 V_55 ;
T_1 V_56 = 0 , V_57 = 0 , V_58 = 0 ;
F_3 ( V_59 , V_60 L_1 ,
V_61 , V_2 -> V_37 ) ;
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
memcpy ( V_2 -> V_5 , V_5 , V_4 ) ;
memcpy ( V_2 -> V_6 , V_6 , V_4 ) ;
if ( ! F_4 ( V_2 ) ) {
if ( F_5 ( V_2 ) == true ) {
if ( F_6 ( V_2 ) == false ) {
F_3 ( V_59 , V_60
L_2 ) ;
return false ;
}
} else {
F_3 ( V_59 , V_60
L_3 ) ;
return false ;
}
}
if ( ! F_7 ( V_2 ) ) {
F_3 ( V_59 , V_60 L_4 ) ;
return false ;
}
V_46 -> V_62 = V_61 ;
V_46 -> V_63 = ( T_1 ) V_2 -> V_41 ;
for ( V_52 = 0 ; V_52 < 6 ; V_52 ++ )
V_46 -> V_64 [ V_52 ] = V_2 -> V_65 [ V_52 ] ;
V_46 -> V_66 = V_2 -> V_17 ;
V_46 -> V_67 = V_2 -> V_19 ;
V_53 = F_8 ( V_2 ,
V_68 , 0 , 0 ,
sizeof( struct V_45 ) , ( T_1 * ) V_46 ) ;
if ( V_53 != V_54 ) {
F_3 ( V_59 , V_60 L_5 ) ;
return false ;
}
V_53 = F_9 ( V_2 , V_69 , 0 , 0 ,
sizeof( struct V_48 ) , ( T_1 * ) V_49 ) ;
if ( V_53 != V_54 ) {
F_3 ( V_59 , V_60
L_6 ) ;
return false ;
}
V_53 = F_9 ( V_2 , V_70 ,
V_71 , V_72 , 1 ,
& V_2 -> V_73 ) ;
if ( V_53 != V_54 )
return false ;
V_2 -> V_74 = false ;
V_2 -> V_75 = false ;
V_2 -> V_76 = false ;
if ( V_2 -> V_34 ) {
V_2 -> V_77 = ( V_78 ) V_2 -> V_31 ;
} else {
if ( V_2 -> V_35 == V_79 )
V_2 -> V_77 = V_80 ;
else
V_2 -> V_77 = V_81 ;
}
F_10 ( V_2 ) ;
V_2 -> V_82 = V_83 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = 0xFF ;
V_2 -> V_87 = V_2 -> V_88 [ V_89 ] ;
V_2 -> V_90 = V_2 -> V_88 [ V_91 ] ;
for ( V_52 = 0 ; V_52 < 14 ; V_52 ++ ) {
V_2 -> V_92 [ V_52 ] =
V_2 -> V_88 [ V_52 + V_93 ] ;
if ( V_2 -> V_92 [ V_52 ] == 0 )
V_2 -> V_92 [ V_52 ] = V_2 -> V_87 ;
V_2 -> V_94 [ V_52 ] =
V_2 -> V_88 [ V_52 + V_95 ] ;
if ( V_2 -> V_94 [ V_52 ] == 0 )
V_2 -> V_94 [ V_52 ] = V_2 -> V_90 ;
}
if ( ( ( V_2 -> V_88 [ V_96 ] == V_97 ) ||
( V_2 -> V_88 [ V_96 ] == V_98 ) ) &&
( V_2 -> V_99 == V_100 ) ) {
for ( V_52 = 11 ; V_52 < 14 ; V_52 ++ ) {
V_2 -> V_92 [ V_52 ] = V_2 -> V_92 [ 10 ] ;
V_2 -> V_94 [ V_52 ] = V_2 -> V_94 [ 10 ] ;
}
}
V_2 -> V_101 = 0x34 ;
for ( V_52 = 0 ; V_52 < V_102 ; V_52 ++ ) {
V_2 -> V_103 [ V_52 ] =
V_2 -> V_88 [ V_52 + V_104 ] ;
if ( V_2 -> V_103 [ V_52 ] == 0 )
V_2 -> V_103 [ V_52 ] = V_2 -> V_101 ;
}
V_51 = V_2 -> V_88 [ V_105 ] ;
if ( V_51 & V_106 )
V_2 -> V_107 = true ;
else
V_2 -> V_107 = false ;
V_51 &= ( V_108 | V_109 ) ;
if ( V_51 == 0 )
V_51 = ( V_108 | V_109 ) ;
if ( V_51 == ( V_108 | V_109 ) ) {
V_2 -> V_110 = 2 ;
V_2 -> V_111 = V_112 ;
V_2 -> V_113 = 1 ;
V_2 -> V_114 = 1 ;
if ( V_2 -> V_107 == true )
V_2 -> V_115 = V_116 ;
else
V_2 -> V_115 = V_112 ;
} else {
V_2 -> V_110 = 1 ;
V_2 -> V_113 = 0 ;
V_2 -> V_114 = 0 ;
if ( V_51 & V_108 ) {
V_2 -> V_111 = V_116 ;
if ( V_2 -> V_107 == true )
V_2 -> V_115 = V_112 ;
else
V_2 -> V_115 = V_116 ;
} else {
V_2 -> V_111 = V_112 ;
if ( V_2 -> V_107 == true )
V_2 -> V_115 = V_116 ;
else
V_2 -> V_115 = V_112 ;
}
}
V_2 -> V_38 = V_39 ;
V_2 -> V_117 = V_118 ;
V_2 -> V_35 = V_119 ;
V_2 -> V_120 = 1 ;
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = V_49 -> V_124 ;
if ( V_2 -> V_123 == V_125 ) {
if ( ( V_2 -> V_88 [ V_126 ] == 0x1 ) &&
( V_2 -> V_88 [ V_127 ] >= 0x4 ) ) {
V_56 = V_2 -> V_88 [ V_128 ] ;
V_57 = V_2 -> V_88 [ V_129 ] ;
V_58 = V_2 -> V_88 [ V_130 ] ;
if ( V_56 || V_57 || V_58 ) {
F_11 ( V_2 ,
V_131 ,
0xff ,
0x03 ) ;
F_11 ( V_2 ,
V_131 ,
0xfb ,
V_56 ) ;
F_11 ( V_2 ,
V_131 ,
0xfC ,
V_57 ) ;
F_11 ( V_2 ,
V_131 ,
0xfd ,
V_58 ) ;
} else {
F_11 ( V_2 ,
V_131 ,
0xff ,
0x0 ) ;
}
}
}
V_43 -> V_132 = V_133 ;
V_43 -> V_134 = V_2 -> V_11 ;
V_43 -> V_135 = V_2 -> V_11 ;
F_12 ( V_2 , V_43 -> V_134 ) ;
memcpy ( V_2 -> V_136 , V_49 -> V_137 , 6 ) ;
memcpy ( V_2 -> V_65 ,
V_2 -> V_136 , V_4 ) ;
F_3 ( V_59 , V_60 L_7 ,
V_2 -> V_65 ) ;
if ( V_2 -> V_35 == V_138 ) {
F_13 ( V_2 , V_139 ) ;
V_2 -> V_140 = true ;
} else {
F_13 ( V_2 , V_85 ) ;
V_2 -> V_140 = false ;
}
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_2 -> V_141 = V_2 -> V_142 [ 0 ] ;
V_2 -> V_143 = V_2 -> V_141 ;
F_16 ( V_2 , V_2 -> V_142 [ 0 ] ) ;
V_2 -> V_144 = V_2 -> V_88 [ V_145 ] ;
V_2 -> V_146 = false ;
if ( ( V_2 -> V_144 & V_147 ) != 0 ) {
V_53 = F_9 ( V_2 , V_70 ,
V_148 , V_72 , 1 , & V_55 ) ;
if ( V_53 != V_54 )
return false ;
if ( ( V_55 & V_149 ) == 0 ) {
V_2 -> V_146 = true ;
F_17 ( V_2 , V_148 , V_150 ) ;
} else {
F_18 ( V_2 , V_148 , V_150 ) ;
V_2 -> V_146 = false ;
}
}
F_19 ( V_2 , V_151 , 0x38 ) ;
F_19 ( V_2 , V_152 , V_153 ) ;
F_17 ( V_2 , V_154 , 0x01 ) ;
if ( ( V_2 -> V_146 == true ) ||
( V_2 -> V_155 == true ) ) {
F_20 ( V_2 ) ;
} else {
F_21 ( V_2 ) ;
}
F_3 ( V_59 , V_60 L_8 ) ;
return true ;
}
static int F_22 ( struct V_156 * V_157 , T_2 V_158 )
{
struct V_1 * V_159 = F_23 ( V_157 ) ;
if ( ! V_159 || ! V_159 -> V_160 )
return - V_161 ;
if ( V_159 -> V_162 & V_163 )
F_24 ( V_159 -> V_160 ) ;
return 0 ;
}
static int F_25 ( struct V_156 * V_157 )
{
struct V_1 * V_159 = F_23 ( V_157 ) ;
if ( ! V_159 || ! V_159 -> V_160 )
return - V_161 ;
if ( ! ( V_159 -> V_162 & V_163 ) )
F_26 ( V_159 -> V_160 ) ;
return 0 ;
}
static int
F_27 ( struct V_156 * V_157 , const struct V_164 * V_165 )
{
T_1 V_166 [ V_4 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ;
struct V_167 * V_168 = F_28 ( V_157 ) ;
int V_169 = 0 ;
struct V_170 * V_171 = NULL ;
struct V_1 * V_2 ;
F_29 ( V_172 L_9 , V_173 , V_174 ) ;
F_29 ( V_172 L_10 ) ;
V_168 = F_30 ( V_168 ) ;
V_171 = F_31 ( sizeof( struct V_1 ) ) ;
if ( ! V_171 ) {
F_29 (KERN_ERR DEVICE_NAME L_11 ) ;
V_169 = - V_175 ;
goto V_176;
}
V_2 = F_32 ( V_171 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_160 = V_171 ;
V_2 -> V_177 = V_168 ;
F_1 ( V_2 ) ;
F_33 ( & V_2 -> V_178 ) ;
F_34 ( & V_2 -> V_179 ) ;
F_35 ( & V_2 -> V_180 , V_181 ) ;
F_35 ( & V_2 -> V_182 , V_183 ) ;
F_36 ( & V_2 -> V_184 , V_185 ) ;
F_36 ( & V_2 -> V_186 , V_187 ) ;
V_2 -> V_44 . V_188 = ( void * ) V_2 ;
V_171 -> V_189 = & V_190 ;
V_171 -> V_191 =
(struct V_192 * ) & V_193 ;
F_37 ( V_157 , V_2 ) ;
F_38 ( V_171 , & V_157 -> V_160 ) ;
memcpy ( V_2 -> V_160 -> V_194 , V_166 , V_4 ) ;
F_39 ( V_2 ) ;
V_169 = F_40 ( V_171 ) ;
if ( V_169 ) {
F_29 (KERN_ERR DEVICE_NAME L_12 ) ;
goto V_195;
}
return 0 ;
V_195:
F_41 ( V_171 ) ;
V_176:
F_42 ( V_168 ) ;
return V_169 ;
}
static void F_43 ( struct V_1 * V_196 )
{
struct V_197 * V_198 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_196 -> V_7 ; V_52 ++ ) {
V_198 = V_196 -> V_199 [ V_52 ] ;
if ( V_198 -> V_200 ) {
F_44 ( V_198 -> V_200 ) ;
F_45 ( V_198 -> V_200 ) ;
}
F_46 ( V_198 ) ;
}
return;
}
static void F_47 ( struct V_1 * V_196 )
{
struct V_201 * V_202 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_196 -> V_9 ; V_52 ++ ) {
V_202 = V_196 -> V_203 [ V_52 ] ;
if ( V_202 -> V_204 ) {
F_44 ( V_202 -> V_204 ) ;
F_45 ( V_202 -> V_204 ) ;
}
if ( V_202 -> V_205 )
F_48 ( V_202 -> V_205 ) ;
}
F_46 ( V_196 -> V_206 ) ;
return;
}
static void F_39 ( struct V_1 * V_2 )
{
int V_207 ;
V_207 = F_49 ( V_2 -> V_177 ) ;
if ( V_207 )
F_29 ( L_13 , V_207 ) ;
return ;
}
static void F_50 ( struct V_1 * V_196 )
{
F_46 ( V_196 -> V_208 . V_209 ) ;
return;
}
static bool F_51 ( struct V_1 * V_196 )
{
struct V_197 * V_198 ;
struct V_201 * V_202 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_196 -> V_7 ; V_52 ++ ) {
V_198 = F_52 ( sizeof( struct V_197 ) ,
V_210 ) ;
if ( V_198 == NULL ) {
F_3 ( V_211 , V_212
L_14 ,
V_196 -> V_160 -> V_213 ) ;
goto V_214;
}
V_196 -> V_199 [ V_52 ] = V_198 ;
V_198 -> V_196 = V_196 ;
V_198 -> V_200 = F_53 ( 0 , V_215 ) ;
if ( ! V_198 -> V_200 ) {
F_3 ( V_211 ,
V_212 L_15 ) ;
goto V_214;
}
V_198 -> V_216 = false ;
}
V_196 -> V_206 = F_54 ( ( sizeof( struct V_201 ) * V_196 -> V_9 ) ,
V_210 ) ;
if ( V_196 -> V_206 == NULL ) {
F_3 ( V_211 , V_212
L_16 ,
V_196 -> V_160 -> V_213 ) ;
goto V_214;
}
V_196 -> V_217 = NULL ;
V_196 -> V_218 = NULL ;
V_196 -> V_219 = NULL ;
V_196 -> V_220 = NULL ;
V_196 -> V_221 = 0 ;
V_202 = (struct V_201 * ) V_196 -> V_206 ;
for ( V_52 = 0 ; V_52 < V_196 -> V_9 ; V_52 ++ ) {
V_196 -> V_203 [ V_52 ] = V_202 ;
V_202 -> V_2 = V_196 ;
V_202 -> V_204 = F_53 ( 0 , V_215 ) ;
if ( V_202 -> V_204 == NULL ) {
F_3 ( V_211 , V_212
L_17 ) ;
goto V_222;
}
V_202 -> V_205 = F_55 ( V_196 -> V_160 , V_196 -> V_223 ) ;
if ( V_202 -> V_205 == NULL ) {
F_3 ( V_211 , V_212
L_18 ) ;
goto V_222;
}
V_202 -> V_224 = false ;
F_56 ( V_196 -> V_217 ,
V_196 -> V_218 , V_202 ) ;
V_196 -> V_221 ++ ;
V_202 ++ ;
}
V_196 -> V_225 = F_53 ( 0 , V_215 ) ;
if ( V_196 -> V_225 == NULL ) {
F_3 ( V_211 , V_212 L_19 ) ;
goto V_222;
}
V_196 -> V_208 . V_209 = F_52 ( V_226 , V_210 ) ;
if ( V_196 -> V_208 . V_209 == NULL ) {
F_3 ( V_211 , V_212 L_20 ) ;
F_45 ( V_196 -> V_225 ) ;
goto V_222;
}
return true ;
V_222:
F_47 ( V_196 ) ;
V_214:
F_43 ( V_196 ) ;
return false ;
}
static bool F_57 ( struct V_1 * V_2 )
{
int V_227 ;
T_3 V_228 ;
for ( V_227 = 0 ; V_227 < V_229 ; V_227 ++ ) {
V_228 = & ( V_2 -> V_230 [ V_227 ] ) ;
if ( ! F_58 ( V_2 , V_228 ) ) {
F_3 ( V_211 , V_212 L_21 ,
V_2 -> V_160 -> V_213 ) ;
goto V_231;
}
}
V_2 -> V_232 = V_229 ;
V_2 -> V_233 = V_2 -> V_232 ;
return true ;
V_231:
F_59 ( V_2 ) ;
return false ;
}
static void F_59 ( struct V_1 * V_2 )
{
T_3 V_228 ;
int V_227 ;
for ( V_227 = 0 ; V_227 < V_229 ; V_227 ++ ) {
V_228 = & ( V_2 -> V_230 [ V_227 ] ) ;
if ( V_228 -> V_205 )
F_48 ( V_228 -> V_205 ) ;
}
}
int F_58 ( struct V_1 * V_2 ,
T_3 V_228 )
{
V_228 -> V_205 = F_55 ( V_2 -> V_160 , V_2 -> V_223 ) ;
if ( ! V_228 -> V_205 )
return false ;
return true ;
}
static int F_26 ( struct V_170 * V_160 )
{
struct V_1 * V_2 = F_32 ( V_160 ) ;
V_2 -> V_234 = false ;
F_3 ( V_59 , V_60 L_22 ) ;
V_2 -> V_223 = V_235 ;
if ( F_51 ( V_2 ) == false ) {
F_3 ( V_59 , V_60 L_23 ) ;
return - V_175 ;
}
if ( F_57 ( V_2 ) == false ) {
F_3 ( V_59 , V_60 L_24 ) ;
goto V_222;
}
F_60 ( V_2 , V_236 ) ;
F_61 ( V_2 , V_237 ) ;
F_61 ( V_2 , V_238 ) ;
F_62 ( V_2 ) ;
if ( F_2 ( V_2 ) == false ) {
F_3 ( V_59 , V_60 L_25 ) ;
goto V_239;
}
F_63 ( V_2 , & V_2 -> V_240 ) ;
memcpy ( V_2 -> V_44 . V_241 ,
V_2 -> V_65 , V_4 ) ;
memcpy ( V_2 -> V_160 -> V_194 , V_2 -> V_65 , V_4 ) ;
V_2 -> V_242 = false ;
V_2 -> V_243 = false ;
V_2 -> V_244 = false ;
V_2 -> V_245 = false ;
V_2 -> V_246 = false ;
F_64 ( V_2 ) ;
F_65 ( & V_2 -> V_182 , V_247 ) ;
V_2 -> V_248 = 1 ;
V_2 -> V_249 = V_250 ;
V_2 -> V_251 = true ;
V_2 -> V_252 = false ;
V_2 -> V_253 = false ;
V_2 -> V_254 = false ;
V_2 -> V_255 = false ;
V_2 -> V_256 = false ;
V_2 -> V_257 = false ;
V_2 -> V_258 = 0 ;
F_66 ( & V_2 -> V_184 ) ;
F_67 ( V_2 ) ;
if ( ( V_2 -> V_259 == true ) && ( V_2 -> V_260 == true ) ) {
F_68 ( V_2 ,
& ( V_2 -> V_240 ) ,
V_2 -> V_261 | ( 1 << 31 ) ,
V_2 -> V_262 ,
NULL ,
V_2 -> V_263 ,
V_264
) ;
V_2 -> V_249 = V_265 ;
}
if ( V_2 -> V_44 . V_266 == V_267 )
F_69 ( ( void * ) V_2 , V_268 , NULL ) ;
else
F_69 ( ( void * ) V_2 , V_269 , NULL ) ;
F_70 ( V_2 -> V_160 ) ;
V_2 -> V_162 |= V_163 ;
F_3 ( V_59 , V_60 L_26 ) ;
return 0 ;
V_239:
F_59 ( V_2 ) ;
V_222:
F_47 ( V_2 ) ;
F_43 ( V_2 ) ;
F_50 ( V_2 ) ;
F_44 ( V_2 -> V_225 ) ;
F_45 ( V_2 -> V_225 ) ;
F_3 ( V_59 , V_60 L_27 ) ;
return - V_175 ;
}
static int F_24 ( struct V_170 * V_160 )
{
struct V_1 * V_2 = F_32 ( V_160 ) ;
struct V_42 * V_43 = & V_2 -> V_44 ;
T_1 V_270 ;
F_3 ( V_59 , V_60 L_28 ) ;
if ( V_2 == NULL )
return - V_161 ;
if ( V_2 -> V_271 ) {
F_69 ( ( void * ) V_2 , V_272 , NULL ) ;
F_71 ( 30 ) ;
}
memset ( V_43 -> V_273 , 0 , V_274 + V_275 + 1 ) ;
V_43 -> V_276 = false ;
V_2 -> V_259 = false ;
V_2 -> V_249 = V_250 ;
for ( V_270 = 0 ; V_270 < V_277 ; V_270 ++ )
F_72 ( V_2 , V_270 ) ;
if ( ( V_2 -> V_162 & V_278 ) == false ) {
F_73 ( V_2 ) ;
}
F_70 ( V_2 -> V_160 ) ;
F_61 ( V_2 , V_236 ) ;
F_60 ( V_2 , V_238 ) ;
F_60 ( V_2 , V_237 ) ;
F_74 ( & V_2 -> V_180 ) ;
F_74 ( & V_2 -> V_182 ) ;
F_75 ( & V_2 -> V_186 ) ;
F_75 ( & V_2 -> V_184 ) ;
V_2 -> V_244 = false ;
V_2 -> V_245 = false ;
V_2 -> V_246 = false ;
V_2 -> V_279 = false ;
V_2 -> V_271 = false ;
memset ( V_43 -> V_280 , 0 , 6 ) ;
V_43 -> V_281 = V_282 ;
V_2 -> V_162 &= ~ V_163 ;
F_43 ( V_2 ) ;
F_47 ( V_2 ) ;
F_50 ( V_2 ) ;
F_59 ( V_2 ) ;
F_44 ( V_2 -> V_225 ) ;
F_45 ( V_2 -> V_225 ) ;
F_76 ( V_2 , 0 ) ;
F_3 ( V_59 , V_60 L_29 ) ;
return 0 ;
}
static void F_77 ( struct V_156 * V_157 )
{
struct V_1 * V_159 = F_23 ( V_157 ) ;
if ( ! V_159 )
return;
F_37 ( V_157 , NULL ) ;
F_42 ( F_28 ( V_157 ) ) ;
V_159 -> V_162 |= V_278 ;
if ( V_159 -> V_160 ) {
F_78 ( V_159 -> V_160 ) ;
F_41 ( V_159 -> V_160 ) ;
}
}
static int F_79 ( struct V_283 * V_205 , struct V_170 * V_160 )
{
struct V_1 * V_2 = F_32 ( V_160 ) ;
struct V_284 * V_285 = & V_2 -> V_285 ;
unsigned long V_162 ;
F_80 ( & V_2 -> V_178 , V_162 ) ;
F_70 ( V_160 ) ;
if ( ! V_2 -> V_271 ) {
F_81 ( V_205 ) ;
goto V_286;
}
if ( V_2 -> V_243 ) {
F_81 ( V_205 ) ;
V_285 -> V_287 ++ ;
goto V_286;
}
if ( F_82 ( V_2 , V_205 ) ) {
if ( F_83 ( V_160 ) )
F_84 ( V_160 ) ;
}
V_286:
F_85 ( & V_2 -> V_178 , V_162 ) ;
return V_288 ;
}
static unsigned char * F_86 ( const unsigned char * V_289 ,
const unsigned char * V_290 ) {
int V_291 = strlen ( V_289 ) ;
int V_292 = strlen ( V_290 ) ;
while ( V_291 >= V_292 ) {
V_291 -- ;
if( memcmp ( V_289 , V_290 , V_292 ) == 0 )
return ( unsigned char * ) V_289 ;
V_289 ++ ;
}
return NULL ;
}
static int F_87 ( unsigned char * string ,
unsigned char * V_293 ,
unsigned char * V_294 )
{
unsigned char V_295 [ 100 ] ;
unsigned char V_296 [ 100 ] ;
unsigned char * V_297 = NULL , * V_298 = NULL , * V_299 = NULL ;
int V_52 ;
memset ( V_295 , 0 , 100 ) ;
strcat ( V_295 , string ) ;
strcat ( V_295 , L_30 ) ;
V_294 += strlen ( V_295 ) ;
V_297 = F_86 ( V_294 , V_295 ) ;
if ( V_297 == NULL )
return false ;
for ( V_52 = 1 ; ; V_52 ++ ) {
if ( memcmp ( V_297 - V_52 , L_31 , 1 ) == 0 )
break;
if ( memcmp ( V_297 - V_52 , L_32 , 1 ) == 0 )
return false ;
}
V_298 = F_86 ( V_297 , L_31 ) ;
if ( V_298 == NULL ) {
V_298 = V_297 + strlen ( V_297 ) ;
}
memset ( V_296 , 0 , 100 ) ;
memcpy ( V_296 , V_297 , V_298 - V_297 ) ;
V_296 [ V_298 - V_297 ] = '\0' ;
V_297 = F_86 ( V_296 , L_30 ) ;
if ( V_297 == NULL )
return false ;
memset ( V_295 , 0 , 100 ) ;
strcpy ( V_295 , V_297 + 1 ) ;
V_299 = V_295 ;
while( * V_299 != 0x00 ) {
if( * V_299 == ' ' )
V_299 ++ ;
else
break;
}
memcpy ( V_293 , V_299 , strlen ( V_299 ) ) ;
return true ;
}
static unsigned char * F_88 ( struct V_1 * V_2 )
{
unsigned char * V_300 = F_52 ( 1024 , V_210 ) ;
struct V_301 * V_301 ;
if ( ! V_300 ) {
F_29 ( L_33 ) ;
return NULL ;
}
V_301 = F_89 ( V_302 , V_303 , 0 ) ;
if ( F_90 ( V_301 ) ) {
F_46 ( V_300 ) ;
F_29 ( L_34 ) ;
return NULL ;
}
if ( F_91 ( V_301 , 0 , V_300 , 1024 ) < 0 ) {
F_29 ( L_35 ) ;
F_46 ( V_300 ) ;
V_300 = NULL ;
}
F_92 ( V_301 ) ;
return V_300 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_304 = 0 ;
unsigned char V_305 [ 100 ] ;
unsigned char * V_300 = NULL ;
V_2 -> V_306 . V_307 = - 1 ;
V_2 -> V_306 . V_308 = - 1 ;
V_2 -> V_306 . V_249 = - 1 ;
V_300 = F_88 ( V_2 ) ;
if ( V_300 == NULL ) {
V_304 = - 1 ;
return V_304 ;
}
{
memset ( V_305 , 0 , sizeof( V_305 ) ) ;
if( F_87 ( L_36 , V_305 , V_300 ) == true ) {
if( memcmp ( V_305 , L_37 , 3 ) == 0 ) {
V_2 -> V_306 . V_307 = V_100 ;
}
else if( memcmp ( V_305 , L_38 , 5 ) == 0 ) {
V_2 -> V_306 . V_307 = V_97 ;
}
else if( memcmp ( V_305 , L_39 , 6 ) == 0 ) {
V_2 -> V_306 . V_307 = V_98 ;
}
else {
F_29 ( L_40 , V_305 ) ;
}
}
}
{
memset ( V_305 , 0 , sizeof( V_305 ) ) ;
if( F_87 ( L_41 , V_305 , V_300 ) == true ) {
V_2 -> V_306 . V_308 = ( int ) F_93 ( V_305 , NULL , 10 ) ;
}
memset ( V_305 , 0 , sizeof( V_305 ) ) ;
if( F_87 ( L_42 , V_305 , V_300 ) == true ) {
V_2 -> V_306 . V_249 = ( int ) F_93 ( V_305 , NULL , 10 ) ;
}
}
F_46 ( V_300 ) ;
return V_304 ;
}
static void F_94 ( struct V_170 * V_160 )
{
struct V_1 * V_196 = F_32 ( V_160 ) ;
unsigned long V_162 ;
if ( V_196 -> V_162 & V_163 ) {
F_80 ( & V_196 -> V_178 , V_162 ) ;
F_69 ( V_196 , V_309 , NULL ) ;
F_85 ( & V_196 -> V_178 , V_162 ) ;
}
}
void F_95 ( struct V_1 * V_196 )
{
struct V_170 * V_160 = V_196 -> V_160 ;
struct V_42 * V_310 = & V_196 -> V_44 ;
struct V_311 * V_312 ;
T_4 V_313 = 0 ;
T_1 V_314 = 0 ;
int V_169 ;
V_169 = F_9 ( V_196 , V_70 ,
V_315 , V_72 , 1 , & V_314 ) ;
if ( V_169 == 0 )
V_196 -> V_316 = V_314 ;
F_3 ( V_59 , V_60 L_43 ,
V_196 -> V_316 ) ;
if ( V_160 -> V_162 & V_317 ) {
F_3 ( V_211 , V_172
L_44 , V_160 -> V_213 ) ;
V_196 -> V_316 |= ( V_318 | V_319 | V_320 ) ;
} else if ( ( F_96 ( V_160 ) > V_196 -> V_321 ) ||
( V_160 -> V_162 & V_322 ) ) {
V_313 = ~ 0x0 ;
F_97 ( V_196 , V_313 ) ;
V_196 -> V_316 |= ( V_318 | V_319 ) ;
} else {
F_98 (ha, dev) {
int V_323 = F_99 ( V_4 , V_312 -> V_324 ) >> 26 ;
V_313 |= 1ULL << ( V_323 & 0x3f ) ;
}
F_97 ( V_196 , V_313 ) ;
V_196 -> V_316 &= ~ ( V_320 ) ;
V_196 -> V_316 |= ( V_318 | V_319 ) ;
}
if ( V_310 -> V_266 == V_267 ) {
V_196 -> V_316 |= ( V_318 | V_319 ) ;
V_196 -> V_316 &= ~ ( V_320 ) ;
}
F_11 ( V_196 , V_72 ,
V_315 , V_196 -> V_316 ) ;
F_3 ( V_59 , V_60
L_45 , V_196 -> V_316 ) ;
}
static struct V_284 * F_100 ( struct V_170 * V_160 )
{
struct V_1 * V_2 = F_32 ( V_160 ) ;
return & V_2 -> V_285 ;
}
static int F_101 ( struct V_170 * V_160 , struct V_325 * V_326 , int V_327 )
{
int V_169 = 0 ;
switch ( V_327 ) {
case V_328 :
return F_102 ( V_160 , V_326 ) ;
}
return V_169 ;
}
static int F_102 ( struct V_170 * V_160 , struct V_325 * V_326 )
{
T_5 V_329 ;
if ( F_103 ( & V_329 , V_326 -> V_330 , sizeof( V_329 ) ) )
return - V_331 ;
switch ( V_329 ) {
case V_332 : {
struct V_333 V_334 = { V_332 } ;
strncpy ( V_334 . V_335 , V_336 , sizeof( V_334 . V_335 ) - 1 ) ;
strncpy ( V_334 . V_337 , V_174 , sizeof( V_334 . V_337 ) - 1 ) ;
if ( F_104 ( V_326 -> V_330 , & V_334 , sizeof( V_334 ) ) )
return - V_331 ;
return 0 ;
}
}
return - V_338 ;
}
