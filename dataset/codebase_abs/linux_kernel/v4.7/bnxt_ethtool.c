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
V_8 -> V_9 = V_4 -> V_10 ;
V_8 -> V_11 = V_4 -> V_12 / 2 ;
V_8 -> V_13 = V_4 -> V_14 ;
V_8 -> V_15 = V_4 -> V_16 / 2 ;
V_8 -> V_17 = V_4 -> V_18 ;
V_8 -> V_19 = V_4 -> V_20 ;
V_8 -> V_21 = V_4 -> V_22 ;
V_8 -> V_23 = V_4 -> V_24 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 = 0 ;
V_4 -> V_10 = V_8 -> V_9 ;
V_4 -> V_12 = V_8 -> V_11 * 2 ;
V_4 -> V_14 = V_8 -> V_13 ;
V_4 -> V_16 = V_8 -> V_15 * 2 ;
V_4 -> V_18 = V_8 -> V_17 ;
V_4 -> V_20 = V_8 -> V_19 ;
V_4 -> V_22 = V_8 -> V_21 ;
V_4 -> V_24 = V_8 -> V_23 ;
if ( F_6 ( V_2 ) )
V_25 = F_7 ( V_4 ) ;
return V_25 ;
}
static int F_8 ( struct V_1 * V_2 , int V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_26 ) {
case V_27 : {
int V_28 = V_29 * V_4 -> V_30 ;
if ( V_4 -> V_31 & V_32 )
V_28 += V_33 ;
return V_28 ;
}
default:
return - V_34 ;
}
}
static void F_9 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_2 * V_37 )
{
T_1 V_38 , V_39 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_40 = sizeof( struct V_41 ) * V_4 -> V_30 ;
T_1 V_42 = sizeof( struct V_41 ) / 8 ;
memset ( V_37 , 0 , V_40 ) ;
if ( ! V_4 -> V_43 )
return;
for ( V_38 = 0 ; V_38 < V_4 -> V_30 ; V_38 ++ ) {
struct V_44 * V_43 = V_4 -> V_43 [ V_38 ] ;
struct V_45 * V_46 = & V_43 -> V_47 ;
T_3 * V_48 = ( T_3 * ) V_46 -> V_48 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_42 ; V_39 ++ , V_49 ++ )
V_37 [ V_39 ] = F_10 ( V_48 [ V_49 ] ) ;
V_37 [ V_39 ++ ] = V_46 -> V_50 ;
}
if ( V_4 -> V_31 & V_32 ) {
T_3 * V_51 = ( T_3 * ) V_4 -> V_52 ;
for ( V_38 = 0 ; V_38 < V_33 ; V_38 ++ , V_39 ++ ) {
V_37 [ V_39 ] = F_10 ( * ( V_51 +
V_53 [ V_38 ] . V_54 ) ) ;
}
}
}
static void F_11 ( struct V_1 * V_2 , T_1 V_55 , T_4 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_38 ;
switch ( V_55 ) {
case V_27 :
for ( V_38 = 0 ; V_38 < V_4 -> V_30 ; V_38 ++ ) {
sprintf ( V_37 , L_1 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_2 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_3 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_4 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_5 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_6 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_7 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_8 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_9 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_10 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_11 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_12 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_13 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_14 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_15 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_16 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_17 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_18 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_19 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_20 , V_38 ) ;
V_37 += V_56 ;
sprintf ( V_37 , L_21 , V_38 ) ;
V_37 += V_56 ;
}
if ( V_4 -> V_31 & V_32 ) {
for ( V_38 = 0 ; V_38 < V_33 ; V_38 ++ ) {
strcpy ( V_37 , V_53 [ V_38 ] . string ) ;
V_37 += V_56 ;
}
}
break;
default:
F_12 ( V_4 -> V_2 , L_22 ,
V_55 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_58 -> V_59 = V_60 ;
V_58 -> V_61 = V_62 ;
V_58 -> V_63 = V_64 ;
V_58 -> V_65 = V_4 -> V_66 ;
V_58 -> V_67 = V_4 -> V_68 ;
V_58 -> V_69 = V_4 -> V_70 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_58 -> V_65 > V_60 ) ||
( V_58 -> V_69 > V_64 ) ||
( V_58 -> V_69 <= V_71 ) )
return - V_72 ;
if ( F_6 ( V_2 ) )
F_15 ( V_4 , false , false ) ;
V_4 -> V_66 = V_58 -> V_65 ;
V_4 -> V_70 = V_58 -> V_69 ;
F_16 ( V_4 ) ;
if ( F_6 ( V_2 ) )
return F_17 ( V_4 , false , false ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_75 , V_76 , V_77 ;
F_19 ( V_4 , & V_75 , & V_76 , true ) ;
V_74 -> V_78 = V_75 ;
if ( F_19 ( V_4 , & V_75 , & V_76 , false ) ) {
V_75 = 0 ;
V_76 = 0 ;
}
V_77 = F_20 ( V_2 ) ;
if ( V_77 > 1 )
V_76 /= V_77 ;
V_74 -> V_79 = V_75 ;
V_74 -> V_80 = V_76 ;
V_74 -> V_81 = 0 ;
if ( V_4 -> V_31 & V_82 ) {
V_74 -> V_83 = V_4 -> V_84 ;
} else {
V_74 -> V_85 = V_4 -> V_84 ;
V_74 -> V_86 = V_4 -> V_87 ;
}
}
static int F_21 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_75 , V_76 , V_77 ;
T_1 V_25 = 0 ;
bool V_88 = false ;
if ( V_74 -> V_89 )
return - V_72 ;
if ( ! V_74 -> V_83 &&
( ! V_74 -> V_85 || ! V_74 -> V_86 ) )
return - V_72 ;
if ( V_74 -> V_83 &&
( V_74 -> V_85 || V_74 -> V_86 ) )
return - V_72 ;
if ( V_74 -> V_83 )
V_88 = true ;
F_19 ( V_4 , & V_75 , & V_76 , V_88 ) ;
V_77 = F_20 ( V_2 ) ;
if ( V_77 > 1 )
V_76 /= V_77 ;
if ( V_88 && ( V_74 -> V_83 > V_75 ||
V_74 -> V_83 > V_76 ) )
return - V_90 ;
if ( ! V_88 && ( V_74 -> V_85 > V_75 ||
V_74 -> V_86 > V_76 ) )
return - V_90 ;
if ( F_6 ( V_2 ) ) {
if ( F_22 ( V_4 ) ) {
}
V_25 = F_15 ( V_4 , true , false ) ;
if ( V_25 ) {
F_12 ( V_4 -> V_2 , L_23 ,
V_25 ) ;
return V_25 ;
}
}
if ( V_88 ) {
V_4 -> V_31 |= V_82 ;
V_4 -> V_84 = V_74 -> V_83 ;
V_4 -> V_87 = V_74 -> V_83 ;
} else {
V_4 -> V_31 &= ~ V_82 ;
V_4 -> V_84 = V_74 -> V_85 ;
V_4 -> V_87 = V_74 -> V_86 ;
}
V_4 -> V_91 = V_4 -> V_87 ;
if ( V_77 > 1 )
V_4 -> V_91 = V_4 -> V_87 * V_77 ;
V_4 -> V_30 = V_88 ? F_23 ( int , V_4 -> V_91 , V_4 -> V_84 ) :
V_4 -> V_91 + V_4 -> V_84 ;
V_4 -> V_92 = V_4 -> V_30 ;
F_24 ( V_2 ) ;
if ( F_6 ( V_2 ) ) {
V_25 = F_17 ( V_4 , true , false ) ;
if ( ( ! V_25 ) && F_22 ( V_4 ) ) {
}
}
return V_25 ;
}
static int F_25 ( struct V_3 * V_4 , struct V_93 * V_94 ,
T_1 * V_95 )
{
int V_38 , V_39 = 0 ;
V_94 -> V_96 = V_4 -> V_97 ;
for ( V_38 = 0 ; V_38 < V_98 ; V_38 ++ ) {
struct V_99 * V_100 ;
struct V_101 * V_102 ;
V_100 = & V_4 -> V_103 [ V_38 ] ;
F_26 () ;
F_27 (fltr, head, hash) {
if ( V_39 == V_94 -> V_104 )
break;
V_95 [ V_39 ++ ] = V_102 -> V_105 ;
}
F_28 () ;
if ( V_39 == V_94 -> V_104 )
break;
}
V_94 -> V_104 = V_39 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 , struct V_93 * V_94 )
{
struct V_106 * V_107 =
(struct V_106 * ) & V_94 -> V_107 ;
struct V_101 * V_102 ;
struct V_108 * V_109 ;
int V_38 , V_25 = - V_72 ;
if ( V_107 -> V_110 < 0 || V_107 -> V_110 >= V_111 )
return V_25 ;
for ( V_38 = 0 ; V_38 < V_98 ; V_38 ++ ) {
struct V_99 * V_100 ;
V_100 = & V_4 -> V_103 [ V_38 ] ;
F_26 () ;
F_27 (fltr, head, hash) {
if ( V_102 -> V_105 == V_107 -> V_110 )
goto V_112;
}
F_28 () ;
}
return V_25 ;
V_112:
V_109 = & V_102 -> V_109 ;
if ( V_109 -> V_113 . V_114 == V_115 )
V_107 -> V_116 = V_117 ;
else if ( V_109 -> V_113 . V_114 == V_118 )
V_107 -> V_116 = V_119 ;
else
goto V_120;
V_107 -> V_121 . V_122 . V_123 = V_109 -> V_124 . V_125 . V_126 ;
V_107 -> V_127 . V_122 . V_123 = F_30 ( ~ 0 ) ;
V_107 -> V_121 . V_122 . V_128 = V_109 -> V_124 . V_125 . V_129 ;
V_107 -> V_127 . V_122 . V_128 = F_30 ( ~ 0 ) ;
V_107 -> V_121 . V_122 . V_130 = V_109 -> V_131 . V_126 ;
V_107 -> V_127 . V_122 . V_130 = F_31 ( ~ 0 ) ;
V_107 -> V_121 . V_122 . V_132 = V_109 -> V_131 . V_129 ;
V_107 -> V_127 . V_122 . V_132 = F_31 ( ~ 0 ) ;
V_107 -> V_133 = V_102 -> V_134 ;
V_25 = 0 ;
V_120:
F_28 () ;
return V_25 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_93 * V_94 ,
T_1 * V_95 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 = 0 ;
switch ( V_94 -> V_94 ) {
case V_135 :
V_94 -> V_96 = V_4 -> V_84 ;
break;
case V_136 :
V_94 -> V_104 = V_4 -> V_97 ;
V_94 -> V_96 = V_111 ;
break;
case V_137 :
V_25 = F_25 ( V_4 , V_94 , ( T_1 * ) V_95 ) ;
break;
case V_138 :
V_25 = F_29 ( V_4 , V_94 ) ;
break;
default:
V_25 = - V_34 ;
break;
}
return V_25 ;
}
static T_1 F_33 ( struct V_1 * V_2 )
{
return V_139 ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
return V_140 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 * V_141 , T_4 * V_142 ,
T_4 * V_143 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_144 * V_145 = & V_4 -> V_146 [ 0 ] ;
int V_38 = 0 ;
if ( V_143 )
* V_143 = V_147 ;
if ( V_141 )
for ( V_38 = 0 ; V_38 < V_139 ; V_38 ++ )
V_141 [ V_38 ] = F_36 ( V_145 -> V_148 [ V_38 ] ) ;
if ( V_142 )
memcpy ( V_142 , V_145 -> V_149 , V_140 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char * V_152 ;
char * V_153 = NULL ;
V_152 = F_38 ( V_154 , V_155 ) ;
if ( V_152 )
V_153 = F_39 ( V_2 , V_152 , V_154 ) ;
F_40 ( V_151 -> V_156 , V_157 , sizeof( V_151 -> V_156 ) ) ;
F_40 ( V_151 -> V_158 , V_159 , sizeof( V_151 -> V_158 ) ) ;
if ( V_153 && * V_153 != 0 && isdigit ( * V_153 ) )
snprintf ( V_151 -> V_160 , sizeof( V_151 -> V_160 ) - 1 ,
L_24 , V_4 -> V_161 , V_153 ) ;
else
F_40 ( V_151 -> V_160 , V_4 -> V_161 ,
sizeof( V_151 -> V_160 ) ) ;
F_40 ( V_151 -> V_162 , F_41 ( V_4 -> V_163 ) , sizeof( V_151 -> V_162 ) ) ;
V_151 -> V_164 = V_29 * V_4 -> V_30 ;
V_151 -> V_165 = F_42 ( V_4 ) ;
V_151 -> V_166 = 0 ;
V_151 -> V_167 = 0 ;
F_43 ( V_152 ) ;
}
T_1 F_44 ( T_5 V_168 , T_4 V_169 )
{
T_1 V_170 = 0 ;
if ( V_168 & V_171 )
V_170 |= V_172 ;
if ( V_168 & V_173 )
V_170 |= V_174 ;
if ( V_168 & V_175 )
V_170 |= V_176 ;
if ( V_168 & V_177 )
V_170 |= V_178 ;
if ( V_168 & V_179 )
V_170 |= V_180 ;
if ( ( V_169 & V_181 ) == V_181 )
V_170 |= V_182 ;
else if ( V_169 & V_183 )
V_170 |= V_184 ;
else if ( V_169 & V_185 )
V_170 |= V_182 | V_184 ;
return V_170 ;
}
static T_1 F_45 ( struct V_186 * V_187 )
{
T_5 V_168 = V_187 -> V_188 ;
T_4 V_169 = 0 ;
if ( V_187 -> V_189 & V_190 )
V_169 = V_187 -> V_191 ;
return F_44 ( V_168 , V_169 ) ;
}
static T_1 F_46 ( struct V_186 * V_187 )
{
T_5 V_168 = V_187 -> V_192 ;
T_4 V_169 = 0 ;
if ( V_187 -> V_189 & V_190 )
V_169 = V_187 -> V_193 ;
return F_44 ( V_168 , V_169 ) ;
}
static T_1 F_47 ( struct V_186 * V_187 )
{
T_5 V_168 = V_187 -> V_194 ;
T_1 V_195 ;
V_195 = F_44 ( V_168 , 0 ) ;
return V_195 | V_196 | V_197 ;
}
T_1 F_48 ( T_5 V_198 )
{
switch ( V_198 ) {
case V_199 :
return V_200 ;
case V_201 :
return V_202 ;
case V_203 :
return V_204 ;
case V_205 :
return V_206 ;
case V_207 :
return V_208 ;
case V_209 :
return V_210 ;
case V_211 :
return V_212 ;
case V_213 :
return V_214 ;
default:
return V_215 ;
}
}
static int F_49 ( struct V_1 * V_2 , struct V_216 * V_94 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
T_5 V_217 ;
V_94 -> V_195 = F_47 ( V_187 ) ;
if ( V_187 -> V_188 )
V_94 -> V_195 |= V_218 ;
if ( V_187 -> V_189 ) {
V_94 -> V_219 =
F_45 ( V_187 ) ;
V_94 -> V_219 |= V_220 ;
V_94 -> V_189 = V_221 ;
if ( V_187 -> V_222 == V_223 )
V_94 -> V_224 =
F_46 ( V_187 ) ;
V_217 = F_48 ( V_187 -> V_225 ) ;
if ( ! F_50 ( V_2 ) )
V_94 -> V_226 = V_227 ;
else if ( V_187 -> V_226 & V_228 )
V_94 -> V_226 = V_229 ;
else
V_94 -> V_226 = V_230 ;
} else {
V_94 -> V_189 = V_231 ;
V_94 -> V_219 = 0 ;
V_217 =
F_48 ( V_187 -> V_232 ) ;
V_94 -> V_226 = V_230 ;
if ( V_187 -> V_233 == V_228 )
V_94 -> V_226 = V_229 ;
}
F_51 ( V_94 , V_217 ) ;
V_94 -> V_234 = V_235 ;
if ( V_187 -> V_236 == V_237 ) {
V_94 -> V_234 = V_238 ;
V_94 -> V_195 |= V_239 ;
V_94 -> V_219 |= V_240 ;
} else {
V_94 -> V_195 |= V_241 ;
V_94 -> V_219 |= V_242 ;
if ( V_187 -> V_236 == V_243 )
V_94 -> V_234 = V_244 ;
else if ( V_187 -> V_236 ==
V_245 )
V_94 -> V_234 = V_246 ;
}
if ( V_187 -> V_247 ==
V_248 )
V_94 -> V_247 = V_249 ;
else
V_94 -> V_247 = V_250 ;
V_94 -> V_251 = V_187 -> V_252 ;
return 0 ;
}
static T_1 F_52 ( struct V_1 * V_2 , T_5 V_217 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
T_5 V_253 = V_187 -> V_194 ;
T_1 V_254 = 0 ;
switch ( V_217 ) {
case V_200 :
if ( V_253 & V_171 )
V_254 = V_255 ;
break;
case V_202 :
if ( V_253 & V_173 )
V_254 = V_256 ;
break;
case V_204 :
if ( V_253 & V_175 )
V_254 = V_257 ;
break;
case V_206 :
if ( V_253 & V_177 )
V_254 = V_258 ;
break;
case V_208 :
if ( V_253 & V_259 )
V_254 = V_260 ;
break;
case V_210 :
if ( V_253 & V_261 )
V_254 = V_262 ;
break;
case V_212 :
if ( V_253 & V_179 )
V_254 = V_263 ;
break;
case V_214 :
if ( V_253 & V_264 )
V_254 = V_265 ;
break;
default:
F_12 ( V_2 , L_25 ) ;
break;
}
return V_254 ;
}
T_5 F_53 ( T_1 V_219 )
{
T_5 V_266 = 0 ;
if ( V_219 & ( V_172 |
V_267 ) ) {
V_266 |= V_171 ;
}
if ( V_219 & ( V_174 |
V_268 ) ) {
V_266 |= V_173 ;
}
if ( V_219 & V_178 )
V_266 |= V_177 ;
if ( V_219 & V_180 )
V_266 |= V_179 ;
return V_266 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_216 * V_94 )
{
int V_25 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
T_1 V_269 , V_270 = 0 ;
bool V_271 = false ;
if ( F_55 ( V_4 ) )
return V_25 ;
if ( V_94 -> V_189 == V_221 ) {
T_1 V_272 = F_47 ( V_187 ) ;
if ( V_94 -> V_219 & ~ ( V_272 | V_220 |
V_240 | V_242 ) ) {
F_12 ( V_2 , L_26 ,
V_94 -> V_219 ) ;
V_25 = - V_72 ;
goto V_273;
}
V_270 = F_53 ( V_94 -> V_219 ) ;
if ( V_270 & ~ V_187 -> V_194 ) {
F_12 ( V_2 , L_27 ,
V_94 -> V_219 ) ;
V_25 = - V_72 ;
goto V_273;
}
V_187 -> V_189 |= V_274 ;
if ( ! V_270 )
V_187 -> V_219 = V_187 -> V_194 ;
else
V_187 -> V_219 = V_270 ;
V_271 = true ;
} else {
T_5 V_254 ;
T_4 V_275 = V_187 -> V_275 ;
if ( V_275 == V_276 ||
V_275 == V_277 ||
V_187 -> V_236 == V_237 ) {
F_12 ( V_2 , L_28 ) ;
V_25 = - V_72 ;
goto V_273;
}
if ( V_94 -> V_226 == V_230 ) {
F_12 ( V_2 , L_29 ) ;
V_25 = - V_72 ;
goto V_273;
}
if ( V_94 -> V_226 == V_227 )
V_94 -> V_226 = V_229 ;
V_269 = F_56 ( V_94 ) ;
V_254 = F_52 ( V_2 , V_269 ) ;
if ( ! V_254 ) {
V_25 = - V_72 ;
goto V_273;
}
V_187 -> V_232 = V_254 ;
V_187 -> V_233 = V_228 ;
V_187 -> V_189 = 0 ;
V_187 -> V_219 = 0 ;
}
if ( F_6 ( V_2 ) )
V_25 = F_57 ( V_4 , V_271 , false ) ;
V_273:
return V_25 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
if ( F_55 ( V_4 ) )
return;
V_279 -> V_189 = ! ! ( V_187 -> V_189 & V_190 ) ;
V_279 -> V_280 = ! ! ( V_187 -> V_281 & V_185 ) ;
V_279 -> V_282 = ! ! ( V_187 -> V_281 & V_183 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
int V_25 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
if ( F_55 ( V_4 ) )
return V_25 ;
if ( V_279 -> V_189 ) {
if ( ! ( V_187 -> V_189 & V_274 ) )
return - V_72 ;
V_187 -> V_189 |= V_190 ;
if ( V_4 -> V_283 >= 0x10201 )
V_187 -> V_281 =
V_284 ;
} else {
if ( V_187 -> V_189 & V_190 )
V_187 -> V_285 = true ;
V_187 -> V_189 &= ~ V_190 ;
V_187 -> V_281 = 0 ;
}
if ( V_279 -> V_280 )
V_187 -> V_281 |= V_185 ;
if ( V_279 -> V_282 )
V_187 -> V_281 |= V_183 ;
if ( F_6 ( V_2 ) )
V_25 = F_60 ( V_4 ) ;
return V_25 ;
}
static T_1 F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_187 . V_286 ;
}
static int F_62 ( struct V_1 * V_2 ,
T_5 V_287 ,
T_5 V_288 ,
T_5 V_289 ,
T_5 V_290 ,
const T_4 * V_96 ,
T_6 V_291 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
struct V_292 V_293 = { 0 } ;
T_7 V_294 ;
T_4 * V_295 ;
F_63 ( V_4 , & V_293 , V_296 , - 1 , - 1 ) ;
V_293 . V_287 = F_64 ( V_287 ) ;
V_293 . V_288 = F_64 ( V_288 ) ;
V_293 . V_289 = F_64 ( V_289 ) ;
V_293 . V_290 = F_64 ( V_290 ) ;
V_293 . V_297 = F_65 ( V_291 ) ;
V_295 = F_66 ( & V_4 -> V_163 -> V_2 , V_291 , & V_294 ,
V_155 ) ;
if ( ! V_295 ) {
F_12 ( V_2 , L_30 ,
( unsigned ) V_291 ) ;
return - V_90 ;
}
memcpy ( V_295 , V_96 , V_291 ) ;
V_293 . V_298 = F_67 ( V_294 ) ;
V_25 = F_68 ( V_4 , & V_293 , sizeof( V_293 ) , V_299 ) ;
F_69 ( & V_4 -> V_163 -> V_2 , V_291 , V_295 , V_294 ) ;
return V_25 ;
}
static int F_70 ( struct V_1 * V_2 ,
T_5 V_287 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_300 V_293 = { 0 } ;
F_63 ( V_4 , & V_293 , V_301 , - 1 , - 1 ) ;
switch ( V_287 ) {
case V_302 :
case V_303 :
case V_304 :
V_293 . V_305 = V_306 ;
V_293 . V_307 = V_308 ;
break;
case V_309 :
case V_310 :
V_293 . V_305 = V_311 ;
break;
case V_312 :
case V_313 :
V_293 . V_305 =
V_314 ;
break;
case V_315 :
case V_316 :
V_293 . V_305 = V_317 ;
break;
default:
return - V_72 ;
}
return F_68 ( V_4 , & V_293 , sizeof( V_293 ) , V_318 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
T_5 V_287 ,
const T_4 * V_319 ,
T_6 V_320 )
{
int V_25 = 0 ;
T_5 V_321 ;
T_1 V_322 ;
T_1 V_323 ;
struct V_324 * V_325 = (struct V_324 * ) V_319 ;
switch ( V_287 ) {
case V_303 :
case V_304 :
V_321 = V_326 ;
break;
case V_309 :
V_321 = V_327 ;
break;
default:
F_12 ( V_2 , L_31 ,
V_287 ) ;
return - V_72 ;
}
if ( V_320 < sizeof( struct V_324 ) ) {
F_12 ( V_2 , L_32 ,
( unsigned int ) V_320 ) ;
return - V_72 ;
}
if ( V_325 -> V_328 != F_65 ( V_329 ) ) {
F_12 ( V_2 , L_33 ,
F_72 ( V_325 -> V_328 ) ) ;
return - V_72 ;
}
if ( V_325 -> V_321 != V_321 ) {
F_12 ( V_2 , L_34 ,
V_321 , V_325 -> V_321 ) ;
return - V_72 ;
}
if ( V_325 -> V_330 != V_331 ) {
F_12 ( V_2 , L_35 ,
V_331 , V_325 -> V_330 ) ;
return - V_72 ;
}
V_322 = F_72 ( * ( V_332 * ) ( V_319 + V_320 -
sizeof( V_322 ) ) ) ;
V_323 = ~ F_73 ( ~ 0 , V_319 , V_320 - sizeof( V_322 ) ) ;
if ( V_323 != V_322 ) {
F_12 ( V_2 , L_36 ,
( unsigned long ) V_322 ,
( unsigned long ) V_323 ) ;
return - V_72 ;
}
V_25 = F_62 ( V_2 , V_287 , V_333 ,
0 , 0 , V_319 , V_320 ) ;
if ( V_25 == 0 )
V_25 = F_70 ( V_2 , V_287 ) ;
return V_25 ;
}
static bool F_74 ( T_5 V_287 )
{
switch ( V_287 ) {
case V_302 :
case V_303 :
case V_304 :
case V_309 :
case V_310 :
case V_312 :
case V_313 :
return true ;
}
return false ;
}
static bool F_75 ( T_5 V_287 )
{
switch ( V_287 ) {
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
return true ;
}
return false ;
}
static bool F_76 ( T_5 V_287 )
{
return F_74 ( V_287 ) ||
F_75 ( V_287 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
T_5 V_287 ,
const char * V_343 )
{
const struct V_344 * V_345 ;
int V_25 ;
if ( F_76 ( V_287 ) == false )
return - V_72 ;
V_25 = F_78 ( & V_345 , V_343 , & V_2 -> V_2 ) ;
if ( V_25 != 0 ) {
F_12 ( V_2 , L_37 ,
V_25 , V_343 ) ;
return V_25 ;
}
if ( F_74 ( V_287 ) == true )
V_25 = F_71 ( V_2 , V_287 , V_345 -> V_96 , V_345 -> V_346 ) ;
else
V_25 = F_62 ( V_2 , V_287 , V_333 ,
0 , 0 , V_345 -> V_96 , V_345 -> V_346 ) ;
F_79 ( V_345 ) ;
return V_25 ;
}
static int F_80 ( struct V_1 * V_2 ,
char * V_343 )
{
F_12 ( V_2 , L_38 ) ;
return - V_72 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_347 * V_348 )
{
if ( ! F_22 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_12 ( V_2 , L_39 ) ;
return - V_72 ;
}
if ( V_348 -> V_349 == V_350 )
return F_80 ( V_2 , V_348 -> V_96 ) ;
return F_77 ( V_2 , V_348 -> V_349 , V_348 -> V_96 ) ;
}
static int F_82 ( struct V_1 * V_2 , T_1 * V_351 , T_1 * V_352 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
struct V_353 V_293 = { 0 } ;
struct V_354 * V_355 = V_4 -> V_356 ;
F_63 ( V_4 , & V_293 , V_357 , - 1 , - 1 ) ;
F_83 ( & V_4 -> V_358 ) ;
V_25 = F_84 ( V_4 , & V_293 , sizeof( V_293 ) , V_318 ) ;
if ( ! V_25 ) {
* V_351 = F_72 ( V_355 -> V_351 ) ;
* V_352 = F_72 ( V_355 -> V_359 ) ;
}
F_85 ( & V_4 -> V_358 ) ;
return V_25 ;
}
static int F_86 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_360 , T_4 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
T_1 V_361 ;
T_1 V_359 ;
T_4 * V_37 ;
T_6 V_362 ;
T_7 V_294 ;
struct V_363 V_293 = { 0 } ;
V_25 = F_82 ( V_2 , & V_361 , & V_359 ) ;
if ( V_25 != 0 )
return V_25 ;
if ( V_360 < 2 )
return - V_72 ;
* V_96 ++ = V_361 ;
* V_96 ++ = V_359 ;
V_360 -= 2 ;
memset ( V_96 , 0xff , V_360 ) ;
V_362 = V_361 * V_359 ;
V_37 = F_66 ( & V_4 -> V_163 -> V_2 , V_362 , & V_294 ,
V_155 ) ;
if ( ! V_37 ) {
F_12 ( V_2 , L_30 ,
( unsigned ) V_362 ) ;
return - V_90 ;
}
F_63 ( V_4 , & V_293 , V_364 , - 1 , - 1 ) ;
V_293 . V_365 = F_67 ( V_294 ) ;
V_25 = F_68 ( V_4 , & V_293 , sizeof( V_293 ) , V_318 ) ;
if ( V_25 == 0 )
memcpy ( V_96 , V_37 , V_360 > V_362 ? V_362 : V_360 ) ;
F_69 ( & V_4 -> V_163 -> V_2 , V_362 , V_37 , V_294 ) ;
return V_25 ;
}
static int F_88 ( struct V_1 * V_2 , T_1 V_366 , T_1 V_54 ,
T_1 V_352 , T_4 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
T_4 * V_37 ;
T_7 V_294 ;
struct V_367 V_293 = { 0 } ;
V_37 = F_66 ( & V_4 -> V_163 -> V_2 , V_352 , & V_294 ,
V_155 ) ;
if ( ! V_37 ) {
F_12 ( V_2 , L_30 ,
( unsigned ) V_352 ) ;
return - V_90 ;
}
F_63 ( V_4 , & V_293 , V_368 , - 1 , - 1 ) ;
V_293 . V_365 = F_67 ( V_294 ) ;
V_293 . V_369 = F_64 ( V_366 ) ;
V_293 . V_54 = F_65 ( V_54 ) ;
V_293 . V_360 = F_65 ( V_352 ) ;
V_25 = F_68 ( V_4 , & V_293 , sizeof( V_293 ) , V_318 ) ;
if ( V_25 == 0 )
memcpy ( V_96 , V_37 , V_352 ) ;
F_69 ( & V_4 -> V_163 -> V_2 , V_352 , V_37 , V_294 ) ;
return V_25 ;
}
static int F_89 ( struct V_1 * V_2 , T_5 type , T_5 V_370 ,
T_5 V_371 , T_5 * V_366 , T_1 * V_372 ,
T_1 * V_373 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
struct V_374 V_293 = { 0 } ;
struct V_375 * V_355 = V_4 -> V_356 ;
F_63 ( V_4 , & V_293 , V_376 , - 1 , - 1 ) ;
V_293 . V_377 = 0 ;
V_293 . V_369 = 0 ;
V_293 . V_287 = F_64 ( type ) ;
V_293 . V_288 = F_64 ( V_370 ) ;
V_293 . V_289 = F_64 ( V_371 ) ;
V_293 . V_378 = V_379 ;
V_25 = F_90 ( V_4 , & V_293 , sizeof( V_293 ) , V_318 ) ;
if ( V_25 == 0 ) {
if ( V_366 )
* V_366 = F_36 ( V_355 -> V_369 ) ;
if ( V_372 )
* V_372 = F_72 ( V_355 -> V_380 ) ;
if ( V_373 )
* V_373 = F_72 ( V_355 -> V_297 ) ;
}
return V_25 ;
}
static char * F_91 ( int V_381 , T_4 * V_96 , T_6 V_382 )
{
char * V_383 = NULL ;
char * V_384 ;
char * V_6 ;
int V_385 = 0 ;
if ( V_382 < 1 )
return NULL ;
V_96 [ V_382 - 1 ] = 0 ;
for ( V_384 = V_96 ; * V_384 != 0 ; V_384 ++ ) {
V_385 = 0 ;
V_383 = NULL ;
while ( * V_384 != 0 && * V_384 != '\n' ) {
V_6 = V_384 ;
while ( * V_384 != 0 && * V_384 != '\t' && * V_384 != '\n' )
V_384 ++ ;
if ( V_385 == V_381 )
V_383 = V_6 ;
if ( * V_384 != '\t' )
break;
* V_384 = 0 ;
V_385 ++ ;
V_384 ++ ;
}
if ( * V_384 == 0 )
break;
* V_384 = 0 ;
}
return V_383 ;
}
static char * F_39 ( struct V_1 * V_2 , char * V_37 , T_6 V_362 )
{
T_5 V_366 = 0 ;
T_1 V_382 ;
if ( F_89 ( V_2 , V_386 ,
V_333 , V_387 ,
& V_366 , NULL , & V_382 ) != 0 )
return NULL ;
memset ( V_37 , 0 , V_362 ) ;
if ( F_88 ( V_2 , V_366 , 0 , V_382 , V_37 ) != 0 )
return NULL ;
return F_91 ( V_388 , V_37 ,
V_382 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_389 * V_390 ,
T_4 * V_96 )
{
T_1 V_366 ;
T_1 V_54 ;
if ( V_390 -> V_54 == 0 )
return F_87 ( V_2 , V_390 -> V_360 , V_96 ) ;
V_366 = V_390 -> V_54 >> 24 ;
V_54 = V_390 -> V_54 & 0xffffff ;
if ( V_366 == 0 ) {
F_12 ( V_2 , L_40 , V_366 ) ;
return - V_72 ;
}
return F_88 ( V_2 , V_366 - 1 , V_54 , V_390 -> V_360 , V_96 ) ;
}
static int F_93 ( struct V_1 * V_2 , T_4 V_366 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_391 V_293 = { 0 } ;
F_63 ( V_4 , & V_293 , V_392 , - 1 , - 1 ) ;
V_293 . V_369 = F_64 ( V_366 ) ;
return F_68 ( V_4 , & V_293 , sizeof( V_293 ) , V_318 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_389 * V_390 ,
T_4 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_366 , V_393 ;
T_5 type , V_371 , V_370 , V_394 ;
if ( ! F_22 ( V_4 ) ) {
F_12 ( V_2 , L_41 ) ;
return - V_72 ;
}
type = V_390 -> V_395 >> 16 ;
if ( type == 0xffff ) {
V_366 = V_390 -> V_395 & 0xff ;
V_393 = V_390 -> V_395 >> 8 ;
if ( V_366 == 0 )
return - V_72 ;
switch ( V_393 ) {
case 0x0e :
if ( V_390 -> V_54 != ~ V_390 -> V_395 )
return - V_72 ;
return F_93 ( V_2 , V_366 - 1 ) ;
default:
return - V_72 ;
}
}
if ( F_76 ( type ) == true )
return - V_72 ;
V_371 = V_390 -> V_395 & 0xffff ;
V_370 = V_390 -> V_54 >> 16 ;
V_394 = V_390 -> V_54 & 0xffff ;
return F_62 ( V_2 , type , V_370 , V_371 , V_394 , V_96 ,
V_390 -> V_360 ) ;
}
static int F_95 ( struct V_1 * V_2 , struct V_396 * V_397 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_396 * V_398 = & V_4 -> V_398 ;
struct V_186 * V_187 = & V_4 -> V_187 ;
T_1 V_219 =
F_44 ( V_187 -> V_219 , 0 ) ;
int V_25 = 0 ;
if ( F_55 ( V_4 ) )
return 0 ;
if ( ! ( V_4 -> V_31 & V_399 ) )
return - V_34 ;
if ( ! V_397 -> V_400 )
goto V_401;
if ( ! ( V_187 -> V_189 & V_274 ) ) {
F_96 ( V_2 , L_42 ) ;
return - V_72 ;
}
if ( V_397 -> V_402 ) {
if ( V_4 -> V_403 && ( V_397 -> V_404 > V_4 -> V_403 ||
V_397 -> V_404 < V_4 -> V_405 ) ) {
F_96 ( V_2 , L_43 ,
V_4 -> V_405 , V_4 -> V_403 ) ;
return - V_72 ;
} else if ( ! V_4 -> V_403 ) {
V_397 -> V_404 = V_398 -> V_404 ;
}
}
if ( ! V_397 -> V_406 ) {
V_397 -> V_406 = V_219 & V_398 -> V_195 ;
} else if ( V_397 -> V_406 & ~ V_219 ) {
F_96 ( V_2 , L_44 ,
V_397 -> V_406 , V_219 ) ;
return - V_72 ;
}
V_398 -> V_406 = V_397 -> V_406 ;
V_398 -> V_402 = V_397 -> V_402 ;
V_398 -> V_404 = V_397 -> V_404 ;
V_401:
V_398 -> V_400 = V_397 -> V_400 ;
if ( F_6 ( V_2 ) )
V_25 = F_57 ( V_4 , false , true ) ;
return V_25 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_396 * V_397 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_4 -> V_31 & V_399 ) )
return - V_34 ;
* V_397 = V_4 -> V_398 ;
if ( ! V_4 -> V_398 . V_400 ) {
V_397 -> V_406 = 0 ;
V_397 -> V_402 = 0 ;
}
if ( ! V_4 -> V_398 . V_407 )
V_397 -> V_408 = 0 ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 , T_5 V_409 ,
T_5 V_410 , T_5 V_411 ,
T_5 V_373 , T_4 * V_37 )
{
struct V_412 V_293 = { 0 } ;
struct V_413 * V_355 = V_4 -> V_356 ;
int V_25 , V_414 = 0 ;
F_63 ( V_4 , & V_293 , V_415 , - 1 , - 1 ) ;
V_293 . V_416 = V_409 ;
V_293 . V_410 = F_64 ( V_410 ) ;
V_293 . V_417 = F_64 ( V_4 -> V_418 . V_417 ) ;
do {
T_5 V_419 ;
V_419 = F_99 ( T_5 , V_373 , V_420 ) ;
V_373 -= V_419 ;
V_293 . V_421 = F_64 ( V_411 + V_414 ) ;
V_293 . V_373 = V_419 ;
V_293 . V_377 = F_65 ( V_411 + V_414 ?
V_422 : 0 ) ;
F_83 ( & V_4 -> V_358 ) ;
V_25 = F_84 ( V_4 , & V_293 , sizeof( V_293 ) ,
V_318 ) ;
if ( ! V_25 )
memcpy ( V_37 + V_414 , V_355 -> V_96 , V_419 ) ;
F_85 ( & V_4 -> V_358 ) ;
V_414 += V_419 ;
} while ( ! V_25 && V_373 > 0 );
return V_25 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_423 * V_424 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_412 V_293 = { 0 } ;
struct V_413 * V_355 = V_4 -> V_356 ;
int V_25 ;
if ( V_4 -> V_187 . V_425 >
V_426 )
return - V_34 ;
if ( V_4 -> V_283 < 0x10202 )
return - V_34 ;
F_63 ( V_4 , & V_293 , V_415 , - 1 , - 1 ) ;
V_293 . V_416 = V_427 ;
V_293 . V_410 = 0 ;
V_293 . V_421 = F_64 ( V_428 ) ;
V_293 . V_373 = V_429 ;
V_293 . V_417 = F_64 ( V_4 -> V_418 . V_417 ) ;
F_83 ( & V_4 -> V_358 ) ;
V_25 = F_84 ( V_4 , & V_293 , sizeof( V_293 ) , V_318 ) ;
if ( ! V_25 ) {
T_1 V_430 = F_72 ( V_355 -> V_96 [ 0 ] ) ;
switch ( V_430 ) {
case V_431 :
V_424 -> type = V_432 ;
V_424 -> V_433 = V_434 ;
break;
case V_435 :
case V_436 :
V_424 -> type = V_437 ;
V_424 -> V_433 = V_438 ;
break;
case V_439 :
V_424 -> type = V_440 ;
V_424 -> V_433 = V_441 ;
break;
default:
V_25 = - V_34 ;
break;
}
}
F_85 ( & V_4 -> V_358 ) ;
return V_25 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_389 * V_390 ,
T_4 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_442 = V_390 -> V_54 , V_352 = V_390 -> V_360 ;
int V_25 = 0 ;
memset ( V_96 , 0 , V_390 -> V_360 ) ;
if ( V_442 < V_438 ) {
if ( V_442 + V_390 -> V_360 > V_438 )
V_352 = V_438 - V_442 ;
V_25 = F_98 ( V_4 , V_427 , 0 ,
V_442 , V_352 , V_96 ) ;
if ( V_25 )
return V_25 ;
V_442 += V_352 ;
V_96 += V_352 ;
V_352 = V_390 -> V_360 - V_352 ;
}
if ( V_352 ) {
V_442 -= V_438 ;
F_98 ( V_4 , V_443 , 1 , V_442 ,
V_352 , V_96 ) ;
}
return V_25 ;
}
