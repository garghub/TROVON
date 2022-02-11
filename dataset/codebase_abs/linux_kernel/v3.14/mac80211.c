static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
memset ( V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_2 -> V_4 [ V_3 ] . V_6 = V_3 ;
V_2 -> V_4 [ V_3 ] . V_7 = 0 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 -> V_9 . V_10 & V_11 )
return V_2 -> V_8 -> V_9 . V_12 - 24 - 2 ;
return V_2 -> V_8 -> V_9 . V_12 - 24 - 34 ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_15 , V_16 , V_3 ;
V_14 -> V_10 = V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 ;
V_14 -> V_29 = V_2 -> V_30 ;
V_14 -> V_31 = V_32 ;
V_14 -> V_33 = L_1 ;
if ( V_2 -> V_8 -> V_9 . V_10 & V_34 &&
! V_35 . V_36 )
V_14 -> V_10 |= V_37 ;
if ( V_2 -> V_8 -> V_9 . V_10 & V_38 ) {
V_14 -> V_10 |= V_39 ;
V_14 -> V_40 = V_41 ;
V_14 -> V_42 = V_43 ;
}
V_14 -> V_44 = sizeof( struct V_45 ) ;
V_14 -> V_46 = sizeof( struct V_47 ) ;
V_14 -> V_48 = sizeof( V_49 ) ;
V_14 -> V_50 -> V_51 = F_4 ( V_52 ) |
F_4 ( V_53 ) |
F_4 ( V_54 ) |
F_4 ( V_55 ) |
F_4 ( V_56 ) ;
if ( F_5 ( V_2 -> V_8 -> V_57 ) >= 8 )
V_14 -> V_50 -> V_51 |= F_4 ( V_58 ) ;
V_14 -> V_50 -> V_10 |= V_59 ;
V_14 -> V_50 -> V_60 |= V_61 |
V_62 ;
V_14 -> V_50 -> V_63 = V_64 ;
V_14 -> V_50 -> V_65 =
F_6 ( V_64 ) ;
V_14 -> V_50 -> V_66 = 10000 ;
V_14 -> V_67 = V_68 ;
memcpy ( V_2 -> V_69 [ 0 ] . V_70 , V_2 -> V_71 -> V_72 , V_73 ) ;
V_14 -> V_50 -> V_69 = V_2 -> V_69 ;
V_14 -> V_50 -> V_74 = 1 ;
V_15 = ( V_2 -> V_71 -> V_75 > 1 ) ?
F_7 ( V_76 , V_2 -> V_71 -> V_75 ) : 1 ;
for ( V_3 = 1 ; V_3 < V_15 ; V_3 ++ ) {
memcpy ( V_2 -> V_69 [ V_3 ] . V_70 , V_2 -> V_69 [ V_3 - 1 ] . V_70 ,
V_73 ) ;
V_2 -> V_69 [ V_3 ] . V_70 [ 5 ] ++ ;
V_14 -> V_50 -> V_74 ++ ;
}
F_1 ( V_2 ) ;
V_14 -> V_50 -> V_77 = F_2 ( V_2 ) ;
V_14 -> V_50 -> V_78 = V_79 ;
if ( V_2 -> V_71 -> V_80 [ V_81 ] . V_82 )
V_14 -> V_50 -> V_80 [ V_81 ] =
& V_2 -> V_71 -> V_80 [ V_81 ] ;
if ( V_2 -> V_71 -> V_80 [ V_83 ] . V_82 )
V_14 -> V_50 -> V_80 [ V_83 ] =
& V_2 -> V_71 -> V_80 [ V_83 ] ;
V_14 -> V_50 -> V_84 = V_2 -> V_85 -> V_86 ;
if ( V_87 . V_88 != V_89 )
V_14 -> V_50 -> V_10 |= V_90 ;
else
V_14 -> V_50 -> V_10 &= ~ V_90 ;
if ( 0 && V_2 -> V_8 -> V_9 . V_10 & V_91 ) {
V_14 -> V_50 -> V_10 |= V_92 ;
V_14 -> V_50 -> V_93 = V_79 ;
V_14 -> V_50 -> V_94 = V_95 ;
V_14 -> V_50 -> V_96 =
V_97 - 24 - 2 ;
}
V_14 -> V_50 -> V_98 |= V_99 |
V_100 |
V_101 ;
V_2 -> V_102 = V_103 ;
if ( V_2 -> V_8 -> V_104 [ 0 ] . V_105 ) {
V_2 -> V_14 -> V_106 = 1 ;
V_2 -> V_14 -> V_107 = & V_2 -> V_8 -> V_104 [ 0 ] ;
}
#ifdef F_8
if ( V_2 -> V_8 -> V_108 [ V_109 ] . V_110 [ 0 ] . V_111 &&
V_2 -> V_85 -> V_112 -> V_113 &&
V_2 -> V_85 -> V_112 -> V_114 &&
F_9 ( V_2 -> V_85 -> V_115 ) ) {
V_2 -> V_116 . V_10 = V_117 |
V_118 |
V_119 |
V_120 ;
if ( ! V_35 . V_36 )
V_2 -> V_116 . V_10 |= V_121 |
V_122 |
V_123 ;
V_2 -> V_116 . V_124 = V_125 ;
V_2 -> V_116 . V_126 = V_127 ;
V_2 -> V_116 . V_128 = V_129 ;
V_2 -> V_116 . V_130 = & V_131 ;
V_14 -> V_50 -> V_116 = & V_2 -> V_116 ;
}
#endif
V_16 = F_10 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_11 ( V_2 -> V_14 ) ;
if ( V_16 )
F_12 ( V_2 ) ;
return V_16 ;
}
static void F_13 ( struct V_13 * V_14 ,
struct V_132 * V_133 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 , L_2 ) ;
goto V_136;
}
if ( F_17 ( V_135 ) -> V_137 == V_32 &&
! F_18 ( V_138 , & V_2 -> V_139 ) )
goto V_136;
if ( V_133 -> V_140 ) {
if ( F_19 ( V_2 , V_135 , V_133 -> V_140 ) )
goto V_136;
return;
}
if ( F_20 ( V_2 , V_135 ) )
goto V_136;
return;
V_136:
F_21 ( V_14 , V_135 ) ;
}
static inline bool F_22 ( const struct V_141 * V_142 )
{
if ( V_35 . V_143 & V_144 )
return false ;
return true ;
}
static inline bool F_23 ( const struct V_141 * V_142 )
{
if ( V_35 . V_143 & V_145 )
return false ;
if ( V_35 . V_143 & V_146 )
return true ;
return true ;
}
static int F_24 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
enum V_149 V_150 ,
struct V_151 * V_140 , V_49 V_152 ,
V_49 * V_153 , T_1 V_154 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_25 ( V_2 , L_3 ,
V_140 -> V_70 , V_152 , V_150 ) ;
if ( ! ( V_2 -> V_71 -> V_155 ) )
return - V_156 ;
F_26 ( & V_2 -> V_157 ) ;
switch ( V_150 ) {
case V_158 :
if ( ! F_22 ( V_2 -> V_142 ) ) {
V_16 = - V_159 ;
break;
}
V_16 = F_27 ( V_2 , V_140 , V_152 , * V_153 , true ) ;
break;
case V_160 :
V_16 = F_27 ( V_2 , V_140 , V_152 , 0 , false ) ;
break;
case V_161 :
if ( ! F_23 ( V_2 -> V_142 ) ) {
V_16 = - V_159 ;
break;
}
V_16 = F_28 ( V_2 , V_148 , V_140 , V_152 , V_153 ) ;
break;
case V_162 :
V_16 = F_29 ( V_2 , V_148 , V_140 , V_152 ) ;
break;
case V_163 :
case V_164 :
V_16 = F_30 ( V_2 , V_148 , V_140 , V_152 ) ;
break;
case V_165 :
V_16 = F_31 ( V_2 , V_148 , V_140 , V_152 , V_154 ) ;
break;
default:
F_32 ( 1 ) ;
V_16 = - V_159 ;
break;
}
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_34 ( void * V_166 , T_1 * V_167 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = V_166 ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
V_168 -> V_169 = false ;
V_168 -> V_170 = V_171 ;
V_168 -> V_172 ++ ;
F_36 ( & V_2 -> V_173 ) ;
F_37 ( V_2 , & V_168 -> V_174 ) ;
F_38 ( & V_2 -> V_173 ) ;
V_168 -> V_175 = NULL ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_85 ) ;
V_2 -> V_176 = V_177 ;
F_41 ( V_2 -> V_14 ) ;
F_42 (
V_2 -> V_14 , V_178 ,
F_34 , V_2 ) ;
V_2 -> V_179 = NULL ;
F_1 ( V_2 ) ;
memset ( V_2 -> V_180 , 0 , sizeof( V_2 -> V_180 ) ) ;
memset ( V_2 -> V_181 , 0 , sizeof( V_2 -> V_181 ) ) ;
F_43 ( V_2 -> V_14 ) ;
V_2 -> V_182 = 0 ;
V_2 -> V_183 = 0 ;
}
static int F_44 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_26 ( & V_2 -> V_157 ) ;
if ( F_18 ( V_184 , & V_2 -> V_139 ) )
F_39 ( V_2 ) ;
V_16 = F_45 ( V_2 ) ;
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_46 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_26 ( & V_2 -> V_157 ) ;
F_47 ( V_184 , & V_2 -> V_139 ) ;
V_16 = F_48 ( V_2 , NULL ) ;
if ( V_16 )
F_49 ( V_2 , L_4 ,
V_16 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static void F_50 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_51 ( & V_2 -> V_185 ) ;
F_26 ( & V_2 -> V_157 ) ;
F_52 ( & V_2 -> V_186 ) ;
F_40 ( V_2 -> V_85 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 , & V_2 -> V_187 ) ;
F_33 ( & V_2 -> V_157 ) ;
F_52 ( & V_2 -> V_185 ) ;
}
static void F_55 ( void * V_166 , T_1 * V_167 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = V_166 ;
F_56 ( V_2 , V_148 ) ;
}
static struct V_188 * F_57 ( struct V_1 * V_2 )
{
V_49 V_3 ;
F_58 ( & V_2 -> V_157 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
if ( ! V_2 -> V_4 [ V_3 ] . V_7 )
return & V_2 -> V_4 [ V_3 ] ;
F_49 ( V_2 , L_5 ) ;
return NULL ;
}
static int F_59 ( struct V_1 * V_2 , struct V_147 * V_148 ,
T_2 V_189 )
{
struct V_190 V_191 = {
. V_192 = F_35 ( V_148 ) -> V_6 ,
. V_193 = F_60 ( V_189 ) ,
} ;
return F_61 ( V_2 , V_194 , V_195 ,
sizeof( V_191 ) ,
& V_191 ) ;
}
static int F_62 ( struct V_13 * V_14 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
int V_16 ;
F_26 ( & V_2 -> V_157 ) ;
V_16 = F_63 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_196;
if ( V_148 -> type != V_56 )
V_2 -> V_182 ++ ;
if ( V_148 -> type == V_54 ||
V_148 -> type == V_58 ) {
T_3 V_197 = F_64 ( V_2 , V_148 ) ;
V_16 = F_65 ( V_2 , & V_168 -> V_198 ,
V_197 ) ;
if ( V_16 ) {
F_49 ( V_2 , L_6 ) ;
goto V_199;
}
F_66 ( V_2 , V_148 ) ;
goto V_196;
}
V_16 = F_67 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_199;
F_68 ( V_2 , V_148 ) ;
V_16 = F_69 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_200;
if ( ! V_2 -> V_201 &&
V_148 -> type == V_52 && ! V_148 -> V_202 &&
V_2 -> V_8 -> V_9 . V_10 & V_203 ) {
V_2 -> V_201 = V_168 ;
V_148 -> V_204 |= V_205 |
V_206 ;
}
if ( V_148 -> type == V_56 ) {
V_168 -> V_175 = F_57 ( V_2 ) ;
if ( ! V_168 -> V_175 ) {
V_16 = - V_207 ;
goto V_208;
}
F_70 ( V_2 , V_168 -> V_175 ) ;
V_16 = F_71 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_209;
V_16 = F_72 ( V_2 , V_148 , & V_168 -> V_198 ) ;
if ( V_16 )
goto V_210;
V_2 -> V_179 = V_148 ;
}
F_66 ( V_2 , V_148 ) ;
goto V_196;
V_210:
F_73 ( V_2 , V_148 ) ;
V_209:
F_74 ( V_2 , V_168 -> V_175 ) ;
V_208:
if ( V_2 -> V_201 == V_168 ) {
V_2 -> V_201 = NULL ;
V_148 -> V_204 &= ~ ( V_205 |
V_206 ) ;
}
V_200:
V_168 -> V_175 = NULL ;
F_75 ( V_2 , V_148 ) ;
V_199:
if ( V_148 -> type != V_56 )
V_2 -> V_182 -- ;
F_76 (
V_2 -> V_14 , V_211 ,
F_55 , V_2 ) ;
F_77 ( V_2 , V_148 ) ;
V_196:
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
T_3 V_212 = 0 , V_213 ;
for ( V_213 = 0 ; V_213 < V_214 ; V_213 ++ )
if ( V_148 -> V_137 [ V_213 ] != V_215 )
V_212 |= F_4 ( V_148 -> V_137 [ V_213 ] ) ;
if ( V_148 -> V_216 != V_215 )
V_212 |= F_4 ( V_148 -> V_216 ) ;
if ( V_212 ) {
F_26 ( & V_2 -> V_157 ) ;
F_79 ( V_2 , V_212 , true ) ;
F_33 ( & V_2 -> V_157 ) ;
}
if ( V_148 -> type == V_56 ) {
F_51 ( & V_2 -> V_186 ) ;
} else {
F_51 ( & V_2 -> V_217 ) ;
}
}
static void F_80 ( struct V_13 * V_14 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
F_78 ( V_2 , V_148 ) ;
F_26 ( & V_2 -> V_157 ) ;
if ( V_2 -> V_201 == V_168 ) {
V_2 -> V_201 = NULL ;
V_148 -> V_204 &= ~ ( V_205 |
V_206 ) ;
}
F_81 ( V_2 , V_148 ) ;
if ( V_148 -> type == V_54 ||
V_148 -> type == V_58 ) {
#ifdef F_82
if ( V_148 == V_2 -> V_218 ) {
V_2 -> V_218 = NULL ;
V_2 -> V_219 = 0 ;
}
#endif
F_54 ( V_2 , & V_168 -> V_198 ) ;
goto V_199;
}
if ( V_148 -> type == V_56 ) {
V_2 -> V_179 = NULL ;
F_83 ( V_2 , & V_168 -> V_198 ) ;
F_73 ( V_2 , V_148 ) ;
F_74 ( V_2 , V_168 -> V_175 ) ;
V_168 -> V_175 = NULL ;
}
if ( V_2 -> V_182 && V_148 -> type != V_56 )
V_2 -> V_182 -- ;
F_76 (
V_2 -> V_14 , V_211 ,
F_55 , V_2 ) ;
F_75 ( V_2 , V_148 ) ;
V_199:
F_77 ( V_2 , V_148 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static int F_84 ( struct V_13 * V_14 , T_3 V_220 )
{
return 0 ;
}
static void F_85 ( void * V_221 , T_1 * V_167 ,
struct V_147 * V_148 )
{
struct V_222 * V_166 = V_221 ;
struct V_1 * V_2 = V_166 -> V_2 ;
struct V_223 * V_224 = V_2 -> V_225 ;
int V_16 , V_111 ;
if ( F_32 ( V_166 -> V_226 >= V_227 ) )
return;
if ( V_148 -> type != V_52 ||
! V_148 -> V_228 . V_229 )
return;
V_224 -> V_226 = V_166 -> V_226 ++ ;
memcpy ( V_224 -> V_230 , V_148 -> V_228 . V_230 , V_73 ) ;
V_111 = F_86 ( sizeof( * V_224 ) + V_224 -> V_231 * V_73 , 4 ) ;
V_16 = F_61 ( V_2 , V_232 , V_195 , V_111 , V_224 ) ;
if ( V_16 )
F_49 ( V_2 , L_7 , V_16 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_222 V_233 = {
. V_2 = V_2 ,
} ;
F_58 ( & V_2 -> V_157 ) ;
if ( F_32 ( ! V_2 -> V_225 ) )
return;
F_76 (
V_2 -> V_14 , V_211 ,
F_85 , & V_233 ) ;
}
static T_4 F_88 ( struct V_13 * V_14 ,
struct V_234 * V_235 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_223 * V_224 ;
struct V_236 * V_70 ;
int V_237 = F_89 ( V_235 ) ;
bool V_238 = false ;
int V_111 ;
if ( V_237 > V_239 ) {
V_238 = true ;
V_237 = 0 ;
}
V_111 = F_86 ( sizeof( * V_224 ) + V_237 * V_73 , 4 ) ;
V_224 = F_90 ( V_111 , V_240 ) ;
if ( ! V_224 )
return 0 ;
if ( V_238 ) {
V_224 -> V_238 = 1 ;
return ( T_4 ) ( unsigned long ) V_224 ;
}
F_91 (addr, mc_list) {
F_92 ( V_2 , L_8 ,
V_224 -> V_231 , V_70 -> V_70 ) ;
memcpy ( & V_224 -> V_241 [ V_224 -> V_231 * V_73 ] ,
V_70 -> V_70 , V_73 ) ;
V_224 -> V_231 ++ ;
}
return ( T_4 ) ( unsigned long ) V_224 ;
}
static void F_93 ( struct V_13 * V_14 ,
unsigned int V_242 ,
unsigned int * V_243 ,
T_4 V_244 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_223 * V_224 = ( void * ) ( unsigned long ) V_244 ;
F_26 ( & V_2 -> V_157 ) ;
F_94 ( V_2 -> V_225 ) ;
V_2 -> V_225 = V_224 ;
if ( ! V_224 )
goto V_245;
F_87 ( V_2 ) ;
V_245:
F_33 ( & V_2 -> V_157 ) ;
* V_243 = 0 ;
}
static void F_95 ( struct V_1 * V_2 ,
struct V_147 * V_148 ,
struct V_246 * V_228 ,
T_3 V_247 )
{
struct V_47 * V_168 = F_35 ( V_148 ) ;
int V_16 ;
if ( V_247 & V_248 && V_228 -> V_229 )
F_96 ( V_2 , V_148 ) ;
V_16 = F_97 ( V_2 , V_148 ) ;
if ( V_16 )
F_49 ( V_2 , L_9 , V_148 -> V_70 ) ;
if ( V_247 & V_248 ) {
if ( V_228 -> V_229 ) {
V_16 = F_48 ( V_2 , V_148 ) ;
if ( V_16 ) {
F_49 ( V_2 , L_10 ) ;
return;
}
if ( F_18 ( V_184 ,
& V_2 -> V_139 ) ) {
T_3 V_249 = ( 11 * V_148 -> V_228 . V_250 ) / 10 ;
F_98 ( V_2 , V_148 , V_249 , V_249 ,
5 * V_249 ) ;
}
F_99 ( V_2 , V_148 , false ) ;
F_100 ( V_2 , V_148 ) ;
} else if ( V_168 -> V_170 != V_171 ) {
F_101 ( F_99 ( V_2 , V_148 , false ) ,
L_11 ) ;
V_16 = F_102 ( V_2 , V_148 , V_168 -> V_170 ) ;
if ( V_16 )
F_49 ( V_2 , L_12 ) ;
V_168 -> V_170 = V_171 ;
V_16 = F_48 ( V_2 , NULL ) ;
if ( V_16 )
F_49 ( V_2 , L_10 ) ;
}
F_87 ( V_2 ) ;
V_168 -> V_251 . V_252 = 0 ;
if ( ! ( V_2 -> V_8 -> V_9 . V_10 &
V_253 ) ) {
V_16 = F_56 ( V_2 , V_148 ) ;
if ( V_16 )
F_49 ( V_2 , L_13 ) ;
}
F_103 ( V_2 ) ;
F_104 ( V_2 , V_148 , V_254 ,
V_255 ) ;
} else if ( V_247 & V_256 ) {
F_105 ( V_2 , V_168 ,
& V_168 -> V_174 ) ;
} else if ( V_247 & ( V_257 | V_258 |
V_259 ) ) {
V_16 = F_56 ( V_2 , V_148 ) ;
if ( V_16 )
F_49 ( V_2 , L_13 ) ;
}
if ( V_247 & V_260 ) {
F_106 ( V_2 , L_14 ,
V_228 -> V_261 ) ;
F_59 ( V_2 , V_148 , V_228 -> V_261 ) ;
}
if ( V_247 & V_262 ) {
F_92 ( V_2 , L_15 ) ;
V_168 -> V_251 . V_263 = 0 ;
V_16 = F_107 ( V_2 , V_148 ) ;
if ( V_16 )
F_49 ( V_2 , L_16 ) ;
}
}
static int F_108 ( struct V_13 * V_14 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
int V_16 ;
F_26 ( & V_2 -> V_157 ) ;
V_16 = F_109 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_196;
if ( V_148 -> type == V_54 )
F_96 ( V_2 , V_148 ) ;
V_16 = F_67 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_196;
V_16 = F_71 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_264;
V_168 -> V_265 = true ;
V_16 = F_110 ( V_2 , V_148 , & V_168 -> V_198 ) ;
if ( V_16 )
goto V_210;
V_168 -> V_265 = true ;
V_2 -> V_266 ++ ;
F_111 ( V_2 , V_148 , true ) ;
V_16 = F_48 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_267;
if ( V_148 -> V_202 && V_2 -> V_179 )
F_97 ( V_2 , V_2 -> V_179 ) ;
F_103 ( V_2 ) ;
F_33 ( & V_2 -> V_157 ) ;
return 0 ;
V_267:
V_2 -> V_266 -- ;
F_111 ( V_2 , V_148 , false ) ;
V_168 -> V_265 = false ;
F_112 ( V_2 , & V_168 -> V_198 ) ;
V_210:
F_73 ( V_2 , V_148 ) ;
V_264:
F_75 ( V_2 , V_148 ) ;
V_196:
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_113 ( struct V_13 * V_14 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
F_78 ( V_2 , V_148 ) ;
F_26 ( & V_2 -> V_157 ) ;
V_168 -> V_265 = false ;
F_103 ( V_2 ) ;
if ( V_148 -> V_202 && V_2 -> V_179 )
F_97 ( V_2 , V_2 -> V_179 ) ;
F_48 ( V_2 , NULL ) ;
F_112 ( V_2 , & V_168 -> V_198 ) ;
F_73 ( V_2 , V_148 ) ;
V_2 -> V_266 -- ;
F_111 ( V_2 , V_148 , false ) ;
F_75 ( V_2 , V_148 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static void
F_114 ( struct V_1 * V_2 ,
struct V_147 * V_148 ,
struct V_246 * V_228 ,
T_3 V_247 )
{
struct V_47 * V_168 = F_35 ( V_148 ) ;
enum V_268 V_269 = V_270 |
V_271 |
V_272 ;
int V_16 ;
if ( ! V_168 -> V_265 )
return;
if ( V_247 & V_269 ) {
V_16 = F_97 ( V_2 , V_148 ) ;
if ( V_16 )
F_49 ( V_2 , L_9 , V_148 -> V_70 ) ;
}
if ( V_247 & V_273 ) {
if ( F_109 ( V_2 , V_148 ) )
F_115 ( V_2 , L_17 ) ;
}
}
static void F_116 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_246 * V_228 ,
T_3 V_247 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_26 ( & V_2 -> V_157 ) ;
switch ( V_148 -> type ) {
case V_52 :
F_95 ( V_2 , V_148 , V_228 , V_247 ) ;
break;
case V_54 :
case V_58 :
F_114 ( V_2 , V_148 , V_228 , V_247 ) ;
break;
default:
F_32 ( 1 ) ;
}
F_33 ( & V_2 -> V_157 ) ;
}
static int F_117 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_274 * V_275 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
if ( V_275 -> V_82 == 0 || V_275 -> V_82 > V_276 )
return - V_159 ;
F_26 ( & V_2 -> V_157 ) ;
if ( V_2 -> V_176 == V_177 )
V_16 = F_118 ( V_2 , V_148 , V_275 ) ;
else
V_16 = - V_277 ;
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_119 ( struct V_13 * V_14 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_26 ( & V_2 -> V_157 ) ;
F_120 ( V_2 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static void
F_121 ( struct V_13 * V_14 ,
struct V_151 * V_140 , V_49 V_152 ,
int V_278 ,
enum V_279 V_280 ,
bool V_281 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_122 ( V_2 , V_140 , V_280 , V_278 ) ;
}
static void F_123 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
enum V_282 V_224 ,
struct V_151 * V_140 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_45 * V_283 = F_124 ( V_140 ) ;
switch ( V_224 ) {
case V_284 :
if ( F_125 ( & V_2 -> V_285 [ V_283 -> V_286 ] ) > 0 )
F_126 ( V_14 , V_140 , true ) ;
break;
case V_287 :
if ( F_127 ( V_283 -> V_286 == V_171 ) )
break;
F_128 ( V_2 , V_140 ) ;
break;
default:
break;
}
}
static void F_129 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_151 * V_140 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_45 * V_288 = ( void * ) V_140 -> V_289 ;
F_26 ( & V_2 -> V_157 ) ;
if ( V_140 == F_130 ( V_2 -> V_290 [ V_288 -> V_286 ] ) )
F_131 ( V_2 -> V_290 [ V_288 -> V_286 ] ,
F_132 ( - V_291 ) ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static int F_133 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_151 * V_140 ,
enum V_292 V_293 ,
enum V_292 V_294 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
int V_16 ;
F_92 ( V_2 , L_18 ,
V_140 -> V_70 , V_293 , V_294 ) ;
if ( F_32 ( ! V_168 -> V_175 ) )
return - V_159 ;
F_51 ( & V_2 -> V_217 ) ;
F_26 ( & V_2 -> V_157 ) ;
if ( V_293 == V_295 &&
V_294 == V_296 ) {
if ( V_148 -> type == V_52 &&
V_148 -> V_228 . V_250 < 16 ) {
F_49 ( V_2 ,
L_19 ,
V_140 -> V_70 , V_148 -> V_228 . V_250 ) ;
V_16 = - V_159 ;
goto V_196;
}
V_16 = F_134 ( V_2 , V_148 , V_140 ) ;
} else if ( V_293 == V_296 &&
V_294 == V_297 ) {
V_16 = 0 ;
} else if ( V_293 == V_297 &&
V_294 == V_298 ) {
V_16 = F_135 ( V_2 , V_148 , V_140 ) ;
if ( V_16 == 0 )
F_136 ( V_2 , V_140 ,
V_168 -> V_175 -> V_299 -> V_300 ,
true ) ;
} else if ( V_293 == V_298 &&
V_294 == V_301 ) {
F_127 ( F_137 ( V_2 , V_148 ) ) ;
V_16 = 0 ;
} else if ( V_293 == V_301 &&
V_294 == V_298 ) {
F_127 ( F_69 ( V_2 , V_148 ) ) ;
V_16 = 0 ;
} else if ( V_293 == V_298 &&
V_294 == V_297 ) {
V_16 = 0 ;
} else if ( V_293 == V_297 &&
V_294 == V_296 ) {
V_16 = 0 ;
} else if ( V_293 == V_296 &&
V_294 == V_295 ) {
V_16 = F_138 ( V_2 , V_148 , V_140 ) ;
} else {
V_16 = - V_302 ;
}
V_196:
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static int F_139 ( struct V_13 * V_14 , T_3 V_303 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_2 -> V_102 = V_303 ;
return 0 ;
}
static void F_140 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_151 * V_140 , T_3 V_220 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
if ( V_148 -> type == V_52 &&
V_220 & V_304 )
F_99 ( V_2 , V_148 , false ) ;
}
static int F_141 ( struct V_13 * V_14 ,
struct V_147 * V_148 , V_49 V_213 ,
const struct V_305 * V_306 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
V_168 -> V_307 [ V_213 ] = * V_306 ;
if ( V_148 -> type == V_56 ) {
int V_16 ;
F_26 ( & V_2 -> V_157 ) ;
V_16 = F_97 ( V_2 , V_148 ) ;
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
return 0 ;
}
static void F_142 ( struct V_13 * V_14 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
T_3 V_308 = F_7 ( V_309 ,
200 + V_148 -> V_228 . V_250 ) ;
T_3 V_310 = F_7 ( V_311 ,
100 + V_148 -> V_228 . V_250 ) ;
if ( F_32 ( V_148 -> V_228 . V_229 ) )
return;
F_26 ( & V_2 -> V_157 ) ;
F_98 ( V_2 , V_148 , V_308 , V_310 , 500 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static int F_143 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_312 * V_275 ,
struct V_313 * V_314 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_26 ( & V_2 -> V_157 ) ;
if ( V_2 -> V_176 != V_177 ) {
F_144 ( V_2 ,
L_20 ) ;
V_16 = - V_277 ;
goto V_245;
}
V_2 -> V_176 = V_315 ;
V_16 = F_145 ( V_2 , V_148 , V_275 , V_314 ) ;
if ( V_16 )
goto V_316;
V_16 = F_146 ( V_2 , V_275 ) ;
if ( V_16 )
goto V_316;
V_16 = F_147 ( V_2 , V_275 ) ;
if ( ! V_16 )
goto V_245;
V_316:
V_2 -> V_176 = V_177 ;
V_245:
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_148 ( struct V_13 * V_14 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_26 ( & V_2 -> V_157 ) ;
F_149 ( V_2 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static int F_150 ( struct V_13 * V_14 ,
enum V_317 V_224 ,
struct V_147 * V_148 ,
struct V_151 * V_140 ,
struct V_318 * V_319 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
if ( V_35 . V_36 ) {
F_92 ( V_2 , L_21 ) ;
return - V_320 ;
}
switch ( V_319 -> V_105 ) {
case V_321 :
V_319 -> V_10 |= V_322 ;
case V_323 :
V_319 -> V_10 |= V_324 ;
break;
case V_325 :
F_32 ( ! ( V_14 -> V_10 & V_37 ) ) ;
break;
case V_326 :
case V_327 :
return 0 ;
default:
if ( V_14 -> V_106 &&
V_14 -> V_107 -> V_105 == V_319 -> V_105 )
V_319 -> V_10 |= V_328 ;
else
return - V_320 ;
}
F_26 ( & V_2 -> V_157 ) ;
switch ( V_224 ) {
case V_329 :
if ( ( V_148 -> type == V_58 ||
V_148 -> type == V_54 ) && ! V_140 ) {
V_16 = 0 ;
V_319 -> V_330 = V_331 ;
break;
}
F_92 ( V_2 , L_22 ) ;
V_16 = F_151 ( V_2 , V_148 , V_140 , V_319 , false ) ;
if ( V_16 ) {
F_115 ( V_2 , L_23 ) ;
V_319 -> V_330 = V_331 ;
V_16 = 0 ;
}
break;
case V_332 :
if ( V_319 -> V_330 == V_331 ) {
V_16 = 0 ;
break;
}
F_92 ( V_2 , L_24 ) ;
V_16 = F_152 ( V_2 , V_148 , V_140 , V_319 ) ;
break;
default:
V_16 = - V_159 ;
}
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_153 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_318 * V_333 ,
struct V_151 * V_140 ,
T_3 V_334 , V_49 * V_335 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
if ( V_333 -> V_330 == V_331 )
return;
F_154 ( V_2 , V_148 , V_333 , V_140 , V_334 , V_335 ) ;
}
static int F_155 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_336 * V_299 ,
int V_308 ,
enum V_337 type )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
struct V_338 V_339 ;
struct V_188 * V_175 ;
int V_16 , V_3 ;
F_92 ( V_2 , L_25 , V_299 -> V_340 ,
V_308 , type ) ;
if ( V_148 -> type != V_56 ) {
F_49 ( V_2 , L_26 , V_148 -> type ) ;
return - V_159 ;
}
F_26 ( & V_2 -> V_157 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_175 = & V_2 -> V_4 [ V_3 ] ;
if ( V_175 -> V_7 == 0 || V_168 -> V_175 == V_175 )
continue;
if ( V_175 -> V_7 && V_299 == V_175 -> V_299 ) {
V_16 = F_73 ( V_2 , V_148 ) ;
if ( F_156 ( V_16 , L_27 ) )
goto V_196;
F_74 ( V_2 , V_168 -> V_175 ) ;
V_168 -> V_175 = V_175 ;
V_16 = F_71 ( V_2 , V_148 ) ;
if ( F_156 ( V_16 , L_28 ) )
goto V_196;
F_70 ( V_2 , V_168 -> V_175 ) ;
goto V_341;
}
}
if ( V_299 == V_168 -> V_175 -> V_299 )
goto V_341;
F_157 ( & V_339 , V_299 , V_342 ) ;
if ( V_168 -> V_175 -> V_7 == 1 ) {
V_16 = F_158 ( V_2 , V_168 -> V_175 ,
& V_339 , 1 , 1 ) ;
if ( V_16 )
goto V_196;
} else {
V_175 = F_57 ( V_2 ) ;
if ( ! V_175 ) {
V_16 = - V_207 ;
goto V_196;
}
V_16 = F_158 ( V_2 , V_175 , & V_339 ,
1 , 1 ) ;
if ( V_16 ) {
F_49 ( V_2 , L_29 ) ;
goto V_196;
}
V_16 = F_73 ( V_2 , V_148 ) ;
if ( F_156 ( V_16 , L_27 ) )
goto V_196;
F_74 ( V_2 , V_168 -> V_175 ) ;
V_168 -> V_175 = V_175 ;
V_16 = F_71 ( V_2 , V_148 ) ;
if ( F_156 ( V_16 , L_28 ) )
goto V_196;
F_70 ( V_2 , V_168 -> V_175 ) ;
}
V_341:
V_16 = F_159 ( V_2 , V_148 , V_308 , type ) ;
V_196:
F_33 ( & V_2 -> V_157 ) ;
F_92 ( V_2 , L_30 ) ;
return V_16 ;
}
static int F_160 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_92 ( V_2 , L_31 ) ;
F_26 ( & V_2 -> V_157 ) ;
F_161 ( V_2 ) ;
F_33 ( & V_2 -> V_157 ) ;
F_92 ( V_2 , L_30 ) ;
return 0 ;
}
static int F_162 ( struct V_13 * V_14 ,
struct V_343 * V_344 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_345 = ( V_49 * ) V_344 -> V_289 ;
struct V_188 * V_175 ;
int V_16 ;
F_92 ( V_2 , L_32 ) ;
F_26 ( & V_2 -> V_157 ) ;
V_175 = F_57 ( V_2 ) ;
if ( ! V_175 ) {
V_16 = - V_207 ;
goto V_245;
}
V_16 = F_158 ( V_2 , V_175 , & V_344 -> V_346 ,
V_344 -> V_347 ,
V_344 -> V_348 ) ;
if ( V_16 ) {
F_49 ( V_2 , L_33 ) ;
goto V_245;
}
F_70 ( V_2 , V_175 ) ;
* V_345 = V_175 -> V_6 ;
V_245:
F_33 ( & V_2 -> V_157 ) ;
return V_16 ;
}
static void F_163 ( struct V_13 * V_14 ,
struct V_343 * V_344 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_345 = ( V_49 * ) V_344 -> V_289 ;
struct V_188 * V_175 = & V_2 -> V_4 [ * V_345 ] ;
F_26 ( & V_2 -> V_157 ) ;
F_74 ( V_2 , V_175 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static void F_164 ( struct V_13 * V_14 ,
struct V_343 * V_344 ,
T_3 V_220 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_345 = ( V_49 * ) V_344 -> V_289 ;
struct V_188 * V_175 = & V_2 -> V_4 [ * V_345 ] ;
if ( F_101 ( ( V_175 -> V_7 > 1 ) &&
( V_220 & ~ ( V_349 |
V_350 |
V_351 |
V_352 ) ) ,
L_34 ,
V_175 -> V_7 , V_220 ) )
return;
F_26 ( & V_2 -> V_157 ) ;
F_158 ( V_2 , V_175 , & V_344 -> V_346 ,
V_344 -> V_347 ,
V_344 -> V_348 ) ;
F_103 ( V_2 ) ;
F_33 ( & V_2 -> V_157 ) ;
}
static int F_165 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_343 * V_344 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_345 = ( V_49 * ) V_344 -> V_289 ;
struct V_188 * V_175 = & V_2 -> V_4 [ * V_345 ] ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
int V_16 ;
F_26 ( & V_2 -> V_157 ) ;
V_168 -> V_175 = V_175 ;
switch ( V_148 -> type ) {
case V_54 :
case V_58 :
V_16 = 0 ;
goto V_196;
case V_52 :
case V_353 :
break;
default:
V_16 = - V_159 ;
goto V_196;
}
V_16 = F_71 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_196;
V_2 -> V_266 ++ ;
F_111 ( V_2 , V_148 , true ) ;
if ( V_148 -> type == V_353 ) {
V_168 -> V_354 = true ;
V_16 = F_48 ( V_2 , V_148 ) ;
if ( V_16 )
goto V_355;
}
goto V_196;
V_355:
F_73 ( V_2 , V_148 ) ;
V_2 -> V_266 -- ;
F_111 ( V_2 , V_148 , false ) ;
V_196:
F_33 ( & V_2 -> V_157 ) ;
if ( V_16 )
V_168 -> V_175 = NULL ;
return V_16 ;
}
static void F_166 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
struct V_343 * V_344 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_168 = F_35 ( V_148 ) ;
F_26 ( & V_2 -> V_157 ) ;
F_105 ( V_2 , V_168 , & V_168 -> V_174 ) ;
switch ( V_148 -> type ) {
case V_54 :
case V_58 :
goto V_196;
case V_353 :
V_168 -> V_354 = false ;
F_48 ( V_2 , NULL ) ;
break;
default:
break;
}
F_73 ( V_2 , V_148 ) ;
V_2 -> V_266 -- ;
F_111 ( V_2 , V_148 , false ) ;
V_196:
V_168 -> V_175 = NULL ;
F_33 ( & V_2 -> V_157 ) ;
}
static int F_167 ( struct V_13 * V_14 ,
struct V_151 * V_140 ,
bool V_356 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_45 * V_288 = ( void * ) V_140 -> V_289 ;
if ( ! V_288 || ! V_288 -> V_148 ) {
F_49 ( V_2 , L_35 ) ;
return - V_159 ;
}
return F_109 ( V_2 , V_288 -> V_148 ) ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_147 * V_148 ,
void * V_166 , int V_111 )
{
struct V_357 * V_358 [ V_359 + 1 ] ;
int V_316 ;
T_3 V_219 ;
V_316 = F_169 ( V_358 , V_359 , V_166 , V_111 , V_360 ) ;
if ( V_316 )
return V_316 ;
if ( ! V_358 [ V_361 ] )
return - V_159 ;
switch ( F_170 ( V_358 [ V_361 ] ) ) {
case V_362 :
if ( ! V_148 || V_148 -> type != V_54 || ! V_148 -> V_202 ||
! V_148 -> V_228 . V_363 ||
! V_358 [ V_364 ] )
return - V_159 ;
V_219 = F_170 ( V_358 [ V_364 ] ) ;
if ( V_219 >= V_148 -> V_228 . V_250 )
return - V_159 ;
V_2 -> V_219 = V_219 ;
V_2 -> V_218 = V_148 ;
return F_48 ( V_2 , NULL ) ;
case V_365 :
if ( ! V_148 || V_148 -> type != V_52 ||
! V_148 -> V_228 . V_229 || ! V_148 -> V_228 . V_366 ||
! V_358 [ V_367 ] )
return - V_159 ;
if ( F_170 ( V_358 [ V_367 ] ) )
return F_137 ( V_2 , V_148 ) ;
return F_69 ( V_2 , V_148 ) ;
}
return - V_320 ;
}
static int F_171 ( struct V_13 * V_14 ,
struct V_147 * V_148 ,
void * V_166 , int V_111 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_316 ;
F_26 ( & V_2 -> V_157 ) ;
V_316 = F_168 ( V_2 , V_148 , V_166 , V_111 ) ;
F_33 ( & V_2 -> V_157 ) ;
return V_316 ;
}
