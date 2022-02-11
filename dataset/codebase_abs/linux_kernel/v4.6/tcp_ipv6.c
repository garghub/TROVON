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
F_90 ( V_190 -> V_199 , & V_195 , NULL , sizeof( * V_193 ) ) ;
return F_91 ( V_190 -> V_199 ) ;
}
static int F_92 ( char * V_200 , struct V_1 * V_201 ,
const struct V_4 * V_16 , struct V_4 * V_18 ,
const struct V_105 * V_124 )
{
struct V_189 * V_190 ;
struct V_202 * V_161 ;
V_190 = F_93 () ;
if ( ! V_190 )
goto V_203;
V_161 = V_190 -> V_199 ;
if ( F_94 ( V_161 ) )
goto V_204;
if ( F_87 ( V_190 , V_16 , V_18 , V_124 -> V_205 << 2 ) )
goto V_204;
if ( F_95 ( V_190 , V_124 ) )
goto V_204;
if ( F_96 ( V_190 , V_201 ) )
goto V_204;
F_90 ( V_161 , NULL , V_200 , 0 ) ;
if ( F_97 ( V_161 ) )
goto V_204;
F_98 () ;
return 0 ;
V_204:
F_98 () ;
V_203:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static int F_99 ( char * V_200 ,
const struct V_1 * V_201 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_18 , * V_16 ;
struct V_189 * V_190 ;
struct V_202 * V_161 ;
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_18 = & V_3 -> V_86 ;
V_16 = & V_3 -> V_62 ;
} else {
const struct V_106 * V_206 = F_10 ( V_7 ) ;
V_18 = & V_206 -> V_18 ;
V_16 = & V_206 -> V_16 ;
}
V_190 = F_93 () ;
if ( ! V_190 )
goto V_203;
V_161 = V_190 -> V_199 ;
if ( F_94 ( V_161 ) )
goto V_204;
if ( F_87 ( V_190 , V_16 , V_18 , V_7 -> V_198 ) )
goto V_204;
if ( F_95 ( V_190 , V_124 ) )
goto V_204;
if ( F_100 ( V_190 , V_7 , V_124 -> V_205 << 2 ) )
goto V_204;
if ( F_96 ( V_190 , V_201 ) )
goto V_204;
F_90 ( V_161 , NULL , V_200 , 0 ) ;
if ( F_97 ( V_161 ) )
goto V_204;
F_98 () ;
return 0 ;
V_204:
F_98 () ;
V_203:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static bool F_101 ( const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
#ifdef F_23
const T_6 * V_207 = NULL ;
struct V_1 * V_208 ;
const struct V_106 * V_206 = F_10 ( V_7 ) ;
const struct V_105 * V_124 = F_11 ( V_7 ) ;
int V_209 ;
T_3 V_210 [ 16 ] ;
V_208 = F_1 ( V_3 , & V_206 -> V_18 ) ;
V_207 = F_102 ( V_124 ) ;
if ( ! V_208 && ! V_207 )
return false ;
if ( V_208 && ! V_207 ) {
F_58 ( F_103 ( V_3 ) , V_211 ) ;
return true ;
}
if ( ! V_208 && V_207 ) {
F_58 ( F_103 ( V_3 ) , V_212 ) ;
return true ;
}
V_209 = F_99 ( V_210 ,
V_208 ,
NULL , V_7 ) ;
if ( V_209 || memcmp ( V_207 , V_210 , 16 ) != 0 ) {
F_104 ( L_2 ,
V_209 ? L_3 : L_4 ,
& V_206 -> V_18 , F_49 ( V_124 -> V_20 ) ,
& V_206 -> V_16 , F_49 ( V_124 -> V_19 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_105 ( struct V_127 * V_161 ,
const struct V_2 * V_213 ,
struct V_6 * V_7 )
{
struct V_165 * V_166 = F_69 ( V_161 ) ;
const struct V_30 * V_31 = F_6 ( V_213 ) ;
V_166 -> V_172 = F_10 ( V_7 ) -> V_18 ;
V_166 -> V_171 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_213 -> V_59 &&
F_19 ( & V_166 -> V_172 ) & V_57 )
V_166 -> V_214 = F_106 ( V_7 ) ;
if ( ! F_107 ( V_7 ) -> V_215 &&
( F_108 ( V_213 , V_7 , & F_107 ( V_7 ) -> V_216 . V_217 ) ||
V_31 -> V_218 . V_219 . V_220 ||
V_31 -> V_218 . V_219 . V_221 || V_31 -> V_218 . V_219 . V_222 ||
V_31 -> V_218 . V_219 . V_223 || V_31 -> V_173 ) ) {
F_109 ( & V_7 -> V_224 ) ;
V_166 -> V_174 = V_7 ;
}
}
static struct V_8 * F_110 ( const struct V_2 * V_3 ,
struct V_159 * V_160 ,
const struct V_127 * V_161 ,
bool * V_225 )
{
if ( V_225 )
* V_225 = true ;
return F_70 ( V_3 , & V_160 -> V_167 . V_168 , V_161 , V_88 ) ;
}
static void F_111 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_226 , T_2 V_227 , T_2 V_228 , T_2 V_229 ,
int V_230 , struct V_1 * V_201 , int V_231 ,
T_3 V_175 , T_2 V_232 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
struct V_105 * V_233 ;
struct V_6 * V_234 ;
struct V_38 V_39 ;
struct V_125 * V_125 = V_3 ? F_103 ( V_3 ) : F_47 ( F_3 ( V_7 ) -> V_126 ) ;
struct V_2 * V_235 = V_125 -> V_236 . F_14 ;
unsigned int V_237 = sizeof( struct V_105 ) ;
struct V_8 * V_9 ;
T_4 * V_238 ;
if ( V_229 )
V_237 += V_239 ;
#ifdef F_23
if ( V_201 )
V_237 += V_240 ;
#endif
V_234 = F_112 ( V_241 + sizeof( struct V_106 ) + V_237 ,
V_242 ) ;
if ( ! V_234 )
return;
F_113 ( V_234 , V_241 + sizeof( struct V_106 ) + V_237 ) ;
V_233 = (struct V_105 * ) F_114 ( V_234 , V_237 ) ;
F_115 ( V_234 ) ;
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
V_233 -> V_19 = V_124 -> V_20 ;
V_233 -> V_20 = V_124 -> V_19 ;
V_233 -> V_205 = V_237 / 4 ;
V_233 -> V_129 = F_116 ( V_129 ) ;
V_233 -> V_243 = F_116 ( V_226 ) ;
V_233 -> V_226 = ! V_231 || ! V_124 -> V_226 ;
V_233 -> V_231 = V_231 ;
V_233 -> V_244 = F_117 ( V_227 ) ;
V_238 = ( T_4 * ) ( V_233 + 1 ) ;
if ( V_229 ) {
* V_238 ++ = F_116 ( ( V_245 << 24 ) | ( V_245 << 16 ) |
( V_246 << 8 ) | V_247 ) ;
* V_238 ++ = F_116 ( V_228 ) ;
* V_238 ++ = F_116 ( V_229 ) ;
}
#ifdef F_23
if ( V_201 ) {
* V_238 ++ = F_116 ( ( V_245 << 24 ) | ( V_245 << 16 ) |
( V_248 << 8 ) | V_249 ) ;
F_92 ( ( T_6 * ) V_238 , V_201 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , V_233 ) ;
}
#endif
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_16 = F_10 ( V_7 ) -> V_18 ;
V_39 . V_18 = F_10 ( V_7 ) -> V_16 ;
V_39 . V_48 = V_232 ;
V_234 -> V_250 = V_251 ;
V_234 -> V_252 = 0 ;
F_72 ( V_234 , & V_39 . V_18 , & V_39 . V_16 ) ;
V_39 . V_87 = V_88 ;
if ( F_118 ( & V_39 . V_16 ) && ! V_230 )
V_39 . V_89 = F_106 ( V_7 ) ;
else {
if ( ! V_230 && F_119 ( V_125 , V_7 -> V_14 ) )
V_230 = V_7 -> V_14 ;
V_39 . V_89 = V_230 ;
}
V_39 . V_90 = F_120 ( V_125 , V_7 -> V_253 ) ;
V_39 . V_92 = V_233 -> V_19 ;
V_39 . V_93 = V_233 -> V_20 ;
F_121 ( V_7 , F_29 ( & V_39 ) ) ;
V_9 = F_30 ( V_235 , & V_39 , NULL ) ;
if ( ! F_31 ( V_9 ) ) {
F_122 ( V_234 , V_9 ) ;
F_74 ( V_235 , V_234 , & V_39 , NULL , V_175 ) ;
F_123 ( V_125 , V_254 ) ;
if ( V_231 )
F_123 ( V_125 , V_255 ) ;
return;
}
F_79 ( V_234 ) ;
}
static void F_124 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
T_2 V_129 = 0 , V_243 = 0 ;
struct V_1 * V_201 = NULL ;
#ifdef F_23
const T_6 * V_207 = NULL ;
struct V_106 * V_256 = F_10 ( V_7 ) ;
unsigned char V_210 [ 16 ] ;
int V_209 ;
struct V_2 * V_257 = NULL ;
#endif
int V_230 ;
if ( V_124 -> V_231 )
return;
if ( ! V_3 && ! F_125 ( V_7 ) )
return;
#ifdef F_23
V_207 = F_102 ( V_124 ) ;
if ( V_3 && F_126 ( V_3 ) ) {
V_201 = F_1 ( V_3 , & V_256 -> V_18 ) ;
} else if ( V_207 ) {
V_257 = F_127 ( F_47 ( F_3 ( V_7 ) -> V_126 ) ,
& V_132 , NULL , 0 ,
& V_256 -> V_18 ,
V_124 -> V_20 , & V_256 -> V_16 ,
F_49 ( V_124 -> V_20 ) , F_106 ( V_7 ) ) ;
if ( ! V_257 )
return;
F_73 () ;
V_201 = F_1 ( V_257 , & V_256 -> V_18 ) ;
if ( ! V_201 )
goto V_258;
V_209 = F_99 ( V_210 , V_201 , NULL , V_7 ) ;
if ( V_209 || memcmp ( V_207 , V_210 , 16 ) != 0 )
goto V_258;
}
#endif
if ( V_124 -> V_226 )
V_129 = F_54 ( V_124 -> V_243 ) ;
else
V_243 = F_54 ( V_124 -> V_129 ) + V_124 -> V_259 + V_124 -> V_260 + V_7 -> V_198 -
( V_124 -> V_205 << 2 ) ;
V_230 = V_3 ? V_3 -> V_59 : 0 ;
F_111 ( V_3 , V_7 , V_129 , V_243 , 0 , 0 , 0 , V_230 , V_201 , 1 , 0 , 0 ) ;
#ifdef F_23
V_258:
if ( V_257 ) {
F_76 () ;
F_67 ( V_257 ) ;
}
#endif
}
static void F_128 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_226 , T_2 V_227 , T_2 V_228 , T_2 V_229 , int V_230 ,
struct V_1 * V_201 , T_3 V_175 ,
T_2 V_232 )
{
F_111 ( V_3 , V_7 , V_129 , V_226 , V_227 , V_228 , V_229 , V_230 , V_201 , 0 ,
V_175 , V_232 ) ;
}
static void F_129 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_261 * V_262 = F_53 ( V_3 ) ;
struct V_263 * V_264 = F_130 ( V_3 ) ;
F_128 ( V_3 , V_7 , V_264 -> V_265 , V_264 -> V_266 ,
V_264 -> V_267 >> V_262 -> V_268 ,
V_269 + V_264 -> V_270 ,
V_264 -> V_271 , V_262 -> V_272 , F_131 ( V_264 ) ,
V_262 -> V_273 , F_88 ( V_262 -> V_274 ) ) ;
F_52 ( V_262 ) ;
}
static void F_132 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 )
{
F_128 ( V_3 , V_7 , ( V_3 -> V_113 == V_145 ) ?
F_59 ( V_161 ) -> V_144 + 1 : F_14 ( V_3 ) -> V_146 ,
F_59 ( V_161 ) -> V_275 , V_161 -> V_276 ,
V_269 , V_161 -> V_63 , V_3 -> V_59 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_133 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_134
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( ! V_124 -> V_259 )
V_3 = F_135 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_136 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_197 == F_117 ( V_277 ) )
return F_137 ( V_3 , V_7 ) ;
if ( ! F_125 ( V_7 ) )
goto V_278;
return F_138 ( & V_279 ,
& V_280 , V_3 , V_7 ) ;
V_278:
F_58 ( F_103 ( V_3 ) , V_281 ) ;
return 0 ;
}
static struct V_2 * F_139 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 ,
struct V_8 * V_9 ,
struct V_127 * V_282 ,
bool * V_283 )
{
struct V_165 * V_166 ;
struct V_30 * V_284 ;
const struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_285 * V_286 ;
struct V_26 * V_287 ;
struct V_32 * V_288 ;
struct V_2 * V_289 ;
#ifdef F_23
struct V_1 * V_201 ;
#endif
struct V_38 V_39 ;
if ( V_7 -> V_197 == F_117 ( V_277 ) ) {
V_289 = F_140 ( V_3 , V_7 , V_161 , V_9 ,
V_282 , V_283 ) ;
if ( ! V_289 )
return NULL ;
V_286 = (struct V_285 * ) V_289 ;
F_5 ( V_289 ) -> V_290 = & V_286 -> V_291 ;
V_287 = F_5 ( V_289 ) ;
V_284 = F_6 ( V_289 ) ;
V_288 = F_14 ( V_289 ) ;
memcpy ( V_284 , V_31 , sizeof( struct V_30 ) ) ;
V_284 -> V_18 = V_289 -> V_86 ;
F_13 ( V_289 ) -> V_76 = & V_77 ;
V_289 -> V_78 = V_79 ;
#ifdef F_23
V_288 -> V_80 = & V_81 ;
#endif
V_284 -> V_292 = NULL ;
V_284 -> V_293 = NULL ;
V_284 -> V_294 = NULL ;
V_284 -> V_37 = NULL ;
V_284 -> V_295 = F_106 ( V_7 ) ;
V_284 -> V_296 = F_10 ( V_7 ) -> V_140 ;
V_284 -> V_297 = F_141 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_173 )
V_284 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
F_44 ( V_289 , F_13 ( V_289 ) -> V_117 ) ;
return V_289 ;
}
V_166 = F_69 ( V_161 ) ;
if ( F_142 ( V_3 ) )
goto V_298;
if ( ! V_9 ) {
V_9 = F_70 ( V_3 , & V_39 , V_161 , V_88 ) ;
if ( ! V_9 )
goto V_139;
}
V_289 = F_143 ( V_3 , V_161 , V_7 ) ;
if ( ! V_289 )
goto V_299;
V_289 -> V_97 = V_98 ;
F_33 ( V_289 , V_9 , NULL , NULL ) ;
F_2 ( V_289 , V_7 ) ;
V_286 = (struct V_285 * ) V_289 ;
F_5 ( V_289 ) -> V_290 = & V_286 -> V_291 ;
V_288 = F_14 ( V_289 ) ;
V_287 = F_5 ( V_289 ) ;
V_284 = F_6 ( V_289 ) ;
memcpy ( V_284 , V_31 , sizeof( struct V_30 ) ) ;
V_289 -> V_62 = V_166 -> V_172 ;
V_284 -> V_18 = V_166 -> V_171 ;
V_289 -> V_86 = V_166 -> V_171 ;
V_289 -> V_59 = V_166 -> V_214 ;
V_287 -> V_300 = NULL ;
V_284 -> V_292 = NULL ;
V_284 -> V_293 = NULL ;
V_284 -> V_218 . V_301 = V_31 -> V_218 . V_301 ;
V_284 -> V_294 = NULL ;
V_284 -> V_37 = NULL ;
V_284 -> V_295 = F_106 ( V_7 ) ;
V_284 -> V_296 = F_10 ( V_7 ) -> V_140 ;
V_284 -> V_297 = F_141 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_173 )
V_284 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
V_37 = F_75 ( V_31 -> V_37 ) ;
if ( V_37 ) {
V_37 = F_144 ( V_289 , V_37 ) ;
F_145 ( V_284 -> V_37 , V_37 ) ;
}
F_13 ( V_289 ) -> V_68 = 0 ;
if ( V_37 )
F_13 ( V_289 ) -> V_68 = V_37 -> V_102 +
V_37 -> V_101 ;
F_146 ( V_289 , V_9 ) ;
F_44 ( V_289 , F_43 ( V_9 ) ) ;
V_288 -> V_302 = F_147 ( V_9 ) ;
if ( F_14 ( V_3 ) -> V_60 . V_303 &&
F_14 ( V_3 ) -> V_60 . V_303 < V_288 -> V_302 )
V_288 -> V_302 = F_14 ( V_3 ) -> V_60 . V_303 ;
F_148 ( V_289 ) ;
V_287 -> V_304 = V_287 -> V_305 = V_96 ;
V_287 -> V_95 = V_96 ;
#ifdef F_23
V_201 = F_1 ( V_3 , & V_289 -> V_62 ) ;
if ( V_201 ) {
F_86 ( V_289 , (union V_176 * ) & V_289 -> V_62 ,
V_45 , V_201 -> V_201 , V_201 -> V_306 ,
F_149 ( V_3 , V_242 ) ) ;
}
#endif
if ( F_150 ( V_3 , V_289 ) < 0 ) {
F_151 ( V_289 ) ;
F_65 ( V_289 ) ;
goto V_139;
}
* V_283 = F_152 ( V_289 , F_153 ( V_282 ) ) ;
if ( * V_283 ) {
F_154 ( V_288 , V_161 ) ;
if ( V_166 -> V_174 ) {
V_284 -> V_294 = F_155 ( V_166 -> V_174 ,
F_149 ( V_3 , V_242 ) ) ;
F_156 ( V_166 -> V_174 ) ;
V_166 -> V_174 = NULL ;
if ( V_284 -> V_294 )
F_157 ( V_284 -> V_294 , V_289 ) ;
}
}
return V_289 ;
V_298:
F_58 ( F_103 ( V_3 ) , V_307 ) ;
V_299:
F_158 ( V_9 ) ;
V_139:
F_58 ( F_103 ( V_3 ) , V_281 ) ;
return NULL ;
}
static int V_83 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_6 * V_308 = NULL ;
if ( V_7 -> V_197 == F_117 ( V_277 ) )
return V_79 ( V_3 , V_7 ) ;
if ( F_159 ( V_3 , V_7 ) )
goto V_309;
if ( V_31 -> V_218 . V_301 )
V_308 = F_155 ( V_7 , F_149 ( V_3 , V_242 ) ) ;
if ( V_3 -> V_113 == V_310 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_160 ( V_3 , V_7 ) ;
F_161 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_150 -> V_311 ( V_9 , V_31 -> V_15 ) == NULL ) {
F_158 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_162 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_198 ) ;
if ( V_308 )
goto V_312;
return 0 ;
}
if ( F_163 ( V_7 ) )
goto V_313;
if ( V_3 -> V_113 == V_145 ) {
struct V_2 * V_314 = F_133 ( V_3 , V_7 ) ;
if ( ! V_314 )
goto V_309;
if ( V_314 != V_3 ) {
F_160 ( V_314 , V_7 ) ;
F_161 ( V_314 , V_7 ) ;
if ( F_164 ( V_3 , V_314 , V_7 ) )
goto V_315;
if ( V_308 )
F_165 ( V_308 ) ;
return 0 ;
}
} else
F_160 ( V_3 , V_7 ) ;
if ( F_166 ( V_3 , V_7 ) )
goto V_315;
if ( V_308 )
goto V_312;
return 0 ;
V_315:
F_124 ( V_3 , V_7 ) ;
V_309:
if ( V_308 )
F_165 ( V_308 ) ;
F_79 ( V_7 ) ;
return 0 ;
V_313:
F_123 ( F_103 ( V_3 ) , V_316 ) ;
F_123 ( F_103 ( V_3 ) , V_317 ) ;
goto V_309;
V_312:
V_33 = F_14 ( V_3 ) ;
if ( F_107 ( V_308 ) -> V_318 == V_33 -> V_275 &&
! ( ( 1 << V_3 -> V_113 ) & ( V_115 | V_114 ) ) ) {
if ( V_31 -> V_218 . V_219 . V_220 || V_31 -> V_218 . V_219 . V_221 )
V_31 -> V_295 = F_106 ( V_308 ) ;
if ( V_31 -> V_218 . V_219 . V_222 || V_31 -> V_218 . V_219 . V_223 )
V_31 -> V_296 = F_10 ( V_308 ) -> V_140 ;
if ( V_31 -> V_218 . V_219 . V_319 || V_31 -> V_218 . V_219 . V_320 )
V_31 -> V_297 = F_141 ( F_10 ( V_308 ) ) ;
if ( V_31 -> V_173 )
V_31 -> V_65 = V_52 ( F_10 ( V_308 ) ) ;
if ( F_108 ( V_3 , V_308 , & F_107 ( V_308 ) -> V_216 . V_217 ) ) {
F_157 ( V_308 , V_3 ) ;
V_308 = F_167 ( & V_31 -> V_294 , V_308 ) ;
} else {
F_165 ( V_308 ) ;
V_308 = F_167 ( & V_31 -> V_294 , NULL ) ;
}
}
F_79 ( V_308 ) ;
return 0 ;
}
static void F_168 ( struct V_6 * V_7 , const struct V_106 * V_122 ,
const struct V_105 * V_124 )
{
memmove ( & F_107 ( V_7 ) -> V_216 . V_217 , F_169 ( V_7 ) ,
sizeof( struct V_118 ) ) ;
F_170 () ;
F_107 ( V_7 ) -> V_129 = F_54 ( V_124 -> V_129 ) ;
F_107 ( V_7 ) -> V_318 = ( F_107 ( V_7 ) -> V_129 + V_124 -> V_259 + V_124 -> V_260 +
V_7 -> V_198 - V_124 -> V_205 * 4 ) ;
F_107 ( V_7 ) -> V_243 = F_54 ( V_124 -> V_243 ) ;
F_107 ( V_7 ) -> V_321 = F_171 ( V_124 ) ;
F_107 ( V_7 ) -> V_215 = 0 ;
F_107 ( V_7 ) -> V_322 = F_172 ( V_122 ) ;
F_107 ( V_7 ) -> V_323 = 0 ;
}
static void F_173 ( struct V_6 * V_7 )
{
memmove ( F_169 ( V_7 ) , & F_107 ( V_7 ) -> V_216 . V_217 ,
sizeof( struct V_118 ) ) ;
}
static int F_174 ( struct V_6 * V_7 )
{
const struct V_105 * V_124 ;
const struct V_106 * V_122 ;
struct V_2 * V_3 ;
int V_324 ;
struct V_125 * V_125 = F_47 ( V_7 -> V_126 ) ;
if ( V_7 -> V_325 != V_326 )
goto V_327;
F_123 ( V_125 , V_328 ) ;
if ( ! F_175 ( V_7 , sizeof( struct V_105 ) ) )
goto V_327;
V_124 = F_11 ( V_7 ) ;
if ( V_124 -> V_205 < sizeof( struct V_105 ) / 4 )
goto V_329;
if ( ! F_175 ( V_7 , V_124 -> V_205 * 4 ) )
goto V_327;
if ( F_176 ( V_7 , V_88 , V_330 ) )
goto V_331;
V_124 = F_11 ( V_7 ) ;
V_122 = F_10 ( V_7 ) ;
V_332:
V_3 = F_177 ( & V_132 , V_7 , F_178 ( V_124 ) ,
V_124 -> V_20 , V_124 -> V_19 , F_179 ( V_7 ) ) ;
if ( ! V_3 )
goto V_333;
V_334:
if ( V_3 -> V_113 == V_135 )
goto V_335;
if ( V_3 -> V_113 == V_136 ) {
struct V_127 * V_161 = F_180 ( V_3 ) ;
struct V_2 * V_314 ;
V_3 = V_161 -> V_336 ;
F_168 ( V_7 , V_122 , V_124 ) ;
if ( F_101 ( V_3 , V_7 ) ) {
F_181 ( V_161 ) ;
goto V_327;
}
if ( F_182 ( V_3 -> V_113 != V_145 ) ) {
F_183 ( V_3 , V_161 ) ;
goto V_332;
}
F_64 ( V_3 ) ;
V_314 = F_184 ( V_3 , V_7 , V_161 , false ) ;
if ( ! V_314 ) {
F_181 ( V_161 ) ;
goto V_337;
}
if ( V_314 == V_3 ) {
F_181 ( V_161 ) ;
F_173 ( V_7 ) ;
} else if ( F_164 ( V_3 , V_314 , V_7 ) ) {
F_124 ( V_314 , V_7 ) ;
goto V_337;
} else {
F_67 ( V_3 ) ;
return 0 ;
}
}
if ( V_122 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_58 ( V_125 , V_142 ) ;
goto V_337;
}
if ( ! F_185 ( V_3 , V_338 , V_7 ) )
goto V_337;
F_168 ( V_7 , V_122 , V_124 ) ;
if ( F_101 ( V_3 , V_7 ) )
goto V_337;
if ( F_159 ( V_3 , V_7 ) )
goto V_337;
V_7 -> V_126 = NULL ;
if ( V_3 -> V_113 == V_145 ) {
V_324 = V_83 ( V_3 , V_7 ) ;
goto V_339;
}
F_186 ( V_3 ) ;
F_187 ( V_3 ) ;
F_188 ( F_14 ( V_3 ) , V_7 ) ;
V_324 = 0 ;
if ( ! F_26 ( V_3 ) ) {
if ( ! F_189 ( V_3 , V_7 ) )
V_324 = V_83 ( V_3 , V_7 ) ;
} else if ( F_182 ( F_190 ( V_3 , V_7 ,
V_3 -> V_340 + V_3 -> V_341 ) ) ) {
F_66 ( V_3 ) ;
F_58 ( V_125 , V_342 ) ;
goto V_337;
}
F_66 ( V_3 ) ;
V_339:
F_67 ( V_3 ) ;
return V_324 ? - 1 : 0 ;
V_333:
if ( ! F_185 ( NULL , V_338 , V_7 ) )
goto V_327;
F_168 ( V_7 , V_122 , V_124 ) ;
if ( F_163 ( V_7 ) ) {
V_331:
F_123 ( V_125 , V_316 ) ;
V_329:
F_123 ( V_125 , V_317 ) ;
} else {
F_124 ( NULL , V_7 ) ;
}
V_327:
F_79 ( V_7 ) ;
return 0 ;
V_337:
F_67 ( V_3 ) ;
goto V_327;
V_335:
if ( ! F_185 ( NULL , V_338 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_327;
}
F_168 ( V_7 , V_122 , V_124 ) ;
if ( F_163 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_331;
}
switch ( F_191 ( F_53 ( V_3 ) , V_7 , V_124 ) ) {
case V_343 :
{
struct V_2 * V_344 ;
V_344 = F_127 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
V_7 , F_178 ( V_124 ) ,
& F_10 ( V_7 ) -> V_18 , V_124 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_49 ( V_124 -> V_19 ) , F_106 ( V_7 ) ) ;
if ( V_344 ) {
struct V_261 * V_262 = F_53 ( V_3 ) ;
F_192 ( V_262 ) ;
V_3 = V_344 ;
F_173 ( V_7 ) ;
goto V_334;
}
}
case V_345 :
F_129 ( V_3 , V_7 ) ;
break;
case V_346 :
F_173 ( V_7 ) ;
F_124 ( V_3 , V_7 ) ;
F_192 ( F_53 ( V_3 ) ) ;
goto V_327;
case V_347 :
;
}
goto V_327;
}
static void F_193 ( struct V_6 * V_7 )
{
const struct V_106 * V_122 ;
const struct V_105 * V_124 ;
struct V_2 * V_3 ;
if ( V_7 -> V_325 != V_326 )
return;
if ( ! F_175 ( V_7 , F_194 ( V_7 ) + sizeof( struct V_105 ) ) )
return;
V_122 = F_10 ( V_7 ) ;
V_124 = F_11 ( V_7 ) ;
if ( V_124 -> V_205 < sizeof( struct V_105 ) / 4 )
return;
V_3 = F_48 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
& V_122 -> V_18 , V_124 -> V_20 ,
& V_122 -> V_16 , F_49 ( V_124 -> V_19 ) ,
F_179 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_348 = V_349 ;
if ( F_126 ( V_3 ) ) {
struct V_8 * V_9 = F_195 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_196 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_197 ( V_7 , V_9 ) ;
}
}
}
static int F_198 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_13 ( V_3 ) ;
F_199 ( V_3 ) ;
V_29 -> V_76 = & V_82 ;
#ifdef F_23
F_14 ( V_3 ) -> V_80 = & V_84 ;
#endif
return 0 ;
}
static void F_200 ( struct V_2 * V_3 )
{
F_201 ( V_3 ) ;
F_202 ( V_3 ) ;
}
static void F_203 ( struct V_350 * V_129 ,
const struct V_127 * V_161 , int V_351 )
{
long V_352 = V_161 -> V_353 . V_354 - V_355 ;
const struct V_4 * V_356 = & F_69 ( V_161 ) -> V_171 ;
const struct V_4 * V_19 = & F_69 ( V_161 ) -> V_172 ;
if ( V_352 < 0 )
V_352 = 0 ;
F_204 ( V_129 ,
L_5
L_6 ,
V_351 ,
V_356 -> V_17 [ 0 ] , V_356 -> V_17 [ 1 ] ,
V_356 -> V_17 [ 2 ] , V_356 -> V_17 [ 3 ] ,
F_69 ( V_161 ) -> V_357 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_49 ( F_69 ( V_161 ) -> V_358 ) ,
V_154 ,
0 , 0 ,
1 ,
F_205 ( V_352 ) ,
V_161 -> V_359 ,
F_206 ( F_207 ( V_129 ) ,
F_208 ( V_161 -> V_336 ) ) ,
0 ,
0 ,
0 , V_161 ) ;
}
static void F_209 ( struct V_350 * V_129 , struct V_2 * V_360 , int V_351 )
{
const struct V_4 * V_19 , * V_356 ;
T_7 V_361 , V_362 ;
int V_363 ;
unsigned long V_364 ;
const struct V_26 * V_27 = F_5 ( V_360 ) ;
const struct V_32 * V_33 = F_14 ( V_360 ) ;
const struct V_28 * V_29 = F_13 ( V_360 ) ;
const struct V_365 * V_366 = & V_29 -> V_367 . V_366 ;
int V_368 ;
int V_369 ;
V_19 = & V_360 -> V_62 ;
V_356 = & V_360 -> V_86 ;
V_361 = F_49 ( V_27 -> V_107 ) ;
V_362 = F_49 ( V_27 -> V_94 ) ;
if ( V_29 -> V_370 == V_371 ) {
V_363 = 1 ;
V_364 = V_29 -> V_372 ;
} else if ( V_29 -> V_370 == V_373 ) {
V_363 = 4 ;
V_364 = V_29 -> V_372 ;
} else if ( F_210 ( & V_360 -> V_374 ) ) {
V_363 = 2 ;
V_364 = V_360 -> V_374 . V_354 ;
} else {
V_363 = 0 ;
V_364 = V_355 ;
}
V_369 = F_211 ( V_360 ) ;
if ( V_369 == V_145 )
V_368 = V_360 -> V_375 ;
else
V_368 = F_212 ( int , V_33 -> V_275 - V_33 -> V_376 , 0 ) ;
F_204 ( V_129 ,
L_5
L_7 ,
V_351 ,
V_356 -> V_17 [ 0 ] , V_356 -> V_17 [ 1 ] ,
V_356 -> V_17 [ 2 ] , V_356 -> V_17 [ 3 ] , V_362 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_361 ,
V_369 ,
V_33 -> V_64 - V_33 -> V_130 ,
V_368 ,
V_363 ,
F_213 ( V_364 - V_355 ) ,
V_29 -> V_377 ,
F_206 ( F_207 ( V_129 ) , F_208 ( V_360 ) ) ,
V_29 -> V_378 ,
F_214 ( V_360 ) ,
F_215 ( & V_360 -> V_379 ) , V_360 ,
F_205 ( V_29 -> V_380 ) ,
F_205 ( V_29 -> V_381 . V_382 ) ,
( V_29 -> V_381 . V_383 << 1 ) | V_29 -> V_381 . V_384 ,
V_33 -> V_385 ,
V_369 == V_145 ?
V_366 -> V_386 :
( F_216 ( V_33 ) ? - 1 : V_33 -> V_387 )
) ;
}
static void F_217 ( struct V_350 * V_129 ,
struct V_261 * V_262 , int V_351 )
{
long V_388 = V_262 -> V_389 . V_354 - V_355 ;
const struct V_4 * V_19 , * V_356 ;
T_7 V_361 , V_362 ;
V_19 = & V_262 -> V_390 ;
V_356 = & V_262 -> V_391 ;
V_361 = F_49 ( V_262 -> V_392 ) ;
V_362 = F_49 ( V_262 -> V_393 ) ;
F_204 ( V_129 ,
L_5
L_8 ,
V_351 ,
V_356 -> V_17 [ 0 ] , V_356 -> V_17 [ 1 ] ,
V_356 -> V_17 [ 2 ] , V_356 -> V_17 [ 3 ] , V_362 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_361 ,
V_262 -> V_394 , 0 , 0 ,
3 , F_213 ( V_388 ) , 0 , 0 , 0 , 0 ,
F_215 ( & V_262 -> V_395 ) , V_262 ) ;
}
static int F_218 ( struct V_350 * V_129 , void * V_396 )
{
struct V_397 * V_398 ;
struct V_2 * V_3 = V_396 ;
if ( V_396 == V_399 ) {
F_219 ( V_129 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_139;
}
V_398 = V_129 -> V_400 ;
if ( V_3 -> V_113 == V_135 )
F_217 ( V_129 , V_396 , V_398 -> V_401 ) ;
else if ( V_3 -> V_113 == V_136 )
F_203 ( V_129 , V_396 , V_398 -> V_401 ) ;
else
F_209 ( V_129 , V_396 , V_398 -> V_401 ) ;
V_139:
return 0 ;
}
int T_8 F_220 ( struct V_125 * V_125 )
{
return F_221 ( V_125 , & V_402 ) ;
}
void F_222 ( struct V_125 * V_125 )
{
F_223 ( V_125 , & V_402 ) ;
}
static void F_224 ( struct V_2 * V_3 , int V_403 )
{
struct V_26 * V_27 = F_5 ( V_3 ) ;
F_225 ( V_3 , F_226 ( struct V_26 , V_290 ) ) ;
V_403 -= F_226 ( struct V_26 , V_290 ) + sizeof( V_27 -> V_290 ) ;
memset ( & V_27 -> V_290 + 1 , 0 , V_403 ) ;
}
static int T_8 F_227 ( struct V_125 * V_125 )
{
return F_228 ( & V_125 -> V_236 . F_14 , V_404 ,
V_405 , V_88 , V_125 ) ;
}
static void T_9 F_229 ( struct V_125 * V_125 )
{
F_230 ( V_125 -> V_236 . F_14 ) ;
}
static void T_9 F_231 ( struct V_406 * V_407 )
{
F_232 ( & V_132 , & V_99 , V_45 ) ;
}
int T_10 F_233 ( void )
{
int V_324 ;
V_324 = F_234 ( & V_408 , V_88 ) ;
if ( V_324 )
goto V_139;
V_324 = F_235 ( & V_409 ) ;
if ( V_324 )
goto V_410;
V_324 = F_236 ( & V_411 ) ;
if ( V_324 )
goto V_412;
V_139:
return V_324 ;
V_412:
F_237 ( & V_409 ) ;
V_410:
F_238 ( & V_408 , V_88 ) ;
goto V_139;
}
void F_239 ( void )
{
F_240 ( & V_411 ) ;
F_237 ( & V_409 ) ;
F_238 ( & V_408 , V_88 ) ;
}
