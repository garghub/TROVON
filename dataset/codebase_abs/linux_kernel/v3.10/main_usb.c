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
V_2 -> V_44 = 0 ;
V_2 -> V_45 = false ;
V_2 -> V_46 = false ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_47 ) ;
V_2 -> V_47 . V_48 = ( unsigned long ) V_2 ;
V_2 -> V_47 . V_49 = ( V_50 ) V_51 ;
V_2 -> V_47 . V_52 = F_4 ( V_53 ) ;
F_3 ( & V_2 -> V_54 ) ;
V_2 -> V_54 . V_48 = ( unsigned long ) V_2 ;
V_2 -> V_54 . V_49 = ( V_50 ) V_51 ;
V_2 -> V_54 . V_52 = F_4 ( V_53 ) ;
F_3 ( & V_2 -> V_55 ) ;
V_2 -> V_55 . V_48 = ( unsigned long ) V_2 ;
V_2 -> V_55 . V_49 = ( V_50 ) V_56 ;
V_2 -> V_55 . V_52 = F_4 ( V_53 ) ;
return;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_57 )
{
struct V_58 * V_59 = & V_2 -> V_60 ;
T_1 V_3 [ V_4 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_5 [ V_4 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_1 V_6 [ V_4 ]
= { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0xf8 } ;
T_1 V_61 ;
int V_62 ;
T_3 V_63 ;
int V_64 = V_65 ;
T_4 V_66 ;
T_1 V_67 ;
T_1 V_68 = 0 , V_69 = 0 , V_70 = 0 ;
F_6 ( V_71 , V_72 L_1 , V_57 , V_2 -> V_37 ) ;
F_7 ( & V_2 -> V_73 ) ;
if ( V_57 == V_74 ) {
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
memcpy ( V_2 -> V_5 , V_5 , V_4 ) ;
memcpy ( V_2 -> V_6 ,
V_6 ,
V_4 ) ;
if ( ! F_8 ( V_2 ) ) {
if ( F_9 ( V_2 ) == true ) {
if ( F_10 ( V_2 ) == false ) {
F_6 ( V_71 , V_72 L_2 ) ;
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
} else {
F_6 ( V_71 , V_72 L_3 ) ;
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
}
if ( ! F_12 ( V_2 ) ) {
F_6 ( V_71 , V_72 L_4 ) ;
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
}
V_63 . V_75 = ( T_1 ) V_57 ;
V_63 . V_45 = ( T_1 ) V_2 -> V_45 ;
for ( V_62 = 0 ; V_62 < 6 ; V_62 ++ )
V_63 . V_76 [ V_62 ] = V_2 -> V_77 [ V_62 ] ;
V_63 . V_17 = V_2 -> V_17 ;
V_63 . V_19 = V_2 -> V_19 ;
V_64 = F_13 ( V_2 ,
V_78 ,
0 ,
0 ,
sizeof( T_3 ) ,
( T_1 * ) & ( V_63 ) ) ;
if ( V_64 != V_65 ) {
F_6 ( V_71 , V_72 L_5 ) ;
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
if ( V_57 == V_74 ) {
V_64 = F_14 ( V_2 , V_79 , 0 , 0 , sizeof( T_4 ) , ( T_1 * ) & ( V_66 ) ) ;
if ( V_64 != V_65 ) {
F_6 ( V_71 , V_72 L_6 ) ;
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
V_64 = F_14 ( V_2 ,
V_80 ,
V_81 ,
V_82 ,
1 ,
& V_2 -> V_83 ) ;
if ( V_64 != V_65 ) {
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
V_2 -> V_84 = true ;
V_2 -> V_85 = false ;
V_2 -> V_86 = false ;
V_2 -> V_87 = false ;
if ( V_2 -> V_34 ) {
V_2 -> V_88 = ( V_89 ) V_2 -> V_31 ;
} else {
if ( V_2 -> V_35 == V_90 )
V_2 -> V_88 = V_91 ;
else
V_2 -> V_88 = V_92 ;
}
F_15 ( V_2 ) ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 = V_96 ;
V_2 -> V_97 = 0 ;
V_2 -> V_98 = 0xFF ;
V_2 -> V_99 = V_2 -> V_100 [ V_101 ] ;
V_2 -> V_102 = V_2 -> V_100 [ V_103 ] ;
for ( V_62 = 0 ; V_62 < 14 ; V_62 ++ ) {
V_2 -> V_104 [ V_62 ] = V_2 -> V_100 [ V_62 + V_105 ] ;
if ( V_2 -> V_104 [ V_62 ] == 0 )
V_2 -> V_104 [ V_62 ] = V_2 -> V_99 ;
V_2 -> V_106 [ V_62 ] = V_2 -> V_100 [ V_62 + V_107 ] ;
if ( V_2 -> V_106 [ V_62 ] == 0 )
V_2 -> V_106 [ V_62 ] = V_2 -> V_102 ;
}
if( ( ( V_2 -> V_100 [ V_108 ] == V_109 ) ||
( V_2 -> V_100 [ V_108 ] == V_110 ) ) &&
( V_2 -> V_111 == V_112 ) ) {
for ( V_62 = 11 ; V_62 < 14 ; V_62 ++ ) {
V_2 -> V_104 [ V_62 ] = V_2 -> V_104 [ 10 ] ;
V_2 -> V_106 [ V_62 ] = V_2 -> V_106 [ 10 ] ;
}
}
V_2 -> V_113 = 0x34 ;
for ( V_62 = 0 ; V_62 < V_114 ; V_62 ++ ) {
V_2 -> V_115 [ V_62 ] = V_2 -> V_100 [ V_62 + V_116 ] ;
if ( V_2 -> V_115 [ V_62 ] == 0 )
V_2 -> V_115 [ V_62 ] = V_2 -> V_113 ;
}
V_61 = V_2 -> V_100 [ V_117 ] ;
if ( V_61 & V_118 )
V_2 -> V_119 = true ;
else
V_2 -> V_119 = false ;
V_61 &= ( V_120 | V_121 ) ;
if ( V_61 == 0 )
V_61 = ( V_120 | V_121 ) ;
if ( V_61 == ( V_120 | V_121 ) ) {
V_2 -> V_122 = 2 ;
V_2 -> V_123 = V_124 ;
V_2 -> V_125 = 1 ;
V_2 -> V_126 = 1 ;
if ( V_2 -> V_119 == true )
V_2 -> V_127 = V_128 ;
else
V_2 -> V_127 = V_124 ;
if ( V_2 -> V_46 )
V_2 -> V_129 = true ;
else
V_2 -> V_129 = false ;
} else {
V_2 -> V_129 = false ;
V_2 -> V_122 = 1 ;
V_2 -> V_125 = 0 ;
V_2 -> V_126 = 0 ;
if ( V_61 & V_120 ) {
V_2 -> V_123 = V_128 ;
if ( V_2 -> V_119 == true )
V_2 -> V_127 = V_124 ;
else
V_2 -> V_127 = V_128 ;
} else {
V_2 -> V_123 = V_124 ;
if ( V_2 -> V_119 == true )
V_2 -> V_127 = V_128 ;
else
V_2 -> V_127 = V_124 ;
}
}
V_2 -> V_130 = 100 * 255 ;
V_2 -> V_131 = 100 * 16 ;
V_2 -> V_132 = 1 ;
V_2 -> V_133 = 4 ;
V_2 -> V_134 = 0 ;
V_2 -> V_135 = 64 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_136 = V_137 ;
V_2 -> V_138 = V_139 ;
V_2 -> V_35 = V_140 ;
V_2 -> V_141 = 25 ;
V_2 -> V_142 = 1 ;
V_2 -> V_143 = V_144 ;
V_2 -> V_145 = V_66 . V_145 ;
if ( ( V_2 -> V_145 & V_146 ) != 0 ) {
V_2 -> V_97 = 0x80 ;
}
if ( V_2 -> V_145 == V_147 ) {
if( ( V_2 -> V_100 [ V_148 ] == 0x1 ) &&
( V_2 -> V_100 [ V_149 ] >= 0x4 ) ) {
V_68 = V_2 -> V_100 [ V_150 ] ;
V_69 = V_2 -> V_100 [ V_151 ] ;
V_70 = V_2 -> V_100 [ V_152 ] ;
if( ( V_68 || V_69 || V_70 ) ) {
F_16 ( V_2 ,
V_153 ,
0xFF ,
0x03 ) ;
F_16 ( V_2 ,
V_153 ,
0xFB ,
V_68 ) ;
F_16 ( V_2 ,
V_153 ,
0xFC ,
V_69 ) ;
F_16 ( V_2 ,
V_153 ,
0xFD ,
V_70 ) ;
} else {
F_16 ( V_2 ,
V_153 ,
0xFF ,
0x0 ) ;
}
}
}
V_59 -> V_154 = V_155 ;
V_59 -> V_156 = V_2 -> V_11 ;
V_59 -> V_157 = V_2 -> V_11 ;
F_17 ( V_2 , V_59 -> V_156 ) ;
memcpy ( V_2 -> V_158 , & ( V_66 . V_159 [ 0 ] ) , 6 ) ;
memcpy ( V_2 -> V_77 ,
V_2 -> V_158 ,
V_4 ) ;
F_6 ( V_71 , V_72 L_7 ,
V_2 -> V_77 ) ;
}
if ( V_2 -> V_35 == V_160 ) {
F_18 ( V_2 , V_161 ) ;
V_2 -> V_162 = true ;
} else {
F_18 ( V_2 , V_96 ) ;
V_2 -> V_162 = false ;
}
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_40 ) {
V_2 -> V_163 = V_2 -> V_164 [ 0 ] ;
V_2 -> V_165 = V_2 -> V_163 ;
F_21 ( V_2 , V_2 -> V_164 [ 0 ] ) ;
}
V_2 -> V_166 = V_2 -> V_100 [ V_167 ] ;
V_2 -> V_168 = false ;
if ( ( V_2 -> V_166 & V_169 ) != 0 ) {
V_64 = F_14 ( V_2 ,
V_80 ,
V_170 ,
V_82 ,
1 ,
& V_67 ) ;
if ( V_64 != V_65 ) {
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
if ( ( V_67 & V_171 ) == 0 ) {
V_2 -> V_168 = true ;
F_22 ( V_2 , V_170 , V_172 ) ;
} else {
F_23 ( V_2 , V_170 , V_172 ) ;
V_2 -> V_168 = false ;
}
}
F_24 ( V_2 , V_82 , V_173 , V_174 , 0x38 ) ;
F_24 ( V_2 , V_82 , V_173 , V_175 , V_176 ) ;
F_22 ( V_2 , V_177 , 0x01 ) ;
if ( ( V_2 -> V_168 == true ) || ( V_2 -> V_178 == true ) ) {
F_25 ( V_2 ) ;
} else {
F_26 ( V_2 ) ;
}
F_11 ( & V_2 -> V_73 ) ;
F_6 ( V_71 , V_72 L_8 ) ;
return true ;
}
static int F_27 ( struct V_179 * V_180 , T_5 V_181 )
{
struct V_1 * V_182 = F_28 ( V_180 ) ;
if ( ! V_182 || ! V_182 -> V_183 )
return - V_184 ;
if ( V_182 -> V_185 & V_186 )
F_29 ( V_182 -> V_183 ) ;
return 0 ;
}
static int F_30 ( struct V_179 * V_180 )
{
struct V_1 * V_182 = F_28 ( V_180 ) ;
if ( ! V_182 || ! V_182 -> V_183 )
return - V_184 ;
if ( ! ( V_182 -> V_185 & V_186 ) )
F_31 ( V_182 -> V_183 ) ;
return 0 ;
}
static int
F_32 ( struct V_179 * V_180 , const struct V_187 * V_188 )
{
T_1 V_189 [ V_4 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ;
struct V_190 * V_191 = F_33 ( V_180 ) ;
int V_192 = 0 ;
struct V_193 * V_194 = NULL ;
struct V_1 * V_2 ;
F_34 ( V_195 L_9 , V_196 , V_197 ) ;
F_34 ( V_195 L_10 ) ;
V_191 = F_35 ( V_191 ) ;
V_194 = F_36 ( sizeof( struct V_1 ) ) ;
if ( ! V_194 ) {
F_34 (KERN_ERR DEVICE_NAME L_11 ) ;
V_192 = - V_198 ;
goto V_199;
}
V_2 = F_37 ( V_194 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_183 = V_194 ;
V_2 -> V_200 = V_191 ;
F_1 ( V_2 ) ;
F_38 ( & V_2 -> V_73 ) ;
V_2 -> V_201 = V_202 ;
V_2 -> V_60 . V_203 = ( void * ) V_2 ;
V_194 -> V_204 = & V_205 ;
V_194 -> V_206 =
(struct V_207 * ) & V_208 ;
F_39 ( V_180 , V_2 ) ;
F_40 ( V_194 , & V_180 -> V_183 ) ;
memcpy ( V_2 -> V_183 -> V_209 , V_189 , V_4 ) ;
V_192 = F_41 ( V_194 ) ;
if ( V_192 ) {
F_34 (KERN_ERR DEVICE_NAME L_12 ) ;
goto V_210;
}
F_42 ( V_2 ) ;
return 0 ;
V_210:
F_43 ( V_194 ) ;
V_199:
F_44 ( V_191 ) ;
return V_192 ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_6 V_211 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_7 ; V_62 ++ ) {
V_211 = V_2 -> V_212 [ V_62 ] ;
if ( V_211 -> V_213 ) {
F_46 ( V_211 -> V_213 ) ;
F_47 ( V_211 -> V_213 ) ;
}
F_48 ( V_211 ) ;
}
return;
}
static void F_49 ( struct V_1 * V_2 )
{
T_7 V_214 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_9 ; V_62 ++ ) {
V_214 = V_2 -> V_215 [ V_62 ] ;
if ( V_214 -> V_213 ) {
F_46 ( V_214 -> V_213 ) ;
F_47 ( V_214 -> V_213 ) ;
}
if ( V_214 -> V_216 )
F_50 ( V_214 -> V_216 ) ;
}
F_48 ( V_2 -> V_217 ) ;
return;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_218 ;
V_218 = F_51 ( V_2 -> V_200 ) ;
if ( V_218 )
F_34 ( L_13 , V_218 ) ;
return ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_219 . V_220 ) ;
return;
}
static bool F_53 ( struct V_1 * V_2 )
{
T_6 V_211 ;
T_7 V_214 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_7 ; V_62 ++ ) {
V_211 = F_54 ( sizeof( V_221 ) , V_222 ) ;
if ( V_211 == NULL ) {
F_6 ( V_223 , V_224 L_14 , V_2 -> V_183 -> V_225 ) ;
goto V_226;
}
V_2 -> V_212 [ V_62 ] = V_211 ;
V_211 -> V_2 = ( void * ) V_2 ;
V_211 -> V_213 = F_55 ( 0 , V_227 ) ;
if ( V_211 -> V_213 == NULL ) {
F_6 ( V_223 , V_224 L_15 ) ;
goto V_226;
}
V_211 -> V_228 = false ;
}
V_2 -> V_217 = F_56 ( ( sizeof( V_229 ) * V_2 -> V_9 ) , V_222 ) ;
if ( V_2 -> V_217 == NULL ) {
F_6 ( V_223 , V_224 L_16 , V_2 -> V_183 -> V_225 ) ;
goto V_226;
}
V_2 -> V_230 = NULL ;
V_2 -> V_231 = NULL ;
V_2 -> V_232 = NULL ;
V_2 -> V_233 = NULL ;
V_2 -> V_234 = 0 ;
V_214 = ( T_7 ) V_2 -> V_217 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_9 ; V_62 ++ ) {
V_2 -> V_215 [ V_62 ] = V_214 ;
V_214 -> V_2 = ( void * ) V_2 ;
V_214 -> V_213 = F_55 ( 0 , V_227 ) ;
if ( V_214 -> V_213 == NULL ) {
F_6 ( V_223 , V_224 L_17 ) ;
goto V_235;
}
V_214 -> V_216 = F_57 ( ( int ) V_2 -> V_236 ) ;
if ( V_214 -> V_216 == NULL ) {
F_6 ( V_223 , V_224 L_18 ) ;
goto V_235;
}
V_214 -> V_216 -> V_183 = V_2 -> V_183 ;
V_214 -> V_228 = false ;
F_58 ( V_2 -> V_230 , V_2 -> V_231 , V_214 ) ;
V_2 -> V_234 ++ ;
V_214 ++ ;
}
V_2 -> V_237 = F_55 ( 0 , V_227 ) ;
if ( V_2 -> V_237 == NULL ) {
F_6 ( V_223 , V_224 L_19 ) ;
goto V_235;
}
V_2 -> V_238 = F_55 ( 0 , V_227 ) ;
if ( V_2 -> V_238 == NULL ) {
F_6 ( V_223 , V_224 L_20 ) ;
F_47 ( V_2 -> V_237 ) ;
goto V_235;
}
V_2 -> V_219 . V_220 = F_54 ( V_239 , V_222 ) ;
if ( V_2 -> V_219 . V_220 == NULL ) {
F_6 ( V_223 , V_224 L_21 ) ;
F_47 ( V_2 -> V_237 ) ;
F_47 ( V_2 -> V_238 ) ;
goto V_235;
}
return true ;
V_235:
F_49 ( V_2 ) ;
V_226:
F_45 ( V_2 ) ;
return false ;
}
static bool F_59 ( struct V_1 * V_2 )
{
int V_240 ;
T_8 V_241 ;
for ( V_240 = 0 ; V_240 < V_242 ; V_240 ++ ) {
V_241 = & ( V_2 -> V_243 [ V_240 ] ) ;
if ( ! F_60 ( V_2 , V_241 ) ) {
F_6 ( V_223 , V_224 L_22 ,
V_2 -> V_183 -> V_225 ) ;
goto V_244;
}
}
V_2 -> V_245 = V_242 ;
V_2 -> V_246 = V_2 -> V_245 ;
return true ;
V_244:
F_61 ( V_2 ) ;
return false ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_8 V_241 ;
int V_240 ;
for ( V_240 = 0 ; V_240 < V_242 ; V_240 ++ ) {
V_241 = & ( V_2 -> V_243 [ V_240 ] ) ;
if ( V_241 -> V_216 )
F_50 ( V_241 -> V_216 ) ;
}
}
int F_60 ( struct V_1 * V_2 ,
T_8 V_241 )
{
V_241 -> V_216 = F_57 ( ( int ) V_2 -> V_236 ) ;
if ( V_241 -> V_216 == NULL )
return false ;
ASSERT ( V_241 -> V_216 ) ;
V_241 -> V_216 -> V_183 = V_2 -> V_183 ;
return true ;
}
static int F_31 ( struct V_193 * V_183 )
{
struct V_1 * V_2 = F_37 ( V_183 ) ;
V_2 -> V_247 = false ;
F_6 ( V_71 , V_72 L_23 ) ;
V_2 -> V_236 = V_248 ;
if ( F_53 ( V_2 ) == false ) {
F_6 ( V_71 , V_72 L_24 ) ;
return - V_198 ;
}
if ( F_59 ( V_2 ) == false ) {
F_6 ( V_71 , V_72 L_25 ) ;
goto V_235;
}
F_62 ( V_2 , V_249 ) ;
F_62 ( V_2 , V_250 ) ;
F_62 ( V_2 , V_251 ) ;
F_63 ( V_2 , V_252 ) ;
F_63 ( V_2 , V_253 ) ;
F_64 ( V_2 ) ;
if ( F_5 ( V_2 , V_74 ) == false ) {
F_6 ( V_71 , V_72 L_26 ) ;
goto V_254;
}
F_65 ( V_2 -> V_183 ) ;
F_66 ( V_2 , & V_2 -> V_255 ) ;
memcpy ( V_2 -> V_60 . V_256 ,
V_2 -> V_77 , V_4 ) ;
memcpy ( V_2 -> V_183 -> V_209 , V_2 -> V_77 , V_4 ) ;
V_2 -> V_257 = false ;
V_2 -> V_258 = false ;
V_2 -> V_259 = false ;
V_2 -> V_260 = false ;
V_2 -> V_261 = false ;
if ( V_2 -> V_46 ) {
F_2 ( V_2 ) ;
}
F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_262 , ( void * ) V_263 , ( unsigned long ) V_2 ) ;
F_68 ( & V_2 -> V_264 , ( void * ) V_265 , ( unsigned long ) V_2 ) ;
F_68 ( & V_2 -> V_266 , ( void * ) V_267 , ( unsigned long ) V_2 ) ;
F_69 ( & V_2 -> V_60 . V_268 ) ;
V_2 -> V_269 = 100 ;
V_2 -> V_270 = V_271 ;
V_2 -> V_272 = true ;
V_2 -> V_273 = false ;
V_2 -> V_274 = false ;
V_2 -> V_275 = false ;
V_2 -> V_276 = false ;
V_2 -> V_277 = false ;
V_2 -> V_278 = false ;
V_2 -> V_279 = false ;
V_2 -> V_280 = false ;
V_2 -> V_281 = 0 ;
V_265 ( V_2 ) ;
V_267 ( V_2 ) ;
if ( ( V_2 -> V_282 == true ) && ( V_2 -> V_283 == true ) ) {
F_7 ( & V_2 -> V_73 ) ;
F_70 ( V_2 ,
& ( V_2 -> V_255 ) ,
V_2 -> V_284 | ( 1 << 31 ) ,
V_2 -> V_285 ,
NULL ,
V_2 -> V_286 ,
V_287
) ;
F_11 ( & V_2 -> V_73 ) ;
V_2 -> V_270 = V_288 ;
}
if ( V_2 -> V_60 . V_289 == V_290 )
F_71 ( ( void * ) V_2 , V_291 , NULL ) ;
else
F_71 ( ( void * ) V_2 , V_292 , NULL ) ;
F_72 ( V_2 -> V_183 ) ;
V_2 -> V_185 |= V_186 ;
F_6 ( V_71 , V_72 L_27 ) ;
return 0 ;
V_254:
F_61 ( V_2 ) ;
V_235:
F_49 ( V_2 ) ;
F_45 ( V_2 ) ;
F_52 ( V_2 ) ;
F_46 ( V_2 -> V_237 ) ;
F_46 ( V_2 -> V_238 ) ;
F_47 ( V_2 -> V_237 ) ;
F_47 ( V_2 -> V_238 ) ;
F_6 ( V_71 , V_72 L_28 ) ;
return - V_198 ;
}
static int F_29 ( struct V_193 * V_183 )
{
struct V_1 * V_2 = F_37 ( V_183 ) ;
struct V_58 * V_59 = & V_2 -> V_60 ;
int V_293 ;
F_6 ( V_71 , V_72 L_29 ) ;
if ( V_2 == NULL )
return - V_184 ;
if ( V_2 -> V_294 ) {
F_71 ( ( void * ) V_2 , V_295 , NULL ) ;
F_73 ( 30 ) ;
}
memset ( V_59 -> V_296 , 0 , V_297 + V_298 + 1 ) ;
V_59 -> V_299 = false ;
V_2 -> V_282 = false ;
V_2 -> V_270 = V_271 ;
F_7 ( & V_2 -> V_73 ) ;
for ( V_293 = 0 ; V_293 < V_300 ; V_293 ++ )
F_74 ( V_2 , V_293 ) ;
F_11 ( & V_2 -> V_73 ) ;
if ( ( V_2 -> V_185 & V_301 ) == false ) {
F_75 ( V_2 ) ;
}
F_72 ( V_2 -> V_183 ) ;
F_63 ( V_2 , V_249 ) ;
F_62 ( V_2 , V_253 ) ;
F_62 ( V_2 , V_252 ) ;
V_2 -> V_273 = true ;
F_76 ( & V_2 -> V_302 ) ;
F_76 ( & V_59 -> V_268 ) ;
F_76 ( & V_2 -> V_303 ) ;
if ( V_2 -> V_46 ) {
F_76 ( & V_2 -> V_47 ) ;
F_76 ( & V_2 -> V_54 ) ;
F_76 ( & V_2 -> V_55 ) ;
}
F_77 ( & V_2 -> V_262 ) ;
F_77 ( & V_2 -> V_264 ) ;
F_77 ( & V_2 -> V_266 ) ;
V_2 -> V_259 = false ;
V_2 -> V_260 = false ;
V_2 -> V_261 = false ;
V_2 -> V_304 = false ;
V_2 -> V_294 = false ;
memset ( V_59 -> V_305 , 0 , 6 ) ;
V_59 -> V_306 = V_307 ;
F_45 ( V_2 ) ;
F_49 ( V_2 ) ;
F_52 ( V_2 ) ;
F_61 ( V_2 ) ;
F_46 ( V_2 -> V_237 ) ;
F_46 ( V_2 -> V_238 ) ;
F_47 ( V_2 -> V_237 ) ;
F_47 ( V_2 -> V_238 ) ;
F_78 ( V_2 , 0 ) ;
V_2 -> V_185 &= ( ~ V_186 ) ;
F_6 ( V_71 , V_72 L_30 ) ;
return 0 ;
}
static void F_79 ( struct V_179 * V_180 )
{
struct V_1 * V_182 = F_28 ( V_180 ) ;
if ( ! V_182 )
return;
F_39 ( V_180 , NULL ) ;
F_44 ( F_33 ( V_180 ) ) ;
V_182 -> V_185 |= V_301 ;
if ( V_182 -> V_183 ) {
F_80 ( V_182 -> V_183 ) ;
F_43 ( V_182 -> V_183 ) ;
}
}
static int V_202 ( struct V_308 * V_216 , struct V_193 * V_183 )
{
struct V_1 * V_2 = F_37 ( V_183 ) ;
F_7 ( & V_2 -> V_73 ) ;
if ( F_81 ( V_2 -> V_257 ) )
F_82 ( V_216 ) ;
else
F_83 ( V_2 , V_216 ) ;
F_11 ( & V_2 -> V_73 ) ;
return V_309 ;
}
static int F_84 ( struct V_308 * V_216 , struct V_193 * V_183 )
{
struct V_1 * V_2 = F_37 ( V_183 ) ;
struct V_310 * V_311 = & V_2 -> V_311 ;
F_7 ( & V_2 -> V_73 ) ;
F_72 ( V_183 ) ;
if ( ! V_2 -> V_294 ) {
F_82 ( V_216 ) ;
goto V_312;
}
if ( V_2 -> V_258 ) {
F_82 ( V_216 ) ;
V_311 -> V_313 ++ ;
goto V_312;
}
if ( F_85 ( V_2 , V_314 , V_216 ) ) {
if ( F_86 ( V_183 ) )
F_87 ( V_183 ) ;
}
V_312:
F_11 ( & V_2 -> V_73 ) ;
return V_309 ;
}
static inline T_9 F_88 ( int V_315 , unsigned char * V_48 )
{
int V_316 = - 1 ;
while( -- V_315 >= 0 ) {
unsigned char V_317 = * V_48 ++ ;
int V_318 ;
for ( V_318 = 0 ; V_318 < 8 ; V_318 ++ , V_317 >>= 1 ) {
V_316 = ( V_316 << 1 ) ^
( ( V_316 < 0 ) ^ ( V_317 & 1 ) ? V_319 : 0 ) ;
}
}
return V_316 ;
}
static unsigned char * F_89 ( const unsigned char * V_320 ,
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
static int F_90 ( unsigned char * string ,
unsigned char * V_324 ,
unsigned char * V_325 )
{
unsigned char V_326 [ 100 ] ;
unsigned char V_327 [ 100 ] ;
unsigned char * V_328 = NULL , * V_329 = NULL , * V_330 = NULL ;
int V_62 ;
memset ( V_326 , 0 , 100 ) ;
strcat ( V_326 , string ) ;
strcat ( V_326 , L_31 ) ;
V_325 += strlen ( V_326 ) ;
V_328 = F_89 ( V_325 , V_326 ) ;
if ( V_328 == NULL )
return false ;
for ( V_62 = 1 ; ; V_62 ++ ) {
if ( memcmp ( V_328 - V_62 , L_32 , 1 ) == 0 )
break;
if ( memcmp ( V_328 - V_62 , L_33 , 1 ) == 0 )
return false ;
}
V_329 = F_89 ( V_328 , L_32 ) ;
if ( V_329 == NULL ) {
V_329 = V_328 + strlen ( V_328 ) ;
}
memset ( V_327 , 0 , 100 ) ;
memcpy ( V_327 , V_328 , V_329 - V_328 ) ;
V_327 [ V_329 - V_328 ] = '\0' ;
V_328 = F_89 ( V_327 , L_31 ) ;
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
static unsigned char * F_91 ( struct V_1 * V_2 )
{
unsigned char * V_331 = F_54 ( 1024 , V_222 ) ;
struct V_332 * V_332 ;
if ( ! V_331 ) {
F_34 ( L_34 ) ;
return NULL ;
}
V_332 = F_92 ( V_333 , V_334 , 0 ) ;
if ( F_93 ( V_332 ) ) {
F_48 ( V_331 ) ;
F_34 ( L_35 ) ;
return NULL ;
}
if ( F_94 ( V_332 , 0 , V_331 , 1024 ) < 0 ) {
F_34 ( L_36 ) ;
F_48 ( V_331 ) ;
V_331 = NULL ;
}
F_95 ( V_332 ) ;
return V_331 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_335 = 0 ;
unsigned char V_336 [ 100 ] ;
unsigned char * V_331 = NULL ;
V_2 -> V_337 . V_338 = - 1 ;
V_2 -> V_337 . V_339 = - 1 ;
V_2 -> V_337 . V_270 = - 1 ;
V_331 = F_91 ( V_2 ) ;
if ( V_331 == NULL ) {
V_335 = - 1 ;
return V_335 ;
}
{
memset ( V_336 , 0 , sizeof( V_336 ) ) ;
if( F_90 ( L_37 , V_336 , V_331 ) == true ) {
if( memcmp ( V_336 , L_38 , 3 ) == 0 ) {
V_2 -> V_337 . V_338 = V_112 ;
}
else if( memcmp ( V_336 , L_39 , 5 ) == 0 ) {
V_2 -> V_337 . V_338 = V_109 ;
}
else if( memcmp ( V_336 , L_40 , 6 ) == 0 ) {
V_2 -> V_337 . V_338 = V_110 ;
}
else {
F_34 ( L_41 , V_336 ) ;
}
}
}
{
memset ( V_336 , 0 , sizeof( V_336 ) ) ;
if( F_90 ( L_42 , V_336 , V_331 ) == true ) {
V_2 -> V_337 . V_339 = ( int ) F_96 ( V_336 , NULL , 10 ) ;
}
memset ( V_336 , 0 , sizeof( V_336 ) ) ;
if( F_90 ( L_43 , V_336 , V_331 ) == true ) {
V_2 -> V_337 . V_270 = ( int ) F_96 ( V_336 , NULL , 10 ) ;
}
}
F_48 ( V_331 ) ;
return V_335 ;
}
static void F_65 ( struct V_193 * V_183 )
{
struct V_1 * V_2 = F_37 ( V_183 ) ;
struct V_58 * V_59 = & V_2 -> V_60 ;
struct V_340 * V_341 ;
T_9 V_342 [ 2 ] ;
int V_62 ;
T_1 V_343 [ 8 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_344 = 0 ;
int V_192 ;
F_7 ( & V_2 -> V_73 ) ;
V_192 = F_14 ( V_2 ,
V_80 ,
V_345 ,
V_82 ,
1 ,
& V_344
) ;
if ( V_192 == 0 ) V_2 -> V_346 = V_344 ;
F_6 ( V_71 , V_72 L_44 , V_2 -> V_346 ) ;
if ( V_183 -> V_185 & V_347 ) {
F_6 ( V_223 , V_195 L_45 , V_183 -> V_225 ) ;
V_2 -> V_346 |= ( V_348 | V_349 | V_350 ) ;
}
else if ( ( F_97 ( V_183 ) > V_2 -> V_351 ) ||
( V_183 -> V_185 & V_352 ) ) {
F_13 ( V_2 ,
V_353 ,
V_354 ,
V_82 ,
8 ,
V_343
) ;
V_2 -> V_346 |= ( V_348 | V_349 ) ;
}
else {
memset ( V_342 , 0 , sizeof( V_342 ) ) ;
F_98 (ha, dev) {
int V_355 = F_88 ( V_4 , V_341 -> V_356 ) >> 26 ;
V_342 [ V_355 >> 5 ] |= F_99 ( 1 << ( V_355 & 31 ) ) ;
}
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
F_100 ( V_2 , V_62 , * ( ( T_1 * ) & V_342 [ 0 ] + V_62 ) ) ;
F_100 ( V_2 , V_62 + 4 , * ( ( T_1 * ) & V_342 [ 1 ] + V_62 ) ) ;
}
V_2 -> V_346 &= ~ ( V_350 ) ;
V_2 -> V_346 |= ( V_348 | V_349 ) ;
}
if ( V_59 -> V_289 == V_290 ) {
V_2 -> V_346 |= ( V_348 | V_349 ) ;
V_2 -> V_346 &= ~ ( V_350 ) ;
}
F_16 ( V_2 , V_82 , V_345 , V_2 -> V_346 ) ;
F_6 ( V_71 , V_72 L_46 , V_2 -> V_346 ) ;
F_11 ( & V_2 -> V_73 ) ;
}
static struct V_310 * F_101 ( struct V_193 * V_183 )
{
struct V_1 * V_2 = F_37 ( V_183 ) ;
return & V_2 -> V_311 ;
}
static int F_102 ( struct V_193 * V_183 , struct V_357 * V_358 , int V_359 )
{
struct V_1 * V_2 = F_37 ( V_183 ) ;
struct V_360 * V_361 = (struct V_360 * ) V_358 ;
int V_192 = 0 ;
switch ( V_359 ) {
case V_362 :
if ( ! ( V_2 -> V_185 & V_186 ) )
V_192 = - V_363 ;
V_192 = F_103 ( V_2 , & V_361 -> V_364 . V_48 ) ;
break;
case V_365 :
return F_104 ( V_183 , ( void * ) V_358 -> V_366 ) ;
}
return V_192 ;
}
static int F_104 ( struct V_193 * V_183 , void * V_367 )
{
T_9 V_368 ;
if ( F_105 ( & V_368 , V_367 , sizeof( V_368 ) ) )
return - V_363 ;
switch ( V_368 ) {
case V_369 : {
struct V_370 V_371 = { V_369 } ;
strncpy ( V_371 . V_372 , V_373 , sizeof( V_371 . V_372 ) - 1 ) ;
strncpy ( V_371 . V_374 , V_197 , sizeof( V_371 . V_374 ) - 1 ) ;
if ( F_106 ( V_367 , & V_371 , sizeof( V_371 ) ) )
return - V_363 ;
return 0 ;
}
}
return - V_375 ;
}
