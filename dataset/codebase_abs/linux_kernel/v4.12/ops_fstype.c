static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 10 ;
V_2 -> V_5 = 1 ;
V_2 -> V_6 = 1 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = F_3 ( 18 ) ;
V_2 -> V_9 = 10 ;
}
static struct V_10 * F_4 ( struct V_11 * V_12 )
{
struct V_10 * V_13 ;
struct V_14 * V_15 ;
V_13 = F_5 ( sizeof( struct V_10 ) , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_12 -> V_17 = V_13 ;
V_13 -> V_18 = V_12 ;
V_13 -> V_19 = F_6 ( struct V_20 ) ;
if ( ! V_13 -> V_19 ) {
F_7 ( V_13 ) ;
return NULL ;
}
F_8 ( V_21 , & V_13 -> V_22 ) ;
F_1 ( & V_13 -> V_23 ) ;
F_9 ( & V_13 -> V_24 ) ;
F_10 ( & V_13 -> V_25 , 0 ) ;
F_11 ( & V_13 -> V_26 ) ;
F_11 ( & V_13 -> V_27 ) ;
F_2 ( & V_13 -> V_28 ) ;
F_2 ( & V_13 -> V_29 ) ;
V_13 -> V_30 . V_31 = NULL ;
F_12 ( & V_13 -> V_32 ) ;
F_2 ( & V_13 -> V_33 ) ;
F_13 ( & V_13 -> V_34 ) ;
F_11 ( & V_13 -> V_35 ) ;
F_12 ( & V_13 -> V_36 ) ;
F_13 ( & V_13 -> V_37 ) ;
F_13 ( & V_13 -> V_38 ) ;
F_9 ( & V_13 -> V_39 ) ;
F_12 ( & V_13 -> V_40 ) ;
F_2 ( & V_13 -> V_41 ) ;
F_2 ( & V_13 -> V_42 ) ;
V_15 = & V_13 -> V_43 ;
F_14 ( V_15 ) ;
V_15 -> V_44 = & V_45 ;
V_15 -> V_46 = V_12 -> V_47 -> V_48 ;
V_15 -> V_49 = 0 ;
F_15 ( V_15 , V_50 ) ;
V_15 -> V_51 = NULL ;
V_15 -> V_52 = 0 ;
F_2 ( & V_13 -> V_53 ) ;
F_10 ( & V_13 -> V_54 , 0 ) ;
F_12 ( & V_13 -> V_55 ) ;
F_12 ( & V_13 -> V_56 ) ;
F_2 ( & V_13 -> V_57 ) ;
F_9 ( & V_13 -> V_58 ) ;
F_9 ( & V_13 -> V_59 ) ;
F_2 ( & V_13 -> V_60 ) ;
F_12 ( & V_13 -> V_61 ) ;
F_12 ( & V_13 -> V_62 ) ;
F_16 ( & V_13 -> V_63 ) ;
F_10 ( & V_13 -> V_64 , 0 ) ;
F_10 ( & V_13 -> V_65 , 0 ) ;
F_9 ( & V_13 -> V_66 ) ;
F_9 ( & V_13 -> V_67 ) ;
F_10 ( & V_13 -> V_68 , V_69 ) ;
F_13 ( & V_13 -> V_70 ) ;
return V_13 ;
}
static int F_17 ( struct V_10 * V_13 , int V_71 )
{
struct V_72 * V_12 = & V_13 -> V_73 ;
if ( V_12 -> V_74 != V_75 ||
V_12 -> V_76 != V_77 ) {
if ( ! V_71 )
F_18 ( L_1 ) ;
return - V_78 ;
}
if ( V_12 -> V_79 == V_80 &&
V_12 -> V_81 == V_82 )
return 0 ;
F_19 ( V_13 , L_2 ) ;
return - V_78 ;
}
static void F_20 ( struct V_83 * V_83 )
{
struct V_84 * V_84 = V_83 -> V_85 ;
if ( ! V_83 -> V_86 )
F_21 ( V_84 ) ;
else
F_18 ( L_3 , V_83 -> V_86 ) ;
F_22 ( V_84 ) ;
}
static void F_23 ( struct V_10 * V_13 , const void * V_87 )
{
struct V_72 * V_12 = & V_13 -> V_73 ;
struct V_11 * V_88 = V_13 -> V_18 ;
const struct V_89 * V_90 = V_87 ;
V_12 -> V_74 = F_24 ( V_90 -> V_91 . V_92 ) ;
V_12 -> V_76 = F_24 ( V_90 -> V_91 . V_93 ) ;
V_12 -> V_94 = F_24 ( V_90 -> V_91 . V_95 ) ;
V_12 -> V_79 = F_24 ( V_90 -> V_79 ) ;
V_12 -> V_81 = F_24 ( V_90 -> V_81 ) ;
V_12 -> V_96 = F_24 ( V_90 -> V_96 ) ;
V_12 -> V_97 = F_24 ( V_90 -> V_97 ) ;
V_12 -> V_98 . V_99 = F_25 ( V_90 -> V_98 . V_99 ) ;
V_12 -> V_98 . V_100 = F_25 ( V_90 -> V_98 . V_100 ) ;
V_12 -> V_101 . V_99 = F_25 ( V_90 -> V_101 . V_99 ) ;
V_12 -> V_101 . V_100 = F_25 ( V_90 -> V_101 . V_100 ) ;
memcpy ( V_12 -> V_102 , V_90 -> V_102 , V_103 ) ;
memcpy ( V_12 -> V_104 , V_90 -> V_104 , V_103 ) ;
memcpy ( V_88 -> V_105 , V_90 -> V_106 , 16 ) ;
}
static int F_26 ( struct V_10 * V_13 , T_1 V_107 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_89 * V_108 ;
struct V_84 * V_84 ;
struct V_83 * V_83 ;
V_84 = F_27 ( V_50 ) ;
if ( F_28 ( ! V_84 ) )
return - V_109 ;
F_29 ( V_84 ) ;
F_30 ( V_84 ) ;
F_31 ( V_84 ) ;
V_83 = F_32 ( V_50 , 1 ) ;
V_83 -> V_110 . V_111 = V_107 * ( V_12 -> V_112 >> 9 ) ;
V_83 -> V_113 = V_12 -> V_47 ;
F_33 ( V_83 , V_84 , V_114 , 0 ) ;
V_83 -> V_115 = F_20 ;
V_83 -> V_85 = V_84 ;
F_34 ( V_83 , V_116 , V_117 ) ;
F_35 ( V_83 ) ;
F_36 ( V_84 ) ;
F_37 ( V_83 ) ;
if ( ! F_38 ( V_84 ) ) {
F_39 ( V_84 ) ;
return - V_118 ;
}
V_108 = F_40 ( V_84 ) ;
F_23 ( V_13 , V_108 ) ;
F_41 ( V_84 ) ;
F_39 ( V_84 ) ;
return F_17 ( V_13 , V_71 ) ;
}
static int F_42 ( struct V_10 * V_13 , int V_71 )
{
T_2 V_119 , V_120 , V_121 ;
T_2 V_122 ;
unsigned int V_123 ;
int error ;
error = F_26 ( V_13 , V_124 >> V_13 -> V_125 , V_71 ) ;
if ( error ) {
if ( ! V_71 )
F_43 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_125 = V_13 -> V_73 . V_97 -
V_126 ;
V_13 -> V_127 = F_3 ( V_13 -> V_125 ) ;
V_13 -> V_128 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_129 ) ) / sizeof( V_130 ) ;
V_13 -> V_131 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_132 ) ) / sizeof( V_130 ) ;
V_13 -> V_133 = V_13 -> V_73 . V_96 - sizeof( struct V_132 ) ;
V_13 -> V_134 = V_13 -> V_73 . V_96 / 2 ;
V_13 -> V_135 = V_13 -> V_73 . V_97 - 1 ;
V_13 -> V_136 = V_13 -> V_134 / sizeof( V_130 ) ;
V_13 -> V_137 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_132 ) ) /
sizeof( struct V_138 ) ;
V_13 -> V_139 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_132 ) )
* V_140 ;
V_119 = F_44 ( sizeof( V_130 ) * F_3 ( V_141 ) ,
V_13 -> V_133 ) ;
V_120 = 0 ;
for ( V_122 = V_119 ; V_122 > V_13 -> V_128 ; ) {
V_122 = F_44 ( V_122 , V_13 -> V_131 ) ;
V_120 += V_122 ;
}
V_121 = 2 + V_141 ;
V_13 -> V_142 = V_119 + V_120 + V_121 ;
V_13 -> V_143 [ 0 ] = V_13 -> V_73 . V_96 -
sizeof( struct V_129 ) ;
V_13 -> V_143 [ 1 ] = V_13 -> V_73 . V_96 * V_13 -> V_128 ;
for ( V_123 = 2 ; ; V_123 ++ ) {
V_130 V_144 , V_145 ;
T_2 V_146 ;
V_144 = V_13 -> V_143 [ V_123 - 1 ] * V_13 -> V_131 ;
V_145 = V_144 ;
V_146 = F_45 ( V_145 , V_13 -> V_131 ) ;
if ( V_145 != V_13 -> V_143 [ V_123 - 1 ] || V_146 )
break;
V_13 -> V_143 [ V_123 ] = V_144 ;
}
V_13 -> V_147 = V_123 ;
V_13 -> V_143 [ V_123 ] = ~ 0 ;
F_46 ( V_13 , V_13 -> V_147 <= V_148 ) ;
V_13 -> V_149 [ 0 ] = V_13 -> V_73 . V_96 -
sizeof( struct V_129 ) ;
V_13 -> V_149 [ 1 ] = V_13 -> V_133 * V_13 -> V_128 ;
for ( V_123 = 2 ; ; V_123 ++ ) {
V_130 V_144 , V_145 ;
T_2 V_146 ;
V_144 = V_13 -> V_149 [ V_123 - 1 ] * V_13 -> V_131 ;
V_145 = V_144 ;
V_146 = F_45 ( V_145 , V_13 -> V_131 ) ;
if ( V_145 != V_13 -> V_149 [ V_123 - 1 ] || V_146 )
break;
V_13 -> V_149 [ V_123 ] = V_144 ;
}
V_13 -> V_150 = V_123 ;
V_13 -> V_149 [ V_123 ] = ~ 0 ;
F_46 ( V_13 , V_13 -> V_150 <= V_148 ) ;
V_13 -> V_151 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_152 ) ) /
V_153 ;
return 0 ;
}
static int F_47 ( struct V_10 * V_13 , int V_71 )
{
char * V_154 , * V_155 ;
int error = 0 ;
V_154 = V_13 -> V_156 . V_157 ;
V_155 = V_13 -> V_156 . V_158 ;
if ( ! V_154 [ 0 ] || ! V_155 [ 0 ] ) {
error = F_26 ( V_13 , V_124 >> V_13 -> V_125 , V_71 ) ;
if ( error )
return error ;
if ( ! V_154 [ 0 ] )
V_154 = V_13 -> V_73 . V_102 ;
if ( ! V_155 [ 0 ] )
V_155 = V_13 -> V_73 . V_104 ;
}
if ( ! V_155 [ 0 ] )
V_155 = V_13 -> V_18 -> V_159 ;
F_48 ( V_13 -> V_160 , V_154 , V_161 ) ;
F_48 ( V_13 -> V_162 , V_155 , V_161 ) ;
V_155 = V_13 -> V_162 ;
while ( ( V_155 = strchr ( V_155 , '/' ) ) )
* V_155 = '_' ;
return error ;
}
static int F_49 ( struct V_10 * V_13 , struct V_163 * V_164 ,
int V_165 )
{
int error = 0 ;
if ( V_165 )
goto V_166;
error = F_50 ( V_13 ,
V_167 , & V_168 ,
V_169 , V_170 | V_171 ,
V_164 ) ;
if ( error ) {
F_43 ( V_13 , L_5 , error ) ;
goto V_172;
}
error = F_50 ( V_13 ,
V_173 , & V_168 ,
V_174 ,
V_170 | V_175 ,
& V_13 -> V_176 ) ;
if ( error ) {
F_43 ( V_13 , L_6 , error ) ;
goto V_177;
}
error = F_51 ( V_13 , V_178 , & V_168 ,
V_179 , & V_13 -> V_180 ) ;
if ( error ) {
F_43 ( V_13 , L_7 , error ) ;
goto V_181;
}
error = F_51 ( V_13 , V_182 , & V_183 ,
V_179 , & V_13 -> V_184 ) ;
if ( error ) {
F_43 ( V_13 , L_8 , error ) ;
goto V_185;
}
return 0 ;
V_166:
F_52 ( V_13 -> V_184 ) ;
V_185:
F_52 ( V_13 -> V_180 ) ;
V_181:
F_53 ( & V_13 -> V_176 ) ;
V_177:
F_53 ( V_164 ) ;
V_172:
return error ;
}
static int F_54 ( struct V_11 * V_12 , struct V_186 * * V_187 ,
V_130 V_99 , const char * V_188 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_186 * V_186 ;
struct V_189 * V_189 ;
V_189 = F_55 ( V_12 , V_190 , V_99 , 0 ,
V_191 ) ;
if ( F_56 ( V_189 ) ) {
F_43 ( V_13 , L_9 , V_188 , F_57 ( V_189 ) ) ;
return F_57 ( V_189 ) ;
}
V_186 = F_58 ( V_189 ) ;
if ( ! V_186 ) {
F_43 ( V_13 , L_10 , V_188 ) ;
return - V_109 ;
}
* V_187 = V_186 ;
return 0 ;
}
static int F_59 ( struct V_10 * V_13 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_163 V_192 ;
V_130 V_99 ;
int V_193 ;
V_193 = F_50 ( V_13 , V_194 , & V_195 ,
V_174 , 0 , & V_192 ) ;
if ( V_193 ) {
F_43 ( V_13 , L_11 , V_193 ) ;
return V_193 ;
}
V_193 = F_42 ( V_13 , V_71 ) ;
if ( V_193 ) {
F_43 ( V_13 , L_12 , V_193 ) ;
goto V_196;
}
if ( V_13 -> V_73 . V_96 < F_60 ( V_12 -> V_47 ) ) {
V_193 = - V_78 ;
F_43 ( V_13 , L_13
L_14 ,
V_13 -> V_73 . V_96 , F_60 ( V_12 -> V_47 ) ) ;
goto V_196;
}
if ( V_13 -> V_73 . V_96 > V_114 ) {
V_193 = - V_78 ;
F_43 ( V_13 , L_15
L_16 ,
V_13 -> V_73 . V_96 , ( unsigned int ) V_114 ) ;
goto V_196;
}
F_61 ( V_12 , V_13 -> V_73 . V_96 ) ;
V_99 = V_13 -> V_73 . V_101 . V_99 ;
V_193 = F_54 ( V_12 , & V_13 -> V_197 , V_99 , L_17 ) ;
if ( V_193 )
goto V_196;
V_99 = V_13 -> V_73 . V_98 . V_99 ;
V_193 = F_54 ( V_12 , & V_13 -> V_198 , V_99 , L_18 ) ;
if ( V_193 ) {
F_62 ( V_13 -> V_197 ) ;
goto V_196;
}
V_12 -> V_199 = F_63 ( V_13 -> V_156 . V_200 ? V_13 -> V_198 : V_13 -> V_197 ) ;
V_196:
F_53 ( & V_192 ) ;
return V_193 ;
}
static void F_64 ( struct V_10 * V_13 )
{
char * V_201 = L_19 ;
char * V_202 [] = { V_201 , NULL } ;
F_65 ( V_13 , L_20 ) ;
if ( V_13 -> V_203 . V_204 -> V_205 )
V_13 -> V_203 . V_204 -> V_205 ( V_13 ) ;
F_66 ( & V_13 -> V_206 , V_207 , V_202 ) ;
}
static int F_67 ( struct V_10 * V_13 , struct V_163 * V_208 )
{
struct V_209 * V_210 = F_68 ( V_13 -> V_211 ) ;
struct V_212 V_188 ;
char V_87 [ 20 ] ;
struct V_213 * V_214 ;
int error ;
V_188 . V_188 = V_87 ;
F_69 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_70 ( V_210 -> V_215 , V_174 , 0 , V_208 ) ;
if ( error )
break;
V_188 . V_216 = sprintf ( V_87 , L_21 , V_13 -> V_217 ) ;
V_188 . V_218 = F_71 ( V_188 . V_188 , V_188 . V_216 ) ;
error = F_72 ( V_13 -> V_211 , & V_188 , NULL ) ;
if ( error == - V_219 ) {
error = 0 ;
break;
}
F_53 ( V_208 ) ;
if ( error )
break;
error = - V_109 ;
V_214 = F_5 ( sizeof( struct V_213 ) , V_16 ) ;
if ( ! V_214 )
break;
F_12 ( & V_214 -> V_220 ) ;
F_12 ( & V_214 -> V_221 ) ;
F_73 ( & V_214 -> V_222 , V_223 ) ;
V_214 -> V_224 = F_74 ( V_13 -> V_211 , & V_188 , 1 ) ;
if ( ! V_214 -> V_224 || F_56 ( V_214 -> V_224 ) ) {
if ( ! V_214 -> V_224 )
error = - V_219 ;
else
error = F_57 ( V_214 -> V_224 ) ;
F_7 ( V_214 ) ;
break;
}
F_75 ( & V_13 -> V_33 ) ;
V_214 -> V_225 = V_13 -> V_217 ++ ;
F_76 ( & V_214 -> V_226 , & V_13 -> V_32 ) ;
F_77 ( & V_13 -> V_33 ) ;
}
F_78 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_79 ( struct V_10 * V_13 , struct V_213 * V_214 )
{
int error ;
struct V_163 V_227 ;
struct V_228 V_229 ;
struct V_209 * V_230 ;
V_230 = F_68 ( V_214 -> V_224 ) ;
error = F_70 ( V_230 -> V_215 , V_174 , V_170 |
V_175 | V_171 , & V_227 ) ;
if ( error ) {
F_43 ( V_13 , L_22 ) ;
return - V_231 ;
}
error = F_80 ( V_214 ) ;
if ( error ) {
F_43 ( V_13 , L_23 ) ;
goto V_232;
}
error = F_81 ( V_214 , & V_229 ) ;
if ( error ) {
F_43 ( V_13 , L_24 ) ;
goto V_232;
}
if ( ! ( V_229 . V_233 & V_234 ) ) {
error = - V_231 ;
F_43 ( V_13 , L_25
L_26 , V_214 -> V_225 ) ;
}
V_232:
F_53 ( & V_227 ) ;
return error ;
}
static int F_82 ( struct V_10 * V_13 , int V_165 )
{
struct V_189 * V_235 = F_83 ( V_13 -> V_198 ) ;
struct V_163 V_208 ;
struct V_209 * V_230 ;
int V_236 = 1 ;
int error = 0 ;
if ( V_165 ) {
V_236 = 0 ;
goto V_237;
}
V_13 -> V_211 = F_84 ( V_235 , L_27 ) ;
if ( F_56 ( V_13 -> V_211 ) ) {
F_43 ( V_13 , L_28 , error ) ;
return F_57 ( V_13 -> V_211 ) ;
}
error = F_67 ( V_13 , & V_208 ) ;
if ( error ) {
F_43 ( V_13 , L_29 , error ) ;
goto V_172;
}
error = - V_238 ;
if ( ! F_85 ( V_13 ) ) {
F_43 ( V_13 , L_30 ) ;
goto V_239;
}
F_10 ( & V_13 -> V_240 , 0 ) ;
if ( V_13 -> V_156 . V_241 ) {
V_13 -> V_242 = F_86 ( V_13 , 0 ) ;
F_10 ( & V_13 -> V_243 , V_13 -> V_242 -> V_244 ) ;
F_10 ( & V_13 -> V_245 , 2 * V_13 -> V_242 -> V_244 / 5 ) ;
F_10 ( & V_13 -> V_246 , 4 * V_13 -> V_242 -> V_244 / 5 ) ;
} else {
if ( V_13 -> V_203 . V_247 >= F_85 ( V_13 ) ) {
F_43 ( V_13 , L_31 ,
V_13 -> V_203 . V_247 ) ;
F_43 ( V_13 , L_32 ,
F_85 ( V_13 ) ,
F_85 ( V_13 ) - 1 ) ;
goto V_239;
}
V_13 -> V_242 = F_86 ( V_13 , V_13 -> V_203 . V_247 ) ;
error = F_50 ( V_13 , V_13 -> V_203 . V_247 ,
& V_248 ,
V_169 , V_170 ,
& V_13 -> V_249 ) ;
if ( error ) {
F_43 ( V_13 , L_33 , error ) ;
goto V_239;
}
V_230 = F_68 ( V_13 -> V_242 -> V_224 ) ;
error = F_70 ( V_230 -> V_215 , V_174 ,
V_170 | V_175 | V_171 ,
& V_13 -> V_250 ) ;
if ( error ) {
F_43 ( V_13 , L_34 ,
error ) ;
goto V_251;
}
error = F_80 ( V_13 -> V_242 ) ;
if ( error ) {
F_43 ( V_13 , L_35 ,
V_13 -> V_242 -> V_225 , error ) ;
goto V_237;
}
F_10 ( & V_13 -> V_243 , V_13 -> V_242 -> V_244 ) ;
F_10 ( & V_13 -> V_245 , 2 * V_13 -> V_242 -> V_244 / 5 ) ;
F_10 ( & V_13 -> V_246 , 4 * V_13 -> V_242 -> V_244 / 5 ) ;
F_87 ( V_13 , V_13 -> V_242 ) ;
}
F_88 ( V_13 , F_89 ( & V_13 -> V_243 ) ) ;
if ( V_13 -> V_203 . V_252 ) {
unsigned int V_123 ;
for ( V_123 = 0 ; V_123 < V_13 -> V_217 ; V_123 ++ ) {
struct V_213 * V_214 = F_86 ( V_13 , V_123 ) ;
if ( V_13 -> V_156 . V_241 ) {
error = F_79 ( V_13 , V_214 ) ;
if ( error )
goto V_237;
continue;
}
error = F_90 ( V_214 , true ) ;
if ( error ) {
F_43 ( V_13 , L_36 ,
V_123 , error ) ;
goto V_237;
}
}
F_64 ( V_13 ) ;
} else if ( ! V_13 -> V_156 . V_241 ) {
error = F_90 ( V_13 -> V_242 , true ) ;
if ( error ) {
F_43 ( V_13 , L_37 , error ) ;
goto V_237;
}
}
V_13 -> V_253 = 1 ;
F_8 ( V_254 , & V_13 -> V_22 ) ;
F_53 ( & V_208 ) ;
V_236 = 0 ;
F_73 ( & V_13 -> V_255 , V_256 ) ;
return 0 ;
V_237:
if ( ! V_13 -> V_156 . V_241 )
F_53 ( & V_13 -> V_250 ) ;
V_251:
if ( ! V_13 -> V_156 . V_241 )
F_53 ( & V_13 -> V_249 ) ;
V_239:
F_91 ( V_13 ) ;
if ( V_236 )
F_53 ( & V_208 ) ;
V_172:
F_92 ( V_13 -> V_211 ) ;
return error ;
}
static int F_93 ( struct V_10 * V_13 , int V_165 )
{
int error = 0 ;
struct V_189 * V_235 = F_83 ( V_13 -> V_198 ) ;
if ( V_165 )
goto V_257;
error = F_82 ( V_13 , V_165 ) ;
F_94 ( & V_13 -> V_35 ) ;
if ( error )
goto V_172;
V_13 -> V_258 = F_84 ( V_235 , L_38 ) ;
if ( F_56 ( V_13 -> V_258 ) ) {
error = F_57 ( V_13 -> V_258 ) ;
F_43 ( V_13 , L_39 , error ) ;
goto V_259;
}
V_13 -> V_260 = F_84 ( V_235 , L_40 ) ;
if ( F_56 ( V_13 -> V_260 ) ) {
error = F_57 ( V_13 -> V_260 ) ;
F_43 ( V_13 , L_41 , error ) ;
goto V_261;
}
V_13 -> V_262 = 0 ;
V_13 -> V_263 = F_84 ( V_235 , L_42 ) ;
if ( F_56 ( V_13 -> V_263 ) ) {
error = F_57 ( V_13 -> V_263 ) ;
F_43 ( V_13 , L_43 , error ) ;
goto V_264;
}
F_95 ( & V_13 -> V_263 -> V_265 ,
& V_266 ) ;
error = F_96 ( V_13 ) ;
if ( error )
goto V_257;
return 0 ;
V_257:
F_92 ( V_13 -> V_263 ) ;
V_264:
F_97 ( V_13 ) ;
F_92 ( V_13 -> V_260 ) ;
V_261:
F_92 ( V_13 -> V_258 ) ;
V_259:
F_82 ( V_13 , V_267 ) ;
V_172:
return error ;
}
static int F_98 ( struct V_10 * V_13 , int V_165 )
{
struct V_189 * V_268 = NULL ;
char V_87 [ 30 ] ;
int error = 0 ;
struct V_209 * V_230 ;
struct V_189 * V_235 = F_83 ( V_13 -> V_198 ) ;
if ( V_13 -> V_156 . V_241 )
return 0 ;
if ( V_165 )
goto V_269;
V_268 = F_84 ( V_235 , L_44 ) ;
if ( F_56 ( V_268 ) ) {
error = F_57 ( V_268 ) ;
F_43 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_87 , L_46 , V_13 -> V_242 -> V_225 ) ;
V_13 -> V_270 = F_84 ( V_268 , V_87 ) ;
if ( F_56 ( V_13 -> V_270 ) ) {
error = F_57 ( V_13 -> V_270 ) ;
F_43 ( V_13 , L_47 , error ) ;
goto V_172;
}
sprintf ( V_87 , L_48 , V_13 -> V_242 -> V_225 ) ;
V_13 -> V_271 = F_84 ( V_268 , V_87 ) ;
if ( F_56 ( V_13 -> V_271 ) ) {
error = F_57 ( V_13 -> V_271 ) ;
F_43 ( V_13 , L_49 , error ) ;
goto V_272;
}
F_92 ( V_268 ) ;
V_268 = NULL ;
V_230 = F_68 ( V_13 -> V_270 ) ;
error = F_70 ( V_230 -> V_215 , V_169 , 0 ,
& V_13 -> V_273 ) ;
if ( error ) {
F_43 ( V_13 , L_50 , error ) ;
goto V_274;
}
V_230 = F_68 ( V_13 -> V_271 ) ;
error = F_70 ( V_230 -> V_215 , V_169 , 0 ,
& V_13 -> V_275 ) ;
if ( error ) {
F_43 ( V_13 , L_51 , error ) ;
goto V_276;
}
return 0 ;
V_269:
F_53 ( & V_13 -> V_275 ) ;
V_276:
F_53 ( & V_13 -> V_273 ) ;
V_274:
F_92 ( V_13 -> V_271 ) ;
V_272:
F_92 ( V_13 -> V_270 ) ;
V_172:
F_92 ( V_268 ) ;
return error ;
}
static int F_99 ( struct V_10 * V_13 , int V_71 )
{
const struct V_277 * V_278 ;
struct V_279 * V_280 = & V_13 -> V_203 ;
struct V_281 * args = & V_13 -> V_156 ;
const char * V_154 = V_13 -> V_160 ;
const char * V_155 = V_13 -> V_162 ;
char * V_282 , * V_283 ;
int V_193 ;
if ( ! strcmp ( L_52 , V_154 ) ) {
V_278 = & V_284 ;
V_13 -> V_156 . V_285 = 1 ;
#ifdef F_100
} else if ( ! strcmp ( L_53 , V_154 ) ) {
V_278 = & V_286 ;
#endif
} else {
F_101 ( L_54 , V_154 ) ;
return - V_219 ;
}
F_65 ( V_13 , L_55 , V_154 , V_155 ) ;
V_280 -> V_204 = V_278 ;
V_280 -> V_252 = 1 ;
for ( V_283 = args -> V_287 ; ( V_282 = F_102 ( & V_283 , L_56 ) ) ; ) {
T_3 V_288 [ V_289 ] ;
int V_290 , V_291 ;
if ( ! V_282 || ! * V_282 )
continue;
V_290 = F_103 ( V_282 , * V_278 -> V_292 , V_288 ) ;
switch ( V_290 ) {
case V_293 :
V_193 = F_104 ( & V_288 [ 0 ] , & V_291 ) ;
if ( V_193 || V_291 < 0 )
goto V_294;
if ( F_105 ( V_21 , & V_13 -> V_22 ) )
V_280 -> V_247 = V_291 ;
break;
case V_295 :
case V_296 :
break;
case V_297 :
V_193 = F_104 ( & V_288 [ 0 ] , & V_291 ) ;
if ( V_193 || ( V_291 != 0 && V_291 != 1 ) )
goto V_294;
V_280 -> V_252 = V_291 ;
break;
case V_298 :
default:
V_294:
F_65 ( V_13 , L_57 , V_282 ) ;
return - V_78 ;
}
}
if ( V_278 -> V_299 == NULL ) {
F_65 ( V_13 , L_58 ) ;
F_94 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_193 = V_278 -> V_299 ( V_13 , V_155 ) ;
if ( V_193 == 0 )
F_65 ( V_13 , L_59 ) ;
F_94 ( & V_13 -> V_26 ) ;
return V_193 ;
}
void F_106 ( struct V_10 * V_13 )
{
const struct V_277 * V_278 = V_13 -> V_203 . V_204 ;
if ( F_107 ( ! F_108 ( V_300 , & V_13 -> V_22 ) ) &&
V_278 -> V_301 )
V_278 -> V_301 ( V_13 ) ;
}
static int F_109 ( struct V_10 * V_13 )
{
if ( V_13 -> V_203 . V_204 -> V_299 == NULL )
return 0 ;
return F_110 ( & V_13 -> V_22 , V_21 , V_302 )
? - V_303 : 0 ;
}
void F_111 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_304 [ 20 ] ;
char V_305 [ 20 ] ;
char * V_202 [] = { V_304 , V_305 , NULL } ;
sprintf ( V_304 , L_60 , ( V_12 -> V_306 & V_307 ) ? 1 : 0 ) ;
sprintf ( V_305 , L_61 , V_13 -> V_156 . V_241 ? 1 : 0 ) ;
F_66 ( & V_13 -> V_206 , V_308 , V_202 ) ;
}
static int F_112 ( struct V_11 * V_12 , struct V_281 * args , int V_71 )
{
struct V_10 * V_13 ;
struct V_163 V_164 ;
int error ;
V_13 = F_4 ( V_12 ) ;
if ( ! V_13 ) {
F_18 ( L_62 ) ;
return - V_109 ;
}
V_13 -> V_156 = * args ;
if ( V_13 -> V_156 . V_241 ) {
V_12 -> V_306 |= V_307 ;
F_8 ( V_309 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_156 . V_310 )
V_12 -> V_306 |= V_311 ;
if ( V_13 -> V_156 . V_312 )
F_8 ( V_313 , & V_13 -> V_22 ) ;
V_12 -> V_306 |= V_314 ;
V_12 -> V_315 = V_75 ;
V_12 -> V_316 = & V_317 ;
V_12 -> V_318 = & V_319 ;
V_12 -> V_320 = & V_321 ;
V_12 -> V_322 = V_323 ;
V_12 -> V_324 = & V_325 ;
V_12 -> V_326 = V_327 | V_328 ;
F_113 ( V_12 ) -> V_49 |= V_329 ;
V_12 -> V_330 = 1 ;
V_12 -> V_331 = V_332 ;
V_13 -> V_73 . V_96 = F_114 ( V_12 , V_333 ) ;
V_13 -> V_73 . V_97 = V_12 -> V_334 ;
V_13 -> V_125 = V_13 -> V_73 . V_97 -
V_126 ;
V_13 -> V_127 = F_3 ( V_13 -> V_125 ) ;
V_13 -> V_23 . V_335 = V_13 -> V_156 . V_336 ;
V_13 -> V_23 . V_337 = V_13 -> V_156 . V_338 ;
if ( V_13 -> V_156 . V_339 ) {
V_13 -> V_23 . V_340 = 0 ;
V_13 -> V_23 . V_341 = V_13 -> V_156 . V_339 ;
} else {
V_13 -> V_23 . V_340 = 1 ;
V_13 -> V_23 . V_341 = 30 ;
}
error = F_47 ( V_13 , V_71 ) ;
if ( error ) {
F_115 ( V_13 -> V_19 ) ;
F_7 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_342 , V_161 , L_63 , V_13 -> V_162 ) ;
error = F_116 ( V_13 ) ;
if ( error )
return error ;
F_117 ( V_13 ) ;
error = F_99 ( V_13 , V_71 ) ;
if ( error )
goto V_343;
error = F_49 ( V_13 , & V_164 , DO ) ;
if ( error )
goto V_344;
error = F_59 ( V_13 , V_71 ) ;
if ( error )
goto V_345;
error = F_109 ( V_13 ) ;
if ( error )
goto V_346;
if ( V_13 -> V_203 . V_247 < 0 ) {
error = V_13 -> V_203 . V_247 ;
V_13 -> V_203 . V_247 = 0 ;
goto V_346;
}
if ( V_13 -> V_156 . V_241 )
snprintf ( V_13 -> V_342 , V_161 , L_64 ,
V_13 -> V_162 ) ;
else
snprintf ( V_13 -> V_342 , V_161 , L_65 ,
V_13 -> V_162 , V_13 -> V_203 . V_247 ) ;
error = F_93 ( V_13 , DO ) ;
if ( error )
goto V_346;
error = F_98 ( V_13 , DO ) ;
if ( error )
goto V_347;
error = F_118 ( V_13 ) ;
if ( error ) {
F_43 ( V_13 , L_66 , error ) ;
goto V_348;
}
if ( ! ( V_12 -> V_306 & V_307 ) ) {
error = F_119 ( V_13 ) ;
if ( error ) {
F_43 ( V_13 , L_67 , error ) ;
goto V_348;
}
}
F_53 ( & V_164 ) ;
F_111 ( V_13 ) ;
return 0 ;
V_348:
F_98 ( V_13 , V_267 ) ;
V_347:
F_93 ( V_13 , V_267 ) ;
V_346:
if ( V_13 -> V_197 )
F_62 ( V_13 -> V_197 ) ;
if ( V_13 -> V_198 )
F_62 ( V_13 -> V_198 ) ;
if ( V_12 -> V_199 )
F_62 ( V_12 -> V_199 ) ;
V_12 -> V_199 = NULL ;
V_345:
F_49 ( V_13 , & V_164 , V_267 ) ;
V_344:
F_94 ( & V_13 -> V_35 ) ;
F_120 ( V_13 ) ;
F_106 ( V_13 ) ;
V_343:
F_121 ( V_13 ) ;
F_115 ( V_13 -> V_19 ) ;
F_122 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_123 ( struct V_11 * V_88 , void * V_349 )
{
V_88 -> V_47 = V_349 ;
V_88 -> V_350 = V_88 -> V_47 -> V_351 ;
V_88 -> V_352 = F_124 ( V_88 -> V_47 -> V_353 ) ;
return 0 ;
}
static int F_125 ( struct V_11 * V_88 , void * V_354 )
{
struct V_355 * V_356 = V_354 ;
return ( V_356 == V_88 -> V_47 ) ;
}
static struct V_186 * F_126 ( struct V_357 * V_358 , int V_49 ,
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
V_356 = F_127 ( V_359 , V_360 , V_358 ) ;
if ( F_56 ( V_356 ) )
return F_128 ( V_356 ) ;
F_69 ( & V_356 -> V_364 ) ;
if ( V_356 -> V_365 > 0 ) {
F_78 ( & V_356 -> V_364 ) ;
error = - V_366 ;
goto V_367;
}
V_88 = F_129 ( V_358 , F_125 , F_123 , V_49 , V_356 ) ;
F_78 ( & V_356 -> V_364 ) ;
error = F_57 ( V_88 ) ;
if ( F_56 ( V_88 ) )
goto V_367;
if ( V_88 -> V_199 ) {
F_130 ( & V_88 -> V_368 ) ;
F_131 ( V_356 , V_360 ) ;
F_132 ( & V_88 -> V_368 ) ;
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
error = F_133 ( & args , V_349 ) ;
if ( error ) {
F_18 ( L_68 ) ;
goto V_376;
}
if ( V_88 -> V_199 ) {
error = - V_366 ;
if ( ( V_49 ^ V_88 -> V_306 ) & V_307 )
goto V_376;
} else {
snprintf ( V_88 -> V_159 , sizeof( V_88 -> V_159 ) , L_69 , V_356 ) ;
F_61 ( V_88 , F_134 ( V_356 ) ) ;
error = F_112 ( V_88 , & args , V_49 & V_377 ? 1 : 0 ) ;
if ( error )
goto V_376;
V_88 -> V_306 |= V_378 ;
V_356 -> V_379 = V_88 ;
}
V_13 = V_88 -> V_17 ;
if ( args . V_200 )
return F_63 ( V_13 -> V_198 ) ;
else
return F_63 ( V_13 -> V_197 ) ;
V_376:
F_135 ( V_88 ) ;
return F_136 ( error ) ;
V_367:
F_131 ( V_356 , V_360 ) ;
return F_136 ( error ) ;
}
static int F_137 ( struct V_11 * V_88 , void * V_354 )
{
return - V_78 ;
}
static struct V_186 * F_138 ( struct V_357 * V_358 ,
int V_49 , const char * V_359 , void * V_349 )
{
struct V_11 * V_88 ;
struct V_10 * V_13 ;
struct V_380 V_380 ;
int error ;
error = F_139 ( V_359 , V_381 , & V_380 ) ;
if ( error ) {
F_18 ( L_70 ,
V_359 , error ) ;
return F_136 ( error ) ;
}
V_88 = F_129 ( & V_382 , F_125 , F_137 , V_49 ,
V_380 . V_186 -> V_383 -> V_47 ) ;
F_140 ( & V_380 ) ;
if ( F_56 ( V_88 ) ) {
F_18 ( L_71 ) ;
return F_128 ( V_88 ) ;
}
if ( ( V_49 ^ V_88 -> V_306 ) & V_307 ) {
F_135 ( V_88 ) ;
return F_136 ( - V_366 ) ;
}
V_13 = V_88 -> V_17 ;
return F_63 ( V_13 -> V_198 ) ;
}
static void F_141 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_142 ( V_12 ) ;
return;
}
F_143 ( V_13 , NULL , V_384 ) ;
F_62 ( V_13 -> V_197 ) ;
F_62 ( V_13 -> V_198 ) ;
V_13 -> V_197 = NULL ;
V_13 -> V_198 = NULL ;
F_144 ( V_12 ) ;
F_121 ( V_13 ) ;
F_115 ( V_13 -> V_19 ) ;
F_142 ( V_12 ) ;
}
