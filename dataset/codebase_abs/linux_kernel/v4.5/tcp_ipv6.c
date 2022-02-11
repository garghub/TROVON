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
static int F_12 ( struct V_2 * V_3 , struct V_21 * V_22 ,
int V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_22 ;
struct V_26 * V_27 = F_5 ( V_3 ) ;
struct V_28 * V_29 = F_13 ( V_3 ) ;
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 = F_14 ( V_3 ) ;
struct V_4 * V_18 = NULL , * V_34 , V_35 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
struct V_8 * V_9 ;
int V_40 ;
int V_41 ;
if ( V_23 < V_42 )
return - V_43 ;
if ( V_25 -> V_44 != V_45 )
return - V_46 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_31 -> V_47 ) {
V_39 . V_48 = V_25 -> V_49 & V_50 ;
F_15 ( V_39 . V_48 ) ;
if ( V_39 . V_48 & V_51 ) {
struct V_52 * V_48 ;
V_48 = F_16 ( V_3 , V_39 . V_48 ) ;
if ( ! V_48 )
return - V_43 ;
F_17 ( V_48 ) ;
}
}
if ( F_18 ( & V_25 -> V_53 ) )
V_25 -> V_53 . V_54 [ 15 ] = 0x1 ;
V_40 = F_19 ( & V_25 -> V_53 ) ;
if ( V_40 & V_55 )
return - V_56 ;
if ( V_40 & V_57 ) {
if ( V_23 >= sizeof( struct V_24 ) &&
V_25 -> V_58 ) {
if ( V_3 -> V_59 &&
V_3 -> V_59 != V_25 -> V_58 )
return - V_43 ;
V_3 -> V_59 = V_25 -> V_58 ;
}
if ( ! V_3 -> V_59 )
return - V_43 ;
}
if ( V_33 -> V_60 . V_61 &&
! F_20 ( & V_3 -> V_62 , & V_25 -> V_53 ) ) {
V_33 -> V_60 . V_63 = 0 ;
V_33 -> V_60 . V_61 = 0 ;
V_33 -> V_64 = 0 ;
}
V_3 -> V_62 = V_25 -> V_53 ;
V_31 -> V_65 = V_39 . V_48 ;
if ( V_40 == V_66 ) {
T_2 V_67 = V_29 -> V_68 ;
struct V_69 sin ;
F_21 ( V_3 , L_1 ) ;
if ( F_22 ( V_3 ) )
return - V_56 ;
sin . V_70 = V_71 ;
sin . V_72 = V_25 -> V_73 ;
sin . V_74 . V_75 = V_25 -> V_53 . V_17 [ 3 ] ;
V_29 -> V_76 = & V_77 ;
V_3 -> V_78 = V_79 ;
#ifdef F_23
V_33 -> V_80 = & V_81 ;
#endif
V_41 = F_24 ( V_3 , (struct V_21 * ) & sin , sizeof( sin ) ) ;
if ( V_41 ) {
V_29 -> V_68 = V_67 ;
V_29 -> V_76 = & V_82 ;
V_3 -> V_78 = V_83 ;
#ifdef F_23
V_33 -> V_80 = & V_84 ;
#endif
goto V_85;
}
V_31 -> V_18 = V_3 -> V_86 ;
return V_41 ;
}
if ( ! F_18 ( & V_3 -> V_86 ) )
V_18 = & V_3 -> V_86 ;
V_39 . V_87 = V_88 ;
V_39 . V_16 = V_3 -> V_62 ;
V_39 . V_18 = V_18 ? * V_18 : V_31 -> V_18 ;
V_39 . V_89 = V_3 -> V_59 ;
V_39 . V_90 = V_3 -> V_91 ;
V_39 . V_92 = V_25 -> V_73 ;
V_39 . V_93 = V_27 -> V_94 ;
V_37 = F_25 ( V_31 -> V_37 , F_26 ( V_3 ) ) ;
V_34 = F_27 ( & V_39 , V_37 , & V_35 ) ;
F_28 ( V_3 , F_29 ( & V_39 ) ) ;
V_9 = F_30 ( V_3 , & V_39 , V_34 ) ;
if ( F_31 ( V_9 ) ) {
V_41 = F_32 ( V_9 ) ;
goto V_85;
}
if ( ! V_18 ) {
V_18 = & V_39 . V_18 ;
V_3 -> V_86 = * V_18 ;
}
V_31 -> V_18 = * V_18 ;
V_27 -> V_95 = V_96 ;
V_3 -> V_97 = V_98 ;
F_33 ( V_3 , V_9 , NULL , NULL ) ;
if ( V_99 . V_100 &&
! V_33 -> V_60 . V_61 &&
F_20 ( & V_39 . V_16 , & V_3 -> V_62 ) )
F_34 ( V_3 , V_9 ) ;
V_29 -> V_68 = 0 ;
if ( V_37 )
V_29 -> V_68 = V_37 -> V_101 +
V_37 -> V_102 ;
V_33 -> V_60 . V_103 = V_104 - sizeof( struct V_105 ) - sizeof( struct V_106 ) ;
V_27 -> V_107 = V_25 -> V_73 ;
F_35 ( V_3 , V_108 ) ;
V_41 = F_36 ( & V_99 , V_3 ) ;
if ( V_41 )
goto V_109;
F_37 ( V_3 ) ;
if ( ! V_33 -> V_64 && F_38 ( ! V_33 -> V_110 ) )
V_33 -> V_64 = F_9 ( V_31 -> V_18 . V_17 ,
V_3 -> V_62 . V_17 ,
V_27 -> V_94 ,
V_27 -> V_107 ) ;
V_41 = F_39 ( V_3 ) ;
if ( V_41 )
goto V_109;
return 0 ;
V_109:
F_35 ( V_3 , V_111 ) ;
F_40 ( V_3 ) ;
V_85:
V_27 -> V_107 = 0 ;
V_3 -> V_112 = 0 ;
return V_41 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_113 ) & ( V_114 | V_115 ) )
return;
V_9 = F_42 ( V_3 , F_14 ( V_3 ) -> V_116 ) ;
if ( ! V_9 )
return;
if ( F_13 ( V_3 ) -> V_117 > F_43 ( V_9 ) ) {
F_44 ( V_3 , F_43 ( V_9 ) ) ;
F_45 ( V_3 ) ;
}
}
static void F_46 ( struct V_6 * V_7 , struct V_118 * V_37 ,
T_3 type , T_3 V_119 , int V_120 , T_4 V_121 )
{
const struct V_106 * V_122 = ( const struct V_106 * ) V_7 -> V_123 ;
const struct V_105 * V_124 = (struct V_105 * ) ( V_7 -> V_123 + V_120 ) ;
struct V_125 * V_125 = F_47 ( V_7 -> V_126 ) ;
struct V_127 * V_128 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_1 V_129 , V_130 ;
struct V_2 * V_3 ;
bool V_131 ;
int V_41 ;
V_3 = F_48 ( V_125 , & V_132 ,
& V_122 -> V_16 , V_124 -> V_19 ,
& V_122 -> V_18 , F_49 ( V_124 -> V_20 ) ,
V_7 -> V_126 -> V_133 ) ;
if ( ! V_3 ) {
F_50 ( V_125 , F_51 ( V_7 -> V_126 ) ,
V_134 ) ;
return;
}
if ( V_3 -> V_113 == V_135 ) {
F_52 ( F_53 ( V_3 ) ) ;
return;
}
V_129 = F_54 ( V_124 -> V_129 ) ;
V_131 = F_55 ( type , V_119 , & V_41 ) ;
if ( V_3 -> V_113 == V_136 )
return F_56 ( V_3 , V_129 , V_131 ) ;
F_57 ( V_3 ) ;
if ( F_26 ( V_3 ) && type != V_137 )
F_58 ( V_125 , V_138 ) ;
if ( V_3 -> V_113 == V_111 )
goto V_139;
if ( F_10 ( V_7 ) -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_58 ( V_125 , V_142 ) ;
goto V_139;
}
V_33 = F_14 ( V_3 ) ;
V_128 = V_33 -> V_143 ;
V_130 = V_128 ? F_59 ( V_128 ) -> V_144 : V_33 -> V_130 ;
if ( V_3 -> V_113 != V_145 &&
! F_60 ( V_129 , V_130 , V_33 -> V_146 ) ) {
F_58 ( V_125 , V_147 ) ;
goto V_139;
}
V_31 = F_6 ( V_3 ) ;
if ( type == V_148 ) {
struct V_8 * V_9 = F_61 ( V_3 , V_31 -> V_149 ) ;
if ( V_9 )
V_9 -> V_150 -> V_151 ( V_9 , V_3 , V_7 ) ;
goto V_139;
}
if ( type == V_137 ) {
if ( V_3 -> V_113 == V_145 )
goto V_139;
if ( ! F_62 ( V_3 ) )
goto V_139;
V_33 -> V_116 = F_54 ( V_121 ) ;
if ( ! F_26 ( V_3 ) )
F_41 ( V_3 ) ;
else if ( ! F_63 ( V_152 ,
& V_33 -> V_153 ) )
F_64 ( V_3 ) ;
goto V_139;
}
switch ( V_3 -> V_113 ) {
case V_108 :
case V_154 :
if ( V_128 && ! V_128 -> V_3 )
break;
if ( ! F_26 ( V_3 ) ) {
V_3 -> V_155 = V_41 ;
V_3 -> V_156 ( V_3 ) ;
F_65 ( V_3 ) ;
} else
V_3 -> V_157 = V_41 ;
goto V_139;
}
if ( ! F_26 ( V_3 ) && V_31 -> V_158 ) {
V_3 -> V_155 = V_41 ;
V_3 -> V_156 ( V_3 ) ;
} else
V_3 -> V_157 = V_41 ;
V_139:
F_66 ( V_3 ) ;
F_67 ( V_3 ) ;
}
static int F_68 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_159 * V_160 ,
struct V_127 * V_161 ,
struct V_162 * V_163 ,
bool V_164 )
{
struct V_165 * V_166 = F_69 ( V_161 ) ;
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_38 * V_39 = & V_160 -> V_167 . V_168 ;
struct V_6 * V_7 ;
int V_41 = - V_169 ;
if ( ! V_9 && ( V_9 = F_70 ( V_3 , V_39 , V_161 ,
V_88 ) ) == NULL )
goto V_170;
V_7 = F_71 ( V_3 , V_9 , V_161 , V_163 , V_164 ) ;
if ( V_7 ) {
F_72 ( V_7 , & V_166 -> V_171 ,
& V_166 -> V_172 ) ;
V_39 -> V_16 = V_166 -> V_172 ;
if ( V_31 -> V_173 && V_166 -> V_174 )
V_39 -> V_48 = V_52 ( F_10 ( V_166 -> V_174 ) ) ;
F_73 () ;
V_41 = F_74 ( V_3 , V_7 , V_39 , F_75 ( V_31 -> V_37 ) ,
V_31 -> V_175 ) ;
F_76 () ;
V_41 = F_77 ( V_41 ) ;
}
V_170:
return V_41 ;
}
static void F_78 ( struct V_127 * V_161 )
{
F_79 ( F_69 ( V_161 ) -> V_174 ) ;
}
static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_80 ( V_3 , (union V_176 * ) V_5 , V_45 ) ;
}
static struct V_1 * F_81 ( const struct V_2 * V_3 ,
const struct V_2 * V_177 )
{
return F_1 ( V_3 , & V_177 -> V_62 ) ;
}
static int F_82 ( struct V_2 * V_3 , char T_5 * V_178 ,
int V_179 )
{
struct V_180 V_181 ;
struct V_24 * V_182 = (struct V_24 * ) & V_181 . V_183 ;
if ( V_179 < sizeof( V_181 ) )
return - V_43 ;
if ( F_83 ( & V_181 , V_178 , sizeof( V_181 ) ) )
return - V_184 ;
if ( V_182 -> V_44 != V_45 )
return - V_43 ;
if ( ! V_181 . V_185 ) {
if ( F_84 ( & V_182 -> V_53 ) )
return F_85 ( V_3 , (union V_176 * ) & V_182 -> V_53 . V_17 [ 3 ] ,
V_71 ) ;
return F_85 ( V_3 , (union V_176 * ) & V_182 -> V_53 ,
V_45 ) ;
}
if ( V_181 . V_185 > V_186 )
return - V_43 ;
if ( F_84 ( & V_182 -> V_53 ) )
return F_86 ( V_3 , (union V_176 * ) & V_182 -> V_53 . V_17 [ 3 ] ,
V_71 , V_181 . V_187 , V_181 . V_185 , V_188 ) ;
return F_86 ( V_3 , (union V_176 * ) & V_182 -> V_53 ,
V_45 , V_181 . V_187 , V_181 . V_185 , V_188 ) ;
}
static int F_87 ( struct V_189 * V_190 ,
const struct V_4 * V_16 ,
const struct V_4 * V_18 , int V_191 )
{
struct V_192 * V_193 ;
struct V_194 V_195 ;
V_193 = & V_190 -> V_196 . V_168 ;
V_193 -> V_18 = * V_18 ;
V_193 -> V_16 = * V_16 ;
V_193 -> V_197 = F_88 ( V_88 ) ;
V_193 -> V_198 = F_88 ( V_191 ) ;
F_89 ( & V_195 , V_193 , sizeof( * V_193 ) ) ;
return F_90 ( & V_190 -> V_199 , & V_195 , sizeof( * V_193 ) ) ;
}
static int F_91 ( char * V_200 , struct V_1 * V_201 ,
const struct V_4 * V_16 , struct V_4 * V_18 ,
const struct V_105 * V_124 )
{
struct V_189 * V_190 ;
struct V_202 * V_203 ;
V_190 = F_92 () ;
if ( ! V_190 )
goto V_204;
V_203 = & V_190 -> V_199 ;
if ( F_93 ( V_203 ) )
goto V_205;
if ( F_87 ( V_190 , V_16 , V_18 , V_124 -> V_206 << 2 ) )
goto V_205;
if ( F_94 ( V_190 , V_124 ) )
goto V_205;
if ( F_95 ( V_190 , V_201 ) )
goto V_205;
if ( F_96 ( V_203 , V_200 ) )
goto V_205;
F_97 () ;
return 0 ;
V_205:
F_97 () ;
V_204:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static int F_98 ( char * V_200 ,
const struct V_1 * V_201 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_18 , * V_16 ;
struct V_189 * V_190 ;
struct V_202 * V_203 ;
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_18 = & V_3 -> V_86 ;
V_16 = & V_3 -> V_62 ;
} else {
const struct V_106 * V_207 = F_10 ( V_7 ) ;
V_18 = & V_207 -> V_18 ;
V_16 = & V_207 -> V_16 ;
}
V_190 = F_92 () ;
if ( ! V_190 )
goto V_204;
V_203 = & V_190 -> V_199 ;
if ( F_93 ( V_203 ) )
goto V_205;
if ( F_87 ( V_190 , V_16 , V_18 , V_7 -> V_198 ) )
goto V_205;
if ( F_94 ( V_190 , V_124 ) )
goto V_205;
if ( F_99 ( V_190 , V_7 , V_124 -> V_206 << 2 ) )
goto V_205;
if ( F_95 ( V_190 , V_201 ) )
goto V_205;
if ( F_96 ( V_203 , V_200 ) )
goto V_205;
F_97 () ;
return 0 ;
V_205:
F_97 () ;
V_204:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static bool F_100 ( const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
#ifdef F_23
const T_6 * V_208 = NULL ;
struct V_1 * V_209 ;
const struct V_106 * V_207 = F_10 ( V_7 ) ;
const struct V_105 * V_124 = F_11 ( V_7 ) ;
int V_210 ;
T_3 V_211 [ 16 ] ;
V_209 = F_1 ( V_3 , & V_207 -> V_18 ) ;
V_208 = F_101 ( V_124 ) ;
if ( ! V_209 && ! V_208 )
return false ;
if ( V_209 && ! V_208 ) {
F_58 ( F_102 ( V_3 ) , V_212 ) ;
return true ;
}
if ( ! V_209 && V_208 ) {
F_58 ( F_102 ( V_3 ) , V_213 ) ;
return true ;
}
V_210 = F_98 ( V_211 ,
V_209 ,
NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 ) {
F_103 ( L_2 ,
V_210 ? L_3 : L_4 ,
& V_207 -> V_18 , F_49 ( V_124 -> V_20 ) ,
& V_207 -> V_16 , F_49 ( V_124 -> V_19 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_104 ( struct V_127 * V_161 ,
const struct V_2 * V_214 ,
struct V_6 * V_7 )
{
struct V_165 * V_166 = F_69 ( V_161 ) ;
const struct V_30 * V_31 = F_6 ( V_214 ) ;
V_166 -> V_172 = F_10 ( V_7 ) -> V_18 ;
V_166 -> V_171 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_214 -> V_59 &&
F_19 ( & V_166 -> V_172 ) & V_57 )
V_166 -> V_215 = F_105 ( V_7 ) ;
if ( ! F_106 ( V_7 ) -> V_216 &&
( F_107 ( V_214 , V_7 , & F_106 ( V_7 ) -> V_217 . V_218 ) ||
V_31 -> V_219 . V_220 . V_221 ||
V_31 -> V_219 . V_220 . V_222 || V_31 -> V_219 . V_220 . V_223 ||
V_31 -> V_219 . V_220 . V_224 || V_31 -> V_173 ) ) {
F_108 ( & V_7 -> V_225 ) ;
V_166 -> V_174 = V_7 ;
}
}
static struct V_8 * F_109 ( const struct V_2 * V_3 ,
struct V_159 * V_160 ,
const struct V_127 * V_161 ,
bool * V_226 )
{
if ( V_226 )
* V_226 = true ;
return F_70 ( V_3 , & V_160 -> V_167 . V_168 , V_161 , V_88 ) ;
}
static void F_110 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_227 , T_2 V_228 , T_2 V_229 , T_2 V_230 ,
int V_231 , struct V_1 * V_201 , int V_232 ,
T_3 V_175 , T_2 V_233 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
struct V_105 * V_234 ;
struct V_6 * V_235 ;
struct V_38 V_39 ;
struct V_125 * V_125 = V_3 ? F_102 ( V_3 ) : F_47 ( F_3 ( V_7 ) -> V_126 ) ;
struct V_2 * V_236 = V_125 -> V_237 . F_14 ;
unsigned int V_238 = sizeof( struct V_105 ) ;
struct V_8 * V_9 ;
T_4 * V_239 ;
if ( V_230 )
V_238 += V_240 ;
#ifdef F_23
if ( V_201 )
V_238 += V_241 ;
#endif
V_235 = F_111 ( V_242 + sizeof( struct V_106 ) + V_238 ,
V_243 ) ;
if ( ! V_235 )
return;
F_112 ( V_235 , V_242 + sizeof( struct V_106 ) + V_238 ) ;
V_234 = (struct V_105 * ) F_113 ( V_235 , V_238 ) ;
F_114 ( V_235 ) ;
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
V_234 -> V_19 = V_124 -> V_20 ;
V_234 -> V_20 = V_124 -> V_19 ;
V_234 -> V_206 = V_238 / 4 ;
V_234 -> V_129 = F_115 ( V_129 ) ;
V_234 -> V_244 = F_115 ( V_227 ) ;
V_234 -> V_227 = ! V_232 || ! V_124 -> V_227 ;
V_234 -> V_232 = V_232 ;
V_234 -> V_245 = F_116 ( V_228 ) ;
V_239 = ( T_4 * ) ( V_234 + 1 ) ;
if ( V_230 ) {
* V_239 ++ = F_115 ( ( V_246 << 24 ) | ( V_246 << 16 ) |
( V_247 << 8 ) | V_248 ) ;
* V_239 ++ = F_115 ( V_229 ) ;
* V_239 ++ = F_115 ( V_230 ) ;
}
#ifdef F_23
if ( V_201 ) {
* V_239 ++ = F_115 ( ( V_246 << 24 ) | ( V_246 << 16 ) |
( V_249 << 8 ) | V_250 ) ;
F_91 ( ( T_6 * ) V_239 , V_201 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , V_234 ) ;
}
#endif
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_16 = F_10 ( V_7 ) -> V_18 ;
V_39 . V_18 = F_10 ( V_7 ) -> V_16 ;
V_39 . V_48 = V_233 ;
V_235 -> V_251 = V_252 ;
V_235 -> V_253 = 0 ;
F_72 ( V_235 , & V_39 . V_18 , & V_39 . V_16 ) ;
V_39 . V_87 = V_88 ;
if ( F_117 ( & V_39 . V_16 ) && ! V_231 )
V_39 . V_89 = F_105 ( V_7 ) ;
else
V_39 . V_89 = V_231 ;
V_39 . V_90 = F_118 ( V_125 , V_7 -> V_254 ) ;
V_39 . V_92 = V_234 -> V_19 ;
V_39 . V_93 = V_234 -> V_20 ;
F_119 ( V_7 , F_29 ( & V_39 ) ) ;
V_9 = F_30 ( V_236 , & V_39 , NULL ) ;
if ( ! F_31 ( V_9 ) ) {
F_120 ( V_235 , V_9 ) ;
F_74 ( V_236 , V_235 , & V_39 , NULL , V_175 ) ;
F_121 ( V_125 , V_255 ) ;
if ( V_232 )
F_121 ( V_125 , V_256 ) ;
return;
}
F_79 ( V_235 ) ;
}
static void F_122 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
T_2 V_129 = 0 , V_244 = 0 ;
struct V_1 * V_201 = NULL ;
#ifdef F_23
const T_6 * V_208 = NULL ;
struct V_106 * V_257 = F_10 ( V_7 ) ;
unsigned char V_211 [ 16 ] ;
int V_210 ;
struct V_2 * V_258 = NULL ;
#endif
int V_231 ;
if ( V_124 -> V_232 )
return;
if ( ! V_3 && ! F_123 ( V_7 ) )
return;
#ifdef F_23
V_208 = F_101 ( V_124 ) ;
if ( V_3 && F_124 ( V_3 ) ) {
V_201 = F_1 ( V_3 , & V_257 -> V_18 ) ;
} else if ( V_208 ) {
V_258 = F_125 ( F_47 ( F_3 ( V_7 ) -> V_126 ) ,
& V_132 , & V_257 -> V_18 ,
V_124 -> V_20 , & V_257 -> V_16 ,
F_49 ( V_124 -> V_20 ) , F_105 ( V_7 ) ) ;
if ( ! V_258 )
return;
F_73 () ;
V_201 = F_1 ( V_258 , & V_257 -> V_18 ) ;
if ( ! V_201 )
goto V_259;
V_210 = F_98 ( V_211 , V_201 , NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 )
goto V_259;
}
#endif
if ( V_124 -> V_227 )
V_129 = F_54 ( V_124 -> V_244 ) ;
else
V_244 = F_54 ( V_124 -> V_129 ) + V_124 -> V_260 + V_124 -> V_261 + V_7 -> V_198 -
( V_124 -> V_206 << 2 ) ;
V_231 = V_3 ? V_3 -> V_59 : 0 ;
F_110 ( V_3 , V_7 , V_129 , V_244 , 0 , 0 , 0 , V_231 , V_201 , 1 , 0 , 0 ) ;
#ifdef F_23
V_259:
if ( V_258 ) {
F_76 () ;
F_67 ( V_258 ) ;
}
#endif
}
static void F_126 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_227 , T_2 V_228 , T_2 V_229 , T_2 V_230 , int V_231 ,
struct V_1 * V_201 , T_3 V_175 ,
T_2 V_233 )
{
F_110 ( V_3 , V_7 , V_129 , V_227 , V_228 , V_229 , V_230 , V_231 , V_201 , 0 ,
V_175 , V_233 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_262 * V_263 = F_53 ( V_3 ) ;
struct V_264 * V_265 = F_128 ( V_3 ) ;
F_126 ( V_3 , V_7 , V_265 -> V_266 , V_265 -> V_267 ,
V_265 -> V_268 >> V_263 -> V_269 ,
V_270 + V_265 -> V_271 ,
V_265 -> V_272 , V_263 -> V_273 , F_129 ( V_265 ) ,
V_263 -> V_274 , F_88 ( V_263 -> V_275 ) ) ;
F_52 ( V_263 ) ;
}
static void F_130 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 )
{
F_126 ( V_3 , V_7 , ( V_3 -> V_113 == V_145 ) ?
F_59 ( V_161 ) -> V_144 + 1 : F_14 ( V_3 ) -> V_146 ,
F_59 ( V_161 ) -> V_276 , V_161 -> V_277 ,
V_270 , V_161 -> V_63 , V_3 -> V_59 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_131 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_132
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( ! V_124 -> V_260 )
V_3 = F_133 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_134 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_197 == F_116 ( V_278 ) )
return F_135 ( V_3 , V_7 ) ;
if ( ! F_123 ( V_7 ) )
goto V_279;
return F_136 ( & V_280 ,
& V_281 , V_3 , V_7 ) ;
V_279:
F_58 ( F_102 ( V_3 ) , V_282 ) ;
return 0 ;
}
static struct V_2 * F_137 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 ,
struct V_8 * V_9 ,
struct V_127 * V_283 ,
bool * V_284 )
{
struct V_165 * V_166 ;
struct V_30 * V_285 ;
const struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_286 * V_287 ;
struct V_26 * V_288 ;
struct V_32 * V_289 ;
struct V_2 * V_290 ;
#ifdef F_23
struct V_1 * V_201 ;
#endif
struct V_38 V_39 ;
if ( V_7 -> V_197 == F_116 ( V_278 ) ) {
V_290 = F_138 ( V_3 , V_7 , V_161 , V_9 ,
V_283 , V_284 ) ;
if ( ! V_290 )
return NULL ;
V_287 = (struct V_286 * ) V_290 ;
F_5 ( V_290 ) -> V_291 = & V_287 -> V_292 ;
V_288 = F_5 ( V_290 ) ;
V_285 = F_6 ( V_290 ) ;
V_289 = F_14 ( V_290 ) ;
memcpy ( V_285 , V_31 , sizeof( struct V_30 ) ) ;
V_285 -> V_18 = V_290 -> V_86 ;
F_13 ( V_290 ) -> V_76 = & V_77 ;
V_290 -> V_78 = V_79 ;
#ifdef F_23
V_289 -> V_80 = & V_81 ;
#endif
V_285 -> V_293 = NULL ;
V_285 -> V_294 = NULL ;
V_285 -> V_295 = NULL ;
V_285 -> V_37 = NULL ;
V_285 -> V_296 = F_105 ( V_7 ) ;
V_285 -> V_297 = F_10 ( V_7 ) -> V_140 ;
V_285 -> V_298 = F_139 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_173 )
V_285 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
F_44 ( V_290 , F_13 ( V_290 ) -> V_117 ) ;
return V_290 ;
}
V_166 = F_69 ( V_161 ) ;
if ( F_140 ( V_3 ) )
goto V_299;
if ( ! V_9 ) {
V_9 = F_70 ( V_3 , & V_39 , V_161 , V_88 ) ;
if ( ! V_9 )
goto V_139;
}
V_290 = F_141 ( V_3 , V_161 , V_7 ) ;
if ( ! V_290 )
goto V_300;
V_290 -> V_97 = V_98 ;
F_33 ( V_290 , V_9 , NULL , NULL ) ;
F_2 ( V_290 , V_7 ) ;
V_287 = (struct V_286 * ) V_290 ;
F_5 ( V_290 ) -> V_291 = & V_287 -> V_292 ;
V_289 = F_14 ( V_290 ) ;
V_288 = F_5 ( V_290 ) ;
V_285 = F_6 ( V_290 ) ;
memcpy ( V_285 , V_31 , sizeof( struct V_30 ) ) ;
V_290 -> V_62 = V_166 -> V_172 ;
V_285 -> V_18 = V_166 -> V_171 ;
V_290 -> V_86 = V_166 -> V_171 ;
V_290 -> V_59 = V_166 -> V_215 ;
V_288 -> V_301 = NULL ;
V_285 -> V_293 = NULL ;
V_285 -> V_294 = NULL ;
V_285 -> V_219 . V_302 = V_31 -> V_219 . V_302 ;
V_285 -> V_295 = NULL ;
V_285 -> V_37 = NULL ;
V_285 -> V_296 = F_105 ( V_7 ) ;
V_285 -> V_297 = F_10 ( V_7 ) -> V_140 ;
V_285 -> V_298 = F_139 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_173 )
V_285 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
V_37 = F_75 ( V_31 -> V_37 ) ;
if ( V_37 ) {
V_37 = F_142 ( V_290 , V_37 ) ;
F_143 ( V_285 -> V_37 , V_37 ) ;
}
F_13 ( V_290 ) -> V_68 = 0 ;
if ( V_37 )
F_13 ( V_290 ) -> V_68 = V_37 -> V_102 +
V_37 -> V_101 ;
F_144 ( V_290 , V_9 ) ;
F_44 ( V_290 , F_43 ( V_9 ) ) ;
V_289 -> V_303 = F_145 ( V_9 ) ;
if ( F_14 ( V_3 ) -> V_60 . V_304 &&
F_14 ( V_3 ) -> V_60 . V_304 < V_289 -> V_303 )
V_289 -> V_303 = F_14 ( V_3 ) -> V_60 . V_304 ;
F_146 ( V_290 ) ;
V_288 -> V_305 = V_288 -> V_306 = V_96 ;
V_288 -> V_95 = V_96 ;
#ifdef F_23
V_201 = F_1 ( V_3 , & V_290 -> V_62 ) ;
if ( V_201 ) {
F_86 ( V_290 , (union V_176 * ) & V_290 -> V_62 ,
V_45 , V_201 -> V_201 , V_201 -> V_307 ,
F_147 ( V_3 , V_243 ) ) ;
}
#endif
if ( F_148 ( V_3 , V_290 ) < 0 ) {
F_149 ( V_290 ) ;
F_65 ( V_290 ) ;
goto V_139;
}
* V_284 = F_150 ( V_290 , F_151 ( V_283 ) ) ;
if ( * V_284 ) {
F_152 ( V_289 , V_161 ) ;
if ( V_166 -> V_174 ) {
V_285 -> V_295 = F_153 ( V_166 -> V_174 ,
F_147 ( V_3 , V_243 ) ) ;
F_154 ( V_166 -> V_174 ) ;
V_166 -> V_174 = NULL ;
if ( V_285 -> V_295 )
F_155 ( V_285 -> V_295 , V_290 ) ;
}
}
return V_290 ;
V_299:
F_58 ( F_102 ( V_3 ) , V_308 ) ;
V_300:
F_156 ( V_9 ) ;
V_139:
F_58 ( F_102 ( V_3 ) , V_282 ) ;
return NULL ;
}
static int V_83 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_6 * V_309 = NULL ;
if ( V_7 -> V_197 == F_116 ( V_278 ) )
return V_79 ( V_3 , V_7 ) ;
if ( F_157 ( V_3 , V_7 ) )
goto V_310;
if ( V_31 -> V_219 . V_302 )
V_309 = F_153 ( V_7 , F_147 ( V_3 , V_243 ) ) ;
if ( V_3 -> V_113 == V_311 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_158 ( V_3 , V_7 ) ;
F_159 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_150 -> V_312 ( V_9 , V_31 -> V_15 ) == NULL ) {
F_156 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_160 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_198 ) ;
if ( V_309 )
goto V_313;
return 0 ;
}
if ( F_161 ( V_7 ) )
goto V_314;
if ( V_3 -> V_113 == V_145 ) {
struct V_2 * V_315 = F_131 ( V_3 , V_7 ) ;
if ( ! V_315 )
goto V_310;
if ( V_315 != V_3 ) {
F_158 ( V_315 , V_7 ) ;
F_159 ( V_315 , V_7 ) ;
if ( F_162 ( V_3 , V_315 , V_7 ) )
goto V_316;
if ( V_309 )
F_163 ( V_309 ) ;
return 0 ;
}
} else
F_158 ( V_3 , V_7 ) ;
if ( F_164 ( V_3 , V_7 ) )
goto V_316;
if ( V_309 )
goto V_313;
return 0 ;
V_316:
F_122 ( V_3 , V_7 ) ;
V_310:
if ( V_309 )
F_163 ( V_309 ) ;
F_79 ( V_7 ) ;
return 0 ;
V_314:
F_121 ( F_102 ( V_3 ) , V_317 ) ;
F_121 ( F_102 ( V_3 ) , V_318 ) ;
goto V_310;
V_313:
V_33 = F_14 ( V_3 ) ;
if ( F_106 ( V_309 ) -> V_319 == V_33 -> V_276 &&
! ( ( 1 << V_3 -> V_113 ) & ( V_115 | V_114 ) ) ) {
if ( V_31 -> V_219 . V_220 . V_221 || V_31 -> V_219 . V_220 . V_222 )
V_31 -> V_296 = F_105 ( V_309 ) ;
if ( V_31 -> V_219 . V_220 . V_223 || V_31 -> V_219 . V_220 . V_224 )
V_31 -> V_297 = F_10 ( V_309 ) -> V_140 ;
if ( V_31 -> V_219 . V_220 . V_320 || V_31 -> V_219 . V_220 . V_321 )
V_31 -> V_298 = F_139 ( F_10 ( V_309 ) ) ;
if ( V_31 -> V_173 )
V_31 -> V_65 = V_52 ( F_10 ( V_309 ) ) ;
if ( F_107 ( V_3 , V_309 , & F_106 ( V_309 ) -> V_217 . V_218 ) ) {
F_155 ( V_309 , V_3 ) ;
V_309 = F_165 ( & V_31 -> V_295 , V_309 ) ;
} else {
F_163 ( V_309 ) ;
V_309 = F_165 ( & V_31 -> V_295 , NULL ) ;
}
}
F_79 ( V_309 ) ;
return 0 ;
}
static void F_166 ( struct V_6 * V_7 , const struct V_106 * V_122 ,
const struct V_105 * V_124 )
{
memmove ( & F_106 ( V_7 ) -> V_217 . V_218 , F_167 ( V_7 ) ,
sizeof( struct V_118 ) ) ;
F_168 () ;
F_106 ( V_7 ) -> V_129 = F_54 ( V_124 -> V_129 ) ;
F_106 ( V_7 ) -> V_319 = ( F_106 ( V_7 ) -> V_129 + V_124 -> V_260 + V_124 -> V_261 +
V_7 -> V_198 - V_124 -> V_206 * 4 ) ;
F_106 ( V_7 ) -> V_244 = F_54 ( V_124 -> V_244 ) ;
F_106 ( V_7 ) -> V_322 = F_169 ( V_124 ) ;
F_106 ( V_7 ) -> V_216 = 0 ;
F_106 ( V_7 ) -> V_323 = F_170 ( V_122 ) ;
F_106 ( V_7 ) -> V_324 = 0 ;
}
static void F_171 ( struct V_6 * V_7 )
{
memmove ( F_167 ( V_7 ) , & F_106 ( V_7 ) -> V_217 . V_218 ,
sizeof( struct V_118 ) ) ;
}
static int F_172 ( struct V_6 * V_7 )
{
const struct V_105 * V_124 ;
const struct V_106 * V_122 ;
struct V_2 * V_3 ;
int V_325 ;
struct V_125 * V_125 = F_47 ( V_7 -> V_126 ) ;
if ( V_7 -> V_326 != V_327 )
goto V_328;
F_121 ( V_125 , V_329 ) ;
if ( ! F_173 ( V_7 , sizeof( struct V_105 ) ) )
goto V_328;
V_124 = F_11 ( V_7 ) ;
if ( V_124 -> V_206 < sizeof( struct V_105 ) / 4 )
goto V_330;
if ( ! F_173 ( V_7 , V_124 -> V_206 * 4 ) )
goto V_328;
if ( F_174 ( V_7 , V_88 , V_331 ) )
goto V_332;
V_124 = F_11 ( V_7 ) ;
V_122 = F_10 ( V_7 ) ;
V_333:
V_3 = F_175 ( & V_132 , V_7 , V_124 -> V_20 , V_124 -> V_19 ,
F_176 ( V_7 ) ) ;
if ( ! V_3 )
goto V_334;
V_335:
if ( V_3 -> V_113 == V_135 )
goto V_336;
if ( V_3 -> V_113 == V_136 ) {
struct V_127 * V_161 = F_177 ( V_3 ) ;
struct V_2 * V_315 ;
V_3 = V_161 -> V_337 ;
F_166 ( V_7 , V_122 , V_124 ) ;
if ( F_100 ( V_3 , V_7 ) ) {
F_178 ( V_161 ) ;
goto V_328;
}
if ( F_179 ( V_3 -> V_113 != V_145 ) ) {
F_180 ( V_3 , V_161 ) ;
goto V_333;
}
F_64 ( V_3 ) ;
V_315 = F_181 ( V_3 , V_7 , V_161 , false ) ;
if ( ! V_315 ) {
F_178 ( V_161 ) ;
goto V_338;
}
if ( V_315 == V_3 ) {
F_178 ( V_161 ) ;
F_171 ( V_7 ) ;
} else if ( F_162 ( V_3 , V_315 , V_7 ) ) {
F_122 ( V_315 , V_7 ) ;
goto V_338;
} else {
F_67 ( V_3 ) ;
return 0 ;
}
}
if ( V_122 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_58 ( V_125 , V_142 ) ;
goto V_338;
}
if ( ! F_182 ( V_3 , V_339 , V_7 ) )
goto V_338;
F_166 ( V_7 , V_122 , V_124 ) ;
if ( F_100 ( V_3 , V_7 ) )
goto V_338;
if ( F_157 ( V_3 , V_7 ) )
goto V_338;
V_7 -> V_126 = NULL ;
if ( V_3 -> V_113 == V_145 ) {
V_325 = V_83 ( V_3 , V_7 ) ;
goto V_340;
}
F_183 ( V_3 ) ;
F_184 ( V_3 ) ;
F_14 ( V_3 ) -> V_341 += F_185 ( V_342 , 1 , F_186 ( V_7 ) -> V_343 ) ;
V_325 = 0 ;
if ( ! F_26 ( V_3 ) ) {
if ( ! F_187 ( V_3 , V_7 ) )
V_325 = V_83 ( V_3 , V_7 ) ;
} else if ( F_179 ( F_188 ( V_3 , V_7 ,
V_3 -> V_344 + V_3 -> V_345 ) ) ) {
F_66 ( V_3 ) ;
F_58 ( V_125 , V_346 ) ;
goto V_338;
}
F_66 ( V_3 ) ;
V_340:
F_67 ( V_3 ) ;
return V_325 ? - 1 : 0 ;
V_334:
if ( ! F_182 ( NULL , V_339 , V_7 ) )
goto V_328;
F_166 ( V_7 , V_122 , V_124 ) ;
if ( F_161 ( V_7 ) ) {
V_332:
F_121 ( V_125 , V_317 ) ;
V_330:
F_121 ( V_125 , V_318 ) ;
} else {
F_122 ( NULL , V_7 ) ;
}
V_328:
F_79 ( V_7 ) ;
return 0 ;
V_338:
F_67 ( V_3 ) ;
goto V_328;
V_336:
if ( ! F_182 ( NULL , V_339 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_328;
}
F_166 ( V_7 , V_122 , V_124 ) ;
if ( F_161 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_332;
}
switch ( F_189 ( F_53 ( V_3 ) , V_7 , V_124 ) ) {
case V_347 :
{
struct V_2 * V_348 ;
V_348 = F_125 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
& F_10 ( V_7 ) -> V_18 , V_124 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_49 ( V_124 -> V_19 ) , F_105 ( V_7 ) ) ;
if ( V_348 ) {
struct V_262 * V_263 = F_53 ( V_3 ) ;
F_190 ( V_263 ) ;
V_3 = V_348 ;
F_171 ( V_7 ) ;
goto V_335;
}
}
case V_349 :
F_127 ( V_3 , V_7 ) ;
break;
case V_350 :
F_171 ( V_7 ) ;
F_122 ( V_3 , V_7 ) ;
F_190 ( F_53 ( V_3 ) ) ;
goto V_328;
case V_351 :
;
}
goto V_328;
}
static void F_191 ( struct V_6 * V_7 )
{
const struct V_106 * V_122 ;
const struct V_105 * V_124 ;
struct V_2 * V_3 ;
if ( V_7 -> V_326 != V_327 )
return;
if ( ! F_173 ( V_7 , F_192 ( V_7 ) + sizeof( struct V_105 ) ) )
return;
V_122 = F_10 ( V_7 ) ;
V_124 = F_11 ( V_7 ) ;
if ( V_124 -> V_206 < sizeof( struct V_105 ) / 4 )
return;
V_3 = F_48 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
& V_122 -> V_18 , V_124 -> V_20 ,
& V_122 -> V_16 , F_49 ( V_124 -> V_19 ) ,
F_176 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_352 = V_353 ;
if ( F_124 ( V_3 ) ) {
struct V_8 * V_9 = F_193 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_194 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_195 ( V_7 , V_9 ) ;
}
}
}
static int F_196 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_13 ( V_3 ) ;
F_197 ( V_3 ) ;
V_29 -> V_76 = & V_82 ;
#ifdef F_23
F_14 ( V_3 ) -> V_80 = & V_84 ;
#endif
return 0 ;
}
static void F_198 ( struct V_2 * V_3 )
{
F_199 ( V_3 ) ;
F_200 ( V_3 ) ;
}
static void F_201 ( struct V_354 * V_129 ,
const struct V_127 * V_161 , int V_355 )
{
long V_356 = V_161 -> V_357 . V_358 - V_359 ;
const struct V_4 * V_360 = & F_69 ( V_161 ) -> V_171 ;
const struct V_4 * V_19 = & F_69 ( V_161 ) -> V_172 ;
if ( V_356 < 0 )
V_356 = 0 ;
F_202 ( V_129 ,
L_5
L_6 ,
V_355 ,
V_360 -> V_17 [ 0 ] , V_360 -> V_17 [ 1 ] ,
V_360 -> V_17 [ 2 ] , V_360 -> V_17 [ 3 ] ,
F_69 ( V_161 ) -> V_361 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_49 ( F_69 ( V_161 ) -> V_362 ) ,
V_154 ,
0 , 0 ,
1 ,
F_203 ( V_356 ) ,
V_161 -> V_363 ,
F_204 ( F_205 ( V_129 ) ,
F_206 ( V_161 -> V_337 ) ) ,
0 ,
0 ,
0 , V_161 ) ;
}
static void F_207 ( struct V_354 * V_129 , struct V_2 * V_364 , int V_355 )
{
const struct V_4 * V_19 , * V_360 ;
T_7 V_365 , V_366 ;
int V_367 ;
unsigned long V_368 ;
const struct V_26 * V_27 = F_5 ( V_364 ) ;
const struct V_32 * V_33 = F_14 ( V_364 ) ;
const struct V_28 * V_29 = F_13 ( V_364 ) ;
const struct V_369 * V_370 = & V_29 -> V_371 . V_370 ;
int V_372 ;
int V_373 ;
V_19 = & V_364 -> V_62 ;
V_360 = & V_364 -> V_86 ;
V_365 = F_49 ( V_27 -> V_107 ) ;
V_366 = F_49 ( V_27 -> V_94 ) ;
if ( V_29 -> V_374 == V_375 ) {
V_367 = 1 ;
V_368 = V_29 -> V_376 ;
} else if ( V_29 -> V_374 == V_377 ) {
V_367 = 4 ;
V_368 = V_29 -> V_376 ;
} else if ( F_208 ( & V_364 -> V_378 ) ) {
V_367 = 2 ;
V_368 = V_364 -> V_378 . V_358 ;
} else {
V_367 = 0 ;
V_368 = V_359 ;
}
V_373 = F_209 ( V_364 ) ;
if ( V_373 == V_145 )
V_372 = V_364 -> V_379 ;
else
V_372 = F_185 ( int , V_33 -> V_276 - V_33 -> V_380 , 0 ) ;
F_202 ( V_129 ,
L_5
L_7 ,
V_355 ,
V_360 -> V_17 [ 0 ] , V_360 -> V_17 [ 1 ] ,
V_360 -> V_17 [ 2 ] , V_360 -> V_17 [ 3 ] , V_366 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_365 ,
V_373 ,
V_33 -> V_64 - V_33 -> V_130 ,
V_372 ,
V_367 ,
F_210 ( V_368 - V_359 ) ,
V_29 -> V_381 ,
F_204 ( F_205 ( V_129 ) , F_206 ( V_364 ) ) ,
V_29 -> V_382 ,
F_211 ( V_364 ) ,
F_212 ( & V_364 -> V_383 ) , V_364 ,
F_203 ( V_29 -> V_384 ) ,
F_203 ( V_29 -> V_385 . V_386 ) ,
( V_29 -> V_385 . V_387 << 1 ) | V_29 -> V_385 . V_388 ,
V_33 -> V_389 ,
V_373 == V_145 ?
V_370 -> V_390 :
( F_213 ( V_33 ) ? - 1 : V_33 -> V_391 )
) ;
}
static void F_214 ( struct V_354 * V_129 ,
struct V_262 * V_263 , int V_355 )
{
long V_392 = V_263 -> V_393 . V_358 - V_359 ;
const struct V_4 * V_19 , * V_360 ;
T_7 V_365 , V_366 ;
V_19 = & V_263 -> V_394 ;
V_360 = & V_263 -> V_395 ;
V_365 = F_49 ( V_263 -> V_396 ) ;
V_366 = F_49 ( V_263 -> V_397 ) ;
F_202 ( V_129 ,
L_5
L_8 ,
V_355 ,
V_360 -> V_17 [ 0 ] , V_360 -> V_17 [ 1 ] ,
V_360 -> V_17 [ 2 ] , V_360 -> V_17 [ 3 ] , V_366 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_365 ,
V_263 -> V_398 , 0 , 0 ,
3 , F_210 ( V_392 ) , 0 , 0 , 0 , 0 ,
F_212 ( & V_263 -> V_399 ) , V_263 ) ;
}
static int F_215 ( struct V_354 * V_129 , void * V_400 )
{
struct V_401 * V_402 ;
struct V_2 * V_3 = V_400 ;
if ( V_400 == V_403 ) {
F_216 ( V_129 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_139;
}
V_402 = V_129 -> V_404 ;
if ( V_3 -> V_113 == V_135 )
F_214 ( V_129 , V_400 , V_402 -> V_405 ) ;
else if ( V_3 -> V_113 == V_136 )
F_201 ( V_129 , V_400 , V_402 -> V_405 ) ;
else
F_207 ( V_129 , V_400 , V_402 -> V_405 ) ;
V_139:
return 0 ;
}
int T_8 F_217 ( struct V_125 * V_125 )
{
return F_218 ( V_125 , & V_406 ) ;
}
void F_219 ( struct V_125 * V_125 )
{
F_220 ( V_125 , & V_406 ) ;
}
static void F_221 ( struct V_2 * V_3 , int V_407 )
{
struct V_26 * V_27 = F_5 ( V_3 ) ;
F_222 ( V_3 , F_223 ( struct V_26 , V_291 ) ) ;
V_407 -= F_223 ( struct V_26 , V_291 ) + sizeof( V_27 -> V_291 ) ;
memset ( & V_27 -> V_291 + 1 , 0 , V_407 ) ;
}
static int T_8 F_224 ( struct V_125 * V_125 )
{
return F_225 ( & V_125 -> V_237 . F_14 , V_408 ,
V_409 , V_88 , V_125 ) ;
}
static void T_9 F_226 ( struct V_125 * V_125 )
{
F_227 ( V_125 -> V_237 . F_14 ) ;
}
static void T_9 F_228 ( struct V_410 * V_411 )
{
F_229 ( & V_132 , & V_99 , V_45 ) ;
}
int T_10 F_230 ( void )
{
int V_325 ;
V_325 = F_231 ( & V_412 , V_88 ) ;
if ( V_325 )
goto V_139;
V_325 = F_232 ( & V_413 ) ;
if ( V_325 )
goto V_414;
V_325 = F_233 ( & V_415 ) ;
if ( V_325 )
goto V_416;
V_139:
return V_325 ;
V_416:
F_234 ( & V_413 ) ;
V_414:
F_235 ( & V_412 , V_88 ) ;
goto V_139;
}
void F_236 ( void )
{
F_237 ( & V_415 ) ;
F_234 ( & V_413 ) ;
F_235 ( & V_412 , V_88 ) ;
}
