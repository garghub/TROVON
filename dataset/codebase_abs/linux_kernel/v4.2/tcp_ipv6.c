static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return NULL ;
}
static void F_2 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( V_9 ) {
const struct V_10 * V_11 = ( const struct V_10 * ) V_9 ;
F_4 ( V_9 ) ;
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
struct V_36 V_37 ;
struct V_8 * V_9 ;
int V_38 ;
int V_39 ;
if ( V_23 < V_40 )
return - V_41 ;
if ( V_25 -> V_42 != V_43 )
return - V_44 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( V_31 -> V_45 ) {
V_37 . V_46 = V_25 -> V_47 & V_48 ;
F_15 ( V_37 . V_46 ) ;
if ( V_37 . V_46 & V_49 ) {
struct V_50 * V_46 ;
V_46 = F_16 ( V_3 , V_37 . V_46 ) ;
if ( ! V_46 )
return - V_41 ;
F_17 ( V_46 ) ;
}
}
if ( F_18 ( & V_25 -> V_51 ) )
V_25 -> V_51 . V_52 [ 15 ] = 0x1 ;
V_38 = F_19 ( & V_25 -> V_51 ) ;
if ( V_38 & V_53 )
return - V_54 ;
if ( V_38 & V_55 ) {
if ( V_23 >= sizeof( struct V_24 ) &&
V_25 -> V_56 ) {
if ( V_3 -> V_57 &&
V_3 -> V_57 != V_25 -> V_56 )
return - V_41 ;
V_3 -> V_57 = V_25 -> V_56 ;
}
if ( ! V_3 -> V_57 )
return - V_41 ;
}
if ( V_33 -> V_58 . V_59 &&
! F_20 ( & V_3 -> V_60 , & V_25 -> V_51 ) ) {
V_33 -> V_58 . V_61 = 0 ;
V_33 -> V_58 . V_59 = 0 ;
V_33 -> V_62 = 0 ;
}
V_3 -> V_60 = V_25 -> V_51 ;
V_31 -> V_63 = V_37 . V_46 ;
if ( V_38 == V_64 ) {
T_2 V_65 = V_29 -> V_66 ;
struct V_67 sin ;
F_21 ( V_3 , L_1 ) ;
if ( F_22 ( V_3 ) )
return - V_54 ;
sin . V_68 = V_69 ;
sin . V_70 = V_25 -> V_71 ;
sin . V_72 . V_73 = V_25 -> V_51 . V_17 [ 3 ] ;
V_29 -> V_74 = & V_75 ;
V_3 -> V_76 = V_77 ;
#ifdef F_23
V_33 -> V_78 = & V_79 ;
#endif
V_39 = F_24 ( V_3 , (struct V_21 * ) & sin , sizeof( sin ) ) ;
if ( V_39 ) {
V_29 -> V_66 = V_65 ;
V_29 -> V_74 = & V_80 ;
V_3 -> V_76 = V_81 ;
#ifdef F_23
V_33 -> V_78 = & V_82 ;
#endif
goto V_83;
}
V_31 -> V_18 = V_3 -> V_84 ;
return V_39 ;
}
if ( ! F_18 ( & V_3 -> V_84 ) )
V_18 = & V_3 -> V_84 ;
V_37 . V_85 = V_86 ;
V_37 . V_16 = V_3 -> V_60 ;
V_37 . V_18 = V_18 ? * V_18 : V_31 -> V_18 ;
V_37 . V_87 = V_3 -> V_57 ;
V_37 . V_88 = V_3 -> V_89 ;
V_37 . V_90 = V_25 -> V_71 ;
V_37 . V_91 = V_27 -> V_92 ;
V_34 = F_25 ( & V_37 , V_31 -> V_93 , & V_35 ) ;
F_26 ( V_3 , F_27 ( & V_37 ) ) ;
V_9 = F_28 ( V_3 , & V_37 , V_34 ) ;
if ( F_29 ( V_9 ) ) {
V_39 = F_30 ( V_9 ) ;
goto V_83;
}
if ( ! V_18 ) {
V_18 = & V_37 . V_18 ;
V_3 -> V_84 = * V_18 ;
}
V_31 -> V_18 = * V_18 ;
V_27 -> V_94 = V_95 ;
V_3 -> V_96 = V_97 ;
F_31 ( V_3 , V_9 , NULL , NULL ) ;
if ( V_98 . V_99 &&
! V_33 -> V_58 . V_59 &&
F_20 ( & V_37 . V_16 , & V_3 -> V_60 ) )
F_32 ( V_3 , V_9 ) ;
V_29 -> V_66 = 0 ;
if ( V_31 -> V_93 )
V_29 -> V_66 = ( V_31 -> V_93 -> V_100 +
V_31 -> V_93 -> V_101 ) ;
V_33 -> V_58 . V_102 = V_103 - sizeof( struct V_104 ) - sizeof( struct V_105 ) ;
V_27 -> V_106 = V_25 -> V_71 ;
F_33 ( V_3 , V_107 ) ;
V_39 = F_34 ( & V_98 , V_3 ) ;
if ( V_39 )
goto V_108;
F_35 ( V_3 ) ;
if ( ! V_33 -> V_62 && F_36 ( ! V_33 -> V_109 ) )
V_33 -> V_62 = F_9 ( V_31 -> V_18 . V_17 ,
V_3 -> V_60 . V_17 ,
V_27 -> V_92 ,
V_27 -> V_106 ) ;
V_39 = F_37 ( V_3 ) ;
if ( V_39 )
goto V_108;
return 0 ;
V_108:
F_33 ( V_3 , V_110 ) ;
F_38 ( V_3 ) ;
V_83:
V_27 -> V_106 = 0 ;
V_3 -> V_111 = 0 ;
return V_39 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_112 ) & ( V_113 | V_114 ) )
return;
V_9 = F_40 ( V_3 , F_14 ( V_3 ) -> V_115 ) ;
if ( ! V_9 )
return;
if ( F_13 ( V_3 ) -> V_116 > F_41 ( V_9 ) ) {
F_42 ( V_3 , F_41 ( V_9 ) ) ;
F_43 ( V_3 ) ;
}
}
static void F_44 ( struct V_6 * V_7 , struct V_117 * V_93 ,
T_3 type , T_3 V_118 , int V_119 , T_4 V_120 )
{
const struct V_105 * V_121 = ( const struct V_105 * ) V_7 -> V_122 ;
const struct V_104 * V_123 = (struct V_104 * ) ( V_7 -> V_122 + V_119 ) ;
struct V_124 * V_124 = F_45 ( V_7 -> V_125 ) ;
struct V_126 * V_127 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_1 V_128 , V_129 ;
struct V_2 * V_3 ;
int V_39 ;
V_3 = F_46 ( V_124 , & V_130 ,
& V_121 -> V_16 , V_123 -> V_19 ,
& V_121 -> V_18 , F_47 ( V_123 -> V_20 ) ,
V_7 -> V_125 -> V_131 ) ;
if ( ! V_3 ) {
F_48 ( V_124 , F_49 ( V_7 -> V_125 ) ,
V_132 ) ;
return;
}
if ( V_3 -> V_112 == V_133 ) {
F_50 ( F_51 ( V_3 ) ) ;
return;
}
V_128 = F_52 ( V_123 -> V_128 ) ;
if ( V_3 -> V_112 == V_134 )
return F_53 ( V_3 , V_128 ) ;
F_54 ( V_3 ) ;
if ( F_55 ( V_3 ) && type != V_135 )
F_56 ( V_124 , V_136 ) ;
if ( V_3 -> V_112 == V_110 )
goto V_137;
if ( F_10 ( V_7 ) -> V_138 < F_6 ( V_3 ) -> V_139 ) {
F_56 ( V_124 , V_140 ) ;
goto V_137;
}
V_33 = F_14 ( V_3 ) ;
V_127 = V_33 -> V_141 ;
V_129 = V_127 ? F_57 ( V_127 ) -> V_142 : V_33 -> V_129 ;
if ( V_3 -> V_112 != V_143 &&
! F_58 ( V_128 , V_129 , V_33 -> V_144 ) ) {
F_56 ( V_124 , V_145 ) ;
goto V_137;
}
V_31 = F_6 ( V_3 ) ;
if ( type == V_146 ) {
struct V_8 * V_9 = F_59 ( V_3 , V_31 -> V_147 ) ;
if ( V_9 )
V_9 -> V_148 -> V_149 ( V_9 , V_3 , V_7 ) ;
goto V_137;
}
if ( type == V_135 ) {
if ( V_3 -> V_112 == V_143 )
goto V_137;
if ( ! F_60 ( V_3 ) )
goto V_137;
V_33 -> V_115 = F_52 ( V_120 ) ;
if ( ! F_55 ( V_3 ) )
F_39 ( V_3 ) ;
else if ( ! F_61 ( V_150 ,
& V_33 -> V_151 ) )
F_62 ( V_3 ) ;
goto V_137;
}
F_63 ( type , V_118 , & V_39 ) ;
switch ( V_3 -> V_112 ) {
case V_107 :
case V_152 :
if ( V_127 && ! V_127 -> V_3 )
break;
if ( ! F_55 ( V_3 ) ) {
V_3 -> V_153 = V_39 ;
V_3 -> V_154 ( V_3 ) ;
F_64 ( V_3 ) ;
} else
V_3 -> V_155 = V_39 ;
goto V_137;
}
if ( ! F_55 ( V_3 ) && V_31 -> V_156 ) {
V_3 -> V_153 = V_39 ;
V_3 -> V_154 ( V_3 ) ;
} else
V_3 -> V_155 = V_39 ;
V_137:
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
}
static int F_67 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_157 * V_158 ,
struct V_126 * V_159 ,
T_5 V_160 ,
struct V_161 * V_162 )
{
struct V_163 * V_164 = F_68 ( V_159 ) ;
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 = & V_158 -> V_165 . V_166 ;
struct V_6 * V_7 ;
int V_39 = - V_167 ;
if ( ! V_9 && ( V_9 = F_69 ( V_3 , V_37 , V_159 ) ) == NULL )
goto V_168;
V_7 = F_70 ( V_3 , V_9 , V_159 , V_162 ) ;
if ( V_7 ) {
F_71 ( V_7 , & V_164 -> V_169 ,
& V_164 -> V_170 ) ;
V_37 -> V_16 = V_164 -> V_170 ;
if ( V_31 -> V_171 && V_164 -> V_172 )
V_37 -> V_46 = V_50 ( F_10 ( V_164 -> V_172 ) ) ;
F_72 ( V_7 , V_160 ) ;
V_39 = F_73 ( V_3 , V_7 , V_37 , V_31 -> V_93 , V_31 -> V_173 ) ;
V_39 = F_74 ( V_39 ) ;
}
V_168:
return V_39 ;
}
static void F_75 ( struct V_126 * V_159 )
{
F_76 ( F_68 ( V_159 ) -> V_172 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_77 ( V_3 , (union V_174 * ) V_5 , V_43 ) ;
}
static struct V_1 * F_78 ( struct V_2 * V_3 ,
const struct V_2 * V_175 )
{
return F_1 ( V_3 , & V_175 -> V_60 ) ;
}
static int F_79 ( struct V_2 * V_3 , char T_6 * V_176 ,
int V_177 )
{
struct V_178 V_179 ;
struct V_24 * V_180 = (struct V_24 * ) & V_179 . V_181 ;
if ( V_177 < sizeof( V_179 ) )
return - V_41 ;
if ( F_80 ( & V_179 , V_176 , sizeof( V_179 ) ) )
return - V_182 ;
if ( V_180 -> V_42 != V_43 )
return - V_41 ;
if ( ! V_179 . V_183 ) {
if ( F_81 ( & V_180 -> V_51 ) )
return F_82 ( V_3 , (union V_174 * ) & V_180 -> V_51 . V_17 [ 3 ] ,
V_69 ) ;
return F_82 ( V_3 , (union V_174 * ) & V_180 -> V_51 ,
V_43 ) ;
}
if ( V_179 . V_183 > V_184 )
return - V_41 ;
if ( F_81 ( & V_180 -> V_51 ) )
return F_83 ( V_3 , (union V_174 * ) & V_180 -> V_51 . V_17 [ 3 ] ,
V_69 , V_179 . V_185 , V_179 . V_183 , V_186 ) ;
return F_83 ( V_3 , (union V_174 * ) & V_180 -> V_51 ,
V_43 , V_179 . V_185 , V_179 . V_183 , V_186 ) ;
}
static int F_84 ( struct V_187 * V_188 ,
const struct V_4 * V_16 ,
const struct V_4 * V_18 , int V_189 )
{
struct V_190 * V_191 ;
struct V_192 V_193 ;
V_191 = & V_188 -> V_194 . V_166 ;
V_191 -> V_18 = * V_18 ;
V_191 -> V_16 = * V_16 ;
V_191 -> V_195 = F_85 ( V_86 ) ;
V_191 -> V_196 = F_85 ( V_189 ) ;
F_86 ( & V_193 , V_191 , sizeof( * V_191 ) ) ;
return F_87 ( & V_188 -> V_197 , & V_193 , sizeof( * V_191 ) ) ;
}
static int F_88 ( char * V_198 , struct V_1 * V_199 ,
const struct V_4 * V_16 , struct V_4 * V_18 ,
const struct V_104 * V_123 )
{
struct V_187 * V_188 ;
struct V_200 * V_201 ;
V_188 = F_89 () ;
if ( ! V_188 )
goto V_202;
V_201 = & V_188 -> V_197 ;
if ( F_90 ( V_201 ) )
goto V_203;
if ( F_84 ( V_188 , V_16 , V_18 , V_123 -> V_204 << 2 ) )
goto V_203;
if ( F_91 ( V_188 , V_123 ) )
goto V_203;
if ( F_92 ( V_188 , V_199 ) )
goto V_203;
if ( F_93 ( V_201 , V_198 ) )
goto V_203;
F_94 () ;
return 0 ;
V_203:
F_94 () ;
V_202:
memset ( V_198 , 0 , 16 ) ;
return 1 ;
}
static int F_95 ( char * V_198 ,
const struct V_1 * V_199 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_18 , * V_16 ;
struct V_187 * V_188 ;
struct V_200 * V_201 ;
const struct V_104 * V_123 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_18 = & V_3 -> V_84 ;
V_16 = & V_3 -> V_60 ;
} else {
const struct V_105 * V_205 = F_10 ( V_7 ) ;
V_18 = & V_205 -> V_18 ;
V_16 = & V_205 -> V_16 ;
}
V_188 = F_89 () ;
if ( ! V_188 )
goto V_202;
V_201 = & V_188 -> V_197 ;
if ( F_90 ( V_201 ) )
goto V_203;
if ( F_84 ( V_188 , V_16 , V_18 , V_7 -> V_196 ) )
goto V_203;
if ( F_91 ( V_188 , V_123 ) )
goto V_203;
if ( F_96 ( V_188 , V_7 , V_123 -> V_204 << 2 ) )
goto V_203;
if ( F_92 ( V_188 , V_199 ) )
goto V_203;
if ( F_93 ( V_201 , V_198 ) )
goto V_203;
F_94 () ;
return 0 ;
V_203:
F_94 () ;
V_202:
memset ( V_198 , 0 , 16 ) ;
return 1 ;
}
static bool F_97 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_206 = NULL ;
struct V_1 * V_207 ;
const struct V_105 * V_205 = F_10 ( V_7 ) ;
const struct V_104 * V_123 = F_11 ( V_7 ) ;
int V_208 ;
T_3 V_209 [ 16 ] ;
V_207 = F_1 ( V_3 , & V_205 -> V_18 ) ;
V_206 = F_98 ( V_123 ) ;
if ( ! V_207 && ! V_206 )
return false ;
if ( V_207 && ! V_206 ) {
F_56 ( F_99 ( V_3 ) , V_210 ) ;
return true ;
}
if ( ! V_207 && V_206 ) {
F_56 ( F_99 ( V_3 ) , V_211 ) ;
return true ;
}
V_208 = F_95 ( V_209 ,
V_207 ,
NULL , V_7 ) ;
if ( V_208 || memcmp ( V_206 , V_209 , 16 ) != 0 ) {
F_100 ( L_2 ,
V_208 ? L_3 : L_4 ,
& V_205 -> V_18 , F_47 ( V_123 -> V_20 ) ,
& V_205 -> V_16 , F_47 ( V_123 -> V_19 ) ) ;
return true ;
}
return false ;
}
static void F_101 ( struct V_126 * V_159 , struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_163 * V_164 = F_68 ( V_159 ) ;
struct V_30 * V_31 = F_6 ( V_3 ) ;
V_164 -> V_170 = F_10 ( V_7 ) -> V_18 ;
V_164 -> V_169 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_3 -> V_57 &&
F_19 ( & V_164 -> V_170 ) & V_55 )
V_164 -> V_212 = F_102 ( V_7 ) ;
if ( ! F_103 ( V_7 ) -> V_213 &&
( F_104 ( V_3 , V_7 , & F_103 ( V_7 ) -> V_214 . V_215 ) ||
V_31 -> V_216 . V_217 . V_218 ||
V_31 -> V_216 . V_217 . V_219 || V_31 -> V_216 . V_217 . V_220 ||
V_31 -> V_216 . V_217 . V_221 || V_31 -> V_171 ) ) {
F_105 ( & V_7 -> V_222 ) ;
V_164 -> V_172 = V_7 ;
}
}
static struct V_8 * F_106 ( struct V_2 * V_3 , struct V_157 * V_158 ,
const struct V_126 * V_159 ,
bool * V_223 )
{
if ( V_223 )
* V_223 = true ;
return F_69 ( V_3 , & V_158 -> V_165 . V_166 , V_159 ) ;
}
static void F_107 ( struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_128 ,
T_2 V_224 , T_2 V_225 , T_2 V_226 , T_2 V_227 ,
int V_228 , struct V_1 * V_199 , int V_229 ,
T_3 V_173 , T_2 V_230 )
{
const struct V_104 * V_123 = F_11 ( V_7 ) ;
struct V_104 * V_231 ;
struct V_6 * V_232 ;
struct V_36 V_37 ;
struct V_124 * V_124 = V_3 ? F_99 ( V_3 ) : F_45 ( F_3 ( V_7 ) -> V_125 ) ;
struct V_2 * V_233 = V_124 -> V_234 . F_14 ;
unsigned int V_235 = sizeof( struct V_104 ) ;
struct V_8 * V_9 ;
T_4 * V_236 ;
if ( V_227 )
V_235 += V_237 ;
#ifdef F_23
if ( V_199 )
V_235 += V_238 ;
#endif
V_232 = F_108 ( V_239 + sizeof( struct V_105 ) + V_235 ,
V_240 ) ;
if ( ! V_232 )
return;
F_109 ( V_232 , V_239 + sizeof( struct V_105 ) + V_235 ) ;
V_231 = (struct V_104 * ) F_110 ( V_232 , V_235 ) ;
F_111 ( V_232 ) ;
memset ( V_231 , 0 , sizeof( * V_231 ) ) ;
V_231 -> V_19 = V_123 -> V_20 ;
V_231 -> V_20 = V_123 -> V_19 ;
V_231 -> V_204 = V_235 / 4 ;
V_231 -> V_128 = F_112 ( V_128 ) ;
V_231 -> V_241 = F_112 ( V_224 ) ;
V_231 -> V_224 = ! V_229 || ! V_123 -> V_224 ;
V_231 -> V_229 = V_229 ;
V_231 -> V_242 = F_113 ( V_225 ) ;
V_236 = ( T_4 * ) ( V_231 + 1 ) ;
if ( V_227 ) {
* V_236 ++ = F_112 ( ( V_243 << 24 ) | ( V_243 << 16 ) |
( V_244 << 8 ) | V_245 ) ;
* V_236 ++ = F_112 ( V_226 ) ;
* V_236 ++ = F_112 ( V_227 ) ;
}
#ifdef F_23
if ( V_199 ) {
* V_236 ++ = F_112 ( ( V_243 << 24 ) | ( V_243 << 16 ) |
( V_246 << 8 ) | V_247 ) ;
F_88 ( ( T_7 * ) V_236 , V_199 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , V_231 ) ;
}
#endif
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_16 = F_10 ( V_7 ) -> V_18 ;
V_37 . V_18 = F_10 ( V_7 ) -> V_16 ;
V_37 . V_46 = V_230 ;
V_232 -> V_248 = V_249 ;
V_232 -> V_250 = 0 ;
F_71 ( V_232 , & V_37 . V_18 , & V_37 . V_16 ) ;
V_37 . V_85 = V_86 ;
if ( F_114 ( & V_37 . V_16 ) && ! V_228 )
V_37 . V_87 = F_102 ( V_7 ) ;
else
V_37 . V_87 = V_228 ;
V_37 . V_88 = F_115 ( V_124 , V_7 -> V_251 ) ;
V_37 . V_90 = V_231 -> V_19 ;
V_37 . V_91 = V_231 -> V_20 ;
F_116 ( V_7 , F_27 ( & V_37 ) ) ;
V_9 = F_28 ( V_233 , & V_37 , NULL ) ;
if ( ! F_29 ( V_9 ) ) {
F_117 ( V_232 , V_9 ) ;
F_73 ( V_233 , V_232 , & V_37 , NULL , V_173 ) ;
F_118 ( V_124 , V_252 ) ;
if ( V_229 )
F_118 ( V_124 , V_253 ) ;
return;
}
F_76 ( V_232 ) ;
}
static void F_119 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_104 * V_123 = F_11 ( V_7 ) ;
T_2 V_128 = 0 , V_241 = 0 ;
struct V_1 * V_199 = NULL ;
#ifdef F_23
const T_7 * V_206 = NULL ;
struct V_105 * V_254 = F_10 ( V_7 ) ;
unsigned char V_209 [ 16 ] ;
int V_208 ;
struct V_2 * V_255 = NULL ;
#endif
int V_228 ;
if ( V_123 -> V_229 )
return;
if ( ! V_3 && ! F_120 ( V_7 ) )
return;
#ifdef F_23
V_206 = F_98 ( V_123 ) ;
if ( ! V_3 && V_206 ) {
V_255 = F_121 ( F_45 ( F_3 ( V_7 ) -> V_125 ) ,
& V_130 , & V_254 -> V_18 ,
V_123 -> V_20 , & V_254 -> V_16 ,
F_47 ( V_123 -> V_20 ) , F_102 ( V_7 ) ) ;
if ( ! V_255 )
return;
F_122 () ;
V_199 = F_1 ( V_255 , & V_254 -> V_18 ) ;
if ( ! V_199 )
goto V_256;
V_208 = F_95 ( V_209 , V_199 , NULL , V_7 ) ;
if ( V_208 || memcmp ( V_206 , V_209 , 16 ) != 0 )
goto V_256;
} else {
V_199 = V_3 ? F_1 ( V_3 , & V_254 -> V_18 ) : NULL ;
}
#endif
if ( V_123 -> V_224 )
V_128 = F_52 ( V_123 -> V_241 ) ;
else
V_241 = F_52 ( V_123 -> V_128 ) + V_123 -> V_257 + V_123 -> V_258 + V_7 -> V_196 -
( V_123 -> V_204 << 2 ) ;
V_228 = V_3 ? V_3 -> V_57 : 0 ;
F_107 ( V_3 , V_7 , V_128 , V_241 , 0 , 0 , 0 , V_228 , V_199 , 1 , 0 , 0 ) ;
#ifdef F_23
V_256:
if ( V_255 ) {
F_123 () ;
F_66 ( V_255 ) ;
}
#endif
}
static void F_124 ( struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_128 ,
T_2 V_224 , T_2 V_225 , T_2 V_226 , T_2 V_227 , int V_228 ,
struct V_1 * V_199 , T_3 V_173 ,
T_2 V_230 )
{
F_107 ( V_3 , V_7 , V_128 , V_224 , V_225 , V_226 , V_227 , V_228 , V_199 , 0 ,
V_173 , V_230 ) ;
}
static void F_125 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_259 * V_260 = F_51 ( V_3 ) ;
struct V_261 * V_262 = F_126 ( V_3 ) ;
F_124 ( V_3 , V_7 , V_262 -> V_263 , V_262 -> V_264 ,
V_262 -> V_265 >> V_260 -> V_266 ,
V_267 + V_262 -> V_268 ,
V_262 -> V_269 , V_260 -> V_270 , F_127 ( V_262 ) ,
V_260 -> V_271 , F_85 ( V_260 -> V_272 ) ) ;
F_50 ( V_260 ) ;
}
static void F_128 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_126 * V_159 )
{
F_124 ( V_3 , V_7 , ( V_3 -> V_112 == V_143 ) ?
F_57 ( V_159 ) -> V_142 + 1 : F_14 ( V_3 ) -> V_144 ,
F_57 ( V_159 ) -> V_273 , V_159 -> V_274 ,
V_267 , V_159 -> V_61 , V_3 -> V_57 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_129 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_104 * V_123 = F_11 ( V_7 ) ;
struct V_126 * V_159 ;
struct V_2 * V_275 ;
V_159 = F_130 ( V_3 , V_123 -> V_20 ,
& F_10 ( V_7 ) -> V_18 ,
& F_10 ( V_7 ) -> V_16 , F_102 ( V_7 ) ) ;
if ( V_159 ) {
V_275 = F_131 ( V_3 , V_7 , V_159 , false ) ;
if ( ! V_275 || V_275 == V_3 )
F_132 ( V_159 ) ;
return V_275 ;
}
V_275 = F_46 ( F_99 ( V_3 ) , & V_130 ,
& F_10 ( V_7 ) -> V_18 , V_123 -> V_20 ,
& F_10 ( V_7 ) -> V_16 , F_47 ( V_123 -> V_19 ) ,
F_102 ( V_7 ) ) ;
if ( V_275 ) {
if ( V_275 -> V_112 != V_133 ) {
F_54 ( V_275 ) ;
return V_275 ;
}
F_50 ( F_51 ( V_275 ) ) ;
return NULL ;
}
#ifdef F_133
if ( ! V_123 -> V_257 )
V_3 = F_134 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_135 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_195 == F_113 ( V_276 ) )
return F_136 ( V_3 , V_7 ) ;
if ( ! F_120 ( V_7 ) )
goto V_277;
return F_137 ( & V_278 ,
& V_279 , V_3 , V_7 ) ;
V_277:
F_56 ( F_99 ( V_3 ) , V_280 ) ;
return 0 ;
}
static struct V_2 * F_138 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_126 * V_159 ,
struct V_8 * V_9 )
{
struct V_163 * V_164 ;
struct V_30 * V_281 , * V_31 = F_6 ( V_3 ) ;
struct V_282 * V_283 ;
struct V_26 * V_284 ;
struct V_32 * V_285 ;
struct V_2 * V_286 ;
#ifdef F_23
struct V_1 * V_199 ;
#endif
struct V_36 V_37 ;
if ( V_7 -> V_195 == F_113 ( V_276 ) ) {
V_286 = F_139 ( V_3 , V_7 , V_159 , V_9 ) ;
if ( ! V_286 )
return NULL ;
V_283 = (struct V_282 * ) V_286 ;
F_5 ( V_286 ) -> V_287 = & V_283 -> V_288 ;
V_284 = F_5 ( V_286 ) ;
V_281 = F_6 ( V_286 ) ;
V_285 = F_14 ( V_286 ) ;
memcpy ( V_281 , V_31 , sizeof( struct V_30 ) ) ;
V_281 -> V_18 = V_286 -> V_84 ;
F_13 ( V_286 ) -> V_74 = & V_75 ;
V_286 -> V_76 = V_77 ;
#ifdef F_23
V_285 -> V_78 = & V_79 ;
#endif
V_281 -> V_289 = NULL ;
V_281 -> V_290 = NULL ;
V_281 -> V_291 = NULL ;
V_281 -> V_93 = NULL ;
V_281 -> V_292 = F_102 ( V_7 ) ;
V_281 -> V_293 = F_10 ( V_7 ) -> V_138 ;
V_281 -> V_294 = F_140 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_171 )
V_281 -> V_63 = V_50 ( F_10 ( V_7 ) ) ;
F_42 ( V_286 , F_13 ( V_286 ) -> V_116 ) ;
return V_286 ;
}
V_164 = F_68 ( V_159 ) ;
if ( F_141 ( V_3 ) )
goto V_295;
if ( ! V_9 ) {
V_9 = F_69 ( V_3 , & V_37 , V_159 ) ;
if ( ! V_9 )
goto V_137;
}
V_286 = F_142 ( V_3 , V_159 , V_7 ) ;
if ( ! V_286 )
goto V_296;
V_286 -> V_96 = V_97 ;
F_31 ( V_286 , V_9 , NULL , NULL ) ;
F_2 ( V_286 , V_7 ) ;
V_283 = (struct V_282 * ) V_286 ;
F_5 ( V_286 ) -> V_287 = & V_283 -> V_288 ;
V_285 = F_14 ( V_286 ) ;
V_284 = F_5 ( V_286 ) ;
V_281 = F_6 ( V_286 ) ;
memcpy ( V_281 , V_31 , sizeof( struct V_30 ) ) ;
V_286 -> V_60 = V_164 -> V_170 ;
V_281 -> V_18 = V_164 -> V_169 ;
V_286 -> V_84 = V_164 -> V_169 ;
V_286 -> V_57 = V_164 -> V_212 ;
F_35 ( V_286 ) ;
V_284 -> V_297 = NULL ;
V_281 -> V_289 = NULL ;
V_281 -> V_290 = NULL ;
V_281 -> V_216 . V_298 = V_31 -> V_216 . V_298 ;
V_281 -> V_291 = NULL ;
if ( V_164 -> V_172 ) {
V_281 -> V_291 = F_143 ( V_164 -> V_172 ,
F_144 ( V_3 , V_240 ) ) ;
F_145 ( V_164 -> V_172 ) ;
V_164 -> V_172 = NULL ;
if ( V_281 -> V_291 )
F_146 ( V_281 -> V_291 , V_286 ) ;
}
V_281 -> V_93 = NULL ;
V_281 -> V_292 = F_102 ( V_7 ) ;
V_281 -> V_293 = F_10 ( V_7 ) -> V_138 ;
V_281 -> V_294 = F_140 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_171 )
V_281 -> V_63 = V_50 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_93 )
V_281 -> V_93 = F_147 ( V_286 , V_31 -> V_93 ) ;
F_13 ( V_286 ) -> V_66 = 0 ;
if ( V_281 -> V_93 )
F_13 ( V_286 ) -> V_66 = ( V_281 -> V_93 -> V_101 +
V_281 -> V_93 -> V_100 ) ;
F_148 ( V_286 , V_9 ) ;
F_42 ( V_286 , F_41 ( V_9 ) ) ;
V_285 -> V_299 = F_149 ( V_9 ) ;
if ( F_14 ( V_3 ) -> V_58 . V_300 &&
F_14 ( V_3 ) -> V_58 . V_300 < V_285 -> V_299 )
V_285 -> V_299 = F_14 ( V_3 ) -> V_58 . V_300 ;
F_150 ( V_286 ) ;
V_284 -> V_301 = V_284 -> V_302 = V_95 ;
V_284 -> V_94 = V_95 ;
#ifdef F_23
V_199 = F_1 ( V_3 , & V_286 -> V_60 ) ;
if ( V_199 ) {
F_83 ( V_286 , (union V_174 * ) & V_286 -> V_60 ,
V_43 , V_199 -> V_199 , V_199 -> V_303 ,
F_144 ( V_3 , V_240 ) ) ;
}
#endif
if ( F_151 ( V_3 , V_286 ) < 0 ) {
F_152 ( V_286 ) ;
F_64 ( V_286 ) ;
goto V_137;
}
F_153 ( V_286 , NULL ) ;
return V_286 ;
V_295:
F_56 ( F_99 ( V_3 ) , V_304 ) ;
V_296:
F_154 ( V_9 ) ;
V_137:
F_56 ( F_99 ( V_3 ) , V_280 ) ;
return NULL ;
}
static int V_81 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_6 * V_305 = NULL ;
if ( V_7 -> V_195 == F_113 ( V_276 ) )
return V_77 ( V_3 , V_7 ) ;
if ( F_155 ( V_3 , V_7 ) )
goto V_306;
if ( V_31 -> V_216 . V_298 )
V_305 = F_143 ( V_7 , F_144 ( V_3 , V_240 ) ) ;
if ( V_3 -> V_112 == V_307 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_156 ( V_3 , V_7 ) ;
F_157 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_148 -> V_308 ( V_9 , V_31 -> V_15 ) == NULL ) {
F_154 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_158 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_196 ) ;
if ( V_305 )
goto V_309;
return 0 ;
}
if ( F_159 ( V_7 ) )
goto V_310;
if ( V_3 -> V_112 == V_143 ) {
struct V_2 * V_275 = F_129 ( V_3 , V_7 ) ;
if ( ! V_275 )
goto V_306;
if ( V_275 != V_3 ) {
F_156 ( V_275 , V_7 ) ;
F_157 ( V_3 , V_7 ) ;
if ( F_160 ( V_3 , V_275 , V_7 ) )
goto V_311;
if ( V_305 )
F_161 ( V_305 ) ;
return 0 ;
}
} else
F_156 ( V_3 , V_7 ) ;
if ( F_162 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_196 ) )
goto V_311;
if ( V_305 )
goto V_309;
return 0 ;
V_311:
F_119 ( V_3 , V_7 ) ;
V_306:
if ( V_305 )
F_161 ( V_305 ) ;
F_76 ( V_7 ) ;
return 0 ;
V_310:
F_118 ( F_99 ( V_3 ) , V_312 ) ;
F_118 ( F_99 ( V_3 ) , V_313 ) ;
goto V_306;
V_309:
V_33 = F_14 ( V_3 ) ;
if ( F_103 ( V_305 ) -> V_314 == V_33 -> V_273 &&
! ( ( 1 << V_3 -> V_112 ) & ( V_114 | V_113 ) ) ) {
if ( V_31 -> V_216 . V_217 . V_218 || V_31 -> V_216 . V_217 . V_219 )
V_31 -> V_292 = F_102 ( V_305 ) ;
if ( V_31 -> V_216 . V_217 . V_220 || V_31 -> V_216 . V_217 . V_221 )
V_31 -> V_293 = F_10 ( V_305 ) -> V_138 ;
if ( V_31 -> V_216 . V_217 . V_315 || V_31 -> V_216 . V_217 . V_316 )
V_31 -> V_294 = F_140 ( F_10 ( V_305 ) ) ;
if ( V_31 -> V_171 )
V_31 -> V_63 = V_50 ( F_10 ( V_305 ) ) ;
if ( F_104 ( V_3 , V_305 , & F_103 ( V_305 ) -> V_214 . V_215 ) ) {
F_146 ( V_305 , V_3 ) ;
V_305 = F_163 ( & V_31 -> V_291 , V_305 ) ;
} else {
F_161 ( V_305 ) ;
V_305 = F_163 ( & V_31 -> V_291 , NULL ) ;
}
}
F_76 ( V_305 ) ;
return 0 ;
}
static void F_164 ( struct V_6 * V_7 , const struct V_105 * V_121 ,
const struct V_104 * V_123 )
{
memmove ( & F_103 ( V_7 ) -> V_214 . V_215 , F_165 ( V_7 ) ,
sizeof( struct V_117 ) ) ;
F_166 () ;
F_103 ( V_7 ) -> V_128 = F_52 ( V_123 -> V_128 ) ;
F_103 ( V_7 ) -> V_314 = ( F_103 ( V_7 ) -> V_128 + V_123 -> V_257 + V_123 -> V_258 +
V_7 -> V_196 - V_123 -> V_204 * 4 ) ;
F_103 ( V_7 ) -> V_241 = F_52 ( V_123 -> V_241 ) ;
F_103 ( V_7 ) -> V_317 = F_167 ( V_123 ) ;
F_103 ( V_7 ) -> V_213 = 0 ;
F_103 ( V_7 ) -> V_318 = F_168 ( V_121 ) ;
F_103 ( V_7 ) -> V_319 = 0 ;
}
static void F_169 ( struct V_6 * V_7 )
{
memmove ( F_165 ( V_7 ) , & F_103 ( V_7 ) -> V_214 . V_215 ,
sizeof( struct V_117 ) ) ;
}
static int F_170 ( struct V_6 * V_7 )
{
const struct V_104 * V_123 ;
const struct V_105 * V_121 ;
struct V_2 * V_3 ;
int V_320 ;
struct V_124 * V_124 = F_45 ( V_7 -> V_125 ) ;
if ( V_7 -> V_321 != V_322 )
goto V_323;
F_118 ( V_124 , V_324 ) ;
if ( ! F_171 ( V_7 , sizeof( struct V_104 ) ) )
goto V_323;
V_123 = F_11 ( V_7 ) ;
if ( V_123 -> V_204 < sizeof( struct V_104 ) / 4 )
goto V_325;
if ( ! F_171 ( V_7 , V_123 -> V_204 * 4 ) )
goto V_323;
if ( F_172 ( V_7 , V_86 , V_326 ) )
goto V_327;
V_123 = F_11 ( V_7 ) ;
V_121 = F_10 ( V_7 ) ;
V_3 = F_173 ( & V_130 , V_7 , V_123 -> V_20 , V_123 -> V_19 ,
F_174 ( V_7 ) ) ;
if ( ! V_3 )
goto V_328;
V_329:
if ( V_3 -> V_112 == V_133 )
goto V_330;
if ( V_121 -> V_138 < F_6 ( V_3 ) -> V_139 ) {
F_56 ( V_124 , V_140 ) ;
goto V_331;
}
if ( ! F_175 ( V_3 , V_332 , V_7 ) )
goto V_331;
F_164 ( V_7 , V_121 , V_123 ) ;
#ifdef F_23
if ( F_97 ( V_3 , V_7 ) )
goto V_331;
#endif
if ( F_155 ( V_3 , V_7 ) )
goto V_331;
F_176 ( V_3 ) ;
V_7 -> V_125 = NULL ;
F_177 ( V_3 ) ;
F_14 ( V_3 ) -> V_333 += F_178 ( T_5 , 1 , F_179 ( V_7 ) -> V_334 ) ;
V_320 = 0 ;
if ( ! F_55 ( V_3 ) ) {
if ( ! F_180 ( V_3 , V_7 ) )
V_320 = V_81 ( V_3 , V_7 ) ;
} else if ( F_181 ( F_182 ( V_3 , V_7 ,
V_3 -> V_335 + V_3 -> V_336 ) ) ) {
F_65 ( V_3 ) ;
F_56 ( V_124 , V_337 ) ;
goto V_331;
}
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
return V_320 ? - 1 : 0 ;
V_328:
if ( ! F_175 ( NULL , V_332 , V_7 ) )
goto V_323;
F_164 ( V_7 , V_121 , V_123 ) ;
if ( F_159 ( V_7 ) ) {
V_327:
F_118 ( V_124 , V_312 ) ;
V_325:
F_118 ( V_124 , V_313 ) ;
} else {
F_119 ( NULL , V_7 ) ;
}
V_323:
F_76 ( V_7 ) ;
return 0 ;
V_331:
F_66 ( V_3 ) ;
goto V_323;
V_330:
if ( ! F_175 ( NULL , V_332 , V_7 ) ) {
F_50 ( F_51 ( V_3 ) ) ;
goto V_323;
}
F_164 ( V_7 , V_121 , V_123 ) ;
if ( F_159 ( V_7 ) ) {
F_50 ( F_51 ( V_3 ) ) ;
goto V_327;
}
switch ( F_183 ( F_51 ( V_3 ) , V_7 , V_123 ) ) {
case V_338 :
{
struct V_2 * V_339 ;
V_339 = F_121 ( F_45 ( V_7 -> V_125 ) , & V_130 ,
& F_10 ( V_7 ) -> V_18 , V_123 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_47 ( V_123 -> V_19 ) , F_102 ( V_7 ) ) ;
if ( V_339 ) {
struct V_259 * V_260 = F_51 ( V_3 ) ;
F_184 ( V_260 ) ;
F_50 ( V_260 ) ;
V_3 = V_339 ;
F_169 ( V_7 ) ;
goto V_329;
}
}
case V_340 :
F_125 ( V_3 , V_7 ) ;
break;
case V_341 :
F_169 ( V_7 ) ;
goto V_328;
case V_342 :
;
}
goto V_323;
}
static void F_185 ( struct V_6 * V_7 )
{
const struct V_105 * V_121 ;
const struct V_104 * V_123 ;
struct V_2 * V_3 ;
if ( V_7 -> V_321 != V_322 )
return;
if ( ! F_171 ( V_7 , F_186 ( V_7 ) + sizeof( struct V_104 ) ) )
return;
V_121 = F_10 ( V_7 ) ;
V_123 = F_11 ( V_7 ) ;
if ( V_123 -> V_204 < sizeof( struct V_104 ) / 4 )
return;
V_3 = F_46 ( F_45 ( V_7 -> V_125 ) , & V_130 ,
& V_121 -> V_18 , V_123 -> V_20 ,
& V_121 -> V_16 , F_47 ( V_123 -> V_19 ) ,
F_174 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_343 = V_344 ;
if ( F_187 ( V_3 ) ) {
struct V_8 * V_9 = F_188 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_189 ( V_9 , F_6 ( V_3 ) -> V_15 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_190 ( V_7 , V_9 ) ;
}
}
}
static int F_191 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_13 ( V_3 ) ;
F_192 ( V_3 ) ;
V_29 -> V_74 = & V_80 ;
#ifdef F_23
F_14 ( V_3 ) -> V_78 = & V_82 ;
#endif
return 0 ;
}
static void F_193 ( struct V_2 * V_3 )
{
F_194 ( V_3 ) ;
F_195 ( V_3 ) ;
}
static void F_196 ( struct V_345 * V_128 ,
struct V_126 * V_159 , int V_346 , T_8 V_347 )
{
long V_348 = V_159 -> V_349 . V_350 - V_351 ;
const struct V_4 * V_352 = & F_68 ( V_159 ) -> V_169 ;
const struct V_4 * V_19 = & F_68 ( V_159 ) -> V_170 ;
if ( V_348 < 0 )
V_348 = 0 ;
F_197 ( V_128 ,
L_5
L_6 ,
V_346 ,
V_352 -> V_17 [ 0 ] , V_352 -> V_17 [ 1 ] ,
V_352 -> V_17 [ 2 ] , V_352 -> V_17 [ 3 ] ,
F_68 ( V_159 ) -> V_353 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_47 ( F_68 ( V_159 ) -> V_354 ) ,
V_152 ,
0 , 0 ,
1 ,
F_198 ( V_348 ) ,
V_159 -> V_355 ,
F_199 ( F_200 ( V_128 ) , V_347 ) ,
0 ,
0 ,
0 , V_159 ) ;
}
static void F_201 ( struct V_345 * V_128 , struct V_2 * V_356 , int V_346 )
{
const struct V_4 * V_19 , * V_352 ;
T_9 V_357 , V_358 ;
int V_359 ;
unsigned long V_360 ;
const struct V_26 * V_27 = F_5 ( V_356 ) ;
const struct V_32 * V_33 = F_14 ( V_356 ) ;
const struct V_28 * V_29 = F_13 ( V_356 ) ;
struct V_361 * V_362 = V_29 -> V_363 . V_362 ;
V_19 = & V_356 -> V_60 ;
V_352 = & V_356 -> V_84 ;
V_357 = F_47 ( V_27 -> V_106 ) ;
V_358 = F_47 ( V_27 -> V_92 ) ;
if ( V_29 -> V_364 == V_365 ) {
V_359 = 1 ;
V_360 = V_29 -> V_366 ;
} else if ( V_29 -> V_364 == V_367 ) {
V_359 = 4 ;
V_360 = V_29 -> V_366 ;
} else if ( F_202 ( & V_356 -> V_368 ) ) {
V_359 = 2 ;
V_360 = V_356 -> V_368 . V_350 ;
} else {
V_359 = 0 ;
V_360 = V_351 ;
}
F_197 ( V_128 ,
L_5
L_7 ,
V_346 ,
V_352 -> V_17 [ 0 ] , V_352 -> V_17 [ 1 ] ,
V_352 -> V_17 [ 2 ] , V_352 -> V_17 [ 3 ] , V_358 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_357 ,
V_356 -> V_112 ,
V_33 -> V_62 - V_33 -> V_129 ,
( V_356 -> V_112 == V_143 ) ? V_356 -> V_369 : ( V_33 -> V_273 - V_33 -> V_370 ) ,
V_359 ,
F_203 ( V_360 - V_351 ) ,
V_29 -> V_371 ,
F_199 ( F_200 ( V_128 ) , F_204 ( V_356 ) ) ,
V_29 -> V_372 ,
F_205 ( V_356 ) ,
F_206 ( & V_356 -> V_373 ) , V_356 ,
F_198 ( V_29 -> V_374 ) ,
F_198 ( V_29 -> V_375 . V_376 ) ,
( V_29 -> V_375 . V_377 << 1 ) | V_29 -> V_375 . V_378 ,
V_33 -> V_379 ,
V_356 -> V_112 == V_143 ?
( V_362 ? V_362 -> V_380 : 0 ) :
( F_207 ( V_33 ) ? - 1 : V_33 -> V_381 )
) ;
}
static void F_208 ( struct V_345 * V_128 ,
struct V_259 * V_260 , int V_346 )
{
long V_382 = V_260 -> V_383 . V_350 - V_351 ;
const struct V_4 * V_19 , * V_352 ;
T_9 V_357 , V_358 ;
V_19 = & V_260 -> V_384 ;
V_352 = & V_260 -> V_385 ;
V_357 = F_47 ( V_260 -> V_386 ) ;
V_358 = F_47 ( V_260 -> V_387 ) ;
F_197 ( V_128 ,
L_5
L_8 ,
V_346 ,
V_352 -> V_17 [ 0 ] , V_352 -> V_17 [ 1 ] ,
V_352 -> V_17 [ 2 ] , V_352 -> V_17 [ 3 ] , V_358 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_357 ,
V_260 -> V_388 , 0 , 0 ,
3 , F_203 ( V_382 ) , 0 , 0 , 0 , 0 ,
F_206 ( & V_260 -> V_389 ) , V_260 ) ;
}
static int F_209 ( struct V_345 * V_128 , void * V_390 )
{
struct V_391 * V_392 ;
struct V_2 * V_3 = V_390 ;
if ( V_390 == V_393 ) {
F_210 ( V_128 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_137;
}
V_392 = V_128 -> V_394 ;
switch ( V_392 -> V_395 ) {
case V_396 :
case V_397 :
if ( V_3 -> V_112 == V_133 )
F_208 ( V_128 , V_390 , V_392 -> V_398 ) ;
else
F_201 ( V_128 , V_390 , V_392 -> V_398 ) ;
break;
case V_399 :
F_196 ( V_128 , V_390 , V_392 -> V_398 , V_392 -> V_347 ) ;
break;
}
V_137:
return 0 ;
}
int T_10 F_211 ( struct V_124 * V_124 )
{
return F_212 ( V_124 , & V_400 ) ;
}
void F_213 ( struct V_124 * V_124 )
{
F_214 ( V_124 , & V_400 ) ;
}
static void F_215 ( struct V_2 * V_3 , int V_401 )
{
struct V_26 * V_27 = F_5 ( V_3 ) ;
F_216 ( V_3 , F_217 ( struct V_26 , V_287 ) ) ;
V_401 -= F_217 ( struct V_26 , V_287 ) + sizeof( V_27 -> V_287 ) ;
memset ( & V_27 -> V_287 + 1 , 0 , V_401 ) ;
}
static int T_10 F_218 ( struct V_124 * V_124 )
{
return F_219 ( & V_124 -> V_234 . F_14 , V_402 ,
V_403 , V_86 , V_124 ) ;
}
static void T_11 F_220 ( struct V_124 * V_124 )
{
F_221 ( V_124 -> V_234 . F_14 ) ;
}
static void T_11 F_222 ( struct V_404 * V_405 )
{
F_223 ( & V_130 , & V_98 , V_43 ) ;
}
int T_12 F_224 ( void )
{
int V_320 ;
V_320 = F_225 ( & V_406 , V_86 ) ;
if ( V_320 )
goto V_137;
V_320 = F_226 ( & V_407 ) ;
if ( V_320 )
goto V_408;
V_320 = F_227 ( & V_409 ) ;
if ( V_320 )
goto V_410;
V_137:
return V_320 ;
V_410:
F_228 ( & V_407 ) ;
V_408:
F_229 ( & V_406 , V_86 ) ;
goto V_137;
}
void F_230 ( void )
{
F_231 ( & V_409 ) ;
F_228 ( & V_407 ) ;
F_229 ( & V_406 , V_86 ) ;
}
