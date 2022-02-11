static int F_1 ( void )
{
unsigned long V_1 ;
if ( V_2 )
V_1 = V_2 / V_3 ;
else
V_1 = ( V_4 * F_2 () ) /
100 ;
return 2 + F_3 ( V_1 - 1 ) ;
}
static void F_4 ( void )
{
int V_5 = F_1 () ;
F_5 ( & V_6 , V_5 ) ;
F_6 () ;
}
int F_7 ( struct V_7 * V_8 , int V_9 ,
void T_1 * V_10 , T_2 * V_11 ,
T_3 * V_12 )
{
int V_13 ;
V_13 = F_8 ( V_8 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_13 == 0 && V_9 )
V_14 = 0 ;
return V_13 ;
}
int F_9 ( struct V_7 * V_8 , int V_9 ,
void T_1 * V_10 , T_2 * V_11 ,
T_3 * V_12 )
{
int V_13 ;
V_13 = F_10 ( V_8 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_13 == 0 && V_9 )
V_15 = 0 ;
return V_13 ;
}
int F_11 ( struct V_7 * V_8 , int V_9 ,
void T_1 * V_10 , T_2 * V_11 ,
T_3 * V_12 )
{
int V_16 = V_4 ;
int V_13 ;
V_13 = F_8 ( V_8 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_13 == 0 && V_9 && V_4 != V_16 ) {
F_4 () ;
V_2 = 0 ;
}
return V_13 ;
}
int F_12 ( struct V_7 * V_8 , int V_9 ,
void T_1 * V_10 , T_2 * V_11 ,
T_3 * V_12 )
{
unsigned long V_17 = V_2 ;
int V_13 ;
V_13 = F_10 ( V_8 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_13 == 0 && V_9 && V_2 != V_17 ) {
F_4 () ;
V_4 = 0 ;
}
return V_13 ;
}
static inline void F_13 ( struct V_18 * V_19 )
{
F_14 ( V_19 , V_20 ) ;
F_15 ( & V_6 , & V_19 -> V_21 ,
V_19 -> V_22 ) ;
}
void F_16 ( struct V_18 * V_19 )
{
unsigned long V_23 ;
F_17 ( V_23 ) ;
F_13 ( V_19 ) ;
F_18 ( V_23 ) ;
}
static void F_19 ( struct V_18 * V_19 ,
long * V_24 , long * V_25 )
{
F_20 ( & V_6 , & V_19 -> V_21 ,
V_24 , V_25 ) ;
}
int F_21 ( struct V_18 * V_19 , unsigned int V_26 )
{
int V_13 = 0 ;
F_22 ( & V_27 ) ;
if ( V_26 > V_19 -> V_28 ) {
V_13 = - V_29 ;
} else {
V_26 -= V_19 -> V_26 ;
if ( V_30 + V_26 < 100 ) {
V_30 += V_26 ;
V_19 -> V_26 += V_26 ;
} else {
V_13 = - V_29 ;
}
}
F_23 ( & V_27 ) ;
return V_13 ;
}
int F_24 ( struct V_18 * V_19 , unsigned V_28 )
{
int V_13 = 0 ;
if ( V_28 > 100 )
return - V_29 ;
F_22 ( & V_27 ) ;
if ( V_19 -> V_26 > V_28 ) {
V_13 = - V_29 ;
} else {
V_19 -> V_28 = V_28 ;
V_19 -> V_22 = ( V_31 * V_28 ) / 100 ;
}
F_23 ( & V_27 ) ;
return V_13 ;
}
static unsigned long F_25 ( unsigned long V_32 )
{
#ifdef F_26
int V_33 ;
unsigned long V_34 = 0 ;
F_27 (node, N_HIGH_MEMORY) {
struct V_35 * V_36 =
& F_28 ( V_33 ) -> V_37 [ V_38 ] ;
V_34 += F_29 ( V_36 , V_39 ) +
F_30 ( V_36 ) ;
}
return F_31 ( V_34 , V_32 ) ;
#else
return 0 ;
#endif
}
unsigned long F_2 ( void )
{
unsigned long V_34 ;
V_34 = F_32 ( V_39 ) + F_33 () ;
if ( ! V_40 )
V_34 -= F_25 ( V_34 ) ;
return V_34 + 1 ;
}
static unsigned long F_34 ( unsigned long V_41 ,
unsigned long V_42 )
{
return ( V_41 + V_42 ) / 2 ;
}
static unsigned long F_35 ( unsigned long V_41 )
{
return F_36 ( V_41 , V_43 ) ;
}
void F_37 ( unsigned long * V_44 , unsigned long * V_45 )
{
unsigned long V_46 ;
unsigned long V_47 ;
unsigned long V_48 ( V_49 ) ;
struct V_50 * V_51 ;
if ( ! V_2 || ! V_14 )
V_49 = F_2 () ;
if ( V_2 )
V_47 = F_38 ( V_2 , V_3 ) ;
else
V_47 = ( V_4 * V_49 ) / 100 ;
if ( V_14 )
V_46 = F_38 ( V_14 , V_3 ) ;
else
V_46 = ( V_15 * V_49 ) / 100 ;
if ( V_46 >= V_47 )
V_46 = V_47 / 2 ;
V_51 = V_52 ;
if ( V_51 -> V_23 & V_53 || F_39 ( V_51 ) ) {
V_46 += V_46 / 4 ;
V_47 += V_47 / 4 ;
}
* V_44 = V_46 ;
* V_45 = V_47 ;
F_40 ( V_46 , V_47 ) ;
}
unsigned long F_41 ( struct V_18 * V_19 , unsigned long V_47 )
{
T_4 V_54 ;
long V_24 , V_25 ;
F_19 ( V_19 , & V_24 , & V_25 ) ;
V_54 = ( V_47 * ( 100 - V_30 ) ) / 100 ;
V_54 *= V_24 ;
F_42 ( V_54 , V_25 ) ;
V_54 += ( V_47 * V_19 -> V_26 ) / 100 ;
if ( V_54 > ( V_47 * V_19 -> V_28 ) / 100 )
V_54 = V_47 * V_19 -> V_28 / 100 ;
return V_54 ;
}
static unsigned long F_43 ( struct V_18 * V_19 ,
unsigned long V_41 ,
unsigned long V_42 ,
unsigned long V_47 ,
unsigned long V_55 ,
unsigned long V_54 )
{
unsigned long V_56 = V_19 -> V_57 ;
unsigned long V_58 = F_34 ( V_41 , V_42 ) ;
unsigned long V_59 = F_35 ( V_41 ) ;
unsigned long V_60 ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long V_63 ;
long long V_64 ;
long V_34 ;
if ( F_44 ( V_47 >= V_59 ) )
return 0 ;
V_61 = ( V_58 + V_59 ) / 2 ;
V_34 = F_45 ( ( V_61 - V_47 ) << V_65 ,
V_59 - V_61 + 1 ) ;
V_64 = V_34 ;
V_64 = V_64 * V_34 >> V_65 ;
V_64 = V_64 * V_34 >> V_65 ;
V_64 += 1 << V_65 ;
if ( F_44 ( V_55 > V_41 ) )
V_55 = V_41 ;
V_55 = F_36 ( V_55 , ( V_59 - V_47 ) / 8 ) ;
V_34 = F_46 ( ( T_4 ) V_55 << 16 , V_41 + 1 ) ;
V_62 = V_61 * ( T_4 ) V_34 >> 16 ;
V_63 = ( V_41 - V_55 + 8 * V_56 ) * ( T_4 ) V_34 >> 16 ;
V_60 = V_62 + V_63 ;
if ( V_54 < V_60 - V_63 / 4 ) {
V_64 = F_46 ( V_64 * ( V_60 - V_54 ) ,
V_60 - V_62 + 1 ) ;
} else
V_64 /= 4 ;
V_60 = V_55 / 2 ;
if ( V_54 < V_60 ) {
if ( V_54 > V_60 / 8 )
V_64 = F_46 ( V_64 * V_60 , V_54 ) ;
else
V_64 *= 8 ;
}
return V_64 ;
}
static void F_47 ( struct V_18 * V_19 ,
unsigned long V_66 ,
unsigned long V_67 )
{
const unsigned long V_68 = F_48 ( 3 * V_69 ) ;
unsigned long V_70 = V_19 -> V_57 ;
unsigned long V_71 = V_19 -> V_72 ;
T_4 V_73 ;
V_73 = V_67 - V_19 -> V_74 ;
V_73 *= V_69 ;
if ( F_44 ( V_66 > V_68 ) ) {
F_42 ( V_73 , V_66 ) ;
V_70 = V_73 ;
goto V_75;
}
V_73 += ( T_4 ) V_19 -> V_72 * ( V_68 - V_66 ) ;
V_73 >>= F_3 ( V_68 ) ;
if ( V_70 > V_71 && V_71 >= ( unsigned long ) V_73 )
V_70 -= ( V_70 - V_71 ) >> 3 ;
if ( V_70 < V_71 && V_71 <= ( unsigned long ) V_73 )
V_70 += ( V_71 - V_70 ) >> 3 ;
V_75:
V_19 -> V_72 = V_73 ;
V_19 -> V_57 = V_70 ;
}
static void F_49 ( unsigned long V_41 , unsigned long V_47 )
{
unsigned long V_59 = V_43 ;
if ( V_59 < V_41 ) {
V_59 = V_41 ;
goto V_76;
}
V_41 = F_36 ( V_41 , V_47 ) ;
if ( V_59 > V_41 ) {
V_59 -= ( V_59 - V_41 ) >> 5 ;
goto V_76;
}
return;
V_76:
V_43 = V_59 ;
}
static void F_50 ( unsigned long V_41 ,
unsigned long V_47 ,
unsigned long V_77 )
{
static F_51 ( V_78 ) ;
static unsigned long V_79 ;
if ( F_52 ( V_77 , V_79 + V_80 ) )
return;
F_53 ( & V_78 ) ;
if ( F_54 ( V_77 , V_79 + V_80 ) ) {
F_49 ( V_41 , V_47 ) ;
V_79 = V_77 ;
}
F_55 ( & V_78 ) ;
}
static void F_56 ( struct V_18 * V_19 ,
unsigned long V_41 ,
unsigned long V_42 ,
unsigned long V_47 ,
unsigned long V_55 ,
unsigned long V_54 ,
unsigned long V_81 ,
unsigned long V_66 )
{
unsigned long V_58 = F_34 ( V_41 , V_42 ) ;
unsigned long V_59 = F_35 ( V_41 ) ;
unsigned long V_61 = ( V_58 + V_59 ) / 2 ;
unsigned long V_56 = V_19 -> V_57 ;
unsigned long V_82 = V_19 -> V_82 ;
unsigned long V_83 ;
unsigned long V_84 ;
unsigned long V_85 ;
unsigned long V_64 ;
unsigned long V_86 ;
unsigned long V_34 ;
V_83 = ( V_81 - V_19 -> V_87 ) * V_69 / V_66 ;
V_64 = F_43 ( V_19 , V_41 , V_42 , V_47 ,
V_55 , V_54 ) ;
V_84 = ( T_4 ) V_82 *
V_64 >> V_65 ;
V_84 ++ ;
V_85 = F_46 ( ( T_4 ) V_84 * V_56 ,
V_83 | 1 ) ;
V_86 = 0 ;
if ( V_47 < V_61 ) {
V_34 = F_31 ( V_19 -> V_85 ,
F_31 ( V_85 , V_84 ) ) ;
if ( V_82 < V_34 )
V_86 = V_34 - V_82 ;
} else {
V_34 = F_36 ( V_19 -> V_85 ,
F_36 ( V_85 , V_84 ) ) ;
if ( V_82 > V_34 )
V_86 = V_82 - V_34 ;
}
V_86 >>= V_82 / ( 2 * V_86 + 1 ) ;
V_86 = ( V_86 + 7 ) / 8 ;
if ( V_82 < V_85 )
V_82 += V_86 ;
else
V_82 -= V_86 ;
V_19 -> V_82 = F_36 ( V_82 , 1UL ) ;
V_19 -> V_85 = V_85 ;
F_57 ( V_19 , V_83 , V_84 ) ;
}
void F_58 ( struct V_18 * V_19 ,
unsigned long V_41 ,
unsigned long V_42 ,
unsigned long V_47 ,
unsigned long V_55 ,
unsigned long V_54 ,
unsigned long V_88 )
{
unsigned long V_77 = V_89 ;
unsigned long V_66 = V_77 - V_19 -> V_90 ;
unsigned long V_81 ;
unsigned long V_67 ;
if ( V_66 < V_80 )
return;
V_81 = F_59 ( & V_19 -> V_91 [ V_92 ] ) ;
V_67 = F_59 ( & V_19 -> V_91 [ V_20 ] ) ;
if ( V_66 > V_69 && F_52 ( V_19 -> V_90 , V_88 ) )
goto V_93;
if ( V_41 ) {
F_50 ( V_41 , V_47 , V_77 ) ;
F_56 ( V_19 , V_41 , V_42 , V_47 ,
V_55 , V_54 ,
V_81 , V_66 ) ;
}
F_47 ( V_19 , V_66 , V_67 ) ;
V_93:
V_19 -> V_87 = V_81 ;
V_19 -> V_74 = V_67 ;
V_19 -> V_90 = V_77 ;
}
static void F_60 ( struct V_18 * V_19 ,
unsigned long V_41 ,
unsigned long V_42 ,
unsigned long V_47 ,
unsigned long V_55 ,
unsigned long V_54 ,
unsigned long V_88 )
{
if ( F_61 ( V_19 -> V_90 + V_80 ) )
return;
F_53 ( & V_19 -> V_94 . V_95 ) ;
F_58 ( V_19 , V_41 , V_42 , V_47 ,
V_55 , V_54 , V_88 ) ;
F_55 ( & V_19 -> V_94 . V_95 ) ;
}
static unsigned long F_62 ( unsigned long V_47 ,
unsigned long V_41 )
{
if ( V_41 > V_47 )
return 1UL << ( F_3 ( V_41 - V_47 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_63 ( struct V_18 * V_19 ,
unsigned long V_54 )
{
unsigned long V_73 = V_19 -> V_57 ;
unsigned long V_96 = F_3 ( V_73 ) ;
unsigned long V_97 = F_3 ( V_19 -> V_82 ) ;
unsigned long V_98 ;
V_98 = V_69 / 50 ;
if ( V_96 > V_97 )
V_98 += ( V_96 - V_97 ) * ( 20 * V_69 ) / 1024 ;
V_98 = F_31 ( V_98 , V_54 * V_69 / ( 8 * V_73 + 1 ) ) ;
return F_64 ( V_98 , 4 , V_99 ) ;
}
static void F_65 ( struct V_100 * V_101 ,
unsigned long V_102 )
{
unsigned long V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
unsigned long V_54 ;
unsigned long V_58 ;
unsigned long V_106 ;
unsigned long V_107 ;
unsigned long V_55 ;
long V_108 = 0 ;
long V_48 ( V_109 ) ;
bool V_110 = false ;
unsigned long V_84 ;
unsigned long V_48 ( V_82 ) ;
unsigned long V_64 ;
struct V_18 * V_19 = V_101 -> V_18 ;
unsigned long V_88 = V_89 ;
for (; ; ) {
V_103 = F_32 ( V_111 ) +
F_32 ( V_112 ) ;
V_105 = V_103 + F_32 ( V_113 ) ;
F_37 ( & V_106 , & V_107 ) ;
V_58 = F_34 ( V_107 ,
V_106 ) ;
if ( V_105 <= V_58 )
break;
if ( F_44 ( ! F_66 ( V_19 ) ) )
F_67 ( V_19 ) ;
V_55 = F_41 ( V_19 , V_107 ) ;
if ( V_55 < 2 * F_68 ( V_19 ) ) {
V_104 = F_69 ( V_19 , V_114 ) ;
V_54 = V_104 +
F_69 ( V_19 , V_115 ) ;
} else {
V_104 = V_91 ( V_19 , V_114 ) ;
V_54 = V_104 +
V_91 ( V_19 , V_115 ) ;
}
V_110 = ( V_54 > V_55 ) ||
( V_105 > V_107 ) ;
if ( V_110 && ! V_19 -> V_110 )
V_19 -> V_110 = 1 ;
F_60 ( V_19 , V_107 , V_106 ,
V_105 , V_55 , V_54 ,
V_88 ) ;
V_109 = F_63 ( V_19 , V_54 ) ;
V_82 = V_19 -> V_82 ;
V_64 = F_43 ( V_19 , V_107 ,
V_106 , V_105 ,
V_55 , V_54 ) ;
V_84 = ( ( T_4 ) V_82 * V_64 ) >>
V_65 ;
if ( F_44 ( V_84 == 0 ) ) {
V_108 = V_109 ;
goto V_108;
}
V_108 = V_69 * V_102 / V_84 ;
if ( F_44 ( V_108 <= 0 ) ) {
F_70 ( V_19 ,
V_107 ,
V_106 ,
V_105 ,
V_55 ,
V_54 ,
V_82 ,
V_84 ,
V_102 ,
V_108 ,
V_88 ) ;
V_108 = 1 ;
break;
}
V_108 = F_31 ( V_108 , V_109 ) ;
V_108:
F_70 ( V_19 ,
V_107 ,
V_106 ,
V_105 ,
V_55 ,
V_54 ,
V_82 ,
V_84 ,
V_102 ,
V_108 ,
V_88 ) ;
F_71 ( V_116 ) ;
F_72 ( V_108 ) ;
if ( V_84 )
break;
if ( V_54 <= F_68 ( V_19 ) )
break;
if ( F_73 ( V_52 ) )
break;
}
if ( ! V_110 && V_19 -> V_110 )
V_19 -> V_110 = 0 ;
V_52 -> V_117 = 0 ;
if ( V_108 == 0 ) {
V_52 -> V_118 =
F_62 ( V_105 , V_107 ) ;
} else if ( V_108 <= V_109 / 4 &&
V_102 >= V_52 -> V_118 ) {
V_52 -> V_118 = F_64 (
V_82 * ( V_109 / 2 ) / V_69 ,
V_102 + V_102 / 8 ,
V_102 * 4 ) ;
} else if ( V_108 >= V_109 ) {
V_52 -> V_118 = 1 | F_64 (
V_82 * ( V_109 / 2 ) / V_69 ,
V_102 / 4 ,
V_102 - V_102 / 8 ) ;
}
if ( F_66 ( V_19 ) )
return;
if ( V_119 )
return;
if ( V_103 > V_106 )
F_67 ( V_19 ) ;
}
void F_74 ( struct V_120 * V_120 , int V_121 )
{
if ( F_75 ( V_120 ) || V_121 ) {
struct V_100 * V_101 = F_76 ( V_120 ) ;
if ( V_101 )
F_77 ( V_101 ) ;
}
}
void F_78 ( struct V_100 * V_101 ,
unsigned long V_122 )
{
struct V_18 * V_19 = V_101 -> V_18 ;
int V_123 ;
int * V_124 ;
if ( ! F_79 ( V_19 ) )
return;
V_123 = V_52 -> V_118 ;
if ( V_19 -> V_110 )
V_123 = F_31 ( V_123 , 32 >> ( V_125 - 10 ) ) ;
V_52 -> V_117 += V_122 ;
F_80 () ;
V_124 = & F_81 ( V_126 ) ;
if ( F_44 ( V_52 -> V_117 >= V_123 ) )
* V_124 = 0 ;
else {
* V_124 += V_122 ;
if ( F_44 ( * V_124 >= V_127 ) ) {
* V_124 = 0 ;
V_123 = 0 ;
}
}
F_82 () ;
if ( F_44 ( V_52 -> V_117 >= V_123 ) )
F_65 ( V_101 , V_52 -> V_117 ) ;
}
void F_83 ( T_5 V_128 )
{
unsigned long V_106 ;
unsigned long V_107 ;
for ( ; ; ) {
F_37 ( & V_106 , & V_107 ) ;
V_107 += V_107 / 10 ;
if ( F_32 ( V_112 ) +
F_32 ( V_113 ) <= V_107 )
break;
F_84 ( V_129 , V_69 / 10 ) ;
if ( ( V_128 & ( V_130 | V_131 ) ) != ( V_130 | V_131 ) )
break;
}
}
int F_85 ( V_7 * V_8 , int V_9 ,
void T_1 * V_10 , T_2 * V_132 , T_3 * V_12 )
{
F_86 ( V_8 , V_9 , V_10 , V_132 , V_12 ) ;
F_87 () ;
return 0 ;
}
void F_88 ( unsigned long V_133 )
{
struct V_134 * V_135 = (struct V_134 * ) V_133 ;
int V_136 = F_32 ( V_111 ) +
F_32 ( V_112 ) ;
if ( F_89 ( & V_135 -> V_18 ) )
F_90 ( & V_135 -> V_18 , V_136 ,
V_137 ) ;
}
void F_91 ( struct V_18 * V_138 )
{
F_92 ( & V_138 -> V_139 , V_89 + V_119 ) ;
}
void F_93 ( void )
{
struct V_18 * V_19 ;
F_94 () ;
F_95 (bdi, &bdi_list, bdi_list)
F_96 ( & V_19 -> V_139 ) ;
F_97 () ;
}
void F_6 ( void )
{
unsigned long V_106 ;
unsigned long V_107 ;
F_37 ( & V_106 , & V_107 ) ;
V_127 = V_107 / ( F_98 () * 32 ) ;
if ( V_127 < 16 )
V_127 = 16 ;
}
static int T_6
F_99 ( struct V_140 * V_141 , unsigned long V_142 , void * V_143 )
{
F_6 () ;
return V_144 ;
}
void T_7 F_100 ( void )
{
int V_5 ;
F_6 () ;
F_101 ( & V_145 ) ;
V_5 = F_1 () ;
F_102 ( & V_6 , V_5 ) ;
}
void F_103 ( struct V_100 * V_101 ,
T_8 V_146 , T_8 V_147 )
{
#define F_104 4096
unsigned long V_148 ;
do {
F_105 ( & V_101 -> V_149 ) ;
V_148 = F_106 ( & V_101 -> V_150 ,
& V_146 , V_147 , F_104 ,
V_151 , V_152 ) ;
F_107 ( & V_101 -> V_149 ) ;
F_108 ( V_148 > F_104 ) ;
F_109 () ;
} while ( V_148 >= F_104 && V_146 );
}
int F_110 ( struct V_100 * V_101 ,
struct V_153 * V_154 , T_9 V_155 ,
void * V_133 )
{
int V_13 = 0 ;
int V_156 = 0 ;
struct V_157 V_158 ;
int V_136 ;
T_8 V_48 ( V_159 ) ;
T_8 V_160 ;
T_8 V_147 ;
T_8 V_161 ;
int V_162 ;
int V_163 = 0 ;
int V_164 ;
F_111 ( & V_158 , 0 ) ;
if ( V_154 -> V_165 ) {
V_159 = V_101 -> V_159 ;
V_160 = V_159 ;
if ( V_160 == 0 )
V_162 = 1 ;
else
V_162 = 0 ;
V_147 = - 1 ;
} else {
V_160 = V_154 -> V_166 >> V_167 ;
V_147 = V_154 -> V_168 >> V_167 ;
if ( V_154 -> V_166 == 0 && V_154 -> V_168 == V_169 )
V_163 = 1 ;
V_162 = 1 ;
}
if ( V_154 -> V_170 == V_171 || V_154 -> V_172 )
V_164 = V_152 ;
else
V_164 = V_151 ;
V_173:
if ( V_154 -> V_170 == V_171 || V_154 -> V_172 )
F_103 ( V_101 , V_160 , V_147 ) ;
V_161 = V_160 ;
while ( ! V_156 && ( V_160 <= V_147 ) ) {
int V_174 ;
V_136 = F_112 ( & V_158 , V_101 , & V_160 , V_164 ,
F_31 ( V_147 - V_160 , ( T_8 ) V_175 - 1 ) + 1 ) ;
if ( V_136 == 0 )
break;
for ( V_174 = 0 ; V_174 < V_136 ; V_174 ++ ) {
struct V_120 * V_120 = V_158 . V_176 [ V_174 ] ;
if ( V_120 -> V_160 > V_147 ) {
V_156 = 1 ;
break;
}
V_161 = V_120 -> V_160 ;
F_113 ( V_120 ) ;
if ( F_44 ( V_120 -> V_101 != V_101 ) ) {
V_177:
F_114 ( V_120 ) ;
continue;
}
if ( ! F_115 ( V_120 ) ) {
goto V_177;
}
if ( F_116 ( V_120 ) ) {
if ( V_154 -> V_170 != V_178 )
F_117 ( V_120 ) ;
else
goto V_177;
}
F_118 ( F_116 ( V_120 ) ) ;
if ( ! F_119 ( V_120 ) )
goto V_177;
F_120 ( V_154 , V_101 -> V_18 ) ;
V_13 = (* V_155)( V_120 , V_154 , V_133 ) ;
if ( F_44 ( V_13 ) ) {
if ( V_13 == V_179 ) {
F_114 ( V_120 ) ;
V_13 = 0 ;
} else {
V_161 = V_120 -> V_160 + 1 ;
V_156 = 1 ;
break;
}
}
if ( -- V_154 -> V_180 <= 0 &&
V_154 -> V_170 == V_178 ) {
V_156 = 1 ;
break;
}
}
F_121 ( & V_158 ) ;
F_109 () ;
}
if ( ! V_162 && ! V_156 ) {
V_162 = 1 ;
V_160 = 0 ;
V_147 = V_159 - 1 ;
goto V_173;
}
if ( V_154 -> V_165 || ( V_163 && V_154 -> V_180 > 0 ) )
V_101 -> V_159 = V_161 ;
return V_13 ;
}
static int F_122 ( struct V_120 * V_120 , struct V_153 * V_154 ,
void * V_133 )
{
struct V_100 * V_101 = V_133 ;
int V_13 = V_101 -> V_181 -> V_155 ( V_120 , V_154 ) ;
F_123 ( V_101 , V_13 ) ;
return V_13 ;
}
int F_124 ( struct V_100 * V_101 ,
struct V_153 * V_154 )
{
struct V_182 V_183 ;
int V_13 ;
if ( ! V_101 -> V_181 -> V_155 )
return 0 ;
F_125 ( & V_183 ) ;
V_13 = F_110 ( V_101 , V_154 , F_122 , V_101 ) ;
F_126 ( & V_183 ) ;
return V_13 ;
}
int F_127 ( struct V_100 * V_101 , struct V_153 * V_154 )
{
int V_13 ;
if ( V_154 -> V_180 <= 0 )
return 0 ;
if ( V_101 -> V_181 -> V_184 )
V_13 = V_101 -> V_181 -> V_184 ( V_101 , V_154 ) ;
else
V_13 = F_124 ( V_101 , V_154 ) ;
return V_13 ;
}
int F_128 ( struct V_120 * V_120 , int V_185 )
{
struct V_100 * V_101 = V_120 -> V_101 ;
int V_13 = 0 ;
struct V_153 V_154 = {
. V_170 = V_171 ,
. V_180 = 1 ,
} ;
F_118 ( ! F_129 ( V_120 ) ) ;
if ( V_185 )
F_117 ( V_120 ) ;
if ( F_119 ( V_120 ) ) {
F_130 ( V_120 ) ;
V_13 = V_101 -> V_181 -> V_155 ( V_120 , & V_154 ) ;
if ( V_13 == 0 && V_185 ) {
F_117 ( V_120 ) ;
if ( F_131 ( V_120 ) )
V_13 = - V_186 ;
}
F_132 ( V_120 ) ;
} else {
F_114 ( V_120 ) ;
}
return V_13 ;
}
int F_133 ( struct V_120 * V_120 )
{
if ( ! F_115 ( V_120 ) )
return ! F_134 ( V_120 ) ;
return 0 ;
}
void F_135 ( struct V_120 * V_120 , struct V_100 * V_101 )
{
if ( F_136 ( V_101 ) ) {
F_137 ( V_120 , V_111 ) ;
F_137 ( V_120 , V_187 ) ;
F_14 ( V_101 -> V_18 , V_114 ) ;
F_14 ( V_101 -> V_18 , V_92 ) ;
F_138 ( V_188 ) ;
}
}
void F_139 ( struct V_120 * V_120 )
{
F_140 ( V_120 , V_113 ) ;
}
int F_141 ( struct V_120 * V_120 )
{
if ( ! F_134 ( V_120 ) ) {
struct V_100 * V_101 = F_76 ( V_120 ) ;
struct V_100 * V_189 ;
if ( ! V_101 )
return 1 ;
F_105 ( & V_101 -> V_149 ) ;
V_189 = F_76 ( V_120 ) ;
if ( V_189 ) {
F_118 ( V_189 != V_101 ) ;
F_108 ( ! F_142 ( V_120 ) && ! F_143 ( V_120 ) ) ;
F_135 ( V_120 , V_101 ) ;
F_144 ( & V_101 -> V_150 ,
F_145 ( V_120 ) , V_151 ) ;
}
F_107 ( & V_101 -> V_149 ) ;
if ( V_101 -> V_190 ) {
F_146 ( V_101 -> V_190 , V_191 ) ;
}
return 1 ;
}
return 0 ;
}
int F_147 ( struct V_153 * V_154 , struct V_120 * V_120 )
{
V_154 -> V_192 ++ ;
return F_141 ( V_120 ) ;
}
int F_75 ( struct V_120 * V_120 )
{
struct V_100 * V_101 = F_76 ( V_120 ) ;
if ( F_148 ( V_101 ) ) {
int (* F_149)( struct V_120 * ) = V_101 -> V_181 -> F_75 ;
F_150 ( V_120 ) ;
#ifdef F_151
if ( ! F_149 )
F_149 = V_193 ;
#endif
return (* F_149)( V_120 ) ;
}
if ( ! F_115 ( V_120 ) ) {
if ( ! F_134 ( V_120 ) )
return 1 ;
}
return 0 ;
}
int F_152 ( struct V_120 * V_120 )
{
int V_13 ;
F_113 ( V_120 ) ;
V_13 = F_75 ( V_120 ) ;
F_114 ( V_120 ) ;
return V_13 ;
}
int F_119 ( struct V_120 * V_120 )
{
struct V_100 * V_101 = F_76 ( V_120 ) ;
F_118 ( ! F_129 ( V_120 ) ) ;
if ( V_101 && F_136 ( V_101 ) ) {
if ( F_153 ( V_120 ) )
F_75 ( V_120 ) ;
if ( F_154 ( V_120 ) ) {
F_155 ( V_120 , V_111 ) ;
F_156 ( V_101 -> V_18 ,
V_114 ) ;
return 1 ;
}
return 0 ;
}
return F_154 ( V_120 ) ;
}
int F_157 ( struct V_120 * V_120 )
{
struct V_100 * V_101 = F_76 ( V_120 ) ;
int V_13 ;
if ( V_101 ) {
struct V_18 * V_19 = V_101 -> V_18 ;
unsigned long V_23 ;
F_158 ( & V_101 -> V_149 , V_23 ) ;
V_13 = F_159 ( V_120 ) ;
if ( V_13 ) {
F_160 ( & V_101 -> V_150 ,
F_145 ( V_120 ) ,
V_194 ) ;
if ( F_161 ( V_19 ) ) {
F_162 ( V_19 , V_115 ) ;
F_13 ( V_19 ) ;
}
}
F_163 ( & V_101 -> V_149 , V_23 ) ;
} else {
V_13 = F_159 ( V_120 ) ;
}
if ( V_13 ) {
F_155 ( V_120 , V_113 ) ;
F_140 ( V_120 , V_195 ) ;
}
return V_13 ;
}
int F_164 ( struct V_120 * V_120 )
{
struct V_100 * V_101 = F_76 ( V_120 ) ;
int V_13 ;
if ( V_101 ) {
struct V_18 * V_19 = V_101 -> V_18 ;
unsigned long V_23 ;
F_158 ( & V_101 -> V_149 , V_23 ) ;
V_13 = F_165 ( V_120 ) ;
if ( ! V_13 ) {
F_144 ( & V_101 -> V_150 ,
F_145 ( V_120 ) ,
V_194 ) ;
if ( F_161 ( V_19 ) )
F_14 ( V_19 , V_115 ) ;
}
if ( ! F_115 ( V_120 ) )
F_160 ( & V_101 -> V_150 ,
F_145 ( V_120 ) ,
V_151 ) ;
F_160 ( & V_101 -> V_150 ,
F_145 ( V_120 ) ,
V_152 ) ;
F_163 ( & V_101 -> V_149 , V_23 ) ;
} else {
V_13 = F_165 ( V_120 ) ;
}
if ( ! V_13 )
F_139 ( V_120 ) ;
return V_13 ;
}
int F_166 ( struct V_100 * V_101 , int V_164 )
{
return F_167 ( & V_101 -> V_150 , V_164 ) ;
}
