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
static int F_5 ( struct V_1 * V_2 ,
T_2 V_56 )
{
struct V_57 * V_58 = & V_2 -> V_59 ;
T_1 V_3 [ V_4 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_5 [ V_4 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_1 V_6 [ V_4 ]
= { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0xf8 } ;
T_1 V_60 ;
int V_61 ;
T_3 V_62 ;
int V_63 = V_64 ;
T_4 V_65 ;
T_1 V_66 ;
T_1 V_67 = 0 , V_68 = 0 , V_69 = 0 ;
F_6 ( V_70 , V_71 L_1 , V_56 , V_2 -> V_37 ) ;
F_7 ( & V_2 -> V_72 ) ;
if ( V_56 == V_73 ) {
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
memcpy ( V_2 -> V_5 , V_5 , V_4 ) ;
memcpy ( V_2 -> V_6 ,
V_6 ,
V_4 ) ;
if ( ! F_8 ( V_2 ) ) {
if ( F_9 ( V_2 ) == true ) {
if ( F_10 ( V_2 ) == false ) {
F_6 ( V_70 , V_71 L_2 ) ;
F_11 ( & V_2 -> V_72 ) ;
return false ;
}
} else {
F_6 ( V_70 , V_71 L_3 ) ;
F_11 ( & V_2 -> V_72 ) ;
return false ;
}
}
if ( ! F_12 ( V_2 ) ) {
F_6 ( V_70 , V_71 L_4 ) ;
F_11 ( & V_2 -> V_72 ) ;
return false ;
}
}
V_62 . V_74 = ( T_1 ) V_56 ;
V_62 . V_44 = ( T_1 ) V_2 -> V_44 ;
for ( V_61 = 0 ; V_61 < 6 ; V_61 ++ )
V_62 . V_75 [ V_61 ] = V_2 -> V_76 [ V_61 ] ;
V_62 . V_17 = V_2 -> V_17 ;
V_62 . V_19 = V_2 -> V_19 ;
V_63 = F_13 ( V_2 ,
V_77 ,
0 ,
0 ,
sizeof( T_3 ) ,
( T_1 * ) & ( V_62 ) ) ;
if ( V_63 != V_64 ) {
F_6 ( V_70 , V_71 L_5 ) ;
F_11 ( & V_2 -> V_72 ) ;
return false ;
}
if ( V_56 == V_73 ) {
V_63 = F_14 ( V_2 , V_78 , 0 , 0 , sizeof( T_4 ) , ( T_1 * ) & ( V_65 ) ) ;
if ( V_63 != V_64 ) {
F_6 ( V_70 , V_71 L_6 ) ;
F_11 ( & V_2 -> V_72 ) ;
return false ;
}
V_63 = F_14 ( V_2 ,
V_79 ,
V_80 ,
V_81 ,
1 ,
& V_2 -> V_82 ) ;
if ( V_63 != V_64 ) {
F_11 ( & V_2 -> V_72 ) ;
return false ;
}
V_2 -> V_83 = true ;
V_2 -> V_84 = false ;
V_2 -> V_85 = false ;
V_2 -> V_86 = false ;
if ( V_2 -> V_34 ) {
V_2 -> V_87 = ( V_88 ) V_2 -> V_31 ;
} else {
if ( V_2 -> V_35 == V_89 )
V_2 -> V_87 = V_90 ;
else
V_2 -> V_87 = V_91 ;
}
F_15 ( V_2 ) ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = V_95 ;
V_2 -> V_96 = 0 ;
V_2 -> V_97 = 0xFF ;
V_2 -> V_98 = V_2 -> V_99 [ V_100 ] ;
V_2 -> V_101 = V_2 -> V_99 [ V_102 ] ;
for ( V_61 = 0 ; V_61 < 14 ; V_61 ++ ) {
V_2 -> V_103 [ V_61 ] = V_2 -> V_99 [ V_61 + V_104 ] ;
if ( V_2 -> V_103 [ V_61 ] == 0 )
V_2 -> V_103 [ V_61 ] = V_2 -> V_98 ;
V_2 -> V_105 [ V_61 ] = V_2 -> V_99 [ V_61 + V_106 ] ;
if ( V_2 -> V_105 [ V_61 ] == 0 )
V_2 -> V_105 [ V_61 ] = V_2 -> V_101 ;
}
if( ( ( V_2 -> V_99 [ V_107 ] == V_108 ) ||
( V_2 -> V_99 [ V_107 ] == V_109 ) ) &&
( V_2 -> V_110 == V_111 ) ) {
for ( V_61 = 11 ; V_61 < 14 ; V_61 ++ ) {
V_2 -> V_103 [ V_61 ] = V_2 -> V_103 [ 10 ] ;
V_2 -> V_105 [ V_61 ] = V_2 -> V_105 [ 10 ] ;
}
}
V_2 -> V_112 = 0x34 ;
for ( V_61 = 0 ; V_61 < V_113 ; V_61 ++ ) {
V_2 -> V_114 [ V_61 ] = V_2 -> V_99 [ V_61 + V_115 ] ;
if ( V_2 -> V_114 [ V_61 ] == 0 )
V_2 -> V_114 [ V_61 ] = V_2 -> V_112 ;
}
V_60 = V_2 -> V_99 [ V_116 ] ;
if ( V_60 & V_117 )
V_2 -> V_118 = true ;
else
V_2 -> V_118 = false ;
V_60 &= ( V_119 | V_120 ) ;
if ( V_60 == 0 )
V_60 = ( V_119 | V_120 ) ;
if ( V_60 == ( V_119 | V_120 ) ) {
V_2 -> V_121 = 2 ;
V_2 -> V_122 = V_123 ;
V_2 -> V_124 = 1 ;
V_2 -> V_125 = 1 ;
if ( V_2 -> V_118 == true )
V_2 -> V_126 = V_127 ;
else
V_2 -> V_126 = V_123 ;
if ( V_2 -> V_45 )
V_2 -> V_128 = true ;
else
V_2 -> V_128 = false ;
} else {
V_2 -> V_128 = false ;
V_2 -> V_121 = 1 ;
V_2 -> V_124 = 0 ;
V_2 -> V_125 = 0 ;
if ( V_60 & V_119 ) {
V_2 -> V_122 = V_127 ;
if ( V_2 -> V_118 == true )
V_2 -> V_126 = V_123 ;
else
V_2 -> V_126 = V_127 ;
} else {
V_2 -> V_122 = V_123 ;
if ( V_2 -> V_118 == true )
V_2 -> V_126 = V_127 ;
else
V_2 -> V_126 = V_123 ;
}
}
V_2 -> V_129 = 100 * 255 ;
V_2 -> V_130 = 100 * 16 ;
V_2 -> V_131 = 1 ;
V_2 -> V_132 = 4 ;
V_2 -> V_133 = 0 ;
V_2 -> V_134 = 64 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_135 = V_136 ;
V_2 -> V_137 = V_138 ;
V_2 -> V_35 = V_139 ;
V_2 -> V_140 = 25 ;
V_2 -> V_141 = 1 ;
V_2 -> V_142 = V_143 ;
V_2 -> V_144 = V_65 . V_144 ;
if ( ( V_2 -> V_144 & V_145 ) != 0 ) {
V_2 -> V_96 = 0x80 ;
}
if ( V_2 -> V_144 == V_146 ) {
if( ( V_2 -> V_99 [ V_147 ] == 0x1 ) &&
( V_2 -> V_99 [ V_148 ] >= 0x4 ) ) {
V_67 = V_2 -> V_99 [ V_149 ] ;
V_68 = V_2 -> V_99 [ V_150 ] ;
V_69 = V_2 -> V_99 [ V_151 ] ;
if( ( V_67 || V_68 || V_69 ) ) {
F_16 ( V_2 ,
V_152 ,
0xFF ,
0x03 ) ;
F_16 ( V_2 ,
V_152 ,
0xFB ,
V_67 ) ;
F_16 ( V_2 ,
V_152 ,
0xFC ,
V_68 ) ;
F_16 ( V_2 ,
V_152 ,
0xFD ,
V_69 ) ;
} else {
F_16 ( V_2 ,
V_152 ,
0xFF ,
0x0 ) ;
}
}
}
V_58 -> V_153 = V_154 ;
V_58 -> V_155 = V_2 -> V_11 ;
V_58 -> V_156 = V_2 -> V_11 ;
F_17 ( V_2 , V_58 -> V_155 ) ;
memcpy ( V_2 -> V_157 , & ( V_65 . V_158 [ 0 ] ) , 6 ) ;
memcpy ( V_2 -> V_76 ,
V_2 -> V_157 ,
V_4 ) ;
F_6 ( V_70 , V_71 L_7 ,
V_2 -> V_76 ) ;
}
if ( V_2 -> V_35 == V_159 ) {
F_18 ( V_2 , V_160 ) ;
V_2 -> V_161 = true ;
} else {
F_18 ( V_2 , V_95 ) ;
V_2 -> V_161 = false ;
}
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_40 ) {
V_2 -> V_162 = V_2 -> V_163 [ 0 ] ;
V_2 -> V_164 = V_2 -> V_162 ;
F_21 ( V_2 , V_2 -> V_163 [ 0 ] ) ;
}
V_2 -> V_165 = V_2 -> V_99 [ V_166 ] ;
V_2 -> V_167 = false ;
if ( ( V_2 -> V_165 & V_168 ) != 0 ) {
V_63 = F_14 ( V_2 ,
V_79 ,
V_169 ,
V_81 ,
1 ,
& V_66 ) ;
if ( V_63 != V_64 ) {
F_11 ( & V_2 -> V_72 ) ;
return false ;
}
if ( ( V_66 & V_170 ) == 0 ) {
V_2 -> V_167 = true ;
F_22 ( V_2 , V_169 , V_171 ) ;
} else {
F_23 ( V_2 , V_169 , V_171 ) ;
V_2 -> V_167 = false ;
}
}
F_24 ( V_2 , V_81 , V_172 , V_173 , 0x38 ) ;
F_24 ( V_2 , V_81 , V_172 , V_174 , V_175 ) ;
F_22 ( V_2 , V_176 , 0x01 ) ;
if ( ( V_2 -> V_167 == true ) || ( V_2 -> V_177 == true ) ) {
F_25 ( V_2 ) ;
} else {
F_26 ( V_2 ) ;
}
F_11 ( & V_2 -> V_72 ) ;
F_6 ( V_70 , V_71 L_8 ) ;
return true ;
}
static int F_27 ( struct V_178 * V_179 , T_5 V_180 )
{
struct V_1 * V_181 = F_28 ( V_179 ) ;
if ( ! V_181 || ! V_181 -> V_182 )
return - V_183 ;
if ( V_181 -> V_184 & V_185 )
F_29 ( V_181 -> V_182 ) ;
return 0 ;
}
static int F_30 ( struct V_178 * V_179 )
{
struct V_1 * V_181 = F_28 ( V_179 ) ;
if ( ! V_181 || ! V_181 -> V_182 )
return - V_183 ;
if ( ! ( V_181 -> V_184 & V_185 ) )
F_31 ( V_181 -> V_182 ) ;
return 0 ;
}
static int
F_32 ( struct V_178 * V_179 , const struct V_186 * V_187 )
{
T_1 V_188 [ V_4 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ;
struct V_189 * V_190 = F_33 ( V_179 ) ;
int V_191 = 0 ;
struct V_192 * V_193 = NULL ;
struct V_1 * V_2 ;
F_34 ( V_194 L_9 , V_195 , V_196 ) ;
F_34 ( V_194 L_10 ) ;
V_190 = F_35 ( V_190 ) ;
V_193 = F_36 ( sizeof( struct V_1 ) ) ;
if ( ! V_193 ) {
F_34 (KERN_ERR DEVICE_NAME L_11 ) ;
V_191 = - V_197 ;
goto V_198;
}
V_2 = F_37 ( V_193 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_182 = V_193 ;
V_2 -> V_199 = V_190 ;
F_1 ( V_2 ) ;
F_38 ( & V_2 -> V_72 ) ;
F_39 ( & V_2 -> V_200 , V_201 ) ;
F_39 ( & V_2 -> V_202 , V_203 ) ;
F_40 ( & V_2 -> V_204 , V_205 ) ;
F_40 ( & V_2 -> V_206 , V_207 ) ;
V_2 -> V_208 = F_41 ( 0 , V_209 ) ;
if ( ! V_2 -> V_208 ) {
F_6 ( V_210 , V_211 L_12 ) ;
goto V_212;
}
V_2 -> V_213 = V_214 ;
V_2 -> V_59 . V_215 = ( void * ) V_2 ;
V_193 -> V_216 = & V_217 ;
V_193 -> V_218 =
(struct V_219 * ) & V_220 ;
F_42 ( V_179 , V_2 ) ;
F_43 ( V_193 , & V_179 -> V_182 ) ;
memcpy ( V_2 -> V_182 -> V_221 , V_188 , V_4 ) ;
F_44 ( V_2 ) ;
V_191 = F_45 ( V_193 ) ;
if ( V_191 ) {
F_34 (KERN_ERR DEVICE_NAME L_13 ) ;
goto V_212;
}
return 0 ;
V_212:
F_46 ( V_193 ) ;
V_198:
F_47 ( V_190 ) ;
return V_191 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_222 * V_223 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_7 ; V_61 ++ ) {
V_223 = V_2 -> V_224 [ V_61 ] ;
if ( V_223 -> V_225 ) {
F_49 ( V_223 -> V_225 ) ;
F_50 ( V_223 -> V_225 ) ;
}
F_51 ( V_223 ) ;
}
return;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_226 * V_227 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_9 ; V_61 ++ ) {
V_227 = V_2 -> V_228 [ V_61 ] ;
if ( V_227 -> V_225 ) {
F_49 ( V_227 -> V_225 ) ;
F_50 ( V_227 -> V_225 ) ;
}
if ( V_227 -> V_229 )
F_53 ( V_227 -> V_229 ) ;
}
F_51 ( V_2 -> V_230 ) ;
return;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_231 ;
V_231 = F_54 ( V_2 -> V_199 ) ;
if ( V_231 )
F_34 ( L_14 , V_231 ) ;
return ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_232 . V_233 ) ;
return;
}
static bool F_56 ( struct V_1 * V_2 )
{
struct V_222 * V_223 ;
struct V_226 * V_227 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_7 ; V_61 ++ ) {
V_223 = F_57 ( sizeof( struct V_222 ) , V_234 ) ;
if ( V_223 == NULL ) {
F_6 ( V_210 , V_211 L_15 , V_2 -> V_182 -> V_235 ) ;
goto V_236;
}
V_2 -> V_224 [ V_61 ] = V_223 ;
V_223 -> V_2 = ( void * ) V_2 ;
V_223 -> V_225 = F_41 ( 0 , V_209 ) ;
if ( V_223 -> V_225 == NULL ) {
F_6 ( V_210 , V_211 L_16 ) ;
goto V_236;
}
V_223 -> V_237 = false ;
}
V_2 -> V_230 = F_58 ( ( sizeof( struct V_226 ) * V_2 -> V_9 ) ,
V_234 ) ;
if ( V_2 -> V_230 == NULL ) {
F_6 ( V_210 , V_211 L_17 , V_2 -> V_182 -> V_235 ) ;
goto V_236;
}
V_2 -> V_238 = NULL ;
V_2 -> V_239 = NULL ;
V_2 -> V_240 = NULL ;
V_2 -> V_241 = NULL ;
V_2 -> V_242 = 0 ;
V_227 = (struct V_226 * ) V_2 -> V_230 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_9 ; V_61 ++ ) {
V_2 -> V_228 [ V_61 ] = V_227 ;
V_227 -> V_2 = ( void * ) V_2 ;
V_227 -> V_225 = F_41 ( 0 , V_209 ) ;
if ( V_227 -> V_225 == NULL ) {
F_6 ( V_210 , V_211 L_18 ) ;
goto V_243;
}
V_227 -> V_229 = F_59 ( ( int ) V_2 -> V_244 ) ;
if ( V_227 -> V_229 == NULL ) {
F_6 ( V_210 , V_211 L_19 ) ;
goto V_243;
}
V_227 -> V_229 -> V_182 = V_2 -> V_182 ;
V_227 -> V_237 = false ;
F_60 ( V_2 -> V_238 , V_2 -> V_239 , V_227 ) ;
V_2 -> V_242 ++ ;
V_227 ++ ;
}
V_2 -> V_245 = F_41 ( 0 , V_209 ) ;
if ( V_2 -> V_245 == NULL ) {
F_6 ( V_210 , V_211 L_20 ) ;
goto V_243;
}
V_2 -> V_232 . V_233 = F_57 ( V_246 , V_234 ) ;
if ( V_2 -> V_232 . V_233 == NULL ) {
F_6 ( V_210 , V_211 L_21 ) ;
F_50 ( V_2 -> V_245 ) ;
goto V_243;
}
return true ;
V_243:
F_52 ( V_2 ) ;
V_236:
F_48 ( V_2 ) ;
return false ;
}
static bool F_61 ( struct V_1 * V_2 )
{
int V_247 ;
T_6 V_248 ;
for ( V_247 = 0 ; V_247 < V_249 ; V_247 ++ ) {
V_248 = & ( V_2 -> V_250 [ V_247 ] ) ;
if ( ! F_62 ( V_2 , V_248 ) ) {
F_6 ( V_210 , V_211 L_22 ,
V_2 -> V_182 -> V_235 ) ;
goto V_251;
}
}
V_2 -> V_252 = V_249 ;
V_2 -> V_253 = V_2 -> V_252 ;
return true ;
V_251:
F_63 ( V_2 ) ;
return false ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_6 V_248 ;
int V_247 ;
for ( V_247 = 0 ; V_247 < V_249 ; V_247 ++ ) {
V_248 = & ( V_2 -> V_250 [ V_247 ] ) ;
if ( V_248 -> V_229 )
F_53 ( V_248 -> V_229 ) ;
}
}
int F_62 ( struct V_1 * V_2 ,
T_6 V_248 )
{
V_248 -> V_229 = F_59 ( ( int ) V_2 -> V_244 ) ;
if ( V_248 -> V_229 == NULL )
return false ;
V_248 -> V_229 -> V_182 = V_2 -> V_182 ;
return true ;
}
static int F_31 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
V_2 -> V_254 = false ;
F_6 ( V_70 , V_71 L_23 ) ;
V_2 -> V_244 = V_255 ;
if ( F_56 ( V_2 ) == false ) {
F_6 ( V_70 , V_71 L_24 ) ;
return - V_197 ;
}
if ( F_61 ( V_2 ) == false ) {
F_6 ( V_70 , V_71 L_25 ) ;
goto V_243;
}
F_64 ( V_2 , V_256 ) ;
F_64 ( V_2 , V_257 ) ;
F_64 ( V_2 , V_258 ) ;
F_65 ( V_2 , V_259 ) ;
F_65 ( V_2 , V_260 ) ;
F_66 ( V_2 ) ;
if ( F_5 ( V_2 , V_73 ) == false ) {
F_6 ( V_70 , V_71 L_26 ) ;
goto V_261;
}
F_67 ( V_2 -> V_182 ) ;
F_68 ( V_2 , & V_2 -> V_262 ) ;
memcpy ( V_2 -> V_59 . V_263 ,
V_2 -> V_76 , V_4 ) ;
memcpy ( V_2 -> V_182 -> V_221 , V_2 -> V_76 , V_4 ) ;
V_2 -> V_264 = false ;
V_2 -> V_265 = false ;
V_2 -> V_266 = false ;
V_2 -> V_267 = false ;
V_2 -> V_268 = false ;
if ( V_2 -> V_45 ) {
F_2 ( V_2 ) ;
}
F_69 ( V_2 ) ;
F_70 ( & V_2 -> V_269 , ( void * ) V_270 , ( unsigned long ) V_2 ) ;
F_71 ( & V_2 -> V_202 , V_52 ) ;
V_2 -> V_271 = 100 ;
V_2 -> V_272 = V_273 ;
V_2 -> V_274 = true ;
V_2 -> V_275 = false ;
V_2 -> V_276 = false ;
V_2 -> V_277 = false ;
V_2 -> V_278 = false ;
V_2 -> V_279 = false ;
V_2 -> V_280 = false ;
V_2 -> V_281 = false ;
V_2 -> V_282 = false ;
V_2 -> V_283 = 0 ;
F_72 ( & V_2 -> V_204 ) ;
V_270 ( V_2 ) ;
if ( ( V_2 -> V_284 == true ) && ( V_2 -> V_285 == true ) ) {
F_7 ( & V_2 -> V_72 ) ;
F_73 ( V_2 ,
& ( V_2 -> V_262 ) ,
V_2 -> V_286 | ( 1 << 31 ) ,
V_2 -> V_287 ,
NULL ,
V_2 -> V_288 ,
V_289
) ;
F_11 ( & V_2 -> V_72 ) ;
V_2 -> V_272 = V_290 ;
}
if ( V_2 -> V_59 . V_291 == V_292 )
F_74 ( ( void * ) V_2 , V_293 , NULL ) ;
else
F_74 ( ( void * ) V_2 , V_294 , NULL ) ;
F_75 ( V_2 -> V_182 ) ;
V_2 -> V_184 |= V_185 ;
F_6 ( V_70 , V_71 L_27 ) ;
return 0 ;
V_261:
F_63 ( V_2 ) ;
V_243:
F_52 ( V_2 ) ;
F_48 ( V_2 ) ;
F_55 ( V_2 ) ;
F_49 ( V_2 -> V_245 ) ;
F_50 ( V_2 -> V_245 ) ;
F_6 ( V_70 , V_71 L_28 ) ;
return - V_197 ;
}
static int F_29 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_57 * V_58 = & V_2 -> V_59 ;
int V_295 ;
F_6 ( V_70 , V_71 L_29 ) ;
if ( V_2 == NULL )
return - V_183 ;
if ( V_2 -> V_296 ) {
F_74 ( ( void * ) V_2 , V_297 , NULL ) ;
F_76 ( 30 ) ;
}
memset ( V_58 -> V_298 , 0 , V_299 + V_300 + 1 ) ;
V_58 -> V_301 = false ;
V_2 -> V_284 = false ;
V_2 -> V_272 = V_273 ;
F_7 ( & V_2 -> V_72 ) ;
for ( V_295 = 0 ; V_295 < V_302 ; V_295 ++ )
F_77 ( V_2 , V_295 ) ;
F_11 ( & V_2 -> V_72 ) ;
if ( ( V_2 -> V_184 & V_303 ) == false ) {
F_78 ( V_2 ) ;
}
F_75 ( V_2 -> V_182 ) ;
F_65 ( V_2 , V_256 ) ;
F_64 ( V_2 , V_260 ) ;
F_64 ( V_2 , V_259 ) ;
V_2 -> V_275 = true ;
F_79 ( & V_2 -> V_200 ) ;
F_79 ( & V_2 -> V_202 ) ;
if ( V_2 -> V_45 ) {
F_80 ( & V_2 -> V_46 ) ;
F_80 ( & V_2 -> V_53 ) ;
F_80 ( & V_2 -> V_54 ) ;
}
F_81 ( & V_2 -> V_206 ) ;
F_81 ( & V_2 -> V_204 ) ;
F_82 ( & V_2 -> V_269 ) ;
V_2 -> V_266 = false ;
V_2 -> V_267 = false ;
V_2 -> V_268 = false ;
V_2 -> V_304 = false ;
V_2 -> V_296 = false ;
memset ( V_58 -> V_305 , 0 , 6 ) ;
V_58 -> V_306 = V_307 ;
V_2 -> V_184 &= ~ V_185 ;
F_48 ( V_2 ) ;
F_52 ( V_2 ) ;
F_55 ( V_2 ) ;
F_63 ( V_2 ) ;
F_49 ( V_2 -> V_245 ) ;
F_50 ( V_2 -> V_245 ) ;
F_83 ( V_2 , 0 ) ;
F_6 ( V_70 , V_71 L_30 ) ;
return 0 ;
}
static void F_84 ( struct V_178 * V_179 )
{
struct V_1 * V_181 = F_28 ( V_179 ) ;
if ( ! V_181 )
return;
F_42 ( V_179 , NULL ) ;
F_47 ( F_33 ( V_179 ) ) ;
V_181 -> V_184 |= V_303 ;
if ( V_181 -> V_182 ) {
F_85 ( V_181 -> V_182 ) ;
F_49 ( V_181 -> V_208 ) ;
F_50 ( V_181 -> V_208 ) ;
F_46 ( V_181 -> V_182 ) ;
}
}
static int V_214 ( struct V_308 * V_229 , struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
F_7 ( & V_2 -> V_72 ) ;
if ( F_86 ( V_2 -> V_264 ) )
F_87 ( V_229 ) ;
else
F_88 ( V_2 , V_229 ) ;
F_11 ( & V_2 -> V_72 ) ;
return V_309 ;
}
static int F_89 ( struct V_308 * V_229 , struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_310 * V_311 = & V_2 -> V_311 ;
F_7 ( & V_2 -> V_72 ) ;
F_75 ( V_182 ) ;
if ( ! V_2 -> V_296 ) {
F_87 ( V_229 ) ;
goto V_312;
}
if ( V_2 -> V_265 ) {
F_87 ( V_229 ) ;
V_311 -> V_313 ++ ;
goto V_312;
}
if ( F_90 ( V_2 , V_314 , V_229 ) ) {
if ( F_91 ( V_182 ) )
F_92 ( V_182 ) ;
}
V_312:
F_11 ( & V_2 -> V_72 ) ;
return V_309 ;
}
static inline T_7 F_93 ( int V_315 , unsigned char * V_47 )
{
int V_316 = - 1 ;
while( -- V_315 >= 0 ) {
unsigned char V_317 = * V_47 ++ ;
int V_318 ;
for ( V_318 = 0 ; V_318 < 8 ; V_318 ++ , V_317 >>= 1 ) {
V_316 = ( V_316 << 1 ) ^
( ( V_316 < 0 ) ^ ( V_317 & 1 ) ? V_319 : 0 ) ;
}
}
return V_316 ;
}
static unsigned char * F_94 ( const unsigned char * V_320 ,
const unsigned char * V_321 ) {
int V_322 = strlen ( V_320 ) ;
int V_323 = strlen ( V_321 ) ;
while ( V_322 >= V_323 ) {
V_322 -- ;
if( memcmp ( V_320 , V_321 , V_323 ) == 0 )
return ( unsigned char * ) V_320 ;
V_320 ++ ;
}
return NULL ;
}
static int F_95 ( unsigned char * string ,
unsigned char * V_324 ,
unsigned char * V_325 )
{
unsigned char V_326 [ 100 ] ;
unsigned char V_327 [ 100 ] ;
unsigned char * V_328 = NULL , * V_329 = NULL , * V_330 = NULL ;
int V_61 ;
memset ( V_326 , 0 , 100 ) ;
strcat ( V_326 , string ) ;
strcat ( V_326 , L_31 ) ;
V_325 += strlen ( V_326 ) ;
V_328 = F_94 ( V_325 , V_326 ) ;
if ( V_328 == NULL )
return false ;
for ( V_61 = 1 ; ; V_61 ++ ) {
if ( memcmp ( V_328 - V_61 , L_32 , 1 ) == 0 )
break;
if ( memcmp ( V_328 - V_61 , L_33 , 1 ) == 0 )
return false ;
}
V_329 = F_94 ( V_328 , L_32 ) ;
if ( V_329 == NULL ) {
V_329 = V_328 + strlen ( V_328 ) ;
}
memset ( V_327 , 0 , 100 ) ;
memcpy ( V_327 , V_328 , V_329 - V_328 ) ;
V_327 [ V_329 - V_328 ] = '\0' ;
V_328 = F_94 ( V_327 , L_31 ) ;
if ( V_328 == NULL )
return false ;
memset ( V_326 , 0 , 100 ) ;
strcpy ( V_326 , V_328 + 1 ) ;
V_330 = V_326 ;
while( * V_330 != 0x00 ) {
if( * V_330 == ' ' )
V_330 ++ ;
else
break;
}
memcpy ( V_324 , V_330 , strlen ( V_330 ) ) ;
return true ;
}
static unsigned char * F_96 ( struct V_1 * V_2 )
{
unsigned char * V_331 = F_57 ( 1024 , V_234 ) ;
struct V_332 * V_332 ;
if ( ! V_331 ) {
F_34 ( L_34 ) ;
return NULL ;
}
V_332 = F_97 ( V_333 , V_334 , 0 ) ;
if ( F_98 ( V_332 ) ) {
F_51 ( V_331 ) ;
F_34 ( L_35 ) ;
return NULL ;
}
if ( F_99 ( V_332 , 0 , V_331 , 1024 ) < 0 ) {
F_34 ( L_36 ) ;
F_51 ( V_331 ) ;
V_331 = NULL ;
}
F_100 ( V_332 ) ;
return V_331 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_335 = 0 ;
unsigned char V_336 [ 100 ] ;
unsigned char * V_331 = NULL ;
V_2 -> V_337 . V_338 = - 1 ;
V_2 -> V_337 . V_339 = - 1 ;
V_2 -> V_337 . V_272 = - 1 ;
V_331 = F_96 ( V_2 ) ;
if ( V_331 == NULL ) {
V_335 = - 1 ;
return V_335 ;
}
{
memset ( V_336 , 0 , sizeof( V_336 ) ) ;
if( F_95 ( L_37 , V_336 , V_331 ) == true ) {
if( memcmp ( V_336 , L_38 , 3 ) == 0 ) {
V_2 -> V_337 . V_338 = V_111 ;
}
else if( memcmp ( V_336 , L_39 , 5 ) == 0 ) {
V_2 -> V_337 . V_338 = V_108 ;
}
else if( memcmp ( V_336 , L_40 , 6 ) == 0 ) {
V_2 -> V_337 . V_338 = V_109 ;
}
else {
F_34 ( L_41 , V_336 ) ;
}
}
}
{
memset ( V_336 , 0 , sizeof( V_336 ) ) ;
if( F_95 ( L_42 , V_336 , V_331 ) == true ) {
V_2 -> V_337 . V_339 = ( int ) F_101 ( V_336 , NULL , 10 ) ;
}
memset ( V_336 , 0 , sizeof( V_336 ) ) ;
if( F_95 ( L_43 , V_336 , V_331 ) == true ) {
V_2 -> V_337 . V_272 = ( int ) F_101 ( V_336 , NULL , 10 ) ;
}
}
F_51 ( V_331 ) ;
return V_335 ;
}
static void F_67 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_57 * V_58 = & V_2 -> V_59 ;
struct V_340 * V_341 ;
T_7 V_342 [ 2 ] ;
int V_61 ;
T_1 V_343 [ 8 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_344 = 0 ;
int V_191 ;
F_7 ( & V_2 -> V_72 ) ;
V_191 = F_14 ( V_2 ,
V_79 ,
V_345 ,
V_81 ,
1 ,
& V_344
) ;
if ( V_191 == 0 ) V_2 -> V_346 = V_344 ;
F_6 ( V_70 , V_71 L_44 , V_2 -> V_346 ) ;
if ( V_182 -> V_184 & V_347 ) {
F_6 ( V_210 , V_194 L_45 , V_182 -> V_235 ) ;
V_2 -> V_346 |= ( V_348 | V_349 | V_350 ) ;
}
else if ( ( F_102 ( V_182 ) > V_2 -> V_351 ) ||
( V_182 -> V_184 & V_352 ) ) {
F_13 ( V_2 ,
V_353 ,
V_354 ,
V_81 ,
8 ,
V_343
) ;
V_2 -> V_346 |= ( V_348 | V_349 ) ;
}
else {
memset ( V_342 , 0 , sizeof( V_342 ) ) ;
F_103 (ha, dev) {
int V_355 = F_93 ( V_4 , V_341 -> V_356 ) >> 26 ;
V_342 [ V_355 >> 5 ] |= F_104 ( 1 << ( V_355 & 31 ) ) ;
}
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
F_105 ( V_2 , V_61 , * ( ( T_1 * ) & V_342 [ 0 ] + V_61 ) ) ;
F_105 ( V_2 , V_61 + 4 , * ( ( T_1 * ) & V_342 [ 1 ] + V_61 ) ) ;
}
V_2 -> V_346 &= ~ ( V_350 ) ;
V_2 -> V_346 |= ( V_348 | V_349 ) ;
}
if ( V_58 -> V_291 == V_292 ) {
V_2 -> V_346 |= ( V_348 | V_349 ) ;
V_2 -> V_346 &= ~ ( V_350 ) ;
}
F_16 ( V_2 , V_81 , V_345 , V_2 -> V_346 ) ;
F_6 ( V_70 , V_71 L_46 , V_2 -> V_346 ) ;
F_11 ( & V_2 -> V_72 ) ;
}
static struct V_310 * F_106 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
return & V_2 -> V_311 ;
}
static int F_107 ( struct V_192 * V_182 , struct V_357 * V_358 , int V_359 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_360 * V_361 = (struct V_360 * ) V_358 ;
int V_191 = 0 ;
switch ( V_359 ) {
case V_362 :
if ( ! ( V_2 -> V_184 & V_185 ) )
V_191 = - V_363 ;
V_191 = F_108 ( V_2 , & V_361 -> V_364 . V_47 ) ;
break;
case V_365 :
return F_109 ( V_182 , ( void * ) V_358 -> V_366 ) ;
}
return V_191 ;
}
static int F_109 ( struct V_192 * V_182 , void * V_367 )
{
T_7 V_368 ;
if ( F_110 ( & V_368 , V_367 , sizeof( V_368 ) ) )
return - V_363 ;
switch ( V_368 ) {
case V_369 : {
struct V_370 V_371 = { V_369 } ;
strncpy ( V_371 . V_372 , V_373 , sizeof( V_371 . V_372 ) - 1 ) ;
strncpy ( V_371 . V_374 , V_196 , sizeof( V_371 . V_374 ) - 1 ) ;
if ( F_111 ( V_367 , & V_371 , sizeof( V_371 ) ) )
return - V_363 ;
return 0 ;
}
}
return - V_375 ;
}
