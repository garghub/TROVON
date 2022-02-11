static void
F_1 ( T_1 V_1 ) {
T_2 V_2 [ V_3 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_2 V_4 [ V_3 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_3 V_5 [ V_3 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0xF8 } ;
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
memcpy ( V_1 -> V_4 , V_4 , V_3 ) ;
memcpy ( V_1 -> V_5 , V_5 , V_3 ) ;
V_1 -> V_6 = V_7 ;
V_1 -> V_8 = V_9 ;
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
if ( V_1 -> V_30 < V_32 ) V_1 -> V_33 = TRUE ;
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = V_1 -> V_34 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_39 = TRUE ;
V_1 -> V_40 = 0 ;
V_1 -> V_41 = 0 ;
V_1 -> V_42 = 0 ;
V_1 -> V_43 = 0 ;
V_1 -> V_44 = FALSE ;
V_1 -> V_45 = FALSE ;
}
static void F_2 ( T_1 V_1 )
{
F_3 ( & V_1 -> V_46 ) ;
V_1 -> V_46 . V_47 = ( unsigned long ) V_1 ;
V_1 -> V_46 . V_48 = ( V_49 ) V_50 ;
V_1 -> V_46 . V_51 = F_4 ( V_52 ) ;
F_3 ( & V_1 -> V_53 ) ;
V_1 -> V_53 . V_47 = ( unsigned long ) V_1 ;
V_1 -> V_53 . V_48 = ( V_49 ) V_50 ;
V_1 -> V_53 . V_51 = F_4 ( V_52 ) ;
F_3 ( & V_1 -> V_54 ) ;
V_1 -> V_54 . V_47 = ( unsigned long ) V_1 ;
V_1 -> V_54 . V_48 = ( V_49 ) V_55 ;
V_1 -> V_54 . V_51 = F_4 ( V_52 ) ;
return;
}
static BOOL F_5 ( T_1 V_1 , T_4 V_56 )
{
T_3 V_2 [ V_3 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_3 V_4 [ V_3 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0x00 } ;
T_3 V_5 [ V_3 ] = { 0xAA , 0xAA , 0x03 , 0x00 , 0x00 , 0xF8 } ;
T_2 V_57 ;
unsigned int V_58 ;
T_5 V_59 ;
int V_60 = V_61 ;
T_6 V_62 ;
T_7 V_63 = & ( V_1 -> V_64 ) ;
T_2 V_65 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
T_2 V_68 = 0 ;
F_6 ( V_69 , V_70 L_1 , V_56 , V_1 -> V_36 ) ;
F_7 ( & V_1 -> V_71 ) ;
if ( V_56 == V_72 ) {
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
memcpy ( V_1 -> V_4 , V_4 , V_3 ) ;
memcpy ( V_1 -> V_5 ,
V_5 ,
V_3 ) ;
if ( ! F_8 ( V_1 ) ) {
if ( F_9 ( V_1 ) == TRUE ) {
if ( F_10 ( V_1 ) == FALSE ) {
F_6 ( V_69 , V_70 L_2 ) ;
F_11 ( & V_1 -> V_71 ) ;
return FALSE ;
}
} else {
F_6 ( V_69 , V_70 L_3 ) ;
F_11 ( & V_1 -> V_71 ) ;
return FALSE ;
}
}
if ( ! F_12 ( V_1 ) ) {
F_6 ( V_69 , V_70 L_4 ) ;
F_11 ( & V_1 -> V_71 ) ;
return FALSE ;
}
}
V_59 . V_73 = ( T_2 ) V_56 ;
V_59 . V_44 = ( T_2 ) V_1 -> V_44 ;
for ( V_58 = 0 ; V_58 < 6 ; V_58 ++ )
V_59 . V_74 [ V_58 ] = V_1 -> V_75 [ V_58 ] ;
V_59 . V_16 = V_1 -> V_16 ;
V_59 . V_18 = V_1 -> V_18 ;
V_60 = F_13 ( V_1 ,
V_76 ,
0 ,
0 ,
sizeof( T_5 ) ,
( V_77 ) & ( V_59 ) ) ;
if ( V_60 != V_61 ) {
F_6 ( V_69 , V_70 L_5 ) ;
F_11 ( & V_1 -> V_71 ) ;
return FALSE ;
}
if ( V_56 == V_72 ) {
V_60 = F_14 ( V_1 , V_78 , 0 , 0 , sizeof( T_6 ) , ( V_77 ) & ( V_62 ) ) ;
if ( V_60 != V_61 ) {
F_6 ( V_69 , V_70 L_6 ) ;
F_11 ( & V_1 -> V_71 ) ;
return FALSE ;
}
V_60 = F_14 ( V_1 ,
V_79 ,
V_80 ,
V_81 ,
1 ,
& V_1 -> V_82 ) ;
if ( V_60 != V_61 ) {
F_11 ( & V_1 -> V_71 ) ;
return FALSE ;
}
V_1 -> V_83 = TRUE ;
V_1 -> V_84 = FALSE ;
V_1 -> V_85 = FALSE ;
V_1 -> V_86 = FALSE ;
if ( V_1 -> V_33 ) {
V_1 -> V_87 = ( V_88 ) V_1 -> V_30 ;
} else {
if ( V_1 -> V_34 == V_89 )
V_1 -> V_87 = V_90 ;
else
V_1 -> V_87 = V_91 ;
}
F_15 ( V_1 ) ;
V_1 -> V_92 = V_93 ;
V_1 -> V_94 = V_95 ;
V_1 -> V_96 = 0 ;
V_1 -> V_97 = 0xFF ;
V_1 -> V_98 = V_1 -> V_99 [ V_100 ] ;
V_1 -> V_101 = V_1 -> V_99 [ V_102 ] ;
for ( V_58 = 0 ; V_58 < 14 ; V_58 ++ ) {
V_1 -> V_103 [ V_58 ] = V_1 -> V_99 [ V_58 + V_104 ] ;
if ( V_1 -> V_103 [ V_58 ] == 0 )
V_1 -> V_103 [ V_58 ] = V_1 -> V_98 ;
V_1 -> V_105 [ V_58 ] = V_1 -> V_99 [ V_58 + V_106 ] ;
if ( V_1 -> V_105 [ V_58 ] == 0 )
V_1 -> V_105 [ V_58 ] = V_1 -> V_101 ;
}
if( ( ( V_1 -> V_99 [ V_107 ] == V_108 ) ||
( V_1 -> V_99 [ V_107 ] == V_109 ) ) &&
( V_1 -> V_110 == V_111 ) ) {
for ( V_58 = 11 ; V_58 < 14 ; V_58 ++ ) {
V_1 -> V_103 [ V_58 ] = V_1 -> V_103 [ 10 ] ;
V_1 -> V_105 [ V_58 ] = V_1 -> V_105 [ 10 ] ;
}
}
V_1 -> V_112 = 0x34 ;
for ( V_58 = 0 ; V_58 < V_113 ; V_58 ++ ) {
V_1 -> V_114 [ V_58 ] = V_1 -> V_99 [ V_58 + V_115 ] ;
if ( V_1 -> V_114 [ V_58 ] == 0 )
V_1 -> V_114 [ V_58 ] = V_1 -> V_112 ;
}
V_57 = V_1 -> V_99 [ V_116 ] ;
if ( V_57 & V_117 )
V_1 -> V_118 = TRUE ;
else
V_1 -> V_118 = FALSE ;
V_57 &= ( V_119 | V_120 ) ;
if ( V_57 == 0 )
V_57 = ( V_119 | V_120 ) ;
if ( V_57 == ( V_119 | V_120 ) ) {
V_1 -> V_121 = 2 ;
V_1 -> V_122 = V_123 ;
V_1 -> V_124 = 1 ;
V_1 -> V_125 = 1 ;
if ( V_1 -> V_118 == TRUE )
V_1 -> V_126 = V_127 ;
else
V_1 -> V_126 = V_123 ;
if ( V_1 -> V_45 )
V_1 -> V_128 = TRUE ;
else
V_1 -> V_128 = FALSE ;
} else {
V_1 -> V_128 = FALSE ;
V_1 -> V_121 = 1 ;
V_1 -> V_124 = 0 ;
V_1 -> V_125 = 0 ;
if ( V_57 & V_119 ) {
V_1 -> V_122 = V_127 ;
if ( V_1 -> V_118 == TRUE )
V_1 -> V_126 = V_123 ;
else
V_1 -> V_126 = V_127 ;
} else {
V_1 -> V_122 = V_123 ;
if ( V_1 -> V_118 == TRUE )
V_1 -> V_126 = V_127 ;
else
V_1 -> V_126 = V_123 ;
}
}
V_1 -> V_129 = 100 * 255 ;
V_1 -> V_130 = 100 * 16 ;
V_1 -> V_131 = 1 ;
V_1 -> V_132 = 4 ;
V_1 -> V_133 = 0 ;
V_1 -> V_134 = 64 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_135 = V_136 ;
V_1 -> V_137 = V_138 ;
V_1 -> V_34 = V_139 ;
V_1 -> V_140 = 25 ;
V_1 -> V_141 = 1 ;
V_1 -> V_142 = V_143 ;
V_1 -> V_144 = V_62 . V_144 ;
if ( ( V_1 -> V_144 & V_145 ) != 0 ) {
V_1 -> V_96 = 0x80 ;
}
if ( V_1 -> V_144 == V_146 ) {
if( ( V_1 -> V_99 [ V_147 ] == 0x1 ) &&
( V_1 -> V_99 [ V_148 ] >= 0x4 ) ) {
V_66 = V_1 -> V_99 [ V_149 ] ;
V_67 = V_1 -> V_99 [ V_150 ] ;
V_68 = V_1 -> V_99 [ V_151 ] ;
if( ( V_66 || V_67 || V_68 ) ) {
F_16 ( V_1 , V_152 , 0xFF , 0x03 ) ;
F_16 ( V_1 , V_152 , 0xFB , V_66 ) ;
F_16 ( V_1 , V_152 , 0xFC , V_67 ) ;
F_16 ( V_1 , V_152 , 0xFD , V_68 ) ;
} else {
F_16 ( V_1 , V_152 , 0xFF , 0x0 ) ;
}
}
}
V_63 -> V_153 = V_154 ;
V_63 -> V_155 = V_1 -> V_10 ;
V_63 -> V_156 = V_1 -> V_10 ;
F_17 ( V_1 , V_63 -> V_155 ) ;
memcpy ( V_1 -> V_157 , & ( V_62 . V_158 [ 0 ] ) , 6 ) ;
memcpy ( V_1 -> V_75 ,
V_1 -> V_157 ,
V_3 ) ;
F_6 ( V_69 , V_70 L_7 ,
V_1 -> V_75 ) ;
}
if ( V_1 -> V_34 == V_159 ) {
F_18 ( V_1 , V_160 ) ;
V_1 -> V_161 = TRUE ;
} else {
F_18 ( V_1 , V_95 ) ;
V_1 -> V_161 = FALSE ;
}
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
if ( V_1 -> V_39 ) {
V_1 -> V_162 = V_1 -> V_163 [ 0 ] ;
V_1 -> V_164 = V_1 -> V_162 ;
F_21 ( V_1 , V_1 -> V_163 [ 0 ] ) ;
}
V_1 -> V_165 = V_1 -> V_99 [ V_166 ] ;
V_1 -> V_167 = FALSE ;
if ( ( V_1 -> V_165 & V_168 ) != 0 ) {
V_60 = F_14 ( V_1 ,
V_79 ,
V_169 ,
V_81 ,
1 ,
& V_65 ) ;
if ( V_60 != V_61 ) {
F_11 ( & V_1 -> V_71 ) ;
return FALSE ;
}
if ( ( V_65 & V_170 ) == 0 ) {
V_1 -> V_167 = TRUE ;
F_22 ( V_1 , V_169 , V_171 ) ;
} else {
F_23 ( V_1 , V_169 , V_171 ) ;
V_1 -> V_167 = FALSE ;
}
}
F_24 ( V_1 , V_81 , V_172 , V_173 , 0x38 ) ;
F_24 ( V_1 , V_81 , V_172 , V_174 , V_175 ) ;
F_22 ( V_1 , V_176 , 0x01 ) ;
if ( ( V_1 -> V_167 == TRUE ) || ( V_1 -> V_177 == TRUE ) ) {
F_25 ( V_1 ) ;
} else {
F_26 ( V_1 ) ;
}
F_11 ( & V_1 -> V_71 ) ;
F_6 ( V_69 , V_70 L_8 ) ;
return TRUE ;
}
static BOOL F_27 ( T_1 V_1 )
{
T_8 * V_178 ;
int V_58 = 0 ;
if ( V_1 -> V_179 == TRUE ) {
V_178 = ( T_8 * ) V_1 -> V_180 -> V_47 ;
V_178 -> type = V_181 ;
V_178 -> V_182 = 0 ;
V_178 -> V_183 = 0 ;
F_28 ( V_1 -> V_180 , sizeof( T_8 ) ) ;
V_1 -> V_180 -> V_184 = V_1 -> V_185 ;
F_29 ( V_1 -> V_180 ) ;
V_1 -> V_180 -> V_186 = V_187 ;
V_1 -> V_180 -> V_188 = F_30 ( V_189 ) ;
memset ( V_1 -> V_180 -> V_190 , 0 , sizeof( V_1 -> V_180 -> V_190 ) ) ;
F_31 ( V_1 -> V_180 ) ;
V_1 -> V_180 = F_32 ( ( int ) V_1 -> V_191 ) ;
while( V_1 -> V_179 == TRUE ) {
F_33 ( V_192 ) ;
F_34 ( V_52 / 20 ) ;
V_58 ++ ;
if( V_58 > 20 )
break;
}
}
return TRUE ;
}
static int F_35 ( struct V_193 * V_194 , T_9 V_195 )
{
T_1 V_196 = F_36 ( V_194 ) ;
if ( ! V_196 || ! V_196 -> V_184 )
return - V_197 ;
if ( V_196 -> V_198 & V_199 )
F_37 ( V_196 -> V_184 ) ;
F_38 ( F_39 ( V_194 ) ) ;
return 0 ;
}
static int F_40 ( struct V_193 * V_194 )
{
T_1 V_196 = F_36 ( V_194 ) ;
if ( ! V_196 || ! V_196 -> V_184 )
return - V_197 ;
F_41 ( F_39 ( V_194 ) ) ;
if ( ! ( V_196 -> V_198 & V_199 ) )
F_42 ( V_196 -> V_184 ) ;
return 0 ;
}
static int T_10
F_43 ( struct V_193 * V_194 , const struct V_200 * V_201 )
{
T_3 V_202 [ V_3 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ;
struct V_203 * V_204 = F_39 ( V_194 ) ;
int V_205 = 0 ;
struct V_206 * V_207 = NULL ;
T_1 V_1 = NULL ;
F_44 ( V_208 L_9 , V_209 , V_210 ) ;
F_44 ( V_208 L_10 ) ;
V_204 = F_41 ( V_204 ) ;
V_207 = F_45 ( sizeof( V_211 ) ) ;
if ( ! V_207 ) {
F_44 (KERN_ERR DEVICE_NAME L_11 ) ;
V_205 = - V_212 ;
goto V_213;
}
V_1 = F_46 ( V_207 ) ;
memset ( V_1 , 0 , sizeof( V_211 ) ) ;
V_1 -> V_184 = V_207 ;
V_1 -> V_214 = V_204 ;
F_1 ( V_1 ) ;
F_47 ( & V_1 -> V_71 ) ;
V_1 -> V_215 = V_216 ;
V_1 -> V_64 . V_217 = ( void * ) V_1 ;
V_207 -> V_218 = & V_219 ;
V_207 -> V_220 =
(struct V_221 * ) & V_222 ;
F_48 ( V_194 , V_1 ) ;
F_49 ( V_207 , & V_194 -> V_184 ) ;
memcpy ( V_1 -> V_184 -> V_223 , V_202 , V_3 ) ;
V_205 = F_50 ( V_207 ) ;
if ( V_205 ) {
F_44 (KERN_ERR DEVICE_NAME L_12 ) ;
goto V_224;
}
F_51 ( V_1 ) ;
{
union V_225 V_226 ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 . V_47 . V_198 = V_227 ;
V_226 . V_47 . V_228 = V_229 ;
F_52 ( V_1 -> V_184 ,
V_230 ,
& V_226 ,
V_1 -> V_184 -> V_231 ) ;
}
return 0 ;
V_224:
F_53 ( V_207 ) ;
V_213:
F_38 ( V_204 ) ;
return V_205 ;
}
static void F_54 ( T_1 V_1 )
{
T_11 V_232 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_6 ; V_58 ++ ) {
V_232 = V_1 -> V_233 [ V_58 ] ;
if ( V_232 -> V_234 ) {
F_55 ( V_232 -> V_234 ) ;
F_56 ( V_232 -> V_234 ) ;
}
F_57 ( V_232 ) ;
}
return;
}
static void F_58 ( T_1 V_1 )
{
T_12 V_235 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_8 ; V_58 ++ ) {
V_235 = V_1 -> V_236 [ V_58 ] ;
if ( V_235 -> V_234 ) {
F_55 ( V_235 -> V_234 ) ;
F_56 ( V_235 -> V_234 ) ;
}
if ( V_235 -> V_180 )
F_59 ( V_235 -> V_180 ) ;
}
F_57 ( V_1 -> V_237 ) ;
return;
}
static void F_51 ( T_1 V_1 )
{
int V_238 ;
V_238 = F_60 ( V_1 -> V_214 ) ;
if ( V_238 )
F_44 ( L_13 , V_238 ) ;
return ;
}
static void F_61 ( T_1 V_1 )
{
F_57 ( V_1 -> V_239 . V_240 ) ;
return;
}
static BOOL F_62 ( T_1 V_1 ) {
T_11 V_232 ;
T_12 V_235 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_6 ; V_58 ++ ) {
V_232 = F_63 ( sizeof( V_241 ) , V_242 ) ;
if ( V_232 == NULL ) {
F_6 ( V_243 , V_244 L_14 , V_1 -> V_184 -> V_231 ) ;
goto V_245;
}
V_1 -> V_233 [ V_58 ] = V_232 ;
V_232 -> V_1 = ( void * ) V_1 ;
V_232 -> V_234 = F_64 ( 0 , V_246 ) ;
if ( V_232 -> V_234 == NULL ) {
F_6 ( V_243 , V_244 L_15 ) ;
goto V_245;
}
V_232 -> V_247 = FALSE ;
}
V_1 -> V_237 = F_65 ( ( sizeof( V_248 ) * V_1 -> V_8 ) , V_242 ) ;
if ( V_1 -> V_237 == NULL ) {
F_6 ( V_243 , V_244 L_16 , V_1 -> V_184 -> V_231 ) ;
goto V_245;
}
V_1 -> V_249 = NULL ;
V_1 -> V_250 = NULL ;
V_1 -> V_251 = NULL ;
V_1 -> V_252 = NULL ;
V_1 -> V_253 = 0 ;
V_235 = ( T_12 ) V_1 -> V_237 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_8 ; V_58 ++ ) {
V_1 -> V_236 [ V_58 ] = V_235 ;
V_235 -> V_1 = ( void * ) V_1 ;
V_235 -> V_234 = F_64 ( 0 , V_246 ) ;
if ( V_235 -> V_234 == NULL ) {
F_6 ( V_243 , V_244 L_17 ) ;
goto V_254;
}
V_235 -> V_180 = F_32 ( ( int ) V_1 -> V_191 ) ;
if ( V_235 -> V_180 == NULL ) {
F_6 ( V_243 , V_244 L_18 ) ;
goto V_254;
}
V_235 -> V_180 -> V_184 = V_1 -> V_184 ;
V_235 -> V_247 = FALSE ;
F_66 ( V_1 -> V_249 , V_1 -> V_250 , V_235 ) ;
V_1 -> V_253 ++ ;
V_235 ++ ;
}
V_1 -> V_255 = F_64 ( 0 , V_246 ) ;
if ( V_1 -> V_255 == NULL ) {
F_6 ( V_243 , V_244 L_19 ) ;
goto V_254;
}
V_1 -> V_256 = F_64 ( 0 , V_246 ) ;
if ( V_1 -> V_256 == NULL ) {
F_6 ( V_243 , V_244 L_20 ) ;
F_56 ( V_1 -> V_255 ) ;
goto V_254;
}
V_1 -> V_239 . V_240 = F_63 ( V_257 , V_242 ) ;
if ( V_1 -> V_239 . V_240 == NULL ) {
F_6 ( V_243 , V_244 L_21 ) ;
F_56 ( V_1 -> V_255 ) ;
F_56 ( V_1 -> V_256 ) ;
goto V_254;
}
return TRUE ;
V_254:
F_58 ( V_1 ) ;
V_245:
F_54 ( V_1 ) ;
return FALSE ;
}
static BOOL F_67 ( T_1 V_1 ) {
int V_258 ;
T_13 V_259 ;
for ( V_258 = 0 ; V_258 < V_260 ; V_258 ++ ) {
V_259 = & ( V_1 -> V_261 [ V_258 ] ) ;
if ( ! F_68 ( V_1 , V_259 ) ) {
F_6 ( V_243 , V_244 L_22 ,
V_1 -> V_184 -> V_231 ) ;
goto V_262;
}
}
V_1 -> V_263 = V_260 ;
V_1 -> V_264 = V_1 -> V_263 ;
return TRUE ;
V_262:
F_69 ( V_1 ) ;
return FALSE ;
}
static void F_69 ( T_1 V_1 ) {
T_13 V_259 ;
int V_258 ;
for ( V_258 = 0 ; V_258 < V_260 ; V_258 ++ ) {
V_259 = & ( V_1 -> V_261 [ V_258 ] ) ;
if ( V_259 -> V_180 )
F_59 ( V_259 -> V_180 ) ;
}
}
BOOL F_68 ( T_1 V_1 , T_13 V_259 ) {
V_259 -> V_180 = F_32 ( ( int ) V_1 -> V_191 ) ;
if ( V_259 -> V_180 == NULL )
return FALSE ;
ASSERT ( V_259 -> V_180 ) ;
V_259 -> V_180 -> V_184 = V_1 -> V_184 ;
return TRUE ;
}
static int F_42 ( struct V_206 * V_184 ) {
T_1 V_1 = ( T_1 ) F_46 ( V_184 ) ;
extern T_14 V_265 ;
memset ( V_265 . V_266 , 0 , sizeof( V_265 . V_266 ) ) ;
V_265 . V_267 = 0 ;
V_265 . V_268 = 0 ;
V_265 . V_269 = 0 ;
V_265 . V_270 = FALSE ;
V_1 -> V_271 = FALSE ;
F_6 ( V_69 , V_70 L_23 ) ;
V_1 -> V_191 = V_272 ;
if ( F_62 ( V_1 ) == FALSE ) {
F_6 ( V_69 , V_70 L_24 ) ;
return - V_212 ;
}
if ( F_67 ( V_1 ) == FALSE ) {
F_6 ( V_69 , V_70 L_25 ) ;
goto V_254;
}
F_70 ( V_1 , V_273 ) ;
F_70 ( V_1 , V_274 ) ;
F_70 ( V_1 , V_275 ) ;
F_71 ( V_1 , V_276 ) ;
F_71 ( V_1 , V_277 ) ;
F_72 ( V_1 ) ;
if ( F_5 ( V_1 , V_72 ) == FALSE ) {
F_6 ( V_69 , V_70 L_26 ) ;
goto V_278;
}
F_73 ( V_1 -> V_184 ) ;
F_74 ( V_1 , & V_1 -> V_279 ) ;
memcpy ( V_1 -> V_64 . V_280 , V_1 -> V_75 , V_3 ) ;
memcpy ( V_1 -> V_184 -> V_223 , V_1 -> V_75 , V_3 ) ;
V_1 -> V_281 = FALSE ;
V_1 -> V_282 = FALSE ;
V_1 -> V_283 = FALSE ;
V_1 -> V_284 = FALSE ;
V_1 -> V_285 = FALSE ;
if ( V_1 -> V_45 ) {
F_2 ( V_1 ) ;
}
F_75 ( V_1 ) ;
F_76 ( & V_1 -> V_286 , ( void * ) V_287 , ( unsigned long ) V_1 ) ;
F_76 ( & V_1 -> V_288 , ( void * ) V_289 , ( unsigned long ) V_1 ) ;
F_76 ( & V_1 -> V_290 , ( void * ) V_291 , ( unsigned long ) V_1 ) ;
F_77 ( & ( V_1 -> V_64 . V_292 ) ) ;
V_1 -> V_293 = 100 ;
V_1 -> V_294 = V_295 ;
V_1 -> V_296 = TRUE ;
V_1 -> V_297 = FALSE ;
V_1 -> V_298 = FALSE ;
V_1 -> V_179 = FALSE ;
#ifdef F_78
V_1 -> V_299 = FALSE ;
V_1 -> V_300 = FALSE ;
V_1 -> V_301 = FALSE ;
V_1 -> V_302 = FALSE ;
V_1 -> V_303 = FALSE ;
#endif
V_1 -> V_304 = 0 ;
V_289 ( V_1 ) ;
V_291 ( V_1 ) ;
if ( ( V_1 -> V_305 == TRUE ) && ( V_1 -> V_306 == TRUE ) ) {
F_7 ( & V_1 -> V_71 ) ;
F_79 ( V_1 ,
& ( V_1 -> V_279 ) ,
V_1 -> V_307 | ( 1 << 31 ) ,
V_1 -> V_308 ,
NULL ,
V_1 -> V_309 ,
V_310
) ;
F_11 ( & V_1 -> V_71 ) ;
V_1 -> V_294 = V_311 ;
}
if ( V_1 -> V_64 . V_312 == V_313 ) {
F_80 ( ( void * ) V_1 , V_314 , NULL ) ;
}
else {
F_80 ( ( void * ) V_1 , V_315 , NULL ) ;
}
F_81 ( V_1 -> V_184 ) ;
V_1 -> V_198 |= V_199 ;
{
union V_225 V_226 ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 . V_47 . V_198 = V_316 ;
F_52 ( V_1 -> V_184 , V_230 , & V_226 , NULL ) ;
}
F_6 ( V_69 , V_70 L_27 ) ;
return 0 ;
V_278:
F_69 ( V_1 ) ;
V_254:
F_58 ( V_1 ) ;
F_54 ( V_1 ) ;
F_61 ( V_1 ) ;
F_55 ( V_1 -> V_255 ) ;
F_55 ( V_1 -> V_256 ) ;
F_56 ( V_1 -> V_255 ) ;
F_56 ( V_1 -> V_256 ) ;
F_6 ( V_69 , V_70 L_28 ) ;
return - V_212 ;
}
static int F_37 ( struct V_206 * V_184 ) {
T_1 V_1 = ( T_1 ) F_46 ( V_184 ) ;
T_7 V_63 = & ( V_1 -> V_64 ) ;
int V_317 ;
F_6 ( V_69 , V_70 L_29 ) ;
if ( V_1 == NULL )
return - V_197 ;
{
union V_225 V_226 ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 . V_47 . V_198 = V_318 ;
F_52 ( V_1 -> V_184 , V_230 , & V_226 , NULL ) ;
}
if ( V_1 -> V_319 ) {
F_80 ( ( void * ) V_1 , V_320 , NULL ) ;
F_82 ( 30 ) ;
}
F_27 ( V_1 ) ;
memset ( V_63 -> V_321 , 0 , V_322 + V_323 + 1 ) ;
V_63 -> V_324 = FALSE ;
V_1 -> V_305 = FALSE ;
V_1 -> V_294 = V_295 ;
F_7 ( & V_1 -> V_71 ) ;
for ( V_317 = 0 ; V_317 < V_325 ; V_317 ++ )
F_83 ( V_1 , V_317 ) ;
F_11 ( & V_1 -> V_71 ) ;
if ( ( V_1 -> V_198 & V_326 ) == FALSE ) {
F_84 ( V_1 ) ;
}
F_81 ( V_1 -> V_184 ) ;
F_71 ( V_1 , V_273 ) ;
F_70 ( V_1 , V_277 ) ;
F_70 ( V_1 , V_276 ) ;
V_1 -> V_297 = TRUE ;
F_85 ( & V_1 -> V_327 ) ;
F_85 ( & V_63 -> V_292 ) ;
F_85 ( & V_1 -> V_328 ) ;
if ( V_1 -> V_45 ) {
F_85 ( & V_1 -> V_46 ) ;
F_85 ( & V_1 -> V_53 ) ;
F_85 ( & V_1 -> V_54 ) ;
}
F_86 ( & V_1 -> V_286 ) ;
F_86 ( & V_1 -> V_288 ) ;
F_86 ( & V_1 -> V_290 ) ;
V_1 -> V_283 = FALSE ;
V_1 -> V_284 = FALSE ;
V_1 -> V_285 = FALSE ;
V_1 -> V_329 = FALSE ;
V_1 -> V_319 = FALSE ;
memset ( V_63 -> V_330 , 0 , 6 ) ;
V_63 -> V_331 = V_332 ;
F_54 ( V_1 ) ;
F_58 ( V_1 ) ;
F_61 ( V_1 ) ;
F_69 ( V_1 ) ;
F_55 ( V_1 -> V_255 ) ;
F_55 ( V_1 -> V_256 ) ;
F_56 ( V_1 -> V_255 ) ;
F_56 ( V_1 -> V_256 ) ;
F_87 ( V_1 , 0 ) ;
V_1 -> V_198 &= ( ~ V_199 ) ;
F_6 ( V_69 , V_70 L_30 ) ;
return 0 ;
}
static void T_15 F_88 ( struct V_193 * V_194 )
{
T_1 V_196 = F_36 ( V_194 ) ;
if ( ! V_196 )
return;
{
union V_225 V_333 ;
memset ( & V_333 , 0 , sizeof( V_333 ) ) ;
V_333 . V_47 . V_198 = V_334 ;
F_52 ( V_196 -> V_184 , V_230 , & V_333 , NULL ) ;
}
F_27 ( V_196 ) ;
F_89 ( V_196 -> V_335 ) ;
F_48 ( V_194 , NULL ) ;
F_38 ( F_39 ( V_194 ) ) ;
V_196 -> V_198 |= V_326 ;
if ( V_196 -> V_184 ) {
F_90 ( V_196 -> V_184 ) ;
F_91 ( V_196 , 0 ) ;
F_53 ( V_196 -> V_184 ) ;
}
}
static int V_216 ( struct V_336 * V_180 , struct V_206 * V_184 )
{
T_1 V_1 = F_46 ( V_184 ) ;
F_7 ( & V_1 -> V_71 ) ;
if ( F_92 ( V_1 -> V_281 ) )
F_93 ( V_180 ) ;
else
F_94 ( V_1 , V_180 ) ;
F_11 ( & V_1 -> V_71 ) ;
return V_337 ;
}
static int F_95 ( struct V_336 * V_180 , struct V_206 * V_184 )
{
T_1 V_1 = F_46 ( V_184 ) ;
struct V_338 * V_339 = & V_1 -> V_339 ;
F_7 ( & V_1 -> V_71 ) ;
F_81 ( V_184 ) ;
if ( ! V_1 -> V_319 ) {
F_93 ( V_180 ) ;
goto V_340;
}
if ( V_1 -> V_282 ) {
F_93 ( V_180 ) ;
V_339 -> V_341 ++ ;
goto V_340;
}
if ( F_96 ( V_1 , V_342 , V_180 ) ) {
if ( F_97 ( V_184 ) )
F_98 ( V_184 ) ;
}
V_340:
F_11 ( & V_1 -> V_71 ) ;
return V_337 ;
}
static inline T_16 F_99 ( int V_228 , unsigned char * V_47 )
{
int V_343 = - 1 ;
while( -- V_228 >= 0 ) {
unsigned char V_344 = * V_47 ++ ;
int V_345 ;
for ( V_345 = 0 ; V_345 < 8 ; V_345 ++ , V_344 >>= 1 ) {
V_343 = ( V_343 << 1 ) ^
( ( V_343 < 0 ) ^ ( V_344 & 1 ) ? V_346 : 0 ) ;
}
}
return V_343 ;
}
static unsigned char * F_100 ( const unsigned char * V_347 ,
const unsigned char * V_348 ) {
int V_349 = strlen ( V_347 ) ;
int V_350 = strlen ( V_348 ) ;
while ( V_349 >= V_350 ) {
V_349 -- ;
if( memcmp ( V_347 , V_348 , V_350 ) == 0 )
return ( unsigned char * ) V_347 ;
V_347 ++ ;
}
return NULL ;
}
static int F_101 ( unsigned char * string ,
unsigned char * V_351 ,
unsigned char * V_352 )
{
unsigned char V_353 [ 100 ] ;
unsigned char V_354 [ 100 ] ;
unsigned char * V_355 = NULL , * V_356 = NULL , * V_357 = NULL ;
int V_58 ;
memset ( V_353 , 0 , 100 ) ;
strcat ( V_353 , string ) ;
strcat ( V_353 , L_31 ) ;
V_352 += strlen ( V_353 ) ;
V_355 = F_100 ( V_352 , V_353 ) ;
if ( V_355 == NULL )
return FALSE ;
for ( V_58 = 1 ; ; V_58 ++ ) {
if ( memcmp ( V_355 - V_58 , L_32 , 1 ) == 0 )
break;
if ( memcmp ( V_355 - V_58 , L_33 , 1 ) == 0 )
return FALSE ;
}
V_356 = F_100 ( V_355 , L_32 ) ;
if ( V_356 == NULL ) {
V_356 = V_355 + strlen ( V_355 ) ;
}
memset ( V_354 , 0 , 100 ) ;
memcpy ( V_354 , V_355 , V_356 - V_355 ) ;
V_354 [ V_356 - V_355 ] = '\0' ;
V_355 = F_100 ( V_354 , L_31 ) ;
if ( V_355 == NULL )
return FALSE ;
memset ( V_353 , 0 , 100 ) ;
strcpy ( V_353 , V_355 + 1 ) ;
V_357 = V_353 ;
while( * V_357 != 0x00 ) {
if( * V_357 == ' ' )
V_357 ++ ;
else
break;
}
memcpy ( V_351 , V_357 , strlen ( V_357 ) ) ;
return TRUE ;
}
static unsigned char * F_102 ( T_1 V_1 )
{
unsigned char * V_358 = V_359 ;
unsigned char * V_360 = NULL ;
struct V_361 * V_362 = NULL ;
T_17 V_363 = F_103 () ;
int V_364 = 0 ;
F_104 ( V_365 ) ;
V_362 = F_105 ( V_358 , V_366 , 0 ) ;
if ( F_106 ( V_362 ) ) {
F_44 ( L_34 ) ;
V_364 = - 1 ;
goto V_367;
}
if( ! ( V_362 -> V_368 ) || ! ( V_362 -> V_368 -> V_369 ) || ! ( V_362 -> V_368 -> V_370 ) ) {
F_44 ( L_35 , V_358 ) ;
V_364 = - 1 ;
goto V_371;
}
V_360 = F_63 ( 1024 , V_242 ) ;
if( V_360 == NULL ) {
F_44 ( L_36 ) ;
V_364 = - 1 ;
goto V_371;
}
if( V_362 -> V_368 -> V_369 ( V_362 , V_360 , 1024 , & V_362 -> V_372 ) < 0 ) {
F_44 ( L_37 ) ;
V_364 = - 1 ;
}
V_371:
if( F_107 ( V_362 , NULL ) )
F_44 ( L_38 ) ;
V_367:
F_104 ( V_363 ) ;
if( V_364 != 0 ) {
F_57 ( V_360 ) ;
V_360 = NULL ;
}
return V_360 ;
}
static int F_72 ( T_1 V_1 ) {
int V_364 = 0 ;
unsigned char V_373 [ 100 ] ;
unsigned char * V_360 = NULL ;
V_1 -> V_374 . V_375 = - 1 ;
V_1 -> V_374 . V_376 = - 1 ;
V_1 -> V_374 . V_294 = - 1 ;
V_360 = F_102 ( V_1 ) ;
if ( V_360 == NULL ) {
V_364 = - 1 ;
return V_364 ;
}
{
memset ( V_373 , 0 , sizeof( V_373 ) ) ;
if( F_101 ( L_39 , V_373 , V_360 ) == TRUE ) {
if( memcmp ( V_373 , L_40 , 3 ) == 0 ) {
V_1 -> V_374 . V_375 = V_111 ;
}
else if( memcmp ( V_373 , L_41 , 5 ) == 0 ) {
V_1 -> V_374 . V_375 = V_108 ;
}
else if( memcmp ( V_373 , L_42 , 6 ) == 0 ) {
V_1 -> V_374 . V_375 = V_109 ;
}
else {
F_44 ( L_43 , V_373 ) ;
}
}
}
{
memset ( V_373 , 0 , sizeof( V_373 ) ) ;
if( F_101 ( L_44 , V_373 , V_360 ) == TRUE ) {
V_1 -> V_374 . V_376 = ( int ) F_108 ( V_373 , NULL , 10 ) ;
}
memset ( V_373 , 0 , sizeof( V_373 ) ) ;
if( F_101 ( L_45 , V_373 , V_360 ) == TRUE ) {
V_1 -> V_374 . V_294 = ( int ) F_108 ( V_373 , NULL , 10 ) ;
}
}
F_57 ( V_360 ) ;
return V_364 ;
}
static void F_73 ( struct V_206 * V_184 ) {
T_1 V_1 = ( T_1 ) F_46 ( V_184 ) ;
T_7 V_63 = & ( V_1 -> V_64 ) ;
T_16 V_377 [ 2 ] ;
int V_58 ;
struct V_378 * V_379 ;
T_2 V_380 [ 8 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_2 V_381 = 0 ;
int V_205 ;
F_7 ( & V_1 -> V_71 ) ;
V_205 = F_14 ( V_1 ,
V_79 ,
V_382 ,
V_81 ,
1 ,
& V_381
) ;
if ( V_205 == 0 ) V_1 -> V_383 = V_381 ;
F_6 ( V_69 , V_70 L_46 , V_1 -> V_383 ) ;
if ( V_184 -> V_198 & V_384 ) {
F_6 ( V_243 , V_208 L_47 , V_184 -> V_231 ) ;
V_1 -> V_383 |= ( V_385 | V_386 | V_387 ) ;
}
else if ( ( F_109 ( V_184 ) > V_1 -> V_388 ) ||
( V_184 -> V_198 & V_389 ) ) {
F_13 ( V_1 ,
V_390 ,
V_391 ,
V_81 ,
8 ,
V_380
) ;
V_1 -> V_383 |= ( V_385 | V_386 ) ;
}
else {
memset ( V_377 , 0 , sizeof( V_377 ) ) ;
F_110 (ha, dev) {
int V_392 = F_99 ( V_3 , V_379 -> V_393 ) >> 26 ;
V_377 [ V_392 >> 5 ] |= F_111 ( 1 << ( V_392 & 31 ) ) ;
}
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ ) {
F_112 ( V_1 , V_58 , * ( ( V_77 ) & V_377 [ 0 ] + V_58 ) ) ;
F_112 ( V_1 , V_58 + 4 , * ( ( V_77 ) & V_377 [ 1 ] + V_58 ) ) ;
}
V_1 -> V_383 &= ~ ( V_387 ) ;
V_1 -> V_383 |= ( V_385 | V_386 ) ;
}
if ( V_63 -> V_312 == V_313 ) {
V_1 -> V_383 |= ( V_385 | V_386 ) ;
V_1 -> V_383 &= ~ ( V_387 ) ;
}
F_16 ( V_1 , V_81 , V_382 , V_1 -> V_383 ) ;
F_6 ( V_69 , V_70 L_48 , V_1 -> V_383 ) ;
F_11 ( & V_1 -> V_71 ) ;
}
static struct V_338 * F_113 ( struct V_206 * V_184 ) {
T_1 V_1 = ( T_1 ) F_46 ( V_184 ) ;
return & V_1 -> V_339 ;
}
static int F_114 ( struct V_206 * V_184 , struct V_394 * V_395 , int V_396 ) {
T_1 V_1 = ( T_1 ) F_46 ( V_184 ) ;
T_7 V_63 = & ( V_1 -> V_64 ) ;
T_18 V_397 ;
struct V_398 * V_399 = (struct V_398 * ) V_395 ;
int V_205 = 0 ;
if ( V_63 == NULL ) {
V_205 = - V_400 ;
return V_205 ;
}
switch( V_396 ) {
case V_401 :
V_205 = F_115 ( V_184 , NULL , ( char * ) & ( V_399 -> V_402 . V_231 ) , NULL ) ;
break;
case V_403 :
case V_404 :
V_205 = - V_405 ;
break;
case V_406 :
V_205 = F_116 ( V_184 , NULL , & ( V_399 -> V_402 . V_407 ) , NULL ) ;
break;
case V_408 :
V_205 = F_117 ( V_184 , NULL , & ( V_399 -> V_402 . V_407 ) , NULL ) ;
break;
case V_409 :
{
char V_410 [ V_411 + 1 ] ;
if ( V_399 -> V_402 . V_410 . V_228 > V_411 ) {
V_205 = - V_412 ;
break;
}
if ( F_118 ( V_410 , V_399 -> V_402 . V_410 . V_413 ,
V_399 -> V_402 . V_410 . V_228 ) ) {
V_205 = - V_400 ;
break;
}
V_205 = F_119 ( V_184 , NULL ,
& ( V_399 -> V_402 . V_410 ) , V_410 ) ;
}
break;
case V_414 :
{
char V_410 [ V_411 + 1 ] ;
if ( V_399 -> V_402 . V_410 . V_413 ) {
F_120 ( V_184 , NULL ,
& ( V_399 -> V_402 . V_410 ) , V_410 ) ;
if ( F_121 ( V_399 -> V_402 . V_410 . V_413 ,
V_410 ,
V_399 -> V_402 . V_410 . V_228 ) )
V_205 = - V_400 ;
}
}
break;
case V_415 :
V_205 = F_122 ( V_184 , NULL , & ( V_399 -> V_402 . V_416 ) , NULL ) ;
break;
case V_417 :
V_205 = F_123 ( V_184 , NULL , & ( V_399 -> V_402 . V_416 ) , NULL ) ;
break;
case V_418 :
F_6 ( V_69 , V_70 L_49 ) ;
V_205 = - V_405 ;
break;
case V_419 :
F_6 ( V_69 , V_70 L_50 ) ;
V_205 = - V_405 ;
break;
case V_420 :
V_205 = F_124 ( V_184 , NULL , & ( V_399 -> V_402 . V_421 ) , NULL ) ;
break;
case V_422 :
F_125 ( V_184 , NULL , & ( V_399 -> V_402 . V_421 ) , NULL ) ;
break;
case V_423 :
V_205 = F_126 ( V_184 , & ( V_399 -> V_402 . V_424 ) ) ;
break;
case V_425 :
V_205 = F_127 ( V_184 , NULL , & ( V_399 -> V_402 . V_424 ) , NULL ) ;
break;
case V_426 :
V_205 = F_128 ( V_184 , NULL , & ( V_399 -> V_402 . V_427 ) , NULL ) ;
break;
case V_428 :
V_205 = F_129 ( V_184 , NULL , & ( V_399 -> V_402 . V_427 ) , NULL ) ;
break;
case V_429 :
V_205 = F_130 ( V_184 , NULL , & ( V_399 -> V_402 . V_430 ) , NULL ) ;
break;
case V_431 :
F_131 ( V_184 , NULL , & ( V_399 -> V_402 . V_430 ) , NULL ) ;
break;
case V_432 :
{
char V_309 [ V_433 ] ;
if ( V_399 -> V_402 . V_434 . V_413 ) {
if ( V_399 -> V_402 . V_434 . V_228 > V_433 ) {
V_205 = - V_412 ;
break;
}
memset ( V_309 , 0 , V_433 ) ;
if ( F_118 ( V_309 ,
V_399 -> V_402 . V_434 . V_413 ,
V_399 -> V_402 . V_434 . V_228 ) ) {
V_205 = - V_400 ;
break;
}
} else if ( V_399 -> V_402 . V_434 . V_228 != 0 ) {
V_205 = - V_435 ;
break;
}
V_205 = F_132 ( V_184 , NULL , & ( V_399 -> V_402 . V_434 ) , V_309 ) ;
}
break;
case V_436 :
if ( ! F_133 ( V_437 ) ) {
V_205 = - V_438 ;
break;
}
{
char V_309 [ V_433 ] ;
V_205 = F_134 ( V_184 , NULL , & ( V_399 -> V_402 . V_434 ) , V_309 ) ;
if ( V_205 != 0 ) break;
if ( V_399 -> V_402 . V_434 . V_413 ) {
if ( F_121 ( V_399 -> V_402 . V_434 . V_413 ,
V_309 ,
V_399 -> V_402 . V_434 . V_228 ) )
V_205 = - V_400 ;
}
}
break;
case V_439 :
F_6 ( V_69 , V_70 L_51 ) ;
V_205 = - V_405 ;
break;
case V_440 :
F_6 ( V_69 , V_70 L_51 ) ;
V_205 = - V_405 ;
break;
case V_441 :
V_205 = F_135 ( V_184 , NULL , & ( V_399 -> V_402 . V_442 ) , NULL ) ;
break;
case V_443 :
V_205 = F_136 ( V_184 , NULL , & ( V_399 -> V_402 . V_442 ) , NULL ) ;
break;
case V_444 :
{
struct V_445 V_446 ;
F_137 ( V_184 , NULL , & ( V_399 -> V_402 . V_47 ) , ( char * ) & V_446 ) ;
if ( F_121 ( V_399 -> V_402 . V_47 . V_413 , & V_446 , sizeof( struct V_445 ) ) )
V_205 = - V_400 ;
}
break;
case V_447 :
V_205 = F_138 ( V_184 , NULL , & ( V_399 -> V_402 . V_448 ) , NULL ) ;
break;
case V_449 :
V_205 = F_139 ( V_184 , NULL , & ( V_399 -> V_402 . V_448 ) , NULL ) ;
break;
case V_450 :
V_205 = F_140 ( V_184 , NULL , & ( V_399 -> V_402 . V_451 ) , NULL ) ;
break;
case V_452 :
F_6 ( V_69 , V_70 L_52 ) ;
V_205 = - V_405 ;
break;
case V_453 :
{
char V_360 [ V_454 * ( sizeof( struct V_455 ) + sizeof( struct V_456 ) ) ] ;
if ( V_399 -> V_402 . V_47 . V_413 ) {
V_205 = F_141 ( V_184 , NULL , & ( V_399 -> V_402 . V_47 ) , V_360 ) ;
if ( V_205 == 0 ) {
if ( F_121 ( V_399 -> V_402 . V_47 . V_413 ,
V_360 ,
( V_399 -> V_402 . V_47 . V_228 * ( sizeof( struct V_455 ) + sizeof( struct V_456 ) ) )
) )
V_205 = - V_400 ;
}
}
}
break;
#ifdef F_142
case V_457 :
F_6 ( V_69 , V_70 L_53 ) ;
V_205 = - V_405 ;
break;
case V_458 :
F_6 ( V_69 , V_70 L_53 ) ;
V_205 = - V_405 ;
break;
#endif
case V_459 :
F_6 ( V_69 , V_70 L_54 ) ;
V_205 = - V_405 ;
break;
#ifdef F_78
case V_460 :
F_6 ( V_69 , V_70 L_55 ) ;
V_205 = F_143 ( V_184 , NULL , & ( V_399 -> V_402 . V_461 ) , NULL ) ;
break;
case V_462 :
F_6 ( V_69 , V_70 L_56 ) ;
V_205 = F_144 ( V_184 , NULL , & ( V_399 -> V_402 . V_461 ) , NULL ) ;
break;
case V_463 :
F_6 ( V_69 , V_70 L_57 ) ;
V_205 = F_145 ( V_184 , NULL , & ( V_399 -> V_402 . V_47 ) , V_399 -> V_402 . V_47 . V_413 ) ;
break;
case V_464 :
F_6 ( V_69 , V_70 L_58 ) ;
V_205 = F_146 ( V_184 , NULL , & ( V_399 -> V_402 . V_47 ) , V_399 -> V_402 . V_47 . V_413 ) ;
break;
case V_465 :
{
char V_466 [ sizeof( struct V_467 ) + V_468 + 1 ] ;
F_6 ( V_69 , V_70 L_59 ) ;
if( V_399 -> V_402 . V_434 . V_413 ) {
memset ( V_466 , 0 , sizeof( struct V_467 ) + V_468 + 1 ) ;
if( V_399 -> V_402 . V_434 . V_228 > ( sizeof( struct V_467 ) + V_468 ) ) {
V_205 = - V_412 ;
break;
}
if( F_118 ( V_466 , V_399 -> V_402 . V_434 . V_413 , V_399 -> V_402 . V_434 . V_228 ) ) {
V_205 = - V_400 ;
break;
}
} else if( V_399 -> V_402 . V_434 . V_228 != 0 ) {
V_205 = - V_435 ;
break;
}
V_205 = F_147 ( V_184 , NULL , & ( V_399 -> V_402 . V_434 ) , V_466 ) ;
}
break;
case V_469 :
F_6 ( V_69 , V_70 L_60 ) ;
V_205 = F_148 ( V_184 , NULL , & ( V_399 -> V_402 . V_434 ) , NULL ) ;
break;
case V_470 :
F_6 ( V_69 , V_70 L_61 ) ;
V_205 = F_149 ( V_184 , NULL , & ( V_399 -> V_402 . V_47 ) , V_399 -> V_402 . V_47 . V_413 ) ;
break;
#endif
case V_471 :
if ( ! ( V_1 -> V_198 & V_199 ) ) {
V_205 = - V_400 ;
break;
} else {
V_205 = 0 ;
}
V_397 = ( T_18 ) V_395 ;
V_397 -> V_472 = V_473 ;
break;
case V_474 :
if ( ! ( V_1 -> V_198 & V_199 ) &&
( ( ( T_18 ) V_395 ) -> V_475 != V_476 ) )
{
V_205 = - V_400 ;
break;
} else {
V_205 = 0 ;
}
if ( F_150 ( 0 , ( void * ) & ( V_63 -> V_477 ) ) ) {
return - V_478 ;
}
V_205 = F_151 ( V_1 , V_395 ) ;
F_152 ( 0 , ( void * ) & ( V_63 -> V_477 ) ) ;
break;
case V_479 :
if ( ! ( V_1 -> V_198 & V_199 ) ) {
V_205 = - V_400 ;
break;
} else {
V_205 = 0 ;
}
V_205 = F_153 ( V_1 , & V_399 -> V_402 . V_47 ) ;
break;
case V_480 :
if ( ! ( V_1 -> V_198 & V_199 ) ) {
V_205 = - V_400 ;
break;
} else {
V_205 = 0 ;
}
V_205 = F_154 ( V_1 , & V_399 -> V_402 . V_47 ) ;
break;
case V_481 :
return F_155 ( V_184 , ( void * ) V_395 -> V_482 ) ;
default:
V_205 = - V_405 ;
F_6 ( V_69 , V_70 L_62 , V_396 ) ;
}
if ( V_1 -> V_483 ) {
if ( V_63 -> V_312 == V_313 ) {
F_81 ( V_1 -> V_184 ) ;
F_7 ( & V_1 -> V_71 ) ;
F_80 ( ( void * ) V_1 , V_314 , NULL ) ;
F_11 ( & V_1 -> V_71 ) ;
}
else {
F_6 ( V_69 , V_70 L_63 ) ;
F_7 ( & V_1 -> V_71 ) ;
if ( V_1 -> V_319 &&
memcmp ( V_63 -> V_484 , V_63 -> V_321 , V_322 + V_323 ) ) {
F_80 ( ( void * ) V_1 , V_320 , NULL ) ;
} else {
V_1 -> V_319 = FALSE ;
V_63 -> V_331 = V_332 ;
memset ( V_63 -> V_330 , 0 , 6 ) ;
}
F_24 ( V_1 , V_81 , V_172 , V_174 , V_175 ) ;
F_81 ( V_1 -> V_184 ) ;
#ifdef F_78
V_63 -> V_153 = V_485 ;
if ( ! V_1 -> V_303 )
#endif
F_80 ( ( void * ) V_1 ,
V_315 ,
V_63 -> V_321 ) ;
F_80 ( ( void * ) V_1 ,
V_486 ,
NULL ) ;
F_11 ( & V_1 -> V_71 ) ;
}
V_1 -> V_483 = FALSE ;
}
return V_205 ;
}
static int F_155 ( struct V_206 * V_184 , void * V_487 )
{
T_16 V_488 ;
if ( F_118 ( & V_488 , V_487 , sizeof( V_488 ) ) )
return - V_400 ;
switch ( V_488 ) {
case V_489 : {
struct V_490 V_491 = { V_489 } ;
strncpy ( V_491 . V_492 , V_493 , sizeof( V_491 . V_492 ) - 1 ) ;
strncpy ( V_491 . V_494 , V_210 , sizeof( V_491 . V_494 ) - 1 ) ;
if ( F_121 ( V_487 , & V_491 , sizeof( V_491 ) ) )
return - V_400 ;
return 0 ;
}
}
return - V_405 ;
}
