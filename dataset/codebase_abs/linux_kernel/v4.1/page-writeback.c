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
( V_30 - V_68 ) | 1 ) ;
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
V_9 = F_50 ( ( T_4 ) V_72 << 16 , V_64 | 1 ) ;
V_77 = V_68 * ( T_4 ) V_9 >> 16 ;
V_78 = ( V_64 - V_72 + 8 * V_73 ) * ( T_4 ) V_9 >> 16 ;
V_76 = V_77 + V_78 ;
if ( V_67 < V_76 - V_78 / 4 ) {
V_69 = F_51 ( V_69 * ( V_76 - V_67 ) ,
( V_76 - V_77 ) | 1 ) ;
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
V_90 = V_84 - F_3 ( V_84 , V_46 -> V_91 ) ;
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
static unsigned long V_96 = V_97 ;
if ( F_58 ( V_94 , V_96 + V_98 ) )
return;
F_59 ( & V_95 ) ;
if ( F_60 ( V_94 , V_96 + V_98 ) ) {
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
unsigned long V_99 ,
unsigned long V_83 )
{
unsigned long V_75 = F_40 ( V_64 , V_65 ) ;
unsigned long V_30 = F_41 ( V_64 ) ;
unsigned long V_68 = ( V_75 + V_30 ) / 2 ;
unsigned long V_73 = V_46 -> V_74 ;
unsigned long V_100 = V_46 -> V_100 ;
unsigned long V_101 ;
unsigned long V_102 ;
unsigned long V_103 ;
unsigned long V_69 ;
unsigned long V_104 ;
unsigned long V_9 ;
V_101 = ( V_99 - V_46 -> V_105 ) * V_86 / V_83 ;
V_69 = F_48 ( V_46 , V_64 , V_65 , V_18 ,
V_72 , V_67 ) ;
V_102 = ( T_4 ) V_100 *
V_69 >> V_71 ;
V_102 ++ ;
V_103 = F_50 ( ( T_4 ) V_102 * V_73 ,
V_101 | 1 ) ;
if ( F_27 ( V_103 > V_73 ) )
V_103 = V_73 ;
V_104 = 0 ;
if ( F_27 ( V_46 -> V_79 & V_80 ) ) {
V_18 = V_67 ;
if ( V_67 < 8 )
V_68 = V_67 + 1 ;
else
V_68 = ( V_72 +
F_43 ( V_46 , V_65 ) ) / 2 ;
}
if ( V_18 < V_68 ) {
V_9 = F_63 ( V_46 -> V_103 ,
V_103 , V_102 ) ;
if ( V_100 < V_9 )
V_104 = V_9 - V_100 ;
} else {
V_9 = F_64 ( V_46 -> V_103 ,
V_103 , V_102 ) ;
if ( V_100 > V_9 )
V_104 = V_100 - V_9 ;
}
V_104 >>= V_100 / ( 2 * V_104 + 1 ) ;
V_104 = ( V_104 + 7 ) / 8 ;
if ( V_100 < V_103 )
V_100 += V_104 ;
else
V_100 -= V_104 ;
V_46 -> V_100 = F_42 ( V_100 , 1UL ) ;
V_46 -> V_103 = V_103 ;
F_65 ( V_46 , V_101 , V_102 ) ;
}
void F_66 ( struct V_45 * V_46 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_18 ,
unsigned long V_72 ,
unsigned long V_67 ,
unsigned long V_106 )
{
unsigned long V_94 = V_52 ;
unsigned long V_83 = V_94 - V_46 -> V_107 ;
unsigned long V_99 ;
unsigned long V_84 ;
if ( V_83 < V_98 )
return;
V_99 = F_67 ( & V_46 -> V_108 [ V_109 ] ) ;
V_84 = F_67 ( & V_46 -> V_108 [ V_47 ] ) ;
if ( V_83 > V_86 && F_58 ( V_46 -> V_107 , V_106 ) )
goto V_110;
if ( V_64 ) {
F_56 ( V_64 , V_18 , V_94 ) ;
F_62 ( V_46 , V_64 , V_65 , V_18 ,
V_72 , V_67 ,
V_99 , V_83 ) ;
}
F_52 ( V_46 , V_83 , V_84 ) ;
V_110:
V_46 -> V_105 = V_99 ;
V_46 -> V_91 = V_84 ;
V_46 -> V_107 = V_94 ;
}
static void F_68 ( struct V_45 * V_46 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_18 ,
unsigned long V_72 ,
unsigned long V_67 ,
unsigned long V_106 )
{
if ( F_69 ( V_46 -> V_107 + V_98 ) )
return;
F_59 ( & V_46 -> V_111 . V_112 ) ;
F_66 ( V_46 , V_64 , V_65 , V_18 ,
V_72 , V_67 , V_106 ) ;
F_61 ( & V_46 -> V_111 . V_112 ) ;
}
static unsigned long F_70 ( unsigned long V_18 ,
unsigned long V_64 )
{
if ( V_64 > V_18 )
return 1UL << ( F_54 ( V_64 - V_18 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_71 ( struct V_45 * V_46 ,
unsigned long V_67 )
{
unsigned long V_90 = V_46 -> V_74 ;
unsigned long V_56 ;
V_56 = V_67 / ( 1 + V_90 / F_53 ( 1 + V_86 / 8 ) ) ;
V_56 ++ ;
return F_49 (unsigned long, t, MAX_PAUSE) ;
}
static long F_72 ( struct V_45 * V_46 ,
long V_113 ,
unsigned long V_102 ,
unsigned long V_100 ,
int * V_114 )
{
long V_115 = F_54 ( V_46 -> V_74 ) ;
long V_116 = F_54 ( V_46 -> V_100 ) ;
long V_56 ;
long V_117 ;
int V_118 ;
V_56 = F_42 ( 1 , V_86 / 100 ) ;
if ( V_115 > V_116 )
V_56 += ( V_115 - V_116 ) * ( 10 * V_86 ) / 1024 ;
V_56 = F_3 ( V_56 , 1 + V_113 / 2 ) ;
V_118 = V_100 * V_56 / F_53 ( V_86 ) ;
if ( V_118 < V_119 ) {
V_56 = V_113 ;
V_118 = V_100 * V_56 / F_53 ( V_86 ) ;
if ( V_118 > V_119 ) {
V_118 = V_119 ;
V_56 = V_86 * V_119 / V_100 ;
}
}
V_117 = V_86 * V_118 / ( V_102 + 1 ) ;
if ( V_117 > V_113 ) {
V_56 = V_113 ;
V_118 = V_102 * V_56 / F_53 ( V_86 ) ;
}
* V_114 = V_118 ;
return V_118 >= V_119 ? 1 + V_56 / 2 : V_56 ;
}
static inline void F_73 ( struct V_45 * V_46 ,
unsigned long V_120 ,
unsigned long V_121 ,
unsigned long * V_67 ,
unsigned long * V_72 ,
unsigned long * V_82 )
{
unsigned long V_122 ;
* V_72 = F_43 ( V_46 , V_120 ) ;
if ( V_82 )
* V_82 = V_120 ? F_50 ( ( T_4 ) * V_72 *
V_121 ,
V_120 ) : 0 ;
if ( * V_72 < 2 * F_74 ( V_46 ) ) {
V_122 = F_75 ( V_46 , V_123 ) ;
* V_67 = V_122 +
F_75 ( V_46 , V_124 ) ;
} else {
V_122 = V_108 ( V_46 , V_123 ) ;
* V_67 = V_122 +
V_108 ( V_46 , V_124 ) ;
}
}
static void F_76 ( struct V_125 * V_126 ,
unsigned long V_127 )
{
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_121 ;
unsigned long V_120 ;
long V_85 ;
long V_117 ;
long V_113 ;
long V_130 ;
int V_114 ;
bool V_131 = false ;
unsigned long V_102 ;
unsigned long V_100 ;
unsigned long V_69 ;
struct V_45 * V_46 = F_77 ( V_126 -> V_132 ) ;
bool V_133 = V_46 -> V_79 & V_80 ;
unsigned long V_106 = V_52 ;
for (; ; ) {
unsigned long V_94 = V_52 ;
unsigned long V_134 ( V_72 ) ;
unsigned long V_64 ;
unsigned long V_134 ( V_67 ) ;
unsigned long V_18 ;
unsigned long V_65 ;
V_128 = F_9 ( V_31 ) +
F_9 ( V_32 ) ;
V_129 = V_128 + F_9 ( V_33 ) ;
F_10 ( & V_121 , & V_120 ) ;
if ( F_27 ( V_133 ) ) {
F_73 ( V_46 , V_120 , V_121 ,
& V_67 , & V_72 , & V_65 ) ;
V_18 = V_67 ;
V_64 = V_72 ;
} else {
V_18 = V_129 ;
V_64 = V_120 ;
V_65 = V_121 ;
}
if ( V_18 <= F_40 ( V_64 , V_65 ) ) {
V_26 -> V_135 = V_94 ;
V_26 -> V_136 = 0 ;
V_26 -> V_114 =
F_70 ( V_18 , V_64 ) ;
break;
}
if ( F_27 ( ! F_78 ( V_46 ) ) )
F_79 ( V_46 ) ;
if ( ! V_133 )
F_73 ( V_46 , V_120 , V_121 ,
& V_67 , & V_72 , NULL ) ;
V_131 = ( V_67 > V_72 ) &&
( ( V_129 > V_120 ) || V_133 ) ;
if ( V_131 && ! V_46 -> V_131 )
V_46 -> V_131 = 1 ;
F_68 ( V_46 , V_120 , V_121 ,
V_129 , V_72 , V_67 ,
V_106 ) ;
V_100 = V_46 -> V_100 ;
V_69 = F_48 ( V_46 , V_120 ,
V_121 , V_129 ,
V_72 , V_67 ) ;
V_102 = ( ( T_4 ) V_100 * V_69 ) >>
V_71 ;
V_113 = F_71 ( V_46 , V_67 ) ;
V_130 = F_72 ( V_46 , V_113 ,
V_102 , V_100 ,
& V_114 ) ;
if ( F_27 ( V_102 == 0 ) ) {
V_85 = V_113 ;
V_117 = V_113 ;
goto V_117;
}
V_85 = V_86 * V_127 / V_102 ;
V_117 = V_85 ;
if ( V_26 -> V_135 )
V_117 -= V_94 - V_26 -> V_135 ;
if ( V_117 < V_130 ) {
F_80 ( V_46 ,
V_120 ,
V_121 ,
V_129 ,
V_72 ,
V_67 ,
V_100 ,
V_102 ,
V_127 ,
V_85 ,
F_3 ( V_117 , 0L ) ,
V_106 ) ;
if ( V_117 < - V_86 ) {
V_26 -> V_135 = V_94 ;
V_26 -> V_136 = 0 ;
} else if ( V_85 ) {
V_26 -> V_135 += V_85 ;
V_26 -> V_136 = 0 ;
} else if ( V_26 -> V_114 <= V_127 )
V_26 -> V_114 += V_127 ;
break;
}
if ( F_27 ( V_117 > V_113 ) ) {
V_94 += F_3 ( V_117 - V_113 , V_113 ) ;
V_117 = V_113 ;
}
V_117:
F_80 ( V_46 ,
V_120 ,
V_121 ,
V_129 ,
V_72 ,
V_67 ,
V_100 ,
V_102 ,
V_127 ,
V_85 ,
V_117 ,
V_106 ) ;
F_81 ( V_137 ) ;
F_82 ( V_117 ) ;
V_26 -> V_135 = V_94 + V_117 ;
V_26 -> V_136 = 0 ;
V_26 -> V_114 = V_114 ;
if ( V_102 )
break;
if ( V_67 <= F_74 ( V_46 ) )
break;
if ( F_83 ( V_26 ) )
break;
}
if ( ! V_131 && V_46 -> V_131 )
V_46 -> V_131 = 0 ;
if ( F_78 ( V_46 ) )
return;
if ( V_138 )
return;
if ( V_128 > V_121 )
F_79 ( V_46 ) ;
}
void F_84 ( struct V_125 * V_126 )
{
struct V_45 * V_46 = F_77 ( V_126 -> V_132 ) ;
int V_139 ;
int * V_140 ;
if ( ! F_85 ( V_46 ) )
return;
V_139 = V_26 -> V_114 ;
if ( V_46 -> V_131 )
V_139 = F_3 ( V_139 , 32 >> ( V_141 - 10 ) ) ;
F_86 () ;
V_140 = F_87 ( & V_142 ) ;
if ( F_27 ( V_26 -> V_136 >= V_139 ) )
* V_140 = 0 ;
else if ( F_27 ( * V_140 >= V_143 ) ) {
* V_140 = 0 ;
V_139 = 0 ;
}
V_140 = F_87 ( & V_144 ) ;
if ( * V_140 > 0 && V_26 -> V_136 < V_139 ) {
unsigned long V_145 ;
V_145 = F_3 ( * V_140 , V_139 - V_26 -> V_136 ) ;
* V_140 -= V_145 ;
V_26 -> V_136 += V_145 ;
}
F_88 () ;
if ( F_27 ( V_26 -> V_136 >= V_139 ) )
F_76 ( V_126 , V_26 -> V_136 ) ;
}
void F_89 ( T_5 V_146 )
{
unsigned long V_121 ;
unsigned long V_120 ;
for ( ; ; ) {
F_10 ( & V_121 , & V_120 ) ;
V_120 = F_41 ( V_120 ) ;
V_120 += V_120 / 10 ;
if ( F_9 ( V_32 ) +
F_9 ( V_33 ) <= V_120 )
break;
F_90 ( V_147 , V_86 / 10 ) ;
if ( ( V_146 & ( V_148 | V_149 ) ) != ( V_148 | V_149 ) )
break;
}
}
int F_91 ( struct V_34 * V_35 , int V_36 ,
void T_1 * V_37 , T_2 * V_150 , T_3 * V_39 )
{
F_92 ( V_35 , V_36 , V_37 , V_150 , V_39 ) ;
return 0 ;
}
void F_93 ( unsigned long V_151 )
{
struct V_152 * V_153 = (struct V_152 * ) V_151 ;
int V_2 = F_9 ( V_31 ) +
F_9 ( V_32 ) ;
if ( F_94 ( & V_153 -> V_45 ) )
F_95 ( & V_153 -> V_45 , V_2 ,
V_154 ) ;
}
void F_96 ( struct V_45 * V_155 )
{
F_28 ( & V_155 -> V_156 , V_52 + V_138 ) ;
}
void F_97 ( void )
{
struct V_45 * V_46 ;
F_98 () ;
F_99 (bdi, &bdi_list, bdi_list)
F_100 ( & V_46 -> V_156 ) ;
F_101 () ;
}
void F_21 ( void )
{
unsigned long V_121 ;
unsigned long V_120 ;
F_10 ( & V_121 , & V_120 ) ;
V_66 = V_120 ;
V_143 = V_120 / ( F_102 () * 32 ) ;
if ( V_143 < 16 )
V_143 = 16 ;
}
static int
F_103 ( struct V_157 * V_158 , unsigned long V_159 ,
void * V_160 )
{
switch ( V_159 & ~ V_161 ) {
case V_162 :
case V_163 :
F_21 () ;
return V_164 ;
default:
return V_165 ;
}
}
void T_6 F_104 ( void )
{
F_21 () ;
F_105 ( & V_166 ) ;
F_106 ( & V_48 , V_167 ) ;
}
void F_107 ( struct V_125 * V_126 ,
T_7 V_168 , T_7 V_169 )
{
#define F_108 4096
unsigned long V_170 ;
do {
F_109 ( & V_126 -> V_171 ) ;
V_170 = F_110 ( & V_126 -> V_172 ,
& V_168 , V_169 , F_108 ,
V_173 , V_174 ) ;
F_111 ( & V_126 -> V_171 ) ;
F_112 ( V_170 > F_108 ) ;
F_113 () ;
} while ( V_170 >= F_108 && V_168 );
}
int F_114 ( struct V_125 * V_126 ,
struct V_175 * V_176 , T_8 V_177 ,
void * V_151 )
{
int V_40 = 0 ;
int V_178 = 0 ;
struct V_179 V_180 ;
int V_2 ;
T_7 V_134 ( V_181 ) ;
T_7 V_182 ;
T_7 V_169 ;
T_7 V_183 ;
int V_184 ;
int V_185 = 0 ;
int V_186 ;
F_115 ( & V_180 , 0 ) ;
if ( V_176 -> V_187 ) {
V_181 = V_126 -> V_181 ;
V_182 = V_181 ;
if ( V_182 == 0 )
V_184 = 1 ;
else
V_184 = 0 ;
V_169 = - 1 ;
} else {
V_182 = V_176 -> V_188 >> V_189 ;
V_169 = V_176 -> V_190 >> V_189 ;
if ( V_176 -> V_188 == 0 && V_176 -> V_190 == V_191 )
V_185 = 1 ;
V_184 = 1 ;
}
if ( V_176 -> V_192 == V_193 || V_176 -> V_194 )
V_186 = V_174 ;
else
V_186 = V_173 ;
V_195:
if ( V_176 -> V_192 == V_193 || V_176 -> V_194 )
F_107 ( V_126 , V_182 , V_169 ) ;
V_183 = V_182 ;
while ( ! V_178 && ( V_182 <= V_169 ) ) {
int V_196 ;
V_2 = F_116 ( & V_180 , V_126 , & V_182 , V_186 ,
F_3 ( V_169 - V_182 , ( T_7 ) V_197 - 1 ) + 1 ) ;
if ( V_2 == 0 )
break;
for ( V_196 = 0 ; V_196 < V_2 ; V_196 ++ ) {
struct V_198 * V_198 = V_180 . V_118 [ V_196 ] ;
if ( V_198 -> V_182 > V_169 ) {
V_178 = 1 ;
break;
}
V_183 = V_198 -> V_182 ;
F_117 ( V_198 ) ;
if ( F_27 ( V_198 -> V_126 != V_126 ) ) {
V_199:
F_118 ( V_198 ) ;
continue;
}
if ( ! F_119 ( V_198 ) ) {
goto V_199;
}
if ( F_120 ( V_198 ) ) {
if ( V_176 -> V_192 != V_200 )
F_121 ( V_198 ) ;
else
goto V_199;
}
F_122 ( F_120 ( V_198 ) ) ;
if ( ! F_123 ( V_198 ) )
goto V_199;
F_124 ( V_176 , F_77 ( V_126 -> V_132 ) ) ;
V_40 = (* V_177)( V_198 , V_176 , V_151 ) ;
if ( F_27 ( V_40 ) ) {
if ( V_40 == V_201 ) {
F_118 ( V_198 ) ;
V_40 = 0 ;
} else {
V_183 = V_198 -> V_182 + 1 ;
V_178 = 1 ;
break;
}
}
if ( -- V_176 -> V_202 <= 0 &&
V_176 -> V_192 == V_200 ) {
V_178 = 1 ;
break;
}
}
F_125 ( & V_180 ) ;
F_113 () ;
}
if ( ! V_184 && ! V_178 ) {
V_184 = 1 ;
V_182 = 0 ;
V_169 = V_181 - 1 ;
goto V_195;
}
if ( V_176 -> V_187 || ( V_185 && V_176 -> V_202 > 0 ) )
V_126 -> V_181 = V_183 ;
return V_40 ;
}
static int F_126 ( struct V_198 * V_198 , struct V_175 * V_176 ,
void * V_151 )
{
struct V_125 * V_126 = V_151 ;
int V_40 = V_126 -> V_203 -> V_177 ( V_198 , V_176 ) ;
F_127 ( V_126 , V_40 ) ;
return V_40 ;
}
int F_128 ( struct V_125 * V_126 ,
struct V_175 * V_176 )
{
struct V_204 V_205 ;
int V_40 ;
if ( ! V_126 -> V_203 -> V_177 )
return 0 ;
F_129 ( & V_205 ) ;
V_40 = F_114 ( V_126 , V_176 , F_126 , V_126 ) ;
F_130 ( & V_205 ) ;
return V_40 ;
}
int F_131 ( struct V_125 * V_126 , struct V_175 * V_176 )
{
int V_40 ;
if ( V_176 -> V_202 <= 0 )
return 0 ;
if ( V_126 -> V_203 -> V_206 )
V_40 = V_126 -> V_203 -> V_206 ( V_126 , V_176 ) ;
else
V_40 = F_128 ( V_126 , V_176 ) ;
return V_40 ;
}
int F_132 ( struct V_198 * V_198 , int V_207 )
{
struct V_125 * V_126 = V_198 -> V_126 ;
int V_40 = 0 ;
struct V_175 V_176 = {
. V_192 = V_193 ,
. V_202 = 1 ,
} ;
F_122 ( ! F_133 ( V_198 ) ) ;
if ( V_207 )
F_121 ( V_198 ) ;
if ( F_123 ( V_198 ) ) {
F_134 ( V_198 ) ;
V_40 = V_126 -> V_203 -> V_177 ( V_198 , & V_176 ) ;
if ( V_40 == 0 && V_207 ) {
F_121 ( V_198 ) ;
if ( F_135 ( V_198 ) )
V_40 = - V_208 ;
}
F_136 ( V_198 ) ;
} else {
F_118 ( V_198 ) ;
}
return V_40 ;
}
int F_137 ( struct V_198 * V_198 )
{
if ( ! F_119 ( V_198 ) )
return ! F_138 ( V_198 ) ;
return 0 ;
}
void F_139 ( struct V_198 * V_198 , struct V_125 * V_126 )
{
F_140 ( V_198 , V_126 ) ;
if ( F_141 ( V_126 ) ) {
struct V_45 * V_46 = F_77 ( V_126 -> V_132 ) ;
F_142 ( V_198 , V_31 ) ;
F_142 ( V_198 , V_209 ) ;
F_25 ( V_46 , V_123 ) ;
F_25 ( V_46 , V_109 ) ;
F_143 ( V_210 ) ;
V_26 -> V_136 ++ ;
F_144 ( V_142 ) ;
}
}
void F_145 ( struct V_198 * V_198 , struct V_125 * V_126 )
{
if ( F_141 ( V_126 ) ) {
F_146 ( V_198 , V_31 ) ;
F_147 ( F_77 ( V_126 -> V_132 ) , V_123 ) ;
F_148 ( V_210 ) ;
}
}
int F_149 ( struct V_198 * V_198 )
{
if ( ! F_138 ( V_198 ) ) {
struct V_125 * V_126 = F_150 ( V_198 ) ;
unsigned long V_27 ;
if ( ! V_126 )
return 1 ;
F_151 ( & V_126 -> V_171 , V_27 ) ;
F_122 ( F_150 ( V_198 ) != V_126 ) ;
F_112 ( ! F_152 ( V_198 ) && ! F_153 ( V_198 ) ) ;
F_139 ( V_198 , V_126 ) ;
F_154 ( & V_126 -> V_172 , F_155 ( V_198 ) ,
V_173 ) ;
F_156 ( & V_126 -> V_171 , V_27 ) ;
if ( V_126 -> V_132 ) {
F_157 ( V_126 -> V_132 , V_211 ) ;
}
return 1 ;
}
return 0 ;
}
void F_158 ( struct V_198 * V_198 )
{
struct V_125 * V_126 = V_198 -> V_126 ;
if ( V_126 && F_141 ( V_126 ) ) {
V_26 -> V_136 -- ;
F_146 ( V_198 , V_209 ) ;
F_147 ( F_77 ( V_126 -> V_132 ) , V_109 ) ;
}
}
int F_159 ( struct V_175 * V_176 , struct V_198 * V_198 )
{
int V_40 ;
V_176 -> V_212 ++ ;
V_40 = F_149 ( V_198 ) ;
F_158 ( V_198 ) ;
return V_40 ;
}
int F_160 ( struct V_198 * V_198 )
{
struct V_125 * V_126 = F_150 ( V_198 ) ;
if ( F_161 ( V_126 ) ) {
int (* F_162)( struct V_198 * ) = V_126 -> V_203 -> F_160 ;
if ( F_163 ( V_198 ) )
F_164 ( V_198 ) ;
#ifdef F_165
if ( ! F_162 )
F_162 = V_213 ;
#endif
return (* F_162)( V_198 ) ;
}
if ( ! F_119 ( V_198 ) ) {
if ( ! F_138 ( V_198 ) )
return 1 ;
}
return 0 ;
}
int F_166 ( struct V_198 * V_198 )
{
int V_40 ;
F_117 ( V_198 ) ;
V_40 = F_160 ( V_198 ) ;
F_118 ( V_198 ) ;
return V_40 ;
}
int F_123 ( struct V_198 * V_198 )
{
struct V_125 * V_126 = F_150 ( V_198 ) ;
F_122 ( ! F_133 ( V_198 ) ) ;
if ( V_126 && F_141 ( V_126 ) ) {
if ( F_167 ( V_198 ) )
F_160 ( V_198 ) ;
if ( F_168 ( V_198 ) ) {
F_146 ( V_198 , V_31 ) ;
F_147 ( F_77 ( V_126 -> V_132 ) ,
V_123 ) ;
return 1 ;
}
return 0 ;
}
return F_168 ( V_198 ) ;
}
int F_169 ( struct V_198 * V_198 )
{
struct V_125 * V_126 = F_150 ( V_198 ) ;
struct V_214 * V_215 ;
int V_40 ;
V_215 = F_170 ( V_198 ) ;
if ( V_126 ) {
struct V_45 * V_46 = F_77 ( V_126 -> V_132 ) ;
unsigned long V_27 ;
F_151 ( & V_126 -> V_171 , V_27 ) ;
V_40 = F_171 ( V_198 ) ;
if ( V_40 ) {
F_172 ( & V_126 -> V_172 ,
F_155 ( V_198 ) ,
V_216 ) ;
if ( F_173 ( V_46 ) ) {
F_174 ( V_46 , V_124 ) ;
F_24 ( V_46 ) ;
}
}
F_156 ( & V_126 -> V_171 , V_27 ) ;
} else {
V_40 = F_171 ( V_198 ) ;
}
if ( V_40 ) {
F_175 ( V_215 , V_217 ) ;
F_146 ( V_198 , V_33 ) ;
F_176 ( V_198 , V_218 ) ;
}
F_177 ( V_215 ) ;
return V_40 ;
}
int F_178 ( struct V_198 * V_198 , bool V_219 )
{
struct V_125 * V_126 = F_150 ( V_198 ) ;
struct V_214 * V_215 ;
int V_40 ;
V_215 = F_170 ( V_198 ) ;
if ( V_126 ) {
struct V_45 * V_46 = F_77 ( V_126 -> V_132 ) ;
unsigned long V_27 ;
F_151 ( & V_126 -> V_171 , V_27 ) ;
V_40 = F_179 ( V_198 ) ;
if ( ! V_40 ) {
F_154 ( & V_126 -> V_172 ,
F_155 ( V_198 ) ,
V_216 ) ;
if ( F_173 ( V_46 ) )
F_25 ( V_46 , V_124 ) ;
}
if ( ! F_119 ( V_198 ) )
F_172 ( & V_126 -> V_172 ,
F_155 ( V_198 ) ,
V_173 ) ;
if ( ! V_219 )
F_172 ( & V_126 -> V_172 ,
F_155 ( V_198 ) ,
V_174 ) ;
F_156 ( & V_126 -> V_171 , V_27 ) ;
} else {
V_40 = F_179 ( V_198 ) ;
}
if ( ! V_40 ) {
F_180 ( V_215 , V_217 ) ;
F_176 ( V_198 , V_33 ) ;
}
F_177 ( V_215 ) ;
return V_40 ;
}
int F_181 ( struct V_125 * V_126 , int V_186 )
{
return F_182 ( & V_126 -> V_172 , V_186 ) ;
}
void F_183 ( struct V_198 * V_198 )
{
if ( F_184 ( F_77 ( V_198 -> V_126 -> V_132 ) ) )
F_121 ( V_198 ) ;
}
