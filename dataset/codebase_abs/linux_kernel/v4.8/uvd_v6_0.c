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
V_9 = F_13 ( V_4 , V_2 , 512 , V_13 , 0xf ,
& V_4 -> V_10 . V_11 , 0 , V_14 ) ;
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
T_1 V_15 ;
int V_9 ;
V_9 = F_18 ( V_4 ) ;
if ( V_9 )
goto V_16;
V_2 -> V_17 = true ;
V_9 = F_19 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_17 = false ;
goto V_16;
}
V_9 = F_20 ( V_2 , 10 ) ;
if ( V_9 ) {
F_21 ( L_2 , V_9 ) ;
goto V_16;
}
V_15 = F_22 ( V_18 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_22 ( V_19 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_22 ( V_20 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
F_23 ( V_2 , F_22 ( V_21 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_22 ( V_22 , 0 ) ) ;
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
V_9 = F_15 ( V_4 ) ;
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
V_9 = F_17 ( V_4 ) ;
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
static int F_18 ( struct V_3 * V_4 )
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
if ( V_4 -> V_56 & V_57 ) {
F_35 ( V_4 ) ;
} else {
T_1 V_58 = F_2 ( V_59 ) ;
V_58 &= ~ V_60 ;
F_5 ( V_59 , V_58 ) ;
}
F_34 ( V_61 , 0 , ~ V_62 ) ;
F_34 ( V_63 , V_64 , ~ V_64 ) ;
F_36 ( 1 ) ;
F_5 ( V_65 ,
V_66 |
V_67 |
V_68 |
V_69 |
V_70 |
V_71 |
V_72 |
V_73 ) ;
F_36 ( 5 ) ;
F_34 ( V_74 , 0 , ~ V_75 ) ;
F_36 ( 5 ) ;
F_5 ( V_76 ,
( 0x40 << V_77 ) |
V_78 |
V_79 |
V_80 |
V_81 |
V_82 ) ;
#ifdef F_37
V_50 = 0xa ;
V_51 = 0 ;
#endif
F_5 ( V_83 , V_50 ) ;
F_5 ( V_84 , V_51 ) ;
F_5 ( V_85 , 0x40c2040 ) ;
F_5 ( V_86 , 0x0 ) ;
F_5 ( V_87 , 0x40c2040 ) ;
F_5 ( V_88 , 0x0 ) ;
F_5 ( V_89 , 0 ) ;
F_5 ( V_90 , 0x88 ) ;
F_5 ( V_65 , V_67 ) ;
F_36 ( 5 ) ;
F_5 ( V_91 , V_92 ) ;
F_34 ( V_63 , 0 , ~ V_64 ) ;
F_5 ( V_65 , 0 ) ;
F_36 ( 10 ) ;
for ( V_52 = 0 ; V_52 < 10 ; ++ V_52 ) {
T_1 V_93 ;
for ( V_53 = 0 ; V_53 < 100 ; ++ V_53 ) {
V_93 = F_2 ( V_94 ) ;
if ( V_93 & 2 )
break;
F_36 ( 10 ) ;
}
V_9 = 0 ;
if ( V_93 & 2 )
break;
F_21 ( L_4 ) ;
F_34 ( V_65 , V_67 ,
~ V_67 ) ;
F_36 ( 10 ) ;
F_34 ( V_65 , 0 ,
~ V_67 ) ;
F_36 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_21 ( L_5 ) ;
return V_9 ;
}
F_34 ( V_61 ,
( V_62 | V_95 ) ,
~ ( V_62 | V_95 ) ) ;
F_34 ( V_94 , 0 , ~ ( 2 << V_96 ) ) ;
V_49 = F_38 ( V_2 -> V_97 ) ;
V_15 = 0 ;
V_15 = F_39 ( V_15 , V_98 , V_99 , V_49 ) ;
V_15 = F_39 ( V_15 , V_98 , V_100 , 1 ) ;
V_15 = F_39 ( V_15 , V_98 , V_101 , 1 ) ;
V_15 = F_39 ( V_15 , V_98 , V_102 , 0 ) ;
V_15 = F_39 ( V_15 , V_98 , V_103 , 1 ) ;
V_15 = F_39 ( V_15 , V_98 , V_104 , 1 ) ;
F_5 ( V_105 , V_15 ) ;
F_5 ( V_106 , 0 ) ;
F_5 ( V_107 , ( F_32 ( V_2 -> V_28 ) >> 2 ) ) ;
F_5 ( V_108 ,
F_31 ( V_2 -> V_28 ) ) ;
F_5 ( V_109 ,
F_32 ( V_2 -> V_28 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_34 ( V_105 , 0 , ~ V_110 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_5 ( V_105 , 0x11010101 ) ;
F_34 ( V_63 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_65 , V_67 ) ;
F_36 ( 5 ) ;
F_5 ( V_91 , 0x0 ) ;
F_34 ( V_63 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , T_3 V_111 , T_3 V_112 ,
unsigned V_23 )
{
F_41 ( V_23 & V_113 ) ;
F_23 ( V_2 , F_22 ( V_114 , 0 ) ) ;
F_23 ( V_2 , V_112 ) ;
F_23 ( V_2 , F_22 ( V_115 , 0 ) ) ;
F_23 ( V_2 , V_111 & 0xffffffff ) ;
F_23 ( V_2 , F_22 ( V_116 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_111 ) & 0xff ) ;
F_23 ( V_2 , F_22 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_115 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_116 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_23 ( V_2 , F_22 ( V_118 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_23 ( V_2 , F_22 ( V_119 , 0 ) ) ;
F_23 ( V_2 , 1 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_52 ;
int V_9 ;
F_5 ( V_114 , 0xCAFEDEAD ) ;
V_9 = F_20 ( V_2 , 3 ) ;
if ( V_9 ) {
F_21 ( L_6 ,
V_2 -> V_120 , V_9 ) ;
return V_9 ;
}
F_23 ( V_2 , F_22 ( V_114 , 0 ) ) ;
F_23 ( V_2 , 0xDEADBEEF ) ;
F_24 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_4 -> V_121 ; V_52 ++ ) {
V_15 = F_2 ( V_114 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_45 ( 1 ) ;
}
if ( V_52 < V_4 -> V_121 ) {
F_25 ( L_7 ,
V_2 -> V_120 , V_52 ) ;
} else {
F_21 ( L_8 ,
V_2 -> V_120 , V_15 ) ;
V_9 = - V_122 ;
}
return V_9 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
unsigned V_125 , bool V_126 )
{
F_23 ( V_2 , F_22 ( V_127 , 0 ) ) ;
F_23 ( V_2 , V_125 ) ;
F_23 ( V_2 , F_22 ( V_128 , 0 ) ) ;
F_23 ( V_2 , F_31 ( V_124 -> V_28 ) ) ;
F_23 ( V_2 , F_22 ( V_129 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_124 -> V_28 ) ) ;
F_23 ( V_2 , F_22 ( V_130 , 0 ) ) ;
F_23 ( V_2 , V_124 -> V_131 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
unsigned V_125 , T_2 V_132 )
{
T_1 V_133 ;
if ( V_125 < 8 )
V_133 = V_134 + V_125 ;
else
V_133 = V_135 + V_125 - 8 ;
F_23 ( V_2 , F_22 ( V_115 , 0 ) ) ;
F_23 ( V_2 , V_133 << 2 ) ;
F_23 ( V_2 , F_22 ( V_116 , 0 ) ) ;
F_23 ( V_2 , V_132 >> 12 ) ;
F_23 ( V_2 , F_22 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_22 ( V_115 , 0 ) ) ;
F_23 ( V_2 , V_136 << 2 ) ;
F_23 ( V_2 , F_22 ( V_116 , 0 ) ) ;
F_23 ( V_2 , 1 << V_125 ) ;
F_23 ( V_2 , F_22 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_22 ( V_115 , 0 ) ) ;
F_23 ( V_2 , V_136 << 2 ) ;
F_23 ( V_2 , F_22 ( V_116 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_137 , 0 ) ) ;
F_23 ( V_2 , 1 << V_125 ) ;
F_23 ( V_2 , F_22 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 0xC ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_1 V_112 = V_2 -> V_138 . V_139 ;
T_2 V_111 = V_2 -> V_138 . V_28 ;
F_23 ( V_2 , F_22 ( V_115 , 0 ) ) ;
F_23 ( V_2 , F_31 ( V_111 ) ) ;
F_23 ( V_2 , F_22 ( V_116 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_111 ) ) ;
F_23 ( V_2 , F_22 ( V_137 , 0 ) ) ;
F_23 ( V_2 , 0xffffffff ) ;
F_23 ( V_2 , F_22 ( V_140 , 0 ) ) ;
F_23 ( V_2 , V_112 ) ;
F_23 ( V_2 , F_22 ( V_117 , 0 ) ) ;
F_23 ( V_2 , 0xE ) ;
}
static bool F_49 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_141 ) & V_142 ) ;
}
static int F_50 ( void * V_8 )
{
unsigned V_52 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_121 ; V_52 ++ ) {
if ( ! ( F_2 ( V_141 ) & V_142 ) )
return 0 ;
}
return - V_143 ;
}
static int F_51 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_27 ( V_4 ) ;
F_34 ( V_74 , V_75 ,
~ V_75 ) ;
F_36 ( 5 ) ;
return F_18 ( V_4 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_144 * V_145 ,
unsigned type ,
enum V_146 V_147 )
{
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_144 * V_145 ,
struct V_148 * V_149 )
{
F_54 ( L_9 ) ;
F_55 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 )
{
T_1 V_58 , V_150 , V_151 , V_152 ;
V_58 = F_2 ( V_59 ) ;
V_150 = F_2 ( V_153 ) ;
V_151 = F_2 ( V_154 ) ;
V_58 &= ~ ( V_155 |
V_156 ) ;
V_152 = V_157 |
V_158 |
V_159 |
V_160 |
V_161 ;
V_58 |= V_60 |
( 1 << F_56 ( V_162 , V_163 ) ) |
( 4 << F_56 ( V_162 , V_164 ) ) ;
V_58 &= ~ ( V_165 |
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
V_186 ) ;
V_151 &= ~ ( V_187 |
V_188 |
V_189 |
V_190 |
V_191 ) ;
V_150 |= V_152 ;
F_5 ( V_59 , V_58 ) ;
F_5 ( V_192 , 0 ) ;
F_5 ( V_153 , V_150 ) ;
F_5 ( V_154 , V_151 ) ;
}
static void F_57 ( struct V_3 * V_4 , bool V_193 )
{
T_4 V_15 = F_58 ( V_194 ) ;
if ( V_193 )
V_15 |= ( V_195 |
V_196 ) ;
else
V_15 &= ~ ( V_195 |
V_196 ) ;
F_59 ( V_194 , V_15 ) ;
}
static int F_60 ( void * V_8 ,
enum V_197 V_147 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_193 = ( V_147 == V_198 ) ? true : false ;
static int V_199 = - 1 ;
if ( V_4 -> V_200 == V_201 ||
V_4 -> V_200 == V_202 )
F_57 ( V_4 , V_193 ) ;
if ( ! ( V_4 -> V_56 & V_57 ) )
return 0 ;
if ( V_199 == V_147 )
return 0 ;
V_199 = V_147 ;
if ( V_193 ) {
F_35 ( V_4 ) ;
} else {
if ( F_50 ( V_8 ) )
return - V_203 ;
}
return 0 ;
}
static int F_61 ( void * V_8 ,
enum V_204 V_147 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_205 & V_206 ) )
return 0 ;
if ( V_147 == V_207 ) {
F_27 ( V_4 ) ;
return 0 ;
} else {
return F_18 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_200 >= V_202 ) {
V_4 -> V_10 . V_2 . V_208 = & V_209 ;
F_25 ( L_10 ) ;
} else {
V_4 -> V_10 . V_2 . V_208 = & V_210 ;
F_25 ( L_11 ) ;
}
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_211 = 1 ;
V_4 -> V_10 . V_11 . V_208 = & V_212 ;
}
