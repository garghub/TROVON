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
if ( F_18 ( V_2 ) ) {
int V_40 = 256 ;
while ( ( -- V_40 > 0 ) &&
! ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) ) {
F_19 ( 5 ) ;
F_20 () ;
}
F_19 ( V_2 -> V_43 ) ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_44 | V_45 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 &= ~ ( V_47 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
while ( F_6 ( V_2 -> V_9 . V_13 + V_48 ) &
V_49 )
F_20 () ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_50 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 |= V_51 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
}
return;
}
if ( V_2 -> V_52 && V_2 -> V_53 )
return;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_39 & ~ V_44 , V_2 -> V_9 . V_13 + V_14 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
if ( V_2 -> V_52 && V_2 -> V_54 ) {
if ( V_2 -> V_9 . V_55 ) {
F_22 ( V_2 -> V_56 ) ;
V_2 -> V_54 = 0 ;
} else {
return;
}
}
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_39 & ~ V_57 , V_2 -> V_9 . V_13 + V_16 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_39 & ~ V_50 , V_2 -> V_9 . V_13 + V_14 ) ;
}
static void F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_16 ( & V_2 -> V_36 , V_37 ) ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = & V_2 -> V_9 . V_31 -> V_59 ;
unsigned long V_39 ;
if ( V_2 -> V_9 . V_60 ) {
F_8 ( V_2 -> V_9 . V_60 , V_2 -> V_9 . V_13 + V_61 ) ;
V_2 -> V_9 . V_25 . V_62 ++ ;
V_2 -> V_9 . V_60 = 0 ;
return;
}
if ( F_25 ( V_59 ) || F_26 ( & V_2 -> V_9 ) ) {
F_17 ( & V_2 -> V_9 ) ;
return;
}
if ( V_2 -> V_52 ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_44 ;
if ( V_2 -> V_53 ) {
V_39 |= V_63 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
} else {
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_27 ( V_2 ) ;
}
}
while ( ! F_25 ( V_59 ) &&
! ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_64 ) ) {
F_8 ( V_59 -> V_65 [ V_59 -> V_66 ] , V_2 -> V_9 . V_13 + V_61 ) ;
V_59 -> V_66 = ( V_59 -> V_66 + 1 ) & ( V_67 - 1 ) ;
V_2 -> V_9 . V_25 . V_62 ++ ;
}
if ( F_28 ( V_59 ) < V_68 )
F_29 ( & V_2 -> V_9 ) ;
if ( F_25 ( V_59 ) )
F_17 ( & V_2 -> V_9 ) ;
}
static void F_30 ( void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_69 * V_70 = & V_2 -> V_71 [ 0 ] ;
struct V_58 * V_59 = & V_2 -> V_9 . V_31 -> V_59 ;
unsigned long V_34 ;
unsigned long V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_31 ( V_2 -> V_9 . V_72 , V_70 , V_2 -> V_73 , V_74 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_63 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_59 -> V_66 = ( V_59 -> V_66 + V_2 -> V_75 ) & ( V_67 - 1 ) ;
V_2 -> V_9 . V_25 . V_62 += V_2 -> V_75 ;
F_32 ( V_2 -> V_9 . V_72 , L_1 ) ;
V_2 -> V_53 = 0 ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( F_28 ( V_59 ) < V_68 )
F_29 ( & V_2 -> V_9 ) ;
if ( F_33 ( & V_2 -> V_76 ) ) {
F_34 ( & V_2 -> V_76 ) ;
F_32 ( V_2 -> V_9 . V_72 , L_2 , V_77 ) ;
return;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( ! F_25 ( V_59 ) && ! F_26 ( & V_2 -> V_9 ) )
F_27 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = & V_2 -> V_9 . V_31 -> V_59 ;
struct V_69 * V_70 = V_2 -> V_71 ;
struct V_78 * V_79 ;
struct V_80 * V_81 = V_2 -> V_82 ;
struct V_83 * V_72 = V_2 -> V_9 . V_72 ;
unsigned long V_39 ;
int V_84 ;
if ( V_2 -> V_53 )
return;
V_2 -> V_75 = F_28 ( V_59 ) ;
if ( V_59 -> V_66 < V_59 -> V_85 ) {
V_2 -> V_73 = 1 ;
F_35 ( V_70 , V_59 -> V_65 + V_59 -> V_66 , V_2 -> V_75 ) ;
} else {
V_2 -> V_73 = 2 ;
F_36 ( V_70 , 2 ) ;
F_37 ( V_70 , V_59 -> V_65 + V_59 -> V_66 ,
V_67 - V_59 -> V_66 ) ;
F_37 ( V_70 + 1 , V_59 -> V_65 , V_59 -> V_85 ) ;
}
V_84 = F_38 ( V_72 , V_70 , V_2 -> V_73 , V_74 ) ;
if ( V_84 == 0 ) {
F_39 ( V_72 , L_3 ) ;
return;
}
V_79 = F_40 ( V_81 , V_70 , V_2 -> V_73 ,
V_86 , V_87 ) ;
if ( ! V_79 ) {
F_31 ( V_72 , V_70 , V_2 -> V_73 ,
V_74 ) ;
F_39 ( V_72 , L_4 ) ;
return;
}
V_79 -> V_88 = F_30 ;
V_79 -> V_89 = V_2 ;
F_32 ( V_72 , L_5 ,
F_28 ( V_59 ) ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_63 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_53 = 1 ;
F_41 ( V_79 ) ;
F_42 ( V_81 ) ;
return;
}
static void F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
if ( F_18 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 &= ~ ( V_51 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_50 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
}
if ( ! V_2 -> V_52 ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_39 | V_44 , V_2 -> V_9 . V_13 + V_14 ) ;
}
if ( F_18 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_45 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 |= V_47 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
}
if ( V_2 -> V_52 ) {
if ( V_2 -> V_9 . V_60 ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_63 ;
V_39 |= V_44 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
return;
}
if ( ! F_25 ( & V_9 -> V_31 -> V_59 ) &&
! F_26 ( V_9 ) )
F_27 ( V_2 ) ;
return;
}
}
static T_1 F_44 ( int V_90 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
unsigned int V_92 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_8 ( V_93 , V_2 -> V_9 . V_13 + V_94 ) ;
V_92 = F_6 ( V_2 -> V_9 . V_13 + V_94 ) & V_95 ;
F_11 ( & V_2 -> V_9 , ! ! V_92 ) ;
F_12 ( & V_2 -> V_9 . V_31 -> V_9 . V_32 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return V_96 ;
}
static T_1 F_45 ( int V_90 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_24 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return V_96 ;
}
static T_1 F_46 ( int V_90 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
unsigned int V_97 , V_98 , V_99 = 0 ;
struct V_100 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
unsigned long V_34 , V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
while ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_101 ) {
V_98 = V_102 ;
V_2 -> V_9 . V_25 . V_97 ++ ;
V_97 = F_6 ( V_2 -> V_9 . V_13 + V_48 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
if ( V_39 & V_103 ) {
F_8 ( V_103 , V_2 -> V_9 . V_13 + V_41 ) ;
if ( F_47 ( & V_2 -> V_9 ) )
continue;
}
if ( F_48 ( & V_2 -> V_9 , ( unsigned char ) V_97 ) )
continue;
if ( F_49 ( V_97 & V_104 ) ) {
if ( V_97 & V_105 )
V_2 -> V_9 . V_25 . V_106 ++ ;
else if ( V_97 & V_107 )
V_2 -> V_9 . V_25 . V_108 ++ ;
else if ( V_97 & V_109 )
V_2 -> V_9 . V_25 . V_110 ++ ;
if ( V_97 & V_111 )
V_2 -> V_9 . V_25 . V_112 ++ ;
if ( V_97 & V_2 -> V_9 . V_113 ) {
if ( ++ V_99 > 100 )
goto V_114;
continue;
}
V_97 &= ( V_2 -> V_9 . V_115 | 0xFF ) ;
if ( V_97 & V_105 )
V_98 = V_116 ;
else if ( V_97 & V_107 )
V_98 = V_117 ;
else if ( V_97 & V_109 )
V_98 = V_118 ;
if ( V_97 & V_111 )
V_98 = V_119 ;
#ifdef F_50
V_2 -> V_9 . V_120 = 0 ;
#endif
}
if ( V_2 -> V_9 . V_113 & V_121 )
goto V_114;
F_51 ( V_9 , V_97 , V_98 ) ;
}
V_114:
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_52 ( V_9 ) ;
return V_96 ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
if ( ( V_39 & V_101 ) && ! V_2 -> V_54 ) {
V_2 -> V_54 = 1 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_50 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_54 ( V_2 ) ;
}
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static T_1 F_55 ( int V_90 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
unsigned int V_122 ;
unsigned int V_123 ;
V_122 = F_6 ( V_2 -> V_9 . V_13 + V_94 ) ;
if ( V_122 & V_124 ) {
if ( V_2 -> V_52 )
F_53 ( V_2 ) ;
else
F_46 ( V_90 , V_91 ) ;
}
if ( V_122 & V_125 &&
F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_44 )
F_45 ( V_90 , V_91 ) ;
if ( V_122 & V_93 )
F_44 ( V_90 , V_91 ) ;
if ( V_122 & V_126 )
F_8 ( V_126 , V_2 -> V_9 . V_13 + V_94 ) ;
V_123 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
if ( V_123 & V_127 ) {
F_39 ( V_2 -> V_9 . V_72 , L_6 ) ;
V_2 -> V_9 . V_25 . V_112 ++ ;
F_8 ( V_123 | V_127 , V_2 -> V_9 . V_13 + V_41 ) ;
}
return V_96 ;
}
static unsigned int F_56 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_84 ;
V_84 = ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) ? V_128 : 0 ;
if ( V_2 -> V_52 && V_2 -> V_53 )
V_84 = 0 ;
return V_84 ;
}
static unsigned int F_57 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_129 = V_27 | V_29 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_94 ) & V_95 )
V_129 |= V_30 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_130 )
V_129 |= V_131 ;
if ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_132 )
V_129 |= V_133 ;
return V_129 ;
}
static void F_58 ( struct V_8 * V_9 , unsigned int V_134 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) & ~ ( V_130 | V_135 ) ;
if ( V_134 & V_131 )
V_39 |= V_130 | V_135 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & ~ V_132 ;
if ( V_134 & V_133 )
V_39 |= V_132 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) ;
}
static void F_59 ( struct V_8 * V_9 , int V_136 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 , V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) & ~ V_137 ;
if ( V_136 != 0 )
V_39 |= V_137 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_138 )
{
unsigned int V_92 ;
V_92 = F_6 ( V_2 -> V_9 . V_13 + V_139 ) & ( V_140 | V_141 ) ;
V_92 |= V_142 << V_143 | V_144 ;
F_8 ( V_92 , V_2 -> V_9 . V_13 + V_139 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_50 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_54 = 0 ;
if ( F_33 ( & V_2 -> V_76 ) )
F_34 ( & V_2 -> V_76 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static void F_62 ( void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_80 * V_81 = V_2 -> V_56 ;
struct V_69 * V_70 = & V_2 -> V_145 ;
struct V_100 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
struct V_146 V_31 ;
enum V_147 V_19 ;
unsigned int V_148 ;
F_31 ( V_2 -> V_9 . V_72 , V_70 , 1 , V_149 ) ;
V_19 = F_63 ( V_81 , ( V_150 ) 0 , & V_31 ) ;
V_148 = V_151 - V_31 . V_152 ;
F_32 ( V_2 -> V_9 . V_72 , L_7 , V_148 ) ;
if ( V_148 ) {
if ( ! ( V_2 -> V_9 . V_113 & V_121 ) )
F_64 ( V_9 , V_2 -> V_153 , V_148 ) ;
F_52 ( V_9 ) ;
F_54 ( V_2 ) ;
} else if ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_101 ) {
F_54 ( V_2 ) ;
} else {
F_61 ( V_2 ) ;
}
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = & V_2 -> V_145 ;
struct V_80 * V_81 = V_2 -> V_56 ;
struct V_83 * V_72 = V_2 -> V_9 . V_72 ;
struct V_78 * V_79 ;
int V_84 ;
F_35 ( V_70 , V_2 -> V_153 , V_151 ) ;
V_84 = F_38 ( V_72 , V_70 , 1 , V_149 ) ;
if ( V_84 == 0 ) {
F_39 ( V_72 , L_8 ) ;
return - V_154 ;
}
V_79 = F_40 ( V_81 , V_70 , 1 , V_155 ,
V_87 ) ;
if ( ! V_79 ) {
F_31 ( V_72 , V_70 , 1 , V_149 ) ;
F_39 ( V_72 , L_9 ) ;
return - V_154 ;
}
V_79 -> V_88 = F_62 ;
V_79 -> V_89 = V_2 ;
F_32 ( V_72 , L_10 ) ;
F_41 ( V_79 ) ;
F_42 ( V_81 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 ) {
F_66 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
F_67 ( V_2 -> V_153 ) ;
V_2 -> V_153 = NULL ;
}
if ( V_2 -> V_82 ) {
F_66 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
}
V_2 -> V_156 = 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_157 V_158 = {} ;
struct V_83 * V_72 = V_2 -> V_9 . V_72 ;
int V_84 ;
V_2 -> V_56 = F_69 ( V_72 , L_11 ) ;
if ( ! V_2 -> V_56 ) {
F_32 ( V_72 , L_12 ) ;
V_84 = - V_154 ;
goto V_159;
}
V_158 . V_160 = V_155 ;
V_158 . V_161 = V_2 -> V_9 . V_162 + V_48 ;
V_158 . V_163 = V_164 ;
V_158 . V_165 = V_144 ;
V_84 = F_70 ( V_2 -> V_56 , & V_158 ) ;
if ( V_84 ) {
F_39 ( V_72 , L_13 ) ;
goto V_159;
}
V_2 -> V_153 = F_71 ( V_166 , V_167 ) ;
if ( ! V_2 -> V_153 ) {
V_84 = - V_168 ;
goto V_159;
}
V_2 -> V_82 = F_69 ( V_72 , L_14 ) ;
if ( ! V_2 -> V_82 ) {
F_39 ( V_72 , L_15 ) ;
V_84 = - V_154 ;
goto V_159;
}
V_158 . V_160 = V_86 ;
V_158 . V_169 = V_2 -> V_9 . V_162 + V_61 ;
V_158 . V_170 = V_164 ;
V_158 . V_171 = V_142 ;
V_84 = F_70 ( V_2 -> V_82 , & V_158 ) ;
if ( V_84 ) {
F_39 ( V_72 , L_16 ) ;
goto V_159;
}
V_2 -> V_156 = 1 ;
return 0 ;
V_159:
F_65 ( V_2 ) ;
return V_84 ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
F_73 ( & V_2 -> V_76 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_172 | V_63 | V_173 |
F_74 ( 3 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 |= V_174 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
V_2 -> V_52 = 1 ;
}
static void F_75 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_172 | V_63 | V_173 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_135 | V_130 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 &= ~ V_174 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
V_2 -> V_52 = 0 ;
}
static int F_76 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_175 , V_176 ;
unsigned long V_34 , V_39 ;
V_175 = F_77 ( V_2 -> V_177 ) ;
if ( V_175 )
return V_175 ;
V_175 = F_77 ( V_2 -> V_178 ) ;
if ( V_175 ) {
F_78 ( V_2 -> V_177 ) ;
return V_175 ;
}
F_60 ( V_2 , 0 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
if ( F_18 ( V_2 ) )
V_39 |= V_179 ;
V_39 &= ~ ( V_180 << V_181 ) ;
V_39 |= V_182 << V_181 ;
F_8 ( V_39 & ~ V_51 , V_2 -> V_9 . V_13 + V_46 ) ;
V_176 = 100 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_183 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_183 ) && ( -- V_176 > 0 ) )
F_19 ( 1 ) ;
if ( F_4 ( V_2 ) && ! F_79 ( V_9 ) &&
! V_2 -> V_156 )
F_68 ( V_2 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_8 ( V_93 , V_2 -> V_9 . V_13 + V_94 ) ;
if ( V_2 -> V_156 && ! V_2 -> V_52 )
F_72 ( V_2 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_50 | V_184 | V_185 ;
if ( F_18 ( V_2 ) ) {
V_39 |= V_186 ;
V_39 &= ~ ( V_184 ) ;
}
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
F_8 ( V_39 | V_127 , V_2 -> V_9 . V_13 + V_41 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 |= V_187 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= ( V_57 | V_188 ) ;
if ( ! V_2 -> V_189 )
V_39 |= V_190 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( ! F_2 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_39 |= V_191 | V_192 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_18 ) ;
}
if ( F_18 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
if ( V_2 -> V_193 )
V_39 |= V_194 ;
else
V_39 &= ~ ( V_194 ) ;
F_8 ( V_39 | V_51 , V_2 -> V_9 . V_13 + V_46 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
if ( V_2 -> V_195 )
V_39 |= V_196 ;
else
V_39 &= ~ ( V_196 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_18 ) ;
}
F_23 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( F_18 ( V_2 ) ) {
struct V_197 * V_198 ;
V_198 = F_80 ( V_2 -> V_9 . V_72 ) ;
V_2 -> V_193 = V_198 -> V_193 ;
V_2 -> V_195 = V_198 -> V_195 ;
V_2 -> V_43 = V_198 -> V_199 ;
if ( V_198 -> V_200 )
V_198 -> V_200 ( 1 ) ;
}
return 0 ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
unsigned long V_34 ;
if ( V_2 -> V_52 ) {
int V_84 ;
V_84 = F_82 ( V_2 -> V_76 ,
! V_2 -> V_54 && ! V_2 -> V_53 ) ;
if ( V_84 != 0 ) {
V_2 -> V_54 = 0 ;
V_2 -> V_53 = 0 ;
F_22 ( V_2 -> V_82 ) ;
F_22 ( V_2 -> V_56 ) ;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_17 ( V_9 ) ;
F_21 ( V_9 ) ;
F_75 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_65 ( V_2 ) ;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_188 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( F_18 ( V_2 ) ) {
struct V_197 * V_198 ;
V_198 = F_80 ( V_2 -> V_9 . V_72 ) ;
if ( V_198 -> V_200 )
V_198 -> V_200 ( 0 ) ;
}
F_83 ( & V_2 -> V_36 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_44 | V_50 | V_184 | V_185 ) ;
if ( F_18 ( V_2 ) )
V_39 &= ~ ( V_186 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_78 ( V_2 -> V_177 ) ;
F_78 ( V_2 -> V_178 ) ;
}
static void F_84 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
struct V_69 * V_70 = & V_2 -> V_71 [ 0 ] ;
unsigned long V_39 ;
int V_176 = 100 , V_201 , V_202 , V_203 , V_204 ;
if ( ! V_2 -> V_82 )
return;
V_2 -> V_75 = 0 ;
F_22 ( V_2 -> V_82 ) ;
if ( V_2 -> V_53 ) {
F_31 ( V_2 -> V_9 . V_72 , V_70 , V_2 -> V_73 ,
V_74 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ V_63 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_53 = false ;
}
V_201 = F_6 ( V_2 -> V_9 . V_13 + V_205 ) ;
V_202 = F_6 ( V_2 -> V_9 . V_13 + V_206 ) ;
V_203 = F_6 ( V_2 -> V_9 . V_13 + V_207 ) ;
V_204 = F_6 ( V_2 -> V_9 . V_13 + V_208 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_183 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_183 ) && ( -- V_176 > 0 ) )
F_19 ( 1 ) ;
F_8 ( V_201 , V_2 -> V_9 . V_13 + V_205 ) ;
F_8 ( V_202 , V_2 -> V_9 . V_13 + V_206 ) ;
F_8 ( V_203 , V_2 -> V_9 . V_13 + V_207 ) ;
F_8 ( V_204 , V_2 -> V_9 . V_13 + V_208 ) ;
}
static void
F_85 ( struct V_8 * V_9 , struct V_209 * V_210 ,
struct V_209 * V_211 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 ;
unsigned int V_15 , V_212 , V_213 , V_214 , V_215 ;
unsigned int V_216 = V_211 ? V_211 -> V_217 & V_218 : V_219 ;
unsigned int div , V_220 ;
unsigned long V_221 , V_222 ;
T_2 V_223 ;
if ( 0 ) {
V_210 -> V_217 &= ~ ( V_224 | V_225 | V_226 ) ;
V_210 -> V_217 |= V_227 ;
}
while ( ( V_210 -> V_217 & V_218 ) != V_228 &&
( V_210 -> V_217 & V_218 ) != V_219 ) {
V_210 -> V_217 &= ~ V_218 ;
V_210 -> V_217 |= V_216 ;
V_216 = V_219 ;
}
if ( ( V_210 -> V_217 & V_218 ) == V_219 )
V_15 = V_229 | V_183 | V_190 ;
else
V_15 = V_183 | V_190 ;
if ( V_210 -> V_217 & V_225 ) {
if ( V_2 -> V_189 ) {
V_15 &= ~ V_190 ;
V_15 |= V_135 ;
} else {
V_210 -> V_217 &= ~ V_225 ;
}
}
if ( V_210 -> V_217 & V_230 )
V_15 |= V_231 ;
if ( V_210 -> V_217 & V_232 ) {
V_15 |= V_233 ;
if ( V_210 -> V_217 & V_234 )
V_15 |= V_235 ;
}
F_83 ( & V_2 -> V_36 ) ;
V_214 = F_86 ( V_9 , V_210 , V_211 , 50 , V_9 -> V_236 / 16 ) ;
V_215 = F_87 ( V_9 , V_214 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_2 -> V_9 . V_115 = 0 ;
if ( V_210 -> V_237 & V_238 )
V_2 -> V_9 . V_115 |= ( V_109 | V_107 ) ;
if ( V_210 -> V_237 & ( V_239 | V_240 ) )
V_2 -> V_9 . V_115 |= V_105 ;
V_2 -> V_9 . V_113 = 0 ;
if ( V_210 -> V_237 & V_241 )
V_2 -> V_9 . V_113 |= V_107 | V_109 ;
if ( V_210 -> V_237 & V_242 ) {
V_2 -> V_9 . V_113 |= V_105 ;
if ( V_210 -> V_237 & V_241 )
V_2 -> V_9 . V_113 |= V_111 ;
}
if ( ( V_210 -> V_217 & V_243 ) == 0 )
V_2 -> V_9 . V_113 |= V_121 ;
F_88 ( V_9 , V_210 -> V_217 , V_214 ) ;
V_212 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_212 & ~ ( V_44 | V_50 | V_184 ) ,
V_2 -> V_9 . V_13 + V_14 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) )
F_20 () ;
V_213 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_213 & ~ ( V_188 | V_57 ) ,
V_2 -> V_9 . V_13 + V_16 ) ;
V_213 &= ( V_188 | V_57 ) ;
if ( F_18 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_9 . V_236 / ( V_214 * 16 ) ;
if ( V_214 == 38400 && V_215 != div )
V_214 = V_2 -> V_9 . V_236 / ( V_215 * 16 ) ;
div = V_2 -> V_9 . V_236 / ( V_214 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_89 ( 16 * div * V_214 , V_2 -> V_9 . V_236 ,
1 << 16 , 1 << 16 , & V_221 , & V_222 ) ;
V_223 = V_2 -> V_9 . V_236 ;
V_223 *= V_221 ;
F_90 ( V_223 , V_222 * 16 * div ) ;
F_91 ( V_210 ,
( V_244 ) V_223 , ( V_244 ) V_223 ) ;
V_221 -= 1 ;
V_222 -= 1 ;
V_220 = F_6 ( V_2 -> V_9 . V_13 + V_139 ) ;
V_220 = ( V_220 & ( ~ V_140 ) ) | F_92 ( div ) ;
if ( V_2 -> V_245 )
V_220 |= V_141 ;
F_8 ( V_220 , V_2 -> V_9 . V_13 + V_139 ) ;
F_8 ( V_221 , V_2 -> V_9 . V_13 + V_205 ) ;
F_8 ( V_222 , V_2 -> V_9 . V_13 + V_206 ) ;
if ( ! F_2 ( V_2 ) )
F_8 ( V_2 -> V_9 . V_236 / div / 1000 ,
V_2 -> V_9 . V_13 + V_246 ) ;
F_8 ( V_212 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_15 | V_213 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( F_93 ( & V_2 -> V_9 , V_210 -> V_217 ) )
F_23 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static const char * F_94 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_247 ? L_17 : NULL ;
}
static void F_95 ( struct V_8 * V_9 , int V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_34 & V_248 )
V_2 -> V_9 . type = V_247 ;
}
static int
F_96 ( struct V_8 * V_9 , struct V_249 * V_250 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_84 = 0 ;
if ( V_250 -> type != V_251 && V_250 -> type != V_247 )
V_84 = - V_154 ;
if ( V_2 -> V_9 . V_90 != V_250 -> V_90 )
V_84 = - V_154 ;
if ( V_250 -> V_252 != V_253 )
V_84 = - V_154 ;
if ( V_2 -> V_9 . V_236 / 16 != V_250 -> V_254 )
V_84 = - V_154 ;
if ( V_2 -> V_9 . V_162 != ( unsigned long ) V_250 -> V_255 )
V_84 = - V_154 ;
if ( V_2 -> V_9 . V_256 != V_250 -> V_9 )
V_84 = - V_154 ;
if ( V_250 -> V_257 != 0 )
V_84 = - V_154 ;
return V_84 ;
}
static int F_97 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 ;
unsigned long V_39 ;
int V_175 ;
V_175 = F_77 ( V_2 -> V_178 ) ;
if ( V_175 )
return V_175 ;
V_175 = F_77 ( V_2 -> V_177 ) ;
if ( V_175 )
F_78 ( V_2 -> V_178 ) ;
F_60 ( V_2 , 0 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( F_2 ( V_2 ) )
V_39 |= V_258 ;
V_39 |= V_185 | V_50 ;
V_39 &= ~ ( V_44 | V_184 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= V_57 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return 0 ;
}
static int F_98 ( struct V_8 * V_9 )
{
if ( ! ( F_99 ( V_9 -> V_13 + V_41 ) & V_101 ) )
return V_259 ;
return F_99 ( V_9 -> V_13 + V_48 ) & V_260 ;
}
static void F_100 ( struct V_8 * V_9 , unsigned char V_261 )
{
unsigned int V_19 ;
do {
V_19 = F_99 ( V_9 -> V_13 + V_94 ) ;
} while ( ~ V_19 & V_125 );
F_101 ( V_261 , V_9 -> V_13 + V_61 ) ;
do {
V_19 = F_99 ( V_9 -> V_13 + V_41 ) ;
} while ( ~ V_19 & V_42 );
}
static void F_102 ( struct V_8 * V_9 , int V_262 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_64 )
F_20 () ;
F_8 ( V_262 , V_2 -> V_9 . V_13 + V_61 ) ;
}
static void
F_103 ( struct V_263 * V_264 , const char * V_265 , unsigned int V_148 )
{
struct V_1 * V_2 = V_266 [ V_264 -> V_267 ] ;
struct V_10 V_268 ;
unsigned int V_12 ;
unsigned long V_34 = 0 ;
int V_269 = 1 ;
int V_175 ;
V_175 = F_104 ( V_2 -> V_177 ) ;
if ( V_175 )
return;
V_175 = F_104 ( V_2 -> V_178 ) ;
if ( V_175 ) {
F_105 ( V_2 -> V_177 ) ;
return;
}
if ( V_2 -> V_9 . V_120 )
V_269 = 0 ;
else if ( V_270 )
V_269 = F_106 ( & V_2 -> V_9 . V_35 , V_34 ) ;
else
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_5 ( & V_2 -> V_9 , & V_268 ) ;
V_12 = V_268 . V_12 ;
if ( F_2 ( V_2 ) )
V_12 |= V_258 ;
V_12 |= V_185 ;
V_12 &= ~ ( V_44 | V_50 | V_184 ) ;
F_8 ( V_12 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_268 . V_15 | V_188 , V_2 -> V_9 . V_13 + V_16 ) ;
F_107 ( & V_2 -> V_9 , V_265 , V_148 , F_102 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) ) ;
F_7 ( & V_2 -> V_9 , & V_268 ) ;
if ( V_269 )
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_105 ( V_2 -> V_178 ) ;
F_105 ( V_2 -> V_177 ) ;
}
static void T_3
F_108 ( struct V_1 * V_2 , int * V_214 ,
int * V_108 , int * V_271 )
{
if ( F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_185 ) {
unsigned int V_15 , V_201 , V_202 , V_236 ;
unsigned int V_272 ;
unsigned int V_273 ;
V_15 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
* V_108 = 'n' ;
if ( V_15 & V_233 ) {
if ( V_15 & V_235 )
* V_108 = 'o' ;
else
* V_108 = 'e' ;
}
if ( V_15 & V_229 )
* V_271 = 8 ;
else
* V_271 = 7 ;
V_201 = F_6 ( V_2 -> V_9 . V_13 + V_205 ) & 0xffff ;
V_202 = F_6 ( V_2 -> V_9 . V_13 + V_206 ) & 0xffff ;
V_273 = ( F_6 ( V_2 -> V_9 . V_13 + V_139 ) & V_140 ) >> 7 ;
if ( V_273 == 6 )
V_273 = 7 ;
else
V_273 = 6 - V_273 ;
V_236 = F_109 ( V_2 -> V_177 ) ;
V_236 /= V_273 ;
{
unsigned int V_274 = V_201 + 1 ;
unsigned int div = 16 * ( V_202 + 1 ) ;
unsigned int V_275 = V_236 % div ;
V_272 = ( V_236 / div ) * V_274 ;
V_272 += ( V_275 * V_274 + div / 2 ) / div ;
* V_214 = ( V_272 + 50 ) / 100 * 100 ;
}
if ( * V_214 != V_272 )
F_110 ( L_18 ,
V_272 , * V_214 ) ;
}
}
static int T_3
F_111 ( struct V_263 * V_264 , char * V_276 )
{
struct V_1 * V_2 ;
int V_214 = 9600 ;
int V_271 = 8 ;
int V_108 = 'n' ;
int V_277 = 'n' ;
int V_175 ;
if ( V_264 -> V_267 == - 1 || V_264 -> V_267 >= F_112 ( V_266 ) )
V_264 -> V_267 = 0 ;
V_2 = V_266 [ V_264 -> V_267 ] ;
if ( V_2 == NULL )
return - V_278 ;
V_175 = F_77 ( V_2 -> V_178 ) ;
if ( V_175 )
goto V_279;
if ( V_276 )
F_113 ( V_276 , & V_214 , & V_108 , & V_271 , & V_277 ) ;
else
F_108 ( V_2 , & V_214 , & V_108 , & V_271 ) ;
F_60 ( V_2 , 0 ) ;
V_175 = F_114 ( & V_2 -> V_9 , V_264 , V_214 , V_108 , V_271 , V_277 ) ;
F_105 ( V_2 -> V_178 ) ;
if ( V_175 ) {
F_115 ( V_2 -> V_178 ) ;
goto V_279;
}
V_175 = F_116 ( V_2 -> V_177 ) ;
if ( V_175 )
F_78 ( V_2 -> V_178 ) ;
V_279:
return V_175 ;
}
static int F_117 ( struct V_280 * V_72 , T_4 V_31 )
{
struct V_1 * V_2 = F_118 ( V_72 ) ;
unsigned int V_92 ;
V_92 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_92 |= V_281 ;
F_8 ( V_92 , V_2 -> V_9 . V_13 + V_18 ) ;
F_119 ( & V_282 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_120 ( struct V_280 * V_72 )
{
struct V_1 * V_2 = F_118 ( V_72 ) ;
unsigned int V_92 ;
V_92 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_92 &= ~ V_281 ;
F_8 ( V_92 , V_2 -> V_9 . V_13 + V_18 ) ;
F_121 ( & V_282 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_280 * V_283 )
{
struct V_284 * V_285 = V_283 -> V_72 . V_286 ;
const struct V_287 * V_288 =
F_123 ( V_289 , & V_283 -> V_72 ) ;
int V_84 ;
if ( ! V_285 )
return 1 ;
V_84 = F_124 ( V_285 , L_19 ) ;
if ( V_84 < 0 ) {
F_39 ( & V_283 -> V_72 , L_20 , V_84 ) ;
return V_84 ;
}
V_2 -> V_9 . line = V_84 ;
if ( F_125 ( V_285 , L_21 , NULL ) )
V_2 -> V_189 = 1 ;
if ( F_125 ( V_285 , L_22 , NULL ) )
V_2 -> V_290 = 1 ;
if ( F_125 ( V_285 , L_23 , NULL ) )
V_2 -> V_245 = 1 ;
V_2 -> V_3 = V_288 -> V_33 ;
return 0 ;
}
static inline int F_122 ( struct V_1 * V_2 ,
struct V_280 * V_283 )
{
return 1 ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_280 * V_283 )
{
struct V_197 * V_198 = F_80 ( & V_283 -> V_72 ) ;
V_2 -> V_9 . line = V_283 -> V_291 ;
V_2 -> V_3 = (struct V_292 * ) V_283 -> V_293 -> V_294 ;
if ( ! V_198 )
return;
if ( V_198 -> V_34 & V_295 )
V_2 -> V_189 = 1 ;
if ( V_198 -> V_34 & V_296 )
V_2 -> V_290 = 1 ;
}
static int F_127 ( struct V_280 * V_283 )
{
struct V_1 * V_2 ;
void T_5 * V_297 ;
int V_84 = 0 ;
struct V_298 * V_299 ;
V_2 = F_128 ( & V_283 -> V_72 , sizeof( * V_2 ) , V_167 ) ;
if ( ! V_2 )
return - V_168 ;
V_84 = F_122 ( V_2 , V_283 ) ;
if ( V_84 > 0 )
F_126 ( V_2 , V_283 ) ;
else if ( V_84 < 0 )
return V_84 ;
V_299 = F_129 ( V_283 , V_300 , 0 ) ;
V_297 = F_130 ( & V_283 -> V_72 , V_299 ) ;
if ( F_131 ( V_297 ) )
return F_132 ( V_297 ) ;
V_2 -> V_9 . V_72 = & V_283 -> V_72 ;
V_2 -> V_9 . V_162 = V_299 -> V_301 ;
V_2 -> V_9 . V_13 = V_297 ;
V_2 -> V_9 . type = V_247 ,
V_2 -> V_9 . V_302 = V_253 ;
V_2 -> V_9 . V_90 = F_133 ( V_283 , 0 ) ;
V_2 -> V_303 = F_133 ( V_283 , 0 ) ;
V_2 -> V_304 = F_133 ( V_283 , 1 ) ;
V_2 -> V_305 = F_133 ( V_283 , 2 ) ;
V_2 -> V_9 . V_306 = 32 ;
V_2 -> V_9 . V_21 = & V_307 ;
V_2 -> V_9 . V_34 = V_308 ;
F_134 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_309 = F_13 ;
V_2 -> V_36 . V_33 = ( unsigned long ) V_2 ;
V_2 -> V_178 = F_135 ( & V_283 -> V_72 , L_24 ) ;
if ( F_131 ( V_2 -> V_178 ) ) {
V_84 = F_132 ( V_2 -> V_178 ) ;
F_39 ( & V_283 -> V_72 , L_25 , V_84 ) ;
return V_84 ;
}
V_2 -> V_177 = F_135 ( & V_283 -> V_72 , L_26 ) ;
if ( F_131 ( V_2 -> V_177 ) ) {
V_84 = F_132 ( V_2 -> V_177 ) ;
F_39 ( & V_283 -> V_72 , L_27 , V_84 ) ;
return V_84 ;
}
V_2 -> V_9 . V_236 = F_109 ( V_2 -> V_177 ) ;
if ( V_2 -> V_304 > 0 ) {
V_84 = F_136 ( & V_283 -> V_72 , V_2 -> V_303 , F_46 , 0 ,
F_137 ( & V_283 -> V_72 ) , V_2 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_136 ( & V_283 -> V_72 , V_2 -> V_304 , F_45 , 0 ,
F_137 ( & V_283 -> V_72 ) , V_2 ) ;
if ( V_84 )
return V_84 ;
if ( ! F_18 ( V_2 ) ) {
V_84 = F_136 ( & V_283 -> V_72 , V_2 -> V_305 ,
F_44 , 0 ,
F_137 ( & V_283 -> V_72 ) , V_2 ) ;
if ( V_84 )
return V_84 ;
}
} else {
V_84 = F_136 ( & V_283 -> V_72 , V_2 -> V_9 . V_90 , F_55 , 0 ,
F_137 ( & V_283 -> V_72 ) , V_2 ) ;
if ( V_84 )
return V_84 ;
}
V_266 [ V_2 -> V_9 . line ] = V_2 ;
F_138 ( V_283 , V_2 ) ;
return F_139 ( & V_282 , & V_2 -> V_9 ) ;
}
static int F_140 ( struct V_280 * V_283 )
{
struct V_1 * V_2 = F_118 ( V_283 ) ;
return F_141 ( & V_282 , & V_2 -> V_9 ) ;
}
static int T_3 F_142 ( void )
{
int V_84 = F_143 ( & V_282 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_144 ( & V_310 ) ;
if ( V_84 != 0 )
F_145 ( & V_282 ) ;
return V_84 ;
}
static void T_6 F_146 ( void )
{
F_147 ( & V_310 ) ;
F_145 ( & V_282 ) ;
}
