static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return F_2 ( - V_6 ) ;
}
static int F_3 ( struct V_1 * V_7 )
{
return - V_6 ;
}
static int F_4 ( struct V_8 * V_9 , union V_10 * V_11 , T_1 V_12 )
{
return - V_6 ;
}
static int F_5 ( struct V_8 * V_9 , union V_10 * V_11 , T_1 V_12 )
{
return - V_6 ;
}
static int F_6 ( struct V_13 * V_14 , int V_15 ,
T_2 V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_21 * V_23 )
{
return - V_6 ;
}
static int F_7 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_8 ( V_25 -> V_28 ) ;
struct V_29 * V_30 = F_9 ( V_25 ) ;
struct V_31 * V_32 , * V_33 ;
F_10 ( L_1 , V_34 , V_25 ) ;
F_11 (mm, tmp, &ucontext->mmaps, entry)
F_12 ( V_32 ) ;
F_13 ( & V_27 -> V_35 , & V_30 -> V_36 ) ;
F_12 ( V_30 ) ;
return 0 ;
}
static struct V_24 * F_14 ( struct V_13 * V_14 ,
struct V_37 * V_38 )
{
struct V_29 * V_25 ;
struct V_26 * V_27 = F_8 ( V_14 ) ;
F_10 ( L_2 , V_34 , V_14 ) ;
V_25 = F_15 ( sizeof( * V_25 ) , V_39 ) ;
if ( ! V_25 )
return F_2 ( - V_40 ) ;
F_16 ( & V_27 -> V_35 , & V_25 -> V_36 ) ;
F_17 ( & V_25 -> V_41 ) ;
F_18 ( & V_25 -> V_42 ) ;
return & V_25 -> V_43 ;
}
static int F_19 ( struct V_24 * V_25 , struct V_44 * V_45 )
{
int V_46 = V_45 -> V_47 - V_45 -> V_48 ;
T_3 V_49 = V_45 -> V_50 << V_51 ;
struct V_52 * V_35 ;
int V_53 = 0 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
T_4 V_54 ;
F_10 ( L_3 , V_34 , V_45 -> V_50 ,
V_49 , V_46 ) ;
if ( V_45 -> V_48 & ( V_55 - 1 ) )
return - V_56 ;
V_35 = & ( F_8 ( V_25 -> V_28 ) -> V_35 ) ;
V_30 = F_9 ( V_25 ) ;
V_32 = F_20 ( V_30 , V_49 , V_46 ) ;
if ( ! V_32 )
return - V_56 ;
V_54 = V_32 -> V_54 ;
F_12 ( V_32 ) ;
if ( ( V_54 >= F_21 ( V_35 -> V_57 . V_58 , 0 ) ) &&
( V_54 < ( F_21 ( V_35 -> V_57 . V_58 , 0 ) +
F_22 ( V_35 -> V_57 . V_58 , 0 ) ) ) ) {
V_45 -> V_59 = F_23 ( V_45 -> V_59 ) ;
V_53 = F_24 ( V_45 , V_45 -> V_48 ,
V_54 >> V_51 ,
V_46 , V_45 -> V_59 ) ;
} else if ( ( V_54 >= F_21 ( V_35 -> V_57 . V_58 , 2 ) ) &&
( V_54 < ( F_21 ( V_35 -> V_57 . V_58 , 2 ) +
F_22 ( V_35 -> V_57 . V_58 , 2 ) ) ) ) {
if ( V_54 >= V_35 -> V_60 )
V_45 -> V_59 = F_25 ( V_45 -> V_59 ) ;
else
V_45 -> V_59 = F_23 ( V_45 -> V_59 ) ;
V_53 = F_24 ( V_45 , V_45 -> V_48 ,
V_54 >> V_51 ,
V_46 , V_45 -> V_59 ) ;
} else {
V_53 = F_26 ( V_45 , V_45 -> V_48 ,
V_54 >> V_51 ,
V_46 , V_45 -> V_59 ) ;
}
return V_53 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_26 * V_27 ;
struct V_61 * V_62 ;
V_62 = F_28 ( V_3 ) ;
V_27 = V_62 -> V_27 ;
F_10 ( L_4 , V_34 , V_3 , V_62 -> V_63 ) ;
F_29 ( & V_27 -> V_35 . V_64 . V_65 , V_62 -> V_63 ) ;
F_30 ( & V_27 -> V_35 . V_66 . V_67 ) ;
V_27 -> V_35 . V_66 . V_3 . V_68 -- ;
F_31 ( & V_27 -> V_35 . V_66 . V_67 ) ;
F_12 ( V_62 ) ;
return 0 ;
}
static struct V_2 * F_32 ( struct V_13 * V_14 ,
struct V_24 * V_25 ,
struct V_37 * V_38 )
{
struct V_61 * V_62 ;
T_3 V_63 ;
struct V_26 * V_27 ;
F_10 ( L_2 , V_34 , V_14 ) ;
V_27 = (struct V_26 * ) V_14 ;
V_63 = F_33 ( & V_27 -> V_35 . V_64 . V_65 ) ;
if ( ! V_63 )
return F_2 ( - V_56 ) ;
V_62 = F_15 ( sizeof( * V_62 ) , V_39 ) ;
if ( ! V_62 ) {
F_29 ( & V_27 -> V_35 . V_64 . V_65 , V_63 ) ;
return F_2 ( - V_40 ) ;
}
V_62 -> V_63 = V_63 ;
V_62 -> V_27 = V_27 ;
if ( V_25 ) {
if ( F_34 ( V_38 , & V_62 -> V_63 , sizeof( T_3 ) ) ) {
F_27 ( & V_62 -> V_69 ) ;
return F_2 ( - V_70 ) ;
}
}
F_30 ( & V_27 -> V_35 . V_66 . V_67 ) ;
V_27 -> V_35 . V_66 . V_3 . V_68 ++ ;
if ( V_27 -> V_35 . V_66 . V_3 . V_68 > V_27 -> V_35 . V_66 . V_3 . V_71 )
V_27 -> V_35 . V_66 . V_3 . V_71 = V_27 -> V_35 . V_66 . V_3 . V_68 ;
F_31 ( & V_27 -> V_35 . V_66 . V_67 ) ;
F_10 ( L_5 , V_34 , V_63 , V_62 ) ;
return & V_62 -> V_69 ;
}
static int F_35 ( struct V_13 * V_14 , T_2 V_72 , T_1 V_73 ,
T_1 * V_74 )
{
F_10 ( L_2 , V_34 , V_14 ) ;
* V_74 = 0 ;
return 0 ;
}
static int F_36 ( struct V_13 * V_14 , T_2 V_72 , int V_73 ,
union V_10 * V_11 )
{
struct V_26 * V_75 ;
F_10 ( L_6 ,
V_34 , V_14 , V_72 , V_73 , V_11 ) ;
V_75 = F_8 ( V_14 ) ;
F_37 ( V_72 == 0 ) ;
memset ( & ( V_11 -> V_76 [ 0 ] ) , 0 , sizeof( V_11 -> V_76 ) ) ;
memcpy ( & ( V_11 -> V_76 [ 0 ] ) , V_75 -> V_35 . V_57 . V_77 [ V_72 - 1 ] -> V_78 , 6 ) ;
return 0 ;
}
static int F_38 ( struct V_13 * V_14 ,
struct V_79 * V_80 )
{
struct V_26 * V_75 ;
F_10 ( L_2 , V_34 , V_14 ) ;
V_75 = F_8 ( V_14 ) ;
memset ( V_80 , 0 , sizeof *V_80 ) ;
memcpy ( & V_80 -> V_81 , V_75 -> V_35 . V_57 . V_77 [ 0 ] -> V_78 , 6 ) ;
V_80 -> V_82 = V_75 -> V_35 . V_57 . V_83 ;
V_80 -> V_84 = V_75 -> V_35 . V_57 . V_85 ;
V_80 -> V_86 = V_75 -> V_86 ;
V_80 -> V_87 = V_88 ;
V_80 -> V_89 = ( T_3 ) V_75 -> V_35 . V_57 . V_58 -> V_90 ;
V_80 -> V_91 = ( T_3 ) V_75 -> V_35 . V_57 . V_58 -> V_28 ;
V_80 -> V_92 = V_93 ;
V_80 -> V_94 = V_95 ;
V_80 -> V_96 = V_97 ;
V_80 -> V_98 = V_99 ;
V_80 -> V_100 = 1 ;
V_80 -> V_101 = V_102 ;
V_80 -> V_103 = V_102 ;
V_80 -> V_104 = V_105 ;
V_80 -> V_106 = V_107 ;
V_80 -> V_108 = F_39 ( & V_75 -> V_35 ) ;
V_80 -> V_109 = V_110 ;
V_80 -> V_111 = 0 ;
V_80 -> V_112 = V_113 ;
return 0 ;
}
static int F_40 ( struct V_13 * V_14 , T_2 V_72 ,
struct V_114 * V_80 )
{
struct V_26 * V_75 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
F_10 ( L_2 , V_34 , V_14 ) ;
V_75 = F_8 ( V_14 ) ;
V_116 = V_75 -> V_35 . V_57 . V_77 [ V_72 - 1 ] ;
memset ( V_80 , 0 , sizeof( struct V_114 ) ) ;
V_80 -> V_119 = V_120 ;
if ( V_116 -> V_121 >= 4096 )
V_80 -> V_122 = V_120 ;
else if ( V_116 -> V_121 >= 2048 )
V_80 -> V_122 = V_123 ;
else if ( V_116 -> V_121 >= 1024 )
V_80 -> V_122 = V_124 ;
else if ( V_116 -> V_121 >= 512 )
V_80 -> V_122 = V_125 ;
else
V_80 -> V_122 = V_126 ;
if ( ! F_41 ( V_116 ) )
V_80 -> V_127 = V_128 ;
else {
V_118 = F_42 ( V_116 ) ;
if ( V_118 ) {
if ( V_118 -> V_129 )
V_80 -> V_127 = V_130 ;
else
V_80 -> V_127 = V_131 ;
F_43 ( V_118 ) ;
} else
V_80 -> V_127 = V_131 ;
}
V_80 -> V_132 =
V_133 |
V_134 |
V_135 |
V_136 |
V_137 | V_138 ;
V_80 -> V_139 = 1 ;
V_80 -> V_140 = 1 ;
V_80 -> V_141 = 2 ;
V_80 -> V_142 = V_143 ;
V_80 -> V_144 = - 1 ;
return 0 ;
}
static T_5 F_44 ( struct V_28 * V_75 , struct V_145 * V_146 ,
char * V_147 )
{
struct V_26 * V_26 = F_45 ( V_75 , struct V_26 ,
V_14 . V_75 ) ;
F_10 ( L_7 , V_34 , V_75 ) ;
return sprintf ( V_147 , L_8 , V_26 -> V_35 . V_57 . V_83 ) ;
}
static T_5 F_46 ( struct V_28 * V_75 , struct V_145 * V_146 ,
char * V_147 )
{
struct V_26 * V_26 = F_45 ( V_75 , struct V_26 ,
V_14 . V_75 ) ;
F_10 ( L_7 , V_34 , V_75 ) ;
return sprintf ( V_147 , L_9 ,
F_47 ( V_26 -> V_35 . V_57 . V_85 ) ,
F_48 ( V_26 -> V_35 . V_57 . V_85 ) ,
F_49 ( V_26 -> V_35 . V_57 . V_85 ) ,
F_50 ( V_26 -> V_35 . V_57 . V_85 ) ) ;
}
static T_5 F_51 ( struct V_28 * V_75 , struct V_145 * V_146 ,
char * V_147 )
{
struct V_26 * V_26 = F_45 ( V_75 , struct V_26 ,
V_14 . V_75 ) ;
struct V_148 V_149 ;
struct V_115 * V_150 = V_26 -> V_35 . V_57 . V_77 [ 0 ] ;
F_10 ( L_7 , V_34 , V_75 ) ;
V_150 -> V_151 -> V_152 ( V_150 , & V_149 ) ;
return sprintf ( V_147 , L_10 , V_149 . V_153 ) ;
}
static T_5 F_52 ( struct V_28 * V_75 , struct V_145 * V_146 ,
char * V_147 )
{
struct V_26 * V_26 = F_45 ( V_75 , struct V_26 ,
V_14 . V_75 ) ;
F_10 ( L_7 , V_34 , V_75 ) ;
return sprintf ( V_147 , L_11 , V_26 -> V_35 . V_57 . V_58 -> V_90 ,
V_26 -> V_35 . V_57 . V_58 -> V_28 ) ;
}
static int F_53 ( struct V_13 * V_14 ,
union V_154 * V_66 )
{
struct V_155 V_156 , V_157 ;
struct V_26 * V_26 = F_8 ( V_14 ) ;
F_54 ( V_26 -> V_35 . V_57 . V_58 , & V_156 , & V_157 ) ;
memset ( V_66 , 0 , sizeof *V_66 ) ;
V_66 -> V_158 . V_159 = V_156 . V_159 + V_157 . V_159 ;
V_66 -> V_158 . V_160 = V_156 . V_160 + V_157 . V_160 ;
V_66 -> V_158 . V_161 = V_156 . V_161 + V_157 . V_161 ;
V_66 -> V_158 . V_162 = V_156 . V_162 + V_157 . V_160 ;
return 0 ;
}
int F_55 ( struct V_26 * V_75 )
{
int V_53 ;
int V_163 ;
F_10 ( L_12 , V_34 , V_75 ) ;
F_37 ( ! V_75 -> V_35 . V_57 . V_77 [ 0 ] ) ;
F_56 ( V_75 -> V_14 . V_164 , L_13 , V_165 ) ;
memset ( & V_75 -> V_14 . V_166 , 0 , sizeof( V_75 -> V_14 . V_166 ) ) ;
memcpy ( & V_75 -> V_14 . V_166 , V_75 -> V_35 . V_57 . V_77 [ 0 ] -> V_78 , 6 ) ;
V_75 -> V_14 . V_167 = V_168 ;
V_75 -> V_86 = V_169 | V_170 ;
if ( V_171 )
V_75 -> V_86 |= V_172 ;
V_75 -> V_14 . V_173 = 0 ;
V_75 -> V_14 . V_174 =
( 1ull << V_175 ) |
( 1ull << V_176 ) |
( 1ull << V_177 ) |
( 1ull << V_178 ) |
( 1ull << V_179 ) |
( 1ull << V_180 ) |
( 1ull << V_181 ) |
( 1ull << V_182 ) |
( 1ull << V_183 ) |
( 1ull << V_184 ) |
( 1ull << V_185 ) |
( 1ull << V_186 ) |
( 1ull << V_187 ) |
( 1ull << V_188 ) |
( 1ull << V_189 ) |
( 1ull << V_190 ) |
( 1ull << V_191 ) |
( 1ull << V_192 ) ;
V_75 -> V_14 . V_193 = V_194 ;
memcpy ( V_75 -> V_14 . V_195 , V_196 , sizeof( V_196 ) ) ;
V_75 -> V_14 . V_197 = V_75 -> V_35 . V_57 . V_198 ;
V_75 -> V_14 . V_199 = 1 ;
V_75 -> V_14 . V_200 = & ( V_75 -> V_35 . V_57 . V_58 -> V_75 ) ;
V_75 -> V_14 . V_201 = F_38 ;
V_75 -> V_14 . V_202 = F_40 ;
V_75 -> V_14 . V_203 = F_35 ;
V_75 -> V_14 . V_204 = F_36 ;
V_75 -> V_14 . V_205 = F_14 ;
V_75 -> V_14 . V_206 = F_7 ;
V_75 -> V_14 . V_207 = F_19 ;
V_75 -> V_14 . V_208 = F_32 ;
V_75 -> V_14 . V_209 = F_27 ;
V_75 -> V_14 . V_210 = F_1 ;
V_75 -> V_14 . V_211 = F_3 ;
V_75 -> V_14 . V_212 = V_213 ;
V_75 -> V_14 . V_214 = V_215 ;
V_75 -> V_14 . V_216 = V_217 ;
V_75 -> V_14 . V_218 = V_219 ;
V_75 -> V_14 . V_220 = V_221 ;
V_75 -> V_14 . V_222 = V_223 ;
V_75 -> V_14 . V_224 = V_225 ;
V_75 -> V_14 . V_226 = V_227 ;
V_75 -> V_14 . V_228 = V_229 ;
V_75 -> V_14 . V_230 = V_231 ;
V_75 -> V_14 . V_232 = V_233 ;
V_75 -> V_14 . V_234 = V_235 ;
V_75 -> V_14 . V_236 = V_237 ;
V_75 -> V_14 . V_238 = V_239 ;
V_75 -> V_14 . V_240 = V_241 ;
V_75 -> V_14 . V_242 = V_243 ;
V_75 -> V_14 . V_244 = V_245 ;
V_75 -> V_14 . V_246 = V_247 ;
V_75 -> V_14 . V_248 = V_249 ;
V_75 -> V_14 . V_250 = F_4 ;
V_75 -> V_14 . V_251 = F_5 ;
V_75 -> V_14 . V_252 = F_6 ;
V_75 -> V_14 . V_253 = V_254 ;
V_75 -> V_14 . V_255 = V_256 ;
V_75 -> V_14 . V_257 = V_258 ;
V_75 -> V_14 . V_259 = F_53 ;
V_75 -> V_14 . V_260 = V_261 ;
V_75 -> V_14 . V_262 = F_57 ( sizeof( struct V_263 ) , V_39 ) ;
if ( ! V_75 -> V_14 . V_262 )
return - V_40 ;
V_75 -> V_14 . V_262 -> V_264 = V_265 ;
V_75 -> V_14 . V_262 -> V_266 = V_267 ;
V_75 -> V_14 . V_262 -> V_268 = V_269 ;
V_75 -> V_14 . V_262 -> V_270 = V_271 ;
V_75 -> V_14 . V_262 -> V_272 = V_273 ;
V_75 -> V_14 . V_262 -> V_274 = V_275 ;
V_75 -> V_14 . V_262 -> V_276 = V_277 ;
V_75 -> V_14 . V_262 -> V_278 = V_279 ;
V_53 = F_58 ( & V_75 -> V_14 , NULL ) ;
if ( V_53 )
goto V_280;
for ( V_163 = 0 ; V_163 < F_59 ( V_281 ) ; ++ V_163 ) {
V_53 = F_60 ( & V_75 -> V_14 . V_75 ,
V_281 [ V_163 ] ) ;
if ( V_53 )
goto V_282;
}
return 0 ;
V_282:
F_61 ( & V_75 -> V_14 ) ;
V_280:
F_12 ( V_75 -> V_14 . V_262 ) ;
return V_53 ;
}
void F_62 ( struct V_26 * V_75 )
{
int V_163 ;
F_10 ( L_12 , V_34 , V_75 ) ;
for ( V_163 = 0 ; V_163 < F_59 ( V_281 ) ; ++ V_163 )
F_63 ( & V_75 -> V_14 . V_75 ,
V_281 [ V_163 ] ) ;
F_61 ( & V_75 -> V_14 ) ;
F_12 ( V_75 -> V_14 . V_262 ) ;
return;
}
