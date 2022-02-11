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
F_19 ( V_4 , & V_75 , & V_76 , false ) ;
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
static T_1 F_44 ( T_5 V_168 , T_4 V_169 )
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
} else {
V_94 -> V_189 = V_225 ;
V_94 -> V_219 = 0 ;
}
V_94 -> V_226 = V_227 ;
if ( V_187 -> V_228 == V_229 ) {
V_94 -> V_226 = V_230 ;
V_94 -> V_195 |= V_231 ;
V_94 -> V_219 |= V_232 ;
} else {
V_94 -> V_195 |= V_233 ;
V_94 -> V_219 |= V_234 ;
if ( V_187 -> V_228 == V_235 )
V_94 -> V_226 = V_236 ;
else if ( V_187 -> V_228 ==
V_237 )
V_94 -> V_226 = V_238 ;
}
if ( V_187 -> V_222 == V_223 ) {
if ( V_187 -> V_239 & V_240 )
V_94 -> V_239 = V_241 ;
} else {
V_94 -> V_239 = V_242 ;
}
V_217 = F_48 ( V_187 -> V_243 ) ;
F_50 ( V_94 , V_217 ) ;
if ( V_187 -> V_244 ==
V_245 )
V_94 -> V_244 = V_246 ;
else
V_94 -> V_244 = V_247 ;
V_94 -> V_248 = V_187 -> V_249 ;
return 0 ;
}
static T_1 F_51 ( struct V_1 * V_2 , T_5 V_217 )
{
switch ( V_217 ) {
case V_200 :
return V_250 ;
case V_202 :
return V_251 ;
case V_204 :
return V_252 ;
case V_206 :
return V_253 ;
case V_208 :
return V_254 ;
case V_210 :
return V_255 ;
case V_212 :
return V_256 ;
case V_214 :
return V_257 ;
default:
F_12 ( V_2 , L_25 ) ;
break;
}
return 0 ;
}
static T_5 F_52 ( T_1 V_219 )
{
T_5 V_258 = 0 ;
if ( V_219 & ( V_172 |
V_259 ) ) {
V_258 |= V_171 ;
}
if ( V_219 & ( V_174 |
V_260 ) ) {
V_258 |= V_173 ;
}
if ( V_219 & V_178 )
V_258 |= V_177 ;
if ( V_219 & V_180 )
V_258 |= V_179 ;
return V_258 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_216 * V_94 )
{
int V_25 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
T_1 V_261 , V_262 = 0 ;
bool V_263 = false ;
if ( F_54 ( V_4 ) )
return V_25 ;
if ( V_94 -> V_189 == V_221 ) {
T_1 V_264 = F_47 ( V_187 ) ;
if ( V_94 -> V_219 & ~ ( V_264 | V_220 |
V_232 | V_234 ) ) {
F_12 ( V_2 , L_26 ,
V_94 -> V_219 ) ;
V_25 = - V_72 ;
goto V_265;
}
V_262 = F_52 ( V_94 -> V_219 ) ;
if ( V_262 & ~ V_187 -> V_194 ) {
F_12 ( V_2 , L_27 ,
V_94 -> V_219 ) ;
V_25 = - V_72 ;
goto V_265;
}
V_187 -> V_189 |= V_266 ;
if ( ! V_262 )
V_187 -> V_219 = V_187 -> V_194 ;
else
V_187 -> V_219 = V_262 ;
V_263 = true ;
} else {
if ( V_94 -> V_239 == V_267 ) {
F_12 ( V_2 , L_28 ) ;
V_25 = - V_72 ;
goto V_265;
}
if ( V_94 -> V_239 == V_242 )
V_94 -> V_239 = V_241 ;
V_261 = F_55 ( V_94 ) ;
V_187 -> V_268 = F_51 ( V_2 , V_261 ) ;
V_187 -> V_269 = V_240 ;
V_187 -> V_189 = 0 ;
V_187 -> V_219 = 0 ;
}
if ( F_6 ( V_2 ) )
V_25 = F_56 ( V_4 , V_263 ) ;
V_265:
return V_25 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
if ( F_54 ( V_4 ) )
return;
V_271 -> V_189 = ! ! ( V_187 -> V_189 & V_190 ) ;
V_271 -> V_272 = ! ! ( V_187 -> V_273 & V_185 ) ;
V_271 -> V_274 = ! ! ( V_187 -> V_273 & V_183 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
int V_25 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 = & V_4 -> V_187 ;
if ( F_54 ( V_4 ) )
return V_25 ;
if ( V_271 -> V_189 ) {
if ( ! ( V_187 -> V_189 & V_266 ) )
return - V_72 ;
V_187 -> V_189 |= V_190 ;
V_187 -> V_273 |= V_181 ;
} else {
if ( V_187 -> V_189 & V_190 )
V_187 -> V_275 = true ;
V_187 -> V_189 &= ~ V_190 ;
V_187 -> V_273 &= ~ V_181 ;
}
if ( V_271 -> V_272 )
V_187 -> V_273 |= V_185 ;
else
V_187 -> V_273 &= ~ V_185 ;
if ( V_271 -> V_274 )
V_187 -> V_273 |= V_183 ;
else
V_187 -> V_273 &= ~ V_183 ;
if ( F_6 ( V_2 ) )
V_25 = F_59 ( V_4 ) ;
return V_25 ;
}
static T_1 F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_187 . V_276 ;
}
static int F_61 ( struct V_1 * V_2 ,
T_5 V_277 ,
T_5 V_278 ,
T_5 V_279 ,
T_5 V_280 ,
const T_4 * V_96 ,
T_6 V_281 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
struct V_282 V_283 = { 0 } ;
T_7 V_284 ;
T_4 * V_285 ;
F_62 ( V_4 , & V_283 , V_286 , - 1 , - 1 ) ;
V_283 . V_277 = F_63 ( V_277 ) ;
V_283 . V_278 = F_63 ( V_278 ) ;
V_283 . V_279 = F_63 ( V_279 ) ;
V_283 . V_280 = F_63 ( V_280 ) ;
V_283 . V_287 = F_64 ( V_281 ) ;
V_285 = F_65 ( & V_4 -> V_163 -> V_2 , V_281 , & V_284 ,
V_155 ) ;
if ( ! V_285 ) {
F_12 ( V_2 , L_29 ,
( unsigned ) V_281 ) ;
return - V_90 ;
}
memcpy ( V_285 , V_96 , V_281 ) ;
V_283 . V_288 = F_66 ( V_284 ) ;
V_25 = F_67 ( V_4 , & V_283 , sizeof( V_283 ) , V_289 ) ;
F_68 ( & V_4 -> V_163 -> V_2 , V_281 , V_285 , V_284 ) ;
return V_25 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_5 V_277 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_290 V_283 = { 0 } ;
F_62 ( V_4 , & V_283 , V_291 , - 1 , - 1 ) ;
switch ( V_277 ) {
case V_292 :
case V_293 :
case V_294 :
V_283 . V_295 = V_296 ;
V_283 . V_297 = V_298 ;
break;
case V_299 :
case V_300 :
V_283 . V_295 = V_301 ;
break;
case V_302 :
case V_303 :
V_283 . V_295 =
V_304 ;
break;
case V_305 :
case V_306 :
V_283 . V_295 = V_307 ;
break;
default:
return - V_72 ;
}
return F_67 ( V_4 , & V_283 , sizeof( V_283 ) , V_308 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
T_5 V_277 ,
const T_4 * V_309 ,
T_6 V_310 )
{
int V_25 = 0 ;
T_5 V_311 ;
T_1 V_312 ;
T_1 V_313 ;
struct V_314 * V_315 = (struct V_314 * ) V_309 ;
switch ( V_277 ) {
case V_293 :
case V_294 :
V_311 = V_316 ;
break;
case V_299 :
V_311 = V_317 ;
break;
default:
F_12 ( V_2 , L_30 ,
V_277 ) ;
return - V_72 ;
}
if ( V_310 < sizeof( struct V_314 ) ) {
F_12 ( V_2 , L_31 ,
( unsigned int ) V_310 ) ;
return - V_72 ;
}
if ( V_315 -> V_318 != F_64 ( V_319 ) ) {
F_12 ( V_2 , L_32 ,
F_71 ( V_315 -> V_318 ) ) ;
return - V_72 ;
}
if ( V_315 -> V_311 != V_311 ) {
F_12 ( V_2 , L_33 ,
V_311 , V_315 -> V_311 ) ;
return - V_72 ;
}
if ( V_315 -> V_320 != V_321 ) {
F_12 ( V_2 , L_34 ,
V_321 , V_315 -> V_320 ) ;
return - V_72 ;
}
V_312 = F_71 ( * ( V_322 * ) ( V_309 + V_310 -
sizeof( V_312 ) ) ) ;
V_313 = ~ F_72 ( ~ 0 , V_309 , V_310 - sizeof( V_312 ) ) ;
if ( V_313 != V_312 ) {
F_12 ( V_2 , L_35 ,
( unsigned long ) V_312 ,
( unsigned long ) V_313 ) ;
return - V_72 ;
}
V_25 = F_61 ( V_2 , V_277 , V_323 ,
0 , 0 , V_309 , V_310 ) ;
if ( V_25 == 0 )
V_25 = F_69 ( V_2 , V_277 ) ;
return V_25 ;
}
static bool F_73 ( T_5 V_277 )
{
switch ( V_277 ) {
case V_292 :
case V_293 :
case V_294 :
case V_299 :
case V_300 :
case V_302 :
case V_303 :
return true ;
}
return false ;
}
static bool F_74 ( T_5 V_277 )
{
switch ( V_277 ) {
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
return true ;
}
return false ;
}
static bool F_75 ( T_5 V_277 )
{
return F_73 ( V_277 ) ||
F_74 ( V_277 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
T_5 V_277 ,
const char * V_333 )
{
const struct V_334 * V_335 ;
int V_25 ;
if ( F_75 ( V_277 ) == false )
return - V_72 ;
V_25 = F_77 ( & V_335 , V_333 , & V_2 -> V_2 ) ;
if ( V_25 != 0 ) {
F_12 ( V_2 , L_36 ,
V_25 , V_333 ) ;
return V_25 ;
}
if ( F_73 ( V_277 ) == true )
V_25 = F_70 ( V_2 , V_277 , V_335 -> V_96 , V_335 -> V_336 ) ;
else
V_25 = F_61 ( V_2 , V_277 , V_323 ,
0 , 0 , V_335 -> V_96 , V_335 -> V_336 ) ;
F_78 ( V_335 ) ;
return V_25 ;
}
static int F_79 ( struct V_1 * V_2 ,
char * V_333 )
{
F_12 ( V_2 , L_37 ) ;
return - V_72 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_337 * V_338 )
{
if ( ! F_22 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_12 ( V_2 , L_38 ) ;
return - V_72 ;
}
if ( V_338 -> V_339 == V_340 )
return F_79 ( V_2 , V_338 -> V_96 ) ;
return F_76 ( V_2 , V_338 -> V_339 , V_338 -> V_96 ) ;
}
static int F_81 ( struct V_1 * V_2 , T_1 * V_341 , T_1 * V_342 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
struct V_343 V_283 = { 0 } ;
struct V_344 * V_345 = V_4 -> V_346 ;
F_62 ( V_4 , & V_283 , V_347 , - 1 , - 1 ) ;
F_82 ( & V_4 -> V_348 ) ;
V_25 = F_83 ( V_4 , & V_283 , sizeof( V_283 ) , V_308 ) ;
if ( ! V_25 ) {
* V_341 = F_71 ( V_345 -> V_341 ) ;
* V_342 = F_71 ( V_345 -> V_349 ) ;
}
F_84 ( & V_4 -> V_348 ) ;
return V_25 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_350 , T_4 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
T_1 V_351 ;
T_1 V_349 ;
T_4 * V_37 ;
T_6 V_352 ;
T_7 V_284 ;
struct V_353 V_283 = { 0 } ;
V_25 = F_81 ( V_2 , & V_351 , & V_349 ) ;
if ( V_25 != 0 )
return V_25 ;
if ( V_350 < 2 )
return - V_72 ;
* V_96 ++ = V_351 ;
* V_96 ++ = V_349 ;
V_350 -= 2 ;
memset ( V_96 , 0xff , V_350 ) ;
V_352 = V_351 * V_349 ;
V_37 = F_65 ( & V_4 -> V_163 -> V_2 , V_352 , & V_284 ,
V_155 ) ;
if ( ! V_37 ) {
F_12 ( V_2 , L_29 ,
( unsigned ) V_352 ) ;
return - V_90 ;
}
F_62 ( V_4 , & V_283 , V_354 , - 1 , - 1 ) ;
V_283 . V_355 = F_66 ( V_284 ) ;
V_25 = F_67 ( V_4 , & V_283 , sizeof( V_283 ) , V_308 ) ;
if ( V_25 == 0 )
memcpy ( V_96 , V_37 , V_350 > V_352 ? V_352 : V_350 ) ;
F_68 ( & V_4 -> V_163 -> V_2 , V_352 , V_37 , V_284 ) ;
return V_25 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_356 , T_1 V_54 ,
T_1 V_342 , T_4 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
T_4 * V_37 ;
T_7 V_284 ;
struct V_357 V_283 = { 0 } ;
V_37 = F_65 ( & V_4 -> V_163 -> V_2 , V_342 , & V_284 ,
V_155 ) ;
if ( ! V_37 ) {
F_12 ( V_2 , L_29 ,
( unsigned ) V_342 ) ;
return - V_90 ;
}
F_62 ( V_4 , & V_283 , V_358 , - 1 , - 1 ) ;
V_283 . V_355 = F_66 ( V_284 ) ;
V_283 . V_359 = F_63 ( V_356 ) ;
V_283 . V_54 = F_64 ( V_54 ) ;
V_283 . V_350 = F_64 ( V_342 ) ;
V_25 = F_67 ( V_4 , & V_283 , sizeof( V_283 ) , V_308 ) ;
if ( V_25 == 0 )
memcpy ( V_96 , V_37 , V_342 ) ;
F_68 ( & V_4 -> V_163 -> V_2 , V_342 , V_37 , V_284 ) ;
return V_25 ;
}
static int F_88 ( struct V_1 * V_2 , T_5 type , T_5 V_360 ,
T_5 V_361 , T_5 * V_356 , T_1 * V_362 ,
T_1 * V_363 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
struct V_364 V_283 = { 0 } ;
struct V_365 * V_345 = V_4 -> V_346 ;
F_62 ( V_4 , & V_283 , V_366 , - 1 , - 1 ) ;
V_283 . V_367 = 0 ;
V_283 . V_359 = 0 ;
V_283 . V_277 = F_63 ( type ) ;
V_283 . V_278 = F_63 ( V_360 ) ;
V_283 . V_279 = F_63 ( V_361 ) ;
V_283 . V_368 = V_369 ;
V_25 = F_89 ( V_4 , & V_283 , sizeof( V_283 ) , V_308 ) ;
if ( V_25 == 0 ) {
if ( V_356 )
* V_356 = F_36 ( V_345 -> V_359 ) ;
if ( V_362 )
* V_362 = F_71 ( V_345 -> V_370 ) ;
if ( V_363 )
* V_363 = F_71 ( V_345 -> V_287 ) ;
}
return V_25 ;
}
static char * F_90 ( int V_371 , T_4 * V_96 , T_6 V_372 )
{
char * V_373 = NULL ;
char * V_374 ;
char * V_6 ;
int V_375 = 0 ;
if ( V_372 < 1 )
return NULL ;
V_96 [ V_372 - 1 ] = 0 ;
for ( V_374 = V_96 ; * V_374 != 0 ; V_374 ++ ) {
V_375 = 0 ;
V_373 = NULL ;
while ( * V_374 != 0 && * V_374 != '\n' ) {
V_6 = V_374 ;
while ( * V_374 != 0 && * V_374 != '\t' && * V_374 != '\n' )
V_374 ++ ;
if ( V_375 == V_371 )
V_373 = V_6 ;
if ( * V_374 != '\t' )
break;
* V_374 = 0 ;
V_375 ++ ;
V_374 ++ ;
}
if ( * V_374 == 0 )
break;
* V_374 = 0 ;
}
return V_373 ;
}
static char * F_39 ( struct V_1 * V_2 , char * V_37 , T_6 V_352 )
{
T_5 V_356 = 0 ;
T_1 V_372 ;
if ( F_88 ( V_2 , V_376 ,
V_323 , V_377 ,
& V_356 , NULL , & V_372 ) != 0 )
return NULL ;
memset ( V_37 , 0 , V_352 ) ;
if ( F_87 ( V_2 , V_356 , 0 , V_372 , V_37 ) != 0 )
return NULL ;
return F_90 ( V_378 , V_37 ,
V_372 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_379 * V_380 ,
T_4 * V_96 )
{
T_1 V_356 ;
T_1 V_54 ;
if ( V_380 -> V_54 == 0 )
return F_86 ( V_2 , V_380 -> V_350 , V_96 ) ;
V_356 = V_380 -> V_54 >> 24 ;
V_54 = V_380 -> V_54 & 0xffffff ;
if ( V_356 == 0 ) {
F_12 ( V_2 , L_39 , V_356 ) ;
return - V_72 ;
}
return F_87 ( V_2 , V_356 - 1 , V_54 , V_380 -> V_350 , V_96 ) ;
}
static int F_92 ( struct V_1 * V_2 , T_4 V_356 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_381 V_283 = { 0 } ;
F_62 ( V_4 , & V_283 , V_382 , - 1 , - 1 ) ;
V_283 . V_359 = F_63 ( V_356 ) ;
return F_67 ( V_4 , & V_283 , sizeof( V_283 ) , V_308 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_379 * V_380 ,
T_4 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_356 , V_383 ;
T_5 type , V_361 , V_360 , V_384 ;
if ( ! F_22 ( V_4 ) ) {
F_12 ( V_2 , L_40 ) ;
return - V_72 ;
}
type = V_380 -> V_385 >> 16 ;
if ( type == 0xffff ) {
V_356 = V_380 -> V_385 & 0xff ;
V_383 = V_380 -> V_385 >> 8 ;
if ( V_356 == 0 )
return - V_72 ;
switch ( V_383 ) {
case 0x0e :
if ( V_380 -> V_54 != ~ V_380 -> V_385 )
return - V_72 ;
return F_92 ( V_2 , V_356 - 1 ) ;
default:
return - V_72 ;
}
}
if ( F_75 ( type ) == true )
return - V_72 ;
V_361 = V_380 -> V_385 & 0xffff ;
V_360 = V_380 -> V_54 >> 16 ;
V_384 = V_380 -> V_54 & 0xffff ;
return F_61 ( V_2 , type , V_360 , V_361 , V_384 , V_96 ,
V_380 -> V_350 ) ;
}
