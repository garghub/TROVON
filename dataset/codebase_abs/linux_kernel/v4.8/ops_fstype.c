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
F_10 ( & V_13 -> V_35 ) ;
F_11 ( & V_13 -> V_36 ) ;
F_12 ( & V_13 -> V_37 ) ;
F_12 ( & V_13 -> V_38 ) ;
F_8 ( & V_13 -> V_39 ) ;
F_11 ( & V_13 -> V_40 ) ;
F_2 ( & V_13 -> V_41 ) ;
F_2 ( & V_13 -> V_42 ) ;
V_15 = & V_13 -> V_43 ;
F_13 ( V_15 ) ;
V_15 -> V_44 = & V_45 ;
V_15 -> V_46 = V_12 -> V_47 -> V_48 ;
V_15 -> V_49 = 0 ;
F_14 ( V_15 , V_50 ) ;
V_15 -> V_51 = NULL ;
V_15 -> V_52 = 0 ;
F_2 ( & V_13 -> V_53 ) ;
F_9 ( & V_13 -> V_54 , 0 ) ;
F_11 ( & V_13 -> V_55 ) ;
F_11 ( & V_13 -> V_56 ) ;
F_2 ( & V_13 -> V_57 ) ;
F_8 ( & V_13 -> V_58 ) ;
F_8 ( & V_13 -> V_59 ) ;
F_2 ( & V_13 -> V_60 ) ;
F_11 ( & V_13 -> V_61 ) ;
F_11 ( & V_13 -> V_62 ) ;
F_15 ( & V_13 -> V_63 ) ;
F_9 ( & V_13 -> V_64 , 0 ) ;
F_9 ( & V_13 -> V_65 , 0 ) ;
F_8 ( & V_13 -> V_66 ) ;
F_8 ( & V_13 -> V_67 ) ;
F_9 ( & V_13 -> V_68 , V_69 ) ;
F_12 ( & V_13 -> V_70 ) ;
return V_13 ;
}
static int F_16 ( struct V_10 * V_13 , int V_71 )
{
struct V_72 * V_12 = & V_13 -> V_73 ;
if ( V_12 -> V_74 != V_75 ||
V_12 -> V_76 != V_77 ) {
if ( ! V_71 )
F_17 ( L_1 ) ;
return - V_78 ;
}
if ( V_12 -> V_79 == V_80 &&
V_12 -> V_81 == V_82 )
return 0 ;
F_18 ( V_13 , L_2 ) ;
return - V_78 ;
}
static void F_19 ( struct V_83 * V_83 )
{
struct V_84 * V_84 = V_83 -> V_85 ;
if ( ! V_83 -> V_86 )
F_20 ( V_84 ) ;
else
F_17 ( L_3 , V_83 -> V_86 ) ;
F_21 ( V_84 ) ;
}
static void F_22 ( struct V_10 * V_13 , const void * V_87 )
{
struct V_72 * V_12 = & V_13 -> V_73 ;
struct V_11 * V_88 = V_13 -> V_18 ;
const struct V_89 * V_90 = V_87 ;
V_12 -> V_74 = F_23 ( V_90 -> V_91 . V_92 ) ;
V_12 -> V_76 = F_23 ( V_90 -> V_91 . V_93 ) ;
V_12 -> V_94 = F_23 ( V_90 -> V_91 . V_95 ) ;
V_12 -> V_79 = F_23 ( V_90 -> V_79 ) ;
V_12 -> V_81 = F_23 ( V_90 -> V_81 ) ;
V_12 -> V_96 = F_23 ( V_90 -> V_96 ) ;
V_12 -> V_97 = F_23 ( V_90 -> V_97 ) ;
V_12 -> V_98 . V_99 = F_24 ( V_90 -> V_98 . V_99 ) ;
V_12 -> V_98 . V_100 = F_24 ( V_90 -> V_98 . V_100 ) ;
V_12 -> V_101 . V_99 = F_24 ( V_90 -> V_101 . V_99 ) ;
V_12 -> V_101 . V_100 = F_24 ( V_90 -> V_101 . V_100 ) ;
memcpy ( V_12 -> V_102 , V_90 -> V_102 , V_103 ) ;
memcpy ( V_12 -> V_104 , V_90 -> V_104 , V_103 ) ;
memcpy ( V_88 -> V_105 , V_90 -> V_106 , 16 ) ;
}
static int F_25 ( struct V_10 * V_13 , T_1 V_107 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_89 * V_108 ;
struct V_84 * V_84 ;
struct V_83 * V_83 ;
V_84 = F_26 ( V_50 ) ;
if ( F_27 ( ! V_84 ) )
return - V_109 ;
F_28 ( V_84 ) ;
F_29 ( V_84 ) ;
F_30 ( V_84 ) ;
V_83 = F_31 ( V_50 , 1 ) ;
V_83 -> V_110 . V_111 = V_107 * ( V_12 -> V_112 >> 9 ) ;
V_83 -> V_113 = V_12 -> V_47 ;
F_32 ( V_83 , V_84 , V_114 , 0 ) ;
V_83 -> V_115 = F_19 ;
V_83 -> V_85 = V_84 ;
F_33 ( V_83 , V_116 , V_117 | V_118 ) ;
F_34 ( V_83 ) ;
F_35 ( V_84 ) ;
F_36 ( V_83 ) ;
if ( ! F_37 ( V_84 ) ) {
F_38 ( V_84 ) ;
return - V_119 ;
}
V_108 = F_39 ( V_84 ) ;
F_22 ( V_13 , V_108 ) ;
F_40 ( V_84 ) ;
F_38 ( V_84 ) ;
return F_16 ( V_13 , V_71 ) ;
}
static int F_41 ( struct V_10 * V_13 , int V_71 )
{
T_2 V_120 , V_121 , V_122 ;
T_2 V_123 ;
unsigned int V_124 ;
int error ;
error = F_25 ( V_13 , V_125 >> V_13 -> V_126 , V_71 ) ;
if ( error ) {
if ( ! V_71 )
F_42 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_126 = V_13 -> V_73 . V_97 -
V_127 ;
V_13 -> V_128 = 1 << V_13 -> V_126 ;
V_13 -> V_129 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_130 ) ) / sizeof( V_131 ) ;
V_13 -> V_132 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_133 ) ) / sizeof( V_131 ) ;
V_13 -> V_134 = V_13 -> V_73 . V_96 - sizeof( struct V_133 ) ;
V_13 -> V_135 = V_13 -> V_73 . V_96 / 2 ;
V_13 -> V_136 = V_13 -> V_73 . V_97 - 1 ;
V_13 -> V_137 = V_13 -> V_135 / sizeof( V_131 ) ;
V_13 -> V_138 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_133 ) ) /
sizeof( struct V_139 ) ;
V_13 -> V_140 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_133 ) )
* V_141 ;
V_120 = F_43 ( sizeof( V_131 ) * ( 1 << V_142 ) ,
V_13 -> V_134 ) ;
V_121 = 0 ;
for ( V_123 = V_120 ; V_123 > V_13 -> V_129 ; ) {
V_123 = F_43 ( V_123 , V_13 -> V_132 ) ;
V_121 += V_123 ;
}
V_122 = 2 + V_142 ;
V_13 -> V_143 = V_120 + V_121 + V_122 ;
V_13 -> V_144 [ 0 ] = V_13 -> V_73 . V_96 -
sizeof( struct V_130 ) ;
V_13 -> V_144 [ 1 ] = V_13 -> V_73 . V_96 * V_13 -> V_129 ;
for ( V_124 = 2 ; ; V_124 ++ ) {
V_131 V_145 , V_146 ;
T_2 V_147 ;
V_145 = V_13 -> V_144 [ V_124 - 1 ] * V_13 -> V_132 ;
V_146 = V_145 ;
V_147 = F_44 ( V_146 , V_13 -> V_132 ) ;
if ( V_146 != V_13 -> V_144 [ V_124 - 1 ] || V_147 )
break;
V_13 -> V_144 [ V_124 ] = V_145 ;
}
V_13 -> V_148 = V_124 ;
V_13 -> V_144 [ V_124 ] = ~ 0 ;
F_45 ( V_13 , V_13 -> V_148 <= V_149 ) ;
V_13 -> V_150 [ 0 ] = V_13 -> V_73 . V_96 -
sizeof( struct V_130 ) ;
V_13 -> V_150 [ 1 ] = V_13 -> V_134 * V_13 -> V_129 ;
for ( V_124 = 2 ; ; V_124 ++ ) {
V_131 V_145 , V_146 ;
T_2 V_147 ;
V_145 = V_13 -> V_150 [ V_124 - 1 ] * V_13 -> V_132 ;
V_146 = V_145 ;
V_147 = F_44 ( V_146 , V_13 -> V_132 ) ;
if ( V_146 != V_13 -> V_150 [ V_124 - 1 ] || V_147 )
break;
V_13 -> V_150 [ V_124 ] = V_145 ;
}
V_13 -> V_151 = V_124 ;
V_13 -> V_150 [ V_124 ] = ~ 0 ;
F_45 ( V_13 , V_13 -> V_151 <= V_149 ) ;
V_13 -> V_152 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_153 ) ) /
V_154 ;
return 0 ;
}
static int F_46 ( struct V_10 * V_13 , int V_71 )
{
char * V_155 , * V_156 ;
int error = 0 ;
V_155 = V_13 -> V_157 . V_158 ;
V_156 = V_13 -> V_157 . V_159 ;
if ( ! V_155 [ 0 ] || ! V_156 [ 0 ] ) {
error = F_25 ( V_13 , V_125 >> V_13 -> V_126 , V_71 ) ;
if ( error )
return error ;
if ( ! V_155 [ 0 ] )
V_155 = V_13 -> V_73 . V_102 ;
if ( ! V_156 [ 0 ] )
V_156 = V_13 -> V_73 . V_104 ;
}
if ( ! V_156 [ 0 ] )
V_156 = V_13 -> V_18 -> V_160 ;
F_47 ( V_13 -> V_161 , V_155 , V_162 ) ;
F_47 ( V_13 -> V_163 , V_156 , V_162 ) ;
V_156 = V_13 -> V_163 ;
while ( ( V_156 = strchr ( V_156 , '/' ) ) )
* V_156 = '_' ;
return error ;
}
static int F_48 ( struct V_10 * V_13 , struct V_164 * V_165 ,
int V_166 )
{
int error = 0 ;
if ( V_166 )
goto V_167;
error = F_49 ( V_13 ,
V_168 , & V_169 ,
V_170 , V_171 | V_172 ,
V_165 ) ;
if ( error ) {
F_42 ( V_13 , L_5 , error ) ;
goto V_173;
}
error = F_49 ( V_13 ,
V_174 , & V_169 ,
V_175 ,
V_171 | V_176 ,
& V_13 -> V_177 ) ;
if ( error ) {
F_42 ( V_13 , L_6 , error ) ;
goto V_178;
}
error = F_50 ( V_13 , V_179 , & V_169 ,
V_180 , & V_13 -> V_181 ) ;
if ( error ) {
F_42 ( V_13 , L_7 , error ) ;
goto V_182;
}
error = F_50 ( V_13 , V_183 , & V_184 ,
V_180 , & V_13 -> V_185 ) ;
if ( error ) {
F_42 ( V_13 , L_8 , error ) ;
goto V_186;
}
return 0 ;
V_167:
F_51 ( V_13 -> V_185 ) ;
V_186:
F_51 ( V_13 -> V_181 ) ;
V_182:
F_52 ( & V_13 -> V_177 ) ;
V_178:
F_52 ( V_165 ) ;
V_173:
return error ;
}
static int F_53 ( struct V_11 * V_12 , struct V_187 * * V_188 ,
V_131 V_99 , const char * V_189 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_187 * V_187 ;
struct V_190 * V_190 ;
V_190 = F_54 ( V_12 , V_191 , V_99 , 0 ,
V_192 ) ;
if ( F_55 ( V_190 ) ) {
F_42 ( V_13 , L_9 , V_189 , F_56 ( V_190 ) ) ;
return F_56 ( V_190 ) ;
}
V_187 = F_57 ( V_190 ) ;
if ( ! V_187 ) {
F_42 ( V_13 , L_10 , V_189 ) ;
return - V_109 ;
}
* V_188 = V_187 ;
return 0 ;
}
static int F_58 ( struct V_10 * V_13 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_164 V_193 ;
V_131 V_99 ;
int V_194 ;
V_194 = F_49 ( V_13 , V_195 , & V_196 ,
V_175 , 0 , & V_193 ) ;
if ( V_194 ) {
F_42 ( V_13 , L_11 , V_194 ) ;
return V_194 ;
}
V_194 = F_41 ( V_13 , V_71 ) ;
if ( V_194 ) {
F_42 ( V_13 , L_12 , V_194 ) ;
goto V_197;
}
if ( V_13 -> V_73 . V_96 < F_59 ( V_12 -> V_47 ) ) {
V_194 = - V_78 ;
F_42 ( V_13 , L_13
L_14 ,
V_13 -> V_73 . V_96 , F_59 ( V_12 -> V_47 ) ) ;
goto V_197;
}
if ( V_13 -> V_73 . V_96 > V_114 ) {
V_194 = - V_78 ;
F_42 ( V_13 , L_15
L_16 ,
V_13 -> V_73 . V_96 , ( unsigned int ) V_114 ) ;
goto V_197;
}
F_60 ( V_12 , V_13 -> V_73 . V_96 ) ;
V_99 = V_13 -> V_73 . V_101 . V_99 ;
V_194 = F_53 ( V_12 , & V_13 -> V_198 , V_99 , L_17 ) ;
if ( V_194 )
goto V_197;
V_99 = V_13 -> V_73 . V_98 . V_99 ;
V_194 = F_53 ( V_12 , & V_13 -> V_199 , V_99 , L_18 ) ;
if ( V_194 ) {
F_61 ( V_13 -> V_198 ) ;
goto V_197;
}
V_12 -> V_200 = F_62 ( V_13 -> V_157 . V_201 ? V_13 -> V_199 : V_13 -> V_198 ) ;
V_197:
F_52 ( & V_193 ) ;
return V_194 ;
}
static void F_63 ( struct V_10 * V_13 )
{
char * V_202 = L_19 ;
char * V_203 [] = { V_202 , NULL } ;
F_64 ( V_13 , L_20 ) ;
if ( V_13 -> V_204 . V_205 -> V_206 )
V_13 -> V_204 . V_205 -> V_206 ( V_13 ) ;
F_65 ( & V_13 -> V_207 , V_208 , V_203 ) ;
}
static int F_66 ( struct V_10 * V_13 , struct V_164 * V_209 )
{
struct V_210 * V_211 = F_67 ( V_13 -> V_212 ) ;
struct V_213 V_189 ;
char V_87 [ 20 ] ;
struct V_214 * V_215 ;
int error ;
V_189 . V_189 = V_87 ;
F_68 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_69 ( V_211 -> V_216 , V_175 , 0 , V_209 ) ;
if ( error )
break;
V_189 . V_217 = sprintf ( V_87 , L_21 , V_13 -> V_218 ) ;
V_189 . V_219 = F_70 ( V_189 . V_189 , V_189 . V_217 ) ;
error = F_71 ( V_13 -> V_212 , & V_189 , NULL ) ;
if ( error == - V_220 ) {
error = 0 ;
break;
}
F_52 ( V_209 ) ;
if ( error )
break;
error = - V_109 ;
V_215 = F_4 ( sizeof( struct V_214 ) , V_16 ) ;
if ( ! V_215 )
break;
F_11 ( & V_215 -> V_221 ) ;
F_11 ( & V_215 -> V_222 ) ;
F_72 ( & V_215 -> V_223 , V_224 ) ;
V_215 -> V_225 = F_73 ( V_13 -> V_212 , & V_189 , 1 ) ;
if ( ! V_215 -> V_225 || F_55 ( V_215 -> V_225 ) ) {
if ( ! V_215 -> V_225 )
error = - V_220 ;
else
error = F_56 ( V_215 -> V_225 ) ;
F_6 ( V_215 ) ;
break;
}
F_74 ( & V_13 -> V_33 ) ;
V_215 -> V_226 = V_13 -> V_218 ++ ;
F_75 ( & V_215 -> V_227 , & V_13 -> V_32 ) ;
F_76 ( & V_13 -> V_33 ) ;
}
F_77 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_78 ( struct V_10 * V_13 , struct V_214 * V_215 )
{
int error ;
struct V_164 V_228 ;
struct V_229 V_230 ;
struct V_210 * V_231 ;
V_231 = F_67 ( V_215 -> V_225 ) ;
error = F_69 ( V_231 -> V_216 , V_175 , V_171 |
V_176 | V_172 , & V_228 ) ;
if ( error ) {
F_42 ( V_13 , L_22 ) ;
return - V_232 ;
}
error = F_79 ( V_215 ) ;
if ( error ) {
F_42 ( V_13 , L_23 ) ;
goto V_233;
}
error = F_80 ( V_215 , & V_230 ) ;
if ( error ) {
F_42 ( V_13 , L_24 ) ;
goto V_233;
}
if ( ! ( V_230 . V_234 & V_235 ) ) {
error = - V_232 ;
F_42 ( V_13 , L_25
L_26 , V_215 -> V_226 ) ;
}
V_233:
F_52 ( & V_228 ) ;
return error ;
}
static int F_81 ( struct V_10 * V_13 , int V_166 )
{
struct V_190 * V_236 = F_82 ( V_13 -> V_199 ) ;
struct V_164 V_209 ;
struct V_210 * V_231 ;
int V_237 = 1 ;
int error = 0 ;
if ( V_166 ) {
V_237 = 0 ;
goto V_238;
}
V_13 -> V_212 = F_83 ( V_236 , L_27 ) ;
if ( F_55 ( V_13 -> V_212 ) ) {
F_42 ( V_13 , L_28 , error ) ;
return F_56 ( V_13 -> V_212 ) ;
}
error = F_66 ( V_13 , & V_209 ) ;
if ( error ) {
F_42 ( V_13 , L_29 , error ) ;
goto V_173;
}
error = - V_239 ;
if ( ! F_84 ( V_13 ) ) {
F_42 ( V_13 , L_30 ) ;
goto V_240;
}
if ( V_13 -> V_157 . V_241 ) {
V_13 -> V_242 = F_85 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_243 , V_13 -> V_242 -> V_244 ) ;
F_9 ( & V_13 -> V_245 , 2 * V_13 -> V_242 -> V_244 / 5 ) ;
F_9 ( & V_13 -> V_246 , 4 * V_13 -> V_242 -> V_244 / 5 ) ;
} else {
if ( V_13 -> V_204 . V_247 >= F_84 ( V_13 ) ) {
F_42 ( V_13 , L_31 ,
V_13 -> V_204 . V_247 ) ;
F_42 ( V_13 , L_32 ,
F_84 ( V_13 ) ,
F_84 ( V_13 ) - 1 ) ;
goto V_240;
}
V_13 -> V_242 = F_85 ( V_13 , V_13 -> V_204 . V_247 ) ;
error = F_49 ( V_13 , V_13 -> V_204 . V_247 ,
& V_248 ,
V_170 , V_171 ,
& V_13 -> V_249 ) ;
if ( error ) {
F_42 ( V_13 , L_33 , error ) ;
goto V_240;
}
V_231 = F_67 ( V_13 -> V_242 -> V_225 ) ;
error = F_69 ( V_231 -> V_216 , V_175 ,
V_171 | V_176 | V_172 ,
& V_13 -> V_250 ) ;
if ( error ) {
F_42 ( V_13 , L_34 ,
error ) ;
goto V_251;
}
error = F_79 ( V_13 -> V_242 ) ;
if ( error ) {
F_42 ( V_13 , L_35 ,
V_13 -> V_242 -> V_226 , error ) ;
goto V_238;
}
F_9 ( & V_13 -> V_243 , V_13 -> V_242 -> V_244 ) ;
F_9 ( & V_13 -> V_245 , 2 * V_13 -> V_242 -> V_244 / 5 ) ;
F_9 ( & V_13 -> V_246 , 4 * V_13 -> V_242 -> V_244 / 5 ) ;
F_86 ( V_13 , V_13 -> V_242 ) ;
}
F_87 ( V_13 , F_88 ( & V_13 -> V_243 ) ) ;
if ( V_13 -> V_204 . V_252 ) {
unsigned int V_124 ;
for ( V_124 = 0 ; V_124 < V_13 -> V_218 ; V_124 ++ ) {
struct V_214 * V_215 = F_85 ( V_13 , V_124 ) ;
if ( V_13 -> V_157 . V_241 ) {
error = F_78 ( V_13 , V_215 ) ;
if ( error )
goto V_238;
continue;
}
error = F_89 ( V_215 , true ) ;
if ( error ) {
F_42 ( V_13 , L_36 ,
V_124 , error ) ;
goto V_238;
}
}
F_63 ( V_13 ) ;
} else if ( ! V_13 -> V_157 . V_241 ) {
error = F_89 ( V_13 -> V_242 , true ) ;
if ( error ) {
F_42 ( V_13 , L_37 , error ) ;
goto V_238;
}
}
V_13 -> V_253 = 1 ;
F_7 ( V_254 , & V_13 -> V_22 ) ;
F_52 ( & V_209 ) ;
V_237 = 0 ;
F_72 ( & V_13 -> V_255 , V_256 ) ;
return 0 ;
V_238:
if ( ! V_13 -> V_157 . V_241 )
F_52 ( & V_13 -> V_250 ) ;
V_251:
if ( ! V_13 -> V_157 . V_241 )
F_52 ( & V_13 -> V_249 ) ;
V_240:
F_90 ( V_13 ) ;
if ( V_237 )
F_52 ( & V_209 ) ;
V_173:
F_91 ( V_13 -> V_212 ) ;
return error ;
}
static int F_92 ( struct V_10 * V_13 , int V_166 )
{
int error = 0 ;
struct V_190 * V_236 = F_82 ( V_13 -> V_199 ) ;
if ( V_166 )
goto V_257;
error = F_81 ( V_13 , V_166 ) ;
F_93 ( & V_13 -> V_35 ) ;
if ( error )
goto V_173;
V_13 -> V_258 = F_83 ( V_236 , L_38 ) ;
if ( F_55 ( V_13 -> V_258 ) ) {
error = F_56 ( V_13 -> V_258 ) ;
F_42 ( V_13 , L_39 , error ) ;
goto V_259;
}
V_13 -> V_260 = F_83 ( V_236 , L_40 ) ;
if ( F_55 ( V_13 -> V_260 ) ) {
error = F_56 ( V_13 -> V_260 ) ;
F_42 ( V_13 , L_41 , error ) ;
goto V_261;
}
V_13 -> V_262 = 0 ;
V_13 -> V_263 = F_83 ( V_236 , L_42 ) ;
if ( F_55 ( V_13 -> V_263 ) ) {
error = F_56 ( V_13 -> V_263 ) ;
F_42 ( V_13 , L_43 , error ) ;
goto V_264;
}
F_94 ( & V_13 -> V_263 -> V_265 ,
& V_266 ) ;
error = F_95 ( V_13 ) ;
if ( error )
goto V_257;
return 0 ;
V_257:
F_91 ( V_13 -> V_263 ) ;
V_264:
F_96 ( V_13 ) ;
F_91 ( V_13 -> V_260 ) ;
V_261:
F_91 ( V_13 -> V_258 ) ;
V_259:
F_81 ( V_13 , V_267 ) ;
V_173:
return error ;
}
static int F_97 ( struct V_10 * V_13 , int V_166 )
{
struct V_190 * V_268 = NULL ;
char V_87 [ 30 ] ;
int error = 0 ;
struct V_210 * V_231 ;
struct V_190 * V_236 = F_82 ( V_13 -> V_199 ) ;
if ( V_13 -> V_157 . V_241 )
return 0 ;
if ( V_166 )
goto V_269;
V_268 = F_83 ( V_236 , L_44 ) ;
if ( F_55 ( V_268 ) ) {
error = F_56 ( V_268 ) ;
F_42 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_87 , L_46 , V_13 -> V_242 -> V_226 ) ;
V_13 -> V_270 = F_83 ( V_268 , V_87 ) ;
if ( F_55 ( V_13 -> V_270 ) ) {
error = F_56 ( V_13 -> V_270 ) ;
F_42 ( V_13 , L_47 , error ) ;
goto V_173;
}
sprintf ( V_87 , L_48 , V_13 -> V_242 -> V_226 ) ;
V_13 -> V_271 = F_83 ( V_268 , V_87 ) ;
if ( F_55 ( V_13 -> V_271 ) ) {
error = F_56 ( V_13 -> V_271 ) ;
F_42 ( V_13 , L_49 , error ) ;
goto V_272;
}
F_91 ( V_268 ) ;
V_268 = NULL ;
V_231 = F_67 ( V_13 -> V_270 ) ;
error = F_69 ( V_231 -> V_216 , V_170 , 0 ,
& V_13 -> V_273 ) ;
if ( error ) {
F_42 ( V_13 , L_50 , error ) ;
goto V_274;
}
V_231 = F_67 ( V_13 -> V_271 ) ;
error = F_69 ( V_231 -> V_216 , V_170 , 0 ,
& V_13 -> V_275 ) ;
if ( error ) {
F_42 ( V_13 , L_51 , error ) ;
goto V_276;
}
return 0 ;
V_269:
F_52 ( & V_13 -> V_275 ) ;
V_276:
F_52 ( & V_13 -> V_273 ) ;
V_274:
F_91 ( V_13 -> V_271 ) ;
V_272:
F_91 ( V_13 -> V_270 ) ;
V_173:
F_91 ( V_268 ) ;
return error ;
}
static int F_98 ( struct V_10 * V_13 , int V_71 )
{
const struct V_277 * V_278 ;
struct V_279 * V_280 = & V_13 -> V_204 ;
struct V_281 * args = & V_13 -> V_157 ;
const char * V_155 = V_13 -> V_161 ;
const char * V_156 = V_13 -> V_163 ;
char * V_282 , * V_283 ;
int V_194 ;
if ( ! strcmp ( L_52 , V_155 ) ) {
V_278 = & V_284 ;
V_13 -> V_157 . V_285 = 1 ;
#ifdef F_99
} else if ( ! strcmp ( L_53 , V_155 ) ) {
V_278 = & V_286 ;
#endif
} else {
F_100 ( L_54 , V_155 ) ;
return - V_220 ;
}
F_64 ( V_13 , L_55 , V_155 , V_156 ) ;
V_280 -> V_205 = V_278 ;
V_280 -> V_252 = 1 ;
for ( V_283 = args -> V_287 ; ( V_282 = F_101 ( & V_283 , L_56 ) ) ; ) {
T_3 V_288 [ V_289 ] ;
int V_290 , V_291 ;
if ( ! V_282 || ! * V_282 )
continue;
V_290 = F_102 ( V_282 , * V_278 -> V_292 , V_288 ) ;
switch ( V_290 ) {
case V_293 :
V_194 = F_103 ( & V_288 [ 0 ] , & V_291 ) ;
if ( V_194 || V_291 < 0 )
goto V_294;
if ( F_104 ( V_21 , & V_13 -> V_22 ) )
V_280 -> V_247 = V_291 ;
break;
case V_295 :
case V_296 :
break;
case V_297 :
V_194 = F_103 ( & V_288 [ 0 ] , & V_291 ) ;
if ( V_194 || ( V_291 != 0 && V_291 != 1 ) )
goto V_294;
V_280 -> V_252 = V_291 ;
break;
case V_298 :
default:
V_294:
F_64 ( V_13 , L_57 , V_282 ) ;
return - V_78 ;
}
}
if ( V_278 -> V_299 == NULL ) {
F_64 ( V_13 , L_58 ) ;
F_93 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_194 = V_278 -> V_299 ( V_13 , V_156 ) ;
if ( V_194 == 0 )
F_64 ( V_13 , L_59 ) ;
F_93 ( & V_13 -> V_26 ) ;
return V_194 ;
}
void F_105 ( struct V_10 * V_13 )
{
const struct V_277 * V_278 = V_13 -> V_204 . V_205 ;
if ( F_106 ( ! F_107 ( V_300 , & V_13 -> V_22 ) ) &&
V_278 -> V_301 )
V_278 -> V_301 ( V_13 ) ;
}
static int F_108 ( struct V_10 * V_13 )
{
if ( V_13 -> V_204 . V_205 -> V_299 == NULL )
return 0 ;
return F_109 ( & V_13 -> V_22 , V_21 , V_302 )
? - V_303 : 0 ;
}
void F_110 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_304 [ 20 ] ;
char V_305 [ 20 ] ;
char * V_203 [] = { V_304 , V_305 , NULL } ;
sprintf ( V_304 , L_60 , ( V_12 -> V_306 & V_307 ) ? 1 : 0 ) ;
sprintf ( V_305 , L_61 , V_13 -> V_157 . V_241 ? 1 : 0 ) ;
F_65 ( & V_13 -> V_207 , V_308 , V_203 ) ;
}
static int F_111 ( struct V_11 * V_12 , struct V_281 * args , int V_71 )
{
struct V_10 * V_13 ;
struct V_164 V_165 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( L_62 ) ;
return - V_109 ;
}
V_13 -> V_157 = * args ;
if ( V_13 -> V_157 . V_241 ) {
V_12 -> V_306 |= V_307 ;
F_7 ( V_309 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_157 . V_310 )
V_12 -> V_306 |= V_311 ;
if ( V_13 -> V_157 . V_312 )
F_7 ( V_313 , & V_13 -> V_22 ) ;
V_12 -> V_306 |= V_314 ;
V_12 -> V_315 = V_75 ;
V_12 -> V_316 = & V_317 ;
V_12 -> V_318 = & V_319 ;
V_12 -> V_320 = & V_321 ;
V_12 -> V_322 = V_323 ;
V_12 -> V_324 = & V_325 ;
V_12 -> V_326 = V_327 | V_328 ;
F_112 ( V_12 ) -> V_49 |= V_329 ;
V_12 -> V_330 = 1 ;
V_12 -> V_331 = V_332 ;
V_13 -> V_73 . V_96 = F_113 ( V_12 , V_333 ) ;
V_13 -> V_73 . V_97 = V_12 -> V_334 ;
V_13 -> V_126 = V_13 -> V_73 . V_97 -
V_127 ;
V_13 -> V_128 = 1 << V_13 -> V_126 ;
V_13 -> V_23 . V_335 = V_13 -> V_157 . V_336 ;
V_13 -> V_23 . V_337 = V_13 -> V_157 . V_338 ;
if ( V_13 -> V_157 . V_339 ) {
V_13 -> V_23 . V_340 = 0 ;
V_13 -> V_23 . V_341 = V_13 -> V_157 . V_339 ;
} else {
V_13 -> V_23 . V_340 = 1 ;
V_13 -> V_23 . V_341 = 30 ;
}
error = F_46 ( V_13 , V_71 ) ;
if ( error ) {
F_114 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_342 , V_162 , L_63 , V_13 -> V_163 ) ;
error = F_115 ( V_13 ) ;
if ( error )
return error ;
F_116 ( V_13 ) ;
error = F_98 ( V_13 , V_71 ) ;
if ( error )
goto V_343;
error = F_48 ( V_13 , & V_165 , DO ) ;
if ( error )
goto V_344;
error = F_58 ( V_13 , V_71 ) ;
if ( error )
goto V_345;
error = F_108 ( V_13 ) ;
if ( error )
goto V_346;
if ( V_13 -> V_204 . V_247 < 0 ) {
error = V_13 -> V_204 . V_247 ;
V_13 -> V_204 . V_247 = 0 ;
goto V_346;
}
if ( V_13 -> V_157 . V_241 )
snprintf ( V_13 -> V_342 , V_162 , L_64 ,
V_13 -> V_163 ) ;
else
snprintf ( V_13 -> V_342 , V_162 , L_65 ,
V_13 -> V_163 , V_13 -> V_204 . V_247 ) ;
error = F_92 ( V_13 , DO ) ;
if ( error )
goto V_346;
error = F_97 ( V_13 , DO ) ;
if ( error )
goto V_347;
error = F_117 ( V_13 ) ;
if ( error ) {
F_42 ( V_13 , L_66 , error ) ;
goto V_348;
}
if ( ! ( V_12 -> V_306 & V_307 ) ) {
error = F_118 ( V_13 ) ;
if ( error ) {
F_42 ( V_13 , L_67 , error ) ;
goto V_348;
}
}
F_52 ( & V_165 ) ;
F_110 ( V_13 ) ;
return 0 ;
V_348:
F_97 ( V_13 , V_267 ) ;
V_347:
F_92 ( V_13 , V_267 ) ;
V_346:
if ( V_13 -> V_198 )
F_61 ( V_13 -> V_198 ) ;
if ( V_13 -> V_199 )
F_61 ( V_13 -> V_199 ) ;
if ( V_12 -> V_200 )
F_61 ( V_12 -> V_200 ) ;
V_12 -> V_200 = NULL ;
V_345:
F_48 ( V_13 , & V_165 , V_267 ) ;
V_344:
F_93 ( & V_13 -> V_35 ) ;
F_119 ( V_13 ) ;
F_105 ( V_13 ) ;
V_343:
F_120 ( V_13 ) ;
F_114 ( V_13 -> V_19 ) ;
F_121 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_122 ( struct V_11 * V_88 , void * V_349 )
{
V_88 -> V_47 = V_349 ;
V_88 -> V_350 = V_88 -> V_47 -> V_351 ;
V_88 -> V_352 = & F_123 ( V_88 -> V_47 ) -> V_353 ;
return 0 ;
}
static int F_124 ( struct V_11 * V_88 , void * V_354 )
{
struct V_355 * V_356 = V_354 ;
return ( V_356 == V_88 -> V_47 ) ;
}
static struct V_187 * F_125 ( struct V_357 * V_358 , int V_49 ,
const char * V_359 , void * V_349 )
{
struct V_355 * V_356 ;
struct V_11 * V_88 ;
T_4 V_360 = V_361 | V_362 ;
int error ;
struct V_281 args ;
struct V_10 * V_13 ;
if ( ! ( V_49 & V_307 ) )
V_360 |= V_363 ;
V_356 = F_126 ( V_359 , V_360 , V_358 ) ;
if ( F_55 ( V_356 ) )
return F_127 ( V_356 ) ;
F_68 ( & V_356 -> V_364 ) ;
if ( V_356 -> V_365 > 0 ) {
F_77 ( & V_356 -> V_364 ) ;
error = - V_366 ;
goto V_367;
}
V_88 = F_128 ( V_358 , F_124 , F_122 , V_49 , V_356 ) ;
F_77 ( & V_356 -> V_364 ) ;
error = F_56 ( V_88 ) ;
if ( F_55 ( V_88 ) )
goto V_367;
if ( V_88 -> V_200 ) {
F_129 ( & V_88 -> V_368 ) ;
F_130 ( V_356 , V_360 ) ;
F_131 ( & V_88 -> V_368 ) ;
} else {
V_88 -> V_369 = V_360 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_370 = V_371 ;
args . V_372 = V_373 ;
args . V_336 = 30 ;
args . V_339 = 30 ;
args . V_338 = 60 ;
args . V_374 = V_375 ;
error = F_132 ( & args , V_349 ) ;
if ( error ) {
F_17 ( L_68 ) ;
goto V_376;
}
if ( V_88 -> V_200 ) {
error = - V_366 ;
if ( ( V_49 ^ V_88 -> V_306 ) & V_307 )
goto V_376;
} else {
snprintf ( V_88 -> V_160 , sizeof( V_88 -> V_160 ) , L_69 , V_356 ) ;
F_60 ( V_88 , F_133 ( V_356 ) ) ;
error = F_111 ( V_88 , & args , V_49 & V_377 ? 1 : 0 ) ;
if ( error )
goto V_376;
V_88 -> V_306 |= V_378 ;
V_356 -> V_379 = V_88 ;
}
V_13 = V_88 -> V_17 ;
if ( args . V_201 )
return F_62 ( V_13 -> V_199 ) ;
else
return F_62 ( V_13 -> V_198 ) ;
V_376:
F_134 ( V_88 ) ;
return F_135 ( error ) ;
V_367:
F_130 ( V_356 , V_360 ) ;
return F_135 ( error ) ;
}
static int F_136 ( struct V_11 * V_88 , void * V_354 )
{
return - V_78 ;
}
static struct V_187 * F_137 ( struct V_357 * V_358 ,
int V_49 , const char * V_359 , void * V_349 )
{
struct V_11 * V_88 ;
struct V_10 * V_13 ;
struct V_380 V_380 ;
int error ;
error = F_138 ( V_359 , V_381 , & V_380 ) ;
if ( error ) {
F_17 ( L_70 ,
V_359 , error ) ;
return F_135 ( error ) ;
}
V_88 = F_128 ( & V_382 , F_124 , F_136 , V_49 ,
V_380 . V_187 -> V_383 -> V_47 ) ;
F_139 ( & V_380 ) ;
if ( F_55 ( V_88 ) ) {
F_17 ( L_71 ) ;
return F_127 ( V_88 ) ;
}
if ( ( V_49 ^ V_88 -> V_306 ) & V_307 ) {
F_134 ( V_88 ) ;
return F_135 ( - V_366 ) ;
}
V_13 = V_88 -> V_17 ;
return F_62 ( V_13 -> V_199 ) ;
}
static void F_140 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_141 ( V_12 ) ;
return;
}
F_142 ( V_13 , NULL , V_384 ) ;
F_61 ( V_13 -> V_198 ) ;
F_61 ( V_13 -> V_199 ) ;
V_13 -> V_198 = NULL ;
V_13 -> V_199 = NULL ;
F_143 ( V_12 ) ;
F_120 ( V_13 ) ;
F_114 ( V_13 -> V_19 ) ;
F_141 ( V_12 ) ;
}
