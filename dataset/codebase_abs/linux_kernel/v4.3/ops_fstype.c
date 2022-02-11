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
return 0 ;
}
static int F_45 ( struct V_10 * V_13 , int V_71 )
{
char * V_151 , * V_152 ;
int error = 0 ;
V_151 = V_13 -> V_153 . V_154 ;
V_152 = V_13 -> V_153 . V_155 ;
if ( ! V_151 [ 0 ] || ! V_152 [ 0 ] ) {
error = F_25 ( V_13 , V_124 >> V_13 -> V_125 , V_71 ) ;
if ( error )
return error ;
if ( ! V_151 [ 0 ] )
V_151 = V_13 -> V_73 . V_102 ;
if ( ! V_152 [ 0 ] )
V_152 = V_13 -> V_73 . V_104 ;
}
if ( ! V_152 [ 0 ] )
V_152 = V_13 -> V_18 -> V_156 ;
F_46 ( V_13 -> V_157 , V_151 , V_158 ) ;
F_46 ( V_13 -> V_159 , V_152 , V_158 ) ;
V_152 = V_13 -> V_159 ;
while ( ( V_152 = strchr ( V_152 , '/' ) ) )
* V_152 = '_' ;
return error ;
}
static int F_47 ( struct V_10 * V_13 , struct V_160 * V_161 ,
int V_162 )
{
int error = 0 ;
if ( V_162 )
goto V_163;
error = F_48 ( V_13 ,
V_164 , & V_165 ,
V_166 , V_167 | V_168 ,
V_161 ) ;
if ( error ) {
F_41 ( V_13 , L_5 , error ) ;
goto V_169;
}
error = F_48 ( V_13 ,
V_170 , & V_165 ,
V_171 ,
V_167 | V_172 ,
& V_13 -> V_173 ) ;
if ( error ) {
F_41 ( V_13 , L_6 , error ) ;
goto V_174;
}
error = F_49 ( V_13 , V_175 , & V_165 ,
V_176 , & V_13 -> V_177 ) ;
if ( error ) {
F_41 ( V_13 , L_7 , error ) ;
goto V_178;
}
error = F_49 ( V_13 , V_179 , & V_180 ,
V_176 , & V_13 -> V_181 ) ;
if ( error ) {
F_41 ( V_13 , L_8 , error ) ;
goto V_182;
}
return 0 ;
V_163:
F_50 ( V_13 -> V_181 ) ;
V_182:
F_50 ( V_13 -> V_177 ) ;
V_178:
F_51 ( & V_13 -> V_173 ) ;
V_174:
F_51 ( V_161 ) ;
V_169:
return error ;
}
static int F_52 ( struct V_11 * V_12 , struct V_183 * * V_184 ,
V_130 V_99 , const char * V_185 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_183 * V_183 ;
struct V_186 * V_186 ;
V_186 = F_53 ( V_12 , V_187 , V_99 , 0 , 0 ) ;
if ( F_54 ( V_186 ) ) {
F_41 ( V_13 , L_9 , V_185 , F_55 ( V_186 ) ) ;
return F_55 ( V_186 ) ;
}
V_183 = F_56 ( V_186 ) ;
if ( ! V_183 ) {
F_41 ( V_13 , L_10 , V_185 ) ;
return - V_109 ;
}
* V_184 = V_183 ;
return 0 ;
}
static int F_57 ( struct V_10 * V_13 , int V_71 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_160 V_188 ;
V_130 V_99 ;
int V_189 ;
V_189 = F_48 ( V_13 , V_190 , & V_191 ,
V_171 , 0 , & V_188 ) ;
if ( V_189 ) {
F_41 ( V_13 , L_11 , V_189 ) ;
return V_189 ;
}
V_189 = F_40 ( V_13 , V_71 ) ;
if ( V_189 ) {
F_41 ( V_13 , L_12 , V_189 ) ;
goto V_192;
}
if ( V_13 -> V_73 . V_96 < F_58 ( V_12 -> V_47 ) ) {
V_189 = - V_78 ;
F_41 ( V_13 , L_13
L_14 ,
V_13 -> V_73 . V_96 , F_58 ( V_12 -> V_47 ) ) ;
goto V_192;
}
if ( V_13 -> V_73 . V_96 > V_114 ) {
V_189 = - V_78 ;
F_41 ( V_13 , L_15
L_16 ,
V_13 -> V_73 . V_96 , ( unsigned int ) V_114 ) ;
goto V_192;
}
F_59 ( V_12 , V_13 -> V_73 . V_96 ) ;
V_99 = V_13 -> V_73 . V_101 . V_99 ;
V_189 = F_52 ( V_12 , & V_13 -> V_193 , V_99 , L_17 ) ;
if ( V_189 )
goto V_192;
V_99 = V_13 -> V_73 . V_98 . V_99 ;
V_189 = F_52 ( V_12 , & V_13 -> V_194 , V_99 , L_18 ) ;
if ( V_189 ) {
F_60 ( V_13 -> V_193 ) ;
goto V_192;
}
V_12 -> V_195 = F_61 ( V_13 -> V_153 . V_196 ? V_13 -> V_194 : V_13 -> V_193 ) ;
V_192:
F_51 ( & V_188 ) ;
return V_189 ;
}
static void F_62 ( struct V_10 * V_13 )
{
char * V_197 = L_19 ;
char * V_198 [] = { V_197 , NULL } ;
F_63 ( V_13 , L_20 ) ;
if ( V_13 -> V_199 . V_200 -> V_201 )
V_13 -> V_199 . V_200 -> V_201 ( V_13 ) ;
F_64 ( & V_13 -> V_202 , V_203 , V_198 ) ;
}
static int F_65 ( struct V_10 * V_13 , struct V_160 * V_204 )
{
struct V_205 * V_206 = F_66 ( V_13 -> V_207 ) ;
struct V_208 V_185 ;
char V_87 [ 20 ] ;
struct V_209 * V_210 ;
int error ;
V_185 . V_185 = V_87 ;
F_67 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_68 ( V_206 -> V_211 , V_171 , 0 , V_204 ) ;
if ( error )
break;
V_185 . V_212 = sprintf ( V_87 , L_21 , V_13 -> V_213 ) ;
V_185 . V_214 = F_69 ( V_185 . V_185 , V_185 . V_212 ) ;
error = F_70 ( V_13 -> V_207 , & V_185 , NULL ) ;
if ( error == - V_215 ) {
error = 0 ;
break;
}
F_51 ( V_204 ) ;
if ( error )
break;
error = - V_109 ;
V_210 = F_4 ( sizeof( struct V_209 ) , V_16 ) ;
if ( ! V_210 )
break;
F_11 ( & V_210 -> V_216 ) ;
F_11 ( & V_210 -> V_217 ) ;
F_71 ( & V_210 -> V_218 , V_219 ) ;
V_210 -> V_220 = F_72 ( V_13 -> V_207 , & V_185 , 1 ) ;
if ( ! V_210 -> V_220 || F_54 ( V_210 -> V_220 ) ) {
if ( ! V_210 -> V_220 )
error = - V_215 ;
else
error = F_55 ( V_210 -> V_220 ) ;
F_6 ( V_210 ) ;
break;
}
F_73 ( & V_13 -> V_33 ) ;
V_210 -> V_221 = V_13 -> V_213 ++ ;
F_74 ( & V_210 -> V_222 , & V_13 -> V_32 ) ;
F_75 ( & V_13 -> V_33 ) ;
}
F_76 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_77 ( struct V_10 * V_13 , struct V_209 * V_210 )
{
int error ;
struct V_160 V_223 ;
struct V_224 V_225 ;
struct V_205 * V_226 ;
V_226 = F_66 ( V_210 -> V_220 ) ;
error = F_68 ( V_226 -> V_211 , V_171 , V_167 |
V_172 | V_168 , & V_223 ) ;
if ( error ) {
F_41 ( V_13 , L_22 ) ;
return - V_227 ;
}
error = F_78 ( V_210 ) ;
if ( error ) {
F_41 ( V_13 , L_23 ) ;
goto V_228;
}
error = F_79 ( V_210 , & V_225 ) ;
if ( error ) {
F_41 ( V_13 , L_24 ) ;
goto V_228;
}
if ( ! ( V_225 . V_229 & V_230 ) ) {
error = - V_227 ;
F_41 ( V_13 , L_25
L_26 , V_210 -> V_221 ) ;
}
V_228:
F_51 ( & V_223 ) ;
return error ;
}
static int F_80 ( struct V_10 * V_13 , int V_162 )
{
struct V_186 * V_231 = F_81 ( V_13 -> V_194 ) ;
struct V_160 V_204 ;
struct V_205 * V_226 ;
int V_232 = 1 ;
int error = 0 ;
if ( V_162 ) {
V_232 = 0 ;
goto V_233;
}
V_13 -> V_207 = F_82 ( V_231 , L_27 ) ;
if ( F_54 ( V_13 -> V_207 ) ) {
F_41 ( V_13 , L_28 , error ) ;
return F_55 ( V_13 -> V_207 ) ;
}
error = F_65 ( V_13 , & V_204 ) ;
if ( error ) {
F_41 ( V_13 , L_29 , error ) ;
goto V_169;
}
error = - V_234 ;
if ( ! F_83 ( V_13 ) ) {
F_41 ( V_13 , L_30 ) ;
goto V_235;
}
if ( V_13 -> V_153 . V_236 ) {
V_13 -> V_237 = F_84 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_238 , V_13 -> V_237 -> V_239 ) ;
F_9 ( & V_13 -> V_240 , 2 * V_13 -> V_237 -> V_239 / 5 ) ;
F_9 ( & V_13 -> V_241 , 4 * V_13 -> V_237 -> V_239 / 5 ) ;
} else {
if ( V_13 -> V_199 . V_242 >= F_83 ( V_13 ) ) {
F_41 ( V_13 , L_31 ,
V_13 -> V_199 . V_242 ) ;
F_41 ( V_13 , L_32 ,
F_83 ( V_13 ) ,
F_83 ( V_13 ) - 1 ) ;
goto V_235;
}
V_13 -> V_237 = F_84 ( V_13 , V_13 -> V_199 . V_242 ) ;
error = F_48 ( V_13 , V_13 -> V_199 . V_242 ,
& V_243 ,
V_166 , V_167 ,
& V_13 -> V_244 ) ;
if ( error ) {
F_41 ( V_13 , L_33 , error ) ;
goto V_235;
}
V_226 = F_66 ( V_13 -> V_237 -> V_220 ) ;
error = F_68 ( V_226 -> V_211 , V_171 ,
V_167 | V_172 | V_168 ,
& V_13 -> V_245 ) ;
if ( error ) {
F_41 ( V_13 , L_34 ,
error ) ;
goto V_246;
}
error = F_78 ( V_13 -> V_237 ) ;
if ( error ) {
F_41 ( V_13 , L_35 ,
V_13 -> V_237 -> V_221 , error ) ;
goto V_233;
}
F_9 ( & V_13 -> V_238 , V_13 -> V_237 -> V_239 ) ;
F_9 ( & V_13 -> V_240 , 2 * V_13 -> V_237 -> V_239 / 5 ) ;
F_9 ( & V_13 -> V_241 , 4 * V_13 -> V_237 -> V_239 / 5 ) ;
F_85 ( V_13 , V_13 -> V_237 ) ;
}
F_86 ( V_13 , F_87 ( & V_13 -> V_238 ) ) ;
if ( V_13 -> V_199 . V_247 ) {
unsigned int V_123 ;
for ( V_123 = 0 ; V_123 < V_13 -> V_213 ; V_123 ++ ) {
struct V_209 * V_210 = F_84 ( V_13 , V_123 ) ;
if ( V_13 -> V_153 . V_236 ) {
error = F_77 ( V_13 , V_210 ) ;
if ( error )
goto V_233;
continue;
}
error = F_88 ( V_210 , true ) ;
if ( error ) {
F_41 ( V_13 , L_36 ,
V_123 , error ) ;
goto V_233;
}
}
F_62 ( V_13 ) ;
} else if ( ! V_13 -> V_153 . V_236 ) {
error = F_88 ( V_13 -> V_237 , true ) ;
if ( error ) {
F_41 ( V_13 , L_37 , error ) ;
goto V_233;
}
}
V_13 -> V_248 = 1 ;
F_7 ( V_249 , & V_13 -> V_22 ) ;
F_51 ( & V_204 ) ;
V_232 = 0 ;
F_71 ( & V_13 -> V_250 , V_251 ) ;
return 0 ;
V_233:
if ( ! V_13 -> V_153 . V_236 )
F_51 ( & V_13 -> V_245 ) ;
V_246:
if ( ! V_13 -> V_153 . V_236 )
F_51 ( & V_13 -> V_244 ) ;
V_235:
F_89 ( V_13 ) ;
if ( V_232 )
F_51 ( & V_204 ) ;
V_169:
F_90 ( V_13 -> V_207 ) ;
return error ;
}
static int F_91 ( struct V_10 * V_13 , int V_162 )
{
int error = 0 ;
struct V_186 * V_231 = F_81 ( V_13 -> V_194 ) ;
if ( V_162 )
goto V_252;
error = F_80 ( V_13 , V_162 ) ;
F_92 ( & V_13 -> V_35 ) ;
if ( error )
goto V_169;
V_13 -> V_253 = F_82 ( V_231 , L_38 ) ;
if ( F_54 ( V_13 -> V_253 ) ) {
error = F_55 ( V_13 -> V_253 ) ;
F_41 ( V_13 , L_39 , error ) ;
goto V_254;
}
V_13 -> V_255 = F_82 ( V_231 , L_40 ) ;
if ( F_54 ( V_13 -> V_255 ) ) {
error = F_55 ( V_13 -> V_255 ) ;
F_41 ( V_13 , L_41 , error ) ;
goto V_256;
}
V_13 -> V_257 = 0 ;
V_13 -> V_258 = F_82 ( V_231 , L_42 ) ;
if ( F_54 ( V_13 -> V_258 ) ) {
error = F_55 ( V_13 -> V_258 ) ;
F_41 ( V_13 , L_43 , error ) ;
goto V_259;
}
F_93 ( & V_13 -> V_258 -> V_260 ,
& V_261 ) ;
error = F_94 ( V_13 ) ;
if ( error )
goto V_252;
return 0 ;
V_252:
F_90 ( V_13 -> V_258 ) ;
V_259:
F_95 ( V_13 ) ;
F_90 ( V_13 -> V_255 ) ;
V_256:
F_90 ( V_13 -> V_253 ) ;
V_254:
F_80 ( V_13 , V_262 ) ;
V_169:
return error ;
}
static int F_96 ( struct V_10 * V_13 , int V_162 )
{
struct V_186 * V_263 = NULL ;
char V_87 [ 30 ] ;
int error = 0 ;
struct V_205 * V_226 ;
struct V_186 * V_231 = F_81 ( V_13 -> V_194 ) ;
if ( V_13 -> V_153 . V_236 )
return 0 ;
if ( V_162 )
goto V_264;
V_263 = F_82 ( V_231 , L_44 ) ;
if ( F_54 ( V_263 ) ) {
error = F_55 ( V_263 ) ;
F_41 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_87 , L_46 , V_13 -> V_237 -> V_221 ) ;
V_13 -> V_265 = F_82 ( V_263 , V_87 ) ;
if ( F_54 ( V_13 -> V_265 ) ) {
error = F_55 ( V_13 -> V_265 ) ;
F_41 ( V_13 , L_47 , error ) ;
goto V_169;
}
sprintf ( V_87 , L_48 , V_13 -> V_237 -> V_221 ) ;
V_13 -> V_266 = F_82 ( V_263 , V_87 ) ;
if ( F_54 ( V_13 -> V_266 ) ) {
error = F_55 ( V_13 -> V_266 ) ;
F_41 ( V_13 , L_49 , error ) ;
goto V_267;
}
F_90 ( V_263 ) ;
V_263 = NULL ;
V_226 = F_66 ( V_13 -> V_265 ) ;
error = F_68 ( V_226 -> V_211 , V_166 , 0 ,
& V_13 -> V_268 ) ;
if ( error ) {
F_41 ( V_13 , L_50 , error ) ;
goto V_269;
}
V_226 = F_66 ( V_13 -> V_266 ) ;
error = F_68 ( V_226 -> V_211 , V_166 , 0 ,
& V_13 -> V_270 ) ;
if ( error ) {
F_41 ( V_13 , L_51 , error ) ;
goto V_271;
}
return 0 ;
V_264:
F_51 ( & V_13 -> V_270 ) ;
V_271:
F_51 ( & V_13 -> V_268 ) ;
V_269:
F_90 ( V_13 -> V_266 ) ;
V_267:
F_90 ( V_13 -> V_265 ) ;
V_169:
if ( V_263 )
F_90 ( V_263 ) ;
return error ;
}
static int F_97 ( struct V_10 * V_13 , int V_71 )
{
const struct V_272 * V_273 ;
struct V_274 * V_275 = & V_13 -> V_199 ;
struct V_276 * args = & V_13 -> V_153 ;
const char * V_151 = V_13 -> V_157 ;
const char * V_152 = V_13 -> V_159 ;
char * V_277 , * V_278 ;
int V_189 ;
if ( ! strcmp ( L_52 , V_151 ) ) {
V_273 = & V_279 ;
V_13 -> V_153 . V_280 = 1 ;
#ifdef F_98
} else if ( ! strcmp ( L_53 , V_151 ) ) {
V_273 = & V_281 ;
#endif
} else {
F_99 ( L_54 , V_151 ) ;
return - V_215 ;
}
F_63 ( V_13 , L_55 , V_151 , V_152 ) ;
V_275 -> V_200 = V_273 ;
V_275 -> V_247 = 1 ;
for ( V_278 = args -> V_282 ; ( V_277 = F_100 ( & V_278 , L_56 ) ) ; ) {
T_3 V_283 [ V_284 ] ;
int V_285 , V_286 ;
if ( ! V_277 || ! * V_277 )
continue;
V_285 = F_101 ( V_277 , * V_273 -> V_287 , V_283 ) ;
switch ( V_285 ) {
case V_288 :
V_189 = F_102 ( & V_283 [ 0 ] , & V_286 ) ;
if ( V_189 || V_286 < 0 )
goto V_289;
if ( F_103 ( V_21 , & V_13 -> V_22 ) )
V_275 -> V_242 = V_286 ;
break;
case V_290 :
case V_291 :
break;
case V_292 :
V_189 = F_102 ( & V_283 [ 0 ] , & V_286 ) ;
if ( V_189 || ( V_286 != 0 && V_286 != 1 ) )
goto V_289;
V_275 -> V_247 = V_286 ;
break;
case V_293 :
default:
V_289:
F_63 ( V_13 , L_57 , V_277 ) ;
return - V_78 ;
}
}
if ( V_273 -> V_294 == NULL ) {
F_63 ( V_13 , L_58 ) ;
F_92 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_189 = V_273 -> V_294 ( V_13 , V_152 ) ;
if ( V_189 == 0 )
F_63 ( V_13 , L_59 ) ;
F_92 ( & V_13 -> V_26 ) ;
return V_189 ;
}
void F_104 ( struct V_10 * V_13 )
{
const struct V_272 * V_273 = V_13 -> V_199 . V_200 ;
if ( F_105 ( ! F_106 ( V_295 , & V_13 -> V_22 ) ) &&
V_273 -> V_296 )
V_273 -> V_296 ( V_13 ) ;
}
static int F_107 ( struct V_10 * V_13 )
{
if ( V_13 -> V_199 . V_200 -> V_294 == NULL )
return 0 ;
return F_108 ( & V_13 -> V_22 , V_21 , V_297 )
? - V_298 : 0 ;
}
void F_109 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_299 [ 20 ] ;
char V_300 [ 20 ] ;
char * V_198 [] = { V_299 , V_300 , NULL } ;
sprintf ( V_299 , L_60 , ( V_12 -> V_301 & V_302 ) ? 1 : 0 ) ;
sprintf ( V_300 , L_61 , V_13 -> V_153 . V_236 ? 1 : 0 ) ;
F_64 ( & V_13 -> V_202 , V_303 , V_198 ) ;
}
static int F_110 ( struct V_11 * V_12 , struct V_276 * args , int V_71 )
{
struct V_10 * V_13 ;
struct V_160 V_161 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( L_62 ) ;
return - V_109 ;
}
V_13 -> V_153 = * args ;
if ( V_13 -> V_153 . V_236 ) {
V_12 -> V_301 |= V_302 ;
F_7 ( V_304 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_153 . V_305 )
V_12 -> V_301 |= V_306 ;
if ( V_13 -> V_153 . V_307 )
F_7 ( V_308 , & V_13 -> V_22 ) ;
V_12 -> V_301 |= V_309 ;
V_12 -> V_310 = V_75 ;
V_12 -> V_311 = & V_312 ;
V_12 -> V_313 = & V_314 ;
V_12 -> V_315 = & V_316 ;
V_12 -> V_317 = V_318 ;
V_12 -> V_319 = & V_320 ;
V_12 -> V_321 = V_322 | V_323 ;
F_111 ( V_12 ) -> V_49 |= V_324 ;
V_12 -> V_325 = 1 ;
V_12 -> V_326 = V_327 ;
V_13 -> V_73 . V_96 = F_112 ( V_12 , V_328 ) ;
V_13 -> V_73 . V_97 = V_12 -> V_329 ;
V_13 -> V_125 = V_13 -> V_73 . V_97 -
V_126 ;
V_13 -> V_127 = 1 << V_13 -> V_125 ;
V_13 -> V_23 . V_330 = V_13 -> V_153 . V_331 ;
V_13 -> V_23 . V_332 = V_13 -> V_153 . V_333 ;
if ( V_13 -> V_153 . V_334 ) {
V_13 -> V_23 . V_335 = 0 ;
V_13 -> V_23 . V_336 = V_13 -> V_153 . V_334 ;
} else {
V_13 -> V_23 . V_335 = 1 ;
V_13 -> V_23 . V_336 = 30 ;
}
error = F_45 ( V_13 , V_71 ) ;
if ( error ) {
F_113 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_337 , V_158 , L_63 , V_13 -> V_159 ) ;
error = F_114 ( V_13 ) ;
if ( error )
return error ;
F_115 ( V_13 ) ;
error = F_97 ( V_13 , V_71 ) ;
if ( error )
goto V_338;
error = F_47 ( V_13 , & V_161 , DO ) ;
if ( error )
goto V_339;
error = F_57 ( V_13 , V_71 ) ;
if ( error )
goto V_340;
error = F_107 ( V_13 ) ;
if ( error )
goto V_341;
if ( V_13 -> V_199 . V_242 < 0 ) {
error = V_13 -> V_199 . V_242 ;
V_13 -> V_199 . V_242 = 0 ;
goto V_341;
}
if ( V_13 -> V_153 . V_236 )
snprintf ( V_13 -> V_337 , V_158 , L_64 ,
V_13 -> V_159 ) ;
else
snprintf ( V_13 -> V_337 , V_158 , L_65 ,
V_13 -> V_159 , V_13 -> V_199 . V_242 ) ;
error = F_91 ( V_13 , DO ) ;
if ( error )
goto V_341;
error = F_96 ( V_13 , DO ) ;
if ( error )
goto V_342;
error = F_116 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_66 , error ) ;
goto V_343;
}
if ( ! ( V_12 -> V_301 & V_302 ) ) {
error = F_117 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_67 , error ) ;
goto V_343;
}
}
F_51 ( & V_161 ) ;
F_109 ( V_13 ) ;
return 0 ;
V_343:
F_96 ( V_13 , V_262 ) ;
V_342:
F_91 ( V_13 , V_262 ) ;
V_341:
if ( V_13 -> V_193 )
F_60 ( V_13 -> V_193 ) ;
if ( V_13 -> V_194 )
F_60 ( V_13 -> V_194 ) ;
if ( V_12 -> V_195 )
F_60 ( V_12 -> V_195 ) ;
V_12 -> V_195 = NULL ;
V_340:
F_47 ( V_13 , & V_161 , V_262 ) ;
V_339:
F_92 ( & V_13 -> V_35 ) ;
F_118 ( V_13 ) ;
F_104 ( V_13 ) ;
V_338:
F_119 ( V_13 ) ;
F_113 ( V_13 -> V_19 ) ;
F_120 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_121 ( struct V_11 * V_88 , void * V_344 )
{
V_88 -> V_47 = V_344 ;
V_88 -> V_345 = V_88 -> V_47 -> V_346 ;
V_88 -> V_347 = & F_122 ( V_88 -> V_47 ) -> V_348 ;
return 0 ;
}
static int F_123 ( struct V_11 * V_88 , void * V_349 )
{
struct V_350 * V_351 = V_349 ;
return ( V_351 == V_88 -> V_47 ) ;
}
static struct V_183 * F_124 ( struct V_352 * V_353 , int V_49 ,
const char * V_354 , void * V_344 )
{
struct V_350 * V_351 ;
struct V_11 * V_88 ;
T_4 V_355 = V_356 | V_357 ;
int error ;
struct V_276 args ;
struct V_10 * V_13 ;
if ( ! ( V_49 & V_302 ) )
V_355 |= V_358 ;
V_351 = F_125 ( V_354 , V_355 , V_353 ) ;
if ( F_54 ( V_351 ) )
return F_126 ( V_351 ) ;
F_67 ( & V_351 -> V_359 ) ;
if ( V_351 -> V_360 > 0 ) {
F_76 ( & V_351 -> V_359 ) ;
error = - V_361 ;
goto V_362;
}
V_88 = F_127 ( V_353 , F_123 , F_121 , V_49 , V_351 ) ;
F_76 ( & V_351 -> V_359 ) ;
error = F_55 ( V_88 ) ;
if ( F_54 ( V_88 ) )
goto V_362;
if ( V_88 -> V_195 ) {
F_128 ( & V_88 -> V_363 ) ;
F_129 ( V_351 , V_355 ) ;
F_130 ( & V_88 -> V_363 ) ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_364 = V_365 ;
args . V_366 = V_367 ;
args . V_331 = 30 ;
args . V_334 = 30 ;
args . V_333 = 60 ;
args . V_368 = V_369 ;
error = F_131 ( & args , V_344 ) ;
if ( error ) {
F_17 ( L_68 ) ;
goto V_370;
}
if ( V_88 -> V_195 ) {
error = - V_361 ;
if ( ( V_49 ^ V_88 -> V_301 ) & V_302 )
goto V_370;
} else {
char V_371 [ V_372 ] ;
V_88 -> V_373 = V_355 ;
F_46 ( V_88 -> V_156 , F_132 ( V_351 , V_371 ) , sizeof( V_88 -> V_156 ) ) ;
F_59 ( V_88 , F_133 ( V_351 ) ) ;
error = F_110 ( V_88 , & args , V_49 & V_374 ? 1 : 0 ) ;
if ( error )
goto V_370;
V_88 -> V_301 |= V_375 ;
V_351 -> V_376 = V_88 ;
}
V_13 = V_88 -> V_17 ;
if ( args . V_196 )
return F_61 ( V_13 -> V_194 ) ;
else
return F_61 ( V_13 -> V_193 ) ;
V_370:
F_134 ( V_88 ) ;
return F_135 ( error ) ;
V_362:
F_129 ( V_351 , V_355 ) ;
return F_135 ( error ) ;
}
static int F_136 ( struct V_11 * V_88 , void * V_349 )
{
return - V_78 ;
}
static struct V_183 * F_137 ( struct V_352 * V_353 ,
int V_49 , const char * V_354 , void * V_344 )
{
struct V_11 * V_88 ;
struct V_10 * V_13 ;
struct V_377 V_377 ;
int error ;
error = F_138 ( V_354 , V_378 , & V_377 ) ;
if ( error ) {
F_17 ( L_69 ,
V_354 , error ) ;
return F_135 ( error ) ;
}
V_88 = F_127 ( & V_379 , F_123 , F_136 , V_49 ,
F_81 ( V_377 . V_183 ) -> V_380 -> V_47 ) ;
F_139 ( & V_377 ) ;
if ( F_54 ( V_88 ) ) {
F_17 ( L_70 ) ;
return F_126 ( V_88 ) ;
}
if ( ( V_49 ^ V_88 -> V_301 ) & V_302 ) {
F_134 ( V_88 ) ;
return F_135 ( - V_361 ) ;
}
V_13 = V_88 -> V_17 ;
return F_61 ( V_13 -> V_194 ) ;
}
static void F_140 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_141 ( V_12 ) ;
return;
}
F_142 ( V_13 , NULL , V_381 ) ;
F_60 ( V_13 -> V_193 ) ;
F_60 ( V_13 -> V_194 ) ;
V_13 -> V_193 = NULL ;
V_13 -> V_194 = NULL ;
F_143 ( V_12 ) ;
F_119 ( V_13 ) ;
F_113 ( V_13 -> V_19 ) ;
F_141 ( V_12 ) ;
}
