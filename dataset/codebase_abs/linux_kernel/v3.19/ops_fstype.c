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
V_15 -> V_52 = V_12 -> V_53 ;
V_15 -> V_54 = 0 ;
F_2 ( & V_13 -> V_55 ) ;
F_9 ( & V_13 -> V_56 , 0 ) ;
F_11 ( & V_13 -> V_57 ) ;
F_11 ( & V_13 -> V_58 ) ;
F_2 ( & V_13 -> V_59 ) ;
F_8 ( & V_13 -> V_60 ) ;
F_8 ( & V_13 -> V_61 ) ;
F_2 ( & V_13 -> V_62 ) ;
F_11 ( & V_13 -> V_63 ) ;
F_11 ( & V_13 -> V_64 ) ;
F_15 ( & V_13 -> V_65 ) ;
F_9 ( & V_13 -> V_66 , 0 ) ;
F_9 ( & V_13 -> V_67 , 0 ) ;
F_8 ( & V_13 -> V_68 ) ;
F_8 ( & V_13 -> V_69 ) ;
F_9 ( & V_13 -> V_70 , V_71 ) ;
F_12 ( & V_13 -> V_72 ) ;
return V_13 ;
}
static int F_16 ( struct V_10 * V_13 , int V_73 )
{
struct V_74 * V_12 = & V_13 -> V_75 ;
if ( V_12 -> V_76 != V_77 ||
V_12 -> V_78 != V_79 ) {
if ( ! V_73 )
F_17 ( L_1 ) ;
return - V_80 ;
}
if ( V_12 -> V_81 == V_82 &&
V_12 -> V_83 == V_84 )
return 0 ;
F_18 ( V_13 , L_2 ) ;
return - V_80 ;
}
static void F_19 ( struct V_85 * V_85 , int error )
{
struct V_86 * V_86 = V_85 -> V_87 ;
if ( ! error )
F_20 ( V_86 ) ;
else
F_17 ( L_3 , error ) ;
F_21 ( V_86 ) ;
}
static void F_22 ( struct V_10 * V_13 , const void * V_88 )
{
struct V_74 * V_12 = & V_13 -> V_75 ;
struct V_11 * V_89 = V_13 -> V_18 ;
const struct V_90 * V_91 = V_88 ;
V_12 -> V_76 = F_23 ( V_91 -> V_92 . V_93 ) ;
V_12 -> V_78 = F_23 ( V_91 -> V_92 . V_94 ) ;
V_12 -> V_95 = F_23 ( V_91 -> V_92 . V_96 ) ;
V_12 -> V_81 = F_23 ( V_91 -> V_81 ) ;
V_12 -> V_83 = F_23 ( V_91 -> V_83 ) ;
V_12 -> V_97 = F_23 ( V_91 -> V_97 ) ;
V_12 -> V_98 = F_23 ( V_91 -> V_98 ) ;
V_12 -> V_99 . V_100 = F_24 ( V_91 -> V_99 . V_100 ) ;
V_12 -> V_99 . V_101 = F_24 ( V_91 -> V_99 . V_101 ) ;
V_12 -> V_102 . V_100 = F_24 ( V_91 -> V_102 . V_100 ) ;
V_12 -> V_102 . V_101 = F_24 ( V_91 -> V_102 . V_101 ) ;
memcpy ( V_12 -> V_103 , V_91 -> V_103 , V_104 ) ;
memcpy ( V_12 -> V_105 , V_91 -> V_105 , V_104 ) ;
memcpy ( V_89 -> V_106 , V_91 -> V_107 , 16 ) ;
}
static int F_25 ( struct V_10 * V_13 , T_1 V_108 , int V_73 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_90 * V_109 ;
struct V_86 * V_86 ;
struct V_85 * V_85 ;
V_86 = F_26 ( V_50 ) ;
if ( F_27 ( ! V_86 ) )
return - V_110 ;
F_28 ( V_86 ) ;
F_29 ( V_86 ) ;
F_30 ( V_86 ) ;
V_85 = F_31 ( V_50 , 1 ) ;
V_85 -> V_111 . V_112 = V_108 * ( V_12 -> V_113 >> 9 ) ;
V_85 -> V_114 = V_12 -> V_47 ;
F_32 ( V_85 , V_86 , V_115 , 0 ) ;
V_85 -> V_116 = F_19 ;
V_85 -> V_87 = V_86 ;
F_33 ( V_117 | V_118 , V_85 ) ;
F_34 ( V_86 ) ;
F_35 ( V_85 ) ;
if ( ! F_36 ( V_86 ) ) {
F_37 ( V_86 ) ;
return - V_119 ;
}
V_109 = F_38 ( V_86 ) ;
F_22 ( V_13 , V_109 ) ;
F_39 ( V_86 ) ;
F_37 ( V_86 ) ;
return F_16 ( V_13 , V_73 ) ;
}
static int F_40 ( struct V_10 * V_13 , int V_73 )
{
T_2 V_120 , V_121 , V_122 ;
T_2 V_123 ;
unsigned int V_124 ;
int error ;
error = F_25 ( V_13 , V_125 >> V_13 -> V_126 , V_73 ) ;
if ( error ) {
if ( ! V_73 )
F_41 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_126 = V_13 -> V_75 . V_98 -
V_127 ;
V_13 -> V_128 = 1 << V_13 -> V_126 ;
V_13 -> V_129 = ( V_13 -> V_75 . V_97 -
sizeof( struct V_130 ) ) / sizeof( V_131 ) ;
V_13 -> V_132 = ( V_13 -> V_75 . V_97 -
sizeof( struct V_133 ) ) / sizeof( V_131 ) ;
V_13 -> V_134 = V_13 -> V_75 . V_97 - sizeof( struct V_133 ) ;
V_13 -> V_135 = V_13 -> V_75 . V_97 / 2 ;
V_13 -> V_136 = V_13 -> V_75 . V_98 - 1 ;
V_13 -> V_137 = V_13 -> V_135 / sizeof( V_131 ) ;
V_13 -> V_138 = ( V_13 -> V_75 . V_97 -
sizeof( struct V_133 ) ) /
sizeof( struct V_139 ) ;
V_13 -> V_140 = ( V_13 -> V_75 . V_97 -
sizeof( struct V_133 ) )
* V_141 ;
V_120 = F_42 ( sizeof( V_131 ) * ( 1 << V_142 ) ,
V_13 -> V_134 ) ;
V_121 = 0 ;
for ( V_123 = V_120 ; V_123 > V_13 -> V_129 ; ) {
V_123 = F_42 ( V_123 , V_13 -> V_132 ) ;
V_121 += V_123 ;
}
V_122 = 2 + V_142 ;
V_13 -> V_143 = V_120 + V_121 + V_122 ;
V_13 -> V_144 [ 0 ] = V_13 -> V_75 . V_97 -
sizeof( struct V_130 ) ;
V_13 -> V_144 [ 1 ] = V_13 -> V_75 . V_97 * V_13 -> V_129 ;
for ( V_124 = 2 ; ; V_124 ++ ) {
V_131 V_145 , V_146 ;
T_2 V_147 ;
V_145 = V_13 -> V_144 [ V_124 - 1 ] * V_13 -> V_132 ;
V_146 = V_145 ;
V_147 = F_43 ( V_146 , V_13 -> V_132 ) ;
if ( V_146 != V_13 -> V_144 [ V_124 - 1 ] || V_147 )
break;
V_13 -> V_144 [ V_124 ] = V_145 ;
}
V_13 -> V_148 = V_124 ;
V_13 -> V_144 [ V_124 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_148 <= V_149 ) ;
V_13 -> V_150 [ 0 ] = V_13 -> V_75 . V_97 -
sizeof( struct V_130 ) ;
V_13 -> V_150 [ 1 ] = V_13 -> V_134 * V_13 -> V_129 ;
for ( V_124 = 2 ; ; V_124 ++ ) {
V_131 V_145 , V_146 ;
T_2 V_147 ;
V_145 = V_13 -> V_150 [ V_124 - 1 ] * V_13 -> V_132 ;
V_146 = V_145 ;
V_147 = F_43 ( V_146 , V_13 -> V_132 ) ;
if ( V_146 != V_13 -> V_150 [ V_124 - 1 ] || V_147 )
break;
V_13 -> V_150 [ V_124 ] = V_145 ;
}
V_13 -> V_151 = V_124 ;
V_13 -> V_150 [ V_124 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_151 <= V_149 ) ;
return 0 ;
}
static int F_45 ( struct V_10 * V_13 , int V_73 )
{
char * V_152 , * V_153 ;
int error = 0 ;
V_152 = V_13 -> V_154 . V_155 ;
V_153 = V_13 -> V_154 . V_156 ;
if ( ! V_152 [ 0 ] || ! V_153 [ 0 ] ) {
error = F_25 ( V_13 , V_125 >> V_13 -> V_126 , V_73 ) ;
if ( error )
return error ;
if ( ! V_152 [ 0 ] )
V_152 = V_13 -> V_75 . V_103 ;
if ( ! V_153 [ 0 ] )
V_153 = V_13 -> V_75 . V_105 ;
}
if ( ! V_153 [ 0 ] )
V_153 = V_13 -> V_18 -> V_157 ;
F_46 ( V_13 -> V_158 , V_152 , V_159 ) ;
F_46 ( V_13 -> V_160 , V_153 , V_159 ) ;
V_153 = V_13 -> V_160 ;
while ( ( V_153 = strchr ( V_153 , '/' ) ) )
* V_153 = '_' ;
return error ;
}
static int F_47 ( struct V_10 * V_13 , struct V_161 * V_162 ,
int V_163 )
{
int error = 0 ;
if ( V_163 )
goto V_164;
error = F_48 ( V_13 ,
V_165 , & V_166 ,
V_167 , V_168 | V_169 ,
V_162 ) ;
if ( error ) {
F_41 ( V_13 , L_5 , error ) ;
goto V_170;
}
error = F_48 ( V_13 ,
V_171 , & V_166 ,
V_172 ,
V_168 | V_173 ,
& V_13 -> V_174 ) ;
if ( error ) {
F_41 ( V_13 , L_6 , error ) ;
goto V_175;
}
error = F_49 ( V_13 , V_176 , & V_166 ,
V_177 , & V_13 -> V_178 ) ;
if ( error ) {
F_41 ( V_13 , L_7 , error ) ;
goto V_179;
}
error = F_49 ( V_13 , V_180 , & V_181 ,
V_177 , & V_13 -> V_182 ) ;
if ( error ) {
F_41 ( V_13 , L_8 , error ) ;
goto V_183;
}
return 0 ;
V_164:
F_50 ( V_13 -> V_182 ) ;
V_183:
F_50 ( V_13 -> V_178 ) ;
V_179:
F_51 ( & V_13 -> V_174 ) ;
V_175:
F_51 ( V_162 ) ;
V_170:
return error ;
}
static int F_52 ( struct V_11 * V_12 , struct V_184 * * V_185 ,
V_131 V_100 , const char * V_186 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_184 * V_184 ;
struct V_187 * V_187 ;
V_187 = F_53 ( V_12 , V_188 , V_100 , 0 , 0 ) ;
if ( F_54 ( V_187 ) ) {
F_41 ( V_13 , L_9 , V_186 , F_55 ( V_187 ) ) ;
return F_55 ( V_187 ) ;
}
V_184 = F_56 ( V_187 ) ;
if ( ! V_184 ) {
F_41 ( V_13 , L_10 , V_186 ) ;
return - V_110 ;
}
* V_185 = V_184 ;
return 0 ;
}
static int F_57 ( struct V_10 * V_13 , int V_73 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_161 V_189 ;
V_131 V_100 ;
int V_190 ;
V_190 = F_48 ( V_13 , V_191 , & V_192 ,
V_172 , 0 , & V_189 ) ;
if ( V_190 ) {
F_41 ( V_13 , L_11 , V_190 ) ;
return V_190 ;
}
V_190 = F_40 ( V_13 , V_73 ) ;
if ( V_190 ) {
F_41 ( V_13 , L_12 , V_190 ) ;
goto V_193;
}
if ( V_13 -> V_75 . V_97 < F_58 ( V_12 -> V_47 ) ) {
V_190 = - V_80 ;
F_41 ( V_13 , L_13
L_14 ,
V_13 -> V_75 . V_97 , F_58 ( V_12 -> V_47 ) ) ;
goto V_193;
}
if ( V_13 -> V_75 . V_97 > V_115 ) {
V_190 = - V_80 ;
F_41 ( V_13 , L_15
L_16 ,
V_13 -> V_75 . V_97 , ( unsigned int ) V_115 ) ;
goto V_193;
}
F_59 ( V_12 , V_13 -> V_75 . V_97 ) ;
V_100 = V_13 -> V_75 . V_102 . V_100 ;
V_190 = F_52 ( V_12 , & V_13 -> V_194 , V_100 , L_17 ) ;
if ( V_190 )
goto V_193;
V_100 = V_13 -> V_75 . V_99 . V_100 ;
V_190 = F_52 ( V_12 , & V_13 -> V_195 , V_100 , L_18 ) ;
if ( V_190 ) {
F_60 ( V_13 -> V_194 ) ;
goto V_193;
}
V_12 -> V_196 = F_61 ( V_13 -> V_154 . V_197 ? V_13 -> V_195 : V_13 -> V_194 ) ;
V_193:
F_51 ( & V_189 ) ;
return V_190 ;
}
static void F_62 ( struct V_10 * V_13 )
{
char * V_198 = L_19 ;
char * V_199 [] = { V_198 , NULL } ;
F_63 ( V_13 , L_20 ) ;
if ( V_13 -> V_200 . V_201 -> V_202 )
V_13 -> V_200 . V_201 -> V_202 ( V_13 ) ;
F_64 ( & V_13 -> V_203 , V_204 , V_199 ) ;
}
static int F_65 ( struct V_10 * V_13 , struct V_161 * V_205 )
{
struct V_206 * V_207 = F_66 ( V_13 -> V_208 ) ;
struct V_209 V_186 ;
char V_88 [ 20 ] ;
struct V_210 * V_211 ;
int error ;
V_186 . V_186 = V_88 ;
F_67 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_68 ( V_207 -> V_212 , V_172 , 0 , V_205 ) ;
if ( error )
break;
V_186 . V_213 = sprintf ( V_88 , L_21 , V_13 -> V_214 ) ;
V_186 . V_215 = F_69 ( V_186 . V_186 , V_186 . V_213 ) ;
error = F_70 ( V_13 -> V_208 , & V_186 , NULL ) ;
if ( error == - V_216 ) {
error = 0 ;
break;
}
F_51 ( V_205 ) ;
if ( error )
break;
error = - V_110 ;
V_211 = F_4 ( sizeof( struct V_210 ) , V_16 ) ;
if ( ! V_211 )
break;
F_11 ( & V_211 -> V_217 ) ;
F_11 ( & V_211 -> V_218 ) ;
F_71 ( & V_211 -> V_219 , V_220 ) ;
V_211 -> V_221 = F_72 ( V_13 -> V_208 , & V_186 , 1 ) ;
if ( ! V_211 -> V_221 || F_54 ( V_211 -> V_221 ) ) {
if ( ! V_211 -> V_221 )
error = - V_216 ;
else
error = F_55 ( V_211 -> V_221 ) ;
F_6 ( V_211 ) ;
break;
}
F_73 ( & V_13 -> V_33 ) ;
V_211 -> V_222 = V_13 -> V_214 ++ ;
F_74 ( & V_211 -> V_223 , & V_13 -> V_32 ) ;
F_75 ( & V_13 -> V_33 ) ;
}
F_76 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_77 ( struct V_10 * V_13 , struct V_210 * V_211 )
{
int error ;
struct V_161 V_224 ;
struct V_225 V_226 ;
struct V_206 * V_227 ;
V_227 = F_66 ( V_211 -> V_221 ) ;
error = F_68 ( V_227 -> V_212 , V_172 , V_168 |
V_173 | V_169 , & V_224 ) ;
if ( error ) {
F_41 ( V_13 , L_22 ) ;
return - V_228 ;
}
error = F_78 ( V_211 ) ;
if ( error ) {
F_41 ( V_13 , L_23 ) ;
goto V_229;
}
error = F_79 ( V_211 , & V_226 ) ;
if ( error ) {
F_41 ( V_13 , L_24 ) ;
goto V_229;
}
if ( ! ( V_226 . V_230 & V_231 ) ) {
error = - V_228 ;
F_41 ( V_13 , L_25
L_26 , V_211 -> V_222 ) ;
}
V_229:
F_51 ( & V_224 ) ;
return error ;
}
static int F_80 ( struct V_10 * V_13 , int V_163 )
{
struct V_187 * V_232 = V_13 -> V_195 -> V_233 ;
struct V_161 V_205 ;
struct V_206 * V_227 ;
int V_234 = 1 ;
int error = 0 ;
if ( V_163 ) {
V_234 = 0 ;
goto V_235;
}
V_13 -> V_208 = F_81 ( V_232 , L_27 ) ;
if ( F_54 ( V_13 -> V_208 ) ) {
F_41 ( V_13 , L_28 , error ) ;
return F_55 ( V_13 -> V_208 ) ;
}
error = F_65 ( V_13 , & V_205 ) ;
if ( error ) {
F_41 ( V_13 , L_29 , error ) ;
goto V_170;
}
error = - V_236 ;
if ( ! F_82 ( V_13 ) ) {
F_41 ( V_13 , L_30 ) ;
goto V_237;
}
if ( V_13 -> V_154 . V_238 ) {
V_13 -> V_239 = F_83 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_240 , V_13 -> V_239 -> V_241 ) ;
F_9 ( & V_13 -> V_242 , 2 * V_13 -> V_239 -> V_241 / 5 ) ;
F_9 ( & V_13 -> V_243 , 4 * V_13 -> V_239 -> V_241 / 5 ) ;
} else {
if ( V_13 -> V_200 . V_244 >= F_82 ( V_13 ) ) {
F_41 ( V_13 , L_31 ,
V_13 -> V_200 . V_244 ) ;
F_41 ( V_13 , L_32 ,
F_82 ( V_13 ) ,
F_82 ( V_13 ) - 1 ) ;
goto V_237;
}
V_13 -> V_239 = F_83 ( V_13 , V_13 -> V_200 . V_244 ) ;
error = F_48 ( V_13 , V_13 -> V_200 . V_244 ,
& V_245 ,
V_167 , V_168 ,
& V_13 -> V_246 ) ;
if ( error ) {
F_41 ( V_13 , L_33 , error ) ;
goto V_237;
}
V_227 = F_66 ( V_13 -> V_239 -> V_221 ) ;
error = F_68 ( V_227 -> V_212 , V_172 ,
V_168 | V_173 | V_169 ,
& V_13 -> V_247 ) ;
if ( error ) {
F_41 ( V_13 , L_34 ,
error ) ;
goto V_248;
}
error = F_78 ( V_13 -> V_239 ) ;
if ( error ) {
F_41 ( V_13 , L_35 ,
V_13 -> V_239 -> V_222 , error ) ;
goto V_235;
}
F_9 ( & V_13 -> V_240 , V_13 -> V_239 -> V_241 ) ;
F_9 ( & V_13 -> V_242 , 2 * V_13 -> V_239 -> V_241 / 5 ) ;
F_9 ( & V_13 -> V_243 , 4 * V_13 -> V_239 -> V_241 / 5 ) ;
F_84 ( V_13 , V_13 -> V_239 ) ;
}
F_85 ( V_13 , F_86 ( & V_13 -> V_240 ) ) ;
if ( V_13 -> V_200 . V_249 ) {
unsigned int V_124 ;
for ( V_124 = 0 ; V_124 < V_13 -> V_214 ; V_124 ++ ) {
struct V_210 * V_211 = F_83 ( V_13 , V_124 ) ;
if ( V_13 -> V_154 . V_238 ) {
error = F_77 ( V_13 , V_211 ) ;
if ( error )
goto V_235;
continue;
}
error = F_87 ( V_211 , true ) ;
if ( error ) {
F_41 ( V_13 , L_36 ,
V_124 , error ) ;
goto V_235;
}
}
F_62 ( V_13 ) ;
} else if ( ! V_13 -> V_154 . V_238 ) {
error = F_87 ( V_13 -> V_239 , true ) ;
if ( error ) {
F_41 ( V_13 , L_37 , error ) ;
goto V_235;
}
}
F_7 ( V_250 , & V_13 -> V_22 ) ;
F_51 ( & V_205 ) ;
V_234 = 0 ;
F_71 ( & V_13 -> V_251 , V_252 ) ;
return 0 ;
V_235:
if ( ! V_13 -> V_154 . V_238 )
F_51 ( & V_13 -> V_247 ) ;
V_248:
if ( ! V_13 -> V_154 . V_238 )
F_51 ( & V_13 -> V_246 ) ;
V_237:
F_88 ( V_13 ) ;
if ( V_234 )
F_51 ( & V_205 ) ;
V_170:
F_89 ( V_13 -> V_208 ) ;
return error ;
}
static int F_90 ( struct V_10 * V_13 , int V_163 )
{
int error = 0 ;
struct V_187 * V_232 = V_13 -> V_195 -> V_233 ;
if ( V_163 )
goto V_253;
error = F_80 ( V_13 , V_163 ) ;
F_91 ( & V_13 -> V_35 ) ;
if ( error )
goto V_170;
V_13 -> V_254 = F_81 ( V_232 , L_38 ) ;
if ( F_54 ( V_13 -> V_254 ) ) {
error = F_55 ( V_13 -> V_254 ) ;
F_41 ( V_13 , L_39 , error ) ;
goto V_255;
}
V_13 -> V_256 = F_81 ( V_232 , L_40 ) ;
if ( F_54 ( V_13 -> V_256 ) ) {
error = F_55 ( V_13 -> V_256 ) ;
F_41 ( V_13 , L_41 , error ) ;
goto V_257;
}
V_13 -> V_258 = 0 ;
V_13 -> V_259 = F_81 ( V_232 , L_42 ) ;
if ( F_54 ( V_13 -> V_259 ) ) {
error = F_55 ( V_13 -> V_259 ) ;
F_41 ( V_13 , L_43 , error ) ;
goto V_260;
}
F_92 ( & V_13 -> V_259 -> V_261 ,
& V_262 ) ;
error = F_93 ( V_13 ) ;
if ( error )
goto V_253;
return 0 ;
V_253:
F_89 ( V_13 -> V_259 ) ;
V_260:
F_94 ( V_13 ) ;
F_89 ( V_13 -> V_256 ) ;
V_257:
F_89 ( V_13 -> V_254 ) ;
V_255:
F_80 ( V_13 , V_263 ) ;
V_170:
return error ;
}
static int F_95 ( struct V_10 * V_13 , int V_163 )
{
struct V_187 * V_264 = NULL ;
char V_88 [ 30 ] ;
int error = 0 ;
struct V_206 * V_227 ;
struct V_187 * V_232 = V_13 -> V_195 -> V_233 ;
if ( V_13 -> V_154 . V_238 )
return 0 ;
if ( V_163 )
goto V_265;
V_264 = F_81 ( V_232 , L_44 ) ;
if ( F_54 ( V_264 ) ) {
error = F_55 ( V_264 ) ;
F_41 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_88 , L_46 , V_13 -> V_239 -> V_222 ) ;
V_13 -> V_266 = F_81 ( V_264 , V_88 ) ;
if ( F_54 ( V_13 -> V_266 ) ) {
error = F_55 ( V_13 -> V_266 ) ;
F_41 ( V_13 , L_47 , error ) ;
goto V_170;
}
sprintf ( V_88 , L_48 , V_13 -> V_239 -> V_222 ) ;
V_13 -> V_267 = F_81 ( V_264 , V_88 ) ;
if ( F_54 ( V_13 -> V_267 ) ) {
error = F_55 ( V_13 -> V_267 ) ;
F_41 ( V_13 , L_49 , error ) ;
goto V_268;
}
F_89 ( V_264 ) ;
V_264 = NULL ;
V_227 = F_66 ( V_13 -> V_266 ) ;
error = F_68 ( V_227 -> V_212 , V_167 , 0 ,
& V_13 -> V_269 ) ;
if ( error ) {
F_41 ( V_13 , L_50 , error ) ;
goto V_270;
}
V_227 = F_66 ( V_13 -> V_267 ) ;
error = F_68 ( V_227 -> V_212 , V_167 , 0 ,
& V_13 -> V_271 ) ;
if ( error ) {
F_41 ( V_13 , L_51 , error ) ;
goto V_272;
}
return 0 ;
V_265:
F_51 ( & V_13 -> V_271 ) ;
V_272:
F_51 ( & V_13 -> V_269 ) ;
V_270:
F_89 ( V_13 -> V_267 ) ;
V_268:
F_89 ( V_13 -> V_266 ) ;
V_170:
if ( V_264 )
F_89 ( V_264 ) ;
return error ;
}
static int F_96 ( struct V_10 * V_13 , int V_73 )
{
const struct V_273 * V_274 ;
struct V_275 * V_276 = & V_13 -> V_200 ;
struct V_277 * args = & V_13 -> V_154 ;
const char * V_152 = V_13 -> V_158 ;
const char * V_153 = V_13 -> V_160 ;
char * V_278 , * V_279 ;
int V_190 ;
if ( ! strcmp ( L_52 , V_152 ) ) {
V_274 = & V_280 ;
V_13 -> V_154 . V_281 = 1 ;
#ifdef F_97
} else if ( ! strcmp ( L_53 , V_152 ) ) {
V_274 = & V_282 ;
#endif
} else {
F_98 ( L_54 , V_152 ) ;
return - V_216 ;
}
F_63 ( V_13 , L_55 , V_152 , V_153 ) ;
V_276 -> V_201 = V_274 ;
V_276 -> V_249 = 1 ;
for ( V_279 = args -> V_283 ; ( V_278 = F_99 ( & V_279 , L_56 ) ) ; ) {
T_3 V_284 [ V_285 ] ;
int V_286 , V_287 ;
if ( ! V_278 || ! * V_278 )
continue;
V_286 = F_100 ( V_278 , * V_274 -> V_288 , V_284 ) ;
switch ( V_286 ) {
case V_289 :
V_190 = F_101 ( & V_284 [ 0 ] , & V_287 ) ;
if ( V_190 || V_287 < 0 )
goto V_290;
if ( F_102 ( V_21 , & V_13 -> V_22 ) )
V_276 -> V_244 = V_287 ;
break;
case V_291 :
case V_292 :
break;
case V_293 :
V_190 = F_101 ( & V_284 [ 0 ] , & V_287 ) ;
if ( V_190 || ( V_287 != 0 && V_287 != 1 ) )
goto V_290;
V_276 -> V_249 = V_287 ;
break;
case V_294 :
default:
V_290:
F_63 ( V_13 , L_57 , V_278 ) ;
return - V_80 ;
}
}
if ( V_274 -> V_295 == NULL ) {
F_63 ( V_13 , L_58 ) ;
F_91 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_190 = V_274 -> V_295 ( V_13 , V_153 ) ;
if ( V_190 == 0 )
F_63 ( V_13 , L_59 ) ;
F_91 ( & V_13 -> V_26 ) ;
return V_190 ;
}
void F_103 ( struct V_10 * V_13 )
{
const struct V_273 * V_274 = V_13 -> V_200 . V_201 ;
if ( F_104 ( ! F_105 ( V_296 , & V_13 -> V_22 ) ) &&
V_274 -> V_297 )
V_274 -> V_297 ( V_13 ) ;
}
static int F_106 ( struct V_10 * V_13 )
{
if ( V_13 -> V_200 . V_201 -> V_295 == NULL )
return 0 ;
return F_107 ( & V_13 -> V_22 , V_21 , V_298 )
? - V_299 : 0 ;
}
void F_108 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_300 [ 20 ] ;
char V_301 [ 20 ] ;
char * V_199 [] = { V_300 , V_301 , NULL } ;
sprintf ( V_300 , L_60 , ( V_12 -> V_302 & V_303 ) ? 1 : 0 ) ;
sprintf ( V_301 , L_61 , V_13 -> V_154 . V_238 ? 1 : 0 ) ;
F_64 ( & V_13 -> V_203 , V_304 , V_199 ) ;
}
static int F_109 ( struct V_11 * V_12 , struct V_277 * args , int V_73 )
{
struct V_10 * V_13 ;
struct V_161 V_162 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( L_62 ) ;
return - V_110 ;
}
V_13 -> V_154 = * args ;
if ( V_13 -> V_154 . V_238 ) {
V_12 -> V_302 |= V_303 ;
F_7 ( V_305 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_154 . V_306 )
V_12 -> V_302 |= V_307 ;
if ( V_13 -> V_154 . V_308 )
F_7 ( V_309 , & V_13 -> V_22 ) ;
V_12 -> V_302 |= V_310 ;
V_12 -> V_311 = V_77 ;
V_12 -> V_312 = & V_313 ;
V_12 -> V_314 = & V_315 ;
V_12 -> V_316 = & V_317 ;
V_12 -> V_318 = V_319 ;
V_12 -> V_320 = & V_321 ;
V_12 -> V_322 = V_323 | V_324 ;
F_110 ( V_12 ) -> V_49 |= V_325 ;
V_12 -> V_326 = 1 ;
V_12 -> V_327 = V_328 ;
V_13 -> V_75 . V_97 = F_111 ( V_12 , V_329 ) ;
V_13 -> V_75 . V_98 = V_12 -> V_330 ;
V_13 -> V_126 = V_13 -> V_75 . V_98 -
V_127 ;
V_13 -> V_128 = 1 << V_13 -> V_126 ;
V_13 -> V_23 . V_331 = V_13 -> V_154 . V_332 ;
V_13 -> V_23 . V_333 = V_13 -> V_154 . V_334 ;
if ( V_13 -> V_154 . V_335 ) {
V_13 -> V_23 . V_336 = 0 ;
V_13 -> V_23 . V_337 = V_13 -> V_154 . V_335 ;
} else {
V_13 -> V_23 . V_336 = 1 ;
V_13 -> V_23 . V_337 = 30 ;
}
error = F_45 ( V_13 , V_73 ) ;
if ( error ) {
F_112 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_338 , V_159 , L_63 , V_13 -> V_160 ) ;
error = F_113 ( V_13 ) ;
if ( error )
return error ;
F_114 ( V_13 ) ;
error = F_96 ( V_13 , V_73 ) ;
if ( error )
goto V_339;
error = F_47 ( V_13 , & V_162 , DO ) ;
if ( error )
goto V_340;
error = F_57 ( V_13 , V_73 ) ;
if ( error )
goto V_341;
error = F_106 ( V_13 ) ;
if ( error )
goto V_342;
if ( V_13 -> V_200 . V_244 < 0 ) {
error = V_13 -> V_200 . V_244 ;
V_13 -> V_200 . V_244 = 0 ;
goto V_342;
}
if ( V_13 -> V_154 . V_238 )
snprintf ( V_13 -> V_338 , V_159 , L_64 ,
V_13 -> V_160 ) ;
else
snprintf ( V_13 -> V_338 , V_159 , L_65 ,
V_13 -> V_160 , V_13 -> V_200 . V_244 ) ;
error = F_90 ( V_13 , DO ) ;
if ( error )
goto V_342;
error = F_95 ( V_13 , DO ) ;
if ( error )
goto V_343;
error = F_115 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_66 , error ) ;
goto V_344;
}
if ( ! ( V_12 -> V_302 & V_303 ) ) {
error = F_116 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_67 , error ) ;
goto V_344;
}
}
F_51 ( & V_162 ) ;
F_108 ( V_13 ) ;
return 0 ;
V_344:
F_95 ( V_13 , V_263 ) ;
V_343:
F_90 ( V_13 , V_263 ) ;
V_342:
if ( V_13 -> V_194 )
F_60 ( V_13 -> V_194 ) ;
if ( V_13 -> V_195 )
F_60 ( V_13 -> V_195 ) ;
if ( V_12 -> V_196 )
F_60 ( V_12 -> V_196 ) ;
V_12 -> V_196 = NULL ;
V_341:
F_47 ( V_13 , & V_162 , V_263 ) ;
V_340:
F_91 ( & V_13 -> V_35 ) ;
F_117 ( V_13 ) ;
F_103 ( V_13 ) ;
V_339:
F_118 ( V_13 ) ;
F_112 ( V_13 -> V_19 ) ;
F_119 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_120 ( struct V_11 * V_89 , void * V_345 )
{
V_89 -> V_47 = V_345 ;
V_89 -> V_346 = V_89 -> V_47 -> V_347 ;
V_89 -> V_53 = & F_121 ( V_89 -> V_47 ) -> V_52 ;
return 0 ;
}
static int F_122 ( struct V_11 * V_89 , void * V_348 )
{
struct V_349 * V_350 = V_348 ;
return ( V_350 == V_89 -> V_47 ) ;
}
static struct V_184 * F_123 ( struct V_351 * V_352 , int V_49 ,
const char * V_353 , void * V_345 )
{
struct V_349 * V_350 ;
struct V_11 * V_89 ;
T_4 V_354 = V_355 | V_356 ;
int error ;
struct V_277 args ;
struct V_10 * V_13 ;
if ( ! ( V_49 & V_303 ) )
V_354 |= V_357 ;
V_350 = F_124 ( V_353 , V_354 , V_352 ) ;
if ( F_54 ( V_350 ) )
return F_125 ( V_350 ) ;
F_67 ( & V_350 -> V_358 ) ;
if ( V_350 -> V_359 > 0 ) {
F_76 ( & V_350 -> V_358 ) ;
error = - V_360 ;
goto V_361;
}
V_89 = F_126 ( V_352 , F_122 , F_120 , V_49 , V_350 ) ;
F_76 ( & V_350 -> V_358 ) ;
error = F_55 ( V_89 ) ;
if ( F_54 ( V_89 ) )
goto V_361;
if ( V_89 -> V_196 ) {
F_127 ( & V_89 -> V_362 ) ;
F_128 ( V_350 , V_354 ) ;
F_129 ( & V_89 -> V_362 ) ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_363 = V_364 ;
args . V_365 = V_366 ;
args . V_332 = 30 ;
args . V_335 = 30 ;
args . V_334 = 60 ;
args . V_367 = V_368 ;
error = F_130 ( & args , V_345 ) ;
if ( error ) {
F_17 ( L_68 ) ;
goto V_369;
}
if ( V_89 -> V_196 ) {
error = - V_360 ;
if ( ( V_49 ^ V_89 -> V_302 ) & V_303 )
goto V_369;
} else {
char V_370 [ V_371 ] ;
V_89 -> V_372 = V_354 ;
F_46 ( V_89 -> V_157 , F_131 ( V_350 , V_370 ) , sizeof( V_89 -> V_157 ) ) ;
F_59 ( V_89 , F_132 ( V_350 ) ) ;
error = F_109 ( V_89 , & args , V_49 & V_373 ? 1 : 0 ) ;
if ( error )
goto V_369;
V_89 -> V_302 |= V_374 ;
V_350 -> V_375 = V_89 ;
}
V_13 = V_89 -> V_17 ;
if ( args . V_197 )
return F_61 ( V_13 -> V_195 ) ;
else
return F_61 ( V_13 -> V_194 ) ;
V_369:
F_133 ( V_89 ) ;
return F_134 ( error ) ;
V_361:
F_128 ( V_350 , V_354 ) ;
return F_134 ( error ) ;
}
static int F_135 ( struct V_11 * V_89 , void * V_348 )
{
return - V_80 ;
}
static struct V_184 * F_136 ( struct V_351 * V_352 ,
int V_49 , const char * V_353 , void * V_345 )
{
struct V_11 * V_89 ;
struct V_10 * V_13 ;
struct V_376 V_376 ;
int error ;
error = F_137 ( V_353 , V_377 , & V_376 ) ;
if ( error ) {
F_17 ( L_69 ,
V_353 , error ) ;
return F_134 ( error ) ;
}
V_89 = F_126 ( & V_378 , F_122 , F_135 , V_49 ,
V_376 . V_184 -> V_233 -> V_379 -> V_47 ) ;
F_138 ( & V_376 ) ;
if ( F_54 ( V_89 ) ) {
F_17 ( L_70 ) ;
return F_125 ( V_89 ) ;
}
if ( ( V_49 ^ V_89 -> V_302 ) & V_303 ) {
F_133 ( V_89 ) ;
return F_134 ( - V_360 ) ;
}
V_13 = V_89 -> V_17 ;
return F_61 ( V_13 -> V_195 ) ;
}
static void F_139 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_140 ( V_12 ) ;
return;
}
F_141 ( V_13 , NULL , V_380 ) ;
F_60 ( V_13 -> V_194 ) ;
F_60 ( V_13 -> V_195 ) ;
V_13 -> V_194 = NULL ;
V_13 -> V_195 = NULL ;
F_142 ( V_12 ) ;
F_118 ( V_13 ) ;
F_112 ( V_13 -> V_19 ) ;
F_140 ( V_12 ) ;
}
