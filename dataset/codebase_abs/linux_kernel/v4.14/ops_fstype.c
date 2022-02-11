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
memcpy ( & V_88 -> V_105 , V_90 -> V_106 , 16 ) ;
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
F_33 ( V_83 , V_12 -> V_47 ) ;
F_34 ( V_83 , V_84 , V_113 , 0 ) ;
V_83 -> V_114 = F_20 ;
V_83 -> V_85 = V_84 ;
F_35 ( V_83 , V_115 , V_116 ) ;
F_36 ( V_83 ) ;
F_37 ( V_84 ) ;
F_38 ( V_83 ) ;
if ( ! F_39 ( V_84 ) ) {
F_40 ( V_84 ) ;
return - V_117 ;
}
V_108 = F_41 ( V_84 ) ;
F_23 ( V_13 , V_108 ) ;
F_42 ( V_84 ) ;
F_40 ( V_84 ) ;
return F_17 ( V_13 , V_71 ) ;
}
static int F_43 ( struct V_10 * V_13 , int V_71 )
{
T_2 V_118 , V_119 , V_120 ;
T_2 V_121 ;
unsigned int V_122 ;
int error ;
error = F_26 ( V_13 , V_123 >> V_13 -> V_124 , V_71 ) ;
if ( error ) {
if ( ! V_71 )
F_44 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_124 = V_13 -> V_73 . V_97 -
V_125 ;
V_13 -> V_126 = F_3 ( V_13 -> V_124 ) ;
V_13 -> V_127 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_128 ) ) / sizeof( V_129 ) ;
V_13 -> V_130 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_131 ) ) / sizeof( V_129 ) ;
V_13 -> V_132 = V_13 -> V_73 . V_96 - sizeof( struct V_131 ) ;
V_13 -> V_133 = V_13 -> V_73 . V_96 / 2 ;
V_13 -> V_134 = V_13 -> V_73 . V_97 - 1 ;
V_13 -> V_135 = V_13 -> V_133 / sizeof( V_129 ) ;
V_13 -> V_136 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_131 ) ) /
sizeof( struct V_137 ) ;
V_13 -> V_138 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_131 ) )
* V_139 ;
V_118 = F_45 ( sizeof( V_129 ) * F_3 ( V_140 ) ,
V_13 -> V_132 ) ;
V_119 = 0 ;
for ( V_121 = V_118 ; V_121 > V_13 -> V_127 ; ) {
V_121 = F_45 ( V_121 , V_13 -> V_130 ) ;
V_119 += V_121 ;
}
V_120 = 2 + V_140 ;
V_13 -> V_141 = V_118 + V_119 + V_120 ;
V_13 -> V_142 [ 0 ] = V_13 -> V_73 . V_96 -
sizeof( struct V_128 ) ;
V_13 -> V_142 [ 1 ] = V_13 -> V_73 . V_96 * V_13 -> V_127 ;
for ( V_122 = 2 ; ; V_122 ++ ) {
V_129 V_143 , V_144 ;
T_2 V_145 ;
V_143 = V_13 -> V_142 [ V_122 - 1 ] * V_13 -> V_130 ;
V_144 = V_143 ;
V_145 = F_46 ( V_144 , V_13 -> V_130 ) ;
if ( V_144 != V_13 -> V_142 [ V_122 - 1 ] || V_145 )
break;
V_13 -> V_142 [ V_122 ] = V_143 ;
}
V_13 -> V_146 = V_122 ;
V_13 -> V_142 [ V_122 ] = ~ 0 ;
F_47 ( V_13 , V_13 -> V_146 <= V_147 ) ;
V_13 -> V_148 [ 0 ] = V_13 -> V_73 . V_96 -
sizeof( struct V_128 ) ;
V_13 -> V_148 [ 1 ] = V_13 -> V_132 * V_13 -> V_127 ;
for ( V_122 = 2 ; ; V_122 ++ ) {
V_129 V_143 , V_144 ;
T_2 V_145 ;
V_143 = V_13 -> V_148 [ V_122 - 1 ] * V_13 -> V_130 ;
V_144 = V_143 ;
V_145 = F_46 ( V_144 , V_13 -> V_130 ) ;
if ( V_144 != V_13 -> V_148 [ V_122 - 1 ] || V_145 )
break;
V_13 -> V_148 [ V_122 ] = V_143 ;
}
V_13 -> V_149 = V_122 ;
V_13 -> V_148 [ V_122 ] = ~ 0 ;
F_47 ( V_13 , V_13 -> V_149 <= V_147 ) ;
V_13 -> V_150 = ( V_13 -> V_73 . V_96 -
sizeof( struct V_151 ) ) /
V_152 ;
return 0 ;
}
static int F_48 ( struct V_10 * V_13 , int V_71 )
{
char * V_153 , * V_154 ;
int error = 0 ;
V_153 = V_13 -> V_155 . V_156 ;
V_154 = V_13 -> V_155 . V_157 ;
if ( ! V_153 [ 0 ] || ! V_154 [ 0 ] ) {
error = F_26 ( V_13 , V_123 >> V_13 -> V_124 , V_71 ) ;
if ( error )
return error ;
if ( ! V_153 [ 0 ] )
V_153 = V_13 -> V_73 . V_102 ;
if ( ! V_154 [ 0 ] )
V_154 = V_13 -> V_73 . V_104 ;
}
if ( ! V_154 [ 0 ] )
V_154 = V_13 -> V_18 -> V_158 ;
F_49 ( V_13 -> V_159 , V_153 , V_160 ) ;
F_49 ( V_13 -> V_161 , V_154 , V_160 ) ;
V_154 = V_13 -> V_161 ;
while ( ( V_154 = strchr ( V_154 , '/' ) ) )
* V_154 = '_' ;
return error ;
}
static int F_50 ( struct V_10 * V_13 , struct V_162 * V_163 ,
int V_164 )
{
int error = 0 ;
if ( V_164 )
goto V_165;
error = F_51 ( V_13 ,
V_166 , & V_167 ,
V_168 , V_169 | V_170 ,
V_163 ) ;
if ( error ) {
F_44 ( V_13 , L_5 , error ) ;
goto V_171;
}
error = F_51 ( V_13 ,
V_172 , & V_167 ,
V_173 ,
V_169 | V_174 ,
& V_13 -> V_175 ) ;
if ( error ) {
F_44 ( V_13 , L_6 , error ) ;
goto V_176;
}
error = F_52 ( V_13 , V_177 , & V_167 ,
V_178 , & V_13 -> V_179 ) ;
if ( error ) {
F_44 ( V_13 , L_7 , error ) ;
goto V_180;
}
error = F_52 ( V_13 , V_181 , & V_182 ,
V_178 , & V_13 -> V_183 ) ;
if ( error ) {
F_44 ( V_13 , L_8 , error ) ;
goto V_184;
}
return 0 ;
V_165:
F_53 ( V_13 -> V_183 ) ;
V_184:
F_53 ( V_13 -> V_179 ) ;
V_180:
F_54 ( & V_13 -> V_175 ) ;
V_176:
F_54 ( V_163 ) ;
V_171:
return error ;
}
static int F_55 ( struct V_11 * V_12 , struct V_185 * * V_186 ,
V_129 V_99 , const char * V_187 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_185 * V_185 ;
struct V_188 * V_188 ;
V_188 = F_56 ( V_12 , V_189 , V_99 , 0 ,
V_190 ) ;
if ( F_57 ( V_188 ) ) {
F_44 ( V_13 , L_9 , V_187 , F_58 ( V_188 ) ) ;
return F_58 ( V_188 ) ;
}
V_185 = F_59 ( V_188 ) ;
if ( ! V_185 ) {
F_44 ( V_13 , L_10 , V_187 ) ;
return - V_109 ;
}
* V_186 = V_185 ;
return 0 ;
}
static int F_60 ( struct V_10 * V_13 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_162 V_191 ;
V_129 V_99 ;
int V_192 ;
V_192 = F_51 ( V_13 , V_193 , & V_194 ,
V_173 , 0 , & V_191 ) ;
if ( V_192 ) {
F_44 ( V_13 , L_11 , V_192 ) ;
return V_192 ;
}
V_192 = F_43 ( V_13 , V_71 ) ;
if ( V_192 ) {
F_44 ( V_13 , L_12 , V_192 ) ;
goto V_195;
}
if ( V_13 -> V_73 . V_96 < F_61 ( V_12 -> V_47 ) ) {
V_192 = - V_78 ;
F_44 ( V_13 , L_13
L_14 ,
V_13 -> V_73 . V_96 , F_61 ( V_12 -> V_47 ) ) ;
goto V_195;
}
if ( V_13 -> V_73 . V_96 > V_113 ) {
V_192 = - V_78 ;
F_44 ( V_13 , L_15
L_16 ,
V_13 -> V_73 . V_96 , ( unsigned int ) V_113 ) ;
goto V_195;
}
F_62 ( V_12 , V_13 -> V_73 . V_96 ) ;
V_99 = V_13 -> V_73 . V_101 . V_99 ;
V_192 = F_55 ( V_12 , & V_13 -> V_196 , V_99 , L_17 ) ;
if ( V_192 )
goto V_195;
V_99 = V_13 -> V_73 . V_98 . V_99 ;
V_192 = F_55 ( V_12 , & V_13 -> V_197 , V_99 , L_18 ) ;
if ( V_192 ) {
F_63 ( V_13 -> V_196 ) ;
goto V_195;
}
V_12 -> V_198 = F_64 ( V_13 -> V_155 . V_199 ? V_13 -> V_197 : V_13 -> V_196 ) ;
V_195:
F_54 ( & V_191 ) ;
return V_192 ;
}
static void F_65 ( struct V_10 * V_13 )
{
char * V_200 = L_19 ;
char * V_201 [] = { V_200 , NULL } ;
F_66 ( V_13 , L_20 ) ;
if ( V_13 -> V_202 . V_203 -> V_204 )
V_13 -> V_202 . V_203 -> V_204 ( V_13 ) ;
F_67 ( & V_13 -> V_205 , V_206 , V_201 ) ;
}
static int F_68 ( struct V_10 * V_13 , struct V_162 * V_207 )
{
struct V_208 * V_209 = F_69 ( V_13 -> V_210 ) ;
struct V_211 V_187 ;
char V_87 [ 20 ] ;
struct V_212 * V_213 ;
int error ;
V_187 . V_187 = V_87 ;
F_70 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_71 ( V_209 -> V_214 , V_173 , 0 , V_207 ) ;
if ( error )
break;
V_187 . V_215 = sprintf ( V_87 , L_21 , V_13 -> V_216 ) ;
V_187 . V_217 = F_72 ( V_187 . V_187 , V_187 . V_215 ) ;
error = F_73 ( V_13 -> V_210 , & V_187 , NULL ) ;
if ( error == - V_218 ) {
error = 0 ;
break;
}
F_54 ( V_207 ) ;
if ( error )
break;
error = - V_109 ;
V_213 = F_5 ( sizeof( struct V_212 ) , V_16 ) ;
if ( ! V_213 )
break;
F_12 ( & V_213 -> V_219 ) ;
F_12 ( & V_213 -> V_220 ) ;
F_74 ( & V_213 -> V_221 , V_222 ) ;
V_213 -> V_223 = F_75 ( V_13 -> V_210 , & V_187 , 1 ) ;
if ( ! V_213 -> V_223 || F_57 ( V_213 -> V_223 ) ) {
if ( ! V_213 -> V_223 )
error = - V_218 ;
else
error = F_58 ( V_213 -> V_223 ) ;
F_7 ( V_213 ) ;
break;
}
F_76 ( & V_13 -> V_33 ) ;
V_213 -> V_224 = V_13 -> V_216 ++ ;
F_77 ( & V_213 -> V_225 , & V_13 -> V_32 ) ;
F_78 ( & V_13 -> V_33 ) ;
}
F_79 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_80 ( struct V_10 * V_13 , struct V_212 * V_213 )
{
int error ;
struct V_162 V_226 ;
struct V_227 V_228 ;
struct V_208 * V_229 ;
V_229 = F_69 ( V_213 -> V_223 ) ;
error = F_71 ( V_229 -> V_214 , V_173 , V_169 |
V_174 | V_170 , & V_226 ) ;
if ( error ) {
F_44 ( V_13 , L_22 ) ;
return - V_230 ;
}
error = F_81 ( V_213 ) ;
if ( error ) {
F_44 ( V_13 , L_23 ) ;
goto V_231;
}
error = F_82 ( V_213 , & V_228 ) ;
if ( error ) {
F_44 ( V_13 , L_24 ) ;
goto V_231;
}
if ( ! ( V_228 . V_232 & V_233 ) ) {
error = - V_230 ;
F_44 ( V_13 , L_25
L_26 , V_213 -> V_224 ) ;
}
V_231:
F_54 ( & V_226 ) ;
return error ;
}
static int F_83 ( struct V_10 * V_13 , int V_164 )
{
struct V_188 * V_234 = F_84 ( V_13 -> V_197 ) ;
struct V_162 V_207 ;
struct V_208 * V_229 ;
int V_235 = 1 ;
int error = 0 ;
if ( V_164 ) {
V_235 = 0 ;
goto V_236;
}
V_13 -> V_210 = F_85 ( V_234 , L_27 ) ;
if ( F_57 ( V_13 -> V_210 ) ) {
F_44 ( V_13 , L_28 , error ) ;
return F_58 ( V_13 -> V_210 ) ;
}
error = F_68 ( V_13 , & V_207 ) ;
if ( error ) {
F_44 ( V_13 , L_29 , error ) ;
goto V_171;
}
error = - V_237 ;
if ( ! F_86 ( V_13 ) ) {
F_44 ( V_13 , L_30 ) ;
goto V_238;
}
F_10 ( & V_13 -> V_239 , 0 ) ;
if ( V_13 -> V_155 . V_240 ) {
V_13 -> V_241 = F_87 ( V_13 , 0 ) ;
F_10 ( & V_13 -> V_242 , V_13 -> V_241 -> V_243 ) ;
F_10 ( & V_13 -> V_244 , 2 * V_13 -> V_241 -> V_243 / 5 ) ;
F_10 ( & V_13 -> V_245 , 4 * V_13 -> V_241 -> V_243 / 5 ) ;
} else {
if ( V_13 -> V_202 . V_246 >= F_86 ( V_13 ) ) {
F_44 ( V_13 , L_31 ,
V_13 -> V_202 . V_246 ) ;
F_44 ( V_13 , L_32 ,
F_86 ( V_13 ) ,
F_86 ( V_13 ) - 1 ) ;
goto V_238;
}
V_13 -> V_241 = F_87 ( V_13 , V_13 -> V_202 . V_246 ) ;
error = F_51 ( V_13 , V_13 -> V_202 . V_246 ,
& V_247 ,
V_168 , V_169 ,
& V_13 -> V_248 ) ;
if ( error ) {
F_44 ( V_13 , L_33 , error ) ;
goto V_238;
}
V_229 = F_69 ( V_13 -> V_241 -> V_223 ) ;
error = F_71 ( V_229 -> V_214 , V_173 ,
V_169 | V_174 | V_170 ,
& V_13 -> V_249 ) ;
if ( error ) {
F_44 ( V_13 , L_34 ,
error ) ;
goto V_250;
}
error = F_81 ( V_13 -> V_241 ) ;
if ( error ) {
F_44 ( V_13 , L_35 ,
V_13 -> V_241 -> V_224 , error ) ;
goto V_236;
}
F_10 ( & V_13 -> V_242 , V_13 -> V_241 -> V_243 ) ;
F_10 ( & V_13 -> V_244 , 2 * V_13 -> V_241 -> V_243 / 5 ) ;
F_10 ( & V_13 -> V_245 , 4 * V_13 -> V_241 -> V_243 / 5 ) ;
F_88 ( V_13 , V_13 -> V_241 ) ;
}
F_89 ( V_13 , F_90 ( & V_13 -> V_242 ) ) ;
if ( V_13 -> V_202 . V_251 ) {
unsigned int V_122 ;
for ( V_122 = 0 ; V_122 < V_13 -> V_216 ; V_122 ++ ) {
struct V_212 * V_213 = F_87 ( V_13 , V_122 ) ;
if ( V_13 -> V_155 . V_240 ) {
error = F_80 ( V_13 , V_213 ) ;
if ( error )
goto V_236;
continue;
}
error = F_91 ( V_213 , true ) ;
if ( error ) {
F_44 ( V_13 , L_36 ,
V_122 , error ) ;
goto V_236;
}
}
F_65 ( V_13 ) ;
} else if ( ! V_13 -> V_155 . V_240 ) {
error = F_91 ( V_13 -> V_241 , true ) ;
if ( error ) {
F_44 ( V_13 , L_37 , error ) ;
goto V_236;
}
}
V_13 -> V_252 = 1 ;
F_8 ( V_253 , & V_13 -> V_22 ) ;
F_54 ( & V_207 ) ;
V_235 = 0 ;
F_74 ( & V_13 -> V_254 , V_255 ) ;
return 0 ;
V_236:
if ( ! V_13 -> V_155 . V_240 )
F_54 ( & V_13 -> V_249 ) ;
V_250:
if ( ! V_13 -> V_155 . V_240 )
F_54 ( & V_13 -> V_248 ) ;
V_238:
F_92 ( V_13 ) ;
if ( V_235 )
F_54 ( & V_207 ) ;
V_171:
F_93 ( V_13 -> V_210 ) ;
return error ;
}
static int F_94 ( struct V_10 * V_13 , int V_164 )
{
int error = 0 ;
struct V_188 * V_234 = F_84 ( V_13 -> V_197 ) ;
if ( V_164 )
goto V_256;
error = F_83 ( V_13 , V_164 ) ;
F_95 ( & V_13 -> V_35 ) ;
if ( error )
goto V_171;
V_13 -> V_257 = F_85 ( V_234 , L_38 ) ;
if ( F_57 ( V_13 -> V_257 ) ) {
error = F_58 ( V_13 -> V_257 ) ;
F_44 ( V_13 , L_39 , error ) ;
goto V_258;
}
V_13 -> V_259 = F_85 ( V_234 , L_40 ) ;
if ( F_57 ( V_13 -> V_259 ) ) {
error = F_58 ( V_13 -> V_259 ) ;
F_44 ( V_13 , L_41 , error ) ;
goto V_260;
}
V_13 -> V_261 = 0 ;
V_13 -> V_262 = F_85 ( V_234 , L_42 ) ;
if ( F_57 ( V_13 -> V_262 ) ) {
error = F_58 ( V_13 -> V_262 ) ;
F_44 ( V_13 , L_43 , error ) ;
goto V_263;
}
F_96 ( & V_13 -> V_262 -> V_264 ,
& V_265 ) ;
error = F_97 ( V_13 ) ;
if ( error )
goto V_256;
return 0 ;
V_256:
F_93 ( V_13 -> V_262 ) ;
V_263:
F_98 ( V_13 ) ;
F_93 ( V_13 -> V_259 ) ;
V_260:
F_93 ( V_13 -> V_257 ) ;
V_258:
F_83 ( V_13 , V_266 ) ;
V_171:
return error ;
}
static int F_99 ( struct V_10 * V_13 , int V_164 )
{
struct V_188 * V_267 = NULL ;
char V_87 [ 30 ] ;
int error = 0 ;
struct V_208 * V_229 ;
struct V_188 * V_234 = F_84 ( V_13 -> V_197 ) ;
if ( V_13 -> V_155 . V_240 )
return 0 ;
if ( V_164 )
goto V_268;
V_267 = F_85 ( V_234 , L_44 ) ;
if ( F_57 ( V_267 ) ) {
error = F_58 ( V_267 ) ;
F_44 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_87 , L_46 , V_13 -> V_241 -> V_224 ) ;
V_13 -> V_269 = F_85 ( V_267 , V_87 ) ;
if ( F_57 ( V_13 -> V_269 ) ) {
error = F_58 ( V_13 -> V_269 ) ;
F_44 ( V_13 , L_47 , error ) ;
goto V_171;
}
sprintf ( V_87 , L_48 , V_13 -> V_241 -> V_224 ) ;
V_13 -> V_270 = F_85 ( V_267 , V_87 ) ;
if ( F_57 ( V_13 -> V_270 ) ) {
error = F_58 ( V_13 -> V_270 ) ;
F_44 ( V_13 , L_49 , error ) ;
goto V_271;
}
F_93 ( V_267 ) ;
V_267 = NULL ;
V_229 = F_69 ( V_13 -> V_269 ) ;
error = F_71 ( V_229 -> V_214 , V_168 , 0 ,
& V_13 -> V_272 ) ;
if ( error ) {
F_44 ( V_13 , L_50 , error ) ;
goto V_273;
}
V_229 = F_69 ( V_13 -> V_270 ) ;
error = F_71 ( V_229 -> V_214 , V_168 , 0 ,
& V_13 -> V_274 ) ;
if ( error ) {
F_44 ( V_13 , L_51 , error ) ;
goto V_275;
}
return 0 ;
V_268:
F_54 ( & V_13 -> V_274 ) ;
V_275:
F_54 ( & V_13 -> V_272 ) ;
V_273:
F_93 ( V_13 -> V_270 ) ;
V_271:
F_93 ( V_13 -> V_269 ) ;
V_171:
F_93 ( V_267 ) ;
return error ;
}
static int F_100 ( struct V_10 * V_13 , int V_71 )
{
const struct V_276 * V_277 ;
struct V_278 * V_279 = & V_13 -> V_202 ;
struct V_280 * args = & V_13 -> V_155 ;
const char * V_153 = V_13 -> V_159 ;
const char * V_154 = V_13 -> V_161 ;
char * V_281 , * V_282 ;
int V_192 ;
if ( ! strcmp ( L_52 , V_153 ) ) {
V_277 = & V_283 ;
V_13 -> V_155 . V_284 = 1 ;
#ifdef F_101
} else if ( ! strcmp ( L_53 , V_153 ) ) {
V_277 = & V_285 ;
#endif
} else {
F_102 ( L_54 , V_153 ) ;
return - V_218 ;
}
F_66 ( V_13 , L_55 , V_153 , V_154 ) ;
V_279 -> V_203 = V_277 ;
V_279 -> V_251 = 1 ;
for ( V_282 = args -> V_286 ; ( V_281 = F_103 ( & V_282 , L_56 ) ) ; ) {
T_3 V_287 [ V_288 ] ;
int V_289 , V_290 ;
if ( ! V_281 || ! * V_281 )
continue;
V_289 = F_104 ( V_281 , * V_277 -> V_291 , V_287 ) ;
switch ( V_289 ) {
case V_292 :
V_192 = F_105 ( & V_287 [ 0 ] , & V_290 ) ;
if ( V_192 || V_290 < 0 )
goto V_293;
if ( F_106 ( V_21 , & V_13 -> V_22 ) )
V_279 -> V_246 = V_290 ;
break;
case V_294 :
case V_295 :
break;
case V_296 :
V_192 = F_105 ( & V_287 [ 0 ] , & V_290 ) ;
if ( V_192 || ( V_290 != 0 && V_290 != 1 ) )
goto V_293;
V_279 -> V_251 = V_290 ;
break;
case V_297 :
default:
V_293:
F_66 ( V_13 , L_57 , V_281 ) ;
return - V_78 ;
}
}
if ( V_277 -> V_298 == NULL ) {
F_66 ( V_13 , L_58 ) ;
F_95 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_192 = V_277 -> V_298 ( V_13 , V_154 ) ;
if ( V_192 == 0 )
F_66 ( V_13 , L_59 ) ;
F_95 ( & V_13 -> V_26 ) ;
return V_192 ;
}
void F_107 ( struct V_10 * V_13 )
{
const struct V_276 * V_277 = V_13 -> V_202 . V_203 ;
if ( F_108 ( ! F_109 ( V_299 , & V_13 -> V_22 ) ) &&
V_277 -> V_300 )
V_277 -> V_300 ( V_13 ) ;
}
static int F_110 ( struct V_10 * V_13 )
{
if ( V_13 -> V_202 . V_203 -> V_298 == NULL )
return 0 ;
return F_111 ( & V_13 -> V_22 , V_21 , V_301 )
? - V_302 : 0 ;
}
void F_112 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_303 [ 20 ] ;
char V_304 [ 20 ] ;
char * V_201 [] = { V_303 , V_304 , NULL } ;
sprintf ( V_303 , L_60 , F_113 ( V_12 ) ) ;
sprintf ( V_304 , L_61 , V_13 -> V_155 . V_240 ? 1 : 0 ) ;
F_67 ( & V_13 -> V_205 , V_305 , V_201 ) ;
}
static int F_114 ( struct V_11 * V_12 , struct V_280 * args , int V_71 )
{
struct V_10 * V_13 ;
struct V_162 V_163 ;
int error ;
V_13 = F_4 ( V_12 ) ;
if ( ! V_13 ) {
F_18 ( L_62 ) ;
return - V_109 ;
}
V_13 -> V_155 = * args ;
if ( V_13 -> V_155 . V_240 ) {
V_12 -> V_306 |= V_307 ;
F_8 ( V_308 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_155 . V_309 )
V_12 -> V_306 |= V_310 ;
if ( V_13 -> V_155 . V_311 )
F_8 ( V_312 , & V_13 -> V_22 ) ;
V_12 -> V_306 |= V_313 ;
V_12 -> V_314 = V_75 ;
V_12 -> V_315 = & V_316 ;
V_12 -> V_317 = & V_318 ;
V_12 -> V_319 = & V_320 ;
V_12 -> V_321 = V_322 ;
V_12 -> V_323 = & V_324 ;
V_12 -> V_325 = V_326 | V_327 ;
F_115 ( V_12 ) -> V_49 |= V_328 ;
V_12 -> V_329 = 1 ;
V_12 -> V_330 = V_331 ;
V_13 -> V_73 . V_96 = F_116 ( V_12 , V_332 ) ;
V_13 -> V_73 . V_97 = V_12 -> V_333 ;
V_13 -> V_124 = V_13 -> V_73 . V_97 -
V_125 ;
V_13 -> V_126 = F_3 ( V_13 -> V_124 ) ;
V_13 -> V_23 . V_334 = V_13 -> V_155 . V_335 ;
V_13 -> V_23 . V_336 = V_13 -> V_155 . V_337 ;
if ( V_13 -> V_155 . V_338 ) {
V_13 -> V_23 . V_339 = 0 ;
V_13 -> V_23 . V_340 = V_13 -> V_155 . V_338 ;
} else {
V_13 -> V_23 . V_339 = 1 ;
V_13 -> V_23 . V_340 = 30 ;
}
error = F_48 ( V_13 , V_71 ) ;
if ( error ) {
F_117 ( V_13 -> V_19 ) ;
F_7 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_341 , sizeof( V_13 -> V_341 ) , L_63 , V_13 -> V_161 ) ;
error = F_118 ( V_13 ) ;
if ( error )
return error ;
F_119 ( V_13 ) ;
error = F_100 ( V_13 , V_71 ) ;
if ( error )
goto V_342;
error = F_50 ( V_13 , & V_163 , DO ) ;
if ( error )
goto V_343;
error = F_60 ( V_13 , V_71 ) ;
if ( error )
goto V_344;
error = F_110 ( V_13 ) ;
if ( error )
goto V_345;
if ( V_13 -> V_202 . V_246 < 0 ) {
error = V_13 -> V_202 . V_246 ;
V_13 -> V_202 . V_246 = 0 ;
goto V_345;
}
if ( V_13 -> V_155 . V_240 )
snprintf ( V_13 -> V_341 , sizeof( V_13 -> V_341 ) , L_64 ,
V_13 -> V_161 ) ;
else
snprintf ( V_13 -> V_341 , sizeof( V_13 -> V_341 ) , L_65 ,
V_13 -> V_161 , V_13 -> V_202 . V_246 ) ;
error = F_94 ( V_13 , DO ) ;
if ( error )
goto V_345;
error = F_99 ( V_13 , DO ) ;
if ( error )
goto V_346;
error = F_120 ( V_13 ) ;
if ( error ) {
F_44 ( V_13 , L_66 , error ) ;
goto V_347;
}
if ( ! F_113 ( V_12 ) ) {
error = F_121 ( V_13 ) ;
if ( error ) {
F_44 ( V_13 , L_67 , error ) ;
goto V_347;
}
}
F_54 ( & V_163 ) ;
F_112 ( V_13 ) ;
return 0 ;
V_347:
F_99 ( V_13 , V_266 ) ;
V_346:
F_94 ( V_13 , V_266 ) ;
V_345:
if ( V_13 -> V_196 )
F_63 ( V_13 -> V_196 ) ;
if ( V_13 -> V_197 )
F_63 ( V_13 -> V_197 ) ;
if ( V_12 -> V_198 )
F_63 ( V_12 -> V_198 ) ;
V_12 -> V_198 = NULL ;
V_344:
F_50 ( V_13 , & V_163 , V_266 ) ;
V_343:
F_95 ( & V_13 -> V_35 ) ;
F_122 ( V_13 ) ;
F_107 ( V_13 ) ;
V_342:
F_123 ( V_13 ) ;
F_117 ( V_13 -> V_19 ) ;
F_124 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_125 ( struct V_11 * V_88 , void * V_348 )
{
V_88 -> V_47 = V_348 ;
V_88 -> V_349 = V_88 -> V_47 -> V_350 ;
V_88 -> V_351 = F_126 ( V_88 -> V_47 -> V_352 ) ;
return 0 ;
}
static int F_127 ( struct V_11 * V_88 , void * V_353 )
{
struct V_354 * V_355 = V_353 ;
return ( V_355 == V_88 -> V_47 ) ;
}
static struct V_185 * F_128 ( struct V_356 * V_357 , int V_49 ,
const char * V_358 , void * V_348 )
{
struct V_354 * V_355 ;
struct V_11 * V_88 ;
T_4 V_359 = V_360 | V_361 ;
int error ;
struct V_280 args ;
struct V_10 * V_13 ;
if ( ! ( V_49 & V_307 ) )
V_359 |= V_362 ;
V_355 = F_129 ( V_358 , V_359 , V_357 ) ;
if ( F_57 ( V_355 ) )
return F_130 ( V_355 ) ;
F_70 ( & V_355 -> V_363 ) ;
if ( V_355 -> V_364 > 0 ) {
F_79 ( & V_355 -> V_363 ) ;
error = - V_365 ;
goto V_366;
}
V_88 = F_131 ( V_357 , F_127 , F_125 , V_49 , V_355 ) ;
F_79 ( & V_355 -> V_363 ) ;
error = F_58 ( V_88 ) ;
if ( F_57 ( V_88 ) )
goto V_366;
if ( V_88 -> V_198 ) {
F_132 ( & V_88 -> V_367 ) ;
F_133 ( V_355 , V_359 ) ;
F_134 ( & V_88 -> V_367 ) ;
} else {
V_88 -> V_368 = V_359 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_369 = V_370 ;
args . V_371 = V_372 ;
args . V_335 = 30 ;
args . V_338 = 30 ;
args . V_337 = 60 ;
args . V_373 = V_374 ;
error = F_135 ( & args , V_348 ) ;
if ( error ) {
F_18 ( L_68 ) ;
goto V_375;
}
if ( V_88 -> V_198 ) {
error = - V_365 ;
if ( ( V_49 ^ V_88 -> V_306 ) & V_307 )
goto V_375;
} else {
snprintf ( V_88 -> V_158 , sizeof( V_88 -> V_158 ) , L_69 , V_355 ) ;
F_62 ( V_88 , F_136 ( V_355 ) ) ;
error = F_114 ( V_88 , & args , V_49 & V_376 ? 1 : 0 ) ;
if ( error )
goto V_375;
V_88 -> V_306 |= V_377 ;
V_355 -> V_378 = V_88 ;
}
V_13 = V_88 -> V_17 ;
if ( args . V_199 )
return F_64 ( V_13 -> V_197 ) ;
else
return F_64 ( V_13 -> V_196 ) ;
V_375:
F_137 ( V_88 ) ;
return F_138 ( error ) ;
V_366:
F_133 ( V_355 , V_359 ) ;
return F_138 ( error ) ;
}
static int F_139 ( struct V_11 * V_88 , void * V_353 )
{
return - V_78 ;
}
static struct V_185 * F_140 ( struct V_356 * V_357 ,
int V_49 , const char * V_358 , void * V_348 )
{
struct V_11 * V_88 ;
struct V_10 * V_13 ;
struct V_379 V_379 ;
int error ;
error = F_141 ( V_358 , V_380 , & V_379 ) ;
if ( error ) {
F_18 ( L_70 ,
V_358 , error ) ;
return F_138 ( error ) ;
}
V_88 = F_131 ( & V_381 , F_127 , F_139 , V_49 ,
V_379 . V_185 -> V_382 -> V_47 ) ;
F_142 ( & V_379 ) ;
if ( F_57 ( V_88 ) ) {
F_18 ( L_71 ) ;
return F_130 ( V_88 ) ;
}
if ( ( V_49 ^ V_88 -> V_306 ) & V_307 ) {
F_137 ( V_88 ) ;
return F_138 ( - V_365 ) ;
}
V_13 = V_88 -> V_17 ;
return F_64 ( V_13 -> V_197 ) ;
}
static void F_143 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_144 ( V_12 ) ;
return;
}
F_145 ( V_13 , NULL , V_383 ) ;
F_63 ( V_13 -> V_196 ) ;
F_63 ( V_13 -> V_197 ) ;
V_13 -> V_196 = NULL ;
V_13 -> V_197 = NULL ;
F_146 ( V_12 ) ;
F_117 ( V_13 -> V_19 ) ;
F_144 ( V_12 ) ;
}
