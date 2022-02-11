static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 ,
struct V_5 * V_6 )
{
return - V_7 ;
}
static struct V_8 * F_2 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
return F_3 ( - V_7 ) ;
}
static int F_4 ( struct V_8 * V_13 )
{
return - V_7 ;
}
static int F_5 ( struct V_14 * V_15 , union V_16 * V_17 , T_2 V_18 )
{
return - V_7 ;
}
static int F_6 ( struct V_14 * V_15 , union V_16 * V_17 , T_2 V_18 )
{
return - V_7 ;
}
static int F_7 ( struct V_1 * V_2 , int V_19 ,
T_1 V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_25 * V_27 )
{
return - V_7 ;
}
static int F_8 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_9 ( V_29 -> V_32 ) ;
struct V_33 * V_34 = F_10 ( V_29 ) ;
struct V_35 * V_36 , * V_37 ;
F_11 ( L_1 , V_38 , V_29 ) ;
F_12 (mm, tmp, &ucontext->mmaps, entry)
F_13 ( V_36 ) ;
F_14 ( & V_31 -> V_39 , & V_34 -> V_40 ) ;
F_13 ( V_34 ) ;
return 0 ;
}
static struct V_28 * F_15 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_33 * V_29 ;
struct V_30 * V_31 = F_9 ( V_2 ) ;
F_11 ( L_2 , V_38 , V_2 ) ;
V_29 = F_16 ( sizeof( * V_29 ) , V_43 ) ;
if ( ! V_29 )
return F_3 ( - V_44 ) ;
F_17 ( & V_31 -> V_39 , & V_29 -> V_40 ) ;
F_18 ( & V_29 -> V_45 ) ;
F_19 ( & V_29 -> V_46 ) ;
return & V_29 -> V_47 ;
}
static int F_20 ( struct V_28 * V_29 , struct V_48 * V_49 )
{
int V_50 = V_49 -> V_51 - V_49 -> V_52 ;
T_3 V_53 = V_49 -> V_54 << V_55 ;
struct V_56 * V_39 ;
int V_57 = 0 ;
struct V_35 * V_36 ;
struct V_33 * V_34 ;
T_4 V_58 ;
F_11 ( L_3 , V_38 , V_49 -> V_54 ,
V_53 , V_50 ) ;
if ( V_49 -> V_52 & ( V_59 - 1 ) )
return - V_60 ;
V_39 = & ( F_9 ( V_29 -> V_32 ) -> V_39 ) ;
V_34 = F_10 ( V_29 ) ;
V_36 = F_21 ( V_34 , V_53 , V_50 ) ;
if ( ! V_36 )
return - V_60 ;
V_58 = V_36 -> V_58 ;
F_13 ( V_36 ) ;
if ( ( V_58 >= F_22 ( V_39 -> V_61 . V_62 , 0 ) ) &&
( V_58 < ( F_22 ( V_39 -> V_61 . V_62 , 0 ) +
F_23 ( V_39 -> V_61 . V_62 , 0 ) ) ) ) {
V_49 -> V_63 = F_24 ( V_49 -> V_63 ) ;
V_57 = F_25 ( V_49 , V_49 -> V_52 ,
V_58 >> V_55 ,
V_50 , V_49 -> V_63 ) ;
} else if ( ( V_58 >= F_22 ( V_39 -> V_61 . V_62 , 2 ) ) &&
( V_58 < ( F_22 ( V_39 -> V_61 . V_62 , 2 ) +
F_23 ( V_39 -> V_61 . V_62 , 2 ) ) ) ) {
if ( V_58 >= V_39 -> V_64 )
V_49 -> V_63 = F_26 ( V_49 -> V_63 ) ;
else
V_49 -> V_63 = F_24 ( V_49 -> V_63 ) ;
V_57 = F_25 ( V_49 , V_49 -> V_52 ,
V_58 >> V_55 ,
V_50 , V_49 -> V_63 ) ;
} else {
V_57 = F_27 ( V_49 , V_49 -> V_52 ,
V_58 >> V_55 ,
V_50 , V_49 -> V_63 ) ;
}
return V_57 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_30 * V_31 ;
struct V_65 * V_66 ;
V_66 = F_29 ( V_10 ) ;
V_31 = V_66 -> V_31 ;
F_11 ( L_4 , V_38 , V_10 , V_66 -> V_67 ) ;
F_30 ( & V_31 -> V_39 . V_68 . V_69 , V_66 -> V_67 ,
& V_31 -> V_39 . V_68 . V_70 ) ;
F_13 ( V_66 ) ;
return 0 ;
}
static struct V_9 * F_31 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_41 * V_42 )
{
struct V_65 * V_66 ;
T_3 V_67 ;
struct V_30 * V_31 ;
F_11 ( L_2 , V_38 , V_2 ) ;
V_31 = (struct V_30 * ) V_2 ;
V_67 = F_32 ( & V_31 -> V_39 . V_68 . V_69 ,
& V_31 -> V_39 . V_68 . V_70 ) ;
if ( ! V_67 )
return F_3 ( - V_60 ) ;
V_66 = F_16 ( sizeof( * V_66 ) , V_43 ) ;
if ( ! V_66 ) {
F_30 ( & V_31 -> V_39 . V_68 . V_69 , V_67 ,
& V_31 -> V_39 . V_68 . V_70 ) ;
return F_3 ( - V_44 ) ;
}
V_66 -> V_67 = V_67 ;
V_66 -> V_31 = V_31 ;
if ( V_29 ) {
if ( F_33 ( V_42 , & V_66 -> V_67 , sizeof( T_3 ) ) ) {
F_28 ( & V_66 -> V_71 ) ;
return F_3 ( - V_72 ) ;
}
}
F_11 ( L_5 , V_38 , V_67 , V_66 ) ;
return & V_66 -> V_71 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_73 ,
T_2 * V_74 )
{
F_11 ( L_2 , V_38 , V_2 ) ;
* V_74 = 0 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_3 , int V_73 ,
union V_16 * V_17 )
{
struct V_30 * V_75 ;
F_11 ( L_6 ,
V_38 , V_2 , V_3 , V_73 , V_17 ) ;
V_75 = F_9 ( V_2 ) ;
F_36 ( V_3 == 0 ) ;
memset ( & ( V_17 -> V_76 [ 0 ] ) , 0 , sizeof( V_17 -> V_76 ) ) ;
memcpy ( & ( V_17 -> V_76 [ 0 ] ) , V_75 -> V_39 . V_61 . V_77 [ V_3 - 1 ] -> V_78 , 6 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_79 * V_6 )
{
struct V_30 * V_75 ;
F_11 ( L_2 , V_38 , V_2 ) ;
V_75 = F_9 ( V_2 ) ;
memset ( V_6 , 0 , sizeof *V_6 ) ;
memcpy ( & V_6 -> V_80 , V_75 -> V_39 . V_61 . V_77 [ 0 ] -> V_78 , 6 ) ;
V_6 -> V_81 = V_75 -> V_39 . V_61 . V_82 ;
V_6 -> V_83 = V_75 -> V_39 . V_61 . V_84 ;
V_6 -> V_85 = V_75 -> V_85 ;
V_6 -> V_86 = V_87 ;
V_6 -> V_88 = ( T_3 ) V_75 -> V_39 . V_61 . V_62 -> V_89 ;
V_6 -> V_90 = ( T_3 ) V_75 -> V_39 . V_61 . V_62 -> V_32 ;
V_6 -> V_91 = V_92 ;
V_6 -> V_93 = V_94 ;
V_6 -> V_95 = V_96 ;
V_6 -> V_97 = V_98 ;
V_6 -> V_99 = 1 ;
V_6 -> V_100 = V_101 ;
V_6 -> V_102 = V_101 ;
V_6 -> V_103 = V_104 ;
V_6 -> V_105 = V_106 ;
V_6 -> V_107 = F_38 ( & V_75 -> V_39 ) ;
V_6 -> V_108 = V_109 ;
V_6 -> V_110 = 0 ;
V_6 -> V_111 = V_112 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_113 * V_6 )
{
struct V_30 * V_75 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
F_11 ( L_2 , V_38 , V_2 ) ;
V_75 = F_9 ( V_2 ) ;
V_115 = V_75 -> V_39 . V_61 . V_77 [ V_3 - 1 ] ;
memset ( V_6 , 0 , sizeof( struct V_113 ) ) ;
V_6 -> V_118 = V_119 ;
if ( V_115 -> V_120 >= 4096 )
V_6 -> V_121 = V_119 ;
else if ( V_115 -> V_120 >= 2048 )
V_6 -> V_121 = V_122 ;
else if ( V_115 -> V_120 >= 1024 )
V_6 -> V_121 = V_123 ;
else if ( V_115 -> V_120 >= 512 )
V_6 -> V_121 = V_124 ;
else
V_6 -> V_121 = V_125 ;
if ( ! F_40 ( V_115 ) )
V_6 -> V_126 = V_127 ;
else {
V_117 = F_41 ( V_115 ) ;
if ( V_117 ) {
if ( V_117 -> V_128 )
V_6 -> V_126 = V_129 ;
else
V_6 -> V_126 = V_130 ;
F_42 ( V_117 ) ;
} else
V_6 -> V_126 = V_130 ;
}
V_6 -> V_131 =
V_132 |
V_133 |
V_134 |
V_135 |
V_136 | V_137 ;
V_6 -> V_138 = 1 ;
V_6 -> V_139 = 1 ;
V_6 -> V_140 = 2 ;
V_6 -> V_141 = 2 ;
V_6 -> V_142 = - 1 ;
return 0 ;
}
static T_5 F_43 ( struct V_32 * V_75 , struct V_143 * V_144 ,
char * V_145 )
{
struct V_30 * V_30 = F_44 ( V_75 , struct V_30 ,
V_2 . V_75 ) ;
F_11 ( L_7 , V_38 , V_75 ) ;
return sprintf ( V_145 , L_8 , V_30 -> V_39 . V_61 . V_82 ) ;
}
static T_5 F_45 ( struct V_32 * V_75 , struct V_143 * V_144 ,
char * V_145 )
{
struct V_30 * V_30 = F_44 ( V_75 , struct V_30 ,
V_2 . V_75 ) ;
F_11 ( L_7 , V_38 , V_75 ) ;
return sprintf ( V_145 , L_9 ,
F_46 ( V_30 -> V_39 . V_61 . V_84 ) ,
F_47 ( V_30 -> V_39 . V_61 . V_84 ) ,
F_48 ( V_30 -> V_39 . V_61 . V_84 ) ,
F_49 ( V_30 -> V_39 . V_61 . V_84 ) ) ;
}
static T_5 F_50 ( struct V_32 * V_75 , struct V_143 * V_144 ,
char * V_145 )
{
struct V_30 * V_30 = F_44 ( V_75 , struct V_30 ,
V_2 . V_75 ) ;
struct V_146 V_147 ;
struct V_114 * V_148 = V_30 -> V_39 . V_61 . V_77 [ 0 ] ;
F_11 ( L_7 , V_38 , V_75 ) ;
V_148 -> V_149 -> V_150 ( V_148 , & V_147 ) ;
return sprintf ( V_145 , L_10 , V_147 . V_151 ) ;
}
static T_5 F_51 ( struct V_32 * V_75 , struct V_143 * V_144 ,
char * V_145 )
{
struct V_30 * V_30 = F_44 ( V_75 , struct V_30 ,
V_2 . V_75 ) ;
F_11 ( L_7 , V_38 , V_75 ) ;
return sprintf ( V_145 , L_11 , V_30 -> V_39 . V_61 . V_62 -> V_89 ,
V_30 -> V_39 . V_61 . V_62 -> V_32 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
union V_152 * V_153 )
{
struct V_154 V_155 , V_156 ;
struct V_30 * V_30 = F_9 ( V_2 ) ;
F_53 ( V_30 -> V_39 . V_61 . V_62 , & V_155 , & V_156 ) ;
memset ( V_153 , 0 , sizeof *V_153 ) ;
V_153 -> V_157 . V_158 = V_155 . V_158 + V_156 . V_158 ;
V_153 -> V_157 . V_159 = V_155 . V_159 + V_156 . V_159 ;
V_153 -> V_157 . V_160 = V_155 . V_160 + V_156 . V_160 ;
V_153 -> V_157 . V_161 = V_155 . V_161 + V_156 . V_159 ;
return 0 ;
}
int F_54 ( struct V_30 * V_75 )
{
int V_57 ;
int V_162 ;
F_11 ( L_12 , V_38 , V_75 ) ;
F_36 ( ! V_75 -> V_39 . V_61 . V_77 [ 0 ] ) ;
F_55 ( V_75 -> V_2 . V_163 , L_13 , V_164 ) ;
memset ( & V_75 -> V_2 . V_165 , 0 , sizeof( V_75 -> V_2 . V_165 ) ) ;
memcpy ( & V_75 -> V_2 . V_165 , V_75 -> V_39 . V_61 . V_77 [ 0 ] -> V_78 , 6 ) ;
V_75 -> V_2 . V_166 = V_167 ;
V_75 -> V_85 = V_168 | V_169 ;
if ( V_170 )
V_75 -> V_85 |= V_171 ;
V_75 -> V_2 . V_172 = 0 ;
V_75 -> V_2 . V_173 =
( 1ull << V_174 ) |
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
( 1ull << V_190 ) ;
V_75 -> V_2 . V_191 = V_192 ;
memcpy ( V_75 -> V_2 . V_193 , V_194 , sizeof( V_194 ) ) ;
V_75 -> V_2 . V_195 = V_75 -> V_39 . V_61 . V_196 ;
V_75 -> V_2 . V_197 = 1 ;
V_75 -> V_2 . V_198 = & ( V_75 -> V_39 . V_61 . V_62 -> V_75 ) ;
V_75 -> V_2 . V_199 = F_37 ;
V_75 -> V_2 . V_200 = F_39 ;
V_75 -> V_2 . V_201 = F_1 ;
V_75 -> V_2 . V_202 = F_34 ;
V_75 -> V_2 . V_203 = F_35 ;
V_75 -> V_2 . V_204 = F_15 ;
V_75 -> V_2 . V_205 = F_8 ;
V_75 -> V_2 . V_206 = F_20 ;
V_75 -> V_2 . V_207 = F_31 ;
V_75 -> V_2 . V_208 = F_28 ;
V_75 -> V_2 . V_209 = F_2 ;
V_75 -> V_2 . V_210 = F_4 ;
V_75 -> V_2 . V_211 = V_212 ;
V_75 -> V_2 . V_213 = V_214 ;
V_75 -> V_2 . V_215 = V_216 ;
V_75 -> V_2 . V_217 = V_218 ;
V_75 -> V_2 . V_219 = V_220 ;
V_75 -> V_2 . V_221 = V_222 ;
V_75 -> V_2 . V_223 = V_224 ;
V_75 -> V_2 . V_225 = V_226 ;
V_75 -> V_2 . V_227 = V_228 ;
V_75 -> V_2 . V_229 = V_230 ;
V_75 -> V_2 . V_231 = V_232 ;
V_75 -> V_2 . V_233 = V_234 ;
V_75 -> V_2 . V_235 = V_236 ;
V_75 -> V_2 . V_237 = V_238 ;
V_75 -> V_2 . V_239 = V_240 ;
V_75 -> V_2 . V_241 = V_242 ;
V_75 -> V_2 . V_243 = V_244 ;
V_75 -> V_2 . V_245 = V_246 ;
V_75 -> V_2 . V_247 = F_5 ;
V_75 -> V_2 . V_248 = F_6 ;
V_75 -> V_2 . V_249 = F_7 ;
V_75 -> V_2 . V_250 = V_251 ;
V_75 -> V_2 . V_252 = V_253 ;
V_75 -> V_2 . V_254 = V_255 ;
V_75 -> V_2 . V_256 = F_52 ;
V_75 -> V_2 . V_257 = V_258 ;
V_75 -> V_2 . V_259 = F_56 ( sizeof( struct V_260 ) , V_43 ) ;
if ( ! V_75 -> V_2 . V_259 )
return - V_44 ;
V_75 -> V_2 . V_259 -> V_261 = V_262 ;
V_75 -> V_2 . V_259 -> V_263 = V_264 ;
V_75 -> V_2 . V_259 -> V_265 = V_266 ;
V_75 -> V_2 . V_259 -> V_267 = V_268 ;
V_75 -> V_2 . V_259 -> V_269 = V_270 ;
V_75 -> V_2 . V_259 -> V_271 = V_272 ;
V_75 -> V_2 . V_259 -> V_273 = V_274 ;
V_75 -> V_2 . V_259 -> V_275 = V_276 ;
V_57 = F_57 ( & V_75 -> V_2 , NULL ) ;
if ( V_57 )
goto V_277;
for ( V_162 = 0 ; V_162 < F_58 ( V_278 ) ; ++ V_162 ) {
V_57 = F_59 ( & V_75 -> V_2 . V_75 ,
V_278 [ V_162 ] ) ;
if ( V_57 )
goto V_279;
}
return 0 ;
V_279:
F_60 ( & V_75 -> V_2 ) ;
V_277:
F_13 ( V_75 -> V_2 . V_259 ) ;
return V_57 ;
}
void F_61 ( struct V_30 * V_75 )
{
int V_162 ;
F_11 ( L_12 , V_38 , V_75 ) ;
for ( V_162 = 0 ; V_162 < F_58 ( V_278 ) ; ++ V_162 )
F_62 ( & V_75 -> V_2 . V_75 ,
V_278 [ V_162 ] ) ;
F_60 ( & V_75 -> V_2 ) ;
F_13 ( V_75 -> V_2 . V_259 ) ;
return;
}
