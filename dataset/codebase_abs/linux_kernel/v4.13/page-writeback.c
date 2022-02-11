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
static unsigned long F_8 ( struct V_23 * V_24 )
{
unsigned long V_25 = 0 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
struct V_28 * V_28 = V_24 -> V_29 + V_26 ;
if ( ! F_9 ( V_28 ) )
continue;
V_25 += F_10 ( V_28 , V_30 ) ;
}
V_25 -= V_18 ( V_25 , V_24 -> V_31 ) ;
V_25 += F_11 ( V_24 , V_32 ) ;
V_25 += F_11 ( V_24 , V_33 ) ;
return V_25 ;
}
static unsigned long F_12 ( unsigned long V_34 )
{
#ifdef F_13
int V_35 ;
unsigned long V_36 = 0 ;
int V_37 ;
F_14 (node, N_HIGH_MEMORY) {
for ( V_37 = V_38 + 1 ; V_37 < V_27 ; V_37 ++ ) {
struct V_28 * V_26 ;
unsigned long V_25 ;
if ( ! F_15 ( V_37 ) )
continue;
V_26 = & F_16 ( V_35 ) -> V_29 [ V_37 ] ;
if ( ! F_9 ( V_26 ) )
continue;
V_25 = F_10 ( V_26 , V_30 ) ;
V_25 -= V_18 ( V_25 , F_17 ( V_26 ) ) ;
V_25 += F_10 ( V_26 , V_39 ) ;
V_25 += F_10 ( V_26 , V_40 ) ;
V_36 += V_25 ;
}
}
if ( ( long ) V_36 < 0 )
V_36 = 0 ;
return V_18 ( V_36 , V_34 ) ;
#else
return 0 ;
#endif
}
static unsigned long F_18 ( void )
{
unsigned long V_36 ;
V_36 = F_19 ( V_30 ) ;
V_36 -= V_18 ( V_36 , V_31 ) ;
V_36 += F_20 ( V_32 ) ;
V_36 += F_20 ( V_33 ) ;
if ( ! V_41 )
V_36 -= F_12 ( V_36 ) ;
return V_36 + 1 ;
}
static void F_21 ( struct V_1 * V_2 )
{
const unsigned long V_42 = V_2 -> V_43 ;
struct V_1 * V_6 = F_3 ( V_2 ) ;
unsigned long V_44 = V_45 ;
unsigned long V_46 = V_47 ;
unsigned long V_48 = ( V_49 * V_50 ) / 100 ;
unsigned long V_51 = ( V_52 * V_50 ) / 100 ;
unsigned long V_53 ;
unsigned long V_54 ;
struct V_55 * V_56 ;
if ( V_6 ) {
unsigned long V_57 = V_6 -> V_43 ;
if ( V_44 )
V_48 = V_18 ( F_22 ( V_44 , V_57 ) ,
V_50 ) ;
if ( V_46 )
V_51 = V_18 ( F_22 ( V_46 , V_57 ) ,
V_50 ) ;
V_44 = V_46 = 0 ;
}
if ( V_44 )
V_53 = F_22 ( V_44 , V_50 ) ;
else
V_53 = ( V_48 * V_42 ) / V_50 ;
if ( V_46 )
V_54 = F_22 ( V_46 , V_50 ) ;
else
V_54 = ( V_51 * V_42 ) / V_50 ;
if ( V_54 >= V_53 )
V_54 = V_53 / 2 ;
V_56 = V_58 ;
if ( V_56 -> V_59 & V_60 || F_23 ( V_56 ) ) {
V_54 += V_54 / 4 + V_22 . V_61 / 32 ;
V_53 += V_53 / 4 + V_22 . V_61 / 32 ;
}
V_2 -> V_53 = V_53 ;
V_2 -> V_54 = V_54 ;
if ( ! V_6 )
F_24 ( V_54 , V_53 ) ;
}
void F_25 ( unsigned long * V_62 , unsigned long * V_63 )
{
struct V_1 V_6 = { V_64 } ;
V_6 . V_43 = F_18 () ;
F_21 ( & V_6 ) ;
* V_62 = V_6 . V_54 ;
* V_63 = V_6 . V_53 ;
}
static unsigned long F_26 ( struct V_23 * V_24 )
{
unsigned long V_65 = F_8 ( V_24 ) ;
struct V_55 * V_56 = V_58 ;
unsigned long V_66 ;
if ( V_45 )
V_66 = F_22 ( V_45 , V_50 ) *
V_65 / F_18 () ;
else
V_66 = V_49 * V_65 / 100 ;
if ( V_56 -> V_59 & V_60 || F_23 ( V_56 ) )
V_66 += V_66 / 4 ;
return V_66 ;
}
bool F_27 ( struct V_23 * V_24 )
{
unsigned long V_67 = F_26 ( V_24 ) ;
unsigned long V_25 = 0 ;
V_25 += F_11 ( V_24 , V_68 ) ;
V_25 += F_11 ( V_24 , V_69 ) ;
V_25 += F_11 ( V_24 , V_70 ) ;
return V_25 <= V_67 ;
}
int F_28 ( struct V_71 * V_72 , int V_73 ,
void T_1 * V_74 , T_2 * V_75 ,
T_3 * V_76 )
{
int V_77 ;
V_77 = F_29 ( V_72 , V_73 , V_74 , V_75 , V_76 ) ;
if ( V_77 == 0 && V_73 )
V_47 = 0 ;
return V_77 ;
}
int F_30 ( struct V_71 * V_72 , int V_73 ,
void T_1 * V_74 , T_2 * V_75 ,
T_3 * V_76 )
{
int V_77 ;
V_77 = F_31 ( V_72 , V_73 , V_74 , V_75 , V_76 ) ;
if ( V_77 == 0 && V_73 )
V_52 = 0 ;
return V_77 ;
}
int F_32 ( struct V_71 * V_72 , int V_73 ,
void T_1 * V_74 , T_2 * V_75 ,
T_3 * V_76 )
{
int V_78 = V_49 ;
int V_77 ;
V_77 = F_29 ( V_72 , V_73 , V_74 , V_75 , V_76 ) ;
if ( V_77 == 0 && V_73 && V_49 != V_78 ) {
F_33 () ;
V_45 = 0 ;
}
return V_77 ;
}
int F_34 ( struct V_71 * V_72 , int V_73 ,
void T_1 * V_74 , T_2 * V_75 ,
T_3 * V_76 )
{
unsigned long V_79 = V_45 ;
int V_77 ;
V_77 = F_31 ( V_72 , V_73 , V_74 , V_75 , V_76 ) ;
if ( V_77 == 0 && V_73 && V_45 != V_79 ) {
F_33 () ;
V_49 = 0 ;
}
return V_77 ;
}
static unsigned long F_35 ( unsigned long V_80 )
{
V_80 += V_81 ;
if ( ! V_80 )
return 1 ;
return V_80 ;
}
static void F_36 ( struct V_4 * V_3 ,
struct V_7 * V_82 ,
unsigned int V_83 )
{
F_37 ( & V_3 -> V_82 , V_82 ,
V_83 ) ;
if ( F_38 ( ! V_3 -> V_84 ) ) {
V_3 -> V_84 = F_35 ( V_85 ) ;
F_39 ( & V_3 -> V_86 , V_3 -> V_84 ) ;
}
}
static inline void F_40 ( struct V_8 * V_9 )
{
struct V_4 * V_87 ;
F_41 ( V_9 , V_88 ) ;
F_36 ( & V_22 , & V_9 -> V_82 ,
V_9 -> V_16 -> V_83 ) ;
V_87 = F_42 ( V_9 ) ;
if ( V_87 )
F_36 ( V_87 , F_4 ( V_9 ) ,
V_9 -> V_16 -> V_83 ) ;
}
void F_43 ( struct V_8 * V_9 )
{
unsigned long V_59 ;
F_44 ( V_59 ) ;
F_40 ( V_9 ) ;
F_45 ( V_59 ) ;
}
static void F_46 ( unsigned long V_89 )
{
struct V_4 * V_3 = ( void * ) V_89 ;
int V_90 = ( V_85 - V_3 -> V_84 ) /
V_81 ;
if ( F_47 ( & V_3 -> V_82 , V_90 + 1 ) ) {
V_3 -> V_84 = F_35 ( V_3 -> V_84 +
V_90 * V_81 ) ;
F_39 ( & V_3 -> V_86 , V_3 -> V_84 ) ;
} else {
V_3 -> V_84 = 0 ;
}
}
int F_48 ( struct V_4 * V_3 , T_4 V_91 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_49 ( & V_3 -> V_92 ) ;
F_50 ( & V_3 -> V_86 , F_46 ,
( unsigned long ) V_3 ) ;
V_3 -> V_93 = V_85 ;
return F_51 ( & V_3 -> V_82 , V_91 ) ;
}
void F_52 ( struct V_4 * V_3 )
{
F_53 ( & V_3 -> V_86 ) ;
F_54 ( & V_3 -> V_82 ) ;
}
int F_55 ( struct V_94 * V_16 , unsigned int V_19 )
{
int V_77 = 0 ;
F_56 ( & V_95 ) ;
if ( V_19 > V_16 -> V_21 ) {
V_77 = - V_96 ;
} else {
V_19 -= V_16 -> V_19 ;
if ( V_97 + V_19 < 100 ) {
V_97 += V_19 ;
V_16 -> V_19 += V_19 ;
} else {
V_77 = - V_96 ;
}
}
F_57 ( & V_95 ) ;
return V_77 ;
}
int F_58 ( struct V_94 * V_16 , unsigned V_21 )
{
int V_77 = 0 ;
if ( V_21 > 100 )
return - V_96 ;
F_56 ( & V_95 ) ;
if ( V_16 -> V_19 > V_21 ) {
V_77 = - V_96 ;
} else {
V_16 -> V_21 = V_21 ;
V_16 -> V_83 = ( V_98 * V_21 ) / 100 ;
}
F_57 ( & V_95 ) ;
return V_77 ;
}
static unsigned long F_59 ( unsigned long V_53 ,
unsigned long V_54 )
{
return ( V_53 + V_54 ) / 2 ;
}
static unsigned long F_60 ( struct V_4 * V_3 ,
unsigned long V_53 )
{
return V_20 ( V_53 , V_3 -> V_61 ) ;
}
static void F_61 ( struct V_1 * V_5 ,
unsigned long V_99 , unsigned long V_100 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_101 = V_99 - V_18 ( V_99 , V_5 -> V_66 ) ;
unsigned long V_102 = V_6 -> V_43 - V_18 ( V_6 -> V_43 , V_6 -> V_66 ) ;
unsigned long V_103 = V_102 - V_18 ( V_102 , V_101 ) ;
V_5 -> V_43 = V_99 + V_18 ( V_100 , V_103 ) ;
}
static unsigned long F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_53 = V_2 -> V_53 ;
T_5 V_104 ;
long V_105 , V_106 ;
unsigned long V_107 , V_108 ;
F_63 ( & V_3 -> V_82 , V_2 -> V_109 ,
& V_105 , & V_106 ) ;
V_104 = ( V_53 * ( 100 - V_97 ) ) / 100 ;
V_104 *= V_105 ;
F_7 ( V_104 , V_106 ) ;
F_5 ( V_2 -> V_9 , & V_107 , & V_108 ) ;
V_104 += ( V_53 * V_107 ) / 100 ;
if ( V_104 > ( V_53 * V_108 ) / 100 )
V_104 = V_53 * V_108 / 100 ;
return V_104 ;
}
unsigned long F_64 ( struct V_8 * V_9 , unsigned long V_53 )
{
struct V_1 V_6 = { F_65 ( V_9 ) ,
. V_53 = V_53 } ;
return F_62 ( & V_6 ) ;
}
static long long F_66 ( unsigned long V_110 ,
unsigned long V_66 ,
unsigned long V_67 )
{
long long V_111 ;
long V_36 ;
V_36 = F_67 ( ( ( V_112 ) V_110 - ( V_112 ) V_66 ) << V_113 ,
( V_67 - V_110 ) | 1 ) ;
V_111 = V_36 ;
V_111 = V_111 * V_36 >> V_113 ;
V_111 = V_111 * V_36 >> V_113 ;
V_111 += 1 << V_113 ;
return F_68 ( V_111 , 0LL , 2LL << V_113 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_114 = V_9 -> V_14 ;
unsigned long V_115 = F_59 ( V_2 -> V_53 , V_2 -> V_54 ) ;
unsigned long V_67 = F_60 ( F_2 ( V_2 ) , V_2 -> V_53 ) ;
unsigned long V_104 = V_2 -> V_104 ;
unsigned long V_116 ;
unsigned long V_110 ;
unsigned long V_117 ;
unsigned long V_118 ;
long long V_111 ;
long V_36 ;
V_2 -> V_111 = 0 ;
if ( F_38 ( V_2 -> V_66 >= V_67 ) )
return;
V_110 = ( V_115 + V_67 ) / 2 ;
V_111 = F_66 ( V_110 , V_2 -> V_66 , V_67 ) ;
if ( F_38 ( V_9 -> V_16 -> V_119 & V_120 ) ) {
long long V_121 ;
if ( V_2 -> V_122 < 8 ) {
V_2 -> V_111 = F_70 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
return;
}
if ( V_2 -> V_122 >= V_104 )
return;
V_117 = F_59 ( V_104 ,
V_2 -> V_123 ) ;
if ( V_117 == 0 || V_117 == V_104 )
return;
V_121 = F_66 ( V_117 , V_2 -> V_122 ,
V_104 ) ;
V_2 -> V_111 = V_18 ( V_111 , V_121 ) ;
return;
}
if ( F_38 ( V_104 > V_2 -> V_53 ) )
V_104 = V_2 -> V_53 ;
V_104 = V_20 ( V_104 , ( V_67 - V_2 -> V_66 ) / 8 ) ;
V_36 = F_71 ( ( T_5 ) V_104 << 16 , V_2 -> V_53 | 1 ) ;
V_117 = V_110 * ( T_5 ) V_36 >> 16 ;
V_118 = ( V_2 -> V_53 - V_104 + 8 * V_114 ) * ( T_5 ) V_36 >> 16 ;
V_116 = V_117 + V_118 ;
if ( V_2 -> V_122 < V_116 - V_118 / 4 ) {
V_111 = F_72 ( V_111 * ( V_116 - V_2 -> V_122 ) ,
( V_116 - V_117 ) | 1 ) ;
} else
V_111 /= 4 ;
V_116 = V_104 / 2 ;
if ( V_2 -> V_122 < V_116 ) {
if ( V_2 -> V_122 > V_116 / 8 )
V_111 = F_71 ( V_111 * V_116 ,
V_2 -> V_122 ) ;
else
V_111 *= 8 ;
}
V_2 -> V_111 = V_111 ;
}
static void F_73 ( struct V_8 * V_9 ,
unsigned long V_124 ,
unsigned long V_125 )
{
const unsigned long V_126 = F_74 ( 3 * V_127 ) ;
unsigned long V_128 = V_9 -> V_14 ;
unsigned long V_129 = V_9 -> V_130 ;
T_5 V_131 ;
V_131 = V_125 - V_18 ( V_125 , V_9 -> V_132 ) ;
V_131 *= V_127 ;
if ( F_38 ( V_124 > V_126 ) ) {
F_7 ( V_131 , V_124 ) ;
V_128 = V_131 ;
goto V_133;
}
V_131 += ( T_5 ) V_9 -> V_130 * ( V_126 - V_124 ) ;
V_131 >>= F_75 ( V_126 ) ;
if ( V_128 > V_129 && V_129 >= ( unsigned long ) V_131 )
V_128 -= ( V_128 - V_129 ) >> 3 ;
if ( V_128 < V_129 && V_129 <= ( unsigned long ) V_131 )
V_128 += ( V_129 - V_128 ) >> 3 ;
V_133:
V_128 = V_20 ( V_128 , 1LU ) ;
if ( F_76 ( V_9 ) ) {
long V_134 = V_128 - V_9 -> V_14 ;
F_77 ( F_78 ( V_134 ,
& V_9 -> V_16 -> V_17 ) <= 0 ) ;
}
V_9 -> V_130 = V_131 ;
V_9 -> V_14 = V_128 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_53 = V_2 -> V_53 ;
unsigned long V_67 = V_3 -> V_61 ;
if ( V_67 < V_53 ) {
V_67 = V_53 ;
goto V_135;
}
V_53 = V_20 ( V_53 , V_2 -> V_66 ) ;
if ( V_67 > V_53 ) {
V_67 -= ( V_67 - V_53 ) >> 5 ;
goto V_135;
}
return;
V_135:
V_3 -> V_61 = V_67 ;
}
static void F_80 ( struct V_1 * V_2 ,
unsigned long V_136 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
if ( F_81 ( V_136 , V_3 -> V_93 + V_137 ) )
return;
F_82 ( & V_3 -> V_92 ) ;
if ( F_83 ( V_136 , V_3 -> V_93 + V_137 ) ) {
F_79 ( V_2 ) ;
V_3 -> V_93 = V_136 ;
}
F_84 ( & V_3 -> V_92 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
unsigned long V_138 ,
unsigned long V_124 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_66 = V_2 -> V_66 ;
unsigned long V_115 = F_59 ( V_2 -> V_53 , V_2 -> V_54 ) ;
unsigned long V_67 = F_60 ( F_2 ( V_2 ) , V_2 -> V_53 ) ;
unsigned long V_110 = ( V_115 + V_67 ) / 2 ;
unsigned long V_114 = V_9 -> V_14 ;
unsigned long V_139 = V_9 -> V_139 ;
unsigned long V_140 ;
unsigned long V_141 ;
unsigned long V_142 ;
unsigned long V_143 ;
unsigned long V_36 ;
unsigned long V_144 ;
V_140 = ( V_138 - V_9 -> V_145 ) * V_127 / V_124 ;
V_141 = ( T_5 ) V_139 *
V_2 -> V_111 >> V_113 ;
V_141 ++ ;
V_142 = F_71 ( ( T_5 ) V_141 * V_114 ,
V_140 | 1 ) ;
if ( F_38 ( V_142 > V_114 ) )
V_142 = V_114 ;
V_143 = 0 ;
if ( F_38 ( V_9 -> V_16 -> V_119 & V_120 ) ) {
V_66 = V_2 -> V_122 ;
if ( V_2 -> V_122 < 8 )
V_110 = V_2 -> V_122 + 1 ;
else
V_110 = ( V_2 -> V_104 + V_2 -> V_123 ) / 2 ;
}
if ( V_66 < V_110 ) {
V_36 = F_86 ( V_9 -> V_142 ,
V_142 , V_141 ) ;
if ( V_139 < V_36 )
V_143 = V_36 - V_139 ;
} else {
V_36 = F_87 ( V_9 -> V_142 ,
V_142 , V_141 ) ;
if ( V_139 > V_36 )
V_143 = V_139 - V_36 ;
}
V_144 = V_139 / ( 2 * V_143 + 1 ) ;
if ( V_144 < V_146 )
V_143 = F_22 ( V_143 >> V_144 , 8 ) ;
else
V_143 = 0 ;
if ( V_139 < V_142 )
V_139 += V_143 ;
else
V_139 -= V_143 ;
V_9 -> V_139 = V_20 ( V_139 , 1UL ) ;
V_9 -> V_142 = V_142 ;
F_88 ( V_9 , V_140 , V_141 ) ;
}
static void F_89 ( struct V_1 * V_6 ,
struct V_1 * V_5 ,
unsigned long V_147 ,
bool V_148 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned long V_136 = V_85 ;
unsigned long V_124 = V_136 - V_9 -> V_149 ;
unsigned long V_138 ;
unsigned long V_125 ;
F_90 ( & V_9 -> V_150 ) ;
if ( V_124 < V_137 )
return;
V_138 = F_91 ( & V_9 -> V_151 [ V_152 ] ) ;
V_125 = F_91 ( & V_9 -> V_151 [ V_88 ] ) ;
if ( V_124 > V_127 && F_81 ( V_9 -> V_149 , V_147 ) )
goto V_153;
if ( V_148 ) {
F_80 ( V_6 , V_136 ) ;
F_85 ( V_6 , V_138 , V_124 ) ;
if ( F_92 ( V_154 ) && V_5 ) {
F_80 ( V_5 , V_136 ) ;
F_85 ( V_5 , V_138 , V_124 ) ;
}
}
F_73 ( V_9 , V_124 , V_125 ) ;
V_153:
V_9 -> V_145 = V_138 ;
V_9 -> V_132 = V_125 ;
V_9 -> V_149 = V_136 ;
}
void F_93 ( struct V_8 * V_9 , unsigned long V_147 )
{
struct V_1 V_6 = { F_65 (wb) } ;
F_89 ( & V_6 , NULL , V_147 , false ) ;
}
static unsigned long F_94 ( unsigned long V_66 ,
unsigned long V_53 )
{
if ( V_53 > V_66 )
return 1UL << ( F_75 ( V_53 - V_66 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_95 ( struct V_8 * V_9 ,
unsigned long V_122 )
{
unsigned long V_131 = V_9 -> V_14 ;
unsigned long V_89 ;
V_89 = V_122 / ( 1 + V_131 / F_74 ( 1 + V_127 / 8 ) ) ;
V_89 ++ ;
return F_70 (unsigned long, t, MAX_PAUSE) ;
}
static long F_96 ( struct V_8 * V_9 ,
long V_155 ,
unsigned long V_141 ,
unsigned long V_139 ,
int * V_156 )
{
long V_157 = F_75 ( V_9 -> V_14 ) ;
long V_158 = F_75 ( V_9 -> V_139 ) ;
long V_89 ;
long V_159 ;
int V_160 ;
V_89 = V_20 ( 1 , V_127 / 100 ) ;
if ( V_157 > V_158 )
V_89 += ( V_157 - V_158 ) * ( 10 * V_127 ) / 1024 ;
V_89 = V_18 ( V_89 , 1 + V_155 / 2 ) ;
V_160 = V_139 * V_89 / F_74 ( V_127 ) ;
if ( V_160 < V_161 ) {
V_89 = V_155 ;
V_160 = V_139 * V_89 / F_74 ( V_127 ) ;
if ( V_160 > V_161 ) {
V_160 = V_161 ;
V_89 = V_127 * V_161 / V_139 ;
}
}
V_159 = V_127 * V_160 / ( V_141 + 1 ) ;
if ( V_159 > V_155 ) {
V_89 = V_155 ;
V_160 = V_141 * V_89 / F_74 ( V_127 ) ;
}
* V_156 = V_160 ;
return V_160 >= V_161 ? 1 + V_89 / 2 : V_89 ;
}
static inline void F_97 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_162 ;
V_2 -> V_104 = F_62 ( V_2 ) ;
V_2 -> V_123 = V_2 -> V_53 ?
F_71 ( ( T_5 ) V_2 -> V_104 * V_2 -> V_54 , V_2 -> V_53 ) : 0 ;
if ( V_2 -> V_104 < 2 * F_98 ( V_9 ) ) {
V_162 = F_99 ( V_9 , V_163 ) ;
V_2 -> V_122 = V_162 + F_99 ( V_9 , V_164 ) ;
} else {
V_162 = F_100 ( V_9 , V_163 ) ;
V_2 -> V_122 = V_162 + F_100 ( V_9 , V_164 ) ;
}
}
static void F_101 ( struct V_165 * V_166 ,
struct V_8 * V_9 ,
unsigned long V_167 )
{
struct V_1 V_168 = { F_65 (wb) } ;
struct V_1 V_169 = { F_102 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_168 ;
struct V_1 * const V_5 = F_1 ( & V_169 ) ?
& V_169 : NULL ;
struct V_1 * V_170 ;
unsigned long V_171 ;
long V_126 ;
long V_159 ;
long V_155 ;
long V_172 ;
int V_156 ;
bool V_173 = false ;
unsigned long V_141 ;
unsigned long V_139 ;
struct V_94 * V_16 = V_9 -> V_16 ;
bool V_174 = V_16 -> V_119 & V_120 ;
unsigned long V_147 = V_85 ;
for (; ; ) {
unsigned long V_136 = V_85 ;
unsigned long V_66 , V_53 , V_54 ;
unsigned long V_175 = 0 ;
unsigned long V_176 = 0 ;
unsigned long V_177 = 0 ;
V_171 = F_20 ( V_68 ) +
F_20 ( V_69 ) ;
V_6 -> V_43 = F_18 () ;
V_6 -> V_66 = V_171 + F_20 ( V_70 ) ;
F_21 ( V_6 ) ;
if ( F_38 ( V_174 ) ) {
F_97 ( V_6 ) ;
V_66 = V_6 -> V_122 ;
V_53 = V_6 -> V_104 ;
V_54 = V_6 -> V_123 ;
} else {
V_66 = V_6 -> V_66 ;
V_53 = V_6 -> V_53 ;
V_54 = V_6 -> V_54 ;
}
if ( V_5 ) {
unsigned long V_99 , V_100 , V_178 ;
F_103 ( V_9 , & V_99 , & V_100 ,
& V_5 -> V_66 , & V_178 ) ;
V_5 -> V_66 += V_178 ;
F_61 ( V_5 , V_99 , V_100 ) ;
F_21 ( V_5 ) ;
if ( F_38 ( V_174 ) ) {
F_97 ( V_5 ) ;
V_175 = V_5 -> V_122 ;
V_176 = V_5 -> V_104 ;
V_177 = V_5 -> V_123 ;
} else {
V_175 = V_5 -> V_66 ;
V_176 = V_5 -> V_53 ;
V_177 = V_5 -> V_54 ;
}
}
if ( V_66 <= F_59 ( V_53 , V_54 ) &&
( ! V_5 ||
V_175 <= F_59 ( V_176 , V_177 ) ) ) {
unsigned long V_179 = F_94 ( V_66 , V_53 ) ;
unsigned long V_180 = V_181 ;
V_58 -> V_182 = V_136 ;
V_58 -> V_183 = 0 ;
if ( V_5 )
V_180 = F_94 ( V_175 , V_176 ) ;
V_58 -> V_156 = V_18 ( V_179 , V_180 ) ;
break;
}
if ( F_38 ( ! F_104 ( V_9 ) ) )
F_105 ( V_9 ) ;
if ( ! V_174 )
F_97 ( V_6 ) ;
V_173 = ( V_6 -> V_122 > V_6 -> V_104 ) &&
( ( V_6 -> V_66 > V_6 -> V_53 ) || V_174 ) ;
F_69 ( V_6 ) ;
V_170 = V_6 ;
if ( V_5 ) {
if ( ! V_174 )
F_97 ( V_5 ) ;
V_173 |= ( V_5 -> V_122 > V_5 -> V_104 ) &&
( ( V_5 -> V_66 > V_5 -> V_53 ) || V_174 ) ;
F_69 ( V_5 ) ;
if ( V_5 -> V_111 < V_6 -> V_111 )
V_170 = V_5 ;
}
if ( V_173 && ! V_9 -> V_173 )
V_9 -> V_173 = 1 ;
if ( F_106 ( V_9 -> V_149 +
V_137 ) ) {
F_82 ( & V_9 -> V_150 ) ;
F_89 ( V_6 , V_5 , V_147 , true ) ;
F_84 ( & V_9 -> V_150 ) ;
}
V_139 = V_9 -> V_139 ;
V_141 = ( ( T_5 ) V_139 * V_170 -> V_111 ) >>
V_113 ;
V_155 = F_95 ( V_9 , V_170 -> V_122 ) ;
V_172 = F_96 ( V_9 , V_155 ,
V_141 , V_139 ,
& V_156 ) ;
if ( F_38 ( V_141 == 0 ) ) {
V_126 = V_155 ;
V_159 = V_155 ;
goto V_159;
}
V_126 = V_127 * V_167 / V_141 ;
V_159 = V_126 ;
if ( V_58 -> V_182 )
V_159 -= V_136 - V_58 -> V_182 ;
if ( V_159 < V_172 ) {
F_107 ( V_9 ,
V_170 -> V_53 ,
V_170 -> V_54 ,
V_170 -> V_66 ,
V_170 -> V_104 ,
V_170 -> V_122 ,
V_139 ,
V_141 ,
V_167 ,
V_126 ,
V_18 ( V_159 , 0L ) ,
V_147 ) ;
if ( V_159 < - V_127 ) {
V_58 -> V_182 = V_136 ;
V_58 -> V_183 = 0 ;
} else if ( V_126 ) {
V_58 -> V_182 += V_126 ;
V_58 -> V_183 = 0 ;
} else if ( V_58 -> V_156 <= V_167 )
V_58 -> V_156 += V_167 ;
break;
}
if ( F_38 ( V_159 > V_155 ) ) {
V_136 += V_18 ( V_159 - V_155 , V_155 ) ;
V_159 = V_155 ;
}
V_159:
F_107 ( V_9 ,
V_170 -> V_53 ,
V_170 -> V_54 ,
V_170 -> V_66 ,
V_170 -> V_104 ,
V_170 -> V_122 ,
V_139 ,
V_141 ,
V_167 ,
V_126 ,
V_159 ,
V_147 ) ;
F_108 ( V_184 ) ;
V_9 -> V_185 = V_136 ;
F_109 ( V_159 ) ;
V_58 -> V_182 = V_136 + V_159 ;
V_58 -> V_183 = 0 ;
V_58 -> V_156 = V_156 ;
if ( V_141 )
break;
if ( V_170 -> V_122 <= F_98 ( V_9 ) )
break;
if ( F_110 ( V_58 ) )
break;
}
if ( ! V_173 && V_9 -> V_173 )
V_9 -> V_173 = 0 ;
if ( F_104 ( V_9 ) )
return;
if ( V_186 )
return;
if ( V_171 > V_6 -> V_54 )
F_105 ( V_9 ) ;
}
void F_111 ( struct V_165 * V_166 )
{
struct V_187 * V_187 = V_166 -> V_188 ;
struct V_94 * V_16 = F_112 ( V_187 ) ;
struct V_8 * V_9 = NULL ;
int V_189 ;
int * V_190 ;
if ( ! F_113 ( V_16 ) )
return;
if ( F_114 ( V_187 ) )
V_9 = F_115 ( V_16 , V_191 ) ;
if ( ! V_9 )
V_9 = & V_16 -> V_9 ;
V_189 = V_58 -> V_156 ;
if ( V_9 -> V_173 )
V_189 = V_18 ( V_189 , 32 >> ( V_192 - 10 ) ) ;
F_116 () ;
V_190 = F_117 ( & V_193 ) ;
if ( F_38 ( V_58 -> V_183 >= V_189 ) )
* V_190 = 0 ;
else if ( F_38 ( * V_190 >= V_194 ) ) {
* V_190 = 0 ;
V_189 = 0 ;
}
V_190 = F_117 ( & V_195 ) ;
if ( * V_190 > 0 && V_58 -> V_183 < V_189 ) {
unsigned long V_196 ;
V_196 = V_18 ( * V_190 , V_189 - V_58 -> V_183 ) ;
* V_190 -= V_196 ;
V_58 -> V_183 += V_196 ;
}
F_118 () ;
if ( F_38 ( V_58 -> V_183 >= V_189 ) )
F_101 ( V_166 , V_9 , V_58 -> V_183 ) ;
F_119 ( V_9 ) ;
}
bool F_120 ( struct V_8 * V_9 )
{
struct V_1 V_168 = { F_65 (wb) } ;
struct V_1 V_169 = { F_102 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_168 ;
struct V_1 * const V_5 = F_1 ( & V_169 ) ?
& V_169 : NULL ;
V_6 -> V_43 = F_18 () ;
V_6 -> V_66 = F_20 ( V_68 ) +
F_20 ( V_69 ) ;
F_21 ( V_6 ) ;
if ( V_6 -> V_66 > V_6 -> V_54 )
return true ;
if ( F_100 ( V_9 , V_163 ) >
F_64 ( V_6 -> V_9 , V_6 -> V_54 ) )
return true ;
if ( V_5 ) {
unsigned long V_99 , V_100 , V_178 ;
F_103 ( V_9 , & V_99 , & V_100 , & V_5 -> V_66 ,
& V_178 ) ;
F_61 ( V_5 , V_99 , V_100 ) ;
F_21 ( V_5 ) ;
if ( V_5 -> V_66 > V_5 -> V_54 )
return true ;
if ( F_100 ( V_9 , V_163 ) >
F_64 ( V_5 -> V_9 , V_5 -> V_54 ) )
return true ;
}
return false ;
}
int F_121 ( struct V_71 * V_72 , int V_73 ,
void T_1 * V_74 , T_2 * V_197 , T_3 * V_76 )
{
F_122 ( V_72 , V_73 , V_74 , V_197 , V_76 ) ;
return 0 ;
}
void F_123 ( unsigned long V_198 )
{
struct V_199 * V_200 = (struct V_199 * ) V_198 ;
int V_25 = F_20 ( V_68 ) +
F_20 ( V_69 ) ;
struct V_8 * V_9 ;
if ( ! F_124 ( V_200 -> V_94 ) )
return;
F_125 () ;
F_126 (wb, &q->backing_dev_info->wb_list, bdi_node)
if ( F_76 ( V_9 ) )
F_127 ( V_9 , V_25 , true ,
V_201 ) ;
F_128 () ;
}
void F_129 ( struct V_94 * V_202 )
{
F_39 ( & V_202 -> V_203 , V_85 + V_186 ) ;
}
void F_130 ( void )
{
struct V_94 * V_16 ;
F_125 () ;
F_126 (bdi, &bdi_list, bdi_list)
F_131 ( & V_16 -> V_203 ) ;
F_128 () ;
}
void F_33 ( void )
{
struct V_4 * V_3 = & V_22 ;
unsigned long V_204 ;
unsigned long V_205 ;
F_25 ( & V_204 , & V_205 ) ;
V_3 -> V_61 = V_205 ;
V_194 = V_205 / ( F_132 () * 32 ) ;
if ( V_194 < 16 )
V_194 = 16 ;
}
static int F_133 ( unsigned int V_206 )
{
F_33 () ;
return 0 ;
}
void T_6 F_134 ( void )
{
F_135 ( F_48 ( & V_22 , V_191 ) ) ;
F_136 ( V_207 , L_1 ,
F_133 , NULL ) ;
F_136 ( V_208 , L_2 , NULL ,
F_133 ) ;
}
void F_137 ( struct V_165 * V_166 ,
T_7 V_209 , T_7 V_210 )
{
#define F_138 4096
unsigned long V_211 = 0 ;
struct V_212 V_213 ;
void * * V_214 ;
F_139 ( & V_166 -> V_215 ) ;
F_140 (slot, &mapping->page_tree, &iter, start,
PAGECACHE_TAG_DIRTY) {
if ( V_213 . V_216 > V_210 )
break;
F_141 ( & V_166 -> V_217 , & V_213 ,
V_218 ) ;
V_211 ++ ;
if ( ( V_211 % F_138 ) != 0 )
continue;
V_214 = F_142 ( V_214 , & V_213 ) ;
F_143 ( & V_166 -> V_215 ) ;
F_144 () ;
F_139 ( & V_166 -> V_215 ) ;
}
F_143 ( & V_166 -> V_215 ) ;
}
int F_145 ( struct V_165 * V_166 ,
struct V_219 * V_220 , T_8 V_221 ,
void * V_198 )
{
int V_77 = 0 ;
int V_222 = 0 ;
struct V_223 V_224 ;
int V_25 ;
T_7 V_225 ( V_226 ) ;
T_7 V_216 ;
T_7 V_210 ;
T_7 V_227 ;
int V_228 ;
int V_229 = 0 ;
int V_230 ;
F_146 ( & V_224 , 0 ) ;
if ( V_220 -> V_231 ) {
V_226 = V_166 -> V_226 ;
V_216 = V_226 ;
if ( V_216 == 0 )
V_228 = 1 ;
else
V_228 = 0 ;
V_210 = - 1 ;
} else {
V_216 = V_220 -> V_232 >> V_192 ;
V_210 = V_220 -> V_233 >> V_192 ;
if ( V_220 -> V_232 == 0 && V_220 -> V_233 == V_234 )
V_229 = 1 ;
V_228 = 1 ;
}
if ( V_220 -> V_235 == V_236 || V_220 -> V_237 )
V_230 = V_218 ;
else
V_230 = V_238 ;
V_239:
if ( V_220 -> V_235 == V_236 || V_220 -> V_237 )
F_137 ( V_166 , V_216 , V_210 ) ;
V_227 = V_216 ;
while ( ! V_222 && ( V_216 <= V_210 ) ) {
int V_37 ;
V_25 = F_147 ( & V_224 , V_166 , & V_216 , V_230 ,
V_18 ( V_210 - V_216 , ( T_7 ) V_240 - 1 ) + 1 ) ;
if ( V_25 == 0 )
break;
for ( V_37 = 0 ; V_37 < V_25 ; V_37 ++ ) {
struct V_241 * V_241 = V_224 . V_160 [ V_37 ] ;
if ( V_241 -> V_216 > V_210 ) {
V_222 = 1 ;
break;
}
V_227 = V_241 -> V_216 ;
F_148 ( V_241 ) ;
if ( F_38 ( V_241 -> V_166 != V_166 ) ) {
V_242:
F_149 ( V_241 ) ;
continue;
}
if ( ! F_150 ( V_241 ) ) {
goto V_242;
}
if ( F_151 ( V_241 ) ) {
if ( V_220 -> V_235 != V_243 )
F_152 ( V_241 ) ;
else
goto V_242;
}
F_135 ( F_151 ( V_241 ) ) ;
if ( ! F_153 ( V_241 ) )
goto V_242;
F_154 ( V_220 , F_112 ( V_166 -> V_188 ) ) ;
V_77 = (* V_221)( V_241 , V_220 , V_198 ) ;
if ( F_38 ( V_77 ) ) {
if ( V_77 == V_244 ) {
F_149 ( V_241 ) ;
V_77 = 0 ;
} else {
V_227 = V_241 -> V_216 + 1 ;
V_222 = 1 ;
break;
}
}
if ( -- V_220 -> V_245 <= 0 &&
V_220 -> V_235 == V_243 ) {
V_222 = 1 ;
break;
}
}
F_155 ( & V_224 ) ;
F_144 () ;
}
if ( ! V_228 && ! V_222 ) {
V_228 = 1 ;
V_216 = 0 ;
V_210 = V_226 - 1 ;
goto V_239;
}
if ( V_220 -> V_231 || ( V_229 && V_220 -> V_245 > 0 ) )
V_166 -> V_226 = V_227 ;
return V_77 ;
}
static int F_156 ( struct V_241 * V_241 , struct V_219 * V_220 ,
void * V_198 )
{
struct V_165 * V_166 = V_198 ;
int V_77 = V_166 -> V_246 -> V_221 ( V_241 , V_220 ) ;
F_157 ( V_166 , V_77 ) ;
return V_77 ;
}
int F_158 ( struct V_165 * V_166 ,
struct V_219 * V_220 )
{
struct V_247 V_248 ;
int V_77 ;
if ( ! V_166 -> V_246 -> V_221 )
return 0 ;
F_159 ( & V_248 ) ;
V_77 = F_145 ( V_166 , V_220 , F_156 , V_166 ) ;
F_160 ( & V_248 ) ;
return V_77 ;
}
int F_161 ( struct V_165 * V_166 , struct V_219 * V_220 )
{
int V_77 ;
if ( V_220 -> V_245 <= 0 )
return 0 ;
while ( 1 ) {
if ( V_166 -> V_246 -> V_249 )
V_77 = V_166 -> V_246 -> V_249 ( V_166 , V_220 ) ;
else
V_77 = F_158 ( V_166 , V_220 ) ;
if ( ( V_77 != - V_250 ) || ( V_220 -> V_235 != V_236 ) )
break;
F_144 () ;
F_162 ( V_251 , V_127 / 50 ) ;
}
return V_77 ;
}
int F_163 ( struct V_241 * V_241 )
{
struct V_165 * V_166 = V_241 -> V_166 ;
int V_77 = 0 ;
struct V_219 V_220 = {
. V_235 = V_236 ,
. V_245 = 1 ,
} ;
F_135 ( ! F_164 ( V_241 ) ) ;
F_152 ( V_241 ) ;
if ( F_153 ( V_241 ) ) {
F_165 ( V_241 ) ;
V_77 = V_166 -> V_246 -> V_221 ( V_241 , & V_220 ) ;
if ( V_77 == 0 )
F_152 ( V_241 ) ;
F_166 ( V_241 ) ;
} else {
F_149 ( V_241 ) ;
}
if ( ! V_77 )
V_77 = F_167 ( V_166 ) ;
return V_77 ;
}
int F_168 ( struct V_241 * V_241 )
{
if ( ! F_150 ( V_241 ) )
return ! F_169 ( V_241 ) ;
return 0 ;
}
void F_170 ( struct V_241 * V_241 , struct V_165 * V_166 )
{
struct V_187 * V_187 = V_166 -> V_188 ;
F_171 ( V_241 , V_166 ) ;
if ( F_172 ( V_166 ) ) {
struct V_8 * V_9 ;
F_173 ( V_187 , V_241 ) ;
V_9 = F_174 ( V_187 ) ;
F_175 ( V_241 , V_68 ) ;
F_176 ( V_241 , V_252 ) ;
F_177 ( V_241 , V_253 ) ;
F_41 ( V_9 , V_163 ) ;
F_41 ( V_9 , V_152 ) ;
F_178 ( V_50 ) ;
V_58 -> V_183 ++ ;
F_179 ( V_193 ) ;
}
}
void F_180 ( struct V_241 * V_241 , struct V_165 * V_166 ,
struct V_8 * V_9 )
{
if ( F_172 ( V_166 ) ) {
F_181 ( V_241 , V_68 ) ;
F_182 ( V_241 , V_252 ) ;
F_183 ( V_9 , V_163 ) ;
F_184 ( V_50 ) ;
}
}
int F_185 ( struct V_241 * V_241 )
{
F_186 ( V_241 ) ;
if ( ! F_169 ( V_241 ) ) {
struct V_165 * V_166 = F_187 ( V_241 ) ;
unsigned long V_59 ;
if ( ! V_166 ) {
F_188 ( V_241 ) ;
return 1 ;
}
F_189 ( & V_166 -> V_215 , V_59 ) ;
F_135 ( F_187 ( V_241 ) != V_166 ) ;
F_77 ( ! F_190 ( V_241 ) && ! F_191 ( V_241 ) ) ;
F_170 ( V_241 , V_166 ) ;
F_192 ( & V_166 -> V_217 , F_193 ( V_241 ) ,
V_238 ) ;
F_194 ( & V_166 -> V_215 , V_59 ) ;
F_188 ( V_241 ) ;
if ( V_166 -> V_188 ) {
F_195 ( V_166 -> V_188 , V_254 ) ;
}
return 1 ;
}
F_188 ( V_241 ) ;
return 0 ;
}
void F_196 ( struct V_241 * V_241 )
{
struct V_165 * V_166 = V_241 -> V_166 ;
if ( V_166 && F_172 ( V_166 ) ) {
struct V_187 * V_187 = V_166 -> V_188 ;
struct V_8 * V_9 ;
bool V_255 ;
V_9 = F_197 ( V_187 , & V_255 ) ;
V_58 -> V_183 -- ;
F_198 ( V_241 , V_253 ) ;
F_183 ( V_9 , V_152 ) ;
F_199 ( V_187 , V_255 ) ;
}
}
int F_200 ( struct V_219 * V_220 , struct V_241 * V_241 )
{
int V_77 ;
V_220 -> V_256 ++ ;
V_77 = F_185 ( V_241 ) ;
F_196 ( V_241 ) ;
return V_77 ;
}
int F_201 ( struct V_241 * V_241 )
{
struct V_165 * V_166 = F_187 ( V_241 ) ;
V_241 = F_202 ( V_241 ) ;
if ( F_203 ( V_166 ) ) {
int (* F_204)( struct V_241 * ) = V_166 -> V_246 -> F_201 ;
if ( F_205 ( V_241 ) )
F_206 ( V_241 ) ;
#ifdef F_207
if ( ! F_204 )
F_204 = V_257 ;
#endif
return (* F_204)( V_241 ) ;
}
if ( ! F_150 ( V_241 ) ) {
if ( ! F_169 ( V_241 ) )
return 1 ;
}
return 0 ;
}
int F_208 ( struct V_241 * V_241 )
{
int V_77 ;
F_148 ( V_241 ) ;
V_77 = F_201 ( V_241 ) ;
F_149 ( V_241 ) ;
return V_77 ;
}
void F_209 ( struct V_241 * V_241 )
{
struct V_165 * V_166 = F_187 ( V_241 ) ;
if ( F_172 ( V_166 ) ) {
struct V_187 * V_187 = V_166 -> V_188 ;
struct V_8 * V_9 ;
bool V_255 ;
F_186 ( V_241 ) ;
V_9 = F_197 ( V_187 , & V_255 ) ;
if ( F_210 ( V_241 ) )
F_180 ( V_241 , V_166 , V_9 ) ;
F_199 ( V_187 , V_255 ) ;
F_188 ( V_241 ) ;
} else {
F_211 ( V_241 ) ;
}
}
int F_153 ( struct V_241 * V_241 )
{
struct V_165 * V_166 = F_187 ( V_241 ) ;
int V_77 = 0 ;
F_135 ( ! F_164 ( V_241 ) ) ;
if ( V_166 && F_172 ( V_166 ) ) {
struct V_187 * V_187 = V_166 -> V_188 ;
struct V_8 * V_9 ;
bool V_255 ;
if ( F_212 ( V_241 ) )
F_201 ( V_241 ) ;
V_9 = F_197 ( V_187 , & V_255 ) ;
if ( F_210 ( V_241 ) ) {
F_181 ( V_241 , V_68 ) ;
F_182 ( V_241 , V_252 ) ;
F_183 ( V_9 , V_163 ) ;
V_77 = 1 ;
}
F_199 ( V_187 , V_255 ) ;
return V_77 ;
}
return F_210 ( V_241 ) ;
}
int F_213 ( struct V_241 * V_241 )
{
struct V_165 * V_166 = F_187 ( V_241 ) ;
struct V_258 * V_259 ;
struct V_260 * V_260 ;
int V_77 ;
V_259 = F_186 ( V_241 ) ;
V_260 = F_214 ( V_241 , F_215 ( V_241 ) ) ;
if ( V_166 && F_216 ( V_166 ) ) {
struct V_187 * V_187 = V_166 -> V_188 ;
struct V_94 * V_16 = F_112 ( V_187 ) ;
unsigned long V_59 ;
F_189 ( & V_166 -> V_215 , V_59 ) ;
V_77 = F_217 ( V_241 ) ;
if ( V_77 ) {
F_218 ( & V_166 -> V_217 ,
F_193 ( V_241 ) ,
V_261 ) ;
if ( F_219 ( V_16 ) ) {
struct V_8 * V_9 = F_174 ( V_187 ) ;
F_183 ( V_9 , V_164 ) ;
F_40 ( V_9 ) ;
}
}
if ( V_166 -> V_188 && ! F_220 ( V_166 ,
V_261 ) )
F_221 ( V_166 -> V_188 ) ;
F_194 ( & V_166 -> V_215 , V_59 ) ;
} else {
V_77 = F_217 ( V_241 ) ;
}
if ( V_77 ) {
F_222 ( V_260 , V_70 ) ;
F_182 ( V_241 , V_252 ) ;
F_223 ( V_241 , V_262 ) ;
}
F_224 ( V_259 ) ;
return V_77 ;
}
int F_225 ( struct V_241 * V_241 , bool V_263 )
{
struct V_165 * V_166 = F_187 ( V_241 ) ;
int V_77 ;
F_186 ( V_241 ) ;
if ( V_166 && F_216 ( V_166 ) ) {
struct V_187 * V_187 = V_166 -> V_188 ;
struct V_94 * V_16 = F_112 ( V_187 ) ;
unsigned long V_59 ;
F_189 ( & V_166 -> V_215 , V_59 ) ;
V_77 = F_226 ( V_241 ) ;
if ( ! V_77 ) {
bool V_264 ;
V_264 = F_220 ( V_166 ,
V_261 ) ;
F_192 ( & V_166 -> V_217 ,
F_193 ( V_241 ) ,
V_261 ) ;
if ( F_219 ( V_16 ) )
F_41 ( F_174 ( V_187 ) , V_164 ) ;
if ( V_166 -> V_188 && ! V_264 )
F_227 ( V_166 -> V_188 ) ;
}
if ( ! F_150 ( V_241 ) )
F_218 ( & V_166 -> V_217 ,
F_193 ( V_241 ) ,
V_238 ) ;
if ( ! V_263 )
F_218 ( & V_166 -> V_217 ,
F_193 ( V_241 ) ,
V_218 ) ;
F_194 ( & V_166 -> V_215 , V_59 ) ;
} else {
V_77 = F_226 ( V_241 ) ;
}
if ( ! V_77 ) {
F_228 ( V_241 , V_70 ) ;
F_229 ( V_241 , V_252 ) ;
}
F_188 ( V_241 ) ;
return V_77 ;
}
int F_220 ( struct V_165 * V_166 , int V_230 )
{
return F_230 ( & V_166 -> V_217 , V_230 ) ;
}
void F_231 ( struct V_241 * V_241 )
{
if ( F_232 ( F_112 ( V_241 -> V_166 -> V_188 ) ) )
F_152 ( V_241 ) ;
}
