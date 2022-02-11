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
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_7 , V_8 ;
V_7 = V_2 -> V_9 . V_10 -> V_11 ( & V_2 -> V_9 ) ;
V_8 = V_7 ^ V_2 -> V_12 ;
if ( V_8 == 0 )
return;
V_2 -> V_12 = V_7 ;
if ( V_8 & V_13 )
V_2 -> V_9 . V_14 . V_15 ++ ;
if ( V_8 & V_16 )
V_2 -> V_9 . V_14 . V_17 ++ ;
if ( V_8 & V_18 )
F_5 ( & V_2 -> V_9 , V_7 & V_18 ) ;
if ( V_8 & V_19 )
F_6 ( & V_2 -> V_9 , V_7 & V_19 ) ;
F_7 ( & V_2 -> V_9 . V_20 -> V_9 . V_21 ) ;
}
static void F_8 ( unsigned long V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
unsigned long V_23 ;
if ( V_2 -> V_9 . V_20 ) {
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
F_4 ( V_2 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
F_11 ( & V_2 -> V_25 , V_26 + V_27 ) ;
}
}
static void F_12 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
if ( F_13 ( V_2 ) ) {
int V_30 = 256 ;
while ( ( -- V_30 > 0 ) &&
! ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) ) {
F_15 ( 5 ) ;
F_16 () ;
}
F_15 ( V_2 -> V_34 ) ;
if ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) {
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 &= ~ ( V_36 | V_37 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
V_29 &= ~ ( V_39 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_38 ) ;
while ( F_14 ( V_2 -> V_9 . V_31 + V_40 ) &
V_41 )
F_16 () ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 |= V_42 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
V_29 |= V_43 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_38 ) ;
}
return;
}
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_29 & ~ V_36 , V_2 -> V_9 . V_31 + V_35 ) ;
}
static void F_18 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
F_17 ( V_29 & ~ V_45 , V_2 -> V_9 . V_31 + V_44 ) ;
}
static void F_19 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_11 ( & V_2 -> V_25 , V_26 ) ;
}
static inline void F_20 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_9 . V_20 -> V_47 ;
while ( ! F_21 ( V_47 ) &&
! ( F_14 ( V_2 -> V_9 . V_31 + F_1 ( V_2 ) )
& V_48 ) ) {
F_17 ( V_47 -> V_49 [ V_47 -> V_50 ] , V_2 -> V_9 . V_31 + V_51 ) ;
V_47 -> V_50 = ( V_47 -> V_50 + 1 ) & ( V_52 - 1 ) ;
V_2 -> V_9 . V_14 . V_53 ++ ;
}
if ( F_22 ( V_47 ) < V_54 )
F_23 ( & V_2 -> V_9 ) ;
if ( F_21 ( V_47 ) )
F_12 ( & V_2 -> V_9 ) ;
}
static void F_24 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
if ( F_13 ( V_2 ) ) {
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
V_29 &= ~ ( V_43 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_38 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 &= ~ ( V_42 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
}
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_29 | V_36 , V_2 -> V_9 . V_31 + V_35 ) ;
if ( F_13 ( V_2 ) ) {
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 |= V_37 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
V_29 |= V_39 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_38 ) ;
}
if ( F_14 ( V_2 -> V_9 . V_31 + F_1 ( V_2 ) ) & V_55 )
F_20 ( V_2 ) ;
}
static T_1 F_25 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
unsigned int V_58 ;
unsigned long V_23 ;
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
F_17 ( V_59 , V_2 -> V_9 . V_31 + V_60 ) ;
V_58 = F_14 ( V_2 -> V_9 . V_31 + V_60 ) & V_61 ;
F_6 ( & V_2 -> V_9 , ! ! V_58 ) ;
F_7 ( & V_2 -> V_9 . V_20 -> V_9 . V_21 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
return V_62 ;
}
static T_1 F_26 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_46 * V_47 = & V_2 -> V_9 . V_20 -> V_47 ;
unsigned long V_23 ;
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
if ( V_2 -> V_9 . V_63 )
{
F_17 ( V_2 -> V_9 . V_63 , V_2 -> V_9 . V_31 + V_51 ) ;
goto V_64;
}
if ( F_21 ( V_47 ) || F_27 ( & V_2 -> V_9 ) ) {
F_12 ( & V_2 -> V_9 ) ;
goto V_64;
}
F_20 ( V_2 ) ;
if ( F_22 ( V_47 ) < V_54 )
F_23 ( & V_2 -> V_9 ) ;
V_64:
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
return V_62 ;
}
static T_1 F_28 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
unsigned int V_65 , V_66 , V_67 = 0 ;
struct V_68 * V_69 = V_2 -> V_9 . V_20 -> V_9 . V_69 ;
unsigned long V_23 , V_29 ;
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
while ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_70 ) {
V_66 = V_71 ;
V_2 -> V_9 . V_14 . V_65 ++ ;
V_65 = F_14 ( V_2 -> V_9 . V_31 + V_40 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_32 ) ;
if ( V_29 & V_72 ) {
F_17 ( V_72 , V_2 -> V_9 . V_31 + V_32 ) ;
if ( F_29 ( & V_2 -> V_9 ) )
continue;
}
if ( F_30 ( & V_2 -> V_9 , ( unsigned char ) V_65 ) )
continue;
if ( F_31 ( V_65 & V_73 ) ) {
if ( V_65 & V_74 )
V_2 -> V_9 . V_14 . V_75 ++ ;
else if ( V_65 & V_76 )
V_2 -> V_9 . V_14 . V_77 ++ ;
else if ( V_65 & V_78 )
V_2 -> V_9 . V_14 . V_79 ++ ;
if ( V_65 & V_80 )
V_2 -> V_9 . V_14 . V_81 ++ ;
if ( V_65 & V_2 -> V_9 . V_82 ) {
if ( ++ V_67 > 100 )
goto V_64;
continue;
}
V_65 &= V_2 -> V_9 . V_83 ;
if ( V_65 & V_74 )
V_66 = V_84 ;
else if ( V_65 & V_76 )
V_66 = V_85 ;
else if ( V_65 & V_78 )
V_66 = V_86 ;
if ( V_65 & V_80 )
V_66 = V_87 ;
#ifdef F_32
V_2 -> V_9 . V_88 = 0 ;
#endif
}
F_33 ( V_69 , V_65 , V_66 ) ;
}
V_64:
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
F_34 ( V_69 ) ;
return V_62 ;
}
static T_1 F_35 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
unsigned int V_89 ;
V_89 = F_14 ( V_2 -> V_9 . V_31 + V_60 ) ;
if ( V_89 & V_90 )
F_28 ( V_56 , V_57 ) ;
if ( V_89 & V_91 &&
F_14 ( V_2 -> V_9 . V_31 + V_35 ) & V_36 )
F_26 ( V_56 , V_57 ) ;
if ( V_89 & V_59 )
F_25 ( V_56 , V_57 ) ;
return V_62 ;
}
static unsigned int F_36 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) ? V_92 : 0 ;
}
static unsigned int F_37 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_93 = V_16 | V_18 ;
if ( F_14 ( V_2 -> V_9 . V_31 + V_60 ) & V_61 )
V_93 |= V_19 ;
if ( F_14 ( V_2 -> V_9 . V_31 + V_44 ) & V_94 )
V_93 |= V_95 ;
return V_93 ;
}
static void F_38 ( struct V_28 * V_9 , unsigned int V_96 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) & ~ V_94 ;
if ( V_96 & V_95 )
V_29 |= V_94 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
}
static void F_39 ( struct V_28 * V_9 , int V_97 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_23 , V_29 ;
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) & ~ V_98 ;
if ( V_97 != 0 )
V_29 |= V_98 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_99 )
{
unsigned int V_58 ;
unsigned int V_100 ;
V_58 = V_101 << 10 | V_102 ;
V_100 = ( F_41 ( V_2 -> V_103 ) + V_2 -> V_9 . V_104 / 2 )
/ V_2 -> V_9 . V_104 ;
if( ! V_100 )
V_100 = 1 ;
V_58 |= F_42 ( V_100 ) ;
F_17 ( V_58 , V_2 -> V_9 . V_31 + V_105 ) ;
return 0 ;
}
static int F_43 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_106 ;
unsigned long V_23 , V_29 ;
F_40 ( V_2 , 0 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
if ( F_13 ( V_2 ) )
V_29 |= V_107 ;
V_29 &= ~ ( V_108 << V_109 ) ;
V_29 |= V_110 << V_109 ;
F_17 ( V_29 & ~ V_43 , V_2 -> V_9 . V_31 + V_38 ) ;
if ( F_13 ( V_2 ) ) {
int V_111 = 100 ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
V_29 &= ~ V_112 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
while ( ! ( F_14 ( V_2 -> V_9 . V_31 + V_44 ) & V_112 ) &&
( -- V_111 > 0 ) ) {
F_15 ( 1 ) ;
}
}
if ( V_2 -> V_113 > 0 ) {
V_106 = F_44 ( V_2 -> V_114 , F_28 , 0 ,
V_115 , V_2 ) ;
if ( V_106 )
goto V_116;
V_106 = F_44 ( V_2 -> V_113 , F_26 , 0 ,
V_115 , V_2 ) ;
if ( V_106 )
goto V_117;
if ( ! F_13 ( V_2 ) ) {
V_106 = F_44 ( V_2 -> V_118 , F_25 ,
( V_2 -> V_118 < V_119 ) ? 0 :
V_120 |
V_121 ,
V_115 , V_2 ) ;
if ( V_106 )
goto V_122;
}
} else {
V_106 = F_44 ( V_2 -> V_9 . V_56 , F_35 , 0 ,
V_115 , V_2 ) ;
if ( V_106 ) {
F_45 ( V_2 -> V_9 . V_56 , V_2 ) ;
goto V_116;
}
}
F_17 ( V_59 , V_2 -> V_9 . V_31 + V_60 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 |= V_42 | V_123 | V_124 ;
if ( F_13 ( V_2 ) ) {
V_29 |= V_125 ;
V_29 &= ~ ( V_123 ) ;
}
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
V_29 |= ( V_45 | V_126 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_13 ( V_2 ) ) {
int V_111 = 64 ;
while ( ( -- V_111 > 0 ) &&
( F_14 ( V_2 -> V_9 . V_31 + V_40 ) & V_41 ) ) {
F_16 () ;
}
}
if ( F_3 ( V_2 ) ) {
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_127 ) ;
V_29 |= V_128 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_127 ) ;
}
if ( F_13 ( V_2 ) ) {
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
if ( V_2 -> V_129 )
V_29 |= V_130 ;
else
V_29 &= ~ ( V_130 ) ;
F_17 ( V_29 | V_43 , V_2 -> V_9 . V_31 + V_38 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_127 ) ;
if ( V_2 -> V_131 )
V_29 |= V_132 ;
else
V_29 &= ~ ( V_132 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_127 ) ;
}
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
F_19 ( & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
if ( F_13 ( V_2 ) ) {
struct V_133 * V_134 ;
V_134 = V_2 -> V_9 . V_135 -> V_136 ;
V_2 -> V_129 = V_134 -> V_129 ;
V_2 -> V_131 = V_134 -> V_131 ;
V_2 -> V_34 = V_134 -> V_137 ;
if ( V_134 -> V_138 )
V_134 -> V_138 ( 1 ) ;
}
return 0 ;
V_122:
if ( V_2 -> V_113 )
F_45 ( V_2 -> V_113 , V_2 ) ;
V_117:
if ( V_2 -> V_114 )
F_45 ( V_2 -> V_114 , V_2 ) ;
V_116:
return V_106 ;
}
static void F_46 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
V_29 &= ~ ( V_126 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_13 ( V_2 ) ) {
struct V_133 * V_134 ;
V_134 = V_2 -> V_9 . V_135 -> V_136 ;
if ( V_134 -> V_138 )
V_134 -> V_138 ( 0 ) ;
}
F_47 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_113 > 0 ) {
if ( ! F_13 ( V_2 ) )
F_45 ( V_2 -> V_118 , V_2 ) ;
F_45 ( V_2 -> V_113 , V_2 ) ;
F_45 ( V_2 -> V_114 , V_2 ) ;
} else
F_45 ( V_2 -> V_9 . V_56 , V_2 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 &= ~ ( V_36 | V_42 | V_123 | V_124 ) ;
if ( F_13 ( V_2 ) )
V_29 &= ~ ( V_125 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
}
static void
F_48 ( struct V_28 * V_9 , struct V_139 * V_140 ,
struct V_139 * V_141 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_23 ;
unsigned int V_142 , V_143 , V_144 , V_145 , V_146 ;
unsigned int V_147 = V_141 ? V_141 -> V_148 & V_149 : V_150 ;
unsigned int div , V_151 ;
unsigned long V_152 , V_153 ;
T_2 V_154 ;
if ( 0 ) {
V_140 -> V_148 &= ~ ( V_155 | V_156 | V_157 ) ;
V_140 -> V_148 |= V_158 ;
}
while ( ( V_140 -> V_148 & V_149 ) != V_159 &&
( V_140 -> V_148 & V_149 ) != V_150 ) {
V_140 -> V_148 &= ~ V_149 ;
V_140 -> V_148 |= V_147 ;
V_147 = V_150 ;
}
if ( ( V_140 -> V_148 & V_149 ) == V_150 )
V_142 = V_160 | V_112 | V_161 ;
else
V_142 = V_112 | V_161 ;
if ( V_140 -> V_148 & V_156 ) {
if( V_2 -> V_162 ) {
V_142 &= ~ V_161 ;
V_142 |= V_163 ;
} else {
V_140 -> V_148 &= ~ V_156 ;
}
}
if ( V_140 -> V_148 & V_164 )
V_142 |= V_165 ;
if ( V_140 -> V_148 & V_166 ) {
V_142 |= V_167 ;
if ( V_140 -> V_148 & V_168 )
V_142 |= V_169 ;
}
V_145 = F_49 ( V_9 , V_140 , V_141 , 50 , V_9 -> V_104 / 16 ) ;
V_146 = F_50 ( V_9 , V_145 ) ;
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
V_2 -> V_9 . V_83 = 0 ;
if ( V_140 -> V_170 & V_171 )
V_2 -> V_9 . V_83 |= ( V_78 | V_76 ) ;
if ( V_140 -> V_170 & ( V_172 | V_173 ) )
V_2 -> V_9 . V_83 |= V_74 ;
V_2 -> V_9 . V_82 = 0 ;
if ( V_140 -> V_170 & V_174 )
V_2 -> V_9 . V_82 |= V_76 ;
if ( V_140 -> V_170 & V_175 ) {
V_2 -> V_9 . V_82 |= V_74 ;
if ( V_140 -> V_170 & V_174 )
V_2 -> V_9 . V_82 |= V_80 ;
}
F_47 ( & V_2 -> V_25 ) ;
F_51 ( V_9 , V_140 -> V_148 , V_145 ) ;
V_143 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_143 & ~ ( V_36 | V_42 | V_123 ) ,
V_2 -> V_9 . V_31 + V_35 ) ;
while ( ! ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) )
F_16 () ;
V_144 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
F_17 ( V_144 & ~ ( V_126 | V_45 ) ,
V_2 -> V_9 . V_31 + V_44 ) ;
V_144 &= ( V_126 | V_45 ) ;
if ( F_13 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_9 . V_104 / ( V_145 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_52 ( 16 * div * V_145 , V_2 -> V_9 . V_104 ,
1 << 16 , 1 << 16 , & V_152 , & V_153 ) ;
V_154 = V_2 -> V_9 . V_104 ;
V_154 *= V_152 ;
F_53 ( V_154 , V_153 * 16 * div ) ;
F_54 ( V_140 ,
( V_176 ) V_154 , ( V_176 ) V_154 ) ;
V_152 -= 1 ;
V_153 -= 1 ;
V_151 = F_14 ( V_2 -> V_9 . V_31 + V_105 ) ;
V_151 = ( V_151 & ( ~ V_177 ) ) | F_42 ( div ) ;
F_17 ( V_151 , V_2 -> V_9 . V_31 + V_105 ) ;
F_17 ( V_152 , V_2 -> V_9 . V_31 + V_178 ) ;
F_17 ( V_153 , V_2 -> V_9 . V_31 + V_179 ) ;
if ( F_3 ( V_2 ) )
F_17 ( V_2 -> V_9 . V_104 / div / 1000 ,
V_2 -> V_9 . V_31 + V_180 ) ;
F_17 ( V_143 , V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_142 | V_144 , V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_55 ( & V_2 -> V_9 , V_140 -> V_148 ) )
F_19 ( & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
}
static const char * F_56 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_181 ? L_1 : NULL ;
}
static void F_57 ( struct V_28 * V_9 )
{
struct V_182 * V_183 = F_58 ( V_9 -> V_135 ) ;
struct V_184 * V_185 ;
V_185 = F_59 ( V_183 , V_186 , 0 ) ;
F_60 ( V_185 -> V_187 , F_61 ( V_185 ) ) ;
}
static int F_62 ( struct V_28 * V_9 )
{
struct V_182 * V_183 = F_58 ( V_9 -> V_135 ) ;
struct V_184 * V_185 ;
void * V_188 ;
V_185 = F_59 ( V_183 , V_186 , 0 ) ;
if ( ! V_185 )
return - V_189 ;
V_188 = F_63 ( V_185 -> V_187 , F_61 ( V_185 ) , L_2 ) ;
return V_188 ? 0 : - V_190 ;
}
static void F_64 ( struct V_28 * V_9 , int V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_23 & V_191 &&
F_62 ( & V_2 -> V_9 ) == 0 )
V_2 -> V_9 . type = V_181 ;
}
static int
F_65 ( struct V_28 * V_9 , struct V_192 * V_193 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_188 = 0 ;
if ( V_193 -> type != V_194 && V_193 -> type != V_181 )
V_188 = - V_195 ;
if ( V_2 -> V_9 . V_56 != V_193 -> V_56 )
V_188 = - V_195 ;
if ( V_193 -> V_196 != V_197 )
V_188 = - V_195 ;
if ( V_2 -> V_9 . V_104 / 16 != V_193 -> V_198 )
V_188 = - V_195 ;
if ( ( void * ) V_2 -> V_9 . V_199 != V_193 -> V_200 )
V_188 = - V_195 ;
if ( V_2 -> V_9 . V_201 != V_193 -> V_9 )
V_188 = - V_195 ;
if ( V_193 -> V_202 != 0 )
V_188 = - V_195 ;
return V_188 ;
}
static void F_66 ( struct V_28 * V_9 , int V_203 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_14 ( V_2 -> V_9 . V_31 + F_1 ( V_2 ) ) & V_48 )
F_16 () ;
F_17 ( V_203 , V_2 -> V_9 . V_31 + V_51 ) ;
}
static void
F_67 ( struct V_204 * V_205 , const char * V_206 , unsigned int V_207 )
{
struct V_1 * V_2 = V_208 [ V_205 -> V_209 ] ;
unsigned int V_143 , V_210 , V_211 ;
V_211 = V_143 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_210 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_2 ( V_2 ) )
V_211 |= V_212 ;
V_211 |= V_124 ;
V_211 &= ~ ( V_36 | V_42 | V_123 ) ;
F_17 ( V_211 , V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_210 | V_126 , V_2 -> V_9 . V_31 + V_44 ) ;
F_68 ( & V_2 -> V_9 , V_206 , V_207 , F_66 ) ;
while ( ! ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) ) ;
F_17 ( V_143 , V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_210 , V_2 -> V_9 . V_31 + V_44 ) ;
}
static void T_3
F_69 ( struct V_1 * V_2 , int * V_145 ,
int * V_77 , int * V_213 )
{
if ( F_14 ( V_2 -> V_9 . V_31 + V_35 ) & V_124 ) {
unsigned int V_142 , V_214 , V_215 , V_104 ;
unsigned int V_216 ;
unsigned int V_217 ;
V_142 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
* V_77 = 'n' ;
if ( V_142 & V_167 ) {
if ( V_142 & V_169 )
* V_77 = 'o' ;
else
* V_77 = 'e' ;
}
if ( V_142 & V_160 )
* V_213 = 8 ;
else
* V_213 = 7 ;
V_214 = F_14 ( V_2 -> V_9 . V_31 + V_178 ) & 0xffff ;
V_215 = F_14 ( V_2 -> V_9 . V_31 + V_179 ) & 0xffff ;
V_217 = ( F_14 ( V_2 -> V_9 . V_31 + V_105 ) & V_177 ) >> 7 ;
if ( V_217 == 6 )
V_217 = 7 ;
else
V_217 = 6 - V_217 ;
V_104 = F_41 ( V_2 -> V_103 ) ;
V_104 /= V_217 ;
{
unsigned int V_218 = V_214 + 1 ;
unsigned int div = 16 * ( V_215 + 1 ) ;
unsigned int V_219 = V_104 % div ;
V_216 = ( V_104 / div ) * V_218 ;
V_216 += ( V_219 * V_218 + div / 2 ) / div ;
* V_145 = ( V_216 + 50 ) / 100 * 100 ;
}
if( * V_145 != V_216 )
F_70 ( V_220 L_3 ,
V_216 , * V_145 ) ;
}
}
static int T_3
F_71 ( struct V_204 * V_205 , char * V_221 )
{
struct V_1 * V_2 ;
int V_145 = 9600 ;
int V_213 = 8 ;
int V_77 = 'n' ;
int V_222 = 'n' ;
if ( V_205 -> V_209 == - 1 || V_205 -> V_209 >= F_72 ( V_208 ) )
V_205 -> V_209 = 0 ;
V_2 = V_208 [ V_205 -> V_209 ] ;
if( V_2 == NULL )
return - V_189 ;
if ( V_221 )
F_73 ( V_221 , & V_145 , & V_77 , & V_213 , & V_222 ) ;
else
F_69 ( V_2 , & V_145 , & V_77 , & V_213 ) ;
F_40 ( V_2 , 0 ) ;
return F_74 ( & V_2 -> V_9 , V_205 , V_145 , V_77 , V_213 , V_222 ) ;
}
static int F_75 ( struct V_182 * V_135 , T_4 V_20 )
{
struct V_1 * V_2 = F_76 ( V_135 ) ;
if ( V_2 )
F_77 ( & V_223 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_78 ( struct V_182 * V_135 )
{
struct V_1 * V_2 = F_76 ( V_135 ) ;
if ( V_2 )
F_79 ( & V_223 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
struct V_224 * V_225 = V_183 -> V_135 . V_226 ;
const struct V_227 * V_228 =
F_81 ( V_229 , & V_183 -> V_135 ) ;
int V_188 ;
if ( ! V_225 )
return - V_189 ;
V_188 = F_82 ( V_225 , L_4 ) ;
if ( V_188 < 0 ) {
F_83 ( & V_183 -> V_135 , L_5 , V_188 ) ;
return - V_189 ;
}
V_2 -> V_9 . line = V_188 ;
if ( F_84 ( V_225 , L_6 , NULL ) )
V_2 -> V_162 = 1 ;
if ( F_84 ( V_225 , L_7 , NULL ) )
V_2 -> V_230 = 1 ;
V_2 -> V_3 = V_228 -> V_22 ;
return 0 ;
}
static inline int F_80 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
return - V_189 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
struct V_133 * V_134 = V_183 -> V_135 . V_136 ;
V_2 -> V_9 . line = V_183 -> V_231 ;
V_2 -> V_3 = (struct V_232 * ) V_183 -> V_233 -> V_234 ;
if ( ! V_134 )
return;
if ( V_134 -> V_23 & V_235 )
V_2 -> V_162 = 1 ;
if ( V_134 -> V_23 & V_236 )
V_2 -> V_230 = 1 ;
}
static int F_86 ( struct V_182 * V_183 )
{
struct V_1 * V_2 ;
struct V_133 * V_134 ;
void T_5 * V_237 ;
int V_188 = 0 ;
struct V_184 * V_238 ;
V_2 = F_87 ( sizeof( * V_2 ) , V_239 ) ;
if ( ! V_2 )
return - V_240 ;
V_188 = F_80 ( V_2 , V_183 ) ;
if ( V_188 == - V_189 )
F_85 ( V_2 , V_183 ) ;
V_238 = F_59 ( V_183 , V_186 , 0 ) ;
if ( ! V_238 ) {
V_188 = - V_189 ;
goto free;
}
V_237 = F_88 ( V_238 -> V_187 , V_241 ) ;
if ( ! V_237 ) {
V_188 = - V_240 ;
goto free;
}
V_2 -> V_9 . V_135 = & V_183 -> V_135 ;
V_2 -> V_9 . V_199 = V_238 -> V_187 ;
V_2 -> V_9 . V_31 = V_237 ;
V_2 -> V_9 . type = V_181 ,
V_2 -> V_9 . V_242 = V_197 ;
V_2 -> V_9 . V_56 = F_89 ( V_183 , 0 ) ;
V_2 -> V_114 = F_89 ( V_183 , 0 ) ;
V_2 -> V_113 = F_89 ( V_183 , 1 ) ;
V_2 -> V_118 = F_89 ( V_183 , 2 ) ;
V_2 -> V_9 . V_243 = 32 ;
V_2 -> V_9 . V_10 = & V_244 ;
V_2 -> V_9 . V_23 = V_245 ;
F_90 ( & V_2 -> V_25 ) ;
V_2 -> V_25 . V_246 = F_8 ;
V_2 -> V_25 . V_22 = ( unsigned long ) V_2 ;
V_2 -> V_103 = F_91 ( & V_183 -> V_135 , L_8 ) ;
if ( F_92 ( V_2 -> V_103 ) ) {
V_188 = F_93 ( V_2 -> V_103 ) ;
goto V_247;
}
F_94 ( V_2 -> V_103 ) ;
V_2 -> V_9 . V_104 = F_41 ( V_2 -> V_103 ) ;
V_208 [ V_2 -> V_9 . line ] = V_2 ;
V_134 = V_183 -> V_135 . V_136 ;
if ( V_134 && V_134 -> V_248 ) {
V_188 = V_134 -> V_248 ( V_183 ) ;
if ( V_188 )
goto V_249;
}
V_188 = F_95 ( & V_223 , & V_2 -> V_9 ) ;
if ( V_188 )
goto V_250;
F_96 ( V_183 , & V_2 -> V_9 ) ;
return 0 ;
V_250:
if ( V_134 && V_134 -> exit )
V_134 -> exit ( V_183 ) ;
V_249:
F_97 ( V_2 -> V_103 ) ;
F_98 ( V_2 -> V_103 ) ;
V_247:
F_99 ( V_2 -> V_9 . V_31 ) ;
free:
F_100 ( V_2 ) ;
return V_188 ;
}
static int F_101 ( struct V_182 * V_183 )
{
struct V_133 * V_134 ;
struct V_1 * V_2 = F_76 ( V_183 ) ;
V_134 = V_183 -> V_135 . V_136 ;
F_96 ( V_183 , NULL ) ;
if ( V_2 ) {
F_102 ( & V_223 , & V_2 -> V_9 ) ;
F_97 ( V_2 -> V_103 ) ;
}
F_98 ( V_2 -> V_103 ) ;
if ( V_134 && V_134 -> exit )
V_134 -> exit ( V_183 ) ;
F_99 ( V_2 -> V_9 . V_31 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
static int T_3 F_103 ( void )
{
int V_188 ;
F_70 ( V_220 L_9 ) ;
V_188 = F_104 ( & V_223 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_105 ( & V_251 ) ;
if ( V_188 != 0 )
F_106 ( & V_223 ) ;
return 0 ;
}
static void T_6 F_107 ( void )
{
F_108 ( & V_251 ) ;
F_106 ( & V_223 ) ;
}
