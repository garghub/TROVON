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
F_2 ( & V_14 -> V_26 ) ;
F_2 ( & V_14 -> V_27 ) ;
V_14 -> V_28 . V_29 = NULL ;
F_11 ( & V_14 -> V_30 ) ;
F_2 ( & V_14 -> V_31 ) ;
F_12 ( & V_14 -> V_32 ) ;
F_11 ( & V_14 -> V_33 ) ;
F_12 ( & V_14 -> V_34 ) ;
F_8 ( & V_14 -> V_35 ) ;
F_11 ( & V_14 -> V_36 ) ;
F_2 ( & V_14 -> V_37 ) ;
F_2 ( & V_14 -> V_38 ) ;
F_9 ( & V_14 -> V_39 , 0 ) ;
F_11 ( & V_14 -> V_40 ) ;
F_11 ( & V_14 -> V_41 ) ;
F_11 ( & V_14 -> V_42 ) ;
F_11 ( & V_14 -> V_43 ) ;
F_8 ( & V_14 -> V_44 ) ;
F_8 ( & V_14 -> V_45 ) ;
F_2 ( & V_14 -> V_46 ) ;
F_11 ( & V_14 -> V_47 ) ;
F_11 ( & V_14 -> V_48 ) ;
F_13 ( & V_14 -> V_49 ) ;
F_9 ( & V_14 -> V_50 , 0 ) ;
F_8 ( & V_14 -> V_51 ) ;
F_11 ( & V_14 -> V_52 ) ;
F_12 ( & V_14 -> V_53 ) ;
return V_14 ;
}
static int F_14 ( struct V_11 * V_14 , int V_54 )
{
struct V_55 * V_13 = & V_14 -> V_56 ;
if ( V_13 -> V_57 != V_58 ||
V_13 -> V_59 != V_60 ) {
if ( ! V_54 )
F_15 ( V_61 L_1 ) ;
return - V_62 ;
}
if ( V_13 -> V_63 == V_64 &&
V_13 -> V_65 == V_66 )
return 0 ;
F_16 ( V_14 , L_2 ) ;
return - V_62 ;
}
static void F_17 ( struct V_67 * V_67 , int error )
{
struct V_68 * V_68 = V_67 -> V_69 ;
if ( ! error )
F_18 ( V_68 ) ;
else
F_15 ( V_61 L_3 , error ) ;
F_19 ( V_68 ) ;
}
static void F_20 ( struct V_11 * V_14 , const void * V_70 )
{
struct V_55 * V_13 = & V_14 -> V_56 ;
struct V_12 * V_71 = V_14 -> V_17 ;
const struct V_72 * V_73 = V_70 ;
V_13 -> V_57 = F_21 ( V_73 -> V_74 . V_75 ) ;
V_13 -> V_59 = F_21 ( V_73 -> V_74 . V_76 ) ;
V_13 -> V_77 = F_21 ( V_73 -> V_74 . V_78 ) ;
V_13 -> V_63 = F_21 ( V_73 -> V_63 ) ;
V_13 -> V_65 = F_21 ( V_73 -> V_65 ) ;
V_13 -> V_79 = F_21 ( V_73 -> V_79 ) ;
V_13 -> V_80 = F_21 ( V_73 -> V_80 ) ;
V_13 -> V_81 . V_82 = F_22 ( V_73 -> V_81 . V_82 ) ;
V_13 -> V_81 . V_83 = F_22 ( V_73 -> V_81 . V_83 ) ;
V_13 -> V_84 . V_82 = F_22 ( V_73 -> V_84 . V_82 ) ;
V_13 -> V_84 . V_83 = F_22 ( V_73 -> V_84 . V_83 ) ;
memcpy ( V_13 -> V_85 , V_73 -> V_85 , V_86 ) ;
memcpy ( V_13 -> V_87 , V_73 -> V_87 , V_86 ) ;
memcpy ( V_71 -> V_88 , V_73 -> V_89 , 16 ) ;
}
static int F_23 ( struct V_11 * V_14 , T_1 V_90 , int V_54 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_72 * V_91 ;
struct V_68 * V_68 ;
struct V_67 * V_67 ;
V_68 = F_24 ( V_92 ) ;
if ( F_25 ( ! V_68 ) )
return - V_93 ;
F_26 ( V_68 ) ;
F_27 ( V_68 ) ;
F_28 ( V_68 ) ;
V_67 = F_29 ( V_92 , 1 ) ;
V_67 -> V_94 = V_90 * ( V_13 -> V_95 >> 9 ) ;
V_67 -> V_96 = V_13 -> V_97 ;
F_30 ( V_67 , V_68 , V_98 , 0 ) ;
V_67 -> V_99 = F_17 ;
V_67 -> V_69 = V_68 ;
F_31 ( V_100 | V_101 , V_67 ) ;
F_32 ( V_68 ) ;
F_33 ( V_67 ) ;
if ( ! F_34 ( V_68 ) ) {
F_35 ( V_68 ) ;
return - V_102 ;
}
V_91 = F_36 ( V_68 ) ;
F_20 ( V_14 , V_91 ) ;
F_37 ( V_68 ) ;
F_35 ( V_68 ) ;
return F_14 ( V_14 , V_54 ) ;
}
static int F_38 ( struct V_11 * V_14 , int V_54 )
{
T_2 V_103 , V_104 , V_105 ;
T_2 V_106 ;
unsigned int V_107 ;
int error ;
error = F_23 ( V_14 , V_108 >> V_14 -> V_109 , V_54 ) ;
if ( error ) {
if ( ! V_54 )
F_39 ( V_14 , L_4 ) ;
return error ;
}
V_14 -> V_109 = V_14 -> V_56 . V_80 -
V_110 ;
V_14 -> V_111 = 1 << V_14 -> V_109 ;
V_14 -> V_112 = ( V_14 -> V_56 . V_79 -
sizeof( struct V_113 ) ) / sizeof( V_114 ) ;
V_14 -> V_115 = ( V_14 -> V_56 . V_79 -
sizeof( struct V_116 ) ) / sizeof( V_114 ) ;
V_14 -> V_117 = V_14 -> V_56 . V_79 - sizeof( struct V_116 ) ;
V_14 -> V_118 = V_14 -> V_56 . V_79 / 2 ;
V_14 -> V_119 = V_14 -> V_56 . V_80 - 1 ;
V_14 -> V_120 = V_14 -> V_118 / sizeof( V_114 ) ;
V_14 -> V_121 = ( V_14 -> V_56 . V_79 -
sizeof( struct V_116 ) ) /
sizeof( struct V_122 ) ;
V_14 -> V_123 = ( V_14 -> V_56 . V_79 -
sizeof( struct V_116 ) )
* V_124 ;
V_103 = F_40 ( sizeof( V_114 ) * ( 1 << V_125 ) ,
V_14 -> V_117 ) ;
V_104 = 0 ;
for ( V_106 = V_103 ; V_106 > V_14 -> V_112 ; ) {
V_106 = F_40 ( V_106 , V_14 -> V_115 ) ;
V_104 += V_106 ;
}
V_105 = 2 + V_125 ;
V_14 -> V_126 = V_103 + V_104 + V_105 ;
V_14 -> V_127 [ 0 ] = V_14 -> V_56 . V_79 -
sizeof( struct V_113 ) ;
V_14 -> V_127 [ 1 ] = V_14 -> V_56 . V_79 * V_14 -> V_112 ;
for ( V_107 = 2 ; ; V_107 ++ ) {
V_114 V_128 , V_129 ;
T_2 V_130 ;
V_128 = V_14 -> V_127 [ V_107 - 1 ] * V_14 -> V_115 ;
V_129 = V_128 ;
V_130 = F_41 ( V_129 , V_14 -> V_115 ) ;
if ( V_129 != V_14 -> V_127 [ V_107 - 1 ] || V_130 )
break;
V_14 -> V_127 [ V_107 ] = V_128 ;
}
V_14 -> V_131 = V_107 ;
V_14 -> V_127 [ V_107 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_131 <= V_132 ) ;
V_14 -> V_133 [ 0 ] = V_14 -> V_56 . V_79 -
sizeof( struct V_113 ) ;
V_14 -> V_133 [ 1 ] = V_14 -> V_117 * V_14 -> V_112 ;
for ( V_107 = 2 ; ; V_107 ++ ) {
V_114 V_128 , V_129 ;
T_2 V_130 ;
V_128 = V_14 -> V_133 [ V_107 - 1 ] * V_14 -> V_115 ;
V_129 = V_128 ;
V_130 = F_41 ( V_129 , V_14 -> V_115 ) ;
if ( V_129 != V_14 -> V_133 [ V_107 - 1 ] || V_130 )
break;
V_14 -> V_133 [ V_107 ] = V_128 ;
}
V_14 -> V_134 = V_107 ;
V_14 -> V_133 [ V_107 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_134 <= V_132 ) ;
return 0 ;
}
static int F_43 ( struct V_11 * V_14 , int V_54 )
{
char * V_135 , * V_136 ;
int error = 0 ;
V_135 = V_14 -> V_137 . V_138 ;
V_136 = V_14 -> V_137 . V_139 ;
if ( ! V_135 [ 0 ] || ! V_136 [ 0 ] ) {
error = F_23 ( V_14 , V_108 >> V_14 -> V_109 , V_54 ) ;
if ( error )
return error ;
if ( ! V_135 [ 0 ] )
V_135 = V_14 -> V_56 . V_85 ;
if ( ! V_136 [ 0 ] )
V_136 = V_14 -> V_56 . V_87 ;
}
if ( ! V_136 [ 0 ] )
V_136 = V_14 -> V_17 -> V_140 ;
F_44 ( V_14 -> V_141 , V_135 , V_142 ) ;
F_44 ( V_14 -> V_143 , V_136 , V_142 ) ;
V_136 = V_14 -> V_143 ;
while ( ( V_136 = strchr ( V_136 , '/' ) ) )
* V_136 = '_' ;
return error ;
}
static int F_45 ( struct V_11 * V_14 , struct V_144 * V_145 ,
int V_146 )
{
int error = 0 ;
if ( V_146 )
goto V_147;
error = F_46 ( V_14 ,
V_148 , & V_149 ,
V_150 , V_151 | V_152 ,
V_145 ) ;
if ( error ) {
F_39 ( V_14 , L_5 , error ) ;
goto V_153;
}
error = F_46 ( V_14 ,
V_154 , & V_149 ,
V_155 ,
V_151 | V_156 ,
& V_14 -> V_157 ) ;
if ( error ) {
F_39 ( V_14 , L_6 , error ) ;
goto V_158;
}
error = F_47 ( V_14 , V_159 , & V_149 ,
V_160 , & V_14 -> V_161 ) ;
if ( error ) {
F_39 ( V_14 , L_7 , error ) ;
goto V_162;
}
error = F_47 ( V_14 , V_163 , & V_164 ,
V_160 , & V_14 -> V_165 ) ;
if ( error ) {
F_39 ( V_14 , L_8 , error ) ;
goto V_166;
}
return 0 ;
V_147:
F_48 ( V_14 -> V_165 ) ;
V_166:
F_48 ( V_14 -> V_161 ) ;
V_162:
F_49 ( & V_14 -> V_157 ) ;
V_158:
F_49 ( V_145 ) ;
V_153:
return error ;
}
static int F_50 ( struct V_12 * V_13 , struct V_167 * * V_168 ,
V_114 V_82 , const char * V_169 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
struct V_167 * V_167 ;
struct V_170 * V_170 ;
V_170 = F_51 ( V_13 , V_171 , V_82 , 0 , 0 ) ;
if ( F_52 ( V_170 ) ) {
F_39 ( V_14 , L_9 , V_169 , F_53 ( V_170 ) ) ;
return F_53 ( V_170 ) ;
}
V_167 = F_54 ( V_170 ) ;
if ( ! V_167 ) {
F_39 ( V_14 , L_10 , V_169 ) ;
return - V_172 ;
}
* V_168 = V_167 ;
return 0 ;
}
static int F_55 ( struct V_11 * V_14 , int V_54 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_144 V_173 ;
V_114 V_82 ;
int V_174 ;
V_174 = F_46 ( V_14 , V_175 , & V_176 ,
V_155 , 0 , & V_173 ) ;
if ( V_174 ) {
F_39 ( V_14 , L_11 , V_174 ) ;
return V_174 ;
}
V_174 = F_38 ( V_14 , V_54 ) ;
if ( V_174 ) {
F_39 ( V_14 , L_12 , V_174 ) ;
goto V_177;
}
if ( V_14 -> V_56 . V_79 < F_56 ( V_13 -> V_97 ) ) {
V_174 = - V_62 ;
F_39 ( V_14 , L_13
L_14 ,
V_14 -> V_56 . V_79 , F_56 ( V_13 -> V_97 ) ) ;
goto V_177;
}
if ( V_14 -> V_56 . V_79 > V_98 ) {
V_174 = - V_62 ;
F_39 ( V_14 , L_15
L_16 ,
V_14 -> V_56 . V_79 , ( unsigned int ) V_98 ) ;
goto V_177;
}
F_57 ( V_13 , V_14 -> V_56 . V_79 ) ;
V_82 = V_14 -> V_56 . V_84 . V_82 ;
V_174 = F_50 ( V_13 , & V_14 -> V_178 , V_82 , L_17 ) ;
if ( V_174 )
goto V_177;
V_82 = V_14 -> V_56 . V_81 . V_82 ;
V_174 = F_50 ( V_13 , & V_14 -> V_179 , V_82 , L_18 ) ;
if ( V_174 ) {
F_58 ( V_14 -> V_178 ) ;
goto V_177;
}
V_13 -> V_180 = F_59 ( V_14 -> V_137 . V_181 ? V_14 -> V_179 : V_14 -> V_178 ) ;
V_177:
F_49 ( & V_173 ) ;
return V_174 ;
}
static int F_60 ( struct V_11 * V_14 )
{
struct V_182 * V_183 = V_14 -> V_184 ;
unsigned int V_185 ;
V_114 V_186 , V_187 ;
struct V_188 * V_189 = F_61 ( V_183 -> V_190 ) ;
struct V_191 * V_192 = NULL ;
struct V_193 V_194 ;
int V_195 = 0 ;
V_187 = 0 ;
for ( V_185 = 0 ; V_185 < V_196 ( V_183 -> V_190 ) > > V_14 -> V_56 . V_80 ; V_185 ++ ) {
V_194 . V_197 = 0 ;
V_194 . V_198 = 0 ;
V_194 . V_199 = 1 << V_189 -> V_200 . V_201 ;
V_195 = F_62 ( V_183 -> V_190 , V_185 , & V_194 , 0 ) ;
V_186 = V_194 . V_198 ;
if ( V_195 || ! V_186 ) {
F_15 ( V_202 L_19
L_20 , V_195 , V_185 , ( unsigned long long ) V_186 ) ;
break;
}
if ( ! V_187 || V_186 != V_187 + 1 ) {
V_192 = F_4 ( sizeof( struct V_191 ) ,
V_15 ) ;
if ( ! V_192 ) {
F_15 ( V_202 L_21
L_22 ) ;
V_195 = - V_172 ;
break;
}
V_192 -> V_203 = V_186 ;
V_192 -> V_204 = V_185 ;
V_192 -> V_205 = 1 ;
F_63 ( & V_192 -> V_206 , & V_183 -> V_206 ) ;
} else {
V_192 -> V_205 ++ ;
}
V_187 = V_186 ;
}
return V_195 ;
}
static void F_64 ( struct V_11 * V_14 )
{
char * V_207 = L_23 ;
char * V_208 [] = { V_207 , NULL } ;
F_65 ( V_14 , L_24 ) ;
if ( V_14 -> V_209 . V_210 -> V_211 )
V_14 -> V_209 . V_210 -> V_211 ( V_14 ) ;
F_66 ( & V_14 -> V_212 , V_213 , V_208 ) ;
}
static int F_67 ( struct V_11 * V_14 , struct V_144 * V_214 )
{
struct V_188 * V_215 = F_61 ( V_14 -> V_216 ) ;
struct V_217 V_169 ;
char V_70 [ 20 ] ;
struct V_182 * V_183 ;
int error ;
V_169 . V_169 = V_70 ;
F_68 ( & V_14 -> V_32 ) ;
for (; ; ) {
error = F_69 ( V_215 -> V_218 , V_155 , 0 , V_214 ) ;
if ( error )
break;
V_169 . V_219 = sprintf ( V_70 , L_25 , V_14 -> V_220 ) ;
V_169 . V_221 = F_70 ( V_169 . V_169 , V_169 . V_219 ) ;
error = F_71 ( V_14 -> V_216 , & V_169 , NULL ) ;
if ( error == - V_222 ) {
error = 0 ;
break;
}
F_49 ( V_214 ) ;
if ( error )
break;
error = - V_172 ;
V_183 = F_4 ( sizeof( struct V_182 ) , V_15 ) ;
if ( ! V_183 )
break;
F_11 ( & V_183 -> V_206 ) ;
F_72 ( & V_183 -> V_223 , V_224 ) ;
V_183 -> V_190 = F_73 ( V_14 -> V_216 , & V_169 , 1 ) ;
if ( ! V_183 -> V_190 || F_52 ( V_183 -> V_190 ) ) {
if ( ! V_183 -> V_190 )
error = - V_222 ;
else
error = F_53 ( V_183 -> V_190 ) ;
F_6 ( V_183 ) ;
break;
}
F_74 ( & V_14 -> V_31 ) ;
V_183 -> V_225 = V_14 -> V_220 ++ ;
F_63 ( & V_183 -> V_226 , & V_14 -> V_30 ) ;
F_75 ( & V_14 -> V_31 ) ;
}
F_76 ( & V_14 -> V_32 ) ;
return error ;
}
static int F_77 ( struct V_11 * V_14 , int V_146 )
{
struct V_170 * V_227 = V_14 -> V_179 -> V_228 ;
struct V_144 V_214 ;
struct V_188 * V_189 ;
int V_229 = 1 ;
int error = 0 ;
if ( V_146 ) {
V_229 = 0 ;
goto V_230;
}
V_14 -> V_216 = F_78 ( V_227 , L_26 ) ;
if ( F_52 ( V_14 -> V_216 ) ) {
F_39 ( V_14 , L_27 , error ) ;
return F_53 ( V_14 -> V_216 ) ;
}
error = F_67 ( V_14 , & V_214 ) ;
if ( error ) {
F_39 ( V_14 , L_28 , error ) ;
goto V_153;
}
error = - V_231 ;
if ( ! F_79 ( V_14 ) ) {
F_39 ( V_14 , L_29 ) ;
goto V_232;
}
if ( V_14 -> V_137 . V_233 ) {
V_14 -> V_184 = F_80 ( V_14 , 0 ) ;
F_9 ( & V_14 -> V_234 , V_14 -> V_184 -> V_235 ) ;
F_9 ( & V_14 -> V_236 , 2 * V_14 -> V_184 -> V_235 / 5 ) ;
F_9 ( & V_14 -> V_237 , 4 * V_14 -> V_184 -> V_235 / 5 ) ;
} else {
if ( V_14 -> V_209 . V_238 >= F_79 ( V_14 ) ) {
F_39 ( V_14 , L_30 ,
V_14 -> V_209 . V_238 ) ;
F_39 ( V_14 , L_31 ,
F_79 ( V_14 ) ,
F_79 ( V_14 ) - 1 ) ;
goto V_232;
}
V_14 -> V_184 = F_80 ( V_14 , V_14 -> V_209 . V_238 ) ;
error = F_46 ( V_14 , V_14 -> V_209 . V_238 ,
& V_239 ,
V_150 , V_151 ,
& V_14 -> V_240 ) ;
if ( error ) {
F_39 ( V_14 , L_32 , error ) ;
goto V_232;
}
V_189 = F_61 ( V_14 -> V_184 -> V_190 ) ;
error = F_69 ( V_189 -> V_218 , V_155 ,
V_151 | V_156 | V_152 ,
& V_14 -> V_241 ) ;
if ( error ) {
F_39 ( V_14 , L_33 ,
error ) ;
goto V_242;
}
error = F_81 ( V_14 -> V_184 ) ;
if ( error ) {
F_39 ( V_14 , L_34 ,
V_14 -> V_184 -> V_225 , error ) ;
goto V_230;
}
F_9 ( & V_14 -> V_234 , V_14 -> V_184 -> V_235 ) ;
F_9 ( & V_14 -> V_236 , 2 * V_14 -> V_184 -> V_235 / 5 ) ;
F_9 ( & V_14 -> V_237 , 4 * V_14 -> V_184 -> V_235 / 5 ) ;
F_60 ( V_14 ) ;
}
F_82 ( V_14 , F_83 ( & V_14 -> V_234 ) ) ;
if ( V_14 -> V_209 . V_243 ) {
unsigned int V_107 ;
for ( V_107 = 0 ; V_107 < V_14 -> V_220 ; V_107 ++ ) {
error = F_84 ( F_80 ( V_14 , V_107 ) ,
true ) ;
if ( error ) {
F_39 ( V_14 , L_35 ,
V_107 , error ) ;
goto V_230;
}
}
F_64 ( V_14 ) ;
} else if ( ! V_14 -> V_137 . V_233 ) {
error = F_84 ( V_14 -> V_184 , true ) ;
if ( error ) {
F_39 ( V_14 , L_36 , error ) ;
goto V_230;
}
}
F_7 ( V_244 , & V_14 -> V_21 ) ;
F_49 ( & V_214 ) ;
V_229 = 0 ;
return 0 ;
V_230:
if ( ! V_14 -> V_137 . V_233 )
F_49 ( & V_14 -> V_241 ) ;
V_242:
if ( ! V_14 -> V_137 . V_233 )
F_49 ( & V_14 -> V_240 ) ;
V_232:
F_85 ( V_14 ) ;
if ( V_229 )
F_49 ( & V_214 ) ;
V_153:
F_86 ( V_14 -> V_216 ) ;
return error ;
}
static int F_87 ( struct V_11 * V_14 , int V_146 )
{
int error = 0 ;
struct V_170 * V_227 = V_14 -> V_179 -> V_228 ;
if ( V_146 )
goto V_245;
error = F_77 ( V_14 , V_146 ) ;
if ( error )
goto V_153;
V_14 -> V_246 = F_78 ( V_227 , L_37 ) ;
if ( F_52 ( V_14 -> V_246 ) ) {
error = F_53 ( V_14 -> V_246 ) ;
F_39 ( V_14 , L_38 , error ) ;
goto V_247;
}
V_14 -> V_248 = F_78 ( V_227 , L_39 ) ;
if ( F_52 ( V_14 -> V_248 ) ) {
error = F_53 ( V_14 -> V_248 ) ;
F_39 ( V_14 , L_40 , error ) ;
goto V_249;
}
V_14 -> V_250 = 0 ;
V_14 -> V_251 = F_78 ( V_227 , L_41 ) ;
if ( F_52 ( V_14 -> V_251 ) ) {
error = F_53 ( V_14 -> V_251 ) ;
F_39 ( V_14 , L_42 , error ) ;
goto V_252;
}
F_88 ( & V_14 -> V_251 -> V_253 ,
& V_254 ) ;
error = F_89 ( V_14 ) ;
if ( error )
goto V_245;
return 0 ;
V_245:
F_86 ( V_14 -> V_251 ) ;
V_252:
F_90 ( V_14 ) ;
F_86 ( V_14 -> V_248 ) ;
V_249:
F_86 ( V_14 -> V_246 ) ;
V_247:
F_77 ( V_14 , V_255 ) ;
V_153:
return error ;
}
static int F_91 ( struct V_11 * V_14 , int V_146 )
{
struct V_170 * V_256 = NULL ;
char V_70 [ 30 ] ;
int error = 0 ;
struct V_188 * V_189 ;
struct V_170 * V_227 = V_14 -> V_179 -> V_228 ;
if ( V_14 -> V_137 . V_233 )
return 0 ;
if ( V_146 )
goto V_257;
V_256 = F_78 ( V_227 , L_43 ) ;
if ( F_52 ( V_256 ) ) {
error = F_53 ( V_256 ) ;
F_39 ( V_14 , L_44 , error ) ;
return error ;
}
sprintf ( V_70 , L_45 , V_14 -> V_184 -> V_225 ) ;
V_14 -> V_258 = F_78 ( V_256 , V_70 ) ;
if ( F_52 ( V_14 -> V_258 ) ) {
error = F_53 ( V_14 -> V_258 ) ;
F_39 ( V_14 , L_46 , error ) ;
goto V_153;
}
sprintf ( V_70 , L_47 , V_14 -> V_184 -> V_225 ) ;
V_14 -> V_259 = F_78 ( V_256 , V_70 ) ;
if ( F_52 ( V_14 -> V_259 ) ) {
error = F_53 ( V_14 -> V_259 ) ;
F_39 ( V_14 , L_48 , error ) ;
goto V_260;
}
F_86 ( V_256 ) ;
V_256 = NULL ;
V_189 = F_61 ( V_14 -> V_258 ) ;
error = F_69 ( V_189 -> V_218 , V_150 , 0 ,
& V_14 -> V_261 ) ;
if ( error ) {
F_39 ( V_14 , L_49 , error ) ;
goto V_262;
}
V_189 = F_61 ( V_14 -> V_259 ) ;
error = F_69 ( V_189 -> V_218 , V_150 , 0 ,
& V_14 -> V_263 ) ;
if ( error ) {
F_39 ( V_14 , L_50 , error ) ;
goto V_264;
}
return 0 ;
V_257:
F_49 ( & V_14 -> V_263 ) ;
V_264:
F_49 ( & V_14 -> V_261 ) ;
V_262:
F_86 ( V_14 -> V_259 ) ;
V_260:
F_86 ( V_14 -> V_258 ) ;
V_153:
if ( V_256 )
F_86 ( V_256 ) ;
return error ;
}
static int F_92 ( struct V_11 * V_14 , int V_146 )
{
struct V_265 * V_91 ;
int error = 0 ;
if ( V_146 )
goto V_266;
V_91 = F_93 ( V_267 , V_14 , L_51 ) ;
error = F_52 ( V_91 ) ;
if ( error ) {
F_39 ( V_14 , L_52 , error ) ;
return error ;
}
V_14 -> V_268 = V_91 ;
V_91 = F_93 ( V_269 , V_14 , L_53 ) ;
error = F_52 ( V_91 ) ;
if ( error ) {
F_39 ( V_14 , L_54 , error ) ;
goto V_153;
}
V_14 -> V_270 = V_91 ;
return 0 ;
V_266:
F_94 ( V_14 -> V_270 ) ;
V_153:
F_94 ( V_14 -> V_268 ) ;
return error ;
}
static int F_95 ( struct V_11 * V_14 , int V_54 )
{
const struct V_271 * V_272 ;
struct V_273 * V_274 = & V_14 -> V_209 ;
struct V_275 * args = & V_14 -> V_137 ;
const char * V_135 = V_14 -> V_141 ;
const char * V_136 = V_14 -> V_143 ;
char * V_276 , * V_277 ;
int V_174 ;
if ( ! strcmp ( L_55 , V_135 ) ) {
V_272 = & V_278 ;
V_14 -> V_137 . V_279 = 1 ;
#ifdef F_96
} else if ( ! strcmp ( L_56 , V_135 ) ) {
V_272 = & V_280 ;
#endif
} else {
F_15 ( V_202 L_57 , V_135 ) ;
return - V_222 ;
}
F_65 ( V_14 , L_58 , V_135 , V_136 ) ;
V_274 -> V_210 = V_272 ;
V_274 -> V_243 = 1 ;
for ( V_277 = args -> V_281 ; ( V_276 = F_97 ( & V_277 , L_59 ) ) ; ) {
T_3 V_282 [ V_283 ] ;
int V_284 , V_285 ;
if ( ! V_276 || ! * V_276 )
continue;
V_284 = F_98 ( V_276 , * V_272 -> V_286 , V_282 ) ;
switch ( V_284 ) {
case V_287 :
V_174 = F_99 ( & V_282 [ 0 ] , & V_285 ) ;
if ( V_174 || V_285 < 0 )
goto V_288;
if ( F_100 ( V_20 , & V_14 -> V_21 ) )
V_274 -> V_238 = V_285 ;
break;
case V_289 :
case V_290 :
break;
case V_291 :
V_174 = F_99 ( & V_282 [ 0 ] , & V_285 ) ;
if ( V_174 || ( V_285 != 0 && V_285 != 1 ) )
goto V_288;
V_274 -> V_243 = V_285 ;
break;
case V_292 :
default:
V_288:
F_65 ( V_14 , L_60 , V_276 ) ;
return - V_62 ;
}
}
if ( V_272 -> V_293 == NULL ) {
F_65 ( V_14 , L_61 ) ;
F_101 ( & V_14 -> V_25 ) ;
return 0 ;
}
V_174 = V_272 -> V_293 ( V_14 , V_136 ) ;
if ( V_174 == 0 )
F_65 ( V_14 , L_62 ) ;
F_101 ( & V_14 -> V_25 ) ;
return V_174 ;
}
void F_102 ( struct V_11 * V_14 )
{
const struct V_271 * V_272 = V_14 -> V_209 . V_210 ;
if ( F_103 ( ! F_104 ( V_294 , & V_14 -> V_21 ) ) &&
V_272 -> V_295 )
V_272 -> V_295 ( V_14 ) ;
}
static int F_105 ( void * V_296 )
{
if ( F_106 ( V_297 ) )
return - V_298 ;
F_107 () ;
return 0 ;
}
static int F_108 ( struct V_11 * V_14 )
{
if ( V_14 -> V_209 . V_210 -> V_293 == NULL )
return 0 ;
return F_109 ( & V_14 -> V_21 , V_20 , F_105 , V_299 ) ;
}
void F_110 ( struct V_11 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
char V_300 [ 20 ] ;
char V_301 [ 20 ] ;
char * V_208 [] = { V_300 , V_301 , NULL } ;
sprintf ( V_300 , L_63 , ( V_13 -> V_302 & V_303 ) ? 1 : 0 ) ;
sprintf ( V_301 , L_64 , V_14 -> V_137 . V_233 ? 1 : 0 ) ;
F_66 ( & V_14 -> V_212 , V_304 , V_208 ) ;
}
static int F_111 ( struct V_12 * V_13 , struct V_275 * args , int V_54 )
{
struct V_11 * V_14 ;
struct V_144 V_145 ;
int error ;
V_14 = F_3 ( V_13 ) ;
if ( ! V_14 ) {
F_15 ( V_61 L_65 ) ;
return - V_172 ;
}
V_14 -> V_137 = * args ;
if ( V_14 -> V_137 . V_233 ) {
V_13 -> V_302 |= V_303 ;
F_7 ( V_305 , & V_14 -> V_21 ) ;
}
if ( V_14 -> V_137 . V_306 )
V_13 -> V_302 |= V_307 ;
if ( V_14 -> V_137 . V_308 )
F_7 ( V_309 , & V_14 -> V_21 ) ;
V_13 -> V_302 |= V_310 ;
V_13 -> V_311 = V_58 ;
V_13 -> V_312 = & V_313 ;
V_13 -> V_314 = & V_315 ;
V_13 -> V_316 = & V_317 ;
V_13 -> V_318 = V_319 ;
V_13 -> V_320 = & V_321 ;
F_112 ( V_13 ) -> V_322 |= V_323 ;
V_13 -> V_324 = 1 ;
V_13 -> V_325 = V_326 ;
V_14 -> V_56 . V_79 = F_113 ( V_13 , V_327 ) ;
V_14 -> V_56 . V_80 = V_13 -> V_328 ;
V_14 -> V_109 = V_14 -> V_56 . V_80 -
V_110 ;
V_14 -> V_111 = 1 << V_14 -> V_109 ;
V_14 -> V_22 . V_329 = V_14 -> V_137 . V_330 ;
V_14 -> V_22 . V_331 = V_14 -> V_137 . V_332 ;
if ( V_14 -> V_137 . V_333 ) {
V_14 -> V_22 . V_334 = 0 ;
V_14 -> V_22 . V_335 = V_14 -> V_137 . V_333 ;
} else {
V_14 -> V_22 . V_334 = 1 ;
V_14 -> V_22 . V_335 = 30 ;
}
error = F_43 ( V_14 , V_54 ) ;
if ( error ) {
F_114 ( V_14 -> V_18 ) ;
F_6 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
snprintf ( V_14 -> V_336 , V_142 , L_66 , V_14 -> V_143 ) ;
error = F_115 ( V_14 ) ;
if ( error )
return error ;
F_116 ( V_14 ) ;
error = F_95 ( V_14 , V_54 ) ;
if ( error )
goto V_337;
error = F_45 ( V_14 , & V_145 , DO ) ;
if ( error )
goto V_338;
error = F_55 ( V_14 , V_54 ) ;
if ( error )
goto V_339;
error = F_108 ( V_14 ) ;
if ( error )
goto V_340;
if ( V_14 -> V_209 . V_238 < 0 ) {
error = V_14 -> V_209 . V_238 ;
V_14 -> V_209 . V_238 = 0 ;
goto V_340;
}
if ( V_14 -> V_137 . V_233 )
snprintf ( V_14 -> V_336 , V_142 , L_67 ,
V_14 -> V_143 ) ;
else
snprintf ( V_14 -> V_336 , V_142 , L_68 ,
V_14 -> V_143 , V_14 -> V_209 . V_238 ) ;
error = F_87 ( V_14 , DO ) ;
if ( error )
goto V_340;
error = F_91 ( V_14 , DO ) ;
if ( error )
goto V_341;
error = F_117 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_69 , error ) ;
goto V_342;
}
error = F_92 ( V_14 , DO ) ;
if ( error )
goto V_342;
if ( ! ( V_13 -> V_302 & V_303 ) ) {
error = F_118 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_70 , error ) ;
goto V_343;
}
}
F_49 ( & V_145 ) ;
F_110 ( V_14 ) ;
return 0 ;
V_343:
F_92 ( V_14 , V_255 ) ;
V_342:
F_91 ( V_14 , V_255 ) ;
V_341:
F_87 ( V_14 , V_255 ) ;
V_340:
if ( V_14 -> V_178 )
F_58 ( V_14 -> V_178 ) ;
if ( V_14 -> V_179 )
F_58 ( V_14 -> V_179 ) ;
if ( V_13 -> V_180 )
F_58 ( V_13 -> V_180 ) ;
V_13 -> V_180 = NULL ;
V_339:
F_45 ( V_14 , & V_145 , V_255 ) ;
V_338:
F_119 ( V_14 ) ;
F_102 ( V_14 ) ;
V_337:
F_120 ( V_14 ) ;
F_114 ( V_14 -> V_18 ) ;
F_121 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
static int F_122 ( struct V_12 * V_71 , void * V_344 )
{
V_71 -> V_97 = V_344 ;
V_71 -> V_345 = V_71 -> V_97 -> V_346 ;
V_71 -> V_347 = & F_123 ( V_71 -> V_97 ) -> V_348 ;
return 0 ;
}
static int F_124 ( struct V_12 * V_71 , void * V_349 )
{
struct V_350 * V_351 = V_349 ;
return ( V_351 == V_71 -> V_97 ) ;
}
static struct V_167 * F_125 ( struct V_352 * V_353 , int V_322 ,
const char * V_354 , void * V_344 )
{
struct V_350 * V_351 ;
struct V_12 * V_71 ;
T_4 V_355 = V_356 | V_357 ;
int error ;
struct V_275 args ;
struct V_11 * V_14 ;
if ( ! ( V_322 & V_303 ) )
V_355 |= V_358 ;
V_351 = F_126 ( V_354 , V_355 , V_353 ) ;
if ( F_52 ( V_351 ) )
return F_127 ( V_351 ) ;
F_68 ( & V_351 -> V_359 ) ;
if ( V_351 -> V_360 > 0 ) {
F_76 ( & V_351 -> V_359 ) ;
error = - V_361 ;
goto V_362;
}
V_71 = F_128 ( V_353 , F_124 , F_122 , V_322 , V_351 ) ;
F_76 ( & V_351 -> V_359 ) ;
error = F_53 ( V_71 ) ;
if ( F_52 ( V_71 ) )
goto V_362;
if ( V_71 -> V_180 )
F_129 ( V_351 , V_355 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_363 = V_364 ;
args . V_365 = V_366 ;
args . V_330 = 30 ;
args . V_333 = 30 ;
args . V_332 = 60 ;
args . V_367 = V_368 ;
error = F_130 ( & args , V_344 ) ;
if ( error ) {
F_15 ( V_61 L_71 ) ;
goto V_369;
}
if ( V_71 -> V_180 ) {
error = - V_361 ;
if ( ( V_322 ^ V_71 -> V_302 ) & V_303 )
goto V_369;
} else {
char V_370 [ V_371 ] ;
V_71 -> V_372 = V_355 ;
F_44 ( V_71 -> V_140 , F_131 ( V_351 , V_370 ) , sizeof( V_71 -> V_140 ) ) ;
F_57 ( V_71 , F_132 ( V_351 ) ) ;
error = F_111 ( V_71 , & args , V_322 & V_373 ? 1 : 0 ) ;
if ( error )
goto V_369;
V_71 -> V_302 |= V_374 ;
V_351 -> V_375 = V_71 ;
}
V_14 = V_71 -> V_16 ;
if ( args . V_181 )
return F_59 ( V_14 -> V_179 ) ;
else
return F_59 ( V_14 -> V_178 ) ;
V_369:
F_133 ( V_71 ) ;
return F_134 ( error ) ;
V_362:
F_129 ( V_351 , V_355 ) ;
return F_134 ( error ) ;
}
static int F_135 ( struct V_12 * V_71 , void * V_349 )
{
return - V_62 ;
}
static struct V_167 * F_136 ( struct V_352 * V_353 ,
int V_322 , const char * V_354 , void * V_344 )
{
struct V_12 * V_71 ;
struct V_11 * V_14 ;
struct V_376 V_376 ;
int error ;
error = F_137 ( V_354 , V_377 , & V_376 ) ;
if ( error ) {
F_15 ( V_61 L_72 ,
V_354 , error ) ;
return F_134 ( error ) ;
}
V_71 = F_128 ( & V_378 , F_124 , F_135 , V_322 ,
V_376 . V_167 -> V_228 -> V_379 -> V_97 ) ;
F_138 ( & V_376 ) ;
if ( F_52 ( V_71 ) ) {
F_15 ( V_61 L_73 ) ;
return F_127 ( V_71 ) ;
}
if ( ( V_322 ^ V_71 -> V_302 ) & V_303 ) {
F_133 ( V_71 ) ;
return F_134 ( - V_361 ) ;
}
V_14 = V_71 -> V_16 ;
return F_59 ( V_14 -> V_179 ) ;
}
static void F_139 ( struct V_12 * V_13 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
if ( V_14 == NULL ) {
F_140 ( V_13 ) ;
return;
}
F_141 ( V_14 ) ;
F_58 ( V_14 -> V_178 ) ;
F_58 ( V_14 -> V_179 ) ;
V_14 -> V_178 = NULL ;
V_14 -> V_179 = NULL ;
F_142 ( V_13 ) ;
F_120 ( V_14 ) ;
F_114 ( V_14 -> V_18 ) ;
F_140 ( V_13 ) ;
}
