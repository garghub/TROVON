static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_5 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_5 ( V_6 , V_2 -> V_7 ) ;
}
static int F_6 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_9 ( void * V_8 )
{
struct V_1 * V_2 ;
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_10 ( V_4 , 124 , & V_4 -> V_10 . V_11 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_11 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 = & V_4 -> V_10 . V_2 ;
sprintf ( V_2 -> V_12 , L_1 ) ;
V_9 = F_13 ( V_4 , V_2 , 512 , & V_4 -> V_10 . V_11 , 0 ) ;
return V_9 ;
}
static int F_14 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_16 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_17 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_13 ;
int V_9 ;
F_18 ( V_4 , 10000 , 10000 ) ;
F_19 ( V_4 , V_14 ) ;
F_20 ( V_4 , true ) ;
V_2 -> V_15 = true ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_15 = false ;
goto V_16;
}
V_9 = F_22 ( V_2 , 10 ) ;
if ( V_9 ) {
F_23 ( L_2 , V_9 ) ;
goto V_16;
}
V_13 = F_24 ( V_17 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_13 = F_24 ( V_18 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_13 = F_24 ( V_19 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
F_25 ( V_2 , F_24 ( V_20 , 0 ) ) ;
F_25 ( V_2 , 0x8 ) ;
F_25 ( V_2 , F_24 ( V_21 , 0 ) ) ;
F_25 ( V_2 , 3 ) ;
F_26 ( V_2 ) ;
V_16:
if ( ! V_9 )
F_27 ( L_3 ) ;
return V_9 ;
}
static int F_28 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
if ( F_2 ( V_22 ) != 0 )
F_29 ( V_4 ) ;
V_2 -> V_15 = false ;
return 0 ;
}
static int F_30 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_28 ( V_4 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_4 -> V_23 & V_24 ) ) {
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
}
return V_9 ;
}
static int F_31 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_23 & V_24 ) ) {
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static void F_32 ( struct V_3 * V_4 )
{
T_2 V_25 ;
T_1 V_26 ;
F_5 ( V_27 ,
F_33 ( V_4 -> V_10 . V_28 ) ) ;
F_5 ( V_29 ,
F_34 ( V_4 -> V_10 . V_28 ) ) ;
V_25 = V_30 ;
V_26 = F_35 ( V_4 -> V_10 . V_31 -> V_26 + 4 ) ;
F_5 ( V_32 , V_25 >> 3 ) ;
F_5 ( V_33 , V_26 ) ;
V_25 += V_26 ;
V_26 = V_34 ;
F_5 ( V_35 , V_25 >> 3 ) ;
F_5 ( V_36 , V_26 ) ;
V_25 += V_26 ;
V_26 = V_37 +
( V_38 * V_4 -> V_10 . V_39 ) ;
F_5 ( V_40 , V_25 >> 3 ) ;
F_5 ( V_41 , V_26 ) ;
F_5 ( V_42 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_46 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_47 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_48 , V_4 -> V_10 . V_39 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_49 , V_13 ;
T_1 V_50 ;
T_1 V_51 ;
int V_52 , V_53 , V_9 ;
F_37 ( V_54 , 0 , ~ V_55 ) ;
V_50 = 0 ;
V_51 = 0 ;
F_32 ( V_4 ) ;
F_38 ( V_56 , V_57 , 0 ) ;
F_38 ( V_58 , V_59 , 1 ) ;
F_39 ( 1 ) ;
F_5 ( V_60 ,
V_61 |
V_62 |
V_63 |
V_64 |
V_65 |
V_66 |
V_67 |
V_68 ) ;
F_39 ( 5 ) ;
F_38 ( V_69 , V_70 , 0 ) ;
F_39 ( 5 ) ;
F_5 ( V_71 ,
( 0x40 << V_72 ) |
V_73 |
V_74 |
V_75 |
V_76 |
V_77 ) ;
#ifdef F_40
V_50 = 0xa ;
V_51 = 0 ;
#endif
F_5 ( V_78 , V_50 ) ;
F_5 ( V_79 , V_51 ) ;
F_5 ( V_80 , 0x40c2040 ) ;
F_5 ( V_81 , 0x0 ) ;
F_5 ( V_82 , 0x40c2040 ) ;
F_5 ( V_83 , 0x0 ) ;
F_5 ( V_84 , 0 ) ;
F_5 ( V_85 , 0x88 ) ;
F_5 ( V_60 , V_62 ) ;
F_39 ( 5 ) ;
F_5 ( V_86 , V_87 ) ;
F_38 ( V_58 , V_59 , 0 ) ;
F_5 ( V_60 , 0 ) ;
F_39 ( 10 ) ;
for ( V_52 = 0 ; V_52 < 10 ; ++ V_52 ) {
T_1 V_88 ;
for ( V_53 = 0 ; V_53 < 100 ; ++ V_53 ) {
V_88 = F_2 ( V_22 ) ;
if ( V_88 & 2 )
break;
F_39 ( 10 ) ;
}
V_9 = 0 ;
if ( V_88 & 2 )
break;
F_23 ( L_4 ) ;
F_38 ( V_89 , V_90 , 1 ) ;
F_39 ( 10 ) ;
F_38 ( V_89 , V_90 , 0 ) ;
F_39 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_23 ( L_5 ) ;
return V_9 ;
}
F_37 ( V_91 ,
( V_92 | V_93 ) ,
~ ( V_92 | V_93 ) ) ;
F_37 ( V_22 , 0 , ~ ( 2 << V_94 ) ) ;
V_49 = F_41 ( V_2 -> V_95 ) ;
V_13 = F_42 ( 0 , V_96 , V_97 , V_49 ) ;
V_13 = F_42 ( V_13 , V_96 , V_98 , 1 ) ;
V_13 = F_42 ( V_13 , V_96 , V_99 , 1 ) ;
V_13 = F_42 ( V_13 , V_96 , V_100 , 0 ) ;
V_13 = F_42 ( V_13 , V_96 , V_101 , 1 ) ;
V_13 = F_42 ( V_13 , V_96 , V_102 , 1 ) ;
F_5 ( V_103 , V_13 ) ;
F_5 ( V_104 , 0 ) ;
F_5 ( V_105 , ( F_34 ( V_2 -> V_28 ) >> 2 ) ) ;
F_5 ( V_106 ,
F_33 ( V_2 -> V_28 ) ) ;
F_5 ( V_107 ,
F_34 ( V_2 -> V_28 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_38 ( V_96 , V_99 , 0 ) ;
return 0 ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_5 ( V_103 , 0x11010101 ) ;
F_37 ( V_108 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_39 ( 1 ) ;
F_5 ( V_60 , V_62 ) ;
F_39 ( 5 ) ;
F_5 ( V_86 , 0x0 ) ;
F_37 ( V_108 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_22 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_3 V_109 , T_3 V_110 ,
unsigned V_23 )
{
F_44 ( V_23 & V_111 ) ;
F_25 ( V_2 , F_24 ( V_112 , 0 ) ) ;
F_25 ( V_2 , V_110 ) ;
F_25 ( V_2 , F_24 ( V_113 , 0 ) ) ;
F_25 ( V_2 , V_109 & 0xffffffff ) ;
F_25 ( V_2 , F_24 ( V_114 , 0 ) ) ;
F_25 ( V_2 , F_34 ( V_109 ) & 0xff ) ;
F_25 ( V_2 , F_24 ( V_115 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_113 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_114 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_115 , 0 ) ) ;
F_25 ( V_2 , 2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_116 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_117 , 0 ) ) ;
F_25 ( V_2 , 1 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 = 0 ;
unsigned V_52 ;
int V_9 ;
F_5 ( V_112 , 0xCAFEDEAD ) ;
V_9 = F_22 ( V_2 , 3 ) ;
if ( V_9 ) {
F_23 ( L_6 ,
V_2 -> V_118 , V_9 ) ;
return V_9 ;
}
F_25 ( V_2 , F_24 ( V_112 , 0 ) ) ;
F_25 ( V_2 , 0xDEADBEEF ) ;
F_26 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_4 -> V_119 ; V_52 ++ ) {
V_13 = F_2 ( V_112 ) ;
if ( V_13 == 0xDEADBEEF )
break;
F_48 ( 1 ) ;
}
if ( V_52 < V_4 -> V_119 ) {
F_27 ( L_7 ,
V_2 -> V_118 , V_52 ) ;
} else {
F_23 ( L_8 ,
V_2 -> V_118 , V_13 ) ;
V_9 = - V_120 ;
}
return V_9 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_121 * V_122 ,
unsigned V_123 , bool V_124 )
{
F_25 ( V_2 , F_24 ( V_125 , 0 ) ) ;
F_25 ( V_2 , V_123 ) ;
F_25 ( V_2 , F_24 ( V_126 , 0 ) ) ;
F_25 ( V_2 , F_33 ( V_122 -> V_28 ) ) ;
F_25 ( V_2 , F_24 ( V_127 , 0 ) ) ;
F_25 ( V_2 , F_34 ( V_122 -> V_28 ) ) ;
F_25 ( V_2 , F_24 ( V_128 , 0 ) ) ;
F_25 ( V_2 , V_122 -> V_129 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned V_123 , T_2 V_130 )
{
T_1 V_131 ;
if ( V_123 < 8 )
V_131 = V_132 + V_123 ;
else
V_131 = V_133 + V_123 - 8 ;
F_25 ( V_2 , F_24 ( V_113 , 0 ) ) ;
F_25 ( V_2 , V_131 << 2 ) ;
F_25 ( V_2 , F_24 ( V_114 , 0 ) ) ;
F_25 ( V_2 , V_130 >> 12 ) ;
F_25 ( V_2 , F_24 ( V_115 , 0 ) ) ;
F_25 ( V_2 , 0x8 ) ;
F_25 ( V_2 , F_24 ( V_113 , 0 ) ) ;
F_25 ( V_2 , V_134 << 2 ) ;
F_25 ( V_2 , F_24 ( V_114 , 0 ) ) ;
F_25 ( V_2 , 1 << V_123 ) ;
F_25 ( V_2 , F_24 ( V_115 , 0 ) ) ;
F_25 ( V_2 , 0x8 ) ;
F_25 ( V_2 , F_24 ( V_113 , 0 ) ) ;
F_25 ( V_2 , V_134 << 2 ) ;
F_25 ( V_2 , F_24 ( V_114 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_135 , 0 ) ) ;
F_25 ( V_2 , 1 << V_123 ) ;
F_25 ( V_2 , F_24 ( V_115 , 0 ) ) ;
F_25 ( V_2 , 0xC ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_110 = V_2 -> V_136 . V_137 ;
T_2 V_109 = V_2 -> V_136 . V_28 ;
F_25 ( V_2 , F_24 ( V_113 , 0 ) ) ;
F_25 ( V_2 , F_33 ( V_109 ) ) ;
F_25 ( V_2 , F_24 ( V_114 , 0 ) ) ;
F_25 ( V_2 , F_34 ( V_109 ) ) ;
F_25 ( V_2 , F_24 ( V_135 , 0 ) ) ;
F_25 ( V_2 , 0xffffffff ) ;
F_25 ( V_2 , F_24 ( V_138 , 0 ) ) ;
F_25 ( V_2 , V_110 ) ;
F_25 ( V_2 , F_24 ( V_115 , 0 ) ) ;
F_25 ( V_2 , 0xE ) ;
}
static bool F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_139 ) & V_140 ) ;
}
static int F_53 ( void * V_8 )
{
unsigned V_52 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_119 ; V_52 ++ ) {
if ( F_52 ( V_8 ) )
return 0 ;
}
return - V_141 ;
}
static bool F_54 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_142 = 0 ;
T_4 V_13 = F_2 ( V_139 ) ;
if ( F_55 ( V_13 , V_143 , V_144 ) ||
F_55 ( V_13 , V_143 , V_145 ) ||
( F_2 ( V_22 ) & V_146 ) )
V_142 = F_42 ( V_142 , V_69 , V_70 , 1 ) ;
if ( V_142 ) {
V_4 -> V_10 . V_142 = V_142 ;
return true ;
} else {
V_4 -> V_10 . V_142 = 0 ;
return false ;
}
}
static int F_56 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_10 . V_142 )
return 0 ;
F_29 ( V_4 ) ;
return 0 ;
}
static int F_57 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_142 ;
if ( ! V_4 -> V_10 . V_142 )
return 0 ;
V_142 = V_4 -> V_10 . V_142 ;
if ( V_142 ) {
T_4 V_13 ;
V_13 = F_2 ( V_147 ) ;
V_13 |= V_142 ;
F_58 ( V_4 -> V_148 , L_9 , V_13 ) ;
F_5 ( V_147 , V_13 ) ;
V_13 = F_2 ( V_147 ) ;
F_59 ( 50 ) ;
V_13 &= ~ V_142 ;
F_5 ( V_147 , V_13 ) ;
V_13 = F_2 ( V_147 ) ;
F_59 ( 50 ) ;
}
return 0 ;
}
static int F_60 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_10 . V_142 )
return 0 ;
F_39 ( 5 ) ;
return F_36 ( V_4 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_149 * V_150 ,
unsigned type ,
enum V_151 V_152 )
{
return 0 ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_149 * V_150 ,
struct V_153 * V_154 )
{
F_63 ( L_10 ) ;
F_64 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_3 * V_4 , bool V_155 )
{
T_1 V_156 , V_157 ;
V_156 = F_2 ( V_158 ) ;
V_157 = F_2 ( V_159 ) ;
V_156 |= V_160 |
V_161 |
V_162 |
V_163 |
V_164 |
V_165 |
V_166 |
V_167 |
V_168 |
V_169 |
V_170 |
V_171 |
V_172 ;
if ( V_155 ) {
V_157 |= ( V_173 |
V_174 |
V_175 |
V_176 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 ) ;
if ( V_4 -> V_193 & V_194 )
V_157 |= V_195 ;
V_157 &= ~ V_196 ;
} else {
V_157 = 0 ;
}
F_5 ( V_158 , V_156 ) ;
F_5 ( V_159 , V_157 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
T_1 V_197 , V_198 ;
V_197 = F_2 ( V_199 ) ;
V_198 = F_2 ( V_200 ) ;
V_197 &= ~ ( V_201 |
V_202 ) ;
V_197 |= V_203 |
( 1 << F_67 ( V_204 , V_205 ) ) |
( 4 << F_67 ( V_204 , V_206 ) ) ;
V_197 &= ~ ( V_207 |
V_208 |
V_209 |
V_210 |
V_211 |
V_212 |
V_213 |
V_214 |
V_215 |
V_216 |
V_217 |
V_218 |
V_219 |
V_220 |
V_221 |
V_222 |
V_223 |
V_224 |
V_225 |
V_226 |
V_227 |
V_228 ) ;
V_198 &= ~ ( V_229 |
V_230 |
V_231 |
V_232 |
V_233 ) ;
F_5 ( V_199 , V_197 ) ;
F_5 ( V_200 , V_198 ) ;
}
static void F_20 ( struct V_3 * V_4 ,
bool V_155 )
{
T_4 V_234 , V_197 ;
if ( V_155 && ( V_4 -> V_235 & V_236 ) ) {
V_197 = F_68 ( V_237 ) ;
V_197 |= 0xfff ;
F_69 ( V_237 , V_197 ) ;
V_234 = V_197 = F_2 ( V_199 ) ;
V_197 |= V_203 ;
if ( V_234 != V_197 )
F_5 ( V_199 , V_197 ) ;
} else {
V_197 = F_68 ( V_237 ) ;
V_197 &= ~ 0xfff ;
F_69 ( V_237 , V_197 ) ;
V_234 = V_197 = F_2 ( V_199 ) ;
V_197 &= ~ V_203 ;
if ( V_234 != V_197 )
F_5 ( V_199 , V_197 ) ;
}
}
static int F_19 ( void * V_8 ,
enum V_238 V_152 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_155 = ( V_152 == V_239 ) ? true : false ;
if ( V_155 ) {
if ( F_53 ( V_8 ) )
return - V_240 ;
F_65 ( V_4 , true ) ;
} else {
F_65 ( V_4 , false ) ;
}
F_66 ( V_4 ) ;
return 0 ;
}
static int F_70 ( void * V_8 ,
enum V_241 V_152 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_242 = 0 ;
F_5 ( V_54 , V_243 ) ;
if ( V_152 == V_244 ) {
F_29 ( V_4 ) ;
} else {
V_242 = F_36 ( V_4 ) ;
if ( V_242 )
goto V_245;
}
V_245:
return V_242 ;
}
static void F_71 ( void * V_8 , T_4 * V_23 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_197 ;
F_72 ( & V_4 -> V_246 . V_247 ) ;
if ( F_73 ( V_248 ) &
V_249 ) {
F_27 ( L_11 ) ;
goto V_245;
}
V_197 = F_2 ( V_199 ) ;
if ( V_197 & V_203 )
* V_23 |= V_236 ;
V_245:
F_74 ( & V_4 -> V_246 . V_247 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_250 >= V_251 ) {
V_4 -> V_10 . V_2 . V_252 = & V_253 ;
F_27 ( L_12 ) ;
} else {
V_4 -> V_10 . V_2 . V_252 = & V_254 ;
F_27 ( L_13 ) ;
}
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_255 = 1 ;
V_4 -> V_10 . V_11 . V_252 = & V_256 ;
}
