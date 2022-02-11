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
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_7 ;
}
static void F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_12 = F_6 ( V_9 -> V_13 + V_14 ) ;
V_11 -> V_15 = F_6 ( V_9 -> V_13 + V_16 ) ;
V_11 -> V_17 = F_6 ( V_9 -> V_13 + V_18 ) ;
}
static void F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
F_8 ( V_11 -> V_12 , V_9 -> V_13 + V_14 ) ;
F_8 ( V_11 -> V_15 , V_9 -> V_13 + V_16 ) ;
F_8 ( V_11 -> V_17 , V_9 -> V_13 + V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_19 , V_20 ;
V_19 = V_2 -> V_9 . V_21 -> V_22 ( & V_2 -> V_9 ) ;
V_20 = V_19 ^ V_2 -> V_23 ;
if ( V_20 == 0 )
return;
V_2 -> V_23 = V_19 ;
if ( V_20 & V_24 )
V_2 -> V_9 . V_25 . V_26 ++ ;
if ( V_20 & V_27 )
V_2 -> V_9 . V_25 . V_28 ++ ;
if ( V_20 & V_29 )
F_10 ( & V_2 -> V_9 , V_19 & V_29 ) ;
if ( V_20 & V_30 )
F_11 ( & V_2 -> V_9 , V_19 & V_30 ) ;
F_12 ( & V_2 -> V_9 . V_31 -> V_9 . V_32 ) ;
}
static void F_13 ( unsigned long V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
unsigned long V_34 ;
if ( V_2 -> V_9 . V_31 ) {
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_9 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_16 ( & V_2 -> V_36 , V_37 + V_38 ) ;
}
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
if ( V_2 -> V_40 && V_2 -> V_41 )
return;
V_39 = F_6 ( V_9 -> V_13 + V_14 ) ;
F_8 ( V_39 & ~ V_42 , V_9 -> V_13 + V_14 ) ;
if ( V_9 -> V_43 . V_34 & V_44 &&
F_6 ( V_9 -> V_13 + V_45 ) & V_46 ) {
V_39 = F_6 ( V_9 -> V_13 + V_16 ) ;
if ( V_9 -> V_43 . V_34 & V_47 )
V_39 &= ~ V_48 ;
else
V_39 |= V_48 ;
F_8 ( V_39 , V_9 -> V_13 + V_16 ) ;
V_39 = F_6 ( V_9 -> V_13 + V_49 ) ;
V_39 &= ~ V_50 ;
F_8 ( V_39 , V_9 -> V_13 + V_49 ) ;
}
}
static void F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
if ( V_2 -> V_40 && V_2 -> V_51 ) {
if ( V_2 -> V_9 . V_52 ) {
F_19 ( V_2 -> V_53 ) ;
V_2 -> V_51 = 0 ;
} else {
return;
}
}
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_39 & ~ V_54 , V_2 -> V_9 . V_13 + V_16 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_39 & ~ V_55 , V_2 -> V_9 . V_13 + V_14 ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_16 ( & V_2 -> V_36 , V_37 ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = & V_2 -> V_9 . V_31 -> V_57 ;
unsigned long V_39 ;
if ( V_2 -> V_9 . V_58 ) {
F_8 ( V_2 -> V_9 . V_58 , V_2 -> V_9 . V_13 + V_59 ) ;
V_2 -> V_9 . V_25 . V_60 ++ ;
V_2 -> V_9 . V_58 = 0 ;
return;
}
if ( F_22 ( V_57 ) || F_23 ( & V_2 -> V_9 ) ) {
F_17 ( & V_2 -> V_9 ) ;
return;
}
if ( V_2 -> V_40 ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_42 ;
if ( V_2 -> V_41 ) {
V_39 |= V_61 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
} else {
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_24 ( V_2 ) ;
}
}
while ( ! F_22 ( V_57 ) &&
! ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_62 ) ) {
F_8 ( V_57 -> V_63 [ V_57 -> V_64 ] , V_2 -> V_9 . V_13 + V_59 ) ;
V_57 -> V_64 = ( V_57 -> V_64 + 1 ) & ( V_65 - 1 ) ;
V_2 -> V_9 . V_25 . V_60 ++ ;
}
if ( F_25 ( V_57 ) < V_66 )
F_26 ( & V_2 -> V_9 ) ;
if ( F_22 ( V_57 ) )
F_17 ( & V_2 -> V_9 ) ;
}
static void F_27 ( void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_67 * V_68 = & V_2 -> V_69 [ 0 ] ;
struct V_56 * V_57 = & V_2 -> V_9 . V_31 -> V_57 ;
unsigned long V_34 ;
unsigned long V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_28 ( V_2 -> V_9 . V_70 , V_68 , V_2 -> V_71 , V_72 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_61 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_57 -> V_64 = ( V_57 -> V_64 + V_2 -> V_73 ) & ( V_65 - 1 ) ;
V_2 -> V_9 . V_25 . V_60 += V_2 -> V_73 ;
F_29 ( V_2 -> V_9 . V_70 , L_1 ) ;
V_2 -> V_41 = 0 ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( F_25 ( V_57 ) < V_66 )
F_26 ( & V_2 -> V_9 ) ;
if ( F_30 ( & V_2 -> V_74 ) ) {
F_31 ( & V_2 -> V_74 ) ;
F_29 ( V_2 -> V_9 . V_70 , L_2 , V_75 ) ;
return;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( ! F_22 ( V_57 ) && ! F_23 ( & V_2 -> V_9 ) )
F_24 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = & V_2 -> V_9 . V_31 -> V_57 ;
struct V_67 * V_68 = V_2 -> V_69 ;
struct V_76 * V_77 ;
struct V_78 * V_79 = V_2 -> V_80 ;
struct V_81 * V_70 = V_2 -> V_9 . V_70 ;
unsigned long V_39 ;
int V_82 ;
if ( V_2 -> V_41 )
return;
V_2 -> V_73 = F_25 ( V_57 ) ;
if ( V_57 -> V_64 < V_57 -> V_83 ) {
V_2 -> V_71 = 1 ;
F_32 ( V_68 , V_57 -> V_63 + V_57 -> V_64 , V_2 -> V_73 ) ;
} else {
V_2 -> V_71 = 2 ;
F_33 ( V_68 , 2 ) ;
F_34 ( V_68 , V_57 -> V_63 + V_57 -> V_64 ,
V_65 - V_57 -> V_64 ) ;
F_34 ( V_68 + 1 , V_57 -> V_63 , V_57 -> V_83 ) ;
}
V_82 = F_35 ( V_70 , V_68 , V_2 -> V_71 , V_72 ) ;
if ( V_82 == 0 ) {
F_36 ( V_70 , L_3 ) ;
return;
}
V_77 = F_37 ( V_79 , V_68 , V_2 -> V_71 ,
V_84 , V_85 ) ;
if ( ! V_77 ) {
F_28 ( V_70 , V_68 , V_2 -> V_71 ,
V_72 ) ;
F_36 ( V_70 , L_4 ) ;
return;
}
V_77 -> V_86 = F_27 ;
V_77 -> V_87 = V_2 ;
F_29 ( V_70 , L_5 ,
F_25 ( V_57 ) ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_61 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_41 = 1 ;
F_38 ( V_77 ) ;
F_39 ( V_79 ) ;
return;
}
static void F_40 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
if ( V_9 -> V_43 . V_34 & V_44 ) {
V_39 = F_6 ( V_9 -> V_13 + V_16 ) ;
if ( V_9 -> V_43 . V_34 & V_88 )
V_39 &= ~ V_48 ;
else
V_39 |= V_48 ;
F_8 ( V_39 , V_9 -> V_13 + V_16 ) ;
V_39 = F_6 ( V_9 -> V_13 + V_49 ) ;
V_39 |= V_50 ;
F_8 ( V_39 , V_9 -> V_13 + V_49 ) ;
}
if ( ! V_2 -> V_40 ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_39 | V_42 , V_2 -> V_9 . V_13 + V_14 ) ;
}
if ( V_2 -> V_40 ) {
if ( V_2 -> V_9 . V_58 ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_61 ;
V_39 |= V_42 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
return;
}
if ( ! F_22 ( & V_9 -> V_31 -> V_57 ) &&
! F_23 ( V_9 ) )
F_24 ( V_2 ) ;
return;
}
}
static T_1 F_41 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
unsigned int V_91 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_8 ( V_92 , V_2 -> V_9 . V_13 + V_93 ) ;
V_91 = F_6 ( V_2 -> V_9 . V_13 + V_93 ) & V_94 ;
F_11 ( & V_2 -> V_9 , ! ! V_91 ) ;
F_12 ( & V_2 -> V_9 . V_31 -> V_9 . V_32 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return V_95 ;
}
static T_1 F_42 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_21 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return V_95 ;
}
static T_1 F_43 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
unsigned int V_96 , V_97 , V_98 = 0 ;
struct V_99 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
unsigned long V_34 , V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
while ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_100 ) {
V_97 = V_101 ;
V_2 -> V_9 . V_25 . V_96 ++ ;
V_96 = F_6 ( V_2 -> V_9 . V_13 + V_102 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_45 ) ;
if ( V_39 & V_103 ) {
F_8 ( V_103 , V_2 -> V_9 . V_13 + V_45 ) ;
if ( F_44 ( & V_2 -> V_9 ) )
continue;
}
if ( F_45 ( & V_2 -> V_9 , ( unsigned char ) V_96 ) )
continue;
if ( F_46 ( V_96 & V_104 ) ) {
if ( V_96 & V_105 )
V_2 -> V_9 . V_25 . V_106 ++ ;
else if ( V_96 & V_107 )
V_2 -> V_9 . V_25 . V_108 ++ ;
else if ( V_96 & V_109 )
V_2 -> V_9 . V_25 . V_110 ++ ;
if ( V_96 & V_111 )
V_2 -> V_9 . V_25 . V_112 ++ ;
if ( V_96 & V_2 -> V_9 . V_113 ) {
if ( ++ V_98 > 100 )
goto V_114;
continue;
}
V_96 &= ( V_2 -> V_9 . V_115 | 0xFF ) ;
if ( V_96 & V_105 )
V_97 = V_116 ;
else if ( V_96 & V_107 )
V_97 = V_117 ;
else if ( V_96 & V_109 )
V_97 = V_118 ;
if ( V_96 & V_111 )
V_97 = V_119 ;
#ifdef F_47
V_2 -> V_9 . V_120 = 0 ;
#endif
}
if ( V_2 -> V_9 . V_113 & V_121 )
goto V_114;
F_48 ( V_9 , V_96 , V_97 ) ;
}
V_114:
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_49 ( V_9 ) ;
return V_95 ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_45 ) ;
if ( ( V_39 & V_100 ) && ! V_2 -> V_51 ) {
V_2 -> V_51 = 1 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_55 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_51 ( V_2 ) ;
}
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static T_1 F_52 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
unsigned int V_122 ;
unsigned int V_123 ;
V_122 = F_6 ( V_2 -> V_9 . V_13 + V_93 ) ;
V_123 = F_6 ( V_2 -> V_9 . V_13 + V_45 ) ;
if ( V_122 & V_124 ) {
if ( V_2 -> V_40 )
F_50 ( V_2 ) ;
else
F_43 ( V_89 , V_90 ) ;
}
if ( ( V_122 & V_125 &&
F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_42 ) ||
( V_123 & V_46 &&
F_6 ( V_2 -> V_9 . V_13 + V_49 ) & V_50 ) )
F_42 ( V_89 , V_90 ) ;
if ( V_122 & V_92 )
F_41 ( V_89 , V_90 ) ;
if ( V_122 & V_126 )
F_8 ( V_126 , V_2 -> V_9 . V_13 + V_93 ) ;
if ( V_123 & V_127 ) {
F_36 ( V_2 -> V_9 . V_70 , L_6 ) ;
V_2 -> V_9 . V_25 . V_112 ++ ;
F_8 ( V_127 , V_2 -> V_9 . V_13 + V_45 ) ;
}
return V_95 ;
}
static unsigned int F_53 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_82 ;
V_82 = ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_46 ) ? V_128 : 0 ;
if ( V_2 -> V_40 && V_2 -> V_41 )
V_82 = 0 ;
return V_82 ;
}
static unsigned int F_54 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_129 = V_27 | V_29 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_93 ) & V_94 )
V_129 |= V_30 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_48 )
V_129 |= V_130 ;
if ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_131 )
V_129 |= V_132 ;
return V_129 ;
}
static void F_55 ( struct V_8 * V_9 , unsigned int V_133 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
if ( ! ( V_9 -> V_43 . V_34 & V_44 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_48 | V_134 ) ;
if ( V_133 & V_130 )
V_39 |= V_48 | V_134 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
}
V_39 = F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & ~ V_131 ;
if ( V_133 & V_132 )
V_39 |= V_131 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) ;
}
static void F_56 ( struct V_8 * V_9 , int V_135 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 , V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) & ~ V_136 ;
if ( V_135 != 0 )
V_39 |= V_136 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_137 )
{
unsigned int V_91 ;
V_91 = F_6 ( V_2 -> V_9 . V_13 + V_138 ) & ( V_139 | V_140 ) ;
V_91 |= V_141 << V_142 | V_143 ;
F_8 ( V_91 , V_2 -> V_9 . V_13 + V_138 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_55 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_51 = 0 ;
if ( F_30 ( & V_2 -> V_74 ) )
F_31 ( & V_2 -> V_74 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static void F_59 ( void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_78 * V_79 = V_2 -> V_53 ;
struct V_67 * V_68 = & V_2 -> V_144 ;
struct V_99 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
struct V_145 V_31 ;
enum V_146 V_19 ;
unsigned int V_147 ;
F_28 ( V_2 -> V_9 . V_70 , V_68 , 1 , V_148 ) ;
V_19 = F_60 ( V_79 , ( V_149 ) 0 , & V_31 ) ;
V_147 = V_150 - V_31 . V_151 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_152 ) {
V_147 -- ;
F_8 ( V_152 , V_2 -> V_9 . V_13 + V_45 ) ;
}
F_29 ( V_2 -> V_9 . V_70 , L_7 , V_147 ) ;
if ( V_147 ) {
if ( ! ( V_2 -> V_9 . V_113 & V_121 ) )
F_61 ( V_9 , V_2 -> V_153 , V_147 ) ;
F_49 ( V_9 ) ;
F_51 ( V_2 ) ;
} else if ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_100 ) {
F_51 ( V_2 ) ;
} else {
F_58 ( V_2 ) ;
}
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = & V_2 -> V_144 ;
struct V_78 * V_79 = V_2 -> V_53 ;
struct V_81 * V_70 = V_2 -> V_9 . V_70 ;
struct V_76 * V_77 ;
int V_82 ;
F_32 ( V_68 , V_2 -> V_153 , V_150 ) ;
V_82 = F_35 ( V_70 , V_68 , 1 , V_148 ) ;
if ( V_82 == 0 ) {
F_36 ( V_70 , L_8 ) ;
return - V_154 ;
}
V_77 = F_37 ( V_79 , V_68 , 1 , V_155 ,
V_85 ) ;
if ( ! V_77 ) {
F_28 ( V_70 , V_68 , 1 , V_148 ) ;
F_36 ( V_70 , L_9 ) ;
return - V_154 ;
}
V_77 -> V_86 = F_59 ;
V_77 -> V_87 = V_2 ;
F_29 ( V_70 , L_10 ) ;
F_38 ( V_77 ) ;
F_39 ( V_79 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 ) {
F_63 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
F_64 ( V_2 -> V_153 ) ;
V_2 -> V_153 = NULL ;
}
if ( V_2 -> V_80 ) {
F_63 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
V_2 -> V_156 = 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_157 V_158 = {} ;
struct V_81 * V_70 = V_2 -> V_9 . V_70 ;
int V_82 ;
V_2 -> V_53 = F_66 ( V_70 , L_11 ) ;
if ( ! V_2 -> V_53 ) {
F_29 ( V_70 , L_12 ) ;
V_82 = - V_154 ;
goto V_159;
}
V_158 . V_160 = V_155 ;
V_158 . V_161 = V_2 -> V_9 . V_162 + V_102 ;
V_158 . V_163 = V_164 ;
V_158 . V_165 = V_143 ;
V_82 = F_67 ( V_2 -> V_53 , & V_158 ) ;
if ( V_82 ) {
F_36 ( V_70 , L_13 ) ;
goto V_159;
}
V_2 -> V_153 = F_68 ( V_166 , V_167 ) ;
if ( ! V_2 -> V_153 ) {
V_82 = - V_168 ;
goto V_159;
}
V_2 -> V_80 = F_66 ( V_70 , L_14 ) ;
if ( ! V_2 -> V_80 ) {
F_36 ( V_70 , L_15 ) ;
V_82 = - V_154 ;
goto V_159;
}
V_158 . V_160 = V_84 ;
V_158 . V_169 = V_2 -> V_9 . V_162 + V_59 ;
V_158 . V_170 = V_164 ;
V_158 . V_171 = V_141 ;
V_82 = F_67 ( V_2 -> V_80 , & V_158 ) ;
if ( V_82 ) {
F_36 ( V_70 , L_16 ) ;
goto V_159;
}
V_2 -> V_156 = 1 ;
return 0 ;
V_159:
F_62 ( V_2 ) ;
return V_82 ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
F_70 ( & V_2 -> V_74 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_172 | V_61 | V_173 |
F_71 ( 3 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_49 ) ;
V_39 |= V_174 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_49 ) ;
V_2 -> V_40 = 1 ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_172 | V_61 | V_173 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_134 | V_48 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_49 ) ;
V_39 &= ~ V_174 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_49 ) ;
V_2 -> V_40 = 0 ;
}
static int F_73 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_175 , V_176 ;
unsigned long V_34 , V_39 ;
V_175 = F_74 ( V_2 -> V_177 ) ;
if ( V_175 )
return V_175 ;
V_175 = F_74 ( V_2 -> V_178 ) ;
if ( V_175 ) {
F_75 ( V_2 -> V_177 ) ;
return V_175 ;
}
F_57 ( V_2 , 0 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_49 ) ;
V_39 &= ~ ( V_179 << V_180 ) ;
V_39 |= V_181 << V_180 ;
F_8 ( V_39 & ~ V_182 , V_2 -> V_9 . V_13 + V_49 ) ;
V_176 = 100 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_183 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_183 ) && ( -- V_176 > 0 ) )
F_76 ( 1 ) ;
if ( F_4 ( V_2 ) && ! F_77 ( V_9 ) &&
! V_2 -> V_156 )
F_65 ( V_2 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_8 ( V_92 , V_2 -> V_9 . V_13 + V_93 ) ;
F_8 ( V_127 , V_2 -> V_9 . V_13 + V_45 ) ;
if ( V_2 -> V_156 && ! V_2 -> V_40 )
F_69 ( V_2 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_55 | V_184 | V_185 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_49 ) ;
V_39 |= V_186 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_49 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= ( V_54 | V_187 ) ;
if ( ! V_2 -> V_188 )
V_39 |= V_189 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( ! F_2 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_39 |= V_190 | V_191 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_18 ) ;
}
F_20 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return 0 ;
}
static void F_78 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
unsigned long V_34 ;
if ( V_2 -> V_40 ) {
int V_82 ;
V_82 = F_79 ( V_2 -> V_74 ,
! V_2 -> V_51 && ! V_2 -> V_41 ) ;
if ( V_82 != 0 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_41 = 0 ;
F_19 ( V_2 -> V_80 ) ;
F_19 ( V_2 -> V_53 ) ;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_17 ( V_9 ) ;
F_18 ( V_9 ) ;
F_72 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_62 ( V_2 ) ;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_187 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_80 ( & V_2 -> V_36 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_42 | V_55 | V_184 | V_185 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_75 ( V_2 -> V_177 ) ;
F_75 ( V_2 -> V_178 ) ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
struct V_67 * V_68 = & V_2 -> V_69 [ 0 ] ;
unsigned long V_39 ;
int V_176 = 100 , V_192 , V_193 , V_194 ;
if ( ! V_2 -> V_80 )
return;
V_2 -> V_73 = 0 ;
F_19 ( V_2 -> V_80 ) ;
if ( V_2 -> V_41 ) {
F_28 ( V_2 -> V_9 . V_70 , V_68 , V_2 -> V_71 ,
V_72 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_61 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_41 = false ;
}
V_192 = F_6 ( V_2 -> V_9 . V_13 + V_195 ) ;
V_193 = F_6 ( V_2 -> V_9 . V_13 + V_196 ) ;
V_194 = F_6 ( V_2 -> V_9 . V_13 + V_197 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_183 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_183 ) && ( -- V_176 > 0 ) )
F_76 ( 1 ) ;
F_8 ( V_192 , V_2 -> V_9 . V_13 + V_195 ) ;
F_8 ( V_193 , V_2 -> V_9 . V_13 + V_196 ) ;
F_8 ( V_194 , V_2 -> V_9 . V_13 + V_197 ) ;
}
static void
F_82 ( struct V_8 * V_9 , struct V_198 * V_199 ,
struct V_198 * V_200 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 ;
unsigned int V_15 , V_201 , V_202 , V_203 , V_204 ;
unsigned int V_205 = V_200 ? V_200 -> V_206 & V_207 : V_208 ;
unsigned int div , V_209 ;
unsigned long V_210 , V_211 ;
T_2 V_212 ;
while ( ( V_199 -> V_206 & V_207 ) != V_213 &&
( V_199 -> V_206 & V_207 ) != V_208 ) {
V_199 -> V_206 &= ~ V_207 ;
V_199 -> V_206 |= V_205 ;
V_205 = V_208 ;
}
if ( ( V_199 -> V_206 & V_207 ) == V_208 )
V_15 = V_214 | V_183 | V_189 ;
else
V_15 = V_183 | V_189 ;
if ( V_199 -> V_206 & V_215 ) {
if ( V_2 -> V_188 ) {
V_15 &= ~ V_189 ;
if ( V_9 -> V_43 . V_34 & V_44 ) {
if ( ! ( V_9 -> V_43 . V_34 &
V_47 ) )
V_15 |= V_48 ;
} else {
V_15 |= V_134 ;
}
} else {
V_199 -> V_206 &= ~ V_215 ;
}
} else if ( V_9 -> V_43 . V_34 & V_44 )
if ( ! ( V_9 -> V_43 . V_34 & V_47 ) )
V_15 |= V_48 ;
if ( V_199 -> V_206 & V_216 )
V_15 |= V_217 ;
if ( V_199 -> V_206 & V_218 ) {
V_15 |= V_219 ;
if ( V_199 -> V_206 & V_220 )
V_15 |= V_221 ;
}
F_80 ( & V_2 -> V_36 ) ;
V_203 = F_83 ( V_9 , V_199 , V_200 , 50 , V_9 -> V_222 / 16 ) ;
V_204 = F_84 ( V_9 , V_203 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_2 -> V_9 . V_115 = 0 ;
if ( V_199 -> V_223 & V_224 )
V_2 -> V_9 . V_115 |= ( V_109 | V_107 ) ;
if ( V_199 -> V_223 & ( V_225 | V_226 ) )
V_2 -> V_9 . V_115 |= V_105 ;
V_2 -> V_9 . V_113 = 0 ;
if ( V_199 -> V_223 & V_227 )
V_2 -> V_9 . V_113 |= V_107 | V_109 ;
if ( V_199 -> V_223 & V_228 ) {
V_2 -> V_9 . V_113 |= V_105 ;
if ( V_199 -> V_223 & V_227 )
V_2 -> V_9 . V_113 |= V_111 ;
}
if ( ( V_199 -> V_206 & V_229 ) == 0 )
V_2 -> V_9 . V_113 |= V_121 ;
F_85 ( V_9 , V_199 -> V_206 , V_203 ) ;
V_201 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_201 & ~ ( V_42 | V_55 | V_184 ) ,
V_2 -> V_9 . V_13 + V_14 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_46 ) )
F_86 () ;
V_202 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_202 & ~ ( V_187 | V_54 ) ,
V_2 -> V_9 . V_13 + V_16 ) ;
V_202 &= ( V_187 | V_54 ) ;
div = V_2 -> V_9 . V_222 / ( V_203 * 16 ) ;
if ( V_203 == 38400 && V_204 != div )
V_203 = V_2 -> V_9 . V_222 / ( V_204 * 16 ) ;
div = V_2 -> V_9 . V_222 / ( V_203 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
F_87 ( 16 * div * V_203 , V_2 -> V_9 . V_222 ,
1 << 16 , 1 << 16 , & V_210 , & V_211 ) ;
V_212 = V_2 -> V_9 . V_222 ;
V_212 *= V_210 ;
F_88 ( V_212 , V_211 * 16 * div ) ;
F_89 ( V_199 ,
( V_230 ) V_212 , ( V_230 ) V_212 ) ;
V_210 -= 1 ;
V_211 -= 1 ;
V_209 = F_6 ( V_2 -> V_9 . V_13 + V_138 ) ;
V_209 = ( V_209 & ( ~ V_139 ) ) | F_90 ( div ) ;
if ( V_2 -> V_231 )
V_209 |= V_140 ;
F_8 ( V_209 , V_2 -> V_9 . V_13 + V_138 ) ;
F_8 ( V_210 , V_2 -> V_9 . V_13 + V_195 ) ;
F_8 ( V_211 , V_2 -> V_9 . V_13 + V_196 ) ;
if ( ! F_2 ( V_2 ) )
F_8 ( V_2 -> V_9 . V_222 / div / 1000 ,
V_2 -> V_9 . V_13 + V_232 ) ;
F_8 ( V_201 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_15 | V_202 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( F_91 ( & V_2 -> V_9 , V_199 -> V_206 ) )
F_20 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static const char * F_92 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_233 ? L_17 : NULL ;
}
static void F_93 ( struct V_8 * V_9 , int V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_34 & V_234 )
V_2 -> V_9 . type = V_233 ;
}
static int
F_94 ( struct V_8 * V_9 , struct V_235 * V_236 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_82 = 0 ;
if ( V_236 -> type != V_237 && V_236 -> type != V_233 )
V_82 = - V_154 ;
if ( V_2 -> V_9 . V_89 != V_236 -> V_89 )
V_82 = - V_154 ;
if ( V_236 -> V_238 != V_239 )
V_82 = - V_154 ;
if ( V_2 -> V_9 . V_222 / 16 != V_236 -> V_240 )
V_82 = - V_154 ;
if ( V_2 -> V_9 . V_162 != ( unsigned long ) V_236 -> V_241 )
V_82 = - V_154 ;
if ( V_2 -> V_9 . V_242 != V_236 -> V_9 )
V_82 = - V_154 ;
if ( V_236 -> V_243 != 0 )
V_82 = - V_154 ;
return V_82 ;
}
static int F_95 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 ;
unsigned long V_39 ;
int V_175 ;
V_175 = F_74 ( V_2 -> V_178 ) ;
if ( V_175 )
return V_175 ;
V_175 = F_74 ( V_2 -> V_177 ) ;
if ( V_175 )
F_75 ( V_2 -> V_178 ) ;
F_57 ( V_2 , 0 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( F_2 ( V_2 ) )
V_39 |= V_244 ;
V_39 |= V_185 | V_55 ;
V_39 &= ~ ( V_42 | V_184 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= V_54 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return 0 ;
}
static int F_96 ( struct V_8 * V_9 )
{
if ( ! ( F_97 ( V_9 -> V_13 + V_45 ) & V_100 ) )
return V_245 ;
return F_97 ( V_9 -> V_13 + V_102 ) & V_246 ;
}
static void F_98 ( struct V_8 * V_9 , unsigned char V_247 )
{
unsigned int V_19 ;
do {
V_19 = F_97 ( V_9 -> V_13 + V_93 ) ;
} while ( ~ V_19 & V_125 );
F_99 ( V_247 , V_9 -> V_13 + V_59 ) ;
do {
V_19 = F_97 ( V_9 -> V_13 + V_45 ) ;
} while ( ~ V_19 & V_46 );
}
static int F_100 ( struct V_8 * V_9 ,
struct V_248 * V_249 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
V_249 -> V_250 = 0 ;
V_249 -> V_251 = 0 ;
V_249 -> V_34 |= V_252 ;
if ( ! V_2 -> V_188 )
V_249 -> V_34 &= ~ V_44 ;
if ( V_249 -> V_34 & V_44 ) {
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_134 ;
if ( V_249 -> V_34 & V_47 )
V_39 &= ~ V_48 ;
else
V_39 |= V_48 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
}
V_9 -> V_43 = * V_249 ;
return 0 ;
}
static void F_101 ( struct V_8 * V_9 , int V_253 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_62 )
F_86 () ;
F_8 ( V_253 , V_2 -> V_9 . V_13 + V_59 ) ;
}
static void
F_102 ( struct V_254 * V_255 , const char * V_256 , unsigned int V_147 )
{
struct V_1 * V_2 = V_257 [ V_255 -> V_258 ] ;
struct V_10 V_259 ;
unsigned int V_12 ;
unsigned long V_34 = 0 ;
int V_260 = 1 ;
int V_175 ;
V_175 = F_103 ( V_2 -> V_177 ) ;
if ( V_175 )
return;
V_175 = F_103 ( V_2 -> V_178 ) ;
if ( V_175 ) {
F_104 ( V_2 -> V_177 ) ;
return;
}
if ( V_2 -> V_9 . V_120 )
V_260 = 0 ;
else if ( V_261 )
V_260 = F_105 ( & V_2 -> V_9 . V_35 , V_34 ) ;
else
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_5 ( & V_2 -> V_9 , & V_259 ) ;
V_12 = V_259 . V_12 ;
if ( F_2 ( V_2 ) )
V_12 |= V_244 ;
V_12 |= V_185 ;
V_12 &= ~ ( V_42 | V_55 | V_184 ) ;
F_8 ( V_12 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_259 . V_15 | V_187 , V_2 -> V_9 . V_13 + V_16 ) ;
F_106 ( & V_2 -> V_9 , V_256 , V_147 , F_101 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_46 ) ) ;
F_7 ( & V_2 -> V_9 , & V_259 ) ;
if ( V_260 )
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_104 ( V_2 -> V_178 ) ;
F_104 ( V_2 -> V_177 ) ;
}
static void T_3
F_107 ( struct V_1 * V_2 , int * V_203 ,
int * V_108 , int * V_262 )
{
if ( F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_185 ) {
unsigned int V_15 , V_192 , V_193 , V_222 ;
unsigned int V_263 ;
unsigned int V_264 ;
V_15 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
* V_108 = 'n' ;
if ( V_15 & V_219 ) {
if ( V_15 & V_221 )
* V_108 = 'o' ;
else
* V_108 = 'e' ;
}
if ( V_15 & V_214 )
* V_262 = 8 ;
else
* V_262 = 7 ;
V_192 = F_6 ( V_2 -> V_9 . V_13 + V_195 ) & 0xffff ;
V_193 = F_6 ( V_2 -> V_9 . V_13 + V_196 ) & 0xffff ;
V_264 = ( F_6 ( V_2 -> V_9 . V_13 + V_138 ) & V_139 ) >> 7 ;
if ( V_264 == 6 )
V_264 = 7 ;
else
V_264 = 6 - V_264 ;
V_222 = F_108 ( V_2 -> V_177 ) ;
V_222 /= V_264 ;
{
unsigned int V_265 = V_192 + 1 ;
unsigned int div = 16 * ( V_193 + 1 ) ;
unsigned int V_266 = V_222 % div ;
V_263 = ( V_222 / div ) * V_265 ;
V_263 += ( V_266 * V_265 + div / 2 ) / div ;
* V_203 = ( V_263 + 50 ) / 100 * 100 ;
}
if ( * V_203 != V_263 )
F_109 ( L_18 ,
V_263 , * V_203 ) ;
}
}
static int T_3
F_110 ( struct V_254 * V_255 , char * V_267 )
{
struct V_1 * V_2 ;
int V_203 = 9600 ;
int V_262 = 8 ;
int V_108 = 'n' ;
int V_268 = 'n' ;
int V_175 ;
if ( V_255 -> V_258 == - 1 || V_255 -> V_258 >= F_111 ( V_257 ) )
V_255 -> V_258 = 0 ;
V_2 = V_257 [ V_255 -> V_258 ] ;
if ( V_2 == NULL )
return - V_269 ;
V_175 = F_74 ( V_2 -> V_178 ) ;
if ( V_175 )
goto V_270;
if ( V_267 )
F_112 ( V_267 , & V_203 , & V_108 , & V_262 , & V_268 ) ;
else
F_107 ( V_2 , & V_203 , & V_108 , & V_262 ) ;
F_57 ( V_2 , 0 ) ;
V_175 = F_113 ( & V_2 -> V_9 , V_255 , V_203 , V_108 , V_262 , V_268 ) ;
F_104 ( V_2 -> V_178 ) ;
if ( V_175 ) {
F_114 ( V_2 -> V_178 ) ;
goto V_270;
}
V_175 = F_115 ( V_2 -> V_177 ) ;
if ( V_175 )
F_75 ( V_2 -> V_178 ) ;
V_270:
return V_175 ;
}
static int F_116 ( struct V_271 * V_70 , T_4 V_31 )
{
struct V_1 * V_2 = F_117 ( V_70 ) ;
unsigned int V_91 ;
V_91 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_91 |= V_272 ;
F_8 ( V_91 , V_2 -> V_9 . V_13 + V_18 ) ;
F_118 ( & V_273 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_119 ( struct V_271 * V_70 )
{
struct V_1 * V_2 = F_117 ( V_70 ) ;
unsigned int V_91 ;
V_91 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_91 &= ~ V_272 ;
F_8 ( V_91 , V_2 -> V_9 . V_13 + V_18 ) ;
F_120 ( & V_273 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_271 * V_274 )
{
struct V_275 * V_276 = V_274 -> V_70 . V_277 ;
const struct V_278 * V_279 =
F_122 ( V_280 , & V_274 -> V_70 ) ;
int V_82 ;
if ( ! V_276 )
return 1 ;
V_82 = F_123 ( V_276 , L_19 ) ;
if ( V_82 < 0 ) {
F_36 ( & V_274 -> V_70 , L_20 , V_82 ) ;
return V_82 ;
}
V_2 -> V_9 . line = V_82 ;
if ( F_124 ( V_276 , L_21 , NULL ) )
V_2 -> V_188 = 1 ;
if ( F_124 ( V_276 , L_22 , NULL ) )
V_2 -> V_231 = 1 ;
V_2 -> V_3 = V_279 -> V_33 ;
return 0 ;
}
static inline int F_121 ( struct V_1 * V_2 ,
struct V_271 * V_274 )
{
return 1 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_271 * V_274 )
{
struct V_281 * V_282 = F_126 ( & V_274 -> V_70 ) ;
V_2 -> V_9 . line = V_274 -> V_283 ;
V_2 -> V_3 = (struct V_284 * ) V_274 -> V_285 -> V_286 ;
if ( ! V_282 )
return;
if ( V_282 -> V_34 & V_287 )
V_2 -> V_188 = 1 ;
}
static int F_127 ( struct V_271 * V_274 )
{
struct V_1 * V_2 ;
void T_5 * V_288 ;
int V_82 = 0 ;
struct V_289 * V_290 ;
int V_291 , V_292 , V_293 ;
V_2 = F_128 ( & V_274 -> V_70 , sizeof( * V_2 ) , V_167 ) ;
if ( ! V_2 )
return - V_168 ;
V_82 = F_121 ( V_2 , V_274 ) ;
if ( V_82 > 0 )
F_125 ( V_2 , V_274 ) ;
else if ( V_82 < 0 )
return V_82 ;
V_290 = F_129 ( V_274 , V_294 , 0 ) ;
V_288 = F_130 ( & V_274 -> V_70 , V_290 ) ;
if ( F_131 ( V_288 ) )
return F_132 ( V_288 ) ;
V_292 = F_133 ( V_274 , 0 ) ;
V_291 = F_133 ( V_274 , 1 ) ;
V_293 = F_133 ( V_274 , 2 ) ;
V_2 -> V_9 . V_70 = & V_274 -> V_70 ;
V_2 -> V_9 . V_162 = V_290 -> V_295 ;
V_2 -> V_9 . V_13 = V_288 ;
V_2 -> V_9 . type = V_233 ,
V_2 -> V_9 . V_296 = V_239 ;
V_2 -> V_9 . V_89 = V_292 ;
V_2 -> V_9 . V_297 = 32 ;
V_2 -> V_9 . V_21 = & V_298 ;
V_2 -> V_9 . V_299 = F_100 ;
V_2 -> V_9 . V_43 . V_34 =
V_88 | V_252 ;
V_2 -> V_9 . V_34 = V_300 ;
F_134 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_301 = F_13 ;
V_2 -> V_36 . V_33 = ( unsigned long ) V_2 ;
V_2 -> V_178 = F_135 ( & V_274 -> V_70 , L_23 ) ;
if ( F_131 ( V_2 -> V_178 ) ) {
V_82 = F_132 ( V_2 -> V_178 ) ;
F_36 ( & V_274 -> V_70 , L_24 , V_82 ) ;
return V_82 ;
}
V_2 -> V_177 = F_135 ( & V_274 -> V_70 , L_25 ) ;
if ( F_131 ( V_2 -> V_177 ) ) {
V_82 = F_132 ( V_2 -> V_177 ) ;
F_36 ( & V_274 -> V_70 , L_26 , V_82 ) ;
return V_82 ;
}
V_2 -> V_9 . V_222 = F_108 ( V_2 -> V_177 ) ;
if ( V_291 > 0 ) {
V_82 = F_136 ( & V_274 -> V_70 , V_292 , F_43 , 0 ,
F_137 ( & V_274 -> V_70 ) , V_2 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_136 ( & V_274 -> V_70 , V_291 , F_42 , 0 ,
F_137 ( & V_274 -> V_70 ) , V_2 ) ;
if ( V_82 )
return V_82 ;
} else {
V_82 = F_136 ( & V_274 -> V_70 , V_292 , F_52 , 0 ,
F_137 ( & V_274 -> V_70 ) , V_2 ) ;
if ( V_82 )
return V_82 ;
}
V_257 [ V_2 -> V_9 . line ] = V_2 ;
F_138 ( V_274 , V_2 ) ;
return F_139 ( & V_273 , & V_2 -> V_9 ) ;
}
static int F_140 ( struct V_271 * V_274 )
{
struct V_1 * V_2 = F_117 ( V_274 ) ;
return F_141 ( & V_273 , & V_2 -> V_9 ) ;
}
static int T_3 F_142 ( void )
{
int V_82 = F_143 ( & V_273 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_144 ( & V_302 ) ;
if ( V_82 != 0 )
F_145 ( & V_273 ) ;
return V_82 ;
}
static void T_6 F_146 ( void )
{
F_147 ( & V_302 ) ;
F_145 ( & V_273 ) ;
}
