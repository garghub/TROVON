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
V_103 = F_40 ( sizeof( V_114 ) * ( 1 << V_123 ) ,
V_14 -> V_117 ) ;
V_104 = 0 ;
for ( V_106 = V_103 ; V_106 > V_14 -> V_112 ; ) {
V_106 = F_40 ( V_106 , V_14 -> V_115 ) ;
V_104 += V_106 ;
}
V_105 = 2 + V_123 ;
V_14 -> V_124 = V_103 + V_104 + V_105 ;
V_14 -> V_125 [ 0 ] = V_14 -> V_56 . V_79 -
sizeof( struct V_113 ) ;
V_14 -> V_125 [ 1 ] = V_14 -> V_56 . V_79 * V_14 -> V_112 ;
for ( V_107 = 2 ; ; V_107 ++ ) {
V_114 V_126 , V_127 ;
T_2 V_128 ;
V_126 = V_14 -> V_125 [ V_107 - 1 ] * V_14 -> V_115 ;
V_127 = V_126 ;
V_128 = F_41 ( V_127 , V_14 -> V_115 ) ;
if ( V_127 != V_14 -> V_125 [ V_107 - 1 ] || V_128 )
break;
V_14 -> V_125 [ V_107 ] = V_126 ;
}
V_14 -> V_129 = V_107 ;
V_14 -> V_125 [ V_107 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_129 <= V_130 ) ;
V_14 -> V_131 [ 0 ] = V_14 -> V_56 . V_79 -
sizeof( struct V_113 ) ;
V_14 -> V_131 [ 1 ] = V_14 -> V_117 * V_14 -> V_112 ;
for ( V_107 = 2 ; ; V_107 ++ ) {
V_114 V_126 , V_127 ;
T_2 V_128 ;
V_126 = V_14 -> V_131 [ V_107 - 1 ] * V_14 -> V_115 ;
V_127 = V_126 ;
V_128 = F_41 ( V_127 , V_14 -> V_115 ) ;
if ( V_127 != V_14 -> V_131 [ V_107 - 1 ] || V_128 )
break;
V_14 -> V_131 [ V_107 ] = V_126 ;
}
V_14 -> V_132 = V_107 ;
V_14 -> V_131 [ V_107 ] = ~ 0 ;
F_42 ( V_14 , V_14 -> V_132 <= V_130 ) ;
return 0 ;
}
static int F_43 ( struct V_11 * V_14 , int V_54 )
{
char * V_133 , * V_134 ;
int error = 0 ;
V_133 = V_14 -> V_135 . V_136 ;
V_134 = V_14 -> V_135 . V_137 ;
if ( ! V_133 [ 0 ] || ! V_134 [ 0 ] ) {
error = F_23 ( V_14 , V_108 >> V_14 -> V_109 , V_54 ) ;
if ( error )
return error ;
if ( ! V_133 [ 0 ] )
V_133 = V_14 -> V_56 . V_85 ;
if ( ! V_134 [ 0 ] )
V_134 = V_14 -> V_56 . V_87 ;
}
if ( ! V_134 [ 0 ] )
V_134 = V_14 -> V_17 -> V_138 ;
F_44 ( V_14 -> V_139 , V_133 , V_140 ) ;
F_44 ( V_14 -> V_141 , V_134 , V_140 ) ;
V_134 = V_14 -> V_141 ;
while ( ( V_134 = strchr ( V_134 , '/' ) ) )
* V_134 = '_' ;
return error ;
}
static int F_45 ( struct V_11 * V_14 , struct V_142 * V_143 ,
int V_144 )
{
int error = 0 ;
if ( V_144 )
goto V_145;
error = F_46 ( V_14 ,
V_146 , & V_147 ,
V_148 , V_149 | V_150 ,
V_143 ) ;
if ( error ) {
F_39 ( V_14 , L_5 , error ) ;
goto V_151;
}
error = F_46 ( V_14 ,
V_152 , & V_147 ,
V_153 ,
V_149 | V_154 ,
& V_14 -> V_155 ) ;
if ( error ) {
F_39 ( V_14 , L_6 , error ) ;
goto V_156;
}
error = F_47 ( V_14 , V_157 , & V_147 ,
V_158 , & V_14 -> V_159 ) ;
if ( error ) {
F_39 ( V_14 , L_7 , error ) ;
goto V_160;
}
error = F_47 ( V_14 , V_161 , & V_162 ,
V_158 , & V_14 -> V_163 ) ;
if ( error ) {
F_39 ( V_14 , L_8 , error ) ;
goto V_164;
}
return 0 ;
V_145:
F_48 ( V_14 -> V_163 ) ;
V_164:
F_48 ( V_14 -> V_159 ) ;
V_160:
F_49 ( & V_14 -> V_155 ) ;
V_156:
F_49 ( V_143 ) ;
V_151:
return error ;
}
static int F_50 ( struct V_12 * V_13 , struct V_165 * * V_166 ,
V_114 V_82 , const char * V_167 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
struct V_165 * V_165 ;
struct V_168 * V_168 ;
V_168 = F_51 ( V_13 , V_169 , V_82 , 0 , 0 ) ;
if ( F_52 ( V_168 ) ) {
F_39 ( V_14 , L_9 , V_167 , F_53 ( V_168 ) ) ;
return F_53 ( V_168 ) ;
}
V_165 = F_54 ( V_168 ) ;
if ( ! V_165 ) {
F_39 ( V_14 , L_10 , V_167 ) ;
return - V_170 ;
}
* V_166 = V_165 ;
return 0 ;
}
static int F_55 ( struct V_11 * V_14 , int V_54 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
struct V_142 V_171 ;
V_114 V_82 ;
int V_172 ;
V_172 = F_46 ( V_14 , V_173 , & V_174 ,
V_153 , 0 , & V_171 ) ;
if ( V_172 ) {
F_39 ( V_14 , L_11 , V_172 ) ;
return V_172 ;
}
V_172 = F_38 ( V_14 , V_54 ) ;
if ( V_172 ) {
F_39 ( V_14 , L_12 , V_172 ) ;
goto V_175;
}
if ( V_14 -> V_56 . V_79 < F_56 ( V_13 -> V_97 ) ) {
V_172 = - V_62 ;
F_39 ( V_14 , L_13
L_14 ,
V_14 -> V_56 . V_79 , F_56 ( V_13 -> V_97 ) ) ;
goto V_175;
}
if ( V_14 -> V_56 . V_79 > V_98 ) {
V_172 = - V_62 ;
F_39 ( V_14 , L_15
L_16 ,
V_14 -> V_56 . V_79 , ( unsigned int ) V_98 ) ;
goto V_175;
}
F_57 ( V_13 , V_14 -> V_56 . V_79 ) ;
V_82 = V_14 -> V_56 . V_84 . V_82 ;
V_172 = F_50 ( V_13 , & V_14 -> V_176 , V_82 , L_17 ) ;
if ( V_172 )
goto V_175;
V_82 = V_14 -> V_56 . V_81 . V_82 ;
V_172 = F_50 ( V_13 , & V_14 -> V_177 , V_82 , L_18 ) ;
if ( V_172 ) {
F_58 ( V_14 -> V_176 ) ;
goto V_175;
}
V_13 -> V_178 = F_59 ( V_14 -> V_135 . V_179 ? V_14 -> V_177 : V_14 -> V_176 ) ;
V_175:
F_49 ( & V_171 ) ;
return V_172 ;
}
static int F_60 ( struct V_11 * V_14 )
{
struct V_180 * V_181 = V_14 -> V_182 ;
unsigned int V_183 ;
V_114 V_184 , V_185 ;
struct V_186 * V_187 = F_61 ( V_181 -> V_188 ) ;
struct V_189 * V_190 = NULL ;
struct V_191 V_192 ;
int V_193 = 0 ;
V_185 = 0 ;
for ( V_183 = 0 ; V_183 < V_194 ( V_181 -> V_188 ) > > V_14 -> V_56 . V_80 ; V_183 ++ ) {
V_192 . V_195 = 0 ;
V_192 . V_196 = 0 ;
V_192 . V_197 = 1 << V_187 -> V_198 . V_199 ;
V_193 = F_62 ( V_181 -> V_188 , V_183 , & V_192 , 0 ) ;
V_184 = V_192 . V_196 ;
if ( V_193 || ! V_184 ) {
F_15 ( V_200 L_19
L_20 , V_193 , V_183 , ( unsigned long long ) V_184 ) ;
break;
}
if ( ! V_185 || V_184 != V_185 + 1 ) {
V_190 = F_4 ( sizeof( struct V_189 ) ,
V_15 ) ;
if ( ! V_190 ) {
F_15 ( V_200 L_21
L_22 ) ;
V_193 = - V_170 ;
break;
}
V_190 -> V_201 = V_184 ;
V_190 -> V_202 = V_183 ;
V_190 -> V_203 = 1 ;
F_63 ( & V_190 -> V_204 , & V_181 -> V_204 ) ;
} else {
V_190 -> V_203 ++ ;
}
V_185 = V_184 ;
}
return V_193 ;
}
static void F_64 ( struct V_11 * V_14 )
{
char * V_205 = L_23 ;
char * V_206 [] = { V_205 , NULL } ;
F_65 ( V_14 , L_24 ) ;
if ( V_14 -> V_207 . V_208 -> V_209 )
V_14 -> V_207 . V_208 -> V_209 ( V_14 ) ;
F_66 ( & V_14 -> V_210 , V_211 , V_206 ) ;
}
static int F_67 ( struct V_11 * V_14 , struct V_142 * V_212 )
{
struct V_186 * V_213 = F_61 ( V_14 -> V_214 ) ;
struct V_215 V_167 ;
char V_70 [ 20 ] ;
struct V_180 * V_181 ;
int error ;
V_167 . V_167 = V_70 ;
F_68 ( & V_14 -> V_32 ) ;
for (; ; ) {
error = F_69 ( V_213 -> V_216 , V_153 , 0 , V_212 ) ;
if ( error )
break;
V_167 . V_217 = sprintf ( V_70 , L_25 , V_14 -> V_218 ) ;
V_167 . V_219 = F_70 ( V_167 . V_167 , V_167 . V_217 ) ;
error = F_71 ( V_14 -> V_214 , & V_167 , NULL ) ;
if ( error == - V_220 ) {
error = 0 ;
break;
}
F_49 ( V_212 ) ;
if ( error )
break;
error = - V_170 ;
V_181 = F_4 ( sizeof( struct V_180 ) , V_15 ) ;
if ( ! V_181 )
break;
F_11 ( & V_181 -> V_204 ) ;
F_72 ( & V_181 -> V_221 , V_222 ) ;
V_181 -> V_188 = F_73 ( V_14 -> V_214 , & V_167 , 1 ) ;
if ( ! V_181 -> V_188 || F_52 ( V_181 -> V_188 ) ) {
if ( ! V_181 -> V_188 )
error = - V_220 ;
else
error = F_53 ( V_181 -> V_188 ) ;
F_6 ( V_181 ) ;
break;
}
F_74 ( & V_14 -> V_31 ) ;
V_181 -> V_223 = V_14 -> V_218 ++ ;
F_63 ( & V_181 -> V_224 , & V_14 -> V_30 ) ;
F_75 ( & V_14 -> V_31 ) ;
}
F_76 ( & V_14 -> V_32 ) ;
return error ;
}
static int F_77 ( struct V_11 * V_14 , int V_144 )
{
struct V_168 * V_225 = V_14 -> V_177 -> V_226 ;
struct V_142 V_212 ;
struct V_186 * V_187 ;
int V_227 = 1 ;
int error = 0 ;
if ( V_144 ) {
V_227 = 0 ;
goto V_228;
}
V_14 -> V_214 = F_78 ( V_225 , L_26 ) ;
if ( F_52 ( V_14 -> V_214 ) ) {
F_39 ( V_14 , L_27 , error ) ;
return F_53 ( V_14 -> V_214 ) ;
}
error = F_67 ( V_14 , & V_212 ) ;
if ( error ) {
F_39 ( V_14 , L_28 , error ) ;
goto V_151;
}
error = - V_229 ;
if ( ! F_79 ( V_14 ) ) {
F_39 ( V_14 , L_29 ) ;
goto V_230;
}
if ( V_14 -> V_135 . V_231 ) {
V_14 -> V_182 = F_80 ( V_14 , 0 ) ;
F_9 ( & V_14 -> V_232 , V_14 -> V_182 -> V_233 ) ;
F_9 ( & V_14 -> V_234 , 2 * V_14 -> V_182 -> V_233 / 5 ) ;
F_9 ( & V_14 -> V_235 , 4 * V_14 -> V_182 -> V_233 / 5 ) ;
} else {
if ( V_14 -> V_207 . V_236 >= F_79 ( V_14 ) ) {
F_39 ( V_14 , L_30 ,
V_14 -> V_207 . V_236 ) ;
F_39 ( V_14 , L_31 ,
F_79 ( V_14 ) ,
F_79 ( V_14 ) - 1 ) ;
goto V_230;
}
V_14 -> V_182 = F_80 ( V_14 , V_14 -> V_207 . V_236 ) ;
error = F_46 ( V_14 , V_14 -> V_207 . V_236 ,
& V_237 ,
V_148 , V_149 ,
& V_14 -> V_238 ) ;
if ( error ) {
F_39 ( V_14 , L_32 , error ) ;
goto V_230;
}
V_187 = F_61 ( V_14 -> V_182 -> V_188 ) ;
error = F_69 ( V_187 -> V_216 , V_153 ,
V_149 | V_154 | V_150 ,
& V_14 -> V_239 ) ;
if ( error ) {
F_39 ( V_14 , L_33 ,
error ) ;
goto V_240;
}
error = F_81 ( V_14 -> V_182 ) ;
if ( error ) {
F_39 ( V_14 , L_34 ,
V_14 -> V_182 -> V_223 , error ) ;
goto V_228;
}
F_9 ( & V_14 -> V_232 , V_14 -> V_182 -> V_233 ) ;
F_9 ( & V_14 -> V_234 , 2 * V_14 -> V_182 -> V_233 / 5 ) ;
F_9 ( & V_14 -> V_235 , 4 * V_14 -> V_182 -> V_233 / 5 ) ;
F_60 ( V_14 ) ;
}
F_82 ( V_14 , F_83 ( & V_14 -> V_232 ) ) ;
if ( V_14 -> V_207 . V_241 ) {
unsigned int V_107 ;
for ( V_107 = 0 ; V_107 < V_14 -> V_218 ; V_107 ++ ) {
error = F_84 ( F_80 ( V_14 , V_107 ) ,
true ) ;
if ( error ) {
F_39 ( V_14 , L_35 ,
V_107 , error ) ;
goto V_228;
}
}
F_64 ( V_14 ) ;
} else if ( ! V_14 -> V_135 . V_231 ) {
error = F_84 ( V_14 -> V_182 , true ) ;
if ( error ) {
F_39 ( V_14 , L_36 , error ) ;
goto V_228;
}
}
F_7 ( V_242 , & V_14 -> V_21 ) ;
F_49 ( & V_212 ) ;
V_227 = 0 ;
return 0 ;
V_228:
if ( ! V_14 -> V_135 . V_231 )
F_49 ( & V_14 -> V_239 ) ;
V_240:
if ( ! V_14 -> V_135 . V_231 )
F_49 ( & V_14 -> V_238 ) ;
V_230:
F_85 ( V_14 ) ;
if ( V_227 )
F_49 ( & V_212 ) ;
V_151:
F_86 ( V_14 -> V_214 ) ;
return error ;
}
static int F_87 ( struct V_11 * V_14 , int V_144 )
{
int error = 0 ;
struct V_168 * V_225 = V_14 -> V_177 -> V_226 ;
if ( V_144 )
goto V_243;
error = F_77 ( V_14 , V_144 ) ;
if ( error )
goto V_151;
V_14 -> V_244 = F_78 ( V_225 , L_37 ) ;
if ( F_52 ( V_14 -> V_244 ) ) {
error = F_53 ( V_14 -> V_244 ) ;
F_39 ( V_14 , L_38 , error ) ;
goto V_245;
}
V_14 -> V_246 = F_78 ( V_225 , L_39 ) ;
if ( F_52 ( V_14 -> V_246 ) ) {
error = F_53 ( V_14 -> V_246 ) ;
F_39 ( V_14 , L_40 , error ) ;
goto V_247;
}
V_14 -> V_248 = 0 ;
V_14 -> V_249 = F_78 ( V_225 , L_41 ) ;
if ( F_52 ( V_14 -> V_249 ) ) {
error = F_53 ( V_14 -> V_249 ) ;
F_39 ( V_14 , L_42 , error ) ;
goto V_250;
}
F_88 ( & V_14 -> V_249 -> V_251 ,
& V_252 ) ;
error = F_89 ( V_14 ) ;
if ( error )
goto V_243;
return 0 ;
V_243:
F_86 ( V_14 -> V_249 ) ;
V_250:
F_90 ( V_14 ) ;
F_86 ( V_14 -> V_246 ) ;
V_247:
F_86 ( V_14 -> V_244 ) ;
V_245:
F_77 ( V_14 , V_253 ) ;
V_151:
return error ;
}
static int F_91 ( struct V_11 * V_14 , int V_144 )
{
struct V_168 * V_254 = NULL ;
char V_70 [ 30 ] ;
int error = 0 ;
struct V_186 * V_187 ;
struct V_168 * V_225 = V_14 -> V_177 -> V_226 ;
if ( V_14 -> V_135 . V_231 )
return 0 ;
if ( V_144 )
goto V_255;
V_254 = F_78 ( V_225 , L_43 ) ;
if ( F_52 ( V_254 ) ) {
error = F_53 ( V_254 ) ;
F_39 ( V_14 , L_44 , error ) ;
return error ;
}
sprintf ( V_70 , L_45 , V_14 -> V_182 -> V_223 ) ;
V_14 -> V_256 = F_78 ( V_254 , V_70 ) ;
if ( F_52 ( V_14 -> V_256 ) ) {
error = F_53 ( V_14 -> V_256 ) ;
F_39 ( V_14 , L_46 , error ) ;
goto V_151;
}
sprintf ( V_70 , L_47 , V_14 -> V_182 -> V_223 ) ;
V_14 -> V_257 = F_78 ( V_254 , V_70 ) ;
if ( F_52 ( V_14 -> V_257 ) ) {
error = F_53 ( V_14 -> V_257 ) ;
F_39 ( V_14 , L_48 , error ) ;
goto V_258;
}
F_86 ( V_254 ) ;
V_254 = NULL ;
V_187 = F_61 ( V_14 -> V_256 ) ;
error = F_69 ( V_187 -> V_216 , V_148 , 0 ,
& V_14 -> V_259 ) ;
if ( error ) {
F_39 ( V_14 , L_49 , error ) ;
goto V_260;
}
V_187 = F_61 ( V_14 -> V_257 ) ;
error = F_69 ( V_187 -> V_216 , V_148 , 0 ,
& V_14 -> V_261 ) ;
if ( error ) {
F_39 ( V_14 , L_50 , error ) ;
goto V_262;
}
return 0 ;
V_255:
F_49 ( & V_14 -> V_261 ) ;
V_262:
F_49 ( & V_14 -> V_259 ) ;
V_260:
F_86 ( V_14 -> V_257 ) ;
V_258:
F_86 ( V_14 -> V_256 ) ;
V_151:
if ( V_254 )
F_86 ( V_254 ) ;
return error ;
}
static int F_92 ( struct V_11 * V_14 , int V_144 )
{
struct V_263 * V_91 ;
int error = 0 ;
if ( V_144 )
goto V_264;
V_91 = F_93 ( V_265 , V_14 , L_51 ) ;
error = F_52 ( V_91 ) ;
if ( error ) {
F_39 ( V_14 , L_52 , error ) ;
return error ;
}
V_14 -> V_266 = V_91 ;
V_91 = F_93 ( V_267 , V_14 , L_53 ) ;
error = F_52 ( V_91 ) ;
if ( error ) {
F_39 ( V_14 , L_54 , error ) ;
goto V_151;
}
V_14 -> V_268 = V_91 ;
return 0 ;
V_264:
F_94 ( V_14 -> V_268 ) ;
V_151:
F_94 ( V_14 -> V_266 ) ;
return error ;
}
static int F_95 ( struct V_11 * V_14 , int V_54 )
{
const struct V_269 * V_270 ;
struct V_271 * V_272 = & V_14 -> V_207 ;
struct V_273 * args = & V_14 -> V_135 ;
const char * V_133 = V_14 -> V_139 ;
const char * V_134 = V_14 -> V_141 ;
char * V_274 , * V_275 ;
int V_172 ;
if ( ! strcmp ( L_55 , V_133 ) ) {
V_270 = & V_276 ;
V_14 -> V_135 . V_277 = 1 ;
#ifdef F_96
} else if ( ! strcmp ( L_56 , V_133 ) ) {
V_270 = & V_278 ;
#endif
} else {
F_15 ( V_200 L_57 , V_133 ) ;
return - V_220 ;
}
F_65 ( V_14 , L_58 , V_133 , V_134 ) ;
V_272 -> V_208 = V_270 ;
V_272 -> V_241 = 1 ;
for ( V_275 = args -> V_279 ; ( V_274 = F_97 ( & V_275 , L_59 ) ) ; ) {
T_3 V_280 [ V_281 ] ;
int V_282 , V_283 ;
if ( ! V_274 || ! * V_274 )
continue;
V_282 = F_98 ( V_274 , * V_270 -> V_284 , V_280 ) ;
switch ( V_282 ) {
case V_285 :
V_172 = F_99 ( & V_280 [ 0 ] , & V_283 ) ;
if ( V_172 || V_283 < 0 )
goto V_286;
if ( F_100 ( V_20 , & V_14 -> V_21 ) )
V_272 -> V_236 = V_283 ;
break;
case V_287 :
case V_288 :
break;
case V_289 :
V_172 = F_99 ( & V_280 [ 0 ] , & V_283 ) ;
if ( V_172 || ( V_283 != 0 && V_283 != 1 ) )
goto V_286;
V_272 -> V_241 = V_283 ;
break;
case V_290 :
default:
V_286:
F_65 ( V_14 , L_60 , V_274 ) ;
return - V_62 ;
}
}
if ( V_270 -> V_291 == NULL ) {
F_65 ( V_14 , L_61 ) ;
F_101 ( & V_14 -> V_25 ) ;
return 0 ;
}
V_172 = V_270 -> V_291 ( V_14 , V_134 ) ;
if ( V_172 == 0 )
F_65 ( V_14 , L_62 ) ;
F_101 ( & V_14 -> V_25 ) ;
return V_172 ;
}
void F_102 ( struct V_11 * V_14 )
{
const struct V_269 * V_270 = V_14 -> V_207 . V_208 ;
if ( F_103 ( ! F_104 ( V_292 , & V_14 -> V_21 ) ) &&
V_270 -> V_293 )
V_270 -> V_293 ( V_14 ) ;
}
static int F_105 ( void * V_294 )
{
if ( F_106 ( V_295 ) )
return - V_296 ;
F_107 () ;
return 0 ;
}
static int F_108 ( struct V_11 * V_14 )
{
if ( V_14 -> V_207 . V_208 -> V_291 == NULL )
return 0 ;
return F_109 ( & V_14 -> V_21 , V_20 , F_105 , V_297 ) ;
}
void F_110 ( struct V_11 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_17 ;
char V_298 [ 20 ] ;
char V_299 [ 20 ] ;
char * V_206 [] = { V_298 , V_299 , NULL } ;
sprintf ( V_298 , L_63 , ( V_13 -> V_300 & V_301 ) ? 1 : 0 ) ;
sprintf ( V_299 , L_64 , V_14 -> V_135 . V_231 ? 1 : 0 ) ;
F_66 ( & V_14 -> V_210 , V_302 , V_206 ) ;
}
static int F_111 ( struct V_12 * V_13 , struct V_273 * args , int V_54 )
{
struct V_11 * V_14 ;
struct V_142 V_143 ;
int error ;
V_14 = F_3 ( V_13 ) ;
if ( ! V_14 ) {
F_15 ( V_61 L_65 ) ;
return - V_170 ;
}
V_14 -> V_135 = * args ;
if ( V_14 -> V_135 . V_231 ) {
V_13 -> V_300 |= V_301 ;
F_7 ( V_303 , & V_14 -> V_21 ) ;
}
if ( V_14 -> V_135 . V_304 )
V_13 -> V_300 |= V_305 ;
if ( V_14 -> V_135 . V_306 )
F_7 ( V_307 , & V_14 -> V_21 ) ;
V_13 -> V_300 |= V_308 ;
V_13 -> V_309 = V_58 ;
V_13 -> V_310 = & V_311 ;
V_13 -> V_312 = & V_313 ;
V_13 -> V_314 = & V_315 ;
V_13 -> V_316 = V_317 ;
V_13 -> V_318 = & V_319 ;
F_112 ( V_13 ) -> V_320 |= V_321 ;
V_13 -> V_322 = 1 ;
V_13 -> V_323 = V_324 ;
V_14 -> V_56 . V_79 = F_113 ( V_13 , V_325 ) ;
V_14 -> V_56 . V_80 = V_13 -> V_326 ;
V_14 -> V_109 = V_14 -> V_56 . V_80 -
V_110 ;
V_14 -> V_111 = 1 << V_14 -> V_109 ;
V_14 -> V_22 . V_327 = V_14 -> V_135 . V_328 ;
V_14 -> V_22 . V_329 = V_14 -> V_135 . V_330 ;
if ( V_14 -> V_135 . V_331 ) {
V_14 -> V_22 . V_332 = 0 ;
V_14 -> V_22 . V_333 = V_14 -> V_135 . V_331 ;
} else {
V_14 -> V_22 . V_332 = 1 ;
V_14 -> V_22 . V_333 = 30 ;
}
error = F_43 ( V_14 , V_54 ) ;
if ( error ) {
F_114 ( V_14 -> V_18 ) ;
F_6 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
snprintf ( V_14 -> V_334 , V_140 , L_66 , V_14 -> V_141 ) ;
error = F_115 ( V_14 ) ;
if ( error )
return error ;
F_116 ( V_14 ) ;
error = F_95 ( V_14 , V_54 ) ;
if ( error )
goto V_335;
error = F_45 ( V_14 , & V_143 , DO ) ;
if ( error )
goto V_336;
error = F_55 ( V_14 , V_54 ) ;
if ( error )
goto V_337;
error = F_108 ( V_14 ) ;
if ( error )
goto V_338;
if ( V_14 -> V_207 . V_236 < 0 ) {
error = V_14 -> V_207 . V_236 ;
V_14 -> V_207 . V_236 = 0 ;
goto V_338;
}
if ( V_14 -> V_135 . V_231 )
snprintf ( V_14 -> V_334 , V_140 , L_67 ,
V_14 -> V_141 ) ;
else
snprintf ( V_14 -> V_334 , V_140 , L_68 ,
V_14 -> V_141 , V_14 -> V_207 . V_236 ) ;
error = F_87 ( V_14 , DO ) ;
if ( error )
goto V_338;
error = F_91 ( V_14 , DO ) ;
if ( error )
goto V_339;
error = F_117 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_69 , error ) ;
goto V_340;
}
error = F_92 ( V_14 , DO ) ;
if ( error )
goto V_340;
if ( ! ( V_13 -> V_300 & V_301 ) ) {
error = F_118 ( V_14 ) ;
if ( error ) {
F_39 ( V_14 , L_70 , error ) ;
goto V_341;
}
}
F_49 ( & V_143 ) ;
F_110 ( V_14 ) ;
return 0 ;
V_341:
F_92 ( V_14 , V_253 ) ;
V_340:
F_91 ( V_14 , V_253 ) ;
V_339:
F_87 ( V_14 , V_253 ) ;
V_338:
if ( V_14 -> V_176 )
F_58 ( V_14 -> V_176 ) ;
if ( V_14 -> V_177 )
F_58 ( V_14 -> V_177 ) ;
if ( V_13 -> V_178 )
F_58 ( V_13 -> V_178 ) ;
V_13 -> V_178 = NULL ;
V_337:
F_45 ( V_14 , & V_143 , V_253 ) ;
V_336:
F_119 ( V_14 ) ;
F_102 ( V_14 ) ;
V_335:
F_120 ( V_14 ) ;
F_114 ( V_14 -> V_18 ) ;
F_121 ( V_14 ) ;
V_13 -> V_16 = NULL ;
return error ;
}
static int F_122 ( struct V_12 * V_71 , void * V_342 )
{
V_71 -> V_97 = V_342 ;
V_71 -> V_343 = V_71 -> V_97 -> V_344 ;
V_71 -> V_345 = & F_123 ( V_71 -> V_97 ) -> V_346 ;
return 0 ;
}
static int F_124 ( struct V_12 * V_71 , void * V_347 )
{
struct V_348 * V_349 = V_347 ;
return ( V_349 == V_71 -> V_97 ) ;
}
static struct V_165 * F_125 ( struct V_350 * V_351 , int V_320 ,
const char * V_352 , void * V_342 )
{
struct V_348 * V_349 ;
struct V_12 * V_71 ;
T_4 V_353 = V_354 | V_355 ;
int error ;
struct V_273 args ;
struct V_11 * V_14 ;
if ( ! ( V_320 & V_301 ) )
V_353 |= V_356 ;
V_349 = F_126 ( V_352 , V_353 , V_351 ) ;
if ( F_52 ( V_349 ) )
return F_127 ( V_349 ) ;
F_68 ( & V_349 -> V_357 ) ;
if ( V_349 -> V_358 > 0 ) {
F_76 ( & V_349 -> V_357 ) ;
error = - V_359 ;
goto V_360;
}
V_71 = F_128 ( V_351 , F_124 , F_122 , V_320 , V_349 ) ;
F_76 ( & V_349 -> V_357 ) ;
error = F_53 ( V_71 ) ;
if ( F_52 ( V_71 ) )
goto V_360;
if ( V_71 -> V_178 )
F_129 ( V_349 , V_353 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_361 = V_362 ;
args . V_363 = V_364 ;
args . V_328 = 30 ;
args . V_331 = 30 ;
args . V_330 = 60 ;
args . V_365 = V_366 ;
error = F_130 ( & args , V_342 ) ;
if ( error ) {
F_15 ( V_61 L_71 ) ;
goto V_367;
}
if ( V_71 -> V_178 ) {
error = - V_359 ;
if ( ( V_320 ^ V_71 -> V_300 ) & V_301 )
goto V_367;
} else {
char V_368 [ V_369 ] ;
V_71 -> V_370 = V_353 ;
F_44 ( V_71 -> V_138 , F_131 ( V_349 , V_368 ) , sizeof( V_71 -> V_138 ) ) ;
F_57 ( V_71 , F_132 ( V_349 ) ) ;
error = F_111 ( V_71 , & args , V_320 & V_371 ? 1 : 0 ) ;
if ( error )
goto V_367;
V_71 -> V_300 |= V_372 ;
V_349 -> V_373 = V_71 ;
}
V_14 = V_71 -> V_16 ;
if ( args . V_179 )
return F_59 ( V_14 -> V_177 ) ;
else
return F_59 ( V_14 -> V_176 ) ;
V_367:
F_133 ( V_71 ) ;
return F_134 ( error ) ;
V_360:
F_129 ( V_349 , V_353 ) ;
return F_134 ( error ) ;
}
static int F_135 ( struct V_12 * V_71 , void * V_347 )
{
return - V_62 ;
}
static struct V_165 * F_136 ( struct V_350 * V_351 ,
int V_320 , const char * V_352 , void * V_342 )
{
struct V_12 * V_71 ;
struct V_11 * V_14 ;
struct V_374 V_374 ;
int error ;
error = F_137 ( V_352 , V_375 , & V_374 ) ;
if ( error ) {
F_15 ( V_61 L_72 ,
V_352 , error ) ;
return F_134 ( error ) ;
}
V_71 = F_128 ( & V_376 , F_124 , F_135 , V_320 ,
V_374 . V_165 -> V_226 -> V_377 -> V_97 ) ;
F_138 ( & V_374 ) ;
if ( F_52 ( V_71 ) ) {
F_15 ( V_61 L_73 ) ;
return F_127 ( V_71 ) ;
}
if ( ( V_320 ^ V_71 -> V_300 ) & V_301 ) {
F_133 ( V_71 ) ;
return F_134 ( - V_359 ) ;
}
V_14 = V_71 -> V_16 ;
return F_59 ( V_14 -> V_177 ) ;
}
static void F_139 ( struct V_12 * V_13 )
{
struct V_11 * V_14 = V_13 -> V_16 ;
if ( V_14 == NULL ) {
F_140 ( V_13 ) ;
return;
}
F_141 ( V_14 ) ;
F_58 ( V_14 -> V_176 ) ;
F_58 ( V_14 -> V_177 ) ;
V_14 -> V_176 = NULL ;
V_14 -> V_177 = NULL ;
F_142 ( V_13 ) ;
F_120 ( V_14 ) ;
F_114 ( V_14 -> V_18 ) ;
F_140 ( V_13 ) ;
}
