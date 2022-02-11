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
F_63 ( ! F_76 ( V_4 -> V_101 -> V_100 . V_88 ) ) ;
F_77 ( & V_5 -> V_111 ,
F_78 ( V_4 -> V_101 -> V_100 . V_88 ) ,
V_104 ,
( int ) V_4 -> V_101 -> V_100 . V_88 & ~ V_133 ) ;
V_130 = F_79 ( V_4 -> V_33 ,
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
V_129 . V_141 = 1 ;
V_11 = F_80 ( V_5 -> V_109 ,
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
static void F_81 ( void * V_106 )
{
struct V_2 * V_4 = V_106 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_99 ) ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_107 * V_108 = V_5 -> V_142 ;
if ( V_108 ) {
F_51 ( V_108 ) ;
F_58 ( V_108 ) ;
F_59 ( V_4 -> V_33 , & V_5 -> V_143 , 1 ,
V_144 ) ;
}
V_5 -> V_145 = NULL ;
V_5 -> V_142 = NULL ;
V_5 -> V_146 = - V_115 ;
}
static void F_83 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_147 * V_148 = & V_4 -> V_101 -> V_4 ;
struct V_80 * V_81 = & V_5 -> V_82 ;
struct V_107 * V_108 = V_5 -> V_142 ;
struct V_149 V_101 ;
enum V_150 V_151 ;
T_4 V_152 ;
F_21 ( V_4 , V_153 ) ;
V_151 = F_84 ( V_108 ,
V_5 -> V_146 ,
& V_101 ) ;
if ( V_151 == V_154 ) {
F_15 ( V_4 -> V_33 , L_10 ) ;
F_18 ( V_4 , V_62 ) ;
F_42 ( & V_5 -> V_99 ) ;
return;
}
F_85 ( V_4 -> V_33 ,
& V_5 -> V_143 ,
1 ,
V_144 ) ;
V_81 -> V_85 = F_52 ( & V_5 -> V_143 ) - V_101 . V_155 ;
F_63 ( V_81 -> V_85 > F_52 ( & V_5 -> V_143 ) ) ;
if ( V_81 -> V_85 < V_81 -> V_86 ) {
V_152 = F_52 ( & V_5 -> V_143 ) - V_81 -> V_86 ;
F_86 ( V_148 , V_81 -> V_88 + V_81 -> V_86 , V_152 ) ;
V_81 -> V_86 = 0 ;
V_4 -> V_92 . V_156 += V_152 ;
}
if ( V_81 -> V_86 < V_81 -> V_85 ) {
V_152 = V_81 -> V_85 - V_81 -> V_86 ;
F_86 ( V_148 , V_81 -> V_88 + V_81 -> V_86 , V_152 ) ;
if ( V_81 -> V_85 >= F_52 ( & V_5 -> V_143 ) )
V_81 -> V_85 = 0 ;
V_81 -> V_86 = V_81 -> V_85 ;
V_4 -> V_92 . V_156 += V_152 ;
}
F_66 ( V_4 -> V_33 ,
& V_5 -> V_143 ,
1 ,
V_144 ) ;
F_87 ( & V_4 -> V_110 ) ;
F_88 ( V_148 ) ;
F_89 ( & V_4 -> V_110 ) ;
F_18 ( V_4 , V_62 ) ;
}
static int F_90 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_117 * V_118 ;
T_3 V_127 ;
struct V_128 V_129 ;
struct V_80 * V_81 ;
int V_11 , V_130 ;
V_81 = & V_5 -> V_82 ;
F_69 ( V_127 ) ;
F_70 ( V_157 , V_127 ) ;
V_5 -> V_142 = F_71 ( V_4 -> V_33 , L_11 ) ;
if ( V_5 -> V_142 == NULL )
goto V_132;
F_72 ( V_4 -> V_33 , L_12 ,
F_73 ( V_5 -> V_142 ) ) ;
F_74 ( & V_5 -> V_158 ) ;
F_75 ( & V_5 -> V_143 , 1 ) ;
F_63 ( ! F_76 ( V_81 -> V_88 ) ) ;
F_77 ( & V_5 -> V_143 ,
F_78 ( V_81 -> V_88 ) ,
sizeof( struct V_83 ) * V_87 ,
( int ) V_81 -> V_88 & ~ V_133 ) ;
V_130 = F_79 ( V_4 -> V_33 ,
& V_5 -> V_143 ,
1 ,
V_144 ) ;
if ( ! V_130 ) {
F_15 ( V_4 -> V_33 , L_6 ) ;
goto V_132;
} else {
F_15 ( V_4 -> V_33 , L_7 , V_134 ,
F_52 ( & V_5 -> V_143 ) ,
V_81 -> V_88 ,
F_61 ( & V_5 -> V_143 ) ) ;
}
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_135 = V_159 ;
V_129 . V_160 = V_137 ;
V_129 . V_161 = V_4 -> V_139 + V_162 ;
V_129 . V_163 = 1 ;
V_11 = F_80 ( V_5 -> V_142 ,
& V_129 ) ;
if ( V_11 ) {
F_65 ( V_4 -> V_33 , L_13 ) ;
goto V_132;
}
V_118 = F_91 ( V_5 -> V_142 ,
F_61 ( & V_5 -> V_143 ) ,
F_52 ( & V_5 -> V_143 ) ,
F_52 ( & V_5 -> V_143 ) / 2 ,
V_159 ,
V_123 ) ;
V_118 -> V_125 = F_81 ;
V_118 -> V_126 = V_4 ;
V_5 -> V_145 = V_118 ;
V_5 -> V_146 = F_67 ( V_118 ) ;
return 0 ;
V_132:
F_65 ( V_4 -> V_33 , L_14 ) ;
V_5 -> V_9 = 0 ;
if ( V_5 -> V_142 )
F_82 ( V_4 ) ;
return - V_115 ;
}
static void F_92 ( unsigned long V_164 )
{
struct V_2 * V_4 = ( void * ) V_164 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_99 ) ;
F_93 ( & V_5 -> V_165 , V_166 + F_94 ( V_4 ) ) ;
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_167 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_167 & ( V_61 | V_62 ) ) {
F_13 ( V_4 , ( V_61
| V_62 ) ) ;
F_42 ( & V_5 -> V_99 ) ;
}
if ( V_167 & ( V_89 | V_96 |
V_91 | V_90 ) )
F_38 ( V_4 , V_167 ) ;
}
if ( F_6 ( V_4 ) ) {
if ( V_167 & V_62 ) {
F_13 ( V_4 , V_62 ) ;
F_42 ( & V_5 -> V_99 ) ;
}
}
if ( V_167 & V_65 )
F_39 ( V_4 ) ;
else if ( V_167 & V_89 ) {
F_21 ( V_4 , V_59 ) ;
F_13 ( V_4 , V_89 ) ;
V_5 -> V_98 = 0 ;
}
}
static void
F_96 ( struct V_2 * V_4 , unsigned int V_167 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_167 & V_5 -> V_28 ) {
F_13 ( V_4 , V_5 -> V_28 ) ;
F_42 ( & V_5 -> V_99 ) ;
}
}
static void
F_97 ( struct V_2 * V_4 , unsigned int V_167 ,
unsigned int V_10 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_167 & ( V_73 | V_72 | V_74
| V_71 ) ) {
V_5 -> V_168 = V_10 ;
V_5 -> V_169 = V_5 -> V_168 ^
V_5 -> V_170 ;
V_5 -> V_170 = V_10 ;
F_42 ( & V_5 -> V_99 ) ;
}
}
static T_5 F_98 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_167 , V_127 , V_173 = 0 ;
bool V_174 = false ;
F_89 ( & V_5 -> V_175 ) ;
do {
V_10 = F_7 ( V_4 ) ;
V_127 = F_99 ( V_4 ) ;
V_167 = V_10 & V_127 ;
if ( ! V_174 ) {
if ( V_171 == V_5 -> V_70 [ V_13 ] )
V_167 |= V_71 ;
if ( V_171 == V_5 -> V_70 [ V_16 ] )
V_167 |= V_72 ;
if ( V_171 == V_5 -> V_70 [ V_19 ] )
V_167 |= V_73 ;
if ( V_171 == V_5 -> V_70 [ V_22 ] )
V_167 |= V_74 ;
V_174 = true ;
}
if ( ! V_167 )
break;
if ( V_5 -> V_176 ) {
V_5 -> V_167 |= V_167 ;
V_5 -> V_177 = V_10 ;
F_13 ( V_4 , V_127 ) ;
F_100 () ;
break;
}
F_95 ( V_4 , V_167 ) ;
F_97 ( V_4 , V_167 , V_10 ) ;
F_96 ( V_4 , V_167 ) ;
} while ( V_173 ++ < V_178 );
F_87 ( & V_5 -> V_175 ) ;
return V_173 ? V_179 : V_180 ;
}
static void F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_181 * V_182 = & V_5 -> V_183 ;
F_102 ( V_4 -> V_33 ,
V_182 -> V_184 ,
V_182 -> V_185 ,
V_116 ) ;
}
static void F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_80 * V_100 = & V_4 -> V_101 -> V_100 ;
struct V_181 * V_182 = & V_5 -> V_183 ;
int V_152 ;
if ( F_104 ( V_4 ) )
return;
V_100 -> V_86 += V_182 -> V_186 ;
V_100 -> V_86 &= V_104 - 1 ;
V_4 -> V_92 . V_103 += V_182 -> V_186 ;
V_182 -> V_186 = 0 ;
F_25 ( V_4 , V_56 ) ;
if ( ! F_45 ( V_100 ) && ! F_46 ( V_4 ) ) {
F_105 ( V_4 -> V_33 ,
V_182 -> V_184 ,
V_182 -> V_185 ,
V_116 ) ;
V_152 = F_62 ( V_100 -> V_85 , V_100 -> V_86 , V_104 ) ;
V_182 -> V_186 = V_152 ;
F_106 ( V_4 , V_182 -> V_184 + V_100 -> V_86 ) ;
F_107 ( V_4 , V_152 ) ;
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
static int F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_181 * V_182 = & V_5 -> V_183 ;
struct V_80 * V_100 = & V_4 -> V_101 -> V_100 ;
V_182 -> V_88 = V_100 -> V_88 ;
V_182 -> V_184 = F_109 ( V_4 -> V_33 ,
V_182 -> V_88 ,
V_104 ,
V_116 ) ;
V_182 -> V_185 = V_104 ;
V_182 -> V_186 = 0 ;
return 0 ;
}
static void F_110 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_80 * V_81 = & V_5 -> V_82 ;
unsigned int V_187 ;
unsigned int V_10 ;
while ( V_81 -> V_85 != V_81 -> V_86 ) {
struct V_83 V_84 ;
F_111 () ;
V_84 = ( (struct V_83 * ) V_81 -> V_88 ) [ V_81 -> V_86 ] ;
V_81 -> V_86 = ( V_81 -> V_86 + 1 ) & ( V_87 - 1 ) ;
V_4 -> V_92 . V_156 ++ ;
V_10 = V_84 . V_10 ;
V_187 = V_188 ;
if ( F_41 ( V_10 & ( V_90 | V_91
| V_96 | V_89 ) ) ) {
if ( V_10 & V_89 ) {
V_10 &= ~ ( V_90 | V_91 ) ;
V_4 -> V_92 . V_93 ++ ;
if ( F_112 ( V_4 ) )
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
V_187 = V_189 ;
else if ( V_10 & V_90 )
V_187 = V_190 ;
else if ( V_10 & V_91 )
V_187 = V_191 ;
}
if ( F_113 ( V_4 , V_84 . V_79 ) )
continue;
F_114 ( V_4 , V_10 , V_96 , V_84 . V_79 , V_187 ) ;
}
F_87 ( & V_4 -> V_110 ) ;
F_88 ( & V_4 -> V_101 -> V_4 ) ;
F_89 ( & V_4 -> V_110 ) ;
}
static void F_115 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_192 ;
for ( V_192 = 0 ; V_192 < 2 ; V_192 ++ ) {
struct V_181 * V_182 = & V_5 -> V_193 [ V_192 ] ;
F_102 ( V_4 -> V_33 ,
V_182 -> V_184 ,
V_182 -> V_185 ,
V_144 ) ;
F_116 ( V_182 -> V_88 ) ;
}
}
static void F_117 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_147 * V_148 = & V_4 -> V_101 -> V_4 ;
struct V_181 * V_182 ;
int V_194 = V_5 -> V_195 ;
unsigned int V_85 ;
unsigned int V_86 ;
unsigned int V_152 ;
do {
F_21 ( V_4 , V_153 ) ;
V_182 = & V_5 -> V_193 [ V_194 ] ;
V_85 = F_118 ( V_4 ) - V_182 -> V_184 ;
V_86 = V_182 -> V_186 ;
V_85 = F_119 ( V_85 , V_182 -> V_185 ) ;
if ( F_120 ( V_85 != V_86 ) ) {
F_121 ( V_4 -> V_33 , V_182 -> V_184 ,
V_182 -> V_185 , V_144 ) ;
V_152 = V_85 - V_86 ;
F_86 ( V_148 , V_182 -> V_88 + V_182 -> V_186 ,
V_152 ) ;
F_105 ( V_4 -> V_33 , V_182 -> V_184 ,
V_182 -> V_185 , V_144 ) ;
V_4 -> V_92 . V_156 += V_152 ;
V_182 -> V_186 = V_85 ;
}
if ( V_85 >= V_182 -> V_185 ) {
V_182 -> V_186 = 0 ;
F_122 ( V_4 , V_182 -> V_184 ) ;
F_123 ( V_4 , V_182 -> V_185 ) ;
V_194 = ! V_194 ;
V_5 -> V_195 = V_194 ;
}
} while ( V_85 >= V_182 -> V_185 );
F_87 ( & V_4 -> V_110 ) ;
F_88 ( V_148 ) ;
F_89 ( & V_4 -> V_110 ) ;
F_18 ( V_4 , V_61 | V_62 ) ;
}
static int F_124 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_192 ;
for ( V_192 = 0 ; V_192 < 2 ; V_192 ++ ) {
struct V_181 * V_182 = & V_5 -> V_193 [ V_192 ] ;
V_182 -> V_88 = F_125 ( V_196 , V_197 ) ;
if ( V_182 -> V_88 == NULL ) {
if ( V_192 != 0 ) {
F_102 ( V_4 -> V_33 ,
V_5 -> V_193 [ 0 ] . V_184 ,
V_196 ,
V_144 ) ;
F_116 ( V_5 -> V_193 [ 0 ] . V_88 ) ;
}
V_5 -> V_6 = 0 ;
return - V_198 ;
}
V_182 -> V_184 = F_109 ( V_4 -> V_33 ,
V_182 -> V_88 ,
V_196 ,
V_144 ) ;
V_182 -> V_185 = V_196 ;
V_182 -> V_186 = 0 ;
}
V_5 -> V_195 = 0 ;
F_126 ( V_4 , V_5 -> V_193 [ 0 ] . V_184 ) ;
F_127 ( V_4 , V_196 ) ;
F_122 ( V_4 , V_5 -> V_193 [ 1 ] . V_184 ) ;
F_123 ( V_4 , V_196 ) ;
return 0 ;
}
static void F_128 ( unsigned long V_164 )
{
struct V_2 * V_4 = (struct V_2 * ) V_164 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 = V_5 -> V_168 ;
unsigned int V_169 = V_5 -> V_169 ;
F_89 ( & V_4 -> V_110 ) ;
V_5 -> V_199 ( V_4 ) ;
if ( V_169 & ( V_21 | V_18
| V_24 | V_15 ) ) {
if ( V_169 & V_21 )
V_4 -> V_92 . V_200 ++ ;
if ( V_169 & V_18 )
V_4 -> V_92 . V_201 ++ ;
if ( V_169 & V_24 )
F_129 ( V_4 , ! ( V_10 & V_24 ) ) ;
if ( V_169 & V_15 )
F_130 ( V_4 , ! ( V_10 & V_15 ) ) ;
F_131 ( & V_4 -> V_101 -> V_4 . V_202 ) ;
V_5 -> V_169 = 0 ;
}
V_5 -> V_203 ( V_4 ) ;
F_87 ( & V_4 -> V_110 ) ;
}
static void F_132 ( struct V_1 * V_5 ,
struct V_204 * V_205 )
{
struct V_206 * V_207 = V_205 -> V_33 . V_208 ;
struct V_209 * V_210 = F_133 ( & V_205 -> V_33 ) ;
if ( V_207 ) {
if ( F_134 ( V_207 , L_15 , NULL ) ) {
if ( F_134 ( V_207 , L_16 , NULL ) ) {
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
if ( F_134 ( V_207 , L_17 , NULL ) ) {
if ( F_134 ( V_207 , L_16 , NULL ) ) {
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
V_5 -> V_6 = V_210 -> V_9 ;
V_5 -> V_7 = V_210 -> V_8 ;
V_5 -> V_9 = false ;
V_5 -> V_8 = false ;
}
}
static void F_135 ( struct V_2 * V_4 ,
struct V_204 * V_205 )
{
struct V_206 * V_207 = V_205 -> V_33 . V_208 ;
struct V_209 * V_210 = F_133 ( & V_205 -> V_33 ) ;
if ( V_207 ) {
T_6 V_211 [ 2 ] ;
if ( F_136 ( V_207 , L_18 ,
V_211 , 2 ) == 0 ) {
struct V_25 * V_26 = & V_4 -> V_30 ;
V_26 -> V_212 = V_211 [ 0 ] ;
V_26 -> V_35 = V_211 [ 1 ] ;
V_26 -> V_31 = 0 ;
if ( F_134 ( V_207 , L_19 , NULL ) )
V_26 -> V_31 |= V_57 ;
if ( F_134 ( V_207 , L_20 ,
NULL ) )
V_26 -> V_31 |= V_32 ;
}
} else {
V_4 -> V_30 = V_210 -> V_30 ;
}
}
static void F_137 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_6 ( V_4 ) ) {
V_5 -> V_213 = & F_90 ;
V_5 -> V_203 = & F_83 ;
V_5 -> V_214 = & F_82 ;
} else if ( F_3 ( V_4 ) ) {
V_5 -> V_213 = & F_124 ;
V_5 -> V_203 = & F_117 ;
V_5 -> V_214 = & F_115 ;
} else {
V_5 -> V_213 = NULL ;
V_5 -> V_203 = & F_110 ;
V_5 -> V_214 = NULL ;
}
if ( F_5 ( V_4 ) ) {
V_5 -> V_215 = & F_68 ;
V_5 -> V_199 = & F_60 ;
V_5 -> V_216 = & F_57 ;
} else if ( F_4 ( V_4 ) ) {
V_5 -> V_215 = & F_108 ;
V_5 -> V_199 = & F_103 ;
V_5 -> V_216 = & F_101 ;
} else {
V_5 -> V_215 = NULL ;
V_5 -> V_199 = & F_43 ;
V_5 -> V_216 = NULL ;
}
}
static void F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_217 = F_139 ( V_4 ) ;
T_6 V_218 ;
int V_219 , V_3 ;
V_219 = 0x55534152 ;
V_3 = 0x44424755 ;
V_5 -> V_220 = false ;
if ( V_217 == V_219 ) {
F_15 ( V_4 -> V_33 , L_21 ) ;
V_5 -> V_220 = true ;
} else if ( V_217 == V_3 ) {
F_15 ( V_4 -> V_33 , L_22 ) ;
V_5 -> V_220 = false ;
} else {
V_218 = F_140 ( V_4 ) ;
switch ( V_218 ) {
case 0x302 :
case 0x10213 :
F_15 ( V_4 -> V_33 , L_23 ) ;
V_5 -> V_220 = true ;
break;
case 0x203 :
case 0x10202 :
F_15 ( V_4 -> V_33 , L_24 ) ;
V_5 -> V_220 = false ;
break;
default:
F_65 ( V_4 -> V_33 , L_25 ) ;
}
}
}
static void F_141 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
enum V_221 V_192 ;
for ( V_192 = 0 ; V_192 < V_222 ; V_192 ++ )
if ( V_5 -> V_70 [ V_192 ] >= 0 )
F_142 ( V_5 -> V_70 [ V_192 ] , V_4 ) ;
}
static int F_143 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int * V_171 = V_5 -> V_70 ;
enum V_221 V_192 ;
int V_223 = 0 ;
for ( V_192 = 0 ; ( V_192 < V_222 ) && ! V_223 ; V_192 ++ ) {
if ( V_171 [ V_192 ] < 0 )
continue;
F_144 ( V_171 [ V_192 ] , V_224 ) ;
V_223 = F_145 ( V_171 [ V_192 ] , F_98 , V_225 ,
L_26 , V_4 ) ;
if ( V_223 )
F_65 ( V_4 -> V_33 , L_27 ,
V_171 [ V_192 ] ) ;
}
while ( V_223 && ( -- V_192 >= 0 ) )
if ( V_171 [ V_192 ] >= 0 )
F_142 ( V_171 [ V_192 ] , V_4 ) ;
return V_223 ;
}
static int F_146 ( struct V_2 * V_4 )
{
struct V_204 * V_205 = F_147 ( V_4 -> V_33 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_226 * V_227 = V_4 -> V_101 -> V_4 . V_227 ;
int V_228 ;
F_13 ( V_4 , - 1 ) ;
V_5 -> V_69 = false ;
V_228 = F_145 ( V_4 -> V_171 , F_98 ,
V_229 | V_230 ,
V_227 ? V_227 -> V_217 : L_26 , V_4 ) ;
if ( V_228 ) {
F_65 ( V_4 -> V_33 , L_28 ) ;
return V_228 ;
}
V_228 = F_143 ( V_4 ) ;
if ( V_228 )
goto F_142;
F_148 ( & V_5 -> V_99 ) ;
F_132 ( V_5 , V_205 ) ;
F_137 ( V_4 ) ;
if ( V_5 -> V_213 ) {
V_228 = V_5 -> V_213 ( V_4 ) ;
if ( V_228 < 0 )
F_137 ( V_4 ) ;
}
if ( V_5 -> V_215 ) {
V_228 = V_5 -> V_215 ( V_4 ) ;
if ( V_228 < 0 )
F_137 ( V_4 ) ;
}
V_5 -> V_170 = F_7 ( V_4 ) ;
V_5 -> V_168 = V_5 -> V_170 ;
F_21 ( V_4 , V_59 | V_231 ) ;
F_21 ( V_4 , V_232 | V_60 ) ;
F_149 ( & V_5 -> V_165 ,
F_92 ,
( unsigned long ) V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( ! V_5 -> V_220 ) {
F_93 ( & V_5 -> V_165 ,
V_166 + F_94 ( V_4 ) ) ;
} else {
F_150 ( V_4 , V_233 ) ;
F_21 ( V_4 , V_153 ) ;
F_18 ( V_4 , V_61 | V_62 ) ;
}
F_25 ( V_4 , V_64 ) ;
} else if ( F_6 ( V_4 ) ) {
if ( ! V_5 -> V_220 ) {
F_93 ( & V_5 -> V_165 ,
V_166 + F_94 ( V_4 ) ) ;
} else {
F_150 ( V_4 , V_233 ) ;
F_21 ( V_4 , V_153 ) ;
F_18 ( V_4 , V_62 ) ;
}
} else {
F_18 ( V_4 , V_65 ) ;
}
return 0 ;
F_142:
F_142 ( V_4 -> V_171 , V_4 ) ;
return V_228 ;
}
static void F_151 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_107 ( V_4 , 0 ) ;
V_5 -> V_183 . V_186 = 0 ;
}
}
static void F_152 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_153 ( & V_5 -> V_165 ) ;
F_154 ( & V_5 -> V_99 ) ;
F_155 ( & V_5 -> V_99 ) ;
F_29 ( V_4 ) ;
F_24 ( V_4 ) ;
F_21 ( V_4 , V_59 ) ;
F_13 ( V_4 , - 1 ) ;
if ( V_5 -> V_214 )
V_5 -> V_214 ( V_4 ) ;
if ( V_5 -> V_216 )
V_5 -> V_216 ( V_4 ) ;
V_5 -> V_82 . V_85 = 0 ;
V_5 -> V_82 . V_86 = 0 ;
F_142 ( V_4 -> V_171 , V_4 ) ;
F_141 ( V_4 ) ;
V_5 -> V_69 = false ;
F_151 ( V_4 ) ;
}
static void F_156 ( struct V_2 * V_4 , unsigned int V_101 ,
unsigned int V_234 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_101 ) {
case 0 :
F_157 ( V_5 -> V_235 ) ;
F_18 ( V_4 , V_5 -> V_236 ) ;
break;
case 3 :
V_5 -> V_236 = F_99 ( V_4 ) ;
F_13 ( V_4 , - 1 ) ;
F_158 ( V_5 -> V_235 ) ;
break;
default:
F_65 ( V_4 -> V_33 , L_29 , V_101 ) ;
}
}
static void F_159 ( struct V_2 * V_4 , struct V_237 * V_238 ,
struct V_237 * V_239 )
{
unsigned long V_31 ;
unsigned int V_240 , V_27 , V_241 , V_242 , V_243 ;
V_27 = V_240 = F_14 ( V_4 ) ;
V_27 &= ~ ( V_244 | V_245 | V_246 |
V_247 | V_29 ) ;
V_243 = F_160 ( V_4 , V_238 , V_239 , 0 , V_4 -> V_248 / 16 ) ;
V_242 = F_161 ( V_4 , V_243 ) ;
if ( V_242 > 65535 ) {
V_242 /= 8 ;
V_27 |= V_249 ;
}
switch ( V_238 -> V_250 & V_251 ) {
case V_252 :
V_27 |= V_253 ;
break;
case V_254 :
V_27 |= V_255 ;
break;
case V_256 :
V_27 |= V_257 ;
break;
default:
V_27 |= V_258 ;
break;
}
if ( V_238 -> V_250 & V_259 )
V_27 |= V_260 ;
if ( V_238 -> V_250 & V_261 ) {
if ( V_238 -> V_250 & V_262 ) {
if ( V_238 -> V_250 & V_263 )
V_27 |= V_264 ;
else
V_27 |= V_265 ;
} else if ( V_238 -> V_250 & V_263 )
V_27 |= V_266 ;
else
V_27 |= V_267 ;
} else
V_27 |= V_268 ;
F_50 ( & V_4 -> V_110 , V_31 ) ;
V_4 -> V_63 = V_96 ;
if ( V_238 -> V_269 & V_270 )
V_4 -> V_63 |= ( V_91 | V_90 ) ;
if ( V_238 -> V_269 & ( V_271 | V_272 | V_273 ) )
V_4 -> V_63 |= V_89 ;
if ( F_3 ( V_4 ) )
F_18 ( V_4 , V_4 -> V_63 ) ;
V_4 -> V_274 = 0 ;
if ( V_238 -> V_269 & V_275 )
V_4 -> V_274 |= ( V_91 | V_90 ) ;
if ( V_238 -> V_269 & V_271 ) {
V_4 -> V_274 |= V_89 ;
if ( V_238 -> V_269 & V_275 )
V_4 -> V_274 |= V_96 ;
}
F_162 ( V_4 , V_238 -> V_250 , V_243 ) ;
V_241 = F_99 ( V_4 ) ;
F_13 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_276 | V_66 ) ;
if ( V_4 -> V_30 . V_31 & V_32 ) {
F_16 ( V_4 , V_4 -> V_30 . V_35 ) ;
V_27 |= V_36 ;
} else if ( V_238 -> V_250 & V_277 ) {
V_27 |= V_45 ;
} else {
V_27 |= V_278 ;
}
F_17 ( V_4 , V_27 ) ;
if ( ( V_240 & V_29 ) != ( V_27 & V_29 ) ) {
unsigned int V_279 ;
if ( ( V_27 & V_29 ) == V_45 ) {
V_279 = V_47 ;
} else {
V_279 = V_46 ;
}
F_21 ( V_4 , V_279 ) ;
}
F_163 ( V_4 , V_242 ) ;
F_21 ( V_4 , V_59 | V_231 ) ;
F_21 ( V_4 , V_232 | V_60 ) ;
F_18 ( V_4 , V_241 ) ;
if ( F_164 ( V_4 , V_238 -> V_250 ) )
F_30 ( V_4 ) ;
else
F_32 ( V_4 ) ;
F_56 ( & V_4 -> V_110 , V_31 ) ;
}
static void F_165 ( struct V_2 * V_4 , struct V_237 * V_238 )
{
if ( V_238 -> V_280 == V_281 ) {
V_4 -> V_31 |= V_282 ;
F_53 ( & V_4 -> V_110 ) ;
F_30 ( V_4 ) ;
F_55 ( & V_4 -> V_110 ) ;
} else {
V_4 -> V_31 &= ~ V_282 ;
if ( ! F_164 ( V_4 , V_238 -> V_250 ) ) {
F_53 ( & V_4 -> V_110 ) ;
F_32 ( V_4 ) ;
F_55 ( & V_4 -> V_110 ) ;
}
}
}
static const char * F_166 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_283 ) ? L_30 : NULL ;
}
static void F_167 ( struct V_2 * V_4 )
{
struct V_204 * V_205 = F_147 ( V_4 -> V_33 ) ;
int V_284 = V_205 -> V_285 [ 0 ] . V_286 - V_205 -> V_285 [ 0 ] . V_287 + 1 ;
F_168 ( V_4 -> V_139 , V_284 ) ;
if ( V_4 -> V_31 & V_288 ) {
F_169 ( V_4 -> V_289 ) ;
V_4 -> V_289 = NULL ;
}
}
static int F_170 ( struct V_2 * V_4 )
{
struct V_204 * V_205 = F_147 ( V_4 -> V_33 ) ;
int V_284 = V_205 -> V_285 [ 0 ] . V_286 - V_205 -> V_285 [ 0 ] . V_287 + 1 ;
if ( ! F_171 ( V_4 -> V_139 , V_284 , L_26 ) )
return - V_290 ;
if ( V_4 -> V_31 & V_288 ) {
V_4 -> V_289 = F_172 ( V_4 -> V_139 , V_284 ) ;
if ( V_4 -> V_289 == NULL ) {
F_168 ( V_4 -> V_139 , V_284 ) ;
return - V_198 ;
}
}
return 0 ;
}
static void F_173 ( struct V_2 * V_4 , int V_31 )
{
if ( V_31 & V_291 ) {
V_4 -> type = V_283 ;
F_170 ( V_4 ) ;
}
}
static int F_174 ( struct V_2 * V_4 , struct V_292 * V_293 )
{
int V_11 = 0 ;
if ( V_293 -> type != V_294 && V_293 -> type != V_283 )
V_11 = - V_115 ;
if ( V_4 -> V_171 != V_293 -> V_171 )
V_11 = - V_115 ;
if ( V_293 -> V_295 != V_296 )
V_11 = - V_115 ;
if ( V_4 -> V_248 / 16 != V_293 -> V_297 )
V_11 = - V_115 ;
if ( ( void * ) V_4 -> V_139 != V_293 -> V_298 )
V_11 = - V_115 ;
if ( V_4 -> V_299 != V_293 -> V_4 )
V_11 = - V_115 ;
if ( V_293 -> V_300 != 0 )
V_11 = - V_115 ;
return V_11 ;
}
static int F_175 ( struct V_2 * V_4 )
{
while ( ! ( F_8 ( V_4 ) & V_65 ) )
F_176 () ;
return F_40 ( V_4 ) ;
}
static void F_177 ( struct V_2 * V_4 , unsigned char V_79 )
{
while ( ! ( F_8 ( V_4 ) & V_39 ) )
F_176 () ;
F_44 ( V_4 , V_79 ) ;
}
static int F_178 ( struct V_1 * V_5 ,
struct V_204 * V_205 )
{
int V_11 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_209 * V_210 = F_133 ( & V_205 -> V_33 ) ;
F_132 ( V_5 , V_205 ) ;
F_137 ( V_4 ) ;
F_135 ( V_4 , V_205 ) ;
V_4 -> V_301 = V_302 ;
V_4 -> V_31 = V_303 ;
V_4 -> V_304 = & V_305 ;
V_4 -> V_306 = 1 ;
V_4 -> V_33 = & V_205 -> V_33 ;
V_4 -> V_139 = V_205 -> V_285 [ 0 ] . V_287 ;
V_4 -> V_171 = V_205 -> V_285 [ 1 ] . V_287 ;
V_4 -> V_307 = F_12 ;
F_179 ( & V_5 -> V_99 , F_128 ,
( unsigned long ) V_4 ) ;
F_154 ( & V_5 -> V_99 ) ;
memset ( & V_5 -> V_82 , 0 , sizeof( V_5 -> V_82 ) ) ;
if ( V_210 && V_210 -> V_308 ) {
V_4 -> V_289 = V_210 -> V_308 ;
} else {
V_4 -> V_31 |= V_288 ;
V_4 -> V_289 = NULL ;
}
if ( ! V_5 -> V_235 ) {
V_5 -> V_235 = F_180 ( & V_205 -> V_33 , L_31 ) ;
if ( F_181 ( V_5 -> V_235 ) ) {
V_11 = F_182 ( V_5 -> V_235 ) ;
V_5 -> V_235 = NULL ;
return V_11 ;
}
V_11 = F_157 ( V_5 -> V_235 ) ;
if ( V_11 ) {
F_183 ( V_5 -> V_235 ) ;
V_5 -> V_235 = NULL ;
return V_11 ;
}
V_4 -> V_248 = F_184 ( V_5 -> V_235 ) ;
F_158 ( V_5 -> V_235 ) ;
}
if ( V_4 -> V_30 . V_31 & V_32 )
V_5 -> V_28 = V_34 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_306 = V_196 ;
V_5 -> V_28 = V_37 | V_38 ;
} else {
V_5 -> V_28 = V_39 ;
}
return 0 ;
}
static void F_185 ( struct V_2 * V_4 , int V_79 )
{
while ( ! ( F_8 ( V_4 ) & V_39 ) )
F_176 () ;
F_44 ( V_4 , V_79 ) ;
}
static void F_186 ( struct V_309 * V_310 , const char * V_311 , T_1 V_152 )
{
struct V_2 * V_4 = & V_312 [ V_310 -> V_313 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_241 ;
unsigned int V_183 ;
V_241 = F_99 ( V_4 ) ;
F_13 ( V_4 , V_65 | V_5 -> V_28 ) ;
V_183 = F_28 ( V_4 ) & V_58 ;
F_25 ( V_4 , V_56 ) ;
F_187 ( V_4 , V_311 , V_152 , F_185 ) ;
do {
V_10 = F_8 ( V_4 ) ;
} while ( ! ( V_10 & V_39 ) );
if ( V_183 )
F_25 ( V_4 , V_58 ) ;
F_18 ( V_4 , V_241 ) ;
}
static void T_7 F_188 ( struct V_2 * V_4 , int * V_243 ,
int * V_94 , int * V_314 )
{
unsigned int V_315 , V_242 ;
V_242 = F_189 ( V_4 ) & V_316 ;
if ( ! V_242 )
return;
V_315 = F_14 ( V_4 ) & V_245 ;
if ( V_315 == V_258 )
* V_314 = 8 ;
else
* V_314 = 7 ;
V_315 = F_14 ( V_4 ) & V_247 ;
if ( V_315 == V_267 )
* V_94 = 'e' ;
else if ( V_315 == V_266 )
* V_94 = 'o' ;
* V_243 = V_4 -> V_248 / ( 16 * ( V_242 - 1 ) ) ;
}
static int T_7 F_190 ( struct V_309 * V_310 , char * V_317 )
{
int V_11 ;
struct V_2 * V_4 = & V_312 [ V_310 -> V_313 ] . V_3 ;
int V_243 = 115200 ;
int V_314 = 8 ;
int V_94 = 'n' ;
int V_318 = 'n' ;
if ( V_4 -> V_289 == NULL ) {
return - V_319 ;
}
V_11 = F_157 ( V_312 [ V_310 -> V_313 ] . V_235 ) ;
if ( V_11 )
return V_11 ;
F_13 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_59 | V_231 ) ;
F_21 ( V_4 , V_232 | V_60 ) ;
if ( V_317 )
F_191 ( V_317 , & V_243 , & V_94 , & V_314 , & V_318 ) ;
else
F_188 ( V_4 , & V_243 , & V_94 , & V_314 ) ;
return F_192 ( V_4 , V_310 , V_243 , V_94 , V_314 , V_318 ) ;
}
static int T_7 F_193 ( void )
{
int V_11 ;
if ( V_320 ) {
struct V_209 * V_210 =
F_133 ( & V_320 -> V_33 ) ;
int V_321 = V_210 -> V_322 ;
struct V_1 * V_4 = & V_312 [ V_321 ] ;
V_4 -> V_236 = 0 ;
V_4 -> V_3 . line = V_321 ;
F_194 ( V_323 , V_321 , NULL ) ;
V_11 = F_178 ( V_4 , V_320 ) ;
if ( V_11 )
return V_11 ;
F_195 ( & V_324 ) ;
}
return 0 ;
}
static int T_7 F_196 ( void )
{
if ( V_320
&& ! ( V_324 . V_31 & V_325 ) )
F_195 ( & V_324 ) ;
return 0 ;
}
static inline bool F_197 ( struct V_2 * V_4 )
{
return V_4 -> V_326 && V_4 -> V_326 -> V_313 == V_4 -> line ;
}
static inline bool F_197 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_198 ( void )
{
#ifdef F_199
return F_200 () ;
#else
return false ;
#endif
}
static int F_201 ( struct V_204 * V_205 ,
T_8 V_101 )
{
struct V_2 * V_4 = F_202 ( V_205 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_197 ( V_4 ) && V_327 ) {
while ( ! ( F_8 ( V_4 ) & V_34 ) )
F_176 () ;
}
V_5 -> V_328 = F_203 ( & V_205 -> V_33 ) ;
if ( F_198 () ) {
unsigned long V_31 ;
F_50 ( & V_5 -> V_175 , V_31 ) ;
V_5 -> V_176 = true ;
F_56 ( & V_5 -> V_175 , V_31 ) ;
F_204 ( & V_205 -> V_33 , 0 ) ;
}
F_205 ( & V_329 , V_4 ) ;
return 0 ;
}
static int F_206 ( struct V_204 * V_205 )
{
struct V_2 * V_4 = F_202 ( V_205 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned long V_31 ;
F_50 ( & V_5 -> V_175 , V_31 ) ;
if ( V_5 -> V_167 ) {
F_95 ( V_4 , V_5 -> V_167 ) ;
F_97 ( V_4 , V_5 -> V_167 ,
V_5 -> V_177 ) ;
F_96 ( V_4 , V_5 -> V_167 ) ;
V_5 -> V_167 = 0 ;
}
V_5 -> V_176 = false ;
F_56 ( & V_5 -> V_175 , V_31 ) ;
F_207 ( & V_329 , V_4 ) ;
F_204 ( & V_205 -> V_33 , V_5 -> V_328 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_330 , struct V_331 * V_33 )
{
enum V_221 V_192 ;
struct V_332 * V_333 ;
V_330 -> V_12 = F_209 ( V_33 , 0 ) ;
if ( F_181 ( V_330 -> V_12 ) )
return F_182 ( V_330 -> V_12 ) ;
for ( V_192 = 0 ; V_192 < V_222 ; V_192 ++ ) {
V_333 = F_11 ( V_330 -> V_12 , V_192 ) ;
if ( V_333 && ( F_210 ( V_333 ) == V_334 ) )
V_330 -> V_70 [ V_192 ] = F_211 ( V_333 ) ;
else
V_330 -> V_70 [ V_192 ] = - V_115 ;
}
return 0 ;
}
static int F_212 ( struct V_204 * V_205 )
{
struct V_1 * V_4 ;
struct V_206 * V_207 = V_205 -> V_33 . V_208 ;
struct V_209 * V_210 = F_133 ( & V_205 -> V_33 ) ;
void * V_164 ;
int V_11 = - V_319 ;
bool V_335 ;
F_213 ( V_87 & ( V_87 - 1 ) ) ;
if ( V_207 )
V_11 = F_214 ( V_207 , L_32 ) ;
else
if ( V_210 )
V_11 = V_210 -> V_322 ;
if ( V_11 < 0 )
V_11 = F_215 ( V_336 , V_337 ) ;
if ( V_11 >= V_337 ) {
V_11 = - V_319 ;
goto V_223;
}
if ( F_216 ( V_11 , V_336 ) ) {
V_11 = - V_290 ;
goto V_223;
}
V_4 = & V_312 [ V_11 ] ;
V_4 -> V_236 = 0 ;
V_4 -> V_3 . line = V_11 ;
F_74 ( & V_4 -> V_175 ) ;
V_11 = F_208 ( V_4 , & V_205 -> V_33 ) ;
if ( V_11 < 0 ) {
F_65 ( & V_205 -> V_33 , L_33 ) ;
goto V_223;
}
V_11 = F_178 ( V_4 , V_205 ) ;
if ( V_11 )
goto V_338;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_11 = - V_198 ;
V_164 = F_125 ( sizeof( struct V_83 )
* V_87 , V_197 ) ;
if ( ! V_164 )
goto V_339;
V_4 -> V_82 . V_88 = V_164 ;
}
V_335 = V_4 -> V_3 . V_30 . V_31 & V_32 ;
V_11 = F_217 ( & V_329 , & V_4 -> V_3 ) ;
if ( V_11 )
goto V_340;
#ifdef F_218
if ( F_197 ( & V_4 -> V_3 )
&& V_341 -> V_31 & V_325 ) {
F_158 ( V_4 -> V_235 ) ;
}
#endif
F_219 ( & V_205 -> V_33 , 1 ) ;
F_220 ( V_205 , V_4 ) ;
F_157 ( V_4 -> V_235 ) ;
if ( V_335 ) {
F_17 ( & V_4 -> V_3 , V_278 ) ;
F_21 ( & V_4 -> V_3 , V_46 ) ;
}
F_138 ( & V_4 -> V_3 ) ;
F_158 ( V_4 -> V_235 ) ;
return 0 ;
V_340:
F_116 ( V_4 -> V_82 . V_88 ) ;
V_4 -> V_82 . V_88 = NULL ;
V_339:
if ( ! F_197 ( & V_4 -> V_3 ) ) {
F_183 ( V_4 -> V_235 ) ;
V_4 -> V_235 = NULL ;
}
V_338:
F_221 ( V_4 -> V_3 . line , V_336 ) ;
V_223:
return V_11 ;
}
static int F_222 ( struct V_204 * V_205 )
{
struct V_2 * V_4 = F_202 ( V_205 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_11 = 0 ;
F_155 ( & V_5 -> V_99 ) ;
F_219 ( & V_205 -> V_33 , 0 ) ;
V_11 = F_223 ( & V_329 , V_4 ) ;
F_116 ( V_5 -> V_82 . V_88 ) ;
F_221 ( V_4 -> line , V_336 ) ;
F_183 ( V_5 -> V_235 ) ;
return V_11 ;
}
static int T_7 F_224 ( void )
{
int V_11 ;
V_11 = F_225 ( & V_329 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_226 ( & V_342 ) ;
if ( V_11 )
F_227 ( & V_329 ) ;
return V_11 ;
}
static void T_9 F_228 ( void )
{
F_229 ( & V_342 ) ;
F_227 ( & V_329 ) ;
}
