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
if ( F_48 ( V_9 , V_96 , V_97 ) == 0 )
V_2 -> V_9 . V_25 . V_122 ++ ;
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
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_123 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_51 ( V_2 ) ;
}
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static T_1 F_52 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
unsigned int V_124 ;
unsigned int V_125 ;
V_124 = F_6 ( V_2 -> V_9 . V_13 + V_93 ) ;
V_125 = F_6 ( V_2 -> V_9 . V_13 + V_45 ) ;
if ( V_124 & ( V_126 | V_127 ) ) {
if ( V_2 -> V_40 )
F_50 ( V_2 ) ;
else
F_43 ( V_89 , V_90 ) ;
}
if ( ( V_124 & V_128 &&
F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_42 ) ||
( V_125 & V_46 &&
F_6 ( V_2 -> V_9 . V_13 + V_49 ) & V_50 ) )
F_42 ( V_89 , V_90 ) ;
if ( V_124 & V_92 )
F_41 ( V_89 , V_90 ) ;
if ( V_124 & V_129 )
F_8 ( V_129 , V_2 -> V_9 . V_13 + V_93 ) ;
if ( V_125 & V_130 ) {
V_2 -> V_9 . V_25 . V_112 ++ ;
F_8 ( V_130 , V_2 -> V_9 . V_13 + V_45 ) ;
}
return V_95 ;
}
static unsigned int F_53 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_82 ;
V_82 = ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_46 ) ? V_131 : 0 ;
if ( V_2 -> V_40 && V_2 -> V_41 )
V_82 = 0 ;
return V_82 ;
}
static unsigned int F_54 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_132 = V_27 | V_29 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_93 ) & V_94 )
V_132 |= V_30 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_48 )
V_132 |= V_133 ;
if ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_134 )
V_132 |= V_135 ;
return V_132 ;
}
static void F_55 ( struct V_8 * V_9 , unsigned int V_136 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
if ( ! ( V_9 -> V_43 . V_34 & V_44 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_48 | V_137 ) ;
if ( V_136 & V_133 )
V_39 |= V_48 | V_137 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
}
V_39 = F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & ~ V_134 ;
if ( V_136 & V_135 )
V_39 |= V_134 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) ;
}
static void F_56 ( struct V_8 * V_9 , int V_138 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 , V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) & ~ V_139 ;
if ( V_138 != 0 )
V_39 |= V_139 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_55 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= V_123 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
V_2 -> V_51 = 0 ;
if ( F_30 ( & V_2 -> V_74 ) )
F_31 ( & V_2 -> V_74 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static void F_58 ( void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_78 * V_79 = V_2 -> V_53 ;
struct V_67 * V_68 = & V_2 -> V_140 ;
struct V_99 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
struct V_141 V_31 ;
enum V_142 V_19 ;
unsigned int V_143 ;
F_28 ( V_2 -> V_9 . V_70 , V_68 , 1 , V_144 ) ;
V_19 = F_59 ( V_79 , ( V_145 ) 0 , & V_31 ) ;
V_143 = V_146 - V_31 . V_147 ;
F_29 ( V_2 -> V_9 . V_70 , L_6 , V_143 ) ;
if ( V_143 ) {
if ( ! ( V_2 -> V_9 . V_113 & V_121 ) ) {
int V_148 = F_60 ( V_9 , V_2 -> V_149 ,
V_143 ) ;
if ( V_148 != V_143 )
V_2 -> V_9 . V_25 . V_122 ++ ;
}
F_49 ( V_9 ) ;
V_2 -> V_9 . V_25 . V_96 += V_143 ;
}
if ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_100 )
F_51 ( V_2 ) ;
else
F_57 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = & V_2 -> V_140 ;
struct V_78 * V_79 = V_2 -> V_53 ;
struct V_81 * V_70 = V_2 -> V_9 . V_70 ;
struct V_76 * V_77 ;
int V_82 ;
F_32 ( V_68 , V_2 -> V_149 , V_146 ) ;
V_82 = F_35 ( V_70 , V_68 , 1 , V_144 ) ;
if ( V_82 == 0 ) {
F_36 ( V_70 , L_7 ) ;
return - V_150 ;
}
V_77 = F_37 ( V_79 , V_68 , 1 , V_151 ,
V_85 ) ;
if ( ! V_77 ) {
F_28 ( V_70 , V_68 , 1 , V_144 ) ;
F_36 ( V_70 , L_8 ) ;
return - V_150 ;
}
V_77 -> V_86 = F_58 ;
V_77 -> V_87 = V_2 ;
F_29 ( V_70 , L_9 ) ;
F_38 ( V_77 ) ;
F_39 ( V_79 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 ,
unsigned char V_152 , unsigned char V_153 )
{
unsigned int V_91 ;
V_91 = F_6 ( V_2 -> V_9 . V_13 + V_154 ) & ( V_155 | V_156 ) ;
V_91 |= V_152 << V_157 | V_153 ;
F_8 ( V_91 , V_2 -> V_9 . V_13 + V_154 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 ) {
F_63 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
F_64 ( V_2 -> V_149 ) ;
V_2 -> V_149 = NULL ;
}
if ( V_2 -> V_80 ) {
F_63 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
V_2 -> V_158 = 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_159 V_160 = {} ;
struct V_81 * V_70 = V_2 -> V_9 . V_70 ;
int V_82 ;
V_2 -> V_53 = F_66 ( V_70 , L_10 ) ;
if ( ! V_2 -> V_53 ) {
F_29 ( V_70 , L_11 ) ;
V_82 = - V_150 ;
goto V_161;
}
V_160 . V_162 = V_151 ;
V_160 . V_163 = V_2 -> V_9 . V_164 + V_102 ;
V_160 . V_165 = V_166 ;
V_160 . V_167 = V_168 - 1 ;
V_82 = F_67 ( V_2 -> V_53 , & V_160 ) ;
if ( V_82 ) {
F_36 ( V_70 , L_12 ) ;
goto V_161;
}
V_2 -> V_149 = F_68 ( V_169 , V_170 ) ;
if ( ! V_2 -> V_149 ) {
V_82 = - V_171 ;
goto V_161;
}
V_2 -> V_80 = F_66 ( V_70 , L_13 ) ;
if ( ! V_2 -> V_80 ) {
F_36 ( V_70 , L_14 ) ;
V_82 = - V_150 ;
goto V_161;
}
V_160 . V_162 = V_84 ;
V_160 . V_172 = V_2 -> V_9 . V_164 + V_59 ;
V_160 . V_173 = V_166 ;
V_160 . V_174 = V_175 ;
V_82 = F_67 ( V_2 -> V_80 , & V_160 ) ;
if ( V_82 ) {
F_36 ( V_70 , L_15 ) ;
goto V_161;
}
V_2 -> V_158 = 1 ;
return 0 ;
V_161:
F_62 ( V_2 ) ;
return V_82 ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
F_70 ( & V_2 -> V_74 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_176 | V_61 | V_177 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= V_123 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_61 ( V_2 , V_175 , V_168 ) ;
V_2 -> V_40 = 1 ;
}
static void F_71 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_176 | V_61 | V_177 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_137 | V_48 | V_123 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_61 ( V_2 , V_178 , V_179 ) ;
V_2 -> V_40 = 0 ;
}
static int F_72 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_180 , V_181 ;
unsigned long V_34 , V_39 ;
V_180 = F_73 ( V_2 -> V_182 ) ;
if ( V_180 )
return V_180 ;
V_180 = F_73 ( V_2 -> V_183 ) ;
if ( V_180 ) {
F_74 ( V_2 -> V_182 ) ;
return V_180 ;
}
F_61 ( V_2 , V_178 , V_179 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_49 ) ;
V_39 &= ~ ( V_184 << V_185 ) ;
V_39 |= V_186 << V_185 ;
F_8 ( V_39 & ~ V_187 , V_2 -> V_9 . V_13 + V_49 ) ;
if ( F_4 ( V_2 ) && ! F_75 ( V_9 ) &&
! V_2 -> V_158 )
F_65 ( V_2 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_181 = 100 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_188 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_188 ) && ( -- V_181 > 0 ) )
F_76 ( 1 ) ;
F_8 ( V_92 , V_2 -> V_9 . V_13 + V_93 ) ;
F_8 ( V_130 , V_2 -> V_9 . V_13 + V_45 ) ;
if ( V_2 -> V_158 && ! V_2 -> V_40 )
F_69 ( V_2 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_55 | V_189 | V_190 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_49 ) ;
V_39 |= V_191 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_49 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= ( V_54 | V_192 ) ;
if ( ! V_2 -> V_193 )
V_39 |= V_194 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( ! F_2 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_39 |= V_195 | V_196 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_18 ) ;
}
F_20 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return 0 ;
}
static void F_77 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
unsigned long V_34 ;
if ( V_2 -> V_40 ) {
int V_82 ;
V_82 = F_78 ( V_2 -> V_74 ,
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
F_71 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_62 ( V_2 ) ;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_192 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_79 ( & V_2 -> V_36 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_42 | V_55 | V_189 | V_190 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_74 ( V_2 -> V_182 ) ;
F_74 ( V_2 -> V_183 ) ;
}
static void F_80 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
struct V_67 * V_68 = & V_2 -> V_69 [ 0 ] ;
unsigned long V_39 ;
int V_181 = 100 , V_197 , V_198 , V_199 ;
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
V_197 = F_6 ( V_2 -> V_9 . V_13 + V_200 ) ;
V_198 = F_6 ( V_2 -> V_9 . V_13 + V_201 ) ;
V_199 = F_6 ( V_2 -> V_9 . V_13 + V_202 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_188 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_188 ) && ( -- V_181 > 0 ) )
F_76 ( 1 ) ;
F_8 ( V_197 , V_2 -> V_9 . V_13 + V_200 ) ;
F_8 ( V_198 , V_2 -> V_9 . V_13 + V_201 ) ;
F_8 ( V_199 , V_2 -> V_9 . V_13 + V_202 ) ;
}
static void
F_81 ( struct V_8 * V_9 , struct V_203 * V_204 ,
struct V_203 * V_205 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 ;
unsigned int V_15 , V_206 , V_207 , V_208 , V_209 ;
unsigned int V_210 = V_205 ? V_205 -> V_211 & V_212 : V_213 ;
unsigned int div , V_214 ;
unsigned long V_215 , V_216 ;
T_2 V_217 ;
while ( ( V_204 -> V_211 & V_212 ) != V_218 &&
( V_204 -> V_211 & V_212 ) != V_213 ) {
V_204 -> V_211 &= ~ V_212 ;
V_204 -> V_211 |= V_210 ;
V_210 = V_213 ;
}
if ( ( V_204 -> V_211 & V_212 ) == V_213 )
V_15 = V_219 | V_188 | V_194 ;
else
V_15 = V_188 | V_194 ;
if ( V_204 -> V_211 & V_220 ) {
if ( V_2 -> V_193 ) {
V_15 &= ~ V_194 ;
if ( V_9 -> V_43 . V_34 & V_44 ) {
if ( ! ( V_9 -> V_43 . V_34 &
V_47 ) )
V_15 |= V_48 ;
} else {
V_15 |= V_137 ;
}
} else {
V_204 -> V_211 &= ~ V_220 ;
}
} else if ( V_9 -> V_43 . V_34 & V_44 )
if ( ! ( V_9 -> V_43 . V_34 & V_47 ) )
V_15 |= V_48 ;
if ( V_204 -> V_211 & V_221 )
V_15 |= V_222 ;
if ( V_204 -> V_211 & V_223 ) {
V_15 |= V_224 ;
if ( V_204 -> V_211 & V_225 )
V_15 |= V_226 ;
}
F_79 ( & V_2 -> V_36 ) ;
V_208 = F_82 ( V_9 , V_204 , V_205 , 50 , V_9 -> V_227 / 16 ) ;
V_209 = F_83 ( V_9 , V_208 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_2 -> V_9 . V_115 = 0 ;
if ( V_204 -> V_228 & V_229 )
V_2 -> V_9 . V_115 |= ( V_109 | V_107 ) ;
if ( V_204 -> V_228 & ( V_230 | V_231 ) )
V_2 -> V_9 . V_115 |= V_105 ;
V_2 -> V_9 . V_113 = 0 ;
if ( V_204 -> V_228 & V_232 )
V_2 -> V_9 . V_113 |= V_107 | V_109 ;
if ( V_204 -> V_228 & V_233 ) {
V_2 -> V_9 . V_113 |= V_105 ;
if ( V_204 -> V_228 & V_232 )
V_2 -> V_9 . V_113 |= V_111 ;
}
if ( ( V_204 -> V_211 & V_234 ) == 0 )
V_2 -> V_9 . V_113 |= V_121 ;
F_84 ( V_9 , V_204 -> V_211 , V_208 ) ;
V_206 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_206 & ~ ( V_42 | V_55 | V_189 ) ,
V_2 -> V_9 . V_13 + V_14 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_46 ) )
F_85 () ;
V_207 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_207 & ~ ( V_192 | V_54 ) ,
V_2 -> V_9 . V_13 + V_16 ) ;
V_207 &= ( V_192 | V_54 | V_123 ) ;
div = V_2 -> V_9 . V_227 / ( V_208 * 16 ) ;
if ( V_208 == 38400 && V_209 != div )
V_208 = V_2 -> V_9 . V_227 / ( V_209 * 16 ) ;
div = V_2 -> V_9 . V_227 / ( V_208 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
F_86 ( 16 * div * V_208 , V_2 -> V_9 . V_227 ,
1 << 16 , 1 << 16 , & V_215 , & V_216 ) ;
V_217 = V_2 -> V_9 . V_227 ;
V_217 *= V_215 ;
F_87 ( V_217 , V_216 * 16 * div ) ;
F_88 ( V_204 ,
( V_235 ) V_217 , ( V_235 ) V_217 ) ;
V_215 -= 1 ;
V_216 -= 1 ;
V_214 = F_6 ( V_2 -> V_9 . V_13 + V_154 ) ;
V_214 = ( V_214 & ( ~ V_155 ) ) | F_89 ( div ) ;
if ( V_2 -> V_236 )
V_214 |= V_156 ;
F_8 ( V_214 , V_2 -> V_9 . V_13 + V_154 ) ;
F_8 ( V_215 , V_2 -> V_9 . V_13 + V_200 ) ;
F_8 ( V_216 , V_2 -> V_9 . V_13 + V_201 ) ;
if ( ! F_2 ( V_2 ) )
F_8 ( V_2 -> V_9 . V_227 / div / 1000 ,
V_2 -> V_9 . V_13 + V_237 ) ;
F_8 ( V_206 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_15 | V_207 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( F_90 ( & V_2 -> V_9 , V_204 -> V_211 ) )
F_20 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static const char * F_91 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_238 ? L_16 : NULL ;
}
static void F_92 ( struct V_8 * V_9 , int V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_34 & V_239 )
V_2 -> V_9 . type = V_238 ;
}
static int
F_93 ( struct V_8 * V_9 , struct V_240 * V_241 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_82 = 0 ;
if ( V_241 -> type != V_242 && V_241 -> type != V_238 )
V_82 = - V_150 ;
if ( V_2 -> V_9 . V_89 != V_241 -> V_89 )
V_82 = - V_150 ;
if ( V_241 -> V_243 != V_244 )
V_82 = - V_150 ;
if ( V_2 -> V_9 . V_227 / 16 != V_241 -> V_245 )
V_82 = - V_150 ;
if ( V_2 -> V_9 . V_164 != ( unsigned long ) V_241 -> V_246 )
V_82 = - V_150 ;
if ( V_2 -> V_9 . V_247 != V_241 -> V_9 )
V_82 = - V_150 ;
if ( V_241 -> V_248 != 0 )
V_82 = - V_150 ;
return V_82 ;
}
static int F_94 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 ;
unsigned long V_39 ;
int V_180 ;
V_180 = F_73 ( V_2 -> V_183 ) ;
if ( V_180 )
return V_180 ;
V_180 = F_73 ( V_2 -> V_182 ) ;
if ( V_180 )
F_74 ( V_2 -> V_183 ) ;
F_61 ( V_2 , V_178 , V_179 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( F_2 ( V_2 ) )
V_39 |= V_249 ;
V_39 |= V_190 | V_55 ;
V_39 &= ~ ( V_42 | V_189 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= V_54 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return 0 ;
}
static int F_95 ( struct V_8 * V_9 )
{
if ( ! ( F_96 ( V_9 -> V_13 + V_45 ) & V_100 ) )
return V_250 ;
return F_96 ( V_9 -> V_13 + V_102 ) & V_251 ;
}
static void F_97 ( struct V_8 * V_9 , unsigned char V_252 )
{
unsigned int V_19 ;
do {
V_19 = F_96 ( V_9 -> V_13 + V_93 ) ;
} while ( ~ V_19 & V_128 );
F_98 ( V_252 , V_9 -> V_13 + V_59 ) ;
do {
V_19 = F_96 ( V_9 -> V_13 + V_45 ) ;
} while ( ~ V_19 & V_46 );
}
static int F_99 ( struct V_8 * V_9 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
V_254 -> V_255 = 0 ;
V_254 -> V_256 = 0 ;
V_254 -> V_34 |= V_257 ;
if ( ! V_2 -> V_193 )
V_254 -> V_34 &= ~ V_44 ;
if ( V_254 -> V_34 & V_44 ) {
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_137 ;
if ( V_254 -> V_34 & V_47 )
V_39 &= ~ V_48 ;
else
V_39 |= V_48 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
}
V_9 -> V_43 = * V_254 ;
return 0 ;
}
static void F_100 ( struct V_8 * V_9 , int V_258 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_62 )
F_85 () ;
F_8 ( V_258 , V_2 -> V_9 . V_13 + V_59 ) ;
}
static void
F_101 ( struct V_259 * V_260 , const char * V_261 , unsigned int V_143 )
{
struct V_1 * V_2 = V_262 [ V_260 -> V_263 ] ;
struct V_10 V_264 ;
unsigned int V_12 ;
unsigned long V_34 = 0 ;
int V_265 = 1 ;
int V_180 ;
V_180 = F_102 ( V_2 -> V_182 ) ;
if ( V_180 )
return;
V_180 = F_102 ( V_2 -> V_183 ) ;
if ( V_180 ) {
F_103 ( V_2 -> V_182 ) ;
return;
}
if ( V_2 -> V_9 . V_120 )
V_265 = 0 ;
else if ( V_266 )
V_265 = F_104 ( & V_2 -> V_9 . V_35 , V_34 ) ;
else
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_5 ( & V_2 -> V_9 , & V_264 ) ;
V_12 = V_264 . V_12 ;
if ( F_2 ( V_2 ) )
V_12 |= V_249 ;
V_12 |= V_190 ;
V_12 &= ~ ( V_42 | V_55 | V_189 ) ;
F_8 ( V_12 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_264 . V_15 | V_192 , V_2 -> V_9 . V_13 + V_16 ) ;
F_105 ( & V_2 -> V_9 , V_261 , V_143 , F_100 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_45 ) & V_46 ) ) ;
F_7 ( & V_2 -> V_9 , & V_264 ) ;
if ( V_265 )
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_103 ( V_2 -> V_183 ) ;
F_103 ( V_2 -> V_182 ) ;
}
static void T_3
F_106 ( struct V_1 * V_2 , int * V_208 ,
int * V_108 , int * V_267 )
{
if ( F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_190 ) {
unsigned int V_15 , V_197 , V_198 , V_227 ;
unsigned int V_268 ;
unsigned int V_269 ;
V_15 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
* V_108 = 'n' ;
if ( V_15 & V_224 ) {
if ( V_15 & V_226 )
* V_108 = 'o' ;
else
* V_108 = 'e' ;
}
if ( V_15 & V_219 )
* V_267 = 8 ;
else
* V_267 = 7 ;
V_197 = F_6 ( V_2 -> V_9 . V_13 + V_200 ) & 0xffff ;
V_198 = F_6 ( V_2 -> V_9 . V_13 + V_201 ) & 0xffff ;
V_269 = ( F_6 ( V_2 -> V_9 . V_13 + V_154 ) & V_155 ) >> 7 ;
if ( V_269 == 6 )
V_269 = 7 ;
else
V_269 = 6 - V_269 ;
V_227 = F_107 ( V_2 -> V_182 ) ;
V_227 /= V_269 ;
{
unsigned int V_270 = V_197 + 1 ;
unsigned int div = 16 * ( V_198 + 1 ) ;
unsigned int V_271 = V_227 % div ;
V_268 = ( V_227 / div ) * V_270 ;
V_268 += ( V_271 * V_270 + div / 2 ) / div ;
* V_208 = ( V_268 + 50 ) / 100 * 100 ;
}
if ( * V_208 != V_268 )
F_108 ( L_17 ,
V_268 , * V_208 ) ;
}
}
static int T_3
F_109 ( struct V_259 * V_260 , char * V_272 )
{
struct V_1 * V_2 ;
int V_208 = 9600 ;
int V_267 = 8 ;
int V_108 = 'n' ;
int V_273 = 'n' ;
int V_180 ;
if ( V_260 -> V_263 == - 1 || V_260 -> V_263 >= F_110 ( V_262 ) )
V_260 -> V_263 = 0 ;
V_2 = V_262 [ V_260 -> V_263 ] ;
if ( V_2 == NULL )
return - V_274 ;
V_180 = F_73 ( V_2 -> V_183 ) ;
if ( V_180 )
goto V_275;
if ( V_272 )
F_111 ( V_272 , & V_208 , & V_108 , & V_267 , & V_273 ) ;
else
F_106 ( V_2 , & V_208 , & V_108 , & V_267 ) ;
F_61 ( V_2 , V_178 , V_179 ) ;
V_180 = F_112 ( & V_2 -> V_9 , V_260 , V_208 , V_108 , V_267 , V_273 ) ;
F_103 ( V_2 -> V_183 ) ;
if ( V_180 ) {
F_113 ( V_2 -> V_183 ) ;
goto V_275;
}
V_180 = F_114 ( V_2 -> V_182 ) ;
if ( V_180 )
F_74 ( V_2 -> V_183 ) ;
V_275:
return V_180 ;
}
static void F_115 ( struct V_8 * V_9 , int V_258 )
{
while ( F_96 ( V_9 -> V_13 + V_202 ) & V_62 )
F_116 () ;
F_98 ( V_258 , V_9 -> V_13 + V_59 ) ;
}
static void F_117 ( struct V_259 * V_276 , const char * V_261 ,
unsigned V_143 )
{
struct V_277 * V_70 = V_276 -> V_33 ;
F_105 ( & V_70 -> V_9 , V_261 , V_143 , F_115 ) ;
}
static int T_3
F_118 ( struct V_277 * V_70 , const char * V_278 )
{
if ( ! V_70 -> V_9 . V_13 )
return - V_274 ;
V_70 -> V_276 -> V_279 = F_117 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
struct V_282 * V_283 = V_281 -> V_70 . V_284 ;
const struct V_285 * V_286 =
F_120 ( V_287 , & V_281 -> V_70 ) ;
int V_82 ;
if ( ! V_283 )
return 1 ;
V_82 = F_121 ( V_283 , L_18 ) ;
if ( V_82 < 0 ) {
F_36 ( & V_281 -> V_70 , L_19 , V_82 ) ;
return V_82 ;
}
V_2 -> V_9 . line = V_82 ;
if ( F_122 ( V_283 , L_20 , NULL ) )
V_2 -> V_193 = 1 ;
if ( F_122 ( V_283 , L_21 , NULL ) )
V_2 -> V_236 = 1 ;
V_2 -> V_3 = V_286 -> V_33 ;
return 0 ;
}
static inline int F_119 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
return 1 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
struct V_288 * V_289 = F_124 ( & V_281 -> V_70 ) ;
V_2 -> V_9 . line = V_281 -> V_290 ;
V_2 -> V_3 = (struct V_291 * ) V_281 -> V_292 -> V_293 ;
if ( ! V_289 )
return;
if ( V_289 -> V_34 & V_294 )
V_2 -> V_193 = 1 ;
}
static int F_125 ( struct V_280 * V_281 )
{
struct V_1 * V_2 ;
void T_4 * V_295 ;
int V_82 = 0 , V_296 ;
struct V_297 * V_298 ;
int V_299 , V_300 , V_301 ;
V_2 = F_126 ( & V_281 -> V_70 , sizeof( * V_2 ) , V_170 ) ;
if ( ! V_2 )
return - V_171 ;
V_82 = F_119 ( V_2 , V_281 ) ;
if ( V_82 > 0 )
F_123 ( V_2 , V_281 ) ;
else if ( V_82 < 0 )
return V_82 ;
V_298 = F_127 ( V_281 , V_302 , 0 ) ;
V_295 = F_128 ( & V_281 -> V_70 , V_298 ) ;
if ( F_129 ( V_295 ) )
return F_130 ( V_295 ) ;
V_300 = F_131 ( V_281 , 0 ) ;
V_299 = F_131 ( V_281 , 1 ) ;
V_301 = F_131 ( V_281 , 2 ) ;
V_2 -> V_9 . V_70 = & V_281 -> V_70 ;
V_2 -> V_9 . V_164 = V_298 -> V_303 ;
V_2 -> V_9 . V_13 = V_295 ;
V_2 -> V_9 . type = V_238 ,
V_2 -> V_9 . V_304 = V_244 ;
V_2 -> V_9 . V_89 = V_300 ;
V_2 -> V_9 . V_305 = 32 ;
V_2 -> V_9 . V_21 = & V_306 ;
V_2 -> V_9 . V_307 = F_99 ;
V_2 -> V_9 . V_43 . V_34 =
V_88 | V_257 ;
V_2 -> V_9 . V_34 = V_308 ;
F_132 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_309 = F_13 ;
V_2 -> V_36 . V_33 = ( unsigned long ) V_2 ;
V_2 -> V_183 = F_133 ( & V_281 -> V_70 , L_22 ) ;
if ( F_129 ( V_2 -> V_183 ) ) {
V_82 = F_130 ( V_2 -> V_183 ) ;
F_36 ( & V_281 -> V_70 , L_23 , V_82 ) ;
return V_82 ;
}
V_2 -> V_182 = F_133 ( & V_281 -> V_70 , L_24 ) ;
if ( F_129 ( V_2 -> V_182 ) ) {
V_82 = F_130 ( V_2 -> V_182 ) ;
F_36 ( & V_281 -> V_70 , L_25 , V_82 ) ;
return V_82 ;
}
V_2 -> V_9 . V_227 = F_107 ( V_2 -> V_182 ) ;
V_82 = F_73 ( V_2 -> V_183 ) ;
if ( V_82 )
return V_82 ;
V_296 = F_96 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_296 &= ~ ( V_310 | V_311 | V_312 | V_55 |
V_42 | V_189 ) ;
F_98 ( V_296 , V_2 -> V_9 . V_13 + V_14 ) ;
F_74 ( V_2 -> V_183 ) ;
if ( V_299 > 0 ) {
V_82 = F_134 ( & V_281 -> V_70 , V_300 , F_43 , 0 ,
F_135 ( & V_281 -> V_70 ) , V_2 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_134 ( & V_281 -> V_70 , V_299 , F_42 , 0 ,
F_135 ( & V_281 -> V_70 ) , V_2 ) ;
if ( V_82 )
return V_82 ;
} else {
V_82 = F_134 ( & V_281 -> V_70 , V_300 , F_52 , 0 ,
F_135 ( & V_281 -> V_70 ) , V_2 ) ;
if ( V_82 )
return V_82 ;
}
V_262 [ V_2 -> V_9 . line ] = V_2 ;
F_136 ( V_281 , V_2 ) ;
return F_137 ( & V_313 , & V_2 -> V_9 ) ;
}
static int F_138 ( struct V_280 * V_281 )
{
struct V_1 * V_2 = F_139 ( V_281 ) ;
return F_140 ( & V_313 , & V_2 -> V_9 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_314 )
return;
F_8 ( V_2 -> V_315 [ 4 ] , V_2 -> V_9 . V_13 + V_154 ) ;
F_8 ( V_2 -> V_315 [ 5 ] , V_2 -> V_9 . V_13 + V_316 ) ;
F_8 ( V_2 -> V_315 [ 6 ] , V_2 -> V_9 . V_13 + V_317 ) ;
F_8 ( V_2 -> V_315 [ 7 ] , V_2 -> V_9 . V_13 + V_200 ) ;
F_8 ( V_2 -> V_315 [ 8 ] , V_2 -> V_9 . V_13 + V_201 ) ;
F_8 ( V_2 -> V_315 [ 9 ] , V_2 -> V_9 . V_13 + V_202 ) ;
F_8 ( V_2 -> V_315 [ 0 ] , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_2 -> V_315 [ 1 ] | V_188 , V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_2 -> V_315 [ 2 ] , V_2 -> V_9 . V_13 + V_18 ) ;
F_8 ( V_2 -> V_315 [ 3 ] , V_2 -> V_9 . V_13 + V_49 ) ;
V_2 -> V_314 = false ;
}
static void F_142 ( struct V_1 * V_2 )
{
V_2 -> V_315 [ 0 ] = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_315 [ 1 ] = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_2 -> V_315 [ 2 ] = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_2 -> V_315 [ 3 ] = F_6 ( V_2 -> V_9 . V_13 + V_49 ) ;
V_2 -> V_315 [ 4 ] = F_6 ( V_2 -> V_9 . V_13 + V_154 ) ;
V_2 -> V_315 [ 5 ] = F_6 ( V_2 -> V_9 . V_13 + V_316 ) ;
V_2 -> V_315 [ 6 ] = F_6 ( V_2 -> V_9 . V_13 + V_317 ) ;
V_2 -> V_315 [ 7 ] = F_6 ( V_2 -> V_9 . V_13 + V_200 ) ;
V_2 -> V_315 [ 8 ] = F_6 ( V_2 -> V_9 . V_13 + V_201 ) ;
V_2 -> V_315 [ 9 ] = F_6 ( V_2 -> V_9 . V_13 + V_202 ) ;
V_2 -> V_314 = true ;
}
static void F_143 ( struct V_1 * V_2 , bool V_318 )
{
unsigned int V_91 ;
V_91 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
if ( V_318 )
V_91 |= V_319 ;
else
V_91 &= ~ V_319 ;
F_8 ( V_91 , V_2 -> V_9 . V_13 + V_18 ) ;
V_91 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( V_318 )
V_91 |= V_189 ;
else
V_91 &= ~ V_189 ;
F_8 ( V_91 , V_2 -> V_9 . V_13 + V_14 ) ;
}
static int F_144 ( struct V_81 * V_70 )
{
struct V_280 * V_281 = F_145 ( V_70 ) ;
struct V_1 * V_2 = F_139 ( V_281 ) ;
int V_82 ;
V_82 = F_102 ( V_2 -> V_183 ) ;
if ( V_82 )
return V_82 ;
F_142 ( V_2 ) ;
F_103 ( V_2 -> V_183 ) ;
return 0 ;
}
static int F_146 ( struct V_81 * V_70 )
{
struct V_280 * V_281 = F_145 ( V_70 ) ;
struct V_1 * V_2 = F_139 ( V_281 ) ;
int V_82 ;
V_82 = F_102 ( V_2 -> V_183 ) ;
if ( V_82 )
return V_82 ;
F_141 ( V_2 ) ;
F_103 ( V_2 -> V_183 ) ;
return 0 ;
}
static int F_147 ( struct V_81 * V_70 )
{
struct V_280 * V_281 = F_145 ( V_70 ) ;
struct V_1 * V_2 = F_139 ( V_281 ) ;
F_143 ( V_2 , true ) ;
F_148 ( & V_313 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_149 ( struct V_81 * V_70 )
{
struct V_280 * V_281 = F_145 ( V_70 ) ;
struct V_1 * V_2 = F_139 ( V_281 ) ;
F_143 ( V_2 , false ) ;
F_150 ( & V_313 , & V_2 -> V_9 ) ;
return 0 ;
}
static int T_3 F_151 ( void )
{
int V_82 = F_152 ( & V_313 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_153 ( & V_320 ) ;
if ( V_82 != 0 )
F_154 ( & V_313 ) ;
return V_82 ;
}
static void T_5 F_155 ( void )
{
F_156 ( & V_320 ) ;
F_154 ( & V_313 ) ;
}
