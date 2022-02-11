static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_2 ( V_1 , V_3 ) ;
V_2 -= F_3 ( V_2 , V_1 -> V_4 ) ;
V_2 += F_2 ( V_1 , V_5 ) ;
V_2 += F_2 ( V_1 , V_6 ) ;
return V_2 ;
}
static unsigned long F_4 ( unsigned long V_7 )
{
#ifdef F_5
int V_8 ;
unsigned long V_9 = 0 ;
F_6 (node, N_HIGH_MEMORY) {
struct V_1 * V_10 = & F_7 ( V_8 ) -> V_11 [ V_12 ] ;
V_9 += F_1 ( V_10 ) ;
}
if ( ( long ) V_9 < 0 )
V_9 = 0 ;
return F_3 ( V_9 , V_7 ) ;
#else
return 0 ;
#endif
}
static unsigned long F_8 ( void )
{
unsigned long V_9 ;
V_9 = F_9 ( V_3 ) ;
V_9 -= F_3 ( V_9 , V_4 ) ;
V_9 += F_9 ( V_5 ) ;
V_9 += F_9 ( V_6 ) ;
if ( ! V_13 )
V_9 -= F_4 ( V_9 ) ;
return V_9 + 1 ;
}
void F_10 ( unsigned long * V_14 , unsigned long * V_15 )
{
const unsigned long V_16 = F_8 () ;
unsigned long V_17 ;
unsigned long V_18 ;
struct V_19 * V_20 ;
if ( V_21 )
V_18 = F_11 ( V_21 , V_22 ) ;
else
V_18 = ( V_23 * V_16 ) / 100 ;
if ( V_24 )
V_17 = F_11 ( V_24 , V_22 ) ;
else
V_17 = ( V_25 * V_16 ) / 100 ;
if ( V_17 >= V_18 )
V_17 = V_18 / 2 ;
V_20 = V_26 ;
if ( V_20 -> V_27 & V_28 || F_12 ( V_20 ) ) {
V_17 += V_17 / 4 ;
V_18 += V_18 / 4 ;
}
* V_14 = V_17 ;
* V_15 = V_18 ;
F_13 ( V_17 , V_18 ) ;
}
static unsigned long F_14 ( struct V_1 * V_1 )
{
unsigned long V_29 = F_1 ( V_1 ) ;
struct V_19 * V_20 = V_26 ;
unsigned long V_18 ;
if ( V_21 )
V_18 = F_11 ( V_21 , V_22 ) *
V_29 / F_8 () ;
else
V_18 = V_23 * V_29 / 100 ;
if ( V_20 -> V_27 & V_28 || F_12 ( V_20 ) )
V_18 += V_18 / 4 ;
return V_18 ;
}
bool F_15 ( struct V_1 * V_1 )
{
unsigned long V_30 = F_14 ( V_1 ) ;
return F_2 ( V_1 , V_31 ) +
F_2 ( V_1 , V_32 ) +
F_2 ( V_1 , V_33 ) <= V_30 ;
}
int F_16 ( struct V_34 * V_35 , int V_36 ,
void T_1 * V_37 , T_2 * V_38 ,
T_3 * V_39 )
{
int V_40 ;
V_40 = F_17 ( V_35 , V_36 , V_37 , V_38 , V_39 ) ;
if ( V_40 == 0 && V_36 )
V_24 = 0 ;
return V_40 ;
}
int F_18 ( struct V_34 * V_35 , int V_36 ,
void T_1 * V_37 , T_2 * V_38 ,
T_3 * V_39 )
{
int V_40 ;
V_40 = F_19 ( V_35 , V_36 , V_37 , V_38 , V_39 ) ;
if ( V_40 == 0 && V_36 )
V_25 = 0 ;
return V_40 ;
}
int F_20 ( struct V_34 * V_35 , int V_36 ,
void T_1 * V_37 , T_2 * V_38 ,
T_3 * V_39 )
{
int V_41 = V_23 ;
int V_40 ;
V_40 = F_17 ( V_35 , V_36 , V_37 , V_38 , V_39 ) ;
if ( V_40 == 0 && V_36 && V_23 != V_41 ) {
F_21 () ;
V_21 = 0 ;
}
return V_40 ;
}
int F_22 ( struct V_34 * V_35 , int V_36 ,
void T_1 * V_37 , T_2 * V_38 ,
T_3 * V_39 )
{
unsigned long V_42 = V_21 ;
int V_40 ;
V_40 = F_19 ( V_35 , V_36 , V_37 , V_38 , V_39 ) ;
if ( V_40 == 0 && V_36 && V_21 != V_42 ) {
F_21 () ;
V_23 = 0 ;
}
return V_40 ;
}
static unsigned long F_23 ( unsigned long V_43 )
{
V_43 += V_44 ;
if ( ! V_43 )
return 1 ;
return V_43 ;
}
static inline void F_24 ( struct V_45 * V_46 )
{
F_25 ( V_46 , V_47 ) ;
F_26 ( & V_48 , & V_46 -> V_49 ,
V_46 -> V_50 ) ;
if ( ! F_27 ( V_51 ) ) {
V_51 = F_23 ( V_52 ) ;
F_28 ( & V_53 , V_51 ) ;
}
}
void F_29 ( struct V_45 * V_46 )
{
unsigned long V_27 ;
F_30 ( V_27 ) ;
F_24 ( V_46 ) ;
F_31 ( V_27 ) ;
}
static void F_32 ( struct V_45 * V_46 ,
long * V_54 , long * V_55 )
{
F_33 ( & V_48 , & V_46 -> V_49 ,
V_54 , V_55 ) ;
}
static void F_34 ( unsigned long V_56 )
{
int V_57 = ( V_52 - V_51 ) /
V_44 ;
if ( F_35 ( & V_48 , V_57 + 1 ) ) {
V_51 = F_23 ( V_51 +
V_57 * V_44 ) ;
F_28 ( & V_53 , V_51 ) ;
} else {
V_51 = 0 ;
}
}
int F_36 ( struct V_45 * V_46 , unsigned int V_58 )
{
int V_40 = 0 ;
F_37 ( & V_59 ) ;
if ( V_58 > V_46 -> V_60 ) {
V_40 = - V_61 ;
} else {
V_58 -= V_46 -> V_58 ;
if ( V_62 + V_58 < 100 ) {
V_62 += V_58 ;
V_46 -> V_58 += V_58 ;
} else {
V_40 = - V_61 ;
}
}
F_38 ( & V_59 ) ;
return V_40 ;
}
int F_39 ( struct V_45 * V_46 , unsigned V_60 )
{
int V_40 = 0 ;
if ( V_60 > 100 )
return - V_61 ;
F_37 ( & V_59 ) ;
if ( V_46 -> V_58 > V_60 ) {
V_40 = - V_61 ;
} else {
V_46 -> V_60 = V_60 ;
V_46 -> V_50 = ( V_63 * V_60 ) / 100 ;
}
F_38 ( & V_59 ) ;
return V_40 ;
}
static unsigned long F_40 ( unsigned long V_64 ,
unsigned long V_65 )
{
return ( V_64 + V_65 ) / 2 ;
}
static unsigned long F_41 ( unsigned long V_64 )
{
return F_42 ( V_64 , V_66 ) ;
}
unsigned long F_43 ( struct V_45 * V_46 , unsigned long V_18 )
{
T_4 V_67 ;
long V_54 , V_55 ;
F_32 ( V_46 , & V_54 , & V_55 ) ;
V_67 = ( V_18 * ( 100 - V_62 ) ) / 100 ;
V_67 *= V_54 ;
F_44 ( V_67 , V_55 ) ;
V_67 += ( V_18 * V_46 -> V_58 ) / 100 ;
if ( V_67 > ( V_18 * V_46 -> V_60 ) / 100 )
V_67 = V_18 * V_46 -> V_60 / 100 ;
return V_67 ;
}
static long long F_45 ( unsigned long V_68 ,
unsigned long V_18 ,
unsigned long V_30 )
{
long long V_69 ;
long V_9 ;
V_9 = F_46 ( ( ( V_70 ) V_68 - ( V_70 ) V_18 ) << V_71 ,
V_30 - V_68 + 1 ) ;
V_69 = V_9 ;
V_69 = V_69 * V_9 >> V_71 ;
V_69 = V_69 * V_9 >> V_71 ;
V_69 += 1 << V_71 ;
return F_47 ( V_69 , 0LL , 2LL << V_71 ) ;
}
static unsigned long F_48 ( struct V_45 * V_46 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_18 ,
unsigned long V_72 ,
unsigned long V_67 )
{
unsigned long V_73 = V_46 -> V_74 ;
unsigned long V_75 = F_40 ( V_64 , V_65 ) ;
unsigned long V_30 = F_41 ( V_64 ) ;
unsigned long V_76 ;
unsigned long V_68 ;
unsigned long V_77 ;
unsigned long V_78 ;
long long V_69 ;
long V_9 ;
if ( F_27 ( V_18 >= V_30 ) )
return 0 ;
V_68 = ( V_75 + V_30 ) / 2 ;
V_69 = F_45 ( V_68 , V_18 , V_30 ) ;
if ( F_27 ( V_46 -> V_79 & V_80 ) ) {
long long V_81 ;
unsigned long V_82 ;
if ( V_67 < 8 )
return F_49 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
if ( V_67 >= V_72 )
return 0 ;
V_82 = F_50 ( ( T_4 ) V_72 * V_65 , V_64 ) ;
V_77 = F_40 ( V_72 ,
V_82 ) ;
if ( V_77 == 0 || V_77 == V_72 )
return 0 ;
V_81 = F_45 ( V_77 , V_67 ,
V_72 ) ;
return F_3 ( V_69 , V_81 ) ;
}
if ( F_27 ( V_72 > V_64 ) )
V_72 = V_64 ;
V_72 = F_42 ( V_72 , ( V_30 - V_18 ) / 8 ) ;
V_9 = F_50 ( ( T_4 ) V_72 << 16 , V_64 + 1 ) ;
V_77 = V_68 * ( T_4 ) V_9 >> 16 ;
V_78 = ( V_64 - V_72 + 8 * V_73 ) * ( T_4 ) V_9 >> 16 ;
V_76 = V_77 + V_78 ;
if ( V_67 < V_76 - V_78 / 4 ) {
V_69 = F_51 ( V_69 * ( V_76 - V_67 ) ,
V_76 - V_77 + 1 ) ;
} else
V_69 /= 4 ;
V_76 = V_72 / 2 ;
if ( V_67 < V_76 ) {
if ( V_67 > V_76 / 8 )
V_69 = F_50 ( V_69 * V_76 , V_67 ) ;
else
V_69 *= 8 ;
}
return V_69 ;
}
static void F_52 ( struct V_45 * V_46 ,
unsigned long V_83 ,
unsigned long V_84 )
{
const unsigned long V_85 = F_53 ( 3 * V_86 ) ;
unsigned long V_87 = V_46 -> V_74 ;
unsigned long V_88 = V_46 -> V_89 ;
T_4 V_90 ;
V_90 = V_84 - V_46 -> V_91 ;
V_90 *= V_86 ;
if ( F_27 ( V_83 > V_85 ) ) {
F_44 ( V_90 , V_83 ) ;
V_87 = V_90 ;
goto V_92;
}
V_90 += ( T_4 ) V_46 -> V_89 * ( V_85 - V_83 ) ;
V_90 >>= F_54 ( V_85 ) ;
if ( V_87 > V_88 && V_88 >= ( unsigned long ) V_90 )
V_87 -= ( V_87 - V_88 ) >> 3 ;
if ( V_87 < V_88 && V_88 <= ( unsigned long ) V_90 )
V_87 += ( V_88 - V_87 ) >> 3 ;
V_92:
V_46 -> V_89 = V_90 ;
V_46 -> V_74 = V_87 ;
}
static void F_55 ( unsigned long V_64 , unsigned long V_18 )
{
unsigned long V_30 = V_66 ;
if ( V_30 < V_64 ) {
V_30 = V_64 ;
goto V_93;
}
V_64 = F_42 ( V_64 , V_18 ) ;
if ( V_30 > V_64 ) {
V_30 -= ( V_30 - V_64 ) >> 5 ;
goto V_93;
}
return;
V_93:
V_66 = V_30 ;
}
static void F_56 ( unsigned long V_64 ,
unsigned long V_18 ,
unsigned long V_94 )
{
static F_57 ( V_95 ) ;
static unsigned long V_96 ;
if ( F_58 ( V_94 , V_96 + V_97 ) )
return;
F_59 ( & V_95 ) ;
if ( F_60 ( V_94 , V_96 + V_97 ) ) {
F_55 ( V_64 , V_18 ) ;
V_96 = V_94 ;
}
F_61 ( & V_95 ) ;
}
static void F_62 ( struct V_45 * V_46 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_18 ,
unsigned long V_72 ,
unsigned long V_67 ,
unsigned long V_98 ,
unsigned long V_83 )
{
unsigned long V_75 = F_40 ( V_64 , V_65 ) ;
unsigned long V_30 = F_41 ( V_64 ) ;
unsigned long V_68 = ( V_75 + V_30 ) / 2 ;
unsigned long V_73 = V_46 -> V_74 ;
unsigned long V_99 = V_46 -> V_99 ;
unsigned long V_100 ;
unsigned long V_101 ;
unsigned long V_102 ;
unsigned long V_69 ;
unsigned long V_103 ;
unsigned long V_9 ;
V_100 = ( V_98 - V_46 -> V_104 ) * V_86 / V_83 ;
V_69 = F_48 ( V_46 , V_64 , V_65 , V_18 ,
V_72 , V_67 ) ;
V_101 = ( T_4 ) V_99 *
V_69 >> V_71 ;
V_101 ++ ;
V_102 = F_50 ( ( T_4 ) V_101 * V_73 ,
V_100 | 1 ) ;
if ( F_27 ( V_102 > V_73 ) )
V_102 = V_73 ;
V_103 = 0 ;
if ( F_27 ( V_46 -> V_79 & V_80 ) ) {
V_18 = V_67 ;
if ( V_67 < 8 )
V_68 = V_67 + 1 ;
else
V_68 = ( V_72 +
F_43 ( V_46 , V_65 ) ) / 2 ;
}
if ( V_18 < V_68 ) {
V_9 = F_3 ( V_46 -> V_102 ,
F_3 ( V_102 , V_101 ) ) ;
if ( V_99 < V_9 )
V_103 = V_9 - V_99 ;
} else {
V_9 = F_42 ( V_46 -> V_102 ,
F_42 ( V_102 , V_101 ) ) ;
if ( V_99 > V_9 )
V_103 = V_99 - V_9 ;
}
V_103 >>= V_99 / ( 2 * V_103 + 1 ) ;
V_103 = ( V_103 + 7 ) / 8 ;
if ( V_99 < V_102 )
V_99 += V_103 ;
else
V_99 -= V_103 ;
V_46 -> V_99 = F_42 ( V_99 , 1UL ) ;
V_46 -> V_102 = V_102 ;
F_63 ( V_46 , V_100 , V_101 ) ;
}
void F_64 ( struct V_45 * V_46 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_18 ,
unsigned long V_72 ,
unsigned long V_67 ,
unsigned long V_105 )
{
unsigned long V_94 = V_52 ;
unsigned long V_83 = V_94 - V_46 -> V_106 ;
unsigned long V_98 ;
unsigned long V_84 ;
if ( V_83 < V_97 )
return;
V_98 = F_65 ( & V_46 -> V_107 [ V_108 ] ) ;
V_84 = F_65 ( & V_46 -> V_107 [ V_47 ] ) ;
if ( V_83 > V_86 && F_58 ( V_46 -> V_106 , V_105 ) )
goto V_109;
if ( V_64 ) {
F_56 ( V_64 , V_18 , V_94 ) ;
F_62 ( V_46 , V_64 , V_65 , V_18 ,
V_72 , V_67 ,
V_98 , V_83 ) ;
}
F_52 ( V_46 , V_83 , V_84 ) ;
V_109:
V_46 -> V_104 = V_98 ;
V_46 -> V_91 = V_84 ;
V_46 -> V_106 = V_94 ;
}
static void F_66 ( struct V_45 * V_46 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_18 ,
unsigned long V_72 ,
unsigned long V_67 ,
unsigned long V_105 )
{
if ( F_67 ( V_46 -> V_106 + V_97 ) )
return;
F_59 ( & V_46 -> V_110 . V_111 ) ;
F_64 ( V_46 , V_64 , V_65 , V_18 ,
V_72 , V_67 , V_105 ) ;
F_61 ( & V_46 -> V_110 . V_111 ) ;
}
static unsigned long F_68 ( unsigned long V_18 ,
unsigned long V_64 )
{
if ( V_64 > V_18 )
return 1UL << ( F_54 ( V_64 - V_18 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_69 ( struct V_45 * V_46 ,
unsigned long V_67 )
{
unsigned long V_90 = V_46 -> V_74 ;
unsigned long V_56 ;
V_56 = V_67 / ( 1 + V_90 / F_53 ( 1 + V_86 / 8 ) ) ;
V_56 ++ ;
return F_49 (unsigned long, t, MAX_PAUSE) ;
}
static long F_70 ( struct V_45 * V_46 ,
long V_112 ,
unsigned long V_101 ,
unsigned long V_99 ,
int * V_113 )
{
long V_114 = F_54 ( V_46 -> V_74 ) ;
long V_115 = F_54 ( V_46 -> V_99 ) ;
long V_56 ;
long V_116 ;
int V_117 ;
V_56 = F_42 ( 1 , V_86 / 100 ) ;
if ( V_114 > V_115 )
V_56 += ( V_114 - V_115 ) * ( 10 * V_86 ) / 1024 ;
V_56 = F_3 ( V_56 , 1 + V_112 / 2 ) ;
V_117 = V_99 * V_56 / F_53 ( V_86 ) ;
if ( V_117 < V_118 ) {
V_56 = V_112 ;
V_117 = V_99 * V_56 / F_53 ( V_86 ) ;
if ( V_117 > V_118 ) {
V_117 = V_118 ;
V_56 = V_86 * V_118 / V_99 ;
}
}
V_116 = V_86 * V_117 / ( V_101 + 1 ) ;
if ( V_116 > V_112 ) {
V_56 = V_112 ;
V_117 = V_101 * V_56 / F_53 ( V_86 ) ;
}
* V_113 = V_117 ;
return V_117 >= V_118 ? 1 + V_56 / 2 : V_56 ;
}
static inline void F_71 ( struct V_45 * V_46 ,
unsigned long V_119 ,
unsigned long V_120 ,
unsigned long * V_67 ,
unsigned long * V_72 ,
unsigned long * V_82 )
{
unsigned long V_121 ;
* V_72 = F_43 ( V_46 , V_119 ) ;
if ( V_82 )
* V_82 = V_119 ? F_50 ( ( T_4 ) * V_72 *
V_120 ,
V_119 ) : 0 ;
if ( * V_72 < 2 * F_72 ( V_46 ) ) {
V_121 = F_73 ( V_46 , V_122 ) ;
* V_67 = V_121 +
F_73 ( V_46 , V_123 ) ;
} else {
V_121 = V_107 ( V_46 , V_122 ) ;
* V_67 = V_121 +
V_107 ( V_46 , V_123 ) ;
}
}
static void F_74 ( struct V_124 * V_125 ,
unsigned long V_126 )
{
unsigned long V_127 ;
unsigned long V_128 ;
unsigned long V_120 ;
unsigned long V_119 ;
long V_85 ;
long V_116 ;
long V_112 ;
long V_129 ;
int V_113 ;
bool V_130 = false ;
unsigned long V_101 ;
unsigned long V_99 ;
unsigned long V_69 ;
struct V_45 * V_46 = V_125 -> V_45 ;
bool V_131 = V_46 -> V_79 & V_80 ;
unsigned long V_105 = V_52 ;
for (; ; ) {
unsigned long V_94 = V_52 ;
unsigned long V_132 ( V_72 ) ;
unsigned long V_64 ;
unsigned long V_132 ( V_67 ) ;
unsigned long V_18 ;
unsigned long V_65 ;
V_127 = F_9 ( V_31 ) +
F_9 ( V_32 ) ;
V_128 = V_127 + F_9 ( V_33 ) ;
F_10 ( & V_120 , & V_119 ) ;
if ( F_27 ( V_131 ) ) {
F_71 ( V_46 , V_119 , V_120 ,
& V_67 , & V_72 , & V_65 ) ;
V_18 = V_67 ;
V_64 = V_72 ;
} else {
V_18 = V_128 ;
V_64 = V_119 ;
V_65 = V_120 ;
}
if ( V_18 <= F_40 ( V_64 , V_65 ) ) {
V_26 -> V_133 = V_94 ;
V_26 -> V_134 = 0 ;
V_26 -> V_113 =
F_68 ( V_18 , V_64 ) ;
break;
}
if ( F_27 ( ! F_75 ( V_46 ) ) )
F_76 ( V_46 ) ;
if ( ! V_131 )
F_71 ( V_46 , V_119 , V_120 ,
& V_67 , & V_72 , NULL ) ;
V_130 = ( V_67 > V_72 ) &&
( ( V_128 > V_119 ) || V_131 ) ;
if ( V_130 && ! V_46 -> V_130 )
V_46 -> V_130 = 1 ;
F_66 ( V_46 , V_119 , V_120 ,
V_128 , V_72 , V_67 ,
V_105 ) ;
V_99 = V_46 -> V_99 ;
V_69 = F_48 ( V_46 , V_119 ,
V_120 , V_128 ,
V_72 , V_67 ) ;
V_101 = ( ( T_4 ) V_99 * V_69 ) >>
V_71 ;
V_112 = F_69 ( V_46 , V_67 ) ;
V_129 = F_70 ( V_46 , V_112 ,
V_101 , V_99 ,
& V_113 ) ;
if ( F_27 ( V_101 == 0 ) ) {
V_85 = V_112 ;
V_116 = V_112 ;
goto V_116;
}
V_85 = V_86 * V_126 / V_101 ;
V_116 = V_85 ;
if ( V_26 -> V_133 )
V_116 -= V_94 - V_26 -> V_133 ;
if ( V_116 < V_129 ) {
F_77 ( V_46 ,
V_119 ,
V_120 ,
V_128 ,
V_72 ,
V_67 ,
V_99 ,
V_101 ,
V_126 ,
V_85 ,
F_3 ( V_116 , 0L ) ,
V_105 ) ;
if ( V_116 < - V_86 ) {
V_26 -> V_133 = V_94 ;
V_26 -> V_134 = 0 ;
} else if ( V_85 ) {
V_26 -> V_133 += V_85 ;
V_26 -> V_134 = 0 ;
} else if ( V_26 -> V_113 <= V_126 )
V_26 -> V_113 += V_126 ;
break;
}
if ( F_27 ( V_116 > V_112 ) ) {
V_94 += F_3 ( V_116 - V_112 , V_112 ) ;
V_116 = V_112 ;
}
V_116:
F_77 ( V_46 ,
V_119 ,
V_120 ,
V_128 ,
V_72 ,
V_67 ,
V_99 ,
V_101 ,
V_126 ,
V_85 ,
V_116 ,
V_105 ) ;
F_78 ( V_135 ) ;
F_79 ( V_116 ) ;
V_26 -> V_133 = V_94 + V_116 ;
V_26 -> V_134 = 0 ;
V_26 -> V_113 = V_113 ;
if ( V_101 )
break;
if ( V_67 <= F_72 ( V_46 ) )
break;
if ( F_80 ( V_26 ) )
break;
}
if ( ! V_130 && V_46 -> V_130 )
V_46 -> V_130 = 0 ;
if ( F_75 ( V_46 ) )
return;
if ( V_136 )
return;
if ( V_127 > V_120 )
F_76 ( V_46 ) ;
}
void F_81 ( struct V_137 * V_137 )
{
if ( F_82 ( V_137 ) ) {
struct V_124 * V_125 = F_83 ( V_137 ) ;
if ( V_125 )
F_84 ( V_125 ) ;
}
}
void F_84 ( struct V_124 * V_125 )
{
struct V_45 * V_46 = V_125 -> V_45 ;
int V_138 ;
int * V_139 ;
if ( ! F_85 ( V_46 ) )
return;
V_138 = V_26 -> V_113 ;
if ( V_46 -> V_130 )
V_138 = F_3 ( V_138 , 32 >> ( V_140 - 10 ) ) ;
F_86 () ;
V_139 = F_87 ( & V_141 ) ;
if ( F_27 ( V_26 -> V_134 >= V_138 ) )
* V_139 = 0 ;
else if ( F_27 ( * V_139 >= V_142 ) ) {
* V_139 = 0 ;
V_138 = 0 ;
}
V_139 = F_87 ( & V_143 ) ;
if ( * V_139 > 0 && V_26 -> V_134 < V_138 ) {
unsigned long V_144 ;
V_144 = F_3 ( * V_139 , V_138 - V_26 -> V_134 ) ;
* V_139 -= V_144 ;
V_26 -> V_134 += V_144 ;
}
F_88 () ;
if ( F_27 ( V_26 -> V_134 >= V_138 ) )
F_74 ( V_125 , V_26 -> V_134 ) ;
}
void F_89 ( T_5 V_145 )
{
unsigned long V_120 ;
unsigned long V_119 ;
for ( ; ; ) {
F_10 ( & V_120 , & V_119 ) ;
V_119 = F_41 ( V_119 ) ;
V_119 += V_119 / 10 ;
if ( F_9 ( V_32 ) +
F_9 ( V_33 ) <= V_119 )
break;
F_90 ( V_146 , V_86 / 10 ) ;
if ( ( V_145 & ( V_147 | V_148 ) ) != ( V_147 | V_148 ) )
break;
}
}
int F_91 ( struct V_34 * V_35 , int V_36 ,
void T_1 * V_37 , T_2 * V_149 , T_3 * V_39 )
{
F_92 ( V_35 , V_36 , V_37 , V_149 , V_39 ) ;
return 0 ;
}
void F_93 ( unsigned long V_150 )
{
struct V_151 * V_152 = (struct V_151 * ) V_150 ;
int V_2 = F_9 ( V_31 ) +
F_9 ( V_32 ) ;
if ( F_94 ( & V_152 -> V_45 ) )
F_95 ( & V_152 -> V_45 , V_2 ,
V_153 ) ;
}
void F_96 ( struct V_45 * V_154 )
{
F_28 ( & V_154 -> V_155 , V_52 + V_136 ) ;
}
void F_97 ( void )
{
struct V_45 * V_46 ;
F_98 () ;
F_99 (bdi, &bdi_list, bdi_list)
F_100 ( & V_46 -> V_155 ) ;
F_101 () ;
}
void F_21 ( void )
{
unsigned long V_120 ;
unsigned long V_119 ;
F_10 ( & V_120 , & V_119 ) ;
V_66 = V_119 ;
V_142 = V_119 / ( F_102 () * 32 ) ;
if ( V_142 < 16 )
V_142 = 16 ;
}
static int
F_103 ( struct V_156 * V_157 , unsigned long V_158 ,
void * V_159 )
{
switch ( V_158 & ~ V_160 ) {
case V_161 :
case V_162 :
F_21 () ;
return V_163 ;
default:
return V_164 ;
}
}
void T_6 F_104 ( void )
{
F_21 () ;
F_105 ( & V_165 ) ;
F_106 ( & V_48 ) ;
}
void F_107 ( struct V_124 * V_125 ,
T_7 V_166 , T_7 V_167 )
{
#define F_108 4096
unsigned long V_168 ;
do {
F_109 ( & V_125 -> V_169 ) ;
V_168 = F_110 ( & V_125 -> V_170 ,
& V_166 , V_167 , F_108 ,
V_171 , V_172 ) ;
F_111 ( & V_125 -> V_169 ) ;
F_112 ( V_168 > F_108 ) ;
F_113 () ;
} while ( V_168 >= F_108 && V_166 );
}
int F_114 ( struct V_124 * V_125 ,
struct V_173 * V_174 , T_8 V_175 ,
void * V_150 )
{
int V_40 = 0 ;
int V_176 = 0 ;
struct V_177 V_178 ;
int V_2 ;
T_7 V_132 ( V_179 ) ;
T_7 V_180 ;
T_7 V_167 ;
T_7 V_181 ;
int V_182 ;
int V_183 = 0 ;
int V_184 ;
F_115 ( & V_178 , 0 ) ;
if ( V_174 -> V_185 ) {
V_179 = V_125 -> V_179 ;
V_180 = V_179 ;
if ( V_180 == 0 )
V_182 = 1 ;
else
V_182 = 0 ;
V_167 = - 1 ;
} else {
V_180 = V_174 -> V_186 >> V_187 ;
V_167 = V_174 -> V_188 >> V_187 ;
if ( V_174 -> V_186 == 0 && V_174 -> V_188 == V_189 )
V_183 = 1 ;
V_182 = 1 ;
}
if ( V_174 -> V_190 == V_191 || V_174 -> V_192 )
V_184 = V_172 ;
else
V_184 = V_171 ;
V_193:
if ( V_174 -> V_190 == V_191 || V_174 -> V_192 )
F_107 ( V_125 , V_180 , V_167 ) ;
V_181 = V_180 ;
while ( ! V_176 && ( V_180 <= V_167 ) ) {
int V_194 ;
V_2 = F_116 ( & V_178 , V_125 , & V_180 , V_184 ,
F_3 ( V_167 - V_180 , ( T_7 ) V_195 - 1 ) + 1 ) ;
if ( V_2 == 0 )
break;
for ( V_194 = 0 ; V_194 < V_2 ; V_194 ++ ) {
struct V_137 * V_137 = V_178 . V_117 [ V_194 ] ;
if ( V_137 -> V_180 > V_167 ) {
V_176 = 1 ;
break;
}
V_181 = V_137 -> V_180 ;
F_117 ( V_137 ) ;
if ( F_27 ( V_137 -> V_125 != V_125 ) ) {
V_196:
F_118 ( V_137 ) ;
continue;
}
if ( ! F_119 ( V_137 ) ) {
goto V_196;
}
if ( F_120 ( V_137 ) ) {
if ( V_174 -> V_190 != V_197 )
F_121 ( V_137 ) ;
else
goto V_196;
}
F_122 ( F_120 ( V_137 ) ) ;
if ( ! F_123 ( V_137 ) )
goto V_196;
F_124 ( V_174 , V_125 -> V_45 ) ;
V_40 = (* V_175)( V_137 , V_174 , V_150 ) ;
if ( F_27 ( V_40 ) ) {
if ( V_40 == V_198 ) {
F_118 ( V_137 ) ;
V_40 = 0 ;
} else {
V_181 = V_137 -> V_180 + 1 ;
V_176 = 1 ;
break;
}
}
if ( -- V_174 -> V_199 <= 0 &&
V_174 -> V_190 == V_197 ) {
V_176 = 1 ;
break;
}
}
F_125 ( & V_178 ) ;
F_113 () ;
}
if ( ! V_182 && ! V_176 ) {
V_182 = 1 ;
V_180 = 0 ;
V_167 = V_179 - 1 ;
goto V_193;
}
if ( V_174 -> V_185 || ( V_183 && V_174 -> V_199 > 0 ) )
V_125 -> V_179 = V_181 ;
return V_40 ;
}
static int F_126 ( struct V_137 * V_137 , struct V_173 * V_174 ,
void * V_150 )
{
struct V_124 * V_125 = V_150 ;
int V_40 = V_125 -> V_200 -> V_175 ( V_137 , V_174 ) ;
F_127 ( V_125 , V_40 ) ;
return V_40 ;
}
int F_128 ( struct V_124 * V_125 ,
struct V_173 * V_174 )
{
struct V_201 V_202 ;
int V_40 ;
if ( ! V_125 -> V_200 -> V_175 )
return 0 ;
F_129 ( & V_202 ) ;
V_40 = F_114 ( V_125 , V_174 , F_126 , V_125 ) ;
F_130 ( & V_202 ) ;
return V_40 ;
}
int F_131 ( struct V_124 * V_125 , struct V_173 * V_174 )
{
int V_40 ;
if ( V_174 -> V_199 <= 0 )
return 0 ;
if ( V_125 -> V_200 -> V_203 )
V_40 = V_125 -> V_200 -> V_203 ( V_125 , V_174 ) ;
else
V_40 = F_128 ( V_125 , V_174 ) ;
return V_40 ;
}
int F_132 ( struct V_137 * V_137 , int V_204 )
{
struct V_124 * V_125 = V_137 -> V_125 ;
int V_40 = 0 ;
struct V_173 V_174 = {
. V_190 = V_191 ,
. V_199 = 1 ,
} ;
F_122 ( ! F_133 ( V_137 ) ) ;
if ( V_204 )
F_121 ( V_137 ) ;
if ( F_123 ( V_137 ) ) {
F_134 ( V_137 ) ;
V_40 = V_125 -> V_200 -> V_175 ( V_137 , & V_174 ) ;
if ( V_40 == 0 && V_204 ) {
F_121 ( V_137 ) ;
if ( F_135 ( V_137 ) )
V_40 = - V_205 ;
}
F_136 ( V_137 ) ;
} else {
F_118 ( V_137 ) ;
}
return V_40 ;
}
int F_137 ( struct V_137 * V_137 )
{
if ( ! F_119 ( V_137 ) )
return ! F_138 ( V_137 ) ;
return 0 ;
}
void F_139 ( struct V_137 * V_137 , struct V_124 * V_125 )
{
F_140 ( V_137 , V_125 ) ;
if ( F_141 ( V_125 ) ) {
F_142 ( V_137 , V_31 ) ;
F_142 ( V_137 , V_206 ) ;
F_25 ( V_125 -> V_45 , V_122 ) ;
F_25 ( V_125 -> V_45 , V_108 ) ;
F_143 ( V_207 ) ;
V_26 -> V_134 ++ ;
F_144 ( V_141 ) ;
}
}
void F_145 ( struct V_137 * V_137 )
{
F_146 ( V_137 , V_208 ) ;
F_147 ( V_137 , V_33 ) ;
}
int F_148 ( struct V_137 * V_137 )
{
if ( ! F_138 ( V_137 ) ) {
struct V_124 * V_125 = F_83 ( V_137 ) ;
struct V_124 * V_209 ;
unsigned long V_27 ;
if ( ! V_125 )
return 1 ;
F_149 ( & V_125 -> V_169 , V_27 ) ;
V_209 = F_83 ( V_137 ) ;
if ( V_209 ) {
F_122 ( V_209 != V_125 ) ;
F_112 ( ! F_150 ( V_137 ) && ! F_151 ( V_137 ) ) ;
F_139 ( V_137 , V_125 ) ;
F_152 ( & V_125 -> V_170 ,
F_153 ( V_137 ) , V_171 ) ;
}
F_154 ( & V_125 -> V_169 , V_27 ) ;
if ( V_125 -> V_210 ) {
F_155 ( V_125 -> V_210 , V_211 ) ;
}
return 1 ;
}
return 0 ;
}
void F_156 ( struct V_137 * V_137 )
{
struct V_124 * V_125 = V_137 -> V_125 ;
if ( V_125 && F_141 ( V_125 ) ) {
V_26 -> V_134 -- ;
F_157 ( V_137 , V_206 ) ;
F_158 ( V_125 -> V_45 , V_108 ) ;
}
}
int F_159 ( struct V_173 * V_174 , struct V_137 * V_137 )
{
V_174 -> V_212 ++ ;
F_156 ( V_137 ) ;
return F_148 ( V_137 ) ;
}
int F_82 ( struct V_137 * V_137 )
{
struct V_124 * V_125 = F_83 ( V_137 ) ;
if ( F_160 ( V_125 ) ) {
int (* F_161)( struct V_137 * ) = V_125 -> V_200 -> F_82 ;
F_162 ( V_137 ) ;
#ifdef F_163
if ( ! F_161 )
F_161 = V_213 ;
#endif
return (* F_161)( V_137 ) ;
}
if ( ! F_119 ( V_137 ) ) {
if ( ! F_138 ( V_137 ) )
return 1 ;
}
return 0 ;
}
int F_164 ( struct V_137 * V_137 )
{
int V_40 ;
F_117 ( V_137 ) ;
V_40 = F_82 ( V_137 ) ;
F_118 ( V_137 ) ;
return V_40 ;
}
int F_123 ( struct V_137 * V_137 )
{
struct V_124 * V_125 = F_83 ( V_137 ) ;
F_122 ( ! F_133 ( V_137 ) ) ;
if ( V_125 && F_141 ( V_125 ) ) {
if ( F_165 ( V_137 ) )
F_82 ( V_137 ) ;
if ( F_166 ( V_137 ) ) {
F_157 ( V_137 , V_31 ) ;
F_158 ( V_125 -> V_45 ,
V_122 ) ;
return 1 ;
}
return 0 ;
}
return F_166 ( V_137 ) ;
}
int F_167 ( struct V_137 * V_137 )
{
struct V_124 * V_125 = F_83 ( V_137 ) ;
int V_40 ;
bool V_214 ;
unsigned long V_215 ;
F_168 ( V_137 , & V_214 , & V_215 ) ;
if ( V_125 ) {
struct V_45 * V_46 = V_125 -> V_45 ;
unsigned long V_27 ;
F_149 ( & V_125 -> V_169 , V_27 ) ;
V_40 = F_169 ( V_137 ) ;
if ( V_40 ) {
F_170 ( & V_125 -> V_170 ,
F_153 ( V_137 ) ,
V_216 ) ;
if ( F_171 ( V_46 ) ) {
F_172 ( V_46 , V_123 ) ;
F_24 ( V_46 ) ;
}
}
F_154 ( & V_125 -> V_169 , V_27 ) ;
} else {
V_40 = F_169 ( V_137 ) ;
}
if ( V_40 ) {
F_173 ( V_137 , V_208 ) ;
F_157 ( V_137 , V_33 ) ;
F_147 ( V_137 , V_217 ) ;
}
F_174 ( V_137 , & V_214 , & V_215 ) ;
return V_40 ;
}
int F_175 ( struct V_137 * V_137 , bool V_218 )
{
struct V_124 * V_125 = F_83 ( V_137 ) ;
int V_40 ;
bool V_214 ;
unsigned long V_215 ;
F_168 ( V_137 , & V_214 , & V_215 ) ;
if ( V_125 ) {
struct V_45 * V_46 = V_125 -> V_45 ;
unsigned long V_27 ;
F_149 ( & V_125 -> V_169 , V_27 ) ;
V_40 = F_176 ( V_137 ) ;
if ( ! V_40 ) {
F_152 ( & V_125 -> V_170 ,
F_153 ( V_137 ) ,
V_216 ) ;
if ( F_171 ( V_46 ) )
F_25 ( V_46 , V_123 ) ;
}
if ( ! F_119 ( V_137 ) )
F_170 ( & V_125 -> V_170 ,
F_153 ( V_137 ) ,
V_171 ) ;
if ( ! V_218 )
F_170 ( & V_125 -> V_170 ,
F_153 ( V_137 ) ,
V_172 ) ;
F_154 ( & V_125 -> V_169 , V_27 ) ;
} else {
V_40 = F_176 ( V_137 ) ;
}
if ( ! V_40 )
F_145 ( V_137 ) ;
F_174 ( V_137 , & V_214 , & V_215 ) ;
return V_40 ;
}
int F_177 ( struct V_124 * V_125 , int V_184 )
{
return F_178 ( & V_125 -> V_170 , V_184 ) ;
}
void F_179 ( struct V_137 * V_137 )
{
struct V_124 * V_125 = F_83 ( V_137 ) ;
struct V_45 * V_46 = V_125 -> V_45 ;
if ( ! F_180 ( V_46 ) )
return;
F_121 ( V_137 ) ;
}
