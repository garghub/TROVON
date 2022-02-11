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
unsigned int V_207 = 0 , V_196 , V_208 , V_209 , V_210 ;
F_1 ( V_1 , 3 * V_211 ) ;
if ( V_203 -> V_194 == V_198 ) {
F_19 ( V_1 -> V_16 , V_212 , & V_196 ) ;
V_196 &= V_213 ;
if ( F_55 ( V_1 , V_203 -> V_194 ,
F_58 ( V_184 ) , V_196 ) )
return - V_38 ;
F_9 ( V_1 -> V_16 , V_79 ,
V_214 ,
V_199 [ V_196 ] . V_215 << V_216 ) ;
} else {
F_19 ( V_1 -> V_16 , V_217 , & V_196 ) ;
V_196 &= V_218 ;
if ( F_55 ( V_1 , V_203 -> V_194 ,
F_58 ( V_184 ) , V_196 ) )
return - V_38 ;
F_9 ( V_1 -> V_16 , V_79 ,
V_219 ,
V_200 [ V_196 ] . V_215 << V_220 ) ;
}
F_19 ( V_1 -> V_16 , V_85 , & V_208 ) ;
if ( V_208 & V_89 ) {
V_209 = F_59 ( V_184 ) / F_58 ( V_184 ) ;
if ( V_209 <= 32 )
V_210 = 2 ;
else if ( V_209 <= 64 )
V_210 = 1 ;
else if ( V_209 <= 128 )
V_210 = 0 ;
else
return - V_38 ;
F_9 ( V_1 -> V_16 , V_85 ,
V_87 | V_88 ,
( ( V_210 + 1 ) << V_90 ) | V_210 ) ;
}
switch ( F_60 ( V_184 ) ) {
case 16 :
V_207 |= V_221 ;
break;
case 20 :
V_207 |= V_222 ;
break;
case 24 :
V_207 |= V_223 ;
break;
case 32 :
V_207 |= V_224 ;
break;
default:
return - V_38 ;
}
F_9 ( V_1 -> V_16 , V_225 ,
V_226 , V_207 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static int F_61 ( struct V_205 * V_227 , unsigned int V_228 )
{
struct V_172 * V_173 = V_227 -> V_173 ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
unsigned int V_229 = 0 , V_230 = 0 ;
F_1 ( V_1 , 3 * V_211 ) ;
switch ( V_228 & V_231 ) {
case V_232 :
V_230 |= V_89 ;
break;
case V_233 :
break;
default:
return - V_38 ;
}
switch ( V_228 & V_234 ) {
case V_235 :
break;
case V_236 :
V_229 |= V_237 ;
break;
default:
return - V_38 ;
}
switch ( V_228 & V_238 ) {
case V_239 :
V_229 |= V_240 ;
break;
case V_241 :
V_229 |= V_242 ;
break;
case V_243 :
V_229 |= V_244 ;
break;
case V_245 :
V_229 |= V_246 ;
break;
case V_247 :
V_229 |= V_246 ;
V_229 |= V_248 ;
break;
default:
return - V_38 ;
}
F_9 ( V_1 -> V_16 , V_225 ,
V_226 | V_249 |
V_250 | V_251 ,
V_229 ) ;
F_9 ( V_1 -> V_16 , V_85 ,
V_86 , V_230 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
int F_62 ( struct V_172 * V_173 ,
struct V_252 * V_137 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_16 * V_16 = V_1 -> V_16 ;
V_1 -> V_137 = V_137 ;
F_9 ( V_16 , V_61 ,
V_253 | V_62 | V_63 ,
V_253 | V_62 | V_63 ) ;
return 0 ;
}
static bool F_63 ( struct V_16 * V_16 )
{
bool V_254 , V_255 ;
int V_256 , V_257 ;
F_19 ( V_16 , V_143 , & V_257 ) ;
V_254 = V_257 & V_258 ;
F_19 ( V_16 , V_153 , & V_256 ) ;
V_255 = V_256 & V_259 ;
return V_254 == V_255 ;
}
static void F_64 ( struct V_16 * V_16 )
{
F_9 ( V_16 , V_143 ,
V_260 , V_260 ) ;
F_9 ( V_16 , V_143 ,
V_260 , 0 ) ;
}
static void F_65 ( struct V_16 * V_16 )
{
int V_261 , V_262 , V_39 ;
F_19 ( V_16 , V_163 , & V_261 ) ;
for ( V_39 = 0 ; V_39 < V_263 ; V_39 ++ ) {
V_262 = ( 0x1 << V_39 ) ;
if ( V_261 & V_262 )
F_21 ( V_16 ,
V_162 , V_262 ) ;
}
}
static void F_66 ( struct V_1 * V_1 )
{
struct V_264 * V_174 = V_1 -> V_174 ;
struct V_16 * V_16 = V_1 -> V_16 ;
F_38 ( V_1 ) ;
F_67 ( V_174 , L_7 ) ;
F_67 ( V_174 , L_8 ) ;
F_9 ( V_16 , V_158 ,
V_265 | V_266 , 0 ) ;
F_9 ( V_16 , V_61 , 0xf , 0xf ) ;
F_68 ( V_174 ) ;
F_65 ( V_16 ) ;
F_9 ( V_16 , V_267 ,
V_268 | V_269 ,
V_268 ) ;
F_9 ( V_16 , V_108 ,
V_270 | V_271 |
V_272 | V_273 ,
V_270 | V_271 |
V_272 ) ;
F_9 ( V_16 , V_143 ,
V_274 , V_274 ) ;
F_9 ( V_16 , V_41 ,
V_44 , 0 ) ;
F_29 ( V_1 , V_275 , 0 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_9 ( V_16 , V_108 ,
V_272 | V_271 , 0 ) ;
F_29 ( V_1 , V_117 , 0 ) ;
F_9 ( V_16 , V_41 ,
V_44 , V_44 ) ;
F_9 ( V_16 , V_85 ,
V_86 , V_89 ) ;
F_9 ( V_16 , V_85 ,
V_86 , V_118 ) ;
F_9 ( V_16 , V_143 ,
V_274 , 0 ) ;
F_21 ( V_16 , V_267 , 0 ) ;
F_64 ( V_16 ) ;
}
static int F_70 ( int V_10 )
{
int V_276 = 0 ;
if ( V_10 & F_71 ( 0 ) )
V_276 |= V_277 ;
if ( V_10 & F_71 ( 1 ) )
V_276 |= V_278 ;
if ( V_10 & F_71 ( 2 ) )
V_276 |= V_279 ;
if ( V_10 & F_71 ( 3 ) )
V_276 |= V_280 ;
if ( V_10 & F_71 ( 4 ) )
V_276 |= V_281 ;
if ( V_10 & F_71 ( 5 ) )
V_276 |= V_282 ;
return V_276 ;
}
static int F_72 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
struct V_264 * V_174 = V_1 -> V_174 ;
int V_283 , V_284 ;
int type = 0 ;
F_19 ( V_16 , V_160 , & V_283 ) ;
V_284 = ( V_283 >> 10 ) & 3 ;
if ( V_284 == 0x3 )
V_1 -> V_285 = true ;
else
V_1 -> V_285 = false ;
switch ( V_284 ) {
case 0 :
type = V_286 ;
break;
case 1 :
F_34 ( V_1 -> V_5 , L_9 ) ;
type = V_287 ;
F_9 ( V_16 , V_61 , 3 << 2 ,
1 << 2 ) ;
F_9 ( V_16 , V_158 ,
V_265 | V_266 ,
V_266 ) ;
F_9 ( V_16 , V_288 ,
V_289 ,
V_290 ) ;
F_73 ( V_174 , L_8 ) ;
F_73 ( V_174 , L_7 ) ;
F_68 ( V_174 ) ;
break;
case 2 :
case 3 :
F_34 ( V_1 -> V_5 , L_10 ) ;
type = V_287 ;
F_9 ( V_16 , V_61 , 3 << 2 ,
2 << 2 ) ;
F_9 ( V_16 , V_158 ,
V_265 | V_266 ,
V_265 ) ;
F_9 ( V_16 , V_288 ,
V_289 ,
V_291 ) ;
F_73 ( V_174 , L_8 ) ;
F_73 ( V_174 , L_7 ) ;
F_68 ( V_174 ) ;
break;
}
return type ;
}
static T_3 F_74 ( int V_116 , void * V_188 )
{
struct V_1 * V_1 = (struct V_1 * ) V_188 ;
struct V_16 * V_16 = V_1 -> V_16 ;
int V_261 , V_262 = 0 , V_171 = 0 , V_292 = 0 ;
if ( F_19 ( V_16 , V_163 , & V_261 ) ) {
F_56 ( V_1 -> V_5 , L_11 ) ;
return V_293 ;
}
if ( ( V_261 & V_294 ) ==
V_295 ) {
F_66 ( V_1 ) ;
V_292 |= V_287 ;
V_262 = V_294 ;
} else if ( V_261 & V_296 ) {
int V_297 ;
F_19 ( V_16 , V_162 ,
& V_297 ) ;
V_1 -> V_298 = F_70 (
V_297 >> 8 ) ;
V_171 |= V_1 -> V_298 ;
V_292 |= V_299 ;
V_262 = V_296 ;
} else if ( V_261 & V_300 ) {
V_292 = V_299 ;
V_262 = V_300 ;
} else if ( V_261 & V_301 ) {
if ( F_63 ( V_16 ) ) {
V_171 |= F_72 ( V_1 ) ;
if ( ! V_1 -> V_285 ) {
if ( ! V_1 -> V_140 ) {
int V_3 ;
V_1 -> V_140 = true ;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 < 0 )
V_1 -> V_140 = false ;
}
V_1 -> V_124 = V_128 ;
F_75 ( & V_1 -> V_136 ) ;
} else {
if ( V_1 -> V_140 ) {
F_5 ( V_1 ) ;
V_1 -> V_140 = false ;
}
}
} else {
F_3 ( V_1 -> V_5 , L_12 ) ;
F_66 ( V_1 ) ;
}
V_292 |= V_287 ;
V_262 = V_301 ;
if ( V_1 -> V_124 == V_128 ) {
V_1 -> V_138 = V_171 ;
V_1 -> V_139 = V_292 ;
}
} else if ( V_261 & V_302 ) {
F_75 ( & V_1 -> V_136 ) ;
V_262 = V_302 ;
} else if ( ( V_261 & V_303 ) ==
V_304 ) {
if ( F_63 ( V_16 ) ) {
F_9 ( V_16 ,
V_267 ,
V_269 ,
V_269 ) ;
F_9 ( V_16 , V_108 ,
V_273 , V_273 ) ;
F_69 ( V_1 ) ;
}
}
if ( ! V_262 )
V_262 = V_261 ;
F_21 ( V_16 , V_162 , V_262 ) ;
if ( V_292 && V_1 -> V_124 == V_133 )
F_37 ( V_1 -> V_137 , V_171 , V_292 ) ;
return V_305 ;
}
static void F_76 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_9 ( V_16 , V_288 ,
V_306 ,
V_1 -> V_307 << V_308 ) ;
F_9 ( V_16 , V_288 ,
V_309 ,
V_1 -> V_310 << V_311 ) ;
F_9 ( V_16 , V_288 ,
V_312 ,
V_1 -> V_313 << V_314 ) ;
F_9 ( V_16 , V_144 ,
V_315 ,
( V_1 -> V_316 - 1 ) << V_317 ) ;
F_9 ( V_16 , V_144 ,
V_318 ,
V_1 -> V_319 << V_320 ) ;
F_9 ( V_16 , V_144 ,
V_321 ,
V_1 -> V_322 << V_323 ) ;
F_21 ( V_16 , V_145 ,
( V_1 -> V_324 [ 0 ] << 8 ) | V_1 -> V_324 [ 1 ] ) ;
F_21 ( V_16 , V_325 ,
( V_1 -> V_324 [ 2 ] << 8 ) | V_1 -> V_324 [ 3 ] ) ;
F_21 ( V_16 , V_326 ,
( V_1 -> V_324 [ 4 ] << 8 ) | V_1 -> V_324 [ 5 ] ) ;
F_21 ( V_16 , V_327 ,
( V_1 -> V_324 [ 6 ] << 8 ) | V_1 -> V_324 [ 7 ] ) ;
F_9 ( V_16 , V_108 ,
V_328 | V_329 ,
0 ) ;
}
static void F_77 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_21 ( V_16 , V_330 , 0x0001 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_331 , V_331 ) ;
F_9 ( V_1 -> V_16 , V_64 ,
V_332 , V_332 ) ;
F_9 ( V_16 , V_112 ,
V_333 ,
V_1 -> V_334 << V_335 ) ;
F_9 ( V_16 , V_64 ,
V_336 | V_65 |
V_337 | V_338 ,
V_336 | V_65 |
V_337 | V_338 ) ;
F_9 ( V_16 , V_339 ,
V_340 ,
V_1 -> V_341 ? 0 : V_340 ) ;
F_9 ( V_16 , V_339 ,
V_342 ,
V_1 -> V_343 ? 0 : V_342 ) ;
F_9 ( V_16 , V_339 ,
V_344 ,
V_1 -> V_345 ? V_344 : 0 ) ;
F_9 ( V_16 , V_143 ,
V_258 ,
V_1 -> V_346 ? 0 : V_258 ) ;
F_9 ( V_16 , V_143 ,
V_347 ,
V_1 -> V_348 << V_349 ) ;
F_9 ( V_16 , V_143 ,
V_350 ,
V_1 -> V_351 << V_352 ) ;
F_9 ( V_16 , V_108 , 0x7ff , 0x7ff ) ;
F_9 ( V_16 , V_158 ,
V_353 , V_1 -> V_354 ) ;
if ( V_1 -> V_316 )
F_76 ( V_1 ) ;
F_9 ( V_16 , V_217 ,
V_218 | V_355 ,
V_356 ) ;
F_9 ( V_16 , V_212 ,
V_213 , V_357 ) ;
F_9 ( V_16 , V_47 ,
V_110 | V_111 ,
V_110 | V_111 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_115 , V_115 ) ;
F_9 ( V_16 , V_212 ,
V_358 , V_358 ) ;
F_9 ( V_16 , V_156 ,
V_359 |
V_360 | V_361 ,
V_359 |
V_360 | V_361 ) ;
F_9 ( V_16 , V_66 ,
V_362 ,
0x20 << V_363 ) ;
F_9 ( V_16 , V_50 ,
V_364 | V_365 ,
( 0x2 << V_366 ) |
( 0x3 << V_367 ) ) ;
F_9 ( V_1 -> V_16 , V_91 ,
V_92 , V_94 ) ;
F_9 ( V_1 -> V_16 , V_95 ,
V_92 , V_368 ) ;
F_9 ( V_16 , V_369 ,
V_370 , V_370 ) ;
}
static int F_78 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_264 * V_174 = F_79 ( V_173 ) ;
V_1 -> V_174 = V_174 ;
return 0 ;
}
static int F_80 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_81 ( unsigned int V_371 , unsigned int V_372 ,
struct V_373 * V_374 )
{
T_2 V_375 , V_376 ;
unsigned int V_377 , V_39 , V_378 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_379 ) ; V_39 ++ ) {
V_377 = V_371 / V_379 [ V_39 ] . V_380 ;
if ( V_377 <= V_381 )
break;
}
if ( V_39 == F_17 ( V_379 ) )
return - V_38 ;
V_374 -> V_382 = V_379 [ V_39 ] . V_383 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_384 ) ; V_39 ++ ) {
if ( V_377 >= V_384 [ V_39 ] . V_380 )
break;
}
if ( V_39 == F_17 ( V_384 ) )
return - V_38 ;
V_374 -> V_385 = V_384 [ V_39 ] . V_383 ;
V_376 = 0 ;
V_378 = F_17 ( V_386 ) ;
for ( V_39 = 0 ; V_39 < F_17 ( V_386 ) ; V_39 ++ ) {
V_375 = 256 * V_372 * 2 * V_386 [ V_39 ] . V_380 ;
if ( V_375 > V_387 && V_375 < V_388 &&
V_376 < V_375 ) {
V_376 = V_375 ;
V_378 = V_39 ;
}
}
if ( F_17 ( V_386 ) == V_378 )
return - V_38 ;
V_374 -> V_389 = V_386 [ V_378 ] . V_383 ;
V_375 = F_82 ( V_376 << 16 , V_377 * V_374 -> V_385 ) ;
V_374 -> V_390 = ( V_375 >> 16 ) & 0x3FF ;
V_374 -> V_391 = V_375 & 0xFFFF ;
return 0 ;
}
static void F_83 ( struct V_1 * V_1 ,
struct V_373 * V_374 )
{
F_9 ( V_1 -> V_16 , V_79 ,
V_80 | V_83 ,
V_392 | V_374 -> V_389 ) ;
F_9 ( V_1 -> V_16 , V_73 ,
V_84 | V_393 ,
V_374 -> V_385 | ( 0x6 << V_394 ) ) ;
F_21 ( V_1 -> V_16 , V_74 , V_374 -> V_391 ) ;
F_9 ( V_1 -> V_16 , V_75 ,
V_395 , V_374 -> V_390 ) ;
F_9 ( V_1 -> V_16 , V_76 ,
V_396 ,
V_374 -> V_382 << V_397 ) ;
F_9 ( V_1 -> V_16 , V_77 ,
V_398 , V_399 ) ;
F_9 ( V_1 -> V_16 ,
V_78 , V_82 , 0 ) ;
if ( V_374 -> V_391 ) {
F_9 ( V_1 -> V_16 , V_77 ,
V_400 | V_401 |
V_402 ,
V_400 | V_401 |
V_403 ) ;
F_9 ( V_1 -> V_16 , V_78 ,
V_404 | V_405 ,
V_404 | V_405 ) ;
} else {
F_9 ( V_1 -> V_16 , V_77 ,
V_400 | V_401 |
V_402 , V_406 ) ;
F_9 ( V_1 -> V_16 , V_78 ,
V_404 | V_405 , 0 ) ;
}
}
static int F_84 ( struct V_172 * V_173 , int V_407 , int V_408 ,
unsigned int V_409 , unsigned int V_410 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_373 V_374 ;
int V_3 , V_372 ;
V_372 = V_410 / 256 ;
V_3 = F_81 ( V_409 , V_372 , & V_374 ) ;
if ( V_3 < 0 ) {
F_56 ( V_173 -> V_5 , L_13 , V_409 ) ;
return V_3 ;
}
F_34 ( V_173 -> V_5 , L_14 ,
V_374 . V_389 , V_374 . V_385 , V_374 . V_391 ,
V_374 . V_390 , V_374 . V_382 ) ;
F_83 ( V_1 , & V_374 ) ;
F_85 ( 2 ) ;
F_9 ( V_1 -> V_16 , V_79 ,
V_80 , V_81 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_1 , unsigned int V_411 )
{
int V_3 = 0 ;
V_1 -> V_412 = F_87 ( V_1 -> V_5 , L_15 ) ;
if ( F_88 ( V_1 -> V_412 ) ) {
F_89 ( V_1 -> V_5 , L_16 ) ;
return 0 ;
}
if ( ! V_1 -> V_413 ) {
V_3 = F_90 ( V_1 -> V_412 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_17 ) ;
return V_3 ;
}
}
if ( V_1 -> V_413 != V_411 ) {
V_411 = F_91 ( V_1 -> V_412 , V_411 ) ;
V_3 = F_92 ( V_1 -> V_412 , V_411 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_18 ) ;
return V_3 ;
}
V_1 -> V_413 = V_411 ;
}
return 0 ;
}
static void F_93 ( struct V_16 * V_16 )
{
F_9 ( V_16 , V_79 ,
V_80 , V_392 ) ;
F_9 ( V_16 , V_78 ,
V_82 , 0 ) ;
F_9 ( V_16 , V_73 ,
V_393 , 0 ) ;
}
static int F_29 ( struct V_1 * V_1 , int V_414 ,
unsigned int V_411 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
int V_3 ;
switch ( V_414 ) {
case V_275 :
F_93 ( V_16 ) ;
if ( V_1 -> V_413 ) {
F_94 ( V_1 -> V_412 ) ;
V_1 -> V_413 = 0 ;
}
break;
case V_415 :
F_1 ( V_1 , 3 * V_211 ) ;
F_93 ( V_16 ) ;
F_9 ( V_16 , V_79 ,
V_83 , 0 ) ;
F_5 ( V_1 ) ;
V_3 = F_86 ( V_1 , V_411 ) ;
if ( V_3 )
return V_3 ;
break;
case V_117 :
if ( F_63 ( V_1 -> V_16 ) ) {
F_9 ( V_16 , V_78 ,
V_82 , V_82 ) ;
F_9 ( V_16 , V_79 ,
V_80 , V_81 ) ;
F_9 ( V_16 , V_79 ,
V_83 , 0xf ) ;
F_9 ( V_16 , V_73 ,
V_393 |
V_84 , 0x10 ) ;
F_9 ( V_16 , V_78 ,
V_404 , V_404 ) ;
} else {
F_93 ( V_16 ) ;
F_3 ( V_1 -> V_5 , L_19 ) ;
}
if ( V_1 -> V_413 ) {
F_94 ( V_1 -> V_412 ) ;
V_1 -> V_413 = 0 ;
}
break;
case V_416 :
F_1 ( V_1 , 3 * V_211 ) ;
F_9 ( V_16 , V_75 ,
V_417 | V_418 ,
V_419 | 0 ) ;
F_5 ( V_1 ) ;
V_3 = F_86 ( V_1 , V_411 ) ;
if ( V_3 )
return V_3 ;
break;
case V_420 :
F_1 ( V_1 , 3 * V_211 ) ;
F_9 ( V_16 , V_75 ,
V_417 | V_418 ,
V_421 |
( 0xf << V_422 ) ) ;
F_5 ( V_1 ) ;
if ( V_1 -> V_413 ) {
F_94 ( V_1 -> V_412 ) ;
V_1 -> V_413 = 0 ;
}
break;
case V_423 :
F_1 ( V_1 , 3 * V_211 ) ;
F_9 ( V_16 , V_75 ,
V_417 | V_418 ,
V_424 |
( 0xf << V_422 ) ) ;
F_5 ( V_1 ) ;
if ( V_1 -> V_413 ) {
F_94 ( V_1 -> V_412 ) ;
V_1 -> V_413 = 0 ;
}
break;
default:
F_56 ( V_1 -> V_5 , L_20 , V_414 ) ;
return - V_38 ;
}
F_34 ( V_1 -> V_5 , L_21 , V_411 ,
V_414 ) ;
return 0 ;
}
static int F_95 ( struct V_172 * V_173 , int V_414 ,
int V_408 , unsigned int V_411 , int V_425 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
return F_29 ( V_1 , V_414 , V_411 ) ;
}
static int F_96 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_29 ( V_1 , V_275 , 0 ) ;
F_65 ( V_16 ) ;
F_9 ( V_16 , V_108 ,
V_270 | V_272 |
V_271 | V_273 ,
V_270 | V_272 ) ;
F_9 ( V_16 , V_143 ,
V_274 , V_274 ) ;
F_9 ( V_16 , V_267 ,
V_269 | V_268 , 0 ) ;
return 0 ;
}
static int F_97 ( struct V_172 * V_173 ,
enum V_426 V_427 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
int V_3 ;
switch ( V_427 ) {
case V_428 :
break;
case V_429 :
break;
case V_430 :
if ( F_98 ( V_173 ) == V_431 ) {
if ( V_1 -> V_413 ) {
V_3 = F_90 ( V_1 -> V_412 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_17 ) ;
return V_3 ;
}
}
F_96 ( V_1 ) ;
}
break;
case V_431 :
F_38 ( V_1 ) ;
F_21 ( V_1 -> V_16 ,
V_267 , 0xffff ) ;
F_9 ( V_1 -> V_16 , V_41 ,
V_44 , 0 ) ;
if ( V_1 -> V_413 )
F_94 ( V_1 -> V_412 ) ;
break;
}
return 0 ;
}
static int T_4 F_99 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
F_100 ( V_1 -> V_116 ) ;
F_101 ( V_173 , V_431 ) ;
F_102 ( V_1 -> V_16 , true ) ;
F_103 ( V_1 -> V_16 ) ;
return 0 ;
}
static int T_4 F_104 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
int V_3 ;
F_102 ( V_1 -> V_16 , false ) ;
F_105 ( V_1 -> V_16 ) ;
V_1 -> V_140 = true ;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 < 0 )
V_1 -> V_140 = false ;
F_106 ( V_1 -> V_116 ) ;
return 0 ;
}
static void F_107 ( struct V_16 * V_16 )
{
F_21 ( V_16 , V_161 , 0x00 ) ;
F_21 ( V_16 , V_161 , 0x00 ) ;
}
static void F_108 ( struct V_1 * V_1 )
{
int V_39 ;
struct V_141 * V_5 = V_1 -> V_5 ;
F_34 ( V_5 , L_22 , V_1 -> V_341 ) ;
F_34 ( V_5 , L_23 , V_1 -> V_343 ) ;
F_34 ( V_5 , L_24 , V_1 -> V_345 ) ;
F_34 ( V_5 , L_25 , V_1 -> V_346 ) ;
F_34 ( V_5 , L_26 , V_1 -> V_354 ) ;
F_34 ( V_5 , L_27 , V_1 -> V_334 ) ;
F_34 ( V_5 , L_28 , V_1 -> V_316 ) ;
for ( V_39 = 0 ; V_39 < V_1 -> V_316 ; V_39 ++ )
F_34 ( V_5 , L_29 , V_39 ,
V_1 -> V_324 [ V_39 ] ) ;
F_34 ( V_5 , L_30 , V_1 -> V_319 ) ;
F_34 ( V_5 , L_31 , V_1 -> V_307 ) ;
F_34 ( V_5 , L_32 , V_1 -> V_310 ) ;
F_34 ( V_5 , L_33 , V_1 -> V_313 ) ;
F_34 ( V_5 , L_34 , V_1 -> V_322 ) ;
F_34 ( V_5 , L_35 ,
V_1 -> V_348 ) ;
F_34 ( V_5 , L_36 ,
V_1 -> V_351 ) ;
}
static int F_109 ( struct V_141 * V_5 ,
struct V_1 * V_1 ) {
V_1 -> V_341 = F_110 ( V_5 ,
L_37 ) ;
V_1 -> V_343 = F_110 ( V_5 ,
L_38 ) ;
V_1 -> V_345 = F_110 ( V_5 ,
L_39 ) ;
F_111 ( V_5 , L_40 ,
& V_1 -> V_346 ) ;
F_111 ( V_5 , L_41 ,
& V_1 -> V_354 ) ;
F_111 ( V_5 , L_42 ,
& V_1 -> V_334 ) ;
F_111 ( V_5 , L_43 ,
& V_1 -> V_316 ) ;
F_112 ( V_5 , L_44 ,
V_1 -> V_324 , V_1 -> V_316 ) ;
F_111 ( V_5 , L_45 ,
& V_1 -> V_319 ) ;
F_111 ( V_5 , L_46 ,
& V_1 -> V_307 ) ;
F_111 ( V_5 , L_47 ,
& V_1 -> V_310 ) ;
F_111 ( V_5 , L_48 ,
& V_1 -> V_313 ) ;
F_111 ( V_5 , L_49 ,
& V_1 -> V_322 ) ;
F_111 ( V_5 , L_50 ,
& V_1 -> V_348 ) ;
F_111 ( V_5 , L_51 ,
& V_1 -> V_351 ) ;
V_1 -> V_412 = F_87 ( V_5 , L_15 ) ;
if ( F_113 ( V_1 -> V_412 ) == - V_432 ) {
return - V_432 ;
} else if ( F_113 ( V_1 -> V_412 ) == - V_433 ) {
V_1 -> V_412 = NULL ;
F_89 ( V_5 , L_16 ) ;
} else if ( F_88 ( V_1 -> V_412 ) ) {
return - V_38 ;
}
return 0 ;
}
static int F_114 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_115 ( V_1 -> V_5 , V_1 -> V_116 , NULL ,
F_74 , V_434 | V_435 ,
L_52 , V_1 ) ;
if ( V_3 ) {
F_56 ( V_1 -> V_5 , L_53 ,
V_1 -> V_116 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int F_116 ( struct V_436 * V_437 ,
const struct V_438 * V_439 )
{
struct V_141 * V_5 = & V_437 -> V_5 ;
struct V_1 * V_1 = F_117 ( & V_437 -> V_5 ) ;
int V_3 , V_10 ;
if ( ! V_1 ) {
V_1 = F_118 ( V_5 , sizeof( * V_1 ) , V_190 ) ;
if ( ! V_1 )
return - V_192 ;
V_3 = F_109 ( V_5 , V_1 ) ;
if ( V_3 )
return V_3 ;
}
F_119 ( V_437 , V_1 ) ;
V_1 -> V_16 = F_120 ( V_437 , & V_440 ) ;
if ( F_88 ( V_1 -> V_16 ) )
return F_113 ( V_1 -> V_16 ) ;
V_1 -> V_5 = V_5 ;
V_1 -> V_116 = V_437 -> V_116 ;
V_1 -> V_124 = V_133 ;
V_1 -> V_140 = false ;
F_121 ( & V_1 -> V_4 , 1 ) ;
F_122 ( & V_1 -> V_136 , F_35 ) ;
F_108 ( V_1 ) ;
F_107 ( V_1 -> V_16 ) ;
V_3 = F_19 ( V_1 -> V_16 , V_153 , & V_10 ) ;
if ( V_3 < 0 ) {
F_56 ( V_5 , L_54 ,
V_3 ) ;
return V_3 ;
}
if ( ( V_10 & V_441 ) !=
V_442 ) {
F_56 ( V_5 , L_55 ) ;
return - V_443 ;
}
F_77 ( V_1 ) ;
if ( V_437 -> V_116 )
F_114 ( V_1 ) ;
return F_123 ( & V_437 -> V_5 , & V_444 ,
& V_445 , 1 ) ;
}
static int F_124 ( struct V_436 * V_446 )
{
F_125 ( & V_446 -> V_5 ) ;
return 0 ;
}
