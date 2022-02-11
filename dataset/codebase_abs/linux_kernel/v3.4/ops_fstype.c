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
F_11 ( & V_14 -> V_44 ) ;
F_8 ( & V_14 -> V_45 ) ;
F_8 ( & V_14 -> V_46 ) ;
F_2 ( & V_14 -> V_47 ) ;
F_11 ( & V_14 -> V_48 ) ;
F_11 ( & V_14 -> V_49 ) ;
F_13 ( & V_14 -> V_50 ) ;
F_9 ( & V_14 -> V_51 , 0 ) ;
F_8 ( & V_14 -> V_52 ) ;
F_11 ( & V_14 -> V_53 ) ;
F_12 ( & V_14 -> V_54 ) ;
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
V_104 = F_40 ( sizeof( V_115 ) * ( 1 << V_124 ) ,
V_14 -> V_118 ) ;
V_105 = 0 ;
for ( V_107 = V_104 ; V_107 > V_14 -> V_113 ; ) {
V_107 = F_40 ( V_107 , V_14 -> V_116 ) ;
V_105 += V_107 ;
}
V_106 = 2 + V_124 ;
V_14 -> V_125 = V_104 + V_105 + V_106 ;
V_14 -> V_126 [ 0 ] = V_14 -> V_57 . V_80 -
sizeof( struct V_114 ) ;
V_14 -> V_126 [ 1 ] = V_14 -> V_57 . V_80 * V_14 -> V_113 ;
for ( V_108 = 2 ; ; V_108 ++ ) {
V_115 V_127 , V_128 ;
T_2 V_129 ;
V_127 = V_14 -> V_126 [ V_108 - 1 ] * V_14 -> V_116 ;
V_128 = V_127 ;
V_129 = F_41 ( V_128 , V_14 -> V_116 ) ;
if ( V_128 != V_14 -> V_126 [ V_108 - 1 ] || V_129 )
break;
V_14 -> V_126 [ V_108 ] = V_127 ;
}
V_14 -> V_130 = V_108 ;
V_14 -> V_126 [ V_108 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_130 <= V_131 ) ;
V_14 -> V_132 [ 0 ] = V_14 -> V_57 . V_80 -
sizeof( struct V_114 ) ;
V_14 -> V_132 [ 1 ] = V_14 -> V_118 * V_14 -> V_113 ;
for ( V_108 = 2 ; ; V_108 ++ ) {
V_115 V_127 , V_128 ;
T_2 V_129 ;
V_127 = V_14 -> V_132 [ V_108 - 1 ] * V_14 -> V_116 ;
V_128 = V_127 ;
V_129 = F_41 ( V_128 , V_14 -> V_116 ) ;
if ( V_128 != V_14 -> V_132 [ V_108 - 1 ] || V_129 )
break;
V_14 -> V_132 [ V_108 ] = V_127 ;
}
V_14 -> V_133 = V_108 ;
V_14 -> V_132 [ V_108 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_133 <= V_131 ) ;
return 0 ;
}
static int F_43 ( struct V_11 * V_14 , int V_55 )
{
char * V_134 , * V_135 ;
int error = 0 ;
V_134 = V_14 -> V_136 . V_137 ;
V_135 = V_14 -> V_136 . V_138 ;
if ( ! V_134 [ 0 ] || ! V_135 [ 0 ] ) {
error = F_23 ( V_14 , V_109 >> V_14 -> V_110 , V_55 ) ;
if ( error )
return error ;
if ( ! V_134 [ 0 ] )
V_134 = V_14 -> V_57 . V_86 ;
if ( ! V_135 [ 0 ] )
V_135 = V_14 -> V_57 . V_88 ;
}
if ( ! V_135 [ 0 ] )
V_135 = V_14 -> V_17 -> V_139 ;
F_44 ( V_14 -> V_140 , V_134 , V_141 ) ;
F_44 ( V_14 -> V_142 , V_135 , V_141 ) ;
V_135 = V_14 -> V_142 ;
while ( ( V_135 = strchr ( V_135 , '/' ) ) )
* V_135 = '_' ;
return error ;
}
static int F_45 ( struct V_11 * V_14 , struct V_143 * V_144 ,
int V_145 )
{
int error = 0 ;
if ( V_145 )
goto V_146;
error = F_46 ( V_14 ,
V_147 , & V_148 ,
V_149 , V_150 | V_151 ,
V_144 ) ;
if ( error ) {
F_39 ( V_14 , L_5 , error ) ;
goto V_152;
}
error = F_46 ( V_14 ,
V_153 , & V_148 ,
V_154 ,
V_150 | V_155 ,
& V_14 -> V_156 ) ;
if ( error ) {
F_39 ( V_14 , L_6 , error ) ;
goto V_157;
}
error = F_47 ( V_14 , V_158 , & V_148 ,
V_159 , & V_14 -> V_160 ) ;
if ( error ) {
F_39 ( V_14 , L_7 , error ) ;
goto V_161;
}
error = F_47 ( V_14 , V_162 , & V_163 ,
V_159 , & V_14 -> V_164 ) ;
if ( error ) {
F_39 ( V_14 , L_8 , error ) ;
goto V_165;
}
return 0 ;
V_146:
F_48 ( V_14 -> V_164 ) ;
V_165:
F_48 ( V_14 -> V_160 ) ;
V_161:
F_49 ( & V_14 -> V_156 ) ;
V_157:
F_49 ( V_144 ) ;
V_152:
return error ;
}
static int F_50 ( struct V_12 * V_13 , struct V_166 * * V_167 ,
V_115 V_83 , const char * V_168 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
struct V_166 * V_166 ;
struct V_169 * V_169 ;
V_169 = F_51 ( V_13 , V_170 , V_83 , 0 , 0 ) ;
if ( F_52 ( V_169 ) ) {
F_39 ( V_14 , L_9 , V_168 , F_53 ( V_169 ) ) ;
return F_53 ( V_169 ) ;
}
V_166 = F_54 ( V_169 ) ;
if ( ! V_166 ) {
F_39 ( V_14 , L_10 , V_168 ) ;
return - V_171 ;
}
* V_167 = V_166 ;
return 0 ;
}
static int F_55 ( struct V_11 * V_14 , int V_55 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_143 V_172 ;
V_115 V_83 ;
int V_173 ;
V_173 = F_46 ( V_14 , V_174 , & V_175 ,
V_154 , 0 , & V_172 ) ;
if ( V_173 ) {
F_39 ( V_14 , L_11 , V_173 ) ;
return V_173 ;
}
V_173 = F_38 ( V_14 , V_55 ) ;
if ( V_173 ) {
F_39 ( V_14 , L_12 , V_173 ) ;
goto V_176;
}
if ( V_14 -> V_57 . V_80 < F_56 ( V_13 -> V_98 ) ) {
V_173 = - V_63 ;
F_39 ( V_14 , L_13
L_14 ,
V_14 -> V_57 . V_80 , F_56 ( V_13 -> V_98 ) ) ;
goto V_176;
}
if ( V_14 -> V_57 . V_80 > V_99 ) {
V_173 = - V_63 ;
F_39 ( V_14 , L_15
L_16 ,
V_14 -> V_57 . V_80 , ( unsigned int ) V_99 ) ;
goto V_176;
}
F_57 ( V_13 , V_14 -> V_57 . V_80 ) ;
V_83 = V_14 -> V_57 . V_85 . V_83 ;
V_173 = F_50 ( V_13 , & V_14 -> V_177 , V_83 , L_17 ) ;
if ( V_173 )
goto V_176;
V_83 = V_14 -> V_57 . V_82 . V_83 ;
V_173 = F_50 ( V_13 , & V_14 -> V_178 , V_83 , L_18 ) ;
if ( V_173 ) {
F_58 ( V_14 -> V_177 ) ;
goto V_176;
}
V_13 -> V_179 = F_59 ( V_14 -> V_136 . V_180 ? V_14 -> V_178 : V_14 -> V_177 ) ;
V_176:
F_49 ( & V_172 ) ;
return V_173 ;
}
static int F_60 ( struct V_11 * V_14 )
{
struct V_181 * V_182 = V_14 -> V_183 ;
unsigned int V_184 ;
V_115 V_185 , V_186 ;
struct V_187 * V_188 = F_61 ( V_182 -> V_189 ) ;
struct V_190 * V_191 = NULL ;
struct V_192 V_193 ;
int V_194 = 0 ;
V_186 = 0 ;
for ( V_184 = 0 ; V_184 < V_195 ( V_182 -> V_189 ) > > V_14 -> V_57 . V_81 ; V_184 ++ ) {
V_193 . V_196 = 0 ;
V_193 . V_197 = 0 ;
V_193 . V_198 = 1 << V_188 -> V_199 . V_200 ;
V_194 = F_62 ( V_182 -> V_189 , V_184 , & V_193 , 0 ) ;
V_185 = V_193 . V_197 ;
if ( V_194 || ! V_185 ) {
F_15 ( V_201 L_19
L_20 , V_194 , V_184 , ( unsigned long long ) V_185 ) ;
break;
}
if ( ! V_186 || V_185 != V_186 + 1 ) {
V_191 = F_4 ( sizeof( struct V_190 ) ,
V_15 ) ;
if ( ! V_191 ) {
F_15 ( V_201 L_21
L_22 ) ;
V_194 = - V_171 ;
break;
}
V_191 -> V_202 = V_185 ;
V_191 -> V_203 = V_184 ;
V_191 -> V_204 = 1 ;
F_63 ( & V_191 -> V_205 , & V_182 -> V_205 ) ;
} else {
V_191 -> V_204 ++ ;
}
V_186 = V_185 ;
}
return V_194 ;
}
static void F_64 ( struct V_11 * V_14 )
{
char * V_206 = L_23 ;
char * V_207 [] = { V_206 , NULL } ;
F_65 ( V_14 , L_24 ) ;
if ( V_14 -> V_208 . V_209 -> V_210 )
V_14 -> V_208 . V_209 -> V_210 ( V_14 ) ;
F_66 ( & V_14 -> V_211 , V_212 , V_207 ) ;
}
static int F_67 ( struct V_11 * V_14 , struct V_143 * V_213 )
{
struct V_187 * V_214 = F_61 ( V_14 -> V_215 ) ;
struct V_216 V_168 ;
char V_71 [ 20 ] ;
struct V_181 * V_182 ;
int error ;
V_168 . V_168 = V_71 ;
F_68 ( & V_14 -> V_32 ) ;
for (; ; ) {
error = F_69 ( V_214 -> V_217 , V_154 , 0 , V_213 ) ;
if ( error )
break;
V_168 . V_218 = sprintf ( V_71 , L_25 , V_14 -> V_219 ) ;
V_168 . V_220 = F_70 ( V_168 . V_168 , V_168 . V_218 ) ;
error = F_71 ( V_14 -> V_215 , & V_168 , NULL ) ;
if ( error == - V_221 ) {
error = 0 ;
break;
}
F_49 ( V_213 ) ;
if ( error )
break;
error = - V_171 ;
V_182 = F_4 ( sizeof( struct V_181 ) , V_15 ) ;
if ( ! V_182 )
break;
F_11 ( & V_182 -> V_205 ) ;
F_72 ( & V_182 -> V_222 , V_223 ) ;
V_182 -> V_189 = F_73 ( V_14 -> V_215 , & V_168 , 1 ) ;
if ( ! V_182 -> V_189 || F_52 ( V_182 -> V_189 ) ) {
if ( ! V_182 -> V_189 )
error = - V_221 ;
else
error = F_53 ( V_182 -> V_189 ) ;
F_6 ( V_182 ) ;
break;
}
F_74 ( & V_14 -> V_31 ) ;
V_182 -> V_224 = V_14 -> V_219 ++ ;
F_63 ( & V_182 -> V_225 , & V_14 -> V_30 ) ;
F_75 ( & V_14 -> V_31 ) ;
}
F_76 ( & V_14 -> V_32 ) ;
return error ;
}
static int F_77 ( struct V_11 * V_14 , int V_145 )
{
struct V_169 * V_226 = V_14 -> V_178 -> V_227 ;
struct V_143 V_213 ;
struct V_187 * V_188 ;
int V_228 = 1 ;
int error = 0 ;
if ( V_145 ) {
V_228 = 0 ;
goto V_229;
}
V_14 -> V_215 = F_78 ( V_226 , L_26 ) ;
if ( F_52 ( V_14 -> V_215 ) ) {
F_39 ( V_14 , L_27 , error ) ;
return F_53 ( V_14 -> V_215 ) ;
}
error = F_67 ( V_14 , & V_213 ) ;
if ( error ) {
F_39 ( V_14 , L_28 , error ) ;
goto V_152;
}
error = - V_230 ;
if ( ! F_79 ( V_14 ) ) {
F_39 ( V_14 , L_29 ) ;
goto V_231;
}
if ( V_14 -> V_136 . V_232 ) {
V_14 -> V_183 = F_80 ( V_14 , 0 ) ;
F_9 ( & V_14 -> V_233 , V_14 -> V_183 -> V_234 ) ;
F_9 ( & V_14 -> V_235 , 2 * V_14 -> V_183 -> V_234 / 5 ) ;
F_9 ( & V_14 -> V_236 , 4 * V_14 -> V_183 -> V_234 / 5 ) ;
} else {
if ( V_14 -> V_208 . V_237 >= F_79 ( V_14 ) ) {
F_39 ( V_14 , L_30 ,
V_14 -> V_208 . V_237 ) ;
F_39 ( V_14 , L_31 ,
F_79 ( V_14 ) ,
F_79 ( V_14 ) - 1 ) ;
goto V_231;
}
V_14 -> V_183 = F_80 ( V_14 , V_14 -> V_208 . V_237 ) ;
error = F_46 ( V_14 , V_14 -> V_208 . V_237 ,
& V_238 ,
V_149 , V_150 ,
& V_14 -> V_239 ) ;
if ( error ) {
F_39 ( V_14 , L_32 , error ) ;
goto V_231;
}
V_188 = F_61 ( V_14 -> V_183 -> V_189 ) ;
error = F_69 ( V_188 -> V_217 , V_154 ,
V_150 | V_155 | V_151 ,
& V_14 -> V_240 ) ;
if ( error ) {
F_39 ( V_14 , L_33 ,
error ) ;
goto V_241;
}
error = F_81 ( V_14 -> V_183 ) ;
if ( error ) {
F_39 ( V_14 , L_34 ,
V_14 -> V_183 -> V_224 , error ) ;
goto V_229;
}
F_9 ( & V_14 -> V_233 , V_14 -> V_183 -> V_234 ) ;
F_9 ( & V_14 -> V_235 , 2 * V_14 -> V_183 -> V_234 / 5 ) ;
F_9 ( & V_14 -> V_236 , 4 * V_14 -> V_183 -> V_234 / 5 ) ;
F_60 ( V_14 ) ;
}
F_82 ( V_14 , F_83 ( & V_14 -> V_233 ) ) ;
if ( V_14 -> V_208 . V_242 ) {
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_219 ; V_108 ++ ) {
error = F_84 ( F_80 ( V_14 , V_108 ) ,
true ) ;
if ( error ) {
F_39 ( V_14 , L_35 ,
V_108 , error ) ;
goto V_229;
}
}
F_64 ( V_14 ) ;
} else if ( ! V_14 -> V_136 . V_232 ) {
error = F_84 ( V_14 -> V_183 , true ) ;
if ( error ) {
F_39 ( V_14 , L_36 , error ) ;
goto V_229;
}
}
F_7 ( V_243 , & V_14 -> V_21 ) ;
F_49 ( & V_213 ) ;
V_228 = 0 ;
return 0 ;
V_229:
if ( ! V_14 -> V_136 . V_232 )
F_49 ( & V_14 -> V_240 ) ;
V_241:
if ( ! V_14 -> V_136 . V_232 )
F_49 ( & V_14 -> V_239 ) ;
V_231:
F_85 ( V_14 ) ;
if ( V_228 )
F_49 ( & V_213 ) ;
V_152:
F_86 ( V_14 -> V_215 ) ;
return error ;
}
static int F_87 ( struct V_11 * V_14 , int V_145 )
{
int error = 0 ;
struct V_169 * V_226 = V_14 -> V_178 -> V_227 ;
if ( V_145 )
goto V_244;
error = F_77 ( V_14 , V_145 ) ;
if ( error )
goto V_152;
V_14 -> V_245 = F_78 ( V_226 , L_37 ) ;
if ( F_52 ( V_14 -> V_245 ) ) {
error = F_53 ( V_14 -> V_245 ) ;
F_39 ( V_14 , L_38 , error ) ;
goto V_246;
}
V_14 -> V_247 = F_78 ( V_226 , L_39 ) ;
if ( F_52 ( V_14 -> V_247 ) ) {
error = F_53 ( V_14 -> V_247 ) ;
F_39 ( V_14 , L_40 , error ) ;
goto V_248;
}
V_14 -> V_249 = 0 ;
V_14 -> V_250 = F_78 ( V_226 , L_41 ) ;
if ( F_52 ( V_14 -> V_250 ) ) {
error = F_53 ( V_14 -> V_250 ) ;
F_39 ( V_14 , L_42 , error ) ;
goto V_251;
}
error = F_88 ( V_14 ) ;
if ( error )
goto V_244;
return 0 ;
V_244:
F_86 ( V_14 -> V_250 ) ;
V_251:
F_89 ( V_14 ) ;
F_86 ( V_14 -> V_247 ) ;
V_248:
F_86 ( V_14 -> V_245 ) ;
V_246:
F_77 ( V_14 , V_252 ) ;
V_152:
return error ;
}
static int F_90 ( struct V_11 * V_14 , int V_145 )
{
struct V_169 * V_253 = NULL ;
char V_71 [ 30 ] ;
int error = 0 ;
struct V_187 * V_188 ;
struct V_169 * V_226 = V_14 -> V_178 -> V_227 ;
if ( V_14 -> V_136 . V_232 )
return 0 ;
if ( V_145 )
goto V_254;
V_253 = F_78 ( V_226 , L_43 ) ;
if ( F_52 ( V_253 ) ) {
error = F_53 ( V_253 ) ;
F_39 ( V_14 , L_44 , error ) ;
return error ;
}
sprintf ( V_71 , L_45 , V_14 -> V_183 -> V_224 ) ;
V_14 -> V_255 = F_78 ( V_253 , V_71 ) ;
if ( F_52 ( V_14 -> V_255 ) ) {
error = F_53 ( V_14 -> V_255 ) ;
F_39 ( V_14 , L_46 , error ) ;
goto V_152;
}
sprintf ( V_71 , L_47 , V_14 -> V_183 -> V_224 ) ;
V_14 -> V_256 = F_78 ( V_253 , V_71 ) ;
if ( F_52 ( V_14 -> V_256 ) ) {
error = F_53 ( V_14 -> V_256 ) ;
F_39 ( V_14 , L_48 , error ) ;
goto V_257;
}
F_86 ( V_253 ) ;
V_253 = NULL ;
V_188 = F_61 ( V_14 -> V_255 ) ;
error = F_69 ( V_188 -> V_217 , V_149 , 0 ,
& V_14 -> V_258 ) ;
if ( error ) {
F_39 ( V_14 , L_49 , error ) ;
goto V_259;
}
V_188 = F_61 ( V_14 -> V_256 ) ;
error = F_69 ( V_188 -> V_217 , V_149 , 0 ,
& V_14 -> V_260 ) ;
if ( error ) {
F_39 ( V_14 , L_50 , error ) ;
goto V_261;
}
return 0 ;
V_254:
F_49 ( & V_14 -> V_260 ) ;
V_261:
F_49 ( & V_14 -> V_258 ) ;
V_259:
F_86 ( V_14 -> V_256 ) ;
V_257:
F_86 ( V_14 -> V_255 ) ;
V_152:
if ( V_253 )
F_86 ( V_253 ) ;
return error ;
}
static int F_91 ( struct V_11 * V_14 , int V_145 )
{
struct V_262 * V_92 ;
int error = 0 ;
if ( V_145 )
goto V_263;
V_92 = F_92 ( V_264 , V_14 , L_51 ) ;
error = F_52 ( V_92 ) ;
if ( error ) {
F_39 ( V_14 , L_52 , error ) ;
return error ;
}
V_14 -> V_265 = V_92 ;
V_92 = F_92 ( V_266 , V_14 , L_53 ) ;
error = F_52 ( V_92 ) ;
if ( error ) {
F_39 ( V_14 , L_54 , error ) ;
goto V_152;
}
V_14 -> V_267 = V_92 ;
return 0 ;
V_263:
F_93 ( V_14 -> V_267 ) ;
V_152:
F_93 ( V_14 -> V_265 ) ;
return error ;
}
static int F_94 ( struct V_11 * V_14 , int V_55 )
{
const struct V_268 * V_269 ;
struct V_270 * V_271 = & V_14 -> V_208 ;
struct V_272 * args = & V_14 -> V_136 ;
const char * V_134 = V_14 -> V_140 ;
const char * V_135 = V_14 -> V_142 ;
char * V_273 , * V_274 ;
int V_173 ;
if ( ! strcmp ( L_55 , V_134 ) ) {
V_269 = & V_275 ;
V_14 -> V_136 . V_276 = 1 ;
#ifdef F_95
} else if ( ! strcmp ( L_56 , V_134 ) ) {
V_269 = & V_277 ;
#endif
} else {
F_15 ( V_201 L_57 , V_134 ) ;
return - V_221 ;
}
F_65 ( V_14 , L_58 , V_134 , V_135 ) ;
V_271 -> V_209 = V_269 ;
V_271 -> V_242 = 1 ;
for ( V_274 = args -> V_278 ; ( V_273 = F_96 ( & V_274 , L_59 ) ) ; ) {
T_3 V_279 [ V_280 ] ;
int V_281 , V_282 ;
if ( ! V_273 || ! * V_273 )
continue;
V_281 = F_97 ( V_273 , * V_269 -> V_283 , V_279 ) ;
switch ( V_281 ) {
case V_284 :
V_173 = F_98 ( & V_279 [ 0 ] , & V_282 ) ;
if ( V_173 || V_282 < 0 )
goto V_285;
if ( F_99 ( V_20 , & V_14 -> V_21 ) )
V_271 -> V_237 = V_282 ;
break;
case V_286 :
break;
case V_287 :
V_173 = F_98 ( & V_279 [ 0 ] , & V_282 ) ;
if ( V_173 || ( V_282 != 0 && V_282 != 1 ) )
goto V_285;
V_271 -> V_242 = V_282 ;
break;
case V_288 :
V_173 = F_98 ( & V_279 [ 0 ] , & V_282 ) ;
if ( V_173 || ( V_282 != 0 && V_282 != 1 ) )
goto V_285;
V_271 -> V_289 = V_282 ;
break;
case V_290 :
default:
V_285:
F_65 ( V_14 , L_60 , V_273 ) ;
return - V_63 ;
}
}
if ( V_269 -> V_291 == NULL ) {
F_65 ( V_14 , L_61 ) ;
F_100 ( & V_14 -> V_25 ) ;
return 0 ;
}
V_173 = V_269 -> V_291 ( V_14 , V_135 ) ;
if ( V_173 == 0 )
F_65 ( V_14 , L_62 ) ;
F_100 ( & V_14 -> V_25 ) ;
return V_173 ;
}
void F_101 ( struct V_11 * V_14 )
{
const struct V_268 * V_269 = V_14 -> V_208 . V_209 ;
if ( F_102 ( ! F_103 ( V_292 , & V_14 -> V_21 ) ) &&
V_269 -> V_293 )
V_269 -> V_293 ( V_14 ) ;
}
static int F_104 ( void * V_294 )
{
if ( F_105 ( V_295 ) )
return - V_296 ;
F_106 () ;
return 0 ;
}
static int F_107 ( struct V_11 * V_14 )
{
if ( V_14 -> V_208 . V_209 -> V_291 == NULL )
return 0 ;
return F_108 ( & V_14 -> V_21 , V_20 , F_104 , V_297 ) ;
}
void F_109 ( struct V_11 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
char V_298 [ 20 ] ;
char V_299 [ 20 ] ;
char * V_207 [] = { V_298 , V_299 , NULL } ;
sprintf ( V_298 , L_63 , ( V_13 -> V_300 & V_301 ) ? 1 : 0 ) ;
sprintf ( V_299 , L_64 , V_14 -> V_136 . V_232 ? 1 : 0 ) ;
F_66 ( & V_14 -> V_211 , V_302 , V_207 ) ;
}
static int F_110 ( struct V_12 * V_13 , struct V_272 * args , int V_55 )
{
struct V_11 * V_14 ;
struct V_143 V_144 ;
int error ;
V_14 = F_3 ( V_13 ) ;
if ( ! V_14 ) {
F_15 ( V_62 L_65 ) ;
return - V_171 ;
}
V_14 -> V_136 = * args ;
if ( V_14 -> V_136 . V_232 ) {
V_13 -> V_300 |= V_301 ;
F_7 ( V_303 , & V_14 -> V_21 ) ;
}
if ( V_14 -> V_136 . V_304 )
V_13 -> V_300 |= V_305 ;
if ( V_14 -> V_136 . V_306 )
F_7 ( V_307 , & V_14 -> V_21 ) ;
V_13 -> V_300 |= V_308 ;
V_13 -> V_309 = V_59 ;
V_13 -> V_310 = & V_311 ;
V_13 -> V_312 = & V_313 ;
V_13 -> V_314 = & V_315 ;
V_13 -> V_316 = V_317 ;
V_13 -> V_318 = & V_319 ;
F_111 ( V_13 ) -> V_320 |= V_321 ;
V_13 -> V_322 = 1 ;
V_13 -> V_323 = V_324 ;
V_14 -> V_57 . V_80 = F_112 ( V_13 , V_325 ) ;
V_14 -> V_57 . V_81 = V_13 -> V_326 ;
V_14 -> V_110 = V_14 -> V_57 . V_81 -
V_111 ;
V_14 -> V_112 = 1 << V_14 -> V_110 ;
V_14 -> V_22 . V_327 = V_14 -> V_136 . V_328 ;
V_14 -> V_22 . V_329 = V_14 -> V_136 . V_330 ;
if ( V_14 -> V_136 . V_331 ) {
V_14 -> V_22 . V_332 = 0 ;
V_14 -> V_22 . V_333 = V_14 -> V_136 . V_331 ;
} else {
V_14 -> V_22 . V_332 = 1 ;
V_14 -> V_22 . V_333 = 30 ;
}
error = F_43 ( V_14 , V_55 ) ;
if ( error )
goto V_152;
snprintf ( V_14 -> V_334 , V_141 , L_66 , V_14 -> V_142 ) ;
F_113 ( V_14 ) ;
error = F_114 ( V_14 ) ;
if ( error )
goto V_152;
error = F_94 ( V_14 , V_55 ) ;
if ( error )
goto V_335;
error = F_45 ( V_14 , & V_144 , DO ) ;
if ( error )
goto V_336;
error = F_55 ( V_14 , V_55 ) ;
if ( error )
goto V_337;
error = F_107 ( V_14 ) ;
if ( error )
goto V_338;
if ( V_14 -> V_208 . V_237 < 0 ) {
error = V_14 -> V_208 . V_237 ;
V_14 -> V_208 . V_237 = 0 ;
goto V_338;
}
if ( V_14 -> V_136 . V_232 )
snprintf ( V_14 -> V_334 , V_141 , L_67 ,
V_14 -> V_142 ) ;
else
snprintf ( V_14 -> V_334 , V_141 , L_68 ,
V_14 -> V_142 , V_14 -> V_208 . V_237 ) ;
error = F_87 ( V_14 , DO ) ;
if ( error )
goto V_338;
error = F_90 ( V_14 , DO ) ;
if ( error )
goto V_339;
error = F_115 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_69 , error ) ;
goto V_340;
}
error = F_91 ( V_14 , DO ) ;
if ( error )
goto V_340;
if ( ! ( V_13 -> V_300 & V_301 ) ) {
error = F_116 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_70 , error ) ;
goto V_341;
}
}
F_49 ( & V_144 ) ;
F_109 ( V_14 ) ;
return 0 ;
V_341:
F_91 ( V_14 , V_252 ) ;
V_340:
F_90 ( V_14 , V_252 ) ;
V_339:
F_87 ( V_14 , V_252 ) ;
V_338:
if ( V_14 -> V_177 )
F_58 ( V_14 -> V_177 ) ;
if ( V_14 -> V_178 )
F_58 ( V_14 -> V_178 ) ;
if ( V_13 -> V_179 )
F_58 ( V_13 -> V_179 ) ;
V_13 -> V_179 = NULL ;
V_337:
F_45 ( V_14 , & V_144 , V_252 ) ;
V_336:
F_117 ( V_14 ) ;
F_101 ( V_14 ) ;
V_335:
F_118 ( V_14 ) ;
V_152:
F_119 ( V_14 ) ;
F_120 ( V_14 -> V_18 ) ;
F_6 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
static int F_121 ( struct V_12 * V_72 , void * V_342 )
{
V_72 -> V_98 = V_342 ;
V_72 -> V_343 = V_72 -> V_98 -> V_344 ;
V_72 -> V_345 = & F_122 ( V_72 -> V_98 ) -> V_346 ;
return 0 ;
}
static int F_123 ( struct V_12 * V_72 , void * V_347 )
{
struct V_348 * V_349 = V_347 ;
return ( V_349 == V_72 -> V_98 ) ;
}
static struct V_166 * F_124 ( struct V_350 * V_351 , int V_320 ,
const char * V_352 , void * V_342 )
{
struct V_348 * V_349 ;
struct V_12 * V_72 ;
T_4 V_353 = V_354 | V_355 ;
int error ;
struct V_272 args ;
struct V_11 * V_14 ;
if ( ! ( V_320 & V_301 ) )
V_353 |= V_356 ;
V_349 = F_125 ( V_352 , V_353 , V_351 ) ;
if ( F_52 ( V_349 ) )
return F_126 ( V_349 ) ;
F_68 ( & V_349 -> V_357 ) ;
if ( V_349 -> V_358 > 0 ) {
F_76 ( & V_349 -> V_357 ) ;
error = - V_359 ;
goto V_360;
}
V_72 = F_127 ( V_351 , F_123 , F_121 , V_349 ) ;
F_76 ( & V_349 -> V_357 ) ;
error = F_53 ( V_72 ) ;
if ( F_52 ( V_72 ) )
goto V_360;
if ( V_72 -> V_179 )
F_128 ( V_349 , V_353 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_361 = V_362 ;
args . V_363 = V_364 ;
args . V_328 = 30 ;
args . V_331 = 30 ;
args . V_330 = 60 ;
args . V_365 = V_366 ;
error = F_129 ( & args , V_342 ) ;
if ( error ) {
F_15 ( V_62 L_71 ) ;
goto V_367;
}
if ( V_72 -> V_179 ) {
error = - V_359 ;
if ( ( V_320 ^ V_72 -> V_300 ) & V_301 )
goto V_367;
} else {
char V_368 [ V_369 ] ;
V_72 -> V_300 = V_320 ;
V_72 -> V_370 = V_353 ;
F_44 ( V_72 -> V_139 , F_130 ( V_349 , V_368 ) , sizeof( V_72 -> V_139 ) ) ;
F_57 ( V_72 , F_131 ( V_349 ) ) ;
error = F_110 ( V_72 , & args , V_320 & V_371 ? 1 : 0 ) ;
if ( error )
goto V_367;
V_72 -> V_300 |= V_372 ;
V_349 -> V_373 = V_72 ;
}
V_14 = V_72 -> V_16 ;
if ( args . V_180 )
return F_59 ( V_14 -> V_178 ) ;
else
return F_59 ( V_14 -> V_177 ) ;
V_367:
F_132 ( V_72 ) ;
return F_133 ( error ) ;
V_360:
F_128 ( V_349 , V_353 ) ;
return F_133 ( error ) ;
}
static int F_134 ( struct V_12 * V_72 , void * V_347 )
{
return - V_63 ;
}
static struct V_166 * F_135 ( struct V_350 * V_351 ,
int V_320 , const char * V_352 , void * V_342 )
{
struct V_12 * V_72 ;
struct V_11 * V_14 ;
struct V_374 V_374 ;
int error ;
error = F_136 ( V_352 , V_375 , & V_374 ) ;
if ( error ) {
F_15 ( V_62 L_72 ,
V_352 , error ) ;
return F_133 ( error ) ;
}
V_72 = F_127 ( & V_376 , F_123 , F_134 ,
V_374 . V_166 -> V_227 -> V_377 -> V_98 ) ;
F_137 ( & V_374 ) ;
if ( F_52 ( V_72 ) ) {
F_15 ( V_62 L_73 ) ;
return F_126 ( V_72 ) ;
}
if ( ( V_320 ^ V_72 -> V_300 ) & V_301 ) {
F_132 ( V_72 ) ;
return F_133 ( - V_359 ) ;
}
V_14 = V_72 -> V_16 ;
return F_59 ( V_14 -> V_178 ) ;
}
static void F_138 ( struct V_12 * V_13 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
if ( V_14 == NULL ) {
F_139 ( V_13 ) ;
return;
}
F_140 ( V_14 ) ;
F_58 ( V_14 -> V_177 ) ;
F_58 ( V_14 -> V_178 ) ;
V_14 -> V_177 = NULL ;
V_14 -> V_178 = NULL ;
F_141 ( V_13 ) ;
F_139 ( V_13 ) ;
F_119 ( V_14 ) ;
F_120 ( V_14 -> V_18 ) ;
F_6 ( V_14 ) ;
}
