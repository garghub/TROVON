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
T_1 V_130 ;
struct V_131 * V_131 = F_48 ( V_7 -> V_132 ) ;
V_3 = F_49 ( V_131 , & V_133 , & V_127 -> V_24 ,
V_129 -> V_27 , & V_127 -> V_26 , V_129 -> V_28 , V_7 -> V_132 -> V_134 ) ;
if ( V_3 == NULL ) {
F_50 ( V_131 , F_51 ( V_7 -> V_132 ) ,
V_135 ) ;
return;
}
if ( V_3 -> V_18 == V_136 ) {
F_52 ( F_53 ( V_3 ) ) ;
return;
}
F_54 ( V_3 ) ;
if ( F_55 ( V_3 ) && type != V_137 )
F_56 ( V_131 , V_138 ) ;
if ( V_3 -> V_18 == V_19 )
goto V_139;
if ( F_14 ( V_7 ) -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_56 ( V_131 , V_142 ) ;
goto V_139;
}
V_41 = F_17 ( V_3 ) ;
V_130 = F_57 ( V_129 -> V_130 ) ;
if ( V_3 -> V_18 != V_143 &&
! F_58 ( V_130 , V_41 -> V_144 , V_41 -> V_145 ) ) {
F_56 ( V_131 , V_146 ) ;
goto V_139;
}
V_39 = F_6 ( V_3 ) ;
if ( type == V_147 ) {
struct V_8 * V_9 = F_59 ( V_3 , V_39 -> V_148 ) ;
if ( V_9 )
V_9 -> V_149 -> V_150 ( V_9 , V_3 , V_7 ) ;
goto V_139;
}
if ( type == V_137 ) {
if ( V_3 -> V_18 == V_143 )
goto V_139;
if ( ! F_60 ( V_3 ) )
goto V_139;
V_41 -> V_121 = F_57 ( V_126 ) ;
if ( ! F_55 ( V_3 ) )
F_42 ( V_3 ) ;
else if ( ! F_61 ( V_151 ,
& V_41 -> V_152 ) )
F_62 ( V_3 ) ;
goto V_139;
}
F_63 ( type , V_124 , & V_47 ) ;
switch ( V_3 -> V_18 ) {
struct V_153 * V_154 , * * V_155 ;
case V_143 :
if ( F_55 ( V_3 ) )
goto V_139;
V_154 = F_64 ( V_3 , & V_155 , V_129 -> V_27 , & V_127 -> V_24 ,
& V_127 -> V_26 , F_65 ( V_7 ) ) ;
if ( ! V_154 )
goto V_139;
F_66 ( V_154 -> V_3 != NULL ) ;
if ( V_130 != F_67 ( V_154 ) -> V_156 ) {
F_56 ( V_131 , V_146 ) ;
goto V_139;
}
F_68 ( V_3 , V_154 , V_155 ) ;
F_56 ( F_69 ( V_3 ) , V_157 ) ;
goto V_139;
case V_115 :
case V_158 :
if ( ! F_55 ( V_3 ) ) {
V_3 -> V_159 = V_47 ;
V_3 -> V_160 ( V_3 ) ;
F_70 ( V_3 ) ;
} else
V_3 -> V_161 = V_47 ;
goto V_139;
}
if ( ! F_55 ( V_3 ) && V_39 -> V_162 ) {
V_3 -> V_159 = V_47 ;
V_3 -> V_160 ( V_3 ) ;
} else
V_3 -> V_161 = V_47 ;
V_139:
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
}
static int F_73 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_153 * V_154 ,
T_5 V_163 )
{
struct V_164 * V_165 = F_74 ( V_154 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_6 * V_7 ;
int V_47 = - V_166 ;
if ( ! V_9 && ( V_9 = F_75 ( V_3 , V_45 , V_154 ) ) == NULL )
goto V_167;
V_7 = F_76 ( V_3 , V_9 , V_154 , NULL ) ;
if ( V_7 ) {
F_77 ( V_7 , & V_165 -> V_168 ,
& V_165 -> V_169 ) ;
V_45 -> V_24 = V_165 -> V_169 ;
if ( V_39 -> V_170 && ( V_165 -> V_171 != NULL ) )
V_45 -> V_54 = V_58 ( F_14 ( V_165 -> V_171 ) ) ;
F_78 ( V_7 , V_163 ) ;
V_47 = F_79 ( V_3 , V_7 , V_45 , V_39 -> V_101 , V_39 -> V_172 ) ;
V_47 = F_80 ( V_47 ) ;
}
V_167:
return V_47 ;
}
static int F_81 ( struct V_2 * V_3 , struct V_153 * V_154 )
{
struct V_44 V_45 ;
int V_173 ;
V_173 = F_73 ( V_3 , NULL , & V_45 , V_154 , 0 ) ;
if ( ! V_173 ) {
F_82 ( F_69 ( V_3 ) , V_174 ) ;
F_56 ( F_69 ( V_3 ) , V_175 ) ;
}
return V_173 ;
}
static void F_83 ( struct V_153 * V_154 )
{
F_84 ( F_74 ( V_154 ) -> V_171 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_85 ( V_3 , (union V_176 * ) V_5 , V_51 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_2 * V_177 )
{
return F_1 ( V_3 , & V_177 -> V_68 ) ;
}
static struct V_1 * F_87 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
return F_1 ( V_3 , & F_74 ( V_154 ) -> V_169 ) ;
}
static int F_88 ( struct V_2 * V_3 , char T_6 * V_178 ,
int V_179 )
{
struct V_180 V_181 ;
struct V_32 * V_182 = (struct V_32 * ) & V_181 . V_183 ;
if ( V_179 < sizeof( V_181 ) )
return - V_49 ;
if ( F_89 ( & V_181 , V_178 , sizeof( V_181 ) ) )
return - V_184 ;
if ( V_182 -> V_50 != V_51 )
return - V_49 ;
if ( ! V_181 . V_185 ) {
if ( F_90 ( & V_182 -> V_59 ) )
return F_91 ( V_3 , (union V_176 * ) & V_182 -> V_59 . V_25 [ 3 ] ,
V_77 ) ;
return F_91 ( V_3 , (union V_176 * ) & V_182 -> V_59 ,
V_51 ) ;
}
if ( V_181 . V_185 > V_186 )
return - V_49 ;
if ( F_90 ( & V_182 -> V_59 ) )
return F_92 ( V_3 , (union V_176 * ) & V_182 -> V_59 . V_25 [ 3 ] ,
V_77 , V_181 . V_187 , V_181 . V_185 , V_188 ) ;
return F_92 ( V_3 , (union V_176 * ) & V_182 -> V_59 ,
V_51 , V_181 . V_187 , V_181 . V_185 , V_188 ) ;
}
static int F_93 ( struct V_189 * V_190 ,
const struct V_4 * V_24 ,
const struct V_4 * V_26 , int V_191 )
{
struct V_192 * V_193 ;
struct V_194 V_195 ;
V_193 = & V_190 -> V_196 . V_197 ;
V_193 -> V_26 = * V_26 ;
V_193 -> V_24 = * V_24 ;
V_193 -> V_198 = F_94 ( V_94 ) ;
V_193 -> V_199 = F_94 ( V_191 ) ;
F_95 ( & V_195 , V_193 , sizeof( * V_193 ) ) ;
return F_96 ( & V_190 -> V_200 , & V_195 , sizeof( * V_193 ) ) ;
}
static int F_97 ( char * V_201 , struct V_1 * V_202 ,
const struct V_4 * V_24 , struct V_4 * V_26 ,
const struct V_112 * V_129 )
{
struct V_189 * V_190 ;
struct V_203 * V_204 ;
V_190 = F_98 () ;
if ( ! V_190 )
goto V_205;
V_204 = & V_190 -> V_200 ;
if ( F_99 ( V_204 ) )
goto V_206;
if ( F_93 ( V_190 , V_24 , V_26 , V_129 -> V_207 << 2 ) )
goto V_206;
if ( F_100 ( V_190 , V_129 ) )
goto V_206;
if ( F_101 ( V_190 , V_202 ) )
goto V_206;
if ( F_102 ( V_204 , V_201 ) )
goto V_206;
F_103 () ;
return 0 ;
V_206:
F_103 () ;
V_205:
memset ( V_201 , 0 , 16 ) ;
return 1 ;
}
static int F_104 ( char * V_201 , struct V_1 * V_202 ,
const struct V_2 * V_3 ,
const struct V_153 * V_154 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_26 , * V_24 ;
struct V_189 * V_190 ;
struct V_203 * V_204 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
if ( V_3 ) {
V_26 = & F_6 ( V_3 ) -> V_26 ;
V_24 = & V_3 -> V_68 ;
} else if ( V_154 ) {
V_26 = & F_74 ( V_154 ) -> V_168 ;
V_24 = & F_74 ( V_154 ) -> V_169 ;
} else {
const struct V_113 * V_208 = F_14 ( V_7 ) ;
V_26 = & V_208 -> V_26 ;
V_24 = & V_208 -> V_24 ;
}
V_190 = F_98 () ;
if ( ! V_190 )
goto V_205;
V_204 = & V_190 -> V_200 ;
if ( F_99 ( V_204 ) )
goto V_206;
if ( F_93 ( V_190 , V_24 , V_26 , V_7 -> V_199 ) )
goto V_206;
if ( F_100 ( V_190 , V_129 ) )
goto V_206;
if ( F_105 ( V_190 , V_7 , V_129 -> V_207 << 2 ) )
goto V_206;
if ( F_101 ( V_190 , V_202 ) )
goto V_206;
if ( F_102 ( V_204 , V_201 ) )
goto V_206;
F_103 () ;
return 0 ;
V_206:
F_103 () ;
V_205:
memset ( V_201 , 0 , 16 ) ;
return 1 ;
}
static int F_106 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_209 = NULL ;
struct V_1 * V_210 ;
const struct V_113 * V_208 = F_14 ( V_7 ) ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
int V_211 ;
T_3 V_212 [ 16 ] ;
V_210 = F_1 ( V_3 , & V_208 -> V_26 ) ;
V_209 = F_107 ( V_129 ) ;
if ( ! V_210 && ! V_209 )
return 0 ;
if ( V_210 && ! V_209 ) {
F_56 ( F_69 ( V_3 ) , V_213 ) ;
return 1 ;
}
if ( ! V_210 && V_209 ) {
F_56 ( F_69 ( V_3 ) , V_214 ) ;
return 1 ;
}
V_211 = F_104 ( V_212 ,
V_210 ,
NULL , NULL , V_7 ) ;
if ( V_211 || memcmp ( V_209 , V_212 , 16 ) != 0 ) {
F_108 ( L_2 ,
V_211 ? L_3 : L_4 ,
& V_208 -> V_26 , F_109 ( V_129 -> V_28 ) ,
& V_208 -> V_24 , F_109 ( V_129 -> V_27 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_110 ( struct V_6 * V_7 , T_2 V_130 , T_2 V_215 , T_2 V_216 ,
T_2 V_217 , T_2 V_218 , int V_219 ,
struct V_1 * V_202 , int V_220 , T_3 V_172 ,
T_2 V_221 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_112 * V_222 ;
struct V_6 * V_223 ;
struct V_44 V_45 ;
struct V_131 * V_131 = F_48 ( F_3 ( V_7 ) -> V_132 ) ;
struct V_2 * V_224 = V_131 -> V_225 . F_17 ;
unsigned int V_226 = sizeof( struct V_112 ) ;
struct V_8 * V_9 ;
T_4 * V_227 ;
if ( V_218 )
V_226 += V_228 ;
#ifdef F_26
if ( V_202 )
V_226 += V_229 ;
#endif
V_223 = F_111 ( V_230 + sizeof( struct V_113 ) + V_226 ,
V_231 ) ;
if ( V_223 == NULL )
return;
F_112 ( V_223 , V_230 + sizeof( struct V_113 ) + V_226 ) ;
V_222 = (struct V_112 * ) F_113 ( V_223 , V_226 ) ;
F_114 ( V_223 ) ;
memset ( V_222 , 0 , sizeof( * V_222 ) ) ;
V_222 -> V_27 = V_129 -> V_28 ;
V_222 -> V_28 = V_129 -> V_27 ;
V_222 -> V_207 = V_226 / 4 ;
V_222 -> V_130 = F_115 ( V_130 ) ;
V_222 -> V_232 = F_115 ( V_215 ) ;
V_222 -> V_215 = ! V_220 || ! V_129 -> V_215 ;
V_222 -> V_220 = V_220 ;
V_222 -> V_233 = F_116 ( V_216 ) ;
V_227 = ( T_4 * ) ( V_222 + 1 ) ;
if ( V_218 ) {
* V_227 ++ = F_115 ( ( V_234 << 24 ) | ( V_234 << 16 ) |
( V_235 << 8 ) | V_236 ) ;
* V_227 ++ = F_115 ( V_217 ) ;
* V_227 ++ = F_115 ( V_218 ) ;
}
#ifdef F_26
if ( V_202 ) {
* V_227 ++ = F_115 ( ( V_234 << 24 ) | ( V_234 << 16 ) |
( V_237 << 8 ) | V_238 ) ;
F_97 ( ( T_7 * ) V_227 , V_202 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_222 ) ;
}
#endif
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_24 = F_14 ( V_7 ) -> V_26 ;
V_45 . V_26 = F_14 ( V_7 ) -> V_24 ;
V_45 . V_54 = V_221 ;
V_223 -> V_239 = V_240 ;
V_223 -> V_241 = 0 ;
F_77 ( V_223 , & V_45 . V_26 , & V_45 . V_24 ) ;
V_45 . V_93 = V_94 ;
if ( F_117 ( & V_45 . V_24 ) && ! V_219 )
V_45 . V_95 = F_65 ( V_7 ) ;
else
V_45 . V_95 = V_219 ;
V_45 . V_98 = V_222 -> V_27 ;
V_45 . V_99 = V_222 -> V_28 ;
F_118 ( V_7 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_224 , & V_45 , NULL ) ;
if ( ! F_33 ( V_9 ) ) {
F_119 ( V_223 , V_9 ) ;
F_79 ( V_224 , V_223 , & V_45 , NULL , V_172 ) ;
F_82 ( V_131 , V_242 ) ;
if ( V_220 )
F_82 ( V_131 , V_243 ) ;
return;
}
F_84 ( V_223 ) ;
}
static void F_120 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
T_2 V_130 = 0 , V_232 = 0 ;
struct V_1 * V_202 = NULL ;
#ifdef F_26
const T_7 * V_209 = NULL ;
struct V_113 * V_244 = F_14 ( V_7 ) ;
unsigned char V_212 [ 16 ] ;
int V_211 ;
struct V_2 * V_245 = NULL ;
#endif
int V_219 ;
if ( V_129 -> V_220 )
return;
if ( ! F_121 ( V_7 ) )
return;
#ifdef F_26
V_209 = F_107 ( V_129 ) ;
if ( ! V_3 && V_209 ) {
V_245 = F_122 ( F_48 ( F_3 ( V_7 ) -> V_132 ) ,
& V_133 , & V_244 -> V_26 ,
V_129 -> V_28 , & V_244 -> V_24 ,
F_109 ( V_129 -> V_28 ) , F_65 ( V_7 ) ) ;
if ( ! V_245 )
return;
F_123 () ;
V_202 = F_1 ( V_245 , & V_244 -> V_26 ) ;
if ( ! V_202 )
goto V_246;
V_211 = F_104 ( V_212 , V_202 , NULL , NULL , V_7 ) ;
if ( V_211 || memcmp ( V_209 , V_212 , 16 ) != 0 )
goto V_246;
} else {
V_202 = V_3 ? F_1 ( V_3 , & V_244 -> V_26 ) : NULL ;
}
#endif
if ( V_129 -> V_215 )
V_130 = F_57 ( V_129 -> V_232 ) ;
else
V_232 = F_57 ( V_129 -> V_130 ) + V_129 -> V_247 + V_129 -> V_248 + V_7 -> V_199 -
( V_129 -> V_207 << 2 ) ;
V_219 = V_3 ? V_3 -> V_65 : 0 ;
F_110 ( V_7 , V_130 , V_232 , 0 , 0 , 0 , V_219 , V_202 , 1 , 0 , 0 ) ;
#ifdef F_26
V_246:
if ( V_245 ) {
F_124 () ;
F_72 ( V_245 ) ;
}
#endif
}
static void F_125 ( struct V_6 * V_7 , T_2 V_130 , T_2 V_215 ,
T_2 V_216 , T_2 V_217 , T_2 V_218 , int V_219 ,
struct V_1 * V_202 , T_3 V_172 ,
T_2 V_221 )
{
F_110 ( V_7 , V_130 , V_215 , V_216 , V_217 , V_218 , V_219 , V_202 , 0 , V_172 ,
V_221 ) ;
}
static void F_126 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_249 * V_250 = F_53 ( V_3 ) ;
struct V_251 * V_252 = F_127 ( V_3 ) ;
F_125 ( V_7 , V_252 -> V_253 , V_252 -> V_254 ,
V_252 -> V_255 >> V_250 -> V_256 ,
V_257 + V_252 -> V_258 ,
V_252 -> V_259 , V_250 -> V_260 , F_128 ( V_252 ) ,
V_250 -> V_261 , ( V_250 -> V_262 << 12 ) ) ;
F_52 ( V_250 ) ;
}
static void F_129 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 )
{
F_125 ( V_7 , F_67 ( V_154 ) -> V_156 + 1 , F_67 ( V_154 ) -> V_263 + 1 ,
V_154 -> V_264 , V_257 , V_154 -> V_69 , V_3 -> V_65 ,
F_1 ( V_3 , & F_14 ( V_7 ) -> V_24 ) ,
0 , 0 ) ;
}
static struct V_2 * F_130 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_153 * V_154 , * * V_155 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_2 * V_265 ;
V_154 = F_64 ( V_3 , & V_155 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , F_65 ( V_7 ) ) ;
if ( V_154 )
return F_131 ( V_3 , V_7 , V_154 , V_155 , false ) ;
V_265 = F_132 ( F_69 ( V_3 ) , & V_133 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 , F_109 ( V_129 -> V_27 ) , F_65 ( V_7 ) ) ;
if ( V_265 ) {
if ( V_265 -> V_18 != V_136 ) {
F_54 ( V_265 ) ;
return V_265 ;
}
F_52 ( F_53 ( V_265 ) ) ;
return NULL ;
}
#ifdef F_133
if ( ! V_129 -> V_247 )
V_3 = F_134 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_135 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_266 V_267 ;
struct V_153 * V_154 ;
struct V_164 * V_165 ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 = F_17 ( V_3 ) ;
T_1 V_268 = F_136 ( V_7 ) -> V_269 ;
struct V_8 * V_9 = NULL ;
struct V_44 V_45 ;
bool V_270 = false ;
if ( V_7 -> V_198 == F_116 ( V_271 ) )
return F_137 ( V_3 , V_7 ) ;
if ( ! F_121 ( V_7 ) )
goto V_272;
if ( ( V_273 == 2 ||
F_138 ( V_3 ) ) && ! V_268 ) {
V_270 = F_139 ( V_3 , V_7 , L_5 ) ;
if ( ! V_270 )
goto V_272;
}
if ( F_140 ( V_3 ) && F_141 ( V_3 ) > 1 ) {
F_56 ( F_69 ( V_3 ) , V_274 ) ;
goto V_272;
}
V_154 = F_142 ( & V_275 ) ;
if ( V_154 == NULL )
goto V_272;
#ifdef F_26
F_67 ( V_154 ) -> V_84 = & V_276 ;
#endif
F_143 ( & V_267 ) ;
V_267 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_267 . V_277 = V_41 -> V_66 . V_277 ;
F_144 ( V_7 , & V_267 , 0 , NULL ) ;
if ( V_270 && ! V_267 . V_278 )
F_143 ( & V_267 ) ;
V_267 . V_279 = V_267 . V_278 ;
F_145 ( V_154 , & V_267 , V_7 ) ;
V_165 = F_74 ( V_154 ) ;
V_165 -> V_169 = F_14 ( V_7 ) -> V_26 ;
V_165 -> V_168 = F_14 ( V_7 ) -> V_24 ;
if ( ! V_270 || V_267 . V_279 )
F_146 ( V_154 , V_7 , F_69 ( V_3 ) ) ;
V_165 -> V_280 = V_3 -> V_65 ;
if ( ! V_3 -> V_65 &&
F_22 ( & V_165 -> V_169 ) & V_63 )
V_165 -> V_280 = F_65 ( V_7 ) ;
if ( ! V_268 ) {
if ( F_147 ( V_3 , V_7 ) ||
V_39 -> V_281 . V_282 . V_283 || V_39 -> V_281 . V_282 . V_284 ||
V_39 -> V_281 . V_282 . V_285 || V_39 -> V_281 . V_282 . V_286 ||
V_39 -> V_170 ) {
F_148 ( & V_7 -> V_287 ) ;
V_165 -> V_171 = V_7 ;
}
if ( V_270 ) {
V_268 = F_149 ( V_3 , V_7 , & V_154 -> V_288 ) ;
V_154 -> V_289 = V_267 . V_279 ;
goto V_290;
}
if ( V_267 . V_278 &&
V_105 . V_106 &&
( V_9 = F_75 ( V_3 , & V_45 , V_154 ) ) != NULL ) {
if ( ! F_150 ( V_154 , V_9 , true ) ) {
F_56 ( F_69 ( V_3 ) , V_291 ) ;
goto V_292;
}
}
else if ( ! V_273 &&
( V_293 - F_151 ( V_3 ) <
( V_293 >> 2 ) ) &&
! F_150 ( V_154 , V_9 , false ) ) {
F_152 ( V_294 L_6 ,
& V_165 -> V_169 , F_109 ( F_15 ( V_7 ) -> V_28 ) ) ;
goto V_292;
}
V_268 = F_12 ( V_7 ) ;
}
V_290:
F_67 ( V_154 ) -> V_156 = V_268 ;
if ( F_153 ( V_3 , V_7 , V_154 ) )
goto V_292;
if ( F_73 ( V_3 , V_9 , & V_45 , V_154 ,
F_154 ( V_7 ) ) ||
V_270 )
goto V_295;
F_67 ( V_154 ) -> V_296 = V_257 ;
F_67 ( V_154 ) -> V_297 = NULL ;
F_155 ( V_3 , V_154 , V_298 ) ;
return 0 ;
V_292:
F_156 ( V_9 ) ;
V_295:
F_157 ( V_154 ) ;
V_272:
F_56 ( F_69 ( V_3 ) , V_157 ) ;
return 0 ;
}
static struct V_2 * F_158 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 ,
struct V_8 * V_9 )
{
struct V_164 * V_165 ;
struct V_38 * V_299 , * V_39 = F_6 ( V_3 ) ;
struct V_300 * V_301 ;
struct V_34 * V_302 ;
struct V_40 * V_303 ;
struct V_2 * V_304 ;
#ifdef F_26
struct V_1 * V_202 ;
#endif
struct V_44 V_45 ;
if ( V_7 -> V_198 == F_116 ( V_271 ) ) {
V_304 = F_159 ( V_3 , V_7 , V_154 , V_9 ) ;
if ( V_304 == NULL )
return NULL ;
V_301 = (struct V_300 * ) V_304 ;
F_5 ( V_304 ) -> V_305 = & V_301 -> V_306 ;
V_302 = F_5 ( V_304 ) ;
V_299 = F_6 ( V_304 ) ;
V_303 = F_17 ( V_304 ) ;
memcpy ( V_299 , V_39 , sizeof( struct V_38 ) ) ;
F_28 ( V_302 -> V_307 , & V_304 -> V_68 ) ;
F_28 ( V_302 -> V_90 , & V_299 -> V_26 ) ;
V_304 -> V_92 = V_299 -> V_26 ;
F_8 ( V_304 ) -> V_20 = & V_21 ;
V_304 -> V_82 = V_83 ;
#ifdef F_26
V_303 -> V_84 = & V_85 ;
#endif
V_299 -> V_308 = NULL ;
V_299 -> V_309 = NULL ;
V_299 -> V_310 = NULL ;
V_299 -> V_101 = NULL ;
V_299 -> V_311 = F_65 ( V_7 ) ;
V_299 -> V_312 = F_14 ( V_7 ) -> V_140 ;
V_299 -> V_313 = F_160 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_170 )
V_299 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
F_45 ( V_304 , F_8 ( V_304 ) -> V_122 ) ;
return V_304 ;
}
V_165 = F_74 ( V_154 ) ;
if ( F_140 ( V_3 ) )
goto V_314;
if ( ! V_9 ) {
V_9 = F_75 ( V_3 , & V_45 , V_154 ) ;
if ( ! V_9 )
goto V_139;
}
V_304 = F_161 ( V_3 , V_154 , V_7 ) ;
if ( V_304 == NULL )
goto V_315;
V_304 -> V_103 = V_104 ;
F_35 ( V_304 , V_9 , NULL , NULL ) ;
F_2 ( V_304 , V_7 ) ;
V_301 = (struct V_300 * ) V_304 ;
F_5 ( V_304 ) -> V_305 = & V_301 -> V_306 ;
V_303 = F_17 ( V_304 ) ;
V_302 = F_5 ( V_304 ) ;
V_299 = F_6 ( V_304 ) ;
memcpy ( V_299 , V_39 , sizeof( struct V_38 ) ) ;
V_304 -> V_68 = V_165 -> V_169 ;
V_299 -> V_26 = V_165 -> V_168 ;
V_304 -> V_92 = V_165 -> V_168 ;
V_304 -> V_65 = V_165 -> V_280 ;
V_302 -> V_316 = NULL ;
V_299 -> V_308 = NULL ;
V_299 -> V_309 = NULL ;
V_299 -> V_281 . V_317 = V_39 -> V_281 . V_317 ;
V_299 -> V_310 = NULL ;
if ( V_165 -> V_171 != NULL ) {
V_299 -> V_310 = F_162 ( V_165 -> V_171 ,
F_163 ( V_3 , V_231 ) ) ;
F_164 ( V_165 -> V_171 ) ;
V_165 -> V_171 = NULL ;
if ( V_299 -> V_310 )
F_165 ( V_299 -> V_310 , V_304 ) ;
}
V_299 -> V_101 = NULL ;
V_299 -> V_311 = F_65 ( V_7 ) ;
V_299 -> V_312 = F_14 ( V_7 ) -> V_140 ;
V_299 -> V_313 = F_160 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_170 )
V_299 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_101 )
V_299 -> V_101 = F_166 ( V_304 , V_39 -> V_101 ) ;
F_8 ( V_304 ) -> V_74 = 0 ;
if ( V_299 -> V_101 )
F_8 ( V_304 ) -> V_74 = ( V_299 -> V_101 -> V_109 +
V_299 -> V_101 -> V_108 ) ;
F_45 ( V_304 , F_44 ( V_9 ) ) ;
V_303 -> V_318 = F_167 ( V_9 ) ;
if ( F_17 ( V_3 ) -> V_66 . V_277 &&
F_17 ( V_3 ) -> V_66 . V_277 < V_303 -> V_318 )
V_303 -> V_318 = F_17 ( V_3 ) -> V_66 . V_277 ;
F_168 ( V_304 ) ;
V_302 -> V_307 = V_302 -> V_90 = V_102 ;
V_302 -> V_91 = V_102 ;
#ifdef F_26
V_202 = F_1 ( V_3 , & V_304 -> V_68 ) ;
if ( V_202 != NULL ) {
F_92 ( V_304 , (union V_176 * ) & V_304 -> V_68 ,
V_51 , V_202 -> V_202 , V_202 -> V_319 ,
F_163 ( V_3 , V_231 ) ) ;
}
#endif
if ( F_169 ( V_3 , V_304 ) < 0 ) {
F_170 ( V_304 ) ;
F_70 ( V_304 ) ;
goto V_139;
}
F_10 ( V_304 , NULL ) ;
return V_304 ;
V_314:
F_56 ( F_69 ( V_3 ) , V_274 ) ;
V_315:
F_156 ( V_9 ) ;
V_139:
F_56 ( F_69 ( V_3 ) , V_157 ) ;
return NULL ;
}
static T_8 F_171 ( struct V_6 * V_7 )
{
if ( V_7 -> V_239 == V_320 ) {
if ( ! F_172 ( V_7 -> V_199 , & F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_7 -> V_241 ) ) {
V_7 -> V_239 = V_321 ;
return 0 ;
}
}
V_7 -> V_241 = ~ F_173 ( F_172 ( V_7 -> V_199 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , 0 ) ) ;
if ( V_7 -> V_199 <= 76 )
return F_174 ( V_7 ) ;
return 0 ;
}
static int V_87 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_6 * V_322 = NULL ;
if ( V_7 -> V_198 == F_116 ( V_271 ) )
return V_83 ( V_3 , V_7 ) ;
#ifdef F_26
if ( F_106 ( V_3 , V_7 ) )
goto V_323;
#endif
if ( F_175 ( V_3 , V_7 ) )
goto V_323;
if ( V_39 -> V_281 . V_317 )
V_322 = F_162 ( V_7 , F_163 ( V_3 , V_231 ) ) ;
if ( V_3 -> V_18 == V_324 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_176 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_149 -> V_325 ( V_9 , V_39 -> V_16 ) == NULL ) {
F_156 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_177 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_199 ) ;
if ( V_322 )
goto V_326;
return 0 ;
}
if ( V_7 -> V_199 < F_178 ( V_7 ) || F_179 ( V_7 ) )
goto V_327;
if ( V_3 -> V_18 == V_143 ) {
struct V_2 * V_265 = F_130 ( V_3 , V_7 ) ;
if ( ! V_265 )
goto V_323;
if ( V_265 != V_3 ) {
F_176 ( V_265 , V_7 ) ;
if ( F_180 ( V_3 , V_265 , V_7 ) )
goto V_328;
if ( V_322 )
F_181 ( V_322 ) ;
return 0 ;
}
} else
F_176 ( V_3 , V_7 ) ;
if ( F_182 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_199 ) )
goto V_328;
if ( V_322 )
goto V_326;
return 0 ;
V_328:
F_120 ( V_3 , V_7 ) ;
V_323:
if ( V_322 )
F_181 ( V_322 ) ;
F_84 ( V_7 ) ;
return 0 ;
V_327:
F_82 ( F_69 ( V_3 ) , V_329 ) ;
F_82 ( F_69 ( V_3 ) , V_330 ) ;
goto V_323;
V_326:
V_41 = F_17 ( V_3 ) ;
if ( F_136 ( V_322 ) -> V_331 == V_41 -> V_332 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_120 | V_119 ) ) ) {
if ( V_39 -> V_281 . V_282 . V_283 || V_39 -> V_281 . V_282 . V_284 )
V_39 -> V_311 = F_65 ( V_322 ) ;
if ( V_39 -> V_281 . V_282 . V_285 || V_39 -> V_281 . V_282 . V_286 )
V_39 -> V_312 = F_14 ( V_322 ) -> V_140 ;
if ( V_39 -> V_281 . V_282 . V_333 || V_39 -> V_281 . V_282 . V_334 )
V_39 -> V_313 = F_160 ( F_14 ( V_322 ) ) ;
if ( V_39 -> V_170 )
V_39 -> V_71 = V_58 ( F_14 ( V_322 ) ) ;
if ( F_147 ( V_3 , V_322 ) ) {
F_165 ( V_322 , V_3 ) ;
V_322 = F_183 ( & V_39 -> V_310 , V_322 ) ;
} else {
F_181 ( V_322 ) ;
V_322 = F_183 ( & V_39 -> V_310 , NULL ) ;
}
}
F_84 ( V_322 ) ;
return 0 ;
}
static int F_184 ( struct V_6 * V_7 )
{
const struct V_112 * V_129 ;
const struct V_113 * V_127 ;
struct V_2 * V_3 ;
int V_335 ;
struct V_131 * V_131 = F_48 ( V_7 -> V_132 ) ;
if ( V_7 -> V_336 != V_337 )
goto V_338;
F_82 ( V_131 , V_339 ) ;
if ( ! F_185 ( V_7 , sizeof( struct V_112 ) ) )
goto V_338;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_207 < sizeof( struct V_112 ) / 4 )
goto V_340;
if ( ! F_185 ( V_7 , V_129 -> V_207 * 4 ) )
goto V_338;
if ( ! F_186 ( V_7 ) && F_171 ( V_7 ) )
goto V_341;
V_129 = F_15 ( V_7 ) ;
V_127 = F_14 ( V_7 ) ;
F_136 ( V_7 ) -> V_130 = F_57 ( V_129 -> V_130 ) ;
F_136 ( V_7 ) -> V_331 = ( F_136 ( V_7 ) -> V_130 + V_129 -> V_247 + V_129 -> V_248 +
V_7 -> V_199 - V_129 -> V_207 * 4 ) ;
F_136 ( V_7 ) -> V_232 = F_57 ( V_129 -> V_232 ) ;
F_136 ( V_7 ) -> V_269 = 0 ;
F_136 ( V_7 ) -> V_342 = F_187 ( V_127 ) ;
F_136 ( V_7 ) -> V_343 = 0 ;
V_3 = F_188 ( & V_133 , V_7 , V_129 -> V_28 , V_129 -> V_27 ) ;
if ( ! V_3 )
goto V_344;
V_345:
if ( V_3 -> V_18 == V_136 )
goto V_346;
if ( V_127 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_56 ( V_131 , V_142 ) ;
goto V_347;
}
if ( ! F_189 ( V_3 , V_348 , V_7 ) )
goto V_347;
if ( F_175 ( V_3 , V_7 ) )
goto V_347;
F_190 ( V_3 , V_7 ) ;
V_7 -> V_132 = NULL ;
F_191 ( V_3 ) ;
V_335 = 0 ;
if ( ! F_55 ( V_3 ) ) {
#ifdef F_192
struct V_40 * V_41 = F_17 ( V_3 ) ;
if ( ! V_41 -> V_349 . V_350 && V_41 -> V_349 . V_351 )
V_41 -> V_349 . V_350 = F_193 () ;
if ( V_41 -> V_349 . V_350 )
V_335 = V_87 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_194 ( V_3 , V_7 ) )
V_335 = V_87 ( V_3 , V_7 ) ;
}
} else if ( F_195 ( F_196 ( V_3 , V_7 ,
V_3 -> V_352 + V_3 -> V_353 ) ) ) {
F_71 ( V_3 ) ;
F_56 ( V_131 , V_354 ) ;
goto V_347;
}
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
return V_335 ? - 1 : 0 ;
V_344:
if ( ! F_189 ( NULL , V_348 , V_7 ) )
goto V_338;
if ( V_7 -> V_199 < ( V_129 -> V_207 << 2 ) || F_179 ( V_7 ) ) {
V_341:
F_82 ( V_131 , V_329 ) ;
V_340:
F_82 ( V_131 , V_330 ) ;
} else {
F_120 ( NULL , V_7 ) ;
}
V_338:
F_84 ( V_7 ) ;
return 0 ;
V_347:
F_72 ( V_3 ) ;
goto V_338;
V_346:
if ( ! F_189 ( NULL , V_348 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_338;
}
if ( V_7 -> V_199 < ( V_129 -> V_207 << 2 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_340;
}
if ( F_179 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_341;
}
switch ( F_197 ( F_53 ( V_3 ) , V_7 , V_129 ) ) {
case V_355 :
{
struct V_2 * V_356 ;
V_356 = F_122 ( F_48 ( V_7 -> V_132 ) , & V_133 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 ,
F_109 ( V_129 -> V_27 ) , F_65 ( V_7 ) ) ;
if ( V_356 != NULL ) {
struct V_249 * V_250 = F_53 ( V_3 ) ;
F_198 ( V_250 , & V_105 ) ;
F_52 ( V_250 ) ;
V_3 = V_356 ;
goto V_345;
}
}
case V_357 :
F_126 ( V_3 , V_7 ) ;
break;
case V_358 :
goto V_344;
case V_359 :
;
}
goto V_338;
}
static void F_199 ( struct V_6 * V_7 )
{
const struct V_113 * V_127 ;
const struct V_112 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_336 != V_337 )
return;
if ( ! F_185 ( V_7 , F_200 ( V_7 ) + sizeof( struct V_112 ) ) )
return;
V_127 = F_14 ( V_7 ) ;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_207 < sizeof( struct V_112 ) / 4 )
return;
V_3 = F_132 ( F_48 ( V_7 -> V_132 ) , & V_133 ,
& V_127 -> V_26 , V_129 -> V_28 ,
& V_127 -> V_24 , F_109 ( V_129 -> V_27 ) ,
F_65 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_360 = V_361 ;
if ( V_3 -> V_18 != V_136 ) {
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
static void F_208 ( struct V_362 * V_130 ,
const struct V_2 * V_3 , struct V_153 * V_154 , int V_363 , T_9 V_364 )
{
int V_365 = V_154 -> V_366 - V_367 ;
const struct V_4 * V_368 = & F_74 ( V_154 ) -> V_168 ;
const struct V_4 * V_27 = & F_74 ( V_154 ) -> V_169 ;
if ( V_365 < 0 )
V_365 = 0 ;
F_209 ( V_130 ,
L_7
L_8 ,
V_363 ,
V_368 -> V_25 [ 0 ] , V_368 -> V_25 [ 1 ] ,
V_368 -> V_25 [ 2 ] , V_368 -> V_25 [ 3 ] ,
F_74 ( V_154 ) -> V_369 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] ,
F_109 ( F_74 ( V_154 ) -> V_370 ) ,
V_158 ,
0 , 0 ,
1 ,
F_210 ( V_365 ) ,
V_154 -> V_371 ,
F_211 ( F_212 ( V_130 ) , V_364 ) ,
0 ,
0 ,
0 , V_154 ) ;
}
static void F_213 ( struct V_362 * V_130 , struct V_2 * V_372 , int V_363 )
{
const struct V_4 * V_27 , * V_368 ;
T_10 V_373 , V_374 ;
int V_375 ;
unsigned long V_376 ;
const struct V_34 * V_35 = F_5 ( V_372 ) ;
const struct V_40 * V_41 = F_17 ( V_372 ) ;
const struct V_36 * V_37 = F_8 ( V_372 ) ;
V_27 = & V_372 -> V_68 ;
V_368 = & V_372 -> V_92 ;
V_373 = F_109 ( V_35 -> V_114 ) ;
V_374 = F_109 ( V_35 -> V_100 ) ;
if ( V_37 -> V_377 == V_378 ) {
V_375 = 1 ;
V_376 = V_37 -> V_379 ;
} else if ( V_37 -> V_377 == V_380 ) {
V_375 = 4 ;
V_376 = V_37 -> V_379 ;
} else if ( F_214 ( & V_372 -> V_381 ) ) {
V_375 = 2 ;
V_376 = V_372 -> V_381 . V_366 ;
} else {
V_375 = 0 ;
V_376 = V_367 ;
}
F_209 ( V_130 ,
L_7
L_9 ,
V_363 ,
V_368 -> V_25 [ 0 ] , V_368 -> V_25 [ 1 ] ,
V_368 -> V_25 [ 2 ] , V_368 -> V_25 [ 3 ] , V_374 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_373 ,
V_372 -> V_18 ,
V_41 -> V_70 - V_41 -> V_144 ,
( V_372 -> V_18 == V_143 ) ? V_372 -> V_382 : ( V_41 -> V_332 - V_41 -> V_383 ) ,
V_375 ,
F_215 ( V_376 - V_367 ) ,
V_37 -> V_384 ,
F_211 ( F_212 ( V_130 ) , F_216 ( V_372 ) ) ,
V_37 -> V_385 ,
F_217 ( V_372 ) ,
F_218 ( & V_372 -> V_386 ) , V_372 ,
F_210 ( V_37 -> V_387 ) ,
F_210 ( V_37 -> V_388 . V_389 ) ,
( V_37 -> V_388 . V_390 << 1 ) | V_37 -> V_388 . V_391 ,
V_41 -> V_392 ,
F_219 ( V_41 ) ? - 1 : V_41 -> V_393
) ;
}
static void F_220 ( struct V_362 * V_130 ,
struct V_249 * V_250 , int V_363 )
{
const struct V_4 * V_27 , * V_368 ;
T_10 V_373 , V_374 ;
T_11 V_394 = V_250 -> V_395 - F_221 () ;
V_27 = & V_250 -> V_396 ;
V_368 = & V_250 -> V_397 ;
V_373 = F_109 ( V_250 -> V_398 ) ;
V_374 = F_109 ( V_250 -> V_399 ) ;
F_209 ( V_130 ,
L_7
L_10 ,
V_363 ,
V_368 -> V_25 [ 0 ] , V_368 -> V_25 [ 1 ] ,
V_368 -> V_25 [ 2 ] , V_368 -> V_25 [ 3 ] , V_374 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_373 ,
V_250 -> V_400 , 0 , 0 ,
3 , F_215 ( V_394 ) , 0 , 0 , 0 , 0 ,
F_218 ( & V_250 -> V_401 ) , V_250 ) ;
}
static int F_222 ( struct V_362 * V_130 , void * V_402 )
{
struct V_403 * V_404 ;
struct V_2 * V_3 = V_402 ;
if ( V_402 == V_405 ) {
F_223 ( V_130 ,
L_11
L_12
L_13
L_14
L_15 ) ;
goto V_139;
}
V_404 = V_130 -> V_406 ;
switch ( V_404 -> V_407 ) {
case V_408 :
case V_409 :
if ( V_3 -> V_18 == V_136 )
F_220 ( V_130 , V_402 , V_404 -> V_410 ) ;
else
F_213 ( V_130 , V_402 , V_404 -> V_410 ) ;
break;
case V_411 :
F_208 ( V_130 , V_404 -> V_412 , V_402 , V_404 -> V_410 , V_404 -> V_364 ) ;
break;
}
V_139:
return 0 ;
}
int T_12 F_224 ( struct V_131 * V_131 )
{
return F_225 ( V_131 , & V_413 ) ;
}
void F_226 ( struct V_131 * V_131 )
{
F_227 ( V_131 , & V_413 ) ;
}
static void F_228 ( struct V_2 * V_3 , int V_414 )
{
struct V_34 * V_35 = F_5 ( V_3 ) ;
F_229 ( V_3 , F_230 ( struct V_34 , V_305 ) ) ;
V_414 -= F_230 ( struct V_34 , V_305 ) + sizeof( V_35 -> V_305 ) ;
memset ( & V_35 -> V_305 + 1 , 0 , V_414 ) ;
}
static int T_12 F_231 ( struct V_131 * V_131 )
{
return F_232 ( & V_131 -> V_225 . F_17 , V_415 ,
V_416 , V_94 , V_131 ) ;
}
static void T_13 F_233 ( struct V_131 * V_131 )
{
F_234 ( V_131 -> V_225 . F_17 ) ;
}
static void T_13 F_235 ( struct V_417 * V_418 )
{
F_236 ( & V_133 , & V_105 , V_51 ) ;
}
int T_14 F_237 ( void )
{
int V_335 ;
V_335 = F_238 ( & V_419 , V_94 ) ;
if ( V_335 )
goto V_139;
V_335 = F_239 ( & V_420 ) ;
if ( V_335 )
goto V_421;
V_335 = F_240 ( & V_422 ) ;
if ( V_335 )
goto V_423;
V_139:
return V_335 ;
V_423:
F_241 ( & V_420 ) ;
V_421:
F_242 ( & V_419 , V_94 ) ;
goto V_139;
}
void F_243 ( void )
{
F_244 ( & V_422 ) ;
F_241 ( & V_420 ) ;
F_242 ( & V_419 , V_94 ) ;
}
