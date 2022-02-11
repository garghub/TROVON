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
V_8 -> V_25 = V_4 -> V_26 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_27 = false ;
int V_28 = 0 ;
V_4 -> V_10 = V_8 -> V_9 ;
V_4 -> V_12 = V_8 -> V_11 * 2 ;
V_4 -> V_14 = V_8 -> V_13 ;
V_4 -> V_16 = V_8 -> V_15 * 2 ;
V_4 -> V_18 = V_8 -> V_17 ;
V_4 -> V_20 = V_8 -> V_19 ;
V_4 -> V_22 = V_8 -> V_21 ;
V_4 -> V_24 = V_8 -> V_23 ;
if ( V_4 -> V_26 != V_8 -> V_25 ) {
T_1 V_29 = V_8 -> V_25 ;
V_29 = F_6 ( T_1 , V_29 ,
V_30 ,
V_31 ) ;
V_29 = F_7 ( V_29 , V_30 ) ;
V_4 -> V_26 = V_29 ;
V_27 = true ;
}
if ( F_8 ( V_2 ) ) {
if ( V_27 ) {
V_28 = F_9 ( V_4 , true , false ) ;
if ( ! V_28 )
V_28 = F_10 ( V_4 , true , false ) ;
} else {
V_28 = F_11 ( V_4 ) ;
}
}
return V_28 ;
}
static int F_12 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_32 ) {
case V_33 : {
int V_34 = V_35 * V_4 -> V_36 ;
if ( V_4 -> V_37 & V_38 )
V_34 += V_39 ;
return V_34 ;
}
default:
return - V_40 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_41 * V_42 , T_2 * V_43 )
{
T_1 V_44 , V_45 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_46 = sizeof( struct V_47 ) * V_4 -> V_36 ;
T_1 V_48 = sizeof( struct V_47 ) / 8 ;
memset ( V_43 , 0 , V_46 ) ;
if ( ! V_4 -> V_49 )
return;
for ( V_44 = 0 ; V_44 < V_4 -> V_36 ; V_44 ++ ) {
struct V_50 * V_49 = V_4 -> V_49 [ V_44 ] ;
struct V_51 * V_52 = & V_49 -> V_53 ;
T_3 * V_54 = ( T_3 * ) V_52 -> V_54 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_48 ; V_45 ++ , V_55 ++ )
V_43 [ V_45 ] = F_14 ( V_54 [ V_55 ] ) ;
V_43 [ V_45 ++ ] = V_52 -> V_56 ;
}
if ( V_4 -> V_37 & V_38 ) {
T_3 * V_57 = ( T_3 * ) V_4 -> V_58 ;
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ , V_45 ++ ) {
V_43 [ V_45 ] = F_14 ( * ( V_57 +
V_59 [ V_44 ] . V_60 ) ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 , T_1 V_61 , T_4 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_44 ;
switch ( V_61 ) {
case V_33 :
for ( V_44 = 0 ; V_44 < V_4 -> V_36 ; V_44 ++ ) {
sprintf ( V_43 , L_1 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_2 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_3 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_4 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_5 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_6 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_7 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_8 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_9 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_10 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_11 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_12 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_13 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_14 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_15 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_16 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_17 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_18 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_19 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_20 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_21 , V_44 ) ;
V_43 += V_62 ;
}
if ( V_4 -> V_37 & V_38 ) {
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ ) {
strcpy ( V_43 , V_59 [ V_44 ] . string ) ;
V_43 += V_62 ;
}
}
break;
default:
F_16 ( V_4 -> V_2 , L_22 ,
V_61 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = V_70 ;
V_64 -> V_71 = V_4 -> V_72 ;
V_64 -> V_73 = V_4 -> V_74 ;
V_64 -> V_75 = V_4 -> V_76 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_64 -> V_71 > V_66 ) ||
( V_64 -> V_75 > V_70 ) ||
( V_64 -> V_75 <= V_77 ) )
return - V_78 ;
if ( F_8 ( V_2 ) )
F_9 ( V_4 , false , false ) ;
V_4 -> V_72 = V_64 -> V_71 ;
V_4 -> V_76 = V_64 -> V_75 ;
F_19 ( V_4 ) ;
if ( F_8 ( V_2 ) )
return F_10 ( V_4 , false , false ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_81 , V_82 , V_83 ;
F_21 ( V_4 , & V_81 , & V_82 , true ) ;
V_80 -> V_84 = F_22 ( int , V_81 , V_82 ) ;
if ( F_21 ( V_4 , & V_81 , & V_82 , false ) ) {
V_81 = 0 ;
V_82 = 0 ;
}
V_83 = F_23 ( V_2 ) ;
if ( V_83 > 1 )
V_82 /= V_83 ;
V_80 -> V_85 = V_81 ;
V_80 -> V_86 = V_82 ;
V_80 -> V_87 = 0 ;
if ( V_4 -> V_37 & V_88 ) {
V_80 -> V_89 = V_4 -> V_90 ;
if ( F_24 ( V_4 ) )
V_80 -> V_89 -- ;
} else {
if ( ! F_24 ( V_4 ) ) {
V_80 -> V_91 = V_4 -> V_90 ;
V_80 -> V_92 = V_4 -> V_93 ;
}
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_81 , V_82 , V_83 ;
T_1 V_28 = 0 ;
bool V_94 = false ;
if ( V_80 -> V_95 )
return - V_78 ;
if ( ! V_80 -> V_89 &&
( ! V_80 -> V_91 || ! V_80 -> V_92 ) )
return - V_78 ;
if ( V_80 -> V_89 &&
( V_80 -> V_91 || V_80 -> V_92 ) )
return - V_78 ;
if ( F_24 ( V_4 ) && ( V_80 -> V_91 ||
V_80 -> V_92 ) )
return - V_78 ;
if ( V_80 -> V_89 )
V_94 = true ;
F_21 ( V_4 , & V_81 , & V_82 , V_94 ) ;
V_83 = F_23 ( V_2 ) ;
if ( V_83 > 1 )
V_82 /= V_83 ;
if ( V_94 &&
V_80 -> V_89 > F_22 ( int , V_81 , V_82 ) )
return - V_96 ;
if ( ! V_94 && ( V_80 -> V_91 > V_81 ||
V_80 -> V_92 > V_82 ) )
return - V_96 ;
if ( F_8 ( V_2 ) ) {
if ( F_26 ( V_4 ) ) {
}
V_28 = F_9 ( V_4 , true , false ) ;
if ( V_28 ) {
F_16 ( V_4 -> V_2 , L_23 ,
V_28 ) ;
return V_28 ;
}
}
if ( V_94 ) {
V_4 -> V_37 |= V_88 ;
V_4 -> V_90 = F_27 ( int , V_80 -> V_89 ,
V_81 ) ;
V_4 -> V_93 = F_27 ( int , V_80 -> V_89 ,
V_82 ) ;
} else {
V_4 -> V_37 &= ~ V_88 ;
V_4 -> V_90 = V_80 -> V_91 ;
V_4 -> V_93 = V_80 -> V_92 ;
}
V_4 -> V_97 = V_4 -> V_93 ;
if ( V_83 > 1 )
V_4 -> V_97 = V_4 -> V_93 * V_83 ;
V_4 -> V_36 = V_94 ? F_22 ( int , V_4 -> V_97 , V_4 -> V_90 ) :
V_4 -> V_97 + V_4 -> V_90 ;
V_4 -> V_98 = V_4 -> V_36 ;
F_28 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
V_28 = F_10 ( V_4 , true , false ) ;
if ( ( ! V_28 ) && F_26 ( V_4 ) ) {
}
}
return V_28 ;
}
static int F_29 ( struct V_3 * V_4 , struct V_99 * V_100 ,
T_1 * V_101 )
{
int V_44 , V_45 = 0 ;
V_100 -> V_102 = V_4 -> V_103 ;
for ( V_44 = 0 ; V_44 < V_104 ; V_44 ++ ) {
struct V_105 * V_106 ;
struct V_107 * V_108 ;
V_106 = & V_4 -> V_109 [ V_44 ] ;
F_30 () ;
F_31 (fltr, head, hash) {
if ( V_45 == V_100 -> V_110 )
break;
V_101 [ V_45 ++ ] = V_108 -> V_111 ;
}
F_32 () ;
if ( V_45 == V_100 -> V_110 )
break;
}
V_100 -> V_110 = V_45 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , struct V_99 * V_100 )
{
struct V_112 * V_113 =
(struct V_112 * ) & V_100 -> V_113 ;
struct V_107 * V_108 ;
struct V_114 * V_115 ;
int V_44 , V_28 = - V_78 ;
if ( V_113 -> V_116 < 0 || V_113 -> V_116 >= V_117 )
return V_28 ;
for ( V_44 = 0 ; V_44 < V_104 ; V_44 ++ ) {
struct V_105 * V_106 ;
V_106 = & V_4 -> V_109 [ V_44 ] ;
F_30 () ;
F_31 (fltr, head, hash) {
if ( V_108 -> V_111 == V_113 -> V_116 )
goto V_118;
}
F_32 () ;
}
return V_28 ;
V_118:
V_115 = & V_108 -> V_115 ;
if ( V_115 -> V_119 . V_120 == V_121 )
V_113 -> V_122 = V_123 ;
else if ( V_115 -> V_119 . V_120 == V_124 )
V_113 -> V_122 = V_125 ;
else
goto V_126;
V_113 -> V_127 . V_128 . V_129 = V_115 -> V_130 . V_131 . V_132 ;
V_113 -> V_133 . V_128 . V_129 = F_34 ( ~ 0 ) ;
V_113 -> V_127 . V_128 . V_134 = V_115 -> V_130 . V_131 . V_135 ;
V_113 -> V_133 . V_128 . V_134 = F_34 ( ~ 0 ) ;
V_113 -> V_127 . V_128 . V_136 = V_115 -> V_137 . V_132 ;
V_113 -> V_133 . V_128 . V_136 = F_35 ( ~ 0 ) ;
V_113 -> V_127 . V_128 . V_138 = V_115 -> V_137 . V_135 ;
V_113 -> V_133 . V_128 . V_138 = F_35 ( ~ 0 ) ;
V_113 -> V_139 = V_108 -> V_140 ;
V_28 = 0 ;
V_126:
F_32 () ;
return V_28 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_99 * V_100 ,
T_1 * V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 = 0 ;
switch ( V_100 -> V_100 ) {
case V_141 :
V_100 -> V_102 = V_4 -> V_90 ;
break;
case V_142 :
V_100 -> V_110 = V_4 -> V_103 ;
V_100 -> V_102 = V_117 ;
break;
case V_143 :
V_28 = F_29 ( V_4 , V_100 , ( T_1 * ) V_101 ) ;
break;
case V_144 :
V_28 = F_33 ( V_4 , V_100 ) ;
break;
default:
V_28 = - V_40 ;
break;
}
return V_28 ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
return V_145 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
return V_146 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_147 , T_4 * V_148 ,
T_4 * V_149 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_150 * V_151 = & V_4 -> V_152 [ 0 ] ;
int V_44 = 0 ;
if ( V_149 )
* V_149 = V_153 ;
if ( V_147 )
for ( V_44 = 0 ; V_44 < V_145 ; V_44 ++ )
V_147 [ V_44 ] = F_40 ( V_151 -> V_154 [ V_44 ] ) ;
if ( V_148 )
memcpy ( V_148 , V_151 -> V_155 , V_146 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char * V_158 ;
char * V_159 = NULL ;
V_158 = F_42 ( V_160 , V_161 ) ;
if ( V_158 )
V_159 = F_43 ( V_2 , V_158 , V_160 ) ;
F_44 ( V_157 -> V_162 , V_163 , sizeof( V_157 -> V_162 ) ) ;
F_44 ( V_157 -> V_164 , V_165 , sizeof( V_157 -> V_164 ) ) ;
if ( V_159 && * V_159 != 0 && isdigit ( * V_159 ) )
snprintf ( V_157 -> V_166 , sizeof( V_157 -> V_166 ) - 1 ,
L_24 , V_4 -> V_167 , V_159 ) ;
else
F_44 ( V_157 -> V_166 , V_4 -> V_167 ,
sizeof( V_157 -> V_166 ) ) ;
F_44 ( V_157 -> V_168 , F_45 ( V_4 -> V_169 ) , sizeof( V_157 -> V_168 ) ) ;
V_157 -> V_170 = V_35 * V_4 -> V_36 ;
V_157 -> V_171 = F_46 ( V_4 ) ;
V_157 -> V_172 = 0 ;
V_157 -> V_173 = 0 ;
F_47 ( V_158 ) ;
}
T_1 F_48 ( T_5 V_174 , T_4 V_175 )
{
T_1 V_176 = 0 ;
if ( V_174 & V_177 )
V_176 |= V_178 ;
if ( V_174 & V_179 )
V_176 |= V_180 ;
if ( V_174 & V_181 )
V_176 |= V_182 ;
if ( V_174 & V_183 )
V_176 |= V_184 ;
if ( V_174 & V_185 )
V_176 |= V_186 ;
if ( ( V_175 & V_187 ) == V_187 )
V_176 |= V_188 ;
else if ( V_175 & V_189 )
V_176 |= V_190 ;
else if ( V_175 & V_191 )
V_176 |= V_188 | V_190 ;
return V_176 ;
}
static void F_49 ( struct V_192 * V_193 ,
struct V_194 * V_195 )
{
T_5 V_174 = V_193 -> V_196 ;
T_4 V_175 = 0 ;
if ( V_193 -> V_197 & V_198 )
V_175 = V_193 -> V_199 ;
F_50 ( V_174 , V_175 , V_195 , V_200 ) ;
}
static void F_51 ( struct V_192 * V_193 ,
struct V_194 * V_195 )
{
T_5 V_174 = V_193 -> V_201 ;
T_4 V_175 = 0 ;
if ( V_193 -> V_197 & V_198 )
V_175 = V_193 -> V_202 ;
F_50 ( V_174 , V_175 , V_195 ,
V_203 ) ;
}
static void F_52 ( struct V_192 * V_193 ,
struct V_194 * V_195 )
{
T_5 V_174 = V_193 -> V_204 ;
F_50 ( V_174 , 0 , V_195 , V_205 ) ;
F_53 ( V_195 , V_205 , V_206 ) ;
F_53 ( V_195 , V_205 ,
V_207 ) ;
if ( V_193 -> V_208 )
F_53 ( V_195 , V_205 ,
V_209 ) ;
}
T_1 F_54 ( T_5 V_210 )
{
switch ( V_210 ) {
case V_211 :
return V_212 ;
case V_213 :
return V_214 ;
case V_215 :
return V_216 ;
case V_217 :
return V_218 ;
case V_219 :
return V_220 ;
case V_221 :
return V_222 ;
case V_223 :
return V_224 ;
case V_225 :
return V_226 ;
default:
return V_227 ;
}
}
static int F_55 ( struct V_1 * V_2 ,
struct V_194 * V_195 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_192 * V_193 = & V_4 -> V_193 ;
struct V_228 * V_229 = & V_195 -> V_229 ;
T_1 V_230 ;
F_56 ( V_195 , V_205 ) ;
F_52 ( V_193 , V_195 ) ;
F_56 ( V_195 , V_200 ) ;
if ( V_193 -> V_197 ) {
F_49 ( V_193 , V_195 ) ;
F_53 ( V_195 ,
V_200 , V_209 ) ;
V_229 -> V_197 = V_231 ;
if ( V_193 -> V_232 == V_233 )
F_51 ( V_193 , V_195 ) ;
V_230 = F_54 ( V_193 -> V_234 ) ;
if ( ! F_57 ( V_2 ) )
V_229 -> V_235 = V_236 ;
else if ( V_193 -> V_235 & V_237 )
V_229 -> V_235 = V_238 ;
else
V_229 -> V_235 = V_239 ;
} else {
V_229 -> V_197 = V_240 ;
V_230 =
F_54 ( V_193 -> V_241 ) ;
V_229 -> V_235 = V_239 ;
if ( V_193 -> V_242 == V_237 )
V_229 -> V_235 = V_238 ;
}
V_229 -> V_243 = V_230 ;
V_229 -> V_244 = V_245 ;
if ( V_193 -> V_246 == V_247 ) {
V_229 -> V_244 = V_248 ;
F_53 ( V_195 , V_205 ,
V_249 ) ;
F_53 ( V_195 , V_200 ,
V_249 ) ;
} else {
F_53 ( V_195 , V_205 ,
V_250 ) ;
F_53 ( V_195 , V_200 ,
V_250 ) ;
if ( V_193 -> V_246 == V_251 )
V_229 -> V_244 = V_252 ;
else if ( V_193 -> V_246 ==
V_253 )
V_229 -> V_244 = V_254 ;
}
V_229 -> V_255 = V_193 -> V_256 ;
return 0 ;
}
static T_1 F_58 ( struct V_1 * V_2 , T_5 V_230 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_192 * V_193 = & V_4 -> V_193 ;
T_5 V_257 = V_193 -> V_204 ;
T_1 V_258 = 0 ;
switch ( V_230 ) {
case V_212 :
if ( V_257 & V_177 )
V_258 = V_259 ;
break;
case V_214 :
if ( V_257 & V_179 )
V_258 = V_260 ;
break;
case V_216 :
if ( V_257 & V_181 )
V_258 = V_261 ;
break;
case V_218 :
if ( V_257 & V_183 )
V_258 = V_262 ;
break;
case V_220 :
if ( V_257 & V_263 )
V_258 = V_264 ;
break;
case V_222 :
if ( V_257 & V_265 )
V_258 = V_266 ;
break;
case V_224 :
if ( V_257 & V_185 )
V_258 = V_267 ;
break;
case V_226 :
if ( V_257 & V_268 )
V_258 = V_269 ;
break;
default:
F_16 ( V_2 , L_25 ) ;
break;
}
return V_258 ;
}
T_5 F_59 ( T_1 V_200 )
{
T_5 V_270 = 0 ;
if ( V_200 & ( V_178 |
V_271 ) ) {
V_270 |= V_177 ;
}
if ( V_200 & ( V_180 |
V_272 ) ) {
V_270 |= V_179 ;
}
if ( V_200 & V_184 )
V_270 |= V_183 ;
if ( V_200 & V_186 )
V_270 |= V_185 ;
return V_270 ;
}
static int F_60 ( struct V_1 * V_2 ,
const struct V_194 * V_195 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_192 * V_193 = & V_4 -> V_193 ;
const struct V_228 * V_229 = & V_195 -> V_229 ;
T_1 V_243 , V_273 = 0 ;
bool V_274 = false ;
int V_28 = 0 ;
if ( ! F_61 ( V_4 ) )
return - V_40 ;
if ( V_229 -> V_197 == V_231 ) {
F_62 ( V_273 , V_195 ,
V_200 ) ;
V_193 -> V_197 |= V_275 ;
if ( ! V_273 )
V_193 -> V_200 = V_193 -> V_208 ;
else
V_193 -> V_200 = V_273 ;
V_274 = true ;
} else {
T_5 V_258 ;
T_4 V_276 = V_193 -> V_276 ;
if ( V_276 == V_277 ||
V_276 == V_278 ||
V_193 -> V_246 == V_247 ) {
F_16 ( V_2 , L_26 ) ;
V_28 = - V_78 ;
goto V_279;
}
if ( V_229 -> V_235 == V_239 ) {
F_16 ( V_2 , L_27 ) ;
V_28 = - V_78 ;
goto V_279;
}
V_243 = V_229 -> V_243 ;
V_258 = F_58 ( V_2 , V_243 ) ;
if ( ! V_258 ) {
V_28 = - V_78 ;
goto V_279;
}
V_193 -> V_241 = V_258 ;
V_193 -> V_242 = V_237 ;
V_193 -> V_197 = 0 ;
V_193 -> V_200 = 0 ;
}
if ( F_8 ( V_2 ) )
V_28 = F_63 ( V_4 , V_274 , false ) ;
V_279:
return V_28 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_192 * V_193 = & V_4 -> V_193 ;
if ( F_65 ( V_4 ) )
return;
V_281 -> V_197 = ! ! ( V_193 -> V_197 & V_198 ) ;
V_281 -> V_282 = ! ! ( V_193 -> V_283 & V_191 ) ;
V_281 -> V_284 = ! ! ( V_193 -> V_283 & V_189 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_192 * V_193 = & V_4 -> V_193 ;
if ( ! F_61 ( V_4 ) )
return - V_40 ;
if ( V_281 -> V_197 ) {
if ( ! ( V_193 -> V_197 & V_275 ) )
return - V_78 ;
V_193 -> V_197 |= V_198 ;
if ( V_4 -> V_285 >= 0x10201 )
V_193 -> V_283 =
V_286 ;
} else {
if ( V_193 -> V_197 & V_198 )
V_193 -> V_287 = true ;
V_193 -> V_197 &= ~ V_198 ;
V_193 -> V_283 = 0 ;
}
if ( V_281 -> V_282 )
V_193 -> V_283 |= V_191 ;
if ( V_281 -> V_284 )
V_193 -> V_283 |= V_189 ;
if ( F_8 ( V_2 ) )
V_28 = F_67 ( V_4 ) ;
return V_28 ;
}
static T_1 F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_193 . V_288 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_5 V_289 ,
T_5 V_290 ,
T_5 V_291 ,
T_5 V_292 ,
const T_4 * V_102 ,
T_6 V_293 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_294 V_295 = { 0 } ;
T_7 V_296 ;
T_4 * V_297 ;
F_70 ( V_4 , & V_295 , V_298 , - 1 , - 1 ) ;
V_295 . V_289 = F_71 ( V_289 ) ;
V_295 . V_290 = F_71 ( V_290 ) ;
V_295 . V_291 = F_71 ( V_291 ) ;
V_295 . V_292 = F_71 ( V_292 ) ;
V_295 . V_299 = F_72 ( V_293 ) ;
V_297 = F_73 ( & V_4 -> V_169 -> V_2 , V_293 , & V_296 ,
V_161 ) ;
if ( ! V_297 ) {
F_16 ( V_2 , L_28 ,
( unsigned ) V_293 ) ;
return - V_96 ;
}
memcpy ( V_297 , V_102 , V_293 ) ;
V_295 . V_300 = F_74 ( V_296 ) ;
V_28 = F_75 ( V_4 , & V_295 , sizeof( V_295 ) , V_301 ) ;
F_76 ( & V_4 -> V_169 -> V_2 , V_293 , V_297 , V_296 ) ;
return V_28 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_5 V_289 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_302 V_295 = { 0 } ;
F_70 ( V_4 , & V_295 , V_303 , - 1 , - 1 ) ;
switch ( V_289 ) {
case V_304 :
case V_305 :
case V_306 :
V_295 . V_307 = V_308 ;
V_295 . V_309 = V_310 ;
break;
case V_311 :
case V_312 :
V_295 . V_307 = V_313 ;
V_295 . V_309 = V_310 ;
break;
case V_314 :
case V_315 :
V_295 . V_307 =
V_316 ;
break;
case V_317 :
case V_318 :
V_295 . V_307 = V_319 ;
break;
default:
return - V_78 ;
}
return F_75 ( V_4 , & V_295 , sizeof( V_295 ) , V_320 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
T_5 V_289 ,
const T_4 * V_321 ,
T_6 V_322 )
{
int V_28 = 0 ;
T_5 V_323 ;
T_1 V_324 ;
T_1 V_325 ;
struct V_326 * V_327 = (struct V_326 * ) V_321 ;
switch ( V_289 ) {
case V_305 :
case V_306 :
V_323 = V_328 ;
break;
case V_304 :
V_323 = V_329 ;
break;
case V_311 :
V_323 = V_330 ;
break;
case V_312 :
V_323 = V_331 ;
break;
case V_314 :
V_323 = V_332 ;
break;
case V_315 :
V_323 = V_333 ;
break;
case V_317 :
V_323 = V_334 ;
break;
case V_318 :
V_323 = V_335 ;
break;
default:
F_16 ( V_2 , L_29 ,
V_289 ) ;
return - V_78 ;
}
if ( V_322 < sizeof( struct V_326 ) ) {
F_16 ( V_2 , L_30 ,
( unsigned int ) V_322 ) ;
return - V_78 ;
}
if ( V_327 -> V_336 != F_72 ( V_337 ) ) {
F_16 ( V_2 , L_31 ,
F_79 ( V_327 -> V_336 ) ) ;
return - V_78 ;
}
if ( V_327 -> V_323 != V_323 ) {
F_16 ( V_2 , L_32 ,
V_323 , V_327 -> V_323 ) ;
return - V_78 ;
}
if ( V_327 -> V_338 != V_339 ) {
F_16 ( V_2 , L_33 ,
V_339 , V_327 -> V_338 ) ;
return - V_78 ;
}
V_324 = F_79 ( * ( V_340 * ) ( V_321 + V_322 -
sizeof( V_324 ) ) ) ;
V_325 = ~ F_80 ( ~ 0 , V_321 , V_322 - sizeof( V_324 ) ) ;
if ( V_325 != V_324 ) {
F_16 ( V_2 , L_34 ,
( unsigned long ) V_324 ,
( unsigned long ) V_325 ) ;
return - V_78 ;
}
V_28 = F_69 ( V_2 , V_289 , V_341 ,
0 , 0 , V_321 , V_322 ) ;
if ( V_28 == 0 )
V_28 = F_77 ( V_2 , V_289 ) ;
return V_28 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_5 V_289 ,
const T_4 * V_321 ,
T_6 V_322 )
{
struct V_342 * V_343 ;
T_1 V_325 ;
T_1 V_324 ;
int V_28 = 0 ;
if ( V_322 < sizeof( struct V_342 ) ) {
F_16 ( V_2 , L_35 ,
( unsigned int ) V_322 ) ;
return - V_78 ;
}
V_343 = (struct V_342 * ) ( V_321 + ( V_322 -
sizeof( * V_343 ) ) ) ;
if ( V_343 -> V_344 != F_72 ( V_345 ) ) {
F_16 ( V_2 , L_36 ,
F_79 ( V_343 -> V_344 ) ) ;
return - V_78 ;
}
if ( F_40 ( V_343 -> V_289 ) != V_289 ) {
F_16 ( V_2 , L_37 ,
V_289 , F_40 ( V_343 -> V_289 ) ) ;
return - V_78 ;
}
if ( F_40 ( V_343 -> V_346 ) <
sizeof( struct V_342 ) ) {
F_16 ( V_2 , L_38 ,
F_40 ( V_343 -> V_346 ) ) ;
return - V_78 ;
}
V_324 = F_79 ( * ( V_340 * ) ( V_321 + V_322 -
sizeof( V_324 ) ) ) ;
V_325 = ~ F_80 ( ~ 0 , V_321 , V_322 - sizeof( V_324 ) ) ;
if ( V_325 != V_324 ) {
F_16 ( V_2 ,
L_39 ,
( unsigned long ) V_324 ,
( unsigned long ) V_325 ) ;
return - V_78 ;
}
V_28 = F_69 ( V_2 , V_289 , V_341 ,
0 , 0 , V_321 , V_322 ) ;
return V_28 ;
}
static bool F_82 ( T_5 V_289 )
{
switch ( V_289 ) {
case V_304 :
case V_305 :
case V_306 :
case V_311 :
case V_312 :
case V_314 :
case V_315 :
case V_317 :
case V_318 :
return true ;
}
return false ;
}
static bool F_83 ( T_5 V_289 )
{
switch ( V_289 ) {
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
return true ;
}
return false ;
}
static bool F_84 ( T_5 V_289 )
{
return F_82 ( V_289 ) ||
F_83 ( V_289 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
T_5 V_289 ,
const char * V_356 )
{
const struct V_357 * V_358 ;
int V_28 ;
V_28 = F_86 ( & V_358 , V_356 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_40 ,
V_28 , V_356 ) ;
return V_28 ;
}
if ( F_82 ( V_289 ) == true )
V_28 = F_78 ( V_2 , V_289 , V_358 -> V_102 , V_358 -> V_359 ) ;
else if ( F_83 ( V_289 ) == true )
V_28 = F_81 ( V_2 , V_289 , V_358 -> V_102 , V_358 -> V_359 ) ;
else
V_28 = F_69 ( V_2 , V_289 , V_341 ,
0 , 0 , V_358 -> V_102 , V_358 -> V_359 ) ;
F_87 ( V_358 ) ;
return V_28 ;
}
static int F_88 ( struct V_1 * V_2 ,
char * V_356 , T_1 V_360 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_361 * V_362 = V_4 -> V_363 ;
struct V_364 V_365 = { 0 } ;
const struct V_357 * V_358 ;
T_1 V_366 ;
T_5 V_367 ;
int V_28 ;
F_89 ( V_4 ) ;
if ( F_90 ( V_2 , V_368 ,
V_341 , V_369 ,
& V_367 , & V_366 , NULL ) != 0 ) {
F_16 ( V_2 , L_41 ) ;
return - V_370 ;
}
V_28 = F_86 ( & V_358 , V_356 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_42 ,
V_28 , V_356 ) ;
return V_28 ;
}
if ( V_358 -> V_359 > V_366 ) {
F_16 ( V_2 , L_43 ,
( unsigned long ) V_358 -> V_359 ) ;
V_28 = - V_371 ;
} else {
T_7 V_296 ;
T_4 * V_297 ;
struct V_372 V_373 = { 0 } ;
F_70 ( V_4 , & V_373 , V_374 , - 1 , - 1 ) ;
V_373 . V_375 = F_71 ( V_367 ) ;
V_373 . V_376 = F_72 ( V_358 -> V_359 ) ;
V_297 = F_73 ( & V_4 -> V_169 -> V_2 , V_358 -> V_359 ,
& V_296 , V_161 ) ;
if ( ! V_297 ) {
F_16 ( V_2 ,
L_28 ,
( unsigned int ) V_358 -> V_359 ) ;
V_28 = - V_96 ;
} else {
memcpy ( V_297 , V_358 -> V_102 , V_358 -> V_359 ) ;
V_373 . V_300 = F_74 ( V_296 ) ;
V_28 = F_75 ( V_4 , & V_373 , sizeof( V_373 ) ,
V_377 ) ;
F_76 ( & V_4 -> V_169 -> V_2 , V_358 -> V_359 , V_297 ,
V_296 ) ;
}
}
F_87 ( V_358 ) ;
if ( V_28 )
return V_28 ;
if ( ( V_360 & 0xffff ) == 0 )
V_360 >>= 16 ;
F_70 ( V_4 , & V_365 , V_378 , - 1 , - 1 ) ;
V_365 . V_360 = F_72 ( V_360 ) ;
V_28 = F_75 ( V_4 , & V_365 , sizeof( V_365 ) ,
V_379 ) ;
if ( V_28 )
return - V_40 ;
if ( V_362 -> V_380 ) {
F_16 ( V_2 , L_44 ,
( V_381 ) V_362 -> V_380 , ( int ) V_362 -> V_382 ) ;
return - V_383 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_384 * V_385 )
{
if ( ! F_26 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_16 ( V_2 , L_45 ) ;
return - V_78 ;
}
if ( V_385 -> V_386 == V_387 ||
V_385 -> V_386 > 0xffff )
return F_88 ( V_2 , V_385 -> V_102 ,
V_385 -> V_386 ) ;
return F_85 ( V_2 , V_385 -> V_386 , V_385 -> V_102 ) ;
}
static int F_92 ( struct V_1 * V_2 , T_1 * V_388 , T_1 * V_389 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_390 V_295 = { 0 } ;
struct V_391 * V_392 = V_4 -> V_363 ;
F_70 ( V_4 , & V_295 , V_393 , - 1 , - 1 ) ;
F_93 ( & V_4 -> V_394 ) ;
V_28 = F_94 ( V_4 , & V_295 , sizeof( V_295 ) , V_320 ) ;
if ( ! V_28 ) {
* V_388 = F_79 ( V_392 -> V_388 ) ;
* V_389 = F_79 ( V_392 -> V_395 ) ;
}
F_95 ( & V_4 -> V_394 ) ;
return V_28 ;
}
static int F_96 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_97 ( struct V_1 * V_2 , T_1 V_376 , T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_1 V_396 ;
T_1 V_395 ;
T_4 * V_43 ;
T_6 V_397 ;
T_7 V_296 ;
struct V_398 V_295 = { 0 } ;
V_28 = F_92 ( V_2 , & V_396 , & V_395 ) ;
if ( V_28 != 0 )
return V_28 ;
if ( V_376 < 2 )
return - V_78 ;
* V_102 ++ = V_396 ;
* V_102 ++ = V_395 ;
V_376 -= 2 ;
memset ( V_102 , 0xff , V_376 ) ;
V_397 = V_396 * V_395 ;
V_43 = F_73 ( & V_4 -> V_169 -> V_2 , V_397 , & V_296 ,
V_161 ) ;
if ( ! V_43 ) {
F_16 ( V_2 , L_28 ,
( unsigned ) V_397 ) ;
return - V_96 ;
}
F_70 ( V_4 , & V_295 , V_399 , - 1 , - 1 ) ;
V_295 . V_400 = F_74 ( V_296 ) ;
V_28 = F_75 ( V_4 , & V_295 , sizeof( V_295 ) , V_320 ) ;
if ( V_28 == 0 )
memcpy ( V_102 , V_43 , V_376 > V_397 ? V_397 : V_376 ) ;
F_76 ( & V_4 -> V_169 -> V_2 , V_397 , V_43 , V_296 ) ;
return V_28 ;
}
static int F_98 ( struct V_1 * V_2 , T_1 V_367 , T_1 V_60 ,
T_1 V_389 , T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_4 * V_43 ;
T_7 V_296 ;
struct V_401 V_295 = { 0 } ;
V_43 = F_73 ( & V_4 -> V_169 -> V_2 , V_389 , & V_296 ,
V_161 ) ;
if ( ! V_43 ) {
F_16 ( V_2 , L_28 ,
( unsigned ) V_389 ) ;
return - V_96 ;
}
F_70 ( V_4 , & V_295 , V_402 , - 1 , - 1 ) ;
V_295 . V_400 = F_74 ( V_296 ) ;
V_295 . V_375 = F_71 ( V_367 ) ;
V_295 . V_60 = F_72 ( V_60 ) ;
V_295 . V_376 = F_72 ( V_389 ) ;
V_28 = F_75 ( V_4 , & V_295 , sizeof( V_295 ) , V_320 ) ;
if ( V_28 == 0 )
memcpy ( V_102 , V_43 , V_389 ) ;
F_76 ( & V_4 -> V_169 -> V_2 , V_389 , V_43 , V_296 ) ;
return V_28 ;
}
static int F_90 ( struct V_1 * V_2 , T_5 type , T_5 V_403 ,
T_5 V_404 , T_5 * V_367 , T_1 * V_405 ,
T_1 * V_406 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_407 V_295 = { 0 } ;
struct V_408 * V_392 = V_4 -> V_363 ;
F_70 ( V_4 , & V_295 , V_409 , - 1 , - 1 ) ;
V_295 . V_410 = 0 ;
V_295 . V_375 = 0 ;
V_295 . V_289 = F_71 ( type ) ;
V_295 . V_290 = F_71 ( V_403 ) ;
V_295 . V_291 = F_71 ( V_404 ) ;
V_295 . V_411 = V_412 ;
V_28 = F_99 ( V_4 , & V_295 , sizeof( V_295 ) , V_320 ) ;
if ( V_28 == 0 ) {
if ( V_367 )
* V_367 = F_40 ( V_392 -> V_375 ) ;
if ( V_405 )
* V_405 = F_79 ( V_392 -> V_413 ) ;
if ( V_406 )
* V_406 = F_79 ( V_392 -> V_299 ) ;
}
return V_28 ;
}
static char * F_100 ( int V_414 , T_4 * V_102 , T_6 V_415 )
{
char * V_416 = NULL ;
char * V_417 ;
char * V_6 ;
int V_418 = 0 ;
if ( V_415 < 1 )
return NULL ;
V_102 [ V_415 - 1 ] = 0 ;
for ( V_417 = V_102 ; * V_417 != 0 ; V_417 ++ ) {
V_418 = 0 ;
V_416 = NULL ;
while ( * V_417 != 0 && * V_417 != '\n' ) {
V_6 = V_417 ;
while ( * V_417 != 0 && * V_417 != '\t' && * V_417 != '\n' )
V_417 ++ ;
if ( V_418 == V_414 )
V_416 = V_6 ;
if ( * V_417 != '\t' )
break;
* V_417 = 0 ;
V_418 ++ ;
V_417 ++ ;
}
if ( * V_417 == 0 )
break;
* V_417 = 0 ;
}
return V_416 ;
}
static char * F_43 ( struct V_1 * V_2 , char * V_43 , T_6 V_397 )
{
T_5 V_367 = 0 ;
T_1 V_415 ;
if ( F_90 ( V_2 , V_419 ,
V_341 , V_369 ,
& V_367 , NULL , & V_415 ) != 0 )
return NULL ;
memset ( V_43 , 0 , V_397 ) ;
if ( F_98 ( V_2 , V_367 , 0 , V_415 , V_43 ) != 0 )
return NULL ;
return F_100 ( V_420 , V_43 ,
V_415 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_421 * V_422 ,
T_4 * V_102 )
{
T_1 V_367 ;
T_1 V_60 ;
if ( V_422 -> V_60 == 0 )
return F_97 ( V_2 , V_422 -> V_376 , V_102 ) ;
V_367 = V_422 -> V_60 >> 24 ;
V_60 = V_422 -> V_60 & 0xffffff ;
if ( V_367 == 0 ) {
F_16 ( V_2 , L_46 , V_367 ) ;
return - V_78 ;
}
return F_98 ( V_2 , V_367 - 1 , V_60 , V_422 -> V_376 , V_102 ) ;
}
static int F_102 ( struct V_1 * V_2 , T_4 V_367 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_423 V_295 = { 0 } ;
F_70 ( V_4 , & V_295 , V_424 , - 1 , - 1 ) ;
V_295 . V_375 = F_71 ( V_367 ) ;
return F_75 ( V_4 , & V_295 , sizeof( V_295 ) , V_320 ) ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_421 * V_422 ,
T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_367 , V_425 ;
T_5 type , V_404 , V_403 , V_426 ;
if ( ! F_26 ( V_4 ) ) {
F_16 ( V_2 , L_47 ) ;
return - V_78 ;
}
type = V_422 -> V_427 >> 16 ;
if ( type == 0xffff ) {
V_367 = V_422 -> V_427 & 0xff ;
V_425 = V_422 -> V_427 >> 8 ;
if ( V_367 == 0 )
return - V_78 ;
switch ( V_425 ) {
case 0x0e :
if ( V_422 -> V_60 != ~ V_422 -> V_427 )
return - V_78 ;
return F_102 ( V_2 , V_367 - 1 ) ;
default:
return - V_78 ;
}
}
if ( F_84 ( type ) == true )
return - V_40 ;
V_404 = V_422 -> V_427 & 0xffff ;
V_403 = V_422 -> V_60 >> 16 ;
V_426 = V_422 -> V_60 & 0xffff ;
return F_69 ( V_2 , type , V_403 , V_404 , V_426 , V_102 ,
V_422 -> V_376 ) ;
}
static int F_104 ( struct V_1 * V_2 , struct V_428 * V_429 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_428 * V_430 = & V_4 -> V_430 ;
struct V_192 * V_193 = & V_4 -> V_193 ;
T_1 V_200 =
F_48 ( V_193 -> V_200 , 0 ) ;
int V_28 = 0 ;
if ( ! F_61 ( V_4 ) )
return - V_40 ;
if ( ! ( V_4 -> V_37 & V_431 ) )
return - V_40 ;
if ( ! V_429 -> V_432 )
goto V_433;
if ( ! ( V_193 -> V_197 & V_275 ) ) {
F_105 ( V_2 , L_48 ) ;
return - V_78 ;
}
if ( V_429 -> V_434 ) {
if ( V_4 -> V_435 && ( V_429 -> V_436 > V_4 -> V_435 ||
V_429 -> V_436 < V_4 -> V_437 ) ) {
F_105 ( V_2 , L_49 ,
V_4 -> V_437 , V_4 -> V_435 ) ;
return - V_78 ;
} else if ( ! V_4 -> V_435 ) {
V_429 -> V_436 = V_430 -> V_436 ;
}
}
if ( ! V_429 -> V_438 ) {
V_429 -> V_438 = V_200 & V_430 -> V_205 ;
} else if ( V_429 -> V_438 & ~ V_200 ) {
F_105 ( V_2 , L_50 ,
V_429 -> V_438 , V_200 ) ;
return - V_78 ;
}
V_430 -> V_438 = V_429 -> V_438 ;
V_430 -> V_434 = V_429 -> V_434 ;
V_430 -> V_436 = V_429 -> V_436 ;
V_433:
V_430 -> V_432 = V_429 -> V_432 ;
if ( F_8 ( V_2 ) )
V_28 = F_63 ( V_4 , false , true ) ;
return V_28 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_428 * V_429 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_4 -> V_37 & V_431 ) )
return - V_40 ;
* V_429 = V_4 -> V_430 ;
if ( ! V_4 -> V_430 . V_432 ) {
V_429 -> V_438 = 0 ;
V_429 -> V_434 = 0 ;
}
if ( ! V_4 -> V_430 . V_439 )
V_429 -> V_440 = 0 ;
return 0 ;
}
static int F_107 ( struct V_3 * V_4 , T_5 V_441 ,
T_5 V_442 , T_5 V_443 ,
T_5 V_406 , T_4 * V_43 )
{
struct V_444 V_295 = { 0 } ;
struct V_445 * V_392 = V_4 -> V_363 ;
int V_28 , V_446 = 0 ;
F_70 ( V_4 , & V_295 , V_447 , - 1 , - 1 ) ;
V_295 . V_448 = V_441 ;
V_295 . V_442 = F_71 ( V_442 ) ;
V_295 . V_449 = F_71 ( V_4 -> V_450 . V_449 ) ;
do {
T_5 V_451 ;
V_451 = F_27 ( T_5 , V_406 , V_452 ) ;
V_406 -= V_451 ;
V_295 . V_453 = F_71 ( V_443 + V_446 ) ;
V_295 . V_406 = V_451 ;
V_295 . V_410 = F_72 ( V_443 + V_446 ?
V_454 : 0 ) ;
F_93 ( & V_4 -> V_394 ) ;
V_28 = F_94 ( V_4 , & V_295 , sizeof( V_295 ) ,
V_320 ) ;
if ( ! V_28 )
memcpy ( V_43 + V_446 , V_392 -> V_102 , V_451 ) ;
F_95 ( & V_4 -> V_394 ) ;
V_446 += V_451 ;
} while ( ! V_28 && V_406 > 0 );
return V_28 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_455 * V_456 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_444 V_295 = { 0 } ;
struct V_445 * V_392 = V_4 -> V_363 ;
int V_28 ;
if ( V_4 -> V_193 . V_457 >
V_458 )
return - V_40 ;
if ( V_4 -> V_285 < 0x10202 )
return - V_40 ;
F_70 ( V_4 , & V_295 , V_447 , - 1 , - 1 ) ;
V_295 . V_448 = V_459 ;
V_295 . V_442 = 0 ;
V_295 . V_453 = F_71 ( V_460 ) ;
V_295 . V_406 = V_461 ;
V_295 . V_449 = F_71 ( V_4 -> V_450 . V_449 ) ;
F_93 ( & V_4 -> V_394 ) ;
V_28 = F_94 ( V_4 , & V_295 , sizeof( V_295 ) , V_320 ) ;
if ( ! V_28 ) {
T_1 V_462 = F_79 ( V_392 -> V_102 [ 0 ] ) ;
switch ( V_462 ) {
case V_463 :
V_456 -> type = V_464 ;
V_456 -> V_465 = V_466 ;
break;
case V_467 :
case V_468 :
V_456 -> type = V_469 ;
V_456 -> V_465 = V_470 ;
break;
case V_471 :
V_456 -> type = V_472 ;
V_456 -> V_465 = V_473 ;
break;
default:
V_28 = - V_40 ;
break;
}
}
F_95 ( & V_4 -> V_394 ) ;
return V_28 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_421 * V_422 ,
T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_474 = V_422 -> V_60 , V_389 = V_422 -> V_376 ;
int V_28 = 0 ;
memset ( V_102 , 0 , V_422 -> V_376 ) ;
if ( V_474 < V_470 ) {
if ( V_474 + V_422 -> V_376 > V_470 )
V_389 = V_470 - V_474 ;
V_28 = F_107 ( V_4 , V_459 , 0 ,
V_474 , V_389 , V_102 ) ;
if ( V_28 )
return V_28 ;
V_474 += V_389 ;
V_102 += V_389 ;
V_389 = V_422 -> V_376 - V_389 ;
}
if ( V_389 ) {
V_474 -= V_470 ;
F_107 ( V_4 , V_475 , 1 , V_474 ,
V_389 , V_102 ) ;
}
return V_28 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_192 * V_193 = & V_4 -> V_193 ;
if ( ! F_61 ( V_4 ) )
return - V_40 ;
if ( ! ( V_193 -> V_197 & V_275 ) )
return - V_78 ;
if ( F_8 ( V_2 ) )
V_28 = F_63 ( V_4 , true , false ) ;
return V_28 ;
}
