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
static T_1 F_12 ( const struct V_6 * V_7 )
{
return F_13 ( F_10 ( V_7 ) -> V_16 . V_17 ,
F_10 ( V_7 ) -> V_18 . V_17 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_21 * V_22 ,
int V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_22 ;
struct V_26 * V_27 = F_5 ( V_3 ) ;
struct V_28 * V_29 = F_15 ( V_3 ) ;
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 = F_16 ( V_3 ) ;
struct V_4 * V_18 = NULL , * V_34 , V_35 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
struct V_8 * V_9 ;
int V_40 ;
int V_41 ;
struct V_42 * V_43 = & F_17 ( V_3 ) -> V_44 . V_43 ;
if ( V_23 < V_45 )
return - V_46 ;
if ( V_25 -> V_47 != V_48 )
return - V_49 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_31 -> V_50 ) {
V_39 . V_51 = V_25 -> V_52 & V_53 ;
F_18 ( V_39 . V_51 ) ;
if ( V_39 . V_51 & V_54 ) {
struct V_55 * V_51 ;
V_51 = F_19 ( V_3 , V_39 . V_51 ) ;
if ( ! V_51 )
return - V_46 ;
F_20 ( V_51 ) ;
}
}
if ( F_21 ( & V_25 -> V_56 ) ) {
if ( F_22 ( & V_3 -> V_57 ) )
F_23 ( F_24 ( V_58 ) ,
& V_25 -> V_56 ) ;
else
V_25 -> V_56 = V_59 ;
}
V_40 = F_25 ( & V_25 -> V_56 ) ;
if ( V_40 & V_60 )
return - V_61 ;
if ( V_40 & V_62 ) {
if ( V_23 >= sizeof( struct V_24 ) &&
V_25 -> V_63 ) {
if ( V_3 -> V_64 &&
V_3 -> V_64 != V_25 -> V_63 )
return - V_46 ;
V_3 -> V_64 = V_25 -> V_63 ;
}
if ( ! V_3 -> V_64 )
return - V_46 ;
}
if ( V_33 -> V_65 . V_66 &&
! F_26 ( & V_3 -> V_67 , & V_25 -> V_56 ) ) {
V_33 -> V_65 . V_68 = 0 ;
V_33 -> V_65 . V_66 = 0 ;
V_33 -> V_69 = 0 ;
}
V_3 -> V_67 = V_25 -> V_56 ;
V_31 -> V_70 = V_39 . V_51 ;
if ( V_40 & V_71 ) {
T_1 V_72 = V_29 -> V_73 ;
struct V_74 sin ;
F_27 ( V_3 , L_1 ) ;
if ( F_28 ( V_3 ) )
return - V_61 ;
sin . V_75 = V_76 ;
sin . V_77 = V_25 -> V_78 ;
sin . V_79 . V_80 = V_25 -> V_56 . V_17 [ 3 ] ;
V_29 -> V_81 = & V_82 ;
V_3 -> V_83 = V_84 ;
#ifdef F_29
V_33 -> V_85 = & V_86 ;
#endif
V_41 = F_30 ( V_3 , (struct V_21 * ) & sin , sizeof( sin ) ) ;
if ( V_41 ) {
V_29 -> V_73 = V_72 ;
V_29 -> V_81 = & V_87 ;
V_3 -> V_83 = V_88 ;
#ifdef F_29
V_33 -> V_85 = & V_89 ;
#endif
goto V_90;
}
V_31 -> V_18 = V_3 -> V_57 ;
return V_41 ;
}
if ( ! F_21 ( & V_3 -> V_57 ) )
V_18 = & V_3 -> V_57 ;
V_39 . V_91 = V_92 ;
V_39 . V_16 = V_3 -> V_67 ;
V_39 . V_18 = V_18 ? * V_18 : V_31 -> V_18 ;
V_39 . V_93 = V_3 -> V_64 ;
V_39 . V_94 = V_3 -> V_95 ;
V_39 . V_96 = V_25 -> V_78 ;
V_39 . V_97 = V_27 -> V_98 ;
V_39 . V_99 = V_3 -> V_100 ;
V_37 = F_31 ( V_31 -> V_37 , F_32 ( V_3 ) ) ;
V_34 = F_33 ( & V_39 , V_37 , & V_35 ) ;
F_34 ( V_3 , F_35 ( & V_39 ) ) ;
V_9 = F_36 ( V_3 , & V_39 , V_34 ) ;
if ( F_37 ( V_9 ) ) {
V_41 = F_38 ( V_9 ) ;
goto V_90;
}
if ( ! V_18 ) {
V_18 = & V_39 . V_18 ;
V_3 -> V_57 = * V_18 ;
}
V_31 -> V_18 = * V_18 ;
V_27 -> V_101 = V_102 ;
V_3 -> V_103 = V_104 ;
F_39 ( V_3 , V_9 , NULL , NULL ) ;
V_29 -> V_73 = 0 ;
if ( V_37 )
V_29 -> V_73 = V_37 -> V_105 +
V_37 -> V_106 ;
V_33 -> V_65 . V_107 = V_108 - sizeof( struct V_109 ) - sizeof( struct V_110 ) ;
V_27 -> V_111 = V_25 -> V_78 ;
F_40 ( V_3 , V_112 ) ;
V_41 = F_41 ( V_43 , V_3 ) ;
if ( V_41 )
goto V_113;
F_42 ( V_3 ) ;
if ( F_43 ( ! V_33 -> V_114 ) ) {
if ( ! V_33 -> V_69 )
V_33 -> V_69 = F_9 ( V_31 -> V_18 . V_17 ,
V_3 -> V_67 . V_17 ,
V_27 -> V_98 ,
V_27 -> V_111 ) ;
V_33 -> V_115 = F_13 ( V_31 -> V_18 . V_17 ,
V_3 -> V_67 . V_17 ) ;
}
if ( F_44 ( V_3 , & V_41 ) )
return V_41 ;
if ( V_41 )
goto V_113;
V_41 = F_45 ( V_3 ) ;
if ( V_41 )
goto V_113;
return 0 ;
V_113:
F_40 ( V_3 , V_116 ) ;
V_90:
V_27 -> V_111 = 0 ;
V_3 -> V_117 = 0 ;
return V_41 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_118 ) & ( V_119 | V_120 ) )
return;
V_9 = F_47 ( V_3 , F_16 ( V_3 ) -> V_121 ) ;
if ( ! V_9 )
return;
if ( F_15 ( V_3 ) -> V_122 > F_48 ( V_9 ) ) {
F_49 ( V_3 , F_48 ( V_9 ) ) ;
F_50 ( V_3 ) ;
}
}
static void F_51 ( struct V_6 * V_7 , struct V_123 * V_37 ,
T_2 type , T_2 V_124 , int V_125 , T_3 V_126 )
{
const struct V_110 * V_127 = ( const struct V_110 * ) V_7 -> V_128 ;
const struct V_109 * V_129 = (struct V_109 * ) ( V_7 -> V_128 + V_125 ) ;
struct V_130 * V_130 = F_52 ( V_7 -> V_131 ) ;
struct V_132 * V_133 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_4 V_134 , V_135 ;
struct V_2 * V_3 ;
bool V_136 ;
int V_41 ;
V_3 = F_53 ( V_130 , & V_137 ,
& V_127 -> V_16 , V_129 -> V_19 ,
& V_127 -> V_18 , F_54 ( V_129 -> V_20 ) ,
V_7 -> V_131 -> V_138 ) ;
if ( ! V_3 ) {
F_55 ( V_130 , F_56 ( V_7 -> V_131 ) ,
V_139 ) ;
return;
}
if ( V_3 -> V_118 == V_140 ) {
F_57 ( F_58 ( V_3 ) ) ;
return;
}
V_134 = F_59 ( V_129 -> V_134 ) ;
V_136 = F_60 ( type , V_124 , & V_41 ) ;
if ( V_3 -> V_118 == V_141 )
return F_61 ( V_3 , V_134 , V_136 ) ;
F_62 ( V_3 ) ;
if ( F_63 ( V_3 ) && type != V_142 )
F_64 ( V_130 , V_143 ) ;
if ( V_3 -> V_118 == V_116 )
goto V_144;
if ( F_10 ( V_7 ) -> V_145 < F_6 ( V_3 ) -> V_146 ) {
F_64 ( V_130 , V_147 ) ;
goto V_144;
}
V_33 = F_16 ( V_3 ) ;
V_133 = V_33 -> V_148 ;
V_135 = V_133 ? F_65 ( V_133 ) -> V_149 : V_33 -> V_135 ;
if ( V_3 -> V_118 != V_150 &&
! F_66 ( V_134 , V_135 , V_33 -> V_151 ) ) {
F_64 ( V_130 , V_152 ) ;
goto V_144;
}
V_31 = F_6 ( V_3 ) ;
if ( type == V_153 ) {
if ( ! F_63 ( V_3 ) ) {
struct V_8 * V_9 = F_67 ( V_3 , V_31 -> V_154 ) ;
if ( V_9 )
V_9 -> V_155 -> V_156 ( V_9 , V_3 , V_7 ) ;
}
goto V_144;
}
if ( type == V_142 ) {
if ( V_3 -> V_118 == V_150 )
goto V_144;
if ( ! F_68 ( V_3 ) )
goto V_144;
V_33 -> V_121 = F_59 ( V_126 ) ;
if ( ! F_63 ( V_3 ) )
F_46 ( V_3 ) ;
else if ( ! F_69 ( V_157 ,
& V_3 -> V_158 ) )
F_70 ( V_3 ) ;
goto V_144;
}
switch ( V_3 -> V_118 ) {
case V_112 :
case V_159 :
if ( V_133 && ! V_133 -> V_3 )
break;
if ( ! F_63 ( V_3 ) ) {
V_3 -> V_160 = V_41 ;
V_3 -> V_161 ( V_3 ) ;
F_71 ( V_3 ) ;
} else
V_3 -> V_162 = V_41 ;
goto V_144;
}
if ( ! F_63 ( V_3 ) && V_31 -> V_163 ) {
V_3 -> V_160 = V_41 ;
V_3 -> V_161 ( V_3 ) ;
} else
V_3 -> V_162 = V_41 ;
V_144:
F_72 ( V_3 ) ;
F_73 ( V_3 ) ;
}
static int F_74 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_164 * V_165 ,
struct V_132 * V_166 ,
struct V_167 * V_168 ,
enum V_169 V_170 )
{
struct V_171 * V_172 = F_75 ( V_166 ) ;
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_38 * V_39 = & V_165 -> V_173 . V_174 ;
struct V_6 * V_7 ;
int V_41 = - V_175 ;
if ( ! V_9 && ( V_9 = F_76 ( V_3 , V_39 , V_166 ,
V_92 ) ) == NULL )
goto V_176;
V_7 = F_77 ( V_3 , V_9 , V_166 , V_168 , V_170 ) ;
if ( V_7 ) {
F_78 ( V_7 , & V_172 -> V_177 ,
& V_172 -> V_178 ) ;
V_39 -> V_16 = V_172 -> V_178 ;
if ( V_31 -> V_179 && V_172 -> V_180 )
V_39 -> V_51 = V_55 ( F_10 ( V_172 -> V_180 ) ) ;
F_79 () ;
V_37 = V_172 -> V_181 ;
if ( ! V_37 )
V_37 = F_80 ( V_31 -> V_37 ) ;
V_41 = F_81 ( V_3 , V_7 , V_39 , V_3 -> V_95 , V_37 , V_31 -> V_182 ) ;
F_82 () ;
V_41 = F_83 ( V_41 ) ;
}
V_176:
return V_41 ;
}
static void F_84 ( struct V_132 * V_166 )
{
F_85 ( F_75 ( V_166 ) -> V_181 ) ;
F_86 ( F_75 ( V_166 ) -> V_180 ) ;
}
static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_87 ( V_3 , (union V_183 * ) V_5 , V_48 ) ;
}
static struct V_1 * F_88 ( const struct V_2 * V_3 ,
const struct V_2 * V_184 )
{
return F_1 ( V_3 , & V_184 -> V_67 ) ;
}
static int F_89 ( struct V_2 * V_3 , char T_5 * V_185 ,
int V_186 )
{
struct V_187 V_188 ;
struct V_24 * V_189 = (struct V_24 * ) & V_188 . V_190 ;
if ( V_186 < sizeof( V_188 ) )
return - V_46 ;
if ( F_90 ( & V_188 , V_185 , sizeof( V_188 ) ) )
return - V_191 ;
if ( V_189 -> V_47 != V_48 )
return - V_46 ;
if ( ! V_188 . V_192 ) {
if ( F_22 ( & V_189 -> V_56 ) )
return F_91 ( V_3 , (union V_183 * ) & V_189 -> V_56 . V_17 [ 3 ] ,
V_76 ) ;
return F_91 ( V_3 , (union V_183 * ) & V_189 -> V_56 ,
V_48 ) ;
}
if ( V_188 . V_192 > V_193 )
return - V_46 ;
if ( F_22 ( & V_189 -> V_56 ) )
return F_92 ( V_3 , (union V_183 * ) & V_189 -> V_56 . V_17 [ 3 ] ,
V_76 , V_188 . V_194 , V_188 . V_192 , V_195 ) ;
return F_92 ( V_3 , (union V_183 * ) & V_189 -> V_56 ,
V_48 , V_188 . V_194 , V_188 . V_192 , V_195 ) ;
}
static int F_93 ( struct V_196 * V_197 ,
const struct V_4 * V_16 ,
const struct V_4 * V_18 ,
const struct V_109 * V_129 , int V_198 )
{
struct V_199 * V_200 ;
struct V_201 V_202 ;
struct V_109 * V_203 ;
V_200 = V_197 -> V_204 ;
V_200 -> V_18 = * V_18 ;
V_200 -> V_16 = * V_16 ;
V_200 -> V_205 = F_94 ( V_92 ) ;
V_200 -> V_206 = F_94 ( V_198 ) ;
V_203 = (struct V_109 * ) ( V_200 + 1 ) ;
memcpy ( V_203 , V_129 , sizeof( * V_129 ) ) ;
V_203 -> V_207 = 0 ;
F_95 ( & V_202 , V_200 , sizeof( * V_200 ) + sizeof( * V_129 ) ) ;
F_96 ( V_197 -> V_208 , & V_202 , NULL ,
sizeof( * V_200 ) + sizeof( * V_129 ) ) ;
return F_97 ( V_197 -> V_208 ) ;
}
static int F_98 ( char * V_209 , const struct V_1 * V_210 ,
const struct V_4 * V_16 , struct V_4 * V_18 ,
const struct V_109 * V_129 )
{
struct V_196 * V_197 ;
struct V_211 * V_166 ;
V_197 = F_99 () ;
if ( ! V_197 )
goto V_212;
V_166 = V_197 -> V_208 ;
if ( F_100 ( V_166 ) )
goto V_213;
if ( F_93 ( V_197 , V_16 , V_18 , V_129 , V_129 -> V_214 << 2 ) )
goto V_213;
if ( F_101 ( V_197 , V_210 ) )
goto V_213;
F_96 ( V_166 , NULL , V_209 , 0 ) ;
if ( F_102 ( V_166 ) )
goto V_213;
F_103 () ;
return 0 ;
V_213:
F_103 () ;
V_212:
memset ( V_209 , 0 , 16 ) ;
return 1 ;
}
static int F_104 ( char * V_209 ,
const struct V_1 * V_210 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_18 , * V_16 ;
struct V_196 * V_197 ;
struct V_211 * V_166 ;
const struct V_109 * V_129 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_18 = & V_3 -> V_57 ;
V_16 = & V_3 -> V_67 ;
} else {
const struct V_110 * V_215 = F_10 ( V_7 ) ;
V_18 = & V_215 -> V_18 ;
V_16 = & V_215 -> V_16 ;
}
V_197 = F_99 () ;
if ( ! V_197 )
goto V_212;
V_166 = V_197 -> V_208 ;
if ( F_100 ( V_166 ) )
goto V_213;
if ( F_93 ( V_197 , V_16 , V_18 , V_129 , V_7 -> V_206 ) )
goto V_213;
if ( F_105 ( V_197 , V_7 , V_129 -> V_214 << 2 ) )
goto V_213;
if ( F_101 ( V_197 , V_210 ) )
goto V_213;
F_96 ( V_166 , NULL , V_209 , 0 ) ;
if ( F_102 ( V_166 ) )
goto V_213;
F_103 () ;
return 0 ;
V_213:
F_103 () ;
V_212:
memset ( V_209 , 0 , 16 ) ;
return 1 ;
}
static bool F_106 ( const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
#ifdef F_29
const T_6 * V_216 = NULL ;
struct V_1 * V_217 ;
const struct V_110 * V_215 = F_10 ( V_7 ) ;
const struct V_109 * V_129 = F_11 ( V_7 ) ;
int V_218 ;
T_2 V_219 [ 16 ] ;
V_217 = F_1 ( V_3 , & V_215 -> V_18 ) ;
V_216 = F_107 ( V_129 ) ;
if ( ! V_217 && ! V_216 )
return false ;
if ( V_217 && ! V_216 ) {
F_108 ( F_17 ( V_3 ) , V_220 ) ;
return true ;
}
if ( ! V_217 && V_216 ) {
F_108 ( F_17 ( V_3 ) , V_221 ) ;
return true ;
}
V_218 = F_104 ( V_219 ,
V_217 ,
NULL , V_7 ) ;
if ( V_218 || memcmp ( V_216 , V_219 , 16 ) != 0 ) {
F_108 ( F_17 ( V_3 ) , V_222 ) ;
F_109 ( L_2 ,
V_218 ? L_3 : L_4 ,
& V_215 -> V_18 , F_54 ( V_129 -> V_20 ) ,
& V_215 -> V_16 , F_54 ( V_129 -> V_19 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_110 ( struct V_132 * V_166 ,
const struct V_2 * V_223 ,
struct V_6 * V_7 )
{
struct V_171 * V_172 = F_75 ( V_166 ) ;
const struct V_30 * V_31 = F_6 ( V_223 ) ;
V_172 -> V_178 = F_10 ( V_7 ) -> V_18 ;
V_172 -> V_177 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_223 -> V_64 &&
F_25 ( & V_172 -> V_178 ) & V_62 )
V_172 -> V_224 = F_111 ( V_7 ) ;
if ( ! F_112 ( V_7 ) -> V_225 &&
( F_113 ( V_223 , V_7 , & F_112 ( V_7 ) -> V_226 . V_227 ) ||
V_31 -> V_228 . V_229 . V_230 ||
V_31 -> V_228 . V_229 . V_231 || V_31 -> V_228 . V_229 . V_232 ||
V_31 -> V_228 . V_229 . V_233 || V_31 -> V_179 ) ) {
F_114 ( & V_7 -> V_234 ) ;
V_172 -> V_180 = V_7 ;
}
}
static struct V_8 * F_115 ( const struct V_2 * V_3 ,
struct V_164 * V_165 ,
const struct V_132 * V_166 )
{
return F_76 ( V_3 , & V_165 -> V_173 . V_174 , V_166 , V_92 ) ;
}
static void F_116 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_134 ,
T_1 V_235 , T_1 V_236 , T_1 V_237 , T_1 V_238 ,
int V_239 , struct V_1 * V_210 , int V_240 ,
T_2 V_182 , T_3 V_241 )
{
const struct V_109 * V_129 = F_11 ( V_7 ) ;
struct V_109 * V_242 ;
struct V_6 * V_243 ;
struct V_38 V_39 ;
struct V_130 * V_130 = V_3 ? F_17 ( V_3 ) : F_52 ( F_3 ( V_7 ) -> V_131 ) ;
struct V_2 * V_244 = V_130 -> V_245 . F_16 ;
unsigned int V_246 = sizeof( struct V_109 ) ;
struct V_8 * V_9 ;
T_3 * V_247 ;
if ( V_238 )
V_246 += V_248 ;
#ifdef F_29
if ( V_210 )
V_246 += V_249 ;
#endif
V_243 = F_117 ( V_250 + sizeof( struct V_110 ) + V_246 ,
V_251 ) ;
if ( ! V_243 )
return;
F_118 ( V_243 , V_250 + sizeof( struct V_110 ) + V_246 ) ;
V_242 = (struct V_109 * ) F_119 ( V_243 , V_246 ) ;
F_120 ( V_243 ) ;
memset ( V_242 , 0 , sizeof( * V_242 ) ) ;
V_242 -> V_19 = V_129 -> V_20 ;
V_242 -> V_20 = V_129 -> V_19 ;
V_242 -> V_214 = V_246 / 4 ;
V_242 -> V_134 = F_24 ( V_134 ) ;
V_242 -> V_252 = F_24 ( V_235 ) ;
V_242 -> V_235 = ! V_240 || ! V_129 -> V_235 ;
V_242 -> V_240 = V_240 ;
V_242 -> V_253 = F_121 ( V_236 ) ;
V_247 = ( T_3 * ) ( V_242 + 1 ) ;
if ( V_238 ) {
* V_247 ++ = F_24 ( ( V_254 << 24 ) | ( V_254 << 16 ) |
( V_255 << 8 ) | V_256 ) ;
* V_247 ++ = F_24 ( V_237 ) ;
* V_247 ++ = F_24 ( V_238 ) ;
}
#ifdef F_29
if ( V_210 ) {
* V_247 ++ = F_24 ( ( V_254 << 24 ) | ( V_254 << 16 ) |
( V_257 << 8 ) | V_258 ) ;
F_98 ( ( T_6 * ) V_247 , V_210 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , V_242 ) ;
}
#endif
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_16 = F_10 ( V_7 ) -> V_18 ;
V_39 . V_18 = F_10 ( V_7 ) -> V_16 ;
V_39 . V_51 = V_241 ;
V_243 -> V_259 = V_260 ;
V_243 -> V_261 = 0 ;
F_78 ( V_243 , & V_39 . V_18 , & V_39 . V_16 ) ;
V_39 . V_91 = V_92 ;
if ( F_122 ( & V_39 . V_16 ) && ! V_239 )
V_39 . V_93 = F_111 ( V_7 ) ;
else {
if ( ! V_239 && F_123 ( V_130 , V_7 -> V_14 ) )
V_239 = V_7 -> V_14 ;
V_39 . V_93 = V_239 ;
}
V_39 . V_94 = F_124 ( V_130 , V_7 -> V_262 ) ;
V_39 . V_96 = V_242 -> V_19 ;
V_39 . V_97 = V_242 -> V_20 ;
V_39 . V_99 = F_125 ( V_130 , V_3 && F_126 ( V_3 ) ? V_3 : NULL ) ;
F_127 ( V_7 , F_35 ( & V_39 ) ) ;
V_9 = F_36 ( V_244 , & V_39 , NULL ) ;
if ( ! F_37 ( V_9 ) ) {
F_128 ( V_243 , V_9 ) ;
F_81 ( V_244 , V_243 , & V_39 , V_39 . V_94 , NULL , V_182 ) ;
F_129 ( V_130 , V_263 ) ;
if ( V_240 )
F_129 ( V_130 , V_264 ) ;
return;
}
F_86 ( V_243 ) ;
}
static void F_130 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_109 * V_129 = F_11 ( V_7 ) ;
T_1 V_134 = 0 , V_252 = 0 ;
struct V_1 * V_210 = NULL ;
#ifdef F_29
const T_6 * V_216 = NULL ;
struct V_110 * V_265 = F_10 ( V_7 ) ;
unsigned char V_219 [ 16 ] ;
int V_218 ;
struct V_2 * V_266 = NULL ;
#endif
int V_239 ;
if ( V_129 -> V_240 )
return;
if ( ! V_3 && ! F_131 ( V_7 ) )
return;
#ifdef F_29
F_79 () ;
V_216 = F_107 ( V_129 ) ;
if ( V_3 && F_126 ( V_3 ) ) {
V_210 = F_1 ( V_3 , & V_265 -> V_18 ) ;
} else if ( V_216 ) {
V_266 = F_132 ( F_52 ( F_3 ( V_7 ) -> V_131 ) ,
& V_137 , NULL , 0 ,
& V_265 -> V_18 ,
V_129 -> V_20 , & V_265 -> V_16 ,
F_54 ( V_129 -> V_20 ) , F_111 ( V_7 ) ) ;
if ( ! V_266 )
goto V_144;
V_210 = F_1 ( V_266 , & V_265 -> V_18 ) ;
if ( ! V_210 )
goto V_144;
V_218 = F_104 ( V_219 , V_210 , NULL , V_7 ) ;
if ( V_218 || memcmp ( V_216 , V_219 , 16 ) != 0 )
goto V_144;
}
#endif
if ( V_129 -> V_235 )
V_134 = F_59 ( V_129 -> V_252 ) ;
else
V_252 = F_59 ( V_129 -> V_134 ) + V_129 -> V_267 + V_129 -> V_268 + V_7 -> V_206 -
( V_129 -> V_214 << 2 ) ;
V_239 = V_3 ? V_3 -> V_64 : 0 ;
F_116 ( V_3 , V_7 , V_134 , V_252 , 0 , 0 , 0 , V_239 , V_210 , 1 , 0 , 0 ) ;
#ifdef F_29
V_144:
F_82 () ;
#endif
}
static void F_133 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_134 ,
T_1 V_235 , T_1 V_236 , T_1 V_237 , T_1 V_238 , int V_239 ,
struct V_1 * V_210 , T_2 V_182 ,
T_3 V_241 )
{
F_116 ( V_3 , V_7 , V_134 , V_235 , V_236 , V_237 , V_238 , V_239 , V_210 , 0 ,
V_182 , V_241 ) ;
}
static void F_134 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_269 * V_270 = F_58 ( V_3 ) ;
struct V_271 * V_272 = F_135 ( V_3 ) ;
F_133 ( V_3 , V_7 , V_272 -> V_273 , V_272 -> V_274 ,
V_272 -> V_275 >> V_270 -> V_276 ,
V_277 + V_272 -> V_278 ,
V_272 -> V_279 , V_270 -> V_280 , F_136 ( V_272 ) ,
V_270 -> V_281 , F_94 ( V_270 -> V_282 ) ) ;
F_57 ( V_270 ) ;
}
static void F_137 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_132 * V_166 )
{
F_133 ( V_3 , V_7 , ( V_3 -> V_118 == V_150 ) ?
F_65 ( V_166 ) -> V_149 + 1 : F_16 ( V_3 ) -> V_151 ,
F_65 ( V_166 ) -> V_283 ,
V_166 -> V_284 >> F_75 ( V_166 ) -> V_285 ,
V_277 + F_65 ( V_166 ) -> V_286 ,
V_166 -> V_68 , V_3 -> V_64 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_138 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_139
const struct V_109 * V_129 = F_11 ( V_7 ) ;
if ( ! V_129 -> V_267 )
V_3 = F_140 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_141 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_205 == F_121 ( V_287 ) )
return F_142 ( V_3 , V_7 ) ;
if ( ! F_131 ( V_7 ) )
goto V_288;
return F_143 ( & V_289 ,
& V_290 , V_3 , V_7 ) ;
V_288:
F_144 ( V_3 ) ;
return 0 ;
}
static void F_145 ( struct V_6 * V_7 )
{
memmove ( F_146 ( V_7 ) , & F_112 ( V_7 ) -> V_226 . V_227 ,
sizeof( struct V_123 ) ) ;
}
static struct V_2 * F_147 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_132 * V_166 ,
struct V_8 * V_9 ,
struct V_132 * V_291 ,
bool * V_292 )
{
struct V_171 * V_172 ;
struct V_30 * V_293 ;
const struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_294 * V_295 ;
struct V_26 * V_296 ;
struct V_32 * V_297 ;
struct V_2 * V_298 ;
#ifdef F_29
struct V_1 * V_210 ;
#endif
struct V_38 V_39 ;
if ( V_7 -> V_205 == F_121 ( V_287 ) ) {
V_298 = F_148 ( V_3 , V_7 , V_166 , V_9 ,
V_291 , V_292 ) ;
if ( ! V_298 )
return NULL ;
V_295 = (struct V_294 * ) V_298 ;
F_5 ( V_298 ) -> V_299 = & V_295 -> V_300 ;
V_296 = F_5 ( V_298 ) ;
V_293 = F_6 ( V_298 ) ;
V_297 = F_16 ( V_298 ) ;
memcpy ( V_293 , V_31 , sizeof( struct V_30 ) ) ;
V_293 -> V_18 = V_298 -> V_57 ;
F_15 ( V_298 ) -> V_81 = & V_82 ;
V_298 -> V_83 = V_84 ;
#ifdef F_29
V_297 -> V_85 = & V_86 ;
#endif
V_293 -> V_301 = NULL ;
V_293 -> V_302 = NULL ;
V_293 -> V_303 = NULL ;
V_293 -> V_304 = NULL ;
V_293 -> V_37 = NULL ;
V_293 -> V_305 = F_111 ( V_7 ) ;
V_293 -> V_306 = F_10 ( V_7 ) -> V_145 ;
V_293 -> V_307 = F_149 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_179 )
V_293 -> V_70 = V_55 ( F_10 ( V_7 ) ) ;
F_49 ( V_298 , F_15 ( V_298 ) -> V_122 ) ;
return V_298 ;
}
V_172 = F_75 ( V_166 ) ;
if ( F_150 ( V_3 ) )
goto V_308;
if ( ! V_9 ) {
V_9 = F_76 ( V_3 , & V_39 , V_166 , V_92 ) ;
if ( ! V_9 )
goto V_144;
}
V_298 = F_151 ( V_3 , V_166 , V_7 ) ;
if ( ! V_298 )
goto V_309;
V_298 -> V_103 = V_104 ;
F_39 ( V_298 , V_9 , NULL , NULL ) ;
F_2 ( V_298 , V_7 ) ;
V_295 = (struct V_294 * ) V_298 ;
F_5 ( V_298 ) -> V_299 = & V_295 -> V_300 ;
V_297 = F_16 ( V_298 ) ;
V_296 = F_5 ( V_298 ) ;
V_293 = F_6 ( V_298 ) ;
memcpy ( V_293 , V_31 , sizeof( struct V_30 ) ) ;
V_298 -> V_67 = V_172 -> V_178 ;
V_293 -> V_18 = V_172 -> V_177 ;
V_298 -> V_57 = V_172 -> V_177 ;
V_298 -> V_64 = V_172 -> V_224 ;
V_296 -> V_310 = NULL ;
V_293 -> V_301 = NULL ;
V_293 -> V_302 = NULL ;
V_293 -> V_303 = NULL ;
V_293 -> V_228 . V_311 = V_31 -> V_228 . V_311 ;
V_293 -> V_304 = NULL ;
V_293 -> V_37 = NULL ;
V_293 -> V_305 = F_111 ( V_7 ) ;
V_293 -> V_306 = F_10 ( V_7 ) -> V_145 ;
V_293 -> V_307 = F_149 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_179 )
V_293 -> V_70 = V_55 ( F_10 ( V_7 ) ) ;
V_37 = V_172 -> V_181 ;
if ( ! V_37 )
V_37 = F_80 ( V_31 -> V_37 ) ;
if ( V_37 ) {
V_37 = F_152 ( V_298 , V_37 ) ;
F_153 ( V_293 -> V_37 , V_37 ) ;
}
F_15 ( V_298 ) -> V_73 = 0 ;
if ( V_37 )
F_15 ( V_298 ) -> V_73 = V_37 -> V_106 +
V_37 -> V_105 ;
F_154 ( V_298 , V_9 ) ;
F_49 ( V_298 , F_48 ( V_9 ) ) ;
V_297 -> V_312 = F_155 ( F_16 ( V_3 ) , F_156 ( V_9 ) ) ;
F_157 ( V_298 ) ;
V_296 -> V_313 = V_296 -> V_314 = V_102 ;
V_296 -> V_101 = V_102 ;
#ifdef F_29
V_210 = F_1 ( V_3 , & V_298 -> V_67 ) ;
if ( V_210 ) {
F_92 ( V_298 , (union V_183 * ) & V_298 -> V_67 ,
V_48 , V_210 -> V_210 , V_210 -> V_315 ,
F_158 ( V_3 , V_251 ) ) ;
}
#endif
if ( F_159 ( V_3 , V_298 ) < 0 ) {
F_160 ( V_298 ) ;
F_71 ( V_298 ) ;
goto V_144;
}
* V_292 = F_161 ( V_298 , F_162 ( V_291 ) ) ;
if ( * V_292 ) {
F_163 ( V_297 , V_166 ) ;
if ( V_172 -> V_180 ) {
V_293 -> V_304 = F_164 ( V_172 -> V_180 ,
F_158 ( V_3 , V_251 ) ) ;
F_165 ( V_172 -> V_180 ) ;
V_172 -> V_180 = NULL ;
if ( V_293 -> V_304 ) {
F_145 ( V_293 -> V_304 ) ;
F_166 ( V_293 -> V_304 , V_298 ) ;
}
}
}
return V_298 ;
V_308:
F_64 ( F_17 ( V_3 ) , V_316 ) ;
V_309:
F_167 ( V_9 ) ;
V_144:
F_144 ( V_3 ) ;
return NULL ;
}
static int V_88 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_6 * V_317 = NULL ;
if ( V_7 -> V_205 == F_121 ( V_287 ) )
return V_84 ( V_3 , V_7 ) ;
if ( F_168 ( V_3 , V_7 ) )
goto V_318;
if ( V_31 -> V_228 . V_311 )
V_317 = F_164 ( V_7 , F_158 ( V_3 , V_251 ) ) ;
if ( V_3 -> V_118 == V_319 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_169 ( V_3 , V_7 ) ;
F_170 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_155 -> V_207 ( V_9 , V_31 -> V_15 ) == NULL ) {
F_167 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_171 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_206 ) ;
if ( V_317 )
goto V_320;
return 0 ;
}
if ( F_172 ( V_7 ) )
goto V_321;
if ( V_3 -> V_118 == V_150 ) {
struct V_2 * V_322 = F_138 ( V_3 , V_7 ) ;
if ( ! V_322 )
goto V_318;
if ( V_322 != V_3 ) {
if ( F_173 ( V_3 , V_322 , V_7 ) )
goto V_323;
if ( V_317 )
F_174 ( V_317 ) ;
return 0 ;
}
} else
F_169 ( V_3 , V_7 ) ;
if ( F_175 ( V_3 , V_7 ) )
goto V_323;
if ( V_317 )
goto V_320;
return 0 ;
V_323:
F_130 ( V_3 , V_7 ) ;
V_318:
if ( V_317 )
F_174 ( V_317 ) ;
F_86 ( V_7 ) ;
return 0 ;
V_321:
F_129 ( F_17 ( V_3 ) , V_324 ) ;
F_129 ( F_17 ( V_3 ) , V_325 ) ;
goto V_318;
V_320:
V_33 = F_16 ( V_3 ) ;
if ( F_112 ( V_317 ) -> V_326 == V_33 -> V_283 &&
! ( ( 1 << V_3 -> V_118 ) & ( V_120 | V_119 ) ) ) {
if ( V_31 -> V_228 . V_229 . V_230 || V_31 -> V_228 . V_229 . V_231 )
V_31 -> V_305 = F_111 ( V_317 ) ;
if ( V_31 -> V_228 . V_229 . V_232 || V_31 -> V_228 . V_229 . V_233 )
V_31 -> V_306 = F_10 ( V_317 ) -> V_145 ;
if ( V_31 -> V_228 . V_229 . V_327 || V_31 -> V_228 . V_229 . V_328 )
V_31 -> V_307 = F_149 ( F_10 ( V_317 ) ) ;
if ( V_31 -> V_179 )
V_31 -> V_70 = V_55 ( F_10 ( V_317 ) ) ;
if ( F_113 ( V_3 , V_317 , & F_112 ( V_317 ) -> V_226 . V_227 ) ) {
F_166 ( V_317 , V_3 ) ;
F_145 ( V_317 ) ;
V_317 = F_176 ( & V_31 -> V_304 , V_317 ) ;
} else {
F_174 ( V_317 ) ;
V_317 = F_176 ( & V_31 -> V_304 , NULL ) ;
}
}
F_86 ( V_317 ) ;
return 0 ;
}
static void F_177 ( struct V_6 * V_7 , const struct V_110 * V_127 ,
const struct V_109 * V_129 )
{
memmove ( & F_112 ( V_7 ) -> V_226 . V_227 , F_146 ( V_7 ) ,
sizeof( struct V_123 ) ) ;
F_178 () ;
F_112 ( V_7 ) -> V_134 = F_59 ( V_129 -> V_134 ) ;
F_112 ( V_7 ) -> V_326 = ( F_112 ( V_7 ) -> V_134 + V_129 -> V_267 + V_129 -> V_268 +
V_7 -> V_206 - V_129 -> V_214 * 4 ) ;
F_112 ( V_7 ) -> V_252 = F_59 ( V_129 -> V_252 ) ;
F_112 ( V_7 ) -> V_329 = F_179 ( V_129 ) ;
F_112 ( V_7 ) -> V_225 = 0 ;
F_112 ( V_7 ) -> V_330 = F_180 ( V_127 ) ;
F_112 ( V_7 ) -> V_331 = 0 ;
}
static int F_181 ( struct V_6 * V_7 )
{
const struct V_109 * V_129 ;
const struct V_110 * V_127 ;
bool V_332 ;
struct V_2 * V_3 ;
int V_333 ;
struct V_130 * V_130 = F_52 ( V_7 -> V_131 ) ;
if ( V_7 -> V_334 != V_335 )
goto V_336;
F_182 ( V_130 , V_337 ) ;
if ( ! F_183 ( V_7 , sizeof( struct V_109 ) ) )
goto V_336;
V_129 = ( const struct V_109 * ) V_7 -> V_128 ;
if ( F_184 ( V_129 -> V_214 < sizeof( struct V_109 ) / 4 ) )
goto V_338;
if ( ! F_183 ( V_7 , V_129 -> V_214 * 4 ) )
goto V_336;
if ( F_185 ( V_7 , V_92 , V_339 ) )
goto V_340;
V_129 = ( const struct V_109 * ) V_7 -> V_128 ;
V_127 = F_10 ( V_7 ) ;
V_341:
V_3 = F_186 ( & V_137 , V_7 , F_187 ( V_129 ) ,
V_129 -> V_20 , V_129 -> V_19 , F_188 ( V_7 ) ,
& V_332 ) ;
if ( ! V_3 )
goto V_342;
V_343:
if ( V_3 -> V_118 == V_140 )
goto V_344;
if ( V_3 -> V_118 == V_141 ) {
struct V_132 * V_166 = F_189 ( V_3 ) ;
struct V_2 * V_322 ;
V_3 = V_166 -> V_345 ;
F_177 ( V_7 , V_127 , V_129 ) ;
if ( F_106 ( V_3 , V_7 ) ) {
F_190 ( V_3 , V_7 ) ;
F_191 ( V_166 ) ;
goto V_336;
}
if ( F_184 ( V_3 -> V_118 != V_150 ) ) {
F_192 ( V_3 , V_166 ) ;
goto V_341;
}
F_70 ( V_3 ) ;
V_332 = true ;
V_322 = F_193 ( V_3 , V_7 , V_166 , false ) ;
if ( ! V_322 ) {
F_191 ( V_166 ) ;
goto V_346;
}
if ( V_322 == V_3 ) {
F_191 ( V_166 ) ;
F_145 ( V_7 ) ;
} else if ( F_173 ( V_3 , V_322 , V_7 ) ) {
F_130 ( V_322 , V_7 ) ;
goto V_346;
} else {
F_73 ( V_3 ) ;
return 0 ;
}
}
if ( V_127 -> V_145 < F_6 ( V_3 ) -> V_146 ) {
F_64 ( V_130 , V_147 ) ;
goto V_346;
}
if ( ! F_194 ( V_3 , V_347 , V_7 ) )
goto V_346;
F_177 ( V_7 , V_127 , V_129 ) ;
if ( F_106 ( V_3 , V_7 ) )
goto V_346;
if ( F_168 ( V_3 , V_7 ) )
goto V_346;
V_129 = ( const struct V_109 * ) V_7 -> V_128 ;
V_127 = F_10 ( V_7 ) ;
V_7 -> V_131 = NULL ;
if ( V_3 -> V_118 == V_150 ) {
V_333 = V_88 ( V_3 , V_7 ) ;
goto V_348;
}
F_195 ( V_3 ) ;
F_196 ( V_3 ) ;
F_197 ( F_16 ( V_3 ) , V_7 ) ;
V_333 = 0 ;
if ( ! F_63 ( V_3 ) ) {
if ( ! F_198 ( V_3 , V_7 ) )
V_333 = V_88 ( V_3 , V_7 ) ;
} else if ( F_199 ( V_3 , V_7 ) ) {
goto V_346;
}
F_72 ( V_3 ) ;
V_348:
if ( V_332 )
F_73 ( V_3 ) ;
return V_333 ? - 1 : 0 ;
V_342:
if ( ! F_194 ( NULL , V_347 , V_7 ) )
goto V_336;
F_177 ( V_7 , V_127 , V_129 ) ;
if ( F_172 ( V_7 ) ) {
V_340:
F_182 ( V_130 , V_324 ) ;
V_338:
F_182 ( V_130 , V_325 ) ;
} else {
F_130 ( NULL , V_7 ) ;
}
V_336:
F_86 ( V_7 ) ;
return 0 ;
V_346:
F_190 ( V_3 , V_7 ) ;
if ( V_332 )
F_73 ( V_3 ) ;
goto V_336;
V_344:
if ( ! F_194 ( NULL , V_347 , V_7 ) ) {
F_57 ( F_58 ( V_3 ) ) ;
goto V_336;
}
F_177 ( V_7 , V_127 , V_129 ) ;
if ( F_172 ( V_7 ) ) {
F_57 ( F_58 ( V_3 ) ) ;
goto V_340;
}
switch ( F_200 ( F_58 ( V_3 ) , V_7 , V_129 ) ) {
case V_349 :
{
struct V_2 * V_350 ;
V_350 = F_132 ( F_52 ( V_7 -> V_131 ) , & V_137 ,
V_7 , F_187 ( V_129 ) ,
& F_10 ( V_7 ) -> V_18 , V_129 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_54 ( V_129 -> V_19 ) , F_111 ( V_7 ) ) ;
if ( V_350 ) {
struct V_269 * V_270 = F_58 ( V_3 ) ;
F_201 ( V_270 ) ;
V_3 = V_350 ;
F_145 ( V_7 ) ;
V_332 = false ;
goto V_343;
}
}
case V_351 :
F_134 ( V_3 , V_7 ) ;
break;
case V_352 :
F_145 ( V_7 ) ;
F_130 ( V_3 , V_7 ) ;
F_201 ( F_58 ( V_3 ) ) ;
goto V_336;
case V_353 :
;
}
goto V_336;
}
static void F_202 ( struct V_6 * V_7 )
{
const struct V_110 * V_127 ;
const struct V_109 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_334 != V_335 )
return;
if ( ! F_183 ( V_7 , F_203 ( V_7 ) + sizeof( struct V_109 ) ) )
return;
V_127 = F_10 ( V_7 ) ;
V_129 = F_11 ( V_7 ) ;
if ( V_129 -> V_214 < sizeof( struct V_109 ) / 4 )
return;
V_3 = F_53 ( F_52 ( V_7 -> V_131 ) , & V_137 ,
& V_127 -> V_18 , V_129 -> V_20 ,
& V_127 -> V_16 , F_54 ( V_129 -> V_19 ) ,
F_188 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_354 = V_355 ;
if ( F_126 ( V_3 ) ) {
struct V_8 * V_9 = F_204 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_205 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_206 ( V_7 , V_9 ) ;
}
}
}
static int F_207 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_15 ( V_3 ) ;
F_208 ( V_3 ) ;
V_29 -> V_81 = & V_87 ;
#ifdef F_29
F_16 ( V_3 ) -> V_85 = & V_89 ;
#endif
return 0 ;
}
static void F_209 ( struct V_2 * V_3 )
{
F_210 ( V_3 ) ;
F_211 ( V_3 ) ;
}
static void F_212 ( struct V_356 * V_134 ,
const struct V_132 * V_166 , int V_357 )
{
long V_358 = V_166 -> V_359 . V_360 - V_361 ;
const struct V_4 * V_362 = & F_75 ( V_166 ) -> V_177 ;
const struct V_4 * V_19 = & F_75 ( V_166 ) -> V_178 ;
if ( V_358 < 0 )
V_358 = 0 ;
F_213 ( V_134 ,
L_5
L_6 ,
V_357 ,
V_362 -> V_17 [ 0 ] , V_362 -> V_17 [ 1 ] ,
V_362 -> V_17 [ 2 ] , V_362 -> V_17 [ 3 ] ,
F_75 ( V_166 ) -> V_363 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_54 ( F_75 ( V_166 ) -> V_364 ) ,
V_159 ,
0 , 0 ,
1 ,
F_214 ( V_358 ) ,
V_166 -> V_365 ,
F_215 ( F_216 ( V_134 ) ,
F_217 ( V_166 -> V_345 ) ) ,
0 ,
0 ,
0 , V_166 ) ;
}
static void F_218 ( struct V_356 * V_134 , struct V_2 * V_366 , int V_357 )
{
const struct V_4 * V_19 , * V_362 ;
T_7 V_367 , V_368 ;
int V_369 ;
unsigned long V_370 ;
const struct V_26 * V_27 = F_5 ( V_366 ) ;
const struct V_32 * V_33 = F_16 ( V_366 ) ;
const struct V_28 * V_29 = F_15 ( V_366 ) ;
const struct V_371 * V_372 = & V_29 -> V_373 . V_372 ;
int V_374 ;
int V_375 ;
V_19 = & V_366 -> V_67 ;
V_362 = & V_366 -> V_57 ;
V_367 = F_54 ( V_27 -> V_111 ) ;
V_368 = F_54 ( V_27 -> V_98 ) ;
if ( V_29 -> V_376 == V_377 ||
V_29 -> V_376 == V_378 ||
V_29 -> V_376 == V_379 ) {
V_369 = 1 ;
V_370 = V_29 -> V_380 ;
} else if ( V_29 -> V_376 == V_381 ) {
V_369 = 4 ;
V_370 = V_29 -> V_380 ;
} else if ( F_219 ( & V_366 -> V_382 ) ) {
V_369 = 2 ;
V_370 = V_366 -> V_382 . V_360 ;
} else {
V_369 = 0 ;
V_370 = V_361 ;
}
V_375 = F_220 ( V_366 ) ;
if ( V_375 == V_150 )
V_374 = V_366 -> V_383 ;
else
V_374 = F_221 ( int , V_33 -> V_283 - V_33 -> V_384 , 0 ) ;
F_213 ( V_134 ,
L_5
L_7 ,
V_357 ,
V_362 -> V_17 [ 0 ] , V_362 -> V_17 [ 1 ] ,
V_362 -> V_17 [ 2 ] , V_362 -> V_17 [ 3 ] , V_368 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_367 ,
V_375 ,
V_33 -> V_69 - V_33 -> V_135 ,
V_374 ,
V_369 ,
F_222 ( V_370 - V_361 ) ,
V_29 -> V_385 ,
F_215 ( F_216 ( V_134 ) , F_217 ( V_366 ) ) ,
V_29 -> V_386 ,
F_223 ( V_366 ) ,
F_224 ( & V_366 -> V_387 ) , V_366 ,
F_214 ( V_29 -> V_388 ) ,
F_214 ( V_29 -> V_389 . V_390 ) ,
( V_29 -> V_389 . V_391 << 1 ) | V_29 -> V_389 . V_392 ,
V_33 -> V_393 ,
V_375 == V_150 ?
V_372 -> V_394 :
( F_225 ( V_33 ) ? - 1 : V_33 -> V_395 )
) ;
}
static void F_226 ( struct V_356 * V_134 ,
struct V_269 * V_270 , int V_357 )
{
long V_396 = V_270 -> V_397 . V_360 - V_361 ;
const struct V_4 * V_19 , * V_362 ;
T_7 V_367 , V_368 ;
V_19 = & V_270 -> V_398 ;
V_362 = & V_270 -> V_399 ;
V_367 = F_54 ( V_270 -> V_400 ) ;
V_368 = F_54 ( V_270 -> V_401 ) ;
F_213 ( V_134 ,
L_5
L_8 ,
V_357 ,
V_362 -> V_17 [ 0 ] , V_362 -> V_17 [ 1 ] ,
V_362 -> V_17 [ 2 ] , V_362 -> V_17 [ 3 ] , V_368 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_367 ,
V_270 -> V_402 , 0 , 0 ,
3 , F_222 ( V_396 ) , 0 , 0 , 0 , 0 ,
F_224 ( & V_270 -> V_403 ) , V_270 ) ;
}
static int F_227 ( struct V_356 * V_134 , void * V_404 )
{
struct V_405 * V_406 ;
struct V_2 * V_3 = V_404 ;
if ( V_404 == V_407 ) {
F_228 ( V_134 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_144;
}
V_406 = V_134 -> V_408 ;
if ( V_3 -> V_118 == V_140 )
F_226 ( V_134 , V_404 , V_406 -> V_409 ) ;
else if ( V_3 -> V_118 == V_141 )
F_212 ( V_134 , V_404 , V_406 -> V_409 ) ;
else
F_218 ( V_134 , V_404 , V_406 -> V_409 ) ;
V_144:
return 0 ;
}
int T_8 F_229 ( struct V_130 * V_130 )
{
return F_230 ( V_130 , & V_410 ) ;
}
void F_231 ( struct V_130 * V_130 )
{
F_232 ( V_130 , & V_410 ) ;
}
static int T_8 F_233 ( struct V_130 * V_130 )
{
return F_234 ( & V_130 -> V_245 . F_16 , V_411 ,
V_412 , V_92 , V_130 ) ;
}
static void T_9 F_235 ( struct V_130 * V_130 )
{
F_236 ( V_130 -> V_245 . F_16 ) ;
}
static void T_9 F_237 ( struct V_413 * V_414 )
{
F_238 ( & V_137 , V_48 ) ;
}
int T_10 F_239 ( void )
{
int V_333 ;
V_333 = F_240 ( & V_415 , V_92 ) ;
if ( V_333 )
goto V_144;
V_333 = F_241 ( & V_416 ) ;
if ( V_333 )
goto V_417;
V_333 = F_242 ( & V_418 ) ;
if ( V_333 )
goto V_419;
V_144:
return V_333 ;
V_419:
F_243 ( & V_416 ) ;
V_417:
F_244 ( & V_415 , V_92 ) ;
goto V_144;
}
void F_245 ( void )
{
F_246 ( & V_418 ) ;
F_243 ( & V_416 ) ;
F_244 ( & V_415 , V_92 ) ;
}
