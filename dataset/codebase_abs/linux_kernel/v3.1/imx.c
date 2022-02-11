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
if ( V_65 & ( V_73 | V_74 | V_75 ) ) {
if ( V_65 & V_73 )
V_2 -> V_9 . V_14 . V_76 ++ ;
else if ( V_65 & V_75 )
V_2 -> V_9 . V_14 . V_77 ++ ;
if ( V_65 & V_74 )
V_2 -> V_9 . V_14 . V_78 ++ ;
if ( V_65 & V_2 -> V_9 . V_79 ) {
if ( ++ V_67 > 100 )
goto V_64;
continue;
}
V_65 &= V_2 -> V_9 . V_80 ;
if ( V_65 & V_73 )
V_66 = V_81 ;
else if ( V_65 & V_75 )
V_66 = V_82 ;
if ( V_65 & V_74 )
V_66 = V_83 ;
#ifdef F_31
V_2 -> V_9 . V_84 = 0 ;
#endif
}
F_32 ( V_69 , V_65 , V_66 ) ;
}
V_64:
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
F_33 ( V_69 ) ;
return V_62 ;
}
static T_1 F_34 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
unsigned int V_85 ;
V_85 = F_14 ( V_2 -> V_9 . V_31 + V_60 ) ;
if ( V_85 & V_86 )
F_28 ( V_56 , V_57 ) ;
if ( V_85 & V_87 &&
F_14 ( V_2 -> V_9 . V_31 + V_35 ) & V_36 )
F_26 ( V_56 , V_57 ) ;
if ( V_85 & V_59 )
F_25 ( V_56 , V_57 ) ;
return V_62 ;
}
static unsigned int F_35 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) ? V_88 : 0 ;
}
static unsigned int F_36 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_89 = V_16 | V_18 ;
if ( F_14 ( V_2 -> V_9 . V_31 + V_60 ) & V_61 )
V_89 |= V_19 ;
if ( F_14 ( V_2 -> V_9 . V_31 + V_44 ) & V_90 )
V_89 |= V_91 ;
return V_89 ;
}
static void F_37 ( struct V_28 * V_9 , unsigned int V_92 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) & ~ V_90 ;
if ( V_92 & V_91 )
V_29 |= V_90 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
}
static void F_38 ( struct V_28 * V_9 , int V_93 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_23 , V_29 ;
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) & ~ V_94 ;
if ( V_93 != 0 )
V_29 |= V_94 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_95 )
{
unsigned int V_58 ;
unsigned int V_96 ;
V_58 = V_97 << 10 | V_98 ;
V_96 = ( F_40 ( V_2 -> V_99 ) + V_2 -> V_9 . V_100 / 2 )
/ V_2 -> V_9 . V_100 ;
if( ! V_96 )
V_96 = 1 ;
V_58 |= F_41 ( V_96 ) ;
F_17 ( V_58 , V_2 -> V_9 . V_31 + V_101 ) ;
return 0 ;
}
static int F_42 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_102 ;
unsigned long V_23 , V_29 ;
F_39 ( V_2 , 0 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
if ( F_13 ( V_2 ) )
V_29 |= V_103 ;
V_29 &= ~ ( V_104 << V_105 ) ;
V_29 |= V_106 << V_105 ;
F_17 ( V_29 & ~ V_43 , V_2 -> V_9 . V_31 + V_38 ) ;
if ( F_13 ( V_2 ) ) {
int V_107 = 100 ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
V_29 &= ~ V_108 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
while ( ! ( F_14 ( V_2 -> V_9 . V_31 + V_44 ) & V_108 ) &&
( -- V_107 > 0 ) ) {
F_15 ( 1 ) ;
}
}
if ( V_2 -> V_109 > 0 ) {
V_102 = F_43 ( V_2 -> V_110 , F_28 , 0 ,
V_111 , V_2 ) ;
if ( V_102 )
goto V_112;
V_102 = F_43 ( V_2 -> V_109 , F_26 , 0 ,
V_111 , V_2 ) ;
if ( V_102 )
goto V_113;
if ( ! F_13 ( V_2 ) ) {
V_102 = F_43 ( V_2 -> V_114 , F_25 ,
( V_2 -> V_114 < V_115 ) ? 0 :
V_116 |
V_117 ,
V_111 , V_2 ) ;
if ( V_102 )
goto V_118;
}
} else {
V_102 = F_43 ( V_2 -> V_9 . V_56 , F_34 , 0 ,
V_111 , V_2 ) ;
if ( V_102 ) {
F_44 ( V_2 -> V_9 . V_56 , V_2 ) ;
goto V_112;
}
}
F_17 ( V_59 , V_2 -> V_9 . V_31 + V_60 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 |= V_42 | V_119 | V_120 ;
if ( F_13 ( V_2 ) ) {
V_29 |= V_121 ;
V_29 &= ~ ( V_119 ) ;
}
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
V_29 |= ( V_45 | V_122 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_13 ( V_2 ) ) {
int V_107 = 64 ;
while ( ( -- V_107 > 0 ) &&
( F_14 ( V_2 -> V_9 . V_31 + V_40 ) & V_41 ) ) {
F_16 () ;
}
}
if ( F_3 ( V_2 ) ) {
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_123 ) ;
V_29 |= V_124 ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_123 ) ;
}
if ( F_13 ( V_2 ) ) {
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_38 ) ;
if ( V_2 -> V_125 )
V_29 |= V_126 ;
else
V_29 &= ~ ( V_126 ) ;
F_17 ( V_29 | V_43 , V_2 -> V_9 . V_31 + V_38 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_123 ) ;
if ( V_2 -> V_127 )
V_29 |= V_128 ;
else
V_29 &= ~ ( V_128 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_123 ) ;
}
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
F_19 ( & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
if ( F_13 ( V_2 ) ) {
struct V_129 * V_130 ;
V_130 = V_2 -> V_9 . V_131 -> V_132 ;
V_2 -> V_125 = V_130 -> V_125 ;
V_2 -> V_127 = V_130 -> V_127 ;
V_2 -> V_34 = V_130 -> V_133 ;
if ( V_130 -> V_134 )
V_130 -> V_134 ( 1 ) ;
}
return 0 ;
V_118:
if ( V_2 -> V_109 )
F_44 ( V_2 -> V_109 , V_2 ) ;
V_113:
if ( V_2 -> V_110 )
F_44 ( V_2 -> V_110 , V_2 ) ;
V_112:
return V_102 ;
}
static void F_45 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
V_29 &= ~ ( V_122 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_13 ( V_2 ) ) {
struct V_129 * V_130 ;
V_130 = V_2 -> V_9 . V_131 -> V_132 ;
if ( V_130 -> V_134 )
V_130 -> V_134 ( 0 ) ;
}
F_46 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_109 > 0 ) {
if ( ! F_13 ( V_2 ) )
F_44 ( V_2 -> V_114 , V_2 ) ;
F_44 ( V_2 -> V_109 , V_2 ) ;
F_44 ( V_2 -> V_110 , V_2 ) ;
} else
F_44 ( V_2 -> V_9 . V_56 , V_2 ) ;
V_29 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_29 &= ~ ( V_36 | V_42 | V_119 | V_120 ) ;
if ( F_13 ( V_2 ) )
V_29 &= ~ ( V_121 ) ;
F_17 ( V_29 , V_2 -> V_9 . V_31 + V_35 ) ;
}
static void
F_47 ( struct V_28 * V_9 , struct V_135 * V_136 ,
struct V_135 * V_137 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_23 ;
unsigned int V_138 , V_139 , V_140 , V_141 , V_142 ;
unsigned int V_143 = V_137 ? V_137 -> V_144 & V_145 : V_146 ;
unsigned int div , V_147 ;
unsigned long V_148 , V_149 ;
T_2 V_150 ;
if ( 0 ) {
V_136 -> V_144 &= ~ ( V_151 | V_152 | V_153 ) ;
V_136 -> V_144 |= V_154 ;
}
while ( ( V_136 -> V_144 & V_145 ) != V_155 &&
( V_136 -> V_144 & V_145 ) != V_146 ) {
V_136 -> V_144 &= ~ V_145 ;
V_136 -> V_144 |= V_143 ;
V_143 = V_146 ;
}
if ( ( V_136 -> V_144 & V_145 ) == V_146 )
V_138 = V_156 | V_108 | V_157 ;
else
V_138 = V_108 | V_157 ;
if ( V_136 -> V_144 & V_152 ) {
if( V_2 -> V_158 ) {
V_138 &= ~ V_157 ;
V_138 |= V_159 ;
} else {
V_136 -> V_144 &= ~ V_152 ;
}
}
if ( V_136 -> V_144 & V_160 )
V_138 |= V_161 ;
if ( V_136 -> V_144 & V_162 ) {
V_138 |= V_163 ;
if ( V_136 -> V_144 & V_164 )
V_138 |= V_165 ;
}
V_141 = F_48 ( V_9 , V_136 , V_137 , 50 , V_9 -> V_100 / 16 ) ;
V_142 = F_49 ( V_9 , V_141 ) ;
F_9 ( & V_2 -> V_9 . V_24 , V_23 ) ;
V_2 -> V_9 . V_80 = 0 ;
if ( V_136 -> V_166 & V_167 )
V_2 -> V_9 . V_80 |= ( V_75 | V_73 ) ;
if ( V_136 -> V_166 & ( V_168 | V_169 ) )
V_2 -> V_9 . V_80 |= V_170 ;
V_2 -> V_9 . V_79 = 0 ;
if ( V_136 -> V_166 & V_171 )
V_2 -> V_9 . V_79 |= V_73 ;
if ( V_136 -> V_166 & V_172 ) {
V_2 -> V_9 . V_79 |= V_170 ;
if ( V_136 -> V_166 & V_171 )
V_2 -> V_9 . V_79 |= V_74 ;
}
F_46 ( & V_2 -> V_25 ) ;
F_50 ( V_9 , V_136 -> V_144 , V_141 ) ;
V_139 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_139 & ~ ( V_36 | V_42 | V_119 ) ,
V_2 -> V_9 . V_31 + V_35 ) ;
while ( ! ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) )
F_16 () ;
V_140 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
F_17 ( V_140 & ~ ( V_122 | V_45 ) ,
V_2 -> V_9 . V_31 + V_44 ) ;
V_140 &= ( V_122 | V_45 ) ;
if ( F_13 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_9 . V_100 / ( V_141 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_51 ( 16 * div * V_141 , V_2 -> V_9 . V_100 ,
1 << 16 , 1 << 16 , & V_148 , & V_149 ) ;
V_150 = V_2 -> V_9 . V_100 ;
V_150 *= V_148 ;
F_52 ( V_150 , V_149 * 16 * div ) ;
F_53 ( V_136 ,
( V_173 ) V_150 , ( V_173 ) V_150 ) ;
V_148 -= 1 ;
V_149 -= 1 ;
V_147 = F_14 ( V_2 -> V_9 . V_31 + V_101 ) ;
V_147 = ( V_147 & ( ~ V_174 ) ) | F_41 ( div ) ;
F_17 ( V_147 , V_2 -> V_9 . V_31 + V_101 ) ;
F_17 ( V_148 , V_2 -> V_9 . V_31 + V_175 ) ;
F_17 ( V_149 , V_2 -> V_9 . V_31 + V_176 ) ;
if ( F_3 ( V_2 ) )
F_17 ( V_2 -> V_9 . V_100 / div / 1000 ,
V_2 -> V_9 . V_31 + V_177 ) ;
F_17 ( V_139 , V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_138 | V_140 , V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_54 ( & V_2 -> V_9 , V_136 -> V_144 ) )
F_19 ( & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_9 . V_24 , V_23 ) ;
}
static const char * F_55 ( struct V_28 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_178 ? L_1 : NULL ;
}
static void F_56 ( struct V_28 * V_9 )
{
struct V_179 * V_180 = F_57 ( V_9 -> V_131 ) ;
struct V_181 * V_182 ;
V_182 = F_58 ( V_180 , V_183 , 0 ) ;
F_59 ( V_182 -> V_184 , F_60 ( V_182 ) ) ;
}
static int F_61 ( struct V_28 * V_9 )
{
struct V_179 * V_180 = F_57 ( V_9 -> V_131 ) ;
struct V_181 * V_182 ;
void * V_185 ;
V_182 = F_58 ( V_180 , V_183 , 0 ) ;
if ( ! V_182 )
return - V_186 ;
V_185 = F_62 ( V_182 -> V_184 , F_60 ( V_182 ) , L_2 ) ;
return V_185 ? 0 : - V_187 ;
}
static void F_63 ( struct V_28 * V_9 , int V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_23 & V_188 &&
F_61 ( & V_2 -> V_9 ) == 0 )
V_2 -> V_9 . type = V_178 ;
}
static int
F_64 ( struct V_28 * V_9 , struct V_189 * V_190 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_185 = 0 ;
if ( V_190 -> type != V_191 && V_190 -> type != V_178 )
V_185 = - V_192 ;
if ( V_2 -> V_9 . V_56 != V_190 -> V_56 )
V_185 = - V_192 ;
if ( V_190 -> V_193 != V_194 )
V_185 = - V_192 ;
if ( V_2 -> V_9 . V_100 / 16 != V_190 -> V_195 )
V_185 = - V_192 ;
if ( ( void * ) V_2 -> V_9 . V_196 != V_190 -> V_197 )
V_185 = - V_192 ;
if ( V_2 -> V_9 . V_198 != V_190 -> V_9 )
V_185 = - V_192 ;
if ( V_190 -> V_199 != 0 )
V_185 = - V_192 ;
return V_185 ;
}
static void F_65 ( struct V_28 * V_9 , int V_200 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_14 ( V_2 -> V_9 . V_31 + F_1 ( V_2 ) ) & V_48 )
F_16 () ;
F_17 ( V_200 , V_2 -> V_9 . V_31 + V_51 ) ;
}
static void
F_66 ( struct V_201 * V_202 , const char * V_203 , unsigned int V_204 )
{
struct V_1 * V_2 = V_205 [ V_202 -> V_206 ] ;
unsigned int V_139 , V_207 , V_208 ;
V_208 = V_139 = F_14 ( V_2 -> V_9 . V_31 + V_35 ) ;
V_207 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
if ( F_2 ( V_2 ) )
V_208 |= V_209 ;
V_208 |= V_120 ;
V_208 &= ~ ( V_36 | V_42 | V_119 ) ;
F_17 ( V_208 , V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_207 | V_122 , V_2 -> V_9 . V_31 + V_44 ) ;
F_67 ( & V_2 -> V_9 , V_203 , V_204 , F_65 ) ;
while ( ! ( F_14 ( V_2 -> V_9 . V_31 + V_32 ) & V_33 ) ) ;
F_17 ( V_139 , V_2 -> V_9 . V_31 + V_35 ) ;
F_17 ( V_207 , V_2 -> V_9 . V_31 + V_44 ) ;
}
static void T_3
F_68 ( struct V_1 * V_2 , int * V_141 ,
int * V_76 , int * V_210 )
{
if ( F_14 ( V_2 -> V_9 . V_31 + V_35 ) & V_120 ) {
unsigned int V_138 , V_211 , V_212 , V_100 ;
unsigned int V_213 ;
unsigned int V_214 ;
V_138 = F_14 ( V_2 -> V_9 . V_31 + V_44 ) ;
* V_76 = 'n' ;
if ( V_138 & V_163 ) {
if ( V_138 & V_165 )
* V_76 = 'o' ;
else
* V_76 = 'e' ;
}
if ( V_138 & V_156 )
* V_210 = 8 ;
else
* V_210 = 7 ;
V_211 = F_14 ( V_2 -> V_9 . V_31 + V_175 ) & 0xffff ;
V_212 = F_14 ( V_2 -> V_9 . V_31 + V_176 ) & 0xffff ;
V_214 = ( F_14 ( V_2 -> V_9 . V_31 + V_101 ) & V_174 ) >> 7 ;
if ( V_214 == 6 )
V_214 = 7 ;
else
V_214 = 6 - V_214 ;
V_100 = F_40 ( V_2 -> V_99 ) ;
V_100 /= V_214 ;
{
unsigned int V_215 = V_211 + 1 ;
unsigned int div = 16 * ( V_212 + 1 ) ;
unsigned int V_216 = V_100 % div ;
V_213 = ( V_100 / div ) * V_215 ;
V_213 += ( V_216 * V_215 + div / 2 ) / div ;
* V_141 = ( V_213 + 50 ) / 100 * 100 ;
}
if( * V_141 != V_213 )
F_69 ( V_217 L_3 ,
V_213 , * V_141 ) ;
}
}
static int T_3
F_70 ( struct V_201 * V_202 , char * V_218 )
{
struct V_1 * V_2 ;
int V_141 = 9600 ;
int V_210 = 8 ;
int V_76 = 'n' ;
int V_219 = 'n' ;
if ( V_202 -> V_206 == - 1 || V_202 -> V_206 >= F_71 ( V_205 ) )
V_202 -> V_206 = 0 ;
V_2 = V_205 [ V_202 -> V_206 ] ;
if( V_2 == NULL )
return - V_186 ;
if ( V_218 )
F_72 ( V_218 , & V_141 , & V_76 , & V_210 , & V_219 ) ;
else
F_68 ( V_2 , & V_141 , & V_76 , & V_210 ) ;
F_39 ( V_2 , 0 ) ;
return F_73 ( & V_2 -> V_9 , V_202 , V_141 , V_76 , V_210 , V_219 ) ;
}
static int F_74 ( struct V_179 * V_131 , T_4 V_20 )
{
struct V_1 * V_2 = F_75 ( V_131 ) ;
if ( V_2 )
F_76 ( & V_220 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_77 ( struct V_179 * V_131 )
{
struct V_1 * V_2 = F_75 ( V_131 ) ;
if ( V_2 )
F_78 ( & V_220 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_179 * V_180 )
{
static int V_221 = 0 ;
struct V_222 * V_223 = V_180 -> V_131 . V_224 ;
const struct V_225 * V_226 =
F_80 ( V_227 , & V_180 -> V_131 ) ;
if ( ! V_223 )
return - V_186 ;
V_2 -> V_9 . line = V_221 ++ ;
if ( V_2 -> V_9 . line >= V_228 )
return - V_192 ;
if ( F_81 ( V_223 , L_4 , NULL ) )
V_2 -> V_158 = 1 ;
if ( F_81 ( V_223 , L_5 , NULL ) )
V_2 -> V_229 = 1 ;
V_2 -> V_3 = V_226 -> V_22 ;
return 0 ;
}
static inline int F_79 ( struct V_1 * V_2 ,
struct V_179 * V_180 )
{
return - V_186 ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_179 * V_180 )
{
struct V_129 * V_130 = V_180 -> V_131 . V_132 ;
V_2 -> V_9 . line = V_180 -> V_230 ;
V_2 -> V_3 = (struct V_231 * ) V_180 -> V_232 -> V_233 ;
if ( ! V_130 )
return;
if ( V_130 -> V_23 & V_234 )
V_2 -> V_158 = 1 ;
if ( V_130 -> V_23 & V_235 )
V_2 -> V_229 = 1 ;
}
static int F_83 ( struct V_179 * V_180 )
{
struct V_1 * V_2 ;
struct V_129 * V_130 ;
void T_5 * V_236 ;
int V_185 = 0 ;
struct V_181 * V_237 ;
V_2 = F_84 ( sizeof( * V_2 ) , V_238 ) ;
if ( ! V_2 )
return - V_239 ;
V_185 = F_79 ( V_2 , V_180 ) ;
if ( V_185 == - V_186 )
F_82 ( V_2 , V_180 ) ;
V_237 = F_58 ( V_180 , V_183 , 0 ) ;
if ( ! V_237 ) {
V_185 = - V_186 ;
goto free;
}
V_236 = F_85 ( V_237 -> V_184 , V_240 ) ;
if ( ! V_236 ) {
V_185 = - V_239 ;
goto free;
}
V_2 -> V_9 . V_131 = & V_180 -> V_131 ;
V_2 -> V_9 . V_196 = V_237 -> V_184 ;
V_2 -> V_9 . V_31 = V_236 ;
V_2 -> V_9 . type = V_178 ,
V_2 -> V_9 . V_241 = V_194 ;
V_2 -> V_9 . V_56 = F_86 ( V_180 , 0 ) ;
V_2 -> V_110 = F_86 ( V_180 , 0 ) ;
V_2 -> V_109 = F_86 ( V_180 , 1 ) ;
V_2 -> V_114 = F_86 ( V_180 , 2 ) ;
V_2 -> V_9 . V_242 = 32 ;
V_2 -> V_9 . V_10 = & V_243 ;
V_2 -> V_9 . V_23 = V_244 ;
F_87 ( & V_2 -> V_25 ) ;
V_2 -> V_25 . V_245 = F_8 ;
V_2 -> V_25 . V_22 = ( unsigned long ) V_2 ;
V_2 -> V_99 = F_88 ( & V_180 -> V_131 , L_6 ) ;
if ( F_89 ( V_2 -> V_99 ) ) {
V_185 = F_90 ( V_2 -> V_99 ) ;
goto V_246;
}
F_91 ( V_2 -> V_99 ) ;
V_2 -> V_9 . V_100 = F_40 ( V_2 -> V_99 ) ;
V_205 [ V_2 -> V_9 . line ] = V_2 ;
V_130 = V_180 -> V_131 . V_132 ;
if ( V_130 && V_130 -> V_247 ) {
V_185 = V_130 -> V_247 ( V_180 ) ;
if ( V_185 )
goto V_248;
}
V_185 = F_92 ( & V_220 , & V_2 -> V_9 ) ;
if ( V_185 )
goto V_249;
F_93 ( V_180 , & V_2 -> V_9 ) ;
return 0 ;
V_249:
if ( V_130 && V_130 -> exit )
V_130 -> exit ( V_180 ) ;
V_248:
F_94 ( V_2 -> V_99 ) ;
F_95 ( V_2 -> V_99 ) ;
V_246:
F_96 ( V_2 -> V_9 . V_31 ) ;
free:
F_97 ( V_2 ) ;
return V_185 ;
}
static int F_98 ( struct V_179 * V_180 )
{
struct V_129 * V_130 ;
struct V_1 * V_2 = F_75 ( V_180 ) ;
V_130 = V_180 -> V_131 . V_132 ;
F_93 ( V_180 , NULL ) ;
if ( V_2 ) {
F_99 ( & V_220 , & V_2 -> V_9 ) ;
F_94 ( V_2 -> V_99 ) ;
}
F_95 ( V_2 -> V_99 ) ;
if ( V_130 && V_130 -> exit )
V_130 -> exit ( V_180 ) ;
F_96 ( V_2 -> V_9 . V_31 ) ;
F_97 ( V_2 ) ;
return 0 ;
}
static int T_3 F_100 ( void )
{
int V_185 ;
F_69 ( V_217 L_7 ) ;
V_185 = F_101 ( & V_220 ) ;
if ( V_185 )
return V_185 ;
V_185 = F_102 ( & V_250 ) ;
if ( V_185 != 0 )
F_103 ( & V_220 ) ;
return 0 ;
}
static void T_6 F_104 ( void )
{
F_105 ( & V_250 ) ;
F_103 ( & V_220 ) ;
}
