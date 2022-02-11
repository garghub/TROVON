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
static const struct V_14 * F_4 ( T_1 V_15 , T_1 type )
{
const struct V_14 * V_16 = V_17 ;
unsigned int V_10 = F_5 ( V_17 ) ;
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_10 ; V_18 ++ ) {
if ( V_16 [ V_18 ] . V_15 == V_15 )
break;
}
if ( V_18 == V_10 || V_16 [ V_18 ] . type != type )
return NULL ;
return & V_16 [ V_18 ] ;
}
static const struct V_14 *
F_6 ( unsigned int V_19 , T_1 type )
{
const struct V_14 * V_16 = V_17 ;
unsigned int V_10 = F_5 ( V_17 ) ;
unsigned int V_18 , V_20 = 0 ;
if ( V_19 > V_10 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_10 ; V_18 ++ ) {
if ( V_16 [ V_18 ] . type != type )
continue;
if ( V_20 == V_19 )
break;
V_20 ++ ;
}
if ( V_18 == V_10 )
return NULL ;
return & V_16 [ V_18 ] ;
}
static int F_7 ( int V_21 , int V_22 )
{
switch ( V_21 ) {
case V_23 :
switch ( V_22 ) {
case V_24 :
default:
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
}
case V_38 :
switch ( V_22 ) {
case V_39 :
default:
return V_40 ;
case V_41 :
return V_42 ;
}
case V_43 :
switch ( V_22 ) {
case V_44 :
return V_45 ;
case V_46 :
return V_47 ;
case V_48 :
return V_49 ;
case V_50 :
default:
return V_51 ;
}
case V_52 :
switch ( V_22 ) {
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
case V_57 :
return V_58 ;
case V_59 :
return V_60 ;
case V_61 :
return V_62 ;
case V_63 :
return V_64 ;
case V_65 :
return V_66 ;
case V_67 :
return V_68 ;
case V_69 :
return V_70 ;
case V_71 :
return V_72 ;
case V_73 :
return V_74 ;
case V_75 :
return V_76 ;
case V_77 :
return V_78 ;
case V_79 :
return V_80 ;
case V_81 :
default:
return V_82 ;
case V_83 :
return V_84 ;
}
case V_85 :
switch ( V_22 ) {
case V_86 :
default:
return V_87 ;
case V_88 :
return V_89 ;
}
case V_90 :
switch ( V_22 ) {
case 0 :
default:
return V_91 ;
case 1 :
return V_92 ;
case 2 :
return V_93 ;
case 3 :
return V_94 ;
}
}
return 0 ;
}
static int
F_8 ( struct V_95 * V_95 , void * V_96 , struct V_97 * V_98 )
{
F_9 ( V_98 -> V_99 , L_1 , sizeof( V_98 -> V_99 ) ) ;
F_9 ( V_98 -> V_100 , L_2 , sizeof( V_98 -> V_100 ) ) ;
F_9 ( V_98 -> V_101 , L_3 , sizeof( V_98 -> V_101 ) ) ;
return 0 ;
}
static int F_10 ( struct V_95 * V_95 , void * V_96 , struct V_102 * V_103 )
{
const struct V_14 * V_16 ;
V_16 = F_6 ( V_103 -> V_19 , V_103 -> type ) ;
memset ( V_103 -> V_104 , 0 , sizeof( V_103 -> V_104 ) ) ;
if ( ! V_16 )
return - V_105 ;
V_103 -> V_106 = V_16 -> V_15 ;
return 0 ;
}
static const struct V_14 *
F_11 ( struct V_107 * V_108 , struct V_109 * V_103 )
{
struct V_110 * V_111 = & V_103 -> V_16 . V_112 ;
struct V_113 * V_114 = V_111 -> V_115 ;
const struct V_14 * V_16 ;
unsigned int V_116 ;
memset ( V_114 [ 0 ] . V_104 , 0 , sizeof( V_114 [ 0 ] . V_104 ) ) ;
memset ( V_111 -> V_104 , 0 , sizeof( V_111 -> V_104 ) ) ;
V_16 = F_4 ( V_111 -> V_106 , V_103 -> type ) ;
if ( ! V_16 ) {
if ( V_103 -> type == V_117 )
V_111 -> V_106 = V_118 ;
else if ( V_103 -> type == V_119 )
V_111 -> V_106 = V_120 ;
else
return NULL ;
V_16 = F_4 ( V_111 -> V_106 , V_103 -> type ) ;
V_111 -> V_2 = 1280 ;
V_111 -> V_3 = 720 ;
}
V_111 -> V_2 = F_12 ( V_111 -> V_2 , V_108 -> V_121 . V_122 ,
V_108 -> V_121 . V_123 ) ;
V_111 -> V_3 = F_12 ( V_111 -> V_3 , V_108 -> V_124 . V_122 ,
V_108 -> V_124 . V_123 ) ;
if ( V_108 -> V_125 -> V_126 -> V_127 == V_128 )
V_111 -> V_3 = F_2 ( V_111 -> V_3 , 32 ) ;
V_111 -> V_2 = F_2 ( V_111 -> V_2 , 2 ) ;
V_111 -> V_3 = F_2 ( V_111 -> V_3 , 2 ) ;
if ( V_111 -> V_129 == V_130 )
V_111 -> V_129 = V_131 ;
V_111 -> V_132 = V_16 -> V_132 ;
V_111 -> V_133 = 0 ;
if ( V_103 -> type == V_119 ) {
for ( V_116 = 0 ; V_116 < V_111 -> V_132 ; V_116 ++ ) {
V_114 [ V_116 ] . V_134 =
F_1 ( V_116 , V_111 -> V_2 ,
V_111 -> V_3 ) ;
V_114 [ V_116 ] . V_135 = F_2 ( V_111 -> V_2 , 128 ) ;
}
} else {
V_114 [ 0 ] . V_134 = F_3 ( V_111 -> V_2 ,
V_111 -> V_3 ) ;
V_114 [ 0 ] . V_135 = 0 ;
}
return V_16 ;
}
static int F_13 ( struct V_95 * V_95 , void * V_96 , struct V_109 * V_103 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
F_11 ( V_108 , V_103 ) ;
return 0 ;
}
static int F_15 ( struct V_95 * V_95 , void * V_96 , struct V_109 * V_103 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
struct V_110 * V_111 = & V_103 -> V_16 . V_112 ;
struct V_110 V_136 ;
const struct V_14 * V_16 ;
struct V_109 V_137 ;
T_1 V_138 = 0 , V_139 = 0 ;
V_136 = * V_111 ;
V_16 = F_11 ( V_108 , V_103 ) ;
if ( ! V_16 )
return - V_105 ;
if ( V_103 -> type == V_119 ) {
V_138 = V_111 -> V_106 ;
V_139 = V_108 -> V_140 -> V_15 ;
} else if ( V_103 -> type == V_117 ) {
V_139 = V_111 -> V_106 ;
V_138 = V_108 -> V_141 -> V_15 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . type = V_119 ;
V_137 . V_16 . V_112 . V_106 = V_138 ;
V_137 . V_16 . V_112 . V_2 = V_136 . V_2 ;
V_137 . V_16 . V_112 . V_3 = V_136 . V_3 ;
F_11 ( V_108 , & V_137 ) ;
if ( V_103 -> type == V_119 ) {
V_108 -> V_142 = V_137 . V_16 . V_112 . V_2 ;
V_108 -> V_143 = V_137 . V_16 . V_112 . V_3 ;
V_108 -> V_144 = V_111 -> V_144 ;
V_108 -> V_145 = V_111 -> V_145 ;
V_108 -> V_146 = V_111 -> V_146 ;
V_108 -> V_147 = V_111 -> V_147 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . type = V_117 ;
V_137 . V_16 . V_112 . V_106 = V_139 ;
V_137 . V_16 . V_112 . V_2 = V_136 . V_2 ;
V_137 . V_16 . V_112 . V_3 = V_136 . V_3 ;
F_11 ( V_108 , & V_137 ) ;
V_108 -> V_2 = V_137 . V_16 . V_112 . V_2 ;
V_108 -> V_3 = V_137 . V_16 . V_112 . V_3 ;
if ( V_103 -> type == V_119 )
V_108 -> V_141 = V_16 ;
else if ( V_103 -> type == V_117 )
V_108 -> V_140 = V_16 ;
return 0 ;
}
static int F_16 ( struct V_95 * V_95 , void * V_96 , struct V_109 * V_103 )
{
struct V_110 * V_111 = & V_103 -> V_16 . V_112 ;
struct V_107 * V_108 = F_14 ( V_95 ) ;
const struct V_14 * V_16 ;
if ( V_103 -> type == V_117 )
V_16 = V_108 -> V_140 ;
else if ( V_103 -> type == V_119 )
V_16 = V_108 -> V_141 ;
else
return - V_105 ;
V_111 -> V_106 = V_16 -> V_15 ;
if ( V_103 -> type == V_117 ) {
V_111 -> V_2 = V_108 -> V_2 ;
V_111 -> V_3 = V_108 -> V_3 ;
V_111 -> V_144 = V_108 -> V_144 ;
V_111 -> V_145 = V_108 -> V_145 ;
V_111 -> V_146 = V_108 -> V_146 ;
V_111 -> V_147 = V_108 -> V_147 ;
} else if ( V_103 -> type == V_119 ) {
V_111 -> V_2 = V_108 -> V_142 ;
V_111 -> V_3 = V_108 -> V_143 ;
}
F_11 ( V_108 , V_103 ) ;
return 0 ;
}
static int
F_17 ( struct V_95 * V_95 , void * V_96 , struct V_148 * V_149 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
if ( V_149 -> type != V_150 )
return - V_105 ;
switch ( V_149 -> V_151 ) {
case V_152 :
case V_153 :
V_149 -> V_154 . V_2 = V_108 -> V_2 ;
V_149 -> V_154 . V_3 = V_108 -> V_3 ;
break;
case V_155 :
V_149 -> V_154 . V_2 = V_108 -> V_142 ;
V_149 -> V_154 . V_3 = V_108 -> V_143 ;
break;
default:
return - V_105 ;
}
V_149 -> V_154 . V_156 = 0 ;
V_149 -> V_154 . V_157 = 0 ;
return 0 ;
}
static int
F_18 ( struct V_95 * V_95 , void * V_96 , struct V_148 * V_149 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
if ( V_149 -> type != V_150 )
return - V_105 ;
switch ( V_149 -> V_151 ) {
case V_155 :
if ( V_149 -> V_154 . V_2 != V_108 -> V_142 ||
V_149 -> V_154 . V_3 != V_108 -> V_143 ||
V_149 -> V_154 . V_156 != 0 || V_149 -> V_154 . V_157 != 0 )
return - V_105 ;
break;
default:
return - V_105 ;
}
return 0 ;
}
static int F_19 ( struct V_95 * V_95 , void * V_96 , struct V_158 * V_159 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
struct V_160 * V_161 = & V_159 -> V_162 . V_163 ;
struct V_164 * V_165 = & V_161 -> V_165 ;
T_2 V_166 , V_167 ;
if ( V_159 -> type != V_117 &&
V_159 -> type != V_119 )
return - V_105 ;
memset ( V_161 -> V_104 , 0 , sizeof( V_161 -> V_104 ) ) ;
if ( ! V_165 -> V_168 )
V_165 -> V_168 = V_108 -> V_165 . V_168 ;
if ( ! V_165 -> V_169 )
V_165 -> V_169 = V_108 -> V_165 . V_169 ;
V_161 -> V_170 = V_171 ;
V_166 = V_165 -> V_169 * ( T_2 ) V_172 ;
F_20 ( V_166 , V_165 -> V_168 ) ;
if ( ! V_166 )
return - V_105 ;
V_167 = ( T_2 ) V_172 ;
F_20 ( V_167 , V_166 ) ;
V_108 -> V_165 = * V_165 ;
V_108 -> V_167 = V_167 ;
return 0 ;
}
static int F_21 ( struct V_95 * V_95 , void * V_96 , struct V_158 * V_159 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
if ( V_159 -> type != V_117 &&
V_159 -> type != V_119 )
return - V_105 ;
V_159 -> V_162 . V_163 . V_170 |= V_171 ;
V_159 -> V_162 . V_163 . V_165 = V_108 -> V_165 ;
return 0 ;
}
static int F_22 ( struct V_95 * V_95 , void * V_96 ,
struct V_173 * V_174 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
const struct V_14 * V_16 ;
V_174 -> type = V_175 ;
V_16 = F_4 ( V_174 -> V_176 ,
V_117 ) ;
if ( ! V_16 ) {
V_16 = F_4 ( V_174 -> V_176 ,
V_119 ) ;
if ( ! V_16 )
return - V_105 ;
}
if ( V_174 -> V_19 )
return - V_105 ;
V_174 -> V_177 . V_178 = V_108 -> V_121 . V_122 ;
V_174 -> V_177 . V_179 = V_108 -> V_121 . V_123 ;
V_174 -> V_177 . V_180 = V_108 -> V_121 . V_181 ;
V_174 -> V_177 . V_182 = V_108 -> V_124 . V_122 ;
V_174 -> V_177 . V_183 = V_108 -> V_124 . V_123 ;
V_174 -> V_177 . V_184 = V_108 -> V_124 . V_181 ;
return 0 ;
}
static int F_23 ( struct V_95 * V_95 , void * V_96 ,
struct V_185 * V_186 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
const struct V_14 * V_16 ;
V_186 -> type = V_187 ;
V_16 = F_4 ( V_186 -> V_176 ,
V_117 ) ;
if ( ! V_16 ) {
V_16 = F_4 ( V_186 -> V_176 ,
V_119 ) ;
if ( ! V_16 )
return - V_105 ;
}
if ( V_186 -> V_19 )
return - V_105 ;
if ( ! V_186 -> V_2 || ! V_186 -> V_3 )
return - V_105 ;
if ( V_186 -> V_2 > V_108 -> V_121 . V_123 ||
V_186 -> V_2 < V_108 -> V_121 . V_122 ||
V_186 -> V_3 > V_108 -> V_124 . V_123 ||
V_186 -> V_3 < V_108 -> V_124 . V_122 )
return - V_105 ;
V_186 -> V_177 . V_122 . V_169 = 1 ;
V_186 -> V_177 . V_122 . V_168 = V_108 -> V_188 . V_123 ;
V_186 -> V_177 . V_123 . V_169 = 1 ;
V_186 -> V_177 . V_123 . V_168 = V_108 -> V_188 . V_122 ;
V_186 -> V_177 . V_189 . V_169 = 1 ;
V_186 -> V_177 . V_189 . V_168 = V_108 -> V_188 . V_123 ;
return 0 ;
}
static int F_24 ( struct V_107 * V_108 )
{
struct V_190 * V_191 = & V_108 -> V_192 . V_193 ;
struct V_194 V_195 ;
struct V_196 V_197 ;
struct V_198 V_199 ;
struct V_200 V_201 ;
struct V_202 V_203 ;
T_1 V_204 , V_205 , V_206 , V_207 = 0 , V_208 = 0 ;
int V_209 ;
V_204 = V_210 ;
V_199 . V_211 = V_212 ;
V_199 . V_213 = V_108 -> V_167 * ( 1 << 16 ) ;
V_209 = F_25 ( V_108 , V_204 , & V_199 ) ;
if ( V_209 )
return V_209 ;
if ( V_108 -> V_140 -> V_15 == V_118 ) {
struct V_214 V_215 ;
V_204 = V_216 ;
V_215 . V_217 = 1 ;
V_215 . V_218 = 1 ;
V_215 . V_219 = V_220 ;
V_209 = F_25 ( V_108 , V_204 , & V_215 ) ;
if ( V_209 )
return V_209 ;
}
V_204 = V_221 ;
V_203 . V_222 = V_191 -> V_223 ;
V_209 = F_25 ( V_108 , V_204 , & V_203 ) ;
if ( V_209 )
return V_209 ;
if ( V_191 -> V_224 ) {
T_1 V_225 = V_226 ;
V_204 = V_227 ;
V_209 = F_25 ( V_108 , V_204 , & V_225 ) ;
if ( V_209 )
return V_209 ;
}
if ( ! V_191 -> V_228 )
V_191 -> V_228 = 2 * 15 - 1 ,
V_204 = V_229 ;
V_195 . V_230 = V_191 -> V_228 ;
V_195 . V_231 = V_191 -> V_224 ;
V_209 = F_25 ( V_108 , V_204 , & V_195 ) ;
if ( V_209 )
return V_209 ;
if ( V_191 -> V_232 == V_233 )
V_205 = V_234 ;
else
V_205 = V_235 ;
V_204 = V_236 ;
V_209 = F_25 ( V_108 , V_204 , & V_205 ) ;
if ( V_209 )
return V_209 ;
if ( ! V_191 -> V_206 )
V_206 = 64000 ;
else
V_206 = V_191 -> V_206 ;
V_204 = V_237 ;
V_201 . V_206 = V_206 ;
V_201 . V_238 = 0 ;
V_209 = F_25 ( V_108 , V_204 , & V_201 ) ;
if ( V_209 )
return V_209 ;
if ( ! V_191 -> V_239 )
V_206 *= 2 ;
else
V_206 = V_191 -> V_239 ;
V_204 = V_240 ;
V_201 . V_206 = V_206 ;
V_201 . V_238 = 0 ;
V_209 = F_25 ( V_108 , V_204 , & V_201 ) ;
if ( V_209 )
return V_209 ;
if ( V_108 -> V_140 -> V_15 == V_118 ) {
V_207 = F_7 ( V_43 ,
V_191 -> V_207 . V_241 ) ;
V_208 = F_7 ( V_52 ,
V_191 -> V_208 . V_241 ) ;
} else if ( V_108 -> V_140 -> V_15 == V_242 ) {
V_207 = F_7 ( V_90 ,
V_191 -> V_207 . V_243 ) ;
V_208 = 0 ;
} else if ( V_108 -> V_140 -> V_15 == V_244 ) {
V_207 = F_7 ( V_38 ,
V_191 -> V_207 . V_245 ) ;
V_208 = F_7 ( V_23 ,
V_191 -> V_208 . V_245 ) ;
} else if ( V_108 -> V_140 -> V_15 == V_246 ) {
V_207 = 0 ;
V_208 = 0 ;
}
V_204 = V_247 ;
V_197 . V_207 = V_207 ;
V_197 . V_208 = V_208 ;
V_209 = F_25 ( V_108 , V_204 , & V_197 ) ;
if ( V_209 )
return V_209 ;
return 0 ;
}
static int F_26 ( struct V_107 * V_108 )
{
int V_209 ;
V_209 = F_27 ( V_108 , V_108 -> V_140 -> V_15 ) ;
if ( V_209 )
return V_209 ;
V_209 = F_28 ( V_108 , V_108 -> V_142 ,
V_108 -> V_143 ) ;
if ( V_209 )
goto V_248;
V_209 = F_29 ( V_108 , V_108 -> V_2 ,
V_108 -> V_3 ) ;
if ( V_209 )
goto V_248;
V_209 = F_30 ( V_108 , V_108 -> V_141 -> V_15 ) ;
if ( V_209 )
goto V_248;
return 0 ;
V_248:
F_31 ( V_108 ) ;
return V_209 ;
}
static int F_32 ( struct V_107 * V_108 , unsigned int * V_249 )
{
struct V_250 V_251 ;
int V_209 ;
V_209 = F_26 ( V_108 ) ;
if ( V_209 )
return V_209 ;
V_209 = F_33 ( V_108 , V_252 , & V_251 ) ;
* V_249 = V_251 . V_253 ;
F_31 ( V_108 ) ;
return V_209 ;
}
static int F_34 ( struct V_254 * V_255 ,
unsigned int * V_256 , unsigned int * V_132 ,
unsigned int V_257 [] , struct V_258 * V_259 [] )
{
struct V_107 * V_108 = F_35 ( V_255 ) ;
unsigned int V_116 , V_249 , V_122 = 4 ;
int V_209 = 0 ;
if ( * V_132 ) {
if ( V_255 -> type == V_119 &&
* V_132 != V_108 -> V_141 -> V_132 )
return - V_105 ;
if ( V_255 -> type == V_117 &&
* V_132 != V_108 -> V_140 -> V_132 )
return - V_105 ;
if ( V_255 -> type == V_119 &&
V_257 [ 0 ] < V_108 -> V_260 )
return - V_105 ;
if ( V_255 -> type == V_117 &&
V_257 [ 0 ] < V_108 -> V_261 )
return - V_105 ;
return 0 ;
}
switch ( V_255 -> type ) {
case V_119 :
* V_132 = V_108 -> V_141 -> V_132 ;
V_209 = F_32 ( V_108 , & V_249 ) ;
if ( V_209 )
break;
V_249 = V_123 ( V_249 , V_122 ) ;
* V_256 = V_123 ( * V_256 , V_249 ) ;
V_108 -> V_262 = * V_256 ;
for ( V_116 = 0 ; V_116 < * V_132 ; ++ V_116 )
V_257 [ V_116 ] = F_1 ( V_116 , V_108 -> V_2 ,
V_108 -> V_3 ) ;
V_108 -> V_260 = V_257 [ 0 ] ;
break;
case V_117 :
* V_132 = V_108 -> V_140 -> V_132 ;
* V_256 = V_123 ( * V_256 , V_122 ) ;
V_108 -> V_263 = * V_256 ;
V_257 [ 0 ] = F_3 ( V_108 -> V_2 , V_108 -> V_3 ) ;
V_108 -> V_261 = V_257 [ 0 ] ;
break;
default:
V_209 = - V_105 ;
break;
}
return V_209 ;
}
static int F_36 ( struct V_107 * V_108 )
{
struct V_250 V_251 ;
int V_209 ;
if ( ! V_108 -> V_262 || ! V_108 -> V_263 )
return - V_105 ;
V_209 = F_33 ( V_108 , V_212 , & V_251 ) ;
if ( V_209 )
return V_209 ;
if ( V_108 -> V_263 < V_251 . V_253 ||
V_108 -> V_263 < V_251 . V_264 )
return - V_105 ;
V_209 = F_33 ( V_108 , V_252 , & V_251 ) ;
if ( V_209 )
return V_209 ;
if ( V_108 -> V_262 < V_251 . V_253 ||
V_108 -> V_262 < V_251 . V_264 )
return - V_105 ;
return 0 ;
}
static int F_37 ( struct V_254 * V_255 , unsigned int V_265 )
{
struct V_107 * V_108 = F_35 ( V_255 ) ;
int V_209 ;
F_38 ( & V_108 -> V_266 ) ;
if ( V_255 -> type == V_119 )
V_108 -> V_267 = 1 ;
else
V_108 -> V_268 = 1 ;
if ( ! ( V_108 -> V_267 & V_108 -> V_268 ) ) {
F_39 ( & V_108 -> V_266 ) ;
return 0 ;
}
F_40 ( V_108 ) ;
V_108 -> V_269 = 0 ;
V_108 -> V_270 = 0 ;
V_209 = F_26 ( V_108 ) ;
if ( V_209 )
goto V_271;
V_209 = F_24 ( V_108 ) ;
if ( V_209 )
goto V_272;
V_209 = F_36 ( V_108 ) ;
if ( V_209 )
goto V_272;
V_209 = F_41 ( V_108 , V_108 -> V_262 ,
V_108 -> V_263 ) ;
if ( V_209 )
goto V_272;
V_209 = F_42 ( V_108 ) ;
if ( V_209 )
goto V_272;
F_39 ( & V_108 -> V_266 ) ;
return 0 ;
V_272:
F_31 ( V_108 ) ;
V_271:
F_43 ( V_108 , V_273 ) ;
if ( V_255 -> type == V_119 )
V_108 -> V_267 = 0 ;
else
V_108 -> V_268 = 0 ;
F_39 ( & V_108 -> V_266 ) ;
return V_209 ;
}
static void F_44 ( struct V_107 * V_108 , unsigned int V_274 ,
T_1 V_275 , T_1 V_276 , T_1 V_277 , T_1 V_133 ,
T_1 V_278 , T_2 V_279 )
{
struct V_280 * V_281 ;
struct V_282 * V_283 ;
unsigned int type ;
if ( V_274 == V_252 )
type = V_119 ;
else
type = V_117 ;
V_281 = F_45 ( V_108 , type , V_275 ) ;
if ( ! V_281 )
return;
V_283 = & V_281 -> V_284 ;
V_283 -> V_285 [ 0 ] . V_276 = V_276 ;
V_283 -> V_285 [ 0 ] . V_277 = V_277 ;
V_281 -> V_133 = V_133 ;
if ( type == V_117 ) {
V_283 -> V_286 = V_279 * V_287 ;
V_281 -> V_288 = V_108 -> V_269 ++ ;
} else {
V_281 -> V_288 = V_108 -> V_270 ++ ;
}
F_46 ( V_281 , V_289 ) ;
}
static void F_47 ( struct V_107 * V_108 , T_1 V_290 ,
struct V_291 * V_292 )
{
struct V_258 * V_293 = V_108 -> V_125 -> V_294 ;
if ( V_290 == V_295 ) {
V_108 -> V_296 = true ;
F_48 ( V_293 , L_4 , V_108 -> error ) ;
}
}
static int F_49 ( void * V_297 , struct V_254 * V_298 ,
struct V_254 * V_299 )
{
struct V_107 * V_108 = V_297 ;
int V_209 ;
V_298 -> type = V_119 ;
V_298 -> V_300 = V_301 | V_302 ;
V_298 -> V_303 = V_304 ;
V_298 -> V_305 = & V_306 ;
V_298 -> V_307 = & V_308 ;
V_298 -> V_309 = V_108 ;
V_298 -> V_310 = sizeof( struct V_311 ) ;
V_298 -> V_312 = 1 ;
V_298 -> V_313 = 1 ;
V_298 -> V_293 = V_108 -> V_125 -> V_293 ;
V_209 = F_50 ( V_298 ) ;
if ( V_209 )
return V_209 ;
V_299 -> type = V_117 ;
V_299 -> V_300 = V_301 | V_302 ;
V_299 -> V_303 = V_304 ;
V_299 -> V_305 = & V_306 ;
V_299 -> V_307 = & V_308 ;
V_299 -> V_309 = V_108 ;
V_299 -> V_310 = sizeof( struct V_311 ) ;
V_299 -> V_312 = 1 ;
V_299 -> V_313 = 1 ;
V_299 -> V_293 = V_108 -> V_125 -> V_293 ;
V_209 = F_50 ( V_299 ) ;
if ( V_209 ) {
F_51 ( V_298 ) ;
return V_209 ;
}
return 0 ;
}
static void F_52 ( struct V_107 * V_108 )
{
V_108 -> V_140 = & V_17 [ 2 ] ;
V_108 -> V_141 = & V_17 [ 0 ] ;
V_108 -> V_2 = 1280 ;
V_108 -> V_3 = F_2 ( 720 , 32 ) ;
V_108 -> V_142 = 1280 ;
V_108 -> V_143 = 720 ;
V_108 -> V_167 = 15 ;
V_108 -> V_165 . V_169 = 1 ;
V_108 -> V_165 . V_168 = 15 ;
V_108 -> V_121 . V_122 = 96 ;
V_108 -> V_121 . V_123 = 1920 ;
if ( V_108 -> V_125 -> V_126 -> V_127 == V_314 )
V_108 -> V_121 . V_123 = 3840 ;
V_108 -> V_121 . V_181 = 2 ;
V_108 -> V_124 . V_122 = 64 ;
V_108 -> V_124 . V_123 = F_2 ( 1080 , 32 ) ;
if ( V_108 -> V_125 -> V_126 -> V_127 == V_314 )
V_108 -> V_124 . V_123 = F_2 ( 2160 , 32 ) ;
V_108 -> V_124 . V_181 = 2 ;
V_108 -> V_188 . V_122 = 1 ;
V_108 -> V_188 . V_123 = 30 ;
V_108 -> V_188 . V_181 = 1 ;
V_108 -> V_315 . V_122 = 24 ;
V_108 -> V_315 . V_123 = 8160 ;
}
static int F_53 ( struct V_95 * V_95 )
{
struct V_316 * V_125 = F_54 ( V_95 ) ;
struct V_107 * V_108 ;
int V_209 ;
V_108 = F_55 ( sizeof( * V_108 ) , V_317 ) ;
if ( ! V_108 )
return - V_318 ;
F_56 ( & V_108 -> V_319 ) ;
F_56 ( & V_108 -> V_320 ) ;
F_56 ( & V_108 -> V_321 ) ;
F_57 ( & V_108 -> V_266 ) ;
V_108 -> V_125 = V_125 ;
V_108 -> V_322 = V_323 ;
F_40 ( V_108 ) ;
V_209 = F_58 ( V_125 -> V_294 ) ;
if ( V_209 < 0 )
goto V_324;
V_209 = F_59 ( V_108 ) ;
if ( V_209 )
goto V_325;
V_209 = F_60 ( V_108 , & V_326 ) ;
if ( V_209 )
goto V_327;
F_52 ( V_108 ) ;
V_108 -> V_328 = F_61 ( & V_329 ) ;
if ( F_62 ( V_108 -> V_328 ) ) {
V_209 = F_63 ( V_108 -> V_328 ) ;
goto V_330;
}
V_108 -> V_331 = F_64 ( V_108 -> V_328 , V_108 , F_49 ) ;
if ( F_62 ( V_108 -> V_331 ) ) {
V_209 = F_63 ( V_108 -> V_331 ) ;
goto V_332;
}
F_65 ( & V_108 -> V_96 , V_125 -> V_333 ) ;
V_108 -> V_96 . V_334 = & V_108 -> V_334 ;
F_66 ( & V_108 -> V_96 ) ;
V_108 -> V_96 . V_331 = V_108 -> V_331 ;
V_95 -> V_335 = & V_108 -> V_96 ;
return 0 ;
V_332:
F_67 ( V_108 -> V_328 ) ;
V_330:
F_68 ( V_108 ) ;
V_327:
F_69 ( V_108 ) ;
V_325:
F_70 ( V_125 -> V_294 ) ;
V_324:
F_71 ( V_108 ) ;
return V_209 ;
}
static int F_72 ( struct V_95 * V_95 )
{
struct V_107 * V_108 = F_14 ( V_95 ) ;
F_73 ( V_108 -> V_331 ) ;
F_67 ( V_108 -> V_328 ) ;
F_69 ( V_108 ) ;
F_68 ( V_108 ) ;
F_74 ( & V_108 -> V_266 ) ;
F_75 ( & V_108 -> V_96 ) ;
F_76 ( & V_108 -> V_96 ) ;
F_70 ( V_108 -> V_125 -> V_294 ) ;
F_71 ( V_108 ) ;
return 0 ;
}
static int F_77 ( struct V_336 * V_337 )
{
struct V_258 * V_293 = & V_337 -> V_293 ;
struct V_338 * V_339 ;
struct V_316 * V_125 ;
int V_209 ;
if ( ! V_293 -> V_340 )
return - V_341 ;
V_125 = F_78 ( V_293 -> V_340 ) ;
if ( ! V_125 )
return - V_341 ;
if ( V_125 -> V_126 -> V_127 == V_314 ) {
V_125 -> V_342 = F_79 ( V_293 , L_5 ) ;
if ( F_62 ( V_125 -> V_342 ) )
return F_63 ( V_125 -> V_342 ) ;
}
F_80 ( V_337 , V_125 ) ;
V_339 = F_81 () ;
if ( ! V_339 )
return - V_318 ;
V_339 -> V_343 = V_344 ;
V_339 -> V_345 = & V_346 ;
V_339 -> V_347 = & V_348 ;
V_339 -> V_349 = V_350 ;
V_339 -> V_351 = & V_125 -> V_351 ;
V_339 -> V_352 = V_353 | V_354 ;
V_209 = F_82 ( V_339 , V_355 , - 1 ) ;
if ( V_209 )
goto V_356;
V_125 -> V_333 = V_339 ;
V_125 -> V_294 = V_293 ;
F_83 ( V_339 , V_125 ) ;
F_84 ( V_293 ) ;
return 0 ;
V_356:
V_344 ( V_339 ) ;
return V_209 ;
}
static int F_85 ( struct V_336 * V_337 )
{
struct V_316 * V_125 = F_78 ( V_337 -> V_293 . V_340 ) ;
F_86 ( V_125 -> V_333 ) ;
F_87 ( V_125 -> V_294 ) ;
return 0 ;
}
static int F_88 ( struct V_258 * V_293 )
{
struct V_316 * V_125 = F_78 ( V_293 ) ;
if ( V_125 -> V_126 -> V_127 == V_128 )
return 0 ;
F_89 ( 0 , V_125 -> V_357 + V_358 ) ;
F_90 ( V_125 -> V_342 ) ;
F_89 ( 1 , V_125 -> V_357 + V_358 ) ;
return 0 ;
}
static int F_91 ( struct V_258 * V_293 )
{
struct V_316 * V_125 = F_78 ( V_293 ) ;
int V_209 ;
if ( V_125 -> V_126 -> V_127 == V_128 )
return 0 ;
F_89 ( 0 , V_125 -> V_357 + V_358 ) ;
V_209 = F_92 ( V_125 -> V_342 ) ;
F_89 ( 1 , V_125 -> V_357 + V_358 ) ;
return V_209 ;
}
