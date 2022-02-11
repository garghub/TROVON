static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 ;
V_10 = & V_5 -> V_10 ;
if ( V_10 -> V_11 . V_12 . V_13 == V_14 ||
V_10 -> V_11 . V_12 . V_13 == V_15 ||
V_10 -> V_11 . V_12 . V_13 == V_16 ) {
V_4 -> V_17 = V_18 ;
V_4 -> V_19 =
( V_20 | V_21 |
V_22 ) ;
V_4 -> V_23 =
( V_24 | V_25 ) ;
V_4 -> V_26 = V_27 ;
V_4 -> V_28 = V_29 ;
} else {
F_3 ( & V_7 -> V_30 -> V_31 , L_1 ,
V_10 -> V_11 . V_12 . V_13 ) ;
}
if ( V_10 -> V_11 . V_12 . V_32 ) {
F_4 ( V_4 , V_10 -> V_11 . V_12 . V_33 ) ;
V_4 -> V_34 = V_10 -> V_11 . V_12 . V_34 ;
} else {
F_4 ( V_4 , V_35 ) ;
V_4 -> V_34 = V_36 ;
}
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_2 ) ;
V_7 = V_5 -> V_8 ;
memset ( V_38 , 0 , sizeof( struct V_37 ) ) ;
strcpy ( V_38 -> V_39 , L_2 ) ;
strcpy ( V_38 -> V_40 , V_41 ) ;
strncpy ( V_38 -> V_42 , V_7 -> V_43 . V_44 ,
V_45 ) ;
strncpy ( V_38 -> V_46 , F_6 ( V_7 -> V_30 ) , 32 ) ;
}
static void
F_7 ( struct V_1 * V_31 ,
struct V_47 * V_48 )
{
struct V_5 * V_5 = F_2 ( V_31 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_49 = 0 , V_50 = 0 , V_51 = 0 , V_52 = 0 ;
if ( F_8 ( V_7 ) ) {
struct V_53 * V_54 = F_9 ( V_7 , V_55 , V_56 ) ;
V_49 = F_10 ( V_54 ) ;
V_50 = F_11 ( V_54 ) ;
V_52 = F_12 ( V_54 , V_5 -> V_57 ) ;
V_51 = F_13 ( V_54 , V_5 -> V_57 ) ;
}
V_48 -> V_49 = V_49 ;
V_48 -> V_50 = V_50 ;
V_48 -> V_52 = V_52 ;
V_48 -> V_51 = V_51 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_58 [ 128 ] ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_59 * V_60 ;
int V_61 ;
V_60 = (struct V_59 * ) ( & V_8 -> V_62 ) ;
V_61 = sprintf ( V_58 , L_3 ,
V_60 -> V_63 , V_60 -> V_64 ,
V_60 -> V_65 , V_60 -> V_66 ) ;
return V_61 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_67 * V_68 ,
T_2 * V_69 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_59 * V_60 ;
int V_61 ;
if ( V_68 -> V_70 != 0 )
return - V_71 ;
V_68 -> V_72 = V_8 -> V_30 -> V_73 ;
V_60 = (struct V_59 * ) ( & V_8 -> V_62 ) ;
V_61 =
sprintf ( ( char * ) V_69 ,
L_3 ,
V_60 -> V_63 , V_60 -> V_64 ,
V_60 -> V_65 , V_60 -> V_66 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_74 , int V_75 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_76 V_77 ;
int V_78 = 0 ;
memset ( & V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 . V_79 . V_80 = 0 ;
V_77 . V_79 . V_12 . V_81 = V_82 ;
V_77 . V_79 . V_12 . V_83 = V_74 ;
V_77 . V_79 . V_12 . V_84 = V_75 ;
V_77 . V_85 = V_5 -> V_10 . V_86 [ 0 ] . V_12 . V_87 ;
V_77 . V_88 = 100 ;
V_77 . V_89 = ( V_80 ) V_2 ;
V_77 . V_90 = V_91 ;
V_78 = F_17 ( V_5 -> V_8 , & V_77 ) ;
if ( V_78 < 0 ) {
F_3 ( & V_7 -> V_30 -> V_31 , L_4 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_18 ( struct V_6 * V_7 ,
T_1 V_92 ,
void * V_58 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 = (struct V_95 * ) V_58 ;
V_94 = (struct V_93 * ) V_96 -> V_97 ;
V_7 = F_19 ( V_94 -> V_98 ) ;
if ( V_92 ) {
F_3 ( & V_7 -> V_30 -> V_31 , L_5 ,
F_20 ( V_92 ) ) ;
F_21 ( V_94 -> V_99 , - 1 ) ;
} else {
F_21 ( V_94 -> V_99 , 1 ) ;
}
F_22 ( & V_94 -> V_100 ) ;
}
static int
F_23 ( struct V_5 * V_5 , int V_101 , int V_102 , int * V_103 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_95 * V_96 ;
struct V_104 * V_105 ;
struct V_93 * V_94 ;
struct V_106 * V_107 ;
int V_108 = 0 ;
V_96 = (struct V_95 * )
F_24 ( V_8 ,
sizeof( struct V_106 ) ,
sizeof( struct V_104 ) ,
sizeof( struct V_93 ) ) ;
if ( ! V_96 )
return - V_109 ;
V_94 = (struct V_93 * ) V_96 -> V_97 ;
V_105 = (struct V_104 * ) V_96 -> V_110 ;
V_107 = (struct V_106 * ) V_96 -> V_111 ;
F_21 ( V_94 -> V_99 , 0 ) ;
V_94 -> V_98 = F_25 ( V_8 ) ;
V_107 -> V_101 = V_101 ;
V_107 -> V_112 = V_102 ;
if ( V_101 )
V_107 -> V_113 = * V_103 ;
F_26 ( ( V_80 * ) V_107 , sizeof( struct V_106 ) / 8 ) ;
V_96 -> V_85 = V_5 -> V_10 . V_86 [ 0 ] . V_12 . V_87 ;
F_27 ( V_8 , V_96 , V_114 , V_115 ,
0 , 0 , 0 ) ;
V_96 -> V_88 = 1000 ;
V_96 -> V_116 = F_18 ;
V_96 -> V_117 = V_96 ;
F_28 ( & V_94 -> V_100 ) ;
V_108 = F_29 ( V_8 , V_96 ) ;
if ( V_108 == V_118 ) {
F_3 ( & V_8 -> V_30 -> V_31 ,
L_6 ,
V_108 ) ;
V_108 = - V_119 ;
} else {
F_30 ( & V_94 -> V_100 , & V_94 -> V_99 ) ;
V_108 = V_105 -> V_92 ;
if ( V_108 ) {
F_3 ( & V_8 -> V_30 -> V_31 , L_7 ) ;
V_108 = - V_119 ;
} else {
F_26 ( ( V_80 * ) ( & V_105 -> V_120 ) ,
sizeof( struct V_106 ) / 8 ) ;
if ( F_31 ( V_94 -> V_99 ) == 1 ) {
if ( ! V_101 )
* V_103 = V_105 -> V_120 . V_113 ;
} else {
V_108 = - V_71 ;
}
}
}
F_32 ( V_8 , V_96 ) ;
return V_108 ;
}
static int F_33 ( struct V_1 * V_2 ,
enum V_121 V_122 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_103 , V_78 ;
switch ( V_122 ) {
case V_123 :
if ( V_7 -> V_124 == V_125 ) {
F_16 ( V_2 , V_126 ,
V_127 ) ;
return 2 ;
} else if ( V_7 -> V_124 == V_128 ) {
V_78 = F_23 ( V_5 , 0 ,
V_129 ,
& V_5 -> V_130 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_23 ( V_5 , 0 ,
V_131 ,
& V_5 -> V_132 ) ;
if ( V_78 )
return V_78 ;
V_103 = V_133 ;
V_78 = F_23 ( V_5 , 1 ,
V_129 ,
& V_103 ) ;
if ( V_78 )
return V_78 ;
V_103 = V_134 ;
V_78 = F_23 ( V_5 , 1 ,
V_131 ,
& V_103 ) ;
if ( V_78 )
return V_78 ;
} else {
return - V_71 ;
}
break;
case V_135 :
if ( V_7 -> V_124 == V_125 ) {
F_16 ( V_2 , V_126 ,
V_136 ) ;
} else if ( V_7 -> V_124 == V_128 ) {
return - V_71 ;
} else {
return - V_71 ;
}
break;
case V_137 :
if ( V_7 -> V_124 == V_125 )
F_16 ( V_2 , V_126 ,
V_138 ) ;
else if ( V_7 -> V_124 == V_128 )
return - V_71 ;
else
return - V_71 ;
break;
case V_139 :
if ( V_7 -> V_124 == V_125 ) {
F_16 ( V_2 , V_126 ,
V_140 ) ;
} else if ( V_7 -> V_124 == V_128 ) {
V_78 = F_23 ( V_5 , 1 ,
V_131 ,
& V_5 -> V_132 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_23 ( V_5 , 1 ,
V_129 ,
& V_5 -> V_130 ) ;
if ( V_78 )
return V_78 ;
} else {
return - V_71 ;
}
break;
default:
return - V_71 ;
}
return 0 ;
}
static void
F_34 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_143 = 0 , V_144 = 0 , V_145 = 0 ,
V_146 = 0 ;
if ( F_8 ( V_7 ) ) {
struct V_53 * V_54 = F_9 ( V_7 , V_55 , V_56 ) ;
V_143 = V_147 ;
V_144 = V_148 ;
V_146 = F_35 ( V_54 , V_5 -> V_57 ) ;
V_145 = F_36 ( V_54 , V_5 -> V_57 ) ;
}
if ( V_5 -> V_149 > V_150 - V_151 ) {
V_142 -> V_146 = 0 ;
V_142 -> V_144 = 0 ;
V_142 -> V_152 = 0 ;
V_142 -> V_153 = V_146 ;
V_142 -> V_154 = 0 ;
V_142 -> V_155 = V_144 ;
} else {
V_142 -> V_146 = V_146 ;
V_142 -> V_144 = V_144 ;
V_142 -> V_152 = 0 ;
V_142 -> V_153 = 0 ;
V_142 -> V_154 = 0 ;
V_142 -> V_155 = 0 ;
}
V_142 -> V_145 = V_145 ;
V_142 -> V_143 = V_143 ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_156 ;
}
static void F_38 ( struct V_1 * V_2 , T_1 V_157 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( ( V_157 ^ V_5 -> V_156 ) & V_158 ) {
if ( V_157 & V_158 )
F_39 ( V_2 ,
V_159 , 0 ) ;
else
F_39 ( V_2 ,
V_160 , 0 ) ;
}
V_5 -> V_156 = V_157 ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
V_162 -> V_28 = 0 ;
V_162 -> V_163 = V_7 -> V_163 ;
V_162 -> V_164 = V_7 -> V_164 ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_165 , T_2 * V_166 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
int V_167 , V_168 , V_169 , V_170 ;
int V_171 ;
switch ( V_165 ) {
case V_172 :
V_171 = F_42 ( V_173 ) ;
for ( V_170 = 0 ; V_170 < V_171 ; V_170 ++ ) {
sprintf ( V_166 , L_8 , V_173 [ V_170 ] ) ;
V_166 += V_174 ;
}
V_167 = F_42 ( V_175 ) ;
for ( V_169 = 0 ; V_169 < F_43 ( V_8 ) ; V_169 ++ ) {
if ( ! ( V_8 -> V_176 . V_177 & ( 1ULL << V_169 ) ) )
continue;
for ( V_170 = 0 ; V_170 < V_167 ; V_170 ++ ) {
sprintf ( V_166 , L_9 , V_169 ,
V_175 [ V_170 ] ) ;
V_166 += V_174 ;
}
}
V_168 = F_42 ( V_178 ) ;
for ( V_169 = 0 ; V_169 < F_44 ( V_8 ) ; V_169 ++ ) {
if ( ! ( V_8 -> V_176 . V_179 & ( 1ULL << V_169 ) ) )
continue;
for ( V_170 = 0 ; V_170 < V_168 ; V_170 ++ ) {
sprintf ( V_166 , L_10 , V_169 ,
V_178 [ V_170 ] ) ;
V_166 += V_174 ;
}
}
break;
default:
F_45 ( V_5 , V_180 , V_5 -> V_2 , L_11 ) ;
break;
}
}
static int F_46 ( struct V_1 * V_2 , int V_181 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
switch ( V_181 ) {
case V_172 :
return ( F_42 ( V_173 ) +
F_42 ( V_175 ) * V_8 -> V_182 +
F_42 ( V_178 ) * V_8 -> V_183 ) ;
default:
return - V_184 ;
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_187 * V_177 ;
struct V_188 * V_189 ;
V_189 = & V_7 -> V_190 ;
switch ( V_7 -> V_124 ) {
case V_128 :
case V_125 : {
struct V_191 * V_55 =
(struct V_191 * ) V_7 -> V_192 ;
if ( ! V_189 -> V_193 ) {
V_186 -> V_194 =
F_48 ( V_55 -> V_56 ) ;
V_186 -> V_195 =
F_49 ( V_55 -> V_56 ) ;
}
V_177 = V_7 -> V_196 [ V_5 -> V_10 . V_86 [ 0 ] . V_12 . V_87 ] ;
V_186 -> V_197 = V_177 -> V_198 ;
break;
}
default:
F_45 ( V_5 , V_180 , V_5 -> V_2 , L_12 ) ;
return - V_71 ;
}
if ( V_189 -> V_193 ) {
V_186 -> V_199 =
V_189 -> V_193 ;
V_186 -> V_200 =
V_189 -> V_201 ;
V_186 -> V_202 =
V_189 -> V_203 ;
V_186 -> V_204 =
V_189 -> V_205 ;
V_186 -> V_206 =
V_189 -> V_207 ;
V_186 -> V_208 =
V_189 -> V_209 ;
V_186 -> V_210 =
V_189 -> V_211 ;
V_186 -> V_212 =
V_189 -> V_213 ;
}
return 0 ;
}
static void F_50 ( struct V_6 * V_8 ,
T_1 V_92 ,
void * V_214 )
{
struct V_215 * V_81 = V_214 ;
struct V_95 * V_96 = V_81 -> V_96 ;
V_8 = V_81 -> V_8 ;
if ( V_92 )
F_3 ( & V_8 -> V_30 -> V_31 , L_13 ,
F_20 ( V_92 ) ) ;
else
F_51 ( & V_8 -> V_30 -> V_31 ,
L_14 ,
V_8 -> V_190 . V_193 ) ;
F_32 ( V_8 , V_96 ) ;
}
static int F_52 ( struct V_5 * V_5 ,
struct V_188 * V_216 )
{
struct V_95 * V_96 ;
struct V_215 * V_81 ;
struct V_188 * V_217 ;
int V_108 ;
struct V_6 * V_8 = V_5 -> V_8 ;
V_96 = (struct V_95 * )
F_24 ( V_8 ,
sizeof( struct V_188 ) ,
0 ,
sizeof( struct V_215 ) ) ;
if ( ! V_96 )
return - V_109 ;
V_81 = (struct V_215 * ) V_96 -> V_97 ;
V_217 = (struct V_188 * ) V_96 -> V_111 ;
memcpy ( V_217 , V_216 , sizeof( struct V_188 ) ) ;
F_26 ( ( V_80 * ) V_217 , ( sizeof( struct V_188 ) ) / 8 ) ;
V_81 -> V_96 = V_96 ;
V_81 -> V_217 = V_217 ;
V_81 -> V_8 = V_8 ;
V_96 -> V_85 = V_5 -> V_10 . V_86 [ 0 ] . V_12 . V_87 ;
F_27 ( V_8 , V_96 , V_114 ,
V_218 , 0 , 0 , 0 ) ;
V_96 -> V_116 = F_50 ;
V_96 -> V_117 = V_81 ;
V_96 -> V_88 = 1000 ;
V_108 = F_29 ( V_8 , V_96 ) ;
if ( V_108 == V_118 ) {
F_32 ( V_8 , V_96 ) ;
return - V_71 ;
}
return 0 ;
}
static void
F_53 ( struct V_6 * V_8 ,
T_1 V_92 , void * V_214 )
{
struct V_95 * V_96 = (struct V_95 * ) V_214 ;
struct V_219 * V_120 = (struct V_219 * )
V_96 -> V_110 ;
struct V_220 * V_221 = (struct V_220 * )
V_96 -> V_97 ;
struct V_222 * V_223 = & V_120 -> V_224 . V_225 ;
struct V_226 * V_227 = & V_120 -> V_224 . V_228 ;
struct V_222 * V_229 = & V_8 -> V_230 . V_225 ;
struct V_226 * V_231 = & V_8 -> V_230 . V_228 ;
if ( ( V_92 != V_232 ) && ! V_120 -> V_92 ) {
F_26 ( ( V_80 * ) & V_120 -> V_224 ,
( sizeof( struct V_233 ) ) >> 3 ) ;
V_229 -> V_234 = V_223 -> V_234 ;
V_229 -> V_235 = V_223 -> V_235 ;
V_229 -> V_236 = V_223 -> V_236 ;
V_229 -> V_237 = V_223 -> V_237 ;
V_229 -> V_238 = V_223 -> V_238 ;
V_229 -> V_239 = V_223 -> V_239 ;
V_229 -> V_240 = V_223 -> V_240 ;
V_229 -> V_241 = V_223 -> V_241 ;
V_229 -> V_242 = V_223 -> V_242 ;
V_229 -> V_243 = V_223 -> V_243 ;
V_229 -> V_244 = V_223 -> V_244 ;
V_229 -> V_245 = V_223 -> V_245 ;
V_229 -> V_246 = V_223 -> V_246 ;
V_229 -> V_247 = V_223 -> V_247 ;
V_229 -> V_248 = V_223 -> V_248 ;
V_229 -> V_249 = V_223 -> V_249 ;
V_229 -> V_250 = V_223 -> V_250 ;
V_229 -> V_251 = V_223 -> V_251 ;
V_229 -> V_252 = V_223 -> V_252 ;
V_229 -> V_253 = V_223 -> V_253 ;
V_229 -> V_254 = V_223 -> V_254 ;
V_229 -> V_255 = V_223 -> V_255 ;
V_229 -> V_256 = V_223 -> V_256 ;
V_229 -> V_257 = V_223 -> V_257 ;
V_229 -> V_258 = V_223 -> V_258 ;
V_229 -> V_259 = V_223 -> V_259 ;
V_229 -> V_260 = V_223 -> V_260 ;
V_229 -> V_261 = V_223 -> V_261 ;
V_231 -> V_262 = V_227 -> V_262 ;
V_231 -> V_263 = V_227 -> V_263 ;
V_231 -> V_264 = V_227 -> V_264 ;
V_231 -> V_265 = V_227 -> V_265 ;
V_231 -> V_266 = V_227 -> V_266 ;
V_231 -> V_267 = V_227 -> V_267 ;
V_231 -> V_268 = V_227 -> V_268 ;
V_231 -> V_269 = V_227 -> V_269 ;
V_231 -> V_270 = V_227 -> V_270 ;
V_231 -> V_240 = V_227 -> V_240 ;
V_231 -> V_238 = V_227 -> V_238 ;
V_231 -> V_271 = V_227 -> V_271 ;
V_231 -> V_272 = V_227 -> V_272 ;
V_231 -> V_247 = V_227 -> V_247 ;
V_231 -> V_248 = V_227 -> V_248 ;
V_231 -> V_249 = V_227 -> V_249 ;
V_231 -> V_250 = V_227 -> V_250 ;
V_231 -> V_273 = V_227 -> V_273 ;
V_231 -> V_274 = V_227 -> V_274 ;
V_231 -> V_275 = V_227 -> V_275 ;
V_231 -> V_276 = V_227 -> V_276 ;
V_120 -> V_92 = 1 ;
} else {
V_120 -> V_92 = - 1 ;
}
F_54 ( & V_221 -> F_54 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_95 * V_96 ;
struct V_220 * V_221 ;
struct V_219 * V_120 ;
int V_108 ;
V_96 = (struct V_95 * )
F_24 ( V_8 ,
0 ,
sizeof( struct V_219 ) ,
sizeof( struct V_76 ) ) ;
if ( ! V_96 )
return - V_109 ;
V_120 = (struct V_219 * ) V_96 -> V_110 ;
memset ( V_120 , 0 , sizeof( struct V_219 ) ) ;
V_221 = (struct V_220 * ) V_96 -> V_97 ;
memset ( V_221 , 0 , sizeof( struct V_220 ) ) ;
V_221 -> V_2 = V_2 ;
F_56 ( & V_221 -> F_54 ) ;
V_96 -> V_85 = V_5 -> V_10 . V_86 [ 0 ] . V_12 . V_87 ;
F_27 ( V_8 , V_96 , V_114 ,
V_277 , 0 , 0 , 0 ) ;
V_96 -> V_116 = F_53 ;
V_96 -> V_117 = V_96 ;
V_96 -> V_88 = 500 ;
V_108 = F_29 ( V_8 , V_96 ) ;
if ( V_108 == V_118 ) {
F_32 ( V_8 , V_96 ) ;
return - V_71 ;
}
F_57 ( & V_221 -> F_54 , F_58 ( 1000 ) ) ;
if ( V_120 -> V_92 != 1 ) {
F_32 ( V_8 , V_96 ) ;
return - V_71 ;
}
F_32 ( V_8 , V_96 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_5 , struct V_185
* V_186 )
{
int V_78 = 0 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_188 * V_189 ;
V_189 = & V_7 -> V_190 ;
if ( V_7 -> V_190 . V_193 || V_7 -> V_190 . V_278 ) {
if ( V_186 -> V_200 )
V_189 -> V_201 =
V_186 -> V_200 ;
else
V_189 -> V_201 =
V_279 ;
if ( V_186 -> V_202 )
V_189 -> V_203 =
V_186 -> V_202 ;
else
V_189 -> V_203 =
V_280 ;
if ( V_186 -> V_204 )
V_189 -> V_205 =
V_186 -> V_204 ;
else
V_189 -> V_205 =
V_281 ;
}
if ( V_7 -> V_190 . V_193 ) {
if ( V_186 -> V_206 )
V_189 -> V_207 =
V_186 -> V_206 ;
else
V_189 -> V_207 =
V_282 ;
if ( V_186 -> V_208 )
V_189 -> V_209 =
V_186 -> V_208 ;
else
V_189 -> V_209 =
V_283 ;
if ( V_186 -> V_210 )
V_189 -> V_211 =
V_186 -> V_210 ;
else
V_189 -> V_211 =
V_284 ;
if ( V_186 -> V_212 )
V_189 -> V_213 =
V_186 -> V_212 ;
else
V_189 -> V_213 =
V_285 ;
}
if ( V_7 -> V_190 . V_278 ) {
if ( V_186 -> V_286 )
V_189 -> V_287 =
V_186 -> V_286 ;
else
V_189 -> V_287 =
V_288 ;
if ( V_186 -> V_289 )
V_189 -> V_290 =
V_186 -> V_289 ;
else
V_189 -> V_290 =
V_291 ;
}
V_78 = F_52 ( V_5 , V_189 ) ;
return V_78 ;
}
static int
F_60 ( struct V_5 * V_5 , struct V_185 * V_186 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_195 ;
switch ( V_7 -> V_124 ) {
case V_128 :
case V_125 : {
struct V_191 * V_55 =
(struct V_191 * ) V_7 -> V_192 ;
if ( ! V_186 -> V_195 )
V_195 = V_292 ;
else
V_195 =
V_186 -> V_195 ;
F_61 ( V_7 , V_293 ,
V_195 ) ;
F_62 ( V_55 -> V_56 , V_195 ) ;
break;
}
default:
return - V_71 ;
}
return 0 ;
}
static int F_63 ( struct V_5 * V_5 , struct V_185
* V_186 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_294 , V_194 ;
switch ( V_7 -> V_124 ) {
case V_128 :
case V_125 : {
struct V_191 * V_55 =
(struct V_191 * ) V_7 -> V_192 ;
if ( ! V_186 -> V_194 )
V_194 = V_295 ;
else
V_194 = V_186 -> V_194 ;
V_294 = F_64 ( V_7 ,
V_194 ) ;
F_61 ( V_7 ,
V_296 ,
V_294 ) ;
F_65 ( V_55 -> V_56 , V_194 ) ;
break;
}
default:
return - V_71 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_78 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_170 , V_87 ;
int V_297 , V_298 ;
switch ( V_7 -> V_124 ) {
case V_128 :
case V_125 :
V_298 = V_299 ;
V_297 = V_300 ;
if ( ( V_186 -> V_197 >= V_298 ) &&
( V_186 -> V_197 <= V_297 ) ) {
for ( V_170 = 0 ; V_170 < V_5 -> V_10 . V_301 ; V_170 ++ ) {
V_87 = V_5 -> V_10 . V_86 [ V_170 ] . V_12 . V_87 ;
V_7 -> V_196 [ V_87 ] -> V_198 =
V_186 -> V_197 ;
}
} else {
F_3 ( & V_7 -> V_30 -> V_31 ,
L_15 ,
V_186 -> V_197 , V_298 ,
V_297 ) ;
return - V_71 ;
}
break;
default:
return - V_71 ;
}
V_7 -> V_190 . V_193 = V_186 -> V_199 ? 1 : 0 ;
V_7 -> V_190 . V_278 = V_186 -> V_302 ? 1 : 0 ;
V_78 = F_59 ( V_5 , V_186 ) ;
if ( ! V_186 -> V_199 ) {
V_78 = F_63 ( V_5 , V_186 ) ;
if ( V_78 )
goto V_303;
V_78 = F_60 ( V_5 , V_186 ) ;
if ( V_78 )
goto V_303;
}
if ( ! V_186 -> V_302 ) {
V_78 = F_67 ( V_5 , V_186 ) ;
if ( V_78 )
goto V_303;
}
return 0 ;
V_303:
return V_78 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_304 * V_305 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_305 -> V_306 =
#ifdef F_69
V_307 |
V_308 |
V_309 |
V_310 |
#endif
V_311 |
V_312 ;
if ( V_5 -> V_313 )
V_305 -> V_314 = F_70 ( V_5 -> V_313 ) ;
else
V_305 -> V_314 = - 1 ;
#ifdef F_69
V_305 -> V_315 = ( 1 << V_316 ) | ( 1 << V_317 ) ;
V_305 -> V_318 = ( 1 << V_319 ) |
( 1 << V_320 ) |
( 1 << V_321 ) |
( 1 << V_322 ) ;
#endif
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 ;
struct V_76 V_77 ;
int V_78 = 0 ;
V_10 = & V_5 -> V_10 ;
if ( V_4 -> V_28 != V_323 && V_4 -> V_28 != V_29 )
return - V_71 ;
if ( V_4 -> V_28 == V_29 && ( ( V_4 -> V_33 != V_324 &&
V_4 -> V_33 != V_325 ) ||
( V_4 -> V_34 != V_326 &&
V_4 -> V_34 != V_327 ) ) )
return - V_71 ;
if ( V_10 -> V_11 . V_12 . V_13 == V_14 ||
V_10 -> V_11 . V_12 . V_13 == V_15 ||
V_10 -> V_11 . V_12 . V_13 == V_16 ) {
F_51 ( & V_7 -> V_30 -> V_31 ,
L_16 ) ;
return - V_71 ;
}
memset ( & V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 . V_79 . V_80 = 0 ;
V_77 . V_79 . V_12 . V_81 = V_328 ;
V_77 . V_85 = V_5 -> V_10 . V_86 [ 0 ] . V_12 . V_87 ;
V_77 . V_88 = 1000 ;
V_77 . V_89 = ( V_80 ) V_2 ;
V_77 . V_90 = V_91 ;
if ( V_4 -> V_28 == V_323 ) {
V_77 . V_79 . V_12 . V_329 = V_330 |
V_331 ;
V_77 . V_79 . V_12 . V_83 = V_4 -> V_23 ;
} else {
V_77 . V_79 . V_12 . V_329 = V_330 ;
V_77 . V_79 . V_12 . V_84 = V_4 -> V_34 ;
V_77 . V_79 . V_12 . V_83 = V_4 -> V_33 ;
}
V_78 = F_17 ( V_5 -> V_8 , & V_77 ) ;
if ( V_78 < 0 ) {
F_3 ( & V_7 -> V_30 -> V_31 , L_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
if ( F_73 ( V_2 ) ) {
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_28 = 0 ;
V_4 . V_33 = 0 ;
V_4 . V_34 = 0 ;
F_71 ( V_2 , & V_4 ) ;
}
return 0 ;
}
static int F_74 ( char * V_12 , struct V_6 * V_7 )
{
T_1 V_332 ;
int V_169 , V_61 = 0 ;
V_61 += sprintf ( V_12 + V_61 , L_18 ) ;
V_332 = V_333 ;
V_61 += sprintf ( V_12 + V_61 , L_19 ,
V_333 , F_75 ( V_7 , V_332 ) ) ;
V_332 = V_334 ;
V_61 += sprintf ( V_12 + V_61 , L_20 ,
V_334 , F_75 ( V_7 , V_332 ) ) ;
V_332 = V_335 ;
V_61 += sprintf ( V_12 + V_61 , L_21 ,
V_335 , F_75 ( V_7 , V_332 ) ) ;
V_332 = V_336 ;
V_61 += sprintf ( V_12 + V_61 , L_22 ,
V_336 , F_75 ( V_7 , V_332 ) ) ;
V_332 = V_337 ;
V_61 += sprintf ( V_12 + V_61 , L_23 ,
V_337 , F_75 ( V_7 , V_332 ) ) ;
V_332 = V_338 ;
V_61 += sprintf ( V_12 + V_61 , L_24 ,
V_338 , F_75 ( V_7 , V_332 ) ) ;
V_61 += sprintf ( V_12 + V_61 , L_25 ,
V_339 ,
F_75 ( V_7 , V_339 ) ) ;
V_61 += sprintf ( V_12 + V_61 , L_26 ,
V_340 , F_75 ( V_7 ,
V_340 ) ) ;
V_61 += sprintf ( V_12 + V_61 , L_27 ,
V_341 ,
F_75 ( V_7 , V_341 ) ) ;
V_61 += sprintf ( V_12 + V_61 , L_28 , V_342 ,
F_75 ( V_7 , V_342 ) ) ;
for ( V_169 = 0 ; V_169 < V_7 -> V_183 ; V_169 ++ ) {
V_332 = F_76 ( V_169 ) ;
V_61 += sprintf ( V_12 + V_61 , L_29 ,
V_332 , V_169 , F_75 ( V_7 , V_332 ) ) ;
V_332 = F_77 ( V_169 ) ;
V_61 += sprintf ( V_12 + V_61 , L_30 ,
V_332 , V_169 , F_75 ( V_7 , V_332 ) ) ;
}
V_332 = V_293 ;
V_61 += sprintf ( V_12 + V_61 , L_31 ,
V_332 , F_75 ( V_7 , V_332 ) ) ;
V_332 = V_296 ;
V_61 += sprintf ( V_12 + V_61 , L_32 ,
V_332 , F_75 ( V_7 , V_332 ) ) ;
for ( V_169 = 0 ; V_169 <= 3 ; V_169 ++ ) {
T_1 V_332 ;
V_332 = F_78 ( V_169 ) ;
V_61 += sprintf ( V_12 + V_61 , L_33 ,
V_332 , V_169 , F_75 ( V_7 , V_332 ) ) ;
V_332 = F_79 ( V_169 ) ;
V_61 += sprintf ( V_12 + V_61 , L_34 ,
V_332 , V_169 , F_75 ( V_7 , V_332 ) ) ;
}
V_61 += sprintf ( V_12 + V_61 , L_35 ,
F_80 ( 0 ) ,
F_75 ( V_7 , F_80 ( 0 ) ) ) ;
V_332 = F_81 ( 0 ) ;
V_61 += sprintf ( V_12 + V_61 , L_36 ,
F_81 ( 0 ) , F_75 ( V_7 , V_332 ) ) ;
V_332 = F_82 ( 0 ) ;
V_61 += sprintf ( V_12 + V_61 , L_37 ,
F_82 ( 0 ) ,
F_75 ( V_7 , V_332 ) ) ;
V_61 += sprintf ( V_12 + V_61 , L_38 ,
F_80 ( 1 ) ,
F_75 ( V_7 , F_80 ( 1 ) ) ) ;
V_332 = F_81 ( 1 ) ;
V_61 += sprintf ( V_12 + V_61 , L_39 ,
F_81 ( 1 ) ,
F_75 ( V_7 , V_332 ) ) ;
V_332 = F_81 ( 1 ) ;
V_61 += sprintf ( V_12 + V_61 , L_40 ,
F_82 ( 1 ) ,
F_75 ( V_7 , V_332 ) ) ;
V_61 += sprintf ( V_12 + V_61 , L_41 ) ;
for ( V_169 = 0 ; V_169 < 16 ; V_169 ++ ) {
V_332 = F_83 ( V_7 , F_84 ( V_169 , V_7 -> V_343 ) ) ;
V_61 += sprintf ( V_12 + V_61 , L_42 ,
F_84 ( V_169 , V_7 -> V_343 ) , V_169 , V_332 ) ;
}
return V_61 ;
}
static int F_85 ( char * V_12 , struct V_6 * V_7 )
{
T_1 V_75 ;
int V_169 , V_61 = 0 ;
V_61 += sprintf ( V_12 + V_61 ,
L_43 ) ;
for ( V_169 = 0 ; V_169 <= 13 ; V_169 ++ ) {
F_86 ( V_7 -> V_30 , ( V_169 * 4 ) , & V_75 ) ;
V_61 += sprintf ( V_12 + V_61 , L_44 ,
( V_169 * 4 ) , V_169 , V_75 ) ;
}
for ( V_169 = 30 ; V_169 <= 34 ; V_169 ++ ) {
F_86 ( V_7 -> V_30 , ( V_169 * 4 ) , & V_75 ) ;
V_61 += sprintf ( V_12 + V_61 , L_44 ,
( V_169 * 4 ) , V_169 , V_75 ) ;
}
return V_61 ;
}
static void F_87 ( struct V_1 * V_31 ,
struct V_344 * V_345 , void * V_346 )
{
struct V_5 * V_5 = F_2 ( V_31 ) ;
int V_61 = 0 ;
struct V_6 * V_7 = V_5 -> V_8 ;
V_345 -> V_40 = V_347 ;
switch ( V_7 -> V_124 ) {
case V_128 :
case V_125 :
memset ( V_346 , 0 , V_348 ) ;
V_61 += F_74 ( V_346 + V_61 , V_7 ) ;
V_61 += F_85 ( V_346 + V_61 , V_7 ) ;
break;
default:
F_3 ( & V_7 -> V_30 -> V_31 , L_45 ,
V_349 , V_7 -> V_124 ) ;
}
}
static T_1 F_88 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_8 -> V_350 ;
}
static int F_89 ( struct V_1 * V_2 , T_1 V_351 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
bool V_352 = ! ! ( V_351 & ( 0x1 << V_353 ) ) ;
F_90 ( V_5 -> V_8 , V_353 ,
V_352 ) ;
return 0 ;
}
void F_91 ( struct V_1 * V_2 )
{
V_2 -> V_354 = & V_355 ;
}
