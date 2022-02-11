static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return NULL ;
}
static void F_2 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 && F_4 ( V_9 ) ) {
const struct V_10 * V_11 = ( const struct V_10 * ) V_9 ;
V_3 -> V_12 = V_9 ;
F_5 ( V_3 ) -> V_13 = V_7 -> V_14 ;
F_6 ( V_3 ) -> V_15 = F_7 ( V_11 ) ;
}
}
static T_1 F_8 ( const struct V_6 * V_7 )
{
return F_9 ( F_10 ( V_7 ) -> V_16 . V_17 ,
F_10 ( V_7 ) -> V_18 . V_17 ,
F_11 ( V_7 ) -> V_19 ,
F_11 ( V_7 ) -> V_20 ) ;
}
static T_1 F_12 ( const struct V_21 * V_21 , const struct V_6 * V_7 )
{
return F_13 ( V_21 , F_10 ( V_7 ) -> V_16 . V_17 ,
F_10 ( V_7 ) -> V_18 . V_17 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_22 * V_23 ,
int V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
struct V_27 * V_28 = F_5 ( V_3 ) ;
struct V_29 * V_30 = F_15 ( V_3 ) ;
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_33 * V_34 = F_16 ( V_3 ) ;
struct V_4 * V_18 = NULL , * V_35 , V_36 ;
struct V_37 * V_38 ;
struct V_39 V_40 ;
struct V_8 * V_9 ;
int V_41 ;
int V_42 ;
struct V_43 * V_44 = & F_17 ( V_3 ) -> V_45 . V_44 ;
if ( V_24 < V_46 )
return - V_47 ;
if ( V_26 -> V_48 != V_49 )
return - V_50 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_32 -> V_51 ) {
V_40 . V_52 = V_26 -> V_53 & V_54 ;
F_18 ( V_40 . V_52 ) ;
if ( V_40 . V_52 & V_55 ) {
struct V_56 * V_52 ;
V_52 = F_19 ( V_3 , V_40 . V_52 ) ;
if ( ! V_52 )
return - V_47 ;
F_20 ( V_52 ) ;
}
}
if ( F_21 ( & V_26 -> V_57 ) ) {
if ( F_22 ( & V_3 -> V_58 ) )
F_23 ( F_24 ( V_59 ) ,
& V_26 -> V_57 ) ;
else
V_26 -> V_57 = V_60 ;
}
V_41 = F_25 ( & V_26 -> V_57 ) ;
if ( V_41 & V_61 )
return - V_62 ;
if ( V_41 & V_63 ) {
if ( V_24 >= sizeof( struct V_25 ) &&
V_26 -> V_64 ) {
if ( V_3 -> V_65 &&
V_3 -> V_65 != V_26 -> V_64 )
return - V_47 ;
V_3 -> V_65 = V_26 -> V_64 ;
}
if ( ! V_3 -> V_65 )
return - V_47 ;
}
if ( V_34 -> V_66 . V_67 &&
! F_26 ( & V_3 -> V_68 , & V_26 -> V_57 ) ) {
V_34 -> V_66 . V_69 = 0 ;
V_34 -> V_66 . V_67 = 0 ;
V_34 -> V_70 = 0 ;
}
V_3 -> V_68 = V_26 -> V_57 ;
V_32 -> V_71 = V_40 . V_52 ;
if ( V_41 & V_72 ) {
T_1 V_73 = V_30 -> V_74 ;
struct V_75 sin ;
F_27 ( V_3 , L_1 ) ;
if ( F_28 ( V_3 ) )
return - V_62 ;
sin . V_76 = V_77 ;
sin . V_78 = V_26 -> V_79 ;
sin . V_80 . V_81 = V_26 -> V_57 . V_17 [ 3 ] ;
V_30 -> V_82 = & V_83 ;
V_3 -> V_84 = V_85 ;
#ifdef F_29
V_34 -> V_86 = & V_87 ;
#endif
V_42 = F_30 ( V_3 , (struct V_22 * ) & sin , sizeof( sin ) ) ;
if ( V_42 ) {
V_30 -> V_74 = V_73 ;
V_30 -> V_82 = & V_88 ;
V_3 -> V_84 = V_89 ;
#ifdef F_29
V_34 -> V_86 = & V_90 ;
#endif
goto V_91;
}
V_32 -> V_18 = V_3 -> V_58 ;
return V_42 ;
}
if ( ! F_21 ( & V_3 -> V_58 ) )
V_18 = & V_3 -> V_58 ;
V_40 . V_92 = V_93 ;
V_40 . V_16 = V_3 -> V_68 ;
V_40 . V_18 = V_18 ? * V_18 : V_32 -> V_18 ;
V_40 . V_94 = V_3 -> V_65 ;
V_40 . V_95 = V_3 -> V_96 ;
V_40 . V_97 = V_26 -> V_79 ;
V_40 . V_98 = V_28 -> V_99 ;
V_40 . V_100 = V_3 -> V_101 ;
V_38 = F_31 ( V_32 -> V_38 , F_32 ( V_3 ) ) ;
V_35 = F_33 ( & V_40 , V_38 , & V_36 ) ;
F_34 ( V_3 , F_35 ( & V_40 ) ) ;
V_9 = F_36 ( V_3 , & V_40 , V_35 ) ;
if ( F_37 ( V_9 ) ) {
V_42 = F_38 ( V_9 ) ;
goto V_91;
}
if ( ! V_18 ) {
V_18 = & V_40 . V_18 ;
V_3 -> V_58 = * V_18 ;
}
V_32 -> V_18 = * V_18 ;
V_28 -> V_102 = V_103 ;
V_3 -> V_104 = V_105 ;
F_39 ( V_3 , V_9 , NULL , NULL ) ;
V_30 -> V_74 = 0 ;
if ( V_38 )
V_30 -> V_74 = V_38 -> V_106 +
V_38 -> V_107 ;
V_34 -> V_66 . V_108 = V_109 - sizeof( struct V_110 ) - sizeof( struct V_111 ) ;
V_28 -> V_112 = V_26 -> V_79 ;
F_40 ( V_3 , V_113 ) ;
V_42 = F_41 ( V_44 , V_3 ) ;
if ( V_42 )
goto V_114;
F_42 ( V_3 ) ;
if ( F_43 ( ! V_34 -> V_115 ) ) {
if ( ! V_34 -> V_70 )
V_34 -> V_70 = F_9 ( V_32 -> V_18 . V_17 ,
V_3 -> V_68 . V_17 ,
V_28 -> V_99 ,
V_28 -> V_112 ) ;
V_34 -> V_116 = F_13 ( F_17 ( V_3 ) ,
V_32 -> V_18 . V_17 ,
V_3 -> V_68 . V_17 ) ;
}
if ( F_44 ( V_3 , & V_42 ) )
return V_42 ;
if ( V_42 )
goto V_114;
V_42 = F_45 ( V_3 ) ;
if ( V_42 )
goto V_114;
return 0 ;
V_114:
F_40 ( V_3 , V_117 ) ;
V_91:
V_28 -> V_112 = 0 ;
V_3 -> V_118 = 0 ;
return V_42 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_119 ) & ( V_120 | V_121 ) )
return;
V_9 = F_47 ( V_3 , F_16 ( V_3 ) -> V_122 ) ;
if ( ! V_9 )
return;
if ( F_15 ( V_3 ) -> V_123 > F_48 ( V_9 ) ) {
F_49 ( V_3 , F_48 ( V_9 ) ) ;
F_50 ( V_3 ) ;
}
}
static void F_51 ( struct V_6 * V_7 , struct V_124 * V_38 ,
T_2 type , T_2 V_125 , int V_126 , T_3 V_127 )
{
const struct V_111 * V_128 = ( const struct V_111 * ) V_7 -> V_129 ;
const struct V_110 * V_130 = (struct V_110 * ) ( V_7 -> V_129 + V_126 ) ;
struct V_21 * V_21 = F_52 ( V_7 -> V_131 ) ;
struct V_132 * V_133 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_4 V_134 , V_135 ;
struct V_2 * V_3 ;
bool V_136 ;
int V_42 ;
V_3 = F_53 ( V_21 , & V_137 ,
& V_128 -> V_16 , V_130 -> V_19 ,
& V_128 -> V_18 , F_54 ( V_130 -> V_20 ) ,
V_7 -> V_131 -> V_138 , F_55 ( V_7 ) ) ;
if ( ! V_3 ) {
F_56 ( V_21 , F_57 ( V_7 -> V_131 ) ,
V_139 ) ;
return;
}
if ( V_3 -> V_119 == V_140 ) {
F_58 ( F_59 ( V_3 ) ) ;
return;
}
V_134 = F_60 ( V_130 -> V_134 ) ;
V_136 = F_61 ( type , V_125 , & V_42 ) ;
if ( V_3 -> V_119 == V_141 )
return F_62 ( V_3 , V_134 , V_136 ) ;
F_63 ( V_3 ) ;
if ( F_64 ( V_3 ) && type != V_142 )
F_65 ( V_21 , V_143 ) ;
if ( V_3 -> V_119 == V_117 )
goto V_144;
if ( F_10 ( V_7 ) -> V_145 < F_6 ( V_3 ) -> V_146 ) {
F_65 ( V_21 , V_147 ) ;
goto V_144;
}
V_34 = F_16 ( V_3 ) ;
V_133 = V_34 -> V_148 ;
V_135 = V_133 ? F_66 ( V_133 ) -> V_149 : V_34 -> V_135 ;
if ( V_3 -> V_119 != V_150 &&
! F_67 ( V_134 , V_135 , V_34 -> V_151 ) ) {
F_65 ( V_21 , V_152 ) ;
goto V_144;
}
V_32 = F_6 ( V_3 ) ;
if ( type == V_153 ) {
if ( ! F_64 ( V_3 ) ) {
struct V_8 * V_9 = F_68 ( V_3 , V_32 -> V_154 ) ;
if ( V_9 )
V_9 -> V_155 -> V_156 ( V_9 , V_3 , V_7 ) ;
}
goto V_144;
}
if ( type == V_142 ) {
if ( V_3 -> V_119 == V_150 )
goto V_144;
if ( ! F_69 ( V_3 ) )
goto V_144;
V_34 -> V_122 = F_60 ( V_127 ) ;
if ( ! F_64 ( V_3 ) )
F_46 ( V_3 ) ;
else if ( ! F_70 ( V_157 ,
& V_3 -> V_158 ) )
F_71 ( V_3 ) ;
goto V_144;
}
switch ( V_3 -> V_119 ) {
case V_113 :
case V_159 :
if ( V_133 && ! V_133 -> V_3 )
break;
if ( ! F_64 ( V_3 ) ) {
V_3 -> V_160 = V_42 ;
V_3 -> V_161 ( V_3 ) ;
F_72 ( V_3 ) ;
} else
V_3 -> V_162 = V_42 ;
goto V_144;
}
if ( ! F_64 ( V_3 ) && V_32 -> V_163 ) {
V_3 -> V_160 = V_42 ;
V_3 -> V_161 ( V_3 ) ;
} else
V_3 -> V_162 = V_42 ;
V_144:
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
}
static int F_75 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_164 * V_165 ,
struct V_132 * V_166 ,
struct V_167 * V_168 ,
enum V_169 V_170 )
{
struct V_171 * V_172 = F_76 ( V_166 ) ;
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 = & V_165 -> V_173 . V_174 ;
struct V_6 * V_7 ;
int V_42 = - V_175 ;
if ( ! V_9 && ( V_9 = F_77 ( V_3 , V_40 , V_166 ,
V_93 ) ) == NULL )
goto V_176;
V_7 = F_78 ( V_3 , V_9 , V_166 , V_168 , V_170 ) ;
if ( V_7 ) {
F_79 ( V_7 , & V_172 -> V_177 ,
& V_172 -> V_178 ) ;
V_40 -> V_16 = V_172 -> V_178 ;
if ( V_32 -> V_179 && V_172 -> V_180 )
V_40 -> V_52 = V_56 ( F_10 ( V_172 -> V_180 ) ) ;
F_80 () ;
V_38 = V_172 -> V_181 ;
if ( ! V_38 )
V_38 = F_81 ( V_32 -> V_38 ) ;
V_42 = F_82 ( V_3 , V_7 , V_40 , V_3 -> V_96 , V_38 , V_32 -> V_182 ) ;
F_83 () ;
V_42 = F_84 ( V_42 ) ;
}
V_176:
return V_42 ;
}
static void F_85 ( struct V_132 * V_166 )
{
F_86 ( F_76 ( V_166 ) -> V_181 ) ;
F_87 ( F_76 ( V_166 ) -> V_180 ) ;
}
static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_88 ( V_3 , (union V_183 * ) V_5 , V_49 ) ;
}
static struct V_1 * F_89 ( const struct V_2 * V_3 ,
const struct V_2 * V_184 )
{
return F_1 ( V_3 , & V_184 -> V_68 ) ;
}
static int F_90 ( struct V_2 * V_3 , int V_185 ,
char T_5 * V_186 , int V_187 )
{
struct V_188 V_189 ;
struct V_25 * V_190 = (struct V_25 * ) & V_189 . V_191 ;
T_2 V_192 ;
if ( V_187 < sizeof( V_189 ) )
return - V_47 ;
if ( F_91 ( & V_189 , V_186 , sizeof( V_189 ) ) )
return - V_193 ;
if ( V_190 -> V_48 != V_49 )
return - V_47 ;
if ( V_185 == V_194 &&
V_189 . V_195 & V_196 ) {
V_192 = V_189 . V_197 ;
if ( V_192 > 128 || ( F_22 ( & V_190 -> V_57 ) &&
V_192 > 32 ) )
return - V_47 ;
} else {
V_192 = F_22 ( & V_190 -> V_57 ) ? 32 : 128 ;
}
if ( ! V_189 . V_198 ) {
if ( F_22 ( & V_190 -> V_57 ) )
return F_92 ( V_3 , (union V_183 * ) & V_190 -> V_57 . V_17 [ 3 ] ,
V_77 , V_192 ) ;
return F_92 ( V_3 , (union V_183 * ) & V_190 -> V_57 ,
V_49 , V_192 ) ;
}
if ( V_189 . V_198 > V_199 )
return - V_47 ;
if ( F_22 ( & V_190 -> V_57 ) )
return F_93 ( V_3 , (union V_183 * ) & V_190 -> V_57 . V_17 [ 3 ] ,
V_77 , V_192 , V_189 . V_200 ,
V_189 . V_198 , V_201 ) ;
return F_93 ( V_3 , (union V_183 * ) & V_190 -> V_57 ,
V_49 , V_192 , V_189 . V_200 ,
V_189 . V_198 , V_201 ) ;
}
static int F_94 ( struct V_202 * V_203 ,
const struct V_4 * V_16 ,
const struct V_4 * V_18 ,
const struct V_110 * V_130 , int V_204 )
{
struct V_205 * V_206 ;
struct V_207 V_208 ;
struct V_110 * V_209 ;
V_206 = V_203 -> V_210 ;
V_206 -> V_18 = * V_18 ;
V_206 -> V_16 = * V_16 ;
V_206 -> V_211 = F_95 ( V_93 ) ;
V_206 -> V_212 = F_95 ( V_204 ) ;
V_209 = (struct V_110 * ) ( V_206 + 1 ) ;
memcpy ( V_209 , V_130 , sizeof( * V_130 ) ) ;
V_209 -> V_213 = 0 ;
F_96 ( & V_208 , V_206 , sizeof( * V_206 ) + sizeof( * V_130 ) ) ;
F_97 ( V_203 -> V_214 , & V_208 , NULL ,
sizeof( * V_206 ) + sizeof( * V_130 ) ) ;
return F_98 ( V_203 -> V_214 ) ;
}
static int F_99 ( char * V_215 , const struct V_1 * V_216 ,
const struct V_4 * V_16 , struct V_4 * V_18 ,
const struct V_110 * V_130 )
{
struct V_202 * V_203 ;
struct V_217 * V_166 ;
V_203 = F_100 () ;
if ( ! V_203 )
goto V_218;
V_166 = V_203 -> V_214 ;
if ( F_101 ( V_166 ) )
goto V_219;
if ( F_94 ( V_203 , V_16 , V_18 , V_130 , V_130 -> V_220 << 2 ) )
goto V_219;
if ( F_102 ( V_203 , V_216 ) )
goto V_219;
F_97 ( V_166 , NULL , V_215 , 0 ) ;
if ( F_103 ( V_166 ) )
goto V_219;
F_104 () ;
return 0 ;
V_219:
F_104 () ;
V_218:
memset ( V_215 , 0 , 16 ) ;
return 1 ;
}
static int F_105 ( char * V_215 ,
const struct V_1 * V_216 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_18 , * V_16 ;
struct V_202 * V_203 ;
struct V_217 * V_166 ;
const struct V_110 * V_130 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_18 = & V_3 -> V_58 ;
V_16 = & V_3 -> V_68 ;
} else {
const struct V_111 * V_221 = F_10 ( V_7 ) ;
V_18 = & V_221 -> V_18 ;
V_16 = & V_221 -> V_16 ;
}
V_203 = F_100 () ;
if ( ! V_203 )
goto V_218;
V_166 = V_203 -> V_214 ;
if ( F_101 ( V_166 ) )
goto V_219;
if ( F_94 ( V_203 , V_16 , V_18 , V_130 , V_7 -> V_212 ) )
goto V_219;
if ( F_106 ( V_203 , V_7 , V_130 -> V_220 << 2 ) )
goto V_219;
if ( F_102 ( V_203 , V_216 ) )
goto V_219;
F_97 ( V_166 , NULL , V_215 , 0 ) ;
if ( F_103 ( V_166 ) )
goto V_219;
F_104 () ;
return 0 ;
V_219:
F_104 () ;
V_218:
memset ( V_215 , 0 , 16 ) ;
return 1 ;
}
static bool F_107 ( const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
#ifdef F_29
const T_6 * V_222 = NULL ;
struct V_1 * V_223 ;
const struct V_111 * V_221 = F_10 ( V_7 ) ;
const struct V_110 * V_130 = F_11 ( V_7 ) ;
int V_224 ;
T_2 V_225 [ 16 ] ;
V_223 = F_1 ( V_3 , & V_221 -> V_18 ) ;
V_222 = F_108 ( V_130 ) ;
if ( ! V_223 && ! V_222 )
return false ;
if ( V_223 && ! V_222 ) {
F_109 ( F_17 ( V_3 ) , V_226 ) ;
return true ;
}
if ( ! V_223 && V_222 ) {
F_109 ( F_17 ( V_3 ) , V_227 ) ;
return true ;
}
V_224 = F_105 ( V_225 ,
V_223 ,
NULL , V_7 ) ;
if ( V_224 || memcmp ( V_222 , V_225 , 16 ) != 0 ) {
F_109 ( F_17 ( V_3 ) , V_228 ) ;
F_110 ( L_2 ,
V_224 ? L_3 : L_4 ,
& V_221 -> V_18 , F_54 ( V_130 -> V_20 ) ,
& V_221 -> V_16 , F_54 ( V_130 -> V_19 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_111 ( struct V_132 * V_166 ,
const struct V_2 * V_229 ,
struct V_6 * V_7 )
{
struct V_171 * V_172 = F_76 ( V_166 ) ;
const struct V_31 * V_32 = F_6 ( V_229 ) ;
V_172 -> V_178 = F_10 ( V_7 ) -> V_18 ;
V_172 -> V_177 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_229 -> V_65 &&
F_25 ( & V_172 -> V_178 ) & V_63 )
V_172 -> V_230 = F_112 ( V_7 ) ;
if ( ! F_113 ( V_7 ) -> V_231 &&
( F_114 ( V_229 , V_7 , & F_113 ( V_7 ) -> V_232 . V_233 ) ||
V_32 -> V_234 . V_235 . V_236 ||
V_32 -> V_234 . V_235 . V_237 || V_32 -> V_234 . V_235 . V_238 ||
V_32 -> V_234 . V_235 . V_239 || V_32 -> V_179 ) ) {
F_115 ( & V_7 -> V_240 ) ;
V_172 -> V_180 = V_7 ;
}
}
static struct V_8 * F_116 ( const struct V_2 * V_3 ,
struct V_164 * V_165 ,
const struct V_132 * V_166 )
{
return F_77 ( V_3 , & V_165 -> V_173 . V_174 , V_166 , V_93 ) ;
}
static void F_117 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_134 ,
T_1 V_241 , T_1 V_242 , T_1 V_243 , T_1 V_244 ,
int V_245 , struct V_1 * V_216 , int V_246 ,
T_2 V_182 , T_3 V_247 )
{
const struct V_110 * V_130 = F_11 ( V_7 ) ;
struct V_110 * V_248 ;
struct V_6 * V_249 ;
struct V_39 V_40 ;
struct V_21 * V_21 = V_3 ? F_17 ( V_3 ) : F_52 ( F_3 ( V_7 ) -> V_131 ) ;
struct V_2 * V_250 = V_21 -> V_251 . F_16 ;
unsigned int V_252 = sizeof( struct V_110 ) ;
struct V_8 * V_9 ;
T_3 * V_253 ;
if ( V_244 )
V_252 += V_254 ;
#ifdef F_29
if ( V_216 )
V_252 += V_255 ;
#endif
V_249 = F_118 ( V_256 + sizeof( struct V_111 ) + V_252 ,
V_257 ) ;
if ( ! V_249 )
return;
F_119 ( V_249 , V_256 + sizeof( struct V_111 ) + V_252 ) ;
V_248 = F_120 ( V_249 , V_252 ) ;
F_121 ( V_249 ) ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_19 = V_130 -> V_20 ;
V_248 -> V_20 = V_130 -> V_19 ;
V_248 -> V_220 = V_252 / 4 ;
V_248 -> V_134 = F_24 ( V_134 ) ;
V_248 -> V_258 = F_24 ( V_241 ) ;
V_248 -> V_241 = ! V_246 || ! V_130 -> V_241 ;
V_248 -> V_246 = V_246 ;
V_248 -> V_259 = F_122 ( V_242 ) ;
V_253 = ( T_3 * ) ( V_248 + 1 ) ;
if ( V_244 ) {
* V_253 ++ = F_24 ( ( V_260 << 24 ) | ( V_260 << 16 ) |
( V_261 << 8 ) | V_262 ) ;
* V_253 ++ = F_24 ( V_243 ) ;
* V_253 ++ = F_24 ( V_244 ) ;
}
#ifdef F_29
if ( V_216 ) {
* V_253 ++ = F_24 ( ( V_260 << 24 ) | ( V_260 << 16 ) |
( V_263 << 8 ) | V_264 ) ;
F_99 ( ( T_6 * ) V_253 , V_216 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , V_248 ) ;
}
#endif
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_16 = F_10 ( V_7 ) -> V_18 ;
V_40 . V_18 = F_10 ( V_7 ) -> V_16 ;
V_40 . V_52 = V_247 ;
V_249 -> V_265 = V_266 ;
V_249 -> V_267 = 0 ;
F_79 ( V_249 , & V_40 . V_18 , & V_40 . V_16 ) ;
V_40 . V_92 = V_93 ;
if ( F_123 ( & V_40 . V_16 ) && ! V_245 )
V_40 . V_94 = F_112 ( V_7 ) ;
else {
if ( ! V_245 && F_124 ( V_21 , V_7 -> V_14 ) )
V_245 = V_7 -> V_14 ;
V_40 . V_94 = V_245 ;
}
V_40 . V_95 = F_125 ( V_21 , V_7 -> V_268 ) ;
V_40 . V_97 = V_248 -> V_19 ;
V_40 . V_98 = V_248 -> V_20 ;
V_40 . V_100 = F_126 ( V_21 , V_3 && F_127 ( V_3 ) ? V_3 : NULL ) ;
F_128 ( V_7 , F_35 ( & V_40 ) ) ;
V_9 = F_36 ( V_250 , & V_40 , NULL ) ;
if ( ! F_37 ( V_9 ) ) {
F_129 ( V_249 , V_9 ) ;
F_82 ( V_250 , V_249 , & V_40 , V_40 . V_95 , NULL , V_182 ) ;
F_130 ( V_21 , V_269 ) ;
if ( V_246 )
F_130 ( V_21 , V_270 ) ;
return;
}
F_87 ( V_249 ) ;
}
static void F_131 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_110 * V_130 = F_11 ( V_7 ) ;
T_1 V_134 = 0 , V_258 = 0 ;
struct V_1 * V_216 = NULL ;
#ifdef F_29
const T_6 * V_222 = NULL ;
struct V_111 * V_271 = F_10 ( V_7 ) ;
unsigned char V_225 [ 16 ] ;
int V_224 ;
struct V_2 * V_272 = NULL ;
#endif
int V_245 ;
if ( V_130 -> V_246 )
return;
if ( ! V_3 && ! F_132 ( V_7 ) )
return;
#ifdef F_29
F_80 () ;
V_222 = F_108 ( V_130 ) ;
if ( V_3 && F_127 ( V_3 ) ) {
V_216 = F_1 ( V_3 , & V_271 -> V_18 ) ;
} else if ( V_222 ) {
V_272 = F_133 ( F_52 ( F_3 ( V_7 ) -> V_131 ) ,
& V_137 , NULL , 0 ,
& V_271 -> V_18 ,
V_130 -> V_20 , & V_271 -> V_16 ,
F_54 ( V_130 -> V_20 ) , F_112 ( V_7 ) ,
F_134 ( V_7 ) ) ;
if ( ! V_272 )
goto V_144;
V_216 = F_1 ( V_272 , & V_271 -> V_18 ) ;
if ( ! V_216 )
goto V_144;
V_224 = F_105 ( V_225 , V_216 , NULL , V_7 ) ;
if ( V_224 || memcmp ( V_222 , V_225 , 16 ) != 0 )
goto V_144;
}
#endif
if ( V_130 -> V_241 )
V_134 = F_60 ( V_130 -> V_258 ) ;
else
V_258 = F_60 ( V_130 -> V_134 ) + V_130 -> V_273 + V_130 -> V_274 + V_7 -> V_212 -
( V_130 -> V_220 << 2 ) ;
V_245 = V_3 ? V_3 -> V_65 : 0 ;
F_117 ( V_3 , V_7 , V_134 , V_258 , 0 , 0 , 0 , V_245 , V_216 , 1 , 0 , 0 ) ;
#ifdef F_29
V_144:
F_83 () ;
#endif
}
static void F_135 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_134 ,
T_1 V_241 , T_1 V_242 , T_1 V_243 , T_1 V_244 , int V_245 ,
struct V_1 * V_216 , T_2 V_182 ,
T_3 V_247 )
{
F_117 ( V_3 , V_7 , V_134 , V_241 , V_242 , V_243 , V_244 , V_245 , V_216 , 0 ,
V_182 , V_247 ) ;
}
static void F_136 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_275 * V_276 = F_59 ( V_3 ) ;
struct V_277 * V_278 = F_137 ( V_3 ) ;
F_135 ( V_3 , V_7 , V_278 -> V_279 , V_278 -> V_280 ,
V_278 -> V_281 >> V_276 -> V_282 ,
F_138 () + V_278 -> V_283 ,
V_278 -> V_284 , V_276 -> V_285 , F_139 ( V_278 ) ,
V_276 -> V_286 , F_95 ( V_276 -> V_287 ) ) ;
F_58 ( V_276 ) ;
}
static void F_140 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_132 * V_166 )
{
F_135 ( V_3 , V_7 , ( V_3 -> V_119 == V_150 ) ?
F_66 ( V_166 ) -> V_149 + 1 : F_16 ( V_3 ) -> V_151 ,
F_66 ( V_166 ) -> V_288 ,
V_166 -> V_289 >> F_76 ( V_166 ) -> V_290 ,
F_138 () + F_66 ( V_166 ) -> V_291 ,
V_166 -> V_69 , V_3 -> V_65 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_141 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_142
const struct V_110 * V_130 = F_11 ( V_7 ) ;
if ( ! V_130 -> V_273 )
V_3 = F_143 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_144 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_211 == F_122 ( V_292 ) )
return F_145 ( V_3 , V_7 ) ;
if ( ! F_132 ( V_7 ) )
goto V_293;
return F_146 ( & V_294 ,
& V_295 , V_3 , V_7 ) ;
V_293:
F_147 ( V_3 ) ;
return 0 ;
}
static void F_148 ( struct V_6 * V_7 )
{
memmove ( F_149 ( V_7 ) , & F_113 ( V_7 ) -> V_232 . V_233 ,
sizeof( struct V_124 ) ) ;
}
static struct V_2 * F_150 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_132 * V_166 ,
struct V_8 * V_9 ,
struct V_132 * V_296 ,
bool * V_297 )
{
struct V_171 * V_172 ;
struct V_31 * V_298 ;
const struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_37 * V_38 ;
struct V_299 * V_300 ;
struct V_27 * V_301 ;
struct V_33 * V_302 ;
struct V_2 * V_303 ;
#ifdef F_29
struct V_1 * V_216 ;
#endif
struct V_39 V_40 ;
if ( V_7 -> V_211 == F_122 ( V_292 ) ) {
V_303 = F_151 ( V_3 , V_7 , V_166 , V_9 ,
V_296 , V_297 ) ;
if ( ! V_303 )
return NULL ;
V_300 = (struct V_299 * ) V_303 ;
F_5 ( V_303 ) -> V_304 = & V_300 -> V_305 ;
V_301 = F_5 ( V_303 ) ;
V_298 = F_6 ( V_303 ) ;
V_302 = F_16 ( V_303 ) ;
memcpy ( V_298 , V_32 , sizeof( struct V_31 ) ) ;
V_298 -> V_18 = V_303 -> V_58 ;
F_15 ( V_303 ) -> V_82 = & V_83 ;
V_303 -> V_84 = V_85 ;
#ifdef F_29
V_302 -> V_86 = & V_87 ;
#endif
V_298 -> V_306 = NULL ;
V_298 -> V_307 = NULL ;
V_298 -> V_308 = NULL ;
V_298 -> V_309 = NULL ;
V_298 -> V_38 = NULL ;
V_298 -> V_310 = F_112 ( V_7 ) ;
V_298 -> V_311 = F_10 ( V_7 ) -> V_145 ;
V_298 -> V_312 = F_152 ( F_10 ( V_7 ) ) ;
if ( V_32 -> V_179 )
V_298 -> V_71 = V_56 ( F_10 ( V_7 ) ) ;
F_49 ( V_303 , F_15 ( V_303 ) -> V_123 ) ;
return V_303 ;
}
V_172 = F_76 ( V_166 ) ;
if ( F_153 ( V_3 ) )
goto V_313;
if ( ! V_9 ) {
V_9 = F_77 ( V_3 , & V_40 , V_166 , V_93 ) ;
if ( ! V_9 )
goto V_144;
}
V_303 = F_154 ( V_3 , V_166 , V_7 ) ;
if ( ! V_303 )
goto V_314;
V_303 -> V_104 = V_105 ;
F_39 ( V_303 , V_9 , NULL , NULL ) ;
F_2 ( V_303 , V_7 ) ;
V_300 = (struct V_299 * ) V_303 ;
F_5 ( V_303 ) -> V_304 = & V_300 -> V_305 ;
V_302 = F_16 ( V_303 ) ;
V_301 = F_5 ( V_303 ) ;
V_298 = F_6 ( V_303 ) ;
memcpy ( V_298 , V_32 , sizeof( struct V_31 ) ) ;
V_303 -> V_68 = V_172 -> V_178 ;
V_298 -> V_18 = V_172 -> V_177 ;
V_303 -> V_58 = V_172 -> V_177 ;
V_303 -> V_65 = V_172 -> V_230 ;
V_301 -> V_315 = NULL ;
V_298 -> V_306 = NULL ;
V_298 -> V_307 = NULL ;
V_298 -> V_308 = NULL ;
V_298 -> V_234 . V_316 = V_32 -> V_234 . V_316 ;
V_298 -> V_309 = NULL ;
V_298 -> V_38 = NULL ;
V_298 -> V_310 = F_112 ( V_7 ) ;
V_298 -> V_311 = F_10 ( V_7 ) -> V_145 ;
V_298 -> V_312 = F_152 ( F_10 ( V_7 ) ) ;
if ( V_32 -> V_179 )
V_298 -> V_71 = V_56 ( F_10 ( V_7 ) ) ;
V_38 = V_172 -> V_181 ;
if ( ! V_38 )
V_38 = F_81 ( V_32 -> V_38 ) ;
if ( V_38 ) {
V_38 = F_155 ( V_303 , V_38 ) ;
F_156 ( V_298 -> V_38 , V_38 ) ;
}
F_15 ( V_303 ) -> V_74 = 0 ;
if ( V_38 )
F_15 ( V_303 ) -> V_74 = V_38 -> V_107 +
V_38 -> V_106 ;
F_157 ( V_303 , V_9 ) ;
F_49 ( V_303 , F_48 ( V_9 ) ) ;
V_302 -> V_317 = F_158 ( F_16 ( V_3 ) , F_159 ( V_9 ) ) ;
F_160 ( V_303 ) ;
V_301 -> V_318 = V_301 -> V_319 = V_103 ;
V_301 -> V_102 = V_103 ;
#ifdef F_29
V_216 = F_1 ( V_3 , & V_303 -> V_68 ) ;
if ( V_216 ) {
F_93 ( V_303 , (union V_183 * ) & V_303 -> V_68 ,
V_49 , 128 , V_216 -> V_216 , V_216 -> V_320 ,
F_161 ( V_3 , V_257 ) ) ;
}
#endif
if ( F_162 ( V_3 , V_303 ) < 0 ) {
F_163 ( V_303 ) ;
F_72 ( V_303 ) ;
goto V_144;
}
* V_297 = F_164 ( V_303 , F_165 ( V_296 ) ) ;
if ( * V_297 ) {
F_166 ( V_302 , V_166 ) ;
if ( V_172 -> V_180 ) {
V_298 -> V_309 = F_167 ( V_172 -> V_180 ,
F_161 ( V_3 , V_257 ) ) ;
F_168 ( V_172 -> V_180 ) ;
V_172 -> V_180 = NULL ;
if ( V_298 -> V_309 ) {
F_148 ( V_298 -> V_309 ) ;
F_169 ( V_298 -> V_309 , V_303 ) ;
}
}
}
return V_303 ;
V_313:
F_65 ( F_17 ( V_3 ) , V_321 ) ;
V_314:
F_170 ( V_9 ) ;
V_144:
F_147 ( V_3 ) ;
return NULL ;
}
static int V_89 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_33 * V_34 ;
struct V_6 * V_322 = NULL ;
if ( V_7 -> V_211 == F_122 ( V_292 ) )
return V_85 ( V_3 , V_7 ) ;
if ( V_32 -> V_234 . V_316 )
V_322 = F_167 ( V_7 , F_161 ( V_3 , V_257 ) ) ;
if ( V_3 -> V_119 == V_323 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_171 ( V_3 , V_7 ) ;
F_172 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_155 -> V_213 ( V_9 , V_32 -> V_15 ) == NULL ) {
F_170 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_173 ( V_3 , V_7 , F_11 ( V_7 ) ) ;
if ( V_322 )
goto V_324;
return 0 ;
}
if ( F_174 ( V_7 ) )
goto V_325;
if ( V_3 -> V_119 == V_150 ) {
struct V_2 * V_326 = F_141 ( V_3 , V_7 ) ;
if ( ! V_326 )
goto V_327;
if ( V_326 != V_3 ) {
if ( F_175 ( V_3 , V_326 , V_7 ) )
goto V_328;
if ( V_322 )
F_176 ( V_322 ) ;
return 0 ;
}
} else
F_171 ( V_3 , V_7 ) ;
if ( F_177 ( V_3 , V_7 ) )
goto V_328;
if ( V_322 )
goto V_324;
return 0 ;
V_328:
F_131 ( V_3 , V_7 ) ;
V_327:
if ( V_322 )
F_176 ( V_322 ) ;
F_87 ( V_7 ) ;
return 0 ;
V_325:
F_130 ( F_17 ( V_3 ) , V_329 ) ;
F_130 ( F_17 ( V_3 ) , V_330 ) ;
goto V_327;
V_324:
V_34 = F_16 ( V_3 ) ;
if ( F_113 ( V_322 ) -> V_331 == V_34 -> V_288 &&
! ( ( 1 << V_3 -> V_119 ) & ( V_121 | V_120 ) ) ) {
if ( V_32 -> V_234 . V_235 . V_236 || V_32 -> V_234 . V_235 . V_237 )
V_32 -> V_310 = F_112 ( V_322 ) ;
if ( V_32 -> V_234 . V_235 . V_238 || V_32 -> V_234 . V_235 . V_239 )
V_32 -> V_311 = F_10 ( V_322 ) -> V_145 ;
if ( V_32 -> V_234 . V_235 . V_332 || V_32 -> V_234 . V_235 . V_333 )
V_32 -> V_312 = F_152 ( F_10 ( V_322 ) ) ;
if ( V_32 -> V_179 )
V_32 -> V_71 = V_56 ( F_10 ( V_322 ) ) ;
if ( F_114 ( V_3 , V_322 , & F_113 ( V_322 ) -> V_232 . V_233 ) ) {
F_169 ( V_322 , V_3 ) ;
F_148 ( V_322 ) ;
V_322 = F_178 ( & V_32 -> V_309 , V_322 ) ;
} else {
F_176 ( V_322 ) ;
V_322 = F_178 ( & V_32 -> V_309 , NULL ) ;
}
}
F_87 ( V_322 ) ;
return 0 ;
}
static void F_179 ( struct V_6 * V_7 , const struct V_111 * V_128 ,
const struct V_110 * V_130 )
{
memmove ( & F_113 ( V_7 ) -> V_232 . V_233 , F_149 ( V_7 ) ,
sizeof( struct V_124 ) ) ;
F_180 () ;
F_113 ( V_7 ) -> V_134 = F_60 ( V_130 -> V_134 ) ;
F_113 ( V_7 ) -> V_331 = ( F_113 ( V_7 ) -> V_134 + V_130 -> V_273 + V_130 -> V_274 +
V_7 -> V_212 - V_130 -> V_220 * 4 ) ;
F_113 ( V_7 ) -> V_258 = F_60 ( V_130 -> V_258 ) ;
F_113 ( V_7 ) -> V_334 = F_181 ( V_130 ) ;
F_113 ( V_7 ) -> V_231 = 0 ;
F_113 ( V_7 ) -> V_335 = F_182 ( V_128 ) ;
F_113 ( V_7 ) -> V_336 = 0 ;
F_113 ( V_7 ) -> V_337 =
V_7 -> V_338 || F_183 ( V_7 ) -> V_339 ;
}
static int F_184 ( struct V_6 * V_7 )
{
int V_340 = F_55 ( V_7 ) ;
const struct V_110 * V_130 ;
const struct V_111 * V_128 ;
bool V_341 ;
struct V_2 * V_3 ;
int V_342 ;
struct V_21 * V_21 = F_52 ( V_7 -> V_131 ) ;
if ( V_7 -> V_343 != V_344 )
goto V_345;
F_185 ( V_21 , V_346 ) ;
if ( ! F_186 ( V_7 , sizeof( struct V_110 ) ) )
goto V_345;
V_130 = ( const struct V_110 * ) V_7 -> V_129 ;
if ( F_187 ( V_130 -> V_220 < sizeof( struct V_110 ) / 4 ) )
goto V_347;
if ( ! F_186 ( V_7 , V_130 -> V_220 * 4 ) )
goto V_345;
if ( F_188 ( V_7 , V_93 , V_348 ) )
goto V_349;
V_130 = ( const struct V_110 * ) V_7 -> V_129 ;
V_128 = F_10 ( V_7 ) ;
V_350:
V_3 = F_189 ( & V_137 , V_7 , F_190 ( V_130 ) ,
V_130 -> V_20 , V_130 -> V_19 , F_191 ( V_7 ) , V_340 ,
& V_341 ) ;
if ( ! V_3 )
goto V_351;
V_352:
if ( V_3 -> V_119 == V_140 )
goto V_353;
if ( V_3 -> V_119 == V_141 ) {
struct V_132 * V_166 = F_192 ( V_3 ) ;
struct V_2 * V_326 ;
V_3 = V_166 -> V_354 ;
F_179 ( V_7 , V_128 , V_130 ) ;
if ( F_107 ( V_3 , V_7 ) ) {
F_193 ( V_3 , V_7 ) ;
F_194 ( V_166 ) ;
goto V_345;
}
if ( F_187 ( V_3 -> V_119 != V_150 ) ) {
F_195 ( V_3 , V_166 ) ;
goto V_350;
}
F_71 ( V_3 ) ;
V_341 = true ;
V_326 = NULL ;
if ( ! F_196 ( V_3 , V_7 ) )
V_326 = F_197 ( V_3 , V_7 , V_166 , false ) ;
if ( ! V_326 ) {
F_194 ( V_166 ) ;
goto V_355;
}
if ( V_326 == V_3 ) {
F_194 ( V_166 ) ;
F_148 ( V_7 ) ;
} else if ( F_175 ( V_3 , V_326 , V_7 ) ) {
F_131 ( V_326 , V_7 ) ;
goto V_355;
} else {
F_74 ( V_3 ) ;
return 0 ;
}
}
if ( V_128 -> V_145 < F_6 ( V_3 ) -> V_146 ) {
F_65 ( V_21 , V_147 ) ;
goto V_355;
}
if ( ! F_198 ( V_3 , V_356 , V_7 ) )
goto V_355;
F_179 ( V_7 , V_128 , V_130 ) ;
if ( F_107 ( V_3 , V_7 ) )
goto V_355;
if ( F_196 ( V_3 , V_7 ) )
goto V_355;
V_130 = ( const struct V_110 * ) V_7 -> V_129 ;
V_128 = F_10 ( V_7 ) ;
V_7 -> V_131 = NULL ;
if ( V_3 -> V_119 == V_150 ) {
V_342 = V_89 ( V_3 , V_7 ) ;
goto V_357;
}
F_199 ( V_3 ) ;
F_200 ( V_3 ) ;
F_201 ( F_16 ( V_3 ) , V_7 ) ;
V_342 = 0 ;
if ( ! F_64 ( V_3 ) ) {
V_342 = V_89 ( V_3 , V_7 ) ;
} else if ( F_202 ( V_3 , V_7 ) ) {
goto V_355;
}
F_73 ( V_3 ) ;
V_357:
if ( V_341 )
F_74 ( V_3 ) ;
return V_342 ? - 1 : 0 ;
V_351:
if ( ! F_198 ( NULL , V_356 , V_7 ) )
goto V_345;
F_179 ( V_7 , V_128 , V_130 ) ;
if ( F_174 ( V_7 ) ) {
V_349:
F_185 ( V_21 , V_329 ) ;
V_347:
F_185 ( V_21 , V_330 ) ;
} else {
F_131 ( NULL , V_7 ) ;
}
V_345:
F_87 ( V_7 ) ;
return 0 ;
V_355:
F_193 ( V_3 , V_7 ) ;
if ( V_341 )
F_74 ( V_3 ) ;
goto V_345;
V_353:
if ( ! F_198 ( NULL , V_356 , V_7 ) ) {
F_58 ( F_59 ( V_3 ) ) ;
goto V_345;
}
F_179 ( V_7 , V_128 , V_130 ) ;
if ( F_174 ( V_7 ) ) {
F_58 ( F_59 ( V_3 ) ) ;
goto V_349;
}
switch ( F_203 ( F_59 ( V_3 ) , V_7 , V_130 ) ) {
case V_358 :
{
struct V_2 * V_359 ;
V_359 = F_133 ( F_52 ( V_7 -> V_131 ) , & V_137 ,
V_7 , F_190 ( V_130 ) ,
& F_10 ( V_7 ) -> V_18 , V_130 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_54 ( V_130 -> V_19 ) , F_112 ( V_7 ) ,
V_340 ) ;
if ( V_359 ) {
struct V_275 * V_276 = F_59 ( V_3 ) ;
F_204 ( V_276 ) ;
V_3 = V_359 ;
F_148 ( V_7 ) ;
V_341 = false ;
goto V_352;
}
}
case V_360 :
F_136 ( V_3 , V_7 ) ;
break;
case V_361 :
F_148 ( V_7 ) ;
F_131 ( V_3 , V_7 ) ;
F_204 ( F_59 ( V_3 ) ) ;
goto V_345;
case V_362 :
;
}
goto V_345;
}
static void F_205 ( struct V_6 * V_7 )
{
const struct V_111 * V_128 ;
const struct V_110 * V_130 ;
struct V_2 * V_3 ;
if ( V_7 -> V_343 != V_344 )
return;
if ( ! F_186 ( V_7 , F_206 ( V_7 ) + sizeof( struct V_110 ) ) )
return;
V_128 = F_10 ( V_7 ) ;
V_130 = F_11 ( V_7 ) ;
if ( V_130 -> V_220 < sizeof( struct V_110 ) / 4 )
return;
V_3 = F_53 ( F_52 ( V_7 -> V_131 ) , & V_137 ,
& V_128 -> V_18 , V_130 -> V_20 ,
& V_128 -> V_16 , F_54 ( V_130 -> V_19 ) ,
F_191 ( V_7 ) , F_55 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_363 = V_364 ;
if ( F_127 ( V_3 ) ) {
struct V_8 * V_9 = F_207 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_208 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_209 ( V_7 , V_9 ) ;
}
}
}
static int F_210 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = F_15 ( V_3 ) ;
F_211 ( V_3 ) ;
V_30 -> V_82 = & V_88 ;
#ifdef F_29
F_16 ( V_3 ) -> V_86 = & V_90 ;
#endif
return 0 ;
}
static void F_212 ( struct V_2 * V_3 )
{
F_213 ( V_3 ) ;
F_214 ( V_3 ) ;
}
static void F_215 ( struct V_365 * V_134 ,
const struct V_132 * V_166 , int V_366 )
{
long V_367 = V_166 -> V_368 . V_369 - V_370 ;
const struct V_4 * V_371 = & F_76 ( V_166 ) -> V_177 ;
const struct V_4 * V_19 = & F_76 ( V_166 ) -> V_178 ;
if ( V_367 < 0 )
V_367 = 0 ;
F_216 ( V_134 ,
L_5
L_6 ,
V_366 ,
V_371 -> V_17 [ 0 ] , V_371 -> V_17 [ 1 ] ,
V_371 -> V_17 [ 2 ] , V_371 -> V_17 [ 3 ] ,
F_76 ( V_166 ) -> V_372 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_54 ( F_76 ( V_166 ) -> V_373 ) ,
V_159 ,
0 , 0 ,
1 ,
F_217 ( V_367 ) ,
V_166 -> V_374 ,
F_218 ( F_219 ( V_134 ) ,
F_220 ( V_166 -> V_354 ) ) ,
0 ,
0 ,
0 , V_166 ) ;
}
static void F_221 ( struct V_365 * V_134 , struct V_2 * V_375 , int V_366 )
{
const struct V_4 * V_19 , * V_371 ;
T_7 V_376 , V_377 ;
int V_378 ;
unsigned long V_379 ;
const struct V_27 * V_28 = F_5 ( V_375 ) ;
const struct V_33 * V_34 = F_16 ( V_375 ) ;
const struct V_29 * V_30 = F_15 ( V_375 ) ;
const struct V_380 * V_381 = & V_30 -> V_382 . V_381 ;
int V_383 ;
int V_384 ;
V_19 = & V_375 -> V_68 ;
V_371 = & V_375 -> V_58 ;
V_376 = F_54 ( V_28 -> V_112 ) ;
V_377 = F_54 ( V_28 -> V_99 ) ;
if ( V_30 -> V_385 == V_386 ||
V_30 -> V_385 == V_387 ||
V_30 -> V_385 == V_388 ) {
V_378 = 1 ;
V_379 = V_30 -> V_389 ;
} else if ( V_30 -> V_385 == V_390 ) {
V_378 = 4 ;
V_379 = V_30 -> V_389 ;
} else if ( F_222 ( & V_375 -> V_391 ) ) {
V_378 = 2 ;
V_379 = V_375 -> V_391 . V_369 ;
} else {
V_378 = 0 ;
V_379 = V_370 ;
}
V_384 = F_223 ( V_375 ) ;
if ( V_384 == V_150 )
V_383 = V_375 -> V_392 ;
else
V_383 = F_224 ( int , V_34 -> V_288 - V_34 -> V_393 , 0 ) ;
F_216 ( V_134 ,
L_5
L_7 ,
V_366 ,
V_371 -> V_17 [ 0 ] , V_371 -> V_17 [ 1 ] ,
V_371 -> V_17 [ 2 ] , V_371 -> V_17 [ 3 ] , V_377 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_376 ,
V_384 ,
V_34 -> V_70 - V_34 -> V_135 ,
V_383 ,
V_378 ,
F_225 ( V_379 - V_370 ) ,
V_30 -> V_394 ,
F_218 ( F_219 ( V_134 ) , F_220 ( V_375 ) ) ,
V_30 -> V_395 ,
F_226 ( V_375 ) ,
F_227 ( & V_375 -> V_396 ) , V_375 ,
F_217 ( V_30 -> V_397 ) ,
F_217 ( V_30 -> V_398 . V_399 ) ,
( V_30 -> V_398 . V_400 << 1 ) | V_30 -> V_398 . V_401 ,
V_34 -> V_402 ,
V_384 == V_150 ?
V_381 -> V_403 :
( F_228 ( V_34 ) ? - 1 : V_34 -> V_404 )
) ;
}
static void F_229 ( struct V_365 * V_134 ,
struct V_275 * V_276 , int V_366 )
{
long V_405 = V_276 -> V_406 . V_369 - V_370 ;
const struct V_4 * V_19 , * V_371 ;
T_7 V_376 , V_377 ;
V_19 = & V_276 -> V_407 ;
V_371 = & V_276 -> V_408 ;
V_376 = F_54 ( V_276 -> V_409 ) ;
V_377 = F_54 ( V_276 -> V_410 ) ;
F_216 ( V_134 ,
L_5
L_8 ,
V_366 ,
V_371 -> V_17 [ 0 ] , V_371 -> V_17 [ 1 ] ,
V_371 -> V_17 [ 2 ] , V_371 -> V_17 [ 3 ] , V_377 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_376 ,
V_276 -> V_411 , 0 , 0 ,
3 , F_225 ( V_405 ) , 0 , 0 , 0 , 0 ,
F_227 ( & V_276 -> V_412 ) , V_276 ) ;
}
static int F_230 ( struct V_365 * V_134 , void * V_413 )
{
struct V_414 * V_415 ;
struct V_2 * V_3 = V_413 ;
if ( V_413 == V_416 ) {
F_231 ( V_134 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_144;
}
V_415 = V_134 -> V_417 ;
if ( V_3 -> V_119 == V_140 )
F_229 ( V_134 , V_413 , V_415 -> V_418 ) ;
else if ( V_3 -> V_119 == V_141 )
F_215 ( V_134 , V_413 , V_415 -> V_418 ) ;
else
F_221 ( V_134 , V_413 , V_415 -> V_418 ) ;
V_144:
return 0 ;
}
int T_8 F_232 ( struct V_21 * V_21 )
{
return F_233 ( V_21 , & V_419 ) ;
}
void F_234 ( struct V_21 * V_21 )
{
F_235 ( V_21 , & V_419 ) ;
}
static int T_8 F_236 ( struct V_21 * V_21 )
{
return F_237 ( & V_21 -> V_251 . F_16 , V_420 ,
V_421 , V_93 , V_21 ) ;
}
static void T_9 F_238 ( struct V_21 * V_21 )
{
F_239 ( V_21 -> V_251 . F_16 ) ;
}
static void T_9 F_240 ( struct V_422 * V_423 )
{
F_241 ( & V_137 , V_49 ) ;
}
int T_10 F_242 ( void )
{
int V_342 ;
V_342 = F_243 ( & V_424 , V_93 ) ;
if ( V_342 )
goto V_144;
V_342 = F_244 ( & V_425 ) ;
if ( V_342 )
goto V_426;
V_342 = F_245 ( & V_427 ) ;
if ( V_342 )
goto V_428;
V_144:
return V_342 ;
V_428:
F_246 ( & V_425 ) ;
V_426:
F_247 ( & V_424 , V_93 ) ;
goto V_144;
}
void F_248 ( void )
{
F_249 ( & V_427 ) ;
F_246 ( & V_425 ) ;
F_247 ( & V_424 , V_93 ) ;
}
