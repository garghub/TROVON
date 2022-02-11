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
F_5 ( V_6 , F_6 ( V_2 -> V_7 ) ) ;
}
static int F_7 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_9 & V_10 ) &&
( F_8 ( V_11 ) & V_12 ) )
return - V_13 ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_11 ( void * V_8 )
{
struct V_1 * V_2 ;
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_14 = F_12 ( V_4 , V_15 , 124 , & V_4 -> V_16 . V_17 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_13 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_14 ( V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 = & V_4 -> V_16 . V_2 ;
sprintf ( V_2 -> V_18 , L_1 ) ;
V_14 = F_15 ( V_4 , V_2 , 512 , & V_4 -> V_16 . V_17 , 0 ) ;
return V_14 ;
}
static int F_16 ( void * V_8 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_14 = F_17 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return F_18 ( V_4 ) ;
}
static int F_19 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_16 . V_2 ;
T_2 V_19 ;
int V_14 ;
F_20 ( V_4 , 10000 , 10000 ) ;
F_21 ( V_4 , V_20 ) ;
F_22 ( V_4 , true ) ;
V_2 -> V_21 = true ;
V_14 = F_23 ( V_2 ) ;
if ( V_14 ) {
V_2 -> V_21 = false ;
goto V_22;
}
V_14 = F_24 ( V_2 , 10 ) ;
if ( V_14 ) {
F_25 ( L_2 , V_14 ) ;
goto V_22;
}
V_19 = F_26 ( V_23 , 0 ) ;
F_27 ( V_2 , V_19 ) ;
F_27 ( V_2 , 0xFFFFF ) ;
V_19 = F_26 ( V_24 , 0 ) ;
F_27 ( V_2 , V_19 ) ;
F_27 ( V_2 , 0xFFFFF ) ;
V_19 = F_26 ( V_25 , 0 ) ;
F_27 ( V_2 , V_19 ) ;
F_27 ( V_2 , 0xFFFFF ) ;
F_27 ( V_2 , F_26 ( V_26 , 0 ) ) ;
F_27 ( V_2 , 0x8 ) ;
F_27 ( V_2 , F_26 ( V_27 , 0 ) ) ;
F_27 ( V_2 , 3 ) ;
F_28 ( V_2 ) ;
V_22:
if ( ! V_14 )
F_29 ( L_3 ) ;
return V_14 ;
}
static int F_30 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_16 . V_2 ;
if ( F_2 ( V_28 ) != 0 )
F_31 ( V_4 ) ;
V_2 -> V_21 = false ;
return 0 ;
}
static int F_32 ( void * V_8 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_14 = F_30 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return F_17 ( V_4 ) ;
}
static int F_33 ( void * V_8 )
{
int V_14 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_14 = F_14 ( V_4 ) ;
if ( V_14 )
return V_14 ;
return F_19 ( V_4 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
T_1 V_29 ;
T_2 V_30 ;
F_5 ( V_31 ,
F_6 ( V_4 -> V_16 . V_32 ) ) ;
F_5 ( V_33 ,
F_35 ( V_4 -> V_16 . V_32 ) ) ;
V_29 = V_34 ;
V_30 = F_36 ( V_4 -> V_16 . V_35 -> V_30 + 4 ) ;
F_5 ( V_36 , V_29 >> 3 ) ;
F_5 ( V_37 , V_30 ) ;
V_29 += V_30 ;
V_30 = V_38 ;
F_5 ( V_39 , V_29 >> 3 ) ;
F_5 ( V_40 , V_30 ) ;
V_29 += V_30 ;
V_30 = V_41 +
( V_42 * V_4 -> V_16 . V_43 ) ;
F_5 ( V_44 , V_29 >> 3 ) ;
F_5 ( V_45 , V_30 ) ;
F_5 ( V_46 , V_4 -> V_47 . V_48 . V_49 ) ;
F_5 ( V_50 , V_4 -> V_47 . V_48 . V_49 ) ;
F_5 ( V_51 , V_4 -> V_47 . V_48 . V_49 ) ;
F_5 ( V_52 , V_4 -> V_16 . V_43 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_16 . V_2 ;
T_2 V_53 , V_19 ;
T_2 V_54 ;
T_2 V_55 ;
int V_56 , V_57 , V_14 ;
F_38 ( V_58 , 0 , ~ V_59 ) ;
V_54 = 0 ;
V_55 = 0 ;
F_34 ( V_4 ) ;
F_39 ( V_60 , V_61 , 0 ) ;
F_39 ( V_62 , V_63 , 1 ) ;
F_40 ( 1 ) ;
F_5 ( V_64 ,
V_65 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 |
V_71 |
V_72 ) ;
F_40 ( 5 ) ;
F_39 ( V_73 , V_74 , 0 ) ;
F_40 ( 5 ) ;
F_5 ( V_75 ,
( 0x40 << V_76 ) |
V_77 |
V_78 |
V_79 |
V_80 |
V_81 ) ;
#ifdef F_41
V_54 = 0xa ;
V_55 = 0 ;
#endif
F_5 ( V_82 , V_54 ) ;
F_5 ( V_83 , V_55 ) ;
F_5 ( V_84 , 0x40c2040 ) ;
F_5 ( V_85 , 0x0 ) ;
F_5 ( V_86 , 0x40c2040 ) ;
F_5 ( V_87 , 0x0 ) ;
F_5 ( V_88 , 0 ) ;
F_5 ( V_89 , 0x88 ) ;
F_5 ( V_64 , V_66 ) ;
F_40 ( 5 ) ;
F_5 ( V_90 , V_91 ) ;
F_39 ( V_62 , V_63 , 0 ) ;
F_5 ( V_64 , 0 ) ;
F_40 ( 10 ) ;
for ( V_56 = 0 ; V_56 < 10 ; ++ V_56 ) {
T_2 V_92 ;
for ( V_57 = 0 ; V_57 < 100 ; ++ V_57 ) {
V_92 = F_2 ( V_28 ) ;
if ( V_92 & 2 )
break;
F_40 ( 10 ) ;
}
V_14 = 0 ;
if ( V_92 & 2 )
break;
F_25 ( L_4 ) ;
F_39 ( V_93 , V_94 , 1 ) ;
F_40 ( 10 ) ;
F_39 ( V_93 , V_94 , 0 ) ;
F_40 ( 10 ) ;
V_14 = - 1 ;
}
if ( V_14 ) {
F_25 ( L_5 ) ;
return V_14 ;
}
F_38 ( V_95 ,
( V_96 | V_97 ) ,
~ ( V_96 | V_97 ) ) ;
F_38 ( V_28 , 0 , ~ ( 2 << V_98 ) ) ;
V_53 = F_42 ( V_2 -> V_99 ) ;
V_19 = F_43 ( 0 , V_100 , V_101 , V_53 ) ;
V_19 = F_43 ( V_19 , V_100 , V_102 , 1 ) ;
V_19 = F_43 ( V_19 , V_100 , V_103 , 1 ) ;
V_19 = F_43 ( V_19 , V_100 , V_104 , 0 ) ;
V_19 = F_43 ( V_19 , V_100 , V_105 , 1 ) ;
V_19 = F_43 ( V_19 , V_100 , V_106 , 1 ) ;
F_5 ( V_107 , V_19 ) ;
F_5 ( V_108 , 0 ) ;
F_5 ( V_109 , ( F_35 ( V_2 -> V_32 ) >> 2 ) ) ;
F_5 ( V_110 ,
F_6 ( V_2 -> V_32 ) ) ;
F_5 ( V_111 ,
F_35 ( V_2 -> V_32 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , F_6 ( V_2 -> V_7 ) ) ;
F_39 ( V_100 , V_103 , 0 ) ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_5 ( V_107 , 0x11010101 ) ;
F_38 ( V_112 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_40 ( 1 ) ;
F_5 ( V_64 , V_66 ) ;
F_40 ( 5 ) ;
F_5 ( V_90 , 0x0 ) ;
F_38 ( V_112 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_28 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_3 V_113 , T_3 V_114 ,
unsigned V_9 )
{
F_45 ( V_9 & V_115 ) ;
F_27 ( V_2 , F_26 ( V_116 , 0 ) ) ;
F_27 ( V_2 , V_114 ) ;
F_27 ( V_2 , F_26 ( V_117 , 0 ) ) ;
F_27 ( V_2 , V_113 & 0xffffffff ) ;
F_27 ( V_2 , F_26 ( V_118 , 0 ) ) ;
F_27 ( V_2 , F_35 ( V_113 ) & 0xff ) ;
F_27 ( V_2 , F_26 ( V_119 , 0 ) ) ;
F_27 ( V_2 , 0 ) ;
F_27 ( V_2 , F_26 ( V_117 , 0 ) ) ;
F_27 ( V_2 , 0 ) ;
F_27 ( V_2 , F_26 ( V_118 , 0 ) ) ;
F_27 ( V_2 , 0 ) ;
F_27 ( V_2 , F_26 ( V_119 , 0 ) ) ;
F_27 ( V_2 , 2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_27 ( V_2 , F_26 ( V_120 , 0 ) ) ;
F_27 ( V_2 , 0 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_27 ( V_2 , F_26 ( V_121 , 0 ) ) ;
F_27 ( V_2 , 1 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_19 = 0 ;
unsigned V_56 ;
int V_14 ;
F_5 ( V_116 , 0xCAFEDEAD ) ;
V_14 = F_24 ( V_2 , 3 ) ;
if ( V_14 ) {
F_25 ( L_6 ,
V_2 -> V_122 , V_14 ) ;
return V_14 ;
}
F_27 ( V_2 , F_26 ( V_116 , 0 ) ) ;
F_27 ( V_2 , 0xDEADBEEF ) ;
F_28 ( V_2 ) ;
for ( V_56 = 0 ; V_56 < V_4 -> V_123 ; V_56 ++ ) {
V_19 = F_2 ( V_116 ) ;
if ( V_19 == 0xDEADBEEF )
break;
F_49 ( 1 ) ;
}
if ( V_56 < V_4 -> V_123 ) {
F_29 ( L_7 ,
V_2 -> V_122 , V_56 ) ;
} else {
F_25 ( L_8 ,
V_2 -> V_122 , V_19 ) ;
V_14 = - V_124 ;
}
return V_14 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_125 * V_126 ,
unsigned V_127 , bool V_128 )
{
F_27 ( V_2 , F_26 ( V_129 , 0 ) ) ;
F_27 ( V_2 , V_127 ) ;
F_27 ( V_2 , F_26 ( V_130 , 0 ) ) ;
F_27 ( V_2 , F_6 ( V_126 -> V_32 ) ) ;
F_27 ( V_2 , F_26 ( V_131 , 0 ) ) ;
F_27 ( V_2 , F_35 ( V_126 -> V_32 ) ) ;
F_27 ( V_2 , F_26 ( V_132 , 0 ) ) ;
F_27 ( V_2 , V_126 -> V_133 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
unsigned V_127 , T_1 V_134 )
{
T_2 V_135 ;
if ( V_127 < 8 )
V_135 = V_136 + V_127 ;
else
V_135 = V_137 + V_127 - 8 ;
F_27 ( V_2 , F_26 ( V_117 , 0 ) ) ;
F_27 ( V_2 , V_135 << 2 ) ;
F_27 ( V_2 , F_26 ( V_118 , 0 ) ) ;
F_27 ( V_2 , V_134 >> 12 ) ;
F_27 ( V_2 , F_26 ( V_119 , 0 ) ) ;
F_27 ( V_2 , 0x8 ) ;
F_27 ( V_2 , F_26 ( V_117 , 0 ) ) ;
F_27 ( V_2 , V_138 << 2 ) ;
F_27 ( V_2 , F_26 ( V_118 , 0 ) ) ;
F_27 ( V_2 , 1 << V_127 ) ;
F_27 ( V_2 , F_26 ( V_119 , 0 ) ) ;
F_27 ( V_2 , 0x8 ) ;
F_27 ( V_2 , F_26 ( V_117 , 0 ) ) ;
F_27 ( V_2 , V_138 << 2 ) ;
F_27 ( V_2 , F_26 ( V_118 , 0 ) ) ;
F_27 ( V_2 , 0 ) ;
F_27 ( V_2 , F_26 ( V_139 , 0 ) ) ;
F_27 ( V_2 , 1 << V_127 ) ;
F_27 ( V_2 , F_26 ( V_119 , 0 ) ) ;
F_27 ( V_2 , 0xC ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_2 V_114 = V_2 -> V_140 . V_141 ;
T_1 V_113 = V_2 -> V_140 . V_32 ;
F_27 ( V_2 , F_26 ( V_117 , 0 ) ) ;
F_27 ( V_2 , F_6 ( V_113 ) ) ;
F_27 ( V_2 , F_26 ( V_118 , 0 ) ) ;
F_27 ( V_2 , F_35 ( V_113 ) ) ;
F_27 ( V_2 , F_26 ( V_139 , 0 ) ) ;
F_27 ( V_2 , 0xffffffff ) ;
F_27 ( V_2 , F_26 ( V_142 , 0 ) ) ;
F_27 ( V_2 , V_114 ) ;
F_27 ( V_2 , F_26 ( V_119 , 0 ) ) ;
F_27 ( V_2 , 0xE ) ;
}
static bool F_53 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_143 ) & V_144 ) ;
}
static int F_54 ( void * V_8 )
{
unsigned V_56 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_123 ; V_56 ++ ) {
if ( F_53 ( V_8 ) )
return 0 ;
}
return - V_145 ;
}
static bool F_55 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_146 = 0 ;
T_4 V_19 = F_2 ( V_143 ) ;
if ( F_56 ( V_19 , V_147 , V_148 ) ||
F_56 ( V_19 , V_147 , V_149 ) ||
( F_2 ( V_28 ) & V_150 ) )
V_146 = F_43 ( V_146 , V_73 , V_74 , 1 ) ;
if ( V_146 ) {
V_4 -> V_16 . V_146 = V_146 ;
return true ;
} else {
V_4 -> V_16 . V_146 = 0 ;
return false ;
}
}
static int F_57 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_16 . V_146 )
return 0 ;
F_31 ( V_4 ) ;
return 0 ;
}
static int F_58 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_146 ;
if ( ! V_4 -> V_16 . V_146 )
return 0 ;
V_146 = V_4 -> V_16 . V_146 ;
if ( V_146 ) {
T_4 V_19 ;
V_19 = F_2 ( V_151 ) ;
V_19 |= V_146 ;
F_59 ( V_4 -> V_152 , L_9 , V_19 ) ;
F_5 ( V_151 , V_19 ) ;
V_19 = F_2 ( V_151 ) ;
F_60 ( 50 ) ;
V_19 &= ~ V_146 ;
F_5 ( V_151 , V_19 ) ;
V_19 = F_2 ( V_151 ) ;
F_60 ( 50 ) ;
}
return 0 ;
}
static int F_61 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_16 . V_146 )
return 0 ;
F_40 ( 5 ) ;
return F_37 ( V_4 ) ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_153 * V_154 ,
unsigned type ,
enum V_155 V_156 )
{
return 0 ;
}
static int F_63 ( struct V_3 * V_4 ,
struct V_153 * V_154 ,
struct V_157 * V_158 )
{
F_64 ( L_10 ) ;
F_65 ( & V_4 -> V_16 . V_2 ) ;
return 0 ;
}
static void F_66 ( struct V_3 * V_4 , bool V_159 )
{
T_2 V_160 , V_161 ;
V_160 = F_2 ( V_162 ) ;
V_161 = F_2 ( V_163 ) ;
V_160 |= V_164 |
V_165 |
V_166 |
V_167 |
V_168 |
V_169 |
V_170 |
V_171 |
V_172 |
V_173 |
V_174 |
V_175 |
V_176 ;
if ( V_159 ) {
V_161 |= ( V_177 |
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
V_192 |
V_193 |
V_194 |
V_195 |
V_196 ) ;
if ( V_4 -> V_197 & V_198 )
V_161 |= V_199 ;
V_161 &= ~ V_200 ;
} else {
V_161 = 0 ;
}
F_5 ( V_162 , V_160 ) ;
F_5 ( V_163 , V_161 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
T_2 V_201 , V_202 ;
V_201 = F_2 ( V_203 ) ;
V_202 = F_2 ( V_204 ) ;
V_201 &= ~ ( V_205 |
V_206 ) ;
V_201 |= V_207 |
( 1 << F_68 ( V_208 , V_209 ) ) |
( 4 << F_68 ( V_208 , V_210 ) ) ;
V_201 &= ~ ( V_211 |
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
V_228 |
V_229 |
V_230 |
V_231 |
V_232 ) ;
V_202 &= ~ ( V_233 |
V_234 |
V_235 |
V_236 |
V_237 ) ;
F_5 ( V_203 , V_201 ) ;
F_5 ( V_204 , V_202 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
bool V_159 )
{
T_4 V_238 , V_201 ;
if ( V_159 && ( V_4 -> V_239 & V_240 ) ) {
V_201 = F_69 ( V_241 ) ;
V_201 |= 0xfff ;
F_70 ( V_241 , V_201 ) ;
V_238 = V_201 = F_2 ( V_203 ) ;
V_201 |= V_207 ;
if ( V_238 != V_201 )
F_5 ( V_203 , V_201 ) ;
} else {
V_201 = F_69 ( V_241 ) ;
V_201 &= ~ 0xfff ;
F_70 ( V_241 , V_201 ) ;
V_238 = V_201 = F_2 ( V_203 ) ;
V_201 &= ~ V_207 ;
if ( V_238 != V_201 )
F_5 ( V_203 , V_201 ) ;
}
}
static int F_21 ( void * V_8 ,
enum V_242 V_156 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_159 = ( V_156 == V_243 ) ? true : false ;
if ( V_159 ) {
if ( F_54 ( V_8 ) )
return - V_244 ;
F_66 ( V_4 , true ) ;
} else {
F_66 ( V_4 , false ) ;
}
F_67 ( V_4 ) ;
return 0 ;
}
static int F_71 ( void * V_8 ,
enum V_245 V_156 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_246 = 0 ;
F_5 ( V_58 , V_247 ) ;
if ( V_156 == V_248 ) {
F_31 ( V_4 ) ;
} else {
V_246 = F_37 ( V_4 ) ;
if ( V_246 )
goto V_249;
}
V_249:
return V_246 ;
}
static void F_72 ( void * V_8 , T_4 * V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_201 ;
F_73 ( & V_4 -> V_250 . V_251 ) ;
if ( V_4 -> V_9 & V_10 )
V_201 = F_8 ( V_252 ) ;
else
V_201 = F_8 ( V_253 ) ;
if ( V_201 & V_254 ) {
F_29 ( L_11 ) ;
goto V_249;
}
V_201 = F_2 ( V_203 ) ;
if ( V_201 & V_207 )
* V_9 |= V_240 ;
V_249:
F_74 ( & V_4 -> V_250 . V_251 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
if ( V_4 -> V_255 >= V_256 ) {
V_4 -> V_16 . V_2 . V_257 = & V_258 ;
F_29 ( L_12 ) ;
} else {
V_4 -> V_16 . V_2 . V_257 = & V_259 ;
F_29 ( L_13 ) ;
}
}
static void F_10 ( struct V_3 * V_4 )
{
V_4 -> V_16 . V_17 . V_260 = 1 ;
V_4 -> V_16 . V_17 . V_257 = & V_261 ;
}
