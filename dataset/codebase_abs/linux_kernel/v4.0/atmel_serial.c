static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static bool F_3 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
return V_5 -> V_6 ;
}
static bool F_4 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
return V_5 -> V_7 ;
}
static bool F_3 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_4 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_5 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
return V_5 -> V_8 ;
}
static bool F_6 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
return V_5 -> V_9 ;
}
static unsigned int F_7 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_11 = 0 ;
V_10 = F_8 ( V_4 ) ;
F_9 ( V_5 -> V_12 , & V_11 ) ;
if ( ! F_10 ( F_11 ( V_5 -> V_12 ,
V_13 ) ) ) {
if ( V_11 & V_14 )
V_10 &= ~ V_15 ;
else
V_10 |= V_15 ;
}
if ( ! F_10 ( F_11 ( V_5 -> V_12 ,
V_16 ) ) ) {
if ( V_11 & V_17 )
V_10 &= ~ V_18 ;
else
V_10 |= V_18 ;
}
if ( ! F_10 ( F_11 ( V_5 -> V_12 ,
V_19 ) ) ) {
if ( V_11 & V_20 )
V_10 &= ~ V_21 ;
else
V_10 |= V_21 ;
}
if ( ! F_10 ( F_11 ( V_5 -> V_12 ,
V_22 ) ) ) {
if ( V_11 & V_23 )
V_10 &= ~ V_24 ;
else
V_10 |= V_24 ;
}
return V_10 ;
}
static int F_12 ( struct V_2 * V_4 ,
struct V_25 * V_26 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_27 ;
F_13 ( V_4 , V_5 -> V_28 ) ;
V_27 = F_14 ( V_4 ) ;
V_27 &= ~ V_29 ;
V_4 -> V_30 = * V_26 ;
if ( V_26 -> V_31 & V_32 ) {
F_15 ( V_4 -> V_33 , L_1 ) ;
V_5 -> V_28 = V_34 ;
if ( ( V_26 -> V_35 ) > 0 )
F_16 ( V_4 , V_26 -> V_35 ) ;
V_27 |= V_36 ;
} else {
F_15 ( V_4 -> V_33 , L_2 ) ;
if ( F_4 ( V_4 ) )
V_5 -> V_28 = V_37 |
V_38 ;
else
V_5 -> V_28 = V_39 ;
}
F_17 ( V_4 , V_27 ) ;
F_18 ( V_4 , V_5 -> V_28 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_2 * V_4 )
{
return ( F_8 ( V_4 ) & V_34 ) ? V_40 : 0 ;
}
static void F_20 ( struct V_2 * V_4 , T_1 V_41 )
{
unsigned int V_42 = 0 ;
unsigned int V_27 = F_14 ( V_4 ) ;
unsigned int V_43 , V_44 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_30 . V_31 & V_32 ) {
if ( ( V_4 -> V_30 . V_35 ) > 0 )
F_16 ( V_4 , V_4 -> V_30 . V_35 ) ;
V_27 &= ~ V_29 ;
V_27 |= V_36 ;
}
if ( ( V_27 & V_29 ) == V_45 ) {
V_43 = V_46 ;
V_44 = V_47 ;
} else {
V_43 = V_47 ;
V_44 = V_46 ;
}
if ( V_41 & V_48 )
V_42 |= V_44 ;
else
V_42 |= V_43 ;
if ( V_41 & V_49 )
V_42 |= V_50 ;
else
V_42 |= V_51 ;
F_21 ( V_4 , V_42 ) ;
F_22 ( V_5 -> V_12 , V_41 ) ;
V_27 &= ~ V_52 ;
if ( V_41 & V_53 )
V_27 |= V_54 ;
else
V_27 |= V_55 ;
F_17 ( V_4 , V_27 ) ;
}
static T_1 F_23 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_11 = 0 , V_10 ;
V_10 = F_8 ( V_4 ) ;
if ( ! ( V_10 & V_24 ) )
V_11 |= V_23 ;
if ( ! ( V_10 & V_15 ) )
V_11 |= V_14 ;
if ( ! ( V_10 & V_18 ) )
V_11 |= V_17 ;
if ( ! ( V_10 & V_21 ) )
V_11 |= V_20 ;
return F_9 ( V_5 -> V_12 , & V_11 ) ;
}
static void F_24 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_25 ( V_4 , V_56 ) ;
}
F_13 ( V_4 , V_5 -> V_28 ) ;
if ( ( V_4 -> V_30 . V_31 & V_32 ) &&
! ( V_4 -> V_30 . V_31 & V_57 ) )
F_26 ( V_4 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
if ( F_28 ( V_4 ) & V_58 )
return;
if ( ( V_4 -> V_30 . V_31 & V_32 ) &&
! ( V_4 -> V_30 . V_31 & V_57 ) )
F_29 ( V_4 ) ;
F_25 ( V_4 , V_58 ) ;
}
F_18 ( V_4 , V_5 -> V_28 ) ;
}
static void F_26 ( struct V_2 * V_4 )
{
F_21 ( V_4 , V_59 ) ;
F_21 ( V_4 , V_60 ) ;
if ( F_3 ( V_4 ) ) {
F_18 ( V_4 , V_61 | V_62 |
V_4 -> V_63 ) ;
F_25 ( V_4 , V_64 ) ;
} else {
F_18 ( V_4 , V_65 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
F_21 ( V_4 , V_66 ) ;
if ( F_3 ( V_4 ) ) {
F_25 ( V_4 , V_67 ) ;
F_13 ( V_4 , V_61 | V_62 |
V_4 -> V_63 ) ;
} else {
F_13 ( V_4 , V_65 ) ;
}
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_68 = 0 ;
if ( V_5 -> V_69 )
return;
V_5 -> V_69 = true ;
if ( V_5 -> V_70 [ V_13 ] >= 0 )
F_31 ( V_5 -> V_70 [ V_13 ] ) ;
else
V_68 |= V_71 ;
if ( V_5 -> V_70 [ V_16 ] >= 0 )
F_31 ( V_5 -> V_70 [ V_16 ] ) ;
else
V_68 |= V_72 ;
if ( V_5 -> V_70 [ V_19 ] >= 0 )
F_31 ( V_5 -> V_70 [ V_19 ] ) ;
else
V_68 |= V_73 ;
if ( V_5 -> V_70 [ V_22 ] >= 0 )
F_31 ( V_5 -> V_70 [ V_22 ] ) ;
else
V_68 |= V_74 ;
F_18 ( V_4 , V_68 ) ;
}
static void F_32 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_75 = 0 ;
if ( ! V_5 -> V_69 )
return;
V_5 -> V_69 = false ;
if ( V_5 -> V_70 [ V_13 ] >= 0 )
F_33 ( V_5 -> V_70 [ V_13 ] ) ;
else
V_75 |= V_71 ;
if ( V_5 -> V_70 [ V_16 ] >= 0 )
F_33 ( V_5 -> V_70 [ V_16 ] ) ;
else
V_75 |= V_72 ;
if ( V_5 -> V_70 [ V_19 ] >= 0 )
F_33 ( V_5 -> V_70 [ V_19 ] ) ;
else
V_75 |= V_73 ;
if ( V_5 -> V_70 [ V_22 ] >= 0 )
F_33 ( V_5 -> V_70 [ V_22 ] ) ;
else
V_75 |= V_74 ;
F_13 ( V_4 , V_75 ) ;
}
static void F_34 ( struct V_2 * V_4 , int V_76 )
{
if ( V_76 != 0 )
F_21 ( V_4 , V_77 ) ;
else
F_21 ( V_4 , V_78 ) ;
}
static void
F_35 ( struct V_2 * V_4 , unsigned int V_10 ,
unsigned int V_79 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_80 * V_81 = & V_5 -> V_82 ;
struct V_83 * V_84 ;
if ( ! F_36 ( V_81 -> V_85 , V_81 -> V_86 , V_87 ) )
return;
V_84 = & ( (struct V_83 * ) V_81 -> V_88 ) [ V_81 -> V_85 ] ;
V_84 -> V_10 = V_10 ;
V_84 -> V_79 = V_79 ;
F_37 () ;
V_81 -> V_85 = ( V_81 -> V_85 + 1 ) & ( V_87 - 1 ) ;
}
static void F_38 ( struct V_2 * V_4 , unsigned int V_10 )
{
F_21 ( V_4 , V_59 ) ;
if ( V_10 & V_89 ) {
V_10 &= ~ ( V_90 | V_91 ) ;
V_4 -> V_92 . V_93 ++ ;
}
if ( V_10 & V_90 )
V_4 -> V_92 . V_94 ++ ;
if ( V_10 & V_91 )
V_4 -> V_92 . V_95 ++ ;
if ( V_10 & V_96 )
V_4 -> V_92 . V_97 ++ ;
}
static void F_39 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_79 ;
V_10 = F_8 ( V_4 ) ;
while ( V_10 & V_65 ) {
V_79 = F_40 ( V_4 ) ;
if ( F_41 ( V_10 & ( V_90 | V_91
| V_96 | V_89 )
|| V_5 -> V_98 ) ) {
F_21 ( V_4 , V_59 ) ;
if ( V_10 & V_89
&& ! V_5 -> V_98 ) {
V_5 -> V_98 = 1 ;
F_18 ( V_4 , V_89 ) ;
} else {
F_13 ( V_4 , V_89 ) ;
V_10 &= ~ V_89 ;
V_5 -> V_98 = 0 ;
}
}
F_35 ( V_4 , V_10 , V_79 ) ;
V_10 = F_8 ( V_4 ) ;
}
F_42 ( & V_5 -> V_99 ) ;
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_80 * V_100 = & V_4 -> V_101 -> V_100 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_102 && F_8 ( V_4 ) & V_5 -> V_28 ) {
F_44 ( V_4 , V_4 -> V_102 ) ;
V_4 -> V_92 . V_103 ++ ;
V_4 -> V_102 = 0 ;
}
if ( F_45 ( V_100 ) || F_46 ( V_4 ) )
return;
while ( F_8 ( V_4 ) & V_5 -> V_28 ) {
F_44 ( V_4 , V_100 -> V_88 [ V_100 -> V_86 ] ) ;
V_100 -> V_86 = ( V_100 -> V_86 + 1 ) & ( V_104 - 1 ) ;
V_4 -> V_92 . V_103 ++ ;
if ( F_45 ( V_100 ) )
break;
}
if ( F_47 ( V_100 ) < V_105 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_100 ) )
F_18 ( V_4 , V_5 -> V_28 ) ;
}
static void F_49 ( void * V_106 )
{
struct V_1 * V_5 = V_106 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_80 * V_100 = & V_4 -> V_101 -> V_100 ;
struct V_107 * V_108 = V_5 -> V_109 ;
unsigned long V_31 ;
F_50 ( & V_4 -> V_110 , V_31 ) ;
if ( V_108 )
F_51 ( V_108 ) ;
V_100 -> V_86 += F_52 ( & V_5 -> V_111 ) ;
V_100 -> V_86 &= V_104 - 1 ;
V_4 -> V_92 . V_103 += F_52 ( & V_5 -> V_111 ) ;
F_53 ( & V_5 -> V_112 ) ;
F_54 ( V_5 -> V_113 ) ;
V_5 -> V_114 = - V_115 ;
V_5 -> V_113 = NULL ;
F_55 ( & V_5 -> V_112 ) ;
if ( F_47 ( V_100 ) < V_105 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_100 ) )
F_42 ( & V_5 -> V_99 ) ;
F_56 ( & V_4 -> V_110 , V_31 ) ;
}
static void F_57 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_107 * V_108 = V_5 -> V_109 ;
if ( V_108 ) {
F_51 ( V_108 ) ;
F_58 ( V_108 ) ;
F_59 ( V_4 -> V_33 , & V_5 -> V_111 , 1 ,
V_116 ) ;
}
V_5 -> V_113 = NULL ;
V_5 -> V_109 = NULL ;
V_5 -> V_114 = - V_115 ;
}
static void F_60 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_80 * V_100 = & V_4 -> V_101 -> V_100 ;
struct V_107 * V_108 = V_5 -> V_109 ;
struct V_117 * V_118 ;
struct V_119 * V_120 = & V_5 -> V_111 ;
if ( V_5 -> V_113 != NULL )
return;
if ( ! F_45 ( V_100 ) && ! F_46 ( V_4 ) ) {
V_120 -> V_121 = V_100 -> V_86 & ( V_104 - 1 ) ;
F_61 ( V_120 ) = ( F_61 ( V_120 ) &
~ ( V_104 - 1 ) )
+ V_120 -> V_121 ;
F_52 ( V_120 ) = F_62 ( V_100 -> V_85 ,
V_100 -> V_86 ,
V_104 ) ;
F_63 ( ! F_52 ( V_120 ) ) ;
V_118 = F_64 ( V_108 ,
V_120 ,
1 ,
V_122 ,
V_123 |
V_124 ) ;
if ( ! V_118 ) {
F_65 ( V_4 -> V_33 , L_3 ) ;
return;
}
F_66 ( V_4 -> V_33 , V_120 , 1 , V_116 ) ;
V_5 -> V_113 = V_118 ;
V_118 -> V_125 = F_49 ;
V_118 -> V_126 = V_5 ;
V_5 -> V_114 = F_67 ( V_118 ) ;
} else {
if ( V_4 -> V_30 . V_31 & V_32 ) {
F_26 ( V_4 ) ;
}
}
if ( F_47 ( V_100 ) < V_105 )
F_48 ( V_4 ) ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_3 V_127 ;
struct V_128 V_129 ;
int V_11 , V_130 ;
F_69 ( V_127 ) ;
F_70 ( V_131 , V_127 ) ;
V_5 -> V_109 = F_71 ( V_4 -> V_33 , L_4 ) ;
if ( V_5 -> V_109 == NULL )
goto V_132;
F_72 ( V_4 -> V_33 , L_5 ,
F_73 ( V_5 -> V_109 ) ) ;
F_74 ( & V_5 -> V_112 ) ;
F_75 ( & V_5 -> V_111 , 1 ) ;
F_63 ( ( int ) V_4 -> V_101 -> V_100 . V_88 & ~ V_133 ) ;
F_76 ( & V_5 -> V_111 ,
F_77 ( V_4 -> V_101 -> V_100 . V_88 ) ,
V_104 ,
( int ) V_4 -> V_101 -> V_100 . V_88 & ~ V_133 ) ;
V_130 = F_78 ( V_4 -> V_33 ,
& V_5 -> V_111 ,
1 ,
V_116 ) ;
if ( ! V_130 ) {
F_15 ( V_4 -> V_33 , L_6 ) ;
goto V_132;
} else {
F_15 ( V_4 -> V_33 , L_7 , V_134 ,
F_52 ( & V_5 -> V_111 ) ,
V_4 -> V_101 -> V_100 . V_88 ,
F_61 ( & V_5 -> V_111 ) ) ;
}
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_135 = V_122 ;
V_129 . V_136 = V_137 ;
V_129 . V_138 = V_4 -> V_139 + V_140 ;
V_11 = F_79 ( V_5 -> V_109 ,
& V_129 ) ;
if ( V_11 ) {
F_65 ( V_4 -> V_33 , L_8 ) ;
goto V_132;
}
return 0 ;
V_132:
F_65 ( V_4 -> V_33 , L_9 ) ;
V_5 -> V_8 = 0 ;
if ( V_5 -> V_109 )
F_57 ( V_4 ) ;
return - V_115 ;
}
static void F_80 ( void * V_106 )
{
struct V_2 * V_4 = V_106 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_99 ) ;
}
static void F_81 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_107 * V_108 = V_5 -> V_141 ;
if ( V_108 ) {
F_51 ( V_108 ) ;
F_58 ( V_108 ) ;
F_59 ( V_4 -> V_33 , & V_5 -> V_142 , 1 ,
V_143 ) ;
}
V_5 -> V_144 = NULL ;
V_5 -> V_141 = NULL ;
V_5 -> V_145 = - V_115 ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_146 * V_147 = & V_4 -> V_101 -> V_4 ;
struct V_80 * V_81 = & V_5 -> V_82 ;
struct V_107 * V_108 = V_5 -> V_141 ;
struct V_148 V_101 ;
enum V_149 V_150 ;
T_4 V_151 ;
F_21 ( V_4 , V_152 ) ;
V_150 = F_83 ( V_108 ,
V_5 -> V_145 ,
& V_101 ) ;
if ( V_150 == V_153 ) {
F_15 ( V_4 -> V_33 , L_10 ) ;
F_18 ( V_4 , V_62 ) ;
F_42 ( & V_5 -> V_99 ) ;
return;
}
F_84 ( V_4 -> V_33 ,
& V_5 -> V_142 ,
1 ,
V_143 ) ;
V_81 -> V_85 = F_52 ( & V_5 -> V_142 ) - V_101 . V_154 ;
F_63 ( V_81 -> V_85 > F_52 ( & V_5 -> V_142 ) ) ;
if ( V_81 -> V_85 < V_81 -> V_86 ) {
V_151 = F_52 ( & V_5 -> V_142 ) - V_81 -> V_86 ;
F_85 ( V_147 , V_81 -> V_88 + V_81 -> V_86 , V_151 ) ;
V_81 -> V_86 = 0 ;
V_4 -> V_92 . V_155 += V_151 ;
}
if ( V_81 -> V_86 < V_81 -> V_85 ) {
V_151 = V_81 -> V_85 - V_81 -> V_86 ;
F_85 ( V_147 , V_81 -> V_88 + V_81 -> V_86 , V_151 ) ;
if ( V_81 -> V_85 >= F_52 ( & V_5 -> V_142 ) )
V_81 -> V_85 = 0 ;
V_81 -> V_86 = V_81 -> V_85 ;
V_4 -> V_92 . V_155 += V_151 ;
}
F_66 ( V_4 -> V_33 ,
& V_5 -> V_142 ,
1 ,
V_143 ) ;
F_86 ( & V_4 -> V_110 ) ;
F_87 ( V_147 ) ;
F_88 ( & V_4 -> V_110 ) ;
F_18 ( V_4 , V_62 ) ;
}
static int F_89 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_117 * V_118 ;
T_3 V_127 ;
struct V_128 V_129 ;
struct V_80 * V_81 ;
int V_11 , V_130 ;
V_81 = & V_5 -> V_82 ;
F_69 ( V_127 ) ;
F_70 ( V_156 , V_127 ) ;
V_5 -> V_141 = F_71 ( V_4 -> V_33 , L_11 ) ;
if ( V_5 -> V_141 == NULL )
goto V_132;
F_72 ( V_4 -> V_33 , L_12 ,
F_73 ( V_5 -> V_141 ) ) ;
F_74 ( & V_5 -> V_157 ) ;
F_75 ( & V_5 -> V_142 , 1 ) ;
F_63 ( ( int ) V_4 -> V_101 -> V_100 . V_88 & ~ V_133 ) ;
F_76 ( & V_5 -> V_142 ,
F_77 ( V_81 -> V_88 ) ,
V_87 ,
( int ) V_81 -> V_88 & ~ V_133 ) ;
V_130 = F_78 ( V_4 -> V_33 ,
& V_5 -> V_142 ,
1 ,
V_143 ) ;
if ( ! V_130 ) {
F_15 ( V_4 -> V_33 , L_6 ) ;
goto V_132;
} else {
F_15 ( V_4 -> V_33 , L_7 , V_134 ,
F_52 ( & V_5 -> V_142 ) ,
V_81 -> V_88 ,
F_61 ( & V_5 -> V_142 ) ) ;
}
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_135 = V_158 ;
V_129 . V_159 = V_137 ;
V_129 . V_160 = V_4 -> V_139 + V_161 ;
V_11 = F_79 ( V_5 -> V_141 ,
& V_129 ) ;
if ( V_11 ) {
F_65 ( V_4 -> V_33 , L_13 ) ;
goto V_132;
}
V_118 = F_90 ( V_5 -> V_141 ,
F_61 ( & V_5 -> V_142 ) ,
F_52 ( & V_5 -> V_142 ) ,
F_52 ( & V_5 -> V_142 ) / 2 ,
V_158 ,
V_123 ) ;
V_118 -> V_125 = F_80 ;
V_118 -> V_126 = V_4 ;
V_5 -> V_144 = V_118 ;
V_5 -> V_145 = F_67 ( V_118 ) ;
return 0 ;
V_132:
F_65 ( V_4 -> V_33 , L_14 ) ;
V_5 -> V_9 = 0 ;
if ( V_5 -> V_141 )
F_81 ( V_4 ) ;
return - V_115 ;
}
static void F_91 ( unsigned long V_162 )
{
struct V_2 * V_4 = ( void * ) V_162 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_99 ) ;
F_92 ( & V_5 -> V_163 , V_164 + F_93 ( V_4 ) ) ;
}
static void
F_94 ( struct V_2 * V_4 , unsigned int V_165 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_165 & ( V_61 | V_62 ) ) {
F_13 ( V_4 , ( V_61
| V_62 ) ) ;
F_42 ( & V_5 -> V_99 ) ;
}
if ( V_165 & ( V_89 | V_96 |
V_91 | V_90 ) )
F_38 ( V_4 , V_165 ) ;
}
if ( F_6 ( V_4 ) ) {
if ( V_165 & V_62 ) {
F_13 ( V_4 , V_62 ) ;
F_42 ( & V_5 -> V_99 ) ;
}
}
if ( V_165 & V_65 )
F_39 ( V_4 ) ;
else if ( V_165 & V_89 ) {
F_21 ( V_4 , V_59 ) ;
F_13 ( V_4 , V_89 ) ;
V_5 -> V_98 = 0 ;
}
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_165 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_165 & V_5 -> V_28 ) {
F_13 ( V_4 , V_5 -> V_28 ) ;
F_42 ( & V_5 -> V_99 ) ;
}
}
static void
F_96 ( struct V_2 * V_4 , unsigned int V_165 ,
unsigned int V_10 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_165 & ( V_73 | V_72 | V_74
| V_71 ) ) {
V_5 -> V_166 = V_10 ;
F_42 ( & V_5 -> V_99 ) ;
}
}
static T_5 F_97 ( int V_167 , void * V_168 )
{
struct V_2 * V_4 = V_168 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_165 , V_127 , V_169 = 0 ;
bool V_170 = false ;
F_88 ( & V_5 -> V_171 ) ;
do {
V_10 = F_7 ( V_4 ) ;
V_127 = F_98 ( V_4 ) ;
V_165 = V_10 & V_127 ;
if ( ! V_170 ) {
if ( V_167 == V_5 -> V_70 [ V_13 ] )
V_165 |= V_71 ;
if ( V_167 == V_5 -> V_70 [ V_16 ] )
V_165 |= V_72 ;
if ( V_167 == V_5 -> V_70 [ V_19 ] )
V_165 |= V_73 ;
if ( V_167 == V_5 -> V_70 [ V_22 ] )
V_165 |= V_74 ;
V_170 = true ;
}
if ( ! V_165 )
break;
if ( V_5 -> V_172 ) {
V_5 -> V_165 |= V_165 ;
V_5 -> V_173 = V_10 ;
F_13 ( V_4 , V_127 ) ;
F_99 () ;
break;
}
F_94 ( V_4 , V_165 ) ;
F_96 ( V_4 , V_165 , V_10 ) ;
F_95 ( V_4 , V_165 ) ;
} while ( V_169 ++ < V_174 );
F_86 ( & V_5 -> V_171 ) ;
return V_169 ? V_175 : V_176 ;
}
static void F_100 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_177 * V_178 = & V_5 -> V_179 ;
F_101 ( V_4 -> V_33 ,
V_178 -> V_180 ,
V_178 -> V_181 ,
V_116 ) ;
}
static void F_102 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_80 * V_100 = & V_4 -> V_101 -> V_100 ;
struct V_177 * V_178 = & V_5 -> V_179 ;
int V_151 ;
if ( F_103 ( V_4 ) )
return;
V_100 -> V_86 += V_178 -> V_182 ;
V_100 -> V_86 &= V_104 - 1 ;
V_4 -> V_92 . V_103 += V_178 -> V_182 ;
V_178 -> V_182 = 0 ;
F_25 ( V_4 , V_56 ) ;
if ( ! F_45 ( V_100 ) && ! F_46 ( V_4 ) ) {
F_104 ( V_4 -> V_33 ,
V_178 -> V_180 ,
V_178 -> V_181 ,
V_116 ) ;
V_151 = F_62 ( V_100 -> V_85 , V_100 -> V_86 , V_104 ) ;
V_178 -> V_182 = V_151 ;
F_105 ( V_4 , V_178 -> V_180 + V_100 -> V_86 ) ;
F_106 ( V_4 , V_151 ) ;
F_25 ( V_4 , V_58 ) ;
F_18 ( V_4 , V_5 -> V_28 ) ;
} else {
if ( ( V_4 -> V_30 . V_31 & V_32 ) &&
! ( V_4 -> V_30 . V_31 & V_57 ) ) {
F_26 ( V_4 ) ;
}
}
if ( F_47 ( V_100 ) < V_105 )
F_48 ( V_4 ) ;
}
static int F_107 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_177 * V_178 = & V_5 -> V_179 ;
struct V_80 * V_100 = & V_4 -> V_101 -> V_100 ;
V_178 -> V_88 = V_100 -> V_88 ;
V_178 -> V_180 = F_108 ( V_4 -> V_33 ,
V_178 -> V_88 ,
V_104 ,
V_116 ) ;
V_178 -> V_181 = V_104 ;
V_178 -> V_182 = 0 ;
return 0 ;
}
static void F_109 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_80 * V_81 = & V_5 -> V_82 ;
unsigned int V_183 ;
unsigned int V_10 ;
while ( V_81 -> V_85 != V_81 -> V_86 ) {
struct V_83 V_84 ;
F_110 () ;
V_84 = ( (struct V_83 * ) V_81 -> V_88 ) [ V_81 -> V_86 ] ;
V_81 -> V_86 = ( V_81 -> V_86 + 1 ) & ( V_87 - 1 ) ;
V_4 -> V_92 . V_155 ++ ;
V_10 = V_84 . V_10 ;
V_183 = V_184 ;
if ( F_41 ( V_10 & ( V_90 | V_91
| V_96 | V_89 ) ) ) {
if ( V_10 & V_89 ) {
V_10 &= ~ ( V_90 | V_91 ) ;
V_4 -> V_92 . V_93 ++ ;
if ( F_111 ( V_4 ) )
continue;
}
if ( V_10 & V_90 )
V_4 -> V_92 . V_94 ++ ;
if ( V_10 & V_91 )
V_4 -> V_92 . V_95 ++ ;
if ( V_10 & V_96 )
V_4 -> V_92 . V_97 ++ ;
V_10 &= V_4 -> V_63 ;
if ( V_10 & V_89 )
V_183 = V_185 ;
else if ( V_10 & V_90 )
V_183 = V_186 ;
else if ( V_10 & V_91 )
V_183 = V_187 ;
}
if ( F_112 ( V_4 , V_84 . V_79 ) )
continue;
F_113 ( V_4 , V_10 , V_96 , V_84 . V_79 , V_183 ) ;
}
F_86 ( & V_4 -> V_110 ) ;
F_87 ( & V_4 -> V_101 -> V_4 ) ;
F_88 ( & V_4 -> V_110 ) ;
}
static void F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_188 ;
for ( V_188 = 0 ; V_188 < 2 ; V_188 ++ ) {
struct V_177 * V_178 = & V_5 -> V_189 [ V_188 ] ;
F_101 ( V_4 -> V_33 ,
V_178 -> V_180 ,
V_178 -> V_181 ,
V_143 ) ;
F_115 ( V_178 -> V_88 ) ;
}
}
static void F_116 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_146 * V_147 = & V_4 -> V_101 -> V_4 ;
struct V_177 * V_178 ;
int V_190 = V_5 -> V_191 ;
unsigned int V_85 ;
unsigned int V_86 ;
unsigned int V_151 ;
do {
F_21 ( V_4 , V_152 ) ;
V_178 = & V_5 -> V_189 [ V_190 ] ;
V_85 = F_117 ( V_4 ) - V_178 -> V_180 ;
V_86 = V_178 -> V_182 ;
V_85 = F_118 ( V_85 , V_178 -> V_181 ) ;
if ( F_119 ( V_85 != V_86 ) ) {
F_120 ( V_4 -> V_33 , V_178 -> V_180 ,
V_178 -> V_181 , V_143 ) ;
V_151 = V_85 - V_86 ;
F_85 ( V_147 , V_178 -> V_88 + V_178 -> V_182 ,
V_151 ) ;
F_104 ( V_4 -> V_33 , V_178 -> V_180 ,
V_178 -> V_181 , V_143 ) ;
V_4 -> V_92 . V_155 += V_151 ;
V_178 -> V_182 = V_85 ;
}
if ( V_85 >= V_178 -> V_181 ) {
V_178 -> V_182 = 0 ;
F_121 ( V_4 , V_178 -> V_180 ) ;
F_122 ( V_4 , V_178 -> V_181 ) ;
V_190 = ! V_190 ;
V_5 -> V_191 = V_190 ;
}
} while ( V_85 >= V_178 -> V_181 );
F_86 ( & V_4 -> V_110 ) ;
F_87 ( V_147 ) ;
F_88 ( & V_4 -> V_110 ) ;
F_18 ( V_4 , V_61 | V_62 ) ;
}
static int F_123 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_188 ;
for ( V_188 = 0 ; V_188 < 2 ; V_188 ++ ) {
struct V_177 * V_178 = & V_5 -> V_189 [ V_188 ] ;
V_178 -> V_88 = F_124 ( V_192 , V_193 ) ;
if ( V_178 -> V_88 == NULL ) {
if ( V_188 != 0 ) {
F_101 ( V_4 -> V_33 ,
V_5 -> V_189 [ 0 ] . V_180 ,
V_192 ,
V_143 ) ;
F_115 ( V_5 -> V_189 [ 0 ] . V_88 ) ;
}
V_5 -> V_6 = 0 ;
return - V_194 ;
}
V_178 -> V_180 = F_108 ( V_4 -> V_33 ,
V_178 -> V_88 ,
V_192 ,
V_143 ) ;
V_178 -> V_181 = V_192 ;
V_178 -> V_182 = 0 ;
}
V_5 -> V_191 = 0 ;
F_125 ( V_4 , V_5 -> V_189 [ 0 ] . V_180 ) ;
F_126 ( V_4 , V_192 ) ;
F_121 ( V_4 , V_5 -> V_189 [ 1 ] . V_180 ) ;
F_122 ( V_4 , V_192 ) ;
return 0 ;
}
static void F_127 ( unsigned long V_162 )
{
struct V_2 * V_4 = (struct V_2 * ) V_162 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 ;
unsigned int V_195 ;
F_88 ( & V_4 -> V_110 ) ;
V_5 -> V_196 ( V_4 ) ;
V_10 = V_5 -> V_166 ;
V_195 = V_10 ^ V_5 -> V_197 ;
if ( V_195 & ( V_21 | V_18
| V_24 | V_15 ) ) {
if ( V_195 & V_21 )
V_4 -> V_92 . V_198 ++ ;
if ( V_195 & V_18 )
V_4 -> V_92 . V_199 ++ ;
if ( V_195 & V_24 )
F_128 ( V_4 , ! ( V_10 & V_24 ) ) ;
if ( V_195 & V_15 )
F_129 ( V_4 , ! ( V_10 & V_15 ) ) ;
F_130 ( & V_4 -> V_101 -> V_4 . V_200 ) ;
V_5 -> V_197 = V_10 ;
}
V_5 -> V_201 ( V_4 ) ;
F_86 ( & V_4 -> V_110 ) ;
}
static int F_131 ( struct V_1 * V_5 ,
struct V_202 * V_203 )
{
struct V_204 * V_205 = V_203 -> V_33 . V_206 ;
struct V_207 * V_208 = F_132 ( & V_203 -> V_33 ) ;
if ( V_205 ) {
if ( F_133 ( V_205 , L_15 , NULL ) ) {
if ( F_133 ( V_205 , L_16 , NULL ) ) {
V_5 -> V_9 = true ;
V_5 -> V_6 = false ;
} else {
V_5 -> V_9 = false ;
V_5 -> V_6 = true ;
}
} else {
V_5 -> V_9 = false ;
V_5 -> V_6 = false ;
}
if ( F_133 ( V_205 , L_17 , NULL ) ) {
if ( F_133 ( V_205 , L_16 , NULL ) ) {
V_5 -> V_8 = true ;
V_5 -> V_7 = false ;
} else {
V_5 -> V_8 = false ;
V_5 -> V_7 = true ;
}
} else {
V_5 -> V_8 = false ;
V_5 -> V_7 = false ;
}
} else {
V_5 -> V_6 = V_208 -> V_9 ;
V_5 -> V_7 = V_208 -> V_8 ;
V_5 -> V_9 = false ;
V_5 -> V_8 = false ;
}
return 0 ;
}
static void F_134 ( struct V_2 * V_4 ,
struct V_202 * V_203 )
{
struct V_204 * V_205 = V_203 -> V_33 . V_206 ;
struct V_207 * V_208 = F_132 ( & V_203 -> V_33 ) ;
if ( V_205 ) {
T_6 V_209 [ 2 ] ;
if ( F_135 ( V_205 , L_18 ,
V_209 , 2 ) == 0 ) {
struct V_25 * V_26 = & V_4 -> V_30 ;
V_26 -> V_210 = V_209 [ 0 ] ;
V_26 -> V_35 = V_209 [ 1 ] ;
V_26 -> V_31 = 0 ;
if ( F_133 ( V_205 , L_19 , NULL ) )
V_26 -> V_31 |= V_57 ;
if ( F_133 ( V_205 , L_20 ,
NULL ) )
V_26 -> V_31 |= V_32 ;
}
} else {
V_4 -> V_30 = V_208 -> V_30 ;
}
}
static void F_136 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_6 ( V_4 ) ) {
V_5 -> V_211 = & F_89 ;
V_5 -> V_201 = & F_82 ;
V_5 -> V_212 = & F_81 ;
} else if ( F_3 ( V_4 ) ) {
V_5 -> V_211 = & F_123 ;
V_5 -> V_201 = & F_116 ;
V_5 -> V_212 = & F_114 ;
} else {
V_5 -> V_211 = NULL ;
V_5 -> V_201 = & F_109 ;
V_5 -> V_212 = NULL ;
}
if ( F_5 ( V_4 ) ) {
V_5 -> V_213 = & F_68 ;
V_5 -> V_196 = & F_60 ;
V_5 -> V_214 = & F_57 ;
} else if ( F_4 ( V_4 ) ) {
V_5 -> V_213 = & F_107 ;
V_5 -> V_196 = & F_102 ;
V_5 -> V_214 = & F_100 ;
} else {
V_5 -> V_213 = NULL ;
V_5 -> V_196 = & F_43 ;
V_5 -> V_214 = NULL ;
}
}
static void F_137 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_215 = F_138 ( V_4 ) ;
T_6 V_216 ;
int V_217 , V_3 ;
V_217 = 0x55534152 ;
V_3 = 0x44424755 ;
V_5 -> V_218 = false ;
if ( V_215 == V_217 ) {
F_15 ( V_4 -> V_33 , L_21 ) ;
V_5 -> V_218 = true ;
} else if ( V_215 == V_3 ) {
F_15 ( V_4 -> V_33 , L_22 ) ;
V_5 -> V_218 = false ;
} else {
V_216 = F_139 ( V_4 ) ;
switch ( V_216 ) {
case 0x302 :
case 0x10213 :
F_15 ( V_4 -> V_33 , L_23 ) ;
V_5 -> V_218 = true ;
break;
case 0x203 :
case 0x10202 :
F_15 ( V_4 -> V_33 , L_24 ) ;
V_5 -> V_218 = false ;
break;
default:
F_65 ( V_4 -> V_33 , L_25 ) ;
}
}
}
static void F_140 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
enum V_219 V_188 ;
for ( V_188 = 0 ; V_188 < V_220 ; V_188 ++ )
if ( V_5 -> V_70 [ V_188 ] >= 0 )
F_141 ( V_5 -> V_70 [ V_188 ] , V_4 ) ;
}
static int F_142 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int * V_167 = V_5 -> V_70 ;
enum V_219 V_188 ;
int V_221 = 0 ;
for ( V_188 = 0 ; ( V_188 < V_220 ) && ! V_221 ; V_188 ++ ) {
if ( V_167 [ V_188 ] < 0 )
continue;
F_143 ( V_167 [ V_188 ] , V_222 ) ;
V_221 = F_144 ( V_167 [ V_188 ] , F_97 , V_223 ,
L_26 , V_4 ) ;
if ( V_221 )
F_65 ( V_4 -> V_33 , L_27 ,
V_167 [ V_188 ] ) ;
}
while ( V_221 && ( -- V_188 >= 0 ) )
if ( V_167 [ V_188 ] >= 0 )
F_141 ( V_167 [ V_188 ] , V_4 ) ;
return V_221 ;
}
static int F_145 ( struct V_2 * V_4 )
{
struct V_202 * V_203 = F_146 ( V_4 -> V_33 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_224 * V_225 = V_4 -> V_101 -> V_4 . V_225 ;
int V_226 ;
F_13 ( V_4 , - 1 ) ;
V_5 -> V_69 = false ;
V_226 = F_144 ( V_4 -> V_167 , F_97 ,
V_227 | V_228 ,
V_225 ? V_225 -> V_215 : L_26 , V_4 ) ;
if ( V_226 ) {
F_65 ( V_4 -> V_33 , L_28 ) ;
return V_226 ;
}
V_226 = F_142 ( V_4 ) ;
if ( V_226 )
goto F_141;
F_131 ( V_5 , V_203 ) ;
if ( V_5 -> V_211 ) {
V_226 = V_5 -> V_211 ( V_4 ) ;
if ( V_226 < 0 )
F_136 ( V_4 ) ;
}
if ( V_5 -> V_213 ) {
V_226 = V_5 -> V_213 ( V_4 ) ;
if ( V_226 < 0 )
F_136 ( V_4 ) ;
}
V_5 -> V_197 = F_7 ( V_4 ) ;
V_5 -> V_166 = V_5 -> V_197 ;
F_21 ( V_4 , V_59 | V_229 ) ;
F_21 ( V_4 , V_230 | V_60 ) ;
F_147 ( & V_5 -> V_163 ,
F_91 ,
( unsigned long ) V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( ! V_5 -> V_218 ) {
F_92 ( & V_5 -> V_163 ,
V_164 + F_93 ( V_4 ) ) ;
} else {
F_148 ( V_4 , V_231 ) ;
F_21 ( V_4 , V_152 ) ;
F_18 ( V_4 , V_61 | V_62 ) ;
}
F_25 ( V_4 , V_64 ) ;
} else if ( F_6 ( V_4 ) ) {
if ( ! V_5 -> V_218 ) {
F_92 ( & V_5 -> V_163 ,
V_164 + F_93 ( V_4 ) ) ;
} else {
F_148 ( V_4 , V_231 ) ;
F_21 ( V_4 , V_152 ) ;
F_18 ( V_4 , V_62 ) ;
}
} else {
F_18 ( V_4 , V_65 ) ;
}
return 0 ;
F_141:
F_141 ( V_4 -> V_167 , V_4 ) ;
return V_226 ;
}
static void F_149 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_106 ( V_4 , 0 ) ;
V_5 -> V_179 . V_182 = 0 ;
}
}
static void F_150 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_151 ( & V_5 -> V_163 ) ;
F_152 ( & V_5 -> V_99 ) ;
F_29 ( V_4 ) ;
F_24 ( V_4 ) ;
F_21 ( V_4 , V_59 ) ;
F_13 ( V_4 , - 1 ) ;
if ( V_5 -> V_212 )
V_5 -> V_212 ( V_4 ) ;
if ( V_5 -> V_214 )
V_5 -> V_214 ( V_4 ) ;
V_5 -> V_82 . V_85 = 0 ;
V_5 -> V_82 . V_86 = 0 ;
F_141 ( V_4 -> V_167 , V_4 ) ;
F_140 ( V_4 ) ;
V_5 -> V_69 = false ;
F_149 ( V_4 ) ;
}
static void F_153 ( struct V_2 * V_4 , unsigned int V_101 ,
unsigned int V_232 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_101 ) {
case 0 :
F_154 ( V_5 -> V_233 ) ;
F_18 ( V_4 , V_5 -> V_234 ) ;
break;
case 3 :
V_5 -> V_234 = F_98 ( V_4 ) ;
F_13 ( V_4 , - 1 ) ;
F_155 ( V_5 -> V_233 ) ;
break;
default:
F_65 ( V_4 -> V_33 , L_29 , V_101 ) ;
}
}
static void F_156 ( struct V_2 * V_4 , struct V_235 * V_236 ,
struct V_235 * V_237 )
{
unsigned long V_31 ;
unsigned int V_238 , V_27 , V_239 , V_240 , V_241 ;
V_27 = V_238 = F_14 ( V_4 ) ;
V_27 &= ~ ( V_242 | V_243 | V_244 |
V_245 | V_29 ) ;
V_241 = F_157 ( V_4 , V_236 , V_237 , 0 , V_4 -> V_246 / 16 ) ;
V_240 = F_158 ( V_4 , V_241 ) ;
if ( V_240 > 65535 ) {
V_240 /= 8 ;
V_27 |= V_247 ;
}
switch ( V_236 -> V_248 & V_249 ) {
case V_250 :
V_27 |= V_251 ;
break;
case V_252 :
V_27 |= V_253 ;
break;
case V_254 :
V_27 |= V_255 ;
break;
default:
V_27 |= V_256 ;
break;
}
if ( V_236 -> V_248 & V_257 )
V_27 |= V_258 ;
if ( V_236 -> V_248 & V_259 ) {
if ( V_236 -> V_248 & V_260 ) {
if ( V_236 -> V_248 & V_261 )
V_27 |= V_262 ;
else
V_27 |= V_263 ;
} else if ( V_236 -> V_248 & V_261 )
V_27 |= V_264 ;
else
V_27 |= V_265 ;
} else
V_27 |= V_266 ;
F_50 ( & V_4 -> V_110 , V_31 ) ;
V_4 -> V_63 = V_96 ;
if ( V_236 -> V_267 & V_268 )
V_4 -> V_63 |= ( V_91 | V_90 ) ;
if ( V_236 -> V_267 & ( V_269 | V_270 | V_271 ) )
V_4 -> V_63 |= V_89 ;
if ( F_3 ( V_4 ) )
F_18 ( V_4 , V_4 -> V_63 ) ;
V_4 -> V_272 = 0 ;
if ( V_236 -> V_267 & V_273 )
V_4 -> V_272 |= ( V_91 | V_90 ) ;
if ( V_236 -> V_267 & V_269 ) {
V_4 -> V_272 |= V_89 ;
if ( V_236 -> V_267 & V_273 )
V_4 -> V_272 |= V_96 ;
}
F_159 ( V_4 , V_236 -> V_248 , V_241 ) ;
V_239 = F_98 ( V_4 ) ;
F_13 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_274 | V_66 ) ;
if ( V_4 -> V_30 . V_31 & V_32 ) {
if ( ( V_4 -> V_30 . V_35 ) > 0 )
F_16 ( V_4 , V_4 -> V_30 . V_35 ) ;
V_27 |= V_36 ;
} else if ( V_236 -> V_248 & V_275 ) {
V_27 |= V_45 ;
} else {
V_27 |= V_276 ;
}
F_17 ( V_4 , V_27 ) ;
if ( ( V_238 & V_29 ) != ( V_27 & V_29 ) ) {
unsigned int V_277 ;
if ( ( V_27 & V_29 ) == V_45 ) {
V_277 = V_47 ;
} else {
V_277 = V_46 ;
}
F_21 ( V_4 , V_277 ) ;
}
F_160 ( V_4 , V_240 ) ;
F_21 ( V_4 , V_59 | V_229 ) ;
F_21 ( V_4 , V_230 | V_60 ) ;
F_18 ( V_4 , V_239 ) ;
if ( F_161 ( V_4 , V_236 -> V_248 ) )
F_30 ( V_4 ) ;
else
F_32 ( V_4 ) ;
F_56 ( & V_4 -> V_110 , V_31 ) ;
}
static void F_162 ( struct V_2 * V_4 , struct V_235 * V_236 )
{
if ( V_236 -> V_278 == V_279 ) {
V_4 -> V_31 |= V_280 ;
F_53 ( & V_4 -> V_110 ) ;
F_30 ( V_4 ) ;
F_55 ( & V_4 -> V_110 ) ;
} else {
V_4 -> V_31 &= ~ V_280 ;
if ( ! F_161 ( V_4 , V_236 -> V_248 ) ) {
F_53 ( & V_4 -> V_110 ) ;
F_32 ( V_4 ) ;
F_55 ( & V_4 -> V_110 ) ;
}
}
}
static const char * F_163 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_281 ) ? L_30 : NULL ;
}
static void F_164 ( struct V_2 * V_4 )
{
struct V_202 * V_203 = F_146 ( V_4 -> V_33 ) ;
int V_282 = V_203 -> V_283 [ 0 ] . V_284 - V_203 -> V_283 [ 0 ] . V_285 + 1 ;
F_165 ( V_4 -> V_139 , V_282 ) ;
if ( V_4 -> V_31 & V_286 ) {
F_166 ( V_4 -> V_287 ) ;
V_4 -> V_287 = NULL ;
}
}
static int F_167 ( struct V_2 * V_4 )
{
struct V_202 * V_203 = F_146 ( V_4 -> V_33 ) ;
int V_282 = V_203 -> V_283 [ 0 ] . V_284 - V_203 -> V_283 [ 0 ] . V_285 + 1 ;
if ( ! F_168 ( V_4 -> V_139 , V_282 , L_26 ) )
return - V_288 ;
if ( V_4 -> V_31 & V_286 ) {
V_4 -> V_287 = F_169 ( V_4 -> V_139 , V_282 ) ;
if ( V_4 -> V_287 == NULL ) {
F_165 ( V_4 -> V_139 , V_282 ) ;
return - V_194 ;
}
}
return 0 ;
}
static void F_170 ( struct V_2 * V_4 , int V_31 )
{
if ( V_31 & V_289 ) {
V_4 -> type = V_281 ;
F_167 ( V_4 ) ;
}
}
static int F_171 ( struct V_2 * V_4 , struct V_290 * V_291 )
{
int V_11 = 0 ;
if ( V_291 -> type != V_292 && V_291 -> type != V_281 )
V_11 = - V_115 ;
if ( V_4 -> V_167 != V_291 -> V_167 )
V_11 = - V_115 ;
if ( V_291 -> V_293 != V_294 )
V_11 = - V_115 ;
if ( V_4 -> V_246 / 16 != V_291 -> V_295 )
V_11 = - V_115 ;
if ( ( void * ) V_4 -> V_139 != V_291 -> V_296 )
V_11 = - V_115 ;
if ( V_4 -> V_297 != V_291 -> V_4 )
V_11 = - V_115 ;
if ( V_291 -> V_298 != 0 )
V_11 = - V_115 ;
return V_11 ;
}
static int F_172 ( struct V_2 * V_4 )
{
while ( ! ( F_8 ( V_4 ) & V_65 ) )
F_173 () ;
return F_40 ( V_4 ) ;
}
static void F_174 ( struct V_2 * V_4 , unsigned char V_79 )
{
while ( ! ( F_8 ( V_4 ) & V_39 ) )
F_173 () ;
F_44 ( V_4 , V_79 ) ;
}
static int F_175 ( struct V_1 * V_5 ,
struct V_202 * V_203 )
{
int V_11 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_207 * V_208 = F_132 ( & V_203 -> V_33 ) ;
if ( ! F_131 ( V_5 , V_203 ) )
F_136 ( V_4 ) ;
F_134 ( V_4 , V_203 ) ;
V_4 -> V_299 = V_300 ;
V_4 -> V_31 = V_301 ;
V_4 -> V_302 = & V_303 ;
V_4 -> V_304 = 1 ;
V_4 -> V_33 = & V_203 -> V_33 ;
V_4 -> V_139 = V_203 -> V_283 [ 0 ] . V_285 ;
V_4 -> V_167 = V_203 -> V_283 [ 1 ] . V_285 ;
V_4 -> V_305 = F_12 ;
F_176 ( & V_5 -> V_99 , F_127 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_82 , 0 , sizeof( V_5 -> V_82 ) ) ;
if ( V_208 && V_208 -> V_306 ) {
V_4 -> V_287 = V_208 -> V_306 ;
} else {
V_4 -> V_31 |= V_286 ;
V_4 -> V_287 = NULL ;
}
if ( ! V_5 -> V_233 ) {
V_5 -> V_233 = F_177 ( & V_203 -> V_33 , L_31 ) ;
if ( F_178 ( V_5 -> V_233 ) ) {
V_11 = F_179 ( V_5 -> V_233 ) ;
V_5 -> V_233 = NULL ;
return V_11 ;
}
V_11 = F_154 ( V_5 -> V_233 ) ;
if ( V_11 ) {
F_180 ( V_5 -> V_233 ) ;
V_5 -> V_233 = NULL ;
return V_11 ;
}
V_4 -> V_246 = F_181 ( V_5 -> V_233 ) ;
F_155 ( V_5 -> V_233 ) ;
}
if ( V_4 -> V_30 . V_31 & V_32 )
V_5 -> V_28 = V_34 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_304 = V_192 ;
V_5 -> V_28 = V_37 | V_38 ;
} else {
V_5 -> V_28 = V_39 ;
}
return 0 ;
}
static void F_182 ( struct V_2 * V_4 , int V_79 )
{
while ( ! ( F_8 ( V_4 ) & V_39 ) )
F_173 () ;
F_44 ( V_4 , V_79 ) ;
}
static void F_183 ( struct V_307 * V_308 , const char * V_309 , T_1 V_151 )
{
struct V_2 * V_4 = & V_310 [ V_308 -> V_311 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_239 ;
unsigned int V_179 ;
V_239 = F_98 ( V_4 ) ;
F_13 ( V_4 , V_65 | V_5 -> V_28 ) ;
V_179 = F_28 ( V_4 ) & V_58 ;
F_25 ( V_4 , V_56 ) ;
F_184 ( V_4 , V_309 , V_151 , F_182 ) ;
do {
V_10 = F_8 ( V_4 ) ;
} while ( ! ( V_10 & V_39 ) );
if ( V_179 )
F_25 ( V_4 , V_58 ) ;
F_18 ( V_4 , V_239 ) ;
}
static void T_7 F_185 ( struct V_2 * V_4 , int * V_241 ,
int * V_94 , int * V_312 )
{
unsigned int V_313 , V_240 ;
V_240 = F_186 ( V_4 ) & V_314 ;
if ( ! V_240 )
return;
V_313 = F_14 ( V_4 ) & V_243 ;
if ( V_313 == V_256 )
* V_312 = 8 ;
else
* V_312 = 7 ;
V_313 = F_14 ( V_4 ) & V_245 ;
if ( V_313 == V_265 )
* V_94 = 'e' ;
else if ( V_313 == V_264 )
* V_94 = 'o' ;
* V_241 = V_4 -> V_246 / ( 16 * ( V_240 - 1 ) ) ;
}
static int T_7 F_187 ( struct V_307 * V_308 , char * V_315 )
{
int V_11 ;
struct V_2 * V_4 = & V_310 [ V_308 -> V_311 ] . V_3 ;
int V_241 = 115200 ;
int V_312 = 8 ;
int V_94 = 'n' ;
int V_316 = 'n' ;
if ( V_4 -> V_287 == NULL ) {
return - V_317 ;
}
V_11 = F_154 ( V_310 [ V_308 -> V_311 ] . V_233 ) ;
if ( V_11 )
return V_11 ;
F_13 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_59 | V_229 ) ;
F_21 ( V_4 , V_230 | V_60 ) ;
if ( V_315 )
F_188 ( V_315 , & V_241 , & V_94 , & V_312 , & V_316 ) ;
else
F_185 ( V_4 , & V_241 , & V_94 , & V_312 ) ;
return F_189 ( V_4 , V_308 , V_241 , V_94 , V_312 , V_316 ) ;
}
static int T_7 F_190 ( void )
{
int V_11 ;
if ( V_318 ) {
struct V_207 * V_208 =
F_132 ( & V_318 -> V_33 ) ;
int V_319 = V_208 -> V_320 ;
struct V_1 * V_4 = & V_310 [ V_319 ] ;
V_4 -> V_234 = 0 ;
V_4 -> V_3 . line = V_319 ;
F_191 ( V_321 , V_319 , NULL ) ;
V_11 = F_175 ( V_4 , V_318 ) ;
if ( V_11 )
return V_11 ;
F_192 ( & V_322 ) ;
}
return 0 ;
}
static int T_7 F_193 ( void )
{
if ( V_318
&& ! ( V_322 . V_31 & V_323 ) )
F_192 ( & V_322 ) ;
return 0 ;
}
static inline bool F_194 ( struct V_2 * V_4 )
{
return V_4 -> V_324 && V_4 -> V_324 -> V_311 == V_4 -> line ;
}
static inline bool F_194 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_195 ( void )
{
#ifdef F_196
return F_197 () ;
#else
return false ;
#endif
}
static int F_198 ( struct V_202 * V_203 ,
T_8 V_101 )
{
struct V_2 * V_4 = F_199 ( V_203 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_194 ( V_4 ) && V_325 ) {
while ( ! ( F_8 ( V_4 ) & V_34 ) )
F_173 () ;
}
V_5 -> V_326 = F_200 ( & V_203 -> V_33 ) ;
if ( F_195 () ) {
unsigned long V_31 ;
F_50 ( & V_5 -> V_171 , V_31 ) ;
V_5 -> V_172 = true ;
F_56 ( & V_5 -> V_171 , V_31 ) ;
F_201 ( & V_203 -> V_33 , 0 ) ;
}
F_202 ( & V_327 , V_4 ) ;
return 0 ;
}
static int F_203 ( struct V_202 * V_203 )
{
struct V_2 * V_4 = F_199 ( V_203 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned long V_31 ;
F_50 ( & V_5 -> V_171 , V_31 ) ;
if ( V_5 -> V_165 ) {
F_94 ( V_4 , V_5 -> V_165 ) ;
F_96 ( V_4 , V_5 -> V_165 ,
V_5 -> V_173 ) ;
F_95 ( V_4 , V_5 -> V_165 ) ;
V_5 -> V_165 = 0 ;
}
V_5 -> V_172 = false ;
F_56 ( & V_5 -> V_171 , V_31 ) ;
F_204 ( & V_327 , V_4 ) ;
F_201 ( & V_203 -> V_33 , V_5 -> V_326 ) ;
return 0 ;
}
static int F_205 ( struct V_1 * V_328 , struct V_329 * V_33 )
{
enum V_219 V_188 ;
struct V_330 * V_331 ;
V_328 -> V_12 = F_206 ( V_33 , 0 ) ;
if ( F_10 ( V_328 -> V_12 ) )
return - 1 ;
for ( V_188 = 0 ; V_188 < V_220 ; V_188 ++ ) {
V_331 = F_11 ( V_328 -> V_12 , V_188 ) ;
if ( V_331 && ( F_207 ( V_331 ) == V_332 ) )
V_328 -> V_70 [ V_188 ] = F_208 ( V_331 ) ;
else
V_328 -> V_70 [ V_188 ] = - V_115 ;
}
return 0 ;
}
static int F_209 ( struct V_202 * V_203 )
{
struct V_1 * V_4 ;
struct V_204 * V_205 = V_203 -> V_33 . V_206 ;
struct V_207 * V_208 = F_132 ( & V_203 -> V_33 ) ;
void * V_162 ;
int V_11 = - V_317 ;
bool V_333 ;
F_210 ( V_87 & ( V_87 - 1 ) ) ;
if ( V_205 )
V_11 = F_211 ( V_205 , L_32 ) ;
else
if ( V_208 )
V_11 = V_208 -> V_320 ;
if ( V_11 < 0 )
V_11 = F_212 ( V_334 , V_335 ) ;
if ( V_11 >= V_335 ) {
V_11 = - V_317 ;
goto V_221;
}
if ( F_213 ( V_11 , V_334 ) ) {
V_11 = - V_288 ;
goto V_221;
}
V_4 = & V_310 [ V_11 ] ;
V_4 -> V_234 = 0 ;
V_4 -> V_3 . line = V_11 ;
F_74 ( & V_4 -> V_171 ) ;
V_11 = F_205 ( V_4 , & V_203 -> V_33 ) ;
if ( V_11 < 0 )
F_65 ( & V_203 -> V_33 , L_33 ,
L_34 ) ;
V_11 = F_175 ( V_4 , V_203 ) ;
if ( V_11 )
goto V_336;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_11 = - V_194 ;
V_162 = F_124 ( sizeof( struct V_83 )
* V_87 , V_193 ) ;
if ( ! V_162 )
goto V_337;
V_4 -> V_82 . V_88 = V_162 ;
}
V_333 = V_4 -> V_3 . V_30 . V_31 & V_32 ;
V_11 = F_214 ( & V_327 , & V_4 -> V_3 ) ;
if ( V_11 )
goto V_338;
#ifdef F_215
if ( F_194 ( & V_4 -> V_3 )
&& V_339 -> V_31 & V_323 ) {
F_155 ( V_4 -> V_233 ) ;
}
#endif
F_216 ( & V_203 -> V_33 , 1 ) ;
F_217 ( V_203 , V_4 ) ;
F_154 ( V_4 -> V_233 ) ;
if ( V_333 ) {
F_17 ( & V_4 -> V_3 , V_276 ) ;
F_21 ( & V_4 -> V_3 , V_46 ) ;
}
F_137 ( & V_4 -> V_3 ) ;
F_155 ( V_4 -> V_233 ) ;
return 0 ;
V_338:
F_115 ( V_4 -> V_82 . V_88 ) ;
V_4 -> V_82 . V_88 = NULL ;
V_337:
if ( ! F_194 ( & V_4 -> V_3 ) ) {
F_180 ( V_4 -> V_233 ) ;
V_4 -> V_233 = NULL ;
}
V_336:
F_218 ( V_4 -> V_3 . line , V_334 ) ;
V_221:
return V_11 ;
}
static int F_219 ( struct V_202 * V_203 )
{
struct V_2 * V_4 = F_199 ( V_203 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_11 = 0 ;
F_152 ( & V_5 -> V_99 ) ;
F_216 ( & V_203 -> V_33 , 0 ) ;
V_11 = F_220 ( & V_327 , V_4 ) ;
F_115 ( V_5 -> V_82 . V_88 ) ;
F_218 ( V_4 -> line , V_334 ) ;
F_180 ( V_5 -> V_233 ) ;
return V_11 ;
}
static int T_7 F_221 ( void )
{
int V_11 ;
V_11 = F_222 ( & V_327 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_223 ( & V_340 ) ;
if ( V_11 )
F_224 ( & V_327 ) ;
return V_11 ;
}
static void T_9 F_225 ( void )
{
F_226 ( & V_340 ) ;
F_224 ( & V_327 ) ;
}
