static void
F_1 ( struct V_1 * V_2 ) {
T_1 V_3 [ V_4 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_5 [ V_4 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_2 V_6 [ V_4 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0xF8 } ;
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
T_3 V_57 )
{
struct V_58 * V_59 = & V_2 -> V_60 ;
T_2 V_3 [ V_4 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_2 V_5 [ V_4 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_2 V_6 [ V_4 ]
= { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0xf8 } ;
T_2 V_61 ;
int V_62 ;
T_4 V_63 ;
int V_64 = V_65 ;
T_5 V_66 ;
T_2 V_67 ;
T_2 V_68 = 0 , V_69 = 0 , V_70 = 0 ;
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
sizeof( T_4 ) ,
( V_79 ) & ( V_63 ) ) ;
if ( V_64 != V_65 ) {
F_6 ( V_71 , V_72 L_5 ) ;
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
if ( V_57 == V_74 ) {
V_64 = F_14 ( V_2 , V_80 , 0 , 0 , sizeof( T_5 ) , ( V_79 ) & ( V_66 ) ) ;
if ( V_64 != V_65 ) {
F_6 ( V_71 , V_72 L_6 ) ;
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
V_64 = F_14 ( V_2 ,
V_81 ,
V_82 ,
V_83 ,
1 ,
& V_2 -> V_84 ) ;
if ( V_64 != V_65 ) {
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
V_2 -> V_85 = true ;
V_2 -> V_86 = false ;
V_2 -> V_87 = false ;
V_2 -> V_88 = false ;
if ( V_2 -> V_34 ) {
V_2 -> V_89 = ( V_90 ) V_2 -> V_31 ;
} else {
if ( V_2 -> V_35 == V_91 )
V_2 -> V_89 = V_92 ;
else
V_2 -> V_89 = V_93 ;
}
F_15 ( V_2 ) ;
V_2 -> V_94 = V_95 ;
V_2 -> V_96 = V_97 ;
V_2 -> V_98 = 0 ;
V_2 -> V_99 = 0xFF ;
V_2 -> V_100 = V_2 -> V_101 [ V_102 ] ;
V_2 -> V_103 = V_2 -> V_101 [ V_104 ] ;
for ( V_62 = 0 ; V_62 < 14 ; V_62 ++ ) {
V_2 -> V_105 [ V_62 ] = V_2 -> V_101 [ V_62 + V_106 ] ;
if ( V_2 -> V_105 [ V_62 ] == 0 )
V_2 -> V_105 [ V_62 ] = V_2 -> V_100 ;
V_2 -> V_107 [ V_62 ] = V_2 -> V_101 [ V_62 + V_108 ] ;
if ( V_2 -> V_107 [ V_62 ] == 0 )
V_2 -> V_107 [ V_62 ] = V_2 -> V_103 ;
}
if( ( ( V_2 -> V_101 [ V_109 ] == V_110 ) ||
( V_2 -> V_101 [ V_109 ] == V_111 ) ) &&
( V_2 -> V_112 == V_113 ) ) {
for ( V_62 = 11 ; V_62 < 14 ; V_62 ++ ) {
V_2 -> V_105 [ V_62 ] = V_2 -> V_105 [ 10 ] ;
V_2 -> V_107 [ V_62 ] = V_2 -> V_107 [ 10 ] ;
}
}
V_2 -> V_114 = 0x34 ;
for ( V_62 = 0 ; V_62 < V_115 ; V_62 ++ ) {
V_2 -> V_116 [ V_62 ] = V_2 -> V_101 [ V_62 + V_117 ] ;
if ( V_2 -> V_116 [ V_62 ] == 0 )
V_2 -> V_116 [ V_62 ] = V_2 -> V_114 ;
}
V_61 = V_2 -> V_101 [ V_118 ] ;
if ( V_61 & V_119 )
V_2 -> V_120 = true ;
else
V_2 -> V_120 = false ;
V_61 &= ( V_121 | V_122 ) ;
if ( V_61 == 0 )
V_61 = ( V_121 | V_122 ) ;
if ( V_61 == ( V_121 | V_122 ) ) {
V_2 -> V_123 = 2 ;
V_2 -> V_124 = V_125 ;
V_2 -> V_126 = 1 ;
V_2 -> V_127 = 1 ;
if ( V_2 -> V_120 == true )
V_2 -> V_128 = V_129 ;
else
V_2 -> V_128 = V_125 ;
if ( V_2 -> V_46 )
V_2 -> V_130 = true ;
else
V_2 -> V_130 = false ;
} else {
V_2 -> V_130 = false ;
V_2 -> V_123 = 1 ;
V_2 -> V_126 = 0 ;
V_2 -> V_127 = 0 ;
if ( V_61 & V_121 ) {
V_2 -> V_124 = V_129 ;
if ( V_2 -> V_120 == true )
V_2 -> V_128 = V_125 ;
else
V_2 -> V_128 = V_129 ;
} else {
V_2 -> V_124 = V_125 ;
if ( V_2 -> V_120 == true )
V_2 -> V_128 = V_129 ;
else
V_2 -> V_128 = V_125 ;
}
}
V_2 -> V_131 = 100 * 255 ;
V_2 -> V_132 = 100 * 16 ;
V_2 -> V_133 = 1 ;
V_2 -> V_134 = 4 ;
V_2 -> V_135 = 0 ;
V_2 -> V_136 = 64 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_137 = V_138 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_35 = V_141 ;
V_2 -> V_142 = 25 ;
V_2 -> V_143 = 1 ;
V_2 -> V_144 = V_145 ;
V_2 -> V_146 = V_66 . V_146 ;
if ( ( V_2 -> V_146 & V_147 ) != 0 ) {
V_2 -> V_98 = 0x80 ;
}
if ( V_2 -> V_146 == V_148 ) {
if( ( V_2 -> V_101 [ V_149 ] == 0x1 ) &&
( V_2 -> V_101 [ V_150 ] >= 0x4 ) ) {
V_68 = V_2 -> V_101 [ V_151 ] ;
V_69 = V_2 -> V_101 [ V_152 ] ;
V_70 = V_2 -> V_101 [ V_153 ] ;
if( ( V_68 || V_69 || V_70 ) ) {
F_16 ( V_2 ,
V_154 ,
0xFF ,
0x03 ) ;
F_16 ( V_2 ,
V_154 ,
0xFB ,
V_68 ) ;
F_16 ( V_2 ,
V_154 ,
0xFC ,
V_69 ) ;
F_16 ( V_2 ,
V_154 ,
0xFD ,
V_70 ) ;
} else {
F_16 ( V_2 ,
V_154 ,
0xFF ,
0x0 ) ;
}
}
}
V_59 -> V_155 = V_156 ;
V_59 -> V_157 = V_2 -> V_11 ;
V_59 -> V_158 = V_2 -> V_11 ;
F_17 ( V_2 , V_59 -> V_157 ) ;
memcpy ( V_2 -> V_159 , & ( V_66 . V_160 [ 0 ] ) , 6 ) ;
memcpy ( V_2 -> V_77 ,
V_2 -> V_159 ,
V_4 ) ;
F_6 ( V_71 , V_72 L_7 ,
V_2 -> V_77 ) ;
}
if ( V_2 -> V_35 == V_161 ) {
F_18 ( V_2 , V_162 ) ;
V_2 -> V_163 = true ;
} else {
F_18 ( V_2 , V_97 ) ;
V_2 -> V_163 = false ;
}
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_40 ) {
V_2 -> V_164 = V_2 -> V_165 [ 0 ] ;
V_2 -> V_166 = V_2 -> V_164 ;
F_21 ( V_2 , V_2 -> V_165 [ 0 ] ) ;
}
V_2 -> V_167 = V_2 -> V_101 [ V_168 ] ;
V_2 -> V_169 = false ;
if ( ( V_2 -> V_167 & V_170 ) != 0 ) {
V_64 = F_14 ( V_2 ,
V_81 ,
V_171 ,
V_83 ,
1 ,
& V_67 ) ;
if ( V_64 != V_65 ) {
F_11 ( & V_2 -> V_73 ) ;
return false ;
}
if ( ( V_67 & V_172 ) == 0 ) {
V_2 -> V_169 = true ;
F_22 ( V_2 , V_171 , V_173 ) ;
} else {
F_23 ( V_2 , V_171 , V_173 ) ;
V_2 -> V_169 = false ;
}
}
F_24 ( V_2 , V_83 , V_174 , V_175 , 0x38 ) ;
F_24 ( V_2 , V_83 , V_174 , V_176 , V_177 ) ;
F_22 ( V_2 , V_178 , 0x01 ) ;
if ( ( V_2 -> V_169 == true ) || ( V_2 -> V_179 == true ) ) {
F_25 ( V_2 ) ;
} else {
F_26 ( V_2 ) ;
}
F_11 ( & V_2 -> V_73 ) ;
F_6 ( V_71 , V_72 L_8 ) ;
return true ;
}
static int F_27 ( struct V_180 * V_181 , T_6 V_182 )
{
struct V_1 * V_183 = F_28 ( V_181 ) ;
if ( ! V_183 || ! V_183 -> V_184 )
return - V_185 ;
if ( V_183 -> V_186 & V_187 )
F_29 ( V_183 -> V_184 ) ;
return 0 ;
}
static int F_30 ( struct V_180 * V_181 )
{
struct V_1 * V_183 = F_28 ( V_181 ) ;
if ( ! V_183 || ! V_183 -> V_184 )
return - V_185 ;
if ( ! ( V_183 -> V_186 & V_187 ) )
F_31 ( V_183 -> V_184 ) ;
return 0 ;
}
static int
F_32 ( struct V_180 * V_181 , const struct V_188 * V_189 )
{
T_2 V_190 [ V_4 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ;
struct V_191 * V_192 = F_33 ( V_181 ) ;
int V_193 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_1 * V_2 ;
F_34 ( V_196 L_9 , V_197 , V_198 ) ;
F_34 ( V_196 L_10 ) ;
V_192 = F_35 ( V_192 ) ;
V_195 = F_36 ( sizeof( struct V_1 ) ) ;
if ( ! V_195 ) {
F_34 (KERN_ERR DEVICE_NAME L_11 ) ;
V_193 = - V_199 ;
goto V_200;
}
V_2 = F_37 ( V_195 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_184 = V_195 ;
V_2 -> V_201 = V_192 ;
F_1 ( V_2 ) ;
F_38 ( & V_2 -> V_73 ) ;
V_2 -> V_202 = V_203 ;
V_2 -> V_60 . V_204 = ( void * ) V_2 ;
V_195 -> V_205 = & V_206 ;
V_195 -> V_207 =
(struct V_208 * ) & V_209 ;
F_39 ( V_181 , V_2 ) ;
F_40 ( V_195 , & V_181 -> V_184 ) ;
memcpy ( V_2 -> V_184 -> V_210 , V_190 , V_4 ) ;
V_193 = F_41 ( V_195 ) ;
if ( V_193 ) {
F_34 (KERN_ERR DEVICE_NAME L_12 ) ;
goto V_211;
}
F_42 ( V_2 ) ;
return 0 ;
V_211:
F_43 ( V_195 ) ;
V_200:
F_44 ( V_192 ) ;
return V_193 ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_7 V_212 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_7 ; V_62 ++ ) {
V_212 = V_2 -> V_213 [ V_62 ] ;
if ( V_212 -> V_214 ) {
F_46 ( V_212 -> V_214 ) ;
F_47 ( V_212 -> V_214 ) ;
}
F_48 ( V_212 ) ;
}
return;
}
static void F_49 ( struct V_1 * V_2 )
{
T_8 V_215 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_9 ; V_62 ++ ) {
V_215 = V_2 -> V_216 [ V_62 ] ;
if ( V_215 -> V_214 ) {
F_46 ( V_215 -> V_214 ) ;
F_47 ( V_215 -> V_214 ) ;
}
if ( V_215 -> V_217 )
F_50 ( V_215 -> V_217 ) ;
}
F_48 ( V_2 -> V_218 ) ;
return;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_219 ;
V_219 = F_51 ( V_2 -> V_201 ) ;
if ( V_219 )
F_34 ( L_13 , V_219 ) ;
return ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_220 . V_221 ) ;
return;
}
static bool F_53 ( struct V_1 * V_2 )
{
T_7 V_212 ;
T_8 V_215 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_7 ; V_62 ++ ) {
V_212 = F_54 ( sizeof( V_222 ) , V_223 ) ;
if ( V_212 == NULL ) {
F_6 ( V_224 , V_225 L_14 , V_2 -> V_184 -> V_226 ) ;
goto V_227;
}
V_2 -> V_213 [ V_62 ] = V_212 ;
V_212 -> V_2 = ( void * ) V_2 ;
V_212 -> V_214 = F_55 ( 0 , V_228 ) ;
if ( V_212 -> V_214 == NULL ) {
F_6 ( V_224 , V_225 L_15 ) ;
goto V_227;
}
V_212 -> V_229 = false ;
}
V_2 -> V_218 = F_56 ( ( sizeof( V_230 ) * V_2 -> V_9 ) , V_223 ) ;
if ( V_2 -> V_218 == NULL ) {
F_6 ( V_224 , V_225 L_16 , V_2 -> V_184 -> V_226 ) ;
goto V_227;
}
V_2 -> V_231 = NULL ;
V_2 -> V_232 = NULL ;
V_2 -> V_233 = NULL ;
V_2 -> V_234 = NULL ;
V_2 -> V_235 = 0 ;
V_215 = ( T_8 ) V_2 -> V_218 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_9 ; V_62 ++ ) {
V_2 -> V_216 [ V_62 ] = V_215 ;
V_215 -> V_2 = ( void * ) V_2 ;
V_215 -> V_214 = F_55 ( 0 , V_228 ) ;
if ( V_215 -> V_214 == NULL ) {
F_6 ( V_224 , V_225 L_17 ) ;
goto V_236;
}
V_215 -> V_217 = F_57 ( ( int ) V_2 -> V_237 ) ;
if ( V_215 -> V_217 == NULL ) {
F_6 ( V_224 , V_225 L_18 ) ;
goto V_236;
}
V_215 -> V_217 -> V_184 = V_2 -> V_184 ;
V_215 -> V_229 = false ;
F_58 ( V_2 -> V_231 , V_2 -> V_232 , V_215 ) ;
V_2 -> V_235 ++ ;
V_215 ++ ;
}
V_2 -> V_238 = F_55 ( 0 , V_228 ) ;
if ( V_2 -> V_238 == NULL ) {
F_6 ( V_224 , V_225 L_19 ) ;
goto V_236;
}
V_2 -> V_239 = F_55 ( 0 , V_228 ) ;
if ( V_2 -> V_239 == NULL ) {
F_6 ( V_224 , V_225 L_20 ) ;
F_47 ( V_2 -> V_238 ) ;
goto V_236;
}
V_2 -> V_220 . V_221 = F_54 ( V_240 , V_223 ) ;
if ( V_2 -> V_220 . V_221 == NULL ) {
F_6 ( V_224 , V_225 L_21 ) ;
F_47 ( V_2 -> V_238 ) ;
F_47 ( V_2 -> V_239 ) ;
goto V_236;
}
return true ;
V_236:
F_49 ( V_2 ) ;
V_227:
F_45 ( V_2 ) ;
return false ;
}
static bool F_59 ( struct V_1 * V_2 )
{
int V_241 ;
T_9 V_242 ;
for ( V_241 = 0 ; V_241 < V_243 ; V_241 ++ ) {
V_242 = & ( V_2 -> V_244 [ V_241 ] ) ;
if ( ! F_60 ( V_2 , V_242 ) ) {
F_6 ( V_224 , V_225 L_22 ,
V_2 -> V_184 -> V_226 ) ;
goto V_245;
}
}
V_2 -> V_246 = V_243 ;
V_2 -> V_247 = V_2 -> V_246 ;
return true ;
V_245:
F_61 ( V_2 ) ;
return false ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_9 V_242 ;
int V_241 ;
for ( V_241 = 0 ; V_241 < V_243 ; V_241 ++ ) {
V_242 = & ( V_2 -> V_244 [ V_241 ] ) ;
if ( V_242 -> V_217 )
F_50 ( V_242 -> V_217 ) ;
}
}
int F_60 ( struct V_1 * V_2 ,
T_9 V_242 )
{
V_242 -> V_217 = F_57 ( ( int ) V_2 -> V_237 ) ;
if ( V_242 -> V_217 == NULL )
return false ;
ASSERT ( V_242 -> V_217 ) ;
V_242 -> V_217 -> V_184 = V_2 -> V_184 ;
return true ;
}
static int F_31 ( struct V_194 * V_184 )
{
struct V_1 * V_2 = F_37 ( V_184 ) ;
V_2 -> V_248 = false ;
F_6 ( V_71 , V_72 L_23 ) ;
V_2 -> V_237 = V_249 ;
if ( F_53 ( V_2 ) == false ) {
F_6 ( V_71 , V_72 L_24 ) ;
return - V_199 ;
}
if ( F_59 ( V_2 ) == false ) {
F_6 ( V_71 , V_72 L_25 ) ;
goto V_236;
}
F_62 ( V_2 , V_250 ) ;
F_62 ( V_2 , V_251 ) ;
F_62 ( V_2 , V_252 ) ;
F_63 ( V_2 , V_253 ) ;
F_63 ( V_2 , V_254 ) ;
F_64 ( V_2 ) ;
if ( F_5 ( V_2 , V_74 ) == false ) {
F_6 ( V_71 , V_72 L_26 ) ;
goto V_255;
}
F_65 ( V_2 -> V_184 ) ;
F_66 ( V_2 , & V_2 -> V_256 ) ;
memcpy ( V_2 -> V_60 . V_257 ,
V_2 -> V_77 , V_4 ) ;
memcpy ( V_2 -> V_184 -> V_210 , V_2 -> V_77 , V_4 ) ;
V_2 -> V_258 = false ;
V_2 -> V_259 = false ;
V_2 -> V_260 = false ;
V_2 -> V_261 = false ;
V_2 -> V_262 = false ;
if ( V_2 -> V_46 ) {
F_2 ( V_2 ) ;
}
F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_263 , ( void * ) V_264 , ( unsigned long ) V_2 ) ;
F_68 ( & V_2 -> V_265 , ( void * ) V_266 , ( unsigned long ) V_2 ) ;
F_68 ( & V_2 -> V_267 , ( void * ) V_268 , ( unsigned long ) V_2 ) ;
F_69 ( & V_2 -> V_60 . V_269 ) ;
V_2 -> V_270 = 100 ;
V_2 -> V_271 = V_272 ;
V_2 -> V_273 = true ;
V_2 -> V_274 = false ;
V_2 -> V_275 = false ;
V_2 -> V_276 = false ;
V_2 -> V_277 = false ;
V_2 -> V_278 = false ;
V_2 -> V_279 = false ;
V_2 -> V_280 = false ;
V_2 -> V_281 = false ;
V_2 -> V_282 = 0 ;
V_266 ( V_2 ) ;
V_268 ( V_2 ) ;
if ( ( V_2 -> V_283 == true ) && ( V_2 -> V_284 == true ) ) {
F_7 ( & V_2 -> V_73 ) ;
F_70 ( V_2 ,
& ( V_2 -> V_256 ) ,
V_2 -> V_285 | ( 1 << 31 ) ,
V_2 -> V_286 ,
NULL ,
V_2 -> V_287 ,
V_288
) ;
F_11 ( & V_2 -> V_73 ) ;
V_2 -> V_271 = V_289 ;
}
if ( V_2 -> V_60 . V_290 == V_291 )
F_71 ( ( void * ) V_2 , V_292 , NULL ) ;
else
F_71 ( ( void * ) V_2 , V_293 , NULL ) ;
F_72 ( V_2 -> V_184 ) ;
V_2 -> V_186 |= V_187 ;
F_6 ( V_71 , V_72 L_27 ) ;
return 0 ;
V_255:
F_61 ( V_2 ) ;
V_236:
F_49 ( V_2 ) ;
F_45 ( V_2 ) ;
F_52 ( V_2 ) ;
F_46 ( V_2 -> V_238 ) ;
F_46 ( V_2 -> V_239 ) ;
F_47 ( V_2 -> V_238 ) ;
F_47 ( V_2 -> V_239 ) ;
F_6 ( V_71 , V_72 L_28 ) ;
return - V_199 ;
}
static int F_29 ( struct V_194 * V_184 )
{
struct V_1 * V_2 = F_37 ( V_184 ) ;
struct V_58 * V_59 = & V_2 -> V_60 ;
int V_294 ;
F_6 ( V_71 , V_72 L_29 ) ;
if ( V_2 == NULL )
return - V_185 ;
if ( V_2 -> V_295 ) {
F_71 ( ( void * ) V_2 , V_296 , NULL ) ;
F_73 ( 30 ) ;
}
memset ( V_59 -> V_297 , 0 , V_298 + V_299 + 1 ) ;
V_59 -> V_300 = false ;
V_2 -> V_283 = false ;
V_2 -> V_271 = V_272 ;
F_7 ( & V_2 -> V_73 ) ;
for ( V_294 = 0 ; V_294 < V_301 ; V_294 ++ )
F_74 ( V_2 , V_294 ) ;
F_11 ( & V_2 -> V_73 ) ;
if ( ( V_2 -> V_186 & V_302 ) == false ) {
F_75 ( V_2 ) ;
}
F_72 ( V_2 -> V_184 ) ;
F_63 ( V_2 , V_250 ) ;
F_62 ( V_2 , V_254 ) ;
F_62 ( V_2 , V_253 ) ;
V_2 -> V_274 = true ;
F_76 ( & V_2 -> V_303 ) ;
F_76 ( & V_59 -> V_269 ) ;
F_76 ( & V_2 -> V_304 ) ;
if ( V_2 -> V_46 ) {
F_76 ( & V_2 -> V_47 ) ;
F_76 ( & V_2 -> V_54 ) ;
F_76 ( & V_2 -> V_55 ) ;
}
F_77 ( & V_2 -> V_263 ) ;
F_77 ( & V_2 -> V_265 ) ;
F_77 ( & V_2 -> V_267 ) ;
V_2 -> V_260 = false ;
V_2 -> V_261 = false ;
V_2 -> V_262 = false ;
V_2 -> V_305 = false ;
V_2 -> V_295 = false ;
memset ( V_59 -> V_306 , 0 , 6 ) ;
V_59 -> V_307 = V_308 ;
F_45 ( V_2 ) ;
F_49 ( V_2 ) ;
F_52 ( V_2 ) ;
F_61 ( V_2 ) ;
F_46 ( V_2 -> V_238 ) ;
F_46 ( V_2 -> V_239 ) ;
F_47 ( V_2 -> V_238 ) ;
F_47 ( V_2 -> V_239 ) ;
F_78 ( V_2 , 0 ) ;
V_2 -> V_186 &= ( ~ V_187 ) ;
F_6 ( V_71 , V_72 L_30 ) ;
return 0 ;
}
static void F_79 ( struct V_180 * V_181 )
{
struct V_1 * V_183 = F_28 ( V_181 ) ;
if ( ! V_183 )
return;
F_39 ( V_181 , NULL ) ;
F_44 ( F_33 ( V_181 ) ) ;
V_183 -> V_186 |= V_302 ;
if ( V_183 -> V_184 ) {
F_80 ( V_183 -> V_184 ) ;
F_43 ( V_183 -> V_184 ) ;
}
}
static int V_203 ( struct V_309 * V_217 , struct V_194 * V_184 )
{
struct V_1 * V_2 = F_37 ( V_184 ) ;
F_7 ( & V_2 -> V_73 ) ;
if ( F_81 ( V_2 -> V_258 ) )
F_82 ( V_217 ) ;
else
F_83 ( V_2 , V_217 ) ;
F_11 ( & V_2 -> V_73 ) ;
return V_310 ;
}
static int F_84 ( struct V_309 * V_217 , struct V_194 * V_184 )
{
struct V_1 * V_2 = F_37 ( V_184 ) ;
struct V_311 * V_312 = & V_2 -> V_312 ;
F_7 ( & V_2 -> V_73 ) ;
F_72 ( V_184 ) ;
if ( ! V_2 -> V_295 ) {
F_82 ( V_217 ) ;
goto V_313;
}
if ( V_2 -> V_259 ) {
F_82 ( V_217 ) ;
V_312 -> V_314 ++ ;
goto V_313;
}
if ( F_85 ( V_2 , V_315 , V_217 ) ) {
if ( F_86 ( V_184 ) )
F_87 ( V_184 ) ;
}
V_313:
F_11 ( & V_2 -> V_73 ) ;
return V_310 ;
}
static inline T_10 F_88 ( int V_316 , unsigned char * V_48 )
{
int V_317 = - 1 ;
while( -- V_316 >= 0 ) {
unsigned char V_318 = * V_48 ++ ;
int V_319 ;
for ( V_319 = 0 ; V_319 < 8 ; V_319 ++ , V_318 >>= 1 ) {
V_317 = ( V_317 << 1 ) ^
( ( V_317 < 0 ) ^ ( V_318 & 1 ) ? V_320 : 0 ) ;
}
}
return V_317 ;
}
static unsigned char * F_89 ( const unsigned char * V_321 ,
const unsigned char * V_322 ) {
int V_323 = strlen ( V_321 ) ;
int V_324 = strlen ( V_322 ) ;
while ( V_323 >= V_324 ) {
V_323 -- ;
if( memcmp ( V_321 , V_322 , V_324 ) == 0 )
return ( unsigned char * ) V_321 ;
V_321 ++ ;
}
return NULL ;
}
static int F_90 ( unsigned char * string ,
unsigned char * V_325 ,
unsigned char * V_326 )
{
unsigned char V_327 [ 100 ] ;
unsigned char V_328 [ 100 ] ;
unsigned char * V_329 = NULL , * V_330 = NULL , * V_331 = NULL ;
int V_62 ;
memset ( V_327 , 0 , 100 ) ;
strcat ( V_327 , string ) ;
strcat ( V_327 , L_31 ) ;
V_326 += strlen ( V_327 ) ;
V_329 = F_89 ( V_326 , V_327 ) ;
if ( V_329 == NULL )
return false ;
for ( V_62 = 1 ; ; V_62 ++ ) {
if ( memcmp ( V_329 - V_62 , L_32 , 1 ) == 0 )
break;
if ( memcmp ( V_329 - V_62 , L_33 , 1 ) == 0 )
return false ;
}
V_330 = F_89 ( V_329 , L_32 ) ;
if ( V_330 == NULL ) {
V_330 = V_329 + strlen ( V_329 ) ;
}
memset ( V_328 , 0 , 100 ) ;
memcpy ( V_328 , V_329 , V_330 - V_329 ) ;
V_328 [ V_330 - V_329 ] = '\0' ;
V_329 = F_89 ( V_328 , L_31 ) ;
if ( V_329 == NULL )
return false ;
memset ( V_327 , 0 , 100 ) ;
strcpy ( V_327 , V_329 + 1 ) ;
V_331 = V_327 ;
while( * V_331 != 0x00 ) {
if( * V_331 == ' ' )
V_331 ++ ;
else
break;
}
memcpy ( V_325 , V_331 , strlen ( V_331 ) ) ;
return true ;
}
static unsigned char * F_91 ( struct V_1 * V_2 )
{
unsigned char * V_332 = V_333 ;
unsigned char * V_334 = NULL ;
struct V_335 * V_336 = NULL ;
T_11 V_337 = F_92 () ;
int V_338 = 0 ;
F_93 ( V_339 ) ;
V_336 = F_94 ( V_332 , V_340 , 0 ) ;
if ( F_95 ( V_336 ) ) {
F_34 ( L_34 ) ;
V_338 = - 1 ;
goto V_341;
}
if( ! ( V_336 -> V_342 ) || ! ( V_336 -> V_342 -> V_343 ) || ! ( V_336 -> V_342 -> V_344 ) ) {
F_34 ( L_35 , V_332 ) ;
V_338 = - 1 ;
goto V_345;
}
V_334 = F_54 ( 1024 , V_223 ) ;
if( V_334 == NULL ) {
F_34 ( L_36 ) ;
V_338 = - 1 ;
goto V_345;
}
if( V_336 -> V_342 -> V_343 ( V_336 , V_334 , 1024 , & V_336 -> V_346 ) < 0 ) {
F_34 ( L_37 ) ;
V_338 = - 1 ;
}
V_345:
if( F_96 ( V_336 , NULL ) )
F_34 ( L_38 ) ;
V_341:
F_93 ( V_337 ) ;
if( V_338 != 0 ) {
F_48 ( V_334 ) ;
V_334 = NULL ;
}
return V_334 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_338 = 0 ;
unsigned char V_347 [ 100 ] ;
unsigned char * V_334 = NULL ;
V_2 -> V_348 . V_349 = - 1 ;
V_2 -> V_348 . V_350 = - 1 ;
V_2 -> V_348 . V_271 = - 1 ;
V_334 = F_91 ( V_2 ) ;
if ( V_334 == NULL ) {
V_338 = - 1 ;
return V_338 ;
}
{
memset ( V_347 , 0 , sizeof( V_347 ) ) ;
if( F_90 ( L_39 , V_347 , V_334 ) == true ) {
if( memcmp ( V_347 , L_40 , 3 ) == 0 ) {
V_2 -> V_348 . V_349 = V_113 ;
}
else if( memcmp ( V_347 , L_41 , 5 ) == 0 ) {
V_2 -> V_348 . V_349 = V_110 ;
}
else if( memcmp ( V_347 , L_42 , 6 ) == 0 ) {
V_2 -> V_348 . V_349 = V_111 ;
}
else {
F_34 ( L_43 , V_347 ) ;
}
}
}
{
memset ( V_347 , 0 , sizeof( V_347 ) ) ;
if( F_90 ( L_44 , V_347 , V_334 ) == true ) {
V_2 -> V_348 . V_350 = ( int ) F_97 ( V_347 , NULL , 10 ) ;
}
memset ( V_347 , 0 , sizeof( V_347 ) ) ;
if( F_90 ( L_45 , V_347 , V_334 ) == true ) {
V_2 -> V_348 . V_271 = ( int ) F_97 ( V_347 , NULL , 10 ) ;
}
}
F_48 ( V_334 ) ;
return V_338 ;
}
static void F_65 ( struct V_194 * V_184 )
{
struct V_1 * V_2 = F_37 ( V_184 ) ;
struct V_58 * V_59 = & V_2 -> V_60 ;
struct V_351 * V_352 ;
T_10 V_353 [ 2 ] ;
int V_62 ;
T_2 V_354 [ 8 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_2 V_355 = 0 ;
int V_193 ;
F_7 ( & V_2 -> V_73 ) ;
V_193 = F_14 ( V_2 ,
V_81 ,
V_356 ,
V_83 ,
1 ,
& V_355
) ;
if ( V_193 == 0 ) V_2 -> V_357 = V_355 ;
F_6 ( V_71 , V_72 L_46 , V_2 -> V_357 ) ;
if ( V_184 -> V_186 & V_358 ) {
F_6 ( V_224 , V_196 L_47 , V_184 -> V_226 ) ;
V_2 -> V_357 |= ( V_359 | V_360 | V_361 ) ;
}
else if ( ( F_98 ( V_184 ) > V_2 -> V_362 ) ||
( V_184 -> V_186 & V_363 ) ) {
F_13 ( V_2 ,
V_364 ,
V_365 ,
V_83 ,
8 ,
V_354
) ;
V_2 -> V_357 |= ( V_359 | V_360 ) ;
}
else {
memset ( V_353 , 0 , sizeof( V_353 ) ) ;
F_99 (ha, dev) {
int V_366 = F_88 ( V_4 , V_352 -> V_367 ) >> 26 ;
V_353 [ V_366 >> 5 ] |= F_100 ( 1 << ( V_366 & 31 ) ) ;
}
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
F_101 ( V_2 , V_62 , * ( ( V_79 ) & V_353 [ 0 ] + V_62 ) ) ;
F_101 ( V_2 , V_62 + 4 , * ( ( V_79 ) & V_353 [ 1 ] + V_62 ) ) ;
}
V_2 -> V_357 &= ~ ( V_361 ) ;
V_2 -> V_357 |= ( V_359 | V_360 ) ;
}
if ( V_59 -> V_290 == V_291 ) {
V_2 -> V_357 |= ( V_359 | V_360 ) ;
V_2 -> V_357 &= ~ ( V_361 ) ;
}
F_16 ( V_2 , V_83 , V_356 , V_2 -> V_357 ) ;
F_6 ( V_71 , V_72 L_48 , V_2 -> V_357 ) ;
F_11 ( & V_2 -> V_73 ) ;
}
static struct V_311 * F_102 ( struct V_194 * V_184 )
{
struct V_1 * V_2 = F_37 ( V_184 ) ;
return & V_2 -> V_312 ;
}
static int F_103 ( struct V_194 * V_184 , struct V_368 * V_369 , int V_370 )
{
struct V_1 * V_2 = F_37 ( V_184 ) ;
struct V_371 * V_372 = (struct V_371 * ) V_369 ;
int V_193 = 0 ;
switch ( V_370 ) {
case V_373 :
if ( ! ( V_2 -> V_186 & V_187 ) )
V_193 = - V_374 ;
V_193 = F_104 ( V_2 , & V_372 -> V_375 . V_48 ) ;
break;
case V_376 :
return F_105 ( V_184 , ( void * ) V_369 -> V_377 ) ;
}
return V_193 ;
}
static int F_105 ( struct V_194 * V_184 , void * V_378 )
{
T_10 V_379 ;
if ( F_106 ( & V_379 , V_378 , sizeof( V_379 ) ) )
return - V_374 ;
switch ( V_379 ) {
case V_380 : {
struct V_381 V_382 = { V_380 } ;
strncpy ( V_382 . V_383 , V_384 , sizeof( V_382 . V_383 ) - 1 ) ;
strncpy ( V_382 . V_385 , V_198 , sizeof( V_382 . V_385 ) - 1 ) ;
if ( F_107 ( V_378 , & V_382 , sizeof( V_382 ) ) )
return - V_374 ;
return 0 ;
}
}
return - V_386 ;
}
