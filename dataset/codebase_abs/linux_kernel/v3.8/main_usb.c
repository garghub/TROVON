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
static int F_27 ( struct V_178 * V_179 , T_8 V_180 )
{
T_1 V_181 = F_28 ( V_179 ) ;
if ( ! V_181 || ! V_181 -> V_182 )
return - V_183 ;
if ( V_181 -> V_184 & V_185 )
F_29 ( V_181 -> V_182 ) ;
F_30 ( F_31 ( V_179 ) ) ;
return 0 ;
}
static int F_32 ( struct V_178 * V_179 )
{
T_1 V_181 = F_28 ( V_179 ) ;
if ( ! V_181 || ! V_181 -> V_182 )
return - V_183 ;
F_33 ( F_31 ( V_179 ) ) ;
if ( ! ( V_181 -> V_184 & V_185 ) )
F_34 ( V_181 -> V_182 ) ;
return 0 ;
}
static int
F_35 ( struct V_178 * V_179 , const struct V_186 * V_187 )
{
T_3 V_188 [ V_3 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ;
struct V_189 * V_190 = F_31 ( V_179 ) ;
int V_191 = 0 ;
struct V_192 * V_193 = NULL ;
T_1 V_1 = NULL ;
F_36 ( V_194 L_9 , V_195 , V_196 ) ;
F_36 ( V_194 L_10 ) ;
V_190 = F_33 ( V_190 ) ;
V_193 = F_37 ( sizeof( V_197 ) ) ;
if ( ! V_193 ) {
F_36 (KERN_ERR DEVICE_NAME L_11 ) ;
V_191 = - V_198 ;
goto V_199;
}
V_1 = F_38 ( V_193 ) ;
memset ( V_1 , 0 , sizeof( V_197 ) ) ;
V_1 -> V_182 = V_193 ;
V_1 -> V_200 = V_190 ;
F_1 ( V_1 ) ;
F_39 ( & V_1 -> V_71 ) ;
V_1 -> V_201 = V_202 ;
V_1 -> V_64 . V_203 = ( void * ) V_1 ;
V_193 -> V_204 = & V_205 ;
V_193 -> V_206 =
(struct V_207 * ) & V_208 ;
F_40 ( V_179 , V_1 ) ;
F_41 ( V_193 , & V_179 -> V_182 ) ;
memcpy ( V_1 -> V_182 -> V_209 , V_188 , V_3 ) ;
V_191 = F_42 ( V_193 ) ;
if ( V_191 ) {
F_36 (KERN_ERR DEVICE_NAME L_12 ) ;
goto V_210;
}
F_43 ( V_1 ) ;
return 0 ;
V_210:
F_44 ( V_193 ) ;
V_199:
F_30 ( V_190 ) ;
return V_191 ;
}
static void F_45 ( T_1 V_1 )
{
T_9 V_211 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_6 ; V_58 ++ ) {
V_211 = V_1 -> V_212 [ V_58 ] ;
if ( V_211 -> V_213 ) {
F_46 ( V_211 -> V_213 ) ;
F_47 ( V_211 -> V_213 ) ;
}
F_48 ( V_211 ) ;
}
return;
}
static void F_49 ( T_1 V_1 )
{
T_10 V_214 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_8 ; V_58 ++ ) {
V_214 = V_1 -> V_215 [ V_58 ] ;
if ( V_214 -> V_213 ) {
F_46 ( V_214 -> V_213 ) ;
F_47 ( V_214 -> V_213 ) ;
}
if ( V_214 -> V_216 )
F_50 ( V_214 -> V_216 ) ;
}
F_48 ( V_1 -> V_217 ) ;
return;
}
static void F_43 ( T_1 V_1 )
{
int V_218 ;
V_218 = F_51 ( V_1 -> V_200 ) ;
if ( V_218 )
F_36 ( L_13 , V_218 ) ;
return ;
}
static void F_52 ( T_1 V_1 )
{
F_48 ( V_1 -> V_219 . V_220 ) ;
return;
}
static BOOL F_53 ( T_1 V_1 ) {
T_9 V_211 ;
T_10 V_214 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_6 ; V_58 ++ ) {
V_211 = F_54 ( sizeof( V_221 ) , V_222 ) ;
if ( V_211 == NULL ) {
F_6 ( V_223 , V_224 L_14 , V_1 -> V_182 -> V_225 ) ;
goto V_226;
}
V_1 -> V_212 [ V_58 ] = V_211 ;
V_211 -> V_1 = ( void * ) V_1 ;
V_211 -> V_213 = F_55 ( 0 , V_227 ) ;
if ( V_211 -> V_213 == NULL ) {
F_6 ( V_223 , V_224 L_15 ) ;
goto V_226;
}
V_211 -> V_228 = FALSE ;
}
V_1 -> V_217 = F_56 ( ( sizeof( V_229 ) * V_1 -> V_8 ) , V_222 ) ;
if ( V_1 -> V_217 == NULL ) {
F_6 ( V_223 , V_224 L_16 , V_1 -> V_182 -> V_225 ) ;
goto V_226;
}
V_1 -> V_230 = NULL ;
V_1 -> V_231 = NULL ;
V_1 -> V_232 = NULL ;
V_1 -> V_233 = NULL ;
V_1 -> V_234 = 0 ;
V_214 = ( T_10 ) V_1 -> V_217 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_8 ; V_58 ++ ) {
V_1 -> V_215 [ V_58 ] = V_214 ;
V_214 -> V_1 = ( void * ) V_1 ;
V_214 -> V_213 = F_55 ( 0 , V_227 ) ;
if ( V_214 -> V_213 == NULL ) {
F_6 ( V_223 , V_224 L_17 ) ;
goto V_235;
}
V_214 -> V_216 = F_57 ( ( int ) V_1 -> V_236 ) ;
if ( V_214 -> V_216 == NULL ) {
F_6 ( V_223 , V_224 L_18 ) ;
goto V_235;
}
V_214 -> V_216 -> V_182 = V_1 -> V_182 ;
V_214 -> V_228 = FALSE ;
F_58 ( V_1 -> V_230 , V_1 -> V_231 , V_214 ) ;
V_1 -> V_234 ++ ;
V_214 ++ ;
}
V_1 -> V_237 = F_55 ( 0 , V_227 ) ;
if ( V_1 -> V_237 == NULL ) {
F_6 ( V_223 , V_224 L_19 ) ;
goto V_235;
}
V_1 -> V_238 = F_55 ( 0 , V_227 ) ;
if ( V_1 -> V_238 == NULL ) {
F_6 ( V_223 , V_224 L_20 ) ;
F_47 ( V_1 -> V_237 ) ;
goto V_235;
}
V_1 -> V_219 . V_220 = F_54 ( V_239 , V_222 ) ;
if ( V_1 -> V_219 . V_220 == NULL ) {
F_6 ( V_223 , V_224 L_21 ) ;
F_47 ( V_1 -> V_237 ) ;
F_47 ( V_1 -> V_238 ) ;
goto V_235;
}
return TRUE ;
V_235:
F_49 ( V_1 ) ;
V_226:
F_45 ( V_1 ) ;
return FALSE ;
}
static BOOL F_59 ( T_1 V_1 ) {
int V_240 ;
T_11 V_241 ;
for ( V_240 = 0 ; V_240 < V_242 ; V_240 ++ ) {
V_241 = & ( V_1 -> V_243 [ V_240 ] ) ;
if ( ! F_60 ( V_1 , V_241 ) ) {
F_6 ( V_223 , V_224 L_22 ,
V_1 -> V_182 -> V_225 ) ;
goto V_244;
}
}
V_1 -> V_245 = V_242 ;
V_1 -> V_246 = V_1 -> V_245 ;
return TRUE ;
V_244:
F_61 ( V_1 ) ;
return FALSE ;
}
static void F_61 ( T_1 V_1 ) {
T_11 V_241 ;
int V_240 ;
for ( V_240 = 0 ; V_240 < V_242 ; V_240 ++ ) {
V_241 = & ( V_1 -> V_243 [ V_240 ] ) ;
if ( V_241 -> V_216 )
F_50 ( V_241 -> V_216 ) ;
}
}
BOOL F_60 ( T_1 V_1 , T_11 V_241 ) {
V_241 -> V_216 = F_57 ( ( int ) V_1 -> V_236 ) ;
if ( V_241 -> V_216 == NULL )
return FALSE ;
ASSERT ( V_241 -> V_216 ) ;
V_241 -> V_216 -> V_182 = V_1 -> V_182 ;
return TRUE ;
}
static int F_34 ( struct V_192 * V_182 ) {
T_1 V_1 = ( T_1 ) F_38 ( V_182 ) ;
V_1 -> V_247 = FALSE ;
F_6 ( V_69 , V_70 L_23 ) ;
V_1 -> V_236 = V_248 ;
if ( F_53 ( V_1 ) == FALSE ) {
F_6 ( V_69 , V_70 L_24 ) ;
return - V_198 ;
}
if ( F_59 ( V_1 ) == FALSE ) {
F_6 ( V_69 , V_70 L_25 ) ;
goto V_235;
}
F_62 ( V_1 , V_249 ) ;
F_62 ( V_1 , V_250 ) ;
F_62 ( V_1 , V_251 ) ;
F_63 ( V_1 , V_252 ) ;
F_63 ( V_1 , V_253 ) ;
F_64 ( V_1 ) ;
if ( F_5 ( V_1 , V_72 ) == FALSE ) {
F_6 ( V_69 , V_70 L_26 ) ;
goto V_254;
}
F_65 ( V_1 -> V_182 ) ;
F_66 ( V_1 , & V_1 -> V_255 ) ;
memcpy ( V_1 -> V_64 . V_256 , V_1 -> V_75 , V_3 ) ;
memcpy ( V_1 -> V_182 -> V_209 , V_1 -> V_75 , V_3 ) ;
V_1 -> V_257 = FALSE ;
V_1 -> V_258 = FALSE ;
V_1 -> V_259 = FALSE ;
V_1 -> V_260 = FALSE ;
V_1 -> V_261 = FALSE ;
if ( V_1 -> V_45 ) {
F_2 ( V_1 ) ;
}
F_67 ( V_1 ) ;
F_68 ( & V_1 -> V_262 , ( void * ) V_263 , ( unsigned long ) V_1 ) ;
F_68 ( & V_1 -> V_264 , ( void * ) V_265 , ( unsigned long ) V_1 ) ;
F_68 ( & V_1 -> V_266 , ( void * ) V_267 , ( unsigned long ) V_1 ) ;
F_69 ( & ( V_1 -> V_64 . V_268 ) ) ;
V_1 -> V_269 = 100 ;
V_1 -> V_270 = V_271 ;
V_1 -> V_272 = TRUE ;
V_1 -> V_273 = FALSE ;
V_1 -> V_274 = FALSE ;
V_1 -> V_275 = FALSE ;
V_1 -> V_276 = FALSE ;
V_1 -> V_277 = FALSE ;
V_1 -> V_278 = FALSE ;
V_1 -> V_279 = FALSE ;
V_1 -> V_280 = FALSE ;
V_1 -> V_281 = 0 ;
V_265 ( V_1 ) ;
V_267 ( V_1 ) ;
if ( ( V_1 -> V_282 == TRUE ) && ( V_1 -> V_283 == TRUE ) ) {
F_7 ( & V_1 -> V_71 ) ;
F_70 ( V_1 ,
& ( V_1 -> V_255 ) ,
V_1 -> V_284 | ( 1 << 31 ) ,
V_1 -> V_285 ,
NULL ,
V_1 -> V_286 ,
V_287
) ;
F_11 ( & V_1 -> V_71 ) ;
V_1 -> V_270 = V_288 ;
}
if ( V_1 -> V_64 . V_289 == V_290 ) {
F_71 ( ( void * ) V_1 , V_291 , NULL ) ;
}
else {
F_71 ( ( void * ) V_1 , V_292 , NULL ) ;
}
F_72 ( V_1 -> V_182 ) ;
V_1 -> V_184 |= V_185 ;
F_6 ( V_69 , V_70 L_27 ) ;
return 0 ;
V_254:
F_61 ( V_1 ) ;
V_235:
F_49 ( V_1 ) ;
F_45 ( V_1 ) ;
F_52 ( V_1 ) ;
F_46 ( V_1 -> V_237 ) ;
F_46 ( V_1 -> V_238 ) ;
F_47 ( V_1 -> V_237 ) ;
F_47 ( V_1 -> V_238 ) ;
F_6 ( V_69 , V_70 L_28 ) ;
return - V_198 ;
}
static int F_29 ( struct V_192 * V_182 ) {
T_1 V_1 = ( T_1 ) F_38 ( V_182 ) ;
T_7 V_63 = & ( V_1 -> V_64 ) ;
int V_293 ;
F_6 ( V_69 , V_70 L_29 ) ;
if ( V_1 == NULL )
return - V_183 ;
if ( V_1 -> V_294 ) {
F_71 ( ( void * ) V_1 , V_295 , NULL ) ;
F_73 ( 30 ) ;
}
memset ( V_63 -> V_296 , 0 , V_297 + V_298 + 1 ) ;
V_63 -> V_299 = FALSE ;
V_1 -> V_282 = FALSE ;
V_1 -> V_270 = V_271 ;
F_7 ( & V_1 -> V_71 ) ;
for ( V_293 = 0 ; V_293 < V_300 ; V_293 ++ )
F_74 ( V_1 , V_293 ) ;
F_11 ( & V_1 -> V_71 ) ;
if ( ( V_1 -> V_184 & V_301 ) == FALSE ) {
F_75 ( V_1 ) ;
}
F_72 ( V_1 -> V_182 ) ;
F_63 ( V_1 , V_249 ) ;
F_62 ( V_1 , V_253 ) ;
F_62 ( V_1 , V_252 ) ;
V_1 -> V_273 = TRUE ;
F_76 ( & V_1 -> V_302 ) ;
F_76 ( & V_63 -> V_268 ) ;
F_76 ( & V_1 -> V_303 ) ;
if ( V_1 -> V_45 ) {
F_76 ( & V_1 -> V_46 ) ;
F_76 ( & V_1 -> V_53 ) ;
F_76 ( & V_1 -> V_54 ) ;
}
F_77 ( & V_1 -> V_262 ) ;
F_77 ( & V_1 -> V_264 ) ;
F_77 ( & V_1 -> V_266 ) ;
V_1 -> V_259 = FALSE ;
V_1 -> V_260 = FALSE ;
V_1 -> V_261 = FALSE ;
V_1 -> V_304 = FALSE ;
V_1 -> V_294 = FALSE ;
memset ( V_63 -> V_305 , 0 , 6 ) ;
V_63 -> V_306 = V_307 ;
F_45 ( V_1 ) ;
F_49 ( V_1 ) ;
F_52 ( V_1 ) ;
F_61 ( V_1 ) ;
F_46 ( V_1 -> V_237 ) ;
F_46 ( V_1 -> V_238 ) ;
F_47 ( V_1 -> V_237 ) ;
F_47 ( V_1 -> V_238 ) ;
F_78 ( V_1 , 0 ) ;
V_1 -> V_184 &= ( ~ V_185 ) ;
F_6 ( V_69 , V_70 L_30 ) ;
return 0 ;
}
static void F_79 ( struct V_178 * V_179 )
{
T_1 V_181 = F_28 ( V_179 ) ;
if ( ! V_181 )
return;
F_40 ( V_179 , NULL ) ;
F_30 ( F_31 ( V_179 ) ) ;
V_181 -> V_184 |= V_301 ;
if ( V_181 -> V_182 ) {
F_80 ( V_181 -> V_182 ) ;
F_44 ( V_181 -> V_182 ) ;
}
}
static int V_202 ( struct V_308 * V_216 , struct V_192 * V_182 )
{
T_1 V_1 = F_38 ( V_182 ) ;
F_7 ( & V_1 -> V_71 ) ;
if ( F_81 ( V_1 -> V_257 ) )
F_82 ( V_216 ) ;
else
F_83 ( V_1 , V_216 ) ;
F_11 ( & V_1 -> V_71 ) ;
return V_309 ;
}
static int F_84 ( struct V_308 * V_216 , struct V_192 * V_182 )
{
T_1 V_1 = F_38 ( V_182 ) ;
struct V_310 * V_311 = & V_1 -> V_311 ;
F_7 ( & V_1 -> V_71 ) ;
F_72 ( V_182 ) ;
if ( ! V_1 -> V_294 ) {
F_82 ( V_216 ) ;
goto V_312;
}
if ( V_1 -> V_258 ) {
F_82 ( V_216 ) ;
V_311 -> V_313 ++ ;
goto V_312;
}
if ( F_85 ( V_1 , V_314 , V_216 ) ) {
if ( F_86 ( V_182 ) )
F_87 ( V_182 ) ;
}
V_312:
F_11 ( & V_1 -> V_71 ) ;
return V_309 ;
}
static inline T_12 F_88 ( int V_315 , unsigned char * V_47 )
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
int V_58 ;
memset ( V_326 , 0 , 100 ) ;
strcat ( V_326 , string ) ;
strcat ( V_326 , L_31 ) ;
V_325 += strlen ( V_326 ) ;
V_328 = F_89 ( V_325 , V_326 ) ;
if ( V_328 == NULL )
return FALSE ;
for ( V_58 = 1 ; ; V_58 ++ ) {
if ( memcmp ( V_328 - V_58 , L_32 , 1 ) == 0 )
break;
if ( memcmp ( V_328 - V_58 , L_33 , 1 ) == 0 )
return FALSE ;
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
return FALSE ;
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
return TRUE ;
}
static unsigned char * F_91 ( T_1 V_1 )
{
unsigned char * V_331 = V_332 ;
unsigned char * V_333 = NULL ;
struct V_334 * V_335 = NULL ;
T_13 V_336 = F_92 () ;
int V_337 = 0 ;
F_93 ( V_338 ) ;
V_335 = F_94 ( V_331 , V_339 , 0 ) ;
if ( F_95 ( V_335 ) ) {
F_36 ( L_34 ) ;
V_337 = - 1 ;
goto V_340;
}
if( ! ( V_335 -> V_341 ) || ! ( V_335 -> V_341 -> V_342 ) || ! ( V_335 -> V_341 -> V_343 ) ) {
F_36 ( L_35 , V_331 ) ;
V_337 = - 1 ;
goto V_344;
}
V_333 = F_54 ( 1024 , V_222 ) ;
if( V_333 == NULL ) {
F_36 ( L_36 ) ;
V_337 = - 1 ;
goto V_344;
}
if( V_335 -> V_341 -> V_342 ( V_335 , V_333 , 1024 , & V_335 -> V_345 ) < 0 ) {
F_36 ( L_37 ) ;
V_337 = - 1 ;
}
V_344:
if( F_96 ( V_335 , NULL ) )
F_36 ( L_38 ) ;
V_340:
F_93 ( V_336 ) ;
if( V_337 != 0 ) {
F_48 ( V_333 ) ;
V_333 = NULL ;
}
return V_333 ;
}
static int F_64 ( T_1 V_1 ) {
int V_337 = 0 ;
unsigned char V_346 [ 100 ] ;
unsigned char * V_333 = NULL ;
V_1 -> V_347 . V_348 = - 1 ;
V_1 -> V_347 . V_349 = - 1 ;
V_1 -> V_347 . V_270 = - 1 ;
V_333 = F_91 ( V_1 ) ;
if ( V_333 == NULL ) {
V_337 = - 1 ;
return V_337 ;
}
{
memset ( V_346 , 0 , sizeof( V_346 ) ) ;
if( F_90 ( L_39 , V_346 , V_333 ) == TRUE ) {
if( memcmp ( V_346 , L_40 , 3 ) == 0 ) {
V_1 -> V_347 . V_348 = V_111 ;
}
else if( memcmp ( V_346 , L_41 , 5 ) == 0 ) {
V_1 -> V_347 . V_348 = V_108 ;
}
else if( memcmp ( V_346 , L_42 , 6 ) == 0 ) {
V_1 -> V_347 . V_348 = V_109 ;
}
else {
F_36 ( L_43 , V_346 ) ;
}
}
}
{
memset ( V_346 , 0 , sizeof( V_346 ) ) ;
if( F_90 ( L_44 , V_346 , V_333 ) == TRUE ) {
V_1 -> V_347 . V_349 = ( int ) F_97 ( V_346 , NULL , 10 ) ;
}
memset ( V_346 , 0 , sizeof( V_346 ) ) ;
if( F_90 ( L_45 , V_346 , V_333 ) == TRUE ) {
V_1 -> V_347 . V_270 = ( int ) F_97 ( V_346 , NULL , 10 ) ;
}
}
F_48 ( V_333 ) ;
return V_337 ;
}
static void F_65 ( struct V_192 * V_182 ) {
T_1 V_1 = ( T_1 ) F_38 ( V_182 ) ;
T_7 V_63 = & ( V_1 -> V_64 ) ;
T_12 V_350 [ 2 ] ;
int V_58 ;
struct V_351 * V_352 ;
T_2 V_353 [ 8 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_2 V_354 = 0 ;
int V_191 ;
F_7 ( & V_1 -> V_71 ) ;
V_191 = F_14 ( V_1 ,
V_79 ,
V_355 ,
V_81 ,
1 ,
& V_354
) ;
if ( V_191 == 0 ) V_1 -> V_356 = V_354 ;
F_6 ( V_69 , V_70 L_46 , V_1 -> V_356 ) ;
if ( V_182 -> V_184 & V_357 ) {
F_6 ( V_223 , V_194 L_47 , V_182 -> V_225 ) ;
V_1 -> V_356 |= ( V_358 | V_359 | V_360 ) ;
}
else if ( ( F_98 ( V_182 ) > V_1 -> V_361 ) ||
( V_182 -> V_184 & V_362 ) ) {
F_13 ( V_1 ,
V_363 ,
V_364 ,
V_81 ,
8 ,
V_353
) ;
V_1 -> V_356 |= ( V_358 | V_359 ) ;
}
else {
memset ( V_350 , 0 , sizeof( V_350 ) ) ;
F_99 (ha, dev) {
int V_365 = F_88 ( V_3 , V_352 -> V_366 ) >> 26 ;
V_350 [ V_365 >> 5 ] |= F_100 ( 1 << ( V_365 & 31 ) ) ;
}
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ ) {
F_101 ( V_1 , V_58 , * ( ( V_77 ) & V_350 [ 0 ] + V_58 ) ) ;
F_101 ( V_1 , V_58 + 4 , * ( ( V_77 ) & V_350 [ 1 ] + V_58 ) ) ;
}
V_1 -> V_356 &= ~ ( V_360 ) ;
V_1 -> V_356 |= ( V_358 | V_359 ) ;
}
if ( V_63 -> V_289 == V_290 ) {
V_1 -> V_356 |= ( V_358 | V_359 ) ;
V_1 -> V_356 &= ~ ( V_360 ) ;
}
F_16 ( V_1 , V_81 , V_355 , V_1 -> V_356 ) ;
F_6 ( V_69 , V_70 L_48 , V_1 -> V_356 ) ;
F_11 ( & V_1 -> V_71 ) ;
}
static struct V_310 * F_102 ( struct V_192 * V_182 )
{
T_1 V_1 = ( T_1 ) F_38 ( V_182 ) ;
return & V_1 -> V_311 ;
}
static int F_103 ( struct V_192 * V_182 , struct V_367 * V_368 , int V_369 )
{
T_1 V_1 = ( T_1 ) F_38 ( V_182 ) ;
struct V_370 * V_371 = (struct V_370 * ) V_368 ;
int V_191 = 0 ;
switch ( V_369 ) {
case V_372 :
if ( ! ( V_1 -> V_184 & V_185 ) )
V_191 = - V_373 ;
V_191 = F_104 ( V_1 , & V_371 -> V_374 . V_47 ) ;
break;
case V_375 :
return F_105 ( V_182 , ( void * ) V_368 -> V_376 ) ;
}
return V_191 ;
}
static int F_105 ( struct V_192 * V_182 , void * V_377 )
{
T_12 V_378 ;
if ( F_106 ( & V_378 , V_377 , sizeof( V_378 ) ) )
return - V_373 ;
switch ( V_378 ) {
case V_379 : {
struct V_380 V_381 = { V_379 } ;
strncpy ( V_381 . V_382 , V_383 , sizeof( V_381 . V_382 ) - 1 ) ;
strncpy ( V_381 . V_384 , V_196 , sizeof( V_381 . V_384 ) - 1 ) ;
if ( F_107 ( V_377 , & V_381 , sizeof( V_381 ) ) )
return - V_373 ;
return 0 ;
}
}
return - V_385 ;
}
