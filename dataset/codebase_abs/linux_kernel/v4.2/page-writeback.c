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
F_12 (node, N_HIGH_MEMORY) {
struct V_23 * V_32 = & F_13 ( V_30 ) -> V_33 [ V_34 ] ;
V_31 += F_8 ( V_32 ) ;
}
if ( ( long ) V_31 < 0 )
V_31 = 0 ;
return V_18 ( V_31 , V_29 ) ;
#else
return 0 ;
#endif
}
static unsigned long F_14 ( void )
{
unsigned long V_31 ;
V_31 = F_15 ( V_25 ) ;
V_31 -= V_18 ( V_31 , V_26 ) ;
V_31 += F_15 ( V_27 ) ;
V_31 += F_15 ( V_28 ) ;
if ( ! V_35 )
V_31 -= F_10 ( V_31 ) ;
return V_31 + 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
const unsigned long V_36 = V_2 -> V_37 ;
struct V_1 * V_6 = F_3 ( V_2 ) ;
unsigned long V_38 = V_39 ;
unsigned long V_40 = V_41 ;
unsigned long V_42 = V_43 ;
unsigned long V_44 = V_45 ;
unsigned long V_46 ;
unsigned long V_47 ;
struct V_48 * V_49 ;
if ( V_6 ) {
unsigned long V_50 = V_6 -> V_37 ;
if ( V_38 )
V_42 = V_18 ( F_17 ( V_38 , V_51 ) * 100 /
V_50 , 100UL ) ;
if ( V_40 )
V_44 = V_18 ( F_17 ( V_40 , V_51 ) * 100 /
V_50 , 100UL ) ;
V_38 = V_40 = 0 ;
}
if ( V_38 )
V_46 = F_17 ( V_38 , V_51 ) ;
else
V_46 = ( V_42 * V_36 ) / 100 ;
if ( V_40 )
V_47 = F_17 ( V_40 , V_51 ) ;
else
V_47 = ( V_44 * V_36 ) / 100 ;
if ( V_47 >= V_46 )
V_47 = V_46 / 2 ;
V_49 = V_52 ;
if ( V_49 -> V_53 & V_54 || F_18 ( V_49 ) ) {
V_47 += V_47 / 4 ;
V_46 += V_46 / 4 ;
}
V_2 -> V_46 = V_46 ;
V_2 -> V_47 = V_47 ;
if ( ! V_6 )
F_19 ( V_47 , V_46 ) ;
}
void F_20 ( unsigned long * V_55 , unsigned long * V_56 )
{
struct V_1 V_6 = { V_57 } ;
V_6 . V_37 = F_14 () ;
F_16 ( & V_6 ) ;
* V_55 = V_6 . V_47 ;
* V_56 = V_6 . V_46 ;
}
static unsigned long F_21 ( struct V_23 * V_23 )
{
unsigned long V_58 = F_8 ( V_23 ) ;
struct V_48 * V_49 = V_52 ;
unsigned long V_59 ;
if ( V_39 )
V_59 = F_17 ( V_39 , V_51 ) *
V_58 / F_14 () ;
else
V_59 = V_43 * V_58 / 100 ;
if ( V_49 -> V_53 & V_54 || F_18 ( V_49 ) )
V_59 += V_59 / 4 ;
return V_59 ;
}
bool F_22 ( struct V_23 * V_23 )
{
unsigned long V_60 = F_21 ( V_23 ) ;
return F_9 ( V_23 , V_61 ) +
F_9 ( V_23 , V_62 ) +
F_9 ( V_23 , V_63 ) <= V_60 ;
}
int F_23 ( struct V_64 * V_65 , int V_66 ,
void T_1 * V_67 , T_2 * V_68 ,
T_3 * V_69 )
{
int V_70 ;
V_70 = F_24 ( V_65 , V_66 , V_67 , V_68 , V_69 ) ;
if ( V_70 == 0 && V_66 )
V_41 = 0 ;
return V_70 ;
}
int F_25 ( struct V_64 * V_65 , int V_66 ,
void T_1 * V_67 , T_2 * V_68 ,
T_3 * V_69 )
{
int V_70 ;
V_70 = F_26 ( V_65 , V_66 , V_67 , V_68 , V_69 ) ;
if ( V_70 == 0 && V_66 )
V_45 = 0 ;
return V_70 ;
}
int F_27 ( struct V_64 * V_65 , int V_66 ,
void T_1 * V_67 , T_2 * V_68 ,
T_3 * V_69 )
{
int V_71 = V_43 ;
int V_70 ;
V_70 = F_24 ( V_65 , V_66 , V_67 , V_68 , V_69 ) ;
if ( V_70 == 0 && V_66 && V_43 != V_71 ) {
F_28 () ;
V_39 = 0 ;
}
return V_70 ;
}
int F_29 ( struct V_64 * V_65 , int V_66 ,
void T_1 * V_67 , T_2 * V_68 ,
T_3 * V_69 )
{
unsigned long V_72 = V_39 ;
int V_70 ;
V_70 = F_26 ( V_65 , V_66 , V_67 , V_68 , V_69 ) ;
if ( V_70 == 0 && V_66 && V_39 != V_72 ) {
F_28 () ;
V_43 = 0 ;
}
return V_70 ;
}
static unsigned long F_30 ( unsigned long V_73 )
{
V_73 += V_74 ;
if ( ! V_73 )
return 1 ;
return V_73 ;
}
static void F_31 ( struct V_4 * V_3 ,
struct V_7 * V_75 ,
unsigned int V_76 )
{
F_32 ( & V_3 -> V_75 , V_75 ,
V_76 ) ;
if ( ! F_33 ( V_3 -> V_77 ) ) {
V_3 -> V_77 = F_30 ( V_78 ) ;
F_34 ( & V_3 -> V_79 , V_3 -> V_77 ) ;
}
}
static inline void F_35 ( struct V_8 * V_9 )
{
struct V_4 * V_80 ;
F_36 ( V_9 , V_81 ) ;
F_31 ( & V_22 , & V_9 -> V_75 ,
V_9 -> V_16 -> V_76 ) ;
V_80 = F_37 ( V_9 ) ;
if ( V_80 )
F_31 ( V_80 , F_4 ( V_9 ) ,
V_9 -> V_16 -> V_76 ) ;
}
void F_38 ( struct V_8 * V_9 )
{
unsigned long V_53 ;
F_39 ( V_53 ) ;
F_35 ( V_9 ) ;
F_40 ( V_53 ) ;
}
static void F_41 ( unsigned long V_82 )
{
struct V_4 * V_3 = ( void * ) V_82 ;
int V_83 = ( V_78 - V_3 -> V_77 ) /
V_74 ;
if ( F_42 ( & V_3 -> V_75 , V_83 + 1 ) ) {
V_3 -> V_77 = F_30 ( V_3 -> V_77 +
V_83 * V_74 ) ;
F_34 ( & V_3 -> V_79 , V_3 -> V_77 ) ;
} else {
V_3 -> V_77 = 0 ;
}
}
int F_43 ( struct V_4 * V_3 , T_4 V_84 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_44 ( & V_3 -> V_85 ) ;
F_45 ( & V_3 -> V_79 ) ;
V_3 -> V_79 . V_86 = F_41 ;
V_3 -> V_79 . V_87 = ( unsigned long ) V_3 ;
V_3 -> V_88 = V_78 ;
return F_46 ( & V_3 -> V_75 , V_84 ) ;
}
void F_47 ( struct V_4 * V_3 )
{
F_48 ( & V_3 -> V_79 ) ;
F_49 ( & V_3 -> V_75 ) ;
}
int F_50 ( struct V_89 * V_16 , unsigned int V_19 )
{
int V_70 = 0 ;
F_51 ( & V_90 ) ;
if ( V_19 > V_16 -> V_21 ) {
V_70 = - V_91 ;
} else {
V_19 -= V_16 -> V_19 ;
if ( V_92 + V_19 < 100 ) {
V_92 += V_19 ;
V_16 -> V_19 += V_19 ;
} else {
V_70 = - V_91 ;
}
}
F_52 ( & V_90 ) ;
return V_70 ;
}
int F_53 ( struct V_89 * V_16 , unsigned V_21 )
{
int V_70 = 0 ;
if ( V_21 > 100 )
return - V_91 ;
F_51 ( & V_90 ) ;
if ( V_16 -> V_19 > V_21 ) {
V_70 = - V_91 ;
} else {
V_16 -> V_21 = V_21 ;
V_16 -> V_76 = ( V_93 * V_21 ) / 100 ;
}
F_52 ( & V_90 ) ;
return V_70 ;
}
static unsigned long F_54 ( unsigned long V_46 ,
unsigned long V_47 )
{
return ( V_46 + V_47 ) / 2 ;
}
static unsigned long F_55 ( struct V_4 * V_3 ,
unsigned long V_46 )
{
return V_20 ( V_46 , V_3 -> V_94 ) ;
}
static void F_56 ( struct V_1 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_95 = V_6 -> V_37 - V_18 ( V_6 -> V_37 , V_6 -> V_59 ) ;
V_5 -> V_37 = V_18 ( V_5 -> V_37 , V_95 ) ;
}
static unsigned long F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_46 = V_2 -> V_46 ;
T_5 V_96 ;
long V_97 , V_98 ;
unsigned long V_99 , V_100 ;
F_58 ( & V_3 -> V_75 , V_2 -> V_101 ,
& V_97 , & V_98 ) ;
V_96 = ( V_46 * ( 100 - V_92 ) ) / 100 ;
V_96 *= V_97 ;
F_7 ( V_96 , V_98 ) ;
F_5 ( V_2 -> V_9 , & V_99 , & V_100 ) ;
V_96 += ( V_46 * V_99 ) / 100 ;
if ( V_96 > ( V_46 * V_100 ) / 100 )
V_96 = V_46 * V_100 / 100 ;
return V_96 ;
}
unsigned long F_59 ( struct V_8 * V_9 , unsigned long V_46 )
{
struct V_1 V_6 = { F_60 ( V_9 ) ,
. V_46 = V_46 } ;
return F_57 ( & V_6 ) ;
}
static long long F_61 ( unsigned long V_102 ,
unsigned long V_59 ,
unsigned long V_60 )
{
long long V_103 ;
long V_31 ;
V_31 = F_62 ( ( ( V_104 ) V_102 - ( V_104 ) V_59 ) << V_105 ,
( V_60 - V_102 ) | 1 ) ;
V_103 = V_31 ;
V_103 = V_103 * V_31 >> V_105 ;
V_103 = V_103 * V_31 >> V_105 ;
V_103 += 1 << V_105 ;
return F_63 ( V_103 , 0LL , 2LL << V_105 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_106 = V_9 -> V_14 ;
unsigned long V_107 = F_54 ( V_2 -> V_46 , V_2 -> V_47 ) ;
unsigned long V_60 = F_55 ( F_2 ( V_2 ) , V_2 -> V_46 ) ;
unsigned long V_96 = V_2 -> V_96 ;
unsigned long V_108 ;
unsigned long V_102 ;
unsigned long V_109 ;
unsigned long V_110 ;
long long V_103 ;
long V_31 ;
V_2 -> V_103 = 0 ;
if ( F_33 ( V_2 -> V_59 >= V_60 ) )
return;
V_102 = ( V_107 + V_60 ) / 2 ;
V_103 = F_61 ( V_102 , V_2 -> V_59 , V_60 ) ;
if ( F_33 ( V_9 -> V_16 -> V_111 & V_112 ) ) {
long long V_113 ;
if ( V_2 -> V_114 < 8 ) {
V_2 -> V_103 = F_65 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
return;
}
if ( V_2 -> V_114 >= V_96 )
return;
V_109 = F_54 ( V_96 ,
V_2 -> V_115 ) ;
if ( V_109 == 0 || V_109 == V_96 )
return;
V_113 = F_61 ( V_109 , V_2 -> V_114 ,
V_96 ) ;
V_2 -> V_103 = V_18 ( V_103 , V_113 ) ;
return;
}
if ( F_33 ( V_96 > V_2 -> V_46 ) )
V_96 = V_2 -> V_46 ;
V_96 = V_20 ( V_96 , ( V_60 - V_2 -> V_59 ) / 8 ) ;
V_31 = F_66 ( ( T_5 ) V_96 << 16 , V_2 -> V_46 | 1 ) ;
V_109 = V_102 * ( T_5 ) V_31 >> 16 ;
V_110 = ( V_2 -> V_46 - V_96 + 8 * V_106 ) * ( T_5 ) V_31 >> 16 ;
V_108 = V_109 + V_110 ;
if ( V_2 -> V_114 < V_108 - V_110 / 4 ) {
V_103 = F_67 ( V_103 * ( V_108 - V_2 -> V_114 ) ,
( V_108 - V_109 ) | 1 ) ;
} else
V_103 /= 4 ;
V_108 = V_96 / 2 ;
if ( V_2 -> V_114 < V_108 ) {
if ( V_2 -> V_114 > V_108 / 8 )
V_103 = F_66 ( V_103 * V_108 ,
V_2 -> V_114 ) ;
else
V_103 *= 8 ;
}
V_2 -> V_103 = V_103 ;
}
static void F_68 ( struct V_8 * V_9 ,
unsigned long V_116 ,
unsigned long V_117 )
{
const unsigned long V_118 = F_69 ( 3 * V_119 ) ;
unsigned long V_120 = V_9 -> V_14 ;
unsigned long V_121 = V_9 -> V_122 ;
T_5 V_123 ;
V_123 = V_117 - V_18 ( V_117 , V_9 -> V_124 ) ;
V_123 *= V_119 ;
if ( F_33 ( V_116 > V_118 ) ) {
F_7 ( V_123 , V_116 ) ;
V_120 = V_123 ;
goto V_125;
}
V_123 += ( T_5 ) V_9 -> V_122 * ( V_118 - V_116 ) ;
V_123 >>= F_70 ( V_118 ) ;
if ( V_120 > V_121 && V_121 >= ( unsigned long ) V_123 )
V_120 -= ( V_120 - V_121 ) >> 3 ;
if ( V_120 < V_121 && V_121 <= ( unsigned long ) V_123 )
V_120 += ( V_121 - V_120 ) >> 3 ;
V_125:
V_120 = V_20 ( V_120 , 1LU ) ;
if ( F_71 ( V_9 ) ) {
long V_126 = V_120 - V_9 -> V_14 ;
F_72 ( F_73 ( V_126 ,
& V_9 -> V_16 -> V_17 ) <= 0 ) ;
}
V_9 -> V_122 = V_123 ;
V_9 -> V_14 = V_120 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_46 = V_2 -> V_46 ;
unsigned long V_60 = V_3 -> V_94 ;
if ( V_60 < V_46 ) {
V_60 = V_46 ;
goto V_127;
}
V_46 = V_20 ( V_46 , V_2 -> V_59 ) ;
if ( V_60 > V_46 ) {
V_60 -= ( V_60 - V_46 ) >> 5 ;
goto V_127;
}
return;
V_127:
V_3 -> V_94 = V_60 ;
}
static void F_75 ( struct V_1 * V_2 ,
unsigned long V_128 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
if ( F_76 ( V_128 , V_3 -> V_88 + V_129 ) )
return;
F_77 ( & V_3 -> V_85 ) ;
if ( F_78 ( V_128 , V_3 -> V_88 + V_129 ) ) {
F_74 ( V_2 ) ;
V_3 -> V_88 = V_128 ;
}
F_79 ( & V_3 -> V_85 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
unsigned long V_130 ,
unsigned long V_116 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_59 = V_2 -> V_59 ;
unsigned long V_107 = F_54 ( V_2 -> V_46 , V_2 -> V_47 ) ;
unsigned long V_60 = F_55 ( F_2 ( V_2 ) , V_2 -> V_46 ) ;
unsigned long V_102 = ( V_107 + V_60 ) / 2 ;
unsigned long V_106 = V_9 -> V_14 ;
unsigned long V_131 = V_9 -> V_131 ;
unsigned long V_132 ;
unsigned long V_133 ;
unsigned long V_134 ;
unsigned long V_135 ;
unsigned long V_31 ;
V_132 = ( V_130 - V_9 -> V_136 ) * V_119 / V_116 ;
V_133 = ( T_5 ) V_131 *
V_2 -> V_103 >> V_105 ;
V_133 ++ ;
V_134 = F_66 ( ( T_5 ) V_133 * V_106 ,
V_132 | 1 ) ;
if ( F_33 ( V_134 > V_106 ) )
V_134 = V_106 ;
V_135 = 0 ;
if ( F_33 ( V_9 -> V_16 -> V_111 & V_112 ) ) {
V_59 = V_2 -> V_114 ;
if ( V_2 -> V_114 < 8 )
V_102 = V_2 -> V_114 + 1 ;
else
V_102 = ( V_2 -> V_96 + V_2 -> V_115 ) / 2 ;
}
if ( V_59 < V_102 ) {
V_31 = F_81 ( V_9 -> V_134 ,
V_134 , V_133 ) ;
if ( V_131 < V_31 )
V_135 = V_31 - V_131 ;
} else {
V_31 = F_82 ( V_9 -> V_134 ,
V_134 , V_133 ) ;
if ( V_131 > V_31 )
V_135 = V_131 - V_31 ;
}
V_135 >>= V_131 / ( 2 * V_135 + 1 ) ;
V_135 = ( V_135 + 7 ) / 8 ;
if ( V_131 < V_134 )
V_131 += V_135 ;
else
V_131 -= V_135 ;
V_9 -> V_131 = V_20 ( V_131 , 1UL ) ;
V_9 -> V_134 = V_134 ;
F_83 ( V_9 -> V_16 , V_132 , V_133 ) ;
}
static void F_84 ( struct V_1 * V_6 ,
struct V_1 * V_5 ,
unsigned long V_137 ,
bool V_138 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned long V_128 = V_78 ;
unsigned long V_116 = V_128 - V_9 -> V_139 ;
unsigned long V_130 ;
unsigned long V_117 ;
F_85 ( & V_9 -> V_140 ) ;
if ( V_116 < V_129 )
return;
V_130 = F_86 ( & V_9 -> V_141 [ V_142 ] ) ;
V_117 = F_86 ( & V_9 -> V_141 [ V_81 ] ) ;
if ( V_116 > V_119 && F_76 ( V_9 -> V_139 , V_137 ) )
goto V_143;
if ( V_138 ) {
F_75 ( V_6 , V_128 ) ;
F_80 ( V_6 , V_130 , V_116 ) ;
if ( F_87 ( V_144 ) && V_5 ) {
F_75 ( V_5 , V_128 ) ;
F_80 ( V_5 , V_130 , V_116 ) ;
}
}
F_68 ( V_9 , V_116 , V_117 ) ;
V_143:
V_9 -> V_136 = V_130 ;
V_9 -> V_124 = V_117 ;
V_9 -> V_139 = V_128 ;
}
void F_88 ( struct V_8 * V_9 , unsigned long V_137 )
{
struct V_1 V_6 = { F_60 (wb) } ;
F_84 ( & V_6 , NULL , V_137 , false ) ;
}
static unsigned long F_89 ( unsigned long V_59 ,
unsigned long V_46 )
{
if ( V_46 > V_59 )
return 1UL << ( F_70 ( V_46 - V_59 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_90 ( struct V_8 * V_9 ,
unsigned long V_114 )
{
unsigned long V_123 = V_9 -> V_14 ;
unsigned long V_82 ;
V_82 = V_114 / ( 1 + V_123 / F_69 ( 1 + V_119 / 8 ) ) ;
V_82 ++ ;
return F_65 (unsigned long, t, MAX_PAUSE) ;
}
static long F_91 ( struct V_8 * V_9 ,
long V_145 ,
unsigned long V_133 ,
unsigned long V_131 ,
int * V_146 )
{
long V_147 = F_70 ( V_9 -> V_14 ) ;
long V_148 = F_70 ( V_9 -> V_131 ) ;
long V_82 ;
long V_149 ;
int V_150 ;
V_82 = V_20 ( 1 , V_119 / 100 ) ;
if ( V_147 > V_148 )
V_82 += ( V_147 - V_148 ) * ( 10 * V_119 ) / 1024 ;
V_82 = V_18 ( V_82 , 1 + V_145 / 2 ) ;
V_150 = V_131 * V_82 / F_69 ( V_119 ) ;
if ( V_150 < V_151 ) {
V_82 = V_145 ;
V_150 = V_131 * V_82 / F_69 ( V_119 ) ;
if ( V_150 > V_151 ) {
V_150 = V_151 ;
V_82 = V_119 * V_151 / V_131 ;
}
}
V_149 = V_119 * V_150 / ( V_133 + 1 ) ;
if ( V_149 > V_145 ) {
V_82 = V_145 ;
V_150 = V_133 * V_82 / F_69 ( V_119 ) ;
}
* V_146 = V_150 ;
return V_150 >= V_151 ? 1 + V_82 / 2 : V_82 ;
}
static inline void F_92 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_152 ;
V_2 -> V_96 = F_57 ( V_2 ) ;
V_2 -> V_115 = V_2 -> V_46 ?
F_66 ( ( T_5 ) V_2 -> V_96 * V_2 -> V_47 , V_2 -> V_46 ) : 0 ;
if ( V_2 -> V_96 < 2 * F_93 ( V_9 ) ) {
V_152 = F_94 ( V_9 , V_153 ) ;
V_2 -> V_114 = V_152 + F_94 ( V_9 , V_154 ) ;
} else {
V_152 = F_95 ( V_9 , V_153 ) ;
V_2 -> V_114 = V_152 + F_95 ( V_9 , V_154 ) ;
}
}
static void F_96 ( struct V_155 * V_156 ,
struct V_8 * V_9 ,
unsigned long V_157 )
{
struct V_1 V_158 = { F_60 (wb) } ;
struct V_1 V_159 = { F_97 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_158 ;
struct V_1 * const V_5 = F_1 ( & V_159 ) ?
& V_159 : NULL ;
struct V_1 * V_160 ;
unsigned long V_161 ;
long V_118 ;
long V_149 ;
long V_145 ;
long V_162 ;
int V_146 ;
bool V_163 = false ;
unsigned long V_133 ;
unsigned long V_131 ;
struct V_89 * V_16 = V_9 -> V_16 ;
bool V_164 = V_16 -> V_111 & V_112 ;
unsigned long V_137 = V_78 ;
for (; ; ) {
unsigned long V_128 = V_78 ;
unsigned long V_59 , V_46 , V_47 ;
unsigned long V_165 , V_166 , V_167 ;
V_161 = F_15 ( V_61 ) +
F_15 ( V_62 ) ;
V_6 -> V_37 = F_14 () ;
V_6 -> V_59 = V_161 + F_15 ( V_63 ) ;
F_16 ( V_6 ) ;
if ( F_33 ( V_164 ) ) {
F_92 ( V_6 ) ;
V_59 = V_6 -> V_114 ;
V_46 = V_6 -> V_96 ;
V_47 = V_6 -> V_115 ;
} else {
V_59 = V_6 -> V_59 ;
V_46 = V_6 -> V_46 ;
V_47 = V_6 -> V_47 ;
}
if ( V_5 ) {
unsigned long V_168 ;
F_98 ( V_9 , & V_5 -> V_37 , & V_5 -> V_59 ,
& V_168 ) ;
F_56 ( V_5 ) ;
V_5 -> V_59 += V_168 ;
F_16 ( V_5 ) ;
if ( F_33 ( V_164 ) ) {
F_92 ( V_5 ) ;
V_165 = V_5 -> V_114 ;
V_166 = V_5 -> V_96 ;
V_167 = V_5 -> V_115 ;
} else {
V_165 = V_5 -> V_59 ;
V_166 = V_5 -> V_46 ;
V_167 = V_5 -> V_47 ;
}
}
if ( V_59 <= F_54 ( V_46 , V_47 ) &&
( ! V_5 ||
V_165 <= F_54 ( V_166 , V_167 ) ) ) {
unsigned long V_169 = F_89 ( V_59 , V_46 ) ;
unsigned long V_170 = V_171 ;
V_52 -> V_172 = V_128 ;
V_52 -> V_173 = 0 ;
if ( V_5 )
V_170 = F_89 ( V_165 , V_166 ) ;
V_52 -> V_146 = V_18 ( V_169 , V_170 ) ;
break;
}
if ( F_33 ( ! F_99 ( V_9 ) ) )
F_100 ( V_9 ) ;
if ( ! V_164 )
F_92 ( V_6 ) ;
V_163 = ( V_6 -> V_114 > V_6 -> V_96 ) &&
( ( V_6 -> V_59 > V_6 -> V_46 ) || V_164 ) ;
F_64 ( V_6 ) ;
V_160 = V_6 ;
if ( V_5 ) {
if ( ! V_164 )
F_92 ( V_5 ) ;
V_163 |= ( V_5 -> V_114 > V_5 -> V_96 ) &&
( ( V_5 -> V_59 > V_5 -> V_46 ) || V_164 ) ;
F_64 ( V_5 ) ;
if ( V_5 -> V_103 < V_6 -> V_103 )
V_160 = V_5 ;
}
if ( V_163 && ! V_9 -> V_163 )
V_9 -> V_163 = 1 ;
if ( F_101 ( V_9 -> V_139 +
V_129 ) ) {
F_77 ( & V_9 -> V_140 ) ;
F_84 ( V_6 , V_5 , V_137 , true ) ;
F_79 ( & V_9 -> V_140 ) ;
}
V_131 = V_9 -> V_131 ;
V_133 = ( ( T_5 ) V_131 * V_160 -> V_103 ) >>
V_105 ;
V_145 = F_90 ( V_9 , V_160 -> V_114 ) ;
V_162 = F_91 ( V_9 , V_145 ,
V_133 , V_131 ,
& V_146 ) ;
if ( F_33 ( V_133 == 0 ) ) {
V_118 = V_145 ;
V_149 = V_145 ;
goto V_149;
}
V_118 = V_119 * V_157 / V_133 ;
V_149 = V_118 ;
if ( V_52 -> V_172 )
V_149 -= V_128 - V_52 -> V_172 ;
if ( V_149 < V_162 ) {
F_102 ( V_16 ,
V_160 -> V_46 ,
V_160 -> V_47 ,
V_160 -> V_59 ,
V_160 -> V_96 ,
V_160 -> V_114 ,
V_131 ,
V_133 ,
V_157 ,
V_118 ,
V_18 ( V_149 , 0L ) ,
V_137 ) ;
if ( V_149 < - V_119 ) {
V_52 -> V_172 = V_128 ;
V_52 -> V_173 = 0 ;
} else if ( V_118 ) {
V_52 -> V_172 += V_118 ;
V_52 -> V_173 = 0 ;
} else if ( V_52 -> V_146 <= V_157 )
V_52 -> V_146 += V_157 ;
break;
}
if ( F_33 ( V_149 > V_145 ) ) {
V_128 += V_18 ( V_149 - V_145 , V_145 ) ;
V_149 = V_145 ;
}
V_149:
F_102 ( V_16 ,
V_160 -> V_46 ,
V_160 -> V_47 ,
V_160 -> V_59 ,
V_160 -> V_96 ,
V_160 -> V_114 ,
V_131 ,
V_133 ,
V_157 ,
V_118 ,
V_149 ,
V_137 ) ;
F_103 ( V_174 ) ;
F_104 ( V_149 ) ;
V_52 -> V_172 = V_128 + V_149 ;
V_52 -> V_173 = 0 ;
V_52 -> V_146 = V_146 ;
if ( V_133 )
break;
if ( V_160 -> V_114 <= F_93 ( V_9 ) )
break;
if ( F_105 ( V_52 ) )
break;
}
if ( ! V_163 && V_9 -> V_163 )
V_9 -> V_163 = 0 ;
if ( F_99 ( V_9 ) )
return;
if ( V_175 )
return;
if ( V_161 > V_6 -> V_47 )
F_100 ( V_9 ) ;
}
void F_106 ( struct V_155 * V_156 )
{
struct V_176 * V_176 = V_156 -> V_177 ;
struct V_89 * V_16 = F_107 ( V_176 ) ;
struct V_8 * V_9 = NULL ;
int V_178 ;
int * V_179 ;
if ( ! F_108 ( V_16 ) )
return;
if ( F_109 ( V_176 ) )
V_9 = F_110 ( V_16 , V_180 ) ;
if ( ! V_9 )
V_9 = & V_16 -> V_9 ;
V_178 = V_52 -> V_146 ;
if ( V_9 -> V_163 )
V_178 = V_18 ( V_178 , 32 >> ( V_181 - 10 ) ) ;
F_111 () ;
V_179 = F_112 ( & V_182 ) ;
if ( F_33 ( V_52 -> V_173 >= V_178 ) )
* V_179 = 0 ;
else if ( F_33 ( * V_179 >= V_183 ) ) {
* V_179 = 0 ;
V_178 = 0 ;
}
V_179 = F_112 ( & V_184 ) ;
if ( * V_179 > 0 && V_52 -> V_173 < V_178 ) {
unsigned long V_185 ;
V_185 = V_18 ( * V_179 , V_178 - V_52 -> V_173 ) ;
* V_179 -= V_185 ;
V_52 -> V_173 += V_185 ;
}
F_113 () ;
if ( F_33 ( V_52 -> V_173 >= V_178 ) )
F_96 ( V_156 , V_9 , V_52 -> V_173 ) ;
F_114 ( V_9 ) ;
}
bool F_115 ( struct V_8 * V_9 )
{
struct V_1 V_158 = { F_60 (wb) } ;
struct V_1 V_159 = { F_97 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_158 ;
struct V_1 * const V_5 = F_1 ( & V_159 ) ?
& V_159 : NULL ;
V_6 -> V_37 = F_14 () ;
V_6 -> V_59 = F_15 ( V_61 ) +
F_15 ( V_62 ) ;
F_16 ( V_6 ) ;
if ( V_6 -> V_59 > V_6 -> V_47 )
return true ;
if ( F_95 ( V_9 , V_153 ) > F_57 ( V_6 ) )
return true ;
if ( V_5 ) {
unsigned long V_168 ;
F_98 ( V_9 , & V_5 -> V_37 , & V_5 -> V_59 , & V_168 ) ;
F_56 ( V_5 ) ;
F_16 ( V_5 ) ;
if ( V_5 -> V_59 > V_5 -> V_47 )
return true ;
if ( F_95 ( V_9 , V_153 ) > F_57 ( V_5 ) )
return true ;
}
return false ;
}
void F_116 ( T_4 V_186 )
{
unsigned long V_187 ;
unsigned long V_188 ;
for ( ; ; ) {
F_20 ( & V_187 , & V_188 ) ;
V_188 = F_55 ( & V_22 , V_188 ) ;
V_188 += V_188 / 10 ;
if ( F_15 ( V_62 ) +
F_15 ( V_63 ) <= V_188 )
break;
F_117 ( V_189 , V_119 / 10 ) ;
if ( ( V_186 & ( V_190 | V_191 ) ) != ( V_190 | V_191 ) )
break;
}
}
int F_118 ( struct V_64 * V_65 , int V_66 ,
void T_1 * V_67 , T_2 * V_192 , T_3 * V_69 )
{
F_119 ( V_65 , V_66 , V_67 , V_192 , V_69 ) ;
return 0 ;
}
void F_120 ( unsigned long V_87 )
{
struct V_193 * V_194 = (struct V_193 * ) V_87 ;
int V_24 = F_15 ( V_61 ) +
F_15 ( V_62 ) ;
struct V_8 * V_9 ;
struct V_195 V_196 ;
if ( ! F_121 ( & V_194 -> V_89 ) )
return;
F_122 (wb, &q->backing_dev_info, &iter, 0 )
if ( F_71 ( V_9 ) )
F_123 ( V_9 , V_24 , true ,
V_197 ) ;
}
void F_124 ( struct V_89 * V_198 )
{
F_34 ( & V_198 -> V_199 , V_78 + V_175 ) ;
}
void F_125 ( void )
{
struct V_89 * V_16 ;
F_126 () ;
F_127 (bdi, &bdi_list, bdi_list)
F_128 ( & V_16 -> V_199 ) ;
F_129 () ;
}
void F_28 ( void )
{
struct V_4 * V_3 = & V_22 ;
unsigned long V_187 ;
unsigned long V_188 ;
F_20 ( & V_187 , & V_188 ) ;
V_3 -> V_94 = V_188 ;
V_183 = V_188 / ( F_130 () * 32 ) ;
if ( V_183 < 16 )
V_183 = 16 ;
}
static int
F_131 ( struct V_200 * V_201 , unsigned long V_202 ,
void * V_203 )
{
switch ( V_202 & ~ V_204 ) {
case V_205 :
case V_206 :
F_28 () ;
return V_207 ;
default:
return V_208 ;
}
}
void T_6 F_132 ( void )
{
F_133 ( F_43 ( & V_22 , V_180 ) ) ;
F_28 () ;
F_134 ( & V_209 ) ;
}
void F_135 ( struct V_155 * V_156 ,
T_7 V_210 , T_7 V_211 )
{
#define F_136 4096
unsigned long V_212 ;
do {
F_137 ( & V_156 -> V_213 ) ;
V_212 = F_138 ( & V_156 -> V_214 ,
& V_210 , V_211 , F_136 ,
V_215 , V_216 ) ;
F_139 ( & V_156 -> V_213 ) ;
F_72 ( V_212 > F_136 ) ;
F_140 () ;
} while ( V_212 >= F_136 && V_210 );
}
int F_141 ( struct V_155 * V_156 ,
struct V_217 * V_218 , T_8 V_219 ,
void * V_87 )
{
int V_70 = 0 ;
int V_220 = 0 ;
struct V_221 V_222 ;
int V_24 ;
T_7 V_223 ( V_224 ) ;
T_7 V_225 ;
T_7 V_211 ;
T_7 V_226 ;
int V_227 ;
int V_228 = 0 ;
int V_229 ;
F_142 ( & V_222 , 0 ) ;
if ( V_218 -> V_230 ) {
V_224 = V_156 -> V_224 ;
V_225 = V_224 ;
if ( V_225 == 0 )
V_227 = 1 ;
else
V_227 = 0 ;
V_211 = - 1 ;
} else {
V_225 = V_218 -> V_231 >> V_232 ;
V_211 = V_218 -> V_233 >> V_232 ;
if ( V_218 -> V_231 == 0 && V_218 -> V_233 == V_234 )
V_228 = 1 ;
V_227 = 1 ;
}
if ( V_218 -> V_235 == V_236 || V_218 -> V_237 )
V_229 = V_216 ;
else
V_229 = V_215 ;
V_238:
if ( V_218 -> V_235 == V_236 || V_218 -> V_237 )
F_135 ( V_156 , V_225 , V_211 ) ;
V_226 = V_225 ;
while ( ! V_220 && ( V_225 <= V_211 ) ) {
int V_239 ;
V_24 = F_143 ( & V_222 , V_156 , & V_225 , V_229 ,
V_18 ( V_211 - V_225 , ( T_7 ) V_240 - 1 ) + 1 ) ;
if ( V_24 == 0 )
break;
for ( V_239 = 0 ; V_239 < V_24 ; V_239 ++ ) {
struct V_241 * V_241 = V_222 . V_150 [ V_239 ] ;
if ( V_241 -> V_225 > V_211 ) {
V_220 = 1 ;
break;
}
V_226 = V_241 -> V_225 ;
F_144 ( V_241 ) ;
if ( F_33 ( V_241 -> V_156 != V_156 ) ) {
V_242:
F_145 ( V_241 ) ;
continue;
}
if ( ! F_146 ( V_241 ) ) {
goto V_242;
}
if ( F_147 ( V_241 ) ) {
if ( V_218 -> V_235 != V_243 )
F_148 ( V_241 ) ;
else
goto V_242;
}
F_133 ( F_147 ( V_241 ) ) ;
if ( ! F_149 ( V_241 ) )
goto V_242;
F_150 ( V_218 , F_107 ( V_156 -> V_177 ) ) ;
V_70 = (* V_219)( V_241 , V_218 , V_87 ) ;
if ( F_33 ( V_70 ) ) {
if ( V_70 == V_244 ) {
F_145 ( V_241 ) ;
V_70 = 0 ;
} else {
V_226 = V_241 -> V_225 + 1 ;
V_220 = 1 ;
break;
}
}
if ( -- V_218 -> V_245 <= 0 &&
V_218 -> V_235 == V_243 ) {
V_220 = 1 ;
break;
}
}
F_151 ( & V_222 ) ;
F_140 () ;
}
if ( ! V_227 && ! V_220 ) {
V_227 = 1 ;
V_225 = 0 ;
V_211 = V_224 - 1 ;
goto V_238;
}
if ( V_218 -> V_230 || ( V_228 && V_218 -> V_245 > 0 ) )
V_156 -> V_224 = V_226 ;
return V_70 ;
}
static int F_152 ( struct V_241 * V_241 , struct V_217 * V_218 ,
void * V_87 )
{
struct V_155 * V_156 = V_87 ;
int V_70 = V_156 -> V_246 -> V_219 ( V_241 , V_218 ) ;
F_153 ( V_156 , V_70 ) ;
return V_70 ;
}
int F_154 ( struct V_155 * V_156 ,
struct V_217 * V_218 )
{
struct V_247 V_248 ;
int V_70 ;
if ( ! V_156 -> V_246 -> V_219 )
return 0 ;
F_155 ( & V_248 ) ;
V_70 = F_141 ( V_156 , V_218 , F_152 , V_156 ) ;
F_156 ( & V_248 ) ;
return V_70 ;
}
int F_157 ( struct V_155 * V_156 , struct V_217 * V_218 )
{
int V_70 ;
if ( V_218 -> V_245 <= 0 )
return 0 ;
if ( V_156 -> V_246 -> V_249 )
V_70 = V_156 -> V_246 -> V_249 ( V_156 , V_218 ) ;
else
V_70 = F_154 ( V_156 , V_218 ) ;
return V_70 ;
}
int F_158 ( struct V_241 * V_241 , int V_250 )
{
struct V_155 * V_156 = V_241 -> V_156 ;
int V_70 = 0 ;
struct V_217 V_218 = {
. V_235 = V_236 ,
. V_245 = 1 ,
} ;
F_133 ( ! F_159 ( V_241 ) ) ;
if ( V_250 )
F_148 ( V_241 ) ;
if ( F_149 ( V_241 ) ) {
F_160 ( V_241 ) ;
V_70 = V_156 -> V_246 -> V_219 ( V_241 , & V_218 ) ;
if ( V_70 == 0 && V_250 ) {
F_148 ( V_241 ) ;
if ( F_161 ( V_241 ) )
V_70 = - V_251 ;
}
F_162 ( V_241 ) ;
} else {
F_145 ( V_241 ) ;
}
return V_70 ;
}
int F_163 ( struct V_241 * V_241 )
{
if ( ! F_146 ( V_241 ) )
return ! F_164 ( V_241 ) ;
return 0 ;
}
void F_165 ( struct V_241 * V_241 , struct V_155 * V_156 ,
struct V_252 * V_253 )
{
struct V_176 * V_176 = V_156 -> V_177 ;
F_166 ( V_241 , V_156 ) ;
if ( F_167 ( V_156 ) ) {
struct V_8 * V_9 ;
F_168 ( V_176 , V_241 ) ;
V_9 = F_169 ( V_176 ) ;
F_170 ( V_253 , V_254 ) ;
F_171 ( V_241 , V_61 ) ;
F_171 ( V_241 , V_255 ) ;
F_36 ( V_9 , V_153 ) ;
F_36 ( V_9 , V_142 ) ;
F_172 ( V_256 ) ;
V_52 -> V_173 ++ ;
F_173 ( V_182 ) ;
}
}
void F_174 ( struct V_241 * V_241 , struct V_155 * V_156 ,
struct V_252 * V_253 , struct V_8 * V_9 )
{
if ( F_167 ( V_156 ) ) {
F_175 ( V_253 , V_254 ) ;
F_176 ( V_241 , V_61 ) ;
F_177 ( V_9 , V_153 ) ;
F_178 ( V_256 ) ;
}
}
int F_179 ( struct V_241 * V_241 )
{
struct V_252 * V_253 ;
V_253 = F_180 ( V_241 ) ;
if ( ! F_164 ( V_241 ) ) {
struct V_155 * V_156 = F_181 ( V_241 ) ;
unsigned long V_53 ;
if ( ! V_156 ) {
F_182 ( V_253 ) ;
return 1 ;
}
F_183 ( & V_156 -> V_213 , V_53 ) ;
F_133 ( F_181 ( V_241 ) != V_156 ) ;
F_72 ( ! F_184 ( V_241 ) && ! F_185 ( V_241 ) ) ;
F_165 ( V_241 , V_156 , V_253 ) ;
F_186 ( & V_156 -> V_214 , F_187 ( V_241 ) ,
V_215 ) ;
F_188 ( & V_156 -> V_213 , V_53 ) ;
F_182 ( V_253 ) ;
if ( V_156 -> V_177 ) {
F_189 ( V_156 -> V_177 , V_257 ) ;
}
return 1 ;
}
F_182 ( V_253 ) ;
return 0 ;
}
void F_190 ( struct V_241 * V_241 )
{
struct V_155 * V_156 = V_241 -> V_156 ;
if ( V_156 && F_167 ( V_156 ) ) {
struct V_176 * V_176 = V_156 -> V_177 ;
struct V_8 * V_9 ;
bool V_258 ;
V_9 = F_191 ( V_176 , & V_258 ) ;
V_52 -> V_173 -- ;
F_176 ( V_241 , V_255 ) ;
F_177 ( V_9 , V_142 ) ;
F_192 ( V_176 , V_258 ) ;
}
}
int F_193 ( struct V_217 * V_218 , struct V_241 * V_241 )
{
int V_70 ;
V_218 -> V_259 ++ ;
V_70 = F_179 ( V_241 ) ;
F_190 ( V_241 ) ;
return V_70 ;
}
int F_194 ( struct V_241 * V_241 )
{
struct V_155 * V_156 = F_181 ( V_241 ) ;
if ( F_195 ( V_156 ) ) {
int (* F_196)( struct V_241 * ) = V_156 -> V_246 -> F_194 ;
if ( F_197 ( V_241 ) )
F_198 ( V_241 ) ;
#ifdef F_199
if ( ! F_196 )
F_196 = V_260 ;
#endif
return (* F_196)( V_241 ) ;
}
if ( ! F_146 ( V_241 ) ) {
if ( ! F_164 ( V_241 ) )
return 1 ;
}
return 0 ;
}
int F_200 ( struct V_241 * V_241 )
{
int V_70 ;
F_144 ( V_241 ) ;
V_70 = F_194 ( V_241 ) ;
F_145 ( V_241 ) ;
return V_70 ;
}
void F_201 ( struct V_241 * V_241 )
{
struct V_155 * V_156 = F_181 ( V_241 ) ;
if ( F_167 ( V_156 ) ) {
struct V_176 * V_176 = V_156 -> V_177 ;
struct V_8 * V_9 ;
struct V_252 * V_253 ;
bool V_258 ;
V_253 = F_180 ( V_241 ) ;
V_9 = F_191 ( V_176 , & V_258 ) ;
if ( F_202 ( V_241 ) )
F_174 ( V_241 , V_156 , V_253 , V_9 ) ;
F_192 ( V_176 , V_258 ) ;
F_182 ( V_253 ) ;
} else {
F_203 ( V_241 ) ;
}
}
int F_149 ( struct V_241 * V_241 )
{
struct V_155 * V_156 = F_181 ( V_241 ) ;
int V_70 = 0 ;
F_133 ( ! F_159 ( V_241 ) ) ;
if ( V_156 && F_167 ( V_156 ) ) {
struct V_176 * V_176 = V_156 -> V_177 ;
struct V_8 * V_9 ;
struct V_252 * V_253 ;
bool V_258 ;
if ( F_204 ( V_241 ) )
F_194 ( V_241 ) ;
V_253 = F_180 ( V_241 ) ;
V_9 = F_191 ( V_176 , & V_258 ) ;
if ( F_202 ( V_241 ) ) {
F_175 ( V_253 , V_254 ) ;
F_176 ( V_241 , V_61 ) ;
F_177 ( V_9 , V_153 ) ;
V_70 = 1 ;
}
F_192 ( V_176 , V_258 ) ;
F_182 ( V_253 ) ;
return V_70 ;
}
return F_202 ( V_241 ) ;
}
int F_205 ( struct V_241 * V_241 )
{
struct V_155 * V_156 = F_181 ( V_241 ) ;
struct V_252 * V_253 ;
int V_70 ;
V_253 = F_180 ( V_241 ) ;
if ( V_156 ) {
struct V_176 * V_176 = V_156 -> V_177 ;
struct V_89 * V_16 = F_107 ( V_176 ) ;
unsigned long V_53 ;
F_183 ( & V_156 -> V_213 , V_53 ) ;
V_70 = F_206 ( V_241 ) ;
if ( V_70 ) {
F_207 ( & V_156 -> V_214 ,
F_187 ( V_241 ) ,
V_261 ) ;
if ( F_208 ( V_16 ) ) {
struct V_8 * V_9 = F_169 ( V_176 ) ;
F_209 ( V_9 , V_154 ) ;
F_35 ( V_9 ) ;
}
}
F_188 ( & V_156 -> V_213 , V_53 ) ;
} else {
V_70 = F_206 ( V_241 ) ;
}
if ( V_70 ) {
F_175 ( V_253 , V_262 ) ;
F_176 ( V_241 , V_63 ) ;
F_210 ( V_241 , V_263 ) ;
}
F_182 ( V_253 ) ;
return V_70 ;
}
int F_211 ( struct V_241 * V_241 , bool V_264 )
{
struct V_155 * V_156 = F_181 ( V_241 ) ;
struct V_252 * V_253 ;
int V_70 ;
V_253 = F_180 ( V_241 ) ;
if ( V_156 ) {
struct V_176 * V_176 = V_156 -> V_177 ;
struct V_89 * V_16 = F_107 ( V_176 ) ;
unsigned long V_53 ;
F_183 ( & V_156 -> V_213 , V_53 ) ;
V_70 = F_212 ( V_241 ) ;
if ( ! V_70 ) {
F_186 ( & V_156 -> V_214 ,
F_187 ( V_241 ) ,
V_261 ) ;
if ( F_208 ( V_16 ) )
F_36 ( F_169 ( V_176 ) , V_154 ) ;
}
if ( ! F_146 ( V_241 ) )
F_207 ( & V_156 -> V_214 ,
F_187 ( V_241 ) ,
V_215 ) ;
if ( ! V_264 )
F_207 ( & V_156 -> V_214 ,
F_187 ( V_241 ) ,
V_216 ) ;
F_188 ( & V_156 -> V_213 , V_53 ) ;
} else {
V_70 = F_212 ( V_241 ) ;
}
if ( ! V_70 ) {
F_170 ( V_253 , V_262 ) ;
F_210 ( V_241 , V_63 ) ;
}
F_182 ( V_253 ) ;
return V_70 ;
}
int F_213 ( struct V_155 * V_156 , int V_229 )
{
return F_214 ( & V_156 -> V_214 , V_229 ) ;
}
void F_215 ( struct V_241 * V_241 )
{
if ( F_216 ( F_107 ( V_241 -> V_156 -> V_177 ) ) )
F_148 ( V_241 ) ;
}
