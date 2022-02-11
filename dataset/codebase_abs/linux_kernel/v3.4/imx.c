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
unsigned int V_107 ;
V_64 = V_108 << 10 | V_109 ;
V_107 = ( F_43 ( V_2 -> V_110 ) + V_2 -> V_8 . V_111 / 2 )
/ V_2 -> V_8 . V_111 ;
if( ! V_107 )
V_107 = 1 ;
V_64 |= F_44 ( V_107 ) ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_112 ) ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 )
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
V_113 = F_46 ( V_2 -> V_121 , F_30 , 0 ,
V_122 , V_2 ) ;
if ( V_113 )
goto V_123;
V_113 = F_46 ( V_2 -> V_120 , F_28 , 0 ,
V_122 , V_2 ) ;
if ( V_113 )
goto V_124;
if ( ! F_17 ( V_2 ) ) {
V_113 = F_46 ( V_2 -> V_125 , F_27 ,
( V_2 -> V_125 < V_126 ) ? 0 :
V_127 |
V_128 ,
V_122 , V_2 ) ;
if ( V_113 )
goto V_129;
}
} else {
V_113 = F_46 ( V_2 -> V_8 . V_62 , F_37 , 0 ,
V_122 , V_2 ) ;
if ( V_113 ) {
F_47 ( V_2 -> V_8 . V_62 , V_2 ) ;
goto V_123;
}
}
F_7 ( V_65 , V_2 -> V_8 . V_12 + V_66 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 |= V_49 | V_130 | V_131 ;
if ( F_17 ( V_2 ) ) {
V_38 |= V_132 ;
V_38 &= ~ ( V_130 ) ;
}
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 |= ( V_51 | V_133 ) ;
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
V_38 |= V_134 ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
if ( F_17 ( V_2 ) ) {
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_45 ) ;
if ( V_2 -> V_135 )
V_38 |= V_136 ;
else
V_38 &= ~ ( V_136 ) ;
F_7 ( V_38 | V_50 , V_2 -> V_8 . V_12 + V_45 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 -> V_137 )
V_38 |= V_138 ;
else
V_38 &= ~ ( V_138 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_17 ) ;
}
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
if ( F_17 ( V_2 ) ) {
struct V_139 * V_140 ;
V_140 = V_2 -> V_8 . V_141 -> V_142 ;
V_2 -> V_135 = V_140 -> V_135 ;
V_2 -> V_137 = V_140 -> V_137 ;
V_2 -> V_42 = V_140 -> V_143 ;
if ( V_140 -> V_144 )
V_140 -> V_144 ( 1 ) ;
}
return 0 ;
V_129:
if ( V_2 -> V_120 )
F_47 ( V_2 -> V_120 , V_2 ) ;
V_124:
if ( V_2 -> V_121 )
F_47 ( V_2 -> V_121 , V_2 ) ;
V_123:
return V_113 ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_38 ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
V_38 &= ~ ( V_133 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_17 ( V_2 ) ) {
struct V_139 * V_140 ;
V_140 = V_2 -> V_8 . V_141 -> V_142 ;
if ( V_140 -> V_144 )
V_140 -> V_144 ( 0 ) ;
}
F_49 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_120 > 0 ) {
if ( ! F_17 ( V_2 ) )
F_47 ( V_2 -> V_125 , V_2 ) ;
F_47 ( V_2 -> V_120 , V_2 ) ;
F_47 ( V_2 -> V_121 , V_2 ) ;
} else
F_47 ( V_2 -> V_8 . V_62 , V_2 ) ;
V_38 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
V_38 &= ~ ( V_43 | V_49 | V_130 | V_131 ) ;
if ( F_17 ( V_2 ) )
V_38 &= ~ ( V_132 ) ;
F_7 ( V_38 , V_2 -> V_8 . V_12 + V_13 ) ;
}
static void
F_50 ( struct V_7 * V_8 , struct V_145 * V_146 ,
struct V_145 * V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_33 ;
unsigned int V_14 , V_148 , V_149 , V_150 , V_151 ;
unsigned int V_152 = V_147 ? V_147 -> V_153 & V_154 : V_155 ;
unsigned int div , V_156 ;
unsigned long V_157 , V_158 ;
T_2 V_159 ;
if ( 0 ) {
V_146 -> V_153 &= ~ ( V_160 | V_161 | V_162 ) ;
V_146 -> V_153 |= V_163 ;
}
while ( ( V_146 -> V_153 & V_154 ) != V_164 &&
( V_146 -> V_153 & V_154 ) != V_155 ) {
V_146 -> V_153 &= ~ V_154 ;
V_146 -> V_153 |= V_152 ;
V_152 = V_155 ;
}
if ( ( V_146 -> V_153 & V_154 ) == V_155 )
V_14 = V_165 | V_119 | V_166 ;
else
V_14 = V_119 | V_166 ;
if ( V_146 -> V_153 & V_161 ) {
if( V_2 -> V_167 ) {
V_14 &= ~ V_166 ;
V_14 |= V_168 ;
} else {
V_146 -> V_153 &= ~ V_161 ;
}
}
if ( V_146 -> V_153 & V_169 )
V_14 |= V_170 ;
if ( V_146 -> V_153 & V_171 ) {
V_14 |= V_172 ;
if ( V_146 -> V_153 & V_173 )
V_14 |= V_174 ;
}
F_49 ( & V_2 -> V_35 ) ;
V_150 = F_51 ( V_8 , V_146 , V_147 , 50 , V_8 -> V_111 / 16 ) ;
V_151 = F_52 ( V_8 , V_150 ) ;
F_13 ( & V_2 -> V_8 . V_34 , V_33 ) ;
V_2 -> V_8 . V_89 = 0 ;
if ( V_146 -> V_175 & V_176 )
V_2 -> V_8 . V_89 |= ( V_84 | V_82 ) ;
if ( V_146 -> V_175 & ( V_177 | V_178 ) )
V_2 -> V_8 . V_89 |= V_80 ;
V_2 -> V_8 . V_88 = 0 ;
if ( V_146 -> V_175 & V_179 )
V_2 -> V_8 . V_88 |= V_82 ;
if ( V_146 -> V_175 & V_180 ) {
V_2 -> V_8 . V_88 |= V_80 ;
if ( V_146 -> V_175 & V_179 )
V_2 -> V_8 . V_88 |= V_86 ;
}
F_53 ( V_8 , V_146 -> V_153 , V_150 ) ;
V_148 = F_5 ( V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_148 & ~ ( V_43 | V_49 | V_130 ) ,
V_2 -> V_8 . V_12 + V_13 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) )
F_19 () ;
V_149 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
F_7 ( V_149 & ~ ( V_133 | V_51 ) ,
V_2 -> V_8 . V_12 + V_15 ) ;
V_149 &= ( V_133 | V_51 ) ;
if ( F_17 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_8 . V_111 / ( V_150 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_54 ( 16 * div * V_150 , V_2 -> V_8 . V_111 ,
1 << 16 , 1 << 16 , & V_157 , & V_158 ) ;
V_159 = V_2 -> V_8 . V_111 ;
V_159 *= V_157 ;
F_55 ( V_159 , V_158 * 16 * div ) ;
F_56 ( V_146 ,
( V_181 ) V_159 , ( V_181 ) V_159 ) ;
V_157 -= 1 ;
V_158 -= 1 ;
V_156 = F_5 ( V_2 -> V_8 . V_12 + V_112 ) ;
V_156 = ( V_156 & ( ~ V_182 ) ) | F_44 ( div ) ;
F_7 ( V_156 , V_2 -> V_8 . V_12 + V_112 ) ;
F_7 ( V_157 , V_2 -> V_8 . V_12 + V_183 ) ;
F_7 ( V_158 , V_2 -> V_8 . V_12 + V_184 ) ;
if ( F_3 ( V_2 ) )
F_7 ( V_2 -> V_8 . V_111 / div / 1000 ,
V_2 -> V_8 . V_12 + V_185 ) ;
F_7 ( V_148 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_14 | V_149 , V_2 -> V_8 . V_12 + V_15 ) ;
if ( F_57 ( & V_2 -> V_8 , V_146 -> V_153 ) )
F_21 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_8 . V_34 , V_33 ) ;
}
static const char * F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_186 ? L_1 : NULL ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_187 * V_188 = F_60 ( V_8 -> V_141 ) ;
struct V_189 * V_190 ;
V_190 = F_61 ( V_188 , V_191 , 0 ) ;
F_62 ( V_190 -> V_192 , F_63 ( V_190 ) ) ;
}
static int F_64 ( struct V_7 * V_8 )
{
struct V_187 * V_188 = F_60 ( V_8 -> V_141 ) ;
struct V_189 * V_190 ;
void * V_193 ;
V_190 = F_61 ( V_188 , V_191 , 0 ) ;
if ( ! V_190 )
return - V_194 ;
V_193 = F_65 ( V_190 -> V_192 , F_63 ( V_190 ) , L_2 ) ;
return V_193 ? 0 : - V_195 ;
}
static void F_66 ( struct V_7 * V_8 , int V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( V_33 & V_196 &&
F_64 ( & V_2 -> V_8 ) == 0 )
V_2 -> V_8 . type = V_186 ;
}
static int
F_67 ( struct V_7 * V_8 , struct V_197 * V_198 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_193 = 0 ;
if ( V_198 -> type != V_199 && V_198 -> type != V_186 )
V_193 = - V_200 ;
if ( V_2 -> V_8 . V_62 != V_198 -> V_62 )
V_193 = - V_200 ;
if ( V_198 -> V_201 != V_202 )
V_193 = - V_200 ;
if ( V_2 -> V_8 . V_111 / 16 != V_198 -> V_203 )
V_193 = - V_200 ;
if ( ( void * ) V_2 -> V_8 . V_204 != V_198 -> V_205 )
V_193 = - V_200 ;
if ( V_2 -> V_8 . V_206 != V_198 -> V_8 )
V_193 = - V_200 ;
if ( V_198 -> V_207 != 0 )
V_193 = - V_200 ;
return V_193 ;
}
static int F_68 ( struct V_7 * V_8 )
{
struct V_9 V_208 ;
unsigned int V_18 ;
unsigned char V_209 ;
F_4 ( V_8 , & V_208 ) ;
F_7 ( V_131 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_208 . V_14 & ~ ( V_210 | V_211 | V_212 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_208 . V_16 & ~ ( V_213 | V_214 | V_215 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_76 );
V_209 = F_5 ( V_8 -> V_12 + V_47 ) ;
F_6 ( V_8 , & V_208 ) ;
return V_209 ;
}
static void F_69 ( struct V_7 * V_8 , unsigned char V_209 )
{
struct V_9 V_208 ;
unsigned int V_18 ;
F_4 ( V_8 , & V_208 ) ;
F_7 ( V_131 , V_8 -> V_12 + V_13 ) ;
F_7 ( V_208 . V_14 & ~ ( V_210 | V_211 | V_212 ) ,
V_8 -> V_12 + V_15 ) ;
F_7 ( V_208 . V_16 & ~ ( V_213 | V_214 | V_215 ) ,
V_8 -> V_12 + V_17 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_66 ) ;
} while ( ~ V_18 & V_97 );
F_7 ( V_209 , V_8 -> V_12 + V_57 ) ;
do {
V_18 = F_5 ( V_8 -> V_12 + V_40 ) ;
} while ( ~ V_18 & V_41 );
F_6 ( V_8 , & V_208 ) ;
}
static void F_70 ( struct V_7 * V_8 , int V_216 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_5 ( V_2 -> V_8 . V_12 + F_1 ( V_2 ) ) & V_54 )
F_19 () ;
F_7 ( V_216 , V_2 -> V_8 . V_12 + V_57 ) ;
}
static void
F_71 ( struct V_217 * V_218 , const char * V_219 , unsigned int V_220 )
{
struct V_1 * V_2 = V_221 [ V_218 -> V_222 ] ;
struct V_9 V_208 ;
unsigned int V_11 ;
F_4 ( & V_2 -> V_8 , & V_208 ) ;
V_11 = V_208 . V_11 ;
if ( F_2 ( V_2 ) )
V_11 |= V_223 ;
V_11 |= V_131 ;
V_11 &= ~ ( V_43 | V_49 | V_130 ) ;
F_7 ( V_11 , V_2 -> V_8 . V_12 + V_13 ) ;
F_7 ( V_208 . V_14 | V_133 , V_2 -> V_8 . V_12 + V_15 ) ;
F_72 ( & V_2 -> V_8 , V_219 , V_220 , F_70 ) ;
while ( ! ( F_5 ( V_2 -> V_8 . V_12 + V_40 ) & V_41 ) ) ;
F_6 ( & V_2 -> V_8 , & V_208 ) ;
}
static void T_3
F_73 ( struct V_1 * V_2 , int * V_150 ,
int * V_83 , int * V_224 )
{
if ( F_5 ( V_2 -> V_8 . V_12 + V_13 ) & V_131 ) {
unsigned int V_14 , V_225 , V_226 , V_111 ;
unsigned int V_227 ;
unsigned int V_228 ;
V_14 = F_5 ( V_2 -> V_8 . V_12 + V_15 ) ;
* V_83 = 'n' ;
if ( V_14 & V_172 ) {
if ( V_14 & V_174 )
* V_83 = 'o' ;
else
* V_83 = 'e' ;
}
if ( V_14 & V_165 )
* V_224 = 8 ;
else
* V_224 = 7 ;
V_225 = F_5 ( V_2 -> V_8 . V_12 + V_183 ) & 0xffff ;
V_226 = F_5 ( V_2 -> V_8 . V_12 + V_184 ) & 0xffff ;
V_228 = ( F_5 ( V_2 -> V_8 . V_12 + V_112 ) & V_182 ) >> 7 ;
if ( V_228 == 6 )
V_228 = 7 ;
else
V_228 = 6 - V_228 ;
V_111 = F_43 ( V_2 -> V_110 ) ;
V_111 /= V_228 ;
{
unsigned int V_229 = V_225 + 1 ;
unsigned int div = 16 * ( V_226 + 1 ) ;
unsigned int V_230 = V_111 % div ;
V_227 = ( V_111 / div ) * V_229 ;
V_227 += ( V_230 * V_229 + div / 2 ) / div ;
* V_150 = ( V_227 + 50 ) / 100 * 100 ;
}
if( * V_150 != V_227 )
F_74 ( V_231 L_3 ,
V_227 , * V_150 ) ;
}
}
static int T_3
F_75 ( struct V_217 * V_218 , char * V_232 )
{
struct V_1 * V_2 ;
int V_150 = 9600 ;
int V_224 = 8 ;
int V_83 = 'n' ;
int V_233 = 'n' ;
if ( V_218 -> V_222 == - 1 || V_218 -> V_222 >= F_76 ( V_221 ) )
V_218 -> V_222 = 0 ;
V_2 = V_221 [ V_218 -> V_222 ] ;
if( V_2 == NULL )
return - V_194 ;
if ( V_232 )
F_77 ( V_232 , & V_150 , & V_83 , & V_224 , & V_233 ) ;
else
F_73 ( V_2 , & V_150 , & V_83 , & V_224 ) ;
F_42 ( V_2 , 0 ) ;
return F_78 ( & V_2 -> V_8 , V_218 , V_150 , V_83 , V_224 , V_233 ) ;
}
static int F_79 ( struct V_187 * V_141 , T_4 V_30 )
{
struct V_1 * V_2 = F_80 ( V_141 ) ;
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_64 |= V_234 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 )
F_81 ( & V_235 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_82 ( struct V_187 * V_141 )
{
struct V_1 * V_2 = F_80 ( V_141 ) ;
unsigned int V_64 ;
V_64 = F_5 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_64 &= ~ V_234 ;
F_7 ( V_64 , V_2 -> V_8 . V_12 + V_17 ) ;
if ( V_2 )
F_83 ( & V_235 , & V_2 -> V_8 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
struct V_236 * V_237 = V_188 -> V_141 . V_238 ;
const struct V_239 * V_240 =
F_85 ( V_241 , & V_188 -> V_141 ) ;
int V_193 ;
if ( ! V_237 )
return 1 ;
V_193 = F_86 ( V_237 , L_4 ) ;
if ( V_193 < 0 ) {
F_87 ( & V_188 -> V_141 , L_5 , V_193 ) ;
return V_193 ;
}
V_2 -> V_8 . line = V_193 ;
if ( F_88 ( V_237 , L_6 , NULL ) )
V_2 -> V_167 = 1 ;
if ( F_88 ( V_237 , L_7 , NULL ) )
V_2 -> V_242 = 1 ;
V_2 -> V_3 = V_240 -> V_32 ;
return 0 ;
}
static inline int F_84 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
return 1 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
struct V_139 * V_140 = V_188 -> V_141 . V_142 ;
V_2 -> V_8 . line = V_188 -> V_243 ;
V_2 -> V_3 = (struct V_244 * ) V_188 -> V_245 -> V_246 ;
if ( ! V_140 )
return;
if ( V_140 -> V_33 & V_247 )
V_2 -> V_167 = 1 ;
if ( V_140 -> V_33 & V_248 )
V_2 -> V_242 = 1 ;
}
static int F_90 ( struct V_187 * V_188 )
{
struct V_1 * V_2 ;
struct V_139 * V_140 ;
void T_5 * V_249 ;
int V_193 = 0 ;
struct V_189 * V_250 ;
V_2 = F_91 ( sizeof( * V_2 ) , V_251 ) ;
if ( ! V_2 )
return - V_252 ;
V_193 = F_84 ( V_2 , V_188 ) ;
if ( V_193 > 0 )
F_89 ( V_2 , V_188 ) ;
else if ( V_193 < 0 )
goto free;
V_250 = F_61 ( V_188 , V_191 , 0 ) ;
if ( ! V_250 ) {
V_193 = - V_194 ;
goto free;
}
V_249 = F_92 ( V_250 -> V_192 , V_253 ) ;
if ( ! V_249 ) {
V_193 = - V_252 ;
goto free;
}
V_2 -> V_8 . V_141 = & V_188 -> V_141 ;
V_2 -> V_8 . V_204 = V_250 -> V_192 ;
V_2 -> V_8 . V_12 = V_249 ;
V_2 -> V_8 . type = V_186 ,
V_2 -> V_8 . V_254 = V_202 ;
V_2 -> V_8 . V_62 = F_93 ( V_188 , 0 ) ;
V_2 -> V_121 = F_93 ( V_188 , 0 ) ;
V_2 -> V_120 = F_93 ( V_188 , 1 ) ;
V_2 -> V_125 = F_93 ( V_188 , 2 ) ;
V_2 -> V_8 . V_255 = 32 ;
V_2 -> V_8 . V_20 = & V_256 ;
V_2 -> V_8 . V_33 = V_257 ;
F_94 ( & V_2 -> V_35 ) ;
V_2 -> V_35 . V_258 = F_12 ;
V_2 -> V_35 . V_32 = ( unsigned long ) V_2 ;
V_2 -> V_110 = F_95 ( & V_188 -> V_141 , L_8 ) ;
if ( F_96 ( V_2 -> V_110 ) ) {
V_193 = F_97 ( V_2 -> V_110 ) ;
goto V_259;
}
F_98 ( V_2 -> V_110 ) ;
V_2 -> V_8 . V_111 = F_43 ( V_2 -> V_110 ) ;
V_221 [ V_2 -> V_8 . line ] = V_2 ;
V_140 = V_188 -> V_141 . V_142 ;
if ( V_140 && V_140 -> V_260 ) {
V_193 = V_140 -> V_260 ( V_188 ) ;
if ( V_193 )
goto V_261;
}
V_193 = F_99 ( & V_235 , & V_2 -> V_8 ) ;
if ( V_193 )
goto V_262;
F_100 ( V_188 , & V_2 -> V_8 ) ;
return 0 ;
V_262:
if ( V_140 && V_140 -> exit )
V_140 -> exit ( V_188 ) ;
V_261:
F_101 ( V_2 -> V_110 ) ;
F_102 ( V_2 -> V_110 ) ;
V_259:
F_103 ( V_2 -> V_8 . V_12 ) ;
free:
F_104 ( V_2 ) ;
return V_193 ;
}
static int F_105 ( struct V_187 * V_188 )
{
struct V_139 * V_140 ;
struct V_1 * V_2 = F_80 ( V_188 ) ;
V_140 = V_188 -> V_141 . V_142 ;
F_100 ( V_188 , NULL ) ;
if ( V_2 ) {
F_106 ( & V_235 , & V_2 -> V_8 ) ;
F_101 ( V_2 -> V_110 ) ;
F_102 ( V_2 -> V_110 ) ;
}
if ( V_140 && V_140 -> exit )
V_140 -> exit ( V_188 ) ;
F_103 ( V_2 -> V_8 . V_12 ) ;
F_104 ( V_2 ) ;
return 0 ;
}
static int T_3 F_107 ( void )
{
int V_193 ;
F_74 ( V_231 L_9 ) ;
V_193 = F_108 ( & V_235 ) ;
if ( V_193 )
return V_193 ;
V_193 = F_109 ( & V_263 ) ;
if ( V_193 != 0 )
F_110 ( & V_235 ) ;
return V_193 ;
}
static void T_6 F_111 ( void )
{
F_112 ( & V_263 ) ;
F_110 ( & V_235 ) ;
}
