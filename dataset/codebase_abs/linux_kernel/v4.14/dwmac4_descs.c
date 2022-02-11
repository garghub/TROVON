static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
void T_1 * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 ;
unsigned int V_9 ;
int V_10 = V_11 ;
V_9 = F_2 ( V_5 -> V_12 ) ;
if ( F_3 ( V_9 & V_13 ) )
return V_14 ;
if ( F_4 ( ! ( V_9 & V_15 ) ) )
return V_16 ;
if ( F_3 ( V_9 & V_17 ) ) {
if ( F_3 ( V_9 & V_18 ) )
V_3 -> V_19 ++ ;
if ( F_3 ( V_9 & V_20 ) )
V_3 -> V_21 ++ ;
if ( F_3 ( V_9 & V_22 ) ) {
V_3 -> V_23 ++ ;
V_8 -> V_24 ++ ;
}
if ( F_3 ( V_9 & V_25 ) ) {
V_3 -> V_26 ++ ;
V_8 -> V_24 ++ ;
}
if ( F_3 ( ( V_9 & V_27 ) ||
( V_9 & V_28 ) ) )
V_8 -> V_29 +=
( V_9 & V_30 )
>> V_31 ;
if ( F_3 ( V_9 & V_32 ) )
V_3 -> V_33 ++ ;
if ( F_3 ( V_9 & V_34 ) )
V_3 -> V_35 ++ ;
if ( F_3 ( V_9 & V_36 ) )
V_3 -> V_37 ++ ;
if ( F_3 ( V_9 & V_38 ) )
V_3 -> V_39 ++ ;
V_10 = V_40 ;
}
if ( F_3 ( V_9 & V_41 ) )
V_3 -> V_33 ++ ;
return V_10 ;
}
static int F_5 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 ;
unsigned int V_42 = F_2 ( V_5 -> V_43 ) ;
unsigned int V_44 = F_2 ( V_5 -> V_45 ) ;
unsigned int V_46 = F_2 ( V_5 -> V_12 ) ;
int V_47 ;
int V_10 = V_48 ;
if ( F_3 ( V_46 & V_49 ) )
return V_50 ;
if ( F_4 ( ! ( V_46 & V_51 ) ) )
return V_52 ;
if ( F_3 ( V_46 & V_53 ) ) {
if ( F_3 ( V_46 & V_54 ) )
V_8 -> V_55 ++ ;
if ( F_3 ( V_46 & V_56 ) )
V_3 -> V_57 ++ ;
if ( F_3 ( V_46 & V_58 ) )
V_3 -> V_59 ++ ;
if ( F_3 ( V_46 & V_60 ) )
V_3 -> V_61 ++ ;
if ( F_3 ( V_46 & V_62 ) ) {
V_3 -> V_63 ++ ;
V_8 -> V_63 ++ ;
}
if ( F_3 ( V_46 & V_64 ) )
V_3 -> V_65 ++ ;
V_10 = V_52 ;
}
V_47 = ( V_42 & V_66 ) >> 8 ;
if ( V_42 & V_67 )
V_3 -> V_68 ++ ;
if ( V_42 & V_69 )
V_3 -> V_70 ++ ;
if ( V_42 & V_71 )
V_3 -> V_72 ++ ;
if ( V_42 & V_73 )
V_3 -> V_74 ++ ;
if ( V_47 == V_75 )
V_3 -> V_76 ++ ;
else if ( V_47 == V_77 )
V_3 -> V_78 ++ ;
else if ( V_47 == V_79 )
V_3 -> V_80 ++ ;
else if ( V_47 == V_81 )
V_3 -> V_82 ++ ;
else if ( V_47 == V_83 )
V_3 -> V_84 ++ ;
else if ( V_47 == V_85 )
V_3 -> V_86 ++ ;
else if ( V_47 == V_87 )
V_3 -> V_88 ++ ;
else if ( V_47 == V_89 )
V_3 -> V_90 ++ ;
else if ( V_47 == V_91 )
V_3 -> V_92 ++ ;
else if ( V_47 == V_93 )
V_3 -> V_94 ++ ;
else if ( V_47 == V_95 )
V_3 -> V_96 ++ ;
if ( V_42 & V_97 )
V_3 -> V_98 ++ ;
if ( V_42 & V_99 )
V_3 -> V_100 ++ ;
if ( V_42 & V_101 )
V_3 -> V_102 ++ ;
if ( F_3 ( V_44 & V_103 ) ) {
V_3 -> V_104 ++ ;
V_10 = V_52 ;
}
if ( F_3 ( V_44 & V_105 ) ) {
V_3 -> V_106 ++ ;
V_10 = V_52 ;
}
if ( V_44 & V_107 )
V_3 -> V_108 ++ ;
if ( V_44 & V_109 )
V_3 -> V_110 ++ ;
if ( ( V_44 & V_111 )
>> V_112 )
V_3 -> V_113 ++ ;
return V_10 ;
}
static int F_6 ( struct V_4 * V_5 )
{
return ( F_2 ( V_5 -> V_45 ) & V_114 ) ;
}
static int F_7 ( struct V_4 * V_5 )
{
return ( F_2 ( V_5 -> V_12 ) & V_13 ) >> V_115 ;
}
static void F_8 ( struct V_4 * V_5 )
{
V_5 -> V_12 |= F_9 ( V_13 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
V_5 -> V_12 |= F_9 ( V_49 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
return ( F_2 ( V_5 -> V_12 ) & V_15 )
>> V_116 ;
}
static int F_12 ( struct V_4 * V_5 , int V_117 )
{
return ( F_2 ( V_5 -> V_12 ) & V_118 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
V_5 -> V_45 |= F_9 ( V_119 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
if ( F_2 ( V_5 -> V_12 ) & V_120 )
return 0 ;
if ( F_2 ( V_5 -> V_12 ) & V_121 )
return 1 ;
return 0 ;
}
static inline T_2 F_15 ( void * V_122 , T_3 V_123 )
{
struct V_4 * V_5 = (struct V_4 * ) V_122 ;
T_2 V_124 ;
V_124 = F_2 ( V_5 -> V_125 ) ;
V_124 += F_2 ( V_5 -> V_43 ) * 1000000000ULL ;
return V_124 ;
}
static int F_16 ( void * V_122 )
{
struct V_4 * V_5 = (struct V_4 * ) V_122 ;
T_3 V_126 , V_127 ;
int V_10 = 1 ;
V_126 = V_5 -> V_12 & V_49 ;
V_127 = ( ( V_5 -> V_12 & V_128 )
>> V_129 ) ;
if ( F_4 ( ! V_126 && V_127 ) ) {
if ( ( V_5 -> V_125 == 0xffffffff ) && ( V_5 -> V_43 == 0xffffffff ) )
V_10 = - V_130 ;
else
V_10 = 0 ;
}
return V_10 ;
}
static int F_17 ( void * V_122 , T_3 V_123 )
{
struct V_4 * V_5 = (struct V_4 * ) V_122 ;
int V_10 = - V_130 ;
if ( F_4 ( V_5 -> V_12 & V_131 ) ) {
if ( F_4 ( F_2 ( V_5 -> V_43 ) & V_132 ) ) {
int V_133 = 0 ;
do {
V_10 = F_16 ( V_122 ) ;
if ( V_10 < 0 )
goto exit;
V_133 ++ ;
} while ( ( V_10 == 1 ) && ( V_133 < 10 ) );
if ( V_133 == 10 )
V_10 = - V_134 ;
}
}
exit:
if ( F_4 ( V_10 == 0 ) )
return 1 ;
return 0 ;
}
static void F_18 ( struct V_4 * V_5 , int V_135 ,
int V_136 , int V_137 )
{
V_5 -> V_12 = F_9 ( V_49 | V_138 ) ;
if ( ! V_135 )
V_5 -> V_12 |= F_9 ( V_139 ) ;
}
static void F_19 ( struct V_4 * V_5 , int V_136 , int V_137 )
{
V_5 -> V_125 = 0 ;
V_5 -> V_43 = 0 ;
V_5 -> V_45 = 0 ;
V_5 -> V_12 = 0 ;
}
static void F_20 ( struct V_4 * V_5 , int V_140 , int V_141 ,
bool V_142 , int V_136 , bool V_143 ,
bool V_144 , unsigned int V_145 )
{
unsigned int V_9 = F_2 ( V_5 -> V_12 ) ;
V_5 -> V_45 |= F_9 ( V_141 & V_114 ) ;
V_9 |= V_145 & V_146 ;
if ( V_140 )
V_9 |= V_147 ;
else
V_9 &= ~ V_147 ;
if ( F_4 ( V_142 ) )
V_9 |= ( V_148 << V_149 ) ;
else
V_9 &= ~ ( V_148 << V_149 ) ;
if ( V_144 )
V_9 |= V_15 ;
else
V_9 &= ~ V_15 ;
if ( V_143 )
V_9 |= V_13 ;
if ( V_140 & V_143 )
F_21 () ;
V_5 -> V_12 = F_9 ( V_9 ) ;
}
static void F_22 ( struct V_4 * V_5 , int V_140 ,
int V_150 , int V_151 , bool V_143 ,
bool V_144 , unsigned int V_152 ,
unsigned int V_153 )
{
unsigned int V_9 = F_2 ( V_5 -> V_12 ) ;
if ( V_150 )
V_5 -> V_45 |= F_9 ( ( V_150 & V_114 ) ) ;
if ( V_151 )
V_5 -> V_45 |= F_9 ( ( V_151 << V_154 )
& V_155 ) ;
if ( V_140 ) {
V_9 |= V_147 |
V_156 |
( ( V_152 << V_157 ) &
V_158 ) |
( ( V_153 & V_159 ) ) ;
} else {
V_9 &= ~ V_147 ;
}
if ( V_144 )
V_9 |= V_15 ;
else
V_9 &= ~ V_15 ;
if ( V_143 )
V_9 |= V_13 ;
if ( V_140 & V_143 )
F_21 () ;
V_5 -> V_12 = F_9 ( V_9 ) ;
}
static void F_23 ( struct V_4 * V_5 , int V_136 )
{
V_5 -> V_45 = 0 ;
V_5 -> V_12 = 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
V_5 -> V_45 |= F_9 ( V_160 ) ;
}
static void F_25 ( void * V_161 , unsigned int V_162 , bool V_163 )
{
struct V_4 * V_5 = (struct V_4 * ) V_161 ;
int V_133 ;
F_26 ( L_1 , V_163 ? L_2 : L_3 ) ;
for ( V_133 = 0 ; V_133 < V_162 ; V_133 ++ ) {
F_26 ( L_4 ,
V_133 , ( unsigned int ) F_27 ( V_5 ) ,
F_2 ( V_5 -> V_125 ) , F_2 ( V_5 -> V_43 ) ,
F_2 ( V_5 -> V_45 ) , F_2 ( V_5 -> V_12 ) ) ;
V_5 ++ ;
}
}
static void F_28 ( struct V_4 * V_5 , unsigned int V_164 )
{
V_5 -> V_125 = 0 ;
V_5 -> V_43 = 0 ;
V_5 -> V_45 = F_9 ( V_164 ) ;
V_5 -> V_12 = F_9 ( V_120 | V_165 ) ;
}
