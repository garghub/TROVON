static T_1 F_1 ( unsigned int V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 , V_6 ;
T_1 V_7 , V_8 , V_9 ;
T_1 V_10 ;
V_4 = F_2 ( V_2 , 128 ) ;
V_5 = F_2 ( V_2 , 128 ) ;
V_7 = F_2 ( V_3 , 32 ) ;
V_8 = F_2 ( ( ( V_3 + 1 ) >> 1 ) , 16 ) ;
V_6 = V_4 * V_7 ;
V_9 = V_5 * V_8 + V_11 ;
V_10 = V_6 + V_9 + V_12 ;
V_10 = F_2 ( V_10 , V_11 ) ;
return V_10 ;
}
static T_1 F_3 ( T_1 V_2 , T_1 V_3 )
{
T_1 V_13 = F_2 ( V_3 , 32 ) * F_2 ( V_2 , 32 ) * 3 / 2 / 2 ;
return F_2 ( V_13 , V_11 ) ;
}
static const struct V_14 *
F_4 ( struct V_15 * V_16 , T_1 V_17 , T_1 type )
{
const struct V_14 * V_18 = V_19 ;
unsigned int V_10 = F_5 ( V_19 ) ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
if ( V_18 [ V_20 ] . V_17 == V_17 )
break;
}
if ( V_20 == V_10 || V_18 [ V_20 ] . type != type )
return NULL ;
if ( type == V_21 &&
! F_6 ( V_16 , V_18 [ V_20 ] . V_17 ) )
return NULL ;
return & V_18 [ V_20 ] ;
}
static const struct V_14 *
F_7 ( struct V_15 * V_16 , unsigned int V_22 , T_1 type )
{
const struct V_14 * V_18 = V_19 ;
unsigned int V_10 = F_5 ( V_19 ) ;
unsigned int V_20 , V_23 = 0 ;
if ( V_22 > V_10 )
return NULL ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
if ( V_18 [ V_20 ] . type != type )
continue;
if ( V_23 == V_22 )
break;
V_23 ++ ;
}
if ( V_20 == V_10 )
return NULL ;
if ( type == V_21 &&
! F_6 ( V_16 , V_18 [ V_20 ] . V_17 ) )
return NULL ;
return & V_18 [ V_20 ] ;
}
static int F_8 ( int V_24 , int V_25 )
{
switch ( V_24 ) {
case V_26 :
switch ( V_25 ) {
case V_27 :
default:
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
}
case V_41 :
switch ( V_25 ) {
case V_42 :
default:
return V_43 ;
case V_44 :
return V_45 ;
}
case V_46 :
switch ( V_25 ) {
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
default:
return V_54 ;
}
case V_55 :
switch ( V_25 ) {
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
case V_60 :
return V_61 ;
case V_62 :
return V_63 ;
case V_64 :
return V_65 ;
case V_66 :
return V_67 ;
case V_68 :
return V_69 ;
case V_70 :
return V_71 ;
case V_72 :
return V_73 ;
case V_74 :
return V_75 ;
case V_76 :
return V_77 ;
case V_78 :
return V_79 ;
case V_80 :
return V_81 ;
case V_82 :
return V_83 ;
case V_84 :
default:
return V_85 ;
case V_86 :
return V_87 ;
}
case V_88 :
switch ( V_25 ) {
case V_89 :
default:
return V_90 ;
case V_91 :
return V_92 ;
}
case V_93 :
switch ( V_25 ) {
case 0 :
default:
return V_94 ;
case 1 :
return V_95 ;
case 2 :
return V_96 ;
case 3 :
return V_97 ;
}
}
return 0 ;
}
static int
F_9 ( struct V_98 * V_98 , void * V_99 , struct V_100 * V_101 )
{
F_10 ( V_101 -> V_102 , L_1 , sizeof( V_101 -> V_102 ) ) ;
F_10 ( V_101 -> V_103 , L_2 , sizeof( V_101 -> V_103 ) ) ;
F_10 ( V_101 -> V_104 , L_3 , sizeof( V_101 -> V_104 ) ) ;
return 0 ;
}
static int F_11 ( struct V_98 * V_98 , void * V_99 , struct V_105 * V_106 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
const struct V_14 * V_18 ;
V_18 = F_7 ( V_16 , V_106 -> V_22 , V_106 -> type ) ;
memset ( V_106 -> V_107 , 0 , sizeof( V_106 -> V_107 ) ) ;
if ( ! V_18 )
return - V_108 ;
V_106 -> V_109 = V_18 -> V_17 ;
return 0 ;
}
static const struct V_14 *
F_13 ( struct V_15 * V_16 , struct V_110 * V_106 )
{
struct V_111 * V_112 = & V_106 -> V_18 . V_113 ;
struct V_114 * V_115 = V_112 -> V_116 ;
const struct V_14 * V_18 ;
unsigned int V_117 ;
memset ( V_115 [ 0 ] . V_107 , 0 , sizeof( V_115 [ 0 ] . V_107 ) ) ;
memset ( V_112 -> V_107 , 0 , sizeof( V_112 -> V_107 ) ) ;
V_18 = F_4 ( V_16 , V_112 -> V_109 , V_106 -> type ) ;
if ( ! V_18 ) {
if ( V_106 -> type == V_21 )
V_112 -> V_109 = V_118 ;
else if ( V_106 -> type == V_119 )
V_112 -> V_109 = V_120 ;
else
return NULL ;
V_18 = F_4 ( V_16 , V_112 -> V_109 , V_106 -> type ) ;
V_112 -> V_2 = 1280 ;
V_112 -> V_3 = 720 ;
}
V_112 -> V_2 = F_14 ( V_112 -> V_2 , V_16 -> V_121 . V_122 ,
V_16 -> V_121 . V_123 ) ;
V_112 -> V_3 = F_14 ( V_112 -> V_3 , V_16 -> V_124 . V_122 ,
V_16 -> V_124 . V_123 ) ;
if ( V_106 -> type == V_119 )
V_112 -> V_3 = F_2 ( V_112 -> V_3 , 32 ) ;
V_112 -> V_2 = F_2 ( V_112 -> V_2 , 2 ) ;
V_112 -> V_3 = F_2 ( V_112 -> V_3 , 2 ) ;
if ( V_112 -> V_125 == V_126 )
V_112 -> V_125 = V_127 ;
V_112 -> V_128 = V_18 -> V_128 ;
V_112 -> V_129 = 0 ;
if ( V_106 -> type == V_119 ) {
for ( V_117 = 0 ; V_117 < V_112 -> V_128 ; V_117 ++ ) {
V_115 [ V_117 ] . V_130 =
F_1 ( V_117 , V_112 -> V_2 ,
V_112 -> V_3 ) ;
V_115 [ V_117 ] . V_131 = F_2 ( V_112 -> V_2 , 128 ) ;
}
} else {
V_115 [ 0 ] . V_130 = F_3 ( V_112 -> V_2 ,
V_112 -> V_3 ) ;
V_115 [ 0 ] . V_131 = 0 ;
}
return V_18 ;
}
static int F_15 ( struct V_98 * V_98 , void * V_99 , struct V_110 * V_106 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
F_13 ( V_16 , V_106 ) ;
return 0 ;
}
static int F_16 ( struct V_98 * V_98 , void * V_99 , struct V_110 * V_106 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
struct V_111 * V_112 = & V_106 -> V_18 . V_113 ;
struct V_111 V_132 ;
const struct V_14 * V_18 ;
struct V_110 V_133 ;
T_1 V_134 = 0 , V_135 = 0 ;
V_132 = * V_112 ;
V_18 = F_13 ( V_16 , V_106 ) ;
if ( ! V_18 )
return - V_108 ;
if ( V_106 -> type == V_119 ) {
V_134 = V_112 -> V_109 ;
V_135 = V_16 -> V_136 -> V_17 ;
} else if ( V_106 -> type == V_21 ) {
V_135 = V_112 -> V_109 ;
V_134 = V_16 -> V_137 -> V_17 ;
}
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . type = V_119 ;
V_133 . V_18 . V_113 . V_109 = V_134 ;
V_133 . V_18 . V_113 . V_2 = V_132 . V_2 ;
V_133 . V_18 . V_113 . V_3 = V_132 . V_3 ;
F_13 ( V_16 , & V_133 ) ;
if ( V_106 -> type == V_119 ) {
V_16 -> V_138 = V_133 . V_18 . V_113 . V_2 ;
V_16 -> V_139 = V_133 . V_18 . V_113 . V_3 ;
V_16 -> V_140 = V_112 -> V_140 ;
V_16 -> V_141 = V_112 -> V_141 ;
V_16 -> V_142 = V_112 -> V_142 ;
V_16 -> V_143 = V_112 -> V_143 ;
}
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . type = V_21 ;
V_133 . V_18 . V_113 . V_109 = V_135 ;
V_133 . V_18 . V_113 . V_2 = V_132 . V_2 ;
V_133 . V_18 . V_113 . V_3 = V_132 . V_3 ;
F_13 ( V_16 , & V_133 ) ;
V_16 -> V_2 = V_133 . V_18 . V_113 . V_2 ;
V_16 -> V_3 = V_133 . V_18 . V_113 . V_3 ;
if ( V_106 -> type == V_119 )
V_16 -> V_137 = V_18 ;
else if ( V_106 -> type == V_21 )
V_16 -> V_136 = V_18 ;
return 0 ;
}
static int F_17 ( struct V_98 * V_98 , void * V_99 , struct V_110 * V_106 )
{
struct V_111 * V_112 = & V_106 -> V_18 . V_113 ;
struct V_15 * V_16 = F_12 ( V_98 ) ;
const struct V_14 * V_18 ;
if ( V_106 -> type == V_21 )
V_18 = V_16 -> V_136 ;
else if ( V_106 -> type == V_119 )
V_18 = V_16 -> V_137 ;
else
return - V_108 ;
V_112 -> V_109 = V_18 -> V_17 ;
if ( V_106 -> type == V_21 ) {
V_112 -> V_2 = V_16 -> V_2 ;
V_112 -> V_3 = V_16 -> V_3 ;
V_112 -> V_140 = V_16 -> V_140 ;
V_112 -> V_141 = V_16 -> V_141 ;
V_112 -> V_142 = V_16 -> V_142 ;
V_112 -> V_143 = V_16 -> V_143 ;
} else if ( V_106 -> type == V_119 ) {
V_112 -> V_2 = V_16 -> V_138 ;
V_112 -> V_3 = V_16 -> V_139 ;
}
F_13 ( V_16 , V_106 ) ;
return 0 ;
}
static int
F_18 ( struct V_98 * V_98 , void * V_99 , struct V_144 * V_145 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
if ( V_145 -> type != V_146 )
return - V_108 ;
switch ( V_145 -> V_147 ) {
case V_148 :
case V_149 :
V_145 -> V_150 . V_2 = V_16 -> V_2 ;
V_145 -> V_150 . V_3 = V_16 -> V_3 ;
break;
case V_151 :
V_145 -> V_150 . V_2 = V_16 -> V_138 ;
V_145 -> V_150 . V_3 = V_16 -> V_139 ;
break;
default:
return - V_108 ;
}
V_145 -> V_150 . V_152 = 0 ;
V_145 -> V_150 . V_153 = 0 ;
return 0 ;
}
static int
F_19 ( struct V_98 * V_98 , void * V_99 , struct V_144 * V_145 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
if ( V_145 -> type != V_146 )
return - V_108 ;
switch ( V_145 -> V_147 ) {
case V_151 :
if ( V_145 -> V_150 . V_2 != V_16 -> V_138 ||
V_145 -> V_150 . V_3 != V_16 -> V_139 ||
V_145 -> V_150 . V_152 != 0 || V_145 -> V_150 . V_153 != 0 )
return - V_108 ;
break;
default:
return - V_108 ;
}
return 0 ;
}
static int F_20 ( struct V_98 * V_98 , void * V_99 , struct V_154 * V_155 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
struct V_156 * V_157 = & V_155 -> V_158 . V_159 ;
struct V_160 * V_161 = & V_157 -> V_161 ;
T_2 V_162 , V_163 ;
if ( V_155 -> type != V_21 &&
V_155 -> type != V_119 )
return - V_108 ;
memset ( V_157 -> V_107 , 0 , sizeof( V_157 -> V_107 ) ) ;
if ( ! V_161 -> V_164 )
V_161 -> V_164 = V_16 -> V_161 . V_164 ;
if ( ! V_161 -> V_165 )
V_161 -> V_165 = V_16 -> V_161 . V_165 ;
V_157 -> V_166 = V_167 ;
V_162 = V_161 -> V_165 * ( T_2 ) V_168 ;
F_21 ( V_162 , V_161 -> V_164 ) ;
if ( ! V_162 )
return - V_108 ;
V_163 = ( T_2 ) V_168 ;
F_21 ( V_163 , V_162 ) ;
V_16 -> V_161 = * V_161 ;
V_16 -> V_163 = V_163 ;
return 0 ;
}
static int F_22 ( struct V_98 * V_98 , void * V_99 , struct V_154 * V_155 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
if ( V_155 -> type != V_21 &&
V_155 -> type != V_119 )
return - V_108 ;
V_155 -> V_158 . V_159 . V_166 |= V_167 ;
V_155 -> V_158 . V_159 . V_161 = V_16 -> V_161 ;
return 0 ;
}
static int F_23 ( struct V_98 * V_98 , void * V_99 ,
struct V_169 * V_170 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
const struct V_14 * V_18 ;
V_170 -> type = V_171 ;
V_18 = F_4 ( V_16 , V_170 -> V_172 ,
V_21 ) ;
if ( ! V_18 ) {
V_18 = F_4 ( V_16 , V_170 -> V_172 ,
V_119 ) ;
if ( ! V_18 )
return - V_108 ;
}
if ( V_170 -> V_22 )
return - V_108 ;
V_170 -> V_173 . V_174 = V_16 -> V_121 . V_122 ;
V_170 -> V_173 . V_175 = V_16 -> V_121 . V_123 ;
V_170 -> V_173 . V_176 = V_16 -> V_121 . V_177 ;
V_170 -> V_173 . V_178 = V_16 -> V_124 . V_122 ;
V_170 -> V_173 . V_179 = V_16 -> V_124 . V_123 ;
V_170 -> V_173 . V_180 = V_16 -> V_124 . V_177 ;
return 0 ;
}
static int F_24 ( struct V_98 * V_98 , void * V_99 ,
struct V_181 * V_182 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
const struct V_14 * V_18 ;
V_182 -> type = V_183 ;
V_18 = F_4 ( V_16 , V_182 -> V_172 ,
V_21 ) ;
if ( ! V_18 ) {
V_18 = F_4 ( V_16 , V_182 -> V_172 ,
V_119 ) ;
if ( ! V_18 )
return - V_108 ;
}
if ( V_182 -> V_22 )
return - V_108 ;
if ( ! V_182 -> V_2 || ! V_182 -> V_3 )
return - V_108 ;
if ( V_182 -> V_2 > V_16 -> V_121 . V_123 ||
V_182 -> V_2 < V_16 -> V_121 . V_122 ||
V_182 -> V_3 > V_16 -> V_124 . V_123 ||
V_182 -> V_3 < V_16 -> V_124 . V_122 )
return - V_108 ;
V_182 -> V_173 . V_122 . V_165 = 1 ;
V_182 -> V_173 . V_122 . V_164 = V_16 -> V_184 . V_123 ;
V_182 -> V_173 . V_123 . V_165 = 1 ;
V_182 -> V_173 . V_123 . V_164 = V_16 -> V_184 . V_122 ;
V_182 -> V_173 . V_185 . V_165 = 1 ;
V_182 -> V_173 . V_185 . V_164 = V_16 -> V_184 . V_123 ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_186 * V_187 = & V_16 -> V_188 . V_189 ;
struct V_190 V_191 ;
struct V_192 V_193 ;
struct V_194 V_195 ;
struct V_196 V_197 ;
struct V_198 V_199 ;
T_1 V_200 , V_201 , V_202 , V_203 = 0 , V_204 = 0 ;
int V_205 ;
V_200 = V_206 ;
V_195 . V_207 = V_208 ;
V_195 . V_209 = V_16 -> V_163 * ( 1 << 16 ) ;
V_205 = F_26 ( V_16 , V_200 , & V_195 ) ;
if ( V_205 )
return V_205 ;
if ( V_16 -> V_136 -> V_17 == V_118 ) {
struct V_210 V_211 ;
V_200 = V_212 ;
V_211 . V_213 = 1 ;
V_211 . V_214 = 1 ;
V_211 . V_215 = V_216 ;
V_205 = F_26 ( V_16 , V_200 , & V_211 ) ;
if ( V_205 )
return V_205 ;
}
V_200 = V_217 ;
V_199 . V_218 = V_187 -> V_219 ;
V_205 = F_26 ( V_16 , V_200 , & V_199 ) ;
if ( V_205 )
return V_205 ;
if ( V_187 -> V_220 ) {
T_1 V_221 = V_222 ;
V_200 = V_223 ;
V_205 = F_26 ( V_16 , V_200 , & V_221 ) ;
if ( V_205 )
return V_205 ;
}
if ( ! V_187 -> V_224 )
V_187 -> V_224 = 2 * 15 - 1 ,
V_200 = V_225 ;
V_191 . V_226 = V_187 -> V_224 ;
V_191 . V_227 = V_187 -> V_220 ;
V_205 = F_26 ( V_16 , V_200 , & V_191 ) ;
if ( V_205 )
return V_205 ;
if ( V_187 -> V_228 == V_229 )
V_201 = V_230 ;
else
V_201 = V_231 ;
V_200 = V_232 ;
V_205 = F_26 ( V_16 , V_200 , & V_201 ) ;
if ( V_205 )
return V_205 ;
if ( ! V_187 -> V_202 )
V_202 = 64000 ;
else
V_202 = V_187 -> V_202 ;
V_200 = V_233 ;
V_197 . V_202 = V_202 ;
V_197 . V_234 = 0 ;
V_205 = F_26 ( V_16 , V_200 , & V_197 ) ;
if ( V_205 )
return V_205 ;
if ( ! V_187 -> V_235 )
V_202 *= 2 ;
else
V_202 = V_187 -> V_235 ;
V_200 = V_236 ;
V_197 . V_202 = V_202 ;
V_197 . V_234 = 0 ;
V_205 = F_26 ( V_16 , V_200 , & V_197 ) ;
if ( V_205 )
return V_205 ;
if ( V_16 -> V_136 -> V_17 == V_118 ) {
V_203 = F_8 ( V_46 ,
V_187 -> V_203 . V_237 ) ;
V_204 = F_8 ( V_55 ,
V_187 -> V_204 . V_237 ) ;
} else if ( V_16 -> V_136 -> V_17 == V_238 ) {
V_203 = F_8 ( V_93 ,
V_187 -> V_203 . V_239 ) ;
V_204 = 0 ;
} else if ( V_16 -> V_136 -> V_17 == V_240 ) {
V_203 = F_8 ( V_41 ,
V_187 -> V_203 . V_241 ) ;
V_204 = F_8 ( V_26 ,
V_187 -> V_204 . V_241 ) ;
} else if ( V_16 -> V_136 -> V_17 == V_242 ) {
V_203 = 0 ;
V_204 = 0 ;
}
V_200 = V_243 ;
V_193 . V_203 = V_203 ;
V_193 . V_204 = V_204 ;
V_205 = F_26 ( V_16 , V_200 , & V_193 ) ;
if ( V_205 )
return V_205 ;
return 0 ;
}
static int F_27 ( struct V_15 * V_16 )
{
int V_205 ;
V_205 = F_28 ( V_16 , V_16 -> V_136 -> V_17 ) ;
if ( V_205 )
return V_205 ;
V_205 = F_29 ( V_16 , V_16 -> V_2 ,
V_16 -> V_3 ) ;
if ( V_205 )
goto V_244;
V_205 = F_30 ( V_16 , V_16 -> V_2 ,
V_16 -> V_3 ) ;
if ( V_205 )
goto V_244;
V_205 = F_31 ( V_16 , V_16 -> V_137 -> V_17 ) ;
if ( V_205 )
goto V_244;
return 0 ;
V_244:
F_32 ( V_16 ) ;
return V_205 ;
}
static int F_33 ( struct V_15 * V_16 , unsigned int * V_245 )
{
struct V_246 V_247 ;
int V_205 ;
V_205 = F_27 ( V_16 ) ;
if ( V_205 )
return V_205 ;
V_205 = F_34 ( V_16 , V_248 , & V_247 ) ;
* V_245 = V_247 . V_249 ;
F_32 ( V_16 ) ;
return V_205 ;
}
static int F_35 ( struct V_250 * V_251 ,
unsigned int * V_252 , unsigned int * V_128 ,
unsigned int V_253 [] , struct V_254 * V_255 [] )
{
struct V_15 * V_16 = F_36 ( V_251 ) ;
unsigned int V_117 , V_245 , V_122 = 4 ;
int V_205 = 0 ;
if ( * V_128 ) {
if ( V_251 -> type == V_119 &&
* V_128 != V_16 -> V_137 -> V_128 )
return - V_108 ;
if ( V_251 -> type == V_21 &&
* V_128 != V_16 -> V_136 -> V_128 )
return - V_108 ;
if ( V_251 -> type == V_119 &&
V_253 [ 0 ] < V_16 -> V_256 )
return - V_108 ;
if ( V_251 -> type == V_21 &&
V_253 [ 0 ] < V_16 -> V_257 )
return - V_108 ;
return 0 ;
}
switch ( V_251 -> type ) {
case V_119 :
* V_128 = V_16 -> V_137 -> V_128 ;
V_205 = F_33 ( V_16 , & V_245 ) ;
if ( V_205 )
break;
V_245 = V_123 ( V_245 , V_122 ) ;
* V_252 = V_123 ( * V_252 , V_245 ) ;
V_16 -> V_258 = * V_252 ;
for ( V_117 = 0 ; V_117 < * V_128 ; ++ V_117 )
V_253 [ V_117 ] = F_1 ( V_117 , V_16 -> V_2 ,
V_16 -> V_3 ) ;
V_16 -> V_256 = V_253 [ 0 ] ;
break;
case V_21 :
* V_128 = V_16 -> V_136 -> V_128 ;
* V_252 = V_123 ( * V_252 , V_122 ) ;
V_16 -> V_259 = * V_252 ;
V_253 [ 0 ] = F_3 ( V_16 -> V_2 , V_16 -> V_3 ) ;
V_16 -> V_257 = V_253 [ 0 ] ;
break;
default:
V_205 = - V_108 ;
break;
}
return V_205 ;
}
static int F_37 ( struct V_15 * V_16 )
{
struct V_246 V_247 ;
int V_205 ;
if ( ! V_16 -> V_258 || ! V_16 -> V_259 )
return - V_108 ;
V_205 = F_34 ( V_16 , V_208 , & V_247 ) ;
if ( V_205 )
return V_205 ;
if ( V_16 -> V_259 < V_247 . V_249 ||
V_16 -> V_259 < V_247 . V_260 )
return - V_108 ;
V_205 = F_34 ( V_16 , V_248 , & V_247 ) ;
if ( V_205 )
return V_205 ;
if ( V_16 -> V_258 < V_247 . V_249 ||
V_16 -> V_258 < V_247 . V_260 )
return - V_108 ;
return 0 ;
}
static int F_38 ( struct V_250 * V_251 , unsigned int V_261 )
{
struct V_15 * V_16 = F_36 ( V_251 ) ;
int V_205 ;
F_39 ( & V_16 -> V_262 ) ;
if ( V_251 -> type == V_119 )
V_16 -> V_263 = 1 ;
else
V_16 -> V_264 = 1 ;
if ( ! ( V_16 -> V_263 & V_16 -> V_264 ) ) {
F_40 ( & V_16 -> V_262 ) ;
return 0 ;
}
F_41 ( V_16 ) ;
V_16 -> V_265 = 0 ;
V_16 -> V_266 = 0 ;
V_205 = F_27 ( V_16 ) ;
if ( V_205 )
goto V_267;
V_205 = F_25 ( V_16 ) ;
if ( V_205 )
goto V_268;
V_205 = F_37 ( V_16 ) ;
if ( V_205 )
goto V_268;
V_205 = F_42 ( V_16 , V_16 -> V_258 ,
V_16 -> V_259 ) ;
if ( V_205 )
goto V_268;
V_205 = F_43 ( V_16 ) ;
if ( V_205 )
goto V_268;
F_40 ( & V_16 -> V_262 ) ;
return 0 ;
V_268:
F_32 ( V_16 ) ;
V_267:
F_44 ( V_16 , V_269 ) ;
if ( V_251 -> type == V_119 )
V_16 -> V_263 = 0 ;
else
V_16 -> V_264 = 0 ;
F_40 ( & V_16 -> V_262 ) ;
return V_205 ;
}
static void F_45 ( struct V_15 * V_16 , unsigned int V_270 ,
T_1 V_271 , T_1 V_272 , T_1 V_273 , T_1 V_129 ,
T_1 V_274 , T_2 V_275 )
{
struct V_276 * V_277 ;
struct V_278 * V_279 ;
unsigned int type ;
if ( V_270 == V_248 )
type = V_119 ;
else
type = V_21 ;
V_277 = F_46 ( V_16 , type , V_271 ) ;
if ( ! V_277 )
return;
V_279 = & V_277 -> V_280 ;
V_279 -> V_281 [ 0 ] . V_272 = V_272 ;
V_279 -> V_281 [ 0 ] . V_273 = V_273 ;
V_277 -> V_129 = V_129 ;
if ( type == V_21 ) {
V_279 -> V_282 = V_275 * V_283 ;
V_277 -> V_284 = V_16 -> V_265 ++ ;
} else {
V_277 -> V_284 = V_16 -> V_266 ++ ;
}
F_47 ( V_277 , V_285 ) ;
}
static void F_48 ( struct V_15 * V_16 , T_1 V_286 ,
struct V_287 * V_288 )
{
struct V_254 * V_289 = V_16 -> V_290 -> V_291 ;
if ( V_286 == V_292 ) {
V_16 -> V_293 = true ;
F_49 ( V_289 , L_4 , V_16 -> error ) ;
}
}
static int F_50 ( void * V_294 , struct V_250 * V_295 ,
struct V_250 * V_296 )
{
struct V_15 * V_16 = V_294 ;
int V_205 ;
V_295 -> type = V_119 ;
V_295 -> V_297 = V_298 | V_299 ;
V_295 -> V_300 = V_301 ;
V_295 -> V_302 = & V_303 ;
V_295 -> V_304 = & V_305 ;
V_295 -> V_306 = V_16 ;
V_295 -> V_307 = sizeof( struct V_308 ) ;
V_295 -> V_309 = 1 ;
V_295 -> V_310 = 1 ;
V_295 -> V_289 = V_16 -> V_290 -> V_289 ;
if ( V_16 -> V_290 -> V_311 -> V_312 == V_313 )
V_295 -> V_314 = 1 ;
V_205 = F_51 ( V_295 ) ;
if ( V_205 )
return V_205 ;
V_296 -> type = V_21 ;
V_296 -> V_297 = V_298 | V_299 ;
V_296 -> V_300 = V_301 ;
V_296 -> V_302 = & V_303 ;
V_296 -> V_304 = & V_305 ;
V_296 -> V_306 = V_16 ;
V_296 -> V_307 = sizeof( struct V_308 ) ;
V_296 -> V_309 = 1 ;
V_296 -> V_310 = 1 ;
V_296 -> V_289 = V_16 -> V_290 -> V_289 ;
V_205 = F_51 ( V_296 ) ;
if ( V_205 ) {
F_52 ( V_295 ) ;
return V_205 ;
}
return 0 ;
}
static void F_53 ( struct V_15 * V_16 )
{
V_16 -> V_136 = & V_19 [ 2 ] ;
V_16 -> V_137 = & V_19 [ 0 ] ;
V_16 -> V_2 = 1280 ;
V_16 -> V_3 = F_2 ( 720 , 32 ) ;
V_16 -> V_138 = 1280 ;
V_16 -> V_139 = 720 ;
V_16 -> V_163 = 15 ;
V_16 -> V_161 . V_165 = 1 ;
V_16 -> V_161 . V_164 = 15 ;
V_16 -> V_121 . V_122 = 96 ;
V_16 -> V_121 . V_123 = 1920 ;
if ( V_16 -> V_290 -> V_311 -> V_312 == V_315 )
V_16 -> V_121 . V_123 = 3840 ;
V_16 -> V_121 . V_177 = 2 ;
V_16 -> V_124 . V_122 = 64 ;
V_16 -> V_124 . V_123 = F_2 ( 1080 , 32 ) ;
if ( V_16 -> V_290 -> V_311 -> V_312 == V_315 )
V_16 -> V_124 . V_123 = F_2 ( 2160 , 32 ) ;
V_16 -> V_124 . V_177 = 2 ;
V_16 -> V_184 . V_122 = 1 ;
V_16 -> V_184 . V_123 = 30 ;
V_16 -> V_184 . V_177 = 1 ;
V_16 -> V_316 . V_122 = 24 ;
V_16 -> V_316 . V_123 = 8160 ;
}
static int F_54 ( struct V_98 * V_98 )
{
struct V_317 * V_290 = F_55 ( V_98 ) ;
struct V_15 * V_16 ;
int V_205 ;
V_16 = F_56 ( sizeof( * V_16 ) , V_318 ) ;
if ( ! V_16 )
return - V_319 ;
F_57 ( & V_16 -> V_320 ) ;
F_57 ( & V_16 -> V_321 ) ;
F_57 ( & V_16 -> V_322 ) ;
F_58 ( & V_16 -> V_262 ) ;
V_16 -> V_290 = V_290 ;
V_16 -> V_323 = V_324 ;
F_41 ( V_16 ) ;
V_205 = F_59 ( V_290 -> V_291 ) ;
if ( V_205 < 0 )
goto V_325;
V_205 = F_60 ( V_16 ) ;
if ( V_205 )
goto V_326;
V_205 = F_61 ( V_16 , & V_327 ) ;
if ( V_205 )
goto V_328;
F_53 ( V_16 ) ;
V_16 -> V_329 = F_62 ( & V_330 ) ;
if ( F_63 ( V_16 -> V_329 ) ) {
V_205 = F_64 ( V_16 -> V_329 ) ;
goto V_331;
}
V_16 -> V_332 = F_65 ( V_16 -> V_329 , V_16 , F_50 ) ;
if ( F_63 ( V_16 -> V_332 ) ) {
V_205 = F_64 ( V_16 -> V_332 ) ;
goto V_333;
}
F_66 ( & V_16 -> V_99 , V_290 -> V_334 ) ;
V_16 -> V_99 . V_335 = & V_16 -> V_335 ;
F_67 ( & V_16 -> V_99 ) ;
V_16 -> V_99 . V_332 = V_16 -> V_332 ;
V_98 -> V_336 = & V_16 -> V_99 ;
return 0 ;
V_333:
F_68 ( V_16 -> V_329 ) ;
V_331:
F_69 ( V_16 ) ;
V_328:
F_70 ( V_16 ) ;
V_326:
F_71 ( V_290 -> V_291 ) ;
V_325:
F_72 ( V_16 ) ;
return V_205 ;
}
static int F_73 ( struct V_98 * V_98 )
{
struct V_15 * V_16 = F_12 ( V_98 ) ;
F_74 ( V_16 -> V_332 ) ;
F_68 ( V_16 -> V_329 ) ;
F_70 ( V_16 ) ;
F_69 ( V_16 ) ;
F_75 ( & V_16 -> V_262 ) ;
F_76 ( & V_16 -> V_99 ) ;
F_77 ( & V_16 -> V_99 ) ;
F_71 ( V_16 -> V_290 -> V_291 ) ;
F_72 ( V_16 ) ;
return 0 ;
}
static int F_78 ( struct V_337 * V_338 )
{
struct V_254 * V_289 = & V_338 -> V_289 ;
struct V_339 * V_340 ;
struct V_317 * V_290 ;
int V_205 ;
if ( ! V_289 -> V_341 )
return - V_342 ;
V_290 = F_79 ( V_289 -> V_341 ) ;
if ( ! V_290 )
return - V_342 ;
if ( V_290 -> V_311 -> V_312 == V_315 ) {
V_290 -> V_343 = F_80 ( V_289 , L_5 ) ;
if ( F_63 ( V_290 -> V_343 ) )
return F_64 ( V_290 -> V_343 ) ;
}
F_81 ( V_338 , V_290 ) ;
V_340 = F_82 () ;
if ( ! V_340 )
return - V_319 ;
F_10 ( V_340 -> V_344 , L_6 , sizeof( V_340 -> V_344 ) ) ;
V_340 -> V_345 = V_346 ;
V_340 -> V_347 = & V_348 ;
V_340 -> V_349 = & V_350 ;
V_340 -> V_351 = V_352 ;
V_340 -> V_353 = & V_290 -> V_353 ;
V_340 -> V_354 = V_355 | V_356 ;
V_205 = F_83 ( V_340 , V_357 , - 1 ) ;
if ( V_205 )
goto V_358;
V_290 -> V_334 = V_340 ;
V_290 -> V_291 = V_289 ;
F_84 ( V_340 , V_290 ) ;
F_85 ( V_289 ) ;
return 0 ;
V_358:
V_346 ( V_340 ) ;
return V_205 ;
}
static int F_86 ( struct V_337 * V_338 )
{
struct V_317 * V_290 = F_79 ( V_338 -> V_289 . V_341 ) ;
F_87 ( V_290 -> V_334 ) ;
F_88 ( V_290 -> V_291 ) ;
return 0 ;
}
static T_3 int F_89 ( struct V_254 * V_289 )
{
struct V_317 * V_290 = F_79 ( V_289 ) ;
if ( V_290 -> V_311 -> V_312 == V_313 )
return 0 ;
F_90 ( 0 , V_290 -> V_359 + V_360 ) ;
F_91 ( V_290 -> V_343 ) ;
F_90 ( 1 , V_290 -> V_359 + V_360 ) ;
return 0 ;
}
static T_3 int F_92 ( struct V_254 * V_289 )
{
struct V_317 * V_290 = F_79 ( V_289 ) ;
int V_205 ;
if ( V_290 -> V_311 -> V_312 == V_313 )
return 0 ;
F_90 ( 0 , V_290 -> V_359 + V_360 ) ;
V_205 = F_93 ( V_290 -> V_343 ) ;
F_90 ( 1 , V_290 -> V_359 + V_360 ) ;
return V_205 ;
}
