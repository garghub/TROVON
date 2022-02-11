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
F_8 ( & V_13 -> V_67 ) ;
F_8 ( & V_13 -> V_68 ) ;
F_9 ( & V_13 -> V_69 , 0 ) ;
F_9 ( & V_13 -> V_70 , 0 ) ;
F_8 ( & V_13 -> V_71 ) ;
return V_13 ;
}
static int F_16 ( struct V_10 * V_13 , int V_72 )
{
struct V_73 * V_12 = & V_13 -> V_74 ;
if ( V_12 -> V_75 != V_76 ||
V_12 -> V_77 != V_78 ) {
if ( ! V_72 )
F_17 ( L_1 ) ;
return - V_79 ;
}
if ( V_12 -> V_80 == V_81 &&
V_12 -> V_82 == V_83 )
return 0 ;
F_18 ( V_13 , L_2 ) ;
return - V_79 ;
}
static void F_19 ( struct V_84 * V_84 , int error )
{
struct V_85 * V_85 = V_84 -> V_86 ;
if ( ! error )
F_20 ( V_85 ) ;
else
F_17 ( L_3 , error ) ;
F_21 ( V_85 ) ;
}
static void F_22 ( struct V_10 * V_13 , const void * V_87 )
{
struct V_73 * V_12 = & V_13 -> V_74 ;
struct V_11 * V_88 = V_13 -> V_18 ;
const struct V_89 * V_90 = V_87 ;
V_12 -> V_75 = F_23 ( V_90 -> V_91 . V_92 ) ;
V_12 -> V_77 = F_23 ( V_90 -> V_91 . V_93 ) ;
V_12 -> V_94 = F_23 ( V_90 -> V_91 . V_95 ) ;
V_12 -> V_80 = F_23 ( V_90 -> V_80 ) ;
V_12 -> V_82 = F_23 ( V_90 -> V_82 ) ;
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
static int F_25 ( struct V_10 * V_13 , T_1 V_107 , int V_72 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_89 * V_108 ;
struct V_85 * V_85 ;
struct V_84 * V_84 ;
V_85 = F_26 ( V_50 ) ;
if ( F_27 ( ! V_85 ) )
return - V_109 ;
F_28 ( V_85 ) ;
F_29 ( V_85 ) ;
F_30 ( V_85 ) ;
V_84 = F_31 ( V_50 , 1 ) ;
V_84 -> V_110 . V_111 = V_107 * ( V_12 -> V_112 >> 9 ) ;
V_84 -> V_113 = V_12 -> V_47 ;
F_32 ( V_84 , V_85 , V_114 , 0 ) ;
V_84 -> V_115 = F_19 ;
V_84 -> V_86 = V_85 ;
F_33 ( V_116 | V_117 , V_84 ) ;
F_34 ( V_85 ) ;
F_35 ( V_84 ) ;
if ( ! F_36 ( V_85 ) ) {
F_37 ( V_85 ) ;
return - V_118 ;
}
V_108 = F_38 ( V_85 ) ;
F_22 ( V_13 , V_108 ) ;
F_39 ( V_85 ) ;
F_37 ( V_85 ) ;
return F_16 ( V_13 , V_72 ) ;
}
static int F_40 ( struct V_10 * V_13 , int V_72 )
{
T_2 V_119 , V_120 , V_121 ;
T_2 V_122 ;
unsigned int V_123 ;
int error ;
error = F_25 ( V_13 , V_124 >> V_13 -> V_125 , V_72 ) ;
if ( error ) {
if ( ! V_72 )
F_41 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_125 = V_13 -> V_74 . V_97 -
V_126 ;
V_13 -> V_127 = 1 << V_13 -> V_125 ;
V_13 -> V_128 = ( V_13 -> V_74 . V_96 -
sizeof( struct V_129 ) ) / sizeof( V_130 ) ;
V_13 -> V_131 = ( V_13 -> V_74 . V_96 -
sizeof( struct V_132 ) ) / sizeof( V_130 ) ;
V_13 -> V_133 = V_13 -> V_74 . V_96 - sizeof( struct V_132 ) ;
V_13 -> V_134 = V_13 -> V_74 . V_96 / 2 ;
V_13 -> V_135 = V_13 -> V_74 . V_97 - 1 ;
V_13 -> V_136 = V_13 -> V_134 / sizeof( V_130 ) ;
V_13 -> V_137 = ( V_13 -> V_74 . V_96 -
sizeof( struct V_132 ) ) /
sizeof( struct V_138 ) ;
V_13 -> V_139 = ( V_13 -> V_74 . V_96 -
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
V_13 -> V_143 [ 0 ] = V_13 -> V_74 . V_96 -
sizeof( struct V_129 ) ;
V_13 -> V_143 [ 1 ] = V_13 -> V_74 . V_96 * V_13 -> V_128 ;
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
V_13 -> V_149 [ 0 ] = V_13 -> V_74 . V_96 -
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
static int F_45 ( struct V_10 * V_13 , int V_72 )
{
char * V_151 , * V_152 ;
int error = 0 ;
V_151 = V_13 -> V_153 . V_154 ;
V_152 = V_13 -> V_153 . V_155 ;
if ( ! V_151 [ 0 ] || ! V_152 [ 0 ] ) {
error = F_25 ( V_13 , V_124 >> V_13 -> V_125 , V_72 ) ;
if ( error )
return error ;
if ( ! V_151 [ 0 ] )
V_151 = V_13 -> V_74 . V_102 ;
if ( ! V_152 [ 0 ] )
V_152 = V_13 -> V_74 . V_104 ;
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
static int F_57 ( struct V_10 * V_13 , int V_72 )
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
V_189 = F_40 ( V_13 , V_72 ) ;
if ( V_189 ) {
F_41 ( V_13 , L_12 , V_189 ) ;
goto V_192;
}
if ( V_13 -> V_74 . V_96 < F_58 ( V_12 -> V_47 ) ) {
V_189 = - V_79 ;
F_41 ( V_13 , L_13
L_14 ,
V_13 -> V_74 . V_96 , F_58 ( V_12 -> V_47 ) ) ;
goto V_192;
}
if ( V_13 -> V_74 . V_96 > V_114 ) {
V_189 = - V_79 ;
F_41 ( V_13 , L_15
L_16 ,
V_13 -> V_74 . V_96 , ( unsigned int ) V_114 ) ;
goto V_192;
}
F_59 ( V_12 , V_13 -> V_74 . V_96 ) ;
V_99 = V_13 -> V_74 . V_101 . V_99 ;
V_189 = F_52 ( V_12 , & V_13 -> V_193 , V_99 , L_17 ) ;
if ( V_189 )
goto V_192;
V_99 = V_13 -> V_74 . V_98 . V_99 ;
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
struct V_186 * V_231 = V_13 -> V_194 -> V_232 ;
struct V_160 V_204 ;
struct V_205 * V_226 ;
int V_233 = 1 ;
int error = 0 ;
if ( V_162 ) {
V_233 = 0 ;
goto V_234;
}
V_13 -> V_207 = F_81 ( V_231 , L_27 ) ;
if ( F_54 ( V_13 -> V_207 ) ) {
F_41 ( V_13 , L_28 , error ) ;
return F_55 ( V_13 -> V_207 ) ;
}
error = F_65 ( V_13 , & V_204 ) ;
if ( error ) {
F_41 ( V_13 , L_29 , error ) ;
goto V_169;
}
error = - V_235 ;
if ( ! F_82 ( V_13 ) ) {
F_41 ( V_13 , L_30 ) ;
goto V_236;
}
if ( V_13 -> V_153 . V_237 ) {
V_13 -> V_238 = F_83 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_239 , V_13 -> V_238 -> V_240 ) ;
F_9 ( & V_13 -> V_241 , 2 * V_13 -> V_238 -> V_240 / 5 ) ;
F_9 ( & V_13 -> V_242 , 4 * V_13 -> V_238 -> V_240 / 5 ) ;
} else {
if ( V_13 -> V_199 . V_243 >= F_82 ( V_13 ) ) {
F_41 ( V_13 , L_31 ,
V_13 -> V_199 . V_243 ) ;
F_41 ( V_13 , L_32 ,
F_82 ( V_13 ) ,
F_82 ( V_13 ) - 1 ) ;
goto V_236;
}
V_13 -> V_238 = F_83 ( V_13 , V_13 -> V_199 . V_243 ) ;
error = F_48 ( V_13 , V_13 -> V_199 . V_243 ,
& V_244 ,
V_166 , V_167 ,
& V_13 -> V_245 ) ;
if ( error ) {
F_41 ( V_13 , L_33 , error ) ;
goto V_236;
}
V_226 = F_66 ( V_13 -> V_238 -> V_220 ) ;
error = F_68 ( V_226 -> V_211 , V_171 ,
V_167 | V_172 | V_168 ,
& V_13 -> V_246 ) ;
if ( error ) {
F_41 ( V_13 , L_34 ,
error ) ;
goto V_247;
}
error = F_78 ( V_13 -> V_238 ) ;
if ( error ) {
F_41 ( V_13 , L_35 ,
V_13 -> V_238 -> V_221 , error ) ;
goto V_234;
}
F_9 ( & V_13 -> V_239 , V_13 -> V_238 -> V_240 ) ;
F_9 ( & V_13 -> V_241 , 2 * V_13 -> V_238 -> V_240 / 5 ) ;
F_9 ( & V_13 -> V_242 , 4 * V_13 -> V_238 -> V_240 / 5 ) ;
F_84 ( V_13 , V_13 -> V_238 ) ;
}
F_85 ( V_13 , F_86 ( & V_13 -> V_239 ) ) ;
if ( V_13 -> V_199 . V_248 ) {
unsigned int V_123 ;
for ( V_123 = 0 ; V_123 < V_13 -> V_213 ; V_123 ++ ) {
struct V_209 * V_210 = F_83 ( V_13 , V_123 ) ;
if ( V_13 -> V_153 . V_237 ) {
error = F_77 ( V_13 , V_210 ) ;
if ( error )
goto V_234;
continue;
}
error = F_87 ( V_210 , true ) ;
if ( error ) {
F_41 ( V_13 , L_36 ,
V_123 , error ) ;
goto V_234;
}
}
F_62 ( V_13 ) ;
} else if ( ! V_13 -> V_153 . V_237 ) {
error = F_87 ( V_13 -> V_238 , true ) ;
if ( error ) {
F_41 ( V_13 , L_37 , error ) ;
goto V_234;
}
}
F_7 ( V_249 , & V_13 -> V_22 ) ;
F_51 ( & V_204 ) ;
V_233 = 0 ;
if ( ! V_13 -> V_153 . V_237 ) {
error = F_68 ( V_13 -> V_181 , V_171 , 0 ,
& V_13 -> V_250 ) ;
if ( error ) {
F_41 ( V_13 , L_38 , error ) ;
goto V_234;
}
}
F_51 ( & V_13 -> V_250 ) ;
return 0 ;
V_234:
if ( ! V_13 -> V_153 . V_237 )
F_51 ( & V_13 -> V_246 ) ;
V_247:
if ( ! V_13 -> V_153 . V_237 )
F_51 ( & V_13 -> V_245 ) ;
V_236:
F_88 ( V_13 ) ;
if ( V_233 )
F_51 ( & V_204 ) ;
V_169:
F_89 ( V_13 -> V_207 ) ;
return error ;
}
static int F_90 ( struct V_10 * V_13 , int V_162 )
{
int error = 0 ;
struct V_186 * V_231 = V_13 -> V_194 -> V_232 ;
if ( V_162 )
goto V_251;
error = F_80 ( V_13 , V_162 ) ;
F_91 ( & V_13 -> V_35 ) ;
if ( error )
goto V_169;
V_13 -> V_252 = F_81 ( V_231 , L_39 ) ;
if ( F_54 ( V_13 -> V_252 ) ) {
error = F_55 ( V_13 -> V_252 ) ;
F_41 ( V_13 , L_40 , error ) ;
goto V_253;
}
V_13 -> V_254 = F_81 ( V_231 , L_41 ) ;
if ( F_54 ( V_13 -> V_254 ) ) {
error = F_55 ( V_13 -> V_254 ) ;
F_41 ( V_13 , L_42 , error ) ;
goto V_255;
}
V_13 -> V_256 = 0 ;
V_13 -> V_257 = F_81 ( V_231 , L_43 ) ;
if ( F_54 ( V_13 -> V_257 ) ) {
error = F_55 ( V_13 -> V_257 ) ;
F_41 ( V_13 , L_44 , error ) ;
goto V_258;
}
F_92 ( & V_13 -> V_257 -> V_259 ,
& V_260 ) ;
error = F_93 ( V_13 ) ;
if ( error )
goto V_251;
return 0 ;
V_251:
F_89 ( V_13 -> V_257 ) ;
V_258:
F_94 ( V_13 ) ;
F_89 ( V_13 -> V_254 ) ;
V_255:
F_89 ( V_13 -> V_252 ) ;
V_253:
F_80 ( V_13 , V_261 ) ;
V_169:
return error ;
}
static int F_95 ( struct V_10 * V_13 , int V_162 )
{
struct V_186 * V_262 = NULL ;
char V_87 [ 30 ] ;
int error = 0 ;
struct V_205 * V_226 ;
struct V_186 * V_231 = V_13 -> V_194 -> V_232 ;
if ( V_13 -> V_153 . V_237 )
return 0 ;
if ( V_162 )
goto V_263;
V_262 = F_81 ( V_231 , L_45 ) ;
if ( F_54 ( V_262 ) ) {
error = F_55 ( V_262 ) ;
F_41 ( V_13 , L_46 , error ) ;
return error ;
}
sprintf ( V_87 , L_47 , V_13 -> V_238 -> V_221 ) ;
V_13 -> V_264 = F_81 ( V_262 , V_87 ) ;
if ( F_54 ( V_13 -> V_264 ) ) {
error = F_55 ( V_13 -> V_264 ) ;
F_41 ( V_13 , L_48 , error ) ;
goto V_169;
}
sprintf ( V_87 , L_49 , V_13 -> V_238 -> V_221 ) ;
V_13 -> V_265 = F_81 ( V_262 , V_87 ) ;
if ( F_54 ( V_13 -> V_265 ) ) {
error = F_55 ( V_13 -> V_265 ) ;
F_41 ( V_13 , L_50 , error ) ;
goto V_266;
}
F_89 ( V_262 ) ;
V_262 = NULL ;
V_226 = F_66 ( V_13 -> V_264 ) ;
error = F_68 ( V_226 -> V_211 , V_166 , 0 ,
& V_13 -> V_267 ) ;
if ( error ) {
F_41 ( V_13 , L_51 , error ) ;
goto V_268;
}
V_226 = F_66 ( V_13 -> V_265 ) ;
error = F_68 ( V_226 -> V_211 , V_166 , 0 ,
& V_13 -> V_269 ) ;
if ( error ) {
F_41 ( V_13 , L_52 , error ) ;
goto V_270;
}
return 0 ;
V_263:
F_51 ( & V_13 -> V_269 ) ;
V_270:
F_51 ( & V_13 -> V_267 ) ;
V_268:
F_89 ( V_13 -> V_265 ) ;
V_266:
F_89 ( V_13 -> V_264 ) ;
V_169:
if ( V_262 )
F_89 ( V_262 ) ;
return error ;
}
static int F_96 ( struct V_10 * V_13 , int V_72 )
{
const struct V_271 * V_272 ;
struct V_273 * V_274 = & V_13 -> V_199 ;
struct V_275 * args = & V_13 -> V_153 ;
const char * V_151 = V_13 -> V_157 ;
const char * V_152 = V_13 -> V_159 ;
char * V_276 , * V_277 ;
int V_189 ;
if ( ! strcmp ( L_53 , V_151 ) ) {
V_272 = & V_278 ;
V_13 -> V_153 . V_279 = 1 ;
#ifdef F_97
} else if ( ! strcmp ( L_54 , V_151 ) ) {
V_272 = & V_280 ;
#endif
} else {
F_98 ( L_55 , V_151 ) ;
return - V_215 ;
}
F_63 ( V_13 , L_56 , V_151 , V_152 ) ;
V_274 -> V_200 = V_272 ;
V_274 -> V_248 = 1 ;
for ( V_277 = args -> V_281 ; ( V_276 = F_99 ( & V_277 , L_57 ) ) ; ) {
T_3 V_282 [ V_283 ] ;
int V_284 , V_285 ;
if ( ! V_276 || ! * V_276 )
continue;
V_284 = F_100 ( V_276 , * V_272 -> V_286 , V_282 ) ;
switch ( V_284 ) {
case V_287 :
V_189 = F_101 ( & V_282 [ 0 ] , & V_285 ) ;
if ( V_189 || V_285 < 0 )
goto V_288;
if ( F_102 ( V_21 , & V_13 -> V_22 ) )
V_274 -> V_243 = V_285 ;
break;
case V_289 :
case V_290 :
break;
case V_291 :
V_189 = F_101 ( & V_282 [ 0 ] , & V_285 ) ;
if ( V_189 || ( V_285 != 0 && V_285 != 1 ) )
goto V_288;
V_274 -> V_248 = V_285 ;
break;
case V_292 :
default:
V_288:
F_63 ( V_13 , L_58 , V_276 ) ;
return - V_79 ;
}
}
if ( V_272 -> V_293 == NULL ) {
F_63 ( V_13 , L_59 ) ;
F_91 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_189 = V_272 -> V_293 ( V_13 , V_152 ) ;
if ( V_189 == 0 )
F_63 ( V_13 , L_60 ) ;
F_91 ( & V_13 -> V_26 ) ;
return V_189 ;
}
void F_103 ( struct V_10 * V_13 )
{
const struct V_271 * V_272 = V_13 -> V_199 . V_200 ;
if ( F_104 ( ! F_105 ( V_294 , & V_13 -> V_22 ) ) &&
V_272 -> V_295 )
V_272 -> V_295 ( V_13 ) ;
}
static int F_106 ( struct V_10 * V_13 )
{
if ( V_13 -> V_199 . V_200 -> V_293 == NULL )
return 0 ;
return F_107 ( & V_13 -> V_22 , V_21 , V_296 )
? - V_297 : 0 ;
}
void F_108 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_298 [ 20 ] ;
char V_299 [ 20 ] ;
char * V_198 [] = { V_298 , V_299 , NULL } ;
sprintf ( V_298 , L_61 , ( V_12 -> V_300 & V_301 ) ? 1 : 0 ) ;
sprintf ( V_299 , L_62 , V_13 -> V_153 . V_237 ? 1 : 0 ) ;
F_64 ( & V_13 -> V_202 , V_302 , V_198 ) ;
}
static int F_109 ( struct V_11 * V_12 , struct V_275 * args , int V_72 )
{
struct V_10 * V_13 ;
struct V_160 V_161 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( L_63 ) ;
return - V_109 ;
}
V_13 -> V_153 = * args ;
if ( V_13 -> V_153 . V_237 ) {
V_12 -> V_300 |= V_301 ;
F_7 ( V_303 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_153 . V_304 )
V_12 -> V_300 |= V_305 ;
if ( V_13 -> V_153 . V_306 )
F_7 ( V_307 , & V_13 -> V_22 ) ;
V_12 -> V_300 |= V_308 ;
V_12 -> V_309 = V_76 ;
V_12 -> V_310 = & V_311 ;
V_12 -> V_312 = & V_313 ;
V_12 -> V_314 = & V_315 ;
V_12 -> V_316 = V_317 ;
V_12 -> V_318 = & V_319 ;
F_110 ( V_12 ) -> V_49 |= V_320 ;
V_12 -> V_321 = 1 ;
V_12 -> V_322 = V_323 ;
V_13 -> V_74 . V_96 = F_111 ( V_12 , V_324 ) ;
V_13 -> V_74 . V_97 = V_12 -> V_325 ;
V_13 -> V_125 = V_13 -> V_74 . V_97 -
V_126 ;
V_13 -> V_127 = 1 << V_13 -> V_125 ;
V_13 -> V_23 . V_326 = V_13 -> V_153 . V_327 ;
V_13 -> V_23 . V_328 = V_13 -> V_153 . V_329 ;
if ( V_13 -> V_153 . V_330 ) {
V_13 -> V_23 . V_331 = 0 ;
V_13 -> V_23 . V_332 = V_13 -> V_153 . V_330 ;
} else {
V_13 -> V_23 . V_331 = 1 ;
V_13 -> V_23 . V_332 = 30 ;
}
error = F_45 ( V_13 , V_72 ) ;
if ( error ) {
F_112 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_333 , V_158 , L_64 , V_13 -> V_159 ) ;
error = F_113 ( V_13 ) ;
if ( error )
return error ;
F_114 ( V_13 ) ;
error = F_96 ( V_13 , V_72 ) ;
if ( error )
goto V_334;
error = F_47 ( V_13 , & V_161 , DO ) ;
if ( error )
goto V_335;
error = F_57 ( V_13 , V_72 ) ;
if ( error )
goto V_336;
error = F_106 ( V_13 ) ;
if ( error )
goto V_337;
if ( V_13 -> V_199 . V_243 < 0 ) {
error = V_13 -> V_199 . V_243 ;
V_13 -> V_199 . V_243 = 0 ;
goto V_337;
}
if ( V_13 -> V_153 . V_237 )
snprintf ( V_13 -> V_333 , V_158 , L_65 ,
V_13 -> V_159 ) ;
else
snprintf ( V_13 -> V_333 , V_158 , L_66 ,
V_13 -> V_159 , V_13 -> V_199 . V_243 ) ;
error = F_90 ( V_13 , DO ) ;
if ( error )
goto V_337;
error = F_95 ( V_13 , DO ) ;
if ( error )
goto V_338;
error = F_115 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_67 , error ) ;
goto V_339;
}
if ( ! ( V_12 -> V_300 & V_301 ) ) {
error = F_116 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_68 , error ) ;
goto V_339;
}
}
F_51 ( & V_161 ) ;
F_108 ( V_13 ) ;
return 0 ;
V_339:
F_95 ( V_13 , V_261 ) ;
V_338:
F_90 ( V_13 , V_261 ) ;
V_337:
if ( V_13 -> V_193 )
F_60 ( V_13 -> V_193 ) ;
if ( V_13 -> V_194 )
F_60 ( V_13 -> V_194 ) ;
if ( V_12 -> V_195 )
F_60 ( V_12 -> V_195 ) ;
V_12 -> V_195 = NULL ;
V_336:
F_47 ( V_13 , & V_161 , V_261 ) ;
V_335:
F_91 ( & V_13 -> V_35 ) ;
F_117 ( V_13 ) ;
F_103 ( V_13 ) ;
V_334:
F_118 ( V_13 ) ;
F_112 ( V_13 -> V_19 ) ;
F_119 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_120 ( struct V_11 * V_88 , void * V_340 )
{
V_88 -> V_47 = V_340 ;
V_88 -> V_341 = V_88 -> V_47 -> V_342 ;
V_88 -> V_53 = & F_121 ( V_88 -> V_47 ) -> V_52 ;
return 0 ;
}
static int F_122 ( struct V_11 * V_88 , void * V_343 )
{
struct V_344 * V_345 = V_343 ;
return ( V_345 == V_88 -> V_47 ) ;
}
static struct V_183 * F_123 ( struct V_346 * V_347 , int V_49 ,
const char * V_348 , void * V_340 )
{
struct V_344 * V_345 ;
struct V_11 * V_88 ;
T_4 V_349 = V_350 | V_351 ;
int error ;
struct V_275 args ;
struct V_10 * V_13 ;
if ( ! ( V_49 & V_301 ) )
V_349 |= V_352 ;
V_345 = F_124 ( V_348 , V_349 , V_347 ) ;
if ( F_54 ( V_345 ) )
return F_125 ( V_345 ) ;
F_67 ( & V_345 -> V_353 ) ;
if ( V_345 -> V_354 > 0 ) {
F_76 ( & V_345 -> V_353 ) ;
error = - V_355 ;
goto V_356;
}
V_88 = F_126 ( V_347 , F_122 , F_120 , V_49 , V_345 ) ;
F_76 ( & V_345 -> V_353 ) ;
error = F_55 ( V_88 ) ;
if ( F_54 ( V_88 ) )
goto V_356;
if ( V_88 -> V_195 ) {
F_127 ( & V_88 -> V_357 ) ;
F_128 ( V_345 , V_349 ) ;
F_129 ( & V_88 -> V_357 ) ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_358 = V_359 ;
args . V_360 = V_361 ;
args . V_327 = 30 ;
args . V_330 = 30 ;
args . V_329 = 60 ;
args . V_362 = V_363 ;
error = F_130 ( & args , V_340 ) ;
if ( error ) {
F_17 ( L_69 ) ;
goto V_364;
}
if ( V_88 -> V_195 ) {
error = - V_355 ;
if ( ( V_49 ^ V_88 -> V_300 ) & V_301 )
goto V_364;
} else {
char V_365 [ V_366 ] ;
V_88 -> V_367 = V_349 ;
F_46 ( V_88 -> V_156 , F_131 ( V_345 , V_365 ) , sizeof( V_88 -> V_156 ) ) ;
F_59 ( V_88 , F_132 ( V_345 ) ) ;
error = F_109 ( V_88 , & args , V_49 & V_368 ? 1 : 0 ) ;
if ( error )
goto V_364;
V_88 -> V_300 |= V_369 ;
V_345 -> V_370 = V_88 ;
}
V_13 = V_88 -> V_17 ;
if ( args . V_196 )
return F_61 ( V_13 -> V_194 ) ;
else
return F_61 ( V_13 -> V_193 ) ;
V_364:
F_133 ( V_88 ) ;
return F_134 ( error ) ;
V_356:
F_128 ( V_345 , V_349 ) ;
return F_134 ( error ) ;
}
static int F_135 ( struct V_11 * V_88 , void * V_343 )
{
return - V_79 ;
}
static struct V_183 * F_136 ( struct V_346 * V_347 ,
int V_49 , const char * V_348 , void * V_340 )
{
struct V_11 * V_88 ;
struct V_10 * V_13 ;
struct V_371 V_371 ;
int error ;
error = F_137 ( V_348 , V_372 , & V_371 ) ;
if ( error ) {
F_17 ( L_70 ,
V_348 , error ) ;
return F_134 ( error ) ;
}
V_88 = F_126 ( & V_373 , F_122 , F_135 , V_49 ,
V_371 . V_183 -> V_232 -> V_374 -> V_47 ) ;
F_138 ( & V_371 ) ;
if ( F_54 ( V_88 ) ) {
F_17 ( L_71 ) ;
return F_125 ( V_88 ) ;
}
if ( ( V_49 ^ V_88 -> V_300 ) & V_301 ) {
F_133 ( V_88 ) ;
return F_134 ( - V_355 ) ;
}
V_13 = V_88 -> V_17 ;
return F_61 ( V_13 -> V_194 ) ;
}
static void F_139 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_140 ( V_12 ) ;
return;
}
F_141 ( V_13 , NULL , V_375 ) ;
F_60 ( V_13 -> V_193 ) ;
F_60 ( V_13 -> V_194 ) ;
V_13 -> V_193 = NULL ;
V_13 -> V_194 = NULL ;
F_142 ( V_12 ) ;
F_118 ( V_13 ) ;
F_112 ( V_13 -> V_19 ) ;
F_140 ( V_12 ) ;
}
