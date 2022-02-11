T_1 F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
V_2 -> V_3 = sizeof( struct V_4 ) ;
V_2 -> V_5 = F_3 ( V_2 -> V_3 ) ;
if ( V_2 -> V_5 == NULL ) {
F_4 ( L_1 ) ;
return V_6 ;
}
}
return V_7 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_5 ) {
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_3 = 0 ;
}
}
}
void F_8 ( T_2 V_8 )
{
int V_9 = 0 ;
T_1 V_10 [ 128 ] ;
V_9 += sprintf ( ( V_10 + V_9 ) , L_2 ) ;
V_9 += sprintf ( ( V_10 + V_9 ) , L_3 , F_9 ( V_8 ) ? L_4 : L_5 ) ;
if ( F_10 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_3 , L_6 ) ;
else if ( F_11 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_3 , L_7 ) ;
else if ( F_12 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_3 , L_8 ) ;
if ( F_13 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_9 ) ;
else if ( F_14 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_10 ) ;
else if ( F_15 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_11 ) ;
else if ( F_16 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_12 ) ;
else if ( F_17 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_13 ) ;
else if ( F_18 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_14 ) ;
else if ( F_19 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_15 ) ;
else if ( F_20 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_16 ) ;
else
V_9 += sprintf ( ( V_10 + V_9 ) , L_17 , V_8 . V_11 ) ;
if ( F_21 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_18 ) ;
else if ( F_22 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_19 ) ;
else if ( F_23 ( V_8 ) )
V_9 += sprintf ( ( V_10 + V_9 ) , L_20 ) ;
else
V_9 += sprintf ( ( V_10 + V_9 ) , L_21 , V_8 . V_12 ) ;
V_9 += sprintf ( ( V_10 + V_9 ) , L_22 , V_8 . V_13 ) ;
F_24 ( L_23 , V_10 ) ;
}
T_1 F_25 (
struct V_1 * V_2 ,
T_1 V_14 ,
T_1 V_15 ,
T_1 V_16 ,
bool V_17
)
{
struct V_4 * V_18 ;
T_1 V_19 ;
V_18 = F_26 ( V_2 ) ;
V_18 -> V_20 = false ;
V_19 = V_16 ;
if ( 0xFF == V_14 )
V_17 = true ;
if ( false == V_17 ) {
T_1 V_21 ;
V_21 = V_14 & ( ~ V_22 ) ;
if ( F_27 ( V_21 ) ) {
#ifndef F_28
if ( V_14 & V_22 )
V_18 -> V_20 = true ;
#endif
V_19 = V_21 ;
}
}
if (
( false == V_18 -> V_20 ) &&
F_27 ( V_15 )
)
V_19 = V_15 ;
return V_19 ;
}
bool F_29 ( struct V_1 * V_23 , T_3 V_24 )
{
bool V_25 = true ;
if ( V_24 > 14 ) {
V_25 = false ;
F_24 ( L_24 ) ;
} else if ( ( V_24 <= 14 ) && ( V_24 >= 1 ) ) {
if ( F_30 ( V_23 -> V_26 . V_27 ) == false ) {
V_25 = false ;
F_24 ( L_25 ) ;
}
} else {
V_25 = false ;
F_24 ( L_26 ) ;
}
return V_25 ;
}
T_1 F_31 ( T_1 V_28 )
{
T_1 V_29 = V_30 ;
switch ( V_28 ) {
case V_31 :
V_29 = V_30 ;
break;
case V_32 :
V_29 = V_33 ;
break;
case V_34 :
V_29 = V_35 ;
break;
case V_36 :
V_29 = V_37 ;
break;
case V_38 :
V_29 = V_39 ;
break;
case V_40 :
V_29 = V_41 ;
break;
case V_42 :
V_29 = V_43 ;
break;
case V_44 :
V_29 = V_45 ;
break;
case V_46 :
V_29 = V_47 ;
break;
case V_48 :
V_29 = V_49 ;
break;
case V_50 :
V_29 = V_51 ;
break;
case V_52 :
V_29 = V_53 ;
break;
case V_54 :
V_29 = V_55 ;
break;
case V_56 :
V_29 = V_57 ;
break;
case V_58 :
V_29 = V_59 ;
break;
case V_60 :
V_29 = V_61 ;
break;
case V_62 :
V_29 = V_63 ;
break;
case V_64 :
V_29 = V_65 ;
break;
case V_66 :
V_29 = V_67 ;
break;
case V_68 :
V_29 = V_69 ;
break;
case V_70 :
V_29 = V_71 ;
break;
case V_72 :
V_29 = V_73 ;
break;
case V_74 :
V_29 = V_75 ;
break;
case V_76 :
V_29 = V_77 ;
break;
case V_78 :
V_29 = V_79 ;
break;
case V_80 :
V_29 = V_81 ;
break;
case V_82 :
V_29 = V_83 ;
break;
case V_84 :
V_29 = V_85 ;
break;
case V_86 :
V_29 = V_87 ;
break;
case V_88 :
V_29 = V_89 ;
break;
case V_90 :
V_29 = V_91 ;
break;
case V_92 :
V_29 = V_93 ;
break;
case V_94 :
V_29 = V_95 ;
break;
case V_96 :
V_29 = V_97 ;
break;
case V_98 :
V_29 = V_99 ;
break;
case V_100 :
V_29 = V_101 ;
break;
case V_102 :
V_29 = V_103 ;
break;
case V_104 :
V_29 = V_105 ;
break;
case V_106 :
V_29 = V_107 ;
break;
case V_108 :
V_29 = V_109 ;
break;
case V_110 :
V_29 = V_111 ;
break;
case V_112 :
V_29 = V_113 ;
break;
case V_114 :
V_29 = V_115 ;
break;
case V_116 :
V_29 = V_117 ;
break;
case V_118 :
V_29 = V_119 ;
break;
case V_120 :
V_29 = V_121 ;
break;
case V_122 :
V_29 = V_123 ;
break;
case V_124 :
V_29 = V_125 ;
break;
case V_126 :
V_29 = V_127 ;
break;
case V_128 :
V_29 = V_129 ;
break;
case V_130 :
V_29 = V_131 ;
break;
case V_132 :
V_29 = V_133 ;
break;
case V_134 :
V_29 = V_135 ;
break;
case V_136 :
V_29 = V_137 ;
break;
case V_138 :
V_29 = V_139 ;
break;
case V_140 :
V_29 = V_141 ;
break;
case V_142 :
V_29 = V_143 ;
break;
case V_144 :
V_29 = V_145 ;
break;
case V_146 :
V_29 = V_147 ;
break;
case V_148 :
V_29 = V_149 ;
break;
case V_150 :
V_29 = V_151 ;
break;
case V_152 :
V_29 = V_153 ;
break;
case V_154 :
V_29 = V_155 ;
break;
case V_156 :
V_29 = V_157 ;
break;
case V_158 :
V_29 = V_159 ;
break;
case V_160 :
V_29 = V_161 ;
break;
case V_162 :
V_29 = V_163 ;
break;
case V_164 :
V_29 = V_165 ;
break;
case V_166 :
V_29 = V_167 ;
break;
case V_168 :
V_29 = V_169 ;
break;
case V_170 :
V_29 = V_171 ;
break;
case V_172 :
V_29 = V_173 ;
break;
case V_174 :
V_29 = V_175 ;
break;
case V_176 :
V_29 = V_177 ;
break;
case V_178 :
V_29 = V_179 ;
break;
case V_180 :
V_29 = V_181 ;
break;
case V_182 :
V_29 = V_183 ;
break;
case V_184 :
V_29 = V_185 ;
break;
case V_186 :
V_29 = V_187 ;
break;
case V_188 :
V_29 = V_189 ;
break;
case V_190 :
V_29 = V_191 ;
break;
case V_192 :
V_29 = V_193 ;
break;
case V_194 :
V_29 = V_195 ;
break;
case V_196 :
V_29 = V_197 ;
break;
default:
break;
}
return V_29 ;
}
T_1 F_32 ( T_1 V_28 )
{
T_1 V_198 = V_31 ;
switch ( V_28 ) {
case V_30 :
V_198 = V_31 ;
break;
case V_33 :
V_198 = V_32 ;
break;
case V_35 :
V_198 = V_34 ;
break;
case V_37 :
V_198 = V_36 ;
break;
case V_39 :
V_198 = V_38 ;
break;
case V_41 :
V_198 = V_40 ;
break;
case V_43 :
V_198 = V_42 ;
break;
case V_45 :
V_198 = V_44 ;
break;
case V_47 :
V_198 = V_46 ;
break;
case V_49 :
V_198 = V_48 ;
break;
case V_51 :
V_198 = V_50 ;
break;
case V_53 :
V_198 = V_52 ;
break;
case V_55 :
V_198 = V_54 ;
break;
case V_57 :
V_198 = V_56 ;
break;
case V_59 :
V_198 = V_58 ;
break;
case V_61 :
V_198 = V_60 ;
break;
case V_63 :
V_198 = V_62 ;
break;
case V_65 :
V_198 = V_64 ;
break;
case V_67 :
V_198 = V_66 ;
break;
case V_69 :
V_198 = V_68 ;
break;
case V_71 :
V_198 = V_70 ;
break;
case V_73 :
V_198 = V_72 ;
break;
case V_75 :
V_198 = V_74 ;
break;
case V_77 :
V_198 = V_76 ;
break;
case V_79 :
V_198 = V_78 ;
break;
case V_81 :
V_198 = V_80 ;
break;
case V_83 :
V_198 = V_82 ;
break;
case V_85 :
V_198 = V_84 ;
break;
case V_87 :
V_198 = V_86 ;
break;
case V_89 :
V_198 = V_88 ;
break;
case V_91 :
V_198 = V_90 ;
break;
case V_93 :
V_198 = V_92 ;
break;
case V_95 :
V_198 = V_94 ;
break;
case V_97 :
V_198 = V_96 ;
break;
case V_99 :
V_198 = V_98 ;
break;
case V_101 :
V_198 = V_100 ;
break;
case V_103 :
V_198 = V_102 ;
break;
case V_105 :
V_198 = V_104 ;
break;
case V_107 :
V_198 = V_106 ;
break;
case V_109 :
V_198 = V_108 ;
break;
case V_111 :
V_198 = V_110 ;
break;
case V_113 :
V_198 = V_112 ;
break;
case V_115 :
V_198 = V_114 ;
break;
case V_117 :
V_198 = V_116 ;
break;
case V_119 :
V_198 = V_118 ;
break;
case V_121 :
V_198 = V_120 ;
break;
case V_123 :
V_198 = V_122 ;
break;
case V_125 :
V_198 = V_124 ;
break;
case V_127 :
V_198 = V_126 ;
break;
case V_129 :
V_198 = V_128 ;
break;
case V_131 :
V_198 = V_130 ;
break;
case V_133 :
V_198 = V_132 ;
break;
case V_135 :
V_198 = V_134 ;
break;
case V_137 :
V_198 = V_136 ;
break;
case V_139 :
V_198 = V_138 ;
break;
case V_141 :
V_198 = V_140 ;
break;
case V_143 :
V_198 = V_142 ;
break;
case V_145 :
V_198 = V_144 ;
break;
case V_147 :
V_198 = V_146 ;
break;
case V_149 :
V_198 = V_148 ;
break;
case V_151 :
V_198 = V_150 ;
break;
case V_153 :
V_198 = V_152 ;
break;
case V_155 :
V_198 = V_154 ;
break;
case V_157 :
V_198 = V_156 ;
break;
case V_159 :
V_198 = V_158 ;
break;
case V_161 :
V_198 = V_160 ;
break;
case V_163 :
V_198 = V_162 ;
break;
case V_165 :
V_198 = V_164 ;
break;
case V_167 :
V_198 = V_166 ;
break;
case V_169 :
V_198 = V_168 ;
break;
case V_171 :
V_198 = V_170 ;
break;
case V_173 :
V_198 = V_172 ;
break;
case V_175 :
V_198 = V_174 ;
break;
case V_177 :
V_198 = V_176 ;
break;
case V_179 :
V_198 = V_178 ;
break;
case V_181 :
V_198 = V_180 ;
break;
case V_183 :
V_198 = V_182 ;
break;
case V_185 :
V_198 = V_184 ;
break;
case V_187 :
V_198 = V_186 ;
break;
case V_189 :
V_198 = V_188 ;
break;
case V_191 :
V_198 = V_190 ;
break;
case V_193 :
V_198 = V_192 ;
break;
case V_195 :
V_198 = V_194 ;
break;
case V_197 :
V_198 = V_196 ;
break;
default:
F_24 ( L_27 , V_28 ) ;
break;
}
return V_198 ;
}
void F_33 ( struct V_1 * V_23 , T_1 * V_199 , T_4 * V_200 )
{
T_1 V_201 , V_202 , V_203 ;
for ( V_201 = 0 ; V_201 < V_204 ; V_201 ++ ) {
V_202 = V_199 [ V_201 ] & V_205 ;
V_203 = V_199 [ V_201 ] & 0x7f ;
if ( V_202 ) {
switch ( V_203 ) {
case V_206 :
* V_200 |= V_207 ;
break;
case V_208 :
* V_200 |= V_209 ;
break;
case V_210 :
* V_200 |= V_211 ;
break;
case V_212 :
* V_200 |= V_213 ;
break;
case V_214 :
* V_200 |= V_215 ;
break;
case V_216 :
* V_200 |= V_217 ;
break;
case V_218 :
* V_200 |= V_219 ;
break;
case V_220 :
* V_200 |= V_221 ;
break;
case V_222 :
* V_200 |= V_223 ;
break;
case V_224 :
* V_200 |= V_225 ;
break;
case V_226 :
* V_200 |= V_227 ;
break;
case V_228 :
* V_200 |= V_229 ;
break;
}
}
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_230 * V_231 = F_35 ( V_2 ) ;
V_231 -> V_232 [ 0 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 1 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 2 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 3 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 4 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 5 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 6 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 7 ] = V_231 -> V_233 [ 0 ] ;
}
static void F_36 ( struct V_1 * V_2 , bool V_234 )
{
struct V_230 * V_231 = F_35 ( V_2 ) ;
if ( V_234 ) {
V_231 -> V_232 [ 0 ] = V_231 -> V_233 [ 1 ] ;
V_231 -> V_232 [ 1 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 2 ] = V_231 -> V_233 [ 1 ] ;
V_231 -> V_232 [ 3 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 4 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 5 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 6 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 7 ] = V_231 -> V_233 [ 0 ] ;
} else {
V_231 -> V_232 [ 0 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 1 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 2 ] = V_231 -> V_233 [ 1 ] ;
V_231 -> V_232 [ 3 ] = V_231 -> V_233 [ 1 ] ;
V_231 -> V_232 [ 4 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 5 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 6 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 7 ] = V_231 -> V_233 [ 0 ] ;
}
}
static void F_37 ( struct V_1 * V_2 , bool V_234 )
{
struct V_230 * V_231 = F_35 ( V_2 ) ;
if ( V_234 ) {
V_231 -> V_232 [ 0 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 1 ] = V_231 -> V_233 [ 1 ] ;
V_231 -> V_232 [ 2 ] = V_231 -> V_233 [ 2 ] ;
V_231 -> V_232 [ 3 ] = V_231 -> V_233 [ 1 ] ;
V_231 -> V_232 [ 4 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 5 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 6 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 7 ] = V_231 -> V_233 [ 0 ] ;
} else {
V_231 -> V_232 [ 0 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 1 ] = V_231 -> V_233 [ 1 ] ;
V_231 -> V_232 [ 2 ] = V_231 -> V_233 [ 2 ] ;
V_231 -> V_232 [ 3 ] = V_231 -> V_233 [ 2 ] ;
V_231 -> V_232 [ 4 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 5 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 6 ] = V_231 -> V_233 [ 0 ] ;
V_231 -> V_232 [ 7 ] = V_231 -> V_233 [ 0 ] ;
}
}
bool F_38 ( struct V_1 * V_2 , T_1 V_235 )
{
struct V_236 * V_237 = & V_2 -> V_26 ;
bool V_234 = ( V_237 -> V_238 ) ? true : false ;
bool V_239 = true ;
switch ( V_235 ) {
case 2 :
F_36 ( V_2 , V_234 ) ;
break;
case 3 :
case 4 :
F_37 ( V_2 , V_234 ) ;
break;
case 1 :
F_34 ( V_2 ) ;
break;
default:
V_239 = false ;
break;
}
return V_239 ;
}
void F_39 ( struct V_1 * V_1 )
{
F_40 ( V_1 , V_240 , V_1 -> V_241 . V_242 ) ;
}
void F_41 ( struct V_1 * V_23 )
{
struct V_4 * V_18 = F_26 ( V_23 ) ;
V_18 -> V_243 = 1 ;
}
void F_42 ( struct V_1 * V_1 )
{
F_43 ( V_1 , V_244 , V_245 ) ;
}
T_5 F_44 ( struct V_1 * V_1 , T_1 * V_10 )
{
T_5 V_29 = V_6 ;
struct V_246 * V_247 ;
int V_201 ;
T_1 V_248 ;
if ( V_10 == NULL )
goto exit;
V_248 = F_45 ( V_1 , V_244 ) ;
if ( V_248 == V_245 )
goto exit;
else if ( V_248 != V_249 )
goto V_250;
V_247 = (struct V_246 * ) V_10 ;
memset ( V_247 , 0 , 16 ) ;
V_247 -> V_251 = F_45 ( V_1 , V_252 ) ;
V_247 -> V_253 = F_45 ( V_1 , V_254 ) ;
V_247 -> V_255 = F_45 ( V_1 , V_256 ) ;
F_46 (
V_257 ,
V_258 ,
L_28 ,
& V_247 ,
sizeof( V_247 )
) ;
F_24 (
L_29 ,
V_259 ,
V_247 -> V_251 ,
V_247 -> V_255 ,
V_247 -> V_253 ,
V_248
) ;
for ( V_201 = 0 ; V_201 < V_247 -> V_255 ; V_201 ++ )
V_247 -> V_260 [ V_201 ] = F_45 ( V_1 , V_252 + 2 + V_201 ) ;
F_46 ( V_257 , V_258 , L_30 ,
V_247 -> V_260 , V_247 -> V_255 ) ;
V_29 = V_7 ;
V_250:
F_42 ( V_1 ) ;
exit:
return V_29 ;
}
T_1 F_47 ( struct V_1 * V_1 , struct V_261 * V_262 )
{
return F_48 ( V_1 , V_262 ) ;
}
T_1 F_49 ( struct V_1 * V_1 , unsigned char V_263 )
{
T_1 V_264 ;
V_264 = ( V_263 & V_265 ) ? V_266 : V_267 ;
return V_264 ;
}
void F_50 ( struct V_1 * V_2 , struct V_261 * V_262 )
{
T_1 V_201 , V_268 , V_269 ;
T_3 V_270 ;
if ( V_262 == NULL )
return;
V_270 = 0 ;
for ( V_201 = 0 ; V_201 < sizeof( V_262 -> V_271 ) ; V_201 ++ ) {
if ( V_262 -> V_271 [ V_201 ] )
V_270 |= F_51 ( V_262 -> V_271 [ V_201 ] & 0x7f ) ;
}
if ( V_262 -> V_272 . V_273 ) {
F_52 ( V_2 , V_274 , ( T_1 * ) ( & V_268 ) ) ;
if ( V_268 == V_275 )
V_269 = 16 ;
else
V_269 = 8 ;
for ( V_201 = 0 ; V_201 < V_269 ; V_201 ++ ) {
if ( V_262 -> V_272 . V_276 . V_277 [ V_201 / 8 ] & F_53 ( V_201 % 8 ) )
V_270 |= F_53 ( V_201 + 12 ) ;
}
}
V_262 -> V_278 = V_270 ;
V_262 -> V_279 = F_54 ( V_270 ) & 0x3f ;
}
void F_55 ( struct V_1 * V_1 )
{
}
void F_56 ( struct V_1 * V_1 , T_1 V_280 , T_1 * V_281 )
{
struct V_4 * V_282 = F_26 ( V_1 ) ;
T_6 * V_283 = & ( V_282 -> V_284 ) ;
switch ( V_280 ) {
case V_285 :
F_55 ( V_1 ) ;
break;
case V_286 :
F_57 ( 1 ) ;
break;
case V_287 :
{
T_4 V_288 ;
V_288 = F_58 ( V_1 , V_289 ) ;
F_59 ( V_1 , V_289 , V_288 | V_290 | V_291 | V_292 ) ;
}
break;
case V_293 :
{
struct V_294 * V_295 = & V_1 -> V_296 ;
T_1 V_288 = F_45 ( V_1 , V_289 ) ;
if ( V_281 ) {
V_288 |= V_297 ;
if ( V_295 -> V_298 != V_299 )
V_288 |= ( V_300 | V_301 ) ;
} else
V_288 &= ~ ( V_302 | V_297 | V_300 | V_301 ) ;
F_43 ( V_1 , V_289 , V_288 ) ;
}
break;
case V_303 :
V_283 -> V_304 = * ( ( T_3 * ) V_281 ) ;
break;
case V_305 :
if ( * ( ( T_1 * ) V_281 ) == true ) {
V_283 -> V_306 = V_283 -> V_304 ;
} else {
V_283 -> V_304 = V_283 -> V_306 ;
}
break;
case V_307 :
if ( * ( ( T_3 * ) V_281 ) == V_308 ) {
struct V_309 * V_310 = & V_282 -> V_311 ;
V_310 -> V_312 = V_310 -> V_313 ;
V_283 -> V_304 = V_310 -> V_314 ;
} else {
V_283 -> V_304 |= * ( ( T_3 * ) V_281 ) ;
}
break;
case V_315 :
V_283 -> V_304 &= * ( ( T_3 * ) V_281 ) ;
break;
case V_316 :
break;
case V_317 :
break;
default:
F_60 (
V_318 ,
V_319 L_31 ,
F_61 ( V_1 ) ,
V_280
) ;
break;
}
}
void F_62 ( struct V_1 * V_1 , T_1 V_280 , T_1 * V_281 )
{
struct V_4 * V_282 = F_26 ( V_1 ) ;
T_6 * V_283 = & ( V_282 -> V_284 ) ;
switch ( V_280 ) {
case V_320 :
* ( ( T_4 * ) V_281 ) = V_282 -> V_321 ;
break;
case V_303 :
* ( ( T_3 * ) V_281 ) = V_283 -> V_304 ;
break;
case V_274 :
* ( ( T_1 * ) V_281 ) = V_282 -> V_268 ;
break;
default:
F_60 (
V_318 ,
V_319 L_31 ,
F_61 ( V_1 ) ,
V_280
) ;
break;
}
}
T_1 F_63 (
struct V_1 * V_1 , enum V_322 V_280 , void * V_323
)
{
struct V_4 * V_282 = F_26 ( V_1 ) ;
T_6 * V_283 = & ( V_282 -> V_284 ) ;
T_1 V_324 = V_7 ;
switch ( V_280 ) {
case V_325 :
if ( * ( ( T_1 * ) V_323 ) )
V_283 -> V_326 |= ( V_327 | V_328 ) ;
else
V_283 -> V_326 &= ~ ( V_327 | V_328 ) ;
break;
case V_329 :
F_24 ( L_32 ) ;
F_24 ( L_33 ,
V_283 -> V_330 , V_283 -> V_331 ) ;
if ( V_283 -> V_330 ) {
F_24 ( L_34 ,
F_64 ( V_283 -> V_332 ) , V_283 -> V_333 , V_283 -> V_334 ) ;
#ifdef F_65
F_66 ( V_1 ) ;
#endif
}
break;
case V_335 :
F_67 ( V_283 , V_336 , * ( ( V_337 * ) V_323 ) ) ;
break;
case V_338 :
F_67 ( V_283 , V_339 , * ( ( T_3 * ) V_323 ) ) ;
break;
case V_340 :
{
T_1 V_341 = * ( ( T_1 * ) V_323 ) ;
struct V_309 * V_310 = & V_282 -> V_311 ;
if ( V_341 == 0 ) {
V_283 -> V_304 = V_342 ;
F_4 ( L_35 ) ;
} else if ( V_341 == 1 ) {
V_283 -> V_304 &= ( ~ V_343 ) ;
F_4 ( L_36 ) ;
} else if ( V_341 == 2 ) {
V_283 -> V_304 &= ( ~ V_344 ) ;
} else if ( V_341 == 3 ) {
V_283 -> V_304 &= ( ~ V_345 ) ;
F_4 ( L_37 ) ;
} else if ( V_341 == 4 ) {
V_310 -> V_312 &= ( ~ V_346 ) ;
} else if ( V_341 == 5 ) {
V_283 -> V_304 &= ( ~ V_347 ) ;
} else if ( V_341 == 6 ) {
if ( ! ( V_283 -> V_304 & V_343 ) ) {
T_7 * V_348 = & V_283 -> V_349 ;
V_348 -> V_350 = F_45 ( V_1 , 0xc50 ) ;
}
V_310 -> V_312 |= V_346 ;
V_283 -> V_304 = V_308 ;
F_4 ( L_38 ) ;
}
}
break;
case V_351 :
V_282 -> V_352 = * ( ( T_1 * ) V_323 ) ;
break;
case V_353 :
V_282 -> V_354 = * ( ( T_1 * ) V_323 ) ;
break;
case V_355 :
V_282 -> V_243 = * ( ( T_1 * ) V_323 ) ;
break;
default:
F_60 ( V_318 , L_39 , V_259 , V_280 ) ;
V_324 = V_6 ;
break;
}
return V_324 ;
}
T_1 F_68 (
struct V_1 * V_1 , enum V_322 V_280 , void * V_323
)
{
struct V_4 * V_282 = F_26 ( V_1 ) ;
T_6 * V_283 = & ( V_282 -> V_284 ) ;
T_1 V_324 = V_7 ;
switch ( V_280 ) {
case V_356 :
{
struct V_357 * V_358 ;
struct V_359 * V_360 ;
struct V_261 * V_262 ;
V_358 = & V_1 -> V_361 ;
V_360 = & V_1 -> V_362 ;
V_262 = F_69 ( V_360 , V_358 -> V_363 . V_364 . V_365 ) ;
if ( V_262 )
* ( ( int * ) V_323 ) = V_262 -> V_366 . V_367 ;
}
break;
case V_335 :
* ( ( V_337 * ) V_323 ) = V_283 -> V_326 ;
break;
case V_338 :
* ( ( T_3 * ) V_323 ) = V_283 -> V_368 ;
break;
case V_340 :
* ( ( T_3 * ) V_323 ) = V_282 -> V_284 . V_304 ;
break;
case V_351 :
* ( ( T_1 * ) V_323 ) = V_282 -> V_352 ;
break;
case V_353 :
* ( ( T_1 * ) V_323 ) = V_282 -> V_354 ;
break;
case V_355 :
* ( ( T_1 * ) V_323 ) = V_282 -> V_243 ;
break;
case V_369 :
* ( T_1 * ) V_323 = false ;
break;
case V_370 :
* ( ( T_3 * ) V_323 ) = V_371 ;
break;
default:
F_60 ( V_318 , L_39 , V_259 , V_280 ) ;
V_324 = V_6 ;
break;
}
return V_324 ;
}
void F_70 (
struct V_1 * V_23 ,
enum V_372 V_373 ,
void * V_374 ,
void * V_375
)
{
switch ( V_373 ) {
#if F_71 ( V_376 ) && F_71 ( V_377 )
case V_378 :
{
struct V_4 * V_18 = F_26 ( V_23 ) ;
T_1 V_379 = * ( T_1 * ) V_374 ;
* ( V_380 * ) V_375 = V_18 -> V_381 [ V_379 ] ;
#ifdef F_72
F_4 ( L_40 ,
V_379 , V_18 -> V_381 [ V_379 ] ) ;
#endif
}
break;
#endif
default:
break;
}
}
void F_73 (
struct V_1 * V_23 ,
enum V_372 V_373 ,
void * V_374 ,
bool V_382
)
{
struct V_4 * V_18 = F_26 ( V_23 ) ;
T_8 V_383 = & V_18 -> V_284 ;
switch ( V_373 ) {
case V_384 :
{
struct V_261 * V_262 = (struct V_261 * ) V_374 ;
if ( V_382 ) {
F_4 ( L_41 , V_262 -> V_385 ) ;
F_74 ( V_383 , V_386 , V_262 -> V_385 , V_262 ) ;
} else {
F_4 ( L_42 , V_262 -> V_385 ) ;
F_74 ( V_383 , V_386 , V_262 -> V_385 , NULL ) ;
}
}
break;
case V_387 :
F_67 ( V_383 , V_388 , V_382 ) ;
break;
case V_389 :
F_67 ( V_383 , V_390 , V_382 ) ;
break;
#if F_71 ( V_376 ) && F_71 ( V_377 )
case V_378 :
{
struct V_391 * V_392 = (struct V_391 * ) V_374 ;
#ifdef F_72
F_4 ( L_43 ,
V_392 -> V_379 , V_392 -> V_393 , V_392 -> V_394 , V_392 -> V_395 ) ;
#endif
V_18 -> V_381 [ V_392 -> V_379 ] = F_75 ( V_383 , V_392 -> V_393 , V_392 -> V_394 , V_392 -> V_395 ) ;
F_24 ( L_44 , V_392 -> V_379 , V_18 -> V_381 [ V_392 -> V_379 ] ) ;
#ifdef F_72
F_24 ( L_45 ,
V_383 -> V_396 . V_381 [ V_397 ] ,
V_383 -> V_396 . V_381 [ V_398 ] ,
V_383 -> V_396 . V_399 ) ;
#endif
}
break;
#endif
default:
break;
}
}
bool F_76 ( T_1 * V_400 , T_1 * V_401 , T_3 V_402 )
{
if ( V_402 == 0 )
return false ;
while ( V_402 > 0 ) {
V_402 -- ;
if ( V_400 [ V_402 ] != V_401 [ V_402 ] )
return false ;
}
return true ;
}
bool F_77 ( char V_403 )
{
if (
( V_403 >= '0' && V_403 <= '9' ) ||
( V_403 >= 'a' && V_403 <= 'f' ) ||
( V_403 >= 'A' && V_403 <= 'F' )
)
return true ;
else
return false ;
}
T_3 F_78 ( char V_403 )
{
if ( V_403 >= '0' && V_403 <= '9' )
return ( V_403 - '0' ) ;
else if ( V_403 >= 'a' && V_403 <= 'f' )
return ( 10 + ( V_403 - 'a' ) ) ;
else if ( V_403 >= 'A' && V_403 <= 'F' )
return ( 10 + ( V_403 - 'A' ) ) ;
else
return 0 ;
}
bool F_79 ( char * V_404 , T_3 * V_405 , T_3 * V_406 )
{
char * V_407 = V_404 ;
if ( V_404 == NULL || V_405 == NULL || V_406 == NULL ) {
F_24 ( L_46 ,
V_404 , V_405 , V_406 ) ;
return false ;
}
* V_406 = 0 ;
* V_405 = 0 ;
while ( * V_407 != '\0' && ( * V_407 == ' ' || * V_407 == '\t' ) ) {
V_407 ++ ;
( * V_406 ) ++ ;
}
if ( * V_407 == '0' && ( * ( V_407 + 1 ) == 'x' || * ( V_407 + 1 ) == 'X' ) ) {
V_407 += 2 ;
( * V_406 ) += 2 ;
}
if ( ! F_77 ( * V_407 ) )
return false ;
do {
( * V_405 ) <<= 4 ;
* V_405 += F_78 ( * V_407 ) ;
V_407 ++ ;
( * V_406 ) ++ ;
} while ( F_77 ( * V_407 ) );
return true ;
}
bool F_80 (
char * V_404 , T_1 * V_408 , T_1 * V_409 , T_3 * V_406
)
{
char * V_407 = V_404 ;
* V_406 = 0 ;
* V_408 = 0 ;
* V_409 = 0 ;
while ( * V_407 != '\0' && ( * V_407 == ' ' || * V_407 == '\t' ) ) {
++ V_407 ;
++ ( * V_406 ) ;
}
do {
( * V_408 ) *= 10 ;
* V_408 += ( * V_407 - '0' ) ;
++ V_407 ;
++ ( * V_406 ) ;
if ( * V_407 == '.' ) {
++ V_407 ;
++ ( * V_406 ) ;
if ( * V_407 < '0' || * V_407 > '9' )
return false ;
else {
* V_409 = * V_407 - '0' ;
++ V_407 ;
++ ( * V_406 ) ;
return true ;
}
}
} while ( * V_407 >= '0' && * V_407 <= '9' );
return true ;
}
bool F_81 ( char * V_404 )
{
if ( * V_404 == '/' && * ( V_404 + 1 ) == '/' )
return true ;
else
return false ;
}
bool F_82 ( char * V_410 , T_1 * V_411 )
{
T_4 V_201 = 0 ;
* V_411 = 0 ;
while ( V_410 [ V_201 ] != '\0' ) {
if ( V_410 [ V_201 ] >= '0' && V_410 [ V_201 ] <= '9' ) {
* V_411 *= 10 ;
* V_411 += ( V_410 [ V_201 ] - '0' ) ;
} else
return false ;
++ V_201 ;
}
return true ;
}
bool F_83 (
char * V_412 , T_3 * V_413 , char * V_414 , char V_415 , char V_416
)
{
T_3 V_201 = 0 , V_417 = 0 ;
char V_418 = V_412 [ ( * V_413 ) ++ ] ;
if ( V_418 != V_415 )
return false ;
V_201 = ( * V_413 ) ;
while ( ( V_418 = V_412 [ ( * V_413 ) ++ ] ) != V_416 )
;
V_417 = ( * V_413 ) - 2 ;
strncpy ( ( char * ) V_414 , ( const char * ) ( V_412 + V_201 ) , V_417 - V_201 + 1 ) ;
return true ;
}
bool F_84 ( T_1 * V_419 , T_1 V_420 )
{
T_1 V_9 = 0 , V_421 = 0 ;
while ( V_420 > V_9 ) {
if ( V_419 [ V_9 ] == ' ' || V_419 [ V_9 ] == '\t' || V_419 [ V_9 ] == '\0' )
++ V_421 ;
++ V_9 ;
}
return V_420 == V_421 ;
}
void F_85 ( struct V_1 * V_1 )
{
struct V_230 * V_422 = V_1 -> V_423 ;
struct V_424 * V_425 = & V_422 -> V_426 ;
int V_427 = false ;
F_43 ( V_1 , V_428 + 3 , F_45 ( V_1 , V_428 + 3 ) | 0xf0 ) ;
V_427 = true ;
if ( V_427 ) {
V_425 -> V_429 = V_425 -> V_430 ;
V_425 -> V_430 = F_58 ( V_1 , V_428 ) ;
V_425 -> V_431 = V_425 -> V_430 - V_425 -> V_429 ;
}
}
void F_86 ( struct V_1 * V_2 , T_1 V_432 )
{
struct V_433 * V_434 = F_87 ( V_2 ) ;
if ( V_2 -> V_435 == V_432 )
return;
F_24 ( L_47 , V_259 , ( V_432 ) ? L_48 : L_49 ) ;
if ( V_432 ) {
V_434 -> V_436 = V_434 -> V_437 ;
F_88 ( V_2 , V_438 ) ;
V_434 -> V_439 = V_434 -> V_440 ;
F_89 ( V_2 , V_441 ) ;
} else {
F_89 ( V_2 , V_434 -> V_439 ) ;
F_88 ( V_2 , V_434 -> V_439 ) ;
}
V_2 -> V_435 = V_432 ;
}
void F_90 ( void * V_442 , struct V_1 * V_2 )
{
T_1 V_443 , V_444 ;
struct V_4 * V_18 = F_26 ( V_2 ) ;
struct V_445 * V_446 = & V_2 -> V_447 . V_448 ;
F_91 (
V_442 ,
L_50 ,
F_64 ( V_446 -> V_449 ) ,
V_446 -> V_450 , V_446 -> V_451
) ;
V_443 = ( V_446 -> V_449 <= V_37 ) ? true : false ;
if ( V_443 )
V_446 -> V_452 [ 0 ] = V_446 -> V_450 ;
for ( V_444 = 0 ; V_444 < V_18 -> V_453 ; V_444 ++ ) {
F_91 (
V_442 ,
L_51 ,
V_444 , V_446 -> V_452 [ V_444 ] ,
V_446 -> V_454 [ V_444 ]
) ;
if ( ! V_443 ) {
F_91 (
V_442 ,
L_52 ,
V_446 -> V_455 [ V_444 ] ,
V_446 -> V_456 [ V_444 ]
) ;
}
}
}
void F_66 ( struct V_1 * V_2 )
{
T_1 V_443 , V_444 ;
struct V_4 * V_18 = F_26 ( V_2 ) ;
struct V_445 * V_446 = & V_2 -> V_447 . V_448 ;
F_24 ( L_53 ) ;
F_24 ( L_50 ,
F_64 ( V_446 -> V_449 ) , V_446 -> V_450 , V_446 -> V_451 ) ;
V_443 = ( V_446 -> V_449 <= V_37 ) ? true : false ;
if ( V_443 )
V_446 -> V_452 [ 0 ] = V_446 -> V_450 ;
for ( V_444 = 0 ; V_444 < V_18 -> V_453 ; V_444 ++ ) {
F_24 ( L_54
, V_444 , V_446 -> V_452 [ V_444 ] , V_446 -> V_454 [ V_444 ] ) ;
if ( ! V_443 ) {
F_92 ( L_55 ,
V_446 -> V_455 [ V_444 ] , V_446 -> V_456 [ V_444 ] ) ;
} else {
F_92 ( L_56 ) ;
}
}
}
void F_93 ( struct V_1 * V_2 , union V_457 * V_458 )
{
T_1 V_443 , V_444 ;
struct V_4 * V_18 = F_26 ( V_2 ) ;
struct V_459 * V_460 = & V_458 -> V_461 . V_462 . V_463 ;
T_9 V_464 = ( T_9 ) ( & V_460 -> V_465 ) ;
struct V_445 * V_446 = & V_2 -> V_447 . V_448 ;
V_446 -> V_449 = V_460 -> V_449 ;
V_443 = ( V_460 -> V_449 <= V_37 ) ? true : false ;
V_446 -> V_450 = V_464 -> V_466 ;
V_446 -> V_451 = V_464 -> V_467 ;
for ( V_444 = 0 ; V_444 < V_18 -> V_453 ; V_444 ++ ) {
V_446 -> V_452 [ V_444 ] = V_464 -> V_468 [ V_444 ] ;
V_446 -> V_454 [ V_444 ] = V_464 -> V_469 [ V_444 ] ;
if ( ! V_443 ) {
V_446 -> V_455 [ V_444 ] = V_464 -> V_470 [ V_444 ] ;
V_446 -> V_456 [ V_444 ] = V_464 -> V_471 [ V_444 ] ;
}
}
}
void F_94 ( struct V_1 * V_2 )
{
T_1 V_323 = V_2 -> V_241 . V_472 ;
T_3 V_473 , V_201 = 0 ;
T_3 V_474 = sizeof( V_475 ) / sizeof( T_3 ) ;
T_3 * V_476 = V_475 ;
T_3 V_477 = 0 , V_478 = 0 , V_479 = 0 ;
if ( V_323 & V_480 ) {
F_24 ( L_57 ) ;
F_24 ( L_58 , V_2 -> V_241 . V_481 ) ;
if ( V_2 -> V_241 . V_481 != 0xff ) {
V_473 = F_95 ( V_2 , V_482 , 0x7f , 0xffffffff ) ;
V_473 &= 0xfff87fff ;
F_24 ( L_59 , V_473 ) ;
for ( V_201 = 0 ; V_201 < V_474 ; V_201 += 2 ) {
V_477 = V_476 [ V_201 ] ;
V_478 = V_476 [ V_201 + 1 ] ;
if ( V_477 == V_2 -> V_241 . V_481 ) {
F_24 ( L_60 , V_477 , V_478 ) ;
V_479 = V_478 ;
break;
}
}
F_24 ( L_61 , V_2 -> V_241 . V_481 , V_479 ) ;
F_96 ( V_2 , V_482 , V_483 , V_484 | V_485 | V_486 | V_487 , V_479 ) ;
V_473 = F_95 ( V_2 , V_482 , 0x7f , 0xffffffff ) ;
F_24 ( L_62 , V_473 ) ;
} else
F_24 ( L_63 , V_2 -> V_241 . V_481 ) ;
} else
F_24 ( L_64 ) ;
}
