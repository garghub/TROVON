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
#ifdef F_19
if ( F_20 () ) {
if ( V_4 -> V_29 == V_30 ) {
if ( V_27 & V_31 )
F_21 ( V_32 , 0 ) ;
else
F_21 ( V_32 , 1 ) ;
}
}
#endif
if ( V_27 & V_31 )
V_28 |= V_33 ;
else
V_28 |= V_34 ;
if ( V_27 & V_35 )
V_28 |= V_36 ;
else
V_28 |= V_37 ;
F_22 ( V_4 , V_28 ) ;
V_12 = F_10 ( V_4 ) & ~ V_38 ;
if ( V_27 & V_39 )
V_12 |= V_40 ;
else
V_12 |= V_41 ;
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
static T_1 F_23 ( struct V_2 * V_4 )
{
unsigned int V_42 , V_43 = 0 ;
V_42 = F_17 ( V_4 ) ;
if ( ! ( V_42 & V_44 ) )
V_43 |= V_45 ;
if ( ! ( V_42 & V_46 ) )
V_43 |= V_47 ;
if ( ! ( V_42 & V_48 ) )
V_43 |= V_49 ;
if ( ! ( V_42 & V_50 ) )
V_43 |= V_51 ;
return V_43 ;
}
static void F_24 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_25 ( V_4 , V_52 ) ;
}
F_9 ( V_4 , V_5 -> V_15 ) ;
if ( ( V_5 -> V_17 . V_13 & V_18 ) &&
! ( V_5 -> V_17 . V_13 & V_53 ) )
F_26 ( V_4 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
if ( F_28 ( V_4 ) & V_54 )
return;
if ( ( V_5 -> V_17 . V_13 & V_18 ) &&
! ( V_5 -> V_17 . V_13 & V_53 ) )
F_29 ( V_4 ) ;
F_25 ( V_4 , V_54 ) ;
}
F_14 ( V_4 , V_5 -> V_15 ) ;
}
static void F_26 ( struct V_2 * V_4 )
{
F_22 ( V_4 , V_55 ) ;
F_22 ( V_4 , V_56 ) ;
if ( F_3 ( V_4 ) ) {
F_14 ( V_4 , V_57 | V_58 |
V_4 -> V_59 ) ;
F_25 ( V_4 , V_60 ) ;
} else {
F_14 ( V_4 , V_61 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
F_22 ( V_4 , V_62 ) ;
if ( F_3 ( V_4 ) ) {
F_25 ( V_4 , V_63 ) ;
F_9 ( V_4 , V_57 | V_58 |
V_4 -> V_59 ) ;
} else {
F_9 ( V_4 , V_61 ) ;
}
}
static void F_30 ( struct V_2 * V_4 )
{
F_14 ( V_4 , V_64 | V_65
| V_66 | V_67 ) ;
}
static void F_31 ( struct V_2 * V_4 , int V_68 )
{
if ( V_68 != 0 )
F_22 ( V_4 , V_69 ) ;
else
F_22 ( V_4 , V_70 ) ;
}
static void
F_32 ( struct V_2 * V_4 , unsigned int V_42 ,
unsigned int V_71 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_72 * V_73 = & V_5 -> V_74 ;
struct V_75 * V_76 ;
if ( ! F_33 ( V_73 -> V_77 , V_73 -> V_78 , V_79 ) )
return;
V_76 = & ( (struct V_75 * ) V_73 -> V_80 ) [ V_73 -> V_77 ] ;
V_76 -> V_42 = V_42 ;
V_76 -> V_71 = V_71 ;
F_34 () ;
V_73 -> V_77 = ( V_73 -> V_77 + 1 ) & ( V_79 - 1 ) ;
}
static void F_35 ( struct V_2 * V_4 , unsigned int V_42 )
{
F_22 ( V_4 , V_55 ) ;
if ( V_42 & V_81 ) {
V_42 &= ~ ( V_82 | V_83 ) ;
V_4 -> V_84 . V_85 ++ ;
}
if ( V_42 & V_82 )
V_4 -> V_84 . V_86 ++ ;
if ( V_42 & V_83 )
V_4 -> V_84 . V_87 ++ ;
if ( V_42 & V_88 )
V_4 -> V_84 . V_89 ++ ;
}
static void F_36 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_42 , V_71 ;
V_42 = F_17 ( V_4 ) ;
while ( V_42 & V_61 ) {
V_71 = F_37 ( V_4 ) ;
if ( F_38 ( V_42 & ( V_82 | V_83
| V_88 | V_81 )
|| V_5 -> V_90 ) ) {
F_22 ( V_4 , V_55 ) ;
if ( V_42 & V_81
&& ! V_5 -> V_90 ) {
V_5 -> V_90 = 1 ;
F_14 ( V_4 , V_81 ) ;
} else {
F_9 ( V_4 , V_81 ) ;
V_42 &= ~ V_81 ;
V_5 -> V_90 = 0 ;
}
}
F_32 ( V_4 , V_42 , V_71 ) ;
V_42 = F_17 ( V_4 ) ;
}
F_39 ( & V_5 -> V_91 ) ;
}
static void F_40 ( struct V_2 * V_4 )
{
struct V_72 * V_92 = & V_4 -> V_93 -> V_92 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_94 && F_17 ( V_4 ) & V_5 -> V_15 ) {
F_41 ( V_4 , V_4 -> V_94 ) ;
V_4 -> V_84 . V_95 ++ ;
V_4 -> V_94 = 0 ;
}
if ( F_42 ( V_92 ) || F_43 ( V_4 ) )
return;
while ( F_17 ( V_4 ) & V_5 -> V_15 ) {
F_41 ( V_4 , V_92 -> V_80 [ V_92 -> V_78 ] ) ;
V_92 -> V_78 = ( V_92 -> V_78 + 1 ) & ( V_96 - 1 ) ;
V_4 -> V_84 . V_95 ++ ;
if ( F_42 ( V_92 ) )
break;
}
if ( F_44 ( V_92 ) < V_97 )
F_45 ( V_4 ) ;
if ( ! F_42 ( V_92 ) )
F_14 ( V_4 , V_5 -> V_15 ) ;
}
static void F_46 ( void * V_98 )
{
struct V_1 * V_5 = V_98 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_72 * V_92 = & V_4 -> V_93 -> V_92 ;
struct V_99 * V_100 = V_5 -> V_101 ;
unsigned long V_13 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
if ( V_100 )
F_47 ( V_100 ) ;
V_92 -> V_78 += F_48 ( & V_5 -> V_102 ) ;
V_92 -> V_78 &= V_96 - 1 ;
V_4 -> V_84 . V_95 += F_48 ( & V_5 -> V_102 ) ;
F_49 ( & V_5 -> V_103 ) ;
F_50 ( V_5 -> V_104 ) ;
V_5 -> V_105 = - V_106 ;
V_5 -> V_104 = NULL ;
F_51 ( & V_5 -> V_103 ) ;
if ( F_44 ( V_92 ) < V_97 )
F_45 ( V_4 ) ;
if ( ! F_42 ( V_92 ) )
F_39 ( & V_5 -> V_91 ) ;
F_15 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_52 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_99 * V_100 = V_5 -> V_101 ;
if ( V_100 ) {
F_47 ( V_100 ) ;
F_53 ( V_100 ) ;
F_54 ( V_4 -> V_19 , & V_5 -> V_102 , 1 ,
V_107 ) ;
}
V_5 -> V_104 = NULL ;
V_5 -> V_101 = NULL ;
V_5 -> V_105 = - V_106 ;
}
static void F_55 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_72 * V_92 = & V_4 -> V_93 -> V_92 ;
struct V_99 * V_100 = V_5 -> V_101 ;
struct V_108 * V_109 ;
struct V_110 * V_111 = & V_5 -> V_102 ;
if ( V_5 -> V_104 != NULL )
return;
if ( ! F_42 ( V_92 ) && ! F_43 ( V_4 ) ) {
V_111 -> V_112 = V_92 -> V_78 & ( V_96 - 1 ) ;
F_56 ( V_111 ) = ( F_56 ( V_111 ) &
~ ( V_96 - 1 ) )
+ V_111 -> V_112 ;
F_48 ( V_111 ) = F_57 ( V_92 -> V_77 ,
V_92 -> V_78 ,
V_96 ) ;
F_58 ( ! F_48 ( V_111 ) ) ;
V_109 = F_59 ( V_100 ,
V_111 ,
1 ,
V_107 ,
V_113 |
V_114 ) ;
if ( ! V_109 ) {
F_60 ( V_4 -> V_19 , L_3 ) ;
return;
}
F_61 ( V_4 -> V_19 , V_111 , 1 , V_107 ) ;
V_5 -> V_104 = V_109 ;
V_109 -> V_115 = F_46 ;
V_109 -> V_116 = V_5 ;
V_5 -> V_105 = F_62 ( V_109 ) ;
} else {
if ( V_5 -> V_17 . V_13 & V_18 ) {
F_26 ( V_4 ) ;
}
}
if ( F_44 ( V_92 ) < V_97 )
F_45 ( V_4 ) ;
}
static int F_63 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_2 V_117 ;
struct V_118 V_119 ;
int V_43 , V_120 ;
F_64 ( V_117 ) ;
F_65 ( V_121 , V_117 ) ;
V_5 -> V_101 = F_66 ( V_4 -> V_19 , L_4 ) ;
if ( V_5 -> V_101 == NULL )
goto V_122;
F_67 ( V_4 -> V_19 , L_5 ,
F_68 ( V_5 -> V_101 ) ) ;
F_69 ( & V_5 -> V_103 ) ;
F_70 ( & V_5 -> V_102 , 1 ) ;
F_58 ( ( int ) V_4 -> V_93 -> V_92 . V_80 & ~ V_123 ) ;
F_71 ( & V_5 -> V_102 ,
F_72 ( V_4 -> V_93 -> V_92 . V_80 ) ,
V_96 ,
( int ) V_4 -> V_93 -> V_92 . V_80 & ~ V_123 ) ;
V_120 = F_73 ( V_4 -> V_19 ,
& V_5 -> V_102 ,
1 ,
V_107 ) ;
if ( ! V_120 ) {
F_11 ( V_4 -> V_19 , L_6 ) ;
goto V_122;
} else {
F_11 ( V_4 -> V_19 , L_7 , V_124 ,
F_48 ( & V_5 -> V_102 ) ,
V_4 -> V_93 -> V_92 . V_80 ,
F_56 ( & V_5 -> V_102 ) ) ;
}
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_125 = V_107 ;
V_119 . V_126 = V_127 ;
V_119 . V_128 = V_4 -> V_29 + V_129 ;
V_43 = F_74 ( V_5 -> V_101 ,
V_130 ,
( unsigned long ) & V_119 ) ;
if ( V_43 ) {
F_60 ( V_4 -> V_19 , L_8 ) ;
goto V_122;
}
return 0 ;
V_122:
F_60 ( V_4 -> V_19 , L_9 ) ;
V_5 -> V_8 = 0 ;
if ( V_5 -> V_101 )
F_52 ( V_4 ) ;
return - V_106 ;
}
static void F_75 ( struct V_2 * V_4 ,
char * V_80 , T_3 V_131 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_132 * V_133 = & V_4 -> V_93 -> V_4 ;
F_76 ( V_4 -> V_19 ,
& V_5 -> V_134 ,
1 ,
V_135 ) ;
F_77 ( V_133 , V_80 , V_131 ) ;
F_61 ( V_4 -> V_19 ,
& V_5 -> V_134 ,
1 ,
V_135 ) ;
F_78 ( & V_4 -> V_14 ) ;
F_79 ( V_133 ) ;
F_80 ( & V_4 -> V_14 ) ;
}
static void F_81 ( void * V_98 )
{
struct V_2 * V_4 = V_98 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_39 ( & V_5 -> V_91 ) ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_99 * V_100 = V_5 -> V_136 ;
if ( V_100 ) {
F_47 ( V_100 ) ;
F_53 ( V_100 ) ;
F_54 ( V_4 -> V_19 , & V_5 -> V_134 , 1 ,
V_135 ) ;
}
V_5 -> V_137 = NULL ;
V_5 -> V_136 = NULL ;
V_5 -> V_138 = - V_106 ;
if ( ! V_5 -> V_139 )
F_83 ( & V_5 -> V_140 ) ;
}
static void F_84 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_72 * V_73 = & V_5 -> V_74 ;
struct V_99 * V_100 = V_5 -> V_136 ;
struct V_141 V_93 ;
enum V_142 V_143 ;
T_3 V_144 , V_131 ;
F_22 ( V_4 , V_145 ) ;
V_143 = F_85 ( V_100 ,
V_5 -> V_138 ,
& V_93 ) ;
if ( V_143 == V_146 ) {
F_11 ( V_4 -> V_19 , L_10 ) ;
F_14 ( V_4 , V_58 ) ;
F_39 ( & V_5 -> V_91 ) ;
return;
}
V_144 = F_48 ( & V_5 -> V_134 ) - V_93 . V_147 ;
F_58 ( V_144 > F_48 ( & V_5 -> V_134 ) ) ;
if ( V_144 > V_73 -> V_77 ) {
V_131 = V_144 - V_73 -> V_77 ;
F_75 ( V_4 , V_73 -> V_80 + V_73 -> V_77 , V_131 ) ;
V_73 -> V_77 += V_131 ;
if ( V_73 -> V_77 == F_48 ( & V_5 -> V_134 ) )
V_73 -> V_77 = 0 ;
V_4 -> V_84 . V_148 += V_131 ;
}
F_14 ( V_4 , V_58 ) ;
}
static int F_86 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_108 * V_109 ;
T_2 V_117 ;
struct V_118 V_119 ;
struct V_72 * V_73 ;
int V_43 , V_120 ;
V_73 = & V_5 -> V_74 ;
F_64 ( V_117 ) ;
F_65 ( V_149 , V_117 ) ;
V_5 -> V_136 = F_66 ( V_4 -> V_19 , L_11 ) ;
if ( V_5 -> V_136 == NULL )
goto V_122;
F_67 ( V_4 -> V_19 , L_12 ,
F_68 ( V_5 -> V_136 ) ) ;
F_69 ( & V_5 -> V_150 ) ;
F_70 ( & V_5 -> V_134 , 1 ) ;
F_58 ( ( int ) V_4 -> V_93 -> V_92 . V_80 & ~ V_123 ) ;
F_71 ( & V_5 -> V_134 ,
F_72 ( V_73 -> V_80 ) ,
V_79 ,
( int ) V_73 -> V_80 & ~ V_123 ) ;
V_120 = F_73 ( V_4 -> V_19 ,
& V_5 -> V_134 ,
1 ,
V_135 ) ;
if ( ! V_120 ) {
F_11 ( V_4 -> V_19 , L_6 ) ;
goto V_122;
} else {
F_11 ( V_4 -> V_19 , L_7 , V_124 ,
F_48 ( & V_5 -> V_134 ) ,
V_73 -> V_80 ,
F_56 ( & V_5 -> V_134 ) ) ;
}
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_125 = V_135 ;
V_119 . V_151 = V_127 ;
V_119 . V_152 = V_4 -> V_29 + V_153 ;
V_43 = F_74 ( V_5 -> V_136 ,
V_130 ,
( unsigned long ) & V_119 ) ;
if ( V_43 ) {
F_60 ( V_4 -> V_19 , L_13 ) ;
goto V_122;
}
V_109 = F_87 ( V_5 -> V_136 ,
F_56 ( & V_5 -> V_134 ) ,
F_48 ( & V_5 -> V_134 ) ,
F_48 ( & V_5 -> V_134 ) / 2 ,
V_135 ,
V_113 ) ;
V_109 -> V_115 = F_81 ;
V_109 -> V_116 = V_4 ;
V_5 -> V_137 = V_109 ;
V_5 -> V_138 = F_62 ( V_109 ) ;
return 0 ;
V_122:
F_60 ( V_4 -> V_19 , L_14 ) ;
V_5 -> V_9 = 0 ;
if ( V_5 -> V_136 )
F_82 ( V_4 ) ;
return - V_106 ;
}
static void F_88 ( unsigned long V_154 )
{
struct V_2 * V_4 = ( void * ) V_154 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_39 ( & V_5 -> V_91 ) ;
F_89 ( & V_5 -> V_140 , V_155 + F_90 ( V_4 ) ) ;
}
static void
F_91 ( struct V_2 * V_4 , unsigned int V_144 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_144 & ( V_57 | V_58 ) ) {
F_9 ( V_4 , ( V_57
| V_58 ) ) ;
F_39 ( & V_5 -> V_91 ) ;
}
if ( V_144 & ( V_81 | V_88 |
V_83 | V_82 ) )
F_35 ( V_4 , V_144 ) ;
}
if ( F_6 ( V_4 ) ) {
if ( V_144 & V_58 ) {
F_9 ( V_4 , V_58 ) ;
F_39 ( & V_5 -> V_91 ) ;
}
}
if ( V_144 & V_61 )
F_36 ( V_4 ) ;
else if ( V_144 & V_81 ) {
F_22 ( V_4 , V_55 ) ;
F_9 ( V_4 , V_81 ) ;
V_5 -> V_90 = 0 ;
}
}
static void
F_92 ( struct V_2 * V_4 , unsigned int V_144 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_144 & V_5 -> V_15 ) {
F_9 ( V_4 , V_5 -> V_15 ) ;
F_39 ( & V_5 -> V_91 ) ;
}
}
static void
F_93 ( struct V_2 * V_4 , unsigned int V_144 ,
unsigned int V_42 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_144 & ( V_64 | V_65 | V_66
| V_67 ) ) {
V_5 -> V_156 = V_42 ;
F_39 ( & V_5 -> V_91 ) ;
}
}
static T_4 F_94 ( int V_157 , void * V_158 )
{
struct V_2 * V_4 = V_158 ;
unsigned int V_42 , V_144 , V_159 = 0 ;
do {
V_42 = F_17 ( V_4 ) ;
V_144 = V_42 & F_95 ( V_4 ) ;
if ( ! V_144 )
break;
F_91 ( V_4 , V_144 ) ;
F_93 ( V_4 , V_144 , V_42 ) ;
F_92 ( V_4 , V_144 ) ;
} while ( V_159 ++ < V_160 );
return V_159 ? V_161 : V_162 ;
}
static void F_96 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_163 * V_164 = & V_5 -> V_165 ;
F_97 ( V_4 -> V_19 ,
V_164 -> V_166 ,
V_164 -> V_167 ,
V_168 ) ;
}
static void F_98 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_72 * V_92 = & V_4 -> V_93 -> V_92 ;
struct V_163 * V_164 = & V_5 -> V_165 ;
int V_131 ;
if ( F_99 ( V_4 ) )
return;
V_92 -> V_78 += V_164 -> V_169 ;
V_92 -> V_78 &= V_96 - 1 ;
V_4 -> V_84 . V_95 += V_164 -> V_169 ;
V_164 -> V_169 = 0 ;
F_25 ( V_4 , V_52 ) ;
if ( ! F_42 ( V_92 ) && ! F_43 ( V_4 ) ) {
F_100 ( V_4 -> V_19 ,
V_164 -> V_166 ,
V_164 -> V_167 ,
V_168 ) ;
V_131 = F_57 ( V_92 -> V_77 , V_92 -> V_78 , V_96 ) ;
V_164 -> V_169 = V_131 ;
F_101 ( V_4 , V_164 -> V_166 + V_92 -> V_78 ) ;
F_102 ( V_4 , V_131 ) ;
F_25 ( V_4 , V_54 ) ;
F_14 ( V_4 , V_5 -> V_15 ) ;
} else {
if ( ( V_5 -> V_17 . V_13 & V_18 ) &&
! ( V_5 -> V_17 . V_13 & V_53 ) ) {
F_26 ( V_4 ) ;
}
}
if ( F_44 ( V_92 ) < V_97 )
F_45 ( V_4 ) ;
}
static int F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_163 * V_164 = & V_5 -> V_165 ;
struct V_72 * V_92 = & V_4 -> V_93 -> V_92 ;
V_164 -> V_80 = V_92 -> V_80 ;
V_164 -> V_166 = F_104 ( V_4 -> V_19 ,
V_164 -> V_80 ,
V_96 ,
V_168 ) ;
V_164 -> V_167 = V_96 ;
V_164 -> V_169 = 0 ;
return 0 ;
}
static void F_105 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_72 * V_73 = & V_5 -> V_74 ;
unsigned int V_170 ;
unsigned int V_42 ;
while ( V_73 -> V_77 != V_73 -> V_78 ) {
struct V_75 V_76 ;
F_106 () ;
V_76 = ( (struct V_75 * ) V_73 -> V_80 ) [ V_73 -> V_78 ] ;
V_73 -> V_78 = ( V_73 -> V_78 + 1 ) & ( V_79 - 1 ) ;
V_4 -> V_84 . V_148 ++ ;
V_42 = V_76 . V_42 ;
V_170 = V_171 ;
if ( F_38 ( V_42 & ( V_82 | V_83
| V_88 | V_81 ) ) ) {
if ( V_42 & V_81 ) {
V_42 &= ~ ( V_82 | V_83 ) ;
V_4 -> V_84 . V_85 ++ ;
if ( F_107 ( V_4 ) )
continue;
}
if ( V_42 & V_82 )
V_4 -> V_84 . V_86 ++ ;
if ( V_42 & V_83 )
V_4 -> V_84 . V_87 ++ ;
if ( V_42 & V_88 )
V_4 -> V_84 . V_89 ++ ;
V_42 &= V_4 -> V_59 ;
if ( V_42 & V_81 )
V_170 = V_172 ;
else if ( V_42 & V_82 )
V_170 = V_173 ;
else if ( V_42 & V_83 )
V_170 = V_174 ;
}
if ( F_108 ( V_4 , V_76 . V_71 ) )
continue;
F_109 ( V_4 , V_42 , V_88 , V_76 . V_71 , V_170 ) ;
}
F_78 ( & V_4 -> V_14 ) ;
F_79 ( & V_4 -> V_93 -> V_4 ) ;
F_80 ( & V_4 -> V_14 ) ;
}
static void F_110 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_175 ;
for ( V_175 = 0 ; V_175 < 2 ; V_175 ++ ) {
struct V_163 * V_164 = & V_5 -> V_176 [ V_175 ] ;
F_97 ( V_4 -> V_19 ,
V_164 -> V_166 ,
V_164 -> V_167 ,
V_177 ) ;
F_111 ( V_164 -> V_80 ) ;
}
if ( ! V_5 -> V_139 )
F_83 ( & V_5 -> V_140 ) ;
}
static void F_112 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_132 * V_133 = & V_4 -> V_93 -> V_4 ;
struct V_163 * V_164 ;
int V_178 = V_5 -> V_179 ;
unsigned int V_77 ;
unsigned int V_78 ;
unsigned int V_131 ;
do {
F_22 ( V_4 , V_145 ) ;
V_164 = & V_5 -> V_176 [ V_178 ] ;
V_77 = F_113 ( V_4 ) - V_164 -> V_166 ;
V_78 = V_164 -> V_169 ;
V_77 = F_114 ( V_77 , V_164 -> V_167 ) ;
if ( F_115 ( V_77 != V_78 ) ) {
F_116 ( V_4 -> V_19 , V_164 -> V_166 ,
V_164 -> V_167 , V_177 ) ;
V_131 = V_77 - V_78 ;
F_77 ( V_133 , V_164 -> V_80 + V_164 -> V_169 ,
V_131 ) ;
F_100 ( V_4 -> V_19 , V_164 -> V_166 ,
V_164 -> V_167 , V_177 ) ;
V_4 -> V_84 . V_148 += V_131 ;
V_164 -> V_169 = V_77 ;
}
if ( V_77 >= V_164 -> V_167 ) {
V_164 -> V_169 = 0 ;
F_117 ( V_4 , V_164 -> V_166 ) ;
F_118 ( V_4 , V_164 -> V_167 ) ;
V_178 = ! V_178 ;
V_5 -> V_179 = V_178 ;
}
} while ( V_77 >= V_164 -> V_167 );
F_78 ( & V_4 -> V_14 ) ;
F_79 ( V_133 ) ;
F_80 ( & V_4 -> V_14 ) ;
F_14 ( V_4 , V_57 | V_58 ) ;
}
static int F_119 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_175 ;
for ( V_175 = 0 ; V_175 < 2 ; V_175 ++ ) {
struct V_163 * V_164 = & V_5 -> V_176 [ V_175 ] ;
V_164 -> V_80 = F_120 ( V_180 , V_181 ) ;
if ( V_164 -> V_80 == NULL ) {
if ( V_175 != 0 ) {
F_97 ( V_4 -> V_19 ,
V_5 -> V_176 [ 0 ] . V_166 ,
V_180 ,
V_177 ) ;
F_111 ( V_5 -> V_176 [ 0 ] . V_80 ) ;
}
V_5 -> V_6 = 0 ;
return - V_182 ;
}
V_164 -> V_166 = F_104 ( V_4 -> V_19 ,
V_164 -> V_80 ,
V_180 ,
V_177 ) ;
V_164 -> V_167 = V_180 ;
V_164 -> V_169 = 0 ;
}
V_5 -> V_179 = 0 ;
F_121 ( V_4 , V_5 -> V_176 [ 0 ] . V_166 ) ;
F_122 ( V_4 , V_180 ) ;
F_117 ( V_4 , V_5 -> V_176 [ 1 ] . V_166 ) ;
F_118 ( V_4 , V_180 ) ;
return 0 ;
}
static void F_123 ( unsigned long V_154 )
{
struct V_2 * V_4 = (struct V_2 * ) V_154 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_42 ;
unsigned int V_183 ;
F_80 ( & V_4 -> V_14 ) ;
V_5 -> V_184 ( V_4 ) ;
V_42 = V_5 -> V_156 ;
V_183 = V_42 ^ V_5 -> V_185 ;
if ( V_183 & ( V_50 | V_48
| V_44 | V_46 ) ) {
if ( V_183 & V_50 )
V_4 -> V_84 . V_186 ++ ;
if ( V_183 & V_48 )
V_4 -> V_84 . V_187 ++ ;
if ( V_183 & V_44 )
F_124 ( V_4 , ! ( V_42 & V_44 ) ) ;
if ( V_183 & V_46 )
F_125 ( V_4 , ! ( V_42 & V_46 ) ) ;
F_126 ( & V_4 -> V_93 -> V_4 . V_188 ) ;
V_5 -> V_185 = V_42 ;
}
V_5 -> V_189 ( V_4 ) ;
F_78 ( & V_4 -> V_14 ) ;
}
static int F_127 ( struct V_1 * V_5 ,
struct V_190 * V_191 )
{
struct V_192 * V_193 = V_191 -> V_19 . V_194 ;
struct V_195 * V_196 = F_128 ( & V_191 -> V_19 ) ;
if ( V_193 ) {
if ( F_129 ( V_193 , L_15 , NULL ) ) {
if ( F_129 ( V_193 , L_16 , NULL ) ) {
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
if ( F_129 ( V_193 , L_17 , NULL ) ) {
if ( F_129 ( V_193 , L_16 , NULL ) ) {
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
V_5 -> V_6 = V_196 -> V_9 ;
V_5 -> V_7 = V_196 -> V_8 ;
V_5 -> V_9 = false ;
V_5 -> V_8 = false ;
}
return 0 ;
}
static void F_130 ( struct V_1 * V_5 ,
struct V_190 * V_191 )
{
struct V_192 * V_193 = V_191 -> V_19 . V_194 ;
struct V_195 * V_196 = F_128 ( & V_191 -> V_19 ) ;
if ( V_193 ) {
T_5 V_197 [ 2 ] ;
if ( F_131 ( V_193 , L_18 ,
V_197 , 2 ) == 0 ) {
struct V_10 * V_11 = & V_5 -> V_17 ;
V_11 -> V_198 = V_197 [ 0 ] ;
V_11 -> V_21 = V_197 [ 1 ] ;
V_11 -> V_13 = 0 ;
if ( F_129 ( V_193 , L_19 , NULL ) )
V_11 -> V_13 |= V_53 ;
if ( F_129 ( V_193 , L_20 ,
NULL ) )
V_11 -> V_13 |= V_18 ;
}
} else {
V_5 -> V_17 = V_196 -> V_17 ;
}
}
static void F_132 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_6 ( V_4 ) ) {
V_5 -> V_199 = & F_86 ;
V_5 -> V_189 = & F_84 ;
V_5 -> V_200 = & F_82 ;
} else if ( F_3 ( V_4 ) ) {
V_5 -> V_199 = & F_119 ;
V_5 -> V_189 = & F_112 ;
V_5 -> V_200 = & F_110 ;
} else {
V_5 -> V_199 = NULL ;
V_5 -> V_189 = & F_105 ;
V_5 -> V_200 = NULL ;
}
if ( F_5 ( V_4 ) ) {
V_5 -> V_201 = & F_63 ;
V_5 -> V_184 = & F_55 ;
V_5 -> V_202 = & F_52 ;
} else if ( F_4 ( V_4 ) ) {
V_5 -> V_201 = & F_103 ;
V_5 -> V_184 = & F_98 ;
V_5 -> V_202 = & F_96 ;
} else {
V_5 -> V_201 = NULL ;
V_5 -> V_184 = & F_40 ;
V_5 -> V_202 = NULL ;
}
}
static void F_133 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_203 = F_134 ( V_4 ) ;
T_5 V_204 ;
int V_205 , V_3 ;
V_205 = 0x55534152 ;
V_3 = 0x44424755 ;
V_5 -> V_139 = false ;
if ( V_203 == V_205 ) {
F_11 ( V_4 -> V_19 , L_21 ) ;
V_5 -> V_139 = true ;
} else if ( V_203 == V_3 ) {
F_11 ( V_4 -> V_19 , L_22 ) ;
V_5 -> V_139 = false ;
} else {
V_204 = F_135 ( V_4 ) ;
switch ( V_204 ) {
case 0x302 :
case 0x10213 :
F_11 ( V_4 -> V_19 , L_23 ) ;
V_5 -> V_139 = true ;
break;
case 0x203 :
case 0x10202 :
F_11 ( V_4 -> V_19 , L_24 ) ;
V_5 -> V_139 = false ;
break;
default:
F_60 ( V_4 -> V_19 , L_25 ) ;
}
}
}
static int F_136 ( struct V_2 * V_4 )
{
struct V_190 * V_191 = F_137 ( V_4 -> V_19 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_206 * V_207 = V_4 -> V_93 -> V_4 . V_207 ;
int V_208 ;
F_9 ( V_4 , - 1 ) ;
V_208 = F_138 ( V_4 -> V_157 , F_94 , V_209 ,
V_207 ? V_207 -> V_203 : L_26 , V_4 ) ;
if ( V_208 ) {
F_139 ( L_27 ) ;
return V_208 ;
}
F_127 ( V_5 , V_191 ) ;
if ( V_5 -> V_199 ) {
V_208 = V_5 -> V_199 ( V_4 ) ;
if ( V_208 < 0 )
F_132 ( V_4 ) ;
}
if ( V_5 -> V_201 ) {
V_208 = V_5 -> V_201 ( V_4 ) ;
if ( V_208 < 0 )
F_132 ( V_4 ) ;
}
if ( V_210 ) {
V_208 = V_210 ( V_4 ) ;
if ( V_208 ) {
F_140 ( V_4 -> V_157 , V_4 ) ;
return V_208 ;
}
}
V_5 -> V_185 = F_17 ( V_4 ) ;
V_5 -> V_156 = V_5 -> V_185 ;
F_22 ( V_4 , V_55 | V_211 ) ;
F_22 ( V_4 , V_212 | V_56 ) ;
if ( F_3 ( V_4 ) ) {
if ( ! V_5 -> V_139 ) {
F_141 ( & V_5 -> V_140 ,
F_88 ,
( unsigned long ) V_4 ) ;
F_89 ( & V_5 -> V_140 ,
V_155 + F_90 ( V_4 ) ) ;
} else {
F_142 ( V_4 , V_213 ) ;
F_22 ( V_4 , V_145 ) ;
F_14 ( V_4 , V_57 | V_58 ) ;
}
F_25 ( V_4 , V_60 ) ;
} else if ( F_6 ( V_4 ) ) {
if ( ! V_5 -> V_139 ) {
F_141 ( & V_5 -> V_140 ,
F_88 ,
( unsigned long ) V_4 ) ;
F_89 ( & V_5 -> V_140 ,
V_155 + F_90 ( V_4 ) ) ;
} else {
F_142 ( V_4 , V_213 ) ;
F_22 ( V_4 , V_145 ) ;
F_14 ( V_4 , V_58 ) ;
}
} else {
F_14 ( V_4 , V_61 ) ;
}
return 0 ;
}
static void F_143 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_29 ( V_4 ) ;
F_24 ( V_4 ) ;
if ( V_5 -> V_200 )
V_5 -> V_200 ( V_4 ) ;
if ( V_5 -> V_202 )
V_5 -> V_202 ( V_4 ) ;
F_22 ( V_4 , V_55 ) ;
F_9 ( V_4 , - 1 ) ;
F_140 ( V_4 -> V_157 , V_4 ) ;
if ( V_214 )
V_214 ( V_4 ) ;
}
static void F_144 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_102 ( V_4 , 0 ) ;
V_5 -> V_165 . V_169 = 0 ;
}
}
static void F_145 ( struct V_2 * V_4 , unsigned int V_93 ,
unsigned int V_215 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_93 ) {
case 0 :
F_146 ( V_5 -> V_216 ) ;
F_14 ( V_4 , V_5 -> V_217 ) ;
break;
case 3 :
V_5 -> V_217 = F_95 ( V_4 ) ;
F_9 ( V_4 , - 1 ) ;
F_147 ( V_5 -> V_216 ) ;
break;
default:
F_139 ( V_218 L_28 , V_93 ) ;
}
}
static void F_148 ( struct V_2 * V_4 , struct V_219 * V_220 ,
struct V_219 * V_221 )
{
unsigned long V_13 ;
unsigned int V_12 , V_222 , V_223 , V_224 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_12 = F_10 ( V_4 ) & ~ ( V_225 | V_226
| V_227 | V_228
| V_16 ) ;
V_224 = F_149 ( V_4 , V_220 , V_221 , 0 , V_4 -> V_229 / 16 ) ;
V_223 = F_150 ( V_4 , V_224 ) ;
if ( V_223 > 65535 ) {
V_223 /= 8 ;
V_12 |= V_230 ;
}
switch ( V_220 -> V_231 & V_232 ) {
case V_233 :
V_12 |= V_234 ;
break;
case V_235 :
V_12 |= V_236 ;
break;
case V_237 :
V_12 |= V_238 ;
break;
default:
V_12 |= V_239 ;
break;
}
if ( V_220 -> V_231 & V_240 )
V_12 |= V_241 ;
if ( V_220 -> V_231 & V_242 ) {
if ( V_220 -> V_231 & V_243 ) {
if ( V_220 -> V_231 & V_244 )
V_12 |= V_245 ;
else
V_12 |= V_246 ;
} else if ( V_220 -> V_231 & V_244 )
V_12 |= V_247 ;
else
V_12 |= V_248 ;
} else
V_12 |= V_249 ;
if ( V_220 -> V_231 & V_250 )
V_12 |= V_251 ;
else
V_12 |= V_252 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
V_4 -> V_59 = V_88 ;
if ( V_220 -> V_253 & V_254 )
V_4 -> V_59 |= ( V_83 | V_82 ) ;
if ( V_220 -> V_253 & ( V_255 | V_256 ) )
V_4 -> V_59 |= V_81 ;
if ( F_3 ( V_4 ) )
F_14 ( V_4 , V_4 -> V_59 ) ;
V_4 -> V_257 = 0 ;
if ( V_220 -> V_253 & V_258 )
V_4 -> V_257 |= ( V_83 | V_82 ) ;
if ( V_220 -> V_253 & V_259 ) {
V_4 -> V_257 |= V_81 ;
if ( V_220 -> V_253 & V_258 )
V_4 -> V_257 |= V_88 ;
}
F_151 ( V_4 , V_220 -> V_231 , V_224 ) ;
V_222 = F_95 ( V_4 ) ;
F_9 ( V_4 , - 1 ) ;
F_22 ( V_4 , V_260 | V_62 ) ;
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
F_152 ( V_4 , V_223 ) ;
F_22 ( V_4 , V_55 | V_211 ) ;
F_22 ( V_4 , V_212 | V_56 ) ;
F_14 ( V_4 , V_222 ) ;
if ( F_153 ( V_4 , V_220 -> V_231 ) )
V_4 -> V_261 -> V_262 ( V_4 ) ;
F_15 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_154 ( struct V_2 * V_4 , int V_263 )
{
if ( V_263 == V_264 ) {
V_4 -> V_13 |= V_265 ;
F_30 ( V_4 ) ;
} else {
V_4 -> V_13 &= ~ V_265 ;
}
}
static const char * F_155 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_266 ) ? L_29 : NULL ;
}
static void F_156 ( struct V_2 * V_4 )
{
struct V_190 * V_191 = F_137 ( V_4 -> V_19 ) ;
int V_267 = V_191 -> V_268 [ 0 ] . V_269 - V_191 -> V_268 [ 0 ] . V_270 + 1 ;
F_157 ( V_4 -> V_29 , V_267 ) ;
if ( V_4 -> V_13 & V_271 ) {
F_158 ( V_4 -> V_272 ) ;
V_4 -> V_272 = NULL ;
}
}
static int F_159 ( struct V_2 * V_4 )
{
struct V_190 * V_191 = F_137 ( V_4 -> V_19 ) ;
int V_267 = V_191 -> V_268 [ 0 ] . V_269 - V_191 -> V_268 [ 0 ] . V_270 + 1 ;
if ( ! F_160 ( V_4 -> V_29 , V_267 , L_26 ) )
return - V_273 ;
if ( V_4 -> V_13 & V_271 ) {
V_4 -> V_272 = F_161 ( V_4 -> V_29 , V_267 ) ;
if ( V_4 -> V_272 == NULL ) {
F_157 ( V_4 -> V_29 , V_267 ) ;
return - V_182 ;
}
}
return 0 ;
}
static void F_162 ( struct V_2 * V_4 , int V_13 )
{
if ( V_13 & V_274 ) {
V_4 -> type = V_266 ;
F_159 ( V_4 ) ;
}
}
static int F_163 ( struct V_2 * V_4 , struct V_275 * V_276 )
{
int V_43 = 0 ;
if ( V_276 -> type != V_277 && V_276 -> type != V_266 )
V_43 = - V_106 ;
if ( V_4 -> V_157 != V_276 -> V_157 )
V_43 = - V_106 ;
if ( V_276 -> V_278 != V_279 )
V_43 = - V_106 ;
if ( V_4 -> V_229 / 16 != V_276 -> V_280 )
V_43 = - V_106 ;
if ( ( void * ) V_4 -> V_29 != V_276 -> V_281 )
V_43 = - V_106 ;
if ( V_4 -> V_282 != V_276 -> V_4 )
V_43 = - V_106 ;
if ( V_276 -> V_283 != 0 )
V_43 = - V_106 ;
return V_43 ;
}
static int F_164 ( struct V_2 * V_4 )
{
while ( ! ( F_17 ( V_4 ) & V_61 ) )
F_165 () ;
return F_37 ( V_4 ) ;
}
static void F_166 ( struct V_2 * V_4 , unsigned char V_71 )
{
while ( ! ( F_17 ( V_4 ) & V_25 ) )
F_165 () ;
F_41 ( V_4 , V_71 ) ;
}
static int
F_167 ( struct V_2 * V_4 , unsigned int V_284 , unsigned long V_98 )
{
struct V_10 V_11 ;
switch ( V_284 ) {
case V_285 :
if ( F_168 ( & V_11 , (struct V_10 * ) V_98 ,
sizeof( V_11 ) ) )
return - V_286 ;
F_7 ( V_4 , & V_11 ) ;
break;
case V_287 :
if ( F_169 ( (struct V_10 * ) V_98 ,
& ( F_1 ( V_4 ) -> V_17 ) ,
sizeof( V_11 ) ) )
return - V_286 ;
break;
default:
return - V_288 ;
}
return 0 ;
}
static int F_170 ( struct V_1 * V_5 ,
struct V_190 * V_191 )
{
int V_43 ;
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_195 * V_196 = F_128 ( & V_191 -> V_19 ) ;
if ( ! F_127 ( V_5 , V_191 ) )
F_132 ( V_4 ) ;
F_130 ( V_5 , V_191 ) ;
V_4 -> V_289 = V_290 ;
V_4 -> V_13 = V_291 ;
V_4 -> V_261 = & V_292 ;
V_4 -> V_293 = 1 ;
V_4 -> V_19 = & V_191 -> V_19 ;
V_4 -> V_29 = V_191 -> V_268 [ 0 ] . V_270 ;
V_4 -> V_157 = V_191 -> V_268 [ 1 ] . V_270 ;
F_171 ( & V_5 -> V_91 , F_123 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_74 , 0 , sizeof( V_5 -> V_74 ) ) ;
if ( V_196 && V_196 -> V_294 ) {
V_4 -> V_272 = V_196 -> V_294 ;
} else {
V_4 -> V_13 |= V_271 ;
V_4 -> V_272 = NULL ;
}
if ( ! V_5 -> V_216 ) {
V_5 -> V_216 = F_172 ( & V_191 -> V_19 , L_30 ) ;
if ( F_173 ( V_5 -> V_216 ) ) {
V_43 = F_174 ( V_5 -> V_216 ) ;
V_5 -> V_216 = NULL ;
return V_43 ;
}
V_43 = F_146 ( V_5 -> V_216 ) ;
if ( V_43 ) {
F_175 ( V_5 -> V_216 ) ;
V_5 -> V_216 = NULL ;
return V_43 ;
}
V_4 -> V_229 = F_176 ( V_5 -> V_216 ) ;
F_147 ( V_5 -> V_216 ) ;
}
if ( V_5 -> V_17 . V_13 & V_18 )
V_5 -> V_15 = V_20 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_293 = V_180 ;
V_5 -> V_15 = V_23 | V_24 ;
} else {
V_5 -> V_15 = V_25 ;
}
return 0 ;
}
static void F_177 ( struct V_2 * V_4 , int V_71 )
{
while ( ! ( F_17 ( V_4 ) & V_25 ) )
F_165 () ;
F_41 ( V_4 , V_71 ) ;
}
static void F_178 ( struct V_295 * V_296 , const char * V_297 , T_1 V_131 )
{
struct V_2 * V_4 = & V_298 [ V_296 -> V_299 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_42 , V_222 ;
unsigned int V_165 ;
V_222 = F_95 ( V_4 ) ;
F_9 ( V_4 , V_61 | V_5 -> V_15 ) ;
V_165 = F_28 ( V_4 ) & V_54 ;
F_25 ( V_4 , V_52 ) ;
F_179 ( V_4 , V_297 , V_131 , F_177 ) ;
do {
V_42 = F_17 ( V_4 ) ;
} while ( ! ( V_42 & V_25 ) );
if ( V_165 )
F_25 ( V_4 , V_54 ) ;
F_14 ( V_4 , V_222 ) ;
}
static void T_6 F_180 ( struct V_2 * V_4 , int * V_224 ,
int * V_86 , int * V_300 )
{
unsigned int V_301 , V_223 ;
V_223 = F_181 ( V_4 ) & V_302 ;
if ( ! V_223 )
return;
V_301 = F_10 ( V_4 ) & V_226 ;
if ( V_301 == V_239 )
* V_300 = 8 ;
else
* V_300 = 7 ;
V_301 = F_10 ( V_4 ) & V_228 ;
if ( V_301 == V_248 )
* V_86 = 'e' ;
else if ( V_301 == V_247 )
* V_86 = 'o' ;
* V_224 = V_4 -> V_229 / ( 16 * ( V_223 - 1 ) ) ;
}
static int T_6 F_182 ( struct V_295 * V_296 , char * V_303 )
{
int V_43 ;
struct V_2 * V_4 = & V_298 [ V_296 -> V_299 ] . V_3 ;
int V_224 = 115200 ;
int V_300 = 8 ;
int V_86 = 'n' ;
int V_304 = 'n' ;
if ( V_4 -> V_272 == NULL ) {
return - V_305 ;
}
V_43 = F_146 ( V_298 [ V_296 -> V_299 ] . V_216 ) ;
if ( V_43 )
return V_43 ;
F_9 ( V_4 , - 1 ) ;
F_22 ( V_4 , V_55 | V_211 ) ;
F_22 ( V_4 , V_212 | V_56 ) ;
if ( V_303 )
F_183 ( V_303 , & V_224 , & V_86 , & V_300 , & V_304 ) ;
else
F_180 ( V_4 , & V_224 , & V_86 , & V_300 ) ;
return F_184 ( V_4 , V_296 , V_224 , V_86 , V_300 , V_304 ) ;
}
static int T_6 F_185 ( void )
{
int V_43 ;
if ( V_306 ) {
struct V_195 * V_196 =
F_128 ( & V_306 -> V_19 ) ;
int V_307 = V_196 -> V_308 ;
struct V_1 * V_4 = & V_298 [ V_307 ] ;
V_4 -> V_217 = 0 ;
V_4 -> V_3 . line = V_307 ;
F_186 ( V_309 , V_307 , NULL ) ;
V_43 = F_170 ( V_4 , V_306 ) ;
if ( V_43 )
return V_43 ;
F_187 ( & V_310 ) ;
}
return 0 ;
}
static int T_6 F_188 ( void )
{
if ( V_306
&& ! ( V_310 . V_13 & V_311 ) )
F_187 ( & V_310 ) ;
return 0 ;
}
static inline bool F_189 ( struct V_2 * V_4 )
{
return V_4 -> V_312 && V_4 -> V_312 -> V_299 == V_4 -> line ;
}
static inline bool F_189 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_190 ( void )
{
#ifdef F_191
return F_192 () ;
#else
return false ;
#endif
}
static int F_193 ( struct V_190 * V_191 ,
T_7 V_93 )
{
struct V_2 * V_4 = F_194 ( V_191 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_189 ( V_4 ) && V_313 ) {
while ( ! ( F_17 ( V_4 ) & V_20 ) )
F_165 () ;
}
V_5 -> V_314 = F_195 ( & V_191 -> V_19 ) ;
if ( F_190 () )
F_196 ( & V_191 -> V_19 , 0 ) ;
F_197 ( & V_315 , V_4 ) ;
return 0 ;
}
static int F_198 ( struct V_190 * V_191 )
{
struct V_2 * V_4 = F_194 ( V_191 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_199 ( & V_315 , V_4 ) ;
F_196 ( & V_191 -> V_19 , V_5 -> V_314 ) ;
return 0 ;
}
static int F_200 ( struct V_190 * V_191 )
{
struct V_1 * V_4 ;
struct V_192 * V_193 = V_191 -> V_19 . V_194 ;
struct V_195 * V_196 = F_128 ( & V_191 -> V_19 ) ;
void * V_154 ;
int V_43 = - V_305 ;
F_201 ( V_79 & ( V_79 - 1 ) ) ;
if ( V_193 )
V_43 = F_202 ( V_193 , L_31 ) ;
else
if ( V_196 )
V_43 = V_196 -> V_308 ;
if ( V_43 < 0 )
V_43 = F_203 ( V_316 , V_317 ) ;
if ( V_43 >= V_317 ) {
V_43 = - V_305 ;
goto V_318;
}
if ( F_204 ( V_43 , V_316 ) ) {
V_43 = - V_273 ;
goto V_318;
}
V_4 = & V_298 [ V_43 ] ;
V_4 -> V_217 = 0 ;
V_4 -> V_3 . line = V_43 ;
V_43 = F_170 ( V_4 , V_191 ) ;
if ( V_43 )
goto V_318;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_43 = - V_182 ;
V_154 = F_120 ( sizeof( struct V_75 )
* V_79 , V_181 ) ;
if ( ! V_154 )
goto V_319;
V_4 -> V_74 . V_80 = V_154 ;
}
V_43 = F_205 ( & V_315 , & V_4 -> V_3 ) ;
if ( V_43 )
goto V_320;
#ifdef F_206
if ( F_189 ( & V_4 -> V_3 )
&& V_321 -> V_13 & V_311 ) {
F_147 ( V_4 -> V_216 ) ;
}
#endif
F_207 ( & V_191 -> V_19 , 1 ) ;
F_208 ( V_191 , V_4 ) ;
if ( V_4 -> V_17 . V_13 & V_18 ) {
F_13 ( & V_4 -> V_3 , V_252 ) ;
F_22 ( & V_4 -> V_3 , V_33 ) ;
}
F_133 ( & V_4 -> V_3 ) ;
return 0 ;
V_320:
F_111 ( V_4 -> V_74 . V_80 ) ;
V_4 -> V_74 . V_80 = NULL ;
V_319:
if ( ! F_189 ( & V_4 -> V_3 ) ) {
F_175 ( V_4 -> V_216 ) ;
V_4 -> V_216 = NULL ;
}
V_318:
return V_43 ;
}
static int F_209 ( struct V_190 * V_191 )
{
struct V_2 * V_4 = F_194 ( V_191 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_43 = 0 ;
F_207 ( & V_191 -> V_19 , 0 ) ;
V_43 = F_210 ( & V_315 , V_4 ) ;
F_211 ( & V_5 -> V_91 ) ;
F_111 ( V_5 -> V_74 . V_80 ) ;
F_212 ( V_4 -> line , V_316 ) ;
F_175 ( V_5 -> V_216 ) ;
return V_43 ;
}
static int T_6 F_213 ( void )
{
int V_43 ;
V_43 = F_214 ( & V_315 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_215 ( & V_322 ) ;
if ( V_43 )
F_216 ( & V_315 ) ;
return V_43 ;
}
static void T_8 F_217 ( void )
{
F_218 ( & V_322 ) ;
F_216 ( & V_315 ) ;
}
