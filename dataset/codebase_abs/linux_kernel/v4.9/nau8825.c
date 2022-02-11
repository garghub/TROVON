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
static int F_55 ( struct V_194 * V_195 ,
struct V_196 * V_184 ,
struct V_197 * V_198 )
{
struct V_172 * V_173 = V_198 -> V_173 ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
unsigned int V_199 = 0 ;
F_1 ( V_1 , 2 * V_200 ) ;
switch ( F_56 ( V_184 ) ) {
case 16 :
V_199 |= V_201 ;
break;
case 20 :
V_199 |= V_202 ;
break;
case 24 :
V_199 |= V_203 ;
break;
case 32 :
V_199 |= V_204 ;
break;
default:
return - V_38 ;
}
F_9 ( V_1 -> V_16 , V_205 ,
V_206 , V_199 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static int F_57 ( struct V_197 * V_207 , unsigned int V_208 )
{
struct V_172 * V_173 = V_207 -> V_173 ;
struct V_1 * V_1 = F_45 ( V_173 ) ;
unsigned int V_209 = 0 , V_210 = 0 ;
F_1 ( V_1 , 2 * V_200 ) ;
switch ( V_208 & V_211 ) {
case V_212 :
V_210 |= V_89 ;
break;
case V_213 :
break;
default:
return - V_38 ;
}
switch ( V_208 & V_214 ) {
case V_215 :
break;
case V_216 :
V_209 |= V_217 ;
break;
default:
return - V_38 ;
}
switch ( V_208 & V_218 ) {
case V_219 :
V_209 |= V_220 ;
break;
case V_221 :
V_209 |= V_222 ;
break;
case V_223 :
V_209 |= V_224 ;
break;
case V_225 :
V_209 |= V_226 ;
break;
case V_227 :
V_209 |= V_226 ;
V_209 |= V_228 ;
break;
default:
return - V_38 ;
}
F_9 ( V_1 -> V_16 , V_205 ,
V_206 | V_229 |
V_230 | V_231 ,
V_209 ) ;
F_9 ( V_1 -> V_16 , V_85 ,
V_86 , V_210 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
int F_58 ( struct V_172 * V_173 ,
struct V_232 * V_137 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_16 * V_16 = V_1 -> V_16 ;
V_1 -> V_137 = V_137 ;
F_9 ( V_16 , V_61 ,
V_233 | V_62 | V_63 ,
V_233 | V_62 | V_63 ) ;
return 0 ;
}
static bool F_59 ( struct V_16 * V_16 )
{
bool V_234 , V_235 ;
int V_236 , V_237 ;
F_19 ( V_16 , V_143 , & V_237 ) ;
V_234 = V_237 & V_238 ;
F_19 ( V_16 , V_153 , & V_236 ) ;
V_235 = V_236 & V_239 ;
return V_234 == V_235 ;
}
static void F_60 ( struct V_16 * V_16 )
{
F_9 ( V_16 , V_143 ,
V_240 , V_240 ) ;
F_9 ( V_16 , V_143 ,
V_240 , 0 ) ;
}
static void F_61 ( struct V_16 * V_16 )
{
int V_241 , V_242 , V_39 ;
F_19 ( V_16 , V_163 , & V_241 ) ;
for ( V_39 = 0 ; V_39 < V_243 ; V_39 ++ ) {
V_242 = ( 0x1 << V_39 ) ;
if ( V_241 & V_242 )
F_21 ( V_16 ,
V_162 , V_242 ) ;
}
}
static void F_62 ( struct V_1 * V_1 )
{
struct V_244 * V_174 = V_1 -> V_174 ;
struct V_16 * V_16 = V_1 -> V_16 ;
F_38 ( V_1 ) ;
F_63 ( V_174 , L_6 ) ;
F_63 ( V_174 , L_7 ) ;
F_9 ( V_16 , V_158 ,
V_245 | V_246 , 0 ) ;
F_9 ( V_16 , V_61 , 0xf , 0xf ) ;
F_64 ( V_174 ) ;
F_61 ( V_16 ) ;
F_9 ( V_16 , V_247 ,
V_248 | V_249 ,
V_248 ) ;
F_9 ( V_16 , V_108 ,
V_250 | V_251 |
V_252 | V_253 ,
V_250 | V_251 |
V_252 ) ;
F_9 ( V_16 , V_143 ,
V_254 , V_254 ) ;
F_9 ( V_16 , V_41 ,
V_44 , 0 ) ;
F_29 ( V_1 , V_255 , 0 ) ;
}
static void F_65 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_9 ( V_16 , V_108 ,
V_252 | V_251 , 0 ) ;
F_29 ( V_1 , V_117 , 0 ) ;
F_9 ( V_16 , V_41 ,
V_44 , V_44 ) ;
F_9 ( V_16 , V_85 ,
V_86 , V_89 ) ;
F_9 ( V_16 , V_85 ,
V_86 , V_118 ) ;
F_9 ( V_16 , V_143 ,
V_254 , 0 ) ;
F_21 ( V_16 , V_247 , 0 ) ;
F_60 ( V_16 ) ;
}
static int F_66 ( int V_10 )
{
int V_256 = 0 ;
if ( V_10 & F_67 ( 0 ) )
V_256 |= V_257 ;
if ( V_10 & F_67 ( 1 ) )
V_256 |= V_258 ;
if ( V_10 & F_67 ( 2 ) )
V_256 |= V_259 ;
if ( V_10 & F_67 ( 3 ) )
V_256 |= V_260 ;
if ( V_10 & F_67 ( 4 ) )
V_256 |= V_261 ;
if ( V_10 & F_67 ( 5 ) )
V_256 |= V_262 ;
return V_256 ;
}
static int F_68 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
struct V_244 * V_174 = V_1 -> V_174 ;
int V_263 , V_264 ;
int type = 0 ;
F_19 ( V_16 , V_160 , & V_263 ) ;
V_264 = ( V_263 >> 10 ) & 3 ;
if ( V_264 == 0x3 )
V_1 -> V_265 = true ;
else
V_1 -> V_265 = false ;
switch ( V_264 ) {
case 0 :
type = V_266 ;
break;
case 1 :
F_34 ( V_1 -> V_5 , L_8 ) ;
type = V_267 ;
F_9 ( V_16 , V_61 , 3 << 2 ,
1 << 2 ) ;
F_9 ( V_16 , V_158 ,
V_245 | V_246 ,
V_246 ) ;
F_9 ( V_16 , V_268 ,
V_269 ,
V_270 ) ;
F_69 ( V_174 , L_7 ) ;
F_69 ( V_174 , L_6 ) ;
F_64 ( V_174 ) ;
break;
case 2 :
case 3 :
F_34 ( V_1 -> V_5 , L_9 ) ;
type = V_267 ;
F_9 ( V_16 , V_61 , 3 << 2 ,
2 << 2 ) ;
F_9 ( V_16 , V_158 ,
V_245 | V_246 ,
V_245 ) ;
F_9 ( V_16 , V_268 ,
V_269 ,
V_271 ) ;
F_69 ( V_174 , L_7 ) ;
F_69 ( V_174 , L_6 ) ;
F_64 ( V_174 ) ;
break;
}
return type ;
}
static T_3 F_70 ( int V_116 , void * V_188 )
{
struct V_1 * V_1 = (struct V_1 * ) V_188 ;
struct V_16 * V_16 = V_1 -> V_16 ;
int V_241 , V_242 = 0 , V_171 = 0 , V_272 = 0 ;
if ( F_19 ( V_16 , V_163 , & V_241 ) ) {
F_71 ( V_1 -> V_5 , L_10 ) ;
return V_273 ;
}
if ( ( V_241 & V_274 ) ==
V_275 ) {
F_62 ( V_1 ) ;
V_272 |= V_267 ;
V_242 = V_274 ;
} else if ( V_241 & V_276 ) {
int V_277 ;
F_19 ( V_16 , V_162 ,
& V_277 ) ;
V_1 -> V_278 = F_66 (
V_277 >> 8 ) ;
V_171 |= V_1 -> V_278 ;
V_272 |= V_279 ;
V_242 = V_276 ;
} else if ( V_241 & V_280 ) {
V_272 = V_279 ;
V_242 = V_280 ;
} else if ( V_241 & V_281 ) {
if ( F_59 ( V_16 ) ) {
V_171 |= F_68 ( V_1 ) ;
if ( ! V_1 -> V_265 ) {
if ( ! V_1 -> V_140 ) {
int V_3 ;
V_1 -> V_140 = true ;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 < 0 )
V_1 -> V_140 = false ;
}
V_1 -> V_124 = V_128 ;
F_72 ( & V_1 -> V_136 ) ;
} else {
if ( V_1 -> V_140 ) {
F_5 ( V_1 ) ;
V_1 -> V_140 = false ;
}
}
} else {
F_3 ( V_1 -> V_5 , L_11 ) ;
F_62 ( V_1 ) ;
}
V_272 |= V_267 ;
V_242 = V_281 ;
if ( V_1 -> V_124 == V_128 ) {
V_1 -> V_138 = V_171 ;
V_1 -> V_139 = V_272 ;
}
} else if ( V_241 & V_282 ) {
F_72 ( & V_1 -> V_136 ) ;
V_242 = V_282 ;
} else if ( ( V_241 & V_283 ) ==
V_284 ) {
if ( F_59 ( V_16 ) ) {
F_9 ( V_16 ,
V_247 ,
V_249 ,
V_249 ) ;
F_9 ( V_16 , V_108 ,
V_253 , V_253 ) ;
F_65 ( V_1 ) ;
}
}
if ( ! V_242 )
V_242 = V_241 ;
F_21 ( V_16 , V_162 , V_242 ) ;
if ( V_272 && V_1 -> V_124 == V_133 )
F_37 ( V_1 -> V_137 , V_171 , V_272 ) ;
return V_285 ;
}
static void F_73 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_9 ( V_16 , V_268 ,
V_286 ,
V_1 -> V_287 << V_288 ) ;
F_9 ( V_16 , V_268 ,
V_289 ,
V_1 -> V_290 << V_291 ) ;
F_9 ( V_16 , V_268 ,
V_292 ,
V_1 -> V_293 << V_294 ) ;
F_9 ( V_16 , V_144 ,
V_295 ,
( V_1 -> V_296 - 1 ) << V_297 ) ;
F_9 ( V_16 , V_144 ,
V_298 ,
V_1 -> V_299 << V_300 ) ;
F_9 ( V_16 , V_144 ,
V_301 ,
V_1 -> V_302 << V_303 ) ;
F_21 ( V_16 , V_145 ,
( V_1 -> V_304 [ 0 ] << 8 ) | V_1 -> V_304 [ 1 ] ) ;
F_21 ( V_16 , V_305 ,
( V_1 -> V_304 [ 2 ] << 8 ) | V_1 -> V_304 [ 3 ] ) ;
F_21 ( V_16 , V_306 ,
( V_1 -> V_304 [ 4 ] << 8 ) | V_1 -> V_304 [ 5 ] ) ;
F_21 ( V_16 , V_307 ,
( V_1 -> V_304 [ 6 ] << 8 ) | V_1 -> V_304 [ 7 ] ) ;
F_9 ( V_16 , V_108 ,
V_308 | V_309 ,
0 ) ;
}
static void F_74 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_21 ( V_16 , V_310 , 0x0001 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_311 , V_311 ) ;
F_9 ( V_1 -> V_16 , V_64 ,
V_312 , V_312 ) ;
F_9 ( V_16 , V_112 ,
V_313 ,
V_1 -> V_314 << V_315 ) ;
F_9 ( V_16 , V_64 ,
V_316 | V_65 |
V_317 | V_318 ,
V_316 | V_65 |
V_317 | V_318 ) ;
F_9 ( V_16 , V_319 ,
V_320 ,
V_1 -> V_321 ? 0 : V_320 ) ;
F_9 ( V_16 , V_319 ,
V_322 ,
V_1 -> V_323 ? 0 : V_322 ) ;
F_9 ( V_16 , V_319 ,
V_324 ,
V_1 -> V_325 ? V_324 : 0 ) ;
F_9 ( V_16 , V_143 ,
V_238 ,
V_1 -> V_326 ? 0 : V_238 ) ;
F_9 ( V_16 , V_143 ,
V_327 ,
V_1 -> V_328 << V_329 ) ;
F_9 ( V_16 , V_143 ,
V_330 ,
V_1 -> V_331 << V_332 ) ;
F_9 ( V_16 , V_108 , 0x7ff , 0x7ff ) ;
F_9 ( V_16 , V_158 ,
V_333 , V_1 -> V_334 ) ;
if ( V_1 -> V_296 )
F_73 ( V_1 ) ;
F_9 ( V_16 , V_335 ,
V_336 , V_337 ) ;
F_9 ( V_16 , V_338 ,
V_339 , V_340 ) ;
F_9 ( V_16 , V_47 ,
V_110 | V_111 ,
V_110 | V_111 ) ;
F_9 ( V_1 -> V_16 , V_112 ,
V_115 , V_115 ) ;
F_9 ( V_16 , V_338 ,
V_341 , V_341 ) ;
F_9 ( V_16 , V_156 ,
V_342 |
V_343 | V_344 ,
V_342 |
V_343 | V_344 ) ;
F_9 ( V_16 , V_66 ,
V_345 ,
0x20 << V_346 ) ;
F_9 ( V_16 , V_50 ,
V_347 | V_348 ,
( 0x2 << V_349 ) |
( 0x3 << V_350 ) ) ;
F_9 ( V_1 -> V_16 , V_91 ,
V_92 , V_94 ) ;
F_9 ( V_1 -> V_16 , V_95 ,
V_92 , V_351 ) ;
}
static int F_75 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_244 * V_174 = F_76 ( V_173 ) ;
V_1 -> V_174 = V_174 ;
return 0 ;
}
static int F_77 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_78 ( unsigned int V_352 , unsigned int V_353 ,
struct V_354 * V_355 )
{
T_2 V_356 , V_357 ;
unsigned int V_358 , V_39 , V_359 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_360 ) ; V_39 ++ ) {
V_358 = V_352 / V_360 [ V_39 ] . V_361 ;
if ( V_358 <= V_362 )
break;
}
if ( V_39 == F_17 ( V_360 ) )
return - V_38 ;
V_355 -> V_363 = V_360 [ V_39 ] . V_364 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_365 ) ; V_39 ++ ) {
if ( V_358 >= V_365 [ V_39 ] . V_361 )
break;
}
if ( V_39 == F_17 ( V_365 ) )
return - V_38 ;
V_355 -> V_366 = V_365 [ V_39 ] . V_364 ;
V_357 = 0 ;
V_359 = F_17 ( V_367 ) ;
for ( V_39 = 0 ; V_39 < F_17 ( V_367 ) ; V_39 ++ ) {
V_356 = 256 * V_353 * 2 * V_367 [ V_39 ] . V_361 ;
if ( V_356 > V_368 && V_356 < V_369 &&
V_357 < V_356 ) {
V_357 = V_356 ;
V_359 = V_39 ;
}
}
if ( F_17 ( V_367 ) == V_359 )
return - V_38 ;
V_355 -> V_370 = V_367 [ V_359 ] . V_364 ;
V_356 = F_79 ( V_357 << 16 , V_358 * V_355 -> V_366 ) ;
V_355 -> V_371 = ( V_356 >> 16 ) & 0x3FF ;
V_355 -> V_372 = V_356 & 0xFFFF ;
return 0 ;
}
static void F_80 ( struct V_1 * V_1 ,
struct V_354 * V_355 )
{
F_9 ( V_1 -> V_16 , V_79 ,
V_80 | V_83 ,
V_373 | V_355 -> V_370 ) ;
F_9 ( V_1 -> V_16 , V_73 ,
V_84 , V_355 -> V_366 ) ;
F_21 ( V_1 -> V_16 , V_74 , V_355 -> V_372 ) ;
F_9 ( V_1 -> V_16 , V_75 ,
V_374 , V_355 -> V_371 ) ;
F_9 ( V_1 -> V_16 , V_76 ,
V_375 , V_355 -> V_363 ) ;
F_9 ( V_1 -> V_16 , V_77 ,
V_376 , V_377 ) ;
F_9 ( V_1 -> V_16 ,
V_78 , V_82 , 0 ) ;
if ( V_355 -> V_372 ) {
F_9 ( V_1 -> V_16 , V_77 ,
V_378 | V_379 |
V_380 ,
V_378 | V_379 |
V_381 ) ;
F_9 ( V_1 -> V_16 , V_78 ,
V_382 , V_382 ) ;
} else {
F_9 ( V_1 -> V_16 , V_77 ,
V_378 | V_379 |
V_380 , V_383 ) ;
F_9 ( V_1 -> V_16 ,
V_78 , V_382 , 0 ) ;
}
}
static int F_81 ( struct V_172 * V_173 , int V_384 , int V_385 ,
unsigned int V_386 , unsigned int V_387 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
struct V_354 V_355 ;
int V_3 , V_353 ;
V_353 = V_387 / 256 ;
V_3 = F_78 ( V_386 , V_353 , & V_355 ) ;
if ( V_3 < 0 ) {
F_71 ( V_173 -> V_5 , L_12 , V_386 ) ;
return V_3 ;
}
F_34 ( V_173 -> V_5 , L_13 ,
V_355 . V_370 , V_355 . V_366 , V_355 . V_372 ,
V_355 . V_371 , V_355 . V_363 ) ;
F_80 ( V_1 , & V_355 ) ;
F_82 ( 2 ) ;
F_9 ( V_1 -> V_16 , V_79 ,
V_80 , V_81 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_1 , unsigned int V_388 )
{
int V_3 = 0 ;
V_1 -> V_389 = F_84 ( V_1 -> V_5 , L_14 ) ;
if ( F_85 ( V_1 -> V_389 ) ) {
F_86 ( V_1 -> V_5 , L_15 ) ;
return 0 ;
}
if ( ! V_1 -> V_390 ) {
V_3 = F_87 ( V_1 -> V_389 ) ;
if ( V_3 ) {
F_71 ( V_1 -> V_5 , L_16 ) ;
return V_3 ;
}
}
if ( V_1 -> V_390 != V_388 ) {
V_388 = F_88 ( V_1 -> V_389 , V_388 ) ;
V_3 = F_89 ( V_1 -> V_389 , V_388 ) ;
if ( V_3 ) {
F_71 ( V_1 -> V_5 , L_17 ) ;
return V_3 ;
}
V_1 -> V_390 = V_388 ;
}
return 0 ;
}
static void F_90 ( struct V_16 * V_16 )
{
F_9 ( V_16 , V_79 ,
V_80 , V_373 ) ;
F_9 ( V_16 , V_78 ,
V_82 , 0 ) ;
}
static int F_29 ( struct V_1 * V_1 , int V_391 ,
unsigned int V_388 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
int V_3 ;
switch ( V_391 ) {
case V_255 :
F_90 ( V_16 ) ;
if ( V_1 -> V_390 ) {
F_91 ( V_1 -> V_389 ) ;
V_1 -> V_390 = 0 ;
}
break;
case V_392 :
F_1 ( V_1 , 2 * V_200 ) ;
F_90 ( V_16 ) ;
F_9 ( V_16 , V_79 ,
V_83 , 0 ) ;
F_5 ( V_1 ) ;
V_3 = F_83 ( V_1 , V_388 ) ;
if ( V_3 )
return V_3 ;
break;
case V_117 :
if ( F_59 ( V_1 -> V_16 ) ) {
F_9 ( V_16 , V_78 ,
V_82 , V_82 ) ;
F_9 ( V_16 , V_79 ,
V_80 , V_81 ) ;
F_9 ( V_16 , V_79 ,
V_83 , 0xf ) ;
F_9 ( V_16 , V_73 ,
V_84 , 0x10 ) ;
F_9 ( V_16 , V_78 ,
V_382 , V_382 ) ;
} else {
F_90 ( V_16 ) ;
F_3 ( V_1 -> V_5 , L_18 ) ;
}
if ( V_1 -> V_390 ) {
F_91 ( V_1 -> V_389 ) ;
V_1 -> V_390 = 0 ;
}
break;
case V_393 :
F_1 ( V_1 , 2 * V_200 ) ;
F_9 ( V_16 , V_75 ,
V_394 , V_395 ) ;
F_5 ( V_1 ) ;
V_3 = F_83 ( V_1 , V_388 ) ;
if ( V_3 )
return V_3 ;
break;
case V_396 :
F_1 ( V_1 , 2 * V_200 ) ;
F_9 ( V_16 , V_75 ,
V_394 , V_397 ) ;
F_5 ( V_1 ) ;
if ( V_1 -> V_390 ) {
F_91 ( V_1 -> V_389 ) ;
V_1 -> V_390 = 0 ;
}
break;
case V_398 :
F_1 ( V_1 , 2 * V_200 ) ;
F_9 ( V_16 , V_75 ,
V_394 , V_399 ) ;
F_5 ( V_1 ) ;
if ( V_1 -> V_390 ) {
F_91 ( V_1 -> V_389 ) ;
V_1 -> V_390 = 0 ;
}
break;
default:
F_71 ( V_1 -> V_5 , L_19 , V_391 ) ;
return - V_38 ;
}
F_34 ( V_1 -> V_5 , L_20 , V_388 ,
V_391 ) ;
return 0 ;
}
static int F_92 ( struct V_172 * V_173 , int V_391 ,
int V_385 , unsigned int V_388 , int V_400 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
return F_29 ( V_1 , V_391 , V_388 ) ;
}
static int F_93 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_16 ;
F_29 ( V_1 , V_255 , 0 ) ;
F_61 ( V_16 ) ;
F_9 ( V_16 , V_108 ,
V_250 | V_252 |
V_251 | V_253 ,
V_250 | V_252 ) ;
F_9 ( V_16 , V_143 ,
V_254 , V_254 ) ;
F_9 ( V_16 , V_247 ,
V_249 | V_248 , 0 ) ;
return 0 ;
}
static int F_94 ( struct V_172 * V_173 ,
enum V_401 V_402 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
int V_3 ;
switch ( V_402 ) {
case V_403 :
break;
case V_404 :
break;
case V_405 :
if ( F_95 ( V_173 ) == V_406 ) {
if ( V_1 -> V_390 ) {
V_3 = F_87 ( V_1 -> V_389 ) ;
if ( V_3 ) {
F_71 ( V_1 -> V_5 , L_16 ) ;
return V_3 ;
}
}
F_93 ( V_1 ) ;
}
break;
case V_406 :
F_38 ( V_1 ) ;
F_21 ( V_1 -> V_16 ,
V_247 , 0xffff ) ;
F_9 ( V_1 -> V_16 , V_41 ,
V_44 , 0 ) ;
if ( V_1 -> V_390 )
F_91 ( V_1 -> V_389 ) ;
break;
}
return 0 ;
}
static int T_4 F_96 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
F_97 ( V_1 -> V_116 ) ;
F_98 ( V_173 , V_406 ) ;
F_99 ( V_1 -> V_16 , true ) ;
F_100 ( V_1 -> V_16 ) ;
return 0 ;
}
static int T_4 F_101 ( struct V_172 * V_173 )
{
struct V_1 * V_1 = F_45 ( V_173 ) ;
int V_3 ;
F_99 ( V_1 -> V_16 , false ) ;
F_102 ( V_1 -> V_16 ) ;
V_1 -> V_140 = true ;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 < 0 )
V_1 -> V_140 = false ;
F_103 ( V_1 -> V_116 ) ;
return 0 ;
}
static void F_104 ( struct V_16 * V_16 )
{
F_21 ( V_16 , V_161 , 0x00 ) ;
F_21 ( V_16 , V_161 , 0x00 ) ;
}
static void F_105 ( struct V_1 * V_1 )
{
int V_39 ;
struct V_141 * V_5 = V_1 -> V_5 ;
F_34 ( V_5 , L_21 , V_1 -> V_321 ) ;
F_34 ( V_5 , L_22 , V_1 -> V_323 ) ;
F_34 ( V_5 , L_23 , V_1 -> V_325 ) ;
F_34 ( V_5 , L_24 , V_1 -> V_326 ) ;
F_34 ( V_5 , L_25 , V_1 -> V_334 ) ;
F_34 ( V_5 , L_26 , V_1 -> V_314 ) ;
F_34 ( V_5 , L_27 , V_1 -> V_296 ) ;
for ( V_39 = 0 ; V_39 < V_1 -> V_296 ; V_39 ++ )
F_34 ( V_5 , L_28 , V_39 ,
V_1 -> V_304 [ V_39 ] ) ;
F_34 ( V_5 , L_29 , V_1 -> V_299 ) ;
F_34 ( V_5 , L_30 , V_1 -> V_287 ) ;
F_34 ( V_5 , L_31 , V_1 -> V_290 ) ;
F_34 ( V_5 , L_32 , V_1 -> V_293 ) ;
F_34 ( V_5 , L_33 , V_1 -> V_302 ) ;
F_34 ( V_5 , L_34 ,
V_1 -> V_328 ) ;
F_34 ( V_5 , L_35 ,
V_1 -> V_331 ) ;
}
static int F_106 ( struct V_141 * V_5 ,
struct V_1 * V_1 ) {
V_1 -> V_321 = F_107 ( V_5 ,
L_36 ) ;
V_1 -> V_323 = F_107 ( V_5 ,
L_37 ) ;
V_1 -> V_325 = F_107 ( V_5 ,
L_38 ) ;
F_108 ( V_5 , L_39 ,
& V_1 -> V_326 ) ;
F_108 ( V_5 , L_40 ,
& V_1 -> V_334 ) ;
F_108 ( V_5 , L_41 ,
& V_1 -> V_314 ) ;
F_108 ( V_5 , L_42 ,
& V_1 -> V_296 ) ;
F_109 ( V_5 , L_43 ,
V_1 -> V_304 , V_1 -> V_296 ) ;
F_108 ( V_5 , L_44 ,
& V_1 -> V_299 ) ;
F_108 ( V_5 , L_45 ,
& V_1 -> V_287 ) ;
F_108 ( V_5 , L_46 ,
& V_1 -> V_290 ) ;
F_108 ( V_5 , L_47 ,
& V_1 -> V_293 ) ;
F_108 ( V_5 , L_48 ,
& V_1 -> V_302 ) ;
F_108 ( V_5 , L_49 ,
& V_1 -> V_328 ) ;
F_108 ( V_5 , L_50 ,
& V_1 -> V_331 ) ;
V_1 -> V_389 = F_84 ( V_5 , L_14 ) ;
if ( F_110 ( V_1 -> V_389 ) == - V_407 ) {
return - V_407 ;
} else if ( F_110 ( V_1 -> V_389 ) == - V_408 ) {
V_1 -> V_389 = NULL ;
F_86 ( V_5 , L_15 ) ;
} else if ( F_85 ( V_1 -> V_389 ) ) {
return - V_38 ;
}
return 0 ;
}
static int F_111 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_112 ( V_1 -> V_5 , V_1 -> V_116 , NULL ,
F_70 , V_409 | V_410 ,
L_51 , V_1 ) ;
if ( V_3 ) {
F_71 ( V_1 -> V_5 , L_52 ,
V_1 -> V_116 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int F_113 ( struct V_411 * V_412 ,
const struct V_413 * V_414 )
{
struct V_141 * V_5 = & V_412 -> V_5 ;
struct V_1 * V_1 = F_114 ( & V_412 -> V_5 ) ;
int V_3 , V_10 ;
if ( ! V_1 ) {
V_1 = F_115 ( V_5 , sizeof( * V_1 ) , V_190 ) ;
if ( ! V_1 )
return - V_192 ;
V_3 = F_106 ( V_5 , V_1 ) ;
if ( V_3 )
return V_3 ;
}
F_116 ( V_412 , V_1 ) ;
V_1 -> V_16 = F_117 ( V_412 , & V_415 ) ;
if ( F_85 ( V_1 -> V_16 ) )
return F_110 ( V_1 -> V_16 ) ;
V_1 -> V_5 = V_5 ;
V_1 -> V_116 = V_412 -> V_116 ;
V_1 -> V_124 = V_133 ;
V_1 -> V_140 = false ;
F_118 ( & V_1 -> V_4 , 1 ) ;
F_119 ( & V_1 -> V_136 , F_35 ) ;
F_105 ( V_1 ) ;
F_104 ( V_1 -> V_16 ) ;
V_3 = F_19 ( V_1 -> V_16 , V_153 , & V_10 ) ;
if ( V_3 < 0 ) {
F_71 ( V_5 , L_53 ,
V_3 ) ;
return V_3 ;
}
if ( ( V_10 & V_416 ) !=
V_417 ) {
F_71 ( V_5 , L_54 ) ;
return - V_418 ;
}
F_74 ( V_1 ) ;
if ( V_412 -> V_116 )
F_111 ( V_1 ) ;
return F_120 ( & V_412 -> V_5 , & V_419 ,
& V_420 , 1 ) ;
}
static int F_121 ( struct V_411 * V_421 )
{
F_122 ( & V_421 -> V_5 ) ;
return 0 ;
}
