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
static T_1 F_8 ( const struct V_6 * V_7 , T_1 * V_16 )
{
return F_9 ( F_10 ( V_7 ) -> V_17 . V_18 ,
F_10 ( V_7 ) -> V_19 . V_18 ,
F_11 ( V_7 ) -> V_20 ,
F_11 ( V_7 ) -> V_21 , V_16 ) ;
}
static int F_12 ( struct V_2 * V_3 , struct V_22 * V_23 ,
int V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
struct V_27 * V_28 = F_5 ( V_3 ) ;
struct V_29 * V_30 = F_13 ( V_3 ) ;
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_33 * V_34 = F_14 ( V_3 ) ;
struct V_4 * V_19 = NULL , * V_35 , V_36 ;
struct V_37 * V_38 ;
struct V_39 V_40 ;
struct V_8 * V_9 ;
int V_41 ;
int V_42 ;
if ( V_24 < V_43 )
return - V_44 ;
if ( V_26 -> V_45 != V_46 )
return - V_47 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_32 -> V_48 ) {
V_40 . V_49 = V_26 -> V_50 & V_51 ;
F_15 ( V_40 . V_49 ) ;
if ( V_40 . V_49 & V_52 ) {
struct V_53 * V_49 ;
V_49 = F_16 ( V_3 , V_40 . V_49 ) ;
if ( ! V_49 )
return - V_44 ;
F_17 ( V_49 ) ;
}
}
if ( F_18 ( & V_26 -> V_54 ) ) {
if ( F_19 ( & V_3 -> V_55 ) )
F_20 ( F_21 ( V_56 ) ,
& V_26 -> V_54 ) ;
else
V_26 -> V_54 = V_57 ;
}
V_41 = F_22 ( & V_26 -> V_54 ) ;
if ( V_41 & V_58 )
return - V_59 ;
if ( V_41 & V_60 ) {
if ( V_24 >= sizeof( struct V_25 ) &&
V_26 -> V_61 ) {
if ( V_3 -> V_62 &&
V_3 -> V_62 != V_26 -> V_61 )
return - V_44 ;
V_3 -> V_62 = V_26 -> V_61 ;
}
if ( ! V_3 -> V_62 )
return - V_44 ;
}
if ( V_34 -> V_63 . V_64 &&
! F_23 ( & V_3 -> V_65 , & V_26 -> V_54 ) ) {
V_34 -> V_63 . V_66 = 0 ;
V_34 -> V_63 . V_64 = 0 ;
V_34 -> V_67 = 0 ;
}
V_3 -> V_65 = V_26 -> V_54 ;
V_32 -> V_68 = V_40 . V_49 ;
if ( V_41 & V_69 ) {
T_1 V_70 = V_30 -> V_71 ;
struct V_72 sin ;
F_24 ( V_3 , L_1 ) ;
if ( F_25 ( V_3 ) )
return - V_59 ;
sin . V_73 = V_74 ;
sin . V_75 = V_26 -> V_76 ;
sin . V_77 . V_78 = V_26 -> V_54 . V_18 [ 3 ] ;
V_30 -> V_79 = & V_80 ;
V_3 -> V_81 = V_82 ;
#ifdef F_26
V_34 -> V_83 = & V_84 ;
#endif
V_42 = F_27 ( V_3 , (struct V_22 * ) & sin , sizeof( sin ) ) ;
if ( V_42 ) {
V_30 -> V_71 = V_70 ;
V_30 -> V_79 = & V_85 ;
V_3 -> V_81 = V_86 ;
#ifdef F_26
V_34 -> V_83 = & V_87 ;
#endif
goto V_88;
}
V_32 -> V_19 = V_3 -> V_55 ;
return V_42 ;
}
if ( ! F_18 ( & V_3 -> V_55 ) )
V_19 = & V_3 -> V_55 ;
V_40 . V_89 = V_90 ;
V_40 . V_17 = V_3 -> V_65 ;
V_40 . V_19 = V_19 ? * V_19 : V_32 -> V_19 ;
V_40 . V_91 = V_3 -> V_62 ;
V_40 . V_92 = V_3 -> V_93 ;
V_40 . V_94 = V_26 -> V_76 ;
V_40 . V_95 = V_28 -> V_96 ;
V_40 . V_97 = V_3 -> V_98 ;
V_38 = F_28 ( V_32 -> V_38 , F_29 ( V_3 ) ) ;
V_35 = F_30 ( & V_40 , V_38 , & V_36 ) ;
F_31 ( V_3 , F_32 ( & V_40 ) ) ;
V_9 = F_33 ( V_3 , & V_40 , V_35 ) ;
if ( F_34 ( V_9 ) ) {
V_42 = F_35 ( V_9 ) ;
goto V_88;
}
if ( ! V_19 ) {
V_19 = & V_40 . V_19 ;
V_3 -> V_55 = * V_19 ;
}
V_32 -> V_19 = * V_19 ;
V_28 -> V_99 = V_100 ;
V_3 -> V_101 = V_102 ;
F_36 ( V_3 , V_9 , NULL , NULL ) ;
if ( V_103 . V_104 &&
! V_34 -> V_63 . V_64 &&
F_23 ( & V_40 . V_17 , & V_3 -> V_65 ) )
F_37 ( V_3 , V_9 ) ;
V_30 -> V_71 = 0 ;
if ( V_38 )
V_30 -> V_71 = V_38 -> V_105 +
V_38 -> V_106 ;
V_34 -> V_63 . V_107 = V_108 - sizeof( struct V_109 ) - sizeof( struct V_110 ) ;
V_28 -> V_111 = V_26 -> V_76 ;
F_38 ( V_3 , V_112 ) ;
V_42 = F_39 ( & V_103 , V_3 ) ;
if ( V_42 )
goto V_113;
F_40 ( V_3 ) ;
if ( ! V_34 -> V_67 && F_41 ( ! V_34 -> V_114 ) )
V_34 -> V_67 = F_9 ( V_32 -> V_19 . V_18 ,
V_3 -> V_65 . V_18 ,
V_28 -> V_96 ,
V_28 -> V_111 ,
& V_34 -> V_115 ) ;
V_42 = F_42 ( V_3 ) ;
if ( V_42 )
goto V_113;
return 0 ;
V_113:
F_38 ( V_3 , V_116 ) ;
F_43 ( V_3 ) ;
V_88:
V_28 -> V_111 = 0 ;
V_3 -> V_117 = 0 ;
return V_42 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_118 ) & ( V_119 | V_120 ) )
return;
V_9 = F_45 ( V_3 , F_14 ( V_3 ) -> V_121 ) ;
if ( ! V_9 )
return;
if ( F_13 ( V_3 ) -> V_122 > F_46 ( V_9 ) ) {
F_47 ( V_3 , F_46 ( V_9 ) ) ;
F_48 ( V_3 ) ;
}
}
static void F_49 ( struct V_6 * V_7 , struct V_123 * V_38 ,
T_2 type , T_2 V_124 , int V_125 , T_3 V_126 )
{
const struct V_110 * V_127 = ( const struct V_110 * ) V_7 -> V_128 ;
const struct V_109 * V_129 = (struct V_109 * ) ( V_7 -> V_128 + V_125 ) ;
struct V_130 * V_130 = F_50 ( V_7 -> V_131 ) ;
struct V_132 * V_133 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_4 V_134 , V_135 ;
struct V_2 * V_3 ;
bool V_136 ;
int V_42 ;
V_3 = F_51 ( V_130 , & V_137 ,
& V_127 -> V_17 , V_129 -> V_20 ,
& V_127 -> V_19 , F_52 ( V_129 -> V_21 ) ,
V_7 -> V_131 -> V_138 ) ;
if ( ! V_3 ) {
F_53 ( V_130 , F_54 ( V_7 -> V_131 ) ,
V_139 ) ;
return;
}
if ( V_3 -> V_118 == V_140 ) {
F_55 ( F_56 ( V_3 ) ) ;
return;
}
V_134 = F_57 ( V_129 -> V_134 ) ;
V_136 = F_58 ( type , V_124 , & V_42 ) ;
if ( V_3 -> V_118 == V_141 )
return F_59 ( V_3 , V_134 , V_136 ) ;
F_60 ( V_3 ) ;
if ( F_61 ( V_3 ) && type != V_142 )
F_62 ( V_130 , V_143 ) ;
if ( V_3 -> V_118 == V_116 )
goto V_144;
if ( F_10 ( V_7 ) -> V_145 < F_6 ( V_3 ) -> V_146 ) {
F_62 ( V_130 , V_147 ) ;
goto V_144;
}
V_34 = F_14 ( V_3 ) ;
V_133 = V_34 -> V_148 ;
V_135 = V_133 ? F_63 ( V_133 ) -> V_149 : V_34 -> V_135 ;
if ( V_3 -> V_118 != V_150 &&
! F_64 ( V_134 , V_135 , V_34 -> V_151 ) ) {
F_62 ( V_130 , V_152 ) ;
goto V_144;
}
V_32 = F_6 ( V_3 ) ;
if ( type == V_153 ) {
struct V_8 * V_9 = F_65 ( V_3 , V_32 -> V_154 ) ;
if ( V_9 )
V_9 -> V_155 -> V_156 ( V_9 , V_3 , V_7 ) ;
goto V_144;
}
if ( type == V_142 ) {
if ( V_3 -> V_118 == V_150 )
goto V_144;
if ( ! F_66 ( V_3 ) )
goto V_144;
V_34 -> V_121 = F_57 ( V_126 ) ;
if ( ! F_61 ( V_3 ) )
F_44 ( V_3 ) ;
else if ( ! F_67 ( V_157 ,
& V_3 -> V_158 ) )
F_68 ( V_3 ) ;
goto V_144;
}
switch ( V_3 -> V_118 ) {
case V_112 :
case V_159 :
if ( V_133 && ! V_133 -> V_3 )
break;
if ( ! F_61 ( V_3 ) ) {
V_3 -> V_160 = V_42 ;
V_3 -> V_161 ( V_3 ) ;
F_69 ( V_3 ) ;
} else
V_3 -> V_162 = V_42 ;
goto V_144;
}
if ( ! F_61 ( V_3 ) && V_32 -> V_163 ) {
V_3 -> V_160 = V_42 ;
V_3 -> V_161 ( V_3 ) ;
} else
V_3 -> V_162 = V_42 ;
V_144:
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
}
static int F_72 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_164 * V_165 ,
struct V_132 * V_166 ,
struct V_167 * V_168 ,
enum V_169 V_170 )
{
struct V_171 * V_172 = F_73 ( V_166 ) ;
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 = & V_165 -> V_173 . V_174 ;
struct V_6 * V_7 ;
int V_42 = - V_175 ;
if ( ! V_9 && ( V_9 = F_74 ( V_3 , V_40 , V_166 ,
V_90 ) ) == NULL )
goto V_176;
V_7 = F_75 ( V_3 , V_9 , V_166 , V_168 , V_170 ) ;
if ( V_7 ) {
F_76 ( V_7 , & V_172 -> V_177 ,
& V_172 -> V_178 ) ;
V_40 -> V_17 = V_172 -> V_178 ;
if ( V_32 -> V_179 && V_172 -> V_180 )
V_40 -> V_49 = V_53 ( F_10 ( V_172 -> V_180 ) ) ;
F_77 () ;
V_38 = V_172 -> V_181 ;
if ( ! V_38 )
V_38 = F_78 ( V_32 -> V_38 ) ;
V_42 = F_79 ( V_3 , V_7 , V_40 , V_3 -> V_93 , V_38 , V_32 -> V_182 ) ;
F_80 () ;
V_42 = F_81 ( V_42 ) ;
}
V_176:
return V_42 ;
}
static void F_82 ( struct V_132 * V_166 )
{
F_83 ( F_73 ( V_166 ) -> V_181 ) ;
F_84 ( F_73 ( V_166 ) -> V_180 ) ;
}
static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_85 ( V_3 , (union V_183 * ) V_5 , V_46 ) ;
}
static struct V_1 * F_86 ( const struct V_2 * V_3 ,
const struct V_2 * V_184 )
{
return F_1 ( V_3 , & V_184 -> V_65 ) ;
}
static int F_87 ( struct V_2 * V_3 , char T_5 * V_185 ,
int V_186 )
{
struct V_187 V_188 ;
struct V_25 * V_189 = (struct V_25 * ) & V_188 . V_190 ;
if ( V_186 < sizeof( V_188 ) )
return - V_44 ;
if ( F_88 ( & V_188 , V_185 , sizeof( V_188 ) ) )
return - V_191 ;
if ( V_189 -> V_45 != V_46 )
return - V_44 ;
if ( ! V_188 . V_192 ) {
if ( F_19 ( & V_189 -> V_54 ) )
return F_89 ( V_3 , (union V_183 * ) & V_189 -> V_54 . V_18 [ 3 ] ,
V_74 ) ;
return F_89 ( V_3 , (union V_183 * ) & V_189 -> V_54 ,
V_46 ) ;
}
if ( V_188 . V_192 > V_193 )
return - V_44 ;
if ( F_19 ( & V_189 -> V_54 ) )
return F_90 ( V_3 , (union V_183 * ) & V_189 -> V_54 . V_18 [ 3 ] ,
V_74 , V_188 . V_194 , V_188 . V_192 , V_195 ) ;
return F_90 ( V_3 , (union V_183 * ) & V_189 -> V_54 ,
V_46 , V_188 . V_194 , V_188 . V_192 , V_195 ) ;
}
static int F_91 ( struct V_196 * V_197 ,
const struct V_4 * V_17 ,
const struct V_4 * V_19 ,
const struct V_109 * V_129 , int V_198 )
{
struct V_199 * V_200 ;
struct V_201 V_202 ;
struct V_109 * V_203 ;
V_200 = V_197 -> V_204 ;
V_200 -> V_19 = * V_19 ;
V_200 -> V_17 = * V_17 ;
V_200 -> V_205 = F_92 ( V_90 ) ;
V_200 -> V_206 = F_92 ( V_198 ) ;
V_203 = (struct V_109 * ) ( V_200 + 1 ) ;
memcpy ( V_203 , V_129 , sizeof( * V_129 ) ) ;
V_203 -> V_207 = 0 ;
F_93 ( & V_202 , V_200 , sizeof( * V_200 ) + sizeof( * V_129 ) ) ;
F_94 ( V_197 -> V_208 , & V_202 , NULL ,
sizeof( * V_200 ) + sizeof( * V_129 ) ) ;
return F_95 ( V_197 -> V_208 ) ;
}
static int F_96 ( char * V_209 , const struct V_1 * V_210 ,
const struct V_4 * V_17 , struct V_4 * V_19 ,
const struct V_109 * V_129 )
{
struct V_196 * V_197 ;
struct V_211 * V_166 ;
V_197 = F_97 () ;
if ( ! V_197 )
goto V_212;
V_166 = V_197 -> V_208 ;
if ( F_98 ( V_166 ) )
goto V_213;
if ( F_91 ( V_197 , V_17 , V_19 , V_129 , V_129 -> V_214 << 2 ) )
goto V_213;
if ( F_99 ( V_197 , V_210 ) )
goto V_213;
F_94 ( V_166 , NULL , V_209 , 0 ) ;
if ( F_100 ( V_166 ) )
goto V_213;
F_101 () ;
return 0 ;
V_213:
F_101 () ;
V_212:
memset ( V_209 , 0 , 16 ) ;
return 1 ;
}
static int F_102 ( char * V_209 ,
const struct V_1 * V_210 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_19 , * V_17 ;
struct V_196 * V_197 ;
struct V_211 * V_166 ;
const struct V_109 * V_129 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_19 = & V_3 -> V_55 ;
V_17 = & V_3 -> V_65 ;
} else {
const struct V_110 * V_215 = F_10 ( V_7 ) ;
V_19 = & V_215 -> V_19 ;
V_17 = & V_215 -> V_17 ;
}
V_197 = F_97 () ;
if ( ! V_197 )
goto V_212;
V_166 = V_197 -> V_208 ;
if ( F_98 ( V_166 ) )
goto V_213;
if ( F_91 ( V_197 , V_17 , V_19 , V_129 , V_7 -> V_206 ) )
goto V_213;
if ( F_103 ( V_197 , V_7 , V_129 -> V_214 << 2 ) )
goto V_213;
if ( F_99 ( V_197 , V_210 ) )
goto V_213;
F_94 ( V_166 , NULL , V_209 , 0 ) ;
if ( F_100 ( V_166 ) )
goto V_213;
F_101 () ;
return 0 ;
V_213:
F_101 () ;
V_212:
memset ( V_209 , 0 , 16 ) ;
return 1 ;
}
static bool F_104 ( const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
#ifdef F_26
const T_6 * V_216 = NULL ;
struct V_1 * V_217 ;
const struct V_110 * V_215 = F_10 ( V_7 ) ;
const struct V_109 * V_129 = F_11 ( V_7 ) ;
int V_218 ;
T_2 V_219 [ 16 ] ;
V_217 = F_1 ( V_3 , & V_215 -> V_19 ) ;
V_216 = F_105 ( V_129 ) ;
if ( ! V_217 && ! V_216 )
return false ;
if ( V_217 && ! V_216 ) {
F_106 ( F_107 ( V_3 ) , V_220 ) ;
return true ;
}
if ( ! V_217 && V_216 ) {
F_106 ( F_107 ( V_3 ) , V_221 ) ;
return true ;
}
V_218 = F_102 ( V_219 ,
V_217 ,
NULL , V_7 ) ;
if ( V_218 || memcmp ( V_216 , V_219 , 16 ) != 0 ) {
F_106 ( F_107 ( V_3 ) , V_222 ) ;
F_108 ( L_2 ,
V_218 ? L_3 : L_4 ,
& V_215 -> V_19 , F_52 ( V_129 -> V_21 ) ,
& V_215 -> V_17 , F_52 ( V_129 -> V_20 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_109 ( struct V_132 * V_166 ,
const struct V_2 * V_223 ,
struct V_6 * V_7 )
{
struct V_171 * V_172 = F_73 ( V_166 ) ;
const struct V_31 * V_32 = F_6 ( V_223 ) ;
V_172 -> V_178 = F_10 ( V_7 ) -> V_19 ;
V_172 -> V_177 = F_10 ( V_7 ) -> V_17 ;
if ( ! V_223 -> V_62 &&
F_22 ( & V_172 -> V_178 ) & V_60 )
V_172 -> V_224 = F_110 ( V_7 ) ;
if ( ! F_111 ( V_7 ) -> V_225 &&
( F_112 ( V_223 , V_7 , & F_111 ( V_7 ) -> V_226 . V_227 ) ||
V_32 -> V_228 . V_229 . V_230 ||
V_32 -> V_228 . V_229 . V_231 || V_32 -> V_228 . V_229 . V_232 ||
V_32 -> V_228 . V_229 . V_233 || V_32 -> V_179 ) ) {
F_113 ( & V_7 -> V_234 ) ;
V_172 -> V_180 = V_7 ;
}
}
static struct V_8 * F_114 ( const struct V_2 * V_3 ,
struct V_164 * V_165 ,
const struct V_132 * V_166 ,
bool * V_235 )
{
if ( V_235 )
* V_235 = true ;
return F_74 ( V_3 , & V_165 -> V_173 . V_174 , V_166 , V_90 ) ;
}
static void F_115 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_134 ,
T_1 V_236 , T_1 V_237 , T_1 V_238 , T_1 V_239 ,
int V_240 , struct V_1 * V_210 , int V_241 ,
T_2 V_182 , T_3 V_242 )
{
const struct V_109 * V_129 = F_11 ( V_7 ) ;
struct V_109 * V_243 ;
struct V_6 * V_244 ;
struct V_39 V_40 ;
struct V_130 * V_130 = V_3 ? F_107 ( V_3 ) : F_50 ( F_3 ( V_7 ) -> V_131 ) ;
struct V_2 * V_245 = V_130 -> V_246 . F_14 ;
unsigned int V_247 = sizeof( struct V_109 ) ;
struct V_8 * V_9 ;
T_3 * V_248 ;
if ( V_239 )
V_247 += V_249 ;
#ifdef F_26
if ( V_210 )
V_247 += V_250 ;
#endif
V_244 = F_116 ( V_251 + sizeof( struct V_110 ) + V_247 ,
V_252 ) ;
if ( ! V_244 )
return;
F_117 ( V_244 , V_251 + sizeof( struct V_110 ) + V_247 ) ;
V_243 = (struct V_109 * ) F_118 ( V_244 , V_247 ) ;
F_119 ( V_244 ) ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_243 -> V_20 = V_129 -> V_21 ;
V_243 -> V_21 = V_129 -> V_20 ;
V_243 -> V_214 = V_247 / 4 ;
V_243 -> V_134 = F_21 ( V_134 ) ;
V_243 -> V_253 = F_21 ( V_236 ) ;
V_243 -> V_236 = ! V_241 || ! V_129 -> V_236 ;
V_243 -> V_241 = V_241 ;
V_243 -> V_254 = F_120 ( V_237 ) ;
V_248 = ( T_3 * ) ( V_243 + 1 ) ;
if ( V_239 ) {
* V_248 ++ = F_21 ( ( V_255 << 24 ) | ( V_255 << 16 ) |
( V_256 << 8 ) | V_257 ) ;
* V_248 ++ = F_21 ( V_238 ) ;
* V_248 ++ = F_21 ( V_239 ) ;
}
#ifdef F_26
if ( V_210 ) {
* V_248 ++ = F_21 ( ( V_255 << 24 ) | ( V_255 << 16 ) |
( V_258 << 8 ) | V_259 ) ;
F_96 ( ( T_6 * ) V_248 , V_210 ,
& F_10 ( V_7 ) -> V_19 ,
& F_10 ( V_7 ) -> V_17 , V_243 ) ;
}
#endif
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_17 = F_10 ( V_7 ) -> V_19 ;
V_40 . V_19 = F_10 ( V_7 ) -> V_17 ;
V_40 . V_49 = V_242 ;
V_244 -> V_260 = V_261 ;
V_244 -> V_262 = 0 ;
F_76 ( V_244 , & V_40 . V_19 , & V_40 . V_17 ) ;
V_40 . V_89 = V_90 ;
if ( F_121 ( & V_40 . V_17 ) && ! V_240 )
V_40 . V_91 = F_110 ( V_7 ) ;
else {
if ( ! V_240 && F_122 ( V_130 , V_7 -> V_14 ) )
V_240 = V_7 -> V_14 ;
V_40 . V_91 = V_240 ;
}
V_40 . V_92 = F_123 ( V_130 , V_7 -> V_263 ) ;
V_40 . V_94 = V_243 -> V_20 ;
V_40 . V_95 = V_243 -> V_21 ;
V_40 . V_97 = F_124 ( V_130 , V_3 && F_125 ( V_3 ) ? V_3 : NULL ) ;
F_126 ( V_7 , F_32 ( & V_40 ) ) ;
V_9 = F_33 ( V_245 , & V_40 , NULL ) ;
if ( ! F_34 ( V_9 ) ) {
F_127 ( V_244 , V_9 ) ;
F_79 ( V_245 , V_244 , & V_40 , V_40 . V_92 , NULL , V_182 ) ;
F_128 ( V_130 , V_264 ) ;
if ( V_241 )
F_128 ( V_130 , V_265 ) ;
return;
}
F_84 ( V_244 ) ;
}
static void F_129 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_109 * V_129 = F_11 ( V_7 ) ;
T_1 V_134 = 0 , V_253 = 0 ;
struct V_1 * V_210 = NULL ;
#ifdef F_26
const T_6 * V_216 = NULL ;
struct V_110 * V_266 = F_10 ( V_7 ) ;
unsigned char V_219 [ 16 ] ;
int V_218 ;
struct V_2 * V_267 = NULL ;
#endif
int V_240 ;
if ( V_129 -> V_241 )
return;
if ( ! V_3 && ! F_130 ( V_7 ) )
return;
#ifdef F_26
F_77 () ;
V_216 = F_105 ( V_129 ) ;
if ( V_3 && F_125 ( V_3 ) ) {
V_210 = F_1 ( V_3 , & V_266 -> V_19 ) ;
} else if ( V_216 ) {
V_267 = F_131 ( F_50 ( F_3 ( V_7 ) -> V_131 ) ,
& V_137 , NULL , 0 ,
& V_266 -> V_19 ,
V_129 -> V_21 , & V_266 -> V_17 ,
F_52 ( V_129 -> V_21 ) , F_110 ( V_7 ) ) ;
if ( ! V_267 )
goto V_144;
V_210 = F_1 ( V_267 , & V_266 -> V_19 ) ;
if ( ! V_210 )
goto V_144;
V_218 = F_102 ( V_219 , V_210 , NULL , V_7 ) ;
if ( V_218 || memcmp ( V_216 , V_219 , 16 ) != 0 )
goto V_144;
}
#endif
if ( V_129 -> V_236 )
V_134 = F_57 ( V_129 -> V_253 ) ;
else
V_253 = F_57 ( V_129 -> V_134 ) + V_129 -> V_268 + V_129 -> V_269 + V_7 -> V_206 -
( V_129 -> V_214 << 2 ) ;
V_240 = V_3 ? V_3 -> V_62 : 0 ;
F_115 ( V_3 , V_7 , V_134 , V_253 , 0 , 0 , 0 , V_240 , V_210 , 1 , 0 , 0 ) ;
#ifdef F_26
V_144:
F_80 () ;
#endif
}
static void F_132 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_134 ,
T_1 V_236 , T_1 V_237 , T_1 V_238 , T_1 V_239 , int V_240 ,
struct V_1 * V_210 , T_2 V_182 ,
T_3 V_242 )
{
F_115 ( V_3 , V_7 , V_134 , V_236 , V_237 , V_238 , V_239 , V_240 , V_210 , 0 ,
V_182 , V_242 ) ;
}
static void F_133 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_270 * V_271 = F_56 ( V_3 ) ;
struct V_272 * V_273 = F_134 ( V_3 ) ;
F_132 ( V_3 , V_7 , V_273 -> V_274 , V_273 -> V_275 ,
V_273 -> V_276 >> V_271 -> V_277 ,
V_278 + V_273 -> V_279 ,
V_273 -> V_280 , V_271 -> V_281 , F_135 ( V_273 ) ,
V_271 -> V_282 , F_92 ( V_271 -> V_283 ) ) ;
F_55 ( V_271 ) ;
}
static void F_136 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_132 * V_166 )
{
F_132 ( V_3 , V_7 , ( V_3 -> V_118 == V_150 ) ?
F_63 ( V_166 ) -> V_149 + 1 : F_14 ( V_3 ) -> V_151 ,
F_63 ( V_166 ) -> V_284 ,
V_166 -> V_285 >> F_73 ( V_166 ) -> V_286 ,
V_278 + F_63 ( V_166 ) -> V_287 ,
V_166 -> V_66 , V_3 -> V_62 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_17 ) ,
0 , 0 ) ;
}
static struct V_2 * F_137 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_138
const struct V_109 * V_129 = F_11 ( V_7 ) ;
if ( ! V_129 -> V_268 )
V_3 = F_139 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_140 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_205 == F_120 ( V_288 ) )
return F_141 ( V_3 , V_7 ) ;
if ( ! F_130 ( V_7 ) )
goto V_289;
return F_142 ( & V_290 ,
& V_291 , V_3 , V_7 ) ;
V_289:
F_143 ( V_3 ) ;
return 0 ;
}
static void F_144 ( struct V_6 * V_7 )
{
memmove ( F_145 ( V_7 ) , & F_111 ( V_7 ) -> V_226 . V_227 ,
sizeof( struct V_123 ) ) ;
}
static struct V_2 * F_146 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_132 * V_166 ,
struct V_8 * V_9 ,
struct V_132 * V_292 ,
bool * V_293 )
{
struct V_171 * V_172 ;
struct V_31 * V_294 ;
const struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_37 * V_38 ;
struct V_295 * V_296 ;
struct V_27 * V_297 ;
struct V_33 * V_298 ;
struct V_2 * V_299 ;
#ifdef F_26
struct V_1 * V_210 ;
#endif
struct V_39 V_40 ;
if ( V_7 -> V_205 == F_120 ( V_288 ) ) {
V_299 = F_147 ( V_3 , V_7 , V_166 , V_9 ,
V_292 , V_293 ) ;
if ( ! V_299 )
return NULL ;
V_296 = (struct V_295 * ) V_299 ;
F_5 ( V_299 ) -> V_300 = & V_296 -> V_301 ;
V_297 = F_5 ( V_299 ) ;
V_294 = F_6 ( V_299 ) ;
V_298 = F_14 ( V_299 ) ;
memcpy ( V_294 , V_32 , sizeof( struct V_31 ) ) ;
V_294 -> V_19 = V_299 -> V_55 ;
F_13 ( V_299 ) -> V_79 = & V_80 ;
V_299 -> V_81 = V_82 ;
#ifdef F_26
V_298 -> V_83 = & V_84 ;
#endif
V_294 -> V_302 = NULL ;
V_294 -> V_303 = NULL ;
V_294 -> V_304 = NULL ;
V_294 -> V_38 = NULL ;
V_294 -> V_305 = F_110 ( V_7 ) ;
V_294 -> V_306 = F_10 ( V_7 ) -> V_145 ;
V_294 -> V_307 = F_148 ( F_10 ( V_7 ) ) ;
if ( V_32 -> V_179 )
V_294 -> V_68 = V_53 ( F_10 ( V_7 ) ) ;
F_47 ( V_299 , F_13 ( V_299 ) -> V_122 ) ;
return V_299 ;
}
V_172 = F_73 ( V_166 ) ;
if ( F_149 ( V_3 ) )
goto V_308;
if ( ! V_9 ) {
V_9 = F_74 ( V_3 , & V_40 , V_166 , V_90 ) ;
if ( ! V_9 )
goto V_144;
}
V_299 = F_150 ( V_3 , V_166 , V_7 ) ;
if ( ! V_299 )
goto V_309;
V_299 -> V_101 = V_102 ;
F_36 ( V_299 , V_9 , NULL , NULL ) ;
F_2 ( V_299 , V_7 ) ;
V_296 = (struct V_295 * ) V_299 ;
F_5 ( V_299 ) -> V_300 = & V_296 -> V_301 ;
V_298 = F_14 ( V_299 ) ;
V_297 = F_5 ( V_299 ) ;
V_294 = F_6 ( V_299 ) ;
memcpy ( V_294 , V_32 , sizeof( struct V_31 ) ) ;
V_299 -> V_65 = V_172 -> V_178 ;
V_294 -> V_19 = V_172 -> V_177 ;
V_299 -> V_55 = V_172 -> V_177 ;
V_299 -> V_62 = V_172 -> V_224 ;
V_297 -> V_310 = NULL ;
V_294 -> V_302 = NULL ;
V_294 -> V_303 = NULL ;
V_294 -> V_228 . V_311 = V_32 -> V_228 . V_311 ;
V_294 -> V_304 = NULL ;
V_294 -> V_38 = NULL ;
V_294 -> V_305 = F_110 ( V_7 ) ;
V_294 -> V_306 = F_10 ( V_7 ) -> V_145 ;
V_294 -> V_307 = F_148 ( F_10 ( V_7 ) ) ;
if ( V_32 -> V_179 )
V_294 -> V_68 = V_53 ( F_10 ( V_7 ) ) ;
V_38 = V_172 -> V_181 ;
if ( ! V_38 )
V_38 = F_78 ( V_32 -> V_38 ) ;
if ( V_38 ) {
V_38 = F_151 ( V_299 , V_38 ) ;
F_152 ( V_294 -> V_38 , V_38 ) ;
}
F_13 ( V_299 ) -> V_71 = 0 ;
if ( V_38 )
F_13 ( V_299 ) -> V_71 = V_38 -> V_106 +
V_38 -> V_105 ;
F_153 ( V_299 , V_9 ) ;
F_47 ( V_299 , F_46 ( V_9 ) ) ;
V_298 -> V_312 = F_154 ( V_9 ) ;
if ( F_14 ( V_3 ) -> V_63 . V_313 &&
F_14 ( V_3 ) -> V_63 . V_313 < V_298 -> V_312 )
V_298 -> V_312 = F_14 ( V_3 ) -> V_63 . V_313 ;
F_155 ( V_299 ) ;
V_297 -> V_314 = V_297 -> V_315 = V_100 ;
V_297 -> V_99 = V_100 ;
#ifdef F_26
V_210 = F_1 ( V_3 , & V_299 -> V_65 ) ;
if ( V_210 ) {
F_90 ( V_299 , (union V_183 * ) & V_299 -> V_65 ,
V_46 , V_210 -> V_210 , V_210 -> V_316 ,
F_156 ( V_3 , V_252 ) ) ;
}
#endif
if ( F_157 ( V_3 , V_299 ) < 0 ) {
F_158 ( V_299 ) ;
F_69 ( V_299 ) ;
goto V_144;
}
* V_293 = F_159 ( V_299 , F_160 ( V_292 ) ) ;
if ( * V_293 ) {
F_161 ( V_298 , V_166 ) ;
if ( V_172 -> V_180 ) {
V_294 -> V_304 = F_162 ( V_172 -> V_180 ,
F_156 ( V_3 , V_252 ) ) ;
F_163 ( V_172 -> V_180 ) ;
V_172 -> V_180 = NULL ;
if ( V_294 -> V_304 ) {
F_144 ( V_294 -> V_304 ) ;
F_164 ( V_294 -> V_304 , V_299 ) ;
}
}
}
return V_299 ;
V_308:
F_62 ( F_107 ( V_3 ) , V_317 ) ;
V_309:
F_165 ( V_9 ) ;
V_144:
F_143 ( V_3 ) ;
return NULL ;
}
static int V_86 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_33 * V_34 ;
struct V_6 * V_318 = NULL ;
if ( V_7 -> V_205 == F_120 ( V_288 ) )
return V_82 ( V_3 , V_7 ) ;
if ( F_166 ( V_3 , V_7 ) )
goto V_319;
if ( V_32 -> V_228 . V_311 )
V_318 = F_162 ( V_7 , F_156 ( V_3 , V_252 ) ) ;
if ( V_3 -> V_118 == V_320 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_167 ( V_3 , V_7 ) ;
F_168 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_155 -> V_207 ( V_9 , V_32 -> V_15 ) == NULL ) {
F_165 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_169 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_206 ) ;
if ( V_318 )
goto V_321;
return 0 ;
}
if ( F_170 ( V_7 ) )
goto V_322;
if ( V_3 -> V_118 == V_150 ) {
struct V_2 * V_323 = F_137 ( V_3 , V_7 ) ;
if ( ! V_323 )
goto V_319;
if ( V_323 != V_3 ) {
F_167 ( V_323 , V_7 ) ;
F_168 ( V_323 , V_7 ) ;
if ( F_171 ( V_3 , V_323 , V_7 ) )
goto V_324;
if ( V_318 )
F_172 ( V_318 ) ;
return 0 ;
}
} else
F_167 ( V_3 , V_7 ) ;
if ( F_173 ( V_3 , V_7 ) )
goto V_324;
if ( V_318 )
goto V_321;
return 0 ;
V_324:
F_129 ( V_3 , V_7 ) ;
V_319:
if ( V_318 )
F_172 ( V_318 ) ;
F_84 ( V_7 ) ;
return 0 ;
V_322:
F_128 ( F_107 ( V_3 ) , V_325 ) ;
F_128 ( F_107 ( V_3 ) , V_326 ) ;
goto V_319;
V_321:
V_34 = F_14 ( V_3 ) ;
if ( F_111 ( V_318 ) -> V_327 == V_34 -> V_284 &&
! ( ( 1 << V_3 -> V_118 ) & ( V_120 | V_119 ) ) ) {
if ( V_32 -> V_228 . V_229 . V_230 || V_32 -> V_228 . V_229 . V_231 )
V_32 -> V_305 = F_110 ( V_318 ) ;
if ( V_32 -> V_228 . V_229 . V_232 || V_32 -> V_228 . V_229 . V_233 )
V_32 -> V_306 = F_10 ( V_318 ) -> V_145 ;
if ( V_32 -> V_228 . V_229 . V_328 || V_32 -> V_228 . V_229 . V_329 )
V_32 -> V_307 = F_148 ( F_10 ( V_318 ) ) ;
if ( V_32 -> V_179 )
V_32 -> V_68 = V_53 ( F_10 ( V_318 ) ) ;
if ( F_112 ( V_3 , V_318 , & F_111 ( V_318 ) -> V_226 . V_227 ) ) {
F_164 ( V_318 , V_3 ) ;
F_144 ( V_318 ) ;
V_318 = F_174 ( & V_32 -> V_304 , V_318 ) ;
} else {
F_172 ( V_318 ) ;
V_318 = F_174 ( & V_32 -> V_304 , NULL ) ;
}
}
F_84 ( V_318 ) ;
return 0 ;
}
static void F_175 ( struct V_6 * V_7 , const struct V_110 * V_127 ,
const struct V_109 * V_129 )
{
memmove ( & F_111 ( V_7 ) -> V_226 . V_227 , F_145 ( V_7 ) ,
sizeof( struct V_123 ) ) ;
F_176 () ;
F_111 ( V_7 ) -> V_134 = F_57 ( V_129 -> V_134 ) ;
F_111 ( V_7 ) -> V_327 = ( F_111 ( V_7 ) -> V_134 + V_129 -> V_268 + V_129 -> V_269 +
V_7 -> V_206 - V_129 -> V_214 * 4 ) ;
F_111 ( V_7 ) -> V_253 = F_57 ( V_129 -> V_253 ) ;
F_111 ( V_7 ) -> V_330 = F_177 ( V_129 ) ;
F_111 ( V_7 ) -> V_225 = 0 ;
F_111 ( V_7 ) -> V_331 = F_178 ( V_127 ) ;
F_111 ( V_7 ) -> V_332 = 0 ;
}
static int F_179 ( struct V_6 * V_7 )
{
const struct V_109 * V_129 ;
const struct V_110 * V_127 ;
bool V_333 ;
struct V_2 * V_3 ;
int V_334 ;
struct V_130 * V_130 = F_50 ( V_7 -> V_131 ) ;
if ( V_7 -> V_335 != V_336 )
goto V_337;
F_180 ( V_130 , V_338 ) ;
if ( ! F_181 ( V_7 , sizeof( struct V_109 ) ) )
goto V_337;
V_129 = ( const struct V_109 * ) V_7 -> V_128 ;
if ( F_182 ( V_129 -> V_214 < sizeof( struct V_109 ) / 4 ) )
goto V_339;
if ( ! F_181 ( V_7 , V_129 -> V_214 * 4 ) )
goto V_337;
if ( F_183 ( V_7 , V_90 , V_340 ) )
goto V_341;
V_129 = ( const struct V_109 * ) V_7 -> V_128 ;
V_127 = F_10 ( V_7 ) ;
V_342:
V_3 = F_184 ( & V_137 , V_7 , F_185 ( V_129 ) ,
V_129 -> V_21 , V_129 -> V_20 , F_186 ( V_7 ) ,
& V_333 ) ;
if ( ! V_3 )
goto V_343;
V_344:
if ( V_3 -> V_118 == V_140 )
goto V_345;
if ( V_3 -> V_118 == V_141 ) {
struct V_132 * V_166 = F_187 ( V_3 ) ;
struct V_2 * V_323 ;
V_3 = V_166 -> V_346 ;
F_175 ( V_7 , V_127 , V_129 ) ;
if ( F_104 ( V_3 , V_7 ) ) {
F_188 ( V_3 , V_7 ) ;
F_189 ( V_166 ) ;
goto V_337;
}
if ( F_182 ( V_3 -> V_118 != V_150 ) ) {
F_190 ( V_3 , V_166 ) ;
goto V_342;
}
F_68 ( V_3 ) ;
V_333 = true ;
V_323 = F_191 ( V_3 , V_7 , V_166 , false ) ;
if ( ! V_323 ) {
F_189 ( V_166 ) ;
goto V_347;
}
if ( V_323 == V_3 ) {
F_189 ( V_166 ) ;
F_144 ( V_7 ) ;
} else if ( F_171 ( V_3 , V_323 , V_7 ) ) {
F_129 ( V_323 , V_7 ) ;
goto V_347;
} else {
F_71 ( V_3 ) ;
return 0 ;
}
}
if ( V_127 -> V_145 < F_6 ( V_3 ) -> V_146 ) {
F_62 ( V_130 , V_147 ) ;
goto V_347;
}
if ( ! F_192 ( V_3 , V_348 , V_7 ) )
goto V_347;
F_175 ( V_7 , V_127 , V_129 ) ;
if ( F_104 ( V_3 , V_7 ) )
goto V_347;
if ( F_166 ( V_3 , V_7 ) )
goto V_347;
V_129 = ( const struct V_109 * ) V_7 -> V_128 ;
V_127 = F_10 ( V_7 ) ;
V_7 -> V_131 = NULL ;
if ( V_3 -> V_118 == V_150 ) {
V_334 = V_86 ( V_3 , V_7 ) ;
goto V_349;
}
F_193 ( V_3 ) ;
F_194 ( V_3 ) ;
F_195 ( F_14 ( V_3 ) , V_7 ) ;
V_334 = 0 ;
if ( ! F_61 ( V_3 ) ) {
if ( ! F_196 ( V_3 , V_7 ) )
V_334 = V_86 ( V_3 , V_7 ) ;
} else if ( F_197 ( V_3 , V_7 ) ) {
goto V_347;
}
F_70 ( V_3 ) ;
V_349:
if ( V_333 )
F_71 ( V_3 ) ;
return V_334 ? - 1 : 0 ;
V_343:
if ( ! F_192 ( NULL , V_348 , V_7 ) )
goto V_337;
F_175 ( V_7 , V_127 , V_129 ) ;
if ( F_170 ( V_7 ) ) {
V_341:
F_180 ( V_130 , V_325 ) ;
V_339:
F_180 ( V_130 , V_326 ) ;
} else {
F_129 ( NULL , V_7 ) ;
}
V_337:
F_84 ( V_7 ) ;
return 0 ;
V_347:
F_188 ( V_3 , V_7 ) ;
if ( V_333 )
F_71 ( V_3 ) ;
goto V_337;
V_345:
if ( ! F_192 ( NULL , V_348 , V_7 ) ) {
F_55 ( F_56 ( V_3 ) ) ;
goto V_337;
}
F_175 ( V_7 , V_127 , V_129 ) ;
if ( F_170 ( V_7 ) ) {
F_55 ( F_56 ( V_3 ) ) ;
goto V_341;
}
switch ( F_198 ( F_56 ( V_3 ) , V_7 , V_129 ) ) {
case V_350 :
{
struct V_2 * V_351 ;
V_351 = F_131 ( F_50 ( V_7 -> V_131 ) , & V_137 ,
V_7 , F_185 ( V_129 ) ,
& F_10 ( V_7 ) -> V_19 , V_129 -> V_21 ,
& F_10 ( V_7 ) -> V_17 ,
F_52 ( V_129 -> V_20 ) , F_110 ( V_7 ) ) ;
if ( V_351 ) {
struct V_270 * V_271 = F_56 ( V_3 ) ;
F_199 ( V_271 ) ;
V_3 = V_351 ;
F_144 ( V_7 ) ;
V_333 = false ;
goto V_344;
}
}
case V_352 :
F_133 ( V_3 , V_7 ) ;
break;
case V_353 :
F_144 ( V_7 ) ;
F_129 ( V_3 , V_7 ) ;
F_199 ( F_56 ( V_3 ) ) ;
goto V_337;
case V_354 :
;
}
goto V_337;
}
static void F_200 ( struct V_6 * V_7 )
{
const struct V_110 * V_127 ;
const struct V_109 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_335 != V_336 )
return;
if ( ! F_181 ( V_7 , F_201 ( V_7 ) + sizeof( struct V_109 ) ) )
return;
V_127 = F_10 ( V_7 ) ;
V_129 = F_11 ( V_7 ) ;
if ( V_129 -> V_214 < sizeof( struct V_109 ) / 4 )
return;
V_3 = F_51 ( F_50 ( V_7 -> V_131 ) , & V_137 ,
& V_127 -> V_19 , V_129 -> V_21 ,
& V_127 -> V_17 , F_52 ( V_129 -> V_20 ) ,
F_186 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_355 = V_356 ;
if ( F_125 ( V_3 ) ) {
struct V_8 * V_9 = F_202 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_203 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_204 ( V_7 , V_9 ) ;
}
}
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = F_13 ( V_3 ) ;
F_206 ( V_3 ) ;
V_30 -> V_79 = & V_85 ;
#ifdef F_26
F_14 ( V_3 ) -> V_83 = & V_87 ;
#endif
return 0 ;
}
static void F_207 ( struct V_2 * V_3 )
{
F_208 ( V_3 ) ;
F_209 ( V_3 ) ;
}
static void F_210 ( struct V_357 * V_134 ,
const struct V_132 * V_166 , int V_358 )
{
long V_359 = V_166 -> V_360 . V_361 - V_362 ;
const struct V_4 * V_363 = & F_73 ( V_166 ) -> V_177 ;
const struct V_4 * V_20 = & F_73 ( V_166 ) -> V_178 ;
if ( V_359 < 0 )
V_359 = 0 ;
F_211 ( V_134 ,
L_5
L_6 ,
V_358 ,
V_363 -> V_18 [ 0 ] , V_363 -> V_18 [ 1 ] ,
V_363 -> V_18 [ 2 ] , V_363 -> V_18 [ 3 ] ,
F_73 ( V_166 ) -> V_364 ,
V_20 -> V_18 [ 0 ] , V_20 -> V_18 [ 1 ] ,
V_20 -> V_18 [ 2 ] , V_20 -> V_18 [ 3 ] ,
F_52 ( F_73 ( V_166 ) -> V_365 ) ,
V_159 ,
0 , 0 ,
1 ,
F_212 ( V_359 ) ,
V_166 -> V_366 ,
F_213 ( F_214 ( V_134 ) ,
F_215 ( V_166 -> V_346 ) ) ,
0 ,
0 ,
0 , V_166 ) ;
}
static void F_216 ( struct V_357 * V_134 , struct V_2 * V_367 , int V_358 )
{
const struct V_4 * V_20 , * V_363 ;
T_7 V_368 , V_369 ;
int V_370 ;
unsigned long V_371 ;
const struct V_27 * V_28 = F_5 ( V_367 ) ;
const struct V_33 * V_34 = F_14 ( V_367 ) ;
const struct V_29 * V_30 = F_13 ( V_367 ) ;
const struct V_372 * V_373 = & V_30 -> V_374 . V_373 ;
int V_375 ;
int V_376 ;
V_20 = & V_367 -> V_65 ;
V_363 = & V_367 -> V_55 ;
V_368 = F_52 ( V_28 -> V_111 ) ;
V_369 = F_52 ( V_28 -> V_96 ) ;
if ( V_30 -> V_377 == V_378 ||
V_30 -> V_377 == V_379 ||
V_30 -> V_377 == V_380 ) {
V_370 = 1 ;
V_371 = V_30 -> V_381 ;
} else if ( V_30 -> V_377 == V_382 ) {
V_370 = 4 ;
V_371 = V_30 -> V_381 ;
} else if ( F_217 ( & V_367 -> V_383 ) ) {
V_370 = 2 ;
V_371 = V_367 -> V_383 . V_361 ;
} else {
V_370 = 0 ;
V_371 = V_362 ;
}
V_376 = F_218 ( V_367 ) ;
if ( V_376 == V_150 )
V_375 = V_367 -> V_384 ;
else
V_375 = F_219 ( int , V_34 -> V_284 - V_34 -> V_385 , 0 ) ;
F_211 ( V_134 ,
L_5
L_7 ,
V_358 ,
V_363 -> V_18 [ 0 ] , V_363 -> V_18 [ 1 ] ,
V_363 -> V_18 [ 2 ] , V_363 -> V_18 [ 3 ] , V_369 ,
V_20 -> V_18 [ 0 ] , V_20 -> V_18 [ 1 ] ,
V_20 -> V_18 [ 2 ] , V_20 -> V_18 [ 3 ] , V_368 ,
V_376 ,
V_34 -> V_67 - V_34 -> V_135 ,
V_375 ,
V_370 ,
F_220 ( V_371 - V_362 ) ,
V_30 -> V_386 ,
F_213 ( F_214 ( V_134 ) , F_215 ( V_367 ) ) ,
V_30 -> V_387 ,
F_221 ( V_367 ) ,
F_222 ( & V_367 -> V_388 ) , V_367 ,
F_212 ( V_30 -> V_389 ) ,
F_212 ( V_30 -> V_390 . V_391 ) ,
( V_30 -> V_390 . V_392 << 1 ) | V_30 -> V_390 . V_393 ,
V_34 -> V_394 ,
V_376 == V_150 ?
V_373 -> V_395 :
( F_223 ( V_34 ) ? - 1 : V_34 -> V_396 )
) ;
}
static void F_224 ( struct V_357 * V_134 ,
struct V_270 * V_271 , int V_358 )
{
long V_397 = V_271 -> V_398 . V_361 - V_362 ;
const struct V_4 * V_20 , * V_363 ;
T_7 V_368 , V_369 ;
V_20 = & V_271 -> V_399 ;
V_363 = & V_271 -> V_400 ;
V_368 = F_52 ( V_271 -> V_401 ) ;
V_369 = F_52 ( V_271 -> V_402 ) ;
F_211 ( V_134 ,
L_5
L_8 ,
V_358 ,
V_363 -> V_18 [ 0 ] , V_363 -> V_18 [ 1 ] ,
V_363 -> V_18 [ 2 ] , V_363 -> V_18 [ 3 ] , V_369 ,
V_20 -> V_18 [ 0 ] , V_20 -> V_18 [ 1 ] ,
V_20 -> V_18 [ 2 ] , V_20 -> V_18 [ 3 ] , V_368 ,
V_271 -> V_403 , 0 , 0 ,
3 , F_220 ( V_397 ) , 0 , 0 , 0 , 0 ,
F_222 ( & V_271 -> V_404 ) , V_271 ) ;
}
static int F_225 ( struct V_357 * V_134 , void * V_405 )
{
struct V_406 * V_407 ;
struct V_2 * V_3 = V_405 ;
if ( V_405 == V_408 ) {
F_226 ( V_134 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_144;
}
V_407 = V_134 -> V_409 ;
if ( V_3 -> V_118 == V_140 )
F_224 ( V_134 , V_405 , V_407 -> V_410 ) ;
else if ( V_3 -> V_118 == V_141 )
F_210 ( V_134 , V_405 , V_407 -> V_410 ) ;
else
F_216 ( V_134 , V_405 , V_407 -> V_410 ) ;
V_144:
return 0 ;
}
int T_8 F_227 ( struct V_130 * V_130 )
{
return F_228 ( V_130 , & V_411 ) ;
}
void F_229 ( struct V_130 * V_130 )
{
F_230 ( V_130 , & V_411 ) ;
}
static int T_8 F_231 ( struct V_130 * V_130 )
{
return F_232 ( & V_130 -> V_246 . F_14 , V_412 ,
V_413 , V_90 , V_130 ) ;
}
static void T_9 F_233 ( struct V_130 * V_130 )
{
F_234 ( V_130 -> V_246 . F_14 ) ;
}
static void T_9 F_235 ( struct V_414 * V_415 )
{
F_236 ( & V_137 , & V_103 , V_46 ) ;
}
int T_10 F_237 ( void )
{
int V_334 ;
V_334 = F_238 ( & V_416 , V_90 ) ;
if ( V_334 )
goto V_144;
V_334 = F_239 ( & V_417 ) ;
if ( V_334 )
goto V_418;
V_334 = F_240 ( & V_419 ) ;
if ( V_334 )
goto V_420;
V_144:
return V_334 ;
V_420:
F_241 ( & V_417 ) ;
V_418:
F_242 ( & V_416 , V_90 ) ;
goto V_144;
}
void F_243 ( void )
{
F_244 ( & V_419 ) ;
F_241 ( & V_417 ) ;
F_242 ( & V_416 , V_90 ) ;
}
