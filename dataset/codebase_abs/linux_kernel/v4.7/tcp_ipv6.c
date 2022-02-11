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
V_41 = F_75 ( V_3 , V_7 , V_39 , F_76 ( V_31 -> V_37 ) ,
V_31 -> V_176 ) ;
F_77 () ;
V_41 = F_78 ( V_41 ) ;
}
V_171:
return V_41 ;
}
static void F_79 ( struct V_127 * V_161 )
{
F_80 ( F_70 ( V_161 ) -> V_175 ) ;
}
static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_81 ( V_3 , (union V_177 * ) V_5 , V_45 ) ;
}
static struct V_1 * F_82 ( const struct V_2 * V_3 ,
const struct V_2 * V_178 )
{
return F_1 ( V_3 , & V_178 -> V_62 ) ;
}
static int F_83 ( struct V_2 * V_3 , char T_5 * V_179 ,
int V_180 )
{
struct V_181 V_182 ;
struct V_24 * V_183 = (struct V_24 * ) & V_182 . V_184 ;
if ( V_180 < sizeof( V_182 ) )
return - V_43 ;
if ( F_84 ( & V_182 , V_179 , sizeof( V_182 ) ) )
return - V_185 ;
if ( V_183 -> V_44 != V_45 )
return - V_43 ;
if ( ! V_182 . V_186 ) {
if ( F_85 ( & V_183 -> V_53 ) )
return F_86 ( V_3 , (union V_177 * ) & V_183 -> V_53 . V_17 [ 3 ] ,
V_71 ) ;
return F_86 ( V_3 , (union V_177 * ) & V_183 -> V_53 ,
V_45 ) ;
}
if ( V_182 . V_186 > V_187 )
return - V_43 ;
if ( F_85 ( & V_183 -> V_53 ) )
return F_87 ( V_3 , (union V_177 * ) & V_183 -> V_53 . V_17 [ 3 ] ,
V_71 , V_182 . V_188 , V_182 . V_186 , V_189 ) ;
return F_87 ( V_3 , (union V_177 * ) & V_183 -> V_53 ,
V_45 , V_182 . V_188 , V_182 . V_186 , V_189 ) ;
}
static int F_88 ( struct V_190 * V_191 ,
const struct V_4 * V_16 ,
const struct V_4 * V_18 , int V_192 )
{
struct V_193 * V_194 ;
struct V_195 V_196 ;
V_194 = & V_191 -> V_197 . V_169 ;
V_194 -> V_18 = * V_18 ;
V_194 -> V_16 = * V_16 ;
V_194 -> V_198 = F_89 ( V_88 ) ;
V_194 -> V_199 = F_89 ( V_192 ) ;
F_90 ( & V_196 , V_194 , sizeof( * V_194 ) ) ;
F_91 ( V_191 -> V_200 , & V_196 , NULL , sizeof( * V_194 ) ) ;
return F_92 ( V_191 -> V_200 ) ;
}
static int F_93 ( char * V_201 , struct V_1 * V_202 ,
const struct V_4 * V_16 , struct V_4 * V_18 ,
const struct V_105 * V_124 )
{
struct V_190 * V_191 ;
struct V_203 * V_161 ;
V_191 = F_94 () ;
if ( ! V_191 )
goto V_204;
V_161 = V_191 -> V_200 ;
if ( F_95 ( V_161 ) )
goto V_205;
if ( F_88 ( V_191 , V_16 , V_18 , V_124 -> V_206 << 2 ) )
goto V_205;
if ( F_96 ( V_191 , V_124 ) )
goto V_205;
if ( F_97 ( V_191 , V_202 ) )
goto V_205;
F_91 ( V_161 , NULL , V_201 , 0 ) ;
if ( F_98 ( V_161 ) )
goto V_205;
F_99 () ;
return 0 ;
V_205:
F_99 () ;
V_204:
memset ( V_201 , 0 , 16 ) ;
return 1 ;
}
static int F_100 ( char * V_201 ,
const struct V_1 * V_202 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_18 , * V_16 ;
struct V_190 * V_191 ;
struct V_203 * V_161 ;
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( V_3 ) {
V_18 = & V_3 -> V_86 ;
V_16 = & V_3 -> V_62 ;
} else {
const struct V_106 * V_207 = F_10 ( V_7 ) ;
V_18 = & V_207 -> V_18 ;
V_16 = & V_207 -> V_16 ;
}
V_191 = F_94 () ;
if ( ! V_191 )
goto V_204;
V_161 = V_191 -> V_200 ;
if ( F_95 ( V_161 ) )
goto V_205;
if ( F_88 ( V_191 , V_16 , V_18 , V_7 -> V_199 ) )
goto V_205;
if ( F_96 ( V_191 , V_124 ) )
goto V_205;
if ( F_101 ( V_191 , V_7 , V_124 -> V_206 << 2 ) )
goto V_205;
if ( F_97 ( V_191 , V_202 ) )
goto V_205;
F_91 ( V_161 , NULL , V_201 , 0 ) ;
if ( F_98 ( V_161 ) )
goto V_205;
F_99 () ;
return 0 ;
V_205:
F_99 () ;
V_204:
memset ( V_201 , 0 , 16 ) ;
return 1 ;
}
static bool F_102 ( const struct V_2 * V_3 ,
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
V_208 = F_103 ( V_124 ) ;
if ( ! V_209 && ! V_208 )
return false ;
if ( V_209 && ! V_208 ) {
F_104 ( F_105 ( V_3 ) , V_212 ) ;
return true ;
}
if ( ! V_209 && V_208 ) {
F_104 ( F_105 ( V_3 ) , V_213 ) ;
return true ;
}
V_210 = F_100 ( V_211 ,
V_209 ,
NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 ) {
F_106 ( L_2 ,
V_210 ? L_3 : L_4 ,
& V_207 -> V_18 , F_49 ( V_124 -> V_20 ) ,
& V_207 -> V_16 , F_49 ( V_124 -> V_19 ) ) ;
return true ;
}
#endif
return false ;
}
static void F_107 ( struct V_127 * V_161 ,
const struct V_2 * V_214 ,
struct V_6 * V_7 )
{
struct V_166 * V_167 = F_70 ( V_161 ) ;
const struct V_30 * V_31 = F_6 ( V_214 ) ;
V_167 -> V_173 = F_10 ( V_7 ) -> V_18 ;
V_167 -> V_172 = F_10 ( V_7 ) -> V_16 ;
if ( ! V_214 -> V_59 &&
F_19 ( & V_167 -> V_173 ) & V_57 )
V_167 -> V_215 = F_108 ( V_7 ) ;
if ( ! F_109 ( V_7 ) -> V_216 &&
( F_110 ( V_214 , V_7 , & F_109 ( V_7 ) -> V_217 . V_218 ) ||
V_31 -> V_219 . V_220 . V_221 ||
V_31 -> V_219 . V_220 . V_222 || V_31 -> V_219 . V_220 . V_223 ||
V_31 -> V_219 . V_220 . V_224 || V_31 -> V_174 ) ) {
F_111 ( & V_7 -> V_225 ) ;
V_167 -> V_175 = V_7 ;
}
}
static struct V_8 * F_112 ( const struct V_2 * V_3 ,
struct V_159 * V_160 ,
const struct V_127 * V_161 ,
bool * V_226 )
{
if ( V_226 )
* V_226 = true ;
return F_71 ( V_3 , & V_160 -> V_168 . V_169 , V_161 , V_88 ) ;
}
static void F_113 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_227 , T_2 V_228 , T_2 V_229 , T_2 V_230 ,
int V_231 , struct V_1 * V_202 , int V_232 ,
T_3 V_176 , T_4 V_233 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
struct V_105 * V_234 ;
struct V_6 * V_235 ;
struct V_38 V_39 ;
struct V_125 * V_125 = V_3 ? F_105 ( V_3 ) : F_47 ( F_3 ( V_7 ) -> V_126 ) ;
struct V_2 * V_236 = V_125 -> V_237 . F_14 ;
unsigned int V_238 = sizeof( struct V_105 ) ;
struct V_8 * V_9 ;
T_4 * V_239 ;
if ( V_230 )
V_238 += V_240 ;
#ifdef F_23
if ( V_202 )
V_238 += V_241 ;
#endif
V_235 = F_114 ( V_242 + sizeof( struct V_106 ) + V_238 ,
V_243 ) ;
if ( ! V_235 )
return;
F_115 ( V_235 , V_242 + sizeof( struct V_106 ) + V_238 ) ;
V_234 = (struct V_105 * ) F_116 ( V_235 , V_238 ) ;
F_117 ( V_235 ) ;
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
V_234 -> V_19 = V_124 -> V_20 ;
V_234 -> V_20 = V_124 -> V_19 ;
V_234 -> V_206 = V_238 / 4 ;
V_234 -> V_129 = F_118 ( V_129 ) ;
V_234 -> V_244 = F_118 ( V_227 ) ;
V_234 -> V_227 = ! V_232 || ! V_124 -> V_227 ;
V_234 -> V_232 = V_232 ;
V_234 -> V_245 = F_119 ( V_228 ) ;
V_239 = ( T_4 * ) ( V_234 + 1 ) ;
if ( V_230 ) {
* V_239 ++ = F_118 ( ( V_246 << 24 ) | ( V_246 << 16 ) |
( V_247 << 8 ) | V_248 ) ;
* V_239 ++ = F_118 ( V_229 ) ;
* V_239 ++ = F_118 ( V_230 ) ;
}
#ifdef F_23
if ( V_202 ) {
* V_239 ++ = F_118 ( ( V_246 << 24 ) | ( V_246 << 16 ) |
( V_249 << 8 ) | V_250 ) ;
F_93 ( ( T_6 * ) V_239 , V_202 ,
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
F_73 ( V_235 , & V_39 . V_18 , & V_39 . V_16 ) ;
V_39 . V_87 = V_88 ;
if ( F_120 ( & V_39 . V_16 ) && ! V_231 )
V_39 . V_89 = F_108 ( V_7 ) ;
else {
if ( ! V_231 && F_121 ( V_125 , V_7 -> V_14 ) )
V_231 = V_7 -> V_14 ;
V_39 . V_89 = V_231 ;
}
V_39 . V_90 = F_122 ( V_125 , V_7 -> V_254 ) ;
V_39 . V_92 = V_234 -> V_19 ;
V_39 . V_93 = V_234 -> V_20 ;
F_123 ( V_7 , F_29 ( & V_39 ) ) ;
V_9 = F_30 ( V_236 , & V_39 , NULL ) ;
if ( ! F_31 ( V_9 ) ) {
F_124 ( V_235 , V_9 ) ;
F_75 ( V_236 , V_235 , & V_39 , NULL , V_176 ) ;
F_125 ( V_125 , V_255 ) ;
if ( V_232 )
F_125 ( V_125 , V_256 ) ;
return;
}
F_80 ( V_235 ) ;
}
static void F_126 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_105 * V_124 = F_11 ( V_7 ) ;
T_2 V_129 = 0 , V_244 = 0 ;
struct V_1 * V_202 = NULL ;
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
if ( ! V_3 && ! F_127 ( V_7 ) )
return;
#ifdef F_23
F_74 () ;
V_208 = F_103 ( V_124 ) ;
if ( V_3 && F_128 ( V_3 ) ) {
V_202 = F_1 ( V_3 , & V_257 -> V_18 ) ;
} else if ( V_208 ) {
V_258 = F_129 ( F_47 ( F_3 ( V_7 ) -> V_126 ) ,
& V_132 , NULL , 0 ,
& V_257 -> V_18 ,
V_124 -> V_20 , & V_257 -> V_16 ,
F_49 ( V_124 -> V_20 ) , F_108 ( V_7 ) ) ;
if ( ! V_258 )
goto V_139;
V_202 = F_1 ( V_258 , & V_257 -> V_18 ) ;
if ( ! V_202 )
goto V_139;
V_210 = F_100 ( V_211 , V_202 , NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 )
goto V_139;
}
#endif
if ( V_124 -> V_227 )
V_129 = F_54 ( V_124 -> V_244 ) ;
else
V_244 = F_54 ( V_124 -> V_129 ) + V_124 -> V_259 + V_124 -> V_260 + V_7 -> V_199 -
( V_124 -> V_206 << 2 ) ;
V_231 = V_3 ? V_3 -> V_59 : 0 ;
F_113 ( V_3 , V_7 , V_129 , V_244 , 0 , 0 , 0 , V_231 , V_202 , 1 , 0 , 0 ) ;
#ifdef F_23
V_139:
F_77 () ;
#endif
}
static void F_130 ( const struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_129 ,
T_2 V_227 , T_2 V_228 , T_2 V_229 , T_2 V_230 , int V_231 ,
struct V_1 * V_202 , T_3 V_176 ,
T_4 V_233 )
{
F_113 ( V_3 , V_7 , V_129 , V_227 , V_228 , V_229 , V_230 , V_231 , V_202 , 0 ,
V_176 , V_233 ) ;
}
static void F_131 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_261 * V_262 = F_53 ( V_3 ) ;
struct V_263 * V_264 = F_132 ( V_3 ) ;
F_130 ( V_3 , V_7 , V_264 -> V_265 , V_264 -> V_266 ,
V_264 -> V_267 >> V_262 -> V_268 ,
V_269 + V_264 -> V_270 ,
V_264 -> V_271 , V_262 -> V_272 , F_133 ( V_264 ) ,
V_262 -> V_273 , F_89 ( V_262 -> V_274 ) ) ;
F_52 ( V_262 ) ;
}
static void F_134 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 )
{
F_130 ( V_3 , V_7 , ( V_3 -> V_113 == V_145 ) ?
F_60 ( V_161 ) -> V_144 + 1 : F_14 ( V_3 ) -> V_146 ,
F_60 ( V_161 ) -> V_275 , V_161 -> V_276 ,
V_269 , V_161 -> V_63 , V_3 -> V_59 ,
F_1 ( V_3 , & F_10 ( V_7 ) -> V_16 ) ,
0 , 0 ) ;
}
static struct V_2 * F_135 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
#ifdef F_136
const struct V_105 * V_124 = F_11 ( V_7 ) ;
if ( ! V_124 -> V_259 )
V_3 = F_137 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_138 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_198 == F_119 ( V_277 ) )
return F_139 ( V_3 , V_7 ) ;
if ( ! F_127 ( V_7 ) )
goto V_278;
return F_140 ( & V_279 ,
& V_280 , V_3 , V_7 ) ;
V_278:
F_141 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_142 ( const struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_127 * V_161 ,
struct V_8 * V_9 ,
struct V_127 * V_281 ,
bool * V_282 )
{
struct V_166 * V_167 ;
struct V_30 * V_283 ;
const struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_284 * V_285 ;
struct V_26 * V_286 ;
struct V_32 * V_287 ;
struct V_2 * V_288 ;
#ifdef F_23
struct V_1 * V_202 ;
#endif
struct V_38 V_39 ;
if ( V_7 -> V_198 == F_119 ( V_277 ) ) {
V_288 = F_143 ( V_3 , V_7 , V_161 , V_9 ,
V_281 , V_282 ) ;
if ( ! V_288 )
return NULL ;
V_285 = (struct V_284 * ) V_288 ;
F_5 ( V_288 ) -> V_289 = & V_285 -> V_290 ;
V_286 = F_5 ( V_288 ) ;
V_283 = F_6 ( V_288 ) ;
V_287 = F_14 ( V_288 ) ;
memcpy ( V_283 , V_31 , sizeof( struct V_30 ) ) ;
V_283 -> V_18 = V_288 -> V_86 ;
F_13 ( V_288 ) -> V_76 = & V_77 ;
V_288 -> V_78 = V_79 ;
#ifdef F_23
V_287 -> V_80 = & V_81 ;
#endif
V_283 -> V_291 = NULL ;
V_283 -> V_292 = NULL ;
V_283 -> V_293 = NULL ;
V_283 -> V_37 = NULL ;
V_283 -> V_294 = F_108 ( V_7 ) ;
V_283 -> V_295 = F_10 ( V_7 ) -> V_140 ;
V_283 -> V_296 = F_144 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_174 )
V_283 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
F_44 ( V_288 , F_13 ( V_288 ) -> V_117 ) ;
return V_288 ;
}
V_167 = F_70 ( V_161 ) ;
if ( F_145 ( V_3 ) )
goto V_297;
if ( ! V_9 ) {
V_9 = F_71 ( V_3 , & V_39 , V_161 , V_88 ) ;
if ( ! V_9 )
goto V_139;
}
V_288 = F_146 ( V_3 , V_161 , V_7 ) ;
if ( ! V_288 )
goto V_298;
V_288 -> V_97 = V_98 ;
F_33 ( V_288 , V_9 , NULL , NULL ) ;
F_2 ( V_288 , V_7 ) ;
V_285 = (struct V_284 * ) V_288 ;
F_5 ( V_288 ) -> V_289 = & V_285 -> V_290 ;
V_287 = F_14 ( V_288 ) ;
V_286 = F_5 ( V_288 ) ;
V_283 = F_6 ( V_288 ) ;
memcpy ( V_283 , V_31 , sizeof( struct V_30 ) ) ;
V_288 -> V_62 = V_167 -> V_173 ;
V_283 -> V_18 = V_167 -> V_172 ;
V_288 -> V_86 = V_167 -> V_172 ;
V_288 -> V_59 = V_167 -> V_215 ;
V_286 -> V_299 = NULL ;
V_283 -> V_291 = NULL ;
V_283 -> V_292 = NULL ;
V_283 -> V_219 . V_300 = V_31 -> V_219 . V_300 ;
V_283 -> V_293 = NULL ;
V_283 -> V_37 = NULL ;
V_283 -> V_294 = F_108 ( V_7 ) ;
V_283 -> V_295 = F_10 ( V_7 ) -> V_140 ;
V_283 -> V_296 = F_144 ( F_10 ( V_7 ) ) ;
if ( V_31 -> V_174 )
V_283 -> V_65 = V_52 ( F_10 ( V_7 ) ) ;
V_37 = F_76 ( V_31 -> V_37 ) ;
if ( V_37 ) {
V_37 = F_147 ( V_288 , V_37 ) ;
F_148 ( V_283 -> V_37 , V_37 ) ;
}
F_13 ( V_288 ) -> V_68 = 0 ;
if ( V_37 )
F_13 ( V_288 ) -> V_68 = V_37 -> V_102 +
V_37 -> V_101 ;
F_149 ( V_288 , V_9 ) ;
F_44 ( V_288 , F_43 ( V_9 ) ) ;
V_287 -> V_301 = F_150 ( V_9 ) ;
if ( F_14 ( V_3 ) -> V_60 . V_302 &&
F_14 ( V_3 ) -> V_60 . V_302 < V_287 -> V_301 )
V_287 -> V_301 = F_14 ( V_3 ) -> V_60 . V_302 ;
F_151 ( V_288 ) ;
V_286 -> V_303 = V_286 -> V_304 = V_96 ;
V_286 -> V_95 = V_96 ;
#ifdef F_23
V_202 = F_1 ( V_3 , & V_288 -> V_62 ) ;
if ( V_202 ) {
F_87 ( V_288 , (union V_177 * ) & V_288 -> V_62 ,
V_45 , V_202 -> V_202 , V_202 -> V_305 ,
F_152 ( V_3 , V_243 ) ) ;
}
#endif
if ( F_153 ( V_3 , V_288 ) < 0 ) {
F_154 ( V_288 ) ;
F_66 ( V_288 ) ;
goto V_139;
}
* V_282 = F_155 ( V_288 , F_156 ( V_281 ) ) ;
if ( * V_282 ) {
F_157 ( V_287 , V_161 ) ;
if ( V_167 -> V_175 ) {
V_283 -> V_293 = F_158 ( V_167 -> V_175 ,
F_152 ( V_3 , V_243 ) ) ;
F_159 ( V_167 -> V_175 ) ;
V_167 -> V_175 = NULL ;
if ( V_283 -> V_293 )
F_160 ( V_283 -> V_293 , V_288 ) ;
}
}
return V_288 ;
V_297:
F_59 ( F_105 ( V_3 ) , V_306 ) ;
V_298:
F_161 ( V_9 ) ;
V_139:
F_141 ( V_3 ) ;
return NULL ;
}
static int V_83 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_30 * V_31 = F_6 ( V_3 ) ;
struct V_32 * V_33 ;
struct V_6 * V_307 = NULL ;
if ( V_7 -> V_198 == F_119 ( V_277 ) )
return V_79 ( V_3 , V_7 ) ;
if ( F_162 ( V_3 , V_7 ) )
goto V_308;
if ( V_31 -> V_219 . V_300 )
V_307 = F_158 ( V_7 , F_152 ( V_3 , V_243 ) ) ;
if ( V_3 -> V_113 == V_309 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_163 ( V_3 , V_7 ) ;
F_164 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_150 -> V_310 ( V_9 , V_31 -> V_15 ) == NULL ) {
F_161 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_165 ( V_3 , V_7 , F_11 ( V_7 ) , V_7 -> V_199 ) ;
if ( V_307 )
goto V_311;
return 0 ;
}
if ( F_166 ( V_7 ) )
goto V_312;
if ( V_3 -> V_113 == V_145 ) {
struct V_2 * V_313 = F_135 ( V_3 , V_7 ) ;
if ( ! V_313 )
goto V_308;
if ( V_313 != V_3 ) {
F_163 ( V_313 , V_7 ) ;
F_164 ( V_313 , V_7 ) ;
if ( F_167 ( V_3 , V_313 , V_7 ) )
goto V_314;
if ( V_307 )
F_168 ( V_307 ) ;
return 0 ;
}
} else
F_163 ( V_3 , V_7 ) ;
if ( F_169 ( V_3 , V_7 ) )
goto V_314;
if ( V_307 )
goto V_311;
return 0 ;
V_314:
F_126 ( V_3 , V_7 ) ;
V_308:
if ( V_307 )
F_168 ( V_307 ) ;
F_80 ( V_7 ) ;
return 0 ;
V_312:
F_125 ( F_105 ( V_3 ) , V_315 ) ;
F_125 ( F_105 ( V_3 ) , V_316 ) ;
goto V_308;
V_311:
V_33 = F_14 ( V_3 ) ;
if ( F_109 ( V_307 ) -> V_317 == V_33 -> V_275 &&
! ( ( 1 << V_3 -> V_113 ) & ( V_115 | V_114 ) ) ) {
if ( V_31 -> V_219 . V_220 . V_221 || V_31 -> V_219 . V_220 . V_222 )
V_31 -> V_294 = F_108 ( V_307 ) ;
if ( V_31 -> V_219 . V_220 . V_223 || V_31 -> V_219 . V_220 . V_224 )
V_31 -> V_295 = F_10 ( V_307 ) -> V_140 ;
if ( V_31 -> V_219 . V_220 . V_318 || V_31 -> V_219 . V_220 . V_319 )
V_31 -> V_296 = F_144 ( F_10 ( V_307 ) ) ;
if ( V_31 -> V_174 )
V_31 -> V_65 = V_52 ( F_10 ( V_307 ) ) ;
if ( F_110 ( V_3 , V_307 , & F_109 ( V_307 ) -> V_217 . V_218 ) ) {
F_160 ( V_307 , V_3 ) ;
V_307 = F_170 ( & V_31 -> V_293 , V_307 ) ;
} else {
F_168 ( V_307 ) ;
V_307 = F_170 ( & V_31 -> V_293 , NULL ) ;
}
}
F_80 ( V_307 ) ;
return 0 ;
}
static void F_171 ( struct V_6 * V_7 , const struct V_106 * V_122 ,
const struct V_105 * V_124 )
{
memmove ( & F_109 ( V_7 ) -> V_217 . V_218 , F_172 ( V_7 ) ,
sizeof( struct V_118 ) ) ;
F_173 () ;
F_109 ( V_7 ) -> V_129 = F_54 ( V_124 -> V_129 ) ;
F_109 ( V_7 ) -> V_317 = ( F_109 ( V_7 ) -> V_129 + V_124 -> V_259 + V_124 -> V_260 +
V_7 -> V_199 - V_124 -> V_206 * 4 ) ;
F_109 ( V_7 ) -> V_244 = F_54 ( V_124 -> V_244 ) ;
F_109 ( V_7 ) -> V_320 = F_174 ( V_124 ) ;
F_109 ( V_7 ) -> V_216 = 0 ;
F_109 ( V_7 ) -> V_321 = F_175 ( V_122 ) ;
F_109 ( V_7 ) -> V_322 = 0 ;
}
static void F_176 ( struct V_6 * V_7 )
{
memmove ( F_172 ( V_7 ) , & F_109 ( V_7 ) -> V_217 . V_218 ,
sizeof( struct V_118 ) ) ;
}
static int F_177 ( struct V_6 * V_7 )
{
const struct V_105 * V_124 ;
const struct V_106 * V_122 ;
bool V_323 ;
struct V_2 * V_3 ;
int V_324 ;
struct V_125 * V_125 = F_47 ( V_7 -> V_126 ) ;
if ( V_7 -> V_325 != V_326 )
goto V_327;
F_178 ( V_125 , V_328 ) ;
if ( ! F_179 ( V_7 , sizeof( struct V_105 ) ) )
goto V_327;
V_124 = ( const struct V_105 * ) V_7 -> V_123 ;
if ( F_180 ( V_124 -> V_206 < sizeof( struct V_105 ) / 4 ) )
goto V_329;
if ( ! F_179 ( V_7 , V_124 -> V_206 * 4 ) )
goto V_327;
if ( F_181 ( V_7 , V_88 , V_330 ) )
goto V_331;
V_124 = ( const struct V_105 * ) V_7 -> V_123 ;
V_122 = F_10 ( V_7 ) ;
V_332:
V_3 = F_182 ( & V_132 , V_7 , F_183 ( V_124 ) ,
V_124 -> V_20 , V_124 -> V_19 , F_184 ( V_7 ) ,
& V_323 ) ;
if ( ! V_3 )
goto V_333;
V_334:
if ( V_3 -> V_113 == V_135 )
goto V_335;
if ( V_3 -> V_113 == V_136 ) {
struct V_127 * V_161 = F_185 ( V_3 ) ;
struct V_2 * V_313 ;
V_3 = V_161 -> V_336 ;
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_102 ( V_3 , V_7 ) ) {
F_186 ( V_161 ) ;
goto V_327;
}
if ( F_180 ( V_3 -> V_113 != V_145 ) ) {
F_187 ( V_3 , V_161 ) ;
goto V_332;
}
F_65 ( V_3 ) ;
V_323 = true ;
V_313 = F_188 ( V_3 , V_7 , V_161 , false ) ;
if ( ! V_313 ) {
F_186 ( V_161 ) ;
goto V_337;
}
if ( V_313 == V_3 ) {
F_186 ( V_161 ) ;
F_176 ( V_7 ) ;
} else if ( F_167 ( V_3 , V_313 , V_7 ) ) {
F_126 ( V_313 , V_7 ) ;
goto V_337;
} else {
F_68 ( V_3 ) ;
return 0 ;
}
}
if ( V_122 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_59 ( V_125 , V_142 ) ;
goto V_337;
}
if ( ! F_189 ( V_3 , V_338 , V_7 ) )
goto V_337;
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_102 ( V_3 , V_7 ) )
goto V_337;
if ( F_162 ( V_3 , V_7 ) )
goto V_337;
V_7 -> V_126 = NULL ;
if ( V_3 -> V_113 == V_145 ) {
V_324 = V_83 ( V_3 , V_7 ) ;
goto V_339;
}
F_190 ( V_3 ) ;
F_191 ( V_3 ) ;
F_192 ( F_14 ( V_3 ) , V_7 ) ;
V_324 = 0 ;
if ( ! F_58 ( V_3 ) ) {
if ( ! F_193 ( V_3 , V_7 ) )
V_324 = V_83 ( V_3 , V_7 ) ;
} else if ( F_180 ( F_194 ( V_3 , V_7 ,
V_3 -> V_340 + V_3 -> V_341 ) ) ) {
F_67 ( V_3 ) ;
F_59 ( V_125 , V_342 ) ;
goto V_337;
}
F_67 ( V_3 ) ;
V_339:
if ( V_323 )
F_68 ( V_3 ) ;
return V_324 ? - 1 : 0 ;
V_333:
if ( ! F_189 ( NULL , V_338 , V_7 ) )
goto V_327;
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_166 ( V_7 ) ) {
V_331:
F_178 ( V_125 , V_315 ) ;
V_329:
F_178 ( V_125 , V_316 ) ;
} else {
F_126 ( NULL , V_7 ) ;
}
V_327:
F_80 ( V_7 ) ;
return 0 ;
V_337:
F_195 ( V_3 , V_7 ) ;
if ( V_323 )
F_68 ( V_3 ) ;
goto V_327;
V_335:
if ( ! F_189 ( NULL , V_338 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_327;
}
F_171 ( V_7 , V_122 , V_124 ) ;
if ( F_166 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_331;
}
switch ( F_196 ( F_53 ( V_3 ) , V_7 , V_124 ) ) {
case V_343 :
{
struct V_2 * V_344 ;
V_344 = F_129 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
V_7 , F_183 ( V_124 ) ,
& F_10 ( V_7 ) -> V_18 , V_124 -> V_20 ,
& F_10 ( V_7 ) -> V_16 ,
F_49 ( V_124 -> V_19 ) , F_108 ( V_7 ) ) ;
if ( V_344 ) {
struct V_261 * V_262 = F_53 ( V_3 ) ;
F_197 ( V_262 ) ;
V_3 = V_344 ;
F_176 ( V_7 ) ;
V_323 = false ;
goto V_334;
}
}
case V_345 :
F_131 ( V_3 , V_7 ) ;
break;
case V_346 :
F_176 ( V_7 ) ;
F_126 ( V_3 , V_7 ) ;
F_197 ( F_53 ( V_3 ) ) ;
goto V_327;
case V_347 :
;
}
goto V_327;
}
static void F_198 ( struct V_6 * V_7 )
{
const struct V_106 * V_122 ;
const struct V_105 * V_124 ;
struct V_2 * V_3 ;
if ( V_7 -> V_325 != V_326 )
return;
if ( ! F_179 ( V_7 , F_199 ( V_7 ) + sizeof( struct V_105 ) ) )
return;
V_122 = F_10 ( V_7 ) ;
V_124 = F_11 ( V_7 ) ;
if ( V_124 -> V_206 < sizeof( struct V_105 ) / 4 )
return;
V_3 = F_48 ( F_47 ( V_7 -> V_126 ) , & V_132 ,
& V_122 -> V_18 , V_124 -> V_20 ,
& V_122 -> V_16 , F_49 ( V_124 -> V_19 ) ,
F_184 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_348 = V_349 ;
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
static void F_208 ( struct V_350 * V_129 ,
const struct V_127 * V_161 , int V_351 )
{
long V_352 = V_161 -> V_353 . V_354 - V_355 ;
const struct V_4 * V_356 = & F_70 ( V_161 ) -> V_172 ;
const struct V_4 * V_19 = & F_70 ( V_161 ) -> V_173 ;
if ( V_352 < 0 )
V_352 = 0 ;
F_209 ( V_129 ,
L_5
L_6 ,
V_351 ,
V_356 -> V_17 [ 0 ] , V_356 -> V_17 [ 1 ] ,
V_356 -> V_17 [ 2 ] , V_356 -> V_17 [ 3 ] ,
F_70 ( V_161 ) -> V_357 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] ,
F_49 ( F_70 ( V_161 ) -> V_358 ) ,
V_154 ,
0 , 0 ,
1 ,
F_210 ( V_352 ) ,
V_161 -> V_359 ,
F_211 ( F_212 ( V_129 ) ,
F_213 ( V_161 -> V_336 ) ) ,
0 ,
0 ,
0 , V_161 ) ;
}
static void F_214 ( struct V_350 * V_129 , struct V_2 * V_360 , int V_351 )
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
if ( V_29 -> V_370 == V_371 ||
V_29 -> V_370 == V_372 ||
V_29 -> V_370 == V_373 ) {
V_363 = 1 ;
V_364 = V_29 -> V_374 ;
} else if ( V_29 -> V_370 == V_375 ) {
V_363 = 4 ;
V_364 = V_29 -> V_374 ;
} else if ( F_215 ( & V_360 -> V_376 ) ) {
V_363 = 2 ;
V_364 = V_360 -> V_376 . V_354 ;
} else {
V_363 = 0 ;
V_364 = V_355 ;
}
V_369 = F_216 ( V_360 ) ;
if ( V_369 == V_145 )
V_368 = V_360 -> V_377 ;
else
V_368 = F_217 ( int , V_33 -> V_275 - V_33 -> V_378 , 0 ) ;
F_209 ( V_129 ,
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
F_218 ( V_364 - V_355 ) ,
V_29 -> V_379 ,
F_211 ( F_212 ( V_129 ) , F_213 ( V_360 ) ) ,
V_29 -> V_380 ,
F_219 ( V_360 ) ,
F_220 ( & V_360 -> V_381 ) , V_360 ,
F_210 ( V_29 -> V_382 ) ,
F_210 ( V_29 -> V_383 . V_384 ) ,
( V_29 -> V_383 . V_385 << 1 ) | V_29 -> V_383 . V_386 ,
V_33 -> V_387 ,
V_369 == V_145 ?
V_366 -> V_388 :
( F_221 ( V_33 ) ? - 1 : V_33 -> V_389 )
) ;
}
static void F_222 ( struct V_350 * V_129 ,
struct V_261 * V_262 , int V_351 )
{
long V_390 = V_262 -> V_391 . V_354 - V_355 ;
const struct V_4 * V_19 , * V_356 ;
T_7 V_361 , V_362 ;
V_19 = & V_262 -> V_392 ;
V_356 = & V_262 -> V_393 ;
V_361 = F_49 ( V_262 -> V_394 ) ;
V_362 = F_49 ( V_262 -> V_395 ) ;
F_209 ( V_129 ,
L_5
L_8 ,
V_351 ,
V_356 -> V_17 [ 0 ] , V_356 -> V_17 [ 1 ] ,
V_356 -> V_17 [ 2 ] , V_356 -> V_17 [ 3 ] , V_362 ,
V_19 -> V_17 [ 0 ] , V_19 -> V_17 [ 1 ] ,
V_19 -> V_17 [ 2 ] , V_19 -> V_17 [ 3 ] , V_361 ,
V_262 -> V_396 , 0 , 0 ,
3 , F_218 ( V_390 ) , 0 , 0 , 0 , 0 ,
F_220 ( & V_262 -> V_397 ) , V_262 ) ;
}
static int F_223 ( struct V_350 * V_129 , void * V_398 )
{
struct V_399 * V_400 ;
struct V_2 * V_3 = V_398 ;
if ( V_398 == V_401 ) {
F_224 ( V_129 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_139;
}
V_400 = V_129 -> V_402 ;
if ( V_3 -> V_113 == V_135 )
F_222 ( V_129 , V_398 , V_400 -> V_403 ) ;
else if ( V_3 -> V_113 == V_136 )
F_208 ( V_129 , V_398 , V_400 -> V_403 ) ;
else
F_214 ( V_129 , V_398 , V_400 -> V_403 ) ;
V_139:
return 0 ;
}
int T_8 F_225 ( struct V_125 * V_125 )
{
return F_226 ( V_125 , & V_404 ) ;
}
void F_227 ( struct V_125 * V_125 )
{
F_228 ( V_125 , & V_404 ) ;
}
static void F_229 ( struct V_2 * V_3 , int V_405 )
{
struct V_26 * V_27 = F_5 ( V_3 ) ;
F_230 ( V_3 , F_231 ( struct V_26 , V_289 ) ) ;
V_405 -= F_231 ( struct V_26 , V_289 ) + sizeof( V_27 -> V_289 ) ;
memset ( & V_27 -> V_289 + 1 , 0 , V_405 ) ;
}
static int T_8 F_232 ( struct V_125 * V_125 )
{
return F_233 ( & V_125 -> V_237 . F_14 , V_406 ,
V_407 , V_88 , V_125 ) ;
}
static void T_9 F_234 ( struct V_125 * V_125 )
{
F_235 ( V_125 -> V_237 . F_14 ) ;
}
static void T_9 F_236 ( struct V_408 * V_409 )
{
F_237 ( & V_132 , & V_99 , V_45 ) ;
}
int T_10 F_238 ( void )
{
int V_324 ;
V_324 = F_239 ( & V_410 , V_88 ) ;
if ( V_324 )
goto V_139;
V_324 = F_240 ( & V_411 ) ;
if ( V_324 )
goto V_412;
V_324 = F_241 ( & V_413 ) ;
if ( V_324 )
goto V_414;
V_139:
return V_324 ;
V_414:
F_242 ( & V_411 ) ;
V_412:
F_243 ( & V_410 , V_88 ) ;
goto V_139;
}
void F_244 ( void )
{
F_245 ( & V_413 ) ;
F_242 ( & V_411 ) ;
F_243 ( & V_410 , V_88 ) ;
}
