static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
V_3 = V_2 -> V_5 . V_6 -> V_7 ( & V_2 -> V_5 ) ;
V_4 = V_3 ^ V_2 -> V_8 ;
if ( V_4 == 0 )
return;
V_2 -> V_8 = V_3 ;
if ( V_4 & V_9 )
V_2 -> V_5 . V_10 . V_11 ++ ;
if ( V_4 & V_12 )
V_2 -> V_5 . V_10 . V_13 ++ ;
if ( V_4 & V_14 )
F_2 ( & V_2 -> V_5 , V_3 & V_14 ) ;
if ( V_4 & V_15 )
F_3 ( & V_2 -> V_5 , V_3 & V_15 ) ;
F_4 ( & V_2 -> V_5 . V_16 -> V_5 . V_17 ) ;
}
static void F_5 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
unsigned long V_19 ;
if ( V_2 -> V_5 . V_16 ) {
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
F_8 ( & V_2 -> V_21 , V_22 + V_23 ) ;
}
}
static void F_9 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_25 ;
if ( F_10 ( V_2 ) ) {
int V_26 = 256 ;
while ( ( -- V_26 > 0 ) &&
! ( F_11 ( V_2 -> V_5 . V_27 + V_28 ) & V_29 ) ) {
F_12 ( 5 ) ;
F_13 () ;
}
F_12 ( V_2 -> V_30 ) ;
if ( F_11 ( V_2 -> V_5 . V_27 + V_28 ) & V_29 ) {
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
V_25 &= ~ ( V_32 | V_33 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_31 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_34 ) ;
V_25 &= ~ ( V_35 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_34 ) ;
while ( F_11 ( V_2 -> V_5 . V_27 + V_36 ) &
V_37 )
F_13 () ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
V_25 |= V_38 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_31 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_34 ) ;
V_25 |= V_39 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_34 ) ;
}
return;
}
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
F_14 ( V_25 & ~ V_32 , V_2 -> V_5 . V_27 + V_31 ) ;
}
static void F_15 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_25 ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) ;
F_14 ( V_25 & ~ V_41 , V_2 -> V_5 . V_27 + V_40 ) ;
}
static void F_16 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
F_8 ( & V_2 -> V_21 , V_22 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_5 . V_16 -> V_43 ;
while ( ! F_18 ( V_43 ) &&
! ( F_11 ( V_2 -> V_5 . V_27 + V_44 ) & V_45 ) ) {
F_14 ( V_43 -> V_46 [ V_43 -> V_47 ] , V_2 -> V_5 . V_27 + V_48 ) ;
V_43 -> V_47 = ( V_43 -> V_47 + 1 ) & ( V_49 - 1 ) ;
V_2 -> V_5 . V_10 . V_50 ++ ;
}
if ( F_19 ( V_43 ) < V_51 )
F_20 ( & V_2 -> V_5 ) ;
if ( F_18 ( V_43 ) )
F_9 ( & V_2 -> V_5 ) ;
}
static void F_21 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_25 ;
if ( F_10 ( V_2 ) ) {
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_34 ) ;
V_25 &= ~ ( V_39 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_34 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
V_25 &= ~ ( V_38 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_31 ) ;
}
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
F_14 ( V_25 | V_32 , V_2 -> V_5 . V_27 + V_31 ) ;
if ( F_10 ( V_2 ) ) {
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
V_25 |= V_33 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_31 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_34 ) ;
V_25 |= V_35 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_34 ) ;
}
if ( F_11 ( V_2 -> V_5 . V_27 + V_44 ) & V_52 )
F_17 ( V_2 ) ;
}
static T_1 F_22 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
unsigned int V_55 ;
unsigned long V_19 ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
F_14 ( V_56 , V_2 -> V_5 . V_27 + V_57 ) ;
V_55 = F_11 ( V_2 -> V_5 . V_27 + V_57 ) & V_58 ;
F_3 ( & V_2 -> V_5 , ! ! V_55 ) ;
F_4 ( & V_2 -> V_5 . V_16 -> V_5 . V_17 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
return V_59 ;
}
static T_1 F_23 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
struct V_42 * V_43 = & V_2 -> V_5 . V_16 -> V_43 ;
unsigned long V_19 ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
if ( V_2 -> V_5 . V_60 )
{
F_14 ( V_2 -> V_5 . V_60 , V_2 -> V_5 . V_27 + V_48 ) ;
goto V_61;
}
if ( F_18 ( V_43 ) || F_24 ( & V_2 -> V_5 ) ) {
F_9 ( & V_2 -> V_5 ) ;
goto V_61;
}
F_17 ( V_2 ) ;
if ( F_19 ( V_43 ) < V_51 )
F_20 ( & V_2 -> V_5 ) ;
V_61:
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
return V_59 ;
}
static T_1 F_25 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
unsigned int V_62 , V_63 , V_64 = 0 ;
struct V_65 * V_66 = V_2 -> V_5 . V_16 -> V_5 . V_66 ;
unsigned long V_19 , V_25 ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
while ( F_11 ( V_2 -> V_5 . V_27 + V_28 ) & V_67 ) {
V_63 = V_68 ;
V_2 -> V_5 . V_10 . V_62 ++ ;
V_62 = F_11 ( V_2 -> V_5 . V_27 + V_36 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_28 ) ;
if ( V_25 & V_69 ) {
F_14 ( V_69 , V_2 -> V_5 . V_27 + V_28 ) ;
if ( F_26 ( & V_2 -> V_5 ) )
continue;
}
if ( F_27 ( & V_2 -> V_5 , ( unsigned char ) V_62 ) )
continue;
if ( V_62 & ( V_70 | V_71 | V_72 ) ) {
if ( V_62 & V_70 )
V_2 -> V_5 . V_10 . V_73 ++ ;
else if ( V_62 & V_72 )
V_2 -> V_5 . V_10 . V_74 ++ ;
if ( V_62 & V_71 )
V_2 -> V_5 . V_10 . V_75 ++ ;
if ( V_62 & V_2 -> V_5 . V_76 ) {
if ( ++ V_64 > 100 )
goto V_61;
continue;
}
V_62 &= V_2 -> V_5 . V_77 ;
if ( V_62 & V_70 )
V_63 = V_78 ;
else if ( V_62 & V_72 )
V_63 = V_79 ;
if ( V_62 & V_71 )
V_63 = V_80 ;
#ifdef F_28
V_2 -> V_5 . V_81 = 0 ;
#endif
}
F_29 ( V_66 , V_62 , V_63 ) ;
}
V_61:
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
F_30 ( V_66 ) ;
return V_59 ;
}
static T_1 F_31 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
unsigned int V_82 ;
V_82 = F_11 ( V_2 -> V_5 . V_27 + V_57 ) ;
if ( V_82 & V_83 )
F_25 ( V_53 , V_54 ) ;
if ( V_82 & V_84 &&
F_11 ( V_2 -> V_5 . V_27 + V_31 ) & V_32 )
F_23 ( V_53 , V_54 ) ;
if ( V_82 & V_56 )
F_22 ( V_53 , V_54 ) ;
return V_59 ;
}
static unsigned int F_32 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return ( F_11 ( V_2 -> V_5 . V_27 + V_28 ) & V_29 ) ? V_85 : 0 ;
}
static unsigned int F_33 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned int V_86 = V_12 | V_14 ;
if ( F_11 ( V_2 -> V_5 . V_27 + V_57 ) & V_58 )
V_86 |= V_15 ;
if ( F_11 ( V_2 -> V_5 . V_27 + V_40 ) & V_87 )
V_86 |= V_88 ;
return V_86 ;
}
static void F_34 ( struct V_24 * V_5 , unsigned int V_89 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_25 ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) & ~ V_87 ;
if ( V_89 & V_88 )
V_25 |= V_87 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_40 ) ;
}
static void F_35 ( struct V_24 * V_5 , int V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_19 , V_25 ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) & ~ V_91 ;
if ( V_90 != 0 )
V_25 |= V_91 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_31 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_92 )
{
unsigned int V_55 ;
unsigned int V_93 ;
V_55 = V_94 << 10 | V_95 ;
V_93 = ( F_37 ( V_2 -> V_96 ) + V_2 -> V_5 . V_97 / 2 )
/ V_2 -> V_5 . V_97 ;
if( ! V_93 )
V_93 = 1 ;
V_55 |= F_38 ( V_93 ) ;
F_14 ( V_55 , V_2 -> V_5 . V_27 + V_98 ) ;
return 0 ;
}
static int F_39 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
int V_99 ;
unsigned long V_19 , V_25 ;
F_36 ( V_2 , 0 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_34 ) ;
if ( F_10 ( V_2 ) )
V_25 |= V_100 ;
V_25 &= ~ ( V_101 << V_102 ) ;
V_25 |= V_103 << V_102 ;
F_14 ( V_25 & ~ V_39 , V_2 -> V_5 . V_27 + V_34 ) ;
if ( F_10 ( V_2 ) ) {
int V_104 = 100 ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) ;
V_25 &= ~ V_105 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_40 ) ;
while ( ! ( F_11 ( V_2 -> V_5 . V_27 + V_40 ) & V_105 ) &&
( -- V_104 > 0 ) ) {
F_12 ( 1 ) ;
}
}
if ( V_2 -> V_106 > 0 ) {
V_99 = F_40 ( V_2 -> V_107 , F_25 , 0 ,
V_108 , V_2 ) ;
if ( V_99 )
goto V_109;
V_99 = F_40 ( V_2 -> V_106 , F_23 , 0 ,
V_108 , V_2 ) ;
if ( V_99 )
goto V_110;
if ( ! F_10 ( V_2 ) ) {
V_99 = F_40 ( V_2 -> V_111 , F_22 ,
( V_2 -> V_111 < V_112 ) ? 0 :
V_113 |
V_114 ,
V_108 , V_2 ) ;
if ( V_99 )
goto V_115;
}
} else {
V_99 = F_40 ( V_2 -> V_5 . V_53 , F_31 , 0 ,
V_108 , V_2 ) ;
if ( V_99 ) {
F_41 ( V_2 -> V_5 . V_53 , V_2 ) ;
goto V_109;
}
}
F_14 ( V_56 , V_2 -> V_5 . V_27 + V_57 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
V_25 |= V_38 | V_116 | V_117 ;
if ( F_10 ( V_2 ) ) {
V_25 |= V_118 ;
V_25 &= ~ ( V_116 ) ;
}
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_31 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) ;
V_25 |= ( V_41 | V_119 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_40 ) ;
if ( F_10 ( V_2 ) ) {
int V_104 = 64 ;
while ( ( -- V_104 > 0 ) &&
( F_11 ( V_2 -> V_5 . V_27 + V_36 ) & V_37 ) ) {
F_13 () ;
}
}
if ( ! F_42 () ) {
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_120 ) ;
V_25 |= V_121 ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_120 ) ;
}
if ( F_10 ( V_2 ) ) {
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_34 ) ;
if ( V_2 -> V_122 )
V_25 |= V_123 ;
else
V_25 &= ~ ( V_123 ) ;
F_14 ( V_25 | V_39 , V_2 -> V_5 . V_27 + V_34 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_120 ) ;
if ( V_2 -> V_124 )
V_25 |= V_125 ;
else
V_25 &= ~ ( V_125 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_120 ) ;
}
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
F_16 ( & V_2 -> V_5 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
if ( F_10 ( V_2 ) ) {
struct V_126 * V_127 ;
V_127 = V_2 -> V_5 . V_128 -> V_129 ;
V_2 -> V_122 = V_127 -> V_122 ;
V_2 -> V_124 = V_127 -> V_124 ;
V_2 -> V_30 = V_127 -> V_130 ;
if ( V_127 -> V_131 )
V_127 -> V_131 ( 1 ) ;
}
return 0 ;
V_115:
if ( V_2 -> V_106 )
F_41 ( V_2 -> V_106 , V_2 ) ;
V_110:
if ( V_2 -> V_107 )
F_41 ( V_2 -> V_107 , V_2 ) ;
V_109:
return V_99 ;
}
static void F_43 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_25 ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) ;
V_25 &= ~ ( V_119 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_40 ) ;
if ( F_10 ( V_2 ) ) {
struct V_126 * V_127 ;
V_127 = V_2 -> V_5 . V_128 -> V_129 ;
if ( V_127 -> V_131 )
V_127 -> V_131 ( 0 ) ;
}
F_44 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_106 > 0 ) {
if ( ! F_10 ( V_2 ) )
F_41 ( V_2 -> V_111 , V_2 ) ;
F_41 ( V_2 -> V_106 , V_2 ) ;
F_41 ( V_2 -> V_107 , V_2 ) ;
} else
F_41 ( V_2 -> V_5 . V_53 , V_2 ) ;
V_25 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
V_25 &= ~ ( V_32 | V_38 | V_116 | V_117 ) ;
if ( F_10 ( V_2 ) )
V_25 &= ~ ( V_118 ) ;
F_14 ( V_25 , V_2 -> V_5 . V_27 + V_31 ) ;
}
static void
F_45 ( struct V_24 * V_5 , struct V_132 * V_133 ,
struct V_132 * V_134 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_19 ;
unsigned int V_135 , V_136 , V_137 , V_138 , V_139 ;
unsigned int V_140 = V_134 ? V_134 -> V_141 & V_142 : V_143 ;
unsigned int div , V_144 ;
unsigned long V_145 , V_146 ;
T_2 V_147 ;
if ( 0 ) {
V_133 -> V_141 &= ~ ( V_148 | V_149 | V_150 ) ;
V_133 -> V_141 |= V_151 ;
}
while ( ( V_133 -> V_141 & V_142 ) != V_152 &&
( V_133 -> V_141 & V_142 ) != V_143 ) {
V_133 -> V_141 &= ~ V_142 ;
V_133 -> V_141 |= V_140 ;
V_140 = V_143 ;
}
if ( ( V_133 -> V_141 & V_142 ) == V_143 )
V_135 = V_153 | V_105 | V_154 ;
else
V_135 = V_105 | V_154 ;
if ( V_133 -> V_141 & V_149 ) {
if( V_2 -> V_155 ) {
V_135 &= ~ V_154 ;
V_135 |= V_156 ;
} else {
V_133 -> V_141 &= ~ V_149 ;
}
}
if ( V_133 -> V_141 & V_157 )
V_135 |= V_158 ;
if ( V_133 -> V_141 & V_159 ) {
V_135 |= V_160 ;
if ( V_133 -> V_141 & V_161 )
V_135 |= V_162 ;
}
V_138 = F_46 ( V_5 , V_133 , V_134 , 50 , V_5 -> V_97 / 16 ) ;
V_139 = F_47 ( V_5 , V_138 ) ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
V_2 -> V_5 . V_77 = 0 ;
if ( V_133 -> V_163 & V_164 )
V_2 -> V_5 . V_77 |= ( V_72 | V_70 ) ;
if ( V_133 -> V_163 & ( V_165 | V_166 ) )
V_2 -> V_5 . V_77 |= V_167 ;
V_2 -> V_5 . V_76 = 0 ;
if ( V_133 -> V_163 & V_168 )
V_2 -> V_5 . V_76 |= V_70 ;
if ( V_133 -> V_163 & V_169 ) {
V_2 -> V_5 . V_76 |= V_167 ;
if ( V_133 -> V_163 & V_168 )
V_2 -> V_5 . V_76 |= V_71 ;
}
F_44 ( & V_2 -> V_21 ) ;
F_48 ( V_5 , V_133 -> V_141 , V_138 ) ;
V_136 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
F_14 ( V_136 & ~ ( V_32 | V_38 | V_116 ) ,
V_2 -> V_5 . V_27 + V_31 ) ;
while ( ! ( F_11 ( V_2 -> V_5 . V_27 + V_28 ) & V_29 ) )
F_13 () ;
V_137 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) ;
F_14 ( V_137 & ~ ( V_119 | V_41 ) ,
V_2 -> V_5 . V_27 + V_40 ) ;
V_137 &= ( V_119 | V_41 ) ;
if ( F_10 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_5 . V_97 / ( V_138 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_49 ( 16 * div * V_138 , V_2 -> V_5 . V_97 ,
1 << 16 , 1 << 16 , & V_145 , & V_146 ) ;
V_147 = V_2 -> V_5 . V_97 ;
V_147 *= V_145 ;
F_50 ( V_147 , V_146 * 16 * div ) ;
F_51 ( V_133 ,
( V_170 ) V_147 , ( V_170 ) V_147 ) ;
V_145 -= 1 ;
V_146 -= 1 ;
V_144 = F_11 ( V_2 -> V_5 . V_27 + V_98 ) ;
V_144 = ( V_144 & ( ~ V_171 ) ) | F_38 ( div ) ;
F_14 ( V_144 , V_2 -> V_5 . V_27 + V_98 ) ;
F_14 ( V_145 , V_2 -> V_5 . V_27 + V_172 ) ;
F_14 ( V_146 , V_2 -> V_5 . V_27 + V_173 ) ;
if ( ! F_42 () )
F_14 ( V_2 -> V_5 . V_97 / div / 1000 ,
V_2 -> V_5 . V_27 + V_174 ) ;
F_14 ( V_136 , V_2 -> V_5 . V_27 + V_31 ) ;
F_14 ( V_135 | V_137 , V_2 -> V_5 . V_27 + V_40 ) ;
if ( F_52 ( & V_2 -> V_5 , V_133 -> V_141 ) )
F_16 ( & V_2 -> V_5 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
}
static const char * F_53 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return V_2 -> V_5 . type == V_175 ? L_1 : NULL ;
}
static void F_54 ( struct V_24 * V_5 )
{
struct V_176 * V_177 = F_55 ( V_5 -> V_128 ) ;
struct V_178 * V_179 ;
V_179 = F_56 ( V_177 , V_180 , 0 ) ;
F_57 ( V_179 -> V_181 , V_179 -> V_182 - V_179 -> V_181 + 1 ) ;
}
static int F_58 ( struct V_24 * V_5 )
{
struct V_176 * V_177 = F_55 ( V_5 -> V_128 ) ;
struct V_178 * V_179 ;
void * V_183 ;
V_179 = F_56 ( V_177 , V_180 , 0 ) ;
if ( ! V_179 )
return - V_184 ;
V_183 = F_59 ( V_179 -> V_181 , V_179 -> V_182 - V_179 -> V_181 + 1 ,
L_2 ) ;
return V_183 ? 0 : - V_185 ;
}
static void F_60 ( struct V_24 * V_5 , int V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
if ( V_19 & V_186 &&
F_58 ( & V_2 -> V_5 ) == 0 )
V_2 -> V_5 . type = V_175 ;
}
static int
F_61 ( struct V_24 * V_5 , struct V_187 * V_188 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
int V_183 = 0 ;
if ( V_188 -> type != V_189 && V_188 -> type != V_175 )
V_183 = - V_190 ;
if ( V_2 -> V_5 . V_53 != V_188 -> V_53 )
V_183 = - V_190 ;
if ( V_188 -> V_191 != V_192 )
V_183 = - V_190 ;
if ( V_2 -> V_5 . V_97 / 16 != V_188 -> V_193 )
V_183 = - V_190 ;
if ( ( void * ) V_2 -> V_5 . V_194 != V_188 -> V_195 )
V_183 = - V_190 ;
if ( V_2 -> V_5 . V_196 != V_188 -> V_5 )
V_183 = - V_190 ;
if ( V_188 -> V_197 != 0 )
V_183 = - V_190 ;
return V_183 ;
}
static void F_62 ( struct V_24 * V_5 , int V_198 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
while ( F_11 ( V_2 -> V_5 . V_27 + V_44 ) & V_45 )
F_13 () ;
F_14 ( V_198 , V_2 -> V_5 . V_27 + V_48 ) ;
}
static void
F_63 ( struct V_199 * V_200 , const char * V_201 , unsigned int V_202 )
{
struct V_1 * V_2 = V_203 [ V_200 -> V_204 ] ;
unsigned int V_136 , V_205 , V_206 ;
V_206 = V_136 = F_11 ( V_2 -> V_5 . V_27 + V_31 ) ;
V_205 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) ;
if ( F_42 () )
V_206 |= V_207 ;
V_206 |= V_117 ;
V_206 &= ~ ( V_32 | V_38 | V_116 ) ;
F_14 ( V_206 , V_2 -> V_5 . V_27 + V_31 ) ;
F_14 ( V_205 | V_119 , V_2 -> V_5 . V_27 + V_40 ) ;
F_64 ( & V_2 -> V_5 , V_201 , V_202 , F_62 ) ;
while ( ! ( F_11 ( V_2 -> V_5 . V_27 + V_28 ) & V_29 ) ) ;
F_14 ( V_136 , V_2 -> V_5 . V_27 + V_31 ) ;
F_14 ( V_205 , V_2 -> V_5 . V_27 + V_40 ) ;
}
static void T_3
F_65 ( struct V_1 * V_2 , int * V_138 ,
int * V_73 , int * V_208 )
{
if ( F_11 ( V_2 -> V_5 . V_27 + V_31 ) & V_117 ) {
unsigned int V_135 , V_209 , V_210 , V_97 ;
unsigned int V_211 ;
unsigned int V_212 ;
V_135 = F_11 ( V_2 -> V_5 . V_27 + V_40 ) ;
* V_73 = 'n' ;
if ( V_135 & V_160 ) {
if ( V_135 & V_162 )
* V_73 = 'o' ;
else
* V_73 = 'e' ;
}
if ( V_135 & V_153 )
* V_208 = 8 ;
else
* V_208 = 7 ;
V_209 = F_11 ( V_2 -> V_5 . V_27 + V_172 ) & 0xffff ;
V_210 = F_11 ( V_2 -> V_5 . V_27 + V_173 ) & 0xffff ;
V_212 = ( F_11 ( V_2 -> V_5 . V_27 + V_98 ) & V_171 ) >> 7 ;
if ( V_212 == 6 )
V_212 = 7 ;
else
V_212 = 6 - V_212 ;
V_97 = F_37 ( V_2 -> V_96 ) ;
V_97 /= V_212 ;
{
unsigned int V_213 = V_209 + 1 ;
unsigned int div = 16 * ( V_210 + 1 ) ;
unsigned int V_214 = V_97 % div ;
V_211 = ( V_97 / div ) * V_213 ;
V_211 += ( V_214 * V_213 + div / 2 ) / div ;
* V_138 = ( V_211 + 50 ) / 100 * 100 ;
}
if( * V_138 != V_211 )
F_66 ( V_215 L_3 ,
V_211 , * V_138 ) ;
}
}
static int T_3
F_67 ( struct V_199 * V_200 , char * V_216 )
{
struct V_1 * V_2 ;
int V_138 = 9600 ;
int V_208 = 8 ;
int V_73 = 'n' ;
int V_217 = 'n' ;
if ( V_200 -> V_204 == - 1 || V_200 -> V_204 >= F_68 ( V_203 ) )
V_200 -> V_204 = 0 ;
V_2 = V_203 [ V_200 -> V_204 ] ;
if( V_2 == NULL )
return - V_184 ;
if ( V_216 )
F_69 ( V_216 , & V_138 , & V_73 , & V_208 , & V_217 ) ;
else
F_65 ( V_2 , & V_138 , & V_73 , & V_208 ) ;
F_36 ( V_2 , 0 ) ;
return F_70 ( & V_2 -> V_5 , V_200 , V_138 , V_73 , V_208 , V_217 ) ;
}
static int F_71 ( struct V_176 * V_128 , T_4 V_16 )
{
struct V_1 * V_2 = F_72 ( V_128 ) ;
if ( V_2 )
F_73 ( & V_218 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_74 ( struct V_176 * V_128 )
{
struct V_1 * V_2 = F_72 ( V_128 ) ;
if ( V_2 )
F_75 ( & V_218 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_76 ( struct V_176 * V_177 )
{
struct V_1 * V_2 ;
struct V_126 * V_127 ;
void T_5 * V_219 ;
int V_183 = 0 ;
struct V_178 * V_220 ;
V_2 = F_77 ( sizeof( * V_2 ) , V_221 ) ;
if ( ! V_2 )
return - V_222 ;
V_220 = F_56 ( V_177 , V_180 , 0 ) ;
if ( ! V_220 ) {
V_183 = - V_184 ;
goto free;
}
V_219 = F_78 ( V_220 -> V_181 , V_223 ) ;
if ( ! V_219 ) {
V_183 = - V_222 ;
goto free;
}
V_2 -> V_5 . V_128 = & V_177 -> V_128 ;
V_2 -> V_5 . V_194 = V_220 -> V_181 ;
V_2 -> V_5 . V_27 = V_219 ;
V_2 -> V_5 . type = V_175 ,
V_2 -> V_5 . V_224 = V_192 ;
V_2 -> V_5 . V_53 = F_79 ( V_177 , 0 ) ;
V_2 -> V_107 = F_79 ( V_177 , 0 ) ;
V_2 -> V_106 = F_79 ( V_177 , 1 ) ;
V_2 -> V_111 = F_79 ( V_177 , 2 ) ;
V_2 -> V_5 . V_225 = 32 ;
V_2 -> V_5 . V_6 = & V_226 ;
V_2 -> V_5 . V_19 = V_227 ;
V_2 -> V_5 . line = V_177 -> V_228 ;
F_80 ( & V_2 -> V_21 ) ;
V_2 -> V_21 . V_229 = F_5 ;
V_2 -> V_21 . V_18 = ( unsigned long ) V_2 ;
V_2 -> V_96 = F_81 ( & V_177 -> V_128 , L_4 ) ;
if ( F_82 ( V_2 -> V_96 ) ) {
V_183 = F_83 ( V_2 -> V_96 ) ;
goto V_230;
}
F_84 ( V_2 -> V_96 ) ;
V_2 -> V_5 . V_97 = F_37 ( V_2 -> V_96 ) ;
V_203 [ V_177 -> V_228 ] = V_2 ;
V_127 = V_177 -> V_128 . V_129 ;
if ( V_127 && ( V_127 -> V_19 & V_231 ) )
V_2 -> V_155 = 1 ;
#ifdef F_85
if ( V_127 && ( V_127 -> V_19 & V_232 ) )
V_2 -> V_233 = 1 ;
#endif
if ( V_127 && V_127 -> V_234 ) {
V_183 = V_127 -> V_234 ( V_177 ) ;
if ( V_183 )
goto V_235;
}
V_183 = F_86 ( & V_218 , & V_2 -> V_5 ) ;
if ( V_183 )
goto V_236;
F_87 ( V_177 , & V_2 -> V_5 ) ;
return 0 ;
V_236:
if ( V_127 && V_127 -> exit )
V_127 -> exit ( V_177 ) ;
V_235:
F_88 ( V_2 -> V_96 ) ;
F_89 ( V_2 -> V_96 ) ;
V_230:
F_90 ( V_2 -> V_5 . V_27 ) ;
free:
F_91 ( V_2 ) ;
return V_183 ;
}
static int F_92 ( struct V_176 * V_177 )
{
struct V_126 * V_127 ;
struct V_1 * V_2 = F_72 ( V_177 ) ;
V_127 = V_177 -> V_128 . V_129 ;
F_87 ( V_177 , NULL ) ;
if ( V_2 ) {
F_93 ( & V_218 , & V_2 -> V_5 ) ;
F_88 ( V_2 -> V_96 ) ;
}
F_89 ( V_2 -> V_96 ) ;
if ( V_127 && V_127 -> exit )
V_127 -> exit ( V_177 ) ;
F_90 ( V_2 -> V_5 . V_27 ) ;
F_91 ( V_2 ) ;
return 0 ;
}
static int T_3 F_94 ( void )
{
int V_183 ;
F_66 ( V_215 L_5 ) ;
V_183 = F_95 ( & V_218 ) ;
if ( V_183 )
return V_183 ;
V_183 = F_96 ( & V_237 ) ;
if ( V_183 != 0 )
F_97 ( & V_218 ) ;
return 0 ;
}
static void T_6 F_98 ( void )
{
F_99 ( & V_237 ) ;
F_97 ( & V_218 ) ;
}
