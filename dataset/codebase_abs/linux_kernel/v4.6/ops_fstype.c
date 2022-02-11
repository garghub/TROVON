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
F_33 ( V_116 | V_117 , V_83 ) ;
F_34 ( V_84 ) ;
F_35 ( V_83 ) ;
if ( ! F_36 ( V_84 ) ) {
F_37 ( V_84 ) ;
return - V_118 ;
}
V_108 = F_38 ( V_84 ) ;
F_22 ( V_13 , V_108 ) ;
F_39 ( V_84 ) ;
F_37 ( V_84 ) ;
return F_16 ( V_13 , V_71 ) ;
}
static int F_40 ( struct V_10 * V_13 , int V_71 )
{
T_2 V_119 , V_120 , V_121 ;
T_2 V_122 ;
unsigned int V_123 ;
int error ;
error = F_25 ( V_13 , V_124 >> V_13 -> V_125 , V_71 ) ;
if ( error ) {
if ( ! V_71 )
F_41 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_125 = V_13 -> V_73 . V_97 -
V_126 ;
V_13 -> V_127 = 1 << V_13 -> V_125 ;
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
V_119 = F_42 ( sizeof( V_130 ) * ( 1 << V_141 ) ,
V_13 -> V_133 ) ;
V_120 = 0 ;
for ( V_122 = V_119 ; V_122 > V_13 -> V_128 ; ) {
V_122 = F_42 ( V_122 , V_13 -> V_131 ) ;
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
V_146 = F_43 ( V_145 , V_13 -> V_131 ) ;
if ( V_145 != V_13 -> V_143 [ V_123 - 1 ] || V_146 )
break;
V_13 -> V_143 [ V_123 ] = V_144 ;
}
V_13 -> V_147 = V_123 ;
V_13 -> V_143 [ V_123 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_147 <= V_148 ) ;
V_13 -> V_149 [ 0 ] = V_13 -> V_73 . V_96 -
sizeof( struct V_129 ) ;
V_13 -> V_149 [ 1 ] = V_13 -> V_133 * V_13 -> V_128 ;
for ( V_123 = 2 ; ; V_123 ++ ) {
V_130 V_144 , V_145 ;
T_2 V_146 ;
V_144 = V_13 -> V_149 [ V_123 - 1 ] * V_13 -> V_131 ;
V_145 = V_144 ;
V_146 = F_43 ( V_145 , V_13 -> V_131 ) ;
if ( V_145 != V_13 -> V_149 [ V_123 - 1 ] || V_146 )
break;
V_13 -> V_149 [ V_123 ] = V_144 ;
}
V_13 -> V_150 = V_123 ;
V_13 -> V_149 [ V_123 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_150 <= V_148 ) ;
V_13 -> V_151 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_152 ) ) /
V_153 ;
return 0 ;
}
static int F_45 ( struct V_10 * V_13 , int V_71 )
{
char * V_154 , * V_155 ;
int error = 0 ;
V_154 = V_13 -> V_156 . V_157 ;
V_155 = V_13 -> V_156 . V_158 ;
if ( ! V_154 [ 0 ] || ! V_155 [ 0 ] ) {
error = F_25 ( V_13 , V_124 >> V_13 -> V_125 , V_71 ) ;
if ( error )
return error ;
if ( ! V_154 [ 0 ] )
V_154 = V_13 -> V_73 . V_102 ;
if ( ! V_155 [ 0 ] )
V_155 = V_13 -> V_73 . V_104 ;
}
if ( ! V_155 [ 0 ] )
V_155 = V_13 -> V_18 -> V_159 ;
F_46 ( V_13 -> V_160 , V_154 , V_161 ) ;
F_46 ( V_13 -> V_162 , V_155 , V_161 ) ;
V_155 = V_13 -> V_162 ;
while ( ( V_155 = strchr ( V_155 , '/' ) ) )
* V_155 = '_' ;
return error ;
}
static int F_47 ( struct V_10 * V_13 , struct V_163 * V_164 ,
int V_165 )
{
int error = 0 ;
if ( V_165 )
goto V_166;
error = F_48 ( V_13 ,
V_167 , & V_168 ,
V_169 , V_170 | V_171 ,
V_164 ) ;
if ( error ) {
F_41 ( V_13 , L_5 , error ) ;
goto V_172;
}
error = F_48 ( V_13 ,
V_173 , & V_168 ,
V_174 ,
V_170 | V_175 ,
& V_13 -> V_176 ) ;
if ( error ) {
F_41 ( V_13 , L_6 , error ) ;
goto V_177;
}
error = F_49 ( V_13 , V_178 , & V_168 ,
V_179 , & V_13 -> V_180 ) ;
if ( error ) {
F_41 ( V_13 , L_7 , error ) ;
goto V_181;
}
error = F_49 ( V_13 , V_182 , & V_183 ,
V_179 , & V_13 -> V_184 ) ;
if ( error ) {
F_41 ( V_13 , L_8 , error ) ;
goto V_185;
}
return 0 ;
V_166:
F_50 ( V_13 -> V_184 ) ;
V_185:
F_50 ( V_13 -> V_180 ) ;
V_181:
F_51 ( & V_13 -> V_176 ) ;
V_177:
F_51 ( V_164 ) ;
V_172:
return error ;
}
static int F_52 ( struct V_11 * V_12 , struct V_186 * * V_187 ,
V_130 V_99 , const char * V_188 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_186 * V_186 ;
struct V_189 * V_189 ;
V_189 = F_53 ( V_12 , V_190 , V_99 , 0 ) ;
if ( F_54 ( V_189 ) ) {
F_41 ( V_13 , L_9 , V_188 , F_55 ( V_189 ) ) ;
return F_55 ( V_189 ) ;
}
V_186 = F_56 ( V_189 ) ;
if ( ! V_186 ) {
F_41 ( V_13 , L_10 , V_188 ) ;
return - V_109 ;
}
* V_187 = V_186 ;
return 0 ;
}
static int F_57 ( struct V_10 * V_13 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_163 V_191 ;
V_130 V_99 ;
int V_192 ;
V_192 = F_48 ( V_13 , V_193 , & V_194 ,
V_174 , 0 , & V_191 ) ;
if ( V_192 ) {
F_41 ( V_13 , L_11 , V_192 ) ;
return V_192 ;
}
V_192 = F_40 ( V_13 , V_71 ) ;
if ( V_192 ) {
F_41 ( V_13 , L_12 , V_192 ) ;
goto V_195;
}
if ( V_13 -> V_73 . V_96 < F_58 ( V_12 -> V_47 ) ) {
V_192 = - V_78 ;
F_41 ( V_13 , L_13
L_14 ,
V_13 -> V_73 . V_96 , F_58 ( V_12 -> V_47 ) ) ;
goto V_195;
}
if ( V_13 -> V_73 . V_96 > V_114 ) {
V_192 = - V_78 ;
F_41 ( V_13 , L_15
L_16 ,
V_13 -> V_73 . V_96 , ( unsigned int ) V_114 ) ;
goto V_195;
}
F_59 ( V_12 , V_13 -> V_73 . V_96 ) ;
V_99 = V_13 -> V_73 . V_101 . V_99 ;
V_192 = F_52 ( V_12 , & V_13 -> V_196 , V_99 , L_17 ) ;
if ( V_192 )
goto V_195;
V_99 = V_13 -> V_73 . V_98 . V_99 ;
V_192 = F_52 ( V_12 , & V_13 -> V_197 , V_99 , L_18 ) ;
if ( V_192 ) {
F_60 ( V_13 -> V_196 ) ;
goto V_195;
}
V_12 -> V_198 = F_61 ( V_13 -> V_156 . V_199 ? V_13 -> V_197 : V_13 -> V_196 ) ;
V_195:
F_51 ( & V_191 ) ;
return V_192 ;
}
static void F_62 ( struct V_10 * V_13 )
{
char * V_200 = L_19 ;
char * V_201 [] = { V_200 , NULL } ;
F_63 ( V_13 , L_20 ) ;
if ( V_13 -> V_202 . V_203 -> V_204 )
V_13 -> V_202 . V_203 -> V_204 ( V_13 ) ;
F_64 ( & V_13 -> V_205 , V_206 , V_201 ) ;
}
static int F_65 ( struct V_10 * V_13 , struct V_163 * V_207 )
{
struct V_208 * V_209 = F_66 ( V_13 -> V_210 ) ;
struct V_211 V_188 ;
char V_87 [ 20 ] ;
struct V_212 * V_213 ;
int error ;
V_188 . V_188 = V_87 ;
F_67 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_68 ( V_209 -> V_214 , V_174 , 0 , V_207 ) ;
if ( error )
break;
V_188 . V_215 = sprintf ( V_87 , L_21 , V_13 -> V_216 ) ;
V_188 . V_217 = F_69 ( V_188 . V_188 , V_188 . V_215 ) ;
error = F_70 ( V_13 -> V_210 , & V_188 , NULL ) ;
if ( error == - V_218 ) {
error = 0 ;
break;
}
F_51 ( V_207 ) ;
if ( error )
break;
error = - V_109 ;
V_213 = F_4 ( sizeof( struct V_212 ) , V_16 ) ;
if ( ! V_213 )
break;
F_11 ( & V_213 -> V_219 ) ;
F_11 ( & V_213 -> V_220 ) ;
F_71 ( & V_213 -> V_221 , V_222 ) ;
V_213 -> V_223 = F_72 ( V_13 -> V_210 , & V_188 , 1 ) ;
if ( ! V_213 -> V_223 || F_54 ( V_213 -> V_223 ) ) {
if ( ! V_213 -> V_223 )
error = - V_218 ;
else
error = F_55 ( V_213 -> V_223 ) ;
F_6 ( V_213 ) ;
break;
}
F_73 ( & V_13 -> V_33 ) ;
V_213 -> V_224 = V_13 -> V_216 ++ ;
F_74 ( & V_213 -> V_225 , & V_13 -> V_32 ) ;
F_75 ( & V_13 -> V_33 ) ;
}
F_76 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_77 ( struct V_10 * V_13 , struct V_212 * V_213 )
{
int error ;
struct V_163 V_226 ;
struct V_227 V_228 ;
struct V_208 * V_229 ;
V_229 = F_66 ( V_213 -> V_223 ) ;
error = F_68 ( V_229 -> V_214 , V_174 , V_170 |
V_175 | V_171 , & V_226 ) ;
if ( error ) {
F_41 ( V_13 , L_22 ) ;
return - V_230 ;
}
error = F_78 ( V_213 ) ;
if ( error ) {
F_41 ( V_13 , L_23 ) ;
goto V_231;
}
error = F_79 ( V_213 , & V_228 ) ;
if ( error ) {
F_41 ( V_13 , L_24 ) ;
goto V_231;
}
if ( ! ( V_228 . V_232 & V_233 ) ) {
error = - V_230 ;
F_41 ( V_13 , L_25
L_26 , V_213 -> V_224 ) ;
}
V_231:
F_51 ( & V_226 ) ;
return error ;
}
static int F_80 ( struct V_10 * V_13 , int V_165 )
{
struct V_189 * V_234 = F_81 ( V_13 -> V_197 ) ;
struct V_163 V_207 ;
struct V_208 * V_229 ;
int V_235 = 1 ;
int error = 0 ;
if ( V_165 ) {
V_235 = 0 ;
goto V_236;
}
V_13 -> V_210 = F_82 ( V_234 , L_27 ) ;
if ( F_54 ( V_13 -> V_210 ) ) {
F_41 ( V_13 , L_28 , error ) ;
return F_55 ( V_13 -> V_210 ) ;
}
error = F_65 ( V_13 , & V_207 ) ;
if ( error ) {
F_41 ( V_13 , L_29 , error ) ;
goto V_172;
}
error = - V_237 ;
if ( ! F_83 ( V_13 ) ) {
F_41 ( V_13 , L_30 ) ;
goto V_238;
}
if ( V_13 -> V_156 . V_239 ) {
V_13 -> V_240 = F_84 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_241 , V_13 -> V_240 -> V_242 ) ;
F_9 ( & V_13 -> V_243 , 2 * V_13 -> V_240 -> V_242 / 5 ) ;
F_9 ( & V_13 -> V_244 , 4 * V_13 -> V_240 -> V_242 / 5 ) ;
} else {
if ( V_13 -> V_202 . V_245 >= F_83 ( V_13 ) ) {
F_41 ( V_13 , L_31 ,
V_13 -> V_202 . V_245 ) ;
F_41 ( V_13 , L_32 ,
F_83 ( V_13 ) ,
F_83 ( V_13 ) - 1 ) ;
goto V_238;
}
V_13 -> V_240 = F_84 ( V_13 , V_13 -> V_202 . V_245 ) ;
error = F_48 ( V_13 , V_13 -> V_202 . V_245 ,
& V_246 ,
V_169 , V_170 ,
& V_13 -> V_247 ) ;
if ( error ) {
F_41 ( V_13 , L_33 , error ) ;
goto V_238;
}
V_229 = F_66 ( V_13 -> V_240 -> V_223 ) ;
error = F_68 ( V_229 -> V_214 , V_174 ,
V_170 | V_175 | V_171 ,
& V_13 -> V_248 ) ;
if ( error ) {
F_41 ( V_13 , L_34 ,
error ) ;
goto V_249;
}
error = F_78 ( V_13 -> V_240 ) ;
if ( error ) {
F_41 ( V_13 , L_35 ,
V_13 -> V_240 -> V_224 , error ) ;
goto V_236;
}
F_9 ( & V_13 -> V_241 , V_13 -> V_240 -> V_242 ) ;
F_9 ( & V_13 -> V_243 , 2 * V_13 -> V_240 -> V_242 / 5 ) ;
F_9 ( & V_13 -> V_244 , 4 * V_13 -> V_240 -> V_242 / 5 ) ;
F_85 ( V_13 , V_13 -> V_240 ) ;
}
F_86 ( V_13 , F_87 ( & V_13 -> V_241 ) ) ;
if ( V_13 -> V_202 . V_250 ) {
unsigned int V_123 ;
for ( V_123 = 0 ; V_123 < V_13 -> V_216 ; V_123 ++ ) {
struct V_212 * V_213 = F_84 ( V_13 , V_123 ) ;
if ( V_13 -> V_156 . V_239 ) {
error = F_77 ( V_13 , V_213 ) ;
if ( error )
goto V_236;
continue;
}
error = F_88 ( V_213 , true ) ;
if ( error ) {
F_41 ( V_13 , L_36 ,
V_123 , error ) ;
goto V_236;
}
}
F_62 ( V_13 ) ;
} else if ( ! V_13 -> V_156 . V_239 ) {
error = F_88 ( V_13 -> V_240 , true ) ;
if ( error ) {
F_41 ( V_13 , L_37 , error ) ;
goto V_236;
}
}
V_13 -> V_251 = 1 ;
F_7 ( V_252 , & V_13 -> V_22 ) ;
F_51 ( & V_207 ) ;
V_235 = 0 ;
F_71 ( & V_13 -> V_253 , V_254 ) ;
return 0 ;
V_236:
if ( ! V_13 -> V_156 . V_239 )
F_51 ( & V_13 -> V_248 ) ;
V_249:
if ( ! V_13 -> V_156 . V_239 )
F_51 ( & V_13 -> V_247 ) ;
V_238:
F_89 ( V_13 ) ;
if ( V_235 )
F_51 ( & V_207 ) ;
V_172:
F_90 ( V_13 -> V_210 ) ;
return error ;
}
static int F_91 ( struct V_10 * V_13 , int V_165 )
{
int error = 0 ;
struct V_189 * V_234 = F_81 ( V_13 -> V_197 ) ;
if ( V_165 )
goto V_255;
error = F_80 ( V_13 , V_165 ) ;
F_92 ( & V_13 -> V_35 ) ;
if ( error )
goto V_172;
V_13 -> V_256 = F_82 ( V_234 , L_38 ) ;
if ( F_54 ( V_13 -> V_256 ) ) {
error = F_55 ( V_13 -> V_256 ) ;
F_41 ( V_13 , L_39 , error ) ;
goto V_257;
}
V_13 -> V_258 = F_82 ( V_234 , L_40 ) ;
if ( F_54 ( V_13 -> V_258 ) ) {
error = F_55 ( V_13 -> V_258 ) ;
F_41 ( V_13 , L_41 , error ) ;
goto V_259;
}
V_13 -> V_260 = 0 ;
V_13 -> V_261 = F_82 ( V_234 , L_42 ) ;
if ( F_54 ( V_13 -> V_261 ) ) {
error = F_55 ( V_13 -> V_261 ) ;
F_41 ( V_13 , L_43 , error ) ;
goto V_262;
}
F_93 ( & V_13 -> V_261 -> V_263 ,
& V_264 ) ;
error = F_94 ( V_13 ) ;
if ( error )
goto V_255;
return 0 ;
V_255:
F_90 ( V_13 -> V_261 ) ;
V_262:
F_95 ( V_13 ) ;
F_90 ( V_13 -> V_258 ) ;
V_259:
F_90 ( V_13 -> V_256 ) ;
V_257:
F_80 ( V_13 , V_265 ) ;
V_172:
return error ;
}
static int F_96 ( struct V_10 * V_13 , int V_165 )
{
struct V_189 * V_266 = NULL ;
char V_87 [ 30 ] ;
int error = 0 ;
struct V_208 * V_229 ;
struct V_189 * V_234 = F_81 ( V_13 -> V_197 ) ;
if ( V_13 -> V_156 . V_239 )
return 0 ;
if ( V_165 )
goto V_267;
V_266 = F_82 ( V_234 , L_44 ) ;
if ( F_54 ( V_266 ) ) {
error = F_55 ( V_266 ) ;
F_41 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_87 , L_46 , V_13 -> V_240 -> V_224 ) ;
V_13 -> V_268 = F_82 ( V_266 , V_87 ) ;
if ( F_54 ( V_13 -> V_268 ) ) {
error = F_55 ( V_13 -> V_268 ) ;
F_41 ( V_13 , L_47 , error ) ;
goto V_172;
}
sprintf ( V_87 , L_48 , V_13 -> V_240 -> V_224 ) ;
V_13 -> V_269 = F_82 ( V_266 , V_87 ) ;
if ( F_54 ( V_13 -> V_269 ) ) {
error = F_55 ( V_13 -> V_269 ) ;
F_41 ( V_13 , L_49 , error ) ;
goto V_270;
}
F_90 ( V_266 ) ;
V_266 = NULL ;
V_229 = F_66 ( V_13 -> V_268 ) ;
error = F_68 ( V_229 -> V_214 , V_169 , 0 ,
& V_13 -> V_271 ) ;
if ( error ) {
F_41 ( V_13 , L_50 , error ) ;
goto V_272;
}
V_229 = F_66 ( V_13 -> V_269 ) ;
error = F_68 ( V_229 -> V_214 , V_169 , 0 ,
& V_13 -> V_273 ) ;
if ( error ) {
F_41 ( V_13 , L_51 , error ) ;
goto V_274;
}
return 0 ;
V_267:
F_51 ( & V_13 -> V_273 ) ;
V_274:
F_51 ( & V_13 -> V_271 ) ;
V_272:
F_90 ( V_13 -> V_269 ) ;
V_270:
F_90 ( V_13 -> V_268 ) ;
V_172:
F_90 ( V_266 ) ;
return error ;
}
static int F_97 ( struct V_10 * V_13 , int V_71 )
{
const struct V_275 * V_276 ;
struct V_277 * V_278 = & V_13 -> V_202 ;
struct V_279 * args = & V_13 -> V_156 ;
const char * V_154 = V_13 -> V_160 ;
const char * V_155 = V_13 -> V_162 ;
char * V_280 , * V_281 ;
int V_192 ;
if ( ! strcmp ( L_52 , V_154 ) ) {
V_276 = & V_282 ;
V_13 -> V_156 . V_283 = 1 ;
#ifdef F_98
} else if ( ! strcmp ( L_53 , V_154 ) ) {
V_276 = & V_284 ;
#endif
} else {
F_99 ( L_54 , V_154 ) ;
return - V_218 ;
}
F_63 ( V_13 , L_55 , V_154 , V_155 ) ;
V_278 -> V_203 = V_276 ;
V_278 -> V_250 = 1 ;
for ( V_281 = args -> V_285 ; ( V_280 = F_100 ( & V_281 , L_56 ) ) ; ) {
T_3 V_286 [ V_287 ] ;
int V_288 , V_289 ;
if ( ! V_280 || ! * V_280 )
continue;
V_288 = F_101 ( V_280 , * V_276 -> V_290 , V_286 ) ;
switch ( V_288 ) {
case V_291 :
V_192 = F_102 ( & V_286 [ 0 ] , & V_289 ) ;
if ( V_192 || V_289 < 0 )
goto V_292;
if ( F_103 ( V_21 , & V_13 -> V_22 ) )
V_278 -> V_245 = V_289 ;
break;
case V_293 :
case V_294 :
break;
case V_295 :
V_192 = F_102 ( & V_286 [ 0 ] , & V_289 ) ;
if ( V_192 || ( V_289 != 0 && V_289 != 1 ) )
goto V_292;
V_278 -> V_250 = V_289 ;
break;
case V_296 :
default:
V_292:
F_63 ( V_13 , L_57 , V_280 ) ;
return - V_78 ;
}
}
if ( V_276 -> V_297 == NULL ) {
F_63 ( V_13 , L_58 ) ;
F_92 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_192 = V_276 -> V_297 ( V_13 , V_155 ) ;
if ( V_192 == 0 )
F_63 ( V_13 , L_59 ) ;
F_92 ( & V_13 -> V_26 ) ;
return V_192 ;
}
void F_104 ( struct V_10 * V_13 )
{
const struct V_275 * V_276 = V_13 -> V_202 . V_203 ;
if ( F_105 ( ! F_106 ( V_298 , & V_13 -> V_22 ) ) &&
V_276 -> V_299 )
V_276 -> V_299 ( V_13 ) ;
}
static int F_107 ( struct V_10 * V_13 )
{
if ( V_13 -> V_202 . V_203 -> V_297 == NULL )
return 0 ;
return F_108 ( & V_13 -> V_22 , V_21 , V_300 )
? - V_301 : 0 ;
}
void F_109 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_302 [ 20 ] ;
char V_303 [ 20 ] ;
char * V_201 [] = { V_302 , V_303 , NULL } ;
sprintf ( V_302 , L_60 , ( V_12 -> V_304 & V_305 ) ? 1 : 0 ) ;
sprintf ( V_303 , L_61 , V_13 -> V_156 . V_239 ? 1 : 0 ) ;
F_64 ( & V_13 -> V_205 , V_306 , V_201 ) ;
}
static int F_110 ( struct V_11 * V_12 , struct V_279 * args , int V_71 )
{
struct V_10 * V_13 ;
struct V_163 V_164 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( L_62 ) ;
return - V_109 ;
}
V_13 -> V_156 = * args ;
if ( V_13 -> V_156 . V_239 ) {
V_12 -> V_304 |= V_305 ;
F_7 ( V_307 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_156 . V_308 )
V_12 -> V_304 |= V_309 ;
if ( V_13 -> V_156 . V_310 )
F_7 ( V_311 , & V_13 -> V_22 ) ;
V_12 -> V_304 |= V_312 ;
V_12 -> V_313 = V_75 ;
V_12 -> V_314 = & V_315 ;
V_12 -> V_316 = & V_317 ;
V_12 -> V_318 = & V_319 ;
V_12 -> V_320 = V_321 ;
V_12 -> V_322 = & V_323 ;
V_12 -> V_324 = V_325 | V_326 ;
F_111 ( V_12 ) -> V_49 |= V_327 ;
V_12 -> V_328 = 1 ;
V_12 -> V_329 = V_330 ;
V_13 -> V_73 . V_96 = F_112 ( V_12 , V_331 ) ;
V_13 -> V_73 . V_97 = V_12 -> V_332 ;
V_13 -> V_125 = V_13 -> V_73 . V_97 -
V_126 ;
V_13 -> V_127 = 1 << V_13 -> V_125 ;
V_13 -> V_23 . V_333 = V_13 -> V_156 . V_334 ;
V_13 -> V_23 . V_335 = V_13 -> V_156 . V_336 ;
if ( V_13 -> V_156 . V_337 ) {
V_13 -> V_23 . V_338 = 0 ;
V_13 -> V_23 . V_339 = V_13 -> V_156 . V_337 ;
} else {
V_13 -> V_23 . V_338 = 1 ;
V_13 -> V_23 . V_339 = 30 ;
}
error = F_45 ( V_13 , V_71 ) ;
if ( error ) {
F_113 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_340 , V_161 , L_63 , V_13 -> V_162 ) ;
error = F_114 ( V_13 ) ;
if ( error )
return error ;
F_115 ( V_13 ) ;
error = F_97 ( V_13 , V_71 ) ;
if ( error )
goto V_341;
error = F_47 ( V_13 , & V_164 , DO ) ;
if ( error )
goto V_342;
error = F_57 ( V_13 , V_71 ) ;
if ( error )
goto V_343;
error = F_107 ( V_13 ) ;
if ( error )
goto V_344;
if ( V_13 -> V_202 . V_245 < 0 ) {
error = V_13 -> V_202 . V_245 ;
V_13 -> V_202 . V_245 = 0 ;
goto V_344;
}
if ( V_13 -> V_156 . V_239 )
snprintf ( V_13 -> V_340 , V_161 , L_64 ,
V_13 -> V_162 ) ;
else
snprintf ( V_13 -> V_340 , V_161 , L_65 ,
V_13 -> V_162 , V_13 -> V_202 . V_245 ) ;
error = F_91 ( V_13 , DO ) ;
if ( error )
goto V_344;
error = F_96 ( V_13 , DO ) ;
if ( error )
goto V_345;
error = F_116 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_66 , error ) ;
goto V_346;
}
if ( ! ( V_12 -> V_304 & V_305 ) ) {
error = F_117 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_67 , error ) ;
goto V_346;
}
}
F_51 ( & V_164 ) ;
F_109 ( V_13 ) ;
return 0 ;
V_346:
F_96 ( V_13 , V_265 ) ;
V_345:
F_91 ( V_13 , V_265 ) ;
V_344:
if ( V_13 -> V_196 )
F_60 ( V_13 -> V_196 ) ;
if ( V_13 -> V_197 )
F_60 ( V_13 -> V_197 ) ;
if ( V_12 -> V_198 )
F_60 ( V_12 -> V_198 ) ;
V_12 -> V_198 = NULL ;
V_343:
F_47 ( V_13 , & V_164 , V_265 ) ;
V_342:
F_92 ( & V_13 -> V_35 ) ;
F_118 ( V_13 ) ;
F_104 ( V_13 ) ;
V_341:
F_119 ( V_13 ) ;
F_113 ( V_13 -> V_19 ) ;
F_120 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_121 ( struct V_11 * V_88 , void * V_347 )
{
V_88 -> V_47 = V_347 ;
V_88 -> V_348 = V_88 -> V_47 -> V_349 ;
V_88 -> V_350 = & F_122 ( V_88 -> V_47 ) -> V_351 ;
return 0 ;
}
static int F_123 ( struct V_11 * V_88 , void * V_352 )
{
struct V_353 * V_354 = V_352 ;
return ( V_354 == V_88 -> V_47 ) ;
}
static struct V_186 * F_124 ( struct V_355 * V_356 , int V_49 ,
const char * V_357 , void * V_347 )
{
struct V_353 * V_354 ;
struct V_11 * V_88 ;
T_4 V_358 = V_359 | V_360 ;
int error ;
struct V_279 args ;
struct V_10 * V_13 ;
if ( ! ( V_49 & V_305 ) )
V_358 |= V_361 ;
V_354 = F_125 ( V_357 , V_358 , V_356 ) ;
if ( F_54 ( V_354 ) )
return F_126 ( V_354 ) ;
F_67 ( & V_354 -> V_362 ) ;
if ( V_354 -> V_363 > 0 ) {
F_76 ( & V_354 -> V_362 ) ;
error = - V_364 ;
goto V_365;
}
V_88 = F_127 ( V_356 , F_123 , F_121 , V_49 , V_354 ) ;
F_76 ( & V_354 -> V_362 ) ;
error = F_55 ( V_88 ) ;
if ( F_54 ( V_88 ) )
goto V_365;
if ( V_88 -> V_198 ) {
F_128 ( & V_88 -> V_366 ) ;
F_129 ( V_354 , V_358 ) ;
F_130 ( & V_88 -> V_366 ) ;
} else {
V_88 -> V_367 = V_358 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_368 = V_369 ;
args . V_370 = V_371 ;
args . V_334 = 30 ;
args . V_337 = 30 ;
args . V_336 = 60 ;
args . V_372 = V_373 ;
error = F_131 ( & args , V_347 ) ;
if ( error ) {
F_17 ( L_68 ) ;
goto V_374;
}
if ( V_88 -> V_198 ) {
error = - V_364 ;
if ( ( V_49 ^ V_88 -> V_304 ) & V_305 )
goto V_374;
} else {
snprintf ( V_88 -> V_159 , sizeof( V_88 -> V_159 ) , L_69 , V_354 ) ;
F_59 ( V_88 , F_132 ( V_354 ) ) ;
error = F_110 ( V_88 , & args , V_49 & V_375 ? 1 : 0 ) ;
if ( error )
goto V_374;
V_88 -> V_304 |= V_376 ;
V_354 -> V_377 = V_88 ;
}
V_13 = V_88 -> V_17 ;
if ( args . V_199 )
return F_61 ( V_13 -> V_197 ) ;
else
return F_61 ( V_13 -> V_196 ) ;
V_374:
F_133 ( V_88 ) ;
return F_134 ( error ) ;
V_365:
F_129 ( V_354 , V_358 ) ;
return F_134 ( error ) ;
}
static int F_135 ( struct V_11 * V_88 , void * V_352 )
{
return - V_78 ;
}
static struct V_186 * F_136 ( struct V_355 * V_356 ,
int V_49 , const char * V_357 , void * V_347 )
{
struct V_11 * V_88 ;
struct V_10 * V_13 ;
struct V_378 V_378 ;
int error ;
error = F_137 ( V_357 , V_379 , & V_378 ) ;
if ( error ) {
F_17 ( L_70 ,
V_357 , error ) ;
return F_134 ( error ) ;
}
V_88 = F_127 ( & V_380 , F_123 , F_135 , V_49 ,
F_81 ( V_378 . V_186 ) -> V_381 -> V_47 ) ;
F_138 ( & V_378 ) ;
if ( F_54 ( V_88 ) ) {
F_17 ( L_71 ) ;
return F_126 ( V_88 ) ;
}
if ( ( V_49 ^ V_88 -> V_304 ) & V_305 ) {
F_133 ( V_88 ) ;
return F_134 ( - V_364 ) ;
}
V_13 = V_88 -> V_17 ;
return F_61 ( V_13 -> V_197 ) ;
}
static void F_139 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_140 ( V_12 ) ;
return;
}
F_141 ( V_13 , NULL , V_382 ) ;
F_60 ( V_13 -> V_196 ) ;
F_60 ( V_13 -> V_197 ) ;
V_13 -> V_196 = NULL ;
V_13 -> V_197 = NULL ;
F_142 ( V_12 ) ;
F_119 ( V_13 ) ;
F_113 ( V_13 -> V_19 ) ;
F_140 ( V_12 ) ;
}
