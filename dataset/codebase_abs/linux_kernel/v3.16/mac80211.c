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
if ( V_2 -> V_12 -> V_13 . V_14 & V_47 &&
F_16 ( V_2 -> V_12 -> V_48 ) >= 9 &&
! V_44 . V_49 ) {
V_18 -> V_14 |= V_50 ;
V_18 -> V_51 = V_52 ;
V_18 -> V_53 = V_54 ;
}
V_18 -> V_55 = sizeof( struct V_56 ) ;
V_18 -> V_57 = sizeof( struct V_58 ) ;
V_18 -> V_59 = sizeof( V_60 ) ;
V_18 -> V_61 -> V_62 = F_17 ( V_63 ) |
F_17 ( V_64 ) |
F_17 ( V_65 ) |
F_17 ( V_66 ) |
F_17 ( V_67 ) |
F_17 ( V_68 ) ;
V_18 -> V_61 -> V_14 |= V_69 ;
V_18 -> V_61 -> V_70 |= V_71 |
V_72 ;
if ( V_2 -> V_12 -> V_13 . V_14 & V_73 )
V_18 -> V_61 -> V_14 |= V_74 ;
if ( V_2 -> V_12 -> V_13 . V_75 [ 0 ] & V_76 )
V_18 -> V_61 -> V_14 |= V_77 ;
V_18 -> V_61 -> V_78 = V_79 ;
V_18 -> V_61 -> V_80 =
F_18 ( V_79 ) ;
V_18 -> V_61 -> V_81 = 10000 ;
V_18 -> V_82 = V_83 ;
memcpy ( V_2 -> V_84 [ 0 ] . V_85 , V_2 -> V_86 -> V_87 , V_88 ) ;
V_18 -> V_61 -> V_84 = V_2 -> V_84 ;
V_18 -> V_61 -> V_89 = 1 ;
V_19 = ( V_2 -> V_86 -> V_90 > 1 ) ?
F_19 ( V_91 , V_2 -> V_86 -> V_90 ) : 1 ;
for ( V_8 = 1 ; V_8 < V_19 ; V_8 ++ ) {
memcpy ( V_2 -> V_84 [ V_8 ] . V_85 , V_2 -> V_84 [ V_8 - 1 ] . V_85 ,
V_88 ) ;
V_2 -> V_84 [ V_8 ] . V_85 [ 5 ] ++ ;
V_18 -> V_61 -> V_89 ++ ;
}
F_13 ( V_2 ) ;
V_18 -> V_61 -> V_92 = F_14 ( V_2 ) ;
V_18 -> V_61 -> V_93 = V_94 ;
if ( V_2 -> V_86 -> V_95 [ V_96 ] . V_97 )
V_18 -> V_61 -> V_95 [ V_96 ] =
& V_2 -> V_86 -> V_95 [ V_96 ] ;
if ( V_2 -> V_86 -> V_95 [ V_98 ] . V_97 )
V_18 -> V_61 -> V_95 [ V_98 ] =
& V_2 -> V_86 -> V_95 [ V_98 ] ;
V_18 -> V_61 -> V_99 = V_2 -> V_6 -> V_100 ;
if ( V_101 . V_102 != V_103 )
V_18 -> V_61 -> V_14 |= V_104 ;
else
V_18 -> V_61 -> V_14 &= ~ V_104 ;
V_18 -> V_61 -> V_14 |= V_105 ;
V_18 -> V_61 -> V_106 = V_94 ;
V_18 -> V_61 -> V_107 = V_108 ;
V_18 -> V_61 -> V_109 = V_110 - 24 - 2 ;
V_18 -> V_61 -> V_111 |= V_112 |
V_113 ;
V_2 -> V_114 = V_115 ;
if ( V_2 -> V_12 -> V_116 [ 0 ] . V_117 ) {
V_2 -> V_18 -> V_118 = 1 ;
V_2 -> V_18 -> V_119 = & V_2 -> V_12 -> V_116 [ 0 ] ;
}
#ifdef F_20
if ( F_2 ( V_2 ) &&
F_21 ( V_2 -> V_6 -> V_120 ) ) {
V_2 -> V_121 . V_14 = V_122 ;
V_18 -> V_61 -> V_121 = & V_2 -> V_121 ;
} else if ( V_2 -> V_12 -> V_123 [ V_124 ] . V_125 [ 0 ] . V_126 &&
V_2 -> V_6 -> V_127 -> V_128 &&
V_2 -> V_6 -> V_127 -> V_129 &&
F_21 ( V_2 -> V_6 -> V_120 ) ) {
V_2 -> V_121 . V_14 = V_130 |
V_131 |
V_132 |
V_133 ;
if ( ! V_44 . V_45 )
V_2 -> V_121 . V_14 |= V_134 |
V_135 |
V_136 ;
V_2 -> V_121 . V_137 = V_138 ;
V_2 -> V_121 . V_139 = V_140 ;
V_2 -> V_121 . V_141 = V_142 ;
V_2 -> V_121 . V_143 = & V_144 ;
V_18 -> V_61 -> V_121 = & V_2 -> V_121 ;
}
#endif
#ifdef F_22
V_2 -> V_145 = V_146 ;
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
struct V_147 * V_148 ,
struct V_149 * V_150 )
{
struct V_56 * V_151 ;
bool V_152 = false ;
if ( F_27 ( ! F_28 ( V_153 , & V_2 -> V_154 ) ) )
return false ;
F_29 ( & V_2 -> V_155 ) ;
if ( ! F_28 ( V_153 , & V_2 -> V_154 ) )
goto V_156;
V_151 = F_30 ( V_148 ) ;
if ( V_151 -> V_157 == V_158 ||
V_151 -> V_157 != V_2 -> V_159 )
goto V_156;
F_31 ( & V_2 -> V_160 , V_150 ) ;
F_32 ( V_2 -> V_18 ) ;
F_1 ( V_2 , V_161 ) ;
F_7 ( V_2 , V_161 ) ;
V_152 = true ;
V_156:
F_33 ( & V_2 -> V_155 ) ;
return V_152 ;
}
static void F_34 ( struct V_17 * V_18 ,
struct V_162 * V_163 ,
struct V_149 * V_150 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_147 * V_148 = V_163 -> V_148 ;
struct V_164 * V_165 = F_36 ( V_150 ) ;
struct V_166 * V_167 = ( void * ) V_150 -> V_168 ;
if ( F_37 ( V_2 ) ) {
F_38 ( V_2 , L_5 ) ;
goto V_169;
}
if ( F_36 ( V_150 ) -> V_170 == V_36 &&
! F_28 ( V_171 , & V_2 -> V_154 ) )
goto V_169;
if ( F_39 ( V_165 -> V_14 & V_172 &&
F_40 ( V_167 -> V_173 ) &&
! F_41 ( V_167 -> V_173 ) &&
! F_42 ( V_167 -> V_173 ) &&
! F_43 ( V_167 -> V_173 ) ) )
V_148 = NULL ;
if ( V_148 ) {
if ( F_26 ( V_2 , V_148 , V_150 ) )
return;
if ( F_44 ( V_2 , V_150 , V_148 ) )
goto V_169;
return;
}
if ( F_45 ( V_2 , V_150 ) )
goto V_169;
return;
V_169:
F_46 ( V_18 , V_150 ) ;
}
static inline bool F_47 ( const struct V_174 * V_175 )
{
if ( V_44 . V_176 & V_177 )
return false ;
return true ;
}
static inline bool F_48 ( const struct V_174 * V_175 )
{
if ( V_44 . V_176 & V_178 )
return false ;
if ( V_44 . V_176 & V_179 )
return true ;
return true ;
}
static int F_49 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
enum V_182 V_183 ,
struct V_147 * V_148 , V_60 V_184 ,
V_60 * V_185 , T_1 V_186 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
bool V_187 = false ;
F_50 ( V_2 , L_6 ,
V_148 -> V_85 , V_184 , V_183 ) ;
if ( ! ( V_2 -> V_86 -> V_188 ) )
return - V_189 ;
switch ( V_183 ) {
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
F_1 ( V_2 , V_195 ) ;
V_187 = true ;
if ( ! F_51 ( V_2 -> V_196 ,
! F_28 ( V_153 , & V_2 -> V_154 ) , V_197 ) ) {
F_52 ( 1 ) ;
F_7 ( V_2 , V_195 ) ;
return - V_198 ;
}
break;
default:
break;
}
F_53 ( & V_2 -> V_199 ) ;
switch ( V_183 ) {
case V_200 :
if ( ! F_47 ( V_2 -> V_175 ) ) {
V_20 = - V_201 ;
break;
}
V_20 = F_54 ( V_2 , V_148 , V_184 , * V_185 , true ) ;
break;
case V_202 :
V_20 = F_54 ( V_2 , V_148 , V_184 , 0 , false ) ;
break;
case V_190 :
if ( ! F_48 ( V_2 -> V_175 ) ) {
V_20 = - V_201 ;
break;
}
V_20 = F_55 ( V_2 , V_181 , V_148 , V_184 , V_185 ) ;
break;
case V_191 :
V_20 = F_56 ( V_2 , V_181 , V_148 , V_184 ) ;
break;
case V_192 :
case V_193 :
V_20 = F_57 ( V_2 , V_181 , V_148 , V_184 ) ;
break;
case V_194 :
V_20 = F_58 ( V_2 , V_181 , V_148 , V_184 , V_186 ) ;
break;
default:
F_52 ( 1 ) ;
V_20 = - V_201 ;
break;
}
F_59 ( & V_2 -> V_199 ) ;
if ( V_187 )
F_7 ( V_2 , V_195 ) ;
return V_20 ;
}
static void F_60 ( void * V_168 , T_1 * V_203 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = V_168 ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
V_204 -> V_205 = false ;
V_204 -> V_206 = V_158 ;
V_204 -> V_207 ++ ;
F_62 ( & V_2 -> V_208 ) ;
F_63 ( V_2 , & V_204 -> V_209 ) ;
F_64 ( & V_2 -> V_208 ) ;
V_204 -> V_210 = NULL ;
}
static void F_65 ( struct V_1 * V_2 )
{
#ifdef F_66
static char * V_211 [] = { L_7 , L_8 , NULL } ;
F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_18 -> V_61 -> V_120 . V_212 , V_213 , V_211 ) ;
#endif
F_69 ( V_2 -> V_6 ) ;
V_2 -> V_214 = V_215 ;
F_70 ( V_2 -> V_18 ) ;
F_71 (
V_2 -> V_18 , V_216 ,
F_60 , V_2 ) ;
V_2 -> V_217 = NULL ;
V_2 -> V_159 = V_158 ;
F_13 ( V_2 ) ;
memset ( V_2 -> V_218 , 0 , sizeof( V_2 -> V_218 ) ) ;
memset ( V_2 -> V_219 , 0 , sizeof( V_2 -> V_219 ) ) ;
F_72 ( V_2 -> V_18 ) ;
F_10 ( V_2 , V_220 ) ;
V_2 -> V_221 = 0 ;
V_2 -> V_222 = 0 ;
}
static int F_73 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
if ( F_28 ( V_223 , & V_2 -> V_154 ) )
F_65 ( V_2 ) ;
V_20 = F_74 ( V_2 ) ;
F_59 ( & V_2 -> V_199 ) ;
return V_20 ;
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
F_12 ( V_223 , & V_2 -> V_154 ) ;
F_76 ( V_2 , NULL ) ;
V_20 = F_77 ( V_2 , NULL ) ;
if ( V_20 )
F_78 ( V_2 , L_9 ,
V_20 ) ;
F_7 ( V_2 , V_220 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static void F_79 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_80 ( & V_2 -> V_224 ) ;
F_80 ( & V_2 -> V_225 ) ;
F_53 ( & V_2 -> V_199 ) ;
F_1 ( V_2 , V_220 ) ;
F_81 ( & V_2 -> V_226 ) ;
F_69 ( V_2 -> V_6 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 , & V_2 -> V_227 ) ;
F_59 ( & V_2 -> V_199 ) ;
F_81 ( & V_2 -> V_225 ) ;
}
static struct V_228 * F_84 ( struct V_1 * V_2 )
{
V_60 V_8 ;
F_85 ( & V_2 -> V_199 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
if ( ! V_2 -> V_9 [ V_8 ] . V_7 )
return & V_2 -> V_9 [ V_8 ] ;
F_78 ( V_2 , L_10 ) ;
return NULL ;
}
static int F_86 ( struct V_1 * V_2 , struct V_180 * V_181 ,
T_2 V_229 )
{
struct V_230 V_231 = {
. V_232 = F_61 ( V_181 ) -> V_11 ,
. V_233 = F_87 ( V_229 ) ,
} ;
return F_88 ( V_2 , V_234 , 0 ,
sizeof( V_231 ) ,
& V_231 ) ;
}
static int F_89 ( struct V_17 * V_18 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
V_20 = F_90 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_235;
if ( V_181 -> type != V_67 )
V_2 -> V_221 ++ ;
if ( V_181 -> type == V_65 ||
V_181 -> type == V_68 ) {
T_3 V_236 = F_91 ( V_2 , V_181 ) ;
V_20 = F_92 ( V_2 , & V_204 -> V_237 ,
V_236 ,
F_93 ( V_181 ) ) ;
if ( V_20 ) {
F_78 ( V_2 , L_11 ) ;
goto V_238;
}
F_94 ( V_2 , V_181 ) ;
goto V_235;
}
V_20 = F_95 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_238;
V_20 = F_96 ( V_2 ) ;
if ( V_20 )
goto V_238;
V_20 = F_97 ( V_2 , V_181 , 0 ) ;
if ( V_20 )
goto V_239;
if ( ! V_2 -> V_240 &&
V_181 -> type == V_63 && ! V_181 -> V_241 ) {
V_2 -> V_240 = V_204 ;
V_181 -> V_242 |= V_243 |
V_244 ;
}
if ( V_181 -> type == V_67 ) {
V_204 -> V_210 = F_84 ( V_2 ) ;
if ( ! V_204 -> V_210 ) {
V_20 = - V_245 ;
goto V_246;
}
F_98 ( V_2 , V_204 -> V_210 ) ;
V_20 = F_99 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_247;
V_20 = F_100 ( V_2 , V_181 , & V_204 -> V_237 ) ;
if ( V_20 )
goto V_248;
V_2 -> V_217 = V_181 ;
}
F_94 ( V_2 , V_181 ) ;
goto V_235;
V_248:
F_101 ( V_2 , V_181 ) ;
V_247:
F_102 ( V_2 , V_204 -> V_210 ) ;
V_246:
if ( V_2 -> V_240 == V_204 ) {
V_2 -> V_240 = NULL ;
V_181 -> V_242 &= ~ ( V_243 |
V_244 ) ;
}
V_239:
V_204 -> V_210 = NULL ;
F_103 ( V_2 , V_181 ) ;
V_238:
if ( V_181 -> type != V_67 )
V_2 -> V_221 -- ;
F_104 ( V_2 , V_181 ) ;
V_235:
F_59 ( & V_2 -> V_199 ) ;
return V_20 ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
T_3 V_249 = 0 , V_250 ;
for ( V_250 = 0 ; V_250 < V_251 ; V_250 ++ )
if ( V_181 -> V_170 [ V_250 ] != V_252 )
V_249 |= F_17 ( V_181 -> V_170 [ V_250 ] ) ;
if ( V_181 -> V_253 != V_252 )
V_249 |= F_17 ( V_181 -> V_253 ) ;
if ( V_249 ) {
F_53 ( & V_2 -> V_199 ) ;
F_106 ( V_2 , V_249 , true ) ;
F_59 ( & V_2 -> V_199 ) ;
}
if ( V_181 -> type == V_67 ) {
F_80 ( & V_2 -> V_226 ) ;
} else {
F_80 ( & V_2 -> V_254 ) ;
}
}
static void F_107 ( struct V_17 * V_18 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
F_105 ( V_2 , V_181 ) ;
F_53 ( & V_2 -> V_199 ) ;
if ( V_2 -> V_240 == V_204 ) {
V_2 -> V_240 = NULL ;
V_181 -> V_242 &= ~ ( V_243 |
V_244 ) ;
}
F_108 ( V_2 , V_181 ) ;
if ( V_181 -> type == V_65 ||
V_181 -> type == V_68 ) {
#ifdef F_109
if ( V_181 == V_2 -> V_255 ) {
V_2 -> V_255 = NULL ;
V_2 -> V_256 = 0 ;
}
#endif
F_83 ( V_2 , & V_204 -> V_237 ) ;
goto V_238;
}
if ( V_181 -> type == V_67 ) {
V_2 -> V_217 = NULL ;
F_110 ( V_2 , & V_204 -> V_237 ) ;
F_101 ( V_2 , V_181 ) ;
F_102 ( V_2 , V_204 -> V_210 ) ;
V_204 -> V_210 = NULL ;
}
if ( V_2 -> V_221 && V_181 -> type != V_67 )
V_2 -> V_221 -- ;
F_96 ( V_2 ) ;
F_103 ( V_2 , V_181 ) ;
V_238:
F_104 ( V_2 , V_181 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static int F_111 ( struct V_17 * V_18 , T_3 V_257 )
{
return 0 ;
}
static void F_112 ( void * V_258 , T_1 * V_203 ,
struct V_180 * V_181 )
{
struct V_259 * V_168 = V_258 ;
struct V_1 * V_2 = V_168 -> V_2 ;
struct V_260 * V_261 = V_2 -> V_262 ;
int V_20 , V_126 ;
if ( F_52 ( V_168 -> V_263 >= V_264 ) )
return;
if ( V_181 -> type != V_63 ||
! V_181 -> V_265 . V_266 )
return;
V_261 -> V_263 = V_168 -> V_263 ++ ;
memcpy ( V_261 -> V_267 , V_181 -> V_265 . V_267 , V_88 ) ;
V_126 = F_113 ( sizeof( * V_261 ) + V_261 -> V_268 * V_88 , 4 ) ;
V_20 = F_88 ( V_2 , V_269 , V_270 , V_126 , V_261 ) ;
if ( V_20 )
F_78 ( V_2 , L_12 , V_20 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_259 V_271 = {
. V_2 = V_2 ,
} ;
F_85 ( & V_2 -> V_199 ) ;
if ( F_52 ( ! V_2 -> V_262 ) )
return;
F_71 (
V_2 -> V_18 , V_272 ,
F_112 , & V_271 ) ;
}
static T_4 F_115 ( struct V_17 * V_18 ,
struct V_273 * V_274 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_260 * V_261 ;
struct V_275 * V_85 ;
int V_276 = F_116 ( V_274 ) ;
bool V_277 = false ;
int V_126 ;
if ( V_276 > V_278 ) {
V_277 = true ;
V_276 = 0 ;
}
V_126 = F_113 ( sizeof( * V_261 ) + V_276 * V_88 , 4 ) ;
V_261 = F_117 ( V_126 , V_279 ) ;
if ( ! V_261 )
return 0 ;
if ( V_277 ) {
V_261 -> V_277 = 1 ;
return ( T_4 ) ( unsigned long ) V_261 ;
}
F_118 (addr, mc_list) {
F_119 ( V_2 , L_13 ,
V_261 -> V_268 , V_85 -> V_85 ) ;
memcpy ( & V_261 -> V_280 [ V_261 -> V_268 * V_88 ] ,
V_85 -> V_85 , V_88 ) ;
V_261 -> V_268 ++ ;
}
return ( T_4 ) ( unsigned long ) V_261 ;
}
static void F_120 ( struct V_17 * V_18 ,
unsigned int V_281 ,
unsigned int * V_282 ,
T_4 V_283 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_260 * V_261 = ( void * ) ( unsigned long ) V_283 ;
F_53 ( & V_2 -> V_199 ) ;
F_121 ( V_2 -> V_262 ) ;
V_2 -> V_262 = V_261 ;
if ( ! V_261 )
goto V_156;
F_114 ( V_2 ) ;
V_156:
F_59 ( & V_2 -> V_199 ) ;
* V_282 = 0 ;
}
static void
F_122 ( struct V_180 * V_181 ,
const struct V_284 * V_285 ,
struct V_284 * V_286 )
{
struct V_287 * V_288 ;
int V_8 ;
memcpy ( V_286 , V_285 , sizeof( * V_286 ) ) ;
for ( V_8 = 0 ; V_8 < F_18 ( V_286 -> V_289 ) ; V_8 ++ ) {
V_288 = & V_286 -> V_289 [ V_8 ] ;
if ( ! V_288 -> V_290 )
break;
switch ( V_288 -> V_291 ) {
case F_87 ( V_292 ) :
if ( V_181 -> V_265 . V_293 != 1 ) {
V_288 -> V_290 = 0 ;
continue;
}
V_288 -> V_294 = V_181 -> V_265 . V_295 [ 0 ] ;
break;
case F_87 ( V_296 ) :
V_288 -> V_294 = * ( V_297 * ) & V_181 -> V_85 [ 2 ] ;
break;
default:
break;
}
V_288 -> V_291 = 0 ;
V_286 -> V_298 ++ ;
}
}
static void F_123 ( void * V_258 , T_1 * V_203 ,
struct V_180 * V_181 )
{
struct V_299 * V_168 = V_258 ;
struct V_1 * V_2 = V_168 -> V_2 ;
struct V_300 * V_261 = V_168 -> V_261 ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
struct V_301 * V_302 ;
int V_8 ;
if ( F_4 ( V_204 -> V_11 >= F_18 ( V_261 -> V_303 ) ) )
return;
V_302 = & V_261 -> V_303 [ V_204 -> V_11 ] ;
if ( V_181 -> type != V_63 || V_181 -> V_241 ||
! V_181 -> V_265 . V_266 )
return;
V_302 -> V_304 = 1 ;
for ( V_8 = 0 ; V_2 -> V_145 [ V_8 ] . V_289 [ 0 ] . V_290 ; V_8 ++ ) {
if ( F_52 ( V_168 -> V_305 >=
F_18 ( V_261 -> V_306 ) ) ) {
V_302 -> V_304 = 0 ;
V_302 -> V_307 = 0 ;
break;
}
F_122 ( V_181 ,
& V_2 -> V_145 [ V_8 ] ,
& V_261 -> V_306 [ V_168 -> V_305 ] ) ;
if ( ! V_261 -> V_306 [ V_168 -> V_305 ] . V_298 )
continue;
V_302 -> V_307 |=
F_87 ( F_17 ( V_168 -> V_305 ) ) ;
V_168 -> V_305 ++ ;
}
}
bool F_124 ( struct V_1 * V_2 ,
struct V_300 * V_261 )
{
struct V_299 V_271 = {
. V_2 = V_2 ,
. V_261 = V_261 ,
} ;
memset ( V_261 , 0 , sizeof( * V_261 ) ) ;
V_261 -> V_308 = F_18 ( V_261 -> V_306 ) ;
V_261 -> V_309 = F_18 ( V_261 -> V_303 ) ;
#ifdef F_66
if ( V_2 -> V_310 . V_311 ) {
memcpy ( V_261 -> V_306 , & V_2 -> V_310 . V_261 . V_306 ,
sizeof( V_261 -> V_306 ) ) ;
memcpy ( V_261 -> V_303 , & V_2 -> V_310 . V_261 . V_303 ,
sizeof( V_261 -> V_303 ) ) ;
return true ;
}
#endif
if ( ! V_2 -> V_145 )
return false ;
F_125 (
V_2 -> V_18 , V_272 ,
F_123 , & V_271 ) ;
return true ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_300 V_261 ;
if ( ! ( V_2 -> V_12 -> V_13 . V_14 & V_312 ) )
return 0 ;
if ( ! F_124 ( V_2 , & V_261 ) )
return 0 ;
return F_88 ( V_2 , V_313 , 0 ,
sizeof( V_261 ) , & V_261 ) ;
}
static inline int F_126 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
return 0 ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_180 * V_181 ,
struct V_314 * V_265 ,
T_3 V_315 )
{
struct V_58 * V_204 = F_61 ( V_181 ) ;
int V_20 ;
if ( V_315 & V_316 && V_265 -> V_266 )
F_128 ( V_2 , V_181 ) ;
V_20 = F_129 ( V_2 , V_181 , false ) ;
if ( V_20 )
F_78 ( V_2 , L_14 , V_181 -> V_85 ) ;
if ( V_315 & V_316 ) {
if ( V_265 -> V_266 ) {
V_20 = F_77 ( V_2 , V_181 ) ;
if ( V_20 ) {
F_78 ( V_2 , L_15 ) ;
return;
}
if ( F_28 ( V_223 ,
& V_2 -> V_154 ) ) {
T_3 V_317 = ( 11 * V_181 -> V_265 . V_318 ) / 10 ;
F_130 ( V_2 , V_181 , V_317 , V_317 ,
5 * V_317 ) ;
}
F_131 ( V_2 , V_181 , false ) ;
F_132 ( V_2 , V_181 ) ;
if ( V_181 -> V_241 )
F_1 ( V_2 , V_319 ) ;
} else if ( V_204 -> V_206 != V_158 ) {
F_133 ( F_131 ( V_2 , V_181 , false ) ,
L_16 ) ;
V_20 = F_134 ( V_2 , V_181 , V_204 -> V_206 ) ;
if ( V_20 )
F_78 ( V_2 , L_17 ) ;
if ( V_2 -> V_159 == V_204 -> V_206 )
V_2 -> V_159 = V_158 ;
V_204 -> V_206 = V_158 ;
V_20 = F_77 ( V_2 , NULL ) ;
if ( V_20 )
F_78 ( V_2 , L_15 ) ;
if ( V_181 -> V_241 )
F_7 ( V_2 , V_319 ) ;
}
F_114 ( V_2 ) ;
F_126 ( V_2 , V_181 ) ;
V_204 -> V_320 . V_321 = 0 ;
F_135 ( V_2 ) ;
F_136 ( V_2 , V_181 , V_322 ,
V_323 ) ;
} else if ( V_315 & V_324 ) {
F_137 ( V_2 , V_204 ,
& V_204 -> V_209 ) ;
F_131 ( V_2 , V_181 , false ) ;
F_4 ( F_138 ( V_2 , V_181 , 0 ) ) ;
} else if ( V_315 & ( V_325 | V_326 |
V_327 ) ) {
V_20 = F_96 ( V_2 ) ;
if ( V_20 )
F_78 ( V_2 , L_18 ) ;
}
if ( V_315 & V_328 ) {
F_139 ( V_2 , L_19 ,
V_265 -> V_329 ) ;
F_86 ( V_2 , V_181 , V_265 -> V_329 ) ;
}
if ( V_315 & V_330 ) {
F_119 ( V_2 , L_20 ) ;
V_204 -> V_320 . V_331 = 0 ;
if ( V_204 -> V_320 . V_332 ) {
V_20 = F_138 ( V_2 , V_181 , 0 ) ;
if ( V_20 )
F_78 ( V_2 ,
L_21 ) ;
}
}
if ( V_315 & V_333 ) {
F_119 ( V_2 , L_22 ) ;
F_126 ( V_2 , V_181 ) ;
}
}
static int F_140 ( struct V_17 * V_18 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
V_20 = F_141 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_235;
if ( V_181 -> type == V_65 )
F_128 ( V_2 , V_181 ) ;
V_20 = F_95 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_235;
V_20 = F_99 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_334;
V_20 = F_142 ( V_2 , V_181 , & V_204 -> V_237 ) ;
if ( V_20 )
goto V_248;
V_204 -> V_335 = true ;
F_96 ( V_2 ) ;
V_20 = F_77 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_336;
if ( V_181 -> V_241 && V_2 -> V_217 )
F_129 ( V_2 , V_2 -> V_217 , false ) ;
F_1 ( V_2 , V_337 ) ;
F_135 ( V_2 ) ;
F_59 ( & V_2 -> V_199 ) ;
return 0 ;
V_336:
F_96 ( V_2 ) ;
V_204 -> V_335 = false ;
F_143 ( V_2 , & V_204 -> V_237 ) ;
V_248:
F_101 ( V_2 , V_181 ) ;
V_334:
F_103 ( V_2 , V_181 ) ;
V_235:
F_59 ( & V_2 -> V_199 ) ;
return V_20 ;
}
static void F_144 ( struct V_17 * V_18 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
F_105 ( V_2 , V_181 ) ;
F_53 ( & V_2 -> V_199 ) ;
V_204 -> V_335 = false ;
F_135 ( V_2 ) ;
F_7 ( V_2 , V_337 ) ;
if ( V_181 -> V_241 && V_2 -> V_217 )
F_129 ( V_2 , V_2 -> V_217 , false ) ;
F_77 ( V_2 , NULL ) ;
F_143 ( V_2 , & V_204 -> V_237 ) ;
F_101 ( V_2 , V_181 ) ;
F_96 ( V_2 ) ;
F_103 ( V_2 , V_181 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static void
F_145 ( struct V_1 * V_2 ,
struct V_180 * V_181 ,
struct V_314 * V_265 ,
T_3 V_315 )
{
struct V_58 * V_204 = F_61 ( V_181 ) ;
if ( ! V_204 -> V_335 )
return;
if ( V_315 & ( V_338 | V_339 |
V_340 ) &&
F_129 ( V_2 , V_181 , false ) )
F_78 ( V_2 , L_14 , V_181 -> V_85 ) ;
if ( V_315 & V_341 &&
F_141 ( V_2 , V_181 ) )
F_146 ( V_2 , L_23 ) ;
}
static void F_147 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_314 * V_265 ,
T_3 V_315 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_53 ( & V_2 -> V_199 ) ;
if ( V_315 & V_342 && ! V_265 -> V_343 )
F_148 ( V_2 , true ) ;
switch ( V_181 -> type ) {
case V_63 :
F_127 ( V_2 , V_181 , V_265 , V_315 ) ;
break;
case V_65 :
case V_68 :
F_145 ( V_2 , V_181 , V_265 , V_315 ) ;
break;
default:
F_52 ( 1 ) ;
}
F_59 ( & V_2 -> V_199 ) ;
}
static int F_149 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_344 * V_345 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
if ( V_345 -> V_97 == 0 || V_345 -> V_97 > V_346 )
return - V_201 ;
F_53 ( & V_2 -> V_199 ) ;
switch ( V_2 -> V_214 ) {
case V_347 :
V_20 = F_148 ( V_2 , true ) ;
if ( V_20 ) {
V_20 = - V_348 ;
goto V_156;
}
break;
case V_215 :
break;
default:
V_20 = - V_348 ;
goto V_156;
}
F_1 ( V_2 , V_349 ) ;
V_20 = F_150 ( V_2 , V_181 , V_345 ) ;
if ( V_20 )
F_7 ( V_2 , V_349 ) ;
V_156:
F_59 ( & V_2 -> V_199 ) ;
F_151 ( V_2 ) ;
return V_20 ;
}
static void F_152 ( struct V_17 * V_18 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_53 ( & V_2 -> V_199 ) ;
F_153 ( V_2 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static void
F_154 ( struct V_17 * V_18 ,
struct V_147 * V_148 , V_60 V_350 ,
int V_351 ,
enum V_352 V_353 ,
bool V_354 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_155 ( V_2 , V_148 , V_353 , V_351 ,
V_350 , V_354 , false ) ;
}
static void
F_156 ( struct V_17 * V_18 ,
struct V_147 * V_148 , V_60 V_350 ,
int V_351 ,
enum V_352 V_353 ,
bool V_354 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_155 ( V_2 , V_148 , V_353 , V_351 ,
V_350 , V_354 , true ) ;
}
static void F_157 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
enum V_355 V_261 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_151 = F_30 ( V_148 ) ;
int V_184 ;
switch ( V_261 ) {
case V_356 :
if ( F_158 ( & V_2 -> V_357 [ V_151 -> V_157 ] ) > 0 )
F_159 ( V_18 , V_148 , true ) ;
F_62 ( & V_151 -> V_358 ) ;
for ( V_184 = 0 ; V_184 < V_359 ; V_184 ++ ) {
struct V_360 * V_361 ;
V_361 = & V_151 -> V_361 [ V_184 ] ;
if ( V_361 -> V_362 != V_363 &&
V_361 -> V_362 != V_364 )
continue;
if ( F_160 ( V_361 ) == 0 )
continue;
F_161 ( V_148 , V_184 , true ) ;
}
F_64 ( & V_151 -> V_358 ) ;
break;
case V_365 :
if ( F_4 ( V_151 -> V_157 == V_158 ) )
break;
F_162 ( V_2 , V_148 ) ;
break;
default:
break;
}
}
static void F_163 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_366 = ( void * ) V_148 -> V_367 ;
F_53 ( & V_2 -> V_199 ) ;
if ( V_148 == F_164 ( V_2 -> V_368 [ V_366 -> V_157 ] ) )
F_165 ( V_2 -> V_368 [ V_366 -> V_157 ] ,
F_166 ( - V_369 ) ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static int F_167 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_147 * V_148 ,
enum V_370 V_371 ,
enum V_370 V_372 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
int V_20 ;
F_119 ( V_2 , L_24 ,
V_148 -> V_85 , V_371 , V_372 ) ;
if ( F_52 ( ! V_204 -> V_210 ) )
return - V_201 ;
F_80 ( & V_2 -> V_254 ) ;
F_53 ( & V_2 -> V_199 ) ;
if ( V_371 == V_373 &&
V_372 == V_374 ) {
if ( V_181 -> type == V_63 &&
V_181 -> V_265 . V_318 < 16 ) {
F_78 ( V_2 ,
L_25 ,
V_148 -> V_85 , V_181 -> V_265 . V_318 ) ;
V_20 = - V_201 ;
goto V_235;
}
V_20 = F_168 ( V_2 , V_181 , V_148 ) ;
} else if ( V_371 == V_374 &&
V_372 == V_375 ) {
V_2 -> V_376 = true ;
V_20 = 0 ;
} else if ( V_371 == V_375 &&
V_372 == V_377 ) {
V_20 = F_169 ( V_2 , V_181 , V_148 ) ;
if ( V_20 == 0 )
F_170 ( V_2 , V_148 ,
V_204 -> V_210 -> V_378 -> V_379 ,
true ) ;
} else if ( V_371 == V_377 &&
V_372 == V_380 ) {
F_4 ( F_138 ( V_2 , V_181 , 0 ) ) ;
V_20 = 0 ;
} else if ( V_371 == V_380 &&
V_372 == V_377 ) {
F_4 ( F_97 ( V_2 , V_181 , 0 ) ) ;
V_20 = 0 ;
} else if ( V_371 == V_377 &&
V_372 == V_375 ) {
V_20 = 0 ;
} else if ( V_371 == V_375 &&
V_372 == V_374 ) {
V_20 = 0 ;
} else if ( V_371 == V_374 &&
V_372 == V_373 ) {
V_20 = F_171 ( V_2 , V_181 , V_148 ) ;
} else {
V_20 = - V_198 ;
}
V_235:
F_59 ( & V_2 -> V_199 ) ;
return V_20 ;
}
static int F_172 ( struct V_17 * V_18 , T_3 V_381 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_2 -> V_114 = V_381 ;
return 0 ;
}
static void F_173 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_147 * V_148 , T_3 V_257 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
if ( V_181 -> type == V_63 &&
V_257 & V_382 )
F_131 ( V_2 , V_181 , false ) ;
}
static int F_174 ( struct V_17 * V_18 ,
struct V_180 * V_181 , V_60 V_250 ,
const struct V_383 * V_384 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
V_204 -> V_385 [ V_250 ] = * V_384 ;
if ( V_181 -> type == V_67 ) {
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
V_20 = F_129 ( V_2 , V_181 , false ) ;
F_59 ( & V_2 -> V_199 ) ;
return V_20 ;
}
return 0 ;
}
static void F_175 ( struct V_17 * V_18 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
T_3 V_386 = F_19 ( V_387 ,
200 + V_181 -> V_265 . V_318 ) ;
T_3 V_388 = F_19 ( V_389 ,
100 + V_181 -> V_265 . V_318 ) ;
if ( F_52 ( V_181 -> V_265 . V_266 ) )
return;
F_53 ( & V_2 -> V_199 ) ;
F_130 ( V_2 , V_181 , V_386 , V_388 , 500 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static int F_176 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_390 * V_345 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
if ( ! F_177 ( V_2 ) ) {
V_20 = - V_348 ;
goto V_156;
}
switch ( V_2 -> V_214 ) {
case V_393 :
F_178 ( V_2 , L_26 ) ;
V_20 = F_153 ( V_2 ) ;
if ( V_20 ) {
V_20 = - V_348 ;
goto V_156;
}
break;
case V_215 :
break;
default:
V_20 = - V_348 ;
goto V_156;
}
V_2 -> V_214 = V_347 ;
V_20 = F_179 ( V_2 , V_181 , V_345 , V_392 ) ;
if ( V_20 )
goto V_394;
V_20 = F_180 ( V_2 , V_345 ) ;
if ( V_20 )
goto V_394;
V_20 = F_181 ( V_2 , V_345 ) ;
if ( ! V_20 )
goto V_156;
V_394:
V_2 -> V_214 = V_215 ;
V_156:
F_59 ( & V_2 -> V_199 ) ;
F_151 ( V_2 ) ;
return V_20 ;
}
static int F_182 ( struct V_17 * V_18 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
V_20 = F_148 ( V_2 , false ) ;
F_59 ( & V_2 -> V_199 ) ;
F_151 ( V_2 ) ;
return V_20 ;
}
static int F_183 ( struct V_17 * V_18 ,
enum V_395 V_261 ,
struct V_180 * V_181 ,
struct V_147 * V_148 ,
struct V_396 * V_397 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_20 ;
if ( V_44 . V_45 ) {
F_119 ( V_2 , L_27 ) ;
return - V_398 ;
}
switch ( V_397 -> V_117 ) {
case V_399 :
V_397 -> V_14 |= V_400 ;
case V_401 :
V_397 -> V_14 |= V_402 ;
break;
case V_403 :
F_52 ( ! ( V_18 -> V_14 & V_46 ) ) ;
break;
case V_404 :
case V_405 :
return 0 ;
default:
if ( V_18 -> V_118 &&
V_18 -> V_119 -> V_117 == V_397 -> V_117 )
V_397 -> V_14 |= V_406 ;
else
return - V_398 ;
}
F_53 ( & V_2 -> V_199 ) ;
switch ( V_261 ) {
case V_407 :
if ( ( V_181 -> type == V_68 ||
V_181 -> type == V_65 ) && ! V_148 ) {
V_20 = 0 ;
V_397 -> V_408 = V_409 ;
break;
}
F_119 ( V_2 , L_28 ) ;
V_20 = F_184 ( V_2 , V_181 , V_148 , V_397 , false ) ;
if ( V_20 ) {
F_146 ( V_2 , L_29 ) ;
V_397 -> V_408 = V_409 ;
V_20 = 0 ;
}
break;
case V_410 :
if ( V_397 -> V_408 == V_409 ) {
V_20 = 0 ;
break;
}
F_119 ( V_2 , L_30 ) ;
V_20 = F_185 ( V_2 , V_181 , V_148 , V_397 ) ;
break;
default:
V_20 = - V_201 ;
}
F_59 ( & V_2 -> V_199 ) ;
return V_20 ;
}
static void F_186 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_396 * V_411 ,
struct V_147 * V_148 ,
T_3 V_412 , V_60 * V_413 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
if ( V_411 -> V_408 == V_409 )
return;
F_187 ( V_2 , V_181 , V_411 , V_148 , V_412 , V_413 ) ;
}
static int F_188 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_414 * V_378 ,
int V_386 ,
enum V_415 type )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
struct V_416 V_417 ;
struct V_228 * V_210 ;
int V_20 , V_8 ;
F_119 ( V_2 , L_31 , V_378 -> V_418 ,
V_386 , type ) ;
if ( V_181 -> type != V_67 ) {
F_78 ( V_2 , L_32 , V_181 -> type ) ;
return - V_201 ;
}
F_53 ( & V_2 -> V_199 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_210 = & V_2 -> V_9 [ V_8 ] ;
if ( V_210 -> V_7 == 0 || V_204 -> V_210 == V_210 )
continue;
if ( V_210 -> V_7 && V_378 == V_210 -> V_378 ) {
V_20 = F_101 ( V_2 , V_181 ) ;
if ( F_189 ( V_20 , L_33 ) )
goto V_235;
F_102 ( V_2 , V_204 -> V_210 ) ;
V_204 -> V_210 = V_210 ;
V_20 = F_99 ( V_2 , V_181 ) ;
if ( F_189 ( V_20 , L_34 ) )
goto V_235;
F_98 ( V_2 , V_204 -> V_210 ) ;
goto V_419;
}
}
if ( V_378 == V_204 -> V_210 -> V_378 )
goto V_419;
F_190 ( & V_417 , V_378 , V_420 ) ;
if ( V_204 -> V_210 -> V_7 == 1 ) {
V_20 = F_191 ( V_2 , V_204 -> V_210 ,
& V_417 , 1 , 1 ) ;
if ( V_20 )
goto V_235;
} else {
V_210 = F_84 ( V_2 ) ;
if ( ! V_210 ) {
V_20 = - V_245 ;
goto V_235;
}
V_20 = F_191 ( V_2 , V_210 , & V_417 ,
1 , 1 ) ;
if ( V_20 ) {
F_78 ( V_2 , L_35 ) ;
goto V_235;
}
V_20 = F_101 ( V_2 , V_181 ) ;
if ( F_189 ( V_20 , L_33 ) )
goto V_235;
F_102 ( V_2 , V_204 -> V_210 ) ;
V_204 -> V_210 = V_210 ;
V_20 = F_99 ( V_2 , V_181 ) ;
if ( F_189 ( V_20 , L_34 ) )
goto V_235;
F_98 ( V_2 , V_204 -> V_210 ) ;
}
V_419:
V_20 = F_192 ( V_2 , V_181 , V_386 , type ) ;
V_235:
F_59 ( & V_2 -> V_199 ) ;
F_119 ( V_2 , L_36 ) ;
return V_20 ;
}
static int F_193 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_119 ( V_2 , L_37 ) ;
F_53 ( & V_2 -> V_199 ) ;
F_194 ( V_2 ) ;
F_59 ( & V_2 -> V_199 ) ;
F_119 ( V_2 , L_36 ) ;
return 0 ;
}
static int F_195 ( struct V_17 * V_18 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_60 * V_423 = ( V_60 * ) V_422 -> V_367 ;
struct V_228 * V_210 ;
int V_20 ;
F_119 ( V_2 , L_38 ) ;
F_53 ( & V_2 -> V_199 ) ;
V_210 = F_84 ( V_2 ) ;
if ( ! V_210 ) {
V_20 = - V_245 ;
goto V_156;
}
V_20 = F_191 ( V_2 , V_210 , & V_422 -> V_424 ,
V_422 -> V_425 ,
V_422 -> V_426 ) ;
if ( V_20 ) {
F_78 ( V_2 , L_39 ) ;
goto V_156;
}
F_98 ( V_2 , V_210 ) ;
* V_423 = V_210 -> V_11 ;
V_156:
F_59 ( & V_2 -> V_199 ) ;
return V_20 ;
}
static void F_196 ( struct V_17 * V_18 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_60 * V_423 = ( V_60 * ) V_422 -> V_367 ;
struct V_228 * V_210 = & V_2 -> V_9 [ * V_423 ] ;
F_53 ( & V_2 -> V_199 ) ;
F_102 ( V_2 , V_210 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static void F_197 ( struct V_17 * V_18 ,
struct V_421 * V_422 ,
T_3 V_257 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_60 * V_423 = ( V_60 * ) V_422 -> V_367 ;
struct V_228 * V_210 = & V_2 -> V_9 [ * V_423 ] ;
if ( F_133 ( ( V_210 -> V_7 > 1 ) &&
( V_257 & ~ ( V_427 |
V_428 |
V_429 |
V_430 ) ) ,
L_40 ,
V_210 -> V_7 , V_257 ) )
return;
F_53 ( & V_2 -> V_199 ) ;
F_135 ( V_2 ) ;
F_191 ( V_2 , V_210 , & V_422 -> V_424 ,
V_422 -> V_425 ,
V_422 -> V_426 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static int F_198 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
V_60 * V_423 = ( V_60 * ) V_422 -> V_367 ;
struct V_228 * V_210 = & V_2 -> V_9 [ * V_423 ] ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
int V_20 ;
F_53 ( & V_2 -> V_199 ) ;
V_204 -> V_210 = V_210 ;
switch ( V_181 -> type ) {
case V_65 :
if ( V_181 -> V_431 ) {
V_204 -> V_335 = true ;
break;
}
case V_68 :
V_20 = 0 ;
goto V_235;
case V_63 :
case V_432 :
break;
default:
V_20 = - V_201 ;
goto V_235;
}
V_20 = F_99 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_235;
F_96 ( V_2 ) ;
if ( V_181 -> type == V_432 ) {
V_204 -> V_433 = true ;
V_20 = F_77 ( V_2 , V_181 ) ;
if ( V_20 )
goto V_434;
}
if ( V_181 -> type == V_65 ) {
F_77 ( V_2 , V_181 ) ;
F_129 ( V_2 , V_181 , false ) ;
}
goto V_235;
V_434:
F_101 ( V_2 , V_181 ) ;
F_96 ( V_2 ) ;
V_235:
F_59 ( & V_2 -> V_199 ) ;
if ( V_20 )
V_204 -> V_210 = NULL ;
return V_20 ;
}
static void F_199 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 = F_61 ( V_181 ) ;
F_53 ( & V_2 -> V_199 ) ;
F_137 ( V_2 , V_204 , & V_204 -> V_209 ) ;
switch ( V_181 -> type ) {
case V_68 :
goto V_235;
case V_432 :
V_204 -> V_433 = false ;
F_77 ( V_2 , NULL ) ;
break;
case V_65 :
if ( ! V_181 -> V_431 || ! V_204 -> V_335 )
goto V_235;
V_204 -> V_335 = false ;
F_77 ( V_2 , NULL ) ;
default:
break;
}
F_101 ( V_2 , V_181 ) ;
V_235:
V_204 -> V_210 = NULL ;
F_96 ( V_2 ) ;
F_59 ( & V_2 -> V_199 ) ;
}
static int F_200 ( struct V_17 * V_18 ,
struct V_147 * V_148 ,
bool V_435 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_56 * V_366 = ( void * ) V_148 -> V_367 ;
if ( ! V_366 || ! V_366 -> V_181 ) {
F_78 ( V_2 , L_41 ) ;
return - V_201 ;
}
return F_141 ( V_2 , V_366 -> V_181 ) ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_180 * V_181 ,
void * V_168 , int V_126 )
{
struct V_436 * V_437 [ V_438 + 1 ] ;
int V_394 ;
T_3 V_256 ;
V_394 = F_202 ( V_437 , V_438 , V_168 , V_126 , V_439 ) ;
if ( V_394 )
return V_394 ;
if ( ! V_437 [ V_440 ] )
return - V_201 ;
switch ( F_203 ( V_437 [ V_440 ] ) ) {
case V_441 :
if ( ! V_181 || V_181 -> type != V_65 || ! V_181 -> V_241 ||
! V_181 -> V_265 . V_442 ||
! V_437 [ V_443 ] )
return - V_201 ;
V_256 = F_203 ( V_437 [ V_443 ] ) ;
if ( V_256 >= V_181 -> V_265 . V_318 )
return - V_201 ;
V_2 -> V_256 = V_256 ;
V_2 -> V_255 = V_181 ;
return F_77 ( V_2 , NULL ) ;
case V_444 :
if ( ! V_181 || V_181 -> type != V_63 ||
! V_181 -> V_265 . V_266 || ! V_181 -> V_265 . V_445 ||
! V_437 [ V_446 ] )
return - V_201 ;
if ( F_203 ( V_437 [ V_446 ] ) )
return F_138 ( V_2 , V_181 , 0 ) ;
return F_97 ( V_2 , V_181 , 0 ) ;
}
return - V_398 ;
}
static int F_204 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
void * V_168 , int V_126 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
int V_394 ;
F_53 ( & V_2 -> V_199 ) ;
V_394 = F_201 ( V_2 , V_181 , V_168 , V_126 ) ;
F_59 ( & V_2 -> V_199 ) ;
return V_394 ;
}
static void F_205 ( struct V_17 * V_18 ,
struct V_180 * V_181 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
F_53 ( & V_2 -> V_199 ) ;
if ( F_189 ( V_2 -> V_447 && V_2 -> V_447 -> V_431 ,
L_42 ) )
goto V_235;
F_119 ( V_2 , L_43 ,
V_417 -> V_448 ) ;
V_2 -> V_447 = V_181 ;
V_235:
F_59 ( & V_2 -> V_199 ) ;
}
static void F_206 ( struct V_17 * V_18 ,
struct V_180 * V_181 , T_3 V_33 , bool V_169 )
{
struct V_1 * V_2 = F_35 ( V_18 ) ;
struct V_58 * V_204 ;
struct V_56 * V_151 ;
if ( ! V_181 || V_181 -> type != V_63 )
return;
F_53 ( & V_2 -> V_199 ) ;
V_204 = F_61 ( V_181 ) ;
V_151 = F_207 ( V_2 , V_204 -> V_206 ) ;
if ( F_52 ( ! V_151 ) )
goto V_449;
if ( V_169 ) {
if ( F_106 ( V_2 , V_151 -> V_450 , true ) )
F_78 ( V_2 , L_44 ) ;
} else {
F_208 ( V_2 -> V_6 ,
V_151 -> V_450 ) ;
}
V_449:
F_59 ( & V_2 -> V_199 ) ;
}
