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
static void F_19 ( struct V_83 * V_83 , int error )
{
struct V_84 * V_84 = V_83 -> V_85 ;
if ( ! error )
F_20 ( V_84 ) ;
else
F_17 ( L_3 , error ) ;
F_21 ( V_84 ) ;
}
static void F_22 ( struct V_10 * V_13 , const void * V_86 )
{
struct V_72 * V_12 = & V_13 -> V_73 ;
struct V_11 * V_87 = V_13 -> V_18 ;
const struct V_88 * V_89 = V_86 ;
V_12 -> V_74 = F_23 ( V_89 -> V_90 . V_91 ) ;
V_12 -> V_76 = F_23 ( V_89 -> V_90 . V_92 ) ;
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
static int F_25 ( struct V_10 * V_13 , T_1 V_106 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_88 * V_107 ;
struct V_84 * V_84 ;
struct V_83 * V_83 ;
V_84 = F_26 ( V_50 ) ;
if ( F_27 ( ! V_84 ) )
return - V_108 ;
F_28 ( V_84 ) ;
F_29 ( V_84 ) ;
F_30 ( V_84 ) ;
V_83 = F_31 ( V_50 , 1 ) ;
V_83 -> V_109 . V_110 = V_106 * ( V_12 -> V_111 >> 9 ) ;
V_83 -> V_112 = V_12 -> V_47 ;
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
return F_16 ( V_13 , V_71 ) ;
}
static int F_40 ( struct V_10 * V_13 , int V_71 )
{
T_2 V_118 , V_119 , V_120 ;
T_2 V_121 ;
unsigned int V_122 ;
int error ;
error = F_25 ( V_13 , V_123 >> V_13 -> V_124 , V_71 ) ;
if ( error ) {
if ( ! V_71 )
F_41 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_124 = V_13 -> V_73 . V_96 -
V_125 ;
V_13 -> V_126 = 1 << V_13 -> V_124 ;
V_13 -> V_127 = ( V_13 -> V_73 . V_95 -
sizeof( struct V_128 ) ) / sizeof( V_129 ) ;
V_13 -> V_130 = ( V_13 -> V_73 . V_95 -
sizeof( struct V_131 ) ) / sizeof( V_129 ) ;
V_13 -> V_132 = V_13 -> V_73 . V_95 - sizeof( struct V_131 ) ;
V_13 -> V_133 = V_13 -> V_73 . V_95 / 2 ;
V_13 -> V_134 = V_13 -> V_73 . V_96 - 1 ;
V_13 -> V_135 = V_13 -> V_133 / sizeof( V_129 ) ;
V_13 -> V_136 = ( V_13 -> V_73 . V_95 -
sizeof( struct V_131 ) ) /
sizeof( struct V_137 ) ;
V_13 -> V_138 = ( V_13 -> V_73 . V_95 -
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
V_13 -> V_142 [ 0 ] = V_13 -> V_73 . V_95 -
sizeof( struct V_128 ) ;
V_13 -> V_142 [ 1 ] = V_13 -> V_73 . V_95 * V_13 -> V_127 ;
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
V_13 -> V_148 [ 0 ] = V_13 -> V_73 . V_95 -
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
static int F_45 ( struct V_10 * V_13 , int V_71 )
{
char * V_150 , * V_151 ;
int error = 0 ;
V_150 = V_13 -> V_152 . V_153 ;
V_151 = V_13 -> V_152 . V_154 ;
if ( ! V_150 [ 0 ] || ! V_151 [ 0 ] ) {
error = F_25 ( V_13 , V_123 >> V_13 -> V_124 , V_71 ) ;
if ( error )
return error ;
if ( ! V_150 [ 0 ] )
V_150 = V_13 -> V_73 . V_101 ;
if ( ! V_151 [ 0 ] )
V_151 = V_13 -> V_73 . V_103 ;
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
static int F_57 ( struct V_10 * V_13 , int V_71 )
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
V_188 = F_40 ( V_13 , V_71 ) ;
if ( V_188 ) {
F_41 ( V_13 , L_12 , V_188 ) ;
goto V_191;
}
if ( V_13 -> V_73 . V_95 < F_58 ( V_12 -> V_47 ) ) {
V_188 = - V_78 ;
F_41 ( V_13 , L_13
L_14 ,
V_13 -> V_73 . V_95 , F_58 ( V_12 -> V_47 ) ) ;
goto V_191;
}
if ( V_13 -> V_73 . V_95 > V_113 ) {
V_188 = - V_78 ;
F_41 ( V_13 , L_15
L_16 ,
V_13 -> V_73 . V_95 , ( unsigned int ) V_113 ) ;
goto V_191;
}
F_59 ( V_12 , V_13 -> V_73 . V_95 ) ;
V_98 = V_13 -> V_73 . V_100 . V_98 ;
V_188 = F_52 ( V_12 , & V_13 -> V_192 , V_98 , L_17 ) ;
if ( V_188 )
goto V_191;
V_98 = V_13 -> V_73 . V_97 . V_98 ;
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
static void F_62 ( struct V_10 * V_13 )
{
char * V_196 = L_19 ;
char * V_197 [] = { V_196 , NULL } ;
F_63 ( V_13 , L_20 ) ;
if ( V_13 -> V_198 . V_199 -> V_200 )
V_13 -> V_198 . V_199 -> V_200 ( V_13 ) ;
F_64 ( & V_13 -> V_201 , V_202 , V_197 ) ;
}
static int F_65 ( struct V_10 * V_13 , struct V_159 * V_203 )
{
struct V_204 * V_205 = F_66 ( V_13 -> V_206 ) ;
struct V_207 V_184 ;
char V_86 [ 20 ] ;
struct V_208 * V_209 ;
int error ;
V_184 . V_184 = V_86 ;
F_67 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_68 ( V_205 -> V_210 , V_170 , 0 , V_203 ) ;
if ( error )
break;
V_184 . V_211 = sprintf ( V_86 , L_21 , V_13 -> V_212 ) ;
V_184 . V_213 = F_69 ( V_184 . V_184 , V_184 . V_211 ) ;
error = F_70 ( V_13 -> V_206 , & V_184 , NULL ) ;
if ( error == - V_214 ) {
error = 0 ;
break;
}
F_51 ( V_203 ) ;
if ( error )
break;
error = - V_108 ;
V_209 = F_4 ( sizeof( struct V_208 ) , V_16 ) ;
if ( ! V_209 )
break;
F_11 ( & V_209 -> V_215 ) ;
F_11 ( & V_209 -> V_216 ) ;
F_71 ( & V_209 -> V_217 , V_218 ) ;
V_209 -> V_219 = F_72 ( V_13 -> V_206 , & V_184 , 1 ) ;
if ( ! V_209 -> V_219 || F_54 ( V_209 -> V_219 ) ) {
if ( ! V_209 -> V_219 )
error = - V_214 ;
else
error = F_55 ( V_209 -> V_219 ) ;
F_6 ( V_209 ) ;
break;
}
F_73 ( & V_13 -> V_33 ) ;
V_209 -> V_220 = V_13 -> V_212 ++ ;
F_74 ( & V_209 -> V_221 , & V_13 -> V_32 ) ;
F_75 ( & V_13 -> V_33 ) ;
}
F_76 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_77 ( struct V_10 * V_13 , struct V_208 * V_209 )
{
int error ;
struct V_159 V_222 ;
struct V_223 V_224 ;
struct V_204 * V_225 ;
V_225 = F_66 ( V_209 -> V_219 ) ;
error = F_68 ( V_225 -> V_210 , V_170 , V_166 |
V_171 | V_167 , & V_222 ) ;
if ( error ) {
F_41 ( V_13 , L_22 ) ;
return - V_226 ;
}
error = F_78 ( V_209 ) ;
if ( error ) {
F_41 ( V_13 , L_23 ) ;
goto V_227;
}
error = F_79 ( V_209 , & V_224 ) ;
if ( error ) {
F_41 ( V_13 , L_24 ) ;
goto V_227;
}
if ( ! ( V_224 . V_228 & V_229 ) ) {
error = - V_226 ;
F_41 ( V_13 , L_25
L_26 , V_209 -> V_220 ) ;
}
V_227:
F_51 ( & V_222 ) ;
return error ;
}
static int F_80 ( struct V_10 * V_13 , int V_161 )
{
struct V_185 * V_230 = F_81 ( V_13 -> V_193 ) ;
struct V_159 V_203 ;
struct V_204 * V_225 ;
int V_231 = 1 ;
int error = 0 ;
if ( V_161 ) {
V_231 = 0 ;
goto V_232;
}
V_13 -> V_206 = F_82 ( V_230 , L_27 ) ;
if ( F_54 ( V_13 -> V_206 ) ) {
F_41 ( V_13 , L_28 , error ) ;
return F_55 ( V_13 -> V_206 ) ;
}
error = F_65 ( V_13 , & V_203 ) ;
if ( error ) {
F_41 ( V_13 , L_29 , error ) ;
goto V_168;
}
error = - V_233 ;
if ( ! F_83 ( V_13 ) ) {
F_41 ( V_13 , L_30 ) ;
goto V_234;
}
if ( V_13 -> V_152 . V_235 ) {
V_13 -> V_236 = F_84 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_237 , V_13 -> V_236 -> V_238 ) ;
F_9 ( & V_13 -> V_239 , 2 * V_13 -> V_236 -> V_238 / 5 ) ;
F_9 ( & V_13 -> V_240 , 4 * V_13 -> V_236 -> V_238 / 5 ) ;
} else {
if ( V_13 -> V_198 . V_241 >= F_83 ( V_13 ) ) {
F_41 ( V_13 , L_31 ,
V_13 -> V_198 . V_241 ) ;
F_41 ( V_13 , L_32 ,
F_83 ( V_13 ) ,
F_83 ( V_13 ) - 1 ) ;
goto V_234;
}
V_13 -> V_236 = F_84 ( V_13 , V_13 -> V_198 . V_241 ) ;
error = F_48 ( V_13 , V_13 -> V_198 . V_241 ,
& V_242 ,
V_165 , V_166 ,
& V_13 -> V_243 ) ;
if ( error ) {
F_41 ( V_13 , L_33 , error ) ;
goto V_234;
}
V_225 = F_66 ( V_13 -> V_236 -> V_219 ) ;
error = F_68 ( V_225 -> V_210 , V_170 ,
V_166 | V_171 | V_167 ,
& V_13 -> V_244 ) ;
if ( error ) {
F_41 ( V_13 , L_34 ,
error ) ;
goto V_245;
}
error = F_78 ( V_13 -> V_236 ) ;
if ( error ) {
F_41 ( V_13 , L_35 ,
V_13 -> V_236 -> V_220 , error ) ;
goto V_232;
}
F_9 ( & V_13 -> V_237 , V_13 -> V_236 -> V_238 ) ;
F_9 ( & V_13 -> V_239 , 2 * V_13 -> V_236 -> V_238 / 5 ) ;
F_9 ( & V_13 -> V_240 , 4 * V_13 -> V_236 -> V_238 / 5 ) ;
F_85 ( V_13 , V_13 -> V_236 ) ;
}
F_86 ( V_13 , F_87 ( & V_13 -> V_237 ) ) ;
if ( V_13 -> V_198 . V_246 ) {
unsigned int V_122 ;
for ( V_122 = 0 ; V_122 < V_13 -> V_212 ; V_122 ++ ) {
struct V_208 * V_209 = F_84 ( V_13 , V_122 ) ;
if ( V_13 -> V_152 . V_235 ) {
error = F_77 ( V_13 , V_209 ) ;
if ( error )
goto V_232;
continue;
}
error = F_88 ( V_209 , true ) ;
if ( error ) {
F_41 ( V_13 , L_36 ,
V_122 , error ) ;
goto V_232;
}
}
F_62 ( V_13 ) ;
} else if ( ! V_13 -> V_152 . V_235 ) {
error = F_88 ( V_13 -> V_236 , true ) ;
if ( error ) {
F_41 ( V_13 , L_37 , error ) ;
goto V_232;
}
}
V_13 -> V_247 = 1 ;
F_7 ( V_248 , & V_13 -> V_22 ) ;
F_51 ( & V_203 ) ;
V_231 = 0 ;
F_71 ( & V_13 -> V_249 , V_250 ) ;
return 0 ;
V_232:
if ( ! V_13 -> V_152 . V_235 )
F_51 ( & V_13 -> V_244 ) ;
V_245:
if ( ! V_13 -> V_152 . V_235 )
F_51 ( & V_13 -> V_243 ) ;
V_234:
F_89 ( V_13 ) ;
if ( V_231 )
F_51 ( & V_203 ) ;
V_168:
F_90 ( V_13 -> V_206 ) ;
return error ;
}
static int F_91 ( struct V_10 * V_13 , int V_161 )
{
int error = 0 ;
struct V_185 * V_230 = F_81 ( V_13 -> V_193 ) ;
if ( V_161 )
goto V_251;
error = F_80 ( V_13 , V_161 ) ;
F_92 ( & V_13 -> V_35 ) ;
if ( error )
goto V_168;
V_13 -> V_252 = F_82 ( V_230 , L_38 ) ;
if ( F_54 ( V_13 -> V_252 ) ) {
error = F_55 ( V_13 -> V_252 ) ;
F_41 ( V_13 , L_39 , error ) ;
goto V_253;
}
V_13 -> V_254 = F_82 ( V_230 , L_40 ) ;
if ( F_54 ( V_13 -> V_254 ) ) {
error = F_55 ( V_13 -> V_254 ) ;
F_41 ( V_13 , L_41 , error ) ;
goto V_255;
}
V_13 -> V_256 = 0 ;
V_13 -> V_257 = F_82 ( V_230 , L_42 ) ;
if ( F_54 ( V_13 -> V_257 ) ) {
error = F_55 ( V_13 -> V_257 ) ;
F_41 ( V_13 , L_43 , error ) ;
goto V_258;
}
F_93 ( & V_13 -> V_257 -> V_259 ,
& V_260 ) ;
error = F_94 ( V_13 ) ;
if ( error )
goto V_251;
return 0 ;
V_251:
F_90 ( V_13 -> V_257 ) ;
V_258:
F_95 ( V_13 ) ;
F_90 ( V_13 -> V_254 ) ;
V_255:
F_90 ( V_13 -> V_252 ) ;
V_253:
F_80 ( V_13 , V_261 ) ;
V_168:
return error ;
}
static int F_96 ( struct V_10 * V_13 , int V_161 )
{
struct V_185 * V_262 = NULL ;
char V_86 [ 30 ] ;
int error = 0 ;
struct V_204 * V_225 ;
struct V_185 * V_230 = F_81 ( V_13 -> V_193 ) ;
if ( V_13 -> V_152 . V_235 )
return 0 ;
if ( V_161 )
goto V_263;
V_262 = F_82 ( V_230 , L_44 ) ;
if ( F_54 ( V_262 ) ) {
error = F_55 ( V_262 ) ;
F_41 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_86 , L_46 , V_13 -> V_236 -> V_220 ) ;
V_13 -> V_264 = F_82 ( V_262 , V_86 ) ;
if ( F_54 ( V_13 -> V_264 ) ) {
error = F_55 ( V_13 -> V_264 ) ;
F_41 ( V_13 , L_47 , error ) ;
goto V_168;
}
sprintf ( V_86 , L_48 , V_13 -> V_236 -> V_220 ) ;
V_13 -> V_265 = F_82 ( V_262 , V_86 ) ;
if ( F_54 ( V_13 -> V_265 ) ) {
error = F_55 ( V_13 -> V_265 ) ;
F_41 ( V_13 , L_49 , error ) ;
goto V_266;
}
F_90 ( V_262 ) ;
V_262 = NULL ;
V_225 = F_66 ( V_13 -> V_264 ) ;
error = F_68 ( V_225 -> V_210 , V_165 , 0 ,
& V_13 -> V_267 ) ;
if ( error ) {
F_41 ( V_13 , L_50 , error ) ;
goto V_268;
}
V_225 = F_66 ( V_13 -> V_265 ) ;
error = F_68 ( V_225 -> V_210 , V_165 , 0 ,
& V_13 -> V_269 ) ;
if ( error ) {
F_41 ( V_13 , L_51 , error ) ;
goto V_270;
}
return 0 ;
V_263:
F_51 ( & V_13 -> V_269 ) ;
V_270:
F_51 ( & V_13 -> V_267 ) ;
V_268:
F_90 ( V_13 -> V_265 ) ;
V_266:
F_90 ( V_13 -> V_264 ) ;
V_168:
if ( V_262 )
F_90 ( V_262 ) ;
return error ;
}
static int F_97 ( struct V_10 * V_13 , int V_71 )
{
const struct V_271 * V_272 ;
struct V_273 * V_274 = & V_13 -> V_198 ;
struct V_275 * args = & V_13 -> V_152 ;
const char * V_150 = V_13 -> V_156 ;
const char * V_151 = V_13 -> V_158 ;
char * V_276 , * V_277 ;
int V_188 ;
if ( ! strcmp ( L_52 , V_150 ) ) {
V_272 = & V_278 ;
V_13 -> V_152 . V_279 = 1 ;
#ifdef F_98
} else if ( ! strcmp ( L_53 , V_150 ) ) {
V_272 = & V_280 ;
#endif
} else {
F_99 ( L_54 , V_150 ) ;
return - V_214 ;
}
F_63 ( V_13 , L_55 , V_150 , V_151 ) ;
V_274 -> V_199 = V_272 ;
V_274 -> V_246 = 1 ;
for ( V_277 = args -> V_281 ; ( V_276 = F_100 ( & V_277 , L_56 ) ) ; ) {
T_3 V_282 [ V_283 ] ;
int V_284 , V_285 ;
if ( ! V_276 || ! * V_276 )
continue;
V_284 = F_101 ( V_276 , * V_272 -> V_286 , V_282 ) ;
switch ( V_284 ) {
case V_287 :
V_188 = F_102 ( & V_282 [ 0 ] , & V_285 ) ;
if ( V_188 || V_285 < 0 )
goto V_288;
if ( F_103 ( V_21 , & V_13 -> V_22 ) )
V_274 -> V_241 = V_285 ;
break;
case V_289 :
case V_290 :
break;
case V_291 :
V_188 = F_102 ( & V_282 [ 0 ] , & V_285 ) ;
if ( V_188 || ( V_285 != 0 && V_285 != 1 ) )
goto V_288;
V_274 -> V_246 = V_285 ;
break;
case V_292 :
default:
V_288:
F_63 ( V_13 , L_57 , V_276 ) ;
return - V_78 ;
}
}
if ( V_272 -> V_293 == NULL ) {
F_63 ( V_13 , L_58 ) ;
F_92 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_188 = V_272 -> V_293 ( V_13 , V_151 ) ;
if ( V_188 == 0 )
F_63 ( V_13 , L_59 ) ;
F_92 ( & V_13 -> V_26 ) ;
return V_188 ;
}
void F_104 ( struct V_10 * V_13 )
{
const struct V_271 * V_272 = V_13 -> V_198 . V_199 ;
if ( F_105 ( ! F_106 ( V_294 , & V_13 -> V_22 ) ) &&
V_272 -> V_295 )
V_272 -> V_295 ( V_13 ) ;
}
static int F_107 ( struct V_10 * V_13 )
{
if ( V_13 -> V_198 . V_199 -> V_293 == NULL )
return 0 ;
return F_108 ( & V_13 -> V_22 , V_21 , V_296 )
? - V_297 : 0 ;
}
void F_109 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_298 [ 20 ] ;
char V_299 [ 20 ] ;
char * V_197 [] = { V_298 , V_299 , NULL } ;
sprintf ( V_298 , L_60 , ( V_12 -> V_300 & V_301 ) ? 1 : 0 ) ;
sprintf ( V_299 , L_61 , V_13 -> V_152 . V_235 ? 1 : 0 ) ;
F_64 ( & V_13 -> V_201 , V_302 , V_197 ) ;
}
static int F_110 ( struct V_11 * V_12 , struct V_275 * args , int V_71 )
{
struct V_10 * V_13 ;
struct V_159 V_160 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( L_62 ) ;
return - V_108 ;
}
V_13 -> V_152 = * args ;
if ( V_13 -> V_152 . V_235 ) {
V_12 -> V_300 |= V_301 ;
F_7 ( V_303 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_152 . V_304 )
V_12 -> V_300 |= V_305 ;
if ( V_13 -> V_152 . V_306 )
F_7 ( V_307 , & V_13 -> V_22 ) ;
V_12 -> V_300 |= V_308 ;
V_12 -> V_309 = V_75 ;
V_12 -> V_310 = & V_311 ;
V_12 -> V_312 = & V_313 ;
V_12 -> V_314 = & V_315 ;
V_12 -> V_316 = V_317 ;
V_12 -> V_318 = & V_319 ;
V_12 -> V_320 = V_321 | V_322 ;
F_111 ( V_12 ) -> V_49 |= V_323 ;
V_12 -> V_324 = 1 ;
V_12 -> V_325 = V_326 ;
V_13 -> V_73 . V_95 = F_112 ( V_12 , V_327 ) ;
V_13 -> V_73 . V_96 = V_12 -> V_328 ;
V_13 -> V_124 = V_13 -> V_73 . V_96 -
V_125 ;
V_13 -> V_126 = 1 << V_13 -> V_124 ;
V_13 -> V_23 . V_329 = V_13 -> V_152 . V_330 ;
V_13 -> V_23 . V_331 = V_13 -> V_152 . V_332 ;
if ( V_13 -> V_152 . V_333 ) {
V_13 -> V_23 . V_334 = 0 ;
V_13 -> V_23 . V_335 = V_13 -> V_152 . V_333 ;
} else {
V_13 -> V_23 . V_334 = 1 ;
V_13 -> V_23 . V_335 = 30 ;
}
error = F_45 ( V_13 , V_71 ) ;
if ( error ) {
F_113 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_336 , V_157 , L_63 , V_13 -> V_158 ) ;
error = F_114 ( V_13 ) ;
if ( error )
return error ;
F_115 ( V_13 ) ;
error = F_97 ( V_13 , V_71 ) ;
if ( error )
goto V_337;
error = F_47 ( V_13 , & V_160 , DO ) ;
if ( error )
goto V_338;
error = F_57 ( V_13 , V_71 ) ;
if ( error )
goto V_339;
error = F_107 ( V_13 ) ;
if ( error )
goto V_340;
if ( V_13 -> V_198 . V_241 < 0 ) {
error = V_13 -> V_198 . V_241 ;
V_13 -> V_198 . V_241 = 0 ;
goto V_340;
}
if ( V_13 -> V_152 . V_235 )
snprintf ( V_13 -> V_336 , V_157 , L_64 ,
V_13 -> V_158 ) ;
else
snprintf ( V_13 -> V_336 , V_157 , L_65 ,
V_13 -> V_158 , V_13 -> V_198 . V_241 ) ;
error = F_91 ( V_13 , DO ) ;
if ( error )
goto V_340;
error = F_96 ( V_13 , DO ) ;
if ( error )
goto V_341;
error = F_116 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_66 , error ) ;
goto V_342;
}
if ( ! ( V_12 -> V_300 & V_301 ) ) {
error = F_117 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_67 , error ) ;
goto V_342;
}
}
F_51 ( & V_160 ) ;
F_109 ( V_13 ) ;
return 0 ;
V_342:
F_96 ( V_13 , V_261 ) ;
V_341:
F_91 ( V_13 , V_261 ) ;
V_340:
if ( V_13 -> V_192 )
F_60 ( V_13 -> V_192 ) ;
if ( V_13 -> V_193 )
F_60 ( V_13 -> V_193 ) ;
if ( V_12 -> V_194 )
F_60 ( V_12 -> V_194 ) ;
V_12 -> V_194 = NULL ;
V_339:
F_47 ( V_13 , & V_160 , V_261 ) ;
V_338:
F_92 ( & V_13 -> V_35 ) ;
F_118 ( V_13 ) ;
F_104 ( V_13 ) ;
V_337:
F_119 ( V_13 ) ;
F_113 ( V_13 -> V_19 ) ;
F_120 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_121 ( struct V_11 * V_87 , void * V_343 )
{
V_87 -> V_47 = V_343 ;
V_87 -> V_344 = V_87 -> V_47 -> V_345 ;
V_87 -> V_346 = & F_122 ( V_87 -> V_47 ) -> V_347 ;
return 0 ;
}
static int F_123 ( struct V_11 * V_87 , void * V_348 )
{
struct V_349 * V_350 = V_348 ;
return ( V_350 == V_87 -> V_47 ) ;
}
static struct V_182 * F_124 ( struct V_351 * V_352 , int V_49 ,
const char * V_353 , void * V_343 )
{
struct V_349 * V_350 ;
struct V_11 * V_87 ;
T_4 V_354 = V_355 | V_356 ;
int error ;
struct V_275 args ;
struct V_10 * V_13 ;
if ( ! ( V_49 & V_301 ) )
V_354 |= V_357 ;
V_350 = F_125 ( V_353 , V_354 , V_352 ) ;
if ( F_54 ( V_350 ) )
return F_126 ( V_350 ) ;
F_67 ( & V_350 -> V_358 ) ;
if ( V_350 -> V_359 > 0 ) {
F_76 ( & V_350 -> V_358 ) ;
error = - V_360 ;
goto V_361;
}
V_87 = F_127 ( V_352 , F_123 , F_121 , V_49 , V_350 ) ;
F_76 ( & V_350 -> V_358 ) ;
error = F_55 ( V_87 ) ;
if ( F_54 ( V_87 ) )
goto V_361;
if ( V_87 -> V_194 ) {
F_128 ( & V_87 -> V_362 ) ;
F_129 ( V_350 , V_354 ) ;
F_130 ( & V_87 -> V_362 ) ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_363 = V_364 ;
args . V_365 = V_366 ;
args . V_330 = 30 ;
args . V_333 = 30 ;
args . V_332 = 60 ;
args . V_367 = V_368 ;
error = F_131 ( & args , V_343 ) ;
if ( error ) {
F_17 ( L_68 ) ;
goto V_369;
}
if ( V_87 -> V_194 ) {
error = - V_360 ;
if ( ( V_49 ^ V_87 -> V_300 ) & V_301 )
goto V_369;
} else {
char V_370 [ V_371 ] ;
V_87 -> V_372 = V_354 ;
F_46 ( V_87 -> V_155 , F_132 ( V_350 , V_370 ) , sizeof( V_87 -> V_155 ) ) ;
F_59 ( V_87 , F_133 ( V_350 ) ) ;
error = F_110 ( V_87 , & args , V_49 & V_373 ? 1 : 0 ) ;
if ( error )
goto V_369;
V_87 -> V_300 |= V_374 ;
V_350 -> V_375 = V_87 ;
}
V_13 = V_87 -> V_17 ;
if ( args . V_195 )
return F_61 ( V_13 -> V_193 ) ;
else
return F_61 ( V_13 -> V_192 ) ;
V_369:
F_134 ( V_87 ) ;
return F_135 ( error ) ;
V_361:
F_129 ( V_350 , V_354 ) ;
return F_135 ( error ) ;
}
static int F_136 ( struct V_11 * V_87 , void * V_348 )
{
return - V_78 ;
}
static struct V_182 * F_137 ( struct V_351 * V_352 ,
int V_49 , const char * V_353 , void * V_343 )
{
struct V_11 * V_87 ;
struct V_10 * V_13 ;
struct V_376 V_376 ;
int error ;
error = F_138 ( V_353 , V_377 , & V_376 ) ;
if ( error ) {
F_17 ( L_69 ,
V_353 , error ) ;
return F_135 ( error ) ;
}
V_87 = F_127 ( & V_378 , F_123 , F_136 , V_49 ,
F_81 ( V_376 . V_182 ) -> V_379 -> V_47 ) ;
F_139 ( & V_376 ) ;
if ( F_54 ( V_87 ) ) {
F_17 ( L_70 ) ;
return F_126 ( V_87 ) ;
}
if ( ( V_49 ^ V_87 -> V_300 ) & V_301 ) {
F_134 ( V_87 ) ;
return F_135 ( - V_360 ) ;
}
V_13 = V_87 -> V_17 ;
return F_61 ( V_13 -> V_193 ) ;
}
static void F_140 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_141 ( V_12 ) ;
return;
}
F_142 ( V_13 , NULL , V_380 ) ;
F_60 ( V_13 -> V_192 ) ;
F_60 ( V_13 -> V_193 ) ;
V_13 -> V_192 = NULL ;
V_13 -> V_193 = NULL ;
F_143 ( V_12 ) ;
F_119 ( V_13 ) ;
F_113 ( V_13 -> V_19 ) ;
F_141 ( V_12 ) ;
}
