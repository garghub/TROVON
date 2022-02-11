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
V_24 |= V_34 ;
F_8 ( V_24 , V_9 -> V_13 + V_16 ) ;
V_24 = F_6 ( V_9 -> V_13 + V_35 ) ;
V_24 &= ~ V_36 ;
F_8 ( V_24 , V_9 -> V_13 + V_35 ) ;
}
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_24 ;
if ( V_2 -> V_25 && V_2 -> V_37 ) {
if ( V_2 -> V_9 . V_38 ) {
F_15 ( V_2 -> V_39 ) ;
V_2 -> V_37 = 0 ;
} else {
return;
}
}
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_24 & ~ V_34 , V_2 -> V_9 . V_13 + V_16 ) ;
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
if ( ! ( V_9 -> V_28 . V_29 & V_80 ) )
V_24 &= ~ V_34 ;
F_8 ( V_24 , V_9 -> V_13 + V_16 ) ;
V_24 = F_6 ( V_9 -> V_13 + V_35 ) ;
V_24 |= V_36 ;
F_8 ( V_24 , V_9 -> V_13 + V_35 ) ;
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
static T_1 F_41 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
unsigned int V_83 ;
unsigned long V_29 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_8 ( V_84 , V_2 -> V_9 . V_13 + V_85 ) ;
V_83 = F_6 ( V_2 -> V_9 . V_13 + V_85 ) & V_86 ;
F_42 ( & V_2 -> V_9 , ! ! V_83 ) ;
F_43 ( & V_2 -> V_9 . V_45 -> V_9 . V_87 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
return V_88 ;
}
static T_1 F_44 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
unsigned long V_29 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_19 ( V_2 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
return V_88 ;
}
static T_1 F_45 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
unsigned int V_89 , V_90 , V_91 = 0 ;
struct V_92 * V_9 = & V_2 -> V_9 . V_45 -> V_9 ;
unsigned long V_29 , V_24 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
while ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_93 ) {
V_90 = V_94 ;
V_2 -> V_9 . V_48 . V_89 ++ ;
V_89 = F_6 ( V_2 -> V_9 . V_13 + V_95 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_31 ) ;
if ( V_24 & V_96 ) {
F_8 ( V_96 , V_2 -> V_9 . V_13 + V_31 ) ;
if ( F_46 ( & V_2 -> V_9 ) )
continue;
}
if ( F_47 ( & V_2 -> V_9 , ( unsigned char ) V_89 ) )
continue;
if ( F_48 ( V_89 & V_97 ) ) {
if ( V_89 & V_98 )
V_2 -> V_9 . V_48 . V_99 ++ ;
else if ( V_89 & V_100 )
V_2 -> V_9 . V_48 . V_101 ++ ;
else if ( V_89 & V_102 )
V_2 -> V_9 . V_48 . V_103 ++ ;
if ( V_89 & V_104 )
V_2 -> V_9 . V_48 . V_105 ++ ;
if ( V_89 & V_2 -> V_9 . V_106 ) {
if ( ++ V_91 > 100 )
goto V_107;
continue;
}
V_89 &= ( V_2 -> V_9 . V_108 | 0xFF ) ;
if ( V_89 & V_98 )
V_90 = V_109 ;
else if ( V_89 & V_100 )
V_90 = V_110 ;
else if ( V_89 & V_102 )
V_90 = V_111 ;
if ( V_89 & V_104 )
V_90 = V_112 ;
#ifdef F_49
V_2 -> V_9 . V_113 = 0 ;
#endif
}
if ( V_2 -> V_9 . V_106 & V_114 )
goto V_107;
if ( F_50 ( V_9 , V_89 , V_90 ) == 0 )
V_2 -> V_9 . V_48 . V_115 ++ ;
}
V_107:
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_51 ( V_9 ) ;
return V_88 ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
unsigned long V_29 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_31 ) ;
if ( ( V_24 & V_93 ) && ! V_2 -> V_37 ) {
V_2 -> V_37 = 1 ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ ( V_40 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ ( V_116 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_53 ( V_2 ) ;
}
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static unsigned int F_54 ( struct V_1 * V_2 )
{
unsigned int V_117 = V_118 ;
unsigned V_119 = F_6 ( V_2 -> V_9 . V_13 + V_85 ) ;
if ( V_119 & V_86 )
V_117 |= V_120 ;
if ( ! ( V_119 & V_121 ) )
V_117 |= V_122 ;
if ( V_2 -> V_123 )
if ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_124 ) )
V_117 |= V_125 ;
return V_117 ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_126 , V_127 ;
V_126 = F_54 ( V_2 ) ;
V_127 = V_126 ^ V_2 -> V_128 ;
if ( V_127 == 0 )
return;
V_2 -> V_128 = V_126 ;
if ( V_127 & V_125 && V_126 & V_125 )
V_2 -> V_9 . V_48 . V_129 ++ ;
if ( V_127 & V_118 )
V_2 -> V_9 . V_48 . V_130 ++ ;
if ( V_127 & V_122 )
F_56 ( & V_2 -> V_9 , V_126 & V_122 ) ;
if ( V_127 & V_120 )
F_42 ( & V_2 -> V_9 , V_126 & V_120 ) ;
F_43 ( & V_2 -> V_9 . V_45 -> V_9 . V_87 ) ;
}
static T_1 F_57 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
unsigned int V_131 ;
unsigned int V_132 ;
T_1 V_73 = V_133 ;
V_131 = F_6 ( V_2 -> V_9 . V_13 + V_85 ) ;
V_132 = F_6 ( V_2 -> V_9 . V_13 + V_31 ) ;
if ( V_131 & ( V_134 | V_135 ) ) {
if ( V_2 -> V_25 )
F_52 ( V_2 ) ;
else
F_45 ( V_81 , V_82 ) ;
V_73 = V_88 ;
}
if ( ( V_131 & V_136 &&
F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_27 ) ||
( V_132 & V_32 &&
F_6 ( V_2 -> V_9 . V_13 + V_35 ) & V_36 ) ) {
F_44 ( V_81 , V_82 ) ;
V_73 = V_88 ;
}
if ( V_131 & V_137 ) {
unsigned long V_29 ;
if ( V_131 & V_137 )
F_8 ( V_137 , V_2 -> V_9 . V_13 + V_85 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_55 ( V_2 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_73 = V_88 ;
}
if ( V_131 & V_84 ) {
F_41 ( V_81 , V_82 ) ;
V_73 = V_88 ;
}
if ( V_131 & V_138 ) {
F_8 ( V_138 , V_2 -> V_9 . V_13 + V_85 ) ;
V_73 = V_88 ;
}
if ( V_132 & V_139 ) {
V_2 -> V_9 . V_48 . V_105 ++ ;
F_8 ( V_139 , V_2 -> V_9 . V_13 + V_31 ) ;
V_73 = V_88 ;
}
return V_73 ;
}
static unsigned int F_58 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_73 ;
V_73 = ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_32 ) ? V_140 : 0 ;
if ( V_2 -> V_25 && V_2 -> V_26 )
V_73 = 0 ;
return V_73 ;
}
static unsigned int F_59 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_73 = F_54 ( V_2 ) ;
F_60 ( V_2 -> V_21 , & V_73 ) ;
return V_73 ;
}
static void F_61 ( struct V_8 * V_9 , unsigned int V_22 )
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
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) & ~ V_141 ;
if ( ! ( V_22 & V_142 ) )
V_24 |= V_141 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_18 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & ~ V_143 ;
if ( V_22 & V_144 )
V_24 |= V_143 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) ;
F_10 ( V_2 -> V_21 , V_22 ) ;
}
static void F_62 ( struct V_8 * V_9 , int V_145 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 , V_24 ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) & ~ V_146 ;
if ( V_145 != 0 )
V_24 |= V_146 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static void F_63 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_29 ;
if ( V_2 -> V_9 . V_45 ) {
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_55 ( V_2 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_17 ( & V_2 -> V_41 , V_42 + V_147 ) ;
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
V_24 |= V_116 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
V_2 -> V_37 = 0 ;
if ( F_30 ( & V_2 -> V_65 ) )
F_31 ( & V_2 -> V_65 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static void F_65 ( void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_69 * V_70 = V_2 -> V_39 ;
struct V_57 * V_58 = & V_2 -> V_148 ;
struct V_92 * V_9 = & V_2 -> V_9 . V_45 -> V_9 ;
struct V_149 V_45 ;
enum V_150 V_126 ;
unsigned int V_151 ;
F_27 ( V_2 -> V_9 . V_61 , V_58 , 1 , V_152 ) ;
V_126 = F_66 ( V_70 , ( V_153 ) 0 , & V_45 ) ;
V_151 = V_154 - V_45 . V_155 ;
F_28 ( V_2 -> V_9 . V_61 , L_6 , V_151 ) ;
if ( V_151 ) {
if ( ! ( V_2 -> V_9 . V_106 & V_114 ) ) {
int V_156 = F_67 ( V_9 , V_2 -> V_157 ,
V_151 ) ;
if ( V_156 != V_151 )
V_2 -> V_9 . V_48 . V_115 ++ ;
}
F_51 ( V_9 ) ;
V_2 -> V_9 . V_48 . V_89 += V_151 ;
}
if ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_93 )
F_53 ( V_2 ) ;
else
F_64 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = & V_2 -> V_148 ;
struct V_69 * V_70 = V_2 -> V_39 ;
struct V_72 * V_61 = V_2 -> V_9 . V_61 ;
struct V_67 * V_68 ;
int V_73 ;
F_32 ( V_58 , V_2 -> V_157 , V_154 ) ;
V_73 = F_35 ( V_61 , V_58 , 1 , V_152 ) ;
if ( V_73 == 0 ) {
F_36 ( V_61 , L_7 ) ;
return - V_158 ;
}
V_68 = F_37 ( V_70 , V_58 , 1 , V_159 ,
V_76 ) ;
if ( ! V_68 ) {
F_27 ( V_61 , V_58 , 1 , V_152 ) ;
F_36 ( V_61 , L_8 ) ;
return - V_158 ;
}
V_68 -> V_77 = F_65 ;
V_68 -> V_78 = V_2 ;
F_28 ( V_61 , L_9 ) ;
F_38 ( V_68 ) ;
F_39 ( V_70 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 ,
unsigned char V_160 , unsigned char V_161 )
{
unsigned int V_83 ;
V_83 = F_6 ( V_2 -> V_9 . V_13 + V_162 ) & ( V_163 | V_164 ) ;
V_83 |= V_160 << V_165 | V_161 ;
F_8 ( V_83 , V_2 -> V_9 . V_13 + V_162 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 ) {
F_70 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
F_71 ( V_2 -> V_157 ) ;
V_2 -> V_157 = NULL ;
}
if ( V_2 -> V_71 ) {
F_70 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
}
V_2 -> V_166 = 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_167 V_168 = {} ;
struct V_72 * V_61 = V_2 -> V_9 . V_61 ;
int V_73 ;
V_2 -> V_39 = F_73 ( V_61 , L_10 ) ;
if ( ! V_2 -> V_39 ) {
F_28 ( V_61 , L_11 ) ;
V_73 = - V_158 ;
goto V_169;
}
V_168 . V_170 = V_159 ;
V_168 . V_171 = V_2 -> V_9 . V_172 + V_95 ;
V_168 . V_173 = V_174 ;
V_168 . V_175 = V_176 - 1 ;
V_73 = F_74 ( V_2 -> V_39 , & V_168 ) ;
if ( V_73 ) {
F_36 ( V_61 , L_12 ) ;
goto V_169;
}
V_2 -> V_157 = F_75 ( V_177 , V_178 ) ;
if ( ! V_2 -> V_157 ) {
V_73 = - V_179 ;
goto V_169;
}
V_2 -> V_71 = F_73 ( V_61 , L_13 ) ;
if ( ! V_2 -> V_71 ) {
F_36 ( V_61 , L_14 ) ;
V_73 = - V_158 ;
goto V_169;
}
V_168 . V_170 = V_75 ;
V_168 . V_180 = V_2 -> V_9 . V_172 + V_47 ;
V_168 . V_181 = V_174 ;
V_168 . V_182 = V_183 ;
V_73 = F_74 ( V_2 -> V_71 , & V_168 ) ;
if ( V_73 ) {
F_36 ( V_61 , L_15 ) ;
goto V_169;
}
V_2 -> V_166 = 1 ;
return 0 ;
V_169:
F_69 ( V_2 ) ;
return V_73 ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
F_77 ( & V_2 -> V_65 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 |= V_184 | V_50 | V_185 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= V_116 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_68 ( V_2 , V_183 , V_176 ) ;
V_2 -> V_25 = 1 ;
}
static void F_78 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ ( V_184 | V_50 | V_185 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ ( V_19 | V_20 | V_116 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_68 ( V_2 , V_186 , V_187 ) ;
V_2 -> V_25 = 0 ;
}
static int F_79 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_188 , V_189 ;
unsigned long V_29 , V_24 ;
V_188 = F_80 ( V_2 -> V_190 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_80 ( V_2 -> V_191 ) ;
if ( V_188 ) {
F_81 ( V_2 -> V_190 ) ;
return V_188 ;
}
F_68 ( V_2 , V_186 , V_187 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_35 ) ;
V_24 &= ~ ( V_192 << V_193 ) ;
V_24 |= V_194 << V_193 ;
F_8 ( V_24 & ~ V_195 , V_2 -> V_9 . V_13 + V_35 ) ;
if ( F_4 ( V_2 ) && ! F_82 ( V_9 ) &&
! V_2 -> V_166 )
F_72 ( V_2 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_189 = 100 ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ V_196 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_196 ) && ( -- V_189 > 0 ) )
F_83 ( 1 ) ;
F_8 ( V_84 | V_137 , V_2 -> V_9 . V_13 + V_85 ) ;
F_8 ( V_139 , V_2 -> V_9 . V_13 + V_31 ) ;
if ( V_2 -> V_166 && ! V_2 -> V_25 )
F_76 ( V_2 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 |= V_40 | V_197 | V_198 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_35 ) ;
V_24 |= V_199 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_35 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= ( V_34 | V_200 ) ;
if ( ! V_2 -> V_201 )
V_24 |= V_202 ;
if ( ! F_2 ( V_2 ) )
V_24 &= ~ V_203 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( ! F_2 ( V_2 ) ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_24 |= V_204 | V_205 |
V_206 | V_207 | V_208 ;
if ( V_2 -> V_123 )
V_24 &= ~ ( V_207 | V_208 ) ;
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
! V_2 -> V_37 && ! V_2 -> V_26 ) ;
if ( V_73 != 0 ) {
V_2 -> V_37 = 0 ;
V_2 -> V_26 = 0 ;
F_15 ( V_2 -> V_71 ) ;
F_15 ( V_2 -> V_39 ) ;
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
V_24 &= ~ ( V_200 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_87 ( & V_2 -> V_41 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_24 &= ~ ( V_27 | V_40 | V_197 | V_198 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_81 ( V_2 -> V_190 ) ;
F_81 ( V_2 -> V_191 ) ;
}
static void F_88 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
struct V_57 * V_58 = & V_2 -> V_59 [ 0 ] ;
unsigned long V_24 ;
int V_189 = 100 , V_209 , V_210 , V_211 ;
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
V_209 = F_6 ( V_2 -> V_9 . V_13 + V_212 ) ;
V_210 = F_6 ( V_2 -> V_9 . V_13 + V_213 ) ;
V_211 = F_6 ( V_2 -> V_9 . V_13 + V_214 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 &= ~ V_196 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_196 ) && ( -- V_189 > 0 ) )
F_83 ( 1 ) ;
F_8 ( V_209 , V_2 -> V_9 . V_13 + V_212 ) ;
F_8 ( V_210 , V_2 -> V_9 . V_13 + V_213 ) ;
F_8 ( V_211 , V_2 -> V_9 . V_13 + V_214 ) ;
}
static void
F_89 ( struct V_8 * V_9 , struct V_215 * V_216 ,
struct V_215 * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
unsigned long V_15 , V_218 , V_219 ;
unsigned int V_220 , V_221 ;
unsigned int V_222 = V_217 ? V_217 -> V_223 & V_224 : V_225 ;
unsigned long div , V_226 ;
unsigned long V_227 , V_228 ;
T_2 V_229 ;
while ( ( V_216 -> V_223 & V_224 ) != V_230 &&
( V_216 -> V_223 & V_224 ) != V_225 ) {
V_216 -> V_223 &= ~ V_224 ;
V_216 -> V_223 |= V_222 ;
V_222 = V_225 ;
}
if ( ( V_216 -> V_223 & V_224 ) == V_225 )
V_15 = V_231 | V_196 | V_202 ;
else
V_15 = V_196 | V_202 ;
if ( V_216 -> V_223 & V_232 ) {
if ( V_2 -> V_201 ) {
V_15 &= ~ V_202 ;
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
V_216 -> V_223 &= ~ V_232 ;
}
} else if ( V_9 -> V_28 . V_29 & V_30 ) {
if ( V_9 -> V_28 . V_29 & V_33 )
F_11 ( V_2 , & V_15 ) ;
else
F_9 ( V_2 , & V_15 ) ;
}
if ( V_216 -> V_223 & V_233 )
V_15 |= V_234 ;
if ( V_216 -> V_223 & V_235 ) {
V_15 |= V_236 ;
if ( V_216 -> V_223 & V_237 )
V_15 |= V_238 ;
}
F_87 ( & V_2 -> V_41 ) ;
V_220 = F_90 ( V_9 , V_216 , V_217 , 50 , V_9 -> V_239 / 16 ) ;
V_221 = F_91 ( V_9 , V_220 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_2 -> V_9 . V_108 = 0 ;
if ( V_216 -> V_240 & V_241 )
V_2 -> V_9 . V_108 |= ( V_102 | V_100 ) ;
if ( V_216 -> V_240 & ( V_242 | V_243 ) )
V_2 -> V_9 . V_108 |= V_98 ;
V_2 -> V_9 . V_106 = 0 ;
if ( V_216 -> V_240 & V_244 )
V_2 -> V_9 . V_106 |= V_100 | V_102 ;
if ( V_216 -> V_240 & V_245 ) {
V_2 -> V_9 . V_106 |= V_98 ;
if ( V_216 -> V_240 & V_244 )
V_2 -> V_9 . V_106 |= V_104 ;
}
if ( ( V_216 -> V_223 & V_246 ) == 0 )
V_2 -> V_9 . V_106 |= V_114 ;
F_92 ( V_9 , V_216 -> V_223 , V_220 ) ;
V_218 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_218 & ~ ( V_27 | V_40 | V_197 ) ,
V_2 -> V_9 . V_13 + V_14 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_32 ) )
F_93 () ;
V_219 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_219 & ~ ( V_200 | V_34 ) ,
V_2 -> V_9 . V_13 + V_16 ) ;
V_219 &= ( V_200 | V_34 | V_116 ) ;
div = V_2 -> V_9 . V_239 / ( V_220 * 16 ) ;
if ( V_220 == 38400 && V_221 != div )
V_220 = V_2 -> V_9 . V_239 / ( V_221 * 16 ) ;
div = V_2 -> V_9 . V_239 / ( V_220 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
F_94 ( 16 * div * V_220 , V_2 -> V_9 . V_239 ,
1 << 16 , 1 << 16 , & V_227 , & V_228 ) ;
V_229 = V_2 -> V_9 . V_239 ;
V_229 *= V_227 ;
F_95 ( V_229 , V_228 * 16 * div ) ;
F_96 ( V_216 ,
( V_247 ) V_229 , ( V_247 ) V_229 ) ;
V_227 -= 1 ;
V_228 -= 1 ;
V_226 = F_6 ( V_2 -> V_9 . V_13 + V_162 ) ;
V_226 = ( V_226 & ( ~ V_163 ) ) | F_97 ( div ) ;
if ( V_2 -> V_123 )
V_226 |= V_164 ;
F_8 ( V_226 , V_2 -> V_9 . V_13 + V_162 ) ;
F_8 ( V_227 , V_2 -> V_9 . V_13 + V_212 ) ;
F_8 ( V_228 , V_2 -> V_9 . V_13 + V_213 ) ;
if ( ! F_2 ( V_2 ) )
F_8 ( V_2 -> V_9 . V_239 / div / 1000 ,
V_2 -> V_9 . V_13 + V_248 ) ;
F_8 ( V_218 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_15 | V_219 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( F_98 ( & V_2 -> V_9 , V_216 -> V_223 ) )
F_16 ( & V_2 -> V_9 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
}
static const char * F_99 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_249 ? L_16 : NULL ;
}
static void F_100 ( struct V_8 * V_9 , int V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_29 & V_250 )
V_2 -> V_9 . type = V_249 ;
}
static int
F_101 ( struct V_8 * V_9 , struct V_251 * V_252 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_73 = 0 ;
if ( V_252 -> type != V_253 && V_252 -> type != V_249 )
V_73 = - V_158 ;
if ( V_2 -> V_9 . V_81 != V_252 -> V_81 )
V_73 = - V_158 ;
if ( V_252 -> V_254 != V_255 )
V_73 = - V_158 ;
if ( V_2 -> V_9 . V_239 / 16 != V_252 -> V_256 )
V_73 = - V_158 ;
if ( V_2 -> V_9 . V_172 != ( unsigned long ) V_252 -> V_257 )
V_73 = - V_158 ;
if ( V_2 -> V_9 . V_258 != V_252 -> V_9 )
V_73 = - V_158 ;
if ( V_252 -> V_259 != 0 )
V_73 = - V_158 ;
return V_73 ;
}
static int F_102 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_29 ;
unsigned long V_24 ;
int V_188 ;
V_188 = F_80 ( V_2 -> V_191 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_80 ( V_2 -> V_190 ) ;
if ( V_188 )
F_81 ( V_2 -> V_191 ) ;
F_68 ( V_2 , V_186 , V_187 ) ;
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( F_2 ( V_2 ) )
V_24 |= V_260 ;
V_24 |= V_198 | V_40 ;
V_24 &= ~ ( V_27 | V_197 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_14 ) ;
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= V_34 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
return 0 ;
}
static int F_103 ( struct V_8 * V_9 )
{
if ( ! ( F_104 ( V_9 -> V_13 + V_31 ) & V_93 ) )
return V_261 ;
return F_104 ( V_9 -> V_13 + V_95 ) & V_262 ;
}
static void F_105 ( struct V_8 * V_9 , unsigned char V_263 )
{
unsigned int V_126 ;
do {
V_126 = F_104 ( V_9 -> V_13 + V_85 ) ;
} while ( ~ V_126 & V_136 );
F_106 ( V_263 , V_9 -> V_13 + V_47 ) ;
do {
V_126 = F_104 ( V_9 -> V_13 + V_31 ) ;
} while ( ~ V_126 & V_32 );
}
static int F_107 ( struct V_8 * V_9 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_24 ;
V_265 -> V_266 = 0 ;
V_265 -> V_267 = 0 ;
if ( ! V_2 -> V_201 )
V_265 -> V_29 &= ~ V_30 ;
if ( V_265 -> V_29 & V_30 ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
if ( V_265 -> V_29 & V_33 )
F_11 ( V_2 , & V_24 ) ;
else
F_9 ( V_2 , & V_24 ) ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
}
if ( ! ( V_265 -> V_29 & V_30 ) ||
V_265 -> V_29 & V_80 ) {
V_24 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_24 |= V_34 ;
F_8 ( V_24 , V_2 -> V_9 . V_13 + V_16 ) ;
}
V_9 -> V_28 = * V_265 ;
return 0 ;
}
static void F_108 ( struct V_8 * V_9 , int V_268 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_51 )
F_93 () ;
F_8 ( V_268 , V_2 -> V_9 . V_13 + V_47 ) ;
}
static void
F_109 ( struct V_269 * V_270 , const char * V_271 , unsigned int V_151 )
{
struct V_1 * V_2 = V_272 [ V_270 -> V_273 ] ;
struct V_10 V_274 ;
unsigned int V_12 ;
unsigned long V_29 = 0 ;
int V_275 = 1 ;
int V_188 ;
V_188 = F_110 ( V_2 -> V_190 ) ;
if ( V_188 )
return;
V_188 = F_110 ( V_2 -> V_191 ) ;
if ( V_188 ) {
F_111 ( V_2 -> V_190 ) ;
return;
}
if ( V_2 -> V_9 . V_113 )
V_275 = 0 ;
else if ( V_276 )
V_275 = F_112 ( & V_2 -> V_9 . V_60 , V_29 ) ;
else
F_26 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_5 ( & V_2 -> V_9 , & V_274 ) ;
V_12 = V_274 . V_12 ;
if ( F_2 ( V_2 ) )
V_12 |= V_260 ;
V_12 |= V_198 ;
V_12 &= ~ ( V_27 | V_40 | V_197 ) ;
F_8 ( V_12 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_274 . V_15 | V_200 , V_2 -> V_9 . V_13 + V_16 ) ;
F_113 ( & V_2 -> V_9 , V_271 , V_151 , F_108 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_31 ) & V_32 ) ) ;
F_7 ( & V_2 -> V_9 , & V_274 ) ;
if ( V_275 )
F_29 ( & V_2 -> V_9 . V_60 , V_29 ) ;
F_111 ( V_2 -> V_191 ) ;
F_111 ( V_2 -> V_190 ) ;
}
static void T_3
F_114 ( struct V_1 * V_2 , int * V_220 ,
int * V_101 , int * V_277 )
{
if ( F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_198 ) {
unsigned int V_15 , V_209 , V_210 , V_239 ;
unsigned int V_278 ;
unsigned int V_279 ;
V_15 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
* V_101 = 'n' ;
if ( V_15 & V_236 ) {
if ( V_15 & V_238 )
* V_101 = 'o' ;
else
* V_101 = 'e' ;
}
if ( V_15 & V_231 )
* V_277 = 8 ;
else
* V_277 = 7 ;
V_209 = F_6 ( V_2 -> V_9 . V_13 + V_212 ) & 0xffff ;
V_210 = F_6 ( V_2 -> V_9 . V_13 + V_213 ) & 0xffff ;
V_279 = ( F_6 ( V_2 -> V_9 . V_13 + V_162 ) & V_163 ) >> 7 ;
if ( V_279 == 6 )
V_279 = 7 ;
else
V_279 = 6 - V_279 ;
V_239 = F_115 ( V_2 -> V_190 ) ;
V_239 /= V_279 ;
{
unsigned int V_280 = V_209 + 1 ;
unsigned int div = 16 * ( V_210 + 1 ) ;
unsigned int V_281 = V_239 % div ;
V_278 = ( V_239 / div ) * V_280 ;
V_278 += ( V_281 * V_280 + div / 2 ) / div ;
* V_220 = ( V_278 + 50 ) / 100 * 100 ;
}
if ( * V_220 != V_278 )
F_116 ( L_17 ,
V_278 , * V_220 ) ;
}
}
static int T_3
F_117 ( struct V_269 * V_270 , char * V_282 )
{
struct V_1 * V_2 ;
int V_220 = 9600 ;
int V_277 = 8 ;
int V_101 = 'n' ;
int V_283 = 'n' ;
int V_188 ;
if ( V_270 -> V_273 == - 1 || V_270 -> V_273 >= F_118 ( V_272 ) )
V_270 -> V_273 = 0 ;
V_2 = V_272 [ V_270 -> V_273 ] ;
if ( V_2 == NULL )
return - V_284 ;
V_188 = F_80 ( V_2 -> V_191 ) ;
if ( V_188 )
goto V_285;
if ( V_282 )
F_119 ( V_282 , & V_220 , & V_101 , & V_277 , & V_283 ) ;
else
F_114 ( V_2 , & V_220 , & V_101 , & V_277 ) ;
F_68 ( V_2 , V_186 , V_187 ) ;
V_188 = F_120 ( & V_2 -> V_9 , V_270 , V_220 , V_101 , V_277 , V_283 ) ;
F_111 ( V_2 -> V_191 ) ;
if ( V_188 ) {
F_121 ( V_2 -> V_191 ) ;
goto V_285;
}
V_188 = F_122 ( V_2 -> V_190 ) ;
if ( V_188 )
F_81 ( V_2 -> V_191 ) ;
V_285:
return V_188 ;
}
static void F_123 ( struct V_8 * V_9 , int V_268 )
{
while ( F_104 ( V_9 -> V_13 + V_214 ) & V_51 )
F_124 () ;
F_106 ( V_268 , V_9 -> V_13 + V_47 ) ;
}
static void F_125 ( struct V_269 * V_286 , const char * V_271 ,
unsigned V_151 )
{
struct V_287 * V_61 = V_286 -> V_56 ;
F_113 ( & V_61 -> V_9 , V_271 , V_151 , F_123 ) ;
}
static int T_3
F_126 ( struct V_287 * V_61 , const char * V_288 )
{
if ( ! V_61 -> V_9 . V_13 )
return - V_284 ;
V_61 -> V_286 -> V_289 = F_125 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = V_291 -> V_61 . V_294 ;
int V_73 ;
V_2 -> V_3 = F_128 ( & V_291 -> V_61 ) ;
if ( ! V_2 -> V_3 )
return 1 ;
V_73 = F_129 ( V_293 , L_18 ) ;
if ( V_73 < 0 ) {
F_36 ( & V_291 -> V_61 , L_19 , V_73 ) ;
return V_73 ;
}
V_2 -> V_9 . line = V_73 ;
if ( F_130 ( V_293 , L_20 , NULL ) ||
F_130 ( V_293 , L_21 , NULL ) )
V_2 -> V_201 = 1 ;
if ( F_130 ( V_293 , L_22 , NULL ) )
V_2 -> V_123 = 1 ;
return 0 ;
}
static inline int F_127 ( struct V_1 * V_2 ,
struct V_290 * V_291 )
{
return 1 ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_290 * V_291 )
{
struct V_295 * V_296 = F_132 ( & V_291 -> V_61 ) ;
V_2 -> V_9 . line = V_291 -> V_297 ;
V_2 -> V_3 = (struct V_298 * ) V_291 -> V_299 -> V_300 ;
if ( ! V_296 )
return;
if ( V_296 -> V_29 & V_301 )
V_2 -> V_201 = 1 ;
}
static int F_133 ( struct V_290 * V_291 )
{
struct V_1 * V_2 ;
void T_4 * V_302 ;
int V_73 = 0 , V_303 ;
struct V_304 * V_305 ;
int V_306 , V_307 , V_308 ;
V_2 = F_134 ( & V_291 -> V_61 , sizeof( * V_2 ) , V_178 ) ;
if ( ! V_2 )
return - V_179 ;
V_73 = F_127 ( V_2 , V_291 ) ;
if ( V_73 > 0 )
F_131 ( V_2 , V_291 ) ;
else if ( V_73 < 0 )
return V_73 ;
V_305 = F_135 ( V_291 , V_309 , 0 ) ;
V_302 = F_136 ( & V_291 -> V_61 , V_305 ) ;
if ( F_137 ( V_302 ) )
return F_138 ( V_302 ) ;
V_307 = F_139 ( V_291 , 0 ) ;
V_306 = F_139 ( V_291 , 1 ) ;
V_308 = F_139 ( V_291 , 2 ) ;
V_2 -> V_9 . V_61 = & V_291 -> V_61 ;
V_2 -> V_9 . V_172 = V_305 -> V_310 ;
V_2 -> V_9 . V_13 = V_302 ;
V_2 -> V_9 . type = V_249 ,
V_2 -> V_9 . V_311 = V_255 ;
V_2 -> V_9 . V_81 = V_307 ;
V_2 -> V_9 . V_312 = 32 ;
V_2 -> V_9 . V_313 = & V_314 ;
V_2 -> V_9 . V_315 = F_107 ;
V_2 -> V_9 . V_28 . V_29 =
V_79 | V_80 ;
V_2 -> V_9 . V_29 = V_316 ;
F_140 ( & V_2 -> V_41 ) ;
V_2 -> V_41 . V_317 = F_63 ;
V_2 -> V_41 . V_56 = ( unsigned long ) V_2 ;
V_2 -> V_21 = F_141 ( & V_2 -> V_9 , 0 ) ;
if ( F_137 ( V_2 -> V_21 ) )
return F_138 ( V_2 -> V_21 ) ;
V_2 -> V_191 = F_142 ( & V_291 -> V_61 , L_23 ) ;
if ( F_137 ( V_2 -> V_191 ) ) {
V_73 = F_138 ( V_2 -> V_191 ) ;
F_36 ( & V_291 -> V_61 , L_24 , V_73 ) ;
return V_73 ;
}
V_2 -> V_190 = F_142 ( & V_291 -> V_61 , L_25 ) ;
if ( F_137 ( V_2 -> V_190 ) ) {
V_73 = F_138 ( V_2 -> V_190 ) ;
F_36 ( & V_291 -> V_61 , L_26 , V_73 ) ;
return V_73 ;
}
V_2 -> V_9 . V_239 = F_115 ( V_2 -> V_190 ) ;
V_73 = F_80 ( V_2 -> V_191 ) ;
if ( V_73 )
return V_73 ;
V_303 = F_104 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_303 &= ~ ( V_318 | V_319 | V_320 | V_40 |
V_27 | V_197 ) ;
F_106 ( V_303 , V_2 -> V_9 . V_13 + V_14 ) ;
F_81 ( V_2 -> V_191 ) ;
if ( V_306 > 0 ) {
V_73 = F_143 ( & V_291 -> V_61 , V_307 , F_45 , 0 ,
F_144 ( & V_291 -> V_61 ) , V_2 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_143 ( & V_291 -> V_61 , V_306 , F_44 , 0 ,
F_144 ( & V_291 -> V_61 ) , V_2 ) ;
if ( V_73 )
return V_73 ;
} else {
V_73 = F_143 ( & V_291 -> V_61 , V_307 , F_57 , 0 ,
F_144 ( & V_291 -> V_61 ) , V_2 ) ;
if ( V_73 )
return V_73 ;
}
V_272 [ V_2 -> V_9 . line ] = V_2 ;
F_145 ( V_291 , V_2 ) ;
return F_146 ( & V_321 , & V_2 -> V_9 ) ;
}
static int F_147 ( struct V_290 * V_291 )
{
struct V_1 * V_2 = F_148 ( V_291 ) ;
return F_149 ( & V_321 , & V_2 -> V_9 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_322 )
return;
F_8 ( V_2 -> V_323 [ 4 ] , V_2 -> V_9 . V_13 + V_162 ) ;
F_8 ( V_2 -> V_323 [ 5 ] , V_2 -> V_9 . V_13 + V_324 ) ;
F_8 ( V_2 -> V_323 [ 6 ] , V_2 -> V_9 . V_13 + V_325 ) ;
F_8 ( V_2 -> V_323 [ 7 ] , V_2 -> V_9 . V_13 + V_212 ) ;
F_8 ( V_2 -> V_323 [ 8 ] , V_2 -> V_9 . V_13 + V_213 ) ;
F_8 ( V_2 -> V_323 [ 9 ] , V_2 -> V_9 . V_13 + V_214 ) ;
F_8 ( V_2 -> V_323 [ 0 ] , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_2 -> V_323 [ 1 ] | V_196 , V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_2 -> V_323 [ 2 ] , V_2 -> V_9 . V_13 + V_18 ) ;
F_8 ( V_2 -> V_323 [ 3 ] , V_2 -> V_9 . V_13 + V_35 ) ;
V_2 -> V_322 = false ;
}
static void F_151 ( struct V_1 * V_2 )
{
V_2 -> V_323 [ 0 ] = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_323 [ 1 ] = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_2 -> V_323 [ 2 ] = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_2 -> V_323 [ 3 ] = F_6 ( V_2 -> V_9 . V_13 + V_35 ) ;
V_2 -> V_323 [ 4 ] = F_6 ( V_2 -> V_9 . V_13 + V_162 ) ;
V_2 -> V_323 [ 5 ] = F_6 ( V_2 -> V_9 . V_13 + V_324 ) ;
V_2 -> V_323 [ 6 ] = F_6 ( V_2 -> V_9 . V_13 + V_325 ) ;
V_2 -> V_323 [ 7 ] = F_6 ( V_2 -> V_9 . V_13 + V_212 ) ;
V_2 -> V_323 [ 8 ] = F_6 ( V_2 -> V_9 . V_13 + V_213 ) ;
V_2 -> V_323 [ 9 ] = F_6 ( V_2 -> V_9 . V_13 + V_214 ) ;
V_2 -> V_322 = true ;
}
static void F_152 ( struct V_1 * V_2 , bool V_326 )
{
unsigned int V_83 ;
V_83 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
if ( V_326 )
V_83 |= V_327 ;
else
V_83 &= ~ V_327 ;
F_8 ( V_83 , V_2 -> V_9 . V_13 + V_18 ) ;
V_83 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
if ( V_326 )
V_83 |= V_197 ;
else
V_83 &= ~ V_197 ;
F_8 ( V_83 , V_2 -> V_9 . V_13 + V_14 ) ;
}
static int F_153 ( struct V_72 * V_61 )
{
struct V_290 * V_291 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_291 ) ;
int V_73 ;
V_73 = F_110 ( V_2 -> V_191 ) ;
if ( V_73 )
return V_73 ;
F_151 ( V_2 ) ;
F_111 ( V_2 -> V_191 ) ;
return 0 ;
}
static int F_155 ( struct V_72 * V_61 )
{
struct V_290 * V_291 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_291 ) ;
int V_73 ;
V_73 = F_110 ( V_2 -> V_191 ) ;
if ( V_73 )
return V_73 ;
F_150 ( V_2 ) ;
F_111 ( V_2 -> V_191 ) ;
return 0 ;
}
static int F_156 ( struct V_72 * V_61 )
{
struct V_290 * V_291 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_291 ) ;
F_152 ( V_2 , true ) ;
F_157 ( & V_321 , & V_2 -> V_9 ) ;
return F_122 ( V_2 -> V_191 ) ;
}
static int F_158 ( struct V_72 * V_61 )
{
struct V_290 * V_291 = F_154 ( V_61 ) ;
struct V_1 * V_2 = F_148 ( V_291 ) ;
F_152 ( V_2 , false ) ;
F_159 ( & V_321 , & V_2 -> V_9 ) ;
F_121 ( V_2 -> V_191 ) ;
return 0 ;
}
static int T_3 F_160 ( void )
{
int V_73 = F_161 ( & V_321 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_162 ( & V_328 ) ;
if ( V_73 != 0 )
F_163 ( & V_321 ) ;
return V_73 ;
}
static void T_5 F_164 ( void )
{
F_165 ( & V_328 ) ;
F_163 ( & V_321 ) ;
}
