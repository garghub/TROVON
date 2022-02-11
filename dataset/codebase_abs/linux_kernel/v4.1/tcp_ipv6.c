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
if ( V_11 -> V_15 )
F_6 ( V_3 ) -> V_16 = V_11 -> V_15 -> V_17 ;
}
}
static T_1 F_7 ( const struct V_6 * V_7 )
{
return F_8 ( F_9 ( V_7 ) -> V_18 . V_19 ,
F_9 ( V_7 ) -> V_20 . V_19 ,
F_10 ( V_7 ) -> V_21 ,
F_10 ( V_7 ) -> V_22 ) ;
}
static int F_11 ( struct V_2 * V_3 , struct V_23 * V_24 ,
int V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
struct V_28 * V_29 = F_5 ( V_3 ) ;
struct V_30 * V_31 = F_12 ( V_3 ) ;
struct V_32 * V_33 = F_6 ( V_3 ) ;
struct V_34 * V_35 = F_13 ( V_3 ) ;
struct V_4 * V_20 = NULL , * V_36 , V_37 ;
struct V_10 * V_11 ;
struct V_38 V_39 ;
struct V_8 * V_9 ;
int V_40 ;
int V_41 ;
if ( V_25 < V_42 )
return - V_43 ;
if ( V_27 -> V_44 != V_45 )
return - V_46 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_33 -> V_47 ) {
V_39 . V_48 = V_27 -> V_49 & V_50 ;
F_14 ( V_39 . V_48 ) ;
if ( V_39 . V_48 & V_51 ) {
struct V_52 * V_48 ;
V_48 = F_15 ( V_3 , V_39 . V_48 ) ;
if ( ! V_48 )
return - V_43 ;
F_16 ( V_48 ) ;
}
}
if ( F_17 ( & V_27 -> V_53 ) )
V_27 -> V_53 . V_54 [ 15 ] = 0x1 ;
V_40 = F_18 ( & V_27 -> V_53 ) ;
if ( V_40 & V_55 )
return - V_56 ;
if ( V_40 & V_57 ) {
if ( V_25 >= sizeof( struct V_26 ) &&
V_27 -> V_58 ) {
if ( V_3 -> V_59 &&
V_3 -> V_59 != V_27 -> V_58 )
return - V_43 ;
V_3 -> V_59 = V_27 -> V_58 ;
}
if ( ! V_3 -> V_59 )
return - V_43 ;
}
if ( V_35 -> V_60 . V_61 &&
! F_19 ( & V_3 -> V_62 , & V_27 -> V_53 ) ) {
V_35 -> V_60 . V_63 = 0 ;
V_35 -> V_60 . V_61 = 0 ;
V_35 -> V_64 = 0 ;
}
V_3 -> V_62 = V_27 -> V_53 ;
V_33 -> V_65 = V_39 . V_48 ;
if ( V_40 == V_66 ) {
T_2 V_67 = V_31 -> V_68 ;
struct V_69 sin ;
F_20 ( V_3 , L_1 ) ;
if ( F_21 ( V_3 ) )
return - V_56 ;
sin . V_70 = V_71 ;
sin . V_72 = V_27 -> V_73 ;
sin . V_74 . V_75 = V_27 -> V_53 . V_19 [ 3 ] ;
V_31 -> V_76 = & V_77 ;
V_3 -> V_78 = V_79 ;
#ifdef F_22
V_35 -> V_80 = & V_81 ;
#endif
V_41 = F_23 ( V_3 , (struct V_23 * ) & sin , sizeof( sin ) ) ;
if ( V_41 ) {
V_31 -> V_68 = V_67 ;
V_31 -> V_76 = & V_82 ;
V_3 -> V_78 = V_83 ;
#ifdef F_22
V_35 -> V_80 = & V_84 ;
#endif
goto V_85;
}
V_33 -> V_20 = V_3 -> V_86 ;
return V_41 ;
}
if ( ! F_17 ( & V_3 -> V_86 ) )
V_20 = & V_3 -> V_86 ;
V_39 . V_87 = V_88 ;
V_39 . V_18 = V_3 -> V_62 ;
V_39 . V_20 = V_20 ? * V_20 : V_33 -> V_20 ;
V_39 . V_89 = V_3 -> V_59 ;
V_39 . V_90 = V_3 -> V_91 ;
V_39 . V_92 = V_27 -> V_73 ;
V_39 . V_93 = V_29 -> V_94 ;
V_36 = F_24 ( & V_39 , V_33 -> V_95 , & V_37 ) ;
F_25 ( V_3 , F_26 ( & V_39 ) ) ;
V_9 = F_27 ( V_3 , & V_39 , V_36 ) ;
if ( F_28 ( V_9 ) ) {
V_41 = F_29 ( V_9 ) ;
goto V_85;
}
if ( ! V_20 ) {
V_20 = & V_39 . V_20 ;
V_3 -> V_86 = * V_20 ;
}
V_33 -> V_20 = * V_20 ;
V_29 -> V_96 = V_97 ;
V_3 -> V_98 = V_99 ;
F_30 ( V_3 , V_9 , NULL , NULL ) ;
V_11 = (struct V_10 * ) V_9 ;
if ( V_100 . V_101 &&
! V_35 -> V_60 . V_61 &&
F_19 ( & V_11 -> V_102 . V_5 , & V_3 -> V_62 ) )
F_31 ( V_3 , V_9 ) ;
V_31 -> V_68 = 0 ;
if ( V_33 -> V_95 )
V_31 -> V_68 = ( V_33 -> V_95 -> V_103 +
V_33 -> V_95 -> V_104 ) ;
V_35 -> V_60 . V_105 = V_106 - sizeof( struct V_107 ) - sizeof( struct V_108 ) ;
V_29 -> V_109 = V_27 -> V_73 ;
F_32 ( V_3 , V_110 ) ;
V_41 = F_33 ( & V_100 , V_3 ) ;
if ( V_41 )
goto V_111;
F_34 ( V_3 ) ;
if ( ! V_35 -> V_64 && F_35 ( ! V_35 -> V_112 ) )
V_35 -> V_64 = F_8 ( V_33 -> V_20 . V_19 ,
V_3 -> V_62 . V_19 ,
V_29 -> V_94 ,
V_29 -> V_109 ) ;
V_41 = F_36 ( V_3 ) ;
if ( V_41 )
goto V_111;
return 0 ;
V_111:
F_32 ( V_3 , V_113 ) ;
F_37 ( V_3 ) ;
V_85:
V_29 -> V_109 = 0 ;
V_3 -> V_114 = 0 ;
return V_41 ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_115 ) & ( V_116 | V_117 ) )
return;
V_9 = F_39 ( V_3 , F_13 ( V_3 ) -> V_118 ) ;
if ( ! V_9 )
return;
if ( F_12 ( V_3 ) -> V_119 > F_40 ( V_9 ) ) {
F_41 ( V_3 , F_40 ( V_9 ) ) ;
F_42 ( V_3 ) ;
}
}
static void F_43 ( struct V_6 * V_7 , struct V_120 * V_95 ,
T_3 type , T_3 V_121 , int V_122 , T_4 V_123 )
{
const struct V_108 * V_124 = ( const struct V_108 * ) V_7 -> V_125 ;
const struct V_107 * V_126 = (struct V_107 * ) ( V_7 -> V_125 + V_122 ) ;
struct V_127 * V_127 = F_44 ( V_7 -> V_128 ) ;
struct V_129 * V_130 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_1 V_131 , V_132 ;
struct V_2 * V_3 ;
int V_41 ;
V_3 = F_45 ( V_127 , & V_133 ,
& V_124 -> V_18 , V_126 -> V_21 ,
& V_124 -> V_20 , F_46 ( V_126 -> V_22 ) ,
V_7 -> V_128 -> V_134 ) ;
if ( ! V_3 ) {
F_47 ( V_127 , F_48 ( V_7 -> V_128 ) ,
V_135 ) ;
return;
}
if ( V_3 -> V_115 == V_136 ) {
F_49 ( F_50 ( V_3 ) ) ;
return;
}
V_131 = F_51 ( V_126 -> V_131 ) ;
if ( V_3 -> V_115 == V_137 )
return F_52 ( V_3 , V_131 ) ;
F_53 ( V_3 ) ;
if ( F_54 ( V_3 ) && type != V_138 )
F_55 ( V_127 , V_139 ) ;
if ( V_3 -> V_115 == V_113 )
goto V_140;
if ( F_9 ( V_7 ) -> V_141 < F_6 ( V_3 ) -> V_142 ) {
F_55 ( V_127 , V_143 ) ;
goto V_140;
}
V_35 = F_13 ( V_3 ) ;
V_130 = V_35 -> V_144 ;
V_132 = V_130 ? F_56 ( V_130 ) -> V_145 : V_35 -> V_132 ;
if ( V_3 -> V_115 != V_146 &&
! F_57 ( V_131 , V_132 , V_35 -> V_147 ) ) {
F_55 ( V_127 , V_148 ) ;
goto V_140;
}
V_33 = F_6 ( V_3 ) ;
if ( type == V_149 ) {
struct V_8 * V_9 = F_58 ( V_3 , V_33 -> V_150 ) ;
if ( V_9 )
V_9 -> V_151 -> V_152 ( V_9 , V_3 , V_7 ) ;
goto V_140;
}
if ( type == V_138 ) {
if ( V_3 -> V_115 == V_146 )
goto V_140;
if ( ! F_59 ( V_3 ) )
goto V_140;
V_35 -> V_118 = F_51 ( V_123 ) ;
if ( ! F_54 ( V_3 ) )
F_38 ( V_3 ) ;
else if ( ! F_60 ( V_153 ,
& V_35 -> V_154 ) )
F_61 ( V_3 ) ;
goto V_140;
}
F_62 ( type , V_121 , & V_41 ) ;
switch ( V_3 -> V_115 ) {
case V_110 :
case V_155 :
if ( V_130 && ! V_130 -> V_3 )
break;
if ( ! F_54 ( V_3 ) ) {
V_3 -> V_156 = V_41 ;
V_3 -> V_157 ( V_3 ) ;
F_63 ( V_3 ) ;
} else
V_3 -> V_158 = V_41 ;
goto V_140;
}
if ( ! F_54 ( V_3 ) && V_33 -> V_159 ) {
V_3 -> V_156 = V_41 ;
V_3 -> V_157 ( V_3 ) ;
} else
V_3 -> V_158 = V_41 ;
V_140:
F_64 ( V_3 ) ;
F_65 ( V_3 ) ;
}
static int F_66 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_160 * V_161 ,
struct V_129 * V_162 ,
T_5 V_163 ,
struct V_164 * V_165 )
{
struct V_166 * V_167 = F_67 ( V_162 ) ;
struct V_32 * V_33 = F_6 ( V_3 ) ;
struct V_38 * V_39 = & V_161 -> V_168 . V_169 ;
struct V_6 * V_7 ;
int V_41 = - V_170 ;
if ( ! V_9 && ( V_9 = F_68 ( V_3 , V_39 , V_162 ) ) == NULL )
goto V_171;
V_7 = F_69 ( V_3 , V_9 , V_162 , V_165 ) ;
if ( V_7 ) {
F_70 ( V_7 , & V_167 -> V_172 ,
& V_167 -> V_173 ) ;
V_39 -> V_18 = V_167 -> V_173 ;
if ( V_33 -> V_174 && V_167 -> V_175 )
V_39 -> V_48 = V_52 ( F_9 ( V_167 -> V_175 ) ) ;
F_71 ( V_7 , V_163 ) ;
V_41 = F_72 ( V_3 , V_7 , V_39 , V_33 -> V_95 , V_33 -> V_176 ) ;
V_41 = F_73 ( V_41 ) ;
}
V_171:
return V_41 ;
}
static void F_74 ( struct V_129 * V_162 )
{
F_75 ( F_67 ( V_162 ) -> V_175 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_76 ( V_3 , (union V_177 * ) V_5 , V_45 ) ;
}
static struct V_1 * F_77 ( struct V_2 * V_3 ,
const struct V_2 * V_178 )
{
return F_1 ( V_3 , & V_178 -> V_62 ) ;
}
static int F_78 ( struct V_2 * V_3 , char T_6 * V_179 ,
int V_180 )
{
struct V_181 V_182 ;
struct V_26 * V_183 = (struct V_26 * ) & V_182 . V_184 ;
if ( V_180 < sizeof( V_182 ) )
return - V_43 ;
if ( F_79 ( & V_182 , V_179 , sizeof( V_182 ) ) )
return - V_185 ;
if ( V_183 -> V_44 != V_45 )
return - V_43 ;
if ( ! V_182 . V_186 ) {
if ( F_80 ( & V_183 -> V_53 ) )
return F_81 ( V_3 , (union V_177 * ) & V_183 -> V_53 . V_19 [ 3 ] ,
V_71 ) ;
return F_81 ( V_3 , (union V_177 * ) & V_183 -> V_53 ,
V_45 ) ;
}
if ( V_182 . V_186 > V_187 )
return - V_43 ;
if ( F_80 ( & V_183 -> V_53 ) )
return F_82 ( V_3 , (union V_177 * ) & V_183 -> V_53 . V_19 [ 3 ] ,
V_71 , V_182 . V_188 , V_182 . V_186 , V_189 ) ;
return F_82 ( V_3 , (union V_177 * ) & V_183 -> V_53 ,
V_45 , V_182 . V_188 , V_182 . V_186 , V_189 ) ;
}
static int F_83 ( struct V_190 * V_191 ,
const struct V_4 * V_18 ,
const struct V_4 * V_20 , int V_192 )
{
struct V_193 * V_194 ;
struct V_195 V_196 ;
V_194 = & V_191 -> V_197 . V_169 ;
V_194 -> V_20 = * V_20 ;
V_194 -> V_18 = * V_18 ;
V_194 -> V_198 = F_84 ( V_88 ) ;
V_194 -> V_199 = F_84 ( V_192 ) ;
F_85 ( & V_196 , V_194 , sizeof( * V_194 ) ) ;
return F_86 ( & V_191 -> V_200 , & V_196 , sizeof( * V_194 ) ) ;
}
static int F_87 ( char * V_201 , struct V_1 * V_202 ,
const struct V_4 * V_18 , struct V_4 * V_20 ,
const struct V_107 * V_126 )
{
struct V_190 * V_191 ;
struct V_203 * V_204 ;
V_191 = F_88 () ;
if ( ! V_191 )
goto V_205;
V_204 = & V_191 -> V_200 ;
if ( F_89 ( V_204 ) )
goto V_206;
if ( F_83 ( V_191 , V_18 , V_20 , V_126 -> V_207 << 2 ) )
goto V_206;
if ( F_90 ( V_191 , V_126 ) )
goto V_206;
if ( F_91 ( V_191 , V_202 ) )
goto V_206;
if ( F_92 ( V_204 , V_201 ) )
goto V_206;
F_93 () ;
return 0 ;
V_206:
F_93 () ;
V_205:
memset ( V_201 , 0 , 16 ) ;
return 1 ;
}
static int F_94 ( char * V_201 ,
const struct V_1 * V_202 ,
const struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_20 , * V_18 ;
struct V_190 * V_191 ;
struct V_203 * V_204 ;
const struct V_107 * V_126 = F_10 ( V_7 ) ;
if ( V_3 ) {
V_20 = & V_3 -> V_86 ;
V_18 = & V_3 -> V_62 ;
} else {
const struct V_108 * V_208 = F_9 ( V_7 ) ;
V_20 = & V_208 -> V_20 ;
V_18 = & V_208 -> V_18 ;
}
V_191 = F_88 () ;
if ( ! V_191 )
goto V_205;
V_204 = & V_191 -> V_200 ;
if ( F_89 ( V_204 ) )
goto V_206;
if ( F_83 ( V_191 , V_18 , V_20 , V_7 -> V_199 ) )
goto V_206;
if ( F_90 ( V_191 , V_126 ) )
goto V_206;
if ( F_95 ( V_191 , V_7 , V_126 -> V_207 << 2 ) )
goto V_206;
if ( F_91 ( V_191 , V_202 ) )
goto V_206;
if ( F_92 ( V_204 , V_201 ) )
goto V_206;
F_93 () ;
return 0 ;
V_206:
F_93 () ;
V_205:
memset ( V_201 , 0 , 16 ) ;
return 1 ;
}
static bool F_96 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_209 = NULL ;
struct V_1 * V_210 ;
const struct V_108 * V_208 = F_9 ( V_7 ) ;
const struct V_107 * V_126 = F_10 ( V_7 ) ;
int V_211 ;
T_3 V_212 [ 16 ] ;
V_210 = F_1 ( V_3 , & V_208 -> V_20 ) ;
V_209 = F_97 ( V_126 ) ;
if ( ! V_210 && ! V_209 )
return false ;
if ( V_210 && ! V_209 ) {
F_55 ( F_98 ( V_3 ) , V_213 ) ;
return true ;
}
if ( ! V_210 && V_209 ) {
F_55 ( F_98 ( V_3 ) , V_214 ) ;
return true ;
}
V_211 = F_94 ( V_212 ,
V_210 ,
NULL , V_7 ) ;
if ( V_211 || memcmp ( V_209 , V_212 , 16 ) != 0 ) {
F_99 ( L_2 ,
V_211 ? L_3 : L_4 ,
& V_208 -> V_20 , F_46 ( V_126 -> V_22 ) ,
& V_208 -> V_18 , F_46 ( V_126 -> V_21 ) ) ;
return true ;
}
return false ;
}
static void F_100 ( struct V_129 * V_162 , struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_166 * V_167 = F_67 ( V_162 ) ;
struct V_32 * V_33 = F_6 ( V_3 ) ;
V_167 -> V_173 = F_9 ( V_7 ) -> V_20 ;
V_167 -> V_172 = F_9 ( V_7 ) -> V_18 ;
if ( ! V_3 -> V_59 &&
F_18 ( & V_167 -> V_173 ) & V_57 )
V_167 -> V_215 = F_101 ( V_7 ) ;
if ( ! F_102 ( V_7 ) -> V_216 &&
( F_103 ( V_3 , V_7 , & F_102 ( V_7 ) -> V_217 . V_218 ) ||
V_33 -> V_219 . V_220 . V_221 ||
V_33 -> V_219 . V_220 . V_222 || V_33 -> V_219 . V_220 . V_223 ||
V_33 -> V_219 . V_220 . V_224 || V_33 -> V_174 ) ) {
F_104 ( & V_7 -> V_225 ) ;
V_167 -> V_175 = V_7 ;
}
}
static struct V_8 * F_105 ( struct V_2 * V_3 , struct V_160 * V_161 ,
const struct V_129 * V_162 ,
bool * V_226 )
{
if ( V_226 )
* V_226 = true ;
return F_68 ( V_3 , & V_161 -> V_168 . V_169 , V_162 ) ;
}
static void F_106 ( struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_131 ,
T_2 V_227 , T_2 V_228 , T_2 V_229 , T_2 V_230 ,
int V_231 , struct V_1 * V_202 , int V_232 ,
T_3 V_176 , T_2 V_233 )
{
const struct V_107 * V_126 = F_10 ( V_7 ) ;
struct V_107 * V_234 ;
struct V_6 * V_235 ;
struct V_38 V_39 ;
struct V_127 * V_127 = V_3 ? F_98 ( V_3 ) : F_44 ( F_3 ( V_7 ) -> V_128 ) ;
struct V_2 * V_236 = V_127 -> V_237 . F_13 ;
unsigned int V_238 = sizeof( struct V_107 ) ;
struct V_8 * V_9 ;
T_4 * V_239 ;
if ( V_230 )
V_238 += V_240 ;
#ifdef F_22
if ( V_202 )
V_238 += V_241 ;
#endif
V_235 = F_107 ( V_242 + sizeof( struct V_108 ) + V_238 ,
V_243 ) ;
if ( ! V_235 )
return;
F_108 ( V_235 , V_242 + sizeof( struct V_108 ) + V_238 ) ;
V_234 = (struct V_107 * ) F_109 ( V_235 , V_238 ) ;
F_110 ( V_235 ) ;
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
V_234 -> V_21 = V_126 -> V_22 ;
V_234 -> V_22 = V_126 -> V_21 ;
V_234 -> V_207 = V_238 / 4 ;
V_234 -> V_131 = F_111 ( V_131 ) ;
V_234 -> V_244 = F_111 ( V_227 ) ;
V_234 -> V_227 = ! V_232 || ! V_126 -> V_227 ;
V_234 -> V_232 = V_232 ;
V_234 -> V_245 = F_112 ( V_228 ) ;
V_239 = ( T_4 * ) ( V_234 + 1 ) ;
if ( V_230 ) {
* V_239 ++ = F_111 ( ( V_246 << 24 ) | ( V_246 << 16 ) |
( V_247 << 8 ) | V_248 ) ;
* V_239 ++ = F_111 ( V_229 ) ;
* V_239 ++ = F_111 ( V_230 ) ;
}
#ifdef F_22
if ( V_202 ) {
* V_239 ++ = F_111 ( ( V_246 << 24 ) | ( V_246 << 16 ) |
( V_249 << 8 ) | V_250 ) ;
F_87 ( ( T_7 * ) V_239 , V_202 ,
& F_9 ( V_7 ) -> V_20 ,
& F_9 ( V_7 ) -> V_18 , V_234 ) ;
}
#endif
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_18 = F_9 ( V_7 ) -> V_20 ;
V_39 . V_20 = F_9 ( V_7 ) -> V_18 ;
V_39 . V_48 = V_233 ;
V_235 -> V_251 = V_252 ;
V_235 -> V_253 = 0 ;
F_70 ( V_235 , & V_39 . V_20 , & V_39 . V_18 ) ;
V_39 . V_87 = V_88 ;
if ( F_113 ( & V_39 . V_18 ) && ! V_231 )
V_39 . V_89 = F_101 ( V_7 ) ;
else
V_39 . V_89 = V_231 ;
V_39 . V_90 = F_114 ( V_127 , V_7 -> V_254 ) ;
V_39 . V_92 = V_234 -> V_21 ;
V_39 . V_93 = V_234 -> V_22 ;
F_115 ( V_7 , F_26 ( & V_39 ) ) ;
V_9 = F_27 ( V_236 , & V_39 , NULL ) ;
if ( ! F_28 ( V_9 ) ) {
F_116 ( V_235 , V_9 ) ;
F_72 ( V_236 , V_235 , & V_39 , NULL , V_176 ) ;
F_117 ( V_127 , V_255 ) ;
if ( V_232 )
F_117 ( V_127 , V_256 ) ;
return;
}
F_75 ( V_235 ) ;
}
static void F_118 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_107 * V_126 = F_10 ( V_7 ) ;
T_2 V_131 = 0 , V_244 = 0 ;
struct V_1 * V_202 = NULL ;
#ifdef F_22
const T_7 * V_209 = NULL ;
struct V_108 * V_257 = F_9 ( V_7 ) ;
unsigned char V_212 [ 16 ] ;
int V_211 ;
struct V_2 * V_258 = NULL ;
#endif
int V_231 ;
if ( V_126 -> V_232 )
return;
if ( ! V_3 && ! F_119 ( V_7 ) )
return;
#ifdef F_22
V_209 = F_97 ( V_126 ) ;
if ( ! V_3 && V_209 ) {
V_258 = F_120 ( F_44 ( F_3 ( V_7 ) -> V_128 ) ,
& V_133 , & V_257 -> V_20 ,
V_126 -> V_22 , & V_257 -> V_18 ,
F_46 ( V_126 -> V_22 ) , F_101 ( V_7 ) ) ;
if ( ! V_258 )
return;
F_121 () ;
V_202 = F_1 ( V_258 , & V_257 -> V_20 ) ;
if ( ! V_202 )
goto V_259;
V_211 = F_94 ( V_212 , V_202 , NULL , V_7 ) ;
if ( V_211 || memcmp ( V_209 , V_212 , 16 ) != 0 )
goto V_259;
} else {
V_202 = V_3 ? F_1 ( V_3 , & V_257 -> V_20 ) : NULL ;
}
#endif
if ( V_126 -> V_227 )
V_131 = F_51 ( V_126 -> V_244 ) ;
else
V_244 = F_51 ( V_126 -> V_131 ) + V_126 -> V_260 + V_126 -> V_261 + V_7 -> V_199 -
( V_126 -> V_207 << 2 ) ;
V_231 = V_3 ? V_3 -> V_59 : 0 ;
F_106 ( V_3 , V_7 , V_131 , V_244 , 0 , 0 , 0 , V_231 , V_202 , 1 , 0 , 0 ) ;
#ifdef F_22
V_259:
if ( V_258 ) {
F_122 () ;
F_65 ( V_258 ) ;
}
#endif
}
static void F_123 ( struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_131 ,
T_2 V_227 , T_2 V_228 , T_2 V_229 , T_2 V_230 , int V_231 ,
struct V_1 * V_202 , T_3 V_176 ,
T_2 V_233 )
{
F_106 ( V_3 , V_7 , V_131 , V_227 , V_228 , V_229 , V_230 , V_231 , V_202 , 0 ,
V_176 , V_233 ) ;
}
static void F_124 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_262 * V_263 = F_50 ( V_3 ) ;
struct V_264 * V_265 = F_125 ( V_3 ) ;
F_123 ( V_3 , V_7 , V_265 -> V_266 , V_265 -> V_267 ,
V_265 -> V_268 >> V_263 -> V_269 ,
V_270 + V_265 -> V_271 ,
V_265 -> V_272 , V_263 -> V_273 , F_126 ( V_265 ) ,
V_263 -> V_274 , F_84 ( V_263 -> V_275 ) ) ;
F_49 ( V_263 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_129 * V_162 )
{
F_123 ( V_3 , V_7 , ( V_3 -> V_115 == V_146 ) ?
F_56 ( V_162 ) -> V_145 + 1 : F_13 ( V_3 ) -> V_147 ,
F_56 ( V_162 ) -> V_276 , V_162 -> V_277 ,
V_270 , V_162 -> V_63 , V_3 -> V_59 ,
F_1 ( V_3 , & F_9 ( V_7 ) -> V_18 ) ,
0 , 0 ) ;
}
static struct V_2 * F_128 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_107 * V_126 = F_10 ( V_7 ) ;
struct V_129 * V_162 ;
struct V_2 * V_278 ;
V_162 = F_129 ( V_3 , V_126 -> V_22 ,
& F_9 ( V_7 ) -> V_20 ,
& F_9 ( V_7 ) -> V_18 , F_101 ( V_7 ) ) ;
if ( V_162 ) {
V_278 = F_130 ( V_3 , V_7 , V_162 , false ) ;
if ( ! V_278 )
F_131 ( V_162 ) ;
return V_278 ;
}
V_278 = F_45 ( F_98 ( V_3 ) , & V_133 ,
& F_9 ( V_7 ) -> V_20 , V_126 -> V_22 ,
& F_9 ( V_7 ) -> V_18 , F_46 ( V_126 -> V_21 ) ,
F_101 ( V_7 ) ) ;
if ( V_278 ) {
if ( V_278 -> V_115 != V_136 ) {
F_53 ( V_278 ) ;
return V_278 ;
}
F_49 ( F_50 ( V_278 ) ) ;
return NULL ;
}
#ifdef F_132
if ( ! V_126 -> V_260 )
V_3 = F_133 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_134 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_198 == F_112 ( V_279 ) )
return F_135 ( V_3 , V_7 ) ;
if ( ! F_119 ( V_7 ) )
goto V_280;
return F_136 ( & V_281 ,
& V_282 , V_3 , V_7 ) ;
V_280:
F_55 ( F_98 ( V_3 ) , V_283 ) ;
return 0 ;
}
static struct V_2 * F_137 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_129 * V_162 ,
struct V_8 * V_9 )
{
struct V_166 * V_167 ;
struct V_32 * V_284 , * V_33 = F_6 ( V_3 ) ;
struct V_285 * V_286 ;
struct V_28 * V_287 ;
struct V_34 * V_288 ;
struct V_2 * V_289 ;
#ifdef F_22
struct V_1 * V_202 ;
#endif
struct V_38 V_39 ;
if ( V_7 -> V_198 == F_112 ( V_279 ) ) {
V_289 = F_138 ( V_3 , V_7 , V_162 , V_9 ) ;
if ( ! V_289 )
return NULL ;
V_286 = (struct V_285 * ) V_289 ;
F_5 ( V_289 ) -> V_290 = & V_286 -> V_291 ;
V_287 = F_5 ( V_289 ) ;
V_284 = F_6 ( V_289 ) ;
V_288 = F_13 ( V_289 ) ;
memcpy ( V_284 , V_33 , sizeof( struct V_32 ) ) ;
V_284 -> V_20 = V_289 -> V_86 ;
F_12 ( V_289 ) -> V_76 = & V_77 ;
V_289 -> V_78 = V_79 ;
#ifdef F_22
V_288 -> V_80 = & V_81 ;
#endif
V_284 -> V_292 = NULL ;
V_284 -> V_293 = NULL ;
V_284 -> V_294 = NULL ;
V_284 -> V_95 = NULL ;
V_284 -> V_295 = F_101 ( V_7 ) ;
V_284 -> V_296 = F_9 ( V_7 ) -> V_141 ;
V_284 -> V_297 = F_139 ( F_9 ( V_7 ) ) ;
if ( V_33 -> V_174 )
V_284 -> V_65 = V_52 ( F_9 ( V_7 ) ) ;
F_41 ( V_289 , F_12 ( V_289 ) -> V_119 ) ;
return V_289 ;
}
V_167 = F_67 ( V_162 ) ;
if ( F_140 ( V_3 ) )
goto V_298;
if ( ! V_9 ) {
V_9 = F_68 ( V_3 , & V_39 , V_162 ) ;
if ( ! V_9 )
goto V_140;
}
V_289 = F_141 ( V_3 , V_162 , V_7 ) ;
if ( ! V_289 )
goto V_299;
V_289 -> V_98 = V_99 ;
F_30 ( V_289 , V_9 , NULL , NULL ) ;
F_2 ( V_289 , V_7 ) ;
V_286 = (struct V_285 * ) V_289 ;
F_5 ( V_289 ) -> V_290 = & V_286 -> V_291 ;
V_288 = F_13 ( V_289 ) ;
V_287 = F_5 ( V_289 ) ;
V_284 = F_6 ( V_289 ) ;
memcpy ( V_284 , V_33 , sizeof( struct V_32 ) ) ;
V_289 -> V_62 = V_167 -> V_173 ;
V_284 -> V_20 = V_167 -> V_172 ;
V_289 -> V_86 = V_167 -> V_172 ;
V_289 -> V_59 = V_167 -> V_215 ;
F_34 ( V_289 ) ;
V_287 -> V_300 = NULL ;
V_284 -> V_292 = NULL ;
V_284 -> V_293 = NULL ;
V_284 -> V_219 . V_301 = V_33 -> V_219 . V_301 ;
V_284 -> V_294 = NULL ;
if ( V_167 -> V_175 ) {
V_284 -> V_294 = F_142 ( V_167 -> V_175 ,
F_143 ( V_3 , V_243 ) ) ;
F_144 ( V_167 -> V_175 ) ;
V_167 -> V_175 = NULL ;
if ( V_284 -> V_294 )
F_145 ( V_284 -> V_294 , V_289 ) ;
}
V_284 -> V_95 = NULL ;
V_284 -> V_295 = F_101 ( V_7 ) ;
V_284 -> V_296 = F_9 ( V_7 ) -> V_141 ;
V_284 -> V_297 = F_139 ( F_9 ( V_7 ) ) ;
if ( V_33 -> V_174 )
V_284 -> V_65 = V_52 ( F_9 ( V_7 ) ) ;
if ( V_33 -> V_95 )
V_284 -> V_95 = F_146 ( V_289 , V_33 -> V_95 ) ;
F_12 ( V_289 ) -> V_68 = 0 ;
if ( V_284 -> V_95 )
F_12 ( V_289 ) -> V_68 = ( V_284 -> V_95 -> V_104 +
V_284 -> V_95 -> V_103 ) ;
F_147 ( V_289 , V_9 ) ;
F_41 ( V_289 , F_40 ( V_9 ) ) ;
V_288 -> V_302 = F_148 ( V_9 ) ;
if ( F_13 ( V_3 ) -> V_60 . V_303 &&
F_13 ( V_3 ) -> V_60 . V_303 < V_288 -> V_302 )
V_288 -> V_302 = F_13 ( V_3 ) -> V_60 . V_303 ;
F_149 ( V_289 ) ;
V_287 -> V_304 = V_287 -> V_305 = V_97 ;
V_287 -> V_96 = V_97 ;
#ifdef F_22
V_202 = F_1 ( V_3 , & V_289 -> V_62 ) ;
if ( V_202 ) {
F_82 ( V_289 , (union V_177 * ) & V_289 -> V_62 ,
V_45 , V_202 -> V_202 , V_202 -> V_306 ,
F_143 ( V_3 , V_243 ) ) ;
}
#endif
if ( F_150 ( V_3 , V_289 ) < 0 ) {
F_151 ( V_289 ) ;
F_63 ( V_289 ) ;
goto V_140;
}
F_152 ( V_289 , NULL ) ;
return V_289 ;
V_298:
F_55 ( F_98 ( V_3 ) , V_307 ) ;
V_299:
F_153 ( V_9 ) ;
V_140:
F_55 ( F_98 ( V_3 ) , V_283 ) ;
return NULL ;
}
static int V_83 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_32 * V_33 = F_6 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_6 * V_308 = NULL ;
if ( V_7 -> V_198 == F_112 ( V_279 ) )
return V_79 ( V_3 , V_7 ) ;
if ( F_154 ( V_3 , V_7 ) )
goto V_309;
if ( V_33 -> V_219 . V_301 )
V_308 = F_142 ( V_7 , F_143 ( V_3 , V_243 ) ) ;
if ( V_3 -> V_115 == V_310 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_155 ( V_3 , V_7 ) ;
F_156 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_151 -> V_311 ( V_9 , V_33 -> V_16 ) == NULL ) {
F_153 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_157 ( V_3 , V_7 , F_10 ( V_7 ) , V_7 -> V_199 ) ;
if ( V_308 )
goto V_312;
return 0 ;
}
if ( V_7 -> V_199 < F_158 ( V_7 ) || F_159 ( V_7 ) )
goto V_313;
if ( V_3 -> V_115 == V_146 ) {
struct V_2 * V_278 = F_128 ( V_3 , V_7 ) ;
if ( ! V_278 )
goto V_309;
if ( V_278 != V_3 ) {
F_155 ( V_278 , V_7 ) ;
F_156 ( V_3 , V_7 ) ;
if ( F_160 ( V_3 , V_278 , V_7 ) )
goto V_314;
if ( V_308 )
F_161 ( V_308 ) ;
return 0 ;
}
} else
F_155 ( V_3 , V_7 ) ;
if ( F_162 ( V_3 , V_7 , F_10 ( V_7 ) , V_7 -> V_199 ) )
goto V_314;
if ( V_308 )
goto V_312;
return 0 ;
V_314:
F_118 ( V_3 , V_7 ) ;
V_309:
if ( V_308 )
F_161 ( V_308 ) ;
F_75 ( V_7 ) ;
return 0 ;
V_313:
F_117 ( F_98 ( V_3 ) , V_315 ) ;
F_117 ( F_98 ( V_3 ) , V_316 ) ;
goto V_309;
V_312:
V_35 = F_13 ( V_3 ) ;
if ( F_102 ( V_308 ) -> V_317 == V_35 -> V_276 &&
! ( ( 1 << V_3 -> V_115 ) & ( V_117 | V_116 ) ) ) {
if ( V_33 -> V_219 . V_220 . V_221 || V_33 -> V_219 . V_220 . V_222 )
V_33 -> V_295 = F_101 ( V_308 ) ;
if ( V_33 -> V_219 . V_220 . V_223 || V_33 -> V_219 . V_220 . V_224 )
V_33 -> V_296 = F_9 ( V_308 ) -> V_141 ;
if ( V_33 -> V_219 . V_220 . V_318 || V_33 -> V_219 . V_220 . V_319 )
V_33 -> V_297 = F_139 ( F_9 ( V_308 ) ) ;
if ( V_33 -> V_174 )
V_33 -> V_65 = V_52 ( F_9 ( V_308 ) ) ;
if ( F_103 ( V_3 , V_308 , & F_102 ( V_308 ) -> V_217 . V_218 ) ) {
F_145 ( V_308 , V_3 ) ;
V_308 = F_163 ( & V_33 -> V_294 , V_308 ) ;
} else {
F_161 ( V_308 ) ;
V_308 = F_163 ( & V_33 -> V_294 , NULL ) ;
}
}
F_75 ( V_308 ) ;
return 0 ;
}
static void F_164 ( struct V_6 * V_7 , const struct V_108 * V_124 ,
const struct V_107 * V_126 )
{
memmove ( & F_102 ( V_7 ) -> V_217 . V_218 , F_165 ( V_7 ) ,
sizeof( struct V_120 ) ) ;
F_166 () ;
F_102 ( V_7 ) -> V_131 = F_51 ( V_126 -> V_131 ) ;
F_102 ( V_7 ) -> V_317 = ( F_102 ( V_7 ) -> V_131 + V_126 -> V_260 + V_126 -> V_261 +
V_7 -> V_199 - V_126 -> V_207 * 4 ) ;
F_102 ( V_7 ) -> V_244 = F_51 ( V_126 -> V_244 ) ;
F_102 ( V_7 ) -> V_320 = F_167 ( V_126 ) ;
F_102 ( V_7 ) -> V_216 = 0 ;
F_102 ( V_7 ) -> V_321 = F_168 ( V_124 ) ;
F_102 ( V_7 ) -> V_322 = 0 ;
}
static void F_169 ( struct V_6 * V_7 )
{
memmove ( F_165 ( V_7 ) , & F_102 ( V_7 ) -> V_217 . V_218 ,
sizeof( struct V_120 ) ) ;
}
static int F_170 ( struct V_6 * V_7 )
{
const struct V_107 * V_126 ;
const struct V_108 * V_124 ;
struct V_2 * V_3 ;
int V_323 ;
struct V_127 * V_127 = F_44 ( V_7 -> V_128 ) ;
if ( V_7 -> V_324 != V_325 )
goto V_326;
F_117 ( V_127 , V_327 ) ;
if ( ! F_171 ( V_7 , sizeof( struct V_107 ) ) )
goto V_326;
V_126 = F_10 ( V_7 ) ;
if ( V_126 -> V_207 < sizeof( struct V_107 ) / 4 )
goto V_328;
if ( ! F_171 ( V_7 , V_126 -> V_207 * 4 ) )
goto V_326;
if ( F_172 ( V_7 , V_88 , V_329 ) )
goto V_330;
V_126 = F_10 ( V_7 ) ;
V_124 = F_9 ( V_7 ) ;
V_3 = F_173 ( & V_133 , V_7 , V_126 -> V_22 , V_126 -> V_21 ,
F_174 ( V_7 ) ) ;
if ( ! V_3 )
goto V_331;
V_332:
if ( V_3 -> V_115 == V_136 )
goto V_333;
if ( V_124 -> V_141 < F_6 ( V_3 ) -> V_142 ) {
F_55 ( V_127 , V_143 ) ;
goto V_334;
}
if ( ! F_175 ( V_3 , V_335 , V_7 ) )
goto V_334;
F_164 ( V_7 , V_124 , V_126 ) ;
#ifdef F_22
if ( F_96 ( V_3 , V_7 ) )
goto V_334;
#endif
if ( F_154 ( V_3 , V_7 ) )
goto V_334;
F_176 ( V_3 ) ;
V_7 -> V_128 = NULL ;
F_177 ( V_3 ) ;
V_323 = 0 ;
if ( ! F_54 ( V_3 ) ) {
if ( ! F_178 ( V_3 , V_7 ) )
V_323 = V_83 ( V_3 , V_7 ) ;
} else if ( F_179 ( F_180 ( V_3 , V_7 ,
V_3 -> V_336 + V_3 -> V_337 ) ) ) {
F_64 ( V_3 ) ;
F_55 ( V_127 , V_338 ) ;
goto V_334;
}
F_64 ( V_3 ) ;
F_65 ( V_3 ) ;
return V_323 ? - 1 : 0 ;
V_331:
if ( ! F_175 ( NULL , V_335 , V_7 ) )
goto V_326;
F_164 ( V_7 , V_124 , V_126 ) ;
if ( V_7 -> V_199 < ( V_126 -> V_207 << 2 ) || F_159 ( V_7 ) ) {
V_330:
F_117 ( V_127 , V_315 ) ;
V_328:
F_117 ( V_127 , V_316 ) ;
} else {
F_118 ( NULL , V_7 ) ;
}
V_326:
F_75 ( V_7 ) ;
return 0 ;
V_334:
F_65 ( V_3 ) ;
goto V_326;
V_333:
if ( ! F_175 ( NULL , V_335 , V_7 ) ) {
F_49 ( F_50 ( V_3 ) ) ;
goto V_326;
}
F_164 ( V_7 , V_124 , V_126 ) ;
if ( V_7 -> V_199 < ( V_126 -> V_207 << 2 ) ) {
F_49 ( F_50 ( V_3 ) ) ;
goto V_328;
}
if ( F_159 ( V_7 ) ) {
F_49 ( F_50 ( V_3 ) ) ;
goto V_330;
}
switch ( F_181 ( F_50 ( V_3 ) , V_7 , V_126 ) ) {
case V_339 :
{
struct V_2 * V_340 ;
V_340 = F_120 ( F_44 ( V_7 -> V_128 ) , & V_133 ,
& F_9 ( V_7 ) -> V_20 , V_126 -> V_22 ,
& F_9 ( V_7 ) -> V_18 ,
F_46 ( V_126 -> V_21 ) , F_101 ( V_7 ) ) ;
if ( V_340 ) {
struct V_262 * V_263 = F_50 ( V_3 ) ;
F_182 ( V_263 ) ;
F_49 ( V_263 ) ;
V_3 = V_340 ;
F_169 ( V_7 ) ;
goto V_332;
}
}
case V_341 :
F_124 ( V_3 , V_7 ) ;
break;
case V_342 :
F_169 ( V_7 ) ;
goto V_331;
case V_343 :
;
}
goto V_326;
}
static void F_183 ( struct V_6 * V_7 )
{
const struct V_108 * V_124 ;
const struct V_107 * V_126 ;
struct V_2 * V_3 ;
if ( V_7 -> V_324 != V_325 )
return;
if ( ! F_171 ( V_7 , F_184 ( V_7 ) + sizeof( struct V_107 ) ) )
return;
V_124 = F_9 ( V_7 ) ;
V_126 = F_10 ( V_7 ) ;
if ( V_126 -> V_207 < sizeof( struct V_107 ) / 4 )
return;
V_3 = F_45 ( F_44 ( V_7 -> V_128 ) , & V_133 ,
& V_124 -> V_20 , V_126 -> V_22 ,
& V_124 -> V_18 , F_46 ( V_126 -> V_21 ) ,
F_174 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_344 = V_345 ;
if ( F_185 ( V_3 ) ) {
struct V_8 * V_9 = F_186 ( V_3 -> V_12 ) ;
if ( V_9 )
V_9 = F_187 ( V_9 , F_6 ( V_3 ) -> V_16 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_188 ( V_7 , V_9 ) ;
}
}
}
static int F_189 ( struct V_2 * V_3 )
{
struct V_30 * V_31 = F_12 ( V_3 ) ;
F_190 ( V_3 ) ;
V_31 -> V_76 = & V_82 ;
#ifdef F_22
F_13 ( V_3 ) -> V_80 = & V_84 ;
#endif
return 0 ;
}
static void F_191 ( struct V_2 * V_3 )
{
F_192 ( V_3 ) ;
F_193 ( V_3 ) ;
}
static void F_194 ( struct V_346 * V_131 ,
struct V_129 * V_162 , int V_347 , T_8 V_348 )
{
long V_349 = V_162 -> V_350 . V_351 - V_352 ;
const struct V_4 * V_353 = & F_67 ( V_162 ) -> V_172 ;
const struct V_4 * V_21 = & F_67 ( V_162 ) -> V_173 ;
if ( V_349 < 0 )
V_349 = 0 ;
F_195 ( V_131 ,
L_5
L_6 ,
V_347 ,
V_353 -> V_19 [ 0 ] , V_353 -> V_19 [ 1 ] ,
V_353 -> V_19 [ 2 ] , V_353 -> V_19 [ 3 ] ,
F_67 ( V_162 ) -> V_354 ,
V_21 -> V_19 [ 0 ] , V_21 -> V_19 [ 1 ] ,
V_21 -> V_19 [ 2 ] , V_21 -> V_19 [ 3 ] ,
F_46 ( F_67 ( V_162 ) -> V_355 ) ,
V_155 ,
0 , 0 ,
1 ,
F_196 ( V_349 ) ,
V_162 -> V_356 ,
F_197 ( F_198 ( V_131 ) , V_348 ) ,
0 ,
0 ,
0 , V_162 ) ;
}
static void F_199 ( struct V_346 * V_131 , struct V_2 * V_357 , int V_347 )
{
const struct V_4 * V_21 , * V_353 ;
T_9 V_358 , V_359 ;
int V_360 ;
unsigned long V_361 ;
const struct V_28 * V_29 = F_5 ( V_357 ) ;
const struct V_34 * V_35 = F_13 ( V_357 ) ;
const struct V_30 * V_31 = F_12 ( V_357 ) ;
struct V_362 * V_363 = V_31 -> V_364 . V_363 ;
V_21 = & V_357 -> V_62 ;
V_353 = & V_357 -> V_86 ;
V_358 = F_46 ( V_29 -> V_109 ) ;
V_359 = F_46 ( V_29 -> V_94 ) ;
if ( V_31 -> V_365 == V_366 ) {
V_360 = 1 ;
V_361 = V_31 -> V_367 ;
} else if ( V_31 -> V_365 == V_368 ) {
V_360 = 4 ;
V_361 = V_31 -> V_367 ;
} else if ( F_200 ( & V_357 -> V_369 ) ) {
V_360 = 2 ;
V_361 = V_357 -> V_369 . V_351 ;
} else {
V_360 = 0 ;
V_361 = V_352 ;
}
F_195 ( V_131 ,
L_5
L_7 ,
V_347 ,
V_353 -> V_19 [ 0 ] , V_353 -> V_19 [ 1 ] ,
V_353 -> V_19 [ 2 ] , V_353 -> V_19 [ 3 ] , V_359 ,
V_21 -> V_19 [ 0 ] , V_21 -> V_19 [ 1 ] ,
V_21 -> V_19 [ 2 ] , V_21 -> V_19 [ 3 ] , V_358 ,
V_357 -> V_115 ,
V_35 -> V_64 - V_35 -> V_132 ,
( V_357 -> V_115 == V_146 ) ? V_357 -> V_370 : ( V_35 -> V_276 - V_35 -> V_371 ) ,
V_360 ,
F_201 ( V_361 - V_352 ) ,
V_31 -> V_372 ,
F_197 ( F_198 ( V_131 ) , F_202 ( V_357 ) ) ,
V_31 -> V_373 ,
F_203 ( V_357 ) ,
F_204 ( & V_357 -> V_374 ) , V_357 ,
F_196 ( V_31 -> V_375 ) ,
F_196 ( V_31 -> V_376 . V_377 ) ,
( V_31 -> V_376 . V_378 << 1 ) | V_31 -> V_376 . V_379 ,
V_35 -> V_380 ,
V_357 -> V_115 == V_146 ?
( V_363 ? V_363 -> V_381 : 0 ) :
( F_205 ( V_35 ) ? - 1 : V_35 -> V_382 )
) ;
}
static void F_206 ( struct V_346 * V_131 ,
struct V_262 * V_263 , int V_347 )
{
long V_383 = V_263 -> V_384 . V_351 - V_352 ;
const struct V_4 * V_21 , * V_353 ;
T_9 V_358 , V_359 ;
V_21 = & V_263 -> V_385 ;
V_353 = & V_263 -> V_386 ;
V_358 = F_46 ( V_263 -> V_387 ) ;
V_359 = F_46 ( V_263 -> V_388 ) ;
F_195 ( V_131 ,
L_5
L_8 ,
V_347 ,
V_353 -> V_19 [ 0 ] , V_353 -> V_19 [ 1 ] ,
V_353 -> V_19 [ 2 ] , V_353 -> V_19 [ 3 ] , V_359 ,
V_21 -> V_19 [ 0 ] , V_21 -> V_19 [ 1 ] ,
V_21 -> V_19 [ 2 ] , V_21 -> V_19 [ 3 ] , V_358 ,
V_263 -> V_389 , 0 , 0 ,
3 , F_201 ( V_383 ) , 0 , 0 , 0 , 0 ,
F_204 ( & V_263 -> V_390 ) , V_263 ) ;
}
static int F_207 ( struct V_346 * V_131 , void * V_391 )
{
struct V_392 * V_393 ;
struct V_2 * V_3 = V_391 ;
if ( V_391 == V_394 ) {
F_208 ( V_131 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_140;
}
V_393 = V_131 -> V_395 ;
switch ( V_393 -> V_396 ) {
case V_397 :
case V_398 :
if ( V_3 -> V_115 == V_136 )
F_206 ( V_131 , V_391 , V_393 -> V_399 ) ;
else
F_199 ( V_131 , V_391 , V_393 -> V_399 ) ;
break;
case V_400 :
F_194 ( V_131 , V_391 , V_393 -> V_399 , V_393 -> V_348 ) ;
break;
}
V_140:
return 0 ;
}
int T_10 F_209 ( struct V_127 * V_127 )
{
return F_210 ( V_127 , & V_401 ) ;
}
void F_211 ( struct V_127 * V_127 )
{
F_212 ( V_127 , & V_401 ) ;
}
static void F_213 ( struct V_2 * V_3 , int V_402 )
{
struct V_28 * V_29 = F_5 ( V_3 ) ;
F_214 ( V_3 , F_215 ( struct V_28 , V_290 ) ) ;
V_402 -= F_215 ( struct V_28 , V_290 ) + sizeof( V_29 -> V_290 ) ;
memset ( & V_29 -> V_290 + 1 , 0 , V_402 ) ;
}
static int T_10 F_216 ( struct V_127 * V_127 )
{
return F_217 ( & V_127 -> V_237 . F_13 , V_403 ,
V_404 , V_88 , V_127 ) ;
}
static void T_11 F_218 ( struct V_127 * V_127 )
{
F_219 ( V_127 -> V_237 . F_13 ) ;
}
static void T_11 F_220 ( struct V_405 * V_406 )
{
F_221 ( & V_133 , & V_100 , V_45 ) ;
}
int T_12 F_222 ( void )
{
int V_323 ;
V_323 = F_223 ( & V_407 , V_88 ) ;
if ( V_323 )
goto V_140;
V_323 = F_224 ( & V_408 ) ;
if ( V_323 )
goto V_409;
V_323 = F_225 ( & V_410 ) ;
if ( V_323 )
goto V_411;
V_140:
return V_323 ;
V_411:
F_226 ( & V_408 ) ;
V_409:
F_227 ( & V_407 , V_88 ) ;
goto V_140;
}
void F_228 ( void )
{
F_229 ( & V_410 ) ;
F_226 ( & V_408 ) ;
F_227 ( & V_407 , V_88 ) ;
}
