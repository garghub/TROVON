static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 64 ;
V_2 -> V_5 = 10 ;
V_2 -> V_6 = 1 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 1 << 18 ;
V_2 -> V_10 = 10 ;
}
static struct V_11 * F_3 ( struct V_12 * V_13 )
{
struct V_11 * V_14 ;
V_14 = F_4 ( sizeof( struct V_11 ) , V_15 ) ;
if ( ! V_14 )
return NULL ;
V_13 -> V_16 = V_14 ;
V_14 -> V_17 = V_13 ;
V_14 -> V_18 = F_5 ( struct V_19 ) ;
if ( ! V_14 -> V_18 ) {
F_6 ( V_14 ) ;
return NULL ;
}
F_7 ( V_20 , & V_14 -> V_21 ) ;
F_1 ( & V_14 -> V_22 ) ;
F_8 ( & V_14 -> V_23 ) ;
F_9 ( & V_14 -> V_24 , 0 ) ;
F_10 ( & V_14 -> V_25 ) ;
F_10 ( & V_14 -> V_26 ) ;
F_2 ( & V_14 -> V_27 ) ;
F_2 ( & V_14 -> V_28 ) ;
V_14 -> V_29 . V_30 = NULL ;
F_11 ( & V_14 -> V_31 ) ;
F_2 ( & V_14 -> V_32 ) ;
F_12 ( & V_14 -> V_33 ) ;
F_11 ( & V_14 -> V_34 ) ;
F_12 ( & V_14 -> V_35 ) ;
F_8 ( & V_14 -> V_36 ) ;
F_11 ( & V_14 -> V_37 ) ;
F_2 ( & V_14 -> V_38 ) ;
F_2 ( & V_14 -> V_39 ) ;
F_9 ( & V_14 -> V_40 , 0 ) ;
F_11 ( & V_14 -> V_41 ) ;
F_11 ( & V_14 -> V_42 ) ;
F_11 ( & V_14 -> V_43 ) ;
F_11 ( & V_14 -> V_44 ) ;
F_2 ( & V_14 -> V_45 ) ;
F_8 ( & V_14 -> V_46 ) ;
F_8 ( & V_14 -> V_47 ) ;
F_2 ( & V_14 -> V_48 ) ;
F_11 ( & V_14 -> V_49 ) ;
F_11 ( & V_14 -> V_50 ) ;
F_13 ( & V_14 -> V_51 ) ;
F_9 ( & V_14 -> V_52 , 0 ) ;
F_8 ( & V_14 -> V_53 ) ;
F_11 ( & V_14 -> V_54 ) ;
return V_14 ;
}
static int F_14 ( struct V_11 * V_14 , int V_55 )
{
struct V_56 * V_13 = & V_14 -> V_57 ;
if ( V_13 -> V_58 != V_59 ||
V_13 -> V_60 != V_61 ) {
if ( ! V_55 )
F_15 ( V_62 L_1 ) ;
return - V_63 ;
}
if ( V_13 -> V_64 == V_65 &&
V_13 -> V_66 == V_67 )
return 0 ;
F_16 ( V_14 , L_2 ) ;
return - V_63 ;
}
static void F_17 ( struct V_68 * V_68 , int error )
{
struct V_69 * V_69 = V_68 -> V_70 ;
if ( ! error )
F_18 ( V_69 ) ;
else
F_15 ( V_62 L_3 , error ) ;
F_19 ( V_69 ) ;
}
static void F_20 ( struct V_11 * V_14 , const void * V_71 )
{
struct V_56 * V_13 = & V_14 -> V_57 ;
struct V_12 * V_72 = V_14 -> V_17 ;
const struct V_73 * V_74 = V_71 ;
V_13 -> V_58 = F_21 ( V_74 -> V_75 . V_76 ) ;
V_13 -> V_60 = F_21 ( V_74 -> V_75 . V_77 ) ;
V_13 -> V_78 = F_21 ( V_74 -> V_75 . V_79 ) ;
V_13 -> V_64 = F_21 ( V_74 -> V_64 ) ;
V_13 -> V_66 = F_21 ( V_74 -> V_66 ) ;
V_13 -> V_80 = F_21 ( V_74 -> V_80 ) ;
V_13 -> V_81 = F_21 ( V_74 -> V_81 ) ;
V_13 -> V_82 . V_83 = F_22 ( V_74 -> V_82 . V_83 ) ;
V_13 -> V_82 . V_84 = F_22 ( V_74 -> V_82 . V_84 ) ;
V_13 -> V_85 . V_83 = F_22 ( V_74 -> V_85 . V_83 ) ;
V_13 -> V_85 . V_84 = F_22 ( V_74 -> V_85 . V_84 ) ;
memcpy ( V_13 -> V_86 , V_74 -> V_86 , V_87 ) ;
memcpy ( V_13 -> V_88 , V_74 -> V_88 , V_87 ) ;
memcpy ( V_72 -> V_89 , V_74 -> V_90 , 16 ) ;
}
static int F_23 ( struct V_11 * V_14 , T_1 V_91 , int V_55 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_73 * V_92 ;
struct V_69 * V_69 ;
struct V_68 * V_68 ;
V_69 = F_24 ( V_93 ) ;
if ( F_25 ( ! V_69 ) )
return - V_94 ;
F_26 ( V_69 ) ;
F_27 ( V_69 ) ;
F_28 ( V_69 ) ;
V_68 = F_29 ( V_93 , 1 ) ;
V_68 -> V_95 = V_91 * ( V_13 -> V_96 >> 9 ) ;
V_68 -> V_97 = V_13 -> V_98 ;
F_30 ( V_68 , V_69 , V_99 , 0 ) ;
V_68 -> V_100 = F_17 ;
V_68 -> V_70 = V_69 ;
F_31 ( V_101 | V_102 , V_68 ) ;
F_32 ( V_69 ) ;
F_33 ( V_68 ) ;
if ( ! F_34 ( V_69 ) ) {
F_35 ( V_69 ) ;
return - V_103 ;
}
V_92 = F_36 ( V_69 ) ;
F_20 ( V_14 , V_92 ) ;
F_37 ( V_69 ) ;
F_35 ( V_69 ) ;
return F_14 ( V_14 , V_55 ) ;
}
static int F_38 ( struct V_11 * V_14 , int V_55 )
{
T_2 V_104 , V_105 , V_106 ;
T_2 V_107 ;
unsigned int V_108 ;
int error ;
error = F_23 ( V_14 , V_109 >> V_14 -> V_110 , V_55 ) ;
if ( error ) {
if ( ! V_55 )
F_39 ( V_14 , L_4 ) ;
return error ;
}
V_14 -> V_110 = V_14 -> V_57 . V_81 -
V_111 ;
V_14 -> V_112 = 1 << V_14 -> V_110 ;
V_14 -> V_113 = ( V_14 -> V_57 . V_80 -
sizeof( struct V_114 ) ) / sizeof( V_115 ) ;
V_14 -> V_116 = ( V_14 -> V_57 . V_80 -
sizeof( struct V_117 ) ) / sizeof( V_115 ) ;
V_14 -> V_118 = V_14 -> V_57 . V_80 - sizeof( struct V_117 ) ;
V_14 -> V_119 = V_14 -> V_57 . V_80 / 2 ;
V_14 -> V_120 = V_14 -> V_57 . V_81 - 1 ;
V_14 -> V_121 = V_14 -> V_119 / sizeof( V_115 ) ;
V_14 -> V_122 = ( V_14 -> V_57 . V_80 -
sizeof( struct V_117 ) ) /
sizeof( struct V_123 ) ;
V_14 -> V_124 = ( V_14 -> V_57 . V_80 -
sizeof( struct V_117 ) )
* V_125 ;
V_104 = F_40 ( sizeof( V_115 ) * ( 1 << V_126 ) ,
V_14 -> V_118 ) ;
V_105 = 0 ;
for ( V_107 = V_104 ; V_107 > V_14 -> V_113 ; ) {
V_107 = F_40 ( V_107 , V_14 -> V_116 ) ;
V_105 += V_107 ;
}
V_106 = 2 + V_126 ;
V_14 -> V_127 = V_104 + V_105 + V_106 ;
V_14 -> V_128 [ 0 ] = V_14 -> V_57 . V_80 -
sizeof( struct V_114 ) ;
V_14 -> V_128 [ 1 ] = V_14 -> V_57 . V_80 * V_14 -> V_113 ;
for ( V_108 = 2 ; ; V_108 ++ ) {
V_115 V_129 , V_130 ;
T_2 V_131 ;
V_129 = V_14 -> V_128 [ V_108 - 1 ] * V_14 -> V_116 ;
V_130 = V_129 ;
V_131 = F_41 ( V_130 , V_14 -> V_116 ) ;
if ( V_130 != V_14 -> V_128 [ V_108 - 1 ] || V_131 )
break;
V_14 -> V_128 [ V_108 ] = V_129 ;
}
V_14 -> V_132 = V_108 ;
V_14 -> V_128 [ V_108 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_132 <= V_133 ) ;
V_14 -> V_134 [ 0 ] = V_14 -> V_57 . V_80 -
sizeof( struct V_114 ) ;
V_14 -> V_134 [ 1 ] = V_14 -> V_118 * V_14 -> V_113 ;
for ( V_108 = 2 ; ; V_108 ++ ) {
V_115 V_129 , V_130 ;
T_2 V_131 ;
V_129 = V_14 -> V_134 [ V_108 - 1 ] * V_14 -> V_116 ;
V_130 = V_129 ;
V_131 = F_41 ( V_130 , V_14 -> V_116 ) ;
if ( V_130 != V_14 -> V_134 [ V_108 - 1 ] || V_131 )
break;
V_14 -> V_134 [ V_108 ] = V_129 ;
}
V_14 -> V_135 = V_108 ;
V_14 -> V_134 [ V_108 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_135 <= V_133 ) ;
return 0 ;
}
static int F_43 ( struct V_11 * V_14 , int V_55 )
{
char * V_136 , * V_137 ;
int error = 0 ;
V_136 = V_14 -> V_138 . V_139 ;
V_137 = V_14 -> V_138 . V_140 ;
if ( ! V_136 [ 0 ] || ! V_137 [ 0 ] ) {
error = F_23 ( V_14 , V_109 >> V_14 -> V_110 , V_55 ) ;
if ( error )
return error ;
if ( ! V_136 [ 0 ] )
V_136 = V_14 -> V_57 . V_86 ;
if ( ! V_137 [ 0 ] )
V_137 = V_14 -> V_57 . V_88 ;
}
if ( ! V_137 [ 0 ] )
V_137 = V_14 -> V_17 -> V_141 ;
F_44 ( V_14 -> V_142 , V_136 , V_143 ) ;
F_44 ( V_14 -> V_144 , V_137 , V_143 ) ;
V_137 = V_14 -> V_144 ;
while ( ( V_137 = strchr ( V_137 , '/' ) ) )
* V_137 = '_' ;
return error ;
}
static int F_45 ( struct V_11 * V_14 , struct V_145 * V_146 ,
int V_147 )
{
int error = 0 ;
if ( V_147 )
goto V_148;
error = F_46 ( V_14 ,
V_149 , & V_150 ,
V_151 , V_152 | V_153 ,
V_146 ) ;
if ( error ) {
F_39 ( V_14 , L_5 , error ) ;
goto V_154;
}
error = F_46 ( V_14 ,
V_155 , & V_150 ,
V_156 ,
V_152 | V_157 ,
& V_14 -> V_158 ) ;
if ( error ) {
F_39 ( V_14 , L_6 , error ) ;
goto V_159;
}
error = F_47 ( V_14 , V_160 , & V_150 ,
V_161 , & V_14 -> V_162 ) ;
if ( error ) {
F_39 ( V_14 , L_7 , error ) ;
goto V_163;
}
error = F_47 ( V_14 , V_164 , & V_165 ,
V_161 , & V_14 -> V_166 ) ;
if ( error ) {
F_39 ( V_14 , L_8 , error ) ;
goto V_167;
}
return 0 ;
V_148:
F_48 ( V_14 -> V_166 ) ;
V_167:
F_48 ( V_14 -> V_162 ) ;
V_163:
F_49 ( & V_14 -> V_158 ) ;
V_159:
F_49 ( V_146 ) ;
V_154:
return error ;
}
static int F_50 ( struct V_12 * V_13 , struct V_168 * * V_169 ,
V_115 V_83 , const char * V_170 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
struct V_168 * V_168 ;
struct V_171 * V_171 ;
V_171 = F_51 ( V_13 , V_172 , V_83 , 0 , 0 ) ;
if ( F_52 ( V_171 ) ) {
F_39 ( V_14 , L_9 , V_170 , F_53 ( V_171 ) ) ;
return F_53 ( V_171 ) ;
}
V_168 = F_54 ( V_171 ) ;
if ( ! V_168 ) {
F_39 ( V_14 , L_10 , V_170 ) ;
return - V_173 ;
}
* V_169 = V_168 ;
return 0 ;
}
static int F_55 ( struct V_11 * V_14 , int V_55 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_145 V_174 ;
V_115 V_83 ;
int V_175 ;
V_175 = F_46 ( V_14 , V_176 , & V_177 ,
V_156 , 0 , & V_174 ) ;
if ( V_175 ) {
F_39 ( V_14 , L_11 , V_175 ) ;
return V_175 ;
}
V_175 = F_38 ( V_14 , V_55 ) ;
if ( V_175 ) {
F_39 ( V_14 , L_12 , V_175 ) ;
goto V_178;
}
if ( V_14 -> V_57 . V_80 < F_56 ( V_13 -> V_98 ) ) {
V_175 = - V_63 ;
F_39 ( V_14 , L_13
L_14 ,
V_14 -> V_57 . V_80 , F_56 ( V_13 -> V_98 ) ) ;
goto V_178;
}
if ( V_14 -> V_57 . V_80 > V_99 ) {
V_175 = - V_63 ;
F_39 ( V_14 , L_15
L_16 ,
V_14 -> V_57 . V_80 , ( unsigned int ) V_99 ) ;
goto V_178;
}
F_57 ( V_13 , V_14 -> V_57 . V_80 ) ;
V_83 = V_14 -> V_57 . V_85 . V_83 ;
V_175 = F_50 ( V_13 , & V_14 -> V_179 , V_83 , L_17 ) ;
if ( V_175 )
goto V_178;
V_83 = V_14 -> V_57 . V_82 . V_83 ;
V_175 = F_50 ( V_13 , & V_14 -> V_180 , V_83 , L_18 ) ;
if ( V_175 ) {
F_58 ( V_14 -> V_179 ) ;
goto V_178;
}
V_13 -> V_181 = F_59 ( V_14 -> V_138 . V_182 ? V_14 -> V_180 : V_14 -> V_179 ) ;
V_178:
F_49 ( & V_174 ) ;
return V_175 ;
}
static int F_60 ( struct V_11 * V_14 )
{
struct V_183 * V_184 = V_14 -> V_185 ;
unsigned int V_186 ;
V_115 V_187 , V_188 ;
struct V_189 * V_190 = F_61 ( V_184 -> V_191 ) ;
struct V_192 * V_193 = NULL ;
struct V_194 V_195 ;
int V_196 = 0 ;
V_188 = 0 ;
for ( V_186 = 0 ; V_186 < V_197 ( V_184 -> V_191 ) > > V_14 -> V_57 . V_81 ; V_186 ++ ) {
V_195 . V_198 = 0 ;
V_195 . V_199 = 0 ;
V_195 . V_200 = 1 << V_190 -> V_201 . V_202 ;
V_196 = F_62 ( V_184 -> V_191 , V_186 , & V_195 , 0 ) ;
V_187 = V_195 . V_199 ;
if ( V_196 || ! V_187 ) {
F_15 ( V_203 L_19
L_20 , V_196 , V_186 , ( unsigned long long ) V_187 ) ;
break;
}
if ( ! V_188 || V_187 != V_188 + 1 ) {
V_193 = F_4 ( sizeof( struct V_192 ) ,
V_15 ) ;
if ( ! V_193 ) {
F_15 ( V_203 L_21
L_22 ) ;
V_196 = - V_173 ;
break;
}
V_193 -> V_204 = V_187 ;
V_193 -> V_205 = V_186 ;
V_193 -> V_206 = 1 ;
F_63 ( & V_193 -> V_207 , & V_184 -> V_207 ) ;
} else {
V_193 -> V_206 ++ ;
}
V_188 = V_187 ;
}
return V_196 ;
}
static void F_64 ( struct V_11 * V_14 )
{
char * V_208 = L_23 ;
char * V_209 [] = { V_208 , NULL } ;
F_65 ( V_14 , L_24 ) ;
if ( V_14 -> V_210 . V_211 -> V_212 )
V_14 -> V_210 . V_211 -> V_212 ( V_14 ) ;
F_66 ( & V_14 -> V_213 , V_214 , V_209 ) ;
}
static int F_67 ( struct V_11 * V_14 , struct V_145 * V_215 )
{
struct V_189 * V_216 = F_61 ( V_14 -> V_217 ) ;
struct V_218 V_170 ;
char V_71 [ 20 ] ;
struct V_183 * V_184 ;
int error ;
V_170 . V_170 = V_71 ;
F_68 ( & V_14 -> V_33 ) ;
for (; ; ) {
error = F_69 ( V_216 -> V_219 , V_156 , 0 , V_215 ) ;
if ( error )
break;
V_170 . V_220 = sprintf ( V_71 , L_25 , V_14 -> V_221 ) ;
V_170 . V_222 = F_70 ( V_170 . V_170 , V_170 . V_220 ) ;
error = F_71 ( V_14 -> V_217 , & V_170 , NULL ) ;
if ( error == - V_223 ) {
error = 0 ;
break;
}
F_49 ( V_215 ) ;
if ( error )
break;
error = - V_173 ;
V_184 = F_4 ( sizeof( struct V_183 ) , V_15 ) ;
if ( ! V_184 )
break;
F_11 ( & V_184 -> V_207 ) ;
F_72 ( & V_184 -> V_224 , V_225 ) ;
V_184 -> V_191 = F_73 ( V_14 -> V_217 , & V_170 , 1 ) ;
if ( ! V_184 -> V_191 || F_52 ( V_184 -> V_191 ) ) {
if ( ! V_184 -> V_191 )
error = - V_223 ;
else
error = F_53 ( V_184 -> V_191 ) ;
F_6 ( V_184 ) ;
break;
}
F_74 ( & V_14 -> V_32 ) ;
V_184 -> V_226 = V_14 -> V_221 ++ ;
F_63 ( & V_184 -> V_227 , & V_14 -> V_31 ) ;
F_75 ( & V_14 -> V_32 ) ;
}
F_76 ( & V_14 -> V_33 ) ;
return error ;
}
static int F_77 ( struct V_11 * V_14 , int V_147 )
{
struct V_171 * V_228 = V_14 -> V_180 -> V_229 ;
struct V_145 V_215 ;
struct V_189 * V_190 ;
int V_230 = 1 ;
int error = 0 ;
if ( V_147 ) {
V_230 = 0 ;
goto V_231;
}
V_14 -> V_217 = F_78 ( V_228 , L_26 ) ;
if ( F_52 ( V_14 -> V_217 ) ) {
F_39 ( V_14 , L_27 , error ) ;
return F_53 ( V_14 -> V_217 ) ;
}
error = F_67 ( V_14 , & V_215 ) ;
if ( error ) {
F_39 ( V_14 , L_28 , error ) ;
goto V_154;
}
error = - V_232 ;
if ( ! F_79 ( V_14 ) ) {
F_39 ( V_14 , L_29 ) ;
goto V_233;
}
if ( V_14 -> V_138 . V_234 ) {
V_14 -> V_185 = F_80 ( V_14 , 0 ) ;
F_9 ( & V_14 -> V_235 , V_14 -> V_185 -> V_236 ) ;
F_9 ( & V_14 -> V_237 , 2 * V_14 -> V_185 -> V_236 / 5 ) ;
F_9 ( & V_14 -> V_238 , 4 * V_14 -> V_185 -> V_236 / 5 ) ;
} else {
if ( V_14 -> V_210 . V_239 >= F_79 ( V_14 ) ) {
F_39 ( V_14 , L_30 ,
V_14 -> V_210 . V_239 ) ;
F_39 ( V_14 , L_31 ,
F_79 ( V_14 ) ,
F_79 ( V_14 ) - 1 ) ;
goto V_233;
}
V_14 -> V_185 = F_80 ( V_14 , V_14 -> V_210 . V_239 ) ;
error = F_46 ( V_14 , V_14 -> V_210 . V_239 ,
& V_240 ,
V_151 , V_152 ,
& V_14 -> V_241 ) ;
if ( error ) {
F_39 ( V_14 , L_32 , error ) ;
goto V_233;
}
V_190 = F_61 ( V_14 -> V_185 -> V_191 ) ;
error = F_69 ( V_190 -> V_219 , V_156 ,
V_152 | V_157 | V_153 ,
& V_14 -> V_242 ) ;
if ( error ) {
F_39 ( V_14 , L_33 ,
error ) ;
goto V_243;
}
error = F_81 ( V_14 -> V_185 ) ;
if ( error ) {
F_39 ( V_14 , L_34 ,
V_14 -> V_185 -> V_226 , error ) ;
goto V_231;
}
F_9 ( & V_14 -> V_235 , V_14 -> V_185 -> V_236 ) ;
F_9 ( & V_14 -> V_237 , 2 * V_14 -> V_185 -> V_236 / 5 ) ;
F_9 ( & V_14 -> V_238 , 4 * V_14 -> V_185 -> V_236 / 5 ) ;
F_60 ( V_14 ) ;
}
F_82 ( V_14 , F_83 ( & V_14 -> V_235 ) ) ;
if ( V_14 -> V_210 . V_244 ) {
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_221 ; V_108 ++ ) {
error = F_84 ( F_80 ( V_14 , V_108 ) ,
true ) ;
if ( error ) {
F_39 ( V_14 , L_35 ,
V_108 , error ) ;
goto V_231;
}
}
F_64 ( V_14 ) ;
} else if ( ! V_14 -> V_138 . V_234 ) {
error = F_84 ( V_14 -> V_185 , true ) ;
if ( error ) {
F_39 ( V_14 , L_36 , error ) ;
goto V_231;
}
}
F_7 ( V_245 , & V_14 -> V_21 ) ;
F_49 ( & V_215 ) ;
V_230 = 0 ;
return 0 ;
V_231:
if ( ! V_14 -> V_138 . V_234 )
F_49 ( & V_14 -> V_242 ) ;
V_243:
if ( ! V_14 -> V_138 . V_234 )
F_49 ( & V_14 -> V_241 ) ;
V_233:
F_85 ( V_14 ) ;
if ( V_230 )
F_49 ( & V_215 ) ;
V_154:
F_86 ( V_14 -> V_217 ) ;
return error ;
}
static int F_87 ( struct V_11 * V_14 , int V_147 )
{
int error = 0 ;
struct V_171 * V_228 = V_14 -> V_180 -> V_229 ;
if ( V_147 )
goto V_246;
error = F_77 ( V_14 , V_147 ) ;
if ( error )
goto V_154;
V_14 -> V_247 = F_78 ( V_228 , L_37 ) ;
if ( F_52 ( V_14 -> V_247 ) ) {
error = F_53 ( V_14 -> V_247 ) ;
F_39 ( V_14 , L_38 , error ) ;
goto V_248;
}
V_14 -> V_249 = F_78 ( V_228 , L_39 ) ;
if ( F_52 ( V_14 -> V_249 ) ) {
error = F_53 ( V_14 -> V_249 ) ;
F_39 ( V_14 , L_40 , error ) ;
goto V_250;
}
V_14 -> V_251 = 0 ;
V_14 -> V_252 = F_78 ( V_228 , L_41 ) ;
if ( F_52 ( V_14 -> V_252 ) ) {
error = F_53 ( V_14 -> V_252 ) ;
F_39 ( V_14 , L_42 , error ) ;
goto V_253;
}
F_88 ( & V_14 -> V_252 -> V_254 ,
& V_255 ) ;
error = F_89 ( V_14 ) ;
if ( error )
goto V_246;
return 0 ;
V_246:
F_86 ( V_14 -> V_252 ) ;
V_253:
F_90 ( V_14 ) ;
F_86 ( V_14 -> V_249 ) ;
V_250:
F_86 ( V_14 -> V_247 ) ;
V_248:
F_77 ( V_14 , V_256 ) ;
V_154:
return error ;
}
static int F_91 ( struct V_11 * V_14 , int V_147 )
{
struct V_171 * V_257 = NULL ;
char V_71 [ 30 ] ;
int error = 0 ;
struct V_189 * V_190 ;
struct V_171 * V_228 = V_14 -> V_180 -> V_229 ;
if ( V_14 -> V_138 . V_234 )
return 0 ;
if ( V_147 )
goto V_258;
V_257 = F_78 ( V_228 , L_43 ) ;
if ( F_52 ( V_257 ) ) {
error = F_53 ( V_257 ) ;
F_39 ( V_14 , L_44 , error ) ;
return error ;
}
sprintf ( V_71 , L_45 , V_14 -> V_185 -> V_226 ) ;
V_14 -> V_259 = F_78 ( V_257 , V_71 ) ;
if ( F_52 ( V_14 -> V_259 ) ) {
error = F_53 ( V_14 -> V_259 ) ;
F_39 ( V_14 , L_46 , error ) ;
goto V_154;
}
sprintf ( V_71 , L_47 , V_14 -> V_185 -> V_226 ) ;
V_14 -> V_260 = F_78 ( V_257 , V_71 ) ;
if ( F_52 ( V_14 -> V_260 ) ) {
error = F_53 ( V_14 -> V_260 ) ;
F_39 ( V_14 , L_48 , error ) ;
goto V_261;
}
F_86 ( V_257 ) ;
V_257 = NULL ;
V_190 = F_61 ( V_14 -> V_259 ) ;
error = F_69 ( V_190 -> V_219 , V_151 , 0 ,
& V_14 -> V_262 ) ;
if ( error ) {
F_39 ( V_14 , L_49 , error ) ;
goto V_263;
}
V_190 = F_61 ( V_14 -> V_260 ) ;
error = F_69 ( V_190 -> V_219 , V_151 , 0 ,
& V_14 -> V_264 ) ;
if ( error ) {
F_39 ( V_14 , L_50 , error ) ;
goto V_265;
}
return 0 ;
V_258:
F_49 ( & V_14 -> V_264 ) ;
V_265:
F_49 ( & V_14 -> V_262 ) ;
V_263:
F_86 ( V_14 -> V_260 ) ;
V_261:
F_86 ( V_14 -> V_259 ) ;
V_154:
if ( V_257 )
F_86 ( V_257 ) ;
return error ;
}
static int F_92 ( struct V_11 * V_14 , int V_147 )
{
struct V_266 * V_92 ;
int error = 0 ;
if ( V_147 )
goto V_267;
V_92 = F_93 ( V_268 , V_14 , L_51 ) ;
error = F_52 ( V_92 ) ;
if ( error ) {
F_39 ( V_14 , L_52 , error ) ;
return error ;
}
V_14 -> V_269 = V_92 ;
V_92 = F_93 ( V_270 , V_14 , L_53 ) ;
error = F_52 ( V_92 ) ;
if ( error ) {
F_39 ( V_14 , L_54 , error ) ;
goto V_154;
}
V_14 -> V_271 = V_92 ;
return 0 ;
V_267:
F_94 ( V_14 -> V_271 ) ;
V_154:
F_94 ( V_14 -> V_269 ) ;
return error ;
}
static int F_95 ( struct V_11 * V_14 , int V_55 )
{
const struct V_272 * V_273 ;
struct V_274 * V_275 = & V_14 -> V_210 ;
struct V_276 * args = & V_14 -> V_138 ;
const char * V_136 = V_14 -> V_142 ;
const char * V_137 = V_14 -> V_144 ;
char * V_277 , * V_278 ;
int V_175 ;
if ( ! strcmp ( L_55 , V_136 ) ) {
V_273 = & V_279 ;
V_14 -> V_138 . V_280 = 1 ;
#ifdef F_96
} else if ( ! strcmp ( L_56 , V_136 ) ) {
V_273 = & V_281 ;
#endif
} else {
F_15 ( V_203 L_57 , V_136 ) ;
return - V_223 ;
}
F_65 ( V_14 , L_58 , V_136 , V_137 ) ;
V_275 -> V_211 = V_273 ;
V_275 -> V_244 = 1 ;
for ( V_278 = args -> V_282 ; ( V_277 = F_97 ( & V_278 , L_59 ) ) ; ) {
T_3 V_283 [ V_284 ] ;
int V_285 , V_286 ;
if ( ! V_277 || ! * V_277 )
continue;
V_285 = F_98 ( V_277 , * V_273 -> V_287 , V_283 ) ;
switch ( V_285 ) {
case V_288 :
V_175 = F_99 ( & V_283 [ 0 ] , & V_286 ) ;
if ( V_175 || V_286 < 0 )
goto V_289;
if ( F_100 ( V_20 , & V_14 -> V_21 ) )
V_275 -> V_239 = V_286 ;
break;
case V_290 :
case V_291 :
break;
case V_292 :
V_175 = F_99 ( & V_283 [ 0 ] , & V_286 ) ;
if ( V_175 || ( V_286 != 0 && V_286 != 1 ) )
goto V_289;
V_275 -> V_244 = V_286 ;
break;
case V_293 :
default:
V_289:
F_65 ( V_14 , L_60 , V_277 ) ;
return - V_63 ;
}
}
if ( V_273 -> V_294 == NULL ) {
F_65 ( V_14 , L_61 ) ;
F_101 ( & V_14 -> V_25 ) ;
return 0 ;
}
V_175 = V_273 -> V_294 ( V_14 , V_137 ) ;
if ( V_175 == 0 )
F_65 ( V_14 , L_62 ) ;
F_101 ( & V_14 -> V_25 ) ;
return V_175 ;
}
void F_102 ( struct V_11 * V_14 )
{
const struct V_272 * V_273 = V_14 -> V_210 . V_211 ;
if ( F_103 ( ! F_104 ( V_295 , & V_14 -> V_21 ) ) &&
V_273 -> V_296 )
V_273 -> V_296 ( V_14 ) ;
}
static int F_105 ( void * V_297 )
{
if ( F_106 ( V_298 ) )
return - V_299 ;
F_107 () ;
return 0 ;
}
static int F_108 ( struct V_11 * V_14 )
{
if ( V_14 -> V_210 . V_211 -> V_294 == NULL )
return 0 ;
return F_109 ( & V_14 -> V_21 , V_20 , F_105 , V_300 ) ;
}
void F_110 ( struct V_11 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
char V_301 [ 20 ] ;
char V_302 [ 20 ] ;
char * V_209 [] = { V_301 , V_302 , NULL } ;
sprintf ( V_301 , L_63 , ( V_13 -> V_303 & V_304 ) ? 1 : 0 ) ;
sprintf ( V_302 , L_64 , V_14 -> V_138 . V_234 ? 1 : 0 ) ;
F_66 ( & V_14 -> V_213 , V_305 , V_209 ) ;
}
static int F_111 ( struct V_12 * V_13 , struct V_276 * args , int V_55 )
{
struct V_11 * V_14 ;
struct V_145 V_146 ;
int error ;
V_14 = F_3 ( V_13 ) ;
if ( ! V_14 ) {
F_15 ( V_62 L_65 ) ;
return - V_173 ;
}
V_14 -> V_138 = * args ;
if ( V_14 -> V_138 . V_234 ) {
V_13 -> V_303 |= V_304 ;
F_7 ( V_306 , & V_14 -> V_21 ) ;
}
if ( V_14 -> V_138 . V_307 )
V_13 -> V_303 |= V_308 ;
if ( V_14 -> V_138 . V_309 )
F_7 ( V_310 , & V_14 -> V_21 ) ;
V_13 -> V_303 |= V_311 ;
V_13 -> V_312 = V_59 ;
V_13 -> V_313 = & V_314 ;
V_13 -> V_315 = & V_316 ;
V_13 -> V_317 = & V_318 ;
V_13 -> V_319 = V_320 ;
V_13 -> V_321 = & V_322 ;
F_112 ( V_13 ) -> V_323 |= V_324 ;
V_13 -> V_325 = 1 ;
V_13 -> V_326 = V_327 ;
V_14 -> V_57 . V_80 = F_113 ( V_13 , V_328 ) ;
V_14 -> V_57 . V_81 = V_13 -> V_329 ;
V_14 -> V_110 = V_14 -> V_57 . V_81 -
V_111 ;
V_14 -> V_112 = 1 << V_14 -> V_110 ;
V_14 -> V_22 . V_330 = V_14 -> V_138 . V_331 ;
V_14 -> V_22 . V_332 = V_14 -> V_138 . V_333 ;
if ( V_14 -> V_138 . V_334 ) {
V_14 -> V_22 . V_335 = 0 ;
V_14 -> V_22 . V_336 = V_14 -> V_138 . V_334 ;
} else {
V_14 -> V_22 . V_335 = 1 ;
V_14 -> V_22 . V_336 = 30 ;
}
error = F_43 ( V_14 , V_55 ) ;
if ( error ) {
F_114 ( V_14 -> V_18 ) ;
F_6 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
snprintf ( V_14 -> V_337 , V_143 , L_66 , V_14 -> V_144 ) ;
error = F_115 ( V_14 ) ;
if ( error )
return error ;
F_116 ( V_14 ) ;
error = F_95 ( V_14 , V_55 ) ;
if ( error )
goto V_338;
error = F_45 ( V_14 , & V_146 , DO ) ;
if ( error )
goto V_339;
error = F_55 ( V_14 , V_55 ) ;
if ( error )
goto V_340;
error = F_108 ( V_14 ) ;
if ( error )
goto V_341;
if ( V_14 -> V_210 . V_239 < 0 ) {
error = V_14 -> V_210 . V_239 ;
V_14 -> V_210 . V_239 = 0 ;
goto V_341;
}
if ( V_14 -> V_138 . V_234 )
snprintf ( V_14 -> V_337 , V_143 , L_67 ,
V_14 -> V_144 ) ;
else
snprintf ( V_14 -> V_337 , V_143 , L_68 ,
V_14 -> V_144 , V_14 -> V_210 . V_239 ) ;
error = F_87 ( V_14 , DO ) ;
if ( error )
goto V_341;
error = F_91 ( V_14 , DO ) ;
if ( error )
goto V_342;
error = F_117 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_69 , error ) ;
goto V_343;
}
error = F_92 ( V_14 , DO ) ;
if ( error )
goto V_343;
if ( ! ( V_13 -> V_303 & V_304 ) ) {
error = F_118 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_70 , error ) ;
goto V_344;
}
}
F_49 ( & V_146 ) ;
F_110 ( V_14 ) ;
return 0 ;
V_344:
F_92 ( V_14 , V_256 ) ;
V_343:
F_91 ( V_14 , V_256 ) ;
V_342:
F_87 ( V_14 , V_256 ) ;
V_341:
if ( V_14 -> V_179 )
F_58 ( V_14 -> V_179 ) ;
if ( V_14 -> V_180 )
F_58 ( V_14 -> V_180 ) ;
if ( V_13 -> V_181 )
F_58 ( V_13 -> V_181 ) ;
V_13 -> V_181 = NULL ;
V_340:
F_45 ( V_14 , & V_146 , V_256 ) ;
V_339:
F_119 ( V_14 ) ;
F_102 ( V_14 ) ;
V_338:
F_120 ( V_14 ) ;
F_114 ( V_14 -> V_18 ) ;
F_121 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
static int F_122 ( struct V_12 * V_72 , void * V_345 )
{
V_72 -> V_98 = V_345 ;
V_72 -> V_346 = V_72 -> V_98 -> V_347 ;
V_72 -> V_348 = & F_123 ( V_72 -> V_98 ) -> V_349 ;
return 0 ;
}
static int F_124 ( struct V_12 * V_72 , void * V_350 )
{
struct V_351 * V_352 = V_350 ;
return ( V_352 == V_72 -> V_98 ) ;
}
static struct V_168 * F_125 ( struct V_353 * V_354 , int V_323 ,
const char * V_355 , void * V_345 )
{
struct V_351 * V_352 ;
struct V_12 * V_72 ;
T_4 V_356 = V_357 | V_358 ;
int error ;
struct V_276 args ;
struct V_11 * V_14 ;
if ( ! ( V_323 & V_304 ) )
V_356 |= V_359 ;
V_352 = F_126 ( V_355 , V_356 , V_354 ) ;
if ( F_52 ( V_352 ) )
return F_127 ( V_352 ) ;
F_68 ( & V_352 -> V_360 ) ;
if ( V_352 -> V_361 > 0 ) {
F_76 ( & V_352 -> V_360 ) ;
error = - V_362 ;
goto V_363;
}
V_72 = F_128 ( V_354 , F_124 , F_122 , V_323 , V_352 ) ;
F_76 ( & V_352 -> V_360 ) ;
error = F_53 ( V_72 ) ;
if ( F_52 ( V_72 ) )
goto V_363;
if ( V_72 -> V_181 )
F_129 ( V_352 , V_356 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_364 = V_365 ;
args . V_366 = V_367 ;
args . V_331 = 30 ;
args . V_334 = 30 ;
args . V_333 = 60 ;
args . V_368 = V_369 ;
error = F_130 ( & args , V_345 ) ;
if ( error ) {
F_15 ( V_62 L_71 ) ;
goto V_370;
}
if ( V_72 -> V_181 ) {
error = - V_362 ;
if ( ( V_323 ^ V_72 -> V_303 ) & V_304 )
goto V_370;
} else {
char V_371 [ V_372 ] ;
V_72 -> V_373 = V_356 ;
F_44 ( V_72 -> V_141 , F_131 ( V_352 , V_371 ) , sizeof( V_72 -> V_141 ) ) ;
F_57 ( V_72 , F_132 ( V_352 ) ) ;
error = F_111 ( V_72 , & args , V_323 & V_374 ? 1 : 0 ) ;
if ( error )
goto V_370;
V_72 -> V_303 |= V_375 ;
V_352 -> V_376 = V_72 ;
}
V_14 = V_72 -> V_16 ;
if ( args . V_182 )
return F_59 ( V_14 -> V_180 ) ;
else
return F_59 ( V_14 -> V_179 ) ;
V_370:
F_133 ( V_72 ) ;
return F_134 ( error ) ;
V_363:
F_129 ( V_352 , V_356 ) ;
return F_134 ( error ) ;
}
static int F_135 ( struct V_12 * V_72 , void * V_350 )
{
return - V_63 ;
}
static struct V_168 * F_136 ( struct V_353 * V_354 ,
int V_323 , const char * V_355 , void * V_345 )
{
struct V_12 * V_72 ;
struct V_11 * V_14 ;
struct V_377 V_377 ;
int error ;
error = F_137 ( V_355 , V_378 , & V_377 ) ;
if ( error ) {
F_15 ( V_62 L_72 ,
V_355 , error ) ;
return F_134 ( error ) ;
}
V_72 = F_128 ( & V_379 , F_124 , F_135 , V_323 ,
V_377 . V_168 -> V_229 -> V_380 -> V_98 ) ;
F_138 ( & V_377 ) ;
if ( F_52 ( V_72 ) ) {
F_15 ( V_62 L_73 ) ;
return F_127 ( V_72 ) ;
}
if ( ( V_323 ^ V_72 -> V_303 ) & V_304 ) {
F_133 ( V_72 ) ;
return F_134 ( - V_362 ) ;
}
V_14 = V_72 -> V_16 ;
return F_59 ( V_14 -> V_180 ) ;
}
static void F_139 ( struct V_12 * V_13 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
if ( V_14 == NULL ) {
F_140 ( V_13 ) ;
return;
}
F_141 ( V_14 ) ;
F_58 ( V_14 -> V_179 ) ;
F_58 ( V_14 -> V_180 ) ;
V_14 -> V_179 = NULL ;
V_14 -> V_180 = NULL ;
F_142 ( V_13 ) ;
F_120 ( V_14 ) ;
F_114 ( V_14 -> V_18 ) ;
F_140 ( V_13 ) ;
}
