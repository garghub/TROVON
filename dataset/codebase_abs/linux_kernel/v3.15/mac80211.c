void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( ! F_2 ( V_2 ) )
return;
F_3 ( V_2 , L_1 , V_4 ) ;
F_4 ( F_5 ( V_4 , V_2 -> V_5 ) ) ;
F_6 ( V_2 -> V_6 ) ;
}
void F_7 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( ! F_2 ( V_2 ) )
return;
F_3 ( V_2 , L_2 , V_4 ) ;
F_4 ( ! F_8 ( V_4 , V_2 -> V_5 ) ) ;
F_9 ( V_2 -> V_6 ) ;
}
static void
F_10 ( struct V_1 * V_2 , enum V_3 V_7 )
{
int V_8 ;
if ( ! F_2 ( V_2 ) )
return;
F_11 (i, mvm->ref_bitmap, IWL_MVM_REF_COUNT) {
if ( V_7 == V_8 )
continue;
F_3 ( V_2 , L_3 , V_8 ) ;
F_12 ( V_8 , V_2 -> V_5 ) ;
F_9 ( V_2 -> V_6 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
int V_8 ;
memset ( V_2 -> V_9 , 0 , sizeof( V_2 -> V_9 ) ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_2 -> V_9 [ V_8 ] . V_11 = V_8 ;
V_2 -> V_9 [ V_8 ] . V_7 = 0 ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 -> V_13 . V_14 & V_15 )
return V_2 -> V_12 -> V_13 . V_16 - 24 - 2 ;
return V_2 -> V_12 -> V_13 . V_16 - 24 - 34 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_19 , V_20 , V_8 ;
V_18 -> V_14 = V_21 |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 ;
V_18 -> V_33 = V_2 -> V_34 ;
V_18 -> V_35 = V_36 ;
V_18 -> V_37 |= V_38 |
V_39 ;
V_18 -> V_40 |= V_41 ;
V_18 -> V_42 = L_4 ;
if ( V_2 -> V_12 -> V_13 . V_14 & V_43 &&
! V_44 . V_45 )
V_18 -> V_14 |= V_46 ;
if ( 0 && V_2 -> V_12 -> V_13 . V_14 & V_47 ) {
V_18 -> V_14 |= V_48 ;
V_18 -> V_49 = V_50 ;
V_18 -> V_51 = V_52 ;
}
V_18 -> V_53 = sizeof( struct V_54 ) ;
V_18 -> V_55 = sizeof( struct V_56 ) ;
V_18 -> V_57 = sizeof( V_58 ) ;
V_18 -> V_59 -> V_60 = F_16 ( V_61 ) |
F_16 ( V_62 ) |
F_16 ( V_63 ) |
F_16 ( V_64 ) |
F_16 ( V_65 ) ;
if ( F_17 ( V_2 -> V_12 -> V_66 ) >= 8 )
V_18 -> V_59 -> V_60 |= F_16 ( V_67 ) ;
V_18 -> V_59 -> V_14 |= V_68 ;
V_18 -> V_59 -> V_69 |= V_70 |
V_71 ;
if ( V_2 -> V_12 -> V_13 . V_14 & V_72 )
V_18 -> V_59 -> V_14 |= V_73 ;
V_18 -> V_59 -> V_74 = V_75 ;
V_18 -> V_59 -> V_76 =
F_18 ( V_75 ) ;
V_18 -> V_59 -> V_77 = 10000 ;
V_18 -> V_78 = V_79 ;
memcpy ( V_2 -> V_80 [ 0 ] . V_81 , V_2 -> V_82 -> V_83 , V_84 ) ;
V_18 -> V_59 -> V_80 = V_2 -> V_80 ;
V_18 -> V_59 -> V_85 = 1 ;
V_19 = ( V_2 -> V_82 -> V_86 > 1 ) ?
F_19 ( V_87 , V_2 -> V_82 -> V_86 ) : 1 ;
for ( V_8 = 1 ; V_8 < V_19 ; V_8 ++ ) {
memcpy ( V_2 -> V_80 [ V_8 ] . V_81 , V_2 -> V_80 [ V_8 - 1 ] . V_81 ,
V_84 ) ;
V_2 -> V_80 [ V_8 ] . V_81 [ 5 ] ++ ;
V_18 -> V_59 -> V_85 ++ ;
}
F_13 ( V_2 ) ;
V_18 -> V_59 -> V_88 = F_14 ( V_2 ) ;
V_18 -> V_59 -> V_89 = V_90 ;
if ( V_2 -> V_82 -> V_91 [ V_92 ] . V_93 )
V_18 -> V_59 -> V_91 [ V_92 ] =
& V_2 -> V_82 -> V_91 [ V_92 ] ;
if ( V_2 -> V_82 -> V_91 [ V_94 ] . V_93 )
V_18 -> V_59 -> V_91 [ V_94 ] =
& V_2 -> V_82 -> V_91 [ V_94 ] ;
V_18 -> V_59 -> V_95 = V_2 -> V_6 -> V_96 ;
if ( V_97 . V_98 != V_99 )
V_18 -> V_59 -> V_14 |= V_100 ;
else
V_18 -> V_59 -> V_14 &= ~ V_100 ;
if ( V_2 -> V_12 -> V_13 . V_14 & V_101 ) {
V_18 -> V_59 -> V_14 |= V_102 ;
V_18 -> V_59 -> V_103 = V_90 ;
V_18 -> V_59 -> V_104 = V_105 ;
V_18 -> V_59 -> V_106 =
V_107 - 24 - 2 ;
}
V_18 -> V_59 -> V_108 |= V_109 |
V_110 ;
V_2 -> V_111 = V_112 ;
if ( V_2 -> V_12 -> V_113 [ 0 ] . V_114 ) {
V_2 -> V_18 -> V_115 = 1 ;
V_2 -> V_18 -> V_116 = & V_2 -> V_12 -> V_113 [ 0 ] ;
}
#ifdef F_20
if ( V_2 -> V_12 -> V_117 [ V_118 ] . V_119 [ 0 ] . V_120 &&
V_2 -> V_6 -> V_121 -> V_122 &&
V_2 -> V_6 -> V_121 -> V_123 &&
F_21 ( V_2 -> V_6 -> V_124 ) ) {
V_2 -> V_125 . V_14 = V_126 |
V_127 |
V_128 |
V_129 ;
if ( ! V_44 . V_45 )
V_2 -> V_125 . V_14 |= V_130 |
V_131 |
V_132 ;
V_2 -> V_125 . V_133 = V_134 ;
V_2 -> V_125 . V_135 = V_136 ;
V_2 -> V_125 . V_137 = V_138 ;
V_2 -> V_125 . V_139 = & V_140 ;
V_18 -> V_59 -> V_125 = & V_2 -> V_125 ;
}
#endif
#ifdef F_22
V_2 -> V_141 = V_142 ;
#endif
V_20 = F_23 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_24 ( V_2 -> V_18 ) ;
if ( V_20 )
F_25 ( V_2 ) ;
return V_20 ;
}
static bool F_26 ( struct V_1 * V_2 ,
struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_54 * V_147 ;
bool V_148 = false ;
if ( F_27 ( ! F_28 ( V_149 , & V_2 -> V_150 ) ) )
return false ;
F_29 ( & V_2 -> V_151 ) ;
if ( ! F_28 ( V_149 , & V_2 -> V_150 ) )
goto V_152;
V_147 = F_30 ( V_144 ) ;
if ( V_147 -> V_153 == V_154 ||
V_147 -> V_153 != V_2 -> V_155 )
goto V_152;
F_31 ( & V_2 -> V_156 , V_146 ) ;
F_32 ( V_2 -> V_18 ) ;
F_1 ( V_2 , V_157 ) ;
F_7 ( V_2 , V_157 ) ;
V_148 = true ;
V_152:
F_33 ( & V_2 -> V_151 ) ;
return V_148 ;
}
static void F_34 ( struct V_17 * V_18 ,
struct V_158 * V_159 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_143 * V_144 = V_159 -> V_144 ;
struct V_160 * V_161 = F_36 ( V_146 ) ;
struct V_162 * V_163 = ( void * ) V_146 -> V_164 ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_2 , L_5 ) ;
goto V_165;
}
if ( F_36 ( V_146 ) -> V_166 == V_36 &&
! F_28 ( V_167 , & V_2 -> V_150 ) )
goto V_165;
if ( F_39 ( V_161 -> V_14 & V_168 &&
F_40 ( V_163 -> V_169 ) &&
! F_41 ( V_163 -> V_169 ) &&
! F_42 ( V_163 -> V_169 ) &&
! F_43 ( V_163 -> V_169 ) ) )
V_144 = NULL ;
if ( V_144 ) {
if ( F_26 ( V_2 , V_144 , V_146 ) )
return;
if ( F_44 ( V_2 , V_146 , V_144 ) )
goto V_165;
return;
}
if ( F_45 ( V_2 , V_146 ) )
goto V_165;
return;
V_165:
F_46 ( V_18 , V_146 ) ;
}
static inline bool F_47 ( const struct V_170 * V_171 )
{
if ( V_44 . V_172 & V_173 )
return false ;
return true ;
}
static inline bool F_48 ( const struct V_170 * V_171 )
{
if ( V_44 . V_172 & V_174 )
return false ;
if ( V_44 . V_172 & V_175 )
return true ;
return true ;
}
static int F_49 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
enum V_178 V_179 ,
struct V_143 * V_144 , V_58 V_180 ,
V_58 * V_181 , T_1 V_182 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
bool V_183 = false ;
F_50 ( V_2 , L_6 ,
V_144 -> V_81 , V_180 , V_179 ) ;
if ( ! ( V_2 -> V_82 -> V_184 ) )
return - V_185 ;
if ( V_179 == V_186 ) {
F_1 ( V_2 , V_187 ) ;
V_183 = true ;
if ( ! F_51 ( V_2 -> V_188 ,
! F_28 ( V_149 , & V_2 -> V_150 ) , V_189 ) ) {
F_52 ( 1 ) ;
F_7 ( V_2 , V_187 ) ;
return - V_190 ;
}
}
F_53 ( & V_2 -> V_191 ) ;
switch ( V_179 ) {
case V_192 :
if ( ! F_47 ( V_2 -> V_171 ) ) {
V_20 = - V_193 ;
break;
}
V_20 = F_54 ( V_2 , V_144 , V_180 , * V_181 , true ) ;
break;
case V_194 :
V_20 = F_54 ( V_2 , V_144 , V_180 , 0 , false ) ;
break;
case V_186 :
if ( ! F_48 ( V_2 -> V_171 ) ) {
V_20 = - V_193 ;
break;
}
V_20 = F_55 ( V_2 , V_177 , V_144 , V_180 , V_181 ) ;
break;
case V_195 :
V_20 = F_56 ( V_2 , V_177 , V_144 , V_180 ) ;
break;
case V_196 :
case V_197 :
V_20 = F_57 ( V_2 , V_177 , V_144 , V_180 ) ;
break;
case V_198 :
V_20 = F_58 ( V_2 , V_177 , V_144 , V_180 , V_182 ) ;
break;
default:
F_52 ( 1 ) ;
V_20 = - V_193 ;
break;
}
F_59 ( & V_2 -> V_191 ) ;
if ( V_183 )
F_7 ( V_2 , V_187 ) ;
return V_20 ;
}
static void F_60 ( void * V_164 , T_1 * V_199 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = V_164 ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
V_200 -> V_201 = false ;
V_200 -> V_202 = V_154 ;
V_200 -> V_203 ++ ;
F_62 ( & V_2 -> V_204 ) ;
F_63 ( V_2 , & V_200 -> V_205 ) ;
F_64 ( & V_2 -> V_204 ) ;
V_200 -> V_206 = NULL ;
}
static void F_65 ( struct V_1 * V_2 )
{
#ifdef F_66
static char * V_207 [] = { L_7 , L_8 , NULL } ;
F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_18 -> V_59 -> V_124 . V_208 , V_209 , V_207 ) ;
#endif
F_69 ( V_2 -> V_6 ) ;
V_2 -> V_210 = V_211 ;
F_70 ( V_2 -> V_18 ) ;
F_71 (
V_2 -> V_18 , V_212 ,
F_60 , V_2 ) ;
V_2 -> V_213 = NULL ;
V_2 -> V_155 = V_154 ;
F_13 ( V_2 ) ;
memset ( V_2 -> V_214 , 0 , sizeof( V_2 -> V_214 ) ) ;
memset ( V_2 -> V_215 , 0 , sizeof( V_2 -> V_215 ) ) ;
F_72 ( V_2 -> V_18 ) ;
F_10 ( V_2 , V_216 ) ;
V_2 -> V_217 = 0 ;
V_2 -> V_218 = 0 ;
}
static int F_73 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
if ( F_28 ( V_219 , & V_2 -> V_150 ) )
F_65 ( V_2 ) ;
V_20 = F_74 ( V_2 ) ;
F_59 ( & V_2 -> V_191 ) ;
return V_20 ;
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
F_12 ( V_219 , & V_2 -> V_150 ) ;
F_76 ( V_2 , NULL ) ;
V_20 = F_77 ( V_2 , NULL ) ;
if ( V_20 )
F_78 ( V_2 , L_9 ,
V_20 ) ;
F_7 ( V_2 , V_216 ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static void F_79 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_80 ( & V_2 -> V_220 ) ;
F_80 ( & V_2 -> V_221 ) ;
F_53 ( & V_2 -> V_191 ) ;
F_1 ( V_2 , V_216 ) ;
F_81 ( & V_2 -> V_222 ) ;
F_69 ( V_2 -> V_6 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 , & V_2 -> V_223 ) ;
F_59 ( & V_2 -> V_191 ) ;
F_81 ( & V_2 -> V_221 ) ;
}
static struct V_224 * F_84 ( struct V_1 * V_2 )
{
V_58 V_8 ;
F_85 ( & V_2 -> V_191 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
if ( ! V_2 -> V_9 [ V_8 ] . V_7 )
return & V_2 -> V_9 [ V_8 ] ;
F_78 ( V_2 , L_10 ) ;
return NULL ;
}
static int F_86 ( struct V_1 * V_2 , struct V_176 * V_177 ,
T_2 V_225 )
{
struct V_226 V_227 = {
. V_228 = F_61 ( V_177 ) -> V_11 ,
. V_229 = F_87 ( V_225 ) ,
} ;
return F_88 ( V_2 , V_230 , V_231 ,
sizeof( V_227 ) ,
& V_227 ) ;
}
static int F_89 ( struct V_17 * V_18 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
V_20 = F_90 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_232;
if ( V_177 -> type != V_65 )
V_2 -> V_217 ++ ;
if ( V_177 -> type == V_63 ||
V_177 -> type == V_67 ) {
T_3 V_233 = F_91 ( V_2 , V_177 ) ;
V_20 = F_92 ( V_2 , & V_200 -> V_234 ,
V_233 ,
F_93 ( V_177 ) ) ;
if ( V_20 ) {
F_78 ( V_2 , L_11 ) ;
goto V_235;
}
F_94 ( V_2 , V_177 ) ;
goto V_232;
}
V_20 = F_95 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_235;
V_20 = F_96 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_235;
V_20 = F_97 ( V_2 , V_177 , V_231 ) ;
if ( V_20 )
goto V_236;
if ( ! V_2 -> V_237 && false &&
V_177 -> type == V_61 && ! V_177 -> V_238 &&
V_2 -> V_12 -> V_13 . V_14 & V_239 ) {
V_2 -> V_237 = V_200 ;
V_177 -> V_240 |= V_241 |
V_242 ;
}
if ( V_177 -> type == V_65 ) {
V_200 -> V_206 = F_84 ( V_2 ) ;
if ( ! V_200 -> V_206 ) {
V_20 = - V_243 ;
goto V_244;
}
F_98 ( V_2 , V_200 -> V_206 ) ;
V_20 = F_99 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_245;
V_20 = F_100 ( V_2 , V_177 , & V_200 -> V_234 ) ;
if ( V_20 )
goto V_246;
V_2 -> V_213 = V_177 ;
}
F_94 ( V_2 , V_177 ) ;
goto V_232;
V_246:
F_101 ( V_2 , V_177 ) ;
V_245:
F_102 ( V_2 , V_200 -> V_206 ) ;
V_244:
if ( V_2 -> V_237 == V_200 ) {
V_2 -> V_237 = NULL ;
V_177 -> V_240 &= ~ ( V_241 |
V_242 ) ;
}
V_236:
V_200 -> V_206 = NULL ;
F_103 ( V_2 , V_177 ) ;
V_235:
if ( V_177 -> type != V_65 )
V_2 -> V_217 -- ;
F_104 ( V_2 , V_177 ) ;
V_232:
F_59 ( & V_2 -> V_191 ) ;
return V_20 ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_176 * V_177 )
{
T_3 V_247 = 0 , V_248 ;
for ( V_248 = 0 ; V_248 < V_249 ; V_248 ++ )
if ( V_177 -> V_166 [ V_248 ] != V_250 )
V_247 |= F_16 ( V_177 -> V_166 [ V_248 ] ) ;
if ( V_177 -> V_251 != V_250 )
V_247 |= F_16 ( V_177 -> V_251 ) ;
if ( V_247 ) {
F_53 ( & V_2 -> V_191 ) ;
F_106 ( V_2 , V_247 , true ) ;
F_59 ( & V_2 -> V_191 ) ;
}
if ( V_177 -> type == V_65 ) {
F_80 ( & V_2 -> V_222 ) ;
} else {
F_80 ( & V_2 -> V_252 ) ;
}
}
static void F_107 ( struct V_17 * V_18 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
F_105 ( V_2 , V_177 ) ;
F_53 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_237 == V_200 ) {
V_2 -> V_237 = NULL ;
V_177 -> V_240 &= ~ ( V_241 |
V_242 ) ;
}
F_108 ( V_2 , V_177 ) ;
if ( V_177 -> type == V_63 ||
V_177 -> type == V_67 ) {
#ifdef F_109
if ( V_177 == V_2 -> V_253 ) {
V_2 -> V_253 = NULL ;
V_2 -> V_254 = 0 ;
}
#endif
F_83 ( V_2 , & V_200 -> V_234 ) ;
goto V_235;
}
if ( V_177 -> type == V_65 ) {
V_2 -> V_213 = NULL ;
F_110 ( V_2 , & V_200 -> V_234 ) ;
F_101 ( V_2 , V_177 ) ;
F_102 ( V_2 , V_200 -> V_206 ) ;
V_200 -> V_206 = NULL ;
}
if ( V_2 -> V_217 && V_177 -> type != V_65 )
V_2 -> V_217 -- ;
F_96 ( V_2 , V_177 ) ;
F_103 ( V_2 , V_177 ) ;
V_235:
F_104 ( V_2 , V_177 ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static int F_111 ( struct V_17 * V_18 , T_3 V_255 )
{
return 0 ;
}
static void F_112 ( void * V_256 , T_1 * V_199 ,
struct V_176 * V_177 )
{
struct V_257 * V_164 = V_256 ;
struct V_1 * V_2 = V_164 -> V_2 ;
struct V_258 * V_259 = V_2 -> V_260 ;
int V_20 , V_120 ;
if ( F_52 ( V_164 -> V_261 >= V_262 ) )
return;
if ( V_177 -> type != V_61 ||
! V_177 -> V_263 . V_264 )
return;
V_259 -> V_261 = V_164 -> V_261 ++ ;
memcpy ( V_259 -> V_265 , V_177 -> V_263 . V_265 , V_84 ) ;
V_120 = F_113 ( sizeof( * V_259 ) + V_259 -> V_266 * V_84 , 4 ) ;
V_20 = F_88 ( V_2 , V_267 , V_268 , V_120 , V_259 ) ;
if ( V_20 )
F_78 ( V_2 , L_12 , V_20 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_257 V_269 = {
. V_2 = V_2 ,
} ;
F_85 ( & V_2 -> V_191 ) ;
if ( F_52 ( ! V_2 -> V_260 ) )
return;
F_71 (
V_2 -> V_18 , V_270 ,
F_112 , & V_269 ) ;
}
static T_4 F_115 ( struct V_17 * V_18 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_258 * V_259 ;
struct V_273 * V_81 ;
int V_274 = F_116 ( V_272 ) ;
bool V_275 = false ;
int V_120 ;
if ( V_274 > V_276 ) {
V_275 = true ;
V_274 = 0 ;
}
V_120 = F_113 ( sizeof( * V_259 ) + V_274 * V_84 , 4 ) ;
V_259 = F_117 ( V_120 , V_277 ) ;
if ( ! V_259 )
return 0 ;
if ( V_275 ) {
V_259 -> V_275 = 1 ;
return ( T_4 ) ( unsigned long ) V_259 ;
}
F_118 (addr, mc_list) {
F_119 ( V_2 , L_13 ,
V_259 -> V_266 , V_81 -> V_81 ) ;
memcpy ( & V_259 -> V_278 [ V_259 -> V_266 * V_84 ] ,
V_81 -> V_81 , V_84 ) ;
V_259 -> V_266 ++ ;
}
return ( T_4 ) ( unsigned long ) V_259 ;
}
static void F_120 ( struct V_17 * V_18 ,
unsigned int V_279 ,
unsigned int * V_280 ,
T_4 V_281 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_258 * V_259 = ( void * ) ( unsigned long ) V_281 ;
F_53 ( & V_2 -> V_191 ) ;
F_121 ( V_2 -> V_260 ) ;
V_2 -> V_260 = V_259 ;
if ( ! V_259 )
goto V_152;
F_114 ( V_2 ) ;
V_152:
F_59 ( & V_2 -> V_191 ) ;
* V_280 = 0 ;
}
static void
F_122 ( struct V_176 * V_177 ,
const struct V_282 * V_283 ,
struct V_282 * V_284 )
{
struct V_285 * V_286 ;
int V_8 ;
memcpy ( V_284 , V_283 , sizeof( * V_284 ) ) ;
for ( V_8 = 0 ; V_8 < F_18 ( V_284 -> V_287 ) ; V_8 ++ ) {
V_286 = & V_284 -> V_287 [ V_8 ] ;
if ( ! V_286 -> V_288 )
break;
switch ( V_286 -> V_289 ) {
case F_87 ( V_290 ) :
if ( V_177 -> V_263 . V_291 != 1 ) {
V_286 -> V_288 = 0 ;
continue;
}
V_286 -> V_292 = V_177 -> V_263 . V_293 [ 0 ] ;
break;
case F_87 ( V_294 ) :
V_286 -> V_292 = * ( V_295 * ) & V_177 -> V_81 [ 2 ] ;
break;
default:
break;
}
V_286 -> V_289 = 0 ;
V_284 -> V_296 ++ ;
}
}
static void F_123 ( void * V_256 , T_1 * V_199 ,
struct V_176 * V_177 )
{
struct V_297 * V_164 = V_256 ;
struct V_1 * V_2 = V_164 -> V_2 ;
struct V_298 * V_259 = V_164 -> V_259 ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
struct V_299 * V_300 ;
int V_8 ;
if ( F_4 ( V_200 -> V_11 >= F_18 ( V_259 -> V_301 ) ) )
return;
V_300 = & V_259 -> V_301 [ V_200 -> V_11 ] ;
if ( V_177 -> type != V_61 || ! V_177 -> V_263 . V_264 )
return;
V_300 -> V_302 = 1 ;
for ( V_8 = 0 ; V_2 -> V_141 [ V_8 ] . V_287 [ 0 ] . V_288 ; V_8 ++ ) {
if ( F_52 ( V_164 -> V_303 >=
F_18 ( V_259 -> V_304 ) ) ) {
V_300 -> V_302 = 0 ;
V_300 -> V_305 = 0 ;
break;
}
F_122 ( V_177 ,
& V_2 -> V_141 [ V_8 ] ,
& V_259 -> V_304 [ V_164 -> V_303 ] ) ;
if ( ! V_259 -> V_304 [ V_164 -> V_303 ] . V_296 )
continue;
V_300 -> V_305 |=
F_87 ( F_16 ( V_164 -> V_303 ) ) ;
V_164 -> V_303 ++ ;
}
}
bool F_124 ( struct V_1 * V_2 ,
struct V_298 * V_259 )
{
struct V_297 V_269 = {
. V_2 = V_2 ,
. V_259 = V_259 ,
} ;
memset ( V_259 , 0 , sizeof( * V_259 ) ) ;
V_259 -> V_306 = F_18 ( V_259 -> V_304 ) ;
V_259 -> V_307 = F_18 ( V_259 -> V_301 ) ;
#ifdef F_66
if ( V_2 -> V_308 . V_309 ) {
memcpy ( V_259 -> V_304 , & V_2 -> V_308 . V_259 . V_304 ,
sizeof( V_259 -> V_304 ) ) ;
memcpy ( V_259 -> V_301 , & V_2 -> V_308 . V_259 . V_301 ,
sizeof( V_259 -> V_301 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_141 )
return false ;
F_125 (
V_2 -> V_18 , V_270 ,
F_123 , & V_269 ) ;
return true ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_176 * V_177 )
{
struct V_298 V_259 ;
if ( ! ( V_2 -> V_12 -> V_13 . V_14 & V_310 ) )
return 0 ;
if ( ! F_124 ( V_2 , & V_259 ) )
return 0 ;
return F_88 ( V_2 , V_311 , V_231 ,
sizeof( V_259 ) , & V_259 ) ;
}
static inline int F_126 ( struct V_1 * V_2 ,
struct V_176 * V_177 )
{
return 0 ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_176 * V_177 ,
struct V_312 * V_263 ,
T_3 V_313 )
{
struct V_56 * V_200 = F_61 ( V_177 ) ;
int V_20 ;
if ( V_313 & V_314 && V_263 -> V_264 )
F_128 ( V_2 , V_177 ) ;
V_20 = F_129 ( V_2 , V_177 ) ;
if ( V_20 )
F_78 ( V_2 , L_14 , V_177 -> V_81 ) ;
if ( V_313 & V_314 ) {
if ( V_263 -> V_264 ) {
V_20 = F_77 ( V_2 , V_177 ) ;
if ( V_20 ) {
F_78 ( V_2 , L_15 ) ;
return;
}
if ( F_28 ( V_219 ,
& V_2 -> V_150 ) ) {
T_3 V_315 = ( 11 * V_177 -> V_263 . V_316 ) / 10 ;
F_130 ( V_2 , V_177 , V_315 , V_315 ,
5 * V_315 ) ;
}
F_131 ( V_2 , V_177 , false ) ;
F_132 ( V_2 , V_177 ) ;
if ( V_177 -> V_238 )
F_1 ( V_2 , V_317 ) ;
} else if ( V_200 -> V_202 != V_154 ) {
F_133 ( F_131 ( V_2 , V_177 , false ) ,
L_16 ) ;
V_20 = F_134 ( V_2 , V_177 , V_200 -> V_202 ) ;
if ( V_20 )
F_78 ( V_2 , L_17 ) ;
if ( V_2 -> V_155 == V_200 -> V_202 )
V_2 -> V_155 = V_154 ;
V_200 -> V_202 = V_154 ;
V_20 = F_77 ( V_2 , NULL ) ;
if ( V_20 )
F_78 ( V_2 , L_15 ) ;
if ( V_177 -> V_238 )
F_7 ( V_2 , V_317 ) ;
}
F_114 ( V_2 ) ;
F_126 ( V_2 , V_177 ) ;
V_200 -> V_318 . V_319 = 0 ;
F_135 ( V_2 ) ;
F_136 ( V_2 , V_177 , V_320 ,
V_321 ) ;
} else if ( V_313 & V_322 ) {
F_137 ( V_2 , V_200 ,
& V_200 -> V_205 ) ;
F_131 ( V_2 , V_177 , false ) ;
F_4 ( F_138 ( V_2 , V_177 , V_231 ) ) ;
} else if ( V_313 & ( V_323 | V_324 |
V_325 ) ) {
V_20 = F_96 ( V_2 , V_177 ) ;
if ( V_20 )
F_78 ( V_2 , L_18 ) ;
}
if ( V_313 & V_326 ) {
F_139 ( V_2 , L_19 ,
V_263 -> V_327 ) ;
F_86 ( V_2 , V_177 , V_263 -> V_327 ) ;
}
if ( V_313 & V_328 ) {
F_119 ( V_2 , L_20 ) ;
V_200 -> V_318 . V_329 = 0 ;
V_20 = F_140 ( V_2 , V_177 , false , V_231 ) ;
if ( V_20 )
F_78 ( V_2 , L_21 ) ;
}
if ( V_313 & V_330 ) {
F_119 ( V_2 , L_22 ) ;
F_126 ( V_2 , V_177 ) ;
}
}
static int F_141 ( struct V_17 * V_18 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
V_20 = F_142 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_232;
if ( V_177 -> type == V_63 )
F_128 ( V_2 , V_177 ) ;
V_20 = F_95 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_232;
V_20 = F_99 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_331;
V_20 = F_143 ( V_2 , V_177 , & V_200 -> V_234 ) ;
if ( V_20 )
goto V_246;
V_200 -> V_332 = true ;
F_96 ( V_2 , V_177 ) ;
V_20 = F_77 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_333;
if ( V_177 -> V_238 && V_2 -> V_213 )
F_129 ( V_2 , V_2 -> V_213 ) ;
F_1 ( V_2 , V_334 ) ;
F_135 ( V_2 ) ;
F_59 ( & V_2 -> V_191 ) ;
return 0 ;
V_333:
F_96 ( V_2 , V_177 ) ;
V_200 -> V_332 = false ;
F_144 ( V_2 , & V_200 -> V_234 ) ;
V_246:
F_101 ( V_2 , V_177 ) ;
V_331:
F_103 ( V_2 , V_177 ) ;
V_232:
F_59 ( & V_2 -> V_191 ) ;
return V_20 ;
}
static void F_145 ( struct V_17 * V_18 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
F_105 ( V_2 , V_177 ) ;
F_53 ( & V_2 -> V_191 ) ;
V_200 -> V_332 = false ;
F_135 ( V_2 ) ;
F_7 ( V_2 , V_334 ) ;
if ( V_177 -> V_238 && V_2 -> V_213 )
F_129 ( V_2 , V_2 -> V_213 ) ;
F_77 ( V_2 , NULL ) ;
F_144 ( V_2 , & V_200 -> V_234 ) ;
F_101 ( V_2 , V_177 ) ;
F_96 ( V_2 , V_177 ) ;
F_103 ( V_2 , V_177 ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static void
F_146 ( struct V_1 * V_2 ,
struct V_176 * V_177 ,
struct V_312 * V_263 ,
T_3 V_313 )
{
struct V_56 * V_200 = F_61 ( V_177 ) ;
if ( ! V_200 -> V_332 )
return;
if ( V_313 & ( V_335 | V_336 |
V_337 ) &&
F_129 ( V_2 , V_177 ) )
F_78 ( V_2 , L_14 , V_177 -> V_81 ) ;
if ( V_313 & V_338 &&
F_142 ( V_2 , V_177 ) )
F_147 ( V_2 , L_23 ) ;
}
static void F_148 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_312 * V_263 ,
T_3 V_313 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_53 ( & V_2 -> V_191 ) ;
switch ( V_177 -> type ) {
case V_61 :
F_127 ( V_2 , V_177 , V_263 , V_313 ) ;
break;
case V_63 :
case V_67 :
F_146 ( V_2 , V_177 , V_263 , V_313 ) ;
break;
default:
F_52 ( 1 ) ;
}
F_59 ( & V_2 -> V_191 ) ;
}
static int F_149 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_339 * V_340 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
if ( V_340 -> V_93 == 0 || V_340 -> V_93 > V_341 )
return - V_193 ;
F_53 ( & V_2 -> V_191 ) ;
switch ( V_2 -> V_210 ) {
case V_342 :
V_20 = F_150 ( V_2 ) ;
if ( V_20 ) {
V_20 = - V_343 ;
goto V_152;
}
break;
case V_211 :
break;
default:
V_20 = - V_343 ;
goto V_152;
}
F_1 ( V_2 , V_344 ) ;
V_20 = F_151 ( V_2 , V_177 , V_340 ) ;
if ( V_20 )
F_7 ( V_2 , V_344 ) ;
V_152:
F_59 ( & V_2 -> V_191 ) ;
F_152 ( V_2 ) ;
return V_20 ;
}
static void F_153 ( struct V_17 * V_18 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_53 ( & V_2 -> V_191 ) ;
F_154 ( V_2 ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static void
F_155 ( struct V_17 * V_18 ,
struct V_143 * V_144 , V_58 V_345 ,
int V_346 ,
enum V_347 V_348 ,
bool V_349 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_156 ( V_2 , V_144 , V_348 , V_346 ,
V_345 , V_349 , false ) ;
}
static void
F_157 ( struct V_17 * V_18 ,
struct V_143 * V_144 , V_58 V_345 ,
int V_346 ,
enum V_347 V_348 ,
bool V_349 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_156 ( V_2 , V_144 , V_348 , V_346 ,
V_345 , V_349 , true ) ;
}
static void F_158 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
enum V_350 V_259 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_54 * V_147 = F_30 ( V_144 ) ;
int V_180 ;
switch ( V_259 ) {
case V_351 :
if ( F_159 ( & V_2 -> V_352 [ V_147 -> V_153 ] ) > 0 )
F_160 ( V_18 , V_144 , true ) ;
F_62 ( & V_147 -> V_353 ) ;
for ( V_180 = 0 ; V_180 < V_354 ; V_180 ++ ) {
struct V_355 * V_356 ;
V_356 = & V_147 -> V_356 [ V_180 ] ;
if ( V_356 -> V_357 != V_358 &&
V_356 -> V_357 != V_359 )
continue;
if ( F_161 ( V_356 ) == 0 )
continue;
F_162 ( V_144 , V_180 , true ) ;
}
F_64 ( & V_147 -> V_353 ) ;
break;
case V_360 :
if ( F_4 ( V_147 -> V_153 == V_154 ) )
break;
F_163 ( V_2 , V_144 ) ;
break;
default:
break;
}
}
static void F_164 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_54 * V_361 = ( void * ) V_144 -> V_362 ;
F_53 ( & V_2 -> V_191 ) ;
if ( V_144 == F_165 ( V_2 -> V_363 [ V_361 -> V_153 ] ) )
F_166 ( V_2 -> V_363 [ V_361 -> V_153 ] ,
F_167 ( - V_364 ) ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static int F_168 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_143 * V_144 ,
enum V_365 V_366 ,
enum V_365 V_367 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
int V_20 ;
F_119 ( V_2 , L_24 ,
V_144 -> V_81 , V_366 , V_367 ) ;
if ( F_52 ( ! V_200 -> V_206 ) )
return - V_193 ;
F_80 ( & V_2 -> V_252 ) ;
F_53 ( & V_2 -> V_191 ) ;
if ( V_366 == V_368 &&
V_367 == V_369 ) {
if ( V_177 -> type == V_61 &&
V_177 -> V_263 . V_316 < 16 ) {
F_78 ( V_2 ,
L_25 ,
V_144 -> V_81 , V_177 -> V_263 . V_316 ) ;
V_20 = - V_193 ;
goto V_232;
}
V_20 = F_169 ( V_2 , V_177 , V_144 ) ;
} else if ( V_366 == V_369 &&
V_367 == V_370 ) {
V_20 = 0 ;
} else if ( V_366 == V_370 &&
V_367 == V_371 ) {
V_20 = F_170 ( V_2 , V_177 , V_144 ) ;
if ( V_20 == 0 )
F_171 ( V_2 , V_144 ,
V_200 -> V_206 -> V_372 -> V_373 ,
true ) ;
} else if ( V_366 == V_371 &&
V_367 == V_374 ) {
if ( V_177 -> V_263 . V_375 )
F_4 ( F_138 ( V_2 , V_177 ,
V_231 ) ) ;
V_20 = 0 ;
} else if ( V_366 == V_374 &&
V_367 == V_371 ) {
F_4 ( F_97 ( V_2 , V_177 , V_231 ) ) ;
V_20 = 0 ;
} else if ( V_366 == V_371 &&
V_367 == V_370 ) {
V_20 = 0 ;
} else if ( V_366 == V_370 &&
V_367 == V_369 ) {
V_20 = 0 ;
} else if ( V_366 == V_369 &&
V_367 == V_368 ) {
V_20 = F_172 ( V_2 , V_177 , V_144 ) ;
} else {
V_20 = - V_190 ;
}
V_232:
F_59 ( & V_2 -> V_191 ) ;
return V_20 ;
}
static int F_173 ( struct V_17 * V_18 , T_3 V_376 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_2 -> V_111 = V_376 ;
return 0 ;
}
static void F_174 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_143 * V_144 , T_3 V_255 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
if ( V_177 -> type == V_61 &&
V_255 & V_377 )
F_131 ( V_2 , V_177 , false ) ;
}
static int F_175 ( struct V_17 * V_18 ,
struct V_176 * V_177 , V_58 V_248 ,
const struct V_378 * V_379 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
V_200 -> V_380 [ V_248 ] = * V_379 ;
if ( V_177 -> type == V_65 ) {
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
V_20 = F_129 ( V_2 , V_177 ) ;
F_59 ( & V_2 -> V_191 ) ;
return V_20 ;
}
return 0 ;
}
static void F_176 ( struct V_17 * V_18 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
T_3 V_381 = F_19 ( V_382 ,
200 + V_177 -> V_263 . V_316 ) ;
T_3 V_383 = F_19 ( V_384 ,
100 + V_177 -> V_263 . V_316 ) ;
if ( F_52 ( V_177 -> V_263 . V_264 ) )
return;
F_53 ( & V_2 -> V_191 ) ;
F_130 ( V_2 , V_177 , V_381 , V_383 , 500 ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static int F_177 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_385 * V_340 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
if ( ! F_178 ( V_2 ) ) {
V_20 = - V_343 ;
goto V_152;
}
switch ( V_2 -> V_210 ) {
case V_388 :
F_179 ( V_2 , L_26 ) ;
V_20 = F_154 ( V_2 ) ;
if ( V_20 ) {
V_20 = - V_343 ;
goto V_152;
}
break;
case V_211 :
break;
default:
V_20 = - V_343 ;
goto V_152;
}
V_2 -> V_210 = V_342 ;
V_20 = F_180 ( V_2 , V_177 , V_340 , V_387 ) ;
if ( V_20 )
goto V_389;
V_20 = F_181 ( V_2 , V_340 ) ;
if ( V_20 )
goto V_389;
V_20 = F_182 ( V_2 , V_340 ) ;
if ( ! V_20 )
goto V_152;
V_389:
V_2 -> V_210 = V_211 ;
V_152:
F_59 ( & V_2 -> V_191 ) ;
F_152 ( V_2 ) ;
return V_20 ;
}
static int F_183 ( struct V_17 * V_18 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
V_20 = F_150 ( V_2 ) ;
F_59 ( & V_2 -> V_191 ) ;
F_152 ( V_2 ) ;
return V_20 ;
}
static int F_184 ( struct V_17 * V_18 ,
enum V_390 V_259 ,
struct V_176 * V_177 ,
struct V_143 * V_144 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
if ( V_44 . V_45 ) {
F_119 ( V_2 , L_27 ) ;
return - V_393 ;
}
switch ( V_392 -> V_114 ) {
case V_394 :
V_392 -> V_14 |= V_395 ;
case V_396 :
V_392 -> V_14 |= V_397 ;
break;
case V_398 :
F_52 ( ! ( V_18 -> V_14 & V_46 ) ) ;
break;
case V_399 :
case V_400 :
return 0 ;
default:
if ( V_18 -> V_115 &&
V_18 -> V_116 -> V_114 == V_392 -> V_114 )
V_392 -> V_14 |= V_401 ;
else
return - V_393 ;
}
F_53 ( & V_2 -> V_191 ) ;
switch ( V_259 ) {
case V_402 :
if ( ( V_177 -> type == V_67 ||
V_177 -> type == V_63 ) && ! V_144 ) {
V_20 = 0 ;
V_392 -> V_403 = V_404 ;
break;
}
F_119 ( V_2 , L_28 ) ;
V_20 = F_185 ( V_2 , V_177 , V_144 , V_392 , false ) ;
if ( V_20 ) {
F_147 ( V_2 , L_29 ) ;
V_392 -> V_403 = V_404 ;
V_20 = 0 ;
}
break;
case V_405 :
if ( V_392 -> V_403 == V_404 ) {
V_20 = 0 ;
break;
}
F_119 ( V_2 , L_30 ) ;
V_20 = F_186 ( V_2 , V_177 , V_144 , V_392 ) ;
break;
default:
V_20 = - V_193 ;
}
F_59 ( & V_2 -> V_191 ) ;
return V_20 ;
}
static void F_187 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_391 * V_406 ,
struct V_143 * V_144 ,
T_3 V_407 , V_58 * V_408 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
if ( V_406 -> V_403 == V_404 )
return;
F_188 ( V_2 , V_177 , V_406 , V_144 , V_407 , V_408 ) ;
}
static int F_189 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_409 * V_372 ,
int V_381 ,
enum V_410 type )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
struct V_411 V_412 ;
struct V_224 * V_206 ;
int V_20 , V_8 ;
F_119 ( V_2 , L_31 , V_372 -> V_413 ,
V_381 , type ) ;
if ( V_177 -> type != V_65 ) {
F_78 ( V_2 , L_32 , V_177 -> type ) ;
return - V_193 ;
}
F_53 ( & V_2 -> V_191 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_206 = & V_2 -> V_9 [ V_8 ] ;
if ( V_206 -> V_7 == 0 || V_200 -> V_206 == V_206 )
continue;
if ( V_206 -> V_7 && V_372 == V_206 -> V_372 ) {
V_20 = F_101 ( V_2 , V_177 ) ;
if ( F_190 ( V_20 , L_33 ) )
goto V_232;
F_102 ( V_2 , V_200 -> V_206 ) ;
V_200 -> V_206 = V_206 ;
V_20 = F_99 ( V_2 , V_177 ) ;
if ( F_190 ( V_20 , L_34 ) )
goto V_232;
F_98 ( V_2 , V_200 -> V_206 ) ;
goto V_414;
}
}
if ( V_372 == V_200 -> V_206 -> V_372 )
goto V_414;
F_191 ( & V_412 , V_372 , V_415 ) ;
if ( V_200 -> V_206 -> V_7 == 1 ) {
V_20 = F_192 ( V_2 , V_200 -> V_206 ,
& V_412 , 1 , 1 ) ;
if ( V_20 )
goto V_232;
} else {
V_206 = F_84 ( V_2 ) ;
if ( ! V_206 ) {
V_20 = - V_243 ;
goto V_232;
}
V_20 = F_192 ( V_2 , V_206 , & V_412 ,
1 , 1 ) ;
if ( V_20 ) {
F_78 ( V_2 , L_35 ) ;
goto V_232;
}
V_20 = F_101 ( V_2 , V_177 ) ;
if ( F_190 ( V_20 , L_33 ) )
goto V_232;
F_102 ( V_2 , V_200 -> V_206 ) ;
V_200 -> V_206 = V_206 ;
V_20 = F_99 ( V_2 , V_177 ) ;
if ( F_190 ( V_20 , L_34 ) )
goto V_232;
F_98 ( V_2 , V_200 -> V_206 ) ;
}
V_414:
V_20 = F_193 ( V_2 , V_177 , V_381 , type ) ;
V_232:
F_59 ( & V_2 -> V_191 ) ;
F_119 ( V_2 , L_36 ) ;
return V_20 ;
}
static int F_194 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_119 ( V_2 , L_37 ) ;
F_53 ( & V_2 -> V_191 ) ;
F_195 ( V_2 ) ;
F_59 ( & V_2 -> V_191 ) ;
F_119 ( V_2 , L_36 ) ;
return 0 ;
}
static int F_196 ( struct V_17 * V_18 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_58 * V_418 = ( V_58 * ) V_417 -> V_362 ;
struct V_224 * V_206 ;
int V_20 ;
F_119 ( V_2 , L_38 ) ;
F_53 ( & V_2 -> V_191 ) ;
V_206 = F_84 ( V_2 ) ;
if ( ! V_206 ) {
V_20 = - V_243 ;
goto V_152;
}
V_20 = F_192 ( V_2 , V_206 , & V_417 -> V_419 ,
V_417 -> V_420 ,
V_417 -> V_421 ) ;
if ( V_20 ) {
F_78 ( V_2 , L_39 ) ;
goto V_152;
}
F_98 ( V_2 , V_206 ) ;
* V_418 = V_206 -> V_11 ;
V_152:
F_59 ( & V_2 -> V_191 ) ;
return V_20 ;
}
static void F_197 ( struct V_17 * V_18 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_58 * V_418 = ( V_58 * ) V_417 -> V_362 ;
struct V_224 * V_206 = & V_2 -> V_9 [ * V_418 ] ;
F_53 ( & V_2 -> V_191 ) ;
F_102 ( V_2 , V_206 ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static void F_198 ( struct V_17 * V_18 ,
struct V_416 * V_417 ,
T_3 V_255 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_58 * V_418 = ( V_58 * ) V_417 -> V_362 ;
struct V_224 * V_206 = & V_2 -> V_9 [ * V_418 ] ;
if ( F_133 ( ( V_206 -> V_7 > 1 ) &&
( V_255 & ~ ( V_422 |
V_423 |
V_424 |
V_425 ) ) ,
L_40 ,
V_206 -> V_7 , V_255 ) )
return;
F_53 ( & V_2 -> V_191 ) ;
F_192 ( V_2 , V_206 , & V_417 -> V_419 ,
V_417 -> V_420 ,
V_417 -> V_421 ) ;
F_135 ( V_2 ) ;
F_59 ( & V_2 -> V_191 ) ;
}
static int F_199 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_58 * V_418 = ( V_58 * ) V_417 -> V_362 ;
struct V_224 * V_206 = & V_2 -> V_9 [ * V_418 ] ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
int V_20 ;
F_53 ( & V_2 -> V_191 ) ;
V_200 -> V_206 = V_206 ;
switch ( V_177 -> type ) {
case V_63 :
case V_67 :
V_20 = 0 ;
goto V_232;
case V_61 :
case V_426 :
break;
default:
V_20 = - V_193 ;
goto V_232;
}
V_20 = F_99 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_232;
F_96 ( V_2 , V_177 ) ;
if ( V_177 -> type == V_426 ) {
V_200 -> V_427 = true ;
V_20 = F_77 ( V_2 , V_177 ) ;
if ( V_20 )
goto V_428;
}
goto V_232;
V_428:
F_101 ( V_2 , V_177 ) ;
F_96 ( V_2 , V_177 ) ;
V_232:
F_59 ( & V_2 -> V_191 ) ;
if ( V_20 )
V_200 -> V_206 = NULL ;
return V_20 ;
}
static void F_200 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_200 = F_61 ( V_177 ) ;
F_53 ( & V_2 -> V_191 ) ;
F_137 ( V_2 , V_200 , & V_200 -> V_205 ) ;
switch ( V_177 -> type ) {
case V_63 :
case V_67 :
goto V_232;
case V_426 :
V_200 -> V_427 = false ;
F_77 ( V_2 , NULL ) ;
break;
default:
break;
}
F_101 ( V_2 , V_177 ) ;
F_96 ( V_2 , V_177 ) ;
V_232:
V_200 -> V_206 = NULL ;
F_59 ( & V_2 -> V_191 ) ;
}
static int F_201 ( struct V_17 * V_18 ,
struct V_143 * V_144 ,
bool V_429 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_54 * V_361 = ( void * ) V_144 -> V_362 ;
if ( ! V_361 || ! V_361 -> V_177 ) {
F_78 ( V_2 , L_41 ) ;
return - V_193 ;
}
return F_142 ( V_2 , V_361 -> V_177 ) ;
}
static int F_202 ( struct V_1 * V_2 ,
struct V_176 * V_177 ,
void * V_164 , int V_120 )
{
struct V_430 * V_431 [ V_432 + 1 ] ;
int V_389 ;
T_3 V_254 ;
V_389 = F_203 ( V_431 , V_432 , V_164 , V_120 , V_433 ) ;
if ( V_389 )
return V_389 ;
if ( ! V_431 [ V_434 ] )
return - V_193 ;
switch ( F_204 ( V_431 [ V_434 ] ) ) {
case V_435 :
if ( ! V_177 || V_177 -> type != V_63 || ! V_177 -> V_238 ||
! V_177 -> V_263 . V_436 ||
! V_431 [ V_437 ] )
return - V_193 ;
V_254 = F_204 ( V_431 [ V_437 ] ) ;
if ( V_254 >= V_177 -> V_263 . V_316 )
return - V_193 ;
V_2 -> V_254 = V_254 ;
V_2 -> V_253 = V_177 ;
return F_77 ( V_2 , NULL ) ;
case V_438 :
if ( ! V_177 || V_177 -> type != V_61 ||
! V_177 -> V_263 . V_264 || ! V_177 -> V_263 . V_375 ||
! V_431 [ V_439 ] )
return - V_193 ;
if ( F_204 ( V_431 [ V_439 ] ) )
return F_138 ( V_2 , V_177 ,
V_231 ) ;
return F_97 ( V_2 , V_177 , V_231 ) ;
}
return - V_393 ;
}
static int F_205 ( struct V_17 * V_18 ,
struct V_176 * V_177 ,
void * V_164 , int V_120 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_389 ;
F_53 ( & V_2 -> V_191 ) ;
V_389 = F_202 ( V_2 , V_177 , V_164 , V_120 ) ;
F_59 ( & V_2 -> V_191 ) ;
return V_389 ;
}
