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
static void F_7 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 != V_19 ) {
if ( F_8 ( V_3 ) -> V_20 == & V_21 ) {
V_22 . V_23 ( V_3 ) ;
return;
}
F_9 () ;
F_10 ( V_3 , NULL ) ;
F_11 () ;
}
}
static T_1 F_12 ( const struct V_6 * V_7 )
{
return F_13 ( F_14 ( V_7 ) -> V_24 . V_25 ,
F_14 ( V_7 ) -> V_26 . V_25 ,
F_15 ( V_7 ) -> V_27 ,
F_15 ( V_7 ) -> V_28 ) ;
}
static int F_16 ( struct V_2 * V_3 , struct V_29 * V_30 ,
int V_31 )
{
struct V_32 * V_33 = (struct V_32 * ) V_30 ;
struct V_34 * V_35 = F_5 ( V_3 ) ;
struct V_36 * V_37 = F_8 ( V_3 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 = F_17 ( V_3 ) ;
struct V_4 * V_26 = NULL , * V_42 , V_43 ;
struct V_10 * V_11 ;
struct V_44 V_45 ;
struct V_8 * V_9 ;
int V_46 ;
int V_47 ;
if ( V_31 < V_48 )
return - V_49 ;
if ( V_33 -> V_50 != V_51 )
return - V_52 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
if ( V_39 -> V_53 ) {
V_45 . V_54 = V_33 -> V_55 & V_56 ;
F_18 ( V_45 . V_54 ) ;
if ( V_45 . V_54 & V_57 ) {
struct V_58 * V_54 ;
V_54 = F_19 ( V_3 , V_45 . V_54 ) ;
if ( V_54 == NULL )
return - V_49 ;
F_20 ( V_54 ) ;
}
}
if ( F_21 ( & V_33 -> V_59 ) )
V_33 -> V_59 . V_60 [ 15 ] = 0x1 ;
V_46 = F_22 ( & V_33 -> V_59 ) ;
if ( V_46 & V_61 )
return - V_62 ;
if ( V_46 & V_63 ) {
if ( V_31 >= sizeof( struct V_32 ) &&
V_33 -> V_64 ) {
if ( V_3 -> V_65 &&
V_3 -> V_65 != V_33 -> V_64 )
return - V_49 ;
V_3 -> V_65 = V_33 -> V_64 ;
}
if ( ! V_3 -> V_65 )
return - V_49 ;
}
if ( V_41 -> V_66 . V_67 &&
! F_23 ( & V_3 -> V_68 , & V_33 -> V_59 ) ) {
V_41 -> V_66 . V_69 = 0 ;
V_41 -> V_66 . V_67 = 0 ;
V_41 -> V_70 = 0 ;
}
V_3 -> V_68 = V_33 -> V_59 ;
V_39 -> V_71 = V_45 . V_54 ;
if ( V_46 == V_72 ) {
T_2 V_73 = V_37 -> V_74 ;
struct V_75 sin ;
F_24 ( V_3 , L_1 ) ;
if ( F_25 ( V_3 ) )
return - V_62 ;
sin . V_76 = V_77 ;
sin . V_78 = V_33 -> V_79 ;
sin . V_80 . V_81 = V_33 -> V_59 . V_25 [ 3 ] ;
V_37 -> V_20 = & V_21 ;
V_3 -> V_82 = V_83 ;
#ifdef F_26
V_41 -> V_84 = & V_85 ;
#endif
V_47 = F_27 ( V_3 , (struct V_29 * ) & sin , sizeof( sin ) ) ;
if ( V_47 ) {
V_37 -> V_74 = V_73 ;
V_37 -> V_20 = & V_86 ;
V_3 -> V_82 = V_87 ;
#ifdef F_26
V_41 -> V_84 = & V_88 ;
#endif
goto V_89;
} else {
F_28 ( V_35 -> V_90 , & V_39 -> V_26 ) ;
F_28 ( V_35 -> V_91 ,
& V_3 -> V_92 ) ;
}
return V_47 ;
}
if ( ! F_21 ( & V_3 -> V_92 ) )
V_26 = & V_3 -> V_92 ;
V_45 . V_93 = V_94 ;
V_45 . V_24 = V_3 -> V_68 ;
V_45 . V_26 = V_26 ? * V_26 : V_39 -> V_26 ;
V_45 . V_95 = V_3 -> V_65 ;
V_45 . V_96 = V_3 -> V_97 ;
V_45 . V_98 = V_33 -> V_79 ;
V_45 . V_99 = V_35 -> V_100 ;
V_42 = F_29 ( & V_45 , V_39 -> V_101 , & V_43 ) ;
F_30 ( V_3 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_3 , & V_45 , V_42 ) ;
if ( F_33 ( V_9 ) ) {
V_47 = F_34 ( V_9 ) ;
goto V_89;
}
if ( V_26 == NULL ) {
V_26 = & V_45 . V_26 ;
V_3 -> V_92 = * V_26 ;
}
V_39 -> V_26 = * V_26 ;
V_35 -> V_91 = V_102 ;
V_3 -> V_103 = V_104 ;
F_35 ( V_3 , V_9 , NULL , NULL ) ;
V_11 = (struct V_10 * ) V_9 ;
if ( V_105 . V_106 &&
! V_41 -> V_66 . V_67 &&
F_23 ( & V_11 -> V_107 . V_5 , & V_3 -> V_68 ) )
F_36 ( V_3 , V_9 ) ;
V_37 -> V_74 = 0 ;
if ( V_39 -> V_101 )
V_37 -> V_74 = ( V_39 -> V_101 -> V_108 +
V_39 -> V_101 -> V_109 ) ;
V_41 -> V_66 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_35 -> V_114 = V_33 -> V_79 ;
F_37 ( V_3 , V_115 ) ;
V_47 = F_38 ( & V_105 , V_3 ) ;
if ( V_47 )
goto V_116;
F_39 ( V_3 ) ;
if ( ! V_41 -> V_70 && F_40 ( ! V_41 -> V_117 ) )
V_41 -> V_70 = F_13 ( V_39 -> V_26 . V_25 ,
V_3 -> V_68 . V_25 ,
V_35 -> V_100 ,
V_35 -> V_114 ) ;
V_47 = F_41 ( V_3 ) ;
if ( V_47 )
goto V_116;
return 0 ;
V_116:
F_37 ( V_3 , V_19 ) ;
F_42 ( V_3 ) ;
V_89:
V_35 -> V_114 = 0 ;
V_3 -> V_118 = 0 ;
return V_47 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_18 ) & ( V_119 | V_120 ) )
return;
V_9 = F_44 ( V_3 , F_17 ( V_3 ) -> V_121 ) ;
if ( ! V_9 )
return;
if ( F_8 ( V_3 ) -> V_122 > F_45 ( V_9 ) ) {
F_46 ( V_3 , F_45 ( V_9 ) ) ;
F_47 ( V_3 ) ;
}
}
static void F_48 ( struct V_6 * V_7 , struct V_123 * V_101 ,
T_3 type , T_3 V_124 , int V_125 , T_4 V_126 )
{
const struct V_113 * V_127 = ( const struct V_113 * ) V_7 -> V_128 ;
const struct V_112 * V_129 = (struct V_112 * ) ( V_7 -> V_128 + V_125 ) ;
struct V_38 * V_39 ;
struct V_2 * V_3 ;
int V_47 ;
struct V_40 * V_41 ;
struct V_130 * V_131 ;
T_1 V_132 , V_133 ;
struct V_134 * V_134 = F_49 ( V_7 -> V_135 ) ;
V_3 = F_50 ( V_134 , & V_136 , & V_127 -> V_24 ,
V_129 -> V_27 , & V_127 -> V_26 , V_129 -> V_28 , V_7 -> V_135 -> V_137 ) ;
if ( V_3 == NULL ) {
F_51 ( V_134 , F_52 ( V_7 -> V_135 ) ,
V_138 ) ;
return;
}
if ( V_3 -> V_18 == V_139 ) {
F_53 ( F_54 ( V_3 ) ) ;
return;
}
F_55 ( V_3 ) ;
if ( F_56 ( V_3 ) && type != V_140 )
F_57 ( V_134 , V_141 ) ;
if ( V_3 -> V_18 == V_19 )
goto V_142;
if ( F_14 ( V_7 ) -> V_143 < F_6 ( V_3 ) -> V_144 ) {
F_57 ( V_134 , V_145 ) ;
goto V_142;
}
V_41 = F_17 ( V_3 ) ;
V_132 = F_58 ( V_129 -> V_132 ) ;
V_131 = V_41 -> V_146 ;
V_133 = V_131 ? F_59 ( V_131 ) -> V_147 : V_41 -> V_133 ;
if ( V_3 -> V_18 != V_148 &&
! F_60 ( V_132 , V_133 , V_41 -> V_149 ) ) {
F_57 ( V_134 , V_150 ) ;
goto V_142;
}
V_39 = F_6 ( V_3 ) ;
if ( type == V_151 ) {
struct V_8 * V_9 = F_61 ( V_3 , V_39 -> V_152 ) ;
if ( V_9 )
V_9 -> V_153 -> V_154 ( V_9 , V_3 , V_7 ) ;
goto V_142;
}
if ( type == V_140 ) {
if ( V_3 -> V_18 == V_148 )
goto V_142;
if ( ! F_62 ( V_3 ) )
goto V_142;
V_41 -> V_121 = F_58 ( V_126 ) ;
if ( ! F_56 ( V_3 ) )
F_43 ( V_3 ) ;
else if ( ! F_63 ( V_155 ,
& V_41 -> V_156 ) )
F_64 ( V_3 ) ;
goto V_142;
}
F_65 ( type , V_124 , & V_47 ) ;
switch ( V_3 -> V_18 ) {
struct V_130 * V_157 , * * V_158 ;
case V_148 :
if ( F_56 ( V_3 ) )
goto V_142;
V_157 = F_66 ( V_3 , & V_158 , V_129 -> V_27 , & V_127 -> V_24 ,
& V_127 -> V_26 , F_67 ( V_7 ) ) ;
if ( ! V_157 )
goto V_142;
F_68 ( V_157 -> V_3 != NULL ) ;
if ( V_132 != F_59 ( V_157 ) -> V_147 ) {
F_57 ( V_134 , V_150 ) ;
goto V_142;
}
F_69 ( V_3 , V_157 , V_158 ) ;
F_57 ( F_70 ( V_3 ) , V_159 ) ;
goto V_142;
case V_115 :
case V_160 :
if ( V_131 && V_131 -> V_3 == NULL )
break;
if ( ! F_56 ( V_3 ) ) {
V_3 -> V_161 = V_47 ;
V_3 -> V_162 ( V_3 ) ;
F_71 ( V_3 ) ;
} else
V_3 -> V_163 = V_47 ;
goto V_142;
}
if ( ! F_56 ( V_3 ) && V_39 -> V_164 ) {
V_3 -> V_161 = V_47 ;
V_3 -> V_162 ( V_3 ) ;
} else
V_3 -> V_163 = V_47 ;
V_142:
F_72 ( V_3 ) ;
F_73 ( V_3 ) ;
}
static int F_74 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_165 * V_166 ,
struct V_130 * V_157 ,
T_5 V_167 ,
struct V_168 * V_169 )
{
struct V_170 * V_171 = F_75 ( V_157 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_44 * V_45 = & V_166 -> V_172 . V_173 ;
struct V_6 * V_7 ;
int V_47 = - V_174 ;
if ( ! V_9 && ( V_9 = F_76 ( V_3 , V_45 , V_157 ) ) == NULL )
goto V_175;
V_7 = F_77 ( V_3 , V_9 , V_157 , V_169 ) ;
if ( V_7 ) {
F_78 ( V_7 , & V_171 -> V_176 ,
& V_171 -> V_177 ) ;
V_45 -> V_24 = V_171 -> V_177 ;
if ( V_39 -> V_178 && ( V_171 -> V_179 != NULL ) )
V_45 -> V_54 = V_58 ( F_14 ( V_171 -> V_179 ) ) ;
F_79 ( V_7 , V_167 ) ;
V_47 = F_80 ( V_3 , V_7 , V_45 , V_39 -> V_101 , V_39 -> V_180 ) ;
V_47 = F_81 ( V_47 ) ;
}
V_175:
return V_47 ;
}
static void F_82 ( struct V_130 * V_157 )
{
F_83 ( F_75 ( V_157 ) -> V_179 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_84 ( V_3 , (union V_181 * ) V_5 , V_51 ) ;
}
static struct V_1 * F_85 ( struct V_2 * V_3 ,
struct V_2 * V_182 )
{
return F_1 ( V_3 , & V_182 -> V_68 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_130 * V_157 )
{
return F_1 ( V_3 , & F_75 ( V_157 ) -> V_177 ) ;
}
static int F_87 ( struct V_2 * V_3 , char T_6 * V_183 ,
int V_184 )
{
struct V_185 V_186 ;
struct V_32 * V_187 = (struct V_32 * ) & V_186 . V_188 ;
if ( V_184 < sizeof( V_186 ) )
return - V_49 ;
if ( F_88 ( & V_186 , V_183 , sizeof( V_186 ) ) )
return - V_189 ;
if ( V_187 -> V_50 != V_51 )
return - V_49 ;
if ( ! V_186 . V_190 ) {
if ( F_89 ( & V_187 -> V_59 ) )
return F_90 ( V_3 , (union V_181 * ) & V_187 -> V_59 . V_25 [ 3 ] ,
V_77 ) ;
return F_90 ( V_3 , (union V_181 * ) & V_187 -> V_59 ,
V_51 ) ;
}
if ( V_186 . V_190 > V_191 )
return - V_49 ;
if ( F_89 ( & V_187 -> V_59 ) )
return F_91 ( V_3 , (union V_181 * ) & V_187 -> V_59 . V_25 [ 3 ] ,
V_77 , V_186 . V_192 , V_186 . V_190 , V_193 ) ;
return F_91 ( V_3 , (union V_181 * ) & V_187 -> V_59 ,
V_51 , V_186 . V_192 , V_186 . V_190 , V_193 ) ;
}
static int F_92 ( struct V_194 * V_195 ,
const struct V_4 * V_24 ,
const struct V_4 * V_26 , int V_196 )
{
struct V_197 * V_198 ;
struct V_199 V_200 ;
V_198 = & V_195 -> V_201 . V_173 ;
V_198 -> V_26 = * V_26 ;
V_198 -> V_24 = * V_24 ;
V_198 -> V_202 = F_93 ( V_94 ) ;
V_198 -> V_203 = F_93 ( V_196 ) ;
F_94 ( & V_200 , V_198 , sizeof( * V_198 ) ) ;
return F_95 ( & V_195 -> V_204 , & V_200 , sizeof( * V_198 ) ) ;
}
static int F_96 ( char * V_205 , struct V_1 * V_206 ,
const struct V_4 * V_24 , struct V_4 * V_26 ,
const struct V_112 * V_129 )
{
struct V_194 * V_195 ;
struct V_207 * V_208 ;
V_195 = F_97 () ;
if ( ! V_195 )
goto V_209;
V_208 = & V_195 -> V_204 ;
if ( F_98 ( V_208 ) )
goto V_210;
if ( F_92 ( V_195 , V_24 , V_26 , V_129 -> V_211 << 2 ) )
goto V_210;
if ( F_99 ( V_195 , V_129 ) )
goto V_210;
if ( F_100 ( V_195 , V_206 ) )
goto V_210;
if ( F_101 ( V_208 , V_205 ) )
goto V_210;
F_102 () ;
return 0 ;
V_210:
F_102 () ;
V_209:
memset ( V_205 , 0 , 16 ) ;
return 1 ;
}
static int F_103 ( char * V_205 , struct V_1 * V_206 ,
const struct V_2 * V_3 ,
const struct V_130 * V_157 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_26 , * V_24 ;
struct V_194 * V_195 ;
struct V_207 * V_208 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
if ( V_3 ) {
V_26 = & F_6 ( V_3 ) -> V_26 ;
V_24 = & V_3 -> V_68 ;
} else if ( V_157 ) {
V_26 = & F_75 ( V_157 ) -> V_176 ;
V_24 = & F_75 ( V_157 ) -> V_177 ;
} else {
const struct V_113 * V_212 = F_14 ( V_7 ) ;
V_26 = & V_212 -> V_26 ;
V_24 = & V_212 -> V_24 ;
}
V_195 = F_97 () ;
if ( ! V_195 )
goto V_209;
V_208 = & V_195 -> V_204 ;
if ( F_98 ( V_208 ) )
goto V_210;
if ( F_92 ( V_195 , V_24 , V_26 , V_7 -> V_203 ) )
goto V_210;
if ( F_99 ( V_195 , V_129 ) )
goto V_210;
if ( F_104 ( V_195 , V_7 , V_129 -> V_211 << 2 ) )
goto V_210;
if ( F_100 ( V_195 , V_206 ) )
goto V_210;
if ( F_101 ( V_208 , V_205 ) )
goto V_210;
F_102 () ;
return 0 ;
V_210:
F_102 () ;
V_209:
memset ( V_205 , 0 , 16 ) ;
return 1 ;
}
static int F_105 ( struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
const T_7 * V_213 = NULL ;
struct V_1 * V_214 ;
const struct V_113 * V_212 = F_14 ( V_7 ) ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
int V_215 ;
T_3 V_216 [ 16 ] ;
V_214 = F_1 ( V_3 , & V_212 -> V_26 ) ;
V_213 = F_106 ( V_129 ) ;
if ( ! V_214 && ! V_213 )
return 0 ;
if ( V_214 && ! V_213 ) {
F_57 ( F_70 ( V_3 ) , V_217 ) ;
return 1 ;
}
if ( ! V_214 && V_213 ) {
F_57 ( F_70 ( V_3 ) , V_218 ) ;
return 1 ;
}
V_215 = F_103 ( V_216 ,
V_214 ,
NULL , NULL , V_7 ) ;
if ( V_215 || memcmp ( V_213 , V_216 , 16 ) != 0 ) {
F_107 ( L_2 ,
V_215 ? L_3 : L_4 ,
& V_212 -> V_26 , F_108 ( V_129 -> V_28 ) ,
& V_212 -> V_24 , F_108 ( V_129 -> V_27 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
int V_219 ;
F_110 () ;
V_219 = F_105 ( V_3 , V_7 ) ;
F_111 () ;
return V_219 ;
}
static void F_112 ( struct V_130 * V_157 , struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_170 * V_171 = F_75 ( V_157 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
V_171 -> V_177 = F_14 ( V_7 ) -> V_26 ;
V_171 -> V_176 = F_14 ( V_7 ) -> V_24 ;
V_171 -> V_220 = V_3 -> V_65 ;
if ( ! V_3 -> V_65 &&
F_22 ( & V_171 -> V_177 ) & V_63 )
V_171 -> V_220 = F_113 ( V_7 ) ;
if ( ! F_114 ( V_7 ) -> V_221 &&
( F_115 ( V_3 , V_7 , & F_114 ( V_7 ) -> V_222 . V_223 ) ||
V_39 -> V_224 . V_225 . V_226 ||
V_39 -> V_224 . V_225 . V_227 || V_39 -> V_224 . V_225 . V_228 ||
V_39 -> V_224 . V_225 . V_229 || V_39 -> V_178 ) ) {
F_116 ( & V_7 -> V_230 ) ;
V_171 -> V_179 = V_7 ;
}
}
static struct V_8 * F_117 ( struct V_2 * V_3 , struct V_165 * V_166 ,
const struct V_130 * V_157 ,
bool * V_231 )
{
if ( V_231 )
* V_231 = true ;
return F_76 ( V_3 , & V_166 -> V_172 . V_173 , V_157 ) ;
}
static void F_118 ( struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_132 ,
T_2 V_232 , T_2 V_233 , T_2 V_234 , T_2 V_235 ,
int V_236 , struct V_1 * V_206 , int V_237 ,
T_3 V_180 , T_2 V_238 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_112 * V_239 ;
struct V_6 * V_240 ;
struct V_44 V_45 ;
struct V_134 * V_134 = V_3 ? F_70 ( V_3 ) : F_49 ( F_3 ( V_7 ) -> V_135 ) ;
struct V_2 * V_241 = V_134 -> V_242 . F_17 ;
unsigned int V_243 = sizeof( struct V_112 ) ;
struct V_8 * V_9 ;
T_4 * V_244 ;
if ( V_235 )
V_243 += V_245 ;
#ifdef F_26
if ( V_206 )
V_243 += V_246 ;
#endif
V_240 = F_119 ( V_247 + sizeof( struct V_113 ) + V_243 ,
V_248 ) ;
if ( V_240 == NULL )
return;
F_120 ( V_240 , V_247 + sizeof( struct V_113 ) + V_243 ) ;
V_239 = (struct V_112 * ) F_121 ( V_240 , V_243 ) ;
F_122 ( V_240 ) ;
memset ( V_239 , 0 , sizeof( * V_239 ) ) ;
V_239 -> V_27 = V_129 -> V_28 ;
V_239 -> V_28 = V_129 -> V_27 ;
V_239 -> V_211 = V_243 / 4 ;
V_239 -> V_132 = F_123 ( V_132 ) ;
V_239 -> V_249 = F_123 ( V_232 ) ;
V_239 -> V_232 = ! V_237 || ! V_129 -> V_232 ;
V_239 -> V_237 = V_237 ;
V_239 -> V_250 = F_124 ( V_233 ) ;
V_244 = ( T_4 * ) ( V_239 + 1 ) ;
if ( V_235 ) {
* V_244 ++ = F_123 ( ( V_251 << 24 ) | ( V_251 << 16 ) |
( V_252 << 8 ) | V_253 ) ;
* V_244 ++ = F_123 ( V_234 ) ;
* V_244 ++ = F_123 ( V_235 ) ;
}
#ifdef F_26
if ( V_206 ) {
* V_244 ++ = F_123 ( ( V_251 << 24 ) | ( V_251 << 16 ) |
( V_254 << 8 ) | V_255 ) ;
F_96 ( ( T_7 * ) V_244 , V_206 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_239 ) ;
}
#endif
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_24 = F_14 ( V_7 ) -> V_26 ;
V_45 . V_26 = F_14 ( V_7 ) -> V_24 ;
V_45 . V_54 = V_238 ;
V_240 -> V_256 = V_257 ;
V_240 -> V_258 = 0 ;
F_78 ( V_240 , & V_45 . V_26 , & V_45 . V_24 ) ;
V_45 . V_93 = V_94 ;
if ( F_125 ( & V_45 . V_24 ) && ! V_236 )
V_45 . V_95 = F_113 ( V_7 ) ;
else
V_45 . V_95 = V_236 ;
V_45 . V_96 = F_126 ( V_134 , V_7 -> V_259 ) ;
V_45 . V_98 = V_239 -> V_27 ;
V_45 . V_99 = V_239 -> V_28 ;
F_127 ( V_7 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_241 , & V_45 , NULL ) ;
if ( ! F_33 ( V_9 ) ) {
F_128 ( V_240 , V_9 ) ;
F_80 ( V_241 , V_240 , & V_45 , NULL , V_180 ) ;
F_129 ( V_134 , V_260 ) ;
if ( V_237 )
F_129 ( V_134 , V_261 ) ;
return;
}
F_83 ( V_240 ) ;
}
static void F_130 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
T_2 V_132 = 0 , V_249 = 0 ;
struct V_1 * V_206 = NULL ;
#ifdef F_26
const T_7 * V_213 = NULL ;
struct V_113 * V_262 = F_14 ( V_7 ) ;
unsigned char V_216 [ 16 ] ;
int V_215 ;
struct V_2 * V_263 = NULL ;
#endif
int V_236 ;
if ( V_129 -> V_237 )
return;
if ( ! V_3 && ! F_131 ( V_7 ) )
return;
#ifdef F_26
V_213 = F_106 ( V_129 ) ;
if ( ! V_3 && V_213 ) {
V_263 = F_132 ( F_49 ( F_3 ( V_7 ) -> V_135 ) ,
& V_136 , & V_262 -> V_26 ,
V_129 -> V_28 , & V_262 -> V_24 ,
F_108 ( V_129 -> V_28 ) , F_113 ( V_7 ) ) ;
if ( ! V_263 )
return;
F_110 () ;
V_206 = F_1 ( V_263 , & V_262 -> V_26 ) ;
if ( ! V_206 )
goto V_264;
V_215 = F_103 ( V_216 , V_206 , NULL , NULL , V_7 ) ;
if ( V_215 || memcmp ( V_213 , V_216 , 16 ) != 0 )
goto V_264;
} else {
V_206 = V_3 ? F_1 ( V_3 , & V_262 -> V_26 ) : NULL ;
}
#endif
if ( V_129 -> V_232 )
V_132 = F_58 ( V_129 -> V_249 ) ;
else
V_249 = F_58 ( V_129 -> V_132 ) + V_129 -> V_265 + V_129 -> V_266 + V_7 -> V_203 -
( V_129 -> V_211 << 2 ) ;
V_236 = V_3 ? V_3 -> V_65 : 0 ;
F_118 ( V_3 , V_7 , V_132 , V_249 , 0 , 0 , 0 , V_236 , V_206 , 1 , 0 , 0 ) ;
#ifdef F_26
V_264:
if ( V_263 ) {
F_111 () ;
F_73 ( V_263 ) ;
}
#endif
}
static void F_133 ( struct V_2 * V_3 , struct V_6 * V_7 , T_2 V_132 ,
T_2 V_232 , T_2 V_233 , T_2 V_234 , T_2 V_235 , int V_236 ,
struct V_1 * V_206 , T_3 V_180 ,
T_2 V_238 )
{
F_118 ( V_3 , V_7 , V_132 , V_232 , V_233 , V_234 , V_235 , V_236 , V_206 , 0 ,
V_180 , V_238 ) ;
}
static void F_134 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_267 * V_268 = F_54 ( V_3 ) ;
struct V_269 * V_270 = F_135 ( V_3 ) ;
F_133 ( V_3 , V_7 , V_270 -> V_271 , V_270 -> V_272 ,
V_270 -> V_273 >> V_268 -> V_274 ,
V_275 + V_270 -> V_276 ,
V_270 -> V_277 , V_268 -> V_278 , F_136 ( V_270 ) ,
V_268 -> V_279 , ( V_268 -> V_280 << 12 ) ) ;
F_53 ( V_268 ) ;
}
static void F_137 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_130 * V_157 )
{
F_133 ( V_3 , V_7 , ( V_3 -> V_18 == V_148 ) ?
F_59 ( V_157 ) -> V_147 + 1 : F_17 ( V_3 ) -> V_149 ,
F_59 ( V_157 ) -> V_281 , V_157 -> V_282 ,
V_275 , V_157 -> V_69 , V_3 -> V_65 ,
F_1 ( V_3 , & F_14 ( V_7 ) -> V_24 ) ,
0 , 0 ) ;
}
static struct V_2 * F_138 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_130 * V_157 , * * V_158 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_2 * V_283 ;
V_157 = F_66 ( V_3 , & V_158 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , F_113 ( V_7 ) ) ;
if ( V_157 )
return F_139 ( V_3 , V_7 , V_157 , V_158 , false ) ;
V_283 = F_140 ( F_70 ( V_3 ) , & V_136 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 , F_108 ( V_129 -> V_27 ) ,
F_113 ( V_7 ) ) ;
if ( V_283 ) {
if ( V_283 -> V_18 != V_139 ) {
F_55 ( V_283 ) ;
return V_283 ;
}
F_53 ( F_54 ( V_283 ) ) ;
return NULL ;
}
#ifdef F_141
if ( ! V_129 -> V_265 )
V_3 = F_142 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_143 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
if ( V_7 -> V_202 == F_124 ( V_284 ) )
return F_144 ( V_3 , V_7 ) ;
if ( ! F_131 ( V_7 ) )
goto V_285;
return F_145 ( & V_286 ,
& V_287 , V_3 , V_7 ) ;
V_285:
F_57 ( F_70 ( V_3 ) , V_159 ) ;
return 0 ;
}
static struct V_2 * F_146 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_130 * V_157 ,
struct V_8 * V_9 )
{
struct V_170 * V_171 ;
struct V_38 * V_288 , * V_39 = F_6 ( V_3 ) ;
struct V_289 * V_290 ;
struct V_34 * V_291 ;
struct V_40 * V_292 ;
struct V_2 * V_293 ;
#ifdef F_26
struct V_1 * V_206 ;
#endif
struct V_44 V_45 ;
if ( V_7 -> V_202 == F_124 ( V_284 ) ) {
V_293 = F_147 ( V_3 , V_7 , V_157 , V_9 ) ;
if ( V_293 == NULL )
return NULL ;
V_290 = (struct V_289 * ) V_293 ;
F_5 ( V_293 ) -> V_294 = & V_290 -> V_295 ;
V_291 = F_5 ( V_293 ) ;
V_288 = F_6 ( V_293 ) ;
V_292 = F_17 ( V_293 ) ;
memcpy ( V_288 , V_39 , sizeof( struct V_38 ) ) ;
F_28 ( V_291 -> V_296 , & V_293 -> V_68 ) ;
F_28 ( V_291 -> V_90 , & V_288 -> V_26 ) ;
V_293 -> V_92 = V_288 -> V_26 ;
F_8 ( V_293 ) -> V_20 = & V_21 ;
V_293 -> V_82 = V_83 ;
#ifdef F_26
V_292 -> V_84 = & V_85 ;
#endif
V_288 -> V_297 = NULL ;
V_288 -> V_298 = NULL ;
V_288 -> V_299 = NULL ;
V_288 -> V_101 = NULL ;
V_288 -> V_300 = F_113 ( V_7 ) ;
V_288 -> V_301 = F_14 ( V_7 ) -> V_143 ;
V_288 -> V_302 = F_148 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_178 )
V_288 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
F_46 ( V_293 , F_8 ( V_293 ) -> V_122 ) ;
return V_293 ;
}
V_171 = F_75 ( V_157 ) ;
if ( F_149 ( V_3 ) )
goto V_303;
if ( ! V_9 ) {
V_9 = F_76 ( V_3 , & V_45 , V_157 ) ;
if ( ! V_9 )
goto V_142;
}
V_293 = F_150 ( V_3 , V_157 , V_7 ) ;
if ( V_293 == NULL )
goto V_304;
V_293 -> V_103 = V_104 ;
F_35 ( V_293 , V_9 , NULL , NULL ) ;
F_2 ( V_293 , V_7 ) ;
V_290 = (struct V_289 * ) V_293 ;
F_5 ( V_293 ) -> V_294 = & V_290 -> V_295 ;
V_292 = F_17 ( V_293 ) ;
V_291 = F_5 ( V_293 ) ;
V_288 = F_6 ( V_293 ) ;
memcpy ( V_288 , V_39 , sizeof( struct V_38 ) ) ;
V_293 -> V_68 = V_171 -> V_177 ;
V_288 -> V_26 = V_171 -> V_176 ;
V_293 -> V_92 = V_171 -> V_176 ;
V_293 -> V_65 = V_171 -> V_220 ;
F_39 ( V_293 ) ;
V_291 -> V_305 = NULL ;
V_288 -> V_297 = NULL ;
V_288 -> V_298 = NULL ;
V_288 -> V_224 . V_306 = V_39 -> V_224 . V_306 ;
V_288 -> V_299 = NULL ;
if ( V_171 -> V_179 != NULL ) {
V_288 -> V_299 = F_151 ( V_171 -> V_179 ,
F_152 ( V_3 , V_248 ) ) ;
F_153 ( V_171 -> V_179 ) ;
V_171 -> V_179 = NULL ;
if ( V_288 -> V_299 )
F_154 ( V_288 -> V_299 , V_293 ) ;
}
V_288 -> V_101 = NULL ;
V_288 -> V_300 = F_113 ( V_7 ) ;
V_288 -> V_301 = F_14 ( V_7 ) -> V_143 ;
V_288 -> V_302 = F_148 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_178 )
V_288 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_101 )
V_288 -> V_101 = F_155 ( V_293 , V_39 -> V_101 ) ;
F_8 ( V_293 ) -> V_74 = 0 ;
if ( V_288 -> V_101 )
F_8 ( V_293 ) -> V_74 = ( V_288 -> V_101 -> V_109 +
V_288 -> V_101 -> V_108 ) ;
F_46 ( V_293 , F_45 ( V_9 ) ) ;
V_292 -> V_307 = F_156 ( V_9 ) ;
if ( F_17 ( V_3 ) -> V_66 . V_308 &&
F_17 ( V_3 ) -> V_66 . V_308 < V_292 -> V_307 )
V_292 -> V_307 = F_17 ( V_3 ) -> V_66 . V_308 ;
F_157 ( V_293 ) ;
V_291 -> V_296 = V_291 -> V_90 = V_102 ;
V_291 -> V_91 = V_102 ;
#ifdef F_26
V_206 = F_1 ( V_3 , & V_293 -> V_68 ) ;
if ( V_206 != NULL ) {
F_91 ( V_293 , (union V_181 * ) & V_293 -> V_68 ,
V_51 , V_206 -> V_206 , V_206 -> V_309 ,
F_152 ( V_3 , V_248 ) ) ;
}
#endif
if ( F_158 ( V_3 , V_293 ) < 0 ) {
F_159 ( V_293 ) ;
F_71 ( V_293 ) ;
goto V_142;
}
F_10 ( V_293 , NULL ) ;
return V_293 ;
V_303:
F_57 ( F_70 ( V_3 ) , V_310 ) ;
V_304:
F_160 ( V_9 ) ;
V_142:
F_57 ( F_70 ( V_3 ) , V_159 ) ;
return NULL ;
}
static int V_87 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_6 * V_311 = NULL ;
if ( V_7 -> V_202 == F_124 ( V_284 ) )
return V_83 ( V_3 , V_7 ) ;
if ( F_161 ( V_3 , V_7 ) )
goto V_312;
if ( V_39 -> V_224 . V_306 )
V_311 = F_151 ( V_7 , F_152 ( V_3 , V_248 ) ) ;
if ( V_3 -> V_18 == V_313 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_162 ( V_3 , V_7 ) ;
F_163 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_153 -> V_314 ( V_9 , V_39 -> V_16 ) == NULL ) {
F_160 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_164 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_203 ) ;
if ( V_311 )
goto V_315;
return 0 ;
}
if ( V_7 -> V_203 < F_165 ( V_7 ) || F_166 ( V_7 ) )
goto V_316;
if ( V_3 -> V_18 == V_148 ) {
struct V_2 * V_283 = F_138 ( V_3 , V_7 ) ;
if ( ! V_283 )
goto V_312;
if ( V_283 != V_3 ) {
F_162 ( V_283 , V_7 ) ;
F_163 ( V_3 , V_7 ) ;
if ( F_167 ( V_3 , V_283 , V_7 ) )
goto V_317;
if ( V_311 )
F_168 ( V_311 ) ;
return 0 ;
}
} else
F_162 ( V_3 , V_7 ) ;
if ( F_169 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_203 ) )
goto V_317;
if ( V_311 )
goto V_315;
return 0 ;
V_317:
F_130 ( V_3 , V_7 ) ;
V_312:
if ( V_311 )
F_168 ( V_311 ) ;
F_83 ( V_7 ) ;
return 0 ;
V_316:
F_129 ( F_70 ( V_3 ) , V_318 ) ;
F_129 ( F_70 ( V_3 ) , V_319 ) ;
goto V_312;
V_315:
V_41 = F_17 ( V_3 ) ;
if ( F_114 ( V_311 ) -> V_320 == V_41 -> V_281 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_120 | V_119 ) ) ) {
if ( V_39 -> V_224 . V_225 . V_226 || V_39 -> V_224 . V_225 . V_227 )
V_39 -> V_300 = F_113 ( V_311 ) ;
if ( V_39 -> V_224 . V_225 . V_228 || V_39 -> V_224 . V_225 . V_229 )
V_39 -> V_301 = F_14 ( V_311 ) -> V_143 ;
if ( V_39 -> V_224 . V_225 . V_321 || V_39 -> V_224 . V_225 . V_322 )
V_39 -> V_302 = F_148 ( F_14 ( V_311 ) ) ;
if ( V_39 -> V_178 )
V_39 -> V_71 = V_58 ( F_14 ( V_311 ) ) ;
if ( F_115 ( V_3 , V_311 , & F_114 ( V_311 ) -> V_222 . V_223 ) ) {
F_154 ( V_311 , V_3 ) ;
V_311 = F_170 ( & V_39 -> V_299 , V_311 ) ;
} else {
F_168 ( V_311 ) ;
V_311 = F_170 ( & V_39 -> V_299 , NULL ) ;
}
}
F_83 ( V_311 ) ;
return 0 ;
}
static void F_171 ( struct V_6 * V_7 , const struct V_113 * V_127 ,
const struct V_112 * V_129 )
{
memmove ( & F_114 ( V_7 ) -> V_222 . V_223 , F_172 ( V_7 ) ,
sizeof( struct V_123 ) ) ;
F_173 () ;
F_114 ( V_7 ) -> V_132 = F_58 ( V_129 -> V_132 ) ;
F_114 ( V_7 ) -> V_320 = ( F_114 ( V_7 ) -> V_132 + V_129 -> V_265 + V_129 -> V_266 +
V_7 -> V_203 - V_129 -> V_211 * 4 ) ;
F_114 ( V_7 ) -> V_249 = F_58 ( V_129 -> V_249 ) ;
F_114 ( V_7 ) -> V_323 = F_174 ( V_129 ) ;
F_114 ( V_7 ) -> V_221 = 0 ;
F_114 ( V_7 ) -> V_324 = F_175 ( V_127 ) ;
F_114 ( V_7 ) -> V_325 = 0 ;
}
static int F_176 ( struct V_6 * V_7 )
{
const struct V_112 * V_129 ;
const struct V_113 * V_127 ;
struct V_2 * V_3 ;
int V_219 ;
struct V_134 * V_134 = F_49 ( V_7 -> V_135 ) ;
if ( V_7 -> V_326 != V_327 )
goto V_328;
F_129 ( V_134 , V_329 ) ;
if ( ! F_177 ( V_7 , sizeof( struct V_112 ) ) )
goto V_328;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_211 < sizeof( struct V_112 ) / 4 )
goto V_330;
if ( ! F_177 ( V_7 , V_129 -> V_211 * 4 ) )
goto V_328;
if ( F_178 ( V_7 , V_94 , V_331 ) )
goto V_332;
V_129 = F_15 ( V_7 ) ;
V_127 = F_14 ( V_7 ) ;
V_3 = F_179 ( & V_136 , V_7 , V_129 -> V_28 , V_129 -> V_27 ,
F_67 ( V_7 ) ) ;
if ( ! V_3 )
goto V_333;
V_334:
if ( V_3 -> V_18 == V_139 )
goto V_335;
if ( V_127 -> V_143 < F_6 ( V_3 ) -> V_144 ) {
F_57 ( V_134 , V_145 ) ;
goto V_336;
}
if ( ! F_180 ( V_3 , V_337 , V_7 ) )
goto V_336;
F_171 ( V_7 , V_127 , V_129 ) ;
#ifdef F_26
if ( F_109 ( V_3 , V_7 ) )
goto V_336;
#endif
if ( F_161 ( V_3 , V_7 ) )
goto V_336;
F_181 ( V_3 ) ;
V_7 -> V_135 = NULL ;
F_182 ( V_3 ) ;
V_219 = 0 ;
if ( ! F_56 ( V_3 ) ) {
if ( ! F_183 ( V_3 , V_7 ) )
V_219 = V_87 ( V_3 , V_7 ) ;
} else if ( F_184 ( F_185 ( V_3 , V_7 ,
V_3 -> V_338 + V_3 -> V_339 ) ) ) {
F_72 ( V_3 ) ;
F_57 ( V_134 , V_340 ) ;
goto V_336;
}
F_72 ( V_3 ) ;
F_73 ( V_3 ) ;
return V_219 ? - 1 : 0 ;
V_333:
if ( ! F_180 ( NULL , V_337 , V_7 ) )
goto V_328;
F_171 ( V_7 , V_127 , V_129 ) ;
if ( V_7 -> V_203 < ( V_129 -> V_211 << 2 ) || F_166 ( V_7 ) ) {
V_332:
F_129 ( V_134 , V_318 ) ;
V_330:
F_129 ( V_134 , V_319 ) ;
} else {
F_130 ( NULL , V_7 ) ;
}
V_328:
F_83 ( V_7 ) ;
return 0 ;
V_336:
F_73 ( V_3 ) ;
goto V_328;
V_335:
if ( ! F_180 ( NULL , V_337 , V_7 ) ) {
F_53 ( F_54 ( V_3 ) ) ;
goto V_328;
}
F_171 ( V_7 , V_127 , V_129 ) ;
if ( V_7 -> V_203 < ( V_129 -> V_211 << 2 ) ) {
F_53 ( F_54 ( V_3 ) ) ;
goto V_330;
}
if ( F_166 ( V_7 ) ) {
F_53 ( F_54 ( V_3 ) ) ;
goto V_332;
}
switch ( F_186 ( F_54 ( V_3 ) , V_7 , V_129 ) ) {
case V_341 :
{
struct V_2 * V_342 ;
V_342 = F_132 ( F_49 ( V_7 -> V_135 ) , & V_136 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 ,
F_108 ( V_129 -> V_27 ) , F_113 ( V_7 ) ) ;
if ( V_342 != NULL ) {
struct V_267 * V_268 = F_54 ( V_3 ) ;
F_187 ( V_268 , & V_105 ) ;
F_53 ( V_268 ) ;
V_3 = V_342 ;
goto V_334;
}
}
case V_343 :
F_134 ( V_3 , V_7 ) ;
break;
case V_344 :
goto V_333;
case V_345 :
;
}
goto V_328;
}
static void F_188 ( struct V_6 * V_7 )
{
const struct V_113 * V_127 ;
const struct V_112 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_326 != V_327 )
return;
if ( ! F_177 ( V_7 , F_189 ( V_7 ) + sizeof( struct V_112 ) ) )
return;
V_127 = F_14 ( V_7 ) ;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_211 < sizeof( struct V_112 ) / 4 )
return;
V_3 = F_140 ( F_49 ( V_7 -> V_135 ) , & V_136 ,
& V_127 -> V_26 , V_129 -> V_28 ,
& V_127 -> V_24 , F_108 ( V_129 -> V_27 ) ,
F_67 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_346 = V_347 ;
if ( V_3 -> V_18 != V_139 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
if ( V_9 )
V_9 = F_190 ( V_9 , F_6 ( V_3 ) -> V_16 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_191 ( V_7 , V_9 ) ;
}
}
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = F_8 ( V_3 ) ;
F_193 ( V_3 ) ;
V_37 -> V_20 = & V_86 ;
#ifdef F_26
F_17 ( V_3 ) -> V_84 = & V_88 ;
#endif
return 0 ;
}
static void F_194 ( struct V_2 * V_3 )
{
F_195 ( V_3 ) ;
F_196 ( V_3 ) ;
}
static void F_197 ( struct V_348 * V_132 ,
const struct V_2 * V_3 , struct V_130 * V_157 , int V_349 , T_8 V_350 )
{
int V_351 = V_157 -> V_352 - V_353 ;
const struct V_4 * V_354 = & F_75 ( V_157 ) -> V_176 ;
const struct V_4 * V_27 = & F_75 ( V_157 ) -> V_177 ;
if ( V_351 < 0 )
V_351 = 0 ;
F_198 ( V_132 ,
L_5
L_6 ,
V_349 ,
V_354 -> V_25 [ 0 ] , V_354 -> V_25 [ 1 ] ,
V_354 -> V_25 [ 2 ] , V_354 -> V_25 [ 3 ] ,
F_75 ( V_157 ) -> V_355 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] ,
F_108 ( F_75 ( V_157 ) -> V_356 ) ,
V_160 ,
0 , 0 ,
1 ,
F_199 ( V_351 ) ,
V_157 -> V_357 ,
F_200 ( F_201 ( V_132 ) , V_350 ) ,
0 ,
0 ,
0 , V_157 ) ;
}
static void F_202 ( struct V_348 * V_132 , struct V_2 * V_358 , int V_349 )
{
const struct V_4 * V_27 , * V_354 ;
T_9 V_359 , V_360 ;
int V_361 ;
unsigned long V_362 ;
const struct V_34 * V_35 = F_5 ( V_358 ) ;
const struct V_40 * V_41 = F_17 ( V_358 ) ;
const struct V_36 * V_37 = F_8 ( V_358 ) ;
struct V_363 * V_364 = V_37 -> V_365 . V_364 ;
V_27 = & V_358 -> V_68 ;
V_354 = & V_358 -> V_92 ;
V_359 = F_108 ( V_35 -> V_114 ) ;
V_360 = F_108 ( V_35 -> V_100 ) ;
if ( V_37 -> V_366 == V_367 ) {
V_361 = 1 ;
V_362 = V_37 -> V_368 ;
} else if ( V_37 -> V_366 == V_369 ) {
V_361 = 4 ;
V_362 = V_37 -> V_368 ;
} else if ( F_203 ( & V_358 -> V_370 ) ) {
V_361 = 2 ;
V_362 = V_358 -> V_370 . V_352 ;
} else {
V_361 = 0 ;
V_362 = V_353 ;
}
F_198 ( V_132 ,
L_5
L_7 ,
V_349 ,
V_354 -> V_25 [ 0 ] , V_354 -> V_25 [ 1 ] ,
V_354 -> V_25 [ 2 ] , V_354 -> V_25 [ 3 ] , V_360 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_359 ,
V_358 -> V_18 ,
V_41 -> V_70 - V_41 -> V_133 ,
( V_358 -> V_18 == V_148 ) ? V_358 -> V_371 : ( V_41 -> V_281 - V_41 -> V_372 ) ,
V_361 ,
F_204 ( V_362 - V_353 ) ,
V_37 -> V_373 ,
F_200 ( F_201 ( V_132 ) , F_205 ( V_358 ) ) ,
V_37 -> V_374 ,
F_206 ( V_358 ) ,
F_207 ( & V_358 -> V_375 ) , V_358 ,
F_199 ( V_37 -> V_376 ) ,
F_199 ( V_37 -> V_377 . V_378 ) ,
( V_37 -> V_377 . V_379 << 1 ) | V_37 -> V_377 . V_380 ,
V_41 -> V_381 ,
V_358 -> V_18 == V_148 ?
( V_364 ? V_364 -> V_382 : 0 ) :
( F_208 ( V_41 ) ? - 1 : V_41 -> V_383 )
) ;
}
static void F_209 ( struct V_348 * V_132 ,
struct V_267 * V_268 , int V_349 )
{
const struct V_4 * V_27 , * V_354 ;
T_9 V_359 , V_360 ;
T_10 V_384 = V_268 -> V_385 - F_210 () ;
V_27 = & V_268 -> V_386 ;
V_354 = & V_268 -> V_387 ;
V_359 = F_108 ( V_268 -> V_388 ) ;
V_360 = F_108 ( V_268 -> V_389 ) ;
F_198 ( V_132 ,
L_5
L_8 ,
V_349 ,
V_354 -> V_25 [ 0 ] , V_354 -> V_25 [ 1 ] ,
V_354 -> V_25 [ 2 ] , V_354 -> V_25 [ 3 ] , V_360 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_359 ,
V_268 -> V_390 , 0 , 0 ,
3 , F_204 ( V_384 ) , 0 , 0 , 0 , 0 ,
F_207 ( & V_268 -> V_391 ) , V_268 ) ;
}
static int F_211 ( struct V_348 * V_132 , void * V_392 )
{
struct V_393 * V_394 ;
struct V_2 * V_3 = V_392 ;
if ( V_392 == V_395 ) {
F_212 ( V_132 ,
L_9
L_10
L_11
L_12
L_13 ) ;
goto V_142;
}
V_394 = V_132 -> V_396 ;
switch ( V_394 -> V_397 ) {
case V_398 :
case V_399 :
if ( V_3 -> V_18 == V_139 )
F_209 ( V_132 , V_392 , V_394 -> V_400 ) ;
else
F_202 ( V_132 , V_392 , V_394 -> V_400 ) ;
break;
case V_401 :
F_197 ( V_132 , V_394 -> V_402 , V_392 , V_394 -> V_400 , V_394 -> V_350 ) ;
break;
}
V_142:
return 0 ;
}
int T_11 F_213 ( struct V_134 * V_134 )
{
return F_214 ( V_134 , & V_403 ) ;
}
void F_215 ( struct V_134 * V_134 )
{
F_216 ( V_134 , & V_403 ) ;
}
static void F_217 ( struct V_2 * V_3 , int V_404 )
{
struct V_34 * V_35 = F_5 ( V_3 ) ;
F_218 ( V_3 , F_219 ( struct V_34 , V_294 ) ) ;
V_404 -= F_219 ( struct V_34 , V_294 ) + sizeof( V_35 -> V_294 ) ;
memset ( & V_35 -> V_294 + 1 , 0 , V_404 ) ;
}
static int T_11 F_220 ( struct V_134 * V_134 )
{
return F_221 ( & V_134 -> V_242 . F_17 , V_405 ,
V_406 , V_94 , V_134 ) ;
}
static void T_12 F_222 ( struct V_134 * V_134 )
{
F_223 ( V_134 -> V_242 . F_17 ) ;
}
static void T_12 F_224 ( struct V_407 * V_408 )
{
F_225 ( & V_136 , & V_105 , V_51 ) ;
}
int T_13 F_226 ( void )
{
int V_219 ;
V_219 = F_227 ( & V_409 , V_94 ) ;
if ( V_219 )
goto V_142;
V_219 = F_228 ( & V_410 ) ;
if ( V_219 )
goto V_411;
V_219 = F_229 ( & V_412 ) ;
if ( V_219 )
goto V_413;
V_142:
return V_219 ;
V_413:
F_230 ( & V_410 ) ;
V_411:
F_231 ( & V_409 , V_94 ) ;
goto V_142;
}
void F_232 ( void )
{
F_233 ( & V_412 ) ;
F_230 ( & V_410 ) ;
F_231 ( & V_409 , V_94 ) ;
}
