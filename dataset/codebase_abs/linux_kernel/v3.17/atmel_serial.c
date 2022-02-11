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
void F_12 ( struct V_2 * V_4 , struct V_25 * V_26 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_27 ;
unsigned long V_28 ;
F_13 ( & V_4 -> V_29 , V_28 ) ;
F_14 ( V_4 , V_5 -> V_30 ) ;
V_27 = F_15 ( V_4 ) ;
V_27 &= ~ V_31 ;
V_5 -> V_32 = * V_26 ;
if ( V_26 -> V_28 & V_33 ) {
F_16 ( V_4 -> V_34 , L_1 ) ;
V_5 -> V_30 = V_35 ;
if ( ( V_26 -> V_36 ) > 0 )
F_17 ( V_4 , V_26 -> V_36 ) ;
V_27 |= V_37 ;
} else {
F_16 ( V_4 -> V_34 , L_2 ) ;
if ( F_4 ( V_4 ) )
V_5 -> V_30 = V_38 |
V_39 ;
else
V_5 -> V_30 = V_40 ;
}
F_18 ( V_4 , V_27 ) ;
F_19 ( V_4 , V_5 -> V_30 ) ;
F_20 ( & V_4 -> V_29 , V_28 ) ;
}
static T_1 F_21 ( struct V_2 * V_4 )
{
return ( F_8 ( V_4 ) & V_35 ) ? V_41 : 0 ;
}
static void F_22 ( struct V_2 * V_4 , T_1 V_42 )
{
unsigned int V_43 = 0 ;
unsigned int V_27 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_42 & V_44 )
V_43 |= V_45 ;
else
V_43 |= V_46 ;
if ( V_42 & V_47 )
V_43 |= V_48 ;
else
V_43 |= V_49 ;
F_23 ( V_4 , V_43 ) ;
F_24 ( V_5 -> V_12 , V_42 ) ;
V_27 = F_15 ( V_4 ) & ~ V_50 ;
if ( V_42 & V_51 )
V_27 |= V_52 ;
else
V_27 |= V_53 ;
V_27 &= ~ V_31 ;
if ( V_5 -> V_32 . V_28 & V_33 ) {
F_16 ( V_4 -> V_34 , L_1 ) ;
if ( ( V_5 -> V_32 . V_36 ) > 0 )
F_17 ( V_4 ,
V_5 -> V_32 . V_36 ) ;
V_27 |= V_37 ;
} else {
F_16 ( V_4 -> V_34 , L_2 ) ;
}
F_18 ( V_4 , V_27 ) ;
}
static T_1 F_25 ( struct V_2 * V_4 )
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
static void F_26 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_27 ( V_4 , V_54 ) ;
}
F_14 ( V_4 , V_5 -> V_30 ) ;
if ( ( V_5 -> V_32 . V_28 & V_33 ) &&
! ( V_5 -> V_32 . V_28 & V_55 ) )
F_28 ( V_4 ) ;
}
static void F_29 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
if ( F_30 ( V_4 ) & V_56 )
return;
if ( ( V_5 -> V_32 . V_28 & V_33 ) &&
! ( V_5 -> V_32 . V_28 & V_55 ) )
F_31 ( V_4 ) ;
F_27 ( V_4 , V_56 ) ;
}
F_19 ( V_4 , V_5 -> V_30 ) ;
}
static void F_28 ( struct V_2 * V_4 )
{
F_23 ( V_4 , V_57 ) ;
F_23 ( V_4 , V_58 ) ;
if ( F_3 ( V_4 ) ) {
F_19 ( V_4 , V_59 | V_60 |
V_4 -> V_61 ) ;
F_27 ( V_4 , V_62 ) ;
} else {
F_19 ( V_4 , V_63 ) ;
}
}
static void F_31 ( struct V_2 * V_4 )
{
F_23 ( V_4 , V_64 ) ;
if ( F_3 ( V_4 ) ) {
F_27 ( V_4 , V_65 ) ;
F_14 ( V_4 , V_59 | V_60 |
V_4 -> V_61 ) ;
} else {
F_14 ( V_4 , V_63 ) ;
}
}
static void F_32 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_66 = 0 ;
if ( V_5 -> V_67 )
return;
V_5 -> V_67 = true ;
if ( V_5 -> V_68 [ V_13 ] >= 0 )
F_33 ( V_5 -> V_68 [ V_13 ] ) ;
else
V_66 |= V_69 ;
if ( V_5 -> V_68 [ V_16 ] >= 0 )
F_33 ( V_5 -> V_68 [ V_16 ] ) ;
else
V_66 |= V_70 ;
if ( V_5 -> V_68 [ V_19 ] >= 0 )
F_33 ( V_5 -> V_68 [ V_19 ] ) ;
else
V_66 |= V_71 ;
if ( V_5 -> V_68 [ V_22 ] >= 0 )
F_33 ( V_5 -> V_68 [ V_22 ] ) ;
else
V_66 |= V_72 ;
F_19 ( V_4 , V_66 ) ;
}
static void F_34 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_73 = 0 ;
if ( ! V_5 -> V_67 )
return;
V_5 -> V_67 = false ;
if ( V_5 -> V_68 [ V_13 ] >= 0 )
F_35 ( V_5 -> V_68 [ V_13 ] ) ;
else
V_73 |= V_69 ;
if ( V_5 -> V_68 [ V_16 ] >= 0 )
F_35 ( V_5 -> V_68 [ V_16 ] ) ;
else
V_73 |= V_70 ;
if ( V_5 -> V_68 [ V_19 ] >= 0 )
F_35 ( V_5 -> V_68 [ V_19 ] ) ;
else
V_73 |= V_71 ;
if ( V_5 -> V_68 [ V_22 ] >= 0 )
F_35 ( V_5 -> V_68 [ V_22 ] ) ;
else
V_73 |= V_72 ;
F_14 ( V_4 , V_73 ) ;
}
static void F_36 ( struct V_2 * V_4 , int V_74 )
{
if ( V_74 != 0 )
F_23 ( V_4 , V_75 ) ;
else
F_23 ( V_4 , V_76 ) ;
}
static void
F_37 ( struct V_2 * V_4 , unsigned int V_10 ,
unsigned int V_77 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_78 * V_79 = & V_5 -> V_80 ;
struct V_81 * V_82 ;
if ( ! F_38 ( V_79 -> V_83 , V_79 -> V_84 , V_85 ) )
return;
V_82 = & ( (struct V_81 * ) V_79 -> V_86 ) [ V_79 -> V_83 ] ;
V_82 -> V_10 = V_10 ;
V_82 -> V_77 = V_77 ;
F_39 () ;
V_79 -> V_83 = ( V_79 -> V_83 + 1 ) & ( V_85 - 1 ) ;
}
static void F_40 ( struct V_2 * V_4 , unsigned int V_10 )
{
F_23 ( V_4 , V_57 ) ;
if ( V_10 & V_87 ) {
V_10 &= ~ ( V_88 | V_89 ) ;
V_4 -> V_90 . V_91 ++ ;
}
if ( V_10 & V_88 )
V_4 -> V_90 . V_92 ++ ;
if ( V_10 & V_89 )
V_4 -> V_90 . V_93 ++ ;
if ( V_10 & V_94 )
V_4 -> V_90 . V_95 ++ ;
}
static void F_41 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_77 ;
V_10 = F_8 ( V_4 ) ;
while ( V_10 & V_63 ) {
V_77 = F_42 ( V_4 ) ;
if ( F_43 ( V_10 & ( V_88 | V_89
| V_94 | V_87 )
|| V_5 -> V_96 ) ) {
F_23 ( V_4 , V_57 ) ;
if ( V_10 & V_87
&& ! V_5 -> V_96 ) {
V_5 -> V_96 = 1 ;
F_19 ( V_4 , V_87 ) ;
} else {
F_14 ( V_4 , V_87 ) ;
V_10 &= ~ V_87 ;
V_5 -> V_96 = 0 ;
}
}
F_37 ( V_4 , V_10 , V_77 ) ;
V_10 = F_8 ( V_4 ) ;
}
F_44 ( & V_5 -> V_97 ) ;
}
static void F_45 ( struct V_2 * V_4 )
{
struct V_78 * V_98 = & V_4 -> V_99 -> V_98 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_100 && F_8 ( V_4 ) & V_5 -> V_30 ) {
F_46 ( V_4 , V_4 -> V_100 ) ;
V_4 -> V_90 . V_101 ++ ;
V_4 -> V_100 = 0 ;
}
if ( F_47 ( V_98 ) || F_48 ( V_4 ) )
return;
while ( F_8 ( V_4 ) & V_5 -> V_30 ) {
F_46 ( V_4 , V_98 -> V_86 [ V_98 -> V_84 ] ) ;
V_98 -> V_84 = ( V_98 -> V_84 + 1 ) & ( V_102 - 1 ) ;
V_4 -> V_90 . V_101 ++ ;
if ( F_47 ( V_98 ) )
break;
}
if ( F_49 ( V_98 ) < V_103 )
F_50 ( V_4 ) ;
if ( ! F_47 ( V_98 ) )
F_19 ( V_4 , V_5 -> V_30 ) ;
}
static void F_51 ( void * V_104 )
{
struct V_1 * V_5 = V_104 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_78 * V_98 = & V_4 -> V_99 -> V_98 ;
struct V_105 * V_106 = V_5 -> V_107 ;
unsigned long V_28 ;
F_13 ( & V_4 -> V_29 , V_28 ) ;
if ( V_106 )
F_52 ( V_106 ) ;
V_98 -> V_84 += F_53 ( & V_5 -> V_108 ) ;
V_98 -> V_84 &= V_102 - 1 ;
V_4 -> V_90 . V_101 += F_53 ( & V_5 -> V_108 ) ;
F_54 ( & V_5 -> V_109 ) ;
F_55 ( V_5 -> V_110 ) ;
V_5 -> V_111 = - V_112 ;
V_5 -> V_110 = NULL ;
F_56 ( & V_5 -> V_109 ) ;
if ( F_49 ( V_98 ) < V_103 )
F_50 ( V_4 ) ;
if ( ! F_47 ( V_98 ) )
F_44 ( & V_5 -> V_97 ) ;
F_20 ( & V_4 -> V_29 , V_28 ) ;
}
static void F_57 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_105 * V_106 = V_5 -> V_107 ;
if ( V_106 ) {
F_52 ( V_106 ) ;
F_58 ( V_106 ) ;
F_59 ( V_4 -> V_34 , & V_5 -> V_108 , 1 ,
V_113 ) ;
}
V_5 -> V_110 = NULL ;
V_5 -> V_107 = NULL ;
V_5 -> V_111 = - V_112 ;
}
static void F_60 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_78 * V_98 = & V_4 -> V_99 -> V_98 ;
struct V_105 * V_106 = V_5 -> V_107 ;
struct V_114 * V_115 ;
struct V_116 * V_117 = & V_5 -> V_108 ;
if ( V_5 -> V_110 != NULL )
return;
if ( ! F_47 ( V_98 ) && ! F_48 ( V_4 ) ) {
V_117 -> V_118 = V_98 -> V_84 & ( V_102 - 1 ) ;
F_61 ( V_117 ) = ( F_61 ( V_117 ) &
~ ( V_102 - 1 ) )
+ V_117 -> V_118 ;
F_53 ( V_117 ) = F_62 ( V_98 -> V_83 ,
V_98 -> V_84 ,
V_102 ) ;
F_63 ( ! F_53 ( V_117 ) ) ;
V_115 = F_64 ( V_106 ,
V_117 ,
1 ,
V_119 ,
V_120 |
V_121 ) ;
if ( ! V_115 ) {
F_65 ( V_4 -> V_34 , L_3 ) ;
return;
}
F_66 ( V_4 -> V_34 , V_117 , 1 , V_119 ) ;
V_5 -> V_110 = V_115 ;
V_115 -> V_122 = F_51 ;
V_115 -> V_123 = V_5 ;
V_5 -> V_111 = F_67 ( V_115 ) ;
} else {
if ( V_5 -> V_32 . V_28 & V_33 ) {
F_28 ( V_4 ) ;
}
}
if ( F_49 ( V_98 ) < V_103 )
F_50 ( V_4 ) ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_3 V_124 ;
struct V_125 V_126 ;
int V_11 , V_127 ;
F_69 ( V_124 ) ;
F_70 ( V_128 , V_124 ) ;
V_5 -> V_107 = F_71 ( V_4 -> V_34 , L_4 ) ;
if ( V_5 -> V_107 == NULL )
goto V_129;
F_72 ( V_4 -> V_34 , L_5 ,
F_73 ( V_5 -> V_107 ) ) ;
F_74 ( & V_5 -> V_109 ) ;
F_75 ( & V_5 -> V_108 , 1 ) ;
F_63 ( ( int ) V_4 -> V_99 -> V_98 . V_86 & ~ V_130 ) ;
F_76 ( & V_5 -> V_108 ,
F_77 ( V_4 -> V_99 -> V_98 . V_86 ) ,
V_102 ,
( int ) V_4 -> V_99 -> V_98 . V_86 & ~ V_130 ) ;
V_127 = F_78 ( V_4 -> V_34 ,
& V_5 -> V_108 ,
1 ,
V_113 ) ;
if ( ! V_127 ) {
F_16 ( V_4 -> V_34 , L_6 ) ;
goto V_129;
} else {
F_16 ( V_4 -> V_34 , L_7 , V_131 ,
F_53 ( & V_5 -> V_108 ) ,
V_4 -> V_99 -> V_98 . V_86 ,
F_61 ( & V_5 -> V_108 ) ) ;
}
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_132 = V_119 ;
V_126 . V_133 = V_134 ;
V_126 . V_135 = V_4 -> V_136 + V_137 ;
V_11 = F_79 ( V_5 -> V_107 ,
V_138 ,
( unsigned long ) & V_126 ) ;
if ( V_11 ) {
F_65 ( V_4 -> V_34 , L_8 ) ;
goto V_129;
}
return 0 ;
V_129:
F_65 ( V_4 -> V_34 , L_9 ) ;
V_5 -> V_8 = 0 ;
if ( V_5 -> V_107 )
F_57 ( V_4 ) ;
return - V_112 ;
}
static void F_80 ( struct V_2 * V_4 ,
char * V_86 , T_4 V_139 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_140 * V_141 = & V_4 -> V_99 -> V_4 ;
F_81 ( V_4 -> V_34 ,
& V_5 -> V_142 ,
1 ,
V_143 ) ;
F_82 ( V_141 , V_86 , V_139 ) ;
F_66 ( V_4 -> V_34 ,
& V_5 -> V_142 ,
1 ,
V_143 ) ;
F_83 ( & V_4 -> V_29 ) ;
F_84 ( V_141 ) ;
F_85 ( & V_4 -> V_29 ) ;
}
static void F_86 ( void * V_104 )
{
struct V_2 * V_4 = V_104 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_44 ( & V_5 -> V_97 ) ;
}
static void F_87 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_105 * V_106 = V_5 -> V_144 ;
if ( V_106 ) {
F_52 ( V_106 ) ;
F_58 ( V_106 ) ;
F_59 ( V_4 -> V_34 , & V_5 -> V_142 , 1 ,
V_145 ) ;
}
V_5 -> V_146 = NULL ;
V_5 -> V_144 = NULL ;
V_5 -> V_147 = - V_112 ;
}
static void F_88 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_78 * V_79 = & V_5 -> V_80 ;
struct V_105 * V_106 = V_5 -> V_144 ;
struct V_148 V_99 ;
enum V_149 V_150 ;
T_4 V_151 , V_139 ;
F_23 ( V_4 , V_152 ) ;
V_150 = F_89 ( V_106 ,
V_5 -> V_147 ,
& V_99 ) ;
if ( V_150 == V_153 ) {
F_16 ( V_4 -> V_34 , L_10 ) ;
F_19 ( V_4 , V_60 ) ;
F_44 ( & V_5 -> V_97 ) ;
return;
}
V_151 = F_53 ( & V_5 -> V_142 ) - V_99 . V_154 ;
F_63 ( V_151 > F_53 ( & V_5 -> V_142 ) ) ;
if ( V_151 > V_79 -> V_83 ) {
V_139 = V_151 - V_79 -> V_83 ;
F_80 ( V_4 , V_79 -> V_86 + V_79 -> V_83 , V_139 ) ;
V_79 -> V_83 += V_139 ;
if ( V_79 -> V_83 == F_53 ( & V_5 -> V_142 ) )
V_79 -> V_83 = 0 ;
V_4 -> V_90 . V_155 += V_139 ;
}
F_19 ( V_4 , V_60 ) ;
}
static int F_90 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_114 * V_115 ;
T_3 V_124 ;
struct V_125 V_126 ;
struct V_78 * V_79 ;
int V_11 , V_127 ;
V_79 = & V_5 -> V_80 ;
F_69 ( V_124 ) ;
F_70 ( V_156 , V_124 ) ;
V_5 -> V_144 = F_71 ( V_4 -> V_34 , L_11 ) ;
if ( V_5 -> V_144 == NULL )
goto V_129;
F_72 ( V_4 -> V_34 , L_12 ,
F_73 ( V_5 -> V_144 ) ) ;
F_74 ( & V_5 -> V_157 ) ;
F_75 ( & V_5 -> V_142 , 1 ) ;
F_63 ( ( int ) V_4 -> V_99 -> V_98 . V_86 & ~ V_130 ) ;
F_76 ( & V_5 -> V_142 ,
F_77 ( V_79 -> V_86 ) ,
V_85 ,
( int ) V_79 -> V_86 & ~ V_130 ) ;
V_127 = F_78 ( V_4 -> V_34 ,
& V_5 -> V_142 ,
1 ,
V_145 ) ;
if ( ! V_127 ) {
F_16 ( V_4 -> V_34 , L_6 ) ;
goto V_129;
} else {
F_16 ( V_4 -> V_34 , L_7 , V_131 ,
F_53 ( & V_5 -> V_142 ) ,
V_79 -> V_86 ,
F_61 ( & V_5 -> V_142 ) ) ;
}
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_132 = V_143 ;
V_126 . V_158 = V_134 ;
V_126 . V_159 = V_4 -> V_136 + V_160 ;
V_11 = F_79 ( V_5 -> V_144 ,
V_138 ,
( unsigned long ) & V_126 ) ;
if ( V_11 ) {
F_65 ( V_4 -> V_34 , L_13 ) ;
goto V_129;
}
V_115 = F_91 ( V_5 -> V_144 ,
F_61 ( & V_5 -> V_142 ) ,
F_53 ( & V_5 -> V_142 ) ,
F_53 ( & V_5 -> V_142 ) / 2 ,
V_143 ,
V_120 ) ;
V_115 -> V_122 = F_86 ;
V_115 -> V_123 = V_4 ;
V_5 -> V_146 = V_115 ;
V_5 -> V_147 = F_67 ( V_115 ) ;
return 0 ;
V_129:
F_65 ( V_4 -> V_34 , L_14 ) ;
V_5 -> V_9 = 0 ;
if ( V_5 -> V_144 )
F_87 ( V_4 ) ;
return - V_112 ;
}
static void F_92 ( unsigned long V_161 )
{
struct V_2 * V_4 = ( void * ) V_161 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_44 ( & V_5 -> V_97 ) ;
F_93 ( & V_5 -> V_162 , V_163 + F_94 ( V_4 ) ) ;
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_151 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_151 & ( V_59 | V_60 ) ) {
F_14 ( V_4 , ( V_59
| V_60 ) ) ;
F_44 ( & V_5 -> V_97 ) ;
}
if ( V_151 & ( V_87 | V_94 |
V_89 | V_88 ) )
F_40 ( V_4 , V_151 ) ;
}
if ( F_6 ( V_4 ) ) {
if ( V_151 & V_60 ) {
F_14 ( V_4 , V_60 ) ;
F_44 ( & V_5 -> V_97 ) ;
}
}
if ( V_151 & V_63 )
F_41 ( V_4 ) ;
else if ( V_151 & V_87 ) {
F_23 ( V_4 , V_57 ) ;
F_14 ( V_4 , V_87 ) ;
V_5 -> V_96 = 0 ;
}
}
static void
F_96 ( struct V_2 * V_4 , unsigned int V_151 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_151 & V_5 -> V_30 ) {
F_14 ( V_4 , V_5 -> V_30 ) ;
F_44 ( & V_5 -> V_97 ) ;
}
}
static void
F_97 ( struct V_2 * V_4 , unsigned int V_151 ,
unsigned int V_10 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_151 & ( V_71 | V_70 | V_72
| V_69 ) ) {
V_5 -> V_164 = V_10 ;
F_44 ( & V_5 -> V_97 ) ;
}
}
static T_5 F_98 ( int V_165 , void * V_166 )
{
struct V_2 * V_4 = V_166 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_151 , V_167 = 0 ;
bool V_168 = false ;
do {
V_10 = F_7 ( V_4 ) ;
V_151 = V_10 & F_99 ( V_4 ) ;
if ( ! V_168 ) {
if ( V_165 == V_5 -> V_68 [ V_13 ] )
V_151 |= V_69 ;
if ( V_165 == V_5 -> V_68 [ V_16 ] )
V_151 |= V_70 ;
if ( V_165 == V_5 -> V_68 [ V_19 ] )
V_151 |= V_71 ;
if ( V_165 == V_5 -> V_68 [ V_22 ] )
V_151 |= V_72 ;
V_168 = true ;
}
if ( ! V_151 )
break;
F_95 ( V_4 , V_151 ) ;
F_97 ( V_4 , V_151 , V_10 ) ;
F_96 ( V_4 , V_151 ) ;
} while ( V_167 ++ < V_169 );
return V_167 ? V_170 : V_171 ;
}
static void F_100 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_172 * V_173 = & V_5 -> V_174 ;
F_101 ( V_4 -> V_34 ,
V_173 -> V_175 ,
V_173 -> V_176 ,
V_113 ) ;
}
static void F_102 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_78 * V_98 = & V_4 -> V_99 -> V_98 ;
struct V_172 * V_173 = & V_5 -> V_174 ;
int V_139 ;
if ( F_103 ( V_4 ) )
return;
V_98 -> V_84 += V_173 -> V_177 ;
V_98 -> V_84 &= V_102 - 1 ;
V_4 -> V_90 . V_101 += V_173 -> V_177 ;
V_173 -> V_177 = 0 ;
F_27 ( V_4 , V_54 ) ;
if ( ! F_47 ( V_98 ) && ! F_48 ( V_4 ) ) {
F_104 ( V_4 -> V_34 ,
V_173 -> V_175 ,
V_173 -> V_176 ,
V_113 ) ;
V_139 = F_62 ( V_98 -> V_83 , V_98 -> V_84 , V_102 ) ;
V_173 -> V_177 = V_139 ;
F_105 ( V_4 , V_173 -> V_175 + V_98 -> V_84 ) ;
F_106 ( V_4 , V_139 ) ;
F_27 ( V_4 , V_56 ) ;
F_19 ( V_4 , V_5 -> V_30 ) ;
} else {
if ( ( V_5 -> V_32 . V_28 & V_33 ) &&
! ( V_5 -> V_32 . V_28 & V_55 ) ) {
F_28 ( V_4 ) ;
}
}
if ( F_49 ( V_98 ) < V_103 )
F_50 ( V_4 ) ;
}
static int F_107 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_172 * V_173 = & V_5 -> V_174 ;
struct V_78 * V_98 = & V_4 -> V_99 -> V_98 ;
V_173 -> V_86 = V_98 -> V_86 ;
V_173 -> V_175 = F_108 ( V_4 -> V_34 ,
V_173 -> V_86 ,
V_102 ,
V_113 ) ;
V_173 -> V_176 = V_102 ;
V_173 -> V_177 = 0 ;
return 0 ;
}
static void F_109 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_78 * V_79 = & V_5 -> V_80 ;
unsigned int V_178 ;
unsigned int V_10 ;
while ( V_79 -> V_83 != V_79 -> V_84 ) {
struct V_81 V_82 ;
F_110 () ;
V_82 = ( (struct V_81 * ) V_79 -> V_86 ) [ V_79 -> V_84 ] ;
V_79 -> V_84 = ( V_79 -> V_84 + 1 ) & ( V_85 - 1 ) ;
V_4 -> V_90 . V_155 ++ ;
V_10 = V_82 . V_10 ;
V_178 = V_179 ;
if ( F_43 ( V_10 & ( V_88 | V_89
| V_94 | V_87 ) ) ) {
if ( V_10 & V_87 ) {
V_10 &= ~ ( V_88 | V_89 ) ;
V_4 -> V_90 . V_91 ++ ;
if ( F_111 ( V_4 ) )
continue;
}
if ( V_10 & V_88 )
V_4 -> V_90 . V_92 ++ ;
if ( V_10 & V_89 )
V_4 -> V_90 . V_93 ++ ;
if ( V_10 & V_94 )
V_4 -> V_90 . V_95 ++ ;
V_10 &= V_4 -> V_61 ;
if ( V_10 & V_87 )
V_178 = V_180 ;
else if ( V_10 & V_88 )
V_178 = V_181 ;
else if ( V_10 & V_89 )
V_178 = V_182 ;
}
if ( F_112 ( V_4 , V_82 . V_77 ) )
continue;
F_113 ( V_4 , V_10 , V_94 , V_82 . V_77 , V_178 ) ;
}
F_83 ( & V_4 -> V_29 ) ;
F_84 ( & V_4 -> V_99 -> V_4 ) ;
F_85 ( & V_4 -> V_29 ) ;
}
static void F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_183 ;
for ( V_183 = 0 ; V_183 < 2 ; V_183 ++ ) {
struct V_172 * V_173 = & V_5 -> V_184 [ V_183 ] ;
F_101 ( V_4 -> V_34 ,
V_173 -> V_175 ,
V_173 -> V_176 ,
V_145 ) ;
F_115 ( V_173 -> V_86 ) ;
}
}
static void F_116 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_140 * V_141 = & V_4 -> V_99 -> V_4 ;
struct V_172 * V_173 ;
int V_185 = V_5 -> V_186 ;
unsigned int V_83 ;
unsigned int V_84 ;
unsigned int V_139 ;
do {
F_23 ( V_4 , V_152 ) ;
V_173 = & V_5 -> V_184 [ V_185 ] ;
V_83 = F_117 ( V_4 ) - V_173 -> V_175 ;
V_84 = V_173 -> V_177 ;
V_83 = F_118 ( V_83 , V_173 -> V_176 ) ;
if ( F_119 ( V_83 != V_84 ) ) {
F_120 ( V_4 -> V_34 , V_173 -> V_175 ,
V_173 -> V_176 , V_145 ) ;
V_139 = V_83 - V_84 ;
F_82 ( V_141 , V_173 -> V_86 + V_173 -> V_177 ,
V_139 ) ;
F_104 ( V_4 -> V_34 , V_173 -> V_175 ,
V_173 -> V_176 , V_145 ) ;
V_4 -> V_90 . V_155 += V_139 ;
V_173 -> V_177 = V_83 ;
}
if ( V_83 >= V_173 -> V_176 ) {
V_173 -> V_177 = 0 ;
F_121 ( V_4 , V_173 -> V_175 ) ;
F_122 ( V_4 , V_173 -> V_176 ) ;
V_185 = ! V_185 ;
V_5 -> V_186 = V_185 ;
}
} while ( V_83 >= V_173 -> V_176 );
F_83 ( & V_4 -> V_29 ) ;
F_84 ( V_141 ) ;
F_85 ( & V_4 -> V_29 ) ;
F_19 ( V_4 , V_59 | V_60 ) ;
}
static int F_123 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_183 ;
for ( V_183 = 0 ; V_183 < 2 ; V_183 ++ ) {
struct V_172 * V_173 = & V_5 -> V_184 [ V_183 ] ;
V_173 -> V_86 = F_124 ( V_187 , V_188 ) ;
if ( V_173 -> V_86 == NULL ) {
if ( V_183 != 0 ) {
F_101 ( V_4 -> V_34 ,
V_5 -> V_184 [ 0 ] . V_175 ,
V_187 ,
V_145 ) ;
F_115 ( V_5 -> V_184 [ 0 ] . V_86 ) ;
}
V_5 -> V_6 = 0 ;
return - V_189 ;
}
V_173 -> V_175 = F_108 ( V_4 -> V_34 ,
V_173 -> V_86 ,
V_187 ,
V_145 ) ;
V_173 -> V_176 = V_187 ;
V_173 -> V_177 = 0 ;
}
V_5 -> V_186 = 0 ;
F_125 ( V_4 , V_5 -> V_184 [ 0 ] . V_175 ) ;
F_126 ( V_4 , V_187 ) ;
F_121 ( V_4 , V_5 -> V_184 [ 1 ] . V_175 ) ;
F_122 ( V_4 , V_187 ) ;
return 0 ;
}
static void F_127 ( unsigned long V_161 )
{
struct V_2 * V_4 = (struct V_2 * ) V_161 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 ;
unsigned int V_190 ;
F_85 ( & V_4 -> V_29 ) ;
V_5 -> V_191 ( V_4 ) ;
V_10 = V_5 -> V_164 ;
V_190 = V_10 ^ V_5 -> V_192 ;
if ( V_190 & ( V_21 | V_18
| V_24 | V_15 ) ) {
if ( V_190 & V_21 )
V_4 -> V_90 . V_193 ++ ;
if ( V_190 & V_18 )
V_4 -> V_90 . V_194 ++ ;
if ( V_190 & V_24 )
F_128 ( V_4 , ! ( V_10 & V_24 ) ) ;
if ( V_190 & V_15 )
F_129 ( V_4 , ! ( V_10 & V_15 ) ) ;
F_130 ( & V_4 -> V_99 -> V_4 . V_195 ) ;
V_5 -> V_192 = V_10 ;
}
V_5 -> V_196 ( V_4 ) ;
F_83 ( & V_4 -> V_29 ) ;
}
static int F_131 ( struct V_1 * V_5 ,
struct V_197 * V_198 )
{
struct V_199 * V_200 = V_198 -> V_34 . V_201 ;
struct V_202 * V_203 = F_132 ( & V_198 -> V_34 ) ;
if ( V_200 ) {
if ( F_133 ( V_200 , L_15 , NULL ) ) {
if ( F_133 ( V_200 , L_16 , NULL ) ) {
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
if ( F_133 ( V_200 , L_17 , NULL ) ) {
if ( F_133 ( V_200 , L_16 , NULL ) ) {
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
V_5 -> V_6 = V_203 -> V_9 ;
V_5 -> V_7 = V_203 -> V_8 ;
V_5 -> V_9 = false ;
V_5 -> V_8 = false ;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_5 ,
struct V_197 * V_198 )
{
struct V_199 * V_200 = V_198 -> V_34 . V_201 ;
struct V_202 * V_203 = F_132 ( & V_198 -> V_34 ) ;
if ( V_200 ) {
T_6 V_204 [ 2 ] ;
if ( F_135 ( V_200 , L_18 ,
V_204 , 2 ) == 0 ) {
struct V_25 * V_26 = & V_5 -> V_32 ;
V_26 -> V_205 = V_204 [ 0 ] ;
V_26 -> V_36 = V_204 [ 1 ] ;
V_26 -> V_28 = 0 ;
if ( F_133 ( V_200 , L_19 , NULL ) )
V_26 -> V_28 |= V_55 ;
if ( F_133 ( V_200 , L_20 ,
NULL ) )
V_26 -> V_28 |= V_33 ;
}
} else {
V_5 -> V_32 = V_203 -> V_32 ;
}
}
static void F_136 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_6 ( V_4 ) ) {
V_5 -> V_206 = & F_90 ;
V_5 -> V_196 = & F_88 ;
V_5 -> V_207 = & F_87 ;
} else if ( F_3 ( V_4 ) ) {
V_5 -> V_206 = & F_123 ;
V_5 -> V_196 = & F_116 ;
V_5 -> V_207 = & F_114 ;
} else {
V_5 -> V_206 = NULL ;
V_5 -> V_196 = & F_109 ;
V_5 -> V_207 = NULL ;
}
if ( F_5 ( V_4 ) ) {
V_5 -> V_208 = & F_68 ;
V_5 -> V_191 = & F_60 ;
V_5 -> V_209 = & F_57 ;
} else if ( F_4 ( V_4 ) ) {
V_5 -> V_208 = & F_107 ;
V_5 -> V_191 = & F_102 ;
V_5 -> V_209 = & F_100 ;
} else {
V_5 -> V_208 = NULL ;
V_5 -> V_191 = & F_45 ;
V_5 -> V_209 = NULL ;
}
}
static void F_137 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_210 = F_138 ( V_4 ) ;
T_6 V_211 ;
int V_212 , V_3 ;
V_212 = 0x55534152 ;
V_3 = 0x44424755 ;
V_5 -> V_213 = false ;
if ( V_210 == V_212 ) {
F_16 ( V_4 -> V_34 , L_21 ) ;
V_5 -> V_213 = true ;
} else if ( V_210 == V_3 ) {
F_16 ( V_4 -> V_34 , L_22 ) ;
V_5 -> V_213 = false ;
} else {
V_211 = F_139 ( V_4 ) ;
switch ( V_211 ) {
case 0x302 :
case 0x10213 :
F_16 ( V_4 -> V_34 , L_23 ) ;
V_5 -> V_213 = true ;
break;
case 0x203 :
case 0x10202 :
F_16 ( V_4 -> V_34 , L_24 ) ;
V_5 -> V_213 = false ;
break;
default:
F_65 ( V_4 -> V_34 , L_25 ) ;
}
}
}
static void F_140 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
enum V_214 V_183 ;
for ( V_183 = 0 ; V_183 < V_215 ; V_183 ++ )
if ( V_5 -> V_68 [ V_183 ] >= 0 )
F_141 ( V_5 -> V_68 [ V_183 ] , V_4 ) ;
}
static int F_142 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int * V_165 = V_5 -> V_68 ;
enum V_214 V_183 ;
int V_216 = 0 ;
for ( V_183 = 0 ; ( V_183 < V_215 ) && ! V_216 ; V_183 ++ ) {
if ( V_165 [ V_183 ] < 0 )
continue;
F_143 ( V_165 [ V_183 ] , V_217 ) ;
V_216 = F_144 ( V_165 [ V_183 ] , F_98 , V_218 ,
L_26 , V_4 ) ;
if ( V_216 )
F_65 ( V_4 -> V_34 , L_27 ,
V_165 [ V_183 ] ) ;
}
while ( V_216 && ( -- V_183 >= 0 ) )
if ( V_165 [ V_183 ] >= 0 )
F_141 ( V_165 [ V_183 ] , V_4 ) ;
return V_216 ;
}
static int F_145 ( struct V_2 * V_4 )
{
struct V_197 * V_198 = F_146 ( V_4 -> V_34 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_219 * V_220 = V_4 -> V_99 -> V_4 . V_220 ;
int V_221 ;
F_14 ( V_4 , - 1 ) ;
V_5 -> V_67 = false ;
V_221 = F_144 ( V_4 -> V_165 , F_98 , V_222 ,
V_220 ? V_220 -> V_210 : L_26 , V_4 ) ;
if ( V_221 ) {
F_65 ( V_4 -> V_34 , L_28 ) ;
return V_221 ;
}
V_221 = F_142 ( V_4 ) ;
if ( V_221 )
goto F_141;
F_131 ( V_5 , V_198 ) ;
if ( V_5 -> V_206 ) {
V_221 = V_5 -> V_206 ( V_4 ) ;
if ( V_221 < 0 )
F_136 ( V_4 ) ;
}
if ( V_5 -> V_208 ) {
V_221 = V_5 -> V_208 ( V_4 ) ;
if ( V_221 < 0 )
F_136 ( V_4 ) ;
}
V_5 -> V_192 = F_7 ( V_4 ) ;
V_5 -> V_164 = V_5 -> V_192 ;
F_23 ( V_4 , V_57 | V_223 ) ;
F_23 ( V_4 , V_224 | V_58 ) ;
F_147 ( & V_5 -> V_162 ,
F_92 ,
( unsigned long ) V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( ! V_5 -> V_213 ) {
F_93 ( & V_5 -> V_162 ,
V_163 + F_94 ( V_4 ) ) ;
} else {
F_148 ( V_4 , V_225 ) ;
F_23 ( V_4 , V_152 ) ;
F_19 ( V_4 , V_59 | V_60 ) ;
}
F_27 ( V_4 , V_62 ) ;
} else if ( F_6 ( V_4 ) ) {
if ( ! V_5 -> V_213 ) {
F_93 ( & V_5 -> V_162 ,
V_163 + F_94 ( V_4 ) ) ;
} else {
F_148 ( V_4 , V_225 ) ;
F_23 ( V_4 , V_152 ) ;
F_19 ( V_4 , V_60 ) ;
}
} else {
F_19 ( V_4 , V_63 ) ;
}
return 0 ;
F_141:
F_141 ( V_4 -> V_165 , V_4 ) ;
return V_221 ;
}
static void F_149 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_150 ( & V_5 -> V_162 ) ;
F_151 ( & V_5 -> V_97 ) ;
F_31 ( V_4 ) ;
F_26 ( V_4 ) ;
F_23 ( V_4 , V_57 ) ;
F_14 ( V_4 , - 1 ) ;
if ( V_5 -> V_207 )
V_5 -> V_207 ( V_4 ) ;
if ( V_5 -> V_209 )
V_5 -> V_209 ( V_4 ) ;
V_5 -> V_80 . V_83 = 0 ;
V_5 -> V_80 . V_84 = 0 ;
F_141 ( V_4 -> V_165 , V_4 ) ;
F_140 ( V_4 ) ;
V_5 -> V_67 = false ;
}
static void F_152 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_106 ( V_4 , 0 ) ;
V_5 -> V_174 . V_177 = 0 ;
}
}
static void F_153 ( struct V_2 * V_4 , unsigned int V_99 ,
unsigned int V_226 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_99 ) {
case 0 :
F_154 ( V_5 -> V_227 ) ;
F_19 ( V_4 , V_5 -> V_228 ) ;
break;
case 3 :
V_5 -> V_228 = F_99 ( V_4 ) ;
F_14 ( V_4 , - 1 ) ;
F_155 ( V_5 -> V_227 ) ;
break;
default:
F_65 ( V_4 -> V_34 , L_29 , V_99 ) ;
}
}
static void F_156 ( struct V_2 * V_4 , struct V_229 * V_230 ,
struct V_229 * V_231 )
{
unsigned long V_28 ;
unsigned int V_27 , V_232 , V_233 , V_234 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_27 = F_15 ( V_4 ) & ~ ( V_235 | V_236
| V_237 | V_238
| V_31 ) ;
V_234 = F_157 ( V_4 , V_230 , V_231 , 0 , V_4 -> V_239 / 16 ) ;
V_233 = F_158 ( V_4 , V_234 ) ;
if ( V_233 > 65535 ) {
V_233 /= 8 ;
V_27 |= V_240 ;
}
switch ( V_230 -> V_241 & V_242 ) {
case V_243 :
V_27 |= V_244 ;
break;
case V_245 :
V_27 |= V_246 ;
break;
case V_247 :
V_27 |= V_248 ;
break;
default:
V_27 |= V_249 ;
break;
}
if ( V_230 -> V_241 & V_250 )
V_27 |= V_251 ;
if ( V_230 -> V_241 & V_252 ) {
if ( V_230 -> V_241 & V_253 ) {
if ( V_230 -> V_241 & V_254 )
V_27 |= V_255 ;
else
V_27 |= V_256 ;
} else if ( V_230 -> V_241 & V_254 )
V_27 |= V_257 ;
else
V_27 |= V_258 ;
} else
V_27 |= V_259 ;
if ( V_230 -> V_241 & V_260 )
V_27 |= V_261 ;
else
V_27 |= V_262 ;
F_13 ( & V_4 -> V_29 , V_28 ) ;
V_4 -> V_61 = V_94 ;
if ( V_230 -> V_263 & V_264 )
V_4 -> V_61 |= ( V_89 | V_88 ) ;
if ( V_230 -> V_263 & ( V_265 | V_266 | V_267 ) )
V_4 -> V_61 |= V_87 ;
if ( F_3 ( V_4 ) )
F_19 ( V_4 , V_4 -> V_61 ) ;
V_4 -> V_268 = 0 ;
if ( V_230 -> V_263 & V_269 )
V_4 -> V_268 |= ( V_89 | V_88 ) ;
if ( V_230 -> V_263 & V_265 ) {
V_4 -> V_268 |= V_87 ;
if ( V_230 -> V_263 & V_269 )
V_4 -> V_268 |= V_94 ;
}
F_159 ( V_4 , V_230 -> V_241 , V_234 ) ;
V_232 = F_99 ( V_4 ) ;
F_14 ( V_4 , - 1 ) ;
F_23 ( V_4 , V_270 | V_64 ) ;
V_27 &= ~ V_31 ;
if ( V_5 -> V_32 . V_28 & V_33 ) {
if ( ( V_5 -> V_32 . V_36 ) > 0 )
F_17 ( V_4 ,
V_5 -> V_32 . V_36 ) ;
V_27 |= V_37 ;
}
F_18 ( V_4 , V_27 ) ;
F_160 ( V_4 , V_233 ) ;
F_23 ( V_4 , V_57 | V_223 ) ;
F_23 ( V_4 , V_224 | V_58 ) ;
F_19 ( V_4 , V_232 ) ;
if ( F_161 ( V_4 , V_230 -> V_241 ) )
F_32 ( V_4 ) ;
else
F_34 ( V_4 ) ;
F_20 ( & V_4 -> V_29 , V_28 ) ;
}
static void F_162 ( struct V_2 * V_4 , int V_271 )
{
if ( V_271 == V_272 ) {
V_4 -> V_28 |= V_273 ;
F_32 ( V_4 ) ;
} else {
V_4 -> V_28 &= ~ V_273 ;
}
}
static const char * F_163 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_274 ) ? L_30 : NULL ;
}
static void F_164 ( struct V_2 * V_4 )
{
struct V_197 * V_198 = F_146 ( V_4 -> V_34 ) ;
int V_275 = V_198 -> V_276 [ 0 ] . V_277 - V_198 -> V_276 [ 0 ] . V_278 + 1 ;
F_165 ( V_4 -> V_136 , V_275 ) ;
if ( V_4 -> V_28 & V_279 ) {
F_166 ( V_4 -> V_280 ) ;
V_4 -> V_280 = NULL ;
}
}
static int F_167 ( struct V_2 * V_4 )
{
struct V_197 * V_198 = F_146 ( V_4 -> V_34 ) ;
int V_275 = V_198 -> V_276 [ 0 ] . V_277 - V_198 -> V_276 [ 0 ] . V_278 + 1 ;
if ( ! F_168 ( V_4 -> V_136 , V_275 , L_26 ) )
return - V_281 ;
if ( V_4 -> V_28 & V_279 ) {
V_4 -> V_280 = F_169 ( V_4 -> V_136 , V_275 ) ;
if ( V_4 -> V_280 == NULL ) {
F_165 ( V_4 -> V_136 , V_275 ) ;
return - V_189 ;
}
}
return 0 ;
}
static void F_170 ( struct V_2 * V_4 , int V_28 )
{
if ( V_28 & V_282 ) {
V_4 -> type = V_274 ;
F_167 ( V_4 ) ;
}
}
static int F_171 ( struct V_2 * V_4 , struct V_283 * V_284 )
{
int V_11 = 0 ;
if ( V_284 -> type != V_285 && V_284 -> type != V_274 )
V_11 = - V_112 ;
if ( V_4 -> V_165 != V_284 -> V_165 )
V_11 = - V_112 ;
if ( V_284 -> V_286 != V_287 )
V_11 = - V_112 ;
if ( V_4 -> V_239 / 16 != V_284 -> V_288 )
V_11 = - V_112 ;
if ( ( void * ) V_4 -> V_136 != V_284 -> V_289 )
V_11 = - V_112 ;
if ( V_4 -> V_290 != V_284 -> V_4 )
V_11 = - V_112 ;
if ( V_284 -> V_291 != 0 )
V_11 = - V_112 ;
return V_11 ;
}
static int F_172 ( struct V_2 * V_4 )
{
while ( ! ( F_8 ( V_4 ) & V_63 ) )
F_173 () ;
return F_42 ( V_4 ) ;
}
static void F_174 ( struct V_2 * V_4 , unsigned char V_77 )
{
while ( ! ( F_8 ( V_4 ) & V_40 ) )
F_173 () ;
F_46 ( V_4 , V_77 ) ;
}
static int
F_175 ( struct V_2 * V_4 , unsigned int V_292 , unsigned long V_104 )
{
struct V_25 V_26 ;
switch ( V_292 ) {
case V_293 :
if ( F_176 ( & V_26 , (struct V_25 * ) V_104 ,
sizeof( V_26 ) ) )
return - V_294 ;
F_12 ( V_4 , & V_26 ) ;
break;
case V_295 :
if ( F_177 ( (struct V_25 * ) V_104 ,
& ( F_1 ( V_4 ) -> V_32 ) ,
sizeof( V_26 ) ) )
return - V_294 ;
break;
default:
return - V_296 ;
}
return 0 ;
}
static int F_178 ( struct V_1 * V_5 ,
struct V_197 * V_198 )
{
int V_11 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_202 * V_203 = F_132 ( & V_198 -> V_34 ) ;
if ( ! F_131 ( V_5 , V_198 ) )
F_136 ( V_4 ) ;
F_134 ( V_5 , V_198 ) ;
V_4 -> V_297 = V_298 ;
V_4 -> V_28 = V_299 ;
V_4 -> V_300 = & V_301 ;
V_4 -> V_302 = 1 ;
V_4 -> V_34 = & V_198 -> V_34 ;
V_4 -> V_136 = V_198 -> V_276 [ 0 ] . V_278 ;
V_4 -> V_165 = V_198 -> V_276 [ 1 ] . V_278 ;
F_179 ( & V_5 -> V_97 , F_127 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_80 , 0 , sizeof( V_5 -> V_80 ) ) ;
if ( V_203 && V_203 -> V_303 ) {
V_4 -> V_280 = V_203 -> V_303 ;
} else {
V_4 -> V_28 |= V_279 ;
V_4 -> V_280 = NULL ;
}
if ( ! V_5 -> V_227 ) {
V_5 -> V_227 = F_180 ( & V_198 -> V_34 , L_31 ) ;
if ( F_181 ( V_5 -> V_227 ) ) {
V_11 = F_182 ( V_5 -> V_227 ) ;
V_5 -> V_227 = NULL ;
return V_11 ;
}
V_11 = F_154 ( V_5 -> V_227 ) ;
if ( V_11 ) {
F_183 ( V_5 -> V_227 ) ;
V_5 -> V_227 = NULL ;
return V_11 ;
}
V_4 -> V_239 = F_184 ( V_5 -> V_227 ) ;
F_155 ( V_5 -> V_227 ) ;
}
if ( V_5 -> V_32 . V_28 & V_33 )
V_5 -> V_30 = V_35 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_302 = V_187 ;
V_5 -> V_30 = V_38 | V_39 ;
} else {
V_5 -> V_30 = V_40 ;
}
return 0 ;
}
static void F_185 ( struct V_2 * V_4 , int V_77 )
{
while ( ! ( F_8 ( V_4 ) & V_40 ) )
F_173 () ;
F_46 ( V_4 , V_77 ) ;
}
static void F_186 ( struct V_304 * V_305 , const char * V_306 , T_1 V_139 )
{
struct V_2 * V_4 = & V_307 [ V_305 -> V_308 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_232 ;
unsigned int V_174 ;
V_232 = F_99 ( V_4 ) ;
F_14 ( V_4 , V_63 | V_5 -> V_30 ) ;
V_174 = F_30 ( V_4 ) & V_56 ;
F_27 ( V_4 , V_54 ) ;
F_187 ( V_4 , V_306 , V_139 , F_185 ) ;
do {
V_10 = F_8 ( V_4 ) ;
} while ( ! ( V_10 & V_40 ) );
if ( V_174 )
F_27 ( V_4 , V_56 ) ;
F_19 ( V_4 , V_232 ) ;
}
static void T_7 F_188 ( struct V_2 * V_4 , int * V_234 ,
int * V_92 , int * V_309 )
{
unsigned int V_310 , V_233 ;
V_233 = F_189 ( V_4 ) & V_311 ;
if ( ! V_233 )
return;
V_310 = F_15 ( V_4 ) & V_236 ;
if ( V_310 == V_249 )
* V_309 = 8 ;
else
* V_309 = 7 ;
V_310 = F_15 ( V_4 ) & V_238 ;
if ( V_310 == V_258 )
* V_92 = 'e' ;
else if ( V_310 == V_257 )
* V_92 = 'o' ;
* V_234 = V_4 -> V_239 / ( 16 * ( V_233 - 1 ) ) ;
}
static int T_7 F_190 ( struct V_304 * V_305 , char * V_312 )
{
int V_11 ;
struct V_2 * V_4 = & V_307 [ V_305 -> V_308 ] . V_3 ;
int V_234 = 115200 ;
int V_309 = 8 ;
int V_92 = 'n' ;
int V_313 = 'n' ;
if ( V_4 -> V_280 == NULL ) {
return - V_314 ;
}
V_11 = F_154 ( V_307 [ V_305 -> V_308 ] . V_227 ) ;
if ( V_11 )
return V_11 ;
F_14 ( V_4 , - 1 ) ;
F_23 ( V_4 , V_57 | V_223 ) ;
F_23 ( V_4 , V_224 | V_58 ) ;
if ( V_312 )
F_191 ( V_312 , & V_234 , & V_92 , & V_309 , & V_313 ) ;
else
F_188 ( V_4 , & V_234 , & V_92 , & V_309 ) ;
return F_192 ( V_4 , V_305 , V_234 , V_92 , V_309 , V_313 ) ;
}
static int T_7 F_193 ( void )
{
int V_11 ;
if ( V_315 ) {
struct V_202 * V_203 =
F_132 ( & V_315 -> V_34 ) ;
int V_316 = V_203 -> V_317 ;
struct V_1 * V_4 = & V_307 [ V_316 ] ;
V_4 -> V_228 = 0 ;
V_4 -> V_3 . line = V_316 ;
F_194 ( V_318 , V_316 , NULL ) ;
V_11 = F_178 ( V_4 , V_315 ) ;
if ( V_11 )
return V_11 ;
F_195 ( & V_319 ) ;
}
return 0 ;
}
static int T_7 F_196 ( void )
{
if ( V_315
&& ! ( V_319 . V_28 & V_320 ) )
F_195 ( & V_319 ) ;
return 0 ;
}
static inline bool F_197 ( struct V_2 * V_4 )
{
return V_4 -> V_321 && V_4 -> V_321 -> V_308 == V_4 -> line ;
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
static int F_201 ( struct V_197 * V_198 ,
T_8 V_99 )
{
struct V_2 * V_4 = F_202 ( V_198 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_197 ( V_4 ) && V_322 ) {
while ( ! ( F_8 ( V_4 ) & V_35 ) )
F_173 () ;
}
V_5 -> V_323 = F_203 ( & V_198 -> V_34 ) ;
if ( F_198 () )
F_204 ( & V_198 -> V_34 , 0 ) ;
F_205 ( & V_324 , V_4 ) ;
return 0 ;
}
static int F_206 ( struct V_197 * V_198 )
{
struct V_2 * V_4 = F_202 ( V_198 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_207 ( & V_324 , V_4 ) ;
F_204 ( & V_198 -> V_34 , V_5 -> V_323 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_325 , struct V_326 * V_34 )
{
enum V_214 V_183 ;
struct V_327 * V_328 ;
V_325 -> V_12 = F_209 ( V_34 , 0 ) ;
if ( F_10 ( V_325 -> V_12 ) )
return - 1 ;
for ( V_183 = 0 ; V_183 < V_215 ; V_183 ++ ) {
V_328 = F_11 ( V_325 -> V_12 , V_183 ) ;
if ( V_328 && ( F_210 ( V_328 ) == V_329 ) )
V_325 -> V_68 [ V_183 ] = F_211 ( V_328 ) ;
else
V_325 -> V_68 [ V_183 ] = - V_112 ;
}
return 0 ;
}
static int F_212 ( struct V_197 * V_198 )
{
struct V_1 * V_4 ;
struct V_199 * V_200 = V_198 -> V_34 . V_201 ;
struct V_202 * V_203 = F_132 ( & V_198 -> V_34 ) ;
void * V_161 ;
int V_11 = - V_314 ;
F_213 ( V_85 & ( V_85 - 1 ) ) ;
if ( V_200 )
V_11 = F_214 ( V_200 , L_32 ) ;
else
if ( V_203 )
V_11 = V_203 -> V_317 ;
if ( V_11 < 0 )
V_11 = F_215 ( V_330 , V_331 ) ;
if ( V_11 >= V_331 ) {
V_11 = - V_314 ;
goto V_216;
}
if ( F_216 ( V_11 , V_330 ) ) {
V_11 = - V_281 ;
goto V_216;
}
V_4 = & V_307 [ V_11 ] ;
V_4 -> V_228 = 0 ;
V_4 -> V_3 . line = V_11 ;
V_11 = F_208 ( V_4 , & V_198 -> V_34 ) ;
if ( V_11 < 0 )
F_65 ( & V_198 -> V_34 , L_33 ,
L_34 ) ;
V_11 = F_178 ( V_4 , V_198 ) ;
if ( V_11 )
goto V_216;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_11 = - V_189 ;
V_161 = F_124 ( sizeof( struct V_81 )
* V_85 , V_188 ) ;
if ( ! V_161 )
goto V_332;
V_4 -> V_80 . V_86 = V_161 ;
}
V_11 = F_217 ( & V_324 , & V_4 -> V_3 ) ;
if ( V_11 )
goto V_333;
#ifdef F_218
if ( F_197 ( & V_4 -> V_3 )
&& V_334 -> V_28 & V_320 ) {
F_155 ( V_4 -> V_227 ) ;
}
#endif
F_219 ( & V_198 -> V_34 , 1 ) ;
F_220 ( V_198 , V_4 ) ;
if ( V_4 -> V_32 . V_28 & V_33 ) {
F_18 ( & V_4 -> V_3 , V_262 ) ;
F_23 ( & V_4 -> V_3 , V_45 ) ;
}
F_137 ( & V_4 -> V_3 ) ;
return 0 ;
V_333:
F_115 ( V_4 -> V_80 . V_86 ) ;
V_4 -> V_80 . V_86 = NULL ;
V_332:
if ( ! F_197 ( & V_4 -> V_3 ) ) {
F_183 ( V_4 -> V_227 ) ;
V_4 -> V_227 = NULL ;
}
V_216:
return V_11 ;
}
static int F_221 ( struct V_197 * V_198 )
{
struct V_2 * V_4 = F_202 ( V_198 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_11 = 0 ;
F_151 ( & V_5 -> V_97 ) ;
F_219 ( & V_198 -> V_34 , 0 ) ;
V_11 = F_222 ( & V_324 , V_4 ) ;
F_115 ( V_5 -> V_80 . V_86 ) ;
F_223 ( V_4 -> line , V_330 ) ;
F_183 ( V_5 -> V_227 ) ;
return V_11 ;
}
static int T_7 F_224 ( void )
{
int V_11 ;
V_11 = F_225 ( & V_324 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_226 ( & V_335 ) ;
if ( V_11 )
F_227 ( & V_324 ) ;
return V_11 ;
}
static void T_9 F_228 ( void )
{
F_229 ( & V_335 ) ;
F_227 ( & V_324 ) ;
}
