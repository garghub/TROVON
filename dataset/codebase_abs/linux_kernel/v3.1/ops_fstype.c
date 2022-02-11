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
F_5 ( V_18 , & V_14 -> V_19 ) ;
F_1 ( & V_14 -> V_20 ) ;
F_6 ( & V_14 -> V_21 ) ;
F_7 ( & V_14 -> V_22 , 0 ) ;
F_8 ( & V_14 -> V_23 ) ;
F_2 ( & V_14 -> V_24 ) ;
F_2 ( & V_14 -> V_25 ) ;
F_9 ( & V_14 -> V_26 ) ;
F_10 ( & V_14 -> V_27 ) ;
F_10 ( & V_14 -> V_28 ) ;
F_10 ( & V_14 -> V_29 ) ;
F_2 ( & V_14 -> V_30 ) ;
F_9 ( & V_14 -> V_31 ) ;
F_10 ( & V_14 -> V_32 ) ;
F_9 ( & V_14 -> V_33 ) ;
F_6 ( & V_14 -> V_34 ) ;
F_10 ( & V_14 -> V_35 ) ;
F_2 ( & V_14 -> V_36 ) ;
F_2 ( & V_14 -> V_37 ) ;
F_7 ( & V_14 -> V_38 , 0 ) ;
F_10 ( & V_14 -> V_39 ) ;
F_10 ( & V_14 -> V_40 ) ;
F_10 ( & V_14 -> V_41 ) ;
F_10 ( & V_14 -> V_42 ) ;
F_10 ( & V_14 -> V_43 ) ;
F_6 ( & V_14 -> V_44 ) ;
F_6 ( & V_14 -> V_45 ) ;
F_2 ( & V_14 -> V_46 ) ;
F_10 ( & V_14 -> V_47 ) ;
F_10 ( & V_14 -> V_48 ) ;
F_11 ( & V_14 -> V_49 ) ;
F_7 ( & V_14 -> V_50 , 0 ) ;
F_6 ( & V_14 -> V_51 ) ;
F_10 ( & V_14 -> V_52 ) ;
F_9 ( & V_14 -> V_53 ) ;
return V_14 ;
}
static int F_12 ( struct V_11 * V_14 , int V_54 )
{
struct V_55 * V_13 = & V_14 -> V_56 ;
if ( V_13 -> V_57 != V_58 ||
V_13 -> V_59 != V_60 ) {
if ( ! V_54 )
F_13 ( V_61 L_1 ) ;
return - V_62 ;
}
if ( V_13 -> V_63 == V_64 &&
V_13 -> V_65 == V_66 )
return 0 ;
F_14 ( V_14 , L_2 ) ;
return - V_62 ;
}
static void F_15 ( struct V_67 * V_67 , int error )
{
struct V_68 * V_68 = V_67 -> V_69 ;
if ( ! error )
F_16 ( V_68 ) ;
else
F_13 ( V_61 L_3 , error ) ;
F_17 ( V_68 ) ;
}
static void F_18 ( struct V_11 * V_14 , const void * V_70 )
{
struct V_55 * V_13 = & V_14 -> V_56 ;
struct V_12 * V_71 = V_14 -> V_17 ;
const struct V_72 * V_73 = V_70 ;
V_13 -> V_57 = F_19 ( V_73 -> V_74 . V_75 ) ;
V_13 -> V_59 = F_19 ( V_73 -> V_74 . V_76 ) ;
V_13 -> V_77 = F_19 ( V_73 -> V_74 . V_78 ) ;
V_13 -> V_63 = F_19 ( V_73 -> V_63 ) ;
V_13 -> V_65 = F_19 ( V_73 -> V_65 ) ;
V_13 -> V_79 = F_19 ( V_73 -> V_79 ) ;
V_13 -> V_80 = F_19 ( V_73 -> V_80 ) ;
V_13 -> V_81 . V_82 = F_20 ( V_73 -> V_81 . V_82 ) ;
V_13 -> V_81 . V_83 = F_20 ( V_73 -> V_81 . V_83 ) ;
V_13 -> V_84 . V_82 = F_20 ( V_73 -> V_84 . V_82 ) ;
V_13 -> V_84 . V_83 = F_20 ( V_73 -> V_84 . V_83 ) ;
memcpy ( V_13 -> V_85 , V_73 -> V_85 , V_86 ) ;
memcpy ( V_13 -> V_87 , V_73 -> V_87 , V_86 ) ;
memcpy ( V_71 -> V_88 , V_73 -> V_89 , 16 ) ;
}
static int F_21 ( struct V_11 * V_14 , T_1 V_90 , int V_54 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_72 * V_91 ;
struct V_68 * V_68 ;
struct V_67 * V_67 ;
V_68 = F_22 ( V_92 ) ;
if ( F_23 ( ! V_68 ) )
return - V_93 ;
F_24 ( V_68 ) ;
F_25 ( V_68 ) ;
F_26 ( V_68 ) ;
V_67 = F_27 ( V_92 , 1 ) ;
V_67 -> V_94 = V_90 * ( V_13 -> V_95 >> 9 ) ;
V_67 -> V_96 = V_13 -> V_97 ;
F_28 ( V_67 , V_68 , V_98 , 0 ) ;
V_67 -> V_99 = F_15 ;
V_67 -> V_69 = V_68 ;
F_29 ( V_100 | V_101 | V_102 , V_67 ) ;
F_30 ( V_68 ) ;
F_31 ( V_67 ) ;
if ( ! F_32 ( V_68 ) ) {
F_33 ( V_68 ) ;
return - V_103 ;
}
V_91 = F_34 ( V_68 ) ;
F_18 ( V_14 , V_91 ) ;
F_35 ( V_68 ) ;
F_33 ( V_68 ) ;
return F_12 ( V_14 , V_54 ) ;
}
static int F_36 ( struct V_11 * V_14 , int V_54 )
{
T_2 V_104 , V_105 , V_106 ;
T_2 V_107 ;
unsigned int V_108 ;
int error ;
error = F_21 ( V_14 , V_109 >> V_14 -> V_110 , V_54 ) ;
if ( error ) {
if ( ! V_54 )
F_37 ( V_14 , L_4 ) ;
return error ;
}
V_14 -> V_110 = V_14 -> V_56 . V_80 -
V_111 ;
V_14 -> V_112 = 1 << V_14 -> V_110 ;
V_14 -> V_113 = ( V_14 -> V_56 . V_79 -
sizeof( struct V_114 ) ) / sizeof( V_115 ) ;
V_14 -> V_116 = ( V_14 -> V_56 . V_79 -
sizeof( struct V_117 ) ) / sizeof( V_115 ) ;
V_14 -> V_118 = V_14 -> V_56 . V_79 - sizeof( struct V_117 ) ;
V_14 -> V_119 = V_14 -> V_56 . V_79 / 2 ;
V_14 -> V_120 = V_14 -> V_56 . V_80 - 1 ;
V_14 -> V_121 = V_14 -> V_119 / sizeof( V_115 ) ;
V_14 -> V_122 = ( V_14 -> V_56 . V_79 -
sizeof( struct V_117 ) ) /
sizeof( struct V_123 ) ;
V_104 = F_38 ( sizeof( V_115 ) * ( 1 << V_124 ) ,
V_14 -> V_118 ) ;
V_105 = 0 ;
for ( V_107 = V_104 ; V_107 > V_14 -> V_113 ; ) {
V_107 = F_38 ( V_107 , V_14 -> V_116 ) ;
V_105 += V_107 ;
}
V_106 = 2 + V_124 ;
V_14 -> V_125 = V_104 + V_105 + V_106 ;
V_14 -> V_126 [ 0 ] = V_14 -> V_56 . V_79 -
sizeof( struct V_114 ) ;
V_14 -> V_126 [ 1 ] = V_14 -> V_56 . V_79 * V_14 -> V_113 ;
for ( V_108 = 2 ; ; V_108 ++ ) {
V_115 V_127 , V_128 ;
T_2 V_129 ;
V_127 = V_14 -> V_126 [ V_108 - 1 ] * V_14 -> V_116 ;
V_128 = V_127 ;
V_129 = F_39 ( V_128 , V_14 -> V_116 ) ;
if ( V_128 != V_14 -> V_126 [ V_108 - 1 ] || V_129 )
break;
V_14 -> V_126 [ V_108 ] = V_127 ;
}
V_14 -> V_130 = V_108 ;
V_14 -> V_126 [ V_108 ] = ~ 0 ;
F_40 ( V_14 , V_14 -> V_130 <= V_131 ) ;
V_14 -> V_132 [ 0 ] = V_14 -> V_56 . V_79 -
sizeof( struct V_114 ) ;
V_14 -> V_132 [ 1 ] = V_14 -> V_118 * V_14 -> V_113 ;
for ( V_108 = 2 ; ; V_108 ++ ) {
V_115 V_127 , V_128 ;
T_2 V_129 ;
V_127 = V_14 -> V_132 [ V_108 - 1 ] * V_14 -> V_116 ;
V_128 = V_127 ;
V_129 = F_39 ( V_128 , V_14 -> V_116 ) ;
if ( V_128 != V_14 -> V_132 [ V_108 - 1 ] || V_129 )
break;
V_14 -> V_132 [ V_108 ] = V_127 ;
}
V_14 -> V_133 = V_108 ;
V_14 -> V_132 [ V_108 ] = ~ 0 ;
F_40 ( V_14 , V_14 -> V_133 <= V_131 ) ;
return 0 ;
}
static int F_41 ( struct V_11 * V_14 , int V_54 )
{
char * V_134 , * V_135 ;
int error = 0 ;
V_134 = V_14 -> V_136 . V_137 ;
V_135 = V_14 -> V_136 . V_138 ;
if ( ! V_134 [ 0 ] || ! V_135 [ 0 ] ) {
error = F_21 ( V_14 , V_109 >> V_14 -> V_110 , V_54 ) ;
if ( error )
return error ;
if ( ! V_134 [ 0 ] )
V_134 = V_14 -> V_56 . V_85 ;
if ( ! V_135 [ 0 ] )
V_135 = V_14 -> V_56 . V_87 ;
}
if ( ! V_135 [ 0 ] )
V_135 = V_14 -> V_17 -> V_139 ;
F_42 ( V_14 -> V_140 , V_134 , V_141 ) ;
F_42 ( V_14 -> V_142 , V_135 , V_141 ) ;
V_135 = V_14 -> V_142 ;
while ( ( V_135 = strchr ( V_135 , '/' ) ) )
* V_135 = '_' ;
return error ;
}
static int F_43 ( struct V_11 * V_14 , struct V_143 * V_144 ,
int V_145 )
{
int error = 0 ;
if ( V_145 )
goto V_146;
error = F_44 ( V_14 ,
V_147 , & V_148 ,
V_149 , V_150 | V_151 ,
V_144 ) ;
if ( error ) {
F_37 ( V_14 , L_5 , error ) ;
goto V_152;
}
error = F_44 ( V_14 ,
V_153 , & V_148 ,
V_154 ,
V_150 | V_155 ,
& V_14 -> V_156 ) ;
if ( error ) {
F_37 ( V_14 , L_6 , error ) ;
goto V_157;
}
error = F_45 ( V_14 , V_158 , & V_148 ,
V_159 , & V_14 -> V_160 ) ;
if ( error ) {
F_37 ( V_14 , L_7 , error ) ;
goto V_161;
}
error = F_45 ( V_14 , V_162 , & V_163 ,
V_159 , & V_14 -> V_164 ) ;
if ( error ) {
F_37 ( V_14 , L_8 , error ) ;
goto V_165;
}
return 0 ;
V_146:
F_46 ( V_14 -> V_164 ) ;
V_165:
F_46 ( V_14 -> V_160 ) ;
V_161:
F_47 ( & V_14 -> V_156 ) ;
V_157:
F_47 ( V_144 ) ;
V_152:
return error ;
}
static int F_48 ( struct V_12 * V_13 , struct V_166 * * V_167 ,
V_115 V_82 , const char * V_168 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
struct V_166 * V_166 ;
struct V_169 * V_169 ;
V_169 = F_49 ( V_13 , V_170 , V_82 , 0 , 0 ) ;
if ( F_50 ( V_169 ) ) {
F_37 ( V_14 , L_9 , V_168 , F_51 ( V_169 ) ) ;
return F_51 ( V_169 ) ;
}
V_166 = F_52 ( V_169 ) ;
if ( ! V_166 ) {
F_37 ( V_14 , L_10 , V_168 ) ;
F_53 ( V_169 ) ;
return - V_171 ;
}
* V_167 = V_166 ;
return 0 ;
}
static int F_54 ( struct V_11 * V_14 , int V_54 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_143 V_172 ;
V_115 V_82 ;
int V_173 ;
V_173 = F_44 ( V_14 , V_174 , & V_175 ,
V_154 , 0 , & V_172 ) ;
if ( V_173 ) {
F_37 ( V_14 , L_11 , V_173 ) ;
return V_173 ;
}
V_173 = F_36 ( V_14 , V_54 ) ;
if ( V_173 ) {
F_37 ( V_14 , L_12 , V_173 ) ;
goto V_176;
}
if ( V_14 -> V_56 . V_79 < F_55 ( V_13 -> V_97 ) ) {
V_173 = - V_62 ;
F_37 ( V_14 , L_13
L_14 ,
V_14 -> V_56 . V_79 , F_55 ( V_13 -> V_97 ) ) ;
goto V_176;
}
if ( V_14 -> V_56 . V_79 > V_98 ) {
V_173 = - V_62 ;
F_37 ( V_14 , L_15
L_16 ,
V_14 -> V_56 . V_79 , ( unsigned int ) V_98 ) ;
goto V_176;
}
F_56 ( V_13 , V_14 -> V_56 . V_79 ) ;
V_82 = V_14 -> V_56 . V_84 . V_82 ;
V_173 = F_48 ( V_13 , & V_14 -> V_177 , V_82 , L_17 ) ;
if ( V_173 )
goto V_176;
V_82 = V_14 -> V_56 . V_81 . V_82 ;
V_173 = F_48 ( V_13 , & V_14 -> V_178 , V_82 , L_18 ) ;
if ( V_173 ) {
F_57 ( V_14 -> V_177 ) ;
goto V_176;
}
V_13 -> V_179 = F_58 ( V_14 -> V_136 . V_180 ? V_14 -> V_178 : V_14 -> V_177 ) ;
V_176:
F_47 ( & V_172 ) ;
return V_173 ;
}
static int F_59 ( struct V_11 * V_14 )
{
struct V_181 * V_182 = V_14 -> V_183 ;
unsigned int V_184 ;
V_115 V_185 , V_186 ;
struct V_187 * V_188 = F_60 ( V_182 -> V_189 ) ;
struct V_190 * V_191 = NULL ;
struct V_192 V_193 ;
int V_194 = 0 ;
V_186 = 0 ;
for ( V_184 = 0 ; V_184 < V_195 ( V_182 -> V_189 ) > > V_14 -> V_56 . V_80 ; V_184 ++ ) {
V_193 . V_196 = 0 ;
V_193 . V_197 = 0 ;
V_193 . V_198 = 1 << V_188 -> V_199 . V_200 ;
V_194 = F_61 ( V_182 -> V_189 , V_184 , & V_193 , 0 ) ;
V_185 = V_193 . V_197 ;
if ( V_194 || ! V_185 ) {
F_13 ( V_201 L_19
L_20 , V_194 , V_184 , ( unsigned long long ) V_185 ) ;
break;
}
if ( ! V_186 || V_185 != V_186 + 1 ) {
V_191 = F_4 ( sizeof( struct V_190 ) ,
V_15 ) ;
if ( ! V_191 ) {
F_13 ( V_201 L_21
L_22 ) ;
V_194 = - V_171 ;
break;
}
V_191 -> V_202 = V_185 ;
V_191 -> V_203 = V_184 ;
V_191 -> V_204 = 1 ;
F_62 ( & V_191 -> V_205 , & V_182 -> V_205 ) ;
} else {
V_191 -> V_204 ++ ;
}
V_186 = V_185 ;
}
return V_194 ;
}
static void F_63 ( struct V_11 * V_14 )
{
char * V_206 = L_23 ;
char * V_207 [] = { V_206 , NULL } ;
struct V_208 * V_209 = & V_14 -> V_210 ;
V_209 -> V_211 = 1 ;
F_64 ( & V_14 -> V_212 , V_213 , V_207 ) ;
}
static int F_65 ( struct V_11 * V_14 , struct V_143 * V_214 )
{
struct V_187 * V_215 = F_60 ( V_14 -> V_216 ) ;
struct V_217 V_168 ;
char V_70 [ 20 ] ;
struct V_181 * V_182 ;
int error ;
V_168 . V_168 = V_70 ;
F_66 ( & V_14 -> V_31 ) ;
for (; ; ) {
error = F_67 ( V_215 -> V_218 , V_154 , 0 , V_214 ) ;
if ( error )
break;
V_168 . V_219 = sprintf ( V_70 , L_24 , V_14 -> V_220 ) ;
V_168 . V_221 = F_68 ( V_168 . V_168 , V_168 . V_219 ) ;
error = F_69 ( V_14 -> V_216 , & V_168 , NULL ) ;
if ( error == - V_222 ) {
error = 0 ;
break;
}
F_47 ( V_214 ) ;
if ( error )
break;
error = - V_171 ;
V_182 = F_4 ( sizeof( struct V_181 ) , V_15 ) ;
if ( ! V_182 )
break;
F_10 ( & V_182 -> V_205 ) ;
F_70 ( & V_182 -> V_223 , V_224 ) ;
V_182 -> V_189 = F_71 ( V_14 -> V_216 , & V_168 , 1 ) ;
if ( ! V_182 -> V_189 || F_50 ( V_182 -> V_189 ) ) {
if ( ! V_182 -> V_189 )
error = - V_222 ;
else
error = F_51 ( V_182 -> V_189 ) ;
F_72 ( V_182 ) ;
break;
}
F_73 ( & V_14 -> V_30 ) ;
V_182 -> V_225 = V_14 -> V_220 ++ ;
F_62 ( & V_182 -> V_226 , & V_14 -> V_29 ) ;
F_74 ( & V_14 -> V_30 ) ;
}
F_75 ( & V_14 -> V_31 ) ;
return error ;
}
static int F_76 ( struct V_11 * V_14 , int V_145 )
{
struct V_169 * V_227 = V_14 -> V_178 -> V_228 ;
struct V_143 V_214 ;
struct V_187 * V_188 ;
int V_229 = 1 ;
int error = 0 ;
if ( V_145 ) {
V_229 = 0 ;
goto V_230;
}
V_14 -> V_216 = F_77 ( V_227 , L_25 ) ;
if ( F_50 ( V_14 -> V_216 ) ) {
F_37 ( V_14 , L_26 , error ) ;
return F_51 ( V_14 -> V_216 ) ;
}
V_188 = F_60 ( V_14 -> V_216 ) ;
error = F_65 ( V_14 , & V_214 ) ;
if ( error ) {
F_37 ( V_14 , L_27 , error ) ;
goto V_152;
}
error = - V_231 ;
if ( ! F_78 ( V_14 ) ) {
F_37 ( V_14 , L_28 ) ;
goto V_232;
}
if ( V_14 -> V_136 . V_233 ) {
V_14 -> V_183 = F_79 ( V_14 , 0 ) ;
F_7 ( & V_14 -> V_234 , V_14 -> V_183 -> V_235 ) ;
F_7 ( & V_14 -> V_236 , 2 * V_14 -> V_183 -> V_235 / 5 ) ;
F_7 ( & V_14 -> V_237 , 4 * V_14 -> V_183 -> V_235 / 5 ) ;
} else {
if ( V_14 -> V_210 . V_238 >= F_78 ( V_14 ) ) {
F_37 ( V_14 , L_29 ,
V_14 -> V_210 . V_238 ) ;
F_37 ( V_14 , L_30 ,
F_78 ( V_14 ) ,
F_78 ( V_14 ) - 1 ) ;
goto V_232;
}
V_14 -> V_183 = F_79 ( V_14 , V_14 -> V_210 . V_238 ) ;
error = F_44 ( V_14 , V_14 -> V_210 . V_238 ,
& V_239 ,
V_149 , V_150 ,
& V_14 -> V_240 ) ;
if ( error ) {
F_37 ( V_14 , L_31 , error ) ;
goto V_232;
}
V_188 = F_60 ( V_14 -> V_183 -> V_189 ) ;
error = F_67 ( V_188 -> V_218 , V_154 ,
V_150 | V_155 | V_151 ,
& V_14 -> V_241 ) ;
if ( error ) {
F_37 ( V_14 , L_32 ,
error ) ;
goto V_242;
}
error = F_80 ( V_14 -> V_183 ) ;
if ( error ) {
F_37 ( V_14 , L_33 ,
V_14 -> V_183 -> V_225 , error ) ;
goto V_230;
}
F_7 ( & V_14 -> V_234 , V_14 -> V_183 -> V_235 ) ;
F_7 ( & V_14 -> V_236 , 2 * V_14 -> V_183 -> V_235 / 5 ) ;
F_7 ( & V_14 -> V_237 , 4 * V_14 -> V_183 -> V_235 / 5 ) ;
F_59 ( V_14 ) ;
}
F_81 ( V_14 , F_82 ( & V_14 -> V_234 ) ) ;
if ( V_14 -> V_210 . V_243 ) {
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_220 ; V_108 ++ ) {
error = F_83 ( F_79 ( V_14 , V_108 ) ,
true ) ;
if ( error ) {
F_37 ( V_14 , L_34 ,
V_108 , error ) ;
goto V_230;
}
}
F_63 ( V_14 ) ;
} else if ( ! V_14 -> V_136 . V_233 ) {
error = F_83 ( V_14 -> V_183 , true ) ;
if ( error ) {
F_37 ( V_14 , L_35 , error ) ;
goto V_230;
}
}
F_5 ( V_244 , & V_14 -> V_19 ) ;
F_47 ( & V_214 ) ;
V_229 = 0 ;
return 0 ;
V_230:
if ( ! V_14 -> V_136 . V_233 )
F_47 ( & V_14 -> V_241 ) ;
V_242:
if ( ! V_14 -> V_136 . V_233 )
F_47 ( & V_14 -> V_240 ) ;
V_232:
F_84 ( V_14 ) ;
if ( V_229 )
F_47 ( & V_214 ) ;
V_152:
F_53 ( V_14 -> V_216 ) ;
return error ;
}
static int F_85 ( struct V_11 * V_14 , int V_145 )
{
int error = 0 ;
struct V_187 * V_188 ;
struct V_169 * V_227 = V_14 -> V_178 -> V_228 ;
if ( V_145 )
goto V_245;
error = F_76 ( V_14 , V_145 ) ;
if ( error )
goto V_152;
V_14 -> V_246 = F_77 ( V_227 , L_36 ) ;
if ( F_50 ( V_14 -> V_246 ) ) {
error = F_51 ( V_14 -> V_246 ) ;
F_37 ( V_14 , L_37 , error ) ;
goto V_247;
}
V_14 -> V_248 = F_77 ( V_227 , L_38 ) ;
if ( F_50 ( V_14 -> V_248 ) ) {
error = F_51 ( V_14 -> V_248 ) ;
F_37 ( V_14 , L_39 , error ) ;
goto V_249;
}
V_188 = F_60 ( V_14 -> V_248 ) ;
V_14 -> V_250 = 0 ;
V_14 -> V_251 = F_77 ( V_227 , L_40 ) ;
if ( F_50 ( V_14 -> V_251 ) ) {
error = F_51 ( V_14 -> V_251 ) ;
F_37 ( V_14 , L_41 , error ) ;
goto V_252;
}
return 0 ;
V_245:
F_53 ( V_14 -> V_251 ) ;
V_252:
F_86 ( V_14 ) ;
F_53 ( V_14 -> V_248 ) ;
V_249:
F_53 ( V_14 -> V_246 ) ;
V_247:
F_76 ( V_14 , V_253 ) ;
V_152:
return error ;
}
static int F_87 ( struct V_11 * V_14 , int V_145 )
{
struct V_169 * V_254 = NULL ;
char V_70 [ 30 ] ;
int error = 0 ;
struct V_187 * V_188 ;
struct V_169 * V_227 = V_14 -> V_178 -> V_228 ;
if ( V_14 -> V_136 . V_233 )
return 0 ;
if ( V_145 )
goto V_255;
V_254 = F_77 ( V_227 , L_42 ) ;
if ( F_50 ( V_254 ) ) {
error = F_51 ( V_254 ) ;
F_37 ( V_14 , L_43 , error ) ;
return error ;
}
sprintf ( V_70 , L_44 , V_14 -> V_183 -> V_225 ) ;
V_14 -> V_256 = F_77 ( V_254 , V_70 ) ;
if ( F_50 ( V_14 -> V_256 ) ) {
error = F_51 ( V_14 -> V_256 ) ;
F_37 ( V_14 , L_45 , error ) ;
goto V_152;
}
sprintf ( V_70 , L_46 , V_14 -> V_183 -> V_225 ) ;
V_14 -> V_257 = F_77 ( V_254 , V_70 ) ;
if ( F_50 ( V_14 -> V_257 ) ) {
error = F_51 ( V_14 -> V_257 ) ;
F_37 ( V_14 , L_47 , error ) ;
goto V_258;
}
F_53 ( V_254 ) ;
V_254 = NULL ;
V_188 = F_60 ( V_14 -> V_256 ) ;
error = F_67 ( V_188 -> V_218 , V_149 , 0 ,
& V_14 -> V_259 ) ;
if ( error ) {
F_37 ( V_14 , L_48 , error ) ;
goto V_260;
}
V_188 = F_60 ( V_14 -> V_257 ) ;
error = F_67 ( V_188 -> V_218 , V_149 , 0 ,
& V_14 -> V_261 ) ;
if ( error ) {
F_37 ( V_14 , L_49 , error ) ;
goto V_262;
}
return 0 ;
V_255:
F_47 ( & V_14 -> V_261 ) ;
V_262:
F_47 ( & V_14 -> V_259 ) ;
V_260:
F_53 ( V_14 -> V_257 ) ;
V_258:
F_53 ( V_14 -> V_256 ) ;
V_152:
if ( V_254 )
F_53 ( V_254 ) ;
return error ;
}
static int F_88 ( struct V_11 * V_14 , int V_145 )
{
struct V_263 * V_91 ;
int error = 0 ;
if ( V_145 )
goto V_264;
V_91 = F_89 ( V_265 , V_14 , L_50 ) ;
error = F_50 ( V_91 ) ;
if ( error ) {
F_37 ( V_14 , L_51 , error ) ;
return error ;
}
V_14 -> V_266 = V_91 ;
V_91 = F_89 ( V_267 , V_14 , L_52 ) ;
error = F_50 ( V_91 ) ;
if ( error ) {
F_37 ( V_14 , L_53 , error ) ;
goto V_152;
}
V_14 -> V_268 = V_91 ;
return 0 ;
V_264:
F_90 ( V_14 -> V_268 ) ;
V_152:
F_90 ( V_14 -> V_266 ) ;
return error ;
}
static int F_91 ( struct V_11 * V_14 , int V_54 )
{
const struct V_269 * V_270 ;
struct V_208 * V_209 = & V_14 -> V_210 ;
struct V_271 * args = & V_14 -> V_136 ;
const char * V_134 = V_14 -> V_140 ;
const char * V_135 = V_14 -> V_142 ;
const char * V_272 ;
char * V_273 , * V_274 ;
int V_173 ;
if ( ! strcmp ( L_54 , V_134 ) ) {
V_270 = & V_275 ;
V_14 -> V_136 . V_276 = 1 ;
#ifdef F_92
} else if ( ! strcmp ( L_55 , V_134 ) ) {
V_270 = & V_277 ;
#endif
} else {
F_13 ( V_201 L_56 , V_134 ) ;
return - V_222 ;
}
F_93 ( V_14 , L_57 , V_134 , V_135 ) ;
V_209 -> V_278 = V_270 ;
V_209 -> V_243 = 1 ;
for ( V_274 = args -> V_279 ; ( V_273 = F_94 ( & V_274 , L_58 ) ) ; ) {
T_3 V_280 [ V_281 ] ;
int V_282 , V_283 ;
if ( ! V_273 || ! * V_273 )
continue;
V_282 = F_95 ( V_273 , * V_270 -> V_284 , V_280 ) ;
switch ( V_282 ) {
case V_285 :
V_173 = F_96 ( & V_280 [ 0 ] , & V_283 ) ;
if ( V_173 || V_283 < 0 )
goto V_286;
if ( F_97 ( V_18 , & V_14 -> V_19 ) )
V_209 -> V_238 = V_283 ;
break;
case V_287 :
break;
case V_288 :
V_173 = F_96 ( & V_280 [ 0 ] , & V_283 ) ;
if ( V_173 || ( V_283 != 0 && V_283 != 1 ) )
goto V_286;
V_209 -> V_243 = V_283 ;
break;
case V_289 :
V_173 = F_96 ( & V_280 [ 0 ] , & V_283 ) ;
if ( V_173 || ( V_283 != 0 && V_283 != 1 ) )
goto V_286;
V_209 -> V_290 = V_283 ;
break;
case V_291 :
default:
V_286:
F_93 ( V_14 , L_59 , V_273 ) ;
return - V_62 ;
}
}
if ( V_14 -> V_136 . V_233 )
snprintf ( V_14 -> V_292 , V_141 , L_60 , V_135 ) ;
else
snprintf ( V_14 -> V_292 , V_141 , L_61 , V_135 ,
V_14 -> V_210 . V_238 ) ;
V_272 = strchr ( V_135 , ':' ) ;
if ( V_272 )
V_272 ++ ;
if ( V_270 -> V_293 == NULL ) {
F_93 ( V_14 , L_62 ) ;
F_98 ( & V_14 -> V_23 ) ;
return 0 ;
}
V_173 = V_270 -> V_293 ( V_14 , V_272 ) ;
if ( V_173 == 0 )
F_93 ( V_14 , L_63 ) ;
F_98 ( & V_14 -> V_23 ) ;
return V_173 ;
}
void F_99 ( struct V_11 * V_14 )
{
const struct V_269 * V_270 = V_14 -> V_210 . V_278 ;
if ( F_100 ( ! F_101 ( V_294 , & V_14 -> V_19 ) ) &&
V_270 -> V_295 )
V_270 -> V_295 ( V_14 ) ;
}
static int F_102 ( void * V_296 )
{
if ( F_103 ( V_297 ) )
return - V_298 ;
F_104 () ;
return 0 ;
}
static int F_105 ( struct V_11 * V_14 )
{
if ( V_14 -> V_210 . V_278 -> V_293 == NULL )
return 0 ;
return F_106 ( & V_14 -> V_19 , V_18 , F_102 , V_299 ) ;
}
void F_107 ( struct V_11 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
char V_300 [ 20 ] ;
char V_301 [ 20 ] ;
char * V_207 [] = { V_300 , V_301 , NULL } ;
sprintf ( V_300 , L_64 , ( V_13 -> V_302 & V_303 ) ? 1 : 0 ) ;
sprintf ( V_301 , L_65 , V_14 -> V_136 . V_233 ? 1 : 0 ) ;
F_64 ( & V_14 -> V_212 , V_304 , V_207 ) ;
}
static int F_108 ( struct V_12 * V_13 , struct V_271 * args , int V_54 )
{
struct V_11 * V_14 ;
struct V_143 V_144 ;
int error ;
V_14 = F_3 ( V_13 ) ;
if ( ! V_14 ) {
F_13 ( V_61 L_66 ) ;
return - V_171 ;
}
V_14 -> V_136 = * args ;
if ( V_14 -> V_136 . V_233 ) {
V_13 -> V_302 |= V_303 ;
F_5 ( V_305 , & V_14 -> V_19 ) ;
}
if ( V_14 -> V_136 . V_306 )
V_13 -> V_302 |= V_307 ;
if ( V_14 -> V_136 . V_308 )
F_5 ( V_309 , & V_14 -> V_19 ) ;
V_13 -> V_302 |= V_310 ;
V_13 -> V_311 = V_58 ;
V_13 -> V_312 = & V_313 ;
V_13 -> V_314 = & V_315 ;
V_13 -> V_316 = & V_317 ;
V_13 -> V_318 = V_319 ;
V_13 -> V_320 = & V_321 ;
F_109 ( V_13 ) -> V_322 |= V_323 ;
V_13 -> V_324 = 1 ;
V_13 -> V_325 = V_326 ;
V_14 -> V_56 . V_79 = F_110 ( V_13 , V_327 ) ;
V_14 -> V_56 . V_80 = V_13 -> V_328 ;
V_14 -> V_110 = V_14 -> V_56 . V_80 -
V_111 ;
V_14 -> V_112 = 1 << V_14 -> V_110 ;
V_14 -> V_20 . V_329 = V_14 -> V_136 . V_330 ;
V_14 -> V_20 . V_331 = V_14 -> V_136 . V_332 ;
if ( V_14 -> V_136 . V_333 ) {
V_14 -> V_20 . V_334 = 0 ;
V_14 -> V_20 . V_335 = V_14 -> V_136 . V_333 ;
} else {
V_14 -> V_20 . V_334 = 1 ;
V_14 -> V_20 . V_335 = 30 ;
}
error = F_41 ( V_14 , V_54 ) ;
if ( error )
goto V_152;
F_111 ( V_14 ) ;
error = F_112 ( V_14 ) ;
if ( error )
goto V_152;
error = F_91 ( V_14 , V_54 ) ;
if ( error )
goto V_336;
error = F_43 ( V_14 , & V_144 , DO ) ;
if ( error )
goto V_337;
error = F_54 ( V_14 , V_54 ) ;
if ( error )
goto V_338;
error = F_105 ( V_14 ) ;
if ( error )
goto V_339;
if ( V_14 -> V_210 . V_238 < 0 ) {
error = V_14 -> V_210 . V_238 ;
V_14 -> V_210 . V_238 = 0 ;
goto V_339;
}
error = F_85 ( V_14 , DO ) ;
if ( error )
goto V_339;
error = F_87 ( V_14 , DO ) ;
if ( error )
goto V_340;
error = F_113 ( V_14 ) ;
if ( error ) {
F_37 ( V_14 , L_67 , error ) ;
goto V_341;
}
error = F_88 ( V_14 , DO ) ;
if ( error )
goto V_341;
if ( ! ( V_13 -> V_302 & V_303 ) ) {
error = F_114 ( V_14 ) ;
if ( error ) {
F_37 ( V_14 , L_68 , error ) ;
goto V_342;
}
}
F_47 ( & V_144 ) ;
F_107 ( V_14 ) ;
return 0 ;
V_342:
F_88 ( V_14 , V_253 ) ;
V_341:
F_87 ( V_14 , V_253 ) ;
V_340:
F_85 ( V_14 , V_253 ) ;
V_339:
if ( V_14 -> V_177 )
F_57 ( V_14 -> V_177 ) ;
if ( V_14 -> V_178 )
F_57 ( V_14 -> V_178 ) ;
if ( V_13 -> V_179 )
F_57 ( V_13 -> V_179 ) ;
V_13 -> V_179 = NULL ;
V_338:
F_43 ( V_14 , & V_144 , V_253 ) ;
V_337:
F_115 ( V_14 ) ;
F_99 ( V_14 ) ;
V_336:
F_116 ( V_14 ) ;
V_152:
F_117 ( V_14 ) ;
F_72 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
static int F_118 ( struct V_12 * V_71 , void * V_343 )
{
V_71 -> V_97 = V_343 ;
V_71 -> V_344 = V_71 -> V_97 -> V_345 ;
V_71 -> V_346 = & F_119 ( V_71 -> V_97 ) -> V_347 ;
return 0 ;
}
static int F_120 ( struct V_12 * V_71 , void * V_348 )
{
struct V_349 * V_350 = V_348 ;
return ( V_350 == V_71 -> V_97 ) ;
}
static struct V_166 * F_121 ( struct V_351 * V_352 , int V_322 ,
const char * V_353 , void * V_343 )
{
struct V_349 * V_350 ;
struct V_12 * V_71 ;
T_4 V_354 = V_355 | V_356 ;
int error ;
struct V_271 args ;
struct V_11 * V_14 ;
if ( ! ( V_322 & V_303 ) )
V_354 |= V_357 ;
V_350 = F_122 ( V_353 , V_354 , V_352 ) ;
if ( F_50 ( V_350 ) )
return F_123 ( V_350 ) ;
F_66 ( & V_350 -> V_358 ) ;
if ( V_350 -> V_359 > 0 ) {
F_75 ( & V_350 -> V_358 ) ;
error = - V_360 ;
goto V_361;
}
V_71 = F_124 ( V_352 , F_120 , F_118 , V_350 ) ;
F_75 ( & V_350 -> V_358 ) ;
error = F_51 ( V_71 ) ;
if ( F_50 ( V_71 ) )
goto V_361;
if ( V_71 -> V_179 )
F_125 ( V_350 , V_354 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_362 = V_363 ;
args . V_364 = V_365 ;
args . V_330 = 30 ;
args . V_333 = 30 ;
args . V_332 = 60 ;
args . V_366 = V_367 ;
error = F_126 ( & args , V_343 ) ;
if ( error ) {
F_13 ( V_61 L_69 ) ;
goto V_368;
}
if ( V_71 -> V_179 ) {
error = - V_360 ;
if ( ( V_322 ^ V_71 -> V_302 ) & V_303 )
goto V_368;
} else {
char V_369 [ V_370 ] ;
V_71 -> V_302 = V_322 ;
V_71 -> V_371 = V_354 ;
F_42 ( V_71 -> V_139 , F_127 ( V_350 , V_369 ) , sizeof( V_71 -> V_139 ) ) ;
F_56 ( V_71 , F_128 ( V_350 ) ) ;
error = F_108 ( V_71 , & args , V_322 & V_372 ? 1 : 0 ) ;
if ( error )
goto V_368;
V_71 -> V_302 |= V_373 ;
V_350 -> V_374 = V_71 ;
}
V_14 = V_71 -> V_16 ;
if ( args . V_180 )
return F_58 ( V_14 -> V_178 ) ;
else
return F_58 ( V_14 -> V_177 ) ;
V_368:
F_129 ( V_71 ) ;
return F_130 ( error ) ;
V_361:
F_125 ( V_350 , V_354 ) ;
return F_130 ( error ) ;
}
static int F_131 ( struct V_12 * V_71 , void * V_348 )
{
return - V_62 ;
}
static struct V_166 * F_132 ( struct V_351 * V_352 ,
int V_322 , const char * V_353 , void * V_343 )
{
struct V_12 * V_71 ;
struct V_11 * V_14 ;
struct V_375 V_375 ;
int error ;
error = F_133 ( V_353 , V_376 , & V_375 ) ;
if ( error ) {
F_13 ( V_61 L_70 ,
V_353 , error ) ;
return F_130 ( error ) ;
}
V_71 = F_124 ( & V_377 , F_120 , F_131 ,
V_375 . V_166 -> V_228 -> V_378 -> V_97 ) ;
F_134 ( & V_375 ) ;
if ( F_50 ( V_71 ) ) {
F_13 ( V_61 L_71 ) ;
return F_123 ( V_71 ) ;
}
if ( ( V_322 ^ V_71 -> V_302 ) & V_303 ) {
F_129 ( V_71 ) ;
return F_130 ( - V_360 ) ;
}
V_14 = V_71 -> V_16 ;
return F_58 ( V_14 -> V_178 ) ;
}
static void F_135 ( struct V_12 * V_13 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
if ( V_14 == NULL ) {
F_136 ( V_13 ) ;
return;
}
F_137 ( V_14 ) ;
F_57 ( V_14 -> V_177 ) ;
F_57 ( V_14 -> V_178 ) ;
V_14 -> V_177 = NULL ;
V_14 -> V_178 = NULL ;
F_138 ( V_13 ) ;
F_136 ( V_13 ) ;
F_117 ( V_14 ) ;
F_72 ( V_14 ) ;
}
