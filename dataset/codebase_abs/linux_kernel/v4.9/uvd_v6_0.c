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
V_9 = F_13 ( V_4 , V_2 , 512 , F_14 ( V_13 , 0 ) , 0xf ,
& V_4 -> V_10 . V_11 , 0 , V_14 ) ;
return V_9 ;
}
static int F_15 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_16 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_18 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_15 ;
int V_9 ;
V_9 = F_19 ( V_4 ) ;
if ( V_9 )
goto V_16;
V_2 -> V_17 = true ;
V_9 = F_20 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_17 = false ;
goto V_16;
}
V_9 = F_21 ( V_2 , 10 ) ;
if ( V_9 ) {
F_22 ( L_2 , V_9 ) ;
goto V_16;
}
V_15 = F_14 ( V_18 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_14 ( V_19 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_14 ( V_20 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
F_23 ( V_2 , F_14 ( V_21 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_14 ( V_22 , 0 ) ) ;
F_23 ( V_2 , 3 ) ;
F_24 ( V_2 ) ;
V_16:
if ( ! V_9 )
F_25 ( L_3 ) ;
return V_9 ;
}
static int F_26 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
F_27 ( V_4 ) ;
V_2 -> V_17 = false ;
return 0 ;
}
static int F_28 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_26 ( V_4 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_4 -> V_23 & V_24 ) ) {
V_9 = F_16 ( V_4 ) ;
if ( V_9 )
return V_9 ;
}
return V_9 ;
}
static int F_29 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_23 & V_24 ) ) {
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_18 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static void F_30 ( struct V_3 * V_4 )
{
T_2 V_25 ;
T_1 V_26 ;
F_5 ( V_27 ,
F_31 ( V_4 -> V_10 . V_28 ) ) ;
F_5 ( V_29 ,
F_32 ( V_4 -> V_10 . V_28 ) ) ;
V_25 = V_30 ;
V_26 = F_33 ( V_4 -> V_10 . V_31 -> V_26 + 4 ) ;
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
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_49 , V_15 ;
T_1 V_50 ;
T_1 V_51 ;
int V_52 , V_53 , V_9 ;
F_34 ( V_54 , 0 , ~ V_55 ) ;
V_50 = 0 ;
V_51 = 0 ;
F_30 ( V_4 ) ;
F_35 ( V_56 , V_57 , 0 ) ;
F_35 ( V_58 , V_59 , 0 ) ;
F_35 ( V_60 , V_61 , 1 ) ;
F_36 ( 1 ) ;
F_5 ( V_62 ,
V_63 |
V_64 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 ) ;
F_36 ( 5 ) ;
F_35 ( V_71 , V_72 , 0 ) ;
F_36 ( 5 ) ;
F_5 ( V_73 ,
( 0x40 << V_74 ) |
V_75 |
V_76 |
V_77 |
V_78 |
V_79 ) ;
#ifdef F_37
V_50 = 0xa ;
V_51 = 0 ;
#endif
F_5 ( V_80 , V_50 ) ;
F_5 ( V_81 , V_51 ) ;
F_5 ( V_82 , 0x40c2040 ) ;
F_5 ( V_83 , 0x0 ) ;
F_5 ( V_84 , 0x40c2040 ) ;
F_5 ( V_85 , 0x0 ) ;
F_5 ( V_86 , 0 ) ;
F_5 ( V_87 , 0x88 ) ;
F_5 ( V_62 , V_64 ) ;
F_36 ( 5 ) ;
F_5 ( V_88 , V_89 ) ;
F_35 ( V_60 , V_61 , 0 ) ;
F_5 ( V_62 , 0 ) ;
F_36 ( 10 ) ;
for ( V_52 = 0 ; V_52 < 10 ; ++ V_52 ) {
T_1 V_90 ;
for ( V_53 = 0 ; V_53 < 100 ; ++ V_53 ) {
V_90 = F_2 ( V_91 ) ;
if ( V_90 & 2 )
break;
F_36 ( 10 ) ;
}
V_9 = 0 ;
if ( V_90 & 2 )
break;
F_22 ( L_4 ) ;
F_35 ( V_92 , V_93 , 1 ) ;
F_36 ( 10 ) ;
F_35 ( V_92 , V_93 , 0 ) ;
F_36 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_22 ( L_5 ) ;
return V_9 ;
}
F_34 ( V_94 ,
( V_95 | V_96 ) ,
~ ( V_95 | V_96 ) ) ;
F_34 ( V_91 , 0 , ~ ( 2 << V_97 ) ) ;
V_49 = F_38 ( V_2 -> V_98 ) ;
V_15 = F_39 ( 0 , V_99 , V_100 , V_49 ) ;
V_15 = F_39 ( V_15 , V_99 , V_101 , 1 ) ;
V_15 = F_39 ( V_15 , V_99 , V_102 , 1 ) ;
V_15 = F_39 ( V_15 , V_99 , V_103 , 0 ) ;
V_15 = F_39 ( V_15 , V_99 , V_104 , 1 ) ;
V_15 = F_39 ( V_15 , V_99 , V_105 , 1 ) ;
F_5 ( V_106 , V_15 ) ;
F_5 ( V_107 , 0 ) ;
F_5 ( V_108 , ( F_32 ( V_2 -> V_28 ) >> 2 ) ) ;
F_5 ( V_109 ,
F_31 ( V_2 -> V_28 ) ) ;
F_5 ( V_110 ,
F_32 ( V_2 -> V_28 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_35 ( V_99 , V_102 , 0 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_5 ( V_106 , 0x11010101 ) ;
F_34 ( V_111 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_62 , V_64 ) ;
F_36 ( 5 ) ;
F_5 ( V_88 , 0x0 ) ;
F_34 ( V_111 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , T_3 V_112 , T_3 V_113 ,
unsigned V_23 )
{
F_41 ( V_23 & V_114 ) ;
F_23 ( V_2 , F_14 ( V_115 , 0 ) ) ;
F_23 ( V_2 , V_113 ) ;
F_23 ( V_2 , F_14 ( V_116 , 0 ) ) ;
F_23 ( V_2 , V_112 & 0xffffffff ) ;
F_23 ( V_2 , F_14 ( V_117 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_112 ) & 0xff ) ;
F_23 ( V_2 , F_14 ( V_118 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_14 ( V_116 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_14 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_14 ( V_118 , 0 ) ) ;
F_23 ( V_2 , 2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_23 ( V_2 , F_14 ( V_119 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_23 ( V_2 , F_14 ( V_120 , 0 ) ) ;
F_23 ( V_2 , 1 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_52 ;
int V_9 ;
F_5 ( V_115 , 0xCAFEDEAD ) ;
V_9 = F_21 ( V_2 , 3 ) ;
if ( V_9 ) {
F_22 ( L_6 ,
V_2 -> V_121 , V_9 ) ;
return V_9 ;
}
F_23 ( V_2 , F_14 ( V_115 , 0 ) ) ;
F_23 ( V_2 , 0xDEADBEEF ) ;
F_24 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_4 -> V_122 ; V_52 ++ ) {
V_15 = F_2 ( V_115 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_45 ( 1 ) ;
}
if ( V_52 < V_4 -> V_122 ) {
F_25 ( L_7 ,
V_2 -> V_121 , V_52 ) ;
} else {
F_22 ( L_8 ,
V_2 -> V_121 , V_15 ) ;
V_9 = - V_123 ;
}
return V_9 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
unsigned V_126 , bool V_127 )
{
F_23 ( V_2 , F_14 ( V_128 , 0 ) ) ;
F_23 ( V_2 , V_126 ) ;
F_23 ( V_2 , F_14 ( V_129 , 0 ) ) ;
F_23 ( V_2 , F_31 ( V_125 -> V_28 ) ) ;
F_23 ( V_2 , F_14 ( V_130 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_125 -> V_28 ) ) ;
F_23 ( V_2 , F_14 ( V_131 , 0 ) ) ;
F_23 ( V_2 , V_125 -> V_132 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
unsigned V_126 , T_2 V_133 )
{
T_1 V_134 ;
if ( V_126 < 8 )
V_134 = V_135 + V_126 ;
else
V_134 = V_136 + V_126 - 8 ;
F_23 ( V_2 , F_14 ( V_116 , 0 ) ) ;
F_23 ( V_2 , V_134 << 2 ) ;
F_23 ( V_2 , F_14 ( V_117 , 0 ) ) ;
F_23 ( V_2 , V_133 >> 12 ) ;
F_23 ( V_2 , F_14 ( V_118 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_14 ( V_116 , 0 ) ) ;
F_23 ( V_2 , V_137 << 2 ) ;
F_23 ( V_2 , F_14 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 1 << V_126 ) ;
F_23 ( V_2 , F_14 ( V_118 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_14 ( V_116 , 0 ) ) ;
F_23 ( V_2 , V_137 << 2 ) ;
F_23 ( V_2 , F_14 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_14 ( V_138 , 0 ) ) ;
F_23 ( V_2 , 1 << V_126 ) ;
F_23 ( V_2 , F_14 ( V_118 , 0 ) ) ;
F_23 ( V_2 , 0xC ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_1 V_113 = V_2 -> V_139 . V_140 ;
T_2 V_112 = V_2 -> V_139 . V_28 ;
F_23 ( V_2 , F_14 ( V_116 , 0 ) ) ;
F_23 ( V_2 , F_31 ( V_112 ) ) ;
F_23 ( V_2 , F_14 ( V_117 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_112 ) ) ;
F_23 ( V_2 , F_14 ( V_138 , 0 ) ) ;
F_23 ( V_2 , 0xffffffff ) ;
F_23 ( V_2 , F_14 ( V_141 , 0 ) ) ;
F_23 ( V_2 , V_113 ) ;
F_23 ( V_2 , F_14 ( V_118 , 0 ) ) ;
F_23 ( V_2 , 0xE ) ;
}
static unsigned F_49 ( struct V_1 * V_2 )
{
return
8 ;
}
static unsigned F_50 ( struct V_1 * V_2 )
{
return
2 +
2 +
10 +
14 ;
}
static unsigned F_51 ( struct V_1 * V_2 )
{
return
2 +
2 +
10 +
20 +
14 + 14 ;
}
static bool F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_142 ) & V_143 ) ;
}
static int F_53 ( void * V_8 )
{
unsigned V_52 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_122 ; V_52 ++ ) {
if ( F_52 ( V_8 ) )
return 0 ;
}
return - V_144 ;
}
static bool F_54 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_145 = 0 ;
T_4 V_15 = F_2 ( V_142 ) ;
if ( F_55 ( V_15 , V_146 , V_147 ) ||
F_55 ( V_15 , V_146 , V_148 ) ||
( F_2 ( V_91 ) & V_149 ) )
V_145 = F_39 ( V_145 , V_71 , V_72 , 1 ) ;
if ( V_145 ) {
V_4 -> V_10 . V_145 = V_145 ;
return true ;
} else {
V_4 -> V_10 . V_145 = 0 ;
return false ;
}
}
static int F_56 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_10 . V_145 )
return 0 ;
F_27 ( V_4 ) ;
return 0 ;
}
static int F_57 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
T_4 V_145 ;
if ( ! V_4 -> V_10 . V_145 )
return 0 ;
V_145 = V_4 -> V_10 . V_145 ;
if ( V_145 ) {
T_4 V_15 ;
V_15 = F_2 ( V_150 ) ;
V_15 |= V_145 ;
F_58 ( V_4 -> V_151 , L_9 , V_15 ) ;
F_5 ( V_150 , V_15 ) ;
V_15 = F_2 ( V_150 ) ;
F_59 ( 50 ) ;
V_15 &= ~ V_145 ;
F_5 ( V_150 , V_15 ) ;
V_15 = F_2 ( V_150 ) ;
F_59 ( 50 ) ;
}
return 0 ;
}
static int F_60 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! V_4 -> V_10 . V_145 )
return 0 ;
F_36 ( 5 ) ;
return F_19 ( V_4 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_152 * V_153 ,
unsigned type ,
enum V_154 V_155 )
{
return 0 ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_152 * V_153 ,
struct V_156 * V_157 )
{
F_63 ( L_10 ) ;
F_64 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_3 * V_4 )
{
T_1 V_158 , V_159 , V_160 , V_161 ;
V_158 = F_2 ( V_162 ) ;
V_159 = F_2 ( V_163 ) ;
V_160 = F_2 ( V_164 ) ;
V_158 &= ~ ( V_165 |
V_166 ) ;
V_161 = V_167 |
V_168 |
V_169 |
V_170 |
V_171 ;
V_158 |= V_172 |
( 1 << F_66 ( V_56 , V_173 ) ) |
( 4 << F_66 ( V_56 , V_174 ) ) ;
V_158 &= ~ ( V_175 |
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
V_193 |
V_194 |
V_195 |
V_196 ) ;
V_160 &= ~ ( V_197 |
V_198 |
V_199 |
V_200 |
V_201 ) ;
V_159 |= V_161 ;
F_5 ( V_162 , V_158 ) ;
F_5 ( V_202 , 0 ) ;
F_5 ( V_163 , V_159 ) ;
F_5 ( V_164 , V_160 ) ;
}
static void F_67 ( struct V_3 * V_4 , bool V_203 )
{
T_4 V_15 = F_68 ( V_204 ) ;
if ( V_203 )
V_15 |= ( V_205 |
V_206 ) ;
else
V_15 &= ~ ( V_205 |
V_206 ) ;
F_69 ( V_204 , V_15 ) ;
}
static int F_70 ( void * V_8 ,
enum V_207 V_155 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( V_4 -> V_208 == V_209 ||
V_4 -> V_208 == V_210 )
F_67 ( V_4 , V_155 == V_211 ? true : false ) ;
if ( ! ( V_4 -> V_212 & V_213 ) )
return 0 ;
if ( V_155 == V_211 ) {
F_65 ( V_4 ) ;
} else {
if ( F_53 ( V_8 ) )
return - V_214 ;
}
return 0 ;
}
static int F_71 ( void * V_8 ,
enum V_215 V_155 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_216 & V_217 ) )
return 0 ;
F_5 ( V_54 , V_218 ) ;
if ( V_155 == V_219 ) {
F_27 ( V_4 ) ;
return 0 ;
} else {
return F_19 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_208 >= V_210 ) {
V_4 -> V_10 . V_2 . V_220 = & V_221 ;
F_25 ( L_11 ) ;
} else {
V_4 -> V_10 . V_2 . V_220 = & V_222 ;
F_25 ( L_12 ) ;
}
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_223 = 1 ;
V_4 -> V_10 . V_11 . V_220 = & V_224 ;
}
