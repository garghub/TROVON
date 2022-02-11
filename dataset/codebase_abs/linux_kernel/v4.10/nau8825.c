static int F_1 ( struct V_1 * V_1 , long V_2 )
{
int V_3 ;
if ( V_2 ) {
V_3 = F_2 ( & V_1 -> V_4 , V_2 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_1 ) ;
} else {
V_3 = F_4 ( & V_1 -> V_4 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_2 ) ;
}
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_1 )
{
F_6 ( & V_1 -> V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_1 )
{
V_1 -> V_4 . V_6 = 1 ;
}
static void F_8 ( struct V_1 * V_1 ,
unsigned int V_7 , unsigned int V_8 , unsigned int V_9 )
{
unsigned int V_10 , V_11 , V_12 , V_13 , V_14 ;
if ( V_7 == V_8 || V_9 == 0 ) {
return;
} else if ( V_7 < V_8 ) {
V_12 = true ;
V_13 = V_7 ;
V_14 = V_8 ;
} else {
V_12 = false ;
V_13 = V_8 ;
V_14 = V_7 ;
}
if ( V_14 > V_15 )
V_14 = V_15 ;
for ( V_11 = V_13 ; V_11 < V_14 ; V_11 += V_9 ) {
if ( V_12 )
V_10 = V_11 ;
else
V_10 = V_14 - V_11 + V_13 ;
F_9 ( V_1 -> V_16 , V_17 ,
V_18 | V_19 ,
( V_10 << V_20 ) | V_10 ) ;
F_10 ( 10000 , 10500 ) ;
}
if ( V_12 )
V_10 = V_14 ;
else
V_10 = V_13 ;
F_9 ( V_1 -> V_16 , V_17 ,
V_18 | V_19 ,
( V_10 << V_20 ) | V_10 ) ;
}
static T_1 F_11 ( T_1 V_10 )
{
T_1 V_21 , V_22 , V_23 , V_24 , V_25 ;
T_2 V_26 ;
V_21 = F_12 ( V_10 ) - 1 ;
V_23 = V_10 << ( 31 - V_21 ) ;
V_22 = ( V_23 >> 23 ) & 0xff ;
V_24 = ( ( V_23 & 0x7fffff ) *
( ( V_27 [ ( V_22 + 1 ) & 0xff ] -
V_27 [ V_22 ] ) & 0xffff ) ) >> 15 ;
V_26 = ( ( V_21 << 24 ) + ( V_27 [ V_22 ] << 8 ) + V_24 ) ;
V_25 = ( V_26 * V_28 ) >> 31 ;
return V_25 / ( ( 1 << 24 ) / 1000 ) ;
}
static T_1 F_13 ( T_1 V_29 , T_1 V_30 )
{
T_1 V_31 , V_32 ;
if ( F_14 ( V_29 == 0 ) || F_14 ( V_30 == 0 ) ) {
F_15 ( 1 ) ;
return 0 ;
}
V_29 = F_11 ( V_29 ) ;
V_30 = F_11 ( V_30 ) ;
if ( V_29 >= V_30 )
V_31 = ( V_29 - V_30 ) * 20 + V_33 ;
else
V_31 = ( V_30 - V_29 ) * 20 + V_33 ;
V_32 = V_34 - V_31 * 2 ;
V_32 /= 1000 ;
return V_32 ;
}
static int F_16 ( unsigned int V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_17 ( V_37 ) ; V_36 ++ )
if ( V_37 [ V_36 ] . V_35 == V_35 )
return V_36 ;
return - V_38 ;
}
static void F_18 ( struct V_1 * V_1 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_37 ) ; V_39 ++ )
F_19 ( V_1 -> V_16 , V_37 [ V_39 ] . V_35 ,
& V_37 [ V_39 ] . V_40 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
int V_39 , V_11 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_37 ) ; V_39 ++ ) {
if ( V_37 [ V_39 ] . V_35 == V_17 ) {
V_11 = V_37 [ V_39 ] . V_40 &
V_19 ;
F_8 ( V_1 , 0 , V_11 , 3 ) ;
continue;
}
F_21 ( V_1 -> V_16 , V_37 [ V_39 ] . V_35 ,
V_37 [ V_39 ] . V_40 ) ;
}
}
static void F_22 ( struct V_1 * V_1 )
{
F_9 ( V_1 -> V_16 , V_41 ,
V_42 | V_43 |
V_44 | V_45 |
V_46 , V_42 |
V_43 | V_44 |
V_45 | V_46 ) ;
F_9 ( V_1 -> V_16 , V_47 ,
V_48 | V_49 ,
V_48 | V_49 ) ;
F_9 ( V_1 -> V_16 , V_50 ,
V_51 | V_52 |
V_53 ,
V_51 | V_52 ) ;
F_9 ( V_1 -> V_16 , V_54 ,
V_55 | V_56 |
V_57 | V_58 ,
V_55 | V_56 |
V_57 | V_58 ) ;
F_9 ( V_1 -> V_16 , V_54 ,
V_59 | V_60 ,
V_59 | V_60 ) ;
F_9 ( V_1 -> V_16 , V_61 ,
V_62 | V_63 , 0 ) ;
F_9 ( V_1 -> V_16 , V_64 ,
V_65 , V_65 ) ;
F_9 ( V_1 -> V_16 , V_66 ,
V_67 | V_68 ,
V_67 | V_68 ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_9 ( V_1 -> V_16 , V_69 ,
V_70 | V_71 ,
V_70 | V_72 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
F_21 ( V_1 -> V_16 , V_73 , 0x0 ) ;
F_21 ( V_1 -> V_16 , V_74 , 0x3126 ) ;
F_21 ( V_1 -> V_16 , V_75 , 0x0008 ) ;
F_21 ( V_1 -> V_16 , V_76 , 0x0010 ) ;
F_21 ( V_1 -> V_16 , V_77 , 0x0 ) ;
F_21 ( V_1 -> V_16 , V_78 , 0x6000 ) ;
F_9 ( V_1 -> V_16 , V_79 ,
V_80 , V_81 ) ;
F_9 ( V_1 -> V_16 , V_78 , V_82 ,
V_82 ) ;
F_9 ( V_1 -> V_16 , V_79 ,
V_83 , 0xf ) ;
F_9 ( V_1 -> V_16 , V_73 ,
V_84 , 0x10 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
int V_11 , V_36 ;
F_18 ( V_1 ) ;
F_9 ( V_1 -> V_16 , V_85 ,
V_86 | V_87 |
V_88 , V_89 |
( 0x2 << V_90 ) | 0x1 ) ;
V_36 = F_16 ( V_17 ) ;
if ( V_36 != - V_38 ) {
V_11 = V_37 [ V_36 ] . V_40 &
V_19 ;
F_8 ( V_1 , V_11 , 0 , 3 ) ;
}
F_24 ( V_1 ) ;
F_22 ( V_1 ) ;
F_23 ( V_1 ) ;
F_9 ( V_1 -> V_16 , V_91 ,
V_92 | V_93 ,
V_94 | 0xab ) ;
F_9 ( V_1 -> V_16 , V_95 ,
V_96 | V_97 ,
V_98 | 0xab ) ;
F_9 ( V_1 -> V_16 , V_99 ,
V_100 | V_101 |
V_102 | V_103 ,
( 0x9 << V_104 ) | V_105 |
V_106 | V_107 ) ;
F_9 ( V_1 -> V_16 ,
V_108 , V_109 , 0 ) ;
F_9 ( V_1 -> V_16 , V_47 ,
V_110 | V_111 , 0 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_9 ( V_1 -> V_16 , V_64 ,
V_65 , 0 ) ;
F_9 ( V_1 -> V_16 , V_61 ,
V_62 | V_63 ,
V_62 | V_63 ) ;
F_9 ( V_1 -> V_16 , V_47 ,
V_110 | V_111 ,
V_110 | V_111 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_113 | V_114 |
V_115 , V_115 ) ;
F_9 ( V_1 -> V_16 , V_54 ,
V_59 | V_60 , 0 ) ;
F_9 ( V_1 -> V_16 , V_54 ,
V_55 | V_56 |
V_57 | V_58 , 0 ) ;
F_9 ( V_1 -> V_16 , V_50 ,
V_51 | V_52 , 0 ) ;
F_9 ( V_1 -> V_16 , V_47 ,
V_48 | V_49 , 0 ) ;
F_9 ( V_1 -> V_16 , V_41 ,
V_42 | V_43 |
V_45 | V_46 , 0 ) ;
if ( ! V_1 -> V_116 )
F_9 ( V_1 -> V_16 ,
V_41 , V_44 , 0 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_9 ( V_1 -> V_16 , V_69 ,
V_70 | V_71 , 0 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
F_29 ( V_1 , V_117 , 0 ) ;
F_26 ( V_1 ) ;
F_27 ( V_1 ) ;
F_21 ( V_1 -> V_16 , V_99 , 0 ) ;
F_9 ( V_1 -> V_16 , V_108 ,
V_109 , V_109 ) ;
F_9 ( V_1 -> V_16 , V_85 ,
V_86 | V_87 |
V_88 , V_118 ) ;
F_20 ( V_1 ) ;
}
static void F_30 ( struct V_1 * V_1 , int V_119 )
{
F_9 ( V_1 -> V_16 , V_120 ,
V_121 , V_119 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_122 | V_123 ,
V_123 ) ;
switch ( V_1 -> V_124 ) {
case V_125 :
F_9 ( V_1 -> V_16 , V_112 ,
V_113 | V_114 ,
V_113 ) ;
break;
case V_126 :
F_9 ( V_1 -> V_16 , V_112 ,
V_113 | V_114 ,
V_114 ) ;
break;
default:
break;
}
F_31 ( 100 ) ;
F_9 ( V_1 -> V_16 , V_99 ,
V_127 , V_127 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
F_9 ( V_1 -> V_16 ,
V_99 , V_127 , 0 ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
T_1 V_32 ;
switch ( V_1 -> V_124 ) {
case V_128 :
F_25 ( V_1 ) ;
F_31 ( 280 ) ;
V_1 -> V_124 = V_125 ;
F_30 ( V_1 , 0x00d2 ) ;
break;
case V_125 :
F_19 ( V_1 -> V_16 , V_129 ,
& V_1 -> V_130 [ V_125 ] ) ;
F_34 ( V_1 -> V_5 , L_3 ,
V_1 -> V_130 [ V_125 ] ) ;
F_32 ( V_1 ) ;
V_1 -> V_124 = V_126 ;
F_30 ( V_1 , 0x00ff ) ;
break;
case V_126 :
F_19 ( V_1 -> V_16 , V_129 ,
& V_1 -> V_130 [ V_126 ] ) ;
F_34 ( V_1 -> V_5 , L_4 ,
V_1 -> V_130 [ V_126 ] ) ;
F_32 ( V_1 ) ;
F_31 ( 150 ) ;
V_1 -> V_124 = V_131 ;
break;
case V_131 :
V_32 = F_13 (
V_1 -> V_130 [ V_125 ] ,
V_1 -> V_130 [ V_126 ] ) ;
F_34 ( V_1 -> V_5 , L_5 , V_32 ) ;
F_21 ( V_1 -> V_16 , V_132 ,
( V_32 << 8 ) | V_32 ) ;
F_28 ( V_1 ) ;
V_1 -> V_124 = V_133 ;
break;
default:
break;
}
}
static void F_35 ( struct V_134 * V_135 )
{
struct V_1 * V_1 = F_36 (
V_135 , struct V_1 , V_136 ) ;
F_33 ( V_1 ) ;
if ( V_1 -> V_124 == V_131 )
F_33 ( V_1 ) ;
if ( V_1 -> V_124 == V_133 ) {
F_37 ( V_1 -> V_137 , V_1 -> V_138 ,
V_1 -> V_139 ) ;
F_5 ( V_1 ) ;
V_1 -> V_140 = false ;
}
}
static void F_38 ( struct V_1 * V_1 )
{
if ( V_1 -> V_140 ) {
F_39 ( & V_1 -> V_136 ) ;
F_28 ( V_1 ) ;
}
F_7 ( V_1 ) ;
V_1 -> V_124 = V_133 ;
V_1 -> V_140 = false ;
}
static bool F_40 ( struct V_141 * V_5 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_41 ... V_142 :
case V_61 ... V_143 :
case V_108 ... V_144 :
case V_145 ... V_95 :
case V_146 ... V_147 :
case V_148 ... V_149 :
case V_99 ... V_150 :
case V_66 ... V_151 :
case V_152 :
case V_153 ... V_154 :
case V_112 :
case V_155 ... V_156 :
case V_157 ... V_158 :
case V_64 ... V_159 :
case V_54 ... V_160 :
return true ;
default:
return false ;
}
}
static bool F_41 ( struct V_141 * V_5 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_161 ... V_142 :
case V_61 ... V_143 :
case V_108 :
case V_162 ... V_144 :
case V_145 ... V_95 :
case V_146 ... V_147 :
case V_148 ... V_149 :
case V_99 :
case V_66 ... V_151 :
case V_152 :
case V_112 :
case V_155 ... V_156 :
case V_157 ... V_158 :
case V_64 ... V_159 :
case V_54 ... V_47 :
return true ;
default:
return false ;
}
}
static bool F_42 ( struct V_141 * V_5 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_161 :
case V_163 :
case V_162 :
case V_129 :
case V_150 :
case V_153 :
case V_154 :
case V_164 :
case V_160 :
case V_165 ... V_166 :
return true ;
default:
return false ;
}
}
static int F_43 ( struct V_167 * V_168 ,
struct V_169 * V_170 , int V_171 )
{
struct V_172 * V_173 = F_44 ( V_168 -> V_174 ) ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
switch ( V_171 ) {
case V_175 :
F_9 ( V_1 -> V_16 , V_41 ,
V_44 , V_44 ) ;
break;
case V_176 :
if ( ! V_1 -> V_116 )
F_9 ( V_1 -> V_16 ,
V_41 , V_44 , 0 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_46 ( struct V_167 * V_168 ,
struct V_169 * V_170 , int V_171 )
{
struct V_172 * V_173 = F_44 ( V_168 -> V_174 ) ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
switch ( V_171 ) {
case V_175 :
F_31 ( 10 ) ;
F_9 ( V_1 -> V_16 , V_47 ,
V_48 , V_48 ) ;
break;
case V_177 :
F_9 ( V_1 -> V_16 , V_47 ,
V_48 , 0 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_47 ( struct V_167 * V_168 ,
struct V_169 * V_170 , int V_171 )
{
struct V_172 * V_173 = F_44 ( V_168 -> V_174 ) ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
switch ( V_171 ) {
case V_178 :
F_9 ( V_1 -> V_16 , V_112 ,
V_115 , 0 ) ;
break;
case V_176 :
F_9 ( V_1 -> V_16 , V_112 ,
V_115 , V_115 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_48 ( struct V_169 * V_170 ,
struct V_179 * V_180 )
{
struct V_181 * V_182 = F_49 ( V_170 ) ;
struct V_183 * V_184 = ( void * ) V_170 -> V_185 ;
if ( ! V_182 -> V_16 )
return - V_38 ;
F_50 ( V_182 -> V_16 , V_186 ,
V_180 -> V_10 . V_187 . V_188 , V_184 -> V_189 ) ;
return 0 ;
}
static int F_51 ( struct V_169 * V_170 ,
struct V_179 * V_180 )
{
struct V_181 * V_182 = F_49 ( V_170 ) ;
struct V_183 * V_184 = ( void * ) V_170 -> V_185 ;
void * V_188 ;
if ( ! V_182 -> V_16 )
return - V_38 ;
V_188 = F_52 ( V_180 -> V_10 . V_187 . V_188 ,
V_184 -> V_189 , V_190 | V_191 ) ;
if ( ! V_188 )
return - V_192 ;
F_9 ( V_182 -> V_16 , V_165 ,
V_193 , 0 ) ;
F_53 ( V_182 -> V_16 , V_186 ,
V_188 , V_184 -> V_189 ) ;
F_9 ( V_182 -> V_16 , V_165 ,
V_193 , V_193 ) ;
F_54 ( V_188 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 ,
int V_194 , int V_195 , int V_196 )
{
int V_197 ;
if ( V_194 == V_198 ) {
if ( V_196 >= F_17 ( V_199 ) )
return - V_38 ;
V_197 = V_199 [ V_196 ] . V_196 ;
} else {
if ( V_196 >= F_17 ( V_200 ) )
return - V_38 ;
V_197 = V_200 [ V_196 ] . V_196 ;
}
if ( ! V_197 || V_195 * V_196 > V_201 ) {
F_56 ( V_1 -> V_5 , L_6 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_57 ( struct V_202 * V_203 ,
struct V_204 * V_184 ,
struct V_205 * V_206 )
{
struct V_172 * V_173 = V_206 -> V_173 ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
unsigned int V_207 = 0 , V_196 ;
F_1 ( V_1 , 3 * V_208 ) ;
if ( V_203 -> V_194 == V_198 ) {
F_19 ( V_1 -> V_16 , V_209 , & V_196 ) ;
V_196 &= V_210 ;
if ( F_55 ( V_1 , V_203 -> V_194 ,
F_58 ( V_184 ) , V_196 ) )
return - V_38 ;
F_9 ( V_1 -> V_16 , V_79 ,
V_211 ,
V_199 [ V_196 ] . V_212 << V_213 ) ;
} else {
F_19 ( V_1 -> V_16 , V_214 , & V_196 ) ;
V_196 &= V_215 ;
if ( F_55 ( V_1 , V_203 -> V_194 ,
F_58 ( V_184 ) , V_196 ) )
return - V_38 ;
F_9 ( V_1 -> V_16 , V_79 ,
V_216 ,
V_200 [ V_196 ] . V_212 << V_217 ) ;
}
switch ( F_59 ( V_184 ) ) {
case 16 :
V_207 |= V_218 ;
break;
case 20 :
V_207 |= V_219 ;
break;
case 24 :
V_207 |= V_220 ;
break;
case 32 :
V_207 |= V_221 ;
break;
default:
return - V_38 ;
}
F_9 ( V_1 -> V_16 , V_222 ,
V_223 , V_207 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static int F_60 ( struct V_205 * V_224 , unsigned int V_225 )
{
struct V_172 * V_173 = V_224 -> V_173 ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
unsigned int V_226 = 0 , V_227 = 0 ;
F_1 ( V_1 , 3 * V_208 ) ;
switch ( V_225 & V_228 ) {
case V_229 :
V_227 |= V_89 ;
break;
case V_230 :
break;
default:
return - V_38 ;
}
switch ( V_225 & V_231 ) {
case V_232 :
break;
case V_233 :
V_226 |= V_234 ;
break;
default:
return - V_38 ;
}
switch ( V_225 & V_235 ) {
case V_236 :
V_226 |= V_237 ;
break;
case V_238 :
V_226 |= V_239 ;
break;
case V_240 :
V_226 |= V_241 ;
break;
case V_242 :
V_226 |= V_243 ;
break;
case V_244 :
V_226 |= V_243 ;
V_226 |= V_245 ;
break;
default:
return - V_38 ;
}
F_9 ( V_1 -> V_16 , V_222 ,
V_223 | V_246 |
V_247 | V_248 ,
V_226 ) ;
F_9 ( V_1 -> V_16 , V_85 ,
V_86 , V_227 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
int F_61 ( struct V_172 * V_173 ,
struct V_249 * V_137 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_16 * V_16 = V_1 -> V_16 ;
V_1 -> V_137 = V_137 ;
F_9 ( V_16 , V_61 ,
V_250 | V_62 | V_63 ,
V_250 | V_62 | V_63 ) ;
return 0 ;
}
static bool F_62 ( struct V_16 * V_16 )
{
bool V_251 , V_252 ;
int V_253 , V_254 ;
F_19 ( V_16 , V_143 , & V_254 ) ;
V_251 = V_254 & V_255 ;
F_19 ( V_16 , V_153 , & V_253 ) ;
V_252 = V_253 & V_256 ;
return V_251 == V_252 ;
}
static void F_63 ( struct V_16 * V_16 )
{
F_9 ( V_16 , V_143 ,
V_257 , V_257 ) ;
F_9 ( V_16 , V_143 ,
V_257 , 0 ) ;
}
static void F_64 ( struct V_16 * V_16 )
{
int V_258 , V_259 , V_39 ;
F_19 ( V_16 , V_163 , & V_258 ) ;
for ( V_39 = 0 ; V_39 < V_260 ; V_39 ++ ) {
V_259 = ( 0x1 << V_39 ) ;
if ( V_258 & V_259 )
F_21 ( V_16 ,
V_162 , V_259 ) ;
}
}
static void F_65 ( struct V_1 * V_1 )
{
struct V_261 * V_174 = V_1 -> V_174 ;
struct V_16 * V_16 = V_1 -> V_16 ;
F_38 ( V_1 ) ;
F_66 ( V_174 , L_7 ) ;
F_66 ( V_174 , L_8 ) ;
F_9 ( V_16 , V_158 ,
V_262 | V_263 , 0 ) ;
F_9 ( V_16 , V_61 , 0xf , 0xf ) ;
F_67 ( V_174 ) ;
F_64 ( V_16 ) ;
F_9 ( V_16 , V_264 ,
V_265 | V_266 ,
V_265 ) ;
F_9 ( V_16 , V_108 ,
V_267 | V_268 |
V_269 | V_270 ,
V_267 | V_268 |
V_269 ) ;
F_9 ( V_16 , V_143 ,
V_271 , V_271 ) ;
F_9 ( V_16 , V_41 ,
V_44 , 0 ) ;
F_29 ( V_1 , V_272 , 0 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_9 ( V_16 , V_108 ,
V_269 | V_268 , 0 ) ;
F_29 ( V_1 , V_117 , 0 ) ;
F_9 ( V_16 , V_41 ,
V_44 , V_44 ) ;
F_9 ( V_16 , V_85 ,
V_86 , V_89 ) ;
F_9 ( V_16 , V_85 ,
V_86 , V_118 ) ;
F_9 ( V_16 , V_143 ,
V_271 , 0 ) ;
F_21 ( V_16 , V_264 , 0 ) ;
F_63 ( V_16 ) ;
}
static int F_69 ( int V_10 )
{
int V_273 = 0 ;
if ( V_10 & F_70 ( 0 ) )
V_273 |= V_274 ;
if ( V_10 & F_70 ( 1 ) )
V_273 |= V_275 ;
if ( V_10 & F_70 ( 2 ) )
V_273 |= V_276 ;
if ( V_10 & F_70 ( 3 ) )
V_273 |= V_277 ;
if ( V_10 & F_70 ( 4 ) )
V_273 |= V_278 ;
if ( V_10 & F_70 ( 5 ) )
V_273 |= V_279 ;
return V_273 ;
}
static int F_71 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
struct V_261 * V_174 = V_1 -> V_174 ;
int V_280 , V_281 ;
int type = 0 ;
F_19 ( V_16 , V_160 , & V_280 ) ;
V_281 = ( V_280 >> 10 ) & 3 ;
if ( V_281 == 0x3 )
V_1 -> V_282 = true ;
else
V_1 -> V_282 = false ;
switch ( V_281 ) {
case 0 :
type = V_283 ;
break;
case 1 :
F_34 ( V_1 -> V_5 , L_9 ) ;
type = V_284 ;
F_9 ( V_16 , V_61 , 3 << 2 ,
1 << 2 ) ;
F_9 ( V_16 , V_158 ,
V_262 | V_263 ,
V_263 ) ;
F_9 ( V_16 , V_285 ,
V_286 ,
V_287 ) ;
F_72 ( V_174 , L_8 ) ;
F_72 ( V_174 , L_7 ) ;
F_67 ( V_174 ) ;
break;
case 2 :
case 3 :
F_34 ( V_1 -> V_5 , L_10 ) ;
type = V_284 ;
F_9 ( V_16 , V_61 , 3 << 2 ,
2 << 2 ) ;
F_9 ( V_16 , V_158 ,
V_262 | V_263 ,
V_262 ) ;
F_9 ( V_16 , V_285 ,
V_286 ,
V_288 ) ;
F_72 ( V_174 , L_8 ) ;
F_72 ( V_174 , L_7 ) ;
F_67 ( V_174 ) ;
break;
}
return type ;
}
static T_3 F_73 ( int V_116 , void * V_188 )
{
struct V_1 * V_1 = (struct V_1 * ) V_188 ;
struct V_16 * V_16 = V_1 -> V_16 ;
int V_258 , V_259 = 0 , V_171 = 0 , V_289 = 0 ;
if ( F_19 ( V_16 , V_163 , & V_258 ) ) {
F_56 ( V_1 -> V_5 , L_11 ) ;
return V_290 ;
}
if ( ( V_258 & V_291 ) ==
V_292 ) {
F_65 ( V_1 ) ;
V_289 |= V_284 ;
V_259 = V_291 ;
} else if ( V_258 & V_293 ) {
int V_294 ;
F_19 ( V_16 , V_162 ,
& V_294 ) ;
V_1 -> V_295 = F_69 (
V_294 >> 8 ) ;
V_171 |= V_1 -> V_295 ;
V_289 |= V_296 ;
V_259 = V_293 ;
} else if ( V_258 & V_297 ) {
V_289 = V_296 ;
V_259 = V_297 ;
} else if ( V_258 & V_298 ) {
if ( F_62 ( V_16 ) ) {
V_171 |= F_71 ( V_1 ) ;
if ( ! V_1 -> V_282 ) {
if ( ! V_1 -> V_140 ) {
int V_3 ;
V_1 -> V_140 = true ;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 < 0 )
V_1 -> V_140 = false ;
}
V_1 -> V_124 = V_128 ;
F_74 ( & V_1 -> V_136 ) ;
} else {
if ( V_1 -> V_140 ) {
F_5 ( V_1 ) ;
V_1 -> V_140 = false ;
}
}
} else {
F_3 ( V_1 -> V_5 , L_12 ) ;
F_65 ( V_1 ) ;
}
V_289 |= V_284 ;
V_259 = V_298 ;
if ( V_1 -> V_124 == V_128 ) {
V_1 -> V_138 = V_171 ;
V_1 -> V_139 = V_289 ;
}
} else if ( V_258 & V_299 ) {
F_74 ( & V_1 -> V_136 ) ;
V_259 = V_299 ;
} else if ( ( V_258 & V_300 ) ==
V_301 ) {
if ( F_62 ( V_16 ) ) {
F_9 ( V_16 ,
V_264 ,
V_266 ,
V_266 ) ;
F_9 ( V_16 , V_108 ,
V_270 , V_270 ) ;
F_68 ( V_1 ) ;
}
}
if ( ! V_259 )
V_259 = V_258 ;
F_21 ( V_16 , V_162 , V_259 ) ;
if ( V_289 && V_1 -> V_124 == V_133 )
F_37 ( V_1 -> V_137 , V_171 , V_289 ) ;
return V_302 ;
}
static void F_75 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_9 ( V_16 , V_285 ,
V_303 ,
V_1 -> V_304 << V_305 ) ;
F_9 ( V_16 , V_285 ,
V_306 ,
V_1 -> V_307 << V_308 ) ;
F_9 ( V_16 , V_285 ,
V_309 ,
V_1 -> V_310 << V_311 ) ;
F_9 ( V_16 , V_144 ,
V_312 ,
( V_1 -> V_313 - 1 ) << V_314 ) ;
F_9 ( V_16 , V_144 ,
V_315 ,
V_1 -> V_316 << V_317 ) ;
F_9 ( V_16 , V_144 ,
V_318 ,
V_1 -> V_319 << V_320 ) ;
F_21 ( V_16 , V_145 ,
( V_1 -> V_321 [ 0 ] << 8 ) | V_1 -> V_321 [ 1 ] ) ;
F_21 ( V_16 , V_322 ,
( V_1 -> V_321 [ 2 ] << 8 ) | V_1 -> V_321 [ 3 ] ) ;
F_21 ( V_16 , V_323 ,
( V_1 -> V_321 [ 4 ] << 8 ) | V_1 -> V_321 [ 5 ] ) ;
F_21 ( V_16 , V_324 ,
( V_1 -> V_321 [ 6 ] << 8 ) | V_1 -> V_321 [ 7 ] ) ;
F_9 ( V_16 , V_108 ,
V_325 | V_326 ,
0 ) ;
}
static void F_76 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_21 ( V_16 , V_327 , 0x0001 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_328 , V_328 ) ;
F_9 ( V_1 -> V_16 , V_64 ,
V_329 , V_329 ) ;
F_9 ( V_16 , V_112 ,
V_330 ,
V_1 -> V_331 << V_332 ) ;
F_9 ( V_16 , V_64 ,
V_333 | V_65 |
V_334 | V_335 ,
V_333 | V_65 |
V_334 | V_335 ) ;
F_9 ( V_16 , V_336 ,
V_337 ,
V_1 -> V_338 ? 0 : V_337 ) ;
F_9 ( V_16 , V_336 ,
V_339 ,
V_1 -> V_340 ? 0 : V_339 ) ;
F_9 ( V_16 , V_336 ,
V_341 ,
V_1 -> V_342 ? V_341 : 0 ) ;
F_9 ( V_16 , V_143 ,
V_255 ,
V_1 -> V_343 ? 0 : V_255 ) ;
F_9 ( V_16 , V_143 ,
V_344 ,
V_1 -> V_345 << V_346 ) ;
F_9 ( V_16 , V_143 ,
V_347 ,
V_1 -> V_348 << V_349 ) ;
F_9 ( V_16 , V_108 , 0x7ff , 0x7ff ) ;
F_9 ( V_16 , V_158 ,
V_350 , V_1 -> V_351 ) ;
if ( V_1 -> V_313 )
F_75 ( V_1 ) ;
F_9 ( V_16 , V_214 ,
V_215 | V_352 ,
V_353 ) ;
F_9 ( V_16 , V_209 ,
V_210 , V_354 ) ;
F_9 ( V_16 , V_47 ,
V_110 | V_111 ,
V_110 | V_111 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_115 , V_115 ) ;
F_9 ( V_16 , V_209 ,
V_355 , V_355 ) ;
F_9 ( V_16 , V_156 ,
V_356 |
V_357 | V_358 ,
V_356 |
V_357 | V_358 ) ;
F_9 ( V_16 , V_66 ,
V_359 ,
0x20 << V_360 ) ;
F_9 ( V_16 , V_50 ,
V_361 | V_362 ,
( 0x2 << V_363 ) |
( 0x3 << V_364 ) ) ;
F_9 ( V_1 -> V_16 , V_91 ,
V_92 , V_94 ) ;
F_9 ( V_1 -> V_16 , V_95 ,
V_92 , V_365 ) ;
F_9 ( V_16 , V_366 ,
V_367 , V_367 ) ;
}
static int F_77 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_261 * V_174 = F_78 ( V_173 ) ;
V_1 -> V_174 = V_174 ;
return 0 ;
}
static int F_79 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_80 ( unsigned int V_368 , unsigned int V_369 ,
struct V_370 * V_371 )
{
T_2 V_372 , V_373 ;
unsigned int V_374 , V_39 , V_375 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_376 ) ; V_39 ++ ) {
V_374 = V_368 / V_376 [ V_39 ] . V_377 ;
if ( V_374 <= V_378 )
break;
}
if ( V_39 == F_17 ( V_376 ) )
return - V_38 ;
V_371 -> V_379 = V_376 [ V_39 ] . V_380 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_381 ) ; V_39 ++ ) {
if ( V_374 >= V_381 [ V_39 ] . V_377 )
break;
}
if ( V_39 == F_17 ( V_381 ) )
return - V_38 ;
V_371 -> V_382 = V_381 [ V_39 ] . V_380 ;
V_373 = 0 ;
V_375 = F_17 ( V_383 ) ;
for ( V_39 = 0 ; V_39 < F_17 ( V_383 ) ; V_39 ++ ) {
V_372 = 256 * V_369 * 2 * V_383 [ V_39 ] . V_377 ;
if ( V_372 > V_384 && V_372 < V_385 &&
V_373 < V_372 ) {
V_373 = V_372 ;
V_375 = V_39 ;
}
}
if ( F_17 ( V_383 ) == V_375 )
return - V_38 ;
V_371 -> V_386 = V_383 [ V_375 ] . V_380 ;
V_372 = F_81 ( V_373 << 16 , V_374 * V_371 -> V_382 ) ;
V_371 -> V_387 = ( V_372 >> 16 ) & 0x3FF ;
V_371 -> V_388 = V_372 & 0xFFFF ;
return 0 ;
}
static void F_82 ( struct V_1 * V_1 ,
struct V_370 * V_371 )
{
F_9 ( V_1 -> V_16 , V_79 ,
V_80 | V_83 ,
V_389 | V_371 -> V_386 ) ;
F_9 ( V_1 -> V_16 , V_73 ,
V_84 | V_390 ,
V_371 -> V_382 | ( 0x6 << V_391 ) ) ;
F_21 ( V_1 -> V_16 , V_74 , V_371 -> V_388 ) ;
F_9 ( V_1 -> V_16 , V_75 ,
V_392 , V_371 -> V_387 ) ;
F_9 ( V_1 -> V_16 , V_76 ,
V_393 ,
V_371 -> V_379 << V_394 ) ;
F_9 ( V_1 -> V_16 , V_77 ,
V_395 , V_396 ) ;
F_9 ( V_1 -> V_16 ,
V_78 , V_82 , 0 ) ;
if ( V_371 -> V_388 ) {
F_9 ( V_1 -> V_16 , V_77 ,
V_397 | V_398 |
V_399 ,
V_397 | V_398 |
V_400 ) ;
F_9 ( V_1 -> V_16 , V_78 ,
V_401 | V_402 ,
V_401 | V_402 ) ;
} else {
F_9 ( V_1 -> V_16 , V_77 ,
V_397 | V_398 |
V_399 , V_403 ) ;
F_9 ( V_1 -> V_16 , V_78 ,
V_401 | V_402 , 0 ) ;
}
}
static int F_83 ( struct V_172 * V_173 , int V_404 , int V_405 ,
unsigned int V_406 , unsigned int V_407 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_370 V_371 ;
int V_3 , V_369 ;
V_369 = V_407 / 256 ;
V_3 = F_80 ( V_406 , V_369 , & V_371 ) ;
if ( V_3 < 0 ) {
F_56 ( V_173 -> V_5 , L_13 , V_406 ) ;
return V_3 ;
}
F_34 ( V_173 -> V_5 , L_14 ,
V_371 . V_386 , V_371 . V_382 , V_371 . V_388 ,
V_371 . V_387 , V_371 . V_379 ) ;
F_82 ( V_1 , & V_371 ) ;
F_84 ( 2 ) ;
F_9 ( V_1 -> V_16 , V_79 ,
V_80 , V_81 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_1 , unsigned int V_408 )
{
int V_3 = 0 ;
V_1 -> V_409 = F_86 ( V_1 -> V_5 , L_15 ) ;
if ( F_87 ( V_1 -> V_409 ) ) {
F_88 ( V_1 -> V_5 , L_16 ) ;
return 0 ;
}
if ( ! V_1 -> V_410 ) {
V_3 = F_89 ( V_1 -> V_409 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_17 ) ;
return V_3 ;
}
}
if ( V_1 -> V_410 != V_408 ) {
V_408 = F_90 ( V_1 -> V_409 , V_408 ) ;
V_3 = F_91 ( V_1 -> V_409 , V_408 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_18 ) ;
return V_3 ;
}
V_1 -> V_410 = V_408 ;
}
return 0 ;
}
static void F_92 ( struct V_16 * V_16 )
{
F_9 ( V_16 , V_79 ,
V_80 , V_389 ) ;
F_9 ( V_16 , V_78 ,
V_82 , 0 ) ;
F_9 ( V_16 , V_73 ,
V_390 , 0 ) ;
}
static int F_29 ( struct V_1 * V_1 , int V_411 ,
unsigned int V_408 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
int V_3 ;
switch ( V_411 ) {
case V_272 :
F_92 ( V_16 ) ;
if ( V_1 -> V_410 ) {
F_93 ( V_1 -> V_409 ) ;
V_1 -> V_410 = 0 ;
}
break;
case V_412 :
F_1 ( V_1 , 3 * V_208 ) ;
F_92 ( V_16 ) ;
F_9 ( V_16 , V_79 ,
V_83 , 0 ) ;
F_5 ( V_1 ) ;
V_3 = F_85 ( V_1 , V_408 ) ;
if ( V_3 )
return V_3 ;
break;
case V_117 :
if ( F_62 ( V_1 -> V_16 ) ) {
F_9 ( V_16 , V_78 ,
V_82 , V_82 ) ;
F_9 ( V_16 , V_79 ,
V_80 , V_81 ) ;
F_9 ( V_16 , V_79 ,
V_83 , 0xf ) ;
F_9 ( V_16 , V_73 ,
V_390 |
V_84 , 0x10 ) ;
F_9 ( V_16 , V_78 ,
V_401 , V_401 ) ;
} else {
F_92 ( V_16 ) ;
F_3 ( V_1 -> V_5 , L_19 ) ;
}
if ( V_1 -> V_410 ) {
F_93 ( V_1 -> V_409 ) ;
V_1 -> V_410 = 0 ;
}
break;
case V_413 :
F_1 ( V_1 , 3 * V_208 ) ;
F_9 ( V_16 , V_75 ,
V_414 | V_415 ,
V_416 | 0 ) ;
F_5 ( V_1 ) ;
V_3 = F_85 ( V_1 , V_408 ) ;
if ( V_3 )
return V_3 ;
break;
case V_417 :
F_1 ( V_1 , 3 * V_208 ) ;
F_9 ( V_16 , V_75 ,
V_414 | V_415 ,
V_418 |
( 0xf << V_419 ) ) ;
F_5 ( V_1 ) ;
if ( V_1 -> V_410 ) {
F_93 ( V_1 -> V_409 ) ;
V_1 -> V_410 = 0 ;
}
break;
case V_420 :
F_1 ( V_1 , 3 * V_208 ) ;
F_9 ( V_16 , V_75 ,
V_414 | V_415 ,
V_421 |
( 0xf << V_419 ) ) ;
F_5 ( V_1 ) ;
if ( V_1 -> V_410 ) {
F_93 ( V_1 -> V_409 ) ;
V_1 -> V_410 = 0 ;
}
break;
default:
F_56 ( V_1 -> V_5 , L_20 , V_411 ) ;
return - V_38 ;
}
F_34 ( V_1 -> V_5 , L_21 , V_408 ,
V_411 ) ;
return 0 ;
}
static int F_94 ( struct V_172 * V_173 , int V_411 ,
int V_405 , unsigned int V_408 , int V_422 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
return F_29 ( V_1 , V_411 , V_408 ) ;
}
static int F_95 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_29 ( V_1 , V_272 , 0 ) ;
F_64 ( V_16 ) ;
F_9 ( V_16 , V_108 ,
V_267 | V_269 |
V_268 | V_270 ,
V_267 | V_269 ) ;
F_9 ( V_16 , V_143 ,
V_271 , V_271 ) ;
F_9 ( V_16 , V_264 ,
V_266 | V_265 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_172 * V_173 ,
enum V_423 V_424 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
int V_3 ;
switch ( V_424 ) {
case V_425 :
break;
case V_426 :
break;
case V_427 :
if ( F_97 ( V_173 ) == V_428 ) {
if ( V_1 -> V_410 ) {
V_3 = F_89 ( V_1 -> V_409 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_17 ) ;
return V_3 ;
}
}
F_95 ( V_1 ) ;
}
break;
case V_428 :
F_38 ( V_1 ) ;
F_21 ( V_1 -> V_16 ,
V_264 , 0xffff ) ;
F_9 ( V_1 -> V_16 , V_41 ,
V_44 , 0 ) ;
if ( V_1 -> V_410 )
F_93 ( V_1 -> V_409 ) ;
break;
}
return 0 ;
}
static int T_4 F_98 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
F_99 ( V_1 -> V_116 ) ;
F_100 ( V_173 , V_428 ) ;
F_101 ( V_1 -> V_16 , true ) ;
F_102 ( V_1 -> V_16 ) ;
return 0 ;
}
static int T_4 F_103 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
int V_3 ;
F_101 ( V_1 -> V_16 , false ) ;
F_104 ( V_1 -> V_16 ) ;
V_1 -> V_140 = true ;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 < 0 )
V_1 -> V_140 = false ;
F_105 ( V_1 -> V_116 ) ;
return 0 ;
}
static void F_106 ( struct V_16 * V_16 )
{
F_21 ( V_16 , V_161 , 0x00 ) ;
F_21 ( V_16 , V_161 , 0x00 ) ;
}
static void F_107 ( struct V_1 * V_1 )
{
int V_39 ;
struct V_141 * V_5 = V_1 -> V_5 ;
F_34 ( V_5 , L_22 , V_1 -> V_338 ) ;
F_34 ( V_5 , L_23 , V_1 -> V_340 ) ;
F_34 ( V_5 , L_24 , V_1 -> V_342 ) ;
F_34 ( V_5 , L_25 , V_1 -> V_343 ) ;
F_34 ( V_5 , L_26 , V_1 -> V_351 ) ;
F_34 ( V_5 , L_27 , V_1 -> V_331 ) ;
F_34 ( V_5 , L_28 , V_1 -> V_313 ) ;
for ( V_39 = 0 ; V_39 < V_1 -> V_313 ; V_39 ++ )
F_34 ( V_5 , L_29 , V_39 ,
V_1 -> V_321 [ V_39 ] ) ;
F_34 ( V_5 , L_30 , V_1 -> V_316 ) ;
F_34 ( V_5 , L_31 , V_1 -> V_304 ) ;
F_34 ( V_5 , L_32 , V_1 -> V_307 ) ;
F_34 ( V_5 , L_33 , V_1 -> V_310 ) ;
F_34 ( V_5 , L_34 , V_1 -> V_319 ) ;
F_34 ( V_5 , L_35 ,
V_1 -> V_345 ) ;
F_34 ( V_5 , L_36 ,
V_1 -> V_348 ) ;
}
static int F_108 ( struct V_141 * V_5 ,
struct V_1 * V_1 ) {
V_1 -> V_338 = F_109 ( V_5 ,
L_37 ) ;
V_1 -> V_340 = F_109 ( V_5 ,
L_38 ) ;
V_1 -> V_342 = F_109 ( V_5 ,
L_39 ) ;
F_110 ( V_5 , L_40 ,
& V_1 -> V_343 ) ;
F_110 ( V_5 , L_41 ,
& V_1 -> V_351 ) ;
F_110 ( V_5 , L_42 ,
& V_1 -> V_331 ) ;
F_110 ( V_5 , L_43 ,
& V_1 -> V_313 ) ;
F_111 ( V_5 , L_44 ,
V_1 -> V_321 , V_1 -> V_313 ) ;
F_110 ( V_5 , L_45 ,
& V_1 -> V_316 ) ;
F_110 ( V_5 , L_46 ,
& V_1 -> V_304 ) ;
F_110 ( V_5 , L_47 ,
& V_1 -> V_307 ) ;
F_110 ( V_5 , L_48 ,
& V_1 -> V_310 ) ;
F_110 ( V_5 , L_49 ,
& V_1 -> V_319 ) ;
F_110 ( V_5 , L_50 ,
& V_1 -> V_345 ) ;
F_110 ( V_5 , L_51 ,
& V_1 -> V_348 ) ;
V_1 -> V_409 = F_86 ( V_5 , L_15 ) ;
if ( F_112 ( V_1 -> V_409 ) == - V_429 ) {
return - V_429 ;
} else if ( F_112 ( V_1 -> V_409 ) == - V_430 ) {
V_1 -> V_409 = NULL ;
F_88 ( V_5 , L_16 ) ;
} else if ( F_87 ( V_1 -> V_409 ) ) {
return - V_38 ;
}
return 0 ;
}
static int F_113 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_114 ( V_1 -> V_5 , V_1 -> V_116 , NULL ,
F_73 , V_431 | V_432 ,
L_52 , V_1 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_53 ,
V_1 -> V_116 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int F_115 ( struct V_433 * V_434 ,
const struct V_435 * V_436 )
{
struct V_141 * V_5 = & V_434 -> V_5 ;
struct V_1 * V_1 = F_116 ( & V_434 -> V_5 ) ;
int V_3 , V_10 ;
if ( ! V_1 ) {
V_1 = F_117 ( V_5 , sizeof( * V_1 ) , V_190 ) ;
if ( ! V_1 )
return - V_192 ;
V_3 = F_108 ( V_5 , V_1 ) ;
if ( V_3 )
return V_3 ;
}
F_118 ( V_434 , V_1 ) ;
V_1 -> V_16 = F_119 ( V_434 , & V_437 ) ;
if ( F_87 ( V_1 -> V_16 ) )
return F_112 ( V_1 -> V_16 ) ;
V_1 -> V_5 = V_5 ;
V_1 -> V_116 = V_434 -> V_116 ;
V_1 -> V_124 = V_133 ;
V_1 -> V_140 = false ;
F_120 ( & V_1 -> V_4 , 1 ) ;
F_121 ( & V_1 -> V_136 , F_35 ) ;
F_107 ( V_1 ) ;
F_106 ( V_1 -> V_16 ) ;
V_3 = F_19 ( V_1 -> V_16 , V_153 , & V_10 ) ;
if ( V_3 < 0 ) {
F_56 ( V_5 , L_54 ,
V_3 ) ;
return V_3 ;
}
if ( ( V_10 & V_438 ) !=
V_439 ) {
F_56 ( V_5 , L_55 ) ;
return - V_440 ;
}
F_76 ( V_1 ) ;
if ( V_434 -> V_116 )
F_113 ( V_1 ) ;
return F_122 ( & V_434 -> V_5 , & V_441 ,
& V_442 , 1 ) ;
}
static int F_123 ( struct V_433 * V_443 )
{
F_124 ( & V_443 -> V_5 ) ;
return 0 ;
}
