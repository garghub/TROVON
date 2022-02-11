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
unsigned long V_16 ;
unsigned long V_17 ;
unsigned long V_18 ( V_19 ) ;
struct V_20 * V_21 ;
if ( ! V_22 || ! V_23 )
V_19 = F_8 () ;
if ( V_22 )
V_17 = F_11 ( V_22 , V_24 ) ;
else
V_17 = ( V_25 * V_19 ) / 100 ;
if ( V_23 )
V_16 = F_11 ( V_23 , V_24 ) ;
else
V_16 = ( V_26 * V_19 ) / 100 ;
if ( V_16 >= V_17 )
V_16 = V_17 / 2 ;
V_21 = V_27 ;
if ( V_21 -> V_28 & V_29 || F_12 ( V_21 ) ) {
V_16 += V_16 / 4 ;
V_17 += V_17 / 4 ;
}
* V_14 = V_16 ;
* V_15 = V_17 ;
F_13 ( V_16 , V_17 ) ;
}
static unsigned long F_14 ( struct V_1 * V_1 )
{
unsigned long V_30 = F_1 ( V_1 ) ;
struct V_20 * V_21 = V_27 ;
unsigned long V_17 ;
if ( V_22 )
V_17 = F_11 ( V_22 , V_24 ) *
V_30 / F_8 () ;
else
V_17 = V_25 * V_30 / 100 ;
if ( V_21 -> V_28 & V_29 || F_12 ( V_21 ) )
V_17 += V_17 / 4 ;
return V_17 ;
}
bool F_15 ( struct V_1 * V_1 )
{
unsigned long V_31 = F_14 ( V_1 ) ;
return F_2 ( V_1 , V_32 ) +
F_2 ( V_1 , V_33 ) +
F_2 ( V_1 , V_34 ) <= V_31 ;
}
int F_16 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
int V_41 ;
V_41 = F_17 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 )
V_23 = 0 ;
return V_41 ;
}
int F_18 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
int V_41 ;
V_41 = F_19 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 )
V_26 = 0 ;
return V_41 ;
}
int F_20 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
int V_42 = V_25 ;
int V_41 ;
V_41 = F_17 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 && V_25 != V_42 ) {
F_21 () ;
V_22 = 0 ;
}
return V_41 ;
}
int F_22 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
unsigned long V_43 = V_22 ;
int V_41 ;
V_41 = F_19 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 && V_22 != V_43 ) {
F_21 () ;
V_25 = 0 ;
}
return V_41 ;
}
static unsigned long F_23 ( unsigned long V_44 )
{
V_44 += V_45 ;
if ( ! V_44 )
return 1 ;
return V_44 ;
}
static inline void F_24 ( struct V_46 * V_47 )
{
F_25 ( V_47 , V_48 ) ;
F_26 ( & V_49 , & V_47 -> V_50 ,
V_47 -> V_51 ) ;
if ( ! F_27 ( V_52 ) ) {
V_52 = F_23 ( V_53 ) ;
F_28 ( & V_54 , V_52 ) ;
}
}
void F_29 ( struct V_46 * V_47 )
{
unsigned long V_28 ;
F_30 ( V_28 ) ;
F_24 ( V_47 ) ;
F_31 ( V_28 ) ;
}
static void F_32 ( struct V_46 * V_47 ,
long * V_55 , long * V_56 )
{
F_33 ( & V_49 , & V_47 -> V_50 ,
V_55 , V_56 ) ;
}
static void F_34 ( unsigned long V_57 )
{
int V_58 = ( V_53 - V_52 ) /
V_45 ;
if ( F_35 ( & V_49 , V_58 + 1 ) ) {
V_52 = F_23 ( V_52 +
V_58 * V_45 ) ;
F_28 ( & V_54 , V_52 ) ;
} else {
V_52 = 0 ;
}
}
int F_36 ( struct V_46 * V_47 , unsigned int V_59 )
{
int V_41 = 0 ;
F_37 ( & V_60 ) ;
if ( V_59 > V_47 -> V_61 ) {
V_41 = - V_62 ;
} else {
V_59 -= V_47 -> V_59 ;
if ( V_63 + V_59 < 100 ) {
V_63 += V_59 ;
V_47 -> V_59 += V_59 ;
} else {
V_41 = - V_62 ;
}
}
F_38 ( & V_60 ) ;
return V_41 ;
}
int F_39 ( struct V_46 * V_47 , unsigned V_61 )
{
int V_41 = 0 ;
if ( V_61 > 100 )
return - V_62 ;
F_37 ( & V_60 ) ;
if ( V_47 -> V_59 > V_61 ) {
V_41 = - V_62 ;
} else {
V_47 -> V_61 = V_61 ;
V_47 -> V_51 = ( V_64 * V_61 ) / 100 ;
}
F_38 ( & V_60 ) ;
return V_41 ;
}
static unsigned long F_40 ( unsigned long V_65 ,
unsigned long V_66 )
{
return ( V_65 + V_66 ) / 2 ;
}
static unsigned long F_41 ( unsigned long V_65 )
{
return F_42 ( V_65 , V_67 ) ;
}
unsigned long F_43 ( struct V_46 * V_47 , unsigned long V_17 )
{
T_4 V_68 ;
long V_55 , V_56 ;
F_32 ( V_47 , & V_55 , & V_56 ) ;
V_68 = ( V_17 * ( 100 - V_63 ) ) / 100 ;
V_68 *= V_55 ;
F_44 ( V_68 , V_56 ) ;
V_68 += ( V_17 * V_47 -> V_59 ) / 100 ;
if ( V_68 > ( V_17 * V_47 -> V_61 ) / 100 )
V_68 = V_17 * V_47 -> V_61 / 100 ;
return V_68 ;
}
static inline long long F_45 ( unsigned long V_69 ,
unsigned long V_17 ,
unsigned long V_31 )
{
long long V_70 ;
long V_9 ;
V_9 = F_46 ( ( ( V_71 ) V_69 - ( V_71 ) V_17 ) << V_72 ,
V_31 - V_69 + 1 ) ;
V_70 = V_9 ;
V_70 = V_70 * V_9 >> V_72 ;
V_70 = V_70 * V_9 >> V_72 ;
V_70 += 1 << V_72 ;
return F_47 ( V_70 , 0LL , 2LL << V_72 ) ;
}
static unsigned long F_48 ( struct V_46 * V_47 ,
unsigned long V_65 ,
unsigned long V_66 ,
unsigned long V_17 ,
unsigned long V_73 ,
unsigned long V_68 )
{
unsigned long V_74 = V_47 -> V_75 ;
unsigned long V_76 = F_40 ( V_65 , V_66 ) ;
unsigned long V_31 = F_41 ( V_65 ) ;
unsigned long V_77 ;
unsigned long V_69 ;
unsigned long V_78 ;
unsigned long V_79 ;
long long V_70 ;
long V_9 ;
if ( F_27 ( V_17 >= V_31 ) )
return 0 ;
V_69 = ( V_76 + V_31 ) / 2 ;
V_70 = F_45 ( V_69 , V_17 , V_31 ) ;
if ( F_27 ( V_47 -> V_80 & V_81 ) ) {
long long V_82 ;
unsigned long V_83 ;
if ( V_68 < 8 )
return F_49 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
if ( V_68 >= V_73 )
return 0 ;
V_83 = F_50 ( ( T_4 ) V_73 * V_66 , V_65 ) ;
V_78 = F_40 ( V_73 ,
V_83 ) ;
if ( V_78 == 0 || V_78 == V_73 )
return 0 ;
V_82 = F_45 ( V_78 , V_68 ,
V_73 ) ;
return F_3 ( V_70 , V_82 ) ;
}
if ( F_27 ( V_73 > V_65 ) )
V_73 = V_65 ;
V_73 = F_42 ( V_73 , ( V_31 - V_17 ) / 8 ) ;
V_9 = F_50 ( ( T_4 ) V_73 << 16 , V_65 + 1 ) ;
V_78 = V_69 * ( T_4 ) V_9 >> 16 ;
V_79 = ( V_65 - V_73 + 8 * V_74 ) * ( T_4 ) V_9 >> 16 ;
V_77 = V_78 + V_79 ;
if ( V_68 < V_77 - V_79 / 4 ) {
V_70 = F_50 ( V_70 * ( V_77 - V_68 ) ,
V_77 - V_78 + 1 ) ;
} else
V_70 /= 4 ;
V_77 = V_73 / 2 ;
if ( V_68 < V_77 ) {
if ( V_68 > V_77 / 8 )
V_70 = F_50 ( V_70 * V_77 , V_68 ) ;
else
V_70 *= 8 ;
}
return V_70 ;
}
static void F_51 ( struct V_46 * V_47 ,
unsigned long V_84 ,
unsigned long V_85 )
{
const unsigned long V_86 = F_52 ( 3 * V_87 ) ;
unsigned long V_88 = V_47 -> V_75 ;
unsigned long V_89 = V_47 -> V_90 ;
T_4 V_91 ;
V_91 = V_85 - V_47 -> V_92 ;
V_91 *= V_87 ;
if ( F_27 ( V_84 > V_86 ) ) {
F_44 ( V_91 , V_84 ) ;
V_88 = V_91 ;
goto V_93;
}
V_91 += ( T_4 ) V_47 -> V_90 * ( V_86 - V_84 ) ;
V_91 >>= F_53 ( V_86 ) ;
if ( V_88 > V_89 && V_89 >= ( unsigned long ) V_91 )
V_88 -= ( V_88 - V_89 ) >> 3 ;
if ( V_88 < V_89 && V_89 <= ( unsigned long ) V_91 )
V_88 += ( V_89 - V_88 ) >> 3 ;
V_93:
V_47 -> V_90 = V_91 ;
V_47 -> V_75 = V_88 ;
}
static void F_54 ( unsigned long V_65 , unsigned long V_17 )
{
unsigned long V_31 = V_67 ;
if ( V_31 < V_65 ) {
V_31 = V_65 ;
goto V_94;
}
V_65 = F_42 ( V_65 , V_17 ) ;
if ( V_31 > V_65 ) {
V_31 -= ( V_31 - V_65 ) >> 5 ;
goto V_94;
}
return;
V_94:
V_67 = V_31 ;
}
static void F_55 ( unsigned long V_65 ,
unsigned long V_17 ,
unsigned long V_95 )
{
static F_56 ( V_96 ) ;
static unsigned long V_97 ;
if ( F_57 ( V_95 , V_97 + V_98 ) )
return;
F_58 ( & V_96 ) ;
if ( F_59 ( V_95 , V_97 + V_98 ) ) {
F_54 ( V_65 , V_17 ) ;
V_97 = V_95 ;
}
F_60 ( & V_96 ) ;
}
static void F_61 ( struct V_46 * V_47 ,
unsigned long V_65 ,
unsigned long V_66 ,
unsigned long V_17 ,
unsigned long V_73 ,
unsigned long V_68 ,
unsigned long V_99 ,
unsigned long V_84 )
{
unsigned long V_76 = F_40 ( V_65 , V_66 ) ;
unsigned long V_31 = F_41 ( V_65 ) ;
unsigned long V_69 = ( V_76 + V_31 ) / 2 ;
unsigned long V_74 = V_47 -> V_75 ;
unsigned long V_100 = V_47 -> V_100 ;
unsigned long V_101 ;
unsigned long V_102 ;
unsigned long V_103 ;
unsigned long V_70 ;
unsigned long V_104 ;
unsigned long V_9 ;
V_101 = ( V_99 - V_47 -> V_105 ) * V_87 / V_84 ;
V_70 = F_48 ( V_47 , V_65 , V_66 , V_17 ,
V_73 , V_68 ) ;
V_102 = ( T_4 ) V_100 *
V_70 >> V_72 ;
V_102 ++ ;
V_103 = F_50 ( ( T_4 ) V_102 * V_74 ,
V_101 | 1 ) ;
if ( F_27 ( V_103 > V_74 ) )
V_103 = V_74 ;
V_104 = 0 ;
if ( F_27 ( V_47 -> V_80 & V_81 ) ) {
V_17 = V_68 ;
if ( V_68 < 8 )
V_69 = V_68 + 1 ;
else
V_69 = ( V_73 +
F_43 ( V_47 , V_66 ) ) / 2 ;
}
if ( V_17 < V_69 ) {
V_9 = F_3 ( V_47 -> V_103 ,
F_3 ( V_103 , V_102 ) ) ;
if ( V_100 < V_9 )
V_104 = V_9 - V_100 ;
} else {
V_9 = F_42 ( V_47 -> V_103 ,
F_42 ( V_103 , V_102 ) ) ;
if ( V_100 > V_9 )
V_104 = V_100 - V_9 ;
}
V_104 >>= V_100 / ( 2 * V_104 + 1 ) ;
V_104 = ( V_104 + 7 ) / 8 ;
if ( V_100 < V_103 )
V_100 += V_104 ;
else
V_100 -= V_104 ;
V_47 -> V_100 = F_42 ( V_100 , 1UL ) ;
V_47 -> V_103 = V_103 ;
F_62 ( V_47 , V_101 , V_102 ) ;
}
void F_63 ( struct V_46 * V_47 ,
unsigned long V_65 ,
unsigned long V_66 ,
unsigned long V_17 ,
unsigned long V_73 ,
unsigned long V_68 ,
unsigned long V_106 )
{
unsigned long V_95 = V_53 ;
unsigned long V_84 = V_95 - V_47 -> V_107 ;
unsigned long V_99 ;
unsigned long V_85 ;
if ( V_84 < V_98 )
return;
V_99 = F_64 ( & V_47 -> V_108 [ V_109 ] ) ;
V_85 = F_64 ( & V_47 -> V_108 [ V_48 ] ) ;
if ( V_84 > V_87 && F_57 ( V_47 -> V_107 , V_106 ) )
goto V_110;
if ( V_65 ) {
F_55 ( V_65 , V_17 , V_95 ) ;
F_61 ( V_47 , V_65 , V_66 , V_17 ,
V_73 , V_68 ,
V_99 , V_84 ) ;
}
F_51 ( V_47 , V_84 , V_85 ) ;
V_110:
V_47 -> V_105 = V_99 ;
V_47 -> V_92 = V_85 ;
V_47 -> V_107 = V_95 ;
}
static void F_65 ( struct V_46 * V_47 ,
unsigned long V_65 ,
unsigned long V_66 ,
unsigned long V_17 ,
unsigned long V_73 ,
unsigned long V_68 ,
unsigned long V_106 )
{
if ( F_66 ( V_47 -> V_107 + V_98 ) )
return;
F_58 ( & V_47 -> V_111 . V_112 ) ;
F_63 ( V_47 , V_65 , V_66 , V_17 ,
V_73 , V_68 , V_106 ) ;
F_60 ( & V_47 -> V_111 . V_112 ) ;
}
static unsigned long F_67 ( unsigned long V_17 ,
unsigned long V_65 )
{
if ( V_65 > V_17 )
return 1UL << ( F_53 ( V_65 - V_17 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_68 ( struct V_46 * V_47 ,
unsigned long V_68 )
{
unsigned long V_91 = V_47 -> V_75 ;
unsigned long V_57 ;
V_57 = V_68 / ( 1 + V_91 / F_52 ( 1 + V_87 / 8 ) ) ;
V_57 ++ ;
return F_49 (unsigned long, t, MAX_PAUSE) ;
}
static long F_69 ( struct V_46 * V_47 ,
long V_113 ,
unsigned long V_102 ,
unsigned long V_100 ,
int * V_114 )
{
long V_115 = F_53 ( V_47 -> V_75 ) ;
long V_116 = F_53 ( V_47 -> V_100 ) ;
long V_57 ;
long V_117 ;
int V_118 ;
V_57 = F_42 ( 1 , V_87 / 100 ) ;
if ( V_115 > V_116 )
V_57 += ( V_115 - V_116 ) * ( 10 * V_87 ) / 1024 ;
V_57 = F_3 ( V_57 , 1 + V_113 / 2 ) ;
V_118 = V_100 * V_57 / F_52 ( V_87 ) ;
if ( V_118 < V_119 ) {
V_57 = V_113 ;
V_118 = V_100 * V_57 / F_52 ( V_87 ) ;
if ( V_118 > V_119 ) {
V_118 = V_119 ;
V_57 = V_87 * V_119 / V_100 ;
}
}
V_117 = V_87 * V_118 / ( V_102 + 1 ) ;
if ( V_117 > V_113 ) {
V_57 = V_113 ;
V_118 = V_102 * V_57 / F_52 ( V_87 ) ;
}
* V_114 = V_118 ;
return V_118 >= V_119 ? 1 + V_57 / 2 : V_57 ;
}
static inline void F_70 ( struct V_46 * V_47 ,
unsigned long V_120 ,
unsigned long V_121 ,
unsigned long * V_68 ,
unsigned long * V_73 ,
unsigned long * V_83 )
{
unsigned long V_122 ;
* V_73 = F_43 ( V_47 , V_120 ) ;
if ( V_83 )
* V_83 = F_50 ( ( T_4 ) * V_73 *
V_121 ,
V_120 ) ;
if ( * V_73 < 2 * F_71 ( V_47 ) ) {
V_122 = F_72 ( V_47 , V_123 ) ;
* V_68 = V_122 +
F_72 ( V_47 , V_124 ) ;
} else {
V_122 = V_108 ( V_47 , V_123 ) ;
* V_68 = V_122 +
V_108 ( V_47 , V_124 ) ;
}
}
static void F_73 ( struct V_125 * V_126 ,
unsigned long V_127 )
{
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_121 ;
unsigned long V_120 ;
long V_86 ;
long V_117 ;
long V_113 ;
long V_130 ;
int V_114 ;
bool V_131 = false ;
unsigned long V_102 ;
unsigned long V_100 ;
unsigned long V_70 ;
struct V_46 * V_47 = V_126 -> V_46 ;
bool V_132 = V_47 -> V_80 & V_81 ;
unsigned long V_106 = V_53 ;
for (; ; ) {
unsigned long V_95 = V_53 ;
unsigned long V_18 ( V_73 ) ;
unsigned long V_65 ;
unsigned long V_18 ( V_68 ) ;
unsigned long V_17 ;
unsigned long V_66 ;
V_128 = F_9 ( V_32 ) +
F_9 ( V_33 ) ;
V_129 = V_128 + F_9 ( V_34 ) ;
F_10 ( & V_121 , & V_120 ) ;
if ( F_27 ( V_132 ) ) {
F_70 ( V_47 , V_120 , V_121 ,
& V_68 , & V_73 , & V_66 ) ;
V_17 = V_68 ;
V_65 = V_73 ;
} else {
V_17 = V_129 ;
V_65 = V_120 ;
V_66 = V_121 ;
}
if ( V_17 <= F_40 ( V_65 , V_66 ) ) {
V_27 -> V_133 = V_95 ;
V_27 -> V_134 = 0 ;
V_27 -> V_114 =
F_67 ( V_17 , V_65 ) ;
break;
}
if ( F_27 ( ! F_74 ( V_47 ) ) )
F_75 ( V_47 ) ;
if ( ! V_132 )
F_70 ( V_47 , V_120 , V_121 ,
& V_68 , & V_73 , NULL ) ;
V_131 = ( V_68 > V_73 ) &&
( ( V_129 > V_120 ) || V_132 ) ;
if ( V_131 && ! V_47 -> V_131 )
V_47 -> V_131 = 1 ;
F_65 ( V_47 , V_120 , V_121 ,
V_129 , V_73 , V_68 ,
V_106 ) ;
V_100 = V_47 -> V_100 ;
V_70 = F_48 ( V_47 , V_120 ,
V_121 , V_129 ,
V_73 , V_68 ) ;
V_102 = ( ( T_4 ) V_100 * V_70 ) >>
V_72 ;
V_113 = F_68 ( V_47 , V_68 ) ;
V_130 = F_69 ( V_47 , V_113 ,
V_102 , V_100 ,
& V_114 ) ;
if ( F_27 ( V_102 == 0 ) ) {
V_86 = V_113 ;
V_117 = V_113 ;
goto V_117;
}
V_86 = V_87 * V_127 / V_102 ;
V_117 = V_86 ;
if ( V_27 -> V_133 )
V_117 -= V_95 - V_27 -> V_133 ;
if ( V_117 < V_130 ) {
F_76 ( V_47 ,
V_120 ,
V_121 ,
V_129 ,
V_73 ,
V_68 ,
V_100 ,
V_102 ,
V_127 ,
V_86 ,
F_3 ( V_117 , 0L ) ,
V_106 ) ;
if ( V_117 < - V_87 ) {
V_27 -> V_133 = V_95 ;
V_27 -> V_134 = 0 ;
} else if ( V_86 ) {
V_27 -> V_133 += V_86 ;
V_27 -> V_134 = 0 ;
} else if ( V_27 -> V_114 <= V_127 )
V_27 -> V_114 += V_127 ;
break;
}
if ( F_27 ( V_117 > V_113 ) ) {
V_95 += F_3 ( V_117 - V_113 , V_113 ) ;
V_117 = V_113 ;
}
V_117:
F_76 ( V_47 ,
V_120 ,
V_121 ,
V_129 ,
V_73 ,
V_68 ,
V_100 ,
V_102 ,
V_127 ,
V_86 ,
V_117 ,
V_106 ) ;
F_77 ( V_135 ) ;
F_78 ( V_117 ) ;
V_27 -> V_133 = V_95 + V_117 ;
V_27 -> V_134 = 0 ;
V_27 -> V_114 = V_114 ;
if ( V_102 )
break;
if ( V_68 <= F_71 ( V_47 ) )
break;
if ( F_79 ( V_27 ) )
break;
}
if ( ! V_131 && V_47 -> V_131 )
V_47 -> V_131 = 0 ;
if ( F_74 ( V_47 ) )
return;
if ( V_136 )
return;
if ( V_128 > V_121 )
F_75 ( V_47 ) ;
}
void F_80 ( struct V_137 * V_137 , int V_138 )
{
if ( F_81 ( V_137 ) || V_138 ) {
struct V_125 * V_126 = F_82 ( V_137 ) ;
if ( V_126 )
F_83 ( V_126 ) ;
}
}
void F_83 ( struct V_125 * V_126 )
{
struct V_46 * V_47 = V_126 -> V_46 ;
int V_139 ;
int * V_140 ;
if ( ! F_84 ( V_47 ) )
return;
V_139 = V_27 -> V_114 ;
if ( V_47 -> V_131 )
V_139 = F_3 ( V_139 , 32 >> ( V_141 - 10 ) ) ;
F_85 () ;
V_140 = & F_86 ( V_142 ) ;
if ( F_27 ( V_27 -> V_134 >= V_139 ) )
* V_140 = 0 ;
else if ( F_27 ( * V_140 >= V_143 ) ) {
* V_140 = 0 ;
V_139 = 0 ;
}
V_140 = & F_86 ( V_144 ) ;
if ( * V_140 > 0 && V_27 -> V_134 < V_139 ) {
unsigned long V_145 ;
V_145 = F_3 ( * V_140 , V_139 - V_27 -> V_134 ) ;
* V_140 -= V_145 ;
V_27 -> V_134 += V_145 ;
}
F_87 () ;
if ( F_27 ( V_27 -> V_134 >= V_139 ) )
F_73 ( V_126 , V_27 -> V_134 ) ;
}
void F_88 ( T_5 V_146 )
{
unsigned long V_121 ;
unsigned long V_120 ;
for ( ; ; ) {
F_10 ( & V_121 , & V_120 ) ;
V_120 = F_41 ( V_120 ) ;
V_120 += V_120 / 10 ;
if ( F_9 ( V_33 ) +
F_9 ( V_34 ) <= V_120 )
break;
F_89 ( V_147 , V_87 / 10 ) ;
if ( ( V_146 & ( V_148 | V_149 ) ) != ( V_148 | V_149 ) )
break;
}
}
int F_90 ( V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_150 , T_3 * V_40 )
{
F_91 ( V_36 , V_37 , V_38 , V_150 , V_40 ) ;
return 0 ;
}
void F_92 ( unsigned long V_151 )
{
struct V_152 * V_153 = (struct V_152 * ) V_151 ;
int V_2 = F_9 ( V_32 ) +
F_9 ( V_33 ) ;
if ( F_93 ( & V_153 -> V_46 ) )
F_94 ( & V_153 -> V_46 , V_2 ,
V_154 ) ;
}
void F_95 ( struct V_46 * V_155 )
{
F_28 ( & V_155 -> V_156 , V_53 + V_136 ) ;
}
void F_96 ( void )
{
struct V_46 * V_47 ;
F_97 () ;
F_98 (bdi, &bdi_list, bdi_list)
F_99 ( & V_47 -> V_156 ) ;
F_100 () ;
}
void F_21 ( void )
{
unsigned long V_121 ;
unsigned long V_120 ;
F_10 ( & V_121 , & V_120 ) ;
V_67 = V_120 ;
V_143 = V_120 / ( F_101 () * 32 ) ;
if ( V_143 < 16 )
V_143 = 16 ;
}
static int
F_102 ( struct V_157 * V_158 , unsigned long V_159 ,
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
void T_6 F_103 ( void )
{
F_21 () ;
F_104 ( & V_166 ) ;
F_105 ( & V_49 ) ;
}
void F_106 ( struct V_125 * V_126 ,
T_7 V_167 , T_7 V_168 )
{
#define F_107 4096
unsigned long V_169 ;
do {
F_108 ( & V_126 -> V_170 ) ;
V_169 = F_109 ( & V_126 -> V_171 ,
& V_167 , V_168 , F_107 ,
V_172 , V_173 ) ;
F_110 ( & V_126 -> V_170 ) ;
F_111 ( V_169 > F_107 ) ;
F_112 () ;
} while ( V_169 >= F_107 && V_167 );
}
int F_113 ( struct V_125 * V_126 ,
struct V_174 * V_175 , T_8 V_176 ,
void * V_151 )
{
int V_41 = 0 ;
int V_177 = 0 ;
struct V_178 V_179 ;
int V_2 ;
T_7 V_18 ( V_180 ) ;
T_7 V_181 ;
T_7 V_168 ;
T_7 V_182 ;
int V_183 ;
int V_184 = 0 ;
int V_185 ;
F_114 ( & V_179 , 0 ) ;
if ( V_175 -> V_186 ) {
V_180 = V_126 -> V_180 ;
V_181 = V_180 ;
if ( V_181 == 0 )
V_183 = 1 ;
else
V_183 = 0 ;
V_168 = - 1 ;
} else {
V_181 = V_175 -> V_187 >> V_188 ;
V_168 = V_175 -> V_189 >> V_188 ;
if ( V_175 -> V_187 == 0 && V_175 -> V_189 == V_190 )
V_184 = 1 ;
V_183 = 1 ;
}
if ( V_175 -> V_191 == V_192 || V_175 -> V_193 )
V_185 = V_173 ;
else
V_185 = V_172 ;
V_194:
if ( V_175 -> V_191 == V_192 || V_175 -> V_193 )
F_106 ( V_126 , V_181 , V_168 ) ;
V_182 = V_181 ;
while ( ! V_177 && ( V_181 <= V_168 ) ) {
int V_195 ;
V_2 = F_115 ( & V_179 , V_126 , & V_181 , V_185 ,
F_3 ( V_168 - V_181 , ( T_7 ) V_196 - 1 ) + 1 ) ;
if ( V_2 == 0 )
break;
for ( V_195 = 0 ; V_195 < V_2 ; V_195 ++ ) {
struct V_137 * V_137 = V_179 . V_118 [ V_195 ] ;
if ( V_137 -> V_181 > V_168 ) {
V_177 = 1 ;
break;
}
V_182 = V_137 -> V_181 ;
F_116 ( V_137 ) ;
if ( F_27 ( V_137 -> V_126 != V_126 ) ) {
V_197:
F_117 ( V_137 ) ;
continue;
}
if ( ! F_118 ( V_137 ) ) {
goto V_197;
}
if ( F_119 ( V_137 ) ) {
if ( V_175 -> V_191 != V_198 )
F_120 ( V_137 ) ;
else
goto V_197;
}
F_121 ( F_119 ( V_137 ) ) ;
if ( ! F_122 ( V_137 ) )
goto V_197;
F_123 ( V_175 , V_126 -> V_46 ) ;
V_41 = (* V_176)( V_137 , V_175 , V_151 ) ;
if ( F_27 ( V_41 ) ) {
if ( V_41 == V_199 ) {
F_117 ( V_137 ) ;
V_41 = 0 ;
} else {
V_182 = V_137 -> V_181 + 1 ;
V_177 = 1 ;
break;
}
}
if ( -- V_175 -> V_200 <= 0 &&
V_175 -> V_191 == V_198 ) {
V_177 = 1 ;
break;
}
}
F_124 ( & V_179 ) ;
F_112 () ;
}
if ( ! V_183 && ! V_177 ) {
V_183 = 1 ;
V_181 = 0 ;
V_168 = V_180 - 1 ;
goto V_194;
}
if ( V_175 -> V_186 || ( V_184 && V_175 -> V_200 > 0 ) )
V_126 -> V_180 = V_182 ;
return V_41 ;
}
static int F_125 ( struct V_137 * V_137 , struct V_174 * V_175 ,
void * V_151 )
{
struct V_125 * V_126 = V_151 ;
int V_41 = V_126 -> V_201 -> V_176 ( V_137 , V_175 ) ;
F_126 ( V_126 , V_41 ) ;
return V_41 ;
}
int F_127 ( struct V_125 * V_126 ,
struct V_174 * V_175 )
{
struct V_202 V_203 ;
int V_41 ;
if ( ! V_126 -> V_201 -> V_176 )
return 0 ;
F_128 ( & V_203 ) ;
V_41 = F_113 ( V_126 , V_175 , F_125 , V_126 ) ;
F_129 ( & V_203 ) ;
return V_41 ;
}
int F_130 ( struct V_125 * V_126 , struct V_174 * V_175 )
{
int V_41 ;
if ( V_175 -> V_200 <= 0 )
return 0 ;
if ( V_126 -> V_201 -> V_204 )
V_41 = V_126 -> V_201 -> V_204 ( V_126 , V_175 ) ;
else
V_41 = F_127 ( V_126 , V_175 ) ;
return V_41 ;
}
int F_131 ( struct V_137 * V_137 , int V_205 )
{
struct V_125 * V_126 = V_137 -> V_126 ;
int V_41 = 0 ;
struct V_174 V_175 = {
. V_191 = V_192 ,
. V_200 = 1 ,
} ;
F_121 ( ! F_132 ( V_137 ) ) ;
if ( V_205 )
F_120 ( V_137 ) ;
if ( F_122 ( V_137 ) ) {
F_133 ( V_137 ) ;
V_41 = V_126 -> V_201 -> V_176 ( V_137 , & V_175 ) ;
if ( V_41 == 0 && V_205 ) {
F_120 ( V_137 ) ;
if ( F_134 ( V_137 ) )
V_41 = - V_206 ;
}
F_135 ( V_137 ) ;
} else {
F_117 ( V_137 ) ;
}
return V_41 ;
}
int F_136 ( struct V_137 * V_137 )
{
if ( ! F_118 ( V_137 ) )
return ! F_137 ( V_137 ) ;
return 0 ;
}
void F_138 ( struct V_137 * V_137 , struct V_125 * V_126 )
{
F_139 ( V_137 , V_126 ) ;
if ( F_140 ( V_126 ) ) {
F_141 ( V_137 , V_32 ) ;
F_141 ( V_137 , V_207 ) ;
F_25 ( V_126 -> V_46 , V_123 ) ;
F_25 ( V_126 -> V_46 , V_109 ) ;
F_142 ( V_208 ) ;
V_27 -> V_134 ++ ;
F_143 ( V_142 ) ;
}
}
void F_144 ( struct V_137 * V_137 )
{
F_145 ( V_137 , V_209 ) ;
F_146 ( V_137 , V_34 ) ;
}
int F_147 ( struct V_137 * V_137 )
{
if ( ! F_137 ( V_137 ) ) {
struct V_125 * V_126 = F_82 ( V_137 ) ;
struct V_125 * V_210 ;
unsigned long V_28 ;
if ( ! V_126 )
return 1 ;
F_148 ( & V_126 -> V_170 , V_28 ) ;
V_210 = F_82 ( V_137 ) ;
if ( V_210 ) {
F_121 ( V_210 != V_126 ) ;
F_111 ( ! F_149 ( V_137 ) && ! F_150 ( V_137 ) ) ;
F_138 ( V_137 , V_126 ) ;
F_151 ( & V_126 -> V_171 ,
F_152 ( V_137 ) , V_172 ) ;
}
F_153 ( & V_126 -> V_170 , V_28 ) ;
if ( V_126 -> V_211 ) {
F_154 ( V_126 -> V_211 , V_212 ) ;
}
return 1 ;
}
return 0 ;
}
void F_155 ( struct V_137 * V_137 )
{
struct V_125 * V_126 = V_137 -> V_126 ;
if ( V_126 && F_140 ( V_126 ) ) {
V_27 -> V_134 -- ;
F_156 ( V_137 , V_207 ) ;
F_157 ( V_126 -> V_46 , V_109 ) ;
}
}
int F_158 ( struct V_174 * V_175 , struct V_137 * V_137 )
{
V_175 -> V_213 ++ ;
F_155 ( V_137 ) ;
return F_147 ( V_137 ) ;
}
int F_81 ( struct V_137 * V_137 )
{
struct V_125 * V_126 = F_82 ( V_137 ) ;
if ( F_159 ( V_126 ) ) {
int (* F_160)( struct V_137 * ) = V_126 -> V_201 -> F_81 ;
F_161 ( V_137 ) ;
#ifdef F_162
if ( ! F_160 )
F_160 = V_214 ;
#endif
return (* F_160)( V_137 ) ;
}
if ( ! F_118 ( V_137 ) ) {
if ( ! F_137 ( V_137 ) )
return 1 ;
}
return 0 ;
}
int F_163 ( struct V_137 * V_137 )
{
int V_41 ;
F_116 ( V_137 ) ;
V_41 = F_81 ( V_137 ) ;
F_117 ( V_137 ) ;
return V_41 ;
}
int F_122 ( struct V_137 * V_137 )
{
struct V_125 * V_126 = F_82 ( V_137 ) ;
F_121 ( ! F_132 ( V_137 ) ) ;
if ( V_126 && F_140 ( V_126 ) ) {
if ( F_164 ( V_137 ) )
F_81 ( V_137 ) ;
if ( F_165 ( V_137 ) ) {
F_156 ( V_137 , V_32 ) ;
F_157 ( V_126 -> V_46 ,
V_123 ) ;
return 1 ;
}
return 0 ;
}
return F_165 ( V_137 ) ;
}
int F_166 ( struct V_137 * V_137 )
{
struct V_125 * V_126 = F_82 ( V_137 ) ;
int V_41 ;
bool V_215 ;
unsigned long V_216 ;
F_167 ( V_137 , & V_215 , & V_216 ) ;
if ( V_126 ) {
struct V_46 * V_47 = V_126 -> V_46 ;
unsigned long V_28 ;
F_148 ( & V_126 -> V_170 , V_28 ) ;
V_41 = F_168 ( V_137 ) ;
if ( V_41 ) {
F_169 ( & V_126 -> V_171 ,
F_152 ( V_137 ) ,
V_217 ) ;
if ( F_170 ( V_47 ) ) {
F_171 ( V_47 , V_124 ) ;
F_24 ( V_47 ) ;
}
}
F_153 ( & V_126 -> V_170 , V_28 ) ;
} else {
V_41 = F_168 ( V_137 ) ;
}
if ( V_41 ) {
F_172 ( V_137 , V_209 ) ;
F_156 ( V_137 , V_34 ) ;
F_146 ( V_137 , V_218 ) ;
}
F_173 ( V_137 , & V_215 , & V_216 ) ;
return V_41 ;
}
int F_174 ( struct V_137 * V_137 )
{
struct V_125 * V_126 = F_82 ( V_137 ) ;
int V_41 ;
bool V_215 ;
unsigned long V_216 ;
F_167 ( V_137 , & V_215 , & V_216 ) ;
if ( V_126 ) {
struct V_46 * V_47 = V_126 -> V_46 ;
unsigned long V_28 ;
F_148 ( & V_126 -> V_170 , V_28 ) ;
V_41 = F_175 ( V_137 ) ;
if ( ! V_41 ) {
F_151 ( & V_126 -> V_171 ,
F_152 ( V_137 ) ,
V_217 ) ;
if ( F_170 ( V_47 ) )
F_25 ( V_47 , V_124 ) ;
}
if ( ! F_118 ( V_137 ) )
F_169 ( & V_126 -> V_171 ,
F_152 ( V_137 ) ,
V_172 ) ;
F_169 ( & V_126 -> V_171 ,
F_152 ( V_137 ) ,
V_173 ) ;
F_153 ( & V_126 -> V_170 , V_28 ) ;
} else {
V_41 = F_175 ( V_137 ) ;
}
if ( ! V_41 )
F_144 ( V_137 ) ;
F_173 ( V_137 , & V_215 , & V_216 ) ;
return V_41 ;
}
int F_176 ( struct V_125 * V_126 , int V_185 )
{
return F_177 ( & V_126 -> V_171 , V_185 ) ;
}
void F_178 ( struct V_137 * V_137 )
{
struct V_125 * V_126 = F_82 ( V_137 ) ;
struct V_46 * V_47 = V_126 -> V_46 ;
if ( ! F_179 ( V_47 ) )
return;
F_120 ( V_137 ) ;
}
