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
if ( ! F_38 ( V_3 -> V_84 ) ) {
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
F_50 ( & V_3 -> V_86 ) ;
V_3 -> V_86 . V_93 = F_46 ;
V_3 -> V_86 . V_94 = ( unsigned long ) V_3 ;
V_3 -> V_95 = V_85 ;
return F_51 ( & V_3 -> V_82 , V_91 ) ;
}
void F_52 ( struct V_4 * V_3 )
{
F_53 ( & V_3 -> V_86 ) ;
F_54 ( & V_3 -> V_82 ) ;
}
int F_55 ( struct V_96 * V_16 , unsigned int V_19 )
{
int V_77 = 0 ;
F_56 ( & V_97 ) ;
if ( V_19 > V_16 -> V_21 ) {
V_77 = - V_98 ;
} else {
V_19 -= V_16 -> V_19 ;
if ( V_99 + V_19 < 100 ) {
V_99 += V_19 ;
V_16 -> V_19 += V_19 ;
} else {
V_77 = - V_98 ;
}
}
F_57 ( & V_97 ) ;
return V_77 ;
}
int F_58 ( struct V_96 * V_16 , unsigned V_21 )
{
int V_77 = 0 ;
if ( V_21 > 100 )
return - V_98 ;
F_56 ( & V_97 ) ;
if ( V_16 -> V_19 > V_21 ) {
V_77 = - V_98 ;
} else {
V_16 -> V_21 = V_21 ;
V_16 -> V_83 = ( V_100 * V_21 ) / 100 ;
}
F_57 ( & V_97 ) ;
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
unsigned long V_101 , unsigned long V_102 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_103 = V_101 - V_18 ( V_101 , V_5 -> V_66 ) ;
unsigned long V_104 = V_6 -> V_43 - V_18 ( V_6 -> V_43 , V_6 -> V_66 ) ;
unsigned long V_105 = V_104 - V_18 ( V_104 , V_103 ) ;
V_5 -> V_43 = V_101 + V_18 ( V_102 , V_105 ) ;
}
static unsigned long F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_53 = V_2 -> V_53 ;
T_5 V_106 ;
long V_107 , V_108 ;
unsigned long V_109 , V_110 ;
F_63 ( & V_3 -> V_82 , V_2 -> V_111 ,
& V_107 , & V_108 ) ;
V_106 = ( V_53 * ( 100 - V_99 ) ) / 100 ;
V_106 *= V_107 ;
F_7 ( V_106 , V_108 ) ;
F_5 ( V_2 -> V_9 , & V_109 , & V_110 ) ;
V_106 += ( V_53 * V_109 ) / 100 ;
if ( V_106 > ( V_53 * V_110 ) / 100 )
V_106 = V_53 * V_110 / 100 ;
return V_106 ;
}
unsigned long F_64 ( struct V_8 * V_9 , unsigned long V_53 )
{
struct V_1 V_6 = { F_65 ( V_9 ) ,
. V_53 = V_53 } ;
return F_62 ( & V_6 ) ;
}
static long long F_66 ( unsigned long V_112 ,
unsigned long V_66 ,
unsigned long V_67 )
{
long long V_113 ;
long V_36 ;
V_36 = F_67 ( ( ( V_114 ) V_112 - ( V_114 ) V_66 ) << V_115 ,
( V_67 - V_112 ) | 1 ) ;
V_113 = V_36 ;
V_113 = V_113 * V_36 >> V_115 ;
V_113 = V_113 * V_36 >> V_115 ;
V_113 += 1 << V_115 ;
return F_68 ( V_113 , 0LL , 2LL << V_115 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_116 = V_9 -> V_14 ;
unsigned long V_117 = F_59 ( V_2 -> V_53 , V_2 -> V_54 ) ;
unsigned long V_67 = F_60 ( F_2 ( V_2 ) , V_2 -> V_53 ) ;
unsigned long V_106 = V_2 -> V_106 ;
unsigned long V_118 ;
unsigned long V_112 ;
unsigned long V_119 ;
unsigned long V_120 ;
long long V_113 ;
long V_36 ;
V_2 -> V_113 = 0 ;
if ( F_38 ( V_2 -> V_66 >= V_67 ) )
return;
V_112 = ( V_117 + V_67 ) / 2 ;
V_113 = F_66 ( V_112 , V_2 -> V_66 , V_67 ) ;
if ( F_38 ( V_9 -> V_16 -> V_121 & V_122 ) ) {
long long V_123 ;
if ( V_2 -> V_124 < 8 ) {
V_2 -> V_113 = F_70 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
return;
}
if ( V_2 -> V_124 >= V_106 )
return;
V_119 = F_59 ( V_106 ,
V_2 -> V_125 ) ;
if ( V_119 == 0 || V_119 == V_106 )
return;
V_123 = F_66 ( V_119 , V_2 -> V_124 ,
V_106 ) ;
V_2 -> V_113 = V_18 ( V_113 , V_123 ) ;
return;
}
if ( F_38 ( V_106 > V_2 -> V_53 ) )
V_106 = V_2 -> V_53 ;
V_106 = V_20 ( V_106 , ( V_67 - V_2 -> V_66 ) / 8 ) ;
V_36 = F_71 ( ( T_5 ) V_106 << 16 , V_2 -> V_53 | 1 ) ;
V_119 = V_112 * ( T_5 ) V_36 >> 16 ;
V_120 = ( V_2 -> V_53 - V_106 + 8 * V_116 ) * ( T_5 ) V_36 >> 16 ;
V_118 = V_119 + V_120 ;
if ( V_2 -> V_124 < V_118 - V_120 / 4 ) {
V_113 = F_72 ( V_113 * ( V_118 - V_2 -> V_124 ) ,
( V_118 - V_119 ) | 1 ) ;
} else
V_113 /= 4 ;
V_118 = V_106 / 2 ;
if ( V_2 -> V_124 < V_118 ) {
if ( V_2 -> V_124 > V_118 / 8 )
V_113 = F_71 ( V_113 * V_118 ,
V_2 -> V_124 ) ;
else
V_113 *= 8 ;
}
V_2 -> V_113 = V_113 ;
}
static void F_73 ( struct V_8 * V_9 ,
unsigned long V_126 ,
unsigned long V_127 )
{
const unsigned long V_128 = F_74 ( 3 * V_129 ) ;
unsigned long V_130 = V_9 -> V_14 ;
unsigned long V_131 = V_9 -> V_132 ;
T_5 V_133 ;
V_133 = V_127 - V_18 ( V_127 , V_9 -> V_134 ) ;
V_133 *= V_129 ;
if ( F_38 ( V_126 > V_128 ) ) {
F_7 ( V_133 , V_126 ) ;
V_130 = V_133 ;
goto V_135;
}
V_133 += ( T_5 ) V_9 -> V_132 * ( V_128 - V_126 ) ;
V_133 >>= F_75 ( V_128 ) ;
if ( V_130 > V_131 && V_131 >= ( unsigned long ) V_133 )
V_130 -= ( V_130 - V_131 ) >> 3 ;
if ( V_130 < V_131 && V_131 <= ( unsigned long ) V_133 )
V_130 += ( V_131 - V_130 ) >> 3 ;
V_135:
V_130 = V_20 ( V_130 , 1LU ) ;
if ( F_76 ( V_9 ) ) {
long V_136 = V_130 - V_9 -> V_14 ;
F_77 ( F_78 ( V_136 ,
& V_9 -> V_16 -> V_17 ) <= 0 ) ;
}
V_9 -> V_132 = V_133 ;
V_9 -> V_14 = V_130 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_53 = V_2 -> V_53 ;
unsigned long V_67 = V_3 -> V_61 ;
if ( V_67 < V_53 ) {
V_67 = V_53 ;
goto V_137;
}
V_53 = V_20 ( V_53 , V_2 -> V_66 ) ;
if ( V_67 > V_53 ) {
V_67 -= ( V_67 - V_53 ) >> 5 ;
goto V_137;
}
return;
V_137:
V_3 -> V_61 = V_67 ;
}
static void F_80 ( struct V_1 * V_2 ,
unsigned long V_138 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
if ( F_81 ( V_138 , V_3 -> V_95 + V_139 ) )
return;
F_82 ( & V_3 -> V_92 ) ;
if ( F_83 ( V_138 , V_3 -> V_95 + V_139 ) ) {
F_79 ( V_2 ) ;
V_3 -> V_95 = V_138 ;
}
F_84 ( & V_3 -> V_92 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
unsigned long V_140 ,
unsigned long V_126 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_66 = V_2 -> V_66 ;
unsigned long V_117 = F_59 ( V_2 -> V_53 , V_2 -> V_54 ) ;
unsigned long V_67 = F_60 ( F_2 ( V_2 ) , V_2 -> V_53 ) ;
unsigned long V_112 = ( V_117 + V_67 ) / 2 ;
unsigned long V_116 = V_9 -> V_14 ;
unsigned long V_141 = V_9 -> V_141 ;
unsigned long V_142 ;
unsigned long V_143 ;
unsigned long V_144 ;
unsigned long V_145 ;
unsigned long V_36 ;
unsigned long V_146 ;
V_142 = ( V_140 - V_9 -> V_147 ) * V_129 / V_126 ;
V_143 = ( T_5 ) V_141 *
V_2 -> V_113 >> V_115 ;
V_143 ++ ;
V_144 = F_71 ( ( T_5 ) V_143 * V_116 ,
V_142 | 1 ) ;
if ( F_38 ( V_144 > V_116 ) )
V_144 = V_116 ;
V_145 = 0 ;
if ( F_38 ( V_9 -> V_16 -> V_121 & V_122 ) ) {
V_66 = V_2 -> V_124 ;
if ( V_2 -> V_124 < 8 )
V_112 = V_2 -> V_124 + 1 ;
else
V_112 = ( V_2 -> V_106 + V_2 -> V_125 ) / 2 ;
}
if ( V_66 < V_112 ) {
V_36 = F_86 ( V_9 -> V_144 ,
V_144 , V_143 ) ;
if ( V_141 < V_36 )
V_145 = V_36 - V_141 ;
} else {
V_36 = F_87 ( V_9 -> V_144 ,
V_144 , V_143 ) ;
if ( V_141 > V_36 )
V_145 = V_141 - V_36 ;
}
V_146 = V_141 / ( 2 * V_145 + 1 ) ;
if ( V_146 < V_148 )
V_145 = F_22 ( V_145 >> V_146 , 8 ) ;
else
V_145 = 0 ;
if ( V_141 < V_144 )
V_141 += V_145 ;
else
V_141 -= V_145 ;
V_9 -> V_141 = V_20 ( V_141 , 1UL ) ;
V_9 -> V_144 = V_144 ;
F_88 ( V_9 , V_142 , V_143 ) ;
}
static void F_89 ( struct V_1 * V_6 ,
struct V_1 * V_5 ,
unsigned long V_149 ,
bool V_150 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned long V_138 = V_85 ;
unsigned long V_126 = V_138 - V_9 -> V_151 ;
unsigned long V_140 ;
unsigned long V_127 ;
F_90 ( & V_9 -> V_152 ) ;
if ( V_126 < V_139 )
return;
V_140 = F_91 ( & V_9 -> V_153 [ V_154 ] ) ;
V_127 = F_91 ( & V_9 -> V_153 [ V_88 ] ) ;
if ( V_126 > V_129 && F_81 ( V_9 -> V_151 , V_149 ) )
goto V_155;
if ( V_150 ) {
F_80 ( V_6 , V_138 ) ;
F_85 ( V_6 , V_140 , V_126 ) ;
if ( F_92 ( V_156 ) && V_5 ) {
F_80 ( V_5 , V_138 ) ;
F_85 ( V_5 , V_140 , V_126 ) ;
}
}
F_73 ( V_9 , V_126 , V_127 ) ;
V_155:
V_9 -> V_147 = V_140 ;
V_9 -> V_134 = V_127 ;
V_9 -> V_151 = V_138 ;
}
void F_93 ( struct V_8 * V_9 , unsigned long V_149 )
{
struct V_1 V_6 = { F_65 (wb) } ;
F_89 ( & V_6 , NULL , V_149 , false ) ;
}
static unsigned long F_94 ( unsigned long V_66 ,
unsigned long V_53 )
{
if ( V_53 > V_66 )
return 1UL << ( F_75 ( V_53 - V_66 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_95 ( struct V_8 * V_9 ,
unsigned long V_124 )
{
unsigned long V_133 = V_9 -> V_14 ;
unsigned long V_89 ;
V_89 = V_124 / ( 1 + V_133 / F_74 ( 1 + V_129 / 8 ) ) ;
V_89 ++ ;
return F_70 (unsigned long, t, MAX_PAUSE) ;
}
static long F_96 ( struct V_8 * V_9 ,
long V_157 ,
unsigned long V_143 ,
unsigned long V_141 ,
int * V_158 )
{
long V_159 = F_75 ( V_9 -> V_14 ) ;
long V_160 = F_75 ( V_9 -> V_141 ) ;
long V_89 ;
long V_161 ;
int V_162 ;
V_89 = V_20 ( 1 , V_129 / 100 ) ;
if ( V_159 > V_160 )
V_89 += ( V_159 - V_160 ) * ( 10 * V_129 ) / 1024 ;
V_89 = V_18 ( V_89 , 1 + V_157 / 2 ) ;
V_162 = V_141 * V_89 / F_74 ( V_129 ) ;
if ( V_162 < V_163 ) {
V_89 = V_157 ;
V_162 = V_141 * V_89 / F_74 ( V_129 ) ;
if ( V_162 > V_163 ) {
V_162 = V_163 ;
V_89 = V_129 * V_163 / V_141 ;
}
}
V_161 = V_129 * V_162 / ( V_143 + 1 ) ;
if ( V_161 > V_157 ) {
V_89 = V_157 ;
V_162 = V_143 * V_89 / F_74 ( V_129 ) ;
}
* V_158 = V_162 ;
return V_162 >= V_163 ? 1 + V_89 / 2 : V_89 ;
}
static inline void F_97 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_164 ;
V_2 -> V_106 = F_62 ( V_2 ) ;
V_2 -> V_125 = V_2 -> V_53 ?
F_71 ( ( T_5 ) V_2 -> V_106 * V_2 -> V_54 , V_2 -> V_53 ) : 0 ;
if ( V_2 -> V_106 < 2 * F_98 ( V_9 ) ) {
V_164 = F_99 ( V_9 , V_165 ) ;
V_2 -> V_124 = V_164 + F_99 ( V_9 , V_166 ) ;
} else {
V_164 = F_100 ( V_9 , V_165 ) ;
V_2 -> V_124 = V_164 + F_100 ( V_9 , V_166 ) ;
}
}
static void F_101 ( struct V_167 * V_168 ,
struct V_8 * V_9 ,
unsigned long V_169 )
{
struct V_1 V_170 = { F_65 (wb) } ;
struct V_1 V_171 = { F_102 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_170 ;
struct V_1 * const V_5 = F_1 ( & V_171 ) ?
& V_171 : NULL ;
struct V_1 * V_172 ;
unsigned long V_173 ;
long V_128 ;
long V_161 ;
long V_157 ;
long V_174 ;
int V_158 ;
bool V_175 = false ;
unsigned long V_143 ;
unsigned long V_141 ;
struct V_96 * V_16 = V_9 -> V_16 ;
bool V_176 = V_16 -> V_121 & V_122 ;
unsigned long V_149 = V_85 ;
for (; ; ) {
unsigned long V_138 = V_85 ;
unsigned long V_66 , V_53 , V_54 ;
unsigned long V_177 = 0 ;
unsigned long V_178 = 0 ;
unsigned long V_179 = 0 ;
V_173 = F_20 ( V_68 ) +
F_20 ( V_69 ) ;
V_6 -> V_43 = F_18 () ;
V_6 -> V_66 = V_173 + F_20 ( V_70 ) ;
F_21 ( V_6 ) ;
if ( F_38 ( V_176 ) ) {
F_97 ( V_6 ) ;
V_66 = V_6 -> V_124 ;
V_53 = V_6 -> V_106 ;
V_54 = V_6 -> V_125 ;
} else {
V_66 = V_6 -> V_66 ;
V_53 = V_6 -> V_53 ;
V_54 = V_6 -> V_54 ;
}
if ( V_5 ) {
unsigned long V_101 , V_102 , V_180 ;
F_103 ( V_9 , & V_101 , & V_102 ,
& V_5 -> V_66 , & V_180 ) ;
V_5 -> V_66 += V_180 ;
F_61 ( V_5 , V_101 , V_102 ) ;
F_21 ( V_5 ) ;
if ( F_38 ( V_176 ) ) {
F_97 ( V_5 ) ;
V_177 = V_5 -> V_124 ;
V_178 = V_5 -> V_106 ;
V_179 = V_5 -> V_125 ;
} else {
V_177 = V_5 -> V_66 ;
V_178 = V_5 -> V_53 ;
V_179 = V_5 -> V_54 ;
}
}
if ( V_66 <= F_59 ( V_53 , V_54 ) &&
( ! V_5 ||
V_177 <= F_59 ( V_178 , V_179 ) ) ) {
unsigned long V_181 = F_94 ( V_66 , V_53 ) ;
unsigned long V_182 = V_183 ;
V_58 -> V_184 = V_138 ;
V_58 -> V_185 = 0 ;
if ( V_5 )
V_182 = F_94 ( V_177 , V_178 ) ;
V_58 -> V_158 = V_18 ( V_181 , V_182 ) ;
break;
}
if ( F_38 ( ! F_104 ( V_9 ) ) )
F_105 ( V_9 ) ;
if ( ! V_176 )
F_97 ( V_6 ) ;
V_175 = ( V_6 -> V_124 > V_6 -> V_106 ) &&
( ( V_6 -> V_66 > V_6 -> V_53 ) || V_176 ) ;
F_69 ( V_6 ) ;
V_172 = V_6 ;
if ( V_5 ) {
if ( ! V_176 )
F_97 ( V_5 ) ;
V_175 |= ( V_5 -> V_124 > V_5 -> V_106 ) &&
( ( V_5 -> V_66 > V_5 -> V_53 ) || V_176 ) ;
F_69 ( V_5 ) ;
if ( V_5 -> V_113 < V_6 -> V_113 )
V_172 = V_5 ;
}
if ( V_175 && ! V_9 -> V_175 )
V_9 -> V_175 = 1 ;
if ( F_106 ( V_9 -> V_151 +
V_139 ) ) {
F_82 ( & V_9 -> V_152 ) ;
F_89 ( V_6 , V_5 , V_149 , true ) ;
F_84 ( & V_9 -> V_152 ) ;
}
V_141 = V_9 -> V_141 ;
V_143 = ( ( T_5 ) V_141 * V_172 -> V_113 ) >>
V_115 ;
V_157 = F_95 ( V_9 , V_172 -> V_124 ) ;
V_174 = F_96 ( V_9 , V_157 ,
V_143 , V_141 ,
& V_158 ) ;
if ( F_38 ( V_143 == 0 ) ) {
V_128 = V_157 ;
V_161 = V_157 ;
goto V_161;
}
V_128 = V_129 * V_169 / V_143 ;
V_161 = V_128 ;
if ( V_58 -> V_184 )
V_161 -= V_138 - V_58 -> V_184 ;
if ( V_161 < V_174 ) {
F_107 ( V_9 ,
V_172 -> V_53 ,
V_172 -> V_54 ,
V_172 -> V_66 ,
V_172 -> V_106 ,
V_172 -> V_124 ,
V_141 ,
V_143 ,
V_169 ,
V_128 ,
V_18 ( V_161 , 0L ) ,
V_149 ) ;
if ( V_161 < - V_129 ) {
V_58 -> V_184 = V_138 ;
V_58 -> V_185 = 0 ;
} else if ( V_128 ) {
V_58 -> V_184 += V_128 ;
V_58 -> V_185 = 0 ;
} else if ( V_58 -> V_158 <= V_169 )
V_58 -> V_158 += V_169 ;
break;
}
if ( F_38 ( V_161 > V_157 ) ) {
V_138 += V_18 ( V_161 - V_157 , V_157 ) ;
V_161 = V_157 ;
}
V_161:
F_107 ( V_9 ,
V_172 -> V_53 ,
V_172 -> V_54 ,
V_172 -> V_66 ,
V_172 -> V_106 ,
V_172 -> V_124 ,
V_141 ,
V_143 ,
V_169 ,
V_128 ,
V_161 ,
V_149 ) ;
F_108 ( V_186 ) ;
F_109 ( V_161 ) ;
V_58 -> V_184 = V_138 + V_161 ;
V_58 -> V_185 = 0 ;
V_58 -> V_158 = V_158 ;
if ( V_143 )
break;
if ( V_172 -> V_124 <= F_98 ( V_9 ) )
break;
if ( F_110 ( V_58 ) )
break;
}
if ( ! V_175 && V_9 -> V_175 )
V_9 -> V_175 = 0 ;
if ( F_104 ( V_9 ) )
return;
if ( V_187 )
return;
if ( V_173 > V_6 -> V_54 )
F_105 ( V_9 ) ;
}
void F_111 ( struct V_167 * V_168 )
{
struct V_188 * V_188 = V_168 -> V_189 ;
struct V_96 * V_16 = F_112 ( V_188 ) ;
struct V_8 * V_9 = NULL ;
int V_190 ;
int * V_191 ;
if ( ! F_113 ( V_16 ) )
return;
if ( F_114 ( V_188 ) )
V_9 = F_115 ( V_16 , V_192 ) ;
if ( ! V_9 )
V_9 = & V_16 -> V_9 ;
V_190 = V_58 -> V_158 ;
if ( V_9 -> V_175 )
V_190 = V_18 ( V_190 , 32 >> ( V_193 - 10 ) ) ;
F_116 () ;
V_191 = F_117 ( & V_194 ) ;
if ( F_38 ( V_58 -> V_185 >= V_190 ) )
* V_191 = 0 ;
else if ( F_38 ( * V_191 >= V_195 ) ) {
* V_191 = 0 ;
V_190 = 0 ;
}
V_191 = F_117 ( & V_196 ) ;
if ( * V_191 > 0 && V_58 -> V_185 < V_190 ) {
unsigned long V_197 ;
V_197 = V_18 ( * V_191 , V_190 - V_58 -> V_185 ) ;
* V_191 -= V_197 ;
V_58 -> V_185 += V_197 ;
}
F_118 () ;
if ( F_38 ( V_58 -> V_185 >= V_190 ) )
F_101 ( V_168 , V_9 , V_58 -> V_185 ) ;
F_119 ( V_9 ) ;
}
bool F_120 ( struct V_8 * V_9 )
{
struct V_1 V_170 = { F_65 (wb) } ;
struct V_1 V_171 = { F_102 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_170 ;
struct V_1 * const V_5 = F_1 ( & V_171 ) ?
& V_171 : NULL ;
V_6 -> V_43 = F_18 () ;
V_6 -> V_66 = F_20 ( V_68 ) +
F_20 ( V_69 ) ;
F_21 ( V_6 ) ;
if ( V_6 -> V_66 > V_6 -> V_54 )
return true ;
if ( F_100 ( V_9 , V_165 ) >
F_64 ( V_6 -> V_9 , V_6 -> V_54 ) )
return true ;
if ( V_5 ) {
unsigned long V_101 , V_102 , V_180 ;
F_103 ( V_9 , & V_101 , & V_102 , & V_5 -> V_66 ,
& V_180 ) ;
F_61 ( V_5 , V_101 , V_102 ) ;
F_21 ( V_5 ) ;
if ( V_5 -> V_66 > V_5 -> V_54 )
return true ;
if ( F_100 ( V_9 , V_165 ) >
F_64 ( V_5 -> V_9 , V_5 -> V_54 ) )
return true ;
}
return false ;
}
void F_121 ( T_4 V_198 )
{
unsigned long V_199 ;
unsigned long V_200 ;
for ( ; ; ) {
F_25 ( & V_199 , & V_200 ) ;
V_200 = F_60 ( & V_22 , V_200 ) ;
V_200 += V_200 / 10 ;
if ( F_20 ( V_69 ) +
F_20 ( V_70 ) <= V_200 )
break;
F_122 ( V_201 , V_129 / 10 ) ;
if ( ( V_198 & ( V_202 | V_203 ) ) != ( V_202 | V_203 ) )
break;
}
}
int F_123 ( struct V_71 * V_72 , int V_73 ,
void T_1 * V_74 , T_2 * V_204 , T_3 * V_76 )
{
F_124 ( V_72 , V_73 , V_74 , V_204 , V_76 ) ;
return 0 ;
}
void F_125 ( unsigned long V_94 )
{
struct V_205 * V_206 = (struct V_205 * ) V_94 ;
int V_25 = F_20 ( V_68 ) +
F_20 ( V_69 ) ;
struct V_8 * V_9 ;
if ( ! F_126 ( & V_206 -> V_96 ) )
return;
F_127 () ;
F_128 (wb, &q->backing_dev_info.wb_list, bdi_node)
if ( F_76 ( V_9 ) )
F_129 ( V_9 , V_25 , true ,
V_207 ) ;
F_130 () ;
}
void F_131 ( struct V_96 * V_208 )
{
F_39 ( & V_208 -> V_209 , V_85 + V_187 ) ;
}
void F_132 ( void )
{
struct V_96 * V_16 ;
F_127 () ;
F_128 (bdi, &bdi_list, bdi_list)
F_133 ( & V_16 -> V_209 ) ;
F_130 () ;
}
void F_33 ( void )
{
struct V_4 * V_3 = & V_22 ;
unsigned long V_199 ;
unsigned long V_200 ;
F_25 ( & V_199 , & V_200 ) ;
V_3 -> V_61 = V_200 ;
V_195 = V_200 / ( F_134 () * 32 ) ;
if ( V_195 < 16 )
V_195 = 16 ;
}
static int
F_135 ( struct V_210 * V_211 , unsigned long V_212 ,
void * V_213 )
{
switch ( V_212 & ~ V_214 ) {
case V_215 :
case V_216 :
F_33 () ;
return V_217 ;
default:
return V_218 ;
}
}
void T_6 F_136 ( void )
{
F_137 ( F_48 ( & V_22 , V_192 ) ) ;
F_33 () ;
F_138 ( & V_219 ) ;
}
void F_139 ( struct V_167 * V_168 ,
T_7 V_220 , T_7 V_221 )
{
#define F_140 4096
unsigned long V_222 ;
do {
F_141 ( & V_168 -> V_223 ) ;
V_222 = F_142 ( & V_168 -> V_224 ,
& V_220 , V_221 , F_140 ,
V_225 , V_226 ) ;
F_143 ( & V_168 -> V_223 ) ;
F_77 ( V_222 > F_140 ) ;
F_144 () ;
} while ( V_222 >= F_140 && V_220 );
}
int F_145 ( struct V_167 * V_168 ,
struct V_227 * V_228 , T_8 V_229 ,
void * V_94 )
{
int V_77 = 0 ;
int V_230 = 0 ;
struct V_231 V_232 ;
int V_25 ;
T_7 V_233 ( V_234 ) ;
T_7 V_235 ;
T_7 V_221 ;
T_7 V_236 ;
int V_237 ;
int V_238 = 0 ;
int V_239 ;
F_146 ( & V_232 , 0 ) ;
if ( V_228 -> V_240 ) {
V_234 = V_168 -> V_234 ;
V_235 = V_234 ;
if ( V_235 == 0 )
V_237 = 1 ;
else
V_237 = 0 ;
V_221 = - 1 ;
} else {
V_235 = V_228 -> V_241 >> V_193 ;
V_221 = V_228 -> V_242 >> V_193 ;
if ( V_228 -> V_241 == 0 && V_228 -> V_242 == V_243 )
V_238 = 1 ;
V_237 = 1 ;
}
if ( V_228 -> V_244 == V_245 || V_228 -> V_246 )
V_239 = V_226 ;
else
V_239 = V_225 ;
V_247:
if ( V_228 -> V_244 == V_245 || V_228 -> V_246 )
F_139 ( V_168 , V_235 , V_221 ) ;
V_236 = V_235 ;
while ( ! V_230 && ( V_235 <= V_221 ) ) {
int V_37 ;
V_25 = F_147 ( & V_232 , V_168 , & V_235 , V_239 ,
V_18 ( V_221 - V_235 , ( T_7 ) V_248 - 1 ) + 1 ) ;
if ( V_25 == 0 )
break;
for ( V_37 = 0 ; V_37 < V_25 ; V_37 ++ ) {
struct V_249 * V_249 = V_232 . V_162 [ V_37 ] ;
if ( V_249 -> V_235 > V_221 ) {
V_230 = 1 ;
break;
}
V_236 = V_249 -> V_235 ;
F_148 ( V_249 ) ;
if ( F_38 ( V_249 -> V_168 != V_168 ) ) {
V_250:
F_149 ( V_249 ) ;
continue;
}
if ( ! F_150 ( V_249 ) ) {
goto V_250;
}
if ( F_151 ( V_249 ) ) {
if ( V_228 -> V_244 != V_251 )
F_152 ( V_249 ) ;
else
goto V_250;
}
F_137 ( F_151 ( V_249 ) ) ;
if ( ! F_153 ( V_249 ) )
goto V_250;
F_154 ( V_228 , F_112 ( V_168 -> V_189 ) ) ;
V_77 = (* V_229)( V_249 , V_228 , V_94 ) ;
if ( F_38 ( V_77 ) ) {
if ( V_77 == V_252 ) {
F_149 ( V_249 ) ;
V_77 = 0 ;
} else {
V_236 = V_249 -> V_235 + 1 ;
V_230 = 1 ;
break;
}
}
if ( -- V_228 -> V_253 <= 0 &&
V_228 -> V_244 == V_251 ) {
V_230 = 1 ;
break;
}
}
F_155 ( & V_232 ) ;
F_144 () ;
}
if ( ! V_237 && ! V_230 ) {
V_237 = 1 ;
V_235 = 0 ;
V_221 = V_234 - 1 ;
goto V_247;
}
if ( V_228 -> V_240 || ( V_238 && V_228 -> V_253 > 0 ) )
V_168 -> V_234 = V_236 ;
return V_77 ;
}
static int F_156 ( struct V_249 * V_249 , struct V_227 * V_228 ,
void * V_94 )
{
struct V_167 * V_168 = V_94 ;
int V_77 = V_168 -> V_254 -> V_229 ( V_249 , V_228 ) ;
F_157 ( V_168 , V_77 ) ;
return V_77 ;
}
int F_158 ( struct V_167 * V_168 ,
struct V_227 * V_228 )
{
struct V_255 V_256 ;
int V_77 ;
if ( ! V_168 -> V_254 -> V_229 )
return 0 ;
F_159 ( & V_256 ) ;
V_77 = F_145 ( V_168 , V_228 , F_156 , V_168 ) ;
F_160 ( & V_256 ) ;
return V_77 ;
}
int F_161 ( struct V_167 * V_168 , struct V_227 * V_228 )
{
int V_77 ;
if ( V_228 -> V_253 <= 0 )
return 0 ;
if ( V_168 -> V_254 -> V_257 )
V_77 = V_168 -> V_254 -> V_257 ( V_168 , V_228 ) ;
else
V_77 = F_158 ( V_168 , V_228 ) ;
return V_77 ;
}
int F_162 ( struct V_249 * V_249 , int V_258 )
{
struct V_167 * V_168 = V_249 -> V_168 ;
int V_77 = 0 ;
struct V_227 V_228 = {
. V_244 = V_245 ,
. V_253 = 1 ,
} ;
F_137 ( ! F_163 ( V_249 ) ) ;
if ( V_258 )
F_152 ( V_249 ) ;
if ( F_153 ( V_249 ) ) {
F_164 ( V_249 ) ;
V_77 = V_168 -> V_254 -> V_229 ( V_249 , & V_228 ) ;
if ( V_77 == 0 && V_258 ) {
F_152 ( V_249 ) ;
if ( F_165 ( V_249 ) )
V_77 = - V_259 ;
}
F_166 ( V_249 ) ;
} else {
F_149 ( V_249 ) ;
}
return V_77 ;
}
int F_167 ( struct V_249 * V_249 )
{
if ( ! F_150 ( V_249 ) )
return ! F_168 ( V_249 ) ;
return 0 ;
}
void F_169 ( struct V_249 * V_249 , struct V_167 * V_168 )
{
struct V_188 * V_188 = V_168 -> V_189 ;
F_170 ( V_249 , V_168 ) ;
if ( F_171 ( V_168 ) ) {
struct V_8 * V_9 ;
F_172 ( V_188 , V_249 ) ;
V_9 = F_173 ( V_188 ) ;
F_174 ( V_249 , V_260 ) ;
F_175 ( V_249 , V_68 ) ;
F_176 ( V_249 , V_261 ) ;
F_175 ( V_249 , V_262 ) ;
F_41 ( V_9 , V_165 ) ;
F_41 ( V_9 , V_154 ) ;
F_177 ( V_50 ) ;
V_58 -> V_185 ++ ;
F_178 ( V_194 ) ;
}
}
void F_179 ( struct V_249 * V_249 , struct V_167 * V_168 ,
struct V_8 * V_9 )
{
if ( F_171 ( V_168 ) ) {
F_180 ( V_249 , V_260 ) ;
F_181 ( V_249 , V_68 ) ;
F_182 ( V_249 , V_261 ) ;
F_183 ( V_9 , V_165 ) ;
F_184 ( V_50 ) ;
}
}
int F_185 ( struct V_249 * V_249 )
{
F_186 ( V_249 ) ;
if ( ! F_168 ( V_249 ) ) {
struct V_167 * V_168 = F_187 ( V_249 ) ;
unsigned long V_59 ;
if ( ! V_168 ) {
F_188 ( V_249 ) ;
return 1 ;
}
F_189 ( & V_168 -> V_223 , V_59 ) ;
F_137 ( F_187 ( V_249 ) != V_168 ) ;
F_77 ( ! F_190 ( V_249 ) && ! F_191 ( V_249 ) ) ;
F_169 ( V_249 , V_168 ) ;
F_192 ( & V_168 -> V_224 , F_193 ( V_249 ) ,
V_225 ) ;
F_194 ( & V_168 -> V_223 , V_59 ) ;
F_188 ( V_249 ) ;
if ( V_168 -> V_189 ) {
F_195 ( V_168 -> V_189 , V_263 ) ;
}
return 1 ;
}
F_188 ( V_249 ) ;
return 0 ;
}
void F_196 ( struct V_249 * V_249 )
{
struct V_167 * V_168 = V_249 -> V_168 ;
if ( V_168 && F_171 ( V_168 ) ) {
struct V_188 * V_188 = V_168 -> V_189 ;
struct V_8 * V_9 ;
bool V_264 ;
V_9 = F_197 ( V_188 , & V_264 ) ;
V_58 -> V_185 -- ;
F_181 ( V_249 , V_262 ) ;
F_183 ( V_9 , V_154 ) ;
F_198 ( V_188 , V_264 ) ;
}
}
int F_199 ( struct V_227 * V_228 , struct V_249 * V_249 )
{
int V_77 ;
V_228 -> V_265 ++ ;
V_77 = F_185 ( V_249 ) ;
F_196 ( V_249 ) ;
return V_77 ;
}
int F_200 ( struct V_249 * V_249 )
{
struct V_167 * V_168 = F_187 ( V_249 ) ;
V_249 = F_201 ( V_249 ) ;
if ( F_202 ( V_168 ) ) {
int (* F_203)( struct V_249 * ) = V_168 -> V_254 -> F_200 ;
if ( F_204 ( V_249 ) )
F_205 ( V_249 ) ;
#ifdef F_206
if ( ! F_203 )
F_203 = V_266 ;
#endif
return (* F_203)( V_249 ) ;
}
if ( ! F_150 ( V_249 ) ) {
if ( ! F_168 ( V_249 ) )
return 1 ;
}
return 0 ;
}
int F_207 ( struct V_249 * V_249 )
{
int V_77 ;
F_148 ( V_249 ) ;
V_77 = F_200 ( V_249 ) ;
F_149 ( V_249 ) ;
return V_77 ;
}
void F_208 ( struct V_249 * V_249 )
{
struct V_167 * V_168 = F_187 ( V_249 ) ;
if ( F_171 ( V_168 ) ) {
struct V_188 * V_188 = V_168 -> V_189 ;
struct V_8 * V_9 ;
bool V_264 ;
F_186 ( V_249 ) ;
V_9 = F_197 ( V_188 , & V_264 ) ;
if ( F_209 ( V_249 ) )
F_179 ( V_249 , V_168 , V_9 ) ;
F_198 ( V_188 , V_264 ) ;
F_188 ( V_249 ) ;
} else {
F_210 ( V_249 ) ;
}
}
int F_153 ( struct V_249 * V_249 )
{
struct V_167 * V_168 = F_187 ( V_249 ) ;
int V_77 = 0 ;
F_137 ( ! F_163 ( V_249 ) ) ;
if ( V_168 && F_171 ( V_168 ) ) {
struct V_188 * V_188 = V_168 -> V_189 ;
struct V_8 * V_9 ;
bool V_264 ;
if ( F_211 ( V_249 ) )
F_200 ( V_249 ) ;
V_9 = F_197 ( V_188 , & V_264 ) ;
if ( F_209 ( V_249 ) ) {
F_180 ( V_249 , V_260 ) ;
F_181 ( V_249 , V_68 ) ;
F_182 ( V_249 , V_261 ) ;
F_183 ( V_9 , V_165 ) ;
V_77 = 1 ;
}
F_198 ( V_188 , V_264 ) ;
return V_77 ;
}
return F_209 ( V_249 ) ;
}
int F_212 ( struct V_249 * V_249 )
{
struct V_167 * V_168 = F_187 ( V_249 ) ;
int V_77 ;
F_186 ( V_249 ) ;
if ( V_168 ) {
struct V_188 * V_188 = V_168 -> V_189 ;
struct V_96 * V_16 = F_112 ( V_188 ) ;
unsigned long V_59 ;
F_189 ( & V_168 -> V_223 , V_59 ) ;
V_77 = F_213 ( V_249 ) ;
if ( V_77 ) {
F_214 ( & V_168 -> V_224 ,
F_193 ( V_249 ) ,
V_267 ) ;
if ( F_215 ( V_16 ) ) {
struct V_8 * V_9 = F_173 ( V_188 ) ;
F_216 ( V_9 , V_166 ) ;
F_40 ( V_9 ) ;
}
}
if ( V_168 -> V_189 && ! F_217 ( V_168 ,
V_267 ) )
F_218 ( V_168 -> V_189 ) ;
F_194 ( & V_168 -> V_223 , V_59 ) ;
} else {
V_77 = F_213 ( V_249 ) ;
}
if ( V_77 ) {
F_180 ( V_249 , V_268 ) ;
F_181 ( V_249 , V_70 ) ;
F_182 ( V_249 , V_261 ) ;
F_219 ( V_249 , V_269 ) ;
}
F_188 ( V_249 ) ;
return V_77 ;
}
int F_220 ( struct V_249 * V_249 , bool V_270 )
{
struct V_167 * V_168 = F_187 ( V_249 ) ;
int V_77 ;
F_186 ( V_249 ) ;
if ( V_168 ) {
struct V_188 * V_188 = V_168 -> V_189 ;
struct V_96 * V_16 = F_112 ( V_188 ) ;
unsigned long V_59 ;
F_189 ( & V_168 -> V_223 , V_59 ) ;
V_77 = F_221 ( V_249 ) ;
if ( ! V_77 ) {
bool V_271 ;
V_271 = F_217 ( V_168 ,
V_267 ) ;
F_192 ( & V_168 -> V_224 ,
F_193 ( V_249 ) ,
V_267 ) ;
if ( F_215 ( V_16 ) )
F_41 ( F_173 ( V_188 ) , V_166 ) ;
if ( V_168 -> V_189 && ! V_271 )
F_222 ( V_168 -> V_189 ) ;
}
if ( ! F_150 ( V_249 ) )
F_214 ( & V_168 -> V_224 ,
F_193 ( V_249 ) ,
V_225 ) ;
if ( ! V_270 )
F_214 ( & V_168 -> V_224 ,
F_193 ( V_249 ) ,
V_226 ) ;
F_194 ( & V_168 -> V_223 , V_59 ) ;
} else {
V_77 = F_221 ( V_249 ) ;
}
if ( ! V_77 ) {
F_174 ( V_249 , V_268 ) ;
F_219 ( V_249 , V_70 ) ;
F_223 ( V_249 , V_261 ) ;
}
F_188 ( V_249 ) ;
return V_77 ;
}
int F_217 ( struct V_167 * V_168 , int V_239 )
{
return F_224 ( & V_168 -> V_224 , V_239 ) ;
}
void F_225 ( struct V_249 * V_249 )
{
if ( F_226 ( F_112 ( V_249 -> V_168 -> V_189 ) ) )
F_152 ( V_249 ) ;
}
