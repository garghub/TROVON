static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 10 ;
V_2 -> V_5 = 1 ;
V_2 -> V_6 = 1 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 1 << 18 ;
V_2 -> V_9 = 10 ;
}
static struct V_10 * F_3 ( struct V_11 * V_12 )
{
struct V_10 * V_13 ;
struct V_14 * V_15 ;
V_13 = F_4 ( sizeof( struct V_10 ) , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_12 -> V_17 = V_13 ;
V_13 -> V_18 = V_12 ;
V_13 -> V_19 = F_5 ( struct V_20 ) ;
if ( ! V_13 -> V_19 ) {
F_6 ( V_13 ) ;
return NULL ;
}
F_7 ( V_21 , & V_13 -> V_22 ) ;
F_1 ( & V_13 -> V_23 ) ;
F_8 ( & V_13 -> V_24 ) ;
F_9 ( & V_13 -> V_25 , 0 ) ;
F_10 ( & V_13 -> V_26 ) ;
F_10 ( & V_13 -> V_27 ) ;
F_2 ( & V_13 -> V_28 ) ;
F_2 ( & V_13 -> V_29 ) ;
V_13 -> V_30 . V_31 = NULL ;
F_11 ( & V_13 -> V_32 ) ;
F_2 ( & V_13 -> V_33 ) ;
F_12 ( & V_13 -> V_34 ) ;
F_11 ( & V_13 -> V_35 ) ;
F_12 ( & V_13 -> V_36 ) ;
F_12 ( & V_13 -> V_37 ) ;
F_8 ( & V_13 -> V_38 ) ;
F_11 ( & V_13 -> V_39 ) ;
F_2 ( & V_13 -> V_40 ) ;
F_2 ( & V_13 -> V_41 ) ;
V_15 = & V_13 -> V_42 ;
F_13 ( V_15 ) ;
V_15 -> V_43 = & V_44 ;
V_15 -> V_45 = V_12 -> V_46 -> V_47 ;
V_15 -> V_48 = 0 ;
F_14 ( V_15 , V_49 ) ;
V_15 -> V_50 = NULL ;
V_15 -> V_51 = V_12 -> V_52 ;
V_15 -> V_53 = 0 ;
F_2 ( & V_13 -> V_54 ) ;
F_9 ( & V_13 -> V_55 , 0 ) ;
F_11 ( & V_13 -> V_56 ) ;
F_11 ( & V_13 -> V_57 ) ;
F_11 ( & V_13 -> V_58 ) ;
F_11 ( & V_13 -> V_59 ) ;
F_2 ( & V_13 -> V_60 ) ;
F_8 ( & V_13 -> V_61 ) ;
F_8 ( & V_13 -> V_62 ) ;
F_2 ( & V_13 -> V_63 ) ;
F_11 ( & V_13 -> V_64 ) ;
F_11 ( & V_13 -> V_65 ) ;
F_15 ( & V_13 -> V_66 ) ;
F_9 ( & V_13 -> V_67 , 0 ) ;
F_8 ( & V_13 -> V_68 ) ;
F_11 ( & V_13 -> V_69 ) ;
return V_13 ;
}
static int F_16 ( struct V_10 * V_13 , int V_70 )
{
struct V_71 * V_12 = & V_13 -> V_72 ;
if ( V_12 -> V_73 != V_74 ||
V_12 -> V_75 != V_76 ) {
if ( ! V_70 )
F_17 ( V_77 L_1 ) ;
return - V_78 ;
}
if ( V_12 -> V_79 == V_80 &&
V_12 -> V_81 == V_82 )
return 0 ;
F_18 ( V_13 , L_2 ) ;
return - V_78 ;
}
static void F_19 ( struct V_83 * V_83 , int error )
{
struct V_84 * V_84 = V_83 -> V_85 ;
if ( ! error )
F_20 ( V_84 ) ;
else
F_17 ( V_77 L_3 , error ) ;
F_21 ( V_84 ) ;
}
static void F_22 ( struct V_10 * V_13 , const void * V_86 )
{
struct V_71 * V_12 = & V_13 -> V_72 ;
struct V_11 * V_87 = V_13 -> V_18 ;
const struct V_88 * V_89 = V_86 ;
V_12 -> V_73 = F_23 ( V_89 -> V_90 . V_91 ) ;
V_12 -> V_75 = F_23 ( V_89 -> V_90 . V_92 ) ;
V_12 -> V_93 = F_23 ( V_89 -> V_90 . V_94 ) ;
V_12 -> V_79 = F_23 ( V_89 -> V_79 ) ;
V_12 -> V_81 = F_23 ( V_89 -> V_81 ) ;
V_12 -> V_95 = F_23 ( V_89 -> V_95 ) ;
V_12 -> V_96 = F_23 ( V_89 -> V_96 ) ;
V_12 -> V_97 . V_98 = F_24 ( V_89 -> V_97 . V_98 ) ;
V_12 -> V_97 . V_99 = F_24 ( V_89 -> V_97 . V_99 ) ;
V_12 -> V_100 . V_98 = F_24 ( V_89 -> V_100 . V_98 ) ;
V_12 -> V_100 . V_99 = F_24 ( V_89 -> V_100 . V_99 ) ;
memcpy ( V_12 -> V_101 , V_89 -> V_101 , V_102 ) ;
memcpy ( V_12 -> V_103 , V_89 -> V_103 , V_102 ) ;
memcpy ( V_87 -> V_104 , V_89 -> V_105 , 16 ) ;
}
static int F_25 ( struct V_10 * V_13 , T_1 V_106 , int V_70 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_88 * V_107 ;
struct V_84 * V_84 ;
struct V_83 * V_83 ;
V_84 = F_26 ( V_49 ) ;
if ( F_27 ( ! V_84 ) )
return - V_108 ;
F_28 ( V_84 ) ;
F_29 ( V_84 ) ;
F_30 ( V_84 ) ;
V_83 = F_31 ( V_49 , 1 ) ;
V_83 -> V_109 . V_110 = V_106 * ( V_12 -> V_111 >> 9 ) ;
V_83 -> V_112 = V_12 -> V_46 ;
F_32 ( V_83 , V_84 , V_113 , 0 ) ;
V_83 -> V_114 = F_19 ;
V_83 -> V_85 = V_84 ;
F_33 ( V_115 | V_116 , V_83 ) ;
F_34 ( V_84 ) ;
F_35 ( V_83 ) ;
if ( ! F_36 ( V_84 ) ) {
F_37 ( V_84 ) ;
return - V_117 ;
}
V_107 = F_38 ( V_84 ) ;
F_22 ( V_13 , V_107 ) ;
F_39 ( V_84 ) ;
F_37 ( V_84 ) ;
return F_16 ( V_13 , V_70 ) ;
}
static int F_40 ( struct V_10 * V_13 , int V_70 )
{
T_2 V_118 , V_119 , V_120 ;
T_2 V_121 ;
unsigned int V_122 ;
int error ;
error = F_25 ( V_13 , V_123 >> V_13 -> V_124 , V_70 ) ;
if ( error ) {
if ( ! V_70 )
F_41 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_124 = V_13 -> V_72 . V_96 -
V_125 ;
V_13 -> V_126 = 1 << V_13 -> V_124 ;
V_13 -> V_127 = ( V_13 -> V_72 . V_95 -
sizeof( struct V_128 ) ) / sizeof( V_129 ) ;
V_13 -> V_130 = ( V_13 -> V_72 . V_95 -
sizeof( struct V_131 ) ) / sizeof( V_129 ) ;
V_13 -> V_132 = V_13 -> V_72 . V_95 - sizeof( struct V_131 ) ;
V_13 -> V_133 = V_13 -> V_72 . V_95 / 2 ;
V_13 -> V_134 = V_13 -> V_72 . V_96 - 1 ;
V_13 -> V_135 = V_13 -> V_133 / sizeof( V_129 ) ;
V_13 -> V_136 = ( V_13 -> V_72 . V_95 -
sizeof( struct V_131 ) ) /
sizeof( struct V_137 ) ;
V_13 -> V_138 = ( V_13 -> V_72 . V_95 -
sizeof( struct V_131 ) )
* V_139 ;
V_118 = F_42 ( sizeof( V_129 ) * ( 1 << V_140 ) ,
V_13 -> V_132 ) ;
V_119 = 0 ;
for ( V_121 = V_118 ; V_121 > V_13 -> V_127 ; ) {
V_121 = F_42 ( V_121 , V_13 -> V_130 ) ;
V_119 += V_121 ;
}
V_120 = 2 + V_140 ;
V_13 -> V_141 = V_118 + V_119 + V_120 ;
V_13 -> V_142 [ 0 ] = V_13 -> V_72 . V_95 -
sizeof( struct V_128 ) ;
V_13 -> V_142 [ 1 ] = V_13 -> V_72 . V_95 * V_13 -> V_127 ;
for ( V_122 = 2 ; ; V_122 ++ ) {
V_129 V_143 , V_144 ;
T_2 V_145 ;
V_143 = V_13 -> V_142 [ V_122 - 1 ] * V_13 -> V_130 ;
V_144 = V_143 ;
V_145 = F_43 ( V_144 , V_13 -> V_130 ) ;
if ( V_144 != V_13 -> V_142 [ V_122 - 1 ] || V_145 )
break;
V_13 -> V_142 [ V_122 ] = V_143 ;
}
V_13 -> V_146 = V_122 ;
V_13 -> V_142 [ V_122 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_146 <= V_147 ) ;
V_13 -> V_148 [ 0 ] = V_13 -> V_72 . V_95 -
sizeof( struct V_128 ) ;
V_13 -> V_148 [ 1 ] = V_13 -> V_132 * V_13 -> V_127 ;
for ( V_122 = 2 ; ; V_122 ++ ) {
V_129 V_143 , V_144 ;
T_2 V_145 ;
V_143 = V_13 -> V_148 [ V_122 - 1 ] * V_13 -> V_130 ;
V_144 = V_143 ;
V_145 = F_43 ( V_144 , V_13 -> V_130 ) ;
if ( V_144 != V_13 -> V_148 [ V_122 - 1 ] || V_145 )
break;
V_13 -> V_148 [ V_122 ] = V_143 ;
}
V_13 -> V_149 = V_122 ;
V_13 -> V_148 [ V_122 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_149 <= V_147 ) ;
return 0 ;
}
static int F_45 ( struct V_10 * V_13 , int V_70 )
{
char * V_150 , * V_151 ;
int error = 0 ;
V_150 = V_13 -> V_152 . V_153 ;
V_151 = V_13 -> V_152 . V_154 ;
if ( ! V_150 [ 0 ] || ! V_151 [ 0 ] ) {
error = F_25 ( V_13 , V_123 >> V_13 -> V_124 , V_70 ) ;
if ( error )
return error ;
if ( ! V_150 [ 0 ] )
V_150 = V_13 -> V_72 . V_101 ;
if ( ! V_151 [ 0 ] )
V_151 = V_13 -> V_72 . V_103 ;
}
if ( ! V_151 [ 0 ] )
V_151 = V_13 -> V_18 -> V_155 ;
F_46 ( V_13 -> V_156 , V_150 , V_157 ) ;
F_46 ( V_13 -> V_158 , V_151 , V_157 ) ;
V_151 = V_13 -> V_158 ;
while ( ( V_151 = strchr ( V_151 , '/' ) ) )
* V_151 = '_' ;
return error ;
}
static int F_47 ( struct V_10 * V_13 , struct V_159 * V_160 ,
int V_161 )
{
int error = 0 ;
if ( V_161 )
goto V_162;
error = F_48 ( V_13 ,
V_163 , & V_164 ,
V_165 , V_166 | V_167 ,
V_160 ) ;
if ( error ) {
F_41 ( V_13 , L_5 , error ) ;
goto V_168;
}
error = F_48 ( V_13 ,
V_169 , & V_164 ,
V_170 ,
V_166 | V_171 ,
& V_13 -> V_172 ) ;
if ( error ) {
F_41 ( V_13 , L_6 , error ) ;
goto V_173;
}
error = F_49 ( V_13 , V_174 , & V_164 ,
V_175 , & V_13 -> V_176 ) ;
if ( error ) {
F_41 ( V_13 , L_7 , error ) ;
goto V_177;
}
error = F_49 ( V_13 , V_178 , & V_179 ,
V_175 , & V_13 -> V_180 ) ;
if ( error ) {
F_41 ( V_13 , L_8 , error ) ;
goto V_181;
}
return 0 ;
V_162:
F_50 ( V_13 -> V_180 ) ;
V_181:
F_50 ( V_13 -> V_176 ) ;
V_177:
F_51 ( & V_13 -> V_172 ) ;
V_173:
F_51 ( V_160 ) ;
V_168:
return error ;
}
static int F_52 ( struct V_11 * V_12 , struct V_182 * * V_183 ,
V_129 V_98 , const char * V_184 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_182 * V_182 ;
struct V_185 * V_185 ;
V_185 = F_53 ( V_12 , V_186 , V_98 , 0 , 0 ) ;
if ( F_54 ( V_185 ) ) {
F_41 ( V_13 , L_9 , V_184 , F_55 ( V_185 ) ) ;
return F_55 ( V_185 ) ;
}
V_182 = F_56 ( V_185 ) ;
if ( ! V_182 ) {
F_41 ( V_13 , L_10 , V_184 ) ;
return - V_108 ;
}
* V_183 = V_182 ;
return 0 ;
}
static int F_57 ( struct V_10 * V_13 , int V_70 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_159 V_187 ;
V_129 V_98 ;
int V_188 ;
V_188 = F_48 ( V_13 , V_189 , & V_190 ,
V_170 , 0 , & V_187 ) ;
if ( V_188 ) {
F_41 ( V_13 , L_11 , V_188 ) ;
return V_188 ;
}
V_188 = F_40 ( V_13 , V_70 ) ;
if ( V_188 ) {
F_41 ( V_13 , L_12 , V_188 ) ;
goto V_191;
}
if ( V_13 -> V_72 . V_95 < F_58 ( V_12 -> V_46 ) ) {
V_188 = - V_78 ;
F_41 ( V_13 , L_13
L_14 ,
V_13 -> V_72 . V_95 , F_58 ( V_12 -> V_46 ) ) ;
goto V_191;
}
if ( V_13 -> V_72 . V_95 > V_113 ) {
V_188 = - V_78 ;
F_41 ( V_13 , L_15
L_16 ,
V_13 -> V_72 . V_95 , ( unsigned int ) V_113 ) ;
goto V_191;
}
F_59 ( V_12 , V_13 -> V_72 . V_95 ) ;
V_98 = V_13 -> V_72 . V_100 . V_98 ;
V_188 = F_52 ( V_12 , & V_13 -> V_192 , V_98 , L_17 ) ;
if ( V_188 )
goto V_191;
V_98 = V_13 -> V_72 . V_97 . V_98 ;
V_188 = F_52 ( V_12 , & V_13 -> V_193 , V_98 , L_18 ) ;
if ( V_188 ) {
F_60 ( V_13 -> V_192 ) ;
goto V_191;
}
V_12 -> V_194 = F_61 ( V_13 -> V_152 . V_195 ? V_13 -> V_193 : V_13 -> V_192 ) ;
V_191:
F_51 ( & V_187 ) ;
return V_188 ;
}
static int F_62 ( struct V_10 * V_13 )
{
struct V_196 * V_197 = V_13 -> V_198 ;
unsigned int V_199 ;
V_129 V_200 , V_201 ;
struct V_202 * V_203 = F_63 ( V_197 -> V_204 ) ;
struct V_205 * V_206 = NULL ;
struct V_207 V_208 ;
int V_209 = 0 ;
V_201 = 0 ;
for ( V_199 = 0 ; V_199 < V_210 ( V_197 -> V_204 ) > > V_13 -> V_72 . V_96 ; V_199 ++ ) {
V_208 . V_211 = 0 ;
V_208 . V_212 = 0 ;
V_208 . V_213 = 1 << V_203 -> V_214 . V_215 ;
V_209 = F_64 ( V_197 -> V_204 , V_199 , & V_208 , 0 ) ;
V_200 = V_208 . V_212 ;
if ( V_209 || ! V_200 ) {
F_17 ( V_216 L_19
L_20 , V_209 , V_199 , ( unsigned long long ) V_200 ) ;
break;
}
if ( ! V_201 || V_200 != V_201 + 1 ) {
V_206 = F_4 ( sizeof( struct V_205 ) ,
V_16 ) ;
if ( ! V_206 ) {
F_17 ( V_216 L_21
L_22 ) ;
V_209 = - V_108 ;
break;
}
V_206 -> V_217 = V_200 ;
V_206 -> V_218 = V_199 ;
V_206 -> V_219 = 1 ;
F_65 ( & V_206 -> V_220 , & V_197 -> V_220 ) ;
} else {
V_206 -> V_219 ++ ;
}
V_201 = V_200 ;
}
return V_209 ;
}
static void F_66 ( struct V_10 * V_13 )
{
char * V_221 = L_23 ;
char * V_222 [] = { V_221 , NULL } ;
F_67 ( V_13 , L_24 ) ;
if ( V_13 -> V_223 . V_224 -> V_225 )
V_13 -> V_223 . V_224 -> V_225 ( V_13 ) ;
F_68 ( & V_13 -> V_226 , V_227 , V_222 ) ;
}
static int F_69 ( struct V_10 * V_13 , struct V_159 * V_228 )
{
struct V_202 * V_229 = F_63 ( V_13 -> V_230 ) ;
struct V_231 V_184 ;
char V_86 [ 20 ] ;
struct V_196 * V_197 ;
int error ;
V_184 . V_184 = V_86 ;
F_70 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_71 ( V_229 -> V_232 , V_170 , 0 , V_228 ) ;
if ( error )
break;
V_184 . V_233 = sprintf ( V_86 , L_25 , V_13 -> V_234 ) ;
V_184 . V_235 = F_72 ( V_184 . V_184 , V_184 . V_233 ) ;
error = F_73 ( V_13 -> V_230 , & V_184 , NULL ) ;
if ( error == - V_236 ) {
error = 0 ;
break;
}
F_51 ( V_228 ) ;
if ( error )
break;
error = - V_108 ;
V_197 = F_4 ( sizeof( struct V_196 ) , V_16 ) ;
if ( ! V_197 )
break;
F_11 ( & V_197 -> V_220 ) ;
F_74 ( & V_197 -> V_237 , V_238 ) ;
V_197 -> V_204 = F_75 ( V_13 -> V_230 , & V_184 , 1 ) ;
if ( ! V_197 -> V_204 || F_54 ( V_197 -> V_204 ) ) {
if ( ! V_197 -> V_204 )
error = - V_236 ;
else
error = F_55 ( V_197 -> V_204 ) ;
F_6 ( V_197 ) ;
break;
}
F_76 ( & V_13 -> V_33 ) ;
V_197 -> V_239 = V_13 -> V_234 ++ ;
F_65 ( & V_197 -> V_240 , & V_13 -> V_32 ) ;
F_77 ( & V_13 -> V_33 ) ;
}
F_78 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_79 ( struct V_10 * V_13 , struct V_196 * V_197 )
{
int error ;
struct V_159 V_241 ;
struct V_242 V_243 ;
struct V_202 * V_203 ;
V_203 = F_63 ( V_197 -> V_204 ) ;
error = F_71 ( V_203 -> V_232 , V_170 , V_166 |
V_171 | V_167 , & V_241 ) ;
if ( error ) {
F_41 ( V_13 , L_26 ) ;
return - V_244 ;
}
error = F_80 ( V_197 ) ;
if ( error ) {
F_41 ( V_13 , L_27 ) ;
goto V_245;
}
error = F_81 ( V_197 , & V_243 ) ;
if ( error ) {
F_41 ( V_13 , L_28 ) ;
goto V_245;
}
if ( ! ( V_243 . V_246 & V_247 ) ) {
error = - V_244 ;
F_41 ( V_13 , L_29
L_30 , V_197 -> V_239 ) ;
}
V_245:
F_51 ( & V_241 ) ;
return error ;
}
static int F_82 ( struct V_10 * V_13 , int V_161 )
{
struct V_185 * V_248 = V_13 -> V_193 -> V_249 ;
struct V_159 V_228 ;
struct V_202 * V_203 ;
int V_250 = 1 ;
int error = 0 ;
if ( V_161 ) {
V_250 = 0 ;
goto V_251;
}
V_13 -> V_230 = F_83 ( V_248 , L_31 ) ;
if ( F_54 ( V_13 -> V_230 ) ) {
F_41 ( V_13 , L_32 , error ) ;
return F_55 ( V_13 -> V_230 ) ;
}
error = F_69 ( V_13 , & V_228 ) ;
if ( error ) {
F_41 ( V_13 , L_33 , error ) ;
goto V_168;
}
error = - V_252 ;
if ( ! F_84 ( V_13 ) ) {
F_41 ( V_13 , L_34 ) ;
goto V_253;
}
if ( V_13 -> V_152 . V_254 ) {
V_13 -> V_198 = F_85 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_255 , V_13 -> V_198 -> V_256 ) ;
F_9 ( & V_13 -> V_257 , 2 * V_13 -> V_198 -> V_256 / 5 ) ;
F_9 ( & V_13 -> V_258 , 4 * V_13 -> V_198 -> V_256 / 5 ) ;
} else {
if ( V_13 -> V_223 . V_259 >= F_84 ( V_13 ) ) {
F_41 ( V_13 , L_35 ,
V_13 -> V_223 . V_259 ) ;
F_41 ( V_13 , L_36 ,
F_84 ( V_13 ) ,
F_84 ( V_13 ) - 1 ) ;
goto V_253;
}
V_13 -> V_198 = F_85 ( V_13 , V_13 -> V_223 . V_259 ) ;
error = F_48 ( V_13 , V_13 -> V_223 . V_259 ,
& V_260 ,
V_165 , V_166 ,
& V_13 -> V_261 ) ;
if ( error ) {
F_41 ( V_13 , L_37 , error ) ;
goto V_253;
}
V_203 = F_63 ( V_13 -> V_198 -> V_204 ) ;
error = F_71 ( V_203 -> V_232 , V_170 ,
V_166 | V_171 | V_167 ,
& V_13 -> V_262 ) ;
if ( error ) {
F_41 ( V_13 , L_38 ,
error ) ;
goto V_263;
}
error = F_80 ( V_13 -> V_198 ) ;
if ( error ) {
F_41 ( V_13 , L_39 ,
V_13 -> V_198 -> V_239 , error ) ;
goto V_251;
}
F_9 ( & V_13 -> V_255 , V_13 -> V_198 -> V_256 ) ;
F_9 ( & V_13 -> V_257 , 2 * V_13 -> V_198 -> V_256 / 5 ) ;
F_9 ( & V_13 -> V_258 , 4 * V_13 -> V_198 -> V_256 / 5 ) ;
F_62 ( V_13 ) ;
}
F_86 ( V_13 , F_87 ( & V_13 -> V_255 ) ) ;
if ( V_13 -> V_223 . V_264 ) {
unsigned int V_122 ;
for ( V_122 = 0 ; V_122 < V_13 -> V_234 ; V_122 ++ ) {
struct V_196 * V_197 = F_85 ( V_13 , V_122 ) ;
if ( V_13 -> V_152 . V_254 ) {
error = F_79 ( V_13 , V_197 ) ;
if ( error )
goto V_251;
continue;
}
error = F_88 ( V_197 , true ) ;
if ( error ) {
F_41 ( V_13 , L_40 ,
V_122 , error ) ;
goto V_251;
}
}
F_66 ( V_13 ) ;
} else if ( ! V_13 -> V_152 . V_254 ) {
error = F_88 ( V_13 -> V_198 , true ) ;
if ( error ) {
F_41 ( V_13 , L_41 , error ) ;
goto V_251;
}
}
F_7 ( V_265 , & V_13 -> V_22 ) ;
F_51 ( & V_228 ) ;
V_250 = 0 ;
return 0 ;
V_251:
if ( ! V_13 -> V_152 . V_254 )
F_51 ( & V_13 -> V_262 ) ;
V_263:
if ( ! V_13 -> V_152 . V_254 )
F_51 ( & V_13 -> V_261 ) ;
V_253:
F_89 ( V_13 ) ;
if ( V_250 )
F_51 ( & V_228 ) ;
V_168:
F_90 ( V_13 -> V_230 ) ;
return error ;
}
static int F_91 ( struct V_10 * V_13 , int V_161 )
{
int error = 0 ;
struct V_185 * V_248 = V_13 -> V_193 -> V_249 ;
if ( V_161 )
goto V_266;
error = F_82 ( V_13 , V_161 ) ;
if ( error )
goto V_168;
V_13 -> V_267 = F_83 ( V_248 , L_42 ) ;
if ( F_54 ( V_13 -> V_267 ) ) {
error = F_55 ( V_13 -> V_267 ) ;
F_41 ( V_13 , L_43 , error ) ;
goto V_268;
}
V_13 -> V_269 = F_83 ( V_248 , L_44 ) ;
if ( F_54 ( V_13 -> V_269 ) ) {
error = F_55 ( V_13 -> V_269 ) ;
F_41 ( V_13 , L_45 , error ) ;
goto V_270;
}
V_13 -> V_271 = 0 ;
V_13 -> V_272 = F_83 ( V_248 , L_46 ) ;
if ( F_54 ( V_13 -> V_272 ) ) {
error = F_55 ( V_13 -> V_272 ) ;
F_41 ( V_13 , L_47 , error ) ;
goto V_273;
}
F_92 ( & V_13 -> V_272 -> V_274 ,
& V_275 ) ;
error = F_93 ( V_13 ) ;
if ( error )
goto V_266;
return 0 ;
V_266:
F_90 ( V_13 -> V_272 ) ;
V_273:
F_94 ( V_13 ) ;
F_90 ( V_13 -> V_269 ) ;
V_270:
F_90 ( V_13 -> V_267 ) ;
V_268:
F_82 ( V_13 , V_276 ) ;
V_168:
return error ;
}
static int F_95 ( struct V_10 * V_13 , int V_161 )
{
struct V_185 * V_277 = NULL ;
char V_86 [ 30 ] ;
int error = 0 ;
struct V_202 * V_203 ;
struct V_185 * V_248 = V_13 -> V_193 -> V_249 ;
if ( V_13 -> V_152 . V_254 )
return 0 ;
if ( V_161 )
goto V_278;
V_277 = F_83 ( V_248 , L_48 ) ;
if ( F_54 ( V_277 ) ) {
error = F_55 ( V_277 ) ;
F_41 ( V_13 , L_49 , error ) ;
return error ;
}
sprintf ( V_86 , L_50 , V_13 -> V_198 -> V_239 ) ;
V_13 -> V_279 = F_83 ( V_277 , V_86 ) ;
if ( F_54 ( V_13 -> V_279 ) ) {
error = F_55 ( V_13 -> V_279 ) ;
F_41 ( V_13 , L_51 , error ) ;
goto V_168;
}
sprintf ( V_86 , L_52 , V_13 -> V_198 -> V_239 ) ;
V_13 -> V_280 = F_83 ( V_277 , V_86 ) ;
if ( F_54 ( V_13 -> V_280 ) ) {
error = F_55 ( V_13 -> V_280 ) ;
F_41 ( V_13 , L_53 , error ) ;
goto V_281;
}
F_90 ( V_277 ) ;
V_277 = NULL ;
V_203 = F_63 ( V_13 -> V_279 ) ;
error = F_71 ( V_203 -> V_232 , V_165 , 0 ,
& V_13 -> V_282 ) ;
if ( error ) {
F_41 ( V_13 , L_54 , error ) ;
goto V_283;
}
V_203 = F_63 ( V_13 -> V_280 ) ;
error = F_71 ( V_203 -> V_232 , V_165 , 0 ,
& V_13 -> V_284 ) ;
if ( error ) {
F_41 ( V_13 , L_55 , error ) ;
goto V_285;
}
return 0 ;
V_278:
F_51 ( & V_13 -> V_284 ) ;
V_285:
F_51 ( & V_13 -> V_282 ) ;
V_283:
F_90 ( V_13 -> V_280 ) ;
V_281:
F_90 ( V_13 -> V_279 ) ;
V_168:
if ( V_277 )
F_90 ( V_277 ) ;
return error ;
}
static int F_96 ( struct V_10 * V_13 , int V_70 )
{
const struct V_286 * V_287 ;
struct V_288 * V_289 = & V_13 -> V_223 ;
struct V_290 * args = & V_13 -> V_152 ;
const char * V_150 = V_13 -> V_156 ;
const char * V_151 = V_13 -> V_158 ;
char * V_291 , * V_292 ;
int V_188 ;
if ( ! strcmp ( L_56 , V_150 ) ) {
V_287 = & V_293 ;
V_13 -> V_152 . V_294 = 1 ;
#ifdef F_97
} else if ( ! strcmp ( L_57 , V_150 ) ) {
V_287 = & V_295 ;
#endif
} else {
F_17 ( V_216 L_58 , V_150 ) ;
return - V_236 ;
}
F_67 ( V_13 , L_59 , V_150 , V_151 ) ;
V_289 -> V_224 = V_287 ;
V_289 -> V_264 = 1 ;
for ( V_292 = args -> V_296 ; ( V_291 = F_98 ( & V_292 , L_60 ) ) ; ) {
T_3 V_297 [ V_298 ] ;
int V_299 , V_300 ;
if ( ! V_291 || ! * V_291 )
continue;
V_299 = F_99 ( V_291 , * V_287 -> V_301 , V_297 ) ;
switch ( V_299 ) {
case V_302 :
V_188 = F_100 ( & V_297 [ 0 ] , & V_300 ) ;
if ( V_188 || V_300 < 0 )
goto V_303;
if ( F_101 ( V_21 , & V_13 -> V_22 ) )
V_289 -> V_259 = V_300 ;
break;
case V_304 :
case V_305 :
break;
case V_306 :
V_188 = F_100 ( & V_297 [ 0 ] , & V_300 ) ;
if ( V_188 || ( V_300 != 0 && V_300 != 1 ) )
goto V_303;
V_289 -> V_264 = V_300 ;
break;
case V_307 :
default:
V_303:
F_67 ( V_13 , L_61 , V_291 ) ;
return - V_78 ;
}
}
if ( V_287 -> V_308 == NULL ) {
F_67 ( V_13 , L_62 ) ;
F_102 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_188 = V_287 -> V_308 ( V_13 , V_151 ) ;
if ( V_188 == 0 )
F_67 ( V_13 , L_63 ) ;
F_102 ( & V_13 -> V_26 ) ;
return V_188 ;
}
void F_103 ( struct V_10 * V_13 )
{
const struct V_286 * V_287 = V_13 -> V_223 . V_224 ;
if ( F_104 ( ! F_105 ( V_309 , & V_13 -> V_22 ) ) &&
V_287 -> V_310 )
V_287 -> V_310 ( V_13 ) ;
}
static int F_106 ( void * V_311 )
{
if ( F_107 ( V_312 ) )
return - V_313 ;
F_108 () ;
return 0 ;
}
static int F_109 ( struct V_10 * V_13 )
{
if ( V_13 -> V_223 . V_224 -> V_308 == NULL )
return 0 ;
return F_110 ( & V_13 -> V_22 , V_21 , F_106 , V_314 ) ;
}
void F_111 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_315 [ 20 ] ;
char V_316 [ 20 ] ;
char * V_222 [] = { V_315 , V_316 , NULL } ;
sprintf ( V_315 , L_64 , ( V_12 -> V_317 & V_318 ) ? 1 : 0 ) ;
sprintf ( V_316 , L_65 , V_13 -> V_152 . V_254 ? 1 : 0 ) ;
F_68 ( & V_13 -> V_226 , V_319 , V_222 ) ;
}
static int F_112 ( struct V_11 * V_12 , struct V_290 * args , int V_70 )
{
struct V_10 * V_13 ;
struct V_159 V_160 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( V_77 L_66 ) ;
return - V_108 ;
}
V_13 -> V_152 = * args ;
if ( V_13 -> V_152 . V_254 ) {
V_12 -> V_317 |= V_318 ;
F_7 ( V_320 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_152 . V_321 )
V_12 -> V_317 |= V_322 ;
if ( V_13 -> V_152 . V_323 )
F_7 ( V_324 , & V_13 -> V_22 ) ;
V_12 -> V_317 |= V_325 ;
V_12 -> V_326 = V_74 ;
V_12 -> V_327 = & V_328 ;
V_12 -> V_329 = & V_330 ;
V_12 -> V_331 = & V_332 ;
V_12 -> V_333 = V_334 ;
V_12 -> V_335 = & V_336 ;
F_113 ( V_12 ) -> V_48 |= V_337 ;
V_12 -> V_338 = 1 ;
V_12 -> V_339 = V_340 ;
V_13 -> V_72 . V_95 = F_114 ( V_12 , V_341 ) ;
V_13 -> V_72 . V_96 = V_12 -> V_342 ;
V_13 -> V_124 = V_13 -> V_72 . V_96 -
V_125 ;
V_13 -> V_126 = 1 << V_13 -> V_124 ;
V_13 -> V_23 . V_343 = V_13 -> V_152 . V_344 ;
V_13 -> V_23 . V_345 = V_13 -> V_152 . V_346 ;
if ( V_13 -> V_152 . V_347 ) {
V_13 -> V_23 . V_348 = 0 ;
V_13 -> V_23 . V_349 = V_13 -> V_152 . V_347 ;
} else {
V_13 -> V_23 . V_348 = 1 ;
V_13 -> V_23 . V_349 = 30 ;
}
error = F_45 ( V_13 , V_70 ) ;
if ( error ) {
F_115 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_350 , V_157 , L_67 , V_13 -> V_158 ) ;
error = F_116 ( V_13 ) ;
if ( error )
return error ;
F_117 ( V_13 ) ;
error = F_96 ( V_13 , V_70 ) ;
if ( error )
goto V_351;
error = F_47 ( V_13 , & V_160 , DO ) ;
if ( error )
goto V_352;
error = F_57 ( V_13 , V_70 ) ;
if ( error )
goto V_353;
error = F_109 ( V_13 ) ;
if ( error )
goto V_354;
if ( V_13 -> V_223 . V_259 < 0 ) {
error = V_13 -> V_223 . V_259 ;
V_13 -> V_223 . V_259 = 0 ;
goto V_354;
}
if ( V_13 -> V_152 . V_254 )
snprintf ( V_13 -> V_350 , V_157 , L_68 ,
V_13 -> V_158 ) ;
else
snprintf ( V_13 -> V_350 , V_157 , L_69 ,
V_13 -> V_158 , V_13 -> V_223 . V_259 ) ;
error = F_91 ( V_13 , DO ) ;
if ( error )
goto V_354;
error = F_95 ( V_13 , DO ) ;
if ( error )
goto V_355;
error = F_118 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_70 , error ) ;
goto V_356;
}
if ( ! ( V_12 -> V_317 & V_318 ) ) {
error = F_119 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_71 , error ) ;
goto V_356;
}
}
F_51 ( & V_160 ) ;
F_111 ( V_13 ) ;
return 0 ;
V_356:
F_95 ( V_13 , V_276 ) ;
V_355:
F_91 ( V_13 , V_276 ) ;
V_354:
if ( V_13 -> V_192 )
F_60 ( V_13 -> V_192 ) ;
if ( V_13 -> V_193 )
F_60 ( V_13 -> V_193 ) ;
if ( V_12 -> V_194 )
F_60 ( V_12 -> V_194 ) ;
V_12 -> V_194 = NULL ;
V_353:
F_47 ( V_13 , & V_160 , V_276 ) ;
V_352:
F_120 ( V_13 ) ;
F_103 ( V_13 ) ;
V_351:
F_121 ( V_13 ) ;
F_115 ( V_13 -> V_19 ) ;
F_122 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_123 ( struct V_11 * V_87 , void * V_357 )
{
V_87 -> V_46 = V_357 ;
V_87 -> V_358 = V_87 -> V_46 -> V_359 ;
V_87 -> V_52 = & F_124 ( V_87 -> V_46 ) -> V_51 ;
return 0 ;
}
static int F_125 ( struct V_11 * V_87 , void * V_360 )
{
struct V_361 * V_362 = V_360 ;
return ( V_362 == V_87 -> V_46 ) ;
}
static struct V_182 * F_126 ( struct V_363 * V_364 , int V_48 ,
const char * V_365 , void * V_357 )
{
struct V_361 * V_362 ;
struct V_11 * V_87 ;
T_4 V_366 = V_367 | V_368 ;
int error ;
struct V_290 args ;
struct V_10 * V_13 ;
if ( ! ( V_48 & V_318 ) )
V_366 |= V_369 ;
V_362 = F_127 ( V_365 , V_366 , V_364 ) ;
if ( F_54 ( V_362 ) )
return F_128 ( V_362 ) ;
F_70 ( & V_362 -> V_370 ) ;
if ( V_362 -> V_371 > 0 ) {
F_78 ( & V_362 -> V_370 ) ;
error = - V_372 ;
goto V_373;
}
V_87 = F_129 ( V_364 , F_125 , F_123 , V_48 , V_362 ) ;
F_78 ( & V_362 -> V_370 ) ;
error = F_55 ( V_87 ) ;
if ( F_54 ( V_87 ) )
goto V_373;
if ( V_87 -> V_194 ) {
F_130 ( & V_87 -> V_374 ) ;
F_131 ( V_362 , V_366 ) ;
F_132 ( & V_87 -> V_374 ) ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_375 = V_376 ;
args . V_377 = V_378 ;
args . V_344 = 30 ;
args . V_347 = 30 ;
args . V_346 = 60 ;
args . V_379 = V_380 ;
error = F_133 ( & args , V_357 ) ;
if ( error ) {
F_17 ( V_77 L_72 ) ;
goto V_381;
}
if ( V_87 -> V_194 ) {
error = - V_372 ;
if ( ( V_48 ^ V_87 -> V_317 ) & V_318 )
goto V_381;
} else {
char V_382 [ V_383 ] ;
V_87 -> V_384 = V_366 ;
F_46 ( V_87 -> V_155 , F_134 ( V_362 , V_382 ) , sizeof( V_87 -> V_155 ) ) ;
F_59 ( V_87 , F_135 ( V_362 ) ) ;
error = F_112 ( V_87 , & args , V_48 & V_385 ? 1 : 0 ) ;
if ( error )
goto V_381;
V_87 -> V_317 |= V_386 ;
V_362 -> V_387 = V_87 ;
}
V_13 = V_87 -> V_17 ;
if ( args . V_195 )
return F_61 ( V_13 -> V_193 ) ;
else
return F_61 ( V_13 -> V_192 ) ;
V_381:
F_136 ( V_87 ) ;
return F_137 ( error ) ;
V_373:
F_131 ( V_362 , V_366 ) ;
return F_137 ( error ) ;
}
static int F_138 ( struct V_11 * V_87 , void * V_360 )
{
return - V_78 ;
}
static struct V_182 * F_139 ( struct V_363 * V_364 ,
int V_48 , const char * V_365 , void * V_357 )
{
struct V_11 * V_87 ;
struct V_10 * V_13 ;
struct V_388 V_388 ;
int error ;
error = F_140 ( V_365 , V_389 , & V_388 ) ;
if ( error ) {
F_17 ( V_77 L_73 ,
V_365 , error ) ;
return F_137 ( error ) ;
}
V_87 = F_129 ( & V_390 , F_125 , F_138 , V_48 ,
V_388 . V_182 -> V_249 -> V_391 -> V_46 ) ;
F_141 ( & V_388 ) ;
if ( F_54 ( V_87 ) ) {
F_17 ( V_77 L_74 ) ;
return F_128 ( V_87 ) ;
}
if ( ( V_48 ^ V_87 -> V_317 ) & V_318 ) {
F_136 ( V_87 ) ;
return F_137 ( - V_372 ) ;
}
V_13 = V_87 -> V_17 ;
return F_61 ( V_13 -> V_193 ) ;
}
static void F_142 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_143 ( V_12 ) ;
return;
}
F_144 ( V_13 ) ;
F_60 ( V_13 -> V_192 ) ;
F_60 ( V_13 -> V_193 ) ;
V_13 -> V_192 = NULL ;
V_13 -> V_193 = NULL ;
F_145 ( V_12 ) ;
F_121 ( V_13 ) ;
F_115 ( V_13 -> V_19 ) ;
F_143 ( V_12 ) ;
}
