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
static void F_56 ( struct V_1 * V_5 ,
unsigned long V_95 , unsigned long V_96 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_97 = V_95 - V_18 ( V_95 , V_5 -> V_59 ) ;
unsigned long V_98 = V_6 -> V_37 - V_18 ( V_6 -> V_37 , V_6 -> V_59 ) ;
unsigned long V_99 = V_98 - V_18 ( V_98 , V_97 ) ;
V_5 -> V_37 = V_95 + V_18 ( V_96 , V_99 ) ;
}
static unsigned long F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_46 = V_2 -> V_46 ;
T_5 V_100 ;
long V_101 , V_102 ;
unsigned long V_103 , V_104 ;
F_58 ( & V_3 -> V_75 , V_2 -> V_105 ,
& V_101 , & V_102 ) ;
V_100 = ( V_46 * ( 100 - V_92 ) ) / 100 ;
V_100 *= V_101 ;
F_7 ( V_100 , V_102 ) ;
F_5 ( V_2 -> V_9 , & V_103 , & V_104 ) ;
V_100 += ( V_46 * V_103 ) / 100 ;
if ( V_100 > ( V_46 * V_104 ) / 100 )
V_100 = V_46 * V_104 / 100 ;
return V_100 ;
}
unsigned long F_59 ( struct V_8 * V_9 , unsigned long V_46 )
{
struct V_1 V_6 = { F_60 ( V_9 ) ,
. V_46 = V_46 } ;
return F_57 ( & V_6 ) ;
}
static long long F_61 ( unsigned long V_106 ,
unsigned long V_59 ,
unsigned long V_60 )
{
long long V_107 ;
long V_31 ;
V_31 = F_62 ( ( ( V_108 ) V_106 - ( V_108 ) V_59 ) << V_109 ,
( V_60 - V_106 ) | 1 ) ;
V_107 = V_31 ;
V_107 = V_107 * V_31 >> V_109 ;
V_107 = V_107 * V_31 >> V_109 ;
V_107 += 1 << V_109 ;
return F_63 ( V_107 , 0LL , 2LL << V_109 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_110 = V_9 -> V_14 ;
unsigned long V_111 = F_54 ( V_2 -> V_46 , V_2 -> V_47 ) ;
unsigned long V_60 = F_55 ( F_2 ( V_2 ) , V_2 -> V_46 ) ;
unsigned long V_100 = V_2 -> V_100 ;
unsigned long V_112 ;
unsigned long V_106 ;
unsigned long V_113 ;
unsigned long V_114 ;
long long V_107 ;
long V_31 ;
V_2 -> V_107 = 0 ;
if ( F_33 ( V_2 -> V_59 >= V_60 ) )
return;
V_106 = ( V_111 + V_60 ) / 2 ;
V_107 = F_61 ( V_106 , V_2 -> V_59 , V_60 ) ;
if ( F_33 ( V_9 -> V_16 -> V_115 & V_116 ) ) {
long long V_117 ;
if ( V_2 -> V_118 < 8 ) {
V_2 -> V_107 = F_65 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
return;
}
if ( V_2 -> V_118 >= V_100 )
return;
V_113 = F_54 ( V_100 ,
V_2 -> V_119 ) ;
if ( V_113 == 0 || V_113 == V_100 )
return;
V_117 = F_61 ( V_113 , V_2 -> V_118 ,
V_100 ) ;
V_2 -> V_107 = V_18 ( V_107 , V_117 ) ;
return;
}
if ( F_33 ( V_100 > V_2 -> V_46 ) )
V_100 = V_2 -> V_46 ;
V_100 = V_20 ( V_100 , ( V_60 - V_2 -> V_59 ) / 8 ) ;
V_31 = F_66 ( ( T_5 ) V_100 << 16 , V_2 -> V_46 | 1 ) ;
V_113 = V_106 * ( T_5 ) V_31 >> 16 ;
V_114 = ( V_2 -> V_46 - V_100 + 8 * V_110 ) * ( T_5 ) V_31 >> 16 ;
V_112 = V_113 + V_114 ;
if ( V_2 -> V_118 < V_112 - V_114 / 4 ) {
V_107 = F_67 ( V_107 * ( V_112 - V_2 -> V_118 ) ,
( V_112 - V_113 ) | 1 ) ;
} else
V_107 /= 4 ;
V_112 = V_100 / 2 ;
if ( V_2 -> V_118 < V_112 ) {
if ( V_2 -> V_118 > V_112 / 8 )
V_107 = F_66 ( V_107 * V_112 ,
V_2 -> V_118 ) ;
else
V_107 *= 8 ;
}
V_2 -> V_107 = V_107 ;
}
static void F_68 ( struct V_8 * V_9 ,
unsigned long V_120 ,
unsigned long V_121 )
{
const unsigned long V_122 = F_69 ( 3 * V_123 ) ;
unsigned long V_124 = V_9 -> V_14 ;
unsigned long V_125 = V_9 -> V_126 ;
T_5 V_127 ;
V_127 = V_121 - V_18 ( V_121 , V_9 -> V_128 ) ;
V_127 *= V_123 ;
if ( F_33 ( V_120 > V_122 ) ) {
F_7 ( V_127 , V_120 ) ;
V_124 = V_127 ;
goto V_129;
}
V_127 += ( T_5 ) V_9 -> V_126 * ( V_122 - V_120 ) ;
V_127 >>= F_70 ( V_122 ) ;
if ( V_124 > V_125 && V_125 >= ( unsigned long ) V_127 )
V_124 -= ( V_124 - V_125 ) >> 3 ;
if ( V_124 < V_125 && V_125 <= ( unsigned long ) V_127 )
V_124 += ( V_125 - V_124 ) >> 3 ;
V_129:
V_124 = V_20 ( V_124 , 1LU ) ;
if ( F_71 ( V_9 ) ) {
long V_130 = V_124 - V_9 -> V_14 ;
F_72 ( F_73 ( V_130 ,
& V_9 -> V_16 -> V_17 ) <= 0 ) ;
}
V_9 -> V_126 = V_127 ;
V_9 -> V_14 = V_124 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
unsigned long V_46 = V_2 -> V_46 ;
unsigned long V_60 = V_3 -> V_94 ;
if ( V_60 < V_46 ) {
V_60 = V_46 ;
goto V_131;
}
V_46 = V_20 ( V_46 , V_2 -> V_59 ) ;
if ( V_60 > V_46 ) {
V_60 -= ( V_60 - V_46 ) >> 5 ;
goto V_131;
}
return;
V_131:
V_3 -> V_94 = V_60 ;
}
static void F_75 ( struct V_1 * V_2 ,
unsigned long V_132 )
{
struct V_4 * V_3 = F_2 ( V_2 ) ;
if ( F_76 ( V_132 , V_3 -> V_88 + V_133 ) )
return;
F_77 ( & V_3 -> V_85 ) ;
if ( F_78 ( V_132 , V_3 -> V_88 + V_133 ) ) {
F_74 ( V_2 ) ;
V_3 -> V_88 = V_132 ;
}
F_79 ( & V_3 -> V_85 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
unsigned long V_134 ,
unsigned long V_120 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_59 = V_2 -> V_59 ;
unsigned long V_111 = F_54 ( V_2 -> V_46 , V_2 -> V_47 ) ;
unsigned long V_60 = F_55 ( F_2 ( V_2 ) , V_2 -> V_46 ) ;
unsigned long V_106 = ( V_111 + V_60 ) / 2 ;
unsigned long V_110 = V_9 -> V_14 ;
unsigned long V_135 = V_9 -> V_135 ;
unsigned long V_136 ;
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 ;
unsigned long V_31 ;
unsigned long V_140 ;
V_136 = ( V_134 - V_9 -> V_141 ) * V_123 / V_120 ;
V_137 = ( T_5 ) V_135 *
V_2 -> V_107 >> V_109 ;
V_137 ++ ;
V_138 = F_66 ( ( T_5 ) V_137 * V_110 ,
V_136 | 1 ) ;
if ( F_33 ( V_138 > V_110 ) )
V_138 = V_110 ;
V_139 = 0 ;
if ( F_33 ( V_9 -> V_16 -> V_115 & V_116 ) ) {
V_59 = V_2 -> V_118 ;
if ( V_2 -> V_118 < 8 )
V_106 = V_2 -> V_118 + 1 ;
else
V_106 = ( V_2 -> V_100 + V_2 -> V_119 ) / 2 ;
}
if ( V_59 < V_106 ) {
V_31 = F_81 ( V_9 -> V_138 ,
V_138 , V_137 ) ;
if ( V_135 < V_31 )
V_139 = V_31 - V_135 ;
} else {
V_31 = F_82 ( V_9 -> V_138 ,
V_138 , V_137 ) ;
if ( V_135 > V_31 )
V_139 = V_135 - V_31 ;
}
V_140 = V_135 / ( 2 * V_139 + 1 ) ;
if ( V_140 < V_142 )
V_139 = F_17 ( V_139 >> V_140 , 8 ) ;
else
V_139 = 0 ;
if ( V_135 < V_138 )
V_135 += V_139 ;
else
V_135 -= V_139 ;
V_9 -> V_135 = V_20 ( V_135 , 1UL ) ;
V_9 -> V_138 = V_138 ;
F_83 ( V_9 , V_136 , V_137 ) ;
}
static void F_84 ( struct V_1 * V_6 ,
struct V_1 * V_5 ,
unsigned long V_143 ,
bool V_144 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned long V_132 = V_78 ;
unsigned long V_120 = V_132 - V_9 -> V_145 ;
unsigned long V_134 ;
unsigned long V_121 ;
F_85 ( & V_9 -> V_146 ) ;
if ( V_120 < V_133 )
return;
V_134 = F_86 ( & V_9 -> V_147 [ V_148 ] ) ;
V_121 = F_86 ( & V_9 -> V_147 [ V_81 ] ) ;
if ( V_120 > V_123 && F_76 ( V_9 -> V_145 , V_143 ) )
goto V_149;
if ( V_144 ) {
F_75 ( V_6 , V_132 ) ;
F_80 ( V_6 , V_134 , V_120 ) ;
if ( F_87 ( V_150 ) && V_5 ) {
F_75 ( V_5 , V_132 ) ;
F_80 ( V_5 , V_134 , V_120 ) ;
}
}
F_68 ( V_9 , V_120 , V_121 ) ;
V_149:
V_9 -> V_141 = V_134 ;
V_9 -> V_128 = V_121 ;
V_9 -> V_145 = V_132 ;
}
void F_88 ( struct V_8 * V_9 , unsigned long V_143 )
{
struct V_1 V_6 = { F_60 (wb) } ;
F_84 ( & V_6 , NULL , V_143 , false ) ;
}
static unsigned long F_89 ( unsigned long V_59 ,
unsigned long V_46 )
{
if ( V_46 > V_59 )
return 1UL << ( F_70 ( V_46 - V_59 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_90 ( struct V_8 * V_9 ,
unsigned long V_118 )
{
unsigned long V_127 = V_9 -> V_14 ;
unsigned long V_82 ;
V_82 = V_118 / ( 1 + V_127 / F_69 ( 1 + V_123 / 8 ) ) ;
V_82 ++ ;
return F_65 (unsigned long, t, MAX_PAUSE) ;
}
static long F_91 ( struct V_8 * V_9 ,
long V_151 ,
unsigned long V_137 ,
unsigned long V_135 ,
int * V_152 )
{
long V_153 = F_70 ( V_9 -> V_14 ) ;
long V_154 = F_70 ( V_9 -> V_135 ) ;
long V_82 ;
long V_155 ;
int V_156 ;
V_82 = V_20 ( 1 , V_123 / 100 ) ;
if ( V_153 > V_154 )
V_82 += ( V_153 - V_154 ) * ( 10 * V_123 ) / 1024 ;
V_82 = V_18 ( V_82 , 1 + V_151 / 2 ) ;
V_156 = V_135 * V_82 / F_69 ( V_123 ) ;
if ( V_156 < V_157 ) {
V_82 = V_151 ;
V_156 = V_135 * V_82 / F_69 ( V_123 ) ;
if ( V_156 > V_157 ) {
V_156 = V_157 ;
V_82 = V_123 * V_157 / V_135 ;
}
}
V_155 = V_123 * V_156 / ( V_137 + 1 ) ;
if ( V_155 > V_151 ) {
V_82 = V_151 ;
V_156 = V_137 * V_82 / F_69 ( V_123 ) ;
}
* V_152 = V_156 ;
return V_156 >= V_157 ? 1 + V_82 / 2 : V_82 ;
}
static inline void F_92 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_158 ;
V_2 -> V_100 = F_57 ( V_2 ) ;
V_2 -> V_119 = V_2 -> V_46 ?
F_66 ( ( T_5 ) V_2 -> V_100 * V_2 -> V_47 , V_2 -> V_46 ) : 0 ;
if ( V_2 -> V_100 < 2 * F_93 ( V_9 ) ) {
V_158 = F_94 ( V_9 , V_159 ) ;
V_2 -> V_118 = V_158 + F_94 ( V_9 , V_160 ) ;
} else {
V_158 = F_95 ( V_9 , V_159 ) ;
V_2 -> V_118 = V_158 + F_95 ( V_9 , V_160 ) ;
}
}
static void F_96 ( struct V_161 * V_162 ,
struct V_8 * V_9 ,
unsigned long V_163 )
{
struct V_1 V_164 = { F_60 (wb) } ;
struct V_1 V_165 = { F_97 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_164 ;
struct V_1 * const V_5 = F_1 ( & V_165 ) ?
& V_165 : NULL ;
struct V_1 * V_166 ;
unsigned long V_167 ;
long V_122 ;
long V_155 ;
long V_151 ;
long V_168 ;
int V_152 ;
bool V_169 = false ;
unsigned long V_137 ;
unsigned long V_135 ;
struct V_89 * V_16 = V_9 -> V_16 ;
bool V_170 = V_16 -> V_115 & V_116 ;
unsigned long V_143 = V_78 ;
for (; ; ) {
unsigned long V_132 = V_78 ;
unsigned long V_59 , V_46 , V_47 ;
unsigned long V_171 = 0 ;
unsigned long V_172 = 0 ;
unsigned long V_173 = 0 ;
V_167 = F_15 ( V_61 ) +
F_15 ( V_62 ) ;
V_6 -> V_37 = F_14 () ;
V_6 -> V_59 = V_167 + F_15 ( V_63 ) ;
F_16 ( V_6 ) ;
if ( F_33 ( V_170 ) ) {
F_92 ( V_6 ) ;
V_59 = V_6 -> V_118 ;
V_46 = V_6 -> V_100 ;
V_47 = V_6 -> V_119 ;
} else {
V_59 = V_6 -> V_59 ;
V_46 = V_6 -> V_46 ;
V_47 = V_6 -> V_47 ;
}
if ( V_5 ) {
unsigned long V_95 , V_96 , V_174 ;
F_98 ( V_9 , & V_95 , & V_96 ,
& V_5 -> V_59 , & V_174 ) ;
V_5 -> V_59 += V_174 ;
F_56 ( V_5 , V_95 , V_96 ) ;
F_16 ( V_5 ) ;
if ( F_33 ( V_170 ) ) {
F_92 ( V_5 ) ;
V_171 = V_5 -> V_118 ;
V_172 = V_5 -> V_100 ;
V_173 = V_5 -> V_119 ;
} else {
V_171 = V_5 -> V_59 ;
V_172 = V_5 -> V_46 ;
V_173 = V_5 -> V_47 ;
}
}
if ( V_59 <= F_54 ( V_46 , V_47 ) &&
( ! V_5 ||
V_171 <= F_54 ( V_172 , V_173 ) ) ) {
unsigned long V_175 = F_89 ( V_59 , V_46 ) ;
unsigned long V_176 = V_177 ;
V_52 -> V_178 = V_132 ;
V_52 -> V_179 = 0 ;
if ( V_5 )
V_176 = F_89 ( V_171 , V_172 ) ;
V_52 -> V_152 = V_18 ( V_175 , V_176 ) ;
break;
}
if ( F_33 ( ! F_99 ( V_9 ) ) )
F_100 ( V_9 ) ;
if ( ! V_170 )
F_92 ( V_6 ) ;
V_169 = ( V_6 -> V_118 > V_6 -> V_100 ) &&
( ( V_6 -> V_59 > V_6 -> V_46 ) || V_170 ) ;
F_64 ( V_6 ) ;
V_166 = V_6 ;
if ( V_5 ) {
if ( ! V_170 )
F_92 ( V_5 ) ;
V_169 |= ( V_5 -> V_118 > V_5 -> V_100 ) &&
( ( V_5 -> V_59 > V_5 -> V_46 ) || V_170 ) ;
F_64 ( V_5 ) ;
if ( V_5 -> V_107 < V_6 -> V_107 )
V_166 = V_5 ;
}
if ( V_169 && ! V_9 -> V_169 )
V_9 -> V_169 = 1 ;
if ( F_101 ( V_9 -> V_145 +
V_133 ) ) {
F_77 ( & V_9 -> V_146 ) ;
F_84 ( V_6 , V_5 , V_143 , true ) ;
F_79 ( & V_9 -> V_146 ) ;
}
V_135 = V_9 -> V_135 ;
V_137 = ( ( T_5 ) V_135 * V_166 -> V_107 ) >>
V_109 ;
V_151 = F_90 ( V_9 , V_166 -> V_118 ) ;
V_168 = F_91 ( V_9 , V_151 ,
V_137 , V_135 ,
& V_152 ) ;
if ( F_33 ( V_137 == 0 ) ) {
V_122 = V_151 ;
V_155 = V_151 ;
goto V_155;
}
V_122 = V_123 * V_163 / V_137 ;
V_155 = V_122 ;
if ( V_52 -> V_178 )
V_155 -= V_132 - V_52 -> V_178 ;
if ( V_155 < V_168 ) {
F_102 ( V_9 ,
V_166 -> V_46 ,
V_166 -> V_47 ,
V_166 -> V_59 ,
V_166 -> V_100 ,
V_166 -> V_118 ,
V_135 ,
V_137 ,
V_163 ,
V_122 ,
V_18 ( V_155 , 0L ) ,
V_143 ) ;
if ( V_155 < - V_123 ) {
V_52 -> V_178 = V_132 ;
V_52 -> V_179 = 0 ;
} else if ( V_122 ) {
V_52 -> V_178 += V_122 ;
V_52 -> V_179 = 0 ;
} else if ( V_52 -> V_152 <= V_163 )
V_52 -> V_152 += V_163 ;
break;
}
if ( F_33 ( V_155 > V_151 ) ) {
V_132 += V_18 ( V_155 - V_151 , V_151 ) ;
V_155 = V_151 ;
}
V_155:
F_102 ( V_9 ,
V_166 -> V_46 ,
V_166 -> V_47 ,
V_166 -> V_59 ,
V_166 -> V_100 ,
V_166 -> V_118 ,
V_135 ,
V_137 ,
V_163 ,
V_122 ,
V_155 ,
V_143 ) ;
F_103 ( V_180 ) ;
F_104 ( V_155 ) ;
V_52 -> V_178 = V_132 + V_155 ;
V_52 -> V_179 = 0 ;
V_52 -> V_152 = V_152 ;
if ( V_137 )
break;
if ( V_166 -> V_118 <= F_93 ( V_9 ) )
break;
if ( F_105 ( V_52 ) )
break;
}
if ( ! V_169 && V_9 -> V_169 )
V_9 -> V_169 = 0 ;
if ( F_99 ( V_9 ) )
return;
if ( V_181 )
return;
if ( V_167 > V_6 -> V_47 )
F_100 ( V_9 ) ;
}
void F_106 ( struct V_161 * V_162 )
{
struct V_182 * V_182 = V_162 -> V_183 ;
struct V_89 * V_16 = F_107 ( V_182 ) ;
struct V_8 * V_9 = NULL ;
int V_184 ;
int * V_185 ;
if ( ! F_108 ( V_16 ) )
return;
if ( F_109 ( V_182 ) )
V_9 = F_110 ( V_16 , V_186 ) ;
if ( ! V_9 )
V_9 = & V_16 -> V_9 ;
V_184 = V_52 -> V_152 ;
if ( V_9 -> V_169 )
V_184 = V_18 ( V_184 , 32 >> ( V_187 - 10 ) ) ;
F_111 () ;
V_185 = F_112 ( & V_188 ) ;
if ( F_33 ( V_52 -> V_179 >= V_184 ) )
* V_185 = 0 ;
else if ( F_33 ( * V_185 >= V_189 ) ) {
* V_185 = 0 ;
V_184 = 0 ;
}
V_185 = F_112 ( & V_190 ) ;
if ( * V_185 > 0 && V_52 -> V_179 < V_184 ) {
unsigned long V_191 ;
V_191 = V_18 ( * V_185 , V_184 - V_52 -> V_179 ) ;
* V_185 -= V_191 ;
V_52 -> V_179 += V_191 ;
}
F_113 () ;
if ( F_33 ( V_52 -> V_179 >= V_184 ) )
F_96 ( V_162 , V_9 , V_52 -> V_179 ) ;
F_114 ( V_9 ) ;
}
bool F_115 ( struct V_8 * V_9 )
{
struct V_1 V_164 = { F_60 (wb) } ;
struct V_1 V_165 = { F_97 (wb, &gdtc_stor) } ;
struct V_1 * const V_6 = & V_164 ;
struct V_1 * const V_5 = F_1 ( & V_165 ) ?
& V_165 : NULL ;
V_6 -> V_37 = F_14 () ;
V_6 -> V_59 = F_15 ( V_61 ) +
F_15 ( V_62 ) ;
F_16 ( V_6 ) ;
if ( V_6 -> V_59 > V_6 -> V_47 )
return true ;
if ( F_95 ( V_9 , V_159 ) >
F_59 ( V_6 -> V_9 , V_6 -> V_47 ) )
return true ;
if ( V_5 ) {
unsigned long V_95 , V_96 , V_174 ;
F_98 ( V_9 , & V_95 , & V_96 , & V_5 -> V_59 ,
& V_174 ) ;
F_56 ( V_5 , V_95 , V_96 ) ;
F_16 ( V_5 ) ;
if ( V_5 -> V_59 > V_5 -> V_47 )
return true ;
if ( F_95 ( V_9 , V_159 ) >
F_59 ( V_5 -> V_9 , V_5 -> V_47 ) )
return true ;
}
return false ;
}
void F_116 ( T_4 V_192 )
{
unsigned long V_193 ;
unsigned long V_194 ;
for ( ; ; ) {
F_20 ( & V_193 , & V_194 ) ;
V_194 = F_55 ( & V_22 , V_194 ) ;
V_194 += V_194 / 10 ;
if ( F_15 ( V_62 ) +
F_15 ( V_63 ) <= V_194 )
break;
F_117 ( V_195 , V_123 / 10 ) ;
if ( ( V_192 & ( V_196 | V_197 ) ) != ( V_196 | V_197 ) )
break;
}
}
int F_118 ( struct V_64 * V_65 , int V_66 ,
void T_1 * V_67 , T_2 * V_198 , T_3 * V_69 )
{
F_119 ( V_65 , V_66 , V_67 , V_198 , V_69 ) ;
return 0 ;
}
void F_120 ( unsigned long V_87 )
{
struct V_199 * V_200 = (struct V_199 * ) V_87 ;
int V_24 = F_15 ( V_61 ) +
F_15 ( V_62 ) ;
struct V_8 * V_9 ;
if ( ! F_121 ( & V_200 -> V_89 ) )
return;
F_122 () ;
F_123 (wb, &q->backing_dev_info.wb_list, bdi_node)
if ( F_71 ( V_9 ) )
F_124 ( V_9 , V_24 , true ,
V_201 ) ;
F_125 () ;
}
void F_126 ( struct V_89 * V_202 )
{
F_34 ( & V_202 -> V_203 , V_78 + V_181 ) ;
}
void F_127 ( void )
{
struct V_89 * V_16 ;
F_122 () ;
F_123 (bdi, &bdi_list, bdi_list)
F_128 ( & V_16 -> V_203 ) ;
F_125 () ;
}
void F_28 ( void )
{
struct V_4 * V_3 = & V_22 ;
unsigned long V_193 ;
unsigned long V_194 ;
F_20 ( & V_193 , & V_194 ) ;
V_3 -> V_94 = V_194 ;
V_189 = V_194 / ( F_129 () * 32 ) ;
if ( V_189 < 16 )
V_189 = 16 ;
}
static int
F_130 ( struct V_204 * V_205 , unsigned long V_206 ,
void * V_207 )
{
switch ( V_206 & ~ V_208 ) {
case V_209 :
case V_210 :
F_28 () ;
return V_211 ;
default:
return V_212 ;
}
}
void T_6 F_131 ( void )
{
F_132 ( F_43 ( & V_22 , V_186 ) ) ;
F_28 () ;
F_133 ( & V_213 ) ;
}
void F_134 ( struct V_161 * V_162 ,
T_7 V_214 , T_7 V_215 )
{
#define F_135 4096
unsigned long V_216 ;
do {
F_136 ( & V_162 -> V_217 ) ;
V_216 = F_137 ( & V_162 -> V_218 ,
& V_214 , V_215 , F_135 ,
V_219 , V_220 ) ;
F_138 ( & V_162 -> V_217 ) ;
F_72 ( V_216 > F_135 ) ;
F_139 () ;
} while ( V_216 >= F_135 && V_214 );
}
int F_140 ( struct V_161 * V_162 ,
struct V_221 * V_222 , T_8 V_223 ,
void * V_87 )
{
int V_70 = 0 ;
int V_224 = 0 ;
struct V_225 V_226 ;
int V_24 ;
T_7 V_227 ( V_228 ) ;
T_7 V_229 ;
T_7 V_215 ;
T_7 V_230 ;
int V_231 ;
int V_232 = 0 ;
int V_233 ;
F_141 ( & V_226 , 0 ) ;
if ( V_222 -> V_234 ) {
V_228 = V_162 -> V_228 ;
V_229 = V_228 ;
if ( V_229 == 0 )
V_231 = 1 ;
else
V_231 = 0 ;
V_215 = - 1 ;
} else {
V_229 = V_222 -> V_235 >> V_187 ;
V_215 = V_222 -> V_236 >> V_187 ;
if ( V_222 -> V_235 == 0 && V_222 -> V_236 == V_237 )
V_232 = 1 ;
V_231 = 1 ;
}
if ( V_222 -> V_238 == V_239 || V_222 -> V_240 )
V_233 = V_220 ;
else
V_233 = V_219 ;
V_241:
if ( V_222 -> V_238 == V_239 || V_222 -> V_240 )
F_134 ( V_162 , V_229 , V_215 ) ;
V_230 = V_229 ;
while ( ! V_224 && ( V_229 <= V_215 ) ) {
int V_242 ;
V_24 = F_142 ( & V_226 , V_162 , & V_229 , V_233 ,
V_18 ( V_215 - V_229 , ( T_7 ) V_243 - 1 ) + 1 ) ;
if ( V_24 == 0 )
break;
for ( V_242 = 0 ; V_242 < V_24 ; V_242 ++ ) {
struct V_244 * V_244 = V_226 . V_156 [ V_242 ] ;
if ( V_244 -> V_229 > V_215 ) {
V_224 = 1 ;
break;
}
V_230 = V_244 -> V_229 ;
F_143 ( V_244 ) ;
if ( F_33 ( V_244 -> V_162 != V_162 ) ) {
V_245:
F_144 ( V_244 ) ;
continue;
}
if ( ! F_145 ( V_244 ) ) {
goto V_245;
}
if ( F_146 ( V_244 ) ) {
if ( V_222 -> V_238 != V_246 )
F_147 ( V_244 ) ;
else
goto V_245;
}
F_132 ( F_146 ( V_244 ) ) ;
if ( ! F_148 ( V_244 ) )
goto V_245;
F_149 ( V_222 , F_107 ( V_162 -> V_183 ) ) ;
V_70 = (* V_223)( V_244 , V_222 , V_87 ) ;
if ( F_33 ( V_70 ) ) {
if ( V_70 == V_247 ) {
F_144 ( V_244 ) ;
V_70 = 0 ;
} else {
V_230 = V_244 -> V_229 + 1 ;
V_224 = 1 ;
break;
}
}
if ( -- V_222 -> V_248 <= 0 &&
V_222 -> V_238 == V_246 ) {
V_224 = 1 ;
break;
}
}
F_150 ( & V_226 ) ;
F_139 () ;
}
if ( ! V_231 && ! V_224 ) {
V_231 = 1 ;
V_229 = 0 ;
V_215 = V_228 - 1 ;
goto V_241;
}
if ( V_222 -> V_234 || ( V_232 && V_222 -> V_248 > 0 ) )
V_162 -> V_228 = V_230 ;
return V_70 ;
}
static int F_151 ( struct V_244 * V_244 , struct V_221 * V_222 ,
void * V_87 )
{
struct V_161 * V_162 = V_87 ;
int V_70 = V_162 -> V_249 -> V_223 ( V_244 , V_222 ) ;
F_152 ( V_162 , V_70 ) ;
return V_70 ;
}
int F_153 ( struct V_161 * V_162 ,
struct V_221 * V_222 )
{
struct V_250 V_251 ;
int V_70 ;
if ( ! V_162 -> V_249 -> V_223 )
return 0 ;
F_154 ( & V_251 ) ;
V_70 = F_140 ( V_162 , V_222 , F_151 , V_162 ) ;
F_155 ( & V_251 ) ;
return V_70 ;
}
int F_156 ( struct V_161 * V_162 , struct V_221 * V_222 )
{
int V_70 ;
if ( V_222 -> V_248 <= 0 )
return 0 ;
if ( V_162 -> V_249 -> V_252 )
V_70 = V_162 -> V_249 -> V_252 ( V_162 , V_222 ) ;
else
V_70 = F_153 ( V_162 , V_222 ) ;
return V_70 ;
}
int F_157 ( struct V_244 * V_244 , int V_253 )
{
struct V_161 * V_162 = V_244 -> V_162 ;
int V_70 = 0 ;
struct V_221 V_222 = {
. V_238 = V_239 ,
. V_248 = 1 ,
} ;
F_132 ( ! F_158 ( V_244 ) ) ;
if ( V_253 )
F_147 ( V_244 ) ;
if ( F_148 ( V_244 ) ) {
F_159 ( V_244 ) ;
V_70 = V_162 -> V_249 -> V_223 ( V_244 , & V_222 ) ;
if ( V_70 == 0 && V_253 ) {
F_147 ( V_244 ) ;
if ( F_160 ( V_244 ) )
V_70 = - V_254 ;
}
F_161 ( V_244 ) ;
} else {
F_144 ( V_244 ) ;
}
return V_70 ;
}
int F_162 ( struct V_244 * V_244 )
{
if ( ! F_145 ( V_244 ) )
return ! F_163 ( V_244 ) ;
return 0 ;
}
void F_164 ( struct V_244 * V_244 , struct V_161 * V_162 )
{
struct V_182 * V_182 = V_162 -> V_183 ;
F_165 ( V_244 , V_162 ) ;
if ( F_166 ( V_162 ) ) {
struct V_8 * V_9 ;
F_167 ( V_182 , V_244 ) ;
V_9 = F_168 ( V_182 ) ;
F_169 ( V_244 , V_255 ) ;
F_170 ( V_244 , V_61 ) ;
F_170 ( V_244 , V_256 ) ;
F_36 ( V_9 , V_159 ) ;
F_36 ( V_9 , V_148 ) ;
F_171 ( V_51 ) ;
V_52 -> V_179 ++ ;
F_172 ( V_188 ) ;
}
}
void F_173 ( struct V_244 * V_244 , struct V_161 * V_162 ,
struct V_8 * V_9 )
{
if ( F_166 ( V_162 ) ) {
F_174 ( V_244 , V_255 ) ;
F_175 ( V_244 , V_61 ) ;
F_176 ( V_9 , V_159 ) ;
F_177 ( V_51 ) ;
}
}
int F_178 ( struct V_244 * V_244 )
{
F_179 ( V_244 ) ;
if ( ! F_163 ( V_244 ) ) {
struct V_161 * V_162 = F_180 ( V_244 ) ;
unsigned long V_53 ;
if ( ! V_162 ) {
F_181 ( V_244 ) ;
return 1 ;
}
F_182 ( & V_162 -> V_217 , V_53 ) ;
F_132 ( F_180 ( V_244 ) != V_162 ) ;
F_72 ( ! F_183 ( V_244 ) && ! F_184 ( V_244 ) ) ;
F_164 ( V_244 , V_162 ) ;
F_185 ( & V_162 -> V_218 , F_186 ( V_244 ) ,
V_219 ) ;
F_187 ( & V_162 -> V_217 , V_53 ) ;
F_181 ( V_244 ) ;
if ( V_162 -> V_183 ) {
F_188 ( V_162 -> V_183 , V_257 ) ;
}
return 1 ;
}
F_181 ( V_244 ) ;
return 0 ;
}
void F_189 ( struct V_244 * V_244 )
{
struct V_161 * V_162 = V_244 -> V_162 ;
if ( V_162 && F_166 ( V_162 ) ) {
struct V_182 * V_182 = V_162 -> V_183 ;
struct V_8 * V_9 ;
bool V_258 ;
V_9 = F_190 ( V_182 , & V_258 ) ;
V_52 -> V_179 -- ;
F_175 ( V_244 , V_256 ) ;
F_176 ( V_9 , V_148 ) ;
F_191 ( V_182 , V_258 ) ;
}
}
int F_192 ( struct V_221 * V_222 , struct V_244 * V_244 )
{
int V_70 ;
V_222 -> V_259 ++ ;
V_70 = F_178 ( V_244 ) ;
F_189 ( V_244 ) ;
return V_70 ;
}
int F_193 ( struct V_244 * V_244 )
{
struct V_161 * V_162 = F_180 ( V_244 ) ;
if ( F_194 ( V_162 ) ) {
int (* F_195)( struct V_244 * ) = V_162 -> V_249 -> F_193 ;
if ( F_196 ( V_244 ) )
F_197 ( V_244 ) ;
#ifdef F_198
if ( ! F_195 )
F_195 = V_260 ;
#endif
return (* F_195)( V_244 ) ;
}
if ( ! F_145 ( V_244 ) ) {
if ( ! F_163 ( V_244 ) )
return 1 ;
}
return 0 ;
}
int F_199 ( struct V_244 * V_244 )
{
int V_70 ;
F_143 ( V_244 ) ;
V_70 = F_193 ( V_244 ) ;
F_144 ( V_244 ) ;
return V_70 ;
}
void F_200 ( struct V_244 * V_244 )
{
struct V_161 * V_162 = F_180 ( V_244 ) ;
if ( F_166 ( V_162 ) ) {
struct V_182 * V_182 = V_162 -> V_183 ;
struct V_8 * V_9 ;
bool V_258 ;
F_179 ( V_244 ) ;
V_9 = F_190 ( V_182 , & V_258 ) ;
if ( F_201 ( V_244 ) )
F_173 ( V_244 , V_162 , V_9 ) ;
F_191 ( V_182 , V_258 ) ;
F_181 ( V_244 ) ;
} else {
F_202 ( V_244 ) ;
}
}
int F_148 ( struct V_244 * V_244 )
{
struct V_161 * V_162 = F_180 ( V_244 ) ;
int V_70 = 0 ;
F_132 ( ! F_158 ( V_244 ) ) ;
if ( V_162 && F_166 ( V_162 ) ) {
struct V_182 * V_182 = V_162 -> V_183 ;
struct V_8 * V_9 ;
bool V_258 ;
if ( F_203 ( V_244 ) )
F_193 ( V_244 ) ;
V_9 = F_190 ( V_182 , & V_258 ) ;
if ( F_201 ( V_244 ) ) {
F_174 ( V_244 , V_255 ) ;
F_175 ( V_244 , V_61 ) ;
F_176 ( V_9 , V_159 ) ;
V_70 = 1 ;
}
F_191 ( V_182 , V_258 ) ;
return V_70 ;
}
return F_201 ( V_244 ) ;
}
int F_204 ( struct V_244 * V_244 )
{
struct V_161 * V_162 = F_180 ( V_244 ) ;
int V_70 ;
F_179 ( V_244 ) ;
if ( V_162 ) {
struct V_182 * V_182 = V_162 -> V_183 ;
struct V_89 * V_16 = F_107 ( V_182 ) ;
unsigned long V_53 ;
F_182 ( & V_162 -> V_217 , V_53 ) ;
V_70 = F_205 ( V_244 ) ;
if ( V_70 ) {
F_206 ( & V_162 -> V_218 ,
F_186 ( V_244 ) ,
V_261 ) ;
if ( F_207 ( V_16 ) ) {
struct V_8 * V_9 = F_168 ( V_182 ) ;
F_208 ( V_9 , V_160 ) ;
F_35 ( V_9 ) ;
}
}
F_187 ( & V_162 -> V_217 , V_53 ) ;
} else {
V_70 = F_205 ( V_244 ) ;
}
if ( V_70 ) {
F_174 ( V_244 , V_262 ) ;
F_175 ( V_244 , V_63 ) ;
F_209 ( V_244 , V_263 ) ;
}
F_181 ( V_244 ) ;
return V_70 ;
}
int F_210 ( struct V_244 * V_244 , bool V_264 )
{
struct V_161 * V_162 = F_180 ( V_244 ) ;
int V_70 ;
F_179 ( V_244 ) ;
if ( V_162 ) {
struct V_182 * V_182 = V_162 -> V_183 ;
struct V_89 * V_16 = F_107 ( V_182 ) ;
unsigned long V_53 ;
F_182 ( & V_162 -> V_217 , V_53 ) ;
V_70 = F_211 ( V_244 ) ;
if ( ! V_70 ) {
F_185 ( & V_162 -> V_218 ,
F_186 ( V_244 ) ,
V_261 ) ;
if ( F_207 ( V_16 ) )
F_36 ( F_168 ( V_182 ) , V_160 ) ;
}
if ( ! F_145 ( V_244 ) )
F_206 ( & V_162 -> V_218 ,
F_186 ( V_244 ) ,
V_219 ) ;
if ( ! V_264 )
F_206 ( & V_162 -> V_218 ,
F_186 ( V_244 ) ,
V_220 ) ;
F_187 ( & V_162 -> V_217 , V_53 ) ;
} else {
V_70 = F_211 ( V_244 ) ;
}
if ( ! V_70 ) {
F_169 ( V_244 , V_262 ) ;
F_209 ( V_244 , V_63 ) ;
}
F_181 ( V_244 ) ;
return V_70 ;
}
int F_212 ( struct V_161 * V_162 , int V_233 )
{
return F_213 ( & V_162 -> V_218 , V_233 ) ;
}
void F_214 ( struct V_244 * V_244 )
{
if ( F_215 ( F_107 ( V_244 -> V_162 -> V_183 ) ) )
F_147 ( V_244 ) ;
}
