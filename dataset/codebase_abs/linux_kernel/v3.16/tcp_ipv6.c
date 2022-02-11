static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return NULL ;
}
static void F_2 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_10 * V_11 = ( const struct V_10 * ) V_9 ;
F_4 ( V_9 ) ;
V_3 -> V_12 = V_9 ;
F_5 ( V_3 ) -> V_13 = V_7 -> V_14 ;
if ( V_11 -> V_15 )
F_6 ( V_3 ) -> V_16 = V_11 -> V_15 -> V_17 ;
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
if ( ! V_41 -> V_70 && F_39 ( ! V_41 -> V_117 ) )
V_41 -> V_70 = F_13 ( V_39 -> V_26 . V_25 ,
V_3 -> V_68 . V_25 ,
V_35 -> V_100 ,
V_35 -> V_114 ) ;
V_47 = F_40 ( V_3 ) ;
if ( V_47 )
goto V_116;
return 0 ;
V_116:
F_37 ( V_3 , V_19 ) ;
F_41 ( V_3 ) ;
V_89:
V_35 -> V_114 = 0 ;
V_3 -> V_118 = 0 ;
return V_47 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_18 ) & ( V_119 | V_120 ) )
return;
V_9 = F_43 ( V_3 , F_17 ( V_3 ) -> V_121 ) ;
if ( ! V_9 )
return;
if ( F_8 ( V_3 ) -> V_122 > F_44 ( V_9 ) ) {
F_45 ( V_3 , F_44 ( V_9 ) ) ;
F_46 ( V_3 ) ;
}
}
static void F_47 ( struct V_6 * V_7 , struct V_123 * V_101 ,
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
struct V_134 * V_134 = F_48 ( V_7 -> V_135 ) ;
V_3 = F_49 ( V_134 , & V_136 , & V_127 -> V_24 ,
V_129 -> V_27 , & V_127 -> V_26 , V_129 -> V_28 , V_7 -> V_135 -> V_137 ) ;
if ( V_3 == NULL ) {
F_50 ( V_134 , F_51 ( V_7 -> V_135 ) ,
V_138 ) ;
return;
}
if ( V_3 -> V_18 == V_139 ) {
F_52 ( F_53 ( V_3 ) ) ;
return;
}
F_54 ( V_3 ) ;
if ( F_55 ( V_3 ) && type != V_140 )
F_56 ( V_134 , V_141 ) ;
if ( V_3 -> V_18 == V_19 )
goto V_142;
if ( F_14 ( V_7 ) -> V_143 < F_6 ( V_3 ) -> V_144 ) {
F_56 ( V_134 , V_145 ) ;
goto V_142;
}
V_41 = F_17 ( V_3 ) ;
V_132 = F_57 ( V_129 -> V_132 ) ;
V_131 = V_41 -> V_146 ;
V_133 = V_131 ? F_58 ( V_131 ) -> V_147 : V_41 -> V_133 ;
if ( V_3 -> V_18 != V_148 &&
! F_59 ( V_132 , V_133 , V_41 -> V_149 ) ) {
F_56 ( V_134 , V_150 ) ;
goto V_142;
}
V_39 = F_6 ( V_3 ) ;
if ( type == V_151 ) {
struct V_8 * V_9 = F_60 ( V_3 , V_39 -> V_152 ) ;
if ( V_9 )
V_9 -> V_153 -> V_154 ( V_9 , V_3 , V_7 ) ;
goto V_142;
}
if ( type == V_140 ) {
if ( V_3 -> V_18 == V_148 )
goto V_142;
if ( ! F_61 ( V_3 ) )
goto V_142;
V_41 -> V_121 = F_57 ( V_126 ) ;
if ( ! F_55 ( V_3 ) )
F_42 ( V_3 ) ;
else if ( ! F_62 ( V_155 ,
& V_41 -> V_156 ) )
F_63 ( V_3 ) ;
goto V_142;
}
F_64 ( type , V_124 , & V_47 ) ;
switch ( V_3 -> V_18 ) {
struct V_130 * V_157 , * * V_158 ;
case V_148 :
if ( F_55 ( V_3 ) )
goto V_142;
V_157 = F_65 ( V_3 , & V_158 , V_129 -> V_27 , & V_127 -> V_24 ,
& V_127 -> V_26 , F_66 ( V_7 ) ) ;
if ( ! V_157 )
goto V_142;
F_67 ( V_157 -> V_3 != NULL ) ;
if ( V_132 != F_58 ( V_157 ) -> V_147 ) {
F_56 ( V_134 , V_150 ) ;
goto V_142;
}
F_68 ( V_3 , V_157 , V_158 ) ;
F_56 ( F_69 ( V_3 ) , V_159 ) ;
goto V_142;
case V_115 :
case V_160 :
if ( V_131 && V_131 -> V_3 == NULL )
break;
if ( ! F_55 ( V_3 ) ) {
V_3 -> V_161 = V_47 ;
V_3 -> V_162 ( V_3 ) ;
F_70 ( V_3 ) ;
} else
V_3 -> V_163 = V_47 ;
goto V_142;
}
if ( ! F_55 ( V_3 ) && V_39 -> V_164 ) {
V_3 -> V_161 = V_47 ;
V_3 -> V_162 ( V_3 ) ;
} else
V_3 -> V_163 = V_47 ;
V_142:
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
}
static int F_73 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_130 * V_157 ,
T_5 V_165 ,
struct V_166 * V_167 )
{
struct V_168 * V_169 = F_74 ( V_157 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_6 * V_7 ;
int V_47 = - V_170 ;
if ( ! V_9 && ( V_9 = F_75 ( V_3 , V_45 , V_157 ) ) == NULL )
goto V_171;
V_7 = F_76 ( V_3 , V_9 , V_157 , V_167 ) ;
if ( V_7 ) {
F_77 ( V_7 , & V_169 -> V_172 ,
& V_169 -> V_173 ) ;
V_45 -> V_24 = V_169 -> V_173 ;
if ( V_39 -> V_174 && ( V_169 -> V_175 != NULL ) )
V_45 -> V_54 = V_58 ( F_14 ( V_169 -> V_175 ) ) ;
F_78 ( V_7 , V_165 ) ;
V_47 = F_79 ( V_3 , V_7 , V_45 , V_39 -> V_101 , V_39 -> V_176 ) ;
V_47 = F_80 ( V_47 ) ;
}
V_171:
return V_47 ;
}
static int F_81 ( struct V_2 * V_3 , struct V_130 * V_157 )
{
struct V_44 V_45 ;
int V_177 ;
V_177 = F_73 ( V_3 , NULL , & V_45 , V_157 , 0 , NULL ) ;
if ( ! V_177 ) {
F_82 ( F_69 ( V_3 ) , V_178 ) ;
F_56 ( F_69 ( V_3 ) , V_179 ) ;
}
return V_177 ;
}
static void F_83 ( struct V_130 * V_157 )
{
F_84 ( F_74 ( V_157 ) -> V_175 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_85 ( V_3 , (union V_180 * ) V_5 , V_51 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_2 * V_181 )
{
return F_1 ( V_3 , & V_181 -> V_68 ) ;
}
static struct V_1 * F_87 ( struct V_2 * V_3 ,
struct V_130 * V_157 )
{
return F_1 ( V_3 , & F_74 ( V_157 ) -> V_173 ) ;
}
static int F_88 ( struct V_2 * V_3 , char T_6 * V_182 ,
int V_183 )
{
struct V_184 V_185 ;
struct V_32 * V_186 = (struct V_32 * ) & V_185 . V_187 ;
if ( V_183 < sizeof( V_185 ) )
return - V_49 ;
if ( F_89 ( & V_185 , V_182 , sizeof( V_185 ) ) )
return - V_188 ;
if ( V_186 -> V_50 != V_51 )
return - V_49 ;
if ( ! V_185 . V_189 ) {
if ( F_90 ( & V_186 -> V_59 ) )
return F_91 ( V_3 , (union V_180 * ) & V_186 -> V_59 . V_25 [ 3 ] ,
V_77 ) ;
return F_91 ( V_3 , (union V_180 * ) & V_186 -> V_59 ,
V_51 ) ;
}
if ( V_185 . V_189 > V_190 )
return - V_49 ;
if ( F_90 ( & V_186 -> V_59 ) )
return F_92 ( V_3 , (union V_180 * ) & V_186 -> V_59 . V_25 [ 3 ] ,
V_77 , V_185 . V_191 , V_185 . V_189 , V_192 ) ;
return F_92 ( V_3 , (union V_180 * ) & V_186 -> V_59 ,
V_51 , V_185 . V_191 , V_185 . V_189 , V_192 ) ;
}
static int F_93 ( struct V_193 * V_194 ,
const struct V_4 * V_24 ,
const struct V_4 * V_26 , int V_195 )
{
struct V_196 * V_197 ;
struct V_198 V_199 ;
V_197 = & V_194 -> V_200 . V_201 ;
V_197 -> V_26 = * V_26 ;
V_197 -> V_24 = * V_24 ;
V_197 -> V_202 = F_94 ( V_94 ) ;
V_197 -> V_203 = F_94 ( V_195 ) ;
F_95 ( & V_199 , V_197 , sizeof( * V_197 ) ) ;
return F_96 ( & V_194 -> V_204 , & V_199 , sizeof( * V_197 ) ) ;
}
static int F_97 ( char * V_205 , struct V_1 * V_206 ,
const struct V_4 * V_24 , struct V_4 * V_26 ,
const struct V_112 * V_129 )
{
struct V_193 * V_194 ;
struct V_207 * V_208 ;
V_194 = F_98 () ;
if ( ! V_194 )
goto V_209;
V_208 = & V_194 -> V_204 ;
if ( F_99 ( V_208 ) )
goto V_210;
if ( F_93 ( V_194 , V_24 , V_26 , V_129 -> V_211 << 2 ) )
goto V_210;
if ( F_100 ( V_194 , V_129 ) )
goto V_210;
if ( F_101 ( V_194 , V_206 ) )
goto V_210;
if ( F_102 ( V_208 , V_205 ) )
goto V_210;
F_103 () ;
return 0 ;
V_210:
F_103 () ;
V_209:
memset ( V_205 , 0 , 16 ) ;
return 1 ;
}
static int F_104 ( char * V_205 , struct V_1 * V_206 ,
const struct V_2 * V_3 ,
const struct V_130 * V_157 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_26 , * V_24 ;
struct V_193 * V_194 ;
struct V_207 * V_208 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
if ( V_3 ) {
V_26 = & F_6 ( V_3 ) -> V_26 ;
V_24 = & V_3 -> V_68 ;
} else if ( V_157 ) {
V_26 = & F_74 ( V_157 ) -> V_172 ;
V_24 = & F_74 ( V_157 ) -> V_173 ;
} else {
const struct V_113 * V_212 = F_14 ( V_7 ) ;
V_26 = & V_212 -> V_26 ;
V_24 = & V_212 -> V_24 ;
}
V_194 = F_98 () ;
if ( ! V_194 )
goto V_209;
V_208 = & V_194 -> V_204 ;
if ( F_99 ( V_208 ) )
goto V_210;
if ( F_93 ( V_194 , V_24 , V_26 , V_7 -> V_203 ) )
goto V_210;
if ( F_100 ( V_194 , V_129 ) )
goto V_210;
if ( F_105 ( V_194 , V_7 , V_129 -> V_211 << 2 ) )
goto V_210;
if ( F_101 ( V_194 , V_206 ) )
goto V_210;
if ( F_102 ( V_208 , V_205 ) )
goto V_210;
F_103 () ;
return 0 ;
V_210:
F_103 () ;
V_209:
memset ( V_205 , 0 , 16 ) ;
return 1 ;
}
static int F_106 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_213 = NULL ;
struct V_1 * V_214 ;
const struct V_113 * V_212 = F_14 ( V_7 ) ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
int V_215 ;
T_3 V_216 [ 16 ] ;
V_214 = F_1 ( V_3 , & V_212 -> V_26 ) ;
V_213 = F_107 ( V_129 ) ;
if ( ! V_214 && ! V_213 )
return 0 ;
if ( V_214 && ! V_213 ) {
F_56 ( F_69 ( V_3 ) , V_217 ) ;
return 1 ;
}
if ( ! V_214 && V_213 ) {
F_56 ( F_69 ( V_3 ) , V_218 ) ;
return 1 ;
}
V_215 = F_104 ( V_216 ,
V_214 ,
NULL , NULL , V_7 ) ;
if ( V_215 || memcmp ( V_213 , V_216 , 16 ) != 0 ) {
F_108 ( L_2 ,
V_215 ? L_3 : L_4 ,
& V_212 -> V_26 , F_109 ( V_129 -> V_28 ) ,
& V_212 -> V_24 , F_109 ( V_129 -> V_27 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_110 ( struct V_6 * V_7 , T_2 V_132 , T_2 V_219 , T_2 V_220 ,
T_2 V_221 , T_2 V_222 , int V_223 ,
struct V_1 * V_206 , int V_224 , T_3 V_176 ,
T_2 V_225 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_112 * V_226 ;
struct V_6 * V_227 ;
struct V_44 V_45 ;
struct V_134 * V_134 = F_48 ( F_3 ( V_7 ) -> V_135 ) ;
struct V_2 * V_228 = V_134 -> V_229 . F_17 ;
unsigned int V_230 = sizeof( struct V_112 ) ;
struct V_8 * V_9 ;
T_4 * V_231 ;
if ( V_222 )
V_230 += V_232 ;
#ifdef F_26
if ( V_206 )
V_230 += V_233 ;
#endif
V_227 = F_111 ( V_234 + sizeof( struct V_113 ) + V_230 ,
V_235 ) ;
if ( V_227 == NULL )
return;
F_112 ( V_227 , V_234 + sizeof( struct V_113 ) + V_230 ) ;
V_226 = (struct V_112 * ) F_113 ( V_227 , V_230 ) ;
F_114 ( V_227 ) ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
V_226 -> V_27 = V_129 -> V_28 ;
V_226 -> V_28 = V_129 -> V_27 ;
V_226 -> V_211 = V_230 / 4 ;
V_226 -> V_132 = F_115 ( V_132 ) ;
V_226 -> V_236 = F_115 ( V_219 ) ;
V_226 -> V_219 = ! V_224 || ! V_129 -> V_219 ;
V_226 -> V_224 = V_224 ;
V_226 -> V_237 = F_116 ( V_220 ) ;
V_231 = ( T_4 * ) ( V_226 + 1 ) ;
if ( V_222 ) {
* V_231 ++ = F_115 ( ( V_238 << 24 ) | ( V_238 << 16 ) |
( V_239 << 8 ) | V_240 ) ;
* V_231 ++ = F_115 ( V_221 ) ;
* V_231 ++ = F_115 ( V_222 ) ;
}
#ifdef F_26
if ( V_206 ) {
* V_231 ++ = F_115 ( ( V_238 << 24 ) | ( V_238 << 16 ) |
( V_241 << 8 ) | V_242 ) ;
F_97 ( ( T_7 * ) V_231 , V_206 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_226 ) ;
}
#endif
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_24 = F_14 ( V_7 ) -> V_26 ;
V_45 . V_26 = F_14 ( V_7 ) -> V_24 ;
V_45 . V_54 = V_225 ;
V_227 -> V_243 = V_244 ;
V_227 -> V_245 = 0 ;
F_77 ( V_227 , & V_45 . V_26 , & V_45 . V_24 ) ;
V_45 . V_93 = V_94 ;
if ( F_117 ( & V_45 . V_24 ) && ! V_223 )
V_45 . V_95 = F_66 ( V_7 ) ;
else
V_45 . V_95 = V_223 ;
V_45 . V_96 = F_118 ( V_134 , V_7 -> V_246 ) ;
V_45 . V_98 = V_226 -> V_27 ;
V_45 . V_99 = V_226 -> V_28 ;
F_119 ( V_7 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_228 , & V_45 , NULL ) ;
if ( ! F_33 ( V_9 ) ) {
F_120 ( V_227 , V_9 ) ;
F_79 ( V_228 , V_227 , & V_45 , NULL , V_176 ) ;
F_82 ( V_134 , V_247 ) ;
if ( V_224 )
F_82 ( V_134 , V_248 ) ;
return;
}
F_84 ( V_227 ) ;
}
static void F_121 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
T_2 V_132 = 0 , V_236 = 0 ;
struct V_1 * V_206 = NULL ;
#ifdef F_26
const T_7 * V_213 = NULL ;
struct V_113 * V_249 = F_14 ( V_7 ) ;
unsigned char V_216 [ 16 ] ;
int V_215 ;
struct V_2 * V_250 = NULL ;
#endif
int V_223 ;
if ( V_129 -> V_224 )
return;
if ( ! F_122 ( V_7 ) )
return;
#ifdef F_26
V_213 = F_107 ( V_129 ) ;
if ( ! V_3 && V_213 ) {
V_250 = F_123 ( F_48 ( F_3 ( V_7 ) -> V_135 ) ,
& V_136 , & V_249 -> V_26 ,
V_129 -> V_28 , & V_249 -> V_24 ,
F_109 ( V_129 -> V_28 ) , F_66 ( V_7 ) ) ;
if ( ! V_250 )
return;
F_124 () ;
V_206 = F_1 ( V_250 , & V_249 -> V_26 ) ;
if ( ! V_206 )
goto V_251;
V_215 = F_104 ( V_216 , V_206 , NULL , NULL , V_7 ) ;
if ( V_215 || memcmp ( V_213 , V_216 , 16 ) != 0 )
goto V_251;
} else {
V_206 = V_3 ? F_1 ( V_3 , & V_249 -> V_26 ) : NULL ;
}
#endif
if ( V_129 -> V_219 )
V_132 = F_57 ( V_129 -> V_236 ) ;
else
V_236 = F_57 ( V_129 -> V_132 ) + V_129 -> V_252 + V_129 -> V_253 + V_7 -> V_203 -
( V_129 -> V_211 << 2 ) ;
V_223 = V_3 ? V_3 -> V_65 : 0 ;
F_110 ( V_7 , V_132 , V_236 , 0 , 0 , 0 , V_223 , V_206 , 1 , 0 , 0 ) ;
#ifdef F_26
V_251:
if ( V_250 ) {
F_125 () ;
F_72 ( V_250 ) ;
}
#endif
}
static void F_126 ( struct V_6 * V_7 , T_2 V_132 , T_2 V_219 ,
T_2 V_220 , T_2 V_221 , T_2 V_222 , int V_223 ,
struct V_1 * V_206 , T_3 V_176 ,
T_2 V_225 )
{
F_110 ( V_7 , V_132 , V_219 , V_220 , V_221 , V_222 , V_223 , V_206 , 0 , V_176 ,
V_225 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_254 * V_255 = F_53 ( V_3 ) ;
struct V_256 * V_257 = F_128 ( V_3 ) ;
F_126 ( V_7 , V_257 -> V_258 , V_257 -> V_259 ,
V_257 -> V_260 >> V_255 -> V_261 ,
V_262 + V_257 -> V_263 ,
V_257 -> V_264 , V_255 -> V_265 , F_129 ( V_257 ) ,
V_255 -> V_266 , ( V_255 -> V_267 << 12 ) ) ;
F_52 ( V_255 ) ;
}
static void F_130 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_130 * V_157 )
{
F_126 ( V_7 , ( V_3 -> V_18 == V_148 ) ?
F_58 ( V_157 ) -> V_147 + 1 : F_17 ( V_3 ) -> V_149 ,
F_58 ( V_157 ) -> V_268 ,
V_157 -> V_269 , V_262 , V_157 -> V_69 , V_3 -> V_65 ,
F_1 ( V_3 , & F_14 ( V_7 ) -> V_24 ) ,
0 , 0 ) ;
}
static struct V_2 * F_131 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_130 * V_157 , * * V_158 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_2 * V_270 ;
V_157 = F_65 ( V_3 , & V_158 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , F_66 ( V_7 ) ) ;
if ( V_157 )
return F_132 ( V_3 , V_7 , V_157 , V_158 , false ) ;
V_270 = F_133 ( F_69 ( V_3 ) , & V_136 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 , F_109 ( V_129 -> V_27 ) , F_66 ( V_7 ) ) ;
if ( V_270 ) {
if ( V_270 -> V_18 != V_139 ) {
F_54 ( V_270 ) ;
return V_270 ;
}
F_52 ( F_53 ( V_270 ) ) ;
return NULL ;
}
#ifdef F_134
if ( ! V_129 -> V_252 )
V_3 = F_135 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_136 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_271 V_272 ;
struct V_130 * V_157 ;
struct V_168 * V_169 ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 = F_17 ( V_3 ) ;
T_1 V_273 = F_137 ( V_7 ) -> V_274 ;
struct V_8 * V_9 = NULL ;
struct V_166 V_167 = { . V_203 = - 1 } ;
bool V_275 = false , V_131 ;
struct V_44 V_45 ;
int V_47 ;
if ( V_7 -> V_202 == F_116 ( V_276 ) )
return F_138 ( V_3 , V_7 ) ;
if ( ! F_122 ( V_7 ) )
goto V_277;
if ( ( V_278 == 2 ||
F_139 ( V_3 ) ) && ! V_273 ) {
V_275 = F_140 ( V_3 , V_7 , L_5 ) ;
if ( ! V_275 )
goto V_277;
}
if ( F_141 ( V_3 ) && F_142 ( V_3 ) > 1 ) {
F_56 ( F_69 ( V_3 ) , V_279 ) ;
goto V_277;
}
V_157 = F_143 ( & V_280 ) ;
if ( V_157 == NULL )
goto V_277;
#ifdef F_26
F_58 ( V_157 ) -> V_84 = & V_281 ;
#endif
F_144 ( & V_272 ) ;
V_272 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_272 . V_282 = V_41 -> V_66 . V_282 ;
F_145 ( V_7 , & V_272 , 0 , V_275 ? NULL : & V_167 ) ;
if ( V_275 && ! V_272 . V_283 )
F_144 ( & V_272 ) ;
V_272 . V_284 = V_272 . V_283 ;
F_146 ( V_157 , & V_272 , V_7 ) ;
V_169 = F_74 ( V_157 ) ;
V_169 -> V_173 = F_14 ( V_7 ) -> V_26 ;
V_169 -> V_172 = F_14 ( V_7 ) -> V_24 ;
if ( ! V_275 || V_272 . V_284 )
F_147 ( V_157 , V_7 , F_69 ( V_3 ) ) ;
V_169 -> V_285 = V_3 -> V_65 ;
V_169 -> V_286 = F_148 ( V_3 , V_7 ) ;
if ( ! V_3 -> V_65 &&
F_22 ( & V_169 -> V_173 ) & V_63 )
V_169 -> V_285 = F_66 ( V_7 ) ;
if ( ! V_273 ) {
if ( F_149 ( V_3 , V_7 ) ||
V_39 -> V_287 . V_288 . V_289 || V_39 -> V_287 . V_288 . V_290 ||
V_39 -> V_287 . V_288 . V_291 || V_39 -> V_287 . V_288 . V_292 ||
V_39 -> V_174 ) {
F_150 ( & V_7 -> V_293 ) ;
V_169 -> V_175 = V_7 ;
}
if ( V_275 ) {
V_273 = F_151 ( V_3 , V_7 , & V_157 -> V_294 ) ;
V_157 -> V_295 = V_272 . V_284 ;
goto V_296;
}
if ( V_272 . V_283 &&
V_105 . V_106 &&
( V_9 = F_75 ( V_3 , & V_45 , V_157 ) ) != NULL ) {
if ( ! F_152 ( V_157 , V_9 , true ) ) {
F_56 ( F_69 ( V_3 ) , V_297 ) ;
goto V_298;
}
}
else if ( ! V_278 &&
( V_299 - F_153 ( V_3 ) <
( V_299 >> 2 ) ) &&
! F_152 ( V_157 , V_9 , false ) ) {
F_154 ( V_300 L_6 ,
& V_169 -> V_173 , F_109 ( F_15 ( V_7 ) -> V_28 ) ) ;
goto V_298;
}
V_273 = F_12 ( V_7 ) ;
}
V_296:
if ( F_155 ( V_3 , V_7 , V_157 ) )
goto V_298;
if ( ! V_9 && ( V_9 = F_75 ( V_3 , & V_45 , V_157 ) ) == NULL )
goto V_301;
F_58 ( V_157 ) -> V_147 = V_273 ;
F_58 ( V_157 ) -> V_302 = V_262 ;
F_156 ( V_157 , V_3 , V_9 ) ;
V_131 = ! V_275 &&
F_157 ( V_3 , V_7 , V_157 , & V_167 , V_9 ) ;
V_47 = F_73 ( V_3 , V_9 , & V_45 , V_157 ,
F_158 ( V_7 ) , & V_167 ) ;
if ( ! V_131 ) {
if ( V_47 || V_275 )
goto V_301;
F_58 ( V_157 ) -> V_303 = NULL ;
F_159 ( V_3 , V_157 , V_304 ) ;
}
return 0 ;
V_298:
F_160 ( V_9 ) ;
V_301:
F_161 ( V_157 ) ;
V_277:
F_56 ( F_69 ( V_3 ) , V_159 ) ;
return 0 ;
}
static struct V_2 * F_162 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_130 * V_157 ,
struct V_8 * V_9 )
{
struct V_168 * V_169 ;
struct V_38 * V_305 , * V_39 = F_6 ( V_3 ) ;
struct V_306 * V_307 ;
struct V_34 * V_308 ;
struct V_40 * V_309 ;
struct V_2 * V_310 ;
#ifdef F_26
struct V_1 * V_206 ;
#endif
struct V_44 V_45 ;
if ( V_7 -> V_202 == F_116 ( V_276 ) ) {
V_310 = F_163 ( V_3 , V_7 , V_157 , V_9 ) ;
if ( V_310 == NULL )
return NULL ;
V_307 = (struct V_306 * ) V_310 ;
F_5 ( V_310 ) -> V_311 = & V_307 -> V_312 ;
V_308 = F_5 ( V_310 ) ;
V_305 = F_6 ( V_310 ) ;
V_309 = F_17 ( V_310 ) ;
memcpy ( V_305 , V_39 , sizeof( struct V_38 ) ) ;
F_28 ( V_308 -> V_313 , & V_310 -> V_68 ) ;
F_28 ( V_308 -> V_90 , & V_305 -> V_26 ) ;
V_310 -> V_92 = V_305 -> V_26 ;
F_8 ( V_310 ) -> V_20 = & V_21 ;
V_310 -> V_82 = V_83 ;
#ifdef F_26
V_309 -> V_84 = & V_85 ;
#endif
V_305 -> V_314 = NULL ;
V_305 -> V_315 = NULL ;
V_305 -> V_316 = NULL ;
V_305 -> V_101 = NULL ;
V_305 -> V_317 = F_66 ( V_7 ) ;
V_305 -> V_318 = F_14 ( V_7 ) -> V_143 ;
V_305 -> V_319 = F_164 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_174 )
V_305 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
F_45 ( V_310 , F_8 ( V_310 ) -> V_122 ) ;
return V_310 ;
}
V_169 = F_74 ( V_157 ) ;
if ( F_141 ( V_3 ) )
goto V_320;
if ( ! V_9 ) {
V_9 = F_75 ( V_3 , & V_45 , V_157 ) ;
if ( ! V_9 )
goto V_142;
}
V_310 = F_165 ( V_3 , V_157 , V_7 ) ;
if ( V_310 == NULL )
goto V_321;
V_310 -> V_103 = V_104 ;
F_35 ( V_310 , V_9 , NULL , NULL ) ;
F_2 ( V_310 , V_7 ) ;
V_307 = (struct V_306 * ) V_310 ;
F_5 ( V_310 ) -> V_311 = & V_307 -> V_312 ;
V_309 = F_17 ( V_310 ) ;
V_308 = F_5 ( V_310 ) ;
V_305 = F_6 ( V_310 ) ;
memcpy ( V_305 , V_39 , sizeof( struct V_38 ) ) ;
V_310 -> V_68 = V_169 -> V_173 ;
V_305 -> V_26 = V_169 -> V_172 ;
V_310 -> V_92 = V_169 -> V_172 ;
V_310 -> V_65 = V_169 -> V_285 ;
V_308 -> V_322 = NULL ;
V_305 -> V_314 = NULL ;
V_305 -> V_315 = NULL ;
V_305 -> V_287 . V_323 = V_39 -> V_287 . V_323 ;
V_305 -> V_316 = NULL ;
if ( V_169 -> V_175 != NULL ) {
V_305 -> V_316 = F_166 ( V_169 -> V_175 ,
F_167 ( V_3 , V_235 ) ) ;
F_168 ( V_169 -> V_175 ) ;
V_169 -> V_175 = NULL ;
if ( V_305 -> V_316 )
F_169 ( V_305 -> V_316 , V_310 ) ;
}
V_305 -> V_101 = NULL ;
V_305 -> V_317 = F_66 ( V_7 ) ;
V_305 -> V_318 = F_14 ( V_7 ) -> V_143 ;
V_305 -> V_319 = F_164 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_174 )
V_305 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_101 )
V_305 -> V_101 = F_170 ( V_310 , V_39 -> V_101 ) ;
F_8 ( V_310 ) -> V_74 = 0 ;
if ( V_305 -> V_101 )
F_8 ( V_310 ) -> V_74 = ( V_305 -> V_101 -> V_109 +
V_305 -> V_101 -> V_108 ) ;
F_45 ( V_310 , F_44 ( V_9 ) ) ;
V_309 -> V_324 = F_171 ( V_9 ) ;
if ( F_17 ( V_3 ) -> V_66 . V_282 &&
F_17 ( V_3 ) -> V_66 . V_282 < V_309 -> V_324 )
V_309 -> V_324 = F_17 ( V_3 ) -> V_66 . V_282 ;
F_172 ( V_310 ) ;
V_308 -> V_313 = V_308 -> V_90 = V_102 ;
V_308 -> V_91 = V_102 ;
#ifdef F_26
V_206 = F_1 ( V_3 , & V_310 -> V_68 ) ;
if ( V_206 != NULL ) {
F_92 ( V_310 , (union V_180 * ) & V_310 -> V_68 ,
V_51 , V_206 -> V_206 , V_206 -> V_325 ,
F_167 ( V_3 , V_235 ) ) ;
}
#endif
if ( F_173 ( V_3 , V_310 ) < 0 ) {
F_174 ( V_310 ) ;
F_70 ( V_310 ) ;
goto V_142;
}
F_10 ( V_310 , NULL ) ;
return V_310 ;
V_320:
F_56 ( F_69 ( V_3 ) , V_279 ) ;
V_321:
F_160 ( V_9 ) ;
V_142:
F_56 ( F_69 ( V_3 ) , V_159 ) ;
return NULL ;
}
static int V_87 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_6 * V_326 = NULL ;
if ( V_7 -> V_202 == F_116 ( V_276 ) )
return V_83 ( V_3 , V_7 ) ;
#ifdef F_26
if ( F_106 ( V_3 , V_7 ) )
goto V_327;
#endif
if ( F_175 ( V_3 , V_7 ) )
goto V_327;
if ( V_39 -> V_287 . V_323 )
V_326 = F_166 ( V_7 , F_167 ( V_3 , V_235 ) ) ;
if ( V_3 -> V_18 == V_328 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_176 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_153 -> V_329 ( V_9 , V_39 -> V_16 ) == NULL ) {
F_160 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_177 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_203 ) ;
if ( V_326 )
goto V_330;
return 0 ;
}
if ( V_7 -> V_203 < F_178 ( V_7 ) || F_179 ( V_7 ) )
goto V_331;
if ( V_3 -> V_18 == V_148 ) {
struct V_2 * V_270 = F_131 ( V_3 , V_7 ) ;
if ( ! V_270 )
goto V_327;
if ( V_270 != V_3 ) {
F_176 ( V_270 , V_7 ) ;
if ( F_180 ( V_3 , V_270 , V_7 ) )
goto V_332;
if ( V_326 )
F_181 ( V_326 ) ;
return 0 ;
}
} else
F_176 ( V_3 , V_7 ) ;
if ( F_182 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_203 ) )
goto V_332;
if ( V_326 )
goto V_330;
return 0 ;
V_332:
F_121 ( V_3 , V_7 ) ;
V_327:
if ( V_326 )
F_181 ( V_326 ) ;
F_84 ( V_7 ) ;
return 0 ;
V_331:
F_82 ( F_69 ( V_3 ) , V_333 ) ;
F_82 ( F_69 ( V_3 ) , V_334 ) ;
goto V_327;
V_330:
V_41 = F_17 ( V_3 ) ;
if ( F_137 ( V_326 ) -> V_335 == V_41 -> V_268 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_120 | V_119 ) ) ) {
if ( V_39 -> V_287 . V_288 . V_289 || V_39 -> V_287 . V_288 . V_290 )
V_39 -> V_317 = F_66 ( V_326 ) ;
if ( V_39 -> V_287 . V_288 . V_291 || V_39 -> V_287 . V_288 . V_292 )
V_39 -> V_318 = F_14 ( V_326 ) -> V_143 ;
if ( V_39 -> V_287 . V_288 . V_336 || V_39 -> V_287 . V_288 . V_337 )
V_39 -> V_319 = F_164 ( F_14 ( V_326 ) ) ;
if ( V_39 -> V_174 )
V_39 -> V_71 = V_58 ( F_14 ( V_326 ) ) ;
if ( F_149 ( V_3 , V_326 ) ) {
F_169 ( V_326 , V_3 ) ;
V_326 = F_183 ( & V_39 -> V_316 , V_326 ) ;
} else {
F_181 ( V_326 ) ;
V_326 = F_183 ( & V_39 -> V_316 , NULL ) ;
}
}
F_84 ( V_326 ) ;
return 0 ;
}
static int F_184 ( struct V_6 * V_7 )
{
const struct V_112 * V_129 ;
const struct V_113 * V_127 ;
struct V_2 * V_3 ;
int V_338 ;
struct V_134 * V_134 = F_48 ( V_7 -> V_135 ) ;
if ( V_7 -> V_339 != V_340 )
goto V_341;
F_82 ( V_134 , V_342 ) ;
if ( ! F_185 ( V_7 , sizeof( struct V_112 ) ) )
goto V_341;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_211 < sizeof( struct V_112 ) / 4 )
goto V_343;
if ( ! F_185 ( V_7 , V_129 -> V_211 * 4 ) )
goto V_341;
if ( F_186 ( V_7 , V_94 , V_344 ) )
goto V_345;
V_129 = F_15 ( V_7 ) ;
V_127 = F_14 ( V_7 ) ;
F_137 ( V_7 ) -> V_132 = F_57 ( V_129 -> V_132 ) ;
F_137 ( V_7 ) -> V_335 = ( F_137 ( V_7 ) -> V_132 + V_129 -> V_252 + V_129 -> V_253 +
V_7 -> V_203 - V_129 -> V_211 * 4 ) ;
F_137 ( V_7 ) -> V_236 = F_57 ( V_129 -> V_236 ) ;
F_137 ( V_7 ) -> V_274 = 0 ;
F_137 ( V_7 ) -> V_346 = F_187 ( V_127 ) ;
F_137 ( V_7 ) -> V_347 = 0 ;
V_3 = F_188 ( & V_136 , V_7 , V_129 -> V_28 , V_129 -> V_27 ) ;
if ( ! V_3 )
goto V_348;
V_349:
if ( V_3 -> V_18 == V_139 )
goto V_350;
if ( V_127 -> V_143 < F_6 ( V_3 ) -> V_144 ) {
F_56 ( V_134 , V_145 ) ;
goto V_351;
}
if ( ! F_189 ( V_3 , V_352 , V_7 ) )
goto V_351;
if ( F_175 ( V_3 , V_7 ) )
goto V_351;
F_190 ( V_3 , V_7 ) ;
V_7 -> V_135 = NULL ;
F_191 ( V_3 ) ;
V_338 = 0 ;
if ( ! F_55 ( V_3 ) ) {
#ifdef F_192
struct V_40 * V_41 = F_17 ( V_3 ) ;
if ( ! V_41 -> V_353 . V_354 && V_41 -> V_353 . V_355 )
V_41 -> V_353 . V_354 = F_193 () ;
if ( V_41 -> V_353 . V_354 )
V_338 = V_87 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_194 ( V_3 , V_7 ) )
V_338 = V_87 ( V_3 , V_7 ) ;
}
} else if ( F_195 ( F_196 ( V_3 , V_7 ,
V_3 -> V_356 + V_3 -> V_357 ) ) ) {
F_71 ( V_3 ) ;
F_56 ( V_134 , V_358 ) ;
goto V_351;
}
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
return V_338 ? - 1 : 0 ;
V_348:
if ( ! F_189 ( NULL , V_352 , V_7 ) )
goto V_341;
if ( V_7 -> V_203 < ( V_129 -> V_211 << 2 ) || F_179 ( V_7 ) ) {
V_345:
F_82 ( V_134 , V_333 ) ;
V_343:
F_82 ( V_134 , V_334 ) ;
} else {
F_121 ( NULL , V_7 ) ;
}
V_341:
F_84 ( V_7 ) ;
return 0 ;
V_351:
F_72 ( V_3 ) ;
goto V_341;
V_350:
if ( ! F_189 ( NULL , V_352 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_341;
}
if ( V_7 -> V_203 < ( V_129 -> V_211 << 2 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_343;
}
if ( F_179 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_345;
}
switch ( F_197 ( F_53 ( V_3 ) , V_7 , V_129 ) ) {
case V_359 :
{
struct V_2 * V_360 ;
V_360 = F_123 ( F_48 ( V_7 -> V_135 ) , & V_136 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 ,
F_109 ( V_129 -> V_27 ) , F_66 ( V_7 ) ) ;
if ( V_360 != NULL ) {
struct V_254 * V_255 = F_53 ( V_3 ) ;
F_198 ( V_255 , & V_105 ) ;
F_52 ( V_255 ) ;
V_3 = V_360 ;
goto V_349;
}
}
case V_361 :
F_127 ( V_3 , V_7 ) ;
break;
case V_362 :
goto V_348;
case V_363 :
;
}
goto V_341;
}
static void F_199 ( struct V_6 * V_7 )
{
const struct V_113 * V_127 ;
const struct V_112 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_339 != V_340 )
return;
if ( ! F_185 ( V_7 , F_200 ( V_7 ) + sizeof( struct V_112 ) ) )
return;
V_127 = F_14 ( V_7 ) ;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_211 < sizeof( struct V_112 ) / 4 )
return;
V_3 = F_133 ( F_48 ( V_7 -> V_135 ) , & V_136 ,
& V_127 -> V_26 , V_129 -> V_28 ,
& V_127 -> V_24 , F_109 ( V_129 -> V_27 ) ,
F_66 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_364 = V_365 ;
if ( V_3 -> V_18 != V_139 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
if ( V_9 )
V_9 = F_201 ( V_9 , F_6 ( V_3 ) -> V_16 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_202 ( V_7 , V_9 ) ;
}
}
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = F_8 ( V_3 ) ;
F_204 ( V_3 ) ;
V_37 -> V_20 = & V_86 ;
#ifdef F_26
F_17 ( V_3 ) -> V_84 = & V_88 ;
#endif
return 0 ;
}
static void F_205 ( struct V_2 * V_3 )
{
F_206 ( V_3 ) ;
F_207 ( V_3 ) ;
}
static void F_208 ( struct V_366 * V_132 ,
const struct V_2 * V_3 , struct V_130 * V_157 , int V_367 , T_8 V_368 )
{
int V_369 = V_157 -> V_370 - V_371 ;
const struct V_4 * V_372 = & F_74 ( V_157 ) -> V_172 ;
const struct V_4 * V_27 = & F_74 ( V_157 ) -> V_173 ;
if ( V_369 < 0 )
V_369 = 0 ;
F_209 ( V_132 ,
L_7
L_8 ,
V_367 ,
V_372 -> V_25 [ 0 ] , V_372 -> V_25 [ 1 ] ,
V_372 -> V_25 [ 2 ] , V_372 -> V_25 [ 3 ] ,
F_74 ( V_157 ) -> V_373 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] ,
F_109 ( F_74 ( V_157 ) -> V_374 ) ,
V_160 ,
0 , 0 ,
1 ,
F_210 ( V_369 ) ,
V_157 -> V_375 ,
F_211 ( F_212 ( V_132 ) , V_368 ) ,
0 ,
0 ,
0 , V_157 ) ;
}
static void F_213 ( struct V_366 * V_132 , struct V_2 * V_376 , int V_367 )
{
const struct V_4 * V_27 , * V_372 ;
T_9 V_377 , V_378 ;
int V_379 ;
unsigned long V_380 ;
const struct V_34 * V_35 = F_5 ( V_376 ) ;
const struct V_40 * V_41 = F_17 ( V_376 ) ;
const struct V_36 * V_37 = F_8 ( V_376 ) ;
struct V_381 * V_382 = V_37 -> V_383 . V_382 ;
V_27 = & V_376 -> V_68 ;
V_372 = & V_376 -> V_92 ;
V_377 = F_109 ( V_35 -> V_114 ) ;
V_378 = F_109 ( V_35 -> V_100 ) ;
if ( V_37 -> V_384 == V_385 ) {
V_379 = 1 ;
V_380 = V_37 -> V_386 ;
} else if ( V_37 -> V_384 == V_387 ) {
V_379 = 4 ;
V_380 = V_37 -> V_386 ;
} else if ( F_214 ( & V_376 -> V_388 ) ) {
V_379 = 2 ;
V_380 = V_376 -> V_388 . V_370 ;
} else {
V_379 = 0 ;
V_380 = V_371 ;
}
F_209 ( V_132 ,
L_7
L_9 ,
V_367 ,
V_372 -> V_25 [ 0 ] , V_372 -> V_25 [ 1 ] ,
V_372 -> V_25 [ 2 ] , V_372 -> V_25 [ 3 ] , V_378 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_377 ,
V_376 -> V_18 ,
V_41 -> V_70 - V_41 -> V_133 ,
( V_376 -> V_18 == V_148 ) ? V_376 -> V_389 : ( V_41 -> V_268 - V_41 -> V_390 ) ,
V_379 ,
F_215 ( V_380 - V_371 ) ,
V_37 -> V_391 ,
F_211 ( F_212 ( V_132 ) , F_216 ( V_376 ) ) ,
V_37 -> V_392 ,
F_217 ( V_376 ) ,
F_218 ( & V_376 -> V_393 ) , V_376 ,
F_210 ( V_37 -> V_394 ) ,
F_210 ( V_37 -> V_395 . V_396 ) ,
( V_37 -> V_395 . V_397 << 1 ) | V_37 -> V_395 . V_398 ,
V_41 -> V_399 ,
V_376 -> V_18 == V_148 ?
( V_382 ? V_382 -> V_400 : 0 ) :
( F_219 ( V_41 ) ? - 1 : V_41 -> V_401 )
) ;
}
static void F_220 ( struct V_366 * V_132 ,
struct V_254 * V_255 , int V_367 )
{
const struct V_4 * V_27 , * V_372 ;
T_9 V_377 , V_378 ;
T_10 V_402 = V_255 -> V_403 - F_221 () ;
V_27 = & V_255 -> V_404 ;
V_372 = & V_255 -> V_405 ;
V_377 = F_109 ( V_255 -> V_406 ) ;
V_378 = F_109 ( V_255 -> V_407 ) ;
F_209 ( V_132 ,
L_7
L_10 ,
V_367 ,
V_372 -> V_25 [ 0 ] , V_372 -> V_25 [ 1 ] ,
V_372 -> V_25 [ 2 ] , V_372 -> V_25 [ 3 ] , V_378 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_377 ,
V_255 -> V_408 , 0 , 0 ,
3 , F_215 ( V_402 ) , 0 , 0 , 0 , 0 ,
F_218 ( & V_255 -> V_409 ) , V_255 ) ;
}
static int F_222 ( struct V_366 * V_132 , void * V_410 )
{
struct V_411 * V_412 ;
struct V_2 * V_3 = V_410 ;
if ( V_410 == V_413 ) {
F_223 ( V_132 ,
L_11
L_12
L_13
L_14
L_15 ) ;
goto V_142;
}
V_412 = V_132 -> V_414 ;
switch ( V_412 -> V_415 ) {
case V_416 :
case V_417 :
if ( V_3 -> V_18 == V_139 )
F_220 ( V_132 , V_410 , V_412 -> V_418 ) ;
else
F_213 ( V_132 , V_410 , V_412 -> V_418 ) ;
break;
case V_419 :
F_208 ( V_132 , V_412 -> V_420 , V_410 , V_412 -> V_418 , V_412 -> V_368 ) ;
break;
}
V_142:
return 0 ;
}
int T_11 F_224 ( struct V_134 * V_134 )
{
return F_225 ( V_134 , & V_421 ) ;
}
void F_226 ( struct V_134 * V_134 )
{
F_227 ( V_134 , & V_421 ) ;
}
static void F_228 ( struct V_2 * V_3 , int V_422 )
{
struct V_34 * V_35 = F_5 ( V_3 ) ;
F_229 ( V_3 , F_230 ( struct V_34 , V_311 ) ) ;
V_422 -= F_230 ( struct V_34 , V_311 ) + sizeof( V_35 -> V_311 ) ;
memset ( & V_35 -> V_311 + 1 , 0 , V_422 ) ;
}
static int T_11 F_231 ( struct V_134 * V_134 )
{
return F_232 ( & V_134 -> V_229 . F_17 , V_423 ,
V_424 , V_94 , V_134 ) ;
}
static void T_12 F_233 ( struct V_134 * V_134 )
{
F_234 ( V_134 -> V_229 . F_17 ) ;
}
static void T_12 F_235 ( struct V_425 * V_426 )
{
F_236 ( & V_136 , & V_105 , V_51 ) ;
}
int T_13 F_237 ( void )
{
int V_338 ;
V_338 = F_238 ( & V_427 , V_94 ) ;
if ( V_338 )
goto V_142;
V_338 = F_239 ( & V_428 ) ;
if ( V_338 )
goto V_429;
V_338 = F_240 ( & V_430 ) ;
if ( V_338 )
goto V_431;
V_142:
return V_338 ;
V_431:
F_241 ( & V_428 ) ;
V_429:
F_242 ( & V_427 , V_94 ) ;
goto V_142;
}
void F_243 ( void )
{
F_244 ( & V_430 ) ;
F_241 ( & V_428 ) ;
F_242 ( & V_427 , V_94 ) ;
}
