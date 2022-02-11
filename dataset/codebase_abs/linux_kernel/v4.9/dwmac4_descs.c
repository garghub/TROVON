static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
void T_1 * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 ;
unsigned int V_9 ;
int V_10 = V_11 ;
V_9 = V_5 -> V_12 ;
if ( F_2 ( V_9 & V_13 ) )
return V_14 ;
if ( F_3 ( ! ( V_9 & V_15 ) ) )
return V_16 ;
if ( F_2 ( V_9 & V_17 ) ) {
if ( F_2 ( V_9 & V_18 ) )
V_3 -> V_19 ++ ;
if ( F_2 ( V_9 & V_20 ) )
V_3 -> V_21 ++ ;
if ( F_2 ( V_9 & V_22 ) ) {
V_3 -> V_23 ++ ;
V_8 -> V_24 ++ ;
}
if ( F_2 ( V_9 & V_25 ) ) {
V_3 -> V_26 ++ ;
V_8 -> V_24 ++ ;
}
if ( F_2 ( ( V_9 & V_27 ) ||
( V_9 & V_28 ) ) )
V_8 -> V_29 +=
( V_9 & V_30 )
>> V_31 ;
if ( F_2 ( V_9 & V_32 ) )
V_3 -> V_33 ++ ;
if ( F_2 ( V_9 & V_34 ) )
V_3 -> V_35 ++ ;
if ( F_2 ( V_9 & V_36 ) )
V_3 -> V_37 ++ ;
if ( F_2 ( V_9 & V_38 ) )
V_3 -> V_39 ++ ;
V_10 = V_40 ;
}
if ( F_2 ( V_9 & V_41 ) )
V_3 -> V_33 ++ ;
return V_10 ;
}
static int F_4 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 ;
unsigned int V_42 = V_5 -> V_43 ;
unsigned int V_44 = V_5 -> V_45 ;
unsigned int V_46 = V_5 -> V_12 ;
int V_47 ;
int V_10 = V_48 ;
if ( F_2 ( V_46 & V_49 ) )
return V_50 ;
if ( F_3 ( ! ( V_46 & V_51 ) ) )
return V_52 ;
if ( F_2 ( V_46 & V_53 ) ) {
if ( F_2 ( V_46 & V_54 ) )
V_8 -> V_55 ++ ;
if ( F_2 ( V_46 & V_56 ) )
V_3 -> V_57 ++ ;
if ( F_2 ( V_46 & V_58 ) )
V_3 -> V_59 ++ ;
if ( F_2 ( V_46 & V_60 ) )
V_3 -> V_61 ++ ;
if ( F_2 ( V_46 & V_62 ) ) {
V_3 -> V_63 ++ ;
V_8 -> V_64 ++ ;
}
if ( F_2 ( V_46 & V_65 ) )
V_3 -> V_66 ++ ;
V_10 = V_52 ;
}
V_47 = ( V_42 & V_67 ) >> 8 ;
if ( V_42 & V_68 )
V_3 -> V_69 ++ ;
if ( V_42 & V_70 )
V_3 -> V_71 ++ ;
if ( V_42 & V_72 )
V_3 -> V_73 ++ ;
if ( V_42 & V_74 )
V_3 -> V_75 ++ ;
if ( V_47 == V_76 )
V_3 -> V_77 ++ ;
else if ( V_47 == V_78 )
V_3 -> V_79 ++ ;
else if ( V_47 == V_80 )
V_3 -> V_81 ++ ;
else if ( V_47 == V_82 )
V_3 -> V_83 ++ ;
else if ( V_47 == V_84 )
V_3 -> V_85 ++ ;
else if ( V_47 == V_86 )
V_3 -> V_87 ++ ;
else if ( V_47 == V_88 )
V_3 -> V_89 ++ ;
else if ( V_47 == V_90 )
V_3 -> V_91 ++ ;
else if ( V_47 == V_92 )
V_3 -> V_93 ++ ;
else if ( V_47 == V_94 )
V_3 -> V_95 ++ ;
else if ( V_47 == V_96 )
V_3 -> V_97 ++ ;
if ( V_42 & V_98 )
V_3 -> V_99 ++ ;
if ( V_42 & V_100 )
V_3 -> V_101 ++ ;
if ( V_42 & V_102 )
V_3 -> V_103 ++ ;
if ( F_2 ( V_44 & V_104 ) ) {
V_3 -> V_105 ++ ;
V_10 = V_52 ;
}
if ( F_2 ( V_44 & V_106 ) ) {
V_3 -> V_107 ++ ;
V_10 = V_52 ;
}
if ( V_44 & V_108 )
V_3 -> V_109 ++ ;
if ( V_44 & V_110 )
V_3 -> V_111 ++ ;
if ( ( V_44 & V_112 )
>> V_113 )
V_3 -> V_114 ++ ;
return V_10 ;
}
static int F_5 ( struct V_4 * V_5 )
{
return ( V_5 -> V_45 & V_115 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
return ( V_5 -> V_12 & V_13 ) >> V_116 ;
}
static void F_7 ( struct V_4 * V_5 )
{
V_5 -> V_12 |= V_13 ;
}
static void F_8 ( struct V_4 * V_5 )
{
V_5 -> V_12 |= V_49 ;
}
static int F_9 ( struct V_4 * V_5 )
{
return ( V_5 -> V_12 & V_15 ) >> V_117 ;
}
static int F_10 ( struct V_4 * V_5 , int V_118 )
{
return ( V_5 -> V_12 & V_119 ) ;
}
static void F_11 ( struct V_4 * V_5 )
{
V_5 -> V_45 |= V_120 ;
}
static int F_12 ( struct V_4 * V_5 )
{
if ( V_5 -> V_12 & V_121 )
return - V_122 ;
if ( V_5 -> V_12 & V_123 )
return 0 ;
return 1 ;
}
static inline T_2 F_13 ( void * V_124 , T_3 V_125 )
{
struct V_4 * V_5 = (struct V_4 * ) V_124 ;
T_2 V_126 ;
V_126 = V_5 -> V_127 ;
V_126 += V_5 -> V_43 * 1000000000ULL ;
return V_126 ;
}
static int F_14 ( void * V_124 )
{
struct V_4 * V_5 = (struct V_4 * ) V_124 ;
T_3 V_128 , V_129 ;
int V_10 = 1 ;
V_128 = V_5 -> V_12 & V_49 ;
V_129 = ( ( V_5 -> V_12 & V_130 )
>> V_131 ) ;
if ( F_3 ( ! V_128 && V_129 ) ) {
if ( ( V_5 -> V_127 == 0xffffffff ) && ( V_5 -> V_43 == 0xffffffff ) )
V_10 = - V_122 ;
else
V_10 = 0 ;
}
return V_10 ;
}
static int F_15 ( void * V_124 , T_3 V_125 )
{
struct V_4 * V_5 = (struct V_4 * ) V_124 ;
int V_10 = - V_122 ;
if ( F_3 ( V_5 -> V_12 & V_132 ) ) {
if ( F_3 ( V_5 -> V_43 & V_133 ) ) {
int V_134 = 0 ;
do {
V_10 = F_14 ( V_124 ) ;
if ( V_10 < 0 )
goto exit;
V_134 ++ ;
} while ( ( V_10 == 1 ) || ( V_134 < 10 ) );
if ( V_134 == 10 )
V_10 = - V_135 ;
}
}
exit:
return V_10 ;
}
static void F_16 ( struct V_4 * V_5 , int V_136 ,
int V_137 , int V_138 )
{
V_5 -> V_12 = V_49 | V_139 ;
if ( ! V_136 )
V_5 -> V_12 |= V_140 ;
}
static void F_17 ( struct V_4 * V_5 , int V_137 , int V_138 )
{
V_5 -> V_127 = 0 ;
V_5 -> V_43 = 0 ;
V_5 -> V_45 = 0 ;
V_5 -> V_12 = 0 ;
}
static void F_18 ( struct V_4 * V_5 , int V_141 , int V_142 ,
bool V_143 , int V_137 , bool V_144 ,
bool V_145 )
{
unsigned int V_9 = V_5 -> V_12 ;
V_5 -> V_45 |= ( V_142 & V_115 ) ;
if ( V_141 )
V_9 |= V_146 ;
else
V_9 &= ~ V_146 ;
if ( F_3 ( V_143 ) )
V_9 |= ( V_147 << V_148 ) ;
else
V_9 &= ~ ( V_147 << V_148 ) ;
if ( V_145 )
V_9 |= V_15 ;
else
V_9 &= ~ V_15 ;
if ( V_144 )
V_9 |= V_13 ;
if ( V_141 & V_144 )
F_19 () ;
V_5 -> V_12 = V_9 ;
}
static void F_20 ( struct V_4 * V_5 , int V_141 ,
int V_149 , int V_150 , bool V_144 ,
bool V_145 , unsigned int V_151 ,
unsigned int V_152 )
{
unsigned int V_9 = V_5 -> V_12 ;
if ( V_149 )
V_5 -> V_45 |= ( V_149 & V_115 ) ;
if ( V_150 )
V_5 -> V_45 |= ( V_150 << V_153 )
& V_154 ;
if ( V_141 ) {
V_9 |= V_146 |
V_155 |
( ( V_151 << V_156 ) &
V_157 ) |
( ( V_152 & V_158 ) ) ;
} else {
V_9 &= ~ V_146 ;
}
if ( V_145 )
V_9 |= V_15 ;
else
V_9 &= ~ V_15 ;
if ( V_144 )
V_9 |= V_13 ;
if ( V_141 & V_144 )
F_19 () ;
V_5 -> V_12 = V_9 ;
}
static void F_21 ( struct V_4 * V_5 , int V_137 )
{
V_5 -> V_45 = 0 ;
V_5 -> V_12 = 0 ;
}
static void F_22 ( struct V_4 * V_5 )
{
V_5 -> V_45 |= V_159 ;
}
static void F_23 ( void * V_160 , unsigned int V_161 , bool V_162 )
{
struct V_4 * V_5 = (struct V_4 * ) V_160 ;
int V_134 ;
F_24 ( L_1 , V_162 ? L_2 : L_3 ) ;
for ( V_134 = 0 ; V_134 < V_161 ; V_134 ++ ) {
F_24 ( L_4 ,
V_134 , ( unsigned int ) F_25 ( V_5 ) ,
V_5 -> V_127 , V_5 -> V_43 , V_5 -> V_45 , V_5 -> V_12 ) ;
V_5 ++ ;
}
}
static void F_26 ( struct V_4 * V_5 , unsigned int V_163 )
{
V_5 -> V_127 = 0 ;
V_5 -> V_43 = 0 ;
V_5 -> V_45 = V_163 ;
V_5 -> V_12 = V_121 | V_164 ;
}
