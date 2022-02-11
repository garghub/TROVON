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
F_19 ( V_4 , 53300 , 40000 ) ;
V_9 = F_20 ( V_4 ) ;
if ( V_9 )
goto V_16;
V_2 -> V_17 = true ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_17 = false ;
goto V_16;
}
V_9 = F_22 ( V_2 , 10 ) ;
if ( V_9 ) {
F_23 ( L_2 , V_9 ) ;
goto V_16;
}
V_15 = F_14 ( V_18 , 0 ) ;
F_24 ( V_2 , V_15 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
V_15 = F_14 ( V_19 , 0 ) ;
F_24 ( V_2 , V_15 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
V_15 = F_14 ( V_20 , 0 ) ;
F_24 ( V_2 , V_15 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
F_24 ( V_2 , F_14 ( V_21 , 0 ) ) ;
F_24 ( V_2 , 0x8 ) ;
F_24 ( V_2 , F_14 ( V_22 , 0 ) ) ;
F_24 ( V_2 , 3 ) ;
F_25 ( V_2 ) ;
V_16:
F_19 ( V_4 , 0 , 0 ) ;
if ( ! V_9 )
F_26 ( L_3 ) ;
return V_9 ;
}
static int F_27 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
F_28 ( V_4 ) ;
V_2 -> V_17 = false ;
return 0 ;
}
static int F_29 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_27 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_16 ( V_4 ) ;
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
V_9 = F_18 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static void F_31 ( struct V_3 * V_4 )
{
T_2 V_23 ;
T_1 V_24 ;
F_5 ( V_25 ,
F_32 ( V_4 -> V_10 . V_26 ) ) ;
F_5 ( V_27 ,
F_33 ( V_4 -> V_10 . V_26 ) ) ;
V_23 = V_28 ;
V_24 = F_34 ( V_4 -> V_10 . V_29 -> V_24 + 4 ) ;
F_5 ( V_30 , V_23 >> 3 ) ;
F_5 ( V_31 , V_24 ) ;
V_23 += V_24 ;
V_24 = V_32 ;
F_5 ( V_33 , V_23 >> 3 ) ;
F_5 ( V_34 , V_24 ) ;
V_23 += V_24 ;
V_24 = V_35 +
( V_36 * V_4 -> V_10 . V_37 ) ;
F_5 ( V_38 , V_23 >> 3 ) ;
F_5 ( V_39 , V_24 ) ;
F_5 ( V_40 , V_4 -> V_41 . V_42 . V_43 ) ;
F_5 ( V_44 , V_4 -> V_41 . V_42 . V_43 ) ;
F_5 ( V_45 , V_4 -> V_41 . V_42 . V_43 ) ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_46 , V_15 ;
T_1 V_47 ;
T_1 V_48 ;
int V_49 , V_50 , V_9 ;
F_35 ( V_51 , 0 , ~ ( 1 << 2 ) ) ;
V_47 = 0 ;
V_48 = 0 ;
F_31 ( V_4 ) ;
F_5 ( V_52 , 0 ) ;
F_35 ( V_53 , 0 , ~ ( 1 << 1 ) ) ;
F_35 ( V_54 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_55 , V_56 |
V_57 | V_58 |
V_59 | V_60 |
V_61 | V_62 |
V_63 ) ;
F_36 ( 5 ) ;
F_35 ( V_64 , 0 , ~ V_65 ) ;
F_36 ( 5 ) ;
F_5 ( V_66 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_37
V_47 = 0xa ;
V_48 = 0 ;
#endif
F_5 ( V_67 , V_47 ) ;
F_5 ( V_68 , V_48 ) ;
F_5 ( V_69 , 0x40c2040 ) ;
F_5 ( V_70 , 0x0 ) ;
F_5 ( V_71 , 0x40c2040 ) ;
F_5 ( V_72 , 0x0 ) ;
F_5 ( V_73 , 0 ) ;
F_5 ( V_74 , 0x88 ) ;
F_5 ( V_55 , V_57 ) ;
F_36 ( 5 ) ;
F_5 ( V_75 , 1 << 9 ) ;
F_35 ( V_54 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_55 , 0 ) ;
F_36 ( 10 ) ;
for ( V_49 = 0 ; V_49 < 10 ; ++ V_49 ) {
T_1 V_76 ;
for ( V_50 = 0 ; V_50 < 100 ; ++ V_50 ) {
V_76 = F_2 ( V_77 ) ;
if ( V_76 & 2 )
break;
F_36 ( 10 ) ;
}
V_9 = 0 ;
if ( V_76 & 2 )
break;
F_23 ( L_4 ) ;
F_35 ( V_55 , V_57 ,
~ V_57 ) ;
F_36 ( 10 ) ;
F_35 ( V_55 , 0 , ~ V_57 ) ;
F_36 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_23 ( L_5 ) ;
return V_9 ;
}
F_35 ( V_53 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_35 ( V_77 , 0 , ~ ( 2 << 1 ) ) ;
V_46 = F_38 ( V_2 -> V_78 ) ;
V_15 = 0 ;
V_15 = F_39 ( V_15 , V_79 , V_80 , V_46 ) ;
V_15 = F_39 ( V_15 , V_79 , V_81 , 1 ) ;
V_15 = F_39 ( V_15 , V_79 , V_82 , 1 ) ;
V_15 = F_39 ( V_15 , V_79 , V_83 , 0 ) ;
V_15 = F_39 ( V_15 , V_79 , V_84 , 1 ) ;
V_15 = F_39 ( V_15 , V_79 , V_85 , 1 ) ;
F_5 ( V_86 , V_15 ) ;
F_5 ( V_87 , 0 ) ;
F_5 ( V_88 , ( F_33 ( V_2 -> V_26 ) >> 2 ) ) ;
F_5 ( V_89 ,
F_32 ( V_2 -> V_26 ) ) ;
F_5 ( V_90 ,
F_33 ( V_2 -> V_26 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_35 ( V_86 , 0 , ~ V_91 ) ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
F_5 ( V_86 , 0x11010101 ) ;
F_35 ( V_54 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_55 , V_57 ) ;
F_36 ( 5 ) ;
F_5 ( V_75 , 0x0 ) ;
F_35 ( V_54 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , T_3 V_92 , T_3 V_93 ,
unsigned V_94 )
{
F_41 ( V_94 & V_95 ) ;
F_24 ( V_2 , F_14 ( V_96 , 0 ) ) ;
F_24 ( V_2 , V_93 ) ;
F_24 ( V_2 , F_14 ( V_97 , 0 ) ) ;
F_24 ( V_2 , V_92 & 0xffffffff ) ;
F_24 ( V_2 , F_14 ( V_98 , 0 ) ) ;
F_24 ( V_2 , F_33 ( V_92 ) & 0xff ) ;
F_24 ( V_2 , F_14 ( V_99 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_14 ( V_97 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_14 ( V_98 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_14 ( V_99 , 0 ) ) ;
F_24 ( V_2 , 2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_24 ( V_2 , F_14 ( V_100 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_24 ( V_2 , F_14 ( V_101 , 0 ) ) ;
F_24 ( V_2 , 1 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_49 ;
int V_9 ;
F_5 ( V_96 , 0xCAFEDEAD ) ;
V_9 = F_22 ( V_2 , 3 ) ;
if ( V_9 ) {
F_23 ( L_6 ,
V_2 -> V_102 , V_9 ) ;
return V_9 ;
}
F_24 ( V_2 , F_14 ( V_96 , 0 ) ) ;
F_24 ( V_2 , 0xDEADBEEF ) ;
F_25 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_4 -> V_103 ; V_49 ++ ) {
V_15 = F_2 ( V_96 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_45 ( 1 ) ;
}
if ( V_49 < V_4 -> V_103 ) {
F_26 ( L_7 ,
V_2 -> V_102 , V_49 ) ;
} else {
F_23 ( L_8 ,
V_2 -> V_102 , V_15 ) ;
V_9 = - V_104 ;
}
return V_9 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_105 * V_106 ,
unsigned V_107 , bool V_108 )
{
F_24 ( V_2 , F_14 ( V_109 , 0 ) ) ;
F_24 ( V_2 , F_32 ( V_106 -> V_26 ) ) ;
F_24 ( V_2 , F_14 ( V_110 , 0 ) ) ;
F_24 ( V_2 , F_33 ( V_106 -> V_26 ) ) ;
F_24 ( V_2 , F_14 ( V_111 , 0 ) ) ;
F_24 ( V_2 , V_106 -> V_112 ) ;
}
static unsigned F_47 ( struct V_1 * V_2 )
{
return
6 ;
}
static unsigned F_48 ( struct V_1 * V_2 )
{
return
2 +
2 +
14 ;
}
static bool F_49 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_113 ) & V_114 ) ;
}
static int F_50 ( void * V_8 )
{
unsigned V_49 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_103 ; V_49 ++ ) {
if ( ! ( F_2 ( V_113 ) & V_114 ) )
return 0 ;
}
return - V_115 ;
}
static int F_51 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_28 ( V_4 ) ;
F_35 ( V_64 , V_65 ,
~ V_65 ) ;
F_36 ( 5 ) ;
return F_20 ( V_4 ) ;
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
F_55 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static void F_56 ( struct V_3 * V_4 )
{
T_1 V_122 , V_123 , V_124 , V_125 ;
V_122 = F_2 ( V_126 ) ;
V_123 = F_2 ( V_127 ) ;
V_124 = F_2 ( V_128 ) ;
V_122 &= ~ ( V_129 |
V_130 ) ;
V_125 = V_131 |
V_132 |
V_133 |
V_134 |
V_135 ;
V_122 |= V_136 |
( 1 << F_57 ( V_137 , V_138 ) ) |
( 4 << F_57 ( V_137 , V_139 ) ) ;
V_122 &= ~ ( V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 ) ;
V_124 &= ~ ( V_161 |
V_162 |
V_163 |
V_164 |
V_165 ) ;
V_123 |= V_125 ;
F_5 ( V_126 , V_122 ) ;
F_5 ( V_52 , 0 ) ;
F_5 ( V_127 , V_123 ) ;
F_5 ( V_128 , V_124 ) ;
}
static int F_58 ( void * V_8 ,
enum V_166 V_119 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_167 = ( V_119 == V_168 ) ? true : false ;
static int V_169 = - 1 ;
if ( ! ( V_4 -> V_170 & V_171 ) )
return 0 ;
if ( V_169 == V_119 )
return 0 ;
V_169 = V_119 ;
if ( V_167 ) {
F_56 ( V_4 ) ;
} else {
if ( F_50 ( V_8 ) )
return - V_172 ;
}
return 0 ;
}
static int F_59 ( void * V_8 ,
enum V_173 V_119 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_174 & V_175 ) )
return 0 ;
if ( V_119 == V_176 ) {
F_28 ( V_4 ) ;
return 0 ;
} else {
return F_20 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_177 = & V_178 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_179 = 1 ;
V_4 -> V_10 . V_11 . V_177 = & V_180 ;
}
