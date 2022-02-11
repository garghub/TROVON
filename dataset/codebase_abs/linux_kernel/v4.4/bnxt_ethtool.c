static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_9 =
F_5 ( V_10 , F_6 ( V_4 -> V_11 ) , 1 ) ;
V_8 -> V_12 = V_4 -> V_13 / 2 ;
V_8 -> V_14 =
F_5 ( V_10 , F_6 ( V_4 -> V_15 ) , 1 ) ;
V_8 -> V_16 = V_4 -> V_17 / 2 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 = 0 ;
V_4 -> V_11 = F_8 ( V_8 -> V_9 ) ;
V_4 -> V_13 = V_8 -> V_12 * 2 ;
V_4 -> V_15 =
F_8 ( V_8 -> V_14 ) ;
V_4 -> V_17 = V_8 -> V_16 * 2 ;
if ( F_9 ( V_2 ) )
V_18 = F_10 ( V_4 ) ;
return V_18 ;
}
static int F_11 ( struct V_1 * V_2 , int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_19 ) {
case V_20 :
return V_21 * V_4 -> V_22 ;
default:
return - V_23 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 , T_2 * V_26 )
{
T_1 V_27 , V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_29 = sizeof( struct V_30 ) * V_4 -> V_22 ;
T_1 V_31 = sizeof( struct V_30 ) / 8 ;
memset ( V_26 , 0 , V_29 ) ;
if ( ! V_4 -> V_32 )
return;
for ( V_27 = 0 ; V_27 < V_4 -> V_22 ; V_27 ++ ) {
struct V_33 * V_32 = V_4 -> V_32 [ V_27 ] ;
struct V_34 * V_35 = & V_32 -> V_36 ;
T_3 * V_37 = ( T_3 * ) V_35 -> V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_31 ; V_28 ++ , V_38 ++ )
V_26 [ V_28 ] = F_13 ( V_37 [ V_38 ] ) ;
V_26 [ V_28 ++ ] = V_35 -> V_39 ;
}
}
static void F_14 ( struct V_1 * V_2 , T_1 V_40 , T_4 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_27 ;
switch ( V_40 ) {
case V_20 :
for ( V_27 = 0 ; V_27 < V_4 -> V_22 ; V_27 ++ ) {
sprintf ( V_26 , L_1 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_2 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_3 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_4 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_5 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_6 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_7 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_8 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_9 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_10 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_11 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_12 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_13 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_14 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_15 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_16 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_17 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_18 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_19 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_20 , V_27 ) ;
V_26 += V_41 ;
sprintf ( V_26 , L_21 , V_27 ) ;
V_26 += V_41 ;
}
break;
default:
F_15 ( V_4 -> V_2 , L_22 ,
V_40 ) ;
break;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_43 -> V_44 = V_45 ;
V_43 -> V_46 = V_47 ;
V_43 -> V_48 = V_49 ;
V_43 -> V_50 = V_4 -> V_51 ;
V_43 -> V_52 = V_4 -> V_53 ;
V_43 -> V_54 = V_4 -> V_55 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_43 -> V_50 > V_45 ) ||
( V_43 -> V_54 > V_49 ) ||
( V_43 -> V_54 <= V_56 ) )
return - V_57 ;
if ( F_9 ( V_2 ) )
F_18 ( V_4 , false , false ) ;
V_4 -> V_51 = V_43 -> V_50 ;
V_4 -> V_55 = V_43 -> V_54 ;
F_19 ( V_4 ) ;
if ( F_9 ( V_2 ) )
return F_20 ( V_4 , false , false ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_60 , V_61 , V_62 ;
F_22 ( V_4 , & V_60 , & V_61 ) ;
V_62 = F_23 ( V_2 ) ;
if ( V_62 > 1 )
V_61 /= V_62 ;
V_59 -> V_63 = V_60 ;
V_59 -> V_64 = V_61 ;
V_59 -> V_65 = 0 ;
V_59 -> V_66 = 0 ;
V_59 -> V_67 = V_4 -> V_68 ;
V_59 -> V_69 = V_4 -> V_70 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_60 , V_61 , V_62 ;
T_1 V_18 = 0 ;
if ( V_59 -> V_71 || V_59 -> V_72 ||
! V_59 -> V_67 || ! V_59 -> V_69 )
return - V_57 ;
F_22 ( V_4 , & V_60 , & V_61 ) ;
V_62 = F_23 ( V_2 ) ;
if ( V_62 > 1 )
V_61 /= V_62 ;
if ( V_59 -> V_67 > V_60 ||
V_59 -> V_69 > V_61 )
return - V_57 ;
if ( F_9 ( V_2 ) ) {
if ( F_25 ( V_4 ) ) {
}
V_18 = F_18 ( V_4 , true , false ) ;
if ( V_18 ) {
F_15 ( V_4 -> V_2 , L_23 ,
V_18 ) ;
return V_18 ;
}
}
V_4 -> V_68 = V_59 -> V_67 ;
V_4 -> V_70 = V_59 -> V_69 ;
V_4 -> V_73 = V_4 -> V_70 ;
if ( V_62 > 1 )
V_4 -> V_73 = V_4 -> V_70 * V_62 ;
V_4 -> V_22 = F_5 ( int , V_4 -> V_73 , V_4 -> V_68 ) ;
V_4 -> V_74 = V_4 -> V_22 ;
if ( F_9 ( V_2 ) ) {
V_18 = F_20 ( V_4 , true , false ) ;
if ( ( ! V_18 ) && F_25 ( V_4 ) ) {
}
}
return V_18 ;
}
static int F_26 ( struct V_3 * V_4 , struct V_75 * V_76 ,
T_1 * V_77 )
{
int V_27 , V_28 = 0 ;
V_76 -> V_78 = V_4 -> V_79 ;
for ( V_27 = 0 ; V_27 < V_80 ; V_27 ++ ) {
struct V_81 * V_82 ;
struct V_83 * V_84 ;
V_82 = & V_4 -> V_85 [ V_27 ] ;
F_27 () ;
F_28 (fltr, head, hash) {
if ( V_28 == V_76 -> V_86 )
break;
V_77 [ V_28 ++ ] = V_84 -> V_87 ;
}
F_29 () ;
if ( V_28 == V_76 -> V_86 )
break;
}
V_76 -> V_86 = V_28 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_75 * V_76 )
{
struct V_88 * V_89 =
(struct V_88 * ) & V_76 -> V_89 ;
struct V_83 * V_84 ;
struct V_90 * V_91 ;
int V_27 , V_18 = - V_57 ;
if ( V_89 -> V_92 < 0 || V_89 -> V_92 >= V_93 )
return V_18 ;
for ( V_27 = 0 ; V_27 < V_80 ; V_27 ++ ) {
struct V_81 * V_82 ;
V_82 = & V_4 -> V_85 [ V_27 ] ;
F_27 () ;
F_28 (fltr, head, hash) {
if ( V_84 -> V_87 == V_89 -> V_92 )
goto V_94;
}
F_29 () ;
}
return V_18 ;
V_94:
V_91 = & V_84 -> V_91 ;
if ( V_91 -> V_95 . V_96 == V_97 )
V_89 -> V_98 = V_99 ;
else if ( V_91 -> V_95 . V_96 == V_100 )
V_89 -> V_98 = V_101 ;
else
goto V_102;
V_89 -> V_103 . V_104 . V_105 = V_91 -> V_106 . V_107 . V_108 ;
V_89 -> V_109 . V_104 . V_105 = F_31 ( ~ 0 ) ;
V_89 -> V_103 . V_104 . V_110 = V_91 -> V_106 . V_107 . V_111 ;
V_89 -> V_109 . V_104 . V_110 = F_31 ( ~ 0 ) ;
V_89 -> V_103 . V_104 . V_112 = V_91 -> V_113 . V_108 ;
V_89 -> V_109 . V_104 . V_112 = F_32 ( ~ 0 ) ;
V_89 -> V_103 . V_104 . V_114 = V_91 -> V_113 . V_111 ;
V_89 -> V_109 . V_104 . V_114 = F_32 ( ~ 0 ) ;
V_89 -> V_115 = V_84 -> V_116 ;
V_18 = 0 ;
V_102:
F_29 () ;
return V_18 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_75 * V_76 ,
T_1 * V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 = 0 ;
switch ( V_76 -> V_76 ) {
case V_117 :
V_76 -> V_78 = V_4 -> V_68 ;
break;
case V_118 :
V_76 -> V_86 = V_4 -> V_79 ;
V_76 -> V_78 = V_93 ;
break;
case V_119 :
V_18 = F_26 ( V_4 , V_76 , ( T_1 * ) V_77 ) ;
break;
case V_120 :
V_18 = F_30 ( V_4 , V_76 ) ;
break;
default:
V_18 = - V_23 ;
break;
}
return V_18 ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
return V_121 ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
return V_122 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 * V_123 , T_4 * V_124 ,
T_4 * V_125 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_126 * V_127 = & V_4 -> V_128 [ 0 ] ;
int V_27 = 0 ;
if ( V_125 )
* V_125 = V_129 ;
if ( V_123 )
for ( V_27 = 0 ; V_27 < V_121 ; V_27 ++ )
V_123 [ V_27 ] = F_37 ( V_127 -> V_130 [ V_27 ] ) ;
if ( V_124 )
memcpy ( V_124 , V_127 -> V_131 , V_122 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_39 ( V_133 -> V_134 , V_135 , sizeof( V_133 -> V_134 ) ) ;
F_39 ( V_133 -> V_136 , V_137 , sizeof( V_133 -> V_136 ) ) ;
F_39 ( V_133 -> V_138 , V_4 -> V_139 , sizeof( V_133 -> V_138 ) ) ;
F_39 ( V_133 -> V_140 , F_40 ( V_4 -> V_141 ) , sizeof( V_133 -> V_140 ) ) ;
V_133 -> V_142 = V_21 * V_4 -> V_22 ;
V_133 -> V_143 = F_41 ( V_4 ) ;
V_133 -> V_144 = 0 ;
V_133 -> V_145 = 0 ;
}
static T_1 F_42 ( struct V_146 * V_147 )
{
V_10 V_148 = V_147 -> V_149 ;
T_1 V_150 = 0 ;
if ( V_148 & V_151 )
V_150 |= V_152 ;
if ( V_148 & V_153 )
V_150 |= V_154 ;
if ( V_148 & V_155 )
V_150 |= V_156 ;
if ( V_148 & V_157 )
V_150 |= V_158 ;
if ( V_148 & V_159 )
V_150 |= V_160 |
V_161 ;
if ( V_148 & V_162 )
V_150 |= V_163 |
V_164 |
V_165 |
V_166 ;
return V_150 ;
}
static T_1 F_43 ( struct V_146 * V_147 )
{
V_10 V_148 = V_147 -> V_167 ;
T_1 V_150 = 0 ;
if ( V_148 & V_151 )
V_150 |= V_168 ;
if ( V_148 & V_153 )
V_150 |= V_169 ;
if ( V_148 & V_155 )
V_150 |= V_170 ;
if ( V_148 & V_157 )
V_150 |= V_171 ;
if ( V_148 & V_159 )
V_150 |= V_172 |
V_173 ;
if ( V_148 & V_162 )
V_150 |= V_174 |
V_175 |
V_176 |
V_177 ;
return V_150 ;
}
T_1 F_44 ( V_10 V_178 )
{
switch ( V_178 ) {
case V_179 :
return V_180 ;
case V_181 :
return V_182 ;
case V_183 :
return V_184 ;
case V_185 :
return V_186 ;
case V_187 :
return V_188 ;
case V_189 :
return V_190 ;
case V_191 :
return V_192 ;
case V_193 :
return V_194 ;
default:
return V_195 ;
}
}
static int F_45 ( struct V_1 * V_2 , struct V_196 * V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_146 * V_147 = & V_4 -> V_147 ;
V_10 V_197 ;
V_76 -> V_198 = F_42 ( V_147 ) ;
if ( V_147 -> V_167 )
V_76 -> V_198 |= V_199 ;
if ( F_46 ( V_147 -> V_200 ) ) {
V_76 -> V_201 =
F_43 ( V_147 ) ;
V_76 -> V_201 |= V_202 ;
V_76 -> V_203 = V_204 ;
} else {
V_76 -> V_203 = V_205 ;
V_76 -> V_201 = 0 ;
}
if ( V_147 -> V_206 & V_207 ) {
if ( ( V_147 -> V_206 & V_207 ) ==
V_207 ) {
V_76 -> V_201 |= V_208 ;
V_76 -> V_198 |= V_209 ;
} else {
V_76 -> V_201 |= V_210 ;
V_76 -> V_198 |= V_211 ;
if ( V_147 -> V_206 &
V_212 )
V_76 -> V_201 |= V_208 ;
}
} else if ( V_147 -> V_213 & V_207 ) {
if ( ( V_147 -> V_213 & V_207 ) ==
V_207 ) {
V_76 -> V_198 |= V_209 ;
} else {
V_76 -> V_198 |= V_211 ;
if ( V_147 -> V_213 &
V_212 )
V_76 -> V_198 |= V_209 ;
}
}
V_76 -> V_214 = V_215 ;
if ( V_147 -> V_216 == V_217 ) {
V_76 -> V_214 = V_218 ;
V_76 -> V_198 |= V_219 ;
V_76 -> V_201 |= V_220 ;
} else {
V_76 -> V_198 |= V_221 ;
V_76 -> V_201 |= V_222 ;
if ( V_147 -> V_216 == V_223 )
V_76 -> V_214 = V_224 ;
else if ( V_147 -> V_216 ==
V_225 )
V_76 -> V_214 = V_226 ;
}
if ( V_147 -> V_227 == V_228 ) {
if ( V_147 -> V_229 & V_230 )
V_76 -> V_229 = V_231 ;
} else {
V_76 -> V_229 = V_232 ;
}
V_197 = F_44 ( V_147 -> V_233 ) ;
F_47 ( V_76 , V_197 ) ;
if ( V_147 -> V_234 ==
V_235 )
V_76 -> V_234 = V_236 ;
else
V_76 -> V_234 = V_237 ;
V_76 -> V_238 = V_147 -> V_239 ;
return 0 ;
}
static T_1 F_48 ( struct V_1 * V_2 , V_10 V_197 )
{
switch ( V_197 ) {
case V_180 :
return V_240 ;
case V_182 :
return V_241 ;
case V_184 :
return V_242 ;
case V_186 :
return V_243 ;
case V_188 :
return V_244 ;
case V_190 :
return V_245 ;
case V_192 :
return V_246 ;
case V_194 :
return V_247 ;
default:
F_15 ( V_2 , L_24 ) ;
break;
}
return 0 ;
}
static V_10 F_49 ( T_1 V_201 )
{
V_10 V_248 = 0 ;
if ( V_201 & ( V_168 |
V_249 ) ) {
V_248 |= V_151 ;
}
if ( V_201 & ( V_169 |
V_250 ) ) {
V_248 |= V_153 ;
}
if ( V_201 & V_171 )
V_248 |= V_157 ;
return V_248 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_196 * V_76 )
{
int V_18 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_146 * V_147 = & V_4 -> V_147 ;
T_1 V_251 , V_252 = 0 ;
bool V_253 = false ;
if ( F_51 ( V_4 ) )
return V_18 ;
if ( V_76 -> V_203 == V_204 ) {
if ( V_147 -> V_216 != V_217 ) {
F_15 ( V_2 , L_25 ) ;
V_18 = - V_57 ;
goto V_254;
}
if ( V_76 -> V_201 & ~ ( V_255 |
V_202 |
V_220 |
V_208 |
V_210 ) ) {
F_15 ( V_2 , L_26 ,
V_76 -> V_201 ) ;
V_18 = - V_57 ;
goto V_254;
}
V_252 = F_49 ( V_76 -> V_201 ) ;
if ( V_252 & ~ V_147 -> V_149 ) {
F_15 ( V_2 , L_27 ,
V_76 -> V_201 ) ;
V_18 = - V_57 ;
goto V_254;
}
V_147 -> V_203 |= V_256 ;
if ( ! V_252 )
V_147 -> V_201 = V_147 -> V_149 ;
else
V_147 -> V_201 = V_252 ;
V_253 = true ;
} else {
if ( V_76 -> V_229 == V_257 ) {
F_15 ( V_2 , L_28 ) ;
V_18 = - V_57 ;
goto V_254;
}
if ( V_76 -> V_229 == V_232 )
V_76 -> V_229 = V_231 ;
V_251 = F_52 ( V_76 ) ;
V_147 -> V_258 = F_48 ( V_2 , V_251 ) ;
V_147 -> V_259 = V_230 ;
V_147 -> V_203 &= ~ V_256 ;
V_147 -> V_201 = 0 ;
}
if ( F_9 ( V_2 ) )
V_18 = F_53 ( V_4 , V_253 ) ;
V_254:
return V_18 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_146 * V_147 = & V_4 -> V_147 ;
if ( F_51 ( V_4 ) )
return;
V_261 -> V_203 = ! ! ( V_147 -> V_206 &
V_207 ) ;
V_261 -> V_262 = ( ( V_147 -> V_263 & V_212 ) != 0 ) ;
V_261 -> V_264 = ( ( V_147 -> V_263 & V_265 ) != 0 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
int V_18 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_146 * V_147 = & V_4 -> V_147 ;
if ( F_51 ( V_4 ) )
return V_18 ;
if ( V_261 -> V_203 ) {
V_147 -> V_203 |= V_266 ;
V_147 -> V_267 |= V_207 ;
} else {
if ( V_147 -> V_203 & V_266 )
V_147 -> V_268 = true ;
V_147 -> V_203 &= ~ V_266 ;
V_147 -> V_267 &= ~ V_207 ;
}
if ( V_261 -> V_262 )
V_147 -> V_267 |= V_212 ;
else
V_147 -> V_267 &= ~ V_212 ;
if ( V_261 -> V_264 )
V_147 -> V_267 |= V_265 ;
else
V_147 -> V_267 &= ~ V_265 ;
if ( F_9 ( V_2 ) )
V_18 = F_56 ( V_4 ) ;
return V_18 ;
}
static T_1 F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_147 . V_269 ;
}
static int F_58 ( struct V_1 * V_2 ,
V_10 V_270 ,
V_10 V_271 ,
V_10 V_272 ,
V_10 V_273 ,
const T_4 * V_78 ,
T_5 V_274 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
struct V_275 V_276 = { 0 } ;
T_6 V_277 ;
T_4 * V_278 ;
F_59 ( V_4 , & V_276 , V_279 , - 1 , - 1 ) ;
V_276 . V_270 = F_60 ( V_270 ) ;
V_276 . V_271 = F_60 ( V_271 ) ;
V_276 . V_272 = F_60 ( V_272 ) ;
V_276 . V_273 = F_60 ( V_273 ) ;
V_276 . V_280 = F_61 ( V_274 ) ;
V_278 = F_62 ( & V_4 -> V_141 -> V_2 , V_274 , & V_277 ,
V_281 ) ;
if ( ! V_278 ) {
F_15 ( V_2 , L_29 ,
( unsigned ) V_274 ) ;
return - V_282 ;
}
memcpy ( V_278 , V_78 , V_274 ) ;
V_276 . V_283 = F_63 ( V_277 ) ;
V_18 = F_64 ( V_4 , & V_276 , sizeof( V_276 ) , V_284 ) ;
F_65 ( & V_4 -> V_141 -> V_2 , V_274 , V_278 , V_277 ) ;
return V_18 ;
}
static int F_66 ( struct V_1 * V_2 ,
V_10 V_270 ,
const T_4 * V_285 ,
T_5 V_286 )
{
int V_18 = 0 ;
V_10 V_287 ;
T_1 V_288 ;
T_1 V_289 ;
struct V_290 * V_291 = (struct V_290 * ) V_285 ;
switch ( V_270 ) {
case V_292 :
case V_293 :
V_287 = V_294 ;
break;
default:
F_15 ( V_2 , L_30 ,
V_270 ) ;
return - V_57 ;
}
if ( V_286 < sizeof( struct V_290 ) ) {
F_15 ( V_2 , L_31 ,
( unsigned int ) V_286 ) ;
return - V_57 ;
}
if ( V_291 -> V_295 != F_61 ( V_296 ) ) {
F_15 ( V_2 , L_32 ,
F_67 ( V_291 -> V_295 ) ) ;
return - V_57 ;
}
if ( V_291 -> V_287 != V_287 ) {
F_15 ( V_2 , L_33 ,
V_287 , V_291 -> V_287 ) ;
return - V_57 ;
}
if ( V_291 -> V_297 != V_298 ) {
F_15 ( V_2 , L_34 ,
V_298 , V_291 -> V_297 ) ;
return - V_57 ;
}
V_288 = F_67 ( * ( V_299 * ) ( V_285 + V_286 -
sizeof( V_288 ) ) ) ;
V_289 = ~ F_68 ( ~ 0 , V_285 , V_286 - sizeof( V_288 ) ) ;
if ( V_289 != V_288 ) {
F_15 ( V_2 , L_35 ,
( unsigned long ) V_288 ,
( unsigned long ) V_289 ) ;
return - V_57 ;
}
V_18 = F_58 ( V_2 , V_270 , V_300 ,
0 , 0 , V_285 , V_286 ) ;
if ( V_18 == 0 ) {
}
return V_18 ;
}
static bool F_69 ( V_10 V_270 )
{
switch ( V_270 ) {
case V_301 :
case V_292 :
case V_293 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
return true ;
}
return false ;
}
static bool F_70 ( V_10 V_270 )
{
switch ( V_270 ) {
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
return true ;
}
return false ;
}
static bool F_71 ( V_10 V_270 )
{
return F_69 ( V_270 ) ||
F_70 ( V_270 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
V_10 V_270 ,
const char * V_315 )
{
const struct V_316 * V_317 ;
int V_18 ;
if ( F_71 ( V_270 ) == false )
return - V_57 ;
V_18 = F_73 ( & V_317 , V_315 , & V_2 -> V_2 ) ;
if ( V_18 != 0 ) {
F_15 ( V_2 , L_36 ,
V_18 , V_315 ) ;
return V_18 ;
}
if ( F_69 ( V_270 ) == true )
V_18 = F_66 ( V_2 , V_270 , V_317 -> V_78 , V_317 -> V_318 ) ;
else
V_18 = F_58 ( V_2 , V_270 , V_300 ,
0 , 0 , V_317 -> V_78 , V_317 -> V_318 ) ;
F_74 ( V_317 ) ;
return V_18 ;
}
static int F_75 ( struct V_1 * V_2 ,
char * V_315 )
{
F_15 ( V_2 , L_37 ) ;
return - V_57 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_319 * V_320 )
{
if ( ! F_25 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_15 ( V_2 , L_38 ) ;
return - V_57 ;
}
if ( V_320 -> V_321 == V_322 )
return F_75 ( V_2 , V_320 -> V_78 ) ;
return F_72 ( V_2 , V_320 -> V_321 , V_320 -> V_78 ) ;
}
static int F_77 ( struct V_1 * V_2 , T_1 * V_323 , T_1 * V_324 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
struct V_325 V_276 = { 0 } ;
struct V_326 * V_327 = V_4 -> V_328 ;
F_59 ( V_4 , & V_276 , V_329 , - 1 , - 1 ) ;
F_78 ( & V_4 -> V_330 ) ;
V_18 = F_79 ( V_4 , & V_276 , sizeof( V_276 ) , V_331 ) ;
if ( ! V_18 ) {
* V_323 = F_67 ( V_327 -> V_323 ) ;
* V_324 = F_67 ( V_327 -> V_332 ) ;
}
F_80 ( & V_4 -> V_330 ) ;
return V_18 ;
}
static int F_81 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_82 ( struct V_1 * V_2 , T_1 V_333 , T_4 * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
T_1 V_334 ;
T_1 V_332 ;
T_4 * V_26 ;
T_5 V_335 ;
T_6 V_277 ;
struct V_336 V_276 = { 0 } ;
V_18 = F_77 ( V_2 , & V_334 , & V_332 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_333 < 2 )
return - V_57 ;
* V_78 ++ = V_334 ;
* V_78 ++ = V_332 ;
V_333 -= 2 ;
memset ( V_78 , 0xff , V_333 ) ;
V_335 = V_334 * V_332 ;
V_26 = F_62 ( & V_4 -> V_141 -> V_2 , V_335 , & V_277 ,
V_281 ) ;
if ( ! V_26 ) {
F_15 ( V_2 , L_29 ,
( unsigned ) V_335 ) ;
return - V_282 ;
}
F_59 ( V_4 , & V_276 , V_337 , - 1 , - 1 ) ;
V_276 . V_338 = F_63 ( V_277 ) ;
V_18 = F_64 ( V_4 , & V_276 , sizeof( V_276 ) , V_331 ) ;
if ( V_18 == 0 )
memcpy ( V_78 , V_26 , V_333 > V_335 ? V_335 : V_333 ) ;
F_65 ( & V_4 -> V_141 -> V_2 , V_335 , V_26 , V_277 ) ;
return V_18 ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_339 , T_1 V_340 ,
T_1 V_324 , T_4 * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
T_4 * V_26 ;
T_6 V_277 ;
struct V_341 V_276 = { 0 } ;
V_26 = F_62 ( & V_4 -> V_141 -> V_2 , V_324 , & V_277 ,
V_281 ) ;
if ( ! V_26 ) {
F_15 ( V_2 , L_29 ,
( unsigned ) V_324 ) ;
return - V_282 ;
}
F_59 ( V_4 , & V_276 , V_342 , - 1 , - 1 ) ;
V_276 . V_338 = F_63 ( V_277 ) ;
V_276 . V_343 = F_60 ( V_339 ) ;
V_276 . V_340 = F_61 ( V_340 ) ;
V_276 . V_333 = F_61 ( V_324 ) ;
V_18 = F_64 ( V_4 , & V_276 , sizeof( V_276 ) , V_331 ) ;
if ( V_18 == 0 )
memcpy ( V_78 , V_26 , V_324 ) ;
F_65 ( & V_4 -> V_141 -> V_2 , V_324 , V_26 , V_277 ) ;
return V_18 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_344 * V_345 ,
T_4 * V_78 )
{
T_1 V_339 ;
T_1 V_340 ;
if ( V_345 -> V_340 == 0 )
return F_82 ( V_2 , V_345 -> V_333 , V_78 ) ;
V_339 = V_345 -> V_340 >> 24 ;
V_340 = V_345 -> V_340 & 0xffffff ;
if ( V_339 == 0 ) {
F_15 ( V_2 , L_39 , V_339 ) ;
return - V_57 ;
}
return F_83 ( V_2 , V_339 - 1 , V_340 , V_345 -> V_333 , V_78 ) ;
}
static int F_85 ( struct V_1 * V_2 , T_4 V_339 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_346 V_276 = { 0 } ;
F_59 ( V_4 , & V_276 , V_347 , - 1 , - 1 ) ;
V_276 . V_343 = F_60 ( V_339 ) ;
return F_64 ( V_4 , & V_276 , sizeof( V_276 ) , V_331 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_344 * V_345 ,
T_4 * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_339 , V_348 ;
V_10 type , V_349 , V_350 , V_351 ;
if ( ! F_25 ( V_4 ) ) {
F_15 ( V_2 , L_40 ) ;
return - V_57 ;
}
type = V_345 -> V_352 >> 16 ;
if ( type == 0xffff ) {
V_339 = V_345 -> V_352 & 0xff ;
V_348 = V_345 -> V_352 >> 8 ;
if ( V_339 == 0 )
return - V_57 ;
switch ( V_348 ) {
case 0x0e :
if ( V_345 -> V_340 != ~ V_345 -> V_352 )
return - V_57 ;
return F_85 ( V_2 , V_339 - 1 ) ;
default:
return - V_57 ;
}
}
if ( F_71 ( type ) == true )
return - V_57 ;
V_349 = V_345 -> V_352 & 0xffff ;
V_350 = V_345 -> V_340 >> 16 ;
V_351 = V_345 -> V_340 & 0xffff ;
return F_58 ( V_2 , type , V_350 , V_349 , V_351 , V_78 ,
V_345 -> V_333 ) ;
}
