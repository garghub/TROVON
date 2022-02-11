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
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_9 ;
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
V_9 = F_18 ( V_4 ) ;
if ( V_9 )
goto V_14;
V_2 -> V_15 = true ;
V_9 = F_19 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_15 = false ;
goto V_14;
}
V_9 = F_20 ( V_2 , 10 ) ;
if ( V_9 ) {
F_21 ( L_2 , V_9 ) ;
goto V_14;
}
V_13 = F_22 ( V_16 , 0 ) ;
F_23 ( V_2 , V_13 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_13 = F_22 ( V_17 , 0 ) ;
F_23 ( V_2 , V_13 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_13 = F_22 ( V_18 , 0 ) ;
F_23 ( V_2 , V_13 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
F_23 ( V_2 , F_22 ( V_19 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_22 ( V_20 , 0 ) ) ;
F_23 ( V_2 , 3 ) ;
F_24 ( V_2 ) ;
V_14:
if ( ! V_9 )
F_25 ( L_3 ) ;
return V_9 ;
}
static int F_26 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
F_27 ( V_4 ) ;
V_2 -> V_15 = false ;
return 0 ;
}
static int F_28 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_26 ( V_4 ) ;
if ( V_9 )
return V_9 ;
F_29 ( V_4 , V_21 ) ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_30 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static void F_31 ( struct V_3 * V_4 )
{
T_2 V_22 ;
T_1 V_23 ;
F_5 ( V_24 ,
F_32 ( V_4 -> V_10 . V_25 ) ) ;
F_5 ( V_26 ,
F_33 ( V_4 -> V_10 . V_25 ) ) ;
V_22 = V_27 ;
V_23 = F_34 ( V_4 -> V_10 . V_28 -> V_23 + 4 ) ;
F_5 ( V_29 , V_22 >> 3 ) ;
F_5 ( V_30 , V_23 ) ;
V_22 += V_23 ;
V_23 = V_31 ;
F_5 ( V_32 , V_22 >> 3 ) ;
F_5 ( V_33 , V_23 ) ;
V_22 += V_23 ;
V_23 = V_34 +
( V_35 * V_4 -> V_10 . V_36 ) ;
F_5 ( V_37 , V_22 >> 3 ) ;
F_5 ( V_38 , V_23 ) ;
F_5 ( V_39 , V_4 -> V_40 . V_41 . V_42 ) ;
F_5 ( V_43 , V_4 -> V_40 . V_41 . V_42 ) ;
F_5 ( V_44 , V_4 -> V_40 . V_41 . V_42 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_45 , V_13 ;
T_1 V_46 ;
T_1 V_47 ;
int V_48 , V_49 , V_9 ;
F_35 ( V_50 , 0 , ~ ( 1 << 2 ) ) ;
V_46 = 0 ;
V_47 = 0 ;
F_31 ( V_4 ) ;
F_36 ( V_4 , 10000 , 10000 ) ;
F_29 ( V_4 , V_51 ) ;
F_37 ( V_4 , true ) ;
F_35 ( V_52 , 0 , ~ ( 1 << 1 ) ) ;
F_35 ( V_53 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_38 ( 1 ) ;
F_5 ( V_54 , V_55 |
V_56 | V_57 |
V_58 | V_59 |
V_60 | V_61 |
V_62 ) ;
F_38 ( 5 ) ;
F_35 ( V_63 , 0 , ~ V_64 ) ;
F_38 ( 5 ) ;
F_5 ( V_65 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_39
V_46 = 0xa ;
V_47 = 0 ;
#endif
F_5 ( V_66 , V_46 ) ;
F_5 ( V_67 , V_47 ) ;
F_5 ( V_68 , 0x40c2040 ) ;
F_5 ( V_69 , 0x0 ) ;
F_5 ( V_70 , 0x40c2040 ) ;
F_5 ( V_71 , 0x0 ) ;
F_5 ( V_72 , 0 ) ;
F_5 ( V_73 , 0x88 ) ;
F_5 ( V_54 , V_56 ) ;
F_38 ( 5 ) ;
F_5 ( V_74 , 1 << 9 ) ;
F_35 ( V_53 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_54 , 0 ) ;
F_38 ( 10 ) ;
for ( V_48 = 0 ; V_48 < 10 ; ++ V_48 ) {
T_1 V_75 ;
for ( V_49 = 0 ; V_49 < 100 ; ++ V_49 ) {
V_75 = F_2 ( V_76 ) ;
if ( V_75 & 2 )
break;
F_38 ( 10 ) ;
}
V_9 = 0 ;
if ( V_75 & 2 )
break;
F_21 ( L_4 ) ;
F_35 ( V_54 , V_56 ,
~ V_56 ) ;
F_38 ( 10 ) ;
F_35 ( V_54 , 0 , ~ V_56 ) ;
F_38 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_21 ( L_5 ) ;
return V_9 ;
}
F_35 ( V_52 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_35 ( V_76 , 0 , ~ ( 2 << 1 ) ) ;
V_45 = F_40 ( V_2 -> V_77 ) ;
V_13 = 0 ;
V_13 = F_41 ( V_13 , V_78 , V_79 , V_45 ) ;
V_13 = F_41 ( V_13 , V_78 , V_80 , 1 ) ;
V_13 = F_41 ( V_13 , V_78 , V_81 , 1 ) ;
V_13 = F_41 ( V_13 , V_78 , V_82 , 0 ) ;
V_13 = F_41 ( V_13 , V_78 , V_83 , 1 ) ;
V_13 = F_41 ( V_13 , V_78 , V_84 , 1 ) ;
F_5 ( V_85 , V_13 ) ;
F_5 ( V_86 , 0 ) ;
F_5 ( V_87 , ( F_33 ( V_2 -> V_25 ) >> 2 ) ) ;
F_5 ( V_88 ,
F_32 ( V_2 -> V_25 ) ) ;
F_5 ( V_89 ,
F_33 ( V_2 -> V_25 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_35 ( V_85 , 0 , ~ V_90 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_5 ( V_85 , 0x11010101 ) ;
F_35 ( V_53 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_38 ( 1 ) ;
F_5 ( V_54 , V_56 ) ;
F_38 ( 5 ) ;
F_5 ( V_74 , 0x0 ) ;
F_35 ( V_53 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_42 ( struct V_1 * V_2 , T_3 V_91 , T_3 V_92 ,
unsigned V_93 )
{
F_43 ( V_93 & V_94 ) ;
F_23 ( V_2 , F_22 ( V_95 , 0 ) ) ;
F_23 ( V_2 , V_92 ) ;
F_23 ( V_2 , F_22 ( V_96 , 0 ) ) ;
F_23 ( V_2 , V_91 & 0xffffffff ) ;
F_23 ( V_2 , F_22 ( V_97 , 0 ) ) ;
F_23 ( V_2 , F_33 ( V_91 ) & 0xff ) ;
F_23 ( V_2 , F_22 ( V_98 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_96 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_97 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_98 , 0 ) ) ;
F_23 ( V_2 , 2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_23 ( V_2 , F_22 ( V_99 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_23 ( V_2 , F_22 ( V_100 , 0 ) ) ;
F_23 ( V_2 , 1 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 = 0 ;
unsigned V_48 ;
int V_9 ;
F_5 ( V_95 , 0xCAFEDEAD ) ;
V_9 = F_20 ( V_2 , 3 ) ;
if ( V_9 ) {
F_21 ( L_6 ,
V_2 -> V_101 , V_9 ) ;
return V_9 ;
}
F_23 ( V_2 , F_22 ( V_95 , 0 ) ) ;
F_23 ( V_2 , 0xDEADBEEF ) ;
F_24 ( V_2 ) ;
for ( V_48 = 0 ; V_48 < V_4 -> V_102 ; V_48 ++ ) {
V_13 = F_2 ( V_95 ) ;
if ( V_13 == 0xDEADBEEF )
break;
F_47 ( 1 ) ;
}
if ( V_48 < V_4 -> V_102 ) {
F_25 ( L_7 ,
V_2 -> V_101 , V_48 ) ;
} else {
F_21 ( L_8 ,
V_2 -> V_101 , V_13 ) ;
V_9 = - V_103 ;
}
return V_9 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
unsigned V_106 , bool V_107 )
{
F_23 ( V_2 , F_22 ( V_108 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_105 -> V_25 ) ) ;
F_23 ( V_2 , F_22 ( V_109 , 0 ) ) ;
F_23 ( V_2 , F_33 ( V_105 -> V_25 ) ) ;
F_23 ( V_2 , F_22 ( V_110 , 0 ) ) ;
F_23 ( V_2 , V_105 -> V_111 ) ;
}
static bool F_49 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_112 ) & V_113 ) ;
}
static int F_50 ( void * V_8 )
{
unsigned V_48 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_48 = 0 ; V_48 < V_4 -> V_102 ; V_48 ++ ) {
if ( ! ( F_2 ( V_112 ) & V_113 ) )
return 0 ;
}
return - V_114 ;
}
static int F_51 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_27 ( V_4 ) ;
F_35 ( V_63 , V_64 ,
~ V_64 ) ;
F_38 ( 5 ) ;
return F_18 ( V_4 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_115 * V_116 ,
unsigned type ,
enum V_117 V_118 )
{
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_115 * V_116 ,
struct V_119 * V_120 )
{
F_54 ( L_9 ) ;
F_55 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static void F_56 ( struct V_3 * V_4 , bool V_121 )
{
T_1 V_122 , V_123 , V_124 ;
V_122 = F_2 ( V_125 ) ;
V_123 = F_2 ( V_126 ) ;
V_124 = V_127 |
V_128 |
V_129 |
V_130 |
V_131 ;
if ( V_121 ) {
V_123 |= ( V_132 |
V_133 |
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
V_149 ) ;
if ( V_4 -> V_150 & V_151 )
V_123 |= V_152 ;
V_123 &= ~ V_153 ;
V_122 |= V_124 ;
} else {
V_123 = 0 ;
V_122 = 0 ;
}
F_5 ( V_125 , V_122 ) ;
F_5 ( V_126 , V_123 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
T_1 V_154 , V_155 ;
V_154 = F_2 ( V_156 ) ;
V_155 = F_2 ( V_157 ) ;
V_154 &= ~ ( V_158 |
V_159 ) ;
V_154 |= V_160 |
( 1 << F_58 ( V_161 , V_162 ) ) |
( 4 << F_58 ( V_161 , V_163 ) ) ;
V_154 &= ~ ( V_164 |
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
V_176 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_182 |
V_183 |
V_184 ) ;
V_155 &= ~ ( V_185 |
V_186 |
V_187 |
V_188 |
V_189 ) ;
F_5 ( V_156 , V_154 ) ;
F_5 ( V_157 , V_155 ) ;
}
static void F_37 ( struct V_3 * V_4 ,
bool V_121 )
{
T_4 V_190 , V_154 ;
if ( V_121 && ( V_4 -> V_191 & V_192 ) ) {
V_154 = F_59 ( V_193 ) ;
V_154 |= 0xfff ;
F_60 ( V_193 , V_154 ) ;
V_190 = V_154 = F_2 ( V_156 ) ;
V_154 |= V_160 ;
if ( V_190 != V_154 )
F_5 ( V_156 , V_154 ) ;
} else {
V_154 = F_59 ( V_193 ) ;
V_154 &= ~ 0xfff ;
F_60 ( V_193 , V_154 ) ;
V_190 = V_154 = F_2 ( V_156 ) ;
V_154 &= ~ V_160 ;
if ( V_190 != V_154 )
F_5 ( V_156 , V_154 ) ;
}
}
static int F_29 ( void * V_8 ,
enum V_194 V_118 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_121 = ( V_118 == V_21 ) ? true : false ;
if ( ! ( V_4 -> V_191 & V_192 ) )
return 0 ;
if ( V_121 ) {
if ( F_50 ( V_8 ) )
return - V_195 ;
F_56 ( V_4 , true ) ;
} else {
F_56 ( V_4 , false ) ;
}
F_57 ( V_4 ) ;
return 0 ;
}
static int F_61 ( void * V_8 ,
enum V_196 V_118 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_150 & V_151 ) )
return 0 ;
if ( V_118 == V_197 ) {
F_27 ( V_4 ) ;
return 0 ;
} else {
return F_18 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_198 = & V_199 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_200 = 1 ;
V_4 -> V_10 . V_11 . V_198 = & V_201 ;
}
