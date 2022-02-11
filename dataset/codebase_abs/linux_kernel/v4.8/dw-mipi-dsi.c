static int F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] . V_1 > V_1 )
return V_3 [ V_2 ] . V_4 ;
return - V_5 ;
}
static void F_3 ( struct V_6 * V_7 )
{
int V_8 , V_9 ;
V_8 = F_4 ( V_7 -> V_10 ) ;
V_9 = F_5 ( V_11 , V_8 ) * 2 ;
F_6 ( V_9 ) ;
}
static inline struct V_6 * F_7 ( struct V_12 * V_13 )
{
return F_8 ( V_13 , struct V_6 , V_14 ) ;
}
static inline struct V_6 * F_9 ( struct V_15 * V_16 )
{
return F_8 ( V_16 , struct V_6 , V_17 ) ;
}
static inline struct V_6 * F_10 ( struct V_18 * V_19 )
{
return F_8 ( V_19 , struct V_6 , V_19 ) ;
}
static inline void F_11 ( struct V_6 * V_7 , T_1 V_20 , T_1 V_21 )
{
F_12 ( V_21 , V_7 -> V_22 + V_20 ) ;
}
static inline T_1 F_13 ( struct V_6 * V_7 , T_1 V_20 )
{
return F_14 ( V_7 -> V_22 + V_20 ) ;
}
static void F_15 ( struct V_6 * V_7 , T_2 V_23 ,
T_2 V_24 )
{
F_11 ( V_7 , V_25 , V_26 | V_27 ) ;
F_11 ( V_7 , V_28 , V_29 | F_16 ( 0 ) |
F_17 ( V_23 ) ) ;
F_11 ( V_7 , V_25 , V_30 | V_27 ) ;
F_11 ( V_7 , V_28 , V_31 | F_16 ( 0 ) |
F_17 ( V_24 ) ) ;
F_11 ( V_7 , V_25 , V_26 | V_27 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_32 , V_4 , V_33 , V_21 ;
V_33 = ( V_7 -> V_34 < 200 ) ? 0 : ( V_7 -> V_34 + 100 ) / 200 ;
V_4 = F_1 ( V_7 -> V_34 ) ;
if ( V_4 < 0 ) {
F_19 ( V_7 -> V_35 ,
L_1 ,
V_7 -> V_34 ) ;
return V_4 ;
}
F_11 ( V_7 , V_36 , V_37 ) ;
F_15 ( V_7 , 0x10 , V_38 |
F_20 ( V_33 ) |
V_39 |
V_40 ) ;
F_15 ( V_7 , 0x11 , V_41 ) ;
F_15 ( V_7 , 0x12 , V_42 | V_43 |
V_44 ) ;
F_15 ( V_7 , 0x44 , F_21 ( V_4 ) ) ;
F_15 ( V_7 , 0x19 , V_45 | V_46 ) ;
F_15 ( V_7 , 0x17 , F_22 ( V_7 -> V_47 ) ) ;
F_15 ( V_7 , 0x18 , F_23 ( V_7 -> V_48 ) |
V_49 ) ;
F_15 ( V_7 , 0x18 , F_24 ( V_7 -> V_48 ) |
V_50 ) ;
F_15 ( V_7 , 0x20 , V_51 | V_52 |
V_53 | V_54 ) ;
F_15 ( V_7 , 0x21 , V_55 | V_56 |
V_57 | V_58 ) ;
F_15 ( V_7 , 0x21 , V_59 | V_60 |
V_57 | V_61 |
V_58 ) ;
F_15 ( V_7 , 0x22 , V_49 |
F_25 ( V_62 ) ) ;
F_15 ( V_7 , 0x22 , V_50 |
F_26 ( V_63 ) ) ;
F_15 ( V_7 , 0x70 , V_64 | 0xf ) ;
F_15 ( V_7 , 0x71 , V_65 | 0x55 ) ;
F_15 ( V_7 , 0x72 , V_66 | 0xa ) ;
F_11 ( V_7 , V_67 , V_68 | V_69 |
V_70 | V_71 ) ;
V_32 = F_27 ( F_14 , V_7 -> V_22 + V_72 ,
V_21 , V_21 & V_73 , 1000 , V_74 ) ;
if ( V_32 < 0 ) {
F_19 ( V_7 -> V_35 , L_2 ) ;
return V_32 ;
}
V_32 = F_27 ( F_14 , V_7 -> V_22 + V_72 ,
V_21 , V_21 & V_75 , 1000 ,
V_74 ) ;
if ( V_32 < 0 ) {
F_19 ( V_7 -> V_35 ,
L_3 ) ;
return V_32 ;
}
return V_32 ;
}
static int F_28 ( struct V_6 * V_7 )
{
unsigned int V_2 , V_76 ;
unsigned long V_77 , V_78 , V_79 ;
unsigned int V_80 = 1 , V_81 = 1 , V_82 = 1000 ;
unsigned int V_1 = V_3 [ F_2 ( V_3 ) - 1 ] . V_1 ;
int V_83 ;
V_83 = F_29 ( V_7 -> V_84 ) ;
if ( V_83 < 0 ) {
F_19 ( V_7 -> V_35 , L_4 ,
V_7 -> V_84 ) ;
return V_83 ;
}
V_77 = F_5 ( V_7 -> V_10 -> clock , V_11 ) ;
if ( V_77 ) {
V_79 = V_77 * ( V_83 / V_7 -> V_85 ) * 10 / 9 ;
if ( V_79 < V_1 )
V_82 = V_79 ;
else
F_19 ( V_7 -> V_35 , L_5 ) ;
}
V_78 = F_5 ( F_30 ( V_7 -> V_86 ) , V_87 ) ;
V_79 = V_78 ;
for ( V_2 = 1 ; V_2 < 6 ; V_2 ++ ) {
V_76 = V_78 / V_2 ;
if ( ( V_79 > ( V_82 % V_76 ) ) && ( V_82 / V_76 < 512 ) ) {
V_79 = V_82 % V_76 ;
V_81 = V_2 ;
V_80 = V_82 / V_76 ;
}
if ( V_79 == 0 )
break;
}
V_7 -> V_34 = V_78 / V_81 * V_80 ;
V_7 -> V_47 = V_81 ;
V_7 -> V_48 = V_80 ;
return 0 ;
}
static int F_31 ( struct V_12 * V_13 ,
struct V_88 * V_89 )
{
struct V_6 * V_7 = F_7 ( V_13 ) ;
if ( V_89 -> V_85 > V_7 -> V_90 -> V_91 ) {
F_19 ( V_7 -> V_35 , L_6 ,
V_89 -> V_85 ) ;
return - V_5 ;
}
if ( ! ( V_89 -> V_92 & V_93 ) ||
! ( V_89 -> V_92 & V_94 ) ) {
F_19 ( V_7 -> V_35 , L_7 ) ;
return - V_5 ;
}
V_7 -> V_85 = V_89 -> V_85 ;
V_7 -> V_95 = V_89 -> V_95 ;
V_7 -> V_84 = V_89 -> V_84 ;
V_7 -> V_96 = F_32 ( V_89 -> V_35 . V_97 ) ;
if ( V_7 -> V_96 )
return F_33 ( V_7 -> V_96 , & V_7 -> V_17 ) ;
return - V_5 ;
}
static int F_34 ( struct V_12 * V_13 ,
struct V_88 * V_89 )
{
struct V_6 * V_7 = F_7 ( V_13 ) ;
F_35 ( V_7 -> V_96 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 , T_1 V_21 )
{
int V_32 ;
V_32 = F_27 ( F_14 , V_7 -> V_22 + V_98 ,
V_21 , ! ( V_21 & V_99 ) , 1000 ,
V_100 ) ;
if ( V_32 < 0 ) {
F_19 ( V_7 -> V_35 , L_8 ) ;
return V_32 ;
}
F_11 ( V_7 , V_101 , V_21 ) ;
V_32 = F_27 ( F_14 , V_7 -> V_22 + V_98 ,
V_21 , V_21 & ( V_102 | V_103 ) ,
1000 , V_100 ) ;
if ( V_32 < 0 ) {
F_19 ( V_7 -> V_35 , L_9 ) ;
return V_32 ;
}
return 0 ;
}
static int F_37 ( struct V_6 * V_7 ,
const struct V_104 * V_105 )
{
const T_3 * V_106 = V_105 -> V_106 ;
T_1 V_21 = F_38 ( * V_106 ) | F_39 ( V_105 -> type ) ;
if ( V_105 -> V_107 > 2 ) {
F_19 ( V_7 -> V_35 , L_10 ,
V_105 -> V_107 ) ;
return - V_5 ;
}
return F_36 ( V_7 , V_21 ) ;
}
static int F_40 ( struct V_6 * V_7 ,
const struct V_104 * V_105 )
{
const T_1 * V_106 = V_105 -> V_106 ;
int V_108 = V_105 -> V_107 , V_109 = sizeof( * V_106 ) , V_32 ;
T_1 V_21 = F_38 ( V_105 -> V_107 ) | F_39 ( V_105 -> type ) ;
T_1 V_110 = 0 ;
if ( V_105 -> V_107 < 3 ) {
F_19 ( V_7 -> V_35 , L_11 ,
V_105 -> V_107 ) ;
return - V_5 ;
}
while ( F_5 ( V_108 , V_109 ) ) {
if ( V_108 < V_109 ) {
memcpy ( & V_110 , V_106 , V_108 ) ;
F_11 ( V_7 , V_111 , V_110 ) ;
V_108 = 0 ;
} else {
F_11 ( V_7 , V_111 , * V_106 ) ;
V_106 ++ ;
V_108 -= V_109 ;
}
V_32 = F_27 ( F_14 , V_7 -> V_22 + V_98 ,
V_21 , ! ( V_21 & V_112 ) , 1000 ,
V_100 ) ;
if ( V_32 < 0 ) {
F_19 ( V_7 -> V_35 ,
L_12 ) ;
return V_32 ;
}
}
return F_36 ( V_7 , V_21 ) ;
}
static T_4 F_41 ( struct V_12 * V_13 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_7 ( V_13 ) ;
int V_32 ;
switch ( V_105 -> type ) {
case V_113 :
case V_114 :
case V_115 :
V_32 = F_37 ( V_7 , V_105 ) ;
break;
case V_116 :
V_32 = F_40 ( V_7 , V_105 ) ;
break;
default:
F_19 ( V_7 -> V_35 , L_13 ) ;
V_32 = - V_5 ;
}
return V_32 ;
}
static void F_42 ( struct V_6 * V_7 )
{
T_1 V_21 ;
V_21 = V_117 | V_118 ;
F_11 ( V_7 , V_119 , V_21 ) ;
}
static void F_43 ( struct V_6 * V_7 ,
enum V_120 V_10 )
{
if ( V_10 == V_121 ) {
F_11 ( V_7 , V_36 , V_122 ) ;
F_11 ( V_7 , V_123 , V_124 ) ;
F_11 ( V_7 , V_36 , V_37 ) ;
} else {
F_11 ( V_7 , V_36 , V_122 ) ;
F_11 ( V_7 , V_123 , V_125 ) ;
F_42 ( V_7 ) ;
F_11 ( V_7 , V_36 , V_37 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_11 ( V_7 , V_36 , V_122 ) ;
F_11 ( V_7 , V_67 , V_126 ) ;
}
static void F_45 ( struct V_6 * V_7 )
{
F_11 ( V_7 , V_36 , V_122 ) ;
F_11 ( V_7 , V_67 , V_127 | V_128
| V_126 | V_129 ) ;
F_11 ( V_7 , V_130 , F_46 ( 10 ) |
F_47 ( 7 ) ) ;
F_11 ( V_7 , V_131 , V_132 ) ;
}
static void F_48 ( struct V_6 * V_7 ,
struct V_133 * V_10 )
{
T_1 V_21 = 0 , V_134 = 0 ;
switch ( V_7 -> V_84 ) {
case V_135 :
V_134 = V_136 ;
break;
case V_137 :
V_134 = V_138 | V_139 ;
break;
case V_140 :
V_134 = V_141 ;
break;
case V_142 :
V_134 = V_143 ;
break;
}
if ( ! ( V_10 -> V_144 & V_145 ) )
V_21 |= V_146 ;
if ( ! ( V_10 -> V_144 & V_147 ) )
V_21 |= V_148 ;
F_11 ( V_7 , V_149 , F_49 ( V_7 -> V_95 ) ) ;
F_11 ( V_7 , V_150 , V_134 ) ;
F_11 ( V_7 , V_151 , V_21 ) ;
F_11 ( V_7 , V_152 , F_50 ( 4 )
| F_51 ( 4 ) ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
F_11 ( V_7 , V_153 , V_154 | V_155 | V_156 ) ;
}
static void F_53 ( struct V_6 * V_7 ,
struct V_133 * V_10 )
{
F_11 ( V_7 , V_157 , F_54 ( V_10 -> V_158 ) ) ;
}
static void F_55 ( struct V_6 * V_7 )
{
F_11 ( V_7 , V_159 , F_56 ( 1000 ) | F_57 ( 1000 ) ) ;
F_11 ( V_7 , V_160 , 0xd00 ) ;
F_11 ( V_7 , V_161 , V_162 ) ;
F_11 ( V_7 , V_123 , V_124 ) ;
}
static T_1 F_58 ( struct V_6 * V_7 ,
T_1 V_163 )
{
T_1 V_164 , V_165 ;
V_165 = V_163 * V_7 -> V_34 * V_11 / 8 ;
V_164 = V_165 % V_7 -> V_10 -> clock ;
V_165 = V_165 / V_7 -> V_10 -> clock ;
if ( V_164 )
V_165 ++ ;
return V_165 ;
}
static void F_59 ( struct V_6 * V_7 )
{
T_1 V_166 , V_167 , V_168 , V_165 ;
struct V_133 * V_10 = V_7 -> V_10 ;
V_166 = V_10 -> V_166 ;
V_167 = V_10 -> V_169 - V_10 -> V_170 ;
V_168 = V_10 -> V_166 - V_10 -> V_169 ;
V_165 = F_58 ( V_7 , V_166 ) ;
F_11 ( V_7 , V_171 , V_165 ) ;
V_165 = F_58 ( V_7 , V_167 ) ;
F_11 ( V_7 , V_172 , V_165 ) ;
V_165 = F_58 ( V_7 , V_168 ) ;
F_11 ( V_7 , V_173 , V_165 ) ;
}
static void F_60 ( struct V_6 * V_7 )
{
T_1 V_174 , V_175 , V_176 , V_177 ;
struct V_133 * V_10 = V_7 -> V_10 ;
V_174 = V_10 -> V_178 ;
V_175 = V_10 -> V_179 - V_10 -> V_180 ;
V_176 = V_10 -> V_180 - V_10 -> V_178 ;
V_177 = V_10 -> V_181 - V_10 -> V_179 ;
F_11 ( V_7 , V_182 , V_174 ) ;
F_11 ( V_7 , V_183 , V_175 ) ;
F_11 ( V_7 , V_184 , V_176 ) ;
F_11 ( V_7 , V_185 , V_177 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_11 ( V_7 , V_186 , F_62 ( 0x40 )
| F_63 ( 0x40 ) | F_64 ( 10000 ) ) ;
F_11 ( V_7 , V_187 , F_65 ( 0x40 )
| F_66 ( 0x40 ) ) ;
}
static void F_67 ( struct V_6 * V_7 )
{
F_11 ( V_7 , V_188 , F_68 ( 0x20 ) |
F_69 ( V_7 -> V_85 ) ) ;
}
static void F_70 ( struct V_6 * V_7 )
{
F_13 ( V_7 , V_189 ) ;
F_13 ( V_7 , V_190 ) ;
F_11 ( V_7 , V_191 , 0 ) ;
F_11 ( V_7 , V_192 , 0 ) ;
}
static void F_71 ( struct V_18 * V_19 ,
struct V_133 * V_10 ,
struct V_133 * V_193 )
{
struct V_6 * V_7 = F_10 ( V_19 ) ;
int V_32 ;
V_7 -> V_10 = V_193 ;
V_32 = F_28 ( V_7 ) ;
if ( V_32 < 0 )
return;
if ( F_72 ( V_7 -> V_194 ) ) {
F_19 ( V_7 -> V_35 , L_14 , V_195 ) ;
return;
}
F_45 ( V_7 ) ;
F_48 ( V_7 , V_10 ) ;
F_52 ( V_7 ) ;
F_42 ( V_7 ) ;
F_53 ( V_7 , V_10 ) ;
F_55 ( V_7 ) ;
F_59 ( V_7 ) ;
F_60 ( V_7 ) ;
F_61 ( V_7 ) ;
F_67 ( V_7 ) ;
F_70 ( V_7 ) ;
if ( F_73 ( V_7 -> V_96 ) )
F_19 ( V_7 -> V_35 , L_15 ) ;
F_74 ( V_7 -> V_194 ) ;
}
static void F_75 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_10 ( V_19 ) ;
F_76 ( V_7 -> V_96 ) ;
if ( F_72 ( V_7 -> V_194 ) ) {
F_19 ( V_7 -> V_35 , L_14 , V_195 ) ;
return;
}
F_43 ( V_7 , V_121 ) ;
F_77 ( V_7 -> V_96 ) ;
F_43 ( V_7 , V_196 ) ;
F_6 ( 120 ) ;
F_43 ( V_7 , V_121 ) ;
F_44 ( V_7 ) ;
F_74 ( V_7 -> V_194 ) ;
}
static void F_78 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_10 ( V_19 ) ;
int V_197 = F_79 ( V_7 -> V_35 -> V_97 , V_19 ) ;
T_1 V_21 ;
if ( F_72 ( V_7 -> V_194 ) ) {
F_19 ( V_7 -> V_35 , L_14 , V_195 ) ;
return;
}
F_18 ( V_7 ) ;
F_3 ( V_7 ) ;
F_43 ( V_7 , V_196 ) ;
F_80 ( V_7 -> V_96 ) ;
F_74 ( V_7 -> V_194 ) ;
if ( V_197 )
V_21 = V_198 | ( V_198 << 16 ) ;
else
V_21 = V_198 << 16 ;
F_81 ( V_7 -> V_199 , V_200 , V_21 ) ;
F_82 ( V_7 -> V_35 , L_16 , ( V_197 ) ? L_17 : L_18 ) ;
}
static int
F_83 ( struct V_18 * V_19 ,
struct V_201 * V_202 ,
struct V_203 * V_204 )
{
struct V_205 * V_206 = F_84 ( V_202 ) ;
struct V_6 * V_7 = F_10 ( V_19 ) ;
switch ( V_7 -> V_84 ) {
case V_135 :
V_206 -> V_207 = V_208 ;
break;
case V_137 :
V_206 -> V_207 = V_209 ;
break;
case V_142 :
V_206 -> V_207 = V_210 ;
break;
default:
F_85 ( 1 ) ;
return - V_5 ;
}
V_206 -> V_211 = V_212 ;
return 0 ;
}
static int F_86 ( struct V_15 * V_17 )
{
struct V_6 * V_7 = F_9 ( V_17 ) ;
return F_87 ( V_7 -> V_96 ) ;
}
static enum V_213 F_88 (
struct V_15 * V_17 ,
struct V_133 * V_10 )
{
struct V_6 * V_7 = F_9 ( V_17 ) ;
enum V_213 V_214 = V_215 ;
if ( V_7 -> V_90 -> V_216 )
V_214 = V_7 -> V_90 -> V_216 ( V_17 , V_10 ) ;
return V_214 ;
}
static enum V_217
F_89 ( struct V_15 * V_17 , bool V_218 )
{
return V_219 ;
}
static void F_90 ( struct V_15 * V_17 )
{
F_91 ( V_17 ) ;
F_92 ( V_17 ) ;
}
static int F_93 ( struct V_220 * V_221 ,
struct V_6 * V_7 )
{
struct V_18 * V_19 = & V_7 -> V_19 ;
struct V_15 * V_17 = & V_7 -> V_17 ;
struct V_89 * V_35 = V_7 -> V_35 ;
int V_32 ;
V_19 -> V_222 = F_94 ( V_221 ,
V_35 -> V_97 ) ;
if ( V_19 -> V_222 == 0 )
return - V_223 ;
F_95 ( & V_7 -> V_19 ,
& V_224 ) ;
V_32 = F_96 ( V_221 , & V_7 -> V_19 , & V_225 ,
V_226 , NULL ) ;
if ( V_32 ) {
F_19 ( V_35 , L_19 ) ;
return V_32 ;
}
F_97 ( V_17 ,
& V_227 ) ;
F_98 ( V_221 , & V_7 -> V_17 ,
& V_228 ,
V_212 ) ;
F_99 ( V_17 , V_19 ) ;
return 0 ;
}
static int F_100 ( struct V_6 * V_7 )
{
struct V_229 * V_230 = V_7 -> V_35 -> V_97 ;
V_7 -> V_199 = F_101 ( V_230 , L_20 ) ;
if ( F_102 ( V_7 -> V_199 ) ) {
F_19 ( V_7 -> V_35 , L_21 ) ;
return F_103 ( V_7 -> V_199 ) ;
}
return 0 ;
}
static enum V_213 F_104 (
struct V_15 * V_17 ,
struct V_133 * V_10 )
{
if ( V_10 -> V_158 > 0x7ff )
return V_231 ;
if ( V_10 -> V_178 > 0x7ff )
return V_232 ;
return V_215 ;
}
static int F_105 ( struct V_89 * V_35 , struct V_89 * V_233 ,
void * V_234 )
{
const struct V_235 * V_236 =
F_106 ( V_237 , V_35 ) ;
const struct V_238 * V_90 = V_236 -> V_234 ;
struct V_239 * V_240 = F_107 ( V_35 ) ;
struct V_220 * V_221 = V_234 ;
struct V_6 * V_7 ;
struct V_241 * V_242 ;
int V_32 ;
V_7 = F_108 ( V_35 , sizeof( * V_7 ) , V_243 ) ;
if ( ! V_7 )
return - V_244 ;
V_7 -> V_35 = V_35 ;
V_7 -> V_90 = V_90 ;
V_32 = F_100 ( V_7 ) ;
if ( V_32 )
return V_32 ;
V_242 = F_109 ( V_240 , V_245 , 0 ) ;
if ( ! V_242 )
return - V_246 ;
V_7 -> V_22 = F_110 ( V_35 , V_242 ) ;
if ( F_102 ( V_7 -> V_22 ) )
return F_103 ( V_7 -> V_22 ) ;
V_7 -> V_86 = F_111 ( V_35 , L_22 ) ;
if ( F_102 ( V_7 -> V_86 ) ) {
V_32 = F_103 ( V_7 -> V_86 ) ;
F_19 ( V_35 , L_23 , V_32 ) ;
return V_32 ;
}
V_7 -> V_194 = F_111 ( V_35 , L_24 ) ;
if ( F_102 ( V_7 -> V_194 ) ) {
V_32 = F_103 ( V_7 -> V_194 ) ;
F_19 ( V_35 , L_25 , V_32 ) ;
return V_32 ;
}
V_32 = F_72 ( V_7 -> V_86 ) ;
if ( V_32 ) {
F_19 ( V_35 , L_26 , V_195 ) ;
return V_32 ;
}
V_32 = F_93 ( V_221 , V_7 ) ;
if ( V_32 ) {
F_19 ( V_35 , L_27 , V_32 ) ;
goto V_247;
}
F_112 ( V_35 , V_7 ) ;
V_7 -> V_14 . V_248 = & V_249 ;
V_7 -> V_14 . V_35 = V_35 ;
return F_113 ( & V_7 -> V_14 ) ;
V_247:
F_74 ( V_7 -> V_86 ) ;
return V_32 ;
}
static void F_114 ( struct V_89 * V_35 , struct V_89 * V_233 ,
void * V_234 )
{
struct V_6 * V_7 = F_115 ( V_35 ) ;
F_116 ( & V_7 -> V_14 ) ;
F_74 ( V_7 -> V_86 ) ;
}
static int F_117 ( struct V_239 * V_240 )
{
return F_118 ( & V_240 -> V_35 , & V_250 ) ;
}
static int F_119 ( struct V_239 * V_240 )
{
F_120 ( & V_240 -> V_35 , & V_250 ) ;
return 0 ;
}
