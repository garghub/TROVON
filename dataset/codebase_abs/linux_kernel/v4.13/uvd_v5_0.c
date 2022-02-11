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
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_9 ;
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
F_20 ( V_4 , V_24 ) ;
return F_16 ( V_4 ) ;
}
static int F_32 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_13 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return F_18 ( V_4 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
T_1 V_25 ;
T_2 V_26 ;
F_5 ( V_27 ,
F_6 ( V_4 -> V_11 . V_28 ) ) ;
F_5 ( V_29 ,
F_34 ( V_4 -> V_11 . V_28 ) ) ;
V_25 = V_30 ;
V_26 = F_35 ( V_4 -> V_11 . V_31 -> V_26 + 4 ) ;
F_5 ( V_32 , V_25 >> 3 ) ;
F_5 ( V_33 , V_26 ) ;
V_25 += V_26 ;
V_26 = V_34 ;
F_5 ( V_35 , V_25 >> 3 ) ;
F_5 ( V_36 , V_26 ) ;
V_25 += V_26 ;
V_26 = V_37 +
( V_38 * V_4 -> V_11 . V_39 ) ;
F_5 ( V_40 , V_25 >> 3 ) ;
F_5 ( V_41 , V_26 ) ;
F_5 ( V_42 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_46 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_47 , V_4 -> V_43 . V_44 . V_45 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_11 . V_2 ;
T_2 V_48 , V_14 ;
T_2 V_49 ;
T_2 V_50 ;
int V_51 , V_52 , V_9 ;
F_37 ( V_53 , 0 , ~ ( 1 << 2 ) ) ;
V_49 = 0 ;
V_50 = 0 ;
F_33 ( V_4 ) ;
F_37 ( V_54 , 0 , ~ ( 1 << 1 ) ) ;
F_37 ( V_55 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_38 ( 1 ) ;
F_5 ( V_56 , V_57 |
V_58 | V_59 |
V_60 | V_61 |
V_62 | V_63 |
V_64 ) ;
F_38 ( 5 ) ;
F_37 ( V_65 , 0 , ~ V_66 ) ;
F_38 ( 5 ) ;
F_5 ( V_67 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_39
V_49 = 0xa ;
V_50 = 0 ;
#endif
F_5 ( V_68 , V_49 ) ;
F_5 ( V_69 , V_50 ) ;
F_5 ( V_70 , 0x40c2040 ) ;
F_5 ( V_71 , 0x0 ) ;
F_5 ( V_72 , 0x40c2040 ) ;
F_5 ( V_73 , 0x0 ) ;
F_5 ( V_74 , 0 ) ;
F_5 ( V_75 , 0x88 ) ;
F_5 ( V_56 , V_58 ) ;
F_38 ( 5 ) ;
F_5 ( V_76 , 1 << 9 ) ;
F_37 ( V_55 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_56 , 0 ) ;
F_38 ( 10 ) ;
for ( V_51 = 0 ; V_51 < 10 ; ++ V_51 ) {
T_2 V_77 ;
for ( V_52 = 0 ; V_52 < 100 ; ++ V_52 ) {
V_77 = F_2 ( V_23 ) ;
if ( V_77 & 2 )
break;
F_38 ( 10 ) ;
}
V_9 = 0 ;
if ( V_77 & 2 )
break;
F_24 ( L_4 ) ;
F_37 ( V_56 , V_58 ,
~ V_58 ) ;
F_38 ( 10 ) ;
F_37 ( V_56 , 0 , ~ V_58 ) ;
F_38 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_24 ( L_5 ) ;
return V_9 ;
}
F_37 ( V_54 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_37 ( V_23 , 0 , ~ ( 2 << 1 ) ) ;
V_48 = F_40 ( V_2 -> V_78 ) ;
V_14 = 0 ;
V_14 = F_41 ( V_14 , V_79 , V_80 , V_48 ) ;
V_14 = F_41 ( V_14 , V_79 , V_81 , 1 ) ;
V_14 = F_41 ( V_14 , V_79 , V_82 , 1 ) ;
V_14 = F_41 ( V_14 , V_79 , V_83 , 0 ) ;
V_14 = F_41 ( V_14 , V_79 , V_84 , 1 ) ;
V_14 = F_41 ( V_14 , V_79 , V_85 , 1 ) ;
F_5 ( V_86 , V_14 ) ;
F_5 ( V_87 , 0 ) ;
F_5 ( V_88 , ( F_34 ( V_2 -> V_28 ) >> 2 ) ) ;
F_5 ( V_89 ,
F_6 ( V_2 -> V_28 ) ) ;
F_5 ( V_90 ,
F_34 ( V_2 -> V_28 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , F_6 ( V_2 -> V_7 ) ) ;
F_37 ( V_86 , 0 , ~ V_91 ) ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
F_5 ( V_86 , 0x11010101 ) ;
F_37 ( V_55 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_38 ( 1 ) ;
F_5 ( V_56 , V_58 ) ;
F_38 ( 5 ) ;
F_5 ( V_76 , 0x0 ) ;
F_37 ( V_55 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_23 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_3 V_92 , T_3 V_93 ,
unsigned V_94 )
{
F_43 ( V_94 & V_95 ) ;
F_26 ( V_2 , F_25 ( V_96 , 0 ) ) ;
F_26 ( V_2 , V_93 ) ;
F_26 ( V_2 , F_25 ( V_97 , 0 ) ) ;
F_26 ( V_2 , V_92 & 0xffffffff ) ;
F_26 ( V_2 , F_25 ( V_98 , 0 ) ) ;
F_26 ( V_2 , F_34 ( V_92 ) & 0xff ) ;
F_26 ( V_2 , F_25 ( V_99 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , F_25 ( V_97 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , F_25 ( V_98 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , F_25 ( V_99 , 0 ) ) ;
F_26 ( V_2 , 2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_26 ( V_2 , F_25 ( V_100 , 0 ) ) ;
F_26 ( V_2 , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_26 ( V_2 , F_25 ( V_101 , 0 ) ) ;
F_26 ( V_2 , 1 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_14 = 0 ;
unsigned V_51 ;
int V_9 ;
F_5 ( V_96 , 0xCAFEDEAD ) ;
V_9 = F_23 ( V_2 , 3 ) ;
if ( V_9 ) {
F_24 ( L_6 ,
V_2 -> V_102 , V_9 ) ;
return V_9 ;
}
F_26 ( V_2 , F_25 ( V_96 , 0 ) ) ;
F_26 ( V_2 , 0xDEADBEEF ) ;
F_27 ( V_2 ) ;
for ( V_51 = 0 ; V_51 < V_4 -> V_103 ; V_51 ++ ) {
V_14 = F_2 ( V_96 ) ;
if ( V_14 == 0xDEADBEEF )
break;
F_47 ( 1 ) ;
}
if ( V_51 < V_4 -> V_103 ) {
F_28 ( L_7 ,
V_2 -> V_102 , V_51 ) ;
} else {
F_24 ( L_8 ,
V_2 -> V_102 , V_14 ) ;
V_9 = - V_104 ;
}
return V_9 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_105 * V_106 ,
unsigned V_107 , bool V_108 )
{
F_26 ( V_2 , F_25 ( V_109 , 0 ) ) ;
F_26 ( V_2 , F_6 ( V_106 -> V_28 ) ) ;
F_26 ( V_2 , F_25 ( V_110 , 0 ) ) ;
F_26 ( V_2 , F_34 ( V_106 -> V_28 ) ) ;
F_26 ( V_2 , F_25 ( V_111 , 0 ) ) ;
F_26 ( V_2 , V_106 -> V_112 ) ;
}
static bool F_49 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_113 ) & V_114 ) ;
}
static int F_50 ( void * V_8 )
{
unsigned V_51 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_103 ; V_51 ++ ) {
if ( ! ( F_2 ( V_113 ) & V_114 ) )
return 0 ;
}
return - V_115 ;
}
static int F_51 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_30 ( V_4 ) ;
F_37 ( V_65 , V_66 ,
~ V_66 ) ;
F_38 ( 5 ) ;
return F_36 ( V_4 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_116 * V_117 ,
unsigned type ,
enum V_118 V_119 )
{
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_116 * V_117 ,
struct V_120 * V_121 )
{
F_54 ( L_9 ) ;
F_55 ( & V_4 -> V_11 . V_2 ) ;
return 0 ;
}
static void F_56 ( struct V_3 * V_4 , bool V_122 )
{
T_2 V_123 , V_124 , V_125 ;
V_123 = F_2 ( V_126 ) ;
V_124 = F_2 ( V_127 ) ;
V_125 = V_128 |
V_129 |
V_130 |
V_131 |
V_132 ;
if ( V_122 ) {
V_124 |= ( V_133 |
V_134 |
V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 ) ;
if ( V_4 -> V_151 & V_152 )
V_124 |= V_153 ;
V_124 &= ~ V_154 ;
V_123 |= V_125 ;
} else {
V_124 = 0 ;
V_123 = 0 ;
}
F_5 ( V_126 , V_123 ) ;
F_5 ( V_127 , V_124 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
T_2 V_155 , V_156 ;
V_155 = F_2 ( V_157 ) ;
V_156 = F_2 ( V_158 ) ;
V_155 &= ~ ( V_159 |
V_160 ) ;
V_155 |= V_161 |
( 1 << F_58 ( V_162 , V_163 ) ) |
( 4 << F_58 ( V_162 , V_164 ) ) ;
V_155 &= ~ ( V_165 |
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
V_185 ) ;
V_156 &= ~ ( V_186 |
V_187 |
V_188 |
V_189 |
V_190 ) ;
F_5 ( V_157 , V_155 ) ;
F_5 ( V_158 , V_156 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
bool V_122 )
{
T_4 V_191 , V_155 ;
if ( V_122 && ( V_4 -> V_192 & V_193 ) ) {
V_155 = F_59 ( V_194 ) ;
V_155 |= 0xfff ;
F_60 ( V_194 , V_155 ) ;
V_191 = V_155 = F_2 ( V_157 ) ;
V_155 |= V_161 ;
if ( V_191 != V_155 )
F_5 ( V_157 , V_155 ) ;
} else {
V_155 = F_59 ( V_194 ) ;
V_155 &= ~ 0xfff ;
F_60 ( V_194 , V_155 ) ;
V_191 = V_155 = F_2 ( V_157 ) ;
V_155 &= ~ V_161 ;
if ( V_191 != V_155 )
F_5 ( V_157 , V_155 ) ;
}
}
static int F_20 ( void * V_8 ,
enum V_195 V_119 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_122 = ( V_119 == V_24 ) ? true : false ;
if ( V_122 ) {
if ( F_50 ( V_8 ) )
return - V_196 ;
F_56 ( V_4 , true ) ;
} else {
F_56 ( V_4 , false ) ;
}
F_57 ( V_4 ) ;
return 0 ;
}
static int F_61 ( void * V_8 ,
enum V_197 V_119 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_198 = 0 ;
if ( V_119 == V_199 ) {
F_30 ( V_4 ) ;
} else {
V_198 = F_36 ( V_4 ) ;
if ( V_198 )
goto V_200;
}
V_200:
return V_198 ;
}
static void F_62 ( void * V_8 , T_4 * V_94 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_155 ;
F_63 ( & V_4 -> V_201 . V_202 ) ;
if ( F_64 ( V_203 ) &
V_204 ) {
F_28 ( L_10 ) ;
goto V_200;
}
V_155 = F_2 ( V_157 ) ;
if ( V_155 & V_161 )
* V_94 |= V_193 ;
V_200:
F_65 ( & V_4 -> V_201 . V_202 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_11 . V_2 . V_205 = & V_206 ;
}
static void F_9 ( struct V_3 * V_4 )
{
V_4 -> V_11 . V_12 . V_207 = 1 ;
V_4 -> V_11 . V_12 . V_205 = & V_208 ;
}
