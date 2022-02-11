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
F_22 ( V_4 , & V_60 , & V_61 , true ) ;
V_59 -> V_63 = V_60 ;
F_22 ( V_4 , & V_60 , & V_61 , false ) ;
V_62 = F_23 ( V_2 ) ;
if ( V_62 > 1 )
V_61 /= V_62 ;
V_59 -> V_64 = V_60 ;
V_59 -> V_65 = V_61 ;
V_59 -> V_66 = 0 ;
if ( V_4 -> V_67 & V_68 ) {
V_59 -> V_69 = V_4 -> V_70 ;
} else {
V_59 -> V_71 = V_4 -> V_70 ;
V_59 -> V_72 = V_4 -> V_73 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_60 , V_61 , V_62 ;
T_1 V_18 = 0 ;
bool V_74 = false ;
if ( V_59 -> V_75 )
return - V_57 ;
if ( ! V_59 -> V_69 &&
( ! V_59 -> V_71 || ! V_59 -> V_72 ) )
return - V_57 ;
if ( V_59 -> V_69 &&
( V_59 -> V_71 || V_59 -> V_72 ) )
return - V_57 ;
if ( V_59 -> V_69 )
V_74 = true ;
F_22 ( V_4 , & V_60 , & V_61 , V_74 ) ;
V_62 = F_23 ( V_2 ) ;
if ( V_62 > 1 )
V_61 /= V_62 ;
if ( V_74 && ( V_59 -> V_69 > V_60 ||
V_59 -> V_69 > V_61 ) )
return - V_76 ;
if ( ! V_74 && ( V_59 -> V_71 > V_60 ||
V_59 -> V_72 > V_61 ) )
return - V_76 ;
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
if ( V_74 ) {
V_4 -> V_67 |= V_68 ;
V_4 -> V_70 = V_59 -> V_69 ;
V_4 -> V_73 = V_59 -> V_69 ;
} else {
V_4 -> V_67 &= ~ V_68 ;
V_4 -> V_70 = V_59 -> V_71 ;
V_4 -> V_73 = V_59 -> V_72 ;
}
V_4 -> V_77 = V_4 -> V_73 ;
if ( V_62 > 1 )
V_4 -> V_77 = V_4 -> V_73 * V_62 ;
V_4 -> V_22 = V_74 ? F_5 ( int , V_4 -> V_77 , V_4 -> V_70 ) :
V_4 -> V_77 + V_4 -> V_70 ;
V_4 -> V_78 = V_4 -> V_22 ;
F_26 ( V_2 ) ;
if ( F_9 ( V_2 ) ) {
V_18 = F_20 ( V_4 , true , false ) ;
if ( ( ! V_18 ) && F_25 ( V_4 ) ) {
}
}
return V_18 ;
}
static int F_27 ( struct V_3 * V_4 , struct V_79 * V_80 ,
T_1 * V_81 )
{
int V_27 , V_28 = 0 ;
V_80 -> V_82 = V_4 -> V_83 ;
for ( V_27 = 0 ; V_27 < V_84 ; V_27 ++ ) {
struct V_85 * V_86 ;
struct V_87 * V_88 ;
V_86 = & V_4 -> V_89 [ V_27 ] ;
F_28 () ;
F_29 (fltr, head, hash) {
if ( V_28 == V_80 -> V_90 )
break;
V_81 [ V_28 ++ ] = V_88 -> V_91 ;
}
F_30 () ;
if ( V_28 == V_80 -> V_90 )
break;
}
V_80 -> V_90 = V_28 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
struct V_92 * V_93 =
(struct V_92 * ) & V_80 -> V_93 ;
struct V_87 * V_88 ;
struct V_94 * V_95 ;
int V_27 , V_18 = - V_57 ;
if ( V_93 -> V_96 < 0 || V_93 -> V_96 >= V_97 )
return V_18 ;
for ( V_27 = 0 ; V_27 < V_84 ; V_27 ++ ) {
struct V_85 * V_86 ;
V_86 = & V_4 -> V_89 [ V_27 ] ;
F_28 () ;
F_29 (fltr, head, hash) {
if ( V_88 -> V_91 == V_93 -> V_96 )
goto V_98;
}
F_30 () ;
}
return V_18 ;
V_98:
V_95 = & V_88 -> V_95 ;
if ( V_95 -> V_99 . V_100 == V_101 )
V_93 -> V_102 = V_103 ;
else if ( V_95 -> V_99 . V_100 == V_104 )
V_93 -> V_102 = V_105 ;
else
goto V_106;
V_93 -> V_107 . V_108 . V_109 = V_95 -> V_110 . V_111 . V_112 ;
V_93 -> V_113 . V_108 . V_109 = F_32 ( ~ 0 ) ;
V_93 -> V_107 . V_108 . V_114 = V_95 -> V_110 . V_111 . V_115 ;
V_93 -> V_113 . V_108 . V_114 = F_32 ( ~ 0 ) ;
V_93 -> V_107 . V_108 . V_116 = V_95 -> V_117 . V_112 ;
V_93 -> V_113 . V_108 . V_116 = F_33 ( ~ 0 ) ;
V_93 -> V_107 . V_108 . V_118 = V_95 -> V_117 . V_115 ;
V_93 -> V_113 . V_108 . V_118 = F_33 ( ~ 0 ) ;
V_93 -> V_119 = V_88 -> V_120 ;
V_18 = 0 ;
V_106:
F_30 () ;
return V_18 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_79 * V_80 ,
T_1 * V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 = 0 ;
switch ( V_80 -> V_80 ) {
case V_121 :
V_80 -> V_82 = V_4 -> V_70 ;
break;
case V_122 :
V_80 -> V_90 = V_4 -> V_83 ;
V_80 -> V_82 = V_97 ;
break;
case V_123 :
V_18 = F_27 ( V_4 , V_80 , ( T_1 * ) V_81 ) ;
break;
case V_124 :
V_18 = F_31 ( V_4 , V_80 ) ;
break;
default:
V_18 = - V_23 ;
break;
}
return V_18 ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
return V_125 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
return V_126 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 * V_127 , T_4 * V_128 ,
T_4 * V_129 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_130 * V_131 = & V_4 -> V_132 [ 0 ] ;
int V_27 = 0 ;
if ( V_129 )
* V_129 = V_133 ;
if ( V_127 )
for ( V_27 = 0 ; V_27 < V_125 ; V_27 ++ )
V_127 [ V_27 ] = F_38 ( V_131 -> V_134 [ V_27 ] ) ;
if ( V_128 )
memcpy ( V_128 , V_131 -> V_135 , V_126 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_136 * V_137 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_40 ( V_137 -> V_138 , V_139 , sizeof( V_137 -> V_138 ) ) ;
F_40 ( V_137 -> V_140 , V_141 , sizeof( V_137 -> V_140 ) ) ;
F_40 ( V_137 -> V_142 , V_4 -> V_143 , sizeof( V_137 -> V_142 ) ) ;
F_40 ( V_137 -> V_144 , F_41 ( V_4 -> V_145 ) , sizeof( V_137 -> V_144 ) ) ;
V_137 -> V_146 = V_21 * V_4 -> V_22 ;
V_137 -> V_147 = F_42 ( V_4 ) ;
V_137 -> V_148 = 0 ;
V_137 -> V_149 = 0 ;
}
static T_1 F_43 ( struct V_150 * V_151 )
{
V_10 V_152 = V_151 -> V_153 ;
T_1 V_154 = 0 ;
if ( V_152 & V_155 )
V_154 |= V_156 ;
if ( V_152 & V_157 )
V_154 |= V_158 ;
if ( V_152 & V_159 )
V_154 |= V_160 ;
if ( V_152 & V_161 )
V_154 |= V_162 ;
if ( V_152 & V_163 )
V_154 |= V_164 ;
return V_154 ;
}
static T_1 F_44 ( struct V_150 * V_151 )
{
V_10 V_152 = V_151 -> V_165 ;
T_1 V_154 = 0 ;
if ( V_152 & V_155 )
V_154 |= V_166 ;
if ( V_152 & V_157 )
V_154 |= V_167 ;
if ( V_152 & V_159 )
V_154 |= V_168 ;
if ( V_152 & V_161 )
V_154 |= V_169 ;
if ( V_152 & V_163 )
V_154 |= V_170 ;
return V_154 ;
}
T_1 F_45 ( V_10 V_171 )
{
switch ( V_171 ) {
case V_172 :
return V_173 ;
case V_174 :
return V_175 ;
case V_176 :
return V_177 ;
case V_178 :
return V_179 ;
case V_180 :
return V_181 ;
case V_182 :
return V_183 ;
case V_184 :
return V_185 ;
case V_186 :
return V_187 ;
default:
return V_188 ;
}
}
static int F_46 ( struct V_1 * V_2 , struct V_189 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_150 * V_151 = & V_4 -> V_151 ;
V_10 V_190 ;
V_80 -> V_191 = F_43 ( V_151 ) ;
V_80 -> V_191 |= V_192 | V_193 ;
if ( V_151 -> V_165 )
V_80 -> V_191 |= V_194 ;
if ( V_151 -> V_195 ) {
V_80 -> V_196 =
F_44 ( V_151 ) ;
V_80 -> V_196 |= V_197 ;
V_80 -> V_195 = V_198 ;
} else {
V_80 -> V_195 = V_199 ;
V_80 -> V_196 = 0 ;
}
if ( V_151 -> V_195 & V_200 ) {
if ( ( V_151 -> V_201 & V_202 ) ==
V_202 ) {
V_80 -> V_196 |= V_203 ;
} else {
V_80 -> V_196 |= V_204 ;
if ( V_151 -> V_201 &
V_205 )
V_80 -> V_196 |= V_203 ;
}
}
V_80 -> V_206 = V_207 ;
if ( V_151 -> V_208 == V_209 ) {
V_80 -> V_206 = V_210 ;
V_80 -> V_191 |= V_211 ;
V_80 -> V_196 |= V_212 ;
} else {
V_80 -> V_191 |= V_213 ;
V_80 -> V_196 |= V_214 ;
if ( V_151 -> V_208 == V_215 )
V_80 -> V_206 = V_216 ;
else if ( V_151 -> V_208 ==
V_217 )
V_80 -> V_206 = V_218 ;
}
if ( V_151 -> V_219 == V_220 ) {
if ( V_151 -> V_221 & V_222 )
V_80 -> V_221 = V_223 ;
} else {
V_80 -> V_221 = V_224 ;
}
V_190 = F_45 ( V_151 -> V_225 ) ;
F_47 ( V_80 , V_190 ) ;
if ( V_151 -> V_226 ==
V_227 )
V_80 -> V_226 = V_228 ;
else
V_80 -> V_226 = V_229 ;
V_80 -> V_230 = V_151 -> V_231 ;
return 0 ;
}
static T_1 F_48 ( struct V_1 * V_2 , V_10 V_190 )
{
switch ( V_190 ) {
case V_173 :
return V_232 ;
case V_175 :
return V_233 ;
case V_177 :
return V_234 ;
case V_179 :
return V_235 ;
case V_181 :
return V_236 ;
case V_183 :
return V_237 ;
case V_185 :
return V_238 ;
case V_187 :
return V_239 ;
default:
F_15 ( V_2 , L_24 ) ;
break;
}
return 0 ;
}
static V_10 F_49 ( T_1 V_196 )
{
V_10 V_240 = 0 ;
if ( V_196 & ( V_166 |
V_241 ) ) {
V_240 |= V_155 ;
}
if ( V_196 & ( V_167 |
V_242 ) ) {
V_240 |= V_157 ;
}
if ( V_196 & V_169 )
V_240 |= V_161 ;
if ( V_196 & V_170 )
V_240 |= V_163 ;
return V_240 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_189 * V_80 )
{
int V_18 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_150 * V_151 = & V_4 -> V_151 ;
T_1 V_243 , V_244 = 0 ;
bool V_245 = false ;
if ( F_51 ( V_4 ) )
return V_18 ;
if ( V_80 -> V_195 == V_198 ) {
if ( V_151 -> V_208 != V_209 ) {
F_15 ( V_2 , L_25 ) ;
V_18 = - V_57 ;
goto V_246;
}
if ( V_80 -> V_196 & ~ ( V_247 |
V_197 |
V_212 |
V_203 |
V_204 ) ) {
F_15 ( V_2 , L_26 ,
V_80 -> V_196 ) ;
V_18 = - V_57 ;
goto V_246;
}
V_244 = F_49 ( V_80 -> V_196 ) ;
if ( V_244 & ~ V_151 -> V_153 ) {
F_15 ( V_2 , L_27 ,
V_80 -> V_196 ) ;
V_18 = - V_57 ;
goto V_246;
}
V_151 -> V_195 |= V_248 ;
if ( ! V_244 )
V_151 -> V_196 = V_151 -> V_153 ;
else
V_151 -> V_196 = V_244 ;
V_245 = true ;
} else {
if ( V_80 -> V_221 == V_249 ) {
F_15 ( V_2 , L_28 ) ;
V_18 = - V_57 ;
goto V_246;
}
if ( V_80 -> V_221 == V_224 )
V_80 -> V_221 = V_223 ;
V_243 = F_52 ( V_80 ) ;
V_151 -> V_250 = F_48 ( V_2 , V_243 ) ;
V_151 -> V_251 = V_222 ;
V_151 -> V_195 = 0 ;
V_151 -> V_196 = 0 ;
}
if ( F_9 ( V_2 ) )
V_18 = F_53 ( V_4 , V_245 ) ;
V_246:
return V_18 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_150 * V_151 = & V_4 -> V_151 ;
if ( F_51 ( V_4 ) )
return;
V_253 -> V_195 = ! ! ( V_151 -> V_195 & V_200 ) ;
V_253 -> V_254 = ( ( V_151 -> V_255 & V_205 ) != 0 ) ;
V_253 -> V_256 = ( ( V_151 -> V_255 & V_257 ) != 0 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
int V_18 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_150 * V_151 = & V_4 -> V_151 ;
if ( F_51 ( V_4 ) )
return V_18 ;
if ( V_253 -> V_195 ) {
if ( ! ( V_151 -> V_195 & V_248 ) )
return - V_57 ;
V_151 -> V_195 |= V_200 ;
V_151 -> V_258 |= V_202 ;
} else {
if ( V_151 -> V_195 & V_200 )
V_151 -> V_259 = true ;
V_151 -> V_195 &= ~ V_200 ;
V_151 -> V_258 &= ~ V_202 ;
}
if ( V_253 -> V_254 )
V_151 -> V_258 |= V_205 ;
else
V_151 -> V_258 &= ~ V_205 ;
if ( V_253 -> V_256 )
V_151 -> V_258 |= V_257 ;
else
V_151 -> V_258 &= ~ V_257 ;
if ( F_9 ( V_2 ) )
V_18 = F_56 ( V_4 ) ;
return V_18 ;
}
static T_1 F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_151 . V_260 ;
}
static int F_58 ( struct V_1 * V_2 ,
V_10 V_261 ,
V_10 V_262 ,
V_10 V_263 ,
V_10 V_264 ,
const T_4 * V_82 ,
T_5 V_265 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
struct V_266 V_267 = { 0 } ;
T_6 V_268 ;
T_4 * V_269 ;
F_59 ( V_4 , & V_267 , V_270 , - 1 , - 1 ) ;
V_267 . V_261 = F_60 ( V_261 ) ;
V_267 . V_262 = F_60 ( V_262 ) ;
V_267 . V_263 = F_60 ( V_263 ) ;
V_267 . V_264 = F_60 ( V_264 ) ;
V_267 . V_271 = F_61 ( V_265 ) ;
V_269 = F_62 ( & V_4 -> V_145 -> V_2 , V_265 , & V_268 ,
V_272 ) ;
if ( ! V_269 ) {
F_15 ( V_2 , L_29 ,
( unsigned ) V_265 ) ;
return - V_76 ;
}
memcpy ( V_269 , V_82 , V_265 ) ;
V_267 . V_273 = F_63 ( V_268 ) ;
V_18 = F_64 ( V_4 , & V_267 , sizeof( V_267 ) , V_274 ) ;
F_65 ( & V_4 -> V_145 -> V_2 , V_265 , V_269 , V_268 ) ;
return V_18 ;
}
static int F_66 ( struct V_1 * V_2 ,
V_10 V_261 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_275 V_267 = { 0 } ;
F_59 ( V_4 , & V_267 , V_276 , - 1 , - 1 ) ;
switch ( V_261 ) {
case V_277 :
case V_278 :
case V_279 :
V_267 . V_280 = V_281 ;
V_267 . V_282 = V_283 ;
break;
case V_284 :
case V_285 :
V_267 . V_280 = V_286 ;
break;
case V_287 :
case V_288 :
V_267 . V_280 =
V_289 ;
break;
case V_290 :
case V_291 :
V_267 . V_280 = V_292 ;
break;
default:
return - V_57 ;
}
return F_64 ( V_4 , & V_267 , sizeof( V_267 ) , V_293 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
V_10 V_261 ,
const T_4 * V_294 ,
T_5 V_295 )
{
int V_18 = 0 ;
V_10 V_296 ;
T_1 V_297 ;
T_1 V_298 ;
struct V_299 * V_300 = (struct V_299 * ) V_294 ;
switch ( V_261 ) {
case V_278 :
case V_279 :
V_296 = V_301 ;
break;
case V_284 :
V_296 = V_302 ;
break;
default:
F_15 ( V_2 , L_30 ,
V_261 ) ;
return - V_57 ;
}
if ( V_295 < sizeof( struct V_299 ) ) {
F_15 ( V_2 , L_31 ,
( unsigned int ) V_295 ) ;
return - V_57 ;
}
if ( V_300 -> V_303 != F_61 ( V_304 ) ) {
F_15 ( V_2 , L_32 ,
F_68 ( V_300 -> V_303 ) ) ;
return - V_57 ;
}
if ( V_300 -> V_296 != V_296 ) {
F_15 ( V_2 , L_33 ,
V_296 , V_300 -> V_296 ) ;
return - V_57 ;
}
if ( V_300 -> V_305 != V_306 ) {
F_15 ( V_2 , L_34 ,
V_306 , V_300 -> V_305 ) ;
return - V_57 ;
}
V_297 = F_68 ( * ( V_307 * ) ( V_294 + V_295 -
sizeof( V_297 ) ) ) ;
V_298 = ~ F_69 ( ~ 0 , V_294 , V_295 - sizeof( V_297 ) ) ;
if ( V_298 != V_297 ) {
F_15 ( V_2 , L_35 ,
( unsigned long ) V_297 ,
( unsigned long ) V_298 ) ;
return - V_57 ;
}
V_18 = F_58 ( V_2 , V_261 , V_308 ,
0 , 0 , V_294 , V_295 ) ;
if ( V_18 == 0 )
V_18 = F_66 ( V_2 , V_261 ) ;
return V_18 ;
}
static bool F_70 ( V_10 V_261 )
{
switch ( V_261 ) {
case V_277 :
case V_278 :
case V_279 :
case V_284 :
case V_285 :
case V_287 :
case V_288 :
return true ;
}
return false ;
}
static bool F_71 ( V_10 V_261 )
{
switch ( V_261 ) {
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
return true ;
}
return false ;
}
static bool F_72 ( V_10 V_261 )
{
return F_70 ( V_261 ) ||
F_71 ( V_261 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
V_10 V_261 ,
const char * V_318 )
{
const struct V_319 * V_320 ;
int V_18 ;
if ( F_72 ( V_261 ) == false )
return - V_57 ;
V_18 = F_74 ( & V_320 , V_318 , & V_2 -> V_2 ) ;
if ( V_18 != 0 ) {
F_15 ( V_2 , L_36 ,
V_18 , V_318 ) ;
return V_18 ;
}
if ( F_70 ( V_261 ) == true )
V_18 = F_67 ( V_2 , V_261 , V_320 -> V_82 , V_320 -> V_321 ) ;
else
V_18 = F_58 ( V_2 , V_261 , V_308 ,
0 , 0 , V_320 -> V_82 , V_320 -> V_321 ) ;
F_75 ( V_320 ) ;
return V_18 ;
}
static int F_76 ( struct V_1 * V_2 ,
char * V_318 )
{
F_15 ( V_2 , L_37 ) ;
return - V_57 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_322 * V_323 )
{
if ( ! F_25 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_15 ( V_2 , L_38 ) ;
return - V_57 ;
}
if ( V_323 -> V_324 == V_325 )
return F_76 ( V_2 , V_323 -> V_82 ) ;
return F_73 ( V_2 , V_323 -> V_324 , V_323 -> V_82 ) ;
}
static int F_78 ( struct V_1 * V_2 , T_1 * V_326 , T_1 * V_327 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
struct V_328 V_267 = { 0 } ;
struct V_329 * V_330 = V_4 -> V_331 ;
F_59 ( V_4 , & V_267 , V_332 , - 1 , - 1 ) ;
F_79 ( & V_4 -> V_333 ) ;
V_18 = F_80 ( V_4 , & V_267 , sizeof( V_267 ) , V_293 ) ;
if ( ! V_18 ) {
* V_326 = F_68 ( V_330 -> V_326 ) ;
* V_327 = F_68 ( V_330 -> V_334 ) ;
}
F_81 ( & V_4 -> V_333 ) ;
return V_18 ;
}
static int F_82 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_335 , T_4 * V_82 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
T_1 V_336 ;
T_1 V_334 ;
T_4 * V_26 ;
T_5 V_337 ;
T_6 V_268 ;
struct V_338 V_267 = { 0 } ;
V_18 = F_78 ( V_2 , & V_336 , & V_334 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_335 < 2 )
return - V_57 ;
* V_82 ++ = V_336 ;
* V_82 ++ = V_334 ;
V_335 -= 2 ;
memset ( V_82 , 0xff , V_335 ) ;
V_337 = V_336 * V_334 ;
V_26 = F_62 ( & V_4 -> V_145 -> V_2 , V_337 , & V_268 ,
V_272 ) ;
if ( ! V_26 ) {
F_15 ( V_2 , L_29 ,
( unsigned ) V_337 ) ;
return - V_76 ;
}
F_59 ( V_4 , & V_267 , V_339 , - 1 , - 1 ) ;
V_267 . V_340 = F_63 ( V_268 ) ;
V_18 = F_64 ( V_4 , & V_267 , sizeof( V_267 ) , V_293 ) ;
if ( V_18 == 0 )
memcpy ( V_82 , V_26 , V_335 > V_337 ? V_337 : V_335 ) ;
F_65 ( & V_4 -> V_145 -> V_2 , V_337 , V_26 , V_268 ) ;
return V_18 ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_341 , T_1 V_342 ,
T_1 V_327 , T_4 * V_82 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
T_4 * V_26 ;
T_6 V_268 ;
struct V_343 V_267 = { 0 } ;
V_26 = F_62 ( & V_4 -> V_145 -> V_2 , V_327 , & V_268 ,
V_272 ) ;
if ( ! V_26 ) {
F_15 ( V_2 , L_29 ,
( unsigned ) V_327 ) ;
return - V_76 ;
}
F_59 ( V_4 , & V_267 , V_344 , - 1 , - 1 ) ;
V_267 . V_340 = F_63 ( V_268 ) ;
V_267 . V_345 = F_60 ( V_341 ) ;
V_267 . V_342 = F_61 ( V_342 ) ;
V_267 . V_335 = F_61 ( V_327 ) ;
V_18 = F_64 ( V_4 , & V_267 , sizeof( V_267 ) , V_293 ) ;
if ( V_18 == 0 )
memcpy ( V_82 , V_26 , V_327 ) ;
F_65 ( & V_4 -> V_145 -> V_2 , V_327 , V_26 , V_268 ) ;
return V_18 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_346 * V_347 ,
T_4 * V_82 )
{
T_1 V_341 ;
T_1 V_342 ;
if ( V_347 -> V_342 == 0 )
return F_83 ( V_2 , V_347 -> V_335 , V_82 ) ;
V_341 = V_347 -> V_342 >> 24 ;
V_342 = V_347 -> V_342 & 0xffffff ;
if ( V_341 == 0 ) {
F_15 ( V_2 , L_39 , V_341 ) ;
return - V_57 ;
}
return F_84 ( V_2 , V_341 - 1 , V_342 , V_347 -> V_335 , V_82 ) ;
}
static int F_86 ( struct V_1 * V_2 , T_4 V_341 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_348 V_267 = { 0 } ;
F_59 ( V_4 , & V_267 , V_349 , - 1 , - 1 ) ;
V_267 . V_345 = F_60 ( V_341 ) ;
return F_64 ( V_4 , & V_267 , sizeof( V_267 ) , V_293 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_346 * V_347 ,
T_4 * V_82 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_341 , V_350 ;
V_10 type , V_351 , V_352 , V_353 ;
if ( ! F_25 ( V_4 ) ) {
F_15 ( V_2 , L_40 ) ;
return - V_57 ;
}
type = V_347 -> V_354 >> 16 ;
if ( type == 0xffff ) {
V_341 = V_347 -> V_354 & 0xff ;
V_350 = V_347 -> V_354 >> 8 ;
if ( V_341 == 0 )
return - V_57 ;
switch ( V_350 ) {
case 0x0e :
if ( V_347 -> V_342 != ~ V_347 -> V_354 )
return - V_57 ;
return F_86 ( V_2 , V_341 - 1 ) ;
default:
return - V_57 ;
}
}
if ( F_72 ( type ) == true )
return - V_57 ;
V_351 = V_347 -> V_354 & 0xffff ;
V_352 = V_347 -> V_342 >> 16 ;
V_353 = V_347 -> V_342 & 0xffff ;
return F_58 ( V_2 , type , V_352 , V_351 , V_353 , V_82 ,
V_347 -> V_335 ) ;
}
