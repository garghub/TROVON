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
if ( ! V_173 )
F_82 ( F_69 ( V_3 ) , V_174 ) ;
return V_173 ;
}
static void F_83 ( struct V_153 * V_154 )
{
F_84 ( F_74 ( V_154 ) -> V_171 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_85 ( V_3 , (union V_175 * ) V_5 , V_51 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_2 * V_176 )
{
return F_1 ( V_3 , & V_176 -> V_68 ) ;
}
static struct V_1 * F_87 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
return F_1 ( V_3 , & F_74 ( V_154 ) -> V_169 ) ;
}
static int F_88 ( struct V_2 * V_3 , char T_6 * V_177 ,
int V_178 )
{
struct V_179 V_180 ;
struct V_32 * V_181 = (struct V_32 * ) & V_180 . V_182 ;
if ( V_178 < sizeof( V_180 ) )
return - V_49 ;
if ( F_89 ( & V_180 , V_177 , sizeof( V_180 ) ) )
return - V_183 ;
if ( V_181 -> V_50 != V_51 )
return - V_49 ;
if ( ! V_180 . V_184 ) {
if ( F_90 ( & V_181 -> V_59 ) )
return F_91 ( V_3 , (union V_175 * ) & V_181 -> V_59 . V_25 [ 3 ] ,
V_77 ) ;
return F_91 ( V_3 , (union V_175 * ) & V_181 -> V_59 ,
V_51 ) ;
}
if ( V_180 . V_184 > V_185 )
return - V_49 ;
if ( F_90 ( & V_181 -> V_59 ) )
return F_92 ( V_3 , (union V_175 * ) & V_181 -> V_59 . V_25 [ 3 ] ,
V_77 , V_180 . V_186 , V_180 . V_184 , V_187 ) ;
return F_92 ( V_3 , (union V_175 * ) & V_181 -> V_59 ,
V_51 , V_180 . V_186 , V_180 . V_184 , V_187 ) ;
}
static int F_93 ( struct V_188 * V_189 ,
const struct V_4 * V_24 ,
const struct V_4 * V_26 , int V_190 )
{
struct V_191 * V_192 ;
struct V_193 V_194 ;
V_192 = & V_189 -> V_195 . V_196 ;
V_192 -> V_26 = * V_26 ;
V_192 -> V_24 = * V_24 ;
V_192 -> V_197 = F_94 ( V_94 ) ;
V_192 -> V_198 = F_94 ( V_190 ) ;
F_95 ( & V_194 , V_192 , sizeof( * V_192 ) ) ;
return F_96 ( & V_189 -> V_199 , & V_194 , sizeof( * V_192 ) ) ;
}
static int F_97 ( char * V_200 , struct V_1 * V_201 ,
const struct V_4 * V_24 , struct V_4 * V_26 ,
const struct V_112 * V_129 )
{
struct V_188 * V_189 ;
struct V_202 * V_203 ;
V_189 = F_98 () ;
if ( ! V_189 )
goto V_204;
V_203 = & V_189 -> V_199 ;
if ( F_99 ( V_203 ) )
goto V_205;
if ( F_93 ( V_189 , V_24 , V_26 , V_129 -> V_206 << 2 ) )
goto V_205;
if ( F_100 ( V_189 , V_129 ) )
goto V_205;
if ( F_101 ( V_189 , V_201 ) )
goto V_205;
if ( F_102 ( V_203 , V_200 ) )
goto V_205;
F_103 () ;
return 0 ;
V_205:
F_103 () ;
V_204:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static int F_104 ( char * V_200 , struct V_1 * V_201 ,
const struct V_2 * V_3 ,
const struct V_153 * V_154 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_26 , * V_24 ;
struct V_188 * V_189 ;
struct V_202 * V_203 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
if ( V_3 ) {
V_26 = & F_6 ( V_3 ) -> V_26 ;
V_24 = & V_3 -> V_68 ;
} else if ( V_154 ) {
V_26 = & F_74 ( V_154 ) -> V_168 ;
V_24 = & F_74 ( V_154 ) -> V_169 ;
} else {
const struct V_113 * V_207 = F_14 ( V_7 ) ;
V_26 = & V_207 -> V_26 ;
V_24 = & V_207 -> V_24 ;
}
V_189 = F_98 () ;
if ( ! V_189 )
goto V_204;
V_203 = & V_189 -> V_199 ;
if ( F_99 ( V_203 ) )
goto V_205;
if ( F_93 ( V_189 , V_24 , V_26 , V_7 -> V_198 ) )
goto V_205;
if ( F_100 ( V_189 , V_129 ) )
goto V_205;
if ( F_105 ( V_189 , V_7 , V_129 -> V_206 << 2 ) )
goto V_205;
if ( F_101 ( V_189 , V_201 ) )
goto V_205;
if ( F_102 ( V_203 , V_200 ) )
goto V_205;
F_103 () ;
return 0 ;
V_205:
F_103 () ;
V_204:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static int F_106 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_208 = NULL ;
struct V_1 * V_209 ;
const struct V_113 * V_207 = F_14 ( V_7 ) ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
int V_210 ;
T_3 V_211 [ 16 ] ;
V_209 = F_1 ( V_3 , & V_207 -> V_26 ) ;
V_208 = F_107 ( V_129 ) ;
if ( ! V_209 && ! V_208 )
return 0 ;
if ( V_209 && ! V_208 ) {
F_56 ( F_69 ( V_3 ) , V_212 ) ;
return 1 ;
}
if ( ! V_209 && V_208 ) {
F_56 ( F_69 ( V_3 ) , V_213 ) ;
return 1 ;
}
V_210 = F_104 ( V_211 ,
V_209 ,
NULL , NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 ) {
F_108 ( L_2 ,
V_210 ? L_3 : L_4 ,
& V_207 -> V_26 , F_109 ( V_129 -> V_28 ) ,
& V_207 -> V_24 , F_109 ( V_129 -> V_27 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_110 ( struct V_6 * V_7 , T_2 V_130 , T_2 V_214 , T_2 V_215 ,
T_2 V_216 , T_2 V_217 ,
struct V_1 * V_201 , int V_218 , T_3 V_172 ,
T_2 V_219 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_112 * V_220 ;
struct V_6 * V_221 ;
struct V_44 V_45 ;
struct V_131 * V_131 = F_48 ( F_3 ( V_7 ) -> V_132 ) ;
struct V_2 * V_222 = V_131 -> V_223 . F_17 ;
unsigned int V_224 = sizeof( struct V_112 ) ;
struct V_8 * V_9 ;
T_4 * V_225 ;
if ( V_217 )
V_224 += V_226 ;
#ifdef F_26
if ( V_201 )
V_224 += V_227 ;
#endif
V_221 = F_111 ( V_228 + sizeof( struct V_113 ) + V_224 ,
V_229 ) ;
if ( V_221 == NULL )
return;
F_112 ( V_221 , V_228 + sizeof( struct V_113 ) + V_224 ) ;
V_220 = (struct V_112 * ) F_113 ( V_221 , V_224 ) ;
F_114 ( V_221 ) ;
memset ( V_220 , 0 , sizeof( * V_220 ) ) ;
V_220 -> V_27 = V_129 -> V_28 ;
V_220 -> V_28 = V_129 -> V_27 ;
V_220 -> V_206 = V_224 / 4 ;
V_220 -> V_130 = F_115 ( V_130 ) ;
V_220 -> V_230 = F_115 ( V_214 ) ;
V_220 -> V_214 = ! V_218 || ! V_129 -> V_214 ;
V_220 -> V_218 = V_218 ;
V_220 -> V_231 = F_116 ( V_215 ) ;
V_225 = ( T_4 * ) ( V_220 + 1 ) ;
if ( V_217 ) {
* V_225 ++ = F_115 ( ( V_232 << 24 ) | ( V_232 << 16 ) |
( V_233 << 8 ) | V_234 ) ;
* V_225 ++ = F_115 ( V_216 ) ;
* V_225 ++ = F_115 ( V_217 ) ;
}
#ifdef F_26
if ( V_201 ) {
* V_225 ++ = F_115 ( ( V_232 << 24 ) | ( V_232 << 16 ) |
( V_235 << 8 ) | V_236 ) ;
F_97 ( ( T_7 * ) V_225 , V_201 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_220 ) ;
}
#endif
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_24 = F_14 ( V_7 ) -> V_26 ;
V_45 . V_26 = F_14 ( V_7 ) -> V_24 ;
V_45 . V_54 = V_219 ;
V_221 -> V_237 = V_238 ;
V_221 -> V_239 = 0 ;
F_77 ( V_221 , & V_45 . V_26 , & V_45 . V_24 ) ;
V_45 . V_93 = V_94 ;
if ( F_22 ( & V_45 . V_24 ) & V_63 )
V_45 . V_95 = F_65 ( V_7 ) ;
V_45 . V_98 = V_220 -> V_27 ;
V_45 . V_99 = V_220 -> V_28 ;
F_117 ( V_7 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_222 , & V_45 , NULL ) ;
if ( ! F_33 ( V_9 ) ) {
F_118 ( V_221 , V_9 ) ;
F_79 ( V_222 , V_221 , & V_45 , NULL , V_172 ) ;
F_82 ( V_131 , V_240 ) ;
if ( V_218 )
F_82 ( V_131 , V_241 ) ;
return;
}
F_84 ( V_221 ) ;
}
static void F_119 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
T_2 V_130 = 0 , V_230 = 0 ;
struct V_1 * V_201 = NULL ;
#ifdef F_26
const T_7 * V_208 = NULL ;
struct V_113 * V_242 = F_14 ( V_7 ) ;
unsigned char V_211 [ 16 ] ;
int V_210 ;
struct V_2 * V_243 = NULL ;
#endif
if ( V_129 -> V_218 )
return;
if ( ! F_120 ( V_7 ) )
return;
#ifdef F_26
V_208 = F_107 ( V_129 ) ;
if ( ! V_3 && V_208 ) {
V_243 = F_121 ( F_48 ( F_3 ( V_7 ) -> V_132 ) ,
& V_133 , & V_242 -> V_26 ,
V_129 -> V_28 , & V_242 -> V_24 ,
F_109 ( V_129 -> V_28 ) , F_65 ( V_7 ) ) ;
if ( ! V_243 )
return;
F_122 () ;
V_201 = F_1 ( V_243 , & V_242 -> V_26 ) ;
if ( ! V_201 )
goto V_244;
V_210 = F_104 ( V_211 , V_201 , NULL , NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 )
goto V_244;
} else {
V_201 = V_3 ? F_1 ( V_3 , & V_242 -> V_26 ) : NULL ;
}
#endif
if ( V_129 -> V_214 )
V_130 = F_57 ( V_129 -> V_230 ) ;
else
V_230 = F_57 ( V_129 -> V_130 ) + V_129 -> V_245 + V_129 -> V_246 + V_7 -> V_198 -
( V_129 -> V_206 << 2 ) ;
F_110 ( V_7 , V_130 , V_230 , 0 , 0 , 0 , V_201 , 1 , 0 , 0 ) ;
#ifdef F_26
V_244:
if ( V_243 ) {
F_123 () ;
F_72 ( V_243 ) ;
}
#endif
}
static void F_124 ( struct V_6 * V_7 , T_2 V_130 , T_2 V_214 ,
T_2 V_215 , T_2 V_216 , T_2 V_217 ,
struct V_1 * V_201 , T_3 V_172 ,
T_2 V_219 )
{
F_110 ( V_7 , V_130 , V_214 , V_215 , V_216 , V_217 , V_201 , 0 , V_172 ,
V_219 ) ;
}
static void F_125 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_247 * V_248 = F_53 ( V_3 ) ;
struct V_249 * V_250 = F_126 ( V_3 ) ;
F_124 ( V_7 , V_250 -> V_251 , V_250 -> V_252 ,
V_250 -> V_253 >> V_248 -> V_254 ,
V_255 + V_250 -> V_256 ,
V_250 -> V_257 , F_127 ( V_250 ) ,
V_248 -> V_258 , ( V_248 -> V_259 << 12 ) ) ;
F_52 ( V_248 ) ;
}
static void F_128 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 )
{
F_124 ( V_7 , F_67 ( V_154 ) -> V_156 + 1 , F_67 ( V_154 ) -> V_260 + 1 ,
V_154 -> V_261 , V_255 , V_154 -> V_69 ,
F_1 ( V_3 , & F_14 ( V_7 ) -> V_24 ) ,
0 , 0 ) ;
}
static struct V_2 * F_129 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_153 * V_154 , * * V_155 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_2 * V_262 ;
V_154 = F_64 ( V_3 , & V_155 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , F_65 ( V_7 ) ) ;
if ( V_154 )
return F_130 ( V_3 , V_7 , V_154 , V_155 , false ) ;
V_262 = F_131 ( F_69 ( V_3 ) , & V_133 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 , F_109 ( V_129 -> V_27 ) , F_65 ( V_7 ) ) ;
if ( V_262 ) {
if ( V_262 -> V_18 != V_136 ) {
F_54 ( V_262 ) ;
return V_262 ;
}
F_52 ( F_53 ( V_262 ) ) ;
return NULL ;
}
#ifdef F_132
if ( ! V_129 -> V_245 )
V_3 = F_133 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_134 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_263 V_264 ;
struct V_153 * V_154 ;
struct V_164 * V_165 ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 = F_17 ( V_3 ) ;
T_1 V_265 = F_135 ( V_7 ) -> V_266 ;
struct V_8 * V_9 = NULL ;
struct V_44 V_45 ;
bool V_267 = false ;
if ( V_7 -> V_197 == F_116 ( V_268 ) )
return F_136 ( V_3 , V_7 ) ;
if ( ! F_120 ( V_7 ) )
goto V_269;
if ( ( V_270 == 2 ||
F_137 ( V_3 ) ) && ! V_265 ) {
V_267 = F_138 ( V_3 , V_7 , L_5 ) ;
if ( ! V_267 )
goto V_269;
}
if ( F_139 ( V_3 ) && F_140 ( V_3 ) > 1 ) {
F_56 ( F_69 ( V_3 ) , V_271 ) ;
goto V_269;
}
V_154 = F_141 ( & V_272 ) ;
if ( V_154 == NULL )
goto V_269;
#ifdef F_26
F_67 ( V_154 ) -> V_84 = & V_273 ;
#endif
F_142 ( & V_264 ) ;
V_264 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_264 . V_274 = V_41 -> V_66 . V_274 ;
F_143 ( V_7 , & V_264 , 0 , NULL ) ;
if ( V_267 && ! V_264 . V_275 )
F_142 ( & V_264 ) ;
V_264 . V_276 = V_264 . V_275 ;
F_144 ( V_154 , & V_264 , V_7 ) ;
V_165 = F_74 ( V_154 ) ;
V_165 -> V_169 = F_14 ( V_7 ) -> V_26 ;
V_165 -> V_168 = F_14 ( V_7 ) -> V_24 ;
if ( ! V_267 || V_264 . V_276 )
F_145 ( V_154 , V_7 , F_69 ( V_3 ) ) ;
V_165 -> V_277 = V_3 -> V_65 ;
if ( ! V_3 -> V_65 &&
F_22 ( & V_165 -> V_169 ) & V_63 )
V_165 -> V_277 = F_65 ( V_7 ) ;
if ( ! V_265 ) {
if ( F_146 ( V_3 , V_7 ) ||
V_39 -> V_278 . V_279 . V_280 || V_39 -> V_278 . V_279 . V_281 ||
V_39 -> V_278 . V_279 . V_282 || V_39 -> V_278 . V_279 . V_283 ||
V_39 -> V_170 ) {
F_147 ( & V_7 -> V_284 ) ;
V_165 -> V_171 = V_7 ;
}
if ( V_267 ) {
V_265 = F_148 ( V_3 , V_7 , & V_154 -> V_285 ) ;
V_154 -> V_286 = V_264 . V_276 ;
goto V_287;
}
if ( V_264 . V_275 &&
V_105 . V_106 &&
( V_9 = F_75 ( V_3 , & V_45 , V_154 ) ) != NULL ) {
if ( ! F_149 ( V_154 , V_9 , true ) ) {
F_56 ( F_69 ( V_3 ) , V_288 ) ;
goto V_289;
}
}
else if ( ! V_270 &&
( V_290 - F_150 ( V_3 ) <
( V_290 >> 2 ) ) &&
! F_149 ( V_154 , V_9 , false ) ) {
F_151 ( V_291 L_6 ,
& V_165 -> V_169 , F_109 ( F_15 ( V_7 ) -> V_28 ) ) ;
goto V_289;
}
V_265 = F_12 ( V_7 ) ;
}
V_287:
F_67 ( V_154 ) -> V_156 = V_265 ;
if ( F_152 ( V_3 , V_7 , V_154 ) )
goto V_289;
if ( F_73 ( V_3 , V_9 , & V_45 , V_154 ,
F_153 ( V_7 ) ) ||
V_267 )
goto V_292;
F_67 ( V_154 ) -> V_293 = V_255 ;
F_67 ( V_154 ) -> V_294 = NULL ;
F_154 ( V_3 , V_154 , V_295 ) ;
return 0 ;
V_289:
F_155 ( V_9 ) ;
V_292:
F_156 ( V_154 ) ;
V_269:
F_56 ( F_69 ( V_3 ) , V_157 ) ;
return 0 ;
}
static struct V_2 * F_157 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 ,
struct V_8 * V_9 )
{
struct V_164 * V_165 ;
struct V_38 * V_296 , * V_39 = F_6 ( V_3 ) ;
struct V_297 * V_298 ;
struct V_34 * V_299 ;
struct V_40 * V_300 ;
struct V_2 * V_301 ;
#ifdef F_26
struct V_1 * V_201 ;
#endif
struct V_44 V_45 ;
if ( V_7 -> V_197 == F_116 ( V_268 ) ) {
V_301 = F_158 ( V_3 , V_7 , V_154 , V_9 ) ;
if ( V_301 == NULL )
return NULL ;
V_298 = (struct V_297 * ) V_301 ;
F_5 ( V_301 ) -> V_302 = & V_298 -> V_303 ;
V_299 = F_5 ( V_301 ) ;
V_296 = F_6 ( V_301 ) ;
V_300 = F_17 ( V_301 ) ;
memcpy ( V_296 , V_39 , sizeof( struct V_38 ) ) ;
F_28 ( V_299 -> V_304 , & V_301 -> V_68 ) ;
F_28 ( V_299 -> V_90 , & V_296 -> V_26 ) ;
V_301 -> V_92 = V_296 -> V_26 ;
F_8 ( V_301 ) -> V_20 = & V_21 ;
V_301 -> V_82 = V_83 ;
#ifdef F_26
V_300 -> V_84 = & V_85 ;
#endif
V_296 -> V_305 = NULL ;
V_296 -> V_306 = NULL ;
V_296 -> V_307 = NULL ;
V_296 -> V_101 = NULL ;
V_296 -> V_308 = F_65 ( V_7 ) ;
V_296 -> V_309 = F_14 ( V_7 ) -> V_140 ;
V_296 -> V_310 = F_159 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_170 )
V_296 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
F_45 ( V_301 , F_8 ( V_301 ) -> V_122 ) ;
return V_301 ;
}
V_165 = F_74 ( V_154 ) ;
if ( F_139 ( V_3 ) )
goto V_311;
if ( ! V_9 ) {
V_9 = F_75 ( V_3 , & V_45 , V_154 ) ;
if ( ! V_9 )
goto V_139;
}
V_301 = F_160 ( V_3 , V_154 , V_7 ) ;
if ( V_301 == NULL )
goto V_312;
V_301 -> V_103 = V_104 ;
F_35 ( V_301 , V_9 , NULL , NULL ) ;
F_2 ( V_301 , V_7 ) ;
V_298 = (struct V_297 * ) V_301 ;
F_5 ( V_301 ) -> V_302 = & V_298 -> V_303 ;
V_300 = F_17 ( V_301 ) ;
V_299 = F_5 ( V_301 ) ;
V_296 = F_6 ( V_301 ) ;
memcpy ( V_296 , V_39 , sizeof( struct V_38 ) ) ;
V_301 -> V_68 = V_165 -> V_169 ;
V_296 -> V_26 = V_165 -> V_168 ;
V_301 -> V_92 = V_165 -> V_168 ;
V_301 -> V_65 = V_165 -> V_277 ;
V_299 -> V_313 = NULL ;
V_296 -> V_305 = NULL ;
V_296 -> V_306 = NULL ;
V_296 -> V_278 . V_314 = V_39 -> V_278 . V_314 ;
V_296 -> V_307 = NULL ;
if ( V_165 -> V_171 != NULL ) {
V_296 -> V_307 = F_161 ( V_165 -> V_171 ,
F_162 ( V_3 , V_229 ) ) ;
F_163 ( V_165 -> V_171 ) ;
V_165 -> V_171 = NULL ;
if ( V_296 -> V_307 )
F_164 ( V_296 -> V_307 , V_301 ) ;
}
V_296 -> V_101 = NULL ;
V_296 -> V_308 = F_65 ( V_7 ) ;
V_296 -> V_309 = F_14 ( V_7 ) -> V_140 ;
V_296 -> V_310 = F_159 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_170 )
V_296 -> V_71 = V_58 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_101 )
V_296 -> V_101 = F_165 ( V_301 , V_39 -> V_101 ) ;
F_8 ( V_301 ) -> V_74 = 0 ;
if ( V_296 -> V_101 )
F_8 ( V_301 ) -> V_74 = ( V_296 -> V_101 -> V_109 +
V_296 -> V_101 -> V_108 ) ;
F_45 ( V_301 , F_44 ( V_9 ) ) ;
V_300 -> V_315 = F_166 ( V_9 ) ;
if ( F_17 ( V_3 ) -> V_66 . V_274 &&
F_17 ( V_3 ) -> V_66 . V_274 < V_300 -> V_315 )
V_300 -> V_315 = F_17 ( V_3 ) -> V_66 . V_274 ;
F_167 ( V_301 ) ;
V_299 -> V_304 = V_299 -> V_90 = V_102 ;
V_299 -> V_91 = V_102 ;
#ifdef F_26
if ( ( V_201 = F_1 ( V_3 , & V_301 -> V_68 ) ) != NULL ) {
F_92 ( V_301 , (union V_175 * ) & V_301 -> V_68 ,
V_51 , V_201 -> V_201 , V_201 -> V_316 ,
F_162 ( V_3 , V_229 ) ) ;
}
#endif
if ( F_168 ( V_3 , V_301 ) < 0 ) {
F_169 ( V_301 ) ;
F_70 ( V_301 ) ;
goto V_139;
}
F_10 ( V_301 , NULL ) ;
return V_301 ;
V_311:
F_56 ( F_69 ( V_3 ) , V_271 ) ;
V_312:
F_155 ( V_9 ) ;
V_139:
F_56 ( F_69 ( V_3 ) , V_157 ) ;
return NULL ;
}
static T_8 F_170 ( struct V_6 * V_7 )
{
if ( V_7 -> V_237 == V_317 ) {
if ( ! F_171 ( V_7 -> V_198 , & F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_7 -> V_239 ) ) {
V_7 -> V_237 = V_318 ;
return 0 ;
}
}
V_7 -> V_239 = ~ F_172 ( F_171 ( V_7 -> V_198 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , 0 ) ) ;
if ( V_7 -> V_198 <= 76 ) {
return F_173 ( V_7 ) ;
}
return 0 ;
}
static int V_87 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_6 * V_319 = NULL ;
if ( V_7 -> V_197 == F_116 ( V_268 ) )
return V_83 ( V_3 , V_7 ) ;
#ifdef F_26
if ( F_106 ( V_3 , V_7 ) )
goto V_320;
#endif
if ( F_174 ( V_3 , V_7 ) )
goto V_320;
if ( V_39 -> V_278 . V_314 )
V_319 = F_161 ( V_7 , F_162 ( V_3 , V_229 ) ) ;
if ( V_3 -> V_18 == V_321 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_175 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_149 -> V_322 ( V_9 , V_39 -> V_16 ) == NULL ) {
F_155 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_176 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_198 ) ;
if ( V_319 )
goto V_323;
return 0 ;
}
if ( V_7 -> V_198 < F_177 ( V_7 ) || F_178 ( V_7 ) )
goto V_324;
if ( V_3 -> V_18 == V_143 ) {
struct V_2 * V_262 = F_129 ( V_3 , V_7 ) ;
if ( ! V_262 )
goto V_320;
if ( V_262 != V_3 ) {
F_175 ( V_262 , V_7 ) ;
if ( F_179 ( V_3 , V_262 , V_7 ) )
goto V_325;
if ( V_319 )
F_180 ( V_319 ) ;
return 0 ;
}
} else
F_175 ( V_3 , V_7 ) ;
if ( F_181 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_198 ) )
goto V_325;
if ( V_319 )
goto V_323;
return 0 ;
V_325:
F_119 ( V_3 , V_7 ) ;
V_320:
if ( V_319 )
F_180 ( V_319 ) ;
F_84 ( V_7 ) ;
return 0 ;
V_324:
F_82 ( F_69 ( V_3 ) , V_326 ) ;
F_82 ( F_69 ( V_3 ) , V_327 ) ;
goto V_320;
V_323:
V_41 = F_17 ( V_3 ) ;
if ( F_135 ( V_319 ) -> V_328 == V_41 -> V_329 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_120 | V_119 ) ) ) {
if ( V_39 -> V_278 . V_279 . V_280 || V_39 -> V_278 . V_279 . V_281 )
V_39 -> V_308 = F_65 ( V_319 ) ;
if ( V_39 -> V_278 . V_279 . V_282 || V_39 -> V_278 . V_279 . V_283 )
V_39 -> V_309 = F_14 ( V_319 ) -> V_140 ;
if ( V_39 -> V_278 . V_279 . V_330 || V_39 -> V_278 . V_279 . V_331 )
V_39 -> V_310 = F_159 ( F_14 ( V_319 ) ) ;
if ( V_39 -> V_170 )
V_39 -> V_71 = V_58 ( F_14 ( V_319 ) ) ;
if ( F_146 ( V_3 , V_319 ) ) {
F_164 ( V_319 , V_3 ) ;
V_319 = F_182 ( & V_39 -> V_307 , V_319 ) ;
} else {
F_180 ( V_319 ) ;
V_319 = F_182 ( & V_39 -> V_307 , NULL ) ;
}
}
F_84 ( V_319 ) ;
return 0 ;
}
static int F_183 ( struct V_6 * V_7 )
{
const struct V_112 * V_129 ;
const struct V_113 * V_127 ;
struct V_2 * V_3 ;
int V_332 ;
struct V_131 * V_131 = F_48 ( V_7 -> V_132 ) ;
if ( V_7 -> V_333 != V_334 )
goto V_335;
F_82 ( V_131 , V_336 ) ;
if ( ! F_184 ( V_7 , sizeof( struct V_112 ) ) )
goto V_335;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_206 < sizeof( struct V_112 ) / 4 )
goto V_337;
if ( ! F_184 ( V_7 , V_129 -> V_206 * 4 ) )
goto V_335;
if ( ! F_185 ( V_7 ) && F_170 ( V_7 ) )
goto V_338;
V_129 = F_15 ( V_7 ) ;
V_127 = F_14 ( V_7 ) ;
F_135 ( V_7 ) -> V_130 = F_57 ( V_129 -> V_130 ) ;
F_135 ( V_7 ) -> V_328 = ( F_135 ( V_7 ) -> V_130 + V_129 -> V_245 + V_129 -> V_246 +
V_7 -> V_198 - V_129 -> V_206 * 4 ) ;
F_135 ( V_7 ) -> V_230 = F_57 ( V_129 -> V_230 ) ;
F_135 ( V_7 ) -> V_266 = 0 ;
F_135 ( V_7 ) -> V_339 = F_186 ( V_127 ) ;
F_135 ( V_7 ) -> V_340 = 0 ;
V_3 = F_187 ( & V_133 , V_7 , V_129 -> V_28 , V_129 -> V_27 ) ;
if ( ! V_3 )
goto V_341;
V_342:
if ( V_3 -> V_18 == V_136 )
goto V_343;
if ( V_127 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_56 ( V_131 , V_142 ) ;
goto V_344;
}
if ( ! F_188 ( V_3 , V_345 , V_7 ) )
goto V_344;
if ( F_174 ( V_3 , V_7 ) )
goto V_344;
F_189 ( V_3 , V_7 ) ;
V_7 -> V_132 = NULL ;
F_190 ( V_3 ) ;
V_332 = 0 ;
if ( ! F_55 ( V_3 ) ) {
#ifdef F_191
struct V_40 * V_41 = F_17 ( V_3 ) ;
if ( ! V_41 -> V_346 . V_347 && V_41 -> V_346 . V_348 )
V_41 -> V_346 . V_347 = F_192 () ;
if ( V_41 -> V_346 . V_347 )
V_332 = V_87 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_193 ( V_3 , V_7 ) )
V_332 = V_87 ( V_3 , V_7 ) ;
}
} else if ( F_194 ( F_195 ( V_3 , V_7 ,
V_3 -> V_349 + V_3 -> V_350 ) ) ) {
F_71 ( V_3 ) ;
F_56 ( V_131 , V_351 ) ;
goto V_344;
}
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
return V_332 ? - 1 : 0 ;
V_341:
if ( ! F_188 ( NULL , V_345 , V_7 ) )
goto V_335;
if ( V_7 -> V_198 < ( V_129 -> V_206 << 2 ) || F_178 ( V_7 ) ) {
V_338:
F_82 ( V_131 , V_326 ) ;
V_337:
F_82 ( V_131 , V_327 ) ;
} else {
F_119 ( NULL , V_7 ) ;
}
V_335:
F_84 ( V_7 ) ;
return 0 ;
V_344:
F_72 ( V_3 ) ;
goto V_335;
V_343:
if ( ! F_188 ( NULL , V_345 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_335;
}
if ( V_7 -> V_198 < ( V_129 -> V_206 << 2 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_337;
}
if ( F_178 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_338;
}
switch ( F_196 ( F_53 ( V_3 ) , V_7 , V_129 ) ) {
case V_352 :
{
struct V_2 * V_353 ;
V_353 = F_121 ( F_48 ( V_7 -> V_132 ) , & V_133 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 ,
F_109 ( V_129 -> V_27 ) , F_65 ( V_7 ) ) ;
if ( V_353 != NULL ) {
struct V_247 * V_248 = F_53 ( V_3 ) ;
F_197 ( V_248 , & V_105 ) ;
F_52 ( V_248 ) ;
V_3 = V_353 ;
goto V_342;
}
}
case V_354 :
F_125 ( V_3 , V_7 ) ;
break;
case V_355 :
goto V_341;
case V_356 : ;
}
goto V_335;
}
static void F_198 ( struct V_6 * V_7 )
{
const struct V_113 * V_127 ;
const struct V_112 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_333 != V_334 )
return;
if ( ! F_184 ( V_7 , F_199 ( V_7 ) + sizeof( struct V_112 ) ) )
return;
V_127 = F_14 ( V_7 ) ;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_206 < sizeof( struct V_112 ) / 4 )
return;
V_3 = F_131 ( F_48 ( V_7 -> V_132 ) , & V_133 ,
& V_127 -> V_26 , V_129 -> V_28 ,
& V_127 -> V_24 , F_109 ( V_129 -> V_27 ) ,
F_65 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_357 = V_358 ;
if ( V_3 -> V_18 != V_136 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
if ( V_9 )
V_9 = F_200 ( V_9 , F_6 ( V_3 ) -> V_16 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_201 ( V_7 , V_9 ) ;
}
}
}
static int F_202 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = F_8 ( V_3 ) ;
F_203 ( V_3 ) ;
V_37 -> V_20 = & V_86 ;
#ifdef F_26
F_17 ( V_3 ) -> V_84 = & V_88 ;
#endif
return 0 ;
}
static void F_204 ( struct V_2 * V_3 )
{
F_205 ( V_3 ) ;
F_206 ( V_3 ) ;
}
static void F_207 ( struct V_359 * V_130 ,
const struct V_2 * V_3 , struct V_153 * V_154 , int V_360 , T_9 V_361 )
{
int V_362 = V_154 -> V_363 - V_364 ;
const struct V_4 * V_365 = & F_74 ( V_154 ) -> V_168 ;
const struct V_4 * V_27 = & F_74 ( V_154 ) -> V_169 ;
if ( V_362 < 0 )
V_362 = 0 ;
F_208 ( V_130 ,
L_7
L_8 ,
V_360 ,
V_365 -> V_25 [ 0 ] , V_365 -> V_25 [ 1 ] ,
V_365 -> V_25 [ 2 ] , V_365 -> V_25 [ 3 ] ,
F_74 ( V_154 ) -> V_366 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] ,
F_109 ( F_74 ( V_154 ) -> V_367 ) ,
V_158 ,
0 , 0 ,
1 ,
F_209 ( V_362 ) ,
V_154 -> V_368 ,
F_210 ( F_211 ( V_130 ) , V_361 ) ,
0 ,
0 ,
0 , V_154 ) ;
}
static void F_212 ( struct V_359 * V_130 , struct V_2 * V_369 , int V_360 )
{
const struct V_4 * V_27 , * V_365 ;
T_10 V_370 , V_371 ;
int V_372 ;
unsigned long V_373 ;
const struct V_34 * V_35 = F_5 ( V_369 ) ;
const struct V_40 * V_41 = F_17 ( V_369 ) ;
const struct V_36 * V_37 = F_8 ( V_369 ) ;
V_27 = & V_369 -> V_68 ;
V_365 = & V_369 -> V_92 ;
V_370 = F_109 ( V_35 -> V_114 ) ;
V_371 = F_109 ( V_35 -> V_100 ) ;
if ( V_37 -> V_374 == V_375 ) {
V_372 = 1 ;
V_373 = V_37 -> V_376 ;
} else if ( V_37 -> V_374 == V_377 ) {
V_372 = 4 ;
V_373 = V_37 -> V_376 ;
} else if ( F_213 ( & V_369 -> V_378 ) ) {
V_372 = 2 ;
V_373 = V_369 -> V_378 . V_363 ;
} else {
V_372 = 0 ;
V_373 = V_364 ;
}
F_208 ( V_130 ,
L_7
L_9 ,
V_360 ,
V_365 -> V_25 [ 0 ] , V_365 -> V_25 [ 1 ] ,
V_365 -> V_25 [ 2 ] , V_365 -> V_25 [ 3 ] , V_371 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_370 ,
V_369 -> V_18 ,
V_41 -> V_70 - V_41 -> V_144 ,
( V_369 -> V_18 == V_143 ) ? V_369 -> V_379 : ( V_41 -> V_329 - V_41 -> V_380 ) ,
V_372 ,
F_214 ( V_373 - V_364 ) ,
V_37 -> V_381 ,
F_210 ( F_211 ( V_130 ) , F_215 ( V_369 ) ) ,
V_37 -> V_382 ,
F_216 ( V_369 ) ,
F_217 ( & V_369 -> V_383 ) , V_369 ,
F_209 ( V_37 -> V_384 ) ,
F_209 ( V_37 -> V_385 . V_386 ) ,
( V_37 -> V_385 . V_387 << 1 ) | V_37 -> V_385 . V_388 ,
V_41 -> V_389 ,
F_218 ( V_41 ) ? - 1 : V_41 -> V_390
) ;
}
static void F_219 ( struct V_359 * V_130 ,
struct V_247 * V_248 , int V_360 )
{
const struct V_4 * V_27 , * V_365 ;
T_10 V_370 , V_371 ;
T_11 V_391 = V_248 -> V_392 - F_220 () ;
V_27 = & V_248 -> V_393 ;
V_365 = & V_248 -> V_394 ;
V_370 = F_109 ( V_248 -> V_395 ) ;
V_371 = F_109 ( V_248 -> V_396 ) ;
F_208 ( V_130 ,
L_7
L_10 ,
V_360 ,
V_365 -> V_25 [ 0 ] , V_365 -> V_25 [ 1 ] ,
V_365 -> V_25 [ 2 ] , V_365 -> V_25 [ 3 ] , V_371 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_370 ,
V_248 -> V_397 , 0 , 0 ,
3 , F_214 ( V_391 ) , 0 , 0 , 0 , 0 ,
F_217 ( & V_248 -> V_398 ) , V_248 ) ;
}
static int F_221 ( struct V_359 * V_130 , void * V_399 )
{
struct V_400 * V_401 ;
struct V_2 * V_3 = V_399 ;
if ( V_399 == V_402 ) {
F_222 ( V_130 ,
L_11
L_12
L_13
L_14
L_15 ) ;
goto V_139;
}
V_401 = V_130 -> V_403 ;
switch ( V_401 -> V_404 ) {
case V_405 :
case V_406 :
if ( V_3 -> V_18 == V_136 )
F_219 ( V_130 , V_399 , V_401 -> V_407 ) ;
else
F_212 ( V_130 , V_399 , V_401 -> V_407 ) ;
break;
case V_408 :
F_207 ( V_130 , V_401 -> V_409 , V_399 , V_401 -> V_407 , V_401 -> V_361 ) ;
break;
}
V_139:
return 0 ;
}
int T_12 F_223 ( struct V_131 * V_131 )
{
return F_224 ( V_131 , & V_410 ) ;
}
void F_225 ( struct V_131 * V_131 )
{
F_226 ( V_131 , & V_410 ) ;
}
static void F_227 ( struct V_2 * V_3 , int V_411 )
{
struct V_34 * V_35 = F_5 ( V_3 ) ;
F_228 ( V_3 , F_229 ( struct V_34 , V_302 ) ) ;
V_411 -= F_229 ( struct V_34 , V_302 ) + sizeof( V_35 -> V_302 ) ;
memset ( & V_35 -> V_302 + 1 , 0 , V_411 ) ;
}
static int T_12 F_230 ( struct V_131 * V_131 )
{
return F_231 ( & V_131 -> V_223 . F_17 , V_412 ,
V_413 , V_94 , V_131 ) ;
}
static void T_13 F_232 ( struct V_131 * V_131 )
{
F_233 ( V_131 -> V_223 . F_17 ) ;
}
static void T_13 F_234 ( struct V_414 * V_415 )
{
F_235 ( & V_133 , & V_105 , V_51 ) ;
}
int T_14 F_236 ( void )
{
int V_332 ;
V_332 = F_237 ( & V_416 , V_94 ) ;
if ( V_332 )
goto V_139;
V_332 = F_238 ( & V_417 ) ;
if ( V_332 )
goto V_418;
V_332 = F_239 ( & V_419 ) ;
if ( V_332 )
goto V_420;
V_139:
return V_332 ;
V_420:
F_240 ( & V_417 ) ;
V_418:
F_241 ( & V_416 , V_94 ) ;
goto V_139;
}
void F_242 ( void )
{
F_243 ( & V_419 ) ;
F_240 ( & V_417 ) ;
F_241 ( & V_416 , V_94 ) ;
}
