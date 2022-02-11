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
if ( F_5 ( V_2 -> V_8 . V_12 + F_1 ( V_2 ) ) & V_61 )
F_22 ( V_2 ) ;
}
static T_1 F_27 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
unsigned int V_64 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_7 ( V_65 , V_2 -> V_8 . V_12 + V_66 ) ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_66 ) & V_67 ;
F_10 ( & V_2 -> V_8 , ! ! V_64 ) ;
F_11 ( & V_2 -> V_8 . V_30 -> V_8 . V_31 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
return V_68 ;
}
static T_1 F_28 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_52 * V_53 = & V_2 -> V_8 . V_30 -> V_53 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( V_2 -> V_8 . V_69 ) {
F_7 ( V_2 -> V_8 . V_69 , V_2 -> V_8 . V_12 + V_57 ) ;
goto V_70;
}
if ( F_23 ( V_53 ) || F_29 ( & V_2 -> V_8 ) ) {
F_16 ( & V_2 -> V_8 ) ;
goto V_70;
}
F_22 ( V_2 ) ;
if ( F_24 ( V_53 ) < V_60 )
F_25 ( & V_2 -> V_8 ) ;
V_70:
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
return V_68 ;
}
static T_1 F_30 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
unsigned int V_71 , V_72 , V_73 = 0 ;
struct V_74 * V_8 = & V_2 -> V_8 . V_30 -> V_8 ;
unsigned long V_33 , V_38 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
while ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_75 ) {
V_72 = V_76 ;
V_2 -> V_8 . V_24 . V_71 ++ ;
V_71 = F_5 ( V_2 -> V_8 . V_12 + V_47 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_40 ) ;
if ( V_38 & V_77 ) {
F_7 ( V_77 , V_2 -> V_8 . V_12 + V_40 ) ;
if ( F_31 ( & V_2 -> V_8 ) )
continue;
}
if ( F_32 ( & V_2 -> V_8 , ( unsigned char ) V_71 ) )
continue;
if ( F_33 ( V_71 & V_78 ) ) {
if ( V_71 & V_79 )
V_2 -> V_8 . V_24 . V_80 ++ ;
else if ( V_71 & V_81 )
V_2 -> V_8 . V_24 . V_82 ++ ;
else if ( V_71 & V_83 )
V_2 -> V_8 . V_24 . V_84 ++ ;
if ( V_71 & V_85 )
V_2 -> V_8 . V_24 . V_86 ++ ;
if ( V_71 & V_2 -> V_8 . V_87 ) {
if ( ++ V_73 > 100 )
goto V_70;
continue;
}
V_71 &= V_2 -> V_8 . V_88 ;
if ( V_71 & V_79 )
V_72 = V_89 ;
else if ( V_71 & V_81 )
V_72 = V_90 ;
else if ( V_71 & V_83 )
V_72 = V_91 ;
if ( V_71 & V_85 )
V_72 = V_92 ;
#ifdef F_34
V_2 -> V_8 . V_93 = 0 ;
#endif
}
F_35 ( V_8 , V_71 , V_72 ) ;
}
V_70:
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_36 ( V_8 ) ;
return V_68 ;
}
static T_1 F_37 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
unsigned int V_94 ;
V_94 = F_5 ( V_2 -> V_8 . V_12 + V_66 ) ;
if ( V_94 & V_95 )
F_30 ( V_62 , V_63 ) ;
if ( V_94 & V_96 &&
F_5 ( V_2 -> V_8 . V_12 + V_13 ) & V_43 )
F_28 ( V_62 , V_63 ) ;
if ( V_94 & V_65 )
F_27 ( V_62 , V_63 ) ;
if ( V_94 & V_97 )
F_7 ( V_97 , V_2 -> V_8 . V_12 + V_66 ) ;
return V_68 ;
}
static unsigned int F_38 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ? V_98 : 0 ;
}
static unsigned int F_39 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_99 = V_26 | V_28 ;
if ( F_5 ( V_2 -> V_8 . V_12 + V_66 ) & V_67 )
V_99 |= V_29 ;
if ( F_5 ( V_2 -> V_8 . V_12 + V_15 ) & V_100 )
V_99 |= V_101 ;
return V_99 ;
}
static void F_40 ( struct V_7 * V_8 , unsigned int V_102 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) & ~ V_100 ;
if ( V_102 & V_101 )
V_38 |= V_100 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
}
static void F_41 ( struct V_7 * V_8 , int V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_33 , V_38 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) & ~ V_104 ;
if ( V_103 != 0 )
V_38 |= V_104 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_105 )
{
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_106 ) & ( V_107 | V_108 ) ;
V_64 |= V_109 << V_110 | V_111 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_106 ) ;
return 0 ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_112 ;
unsigned long V_33 , V_38 ;
F_42 ( V_2 , 0 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
if ( F_17 ( V_2 ) )
V_38 |= V_113 ;
V_38 &= ~ ( V_114 << V_115 ) ;
V_38 |= V_116 << V_115 ;
F_7 ( V_38 & ~ V_50 , V_2 -> V_8 . V_12 + V_45 ) ;
if ( F_17 ( V_2 ) ) {
int V_117 = 100 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 &= ~ V_118 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_15 ) & V_118 ) &&
( -- V_117 > 0 ) ) {
F_18 ( 1 ) ;
}
}
if ( V_2 -> V_119 > 0 ) {
V_112 = F_44 ( V_2 -> V_120 , F_30 , 0 ,
V_121 , V_2 ) ;
if ( V_112 )
goto V_122;
V_112 = F_44 ( V_2 -> V_119 , F_28 , 0 ,
V_121 , V_2 ) ;
if ( V_112 )
goto V_123;
if ( ! F_17 ( V_2 ) ) {
V_112 = F_44 ( V_2 -> V_124 , F_27 , 0 ,
V_121 , V_2 ) ;
if ( V_112 )
goto V_125;
}
} else {
V_112 = F_44 ( V_2 -> V_8 . V_62 , F_37 , 0 ,
V_121 , V_2 ) ;
if ( V_112 ) {
F_45 ( V_2 -> V_8 . V_62 , V_2 ) ;
goto V_122;
}
}
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_7 ( V_65 , V_2 -> V_8 . V_12 + V_66 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 |= V_49 | V_126 | V_127 ;
if ( F_17 ( V_2 ) ) {
V_38 |= V_128 ;
V_38 &= ~ ( V_126 ) ;
}
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 |= ( V_51 | V_129 ) ;
if ( ! V_2 -> V_130 )
V_38 |= V_131 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_17 ( V_2 ) ) {
int V_117 = 64 ;
while ( ( -- V_117 > 0 ) &&
( F_5 ( V_2 -> V_8 . V_12 + V_47 ) & V_48 ) ) {
F_19 () ;
}
}
if ( F_3 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_38 |= V_132 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
if ( F_17 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
if ( V_2 -> V_133 )
V_38 |= V_134 ;
else
V_38 &= ~ ( V_134 ) ;
F_7 ( V_38 | V_50 , V_2 -> V_8 . V_12 + V_45 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 -> V_135 )
V_38 |= V_136 ;
else
V_38 &= ~ ( V_136 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( F_17 ( V_2 ) ) {
struct V_137 * V_138 ;
V_138 = V_2 -> V_8 . V_139 -> V_140 ;
V_2 -> V_133 = V_138 -> V_133 ;
V_2 -> V_135 = V_138 -> V_135 ;
V_2 -> V_42 = V_138 -> V_141 ;
if ( V_138 -> V_142 )
V_138 -> V_142 ( 1 ) ;
}
return 0 ;
V_125:
if ( V_2 -> V_119 )
F_45 ( V_2 -> V_119 , V_2 ) ;
V_123:
if ( V_2 -> V_120 )
F_45 ( V_2 -> V_120 , V_2 ) ;
V_122:
return V_112 ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 &= ~ ( V_129 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( F_17 ( V_2 ) ) {
struct V_137 * V_138 ;
V_138 = V_2 -> V_8 . V_139 -> V_140 ;
if ( V_138 -> V_142 )
V_138 -> V_142 ( 0 ) ;
}
F_47 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_119 > 0 ) {
if ( ! F_17 ( V_2 ) )
F_45 ( V_2 -> V_124 , V_2 ) ;
F_45 ( V_2 -> V_119 , V_2 ) ;
F_45 ( V_2 -> V_120 , V_2 ) ;
} else
F_45 ( V_2 -> V_8 . V_62 , V_2 ) ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 &= ~ ( V_43 | V_49 | V_126 | V_127 ) ;
if ( F_17 ( V_2 ) )
V_38 &= ~ ( V_128 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static void
F_48 ( struct V_7 * V_8 , struct V_143 * V_144 ,
struct V_143 * V_145 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_33 ;
unsigned int V_14 , V_146 , V_147 , V_148 , V_149 ;
unsigned int V_150 = V_145 ? V_145 -> V_151 & V_152 : V_153 ;
unsigned int div , V_154 ;
unsigned long V_155 , V_156 ;
T_2 V_157 ;
if ( 0 ) {
V_144 -> V_151 &= ~ ( V_158 | V_159 | V_160 ) ;
V_144 -> V_151 |= V_161 ;
}
while ( ( V_144 -> V_151 & V_152 ) != V_162 &&
( V_144 -> V_151 & V_152 ) != V_153 ) {
V_144 -> V_151 &= ~ V_152 ;
V_144 -> V_151 |= V_150 ;
V_150 = V_153 ;
}
if ( ( V_144 -> V_151 & V_152 ) == V_153 )
V_14 = V_163 | V_118 | V_131 ;
else
V_14 = V_118 | V_131 ;
if ( V_144 -> V_151 & V_159 ) {
if ( V_2 -> V_130 ) {
V_14 &= ~ V_131 ;
V_14 |= V_164 ;
} else {
V_144 -> V_151 &= ~ V_159 ;
}
}
if ( V_144 -> V_151 & V_165 )
V_14 |= V_166 ;
if ( V_144 -> V_151 & V_167 ) {
V_14 |= V_168 ;
if ( V_144 -> V_151 & V_169 )
V_14 |= V_170 ;
}
F_47 ( & V_2 -> V_35 ) ;
V_148 = F_49 ( V_8 , V_144 , V_145 , 50 , V_8 -> V_171 / 16 ) ;
V_149 = F_50 ( V_8 , V_148 ) ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_2 -> V_8 . V_88 = 0 ;
if ( V_144 -> V_172 & V_173 )
V_2 -> V_8 . V_88 |= ( V_83 | V_81 ) ;
if ( V_144 -> V_172 & ( V_174 | V_175 ) )
V_2 -> V_8 . V_88 |= V_79 ;
V_2 -> V_8 . V_87 = 0 ;
if ( V_144 -> V_172 & V_176 )
V_2 -> V_8 . V_87 |= V_81 ;
if ( V_144 -> V_172 & V_177 ) {
V_2 -> V_8 . V_87 |= V_79 ;
if ( V_144 -> V_172 & V_176 )
V_2 -> V_8 . V_87 |= V_85 ;
}
F_51 ( V_8 , V_144 -> V_151 , V_148 ) ;
V_146 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_146 & ~ ( V_43 | V_49 | V_126 ) ,
V_2 -> V_8 . V_12 + V_13 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) )
F_19 () ;
V_147 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
F_7 ( V_147 & ~ ( V_129 | V_51 ) ,
V_2 -> V_8 . V_12 + V_15 ) ;
V_147 &= ( V_129 | V_51 ) ;
if ( F_17 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_8 . V_171 / ( V_148 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_52 ( 16 * div * V_148 , V_2 -> V_8 . V_171 ,
1 << 16 , 1 << 16 , & V_155 , & V_156 ) ;
V_157 = V_2 -> V_8 . V_171 ;
V_157 *= V_155 ;
F_53 ( V_157 , V_156 * 16 * div ) ;
F_54 ( V_144 ,
( V_178 ) V_157 , ( V_178 ) V_157 ) ;
V_155 -= 1 ;
V_156 -= 1 ;
V_154 = F_5 ( V_2 -> V_8 . V_12 + V_106 ) ;
V_154 = ( V_154 & ( ~ V_107 ) ) | F_55 ( div ) ;
F_7 ( V_154 , V_2 -> V_8 . V_12 + V_106 ) ;
F_7 ( V_155 , V_2 -> V_8 . V_12 + V_179 ) ;
F_7 ( V_156 , V_2 -> V_8 . V_12 + V_180 ) ;
if ( F_3 ( V_2 ) )
F_7 ( V_2 -> V_8 . V_171 / div / 1000 ,
V_2 -> V_8 . V_12 + V_181 ) ;
F_7 ( V_146 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_14 | V_147 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_56 ( & V_2 -> V_8 , V_144 -> V_151 ) )
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static const char * F_57 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_182 ? L_1 : NULL ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_183 * V_184 = F_59 ( V_8 -> V_139 ) ;
struct V_185 * V_186 ;
V_186 = F_60 ( V_184 , V_187 , 0 ) ;
F_61 ( V_186 -> V_188 , F_62 ( V_186 ) ) ;
}
static int F_63 ( struct V_7 * V_8 )
{
struct V_183 * V_184 = F_59 ( V_8 -> V_139 ) ;
struct V_185 * V_186 ;
void * V_189 ;
V_186 = F_60 ( V_184 , V_187 , 0 ) ;
if ( ! V_186 )
return - V_190 ;
V_189 = F_64 ( V_186 -> V_188 , F_62 ( V_186 ) , L_2 ) ;
return V_189 ? 0 : - V_191 ;
}
static void F_65 ( struct V_7 * V_8 , int V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( V_33 & V_192 &&
F_63 ( & V_2 -> V_8 ) == 0 )
V_2 -> V_8 . type = V_182 ;
}
static int
F_66 ( struct V_7 * V_8 , struct V_193 * V_194 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_189 = 0 ;
if ( V_194 -> type != V_195 && V_194 -> type != V_182 )
V_189 = - V_196 ;
if ( V_2 -> V_8 . V_62 != V_194 -> V_62 )
V_189 = - V_196 ;
if ( V_194 -> V_197 != V_198 )
V_189 = - V_196 ;
if ( V_2 -> V_8 . V_171 / 16 != V_194 -> V_199 )
V_189 = - V_196 ;
if ( ( void * ) V_2 -> V_8 . V_200 != V_194 -> V_201 )
V_189 = - V_196 ;
if ( V_2 -> V_8 . V_202 != V_194 -> V_8 )
V_189 = - V_196 ;
if ( V_194 -> V_203 != 0 )
V_189 = - V_196 ;
return V_189 ;
}
static int F_67 ( struct V_7 * V_8 )
{
struct V_9 V_204 ;
unsigned int V_18 ;
unsigned char V_205 ;
F_4 ( V_8 , & V_204 ) ;
F_7 ( V_127 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_204 . V_14 & ~ ( V_206 | V_207 | V_208 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_204 . V_16 & ~ ( V_209 | V_210 | V_211 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_75 );
V_205 = F_5 ( V_8 -> V_12 + V_47 ) ;
F_6 ( V_8 , & V_204 ) ;
return V_205 ;
}
static void F_68 ( struct V_7 * V_8 , unsigned char V_205 )
{
struct V_9 V_204 ;
unsigned int V_18 ;
F_4 ( V_8 , & V_204 ) ;
F_7 ( V_127 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_204 . V_14 & ~ ( V_206 | V_207 | V_208 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_204 . V_16 & ~ ( V_209 | V_210 | V_211 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_66 ) ;
} while ( ~ V_18 & V_96 );
F_7 ( V_205 , V_8 -> V_12 + V_57 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_41 );
F_6 ( V_8 , & V_204 ) ;
}
static void F_69 ( struct V_7 * V_8 , int V_212 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_5 ( V_2 -> V_8 . V_12 + F_1 ( V_2 ) ) & V_54 )
F_19 () ;
F_7 ( V_212 , V_2 -> V_8 . V_12 + V_57 ) ;
}
static void
F_70 ( struct V_213 * V_214 , const char * V_215 , unsigned int V_216 )
{
struct V_1 * V_2 = V_217 [ V_214 -> V_218 ] ;
struct V_9 V_204 ;
unsigned int V_11 ;
unsigned long V_33 = 0 ;
int V_219 = 1 ;
if ( V_2 -> V_8 . V_93 )
V_219 = 0 ;
else if ( V_220 )
V_219 = F_71 ( & V_2 -> V_8 . V_34 , V_33 ) ;
else
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_4 ( & V_2 -> V_8 , & V_204 ) ;
V_11 = V_204 . V_11 ;
if ( F_2 ( V_2 ) )
V_11 |= V_221 ;
V_11 |= V_127 ;
V_11 &= ~ ( V_43 | V_49 | V_126 ) ;
F_7 ( V_11 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_204 . V_14 | V_129 , V_2 -> V_8 . V_12 + V_15 ) ;
F_72 ( & V_2 -> V_8 , V_215 , V_216 , F_69 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ) ;
F_6 ( & V_2 -> V_8 , & V_204 ) ;
if ( V_219 )
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static void T_3
F_73 ( struct V_1 * V_2 , int * V_148 ,
int * V_82 , int * V_222 )
{
if ( F_5 ( V_2 -> V_8 . V_12 + V_13 ) & V_127 ) {
unsigned int V_14 , V_223 , V_224 , V_171 ;
unsigned int V_225 ;
unsigned int V_226 ;
V_14 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
* V_82 = 'n' ;
if ( V_14 & V_168 ) {
if ( V_14 & V_170 )
* V_82 = 'o' ;
else
* V_82 = 'e' ;
}
if ( V_14 & V_163 )
* V_222 = 8 ;
else
* V_222 = 7 ;
V_223 = F_5 ( V_2 -> V_8 . V_12 + V_179 ) & 0xffff ;
V_224 = F_5 ( V_2 -> V_8 . V_12 + V_180 ) & 0xffff ;
V_226 = ( F_5 ( V_2 -> V_8 . V_12 + V_106 ) & V_107 ) >> 7 ;
if ( V_226 == 6 )
V_226 = 7 ;
else
V_226 = 6 - V_226 ;
V_171 = F_74 ( V_2 -> V_227 ) ;
V_171 /= V_226 ;
{
unsigned int V_228 = V_223 + 1 ;
unsigned int div = 16 * ( V_224 + 1 ) ;
unsigned int V_229 = V_171 % div ;
V_225 = ( V_171 / div ) * V_228 ;
V_225 += ( V_229 * V_228 + div / 2 ) / div ;
* V_148 = ( V_225 + 50 ) / 100 * 100 ;
}
if ( * V_148 != V_225 )
F_75 ( L_3 ,
V_225 , * V_148 ) ;
}
}
static int T_3
F_76 ( struct V_213 * V_214 , char * V_230 )
{
struct V_1 * V_2 ;
int V_148 = 9600 ;
int V_222 = 8 ;
int V_82 = 'n' ;
int V_231 = 'n' ;
if ( V_214 -> V_218 == - 1 || V_214 -> V_218 >= F_77 ( V_217 ) )
V_214 -> V_218 = 0 ;
V_2 = V_217 [ V_214 -> V_218 ] ;
if ( V_2 == NULL )
return - V_190 ;
if ( V_230 )
F_78 ( V_230 , & V_148 , & V_82 , & V_222 , & V_231 ) ;
else
F_73 ( V_2 , & V_148 , & V_82 , & V_222 ) ;
F_42 ( V_2 , 0 ) ;
return F_79 ( & V_2 -> V_8 , V_214 , V_148 , V_82 , V_222 , V_231 ) ;
}
static int F_80 ( struct V_183 * V_139 , T_4 V_30 )
{
struct V_1 * V_2 = F_81 ( V_139 ) ;
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_64 |= V_232 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_17 ) ;
F_82 ( & V_233 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_83 ( struct V_183 * V_139 )
{
struct V_1 * V_2 = F_81 ( V_139 ) ;
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_64 &= ~ V_232 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_17 ) ;
F_84 ( & V_233 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
struct V_234 * V_235 = V_184 -> V_139 . V_236 ;
const struct V_237 * V_238 =
F_86 ( V_239 , & V_184 -> V_139 ) ;
int V_189 ;
if ( ! V_235 )
return 1 ;
V_189 = F_87 ( V_235 , L_4 ) ;
if ( V_189 < 0 ) {
F_88 ( & V_184 -> V_139 , L_5 , V_189 ) ;
return V_189 ;
}
V_2 -> V_8 . line = V_189 ;
if ( F_89 ( V_235 , L_6 , NULL ) )
V_2 -> V_130 = 1 ;
if ( F_89 ( V_235 , L_7 , NULL ) )
V_2 -> V_240 = 1 ;
V_2 -> V_3 = V_238 -> V_32 ;
return 0 ;
}
static inline int F_85 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
return 1 ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
struct V_137 * V_138 = V_184 -> V_139 . V_140 ;
V_2 -> V_8 . line = V_184 -> V_241 ;
V_2 -> V_3 = (struct V_242 * ) V_184 -> V_243 -> V_244 ;
if ( ! V_138 )
return;
if ( V_138 -> V_33 & V_245 )
V_2 -> V_130 = 1 ;
if ( V_138 -> V_33 & V_246 )
V_2 -> V_240 = 1 ;
}
static int F_91 ( struct V_183 * V_184 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 ;
void T_5 * V_247 ;
int V_189 = 0 ;
struct V_185 * V_248 ;
struct V_249 * V_249 ;
V_2 = F_92 ( & V_184 -> V_139 , sizeof( * V_2 ) , V_250 ) ;
if ( ! V_2 )
return - V_251 ;
V_189 = F_85 ( V_2 , V_184 ) ;
if ( V_189 > 0 )
F_90 ( V_2 , V_184 ) ;
else if ( V_189 < 0 )
return V_189 ;
V_248 = F_60 ( V_184 , V_187 , 0 ) ;
if ( ! V_248 )
return - V_190 ;
V_247 = F_93 ( & V_184 -> V_139 , V_248 -> V_188 , V_252 ) ;
if ( ! V_247 )
return - V_251 ;
V_2 -> V_8 . V_139 = & V_184 -> V_139 ;
V_2 -> V_8 . V_200 = V_248 -> V_188 ;
V_2 -> V_8 . V_12 = V_247 ;
V_2 -> V_8 . type = V_182 ,
V_2 -> V_8 . V_253 = V_198 ;
V_2 -> V_8 . V_62 = F_94 ( V_184 , 0 ) ;
V_2 -> V_120 = F_94 ( V_184 , 0 ) ;
V_2 -> V_119 = F_94 ( V_184 , 1 ) ;
V_2 -> V_124 = F_94 ( V_184 , 2 ) ;
V_2 -> V_8 . V_254 = 32 ;
V_2 -> V_8 . V_20 = & V_255 ;
V_2 -> V_8 . V_33 = V_256 ;
F_95 ( & V_2 -> V_35 ) ;
V_2 -> V_35 . V_257 = F_12 ;
V_2 -> V_35 . V_32 = ( unsigned long ) V_2 ;
V_249 = F_96 ( & V_184 -> V_139 ) ;
if ( F_97 ( V_249 ) ) {
V_189 = F_98 ( V_249 ) ;
F_88 ( & V_184 -> V_139 , L_8 , V_189 ) ;
return V_189 ;
}
V_2 -> V_258 = F_99 ( & V_184 -> V_139 , L_9 ) ;
if ( F_97 ( V_2 -> V_258 ) ) {
V_189 = F_98 ( V_2 -> V_258 ) ;
F_88 ( & V_184 -> V_139 , L_10 , V_189 ) ;
return V_189 ;
}
V_2 -> V_227 = F_99 ( & V_184 -> V_139 , L_11 ) ;
if ( F_97 ( V_2 -> V_227 ) ) {
V_189 = F_98 ( V_2 -> V_227 ) ;
F_88 ( & V_184 -> V_139 , L_12 , V_189 ) ;
return V_189 ;
}
F_100 ( V_2 -> V_227 ) ;
F_100 ( V_2 -> V_258 ) ;
V_2 -> V_8 . V_171 = F_74 ( V_2 -> V_227 ) ;
V_217 [ V_2 -> V_8 . line ] = V_2 ;
V_138 = V_184 -> V_139 . V_140 ;
if ( V_138 && V_138 -> V_259 ) {
V_189 = V_138 -> V_259 ( V_184 ) ;
if ( V_189 )
goto V_260;
}
V_189 = F_101 ( & V_233 , & V_2 -> V_8 ) ;
if ( V_189 )
goto V_261;
F_102 ( V_184 , V_2 ) ;
return 0 ;
V_261:
if ( V_138 && V_138 -> exit )
V_138 -> exit ( V_184 ) ;
V_260:
F_103 ( V_2 -> V_227 ) ;
F_103 ( V_2 -> V_258 ) ;
return V_189 ;
}
static int F_104 ( struct V_183 * V_184 )
{
struct V_137 * V_138 ;
struct V_1 * V_2 = F_81 ( V_184 ) ;
V_138 = V_184 -> V_139 . V_140 ;
F_102 ( V_184 , NULL ) ;
F_105 ( & V_233 , & V_2 -> V_8 ) ;
F_103 ( V_2 -> V_227 ) ;
F_103 ( V_2 -> V_258 ) ;
if ( V_138 && V_138 -> exit )
V_138 -> exit ( V_184 ) ;
return 0 ;
}
static int T_3 F_106 ( void )
{
int V_189 ;
F_75 ( L_13 ) ;
V_189 = F_107 ( & V_233 ) ;
if ( V_189 )
return V_189 ;
V_189 = F_108 ( & V_262 ) ;
if ( V_189 != 0 )
F_109 ( & V_233 ) ;
return V_189 ;
}
static void T_6 F_110 ( void )
{
F_111 ( & V_262 ) ;
F_109 ( & V_233 ) ;
}
