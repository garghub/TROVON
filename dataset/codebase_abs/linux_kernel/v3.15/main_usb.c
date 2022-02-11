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
V_2 -> V_40 = true ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = false ;
V_2 -> V_45 = false ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_46 ) ;
V_2 -> V_46 . V_47 = ( unsigned long ) V_2 ;
V_2 -> V_46 . V_48 = ( V_49 ) V_50 ;
V_2 -> V_46 . V_51 = F_4 ( V_52 ) ;
F_3 ( & V_2 -> V_53 ) ;
V_2 -> V_53 . V_47 = ( unsigned long ) V_2 ;
V_2 -> V_53 . V_48 = ( V_49 ) V_50 ;
V_2 -> V_53 . V_51 = F_4 ( V_52 ) ;
F_3 ( & V_2 -> V_54 ) ;
V_2 -> V_54 . V_47 = ( unsigned long ) V_2 ;
V_2 -> V_54 . V_48 = ( V_49 ) V_55 ;
V_2 -> V_54 . V_51 = F_4 ( V_52 ) ;
return;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = & V_2 -> V_58 ;
struct V_59 * V_60 = & V_2 -> V_61 ;
struct V_62 * V_63 = & V_2 -> V_64 ;
T_1 V_3 [ V_4 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_5 [ V_4 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_1 V_6 [ V_4 ]
= { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0xf8 } ;
T_1 V_65 ;
int V_66 ;
int V_67 = V_68 ;
T_1 V_69 ;
T_1 V_70 = 0 , V_71 = 0 , V_72 = 0 ;
F_6 ( V_73 , V_74 L_1 ,
V_75 , V_2 -> V_37 ) ;
F_7 ( & V_2 -> V_76 ) ;
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
memcpy ( V_2 -> V_5 , V_5 , V_4 ) ;
memcpy ( V_2 -> V_6 , V_6 , V_4 ) ;
if ( ! F_8 ( V_2 ) ) {
if ( F_9 ( V_2 ) == true ) {
if ( F_10 ( V_2 ) == false ) {
F_6 ( V_73 , V_74
L_2 ) ;
F_11 ( & V_2 -> V_76 ) ;
return false ;
}
} else {
F_6 ( V_73 , V_74
L_3 ) ;
F_11 ( & V_2 -> V_76 ) ;
return false ;
}
}
if ( ! F_12 ( V_2 ) ) {
F_6 ( V_73 , V_74 L_4 ) ;
F_11 ( & V_2 -> V_76 ) ;
return false ;
}
V_60 -> V_77 = V_75 ;
V_60 -> V_78 = ( T_1 ) V_2 -> V_44 ;
for ( V_66 = 0 ; V_66 < 6 ; V_66 ++ )
V_60 -> V_79 [ V_66 ] = V_2 -> V_80 [ V_66 ] ;
V_60 -> V_81 = V_2 -> V_17 ;
V_60 -> V_82 = V_2 -> V_19 ;
V_67 = F_13 ( V_2 ,
V_83 , 0 , 0 ,
sizeof( struct V_59 ) , ( T_1 * ) V_60 ) ;
if ( V_67 != V_68 ) {
F_6 ( V_73 , V_74 L_5 ) ;
F_11 ( & V_2 -> V_76 ) ;
return false ;
}
V_67 = F_14 ( V_2 , V_84 , 0 , 0 ,
sizeof( struct V_62 ) , ( T_1 * ) V_63 ) ;
if ( V_67 != V_68 ) {
F_6 ( V_73 , V_74
L_6 ) ;
F_11 ( & V_2 -> V_76 ) ;
return false ;
}
V_67 = F_14 ( V_2 , V_85 ,
V_86 , V_87 , 1 ,
& V_2 -> V_88 ) ;
if ( V_67 != V_68 ) {
F_11 ( & V_2 -> V_76 ) ;
return false ;
}
V_2 -> V_89 = true ;
V_2 -> V_90 = false ;
V_2 -> V_91 = false ;
V_2 -> V_92 = false ;
if ( V_2 -> V_34 ) {
V_2 -> V_93 = ( V_94 ) V_2 -> V_31 ;
} else {
if ( V_2 -> V_35 == V_95 )
V_2 -> V_93 = V_96 ;
else
V_2 -> V_93 = V_97 ;
}
F_15 ( V_2 ) ;
V_2 -> V_98 = V_99 ;
V_2 -> V_100 = V_101 ;
V_2 -> V_102 = 0 ;
V_2 -> V_103 = 0xFF ;
V_2 -> V_104 = V_2 -> V_105 [ V_106 ] ;
V_2 -> V_107 = V_2 -> V_105 [ V_108 ] ;
for ( V_66 = 0 ; V_66 < 14 ; V_66 ++ ) {
V_2 -> V_109 [ V_66 ] =
V_2 -> V_105 [ V_66 + V_110 ] ;
if ( V_2 -> V_109 [ V_66 ] == 0 )
V_2 -> V_109 [ V_66 ] = V_2 -> V_104 ;
V_2 -> V_111 [ V_66 ] =
V_2 -> V_105 [ V_66 + V_112 ] ;
if ( V_2 -> V_111 [ V_66 ] == 0 )
V_2 -> V_111 [ V_66 ] = V_2 -> V_107 ;
}
if ( ( ( V_2 -> V_105 [ V_113 ] == V_114 ) ||
( V_2 -> V_105 [ V_113 ] == V_115 ) ) &&
( V_2 -> V_116 == V_117 ) ) {
for ( V_66 = 11 ; V_66 < 14 ; V_66 ++ ) {
V_2 -> V_109 [ V_66 ] = V_2 -> V_109 [ 10 ] ;
V_2 -> V_111 [ V_66 ] = V_2 -> V_111 [ 10 ] ;
}
}
V_2 -> V_118 = 0x34 ;
for ( V_66 = 0 ; V_66 < V_119 ; V_66 ++ ) {
V_2 -> V_120 [ V_66 ] =
V_2 -> V_105 [ V_66 + V_121 ] ;
if ( V_2 -> V_120 [ V_66 ] == 0 )
V_2 -> V_120 [ V_66 ] = V_2 -> V_118 ;
}
V_65 = V_2 -> V_105 [ V_122 ] ;
if ( V_65 & V_123 )
V_2 -> V_124 = true ;
else
V_2 -> V_124 = false ;
V_65 &= ( V_125 | V_126 ) ;
if ( V_65 == 0 )
V_65 = ( V_125 | V_126 ) ;
if ( V_65 == ( V_125 | V_126 ) ) {
V_2 -> V_127 = 2 ;
V_2 -> V_128 = V_129 ;
V_2 -> V_130 = 1 ;
V_2 -> V_131 = 1 ;
if ( V_2 -> V_124 == true )
V_2 -> V_132 = V_133 ;
else
V_2 -> V_132 = V_129 ;
if ( V_2 -> V_45 )
V_2 -> V_134 = true ;
else
V_2 -> V_134 = false ;
} else {
V_2 -> V_134 = false ;
V_2 -> V_127 = 1 ;
V_2 -> V_130 = 0 ;
V_2 -> V_131 = 0 ;
if ( V_65 & V_125 ) {
V_2 -> V_128 = V_133 ;
if ( V_2 -> V_124 == true )
V_2 -> V_132 = V_129 ;
else
V_2 -> V_132 = V_133 ;
} else {
V_2 -> V_128 = V_129 ;
if ( V_2 -> V_124 == true )
V_2 -> V_132 = V_133 ;
else
V_2 -> V_132 = V_129 ;
}
}
V_2 -> V_135 = 100 * 255 ;
V_2 -> V_136 = 100 * 16 ;
V_2 -> V_137 = 1 ;
V_2 -> V_138 = 4 ;
V_2 -> V_139 = 0 ;
V_2 -> V_140 = 64 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_141 = V_142 ;
V_2 -> V_143 = V_144 ;
V_2 -> V_35 = V_145 ;
V_2 -> V_146 = 25 ;
V_2 -> V_147 = 1 ;
V_2 -> V_148 = V_149 ;
V_2 -> V_150 = V_63 -> V_151 ;
if ( ( V_2 -> V_150 & V_152 ) != 0 ) {
V_2 -> V_102 = 0x80 ;
}
if ( V_2 -> V_150 == V_153 ) {
if ( ( V_2 -> V_105 [ V_154 ] == 0x1 ) &&
( V_2 -> V_105 [ V_155 ] >= 0x4 ) ) {
V_70 = V_2 -> V_105 [ V_156 ] ;
V_71 = V_2 -> V_105 [ V_157 ] ;
V_72 = V_2 -> V_105 [ V_158 ] ;
if ( V_70 || V_71 || V_72 ) {
F_16 ( V_2 ,
V_159 ,
0xff ,
0x03 ) ;
F_16 ( V_2 ,
V_159 ,
0xfb ,
V_70 ) ;
F_16 ( V_2 ,
V_159 ,
0xfC ,
V_71 ) ;
F_16 ( V_2 ,
V_159 ,
0xfd ,
V_72 ) ;
} else {
F_16 ( V_2 ,
V_159 ,
0xff ,
0x0 ) ;
}
}
}
V_57 -> V_160 = V_161 ;
V_57 -> V_162 = V_2 -> V_11 ;
V_57 -> V_163 = V_2 -> V_11 ;
F_17 ( V_2 , V_57 -> V_162 ) ;
memcpy ( V_2 -> V_164 , V_63 -> V_165 , 6 ) ;
memcpy ( V_2 -> V_80 ,
V_2 -> V_164 , V_4 ) ;
F_6 ( V_73 , V_74 L_7 ,
V_2 -> V_80 ) ;
if ( V_2 -> V_35 == V_166 ) {
F_18 ( V_2 , V_167 ) ;
V_2 -> V_168 = true ;
} else {
F_18 ( V_2 , V_101 ) ;
V_2 -> V_168 = false ;
}
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_40 ) {
V_2 -> V_169 = V_2 -> V_170 [ 0 ] ;
V_2 -> V_171 = V_2 -> V_169 ;
F_21 ( V_2 , V_2 -> V_170 [ 0 ] ) ;
}
V_2 -> V_172 = V_2 -> V_105 [ V_173 ] ;
V_2 -> V_174 = false ;
if ( ( V_2 -> V_172 & V_175 ) != 0 ) {
V_67 = F_14 ( V_2 , V_85 ,
V_176 , V_87 , 1 , & V_69 ) ;
if ( V_67 != V_68 ) {
F_11 ( & V_2 -> V_76 ) ;
return false ;
}
if ( ( V_69 & V_177 ) == 0 ) {
V_2 -> V_174 = true ;
F_22 ( V_2 , V_176 , V_178 ) ;
} else {
F_23 ( V_2 , V_176 , V_178 ) ;
V_2 -> V_174 = false ;
}
}
F_24 ( V_2 , V_87 ,
V_179 , V_180 , 0x38 ) ;
F_24 ( V_2 , V_87 ,
V_179 , V_181 , V_182 ) ;
F_22 ( V_2 , V_183 , 0x01 ) ;
if ( ( V_2 -> V_174 == true ) ||
( V_2 -> V_184 == true ) ) {
F_25 ( V_2 ) ;
} else {
F_26 ( V_2 ) ;
}
F_11 ( & V_2 -> V_76 ) ;
F_6 ( V_73 , V_74 L_8 ) ;
return true ;
}
static int F_27 ( struct V_185 * V_186 , T_2 V_187 )
{
struct V_1 * V_188 = F_28 ( V_186 ) ;
if ( ! V_188 || ! V_188 -> V_189 )
return - V_190 ;
if ( V_188 -> V_191 & V_192 )
F_29 ( V_188 -> V_189 ) ;
return 0 ;
}
static int F_30 ( struct V_185 * V_186 )
{
struct V_1 * V_188 = F_28 ( V_186 ) ;
if ( ! V_188 || ! V_188 -> V_189 )
return - V_190 ;
if ( ! ( V_188 -> V_191 & V_192 ) )
F_31 ( V_188 -> V_189 ) ;
return 0 ;
}
static int
F_32 ( struct V_185 * V_186 , const struct V_193 * V_194 )
{
T_1 V_195 [ V_4 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ;
struct V_196 * V_197 = F_33 ( V_186 ) ;
int V_198 = 0 ;
struct V_199 * V_200 = NULL ;
struct V_1 * V_2 ;
F_34 ( V_201 L_9 , V_202 , V_203 ) ;
F_34 ( V_201 L_10 ) ;
V_197 = F_35 ( V_197 ) ;
V_200 = F_36 ( sizeof( struct V_1 ) ) ;
if ( ! V_200 ) {
F_34 (KERN_ERR DEVICE_NAME L_11 ) ;
V_198 = - V_204 ;
goto V_205;
}
V_2 = F_37 ( V_200 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_189 = V_200 ;
V_2 -> V_206 = V_197 ;
F_1 ( V_2 ) ;
F_38 ( & V_2 -> V_76 ) ;
F_39 ( & V_2 -> V_207 , V_208 ) ;
F_39 ( & V_2 -> V_209 , V_210 ) ;
F_40 ( & V_2 -> V_211 , V_212 ) ;
F_40 ( & V_2 -> V_213 , V_214 ) ;
V_2 -> V_215 = F_41 ( 0 , V_216 ) ;
if ( ! V_2 -> V_215 ) {
F_6 ( V_217 , V_218 L_12 ) ;
goto V_219;
}
V_2 -> V_220 = V_221 ;
V_2 -> V_58 . V_222 = ( void * ) V_2 ;
V_200 -> V_223 = & V_224 ;
V_200 -> V_225 =
(struct V_226 * ) & V_227 ;
F_42 ( V_186 , V_2 ) ;
F_43 ( V_200 , & V_186 -> V_189 ) ;
memcpy ( V_2 -> V_189 -> V_228 , V_195 , V_4 ) ;
F_44 ( V_2 ) ;
V_198 = F_45 ( V_200 ) ;
if ( V_198 ) {
F_34 (KERN_ERR DEVICE_NAME L_13 ) ;
goto V_219;
}
return 0 ;
V_219:
F_46 ( V_200 ) ;
V_205:
F_47 ( V_197 ) ;
return V_198 ;
}
static void F_48 ( struct V_1 * V_229 )
{
struct V_230 * V_231 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_229 -> V_7 ; V_66 ++ ) {
V_231 = V_229 -> V_232 [ V_66 ] ;
if ( V_231 -> V_233 ) {
F_49 ( V_231 -> V_233 ) ;
F_50 ( V_231 -> V_233 ) ;
}
F_51 ( V_231 ) ;
}
return;
}
static void F_52 ( struct V_1 * V_229 )
{
struct V_234 * V_235 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_229 -> V_9 ; V_66 ++ ) {
V_235 = V_229 -> V_236 [ V_66 ] ;
if ( V_235 -> V_233 ) {
F_49 ( V_235 -> V_233 ) ;
F_50 ( V_235 -> V_233 ) ;
}
if ( V_235 -> V_237 )
F_53 ( V_235 -> V_237 ) ;
}
F_51 ( V_229 -> V_238 ) ;
return;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_239 ;
V_239 = F_54 ( V_2 -> V_206 ) ;
if ( V_239 )
F_34 ( L_14 , V_239 ) ;
return ;
}
static void F_55 ( struct V_1 * V_229 )
{
F_51 ( V_229 -> V_240 . V_241 ) ;
return;
}
static bool F_56 ( struct V_1 * V_229 )
{
struct V_230 * V_231 ;
struct V_234 * V_235 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_229 -> V_7 ; V_66 ++ ) {
V_231 = F_57 ( sizeof( struct V_230 ) ,
V_242 ) ;
if ( V_231 == NULL ) {
F_6 ( V_217 , V_218
L_15 ,
V_229 -> V_189 -> V_243 ) ;
goto V_244;
}
V_229 -> V_232 [ V_66 ] = V_231 ;
V_231 -> V_2 = V_229 ;
V_231 -> V_233 = F_41 ( 0 , V_216 ) ;
if ( V_231 -> V_233 == NULL ) {
F_6 ( V_217 ,
V_218 L_16 ) ;
goto V_244;
}
V_231 -> V_245 = false ;
}
V_229 -> V_238 = F_58 ( ( sizeof( struct V_234 ) * V_229 -> V_9 ) ,
V_242 ) ;
if ( V_229 -> V_238 == NULL ) {
F_6 ( V_217 , V_218
L_17 ,
V_229 -> V_189 -> V_243 ) ;
goto V_244;
}
V_229 -> V_246 = NULL ;
V_229 -> V_247 = NULL ;
V_229 -> V_248 = NULL ;
V_229 -> V_249 = NULL ;
V_229 -> V_250 = 0 ;
V_235 = (struct V_234 * ) V_229 -> V_238 ;
for ( V_66 = 0 ; V_66 < V_229 -> V_9 ; V_66 ++ ) {
V_229 -> V_236 [ V_66 ] = V_235 ;
V_235 -> V_2 = V_229 ;
V_235 -> V_233 = F_41 ( 0 , V_216 ) ;
if ( V_235 -> V_233 == NULL ) {
F_6 ( V_217 , V_218
L_18 ) ;
goto V_251;
}
V_235 -> V_237 = F_59 ( V_229 -> V_189 , V_229 -> V_252 ) ;
if ( V_235 -> V_237 == NULL ) {
F_6 ( V_217 , V_218
L_19 ) ;
goto V_251;
}
V_235 -> V_245 = false ;
F_60 ( V_229 -> V_246 ,
V_229 -> V_247 , V_235 ) ;
V_229 -> V_250 ++ ;
V_235 ++ ;
}
V_229 -> V_253 = F_41 ( 0 , V_216 ) ;
if ( V_229 -> V_253 == NULL ) {
F_6 ( V_217 , V_218 L_20 ) ;
goto V_251;
}
V_229 -> V_240 . V_241 = F_57 ( V_254 , V_242 ) ;
if ( V_229 -> V_240 . V_241 == NULL ) {
F_6 ( V_217 , V_218 L_21 ) ;
F_50 ( V_229 -> V_253 ) ;
goto V_251;
}
return true ;
V_251:
F_52 ( V_229 ) ;
V_244:
F_48 ( V_229 ) ;
return false ;
}
static bool F_61 ( struct V_1 * V_2 )
{
int V_255 ;
T_3 V_256 ;
for ( V_255 = 0 ; V_255 < V_257 ; V_255 ++ ) {
V_256 = & ( V_2 -> V_258 [ V_255 ] ) ;
if ( ! F_62 ( V_2 , V_256 ) ) {
F_6 ( V_217 , V_218 L_22 ,
V_2 -> V_189 -> V_243 ) ;
goto V_259;
}
}
V_2 -> V_260 = V_257 ;
V_2 -> V_261 = V_2 -> V_260 ;
return true ;
V_259:
F_63 ( V_2 ) ;
return false ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_3 V_256 ;
int V_255 ;
for ( V_255 = 0 ; V_255 < V_257 ; V_255 ++ ) {
V_256 = & ( V_2 -> V_258 [ V_255 ] ) ;
if ( V_256 -> V_237 )
F_53 ( V_256 -> V_237 ) ;
}
}
int F_62 ( struct V_1 * V_2 ,
T_3 V_256 )
{
V_256 -> V_237 = F_59 ( V_2 -> V_189 , V_2 -> V_252 ) ;
if ( ! V_256 -> V_237 )
return false ;
return true ;
}
static int F_31 ( struct V_199 * V_189 )
{
struct V_1 * V_2 = F_37 ( V_189 ) ;
V_2 -> V_262 = false ;
F_6 ( V_73 , V_74 L_23 ) ;
V_2 -> V_252 = V_263 ;
if ( F_56 ( V_2 ) == false ) {
F_6 ( V_73 , V_74 L_24 ) ;
return - V_204 ;
}
if ( F_61 ( V_2 ) == false ) {
F_6 ( V_73 , V_74 L_25 ) ;
goto V_251;
}
F_64 ( V_2 , V_264 ) ;
F_64 ( V_2 , V_265 ) ;
F_64 ( V_2 , V_266 ) ;
F_65 ( V_2 , V_267 ) ;
F_65 ( V_2 , V_268 ) ;
F_66 ( V_2 ) ;
if ( F_5 ( V_2 ) == false ) {
F_6 ( V_73 , V_74 L_26 ) ;
goto V_269;
}
F_67 ( V_2 , & V_2 -> V_270 ) ;
memcpy ( V_2 -> V_58 . V_271 ,
V_2 -> V_80 , V_4 ) ;
memcpy ( V_2 -> V_189 -> V_228 , V_2 -> V_80 , V_4 ) ;
V_2 -> V_272 = false ;
V_2 -> V_273 = false ;
V_2 -> V_274 = false ;
V_2 -> V_275 = false ;
V_2 -> V_276 = false ;
if ( V_2 -> V_45 ) {
F_2 ( V_2 ) ;
}
F_68 ( V_2 ) ;
F_69 ( & V_2 -> V_209 , V_52 ) ;
V_2 -> V_277 = 1 ;
V_2 -> V_278 = V_279 ;
V_2 -> V_280 = true ;
V_2 -> V_281 = false ;
V_2 -> V_282 = false ;
V_2 -> V_283 = false ;
V_2 -> V_284 = false ;
V_2 -> V_285 = false ;
V_2 -> V_286 = false ;
V_2 -> V_287 = 0 ;
F_70 ( & V_2 -> V_211 ) ;
F_71 ( V_2 ) ;
if ( ( V_2 -> V_288 == true ) && ( V_2 -> V_289 == true ) ) {
F_7 ( & V_2 -> V_76 ) ;
F_72 ( V_2 ,
& ( V_2 -> V_270 ) ,
V_2 -> V_290 | ( 1 << 31 ) ,
V_2 -> V_291 ,
NULL ,
V_2 -> V_292 ,
V_293
) ;
F_11 ( & V_2 -> V_76 ) ;
V_2 -> V_278 = V_294 ;
}
if ( V_2 -> V_58 . V_295 == V_296 )
F_73 ( ( void * ) V_2 , V_297 , NULL ) ;
else
F_73 ( ( void * ) V_2 , V_298 , NULL ) ;
F_74 ( V_2 -> V_189 ) ;
V_2 -> V_191 |= V_192 ;
F_6 ( V_73 , V_74 L_27 ) ;
return 0 ;
V_269:
F_63 ( V_2 ) ;
V_251:
F_52 ( V_2 ) ;
F_48 ( V_2 ) ;
F_55 ( V_2 ) ;
F_49 ( V_2 -> V_253 ) ;
F_50 ( V_2 -> V_253 ) ;
F_6 ( V_73 , V_74 L_28 ) ;
return - V_204 ;
}
static int F_29 ( struct V_199 * V_189 )
{
struct V_1 * V_2 = F_37 ( V_189 ) ;
struct V_56 * V_57 = & V_2 -> V_58 ;
int V_299 ;
F_6 ( V_73 , V_74 L_29 ) ;
if ( V_2 == NULL )
return - V_190 ;
if ( V_2 -> V_300 ) {
F_73 ( ( void * ) V_2 , V_301 , NULL ) ;
F_75 ( 30 ) ;
}
memset ( V_57 -> V_302 , 0 , V_303 + V_304 + 1 ) ;
V_57 -> V_305 = false ;
V_2 -> V_288 = false ;
V_2 -> V_278 = V_279 ;
F_7 ( & V_2 -> V_76 ) ;
for ( V_299 = 0 ; V_299 < V_306 ; V_299 ++ )
F_76 ( V_2 , V_299 ) ;
F_11 ( & V_2 -> V_76 ) ;
if ( ( V_2 -> V_191 & V_307 ) == false ) {
F_77 ( V_2 ) ;
}
F_74 ( V_2 -> V_189 ) ;
F_65 ( V_2 , V_264 ) ;
F_64 ( V_2 , V_268 ) ;
F_64 ( V_2 , V_267 ) ;
F_78 ( & V_2 -> V_207 ) ;
F_78 ( & V_2 -> V_209 ) ;
if ( V_2 -> V_45 ) {
F_79 ( & V_2 -> V_46 ) ;
F_79 ( & V_2 -> V_53 ) ;
F_79 ( & V_2 -> V_54 ) ;
}
F_80 ( & V_2 -> V_213 ) ;
F_80 ( & V_2 -> V_211 ) ;
V_2 -> V_274 = false ;
V_2 -> V_275 = false ;
V_2 -> V_276 = false ;
V_2 -> V_308 = false ;
V_2 -> V_300 = false ;
memset ( V_57 -> V_309 , 0 , 6 ) ;
V_57 -> V_310 = V_311 ;
V_2 -> V_191 &= ~ V_192 ;
F_48 ( V_2 ) ;
F_52 ( V_2 ) ;
F_55 ( V_2 ) ;
F_63 ( V_2 ) ;
F_49 ( V_2 -> V_253 ) ;
F_50 ( V_2 -> V_253 ) ;
F_81 ( V_2 , 0 ) ;
F_6 ( V_73 , V_74 L_30 ) ;
return 0 ;
}
static void F_82 ( struct V_185 * V_186 )
{
struct V_1 * V_188 = F_28 ( V_186 ) ;
if ( ! V_188 )
return;
F_42 ( V_186 , NULL ) ;
F_47 ( F_33 ( V_186 ) ) ;
V_188 -> V_191 |= V_307 ;
if ( V_188 -> V_189 ) {
F_83 ( V_188 -> V_189 ) ;
F_49 ( V_188 -> V_215 ) ;
F_50 ( V_188 -> V_215 ) ;
F_46 ( V_188 -> V_189 ) ;
}
}
static int V_221 ( struct V_312 * V_237 , struct V_199 * V_189 )
{
struct V_1 * V_2 = F_37 ( V_189 ) ;
F_7 ( & V_2 -> V_76 ) ;
if ( F_84 ( V_2 -> V_272 ) )
F_85 ( V_237 ) ;
else
F_86 ( V_2 , V_237 ) ;
F_11 ( & V_2 -> V_76 ) ;
return V_313 ;
}
static int F_87 ( struct V_312 * V_237 , struct V_199 * V_189 )
{
struct V_1 * V_2 = F_37 ( V_189 ) ;
struct V_314 * V_315 = & V_2 -> V_315 ;
F_7 ( & V_2 -> V_76 ) ;
F_74 ( V_189 ) ;
if ( ! V_2 -> V_300 ) {
F_85 ( V_237 ) ;
goto V_316;
}
if ( V_2 -> V_273 ) {
F_85 ( V_237 ) ;
V_315 -> V_317 ++ ;
goto V_316;
}
if ( F_88 ( V_2 , V_318 , V_237 ) ) {
if ( F_89 ( V_189 ) )
F_90 ( V_189 ) ;
}
V_316:
F_11 ( & V_2 -> V_76 ) ;
return V_313 ;
}
static unsigned char * F_91 ( const unsigned char * V_319 ,
const unsigned char * V_320 ) {
int V_321 = strlen ( V_319 ) ;
int V_322 = strlen ( V_320 ) ;
while ( V_321 >= V_322 ) {
V_321 -- ;
if( memcmp ( V_319 , V_320 , V_322 ) == 0 )
return ( unsigned char * ) V_319 ;
V_319 ++ ;
}
return NULL ;
}
static int F_92 ( unsigned char * string ,
unsigned char * V_323 ,
unsigned char * V_324 )
{
unsigned char V_325 [ 100 ] ;
unsigned char V_326 [ 100 ] ;
unsigned char * V_327 = NULL , * V_328 = NULL , * V_329 = NULL ;
int V_66 ;
memset ( V_325 , 0 , 100 ) ;
strcat ( V_325 , string ) ;
strcat ( V_325 , L_31 ) ;
V_324 += strlen ( V_325 ) ;
V_327 = F_91 ( V_324 , V_325 ) ;
if ( V_327 == NULL )
return false ;
for ( V_66 = 1 ; ; V_66 ++ ) {
if ( memcmp ( V_327 - V_66 , L_32 , 1 ) == 0 )
break;
if ( memcmp ( V_327 - V_66 , L_33 , 1 ) == 0 )
return false ;
}
V_328 = F_91 ( V_327 , L_32 ) ;
if ( V_328 == NULL ) {
V_328 = V_327 + strlen ( V_327 ) ;
}
memset ( V_326 , 0 , 100 ) ;
memcpy ( V_326 , V_327 , V_328 - V_327 ) ;
V_326 [ V_328 - V_327 ] = '\0' ;
V_327 = F_91 ( V_326 , L_31 ) ;
if ( V_327 == NULL )
return false ;
memset ( V_325 , 0 , 100 ) ;
strcpy ( V_325 , V_327 + 1 ) ;
V_329 = V_325 ;
while( * V_329 != 0x00 ) {
if( * V_329 == ' ' )
V_329 ++ ;
else
break;
}
memcpy ( V_323 , V_329 , strlen ( V_329 ) ) ;
return true ;
}
static unsigned char * F_93 ( struct V_1 * V_2 )
{
unsigned char * V_330 = F_57 ( 1024 , V_242 ) ;
struct V_331 * V_331 ;
if ( ! V_330 ) {
F_34 ( L_34 ) ;
return NULL ;
}
V_331 = F_94 ( V_332 , V_333 , 0 ) ;
if ( F_95 ( V_331 ) ) {
F_51 ( V_330 ) ;
F_34 ( L_35 ) ;
return NULL ;
}
if ( F_96 ( V_331 , 0 , V_330 , 1024 ) < 0 ) {
F_34 ( L_36 ) ;
F_51 ( V_330 ) ;
V_330 = NULL ;
}
F_97 ( V_331 ) ;
return V_330 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_334 = 0 ;
unsigned char V_335 [ 100 ] ;
unsigned char * V_330 = NULL ;
V_2 -> V_336 . V_337 = - 1 ;
V_2 -> V_336 . V_338 = - 1 ;
V_2 -> V_336 . V_278 = - 1 ;
V_330 = F_93 ( V_2 ) ;
if ( V_330 == NULL ) {
V_334 = - 1 ;
return V_334 ;
}
{
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
if( F_92 ( L_37 , V_335 , V_330 ) == true ) {
if( memcmp ( V_335 , L_38 , 3 ) == 0 ) {
V_2 -> V_336 . V_337 = V_117 ;
}
else if( memcmp ( V_335 , L_39 , 5 ) == 0 ) {
V_2 -> V_336 . V_337 = V_114 ;
}
else if( memcmp ( V_335 , L_40 , 6 ) == 0 ) {
V_2 -> V_336 . V_337 = V_115 ;
}
else {
F_34 ( L_41 , V_335 ) ;
}
}
}
{
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
if( F_92 ( L_42 , V_335 , V_330 ) == true ) {
V_2 -> V_336 . V_338 = ( int ) F_98 ( V_335 , NULL , 10 ) ;
}
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
if( F_92 ( L_43 , V_335 , V_330 ) == true ) {
V_2 -> V_336 . V_278 = ( int ) F_98 ( V_335 , NULL , 10 ) ;
}
}
F_51 ( V_330 ) ;
return V_334 ;
}
static void F_99 ( struct V_199 * V_189 )
{
struct V_1 * V_229 = F_37 ( V_189 ) ;
unsigned long V_191 ;
if ( V_229 -> V_191 & V_192 ) {
F_100 ( & V_229 -> V_76 , V_191 ) ;
F_73 ( V_229 , V_339 , NULL ) ;
F_101 ( & V_229 -> V_76 , V_191 ) ;
}
}
void F_102 ( struct V_1 * V_229 )
{
struct V_199 * V_189 = V_229 -> V_189 ;
struct V_56 * V_340 = & V_229 -> V_58 ;
struct V_341 * V_342 ;
T_4 V_343 = 0 ;
T_1 V_344 = 0 ;
int V_198 ;
V_198 = F_14 ( V_229 , V_85 ,
V_345 , V_87 , 1 , & V_344 ) ;
if ( V_198 == 0 )
V_229 -> V_346 = V_344 ;
F_6 ( V_73 , V_74 L_44 ,
V_229 -> V_346 ) ;
if ( V_189 -> V_191 & V_347 ) {
F_6 ( V_217 , V_201
L_45 , V_189 -> V_243 ) ;
V_229 -> V_346 |= ( V_348 | V_349 | V_350 ) ;
} else if ( ( F_103 ( V_189 ) > V_229 -> V_351 ) ||
( V_189 -> V_191 & V_352 ) ) {
V_343 = ~ 0x0 ;
F_104 ( V_229 , V_343 ) ;
V_229 -> V_346 |= ( V_348 | V_349 ) ;
} else {
F_105 (ha, dev) {
int V_353 = F_106 ( V_4 , V_342 -> V_354 ) >> 26 ;
V_343 |= 1ULL << ( V_353 & 0x3f ) ;
}
F_104 ( V_229 , V_343 ) ;
V_229 -> V_346 &= ~ ( V_350 ) ;
V_229 -> V_346 |= ( V_348 | V_349 ) ;
}
if ( V_340 -> V_295 == V_296 ) {
V_229 -> V_346 |= ( V_348 | V_349 ) ;
V_229 -> V_346 &= ~ ( V_350 ) ;
}
F_16 ( V_229 , V_87 ,
V_345 , V_229 -> V_346 ) ;
F_6 ( V_73 , V_74
L_46 , V_229 -> V_346 ) ;
}
static struct V_314 * F_107 ( struct V_199 * V_189 )
{
struct V_1 * V_2 = F_37 ( V_189 ) ;
return & V_2 -> V_315 ;
}
static int F_108 ( struct V_199 * V_189 , struct V_355 * V_356 , int V_357 )
{
struct V_1 * V_2 = F_37 ( V_189 ) ;
struct V_358 * V_359 = (struct V_358 * ) V_356 ;
int V_198 = 0 ;
switch ( V_357 ) {
case V_360 :
if ( ! ( V_2 -> V_191 & V_192 ) )
V_198 = - V_361 ;
V_198 = F_109 ( V_2 , & V_359 -> V_362 . V_47 ) ;
break;
case V_363 :
return F_110 ( V_189 , V_356 ) ;
}
return V_198 ;
}
static int F_110 ( struct V_199 * V_189 , struct V_355 * V_356 )
{
T_5 V_364 ;
if ( F_111 ( & V_364 , V_356 -> V_365 , sizeof( V_364 ) ) )
return - V_361 ;
switch ( V_364 ) {
case V_366 : {
struct V_367 V_368 = { V_366 } ;
strncpy ( V_368 . V_369 , V_370 , sizeof( V_368 . V_369 ) - 1 ) ;
strncpy ( V_368 . V_371 , V_203 , sizeof( V_368 . V_371 ) - 1 ) ;
if ( F_112 ( V_356 -> V_365 , & V_368 , sizeof( V_368 ) ) )
return - V_361 ;
return 0 ;
}
}
return - V_372 ;
}
