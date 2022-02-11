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
V_33 -> V_59 = V_54 -> V_9 ;
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
! F_23 ( & V_39 -> V_24 , & V_33 -> V_59 ) ) {
V_41 -> V_66 . V_68 = 0 ;
V_41 -> V_66 . V_67 = 0 ;
V_41 -> V_69 = 0 ;
}
V_39 -> V_24 = V_33 -> V_59 ;
V_39 -> V_70 = V_45 . V_54 ;
if ( V_46 == V_71 ) {
T_2 V_72 = V_37 -> V_73 ;
struct V_74 sin ;
F_24 ( V_3 , L_1 ) ;
if ( F_25 ( V_3 ) )
return - V_62 ;
sin . V_75 = V_76 ;
sin . V_77 = V_33 -> V_78 ;
sin . V_79 . V_80 = V_33 -> V_59 . V_25 [ 3 ] ;
V_37 -> V_20 = & V_21 ;
V_3 -> V_81 = V_82 ;
#ifdef F_26
V_41 -> V_83 = & V_84 ;
#endif
V_47 = F_27 ( V_3 , (struct V_29 * ) & sin , sizeof( sin ) ) ;
if ( V_47 ) {
V_37 -> V_73 = V_72 ;
V_37 -> V_20 = & V_85 ;
V_3 -> V_81 = V_86 ;
#ifdef F_26
V_41 -> V_83 = & V_87 ;
#endif
goto V_88;
} else {
F_28 ( V_35 -> V_89 , & V_39 -> V_26 ) ;
F_28 ( V_35 -> V_90 ,
& V_39 -> V_91 ) ;
}
return V_47 ;
}
if ( ! F_21 ( & V_39 -> V_91 ) )
V_26 = & V_39 -> V_91 ;
V_45 . V_92 = V_93 ;
V_45 . V_24 = V_39 -> V_24 ;
V_45 . V_26 = V_26 ? * V_26 : V_39 -> V_26 ;
V_45 . V_94 = V_3 -> V_65 ;
V_45 . V_95 = V_3 -> V_96 ;
V_45 . V_97 = V_33 -> V_78 ;
V_45 . V_98 = V_35 -> V_99 ;
V_42 = F_29 ( & V_45 , V_39 -> V_100 , & V_43 ) ;
F_30 ( V_3 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_3 , & V_45 , V_42 , true ) ;
if ( F_33 ( V_9 ) ) {
V_47 = F_34 ( V_9 ) ;
goto V_88;
}
if ( V_26 == NULL ) {
V_26 = & V_45 . V_26 ;
V_39 -> V_91 = * V_26 ;
}
V_39 -> V_26 = * V_26 ;
V_35 -> V_90 = V_101 ;
V_3 -> V_102 = V_103 ;
F_35 ( V_3 , V_9 , NULL , NULL ) ;
V_11 = (struct V_10 * ) V_9 ;
if ( V_104 . V_105 &&
! V_41 -> V_66 . V_67 &&
F_23 ( & V_11 -> V_106 . V_5 , & V_39 -> V_24 ) )
F_36 ( V_3 , V_9 ) ;
V_37 -> V_73 = 0 ;
if ( V_39 -> V_100 )
V_37 -> V_73 = ( V_39 -> V_100 -> V_107 +
V_39 -> V_100 -> V_108 ) ;
V_41 -> V_66 . V_109 = V_110 - sizeof( struct V_111 ) - sizeof( struct V_112 ) ;
V_35 -> V_113 = V_33 -> V_78 ;
F_37 ( V_3 , V_114 ) ;
V_47 = F_38 ( & V_104 , V_3 ) ;
if ( V_47 )
goto V_115;
if ( ! V_41 -> V_69 && F_39 ( ! V_41 -> V_116 ) )
V_41 -> V_69 = F_13 ( V_39 -> V_26 . V_25 ,
V_39 -> V_24 . V_25 ,
V_35 -> V_99 ,
V_35 -> V_113 ) ;
V_47 = F_40 ( V_3 ) ;
if ( V_47 )
goto V_115;
return 0 ;
V_115:
F_37 ( V_3 , V_19 ) ;
F_41 ( V_3 ) ;
V_88:
V_35 -> V_113 = 0 ;
V_3 -> V_117 = 0 ;
return V_47 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
if ( ( 1 << V_3 -> V_18 ) & ( V_118 | V_119 ) )
return;
V_9 = F_43 ( V_3 , F_17 ( V_3 ) -> V_120 ) ;
if ( ! V_9 )
return;
if ( F_8 ( V_3 ) -> V_121 > F_44 ( V_9 ) ) {
F_45 ( V_3 , F_44 ( V_9 ) ) ;
F_46 ( V_3 ) ;
}
}
static void F_47 ( struct V_6 * V_7 , struct V_122 * V_100 ,
T_3 type , T_3 V_123 , int V_124 , T_4 V_125 )
{
const struct V_112 * V_126 = ( const struct V_112 * ) V_7 -> V_127 ;
const struct V_111 * V_128 = (struct V_111 * ) ( V_7 -> V_127 + V_124 ) ;
struct V_38 * V_39 ;
struct V_2 * V_3 ;
int V_47 ;
struct V_40 * V_41 ;
T_1 V_129 ;
struct V_130 * V_130 = F_48 ( V_7 -> V_131 ) ;
V_3 = F_49 ( V_130 , & V_132 , & V_126 -> V_24 ,
V_128 -> V_27 , & V_126 -> V_26 , V_128 -> V_28 , V_7 -> V_131 -> V_133 ) ;
if ( V_3 == NULL ) {
F_50 ( V_130 , F_51 ( V_7 -> V_131 ) ,
V_134 ) ;
return;
}
if ( V_3 -> V_18 == V_135 ) {
F_52 ( F_53 ( V_3 ) ) ;
return;
}
F_54 ( V_3 ) ;
if ( F_55 ( V_3 ) && type != V_136 )
F_56 ( V_130 , V_137 ) ;
if ( V_3 -> V_18 == V_19 )
goto V_138;
if ( F_14 ( V_7 ) -> V_139 < F_6 ( V_3 ) -> V_140 ) {
F_56 ( V_130 , V_141 ) ;
goto V_138;
}
V_41 = F_17 ( V_3 ) ;
V_129 = F_57 ( V_128 -> V_129 ) ;
if ( V_3 -> V_18 != V_142 &&
! F_58 ( V_129 , V_41 -> V_143 , V_41 -> V_144 ) ) {
F_56 ( V_130 , V_145 ) ;
goto V_138;
}
V_39 = F_6 ( V_3 ) ;
if ( type == V_146 ) {
struct V_8 * V_9 = F_59 ( V_3 , V_39 -> V_147 ) ;
if ( V_9 )
V_9 -> V_148 -> V_149 ( V_9 , V_3 , V_7 ) ;
goto V_138;
}
if ( type == V_136 ) {
if ( V_3 -> V_18 == V_142 )
goto V_138;
V_41 -> V_120 = F_57 ( V_125 ) ;
if ( ! F_55 ( V_3 ) )
F_42 ( V_3 ) ;
else if ( ! F_60 ( V_150 ,
& V_41 -> V_151 ) )
F_61 ( V_3 ) ;
goto V_138;
}
F_62 ( type , V_123 , & V_47 ) ;
switch ( V_3 -> V_18 ) {
struct V_152 * V_153 , * * V_154 ;
case V_142 :
if ( F_55 ( V_3 ) )
goto V_138;
V_153 = F_63 ( V_3 , & V_154 , V_128 -> V_27 , & V_126 -> V_24 ,
& V_126 -> V_26 , F_64 ( V_7 ) ) ;
if ( ! V_153 )
goto V_138;
F_65 ( V_153 -> V_3 != NULL ) ;
if ( V_129 != F_66 ( V_153 ) -> V_155 ) {
F_56 ( V_130 , V_145 ) ;
goto V_138;
}
F_67 ( V_3 , V_153 , V_154 ) ;
F_56 ( F_68 ( V_3 ) , V_156 ) ;
goto V_138;
case V_114 :
case V_157 :
if ( ! F_55 ( V_3 ) ) {
V_3 -> V_158 = V_47 ;
V_3 -> V_159 ( V_3 ) ;
F_69 ( V_3 ) ;
} else
V_3 -> V_160 = V_47 ;
goto V_138;
}
if ( ! F_55 ( V_3 ) && V_39 -> V_161 ) {
V_3 -> V_158 = V_47 ;
V_3 -> V_159 ( V_3 ) ;
} else
V_3 -> V_160 = V_47 ;
V_138:
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
}
static int F_72 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_152 * V_153 ,
T_5 V_162 )
{
struct V_163 * V_164 = F_73 ( V_153 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_6 * V_7 ;
int V_47 = - V_165 ;
if ( ! V_9 && ( V_9 = F_74 ( V_3 , V_45 , V_153 ) ) == NULL )
goto V_166;
V_7 = F_75 ( V_3 , V_9 , V_153 , NULL ) ;
if ( V_7 ) {
F_76 ( V_7 , & V_164 -> V_167 , & V_164 -> V_168 ) ;
V_45 -> V_24 = V_164 -> V_168 ;
F_77 ( V_7 , V_162 ) ;
V_47 = F_78 ( V_3 , V_7 , V_45 , V_39 -> V_100 , V_39 -> V_169 ) ;
V_47 = F_79 ( V_47 ) ;
}
V_166:
return V_47 ;
}
static int F_80 ( struct V_2 * V_3 , struct V_152 * V_153 )
{
struct V_44 V_45 ;
int V_170 ;
V_170 = F_72 ( V_3 , NULL , & V_45 , V_153 , 0 ) ;
if ( ! V_170 )
F_81 ( F_68 ( V_3 ) , V_171 ) ;
return V_170 ;
}
static void F_82 ( struct V_152 * V_153 )
{
F_83 ( F_73 ( V_153 ) -> V_172 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_84 ( V_3 , (union V_173 * ) V_5 , V_51 ) ;
}
static struct V_1 * F_85 ( struct V_2 * V_3 ,
struct V_2 * V_174 )
{
return F_1 ( V_3 , & F_6 ( V_174 ) -> V_24 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_152 * V_153 )
{
return F_1 ( V_3 , & F_73 ( V_153 ) -> V_168 ) ;
}
static int F_87 ( struct V_2 * V_3 , char T_6 * V_175 ,
int V_176 )
{
struct V_177 V_178 ;
struct V_32 * V_179 = (struct V_32 * ) & V_178 . V_180 ;
if ( V_176 < sizeof( V_178 ) )
return - V_49 ;
if ( F_88 ( & V_178 , V_175 , sizeof( V_178 ) ) )
return - V_181 ;
if ( V_179 -> V_50 != V_51 )
return - V_49 ;
if ( ! V_178 . V_182 ) {
if ( F_89 ( & V_179 -> V_59 ) )
return F_90 ( V_3 , (union V_173 * ) & V_179 -> V_59 . V_25 [ 3 ] ,
V_76 ) ;
return F_90 ( V_3 , (union V_173 * ) & V_179 -> V_59 ,
V_51 ) ;
}
if ( V_178 . V_182 > V_183 )
return - V_49 ;
if ( F_89 ( & V_179 -> V_59 ) )
return F_91 ( V_3 , (union V_173 * ) & V_179 -> V_59 . V_25 [ 3 ] ,
V_76 , V_178 . V_184 , V_178 . V_182 , V_185 ) ;
return F_91 ( V_3 , (union V_173 * ) & V_179 -> V_59 ,
V_51 , V_178 . V_184 , V_178 . V_182 , V_185 ) ;
}
static int F_92 ( struct V_186 * V_187 ,
const struct V_4 * V_24 ,
const struct V_4 * V_26 , int V_188 )
{
struct V_189 * V_190 ;
struct V_191 V_192 ;
V_190 = & V_187 -> V_193 . V_194 ;
V_190 -> V_26 = * V_26 ;
V_190 -> V_24 = * V_24 ;
V_190 -> V_195 = F_93 ( V_93 ) ;
V_190 -> V_196 = F_93 ( V_188 ) ;
F_94 ( & V_192 , V_190 , sizeof( * V_190 ) ) ;
return F_95 ( & V_187 -> V_197 , & V_192 , sizeof( * V_190 ) ) ;
}
static int F_96 ( char * V_198 , struct V_1 * V_199 ,
const struct V_4 * V_24 , struct V_4 * V_26 ,
const struct V_111 * V_128 )
{
struct V_186 * V_187 ;
struct V_200 * V_201 ;
V_187 = F_97 () ;
if ( ! V_187 )
goto V_202;
V_201 = & V_187 -> V_197 ;
if ( F_98 ( V_201 ) )
goto V_203;
if ( F_92 ( V_187 , V_24 , V_26 , V_128 -> V_204 << 2 ) )
goto V_203;
if ( F_99 ( V_187 , V_128 ) )
goto V_203;
if ( F_100 ( V_187 , V_199 ) )
goto V_203;
if ( F_101 ( V_201 , V_198 ) )
goto V_203;
F_102 () ;
return 0 ;
V_203:
F_102 () ;
V_202:
memset ( V_198 , 0 , 16 ) ;
return 1 ;
}
static int F_103 ( char * V_198 , struct V_1 * V_199 ,
const struct V_2 * V_3 ,
const struct V_152 * V_153 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_26 , * V_24 ;
struct V_186 * V_187 ;
struct V_200 * V_201 ;
const struct V_111 * V_128 = F_15 ( V_7 ) ;
if ( V_3 ) {
V_26 = & F_6 ( V_3 ) -> V_26 ;
V_24 = & F_6 ( V_3 ) -> V_24 ;
} else if ( V_153 ) {
V_26 = & F_73 ( V_153 ) -> V_167 ;
V_24 = & F_73 ( V_153 ) -> V_168 ;
} else {
const struct V_112 * V_205 = F_14 ( V_7 ) ;
V_26 = & V_205 -> V_26 ;
V_24 = & V_205 -> V_24 ;
}
V_187 = F_97 () ;
if ( ! V_187 )
goto V_202;
V_201 = & V_187 -> V_197 ;
if ( F_98 ( V_201 ) )
goto V_203;
if ( F_92 ( V_187 , V_24 , V_26 , V_7 -> V_196 ) )
goto V_203;
if ( F_99 ( V_187 , V_128 ) )
goto V_203;
if ( F_104 ( V_187 , V_7 , V_128 -> V_204 << 2 ) )
goto V_203;
if ( F_100 ( V_187 , V_199 ) )
goto V_203;
if ( F_101 ( V_201 , V_198 ) )
goto V_203;
F_102 () ;
return 0 ;
V_203:
F_102 () ;
V_202:
memset ( V_198 , 0 , 16 ) ;
return 1 ;
}
static int F_105 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_206 = NULL ;
struct V_1 * V_207 ;
const struct V_112 * V_205 = F_14 ( V_7 ) ;
const struct V_111 * V_128 = F_15 ( V_7 ) ;
int V_208 ;
T_3 V_209 [ 16 ] ;
V_207 = F_1 ( V_3 , & V_205 -> V_26 ) ;
V_206 = F_106 ( V_128 ) ;
if ( ! V_207 && ! V_206 )
return 0 ;
if ( V_207 && ! V_206 ) {
F_56 ( F_68 ( V_3 ) , V_210 ) ;
return 1 ;
}
if ( ! V_207 && V_206 ) {
F_56 ( F_68 ( V_3 ) , V_211 ) ;
return 1 ;
}
V_208 = F_103 ( V_209 ,
V_207 ,
NULL , NULL , V_7 ) ;
if ( V_208 || memcmp ( V_206 , V_209 , 16 ) != 0 ) {
F_107 ( L_2 ,
V_208 ? L_3 : L_4 ,
& V_205 -> V_26 , F_108 ( V_128 -> V_28 ) ,
& V_205 -> V_24 , F_108 ( V_128 -> V_27 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_109 ( struct V_6 * V_7 , T_2 V_129 , T_2 V_212 , T_2 V_213 ,
T_2 V_214 , T_2 V_215 ,
struct V_1 * V_199 , int V_216 , T_3 V_169 )
{
const struct V_111 * V_128 = F_15 ( V_7 ) ;
struct V_111 * V_217 ;
struct V_6 * V_218 ;
struct V_44 V_45 ;
struct V_130 * V_130 = F_48 ( F_3 ( V_7 ) -> V_131 ) ;
struct V_2 * V_219 = V_130 -> V_220 . F_17 ;
unsigned int V_221 = sizeof( struct V_111 ) ;
struct V_8 * V_9 ;
T_4 * V_222 ;
if ( V_215 )
V_221 += V_223 ;
#ifdef F_26
if ( V_199 )
V_221 += V_224 ;
#endif
V_218 = F_110 ( V_225 + sizeof( struct V_112 ) + V_221 ,
V_226 ) ;
if ( V_218 == NULL )
return;
F_111 ( V_218 , V_225 + sizeof( struct V_112 ) + V_221 ) ;
V_217 = (struct V_111 * ) F_112 ( V_218 , V_221 ) ;
F_113 ( V_218 ) ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_217 -> V_27 = V_128 -> V_28 ;
V_217 -> V_28 = V_128 -> V_27 ;
V_217 -> V_204 = V_221 / 4 ;
V_217 -> V_129 = F_114 ( V_129 ) ;
V_217 -> V_227 = F_114 ( V_212 ) ;
V_217 -> V_212 = ! V_216 || ! V_128 -> V_212 ;
V_217 -> V_216 = V_216 ;
V_217 -> V_228 = F_115 ( V_213 ) ;
V_222 = ( T_4 * ) ( V_217 + 1 ) ;
if ( V_215 ) {
* V_222 ++ = F_114 ( ( V_229 << 24 ) | ( V_229 << 16 ) |
( V_230 << 8 ) | V_231 ) ;
* V_222 ++ = F_114 ( V_214 ) ;
* V_222 ++ = F_114 ( V_215 ) ;
}
#ifdef F_26
if ( V_199 ) {
* V_222 ++ = F_114 ( ( V_229 << 24 ) | ( V_229 << 16 ) |
( V_232 << 8 ) | V_233 ) ;
F_96 ( ( T_7 * ) V_222 , V_199 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_217 ) ;
}
#endif
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_24 = F_14 ( V_7 ) -> V_26 ;
V_45 . V_26 = F_14 ( V_7 ) -> V_24 ;
V_218 -> V_234 = V_235 ;
V_218 -> V_236 = 0 ;
F_76 ( V_218 , & V_45 . V_26 , & V_45 . V_24 ) ;
V_45 . V_92 = V_93 ;
if ( F_22 ( & V_45 . V_24 ) & V_63 )
V_45 . V_94 = F_64 ( V_7 ) ;
V_45 . V_97 = V_217 -> V_27 ;
V_45 . V_98 = V_217 -> V_28 ;
F_116 ( V_7 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_219 , & V_45 , NULL , false ) ;
if ( ! F_33 ( V_9 ) ) {
F_117 ( V_218 , V_9 ) ;
F_78 ( V_219 , V_218 , & V_45 , NULL , V_169 ) ;
F_81 ( V_130 , V_237 ) ;
if ( V_216 )
F_81 ( V_130 , V_238 ) ;
return;
}
F_83 ( V_218 ) ;
}
static void F_118 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_111 * V_128 = F_15 ( V_7 ) ;
T_2 V_129 = 0 , V_227 = 0 ;
struct V_1 * V_199 = NULL ;
#ifdef F_26
const T_7 * V_206 = NULL ;
struct V_112 * V_239 = F_14 ( V_7 ) ;
unsigned char V_209 [ 16 ] ;
int V_208 ;
struct V_2 * V_240 = NULL ;
#endif
if ( V_128 -> V_216 )
return;
if ( ! F_119 ( V_7 ) )
return;
#ifdef F_26
V_206 = F_106 ( V_128 ) ;
if ( ! V_3 && V_206 ) {
V_240 = F_120 ( F_48 ( F_3 ( V_7 ) -> V_131 ) ,
& V_132 , & V_239 -> V_26 ,
V_128 -> V_28 , & V_239 -> V_24 ,
F_108 ( V_128 -> V_28 ) , F_64 ( V_7 ) ) ;
if ( ! V_240 )
return;
F_121 () ;
V_199 = F_1 ( V_240 , & V_239 -> V_26 ) ;
if ( ! V_199 )
goto V_241;
V_208 = F_103 ( V_209 , V_199 , NULL , NULL , V_7 ) ;
if ( V_208 || memcmp ( V_206 , V_209 , 16 ) != 0 )
goto V_241;
} else {
V_199 = V_3 ? F_1 ( V_3 , & V_239 -> V_26 ) : NULL ;
}
#endif
if ( V_128 -> V_212 )
V_129 = F_57 ( V_128 -> V_227 ) ;
else
V_227 = F_57 ( V_128 -> V_129 ) + V_128 -> V_242 + V_128 -> V_243 + V_7 -> V_196 -
( V_128 -> V_204 << 2 ) ;
F_109 ( V_7 , V_129 , V_227 , 0 , 0 , 0 , V_199 , 1 , 0 ) ;
#ifdef F_26
V_241:
if ( V_240 ) {
F_122 () ;
F_71 ( V_240 ) ;
}
#endif
}
static void F_123 ( struct V_6 * V_7 , T_2 V_129 , T_2 V_212 ,
T_2 V_213 , T_2 V_214 , T_2 V_215 ,
struct V_1 * V_199 , T_3 V_169 )
{
F_109 ( V_7 , V_129 , V_212 , V_213 , V_214 , V_215 , V_199 , 0 , V_169 ) ;
}
static void F_124 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_244 * V_245 = F_53 ( V_3 ) ;
struct V_246 * V_247 = F_125 ( V_3 ) ;
F_123 ( V_7 , V_247 -> V_248 , V_247 -> V_249 ,
V_247 -> V_250 >> V_245 -> V_251 ,
V_252 + V_247 -> V_253 ,
V_247 -> V_254 , F_126 ( V_247 ) ,
V_245 -> V_255 ) ;
F_52 ( V_245 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_152 * V_153 )
{
F_123 ( V_7 , F_66 ( V_153 ) -> V_155 + 1 , F_66 ( V_153 ) -> V_256 + 1 ,
V_153 -> V_257 , V_252 , V_153 -> V_68 ,
F_1 ( V_3 , & F_14 ( V_7 ) -> V_24 ) , 0 ) ;
}
static struct V_2 * F_128 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_152 * V_153 , * * V_154 ;
const struct V_111 * V_128 = F_15 ( V_7 ) ;
struct V_2 * V_258 ;
V_153 = F_63 ( V_3 , & V_154 , V_128 -> V_28 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , F_64 ( V_7 ) ) ;
if ( V_153 )
return F_129 ( V_3 , V_7 , V_153 , V_154 , false ) ;
V_258 = F_130 ( F_68 ( V_3 ) , & V_132 ,
& F_14 ( V_7 ) -> V_26 , V_128 -> V_28 ,
& F_14 ( V_7 ) -> V_24 , F_108 ( V_128 -> V_27 ) , F_64 ( V_7 ) ) ;
if ( V_258 ) {
if ( V_258 -> V_18 != V_135 ) {
F_54 ( V_258 ) ;
return V_258 ;
}
F_52 ( F_53 ( V_258 ) ) ;
return NULL ;
}
#ifdef F_131
if ( ! V_128 -> V_242 )
V_3 = F_132 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_133 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_259 V_260 ;
struct V_152 * V_153 ;
struct V_163 * V_164 ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 = F_17 ( V_3 ) ;
T_1 V_261 = F_134 ( V_7 ) -> V_262 ;
struct V_8 * V_9 = NULL ;
struct V_44 V_45 ;
bool V_263 = false ;
if ( V_7 -> V_195 == F_115 ( V_264 ) )
return F_135 ( V_3 , V_7 ) ;
if ( ! F_119 ( V_7 ) )
goto V_265;
if ( ( V_266 == 2 ||
F_136 ( V_3 ) ) && ! V_261 ) {
V_263 = F_137 ( V_3 , V_7 , L_5 ) ;
if ( ! V_263 )
goto V_265;
}
if ( F_138 ( V_3 ) && F_139 ( V_3 ) > 1 ) {
F_56 ( F_68 ( V_3 ) , V_267 ) ;
goto V_265;
}
V_153 = F_140 ( & V_268 ) ;
if ( V_153 == NULL )
goto V_265;
#ifdef F_26
F_66 ( V_153 ) -> V_83 = & V_269 ;
#endif
F_141 ( & V_260 ) ;
V_260 . V_109 = V_110 - sizeof( struct V_111 ) - sizeof( struct V_112 ) ;
V_260 . V_270 = V_41 -> V_66 . V_270 ;
F_142 ( V_7 , & V_260 , 0 , NULL ) ;
if ( V_263 && ! V_260 . V_271 )
F_141 ( & V_260 ) ;
V_260 . V_272 = V_260 . V_271 ;
F_143 ( V_153 , & V_260 , V_7 ) ;
V_164 = F_73 ( V_153 ) ;
V_164 -> V_168 = F_14 ( V_7 ) -> V_26 ;
V_164 -> V_167 = F_14 ( V_7 ) -> V_24 ;
if ( ! V_263 || V_260 . V_272 )
F_144 ( V_153 , V_7 , F_68 ( V_3 ) ) ;
V_164 -> V_273 = V_3 -> V_65 ;
if ( ! V_3 -> V_65 &&
F_22 ( & V_164 -> V_168 ) & V_63 )
V_164 -> V_273 = F_64 ( V_7 ) ;
if ( ! V_261 ) {
if ( F_145 ( V_3 , V_7 ) ||
V_39 -> V_274 . V_275 . V_276 || V_39 -> V_274 . V_275 . V_277 ||
V_39 -> V_274 . V_275 . V_278 || V_39 -> V_274 . V_275 . V_279 ) {
F_146 ( & V_7 -> V_280 ) ;
V_164 -> V_172 = V_7 ;
}
if ( V_263 ) {
V_261 = F_147 ( V_3 , V_7 , & V_153 -> V_281 ) ;
V_153 -> V_282 = V_260 . V_272 ;
goto V_283;
}
if ( V_260 . V_271 &&
V_104 . V_105 &&
( V_9 = F_74 ( V_3 , & V_45 , V_153 ) ) != NULL ) {
if ( ! F_148 ( V_153 , V_9 , true ) ) {
F_56 ( F_68 ( V_3 ) , V_284 ) ;
goto V_285;
}
}
else if ( ! V_266 &&
( V_286 - F_149 ( V_3 ) <
( V_286 >> 2 ) ) &&
! F_148 ( V_153 , V_9 , false ) ) {
F_150 ( V_287 L_6 ,
& V_164 -> V_168 , F_108 ( F_15 ( V_7 ) -> V_28 ) ) ;
goto V_285;
}
V_261 = F_12 ( V_7 ) ;
}
V_283:
F_66 ( V_153 ) -> V_155 = V_261 ;
if ( F_151 ( V_3 , V_7 , V_153 ) )
goto V_285;
if ( F_72 ( V_3 , V_9 , & V_45 , V_153 ,
F_152 ( V_7 ) ) ||
V_263 )
goto V_288;
F_66 ( V_153 ) -> V_289 = V_252 ;
F_66 ( V_153 ) -> V_290 = NULL ;
F_153 ( V_3 , V_153 , V_291 ) ;
return 0 ;
V_285:
F_154 ( V_9 ) ;
V_288:
F_155 ( V_153 ) ;
V_265:
F_56 ( F_68 ( V_3 ) , V_156 ) ;
return 0 ;
}
static struct V_2 * F_156 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_152 * V_153 ,
struct V_8 * V_9 )
{
struct V_163 * V_164 ;
struct V_38 * V_292 , * V_39 = F_6 ( V_3 ) ;
struct V_293 * V_294 ;
struct V_34 * V_295 ;
struct V_40 * V_296 ;
struct V_2 * V_297 ;
#ifdef F_26
struct V_1 * V_199 ;
#endif
struct V_44 V_45 ;
if ( V_7 -> V_195 == F_115 ( V_264 ) ) {
V_297 = F_157 ( V_3 , V_7 , V_153 , V_9 ) ;
if ( V_297 == NULL )
return NULL ;
V_294 = (struct V_293 * ) V_297 ;
F_5 ( V_297 ) -> V_298 = & V_294 -> V_299 ;
V_295 = F_5 ( V_297 ) ;
V_292 = F_6 ( V_297 ) ;
V_296 = F_17 ( V_297 ) ;
memcpy ( V_292 , V_39 , sizeof( struct V_38 ) ) ;
F_28 ( V_295 -> V_300 , & V_292 -> V_24 ) ;
F_28 ( V_295 -> V_89 , & V_292 -> V_26 ) ;
V_292 -> V_91 = V_292 -> V_26 ;
F_8 ( V_297 ) -> V_20 = & V_21 ;
V_297 -> V_81 = V_82 ;
#ifdef F_26
V_296 -> V_83 = & V_84 ;
#endif
V_292 -> V_301 = NULL ;
V_292 -> V_302 = NULL ;
V_292 -> V_303 = NULL ;
V_292 -> V_100 = NULL ;
V_292 -> V_304 = F_64 ( V_7 ) ;
V_292 -> V_305 = F_14 ( V_7 ) -> V_139 ;
V_292 -> V_306 = F_158 ( F_14 ( V_7 ) ) ;
F_45 ( V_297 , F_8 ( V_297 ) -> V_121 ) ;
return V_297 ;
}
V_164 = F_73 ( V_153 ) ;
if ( F_138 ( V_3 ) )
goto V_307;
if ( ! V_9 ) {
V_9 = F_74 ( V_3 , & V_45 , V_153 ) ;
if ( ! V_9 )
goto V_138;
}
V_297 = F_159 ( V_3 , V_153 , V_7 ) ;
if ( V_297 == NULL )
goto V_308;
V_297 -> V_102 = V_103 ;
F_35 ( V_297 , V_9 , NULL , NULL ) ;
F_2 ( V_297 , V_7 ) ;
V_294 = (struct V_293 * ) V_297 ;
F_5 ( V_297 ) -> V_298 = & V_294 -> V_299 ;
V_296 = F_17 ( V_297 ) ;
V_295 = F_5 ( V_297 ) ;
V_292 = F_6 ( V_297 ) ;
memcpy ( V_292 , V_39 , sizeof( struct V_38 ) ) ;
V_292 -> V_24 = V_164 -> V_168 ;
V_292 -> V_26 = V_164 -> V_167 ;
V_292 -> V_91 = V_164 -> V_167 ;
V_297 -> V_65 = V_164 -> V_273 ;
V_295 -> V_309 = NULL ;
V_292 -> V_301 = NULL ;
V_292 -> V_302 = NULL ;
V_292 -> V_274 . V_310 = V_39 -> V_274 . V_310 ;
V_292 -> V_303 = NULL ;
if ( V_164 -> V_172 != NULL ) {
V_292 -> V_303 = F_160 ( V_164 -> V_172 ,
F_161 ( V_3 , V_226 ) ) ;
F_162 ( V_164 -> V_172 ) ;
V_164 -> V_172 = NULL ;
if ( V_292 -> V_303 )
F_163 ( V_292 -> V_303 , V_297 ) ;
}
V_292 -> V_100 = NULL ;
V_292 -> V_304 = F_64 ( V_7 ) ;
V_292 -> V_305 = F_14 ( V_7 ) -> V_139 ;
V_292 -> V_306 = F_158 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_100 )
V_292 -> V_100 = F_164 ( V_297 , V_39 -> V_100 ) ;
F_8 ( V_297 ) -> V_73 = 0 ;
if ( V_292 -> V_100 )
F_8 ( V_297 ) -> V_73 = ( V_292 -> V_100 -> V_108 +
V_292 -> V_100 -> V_107 ) ;
F_165 ( V_297 ) ;
F_45 ( V_297 , F_44 ( V_9 ) ) ;
V_296 -> V_311 = F_166 ( V_9 ) ;
if ( F_17 ( V_3 ) -> V_66 . V_270 &&
F_17 ( V_3 ) -> V_66 . V_270 < V_296 -> V_311 )
V_296 -> V_311 = F_17 ( V_3 ) -> V_66 . V_270 ;
F_167 ( V_297 ) ;
V_295 -> V_300 = V_295 -> V_89 = V_101 ;
V_295 -> V_90 = V_101 ;
#ifdef F_26
if ( ( V_199 = F_1 ( V_3 , & V_292 -> V_24 ) ) != NULL ) {
F_91 ( V_297 , (union V_173 * ) & V_292 -> V_24 ,
V_51 , V_199 -> V_199 , V_199 -> V_312 ,
F_161 ( V_3 , V_226 ) ) ;
}
#endif
if ( F_168 ( V_3 , V_297 ) < 0 ) {
F_169 ( V_297 ) ;
F_69 ( V_297 ) ;
goto V_138;
}
F_10 ( V_297 , NULL ) ;
return V_297 ;
V_307:
F_56 ( F_68 ( V_3 ) , V_267 ) ;
V_308:
F_154 ( V_9 ) ;
V_138:
F_56 ( F_68 ( V_3 ) , V_156 ) ;
return NULL ;
}
static T_8 F_170 ( struct V_6 * V_7 )
{
if ( V_7 -> V_234 == V_313 ) {
if ( ! F_171 ( V_7 -> V_196 , & F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_7 -> V_236 ) ) {
V_7 -> V_234 = V_314 ;
return 0 ;
}
}
V_7 -> V_236 = ~ F_172 ( F_171 ( V_7 -> V_196 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , 0 ) ) ;
if ( V_7 -> V_196 <= 76 ) {
return F_173 ( V_7 ) ;
}
return 0 ;
}
static int V_86 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_6 * V_315 = NULL ;
if ( V_7 -> V_195 == F_115 ( V_264 ) )
return V_82 ( V_3 , V_7 ) ;
#ifdef F_26
if ( F_105 ( V_3 , V_7 ) )
goto V_316;
#endif
if ( F_174 ( V_3 , V_7 ) )
goto V_316;
if ( V_39 -> V_274 . V_310 )
V_315 = F_160 ( V_7 , F_161 ( V_3 , V_226 ) ) ;
if ( V_3 -> V_18 == V_317 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_175 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_148 -> V_318 ( V_9 , V_39 -> V_16 ) == NULL ) {
F_154 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
F_176 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_196 ) ;
if ( V_315 )
goto V_319;
return 0 ;
}
if ( V_7 -> V_196 < F_177 ( V_7 ) || F_178 ( V_7 ) )
goto V_320;
if ( V_3 -> V_18 == V_142 ) {
struct V_2 * V_258 = F_128 ( V_3 , V_7 ) ;
if ( ! V_258 )
goto V_316;
if( V_258 != V_3 ) {
F_175 ( V_258 , V_7 ) ;
if ( F_179 ( V_3 , V_258 , V_7 ) )
goto V_321;
if ( V_315 )
F_180 ( V_315 ) ;
return 0 ;
}
} else
F_175 ( V_3 , V_7 ) ;
if ( F_181 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_196 ) )
goto V_321;
if ( V_315 )
goto V_319;
return 0 ;
V_321:
F_118 ( V_3 , V_7 ) ;
V_316:
if ( V_315 )
F_180 ( V_315 ) ;
F_83 ( V_7 ) ;
return 0 ;
V_320:
F_81 ( F_68 ( V_3 ) , V_322 ) ;
F_81 ( F_68 ( V_3 ) , V_323 ) ;
goto V_316;
V_319:
V_41 = F_17 ( V_3 ) ;
if ( F_134 ( V_315 ) -> V_324 == V_41 -> V_325 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_119 | V_118 ) ) ) {
if ( V_39 -> V_274 . V_275 . V_276 || V_39 -> V_274 . V_275 . V_277 )
V_39 -> V_304 = F_64 ( V_315 ) ;
if ( V_39 -> V_274 . V_275 . V_278 || V_39 -> V_274 . V_275 . V_279 )
V_39 -> V_305 = F_14 ( V_315 ) -> V_139 ;
if ( V_39 -> V_274 . V_275 . V_326 )
V_39 -> V_306 = F_158 ( F_14 ( V_315 ) ) ;
if ( F_145 ( V_3 , V_315 ) ) {
F_163 ( V_315 , V_3 ) ;
V_315 = F_182 ( & V_39 -> V_303 , V_315 ) ;
} else {
F_180 ( V_315 ) ;
V_315 = F_182 ( & V_39 -> V_303 , NULL ) ;
}
}
F_83 ( V_315 ) ;
return 0 ;
}
static int F_183 ( struct V_6 * V_7 )
{
const struct V_111 * V_128 ;
const struct V_112 * V_126 ;
struct V_2 * V_3 ;
int V_327 ;
struct V_130 * V_130 = F_48 ( V_7 -> V_131 ) ;
if ( V_7 -> V_328 != V_329 )
goto V_330;
F_81 ( V_130 , V_331 ) ;
if ( ! F_184 ( V_7 , sizeof( struct V_111 ) ) )
goto V_330;
V_128 = F_15 ( V_7 ) ;
if ( V_128 -> V_204 < sizeof( struct V_111 ) / 4 )
goto V_332;
if ( ! F_184 ( V_7 , V_128 -> V_204 * 4 ) )
goto V_330;
if ( ! F_185 ( V_7 ) && F_170 ( V_7 ) )
goto V_333;
V_128 = F_15 ( V_7 ) ;
V_126 = F_14 ( V_7 ) ;
F_134 ( V_7 ) -> V_129 = F_57 ( V_128 -> V_129 ) ;
F_134 ( V_7 ) -> V_324 = ( F_134 ( V_7 ) -> V_129 + V_128 -> V_242 + V_128 -> V_243 +
V_7 -> V_196 - V_128 -> V_204 * 4 ) ;
F_134 ( V_7 ) -> V_227 = F_57 ( V_128 -> V_227 ) ;
F_134 ( V_7 ) -> V_262 = 0 ;
F_134 ( V_7 ) -> V_334 = F_158 ( V_126 ) ;
F_134 ( V_7 ) -> V_335 = 0 ;
V_3 = F_186 ( & V_132 , V_7 , V_128 -> V_28 , V_128 -> V_27 ) ;
if ( ! V_3 )
goto V_336;
V_337:
if ( V_3 -> V_18 == V_135 )
goto V_338;
if ( V_126 -> V_139 < F_6 ( V_3 ) -> V_140 ) {
F_56 ( V_130 , V_141 ) ;
goto V_339;
}
if ( ! F_187 ( V_3 , V_340 , V_7 ) )
goto V_339;
if ( F_174 ( V_3 , V_7 ) )
goto V_339;
F_188 ( V_3 , V_7 ) ;
V_7 -> V_131 = NULL ;
F_189 ( V_3 ) ;
V_327 = 0 ;
if ( ! F_55 ( V_3 ) ) {
#ifdef F_190
struct V_40 * V_41 = F_17 ( V_3 ) ;
if ( ! V_41 -> V_341 . V_342 && V_41 -> V_341 . V_343 )
V_41 -> V_341 . V_342 = F_191 () ;
if ( V_41 -> V_341 . V_342 )
V_327 = V_86 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_192 ( V_3 , V_7 ) )
V_327 = V_86 ( V_3 , V_7 ) ;
}
} else if ( F_193 ( F_194 ( V_3 , V_7 ,
V_3 -> V_344 + V_3 -> V_345 ) ) ) {
F_70 ( V_3 ) ;
F_56 ( V_130 , V_346 ) ;
goto V_339;
}
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
return V_327 ? - 1 : 0 ;
V_336:
if ( ! F_187 ( NULL , V_340 , V_7 ) )
goto V_330;
if ( V_7 -> V_196 < ( V_128 -> V_204 << 2 ) || F_178 ( V_7 ) ) {
V_333:
F_81 ( V_130 , V_322 ) ;
V_332:
F_81 ( V_130 , V_323 ) ;
} else {
F_118 ( NULL , V_7 ) ;
}
V_330:
F_83 ( V_7 ) ;
return 0 ;
V_339:
F_71 ( V_3 ) ;
goto V_330;
V_338:
if ( ! F_187 ( NULL , V_340 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_330;
}
if ( V_7 -> V_196 < ( V_128 -> V_204 << 2 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_332;
}
if ( F_178 ( V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_333;
}
switch ( F_195 ( F_53 ( V_3 ) , V_7 , V_128 ) ) {
case V_347 :
{
struct V_2 * V_348 ;
V_348 = F_120 ( F_48 ( V_7 -> V_131 ) , & V_132 ,
& F_14 ( V_7 ) -> V_26 , V_128 -> V_28 ,
& F_14 ( V_7 ) -> V_24 ,
F_108 ( V_128 -> V_27 ) , F_64 ( V_7 ) ) ;
if ( V_348 != NULL ) {
struct V_244 * V_245 = F_53 ( V_3 ) ;
F_196 ( V_245 , & V_104 ) ;
F_52 ( V_245 ) ;
V_3 = V_348 ;
goto V_337;
}
}
case V_349 :
F_124 ( V_3 , V_7 ) ;
break;
case V_350 :
goto V_336;
case V_351 : ;
}
goto V_330;
}
static void F_197 ( struct V_6 * V_7 )
{
const struct V_112 * V_126 ;
const struct V_111 * V_128 ;
struct V_2 * V_3 ;
if ( V_7 -> V_328 != V_329 )
return;
if ( ! F_184 ( V_7 , F_198 ( V_7 ) + sizeof( struct V_111 ) ) )
return;
V_126 = F_14 ( V_7 ) ;
V_128 = F_15 ( V_7 ) ;
if ( V_128 -> V_204 < sizeof( struct V_111 ) / 4 )
return;
V_3 = F_130 ( F_48 ( V_7 -> V_131 ) , & V_132 ,
& V_126 -> V_26 , V_128 -> V_28 ,
& V_126 -> V_24 , F_108 ( V_128 -> V_27 ) ,
F_64 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_352 = V_353 ;
if ( V_3 -> V_18 != V_135 ) {
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
V_37 -> V_20 = & V_85 ;
#ifdef F_26
F_17 ( V_3 ) -> V_83 = & V_87 ;
#endif
return 0 ;
}
static void F_203 ( struct V_2 * V_3 )
{
F_204 ( V_3 ) ;
F_205 ( V_3 ) ;
}
static void F_206 ( struct V_354 * V_129 ,
const struct V_2 * V_3 , struct V_152 * V_153 , int V_355 , T_9 V_356 )
{
int V_357 = V_153 -> V_358 - V_359 ;
const struct V_4 * V_360 = & F_73 ( V_153 ) -> V_167 ;
const struct V_4 * V_27 = & F_73 ( V_153 ) -> V_168 ;
if ( V_357 < 0 )
V_357 = 0 ;
F_207 ( V_129 ,
L_7
L_8 ,
V_355 ,
V_360 -> V_25 [ 0 ] , V_360 -> V_25 [ 1 ] ,
V_360 -> V_25 [ 2 ] , V_360 -> V_25 [ 3 ] ,
F_108 ( F_208 ( V_153 ) -> V_361 ) ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] ,
F_108 ( F_208 ( V_153 ) -> V_362 ) ,
V_157 ,
0 , 0 ,
1 ,
F_209 ( V_357 ) ,
V_153 -> V_363 ,
F_210 ( F_211 ( V_129 ) , V_356 ) ,
0 ,
0 ,
0 , V_153 ) ;
}
static void F_212 ( struct V_354 * V_129 , struct V_2 * V_364 , int V_355 )
{
const struct V_4 * V_27 , * V_360 ;
T_10 V_365 , V_366 ;
int V_367 ;
unsigned long V_368 ;
const struct V_34 * V_35 = F_5 ( V_364 ) ;
const struct V_40 * V_41 = F_17 ( V_364 ) ;
const struct V_36 * V_37 = F_8 ( V_364 ) ;
const struct V_38 * V_39 = F_6 ( V_364 ) ;
V_27 = & V_39 -> V_24 ;
V_360 = & V_39 -> V_91 ;
V_365 = F_108 ( V_35 -> V_113 ) ;
V_366 = F_108 ( V_35 -> V_99 ) ;
if ( V_37 -> V_369 == V_370 ) {
V_367 = 1 ;
V_368 = V_37 -> V_371 ;
} else if ( V_37 -> V_369 == V_372 ) {
V_367 = 4 ;
V_368 = V_37 -> V_371 ;
} else if ( F_213 ( & V_364 -> V_373 ) ) {
V_367 = 2 ;
V_368 = V_364 -> V_373 . V_358 ;
} else {
V_367 = 0 ;
V_368 = V_359 ;
}
F_207 ( V_129 ,
L_7
L_9 ,
V_355 ,
V_360 -> V_25 [ 0 ] , V_360 -> V_25 [ 1 ] ,
V_360 -> V_25 [ 2 ] , V_360 -> V_25 [ 3 ] , V_366 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_365 ,
V_364 -> V_18 ,
V_41 -> V_69 - V_41 -> V_143 ,
( V_364 -> V_18 == V_142 ) ? V_364 -> V_374 : ( V_41 -> V_325 - V_41 -> V_375 ) ,
V_367 ,
F_214 ( V_368 - V_359 ) ,
V_37 -> V_376 ,
F_210 ( F_211 ( V_129 ) , F_215 ( V_364 ) ) ,
V_37 -> V_377 ,
F_216 ( V_364 ) ,
F_217 ( & V_364 -> V_378 ) , V_364 ,
F_209 ( V_37 -> V_379 ) ,
F_209 ( V_37 -> V_380 . V_381 ) ,
( V_37 -> V_380 . V_382 << 1 ) | V_37 -> V_380 . V_383 ,
V_41 -> V_384 ,
F_218 ( V_41 ) ? - 1 : V_41 -> V_385
) ;
}
static void F_219 ( struct V_354 * V_129 ,
struct V_244 * V_245 , int V_355 )
{
const struct V_4 * V_27 , * V_360 ;
T_10 V_365 , V_366 ;
const struct V_386 * V_387 = F_220 ( (struct V_2 * ) V_245 ) ;
long V_388 = V_245 -> V_389 - V_359 ;
V_27 = & V_387 -> V_390 ;
V_360 = & V_387 -> V_391 ;
V_365 = F_108 ( V_245 -> V_392 ) ;
V_366 = F_108 ( V_245 -> V_393 ) ;
F_207 ( V_129 ,
L_7
L_10 ,
V_355 ,
V_360 -> V_25 [ 0 ] , V_360 -> V_25 [ 1 ] ,
V_360 -> V_25 [ 2 ] , V_360 -> V_25 [ 3 ] , V_366 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_365 ,
V_245 -> V_394 , 0 , 0 ,
3 , F_214 ( V_388 ) , 0 , 0 , 0 , 0 ,
F_217 ( & V_245 -> V_395 ) , V_245 ) ;
}
static int F_221 ( struct V_354 * V_129 , void * V_396 )
{
struct V_397 * V_398 ;
if ( V_396 == V_399 ) {
F_222 ( V_129 ,
L_11
L_12
L_13
L_14
L_15 ) ;
goto V_138;
}
V_398 = V_129 -> V_400 ;
switch ( V_398 -> V_401 ) {
case V_402 :
case V_403 :
F_212 ( V_129 , V_396 , V_398 -> V_404 ) ;
break;
case V_405 :
F_206 ( V_129 , V_398 -> V_406 , V_396 , V_398 -> V_404 , V_398 -> V_356 ) ;
break;
case V_407 :
F_219 ( V_129 , V_396 , V_398 -> V_404 ) ;
break;
}
V_138:
return 0 ;
}
int T_11 F_223 ( struct V_130 * V_130 )
{
return F_224 ( V_130 , & V_408 ) ;
}
void F_225 ( struct V_130 * V_130 )
{
F_226 ( V_130 , & V_408 ) ;
}
static void F_227 ( struct V_2 * V_3 , int V_409 )
{
struct V_34 * V_35 = F_5 ( V_3 ) ;
F_228 ( V_3 , F_229 ( struct V_34 , V_298 ) ) ;
V_409 -= F_229 ( struct V_34 , V_298 ) + sizeof( V_35 -> V_298 ) ;
memset ( & V_35 -> V_298 + 1 , 0 , V_409 ) ;
}
static int T_11 F_230 ( struct V_130 * V_130 )
{
return F_231 ( & V_130 -> V_220 . F_17 , V_410 ,
V_411 , V_93 , V_130 ) ;
}
static void T_12 F_232 ( struct V_130 * V_130 )
{
F_233 ( V_130 -> V_220 . F_17 ) ;
}
static void T_12 F_234 ( struct V_412 * V_413 )
{
F_235 ( & V_132 , & V_104 , V_51 ) ;
}
int T_13 F_236 ( void )
{
int V_327 ;
V_327 = F_237 ( & V_414 , V_93 ) ;
if ( V_327 )
goto V_138;
V_327 = F_238 ( & V_415 ) ;
if ( V_327 )
goto V_416;
V_327 = F_239 ( & V_417 ) ;
if ( V_327 )
goto V_418;
V_138:
return V_327 ;
V_418:
F_240 ( & V_415 ) ;
V_416:
F_241 ( & V_414 , V_93 ) ;
goto V_138;
}
void F_242 ( void )
{
F_243 ( & V_417 ) ;
F_240 ( & V_415 ) ;
F_241 ( & V_414 , V_93 ) ;
}
