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
struct V_162 * V_163 ,
T_5 V_164 )
{
struct V_165 * V_166 = F_73 ( V_153 ) ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_6 * V_7 ;
int V_47 = - V_167 ;
if ( ! V_9 && ( V_9 = F_74 ( V_3 , V_45 , V_153 ) ) == NULL )
goto V_168;
V_7 = F_75 ( V_3 , V_9 , V_153 , V_163 , NULL ) ;
if ( V_7 ) {
F_76 ( V_7 , & V_166 -> V_169 , & V_166 -> V_170 ) ;
V_45 -> V_24 = V_166 -> V_170 ;
F_77 ( V_7 , V_164 ) ;
V_47 = F_78 ( V_3 , V_7 , V_45 , V_39 -> V_100 , V_39 -> V_171 ) ;
V_47 = F_79 ( V_47 ) ;
}
V_168:
return V_47 ;
}
static int F_80 ( struct V_2 * V_3 , struct V_152 * V_153 ,
struct V_162 * V_163 )
{
struct V_44 V_45 ;
int V_172 ;
V_172 = F_72 ( V_3 , NULL , & V_45 , V_153 , V_163 , 0 ) ;
if ( ! V_172 )
F_81 ( F_68 ( V_3 ) , V_173 ) ;
return V_172 ;
}
static void F_82 ( struct V_152 * V_153 )
{
F_83 ( F_73 ( V_153 ) -> V_174 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_84 ( V_3 , (union V_175 * ) V_5 , V_51 ) ;
}
static struct V_1 * F_85 ( struct V_2 * V_3 ,
struct V_2 * V_176 )
{
return F_1 ( V_3 , & F_6 ( V_176 ) -> V_24 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_152 * V_153 )
{
return F_1 ( V_3 , & F_73 ( V_153 ) -> V_170 ) ;
}
static int F_87 ( struct V_2 * V_3 , char T_6 * V_177 ,
int V_178 )
{
struct V_179 V_180 ;
struct V_32 * V_181 = (struct V_32 * ) & V_180 . V_182 ;
if ( V_178 < sizeof( V_180 ) )
return - V_49 ;
if ( F_88 ( & V_180 , V_177 , sizeof( V_180 ) ) )
return - V_183 ;
if ( V_181 -> V_50 != V_51 )
return - V_49 ;
if ( ! V_180 . V_184 ) {
if ( F_89 ( & V_181 -> V_59 ) )
return F_90 ( V_3 , (union V_175 * ) & V_181 -> V_59 . V_25 [ 3 ] ,
V_76 ) ;
return F_90 ( V_3 , (union V_175 * ) & V_181 -> V_59 ,
V_51 ) ;
}
if ( V_180 . V_184 > V_185 )
return - V_49 ;
if ( F_89 ( & V_181 -> V_59 ) )
return F_91 ( V_3 , (union V_175 * ) & V_181 -> V_59 . V_25 [ 3 ] ,
V_76 , V_180 . V_186 , V_180 . V_184 , V_187 ) ;
return F_91 ( V_3 , (union V_175 * ) & V_181 -> V_59 ,
V_51 , V_180 . V_186 , V_180 . V_184 , V_187 ) ;
}
static int F_92 ( struct V_188 * V_189 ,
const struct V_4 * V_24 ,
const struct V_4 * V_26 , int V_190 )
{
struct V_191 * V_192 ;
struct V_193 V_194 ;
V_192 = & V_189 -> V_195 . V_196 ;
V_192 -> V_26 = * V_26 ;
V_192 -> V_24 = * V_24 ;
V_192 -> V_197 = F_93 ( V_93 ) ;
V_192 -> V_198 = F_93 ( V_190 ) ;
F_94 ( & V_194 , V_192 , sizeof( * V_192 ) ) ;
return F_95 ( & V_189 -> V_199 , & V_194 , sizeof( * V_192 ) ) ;
}
static int F_96 ( char * V_200 , struct V_1 * V_201 ,
const struct V_4 * V_24 , struct V_4 * V_26 ,
const struct V_111 * V_128 )
{
struct V_188 * V_189 ;
struct V_202 * V_203 ;
V_189 = F_97 () ;
if ( ! V_189 )
goto V_204;
V_203 = & V_189 -> V_199 ;
if ( F_98 ( V_203 ) )
goto V_205;
if ( F_92 ( V_189 , V_24 , V_26 , V_128 -> V_206 << 2 ) )
goto V_205;
if ( F_99 ( V_189 , V_128 ) )
goto V_205;
if ( F_100 ( V_189 , V_201 ) )
goto V_205;
if ( F_101 ( V_203 , V_200 ) )
goto V_205;
F_102 () ;
return 0 ;
V_205:
F_102 () ;
V_204:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static int F_103 ( char * V_200 , struct V_1 * V_201 ,
const struct V_2 * V_3 ,
const struct V_152 * V_153 ,
const struct V_6 * V_7 )
{
const struct V_4 * V_26 , * V_24 ;
struct V_188 * V_189 ;
struct V_202 * V_203 ;
const struct V_111 * V_128 = F_15 ( V_7 ) ;
if ( V_3 ) {
V_26 = & F_6 ( V_3 ) -> V_26 ;
V_24 = & F_6 ( V_3 ) -> V_24 ;
} else if ( V_153 ) {
V_26 = & F_73 ( V_153 ) -> V_169 ;
V_24 = & F_73 ( V_153 ) -> V_170 ;
} else {
const struct V_112 * V_207 = F_14 ( V_7 ) ;
V_26 = & V_207 -> V_26 ;
V_24 = & V_207 -> V_24 ;
}
V_189 = F_97 () ;
if ( ! V_189 )
goto V_204;
V_203 = & V_189 -> V_199 ;
if ( F_98 ( V_203 ) )
goto V_205;
if ( F_92 ( V_189 , V_24 , V_26 , V_7 -> V_198 ) )
goto V_205;
if ( F_99 ( V_189 , V_128 ) )
goto V_205;
if ( F_104 ( V_189 , V_7 , V_128 -> V_206 << 2 ) )
goto V_205;
if ( F_100 ( V_189 , V_201 ) )
goto V_205;
if ( F_101 ( V_203 , V_200 ) )
goto V_205;
F_102 () ;
return 0 ;
V_205:
F_102 () ;
V_204:
memset ( V_200 , 0 , 16 ) ;
return 1 ;
}
static int F_105 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
const T_7 * V_208 = NULL ;
struct V_1 * V_209 ;
const struct V_112 * V_207 = F_14 ( V_7 ) ;
const struct V_111 * V_128 = F_15 ( V_7 ) ;
int V_210 ;
T_3 V_211 [ 16 ] ;
V_209 = F_1 ( V_3 , & V_207 -> V_26 ) ;
V_208 = F_106 ( V_128 ) ;
if ( ! V_209 && ! V_208 )
return 0 ;
if ( V_209 && ! V_208 ) {
F_56 ( F_68 ( V_3 ) , V_212 ) ;
return 1 ;
}
if ( ! V_209 && V_208 ) {
F_56 ( F_68 ( V_3 ) , V_213 ) ;
return 1 ;
}
V_210 = F_103 ( V_211 ,
V_209 ,
NULL , NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 ) {
F_107 ( L_2 ,
V_210 ? L_3 : L_4 ,
& V_207 -> V_26 , F_108 ( V_128 -> V_28 ) ,
& V_207 -> V_24 , F_108 ( V_128 -> V_27 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_109 ( struct V_6 * V_7 , T_2 V_129 , T_2 V_214 , T_2 V_215 ,
T_2 V_216 , T_2 V_217 ,
struct V_1 * V_201 , int V_218 , T_3 V_171 )
{
const struct V_111 * V_128 = F_15 ( V_7 ) ;
struct V_111 * V_219 ;
struct V_6 * V_220 ;
struct V_44 V_45 ;
struct V_130 * V_130 = F_48 ( F_3 ( V_7 ) -> V_131 ) ;
struct V_2 * V_221 = V_130 -> V_222 . F_17 ;
unsigned int V_223 = sizeof( struct V_111 ) ;
struct V_8 * V_9 ;
T_4 * V_224 ;
if ( V_217 )
V_223 += V_225 ;
#ifdef F_26
if ( V_201 )
V_223 += V_226 ;
#endif
V_220 = F_110 ( V_227 + sizeof( struct V_112 ) + V_223 ,
V_228 ) ;
if ( V_220 == NULL )
return;
F_111 ( V_220 , V_227 + sizeof( struct V_112 ) + V_223 ) ;
V_219 = (struct V_111 * ) F_112 ( V_220 , V_223 ) ;
F_113 ( V_220 ) ;
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
V_219 -> V_27 = V_128 -> V_28 ;
V_219 -> V_28 = V_128 -> V_27 ;
V_219 -> V_206 = V_223 / 4 ;
V_219 -> V_129 = F_114 ( V_129 ) ;
V_219 -> V_229 = F_114 ( V_214 ) ;
V_219 -> V_214 = ! V_218 || ! V_128 -> V_214 ;
V_219 -> V_218 = V_218 ;
V_219 -> V_230 = F_115 ( V_215 ) ;
V_224 = ( T_4 * ) ( V_219 + 1 ) ;
if ( V_217 ) {
* V_224 ++ = F_114 ( ( V_231 << 24 ) | ( V_231 << 16 ) |
( V_232 << 8 ) | V_233 ) ;
* V_224 ++ = F_114 ( V_216 ) ;
* V_224 ++ = F_114 ( V_217 ) ;
}
#ifdef F_26
if ( V_201 ) {
* V_224 ++ = F_114 ( ( V_231 << 24 ) | ( V_231 << 16 ) |
( V_234 << 8 ) | V_235 ) ;
F_96 ( ( T_7 * ) V_224 , V_201 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_219 ) ;
}
#endif
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_24 = F_14 ( V_7 ) -> V_26 ;
V_45 . V_26 = F_14 ( V_7 ) -> V_24 ;
V_220 -> V_236 = V_237 ;
V_220 -> V_238 = 0 ;
F_76 ( V_220 , & V_45 . V_26 , & V_45 . V_24 ) ;
V_45 . V_92 = V_93 ;
if ( F_22 ( & V_45 . V_24 ) & V_63 )
V_45 . V_94 = F_64 ( V_7 ) ;
V_45 . V_97 = V_219 -> V_27 ;
V_45 . V_98 = V_219 -> V_28 ;
F_116 ( V_7 , F_31 ( & V_45 ) ) ;
V_9 = F_32 ( V_221 , & V_45 , NULL , false ) ;
if ( ! F_33 ( V_9 ) ) {
F_117 ( V_220 , V_9 ) ;
F_78 ( V_221 , V_220 , & V_45 , NULL , V_171 ) ;
F_81 ( V_130 , V_239 ) ;
if ( V_218 )
F_81 ( V_130 , V_240 ) ;
return;
}
F_83 ( V_220 ) ;
}
static void F_118 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
const struct V_111 * V_128 = F_15 ( V_7 ) ;
T_2 V_129 = 0 , V_229 = 0 ;
struct V_1 * V_201 = NULL ;
#ifdef F_26
const T_7 * V_208 = NULL ;
struct V_112 * V_241 = F_14 ( V_7 ) ;
unsigned char V_211 [ 16 ] ;
int V_210 ;
struct V_2 * V_242 = NULL ;
#endif
if ( V_128 -> V_218 )
return;
if ( ! F_119 ( V_7 ) )
return;
#ifdef F_26
V_208 = F_106 ( V_128 ) ;
if ( ! V_3 && V_208 ) {
V_242 = F_120 ( F_48 ( F_3 ( V_7 ) -> V_131 ) ,
& V_132 , & V_241 -> V_26 ,
V_128 -> V_28 , & V_241 -> V_24 ,
F_108 ( V_128 -> V_28 ) , F_64 ( V_7 ) ) ;
if ( ! V_242 )
return;
F_121 () ;
V_201 = F_1 ( V_242 , & V_241 -> V_26 ) ;
if ( ! V_201 )
goto V_243;
V_210 = F_103 ( V_211 , V_201 , NULL , NULL , V_7 ) ;
if ( V_210 || memcmp ( V_208 , V_211 , 16 ) != 0 )
goto V_243;
} else {
V_201 = V_3 ? F_1 ( V_3 , & V_241 -> V_26 ) : NULL ;
}
#endif
if ( V_128 -> V_214 )
V_129 = F_57 ( V_128 -> V_229 ) ;
else
V_229 = F_57 ( V_128 -> V_129 ) + V_128 -> V_244 + V_128 -> V_245 + V_7 -> V_198 -
( V_128 -> V_206 << 2 ) ;
F_109 ( V_7 , V_129 , V_229 , 0 , 0 , 0 , V_201 , 1 , 0 ) ;
#ifdef F_26
V_243:
if ( V_242 ) {
F_122 () ;
F_71 ( V_242 ) ;
}
#endif
}
static void F_123 ( struct V_6 * V_7 , T_2 V_129 , T_2 V_214 ,
T_2 V_215 , T_2 V_216 , T_2 V_217 ,
struct V_1 * V_201 , T_3 V_171 )
{
F_109 ( V_7 , V_129 , V_214 , V_215 , V_216 , V_217 , V_201 , 0 , V_171 ) ;
}
static void F_124 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_246 * V_247 = F_53 ( V_3 ) ;
struct V_248 * V_249 = F_125 ( V_3 ) ;
F_123 ( V_7 , V_249 -> V_250 , V_249 -> V_251 ,
V_249 -> V_252 >> V_247 -> V_253 ,
V_254 + V_249 -> V_255 ,
V_249 -> V_256 , F_126 ( V_249 ) ,
V_247 -> V_257 ) ;
F_52 ( V_247 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_152 * V_153 )
{
F_123 ( V_7 , F_66 ( V_153 ) -> V_155 + 1 , F_66 ( V_153 ) -> V_258 + 1 ,
V_153 -> V_259 , V_254 , V_153 -> V_68 ,
F_1 ( V_3 , & F_14 ( V_7 ) -> V_24 ) , 0 ) ;
}
static struct V_2 * F_128 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_152 * V_153 , * * V_154 ;
const struct V_111 * V_128 = F_15 ( V_7 ) ;
struct V_2 * V_260 ;
V_153 = F_63 ( V_3 , & V_154 , V_128 -> V_28 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , F_64 ( V_7 ) ) ;
if ( V_153 )
return F_129 ( V_3 , V_7 , V_153 , V_154 , false ) ;
V_260 = F_130 ( F_68 ( V_3 ) , & V_132 ,
& F_14 ( V_7 ) -> V_26 , V_128 -> V_28 ,
& F_14 ( V_7 ) -> V_24 , F_108 ( V_128 -> V_27 ) , F_64 ( V_7 ) ) ;
if ( V_260 ) {
if ( V_260 -> V_18 != V_135 ) {
F_54 ( V_260 ) ;
return V_260 ;
}
F_52 ( F_53 ( V_260 ) ) ;
return NULL ;
}
#ifdef F_131
if ( ! V_128 -> V_244 )
V_3 = F_132 ( V_3 , V_7 ) ;
#endif
return V_3 ;
}
static int F_133 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_261 V_262 ;
struct V_263 V_264 ;
const T_3 * V_208 ;
struct V_152 * V_153 ;
struct V_165 * V_166 ;
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 = F_17 ( V_3 ) ;
T_1 V_265 = F_134 ( V_7 ) -> V_266 ;
struct V_8 * V_9 = NULL ;
struct V_44 V_45 ;
bool V_267 = false ;
if ( V_7 -> V_197 == F_115 ( V_268 ) )
return F_135 ( V_3 , V_7 ) ;
if ( ! F_119 ( V_7 ) )
goto V_269;
if ( F_136 ( V_3 ) && ! V_265 ) {
V_267 = F_137 ( V_3 , V_7 , L_5 ) ;
if ( ! V_267 )
goto V_269;
}
if ( F_138 ( V_3 ) && F_139 ( V_3 ) > 1 ) {
F_56 ( F_68 ( V_3 ) , V_270 ) ;
goto V_269;
}
V_153 = F_140 ( & V_271 ) ;
if ( V_153 == NULL )
goto V_269;
#ifdef F_26
F_66 ( V_153 ) -> V_83 = & V_272 ;
#endif
F_141 ( & V_264 ) ;
V_264 . V_109 = V_110 - sizeof( struct V_111 ) - sizeof( struct V_112 ) ;
V_264 . V_273 = V_41 -> V_66 . V_273 ;
F_142 ( V_7 , & V_264 , & V_208 , 0 , NULL ) ;
if ( V_264 . V_274 > 0 &&
V_264 . V_275 &&
! V_41 -> V_66 . V_276 &&
( V_277 > 0 ||
( V_41 -> V_278 != NULL &&
V_41 -> V_278 -> V_279 > 0 ) ) ) {
T_3 * V_280 ;
T_2 * V_281 ;
T_2 * V_282 = & V_262 . V_283 [ V_284 ] ;
int V_285 = V_264 . V_274 - V_286 ;
if ( F_143 ( & V_262 . V_283 [ 0 ] ) != 0 )
goto V_287;
V_281 = ( V_288 T_2 * ) & F_14 ( V_7 ) -> V_24 . V_25 [ 0 ] ;
* V_282 ++ ^= * V_281 ++ ;
* V_282 ++ ^= * V_281 ++ ;
* V_282 ++ ^= * V_281 ++ ;
* V_282 ++ ^= * V_281 ++ ;
V_281 = ( V_288 T_2 * ) & F_14 ( V_7 ) -> V_26 . V_25 [ 0 ] ;
* V_282 ++ ^= * V_281 ++ ;
* V_282 ++ ^= * V_281 ++ ;
* V_282 ++ ^= * V_281 ++ ;
* V_282 ++ ^= * V_281 ++ ;
V_280 = ( T_3 * ) V_282 ;
while ( V_285 -- > 0 )
* V_280 ++ ^= * V_208 ++ ;
V_267 = false ;
V_262 . V_276 = 0 ;
V_262 . V_274 = V_264 . V_274 ;
} else if ( ! V_41 -> V_66 . V_289 ) {
V_262 . V_276 = 1 ;
V_262 . V_274 = 0 ;
} else {
goto V_287;
}
V_262 . V_289 = V_41 -> V_66 . V_289 ;
if ( V_267 && ! V_264 . V_275 )
F_141 ( & V_264 ) ;
V_264 . V_290 = V_264 . V_275 ;
F_144 ( V_153 , & V_264 , V_7 ) ;
V_166 = F_73 ( V_153 ) ;
V_166 -> V_170 = F_14 ( V_7 ) -> V_26 ;
V_166 -> V_169 = F_14 ( V_7 ) -> V_24 ;
if ( ! V_267 || V_264 . V_290 )
F_145 ( V_153 , V_7 , F_68 ( V_3 ) ) ;
V_166 -> V_291 = V_3 -> V_65 ;
if ( ! V_3 -> V_65 &&
F_22 ( & V_166 -> V_170 ) & V_63 )
V_166 -> V_291 = F_64 ( V_7 ) ;
if ( ! V_265 ) {
if ( F_146 ( V_3 , V_7 ) ||
V_39 -> V_292 . V_293 . V_294 || V_39 -> V_292 . V_293 . V_295 ||
V_39 -> V_292 . V_293 . V_296 || V_39 -> V_292 . V_293 . V_297 ) {
F_147 ( & V_7 -> V_298 ) ;
V_166 -> V_174 = V_7 ;
}
if ( V_267 ) {
V_265 = F_148 ( V_3 , V_7 , & V_153 -> V_299 ) ;
V_153 -> V_300 = V_264 . V_290 ;
goto V_301;
}
if ( V_264 . V_275 &&
V_104 . V_105 &&
( V_9 = F_74 ( V_3 , & V_45 , V_153 ) ) != NULL ) {
if ( ! F_149 ( V_153 , V_9 , true ) ) {
F_56 ( F_68 ( V_3 ) , V_302 ) ;
goto V_303;
}
}
else if ( ! V_304 &&
( V_305 - F_150 ( V_3 ) <
( V_305 >> 2 ) ) &&
! F_149 ( V_153 , V_9 , false ) ) {
F_151 ( V_306 L_6 ,
& V_166 -> V_170 , F_108 ( F_15 ( V_7 ) -> V_28 ) ) ;
goto V_303;
}
V_265 = F_12 ( V_7 ) ;
}
V_301:
F_66 ( V_153 ) -> V_155 = V_265 ;
if ( F_152 ( V_3 , V_7 , V_153 ) )
goto V_303;
if ( F_72 ( V_3 , V_9 , & V_45 , V_153 ,
(struct V_162 * ) & V_262 ,
F_153 ( V_7 ) ) ||
V_267 )
goto V_287;
F_66 ( V_153 ) -> V_307 = V_254 ;
F_66 ( V_153 ) -> V_308 = NULL ;
F_154 ( V_3 , V_153 , V_309 ) ;
return 0 ;
V_303:
F_155 ( V_9 ) ;
V_287:
F_156 ( V_153 ) ;
V_269:
F_56 ( F_68 ( V_3 ) , V_156 ) ;
return 0 ;
}
static struct V_2 * F_157 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_152 * V_153 ,
struct V_8 * V_9 )
{
struct V_165 * V_166 ;
struct V_38 * V_310 , * V_39 = F_6 ( V_3 ) ;
struct V_311 * V_312 ;
struct V_34 * V_313 ;
struct V_40 * V_314 ;
struct V_2 * V_315 ;
#ifdef F_26
struct V_1 * V_201 ;
#endif
struct V_44 V_45 ;
if ( V_7 -> V_197 == F_115 ( V_268 ) ) {
V_315 = F_158 ( V_3 , V_7 , V_153 , V_9 ) ;
if ( V_315 == NULL )
return NULL ;
V_312 = (struct V_311 * ) V_315 ;
F_5 ( V_315 ) -> V_316 = & V_312 -> V_317 ;
V_313 = F_5 ( V_315 ) ;
V_310 = F_6 ( V_315 ) ;
V_314 = F_17 ( V_315 ) ;
memcpy ( V_310 , V_39 , sizeof( struct V_38 ) ) ;
F_28 ( V_313 -> V_318 , & V_310 -> V_24 ) ;
F_28 ( V_313 -> V_89 , & V_310 -> V_26 ) ;
V_310 -> V_91 = V_310 -> V_26 ;
F_8 ( V_315 ) -> V_20 = & V_21 ;
V_315 -> V_81 = V_82 ;
#ifdef F_26
V_314 -> V_83 = & V_84 ;
#endif
V_310 -> V_319 = NULL ;
V_310 -> V_320 = NULL ;
V_310 -> V_321 = NULL ;
V_310 -> V_100 = NULL ;
V_310 -> V_322 = F_64 ( V_7 ) ;
V_310 -> V_323 = F_14 ( V_7 ) -> V_139 ;
V_310 -> V_324 = F_159 ( F_14 ( V_7 ) ) ;
F_45 ( V_315 , F_8 ( V_315 ) -> V_121 ) ;
return V_315 ;
}
V_166 = F_73 ( V_153 ) ;
if ( F_138 ( V_3 ) )
goto V_325;
if ( ! V_9 ) {
V_9 = F_74 ( V_3 , & V_45 , V_153 ) ;
if ( ! V_9 )
goto V_138;
}
V_315 = F_160 ( V_3 , V_153 , V_7 ) ;
if ( V_315 == NULL )
goto V_326;
V_315 -> V_102 = V_103 ;
F_35 ( V_315 , V_9 , NULL , NULL ) ;
F_2 ( V_315 , V_7 ) ;
V_312 = (struct V_311 * ) V_315 ;
F_5 ( V_315 ) -> V_316 = & V_312 -> V_317 ;
V_314 = F_17 ( V_315 ) ;
V_313 = F_5 ( V_315 ) ;
V_310 = F_6 ( V_315 ) ;
memcpy ( V_310 , V_39 , sizeof( struct V_38 ) ) ;
V_310 -> V_24 = V_166 -> V_170 ;
V_310 -> V_26 = V_166 -> V_169 ;
V_310 -> V_91 = V_166 -> V_169 ;
V_315 -> V_65 = V_166 -> V_291 ;
V_313 -> V_327 = NULL ;
V_310 -> V_319 = NULL ;
V_310 -> V_320 = NULL ;
V_310 -> V_292 . V_328 = V_39 -> V_292 . V_328 ;
V_310 -> V_321 = NULL ;
if ( V_166 -> V_174 != NULL ) {
V_310 -> V_321 = F_161 ( V_166 -> V_174 ,
F_162 ( V_3 , V_228 ) ) ;
F_163 ( V_166 -> V_174 ) ;
V_166 -> V_174 = NULL ;
if ( V_310 -> V_321 )
F_164 ( V_310 -> V_321 , V_315 ) ;
}
V_310 -> V_100 = NULL ;
V_310 -> V_322 = F_64 ( V_7 ) ;
V_310 -> V_323 = F_14 ( V_7 ) -> V_139 ;
V_310 -> V_324 = F_159 ( F_14 ( V_7 ) ) ;
if ( V_39 -> V_100 )
V_310 -> V_100 = F_165 ( V_315 , V_39 -> V_100 ) ;
F_8 ( V_315 ) -> V_73 = 0 ;
if ( V_310 -> V_100 )
F_8 ( V_315 ) -> V_73 = ( V_310 -> V_100 -> V_108 +
V_310 -> V_100 -> V_107 ) ;
F_166 ( V_315 ) ;
F_45 ( V_315 , F_44 ( V_9 ) ) ;
V_314 -> V_329 = F_167 ( V_9 ) ;
if ( F_17 ( V_3 ) -> V_66 . V_273 &&
F_17 ( V_3 ) -> V_66 . V_273 < V_314 -> V_329 )
V_314 -> V_329 = F_17 ( V_3 ) -> V_66 . V_273 ;
F_168 ( V_315 ) ;
F_169 ( V_315 , V_153 ) ;
V_314 -> V_330 = V_153 -> V_331 ;
V_313 -> V_318 = V_313 -> V_89 = V_101 ;
V_313 -> V_90 = V_101 ;
#ifdef F_26
if ( ( V_201 = F_1 ( V_3 , & V_310 -> V_24 ) ) != NULL ) {
F_91 ( V_315 , (union V_175 * ) & V_310 -> V_24 ,
V_51 , V_201 -> V_201 , V_201 -> V_332 ,
F_162 ( V_3 , V_228 ) ) ;
}
#endif
if ( F_170 ( V_3 , V_315 ) < 0 ) {
F_171 ( V_315 ) ;
F_69 ( V_315 ) ;
goto V_138;
}
F_10 ( V_315 , NULL ) ;
return V_315 ;
V_325:
F_56 ( F_68 ( V_3 ) , V_270 ) ;
V_326:
F_155 ( V_9 ) ;
V_138:
F_56 ( F_68 ( V_3 ) , V_156 ) ;
return NULL ;
}
static T_8 F_172 ( struct V_6 * V_7 )
{
if ( V_7 -> V_236 == V_333 ) {
if ( ! F_173 ( V_7 -> V_198 , & F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , V_7 -> V_238 ) ) {
V_7 -> V_236 = V_334 ;
return 0 ;
}
}
V_7 -> V_238 = ~ F_174 ( F_173 ( V_7 -> V_198 ,
& F_14 ( V_7 ) -> V_26 ,
& F_14 ( V_7 ) -> V_24 , 0 ) ) ;
if ( V_7 -> V_198 <= 76 ) {
return F_175 ( V_7 ) ;
}
return 0 ;
}
static int V_86 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_38 * V_39 = F_6 ( V_3 ) ;
struct V_40 * V_41 ;
struct V_6 * V_335 = NULL ;
if ( V_7 -> V_197 == F_115 ( V_268 ) )
return V_82 ( V_3 , V_7 ) ;
#ifdef F_26
if ( F_105 ( V_3 , V_7 ) )
goto V_336;
#endif
if ( F_176 ( V_3 , V_7 ) )
goto V_336;
if ( V_39 -> V_292 . V_328 )
V_335 = F_161 ( V_7 , F_162 ( V_3 , V_228 ) ) ;
if ( V_3 -> V_18 == V_337 ) {
struct V_8 * V_9 = V_3 -> V_12 ;
F_177 ( V_3 , V_7 ) ;
if ( V_9 ) {
if ( F_5 ( V_3 ) -> V_13 != V_7 -> V_14 ||
V_9 -> V_148 -> V_338 ( V_9 , V_39 -> V_16 ) == NULL ) {
F_155 ( V_9 ) ;
V_3 -> V_12 = NULL ;
}
}
if ( F_178 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_198 ) )
goto V_339;
if ( V_335 )
goto V_340;
return 0 ;
}
if ( V_7 -> V_198 < F_179 ( V_7 ) || F_180 ( V_7 ) )
goto V_341;
if ( V_3 -> V_18 == V_142 ) {
struct V_2 * V_260 = F_128 ( V_3 , V_7 ) ;
if ( ! V_260 )
goto V_336;
if( V_260 != V_3 ) {
F_177 ( V_260 , V_7 ) ;
if ( F_181 ( V_3 , V_260 , V_7 ) )
goto V_339;
if ( V_335 )
F_182 ( V_335 ) ;
return 0 ;
}
} else
F_177 ( V_3 , V_7 ) ;
if ( F_183 ( V_3 , V_7 , F_15 ( V_7 ) , V_7 -> V_198 ) )
goto V_339;
if ( V_335 )
goto V_340;
return 0 ;
V_339:
F_118 ( V_3 , V_7 ) ;
V_336:
if ( V_335 )
F_182 ( V_335 ) ;
F_83 ( V_7 ) ;
return 0 ;
V_341:
F_81 ( F_68 ( V_3 ) , V_342 ) ;
goto V_336;
V_340:
V_41 = F_17 ( V_3 ) ;
if ( F_134 ( V_335 ) -> V_343 == V_41 -> V_344 &&
! ( ( 1 << V_3 -> V_18 ) & ( V_119 | V_118 ) ) ) {
if ( V_39 -> V_292 . V_293 . V_294 || V_39 -> V_292 . V_293 . V_295 )
V_39 -> V_322 = F_64 ( V_335 ) ;
if ( V_39 -> V_292 . V_293 . V_296 || V_39 -> V_292 . V_293 . V_297 )
V_39 -> V_323 = F_14 ( V_335 ) -> V_139 ;
if ( V_39 -> V_292 . V_293 . V_345 )
V_39 -> V_324 = F_159 ( F_14 ( V_7 ) ) ;
if ( F_146 ( V_3 , V_335 ) ) {
F_164 ( V_335 , V_3 ) ;
V_335 = F_184 ( & V_39 -> V_321 , V_335 ) ;
} else {
F_182 ( V_335 ) ;
V_335 = F_184 ( & V_39 -> V_321 , NULL ) ;
}
}
F_83 ( V_335 ) ;
return 0 ;
}
static int F_185 ( struct V_6 * V_7 )
{
const struct V_111 * V_128 ;
const struct V_112 * V_126 ;
struct V_2 * V_3 ;
int V_346 ;
struct V_130 * V_130 = F_48 ( V_7 -> V_131 ) ;
if ( V_7 -> V_347 != V_348 )
goto V_349;
F_81 ( V_130 , V_350 ) ;
if ( ! F_186 ( V_7 , sizeof( struct V_111 ) ) )
goto V_349;
V_128 = F_15 ( V_7 ) ;
if ( V_128 -> V_206 < sizeof( struct V_111 ) / 4 )
goto V_351;
if ( ! F_186 ( V_7 , V_128 -> V_206 * 4 ) )
goto V_349;
if ( ! F_187 ( V_7 ) && F_172 ( V_7 ) )
goto V_351;
V_128 = F_15 ( V_7 ) ;
V_126 = F_14 ( V_7 ) ;
F_134 ( V_7 ) -> V_129 = F_57 ( V_128 -> V_129 ) ;
F_134 ( V_7 ) -> V_343 = ( F_134 ( V_7 ) -> V_129 + V_128 -> V_244 + V_128 -> V_245 +
V_7 -> V_198 - V_128 -> V_206 * 4 ) ;
F_134 ( V_7 ) -> V_229 = F_57 ( V_128 -> V_229 ) ;
F_134 ( V_7 ) -> V_266 = 0 ;
F_134 ( V_7 ) -> V_352 = F_159 ( V_126 ) ;
F_134 ( V_7 ) -> V_353 = 0 ;
V_3 = F_188 ( & V_132 , V_7 , V_128 -> V_28 , V_128 -> V_27 ) ;
if ( ! V_3 )
goto V_354;
V_355:
if ( V_3 -> V_18 == V_135 )
goto V_356;
if ( V_126 -> V_139 < F_6 ( V_3 ) -> V_140 ) {
F_56 ( V_130 , V_141 ) ;
goto V_357;
}
if ( ! F_189 ( V_3 , V_358 , V_7 ) )
goto V_357;
if ( F_176 ( V_3 , V_7 ) )
goto V_357;
V_7 -> V_131 = NULL ;
F_190 ( V_3 ) ;
V_346 = 0 ;
if ( ! F_55 ( V_3 ) ) {
#ifdef F_191
struct V_40 * V_41 = F_17 ( V_3 ) ;
if ( ! V_41 -> V_359 . V_360 && V_41 -> V_359 . V_361 )
V_41 -> V_359 . V_360 = F_192 () ;
if ( V_41 -> V_359 . V_360 )
V_346 = V_86 ( V_3 , V_7 ) ;
else
#endif
{
if ( ! F_193 ( V_3 , V_7 ) )
V_346 = V_86 ( V_3 , V_7 ) ;
}
} else if ( F_194 ( F_195 ( V_3 , V_7 ,
V_3 -> V_362 + V_3 -> V_363 ) ) ) {
F_70 ( V_3 ) ;
F_56 ( V_130 , V_364 ) ;
goto V_357;
}
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
return V_346 ? - 1 : 0 ;
V_354:
if ( ! F_189 ( NULL , V_358 , V_7 ) )
goto V_349;
if ( V_7 -> V_198 < ( V_128 -> V_206 << 2 ) || F_180 ( V_7 ) ) {
V_351:
F_81 ( V_130 , V_342 ) ;
} else {
F_118 ( NULL , V_7 ) ;
}
V_349:
F_83 ( V_7 ) ;
return 0 ;
V_357:
F_71 ( V_3 ) ;
goto V_349;
V_356:
if ( ! F_189 ( NULL , V_358 , V_7 ) ) {
F_52 ( F_53 ( V_3 ) ) ;
goto V_349;
}
if ( V_7 -> V_198 < ( V_128 -> V_206 << 2 ) || F_180 ( V_7 ) ) {
F_81 ( V_130 , V_342 ) ;
F_52 ( F_53 ( V_3 ) ) ;
goto V_349;
}
switch ( F_196 ( F_53 ( V_3 ) , V_7 , V_128 ) ) {
case V_365 :
{
struct V_2 * V_366 ;
V_366 = F_120 ( F_48 ( V_7 -> V_131 ) , & V_132 ,
& F_14 ( V_7 ) -> V_26 , V_128 -> V_28 ,
& F_14 ( V_7 ) -> V_24 ,
F_108 ( V_128 -> V_27 ) , F_64 ( V_7 ) ) ;
if ( V_366 != NULL ) {
struct V_246 * V_247 = F_53 ( V_3 ) ;
F_197 ( V_247 , & V_104 ) ;
F_52 ( V_247 ) ;
V_3 = V_366 ;
goto V_355;
}
}
case V_367 :
F_124 ( V_3 , V_7 ) ;
break;
case V_368 :
goto V_354;
case V_369 : ;
}
goto V_349;
}
static void F_198 ( struct V_6 * V_7 )
{
const struct V_112 * V_126 ;
const struct V_111 * V_128 ;
struct V_2 * V_3 ;
if ( V_7 -> V_347 != V_348 )
return;
if ( ! F_186 ( V_7 , F_199 ( V_7 ) + sizeof( struct V_111 ) ) )
return;
V_126 = F_14 ( V_7 ) ;
V_128 = F_15 ( V_7 ) ;
if ( V_128 -> V_206 < sizeof( struct V_111 ) / 4 )
return;
V_3 = F_130 ( F_48 ( V_7 -> V_131 ) , & V_132 ,
& V_126 -> V_26 , V_128 -> V_28 ,
& V_126 -> V_24 , F_108 ( V_128 -> V_27 ) ,
F_64 ( V_7 ) ) ;
if ( V_3 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_370 = V_371 ;
if ( V_3 -> V_18 != V_135 ) {
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
V_37 -> V_20 = & V_85 ;
#ifdef F_26
F_17 ( V_3 ) -> V_83 = & V_87 ;
#endif
return 0 ;
}
static void F_204 ( struct V_2 * V_3 )
{
F_205 ( V_3 ) ;
F_206 ( V_3 ) ;
}
static void F_207 ( struct V_372 * V_129 ,
const struct V_2 * V_3 , struct V_152 * V_153 , int V_373 , T_9 V_374 )
{
int V_375 = V_153 -> V_376 - V_377 ;
const struct V_4 * V_378 = & F_73 ( V_153 ) -> V_169 ;
const struct V_4 * V_27 = & F_73 ( V_153 ) -> V_170 ;
if ( V_375 < 0 )
V_375 = 0 ;
F_208 ( V_129 ,
L_7
L_8 ,
V_373 ,
V_378 -> V_25 [ 0 ] , V_378 -> V_25 [ 1 ] ,
V_378 -> V_25 [ 2 ] , V_378 -> V_25 [ 3 ] ,
F_108 ( F_209 ( V_153 ) -> V_379 ) ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] ,
F_108 ( F_209 ( V_153 ) -> V_380 ) ,
V_157 ,
0 , 0 ,
1 ,
F_210 ( V_375 ) ,
V_153 -> V_381 ,
F_211 ( F_212 ( V_129 ) , V_374 ) ,
0 ,
0 ,
0 , V_153 ) ;
}
static void F_213 ( struct V_372 * V_129 , struct V_2 * V_382 , int V_373 )
{
const struct V_4 * V_27 , * V_378 ;
T_10 V_383 , V_384 ;
int V_385 ;
unsigned long V_386 ;
const struct V_34 * V_35 = F_5 ( V_382 ) ;
const struct V_40 * V_41 = F_17 ( V_382 ) ;
const struct V_36 * V_37 = F_8 ( V_382 ) ;
const struct V_38 * V_39 = F_6 ( V_382 ) ;
V_27 = & V_39 -> V_24 ;
V_378 = & V_39 -> V_91 ;
V_383 = F_108 ( V_35 -> V_113 ) ;
V_384 = F_108 ( V_35 -> V_99 ) ;
if ( V_37 -> V_387 == V_388 ) {
V_385 = 1 ;
V_386 = V_37 -> V_389 ;
} else if ( V_37 -> V_387 == V_390 ) {
V_385 = 4 ;
V_386 = V_37 -> V_389 ;
} else if ( F_214 ( & V_382 -> V_391 ) ) {
V_385 = 2 ;
V_386 = V_382 -> V_391 . V_376 ;
} else {
V_385 = 0 ;
V_386 = V_377 ;
}
F_208 ( V_129 ,
L_7
L_9 ,
V_373 ,
V_378 -> V_25 [ 0 ] , V_378 -> V_25 [ 1 ] ,
V_378 -> V_25 [ 2 ] , V_378 -> V_25 [ 3 ] , V_384 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_383 ,
V_382 -> V_18 ,
V_41 -> V_69 - V_41 -> V_143 ,
( V_382 -> V_18 == V_142 ) ? V_382 -> V_392 : ( V_41 -> V_344 - V_41 -> V_393 ) ,
V_385 ,
F_215 ( V_386 - V_377 ) ,
V_37 -> V_394 ,
F_211 ( F_212 ( V_129 ) , F_216 ( V_382 ) ) ,
V_37 -> V_395 ,
F_217 ( V_382 ) ,
F_218 ( & V_382 -> V_396 ) , V_382 ,
F_210 ( V_37 -> V_397 ) ,
F_210 ( V_37 -> V_398 . V_399 ) ,
( V_37 -> V_398 . V_400 << 1 ) | V_37 -> V_398 . V_401 ,
V_41 -> V_402 ,
F_219 ( V_41 ) ? - 1 : V_41 -> V_403
) ;
}
static void F_220 ( struct V_372 * V_129 ,
struct V_246 * V_247 , int V_373 )
{
const struct V_4 * V_27 , * V_378 ;
T_10 V_383 , V_384 ;
const struct V_404 * V_405 = F_221 ( (struct V_2 * ) V_247 ) ;
long V_406 = V_247 -> V_407 - V_377 ;
V_27 = & V_405 -> V_408 ;
V_378 = & V_405 -> V_409 ;
V_383 = F_108 ( V_247 -> V_410 ) ;
V_384 = F_108 ( V_247 -> V_411 ) ;
F_208 ( V_129 ,
L_7
L_8 ,
V_373 ,
V_378 -> V_25 [ 0 ] , V_378 -> V_25 [ 1 ] ,
V_378 -> V_25 [ 2 ] , V_378 -> V_25 [ 3 ] , V_384 ,
V_27 -> V_25 [ 0 ] , V_27 -> V_25 [ 1 ] ,
V_27 -> V_25 [ 2 ] , V_27 -> V_25 [ 3 ] , V_383 ,
V_247 -> V_412 , 0 , 0 ,
3 , F_215 ( V_406 ) , 0 , 0 , 0 , 0 ,
F_218 ( & V_247 -> V_413 ) , V_247 ) ;
}
static int F_222 ( struct V_372 * V_129 , void * V_414 )
{
struct V_415 * V_416 ;
if ( V_414 == V_417 ) {
F_223 ( V_129 ,
L_10
L_11
L_12
L_13
L_14 ) ;
goto V_138;
}
V_416 = V_129 -> V_418 ;
switch ( V_416 -> V_419 ) {
case V_420 :
case V_421 :
F_213 ( V_129 , V_414 , V_416 -> V_422 ) ;
break;
case V_423 :
F_207 ( V_129 , V_416 -> V_424 , V_414 , V_416 -> V_422 , V_416 -> V_374 ) ;
break;
case V_425 :
F_220 ( V_129 , V_414 , V_416 -> V_422 ) ;
break;
}
V_138:
return 0 ;
}
int T_11 F_224 ( struct V_130 * V_130 )
{
return F_225 ( V_130 , & V_426 ) ;
}
void F_226 ( struct V_130 * V_130 )
{
F_227 ( V_130 , & V_426 ) ;
}
static int T_11 F_228 ( struct V_130 * V_130 )
{
return F_229 ( & V_130 -> V_222 . F_17 , V_427 ,
V_428 , V_93 , V_130 ) ;
}
static void T_12 F_230 ( struct V_130 * V_130 )
{
F_231 ( V_130 -> V_222 . F_17 ) ;
}
static void T_12 F_232 ( struct V_429 * V_430 )
{
F_233 ( & V_132 , & V_104 , V_51 ) ;
}
int T_13 F_234 ( void )
{
int V_346 ;
V_346 = F_235 ( & V_431 , V_93 ) ;
if ( V_346 )
goto V_138;
V_346 = F_236 ( & V_432 ) ;
if ( V_346 )
goto V_433;
V_346 = F_237 ( & V_434 ) ;
if ( V_346 )
goto V_435;
V_138:
return V_346 ;
V_435:
F_238 ( & V_432 ) ;
V_433:
F_239 ( & V_431 , V_93 ) ;
goto V_138;
}
void F_240 ( void )
{
F_241 ( & V_434 ) ;
F_238 ( & V_432 ) ;
F_239 ( & V_431 , V_93 ) ;
}
