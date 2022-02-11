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
const struct V_2 * V_217 ,
struct V_6 * V_7 )
{
struct V_166 * V_167 = F_70 ( V_161 ) ;
const struct V_30 * V_31 = F_6 ( V_217 ) ;
V_167 -> V_173 = F_10 ( V_7 ) -> V_18 ;
V_167 -> V_172 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_217 -> V_59 &&
F_19 ( & V_167 -> V_173 ) & V_57 )
V_167 -> V_218 = F_108 ( V_7 ) ;
if ( ! F_109 ( V_7 ) -> V_219 &&
( F_110 ( V_217 , V_7 , & F_109 ( V_7 ) -> V_220 . V_221 ) ||
V_31 -> V_222 . V_223 . V_224 ||
V_31 -> V_222 . V_223 . V_225 || V_31 -> V_222 . V_223 . V_226 ||
V_31 -> V_222 . V_223 . V_227 || V_31 -> V_174 ) ) {
F_111 ( & V_7 -> V_228 ) ;
V_167 -> V_175 = V_7 ;
}
}
static struct V_8 * F_112 ( const struct V_2 * V_3 ,
struct V_159 * V_160 ,
const struct V_127 * V_161 ,
bool * V_229 )
{
if ( V_229 )
* V_229 = true ;
return F_71 ( V_3 , & V_160 -> V_168 . V_169 , V_161 , V_88 ) ;
}
static void F_113 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_230 , T_2 V_231 , T_2 V_232 , T_2 V_233 ,
int V_234 , struct V_1 * V_205 , int V_235 ,
T_3 V_177 , T_4 V_236 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
struct V_105 * V_237 ;
struct V_6 * V_238 ;
struct V_38 V_39 ;
struct V_125 * V_125 = V_3 ? F_105 ( V_3 ) : F_47 ( F_3 ( V_7 ) -> V_126 ) ;
struct V_2 * V_239 = V_125 -> V_240 . F_14 ;
unsigned int V_241 = sizeof( struct V_105 ) ;
struct V_8 * V_9 ;
T_4 * V_242 ;
if ( V_233 )
V_241 += V_243 ;
#ifdef F_23
if ( V_205 )
V_241 += V_244 ;
#endif
V_238 = F_114 ( V_245 + sizeof( struct V_106 ) + V_241 ,
V_246 ) ;
if ( ! V_238 )
return;
F_115 ( V_238 , V_245 + sizeof( struct V_106 ) + V_241 ) ;
V_237 = (struct V_105 * ) F_116 ( V_238 , V_241 ) ;
F_117 ( V_238 ) ;
memset ( V_237 , 0 , sizeof( * V_237 ) ) ;
V_237 -> V_19 = V_124 -> V_20 ;
V_237 -> V_20 = V_124 -> V_19 ;
V_237 -> V_209 = V_241 / 4 ;
V_237 -> V_129 = F_118 ( V_129 ) ;
V_237 -> V_247 = F_118 ( V_230 ) ;
V_237 -> V_230 = ! V_235 || ! V_124 -> V_230 ;
V_237 -> V_235 = V_235 ;
V_237 -> V_248 = F_119 ( V_231 ) ;
V_242 = ( T_4 * ) ( V_237 + 1 ) ;
if ( V_233 ) {
* V_242 ++ = F_118 ( ( V_249 << 24 ) | ( V_249 << 16 ) |
( V_250 << 8 ) | V_251 ) ;
* V_242 ++ = F_118 ( V_232 ) ;
* V_242 ++ = F_118 ( V_233 ) ;
}
#ifdef F_23
if ( V_205 ) {
* V_242 ++ = F_118 ( ( V_249 << 24 ) | ( V_249 << 16 ) |
( V_252 << 8 ) | V_253 ) ;
F_94 ( ( T_6 * ) V_242 , V_205 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , V_237 ) ;
}
#endif
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_16 = F_10 ( V_7 ) -> V_18 ;
V_39 . V_18 = F_10 ( V_7 ) -> V_16 ;
V_39 . V_48 = V_236 ;
V_238 -> V_254 = V_255 ;
V_238 -> V_256 = 0 ;
F_73 ( V_238 , & V_39 . V_18 , & V_39 . V_16 ) ;
V_39 . V_87 = V_88 ;
if ( F_120 ( & V_39 . V_16 ) && ! V_234 )
V_39 . V_89 = F_108 ( V_7 ) ;
else {
if ( ! V_234 && F_121 ( V_125 , V_7 -> V_14 ) )
V_234 = V_7 -> V_14 ;
V_39 . V_89 = V_234 ;
}
V_39 . V_90 = F_122 ( V_125 , V_7 -> V_257 ) ;
V_39 . V_92 = V_237 -> V_19 ;
V_39 . V_93 = V_237 -> V_20 ;
F_123 ( V_7 , F_29 ( & V_39 ) ) ;
V_9 = F_30 ( V_239 , & V_39 , NULL ) ;
if ( ! F_31 ( V_9 ) ) {
F_124 ( V_238 , V_9 ) ;
F_76 ( V_239 , V_238 , & V_39 , NULL , V_177 ) ;
F_125 ( V_125 , V_258 ) ;
if ( V_235 )
F_125 ( V_125 , V_259 ) ;
return;
}
F_81 ( V_238 ) ;
}
static void F_126 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
T_2 V_129 = 0 , V_247 = 0 ;
struct V_1 * V_205 = NULL ;
#ifdef F_23
const T_6 * V_211 = NULL ;
struct V_106 * V_260 = F_10 ( V_7 ) ;
unsigned char V_214 [ 16 ] ;
int V_213 ;
struct V_2 * V_261 = NULL ;
#endif
int V_234 ;
if ( V_124 -> V_235 )
return;
if ( ! V_3 && ! F_127 ( V_7 ) )
return;
#ifdef F_23
F_74 () ;
V_211 = F_103 ( V_124 ) ;
if ( V_3 && F_128 ( V_3 ) ) {
V_205 = F_1 ( V_3 , & V_260 -> V_18 ) ;
} else if ( V_211 ) {
V_261 = F_129 ( F_47 ( F_3 ( V_7 ) -> V_126 ) ,
& V_132 , NULL , 0 ,
& V_260 -> V_18 ,
V_124 -> V_20 , & V_260 -> V_16 ,
F_49 ( V_124 -> V_20 ) , F_108 ( V_7 ) ) ;
if ( ! V_261 )
goto V_139;
V_205 = F_1 ( V_261 , & V_260 -> V_18 ) ;
if ( ! V_205 )
goto V_139;
V_213 = F_100 ( V_214 , V_205 , NULL , V_7 ) ;
if ( V_213 || memcmp ( V_211 , V_214 , 16 ) != 0 )
goto V_139;
}
#endif
if ( V_124 -> V_230 )
V_129 = F_54 ( V_124 -> V_247 ) ;
else
V_247 = F_54 ( V_124 -> V_129 ) + V_124 -> V_262 + V_124 -> V_263 + V_7 -> V_201 -
( V_124 -> V_209 << 2 ) ;
V_234 = V_3 ? V_3 -> V_59 : 0 ;
F_113 ( V_3 , V_7 , V_129 , V_247 , 0 , 0 , 0 , V_234 , V_205 , 1 , 0 , 0 ) ;
#ifdef F_23
V_139:
F_77 () ;
#endif
}
static void F_130 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_230 , T_2 V_231 , T_2 V_232 , T_2 V_233 , int V_234 ,
struct V_1 * V_205 , T_3 V_177 ,
T_4 V_236 )
{
F_113 ( V_3 , V_7 , V_129 , V_230 , V_231 , V_232 , V_233 , V_234 , V_205 , 0 ,
V_177 , V_236 ) ;
}
static void F_131 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_264 * V_265 = F_53 ( V_3 ) ;
struct V_266 * V_267 = F_132 ( V_3 ) ;
F_130 ( V_3 , V_7 , V_267 -> V_268 , V_267 -> V_269 ,
V_267 -> V_270 >> V_265 -> V_271 ,
V_272 + V_267 -> V_273 ,
V_267 -> V_274 , V_265 -> V_275 , F_133 ( V_267 ) ,
V_265 -> V_276 , F_90 ( V_265 -> V_277 ) ) ;
F_52 ( V_265 ) ;
}
static void F_134 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 )
{
F_130 ( V_3 , V_7 , ( V_3 -> V_113 == V_145 ) ?
F_60 ( V_161 ) -> V_144 + 1 : F_14 ( V_3 ) -> V_146 ,
F_60 ( V_161 ) -> V_278 ,
V_161 -> V_279 >> F_70 ( V_161 ) -> V_280 ,
V_272 , V_161 -> V_63 , V_3 -> V_59 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_135 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_136
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( ! V_124 -> V_262 )
V_3 = F_137 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_138 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_200 == F_119 ( V_281 ) )
return F_139 ( V_3 , V_7 ) ;
if ( ! F_127 ( V_7 ) )
goto V_282;
return F_140 ( & V_283 ,
& V_284 , V_3 , V_7 ) ;
V_282:
F_141 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_142 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 ,
struct V_8 * V_9 ,
struct V_127 * V_285 ,
bool * V_286 )
{
struct V_166 * V_167 ;
struct V_30 * V_287 ;
const struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_288 * V_289 ;
struct V_26 * V_290 ;
struct V_32 * V_291 ;
struct V_2 * V_292 ;
#ifdef F_23
struct V_1 * V_205 ;
#endif
struct V_38 V_39 ;
if ( V_7 -> V_200 == F_119 ( V_281 ) ) {
V_292 = F_143 ( V_3 , V_7 , V_161 , V_9 ,
V_285 , V_286 ) ;
if ( ! V_292 )
return NULL ;
V_289 = (struct V_288 * ) V_292 ;
F_5 ( V_292 ) -> V_293 = & V_289 -> V_294 ;
V_290 = F_5 ( V_292 ) ;
V_287 = F_6 ( V_292 ) ;
V_291 = F_14 ( V_292 ) ;
memcpy ( V_287 , V_31 , sizeof( struct V_30 ) ) ;
V_287 -> V_18 = V_292 -> V_86 ;
F_13 ( V_292 ) -> V_76 = & V_77 ;
V_292 -> V_78 = V_79 ;
#ifdef F_23
V_291 -> V_80 = & V_81 ;
#endif
V_287 -> V_295 = NULL ;
V_287 -> V_296 = NULL ;
V_287 -> V_297 = NULL ;
V_287 -> V_37 = NULL ;
V_287 -> V_298 = F_108 ( V_7 ) ;
V_287 -> V_299 = F_10 ( V_7 ) -> V_140 ;
V_287 -> V_300 = F_144 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_174 )
V_287 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
F_44 ( V_292 , F_13 ( V_292 ) -> V_117 ) ;
return V_292 ;
}
V_167 = F_70 ( V_161 ) ;
if ( F_145 ( V_3 ) )
goto V_301;
if ( ! V_9 ) {
V_9 = F_71 ( V_3 , & V_39 , V_161 , V_88 ) ;
if ( ! V_9 )
goto V_139;
}
V_292 = F_146 ( V_3 , V_161 , V_7 ) ;
if ( ! V_292 )
goto V_302;
V_292 -> V_97 = V_98 ;
F_33 ( V_292 , V_9 , NULL , NULL ) ;
F_2 ( V_292 , V_7 ) ;
V_289 = (struct V_288 * ) V_292 ;
F_5 ( V_292 ) -> V_293 = & V_289 -> V_294 ;
V_291 = F_14 ( V_292 ) ;
V_290 = F_5 ( V_292 ) ;
V_287 = F_6 ( V_292 ) ;
memcpy ( V_287 , V_31 , sizeof( struct V_30 ) ) ;
V_292 -> V_62 = V_167 -> V_173 ;
V_287 -> V_18 = V_167 -> V_172 ;
V_292 -> V_86 = V_167 -> V_172 ;
V_292 -> V_59 = V_167 -> V_218 ;
V_290 -> V_303 = NULL ;
V_287 -> V_295 = NULL ;
V_287 -> V_296 = NULL ;
V_287 -> V_222 . V_304 = V_31 -> V_222 . V_304 ;
V_287 -> V_297 = NULL ;
V_287 -> V_37 = NULL ;
V_287 -> V_298 = F_108 ( V_7 ) ;
V_287 -> V_299 = F_10 ( V_7 ) -> V_140 ;
V_287 -> V_300 = F_144 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_174 )
V_287 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
V_37 = V_167 -> V_176 ;
if ( ! V_37 )
V_37 = F_75 ( V_31 -> V_37 ) ;
if ( V_37 ) {
V_37 = F_147 ( V_292 , V_37 ) ;
F_148 ( V_287 -> V_37 , V_37 ) ;
}
F_13 ( V_292 ) -> V_68 = 0 ;
if ( V_37 )
F_13 ( V_292 ) -> V_68 = V_37 -> V_102 +
V_37 -> V_101 ;
F_149 ( V_292 , V_9 ) ;
F_44 ( V_292 , F_43 ( V_9 ) ) ;
V_291 -> V_305 = F_150 ( V_9 ) ;
if ( F_14 ( V_3 ) -> V_60 . V_306 &&
F_14 ( V_3 ) -> V_60 . V_306 < V_291 -> V_305 )
V_291 -> V_305 = F_14 ( V_3 ) -> V_60 . V_306 ;
F_151 ( V_292 ) ;
V_290 -> V_307 = V_290 -> V_308 = V_96 ;
V_290 -> V_95 = V_96 ;
#ifdef F_23
V_205 = F_1 ( V_3 , & V_292 -> V_62 ) ;
if ( V_205 ) {
F_88 ( V_292 , (union V_178 * ) & V_292 -> V_62 ,
V_45 , V_205 -> V_205 , V_205 -> V_309 ,
F_152 ( V_3 , V_246 ) ) ;
}
#endif
if ( F_153 ( V_3 , V_292 ) < 0 ) {
F_154 ( V_292 ) ;
F_66 ( V_292 ) ;
goto V_139;
}
* V_286 = F_155 ( V_292 , F_156 ( V_285 ) ) ;
if ( * V_286 ) {
F_157 ( V_291 , V_161 ) ;
if ( V_167 -> V_175 ) {
V_287 -> V_297 = F_158 ( V_167 -> V_175 ,
F_152 ( V_3 , V_246 ) ) ;
F_159 ( V_167 -> V_175 ) ;
V_167 -> V_175 = NULL ;
if ( V_287 -> V_297 )
F_160 ( V_287 -> V_297 , V_292 ) ;
}
}
return V_292 ;
V_301:
F_59 ( F_105 ( V_3 ) , V_310 ) ;
V_302:
F_161 ( V_9 ) ;
V_139:
F_141 ( V_3 ) ;
return NULL ;
}
static int V_83 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_6 * V_311 = NULL ;
if ( V_7 -> V_200 == F_119 ( V_281 ) )
return V_79 ( V_3 , V_7 ) ;
if ( F_162 ( V_3 , V_7 ) )
goto V_312;
if ( V_31 -> V_222 . V_304 )
V_311 = F_158 ( V_7 , F_152 ( V_3 , V_246 ) ) ;
if ( V_3 -> V_113 == V_313 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_163 ( V_3 , V_7 ) ;
F_164 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_150 -> V_202 ( V_9 , V_31 -> V_15 ) == NULL ) {
F_161 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_165 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_201 ) ;
if ( V_311 )
goto V_314;
return 0 ;
}
if ( F_166 ( V_7 ) )
goto V_315;
if ( V_3 -> V_113 == V_145 ) {
struct V_2 * V_316 = F_135 ( V_3 , V_7 ) ;
if ( ! V_316 )
goto V_312;
if ( V_316 != V_3 ) {
F_163 ( V_316 , V_7 ) ;
F_164 ( V_316 , V_7 ) ;
if ( F_167 ( V_3 , V_316 , V_7 ) )
goto V_317;
if ( V_311 )
F_168 ( V_311 ) ;
return 0 ;
}
} else
F_163 ( V_3 , V_7 ) ;
if ( F_169 ( V_3 , V_7 ) )
goto V_317;
if ( V_311 )
goto V_314;
return 0 ;
V_317:
F_126 ( V_3 , V_7 ) ;
V_312:
if ( V_311 )
F_168 ( V_311 ) ;
F_81 ( V_7 ) ;
return 0 ;
V_315:
F_125 ( F_105 ( V_3 ) , V_318 ) ;
F_125 ( F_105 ( V_3 ) , V_319 ) ;
goto V_312;
V_314:
V_33 = F_14 ( V_3 ) ;
if ( F_109 ( V_311 ) -> V_320 == V_33 -> V_278 &&
! ( ( 1 << V_3 -> V_113 ) & ( V_115 | V_114 ) ) ) {
if ( V_31 -> V_222 . V_223 . V_224 || V_31 -> V_222 . V_223 . V_225 )
V_31 -> V_298 = F_108 ( V_311 ) ;
if ( V_31 -> V_222 . V_223 . V_226 || V_31 -> V_222 . V_223 . V_227 )
V_31 -> V_299 = F_10 ( V_311 ) -> V_140 ;
if ( V_31 -> V_222 . V_223 . V_321 || V_31 -> V_222 . V_223 . V_322 )
V_31 -> V_300 = F_144 ( F_10 ( V_311 ) ) ;
if ( V_31 -> V_174 )
V_31 -> V_65 = V_52 ( F_10 ( V_311 ) ) ;
if ( F_110 ( V_3 , V_311 , & F_109 ( V_311 ) -> V_220 . V_221 ) ) {
F_160 ( V_311 , V_3 ) ;
V_311 = F_170 ( & V_31 -> V_297 , V_311 ) ;
} else {
F_168 ( V_311 ) ;
V_311 = F_170 ( & V_31 -> V_297 , NULL ) ;
}
}
F_81 ( V_311 ) ;
return 0 ;
}
static void F_171 ( struct V_6 * V_7 , const struct V_106 * V_122 ,
const struct V_105 * V_124 )
{
memmove ( & F_109 ( V_7 ) -> V_220 . V_221 , F_172 ( V_7 ) ,
sizeof( struct V_118 ) ) ;
F_173 () ;
F_109 ( V_7 ) -> V_129 = F_54 ( V_124 -> V_129 ) ;
F_109 ( V_7 ) -> V_320 = ( F_109 ( V_7 ) -> V_129 + V_124 -> V_262 + V_124 -> V_263 +
V_7 -> V_201 - V_124 -> V_209 * 4 ) ;
F_109 ( V_7 ) -> V_247 = F_54 ( V_124 -> V_247 ) ;
F_109 ( V_7 ) -> V_323 = F_174 ( V_124 ) ;
F_109 ( V_7 ) -> V_219 = 0 ;
F_109 ( V_7 ) -> V_324 = F_175 ( V_122 ) ;
F_109 ( V_7 ) -> V_325 = 0 ;
}
static void F_176 ( struct V_6 * V_7 )
{
memmove ( F_172 ( V_7 ) , & F_109 ( V_7 ) -> V_220 . V_221 ,
sizeof( struct V_118 ) ) ;
}
static int F_177 ( struct V_6 * V_7 )
{
const struct V_105 * V_124 ;
const struct V_106 * V_122 ;
bool V_326 ;
struct V_2 * V_3 ;
int V_327 ;
struct V_125 * V_125 = F_47 ( V_7 -> V_126 ) ;
if ( V_7 -> V_328 != V_329 )
goto V_330;
F_178 ( V_125 , V_331 ) ;
if ( ! F_179 ( V_7 , sizeof( struct V_105 ) ) )
goto V_330;
V_124 = ( const struct V_105 * ) V_7 -> V_123 ;
if ( F_180 ( V_124 -> V_209 < sizeof( struct V_105 ) / 4 ) )
goto V_332;
if ( ! F_179 ( V_7 , V_124 -> V_209 * 4 ) )
goto V_330;
if ( F_181 ( V_7 , V_88 , V_333 ) )
goto V_334;
V_124 = ( const struct V_105 * ) V_7 -> V_123 ;
V_122 = F_10 ( V_7 ) ;
V_335:
V_3 = F_182 ( & V_132 , V_7 , F_183 ( V_124 ) ,
V_124 -> V_20 , V_124 -> V_19 , F_184 ( V_7 ) ,
& V_326 ) ;
if ( ! V_3 )
goto V_336;
V_337:
if ( V_3 -> V_113 == V_135 )
goto V_338;
if ( V_3 -> V_113 == V_136 ) {
struct V_127 * V_161 = F_185 ( V_3 ) ;
struct V_2 * V_316 ;
V_3 = V_161 -> V_339 ;
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_102 ( V_3 , V_7 ) ) {
F_186 ( V_161 ) ;
goto V_330;
}
if ( F_180 ( V_3 -> V_113 != V_145 ) ) {
F_187 ( V_3 , V_161 ) ;
goto V_335;
}
F_65 ( V_3 ) ;
V_326 = true ;
V_316 = F_188 ( V_3 , V_7 , V_161 , false ) ;
if ( ! V_316 ) {
F_186 ( V_161 ) ;
goto V_340;
}
if ( V_316 == V_3 ) {
F_186 ( V_161 ) ;
F_176 ( V_7 ) ;
} else if ( F_167 ( V_3 , V_316 , V_7 ) ) {
F_126 ( V_316 , V_7 ) ;
goto V_340;
} else {
F_68 ( V_3 ) ;
return 0 ;
}
}
if ( V_122 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_59 ( V_125 , V_142 ) ;
goto V_340;
}
if ( ! F_189 ( V_3 , V_341 , V_7 ) )
goto V_340;
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_102 ( V_3 , V_7 ) )
goto V_340;
if ( F_162 ( V_3 , V_7 ) )
goto V_340;
V_7 -> V_126 = NULL ;
if ( V_3 -> V_113 == V_145 ) {
V_327 = V_83 ( V_3 , V_7 ) ;
goto V_342;
}
F_190 ( V_3 ) ;
F_191 ( V_3 ) ;
F_192 ( F_14 ( V_3 ) , V_7 ) ;
V_327 = 0 ;
if ( ! F_58 ( V_3 ) ) {
if ( ! F_193 ( V_3 , V_7 ) )
V_327 = V_83 ( V_3 , V_7 ) ;
} else if ( F_180 ( F_194 ( V_3 , V_7 ,
V_3 -> V_343 + V_3 -> V_344 ) ) ) {
F_67 ( V_3 ) ;
F_59 ( V_125 , V_345 ) ;
goto V_340;
}
F_67 ( V_3 ) ;
V_342:
if ( V_326 )
F_68 ( V_3 ) ;
return V_327 ? - 1 : 0 ;
V_336:
if ( ! F_189 ( NULL , V_341 , V_7 ) )
goto V_330;
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_166 ( V_7 ) ) {
V_334:
F_178 ( V_125 , V_318 ) ;
V_332:
F_178 ( V_125 , V_319 ) ;
} else {
F_126 ( NULL , V_7 ) ;
}
V_330:
F_81 ( V_7 ) ;
return 0 ;
V_340:
F_195 ( V_3 , V_7 ) ;
if ( V_326 )
F_68 ( V_3 ) ;
goto V_330;
V_338:
if ( ! F_189 ( NULL , V_341 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_330;
}
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_166 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_334;
}
switch ( F_196 ( F_53 ( V_3 ) , V_7 , V_124 ) ) {
case V_346 :
{
struct V_2 * V_347 ;
V_347 = F_129 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
V_7 , F_183 ( V_124 ) ,
& F_10 ( V_7 ) -> V_18 , V_124 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_49 ( V_124 -> V_19 ) , F_108 ( V_7 ) ) ;
if ( V_347 ) {
struct V_264 * V_265 = F_53 ( V_3 ) ;
F_197 ( V_265 ) ;
V_3 = V_347 ;
F_176 ( V_7 ) ;
V_326 = false ;
goto V_337;
}
}
case V_348 :
F_131 ( V_3 , V_7 ) ;
break;
case V_349 :
F_176 ( V_7 ) ;
F_126 ( V_3 , V_7 ) ;
F_197 ( F_53 ( V_3 ) ) ;
goto V_330;
case V_350 :
;
}
goto V_330;
}
static void F_198 ( struct V_6 * V_7 )
{
const struct V_106 * V_122 ;
const struct V_105 * V_124 ;
struct V_2 * V_3 ;
if ( V_7 -> V_328 != V_329 )
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
V_7 -> V_351 = V_352 ;
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
static void F_208 ( struct V_353 * V_129 ,
const struct V_127 * V_161 , int V_354 )
{
long V_355 = V_161 -> V_356 . V_357 - V_358 ;
const struct V_4 * V_359 = & F_70 ( V_161 ) -> V_172 ;
const struct V_4 * V_19 = & F_70 ( V_161 ) -> V_173 ;
if ( V_355 < 0 )
V_355 = 0 ;
F_209 ( V_129 ,
L_5
L_6 ,
V_354 ,
V_359 -> V_17 [ 0 ] , V_359 -> V_17 [ 1 ] ,
V_359 -> V_17 [ 2 ] , V_359 -> V_17 [ 3 ] ,
F_70 ( V_161 ) -> V_360 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_49 ( F_70 ( V_161 ) -> V_361 ) ,
V_154 ,
0 , 0 ,
1 ,
F_210 ( V_355 ) ,
V_161 -> V_362 ,
F_211 ( F_212 ( V_129 ) ,
F_213 ( V_161 -> V_339 ) ) ,
0 ,
0 ,
0 , V_161 ) ;
}
static void F_214 ( struct V_353 * V_129 , struct V_2 * V_363 , int V_354 )
{
const struct V_4 * V_19 , * V_359 ;
T_7 V_364 , V_365 ;
int V_366 ;
unsigned long V_367 ;
const struct V_26 * V_27 = F_5 ( V_363 ) ;
const struct V_32 * V_33 = F_14 ( V_363 ) ;
const struct V_28 * V_29 = F_13 ( V_363 ) ;
const struct V_368 * V_369 = & V_29 -> V_370 . V_369 ;
int V_371 ;
int V_372 ;
V_19 = & V_363 -> V_62 ;
V_359 = & V_363 -> V_86 ;
V_364 = F_49 ( V_27 -> V_107 ) ;
V_365 = F_49 ( V_27 -> V_94 ) ;
if ( V_29 -> V_373 == V_374 ||
V_29 -> V_373 == V_375 ||
V_29 -> V_373 == V_376 ) {
V_366 = 1 ;
V_367 = V_29 -> V_377 ;
} else if ( V_29 -> V_373 == V_378 ) {
V_366 = 4 ;
V_367 = V_29 -> V_377 ;
} else if ( F_215 ( & V_363 -> V_379 ) ) {
V_366 = 2 ;
V_367 = V_363 -> V_379 . V_357 ;
} else {
V_366 = 0 ;
V_367 = V_358 ;
}
V_372 = F_216 ( V_363 ) ;
if ( V_372 == V_145 )
V_371 = V_363 -> V_380 ;
else
V_371 = F_217 ( int , V_33 -> V_278 - V_33 -> V_381 , 0 ) ;
F_209 ( V_129 ,
L_5
L_7 ,
V_354 ,
V_359 -> V_17 [ 0 ] , V_359 -> V_17 [ 1 ] ,
V_359 -> V_17 [ 2 ] , V_359 -> V_17 [ 3 ] , V_365 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_364 ,
V_372 ,
V_33 -> V_64 - V_33 -> V_130 ,
V_371 ,
V_366 ,
F_218 ( V_367 - V_358 ) ,
V_29 -> V_382 ,
F_211 ( F_212 ( V_129 ) , F_213 ( V_363 ) ) ,
V_29 -> V_383 ,
F_219 ( V_363 ) ,
F_220 ( & V_363 -> V_384 ) , V_363 ,
F_210 ( V_29 -> V_385 ) ,
F_210 ( V_29 -> V_386 . V_387 ) ,
( V_29 -> V_386 . V_388 << 1 ) | V_29 -> V_386 . V_389 ,
V_33 -> V_390 ,
V_372 == V_145 ?
V_369 -> V_391 :
( F_221 ( V_33 ) ? - 1 : V_33 -> V_392 )
) ;
}
static void F_222 ( struct V_353 * V_129 ,
struct V_264 * V_265 , int V_354 )
{
long V_393 = V_265 -> V_394 . V_357 - V_358 ;
const struct V_4 * V_19 , * V_359 ;
T_7 V_364 , V_365 ;
V_19 = & V_265 -> V_395 ;
V_359 = & V_265 -> V_396 ;
V_364 = F_49 ( V_265 -> V_397 ) ;
V_365 = F_49 ( V_265 -> V_398 ) ;
F_209 ( V_129 ,
L_5
L_8 ,
V_354 ,
V_359 -> V_17 [ 0 ] , V_359 -> V_17 [ 1 ] ,
V_359 -> V_17 [ 2 ] , V_359 -> V_17 [ 3 ] , V_365 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_364 ,
V_265 -> V_399 , 0 , 0 ,
3 , F_218 ( V_393 ) , 0 , 0 , 0 , 0 ,
F_220 ( & V_265 -> V_400 ) , V_265 ) ;
}
static int F_223 ( struct V_353 * V_129 , void * V_401 )
{
struct V_402 * V_403 ;
struct V_2 * V_3 = V_401 ;
if ( V_401 == V_404 ) {
F_224 ( V_129 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_139;
}
V_403 = V_129 -> V_405 ;
if ( V_3 -> V_113 == V_135 )
F_222 ( V_129 , V_401 , V_403 -> V_406 ) ;
else if ( V_3 -> V_113 == V_136 )
F_208 ( V_129 , V_401 , V_403 -> V_406 ) ;
else
F_214 ( V_129 , V_401 , V_403 -> V_406 ) ;
V_139:
return 0 ;
}
int T_8 F_225 ( struct V_125 * V_125 )
{
return F_226 ( V_125 , & V_407 ) ;
}
void F_227 ( struct V_125 * V_125 )
{
F_228 ( V_125 , & V_407 ) ;
}
static void F_229 ( struct V_2 * V_3 , int V_408 )
{
struct V_26 * V_27 = F_5 ( V_3 ) ;
F_230 ( V_3 , F_231 ( struct V_26 , V_293 ) ) ;
V_408 -= F_231 ( struct V_26 , V_293 ) + sizeof( V_27 -> V_293 ) ;
memset ( & V_27 -> V_293 + 1 , 0 , V_408 ) ;
}
static int T_8 F_232 ( struct V_125 * V_125 )
{
return F_233 ( & V_125 -> V_240 . F_14 , V_409 ,
V_410 , V_88 , V_125 ) ;
}
static void T_9 F_234 ( struct V_125 * V_125 )
{
F_235 ( V_125 -> V_240 . F_14 ) ;
}
static void T_9 F_236 ( struct V_411 * V_412 )
{
F_237 ( & V_132 , & V_99 , V_45 ) ;
}
int T_10 F_238 ( void )
{
int V_327 ;
V_327 = F_239 ( & V_413 , V_88 ) ;
if ( V_327 )
goto V_139;
V_327 = F_240 ( & V_414 ) ;
if ( V_327 )
goto V_415;
V_327 = F_241 ( & V_416 ) ;
if ( V_327 )
goto V_417;
V_139:
return V_327 ;
V_417:
F_242 ( & V_414 ) ;
V_415:
F_243 ( & V_413 , V_88 ) ;
goto V_139;
}
void F_244 ( void )
{
F_245 ( & V_416 ) ;
F_242 ( & V_414 ) ;
F_243 ( & V_413 , V_88 ) ;
}
