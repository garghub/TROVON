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
if ( F_58 ( V_3 ) && type != V_137 )
F_59 ( V_125 , V_138 ) ;
if ( V_3 -> V_113 == V_111 )
goto V_139;
if ( F_10 ( V_7 ) -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_59 ( V_125 , V_142 ) ;
goto V_139;
}
V_33 = F_14 ( V_3 ) ;
V_128 = V_33 -> V_143 ;
V_130 = V_128 ? F_60 ( V_128 ) -> V_144 : V_33 -> V_130 ;
if ( V_3 -> V_113 != V_145 &&
! F_61 ( V_129 , V_130 , V_33 -> V_146 ) ) {
F_59 ( V_125 , V_147 ) ;
goto V_139;
}
V_31 = F_6 ( V_3 ) ;
if ( type == V_148 ) {
struct V_8 * V_9 = F_62 ( V_3 , V_31 -> V_149 ) ;
if ( V_9 )
V_9 -> V_150 -> V_151 ( V_9 , V_3 , V_7 ) ;
goto V_139;
}
if ( type == V_137 ) {
if ( V_3 -> V_113 == V_145 )
goto V_139;
if ( ! F_63 ( V_3 ) )
goto V_139;
V_33 -> V_116 = F_54 ( V_121 ) ;
if ( ! F_58 ( V_3 ) )
F_41 ( V_3 ) ;
else if ( ! F_64 ( V_152 ,
& V_33 -> V_153 ) )
F_65 ( V_3 ) ;
goto V_139;
}
switch ( V_3 -> V_113 ) {
case V_108 :
case V_154 :
if ( V_128 && ! V_128 -> V_3 )
break;
if ( ! F_58 ( V_3 ) ) {
V_3 -> V_155 = V_41 ;
V_3 -> V_156 ( V_3 ) ;
F_66 ( V_3 ) ;
} else
V_3 -> V_157 = V_41 ;
goto V_139;
}
if ( ! F_58 ( V_3 ) && V_31 -> V_158 ) {
V_3 -> V_155 = V_41 ;
V_3 -> V_156 ( V_3 ) ;
} else
V_3 -> V_157 = V_41 ;
V_139:
F_67 ( V_3 ) ;
F_68 ( V_3 ) ;
}
static int F_69 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_159 * V_160 ,
struct V_127 * V_161 ,
struct V_162 * V_163 ,
enum V_164 V_165 )
{
struct V_166 * V_167 = F_70 ( V_161 ) ;
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_38 * V_39 = & V_160 -> V_168 . V_169 ;
struct V_6 * V_7 ;
int V_41 = - V_170 ;
if ( ! V_9 && ( V_9 = F_71 ( V_3 , V_39 , V_161 ,
V_88 ) ) == NULL )
goto V_171;
V_7 = F_72 ( V_3 , V_9 , V_161 , V_163 , V_165 ) ;
if ( V_7 ) {
F_73 ( V_7 , & V_167 -> V_172 ,
& V_167 -> V_173 ) ;
V_39 -> V_16 = V_167 -> V_173 ;
if ( V_31 -> V_174 && V_167 -> V_175 )
V_39 -> V_48 = V_52 ( F_10 ( V_167 -> V_175 ) ) ;
F_74 () ;
V_37 = V_167 -> V_176 ;
if ( ! V_37 )
V_37 = F_75 ( V_31 -> V_37 ) ;
V_41 = F_76 ( V_3 , V_7 , V_39 , V_37 , V_31 -> V_177 ) ;
F_77 () ;
V_41 = F_78 ( V_41 ) ;
}
V_171:
return V_41 ;
}
static void F_79 ( struct V_127 * V_161 )
{
F_80 ( F_70 ( V_161 ) -> V_176 ) ;
F_81 ( F_70 ( V_161 ) -> V_175 ) ;
}
static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_82 ( V_3 , (union V_178 * ) V_5 , V_45 ) ;
}
static struct V_1 * F_83 ( const struct V_2 * V_3 ,
const struct V_2 * V_179 )
{
return F_1 ( V_3 , & V_179 -> V_62 ) ;
}
static int F_84 ( struct V_2 * V_3 , char T_5 * V_180 ,
int V_181 )
{
struct V_182 V_183 ;
struct V_24 * V_184 = (struct V_24 * ) & V_183 . V_185 ;
if ( V_181 < sizeof( V_183 ) )
return - V_43 ;
if ( F_85 ( & V_183 , V_180 , sizeof( V_183 ) ) )
return - V_186 ;
if ( V_184 -> V_44 != V_45 )
return - V_43 ;
if ( ! V_183 . V_187 ) {
if ( F_86 ( & V_184 -> V_53 ) )
return F_87 ( V_3 , (union V_178 * ) & V_184 -> V_53 . V_17 [ 3 ] ,
V_71 ) ;
return F_87 ( V_3 , (union V_178 * ) & V_184 -> V_53 ,
V_45 ) ;
}
if ( V_183 . V_187 > V_188 )
return - V_43 ;
if ( F_86 ( & V_184 -> V_53 ) )
return F_88 ( V_3 , (union V_178 * ) & V_184 -> V_53 . V_17 [ 3 ] ,
V_71 , V_183 . V_189 , V_183 . V_187 , V_190 ) ;
return F_88 ( V_3 , (union V_178 * ) & V_184 -> V_53 ,
V_45 , V_183 . V_189 , V_183 . V_187 , V_190 ) ;
}
static int F_89 ( struct V_191 * V_192 ,
const struct V_4 * V_16 ,
const struct V_4 * V_18 ,
const struct V_105 * V_124 , int V_193 )
{
struct V_194 * V_195 ;
struct V_196 V_197 ;
struct V_105 * V_198 ;
V_195 = V_192 -> V_199 ;
V_195 -> V_18 = * V_18 ;
V_195 -> V_16 = * V_16 ;
V_195 -> V_200 = F_90 ( V_88 ) ;
V_195 -> V_201 = F_90 ( V_193 ) ;
V_198 = (struct V_105 * ) ( V_195 + 1 ) ;
memcpy ( V_198 , V_124 , sizeof( * V_124 ) ) ;
V_198 -> V_202 = 0 ;
F_91 ( & V_197 , V_195 , sizeof( * V_195 ) + sizeof( * V_124 ) ) ;
F_92 ( V_192 -> V_203 , & V_197 , NULL ,
sizeof( * V_195 ) + sizeof( * V_124 ) ) ;
return F_93 ( V_192 -> V_203 ) ;
}
static int F_94 ( char * V_204 , const struct V_1 * V_205 ,
const struct V_4 * V_16 , struct V_4 * V_18 ,
const struct V_105 * V_124 )
{
struct V_191 * V_192 ;
struct V_206 * V_161 ;
V_192 = F_95 () ;
if ( ! V_192 )
goto V_207;
V_161 = V_192 -> V_203 ;
if ( F_96 ( V_161 ) )
goto V_208;
if ( F_89 ( V_192 , V_16 , V_18 , V_124 , V_124 -> V_209 << 2 ) )
goto V_208;
if ( F_97 ( V_192 , V_205 ) )
goto V_208;
F_92 ( V_161 , NULL , V_204 , 0 ) ;
if ( F_98 ( V_161 ) )
goto V_208;
F_99 () ;
return 0 ;
V_208:
F_99 () ;
V_207:
memset ( V_204 , 0 , 16 ) ;
return 1 ;
}
static int F_100 ( char * V_204 ,
const struct V_1 * V_205 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_18 , * V_16 ;
struct V_191 * V_192 ;
struct V_206 * V_161 ;
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_18 = & V_3 -> V_86 ;
V_16 = & V_3 -> V_62 ;
} else {
const struct V_106 * V_210 = F_10 ( V_7 ) ;
V_18 = & V_210 -> V_18 ;
V_16 = & V_210 -> V_16 ;
}
V_192 = F_95 () ;
if ( ! V_192 )
goto V_207;
V_161 = V_192 -> V_203 ;
if ( F_96 ( V_161 ) )
goto V_208;
if ( F_89 ( V_192 , V_16 , V_18 , V_124 , V_7 -> V_201 ) )
goto V_208;
if ( F_101 ( V_192 , V_7 , V_124 -> V_209 << 2 ) )
goto V_208;
if ( F_97 ( V_192 , V_205 ) )
goto V_208;
F_92 ( V_161 , NULL , V_204 , 0 ) ;
if ( F_98 ( V_161 ) )
goto V_208;
F_99 () ;
return 0 ;
V_208:
F_99 () ;
V_207:
memset ( V_204 , 0 , 16 ) ;
return 1 ;
}
static bool F_102 ( const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
#ifdef F_23
const T_6 * V_211 = NULL ;
struct V_1 * V_212 ;
const struct V_106 * V_210 = F_10 ( V_7 ) ;
const struct V_105 * V_124 = F_11 ( V_7 ) ;
int V_213 ;
T_3 V_214 [ 16 ] ;
V_212 = F_1 ( V_3 , & V_210 -> V_18 ) ;
V_211 = F_103 ( V_124 ) ;
if ( ! V_212 && ! V_211 )
return false ;
if ( V_212 && ! V_211 ) {
F_104 ( F_105 ( V_3 ) , V_215 ) ;
return true ;
}
if ( ! V_212 && V_211 ) {
F_104 ( F_105 ( V_3 ) , V_216 ) ;
return true ;
}
V_213 = F_100 ( V_214 ,
V_212 ,
NULL , V_7 ) ;
if ( V_213 || memcmp ( V_211 , V_214 , 16 ) != 0 ) {
F_104 ( F_105 ( V_3 ) , V_217 ) ;
F_106 ( L_2 ,
V_213 ? L_3 : L_4 ,
& V_210 -> V_18 , F_49 ( V_124 -> V_20 ) ,
& V_210 -> V_16 , F_49 ( V_124 -> V_19 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_107 ( struct V_127 * V_161 ,
const struct V_2 * V_218 ,
struct V_6 * V_7 )
{
struct V_166 * V_167 = F_70 ( V_161 ) ;
const struct V_30 * V_31 = F_6 ( V_218 ) ;
V_167 -> V_173 = F_10 ( V_7 ) -> V_18 ;
V_167 -> V_172 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_218 -> V_59 &&
F_19 ( & V_167 -> V_173 ) & V_57 )
V_167 -> V_219 = F_108 ( V_7 ) ;
if ( ! F_109 ( V_7 ) -> V_220 &&
( F_110 ( V_218 , V_7 , & F_109 ( V_7 ) -> V_221 . V_222 ) ||
V_31 -> V_223 . V_224 . V_225 ||
V_31 -> V_223 . V_224 . V_226 || V_31 -> V_223 . V_224 . V_227 ||
V_31 -> V_223 . V_224 . V_228 || V_31 -> V_174 ) ) {
F_111 ( & V_7 -> V_229 ) ;
V_167 -> V_175 = V_7 ;
}
}
static struct V_8 * F_112 ( const struct V_2 * V_3 ,
struct V_159 * V_160 ,
const struct V_127 * V_161 ,
bool * V_230 )
{
if ( V_230 )
* V_230 = true ;
return F_71 ( V_3 , & V_160 -> V_168 . V_169 , V_161 , V_88 ) ;
}
static void F_113 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_231 , T_2 V_232 , T_2 V_233 , T_2 V_234 ,
int V_235 , struct V_1 * V_205 , int V_236 ,
T_3 V_177 , T_4 V_237 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
struct V_105 * V_238 ;
struct V_6 * V_239 ;
struct V_38 V_39 ;
struct V_125 * V_125 = V_3 ? F_105 ( V_3 ) : F_47 ( F_3 ( V_7 ) -> V_126 ) ;
struct V_2 * V_240 = V_125 -> V_241 . F_14 ;
unsigned int V_242 = sizeof( struct V_105 ) ;
struct V_8 * V_9 ;
T_4 * V_243 ;
if ( V_234 )
V_242 += V_244 ;
#ifdef F_23
if ( V_205 )
V_242 += V_245 ;
#endif
V_239 = F_114 ( V_246 + sizeof( struct V_106 ) + V_242 ,
V_247 ) ;
if ( ! V_239 )
return;
F_115 ( V_239 , V_246 + sizeof( struct V_106 ) + V_242 ) ;
V_238 = (struct V_105 * ) F_116 ( V_239 , V_242 ) ;
F_117 ( V_239 ) ;
memset ( V_238 , 0 , sizeof( * V_238 ) ) ;
V_238 -> V_19 = V_124 -> V_20 ;
V_238 -> V_20 = V_124 -> V_19 ;
V_238 -> V_209 = V_242 / 4 ;
V_238 -> V_129 = F_118 ( V_129 ) ;
V_238 -> V_248 = F_118 ( V_231 ) ;
V_238 -> V_231 = ! V_236 || ! V_124 -> V_231 ;
V_238 -> V_236 = V_236 ;
V_238 -> V_249 = F_119 ( V_232 ) ;
V_243 = ( T_4 * ) ( V_238 + 1 ) ;
if ( V_234 ) {
* V_243 ++ = F_118 ( ( V_250 << 24 ) | ( V_250 << 16 ) |
( V_251 << 8 ) | V_252 ) ;
* V_243 ++ = F_118 ( V_233 ) ;
* V_243 ++ = F_118 ( V_234 ) ;
}
#ifdef F_23
if ( V_205 ) {
* V_243 ++ = F_118 ( ( V_250 << 24 ) | ( V_250 << 16 ) |
( V_253 << 8 ) | V_254 ) ;
F_94 ( ( T_6 * ) V_243 , V_205 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , V_238 ) ;
}
#endif
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_16 = F_10 ( V_7 ) -> V_18 ;
V_39 . V_18 = F_10 ( V_7 ) -> V_16 ;
V_39 . V_48 = V_237 ;
V_239 -> V_255 = V_256 ;
V_239 -> V_257 = 0 ;
F_73 ( V_239 , & V_39 . V_18 , & V_39 . V_16 ) ;
V_39 . V_87 = V_88 ;
if ( F_120 ( & V_39 . V_16 ) && ! V_235 )
V_39 . V_89 = F_108 ( V_7 ) ;
else {
if ( ! V_235 && F_121 ( V_125 , V_7 -> V_14 ) )
V_235 = V_7 -> V_14 ;
V_39 . V_89 = V_235 ;
}
V_39 . V_90 = F_122 ( V_125 , V_7 -> V_258 ) ;
V_39 . V_92 = V_238 -> V_19 ;
V_39 . V_93 = V_238 -> V_20 ;
F_123 ( V_7 , F_29 ( & V_39 ) ) ;
V_9 = F_30 ( V_240 , & V_39 , NULL ) ;
if ( ! F_31 ( V_9 ) ) {
F_124 ( V_239 , V_9 ) ;
F_76 ( V_240 , V_239 , & V_39 , NULL , V_177 ) ;
F_125 ( V_125 , V_259 ) ;
if ( V_236 )
F_125 ( V_125 , V_260 ) ;
return;
}
F_81 ( V_239 ) ;
}
static void F_126 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
T_2 V_129 = 0 , V_248 = 0 ;
struct V_1 * V_205 = NULL ;
#ifdef F_23
const T_6 * V_211 = NULL ;
struct V_106 * V_261 = F_10 ( V_7 ) ;
unsigned char V_214 [ 16 ] ;
int V_213 ;
struct V_2 * V_262 = NULL ;
#endif
int V_235 ;
if ( V_124 -> V_236 )
return;
if ( ! V_3 && ! F_127 ( V_7 ) )
return;
#ifdef F_23
F_74 () ;
V_211 = F_103 ( V_124 ) ;
if ( V_3 && F_128 ( V_3 ) ) {
V_205 = F_1 ( V_3 , & V_261 -> V_18 ) ;
} else if ( V_211 ) {
V_262 = F_129 ( F_47 ( F_3 ( V_7 ) -> V_126 ) ,
& V_132 , NULL , 0 ,
& V_261 -> V_18 ,
V_124 -> V_20 , & V_261 -> V_16 ,
F_49 ( V_124 -> V_20 ) , F_108 ( V_7 ) ) ;
if ( ! V_262 )
goto V_139;
V_205 = F_1 ( V_262 , & V_261 -> V_18 ) ;
if ( ! V_205 )
goto V_139;
V_213 = F_100 ( V_214 , V_205 , NULL , V_7 ) ;
if ( V_213 || memcmp ( V_211 , V_214 , 16 ) != 0 )
goto V_139;
}
#endif
if ( V_124 -> V_231 )
V_129 = F_54 ( V_124 -> V_248 ) ;
else
V_248 = F_54 ( V_124 -> V_129 ) + V_124 -> V_263 + V_124 -> V_264 + V_7 -> V_201 -
( V_124 -> V_209 << 2 ) ;
V_235 = V_3 ? V_3 -> V_59 : 0 ;
F_113 ( V_3 , V_7 , V_129 , V_248 , 0 , 0 , 0 , V_235 , V_205 , 1 , 0 , 0 ) ;
#ifdef F_23
V_139:
F_77 () ;
#endif
}
static void F_130 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_231 , T_2 V_232 , T_2 V_233 , T_2 V_234 , int V_235 ,
struct V_1 * V_205 , T_3 V_177 ,
T_4 V_237 )
{
F_113 ( V_3 , V_7 , V_129 , V_231 , V_232 , V_233 , V_234 , V_235 , V_205 , 0 ,
V_177 , V_237 ) ;
}
static void F_131 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_265 * V_266 = F_53 ( V_3 ) ;
struct V_267 * V_268 = F_132 ( V_3 ) ;
F_130 ( V_3 , V_7 , V_268 -> V_269 , V_268 -> V_270 ,
V_268 -> V_271 >> V_266 -> V_272 ,
V_273 + V_268 -> V_274 ,
V_268 -> V_275 , V_266 -> V_276 , F_133 ( V_268 ) ,
V_266 -> V_277 , F_90 ( V_266 -> V_278 ) ) ;
F_52 ( V_266 ) ;
}
static void F_134 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 )
{
F_130 ( V_3 , V_7 , ( V_3 -> V_113 == V_145 ) ?
F_60 ( V_161 ) -> V_144 + 1 : F_14 ( V_3 ) -> V_146 ,
F_60 ( V_161 ) -> V_279 ,
V_161 -> V_280 >> F_70 ( V_161 ) -> V_281 ,
V_273 , V_161 -> V_63 , V_3 -> V_59 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_135 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_136
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( ! V_124 -> V_263 )
V_3 = F_137 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_138 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_200 == F_119 ( V_282 ) )
return F_139 ( V_3 , V_7 ) ;
if ( ! F_127 ( V_7 ) )
goto V_283;
return F_140 ( & V_284 ,
& V_285 , V_3 , V_7 ) ;
V_283:
F_141 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_142 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 ,
struct V_8 * V_9 ,
struct V_127 * V_286 ,
bool * V_287 )
{
struct V_166 * V_167 ;
struct V_30 * V_288 ;
const struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_289 * V_290 ;
struct V_26 * V_291 ;
struct V_32 * V_292 ;
struct V_2 * V_293 ;
#ifdef F_23
struct V_1 * V_205 ;
#endif
struct V_38 V_39 ;
if ( V_7 -> V_200 == F_119 ( V_282 ) ) {
V_293 = F_143 ( V_3 , V_7 , V_161 , V_9 ,
V_286 , V_287 ) ;
if ( ! V_293 )
return NULL ;
V_290 = (struct V_289 * ) V_293 ;
F_5 ( V_293 ) -> V_294 = & V_290 -> V_295 ;
V_291 = F_5 ( V_293 ) ;
V_288 = F_6 ( V_293 ) ;
V_292 = F_14 ( V_293 ) ;
memcpy ( V_288 , V_31 , sizeof( struct V_30 ) ) ;
V_288 -> V_18 = V_293 -> V_86 ;
F_13 ( V_293 ) -> V_76 = & V_77 ;
V_293 -> V_78 = V_79 ;
#ifdef F_23
V_292 -> V_80 = & V_81 ;
#endif
V_288 -> V_296 = NULL ;
V_288 -> V_297 = NULL ;
V_288 -> V_298 = NULL ;
V_288 -> V_37 = NULL ;
V_288 -> V_299 = F_108 ( V_7 ) ;
V_288 -> V_300 = F_10 ( V_7 ) -> V_140 ;
V_288 -> V_301 = F_144 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_174 )
V_288 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
F_44 ( V_293 , F_13 ( V_293 ) -> V_117 ) ;
return V_293 ;
}
V_167 = F_70 ( V_161 ) ;
if ( F_145 ( V_3 ) )
goto V_302;
if ( ! V_9 ) {
V_9 = F_71 ( V_3 , & V_39 , V_161 , V_88 ) ;
if ( ! V_9 )
goto V_139;
}
V_293 = F_146 ( V_3 , V_161 , V_7 ) ;
if ( ! V_293 )
goto V_303;
V_293 -> V_97 = V_98 ;
F_33 ( V_293 , V_9 , NULL , NULL ) ;
F_2 ( V_293 , V_7 ) ;
V_290 = (struct V_289 * ) V_293 ;
F_5 ( V_293 ) -> V_294 = & V_290 -> V_295 ;
V_292 = F_14 ( V_293 ) ;
V_291 = F_5 ( V_293 ) ;
V_288 = F_6 ( V_293 ) ;
memcpy ( V_288 , V_31 , sizeof( struct V_30 ) ) ;
V_293 -> V_62 = V_167 -> V_173 ;
V_288 -> V_18 = V_167 -> V_172 ;
V_293 -> V_86 = V_167 -> V_172 ;
V_293 -> V_59 = V_167 -> V_219 ;
V_291 -> V_304 = NULL ;
V_288 -> V_296 = NULL ;
V_288 -> V_297 = NULL ;
V_288 -> V_223 . V_305 = V_31 -> V_223 . V_305 ;
V_288 -> V_298 = NULL ;
V_288 -> V_37 = NULL ;
V_288 -> V_299 = F_108 ( V_7 ) ;
V_288 -> V_300 = F_10 ( V_7 ) -> V_140 ;
V_288 -> V_301 = F_144 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_174 )
V_288 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
V_37 = V_167 -> V_176 ;
if ( ! V_37 )
V_37 = F_75 ( V_31 -> V_37 ) ;
if ( V_37 ) {
V_37 = F_147 ( V_293 , V_37 ) ;
F_148 ( V_288 -> V_37 , V_37 ) ;
}
F_13 ( V_293 ) -> V_68 = 0 ;
if ( V_37 )
F_13 ( V_293 ) -> V_68 = V_37 -> V_102 +
V_37 -> V_101 ;
F_149 ( V_293 , V_9 ) ;
F_44 ( V_293 , F_43 ( V_9 ) ) ;
V_292 -> V_306 = F_150 ( V_9 ) ;
if ( F_14 ( V_3 ) -> V_60 . V_307 &&
F_14 ( V_3 ) -> V_60 . V_307 < V_292 -> V_306 )
V_292 -> V_306 = F_14 ( V_3 ) -> V_60 . V_307 ;
F_151 ( V_293 ) ;
V_291 -> V_308 = V_291 -> V_309 = V_96 ;
V_291 -> V_95 = V_96 ;
#ifdef F_23
V_205 = F_1 ( V_3 , & V_293 -> V_62 ) ;
if ( V_205 ) {
F_88 ( V_293 , (union V_178 * ) & V_293 -> V_62 ,
V_45 , V_205 -> V_205 , V_205 -> V_310 ,
F_152 ( V_3 , V_247 ) ) ;
}
#endif
if ( F_153 ( V_3 , V_293 ) < 0 ) {
F_154 ( V_293 ) ;
F_66 ( V_293 ) ;
goto V_139;
}
* V_287 = F_155 ( V_293 , F_156 ( V_286 ) ) ;
if ( * V_287 ) {
F_157 ( V_292 , V_161 ) ;
if ( V_167 -> V_175 ) {
V_288 -> V_298 = F_158 ( V_167 -> V_175 ,
F_152 ( V_3 , V_247 ) ) ;
F_159 ( V_167 -> V_175 ) ;
V_167 -> V_175 = NULL ;
if ( V_288 -> V_298 )
F_160 ( V_288 -> V_298 , V_293 ) ;
}
}
return V_293 ;
V_302:
F_59 ( F_105 ( V_3 ) , V_311 ) ;
V_303:
F_161 ( V_9 ) ;
V_139:
F_141 ( V_3 ) ;
return NULL ;
}
static void F_162 ( struct V_6 * V_7 )
{
memmove ( F_163 ( V_7 ) , & F_109 ( V_7 ) -> V_221 . V_222 ,
sizeof( struct V_118 ) ) ;
}
static int V_83 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_6 * V_312 = NULL ;
if ( V_7 -> V_200 == F_119 ( V_282 ) )
return V_79 ( V_3 , V_7 ) ;
if ( F_164 ( V_3 , V_7 ) )
goto V_313;
if ( V_31 -> V_223 . V_305 )
V_312 = F_158 ( V_7 , F_152 ( V_3 , V_247 ) ) ;
if ( V_3 -> V_113 == V_314 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_165 ( V_3 , V_7 ) ;
F_166 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_150 -> V_202 ( V_9 , V_31 -> V_15 ) == NULL ) {
F_161 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_167 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_201 ) ;
if ( V_312 )
goto V_315;
return 0 ;
}
if ( F_168 ( V_7 ) )
goto V_316;
if ( V_3 -> V_113 == V_145 ) {
struct V_2 * V_317 = F_135 ( V_3 , V_7 ) ;
if ( ! V_317 )
goto V_313;
if ( V_317 != V_3 ) {
F_165 ( V_317 , V_7 ) ;
F_166 ( V_317 , V_7 ) ;
if ( F_169 ( V_3 , V_317 , V_7 ) )
goto V_318;
if ( V_312 )
F_170 ( V_312 ) ;
return 0 ;
}
} else
F_165 ( V_3 , V_7 ) ;
if ( F_171 ( V_3 , V_7 ) )
goto V_318;
if ( V_312 )
goto V_315;
return 0 ;
V_318:
F_126 ( V_3 , V_7 ) ;
V_313:
if ( V_312 )
F_170 ( V_312 ) ;
F_81 ( V_7 ) ;
return 0 ;
V_316:
F_125 ( F_105 ( V_3 ) , V_319 ) ;
F_125 ( F_105 ( V_3 ) , V_320 ) ;
goto V_313;
V_315:
V_33 = F_14 ( V_3 ) ;
if ( F_109 ( V_312 ) -> V_321 == V_33 -> V_279 &&
! ( ( 1 << V_3 -> V_113 ) & ( V_115 | V_114 ) ) ) {
if ( V_31 -> V_223 . V_224 . V_225 || V_31 -> V_223 . V_224 . V_226 )
V_31 -> V_299 = F_108 ( V_312 ) ;
if ( V_31 -> V_223 . V_224 . V_227 || V_31 -> V_223 . V_224 . V_228 )
V_31 -> V_300 = F_10 ( V_312 ) -> V_140 ;
if ( V_31 -> V_223 . V_224 . V_322 || V_31 -> V_223 . V_224 . V_323 )
V_31 -> V_301 = F_144 ( F_10 ( V_312 ) ) ;
if ( V_31 -> V_174 )
V_31 -> V_65 = V_52 ( F_10 ( V_312 ) ) ;
if ( F_110 ( V_3 , V_312 , & F_109 ( V_312 ) -> V_221 . V_222 ) ) {
F_160 ( V_312 , V_3 ) ;
F_162 ( V_312 ) ;
V_312 = F_172 ( & V_31 -> V_298 , V_312 ) ;
} else {
F_170 ( V_312 ) ;
V_312 = F_172 ( & V_31 -> V_298 , NULL ) ;
}
}
F_81 ( V_312 ) ;
return 0 ;
}
static void F_173 ( struct V_6 * V_7 , const struct V_106 * V_122 ,
const struct V_105 * V_124 )
{
memmove ( & F_109 ( V_7 ) -> V_221 . V_222 , F_163 ( V_7 ) ,
sizeof( struct V_118 ) ) ;
F_174 () ;
F_109 ( V_7 ) -> V_129 = F_54 ( V_124 -> V_129 ) ;
F_109 ( V_7 ) -> V_321 = ( F_109 ( V_7 ) -> V_129 + V_124 -> V_263 + V_124 -> V_264 +
V_7 -> V_201 - V_124 -> V_209 * 4 ) ;
F_109 ( V_7 ) -> V_248 = F_54 ( V_124 -> V_248 ) ;
F_109 ( V_7 ) -> V_324 = F_175 ( V_124 ) ;
F_109 ( V_7 ) -> V_220 = 0 ;
F_109 ( V_7 ) -> V_325 = F_176 ( V_122 ) ;
F_109 ( V_7 ) -> V_326 = 0 ;
}
static int F_177 ( struct V_6 * V_7 )
{
const struct V_105 * V_124 ;
const struct V_106 * V_122 ;
bool V_327 ;
struct V_2 * V_3 ;
int V_328 ;
struct V_125 * V_125 = F_47 ( V_7 -> V_126 ) ;
if ( V_7 -> V_329 != V_330 )
goto V_331;
F_178 ( V_125 , V_332 ) ;
if ( ! F_179 ( V_7 , sizeof( struct V_105 ) ) )
goto V_331;
V_124 = ( const struct V_105 * ) V_7 -> V_123 ;
if ( F_180 ( V_124 -> V_209 < sizeof( struct V_105 ) / 4 ) )
goto V_333;
if ( ! F_179 ( V_7 , V_124 -> V_209 * 4 ) )
goto V_331;
if ( F_181 ( V_7 , V_88 , V_334 ) )
goto V_335;
V_124 = ( const struct V_105 * ) V_7 -> V_123 ;
V_122 = F_10 ( V_7 ) ;
V_336:
V_3 = F_182 ( & V_132 , V_7 , F_183 ( V_124 ) ,
V_124 -> V_20 , V_124 -> V_19 , F_184 ( V_7 ) ,
& V_327 ) ;
if ( ! V_3 )
goto V_337;
V_338:
if ( V_3 -> V_113 == V_135 )
goto V_339;
if ( V_3 -> V_113 == V_136 ) {
struct V_127 * V_161 = F_185 ( V_3 ) ;
struct V_2 * V_317 ;
V_3 = V_161 -> V_340 ;
F_173 ( V_7 , V_122 , V_124 ) ;
if ( F_102 ( V_3 , V_7 ) ) {
F_186 ( V_3 , V_7 ) ;
F_187 ( V_161 ) ;
goto V_331;
}
if ( F_180 ( V_3 -> V_113 != V_145 ) ) {
F_188 ( V_3 , V_161 ) ;
goto V_336;
}
F_65 ( V_3 ) ;
V_327 = true ;
V_317 = F_189 ( V_3 , V_7 , V_161 , false ) ;
if ( ! V_317 ) {
F_187 ( V_161 ) ;
goto V_341;
}
if ( V_317 == V_3 ) {
F_187 ( V_161 ) ;
F_162 ( V_7 ) ;
} else if ( F_169 ( V_3 , V_317 , V_7 ) ) {
F_126 ( V_317 , V_7 ) ;
goto V_341;
} else {
F_68 ( V_3 ) ;
return 0 ;
}
}
if ( V_122 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_59 ( V_125 , V_142 ) ;
goto V_341;
}
if ( ! F_190 ( V_3 , V_342 , V_7 ) )
goto V_341;
F_173 ( V_7 , V_122 , V_124 ) ;
if ( F_102 ( V_3 , V_7 ) )
goto V_341;
if ( F_164 ( V_3 , V_7 ) )
goto V_341;
V_124 = ( const struct V_105 * ) V_7 -> V_123 ;
V_122 = F_10 ( V_7 ) ;
V_7 -> V_126 = NULL ;
if ( V_3 -> V_113 == V_145 ) {
V_328 = V_83 ( V_3 , V_7 ) ;
goto V_343;
}
F_191 ( V_3 ) ;
F_192 ( V_3 ) ;
F_193 ( F_14 ( V_3 ) , V_7 ) ;
V_328 = 0 ;
if ( ! F_58 ( V_3 ) ) {
if ( ! F_194 ( V_3 , V_7 ) )
V_328 = V_83 ( V_3 , V_7 ) ;
} else if ( F_195 ( V_3 , V_7 ) ) {
goto V_341;
}
F_67 ( V_3 ) ;
V_343:
if ( V_327 )
F_68 ( V_3 ) ;
return V_328 ? - 1 : 0 ;
V_337:
if ( ! F_190 ( NULL , V_342 , V_7 ) )
goto V_331;
F_173 ( V_7 , V_122 , V_124 ) ;
if ( F_168 ( V_7 ) ) {
V_335:
F_178 ( V_125 , V_319 ) ;
V_333:
F_178 ( V_125 , V_320 ) ;
} else {
F_126 ( NULL , V_7 ) ;
}
V_331:
F_81 ( V_7 ) ;
return 0 ;
V_341:
F_186 ( V_3 , V_7 ) ;
if ( V_327 )
F_68 ( V_3 ) ;
goto V_331;
V_339:
if ( ! F_190 ( NULL , V_342 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_331;
}
F_173 ( V_7 , V_122 , V_124 ) ;
if ( F_168 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_335;
}
switch ( F_196 ( F_53 ( V_3 ) , V_7 , V_124 ) ) {
case V_344 :
{
struct V_2 * V_345 ;
V_345 = F_129 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
V_7 , F_183 ( V_124 ) ,
& F_10 ( V_7 ) -> V_18 , V_124 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_49 ( V_124 -> V_19 ) , F_108 ( V_7 ) ) ;
if ( V_345 ) {
struct V_265 * V_266 = F_53 ( V_3 ) ;
F_197 ( V_266 ) ;
V_3 = V_345 ;
F_162 ( V_7 ) ;
V_327 = false ;
goto V_338;
}
}
case V_346 :
F_131 ( V_3 , V_7 ) ;
break;
case V_347 :
F_162 ( V_7 ) ;
F_126 ( V_3 , V_7 ) ;
F_197 ( F_53 ( V_3 ) ) ;
goto V_331;
case V_348 :
;
}
goto V_331;
}
static void F_198 ( struct V_6 * V_7 )
{
const struct V_106 * V_122 ;
const struct V_105 * V_124 ;
struct V_2 * V_3 ;
if ( V_7 -> V_329 != V_330 )
return;
if ( ! F_179 ( V_7 , F_199 ( V_7 ) + sizeof( struct V_105 ) ) )
return;
V_122 = F_10 ( V_7 ) ;
V_124 = F_11 ( V_7 ) ;
if ( V_124 -> V_209 < sizeof( struct V_105 ) / 4 )
return;
V_3 = F_48 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
& V_122 -> V_18 , V_124 -> V_20 ,
& V_122 -> V_16 , F_49 ( V_124 -> V_19 ) ,
F_184 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_349 = V_350 ;
if ( F_128 ( V_3 ) ) {
struct V_8 * V_9 = F_200 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_201 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_202 ( V_7 , V_9 ) ;
}
}
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_13 ( V_3 ) ;
F_204 ( V_3 ) ;
V_29 -> V_76 = & V_82 ;
#ifdef F_23
F_14 ( V_3 ) -> V_80 = & V_84 ;
#endif
return 0 ;
}
static void F_205 ( struct V_2 * V_3 )
{
F_206 ( V_3 ) ;
F_207 ( V_3 ) ;
}
static void F_208 ( struct V_351 * V_129 ,
const struct V_127 * V_161 , int V_352 )
{
long V_353 = V_161 -> V_354 . V_355 - V_356 ;
const struct V_4 * V_357 = & F_70 ( V_161 ) -> V_172 ;
const struct V_4 * V_19 = & F_70 ( V_161 ) -> V_173 ;
if ( V_353 < 0 )
V_353 = 0 ;
F_209 ( V_129 ,
L_5
L_6 ,
V_352 ,
V_357 -> V_17 [ 0 ] , V_357 -> V_17 [ 1 ] ,
V_357 -> V_17 [ 2 ] , V_357 -> V_17 [ 3 ] ,
F_70 ( V_161 ) -> V_358 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_49 ( F_70 ( V_161 ) -> V_359 ) ,
V_154 ,
0 , 0 ,
1 ,
F_210 ( V_353 ) ,
V_161 -> V_360 ,
F_211 ( F_212 ( V_129 ) ,
F_213 ( V_161 -> V_340 ) ) ,
0 ,
0 ,
0 , V_161 ) ;
}
static void F_214 ( struct V_351 * V_129 , struct V_2 * V_361 , int V_352 )
{
const struct V_4 * V_19 , * V_357 ;
T_7 V_362 , V_363 ;
int V_364 ;
unsigned long V_365 ;
const struct V_26 * V_27 = F_5 ( V_361 ) ;
const struct V_32 * V_33 = F_14 ( V_361 ) ;
const struct V_28 * V_29 = F_13 ( V_361 ) ;
const struct V_366 * V_367 = & V_29 -> V_368 . V_367 ;
int V_369 ;
int V_370 ;
V_19 = & V_361 -> V_62 ;
V_357 = & V_361 -> V_86 ;
V_362 = F_49 ( V_27 -> V_107 ) ;
V_363 = F_49 ( V_27 -> V_94 ) ;
if ( V_29 -> V_371 == V_372 ||
V_29 -> V_371 == V_373 ||
V_29 -> V_371 == V_374 ) {
V_364 = 1 ;
V_365 = V_29 -> V_375 ;
} else if ( V_29 -> V_371 == V_376 ) {
V_364 = 4 ;
V_365 = V_29 -> V_375 ;
} else if ( F_215 ( & V_361 -> V_377 ) ) {
V_364 = 2 ;
V_365 = V_361 -> V_377 . V_355 ;
} else {
V_364 = 0 ;
V_365 = V_356 ;
}
V_370 = F_216 ( V_361 ) ;
if ( V_370 == V_145 )
V_369 = V_361 -> V_378 ;
else
V_369 = F_217 ( int , V_33 -> V_279 - V_33 -> V_379 , 0 ) ;
F_209 ( V_129 ,
L_5
L_7 ,
V_352 ,
V_357 -> V_17 [ 0 ] , V_357 -> V_17 [ 1 ] ,
V_357 -> V_17 [ 2 ] , V_357 -> V_17 [ 3 ] , V_363 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_362 ,
V_370 ,
V_33 -> V_64 - V_33 -> V_130 ,
V_369 ,
V_364 ,
F_218 ( V_365 - V_356 ) ,
V_29 -> V_380 ,
F_211 ( F_212 ( V_129 ) , F_213 ( V_361 ) ) ,
V_29 -> V_381 ,
F_219 ( V_361 ) ,
F_220 ( & V_361 -> V_382 ) , V_361 ,
F_210 ( V_29 -> V_383 ) ,
F_210 ( V_29 -> V_384 . V_385 ) ,
( V_29 -> V_384 . V_386 << 1 ) | V_29 -> V_384 . V_387 ,
V_33 -> V_388 ,
V_370 == V_145 ?
V_367 -> V_389 :
( F_221 ( V_33 ) ? - 1 : V_33 -> V_390 )
) ;
}
static void F_222 ( struct V_351 * V_129 ,
struct V_265 * V_266 , int V_352 )
{
long V_391 = V_266 -> V_392 . V_355 - V_356 ;
const struct V_4 * V_19 , * V_357 ;
T_7 V_362 , V_363 ;
V_19 = & V_266 -> V_393 ;
V_357 = & V_266 -> V_394 ;
V_362 = F_49 ( V_266 -> V_395 ) ;
V_363 = F_49 ( V_266 -> V_396 ) ;
F_209 ( V_129 ,
L_5
L_8 ,
V_352 ,
V_357 -> V_17 [ 0 ] , V_357 -> V_17 [ 1 ] ,
V_357 -> V_17 [ 2 ] , V_357 -> V_17 [ 3 ] , V_363 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_362 ,
V_266 -> V_397 , 0 , 0 ,
3 , F_218 ( V_391 ) , 0 , 0 , 0 , 0 ,
F_220 ( & V_266 -> V_398 ) , V_266 ) ;
}
static int F_223 ( struct V_351 * V_129 , void * V_399 )
{
struct V_400 * V_401 ;
struct V_2 * V_3 = V_399 ;
if ( V_399 == V_402 ) {
F_224 ( V_129 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_139;
}
V_401 = V_129 -> V_403 ;
if ( V_3 -> V_113 == V_135 )
F_222 ( V_129 , V_399 , V_401 -> V_404 ) ;
else if ( V_3 -> V_113 == V_136 )
F_208 ( V_129 , V_399 , V_401 -> V_404 ) ;
else
F_214 ( V_129 , V_399 , V_401 -> V_404 ) ;
V_139:
return 0 ;
}
int T_8 F_225 ( struct V_125 * V_125 )
{
return F_226 ( V_125 , & V_405 ) ;
}
void F_227 ( struct V_125 * V_125 )
{
F_228 ( V_125 , & V_405 ) ;
}
static int T_8 F_229 ( struct V_125 * V_125 )
{
return F_230 ( & V_125 -> V_241 . F_14 , V_406 ,
V_407 , V_88 , V_125 ) ;
}
static void T_9 F_231 ( struct V_125 * V_125 )
{
F_232 ( V_125 -> V_241 . F_14 ) ;
}
static void T_9 F_233 ( struct V_408 * V_409 )
{
F_234 ( & V_132 , & V_99 , V_45 ) ;
}
int T_10 F_235 ( void )
{
int V_328 ;
V_328 = F_236 ( & V_410 , V_88 ) ;
if ( V_328 )
goto V_139;
V_328 = F_237 ( & V_411 ) ;
if ( V_328 )
goto V_412;
V_328 = F_238 ( & V_413 ) ;
if ( V_328 )
goto V_414;
V_139:
return V_328 ;
V_414:
F_239 ( & V_411 ) ;
V_412:
F_240 ( & V_410 , V_88 ) ;
goto V_139;
}
void F_241 ( void )
{
F_242 ( & V_413 ) ;
F_239 ( & V_411 ) ;
F_240 ( & V_410 , V_88 ) ;
}
