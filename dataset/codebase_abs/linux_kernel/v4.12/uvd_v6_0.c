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
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( void * V_8 )
{
struct V_1 * V_2 ;
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_11 ( V_4 , V_10 , 124 , & V_4 -> V_11 . V_12 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_13 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 = & V_4 -> V_11 . V_2 ;
sprintf ( V_2 -> V_13 , L_1 ) ;
V_9 = F_14 ( V_4 , V_2 , 512 , & V_4 -> V_11 . V_12 , 0 ) ;
return V_9 ;
}
static int F_15 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_16 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return F_17 ( V_4 ) ;
}
static int F_18 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_11 . V_2 ;
T_2 V_14 ;
int V_9 ;
F_19 ( V_4 , 10000 , 10000 ) ;
F_20 ( V_4 , V_15 ) ;
F_21 ( V_4 , true ) ;
V_2 -> V_16 = true ;
V_9 = F_22 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_16 = false ;
goto V_17;
}
V_9 = F_23 ( V_2 , 10 ) ;
if ( V_9 ) {
F_24 ( L_2 , V_9 ) ;
goto V_17;
}
V_14 = F_25 ( V_18 , 0 ) ;
F_26 ( V_2 , V_14 ) ;
F_26 ( V_2 , 0xFFFFF ) ;
V_14 = F_25 ( V_19 , 0 ) ;
F_26 ( V_2 , V_14 ) ;
F_26 ( V_2 , 0xFFFFF ) ;
V_14 = F_25 ( V_20 , 0 ) ;
F_26 ( V_2 , V_14 ) ;
F_26 ( V_2 , 0xFFFFF ) ;
F_26 ( V_2 , F_25 ( V_21 , 0 ) ) ;
F_26 ( V_2 , 0x8 ) ;
F_26 ( V_2 , F_25 ( V_22 , 0 ) ) ;
F_26 ( V_2 , 3 ) ;
F_27 ( V_2 ) ;
V_17:
if ( ! V_9 )
F_28 ( L_3 ) ;
return V_9 ;
}
static int F_29 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_11 . V_2 ;
if ( F_2 ( V_23 ) != 0 )
F_30 ( V_4 ) ;
V_2 -> V_16 = false ;
return 0 ;
}
static int F_31 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_29 ( V_4 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_4 -> V_24 & V_25 ) )
V_9 = F_16 ( V_4 ) ;
return V_9 ;
}
static int F_32 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_24 & V_25 ) ) {
V_9 = F_13 ( V_4 ) ;
if ( V_9 )
return V_9 ;
}
return F_18 ( V_4 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
T_1 V_26 ;
T_2 V_27 ;
F_5 ( V_28 ,
F_6 ( V_4 -> V_11 . V_29 ) ) ;
F_5 ( V_30 ,
F_34 ( V_4 -> V_11 . V_29 ) ) ;
V_26 = V_31 ;
V_27 = F_35 ( V_4 -> V_11 . V_32 -> V_27 + 4 ) ;
F_5 ( V_33 , V_26 >> 3 ) ;
F_5 ( V_34 , V_27 ) ;
V_26 += V_27 ;
V_27 = V_35 ;
F_5 ( V_36 , V_26 >> 3 ) ;
F_5 ( V_37 , V_27 ) ;
V_26 += V_27 ;
V_27 = V_38 +
( V_39 * V_4 -> V_11 . V_40 ) ;
F_5 ( V_41 , V_26 >> 3 ) ;
F_5 ( V_42 , V_27 ) ;
F_5 ( V_43 , V_4 -> V_44 . V_45 . V_46 ) ;
F_5 ( V_47 , V_4 -> V_44 . V_45 . V_46 ) ;
F_5 ( V_48 , V_4 -> V_44 . V_45 . V_46 ) ;
F_5 ( V_49 , V_4 -> V_11 . V_40 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_11 . V_2 ;
T_2 V_50 , V_14 ;
T_2 V_51 ;
T_2 V_52 ;
int V_53 , V_54 , V_9 ;
F_37 ( V_55 , 0 , ~ V_56 ) ;
V_51 = 0 ;
V_52 = 0 ;
F_33 ( V_4 ) ;
F_38 ( V_57 , V_58 , 0 ) ;
F_38 ( V_59 , V_60 , 1 ) ;
F_39 ( 1 ) ;
F_5 ( V_61 ,
V_62 |
V_63 |
V_64 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 ) ;
F_39 ( 5 ) ;
F_38 ( V_70 , V_71 , 0 ) ;
F_39 ( 5 ) ;
F_5 ( V_72 ,
( 0x40 << V_73 ) |
V_74 |
V_75 |
V_76 |
V_77 |
V_78 ) ;
#ifdef F_40
V_51 = 0xa ;
V_52 = 0 ;
#endif
F_5 ( V_79 , V_51 ) ;
F_5 ( V_80 , V_52 ) ;
F_5 ( V_81 , 0x40c2040 ) ;
F_5 ( V_82 , 0x0 ) ;
F_5 ( V_83 , 0x40c2040 ) ;
F_5 ( V_84 , 0x0 ) ;
F_5 ( V_85 , 0 ) ;
F_5 ( V_86 , 0x88 ) ;
F_5 ( V_61 , V_63 ) ;
F_39 ( 5 ) ;
F_5 ( V_87 , V_88 ) ;
F_38 ( V_59 , V_60 , 0 ) ;
F_5 ( V_61 , 0 ) ;
F_39 ( 10 ) ;
for ( V_53 = 0 ; V_53 < 10 ; ++ V_53 ) {
T_2 V_89 ;
for ( V_54 = 0 ; V_54 < 100 ; ++ V_54 ) {
V_89 = F_2 ( V_23 ) ;
if ( V_89 & 2 )
break;
F_39 ( 10 ) ;
}
V_9 = 0 ;
if ( V_89 & 2 )
break;
F_24 ( L_4 ) ;
F_38 ( V_90 , V_91 , 1 ) ;
F_39 ( 10 ) ;
F_38 ( V_90 , V_91 , 0 ) ;
F_39 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_24 ( L_5 ) ;
return V_9 ;
}
F_37 ( V_92 ,
( V_93 | V_94 ) ,
~ ( V_93 | V_94 ) ) ;
F_37 ( V_23 , 0 , ~ ( 2 << V_95 ) ) ;
V_50 = F_41 ( V_2 -> V_96 ) ;
V_14 = F_42 ( 0 , V_97 , V_98 , V_50 ) ;
V_14 = F_42 ( V_14 , V_97 , V_99 , 1 ) ;
V_14 = F_42 ( V_14 , V_97 , V_100 , 1 ) ;
V_14 = F_42 ( V_14 , V_97 , V_101 , 0 ) ;
V_14 = F_42 ( V_14 , V_97 , V_102 , 1 ) ;
V_14 = F_42 ( V_14 , V_97 , V_103 , 1 ) ;
F_5 ( V_104 , V_14 ) ;
F_5 ( V_105 , 0 ) ;
F_5 ( V_106 , ( F_34 ( V_2 -> V_29 ) >> 2 ) ) ;
F_5 ( V_107 ,
F_6 ( V_2 -> V_29 ) ) ;
F_5 ( V_108 ,
F_34 ( V_2 -> V_29 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , F_6 ( V_2 -> V_7 ) ) ;
F_38 ( V_97 , V_100 , 0 ) ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
F_5 ( V_104 , 0x11010101 ) ;
F_37 ( V_109 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_39 ( 1 ) ;
F_5 ( V_61 , V_63 ) ;
F_39 ( 5 ) ;
F_5 ( V_87 , 0x0 ) ;
F_37 ( V_109 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_23 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_3 V_110 , T_3 V_111 ,
unsigned V_24 )
{
F_44 ( V_24 & V_112 ) ;
F_26 ( V_2 , F_25 ( V_113 , 0 ) ) ;
F_26 ( V_2 , V_111 ) ;
F_26 ( V_2 , F_25 ( V_114 , 0 ) ) ;
F_26 ( V_2 , V_110 & 0xffffffff ) ;
F_26 ( V_2 , F_25 ( V_115 , 0 ) ) ;
F_26 ( V_2 , F_34 ( V_110 ) & 0xff ) ;
F_26 ( V_2 , F_25 ( V_116 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , F_25 ( V_114 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , F_25 ( V_115 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , F_25 ( V_116 , 0 ) ) ;
F_26 ( V_2 , 2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_26 ( V_2 , F_25 ( V_117 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_26 ( V_2 , F_25 ( V_118 , 0 ) ) ;
F_26 ( V_2 , 1 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_14 = 0 ;
unsigned V_53 ;
int V_9 ;
F_5 ( V_113 , 0xCAFEDEAD ) ;
V_9 = F_23 ( V_2 , 3 ) ;
if ( V_9 ) {
F_24 ( L_6 ,
V_2 -> V_119 , V_9 ) ;
return V_9 ;
}
F_26 ( V_2 , F_25 ( V_113 , 0 ) ) ;
F_26 ( V_2 , 0xDEADBEEF ) ;
F_27 ( V_2 ) ;
for ( V_53 = 0 ; V_53 < V_4 -> V_120 ; V_53 ++ ) {
V_14 = F_2 ( V_113 ) ;
if ( V_14 == 0xDEADBEEF )
break;
F_48 ( 1 ) ;
}
if ( V_53 < V_4 -> V_120 ) {
F_28 ( L_7 ,
V_2 -> V_119 , V_53 ) ;
} else {
F_24 ( L_8 ,
V_2 -> V_119 , V_14 ) ;
V_9 = - V_121 ;
}
return V_9 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_122 * V_123 ,
unsigned V_124 , bool V_125 )
{
F_26 ( V_2 , F_25 ( V_126 , 0 ) ) ;
F_26 ( V_2 , V_124 ) ;
F_26 ( V_2 , F_25 ( V_127 , 0 ) ) ;
F_26 ( V_2 , F_6 ( V_123 -> V_29 ) ) ;
F_26 ( V_2 , F_25 ( V_128 , 0 ) ) ;
F_26 ( V_2 , F_34 ( V_123 -> V_29 ) ) ;
F_26 ( V_2 , F_25 ( V_129 , 0 ) ) ;
F_26 ( V_2 , V_123 -> V_130 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned V_124 , T_1 V_131 )
{
T_2 V_132 ;
if ( V_124 < 8 )
V_132 = V_133 + V_124 ;
else
V_132 = V_134 + V_124 - 8 ;
F_26 ( V_2 , F_25 ( V_114 , 0 ) ) ;
F_26 ( V_2 , V_132 << 2 ) ;
F_26 ( V_2 , F_25 ( V_115 , 0 ) ) ;
F_26 ( V_2 , V_131 >> 12 ) ;
F_26 ( V_2 , F_25 ( V_116 , 0 ) ) ;
F_26 ( V_2 , 0x8 ) ;
F_26 ( V_2 , F_25 ( V_114 , 0 ) ) ;
F_26 ( V_2 , V_135 << 2 ) ;
F_26 ( V_2 , F_25 ( V_115 , 0 ) ) ;
F_26 ( V_2 , 1 << V_124 ) ;
F_26 ( V_2 , F_25 ( V_116 , 0 ) ) ;
F_26 ( V_2 , 0x8 ) ;
F_26 ( V_2 , F_25 ( V_114 , 0 ) ) ;
F_26 ( V_2 , V_135 << 2 ) ;
F_26 ( V_2 , F_25 ( V_115 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , F_25 ( V_136 , 0 ) ) ;
F_26 ( V_2 , 1 << V_124 ) ;
F_26 ( V_2 , F_25 ( V_116 , 0 ) ) ;
F_26 ( V_2 , 0xC ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_2 V_111 = V_2 -> V_137 . V_138 ;
T_1 V_110 = V_2 -> V_137 . V_29 ;
F_26 ( V_2 , F_25 ( V_114 , 0 ) ) ;
F_26 ( V_2 , F_6 ( V_110 ) ) ;
F_26 ( V_2 , F_25 ( V_115 , 0 ) ) ;
F_26 ( V_2 , F_34 ( V_110 ) ) ;
F_26 ( V_2 , F_25 ( V_136 , 0 ) ) ;
F_26 ( V_2 , 0xffffffff ) ;
F_26 ( V_2 , F_25 ( V_139 , 0 ) ) ;
F_26 ( V_2 , V_111 ) ;
F_26 ( V_2 , F_25 ( V_116 , 0 ) ) ;
F_26 ( V_2 , 0xE ) ;
}
static bool F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_140 ) & V_141 ) ;
}
static int F_53 ( void * V_8 )
{
unsigned V_53 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_120 ; V_53 ++ ) {
if ( F_52 ( V_8 ) )
return 0 ;
}
return - V_142 ;
}
static bool F_54 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_143 = 0 ;
T_4 V_14 = F_2 ( V_140 ) ;
if ( F_55 ( V_14 , V_144 , V_145 ) ||
F_55 ( V_14 , V_144 , V_146 ) ||
( F_2 ( V_23 ) & V_147 ) )
V_143 = F_42 ( V_143 , V_70 , V_71 , 1 ) ;
if ( V_143 ) {
V_4 -> V_11 . V_143 = V_143 ;
return true ;
} else {
V_4 -> V_11 . V_143 = 0 ;
return false ;
}
}
static int F_56 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_11 . V_143 )
return 0 ;
F_30 ( V_4 ) ;
return 0 ;
}
static int F_57 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_143 ;
if ( ! V_4 -> V_11 . V_143 )
return 0 ;
V_143 = V_4 -> V_11 . V_143 ;
if ( V_143 ) {
T_4 V_14 ;
V_14 = F_2 ( V_148 ) ;
V_14 |= V_143 ;
F_58 ( V_4 -> V_149 , L_9 , V_14 ) ;
F_5 ( V_148 , V_14 ) ;
V_14 = F_2 ( V_148 ) ;
F_59 ( 50 ) ;
V_14 &= ~ V_143 ;
F_5 ( V_148 , V_14 ) ;
V_14 = F_2 ( V_148 ) ;
F_59 ( 50 ) ;
}
return 0 ;
}
static int F_60 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_11 . V_143 )
return 0 ;
F_39 ( 5 ) ;
return F_36 ( V_4 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_150 * V_151 ,
unsigned type ,
enum V_152 V_153 )
{
return 0 ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_150 * V_151 ,
struct V_154 * V_155 )
{
F_63 ( L_10 ) ;
F_64 ( & V_4 -> V_11 . V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_3 * V_4 , bool V_156 )
{
T_2 V_157 , V_158 ;
V_157 = F_2 ( V_159 ) ;
V_158 = F_2 ( V_160 ) ;
V_157 |= V_161 |
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
V_172 |
V_173 ;
if ( V_156 ) {
V_158 |= ( V_174 |
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
V_192 |
V_193 ) ;
if ( V_4 -> V_194 & V_195 )
V_158 |= V_196 ;
V_158 &= ~ V_197 ;
} else {
V_158 = 0 ;
}
F_5 ( V_159 , V_157 ) ;
F_5 ( V_160 , V_158 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
T_2 V_198 , V_199 ;
V_198 = F_2 ( V_200 ) ;
V_199 = F_2 ( V_201 ) ;
V_198 &= ~ ( V_202 |
V_203 ) ;
V_198 |= V_204 |
( 1 << F_67 ( V_205 , V_206 ) ) |
( 4 << F_67 ( V_205 , V_207 ) ) ;
V_198 &= ~ ( V_208 |
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
V_228 |
V_229 ) ;
V_199 &= ~ ( V_230 |
V_231 |
V_232 |
V_233 |
V_234 ) ;
F_5 ( V_200 , V_198 ) ;
F_5 ( V_201 , V_199 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
bool V_156 )
{
T_4 V_235 , V_198 ;
if ( V_156 && ( V_4 -> V_236 & V_237 ) ) {
V_198 = F_68 ( V_238 ) ;
V_198 |= 0xfff ;
F_69 ( V_238 , V_198 ) ;
V_235 = V_198 = F_2 ( V_200 ) ;
V_198 |= V_204 ;
if ( V_235 != V_198 )
F_5 ( V_200 , V_198 ) ;
} else {
V_198 = F_68 ( V_238 ) ;
V_198 &= ~ 0xfff ;
F_69 ( V_238 , V_198 ) ;
V_235 = V_198 = F_2 ( V_200 ) ;
V_198 &= ~ V_204 ;
if ( V_235 != V_198 )
F_5 ( V_200 , V_198 ) ;
}
}
static int F_20 ( void * V_8 ,
enum V_239 V_153 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_156 = ( V_153 == V_240 ) ? true : false ;
if ( V_156 ) {
if ( F_53 ( V_8 ) )
return - V_241 ;
F_65 ( V_4 , true ) ;
} else {
F_65 ( V_4 , false ) ;
}
F_66 ( V_4 ) ;
return 0 ;
}
static int F_70 ( void * V_8 ,
enum V_242 V_153 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_243 = 0 ;
F_5 ( V_55 , V_244 ) ;
if ( V_153 == V_245 ) {
F_30 ( V_4 ) ;
} else {
V_243 = F_36 ( V_4 ) ;
if ( V_243 )
goto V_246;
}
V_246:
return V_243 ;
}
static void F_71 ( void * V_8 , T_4 * V_24 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_198 ;
F_72 ( & V_4 -> V_247 . V_248 ) ;
if ( V_4 -> V_24 & V_25 )
V_198 = F_73 ( V_249 ) ;
else
V_198 = F_73 ( V_250 ) ;
if ( V_198 & V_251 ) {
F_28 ( L_11 ) ;
goto V_246;
}
V_198 = F_2 ( V_200 ) ;
if ( V_198 & V_204 )
* V_24 |= V_237 ;
V_246:
F_74 ( & V_4 -> V_247 . V_248 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
if ( V_4 -> V_252 >= V_253 ) {
V_4 -> V_11 . V_2 . V_254 = & V_255 ;
F_28 ( L_12 ) ;
} else {
V_4 -> V_11 . V_2 . V_254 = & V_256 ;
F_28 ( L_13 ) ;
}
}
static void F_9 ( struct V_3 * V_4 )
{
V_4 -> V_11 . V_12 . V_257 = 1 ;
V_4 -> V_11 . V_12 . V_254 = & V_258 ;
}
