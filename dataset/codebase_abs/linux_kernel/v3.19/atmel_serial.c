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
unsigned int V_27 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_41 & V_43 )
V_42 |= V_44 ;
else
V_42 |= V_45 ;
if ( V_41 & V_46 )
V_42 |= V_47 ;
else
V_42 |= V_48 ;
F_21 ( V_4 , V_42 ) ;
F_22 ( V_5 -> V_12 , V_41 ) ;
V_27 = F_14 ( V_4 ) & ~ V_49 ;
if ( V_41 & V_50 )
V_27 |= V_51 ;
else
V_27 |= V_52 ;
V_27 &= ~ V_29 ;
if ( V_4 -> V_30 . V_31 & V_32 ) {
F_15 ( V_4 -> V_33 , L_1 ) ;
if ( ( V_4 -> V_30 . V_35 ) > 0 )
F_16 ( V_4 , V_4 -> V_30 . V_35 ) ;
V_27 |= V_36 ;
} else {
F_15 ( V_4 -> V_33 , L_2 ) ;
}
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
F_25 ( V_4 , V_53 ) ;
}
F_13 ( V_4 , V_5 -> V_28 ) ;
if ( ( V_4 -> V_30 . V_31 & V_32 ) &&
! ( V_4 -> V_30 . V_31 & V_54 ) )
F_26 ( V_4 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
if ( F_28 ( V_4 ) & V_55 )
return;
if ( ( V_4 -> V_30 . V_31 & V_32 ) &&
! ( V_4 -> V_30 . V_31 & V_54 ) )
F_29 ( V_4 ) ;
F_25 ( V_4 , V_55 ) ;
}
F_18 ( V_4 , V_5 -> V_28 ) ;
}
static void F_26 ( struct V_2 * V_4 )
{
F_21 ( V_4 , V_56 ) ;
F_21 ( V_4 , V_57 ) ;
if ( F_3 ( V_4 ) ) {
F_18 ( V_4 , V_58 | V_59 |
V_4 -> V_60 ) ;
F_25 ( V_4 , V_61 ) ;
} else {
F_18 ( V_4 , V_62 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
F_21 ( V_4 , V_63 ) ;
if ( F_3 ( V_4 ) ) {
F_25 ( V_4 , V_64 ) ;
F_13 ( V_4 , V_58 | V_59 |
V_4 -> V_60 ) ;
} else {
F_13 ( V_4 , V_62 ) ;
}
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_65 = 0 ;
if ( V_5 -> V_66 )
return;
V_5 -> V_66 = true ;
if ( V_5 -> V_67 [ V_13 ] >= 0 )
F_31 ( V_5 -> V_67 [ V_13 ] ) ;
else
V_65 |= V_68 ;
if ( V_5 -> V_67 [ V_16 ] >= 0 )
F_31 ( V_5 -> V_67 [ V_16 ] ) ;
else
V_65 |= V_69 ;
if ( V_5 -> V_67 [ V_19 ] >= 0 )
F_31 ( V_5 -> V_67 [ V_19 ] ) ;
else
V_65 |= V_70 ;
if ( V_5 -> V_67 [ V_22 ] >= 0 )
F_31 ( V_5 -> V_67 [ V_22 ] ) ;
else
V_65 |= V_71 ;
F_18 ( V_4 , V_65 ) ;
}
static void F_32 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_72 = 0 ;
if ( ! V_5 -> V_66 )
return;
V_5 -> V_66 = false ;
if ( V_5 -> V_67 [ V_13 ] >= 0 )
F_33 ( V_5 -> V_67 [ V_13 ] ) ;
else
V_72 |= V_68 ;
if ( V_5 -> V_67 [ V_16 ] >= 0 )
F_33 ( V_5 -> V_67 [ V_16 ] ) ;
else
V_72 |= V_69 ;
if ( V_5 -> V_67 [ V_19 ] >= 0 )
F_33 ( V_5 -> V_67 [ V_19 ] ) ;
else
V_72 |= V_70 ;
if ( V_5 -> V_67 [ V_22 ] >= 0 )
F_33 ( V_5 -> V_67 [ V_22 ] ) ;
else
V_72 |= V_71 ;
F_13 ( V_4 , V_72 ) ;
}
static void F_34 ( struct V_2 * V_4 , int V_73 )
{
if ( V_73 != 0 )
F_21 ( V_4 , V_74 ) ;
else
F_21 ( V_4 , V_75 ) ;
}
static void
F_35 ( struct V_2 * V_4 , unsigned int V_10 ,
unsigned int V_76 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_78 = & V_5 -> V_79 ;
struct V_80 * V_81 ;
if ( ! F_36 ( V_78 -> V_82 , V_78 -> V_83 , V_84 ) )
return;
V_81 = & ( (struct V_80 * ) V_78 -> V_85 ) [ V_78 -> V_82 ] ;
V_81 -> V_10 = V_10 ;
V_81 -> V_76 = V_76 ;
F_37 () ;
V_78 -> V_82 = ( V_78 -> V_82 + 1 ) & ( V_84 - 1 ) ;
}
static void F_38 ( struct V_2 * V_4 , unsigned int V_10 )
{
F_21 ( V_4 , V_56 ) ;
if ( V_10 & V_86 ) {
V_10 &= ~ ( V_87 | V_88 ) ;
V_4 -> V_89 . V_90 ++ ;
}
if ( V_10 & V_87 )
V_4 -> V_89 . V_91 ++ ;
if ( V_10 & V_88 )
V_4 -> V_89 . V_92 ++ ;
if ( V_10 & V_93 )
V_4 -> V_89 . V_94 ++ ;
}
static void F_39 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_76 ;
V_10 = F_8 ( V_4 ) ;
while ( V_10 & V_62 ) {
V_76 = F_40 ( V_4 ) ;
if ( F_41 ( V_10 & ( V_87 | V_88
| V_93 | V_86 )
|| V_5 -> V_95 ) ) {
F_21 ( V_4 , V_56 ) ;
if ( V_10 & V_86
&& ! V_5 -> V_95 ) {
V_5 -> V_95 = 1 ;
F_18 ( V_4 , V_86 ) ;
} else {
F_13 ( V_4 , V_86 ) ;
V_10 &= ~ V_86 ;
V_5 -> V_95 = 0 ;
}
}
F_35 ( V_4 , V_10 , V_76 ) ;
V_10 = F_8 ( V_4 ) ;
}
F_42 ( & V_5 -> V_96 ) ;
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_99 && F_8 ( V_4 ) & V_5 -> V_28 ) {
F_44 ( V_4 , V_4 -> V_99 ) ;
V_4 -> V_89 . V_100 ++ ;
V_4 -> V_99 = 0 ;
}
if ( F_45 ( V_97 ) || F_46 ( V_4 ) )
return;
while ( F_8 ( V_4 ) & V_5 -> V_28 ) {
F_44 ( V_4 , V_97 -> V_85 [ V_97 -> V_83 ] ) ;
V_97 -> V_83 = ( V_97 -> V_83 + 1 ) & ( V_101 - 1 ) ;
V_4 -> V_89 . V_100 ++ ;
if ( F_45 ( V_97 ) )
break;
}
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_97 ) )
F_18 ( V_4 , V_5 -> V_28 ) ;
}
static void F_49 ( void * V_103 )
{
struct V_1 * V_5 = V_103 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
struct V_104 * V_105 = V_5 -> V_106 ;
unsigned long V_31 ;
F_50 ( & V_4 -> V_107 , V_31 ) ;
if ( V_105 )
F_51 ( V_105 ) ;
V_97 -> V_83 += F_52 ( & V_5 -> V_108 ) ;
V_97 -> V_83 &= V_101 - 1 ;
V_4 -> V_89 . V_100 += F_52 ( & V_5 -> V_108 ) ;
F_53 ( & V_5 -> V_109 ) ;
F_54 ( V_5 -> V_110 ) ;
V_5 -> V_111 = - V_112 ;
V_5 -> V_110 = NULL ;
F_55 ( & V_5 -> V_109 ) ;
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_97 ) )
F_42 ( & V_5 -> V_96 ) ;
F_56 ( & V_4 -> V_107 , V_31 ) ;
}
static void F_57 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_104 * V_105 = V_5 -> V_106 ;
if ( V_105 ) {
F_51 ( V_105 ) ;
F_58 ( V_105 ) ;
F_59 ( V_4 -> V_33 , & V_5 -> V_108 , 1 ,
V_113 ) ;
}
V_5 -> V_110 = NULL ;
V_5 -> V_106 = NULL ;
V_5 -> V_111 = - V_112 ;
}
static void F_60 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
struct V_104 * V_105 = V_5 -> V_106 ;
struct V_114 * V_115 ;
struct V_116 * V_117 = & V_5 -> V_108 ;
if ( V_5 -> V_110 != NULL )
return;
if ( ! F_45 ( V_97 ) && ! F_46 ( V_4 ) ) {
V_117 -> V_118 = V_97 -> V_83 & ( V_101 - 1 ) ;
F_61 ( V_117 ) = ( F_61 ( V_117 ) &
~ ( V_101 - 1 ) )
+ V_117 -> V_118 ;
F_52 ( V_117 ) = F_62 ( V_97 -> V_82 ,
V_97 -> V_83 ,
V_101 ) ;
F_63 ( ! F_52 ( V_117 ) ) ;
V_115 = F_64 ( V_105 ,
V_117 ,
1 ,
V_119 ,
V_120 |
V_121 ) ;
if ( ! V_115 ) {
F_65 ( V_4 -> V_33 , L_3 ) ;
return;
}
F_66 ( V_4 -> V_33 , V_117 , 1 , V_119 ) ;
V_5 -> V_110 = V_115 ;
V_115 -> V_122 = F_49 ;
V_115 -> V_123 = V_5 ;
V_5 -> V_111 = F_67 ( V_115 ) ;
} else {
if ( V_4 -> V_30 . V_31 & V_32 ) {
F_26 ( V_4 ) ;
}
}
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_3 V_124 ;
struct V_125 V_126 ;
int V_11 , V_127 ;
F_69 ( V_124 ) ;
F_70 ( V_128 , V_124 ) ;
V_5 -> V_106 = F_71 ( V_4 -> V_33 , L_4 ) ;
if ( V_5 -> V_106 == NULL )
goto V_129;
F_72 ( V_4 -> V_33 , L_5 ,
F_73 ( V_5 -> V_106 ) ) ;
F_74 ( & V_5 -> V_109 ) ;
F_75 ( & V_5 -> V_108 , 1 ) ;
F_63 ( ( int ) V_4 -> V_98 -> V_97 . V_85 & ~ V_130 ) ;
F_76 ( & V_5 -> V_108 ,
F_77 ( V_4 -> V_98 -> V_97 . V_85 ) ,
V_101 ,
( int ) V_4 -> V_98 -> V_97 . V_85 & ~ V_130 ) ;
V_127 = F_78 ( V_4 -> V_33 ,
& V_5 -> V_108 ,
1 ,
V_113 ) ;
if ( ! V_127 ) {
F_15 ( V_4 -> V_33 , L_6 ) ;
goto V_129;
} else {
F_15 ( V_4 -> V_33 , L_7 , V_131 ,
F_52 ( & V_5 -> V_108 ) ,
V_4 -> V_98 -> V_97 . V_85 ,
F_61 ( & V_5 -> V_108 ) ) ;
}
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_132 = V_119 ;
V_126 . V_133 = V_134 ;
V_126 . V_135 = V_4 -> V_136 + V_137 ;
V_11 = F_79 ( V_5 -> V_106 ,
& V_126 ) ;
if ( V_11 ) {
F_65 ( V_4 -> V_33 , L_8 ) ;
goto V_129;
}
return 0 ;
V_129:
F_65 ( V_4 -> V_33 , L_9 ) ;
V_5 -> V_8 = 0 ;
if ( V_5 -> V_106 )
F_57 ( V_4 ) ;
return - V_112 ;
}
static void F_80 ( void * V_103 )
{
struct V_2 * V_4 = V_103 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_96 ) ;
}
static void F_81 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_104 * V_105 = V_5 -> V_138 ;
if ( V_105 ) {
F_51 ( V_105 ) ;
F_58 ( V_105 ) ;
F_59 ( V_4 -> V_33 , & V_5 -> V_139 , 1 ,
V_140 ) ;
}
V_5 -> V_141 = NULL ;
V_5 -> V_138 = NULL ;
V_5 -> V_142 = - V_112 ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_143 * V_144 = & V_4 -> V_98 -> V_4 ;
struct V_77 * V_78 = & V_5 -> V_79 ;
struct V_104 * V_105 = V_5 -> V_138 ;
struct V_145 V_98 ;
enum V_146 V_147 ;
T_4 V_148 ;
F_21 ( V_4 , V_149 ) ;
V_147 = F_83 ( V_105 ,
V_5 -> V_142 ,
& V_98 ) ;
if ( V_147 == V_150 ) {
F_15 ( V_4 -> V_33 , L_10 ) ;
F_18 ( V_4 , V_59 ) ;
F_42 ( & V_5 -> V_96 ) ;
return;
}
F_84 ( V_4 -> V_33 ,
& V_5 -> V_139 ,
1 ,
V_151 ) ;
V_78 -> V_82 = F_52 ( & V_5 -> V_139 ) - V_98 . V_152 ;
F_63 ( V_78 -> V_82 > F_52 ( & V_5 -> V_139 ) ) ;
if ( V_78 -> V_82 < V_78 -> V_83 ) {
V_148 = F_52 ( & V_5 -> V_139 ) - V_78 -> V_83 ;
F_85 ( V_144 , V_78 -> V_85 + V_78 -> V_83 , V_148 ) ;
V_78 -> V_83 = 0 ;
V_4 -> V_89 . V_153 += V_148 ;
}
if ( V_78 -> V_83 < V_78 -> V_82 ) {
V_148 = V_78 -> V_82 - V_78 -> V_83 ;
F_85 ( V_144 , V_78 -> V_85 + V_78 -> V_83 , V_148 ) ;
if ( V_78 -> V_82 >= F_52 ( & V_5 -> V_139 ) )
V_78 -> V_82 = 0 ;
V_78 -> V_83 = V_78 -> V_82 ;
V_4 -> V_89 . V_153 += V_148 ;
}
F_66 ( V_4 -> V_33 ,
& V_5 -> V_139 ,
1 ,
V_151 ) ;
F_86 ( & V_4 -> V_107 ) ;
F_87 ( V_144 ) ;
F_88 ( & V_4 -> V_107 ) ;
F_18 ( V_4 , V_59 ) ;
}
static int F_89 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_114 * V_115 ;
T_3 V_124 ;
struct V_125 V_126 ;
struct V_77 * V_78 ;
int V_11 , V_127 ;
V_78 = & V_5 -> V_79 ;
F_69 ( V_124 ) ;
F_70 ( V_154 , V_124 ) ;
V_5 -> V_138 = F_71 ( V_4 -> V_33 , L_11 ) ;
if ( V_5 -> V_138 == NULL )
goto V_129;
F_72 ( V_4 -> V_33 , L_12 ,
F_73 ( V_5 -> V_138 ) ) ;
F_74 ( & V_5 -> V_155 ) ;
F_75 ( & V_5 -> V_139 , 1 ) ;
F_63 ( ( int ) V_4 -> V_98 -> V_97 . V_85 & ~ V_130 ) ;
F_76 ( & V_5 -> V_139 ,
F_77 ( V_78 -> V_85 ) ,
V_84 ,
( int ) V_78 -> V_85 & ~ V_130 ) ;
V_127 = F_78 ( V_4 -> V_33 ,
& V_5 -> V_139 ,
1 ,
V_140 ) ;
if ( ! V_127 ) {
F_15 ( V_4 -> V_33 , L_6 ) ;
goto V_129;
} else {
F_15 ( V_4 -> V_33 , L_7 , V_131 ,
F_52 ( & V_5 -> V_139 ) ,
V_78 -> V_85 ,
F_61 ( & V_5 -> V_139 ) ) ;
}
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_132 = V_151 ;
V_126 . V_156 = V_134 ;
V_126 . V_157 = V_4 -> V_136 + V_158 ;
V_11 = F_79 ( V_5 -> V_138 ,
& V_126 ) ;
if ( V_11 ) {
F_65 ( V_4 -> V_33 , L_13 ) ;
goto V_129;
}
V_115 = F_90 ( V_5 -> V_138 ,
F_61 ( & V_5 -> V_139 ) ,
F_52 ( & V_5 -> V_139 ) ,
F_52 ( & V_5 -> V_139 ) / 2 ,
V_151 ,
V_120 ) ;
V_115 -> V_122 = F_80 ;
V_115 -> V_123 = V_4 ;
V_5 -> V_141 = V_115 ;
V_5 -> V_142 = F_67 ( V_115 ) ;
return 0 ;
V_129:
F_65 ( V_4 -> V_33 , L_14 ) ;
V_5 -> V_9 = 0 ;
if ( V_5 -> V_138 )
F_81 ( V_4 ) ;
return - V_112 ;
}
static void F_91 ( unsigned long V_159 )
{
struct V_2 * V_4 = ( void * ) V_159 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_96 ) ;
F_92 ( & V_5 -> V_160 , V_161 + F_93 ( V_4 ) ) ;
}
static void
F_94 ( struct V_2 * V_4 , unsigned int V_162 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_162 & ( V_58 | V_59 ) ) {
F_13 ( V_4 , ( V_58
| V_59 ) ) ;
F_42 ( & V_5 -> V_96 ) ;
}
if ( V_162 & ( V_86 | V_93 |
V_88 | V_87 ) )
F_38 ( V_4 , V_162 ) ;
}
if ( F_6 ( V_4 ) ) {
if ( V_162 & V_59 ) {
F_13 ( V_4 , V_59 ) ;
F_42 ( & V_5 -> V_96 ) ;
}
}
if ( V_162 & V_62 )
F_39 ( V_4 ) ;
else if ( V_162 & V_86 ) {
F_21 ( V_4 , V_56 ) ;
F_13 ( V_4 , V_86 ) ;
V_5 -> V_95 = 0 ;
}
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_162 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_162 & V_5 -> V_28 ) {
F_13 ( V_4 , V_5 -> V_28 ) ;
F_42 ( & V_5 -> V_96 ) ;
}
}
static void
F_96 ( struct V_2 * V_4 , unsigned int V_162 ,
unsigned int V_10 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_162 & ( V_70 | V_69 | V_71
| V_68 ) ) {
V_5 -> V_163 = V_10 ;
F_42 ( & V_5 -> V_96 ) ;
}
}
static T_5 F_97 ( int V_164 , void * V_165 )
{
struct V_2 * V_4 = V_165 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_162 , V_166 = 0 ;
bool V_167 = false ;
do {
V_10 = F_7 ( V_4 ) ;
V_162 = V_10 & F_98 ( V_4 ) ;
if ( ! V_167 ) {
if ( V_164 == V_5 -> V_67 [ V_13 ] )
V_162 |= V_68 ;
if ( V_164 == V_5 -> V_67 [ V_16 ] )
V_162 |= V_69 ;
if ( V_164 == V_5 -> V_67 [ V_19 ] )
V_162 |= V_70 ;
if ( V_164 == V_5 -> V_67 [ V_22 ] )
V_162 |= V_71 ;
V_167 = true ;
}
if ( ! V_162 )
break;
F_94 ( V_4 , V_162 ) ;
F_96 ( V_4 , V_162 , V_10 ) ;
F_95 ( V_4 , V_162 ) ;
} while ( V_166 ++ < V_168 );
return V_166 ? V_169 : V_170 ;
}
static void F_99 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_171 * V_172 = & V_5 -> V_173 ;
F_100 ( V_4 -> V_33 ,
V_172 -> V_174 ,
V_172 -> V_175 ,
V_113 ) ;
}
static void F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
struct V_171 * V_172 = & V_5 -> V_173 ;
int V_148 ;
if ( F_102 ( V_4 ) )
return;
V_97 -> V_83 += V_172 -> V_176 ;
V_97 -> V_83 &= V_101 - 1 ;
V_4 -> V_89 . V_100 += V_172 -> V_176 ;
V_172 -> V_176 = 0 ;
F_25 ( V_4 , V_53 ) ;
if ( ! F_45 ( V_97 ) && ! F_46 ( V_4 ) ) {
F_103 ( V_4 -> V_33 ,
V_172 -> V_174 ,
V_172 -> V_175 ,
V_113 ) ;
V_148 = F_62 ( V_97 -> V_82 , V_97 -> V_83 , V_101 ) ;
V_172 -> V_176 = V_148 ;
F_104 ( V_4 , V_172 -> V_174 + V_97 -> V_83 ) ;
F_105 ( V_4 , V_148 ) ;
F_25 ( V_4 , V_55 ) ;
F_18 ( V_4 , V_5 -> V_28 ) ;
} else {
if ( ( V_4 -> V_30 . V_31 & V_32 ) &&
! ( V_4 -> V_30 . V_31 & V_54 ) ) {
F_26 ( V_4 ) ;
}
}
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
}
static int F_106 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_171 * V_172 = & V_5 -> V_173 ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
V_172 -> V_85 = V_97 -> V_85 ;
V_172 -> V_174 = F_107 ( V_4 -> V_33 ,
V_172 -> V_85 ,
V_101 ,
V_113 ) ;
V_172 -> V_175 = V_101 ;
V_172 -> V_176 = 0 ;
return 0 ;
}
static void F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_78 = & V_5 -> V_79 ;
unsigned int V_177 ;
unsigned int V_10 ;
while ( V_78 -> V_82 != V_78 -> V_83 ) {
struct V_80 V_81 ;
F_109 () ;
V_81 = ( (struct V_80 * ) V_78 -> V_85 ) [ V_78 -> V_83 ] ;
V_78 -> V_83 = ( V_78 -> V_83 + 1 ) & ( V_84 - 1 ) ;
V_4 -> V_89 . V_153 ++ ;
V_10 = V_81 . V_10 ;
V_177 = V_178 ;
if ( F_41 ( V_10 & ( V_87 | V_88
| V_93 | V_86 ) ) ) {
if ( V_10 & V_86 ) {
V_10 &= ~ ( V_87 | V_88 ) ;
V_4 -> V_89 . V_90 ++ ;
if ( F_110 ( V_4 ) )
continue;
}
if ( V_10 & V_87 )
V_4 -> V_89 . V_91 ++ ;
if ( V_10 & V_88 )
V_4 -> V_89 . V_92 ++ ;
if ( V_10 & V_93 )
V_4 -> V_89 . V_94 ++ ;
V_10 &= V_4 -> V_60 ;
if ( V_10 & V_86 )
V_177 = V_179 ;
else if ( V_10 & V_87 )
V_177 = V_180 ;
else if ( V_10 & V_88 )
V_177 = V_181 ;
}
if ( F_111 ( V_4 , V_81 . V_76 ) )
continue;
F_112 ( V_4 , V_10 , V_93 , V_81 . V_76 , V_177 ) ;
}
F_86 ( & V_4 -> V_107 ) ;
F_87 ( & V_4 -> V_98 -> V_4 ) ;
F_88 ( & V_4 -> V_107 ) ;
}
static void F_113 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_182 ;
for ( V_182 = 0 ; V_182 < 2 ; V_182 ++ ) {
struct V_171 * V_172 = & V_5 -> V_183 [ V_182 ] ;
F_100 ( V_4 -> V_33 ,
V_172 -> V_174 ,
V_172 -> V_175 ,
V_140 ) ;
F_114 ( V_172 -> V_85 ) ;
}
}
static void F_115 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_143 * V_144 = & V_4 -> V_98 -> V_4 ;
struct V_171 * V_172 ;
int V_184 = V_5 -> V_185 ;
unsigned int V_82 ;
unsigned int V_83 ;
unsigned int V_148 ;
do {
F_21 ( V_4 , V_149 ) ;
V_172 = & V_5 -> V_183 [ V_184 ] ;
V_82 = F_116 ( V_4 ) - V_172 -> V_174 ;
V_83 = V_172 -> V_176 ;
V_82 = F_117 ( V_82 , V_172 -> V_175 ) ;
if ( F_118 ( V_82 != V_83 ) ) {
F_119 ( V_4 -> V_33 , V_172 -> V_174 ,
V_172 -> V_175 , V_140 ) ;
V_148 = V_82 - V_83 ;
F_85 ( V_144 , V_172 -> V_85 + V_172 -> V_176 ,
V_148 ) ;
F_103 ( V_4 -> V_33 , V_172 -> V_174 ,
V_172 -> V_175 , V_140 ) ;
V_4 -> V_89 . V_153 += V_148 ;
V_172 -> V_176 = V_82 ;
}
if ( V_82 >= V_172 -> V_175 ) {
V_172 -> V_176 = 0 ;
F_120 ( V_4 , V_172 -> V_174 ) ;
F_121 ( V_4 , V_172 -> V_175 ) ;
V_184 = ! V_184 ;
V_5 -> V_185 = V_184 ;
}
} while ( V_82 >= V_172 -> V_175 );
F_86 ( & V_4 -> V_107 ) ;
F_87 ( V_144 ) ;
F_88 ( & V_4 -> V_107 ) ;
F_18 ( V_4 , V_58 | V_59 ) ;
}
static int F_122 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_182 ;
for ( V_182 = 0 ; V_182 < 2 ; V_182 ++ ) {
struct V_171 * V_172 = & V_5 -> V_183 [ V_182 ] ;
V_172 -> V_85 = F_123 ( V_186 , V_187 ) ;
if ( V_172 -> V_85 == NULL ) {
if ( V_182 != 0 ) {
F_100 ( V_4 -> V_33 ,
V_5 -> V_183 [ 0 ] . V_174 ,
V_186 ,
V_140 ) ;
F_114 ( V_5 -> V_183 [ 0 ] . V_85 ) ;
}
V_5 -> V_6 = 0 ;
return - V_188 ;
}
V_172 -> V_174 = F_107 ( V_4 -> V_33 ,
V_172 -> V_85 ,
V_186 ,
V_140 ) ;
V_172 -> V_175 = V_186 ;
V_172 -> V_176 = 0 ;
}
V_5 -> V_185 = 0 ;
F_124 ( V_4 , V_5 -> V_183 [ 0 ] . V_174 ) ;
F_125 ( V_4 , V_186 ) ;
F_120 ( V_4 , V_5 -> V_183 [ 1 ] . V_174 ) ;
F_121 ( V_4 , V_186 ) ;
return 0 ;
}
static void F_126 ( unsigned long V_159 )
{
struct V_2 * V_4 = (struct V_2 * ) V_159 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 ;
unsigned int V_189 ;
F_88 ( & V_4 -> V_107 ) ;
V_5 -> V_190 ( V_4 ) ;
V_10 = V_5 -> V_163 ;
V_189 = V_10 ^ V_5 -> V_191 ;
if ( V_189 & ( V_21 | V_18
| V_24 | V_15 ) ) {
if ( V_189 & V_21 )
V_4 -> V_89 . V_192 ++ ;
if ( V_189 & V_18 )
V_4 -> V_89 . V_193 ++ ;
if ( V_189 & V_24 )
F_127 ( V_4 , ! ( V_10 & V_24 ) ) ;
if ( V_189 & V_15 )
F_128 ( V_4 , ! ( V_10 & V_15 ) ) ;
F_129 ( & V_4 -> V_98 -> V_4 . V_194 ) ;
V_5 -> V_191 = V_10 ;
}
V_5 -> V_195 ( V_4 ) ;
F_86 ( & V_4 -> V_107 ) ;
}
static int F_130 ( struct V_1 * V_5 ,
struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_33 . V_200 ;
struct V_201 * V_202 = F_131 ( & V_197 -> V_33 ) ;
if ( V_199 ) {
if ( F_132 ( V_199 , L_15 , NULL ) ) {
if ( F_132 ( V_199 , L_16 , NULL ) ) {
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
if ( F_132 ( V_199 , L_17 , NULL ) ) {
if ( F_132 ( V_199 , L_16 , NULL ) ) {
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
V_5 -> V_6 = V_202 -> V_9 ;
V_5 -> V_7 = V_202 -> V_8 ;
V_5 -> V_9 = false ;
V_5 -> V_8 = false ;
}
return 0 ;
}
static void F_133 ( struct V_2 * V_4 ,
struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_33 . V_200 ;
struct V_201 * V_202 = F_131 ( & V_197 -> V_33 ) ;
if ( V_199 ) {
T_6 V_203 [ 2 ] ;
if ( F_134 ( V_199 , L_18 ,
V_203 , 2 ) == 0 ) {
struct V_25 * V_26 = & V_4 -> V_30 ;
V_26 -> V_204 = V_203 [ 0 ] ;
V_26 -> V_35 = V_203 [ 1 ] ;
V_26 -> V_31 = 0 ;
if ( F_132 ( V_199 , L_19 , NULL ) )
V_26 -> V_31 |= V_54 ;
if ( F_132 ( V_199 , L_20 ,
NULL ) )
V_26 -> V_31 |= V_32 ;
}
} else {
V_4 -> V_30 = V_202 -> V_30 ;
}
}
static void F_135 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_6 ( V_4 ) ) {
V_5 -> V_205 = & F_89 ;
V_5 -> V_195 = & F_82 ;
V_5 -> V_206 = & F_81 ;
} else if ( F_3 ( V_4 ) ) {
V_5 -> V_205 = & F_122 ;
V_5 -> V_195 = & F_115 ;
V_5 -> V_206 = & F_113 ;
} else {
V_5 -> V_205 = NULL ;
V_5 -> V_195 = & F_108 ;
V_5 -> V_206 = NULL ;
}
if ( F_5 ( V_4 ) ) {
V_5 -> V_207 = & F_68 ;
V_5 -> V_190 = & F_60 ;
V_5 -> V_208 = & F_57 ;
} else if ( F_4 ( V_4 ) ) {
V_5 -> V_207 = & F_106 ;
V_5 -> V_190 = & F_101 ;
V_5 -> V_208 = & F_99 ;
} else {
V_5 -> V_207 = NULL ;
V_5 -> V_190 = & F_43 ;
V_5 -> V_208 = NULL ;
}
}
static void F_136 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_209 = F_137 ( V_4 ) ;
T_6 V_210 ;
int V_211 , V_3 ;
V_211 = 0x55534152 ;
V_3 = 0x44424755 ;
V_5 -> V_212 = false ;
if ( V_209 == V_211 ) {
F_15 ( V_4 -> V_33 , L_21 ) ;
V_5 -> V_212 = true ;
} else if ( V_209 == V_3 ) {
F_15 ( V_4 -> V_33 , L_22 ) ;
V_5 -> V_212 = false ;
} else {
V_210 = F_138 ( V_4 ) ;
switch ( V_210 ) {
case 0x302 :
case 0x10213 :
F_15 ( V_4 -> V_33 , L_23 ) ;
V_5 -> V_212 = true ;
break;
case 0x203 :
case 0x10202 :
F_15 ( V_4 -> V_33 , L_24 ) ;
V_5 -> V_212 = false ;
break;
default:
F_65 ( V_4 -> V_33 , L_25 ) ;
}
}
}
static void F_139 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
enum V_213 V_182 ;
for ( V_182 = 0 ; V_182 < V_214 ; V_182 ++ )
if ( V_5 -> V_67 [ V_182 ] >= 0 )
F_140 ( V_5 -> V_67 [ V_182 ] , V_4 ) ;
}
static int F_141 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int * V_164 = V_5 -> V_67 ;
enum V_213 V_182 ;
int V_215 = 0 ;
for ( V_182 = 0 ; ( V_182 < V_214 ) && ! V_215 ; V_182 ++ ) {
if ( V_164 [ V_182 ] < 0 )
continue;
F_142 ( V_164 [ V_182 ] , V_216 ) ;
V_215 = F_143 ( V_164 [ V_182 ] , F_97 , V_217 ,
L_26 , V_4 ) ;
if ( V_215 )
F_65 ( V_4 -> V_33 , L_27 ,
V_164 [ V_182 ] ) ;
}
while ( V_215 && ( -- V_182 >= 0 ) )
if ( V_164 [ V_182 ] >= 0 )
F_140 ( V_164 [ V_182 ] , V_4 ) ;
return V_215 ;
}
static int F_144 ( struct V_2 * V_4 )
{
struct V_196 * V_197 = F_145 ( V_4 -> V_33 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_218 * V_219 = V_4 -> V_98 -> V_4 . V_219 ;
int V_220 ;
F_13 ( V_4 , - 1 ) ;
V_5 -> V_66 = false ;
V_220 = F_143 ( V_4 -> V_164 , F_97 , V_221 ,
V_219 ? V_219 -> V_209 : L_26 , V_4 ) ;
if ( V_220 ) {
F_65 ( V_4 -> V_33 , L_28 ) ;
return V_220 ;
}
V_220 = F_141 ( V_4 ) ;
if ( V_220 )
goto F_140;
F_130 ( V_5 , V_197 ) ;
if ( V_5 -> V_205 ) {
V_220 = V_5 -> V_205 ( V_4 ) ;
if ( V_220 < 0 )
F_135 ( V_4 ) ;
}
if ( V_5 -> V_207 ) {
V_220 = V_5 -> V_207 ( V_4 ) ;
if ( V_220 < 0 )
F_135 ( V_4 ) ;
}
V_5 -> V_191 = F_7 ( V_4 ) ;
V_5 -> V_163 = V_5 -> V_191 ;
F_21 ( V_4 , V_56 | V_222 ) ;
F_21 ( V_4 , V_223 | V_57 ) ;
F_146 ( & V_5 -> V_160 ,
F_91 ,
( unsigned long ) V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( ! V_5 -> V_212 ) {
F_92 ( & V_5 -> V_160 ,
V_161 + F_93 ( V_4 ) ) ;
} else {
F_147 ( V_4 , V_224 ) ;
F_21 ( V_4 , V_149 ) ;
F_18 ( V_4 , V_58 | V_59 ) ;
}
F_25 ( V_4 , V_61 ) ;
} else if ( F_6 ( V_4 ) ) {
if ( ! V_5 -> V_212 ) {
F_92 ( & V_5 -> V_160 ,
V_161 + F_93 ( V_4 ) ) ;
} else {
F_147 ( V_4 , V_224 ) ;
F_21 ( V_4 , V_149 ) ;
F_18 ( V_4 , V_59 ) ;
}
} else {
F_18 ( V_4 , V_62 ) ;
}
return 0 ;
F_140:
F_140 ( V_4 -> V_164 , V_4 ) ;
return V_220 ;
}
static void F_148 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_105 ( V_4 , 0 ) ;
V_5 -> V_173 . V_176 = 0 ;
}
}
static void F_149 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_150 ( & V_5 -> V_160 ) ;
F_151 ( & V_5 -> V_96 ) ;
F_29 ( V_4 ) ;
F_24 ( V_4 ) ;
F_21 ( V_4 , V_56 ) ;
F_13 ( V_4 , - 1 ) ;
if ( V_5 -> V_206 )
V_5 -> V_206 ( V_4 ) ;
if ( V_5 -> V_208 )
V_5 -> V_208 ( V_4 ) ;
V_5 -> V_79 . V_82 = 0 ;
V_5 -> V_79 . V_83 = 0 ;
F_140 ( V_4 -> V_164 , V_4 ) ;
F_139 ( V_4 ) ;
V_5 -> V_66 = false ;
F_148 ( V_4 ) ;
}
static void F_152 ( struct V_2 * V_4 , unsigned int V_98 ,
unsigned int V_225 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_98 ) {
case 0 :
F_153 ( V_5 -> V_226 ) ;
F_18 ( V_4 , V_5 -> V_227 ) ;
break;
case 3 :
V_5 -> V_227 = F_98 ( V_4 ) ;
F_13 ( V_4 , - 1 ) ;
F_154 ( V_5 -> V_226 ) ;
break;
default:
F_65 ( V_4 -> V_33 , L_29 , V_98 ) ;
}
}
static void F_155 ( struct V_2 * V_4 , struct V_228 * V_229 ,
struct V_228 * V_230 )
{
unsigned long V_31 ;
unsigned int V_27 , V_231 , V_232 , V_233 ;
V_27 = F_14 ( V_4 ) & ~ ( V_234 | V_235
| V_236 | V_237
| V_29 ) ;
V_233 = F_156 ( V_4 , V_229 , V_230 , 0 , V_4 -> V_238 / 16 ) ;
V_232 = F_157 ( V_4 , V_233 ) ;
if ( V_232 > 65535 ) {
V_232 /= 8 ;
V_27 |= V_239 ;
}
switch ( V_229 -> V_240 & V_241 ) {
case V_242 :
V_27 |= V_243 ;
break;
case V_244 :
V_27 |= V_245 ;
break;
case V_246 :
V_27 |= V_247 ;
break;
default:
V_27 |= V_248 ;
break;
}
if ( V_229 -> V_240 & V_249 )
V_27 |= V_250 ;
if ( V_229 -> V_240 & V_251 ) {
if ( V_229 -> V_240 & V_252 ) {
if ( V_229 -> V_240 & V_253 )
V_27 |= V_254 ;
else
V_27 |= V_255 ;
} else if ( V_229 -> V_240 & V_253 )
V_27 |= V_256 ;
else
V_27 |= V_257 ;
} else
V_27 |= V_258 ;
if ( V_229 -> V_240 & V_259 )
V_27 |= V_260 ;
else
V_27 |= V_261 ;
F_50 ( & V_4 -> V_107 , V_31 ) ;
V_4 -> V_60 = V_93 ;
if ( V_229 -> V_262 & V_263 )
V_4 -> V_60 |= ( V_88 | V_87 ) ;
if ( V_229 -> V_262 & ( V_264 | V_265 | V_266 ) )
V_4 -> V_60 |= V_86 ;
if ( F_3 ( V_4 ) )
F_18 ( V_4 , V_4 -> V_60 ) ;
V_4 -> V_267 = 0 ;
if ( V_229 -> V_262 & V_268 )
V_4 -> V_267 |= ( V_88 | V_87 ) ;
if ( V_229 -> V_262 & V_264 ) {
V_4 -> V_267 |= V_86 ;
if ( V_229 -> V_262 & V_268 )
V_4 -> V_267 |= V_93 ;
}
F_158 ( V_4 , V_229 -> V_240 , V_233 ) ;
V_231 = F_98 ( V_4 ) ;
F_13 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_269 | V_63 ) ;
V_27 &= ~ V_29 ;
if ( V_4 -> V_30 . V_31 & V_32 ) {
if ( ( V_4 -> V_30 . V_35 ) > 0 )
F_16 ( V_4 , V_4 -> V_30 . V_35 ) ;
V_27 |= V_36 ;
}
F_17 ( V_4 , V_27 ) ;
F_159 ( V_4 , V_232 ) ;
F_21 ( V_4 , V_56 | V_222 ) ;
F_21 ( V_4 , V_223 | V_57 ) ;
F_18 ( V_4 , V_231 ) ;
if ( F_160 ( V_4 , V_229 -> V_240 ) )
F_30 ( V_4 ) ;
else
F_32 ( V_4 ) ;
F_56 ( & V_4 -> V_107 , V_31 ) ;
}
static void F_161 ( struct V_2 * V_4 , struct V_228 * V_229 )
{
if ( V_229 -> V_270 == V_271 ) {
V_4 -> V_31 |= V_272 ;
F_53 ( & V_4 -> V_107 ) ;
F_30 ( V_4 ) ;
F_55 ( & V_4 -> V_107 ) ;
} else {
V_4 -> V_31 &= ~ V_272 ;
if ( ! F_160 ( V_4 , V_229 -> V_240 ) ) {
F_53 ( & V_4 -> V_107 ) ;
F_32 ( V_4 ) ;
F_55 ( & V_4 -> V_107 ) ;
}
}
}
static const char * F_162 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_273 ) ? L_30 : NULL ;
}
static void F_163 ( struct V_2 * V_4 )
{
struct V_196 * V_197 = F_145 ( V_4 -> V_33 ) ;
int V_274 = V_197 -> V_275 [ 0 ] . V_276 - V_197 -> V_275 [ 0 ] . V_277 + 1 ;
F_164 ( V_4 -> V_136 , V_274 ) ;
if ( V_4 -> V_31 & V_278 ) {
F_165 ( V_4 -> V_279 ) ;
V_4 -> V_279 = NULL ;
}
}
static int F_166 ( struct V_2 * V_4 )
{
struct V_196 * V_197 = F_145 ( V_4 -> V_33 ) ;
int V_274 = V_197 -> V_275 [ 0 ] . V_276 - V_197 -> V_275 [ 0 ] . V_277 + 1 ;
if ( ! F_167 ( V_4 -> V_136 , V_274 , L_26 ) )
return - V_280 ;
if ( V_4 -> V_31 & V_278 ) {
V_4 -> V_279 = F_168 ( V_4 -> V_136 , V_274 ) ;
if ( V_4 -> V_279 == NULL ) {
F_164 ( V_4 -> V_136 , V_274 ) ;
return - V_188 ;
}
}
return 0 ;
}
static void F_169 ( struct V_2 * V_4 , int V_31 )
{
if ( V_31 & V_281 ) {
V_4 -> type = V_273 ;
F_166 ( V_4 ) ;
}
}
static int F_170 ( struct V_2 * V_4 , struct V_282 * V_283 )
{
int V_11 = 0 ;
if ( V_283 -> type != V_284 && V_283 -> type != V_273 )
V_11 = - V_112 ;
if ( V_4 -> V_164 != V_283 -> V_164 )
V_11 = - V_112 ;
if ( V_283 -> V_285 != V_286 )
V_11 = - V_112 ;
if ( V_4 -> V_238 / 16 != V_283 -> V_287 )
V_11 = - V_112 ;
if ( ( void * ) V_4 -> V_136 != V_283 -> V_288 )
V_11 = - V_112 ;
if ( V_4 -> V_289 != V_283 -> V_4 )
V_11 = - V_112 ;
if ( V_283 -> V_290 != 0 )
V_11 = - V_112 ;
return V_11 ;
}
static int F_171 ( struct V_2 * V_4 )
{
while ( ! ( F_8 ( V_4 ) & V_62 ) )
F_172 () ;
return F_40 ( V_4 ) ;
}
static void F_173 ( struct V_2 * V_4 , unsigned char V_76 )
{
while ( ! ( F_8 ( V_4 ) & V_39 ) )
F_172 () ;
F_44 ( V_4 , V_76 ) ;
}
static int F_174 ( struct V_1 * V_5 ,
struct V_196 * V_197 )
{
int V_11 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_201 * V_202 = F_131 ( & V_197 -> V_33 ) ;
if ( ! F_130 ( V_5 , V_197 ) )
F_135 ( V_4 ) ;
F_133 ( V_4 , V_197 ) ;
V_4 -> V_291 = V_292 ;
V_4 -> V_31 = V_293 ;
V_4 -> V_294 = & V_295 ;
V_4 -> V_296 = 1 ;
V_4 -> V_33 = & V_197 -> V_33 ;
V_4 -> V_136 = V_197 -> V_275 [ 0 ] . V_277 ;
V_4 -> V_164 = V_197 -> V_275 [ 1 ] . V_277 ;
V_4 -> V_297 = F_12 ;
F_175 ( & V_5 -> V_96 , F_126 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_79 , 0 , sizeof( V_5 -> V_79 ) ) ;
if ( V_202 && V_202 -> V_298 ) {
V_4 -> V_279 = V_202 -> V_298 ;
} else {
V_4 -> V_31 |= V_278 ;
V_4 -> V_279 = NULL ;
}
if ( ! V_5 -> V_226 ) {
V_5 -> V_226 = F_176 ( & V_197 -> V_33 , L_31 ) ;
if ( F_177 ( V_5 -> V_226 ) ) {
V_11 = F_178 ( V_5 -> V_226 ) ;
V_5 -> V_226 = NULL ;
return V_11 ;
}
V_11 = F_153 ( V_5 -> V_226 ) ;
if ( V_11 ) {
F_179 ( V_5 -> V_226 ) ;
V_5 -> V_226 = NULL ;
return V_11 ;
}
V_4 -> V_238 = F_180 ( V_5 -> V_226 ) ;
F_154 ( V_5 -> V_226 ) ;
}
if ( V_4 -> V_30 . V_31 & V_32 )
V_5 -> V_28 = V_34 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_296 = V_186 ;
V_5 -> V_28 = V_37 | V_38 ;
} else {
V_5 -> V_28 = V_39 ;
}
return 0 ;
}
static void F_181 ( struct V_2 * V_4 , int V_76 )
{
while ( ! ( F_8 ( V_4 ) & V_39 ) )
F_172 () ;
F_44 ( V_4 , V_76 ) ;
}
static void F_182 ( struct V_299 * V_300 , const char * V_301 , T_1 V_148 )
{
struct V_2 * V_4 = & V_302 [ V_300 -> V_303 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_231 ;
unsigned int V_173 ;
V_231 = F_98 ( V_4 ) ;
F_13 ( V_4 , V_62 | V_5 -> V_28 ) ;
V_173 = F_28 ( V_4 ) & V_55 ;
F_25 ( V_4 , V_53 ) ;
F_183 ( V_4 , V_301 , V_148 , F_181 ) ;
do {
V_10 = F_8 ( V_4 ) ;
} while ( ! ( V_10 & V_39 ) );
if ( V_173 )
F_25 ( V_4 , V_55 ) ;
F_18 ( V_4 , V_231 ) ;
}
static void T_7 F_184 ( struct V_2 * V_4 , int * V_233 ,
int * V_91 , int * V_304 )
{
unsigned int V_305 , V_232 ;
V_232 = F_185 ( V_4 ) & V_306 ;
if ( ! V_232 )
return;
V_305 = F_14 ( V_4 ) & V_235 ;
if ( V_305 == V_248 )
* V_304 = 8 ;
else
* V_304 = 7 ;
V_305 = F_14 ( V_4 ) & V_237 ;
if ( V_305 == V_257 )
* V_91 = 'e' ;
else if ( V_305 == V_256 )
* V_91 = 'o' ;
* V_233 = V_4 -> V_238 / ( 16 * ( V_232 - 1 ) ) ;
}
static int T_7 F_186 ( struct V_299 * V_300 , char * V_307 )
{
int V_11 ;
struct V_2 * V_4 = & V_302 [ V_300 -> V_303 ] . V_3 ;
int V_233 = 115200 ;
int V_304 = 8 ;
int V_91 = 'n' ;
int V_308 = 'n' ;
if ( V_4 -> V_279 == NULL ) {
return - V_309 ;
}
V_11 = F_153 ( V_302 [ V_300 -> V_303 ] . V_226 ) ;
if ( V_11 )
return V_11 ;
F_13 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_56 | V_222 ) ;
F_21 ( V_4 , V_223 | V_57 ) ;
if ( V_307 )
F_187 ( V_307 , & V_233 , & V_91 , & V_304 , & V_308 ) ;
else
F_184 ( V_4 , & V_233 , & V_91 , & V_304 ) ;
return F_188 ( V_4 , V_300 , V_233 , V_91 , V_304 , V_308 ) ;
}
static int T_7 F_189 ( void )
{
int V_11 ;
if ( V_310 ) {
struct V_201 * V_202 =
F_131 ( & V_310 -> V_33 ) ;
int V_311 = V_202 -> V_312 ;
struct V_1 * V_4 = & V_302 [ V_311 ] ;
V_4 -> V_227 = 0 ;
V_4 -> V_3 . line = V_311 ;
F_190 ( V_313 , V_311 , NULL ) ;
V_11 = F_174 ( V_4 , V_310 ) ;
if ( V_11 )
return V_11 ;
F_191 ( & V_314 ) ;
}
return 0 ;
}
static int T_7 F_192 ( void )
{
if ( V_310
&& ! ( V_314 . V_31 & V_315 ) )
F_191 ( & V_314 ) ;
return 0 ;
}
static inline bool F_193 ( struct V_2 * V_4 )
{
return V_4 -> V_316 && V_4 -> V_316 -> V_303 == V_4 -> line ;
}
static inline bool F_193 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_194 ( void )
{
#ifdef F_195
return F_196 () ;
#else
return false ;
#endif
}
static int F_197 ( struct V_196 * V_197 ,
T_8 V_98 )
{
struct V_2 * V_4 = F_198 ( V_197 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_193 ( V_4 ) && V_317 ) {
while ( ! ( F_8 ( V_4 ) & V_34 ) )
F_172 () ;
}
V_5 -> V_318 = F_199 ( & V_197 -> V_33 ) ;
if ( F_194 () )
F_200 ( & V_197 -> V_33 , 0 ) ;
F_201 ( & V_319 , V_4 ) ;
return 0 ;
}
static int F_202 ( struct V_196 * V_197 )
{
struct V_2 * V_4 = F_198 ( V_197 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_203 ( & V_319 , V_4 ) ;
F_200 ( & V_197 -> V_33 , V_5 -> V_318 ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_320 , struct V_321 * V_33 )
{
enum V_213 V_182 ;
struct V_322 * V_323 ;
V_320 -> V_12 = F_205 ( V_33 , 0 ) ;
if ( F_10 ( V_320 -> V_12 ) )
return - 1 ;
for ( V_182 = 0 ; V_182 < V_214 ; V_182 ++ ) {
V_323 = F_11 ( V_320 -> V_12 , V_182 ) ;
if ( V_323 && ( F_206 ( V_323 ) == V_324 ) )
V_320 -> V_67 [ V_182 ] = F_207 ( V_323 ) ;
else
V_320 -> V_67 [ V_182 ] = - V_112 ;
}
return 0 ;
}
static int F_208 ( struct V_196 * V_197 )
{
struct V_1 * V_4 ;
struct V_198 * V_199 = V_197 -> V_33 . V_200 ;
struct V_201 * V_202 = F_131 ( & V_197 -> V_33 ) ;
void * V_159 ;
int V_11 = - V_309 ;
bool V_325 ;
F_209 ( V_84 & ( V_84 - 1 ) ) ;
if ( V_199 )
V_11 = F_210 ( V_199 , L_32 ) ;
else
if ( V_202 )
V_11 = V_202 -> V_312 ;
if ( V_11 < 0 )
V_11 = F_211 ( V_326 , V_327 ) ;
if ( V_11 >= V_327 ) {
V_11 = - V_309 ;
goto V_215;
}
if ( F_212 ( V_11 , V_326 ) ) {
V_11 = - V_280 ;
goto V_215;
}
V_4 = & V_302 [ V_11 ] ;
V_4 -> V_227 = 0 ;
V_4 -> V_3 . line = V_11 ;
V_11 = F_204 ( V_4 , & V_197 -> V_33 ) ;
if ( V_11 < 0 )
F_65 ( & V_197 -> V_33 , L_33 ,
L_34 ) ;
V_11 = F_174 ( V_4 , V_197 ) ;
if ( V_11 )
goto V_215;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_11 = - V_188 ;
V_159 = F_123 ( sizeof( struct V_80 )
* V_84 , V_187 ) ;
if ( ! V_159 )
goto V_328;
V_4 -> V_79 . V_85 = V_159 ;
}
V_325 = V_4 -> V_3 . V_30 . V_31 & V_32 ;
V_11 = F_213 ( & V_319 , & V_4 -> V_3 ) ;
if ( V_11 )
goto V_329;
#ifdef F_214
if ( F_193 ( & V_4 -> V_3 )
&& V_330 -> V_31 & V_315 ) {
F_154 ( V_4 -> V_226 ) ;
}
#endif
F_215 ( & V_197 -> V_33 , 1 ) ;
F_216 ( V_197 , V_4 ) ;
if ( V_325 ) {
F_17 ( & V_4 -> V_3 , V_261 ) ;
F_21 ( & V_4 -> V_3 , V_44 ) ;
}
F_136 ( & V_4 -> V_3 ) ;
return 0 ;
V_329:
F_114 ( V_4 -> V_79 . V_85 ) ;
V_4 -> V_79 . V_85 = NULL ;
V_328:
if ( ! F_193 ( & V_4 -> V_3 ) ) {
F_179 ( V_4 -> V_226 ) ;
V_4 -> V_226 = NULL ;
}
V_215:
return V_11 ;
}
static int F_217 ( struct V_196 * V_197 )
{
struct V_2 * V_4 = F_198 ( V_197 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_11 = 0 ;
F_151 ( & V_5 -> V_96 ) ;
F_215 ( & V_197 -> V_33 , 0 ) ;
V_11 = F_218 ( & V_319 , V_4 ) ;
F_114 ( V_5 -> V_79 . V_85 ) ;
F_219 ( V_4 -> line , V_326 ) ;
F_179 ( V_5 -> V_226 ) ;
return V_11 ;
}
static int T_7 F_220 ( void )
{
int V_11 ;
V_11 = F_221 ( & V_319 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_222 ( & V_331 ) ;
if ( V_11 )
F_223 ( & V_319 ) ;
return V_11 ;
}
static void T_9 F_224 ( void )
{
F_225 ( & V_331 ) ;
F_223 ( & V_319 ) ;
}
