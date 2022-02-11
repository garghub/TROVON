static unsigned long F_1 ( unsigned long V_1 )
{
#ifdef F_2
int V_2 ;
unsigned long V_3 = 0 ;
F_3 (node, N_HIGH_MEMORY) {
struct V_4 * V_5 =
& F_4 ( V_2 ) -> V_6 [ V_7 ] ;
V_3 += F_5 ( V_5 , V_8 ) +
F_6 ( V_5 ) - V_5 -> V_9 ;
}
if ( ( long ) V_3 < 0 )
V_3 = 0 ;
return F_7 ( V_3 , V_1 ) ;
#else
return 0 ;
#endif
}
static unsigned long F_8 ( void )
{
unsigned long V_3 ;
V_3 = F_9 ( V_8 ) + F_10 () ;
V_3 -= F_7 ( V_3 , V_9 ) ;
if ( ! V_10 )
V_3 -= F_1 ( V_3 ) ;
return V_3 + 1 ;
}
void F_11 ( unsigned long * V_11 , unsigned long * V_12 )
{
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 ( V_16 ) ;
struct V_17 * V_18 ;
if ( ! V_19 || ! V_20 )
V_16 = F_8 () ;
if ( V_19 )
V_14 = F_12 ( V_19 , V_21 ) ;
else
V_14 = ( V_22 * V_16 ) / 100 ;
if ( V_20 )
V_13 = F_12 ( V_20 , V_21 ) ;
else
V_13 = ( V_23 * V_16 ) / 100 ;
if ( V_13 >= V_14 )
V_13 = V_14 / 2 ;
V_18 = V_24 ;
if ( V_18 -> V_25 & V_26 || F_13 ( V_18 ) ) {
V_13 += V_13 / 4 ;
V_14 += V_14 / 4 ;
}
* V_11 = V_13 ;
* V_12 = V_14 ;
F_14 ( V_13 , V_14 ) ;
}
static unsigned long F_15 ( struct V_4 * V_4 )
{
unsigned long V_27 = F_5 ( V_4 , V_8 ) +
F_6 ( V_4 ) ;
V_27 -= F_7 ( V_27 , V_4 -> V_9 ) ;
return V_27 ;
}
static unsigned long F_16 ( struct V_4 * V_4 )
{
unsigned long V_28 = F_15 ( V_4 ) ;
struct V_17 * V_18 = V_24 ;
unsigned long V_14 ;
if ( V_19 )
V_14 = F_12 ( V_19 , V_21 ) *
V_28 / F_8 () ;
else
V_14 = V_22 * V_28 / 100 ;
if ( V_18 -> V_25 & V_26 || F_13 ( V_18 ) )
V_14 += V_14 / 4 ;
return V_14 ;
}
bool F_17 ( struct V_4 * V_4 )
{
unsigned long V_29 = F_16 ( V_4 ) ;
return F_5 ( V_4 , V_30 ) +
F_5 ( V_4 , V_31 ) +
F_5 ( V_4 , V_32 ) <= V_29 ;
}
int F_18 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
int V_39 ;
V_39 = F_19 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 )
V_20 = 0 ;
return V_39 ;
}
int F_20 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
int V_39 ;
V_39 = F_21 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 )
V_23 = 0 ;
return V_39 ;
}
int F_22 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
int V_40 = V_22 ;
int V_39 ;
V_39 = F_19 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 && V_22 != V_40 ) {
F_23 () ;
V_19 = 0 ;
}
return V_39 ;
}
int F_24 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
unsigned long V_41 = V_19 ;
int V_39 ;
V_39 = F_21 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 && V_19 != V_41 ) {
F_23 () ;
V_22 = 0 ;
}
return V_39 ;
}
static unsigned long F_25 ( unsigned long V_42 )
{
V_42 += V_43 ;
if ( ! V_42 )
return 1 ;
return V_42 ;
}
static inline void F_26 ( struct V_44 * V_45 )
{
F_27 ( V_45 , V_46 ) ;
F_28 ( & V_47 , & V_45 -> V_48 ,
V_45 -> V_49 ) ;
if ( ! F_29 ( V_50 ) ) {
V_50 = F_25 ( V_51 ) ;
F_30 ( & V_52 , V_50 ) ;
}
}
void F_31 ( struct V_44 * V_45 )
{
unsigned long V_25 ;
F_32 ( V_25 ) ;
F_26 ( V_45 ) ;
F_33 ( V_25 ) ;
}
static void F_34 ( struct V_44 * V_45 ,
long * V_53 , long * V_54 )
{
F_35 ( & V_47 , & V_45 -> V_48 ,
V_53 , V_54 ) ;
}
static void F_36 ( unsigned long V_55 )
{
int V_56 = ( V_51 - V_50 ) /
V_43 ;
if ( F_37 ( & V_47 , V_56 + 1 ) ) {
V_50 = F_25 ( V_50 +
V_56 * V_43 ) ;
F_30 ( & V_52 , V_50 ) ;
} else {
V_50 = 0 ;
}
}
int F_38 ( struct V_44 * V_45 , unsigned int V_57 )
{
int V_39 = 0 ;
F_39 ( & V_58 ) ;
if ( V_57 > V_45 -> V_59 ) {
V_39 = - V_60 ;
} else {
V_57 -= V_45 -> V_57 ;
if ( V_61 + V_57 < 100 ) {
V_61 += V_57 ;
V_45 -> V_57 += V_57 ;
} else {
V_39 = - V_60 ;
}
}
F_40 ( & V_58 ) ;
return V_39 ;
}
int F_41 ( struct V_44 * V_45 , unsigned V_59 )
{
int V_39 = 0 ;
if ( V_59 > 100 )
return - V_60 ;
F_39 ( & V_58 ) ;
if ( V_45 -> V_57 > V_59 ) {
V_39 = - V_60 ;
} else {
V_45 -> V_59 = V_59 ;
V_45 -> V_49 = ( V_62 * V_59 ) / 100 ;
}
F_40 ( & V_58 ) ;
return V_39 ;
}
static unsigned long F_42 ( unsigned long V_63 ,
unsigned long V_64 )
{
return ( V_63 + V_64 ) / 2 ;
}
static unsigned long F_43 ( unsigned long V_63 )
{
return F_44 ( V_63 , V_65 ) ;
}
unsigned long F_45 ( struct V_44 * V_45 , unsigned long V_14 )
{
T_4 V_66 ;
long V_53 , V_54 ;
F_34 ( V_45 , & V_53 , & V_54 ) ;
V_66 = ( V_14 * ( 100 - V_61 ) ) / 100 ;
V_66 *= V_53 ;
F_46 ( V_66 , V_54 ) ;
V_66 += ( V_14 * V_45 -> V_57 ) / 100 ;
if ( V_66 > ( V_14 * V_45 -> V_59 ) / 100 )
V_66 = V_14 * V_45 -> V_59 / 100 ;
return V_66 ;
}
static inline long long F_47 ( unsigned long V_67 ,
unsigned long V_14 ,
unsigned long V_29 )
{
long long V_68 ;
long V_3 ;
V_3 = F_48 ( ( ( V_69 ) V_67 - ( V_69 ) V_14 ) << V_70 ,
V_29 - V_67 + 1 ) ;
V_68 = V_3 ;
V_68 = V_68 * V_3 >> V_70 ;
V_68 = V_68 * V_3 >> V_70 ;
V_68 += 1 << V_70 ;
return F_49 ( V_68 , 0LL , 2LL << V_70 ) ;
}
static unsigned long F_50 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_71 ,
unsigned long V_66 )
{
unsigned long V_72 = V_45 -> V_73 ;
unsigned long V_74 = F_42 ( V_63 , V_64 ) ;
unsigned long V_29 = F_43 ( V_63 ) ;
unsigned long V_75 ;
unsigned long V_67 ;
unsigned long V_76 ;
unsigned long V_77 ;
long long V_68 ;
long V_3 ;
if ( F_29 ( V_14 >= V_29 ) )
return 0 ;
V_67 = ( V_74 + V_29 ) / 2 ;
V_68 = F_47 ( V_67 , V_14 , V_29 ) ;
if ( F_29 ( V_45 -> V_78 & V_79 ) ) {
long long V_80 ;
unsigned long V_81 ;
if ( V_66 < 8 )
return F_51 (long long, pos_ratio * 2 ,
2 << RATELIMIT_CALC_SHIFT) ;
if ( V_66 >= V_71 )
return 0 ;
V_81 = F_52 ( ( T_4 ) V_71 * V_64 , V_63 ) ;
V_76 = F_42 ( V_71 ,
V_81 ) ;
if ( V_76 == 0 || V_76 == V_71 )
return 0 ;
V_80 = F_47 ( V_76 , V_66 ,
V_71 ) ;
return F_7 ( V_68 , V_80 ) ;
}
if ( F_29 ( V_71 > V_63 ) )
V_71 = V_63 ;
V_71 = F_44 ( V_71 , ( V_29 - V_14 ) / 8 ) ;
V_3 = F_52 ( ( T_4 ) V_71 << 16 , V_63 + 1 ) ;
V_76 = V_67 * ( T_4 ) V_3 >> 16 ;
V_77 = ( V_63 - V_71 + 8 * V_72 ) * ( T_4 ) V_3 >> 16 ;
V_75 = V_76 + V_77 ;
if ( V_66 < V_75 - V_77 / 4 ) {
V_68 = F_52 ( V_68 * ( V_75 - V_66 ) ,
V_75 - V_76 + 1 ) ;
} else
V_68 /= 4 ;
V_75 = V_71 / 2 ;
if ( V_66 < V_75 ) {
if ( V_66 > V_75 / 8 )
V_68 = F_52 ( V_68 * V_75 , V_66 ) ;
else
V_68 *= 8 ;
}
return V_68 ;
}
static void F_53 ( struct V_44 * V_45 ,
unsigned long V_82 ,
unsigned long V_83 )
{
const unsigned long V_84 = F_54 ( 3 * V_85 ) ;
unsigned long V_86 = V_45 -> V_73 ;
unsigned long V_87 = V_45 -> V_88 ;
T_4 V_89 ;
V_89 = V_83 - V_45 -> V_90 ;
V_89 *= V_85 ;
if ( F_29 ( V_82 > V_84 ) ) {
F_46 ( V_89 , V_82 ) ;
V_86 = V_89 ;
goto V_91;
}
V_89 += ( T_4 ) V_45 -> V_88 * ( V_84 - V_82 ) ;
V_89 >>= F_55 ( V_84 ) ;
if ( V_86 > V_87 && V_87 >= ( unsigned long ) V_89 )
V_86 -= ( V_86 - V_87 ) >> 3 ;
if ( V_86 < V_87 && V_87 <= ( unsigned long ) V_89 )
V_86 += ( V_87 - V_86 ) >> 3 ;
V_91:
V_45 -> V_88 = V_89 ;
V_45 -> V_73 = V_86 ;
}
static void F_56 ( unsigned long V_63 , unsigned long V_14 )
{
unsigned long V_29 = V_65 ;
if ( V_29 < V_63 ) {
V_29 = V_63 ;
goto V_92;
}
V_63 = F_44 ( V_63 , V_14 ) ;
if ( V_29 > V_63 ) {
V_29 -= ( V_29 - V_63 ) >> 5 ;
goto V_92;
}
return;
V_92:
V_65 = V_29 ;
}
static void F_57 ( unsigned long V_63 ,
unsigned long V_14 ,
unsigned long V_93 )
{
static F_58 ( V_94 ) ;
static unsigned long V_95 ;
if ( F_59 ( V_93 , V_95 + V_96 ) )
return;
F_60 ( & V_94 ) ;
if ( F_61 ( V_93 , V_95 + V_96 ) ) {
F_56 ( V_63 , V_14 ) ;
V_95 = V_93 ;
}
F_62 ( & V_94 ) ;
}
static void F_63 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_71 ,
unsigned long V_66 ,
unsigned long V_97 ,
unsigned long V_82 )
{
unsigned long V_74 = F_42 ( V_63 , V_64 ) ;
unsigned long V_29 = F_43 ( V_63 ) ;
unsigned long V_67 = ( V_74 + V_29 ) / 2 ;
unsigned long V_72 = V_45 -> V_73 ;
unsigned long V_98 = V_45 -> V_98 ;
unsigned long V_99 ;
unsigned long V_100 ;
unsigned long V_101 ;
unsigned long V_68 ;
unsigned long V_102 ;
unsigned long V_3 ;
V_99 = ( V_97 - V_45 -> V_103 ) * V_85 / V_82 ;
V_68 = F_50 ( V_45 , V_63 , V_64 , V_14 ,
V_71 , V_66 ) ;
V_100 = ( T_4 ) V_98 *
V_68 >> V_70 ;
V_100 ++ ;
V_101 = F_52 ( ( T_4 ) V_100 * V_72 ,
V_99 | 1 ) ;
if ( F_29 ( V_101 > V_72 ) )
V_101 = V_72 ;
V_102 = 0 ;
if ( F_29 ( V_45 -> V_78 & V_79 ) ) {
V_14 = V_66 ;
if ( V_66 < 8 )
V_67 = V_66 + 1 ;
else
V_67 = ( V_71 +
F_45 ( V_45 , V_64 ) ) / 2 ;
}
if ( V_14 < V_67 ) {
V_3 = F_7 ( V_45 -> V_101 ,
F_7 ( V_101 , V_100 ) ) ;
if ( V_98 < V_3 )
V_102 = V_3 - V_98 ;
} else {
V_3 = F_44 ( V_45 -> V_101 ,
F_44 ( V_101 , V_100 ) ) ;
if ( V_98 > V_3 )
V_102 = V_98 - V_3 ;
}
V_102 >>= V_98 / ( 2 * V_102 + 1 ) ;
V_102 = ( V_102 + 7 ) / 8 ;
if ( V_98 < V_101 )
V_98 += V_102 ;
else
V_98 -= V_102 ;
V_45 -> V_98 = F_44 ( V_98 , 1UL ) ;
V_45 -> V_101 = V_101 ;
F_64 ( V_45 , V_99 , V_100 ) ;
}
void F_65 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_71 ,
unsigned long V_66 ,
unsigned long V_104 )
{
unsigned long V_93 = V_51 ;
unsigned long V_82 = V_93 - V_45 -> V_105 ;
unsigned long V_97 ;
unsigned long V_83 ;
if ( V_82 < V_96 )
return;
V_97 = F_66 ( & V_45 -> V_106 [ V_107 ] ) ;
V_83 = F_66 ( & V_45 -> V_106 [ V_46 ] ) ;
if ( V_82 > V_85 && F_59 ( V_45 -> V_105 , V_104 ) )
goto V_108;
if ( V_63 ) {
F_57 ( V_63 , V_14 , V_93 ) ;
F_63 ( V_45 , V_63 , V_64 , V_14 ,
V_71 , V_66 ,
V_97 , V_82 ) ;
}
F_53 ( V_45 , V_82 , V_83 ) ;
V_108:
V_45 -> V_103 = V_97 ;
V_45 -> V_90 = V_83 ;
V_45 -> V_105 = V_93 ;
}
static void F_67 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_71 ,
unsigned long V_66 ,
unsigned long V_104 )
{
if ( F_68 ( V_45 -> V_105 + V_96 ) )
return;
F_60 ( & V_45 -> V_109 . V_110 ) ;
F_65 ( V_45 , V_63 , V_64 , V_14 ,
V_71 , V_66 , V_104 ) ;
F_62 ( & V_45 -> V_109 . V_110 ) ;
}
static unsigned long F_69 ( unsigned long V_14 ,
unsigned long V_63 )
{
if ( V_63 > V_14 )
return 1UL << ( F_55 ( V_63 - V_14 ) >> 1 ) ;
return 1 ;
}
static unsigned long F_70 ( struct V_44 * V_45 ,
unsigned long V_66 )
{
unsigned long V_89 = V_45 -> V_73 ;
unsigned long V_55 ;
V_55 = V_66 / ( 1 + V_89 / F_54 ( 1 + V_85 / 8 ) ) ;
V_55 ++ ;
return F_51 (unsigned long, t, MAX_PAUSE) ;
}
static long F_71 ( struct V_44 * V_45 ,
long V_111 ,
unsigned long V_100 ,
unsigned long V_98 ,
int * V_112 )
{
long V_113 = F_55 ( V_45 -> V_73 ) ;
long V_114 = F_55 ( V_45 -> V_98 ) ;
long V_55 ;
long V_115 ;
int V_116 ;
V_55 = F_44 ( 1 , V_85 / 100 ) ;
if ( V_113 > V_114 )
V_55 += ( V_113 - V_114 ) * ( 10 * V_85 ) / 1024 ;
V_55 = F_7 ( V_55 , 1 + V_111 / 2 ) ;
V_116 = V_98 * V_55 / F_54 ( V_85 ) ;
if ( V_116 < V_117 ) {
V_55 = V_111 ;
V_116 = V_98 * V_55 / F_54 ( V_85 ) ;
if ( V_116 > V_117 ) {
V_116 = V_117 ;
V_55 = V_85 * V_117 / V_98 ;
}
}
V_115 = V_85 * V_116 / ( V_100 + 1 ) ;
if ( V_115 > V_111 ) {
V_55 = V_111 ;
V_116 = V_100 * V_55 / F_54 ( V_85 ) ;
}
* V_112 = V_116 ;
return V_116 >= V_117 ? 1 + V_55 / 2 : V_55 ;
}
static inline void F_72 ( struct V_44 * V_45 ,
unsigned long V_118 ,
unsigned long V_119 ,
unsigned long * V_66 ,
unsigned long * V_71 ,
unsigned long * V_81 )
{
unsigned long V_120 ;
* V_71 = F_45 ( V_45 , V_118 ) ;
if ( V_81 )
* V_81 = F_52 ( ( T_4 ) * V_71 *
V_119 ,
V_118 ) ;
if ( * V_71 < 2 * F_73 ( V_45 ) ) {
V_120 = F_74 ( V_45 , V_121 ) ;
* V_66 = V_120 +
F_74 ( V_45 , V_122 ) ;
} else {
V_120 = V_106 ( V_45 , V_121 ) ;
* V_66 = V_120 +
V_106 ( V_45 , V_122 ) ;
}
}
static void F_75 ( struct V_123 * V_124 ,
unsigned long V_125 )
{
unsigned long V_126 ;
unsigned long V_127 ;
unsigned long V_119 ;
unsigned long V_118 ;
long V_84 ;
long V_115 ;
long V_111 ;
long V_128 ;
int V_112 ;
bool V_129 = false ;
unsigned long V_100 ;
unsigned long V_98 ;
unsigned long V_68 ;
struct V_44 * V_45 = V_124 -> V_44 ;
bool V_130 = V_45 -> V_78 & V_79 ;
unsigned long V_104 = V_51 ;
for (; ; ) {
unsigned long V_93 = V_51 ;
unsigned long V_15 ( V_71 ) ;
unsigned long V_63 ;
unsigned long V_15 ( V_66 ) ;
unsigned long V_14 ;
unsigned long V_64 ;
V_126 = F_9 ( V_30 ) +
F_9 ( V_31 ) ;
V_127 = V_126 + F_9 ( V_32 ) ;
F_11 ( & V_119 , & V_118 ) ;
if ( F_29 ( V_130 ) ) {
F_72 ( V_45 , V_118 , V_119 ,
& V_66 , & V_71 , & V_64 ) ;
V_14 = V_66 ;
V_63 = V_71 ;
} else {
V_14 = V_127 ;
V_63 = V_118 ;
V_64 = V_119 ;
}
if ( V_14 <= F_42 ( V_63 , V_64 ) ) {
V_24 -> V_131 = V_93 ;
V_24 -> V_132 = 0 ;
V_24 -> V_112 =
F_69 ( V_14 , V_63 ) ;
break;
}
if ( F_29 ( ! F_76 ( V_45 ) ) )
F_77 ( V_45 ) ;
if ( ! V_130 )
F_72 ( V_45 , V_118 , V_119 ,
& V_66 , & V_71 , NULL ) ;
V_129 = ( V_66 > V_71 ) &&
( ( V_127 > V_118 ) || V_130 ) ;
if ( V_129 && ! V_45 -> V_129 )
V_45 -> V_129 = 1 ;
F_67 ( V_45 , V_118 , V_119 ,
V_127 , V_71 , V_66 ,
V_104 ) ;
V_98 = V_45 -> V_98 ;
V_68 = F_50 ( V_45 , V_118 ,
V_119 , V_127 ,
V_71 , V_66 ) ;
V_100 = ( ( T_4 ) V_98 * V_68 ) >>
V_70 ;
V_111 = F_70 ( V_45 , V_66 ) ;
V_128 = F_71 ( V_45 , V_111 ,
V_100 , V_98 ,
& V_112 ) ;
if ( F_29 ( V_100 == 0 ) ) {
V_84 = V_111 ;
V_115 = V_111 ;
goto V_115;
}
V_84 = V_85 * V_125 / V_100 ;
V_115 = V_84 ;
if ( V_24 -> V_131 )
V_115 -= V_93 - V_24 -> V_131 ;
if ( V_115 < V_128 ) {
F_78 ( V_45 ,
V_118 ,
V_119 ,
V_127 ,
V_71 ,
V_66 ,
V_98 ,
V_100 ,
V_125 ,
V_84 ,
F_7 ( V_115 , 0L ) ,
V_104 ) ;
if ( V_115 < - V_85 ) {
V_24 -> V_131 = V_93 ;
V_24 -> V_132 = 0 ;
} else if ( V_84 ) {
V_24 -> V_131 += V_84 ;
V_24 -> V_132 = 0 ;
} else if ( V_24 -> V_112 <= V_125 )
V_24 -> V_112 += V_125 ;
break;
}
if ( F_29 ( V_115 > V_111 ) ) {
V_93 += F_7 ( V_115 - V_111 , V_111 ) ;
V_115 = V_111 ;
}
V_115:
F_78 ( V_45 ,
V_118 ,
V_119 ,
V_127 ,
V_71 ,
V_66 ,
V_98 ,
V_100 ,
V_125 ,
V_84 ,
V_115 ,
V_104 ) ;
F_79 ( V_133 ) ;
F_80 ( V_115 ) ;
V_24 -> V_131 = V_93 + V_115 ;
V_24 -> V_132 = 0 ;
V_24 -> V_112 = V_112 ;
if ( V_100 )
break;
if ( V_66 <= F_73 ( V_45 ) )
break;
if ( F_81 ( V_24 ) )
break;
}
if ( ! V_129 && V_45 -> V_129 )
V_45 -> V_129 = 0 ;
if ( F_76 ( V_45 ) )
return;
if ( V_134 )
return;
if ( V_126 > V_119 )
F_77 ( V_45 ) ;
}
void F_82 ( struct V_135 * V_135 , int V_136 )
{
if ( F_83 ( V_135 ) || V_136 ) {
struct V_123 * V_124 = F_84 ( V_135 ) ;
if ( V_124 )
F_85 ( V_124 ) ;
}
}
void F_85 ( struct V_123 * V_124 )
{
struct V_44 * V_45 = V_124 -> V_44 ;
int V_137 ;
int * V_138 ;
if ( ! F_86 ( V_45 ) )
return;
V_137 = V_24 -> V_112 ;
if ( V_45 -> V_129 )
V_137 = F_7 ( V_137 , 32 >> ( V_139 - 10 ) ) ;
F_87 () ;
V_138 = & F_88 ( V_140 ) ;
if ( F_29 ( V_24 -> V_132 >= V_137 ) )
* V_138 = 0 ;
else if ( F_29 ( * V_138 >= V_141 ) ) {
* V_138 = 0 ;
V_137 = 0 ;
}
V_138 = & F_88 ( V_142 ) ;
if ( * V_138 > 0 && V_24 -> V_132 < V_137 ) {
unsigned long V_143 ;
V_143 = F_7 ( * V_138 , V_137 - V_24 -> V_132 ) ;
* V_138 -= V_143 ;
V_24 -> V_132 += V_143 ;
}
F_89 () ;
if ( F_29 ( V_24 -> V_132 >= V_137 ) )
F_75 ( V_124 , V_24 -> V_132 ) ;
}
void F_90 ( T_5 V_144 )
{
unsigned long V_119 ;
unsigned long V_118 ;
for ( ; ; ) {
F_11 ( & V_119 , & V_118 ) ;
V_118 = F_43 ( V_118 ) ;
V_118 += V_118 / 10 ;
if ( F_9 ( V_31 ) +
F_9 ( V_32 ) <= V_118 )
break;
F_91 ( V_145 , V_85 / 10 ) ;
if ( ( V_144 & ( V_146 | V_147 ) ) != ( V_146 | V_147 ) )
break;
}
}
int F_92 ( V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_148 , T_3 * V_38 )
{
F_93 ( V_34 , V_35 , V_36 , V_148 , V_38 ) ;
return 0 ;
}
void F_94 ( unsigned long V_149 )
{
struct V_150 * V_151 = (struct V_150 * ) V_149 ;
int V_27 = F_9 ( V_30 ) +
F_9 ( V_31 ) ;
if ( F_95 ( & V_151 -> V_44 ) )
F_96 ( & V_151 -> V_44 , V_27 ,
V_152 ) ;
}
void F_97 ( struct V_44 * V_153 )
{
F_30 ( & V_153 -> V_154 , V_51 + V_134 ) ;
}
void F_98 ( void )
{
struct V_44 * V_45 ;
F_99 () ;
F_100 (bdi, &bdi_list, bdi_list)
F_101 ( & V_45 -> V_154 ) ;
F_102 () ;
}
void F_23 ( void )
{
unsigned long V_119 ;
unsigned long V_118 ;
F_11 ( & V_119 , & V_118 ) ;
V_65 = V_118 ;
V_141 = V_118 / ( F_103 () * 32 ) ;
if ( V_141 < 16 )
V_141 = 16 ;
}
static int
F_104 ( struct V_155 * V_156 , unsigned long V_157 ,
void * V_158 )
{
switch ( V_157 & ~ V_159 ) {
case V_160 :
case V_161 :
F_23 () ;
return V_162 ;
default:
return V_163 ;
}
}
void T_6 F_105 ( void )
{
F_23 () ;
F_106 ( & V_164 ) ;
F_107 ( & V_47 ) ;
}
void F_108 ( struct V_123 * V_124 ,
T_7 V_165 , T_7 V_166 )
{
#define F_109 4096
unsigned long V_167 ;
do {
F_110 ( & V_124 -> V_168 ) ;
V_167 = F_111 ( & V_124 -> V_169 ,
& V_165 , V_166 , F_109 ,
V_170 , V_171 ) ;
F_112 ( & V_124 -> V_168 ) ;
F_113 ( V_167 > F_109 ) ;
F_114 () ;
} while ( V_167 >= F_109 && V_165 );
}
int F_115 ( struct V_123 * V_124 ,
struct V_172 * V_173 , T_8 V_174 ,
void * V_149 )
{
int V_39 = 0 ;
int V_175 = 0 ;
struct V_176 V_177 ;
int V_27 ;
T_7 V_15 ( V_178 ) ;
T_7 V_179 ;
T_7 V_166 ;
T_7 V_180 ;
int V_181 ;
int V_182 = 0 ;
int V_183 ;
F_116 ( & V_177 , 0 ) ;
if ( V_173 -> V_184 ) {
V_178 = V_124 -> V_178 ;
V_179 = V_178 ;
if ( V_179 == 0 )
V_181 = 1 ;
else
V_181 = 0 ;
V_166 = - 1 ;
} else {
V_179 = V_173 -> V_185 >> V_186 ;
V_166 = V_173 -> V_187 >> V_186 ;
if ( V_173 -> V_185 == 0 && V_173 -> V_187 == V_188 )
V_182 = 1 ;
V_181 = 1 ;
}
if ( V_173 -> V_189 == V_190 || V_173 -> V_191 )
V_183 = V_171 ;
else
V_183 = V_170 ;
V_192:
if ( V_173 -> V_189 == V_190 || V_173 -> V_191 )
F_108 ( V_124 , V_179 , V_166 ) ;
V_180 = V_179 ;
while ( ! V_175 && ( V_179 <= V_166 ) ) {
int V_193 ;
V_27 = F_117 ( & V_177 , V_124 , & V_179 , V_183 ,
F_7 ( V_166 - V_179 , ( T_7 ) V_194 - 1 ) + 1 ) ;
if ( V_27 == 0 )
break;
for ( V_193 = 0 ; V_193 < V_27 ; V_193 ++ ) {
struct V_135 * V_135 = V_177 . V_116 [ V_193 ] ;
if ( V_135 -> V_179 > V_166 ) {
V_175 = 1 ;
break;
}
V_180 = V_135 -> V_179 ;
F_118 ( V_135 ) ;
if ( F_29 ( V_135 -> V_124 != V_124 ) ) {
V_195:
F_119 ( V_135 ) ;
continue;
}
if ( ! F_120 ( V_135 ) ) {
goto V_195;
}
if ( F_121 ( V_135 ) ) {
if ( V_173 -> V_189 != V_196 )
F_122 ( V_135 ) ;
else
goto V_195;
}
F_123 ( F_121 ( V_135 ) ) ;
if ( ! F_124 ( V_135 ) )
goto V_195;
F_125 ( V_173 , V_124 -> V_44 ) ;
V_39 = (* V_174)( V_135 , V_173 , V_149 ) ;
if ( F_29 ( V_39 ) ) {
if ( V_39 == V_197 ) {
F_119 ( V_135 ) ;
V_39 = 0 ;
} else {
V_180 = V_135 -> V_179 + 1 ;
V_175 = 1 ;
break;
}
}
if ( -- V_173 -> V_198 <= 0 &&
V_173 -> V_189 == V_196 ) {
V_175 = 1 ;
break;
}
}
F_126 ( & V_177 ) ;
F_114 () ;
}
if ( ! V_181 && ! V_175 ) {
V_181 = 1 ;
V_179 = 0 ;
V_166 = V_178 - 1 ;
goto V_192;
}
if ( V_173 -> V_184 || ( V_182 && V_173 -> V_198 > 0 ) )
V_124 -> V_178 = V_180 ;
return V_39 ;
}
static int F_127 ( struct V_135 * V_135 , struct V_172 * V_173 ,
void * V_149 )
{
struct V_123 * V_124 = V_149 ;
int V_39 = V_124 -> V_199 -> V_174 ( V_135 , V_173 ) ;
F_128 ( V_124 , V_39 ) ;
return V_39 ;
}
int F_129 ( struct V_123 * V_124 ,
struct V_172 * V_173 )
{
struct V_200 V_201 ;
int V_39 ;
if ( ! V_124 -> V_199 -> V_174 )
return 0 ;
F_130 ( & V_201 ) ;
V_39 = F_115 ( V_124 , V_173 , F_127 , V_124 ) ;
F_131 ( & V_201 ) ;
return V_39 ;
}
int F_132 ( struct V_123 * V_124 , struct V_172 * V_173 )
{
int V_39 ;
if ( V_173 -> V_198 <= 0 )
return 0 ;
if ( V_124 -> V_199 -> V_202 )
V_39 = V_124 -> V_199 -> V_202 ( V_124 , V_173 ) ;
else
V_39 = F_129 ( V_124 , V_173 ) ;
return V_39 ;
}
int F_133 ( struct V_135 * V_135 , int V_203 )
{
struct V_123 * V_124 = V_135 -> V_124 ;
int V_39 = 0 ;
struct V_172 V_173 = {
. V_189 = V_190 ,
. V_198 = 1 ,
} ;
F_123 ( ! F_134 ( V_135 ) ) ;
if ( V_203 )
F_122 ( V_135 ) ;
if ( F_124 ( V_135 ) ) {
F_135 ( V_135 ) ;
V_39 = V_124 -> V_199 -> V_174 ( V_135 , & V_173 ) ;
if ( V_39 == 0 && V_203 ) {
F_122 ( V_135 ) ;
if ( F_136 ( V_135 ) )
V_39 = - V_204 ;
}
F_137 ( V_135 ) ;
} else {
F_119 ( V_135 ) ;
}
return V_39 ;
}
int F_138 ( struct V_135 * V_135 )
{
if ( ! F_120 ( V_135 ) )
return ! F_139 ( V_135 ) ;
return 0 ;
}
void F_140 ( struct V_135 * V_135 , struct V_123 * V_124 )
{
F_141 ( V_135 , V_124 ) ;
if ( F_142 ( V_124 ) ) {
F_143 ( V_135 , V_30 ) ;
F_143 ( V_135 , V_205 ) ;
F_27 ( V_124 -> V_44 , V_121 ) ;
F_27 ( V_124 -> V_44 , V_107 ) ;
F_144 ( V_206 ) ;
V_24 -> V_132 ++ ;
F_145 ( V_140 ) ;
}
}
void F_146 ( struct V_135 * V_135 )
{
F_147 ( V_135 , V_207 ) ;
F_148 ( V_135 , V_32 ) ;
}
int F_149 ( struct V_135 * V_135 )
{
if ( ! F_139 ( V_135 ) ) {
struct V_123 * V_124 = F_84 ( V_135 ) ;
struct V_123 * V_208 ;
if ( ! V_124 )
return 1 ;
F_110 ( & V_124 -> V_168 ) ;
V_208 = F_84 ( V_135 ) ;
if ( V_208 ) {
F_123 ( V_208 != V_124 ) ;
F_113 ( ! F_150 ( V_135 ) && ! F_151 ( V_135 ) ) ;
F_140 ( V_135 , V_124 ) ;
F_152 ( & V_124 -> V_169 ,
F_153 ( V_135 ) , V_170 ) ;
}
F_112 ( & V_124 -> V_168 ) ;
if ( V_124 -> V_209 ) {
F_154 ( V_124 -> V_209 , V_210 ) ;
}
return 1 ;
}
return 0 ;
}
void F_155 ( struct V_135 * V_135 )
{
struct V_123 * V_124 = V_135 -> V_124 ;
if ( V_124 && F_142 ( V_124 ) ) {
V_24 -> V_132 -- ;
F_156 ( V_135 , V_205 ) ;
F_157 ( V_124 -> V_44 , V_107 ) ;
}
}
int F_158 ( struct V_172 * V_173 , struct V_135 * V_135 )
{
V_173 -> V_211 ++ ;
F_155 ( V_135 ) ;
return F_149 ( V_135 ) ;
}
int F_83 ( struct V_135 * V_135 )
{
struct V_123 * V_124 = F_84 ( V_135 ) ;
if ( F_159 ( V_124 ) ) {
int (* F_160)( struct V_135 * ) = V_124 -> V_199 -> F_83 ;
F_161 ( V_135 ) ;
#ifdef F_162
if ( ! F_160 )
F_160 = V_212 ;
#endif
return (* F_160)( V_135 ) ;
}
if ( ! F_120 ( V_135 ) ) {
if ( ! F_139 ( V_135 ) )
return 1 ;
}
return 0 ;
}
int F_163 ( struct V_135 * V_135 )
{
int V_39 ;
F_118 ( V_135 ) ;
V_39 = F_83 ( V_135 ) ;
F_119 ( V_135 ) ;
return V_39 ;
}
int F_124 ( struct V_135 * V_135 )
{
struct V_123 * V_124 = F_84 ( V_135 ) ;
F_123 ( ! F_134 ( V_135 ) ) ;
if ( V_124 && F_142 ( V_124 ) ) {
if ( F_164 ( V_135 ) )
F_83 ( V_135 ) ;
if ( F_165 ( V_135 ) ) {
F_156 ( V_135 , V_30 ) ;
F_157 ( V_124 -> V_44 ,
V_121 ) ;
return 1 ;
}
return 0 ;
}
return F_165 ( V_135 ) ;
}
int F_166 ( struct V_135 * V_135 )
{
struct V_123 * V_124 = F_84 ( V_135 ) ;
int V_39 ;
bool V_213 ;
unsigned long V_214 ;
F_167 ( V_135 , & V_213 , & V_214 ) ;
if ( V_124 ) {
struct V_44 * V_45 = V_124 -> V_44 ;
unsigned long V_25 ;
F_168 ( & V_124 -> V_168 , V_25 ) ;
V_39 = F_169 ( V_135 ) ;
if ( V_39 ) {
F_170 ( & V_124 -> V_169 ,
F_153 ( V_135 ) ,
V_215 ) ;
if ( F_171 ( V_45 ) ) {
F_172 ( V_45 , V_122 ) ;
F_26 ( V_45 ) ;
}
}
F_173 ( & V_124 -> V_168 , V_25 ) ;
} else {
V_39 = F_169 ( V_135 ) ;
}
if ( V_39 ) {
F_174 ( V_135 , V_207 ) ;
F_156 ( V_135 , V_32 ) ;
F_148 ( V_135 , V_216 ) ;
}
F_175 ( V_135 , & V_213 , & V_214 ) ;
return V_39 ;
}
int F_176 ( struct V_135 * V_135 )
{
struct V_123 * V_124 = F_84 ( V_135 ) ;
int V_39 ;
bool V_213 ;
unsigned long V_214 ;
F_167 ( V_135 , & V_213 , & V_214 ) ;
if ( V_124 ) {
struct V_44 * V_45 = V_124 -> V_44 ;
unsigned long V_25 ;
F_168 ( & V_124 -> V_168 , V_25 ) ;
V_39 = F_177 ( V_135 ) ;
if ( ! V_39 ) {
F_152 ( & V_124 -> V_169 ,
F_153 ( V_135 ) ,
V_215 ) ;
if ( F_171 ( V_45 ) )
F_27 ( V_45 , V_122 ) ;
}
if ( ! F_120 ( V_135 ) )
F_170 ( & V_124 -> V_169 ,
F_153 ( V_135 ) ,
V_170 ) ;
F_170 ( & V_124 -> V_169 ,
F_153 ( V_135 ) ,
V_171 ) ;
F_173 ( & V_124 -> V_168 , V_25 ) ;
} else {
V_39 = F_177 ( V_135 ) ;
}
if ( ! V_39 )
F_146 ( V_135 ) ;
F_175 ( V_135 , & V_213 , & V_214 ) ;
return V_39 ;
}
int F_178 ( struct V_123 * V_124 , int V_183 )
{
return F_179 ( & V_124 -> V_169 , V_183 ) ;
}
void F_180 ( struct V_135 * V_135 )
{
struct V_123 * V_124 = F_84 ( V_135 ) ;
struct V_44 * V_45 = V_124 -> V_44 ;
if ( ! F_181 ( V_45 ) )
return;
F_122 ( V_135 ) ;
}
