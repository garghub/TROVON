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
if( F_21 ( & V_33 -> V_59 ) )
V_33 -> V_59 . V_60 [ 15 ] = 0x1 ;
V_46 = F_22 ( & V_33 -> V_59 ) ;
if( V_46 & V_61 )
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
V_9 = F_32 ( V_3 , & V_45 , V_42 , true ) ;
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
V_41 -> V_121 = F_57 ( V_126 ) ;
if ( ! F_55 ( V_3 ) )
F_42 ( V_3 ) ;
else if ( ! F_60 ( V_151 ,
& V_41 -> V_152 ) )
F_61 ( V_3 ) ;
goto V_139;
}
F_62 ( type , V_124 , & V_47 ) ;
switch ( V_3 -> V_18 ) {
struct V_153 * V_154 , * * V_155 ;
case V_143 :
if ( F_55 ( V_3 ) )
goto V_139;
V_154 = F_63 ( V_3 , & V_155 , V_129 -> V_27 , & V_127 -> V_24 ,
& V_127 -> V_26 , F_64 ( V_7 ) ) ;
if ( ! V_154 )
goto V_139;
F_65 ( V_154 -> V_3 != NULL ) ;
if ( V_130 != F_66 ( V_154 ) -> V_156 ) {
F_56 ( V_131 , V_146 ) ;
goto V_139;
}
F_67 ( V_3 , V_154 , V_155 ) ;
F_56 ( F_68 ( V_3 ) , V_157 ) ;
goto V_139;
case V_115 :
case V_158 :
if ( ! F_55 ( V_3 ) ) {
V_3 -> V_159 = V_47 ;
V_3 -> V_160 ( V_3 ) ;
F_69 ( V_3 ) ;
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
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
}
static int F_72 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_153 * V_154 ,
T_5 V_163 )
{
struct V_164 * V_165 = F_73 ( V_154 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_6 * V_7 ;
int V_47 = - V_166 ;
if ( ! V_9 && ( V_9 = F_74 ( V_3 , V_45 , V_154 ) ) == NULL )
goto V_167;
V_7 = F_75 ( V_3 , V_9 , V_154 , NULL ) ;
if ( V_7 ) {
F_76 ( V_7 , & V_165 -> V_168 ,
& V_165 -> V_169 ) ;
V_45 -> V_24 = V_165 -> V_169 ;
F_77 ( V_7 , V_163 ) ;
V_47 = F_78 ( V_3 , V_7 , V_45 , V_39 -> V_101 , V_39 -> V_170 ) ;
V_47 = F_79 ( V_47 ) ;
}
V_167:
return V_47 ;
}
static int F_80 ( struct V_2 * V_3 , struct V_153 * V_154 )
{
struct V_44 V_45 ;
int V_171 ;
V_171 = F_72 ( V_3 , NULL , & V_45 , V_154 , 0 ) ;
if ( ! V_171 )
F_81 ( F_68 ( V_3 ) , V_172 ) ;
return V_171 ;
}
static void F_82 ( struct V_153 * V_154 )
{
F_83 ( F_73 ( V_154 ) -> V_173 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_84 ( V_3 , (union V_174 * ) V_5 , V_51 ) ;
}
static struct V_1 * F_85 ( struct V_2 * V_3 ,
struct V_2 * V_175 )
{
return F_1 ( V_3 , & V_175 -> V_68 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
return F_1 ( V_3 , & F_73 ( V_154 ) -> V_169 ) ;
}
static int F_87 ( struct V_2 * V_3 , char T_6 * V_176 ,
int V_177 )
{
struct V_178 V_179 ;
struct V_32 * V_180 = (struct V_32 * ) & V_179 . V_181 ;
if ( V_177 < sizeof( V_179 ) )
return - V_49 ;
if ( F_88 ( & V_179 , V_176 , sizeof( V_179 ) ) )
return - V_182 ;
if ( V_180 -> V_50 != V_51 )
return - V_49 ;
if ( ! V_179 . V_183 ) {
if ( F_89 ( & V_180 -> V_59 ) )
return F_90 ( V_3 , (union V_174 * ) & V_180 -> V_59 . V_25 [ 3 ] ,
V_77 ) ;
return F_90 ( V_3 , (union V_174 * ) & V_180 -> V_59 ,
V_51 ) ;
}
if ( V_179 . V_183 > V_184 )
return - V_49 ;
if ( F_89 ( & V_180 -> V_59 ) )
return F_91 ( V_3 , (union V_174 * ) & V_180 -> V_59 . V_25 [ 3 ] ,
V_77 , V_179 . V_185 , V_179 . V_183 , V_186 ) ;
return F_91 ( V_3 , (union V_174 * ) & V_180 -> V_59 ,
V_51 , V_179 . V_185 , V_179 . V_183 , V_186 ) ;
}
static int F_92 ( struct V_187 * V_188 ,
const struct V_4 * V_24 ,
const struct V_4 * V_26 , int V_189 )
{
struct V_190 * V_191 ;
struct V_192 V_193 ;
V_191 = & V_188 -> V_194 . V_195 ;
V_191 -> V_26 = * V_26 ;
V_191 -> V_24 = * V_24 ;
V_191 -> V_196 = F_93 ( V_94 ) ;
V_191 -> V_197 = F_93 ( V_189 ) ;
F_94 ( & V_193 , V_191 , sizeof( * V_191 ) ) ;
return F_95 ( & V_188 -> V_198 , & V_193 , sizeof( * V_191 ) ) ;
}
static int F_96 ( char * V_199 , struct V_1 * V_200 ,
const struct V_4 * V_24 , struct V_4 * V_26 ,
const struct V_112 * V_129 )
{
struct V_187 * V_188 ;
struct V_201 * V_202 ;
V_188 = F_97 () ;
if ( ! V_188 )
goto V_203;
V_202 = & V_188 -> V_198 ;
if ( F_98 ( V_202 ) )
goto V_204;
if ( F_92 ( V_188 , V_24 , V_26 , V_129 -> V_205 << 2 ) )
goto V_204;
if ( F_99 ( V_188 , V_129 ) )
goto V_204;
if ( F_100 ( V_188 , V_200 ) )
goto V_204;
if ( F_101 ( V_202 , V_199 ) )
goto V_204;
F_102 () ;
return 0 ;
V_204:
F_102 () ;
V_203:
memset ( V_199 , 0 , 16 ) ;
return 1 ;
}
static int F_103 ( char * V_199 , struct V_1 * V_200 ,
const struct V_2 * V_3 ,
const struct V_153 * V_154 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_26 , * V_24 ;
struct V_187 * V_188 ;
struct V_201 * V_202 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
if ( V_3 ) {
V_26 = & F_6 ( V_3 ) -> V_26 ;
V_24 = & V_3 -> V_68 ;
} else if ( V_154 ) {
V_26 = & F_73 ( V_154 ) -> V_168 ;
V_24 = & F_73 ( V_154 ) -> V_169 ;
} else {
const struct V_113 * V_206 = F_14 ( V_7 ) ;
V_26 = & V_206 -> V_26 ;
V_24 = & V_206 -> V_24 ;
}
V_188 = F_97 () ;
if ( ! V_188 )
goto V_203;
V_202 = & V_188 -> V_198 ;
if ( F_98 ( V_202 ) )
goto V_204;
if ( F_92 ( V_188 , V_24 , V_26 , V_7 -> V_197 ) )
goto V_204;
if ( F_99 ( V_188 , V_129 ) )
goto V_204;
if ( F_104 ( V_188 , V_7 , V_129 -> V_205 << 2 ) )
goto V_204;
if ( F_100 ( V_188 , V_200 ) )
goto V_204;
if ( F_101 ( V_202 , V_199 ) )
goto V_204;
F_102 () ;
return 0 ;
V_204:
F_102 () ;
V_203:
memset ( V_199 , 0 , 16 ) ;
return 1 ;
}
static int F_105 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_207 = NULL ;
struct V_1 * V_208 ;
const struct V_113 * V_206 = F_14 ( V_7 ) ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
int V_209 ;
T_3 V_210 [ 16 ] ;
V_208 = F_1 ( V_3 , & V_206 -> V_26 ) ;
V_207 = F_106 ( V_129 ) ;
if ( ! V_208 && ! V_207 )
return 0 ;
if ( V_208 && ! V_207 ) {
F_56 ( F_68 ( V_3 ) , V_211 ) ;
return 1 ;
}
if ( ! V_208 && V_207 ) {
F_56 ( F_68 ( V_3 ) , V_212 ) ;
return 1 ;
}
V_209 = F_103 ( V_210 ,
V_208 ,
NULL , NULL , V_7 ) ;
if ( V_209 || memcmp ( V_207 , V_210 , 16 ) != 0 ) {
F_107 ( L_2 ,
V_209 ? L_3 : L_4 ,
& V_206 -> V_26 , F_108 ( V_129 -> V_28 ) ,
& V_206 -> V_24 , F_108 ( V_129 -> V_27 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_109 ( struct V_6 * V_7 , T_2 V_130 , T_2 V_213 , T_2 V_214 ,
T_2 V_215 , T_2 V_216 ,
struct V_1 * V_200 , int V_217 , T_3 V_170 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_112 * V_218 ;
struct V_6 * V_219 ;
struct V_44 V_45 ;
struct V_131 * V_131 = F_48 ( F_3 ( V_7 ) -> V_132 ) ;
struct V_2 * V_220 = V_131 -> V_221 . F_17 ;
unsigned int V_222 = sizeof( struct V_112 ) ;
struct V_8 * V_9 ;
T_4 * V_223 ;
if ( V_216 )
V_222 += V_224 ;
#ifdef F_26
if ( V_200 )
V_222 += V_225 ;
#endif
V_219 = F_110 ( V_226 + sizeof( struct V_113 ) + V_222 ,
V_227 ) ;
if ( V_219 == NULL )
return;
F_111 ( V_219 , V_226 + sizeof( struct V_113 ) + V_222 ) ;
V_218 = (struct V_112 * ) F_112 ( V_219 , V_222 ) ;
F_113 ( V_219 ) ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
V_218 -> V_27 = V_129 -> V_28 ;
V_218 -> V_28 = V_129 -> V_27 ;
V_218 -> V_205 = V_222 / 4 ;
V_218 -> V_130 = F_114 ( V_130 ) ;
V_218 -> V_228 = F_114 ( V_213 ) ;
V_218 -> V_213 = ! V_217 || ! V_129 -> V_213 ;
V_218 -> V_217 = V_217 ;
V_218 -> V_229 = F_115 ( V_214 ) ;
V_223 = ( T_4 * ) ( V_218 + 1 ) ;
if ( V_216 ) {
* V_223 ++ = F_114 ( ( V_230 << 24 ) | ( V_230 << 16 ) |
( V_231 << 8 ) | V_232 ) ;
* V_223 ++ = F_114 ( V_215 ) ;
* V_223 ++ = F_114 ( V_216 ) ;
}
#ifdef F_26
if ( V_200 ) {
* V_223 ++ = F_114 ( ( V_230 << 24 ) | ( V_230 << 16 ) |
( V_233 << 8 ) | V_234 ) ;
F_96 ( ( T_7 * ) V_223 , V_200 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_218 ) ;
}
#endif
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_24 = F_14 ( V_7 ) -> V_26 ;
V_45 . V_26 = F_14 ( V_7 ) -> V_24 ;
V_219 -> V_235 = V_236 ;
V_219 -> V_237 = 0 ;
F_76 ( V_219 , & V_45 . V_26 , & V_45 . V_24 ) ;
V_45 . V_93 = V_94 ;
if ( F_22 ( & V_45 . V_24 ) & V_63 )
V_45 . V_95 = F_64 ( V_7 ) ;
V_45 . V_98 = V_218 -> V_27 ;
V_45 . V_99 = V_218 -> V_28 ;
F_116 ( V_7 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_220 , & V_45 , NULL , false ) ;
if ( ! F_33 ( V_9 ) ) {
F_117 ( V_219 , V_9 ) ;
F_78 ( V_220 , V_219 , & V_45 , NULL , V_170 ) ;
F_81 ( V_131 , V_238 ) ;
if ( V_217 )
F_81 ( V_131 , V_239 ) ;
return;
}
F_83 ( V_219 ) ;
}
static void F_118 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_112 * V_129 = F_15 ( V_7 ) ;
T_2 V_130 = 0 , V_228 = 0 ;
struct V_1 * V_200 = NULL ;
#ifdef F_26
const T_7 * V_207 = NULL ;
struct V_113 * V_240 = F_14 ( V_7 ) ;
unsigned char V_210 [ 16 ] ;
int V_209 ;
struct V_2 * V_241 = NULL ;
#endif
if ( V_129 -> V_217 )
return;
if ( ! F_119 ( V_7 ) )
return;
#ifdef F_26
V_207 = F_106 ( V_129 ) ;
if ( ! V_3 && V_207 ) {
V_241 = F_120 ( F_48 ( F_3 ( V_7 ) -> V_132 ) ,
& V_133 , & V_240 -> V_26 ,
V_129 -> V_28 , & V_240 -> V_24 ,
F_108 ( V_129 -> V_28 ) , F_64 ( V_7 ) ) ;
if ( ! V_241 )
return;
F_121 () ;
V_200 = F_1 ( V_241 , & V_240 -> V_26 ) ;
if ( ! V_200 )
goto V_242;
V_209 = F_103 ( V_210 , V_200 , NULL , NULL , V_7 ) ;
if ( V_209 || memcmp ( V_207 , V_210 , 16 ) != 0 )
goto V_242;
} else {
V_200 = V_3 ? F_1 ( V_3 , & V_240 -> V_26 ) : NULL ;
}
#endif
if ( V_129 -> V_213 )
V_130 = F_57 ( V_129 -> V_228 ) ;
else
V_228 = F_57 ( V_129 -> V_130 ) + V_129 -> V_243 + V_129 -> V_244 + V_7 -> V_197 -
( V_129 -> V_205 << 2 ) ;
F_109 ( V_7 , V_130 , V_228 , 0 , 0 , 0 , V_200 , 1 , 0 ) ;
#ifdef F_26
V_242:
if ( V_241 ) {
F_122 () ;
F_71 ( V_241 ) ;
}
#endif
}
static void F_123 ( struct V_6 * V_7 , T_2 V_130 , T_2 V_213 ,
T_2 V_214 , T_2 V_215 , T_2 V_216 ,
struct V_1 * V_200 , T_3 V_170 )
{
F_109 ( V_7 , V_130 , V_213 , V_214 , V_215 , V_216 , V_200 , 0 , V_170 ) ;
}
static void F_124 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_245 * V_246 = F_53 ( V_3 ) ;
struct V_247 * V_248 = F_125 ( V_3 ) ;
F_123 ( V_7 , V_248 -> V_249 , V_248 -> V_250 ,
V_248 -> V_251 >> V_246 -> V_252 ,
V_253 + V_248 -> V_254 ,
V_248 -> V_255 , F_126 ( V_248 ) ,
V_246 -> V_256 ) ;
F_52 ( V_246 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 )
{
F_123 ( V_7 , F_66 ( V_154 ) -> V_156 + 1 , F_66 ( V_154 ) -> V_257 + 1 ,
V_154 -> V_258 , V_253 , V_154 -> V_69 ,
F_1 ( V_3 , & F_14 ( V_7 ) -> V_24 ) , 0 ) ;
}
static struct V_2 * F_128 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_153 * V_154 , * * V_155 ;
const struct V_112 * V_129 = F_15 ( V_7 ) ;
struct V_2 * V_259 ;
V_154 = F_63 ( V_3 , & V_155 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , F_64 ( V_7 ) ) ;
if ( V_154 )
return F_129 ( V_3 , V_7 , V_154 , V_155 , false ) ;
V_259 = F_130 ( F_68 ( V_3 ) , & V_133 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 , F_108 ( V_129 -> V_27 ) , F_64 ( V_7 ) ) ;
if ( V_259 ) {
if ( V_259 -> V_18 != V_136 ) {
F_54 ( V_259 ) ;
return V_259 ;
}
F_52 ( F_53 ( V_259 ) ) ;
return NULL ;
}
#ifdef F_131
if ( ! V_129 -> V_243 )
V_3 = F_132 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_133 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_260 V_261 ;
struct V_153 * V_154 ;
struct V_164 * V_165 ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 = F_17 ( V_3 ) ;
T_1 V_262 = F_134 ( V_7 ) -> V_263 ;
struct V_8 * V_9 = NULL ;
struct V_44 V_45 ;
bool V_264 = false ;
if ( V_7 -> V_196 == F_115 ( V_265 ) )
return F_135 ( V_3 , V_7 ) ;
if ( ! F_119 ( V_7 ) )
goto V_266;
if ( ( V_267 == 2 ||
F_136 ( V_3 ) ) && ! V_262 ) {
V_264 = F_137 ( V_3 , V_7 , L_5 ) ;
if ( ! V_264 )
goto V_266;
}
if ( F_138 ( V_3 ) && F_139 ( V_3 ) > 1 ) {
F_56 ( F_68 ( V_3 ) , V_268 ) ;
goto V_266;
}
V_154 = F_140 ( & V_269 ) ;
if ( V_154 == NULL )
goto V_266;
#ifdef F_26
F_66 ( V_154 ) -> V_84 = & V_270 ;
#endif
F_141 ( & V_261 ) ;
V_261 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_261 . V_271 = V_41 -> V_66 . V_271 ;
F_142 ( V_7 , & V_261 , 0 , NULL ) ;
if ( V_264 && ! V_261 . V_272 )
F_141 ( & V_261 ) ;
V_261 . V_273 = V_261 . V_272 ;
F_143 ( V_154 , & V_261 , V_7 ) ;
V_165 = F_73 ( V_154 ) ;
V_165 -> V_169 = F_14 ( V_7 ) -> V_26 ;
V_165 -> V_168 = F_14 ( V_7 ) -> V_24 ;
if ( ! V_264 || V_261 . V_273 )
F_144 ( V_154 , V_7 , F_68 ( V_3 ) ) ;
V_165 -> V_274 = V_3 -> V_65 ;
if ( ! V_3 -> V_65 &&
F_22 ( & V_165 -> V_169 ) & V_63 )
V_165 -> V_274 = F_64 ( V_7 ) ;
if ( ! V_262 ) {
if ( F_145 ( V_3 , V_7 ) ||
V_39 -> V_275 . V_276 . V_277 || V_39 -> V_275 . V_276 . V_278 ||
V_39 -> V_275 . V_276 . V_279 || V_39 -> V_275 . V_276 . V_280 ) {
F_146 ( & V_7 -> V_281 ) ;
V_165 -> V_173 = V_7 ;
}
if ( V_264 ) {
V_262 = F_147 ( V_3 , V_7 , & V_154 -> V_282 ) ;
V_154 -> V_283 = V_261 . V_273 ;
goto V_284;
}
if ( V_261 . V_272 &&
V_105 . V_106 &&
( V_9 = F_74 ( V_3 , & V_45 , V_154 ) ) != NULL ) {
if ( ! F_148 ( V_154 , V_9 , true ) ) {
F_56 ( F_68 ( V_3 ) , V_285 ) ;
goto V_286;
}
}
else if ( ! V_267 &&
( V_287 - F_149 ( V_3 ) <
( V_287 >> 2 ) ) &&
! F_148 ( V_154 , V_9 , false ) ) {
F_150 ( V_288 L_6 ,
& V_165 -> V_169 , F_108 ( F_15 ( V_7 ) -> V_28 ) ) ;
goto V_286;
}
V_262 = F_12 ( V_7 ) ;
}
V_284:
F_66 ( V_154 ) -> V_156 = V_262 ;
if ( F_151 ( V_3 , V_7 , V_154 ) )
goto V_286;
if ( F_72 ( V_3 , V_9 , & V_45 , V_154 ,
F_152 ( V_7 ) ) ||
V_264 )
goto V_289;
F_66 ( V_154 ) -> V_290 = V_253 ;
F_66 ( V_154 ) -> V_291 = NULL ;
F_153 ( V_3 , V_154 , V_292 ) ;
return 0 ;
V_286:
F_154 ( V_9 ) ;
V_289:
F_155 ( V_154 ) ;
V_266:
F_56 ( F_68 ( V_3 ) , V_157 ) ;
return 0 ;
}
static struct V_2 * F_156 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_153 * V_154 ,
struct V_8 * V_9 )
{
struct V_164 * V_165 ;
struct V_38 * V_293 , * V_39 = F_6 ( V_3 ) ;
struct V_294 * V_295 ;
struct V_34 * V_296 ;
struct V_40 * V_297 ;
struct V_2 * V_298 ;
#ifdef F_26
struct V_1 * V_200 ;
#endif
struct V_44 V_45 ;
if ( V_7 -> V_196 == F_115 ( V_265 ) ) {
V_298 = F_157 ( V_3 , V_7 , V_154 , V_9 ) ;
if ( V_298 == NULL )
return NULL ;
V_295 = (struct V_294 * ) V_298 ;
F_5 ( V_298 ) -> V_299 = & V_295 -> V_300 ;
V_296 = F_5 ( V_298 ) ;
V_293 = F_6 ( V_298 ) ;
V_297 = F_17 ( V_298 ) ;
memcpy ( V_293 , V_39 , sizeof( struct V_38 ) ) ;
F_28 ( V_296 -> V_301 , & V_298 -> V_68 ) ;
F_28 ( V_296 -> V_90 , & V_293 -> V_26 ) ;
V_298 -> V_92 = V_293 -> V_26 ;
F_8 ( V_298 ) -> V_20 = & V_21 ;
V_298 -> V_82 = V_83 ;
#ifdef F_26
V_297 -> V_84 = & V_85 ;
#endif
V_293 -> V_302 = NULL ;
V_293 -> V_303 = NULL ;
V_293 -> V_304 = NULL ;
V_293 -> V_101 = NULL ;
V_293 -> V_305 = F_64 ( V_7 ) ;
V_293 -> V_306 = F_14 ( V_7 ) -> V_140 ;
V_293 -> V_307 = F_158 ( F_14 ( V_7 ) ) ;
F_45 ( V_298 , F_8 ( V_298 ) -> V_122 ) ;
return V_298 ;
}
V_165 = F_73 ( V_154 ) ;
if ( F_138 ( V_3 ) )
goto V_308;
if ( ! V_9 ) {
V_9 = F_74 ( V_3 , & V_45 , V_154 ) ;
if ( ! V_9 )
goto V_139;
}
V_298 = F_159 ( V_3 , V_154 , V_7 ) ;
if ( V_298 == NULL )
goto V_309;
V_298 -> V_103 = V_104 ;
F_35 ( V_298 , V_9 , NULL , NULL ) ;
F_2 ( V_298 , V_7 ) ;
V_295 = (struct V_294 * ) V_298 ;
F_5 ( V_298 ) -> V_299 = & V_295 -> V_300 ;
V_297 = F_17 ( V_298 ) ;
V_296 = F_5 ( V_298 ) ;
V_293 = F_6 ( V_298 ) ;
memcpy ( V_293 , V_39 , sizeof( struct V_38 ) ) ;
V_298 -> V_68 = V_165 -> V_169 ;
V_293 -> V_26 = V_165 -> V_168 ;
V_298 -> V_92 = V_165 -> V_168 ;
V_298 -> V_65 = V_165 -> V_274 ;
V_296 -> V_310 = NULL ;
V_293 -> V_302 = NULL ;
V_293 -> V_303 = NULL ;
V_293 -> V_275 . V_311 = V_39 -> V_275 . V_311 ;
V_293 -> V_304 = NULL ;
if ( V_165 -> V_173 != NULL ) {
V_293 -> V_304 = F_160 ( V_165 -> V_173 ,
F_161 ( V_3 , V_227 ) ) ;
F_162 ( V_165 -> V_173 ) ;
V_165 -> V_173 = NULL ;
if ( V_293 -> V_304 )
F_163 ( V_293 -> V_304 , V_298 ) ;
}
V_293 -> V_101 = NULL ;
V_293 -> V_305 = F_64 ( V_7 ) ;
V_293 -> V_306 = F_14 ( V_7 ) -> V_140 ;
V_293 -> V_307 = F_158 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_101 )
V_293 -> V_101 = F_164 ( V_298 , V_39 -> V_101 ) ;
F_8 ( V_298 ) -> V_74 = 0 ;
if ( V_293 -> V_101 )
F_8 ( V_298 ) -> V_74 = ( V_293 -> V_101 -> V_109 +
V_293 -> V_101 -> V_108 ) ;
F_165 ( V_298 ) ;
F_45 ( V_298 , F_44 ( V_9 ) ) ;
V_297 -> V_312 = F_166 ( V_9 ) ;
if ( F_17 ( V_3 ) -> V_66 . V_271 &&
F_17 ( V_3 ) -> V_66 . V_271 < V_297 -> V_312 )
V_297 -> V_312 = F_17 ( V_3 ) -> V_66 . V_271 ;
F_167 ( V_298 ) ;
V_296 -> V_301 = V_296 -> V_90 = V_102 ;
V_296 -> V_91 = V_102 ;
#ifdef F_26
if ( ( V_200 = F_1 ( V_3 , & V_298 -> V_68 ) ) != NULL ) {
F_91 ( V_298 , (union V_174 * ) & V_298 -> V_68 ,
V_51 , V_200 -> V_200 , V_200 -> V_313 ,
F_161 ( V_3 , V_227 ) ) ;
}
#endif
if ( F_168 ( V_3 , V_298 ) < 0 ) {
F_169 ( V_298 ) ;
F_69 ( V_298 ) ;
goto V_139;
}
F_10 ( V_298 , NULL ) ;
return V_298 ;
V_308:
F_56 ( F_68 ( V_3 ) , V_268 ) ;
V_309:
F_154 ( V_9 ) ;
V_139:
F_56 ( F_68 ( V_3 ) , V_157 ) ;
return NULL ;
}
static T_8 F_170 ( struct V_6 * V_7 )
{
if ( V_7 -> V_235 == V_314 ) {
if ( ! F_171 ( V_7 -> V_197 , & F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_7 -> V_237 ) ) {
V_7 -> V_235 = V_315 ;
return 0 ;
}
}
V_7 -> V_237 = ~ F_172 ( F_171 ( V_7 -> V_197 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , 0 ) ) ;
if ( V_7 -> V_197 <= 76 ) {
return F_173 ( V_7 ) ;
}
return 0 ;
}
static int V_87 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_6 * V_316 = NULL ;
if ( V_7 -> V_196 == F_115 ( V_265 ) )
return V_83 ( V_3 , V_7 ) ;
#ifdef F_26
if ( F_105 ( V_3 , V_7 ) )
goto V_317;
#endif
if ( F_174 ( V_3 , V_7 ) )
goto V_317;
if ( V_39 -> V_275 . V_311 )
V_316 = F_160 ( V_7 , F_161 ( V_3 , V_227 ) ) ;
if ( V_3 -> V_18 == V_318 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_175 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_149 -> V_319 ( V_9 , V_39 -> V_16 ) == NULL ) {
F_154 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_176 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_197 ) ;
if ( V_316 )
goto V_320;
return 0 ;
}
if ( V_7 -> V_197 < F_177 ( V_7 ) || F_178 ( V_7 ) )
goto V_321;
if ( V_3 -> V_18 == V_143 ) {
struct V_2 * V_259 = F_128 ( V_3 , V_7 ) ;
if ( ! V_259 )
goto V_317;
if( V_259 != V_3 ) {
F_175 ( V_259 , V_7 ) ;
if ( F_179 ( V_3 , V_259 , V_7 ) )
goto V_322;
if ( V_316 )
F_180 ( V_316 ) ;
return 0 ;
}
} else
F_175 ( V_3 , V_7 ) ;
if ( F_181 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_197 ) )
goto V_322;
if ( V_316 )
goto V_320;
return 0 ;
V_322:
F_118 ( V_3 , V_7 ) ;
V_317:
if ( V_316 )
F_180 ( V_316 ) ;
F_83 ( V_7 ) ;
return 0 ;
V_321:
F_81 ( F_68 ( V_3 ) , V_323 ) ;
F_81 ( F_68 ( V_3 ) , V_324 ) ;
goto V_317;
V_320:
V_41 = F_17 ( V_3 ) ;
if ( F_134 ( V_316 ) -> V_325 == V_41 -> V_326 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_120 | V_119 ) ) ) {
if ( V_39 -> V_275 . V_276 . V_277 || V_39 -> V_275 . V_276 . V_278 )
V_39 -> V_305 = F_64 ( V_316 ) ;
if ( V_39 -> V_275 . V_276 . V_279 || V_39 -> V_275 . V_276 . V_280 )
V_39 -> V_306 = F_14 ( V_316 ) -> V_140 ;
if ( V_39 -> V_275 . V_276 . V_327 )
V_39 -> V_307 = F_158 ( F_14 ( V_316 ) ) ;
if ( F_145 ( V_3 , V_316 ) ) {
F_163 ( V_316 , V_3 ) ;
V_316 = F_182 ( & V_39 -> V_304 , V_316 ) ;
} else {
F_180 ( V_316 ) ;
V_316 = F_182 ( & V_39 -> V_304 , NULL ) ;
}
}
F_83 ( V_316 ) ;
return 0 ;
}
static int F_183 ( struct V_6 * V_7 )
{
const struct V_112 * V_129 ;
const struct V_113 * V_127 ;
struct V_2 * V_3 ;
int V_328 ;
struct V_131 * V_131 = F_48 ( V_7 -> V_132 ) ;
if ( V_7 -> V_329 != V_330 )
goto V_331;
F_81 ( V_131 , V_332 ) ;
if ( ! F_184 ( V_7 , sizeof( struct V_112 ) ) )
goto V_331;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_205 < sizeof( struct V_112 ) / 4 )
goto V_333;
if ( ! F_184 ( V_7 , V_129 -> V_205 * 4 ) )
goto V_331;
if ( ! F_185 ( V_7 ) && F_170 ( V_7 ) )
goto V_334;
V_129 = F_15 ( V_7 ) ;
V_127 = F_14 ( V_7 ) ;
F_134 ( V_7 ) -> V_130 = F_57 ( V_129 -> V_130 ) ;
F_134 ( V_7 ) -> V_325 = ( F_134 ( V_7 ) -> V_130 + V_129 -> V_243 + V_129 -> V_244 +
V_7 -> V_197 - V_129 -> V_205 * 4 ) ;
F_134 ( V_7 ) -> V_228 = F_57 ( V_129 -> V_228 ) ;
F_134 ( V_7 ) -> V_263 = 0 ;
F_134 ( V_7 ) -> V_335 = F_158 ( V_127 ) ;
F_134 ( V_7 ) -> V_336 = 0 ;
V_3 = F_186 ( & V_133 , V_7 , V_129 -> V_28 , V_129 -> V_27 ) ;
if ( ! V_3 )
goto V_337;
V_338:
if ( V_3 -> V_18 == V_136 )
goto V_339;
if ( V_127 -> V_140 < F_6 ( V_3 ) -> V_141 ) {
F_56 ( V_131 , V_142 ) ;
goto V_340;
}
if ( ! F_187 ( V_3 , V_341 , V_7 ) )
goto V_340;
if ( F_174 ( V_3 , V_7 ) )
goto V_340;
F_188 ( V_3 , V_7 ) ;
V_7 -> V_132 = NULL ;
F_189 ( V_3 ) ;
V_328 = 0 ;
if ( ! F_55 ( V_3 ) ) {
#ifdef F_190
struct V_40 * V_41 = F_17 ( V_3 ) ;
if ( ! V_41 -> V_342 . V_343 && V_41 -> V_342 . V_344 )
V_41 -> V_342 . V_343 = F_191 () ;
if ( V_41 -> V_342 . V_343 )
V_328 = V_87 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_192 ( V_3 , V_7 ) )
V_328 = V_87 ( V_3 , V_7 ) ;
}
} else if ( F_193 ( F_194 ( V_3 , V_7 ,
V_3 -> V_345 + V_3 -> V_346 ) ) ) {
F_70 ( V_3 ) ;
F_56 ( V_131 , V_347 ) ;
goto V_340;
}
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
return V_328 ? - 1 : 0 ;
V_337:
if ( ! F_187 ( NULL , V_341 , V_7 ) )
goto V_331;
if ( V_7 -> V_197 < ( V_129 -> V_205 << 2 ) || F_178 ( V_7 ) ) {
V_334:
F_81 ( V_131 , V_323 ) ;
V_333:
F_81 ( V_131 , V_324 ) ;
} else {
F_118 ( NULL , V_7 ) ;
}
V_331:
F_83 ( V_7 ) ;
return 0 ;
V_340:
F_71 ( V_3 ) ;
goto V_331;
V_339:
if ( ! F_187 ( NULL , V_341 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_331;
}
if ( V_7 -> V_197 < ( V_129 -> V_205 << 2 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_333;
}
if ( F_178 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_334;
}
switch ( F_195 ( F_53 ( V_3 ) , V_7 , V_129 ) ) {
case V_348 :
{
struct V_2 * V_349 ;
V_349 = F_120 ( F_48 ( V_7 -> V_132 ) , & V_133 ,
& F_14 ( V_7 ) -> V_26 , V_129 -> V_28 ,
& F_14 ( V_7 ) -> V_24 ,
F_108 ( V_129 -> V_27 ) , F_64 ( V_7 ) ) ;
if ( V_349 != NULL ) {
struct V_245 * V_246 = F_53 ( V_3 ) ;
F_196 ( V_246 , & V_105 ) ;
F_52 ( V_246 ) ;
V_3 = V_349 ;
goto V_338;
}
}
case V_350 :
F_124 ( V_3 , V_7 ) ;
break;
case V_351 :
goto V_337;
case V_352 : ;
}
goto V_331;
}
static void F_197 ( struct V_6 * V_7 )
{
const struct V_113 * V_127 ;
const struct V_112 * V_129 ;
struct V_2 * V_3 ;
if ( V_7 -> V_329 != V_330 )
return;
if ( ! F_184 ( V_7 , F_198 ( V_7 ) + sizeof( struct V_112 ) ) )
return;
V_127 = F_14 ( V_7 ) ;
V_129 = F_15 ( V_7 ) ;
if ( V_129 -> V_205 < sizeof( struct V_112 ) / 4 )
return;
V_3 = F_130 ( F_48 ( V_7 -> V_132 ) , & V_133 ,
& V_127 -> V_26 , V_129 -> V_28 ,
& V_127 -> V_24 , F_108 ( V_129 -> V_27 ) ,
F_64 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_353 = V_354 ;
if ( V_3 -> V_18 != V_136 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
if ( V_9 )
V_9 = F_199 ( V_9 , F_6 ( V_3 ) -> V_16 ) ;
if ( V_9 &&
F_5 ( V_3 ) -> V_13 == V_7 -> V_14 )
F_200 ( V_7 , V_9 ) ;
}
}
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = F_8 ( V_3 ) ;
F_202 ( V_3 ) ;
V_37 -> V_20 = & V_86 ;
#ifdef F_26
F_17 ( V_3 ) -> V_84 = & V_88 ;
#endif
return 0 ;
}
static void F_203 ( struct V_2 * V_3 )
{
F_204 ( V_3 ) ;
F_205 ( V_3 ) ;
}
static void F_206 ( struct V_355 * V_130 ,
const struct V_2 * V_3 , struct V_153 * V_154 , int V_356 , T_9 V_357 )
{
int V_358 = V_154 -> V_359 - V_360 ;
const struct V_4 * V_361 = & F_73 ( V_154 ) -> V_168 ;
const struct V_4 * V_27 = & F_73 ( V_154 ) -> V_169 ;
if ( V_358 < 0 )
V_358 = 0 ;
F_207 ( V_130 ,
L_7
L_8 ,
V_356 ,
V_361 -> V_25 [ 0 ] , V_361 -> V_25 [ 1 ] ,
V_361 -> V_25 [ 2 ] , V_361 -> V_25 [ 3 ] ,
F_73 ( V_154 ) -> V_362 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] ,
F_108 ( F_73 ( V_154 ) -> V_363 ) ,
V_158 ,
0 , 0 ,
1 ,
F_208 ( V_358 ) ,
V_154 -> V_364 ,
F_209 ( F_210 ( V_130 ) , V_357 ) ,
0 ,
0 ,
0 , V_154 ) ;
}
static void F_211 ( struct V_355 * V_130 , struct V_2 * V_365 , int V_356 )
{
const struct V_4 * V_27 , * V_361 ;
T_10 V_366 , V_367 ;
int V_368 ;
unsigned long V_369 ;
const struct V_34 * V_35 = F_5 ( V_365 ) ;
const struct V_40 * V_41 = F_17 ( V_365 ) ;
const struct V_36 * V_37 = F_8 ( V_365 ) ;
V_27 = & V_365 -> V_68 ;
V_361 = & V_365 -> V_92 ;
V_366 = F_108 ( V_35 -> V_114 ) ;
V_367 = F_108 ( V_35 -> V_100 ) ;
if ( V_37 -> V_370 == V_371 ) {
V_368 = 1 ;
V_369 = V_37 -> V_372 ;
} else if ( V_37 -> V_370 == V_373 ) {
V_368 = 4 ;
V_369 = V_37 -> V_372 ;
} else if ( F_212 ( & V_365 -> V_374 ) ) {
V_368 = 2 ;
V_369 = V_365 -> V_374 . V_359 ;
} else {
V_368 = 0 ;
V_369 = V_360 ;
}
F_207 ( V_130 ,
L_7
L_9 ,
V_356 ,
V_361 -> V_25 [ 0 ] , V_361 -> V_25 [ 1 ] ,
V_361 -> V_25 [ 2 ] , V_361 -> V_25 [ 3 ] , V_367 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_366 ,
V_365 -> V_18 ,
V_41 -> V_70 - V_41 -> V_144 ,
( V_365 -> V_18 == V_143 ) ? V_365 -> V_375 : ( V_41 -> V_326 - V_41 -> V_376 ) ,
V_368 ,
F_213 ( V_369 - V_360 ) ,
V_37 -> V_377 ,
F_209 ( F_210 ( V_130 ) , F_214 ( V_365 ) ) ,
V_37 -> V_378 ,
F_215 ( V_365 ) ,
F_216 ( & V_365 -> V_379 ) , V_365 ,
F_208 ( V_37 -> V_380 ) ,
F_208 ( V_37 -> V_381 . V_382 ) ,
( V_37 -> V_381 . V_383 << 1 ) | V_37 -> V_381 . V_384 ,
V_41 -> V_385 ,
F_217 ( V_41 ) ? - 1 : V_41 -> V_386
) ;
}
static void F_218 ( struct V_355 * V_130 ,
struct V_245 * V_246 , int V_356 )
{
const struct V_4 * V_27 , * V_361 ;
T_10 V_366 , V_367 ;
T_11 V_387 = V_246 -> V_388 - F_219 () ;
V_27 = & V_246 -> V_389 ;
V_361 = & V_246 -> V_390 ;
V_366 = F_108 ( V_246 -> V_391 ) ;
V_367 = F_108 ( V_246 -> V_392 ) ;
F_207 ( V_130 ,
L_7
L_10 ,
V_356 ,
V_361 -> V_25 [ 0 ] , V_361 -> V_25 [ 1 ] ,
V_361 -> V_25 [ 2 ] , V_361 -> V_25 [ 3 ] , V_367 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_366 ,
V_246 -> V_393 , 0 , 0 ,
3 , F_213 ( V_387 ) , 0 , 0 , 0 , 0 ,
F_216 ( & V_246 -> V_394 ) , V_246 ) ;
}
static int F_220 ( struct V_355 * V_130 , void * V_395 )
{
struct V_396 * V_397 ;
struct V_2 * V_3 = V_395 ;
if ( V_395 == V_398 ) {
F_221 ( V_130 ,
L_11
L_12
L_13
L_14
L_15 ) ;
goto V_139;
}
V_397 = V_130 -> V_399 ;
switch ( V_397 -> V_400 ) {
case V_401 :
case V_402 :
if ( V_3 -> V_18 == V_136 )
F_218 ( V_130 , V_395 , V_397 -> V_403 ) ;
else
F_211 ( V_130 , V_395 , V_397 -> V_403 ) ;
break;
case V_404 :
F_206 ( V_130 , V_397 -> V_405 , V_395 , V_397 -> V_403 , V_397 -> V_357 ) ;
break;
}
V_139:
return 0 ;
}
int T_12 F_222 ( struct V_131 * V_131 )
{
return F_223 ( V_131 , & V_406 ) ;
}
void F_224 ( struct V_131 * V_131 )
{
F_225 ( V_131 , & V_406 ) ;
}
static void F_226 ( struct V_2 * V_3 , int V_407 )
{
struct V_34 * V_35 = F_5 ( V_3 ) ;
F_227 ( V_3 , F_228 ( struct V_34 , V_299 ) ) ;
V_407 -= F_228 ( struct V_34 , V_299 ) + sizeof( V_35 -> V_299 ) ;
memset ( & V_35 -> V_299 + 1 , 0 , V_407 ) ;
}
static int T_12 F_229 ( struct V_131 * V_131 )
{
return F_230 ( & V_131 -> V_221 . F_17 , V_408 ,
V_409 , V_94 , V_131 ) ;
}
static void T_13 F_231 ( struct V_131 * V_131 )
{
F_232 ( V_131 -> V_221 . F_17 ) ;
}
static void T_13 F_233 ( struct V_410 * V_411 )
{
F_234 ( & V_133 , & V_105 , V_51 ) ;
}
int T_14 F_235 ( void )
{
int V_328 ;
V_328 = F_236 ( & V_412 , V_94 ) ;
if ( V_328 )
goto V_139;
V_328 = F_237 ( & V_413 ) ;
if ( V_328 )
goto V_414;
V_328 = F_238 ( & V_415 ) ;
if ( V_328 )
goto V_416;
V_139:
return V_328 ;
V_416:
F_239 ( & V_413 ) ;
V_414:
F_240 ( & V_412 , V_94 ) ;
goto V_139;
}
void F_241 ( void )
{
F_242 ( & V_415 ) ;
F_239 ( & V_413 ) ;
F_240 ( & V_412 , V_94 ) ;
}
