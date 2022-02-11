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
static void F_34 ( struct V_2 * V_4 , int V_73 )
{
if ( V_73 != 0 )
F_23 ( V_4 , V_74 ) ;
else
F_23 ( V_4 , V_75 ) ;
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
F_23 ( V_4 , V_57 ) ;
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
while ( V_10 & V_63 ) {
V_76 = F_40 ( V_4 ) ;
if ( F_41 ( V_10 & ( V_87 | V_88
| V_93 | V_86 )
|| V_5 -> V_95 ) ) {
F_23 ( V_4 , V_57 ) ;
if ( V_10 & V_86
&& ! V_5 -> V_95 ) {
V_5 -> V_95 = 1 ;
F_19 ( V_4 , V_86 ) ;
} else {
F_14 ( V_4 , V_86 ) ;
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
if ( V_4 -> V_99 && F_8 ( V_4 ) & V_5 -> V_30 ) {
F_44 ( V_4 , V_4 -> V_99 ) ;
V_4 -> V_89 . V_100 ++ ;
V_4 -> V_99 = 0 ;
}
if ( F_45 ( V_97 ) || F_46 ( V_4 ) )
return;
while ( F_8 ( V_4 ) & V_5 -> V_30 ) {
F_44 ( V_4 , V_97 -> V_85 [ V_97 -> V_83 ] ) ;
V_97 -> V_83 = ( V_97 -> V_83 + 1 ) & ( V_101 - 1 ) ;
V_4 -> V_89 . V_100 ++ ;
if ( F_45 ( V_97 ) )
break;
}
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_97 ) )
F_19 ( V_4 , V_5 -> V_30 ) ;
}
static void F_49 ( void * V_103 )
{
struct V_1 * V_5 = V_103 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
struct V_104 * V_105 = V_5 -> V_106 ;
unsigned long V_28 ;
F_13 ( & V_4 -> V_29 , V_28 ) ;
if ( V_105 )
F_50 ( V_105 ) ;
V_97 -> V_83 += F_51 ( & V_5 -> V_107 ) ;
V_97 -> V_83 &= V_101 - 1 ;
V_4 -> V_89 . V_100 += F_51 ( & V_5 -> V_107 ) ;
F_52 ( & V_5 -> V_108 ) ;
F_53 ( V_5 -> V_109 ) ;
V_5 -> V_110 = - V_111 ;
V_5 -> V_109 = NULL ;
F_54 ( & V_5 -> V_108 ) ;
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_97 ) )
F_42 ( & V_5 -> V_96 ) ;
F_20 ( & V_4 -> V_29 , V_28 ) ;
}
static void F_55 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_104 * V_105 = V_5 -> V_106 ;
if ( V_105 ) {
F_50 ( V_105 ) ;
F_56 ( V_105 ) ;
F_57 ( V_4 -> V_34 , & V_5 -> V_107 , 1 ,
V_112 ) ;
}
V_5 -> V_109 = NULL ;
V_5 -> V_106 = NULL ;
V_5 -> V_110 = - V_111 ;
}
static void F_58 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
struct V_104 * V_105 = V_5 -> V_106 ;
struct V_113 * V_114 ;
struct V_115 * V_116 = & V_5 -> V_107 ;
if ( V_5 -> V_109 != NULL )
return;
if ( ! F_45 ( V_97 ) && ! F_46 ( V_4 ) ) {
V_116 -> V_117 = V_97 -> V_83 & ( V_101 - 1 ) ;
F_59 ( V_116 ) = ( F_59 ( V_116 ) &
~ ( V_101 - 1 ) )
+ V_116 -> V_117 ;
F_51 ( V_116 ) = F_60 ( V_97 -> V_82 ,
V_97 -> V_83 ,
V_101 ) ;
F_61 ( ! F_51 ( V_116 ) ) ;
V_114 = F_62 ( V_105 ,
V_116 ,
1 ,
V_112 ,
V_118 |
V_119 ) ;
if ( ! V_114 ) {
F_63 ( V_4 -> V_34 , L_3 ) ;
return;
}
F_64 ( V_4 -> V_34 , V_116 , 1 , V_112 ) ;
V_5 -> V_109 = V_114 ;
V_114 -> V_120 = F_49 ;
V_114 -> V_121 = V_5 ;
V_5 -> V_110 = F_65 ( V_114 ) ;
} else {
if ( V_5 -> V_32 . V_28 & V_33 ) {
F_28 ( V_4 ) ;
}
}
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
}
static int F_66 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_3 V_122 ;
struct V_123 V_124 ;
int V_11 , V_125 ;
F_67 ( V_122 ) ;
F_68 ( V_126 , V_122 ) ;
V_5 -> V_106 = F_69 ( V_4 -> V_34 , L_4 ) ;
if ( V_5 -> V_106 == NULL )
goto V_127;
F_70 ( V_4 -> V_34 , L_5 ,
F_71 ( V_5 -> V_106 ) ) ;
F_72 ( & V_5 -> V_108 ) ;
F_73 ( & V_5 -> V_107 , 1 ) ;
F_61 ( ( int ) V_4 -> V_98 -> V_97 . V_85 & ~ V_128 ) ;
F_74 ( & V_5 -> V_107 ,
F_75 ( V_4 -> V_98 -> V_97 . V_85 ) ,
V_101 ,
( int ) V_4 -> V_98 -> V_97 . V_85 & ~ V_128 ) ;
V_125 = F_76 ( V_4 -> V_34 ,
& V_5 -> V_107 ,
1 ,
V_112 ) ;
if ( ! V_125 ) {
F_16 ( V_4 -> V_34 , L_6 ) ;
goto V_127;
} else {
F_16 ( V_4 -> V_34 , L_7 , V_129 ,
F_51 ( & V_5 -> V_107 ) ,
V_4 -> V_98 -> V_97 . V_85 ,
F_59 ( & V_5 -> V_107 ) ) ;
}
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_130 = V_112 ;
V_124 . V_131 = V_132 ;
V_124 . V_133 = V_4 -> V_134 + V_135 ;
V_11 = F_77 ( V_5 -> V_106 ,
V_136 ,
( unsigned long ) & V_124 ) ;
if ( V_11 ) {
F_63 ( V_4 -> V_34 , L_8 ) ;
goto V_127;
}
return 0 ;
V_127:
F_63 ( V_4 -> V_34 , L_9 ) ;
V_5 -> V_8 = 0 ;
if ( V_5 -> V_106 )
F_55 ( V_4 ) ;
return - V_111 ;
}
static void F_78 ( struct V_2 * V_4 ,
char * V_85 , T_4 V_137 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_138 * V_139 = & V_4 -> V_98 -> V_4 ;
F_79 ( V_4 -> V_34 ,
& V_5 -> V_140 ,
1 ,
V_141 ) ;
F_80 ( V_139 , V_85 , V_137 ) ;
F_64 ( V_4 -> V_34 ,
& V_5 -> V_140 ,
1 ,
V_141 ) ;
F_81 ( & V_4 -> V_29 ) ;
F_82 ( V_139 ) ;
F_83 ( & V_4 -> V_29 ) ;
}
static void F_84 ( void * V_103 )
{
struct V_2 * V_4 = V_103 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_96 ) ;
}
static void F_85 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_104 * V_105 = V_5 -> V_142 ;
if ( V_105 ) {
F_50 ( V_105 ) ;
F_56 ( V_105 ) ;
F_57 ( V_4 -> V_34 , & V_5 -> V_140 , 1 ,
V_141 ) ;
}
V_5 -> V_143 = NULL ;
V_5 -> V_142 = NULL ;
V_5 -> V_144 = - V_111 ;
}
static void F_86 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_78 = & V_5 -> V_79 ;
struct V_104 * V_105 = V_5 -> V_142 ;
struct V_145 V_98 ;
enum V_146 V_147 ;
T_4 V_148 , V_137 ;
F_23 ( V_4 , V_149 ) ;
V_147 = F_87 ( V_105 ,
V_5 -> V_144 ,
& V_98 ) ;
if ( V_147 == V_150 ) {
F_16 ( V_4 -> V_34 , L_10 ) ;
F_19 ( V_4 , V_60 ) ;
F_42 ( & V_5 -> V_96 ) ;
return;
}
V_148 = F_51 ( & V_5 -> V_140 ) - V_98 . V_151 ;
F_61 ( V_148 > F_51 ( & V_5 -> V_140 ) ) ;
if ( V_148 > V_78 -> V_82 ) {
V_137 = V_148 - V_78 -> V_82 ;
F_78 ( V_4 , V_78 -> V_85 + V_78 -> V_82 , V_137 ) ;
V_78 -> V_82 += V_137 ;
if ( V_78 -> V_82 == F_51 ( & V_5 -> V_140 ) )
V_78 -> V_82 = 0 ;
V_4 -> V_89 . V_152 += V_137 ;
}
F_19 ( V_4 , V_60 ) ;
}
static int F_88 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_113 * V_114 ;
T_3 V_122 ;
struct V_123 V_124 ;
struct V_77 * V_78 ;
int V_11 , V_125 ;
V_78 = & V_5 -> V_79 ;
F_67 ( V_122 ) ;
F_68 ( V_153 , V_122 ) ;
V_5 -> V_142 = F_69 ( V_4 -> V_34 , L_11 ) ;
if ( V_5 -> V_142 == NULL )
goto V_127;
F_70 ( V_4 -> V_34 , L_12 ,
F_71 ( V_5 -> V_142 ) ) ;
F_72 ( & V_5 -> V_154 ) ;
F_73 ( & V_5 -> V_140 , 1 ) ;
F_61 ( ( int ) V_4 -> V_98 -> V_97 . V_85 & ~ V_128 ) ;
F_74 ( & V_5 -> V_140 ,
F_75 ( V_78 -> V_85 ) ,
V_84 ,
( int ) V_78 -> V_85 & ~ V_128 ) ;
V_125 = F_76 ( V_4 -> V_34 ,
& V_5 -> V_140 ,
1 ,
V_141 ) ;
if ( ! V_125 ) {
F_16 ( V_4 -> V_34 , L_6 ) ;
goto V_127;
} else {
F_16 ( V_4 -> V_34 , L_7 , V_129 ,
F_51 ( & V_5 -> V_140 ) ,
V_78 -> V_85 ,
F_59 ( & V_5 -> V_140 ) ) ;
}
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_130 = V_141 ;
V_124 . V_155 = V_132 ;
V_124 . V_156 = V_4 -> V_134 + V_157 ;
V_11 = F_77 ( V_5 -> V_142 ,
V_136 ,
( unsigned long ) & V_124 ) ;
if ( V_11 ) {
F_63 ( V_4 -> V_34 , L_13 ) ;
goto V_127;
}
V_114 = F_89 ( V_5 -> V_142 ,
F_59 ( & V_5 -> V_140 ) ,
F_51 ( & V_5 -> V_140 ) ,
F_51 ( & V_5 -> V_140 ) / 2 ,
V_141 ,
V_118 ) ;
V_114 -> V_120 = F_84 ;
V_114 -> V_121 = V_4 ;
V_5 -> V_143 = V_114 ;
V_5 -> V_144 = F_65 ( V_114 ) ;
return 0 ;
V_127:
F_63 ( V_4 -> V_34 , L_14 ) ;
V_5 -> V_9 = 0 ;
if ( V_5 -> V_142 )
F_85 ( V_4 ) ;
return - V_111 ;
}
static void F_90 ( unsigned long V_158 )
{
struct V_2 * V_4 = ( void * ) V_158 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_42 ( & V_5 -> V_96 ) ;
F_91 ( & V_5 -> V_159 , V_160 + F_92 ( V_4 ) ) ;
}
static void
F_93 ( struct V_2 * V_4 , unsigned int V_148 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_148 & ( V_59 | V_60 ) ) {
F_14 ( V_4 , ( V_59
| V_60 ) ) ;
F_42 ( & V_5 -> V_96 ) ;
}
if ( V_148 & ( V_86 | V_93 |
V_88 | V_87 ) )
F_38 ( V_4 , V_148 ) ;
}
if ( F_6 ( V_4 ) ) {
if ( V_148 & V_60 ) {
F_14 ( V_4 , V_60 ) ;
F_42 ( & V_5 -> V_96 ) ;
}
}
if ( V_148 & V_63 )
F_39 ( V_4 ) ;
else if ( V_148 & V_86 ) {
F_23 ( V_4 , V_57 ) ;
F_14 ( V_4 , V_86 ) ;
V_5 -> V_95 = 0 ;
}
}
static void
F_94 ( struct V_2 * V_4 , unsigned int V_148 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_148 & V_5 -> V_30 ) {
F_14 ( V_4 , V_5 -> V_30 ) ;
F_42 ( & V_5 -> V_96 ) ;
}
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_148 ,
unsigned int V_10 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_148 & ( V_71 | V_70 | V_72
| V_69 ) ) {
V_5 -> V_161 = V_10 ;
F_42 ( & V_5 -> V_96 ) ;
}
}
static T_5 F_96 ( int V_162 , void * V_163 )
{
struct V_2 * V_4 = V_163 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_148 , V_164 = 0 ;
bool V_165 = false ;
do {
V_10 = F_7 ( V_4 ) ;
V_148 = V_10 & F_97 ( V_4 ) ;
if ( ! V_165 ) {
if ( V_162 == V_5 -> V_68 [ V_13 ] )
V_148 |= V_69 ;
if ( V_162 == V_5 -> V_68 [ V_16 ] )
V_148 |= V_70 ;
if ( V_162 == V_5 -> V_68 [ V_19 ] )
V_148 |= V_71 ;
if ( V_162 == V_5 -> V_68 [ V_22 ] )
V_148 |= V_72 ;
V_165 = true ;
}
if ( ! V_148 )
break;
F_93 ( V_4 , V_148 ) ;
F_95 ( V_4 , V_148 , V_10 ) ;
F_94 ( V_4 , V_148 ) ;
} while ( V_164 ++ < V_166 );
return V_164 ? V_167 : V_168 ;
}
static void F_98 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_169 * V_170 = & V_5 -> V_171 ;
F_99 ( V_4 -> V_34 ,
V_170 -> V_172 ,
V_170 -> V_173 ,
V_174 ) ;
}
static void F_100 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
struct V_169 * V_170 = & V_5 -> V_171 ;
int V_137 ;
if ( F_101 ( V_4 ) )
return;
V_97 -> V_83 += V_170 -> V_175 ;
V_97 -> V_83 &= V_101 - 1 ;
V_4 -> V_89 . V_100 += V_170 -> V_175 ;
V_170 -> V_175 = 0 ;
F_27 ( V_4 , V_54 ) ;
if ( ! F_45 ( V_97 ) && ! F_46 ( V_4 ) ) {
F_102 ( V_4 -> V_34 ,
V_170 -> V_172 ,
V_170 -> V_173 ,
V_174 ) ;
V_137 = F_60 ( V_97 -> V_82 , V_97 -> V_83 , V_101 ) ;
V_170 -> V_175 = V_137 ;
F_103 ( V_4 , V_170 -> V_172 + V_97 -> V_83 ) ;
F_104 ( V_4 , V_137 ) ;
F_27 ( V_4 , V_56 ) ;
F_19 ( V_4 , V_5 -> V_30 ) ;
} else {
if ( ( V_5 -> V_32 . V_28 & V_33 ) &&
! ( V_5 -> V_32 . V_28 & V_55 ) ) {
F_28 ( V_4 ) ;
}
}
if ( F_47 ( V_97 ) < V_102 )
F_48 ( V_4 ) ;
}
static int F_105 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_169 * V_170 = & V_5 -> V_171 ;
struct V_77 * V_97 = & V_4 -> V_98 -> V_97 ;
V_170 -> V_85 = V_97 -> V_85 ;
V_170 -> V_172 = F_106 ( V_4 -> V_34 ,
V_170 -> V_85 ,
V_101 ,
V_174 ) ;
V_170 -> V_173 = V_101 ;
V_170 -> V_175 = 0 ;
return 0 ;
}
static void F_107 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_77 * V_78 = & V_5 -> V_79 ;
unsigned int V_176 ;
unsigned int V_10 ;
while ( V_78 -> V_82 != V_78 -> V_83 ) {
struct V_80 V_81 ;
F_108 () ;
V_81 = ( (struct V_80 * ) V_78 -> V_85 ) [ V_78 -> V_83 ] ;
V_78 -> V_83 = ( V_78 -> V_83 + 1 ) & ( V_84 - 1 ) ;
V_4 -> V_89 . V_152 ++ ;
V_10 = V_81 . V_10 ;
V_176 = V_177 ;
if ( F_41 ( V_10 & ( V_87 | V_88
| V_93 | V_86 ) ) ) {
if ( V_10 & V_86 ) {
V_10 &= ~ ( V_87 | V_88 ) ;
V_4 -> V_89 . V_90 ++ ;
if ( F_109 ( V_4 ) )
continue;
}
if ( V_10 & V_87 )
V_4 -> V_89 . V_91 ++ ;
if ( V_10 & V_88 )
V_4 -> V_89 . V_92 ++ ;
if ( V_10 & V_93 )
V_4 -> V_89 . V_94 ++ ;
V_10 &= V_4 -> V_61 ;
if ( V_10 & V_86 )
V_176 = V_178 ;
else if ( V_10 & V_87 )
V_176 = V_179 ;
else if ( V_10 & V_88 )
V_176 = V_180 ;
}
if ( F_110 ( V_4 , V_81 . V_76 ) )
continue;
F_111 ( V_4 , V_10 , V_93 , V_81 . V_76 , V_176 ) ;
}
F_81 ( & V_4 -> V_29 ) ;
F_82 ( & V_4 -> V_98 -> V_4 ) ;
F_83 ( & V_4 -> V_29 ) ;
}
static void F_112 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_181 ;
for ( V_181 = 0 ; V_181 < 2 ; V_181 ++ ) {
struct V_169 * V_170 = & V_5 -> V_182 [ V_181 ] ;
F_99 ( V_4 -> V_34 ,
V_170 -> V_172 ,
V_170 -> V_173 ,
V_183 ) ;
F_113 ( V_170 -> V_85 ) ;
}
}
static void F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_138 * V_139 = & V_4 -> V_98 -> V_4 ;
struct V_169 * V_170 ;
int V_184 = V_5 -> V_185 ;
unsigned int V_82 ;
unsigned int V_83 ;
unsigned int V_137 ;
do {
F_23 ( V_4 , V_149 ) ;
V_170 = & V_5 -> V_182 [ V_184 ] ;
V_82 = F_115 ( V_4 ) - V_170 -> V_172 ;
V_83 = V_170 -> V_175 ;
V_82 = F_116 ( V_82 , V_170 -> V_173 ) ;
if ( F_117 ( V_82 != V_83 ) ) {
F_118 ( V_4 -> V_34 , V_170 -> V_172 ,
V_170 -> V_173 , V_183 ) ;
V_137 = V_82 - V_83 ;
F_80 ( V_139 , V_170 -> V_85 + V_170 -> V_175 ,
V_137 ) ;
F_102 ( V_4 -> V_34 , V_170 -> V_172 ,
V_170 -> V_173 , V_183 ) ;
V_4 -> V_89 . V_152 += V_137 ;
V_170 -> V_175 = V_82 ;
}
if ( V_82 >= V_170 -> V_173 ) {
V_170 -> V_175 = 0 ;
F_119 ( V_4 , V_170 -> V_172 ) ;
F_120 ( V_4 , V_170 -> V_173 ) ;
V_184 = ! V_184 ;
V_5 -> V_185 = V_184 ;
}
} while ( V_82 >= V_170 -> V_173 );
F_81 ( & V_4 -> V_29 ) ;
F_82 ( V_139 ) ;
F_83 ( & V_4 -> V_29 ) ;
F_19 ( V_4 , V_59 | V_60 ) ;
}
static int F_121 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_181 ;
for ( V_181 = 0 ; V_181 < 2 ; V_181 ++ ) {
struct V_169 * V_170 = & V_5 -> V_182 [ V_181 ] ;
V_170 -> V_85 = F_122 ( V_186 , V_187 ) ;
if ( V_170 -> V_85 == NULL ) {
if ( V_181 != 0 ) {
F_99 ( V_4 -> V_34 ,
V_5 -> V_182 [ 0 ] . V_172 ,
V_186 ,
V_183 ) ;
F_113 ( V_5 -> V_182 [ 0 ] . V_85 ) ;
}
V_5 -> V_6 = 0 ;
return - V_188 ;
}
V_170 -> V_172 = F_106 ( V_4 -> V_34 ,
V_170 -> V_85 ,
V_186 ,
V_183 ) ;
V_170 -> V_173 = V_186 ;
V_170 -> V_175 = 0 ;
}
V_5 -> V_185 = 0 ;
F_123 ( V_4 , V_5 -> V_182 [ 0 ] . V_172 ) ;
F_124 ( V_4 , V_186 ) ;
F_119 ( V_4 , V_5 -> V_182 [ 1 ] . V_172 ) ;
F_120 ( V_4 , V_186 ) ;
return 0 ;
}
static void F_125 ( unsigned long V_158 )
{
struct V_2 * V_4 = (struct V_2 * ) V_158 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 ;
unsigned int V_189 ;
F_83 ( & V_4 -> V_29 ) ;
V_5 -> V_190 ( V_4 ) ;
V_10 = V_5 -> V_161 ;
V_189 = V_10 ^ V_5 -> V_191 ;
if ( V_189 & ( V_21 | V_18
| V_24 | V_15 ) ) {
if ( V_189 & V_21 )
V_4 -> V_89 . V_192 ++ ;
if ( V_189 & V_18 )
V_4 -> V_89 . V_193 ++ ;
if ( V_189 & V_24 )
F_126 ( V_4 , ! ( V_10 & V_24 ) ) ;
if ( V_189 & V_15 )
F_127 ( V_4 , ! ( V_10 & V_15 ) ) ;
F_128 ( & V_4 -> V_98 -> V_4 . V_194 ) ;
V_5 -> V_191 = V_10 ;
}
V_5 -> V_195 ( V_4 ) ;
F_81 ( & V_4 -> V_29 ) ;
}
static int F_129 ( struct V_1 * V_5 ,
struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_34 . V_200 ;
struct V_201 * V_202 = F_130 ( & V_197 -> V_34 ) ;
if ( V_199 ) {
if ( F_131 ( V_199 , L_15 , NULL ) ) {
if ( F_131 ( V_199 , L_16 , NULL ) ) {
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
if ( F_131 ( V_199 , L_17 , NULL ) ) {
if ( F_131 ( V_199 , L_16 , NULL ) ) {
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
static void F_132 ( struct V_1 * V_5 ,
struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_34 . V_200 ;
struct V_201 * V_202 = F_130 ( & V_197 -> V_34 ) ;
if ( V_199 ) {
T_6 V_203 [ 2 ] ;
if ( F_133 ( V_199 , L_18 ,
V_203 , 2 ) == 0 ) {
struct V_25 * V_26 = & V_5 -> V_32 ;
V_26 -> V_204 = V_203 [ 0 ] ;
V_26 -> V_36 = V_203 [ 1 ] ;
V_26 -> V_28 = 0 ;
if ( F_131 ( V_199 , L_19 , NULL ) )
V_26 -> V_28 |= V_55 ;
if ( F_131 ( V_199 , L_20 ,
NULL ) )
V_26 -> V_28 |= V_33 ;
}
} else {
V_5 -> V_32 = V_202 -> V_32 ;
}
}
static void F_134 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_6 ( V_4 ) ) {
V_5 -> V_205 = & F_88 ;
V_5 -> V_195 = & F_86 ;
V_5 -> V_206 = & F_85 ;
} else if ( F_3 ( V_4 ) ) {
V_5 -> V_205 = & F_121 ;
V_5 -> V_195 = & F_114 ;
V_5 -> V_206 = & F_112 ;
} else {
V_5 -> V_205 = NULL ;
V_5 -> V_195 = & F_107 ;
V_5 -> V_206 = NULL ;
}
if ( F_5 ( V_4 ) ) {
V_5 -> V_207 = & F_66 ;
V_5 -> V_190 = & F_58 ;
V_5 -> V_208 = & F_55 ;
} else if ( F_4 ( V_4 ) ) {
V_5 -> V_207 = & F_105 ;
V_5 -> V_190 = & F_100 ;
V_5 -> V_208 = & F_98 ;
} else {
V_5 -> V_207 = NULL ;
V_5 -> V_190 = & F_43 ;
V_5 -> V_208 = NULL ;
}
}
static void F_135 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_209 = F_136 ( V_4 ) ;
T_6 V_210 ;
int V_211 , V_3 ;
V_211 = 0x55534152 ;
V_3 = 0x44424755 ;
V_5 -> V_212 = false ;
if ( V_209 == V_211 ) {
F_16 ( V_4 -> V_34 , L_21 ) ;
V_5 -> V_212 = true ;
} else if ( V_209 == V_3 ) {
F_16 ( V_4 -> V_34 , L_22 ) ;
V_5 -> V_212 = false ;
} else {
V_210 = F_137 ( V_4 ) ;
switch ( V_210 ) {
case 0x302 :
case 0x10213 :
F_16 ( V_4 -> V_34 , L_23 ) ;
V_5 -> V_212 = true ;
break;
case 0x203 :
case 0x10202 :
F_16 ( V_4 -> V_34 , L_24 ) ;
V_5 -> V_212 = false ;
break;
default:
F_63 ( V_4 -> V_34 , L_25 ) ;
}
}
}
static void F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
enum V_213 V_181 ;
for ( V_181 = 0 ; V_181 < V_214 ; V_181 ++ )
if ( V_5 -> V_68 [ V_181 ] >= 0 )
F_139 ( V_5 -> V_68 [ V_181 ] , V_4 ) ;
}
static int F_140 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int * V_162 = V_5 -> V_68 ;
enum V_213 V_181 ;
int V_215 = 0 ;
for ( V_181 = 0 ; ( V_181 < V_214 ) && ! V_215 ; V_181 ++ ) {
if ( V_162 [ V_181 ] < 0 )
continue;
F_141 ( V_162 [ V_181 ] , V_216 ) ;
V_215 = F_142 ( V_162 [ V_181 ] , F_96 , V_217 ,
L_26 , V_4 ) ;
if ( V_215 )
F_63 ( V_4 -> V_34 , L_27 ,
V_162 [ V_181 ] ) ;
}
while ( V_215 && ( -- V_181 >= 0 ) )
if ( V_162 [ V_181 ] >= 0 )
F_139 ( V_162 [ V_181 ] , V_4 ) ;
return V_215 ;
}
static int F_143 ( struct V_2 * V_4 )
{
struct V_196 * V_197 = F_144 ( V_4 -> V_34 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_218 * V_219 = V_4 -> V_98 -> V_4 . V_219 ;
int V_220 ;
F_14 ( V_4 , - 1 ) ;
V_5 -> V_67 = false ;
V_220 = F_142 ( V_4 -> V_162 , F_96 , V_221 ,
V_219 ? V_219 -> V_209 : L_26 , V_4 ) ;
if ( V_220 ) {
F_63 ( V_4 -> V_34 , L_28 ) ;
return V_220 ;
}
V_220 = F_140 ( V_4 ) ;
if ( V_220 )
goto F_139;
F_129 ( V_5 , V_197 ) ;
if ( V_5 -> V_205 ) {
V_220 = V_5 -> V_205 ( V_4 ) ;
if ( V_220 < 0 )
F_134 ( V_4 ) ;
}
if ( V_5 -> V_207 ) {
V_220 = V_5 -> V_207 ( V_4 ) ;
if ( V_220 < 0 )
F_134 ( V_4 ) ;
}
V_5 -> V_191 = F_7 ( V_4 ) ;
V_5 -> V_161 = V_5 -> V_191 ;
F_23 ( V_4 , V_57 | V_222 ) ;
F_23 ( V_4 , V_223 | V_58 ) ;
F_145 ( & V_5 -> V_159 ,
F_90 ,
( unsigned long ) V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( ! V_5 -> V_212 ) {
F_91 ( & V_5 -> V_159 ,
V_160 + F_92 ( V_4 ) ) ;
} else {
F_146 ( V_4 , V_224 ) ;
F_23 ( V_4 , V_149 ) ;
F_19 ( V_4 , V_59 | V_60 ) ;
}
F_27 ( V_4 , V_62 ) ;
} else if ( F_6 ( V_4 ) ) {
if ( ! V_5 -> V_212 ) {
F_91 ( & V_5 -> V_159 ,
V_160 + F_92 ( V_4 ) ) ;
} else {
F_146 ( V_4 , V_224 ) ;
F_23 ( V_4 , V_149 ) ;
F_19 ( V_4 , V_60 ) ;
}
} else {
F_19 ( V_4 , V_63 ) ;
}
return 0 ;
F_139:
F_139 ( V_4 -> V_162 , V_4 ) ;
return V_220 ;
}
static void F_147 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_148 ( & V_5 -> V_159 ) ;
F_149 ( & V_5 -> V_96 ) ;
F_31 ( V_4 ) ;
F_26 ( V_4 ) ;
F_23 ( V_4 , V_57 ) ;
F_14 ( V_4 , - 1 ) ;
if ( V_5 -> V_206 )
V_5 -> V_206 ( V_4 ) ;
if ( V_5 -> V_208 )
V_5 -> V_208 ( V_4 ) ;
V_5 -> V_79 . V_82 = 0 ;
V_5 -> V_79 . V_83 = 0 ;
F_139 ( V_4 -> V_162 , V_4 ) ;
F_138 ( V_4 ) ;
V_5 -> V_67 = false ;
}
static void F_150 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_104 ( V_4 , 0 ) ;
V_5 -> V_171 . V_175 = 0 ;
}
}
static void F_151 ( struct V_2 * V_4 , unsigned int V_98 ,
unsigned int V_225 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_98 ) {
case 0 :
F_152 ( V_5 -> V_226 ) ;
F_19 ( V_4 , V_5 -> V_227 ) ;
break;
case 3 :
V_5 -> V_227 = F_97 ( V_4 ) ;
F_14 ( V_4 , - 1 ) ;
F_153 ( V_5 -> V_226 ) ;
break;
default:
F_63 ( V_4 -> V_34 , L_29 , V_98 ) ;
}
}
static void F_154 ( struct V_2 * V_4 , struct V_228 * V_229 ,
struct V_228 * V_230 )
{
unsigned long V_28 ;
unsigned int V_27 , V_231 , V_232 , V_233 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_27 = F_15 ( V_4 ) & ~ ( V_234 | V_235
| V_236 | V_237
| V_31 ) ;
V_233 = F_155 ( V_4 , V_229 , V_230 , 0 , V_4 -> V_238 / 16 ) ;
V_232 = F_156 ( V_4 , V_233 ) ;
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
F_13 ( & V_4 -> V_29 , V_28 ) ;
V_4 -> V_61 = V_93 ;
if ( V_229 -> V_262 & V_263 )
V_4 -> V_61 |= ( V_88 | V_87 ) ;
if ( V_229 -> V_262 & ( V_264 | V_265 | V_266 ) )
V_4 -> V_61 |= V_86 ;
if ( F_3 ( V_4 ) )
F_19 ( V_4 , V_4 -> V_61 ) ;
V_4 -> V_267 = 0 ;
if ( V_229 -> V_262 & V_268 )
V_4 -> V_267 |= ( V_88 | V_87 ) ;
if ( V_229 -> V_262 & V_264 ) {
V_4 -> V_267 |= V_86 ;
if ( V_229 -> V_262 & V_268 )
V_4 -> V_267 |= V_93 ;
}
F_157 ( V_4 , V_229 -> V_240 , V_233 ) ;
V_231 = F_97 ( V_4 ) ;
F_14 ( V_4 , - 1 ) ;
F_23 ( V_4 , V_269 | V_64 ) ;
V_27 &= ~ V_31 ;
if ( V_5 -> V_32 . V_28 & V_33 ) {
if ( ( V_5 -> V_32 . V_36 ) > 0 )
F_17 ( V_4 ,
V_5 -> V_32 . V_36 ) ;
V_27 |= V_37 ;
}
F_18 ( V_4 , V_27 ) ;
F_158 ( V_4 , V_232 ) ;
F_23 ( V_4 , V_57 | V_222 ) ;
F_23 ( V_4 , V_223 | V_58 ) ;
F_19 ( V_4 , V_231 ) ;
if ( F_159 ( V_4 , V_229 -> V_240 ) )
V_4 -> V_270 -> V_271 ( V_4 ) ;
F_20 ( & V_4 -> V_29 , V_28 ) ;
}
static void F_160 ( struct V_2 * V_4 , int V_272 )
{
if ( V_272 == V_273 ) {
V_4 -> V_28 |= V_274 ;
F_32 ( V_4 ) ;
} else {
V_4 -> V_28 &= ~ V_274 ;
}
}
static const char * F_161 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_275 ) ? L_30 : NULL ;
}
static void F_162 ( struct V_2 * V_4 )
{
struct V_196 * V_197 = F_144 ( V_4 -> V_34 ) ;
int V_276 = V_197 -> V_277 [ 0 ] . V_278 - V_197 -> V_277 [ 0 ] . V_279 + 1 ;
F_163 ( V_4 -> V_134 , V_276 ) ;
if ( V_4 -> V_28 & V_280 ) {
F_164 ( V_4 -> V_281 ) ;
V_4 -> V_281 = NULL ;
}
}
static int F_165 ( struct V_2 * V_4 )
{
struct V_196 * V_197 = F_144 ( V_4 -> V_34 ) ;
int V_276 = V_197 -> V_277 [ 0 ] . V_278 - V_197 -> V_277 [ 0 ] . V_279 + 1 ;
if ( ! F_166 ( V_4 -> V_134 , V_276 , L_26 ) )
return - V_282 ;
if ( V_4 -> V_28 & V_280 ) {
V_4 -> V_281 = F_167 ( V_4 -> V_134 , V_276 ) ;
if ( V_4 -> V_281 == NULL ) {
F_163 ( V_4 -> V_134 , V_276 ) ;
return - V_188 ;
}
}
return 0 ;
}
static void F_168 ( struct V_2 * V_4 , int V_28 )
{
if ( V_28 & V_283 ) {
V_4 -> type = V_275 ;
F_165 ( V_4 ) ;
}
}
static int F_169 ( struct V_2 * V_4 , struct V_284 * V_285 )
{
int V_11 = 0 ;
if ( V_285 -> type != V_286 && V_285 -> type != V_275 )
V_11 = - V_111 ;
if ( V_4 -> V_162 != V_285 -> V_162 )
V_11 = - V_111 ;
if ( V_285 -> V_287 != V_288 )
V_11 = - V_111 ;
if ( V_4 -> V_238 / 16 != V_285 -> V_289 )
V_11 = - V_111 ;
if ( ( void * ) V_4 -> V_134 != V_285 -> V_290 )
V_11 = - V_111 ;
if ( V_4 -> V_291 != V_285 -> V_4 )
V_11 = - V_111 ;
if ( V_285 -> V_292 != 0 )
V_11 = - V_111 ;
return V_11 ;
}
static int F_170 ( struct V_2 * V_4 )
{
while ( ! ( F_8 ( V_4 ) & V_63 ) )
F_171 () ;
return F_40 ( V_4 ) ;
}
static void F_172 ( struct V_2 * V_4 , unsigned char V_76 )
{
while ( ! ( F_8 ( V_4 ) & V_40 ) )
F_171 () ;
F_44 ( V_4 , V_76 ) ;
}
static int
F_173 ( struct V_2 * V_4 , unsigned int V_293 , unsigned long V_103 )
{
struct V_25 V_26 ;
switch ( V_293 ) {
case V_294 :
if ( F_174 ( & V_26 , (struct V_25 * ) V_103 ,
sizeof( V_26 ) ) )
return - V_295 ;
F_12 ( V_4 , & V_26 ) ;
break;
case V_296 :
if ( F_175 ( (struct V_25 * ) V_103 ,
& ( F_1 ( V_4 ) -> V_32 ) ,
sizeof( V_26 ) ) )
return - V_295 ;
break;
default:
return - V_297 ;
}
return 0 ;
}
static int F_176 ( struct V_1 * V_5 ,
struct V_196 * V_197 )
{
int V_11 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_201 * V_202 = F_130 ( & V_197 -> V_34 ) ;
if ( ! F_129 ( V_5 , V_197 ) )
F_134 ( V_4 ) ;
F_132 ( V_5 , V_197 ) ;
V_4 -> V_298 = V_299 ;
V_4 -> V_28 = V_300 ;
V_4 -> V_270 = & V_301 ;
V_4 -> V_302 = 1 ;
V_4 -> V_34 = & V_197 -> V_34 ;
V_4 -> V_134 = V_197 -> V_277 [ 0 ] . V_279 ;
V_4 -> V_162 = V_197 -> V_277 [ 1 ] . V_279 ;
F_177 ( & V_5 -> V_96 , F_125 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_79 , 0 , sizeof( V_5 -> V_79 ) ) ;
if ( V_202 && V_202 -> V_303 ) {
V_4 -> V_281 = V_202 -> V_303 ;
} else {
V_4 -> V_28 |= V_280 ;
V_4 -> V_281 = NULL ;
}
if ( ! V_5 -> V_226 ) {
V_5 -> V_226 = F_178 ( & V_197 -> V_34 , L_31 ) ;
if ( F_179 ( V_5 -> V_226 ) ) {
V_11 = F_180 ( V_5 -> V_226 ) ;
V_5 -> V_226 = NULL ;
return V_11 ;
}
V_11 = F_152 ( V_5 -> V_226 ) ;
if ( V_11 ) {
F_181 ( V_5 -> V_226 ) ;
V_5 -> V_226 = NULL ;
return V_11 ;
}
V_4 -> V_238 = F_182 ( V_5 -> V_226 ) ;
F_153 ( V_5 -> V_226 ) ;
}
if ( V_5 -> V_32 . V_28 & V_33 )
V_5 -> V_30 = V_35 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_302 = V_186 ;
V_5 -> V_30 = V_38 | V_39 ;
} else {
V_5 -> V_30 = V_40 ;
}
return 0 ;
}
static void F_183 ( struct V_2 * V_4 , int V_76 )
{
while ( ! ( F_8 ( V_4 ) & V_40 ) )
F_171 () ;
F_44 ( V_4 , V_76 ) ;
}
static void F_184 ( struct V_304 * V_305 , const char * V_306 , T_1 V_137 )
{
struct V_2 * V_4 = & V_307 [ V_305 -> V_308 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 , V_231 ;
unsigned int V_171 ;
V_231 = F_97 ( V_4 ) ;
F_14 ( V_4 , V_63 | V_5 -> V_30 ) ;
V_171 = F_30 ( V_4 ) & V_56 ;
F_27 ( V_4 , V_54 ) ;
F_185 ( V_4 , V_306 , V_137 , F_183 ) ;
do {
V_10 = F_8 ( V_4 ) ;
} while ( ! ( V_10 & V_40 ) );
if ( V_171 )
F_27 ( V_4 , V_56 ) ;
F_19 ( V_4 , V_231 ) ;
}
static void T_7 F_186 ( struct V_2 * V_4 , int * V_233 ,
int * V_91 , int * V_309 )
{
unsigned int V_310 , V_232 ;
V_232 = F_187 ( V_4 ) & V_311 ;
if ( ! V_232 )
return;
V_310 = F_15 ( V_4 ) & V_235 ;
if ( V_310 == V_248 )
* V_309 = 8 ;
else
* V_309 = 7 ;
V_310 = F_15 ( V_4 ) & V_237 ;
if ( V_310 == V_257 )
* V_91 = 'e' ;
else if ( V_310 == V_256 )
* V_91 = 'o' ;
* V_233 = V_4 -> V_238 / ( 16 * ( V_232 - 1 ) ) ;
}
static int T_7 F_188 ( struct V_304 * V_305 , char * V_312 )
{
int V_11 ;
struct V_2 * V_4 = & V_307 [ V_305 -> V_308 ] . V_3 ;
int V_233 = 115200 ;
int V_309 = 8 ;
int V_91 = 'n' ;
int V_313 = 'n' ;
if ( V_4 -> V_281 == NULL ) {
return - V_314 ;
}
V_11 = F_152 ( V_307 [ V_305 -> V_308 ] . V_226 ) ;
if ( V_11 )
return V_11 ;
F_14 ( V_4 , - 1 ) ;
F_23 ( V_4 , V_57 | V_222 ) ;
F_23 ( V_4 , V_223 | V_58 ) ;
if ( V_312 )
F_189 ( V_312 , & V_233 , & V_91 , & V_309 , & V_313 ) ;
else
F_186 ( V_4 , & V_233 , & V_91 , & V_309 ) ;
return F_190 ( V_4 , V_305 , V_233 , V_91 , V_309 , V_313 ) ;
}
static int T_7 F_191 ( void )
{
int V_11 ;
if ( V_315 ) {
struct V_201 * V_202 =
F_130 ( & V_315 -> V_34 ) ;
int V_316 = V_202 -> V_317 ;
struct V_1 * V_4 = & V_307 [ V_316 ] ;
V_4 -> V_227 = 0 ;
V_4 -> V_3 . line = V_316 ;
F_192 ( V_318 , V_316 , NULL ) ;
V_11 = F_176 ( V_4 , V_315 ) ;
if ( V_11 )
return V_11 ;
F_193 ( & V_319 ) ;
}
return 0 ;
}
static int T_7 F_194 ( void )
{
if ( V_315
&& ! ( V_319 . V_28 & V_320 ) )
F_193 ( & V_319 ) ;
return 0 ;
}
static inline bool F_195 ( struct V_2 * V_4 )
{
return V_4 -> V_321 && V_4 -> V_321 -> V_308 == V_4 -> line ;
}
static inline bool F_195 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_196 ( void )
{
#ifdef F_197
return F_198 () ;
#else
return false ;
#endif
}
static int F_199 ( struct V_196 * V_197 ,
T_8 V_98 )
{
struct V_2 * V_4 = F_200 ( V_197 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_195 ( V_4 ) && V_322 ) {
while ( ! ( F_8 ( V_4 ) & V_35 ) )
F_171 () ;
}
V_5 -> V_323 = F_201 ( & V_197 -> V_34 ) ;
if ( F_196 () )
F_202 ( & V_197 -> V_34 , 0 ) ;
F_203 ( & V_324 , V_4 ) ;
return 0 ;
}
static int F_204 ( struct V_196 * V_197 )
{
struct V_2 * V_4 = F_200 ( V_197 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_205 ( & V_324 , V_4 ) ;
F_202 ( & V_197 -> V_34 , V_5 -> V_323 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_325 , struct V_326 * V_34 )
{
enum V_213 V_181 ;
struct V_327 * V_328 ;
V_325 -> V_12 = F_207 ( V_34 , 0 ) ;
if ( F_10 ( V_325 -> V_12 ) )
return - 1 ;
for ( V_181 = 0 ; V_181 < V_214 ; V_181 ++ ) {
V_328 = F_11 ( V_325 -> V_12 , V_181 ) ;
if ( V_328 && ( F_208 ( V_328 ) == V_329 ) )
V_325 -> V_68 [ V_181 ] = F_209 ( V_328 ) ;
else
V_325 -> V_68 [ V_181 ] = - V_111 ;
}
return 0 ;
}
static int F_210 ( struct V_196 * V_197 )
{
struct V_1 * V_4 ;
struct V_198 * V_199 = V_197 -> V_34 . V_200 ;
struct V_201 * V_202 = F_130 ( & V_197 -> V_34 ) ;
void * V_158 ;
int V_11 = - V_314 ;
F_211 ( V_84 & ( V_84 - 1 ) ) ;
if ( V_199 )
V_11 = F_212 ( V_199 , L_32 ) ;
else
if ( V_202 )
V_11 = V_202 -> V_317 ;
if ( V_11 < 0 )
V_11 = F_213 ( V_330 , V_331 ) ;
if ( V_11 >= V_331 ) {
V_11 = - V_314 ;
goto V_215;
}
if ( F_214 ( V_11 , V_330 ) ) {
V_11 = - V_282 ;
goto V_215;
}
V_4 = & V_307 [ V_11 ] ;
V_4 -> V_227 = 0 ;
V_4 -> V_3 . line = V_11 ;
V_11 = F_206 ( V_4 , & V_197 -> V_34 ) ;
if ( V_11 < 0 )
F_63 ( & V_197 -> V_34 , L_33 ,
L_34 ) ;
V_11 = F_176 ( V_4 , V_197 ) ;
if ( V_11 )
goto V_215;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_11 = - V_188 ;
V_158 = F_122 ( sizeof( struct V_80 )
* V_84 , V_187 ) ;
if ( ! V_158 )
goto V_332;
V_4 -> V_79 . V_85 = V_158 ;
}
V_11 = F_215 ( & V_324 , & V_4 -> V_3 ) ;
if ( V_11 )
goto V_333;
#ifdef F_216
if ( F_195 ( & V_4 -> V_3 )
&& V_334 -> V_28 & V_320 ) {
F_153 ( V_4 -> V_226 ) ;
}
#endif
F_217 ( & V_197 -> V_34 , 1 ) ;
F_218 ( V_197 , V_4 ) ;
if ( V_4 -> V_32 . V_28 & V_33 ) {
F_18 ( & V_4 -> V_3 , V_261 ) ;
F_23 ( & V_4 -> V_3 , V_45 ) ;
}
F_135 ( & V_4 -> V_3 ) ;
return 0 ;
V_333:
F_113 ( V_4 -> V_79 . V_85 ) ;
V_4 -> V_79 . V_85 = NULL ;
V_332:
if ( ! F_195 ( & V_4 -> V_3 ) ) {
F_181 ( V_4 -> V_226 ) ;
V_4 -> V_226 = NULL ;
}
V_215:
return V_11 ;
}
static int F_219 ( struct V_196 * V_197 )
{
struct V_2 * V_4 = F_200 ( V_197 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_11 = 0 ;
F_149 ( & V_5 -> V_96 ) ;
F_217 ( & V_197 -> V_34 , 0 ) ;
V_11 = F_220 ( & V_324 , V_4 ) ;
F_113 ( V_5 -> V_79 . V_85 ) ;
F_221 ( V_4 -> line , V_330 ) ;
F_181 ( V_5 -> V_226 ) ;
return V_11 ;
}
static int T_7 F_222 ( void )
{
int V_11 ;
V_11 = F_223 ( & V_324 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_224 ( & V_335 ) ;
if ( V_11 )
F_225 ( & V_324 ) ;
return V_11 ;
}
static void T_9 F_226 ( void )
{
F_227 ( & V_335 ) ;
F_225 ( & V_324 ) ;
}
