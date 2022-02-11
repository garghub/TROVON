static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static struct V_4 * F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static struct V_1 * F_3 ( struct V_1 * V_5 )
{
return V_5 -> V_6 ;
}
static struct V_7 * F_4 ( struct V_8 * V_9 )
{
return & V_9 -> V_10 ;
}
static void F_5 ( struct V_8 * V_9 ,
unsigned long * V_11 , unsigned long * V_12 )
{
unsigned long V_13 = V_9 -> V_14 ;
unsigned long V_15 = F_6 ( & V_9 -> V_16 -> V_17 ) ;
unsigned long long V_18 = V_9 -> V_16 -> V_19 ;
unsigned long long V_20 = V_9 -> V_16 -> V_21 ;
if ( V_13 < V_15 ) {
if ( V_18 ) {
V_18 *= V_13 ;
F_7 ( V_18 , V_15 ) ;
}
if ( V_20 < 100 ) {
V_20 *= V_13 ;
F_7 ( V_20 , V_15 ) ;
}
}
* V_11 = V_18 ;
* V_12 = V_20 ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return false ;
}
static struct V_4 * F_2 ( struct V_1 * V_2 )
{
return & V_22 ;
}
static struct V_1 * F_3 ( struct V_1 * V_5 )
{
return NULL ;
}
static struct V_7 * F_4 ( struct V_8 * V_9 )
{
return NULL ;
}
static void F_5 ( struct V_8 * V_9 ,
unsigned long * V_11 , unsigned long * V_12 )
{
* V_11 = V_9 -> V_16 -> V_19 ;
* V_12 = V_9 -> V_16 -> V_21 ;
}
static unsigned long F_8 ( struct V_23 * V_23 )
{
unsigned long V_24 ;
V_24 = F_9 ( V_23 , V_25 ) ;
V_24 -= V_18 ( V_24 , V_23 -> V_26 ) ;
V_24 += F_9 ( V_23 , V_27 ) ;
V_24 += F_9 ( V_23 , V_28 ) ;
return V_24 ;
}
static unsigned long F_10 ( unsigned long V_29 )
{
#ifdef F_11
int V_30 ;
unsigned long V_31 = 0 ;
int V_32 ;
F_12 (node, N_HIGH_MEMORY) {
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
struct V_23 * V_34 = & F_13 ( V_30 ) -> V_35 [ V_32 ] ;
if ( F_14 ( V_34 ) )
V_31 += F_8 ( V_34 ) ;
}
}
if ( ( long ) V_31 < 0 )
V_31 = 0 ;
return V_18 ( V_31 , V_29 ) ;
#else
return 0 ;
#endif
}
static unsigned long F_15 ( void )
{
unsigned long V_31 ;
V_31 = F_16 ( V_25 ) ;
V_31 -= V_18 ( V_31 , V_26 ) ;
V_31 += F_16 ( V_27 ) ;
V_31 += F_16 ( V_28 ) ;
if ( ! V_36 )
V_31 -= F_10 ( V_31 ) ;
return V_31 + 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
const unsigned long V_37 = V_2 -> V_38 ;
struct V_1 * V_6 = F_3 ( V_2 ) ;
unsigned long V_39 = V_40 ;
unsigned long V_41 = V_42 ;
unsigned long V_43 = ( V_44 * V_45 ) / 100 ;
unsigned long V_46 = ( V_47 * V_45 ) / 100 ;
unsigned long V_48 ;
unsigned long V_49 ;
struct V_50 * V_51 ;
if ( V_6 ) {
unsigned long V_52 = V_6 -> V_38 ;
if ( V_39 )
V_43 = V_18 ( F_18 ( V_39 , V_52 ) ,
V_45 ) ;
if ( V_41 )
V_46 = V_18 ( F_18 ( V_41 , V_52 ) ,
V_45 ) ;
V_39 = V_41 = 0 ;
}
if ( V_39 )
V_48 = F_18 ( V_39 , V_45 ) ;
else
V_48 = ( V_43 * V_37 ) / V_45 ;
if ( V_41 )
V_49 = F_18 ( V_41 , V_45 ) ;
else
V_49 = ( V_46 * V_37 ) / V_45 ;
if ( V_49 >= V_48 )
V_49 = V_48 / 2 ;
V_51 = V_53 ;
if ( V_51 -> V_54 & V_55 || F_19 ( V_51 ) ) {
V_49 += V_49 / 4 + V_22 . V_56 / 32 ;
V_48 += V_48 / 4 + V_22 . V_56 / 32 ;
}
V_2 -> V_48 = V_48 ;
V_2 -> V_49 = V_49 ;
if ( ! V_6 )
F_20 ( V_49 , V_48 ) ;
}
void F_21 ( unsigned long * V_57 , unsigned long * V_58 )
{
struct V_1 V_6 = { V_59 } ;
V_6 . V_38 = F_15 () ;
F_17 ( & V_6 ) ;
* V_57 = V_6 . V_49 ;
* V_58 = V_6 . V_48 ;
}
static unsigned long F_22 ( struct V_23 * V_23 )
{
unsigned long V_60 = F_8 ( V_23 ) ;
struct V_50 * V_51 = V_53 ;
unsigned long V_61 ;
if ( V_40 )
V_61 = F_18 ( V_40 , V_45 ) *
V_60 / F_15 () ;
else
V_61 = V_44 * V_60 / 100 ;
if ( V_51 -> V_54 & V_55 || F_19 ( V_51 ) )
V_61 += V_61 / 4 ;
return V_61 ;
}
bool F_23 ( struct V_23 * V_23 )
{
unsigned long V_62 = F_22 ( V_23 ) ;
return F_9 ( V_23 , V_63 ) +
F_9 ( V_23 , V_64 ) +
F_9 ( V_23 , V_65 ) <= V_62 ;
}
int F_24 ( struct V_66 * V_67 , int V_68 ,
void T_1 * V_69 , T_2 * V_70 ,
T_3 * V_71 )
{
int V_72 ;
V_72 = F_25 ( V_67 , V_68 , V_69 , V_70 , V_71 ) ;
if ( V_72 == 0 && V_68 )
V_42 = 0 ;
return V_72 ;
}
int F_26 ( struct V_66 * V_67 , int V_68 ,
void T_1 * V_69 , T_2 * V_70 ,
T_3 * V_71 )
{
int V_72 ;
V_72 = F_27 ( V_67 , V_68 , V_69 , V_70 , V_71 ) ;
if ( V_72 == 0 && V_68 )
V_47 = 0 ;
return V_72 ;
}
int F_28 ( struct V_66 * V_67 , int V_68 ,
void T_1 * V_69 , T_2 * V_70 ,
T_3 * V_71 )
{
int V_73 = V_44 ;
int V_72 ;
V_72 = F_25 ( V_67 , V_68 , V_69 , V_70 , V_71 ) ;
if ( V_72 == 0 && V_68 && V_44 != V_73 ) {
F_29 () ;
V_40 = 0 ;
}
return V_72 ;
}
int F_30 ( struct V_66 * V_67 , int V_68 ,
void T_1 * V_69 , T_2 * V_70 ,
T_3 * V_71 )
{
unsigned long V_74 = V_40 ;
int V_72 ;
V_72 = F_27 ( V_67 , V_68 , V_69 , V_70 , V_71 ) ;
if ( V_72 == 0 && V_68 && V_40 != V_74 ) {
F_29 () ;
V_44 = 0 ;
}
return V_72 ;
}
static unsigned long F_31 ( unsigned long V_75 )
{
V_75 += V_76 ;
if ( ! V_75 )
return 1 ;
return V_75 ;
}
static void F_32 ( struct V_4 * V_3 ,
struct V_7 * V_77 ,
unsigned int V_78 )
{
F_33 ( & V_3 -> V_77 , V_77 ,
V_78 ) ;
if ( ! F_34 ( V_3 -> V_79 ) ) {
V_3 -> V_79 = F_31 ( V_80 ) ;
F_35 ( & V_3 -> V_81 , V_3 -> V_79 ) ;
}
}
static inline void F_36 ( struct V_8 * V_9 )
{
struct V_4 * V_82 ;
F_37 ( V_9 , V_83 ) ;
F_32 ( & V_22 , & V_9 -> V_77 ,
V_9 -> V_16 -> V_78 ) ;
V_82 = F_38 ( V_9 ) ;
if ( V_82 )
F_32 ( V_82 , F_4 ( V_9 ) ,
V_9 -> V_16 -> V_78 ) ;
}
void F_39 ( struct V_8 * V_9 )
{
unsigned long V_54 ;
F_40 ( V_54 ) ;
F_36 ( V_9 ) ;
F_41 ( V_54 ) ;
}
static void F_42 ( unsigned long V_84 )
{
struct V_4 * V_3 = ( void * ) V_84 ;
int V_85 = ( V_80 - V_3 -> V_79 ) /
V_76 ;
if ( F_43 ( & V_3 -> V_77 , V_85 + 1 ) ) {
V_3 -> V_79 = F_31 ( V_3 -> V_79 +
V_85 * V_76 ) ;
F_35 ( & V_3 -> V_81 , V_3 -> V_79 ) ;
} else {
V_3 -> V_79 = 0 ;
}
}
int F_44 ( struct V_4 * V_3 , T_4 V_86 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_45 ( & V_3 -> V_87 ) ;
F_46 ( & V_3 -> V_81 ) ;
V_3 -> V_81 . V_88 = F_42 ;
V_3 -> V_81 . V_89 = ( unsigned long ) V_3 ;
V_3 -> V_90 = V_80 ;
return F_47 ( & V_3 -> V_77 , V_86 ) ;
}
void F_48 ( struct V_4 * V_3 )
{
F_49 ( & V_3 -> V_81 ) ;
F_50 ( & V_3 -> V_77 ) ;
}
int F_51 ( struct V_91 * V_16 , unsigned int V_19 )
{
int V_72 = 0 ;
F_52 ( & V_92 ) ;
if ( V_19 > V_16 -> V_21 ) {
V_72 = - V_93 ;
} else {
V_19 -= V_16 -> V_19 ;
if ( V_94 + V_19 < 100 ) {
V_94 += V_19 ;
V_16 -> V_19 += V_19 ;
} else {
V_72 = - V_93 ;
}
}
F_53 ( & V_92 ) ;
return V_72 ;
}
int F_54 ( struct V_91 * V_16 , unsigned V_21 )
{
int V_72 = 0 ;
if ( V_21 > 100 )
return - V_93 ;
F_52 ( & V_92 ) ;
if ( V_16 -> V_19 > V_21 ) {
V_72 = - V_93 ;
} else {
V_16 -> V_21 = V_21 ;
V_16 -> V_78 = ( V_95 * V_21 ) / 100 ;
}
F_53 ( & V_92 ) ;
return V_72 ;
}
static unsigned long F_55 ( unsigned long V_48 ,
unsigned long V_49 )
{
return ( V_48 + V_49 ) / 2 ;
}
static unsigned long F_56 ( struct V_4 * V_3 ,
unsigned long V_48 )
{
return V_20 ( V_48 , V_3 -> V_56 ) ;
}
static void F_57 ( struct V_1 * V_5 ,
unsigned long V_96 , unsigned long V_97 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_98 = V_96 - V_18 ( V_96 , V_5 -> V_61 ) ;
unsigned long V_99 = V_6 -> V_38 - V_18 ( V_6 -> V_38 , V_6 -> V_61 ) ;
unsigned long V_100 = V_99 - V_18 ( V_99 , V_98 ) ;
V_5 -> V_38 = V_96 + V_18 ( V_97 , V_100 ) ;
}
static unsigned long F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_48 = V_2 -> V_48 ;
T_5 V_101 ;
long V_102 , V_103 ;
unsigned long V_104 , V_105 ;
F_59 ( & V_3 -> V_77 , V_2 -> V_106 ,
& V_102 , & V_103 ) ;
V_101 = ( V_48 * ( 100 - V_94 ) ) / 100 ;
V_101 *= V_102 ;
F_7 ( V_101 , V_103 ) ;
F_5 ( V_2 -> V_9 , & V_104 , & V_105 ) ;
V_101 += ( V_48 * V_104 ) / 100 ;
if ( V_101 > ( V_48 * V_105 ) / 100 )
V_101 = V_48 * V_105 / 100 ;
return V_101 ;
}
unsigned long F_60 ( struct V_8 * V_9 , unsigned long V_48 )
{
struct V_1 V_6 = { F_61 ( V_9 ) ,
. V_48 = V_48 } ;
return F_58 ( & V_6 ) ;
}
static long long F_62 ( unsigned long V_107 ,
unsigned long V_61 ,
unsigned long V_62 )
{
long long V_108 ;
long V_31 ;
V_31 = F_63 ( ( ( V_109 ) V_107 - ( V_109 ) V_61 ) << V_110 ,
( V_62 - V_107 ) | 1 ) ;
V_108 = V_31 ;
V_108 = V_108 * V_31 >> V_110 ;
V_108 = V_108 * V_31 >> V_110 ;
V_108 += 1 << V_110 ;
return F_64 ( V_108 , 0LL , 2LL << V_110 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_111 = V_9 -> V_14 ;
unsigned long V_112 = F_55 ( V_2 -> V_48 , V_2 -> V_49 ) ;
unsigned long V_62 = F_56 ( F_2 ( V_2 ) , V_2 -> V_48 ) ;
unsigned long V_101 = V_2 -> V_101 ;
unsigned long V_113 ;
unsigned long V_107 ;
unsigned long V_114 ;
unsigned long V_115 ;
long long V_108 ;
long V_31 ;
V_2 -> V_108 = 0 ;
if ( F_34 ( V_2 -> V_61 >= V_62 ) )
return;
V_107 = ( V_112 + V_62 ) / 2 ;
V_108 = F_62 ( V_107 , V_2 -> V_61 , V_62 ) ;
if ( F_34 ( V_9 -> V_16 -> V_116 & V_117 ) ) {
long long V_118 ;
if ( V_2 -> V_119 < 8 ) {
V_2 -> V_108 = F_66 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
return;
}
if ( V_2 -> V_119 >= V_101 )
return;
V_114 = F_55 ( V_101 ,
V_2 -> V_120 ) ;
if ( V_114 == 0 || V_114 == V_101 )
return;
V_118 = F_62 ( V_114 , V_2 -> V_119 ,
V_101 ) ;
V_2 -> V_108 = V_18 ( V_108 , V_118 ) ;
return;
}
if ( F_34 ( V_101 > V_2 -> V_48 ) )
V_101 = V_2 -> V_48 ;
V_101 = V_20 ( V_101 , ( V_62 - V_2 -> V_61 ) / 8 ) ;
V_31 = F_67 ( ( T_5 ) V_101 << 16 , V_2 -> V_48 | 1 ) ;
V_114 = V_107 * ( T_5 ) V_31 >> 16 ;
V_115 = ( V_2 -> V_48 - V_101 + 8 * V_111 ) * ( T_5 ) V_31 >> 16 ;
V_113 = V_114 + V_115 ;
if ( V_2 -> V_119 < V_113 - V_115 / 4 ) {
V_108 = F_68 ( V_108 * ( V_113 - V_2 -> V_119 ) ,
( V_113 - V_114 ) | 1 ) ;
} else
V_108 /= 4 ;
V_113 = V_101 / 2 ;
if ( V_2 -> V_119 < V_113 ) {
if ( V_2 -> V_119 > V_113 / 8 )
V_108 = F_67 ( V_108 * V_113 ,
V_2 -> V_119 ) ;
else
V_108 *= 8 ;
}
V_2 -> V_108 = V_108 ;
}
static void F_69 ( struct V_8 * V_9 ,
unsigned long V_121 ,
unsigned long V_122 )
{
const unsigned long V_123 = F_70 ( 3 * V_124 ) ;
unsigned long V_125 = V_9 -> V_14 ;
unsigned long V_126 = V_9 -> V_127 ;
T_5 V_128 ;
V_128 = V_122 - V_18 ( V_122 , V_9 -> V_129 ) ;
V_128 *= V_124 ;
if ( F_34 ( V_121 > V_123 ) ) {
F_7 ( V_128 , V_121 ) ;
V_125 = V_128 ;
goto V_130;
}
V_128 += ( T_5 ) V_9 -> V_127 * ( V_123 - V_121 ) ;
V_128 >>= F_71 ( V_123 ) ;
if ( V_125 > V_126 && V_126 >= ( unsigned long ) V_128 )
V_125 -= ( V_125 - V_126 ) >> 3 ;
if ( V_125 < V_126 && V_126 <= ( unsigned long ) V_128 )
V_125 += ( V_126 - V_125 ) >> 3 ;
V_130:
V_125 = V_20 ( V_125 , 1LU ) ;
if ( F_72 ( V_9 ) ) {
long V_131 = V_125 - V_9 -> V_14 ;
F_73 ( F_74 ( V_131 ,
& V_9 -> V_16 -> V_17 ) <= 0 ) ;
}
V_9 -> V_127 = V_128 ;
V_9 -> V_14 = V_125 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_48 = V_2 -> V_48 ;
unsigned long V_62 = V_3 -> V_56 ;
if ( V_62 < V_48 ) {
V_62 = V_48 ;
goto V_132;
}
V_48 = V_20 ( V_48 , V_2 -> V_61 ) ;
if ( V_62 > V_48 ) {
V_62 -= ( V_62 - V_48 ) >> 5 ;
goto V_132;
}
return;
V_132:
V_3 -> V_56 = V_62 ;
}
static void F_76 ( struct V_1 * V_2 ,
unsigned long V_133 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
if ( F_77 ( V_133 , V_3 -> V_90 + V_134 ) )
return;
F_78 ( & V_3 -> V_87 ) ;
if ( F_79 ( V_133 , V_3 -> V_90 + V_134 ) ) {
F_75 ( V_2 ) ;
V_3 -> V_90 = V_133 ;
}
F_80 ( & V_3 -> V_87 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
unsigned long V_135 ,
unsigned long V_121 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_61 = V_2 -> V_61 ;
unsigned long V_112 = F_55 ( V_2 -> V_48 , V_2 -> V_49 ) ;
unsigned long V_62 = F_56 ( F_2 ( V_2 ) , V_2 -> V_48 ) ;
unsigned long V_107 = ( V_112 + V_62 ) / 2 ;
unsigned long V_111 = V_9 -> V_14 ;
unsigned long V_136 = V_9 -> V_136 ;
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 ;
unsigned long V_140 ;
unsigned long V_31 ;
unsigned long V_141 ;
V_137 = ( V_135 - V_9 -> V_142 ) * V_124 / V_121 ;
V_138 = ( T_5 ) V_136 *
V_2 -> V_108 >> V_110 ;
V_138 ++ ;
V_139 = F_67 ( ( T_5 ) V_138 * V_111 ,
V_137 | 1 ) ;
if ( F_34 ( V_139 > V_111 ) )
V_139 = V_111 ;
V_140 = 0 ;
if ( F_34 ( V_9 -> V_16 -> V_116 & V_117 ) ) {
V_61 = V_2 -> V_119 ;
if ( V_2 -> V_119 < 8 )
V_107 = V_2 -> V_119 + 1 ;
else
V_107 = ( V_2 -> V_101 + V_2 -> V_120 ) / 2 ;
}
if ( V_61 < V_107 ) {
V_31 = F_82 ( V_9 -> V_139 ,
V_139 , V_138 ) ;
if ( V_136 < V_31 )
V_140 = V_31 - V_136 ;
} else {
V_31 = F_83 ( V_9 -> V_139 ,
V_139 , V_138 ) ;
if ( V_136 > V_31 )
V_140 = V_136 - V_31 ;
}
V_141 = V_136 / ( 2 * V_140 + 1 ) ;
if ( V_141 < V_143 )
V_140 = F_18 ( V_140 >> V_141 , 8 ) ;
else
V_140 = 0 ;
if ( V_136 < V_139 )
V_136 += V_140 ;
else
V_136 -= V_140 ;
V_9 -> V_136 = V_20 ( V_136 , 1UL ) ;
V_9 -> V_139 = V_139 ;
F_84 ( V_9 , V_137 , V_138 ) ;
}
static void F_85 ( struct V_1 * V_6 ,
struct V_1 * V_5 ,
unsigned long V_144 ,
bool V_145 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned long V_133 = V_80 ;
unsigned long V_121 = V_133 - V_9 -> V_146 ;
unsigned long V_135 ;
unsigned long V_122 ;
F_86 ( & V_9 -> V_147 ) ;
if ( V_121 < V_134 )
return;
V_135 = F_87 ( & V_9 -> V_148 [ V_149 ] ) ;
V_122 = F_87 ( & V_9 -> V_148 [ V_83 ] ) ;
if ( V_121 > V_124 && F_77 ( V_9 -> V_146 , V_144 ) )
goto V_150;
if ( V_145 ) {
F_76 ( V_6 , V_133 ) ;
F_81 ( V_6 , V_135 , V_121 ) ;
if ( F_88 ( V_151 ) && V_5 ) {
F_76 ( V_5 , V_133 ) ;
F_81 ( V_5 , V_135 , V_121 ) ;
}
}
F_69 ( V_9 , V_121 , V_122 ) ;
V_150:
V_9 -> V_142 = V_135 ;
V_9 -> V_129 = V_122 ;
V_9 -> V_146 = V_133 ;
}
void F_89 ( struct V_8 * V_9 , unsigned long V_144 )
{
struct V_1 V_6 = { F_61 (wb) } ;
F_85 ( & V_6 , NULL , V_144 , false ) ;
}
static unsigned long F_90 ( unsigned long V_61 ,
unsigned long V_48 )
{
if ( V_48 > V_61 )
return 1UL << ( F_71 ( V_48 - V_61 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_91 ( struct V_8 * V_9 ,
unsigned long V_119 )
{
unsigned long V_128 = V_9 -> V_14 ;
unsigned long V_84 ;
V_84 = V_119 / ( 1 + V_128 / F_70 ( 1 + V_124 / 8 ) ) ;
V_84 ++ ;
return F_66 (unsigned long, t, MAX_PAUSE) ;
}
static long F_92 ( struct V_8 * V_9 ,
long V_152 ,
unsigned long V_138 ,
unsigned long V_136 ,
int * V_153 )
{
long V_154 = F_71 ( V_9 -> V_14 ) ;
long V_155 = F_71 ( V_9 -> V_136 ) ;
long V_84 ;
long V_156 ;
int V_157 ;
V_84 = V_20 ( 1 , V_124 / 100 ) ;
if ( V_154 > V_155 )
V_84 += ( V_154 - V_155 ) * ( 10 * V_124 ) / 1024 ;
V_84 = V_18 ( V_84 , 1 + V_152 / 2 ) ;
V_157 = V_136 * V_84 / F_70 ( V_124 ) ;
if ( V_157 < V_158 ) {
V_84 = V_152 ;
V_157 = V_136 * V_84 / F_70 ( V_124 ) ;
if ( V_157 > V_158 ) {
V_157 = V_158 ;
V_84 = V_124 * V_158 / V_136 ;
}
}
V_156 = V_124 * V_157 / ( V_138 + 1 ) ;
if ( V_156 > V_152 ) {
V_84 = V_152 ;
V_157 = V_138 * V_84 / F_70 ( V_124 ) ;
}
* V_153 = V_157 ;
return V_157 >= V_158 ? 1 + V_84 / 2 : V_84 ;
}
static inline void F_93 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_159 ;
V_2 -> V_101 = F_58 ( V_2 ) ;
V_2 -> V_120 = V_2 -> V_48 ?
F_67 ( ( T_5 ) V_2 -> V_101 * V_2 -> V_49 , V_2 -> V_48 ) : 0 ;
if ( V_2 -> V_101 < 2 * F_94 ( V_9 ) ) {
V_159 = F_95 ( V_9 , V_160 ) ;
V_2 -> V_119 = V_159 + F_95 ( V_9 , V_161 ) ;
} else {
V_159 = F_96 ( V_9 , V_160 ) ;
V_2 -> V_119 = V_159 + F_96 ( V_9 , V_161 ) ;
}
}
static void F_97 ( struct V_162 * V_163 ,
struct V_8 * V_9 ,
unsigned long V_164 )
{
struct V_1 V_165 = { F_61 (wb) } ;
struct V_1 V_166 = { F_98 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_165 ;
struct V_1 * const V_5 = F_1 ( & V_166 ) ?
& V_166 : NULL ;
struct V_1 * V_167 ;
unsigned long V_168 ;
long V_123 ;
long V_156 ;
long V_152 ;
long V_169 ;
int V_153 ;
bool V_170 = false ;
unsigned long V_138 ;
unsigned long V_136 ;
struct V_91 * V_16 = V_9 -> V_16 ;
bool V_171 = V_16 -> V_116 & V_117 ;
unsigned long V_144 = V_80 ;
for (; ; ) {
unsigned long V_133 = V_80 ;
unsigned long V_61 , V_48 , V_49 ;
unsigned long V_172 = 0 ;
unsigned long V_173 = 0 ;
unsigned long V_174 = 0 ;
V_168 = F_16 ( V_63 ) +
F_16 ( V_64 ) ;
V_6 -> V_38 = F_15 () ;
V_6 -> V_61 = V_168 + F_16 ( V_65 ) ;
F_17 ( V_6 ) ;
if ( F_34 ( V_171 ) ) {
F_93 ( V_6 ) ;
V_61 = V_6 -> V_119 ;
V_48 = V_6 -> V_101 ;
V_49 = V_6 -> V_120 ;
} else {
V_61 = V_6 -> V_61 ;
V_48 = V_6 -> V_48 ;
V_49 = V_6 -> V_49 ;
}
if ( V_5 ) {
unsigned long V_96 , V_97 , V_175 ;
F_99 ( V_9 , & V_96 , & V_97 ,
& V_5 -> V_61 , & V_175 ) ;
V_5 -> V_61 += V_175 ;
F_57 ( V_5 , V_96 , V_97 ) ;
F_17 ( V_5 ) ;
if ( F_34 ( V_171 ) ) {
F_93 ( V_5 ) ;
V_172 = V_5 -> V_119 ;
V_173 = V_5 -> V_101 ;
V_174 = V_5 -> V_120 ;
} else {
V_172 = V_5 -> V_61 ;
V_173 = V_5 -> V_48 ;
V_174 = V_5 -> V_49 ;
}
}
if ( V_61 <= F_55 ( V_48 , V_49 ) &&
( ! V_5 ||
V_172 <= F_55 ( V_173 , V_174 ) ) ) {
unsigned long V_176 = F_90 ( V_61 , V_48 ) ;
unsigned long V_177 = V_178 ;
V_53 -> V_179 = V_133 ;
V_53 -> V_180 = 0 ;
if ( V_5 )
V_177 = F_90 ( V_172 , V_173 ) ;
V_53 -> V_153 = V_18 ( V_176 , V_177 ) ;
break;
}
if ( F_34 ( ! F_100 ( V_9 ) ) )
F_101 ( V_9 ) ;
if ( ! V_171 )
F_93 ( V_6 ) ;
V_170 = ( V_6 -> V_119 > V_6 -> V_101 ) &&
( ( V_6 -> V_61 > V_6 -> V_48 ) || V_171 ) ;
F_65 ( V_6 ) ;
V_167 = V_6 ;
if ( V_5 ) {
if ( ! V_171 )
F_93 ( V_5 ) ;
V_170 |= ( V_5 -> V_119 > V_5 -> V_101 ) &&
( ( V_5 -> V_61 > V_5 -> V_48 ) || V_171 ) ;
F_65 ( V_5 ) ;
if ( V_5 -> V_108 < V_6 -> V_108 )
V_167 = V_5 ;
}
if ( V_170 && ! V_9 -> V_170 )
V_9 -> V_170 = 1 ;
if ( F_102 ( V_9 -> V_146 +
V_134 ) ) {
F_78 ( & V_9 -> V_147 ) ;
F_85 ( V_6 , V_5 , V_144 , true ) ;
F_80 ( & V_9 -> V_147 ) ;
}
V_136 = V_9 -> V_136 ;
V_138 = ( ( T_5 ) V_136 * V_167 -> V_108 ) >>
V_110 ;
V_152 = F_91 ( V_9 , V_167 -> V_119 ) ;
V_169 = F_92 ( V_9 , V_152 ,
V_138 , V_136 ,
& V_153 ) ;
if ( F_34 ( V_138 == 0 ) ) {
V_123 = V_152 ;
V_156 = V_152 ;
goto V_156;
}
V_123 = V_124 * V_164 / V_138 ;
V_156 = V_123 ;
if ( V_53 -> V_179 )
V_156 -= V_133 - V_53 -> V_179 ;
if ( V_156 < V_169 ) {
F_103 ( V_9 ,
V_167 -> V_48 ,
V_167 -> V_49 ,
V_167 -> V_61 ,
V_167 -> V_101 ,
V_167 -> V_119 ,
V_136 ,
V_138 ,
V_164 ,
V_123 ,
V_18 ( V_156 , 0L ) ,
V_144 ) ;
if ( V_156 < - V_124 ) {
V_53 -> V_179 = V_133 ;
V_53 -> V_180 = 0 ;
} else if ( V_123 ) {
V_53 -> V_179 += V_123 ;
V_53 -> V_180 = 0 ;
} else if ( V_53 -> V_153 <= V_164 )
V_53 -> V_153 += V_164 ;
break;
}
if ( F_34 ( V_156 > V_152 ) ) {
V_133 += V_18 ( V_156 - V_152 , V_152 ) ;
V_156 = V_152 ;
}
V_156:
F_103 ( V_9 ,
V_167 -> V_48 ,
V_167 -> V_49 ,
V_167 -> V_61 ,
V_167 -> V_101 ,
V_167 -> V_119 ,
V_136 ,
V_138 ,
V_164 ,
V_123 ,
V_156 ,
V_144 ) ;
F_104 ( V_181 ) ;
F_105 ( V_156 ) ;
V_53 -> V_179 = V_133 + V_156 ;
V_53 -> V_180 = 0 ;
V_53 -> V_153 = V_153 ;
if ( V_138 )
break;
if ( V_167 -> V_119 <= F_94 ( V_9 ) )
break;
if ( F_106 ( V_53 ) )
break;
}
if ( ! V_170 && V_9 -> V_170 )
V_9 -> V_170 = 0 ;
if ( F_100 ( V_9 ) )
return;
if ( V_182 )
return;
if ( V_168 > V_6 -> V_49 )
F_101 ( V_9 ) ;
}
void F_107 ( struct V_162 * V_163 )
{
struct V_183 * V_183 = V_163 -> V_184 ;
struct V_91 * V_16 = F_108 ( V_183 ) ;
struct V_8 * V_9 = NULL ;
int V_185 ;
int * V_186 ;
if ( ! F_109 ( V_16 ) )
return;
if ( F_110 ( V_183 ) )
V_9 = F_111 ( V_16 , V_187 ) ;
if ( ! V_9 )
V_9 = & V_16 -> V_9 ;
V_185 = V_53 -> V_153 ;
if ( V_9 -> V_170 )
V_185 = V_18 ( V_185 , 32 >> ( V_188 - 10 ) ) ;
F_112 () ;
V_186 = F_113 ( & V_189 ) ;
if ( F_34 ( V_53 -> V_180 >= V_185 ) )
* V_186 = 0 ;
else if ( F_34 ( * V_186 >= V_190 ) ) {
* V_186 = 0 ;
V_185 = 0 ;
}
V_186 = F_113 ( & V_191 ) ;
if ( * V_186 > 0 && V_53 -> V_180 < V_185 ) {
unsigned long V_192 ;
V_192 = V_18 ( * V_186 , V_185 - V_53 -> V_180 ) ;
* V_186 -= V_192 ;
V_53 -> V_180 += V_192 ;
}
F_114 () ;
if ( F_34 ( V_53 -> V_180 >= V_185 ) )
F_97 ( V_163 , V_9 , V_53 -> V_180 ) ;
F_115 ( V_9 ) ;
}
bool F_116 ( struct V_8 * V_9 )
{
struct V_1 V_165 = { F_61 (wb) } ;
struct V_1 V_166 = { F_98 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_165 ;
struct V_1 * const V_5 = F_1 ( & V_166 ) ?
& V_166 : NULL ;
V_6 -> V_38 = F_15 () ;
V_6 -> V_61 = F_16 ( V_63 ) +
F_16 ( V_64 ) ;
F_17 ( V_6 ) ;
if ( V_6 -> V_61 > V_6 -> V_49 )
return true ;
if ( F_96 ( V_9 , V_160 ) >
F_60 ( V_6 -> V_9 , V_6 -> V_49 ) )
return true ;
if ( V_5 ) {
unsigned long V_96 , V_97 , V_175 ;
F_99 ( V_9 , & V_96 , & V_97 , & V_5 -> V_61 ,
& V_175 ) ;
F_57 ( V_5 , V_96 , V_97 ) ;
F_17 ( V_5 ) ;
if ( V_5 -> V_61 > V_5 -> V_49 )
return true ;
if ( F_96 ( V_9 , V_160 ) >
F_60 ( V_5 -> V_9 , V_5 -> V_49 ) )
return true ;
}
return false ;
}
void F_117 ( T_4 V_193 )
{
unsigned long V_194 ;
unsigned long V_195 ;
for ( ; ; ) {
F_21 ( & V_194 , & V_195 ) ;
V_195 = F_56 ( & V_22 , V_195 ) ;
V_195 += V_195 / 10 ;
if ( F_16 ( V_64 ) +
F_16 ( V_65 ) <= V_195 )
break;
F_118 ( V_196 , V_124 / 10 ) ;
if ( ( V_193 & ( V_197 | V_198 ) ) != ( V_197 | V_198 ) )
break;
}
}
int F_119 ( struct V_66 * V_67 , int V_68 ,
void T_1 * V_69 , T_2 * V_199 , T_3 * V_71 )
{
F_120 ( V_67 , V_68 , V_69 , V_199 , V_71 ) ;
return 0 ;
}
void F_121 ( unsigned long V_89 )
{
struct V_200 * V_201 = (struct V_200 * ) V_89 ;
int V_24 = F_16 ( V_63 ) +
F_16 ( V_64 ) ;
struct V_8 * V_9 ;
if ( ! F_122 ( & V_201 -> V_91 ) )
return;
F_123 () ;
F_124 (wb, &q->backing_dev_info.wb_list, bdi_node)
if ( F_72 ( V_9 ) )
F_125 ( V_9 , V_24 , true ,
V_202 ) ;
F_126 () ;
}
void F_127 ( struct V_91 * V_203 )
{
F_35 ( & V_203 -> V_204 , V_80 + V_182 ) ;
}
void F_128 ( void )
{
struct V_91 * V_16 ;
F_123 () ;
F_124 (bdi, &bdi_list, bdi_list)
F_129 ( & V_16 -> V_204 ) ;
F_126 () ;
}
void F_29 ( void )
{
struct V_4 * V_3 = & V_22 ;
unsigned long V_194 ;
unsigned long V_195 ;
F_21 ( & V_194 , & V_195 ) ;
V_3 -> V_56 = V_195 ;
V_190 = V_195 / ( F_130 () * 32 ) ;
if ( V_190 < 16 )
V_190 = 16 ;
}
static int
F_131 ( struct V_205 * V_206 , unsigned long V_207 ,
void * V_208 )
{
switch ( V_207 & ~ V_209 ) {
case V_210 :
case V_211 :
F_29 () ;
return V_212 ;
default:
return V_213 ;
}
}
void T_6 F_132 ( void )
{
F_133 ( F_44 ( & V_22 , V_187 ) ) ;
F_29 () ;
F_134 ( & V_214 ) ;
}
void F_135 ( struct V_162 * V_163 ,
T_7 V_215 , T_7 V_216 )
{
#define F_136 4096
unsigned long V_217 ;
do {
F_137 ( & V_163 -> V_218 ) ;
V_217 = F_138 ( & V_163 -> V_219 ,
& V_215 , V_216 , F_136 ,
V_220 , V_221 ) ;
F_139 ( & V_163 -> V_218 ) ;
F_73 ( V_217 > F_136 ) ;
F_140 () ;
} while ( V_217 >= F_136 && V_215 );
}
int F_141 ( struct V_162 * V_163 ,
struct V_222 * V_223 , T_8 V_224 ,
void * V_89 )
{
int V_72 = 0 ;
int V_225 = 0 ;
struct V_226 V_227 ;
int V_24 ;
T_7 V_228 ( V_229 ) ;
T_7 V_230 ;
T_7 V_216 ;
T_7 V_231 ;
int V_232 ;
int V_233 = 0 ;
int V_234 ;
F_142 ( & V_227 , 0 ) ;
if ( V_223 -> V_235 ) {
V_229 = V_163 -> V_229 ;
V_230 = V_229 ;
if ( V_230 == 0 )
V_232 = 1 ;
else
V_232 = 0 ;
V_216 = - 1 ;
} else {
V_230 = V_223 -> V_236 >> V_188 ;
V_216 = V_223 -> V_237 >> V_188 ;
if ( V_223 -> V_236 == 0 && V_223 -> V_237 == V_238 )
V_233 = 1 ;
V_232 = 1 ;
}
if ( V_223 -> V_239 == V_240 || V_223 -> V_241 )
V_234 = V_221 ;
else
V_234 = V_220 ;
V_242:
if ( V_223 -> V_239 == V_240 || V_223 -> V_241 )
F_135 ( V_163 , V_230 , V_216 ) ;
V_231 = V_230 ;
while ( ! V_225 && ( V_230 <= V_216 ) ) {
int V_32 ;
V_24 = F_143 ( & V_227 , V_163 , & V_230 , V_234 ,
V_18 ( V_216 - V_230 , ( T_7 ) V_243 - 1 ) + 1 ) ;
if ( V_24 == 0 )
break;
for ( V_32 = 0 ; V_32 < V_24 ; V_32 ++ ) {
struct V_244 * V_244 = V_227 . V_157 [ V_32 ] ;
if ( V_244 -> V_230 > V_216 ) {
V_225 = 1 ;
break;
}
V_231 = V_244 -> V_230 ;
F_144 ( V_244 ) ;
if ( F_34 ( V_244 -> V_163 != V_163 ) ) {
V_245:
F_145 ( V_244 ) ;
continue;
}
if ( ! F_146 ( V_244 ) ) {
goto V_245;
}
if ( F_147 ( V_244 ) ) {
if ( V_223 -> V_239 != V_246 )
F_148 ( V_244 ) ;
else
goto V_245;
}
F_133 ( F_147 ( V_244 ) ) ;
if ( ! F_149 ( V_244 ) )
goto V_245;
F_150 ( V_223 , F_108 ( V_163 -> V_184 ) ) ;
V_72 = (* V_224)( V_244 , V_223 , V_89 ) ;
if ( F_34 ( V_72 ) ) {
if ( V_72 == V_247 ) {
F_145 ( V_244 ) ;
V_72 = 0 ;
} else {
V_231 = V_244 -> V_230 + 1 ;
V_225 = 1 ;
break;
}
}
if ( -- V_223 -> V_248 <= 0 &&
V_223 -> V_239 == V_246 ) {
V_225 = 1 ;
break;
}
}
F_151 ( & V_227 ) ;
F_140 () ;
}
if ( ! V_232 && ! V_225 ) {
V_232 = 1 ;
V_230 = 0 ;
V_216 = V_229 - 1 ;
goto V_242;
}
if ( V_223 -> V_235 || ( V_233 && V_223 -> V_248 > 0 ) )
V_163 -> V_229 = V_231 ;
return V_72 ;
}
static int F_152 ( struct V_244 * V_244 , struct V_222 * V_223 ,
void * V_89 )
{
struct V_162 * V_163 = V_89 ;
int V_72 = V_163 -> V_249 -> V_224 ( V_244 , V_223 ) ;
F_153 ( V_163 , V_72 ) ;
return V_72 ;
}
int F_154 ( struct V_162 * V_163 ,
struct V_222 * V_223 )
{
struct V_250 V_251 ;
int V_72 ;
if ( ! V_163 -> V_249 -> V_224 )
return 0 ;
F_155 ( & V_251 ) ;
V_72 = F_141 ( V_163 , V_223 , F_152 , V_163 ) ;
F_156 ( & V_251 ) ;
return V_72 ;
}
int F_157 ( struct V_162 * V_163 , struct V_222 * V_223 )
{
int V_72 ;
if ( V_223 -> V_248 <= 0 )
return 0 ;
if ( V_163 -> V_249 -> V_252 )
V_72 = V_163 -> V_249 -> V_252 ( V_163 , V_223 ) ;
else
V_72 = F_154 ( V_163 , V_223 ) ;
return V_72 ;
}
int F_158 ( struct V_244 * V_244 , int V_253 )
{
struct V_162 * V_163 = V_244 -> V_163 ;
int V_72 = 0 ;
struct V_222 V_223 = {
. V_239 = V_240 ,
. V_248 = 1 ,
} ;
F_133 ( ! F_159 ( V_244 ) ) ;
if ( V_253 )
F_148 ( V_244 ) ;
if ( F_149 ( V_244 ) ) {
F_160 ( V_244 ) ;
V_72 = V_163 -> V_249 -> V_224 ( V_244 , & V_223 ) ;
if ( V_72 == 0 && V_253 ) {
F_148 ( V_244 ) ;
if ( F_161 ( V_244 ) )
V_72 = - V_254 ;
}
F_162 ( V_244 ) ;
} else {
F_145 ( V_244 ) ;
}
return V_72 ;
}
int F_163 ( struct V_244 * V_244 )
{
if ( ! F_146 ( V_244 ) )
return ! F_164 ( V_244 ) ;
return 0 ;
}
void F_165 ( struct V_244 * V_244 , struct V_162 * V_163 )
{
struct V_183 * V_183 = V_163 -> V_184 ;
F_166 ( V_244 , V_163 ) ;
if ( F_167 ( V_163 ) ) {
struct V_8 * V_9 ;
F_168 ( V_183 , V_244 ) ;
V_9 = F_169 ( V_183 ) ;
F_170 ( V_244 , V_255 ) ;
F_171 ( V_244 , V_63 ) ;
F_171 ( V_244 , V_256 ) ;
F_37 ( V_9 , V_160 ) ;
F_37 ( V_9 , V_149 ) ;
F_172 ( V_45 ) ;
V_53 -> V_180 ++ ;
F_173 ( V_189 ) ;
}
}
void F_174 ( struct V_244 * V_244 , struct V_162 * V_163 ,
struct V_8 * V_9 )
{
if ( F_167 ( V_163 ) ) {
F_175 ( V_244 , V_255 ) ;
F_176 ( V_244 , V_63 ) ;
F_177 ( V_9 , V_160 ) ;
F_178 ( V_45 ) ;
}
}
int F_179 ( struct V_244 * V_244 )
{
F_180 ( V_244 ) ;
if ( ! F_164 ( V_244 ) ) {
struct V_162 * V_163 = F_181 ( V_244 ) ;
unsigned long V_54 ;
if ( ! V_163 ) {
F_182 ( V_244 ) ;
return 1 ;
}
F_183 ( & V_163 -> V_218 , V_54 ) ;
F_133 ( F_181 ( V_244 ) != V_163 ) ;
F_73 ( ! F_184 ( V_244 ) && ! F_185 ( V_244 ) ) ;
F_165 ( V_244 , V_163 ) ;
F_186 ( & V_163 -> V_219 , F_187 ( V_244 ) ,
V_220 ) ;
F_188 ( & V_163 -> V_218 , V_54 ) ;
F_182 ( V_244 ) ;
if ( V_163 -> V_184 ) {
F_189 ( V_163 -> V_184 , V_257 ) ;
}
return 1 ;
}
F_182 ( V_244 ) ;
return 0 ;
}
void F_190 ( struct V_244 * V_244 )
{
struct V_162 * V_163 = V_244 -> V_163 ;
if ( V_163 && F_167 ( V_163 ) ) {
struct V_183 * V_183 = V_163 -> V_184 ;
struct V_8 * V_9 ;
bool V_258 ;
V_9 = F_191 ( V_183 , & V_258 ) ;
V_53 -> V_180 -- ;
F_176 ( V_244 , V_256 ) ;
F_177 ( V_9 , V_149 ) ;
F_192 ( V_183 , V_258 ) ;
}
}
int F_193 ( struct V_222 * V_223 , struct V_244 * V_244 )
{
int V_72 ;
V_223 -> V_259 ++ ;
V_72 = F_179 ( V_244 ) ;
F_190 ( V_244 ) ;
return V_72 ;
}
int F_194 ( struct V_244 * V_244 )
{
struct V_162 * V_163 = F_181 ( V_244 ) ;
if ( F_195 ( V_163 ) ) {
int (* F_196)( struct V_244 * ) = V_163 -> V_249 -> F_194 ;
if ( F_197 ( V_244 ) )
F_198 ( V_244 ) ;
#ifdef F_199
if ( ! F_196 )
F_196 = V_260 ;
#endif
return (* F_196)( V_244 ) ;
}
if ( ! F_146 ( V_244 ) ) {
if ( ! F_164 ( V_244 ) )
return 1 ;
}
return 0 ;
}
int F_200 ( struct V_244 * V_244 )
{
int V_72 ;
F_144 ( V_244 ) ;
V_72 = F_194 ( V_244 ) ;
F_145 ( V_244 ) ;
return V_72 ;
}
void F_201 ( struct V_244 * V_244 )
{
struct V_162 * V_163 = F_181 ( V_244 ) ;
if ( F_167 ( V_163 ) ) {
struct V_183 * V_183 = V_163 -> V_184 ;
struct V_8 * V_9 ;
bool V_258 ;
F_180 ( V_244 ) ;
V_9 = F_191 ( V_183 , & V_258 ) ;
if ( F_202 ( V_244 ) )
F_174 ( V_244 , V_163 , V_9 ) ;
F_192 ( V_183 , V_258 ) ;
F_182 ( V_244 ) ;
} else {
F_203 ( V_244 ) ;
}
}
int F_149 ( struct V_244 * V_244 )
{
struct V_162 * V_163 = F_181 ( V_244 ) ;
int V_72 = 0 ;
F_133 ( ! F_159 ( V_244 ) ) ;
if ( V_163 && F_167 ( V_163 ) ) {
struct V_183 * V_183 = V_163 -> V_184 ;
struct V_8 * V_9 ;
bool V_258 ;
if ( F_204 ( V_244 ) )
F_194 ( V_244 ) ;
V_9 = F_191 ( V_183 , & V_258 ) ;
if ( F_202 ( V_244 ) ) {
F_175 ( V_244 , V_255 ) ;
F_176 ( V_244 , V_63 ) ;
F_177 ( V_9 , V_160 ) ;
V_72 = 1 ;
}
F_192 ( V_183 , V_258 ) ;
return V_72 ;
}
return F_202 ( V_244 ) ;
}
int F_205 ( struct V_244 * V_244 )
{
struct V_162 * V_163 = F_181 ( V_244 ) ;
int V_72 ;
F_180 ( V_244 ) ;
if ( V_163 ) {
struct V_183 * V_183 = V_163 -> V_184 ;
struct V_91 * V_16 = F_108 ( V_183 ) ;
unsigned long V_54 ;
F_183 ( & V_163 -> V_218 , V_54 ) ;
V_72 = F_206 ( V_244 ) ;
if ( V_72 ) {
F_207 ( & V_163 -> V_219 ,
F_187 ( V_244 ) ,
V_261 ) ;
if ( F_208 ( V_16 ) ) {
struct V_8 * V_9 = F_169 ( V_183 ) ;
F_209 ( V_9 , V_161 ) ;
F_36 ( V_9 ) ;
}
}
F_188 ( & V_163 -> V_218 , V_54 ) ;
} else {
V_72 = F_206 ( V_244 ) ;
}
if ( V_72 ) {
F_175 ( V_244 , V_262 ) ;
F_176 ( V_244 , V_65 ) ;
F_210 ( V_244 , V_263 ) ;
}
F_182 ( V_244 ) ;
return V_72 ;
}
int F_211 ( struct V_244 * V_244 , bool V_264 )
{
struct V_162 * V_163 = F_181 ( V_244 ) ;
int V_72 ;
F_180 ( V_244 ) ;
if ( V_163 ) {
struct V_183 * V_183 = V_163 -> V_184 ;
struct V_91 * V_16 = F_108 ( V_183 ) ;
unsigned long V_54 ;
F_183 ( & V_163 -> V_218 , V_54 ) ;
V_72 = F_212 ( V_244 ) ;
if ( ! V_72 ) {
F_186 ( & V_163 -> V_219 ,
F_187 ( V_244 ) ,
V_261 ) ;
if ( F_208 ( V_16 ) )
F_37 ( F_169 ( V_183 ) , V_161 ) ;
}
if ( ! F_146 ( V_244 ) )
F_207 ( & V_163 -> V_219 ,
F_187 ( V_244 ) ,
V_220 ) ;
if ( ! V_264 )
F_207 ( & V_163 -> V_219 ,
F_187 ( V_244 ) ,
V_221 ) ;
F_188 ( & V_163 -> V_218 , V_54 ) ;
} else {
V_72 = F_212 ( V_244 ) ;
}
if ( ! V_72 ) {
F_170 ( V_244 , V_262 ) ;
F_210 ( V_244 , V_65 ) ;
}
F_182 ( V_244 ) ;
return V_72 ;
}
int F_213 ( struct V_162 * V_163 , int V_234 )
{
return F_214 ( & V_163 -> V_219 , V_234 ) ;
}
void F_215 ( struct V_244 * V_244 )
{
if ( F_216 ( F_108 ( V_244 -> V_163 -> V_184 ) ) )
F_148 ( V_244 ) ;
}
