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
void F_7 ( struct V_2 * V_4 , struct V_10 * V_11 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_12 ;
unsigned long V_13 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
F_9 ( V_4 , V_5 -> V_15 ) ;
V_12 = F_10 ( V_4 ) ;
V_12 &= ~ V_16 ;
V_5 -> V_17 = * V_11 ;
if ( V_11 -> V_13 & V_18 ) {
F_11 ( V_4 -> V_19 , L_1 ) ;
V_5 -> V_15 = V_20 ;
if ( ( V_11 -> V_21 ) > 0 )
F_12 ( V_4 , V_11 -> V_21 ) ;
V_12 |= V_22 ;
} else {
F_11 ( V_4 -> V_19 , L_2 ) ;
if ( F_4 ( V_4 ) )
V_5 -> V_15 = V_23 |
V_24 ;
else
V_5 -> V_15 = V_25 ;
}
F_13 ( V_4 , V_12 ) ;
F_14 ( V_4 , V_5 -> V_15 ) ;
F_15 ( & V_4 -> V_14 , V_13 ) ;
}
static T_1 F_16 ( struct V_2 * V_4 )
{
return ( F_17 ( V_4 ) & V_20 ) ? V_26 : 0 ;
}
static void F_18 ( struct V_2 * V_4 , T_1 V_27 )
{
unsigned int V_28 = 0 ;
unsigned int V_12 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_19 ( V_5 -> V_29 ) ) {
if ( V_27 & V_30 )
F_20 ( V_5 -> V_29 , 0 ) ;
else
F_20 ( V_5 -> V_29 , 1 ) ;
}
if ( V_27 & V_30 )
V_28 |= V_31 ;
else
V_28 |= V_32 ;
if ( V_27 & V_33 )
V_28 |= V_34 ;
else
V_28 |= V_35 ;
F_21 ( V_4 , V_28 ) ;
V_12 = F_10 ( V_4 ) & ~ V_36 ;
if ( V_27 & V_37 )
V_12 |= V_38 ;
else
V_12 |= V_39 ;
V_12 &= ~ V_16 ;
if ( V_5 -> V_17 . V_13 & V_18 ) {
F_11 ( V_4 -> V_19 , L_1 ) ;
if ( ( V_5 -> V_17 . V_21 ) > 0 )
F_12 ( V_4 ,
V_5 -> V_17 . V_21 ) ;
V_12 |= V_22 ;
} else {
F_11 ( V_4 -> V_19 , L_2 ) ;
}
F_13 ( V_4 , V_12 ) ;
}
static T_1 F_22 ( struct V_2 * V_4 )
{
unsigned int V_40 , V_41 = 0 ;
V_40 = F_17 ( V_4 ) ;
if ( ! ( V_40 & V_42 ) )
V_41 |= V_43 ;
if ( ! ( V_40 & V_44 ) )
V_41 |= V_45 ;
if ( ! ( V_40 & V_46 ) )
V_41 |= V_47 ;
if ( ! ( V_40 & V_48 ) )
V_41 |= V_49 ;
return V_41 ;
}
static void F_23 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_24 ( V_4 , V_50 ) ;
}
F_9 ( V_4 , V_5 -> V_15 ) ;
if ( ( V_5 -> V_17 . V_13 & V_18 ) &&
! ( V_5 -> V_17 . V_13 & V_51 ) )
F_25 ( V_4 ) ;
}
static void F_26 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
if ( F_27 ( V_4 ) & V_52 )
return;
if ( ( V_5 -> V_17 . V_13 & V_18 ) &&
! ( V_5 -> V_17 . V_13 & V_51 ) )
F_28 ( V_4 ) ;
F_24 ( V_4 , V_52 ) ;
}
F_14 ( V_4 , V_5 -> V_15 ) ;
}
static void F_25 ( struct V_2 * V_4 )
{
F_21 ( V_4 , V_53 ) ;
F_21 ( V_4 , V_54 ) ;
if ( F_3 ( V_4 ) ) {
F_14 ( V_4 , V_55 | V_56 |
V_4 -> V_57 ) ;
F_24 ( V_4 , V_58 ) ;
} else {
F_14 ( V_4 , V_59 ) ;
}
}
static void F_28 ( struct V_2 * V_4 )
{
F_21 ( V_4 , V_60 ) ;
if ( F_3 ( V_4 ) ) {
F_24 ( V_4 , V_61 ) ;
F_9 ( V_4 , V_55 | V_56 |
V_4 -> V_57 ) ;
} else {
F_9 ( V_4 , V_59 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
F_14 ( V_4 , V_62 | V_63
| V_64 | V_65 ) ;
}
static void F_30 ( struct V_2 * V_4 , int V_66 )
{
if ( V_66 != 0 )
F_21 ( V_4 , V_67 ) ;
else
F_21 ( V_4 , V_68 ) ;
}
static void
F_31 ( struct V_2 * V_4 , unsigned int V_40 ,
unsigned int V_69 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_71 = & V_5 -> V_72 ;
struct V_73 * V_74 ;
if ( ! F_32 ( V_71 -> V_75 , V_71 -> V_76 , V_77 ) )
return;
V_74 = & ( (struct V_73 * ) V_71 -> V_78 ) [ V_71 -> V_75 ] ;
V_74 -> V_40 = V_40 ;
V_74 -> V_69 = V_69 ;
F_33 () ;
V_71 -> V_75 = ( V_71 -> V_75 + 1 ) & ( V_77 - 1 ) ;
}
static void F_34 ( struct V_2 * V_4 , unsigned int V_40 )
{
F_21 ( V_4 , V_53 ) ;
if ( V_40 & V_79 ) {
V_40 &= ~ ( V_80 | V_81 ) ;
V_4 -> V_82 . V_83 ++ ;
}
if ( V_40 & V_80 )
V_4 -> V_82 . V_84 ++ ;
if ( V_40 & V_81 )
V_4 -> V_82 . V_85 ++ ;
if ( V_40 & V_86 )
V_4 -> V_82 . V_87 ++ ;
}
static void F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 , V_69 ;
V_40 = F_17 ( V_4 ) ;
while ( V_40 & V_59 ) {
V_69 = F_36 ( V_4 ) ;
if ( F_37 ( V_40 & ( V_80 | V_81
| V_86 | V_79 )
|| V_5 -> V_88 ) ) {
F_21 ( V_4 , V_53 ) ;
if ( V_40 & V_79
&& ! V_5 -> V_88 ) {
V_5 -> V_88 = 1 ;
F_14 ( V_4 , V_79 ) ;
} else {
F_9 ( V_4 , V_79 ) ;
V_40 &= ~ V_79 ;
V_5 -> V_88 = 0 ;
}
}
F_31 ( V_4 , V_40 , V_69 ) ;
V_40 = F_17 ( V_4 ) ;
}
F_38 ( & V_5 -> V_89 ) ;
}
static void F_39 ( struct V_2 * V_4 )
{
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_92 && F_17 ( V_4 ) & V_5 -> V_15 ) {
F_40 ( V_4 , V_4 -> V_92 ) ;
V_4 -> V_82 . V_93 ++ ;
V_4 -> V_92 = 0 ;
}
if ( F_41 ( V_90 ) || F_42 ( V_4 ) )
return;
while ( F_17 ( V_4 ) & V_5 -> V_15 ) {
F_40 ( V_4 , V_90 -> V_78 [ V_90 -> V_76 ] ) ;
V_90 -> V_76 = ( V_90 -> V_76 + 1 ) & ( V_94 - 1 ) ;
V_4 -> V_82 . V_93 ++ ;
if ( F_41 ( V_90 ) )
break;
}
if ( F_43 ( V_90 ) < V_95 )
F_44 ( V_4 ) ;
if ( ! F_41 ( V_90 ) )
F_14 ( V_4 , V_5 -> V_15 ) ;
}
static void F_45 ( void * V_96 )
{
struct V_1 * V_5 = V_96 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
struct V_97 * V_98 = V_5 -> V_99 ;
unsigned long V_13 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
if ( V_98 )
F_46 ( V_98 ) ;
V_90 -> V_76 += F_47 ( & V_5 -> V_100 ) ;
V_90 -> V_76 &= V_94 - 1 ;
V_4 -> V_82 . V_93 += F_47 ( & V_5 -> V_100 ) ;
F_48 ( & V_5 -> V_101 ) ;
F_49 ( V_5 -> V_102 ) ;
V_5 -> V_103 = - V_104 ;
V_5 -> V_102 = NULL ;
F_50 ( & V_5 -> V_101 ) ;
if ( F_43 ( V_90 ) < V_95 )
F_44 ( V_4 ) ;
if ( ! F_41 ( V_90 ) )
F_38 ( & V_5 -> V_89 ) ;
F_15 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_51 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_97 * V_98 = V_5 -> V_99 ;
if ( V_98 ) {
F_46 ( V_98 ) ;
F_52 ( V_98 ) ;
F_53 ( V_4 -> V_19 , & V_5 -> V_100 , 1 ,
V_105 ) ;
}
V_5 -> V_102 = NULL ;
V_5 -> V_99 = NULL ;
V_5 -> V_103 = - V_104 ;
}
static void F_54 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
struct V_97 * V_98 = V_5 -> V_99 ;
struct V_106 * V_107 ;
struct V_108 * V_109 = & V_5 -> V_100 ;
if ( V_5 -> V_102 != NULL )
return;
if ( ! F_41 ( V_90 ) && ! F_42 ( V_4 ) ) {
V_109 -> V_110 = V_90 -> V_76 & ( V_94 - 1 ) ;
F_55 ( V_109 ) = ( F_55 ( V_109 ) &
~ ( V_94 - 1 ) )
+ V_109 -> V_110 ;
F_47 ( V_109 ) = F_56 ( V_90 -> V_75 ,
V_90 -> V_76 ,
V_94 ) ;
F_57 ( ! F_47 ( V_109 ) ) ;
V_107 = F_58 ( V_98 ,
V_109 ,
1 ,
V_105 ,
V_111 |
V_112 ) ;
if ( ! V_107 ) {
F_59 ( V_4 -> V_19 , L_3 ) ;
return;
}
F_60 ( V_4 -> V_19 , V_109 , 1 , V_105 ) ;
V_5 -> V_102 = V_107 ;
V_107 -> V_113 = F_45 ;
V_107 -> V_114 = V_5 ;
V_5 -> V_103 = F_61 ( V_107 ) ;
} else {
if ( V_5 -> V_17 . V_13 & V_18 ) {
F_25 ( V_4 ) ;
}
}
if ( F_43 ( V_90 ) < V_95 )
F_44 ( V_4 ) ;
}
static int F_62 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_115 ;
struct V_116 V_117 ;
int V_41 , V_118 ;
F_63 ( V_115 ) ;
F_64 ( V_119 , V_115 ) ;
V_5 -> V_99 = F_65 ( V_4 -> V_19 , L_4 ) ;
if ( V_5 -> V_99 == NULL )
goto V_120;
F_66 ( V_4 -> V_19 , L_5 ,
F_67 ( V_5 -> V_99 ) ) ;
F_68 ( & V_5 -> V_101 ) ;
F_69 ( & V_5 -> V_100 , 1 ) ;
F_57 ( ( int ) V_4 -> V_91 -> V_90 . V_78 & ~ V_121 ) ;
F_70 ( & V_5 -> V_100 ,
F_71 ( V_4 -> V_91 -> V_90 . V_78 ) ,
V_94 ,
( int ) V_4 -> V_91 -> V_90 . V_78 & ~ V_121 ) ;
V_118 = F_72 ( V_4 -> V_19 ,
& V_5 -> V_100 ,
1 ,
V_105 ) ;
if ( ! V_118 ) {
F_11 ( V_4 -> V_19 , L_6 ) ;
goto V_120;
} else {
F_11 ( V_4 -> V_19 , L_7 , V_122 ,
F_47 ( & V_5 -> V_100 ) ,
V_4 -> V_91 -> V_90 . V_78 ,
F_55 ( & V_5 -> V_100 ) ) ;
}
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_123 = V_105 ;
V_117 . V_124 = V_125 ;
V_117 . V_126 = V_4 -> V_127 + V_128 ;
V_41 = F_73 ( V_5 -> V_99 ,
V_129 ,
( unsigned long ) & V_117 ) ;
if ( V_41 ) {
F_59 ( V_4 -> V_19 , L_8 ) ;
goto V_120;
}
return 0 ;
V_120:
F_59 ( V_4 -> V_19 , L_9 ) ;
V_5 -> V_8 = 0 ;
if ( V_5 -> V_99 )
F_51 ( V_4 ) ;
return - V_104 ;
}
static void F_74 ( struct V_2 * V_4 ,
char * V_78 , T_3 V_130 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_131 * V_132 = & V_4 -> V_91 -> V_4 ;
F_75 ( V_4 -> V_19 ,
& V_5 -> V_133 ,
1 ,
V_134 ) ;
F_76 ( V_132 , V_78 , V_130 ) ;
F_60 ( V_4 -> V_19 ,
& V_5 -> V_133 ,
1 ,
V_134 ) ;
F_77 ( & V_4 -> V_14 ) ;
F_78 ( V_132 ) ;
F_79 ( & V_4 -> V_14 ) ;
}
static void F_80 ( void * V_96 )
{
struct V_2 * V_4 = V_96 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_38 ( & V_5 -> V_89 ) ;
}
static void F_81 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_97 * V_98 = V_5 -> V_135 ;
if ( V_98 ) {
F_46 ( V_98 ) ;
F_52 ( V_98 ) ;
F_53 ( V_4 -> V_19 , & V_5 -> V_133 , 1 ,
V_134 ) ;
}
V_5 -> V_136 = NULL ;
V_5 -> V_135 = NULL ;
V_5 -> V_137 = - V_104 ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_71 = & V_5 -> V_72 ;
struct V_97 * V_98 = V_5 -> V_135 ;
struct V_138 V_91 ;
enum V_139 V_140 ;
T_3 V_141 , V_130 ;
F_21 ( V_4 , V_142 ) ;
V_140 = F_83 ( V_98 ,
V_5 -> V_137 ,
& V_91 ) ;
if ( V_140 == V_143 ) {
F_11 ( V_4 -> V_19 , L_10 ) ;
F_14 ( V_4 , V_56 ) ;
F_38 ( & V_5 -> V_89 ) ;
return;
}
V_141 = F_47 ( & V_5 -> V_133 ) - V_91 . V_144 ;
F_57 ( V_141 > F_47 ( & V_5 -> V_133 ) ) ;
if ( V_141 > V_71 -> V_75 ) {
V_130 = V_141 - V_71 -> V_75 ;
F_74 ( V_4 , V_71 -> V_78 + V_71 -> V_75 , V_130 ) ;
V_71 -> V_75 += V_130 ;
if ( V_71 -> V_75 == F_47 ( & V_5 -> V_133 ) )
V_71 -> V_75 = 0 ;
V_4 -> V_82 . V_145 += V_130 ;
}
F_14 ( V_4 , V_56 ) ;
}
static int F_84 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_106 * V_107 ;
T_2 V_115 ;
struct V_116 V_117 ;
struct V_70 * V_71 ;
int V_41 , V_118 ;
V_71 = & V_5 -> V_72 ;
F_63 ( V_115 ) ;
F_64 ( V_146 , V_115 ) ;
V_5 -> V_135 = F_65 ( V_4 -> V_19 , L_11 ) ;
if ( V_5 -> V_135 == NULL )
goto V_120;
F_66 ( V_4 -> V_19 , L_12 ,
F_67 ( V_5 -> V_135 ) ) ;
F_68 ( & V_5 -> V_147 ) ;
F_69 ( & V_5 -> V_133 , 1 ) ;
F_57 ( ( int ) V_4 -> V_91 -> V_90 . V_78 & ~ V_121 ) ;
F_70 ( & V_5 -> V_133 ,
F_71 ( V_71 -> V_78 ) ,
V_77 ,
( int ) V_71 -> V_78 & ~ V_121 ) ;
V_118 = F_72 ( V_4 -> V_19 ,
& V_5 -> V_133 ,
1 ,
V_134 ) ;
if ( ! V_118 ) {
F_11 ( V_4 -> V_19 , L_6 ) ;
goto V_120;
} else {
F_11 ( V_4 -> V_19 , L_7 , V_122 ,
F_47 ( & V_5 -> V_133 ) ,
V_71 -> V_78 ,
F_55 ( & V_5 -> V_133 ) ) ;
}
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_123 = V_134 ;
V_117 . V_148 = V_125 ;
V_117 . V_149 = V_4 -> V_127 + V_150 ;
V_41 = F_73 ( V_5 -> V_135 ,
V_129 ,
( unsigned long ) & V_117 ) ;
if ( V_41 ) {
F_59 ( V_4 -> V_19 , L_13 ) ;
goto V_120;
}
V_107 = F_85 ( V_5 -> V_135 ,
F_55 ( & V_5 -> V_133 ) ,
F_47 ( & V_5 -> V_133 ) ,
F_47 ( & V_5 -> V_133 ) / 2 ,
V_134 ,
V_111 ) ;
V_107 -> V_113 = F_80 ;
V_107 -> V_114 = V_4 ;
V_5 -> V_136 = V_107 ;
V_5 -> V_137 = F_61 ( V_107 ) ;
return 0 ;
V_120:
F_59 ( V_4 -> V_19 , L_14 ) ;
V_5 -> V_9 = 0 ;
if ( V_5 -> V_135 )
F_81 ( V_4 ) ;
return - V_104 ;
}
static void F_86 ( unsigned long V_151 )
{
struct V_2 * V_4 = ( void * ) V_151 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_38 ( & V_5 -> V_89 ) ;
F_87 ( & V_5 -> V_152 , V_153 + F_88 ( V_4 ) ) ;
}
static void
F_89 ( struct V_2 * V_4 , unsigned int V_141 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_141 & ( V_55 | V_56 ) ) {
F_9 ( V_4 , ( V_55
| V_56 ) ) ;
F_38 ( & V_5 -> V_89 ) ;
}
if ( V_141 & ( V_79 | V_86 |
V_81 | V_80 ) )
F_34 ( V_4 , V_141 ) ;
}
if ( F_6 ( V_4 ) ) {
if ( V_141 & V_56 ) {
F_9 ( V_4 , V_56 ) ;
F_38 ( & V_5 -> V_89 ) ;
}
}
if ( V_141 & V_59 )
F_35 ( V_4 ) ;
else if ( V_141 & V_79 ) {
F_21 ( V_4 , V_53 ) ;
F_9 ( V_4 , V_79 ) ;
V_5 -> V_88 = 0 ;
}
}
static void
F_90 ( struct V_2 * V_4 , unsigned int V_141 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_141 & V_5 -> V_15 ) {
F_9 ( V_4 , V_5 -> V_15 ) ;
F_38 ( & V_5 -> V_89 ) ;
}
}
static void
F_91 ( struct V_2 * V_4 , unsigned int V_141 ,
unsigned int V_40 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_141 & ( V_62 | V_63 | V_64
| V_65 ) ) {
V_5 -> V_154 = V_40 ;
F_38 ( & V_5 -> V_89 ) ;
}
}
static T_4 F_92 ( int V_155 , void * V_156 )
{
struct V_2 * V_4 = V_156 ;
unsigned int V_40 , V_141 , V_157 = 0 ;
do {
V_40 = F_17 ( V_4 ) ;
V_141 = V_40 & F_93 ( V_4 ) ;
if ( ! V_141 )
break;
F_89 ( V_4 , V_141 ) ;
F_91 ( V_4 , V_141 , V_40 ) ;
F_90 ( V_4 , V_141 ) ;
} while ( V_157 ++ < V_158 );
return V_157 ? V_159 : V_160 ;
}
static void F_94 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_161 * V_162 = & V_5 -> V_163 ;
F_95 ( V_4 -> V_19 ,
V_162 -> V_164 ,
V_162 -> V_165 ,
V_166 ) ;
}
static void F_96 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
struct V_161 * V_162 = & V_5 -> V_163 ;
int V_130 ;
if ( F_97 ( V_4 ) )
return;
V_90 -> V_76 += V_162 -> V_167 ;
V_90 -> V_76 &= V_94 - 1 ;
V_4 -> V_82 . V_93 += V_162 -> V_167 ;
V_162 -> V_167 = 0 ;
F_24 ( V_4 , V_50 ) ;
if ( ! F_41 ( V_90 ) && ! F_42 ( V_4 ) ) {
F_98 ( V_4 -> V_19 ,
V_162 -> V_164 ,
V_162 -> V_165 ,
V_166 ) ;
V_130 = F_56 ( V_90 -> V_75 , V_90 -> V_76 , V_94 ) ;
V_162 -> V_167 = V_130 ;
F_99 ( V_4 , V_162 -> V_164 + V_90 -> V_76 ) ;
F_100 ( V_4 , V_130 ) ;
F_24 ( V_4 , V_52 ) ;
F_14 ( V_4 , V_5 -> V_15 ) ;
} else {
if ( ( V_5 -> V_17 . V_13 & V_18 ) &&
! ( V_5 -> V_17 . V_13 & V_51 ) ) {
F_25 ( V_4 ) ;
}
}
if ( F_43 ( V_90 ) < V_95 )
F_44 ( V_4 ) ;
}
static int F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
V_162 -> V_78 = V_90 -> V_78 ;
V_162 -> V_164 = F_102 ( V_4 -> V_19 ,
V_162 -> V_78 ,
V_94 ,
V_166 ) ;
V_162 -> V_165 = V_94 ;
V_162 -> V_167 = 0 ;
return 0 ;
}
static void F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_71 = & V_5 -> V_72 ;
unsigned int V_168 ;
unsigned int V_40 ;
while ( V_71 -> V_75 != V_71 -> V_76 ) {
struct V_73 V_74 ;
F_104 () ;
V_74 = ( (struct V_73 * ) V_71 -> V_78 ) [ V_71 -> V_76 ] ;
V_71 -> V_76 = ( V_71 -> V_76 + 1 ) & ( V_77 - 1 ) ;
V_4 -> V_82 . V_145 ++ ;
V_40 = V_74 . V_40 ;
V_168 = V_169 ;
if ( F_37 ( V_40 & ( V_80 | V_81
| V_86 | V_79 ) ) ) {
if ( V_40 & V_79 ) {
V_40 &= ~ ( V_80 | V_81 ) ;
V_4 -> V_82 . V_83 ++ ;
if ( F_105 ( V_4 ) )
continue;
}
if ( V_40 & V_80 )
V_4 -> V_82 . V_84 ++ ;
if ( V_40 & V_81 )
V_4 -> V_82 . V_85 ++ ;
if ( V_40 & V_86 )
V_4 -> V_82 . V_87 ++ ;
V_40 &= V_4 -> V_57 ;
if ( V_40 & V_79 )
V_168 = V_170 ;
else if ( V_40 & V_80 )
V_168 = V_171 ;
else if ( V_40 & V_81 )
V_168 = V_172 ;
}
if ( F_106 ( V_4 , V_74 . V_69 ) )
continue;
F_107 ( V_4 , V_40 , V_86 , V_74 . V_69 , V_168 ) ;
}
F_77 ( & V_4 -> V_14 ) ;
F_78 ( & V_4 -> V_91 -> V_4 ) ;
F_79 ( & V_4 -> V_14 ) ;
}
static void F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_173 ;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
struct V_161 * V_162 = & V_5 -> V_174 [ V_173 ] ;
F_95 ( V_4 -> V_19 ,
V_162 -> V_164 ,
V_162 -> V_165 ,
V_175 ) ;
F_109 ( V_162 -> V_78 ) ;
}
}
static void F_110 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_131 * V_132 = & V_4 -> V_91 -> V_4 ;
struct V_161 * V_162 ;
int V_176 = V_5 -> V_177 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_130 ;
do {
F_21 ( V_4 , V_142 ) ;
V_162 = & V_5 -> V_174 [ V_176 ] ;
V_75 = F_111 ( V_4 ) - V_162 -> V_164 ;
V_76 = V_162 -> V_167 ;
V_75 = F_112 ( V_75 , V_162 -> V_165 ) ;
if ( F_113 ( V_75 != V_76 ) ) {
F_114 ( V_4 -> V_19 , V_162 -> V_164 ,
V_162 -> V_165 , V_175 ) ;
V_130 = V_75 - V_76 ;
F_76 ( V_132 , V_162 -> V_78 + V_162 -> V_167 ,
V_130 ) ;
F_98 ( V_4 -> V_19 , V_162 -> V_164 ,
V_162 -> V_165 , V_175 ) ;
V_4 -> V_82 . V_145 += V_130 ;
V_162 -> V_167 = V_75 ;
}
if ( V_75 >= V_162 -> V_165 ) {
V_162 -> V_167 = 0 ;
F_115 ( V_4 , V_162 -> V_164 ) ;
F_116 ( V_4 , V_162 -> V_165 ) ;
V_176 = ! V_176 ;
V_5 -> V_177 = V_176 ;
}
} while ( V_75 >= V_162 -> V_165 );
F_77 ( & V_4 -> V_14 ) ;
F_78 ( V_132 ) ;
F_79 ( & V_4 -> V_14 ) ;
F_14 ( V_4 , V_55 | V_56 ) ;
}
static int F_117 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_173 ;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
struct V_161 * V_162 = & V_5 -> V_174 [ V_173 ] ;
V_162 -> V_78 = F_118 ( V_178 , V_179 ) ;
if ( V_162 -> V_78 == NULL ) {
if ( V_173 != 0 ) {
F_95 ( V_4 -> V_19 ,
V_5 -> V_174 [ 0 ] . V_164 ,
V_178 ,
V_175 ) ;
F_109 ( V_5 -> V_174 [ 0 ] . V_78 ) ;
}
V_5 -> V_6 = 0 ;
return - V_180 ;
}
V_162 -> V_164 = F_102 ( V_4 -> V_19 ,
V_162 -> V_78 ,
V_178 ,
V_175 ) ;
V_162 -> V_165 = V_178 ;
V_162 -> V_167 = 0 ;
}
V_5 -> V_177 = 0 ;
F_119 ( V_4 , V_5 -> V_174 [ 0 ] . V_164 ) ;
F_120 ( V_4 , V_178 ) ;
F_115 ( V_4 , V_5 -> V_174 [ 1 ] . V_164 ) ;
F_116 ( V_4 , V_178 ) ;
return 0 ;
}
static void F_121 ( unsigned long V_151 )
{
struct V_2 * V_4 = (struct V_2 * ) V_151 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 ;
unsigned int V_181 ;
F_79 ( & V_4 -> V_14 ) ;
V_5 -> V_182 ( V_4 ) ;
V_40 = V_5 -> V_154 ;
V_181 = V_40 ^ V_5 -> V_183 ;
if ( V_181 & ( V_48 | V_46
| V_42 | V_44 ) ) {
if ( V_181 & V_48 )
V_4 -> V_82 . V_184 ++ ;
if ( V_181 & V_46 )
V_4 -> V_82 . V_185 ++ ;
if ( V_181 & V_42 )
F_122 ( V_4 , ! ( V_40 & V_42 ) ) ;
if ( V_181 & V_44 )
F_123 ( V_4 , ! ( V_40 & V_44 ) ) ;
F_124 ( & V_4 -> V_91 -> V_4 . V_186 ) ;
V_5 -> V_183 = V_40 ;
}
V_5 -> V_187 ( V_4 ) ;
F_77 ( & V_4 -> V_14 ) ;
}
static int F_125 ( struct V_1 * V_5 ,
struct V_188 * V_189 )
{
struct V_190 * V_191 = V_189 -> V_19 . V_192 ;
struct V_193 * V_194 = F_126 ( & V_189 -> V_19 ) ;
if ( V_191 ) {
if ( F_127 ( V_191 , L_15 , NULL ) ) {
if ( F_127 ( V_191 , L_16 , NULL ) ) {
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
if ( F_127 ( V_191 , L_17 , NULL ) ) {
if ( F_127 ( V_191 , L_16 , NULL ) ) {
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
V_5 -> V_6 = V_194 -> V_9 ;
V_5 -> V_7 = V_194 -> V_8 ;
V_5 -> V_9 = false ;
V_5 -> V_8 = false ;
}
return 0 ;
}
static void F_128 ( struct V_1 * V_5 ,
struct V_188 * V_189 )
{
struct V_190 * V_191 = V_189 -> V_19 . V_192 ;
struct V_193 * V_194 = F_126 ( & V_189 -> V_19 ) ;
if ( V_191 ) {
T_5 V_195 [ 2 ] ;
if ( F_129 ( V_191 , L_18 ,
V_195 , 2 ) == 0 ) {
struct V_10 * V_11 = & V_5 -> V_17 ;
V_11 -> V_196 = V_195 [ 0 ] ;
V_11 -> V_21 = V_195 [ 1 ] ;
V_11 -> V_13 = 0 ;
if ( F_127 ( V_191 , L_19 , NULL ) )
V_11 -> V_13 |= V_51 ;
if ( F_127 ( V_191 , L_20 ,
NULL ) )
V_11 -> V_13 |= V_18 ;
}
} else {
V_5 -> V_17 = V_194 -> V_17 ;
}
}
static void F_130 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_6 ( V_4 ) ) {
V_5 -> V_197 = & F_84 ;
V_5 -> V_187 = & F_82 ;
V_5 -> V_198 = & F_81 ;
} else if ( F_3 ( V_4 ) ) {
V_5 -> V_197 = & F_117 ;
V_5 -> V_187 = & F_110 ;
V_5 -> V_198 = & F_108 ;
} else {
V_5 -> V_197 = NULL ;
V_5 -> V_187 = & F_103 ;
V_5 -> V_198 = NULL ;
}
if ( F_5 ( V_4 ) ) {
V_5 -> V_199 = & F_62 ;
V_5 -> V_182 = & F_54 ;
V_5 -> V_200 = & F_51 ;
} else if ( F_4 ( V_4 ) ) {
V_5 -> V_199 = & F_101 ;
V_5 -> V_182 = & F_96 ;
V_5 -> V_200 = & F_94 ;
} else {
V_5 -> V_199 = NULL ;
V_5 -> V_182 = & F_39 ;
V_5 -> V_200 = NULL ;
}
}
static void F_131 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_201 = F_132 ( V_4 ) ;
T_5 V_202 ;
int V_203 , V_3 ;
V_203 = 0x55534152 ;
V_3 = 0x44424755 ;
V_5 -> V_204 = false ;
if ( V_201 == V_203 ) {
F_11 ( V_4 -> V_19 , L_21 ) ;
V_5 -> V_204 = true ;
} else if ( V_201 == V_3 ) {
F_11 ( V_4 -> V_19 , L_22 ) ;
V_5 -> V_204 = false ;
} else {
V_202 = F_133 ( V_4 ) ;
switch ( V_202 ) {
case 0x302 :
case 0x10213 :
F_11 ( V_4 -> V_19 , L_23 ) ;
V_5 -> V_204 = true ;
break;
case 0x203 :
case 0x10202 :
F_11 ( V_4 -> V_19 , L_24 ) ;
V_5 -> V_204 = false ;
break;
default:
F_59 ( V_4 -> V_19 , L_25 ) ;
}
}
}
static int F_134 ( struct V_2 * V_4 )
{
struct V_188 * V_189 = F_135 ( V_4 -> V_19 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_205 * V_206 = V_4 -> V_91 -> V_4 . V_206 ;
int V_207 ;
F_9 ( V_4 , - 1 ) ;
V_207 = F_136 ( V_4 -> V_155 , F_92 , V_208 ,
V_206 ? V_206 -> V_201 : L_26 , V_4 ) ;
if ( V_207 ) {
F_59 ( V_4 -> V_19 , L_27 ) ;
return V_207 ;
}
F_125 ( V_5 , V_189 ) ;
if ( V_5 -> V_197 ) {
V_207 = V_5 -> V_197 ( V_4 ) ;
if ( V_207 < 0 )
F_130 ( V_4 ) ;
}
if ( V_5 -> V_199 ) {
V_207 = V_5 -> V_199 ( V_4 ) ;
if ( V_207 < 0 )
F_130 ( V_4 ) ;
}
V_5 -> V_183 = F_17 ( V_4 ) ;
V_5 -> V_154 = V_5 -> V_183 ;
F_21 ( V_4 , V_53 | V_209 ) ;
F_21 ( V_4 , V_210 | V_54 ) ;
F_137 ( & V_5 -> V_152 ,
F_86 ,
( unsigned long ) V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( ! V_5 -> V_204 ) {
F_87 ( & V_5 -> V_152 ,
V_153 + F_88 ( V_4 ) ) ;
} else {
F_138 ( V_4 , V_211 ) ;
F_21 ( V_4 , V_142 ) ;
F_14 ( V_4 , V_55 | V_56 ) ;
}
F_24 ( V_4 , V_58 ) ;
} else if ( F_6 ( V_4 ) ) {
if ( ! V_5 -> V_204 ) {
F_87 ( & V_5 -> V_152 ,
V_153 + F_88 ( V_4 ) ) ;
} else {
F_138 ( V_4 , V_211 ) ;
F_21 ( V_4 , V_142 ) ;
F_14 ( V_4 , V_56 ) ;
}
} else {
F_14 ( V_4 , V_59 ) ;
}
return 0 ;
}
static void F_139 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_140 ( & V_5 -> V_152 ) ;
F_141 ( & V_5 -> V_89 ) ;
F_28 ( V_4 ) ;
F_23 ( V_4 ) ;
F_21 ( V_4 , V_53 ) ;
F_9 ( V_4 , - 1 ) ;
if ( V_5 -> V_198 )
V_5 -> V_198 ( V_4 ) ;
if ( V_5 -> V_200 )
V_5 -> V_200 ( V_4 ) ;
V_5 -> V_72 . V_75 = 0 ;
V_5 -> V_72 . V_76 = 0 ;
F_142 ( V_4 -> V_155 , V_4 ) ;
}
static void F_143 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_100 ( V_4 , 0 ) ;
V_5 -> V_163 . V_167 = 0 ;
}
}
static void F_144 ( struct V_2 * V_4 , unsigned int V_91 ,
unsigned int V_212 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_91 ) {
case 0 :
F_145 ( V_5 -> V_213 ) ;
F_14 ( V_4 , V_5 -> V_214 ) ;
break;
case 3 :
V_5 -> V_214 = F_93 ( V_4 ) ;
F_9 ( V_4 , - 1 ) ;
F_146 ( V_5 -> V_213 ) ;
break;
default:
F_59 ( V_4 -> V_19 , L_28 , V_91 ) ;
}
}
static void F_147 ( struct V_2 * V_4 , struct V_215 * V_216 ,
struct V_215 * V_217 )
{
unsigned long V_13 ;
unsigned int V_12 , V_218 , V_219 , V_220 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_12 = F_10 ( V_4 ) & ~ ( V_221 | V_222
| V_223 | V_224
| V_16 ) ;
V_220 = F_148 ( V_4 , V_216 , V_217 , 0 , V_4 -> V_225 / 16 ) ;
V_219 = F_149 ( V_4 , V_220 ) ;
if ( V_219 > 65535 ) {
V_219 /= 8 ;
V_12 |= V_226 ;
}
switch ( V_216 -> V_227 & V_228 ) {
case V_229 :
V_12 |= V_230 ;
break;
case V_231 :
V_12 |= V_232 ;
break;
case V_233 :
V_12 |= V_234 ;
break;
default:
V_12 |= V_235 ;
break;
}
if ( V_216 -> V_227 & V_236 )
V_12 |= V_237 ;
if ( V_216 -> V_227 & V_238 ) {
if ( V_216 -> V_227 & V_239 ) {
if ( V_216 -> V_227 & V_240 )
V_12 |= V_241 ;
else
V_12 |= V_242 ;
} else if ( V_216 -> V_227 & V_240 )
V_12 |= V_243 ;
else
V_12 |= V_244 ;
} else
V_12 |= V_245 ;
if ( V_216 -> V_227 & V_246 )
V_12 |= V_247 ;
else
V_12 |= V_248 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
V_4 -> V_57 = V_86 ;
if ( V_216 -> V_249 & V_250 )
V_4 -> V_57 |= ( V_81 | V_80 ) ;
if ( V_216 -> V_249 & ( V_251 | V_252 ) )
V_4 -> V_57 |= V_79 ;
if ( F_3 ( V_4 ) )
F_14 ( V_4 , V_4 -> V_57 ) ;
V_4 -> V_253 = 0 ;
if ( V_216 -> V_249 & V_254 )
V_4 -> V_253 |= ( V_81 | V_80 ) ;
if ( V_216 -> V_249 & V_255 ) {
V_4 -> V_253 |= V_79 ;
if ( V_216 -> V_249 & V_254 )
V_4 -> V_253 |= V_86 ;
}
F_150 ( V_4 , V_216 -> V_227 , V_220 ) ;
V_218 = F_93 ( V_4 ) ;
F_9 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_256 | V_60 ) ;
V_12 &= ~ V_16 ;
if ( V_5 -> V_17 . V_13 & V_18 ) {
if ( ( V_5 -> V_17 . V_21 ) > 0 )
F_12 ( V_4 ,
V_5 -> V_17 . V_21 ) ;
V_12 |= V_22 ;
}
F_13 ( V_4 , V_12 ) ;
F_151 ( V_4 , V_219 ) ;
F_21 ( V_4 , V_53 | V_209 ) ;
F_21 ( V_4 , V_210 | V_54 ) ;
F_14 ( V_4 , V_218 ) ;
if ( F_152 ( V_4 , V_216 -> V_227 ) )
V_4 -> V_257 -> V_258 ( V_4 ) ;
F_15 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_153 ( struct V_2 * V_4 , int V_259 )
{
if ( V_259 == V_260 ) {
V_4 -> V_13 |= V_261 ;
F_29 ( V_4 ) ;
} else {
V_4 -> V_13 &= ~ V_261 ;
}
}
static const char * F_154 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_262 ) ? L_29 : NULL ;
}
static void F_155 ( struct V_2 * V_4 )
{
struct V_188 * V_189 = F_135 ( V_4 -> V_19 ) ;
int V_263 = V_189 -> V_264 [ 0 ] . V_265 - V_189 -> V_264 [ 0 ] . V_266 + 1 ;
F_156 ( V_4 -> V_127 , V_263 ) ;
if ( V_4 -> V_13 & V_267 ) {
F_157 ( V_4 -> V_268 ) ;
V_4 -> V_268 = NULL ;
}
}
static int F_158 ( struct V_2 * V_4 )
{
struct V_188 * V_189 = F_135 ( V_4 -> V_19 ) ;
int V_263 = V_189 -> V_264 [ 0 ] . V_265 - V_189 -> V_264 [ 0 ] . V_266 + 1 ;
if ( ! F_159 ( V_4 -> V_127 , V_263 , L_26 ) )
return - V_269 ;
if ( V_4 -> V_13 & V_267 ) {
V_4 -> V_268 = F_160 ( V_4 -> V_127 , V_263 ) ;
if ( V_4 -> V_268 == NULL ) {
F_156 ( V_4 -> V_127 , V_263 ) ;
return - V_180 ;
}
}
return 0 ;
}
static void F_161 ( struct V_2 * V_4 , int V_13 )
{
if ( V_13 & V_270 ) {
V_4 -> type = V_262 ;
F_158 ( V_4 ) ;
}
}
static int F_162 ( struct V_2 * V_4 , struct V_271 * V_272 )
{
int V_41 = 0 ;
if ( V_272 -> type != V_273 && V_272 -> type != V_262 )
V_41 = - V_104 ;
if ( V_4 -> V_155 != V_272 -> V_155 )
V_41 = - V_104 ;
if ( V_272 -> V_274 != V_275 )
V_41 = - V_104 ;
if ( V_4 -> V_225 / 16 != V_272 -> V_276 )
V_41 = - V_104 ;
if ( ( void * ) V_4 -> V_127 != V_272 -> V_277 )
V_41 = - V_104 ;
if ( V_4 -> V_278 != V_272 -> V_4 )
V_41 = - V_104 ;
if ( V_272 -> V_279 != 0 )
V_41 = - V_104 ;
return V_41 ;
}
static int F_163 ( struct V_2 * V_4 )
{
while ( ! ( F_17 ( V_4 ) & V_59 ) )
F_164 () ;
return F_36 ( V_4 ) ;
}
static void F_165 ( struct V_2 * V_4 , unsigned char V_69 )
{
while ( ! ( F_17 ( V_4 ) & V_25 ) )
F_164 () ;
F_40 ( V_4 , V_69 ) ;
}
static int
F_166 ( struct V_2 * V_4 , unsigned int V_280 , unsigned long V_96 )
{
struct V_10 V_11 ;
switch ( V_280 ) {
case V_281 :
if ( F_167 ( & V_11 , (struct V_10 * ) V_96 ,
sizeof( V_11 ) ) )
return - V_282 ;
F_7 ( V_4 , & V_11 ) ;
break;
case V_283 :
if ( F_168 ( (struct V_10 * ) V_96 ,
& ( F_1 ( V_4 ) -> V_17 ) ,
sizeof( V_11 ) ) )
return - V_282 ;
break;
default:
return - V_284 ;
}
return 0 ;
}
static int F_169 ( struct V_1 * V_5 ,
struct V_188 * V_189 )
{
int V_41 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_193 * V_194 = F_126 ( & V_189 -> V_19 ) ;
if ( ! F_125 ( V_5 , V_189 ) )
F_130 ( V_4 ) ;
F_128 ( V_5 , V_189 ) ;
V_4 -> V_285 = V_286 ;
V_4 -> V_13 = V_287 ;
V_4 -> V_257 = & V_288 ;
V_4 -> V_289 = 1 ;
V_4 -> V_19 = & V_189 -> V_19 ;
V_4 -> V_127 = V_189 -> V_264 [ 0 ] . V_266 ;
V_4 -> V_155 = V_189 -> V_264 [ 1 ] . V_266 ;
F_170 ( & V_5 -> V_89 , F_121 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_72 , 0 , sizeof( V_5 -> V_72 ) ) ;
if ( V_194 && V_194 -> V_290 ) {
V_4 -> V_268 = V_194 -> V_290 ;
} else {
V_4 -> V_13 |= V_267 ;
V_4 -> V_268 = NULL ;
}
if ( ! V_5 -> V_213 ) {
V_5 -> V_213 = F_171 ( & V_189 -> V_19 , L_30 ) ;
if ( F_172 ( V_5 -> V_213 ) ) {
V_41 = F_173 ( V_5 -> V_213 ) ;
V_5 -> V_213 = NULL ;
return V_41 ;
}
V_41 = F_145 ( V_5 -> V_213 ) ;
if ( V_41 ) {
F_174 ( V_5 -> V_213 ) ;
V_5 -> V_213 = NULL ;
return V_41 ;
}
V_4 -> V_225 = F_175 ( V_5 -> V_213 ) ;
F_146 ( V_5 -> V_213 ) ;
}
if ( V_5 -> V_17 . V_13 & V_18 )
V_5 -> V_15 = V_20 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_289 = V_178 ;
V_5 -> V_15 = V_23 | V_24 ;
} else {
V_5 -> V_15 = V_25 ;
}
return 0 ;
}
static void F_176 ( struct V_2 * V_4 , int V_69 )
{
while ( ! ( F_17 ( V_4 ) & V_25 ) )
F_164 () ;
F_40 ( V_4 , V_69 ) ;
}
static void F_177 ( struct V_291 * V_292 , const char * V_293 , T_1 V_130 )
{
struct V_2 * V_4 = & V_294 [ V_292 -> V_295 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 , V_218 ;
unsigned int V_163 ;
V_218 = F_93 ( V_4 ) ;
F_9 ( V_4 , V_59 | V_5 -> V_15 ) ;
V_163 = F_27 ( V_4 ) & V_52 ;
F_24 ( V_4 , V_50 ) ;
F_178 ( V_4 , V_293 , V_130 , F_176 ) ;
do {
V_40 = F_17 ( V_4 ) ;
} while ( ! ( V_40 & V_25 ) );
if ( V_163 )
F_24 ( V_4 , V_52 ) ;
F_14 ( V_4 , V_218 ) ;
}
static void T_6 F_179 ( struct V_2 * V_4 , int * V_220 ,
int * V_84 , int * V_296 )
{
unsigned int V_297 , V_219 ;
V_219 = F_180 ( V_4 ) & V_298 ;
if ( ! V_219 )
return;
V_297 = F_10 ( V_4 ) & V_222 ;
if ( V_297 == V_235 )
* V_296 = 8 ;
else
* V_296 = 7 ;
V_297 = F_10 ( V_4 ) & V_224 ;
if ( V_297 == V_244 )
* V_84 = 'e' ;
else if ( V_297 == V_243 )
* V_84 = 'o' ;
* V_220 = V_4 -> V_225 / ( 16 * ( V_219 - 1 ) ) ;
}
static int T_6 F_181 ( struct V_291 * V_292 , char * V_299 )
{
int V_41 ;
struct V_2 * V_4 = & V_294 [ V_292 -> V_295 ] . V_3 ;
int V_220 = 115200 ;
int V_296 = 8 ;
int V_84 = 'n' ;
int V_300 = 'n' ;
if ( V_4 -> V_268 == NULL ) {
return - V_301 ;
}
V_41 = F_145 ( V_294 [ V_292 -> V_295 ] . V_213 ) ;
if ( V_41 )
return V_41 ;
F_9 ( V_4 , - 1 ) ;
F_21 ( V_4 , V_53 | V_209 ) ;
F_21 ( V_4 , V_210 | V_54 ) ;
if ( V_299 )
F_182 ( V_299 , & V_220 , & V_84 , & V_296 , & V_300 ) ;
else
F_179 ( V_4 , & V_220 , & V_84 , & V_296 ) ;
return F_183 ( V_4 , V_292 , V_220 , V_84 , V_296 , V_300 ) ;
}
static int T_6 F_184 ( void )
{
int V_41 ;
if ( V_302 ) {
struct V_193 * V_194 =
F_126 ( & V_302 -> V_19 ) ;
int V_303 = V_194 -> V_304 ;
struct V_1 * V_4 = & V_294 [ V_303 ] ;
V_4 -> V_214 = 0 ;
V_4 -> V_3 . line = V_303 ;
F_185 ( V_305 , V_303 , NULL ) ;
V_41 = F_169 ( V_4 , V_302 ) ;
if ( V_41 )
return V_41 ;
F_186 ( & V_306 ) ;
}
return 0 ;
}
static int T_6 F_187 ( void )
{
if ( V_302
&& ! ( V_306 . V_13 & V_307 ) )
F_186 ( & V_306 ) ;
return 0 ;
}
static inline bool F_188 ( struct V_2 * V_4 )
{
return V_4 -> V_308 && V_4 -> V_308 -> V_295 == V_4 -> line ;
}
static inline bool F_188 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_189 ( void )
{
#ifdef F_190
return F_191 () ;
#else
return false ;
#endif
}
static int F_192 ( struct V_188 * V_189 ,
T_7 V_91 )
{
struct V_2 * V_4 = F_193 ( V_189 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_188 ( V_4 ) && V_309 ) {
while ( ! ( F_17 ( V_4 ) & V_20 ) )
F_164 () ;
}
V_5 -> V_310 = F_194 ( & V_189 -> V_19 ) ;
if ( F_189 () )
F_195 ( & V_189 -> V_19 , 0 ) ;
F_196 ( & V_311 , V_4 ) ;
return 0 ;
}
static int F_197 ( struct V_188 * V_189 )
{
struct V_2 * V_4 = F_193 ( V_189 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_198 ( & V_311 , V_4 ) ;
F_195 ( & V_189 -> V_19 , V_5 -> V_310 ) ;
return 0 ;
}
static int F_199 ( struct V_188 * V_189 )
{
struct V_1 * V_4 ;
struct V_190 * V_191 = V_189 -> V_19 . V_192 ;
struct V_193 * V_194 = F_126 ( & V_189 -> V_19 ) ;
void * V_151 ;
int V_41 = - V_301 ;
F_200 ( V_77 & ( V_77 - 1 ) ) ;
if ( V_191 )
V_41 = F_201 ( V_191 , L_31 ) ;
else
if ( V_194 )
V_41 = V_194 -> V_304 ;
if ( V_41 < 0 )
V_41 = F_202 ( V_312 , V_313 ) ;
if ( V_41 >= V_313 ) {
V_41 = - V_301 ;
goto V_314;
}
if ( F_203 ( V_41 , V_312 ) ) {
V_41 = - V_269 ;
goto V_314;
}
V_4 = & V_294 [ V_41 ] ;
V_4 -> V_214 = 0 ;
V_4 -> V_3 . line = V_41 ;
V_4 -> V_29 = - V_104 ;
if ( V_194 )
V_4 -> V_29 = V_194 -> V_29 ;
else if ( V_191 )
V_4 -> V_29 = F_204 ( V_191 , L_32 , 0 ) ;
if ( F_19 ( V_4 -> V_29 ) ) {
V_41 = F_205 ( & V_189 -> V_19 , V_4 -> V_29 , L_33 ) ;
if ( V_41 ) {
F_59 ( & V_189 -> V_19 , L_34 ) ;
goto V_314;
}
V_41 = F_206 ( V_4 -> V_29 , 1 ) ;
if ( V_41 ) {
F_59 ( & V_189 -> V_19 , L_35 ) ;
goto V_314;
}
}
V_41 = F_169 ( V_4 , V_189 ) ;
if ( V_41 )
goto V_314;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_41 = - V_180 ;
V_151 = F_118 ( sizeof( struct V_73 )
* V_77 , V_179 ) ;
if ( ! V_151 )
goto V_315;
V_4 -> V_72 . V_78 = V_151 ;
}
V_41 = F_207 ( & V_311 , & V_4 -> V_3 ) ;
if ( V_41 )
goto V_316;
#ifdef F_208
if ( F_188 ( & V_4 -> V_3 )
&& V_317 -> V_13 & V_307 ) {
F_146 ( V_4 -> V_213 ) ;
}
#endif
F_209 ( & V_189 -> V_19 , 1 ) ;
F_210 ( V_189 , V_4 ) ;
if ( V_4 -> V_17 . V_13 & V_18 ) {
F_13 ( & V_4 -> V_3 , V_248 ) ;
F_21 ( & V_4 -> V_3 , V_31 ) ;
}
F_131 ( & V_4 -> V_3 ) ;
return 0 ;
V_316:
F_109 ( V_4 -> V_72 . V_78 ) ;
V_4 -> V_72 . V_78 = NULL ;
V_315:
if ( ! F_188 ( & V_4 -> V_3 ) ) {
F_174 ( V_4 -> V_213 ) ;
V_4 -> V_213 = NULL ;
}
V_314:
return V_41 ;
}
static int F_211 ( struct V_188 * V_189 )
{
struct V_2 * V_4 = F_193 ( V_189 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_41 = 0 ;
F_141 ( & V_5 -> V_89 ) ;
F_209 ( & V_189 -> V_19 , 0 ) ;
V_41 = F_212 ( & V_311 , V_4 ) ;
F_109 ( V_5 -> V_72 . V_78 ) ;
F_213 ( V_4 -> line , V_312 ) ;
F_174 ( V_5 -> V_213 ) ;
return V_41 ;
}
static int T_6 F_214 ( void )
{
int V_41 ;
V_41 = F_215 ( & V_311 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_216 ( & V_318 ) ;
if ( V_41 )
F_217 ( & V_311 ) ;
return V_41 ;
}
static void T_8 F_218 ( void )
{
F_219 ( & V_318 ) ;
F_217 ( & V_311 ) ;
}
