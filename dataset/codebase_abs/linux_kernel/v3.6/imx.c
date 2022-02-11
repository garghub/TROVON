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
if ( V_2 -> V_8 . V_69 )
{
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
struct V_74 * V_75 = V_2 -> V_8 . V_30 -> V_8 . V_75 ;
unsigned long V_33 , V_38 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
while ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_76 ) {
V_72 = V_77 ;
V_2 -> V_8 . V_24 . V_71 ++ ;
V_71 = F_5 ( V_2 -> V_8 . V_12 + V_47 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_40 ) ;
if ( V_38 & V_78 ) {
F_7 ( V_78 , V_2 -> V_8 . V_12 + V_40 ) ;
if ( F_31 ( & V_2 -> V_8 ) )
continue;
}
if ( F_32 ( & V_2 -> V_8 , ( unsigned char ) V_71 ) )
continue;
if ( F_33 ( V_71 & V_79 ) ) {
if ( V_71 & V_80 )
V_2 -> V_8 . V_24 . V_81 ++ ;
else if ( V_71 & V_82 )
V_2 -> V_8 . V_24 . V_83 ++ ;
else if ( V_71 & V_84 )
V_2 -> V_8 . V_24 . V_85 ++ ;
if ( V_71 & V_86 )
V_2 -> V_8 . V_24 . V_87 ++ ;
if ( V_71 & V_2 -> V_8 . V_88 ) {
if ( ++ V_73 > 100 )
goto V_70;
continue;
}
V_71 &= V_2 -> V_8 . V_89 ;
if ( V_71 & V_80 )
V_72 = V_90 ;
else if ( V_71 & V_82 )
V_72 = V_91 ;
else if ( V_71 & V_84 )
V_72 = V_92 ;
if ( V_71 & V_86 )
V_72 = V_93 ;
#ifdef F_34
V_2 -> V_8 . V_94 = 0 ;
#endif
}
F_35 ( V_75 , V_71 , V_72 ) ;
}
V_70:
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_36 ( V_75 ) ;
return V_68 ;
}
static T_1 F_37 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
unsigned int V_95 ;
V_95 = F_5 ( V_2 -> V_8 . V_12 + V_66 ) ;
if ( V_95 & V_96 )
F_30 ( V_62 , V_63 ) ;
if ( V_95 & V_97 &&
F_5 ( V_2 -> V_8 . V_12 + V_13 ) & V_43 )
F_28 ( V_62 , V_63 ) ;
if ( V_95 & V_65 )
F_27 ( V_62 , V_63 ) ;
if ( V_95 & V_98 )
F_7 ( V_98 , V_2 -> V_8 . V_12 + V_66 ) ;
return V_68 ;
}
static unsigned int F_38 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ? V_99 : 0 ;
}
static unsigned int F_39 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_100 = V_26 | V_28 ;
if ( F_5 ( V_2 -> V_8 . V_12 + V_66 ) & V_67 )
V_100 |= V_29 ;
if ( F_5 ( V_2 -> V_8 . V_12 + V_15 ) & V_101 )
V_100 |= V_102 ;
return V_100 ;
}
static void F_40 ( struct V_7 * V_8 , unsigned int V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) & ~ V_101 ;
if ( V_103 & V_102 )
V_38 |= V_101 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
}
static void F_41 ( struct V_7 * V_8 , int V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_33 , V_38 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) & ~ V_105 ;
if ( V_104 != 0 )
V_38 |= V_105 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_106 )
{
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_107 ) & ( V_108 | V_109 ) ;
V_64 |= V_110 << V_111 | V_112 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_107 ) ;
return 0 ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_113 ;
unsigned long V_33 , V_38 ;
F_42 ( V_2 , 0 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
if ( F_17 ( V_2 ) )
V_38 |= V_114 ;
V_38 &= ~ ( V_115 << V_116 ) ;
V_38 |= V_117 << V_116 ;
F_7 ( V_38 & ~ V_50 , V_2 -> V_8 . V_12 + V_45 ) ;
if ( F_17 ( V_2 ) ) {
int V_118 = 100 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 &= ~ V_119 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_15 ) & V_119 ) &&
( -- V_118 > 0 ) ) {
F_18 ( 1 ) ;
}
}
if ( V_2 -> V_120 > 0 ) {
V_113 = F_44 ( V_2 -> V_121 , F_30 , 0 ,
V_122 , V_2 ) ;
if ( V_113 )
goto V_123;
V_113 = F_44 ( V_2 -> V_120 , F_28 , 0 ,
V_122 , V_2 ) ;
if ( V_113 )
goto V_124;
if ( ! F_17 ( V_2 ) ) {
V_113 = F_44 ( V_2 -> V_125 , F_27 , 0 ,
V_122 , V_2 ) ;
if ( V_113 )
goto V_126;
}
} else {
V_113 = F_44 ( V_2 -> V_8 . V_62 , F_37 , 0 ,
V_122 , V_2 ) ;
if ( V_113 ) {
F_45 ( V_2 -> V_8 . V_62 , V_2 ) ;
goto V_123;
}
}
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_7 ( V_65 , V_2 -> V_8 . V_12 + V_66 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 |= V_49 | V_127 | V_128 ;
if ( F_17 ( V_2 ) ) {
V_38 |= V_129 ;
V_38 &= ~ ( V_127 ) ;
}
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 |= ( V_51 | V_130 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_17 ( V_2 ) ) {
int V_118 = 64 ;
while ( ( -- V_118 > 0 ) &&
( F_5 ( V_2 -> V_8 . V_12 + V_47 ) & V_48 ) ) {
F_19 () ;
}
}
if ( F_3 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_38 |= V_131 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
if ( F_17 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
if ( V_2 -> V_132 )
V_38 |= V_133 ;
else
V_38 &= ~ ( V_133 ) ;
F_7 ( V_38 | V_50 , V_2 -> V_8 . V_12 + V_45 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 -> V_134 )
V_38 |= V_135 ;
else
V_38 &= ~ ( V_135 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( F_17 ( V_2 ) ) {
struct V_136 * V_137 ;
V_137 = V_2 -> V_8 . V_138 -> V_139 ;
V_2 -> V_132 = V_137 -> V_132 ;
V_2 -> V_134 = V_137 -> V_134 ;
V_2 -> V_42 = V_137 -> V_140 ;
if ( V_137 -> V_141 )
V_137 -> V_141 ( 1 ) ;
}
return 0 ;
V_126:
if ( V_2 -> V_120 )
F_45 ( V_2 -> V_120 , V_2 ) ;
V_124:
if ( V_2 -> V_121 )
F_45 ( V_2 -> V_121 , V_2 ) ;
V_123:
return V_113 ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 &= ~ ( V_130 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( F_17 ( V_2 ) ) {
struct V_136 * V_137 ;
V_137 = V_2 -> V_8 . V_138 -> V_139 ;
if ( V_137 -> V_141 )
V_137 -> V_141 ( 0 ) ;
}
F_47 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_120 > 0 ) {
if ( ! F_17 ( V_2 ) )
F_45 ( V_2 -> V_125 , V_2 ) ;
F_45 ( V_2 -> V_120 , V_2 ) ;
F_45 ( V_2 -> V_121 , V_2 ) ;
} else
F_45 ( V_2 -> V_8 . V_62 , V_2 ) ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 &= ~ ( V_43 | V_49 | V_127 | V_128 ) ;
if ( F_17 ( V_2 ) )
V_38 &= ~ ( V_129 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static void
F_48 ( struct V_7 * V_8 , struct V_142 * V_143 ,
struct V_142 * V_144 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_33 ;
unsigned int V_14 , V_145 , V_146 , V_147 , V_148 ;
unsigned int V_149 = V_144 ? V_144 -> V_150 & V_151 : V_152 ;
unsigned int div , V_153 ;
unsigned long V_154 , V_155 ;
T_2 V_156 ;
if ( 0 ) {
V_143 -> V_150 &= ~ ( V_157 | V_158 | V_159 ) ;
V_143 -> V_150 |= V_160 ;
}
while ( ( V_143 -> V_150 & V_151 ) != V_161 &&
( V_143 -> V_150 & V_151 ) != V_152 ) {
V_143 -> V_150 &= ~ V_151 ;
V_143 -> V_150 |= V_149 ;
V_149 = V_152 ;
}
if ( ( V_143 -> V_150 & V_151 ) == V_152 )
V_14 = V_162 | V_119 | V_163 ;
else
V_14 = V_119 | V_163 ;
if ( V_143 -> V_150 & V_158 ) {
if( V_2 -> V_164 ) {
V_14 &= ~ V_163 ;
V_14 |= V_165 ;
} else {
V_143 -> V_150 &= ~ V_158 ;
}
}
if ( V_143 -> V_150 & V_166 )
V_14 |= V_167 ;
if ( V_143 -> V_150 & V_168 ) {
V_14 |= V_169 ;
if ( V_143 -> V_150 & V_170 )
V_14 |= V_171 ;
}
F_47 ( & V_2 -> V_35 ) ;
V_147 = F_49 ( V_8 , V_143 , V_144 , 50 , V_8 -> V_172 / 16 ) ;
V_148 = F_50 ( V_8 , V_147 ) ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_2 -> V_8 . V_89 = 0 ;
if ( V_143 -> V_173 & V_174 )
V_2 -> V_8 . V_89 |= ( V_84 | V_82 ) ;
if ( V_143 -> V_173 & ( V_175 | V_176 ) )
V_2 -> V_8 . V_89 |= V_80 ;
V_2 -> V_8 . V_88 = 0 ;
if ( V_143 -> V_173 & V_177 )
V_2 -> V_8 . V_88 |= V_82 ;
if ( V_143 -> V_173 & V_178 ) {
V_2 -> V_8 . V_88 |= V_80 ;
if ( V_143 -> V_173 & V_177 )
V_2 -> V_8 . V_88 |= V_86 ;
}
F_51 ( V_8 , V_143 -> V_150 , V_147 ) ;
V_145 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_145 & ~ ( V_43 | V_49 | V_127 ) ,
V_2 -> V_8 . V_12 + V_13 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) )
F_19 () ;
V_146 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
F_7 ( V_146 & ~ ( V_130 | V_51 ) ,
V_2 -> V_8 . V_12 + V_15 ) ;
V_146 &= ( V_130 | V_51 ) ;
if ( F_17 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_8 . V_172 / ( V_147 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_52 ( 16 * div * V_147 , V_2 -> V_8 . V_172 ,
1 << 16 , 1 << 16 , & V_154 , & V_155 ) ;
V_156 = V_2 -> V_8 . V_172 ;
V_156 *= V_154 ;
F_53 ( V_156 , V_155 * 16 * div ) ;
F_54 ( V_143 ,
( V_179 ) V_156 , ( V_179 ) V_156 ) ;
V_154 -= 1 ;
V_155 -= 1 ;
V_153 = F_5 ( V_2 -> V_8 . V_12 + V_107 ) ;
V_153 = ( V_153 & ( ~ V_108 ) ) | F_55 ( div ) ;
F_7 ( V_153 , V_2 -> V_8 . V_12 + V_107 ) ;
F_7 ( V_154 , V_2 -> V_8 . V_12 + V_180 ) ;
F_7 ( V_155 , V_2 -> V_8 . V_12 + V_181 ) ;
if ( F_3 ( V_2 ) )
F_7 ( V_2 -> V_8 . V_172 / div / 1000 ,
V_2 -> V_8 . V_12 + V_182 ) ;
F_7 ( V_145 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_14 | V_146 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_56 ( & V_2 -> V_8 , V_143 -> V_150 ) )
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static const char * F_57 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_183 ? L_1 : NULL ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_184 * V_185 = F_59 ( V_8 -> V_138 ) ;
struct V_186 * V_187 ;
V_187 = F_60 ( V_185 , V_188 , 0 ) ;
F_61 ( V_187 -> V_189 , F_62 ( V_187 ) ) ;
}
static int F_63 ( struct V_7 * V_8 )
{
struct V_184 * V_185 = F_59 ( V_8 -> V_138 ) ;
struct V_186 * V_187 ;
void * V_190 ;
V_187 = F_60 ( V_185 , V_188 , 0 ) ;
if ( ! V_187 )
return - V_191 ;
V_190 = F_64 ( V_187 -> V_189 , F_62 ( V_187 ) , L_2 ) ;
return V_190 ? 0 : - V_192 ;
}
static void F_65 ( struct V_7 * V_8 , int V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( V_33 & V_193 &&
F_63 ( & V_2 -> V_8 ) == 0 )
V_2 -> V_8 . type = V_183 ;
}
static int
F_66 ( struct V_7 * V_8 , struct V_194 * V_195 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_190 = 0 ;
if ( V_195 -> type != V_196 && V_195 -> type != V_183 )
V_190 = - V_197 ;
if ( V_2 -> V_8 . V_62 != V_195 -> V_62 )
V_190 = - V_197 ;
if ( V_195 -> V_198 != V_199 )
V_190 = - V_197 ;
if ( V_2 -> V_8 . V_172 / 16 != V_195 -> V_200 )
V_190 = - V_197 ;
if ( ( void * ) V_2 -> V_8 . V_201 != V_195 -> V_202 )
V_190 = - V_197 ;
if ( V_2 -> V_8 . V_203 != V_195 -> V_8 )
V_190 = - V_197 ;
if ( V_195 -> V_204 != 0 )
V_190 = - V_197 ;
return V_190 ;
}
static int F_67 ( struct V_7 * V_8 )
{
struct V_9 V_205 ;
unsigned int V_18 ;
unsigned char V_206 ;
F_4 ( V_8 , & V_205 ) ;
F_7 ( V_128 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_205 . V_14 & ~ ( V_207 | V_208 | V_209 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_205 . V_16 & ~ ( V_210 | V_211 | V_212 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_76 );
V_206 = F_5 ( V_8 -> V_12 + V_47 ) ;
F_6 ( V_8 , & V_205 ) ;
return V_206 ;
}
static void F_68 ( struct V_7 * V_8 , unsigned char V_206 )
{
struct V_9 V_205 ;
unsigned int V_18 ;
F_4 ( V_8 , & V_205 ) ;
F_7 ( V_128 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_205 . V_14 & ~ ( V_207 | V_208 | V_209 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_205 . V_16 & ~ ( V_210 | V_211 | V_212 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_66 ) ;
} while ( ~ V_18 & V_97 );
F_7 ( V_206 , V_8 -> V_12 + V_57 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_41 );
F_6 ( V_8 , & V_205 ) ;
}
static void F_69 ( struct V_7 * V_8 , int V_213 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_5 ( V_2 -> V_8 . V_12 + F_1 ( V_2 ) ) & V_54 )
F_19 () ;
F_7 ( V_213 , V_2 -> V_8 . V_12 + V_57 ) ;
}
static void
F_70 ( struct V_214 * V_215 , const char * V_216 , unsigned int V_217 )
{
struct V_1 * V_2 = V_218 [ V_215 -> V_219 ] ;
struct V_9 V_205 ;
unsigned int V_11 ;
unsigned long V_33 ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_4 ( & V_2 -> V_8 , & V_205 ) ;
V_11 = V_205 . V_11 ;
if ( F_2 ( V_2 ) )
V_11 |= V_220 ;
V_11 |= V_128 ;
V_11 &= ~ ( V_43 | V_49 | V_127 ) ;
F_7 ( V_11 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_205 . V_14 | V_130 , V_2 -> V_8 . V_12 + V_15 ) ;
F_71 ( & V_2 -> V_8 , V_216 , V_217 , F_69 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ) ;
F_6 ( & V_2 -> V_8 , & V_205 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static void T_3
F_72 ( struct V_1 * V_2 , int * V_147 ,
int * V_83 , int * V_221 )
{
if ( F_5 ( V_2 -> V_8 . V_12 + V_13 ) & V_128 ) {
unsigned int V_14 , V_222 , V_223 , V_172 ;
unsigned int V_224 ;
unsigned int V_225 ;
V_14 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
* V_83 = 'n' ;
if ( V_14 & V_169 ) {
if ( V_14 & V_171 )
* V_83 = 'o' ;
else
* V_83 = 'e' ;
}
if ( V_14 & V_162 )
* V_221 = 8 ;
else
* V_221 = 7 ;
V_222 = F_5 ( V_2 -> V_8 . V_12 + V_180 ) & 0xffff ;
V_223 = F_5 ( V_2 -> V_8 . V_12 + V_181 ) & 0xffff ;
V_225 = ( F_5 ( V_2 -> V_8 . V_12 + V_107 ) & V_108 ) >> 7 ;
if ( V_225 == 6 )
V_225 = 7 ;
else
V_225 = 6 - V_225 ;
V_172 = F_73 ( V_2 -> V_226 ) ;
V_172 /= V_225 ;
{
unsigned int V_227 = V_222 + 1 ;
unsigned int div = 16 * ( V_223 + 1 ) ;
unsigned int V_228 = V_172 % div ;
V_224 = ( V_172 / div ) * V_227 ;
V_224 += ( V_228 * V_227 + div / 2 ) / div ;
* V_147 = ( V_224 + 50 ) / 100 * 100 ;
}
if( * V_147 != V_224 )
F_74 ( V_229 L_3 ,
V_224 , * V_147 ) ;
}
}
static int T_3
F_75 ( struct V_214 * V_215 , char * V_230 )
{
struct V_1 * V_2 ;
int V_147 = 9600 ;
int V_221 = 8 ;
int V_83 = 'n' ;
int V_231 = 'n' ;
if ( V_215 -> V_219 == - 1 || V_215 -> V_219 >= F_76 ( V_218 ) )
V_215 -> V_219 = 0 ;
V_2 = V_218 [ V_215 -> V_219 ] ;
if( V_2 == NULL )
return - V_191 ;
if ( V_230 )
F_77 ( V_230 , & V_147 , & V_83 , & V_221 , & V_231 ) ;
else
F_72 ( V_2 , & V_147 , & V_83 , & V_221 ) ;
F_42 ( V_2 , 0 ) ;
return F_78 ( & V_2 -> V_8 , V_215 , V_147 , V_83 , V_221 , V_231 ) ;
}
static int F_79 ( struct V_184 * V_138 , T_4 V_30 )
{
struct V_1 * V_2 = F_80 ( V_138 ) ;
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_64 |= V_232 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 )
F_81 ( & V_233 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_82 ( struct V_184 * V_138 )
{
struct V_1 * V_2 = F_80 ( V_138 ) ;
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_64 &= ~ V_232 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 )
F_83 ( & V_233 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_184 * V_185 )
{
struct V_234 * V_235 = V_185 -> V_138 . V_236 ;
const struct V_237 * V_238 =
F_85 ( V_239 , & V_185 -> V_138 ) ;
int V_190 ;
if ( ! V_235 )
return 1 ;
V_190 = F_86 ( V_235 , L_4 ) ;
if ( V_190 < 0 ) {
F_87 ( & V_185 -> V_138 , L_5 , V_190 ) ;
return V_190 ;
}
V_2 -> V_8 . line = V_190 ;
if ( F_88 ( V_235 , L_6 , NULL ) )
V_2 -> V_164 = 1 ;
if ( F_88 ( V_235 , L_7 , NULL ) )
V_2 -> V_240 = 1 ;
V_2 -> V_3 = V_238 -> V_32 ;
return 0 ;
}
static inline int F_84 ( struct V_1 * V_2 ,
struct V_184 * V_185 )
{
return 1 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_184 * V_185 )
{
struct V_136 * V_137 = V_185 -> V_138 . V_139 ;
V_2 -> V_8 . line = V_185 -> V_241 ;
V_2 -> V_3 = (struct V_242 * ) V_185 -> V_243 -> V_244 ;
if ( ! V_137 )
return;
if ( V_137 -> V_33 & V_245 )
V_2 -> V_164 = 1 ;
if ( V_137 -> V_33 & V_246 )
V_2 -> V_240 = 1 ;
}
static int F_90 ( struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
void T_5 * V_247 ;
int V_190 = 0 ;
struct V_186 * V_248 ;
struct V_249 * V_249 ;
V_2 = F_91 ( sizeof( * V_2 ) , V_250 ) ;
if ( ! V_2 )
return - V_251 ;
V_190 = F_84 ( V_2 , V_185 ) ;
if ( V_190 > 0 )
F_89 ( V_2 , V_185 ) ;
else if ( V_190 < 0 )
goto free;
V_248 = F_60 ( V_185 , V_188 , 0 ) ;
if ( ! V_248 ) {
V_190 = - V_191 ;
goto free;
}
V_247 = F_92 ( V_248 -> V_189 , V_252 ) ;
if ( ! V_247 ) {
V_190 = - V_251 ;
goto free;
}
V_2 -> V_8 . V_138 = & V_185 -> V_138 ;
V_2 -> V_8 . V_201 = V_248 -> V_189 ;
V_2 -> V_8 . V_12 = V_247 ;
V_2 -> V_8 . type = V_183 ,
V_2 -> V_8 . V_253 = V_199 ;
V_2 -> V_8 . V_62 = F_93 ( V_185 , 0 ) ;
V_2 -> V_121 = F_93 ( V_185 , 0 ) ;
V_2 -> V_120 = F_93 ( V_185 , 1 ) ;
V_2 -> V_125 = F_93 ( V_185 , 2 ) ;
V_2 -> V_8 . V_254 = 32 ;
V_2 -> V_8 . V_20 = & V_255 ;
V_2 -> V_8 . V_33 = V_256 ;
F_94 ( & V_2 -> V_35 ) ;
V_2 -> V_35 . V_257 = F_12 ;
V_2 -> V_35 . V_32 = ( unsigned long ) V_2 ;
V_249 = F_95 ( & V_185 -> V_138 ) ;
if ( F_96 ( V_249 ) ) {
V_190 = F_97 ( V_249 ) ;
goto V_258;
}
V_2 -> V_259 = F_98 ( & V_185 -> V_138 , L_8 ) ;
if ( F_96 ( V_2 -> V_259 ) ) {
V_190 = F_97 ( V_2 -> V_259 ) ;
goto V_258;
}
V_2 -> V_226 = F_98 ( & V_185 -> V_138 , L_9 ) ;
if ( F_96 ( V_2 -> V_226 ) ) {
V_190 = F_97 ( V_2 -> V_226 ) ;
goto V_258;
}
F_99 ( V_2 -> V_226 ) ;
F_99 ( V_2 -> V_259 ) ;
V_2 -> V_8 . V_172 = F_73 ( V_2 -> V_226 ) ;
V_218 [ V_2 -> V_8 . line ] = V_2 ;
V_137 = V_185 -> V_138 . V_139 ;
if ( V_137 && V_137 -> V_260 ) {
V_190 = V_137 -> V_260 ( V_185 ) ;
if ( V_190 )
goto V_261;
}
V_190 = F_100 ( & V_233 , & V_2 -> V_8 ) ;
if ( V_190 )
goto V_262;
F_101 ( V_185 , & V_2 -> V_8 ) ;
return 0 ;
V_262:
if ( V_137 && V_137 -> exit )
V_137 -> exit ( V_185 ) ;
V_261:
F_102 ( V_2 -> V_226 ) ;
F_102 ( V_2 -> V_259 ) ;
V_258:
F_103 ( V_2 -> V_8 . V_12 ) ;
free:
F_104 ( V_2 ) ;
return V_190 ;
}
static int F_105 ( struct V_184 * V_185 )
{
struct V_136 * V_137 ;
struct V_1 * V_2 = F_80 ( V_185 ) ;
V_137 = V_185 -> V_138 . V_139 ;
F_101 ( V_185 , NULL ) ;
F_106 ( & V_233 , & V_2 -> V_8 ) ;
F_102 ( V_2 -> V_226 ) ;
F_102 ( V_2 -> V_259 ) ;
if ( V_137 && V_137 -> exit )
V_137 -> exit ( V_185 ) ;
F_103 ( V_2 -> V_8 . V_12 ) ;
F_104 ( V_2 ) ;
return 0 ;
}
static int T_3 F_107 ( void )
{
int V_190 ;
F_74 ( V_229 L_10 ) ;
V_190 = F_108 ( & V_233 ) ;
if ( V_190 )
return V_190 ;
V_190 = F_109 ( & V_263 ) ;
if ( V_190 != 0 )
F_110 ( & V_233 ) ;
return V_190 ;
}
static void T_6 F_111 ( void )
{
F_112 ( & V_263 ) ;
F_110 ( & V_233 ) ;
}
