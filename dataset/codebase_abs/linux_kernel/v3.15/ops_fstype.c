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
F_11 ( & V_13 -> V_35 ) ;
F_12 ( & V_13 -> V_36 ) ;
F_12 ( & V_13 -> V_37 ) ;
F_8 ( & V_13 -> V_38 ) ;
F_11 ( & V_13 -> V_39 ) ;
F_2 ( & V_13 -> V_40 ) ;
F_2 ( & V_13 -> V_41 ) ;
V_15 = & V_13 -> V_42 ;
F_13 ( V_15 ) ;
V_15 -> V_43 = & V_44 ;
V_15 -> V_45 = V_12 -> V_46 -> V_47 ;
V_15 -> V_48 = 0 ;
F_14 ( V_15 , V_49 ) ;
V_15 -> V_50 = NULL ;
V_15 -> V_51 = V_12 -> V_52 ;
V_15 -> V_53 = 0 ;
F_2 ( & V_13 -> V_54 ) ;
F_9 ( & V_13 -> V_55 , 0 ) ;
F_11 ( & V_13 -> V_56 ) ;
F_11 ( & V_13 -> V_57 ) ;
F_2 ( & V_13 -> V_58 ) ;
F_8 ( & V_13 -> V_59 ) ;
F_8 ( & V_13 -> V_60 ) ;
F_2 ( & V_13 -> V_61 ) ;
F_11 ( & V_13 -> V_62 ) ;
F_11 ( & V_13 -> V_63 ) ;
F_15 ( & V_13 -> V_64 ) ;
F_9 ( & V_13 -> V_65 , 0 ) ;
F_8 ( & V_13 -> V_66 ) ;
return V_13 ;
}
static int F_16 ( struct V_10 * V_13 , int V_67 )
{
struct V_68 * V_12 = & V_13 -> V_69 ;
if ( V_12 -> V_70 != V_71 ||
V_12 -> V_72 != V_73 ) {
if ( ! V_67 )
F_17 ( L_1 ) ;
return - V_74 ;
}
if ( V_12 -> V_75 == V_76 &&
V_12 -> V_77 == V_78 )
return 0 ;
F_18 ( V_13 , L_2 ) ;
return - V_74 ;
}
static void F_19 ( struct V_79 * V_79 , int error )
{
struct V_80 * V_80 = V_79 -> V_81 ;
if ( ! error )
F_20 ( V_80 ) ;
else
F_17 ( L_3 , error ) ;
F_21 ( V_80 ) ;
}
static void F_22 ( struct V_10 * V_13 , const void * V_82 )
{
struct V_68 * V_12 = & V_13 -> V_69 ;
struct V_11 * V_83 = V_13 -> V_18 ;
const struct V_84 * V_85 = V_82 ;
V_12 -> V_70 = F_23 ( V_85 -> V_86 . V_87 ) ;
V_12 -> V_72 = F_23 ( V_85 -> V_86 . V_88 ) ;
V_12 -> V_89 = F_23 ( V_85 -> V_86 . V_90 ) ;
V_12 -> V_75 = F_23 ( V_85 -> V_75 ) ;
V_12 -> V_77 = F_23 ( V_85 -> V_77 ) ;
V_12 -> V_91 = F_23 ( V_85 -> V_91 ) ;
V_12 -> V_92 = F_23 ( V_85 -> V_92 ) ;
V_12 -> V_93 . V_94 = F_24 ( V_85 -> V_93 . V_94 ) ;
V_12 -> V_93 . V_95 = F_24 ( V_85 -> V_93 . V_95 ) ;
V_12 -> V_96 . V_94 = F_24 ( V_85 -> V_96 . V_94 ) ;
V_12 -> V_96 . V_95 = F_24 ( V_85 -> V_96 . V_95 ) ;
memcpy ( V_12 -> V_97 , V_85 -> V_97 , V_98 ) ;
memcpy ( V_12 -> V_99 , V_85 -> V_99 , V_98 ) ;
memcpy ( V_83 -> V_100 , V_85 -> V_101 , 16 ) ;
}
static int F_25 ( struct V_10 * V_13 , T_1 V_102 , int V_67 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_84 * V_103 ;
struct V_80 * V_80 ;
struct V_79 * V_79 ;
V_80 = F_26 ( V_49 ) ;
if ( F_27 ( ! V_80 ) )
return - V_104 ;
F_28 ( V_80 ) ;
F_29 ( V_80 ) ;
F_30 ( V_80 ) ;
V_79 = F_31 ( V_49 , 1 ) ;
V_79 -> V_105 . V_106 = V_102 * ( V_12 -> V_107 >> 9 ) ;
V_79 -> V_108 = V_12 -> V_46 ;
F_32 ( V_79 , V_80 , V_109 , 0 ) ;
V_79 -> V_110 = F_19 ;
V_79 -> V_81 = V_80 ;
F_33 ( V_111 | V_112 , V_79 ) ;
F_34 ( V_80 ) ;
F_35 ( V_79 ) ;
if ( ! F_36 ( V_80 ) ) {
F_37 ( V_80 ) ;
return - V_113 ;
}
V_103 = F_38 ( V_80 ) ;
F_22 ( V_13 , V_103 ) ;
F_39 ( V_80 ) ;
F_37 ( V_80 ) ;
return F_16 ( V_13 , V_67 ) ;
}
static int F_40 ( struct V_10 * V_13 , int V_67 )
{
T_2 V_114 , V_115 , V_116 ;
T_2 V_117 ;
unsigned int V_118 ;
int error ;
error = F_25 ( V_13 , V_119 >> V_13 -> V_120 , V_67 ) ;
if ( error ) {
if ( ! V_67 )
F_41 ( V_13 , L_4 ) ;
return error ;
}
V_13 -> V_120 = V_13 -> V_69 . V_92 -
V_121 ;
V_13 -> V_122 = 1 << V_13 -> V_120 ;
V_13 -> V_123 = ( V_13 -> V_69 . V_91 -
sizeof( struct V_124 ) ) / sizeof( V_125 ) ;
V_13 -> V_126 = ( V_13 -> V_69 . V_91 -
sizeof( struct V_127 ) ) / sizeof( V_125 ) ;
V_13 -> V_128 = V_13 -> V_69 . V_91 - sizeof( struct V_127 ) ;
V_13 -> V_129 = V_13 -> V_69 . V_91 / 2 ;
V_13 -> V_130 = V_13 -> V_69 . V_92 - 1 ;
V_13 -> V_131 = V_13 -> V_129 / sizeof( V_125 ) ;
V_13 -> V_132 = ( V_13 -> V_69 . V_91 -
sizeof( struct V_127 ) ) /
sizeof( struct V_133 ) ;
V_13 -> V_134 = ( V_13 -> V_69 . V_91 -
sizeof( struct V_127 ) )
* V_135 ;
V_114 = F_42 ( sizeof( V_125 ) * ( 1 << V_136 ) ,
V_13 -> V_128 ) ;
V_115 = 0 ;
for ( V_117 = V_114 ; V_117 > V_13 -> V_123 ; ) {
V_117 = F_42 ( V_117 , V_13 -> V_126 ) ;
V_115 += V_117 ;
}
V_116 = 2 + V_136 ;
V_13 -> V_137 = V_114 + V_115 + V_116 ;
V_13 -> V_138 [ 0 ] = V_13 -> V_69 . V_91 -
sizeof( struct V_124 ) ;
V_13 -> V_138 [ 1 ] = V_13 -> V_69 . V_91 * V_13 -> V_123 ;
for ( V_118 = 2 ; ; V_118 ++ ) {
V_125 V_139 , V_140 ;
T_2 V_141 ;
V_139 = V_13 -> V_138 [ V_118 - 1 ] * V_13 -> V_126 ;
V_140 = V_139 ;
V_141 = F_43 ( V_140 , V_13 -> V_126 ) ;
if ( V_140 != V_13 -> V_138 [ V_118 - 1 ] || V_141 )
break;
V_13 -> V_138 [ V_118 ] = V_139 ;
}
V_13 -> V_142 = V_118 ;
V_13 -> V_138 [ V_118 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_142 <= V_143 ) ;
V_13 -> V_144 [ 0 ] = V_13 -> V_69 . V_91 -
sizeof( struct V_124 ) ;
V_13 -> V_144 [ 1 ] = V_13 -> V_128 * V_13 -> V_123 ;
for ( V_118 = 2 ; ; V_118 ++ ) {
V_125 V_139 , V_140 ;
T_2 V_141 ;
V_139 = V_13 -> V_144 [ V_118 - 1 ] * V_13 -> V_126 ;
V_140 = V_139 ;
V_141 = F_43 ( V_140 , V_13 -> V_126 ) ;
if ( V_140 != V_13 -> V_144 [ V_118 - 1 ] || V_141 )
break;
V_13 -> V_144 [ V_118 ] = V_139 ;
}
V_13 -> V_145 = V_118 ;
V_13 -> V_144 [ V_118 ] = ~ 0 ;
F_44 ( V_13 , V_13 -> V_145 <= V_143 ) ;
return 0 ;
}
static int F_45 ( struct V_10 * V_13 , int V_67 )
{
char * V_146 , * V_147 ;
int error = 0 ;
V_146 = V_13 -> V_148 . V_149 ;
V_147 = V_13 -> V_148 . V_150 ;
if ( ! V_146 [ 0 ] || ! V_147 [ 0 ] ) {
error = F_25 ( V_13 , V_119 >> V_13 -> V_120 , V_67 ) ;
if ( error )
return error ;
if ( ! V_146 [ 0 ] )
V_146 = V_13 -> V_69 . V_97 ;
if ( ! V_147 [ 0 ] )
V_147 = V_13 -> V_69 . V_99 ;
}
if ( ! V_147 [ 0 ] )
V_147 = V_13 -> V_18 -> V_151 ;
F_46 ( V_13 -> V_152 , V_146 , V_153 ) ;
F_46 ( V_13 -> V_154 , V_147 , V_153 ) ;
V_147 = V_13 -> V_154 ;
while ( ( V_147 = strchr ( V_147 , '/' ) ) )
* V_147 = '_' ;
return error ;
}
static int F_47 ( struct V_10 * V_13 , struct V_155 * V_156 ,
int V_157 )
{
int error = 0 ;
if ( V_157 )
goto V_158;
error = F_48 ( V_13 ,
V_159 , & V_160 ,
V_161 , V_162 | V_163 ,
V_156 ) ;
if ( error ) {
F_41 ( V_13 , L_5 , error ) ;
goto V_164;
}
error = F_48 ( V_13 ,
V_165 , & V_160 ,
V_166 ,
V_162 | V_167 ,
& V_13 -> V_168 ) ;
if ( error ) {
F_41 ( V_13 , L_6 , error ) ;
goto V_169;
}
error = F_49 ( V_13 , V_170 , & V_160 ,
V_171 , & V_13 -> V_172 ) ;
if ( error ) {
F_41 ( V_13 , L_7 , error ) ;
goto V_173;
}
error = F_49 ( V_13 , V_174 , & V_175 ,
V_171 , & V_13 -> V_176 ) ;
if ( error ) {
F_41 ( V_13 , L_8 , error ) ;
goto V_177;
}
return 0 ;
V_158:
F_50 ( V_13 -> V_176 ) ;
V_177:
F_50 ( V_13 -> V_172 ) ;
V_173:
F_51 ( & V_13 -> V_168 ) ;
V_169:
F_51 ( V_156 ) ;
V_164:
return error ;
}
static int F_52 ( struct V_11 * V_12 , struct V_178 * * V_179 ,
V_125 V_94 , const char * V_180 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
struct V_178 * V_178 ;
struct V_181 * V_181 ;
V_181 = F_53 ( V_12 , V_182 , V_94 , 0 , 0 ) ;
if ( F_54 ( V_181 ) ) {
F_41 ( V_13 , L_9 , V_180 , F_55 ( V_181 ) ) ;
return F_55 ( V_181 ) ;
}
V_178 = F_56 ( V_181 ) ;
if ( ! V_178 ) {
F_41 ( V_13 , L_10 , V_180 ) ;
return - V_104 ;
}
* V_179 = V_178 ;
return 0 ;
}
static int F_57 ( struct V_10 * V_13 , int V_67 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
struct V_155 V_183 ;
V_125 V_94 ;
int V_184 ;
V_184 = F_48 ( V_13 , V_185 , & V_186 ,
V_166 , 0 , & V_183 ) ;
if ( V_184 ) {
F_41 ( V_13 , L_11 , V_184 ) ;
return V_184 ;
}
V_184 = F_40 ( V_13 , V_67 ) ;
if ( V_184 ) {
F_41 ( V_13 , L_12 , V_184 ) ;
goto V_187;
}
if ( V_13 -> V_69 . V_91 < F_58 ( V_12 -> V_46 ) ) {
V_184 = - V_74 ;
F_41 ( V_13 , L_13
L_14 ,
V_13 -> V_69 . V_91 , F_58 ( V_12 -> V_46 ) ) ;
goto V_187;
}
if ( V_13 -> V_69 . V_91 > V_109 ) {
V_184 = - V_74 ;
F_41 ( V_13 , L_15
L_16 ,
V_13 -> V_69 . V_91 , ( unsigned int ) V_109 ) ;
goto V_187;
}
F_59 ( V_12 , V_13 -> V_69 . V_91 ) ;
V_94 = V_13 -> V_69 . V_96 . V_94 ;
V_184 = F_52 ( V_12 , & V_13 -> V_188 , V_94 , L_17 ) ;
if ( V_184 )
goto V_187;
V_94 = V_13 -> V_69 . V_93 . V_94 ;
V_184 = F_52 ( V_12 , & V_13 -> V_189 , V_94 , L_18 ) ;
if ( V_184 ) {
F_60 ( V_13 -> V_188 ) ;
goto V_187;
}
V_12 -> V_190 = F_61 ( V_13 -> V_148 . V_191 ? V_13 -> V_189 : V_13 -> V_188 ) ;
V_187:
F_51 ( & V_183 ) ;
return V_184 ;
}
static void F_62 ( struct V_10 * V_13 )
{
char * V_192 = L_19 ;
char * V_193 [] = { V_192 , NULL } ;
F_63 ( V_13 , L_20 ) ;
if ( V_13 -> V_194 . V_195 -> V_196 )
V_13 -> V_194 . V_195 -> V_196 ( V_13 ) ;
F_64 ( & V_13 -> V_197 , V_198 , V_193 ) ;
}
static int F_65 ( struct V_10 * V_13 , struct V_155 * V_199 )
{
struct V_200 * V_201 = F_66 ( V_13 -> V_202 ) ;
struct V_203 V_180 ;
char V_82 [ 20 ] ;
struct V_204 * V_205 ;
int error ;
V_180 . V_180 = V_82 ;
F_67 ( & V_13 -> V_34 ) ;
for (; ; ) {
error = F_68 ( V_201 -> V_206 , V_166 , 0 , V_199 ) ;
if ( error )
break;
V_180 . V_207 = sprintf ( V_82 , L_21 , V_13 -> V_208 ) ;
V_180 . V_209 = F_69 ( V_180 . V_180 , V_180 . V_207 ) ;
error = F_70 ( V_13 -> V_202 , & V_180 , NULL ) ;
if ( error == - V_210 ) {
error = 0 ;
break;
}
F_51 ( V_199 ) ;
if ( error )
break;
error = - V_104 ;
V_205 = F_4 ( sizeof( struct V_204 ) , V_16 ) ;
if ( ! V_205 )
break;
F_11 ( & V_205 -> V_211 ) ;
F_11 ( & V_205 -> V_212 ) ;
F_71 ( & V_205 -> V_213 , V_214 ) ;
V_205 -> V_215 = F_72 ( V_13 -> V_202 , & V_180 , 1 ) ;
if ( ! V_205 -> V_215 || F_54 ( V_205 -> V_215 ) ) {
if ( ! V_205 -> V_215 )
error = - V_210 ;
else
error = F_55 ( V_205 -> V_215 ) ;
F_6 ( V_205 ) ;
break;
}
F_73 ( & V_13 -> V_33 ) ;
V_205 -> V_216 = V_13 -> V_208 ++ ;
F_74 ( & V_205 -> V_217 , & V_13 -> V_32 ) ;
F_75 ( & V_13 -> V_33 ) ;
}
F_76 ( & V_13 -> V_34 ) ;
return error ;
}
static int F_77 ( struct V_10 * V_13 , struct V_204 * V_205 )
{
int error ;
struct V_155 V_218 ;
struct V_219 V_220 ;
struct V_200 * V_221 ;
V_221 = F_66 ( V_205 -> V_215 ) ;
error = F_68 ( V_221 -> V_206 , V_166 , V_162 |
V_167 | V_163 , & V_218 ) ;
if ( error ) {
F_41 ( V_13 , L_22 ) ;
return - V_222 ;
}
error = F_78 ( V_205 ) ;
if ( error ) {
F_41 ( V_13 , L_23 ) ;
goto V_223;
}
error = F_79 ( V_205 , & V_220 ) ;
if ( error ) {
F_41 ( V_13 , L_24 ) ;
goto V_223;
}
if ( ! ( V_220 . V_224 & V_225 ) ) {
error = - V_222 ;
F_41 ( V_13 , L_25
L_26 , V_205 -> V_216 ) ;
}
V_223:
F_51 ( & V_218 ) ;
return error ;
}
static int F_80 ( struct V_10 * V_13 , int V_157 )
{
struct V_181 * V_226 = V_13 -> V_189 -> V_227 ;
struct V_155 V_199 ;
struct V_200 * V_221 ;
int V_228 = 1 ;
int error = 0 ;
if ( V_157 ) {
V_228 = 0 ;
goto V_229;
}
V_13 -> V_202 = F_81 ( V_226 , L_27 ) ;
if ( F_54 ( V_13 -> V_202 ) ) {
F_41 ( V_13 , L_28 , error ) ;
return F_55 ( V_13 -> V_202 ) ;
}
error = F_65 ( V_13 , & V_199 ) ;
if ( error ) {
F_41 ( V_13 , L_29 , error ) ;
goto V_164;
}
error = - V_230 ;
if ( ! F_82 ( V_13 ) ) {
F_41 ( V_13 , L_30 ) ;
goto V_231;
}
if ( V_13 -> V_148 . V_232 ) {
V_13 -> V_233 = F_83 ( V_13 , 0 ) ;
F_9 ( & V_13 -> V_234 , V_13 -> V_233 -> V_235 ) ;
F_9 ( & V_13 -> V_236 , 2 * V_13 -> V_233 -> V_235 / 5 ) ;
F_9 ( & V_13 -> V_237 , 4 * V_13 -> V_233 -> V_235 / 5 ) ;
} else {
if ( V_13 -> V_194 . V_238 >= F_82 ( V_13 ) ) {
F_41 ( V_13 , L_31 ,
V_13 -> V_194 . V_238 ) ;
F_41 ( V_13 , L_32 ,
F_82 ( V_13 ) ,
F_82 ( V_13 ) - 1 ) ;
goto V_231;
}
V_13 -> V_233 = F_83 ( V_13 , V_13 -> V_194 . V_238 ) ;
error = F_48 ( V_13 , V_13 -> V_194 . V_238 ,
& V_239 ,
V_161 , V_162 ,
& V_13 -> V_240 ) ;
if ( error ) {
F_41 ( V_13 , L_33 , error ) ;
goto V_231;
}
V_221 = F_66 ( V_13 -> V_233 -> V_215 ) ;
error = F_68 ( V_221 -> V_206 , V_166 ,
V_162 | V_167 | V_163 ,
& V_13 -> V_241 ) ;
if ( error ) {
F_41 ( V_13 , L_34 ,
error ) ;
goto V_242;
}
error = F_78 ( V_13 -> V_233 ) ;
if ( error ) {
F_41 ( V_13 , L_35 ,
V_13 -> V_233 -> V_216 , error ) ;
goto V_229;
}
F_9 ( & V_13 -> V_234 , V_13 -> V_233 -> V_235 ) ;
F_9 ( & V_13 -> V_236 , 2 * V_13 -> V_233 -> V_235 / 5 ) ;
F_9 ( & V_13 -> V_237 , 4 * V_13 -> V_233 -> V_235 / 5 ) ;
F_84 ( V_13 , V_13 -> V_233 ) ;
}
F_85 ( V_13 , F_86 ( & V_13 -> V_234 ) ) ;
if ( V_13 -> V_194 . V_243 ) {
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < V_13 -> V_208 ; V_118 ++ ) {
struct V_204 * V_205 = F_83 ( V_13 , V_118 ) ;
if ( V_13 -> V_148 . V_232 ) {
error = F_77 ( V_13 , V_205 ) ;
if ( error )
goto V_229;
continue;
}
error = F_87 ( V_205 , true ) ;
if ( error ) {
F_41 ( V_13 , L_36 ,
V_118 , error ) ;
goto V_229;
}
}
F_62 ( V_13 ) ;
} else if ( ! V_13 -> V_148 . V_232 ) {
error = F_87 ( V_13 -> V_233 , true ) ;
if ( error ) {
F_41 ( V_13 , L_37 , error ) ;
goto V_229;
}
}
F_7 ( V_244 , & V_13 -> V_22 ) ;
F_51 ( & V_199 ) ;
V_228 = 0 ;
return 0 ;
V_229:
if ( ! V_13 -> V_148 . V_232 )
F_51 ( & V_13 -> V_241 ) ;
V_242:
if ( ! V_13 -> V_148 . V_232 )
F_51 ( & V_13 -> V_240 ) ;
V_231:
F_88 ( V_13 ) ;
if ( V_228 )
F_51 ( & V_199 ) ;
V_164:
F_89 ( V_13 -> V_202 ) ;
return error ;
}
static int F_90 ( struct V_10 * V_13 , int V_157 )
{
int error = 0 ;
struct V_181 * V_226 = V_13 -> V_189 -> V_227 ;
if ( V_157 )
goto V_245;
error = F_80 ( V_13 , V_157 ) ;
if ( error )
goto V_164;
V_13 -> V_246 = F_81 ( V_226 , L_38 ) ;
if ( F_54 ( V_13 -> V_246 ) ) {
error = F_55 ( V_13 -> V_246 ) ;
F_41 ( V_13 , L_39 , error ) ;
goto V_247;
}
V_13 -> V_248 = F_81 ( V_226 , L_40 ) ;
if ( F_54 ( V_13 -> V_248 ) ) {
error = F_55 ( V_13 -> V_248 ) ;
F_41 ( V_13 , L_41 , error ) ;
goto V_249;
}
V_13 -> V_250 = 0 ;
V_13 -> V_251 = F_81 ( V_226 , L_42 ) ;
if ( F_54 ( V_13 -> V_251 ) ) {
error = F_55 ( V_13 -> V_251 ) ;
F_41 ( V_13 , L_43 , error ) ;
goto V_252;
}
F_91 ( & V_13 -> V_251 -> V_253 ,
& V_254 ) ;
error = F_92 ( V_13 ) ;
if ( error )
goto V_245;
return 0 ;
V_245:
F_89 ( V_13 -> V_251 ) ;
V_252:
F_93 ( V_13 ) ;
F_89 ( V_13 -> V_248 ) ;
V_249:
F_89 ( V_13 -> V_246 ) ;
V_247:
F_80 ( V_13 , V_255 ) ;
V_164:
return error ;
}
static int F_94 ( struct V_10 * V_13 , int V_157 )
{
struct V_181 * V_256 = NULL ;
char V_82 [ 30 ] ;
int error = 0 ;
struct V_200 * V_221 ;
struct V_181 * V_226 = V_13 -> V_189 -> V_227 ;
if ( V_13 -> V_148 . V_232 )
return 0 ;
if ( V_157 )
goto V_257;
V_256 = F_81 ( V_226 , L_44 ) ;
if ( F_54 ( V_256 ) ) {
error = F_55 ( V_256 ) ;
F_41 ( V_13 , L_45 , error ) ;
return error ;
}
sprintf ( V_82 , L_46 , V_13 -> V_233 -> V_216 ) ;
V_13 -> V_258 = F_81 ( V_256 , V_82 ) ;
if ( F_54 ( V_13 -> V_258 ) ) {
error = F_55 ( V_13 -> V_258 ) ;
F_41 ( V_13 , L_47 , error ) ;
goto V_164;
}
sprintf ( V_82 , L_48 , V_13 -> V_233 -> V_216 ) ;
V_13 -> V_259 = F_81 ( V_256 , V_82 ) ;
if ( F_54 ( V_13 -> V_259 ) ) {
error = F_55 ( V_13 -> V_259 ) ;
F_41 ( V_13 , L_49 , error ) ;
goto V_260;
}
F_89 ( V_256 ) ;
V_256 = NULL ;
V_221 = F_66 ( V_13 -> V_258 ) ;
error = F_68 ( V_221 -> V_206 , V_161 , 0 ,
& V_13 -> V_261 ) ;
if ( error ) {
F_41 ( V_13 , L_50 , error ) ;
goto V_262;
}
V_221 = F_66 ( V_13 -> V_259 ) ;
error = F_68 ( V_221 -> V_206 , V_161 , 0 ,
& V_13 -> V_263 ) ;
if ( error ) {
F_41 ( V_13 , L_51 , error ) ;
goto V_264;
}
return 0 ;
V_257:
F_51 ( & V_13 -> V_263 ) ;
V_264:
F_51 ( & V_13 -> V_261 ) ;
V_262:
F_89 ( V_13 -> V_259 ) ;
V_260:
F_89 ( V_13 -> V_258 ) ;
V_164:
if ( V_256 )
F_89 ( V_256 ) ;
return error ;
}
static int F_95 ( struct V_10 * V_13 , int V_67 )
{
const struct V_265 * V_266 ;
struct V_267 * V_268 = & V_13 -> V_194 ;
struct V_269 * args = & V_13 -> V_148 ;
const char * V_146 = V_13 -> V_152 ;
const char * V_147 = V_13 -> V_154 ;
char * V_270 , * V_271 ;
int V_184 ;
if ( ! strcmp ( L_52 , V_146 ) ) {
V_266 = & V_272 ;
V_13 -> V_148 . V_273 = 1 ;
#ifdef F_96
} else if ( ! strcmp ( L_53 , V_146 ) ) {
V_266 = & V_274 ;
#endif
} else {
F_97 ( L_54 , V_146 ) ;
return - V_210 ;
}
F_63 ( V_13 , L_55 , V_146 , V_147 ) ;
V_268 -> V_195 = V_266 ;
V_268 -> V_243 = 1 ;
for ( V_271 = args -> V_275 ; ( V_270 = F_98 ( & V_271 , L_56 ) ) ; ) {
T_3 V_276 [ V_277 ] ;
int V_278 , V_279 ;
if ( ! V_270 || ! * V_270 )
continue;
V_278 = F_99 ( V_270 , * V_266 -> V_280 , V_276 ) ;
switch ( V_278 ) {
case V_281 :
V_184 = F_100 ( & V_276 [ 0 ] , & V_279 ) ;
if ( V_184 || V_279 < 0 )
goto V_282;
if ( F_101 ( V_21 , & V_13 -> V_22 ) )
V_268 -> V_238 = V_279 ;
break;
case V_283 :
case V_284 :
break;
case V_285 :
V_184 = F_100 ( & V_276 [ 0 ] , & V_279 ) ;
if ( V_184 || ( V_279 != 0 && V_279 != 1 ) )
goto V_282;
V_268 -> V_243 = V_279 ;
break;
case V_286 :
default:
V_282:
F_63 ( V_13 , L_57 , V_270 ) ;
return - V_74 ;
}
}
if ( V_266 -> V_287 == NULL ) {
F_63 ( V_13 , L_58 ) ;
F_102 ( & V_13 -> V_26 ) ;
return 0 ;
}
V_184 = V_266 -> V_287 ( V_13 , V_147 ) ;
if ( V_184 == 0 )
F_63 ( V_13 , L_59 ) ;
F_102 ( & V_13 -> V_26 ) ;
return V_184 ;
}
void F_103 ( struct V_10 * V_13 )
{
const struct V_265 * V_266 = V_13 -> V_194 . V_195 ;
if ( F_104 ( ! F_105 ( V_288 , & V_13 -> V_22 ) ) &&
V_266 -> V_289 )
V_266 -> V_289 ( V_13 ) ;
}
static int F_106 ( void * V_290 )
{
if ( F_107 ( V_291 ) )
return - V_292 ;
F_108 () ;
return 0 ;
}
static int F_109 ( struct V_10 * V_13 )
{
if ( V_13 -> V_194 . V_195 -> V_287 == NULL )
return 0 ;
return F_110 ( & V_13 -> V_22 , V_21 , F_106 , V_293 ) ;
}
void F_111 ( struct V_10 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_18 ;
char V_294 [ 20 ] ;
char V_295 [ 20 ] ;
char * V_193 [] = { V_294 , V_295 , NULL } ;
sprintf ( V_294 , L_60 , ( V_12 -> V_296 & V_297 ) ? 1 : 0 ) ;
sprintf ( V_295 , L_61 , V_13 -> V_148 . V_232 ? 1 : 0 ) ;
F_64 ( & V_13 -> V_197 , V_298 , V_193 ) ;
}
static int F_112 ( struct V_11 * V_12 , struct V_269 * args , int V_67 )
{
struct V_10 * V_13 ;
struct V_155 V_156 ;
int error ;
V_13 = F_3 ( V_12 ) ;
if ( ! V_13 ) {
F_17 ( L_62 ) ;
return - V_104 ;
}
V_13 -> V_148 = * args ;
if ( V_13 -> V_148 . V_232 ) {
V_12 -> V_296 |= V_297 ;
F_7 ( V_299 , & V_13 -> V_22 ) ;
}
if ( V_13 -> V_148 . V_300 )
V_12 -> V_296 |= V_301 ;
if ( V_13 -> V_148 . V_302 )
F_7 ( V_303 , & V_13 -> V_22 ) ;
V_12 -> V_296 |= V_304 ;
V_12 -> V_305 = V_71 ;
V_12 -> V_306 = & V_307 ;
V_12 -> V_308 = & V_309 ;
V_12 -> V_310 = & V_311 ;
V_12 -> V_312 = V_313 ;
V_12 -> V_314 = & V_315 ;
F_113 ( V_12 ) -> V_48 |= V_316 ;
V_12 -> V_317 = 1 ;
V_12 -> V_318 = V_319 ;
V_13 -> V_69 . V_91 = F_114 ( V_12 , V_320 ) ;
V_13 -> V_69 . V_92 = V_12 -> V_321 ;
V_13 -> V_120 = V_13 -> V_69 . V_92 -
V_121 ;
V_13 -> V_122 = 1 << V_13 -> V_120 ;
V_13 -> V_23 . V_322 = V_13 -> V_148 . V_323 ;
V_13 -> V_23 . V_324 = V_13 -> V_148 . V_325 ;
if ( V_13 -> V_148 . V_326 ) {
V_13 -> V_23 . V_327 = 0 ;
V_13 -> V_23 . V_328 = V_13 -> V_148 . V_326 ;
} else {
V_13 -> V_23 . V_327 = 1 ;
V_13 -> V_23 . V_328 = 30 ;
}
error = F_45 ( V_13 , V_67 ) ;
if ( error ) {
F_115 ( V_13 -> V_19 ) ;
F_6 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
snprintf ( V_13 -> V_329 , V_153 , L_63 , V_13 -> V_154 ) ;
error = F_116 ( V_13 ) ;
if ( error )
return error ;
F_117 ( V_13 ) ;
error = F_95 ( V_13 , V_67 ) ;
if ( error )
goto V_330;
error = F_47 ( V_13 , & V_156 , DO ) ;
if ( error )
goto V_331;
error = F_57 ( V_13 , V_67 ) ;
if ( error )
goto V_332;
error = F_109 ( V_13 ) ;
if ( error )
goto V_333;
if ( V_13 -> V_194 . V_238 < 0 ) {
error = V_13 -> V_194 . V_238 ;
V_13 -> V_194 . V_238 = 0 ;
goto V_333;
}
if ( V_13 -> V_148 . V_232 )
snprintf ( V_13 -> V_329 , V_153 , L_64 ,
V_13 -> V_154 ) ;
else
snprintf ( V_13 -> V_329 , V_153 , L_65 ,
V_13 -> V_154 , V_13 -> V_194 . V_238 ) ;
error = F_90 ( V_13 , DO ) ;
if ( error )
goto V_333;
error = F_94 ( V_13 , DO ) ;
if ( error )
goto V_334;
error = F_118 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_66 , error ) ;
goto V_335;
}
if ( ! ( V_12 -> V_296 & V_297 ) ) {
error = F_119 ( V_13 ) ;
if ( error ) {
F_41 ( V_13 , L_67 , error ) ;
goto V_335;
}
}
F_51 ( & V_156 ) ;
F_111 ( V_13 ) ;
return 0 ;
V_335:
F_94 ( V_13 , V_255 ) ;
V_334:
F_90 ( V_13 , V_255 ) ;
V_333:
if ( V_13 -> V_188 )
F_60 ( V_13 -> V_188 ) ;
if ( V_13 -> V_189 )
F_60 ( V_13 -> V_189 ) ;
if ( V_12 -> V_190 )
F_60 ( V_12 -> V_190 ) ;
V_12 -> V_190 = NULL ;
V_332:
F_47 ( V_13 , & V_156 , V_255 ) ;
V_331:
F_120 ( V_13 ) ;
F_103 ( V_13 ) ;
V_330:
F_121 ( V_13 ) ;
F_115 ( V_13 -> V_19 ) ;
F_122 ( V_13 ) ;
V_12 -> V_17 = NULL ;
return error ;
}
static int F_123 ( struct V_11 * V_83 , void * V_336 )
{
V_83 -> V_46 = V_336 ;
V_83 -> V_337 = V_83 -> V_46 -> V_338 ;
V_83 -> V_52 = & F_124 ( V_83 -> V_46 ) -> V_51 ;
return 0 ;
}
static int F_125 ( struct V_11 * V_83 , void * V_339 )
{
struct V_340 * V_341 = V_339 ;
return ( V_341 == V_83 -> V_46 ) ;
}
static struct V_178 * F_126 ( struct V_342 * V_343 , int V_48 ,
const char * V_344 , void * V_336 )
{
struct V_340 * V_341 ;
struct V_11 * V_83 ;
T_4 V_345 = V_346 | V_347 ;
int error ;
struct V_269 args ;
struct V_10 * V_13 ;
if ( ! ( V_48 & V_297 ) )
V_345 |= V_348 ;
V_341 = F_127 ( V_344 , V_345 , V_343 ) ;
if ( F_54 ( V_341 ) )
return F_128 ( V_341 ) ;
F_67 ( & V_341 -> V_349 ) ;
if ( V_341 -> V_350 > 0 ) {
F_76 ( & V_341 -> V_349 ) ;
error = - V_351 ;
goto V_352;
}
V_83 = F_129 ( V_343 , F_125 , F_123 , V_48 , V_341 ) ;
F_76 ( & V_341 -> V_349 ) ;
error = F_55 ( V_83 ) ;
if ( F_54 ( V_83 ) )
goto V_352;
if ( V_83 -> V_190 ) {
F_130 ( & V_83 -> V_353 ) ;
F_131 ( V_341 , V_345 ) ;
F_132 ( & V_83 -> V_353 ) ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_354 = V_355 ;
args . V_356 = V_357 ;
args . V_323 = 30 ;
args . V_326 = 30 ;
args . V_325 = 60 ;
args . V_358 = V_359 ;
error = F_133 ( & args , V_336 ) ;
if ( error ) {
F_17 ( L_68 ) ;
goto V_360;
}
if ( V_83 -> V_190 ) {
error = - V_351 ;
if ( ( V_48 ^ V_83 -> V_296 ) & V_297 )
goto V_360;
} else {
char V_361 [ V_362 ] ;
V_83 -> V_363 = V_345 ;
F_46 ( V_83 -> V_151 , F_134 ( V_341 , V_361 ) , sizeof( V_83 -> V_151 ) ) ;
F_59 ( V_83 , F_135 ( V_341 ) ) ;
error = F_112 ( V_83 , & args , V_48 & V_364 ? 1 : 0 ) ;
if ( error )
goto V_360;
V_83 -> V_296 |= V_365 ;
V_341 -> V_366 = V_83 ;
}
V_13 = V_83 -> V_17 ;
if ( args . V_191 )
return F_61 ( V_13 -> V_189 ) ;
else
return F_61 ( V_13 -> V_188 ) ;
V_360:
F_136 ( V_83 ) ;
return F_137 ( error ) ;
V_352:
F_131 ( V_341 , V_345 ) ;
return F_137 ( error ) ;
}
static int F_138 ( struct V_11 * V_83 , void * V_339 )
{
return - V_74 ;
}
static struct V_178 * F_139 ( struct V_342 * V_343 ,
int V_48 , const char * V_344 , void * V_336 )
{
struct V_11 * V_83 ;
struct V_10 * V_13 ;
struct V_367 V_367 ;
int error ;
error = F_140 ( V_344 , V_368 , & V_367 ) ;
if ( error ) {
F_17 ( L_69 ,
V_344 , error ) ;
return F_137 ( error ) ;
}
V_83 = F_129 ( & V_369 , F_125 , F_138 , V_48 ,
V_367 . V_178 -> V_227 -> V_370 -> V_46 ) ;
F_141 ( & V_367 ) ;
if ( F_54 ( V_83 ) ) {
F_17 ( L_70 ) ;
return F_128 ( V_83 ) ;
}
if ( ( V_48 ^ V_83 -> V_296 ) & V_297 ) {
F_136 ( V_83 ) ;
return F_137 ( - V_351 ) ;
}
V_13 = V_83 -> V_17 ;
return F_61 ( V_13 -> V_189 ) ;
}
static void F_142 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = V_12 -> V_17 ;
if ( V_13 == NULL ) {
F_143 ( V_12 ) ;
return;
}
F_144 ( V_13 ) ;
F_60 ( V_13 -> V_188 ) ;
F_60 ( V_13 -> V_189 ) ;
V_13 -> V_188 = NULL ;
V_13 -> V_189 = NULL ;
F_145 ( V_12 ) ;
F_121 ( V_13 ) ;
F_115 ( V_13 -> V_19 ) ;
F_143 ( V_12 ) ;
}
