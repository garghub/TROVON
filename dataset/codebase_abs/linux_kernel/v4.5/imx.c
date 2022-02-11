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
static void F_9 ( struct V_1 * V_2 , unsigned long * V_15 )
{
* V_15 &= ~ V_19 ;
* V_15 |= V_20 ;
F_10 ( V_2 -> V_21 , V_2 -> V_9 . V_22 | V_23 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned long * V_15 )
{
* V_15 &= ~ ( V_19 | V_20 ) ;
F_10 ( V_2 -> V_21 , V_2 -> V_9 . V_22 & ~ V_23 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned long * V_15 )
{
* V_15 |= V_19 ;
}
static void F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_24 ;
if ( V_2 -> V_25 && V_2 -> V_26 )
return;
V_24 = F_6 ( V_9 -> V_13 + V_14 ) ;
F_8 ( V_24 & ~ V_27 , V_9 -> V_13 + V_14 ) ;
if ( V_9 -> V_28 . V_29 & V_30 &&
F_6 ( V_9 -> V_13 + V_31 ) & V_32 ) {
V_24 = F_6 ( V_9 -> V_13 + V_16 ) ;
if ( V_9 -> V_28 . V_29 & V_33 )
F_11 ( V_2 , & V_24 ) ;
else
F_9 ( V_2 , & V_24 ) ;
F_8 ( V_24 , V_9 -> V_13 + V_16 ) ;
V_24 = F_6 ( V_9 -> V_13 + V_34 ) ;
V_24 &= ~ V_35 ;
F_8 ( V_24 , V_9 -> V_13 + V_34 ) ;
}
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_24 ;
if ( V_2 -> V_25 && V_2 -> V_36 ) {
if ( V_2 -> V_9 . V_37 ) {
F_15 ( V_2 -> V_38 ) ;
V_2 -> V_36 = 0 ;
} else {
return;
}
}
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_24 & ~ V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_24 & ~ V_40 , V_2 -> V_9 . V_13 + V_14 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_17 ( & V_2 -> V_41 , V_42 ) ;
F_18 ( V_2 -> V_21 ) ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_9 . V_45 -> V_44 ;
unsigned long V_24 ;
if ( V_2 -> V_9 . V_46 ) {
F_8 ( V_2 -> V_9 . V_46 , V_2 -> V_9 . V_13 + V_47 ) ;
V_2 -> V_9 . V_48 . V_49 ++ ;
V_2 -> V_9 . V_46 = 0 ;
return;
}
if ( F_20 ( V_44 ) || F_21 ( & V_2 -> V_9 ) ) {
F_13 ( & V_2 -> V_9 ) ;
return;
}
if ( V_2 -> V_25 ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ V_27 ;
if ( V_2 -> V_26 ) {
V_24 |= V_50 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
} else {
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
F_22 ( V_2 ) ;
}
}
while ( ! F_20 ( V_44 ) &&
! ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_51 ) ) {
F_8 ( V_44 -> V_52 [ V_44 -> V_53 ] , V_2 -> V_9 . V_13 + V_47 ) ;
V_44 -> V_53 = ( V_44 -> V_53 + 1 ) & ( V_54 - 1 ) ;
V_2 -> V_9 . V_48 . V_49 ++ ;
}
if ( F_23 ( V_44 ) < V_55 )
F_24 ( & V_2 -> V_9 ) ;
if ( F_20 ( V_44 ) )
F_13 ( & V_2 -> V_9 ) ;
}
static void F_25 ( void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_57 * V_58 = & V_2 -> V_59 [ 0 ] ;
struct V_43 * V_44 = & V_2 -> V_9 . V_45 -> V_44 ;
unsigned long V_29 ;
unsigned long V_24 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_27 ( V_2 -> V_9 . V_61 , V_58 , V_2 -> V_62 , V_63 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ V_50 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_44 -> V_53 = ( V_44 -> V_53 + V_2 -> V_64 ) & ( V_54 - 1 ) ;
V_2 -> V_9 . V_48 . V_49 += V_2 -> V_64 ;
F_28 ( V_2 -> V_9 . V_61 , L_1 ) ;
V_2 -> V_26 = 0 ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
if ( F_23 ( V_44 ) < V_55 )
F_24 ( & V_2 -> V_9 ) ;
if ( F_30 ( & V_2 -> V_65 ) ) {
F_31 ( & V_2 -> V_65 ) ;
F_28 ( V_2 -> V_9 . V_61 , L_2 , V_66 ) ;
return;
}
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
if ( ! F_20 ( V_44 ) && ! F_21 ( & V_2 -> V_9 ) )
F_22 ( V_2 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_9 . V_45 -> V_44 ;
struct V_57 * V_58 = V_2 -> V_59 ;
struct V_67 * V_68 ;
struct V_69 * V_70 = V_2 -> V_71 ;
struct V_72 * V_61 = V_2 -> V_9 . V_61 ;
unsigned long V_24 ;
int V_73 ;
if ( V_2 -> V_26 )
return;
V_2 -> V_64 = F_23 ( V_44 ) ;
if ( V_44 -> V_53 < V_44 -> V_74 ) {
V_2 -> V_62 = 1 ;
F_32 ( V_58 , V_44 -> V_52 + V_44 -> V_53 , V_2 -> V_64 ) ;
} else {
V_2 -> V_62 = 2 ;
F_33 ( V_58 , 2 ) ;
F_34 ( V_58 , V_44 -> V_52 + V_44 -> V_53 ,
V_54 - V_44 -> V_53 ) ;
F_34 ( V_58 + 1 , V_44 -> V_52 , V_44 -> V_74 ) ;
}
V_73 = F_35 ( V_61 , V_58 , V_2 -> V_62 , V_63 ) ;
if ( V_73 == 0 ) {
F_36 ( V_61 , L_3 ) ;
return;
}
V_68 = F_37 ( V_70 , V_58 , V_2 -> V_62 ,
V_75 , V_76 ) ;
if ( ! V_68 ) {
F_27 ( V_61 , V_58 , V_2 -> V_62 ,
V_63 ) ;
F_36 ( V_61 , L_4 ) ;
return;
}
V_68 -> V_77 = F_25 ;
V_68 -> V_78 = V_2 ;
F_28 ( V_61 , L_5 ,
F_23 ( V_44 ) ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 |= V_50 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_26 = 1 ;
F_38 ( V_68 ) ;
F_39 ( V_70 ) ;
return;
}
static void F_40 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_24 ;
if ( V_9 -> V_28 . V_29 & V_30 ) {
V_24 = F_6 ( V_9 -> V_13 + V_16 ) ;
if ( V_9 -> V_28 . V_29 & V_79 )
F_11 ( V_2 , & V_24 ) ;
else
F_9 ( V_2 , & V_24 ) ;
F_8 ( V_24 , V_9 -> V_13 + V_16 ) ;
V_24 = F_6 ( V_9 -> V_13 + V_34 ) ;
V_24 |= V_35 ;
F_8 ( V_24 , V_9 -> V_13 + V_34 ) ;
}
if ( ! V_2 -> V_25 ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_24 | V_27 , V_2 -> V_9 . V_13 + V_14 ) ;
}
if ( V_2 -> V_25 ) {
if ( V_2 -> V_9 . V_46 ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ V_50 ;
V_24 |= V_27 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
return;
}
if ( ! F_20 ( & V_9 -> V_45 -> V_44 ) &&
! F_21 ( V_9 ) )
F_22 ( V_2 ) ;
return;
}
}
static T_1 F_41 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
unsigned int V_82 ;
unsigned long V_29 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_8 ( V_83 , V_2 -> V_9 . V_13 + V_84 ) ;
V_82 = F_6 ( V_2 -> V_9 . V_13 + V_84 ) & V_85 ;
F_42 ( & V_2 -> V_9 , ! ! V_82 ) ;
F_43 ( & V_2 -> V_9 . V_45 -> V_9 . V_86 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
return V_87 ;
}
static T_1 F_44 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
unsigned long V_29 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_19 ( V_2 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
return V_87 ;
}
static T_1 F_45 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
unsigned int V_88 , V_89 , V_90 = 0 ;
struct V_91 * V_9 = & V_2 -> V_9 . V_45 -> V_9 ;
unsigned long V_29 , V_24 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
while ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_92 ) {
V_89 = V_93 ;
V_2 -> V_9 . V_48 . V_88 ++ ;
V_88 = F_6 ( V_2 -> V_9 . V_13 + V_94 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_31 ) ;
if ( V_24 & V_95 ) {
F_8 ( V_95 , V_2 -> V_9 . V_13 + V_31 ) ;
if ( F_46 ( & V_2 -> V_9 ) )
continue;
}
if ( F_47 ( & V_2 -> V_9 , ( unsigned char ) V_88 ) )
continue;
if ( F_48 ( V_88 & V_96 ) ) {
if ( V_88 & V_97 )
V_2 -> V_9 . V_48 . V_98 ++ ;
else if ( V_88 & V_99 )
V_2 -> V_9 . V_48 . V_100 ++ ;
else if ( V_88 & V_101 )
V_2 -> V_9 . V_48 . V_102 ++ ;
if ( V_88 & V_103 )
V_2 -> V_9 . V_48 . V_104 ++ ;
if ( V_88 & V_2 -> V_9 . V_105 ) {
if ( ++ V_90 > 100 )
goto V_106;
continue;
}
V_88 &= ( V_2 -> V_9 . V_107 | 0xFF ) ;
if ( V_88 & V_97 )
V_89 = V_108 ;
else if ( V_88 & V_99 )
V_89 = V_109 ;
else if ( V_88 & V_101 )
V_89 = V_110 ;
if ( V_88 & V_103 )
V_89 = V_111 ;
#ifdef F_49
V_2 -> V_9 . V_112 = 0 ;
#endif
}
if ( V_2 -> V_9 . V_105 & V_113 )
goto V_106;
if ( F_50 ( V_9 , V_88 , V_89 ) == 0 )
V_2 -> V_9 . V_48 . V_114 ++ ;
}
V_106:
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_51 ( V_9 ) ;
return V_87 ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
unsigned long V_29 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_31 ) ;
if ( ( V_24 & V_92 ) && ! V_2 -> V_36 ) {
V_2 -> V_36 = 1 ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ ( V_40 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ ( V_115 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_53 ( V_2 ) ;
}
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static T_1 F_54 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
unsigned int V_116 ;
unsigned int V_117 ;
V_116 = F_6 ( V_2 -> V_9 . V_13 + V_84 ) ;
V_117 = F_6 ( V_2 -> V_9 . V_13 + V_31 ) ;
if ( V_116 & ( V_118 | V_119 ) ) {
if ( V_2 -> V_25 )
F_52 ( V_2 ) ;
else
F_45 ( V_80 , V_81 ) ;
}
if ( ( V_116 & V_120 &&
F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_27 ) ||
( V_117 & V_32 &&
F_6 ( V_2 -> V_9 . V_13 + V_34 ) & V_35 ) )
F_44 ( V_80 , V_81 ) ;
if ( V_116 & V_83 )
F_41 ( V_80 , V_81 ) ;
if ( V_116 & V_121 )
F_8 ( V_121 , V_2 -> V_9 . V_13 + V_84 ) ;
if ( V_117 & V_122 ) {
V_2 -> V_9 . V_48 . V_104 ++ ;
F_8 ( V_122 , V_2 -> V_9 . V_13 + V_31 ) ;
}
return V_87 ;
}
static unsigned int F_55 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_73 ;
V_73 = ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_32 ) ? V_123 : 0 ;
if ( V_2 -> V_25 && V_2 -> V_26 )
V_73 = 0 ;
return V_73 ;
}
static unsigned int F_56 ( struct V_1 * V_2 )
{
unsigned int V_124 = V_125 ;
unsigned V_126 = F_6 ( V_2 -> V_9 . V_13 + V_84 ) ;
if ( V_126 & V_85 )
V_124 |= V_127 ;
if ( ! ( V_126 & V_128 ) )
V_124 |= V_129 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_130 )
V_124 |= V_131 ;
return V_124 ;
}
static unsigned int F_57 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_73 = F_56 ( V_2 ) ;
F_58 ( V_2 -> V_21 , & V_73 ) ;
return V_73 ;
}
static void F_59 ( struct V_8 * V_9 , unsigned int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_24 ;
if ( ! ( V_9 -> V_28 . V_29 & V_30 ) ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ ( V_20 | V_19 ) ;
if ( V_22 & V_23 )
V_24 |= V_20 | V_19 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
}
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) & ~ V_132 ;
if ( ! ( V_22 & V_133 ) )
V_24 |= V_132 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_18 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & ~ V_134 ;
if ( V_22 & V_135 )
V_24 |= V_134 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) ;
F_10 ( V_2 -> V_21 , V_22 ) ;
}
static void F_60 ( struct V_8 * V_9 , int V_136 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 , V_24 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) & ~ V_137 ;
if ( V_136 != 0 )
V_24 |= V_137 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned int V_138 , V_139 ;
V_138 = F_56 ( V_2 ) ;
V_139 = V_138 ^ V_2 -> V_140 ;
if ( V_139 == 0 )
return;
V_2 -> V_140 = V_138 ;
if ( V_139 & V_131 )
V_2 -> V_9 . V_48 . V_141 ++ ;
if ( V_139 & V_125 )
V_2 -> V_9 . V_48 . V_142 ++ ;
if ( V_139 & V_129 )
F_62 ( & V_2 -> V_9 , V_138 & V_129 ) ;
if ( V_139 & V_127 )
F_42 ( & V_2 -> V_9 , V_138 & V_127 ) ;
F_43 ( & V_2 -> V_9 . V_45 -> V_9 . V_86 ) ;
}
static void F_63 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_29 ;
if ( V_2 -> V_9 . V_45 ) {
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_61 ( V_2 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_17 ( & V_2 -> V_41 , V_42 + V_143 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
unsigned long V_29 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 |= V_40 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= V_115 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
V_2 -> V_36 = 0 ;
if ( F_30 ( & V_2 -> V_65 ) )
F_31 ( & V_2 -> V_65 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static void F_65 ( void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_69 * V_70 = V_2 -> V_38 ;
struct V_57 * V_58 = & V_2 -> V_144 ;
struct V_91 * V_9 = & V_2 -> V_9 . V_45 -> V_9 ;
struct V_145 V_45 ;
enum V_146 V_138 ;
unsigned int V_147 ;
F_27 ( V_2 -> V_9 . V_61 , V_58 , 1 , V_148 ) ;
V_138 = F_66 ( V_70 , ( V_149 ) 0 , & V_45 ) ;
V_147 = V_150 - V_45 . V_151 ;
F_28 ( V_2 -> V_9 . V_61 , L_6 , V_147 ) ;
if ( V_147 ) {
if ( ! ( V_2 -> V_9 . V_105 & V_113 ) ) {
int V_152 = F_67 ( V_9 , V_2 -> V_153 ,
V_147 ) ;
if ( V_152 != V_147 )
V_2 -> V_9 . V_48 . V_114 ++ ;
}
F_51 ( V_9 ) ;
V_2 -> V_9 . V_48 . V_88 += V_147 ;
}
if ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_92 )
F_53 ( V_2 ) ;
else
F_64 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = & V_2 -> V_144 ;
struct V_69 * V_70 = V_2 -> V_38 ;
struct V_72 * V_61 = V_2 -> V_9 . V_61 ;
struct V_67 * V_68 ;
int V_73 ;
F_32 ( V_58 , V_2 -> V_153 , V_150 ) ;
V_73 = F_35 ( V_61 , V_58 , 1 , V_148 ) ;
if ( V_73 == 0 ) {
F_36 ( V_61 , L_7 ) ;
return - V_154 ;
}
V_68 = F_37 ( V_70 , V_58 , 1 , V_155 ,
V_76 ) ;
if ( ! V_68 ) {
F_27 ( V_61 , V_58 , 1 , V_148 ) ;
F_36 ( V_61 , L_8 ) ;
return - V_154 ;
}
V_68 -> V_77 = F_65 ;
V_68 -> V_78 = V_2 ;
F_28 ( V_61 , L_9 ) ;
F_38 ( V_68 ) ;
F_39 ( V_70 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 ,
unsigned char V_156 , unsigned char V_157 )
{
unsigned int V_82 ;
V_82 = F_6 ( V_2 -> V_9 . V_13 + V_158 ) & ( V_159 | V_160 ) ;
V_82 |= V_156 << V_161 | V_157 ;
F_8 ( V_82 , V_2 -> V_9 . V_13 + V_158 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 ) {
F_70 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
F_71 ( V_2 -> V_153 ) ;
V_2 -> V_153 = NULL ;
}
if ( V_2 -> V_71 ) {
F_70 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
}
V_2 -> V_162 = 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_163 V_164 = {} ;
struct V_72 * V_61 = V_2 -> V_9 . V_61 ;
int V_73 ;
V_2 -> V_38 = F_73 ( V_61 , L_10 ) ;
if ( ! V_2 -> V_38 ) {
F_28 ( V_61 , L_11 ) ;
V_73 = - V_154 ;
goto V_165;
}
V_164 . V_166 = V_155 ;
V_164 . V_167 = V_2 -> V_9 . V_168 + V_94 ;
V_164 . V_169 = V_170 ;
V_164 . V_171 = V_172 - 1 ;
V_73 = F_74 ( V_2 -> V_38 , & V_164 ) ;
if ( V_73 ) {
F_36 ( V_61 , L_12 ) ;
goto V_165;
}
V_2 -> V_153 = F_75 ( V_173 , V_174 ) ;
if ( ! V_2 -> V_153 ) {
V_73 = - V_175 ;
goto V_165;
}
V_2 -> V_71 = F_73 ( V_61 , L_13 ) ;
if ( ! V_2 -> V_71 ) {
F_36 ( V_61 , L_14 ) ;
V_73 = - V_154 ;
goto V_165;
}
V_164 . V_166 = V_75 ;
V_164 . V_176 = V_2 -> V_9 . V_168 + V_47 ;
V_164 . V_177 = V_170 ;
V_164 . V_178 = V_179 ;
V_73 = F_74 ( V_2 -> V_71 , & V_164 ) ;
if ( V_73 ) {
F_36 ( V_61 , L_15 ) ;
goto V_165;
}
V_2 -> V_162 = 1 ;
return 0 ;
V_165:
F_69 ( V_2 ) ;
return V_73 ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
F_77 ( & V_2 -> V_65 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 |= V_180 | V_50 | V_181 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= V_115 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_68 ( V_2 , V_179 , V_172 ) ;
V_2 -> V_25 = 1 ;
}
static void F_78 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ ( V_180 | V_50 | V_181 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ ( V_19 | V_20 | V_115 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_68 ( V_2 , V_182 , V_183 ) ;
V_2 -> V_25 = 0 ;
}
static int F_79 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_184 , V_185 ;
unsigned long V_29 , V_24 ;
V_184 = F_80 ( V_2 -> V_186 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_80 ( V_2 -> V_187 ) ;
if ( V_184 ) {
F_81 ( V_2 -> V_186 ) ;
return V_184 ;
}
F_68 ( V_2 , V_182 , V_183 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_34 ) ;
V_24 &= ~ ( V_188 << V_189 ) ;
V_24 |= V_190 << V_189 ;
F_8 ( V_24 & ~ V_191 , V_2 -> V_9 . V_13 + V_34 ) ;
if ( F_4 ( V_2 ) && ! F_82 ( V_9 ) &&
! V_2 -> V_162 )
F_72 ( V_2 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_185 = 100 ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ V_192 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_192 ) && ( -- V_185 > 0 ) )
F_83 ( 1 ) ;
F_8 ( V_83 , V_2 -> V_9 . V_13 + V_84 ) ;
F_8 ( V_122 , V_2 -> V_9 . V_13 + V_31 ) ;
if ( V_2 -> V_162 && ! V_2 -> V_25 )
F_76 ( V_2 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 |= V_40 | V_193 | V_194 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_34 ) ;
V_24 |= V_195 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_34 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= ( V_39 | V_196 ) ;
if ( ! V_2 -> V_197 )
V_24 |= V_198 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( ! F_2 ( V_2 ) ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_24 |= V_199 | V_200 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_18 ) ;
}
F_16 ( & V_2 -> V_9 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
return 0 ;
}
static void F_84 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_24 ;
unsigned long V_29 ;
if ( V_2 -> V_25 ) {
int V_73 ;
V_73 = F_85 ( V_2 -> V_65 ,
! V_2 -> V_36 && ! V_2 -> V_26 ) ;
if ( V_73 != 0 ) {
V_2 -> V_36 = 0 ;
V_2 -> V_26 = 0 ;
F_15 ( V_2 -> V_71 ) ;
F_15 ( V_2 -> V_38 ) ;
}
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_13 ( V_9 ) ;
F_14 ( V_9 ) ;
F_78 ( V_2 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_69 ( V_2 ) ;
}
F_86 ( V_2 -> V_21 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ ( V_196 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_87 ( & V_2 -> V_41 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ ( V_27 | V_40 | V_193 | V_194 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_81 ( V_2 -> V_186 ) ;
F_81 ( V_2 -> V_187 ) ;
}
static void F_88 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
struct V_57 * V_58 = & V_2 -> V_59 [ 0 ] ;
unsigned long V_24 ;
int V_185 = 100 , V_201 , V_202 , V_203 ;
if ( ! V_2 -> V_71 )
return;
V_2 -> V_64 = 0 ;
F_15 ( V_2 -> V_71 ) ;
if ( V_2 -> V_26 ) {
F_27 ( V_2 -> V_9 . V_61 , V_58 , V_2 -> V_62 ,
V_63 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ V_50 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_26 = false ;
}
V_201 = F_6 ( V_2 -> V_9 . V_13 + V_204 ) ;
V_202 = F_6 ( V_2 -> V_9 . V_13 + V_205 ) ;
V_203 = F_6 ( V_2 -> V_9 . V_13 + V_206 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ V_192 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_192 ) && ( -- V_185 > 0 ) )
F_83 ( 1 ) ;
F_8 ( V_201 , V_2 -> V_9 . V_13 + V_204 ) ;
F_8 ( V_202 , V_2 -> V_9 . V_13 + V_205 ) ;
F_8 ( V_203 , V_2 -> V_9 . V_13 + V_206 ) ;
}
static void
F_89 ( struct V_8 * V_9 , struct V_207 * V_208 ,
struct V_207 * V_209 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
unsigned long V_15 , V_210 , V_211 ;
unsigned int V_212 , V_213 ;
unsigned int V_214 = V_209 ? V_209 -> V_215 & V_216 : V_217 ;
unsigned long div , V_218 ;
unsigned long V_219 , V_220 ;
T_2 V_221 ;
while ( ( V_208 -> V_215 & V_216 ) != V_222 &&
( V_208 -> V_215 & V_216 ) != V_217 ) {
V_208 -> V_215 &= ~ V_216 ;
V_208 -> V_215 |= V_214 ;
V_214 = V_217 ;
}
if ( ( V_208 -> V_215 & V_216 ) == V_217 )
V_15 = V_223 | V_192 | V_198 ;
else
V_15 = V_192 | V_198 ;
if ( V_208 -> V_215 & V_224 ) {
if ( V_2 -> V_197 ) {
V_15 &= ~ V_198 ;
if ( V_9 -> V_28 . V_29 & V_30 ) {
if ( V_9 -> V_28 . V_29 &
V_33 )
F_11 ( V_2 , & V_15 ) ;
else
F_9 ( V_2 , & V_15 ) ;
} else {
F_12 ( V_2 , & V_15 ) ;
}
} else {
V_208 -> V_215 &= ~ V_224 ;
}
} else if ( V_9 -> V_28 . V_29 & V_30 ) {
if ( V_9 -> V_28 . V_29 & V_33 )
F_11 ( V_2 , & V_15 ) ;
else
F_9 ( V_2 , & V_15 ) ;
}
if ( V_208 -> V_215 & V_225 )
V_15 |= V_226 ;
if ( V_208 -> V_215 & V_227 ) {
V_15 |= V_228 ;
if ( V_208 -> V_215 & V_229 )
V_15 |= V_230 ;
}
F_87 ( & V_2 -> V_41 ) ;
V_212 = F_90 ( V_9 , V_208 , V_209 , 50 , V_9 -> V_231 / 16 ) ;
V_213 = F_91 ( V_9 , V_212 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_2 -> V_9 . V_107 = 0 ;
if ( V_208 -> V_232 & V_233 )
V_2 -> V_9 . V_107 |= ( V_101 | V_99 ) ;
if ( V_208 -> V_232 & ( V_234 | V_235 ) )
V_2 -> V_9 . V_107 |= V_97 ;
V_2 -> V_9 . V_105 = 0 ;
if ( V_208 -> V_232 & V_236 )
V_2 -> V_9 . V_105 |= V_99 | V_101 ;
if ( V_208 -> V_232 & V_237 ) {
V_2 -> V_9 . V_105 |= V_97 ;
if ( V_208 -> V_232 & V_236 )
V_2 -> V_9 . V_105 |= V_103 ;
}
if ( ( V_208 -> V_215 & V_238 ) == 0 )
V_2 -> V_9 . V_105 |= V_113 ;
F_92 ( V_9 , V_208 -> V_215 , V_212 ) ;
V_210 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_210 & ~ ( V_27 | V_40 | V_193 ) ,
V_2 -> V_9 . V_13 + V_14 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_32 ) )
F_93 () ;
V_211 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_211 & ~ ( V_196 | V_39 ) ,
V_2 -> V_9 . V_13 + V_16 ) ;
V_211 &= ( V_196 | V_39 | V_115 ) ;
div = V_2 -> V_9 . V_231 / ( V_212 * 16 ) ;
if ( V_212 == 38400 && V_213 != div )
V_212 = V_2 -> V_9 . V_231 / ( V_213 * 16 ) ;
div = V_2 -> V_9 . V_231 / ( V_212 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
F_94 ( 16 * div * V_212 , V_2 -> V_9 . V_231 ,
1 << 16 , 1 << 16 , & V_219 , & V_220 ) ;
V_221 = V_2 -> V_9 . V_231 ;
V_221 *= V_219 ;
F_95 ( V_221 , V_220 * 16 * div ) ;
F_96 ( V_208 ,
( V_239 ) V_221 , ( V_239 ) V_221 ) ;
V_219 -= 1 ;
V_220 -= 1 ;
V_218 = F_6 ( V_2 -> V_9 . V_13 + V_158 ) ;
V_218 = ( V_218 & ( ~ V_159 ) ) | F_97 ( div ) ;
if ( V_2 -> V_240 )
V_218 |= V_160 ;
F_8 ( V_218 , V_2 -> V_9 . V_13 + V_158 ) ;
F_8 ( V_219 , V_2 -> V_9 . V_13 + V_204 ) ;
F_8 ( V_220 , V_2 -> V_9 . V_13 + V_205 ) ;
if ( ! F_2 ( V_2 ) )
F_8 ( V_2 -> V_9 . V_231 / div / 1000 ,
V_2 -> V_9 . V_13 + V_241 ) ;
F_8 ( V_210 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_15 | V_211 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( F_98 ( & V_2 -> V_9 , V_208 -> V_215 ) )
F_16 ( & V_2 -> V_9 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static const char * F_99 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_242 ? L_16 : NULL ;
}
static void F_100 ( struct V_8 * V_9 , int V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_29 & V_243 )
V_2 -> V_9 . type = V_242 ;
}
static int
F_101 ( struct V_8 * V_9 , struct V_244 * V_245 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_73 = 0 ;
if ( V_245 -> type != V_246 && V_245 -> type != V_242 )
V_73 = - V_154 ;
if ( V_2 -> V_9 . V_80 != V_245 -> V_80 )
V_73 = - V_154 ;
if ( V_245 -> V_247 != V_248 )
V_73 = - V_154 ;
if ( V_2 -> V_9 . V_231 / 16 != V_245 -> V_249 )
V_73 = - V_154 ;
if ( V_2 -> V_9 . V_168 != ( unsigned long ) V_245 -> V_250 )
V_73 = - V_154 ;
if ( V_2 -> V_9 . V_251 != V_245 -> V_9 )
V_73 = - V_154 ;
if ( V_245 -> V_252 != 0 )
V_73 = - V_154 ;
return V_73 ;
}
static int F_102 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
unsigned long V_24 ;
int V_184 ;
V_184 = F_80 ( V_2 -> V_187 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_80 ( V_2 -> V_186 ) ;
if ( V_184 )
F_81 ( V_2 -> V_187 ) ;
F_68 ( V_2 , V_182 , V_183 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( F_2 ( V_2 ) )
V_24 |= V_253 ;
V_24 |= V_194 | V_40 ;
V_24 &= ~ ( V_27 | V_193 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= V_39 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
return 0 ;
}
static int F_103 ( struct V_8 * V_9 )
{
if ( ! ( F_104 ( V_9 -> V_13 + V_31 ) & V_92 ) )
return V_254 ;
return F_104 ( V_9 -> V_13 + V_94 ) & V_255 ;
}
static void F_105 ( struct V_8 * V_9 , unsigned char V_256 )
{
unsigned int V_138 ;
do {
V_138 = F_104 ( V_9 -> V_13 + V_84 ) ;
} while ( ~ V_138 & V_120 );
F_106 ( V_256 , V_9 -> V_13 + V_47 ) ;
do {
V_138 = F_104 ( V_9 -> V_13 + V_31 ) ;
} while ( ~ V_138 & V_32 );
}
static int F_107 ( struct V_8 * V_9 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
V_258 -> V_259 = 0 ;
V_258 -> V_260 = 0 ;
V_258 -> V_29 |= V_261 ;
if ( ! V_2 -> V_197 )
V_258 -> V_29 &= ~ V_30 ;
if ( V_258 -> V_29 & V_30 ) {
unsigned long V_24 ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
if ( V_258 -> V_29 & V_33 )
F_11 ( V_2 , & V_24 ) ;
else
F_9 ( V_2 , & V_24 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
}
V_9 -> V_28 = * V_258 ;
return 0 ;
}
static void F_108 ( struct V_8 * V_9 , int V_262 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_51 )
F_93 () ;
F_8 ( V_262 , V_2 -> V_9 . V_13 + V_47 ) ;
}
static void
F_109 ( struct V_263 * V_264 , const char * V_265 , unsigned int V_147 )
{
struct V_1 * V_2 = V_266 [ V_264 -> V_267 ] ;
struct V_10 V_268 ;
unsigned int V_12 ;
unsigned long V_29 = 0 ;
int V_269 = 1 ;
int V_184 ;
V_184 = F_110 ( V_2 -> V_186 ) ;
if ( V_184 )
return;
V_184 = F_110 ( V_2 -> V_187 ) ;
if ( V_184 ) {
F_111 ( V_2 -> V_186 ) ;
return;
}
if ( V_2 -> V_9 . V_112 )
V_269 = 0 ;
else if ( V_270 )
V_269 = F_112 ( & V_2 -> V_9 . V_60 , V_29 ) ;
else
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_5 ( & V_2 -> V_9 , & V_268 ) ;
V_12 = V_268 . V_12 ;
if ( F_2 ( V_2 ) )
V_12 |= V_253 ;
V_12 |= V_194 ;
V_12 &= ~ ( V_27 | V_40 | V_193 ) ;
F_8 ( V_12 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_268 . V_15 | V_196 , V_2 -> V_9 . V_13 + V_16 ) ;
F_113 ( & V_2 -> V_9 , V_265 , V_147 , F_108 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_32 ) ) ;
F_7 ( & V_2 -> V_9 , & V_268 ) ;
if ( V_269 )
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_111 ( V_2 -> V_187 ) ;
F_111 ( V_2 -> V_186 ) ;
}
static void T_3
F_114 ( struct V_1 * V_2 , int * V_212 ,
int * V_100 , int * V_271 )
{
if ( F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_194 ) {
unsigned int V_15 , V_201 , V_202 , V_231 ;
unsigned int V_272 ;
unsigned int V_273 ;
V_15 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
* V_100 = 'n' ;
if ( V_15 & V_228 ) {
if ( V_15 & V_230 )
* V_100 = 'o' ;
else
* V_100 = 'e' ;
}
if ( V_15 & V_223 )
* V_271 = 8 ;
else
* V_271 = 7 ;
V_201 = F_6 ( V_2 -> V_9 . V_13 + V_204 ) & 0xffff ;
V_202 = F_6 ( V_2 -> V_9 . V_13 + V_205 ) & 0xffff ;
V_273 = ( F_6 ( V_2 -> V_9 . V_13 + V_158 ) & V_159 ) >> 7 ;
if ( V_273 == 6 )
V_273 = 7 ;
else
V_273 = 6 - V_273 ;
V_231 = F_115 ( V_2 -> V_186 ) ;
V_231 /= V_273 ;
{
unsigned int V_274 = V_201 + 1 ;
unsigned int div = 16 * ( V_202 + 1 ) ;
unsigned int V_275 = V_231 % div ;
V_272 = ( V_231 / div ) * V_274 ;
V_272 += ( V_275 * V_274 + div / 2 ) / div ;
* V_212 = ( V_272 + 50 ) / 100 * 100 ;
}
if ( * V_212 != V_272 )
F_116 ( L_17 ,
V_272 , * V_212 ) ;
}
}
static int T_3
F_117 ( struct V_263 * V_264 , char * V_276 )
{
struct V_1 * V_2 ;
int V_212 = 9600 ;
int V_271 = 8 ;
int V_100 = 'n' ;
int V_277 = 'n' ;
int V_184 ;
if ( V_264 -> V_267 == - 1 || V_264 -> V_267 >= F_118 ( V_266 ) )
V_264 -> V_267 = 0 ;
V_2 = V_266 [ V_264 -> V_267 ] ;
if ( V_2 == NULL )
return - V_278 ;
V_184 = F_80 ( V_2 -> V_187 ) ;
if ( V_184 )
goto V_279;
if ( V_276 )
F_119 ( V_276 , & V_212 , & V_100 , & V_271 , & V_277 ) ;
else
F_114 ( V_2 , & V_212 , & V_100 , & V_271 ) ;
F_68 ( V_2 , V_182 , V_183 ) ;
V_184 = F_120 ( & V_2 -> V_9 , V_264 , V_212 , V_100 , V_271 , V_277 ) ;
F_111 ( V_2 -> V_187 ) ;
if ( V_184 ) {
F_121 ( V_2 -> V_187 ) ;
goto V_279;
}
V_184 = F_122 ( V_2 -> V_186 ) ;
if ( V_184 )
F_81 ( V_2 -> V_187 ) ;
V_279:
return V_184 ;
}
static void F_123 ( struct V_8 * V_9 , int V_262 )
{
while ( F_104 ( V_9 -> V_13 + V_206 ) & V_51 )
F_124 () ;
F_106 ( V_262 , V_9 -> V_13 + V_47 ) ;
}
static void F_125 ( struct V_263 * V_280 , const char * V_265 ,
unsigned V_147 )
{
struct V_281 * V_61 = V_280 -> V_56 ;
F_113 ( & V_61 -> V_9 , V_265 , V_147 , F_123 ) ;
}
static int T_3
F_126 ( struct V_281 * V_61 , const char * V_282 )
{
if ( ! V_61 -> V_9 . V_13 )
return - V_278 ;
V_61 -> V_280 -> V_283 = F_125 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_286 * V_287 = V_285 -> V_61 . V_288 ;
int V_73 ;
V_2 -> V_3 = F_128 ( & V_285 -> V_61 ) ;
if ( ! V_2 -> V_3 )
return 1 ;
V_73 = F_129 ( V_287 , L_18 ) ;
if ( V_73 < 0 ) {
F_36 ( & V_285 -> V_61 , L_19 , V_73 ) ;
return V_73 ;
}
V_2 -> V_9 . line = V_73 ;
if ( F_130 ( V_287 , L_20 , NULL ) )
V_2 -> V_197 = 1 ;
if ( F_130 ( V_287 , L_21 , NULL ) )
V_2 -> V_240 = 1 ;
return 0 ;
}
static inline int F_127 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
return 1 ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_289 * V_290 = F_132 ( & V_285 -> V_61 ) ;
V_2 -> V_9 . line = V_285 -> V_291 ;
V_2 -> V_3 = (struct V_292 * ) V_285 -> V_293 -> V_294 ;
if ( ! V_290 )
return;
if ( V_290 -> V_29 & V_295 )
V_2 -> V_197 = 1 ;
}
static int F_133 ( struct V_284 * V_285 )
{
struct V_1 * V_2 ;
void T_4 * V_296 ;
int V_73 = 0 , V_297 ;
struct V_298 * V_299 ;
int V_300 , V_301 , V_302 ;
V_2 = F_134 ( & V_285 -> V_61 , sizeof( * V_2 ) , V_174 ) ;
if ( ! V_2 )
return - V_175 ;
V_73 = F_127 ( V_2 , V_285 ) ;
if ( V_73 > 0 )
F_131 ( V_2 , V_285 ) ;
else if ( V_73 < 0 )
return V_73 ;
V_299 = F_135 ( V_285 , V_303 , 0 ) ;
V_296 = F_136 ( & V_285 -> V_61 , V_299 ) ;
if ( F_137 ( V_296 ) )
return F_138 ( V_296 ) ;
V_301 = F_139 ( V_285 , 0 ) ;
V_300 = F_139 ( V_285 , 1 ) ;
V_302 = F_139 ( V_285 , 2 ) ;
V_2 -> V_9 . V_61 = & V_285 -> V_61 ;
V_2 -> V_9 . V_168 = V_299 -> V_304 ;
V_2 -> V_9 . V_13 = V_296 ;
V_2 -> V_9 . type = V_242 ,
V_2 -> V_9 . V_305 = V_248 ;
V_2 -> V_9 . V_80 = V_301 ;
V_2 -> V_9 . V_306 = 32 ;
V_2 -> V_9 . V_307 = & V_308 ;
V_2 -> V_9 . V_309 = F_107 ;
V_2 -> V_9 . V_28 . V_29 =
V_79 | V_261 ;
V_2 -> V_9 . V_29 = V_310 ;
F_140 ( & V_2 -> V_41 ) ;
V_2 -> V_41 . V_311 = F_63 ;
V_2 -> V_41 . V_56 = ( unsigned long ) V_2 ;
V_2 -> V_21 = F_141 ( & V_2 -> V_9 , 0 ) ;
if ( F_137 ( V_2 -> V_21 ) )
return F_138 ( V_2 -> V_21 ) ;
V_2 -> V_187 = F_142 ( & V_285 -> V_61 , L_22 ) ;
if ( F_137 ( V_2 -> V_187 ) ) {
V_73 = F_138 ( V_2 -> V_187 ) ;
F_36 ( & V_285 -> V_61 , L_23 , V_73 ) ;
return V_73 ;
}
V_2 -> V_186 = F_142 ( & V_285 -> V_61 , L_24 ) ;
if ( F_137 ( V_2 -> V_186 ) ) {
V_73 = F_138 ( V_2 -> V_186 ) ;
F_36 ( & V_285 -> V_61 , L_25 , V_73 ) ;
return V_73 ;
}
V_2 -> V_9 . V_231 = F_115 ( V_2 -> V_186 ) ;
V_73 = F_80 ( V_2 -> V_187 ) ;
if ( V_73 )
return V_73 ;
V_297 = F_104 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_297 &= ~ ( V_312 | V_313 | V_314 | V_40 |
V_27 | V_193 ) ;
F_106 ( V_297 , V_2 -> V_9 . V_13 + V_14 ) ;
F_81 ( V_2 -> V_187 ) ;
if ( V_300 > 0 ) {
V_73 = F_143 ( & V_285 -> V_61 , V_301 , F_45 , 0 ,
F_144 ( & V_285 -> V_61 ) , V_2 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_143 ( & V_285 -> V_61 , V_300 , F_44 , 0 ,
F_144 ( & V_285 -> V_61 ) , V_2 ) ;
if ( V_73 )
return V_73 ;
} else {
V_73 = F_143 ( & V_285 -> V_61 , V_301 , F_54 , 0 ,
F_144 ( & V_285 -> V_61 ) , V_2 ) ;
if ( V_73 )
return V_73 ;
}
V_266 [ V_2 -> V_9 . line ] = V_2 ;
F_145 ( V_285 , V_2 ) ;
return F_146 ( & V_315 , & V_2 -> V_9 ) ;
}
static int F_147 ( struct V_284 * V_285 )
{
struct V_1 * V_2 = F_148 ( V_285 ) ;
return F_149 ( & V_315 , & V_2 -> V_9 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_316 )
return;
F_8 ( V_2 -> V_317 [ 4 ] , V_2 -> V_9 . V_13 + V_158 ) ;
F_8 ( V_2 -> V_317 [ 5 ] , V_2 -> V_9 . V_13 + V_318 ) ;
F_8 ( V_2 -> V_317 [ 6 ] , V_2 -> V_9 . V_13 + V_319 ) ;
F_8 ( V_2 -> V_317 [ 7 ] , V_2 -> V_9 . V_13 + V_204 ) ;
F_8 ( V_2 -> V_317 [ 8 ] , V_2 -> V_9 . V_13 + V_205 ) ;
F_8 ( V_2 -> V_317 [ 9 ] , V_2 -> V_9 . V_13 + V_206 ) ;
F_8 ( V_2 -> V_317 [ 0 ] , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_2 -> V_317 [ 1 ] | V_192 , V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_2 -> V_317 [ 2 ] , V_2 -> V_9 . V_13 + V_18 ) ;
F_8 ( V_2 -> V_317 [ 3 ] , V_2 -> V_9 . V_13 + V_34 ) ;
V_2 -> V_316 = false ;
}
static void F_151 ( struct V_1 * V_2 )
{
V_2 -> V_317 [ 0 ] = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_317 [ 1 ] = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_2 -> V_317 [ 2 ] = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_2 -> V_317 [ 3 ] = F_6 ( V_2 -> V_9 . V_13 + V_34 ) ;
V_2 -> V_317 [ 4 ] = F_6 ( V_2 -> V_9 . V_13 + V_158 ) ;
V_2 -> V_317 [ 5 ] = F_6 ( V_2 -> V_9 . V_13 + V_318 ) ;
V_2 -> V_317 [ 6 ] = F_6 ( V_2 -> V_9 . V_13 + V_319 ) ;
V_2 -> V_317 [ 7 ] = F_6 ( V_2 -> V_9 . V_13 + V_204 ) ;
V_2 -> V_317 [ 8 ] = F_6 ( V_2 -> V_9 . V_13 + V_205 ) ;
V_2 -> V_317 [ 9 ] = F_6 ( V_2 -> V_9 . V_13 + V_206 ) ;
V_2 -> V_316 = true ;
}
static void F_152 ( struct V_1 * V_2 , bool V_320 )
{
unsigned int V_82 ;
V_82 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
if ( V_320 )
V_82 |= V_321 ;
else
V_82 &= ~ V_321 ;
F_8 ( V_82 , V_2 -> V_9 . V_13 + V_18 ) ;
V_82 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( V_320 )
V_82 |= V_193 ;
else
V_82 &= ~ V_193 ;
F_8 ( V_82 , V_2 -> V_9 . V_13 + V_14 ) ;
}
static int F_153 ( struct V_72 * V_61 )
{
struct V_284 * V_285 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_285 ) ;
int V_73 ;
V_73 = F_110 ( V_2 -> V_187 ) ;
if ( V_73 )
return V_73 ;
F_151 ( V_2 ) ;
F_111 ( V_2 -> V_187 ) ;
return 0 ;
}
static int F_155 ( struct V_72 * V_61 )
{
struct V_284 * V_285 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_285 ) ;
int V_73 ;
V_73 = F_110 ( V_2 -> V_187 ) ;
if ( V_73 )
return V_73 ;
F_150 ( V_2 ) ;
F_111 ( V_2 -> V_187 ) ;
return 0 ;
}
static int F_156 ( struct V_72 * V_61 )
{
struct V_284 * V_285 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_285 ) ;
F_152 ( V_2 , true ) ;
F_157 ( & V_315 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_158 ( struct V_72 * V_61 )
{
struct V_284 * V_285 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_285 ) ;
F_152 ( V_2 , false ) ;
F_159 ( & V_315 , & V_2 -> V_9 ) ;
return 0 ;
}
static int T_3 F_160 ( void )
{
int V_73 = F_161 ( & V_315 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_162 ( & V_322 ) ;
if ( V_73 != 0 )
F_163 ( & V_315 ) ;
return V_73 ;
}
static void T_5 F_164 ( void )
{
F_165 ( & V_322 ) ;
F_163 ( & V_315 ) ;
}
