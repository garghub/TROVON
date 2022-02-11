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
T_1 V_42 ;
int V_43 ;
struct V_44 * V_45 = & F_15 ( V_3 ) -> V_46 . V_45 ;
if ( V_24 < V_47 )
return - V_48 ;
if ( V_26 -> V_49 != V_50 )
return - V_51 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_32 -> V_52 ) {
V_40 . V_53 = V_26 -> V_54 & V_55 ;
F_16 ( V_40 . V_53 ) ;
if ( V_40 . V_53 & V_56 ) {
struct V_57 * V_53 ;
V_53 = F_17 ( V_3 , V_40 . V_53 ) ;
if ( ! V_53 )
return - V_48 ;
F_18 ( V_53 ) ;
}
}
if ( F_19 ( & V_26 -> V_58 ) ) {
if ( F_20 ( & V_3 -> V_59 ) )
F_21 ( F_22 ( V_60 ) ,
& V_26 -> V_58 ) ;
else
V_26 -> V_58 = V_61 ;
}
V_41 = F_23 ( & V_26 -> V_58 ) ;
if ( V_41 & V_62 )
return - V_63 ;
if ( V_41 & V_64 ) {
if ( V_24 >= sizeof( struct V_25 ) &&
V_26 -> V_65 ) {
if ( V_3 -> V_66 &&
V_3 -> V_66 != V_26 -> V_65 )
return - V_48 ;
V_3 -> V_66 = V_26 -> V_65 ;
}
if ( ! V_3 -> V_66 )
return - V_48 ;
}
if ( V_34 -> V_67 . V_68 &&
! F_24 ( & V_3 -> V_69 , & V_26 -> V_58 ) ) {
V_34 -> V_67 . V_70 = 0 ;
V_34 -> V_67 . V_68 = 0 ;
V_34 -> V_71 = 0 ;
}
V_3 -> V_69 = V_26 -> V_58 ;
V_32 -> V_72 = V_40 . V_53 ;
if ( V_41 & V_73 ) {
T_1 V_74 = V_30 -> V_75 ;
struct V_76 sin ;
F_25 ( V_3 , L_1 ) ;
if ( F_26 ( V_3 ) )
return - V_63 ;
sin . V_77 = V_78 ;
sin . V_79 = V_26 -> V_80 ;
sin . V_81 . V_82 = V_26 -> V_58 . V_18 [ 3 ] ;
V_30 -> V_83 = & V_84 ;
V_3 -> V_85 = V_86 ;
#ifdef F_27
V_34 -> V_87 = & V_88 ;
#endif
V_43 = F_28 ( V_3 , (struct V_22 * ) & sin , sizeof( sin ) ) ;
if ( V_43 ) {
V_30 -> V_75 = V_74 ;
V_30 -> V_83 = & V_89 ;
V_3 -> V_85 = V_90 ;
#ifdef F_27
V_34 -> V_87 = & V_91 ;
#endif
goto V_92;
}
V_32 -> V_19 = V_3 -> V_59 ;
return V_43 ;
}
if ( ! F_19 ( & V_3 -> V_59 ) )
V_19 = & V_3 -> V_59 ;
V_40 . V_93 = V_94 ;
V_40 . V_17 = V_3 -> V_69 ;
V_40 . V_19 = V_19 ? * V_19 : V_32 -> V_19 ;
V_40 . V_95 = V_3 -> V_66 ;
V_40 . V_96 = V_3 -> V_97 ;
V_40 . V_98 = V_26 -> V_80 ;
V_40 . V_99 = V_28 -> V_100 ;
V_40 . V_101 = V_3 -> V_102 ;
V_38 = F_29 ( V_32 -> V_38 , F_30 ( V_3 ) ) ;
V_35 = F_31 ( & V_40 , V_38 , & V_36 ) ;
F_32 ( V_3 , F_33 ( & V_40 ) ) ;
V_9 = F_34 ( V_3 , & V_40 , V_35 ) ;
if ( F_35 ( V_9 ) ) {
V_43 = F_36 ( V_9 ) ;
goto V_92;
}
if ( ! V_19 ) {
V_19 = & V_40 . V_19 ;
V_3 -> V_59 = * V_19 ;
}
V_32 -> V_19 = * V_19 ;
V_28 -> V_103 = V_104 ;
V_3 -> V_105 = V_106 ;
F_37 ( V_3 , V_9 , NULL , NULL ) ;
if ( V_45 -> V_107 &&
! V_34 -> V_67 . V_68 &&
F_24 ( & V_40 . V_17 , & V_3 -> V_69 ) )
F_38 ( V_3 , V_9 ) ;
V_30 -> V_75 = 0 ;
if ( V_38 )
V_30 -> V_75 = V_38 -> V_108 +
V_38 -> V_109 ;
V_34 -> V_67 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_28 -> V_114 = V_26 -> V_80 ;
F_39 ( V_3 , V_115 ) ;
V_43 = F_40 ( V_45 , V_3 ) ;
if ( V_43 )
goto V_116;
F_41 ( V_3 ) ;
if ( F_42 ( ! V_34 -> V_117 ) ) {
V_42 = F_9 ( V_32 -> V_19 . V_18 ,
V_3 -> V_69 . V_18 ,
V_28 -> V_100 ,
V_28 -> V_114 ,
& V_34 -> V_118 ) ;
if ( ! V_34 -> V_71 )
V_34 -> V_71 = V_42 ;
}
if ( F_43 ( V_3 , & V_43 ) )
return V_43 ;
if ( V_43 )
goto V_116;
V_43 = F_44 ( V_3 ) ;
if ( V_43 )
goto V_116;
return 0 ;
V_116:
F_39 ( V_3 , V_119 ) ;
V_92:
V_28 -> V_114 = 0 ;
V_3 -> V_120 = 0 ;
return V_43 ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_121 ) & ( V_122 | V_123 ) )
return;
V_9 = F_46 ( V_3 , F_14 ( V_3 ) -> V_124 ) ;
if ( ! V_9 )
return;
if ( F_13 ( V_3 ) -> V_125 > F_47 ( V_9 ) ) {
F_48 ( V_3 , F_47 ( V_9 ) ) ;
F_49 ( V_3 ) ;
}
}
static void F_50 ( struct V_6 * V_7 , struct V_126 * V_38 ,
T_2 type , T_2 V_127 , int V_128 , T_3 V_129 )
{
const struct V_113 * V_130 = ( const struct V_113 * ) V_7 -> V_131 ;
const struct V_112 * V_132 = (struct V_112 * ) ( V_7 -> V_131 + V_128 ) ;
struct V_133 * V_133 = F_51 ( V_7 -> V_134 ) ;
struct V_135 * V_136 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_4 V_42 , V_137 ;
struct V_2 * V_3 ;
bool V_138 ;
int V_43 ;
V_3 = F_52 ( V_133 , & V_139 ,
& V_130 -> V_17 , V_132 -> V_20 ,
& V_130 -> V_19 , F_53 ( V_132 -> V_21 ) ,
V_7 -> V_134 -> V_140 ) ;
if ( ! V_3 ) {
F_54 ( V_133 , F_55 ( V_7 -> V_134 ) ,
V_141 ) ;
return;
}
if ( V_3 -> V_121 == V_142 ) {
F_56 ( F_57 ( V_3 ) ) ;
return;
}
V_42 = F_58 ( V_132 -> V_42 ) ;
V_138 = F_59 ( type , V_127 , & V_43 ) ;
if ( V_3 -> V_121 == V_143 )
return F_60 ( V_3 , V_42 , V_138 ) ;
F_61 ( V_3 ) ;
if ( F_62 ( V_3 ) && type != V_144 )
F_63 ( V_133 , V_145 ) ;
if ( V_3 -> V_121 == V_119 )
goto V_146;
if ( F_10 ( V_7 ) -> V_147 < F_6 ( V_3 ) -> V_148 ) {
F_63 ( V_133 , V_149 ) ;
goto V_146;
}
V_34 = F_14 ( V_3 ) ;
V_136 = V_34 -> V_150 ;
V_137 = V_136 ? F_64 ( V_136 ) -> V_151 : V_34 -> V_137 ;
if ( V_3 -> V_121 != V_152 &&
! F_65 ( V_42 , V_137 , V_34 -> V_153 ) ) {
F_63 ( V_133 , V_154 ) ;
goto V_146;
}
V_32 = F_6 ( V_3 ) ;
if ( type == V_155 ) {
if ( ! F_62 ( V_3 ) ) {
struct V_8 * V_9 = F_66 ( V_3 , V_32 -> V_156 ) ;
if ( V_9 )
V_9 -> V_157 -> V_158 ( V_9 , V_3 , V_7 ) ;
}
goto V_146;
}
if ( type == V_144 ) {
if ( V_3 -> V_121 == V_152 )
goto V_146;
if ( ! F_67 ( V_3 ) )
goto V_146;
V_34 -> V_124 = F_58 ( V_129 ) ;
if ( ! F_62 ( V_3 ) )
F_45 ( V_3 ) ;
else if ( ! F_68 ( V_159 ,
& V_3 -> V_160 ) )
F_69 ( V_3 ) ;
goto V_146;
}
switch ( V_3 -> V_121 ) {
case V_115 :
case V_161 :
if ( V_136 && ! V_136 -> V_3 )
break;
if ( ! F_62 ( V_3 ) ) {
V_3 -> V_162 = V_43 ;
V_3 -> V_163 ( V_3 ) ;
F_70 ( V_3 ) ;
} else
V_3 -> V_164 = V_43 ;
goto V_146;
}
if ( ! F_62 ( V_3 ) && V_32 -> V_165 ) {
V_3 -> V_162 = V_43 ;
V_3 -> V_163 ( V_3 ) ;
} else
V_3 -> V_164 = V_43 ;
V_146:
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
}
static int F_73 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_166 * V_167 ,
struct V_135 * V_168 ,
struct V_169 * V_170 ,
enum V_171 V_172 )
{
struct V_173 * V_174 = F_74 ( V_168 ) ;
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 = & V_167 -> V_175 . V_176 ;
struct V_6 * V_7 ;
int V_43 = - V_177 ;
if ( ! V_9 && ( V_9 = F_75 ( V_3 , V_40 , V_168 ,
V_94 ) ) == NULL )
goto V_178;
V_7 = F_76 ( V_3 , V_9 , V_168 , V_170 , V_172 ) ;
if ( V_7 ) {
F_77 ( V_7 , & V_174 -> V_179 ,
& V_174 -> V_180 ) ;
V_40 -> V_17 = V_174 -> V_180 ;
if ( V_32 -> V_181 && V_174 -> V_182 )
V_40 -> V_53 = V_57 ( F_10 ( V_174 -> V_182 ) ) ;
F_78 () ;
V_38 = V_174 -> V_183 ;
if ( ! V_38 )
V_38 = F_79 ( V_32 -> V_38 ) ;
V_43 = F_80 ( V_3 , V_7 , V_40 , V_3 -> V_97 , V_38 , V_32 -> V_184 ) ;
F_81 () ;
V_43 = F_82 ( V_43 ) ;
}
V_178:
return V_43 ;
}
static void F_83 ( struct V_135 * V_168 )
{
F_84 ( F_74 ( V_168 ) -> V_183 ) ;
F_85 ( F_74 ( V_168 ) -> V_182 ) ;
}
static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_86 ( V_3 , (union V_185 * ) V_5 , V_50 ) ;
}
static struct V_1 * F_87 ( const struct V_2 * V_3 ,
const struct V_2 * V_186 )
{
return F_1 ( V_3 , & V_186 -> V_69 ) ;
}
static int F_88 ( struct V_2 * V_3 , char T_5 * V_187 ,
int V_188 )
{
struct V_189 V_190 ;
struct V_25 * V_191 = (struct V_25 * ) & V_190 . V_192 ;
if ( V_188 < sizeof( V_190 ) )
return - V_48 ;
if ( F_89 ( & V_190 , V_187 , sizeof( V_190 ) ) )
return - V_193 ;
if ( V_191 -> V_49 != V_50 )
return - V_48 ;
if ( ! V_190 . V_194 ) {
if ( F_20 ( & V_191 -> V_58 ) )
return F_90 ( V_3 , (union V_185 * ) & V_191 -> V_58 . V_18 [ 3 ] ,
V_78 ) ;
return F_90 ( V_3 , (union V_185 * ) & V_191 -> V_58 ,
V_50 ) ;
}
if ( V_190 . V_194 > V_195 )
return - V_48 ;
if ( F_20 ( & V_191 -> V_58 ) )
return F_91 ( V_3 , (union V_185 * ) & V_191 -> V_58 . V_18 [ 3 ] ,
V_78 , V_190 . V_196 , V_190 . V_194 , V_197 ) ;
return F_91 ( V_3 , (union V_185 * ) & V_191 -> V_58 ,
V_50 , V_190 . V_196 , V_190 . V_194 , V_197 ) ;
}
static int F_92 ( struct V_198 * V_199 ,
const struct V_4 * V_17 ,
const struct V_4 * V_19 ,
const struct V_112 * V_132 , int V_200 )
{
struct V_201 * V_202 ;
struct V_203 V_204 ;
struct V_112 * V_205 ;
V_202 = V_199 -> V_206 ;
V_202 -> V_19 = * V_19 ;
V_202 -> V_17 = * V_17 ;
V_202 -> V_207 = F_93 ( V_94 ) ;
V_202 -> V_208 = F_93 ( V_200 ) ;
V_205 = (struct V_112 * ) ( V_202 + 1 ) ;
memcpy ( V_205 , V_132 , sizeof( * V_132 ) ) ;
V_205 -> V_209 = 0 ;
F_94 ( & V_204 , V_202 , sizeof( * V_202 ) + sizeof( * V_132 ) ) ;
F_95 ( V_199 -> V_210 , & V_204 , NULL ,
sizeof( * V_202 ) + sizeof( * V_132 ) ) ;
return F_96 ( V_199 -> V_210 ) ;
}
static int F_97 ( char * V_211 , const struct V_1 * V_212 ,
const struct V_4 * V_17 , struct V_4 * V_19 ,
const struct V_112 * V_132 )
{
struct V_198 * V_199 ;
struct V_213 * V_168 ;
V_199 = F_98 () ;
if ( ! V_199 )
goto V_214;
V_168 = V_199 -> V_210 ;
if ( F_99 ( V_168 ) )
goto V_215;
if ( F_92 ( V_199 , V_17 , V_19 , V_132 , V_132 -> V_216 << 2 ) )
goto V_215;
if ( F_100 ( V_199 , V_212 ) )
goto V_215;
F_95 ( V_168 , NULL , V_211 , 0 ) ;
if ( F_101 ( V_168 ) )
goto V_215;
F_102 () ;
return 0 ;
V_215:
F_102 () ;
V_214:
memset ( V_211 , 0 , 16 ) ;
return 1 ;
}
static int F_103 ( char * V_211 ,
const struct V_1 * V_212 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_19 , * V_17 ;
struct V_198 * V_199 ;
struct V_213 * V_168 ;
const struct V_112 * V_132 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_19 = & V_3 -> V_59 ;
V_17 = & V_3 -> V_69 ;
} else {
const struct V_113 * V_217 = F_10 ( V_7 ) ;
V_19 = & V_217 -> V_19 ;
V_17 = & V_217 -> V_17 ;
}
V_199 = F_98 () ;
if ( ! V_199 )
goto V_214;
V_168 = V_199 -> V_210 ;
if ( F_99 ( V_168 ) )
goto V_215;
if ( F_92 ( V_199 , V_17 , V_19 , V_132 , V_7 -> V_208 ) )
goto V_215;
if ( F_104 ( V_199 , V_7 , V_132 -> V_216 << 2 ) )
goto V_215;
if ( F_100 ( V_199 , V_212 ) )
goto V_215;
F_95 ( V_168 , NULL , V_211 , 0 ) ;
if ( F_101 ( V_168 ) )
goto V_215;
F_102 () ;
return 0 ;
V_215:
F_102 () ;
V_214:
memset ( V_211 , 0 , 16 ) ;
return 1 ;
}
static bool F_105 ( const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
#ifdef F_27
const T_6 * V_218 = NULL ;
struct V_1 * V_219 ;
const struct V_113 * V_217 = F_10 ( V_7 ) ;
const struct V_112 * V_132 = F_11 ( V_7 ) ;
int V_220 ;
T_2 V_221 [ 16 ] ;
V_219 = F_1 ( V_3 , & V_217 -> V_19 ) ;
V_218 = F_106 ( V_132 ) ;
if ( ! V_219 && ! V_218 )
return false ;
if ( V_219 && ! V_218 ) {
F_107 ( F_15 ( V_3 ) , V_222 ) ;
return true ;
}
if ( ! V_219 && V_218 ) {
F_107 ( F_15 ( V_3 ) , V_223 ) ;
return true ;
}
V_220 = F_103 ( V_221 ,
V_219 ,
NULL , V_7 ) ;
if ( V_220 || memcmp ( V_218 , V_221 , 16 ) != 0 ) {
F_107 ( F_15 ( V_3 ) , V_224 ) ;
F_108 ( L_2 ,
V_220 ? L_3 : L_4 ,
& V_217 -> V_19 , F_53 ( V_132 -> V_21 ) ,
& V_217 -> V_17 , F_53 ( V_132 -> V_20 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_109 ( struct V_135 * V_168 ,
const struct V_2 * V_225 ,
struct V_6 * V_7 )
{
struct V_173 * V_174 = F_74 ( V_168 ) ;
const struct V_31 * V_32 = F_6 ( V_225 ) ;
V_174 -> V_180 = F_10 ( V_7 ) -> V_19 ;
V_174 -> V_179 = F_10 ( V_7 ) -> V_17 ;
if ( ! V_225 -> V_66 &&
F_23 ( & V_174 -> V_180 ) & V_64 )
V_174 -> V_226 = F_110 ( V_7 ) ;
if ( ! F_111 ( V_7 ) -> V_227 &&
( F_112 ( V_225 , V_7 , & F_111 ( V_7 ) -> V_228 . V_229 ) ||
V_32 -> V_230 . V_231 . V_232 ||
V_32 -> V_230 . V_231 . V_233 || V_32 -> V_230 . V_231 . V_234 ||
V_32 -> V_230 . V_231 . V_235 || V_32 -> V_181 ) ) {
F_113 ( & V_7 -> V_236 ) ;
V_174 -> V_182 = V_7 ;
}
}
static struct V_8 * F_114 ( const struct V_2 * V_3 ,
struct V_166 * V_167 ,
const struct V_135 * V_168 ,
bool * V_237 )
{
if ( V_237 )
* V_237 = true ;
return F_75 ( V_3 , & V_167 -> V_175 . V_176 , V_168 , V_94 ) ;
}
static void F_115 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_42 ,
T_1 V_238 , T_1 V_239 , T_1 V_240 , T_1 V_241 ,
int V_242 , struct V_1 * V_212 , int V_243 ,
T_2 V_184 , T_3 V_244 )
{
const struct V_112 * V_132 = F_11 ( V_7 ) ;
struct V_112 * V_245 ;
struct V_6 * V_246 ;
struct V_39 V_40 ;
struct V_133 * V_133 = V_3 ? F_15 ( V_3 ) : F_51 ( F_3 ( V_7 ) -> V_134 ) ;
struct V_2 * V_247 = V_133 -> V_248 . F_14 ;
unsigned int V_249 = sizeof( struct V_112 ) ;
struct V_8 * V_9 ;
T_3 * V_250 ;
if ( V_241 )
V_249 += V_251 ;
#ifdef F_27
if ( V_212 )
V_249 += V_252 ;
#endif
V_246 = F_116 ( V_253 + sizeof( struct V_113 ) + V_249 ,
V_254 ) ;
if ( ! V_246 )
return;
F_117 ( V_246 , V_253 + sizeof( struct V_113 ) + V_249 ) ;
V_245 = (struct V_112 * ) F_118 ( V_246 , V_249 ) ;
F_119 ( V_246 ) ;
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_245 -> V_20 = V_132 -> V_21 ;
V_245 -> V_21 = V_132 -> V_20 ;
V_245 -> V_216 = V_249 / 4 ;
V_245 -> V_42 = F_22 ( V_42 ) ;
V_245 -> V_255 = F_22 ( V_238 ) ;
V_245 -> V_238 = ! V_243 || ! V_132 -> V_238 ;
V_245 -> V_243 = V_243 ;
V_245 -> V_256 = F_120 ( V_239 ) ;
V_250 = ( T_3 * ) ( V_245 + 1 ) ;
if ( V_241 ) {
* V_250 ++ = F_22 ( ( V_257 << 24 ) | ( V_257 << 16 ) |
( V_258 << 8 ) | V_259 ) ;
* V_250 ++ = F_22 ( V_240 ) ;
* V_250 ++ = F_22 ( V_241 ) ;
}
#ifdef F_27
if ( V_212 ) {
* V_250 ++ = F_22 ( ( V_257 << 24 ) | ( V_257 << 16 ) |
( V_260 << 8 ) | V_261 ) ;
F_97 ( ( T_6 * ) V_250 , V_212 ,
& F_10 ( V_7 ) -> V_19 ,
& F_10 ( V_7 ) -> V_17 , V_245 ) ;
}
#endif
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_17 = F_10 ( V_7 ) -> V_19 ;
V_40 . V_19 = F_10 ( V_7 ) -> V_17 ;
V_40 . V_53 = V_244 ;
V_246 -> V_262 = V_263 ;
V_246 -> V_264 = 0 ;
F_77 ( V_246 , & V_40 . V_19 , & V_40 . V_17 ) ;
V_40 . V_93 = V_94 ;
if ( F_121 ( & V_40 . V_17 ) && ! V_242 )
V_40 . V_95 = F_110 ( V_7 ) ;
else {
if ( ! V_242 && F_122 ( V_133 , V_7 -> V_14 ) )
V_242 = V_7 -> V_14 ;
V_40 . V_95 = V_242 ;
}
V_40 . V_96 = F_123 ( V_133 , V_7 -> V_265 ) ;
V_40 . V_98 = V_245 -> V_20 ;
V_40 . V_99 = V_245 -> V_21 ;
V_40 . V_101 = F_124 ( V_133 , V_3 && F_125 ( V_3 ) ? V_3 : NULL ) ;
F_126 ( V_7 , F_33 ( & V_40 ) ) ;
V_9 = F_34 ( V_247 , & V_40 , NULL ) ;
if ( ! F_35 ( V_9 ) ) {
F_127 ( V_246 , V_9 ) ;
F_80 ( V_247 , V_246 , & V_40 , V_40 . V_96 , NULL , V_184 ) ;
F_128 ( V_133 , V_266 ) ;
if ( V_243 )
F_128 ( V_133 , V_267 ) ;
return;
}
F_85 ( V_246 ) ;
}
static void F_129 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_112 * V_132 = F_11 ( V_7 ) ;
T_1 V_42 = 0 , V_255 = 0 ;
struct V_1 * V_212 = NULL ;
#ifdef F_27
const T_6 * V_218 = NULL ;
struct V_113 * V_268 = F_10 ( V_7 ) ;
unsigned char V_221 [ 16 ] ;
int V_220 ;
struct V_2 * V_269 = NULL ;
#endif
int V_242 ;
if ( V_132 -> V_243 )
return;
if ( ! V_3 && ! F_130 ( V_7 ) )
return;
#ifdef F_27
F_78 () ;
V_218 = F_106 ( V_132 ) ;
if ( V_3 && F_125 ( V_3 ) ) {
V_212 = F_1 ( V_3 , & V_268 -> V_19 ) ;
} else if ( V_218 ) {
V_269 = F_131 ( F_51 ( F_3 ( V_7 ) -> V_134 ) ,
& V_139 , NULL , 0 ,
& V_268 -> V_19 ,
V_132 -> V_21 , & V_268 -> V_17 ,
F_53 ( V_132 -> V_21 ) , F_110 ( V_7 ) ) ;
if ( ! V_269 )
goto V_146;
V_212 = F_1 ( V_269 , & V_268 -> V_19 ) ;
if ( ! V_212 )
goto V_146;
V_220 = F_103 ( V_221 , V_212 , NULL , V_7 ) ;
if ( V_220 || memcmp ( V_218 , V_221 , 16 ) != 0 )
goto V_146;
}
#endif
if ( V_132 -> V_238 )
V_42 = F_58 ( V_132 -> V_255 ) ;
else
V_255 = F_58 ( V_132 -> V_42 ) + V_132 -> V_270 + V_132 -> V_271 + V_7 -> V_208 -
( V_132 -> V_216 << 2 ) ;
V_242 = V_3 ? V_3 -> V_66 : 0 ;
F_115 ( V_3 , V_7 , V_42 , V_255 , 0 , 0 , 0 , V_242 , V_212 , 1 , 0 , 0 ) ;
#ifdef F_27
V_146:
F_81 () ;
#endif
}
static void F_132 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_1 V_42 ,
T_1 V_238 , T_1 V_239 , T_1 V_240 , T_1 V_241 , int V_242 ,
struct V_1 * V_212 , T_2 V_184 ,
T_3 V_244 )
{
F_115 ( V_3 , V_7 , V_42 , V_238 , V_239 , V_240 , V_241 , V_242 , V_212 , 0 ,
V_184 , V_244 ) ;
}
static void F_133 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_272 * V_273 = F_57 ( V_3 ) ;
struct V_274 * V_275 = F_134 ( V_3 ) ;
F_132 ( V_3 , V_7 , V_275 -> V_276 , V_275 -> V_277 ,
V_275 -> V_278 >> V_273 -> V_279 ,
V_280 + V_275 -> V_281 ,
V_275 -> V_282 , V_273 -> V_283 , F_135 ( V_275 ) ,
V_273 -> V_284 , F_93 ( V_273 -> V_285 ) ) ;
F_56 ( V_273 ) ;
}
static void F_136 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_135 * V_168 )
{
F_132 ( V_3 , V_7 , ( V_3 -> V_121 == V_152 ) ?
F_64 ( V_168 ) -> V_151 + 1 : F_14 ( V_3 ) -> V_153 ,
F_64 ( V_168 ) -> V_286 ,
V_168 -> V_287 >> F_74 ( V_168 ) -> V_288 ,
V_280 + F_64 ( V_168 ) -> V_289 ,
V_168 -> V_70 , V_3 -> V_66 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_17 ) ,
0 , 0 ) ;
}
static struct V_2 * F_137 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_138
const struct V_112 * V_132 = F_11 ( V_7 ) ;
if ( ! V_132 -> V_270 )
V_3 = F_139 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_140 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_207 == F_120 ( V_290 ) )
return F_141 ( V_3 , V_7 ) ;
if ( ! F_130 ( V_7 ) )
goto V_291;
return F_142 ( & V_292 ,
& V_293 , V_3 , V_7 ) ;
V_291:
F_143 ( V_3 ) ;
return 0 ;
}
static void F_144 ( struct V_6 * V_7 )
{
memmove ( F_145 ( V_7 ) , & F_111 ( V_7 ) -> V_228 . V_229 ,
sizeof( struct V_126 ) ) ;
}
static struct V_2 * F_146 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_135 * V_168 ,
struct V_8 * V_9 ,
struct V_135 * V_294 ,
bool * V_295 )
{
struct V_173 * V_174 ;
struct V_31 * V_296 ;
const struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_37 * V_38 ;
struct V_297 * V_298 ;
struct V_27 * V_299 ;
struct V_33 * V_300 ;
struct V_2 * V_301 ;
#ifdef F_27
struct V_1 * V_212 ;
#endif
struct V_39 V_40 ;
if ( V_7 -> V_207 == F_120 ( V_290 ) ) {
V_301 = F_147 ( V_3 , V_7 , V_168 , V_9 ,
V_294 , V_295 ) ;
if ( ! V_301 )
return NULL ;
V_298 = (struct V_297 * ) V_301 ;
F_5 ( V_301 ) -> V_302 = & V_298 -> V_303 ;
V_299 = F_5 ( V_301 ) ;
V_296 = F_6 ( V_301 ) ;
V_300 = F_14 ( V_301 ) ;
memcpy ( V_296 , V_32 , sizeof( struct V_31 ) ) ;
V_296 -> V_19 = V_301 -> V_59 ;
F_13 ( V_301 ) -> V_83 = & V_84 ;
V_301 -> V_85 = V_86 ;
#ifdef F_27
V_300 -> V_87 = & V_88 ;
#endif
V_296 -> V_304 = NULL ;
V_296 -> V_305 = NULL ;
V_296 -> V_306 = NULL ;
V_296 -> V_38 = NULL ;
V_296 -> V_307 = F_110 ( V_7 ) ;
V_296 -> V_308 = F_10 ( V_7 ) -> V_147 ;
V_296 -> V_309 = F_148 ( F_10 ( V_7 ) ) ;
if ( V_32 -> V_181 )
V_296 -> V_72 = V_57 ( F_10 ( V_7 ) ) ;
F_48 ( V_301 , F_13 ( V_301 ) -> V_125 ) ;
return V_301 ;
}
V_174 = F_74 ( V_168 ) ;
if ( F_149 ( V_3 ) )
goto V_310;
if ( ! V_9 ) {
V_9 = F_75 ( V_3 , & V_40 , V_168 , V_94 ) ;
if ( ! V_9 )
goto V_146;
}
V_301 = F_150 ( V_3 , V_168 , V_7 ) ;
if ( ! V_301 )
goto V_311;
V_301 -> V_105 = V_106 ;
F_37 ( V_301 , V_9 , NULL , NULL ) ;
F_2 ( V_301 , V_7 ) ;
V_298 = (struct V_297 * ) V_301 ;
F_5 ( V_301 ) -> V_302 = & V_298 -> V_303 ;
V_300 = F_14 ( V_301 ) ;
V_299 = F_5 ( V_301 ) ;
V_296 = F_6 ( V_301 ) ;
memcpy ( V_296 , V_32 , sizeof( struct V_31 ) ) ;
V_301 -> V_69 = V_174 -> V_180 ;
V_296 -> V_19 = V_174 -> V_179 ;
V_301 -> V_59 = V_174 -> V_179 ;
V_301 -> V_66 = V_174 -> V_226 ;
V_299 -> V_312 = NULL ;
V_296 -> V_304 = NULL ;
V_296 -> V_305 = NULL ;
V_296 -> V_230 . V_313 = V_32 -> V_230 . V_313 ;
V_296 -> V_306 = NULL ;
V_296 -> V_38 = NULL ;
V_296 -> V_307 = F_110 ( V_7 ) ;
V_296 -> V_308 = F_10 ( V_7 ) -> V_147 ;
V_296 -> V_309 = F_148 ( F_10 ( V_7 ) ) ;
if ( V_32 -> V_181 )
V_296 -> V_72 = V_57 ( F_10 ( V_7 ) ) ;
V_38 = V_174 -> V_183 ;
if ( ! V_38 )
V_38 = F_79 ( V_32 -> V_38 ) ;
if ( V_38 ) {
V_38 = F_151 ( V_301 , V_38 ) ;
F_152 ( V_296 -> V_38 , V_38 ) ;
}
F_13 ( V_301 ) -> V_75 = 0 ;
if ( V_38 )
F_13 ( V_301 ) -> V_75 = V_38 -> V_109 +
V_38 -> V_108 ;
F_153 ( V_301 , V_9 ) ;
F_48 ( V_301 , F_47 ( V_9 ) ) ;
V_300 -> V_314 = F_154 ( F_14 ( V_3 ) , F_155 ( V_9 ) ) ;
F_156 ( V_301 ) ;
V_299 -> V_315 = V_299 -> V_316 = V_104 ;
V_299 -> V_103 = V_104 ;
#ifdef F_27
V_212 = F_1 ( V_3 , & V_301 -> V_69 ) ;
if ( V_212 ) {
F_91 ( V_301 , (union V_185 * ) & V_301 -> V_69 ,
V_50 , V_212 -> V_212 , V_212 -> V_317 ,
F_157 ( V_3 , V_254 ) ) ;
}
#endif
if ( F_158 ( V_3 , V_301 ) < 0 ) {
F_159 ( V_301 ) ;
F_70 ( V_301 ) ;
goto V_146;
}
* V_295 = F_160 ( V_301 , F_161 ( V_294 ) ) ;
if ( * V_295 ) {
F_162 ( V_300 , V_168 ) ;
if ( V_174 -> V_182 ) {
V_296 -> V_306 = F_163 ( V_174 -> V_182 ,
F_157 ( V_3 , V_254 ) ) ;
F_164 ( V_174 -> V_182 ) ;
V_174 -> V_182 = NULL ;
if ( V_296 -> V_306 ) {
F_144 ( V_296 -> V_306 ) ;
F_165 ( V_296 -> V_306 , V_301 ) ;
}
}
}
return V_301 ;
V_310:
F_63 ( F_15 ( V_3 ) , V_318 ) ;
V_311:
F_166 ( V_9 ) ;
V_146:
F_143 ( V_3 ) ;
return NULL ;
}
static int V_90 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_31 * V_32 = F_6 ( V_3 ) ;
struct V_33 * V_34 ;
struct V_6 * V_319 = NULL ;
if ( V_7 -> V_207 == F_120 ( V_290 ) )
return V_86 ( V_3 , V_7 ) ;
if ( F_167 ( V_3 , V_7 ) )
goto V_320;
if ( V_32 -> V_230 . V_313 )
V_319 = F_163 ( V_7 , F_157 ( V_3 , V_254 ) ) ;
if ( V_3 -> V_121 == V_321 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_168 ( V_3 , V_7 ) ;
F_169 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_157 -> V_209 ( V_9 , V_32 -> V_15 ) == NULL ) {
F_166 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_170 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_208 ) ;
if ( V_319 )
goto V_322;
return 0 ;
}
if ( F_171 ( V_7 ) )
goto V_323;
if ( V_3 -> V_121 == V_152 ) {
struct V_2 * V_324 = F_137 ( V_3 , V_7 ) ;
if ( ! V_324 )
goto V_320;
if ( V_324 != V_3 ) {
F_168 ( V_324 , V_7 ) ;
F_169 ( V_324 , V_7 ) ;
if ( F_172 ( V_3 , V_324 , V_7 ) )
goto V_325;
if ( V_319 )
F_173 ( V_319 ) ;
return 0 ;
}
} else
F_168 ( V_3 , V_7 ) ;
if ( F_174 ( V_3 , V_7 ) )
goto V_325;
if ( V_319 )
goto V_322;
return 0 ;
V_325:
F_129 ( V_3 , V_7 ) ;
V_320:
if ( V_319 )
F_173 ( V_319 ) ;
F_85 ( V_7 ) ;
return 0 ;
V_323:
F_128 ( F_15 ( V_3 ) , V_326 ) ;
F_128 ( F_15 ( V_3 ) , V_327 ) ;
goto V_320;
V_322:
V_34 = F_14 ( V_3 ) ;
if ( F_111 ( V_319 ) -> V_328 == V_34 -> V_286 &&
! ( ( 1 << V_3 -> V_121 ) & ( V_123 | V_122 ) ) ) {
if ( V_32 -> V_230 . V_231 . V_232 || V_32 -> V_230 . V_231 . V_233 )
V_32 -> V_307 = F_110 ( V_319 ) ;
if ( V_32 -> V_230 . V_231 . V_234 || V_32 -> V_230 . V_231 . V_235 )
V_32 -> V_308 = F_10 ( V_319 ) -> V_147 ;
if ( V_32 -> V_230 . V_231 . V_329 || V_32 -> V_230 . V_231 . V_330 )
V_32 -> V_309 = F_148 ( F_10 ( V_319 ) ) ;
if ( V_32 -> V_181 )
V_32 -> V_72 = V_57 ( F_10 ( V_319 ) ) ;
if ( F_112 ( V_3 , V_319 , & F_111 ( V_319 ) -> V_228 . V_229 ) ) {
F_165 ( V_319 , V_3 ) ;
F_144 ( V_319 ) ;
V_319 = F_175 ( & V_32 -> V_306 , V_319 ) ;
} else {
F_173 ( V_319 ) ;
V_319 = F_175 ( & V_32 -> V_306 , NULL ) ;
}
}
F_85 ( V_319 ) ;
return 0 ;
}
static void F_176 ( struct V_6 * V_7 , const struct V_113 * V_130 ,
const struct V_112 * V_132 )
{
memmove ( & F_111 ( V_7 ) -> V_228 . V_229 , F_145 ( V_7 ) ,
sizeof( struct V_126 ) ) ;
F_177 () ;
F_111 ( V_7 ) -> V_42 = F_58 ( V_132 -> V_42 ) ;
F_111 ( V_7 ) -> V_328 = ( F_111 ( V_7 ) -> V_42 + V_132 -> V_270 + V_132 -> V_271 +
V_7 -> V_208 - V_132 -> V_216 * 4 ) ;
F_111 ( V_7 ) -> V_255 = F_58 ( V_132 -> V_255 ) ;
F_111 ( V_7 ) -> V_331 = F_178 ( V_132 ) ;
F_111 ( V_7 ) -> V_227 = 0 ;
F_111 ( V_7 ) -> V_332 = F_179 ( V_130 ) ;
F_111 ( V_7 ) -> V_333 = 0 ;
}
static int F_180 ( struct V_6 * V_7 )
{
const struct V_112 * V_132 ;
const struct V_113 * V_130 ;
bool V_334 ;
struct V_2 * V_3 ;
int V_335 ;
struct V_133 * V_133 = F_51 ( V_7 -> V_134 ) ;
if ( V_7 -> V_336 != V_337 )
goto V_338;
F_181 ( V_133 , V_339 ) ;
if ( ! F_182 ( V_7 , sizeof( struct V_112 ) ) )
goto V_338;
V_132 = ( const struct V_112 * ) V_7 -> V_131 ;
if ( F_183 ( V_132 -> V_216 < sizeof( struct V_112 ) / 4 ) )
goto V_340;
if ( ! F_182 ( V_7 , V_132 -> V_216 * 4 ) )
goto V_338;
if ( F_184 ( V_7 , V_94 , V_341 ) )
goto V_342;
V_132 = ( const struct V_112 * ) V_7 -> V_131 ;
V_130 = F_10 ( V_7 ) ;
V_343:
V_3 = F_185 ( & V_139 , V_7 , F_186 ( V_132 ) ,
V_132 -> V_21 , V_132 -> V_20 , F_187 ( V_7 ) ,
& V_334 ) ;
if ( ! V_3 )
goto V_344;
V_345:
if ( V_3 -> V_121 == V_142 )
goto V_346;
if ( V_3 -> V_121 == V_143 ) {
struct V_135 * V_168 = F_188 ( V_3 ) ;
struct V_2 * V_324 ;
V_3 = V_168 -> V_347 ;
F_176 ( V_7 , V_130 , V_132 ) ;
if ( F_105 ( V_3 , V_7 ) ) {
F_189 ( V_3 , V_7 ) ;
F_190 ( V_168 ) ;
goto V_338;
}
if ( F_183 ( V_3 -> V_121 != V_152 ) ) {
F_191 ( V_3 , V_168 ) ;
goto V_343;
}
F_69 ( V_3 ) ;
V_334 = true ;
V_324 = F_192 ( V_3 , V_7 , V_168 , false ) ;
if ( ! V_324 ) {
F_190 ( V_168 ) ;
goto V_348;
}
if ( V_324 == V_3 ) {
F_190 ( V_168 ) ;
F_144 ( V_7 ) ;
} else if ( F_172 ( V_3 , V_324 , V_7 ) ) {
F_129 ( V_324 , V_7 ) ;
goto V_348;
} else {
F_72 ( V_3 ) ;
return 0 ;
}
}
if ( V_130 -> V_147 < F_6 ( V_3 ) -> V_148 ) {
F_63 ( V_133 , V_149 ) ;
goto V_348;
}
if ( ! F_193 ( V_3 , V_349 , V_7 ) )
goto V_348;
F_176 ( V_7 , V_130 , V_132 ) ;
if ( F_105 ( V_3 , V_7 ) )
goto V_348;
if ( F_167 ( V_3 , V_7 ) )
goto V_348;
V_132 = ( const struct V_112 * ) V_7 -> V_131 ;
V_130 = F_10 ( V_7 ) ;
V_7 -> V_134 = NULL ;
if ( V_3 -> V_121 == V_152 ) {
V_335 = V_90 ( V_3 , V_7 ) ;
goto V_350;
}
F_194 ( V_3 ) ;
F_195 ( V_3 ) ;
F_196 ( F_14 ( V_3 ) , V_7 ) ;
V_335 = 0 ;
if ( ! F_62 ( V_3 ) ) {
if ( ! F_197 ( V_3 , V_7 ) )
V_335 = V_90 ( V_3 , V_7 ) ;
} else if ( F_198 ( V_3 , V_7 ) ) {
goto V_348;
}
F_71 ( V_3 ) ;
V_350:
if ( V_334 )
F_72 ( V_3 ) ;
return V_335 ? - 1 : 0 ;
V_344:
if ( ! F_193 ( NULL , V_349 , V_7 ) )
goto V_338;
F_176 ( V_7 , V_130 , V_132 ) ;
if ( F_171 ( V_7 ) ) {
V_342:
F_181 ( V_133 , V_326 ) ;
V_340:
F_181 ( V_133 , V_327 ) ;
} else {
F_129 ( NULL , V_7 ) ;
}
V_338:
F_85 ( V_7 ) ;
return 0 ;
V_348:
F_189 ( V_3 , V_7 ) ;
if ( V_334 )
F_72 ( V_3 ) ;
goto V_338;
V_346:
if ( ! F_193 ( NULL , V_349 , V_7 ) ) {
F_56 ( F_57 ( V_3 ) ) ;
goto V_338;
}
F_176 ( V_7 , V_130 , V_132 ) ;
if ( F_171 ( V_7 ) ) {
F_56 ( F_57 ( V_3 ) ) ;
goto V_342;
}
switch ( F_199 ( F_57 ( V_3 ) , V_7 , V_132 ) ) {
case V_351 :
{
struct V_2 * V_352 ;
V_352 = F_131 ( F_51 ( V_7 -> V_134 ) , & V_139 ,
V_7 , F_186 ( V_132 ) ,
& F_10 ( V_7 ) -> V_19 , V_132 -> V_21 ,
& F_10 ( V_7 ) -> V_17 ,
F_53 ( V_132 -> V_20 ) , F_110 ( V_7 ) ) ;
if ( V_352 ) {
struct V_272 * V_273 = F_57 ( V_3 ) ;
F_200 ( V_273 ) ;
V_3 = V_352 ;
F_144 ( V_7 ) ;
V_334 = false ;
goto V_345;
}
}
case V_353 :
F_133 ( V_3 , V_7 ) ;
break;
case V_354 :
F_144 ( V_7 ) ;
F_129 ( V_3 , V_7 ) ;
F_200 ( F_57 ( V_3 ) ) ;
goto V_338;
case V_355 :
;
}
goto V_338;
}
static void F_201 ( struct V_6 * V_7 )
{
const struct V_113 * V_130 ;
const struct V_112 * V_132 ;
struct V_2 * V_3 ;
if ( V_7 -> V_336 != V_337 )
return;
if ( ! F_182 ( V_7 , F_202 ( V_7 ) + sizeof( struct V_112 ) ) )
return;
V_130 = F_10 ( V_7 ) ;
V_132 = F_11 ( V_7 ) ;
if ( V_132 -> V_216 < sizeof( struct V_112 ) / 4 )
return;
V_3 = F_52 ( F_51 ( V_7 -> V_134 ) , & V_139 ,
& V_130 -> V_19 , V_132 -> V_21 ,
& V_130 -> V_17 , F_53 ( V_132 -> V_20 ) ,
F_187 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_356 = V_357 ;
if ( F_125 ( V_3 ) ) {
struct V_8 * V_9 = F_203 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_204 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_205 ( V_7 , V_9 ) ;
}
}
}
static int F_206 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = F_13 ( V_3 ) ;
F_207 ( V_3 ) ;
V_30 -> V_83 = & V_89 ;
#ifdef F_27
F_14 ( V_3 ) -> V_87 = & V_91 ;
#endif
return 0 ;
}
static void F_208 ( struct V_2 * V_3 )
{
F_209 ( V_3 ) ;
F_210 ( V_3 ) ;
}
static void F_211 ( struct V_358 * V_42 ,
const struct V_135 * V_168 , int V_359 )
{
long V_360 = V_168 -> V_361 . V_362 - V_363 ;
const struct V_4 * V_364 = & F_74 ( V_168 ) -> V_179 ;
const struct V_4 * V_20 = & F_74 ( V_168 ) -> V_180 ;
if ( V_360 < 0 )
V_360 = 0 ;
F_212 ( V_42 ,
L_5
L_6 ,
V_359 ,
V_364 -> V_18 [ 0 ] , V_364 -> V_18 [ 1 ] ,
V_364 -> V_18 [ 2 ] , V_364 -> V_18 [ 3 ] ,
F_74 ( V_168 ) -> V_365 ,
V_20 -> V_18 [ 0 ] , V_20 -> V_18 [ 1 ] ,
V_20 -> V_18 [ 2 ] , V_20 -> V_18 [ 3 ] ,
F_53 ( F_74 ( V_168 ) -> V_366 ) ,
V_161 ,
0 , 0 ,
1 ,
F_213 ( V_360 ) ,
V_168 -> V_367 ,
F_214 ( F_215 ( V_42 ) ,
F_216 ( V_168 -> V_347 ) ) ,
0 ,
0 ,
0 , V_168 ) ;
}
static void F_217 ( struct V_358 * V_42 , struct V_2 * V_368 , int V_359 )
{
const struct V_4 * V_20 , * V_364 ;
T_7 V_369 , V_370 ;
int V_371 ;
unsigned long V_372 ;
const struct V_27 * V_28 = F_5 ( V_368 ) ;
const struct V_33 * V_34 = F_14 ( V_368 ) ;
const struct V_29 * V_30 = F_13 ( V_368 ) ;
const struct V_373 * V_374 = & V_30 -> V_375 . V_374 ;
int V_376 ;
int V_377 ;
V_20 = & V_368 -> V_69 ;
V_364 = & V_368 -> V_59 ;
V_369 = F_53 ( V_28 -> V_114 ) ;
V_370 = F_53 ( V_28 -> V_100 ) ;
if ( V_30 -> V_378 == V_379 ||
V_30 -> V_378 == V_380 ||
V_30 -> V_378 == V_381 ) {
V_371 = 1 ;
V_372 = V_30 -> V_382 ;
} else if ( V_30 -> V_378 == V_383 ) {
V_371 = 4 ;
V_372 = V_30 -> V_382 ;
} else if ( F_218 ( & V_368 -> V_384 ) ) {
V_371 = 2 ;
V_372 = V_368 -> V_384 . V_362 ;
} else {
V_371 = 0 ;
V_372 = V_363 ;
}
V_377 = F_219 ( V_368 ) ;
if ( V_377 == V_152 )
V_376 = V_368 -> V_385 ;
else
V_376 = F_220 ( int , V_34 -> V_286 - V_34 -> V_386 , 0 ) ;
F_212 ( V_42 ,
L_5
L_7 ,
V_359 ,
V_364 -> V_18 [ 0 ] , V_364 -> V_18 [ 1 ] ,
V_364 -> V_18 [ 2 ] , V_364 -> V_18 [ 3 ] , V_370 ,
V_20 -> V_18 [ 0 ] , V_20 -> V_18 [ 1 ] ,
V_20 -> V_18 [ 2 ] , V_20 -> V_18 [ 3 ] , V_369 ,
V_377 ,
V_34 -> V_71 - V_34 -> V_137 ,
V_376 ,
V_371 ,
F_221 ( V_372 - V_363 ) ,
V_30 -> V_387 ,
F_214 ( F_215 ( V_42 ) , F_216 ( V_368 ) ) ,
V_30 -> V_388 ,
F_222 ( V_368 ) ,
F_223 ( & V_368 -> V_389 ) , V_368 ,
F_213 ( V_30 -> V_390 ) ,
F_213 ( V_30 -> V_391 . V_392 ) ,
( V_30 -> V_391 . V_393 << 1 ) | V_30 -> V_391 . V_394 ,
V_34 -> V_395 ,
V_377 == V_152 ?
V_374 -> V_396 :
( F_224 ( V_34 ) ? - 1 : V_34 -> V_397 )
) ;
}
static void F_225 ( struct V_358 * V_42 ,
struct V_272 * V_273 , int V_359 )
{
long V_398 = V_273 -> V_399 . V_362 - V_363 ;
const struct V_4 * V_20 , * V_364 ;
T_7 V_369 , V_370 ;
V_20 = & V_273 -> V_400 ;
V_364 = & V_273 -> V_401 ;
V_369 = F_53 ( V_273 -> V_402 ) ;
V_370 = F_53 ( V_273 -> V_403 ) ;
F_212 ( V_42 ,
L_5
L_8 ,
V_359 ,
V_364 -> V_18 [ 0 ] , V_364 -> V_18 [ 1 ] ,
V_364 -> V_18 [ 2 ] , V_364 -> V_18 [ 3 ] , V_370 ,
V_20 -> V_18 [ 0 ] , V_20 -> V_18 [ 1 ] ,
V_20 -> V_18 [ 2 ] , V_20 -> V_18 [ 3 ] , V_369 ,
V_273 -> V_404 , 0 , 0 ,
3 , F_221 ( V_398 ) , 0 , 0 , 0 , 0 ,
F_223 ( & V_273 -> V_405 ) , V_273 ) ;
}
static int F_226 ( struct V_358 * V_42 , void * V_406 )
{
struct V_407 * V_408 ;
struct V_2 * V_3 = V_406 ;
if ( V_406 == V_409 ) {
F_227 ( V_42 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_146;
}
V_408 = V_42 -> V_410 ;
if ( V_3 -> V_121 == V_142 )
F_225 ( V_42 , V_406 , V_408 -> V_411 ) ;
else if ( V_3 -> V_121 == V_143 )
F_211 ( V_42 , V_406 , V_408 -> V_411 ) ;
else
F_217 ( V_42 , V_406 , V_408 -> V_411 ) ;
V_146:
return 0 ;
}
int T_8 F_228 ( struct V_133 * V_133 )
{
return F_229 ( V_133 , & V_412 ) ;
}
void F_230 ( struct V_133 * V_133 )
{
F_231 ( V_133 , & V_412 ) ;
}
static int T_8 F_232 ( struct V_133 * V_133 )
{
return F_233 ( & V_133 -> V_248 . F_14 , V_413 ,
V_414 , V_94 , V_133 ) ;
}
static void T_9 F_234 ( struct V_133 * V_133 )
{
F_235 ( V_133 -> V_248 . F_14 ) ;
}
static void T_9 F_236 ( struct V_415 * V_416 )
{
F_237 ( & V_139 , V_50 ) ;
}
int T_10 F_238 ( void )
{
int V_335 ;
V_335 = F_239 ( & V_417 , V_94 ) ;
if ( V_335 )
goto V_146;
V_335 = F_240 ( & V_418 ) ;
if ( V_335 )
goto V_419;
V_335 = F_241 ( & V_420 ) ;
if ( V_335 )
goto V_421;
V_146:
return V_335 ;
V_421:
F_242 ( & V_418 ) ;
V_419:
F_243 ( & V_417 , V_94 ) ;
goto V_146;
}
void F_244 ( void )
{
F_245 ( & V_420 ) ;
F_242 ( & V_418 ) ;
F_243 ( & V_417 , V_94 ) ;
}
