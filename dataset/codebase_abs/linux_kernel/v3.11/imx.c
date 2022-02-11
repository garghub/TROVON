static inline unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> F_1 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_6 ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
V_10 -> V_11 = F_5 ( V_8 -> V_12 + V_13 ) ;
V_10 -> V_14 = F_5 ( V_8 -> V_12 + V_15 ) ;
V_10 -> V_16 = F_5 ( V_8 -> V_12 + V_17 ) ;
}
static void F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
F_7 ( V_10 -> V_11 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_10 -> V_14 , V_8 -> V_12 + V_15 ) ;
F_7 ( V_10 -> V_16 , V_8 -> V_12 + V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_18 , V_19 ;
V_18 = V_2 -> V_8 . V_20 -> V_21 ( & V_2 -> V_8 ) ;
V_19 = V_18 ^ V_2 -> V_22 ;
if ( V_19 == 0 )
return;
V_2 -> V_22 = V_18 ;
if ( V_19 & V_23 )
V_2 -> V_8 . V_24 . V_25 ++ ;
if ( V_19 & V_26 )
V_2 -> V_8 . V_24 . V_27 ++ ;
if ( V_19 & V_28 )
F_9 ( & V_2 -> V_8 , V_18 & V_28 ) ;
if ( V_19 & V_29 )
F_10 ( & V_2 -> V_8 , V_18 & V_29 ) ;
F_11 ( & V_2 -> V_8 . V_30 -> V_8 . V_31 ) ;
}
static void F_12 ( unsigned long V_32 )
{
struct V_1 * V_2 = (struct V_1 * ) V_32 ;
unsigned long V_33 ;
if ( V_2 -> V_8 . V_30 ) {
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_8 ( V_2 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_15 ( & V_2 -> V_35 , V_36 + V_37 ) ;
}
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
if ( F_17 ( V_2 ) ) {
int V_39 = 256 ;
while ( ( -- V_39 > 0 ) &&
! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ) {
F_18 ( 5 ) ;
F_19 () ;
}
F_18 ( V_2 -> V_42 ) ;
if ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 &= ~ ( V_43 | V_44 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
V_38 &= ~ ( V_46 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_45 ) ;
while ( F_5 ( V_2 -> V_8 . V_12 + V_47 ) &
V_48 )
F_19 () ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 |= V_49 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
V_38 |= V_50 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_45 ) ;
}
return;
}
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_38 & ~ V_43 , V_2 -> V_8 . V_12 + V_13 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
F_7 ( V_38 & ~ V_51 , V_2 -> V_8 . V_12 + V_15 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
F_15 ( & V_2 -> V_35 , V_36 ) ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = & V_2 -> V_8 . V_30 -> V_53 ;
while ( ! F_23 ( V_53 ) &&
! ( F_5 ( V_2 -> V_8 . V_12 + F_1 ( V_2 ) )
& V_54 ) ) {
F_7 ( V_53 -> V_55 [ V_53 -> V_56 ] , V_2 -> V_8 . V_12 + V_57 ) ;
V_53 -> V_56 = ( V_53 -> V_56 + 1 ) & ( V_58 - 1 ) ;
V_2 -> V_8 . V_24 . V_59 ++ ;
}
if ( F_24 ( V_53 ) < V_60 )
F_25 ( & V_2 -> V_8 ) ;
if ( F_23 ( V_53 ) )
F_16 ( & V_2 -> V_8 ) ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
if ( F_17 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
V_38 &= ~ ( V_50 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_45 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 &= ~ ( V_49 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
}
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_40 ) ;
F_7 ( V_38 | V_61 , V_2 -> V_8 . V_12 + V_40 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
V_38 |= V_62 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_45 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_38 | V_43 , V_2 -> V_8 . V_12 + V_13 ) ;
if ( F_17 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 |= V_44 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
V_38 |= V_46 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_45 ) ;
}
if ( F_5 ( V_2 -> V_8 . V_12 + F_1 ( V_2 ) ) & V_63 )
F_22 ( V_2 ) ;
}
static T_1 F_27 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned int V_66 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_7 ( V_67 , V_2 -> V_8 . V_12 + V_68 ) ;
V_66 = F_5 ( V_2 -> V_8 . V_12 + V_68 ) & V_69 ;
F_10 ( & V_2 -> V_8 , ! ! V_66 ) ;
F_11 ( & V_2 -> V_8 . V_30 -> V_8 . V_31 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
return V_70 ;
}
static T_1 F_28 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
struct V_52 * V_53 = & V_2 -> V_8 . V_30 -> V_53 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( V_2 -> V_8 . V_71 ) {
F_7 ( V_2 -> V_8 . V_71 , V_2 -> V_8 . V_12 + V_57 ) ;
goto V_72;
}
if ( F_23 ( V_53 ) || F_29 ( & V_2 -> V_8 ) ) {
F_16 ( & V_2 -> V_8 ) ;
goto V_72;
}
F_22 ( V_2 ) ;
if ( F_24 ( V_53 ) < V_60 )
F_25 ( & V_2 -> V_8 ) ;
V_72:
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
return V_70 ;
}
static T_1 F_30 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned int V_73 , V_74 , V_75 = 0 ;
struct V_76 * V_8 = & V_2 -> V_8 . V_30 -> V_8 ;
unsigned long V_33 , V_38 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
while ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_77 ) {
V_74 = V_78 ;
V_2 -> V_8 . V_24 . V_73 ++ ;
V_73 = F_5 ( V_2 -> V_8 . V_12 + V_47 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_40 ) ;
if ( V_38 & V_79 ) {
F_7 ( V_79 , V_2 -> V_8 . V_12 + V_40 ) ;
if ( F_31 ( & V_2 -> V_8 ) )
continue;
}
if ( F_32 ( & V_2 -> V_8 , ( unsigned char ) V_73 ) )
continue;
if ( F_33 ( V_73 & V_80 ) ) {
if ( V_73 & V_81 )
V_2 -> V_8 . V_24 . V_82 ++ ;
else if ( V_73 & V_83 )
V_2 -> V_8 . V_24 . V_84 ++ ;
else if ( V_73 & V_85 )
V_2 -> V_8 . V_24 . V_86 ++ ;
if ( V_73 & V_87 )
V_2 -> V_8 . V_24 . V_88 ++ ;
if ( V_73 & V_2 -> V_8 . V_89 ) {
if ( ++ V_75 > 100 )
goto V_72;
continue;
}
V_73 &= V_2 -> V_8 . V_90 ;
if ( V_73 & V_81 )
V_74 = V_91 ;
else if ( V_73 & V_83 )
V_74 = V_92 ;
else if ( V_73 & V_85 )
V_74 = V_93 ;
if ( V_73 & V_87 )
V_74 = V_94 ;
#ifdef F_34
V_2 -> V_8 . V_95 = 0 ;
#endif
}
F_35 ( V_8 , V_73 , V_74 ) ;
}
V_72:
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_36 ( V_8 ) ;
return V_70 ;
}
static T_1 F_37 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned int V_96 ;
unsigned int V_97 ;
V_96 = F_5 ( V_2 -> V_8 . V_12 + V_68 ) ;
if ( V_96 & V_98 )
F_30 ( V_64 , V_65 ) ;
if ( V_96 & V_99 &&
F_5 ( V_2 -> V_8 . V_12 + V_13 ) & V_43 )
F_28 ( V_64 , V_65 ) ;
if ( V_96 & V_67 )
F_27 ( V_64 , V_65 ) ;
if ( V_96 & V_100 )
F_7 ( V_100 , V_2 -> V_8 . V_12 + V_68 ) ;
V_97 = F_5 ( V_2 -> V_8 . V_12 + V_40 ) ;
if ( V_97 & V_61 ) {
F_38 ( V_2 -> V_8 . V_101 , L_1 ) ;
V_2 -> V_8 . V_24 . V_88 ++ ;
F_7 ( V_97 | V_61 , V_2 -> V_8 . V_12 + V_40 ) ;
}
return V_70 ;
}
static unsigned int F_39 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ? V_102 : 0 ;
}
static unsigned int F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_103 = V_26 | V_28 ;
if ( F_5 ( V_2 -> V_8 . V_12 + V_68 ) & V_69 )
V_103 |= V_29 ;
if ( F_5 ( V_2 -> V_8 . V_12 + V_15 ) & V_104 )
V_103 |= V_105 ;
return V_103 ;
}
static void F_41 ( struct V_7 * V_8 , unsigned int V_106 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) & ~ V_104 ;
if ( V_106 & V_105 )
V_38 |= V_104 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
}
static void F_42 ( struct V_7 * V_8 , int V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_33 , V_38 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) & ~ V_108 ;
if ( V_107 != 0 )
V_38 |= V_108 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned int V_109 )
{
unsigned int V_66 ;
V_66 = F_5 ( V_2 -> V_8 . V_12 + V_110 ) & ( V_111 | V_112 ) ;
V_66 |= V_113 << V_114 | V_115 ;
F_7 ( V_66 , V_2 -> V_8 . V_12 + V_110 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_116 ;
unsigned long V_33 , V_38 ;
if ( ! F_45 ( V_8 ) ) {
V_116 = F_46 ( V_2 -> V_117 ) ;
if ( V_116 )
goto V_118;
V_116 = F_46 ( V_2 -> V_119 ) ;
if ( V_116 ) {
F_47 ( V_2 -> V_117 ) ;
goto V_118;
}
}
F_43 ( V_2 , 0 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
if ( F_17 ( V_2 ) )
V_38 |= V_120 ;
V_38 &= ~ ( V_121 << V_122 ) ;
V_38 |= V_123 << V_122 ;
F_7 ( V_38 & ~ V_50 , V_2 -> V_8 . V_12 + V_45 ) ;
if ( F_17 ( V_2 ) ) {
int V_124 = 100 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 &= ~ V_125 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_15 ) & V_125 ) &&
( -- V_124 > 0 ) ) {
F_18 ( 1 ) ;
}
}
if ( V_2 -> V_126 > 0 ) {
V_116 = F_48 ( V_2 -> V_127 , F_30 , 0 ,
V_128 , V_2 ) ;
if ( V_116 )
goto V_118;
V_116 = F_48 ( V_2 -> V_126 , F_28 , 0 ,
V_128 , V_2 ) ;
if ( V_116 )
goto V_129;
if ( ! F_17 ( V_2 ) ) {
V_116 = F_48 ( V_2 -> V_130 , F_27 , 0 ,
V_128 , V_2 ) ;
if ( V_116 )
goto V_131;
}
} else {
V_116 = F_48 ( V_2 -> V_8 . V_64 , F_37 , 0 ,
V_128 , V_2 ) ;
if ( V_116 ) {
F_49 ( V_2 -> V_8 . V_64 , V_2 ) ;
goto V_118;
}
}
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_7 ( V_67 , V_2 -> V_8 . V_12 + V_68 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 |= V_49 | V_132 | V_133 ;
if ( F_17 ( V_2 ) ) {
V_38 |= V_134 ;
V_38 &= ~ ( V_132 ) ;
}
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 |= ( V_51 | V_135 ) ;
if ( ! V_2 -> V_136 )
V_38 |= V_137 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_17 ( V_2 ) ) {
int V_124 = 64 ;
while ( ( -- V_124 > 0 ) &&
( F_5 ( V_2 -> V_8 . V_12 + V_47 ) & V_48 ) ) {
F_19 () ;
}
}
if ( F_3 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_38 |= V_138 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
if ( F_17 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
if ( V_2 -> V_139 )
V_38 |= V_140 ;
else
V_38 &= ~ ( V_140 ) ;
F_7 ( V_38 | V_50 , V_2 -> V_8 . V_12 + V_45 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 -> V_141 )
V_38 |= V_142 ;
else
V_38 &= ~ ( V_142 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( F_17 ( V_2 ) ) {
struct V_143 * V_144 ;
V_144 = V_2 -> V_8 . V_101 -> V_145 ;
V_2 -> V_139 = V_144 -> V_139 ;
V_2 -> V_141 = V_144 -> V_141 ;
V_2 -> V_42 = V_144 -> V_146 ;
if ( V_144 -> V_147 )
V_144 -> V_147 ( 1 ) ;
}
return 0 ;
V_131:
if ( V_2 -> V_126 )
F_49 ( V_2 -> V_126 , V_2 ) ;
V_129:
if ( V_2 -> V_127 )
F_49 ( V_2 -> V_127 , V_2 ) ;
V_118:
return V_116 ;
}
static void F_50 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 &= ~ ( V_135 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( F_17 ( V_2 ) ) {
struct V_143 * V_144 ;
V_144 = V_2 -> V_8 . V_101 -> V_145 ;
if ( V_144 -> V_147 )
V_144 -> V_147 ( 0 ) ;
}
F_51 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_126 > 0 ) {
if ( ! F_17 ( V_2 ) )
F_49 ( V_2 -> V_130 , V_2 ) ;
F_49 ( V_2 -> V_126 , V_2 ) ;
F_49 ( V_2 -> V_127 , V_2 ) ;
} else
F_49 ( V_2 -> V_8 . V_64 , V_2 ) ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 &= ~ ( V_43 | V_49 | V_132 | V_133 ) ;
if ( F_17 ( V_2 ) )
V_38 &= ~ ( V_134 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( ! F_45 ( & V_2 -> V_8 ) ) {
F_47 ( V_2 -> V_117 ) ;
F_47 ( V_2 -> V_119 ) ;
}
}
static void
F_52 ( struct V_7 * V_8 , struct V_148 * V_149 ,
struct V_148 * V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_33 ;
unsigned int V_14 , V_151 , V_152 , V_153 , V_154 ;
unsigned int V_155 = V_150 ? V_150 -> V_156 & V_157 : V_158 ;
unsigned int div , V_159 ;
unsigned long V_160 , V_161 ;
T_2 V_162 ;
if ( 0 ) {
V_149 -> V_156 &= ~ ( V_163 | V_164 | V_165 ) ;
V_149 -> V_156 |= V_166 ;
}
while ( ( V_149 -> V_156 & V_157 ) != V_167 &&
( V_149 -> V_156 & V_157 ) != V_158 ) {
V_149 -> V_156 &= ~ V_157 ;
V_149 -> V_156 |= V_155 ;
V_155 = V_158 ;
}
if ( ( V_149 -> V_156 & V_157 ) == V_158 )
V_14 = V_168 | V_125 | V_137 ;
else
V_14 = V_125 | V_137 ;
if ( V_149 -> V_156 & V_164 ) {
if ( V_2 -> V_136 ) {
V_14 &= ~ V_137 ;
V_14 |= V_169 ;
} else {
V_149 -> V_156 &= ~ V_164 ;
}
}
if ( V_149 -> V_156 & V_170 )
V_14 |= V_171 ;
if ( V_149 -> V_156 & V_172 ) {
V_14 |= V_173 ;
if ( V_149 -> V_156 & V_174 )
V_14 |= V_175 ;
}
F_51 ( & V_2 -> V_35 ) ;
V_153 = F_53 ( V_8 , V_149 , V_150 , 50 , V_8 -> V_176 / 16 ) ;
V_154 = F_54 ( V_8 , V_153 ) ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_2 -> V_8 . V_90 = 0 ;
if ( V_149 -> V_177 & V_178 )
V_2 -> V_8 . V_90 |= ( V_85 | V_83 ) ;
if ( V_149 -> V_177 & ( V_179 | V_180 ) )
V_2 -> V_8 . V_90 |= V_81 ;
V_2 -> V_8 . V_89 = 0 ;
if ( V_149 -> V_177 & V_181 )
V_2 -> V_8 . V_89 |= V_83 ;
if ( V_149 -> V_177 & V_182 ) {
V_2 -> V_8 . V_89 |= V_81 ;
if ( V_149 -> V_177 & V_181 )
V_2 -> V_8 . V_89 |= V_87 ;
}
F_55 ( V_8 , V_149 -> V_156 , V_153 ) ;
V_151 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_151 & ~ ( V_43 | V_49 | V_132 ) ,
V_2 -> V_8 . V_12 + V_13 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) )
F_19 () ;
V_152 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
F_7 ( V_152 & ~ ( V_135 | V_51 ) ,
V_2 -> V_8 . V_12 + V_15 ) ;
V_152 &= ( V_135 | V_51 ) ;
if ( F_17 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_8 . V_176 / ( V_153 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_56 ( 16 * div * V_153 , V_2 -> V_8 . V_176 ,
1 << 16 , 1 << 16 , & V_160 , & V_161 ) ;
V_162 = V_2 -> V_8 . V_176 ;
V_162 *= V_160 ;
F_57 ( V_162 , V_161 * 16 * div ) ;
F_58 ( V_149 ,
( V_183 ) V_162 , ( V_183 ) V_162 ) ;
V_160 -= 1 ;
V_161 -= 1 ;
V_159 = F_5 ( V_2 -> V_8 . V_12 + V_110 ) ;
V_159 = ( V_159 & ( ~ V_111 ) ) | F_59 ( div ) ;
if ( V_2 -> V_184 )
V_159 |= V_112 ;
F_7 ( V_159 , V_2 -> V_8 . V_12 + V_110 ) ;
F_7 ( V_160 , V_2 -> V_8 . V_12 + V_185 ) ;
F_7 ( V_161 , V_2 -> V_8 . V_12 + V_186 ) ;
if ( F_3 ( V_2 ) )
F_7 ( V_2 -> V_8 . V_176 / div / 1000 ,
V_2 -> V_8 . V_12 + V_187 ) ;
F_7 ( V_151 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_14 | V_152 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_60 ( & V_2 -> V_8 , V_149 -> V_156 ) )
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static const char * F_61 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_188 ? L_2 : NULL ;
}
static void F_62 ( struct V_7 * V_8 )
{
struct V_189 * V_190 = F_63 ( V_8 -> V_101 ) ;
struct V_191 * V_192 ;
V_192 = F_64 ( V_190 , V_193 , 0 ) ;
F_65 ( V_192 -> V_194 , F_66 ( V_192 ) ) ;
}
static int F_67 ( struct V_7 * V_8 )
{
struct V_189 * V_190 = F_63 ( V_8 -> V_101 ) ;
struct V_191 * V_192 ;
void * V_195 ;
V_192 = F_64 ( V_190 , V_193 , 0 ) ;
if ( ! V_192 )
return - V_196 ;
V_195 = F_68 ( V_192 -> V_194 , F_66 ( V_192 ) , L_3 ) ;
return V_195 ? 0 : - V_197 ;
}
static void F_69 ( struct V_7 * V_8 , int V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( V_33 & V_198 &&
F_67 ( & V_2 -> V_8 ) == 0 )
V_2 -> V_8 . type = V_188 ;
}
static int
F_70 ( struct V_7 * V_8 , struct V_199 * V_200 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_195 = 0 ;
if ( V_200 -> type != V_201 && V_200 -> type != V_188 )
V_195 = - V_202 ;
if ( V_2 -> V_8 . V_64 != V_200 -> V_64 )
V_195 = - V_202 ;
if ( V_200 -> V_203 != V_204 )
V_195 = - V_202 ;
if ( V_2 -> V_8 . V_176 / 16 != V_200 -> V_205 )
V_195 = - V_202 ;
if ( ( void * ) V_2 -> V_8 . V_206 != V_200 -> V_207 )
V_195 = - V_202 ;
if ( V_2 -> V_8 . V_208 != V_200 -> V_8 )
V_195 = - V_202 ;
if ( V_200 -> V_209 != 0 )
V_195 = - V_202 ;
return V_195 ;
}
static int F_71 ( struct V_7 * V_8 )
{
struct V_9 V_210 ;
unsigned int V_18 ;
unsigned char V_211 ;
F_4 ( V_8 , & V_210 ) ;
F_7 ( V_133 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_210 . V_14 & ~ ( V_212 | V_213 | V_214 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_210 . V_16 & ~ ( V_215 | V_216 | V_217 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_77 );
V_211 = F_5 ( V_8 -> V_12 + V_47 ) ;
F_6 ( V_8 , & V_210 ) ;
return V_211 ;
}
static void F_72 ( struct V_7 * V_8 , unsigned char V_211 )
{
struct V_9 V_210 ;
unsigned int V_18 ;
F_4 ( V_8 , & V_210 ) ;
F_7 ( V_133 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_210 . V_14 & ~ ( V_212 | V_213 | V_214 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_210 . V_16 & ~ ( V_215 | V_216 | V_217 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_68 ) ;
} while ( ~ V_18 & V_99 );
F_7 ( V_211 , V_8 -> V_12 + V_57 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_41 );
F_6 ( V_8 , & V_210 ) ;
}
static void F_73 ( struct V_7 * V_8 , int V_218 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_5 ( V_2 -> V_8 . V_12 + F_1 ( V_2 ) ) & V_54 )
F_19 () ;
F_7 ( V_218 , V_2 -> V_8 . V_12 + V_57 ) ;
}
static void
F_74 ( struct V_219 * V_220 , const char * V_221 , unsigned int V_222 )
{
struct V_1 * V_2 = V_223 [ V_220 -> V_224 ] ;
struct V_9 V_210 ;
unsigned int V_11 ;
unsigned long V_33 = 0 ;
int V_225 = 1 ;
if ( V_2 -> V_8 . V_95 )
V_225 = 0 ;
else if ( V_226 )
V_225 = F_75 ( & V_2 -> V_8 . V_34 , V_33 ) ;
else
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_4 ( & V_2 -> V_8 , & V_210 ) ;
V_11 = V_210 . V_11 ;
if ( F_2 ( V_2 ) )
V_11 |= V_227 ;
V_11 |= V_133 ;
V_11 &= ~ ( V_43 | V_49 | V_132 ) ;
F_7 ( V_11 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_210 . V_14 | V_135 , V_2 -> V_8 . V_12 + V_15 ) ;
F_76 ( & V_2 -> V_8 , V_221 , V_222 , F_73 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ) ;
F_6 ( & V_2 -> V_8 , & V_210 ) ;
if ( V_225 )
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static void T_3
F_77 ( struct V_1 * V_2 , int * V_153 ,
int * V_84 , int * V_228 )
{
if ( F_5 ( V_2 -> V_8 . V_12 + V_13 ) & V_133 ) {
unsigned int V_14 , V_229 , V_230 , V_176 ;
unsigned int V_231 ;
unsigned int V_232 ;
V_14 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
* V_84 = 'n' ;
if ( V_14 & V_173 ) {
if ( V_14 & V_175 )
* V_84 = 'o' ;
else
* V_84 = 'e' ;
}
if ( V_14 & V_168 )
* V_228 = 8 ;
else
* V_228 = 7 ;
V_229 = F_5 ( V_2 -> V_8 . V_12 + V_185 ) & 0xffff ;
V_230 = F_5 ( V_2 -> V_8 . V_12 + V_186 ) & 0xffff ;
V_232 = ( F_5 ( V_2 -> V_8 . V_12 + V_110 ) & V_111 ) >> 7 ;
if ( V_232 == 6 )
V_232 = 7 ;
else
V_232 = 6 - V_232 ;
V_176 = F_78 ( V_2 -> V_117 ) ;
V_176 /= V_232 ;
{
unsigned int V_233 = V_229 + 1 ;
unsigned int div = 16 * ( V_230 + 1 ) ;
unsigned int V_234 = V_176 % div ;
V_231 = ( V_176 / div ) * V_233 ;
V_231 += ( V_234 * V_233 + div / 2 ) / div ;
* V_153 = ( V_231 + 50 ) / 100 * 100 ;
}
if ( * V_153 != V_231 )
F_79 ( L_4 ,
V_231 , * V_153 ) ;
}
}
static int T_3
F_80 ( struct V_219 * V_220 , char * V_235 )
{
struct V_1 * V_2 ;
int V_153 = 9600 ;
int V_228 = 8 ;
int V_84 = 'n' ;
int V_236 = 'n' ;
if ( V_220 -> V_224 == - 1 || V_220 -> V_224 >= F_81 ( V_223 ) )
V_220 -> V_224 = 0 ;
V_2 = V_223 [ V_220 -> V_224 ] ;
if ( V_2 == NULL )
return - V_196 ;
if ( V_235 )
F_82 ( V_235 , & V_153 , & V_84 , & V_228 , & V_236 ) ;
else
F_77 ( V_2 , & V_153 , & V_84 , & V_228 ) ;
F_43 ( V_2 , 0 ) ;
return F_83 ( & V_2 -> V_8 , V_220 , V_153 , V_84 , V_228 , V_236 ) ;
}
static int F_84 ( struct V_189 * V_101 , T_4 V_30 )
{
struct V_1 * V_2 = F_85 ( V_101 ) ;
unsigned int V_66 ;
V_66 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_66 |= V_237 ;
F_7 ( V_66 , V_2 -> V_8 . V_12 + V_17 ) ;
F_86 ( & V_238 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_87 ( struct V_189 * V_101 )
{
struct V_1 * V_2 = F_85 ( V_101 ) ;
unsigned int V_66 ;
V_66 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_66 &= ~ V_237 ;
F_7 ( V_66 , V_2 -> V_8 . V_12 + V_17 ) ;
F_88 ( & V_238 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
struct V_239 * V_240 = V_190 -> V_101 . V_241 ;
const struct V_242 * V_243 =
F_90 ( V_244 , & V_190 -> V_101 ) ;
int V_195 ;
if ( ! V_240 )
return 1 ;
V_195 = F_91 ( V_240 , L_5 ) ;
if ( V_195 < 0 ) {
F_38 ( & V_190 -> V_101 , L_6 , V_195 ) ;
return V_195 ;
}
V_2 -> V_8 . line = V_195 ;
if ( F_92 ( V_240 , L_7 , NULL ) )
V_2 -> V_136 = 1 ;
if ( F_92 ( V_240 , L_8 , NULL ) )
V_2 -> V_245 = 1 ;
if ( F_92 ( V_240 , L_9 , NULL ) )
V_2 -> V_184 = 1 ;
V_2 -> V_3 = V_243 -> V_32 ;
return 0 ;
}
static inline int F_89 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
return 1 ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
struct V_143 * V_144 = V_190 -> V_101 . V_145 ;
V_2 -> V_8 . line = V_190 -> V_246 ;
V_2 -> V_3 = (struct V_247 * ) V_190 -> V_248 -> V_249 ;
if ( ! V_144 )
return;
if ( V_144 -> V_33 & V_250 )
V_2 -> V_136 = 1 ;
if ( V_144 -> V_33 & V_251 )
V_2 -> V_245 = 1 ;
}
static int F_94 ( struct V_189 * V_190 )
{
struct V_1 * V_2 ;
struct V_143 * V_144 ;
void T_5 * V_252 ;
int V_195 = 0 ;
struct V_191 * V_253 ;
struct V_254 * V_254 ;
V_2 = F_95 ( & V_190 -> V_101 , sizeof( * V_2 ) , V_255 ) ;
if ( ! V_2 )
return - V_256 ;
V_195 = F_89 ( V_2 , V_190 ) ;
if ( V_195 > 0 )
F_93 ( V_2 , V_190 ) ;
else if ( V_195 < 0 )
return V_195 ;
V_253 = F_64 ( V_190 , V_193 , 0 ) ;
if ( ! V_253 )
return - V_196 ;
V_252 = F_96 ( & V_190 -> V_101 , V_253 -> V_194 , V_257 ) ;
if ( ! V_252 )
return - V_256 ;
V_2 -> V_8 . V_101 = & V_190 -> V_101 ;
V_2 -> V_8 . V_206 = V_253 -> V_194 ;
V_2 -> V_8 . V_12 = V_252 ;
V_2 -> V_8 . type = V_188 ,
V_2 -> V_8 . V_258 = V_204 ;
V_2 -> V_8 . V_64 = F_97 ( V_190 , 0 ) ;
V_2 -> V_127 = F_97 ( V_190 , 0 ) ;
V_2 -> V_126 = F_97 ( V_190 , 1 ) ;
V_2 -> V_130 = F_97 ( V_190 , 2 ) ;
V_2 -> V_8 . V_259 = 32 ;
V_2 -> V_8 . V_20 = & V_260 ;
V_2 -> V_8 . V_33 = V_261 ;
F_98 ( & V_2 -> V_35 ) ;
V_2 -> V_35 . V_262 = F_12 ;
V_2 -> V_35 . V_32 = ( unsigned long ) V_2 ;
V_254 = F_99 ( & V_190 -> V_101 ) ;
if ( F_100 ( V_254 ) ) {
V_195 = F_101 ( V_254 ) ;
F_38 ( & V_190 -> V_101 , L_10 , V_195 ) ;
return V_195 ;
}
V_2 -> V_119 = F_102 ( & V_190 -> V_101 , L_11 ) ;
if ( F_100 ( V_2 -> V_119 ) ) {
V_195 = F_101 ( V_2 -> V_119 ) ;
F_38 ( & V_190 -> V_101 , L_12 , V_195 ) ;
return V_195 ;
}
V_2 -> V_117 = F_102 ( & V_190 -> V_101 , L_13 ) ;
if ( F_100 ( V_2 -> V_117 ) ) {
V_195 = F_101 ( V_2 -> V_117 ) ;
F_38 ( & V_190 -> V_101 , L_14 , V_195 ) ;
return V_195 ;
}
F_46 ( V_2 -> V_117 ) ;
F_46 ( V_2 -> V_119 ) ;
V_2 -> V_8 . V_176 = F_78 ( V_2 -> V_117 ) ;
V_223 [ V_2 -> V_8 . line ] = V_2 ;
V_144 = V_190 -> V_101 . V_145 ;
if ( V_144 && V_144 -> V_263 ) {
V_195 = V_144 -> V_263 ( V_190 ) ;
if ( V_195 )
goto V_264;
}
V_195 = F_103 ( & V_238 , & V_2 -> V_8 ) ;
if ( V_195 )
goto V_265;
F_104 ( V_190 , V_2 ) ;
if ( ! F_45 ( & V_2 -> V_8 ) ) {
F_47 ( V_2 -> V_117 ) ;
F_47 ( V_2 -> V_119 ) ;
}
return 0 ;
V_265:
if ( V_144 && V_144 -> exit )
V_144 -> exit ( V_190 ) ;
V_264:
F_47 ( V_2 -> V_117 ) ;
F_47 ( V_2 -> V_119 ) ;
return V_195 ;
}
static int F_105 ( struct V_189 * V_190 )
{
struct V_143 * V_144 ;
struct V_1 * V_2 = F_85 ( V_190 ) ;
V_144 = V_190 -> V_101 . V_145 ;
F_104 ( V_190 , NULL ) ;
F_106 ( & V_238 , & V_2 -> V_8 ) ;
if ( V_144 && V_144 -> exit )
V_144 -> exit ( V_190 ) ;
return 0 ;
}
static int T_3 F_107 ( void )
{
int V_195 ;
F_79 ( L_15 ) ;
V_195 = F_108 ( & V_238 ) ;
if ( V_195 )
return V_195 ;
V_195 = F_109 ( & V_266 ) ;
if ( V_195 != 0 )
F_110 ( & V_238 ) ;
return V_195 ;
}
static void T_6 F_111 ( void )
{
F_112 ( & V_266 ) ;
F_110 ( & V_238 ) ;
}
