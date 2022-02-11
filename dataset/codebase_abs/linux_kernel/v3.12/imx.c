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
if ( V_2 -> V_52 && V_2 -> V_54 )
return;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_39 & ~ V_55 , V_2 -> V_9 . V_13 + V_16 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_16 ( & V_2 -> V_36 , V_37 ) ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = & V_2 -> V_9 . V_31 -> V_57 ;
while ( ! F_24 ( V_57 ) &&
! ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) )
& V_58 ) ) {
F_8 ( V_57 -> V_59 [ V_57 -> V_60 ] , V_2 -> V_9 . V_13 + V_61 ) ;
V_57 -> V_60 = ( V_57 -> V_60 + 1 ) & ( V_62 - 1 ) ;
V_2 -> V_9 . V_25 . V_63 ++ ;
}
if ( F_25 ( V_57 ) < V_64 )
F_26 ( & V_2 -> V_9 ) ;
if ( F_24 ( V_57 ) )
F_17 ( & V_2 -> V_9 ) ;
}
static void F_27 ( void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_65 * V_66 = & V_2 -> V_67 [ 0 ] ;
struct V_56 * V_57 = & V_2 -> V_9 . V_31 -> V_57 ;
unsigned long V_34 ;
F_28 ( V_2 -> V_9 . V_68 , V_66 , V_2 -> V_69 , V_70 ) ;
V_2 -> V_53 = 0 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_57 -> V_60 = ( V_57 -> V_60 + V_2 -> V_71 ) & ( V_62 - 1 ) ;
V_2 -> V_9 . V_25 . V_63 += V_2 -> V_71 ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_29 ( V_2 -> V_9 . V_68 , L_1 ) ;
if ( F_25 ( V_57 ) < V_64 )
F_26 ( & V_2 -> V_9 ) ;
if ( F_30 ( & V_2 -> V_72 ) ) {
F_31 ( & V_2 -> V_72 ) ;
F_29 ( V_2 -> V_9 . V_68 , L_2 , V_73 ) ;
return;
}
F_32 ( & V_2 -> V_74 ) ;
}
static void F_33 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_34 ( V_76 , struct V_1 , V_74 ) ;
struct V_56 * V_57 = & V_2 -> V_9 . V_31 -> V_57 ;
struct V_65 * V_66 = V_2 -> V_67 ;
struct V_77 * V_78 ;
struct V_79 * V_80 = V_2 -> V_81 ;
struct V_82 * V_68 = V_2 -> V_9 . V_68 ;
enum V_83 V_19 ;
unsigned long V_34 ;
int V_84 ;
V_19 = V_80 -> V_82 -> V_85 ( V_80 , ( V_86 ) 0 , NULL ) ;
if ( V_87 == V_19 )
return;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_2 -> V_71 = F_25 ( V_57 ) ;
if ( V_2 -> V_71 == 0 ) {
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return;
}
if ( V_57 -> V_60 > V_57 -> V_88 ) {
V_2 -> V_69 = 2 ;
F_35 ( V_66 , 2 ) ;
F_36 ( V_66 , V_57 -> V_59 + V_57 -> V_60 ,
V_62 - V_57 -> V_60 ) ;
F_36 ( V_66 + 1 , V_57 -> V_59 , V_57 -> V_88 ) ;
} else {
V_2 -> V_69 = 1 ;
F_37 ( V_66 , V_57 -> V_59 + V_57 -> V_60 , V_2 -> V_71 ) ;
}
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_84 = F_38 ( V_68 , V_66 , V_2 -> V_69 , V_70 ) ;
if ( V_84 == 0 ) {
F_39 ( V_68 , L_3 ) ;
return;
}
V_78 = F_40 ( V_80 , V_66 , V_2 -> V_69 ,
V_89 , V_90 ) ;
if ( ! V_78 ) {
F_39 ( V_68 , L_4 ) ;
return;
}
V_78 -> V_91 = F_27 ;
V_78 -> V_92 = V_2 ;
F_29 ( V_68 , L_5 ,
F_25 ( V_57 ) ) ;
V_2 -> V_53 = 1 ;
F_41 ( V_78 ) ;
F_42 ( V_80 ) ;
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
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
F_8 ( V_39 | V_93 , V_2 -> V_9 . V_13 + V_41 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 |= V_94 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
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
F_32 ( & V_2 -> V_74 ) ;
return;
}
if ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_95 )
F_23 ( V_2 ) ;
}
static T_1 F_44 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
unsigned int V_98 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_8 ( V_99 , V_2 -> V_9 . V_13 + V_100 ) ;
V_98 = F_6 ( V_2 -> V_9 . V_13 + V_100 ) & V_101 ;
F_11 ( & V_2 -> V_9 , ! ! V_98 ) ;
F_12 ( & V_2 -> V_9 . V_31 -> V_9 . V_32 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return V_102 ;
}
static T_1 F_45 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
struct V_56 * V_57 = & V_2 -> V_9 . V_31 -> V_57 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( V_2 -> V_9 . V_103 ) {
F_8 ( V_2 -> V_9 . V_103 , V_2 -> V_9 . V_13 + V_61 ) ;
goto V_104;
}
if ( F_24 ( V_57 ) || F_46 ( & V_2 -> V_9 ) ) {
F_17 ( & V_2 -> V_9 ) ;
goto V_104;
}
F_23 ( V_2 ) ;
if ( F_25 ( V_57 ) < V_64 )
F_26 ( & V_2 -> V_9 ) ;
V_104:
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
return V_102 ;
}
static T_1 F_47 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
unsigned int V_105 , V_106 , V_107 = 0 ;
struct V_108 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
unsigned long V_34 , V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
while ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_109 ) {
V_106 = V_110 ;
V_2 -> V_9 . V_25 . V_105 ++ ;
V_105 = F_6 ( V_2 -> V_9 . V_13 + V_48 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
if ( V_39 & V_111 ) {
F_8 ( V_111 , V_2 -> V_9 . V_13 + V_41 ) ;
if ( F_48 ( & V_2 -> V_9 ) )
continue;
}
if ( F_49 ( & V_2 -> V_9 , ( unsigned char ) V_105 ) )
continue;
if ( F_50 ( V_105 & V_112 ) ) {
if ( V_105 & V_113 )
V_2 -> V_9 . V_25 . V_114 ++ ;
else if ( V_105 & V_115 )
V_2 -> V_9 . V_25 . V_116 ++ ;
else if ( V_105 & V_117 )
V_2 -> V_9 . V_25 . V_118 ++ ;
if ( V_105 & V_119 )
V_2 -> V_9 . V_25 . V_120 ++ ;
if ( V_105 & V_2 -> V_9 . V_121 ) {
if ( ++ V_107 > 100 )
goto V_104;
continue;
}
V_105 &= V_2 -> V_9 . V_122 ;
if ( V_105 & V_113 )
V_106 = V_123 ;
else if ( V_105 & V_115 )
V_106 = V_124 ;
else if ( V_105 & V_117 )
V_106 = V_125 ;
if ( V_105 & V_119 )
V_106 = V_126 ;
#ifdef F_51
V_2 -> V_9 . V_127 = 0 ;
#endif
}
F_52 ( V_9 , V_105 , V_106 ) ;
}
V_104:
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_53 ( V_9 ) ;
return V_102 ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
if ( ( V_39 & V_109 ) && ! V_2 -> V_54 ) {
V_2 -> V_54 = 1 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_50 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_32 ( & V_2 -> V_128 ) ;
}
}
static T_1 F_55 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
unsigned int V_129 ;
unsigned int V_130 ;
V_129 = F_6 ( V_2 -> V_9 . V_13 + V_100 ) ;
if ( V_129 & V_131 ) {
if ( V_2 -> V_52 )
F_54 ( V_2 ) ;
else
F_47 ( V_96 , V_97 ) ;
}
if ( V_129 & V_132 &&
F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_44 )
F_45 ( V_96 , V_97 ) ;
if ( V_129 & V_99 )
F_44 ( V_96 , V_97 ) ;
if ( V_129 & V_133 )
F_8 ( V_133 , V_2 -> V_9 . V_13 + V_100 ) ;
V_130 = F_6 ( V_2 -> V_9 . V_13 + V_41 ) ;
if ( V_130 & V_93 ) {
F_39 ( V_2 -> V_9 . V_68 , L_6 ) ;
V_2 -> V_9 . V_25 . V_120 ++ ;
F_8 ( V_130 | V_93 , V_2 -> V_9 . V_13 + V_41 ) ;
}
return V_102 ;
}
static unsigned int F_56 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) ? V_134 : 0 ;
}
static unsigned int F_57 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned int V_135 = V_27 | V_29 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_100 ) & V_101 )
V_135 |= V_30 ;
if ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_136 )
V_135 |= V_137 ;
return V_135 ;
}
static void F_58 ( struct V_8 * V_9 , unsigned int V_138 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) & ~ V_136 ;
if ( V_138 & V_137 )
if ( ! V_2 -> V_52 )
V_39 |= V_136 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
}
static void F_59 ( struct V_8 * V_9 , int V_139 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 , V_39 ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) & ~ V_140 ;
if ( V_139 != 0 )
V_39 |= V_140 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_141 )
{
unsigned int V_98 ;
V_98 = F_6 ( V_2 -> V_9 . V_13 + V_142 ) & ( V_143 | V_144 ) ;
V_98 |= V_145 << V_146 | V_147 ;
F_8 ( V_98 , V_2 -> V_9 . V_13 + V_142 ) ;
return 0 ;
}
static void F_61 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_34 ( V_76 , struct V_1 , V_128 ) ;
struct V_108 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
if ( V_2 -> V_148 ) {
F_62 ( V_9 , V_2 -> V_149 , V_2 -> V_148 ) ;
F_53 ( V_9 ) ;
V_2 -> V_148 = 0 ;
}
if ( V_2 -> V_54 )
F_63 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_50 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_2 -> V_54 = 0 ;
if ( F_30 ( & V_2 -> V_72 ) )
F_31 ( & V_2 -> V_72 ) ;
}
static void F_65 ( void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_79 * V_80 = V_2 -> V_150 ;
struct V_65 * V_66 = & V_2 -> V_151 ;
struct V_152 V_31 ;
enum V_83 V_19 ;
unsigned int V_153 ;
F_28 ( V_2 -> V_9 . V_68 , V_66 , 1 , V_154 ) ;
V_19 = V_80 -> V_82 -> V_85 ( V_80 , ( V_86 ) 0 , & V_31 ) ;
V_153 = V_155 - V_31 . V_156 ;
F_29 ( V_2 -> V_9 . V_68 , L_7 , V_153 ) ;
if ( V_153 ) {
V_2 -> V_148 = V_153 ;
F_32 ( & V_2 -> V_128 ) ;
} else
F_64 ( V_2 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = & V_2 -> V_151 ;
struct V_79 * V_80 = V_2 -> V_150 ;
struct V_82 * V_68 = V_2 -> V_9 . V_68 ;
struct V_77 * V_78 ;
int V_84 ;
F_37 ( V_66 , V_2 -> V_149 , V_155 ) ;
V_84 = F_38 ( V_68 , V_66 , 1 , V_154 ) ;
if ( V_84 == 0 ) {
F_39 ( V_68 , L_8 ) ;
return - V_157 ;
}
V_78 = F_40 ( V_80 , V_66 , 1 , V_158 ,
V_90 ) ;
if ( ! V_78 ) {
F_39 ( V_68 , L_9 ) ;
return - V_157 ;
}
V_78 -> V_91 = F_65 ;
V_78 -> V_92 = V_2 ;
F_29 ( V_68 , L_10 ) ;
F_41 ( V_78 ) ;
F_42 ( V_80 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_150 ) {
F_67 ( V_2 -> V_150 ) ;
V_2 -> V_150 = NULL ;
F_68 ( V_2 -> V_149 ) ;
V_2 -> V_149 = NULL ;
}
if ( V_2 -> V_81 ) {
F_67 ( V_2 -> V_81 ) ;
V_2 -> V_81 = NULL ;
}
V_2 -> V_159 = 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_160 V_161 = {} ;
struct V_82 * V_68 = V_2 -> V_9 . V_68 ;
int V_84 ;
V_2 -> V_150 = F_70 ( V_68 , L_11 ) ;
if ( ! V_2 -> V_150 ) {
F_29 ( V_68 , L_12 ) ;
V_84 = - V_157 ;
goto V_162;
}
V_161 . V_163 = V_158 ;
V_161 . V_164 = V_2 -> V_9 . V_165 + V_48 ;
V_161 . V_166 = V_167 ;
V_161 . V_168 = V_147 ;
V_84 = F_71 ( V_2 -> V_150 , & V_161 ) ;
if ( V_84 ) {
F_39 ( V_68 , L_13 ) ;
goto V_162;
}
V_2 -> V_149 = F_72 ( V_169 , V_170 ) ;
if ( ! V_2 -> V_149 ) {
F_39 ( V_68 , L_14 ) ;
V_84 = - V_171 ;
goto V_162;
}
V_2 -> V_148 = 0 ;
V_2 -> V_81 = F_70 ( V_68 , L_15 ) ;
if ( ! V_2 -> V_81 ) {
F_39 ( V_68 , L_16 ) ;
V_84 = - V_157 ;
goto V_162;
}
V_161 . V_163 = V_89 ;
V_161 . V_172 = V_2 -> V_9 . V_165 + V_61 ;
V_161 . V_173 = V_167 ;
V_161 . V_174 = V_145 ;
V_84 = F_71 ( V_2 -> V_81 , & V_161 ) ;
if ( V_84 ) {
F_39 ( V_68 , L_17 ) ;
goto V_162;
}
V_2 -> V_159 = 1 ;
return 0 ;
V_162:
F_66 ( V_2 ) ;
return V_84 ;
}
static void F_73 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_108 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
V_9 -> V_175 = 1 ;
F_74 ( & V_2 -> V_74 , F_33 ) ;
F_74 ( & V_2 -> V_128 , F_61 ) ;
F_75 ( & V_2 -> V_72 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_176 | V_177 | V_178 |
F_76 ( 3 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 |= V_179 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
V_2 -> V_52 = 1 ;
}
static void F_77 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_108 * V_9 = & V_2 -> V_9 . V_31 -> V_9 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_176 | V_177 | V_178 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_180 | V_136 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
V_39 &= ~ V_179 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_46 ) ;
V_2 -> V_52 = 0 ;
V_9 -> V_175 = 0 ;
}
static int F_78 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_181 ;
unsigned long V_34 , V_39 ;
V_181 = F_79 ( V_2 -> V_182 ) ;
if ( V_181 )
goto V_183;
V_181 = F_79 ( V_2 -> V_184 ) ;
if ( V_181 ) {
F_80 ( V_2 -> V_182 ) ;
goto V_183;
}
F_60 ( V_2 , 0 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
if ( F_18 ( V_2 ) )
V_39 |= V_185 ;
V_39 &= ~ ( V_186 << V_187 ) ;
V_39 |= V_188 << V_187 ;
F_8 ( V_39 & ~ V_51 , V_2 -> V_9 . V_13 + V_46 ) ;
if ( F_18 ( V_2 ) ) {
int V_189 = 100 ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ V_190 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_16 ) & V_190 ) &&
( -- V_189 > 0 ) ) {
F_19 ( 1 ) ;
}
}
if ( V_2 -> V_191 > 0 ) {
V_181 = F_81 ( V_2 -> V_192 , F_47 , 0 ,
V_193 , V_2 ) ;
if ( V_181 )
goto V_183;
V_181 = F_81 ( V_2 -> V_191 , F_45 , 0 ,
V_193 , V_2 ) ;
if ( V_181 )
goto V_194;
if ( ! F_18 ( V_2 ) ) {
V_181 = F_81 ( V_2 -> V_195 , F_44 , 0 ,
V_193 , V_2 ) ;
if ( V_181 )
goto V_196;
}
} else {
V_181 = F_81 ( V_2 -> V_9 . V_96 , F_55 , 0 ,
V_193 , V_2 ) ;
if ( V_181 ) {
F_82 ( V_2 -> V_9 . V_96 , V_2 ) ;
goto V_183;
}
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_8 ( V_99 , V_2 -> V_9 . V_13 + V_100 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 |= V_50 | V_197 | V_198 ;
if ( F_18 ( V_2 ) ) {
V_39 |= V_199 ;
V_39 &= ~ ( V_197 ) ;
}
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 |= ( V_55 | V_200 ) ;
if ( ! V_2 -> V_201 )
V_39 |= V_202 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( F_18 ( V_2 ) ) {
int V_189 = 64 ;
while ( ( -- V_189 > 0 ) &&
( F_6 ( V_2 -> V_9 . V_13 + V_48 ) & V_49 ) ) {
F_20 () ;
}
}
if ( ! F_2 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_39 |= V_203 ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_18 ) ;
}
if ( F_18 ( V_2 ) ) {
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_46 ) ;
if ( V_2 -> V_204 )
V_39 |= V_205 ;
else
V_39 &= ~ ( V_205 ) ;
F_8 ( V_39 | V_51 , V_2 -> V_9 . V_13 + V_46 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
if ( V_2 -> V_206 )
V_39 |= V_207 ;
else
V_39 &= ~ ( V_207 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_18 ) ;
}
F_22 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( F_18 ( V_2 ) ) {
struct V_208 * V_209 ;
V_209 = F_83 ( V_2 -> V_9 . V_68 ) ;
V_2 -> V_204 = V_209 -> V_204 ;
V_2 -> V_206 = V_209 -> V_206 ;
V_2 -> V_43 = V_209 -> V_210 ;
if ( V_209 -> V_211 )
V_209 -> V_211 ( 1 ) ;
}
return 0 ;
V_196:
if ( V_2 -> V_191 )
F_82 ( V_2 -> V_191 , V_2 ) ;
V_194:
if ( V_2 -> V_192 )
F_82 ( V_2 -> V_192 , V_2 ) ;
V_183:
return V_181 ;
}
static void F_84 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_39 ;
unsigned long V_34 ;
if ( V_2 -> V_52 ) {
F_85 ( V_2 -> V_72 ,
! V_2 -> V_54 && ! V_2 -> V_53 ) ;
F_21 ( V_9 ) ;
F_77 ( V_2 ) ;
F_66 ( V_2 ) ;
}
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
V_39 &= ~ ( V_200 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_16 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
if ( F_18 ( V_2 ) ) {
struct V_208 * V_209 ;
V_209 = F_83 ( V_2 -> V_9 . V_68 ) ;
if ( V_209 -> V_211 )
V_209 -> V_211 ( 0 ) ;
}
F_86 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_191 > 0 ) {
if ( ! F_18 ( V_2 ) )
F_82 ( V_2 -> V_195 , V_2 ) ;
F_82 ( V_2 -> V_191 , V_2 ) ;
F_82 ( V_2 -> V_192 , V_2 ) ;
} else
F_82 ( V_2 -> V_9 . V_96 , V_2 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_39 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
V_39 &= ~ ( V_44 | V_50 | V_197 | V_198 ) ;
if ( F_18 ( V_2 ) )
V_39 &= ~ ( V_199 ) ;
F_8 ( V_39 , V_2 -> V_9 . V_13 + V_14 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_80 ( V_2 -> V_182 ) ;
F_80 ( V_2 -> V_184 ) ;
}
static void
F_87 ( struct V_8 * V_9 , struct V_212 * V_213 ,
struct V_212 * V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_34 ;
unsigned int V_15 , V_215 , V_216 , V_217 , V_218 ;
unsigned int V_219 = V_214 ? V_214 -> V_220 & V_221 : V_222 ;
unsigned int div , V_223 ;
unsigned long V_224 , V_225 ;
T_2 V_226 ;
if ( 0 ) {
V_213 -> V_220 &= ~ ( V_227 | V_228 | V_229 ) ;
V_213 -> V_220 |= V_230 ;
}
while ( ( V_213 -> V_220 & V_221 ) != V_231 &&
( V_213 -> V_220 & V_221 ) != V_222 ) {
V_213 -> V_220 &= ~ V_221 ;
V_213 -> V_220 |= V_219 ;
V_219 = V_222 ;
}
if ( ( V_213 -> V_220 & V_221 ) == V_222 )
V_15 = V_232 | V_190 | V_202 ;
else
V_15 = V_190 | V_202 ;
if ( V_213 -> V_220 & V_228 ) {
if ( V_2 -> V_201 ) {
V_15 &= ~ V_202 ;
V_15 |= V_180 ;
if ( F_4 ( V_2 ) && ! F_88 ( V_9 )
&& ! V_2 -> V_159 )
F_69 ( V_2 ) ;
} else {
V_213 -> V_220 &= ~ V_228 ;
}
}
if ( V_213 -> V_220 & V_233 )
V_15 |= V_234 ;
if ( V_213 -> V_220 & V_235 ) {
V_15 |= V_236 ;
if ( V_213 -> V_220 & V_237 )
V_15 |= V_238 ;
}
F_86 ( & V_2 -> V_36 ) ;
V_217 = F_89 ( V_9 , V_213 , V_214 , 50 , V_9 -> V_239 / 16 ) ;
V_218 = F_90 ( V_9 , V_217 ) ;
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
V_2 -> V_9 . V_122 = 0 ;
if ( V_213 -> V_240 & V_241 )
V_2 -> V_9 . V_122 |= ( V_117 | V_115 ) ;
if ( V_213 -> V_240 & ( V_242 | V_243 ) )
V_2 -> V_9 . V_122 |= V_113 ;
V_2 -> V_9 . V_121 = 0 ;
if ( V_213 -> V_240 & V_244 )
V_2 -> V_9 . V_121 |= V_115 ;
if ( V_213 -> V_240 & V_245 ) {
V_2 -> V_9 . V_121 |= V_113 ;
if ( V_213 -> V_240 & V_244 )
V_2 -> V_9 . V_121 |= V_119 ;
}
F_91 ( V_9 , V_213 -> V_220 , V_217 ) ;
V_215 = F_6 ( V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_215 & ~ ( V_44 | V_50 | V_197 ) ,
V_2 -> V_9 . V_13 + V_14 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) )
F_20 () ;
V_216 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
F_8 ( V_216 & ~ ( V_200 | V_55 ) ,
V_2 -> V_9 . V_13 + V_16 ) ;
V_216 &= ( V_200 | V_55 ) ;
if ( F_18 ( V_2 ) ) {
div = 1 ;
} else {
div = V_2 -> V_9 . V_239 / ( V_217 * 16 ) ;
if ( V_217 == 38400 && V_218 != div )
V_217 = V_2 -> V_9 . V_239 / ( V_218 * 16 ) ;
div = V_2 -> V_9 . V_239 / ( V_217 * 16 ) ;
if ( div > 7 )
div = 7 ;
if ( ! div )
div = 1 ;
}
F_92 ( 16 * div * V_217 , V_2 -> V_9 . V_239 ,
1 << 16 , 1 << 16 , & V_224 , & V_225 ) ;
V_226 = V_2 -> V_9 . V_239 ;
V_226 *= V_224 ;
F_93 ( V_226 , V_225 * 16 * div ) ;
F_94 ( V_213 ,
( V_246 ) V_226 , ( V_246 ) V_226 ) ;
V_224 -= 1 ;
V_225 -= 1 ;
V_223 = F_6 ( V_2 -> V_9 . V_13 + V_142 ) ;
V_223 = ( V_223 & ( ~ V_143 ) ) | F_95 ( div ) ;
if ( V_2 -> V_247 )
V_223 |= V_144 ;
F_8 ( V_223 , V_2 -> V_9 . V_13 + V_142 ) ;
F_8 ( V_224 , V_2 -> V_9 . V_13 + V_248 ) ;
F_8 ( V_225 , V_2 -> V_9 . V_13 + V_249 ) ;
if ( ! F_2 ( V_2 ) )
F_8 ( V_2 -> V_9 . V_239 / div / 1000 ,
V_2 -> V_9 . V_13 + V_250 ) ;
F_8 ( V_215 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_15 | V_216 , V_2 -> V_9 . V_13 + V_16 ) ;
if ( F_96 ( & V_2 -> V_9 , V_213 -> V_220 ) )
F_22 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_159 && ! V_2 -> V_52 )
F_73 ( V_2 ) ;
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
}
static const char * F_97 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
return V_2 -> V_9 . type == V_251 ? L_18 : NULL ;
}
static void F_98 ( struct V_8 * V_9 )
{
struct V_252 * V_253 = F_99 ( V_9 -> V_68 ) ;
struct V_254 * V_255 ;
V_255 = F_100 ( V_253 , V_256 , 0 ) ;
F_101 ( V_255 -> V_257 , F_102 ( V_255 ) ) ;
}
static int F_103 ( struct V_8 * V_9 )
{
struct V_252 * V_253 = F_99 ( V_9 -> V_68 ) ;
struct V_254 * V_255 ;
void * V_84 ;
V_255 = F_100 ( V_253 , V_256 , 0 ) ;
if ( ! V_255 )
return - V_258 ;
V_84 = F_104 ( V_255 -> V_257 , F_102 ( V_255 ) , L_19 ) ;
return V_84 ? 0 : - V_259 ;
}
static void F_105 ( struct V_8 * V_9 , int V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( V_34 & V_260 &&
F_103 ( & V_2 -> V_9 ) == 0 )
V_2 -> V_9 . type = V_251 ;
}
static int
F_106 ( struct V_8 * V_9 , struct V_261 * V_262 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
int V_84 = 0 ;
if ( V_262 -> type != V_263 && V_262 -> type != V_251 )
V_84 = - V_157 ;
if ( V_2 -> V_9 . V_96 != V_262 -> V_96 )
V_84 = - V_157 ;
if ( V_262 -> V_264 != V_265 )
V_84 = - V_157 ;
if ( V_2 -> V_9 . V_239 / 16 != V_262 -> V_266 )
V_84 = - V_157 ;
if ( ( void * ) V_2 -> V_9 . V_165 != V_262 -> V_267 )
V_84 = - V_157 ;
if ( V_2 -> V_9 . V_268 != V_262 -> V_9 )
V_84 = - V_157 ;
if ( V_262 -> V_269 != 0 )
V_84 = - V_157 ;
return V_84 ;
}
static int F_107 ( struct V_8 * V_9 )
{
struct V_10 V_270 ;
unsigned int V_19 ;
unsigned char V_271 ;
F_5 ( V_9 , & V_270 ) ;
F_8 ( V_198 , V_9 -> V_13 + V_14 ) ;
F_8 ( V_270 . V_15 & ~ ( V_272 | V_273 | V_274 ) ,
V_9 -> V_13 + V_16 ) ;
F_8 ( V_270 . V_17 & ~ ( V_275 | V_276 | V_277 ) ,
V_9 -> V_13 + V_18 ) ;
do {
V_19 = F_6 ( V_9 -> V_13 + V_41 ) ;
} while ( ~ V_19 & V_109 );
V_271 = F_6 ( V_9 -> V_13 + V_48 ) ;
F_7 ( V_9 , & V_270 ) ;
return V_271 ;
}
static void F_108 ( struct V_8 * V_9 , unsigned char V_271 )
{
struct V_10 V_270 ;
unsigned int V_19 ;
F_5 ( V_9 , & V_270 ) ;
F_8 ( V_198 , V_9 -> V_13 + V_14 ) ;
F_8 ( V_270 . V_15 & ~ ( V_272 | V_273 | V_274 ) ,
V_9 -> V_13 + V_16 ) ;
F_8 ( V_270 . V_17 & ~ ( V_275 | V_276 | V_277 ) ,
V_9 -> V_13 + V_18 ) ;
do {
V_19 = F_6 ( V_9 -> V_13 + V_100 ) ;
} while ( ~ V_19 & V_132 );
F_8 ( V_271 , V_9 -> V_13 + V_61 ) ;
do {
V_19 = F_6 ( V_9 -> V_13 + V_41 ) ;
} while ( ~ V_19 & V_42 );
F_7 ( V_9 , & V_270 ) ;
}
static void F_109 ( struct V_8 * V_9 , int V_278 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
while ( F_6 ( V_2 -> V_9 . V_13 + F_1 ( V_2 ) ) & V_58 )
F_20 () ;
F_8 ( V_278 , V_2 -> V_9 . V_13 + V_61 ) ;
}
static void
F_110 ( struct V_279 * V_280 , const char * V_281 , unsigned int V_153 )
{
struct V_1 * V_2 = V_282 [ V_280 -> V_283 ] ;
struct V_10 V_270 ;
unsigned int V_12 ;
unsigned long V_34 = 0 ;
int V_284 = 1 ;
int V_181 ;
V_181 = F_111 ( V_2 -> V_182 ) ;
if ( V_181 )
return;
V_181 = F_111 ( V_2 -> V_184 ) ;
if ( V_181 ) {
F_112 ( V_2 -> V_182 ) ;
return;
}
if ( V_2 -> V_9 . V_127 )
V_284 = 0 ;
else if ( V_285 )
V_284 = F_113 ( & V_2 -> V_9 . V_35 , V_34 ) ;
else
F_14 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_5 ( & V_2 -> V_9 , & V_270 ) ;
V_12 = V_270 . V_12 ;
if ( F_2 ( V_2 ) )
V_12 |= V_286 ;
V_12 |= V_198 ;
V_12 &= ~ ( V_44 | V_50 | V_197 ) ;
F_8 ( V_12 , V_2 -> V_9 . V_13 + V_14 ) ;
F_8 ( V_270 . V_15 | V_200 , V_2 -> V_9 . V_13 + V_16 ) ;
F_114 ( & V_2 -> V_9 , V_281 , V_153 , F_109 ) ;
while ( ! ( F_6 ( V_2 -> V_9 . V_13 + V_41 ) & V_42 ) ) ;
F_7 ( & V_2 -> V_9 , & V_270 ) ;
if ( V_284 )
F_15 ( & V_2 -> V_9 . V_35 , V_34 ) ;
F_112 ( V_2 -> V_184 ) ;
F_112 ( V_2 -> V_182 ) ;
}
static void T_3
F_115 ( struct V_1 * V_2 , int * V_217 ,
int * V_116 , int * V_287 )
{
if ( F_6 ( V_2 -> V_9 . V_13 + V_14 ) & V_198 ) {
unsigned int V_15 , V_288 , V_289 , V_239 ;
unsigned int V_290 ;
unsigned int V_291 ;
V_15 = F_6 ( V_2 -> V_9 . V_13 + V_16 ) ;
* V_116 = 'n' ;
if ( V_15 & V_236 ) {
if ( V_15 & V_238 )
* V_116 = 'o' ;
else
* V_116 = 'e' ;
}
if ( V_15 & V_232 )
* V_287 = 8 ;
else
* V_287 = 7 ;
V_288 = F_6 ( V_2 -> V_9 . V_13 + V_248 ) & 0xffff ;
V_289 = F_6 ( V_2 -> V_9 . V_13 + V_249 ) & 0xffff ;
V_291 = ( F_6 ( V_2 -> V_9 . V_13 + V_142 ) & V_143 ) >> 7 ;
if ( V_291 == 6 )
V_291 = 7 ;
else
V_291 = 6 - V_291 ;
V_239 = F_116 ( V_2 -> V_182 ) ;
V_239 /= V_291 ;
{
unsigned int V_292 = V_288 + 1 ;
unsigned int div = 16 * ( V_289 + 1 ) ;
unsigned int V_293 = V_239 % div ;
V_290 = ( V_239 / div ) * V_292 ;
V_290 += ( V_293 * V_292 + div / 2 ) / div ;
* V_217 = ( V_290 + 50 ) / 100 * 100 ;
}
if ( * V_217 != V_290 )
F_117 ( L_20 ,
V_290 , * V_217 ) ;
}
}
static int T_3
F_118 ( struct V_279 * V_280 , char * V_294 )
{
struct V_1 * V_2 ;
int V_217 = 9600 ;
int V_287 = 8 ;
int V_116 = 'n' ;
int V_295 = 'n' ;
int V_181 ;
if ( V_280 -> V_283 == - 1 || V_280 -> V_283 >= F_119 ( V_282 ) )
V_280 -> V_283 = 0 ;
V_2 = V_282 [ V_280 -> V_283 ] ;
if ( V_2 == NULL )
return - V_258 ;
V_181 = F_79 ( V_2 -> V_184 ) ;
if ( V_181 )
goto V_296;
if ( V_294 )
F_120 ( V_294 , & V_217 , & V_116 , & V_287 , & V_295 ) ;
else
F_115 ( V_2 , & V_217 , & V_116 , & V_287 ) ;
F_60 ( V_2 , 0 ) ;
V_181 = F_121 ( & V_2 -> V_9 , V_280 , V_217 , V_116 , V_287 , V_295 ) ;
F_112 ( V_2 -> V_184 ) ;
if ( V_181 ) {
F_122 ( V_2 -> V_184 ) ;
goto V_296;
}
V_181 = F_123 ( V_2 -> V_182 ) ;
if ( V_181 )
F_80 ( V_2 -> V_184 ) ;
V_296:
return V_181 ;
}
static int F_124 ( struct V_252 * V_68 , T_4 V_31 )
{
struct V_1 * V_2 = F_125 ( V_68 ) ;
unsigned int V_98 ;
V_98 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_98 |= V_297 ;
F_8 ( V_98 , V_2 -> V_9 . V_13 + V_18 ) ;
F_126 ( & V_298 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_127 ( struct V_252 * V_68 )
{
struct V_1 * V_2 = F_125 ( V_68 ) ;
unsigned int V_98 ;
V_98 = F_6 ( V_2 -> V_9 . V_13 + V_18 ) ;
V_98 &= ~ V_297 ;
F_8 ( V_98 , V_2 -> V_9 . V_13 + V_18 ) ;
F_128 ( & V_298 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_299 * V_300 = V_253 -> V_68 . V_301 ;
const struct V_302 * V_303 =
F_130 ( V_304 , & V_253 -> V_68 ) ;
int V_84 ;
if ( ! V_300 )
return 1 ;
V_84 = F_131 ( V_300 , L_21 ) ;
if ( V_84 < 0 ) {
F_39 ( & V_253 -> V_68 , L_22 , V_84 ) ;
return V_84 ;
}
V_2 -> V_9 . line = V_84 ;
if ( F_132 ( V_300 , L_23 , NULL ) )
V_2 -> V_201 = 1 ;
if ( F_132 ( V_300 , L_24 , NULL ) )
V_2 -> V_305 = 1 ;
if ( F_132 ( V_300 , L_25 , NULL ) )
V_2 -> V_247 = 1 ;
V_2 -> V_3 = V_303 -> V_33 ;
return 0 ;
}
static inline int F_129 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
return 1 ;
}
static void F_133 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_208 * V_209 = F_83 ( & V_253 -> V_68 ) ;
V_2 -> V_9 . line = V_253 -> V_306 ;
V_2 -> V_3 = (struct V_307 * ) V_253 -> V_308 -> V_309 ;
if ( ! V_209 )
return;
if ( V_209 -> V_34 & V_310 )
V_2 -> V_201 = 1 ;
if ( V_209 -> V_34 & V_311 )
V_2 -> V_305 = 1 ;
}
static int F_134 ( struct V_252 * V_253 )
{
struct V_1 * V_2 ;
struct V_208 * V_209 ;
void T_5 * V_312 ;
int V_84 = 0 ;
struct V_254 * V_313 ;
V_2 = F_135 ( & V_253 -> V_68 , sizeof( * V_2 ) , V_170 ) ;
if ( ! V_2 )
return - V_171 ;
V_84 = F_129 ( V_2 , V_253 ) ;
if ( V_84 > 0 )
F_133 ( V_2 , V_253 ) ;
else if ( V_84 < 0 )
return V_84 ;
V_313 = F_100 ( V_253 , V_256 , 0 ) ;
if ( ! V_313 )
return - V_258 ;
V_312 = F_136 ( & V_253 -> V_68 , V_313 -> V_257 , V_169 ) ;
if ( ! V_312 )
return - V_171 ;
V_2 -> V_9 . V_68 = & V_253 -> V_68 ;
V_2 -> V_9 . V_165 = V_313 -> V_257 ;
V_2 -> V_9 . V_13 = V_312 ;
V_2 -> V_9 . type = V_251 ,
V_2 -> V_9 . V_314 = V_265 ;
V_2 -> V_9 . V_96 = F_137 ( V_253 , 0 ) ;
V_2 -> V_192 = F_137 ( V_253 , 0 ) ;
V_2 -> V_191 = F_137 ( V_253 , 1 ) ;
V_2 -> V_195 = F_137 ( V_253 , 2 ) ;
V_2 -> V_9 . V_315 = 32 ;
V_2 -> V_9 . V_21 = & V_316 ;
V_2 -> V_9 . V_34 = V_317 ;
F_138 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_318 = F_13 ;
V_2 -> V_36 . V_33 = ( unsigned long ) V_2 ;
V_2 -> V_184 = F_139 ( & V_253 -> V_68 , L_26 ) ;
if ( F_140 ( V_2 -> V_184 ) ) {
V_84 = F_141 ( V_2 -> V_184 ) ;
F_39 ( & V_253 -> V_68 , L_27 , V_84 ) ;
return V_84 ;
}
V_2 -> V_182 = F_139 ( & V_253 -> V_68 , L_28 ) ;
if ( F_140 ( V_2 -> V_182 ) ) {
V_84 = F_141 ( V_2 -> V_182 ) ;
F_39 ( & V_253 -> V_68 , L_29 , V_84 ) ;
return V_84 ;
}
V_2 -> V_9 . V_239 = F_116 ( V_2 -> V_182 ) ;
V_282 [ V_2 -> V_9 . line ] = V_2 ;
V_209 = F_83 ( & V_253 -> V_68 ) ;
if ( V_209 && V_209 -> V_319 ) {
V_84 = V_209 -> V_319 ( V_253 ) ;
if ( V_84 )
return V_84 ;
}
V_84 = F_142 ( & V_298 , & V_2 -> V_9 ) ;
if ( V_84 )
goto V_320;
F_143 ( V_253 , V_2 ) ;
return 0 ;
V_320:
if ( V_209 && V_209 -> exit )
V_209 -> exit ( V_253 ) ;
return V_84 ;
}
static int F_144 ( struct V_252 * V_253 )
{
struct V_208 * V_209 ;
struct V_1 * V_2 = F_125 ( V_253 ) ;
V_209 = F_83 ( & V_253 -> V_68 ) ;
F_145 ( & V_298 , & V_2 -> V_9 ) ;
if ( V_209 && V_209 -> exit )
V_209 -> exit ( V_253 ) ;
return 0 ;
}
static int T_3 F_146 ( void )
{
int V_84 ;
F_117 ( L_30 ) ;
V_84 = F_147 ( & V_298 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_148 ( & V_321 ) ;
if ( V_84 != 0 )
F_149 ( & V_298 ) ;
return V_84 ;
}
static void T_6 F_150 ( void )
{
F_151 ( & V_321 ) ;
F_149 ( & V_298 ) ;
}
