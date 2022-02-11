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
V_2 -> V_200 = V_201 ;
V_2 -> V_59 . V_202 = ( void * ) V_2 ;
V_193 -> V_203 = & V_204 ;
V_193 -> V_205 =
(struct V_206 * ) & V_207 ;
F_39 ( V_179 , V_2 ) ;
F_40 ( V_193 , & V_179 -> V_182 ) ;
memcpy ( V_2 -> V_182 -> V_208 , V_188 , V_4 ) ;
V_191 = F_41 ( V_193 ) ;
if ( V_191 ) {
F_34 (KERN_ERR DEVICE_NAME L_12 ) ;
goto V_209;
}
F_42 ( V_2 ) ;
return 0 ;
V_209:
F_43 ( V_193 ) ;
V_198:
F_44 ( V_190 ) ;
return V_191 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_210 * V_211 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_7 ; V_61 ++ ) {
V_211 = V_2 -> V_212 [ V_61 ] ;
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
struct V_214 * V_215 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_9 ; V_61 ++ ) {
V_215 = V_2 -> V_216 [ V_61 ] ;
if ( V_215 -> V_213 ) {
F_46 ( V_215 -> V_213 ) ;
F_47 ( V_215 -> V_213 ) ;
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
V_219 = F_51 ( V_2 -> V_199 ) ;
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
struct V_210 * V_211 ;
struct V_214 * V_215 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_7 ; V_61 ++ ) {
V_211 = F_54 ( sizeof( struct V_210 ) , V_222 ) ;
if ( V_211 == NULL ) {
F_6 ( V_223 , V_224 L_14 , V_2 -> V_182 -> V_225 ) ;
goto V_226;
}
V_2 -> V_212 [ V_61 ] = V_211 ;
V_211 -> V_2 = ( void * ) V_2 ;
V_211 -> V_213 = F_55 ( 0 , V_227 ) ;
if ( V_211 -> V_213 == NULL ) {
F_6 ( V_223 , V_224 L_15 ) ;
goto V_226;
}
V_211 -> V_228 = false ;
}
V_2 -> V_218 = F_56 ( ( sizeof( struct V_214 ) * V_2 -> V_9 ) ,
V_222 ) ;
if ( V_2 -> V_218 == NULL ) {
F_6 ( V_223 , V_224 L_16 , V_2 -> V_182 -> V_225 ) ;
goto V_226;
}
V_2 -> V_229 = NULL ;
V_2 -> V_230 = NULL ;
V_2 -> V_231 = NULL ;
V_2 -> V_232 = NULL ;
V_2 -> V_233 = 0 ;
V_215 = (struct V_214 * ) V_2 -> V_218 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_9 ; V_61 ++ ) {
V_2 -> V_216 [ V_61 ] = V_215 ;
V_215 -> V_2 = ( void * ) V_2 ;
V_215 -> V_213 = F_55 ( 0 , V_227 ) ;
if ( V_215 -> V_213 == NULL ) {
F_6 ( V_223 , V_224 L_17 ) ;
goto V_234;
}
V_215 -> V_217 = F_57 ( ( int ) V_2 -> V_235 ) ;
if ( V_215 -> V_217 == NULL ) {
F_6 ( V_223 , V_224 L_18 ) ;
goto V_234;
}
V_215 -> V_217 -> V_182 = V_2 -> V_182 ;
V_215 -> V_228 = false ;
F_58 ( V_2 -> V_229 , V_2 -> V_230 , V_215 ) ;
V_2 -> V_233 ++ ;
V_215 ++ ;
}
V_2 -> V_236 = F_55 ( 0 , V_227 ) ;
if ( V_2 -> V_236 == NULL ) {
F_6 ( V_223 , V_224 L_19 ) ;
goto V_234;
}
V_2 -> V_237 = F_55 ( 0 , V_227 ) ;
if ( V_2 -> V_237 == NULL ) {
F_6 ( V_223 , V_224 L_20 ) ;
F_47 ( V_2 -> V_236 ) ;
goto V_234;
}
V_2 -> V_220 . V_221 = F_54 ( V_238 , V_222 ) ;
if ( V_2 -> V_220 . V_221 == NULL ) {
F_6 ( V_223 , V_224 L_21 ) ;
F_47 ( V_2 -> V_236 ) ;
F_47 ( V_2 -> V_237 ) ;
goto V_234;
}
return true ;
V_234:
F_49 ( V_2 ) ;
V_226:
F_45 ( V_2 ) ;
return false ;
}
static bool F_59 ( struct V_1 * V_2 )
{
int V_239 ;
T_6 V_240 ;
for ( V_239 = 0 ; V_239 < V_241 ; V_239 ++ ) {
V_240 = & ( V_2 -> V_242 [ V_239 ] ) ;
if ( ! F_60 ( V_2 , V_240 ) ) {
F_6 ( V_223 , V_224 L_22 ,
V_2 -> V_182 -> V_225 ) ;
goto V_243;
}
}
V_2 -> V_244 = V_241 ;
V_2 -> V_245 = V_2 -> V_244 ;
return true ;
V_243:
F_61 ( V_2 ) ;
return false ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_6 V_240 ;
int V_239 ;
for ( V_239 = 0 ; V_239 < V_241 ; V_239 ++ ) {
V_240 = & ( V_2 -> V_242 [ V_239 ] ) ;
if ( V_240 -> V_217 )
F_50 ( V_240 -> V_217 ) ;
}
}
int F_60 ( struct V_1 * V_2 ,
T_6 V_240 )
{
V_240 -> V_217 = F_57 ( ( int ) V_2 -> V_235 ) ;
if ( V_240 -> V_217 == NULL )
return false ;
V_240 -> V_217 -> V_182 = V_2 -> V_182 ;
return true ;
}
static int F_31 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
V_2 -> V_246 = false ;
F_6 ( V_70 , V_71 L_23 ) ;
V_2 -> V_235 = V_247 ;
if ( F_53 ( V_2 ) == false ) {
F_6 ( V_70 , V_71 L_24 ) ;
return - V_197 ;
}
if ( F_59 ( V_2 ) == false ) {
F_6 ( V_70 , V_71 L_25 ) ;
goto V_234;
}
F_62 ( V_2 , V_248 ) ;
F_62 ( V_2 , V_249 ) ;
F_62 ( V_2 , V_250 ) ;
F_63 ( V_2 , V_251 ) ;
F_63 ( V_2 , V_252 ) ;
F_64 ( V_2 ) ;
if ( F_5 ( V_2 , V_73 ) == false ) {
F_6 ( V_70 , V_71 L_26 ) ;
goto V_253;
}
F_65 ( V_2 -> V_182 ) ;
F_66 ( V_2 , & V_2 -> V_254 ) ;
memcpy ( V_2 -> V_59 . V_255 ,
V_2 -> V_76 , V_4 ) ;
memcpy ( V_2 -> V_182 -> V_208 , V_2 -> V_76 , V_4 ) ;
V_2 -> V_256 = false ;
V_2 -> V_257 = false ;
V_2 -> V_258 = false ;
V_2 -> V_259 = false ;
V_2 -> V_260 = false ;
if ( V_2 -> V_45 ) {
F_2 ( V_2 ) ;
}
F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_261 , ( void * ) V_262 , ( unsigned long ) V_2 ) ;
F_68 ( & V_2 -> V_263 , ( void * ) V_264 , ( unsigned long ) V_2 ) ;
F_68 ( & V_2 -> V_265 , ( void * ) V_266 , ( unsigned long ) V_2 ) ;
F_69 ( & V_2 -> V_59 . V_267 ) ;
V_2 -> V_268 = 100 ;
V_2 -> V_269 = V_270 ;
V_2 -> V_271 = true ;
V_2 -> V_272 = false ;
V_2 -> V_273 = false ;
V_2 -> V_274 = false ;
V_2 -> V_275 = false ;
V_2 -> V_276 = false ;
V_2 -> V_277 = false ;
V_2 -> V_278 = false ;
V_2 -> V_279 = false ;
V_2 -> V_280 = 0 ;
V_264 ( V_2 ) ;
V_266 ( V_2 ) ;
if ( ( V_2 -> V_281 == true ) && ( V_2 -> V_282 == true ) ) {
F_7 ( & V_2 -> V_72 ) ;
F_70 ( V_2 ,
& ( V_2 -> V_254 ) ,
V_2 -> V_283 | ( 1 << 31 ) ,
V_2 -> V_284 ,
NULL ,
V_2 -> V_285 ,
V_286
) ;
F_11 ( & V_2 -> V_72 ) ;
V_2 -> V_269 = V_287 ;
}
if ( V_2 -> V_59 . V_288 == V_289 )
F_71 ( ( void * ) V_2 , V_290 , NULL ) ;
else
F_71 ( ( void * ) V_2 , V_291 , NULL ) ;
F_72 ( V_2 -> V_182 ) ;
V_2 -> V_184 |= V_185 ;
F_6 ( V_70 , V_71 L_27 ) ;
return 0 ;
V_253:
F_61 ( V_2 ) ;
V_234:
F_49 ( V_2 ) ;
F_45 ( V_2 ) ;
F_52 ( V_2 ) ;
F_46 ( V_2 -> V_236 ) ;
F_46 ( V_2 -> V_237 ) ;
F_47 ( V_2 -> V_236 ) ;
F_47 ( V_2 -> V_237 ) ;
F_6 ( V_70 , V_71 L_28 ) ;
return - V_197 ;
}
static int F_29 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_57 * V_58 = & V_2 -> V_59 ;
int V_292 ;
F_6 ( V_70 , V_71 L_29 ) ;
if ( V_2 == NULL )
return - V_183 ;
if ( V_2 -> V_293 ) {
F_71 ( ( void * ) V_2 , V_294 , NULL ) ;
F_73 ( 30 ) ;
}
memset ( V_58 -> V_295 , 0 , V_296 + V_297 + 1 ) ;
V_58 -> V_298 = false ;
V_2 -> V_281 = false ;
V_2 -> V_269 = V_270 ;
F_7 ( & V_2 -> V_72 ) ;
for ( V_292 = 0 ; V_292 < V_299 ; V_292 ++ )
F_74 ( V_2 , V_292 ) ;
F_11 ( & V_2 -> V_72 ) ;
if ( ( V_2 -> V_184 & V_300 ) == false ) {
F_75 ( V_2 ) ;
}
F_72 ( V_2 -> V_182 ) ;
F_63 ( V_2 , V_248 ) ;
F_62 ( V_2 , V_252 ) ;
F_62 ( V_2 , V_251 ) ;
V_2 -> V_272 = true ;
F_76 ( & V_2 -> V_301 ) ;
F_76 ( & V_58 -> V_267 ) ;
F_76 ( & V_2 -> V_302 ) ;
if ( V_2 -> V_45 ) {
F_76 ( & V_2 -> V_46 ) ;
F_76 ( & V_2 -> V_53 ) ;
F_76 ( & V_2 -> V_54 ) ;
}
F_77 ( & V_2 -> V_261 ) ;
F_77 ( & V_2 -> V_263 ) ;
F_77 ( & V_2 -> V_265 ) ;
V_2 -> V_258 = false ;
V_2 -> V_259 = false ;
V_2 -> V_260 = false ;
V_2 -> V_303 = false ;
V_2 -> V_293 = false ;
memset ( V_58 -> V_304 , 0 , 6 ) ;
V_58 -> V_305 = V_306 ;
V_2 -> V_184 &= ~ V_185 ;
F_45 ( V_2 ) ;
F_49 ( V_2 ) ;
F_52 ( V_2 ) ;
F_61 ( V_2 ) ;
F_46 ( V_2 -> V_236 ) ;
F_46 ( V_2 -> V_237 ) ;
F_47 ( V_2 -> V_236 ) ;
F_47 ( V_2 -> V_237 ) ;
F_78 ( V_2 , 0 ) ;
F_6 ( V_70 , V_71 L_30 ) ;
return 0 ;
}
static void F_79 ( struct V_178 * V_179 )
{
struct V_1 * V_181 = F_28 ( V_179 ) ;
if ( ! V_181 )
return;
F_39 ( V_179 , NULL ) ;
F_44 ( F_33 ( V_179 ) ) ;
V_181 -> V_184 |= V_300 ;
if ( V_181 -> V_182 ) {
F_80 ( V_181 -> V_182 ) ;
F_43 ( V_181 -> V_182 ) ;
}
}
static int V_201 ( struct V_307 * V_217 , struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
F_7 ( & V_2 -> V_72 ) ;
if ( F_81 ( V_2 -> V_256 ) )
F_82 ( V_217 ) ;
else
F_83 ( V_2 , V_217 ) ;
F_11 ( & V_2 -> V_72 ) ;
return V_308 ;
}
static int F_84 ( struct V_307 * V_217 , struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_309 * V_310 = & V_2 -> V_310 ;
F_7 ( & V_2 -> V_72 ) ;
F_72 ( V_182 ) ;
if ( ! V_2 -> V_293 ) {
F_82 ( V_217 ) ;
goto V_311;
}
if ( V_2 -> V_257 ) {
F_82 ( V_217 ) ;
V_310 -> V_312 ++ ;
goto V_311;
}
if ( F_85 ( V_2 , V_313 , V_217 ) ) {
if ( F_86 ( V_182 ) )
F_87 ( V_182 ) ;
}
V_311:
F_11 ( & V_2 -> V_72 ) ;
return V_308 ;
}
static inline T_7 F_88 ( int V_314 , unsigned char * V_47 )
{
int V_315 = - 1 ;
while( -- V_314 >= 0 ) {
unsigned char V_316 = * V_47 ++ ;
int V_317 ;
for ( V_317 = 0 ; V_317 < 8 ; V_317 ++ , V_316 >>= 1 ) {
V_315 = ( V_315 << 1 ) ^
( ( V_315 < 0 ) ^ ( V_316 & 1 ) ? V_318 : 0 ) ;
}
}
return V_315 ;
}
static unsigned char * F_89 ( const unsigned char * V_319 ,
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
static int F_90 ( unsigned char * string ,
unsigned char * V_323 ,
unsigned char * V_324 )
{
unsigned char V_325 [ 100 ] ;
unsigned char V_326 [ 100 ] ;
unsigned char * V_327 = NULL , * V_328 = NULL , * V_329 = NULL ;
int V_61 ;
memset ( V_325 , 0 , 100 ) ;
strcat ( V_325 , string ) ;
strcat ( V_325 , L_31 ) ;
V_324 += strlen ( V_325 ) ;
V_327 = F_89 ( V_324 , V_325 ) ;
if ( V_327 == NULL )
return false ;
for ( V_61 = 1 ; ; V_61 ++ ) {
if ( memcmp ( V_327 - V_61 , L_32 , 1 ) == 0 )
break;
if ( memcmp ( V_327 - V_61 , L_33 , 1 ) == 0 )
return false ;
}
V_328 = F_89 ( V_327 , L_32 ) ;
if ( V_328 == NULL ) {
V_328 = V_327 + strlen ( V_327 ) ;
}
memset ( V_326 , 0 , 100 ) ;
memcpy ( V_326 , V_327 , V_328 - V_327 ) ;
V_326 [ V_328 - V_327 ] = '\0' ;
V_327 = F_89 ( V_326 , L_31 ) ;
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
static unsigned char * F_91 ( struct V_1 * V_2 )
{
unsigned char * V_330 = F_54 ( 1024 , V_222 ) ;
struct V_331 * V_331 ;
if ( ! V_330 ) {
F_34 ( L_34 ) ;
return NULL ;
}
V_331 = F_92 ( V_332 , V_333 , 0 ) ;
if ( F_93 ( V_331 ) ) {
F_48 ( V_330 ) ;
F_34 ( L_35 ) ;
return NULL ;
}
if ( F_94 ( V_331 , 0 , V_330 , 1024 ) < 0 ) {
F_34 ( L_36 ) ;
F_48 ( V_330 ) ;
V_330 = NULL ;
}
F_95 ( V_331 ) ;
return V_330 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_334 = 0 ;
unsigned char V_335 [ 100 ] ;
unsigned char * V_330 = NULL ;
V_2 -> V_336 . V_337 = - 1 ;
V_2 -> V_336 . V_338 = - 1 ;
V_2 -> V_336 . V_269 = - 1 ;
V_330 = F_91 ( V_2 ) ;
if ( V_330 == NULL ) {
V_334 = - 1 ;
return V_334 ;
}
{
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
if( F_90 ( L_37 , V_335 , V_330 ) == true ) {
if( memcmp ( V_335 , L_38 , 3 ) == 0 ) {
V_2 -> V_336 . V_337 = V_111 ;
}
else if( memcmp ( V_335 , L_39 , 5 ) == 0 ) {
V_2 -> V_336 . V_337 = V_108 ;
}
else if( memcmp ( V_335 , L_40 , 6 ) == 0 ) {
V_2 -> V_336 . V_337 = V_109 ;
}
else {
F_34 ( L_41 , V_335 ) ;
}
}
}
{
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
if( F_90 ( L_42 , V_335 , V_330 ) == true ) {
V_2 -> V_336 . V_338 = ( int ) F_96 ( V_335 , NULL , 10 ) ;
}
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
if( F_90 ( L_43 , V_335 , V_330 ) == true ) {
V_2 -> V_336 . V_269 = ( int ) F_96 ( V_335 , NULL , 10 ) ;
}
}
F_48 ( V_330 ) ;
return V_334 ;
}
static void F_65 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_57 * V_58 = & V_2 -> V_59 ;
struct V_339 * V_340 ;
T_7 V_341 [ 2 ] ;
int V_61 ;
T_1 V_342 [ 8 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_343 = 0 ;
int V_191 ;
F_7 ( & V_2 -> V_72 ) ;
V_191 = F_14 ( V_2 ,
V_79 ,
V_344 ,
V_81 ,
1 ,
& V_343
) ;
if ( V_191 == 0 ) V_2 -> V_345 = V_343 ;
F_6 ( V_70 , V_71 L_44 , V_2 -> V_345 ) ;
if ( V_182 -> V_184 & V_346 ) {
F_6 ( V_223 , V_194 L_45 , V_182 -> V_225 ) ;
V_2 -> V_345 |= ( V_347 | V_348 | V_349 ) ;
}
else if ( ( F_97 ( V_182 ) > V_2 -> V_350 ) ||
( V_182 -> V_184 & V_351 ) ) {
F_13 ( V_2 ,
V_352 ,
V_353 ,
V_81 ,
8 ,
V_342
) ;
V_2 -> V_345 |= ( V_347 | V_348 ) ;
}
else {
memset ( V_341 , 0 , sizeof( V_341 ) ) ;
F_98 (ha, dev) {
int V_354 = F_88 ( V_4 , V_340 -> V_355 ) >> 26 ;
V_341 [ V_354 >> 5 ] |= F_99 ( 1 << ( V_354 & 31 ) ) ;
}
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
F_100 ( V_2 , V_61 , * ( ( T_1 * ) & V_341 [ 0 ] + V_61 ) ) ;
F_100 ( V_2 , V_61 + 4 , * ( ( T_1 * ) & V_341 [ 1 ] + V_61 ) ) ;
}
V_2 -> V_345 &= ~ ( V_349 ) ;
V_2 -> V_345 |= ( V_347 | V_348 ) ;
}
if ( V_58 -> V_288 == V_289 ) {
V_2 -> V_345 |= ( V_347 | V_348 ) ;
V_2 -> V_345 &= ~ ( V_349 ) ;
}
F_16 ( V_2 , V_81 , V_344 , V_2 -> V_345 ) ;
F_6 ( V_70 , V_71 L_46 , V_2 -> V_345 ) ;
F_11 ( & V_2 -> V_72 ) ;
}
static struct V_309 * F_101 ( struct V_192 * V_182 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
return & V_2 -> V_310 ;
}
static int F_102 ( struct V_192 * V_182 , struct V_356 * V_357 , int V_358 )
{
struct V_1 * V_2 = F_37 ( V_182 ) ;
struct V_359 * V_360 = (struct V_359 * ) V_357 ;
int V_191 = 0 ;
switch ( V_358 ) {
case V_361 :
if ( ! ( V_2 -> V_184 & V_185 ) )
V_191 = - V_362 ;
V_191 = F_103 ( V_2 , & V_360 -> V_363 . V_47 ) ;
break;
case V_364 :
return F_104 ( V_182 , ( void * ) V_357 -> V_365 ) ;
}
return V_191 ;
}
static int F_104 ( struct V_192 * V_182 , void * V_366 )
{
T_7 V_367 ;
if ( F_105 ( & V_367 , V_366 , sizeof( V_367 ) ) )
return - V_362 ;
switch ( V_367 ) {
case V_368 : {
struct V_369 V_370 = { V_368 } ;
strncpy ( V_370 . V_371 , V_372 , sizeof( V_370 . V_371 ) - 1 ) ;
strncpy ( V_370 . V_373 , V_196 , sizeof( V_370 . V_373 ) - 1 ) ;
if ( F_106 ( V_366 , & V_370 , sizeof( V_370 ) ) )
return - V_362 ;
return 0 ;
}
}
return - V_374 ;
}
