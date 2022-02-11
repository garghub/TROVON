int F_1 ( struct V_1 * V_2 , enum V_3 V_3 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_1 ) ;
#endif
switch ( V_3 ) {
case V_5 : return F_4 ( V_6 , ( F_5 ( V_6 ) & ~ V_7 ) | V_8 ) ;
case V_9 : return F_4 ( V_6 , ( F_5 ( V_6 ) & ~ V_7 ) | V_10 ) ;
case V_11 : return F_4 ( V_6 , ( F_5 ( V_6 ) & ~ V_7 ) | V_12 ) ;
case V_13 : return F_4 ( V_6 , ( F_5 ( V_6 ) & ~ V_7 ) | V_14 ) ;
case V_15 : return F_4 ( V_6 , ( F_5 ( V_6 ) & ~ V_7 ) | V_16 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_6 ( struct V_1 * V_2 , enum V_18 V_18 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_3 ) ;
#endif
switch ( V_18 ) {
case V_19 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_21 ) | V_22 ) ;
case V_23 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_21 ) | V_24 ) ;
case V_25 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_21 ) | V_26 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_7 ( struct V_1 * V_2 , enum V_27 V_27 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_4 ) ;
#endif
switch ( V_27 ) {
case V_28 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_29 ) | V_30 ) ;
case V_31 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_29 ) | V_32 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
enum V_27 F_8 ( struct V_1 * V_2 )
{
T_1 V_33 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_5 ) ;
#endif
V_33 = F_5 ( V_20 ) ;
switch ( V_33 & V_29 >> 3 ) {
case V_30 : return V_28 ;
case V_32 : return V_31 ;
default: return V_34 ;
}
}
int F_9 ( struct V_1 * V_2 , enum V_35 V_35 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_6 ) ;
#endif
if ( F_8 ( V_2 ) == V_31 ) {
switch ( V_35 ) {
case V_36 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_37 ) | V_38 ) ;
case V_39 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_37 ) | V_40 ) ;
case V_41 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_37 ) | V_42 ) ;
case V_43 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_37 ) | V_44 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
} else {
switch ( V_35 ) {
case V_36 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_37 ) | V_38 ) ;
case V_45 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_37 ) | V_46 ) ;
case V_47 : return F_4 ( V_20 , ( F_5 ( V_20 ) & ~ V_37 ) | V_48 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
}
int F_10 ( struct V_1 * V_2 , T_2 V_49 )
{
int V_50 ;
T_3 V_51 ;
T_3 V_52 ;
T_1 V_53 ;
T_1 V_54 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_7 ) ;
#endif
V_51 = V_55 / 8388608 ;
if ( V_49 < V_51 ) {
F_3 ( & V_2 -> V_4 , L_8 ) ;
return - V_17 ;
}
V_52 = ( V_55 / V_49 ) ;
V_53 = ( V_52 & 0xff00 ) >> 8 ;
V_54 = ( V_52 & 0xff ) ;
V_50 = F_4 ( V_56 , V_53 ) ;
if ( V_50 ) return V_50 ;
V_50 = F_4 ( V_57 , V_54 ) ;
if ( V_50 ) return V_50 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , T_3 V_58 )
{
int V_50 ;
T_4 V_59 ;
T_4 V_60 ;
T_1 V_53 ;
T_1 V_54 ;
T_4 V_61 = 1000000 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_9 ) ;
#endif
if ( V_58 < 600 || V_58 > 500000 ) {
F_3 ( & V_2 -> V_4 , L_10 ) ;
return - V_17 ;
}
V_60 = V_55 * V_61 ;
F_12 ( V_60 , 524288 ) ;
V_59 = V_58 * V_61 ;
F_12 ( V_59 , V_60 ) ;
V_53 = ( V_59 & 0xff00 ) >> 8 ;
V_54 = ( V_59 & 0xff ) ;
if ( V_53 & ~ V_62 ) {
F_3 ( & V_2 -> V_4 , L_11 ) ;
return - V_17 ;
}
V_50 = F_4 ( V_63 , V_53 ) ;
if ( V_50 ) return V_50 ;
V_50 = F_4 ( V_64 , V_54 ) ;
if ( V_50 ) return V_50 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_3 V_65 )
{
int V_50 ;
T_3 V_66 ;
T_4 V_59 ;
T_4 V_60 ;
T_1 V_53 ;
T_1 V_67 ;
T_1 V_54 ;
T_4 V_61 = 1000000 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_12 ) ;
#endif
V_60 = V_55 * V_61 ;
F_12 ( V_60 , 524288 ) ;
V_66 = F_14 ( V_60 * 8388608 , V_61 ) ;
if ( V_65 > V_66 ) {
F_3 ( & V_2 -> V_4 , L_13 ) ;
return - V_17 ;
}
V_59 = V_65 * V_61 ;
F_12 ( V_59 , V_60 ) ;
V_53 = ( V_59 & 0xff0000 ) >> 16 ;
V_67 = ( V_59 & 0xff00 ) >> 8 ;
V_54 = ( V_59 & 0xff ) ;
V_50 = F_4 ( V_68 , V_53 ) ;
if ( V_50 ) return V_50 ;
V_50 = F_4 ( V_69 , V_67 ) ;
if ( V_50 ) return V_50 ;
V_50 = F_4 ( V_70 , V_54 ) ;
if ( V_50 ) return V_50 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , enum V_71 V_71 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_14 ) ;
#endif
switch( V_71 ) {
case V_72 : return F_4 ( V_73 , ( F_5 ( V_73 ) | V_74 ) ) ;
case V_75 : return F_4 ( V_73 , ( F_5 ( V_73 ) & ~ V_74 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_16 ( struct V_1 * V_2 , enum V_71 V_71 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_15 ) ;
#endif
switch( V_71 ) {
case V_72 : return F_4 ( V_73 , ( F_5 ( V_73 ) | V_76 ) ) ;
case V_75 : return F_4 ( V_73 , ( F_5 ( V_73 ) & ~ V_76 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_17 ( struct V_1 * V_2 , enum V_71 V_71 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_16 ) ;
#endif
switch( V_71 ) {
case V_72 : return F_4 ( V_73 , ( F_5 ( V_73 ) | V_77 ) ) ;
case V_75 : return F_4 ( V_73 , ( F_5 ( V_73 ) & ~ V_77 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_18 ( struct V_1 * V_2 , T_1 V_78 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_17 ) ;
#endif
V_78 += 18 ;
if ( V_78 > 0x1f ) {
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
return F_4 ( V_73 , ( F_5 ( V_73 ) & ~ V_79 ) | V_78 ) ;
}
int F_19 ( struct V_1 * V_2 , enum V_80 V_80 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_18 ) ;
#endif
switch( V_80 ) {
case V_81 : return F_4 ( V_82 , V_83 ) ;
case V_84 : return F_4 ( V_82 , V_85 ) ;
case V_86 : return F_4 ( V_82 , V_87 ) ;
case V_88 : return F_4 ( V_82 , V_89 ) ;
case V_90 : return F_4 ( V_82 , V_91 ) ;
case V_92 : return F_4 ( V_82 , V_93 ) ;
case V_94 : return F_4 ( V_82 , V_95 ) ;
case V_96 : return F_4 ( V_82 , V_97 ) ;
case V_98 : return F_4 ( V_82 , V_99 ) ;
case V_100 : return F_4 ( V_82 , V_101 ) ;
case V_102 : return F_4 ( V_82 , V_103 ) ;
case V_104 : return F_4 ( V_82 , V_105 ) ;
case V_106 : return F_4 ( V_82 , V_107 ) ;
case V_108 : return F_4 ( V_82 , V_109 ) ;
case V_110 : return F_4 ( V_82 , V_111 ) ;
case V_112 : return F_4 ( V_82 , V_113 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_20 ( struct V_1 * V_2 , enum V_114 V_114 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_19 ) ;
#endif
switch( V_114 ) {
case V_115 : return F_4 ( V_116 , ( F_5 ( V_116 ) & ~ V_117 ) ) ;
case V_118 : return F_4 ( V_116 , ( F_5 ( V_116 ) | V_117 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_21 ( struct V_1 * V_2 , enum V_119 V_119 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_20 ) ;
#endif
switch( V_119 ) {
case V_120 : return F_4 ( V_116 , ( ( F_5 ( V_116 ) & ~ V_121 ) & V_122 ) ) ;
case V_123 : return F_4 ( V_116 , ( ( F_5 ( V_116 ) & ~ V_121 ) & V_124 ) ) ;
case V_125 : return F_4 ( V_116 , ( ( F_5 ( V_116 ) & ~ V_121 ) & V_126 ) ) ;
case V_127 : return F_4 ( V_116 , ( ( F_5 ( V_116 ) & ~ V_121 ) & V_128 ) ) ;
case V_129 : return F_4 ( V_116 , ( ( F_5 ( V_116 ) & ~ V_121 ) & V_130 ) ) ;
case V_131 : return F_4 ( V_116 , ( ( F_5 ( V_116 ) & ~ V_121 ) & V_132 ) ) ;
case V_133 : return F_4 ( V_116 , ( ( F_5 ( V_116 ) & ~ V_121 ) & V_134 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
enum V_119 F_22 ( struct V_1 * V_2 )
{
T_1 V_33 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_21 ) ;
#endif
V_33 = F_5 ( V_116 ) ;
switch ( V_33 & V_135 >> 3 ) {
case V_122 : return V_120 ;
case V_124 : return V_123 ;
case V_126 : return V_125 ;
case V_128 : return V_127 ;
case V_130 : return V_129 ;
case V_132 : return V_131 ;
case V_134 : return V_133 ;
default: return V_34 ;
}
}
int F_23 ( struct V_1 * V_2 , T_1 V_136 , enum V_137 V_137 )
{
switch ( V_137 ) {
case V_138 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_140 ) ) ;
case V_141 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_142 ) ) ;
case V_143 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_144 ) ) ;
case V_145 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_146 ) ) ;
case V_147 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_148 ) ) ;
case V_149 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_150 ) ) ;
case V_151 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_152 ) ) ;
case V_153 : return F_4 ( V_136 , ( ( F_5 ( V_136 ) & ~ V_139 ) | V_154 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_24 ( struct V_1 * V_2 , enum V_137 V_137 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_22 ) ;
#endif
return F_23 ( V_2 , V_155 , V_137 ) ;
}
int F_25 ( struct V_1 * V_2 , enum V_137 V_137 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_23 ) ;
#endif
return F_23 ( V_2 , V_156 , V_137 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_136 ,
enum V_157 V_157 , T_1 V_158 )
{
T_1 V_159 ;
if ( V_158 > 7 ) {
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
if ( ( V_157 != V_160 ) &&
( V_157 != V_161 ) &&
( V_157 != V_162 ) ) {
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
V_159 = F_5 ( V_136 ) ;
V_159 = V_159 & V_139 ;
switch( V_157 ) {
case V_160 : V_159 = V_159 | V_163 ; break;
case V_161 : V_159 = V_159 | V_164 ; break;
case V_162 : V_159 = V_159 | V_165 ; break;
}
V_159 = V_159 | V_158 ;
return F_4 ( V_136 , V_159 ) ;
}
int F_27 ( struct V_1 * V_2 , enum V_157 V_157 , T_1 V_158 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_24 ) ;
#endif
return F_26 ( V_2 , V_155 , V_157 , V_158 ) ;
}
int F_28 ( struct V_1 * V_2 , enum V_157 V_157 , T_1 V_158 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_25 ) ;
#endif
return F_26 ( V_2 , V_156 , V_157 , V_158 ) ;
}
int F_29 ( struct V_1 * V_2 , enum V_166 V_166 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_26 ) ;
#endif
switch ( V_166 ) {
case V_167 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_169 ) | V_170 ) ) ;
case V_171 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_169 ) | V_172 ) ) ;
case V_173 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_169 ) | V_174 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_30 ( struct V_1 * V_2 , enum V_175 V_175 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_27 ) ;
#endif
switch ( V_175 ) {
case V_176 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_178 ) ) ;
case V_179 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_180 ) ) ;
case V_181 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_182 ) ) ;
case V_183 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_184 ) ) ;
case V_185 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_186 ) ) ;
case V_187 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_188 ) ) ;
case V_189 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_190 ) ) ;
case V_191 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_177 ) | V_192 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_31 ( struct V_1 * V_2 , enum V_193 V_193 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_28 ) ;
#endif
switch ( V_193 ) {
case V_194 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_196 ) ) ;
case V_197 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_198 ) ) ;
case V_199 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_200 ) ) ;
case V_201 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_202 ) ) ;
case V_203 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_204 ) ) ;
case V_205 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_206 ) ) ;
case V_207 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_208 ) ) ;
case V_209 : return F_4 ( V_168 , ( ( F_5 ( V_168 ) & ~ V_195 ) | V_210 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_32 ( struct V_1 * V_2 , T_1 V_211 , T_1 V_212 )
{
T_1 V_213 ;
T_1 V_214 ;
T_1 V_215 ;
T_1 V_216 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_29 ) ;
#endif
switch ( V_211 ) {
case 0 : V_213 = V_217 ; V_214 = V_218 ; V_215 = V_219 ; break;
case 1 : V_213 = V_220 ; V_214 = V_221 ; V_215 = V_219 ; break;
case 2 : V_213 = V_222 ; V_214 = V_223 ; V_215 = V_219 ; break;
case 3 : V_213 = V_224 ; V_214 = V_225 ; V_215 = V_219 ; break;
case 4 : V_213 = V_226 ; V_214 = V_227 ; V_215 = V_228 ; break;
case 5 : V_213 = V_229 ; V_214 = V_230 ; V_215 = V_228 ; break;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
V_216 = F_5 ( V_215 ) ;
V_216 = V_216 & ~ V_213 ;
V_216 = V_216 | V_212 << V_214 ;
return F_4 ( V_215 , V_216 ) ;
}
bool F_33 ( struct V_1 * V_2 , enum V_231 V_231 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_30 ) ;
#endif
switch( V_231 ) {
case V_232 : return ( F_5 ( V_233 ) & V_234 ) ;
case V_235 : return ( F_5 ( V_233 ) & V_236 ) ;
case V_237 : return ( F_5 ( V_233 ) & V_238 ) ;
case V_239 : return ( F_5 ( V_233 ) & V_240 ) ;
case V_241 : return ( F_5 ( V_233 ) & V_242 ) ;
case V_243 : return ( F_5 ( V_233 ) & V_244 ) ;
case V_245 : return ( F_5 ( V_233 ) & V_246 ) ;
case V_247 : return ( F_5 ( V_233 ) & V_248 ) ;
case V_249 : return ( F_5 ( V_250 ) & V_251 ) ;
case V_252 : return ! ( F_5 ( V_250 ) & V_253 ) ;
case V_254 : return ( F_5 ( V_250 ) & V_255 ) ;
case V_256 : return ( F_5 ( V_250 ) & V_257 ) ;
case V_258 : return ( F_5 ( V_250 ) & V_259 ) ;
case V_260 : return ( F_5 ( V_250 ) & V_261 ) ;
case V_262 : return ( F_5 ( V_250 ) & V_263 ) ;
case V_264 : return ( F_5 ( V_250 ) & V_265 ) ;
default: return false ;
}
}
int F_34 ( struct V_1 * V_2 , enum V_231 V_231 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_31 ) ;
#endif
switch( V_231 ) {
case V_241 : return F_4 ( V_233 , V_242 ) ;
case V_247 : return F_4 ( V_233 , V_248 ) ;
case V_256 : return F_4 ( V_250 , V_257 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_35 ( struct V_1 * V_2 , T_1 V_266 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_32 ) ;
#endif
return F_4 ( V_267 , V_266 ) ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_243 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_33 ) ;
#endif
return F_4 ( V_268 , V_243 ) ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_243 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_34 ) ;
#endif
return F_4 ( V_269 , V_243 ) ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_270 )
{
int V_50 ;
T_1 V_53 , V_54 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_35 ) ;
#endif
V_53 = ( V_270 & 0xff00 ) >> 8 ;
V_54 = ( V_270 & 0xff ) ;
V_50 = F_4 ( V_271 , V_53 ) ;
if ( V_50 ) return V_50 ;
V_50 = F_4 ( V_272 , V_54 ) ;
return V_50 ;
}
int F_39 ( struct V_1 * V_2 , enum V_71 V_71 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_36 ) ;
#endif
switch( V_71 ) {
case V_72 : return F_4 ( V_273 , ( F_5 ( V_273 ) | V_274 ) ) ;
case V_75 : return F_4 ( V_273 , ( F_5 ( V_273 ) & ~ V_274 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_40 ( struct V_1 * V_2 , enum V_275 V_275 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_37 ) ;
#endif
switch( V_275 ) {
case V_276 : return F_4 ( V_273 , ( F_5 ( V_273 ) | V_277 ) ) ;
case V_278 : return F_4 ( V_273 , ( F_5 ( V_273 ) & ~ V_277 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_41 ( struct V_1 * V_2 , T_1 V_279 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_38 ) ;
#endif
if ( V_279 > 0x07 ) {
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
return F_4 ( V_273 , ( F_5 ( V_273 ) & ~ V_280 ) | ( V_279 << 3 ) ) ;
}
int F_42 ( struct V_1 * V_2 , T_1 V_281 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_39 ) ;
#endif
if ( V_281 > 0x07 ) {
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
return F_4 ( V_273 , ( F_5 ( V_273 ) & ~ V_280 ) | V_281 ) ;
}
int F_43 ( struct V_1 * V_2 , T_1 V_282 [ 8 ] )
{
int V_50 = 0 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_40 ) ;
#endif
V_50 += F_4 ( V_283 , V_282 [ 0 ] ) ;
V_50 += F_4 ( V_284 , V_282 [ 1 ] ) ;
V_50 += F_4 ( V_285 , V_282 [ 2 ] ) ;
V_50 += F_4 ( V_286 , V_282 [ 3 ] ) ;
V_50 += F_4 ( V_287 , V_282 [ 4 ] ) ;
V_50 += F_4 ( V_288 , V_282 [ 5 ] ) ;
V_50 += F_4 ( V_289 , V_282 [ 6 ] ) ;
V_50 += F_4 ( V_290 , V_282 [ 7 ] ) ;
return V_50 ;
}
int F_44 ( struct V_1 * V_2 , enum V_291 V_291 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_41 ) ;
#endif
switch( V_291 ) {
case V_292 : return F_4 ( V_293 , ( F_5 ( V_293 ) | V_294 ) ) ;
case V_295 : return F_4 ( V_293 , ( F_5 ( V_293 ) & ~ V_294 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_45 ( struct V_1 * V_2 , enum V_71 V_71 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_42 ) ;
#endif
switch( V_71 ) {
case V_72 : return F_4 ( V_293 , ( F_5 ( V_293 ) | V_296 ) ) ;
case V_75 : return F_4 ( V_293 , ( F_5 ( V_293 ) & ~ V_296 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_46 ( struct V_1 * V_2 , enum V_297 V_297 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_43 ) ;
#endif
switch ( V_297 ) {
case V_298 : return F_4 ( V_293 , ( ( F_5 ( V_293 ) & ~ V_299 ) | V_300 ) ) ;
case V_301 : return F_4 ( V_293 , ( ( F_5 ( V_293 ) & ~ V_299 ) | V_302 ) ) ;
case V_303 : return F_4 ( V_293 , ( ( F_5 ( V_293 ) & ~ V_299 ) | V_304 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_47 ( struct V_1 * V_2 , T_1 V_305 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_44 ) ;
#endif
return F_4 ( V_306 , V_305 ) ;
}
T_1 F_48 ( struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_45 ) ;
#endif
return ( T_1 ) F_5 ( V_306 ) ;
}
int F_49 ( struct V_1 * V_2 , T_1 V_301 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_46 ) ;
#endif
return F_4 ( V_307 , V_301 ) ;
}
int F_50 ( struct V_1 * V_2 , T_1 V_308 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_47 ) ;
#endif
return F_4 ( V_309 , V_308 ) ;
}
int F_51 ( struct V_1 * V_2 , enum V_310 V_310 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_48 ) ;
#endif
switch( V_310 ) {
case V_311 : return F_4 ( V_312 , ( F_5 ( V_312 ) & ~ V_313 ) ) ;
case V_314 : return F_4 ( V_312 , ( F_5 ( V_312 ) | V_313 ) ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_52 ( struct V_1 * V_2 , T_1 V_266 )
{
int V_50 ;
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_49 ) ;
#endif
if ( V_266 & 0x80 ) {
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
V_50 = F_4 ( V_312 , ( F_5 ( V_312 ) & ~ V_315 ) | V_266 ) ;
if ( V_50 )
return V_50 ;
return F_53 ( V_2 , ( T_1 * ) & V_50 , 1 ) ;
}
int F_54 ( struct V_1 * V_2 , enum V_316 V_316 )
{
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_50 ) ;
#endif
switch( V_316 ) {
case V_317 : return F_4 ( V_318 , V_319 ) ;
case V_320 : return F_4 ( V_318 , V_321 ) ;
case V_322 : return F_4 ( V_318 , V_323 ) ;
default:
F_3 ( & V_2 -> V_4 , L_2 ) ;
return - V_17 ;
}
}
int F_53 ( struct V_1 * V_2 , T_1 * V_324 , unsigned int V_325 )
{
#ifdef F_55
int V_326 ;
#endif
struct V_327 V_328 ;
T_1 V_329 [ V_330 + 1 ] ;
int V_50 ;
if ( V_325 > V_330 ) {
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_51 ) ;
#endif
return - V_331 ;
}
V_329 [ 0 ] = V_332 ;
memset ( & V_328 , 0 , sizeof( V_328 ) ) ;
V_328 . V_333 = V_329 ;
V_328 . V_334 = V_329 ;
V_328 . V_335 = V_325 + 1 ;
V_50 = F_56 ( V_2 , & V_328 , 1 ) ;
#ifdef F_55
for ( V_326 = 0 ; V_326 < V_325 ; V_326 ++ )
F_3 ( & V_2 -> V_4 , L_52 , V_326 , V_329 [ V_326 + 1 ] ) ;
#endif
memcpy ( V_324 , & V_329 [ 1 ] , V_325 ) ;
return V_50 ;
}
int F_57 ( struct V_1 * V_2 , T_1 * V_324 , unsigned int V_325 )
{
#ifdef F_55
int V_326 ;
#endif
char V_336 = V_332 | V_337 ;
T_1 V_329 [ V_330 + 1 ] ;
if ( V_325 > V_330 ) {
#ifdef F_2
F_3 ( & V_2 -> V_4 , L_51 ) ;
#endif
return - V_331 ;
}
V_329 [ 0 ] = V_336 ;
memcpy ( & V_329 [ 1 ] , V_324 , V_325 ) ;
#ifdef F_55
for ( V_326 = 0 ; V_326 < V_325 ; V_326 ++ )
F_3 ( & V_2 -> V_4 , L_53 , V_324 [ V_326 ] ) ;
#endif
return F_58 ( V_2 , V_329 , V_325 + 1 ) ;
}
T_1 F_59 ( struct V_1 * V_2 , T_1 V_338 )
{
int V_50 ;
V_50 = F_60 ( V_2 , V_338 ) ;
#ifdef F_61
if ( V_50 < 0 )
F_3 ( & V_2 -> V_4 , L_54 ,
V_338 ) ;
else
F_3 ( & V_2 -> V_4 , L_55 ,
V_50 ,
V_338 ) ;
#endif
return V_50 ;
}
int F_62 ( struct V_1 * V_2 , T_1 V_338 , T_1 V_212 )
{
int V_50 ;
char V_324 [ 2 ] ;
V_324 [ 0 ] = V_338 | V_337 ;
V_324 [ 1 ] = V_212 ;
V_50 = F_58 ( V_2 , & V_324 , 2 ) ;
#ifdef F_61
if ( V_50 < 0 )
F_3 ( & V_2 -> V_4 , L_56 ,
V_212 ,
V_338 ) ;
else
F_3 ( & V_2 -> V_4 , L_57 ,
V_212 ,
V_338 ) ;
#endif
return V_50 ;
}
