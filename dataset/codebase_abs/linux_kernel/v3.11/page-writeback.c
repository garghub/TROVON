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
V_3 -= F_11 (unsigned long, x, min_free_kbytes >> (PAGE_SHIFT - 10)) ;
return V_3 + 1 ;
}
void F_12 ( unsigned long * V_11 , unsigned long * V_12 )
{
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 ( V_16 ) ;
struct V_17 * V_18 ;
if ( ! V_19 || ! V_20 )
V_16 = F_8 () ;
if ( V_19 )
V_14 = F_13 ( V_19 , V_21 ) ;
else
V_14 = ( V_22 * V_16 ) / 100 ;
if ( V_20 )
V_13 = F_13 ( V_20 , V_21 ) ;
else
V_13 = ( V_23 * V_16 ) / 100 ;
if ( V_13 >= V_14 )
V_13 = V_14 / 2 ;
V_18 = V_24 ;
if ( V_18 -> V_25 & V_26 || F_14 ( V_18 ) ) {
V_13 += V_13 / 4 ;
V_14 += V_14 / 4 ;
}
* V_11 = V_13 ;
* V_12 = V_14 ;
F_15 ( V_13 , V_14 ) ;
}
static unsigned long F_16 ( struct V_4 * V_4 )
{
unsigned long V_27 = F_5 ( V_4 , V_8 ) +
F_6 ( V_4 ) ;
V_27 -= F_7 ( V_27 , V_4 -> V_9 ) ;
return V_27 ;
}
static unsigned long F_17 ( struct V_4 * V_4 )
{
unsigned long V_28 = F_16 ( V_4 ) ;
struct V_17 * V_18 = V_24 ;
unsigned long V_14 ;
if ( V_19 )
V_14 = F_13 ( V_19 , V_21 ) *
V_28 / F_8 () ;
else
V_14 = V_22 * V_28 / 100 ;
if ( V_18 -> V_25 & V_26 || F_14 ( V_18 ) )
V_14 += V_14 / 4 ;
return V_14 ;
}
bool F_18 ( struct V_4 * V_4 )
{
unsigned long V_29 = F_17 ( V_4 ) ;
return F_5 ( V_4 , V_30 ) +
F_5 ( V_4 , V_31 ) +
F_5 ( V_4 , V_32 ) <= V_29 ;
}
int F_19 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
int V_39 ;
V_39 = F_20 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 )
V_20 = 0 ;
return V_39 ;
}
int F_21 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
int V_39 ;
V_39 = F_22 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 )
V_23 = 0 ;
return V_39 ;
}
int F_23 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
int V_40 = V_22 ;
int V_39 ;
V_39 = F_20 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 && V_22 != V_40 ) {
F_24 () ;
V_19 = 0 ;
}
return V_39 ;
}
int F_25 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
unsigned long V_41 = V_19 ;
int V_39 ;
V_39 = F_22 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_39 == 0 && V_35 && V_19 != V_41 ) {
F_24 () ;
V_22 = 0 ;
}
return V_39 ;
}
static unsigned long F_26 ( unsigned long V_42 )
{
V_42 += V_43 ;
if ( ! V_42 )
return 1 ;
return V_42 ;
}
static inline void F_27 ( struct V_44 * V_45 )
{
F_28 ( V_45 , V_46 ) ;
F_29 ( & V_47 , & V_45 -> V_48 ,
V_45 -> V_49 ) ;
if ( ! F_30 ( V_50 ) ) {
V_50 = F_26 ( V_51 ) ;
F_31 ( & V_52 , V_50 ) ;
}
}
void F_32 ( struct V_44 * V_45 )
{
unsigned long V_25 ;
F_33 ( V_25 ) ;
F_27 ( V_45 ) ;
F_34 ( V_25 ) ;
}
static void F_35 ( struct V_44 * V_45 ,
long * V_53 , long * V_54 )
{
F_36 ( & V_47 , & V_45 -> V_48 ,
V_53 , V_54 ) ;
}
static void F_37 ( unsigned long V_55 )
{
int V_56 = ( V_51 - V_50 ) /
V_43 ;
if ( F_38 ( & V_47 , V_56 + 1 ) ) {
V_50 = F_26 ( V_50 +
V_56 * V_43 ) ;
F_31 ( & V_52 , V_50 ) ;
} else {
V_50 = 0 ;
}
}
int F_39 ( struct V_44 * V_45 , unsigned int V_57 )
{
int V_39 = 0 ;
F_40 ( & V_58 ) ;
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
F_41 ( & V_58 ) ;
return V_39 ;
}
int F_42 ( struct V_44 * V_45 , unsigned V_59 )
{
int V_39 = 0 ;
if ( V_59 > 100 )
return - V_60 ;
F_40 ( & V_58 ) ;
if ( V_45 -> V_57 > V_59 ) {
V_39 = - V_60 ;
} else {
V_45 -> V_59 = V_59 ;
V_45 -> V_49 = ( V_62 * V_59 ) / 100 ;
}
F_41 ( & V_58 ) ;
return V_39 ;
}
static unsigned long F_43 ( unsigned long V_63 ,
unsigned long V_64 )
{
return ( V_63 + V_64 ) / 2 ;
}
static unsigned long F_44 ( unsigned long V_63 )
{
return F_45 ( V_63 , V_65 ) ;
}
unsigned long F_46 ( struct V_44 * V_45 , unsigned long V_14 )
{
T_4 V_66 ;
long V_53 , V_54 ;
F_35 ( V_45 , & V_53 , & V_54 ) ;
V_66 = ( V_14 * ( 100 - V_61 ) ) / 100 ;
V_66 *= V_53 ;
F_47 ( V_66 , V_54 ) ;
V_66 += ( V_14 * V_45 -> V_57 ) / 100 ;
if ( V_66 > ( V_14 * V_45 -> V_59 ) / 100 )
V_66 = V_14 * V_45 -> V_59 / 100 ;
return V_66 ;
}
static unsigned long F_48 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 )
{
unsigned long V_68 = V_45 -> V_69 ;
unsigned long V_70 = F_43 ( V_63 , V_64 ) ;
unsigned long V_29 = F_44 ( V_63 ) ;
unsigned long V_71 ;
unsigned long V_72 ;
unsigned long V_73 ;
unsigned long V_74 ;
long long V_75 ;
long V_3 ;
if ( F_30 ( V_14 >= V_29 ) )
return 0 ;
V_72 = ( V_70 + V_29 ) / 2 ;
V_3 = F_49 ( ( ( V_76 ) V_72 - ( V_76 ) V_14 ) << V_77 ,
V_29 - V_72 + 1 ) ;
V_75 = V_3 ;
V_75 = V_75 * V_3 >> V_77 ;
V_75 = V_75 * V_3 >> V_77 ;
V_75 += 1 << V_77 ;
if ( F_30 ( V_67 > V_63 ) )
V_67 = V_63 ;
V_67 = F_45 ( V_67 , ( V_29 - V_14 ) / 8 ) ;
V_3 = F_50 ( ( T_4 ) V_67 << 16 , V_63 + 1 ) ;
V_73 = V_72 * ( T_4 ) V_3 >> 16 ;
V_74 = ( V_63 - V_67 + 8 * V_68 ) * ( T_4 ) V_3 >> 16 ;
V_71 = V_73 + V_74 ;
if ( V_66 < V_71 - V_74 / 4 ) {
V_75 = F_50 ( V_75 * ( V_71 - V_66 ) ,
V_71 - V_73 + 1 ) ;
} else
V_75 /= 4 ;
V_71 = V_67 / 2 ;
if ( V_66 < V_71 ) {
if ( V_66 > V_71 / 8 )
V_75 = F_50 ( V_75 * V_71 , V_66 ) ;
else
V_75 *= 8 ;
}
return V_75 ;
}
static void F_51 ( struct V_44 * V_45 ,
unsigned long V_78 ,
unsigned long V_79 )
{
const unsigned long V_80 = F_52 ( 3 * V_81 ) ;
unsigned long V_82 = V_45 -> V_69 ;
unsigned long V_83 = V_45 -> V_84 ;
T_4 V_85 ;
V_85 = V_79 - V_45 -> V_86 ;
V_85 *= V_81 ;
if ( F_30 ( V_78 > V_80 ) ) {
F_47 ( V_85 , V_78 ) ;
V_82 = V_85 ;
goto V_87;
}
V_85 += ( T_4 ) V_45 -> V_84 * ( V_80 - V_78 ) ;
V_85 >>= F_53 ( V_80 ) ;
if ( V_82 > V_83 && V_83 >= ( unsigned long ) V_85 )
V_82 -= ( V_82 - V_83 ) >> 3 ;
if ( V_82 < V_83 && V_83 <= ( unsigned long ) V_85 )
V_82 += ( V_83 - V_82 ) >> 3 ;
V_87:
V_45 -> V_84 = V_85 ;
V_45 -> V_69 = V_82 ;
}
static void F_54 ( unsigned long V_63 , unsigned long V_14 )
{
unsigned long V_29 = V_65 ;
if ( V_29 < V_63 ) {
V_29 = V_63 ;
goto V_88;
}
V_63 = F_45 ( V_63 , V_14 ) ;
if ( V_29 > V_63 ) {
V_29 -= ( V_29 - V_63 ) >> 5 ;
goto V_88;
}
return;
V_88:
V_65 = V_29 ;
}
static void F_55 ( unsigned long V_63 ,
unsigned long V_14 ,
unsigned long V_89 )
{
static F_56 ( V_90 ) ;
static unsigned long V_91 ;
if ( F_57 ( V_89 , V_91 + V_92 ) )
return;
F_58 ( & V_90 ) ;
if ( F_59 ( V_89 , V_91 + V_92 ) ) {
F_54 ( V_63 , V_14 ) ;
V_91 = V_89 ;
}
F_60 ( & V_90 ) ;
}
static void F_61 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 ,
unsigned long V_93 ,
unsigned long V_78 )
{
unsigned long V_70 = F_43 ( V_63 , V_64 ) ;
unsigned long V_29 = F_44 ( V_63 ) ;
unsigned long V_72 = ( V_70 + V_29 ) / 2 ;
unsigned long V_68 = V_45 -> V_69 ;
unsigned long V_94 = V_45 -> V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
unsigned long V_97 ;
unsigned long V_75 ;
unsigned long V_98 ;
unsigned long V_3 ;
V_95 = ( V_93 - V_45 -> V_99 ) * V_81 / V_78 ;
V_75 = F_48 ( V_45 , V_63 , V_64 , V_14 ,
V_67 , V_66 ) ;
V_96 = ( T_4 ) V_94 *
V_75 >> V_77 ;
V_96 ++ ;
V_97 = F_50 ( ( T_4 ) V_96 * V_68 ,
V_95 | 1 ) ;
if ( F_30 ( V_97 > V_68 ) )
V_97 = V_68 ;
V_98 = 0 ;
if ( V_14 < V_72 ) {
V_3 = F_7 ( V_45 -> V_97 ,
F_7 ( V_97 , V_96 ) ) ;
if ( V_94 < V_3 )
V_98 = V_3 - V_94 ;
} else {
V_3 = F_45 ( V_45 -> V_97 ,
F_45 ( V_97 , V_96 ) ) ;
if ( V_94 > V_3 )
V_98 = V_94 - V_3 ;
}
V_98 >>= V_94 / ( 2 * V_98 + 1 ) ;
V_98 = ( V_98 + 7 ) / 8 ;
if ( V_94 < V_97 )
V_94 += V_98 ;
else
V_94 -= V_98 ;
V_45 -> V_94 = F_45 ( V_94 , 1UL ) ;
V_45 -> V_97 = V_97 ;
F_62 ( V_45 , V_95 , V_96 ) ;
}
void F_63 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 ,
unsigned long V_100 )
{
unsigned long V_89 = V_51 ;
unsigned long V_78 = V_89 - V_45 -> V_101 ;
unsigned long V_93 ;
unsigned long V_79 ;
if ( V_78 < V_92 )
return;
V_93 = F_64 ( & V_45 -> V_102 [ V_103 ] ) ;
V_79 = F_64 ( & V_45 -> V_102 [ V_46 ] ) ;
if ( V_78 > V_81 && F_57 ( V_45 -> V_101 , V_100 ) )
goto V_104;
if ( V_63 ) {
F_55 ( V_63 , V_14 , V_89 ) ;
F_61 ( V_45 , V_63 , V_64 , V_14 ,
V_67 , V_66 ,
V_93 , V_78 ) ;
}
F_51 ( V_45 , V_78 , V_79 ) ;
V_104:
V_45 -> V_99 = V_93 ;
V_45 -> V_86 = V_79 ;
V_45 -> V_101 = V_89 ;
}
static void F_65 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 ,
unsigned long V_100 )
{
if ( F_66 ( V_45 -> V_101 + V_92 ) )
return;
F_58 ( & V_45 -> V_105 . V_106 ) ;
F_63 ( V_45 , V_63 , V_64 , V_14 ,
V_67 , V_66 , V_100 ) ;
F_60 ( & V_45 -> V_105 . V_106 ) ;
}
static unsigned long F_67 ( unsigned long V_14 ,
unsigned long V_63 )
{
if ( V_63 > V_14 )
return 1UL << ( F_53 ( V_63 - V_14 ) >> 1 ) ;
return 1 ;
}
static long F_68 ( struct V_44 * V_45 ,
unsigned long V_66 )
{
long V_85 = V_45 -> V_69 ;
long V_55 ;
V_55 = V_66 / ( 1 + V_85 / F_52 ( 1 + V_81 / 8 ) ) ;
V_55 ++ ;
return F_11 ( long , V_55 , V_107 ) ;
}
static long F_69 ( struct V_44 * V_45 ,
long V_108 ,
unsigned long V_96 ,
unsigned long V_94 ,
int * V_109 )
{
long V_110 = F_53 ( V_45 -> V_69 ) ;
long V_111 = F_53 ( V_45 -> V_94 ) ;
long V_55 ;
long V_112 ;
int V_113 ;
V_55 = F_45 ( 1 , V_81 / 100 ) ;
if ( V_110 > V_111 )
V_55 += ( V_110 - V_111 ) * ( 10 * V_81 ) / 1024 ;
V_55 = F_7 ( V_55 , 1 + V_108 / 2 ) ;
V_113 = V_94 * V_55 / F_52 ( V_81 ) ;
if ( V_113 < V_114 ) {
V_55 = V_108 ;
V_113 = V_94 * V_55 / F_52 ( V_81 ) ;
if ( V_113 > V_114 ) {
V_113 = V_114 ;
V_55 = V_81 * V_114 / V_94 ;
}
}
V_112 = V_81 * V_113 / ( V_96 + 1 ) ;
if ( V_112 > V_108 ) {
V_55 = V_108 ;
V_113 = V_96 * V_55 / F_52 ( V_81 ) ;
}
* V_109 = V_113 ;
return V_113 >= V_114 ? 1 + V_55 / 2 : V_55 ;
}
static void F_70 ( struct V_115 * V_116 ,
unsigned long V_117 )
{
unsigned long V_118 ;
unsigned long V_119 ;
unsigned long V_120 ;
unsigned long V_66 ;
unsigned long V_70 ;
unsigned long V_121 ;
unsigned long V_122 ;
unsigned long V_67 ;
long V_80 ;
long V_112 ;
long V_108 ;
long V_123 ;
int V_109 ;
bool V_124 = false ;
unsigned long V_96 ;
unsigned long V_94 ;
unsigned long V_75 ;
struct V_44 * V_45 = V_116 -> V_44 ;
unsigned long V_100 = V_51 ;
for (; ; ) {
unsigned long V_89 = V_51 ;
V_118 = F_9 ( V_30 ) +
F_9 ( V_31 ) ;
V_120 = V_118 + F_9 ( V_32 ) ;
F_12 ( & V_121 , & V_122 ) ;
V_70 = F_43 ( V_122 ,
V_121 ) ;
if ( V_120 <= V_70 ) {
V_24 -> V_125 = V_89 ;
V_24 -> V_126 = 0 ;
V_24 -> V_109 =
F_67 ( V_120 , V_122 ) ;
break;
}
if ( F_30 ( ! F_71 ( V_45 ) ) )
F_72 ( V_45 ) ;
V_67 = F_46 ( V_45 , V_122 ) ;
if ( V_67 < 2 * F_73 ( V_45 ) ) {
V_119 = F_74 ( V_45 , V_127 ) ;
V_66 = V_119 +
F_74 ( V_45 , V_128 ) ;
} else {
V_119 = V_102 ( V_45 , V_127 ) ;
V_66 = V_119 +
V_102 ( V_45 , V_128 ) ;
}
V_124 = ( V_66 > V_67 ) &&
( V_120 > V_122 ) ;
if ( V_124 && ! V_45 -> V_124 )
V_45 -> V_124 = 1 ;
F_65 ( V_45 , V_122 , V_121 ,
V_120 , V_67 , V_66 ,
V_100 ) ;
V_94 = V_45 -> V_94 ;
V_75 = F_48 ( V_45 , V_122 ,
V_121 , V_120 ,
V_67 , V_66 ) ;
V_96 = ( ( T_4 ) V_94 * V_75 ) >>
V_77 ;
V_108 = F_68 ( V_45 , V_66 ) ;
V_123 = F_69 ( V_45 , V_108 ,
V_96 , V_94 ,
& V_109 ) ;
if ( F_30 ( V_96 == 0 ) ) {
V_80 = V_108 ;
V_112 = V_108 ;
goto V_112;
}
V_80 = V_81 * V_117 / V_96 ;
V_112 = V_80 ;
if ( V_24 -> V_125 )
V_112 -= V_89 - V_24 -> V_125 ;
if ( V_112 < V_123 ) {
F_75 ( V_45 ,
V_122 ,
V_121 ,
V_120 ,
V_67 ,
V_66 ,
V_94 ,
V_96 ,
V_117 ,
V_80 ,
F_7 ( V_112 , 0L ) ,
V_100 ) ;
if ( V_112 < - V_81 ) {
V_24 -> V_125 = V_89 ;
V_24 -> V_126 = 0 ;
} else if ( V_80 ) {
V_24 -> V_125 += V_80 ;
V_24 -> V_126 = 0 ;
} else if ( V_24 -> V_109 <= V_117 )
V_24 -> V_109 += V_117 ;
break;
}
if ( F_30 ( V_112 > V_108 ) ) {
V_89 += F_7 ( V_112 - V_108 , V_108 ) ;
V_112 = V_108 ;
}
V_112:
F_75 ( V_45 ,
V_122 ,
V_121 ,
V_120 ,
V_67 ,
V_66 ,
V_94 ,
V_96 ,
V_117 ,
V_80 ,
V_112 ,
V_100 ) ;
F_76 ( V_129 ) ;
F_77 ( V_112 ) ;
V_24 -> V_125 = V_89 + V_112 ;
V_24 -> V_126 = 0 ;
V_24 -> V_109 = V_109 ;
if ( V_96 )
break;
if ( V_66 <= F_73 ( V_45 ) )
break;
if ( F_78 ( V_24 ) )
break;
}
if ( ! V_124 && V_45 -> V_124 )
V_45 -> V_124 = 0 ;
if ( F_71 ( V_45 ) )
return;
if ( V_130 )
return;
if ( V_118 > V_121 )
F_72 ( V_45 ) ;
}
void F_79 ( struct V_131 * V_131 , int V_132 )
{
if ( F_80 ( V_131 ) || V_132 ) {
struct V_115 * V_116 = F_81 ( V_131 ) ;
if ( V_116 )
F_82 ( V_116 ) ;
}
}
void F_82 ( struct V_115 * V_116 )
{
struct V_44 * V_45 = V_116 -> V_44 ;
int V_133 ;
int * V_134 ;
if ( ! F_83 ( V_45 ) )
return;
V_133 = V_24 -> V_109 ;
if ( V_45 -> V_124 )
V_133 = F_7 ( V_133 , 32 >> ( V_135 - 10 ) ) ;
F_84 () ;
V_134 = & F_85 ( V_136 ) ;
if ( F_30 ( V_24 -> V_126 >= V_133 ) )
* V_134 = 0 ;
else if ( F_30 ( * V_134 >= V_137 ) ) {
* V_134 = 0 ;
V_133 = 0 ;
}
V_134 = & F_85 ( V_138 ) ;
if ( * V_134 > 0 && V_24 -> V_126 < V_133 ) {
unsigned long V_139 ;
V_139 = F_7 ( * V_134 , V_133 - V_24 -> V_126 ) ;
* V_134 -= V_139 ;
V_24 -> V_126 += V_139 ;
}
F_86 () ;
if ( F_30 ( V_24 -> V_126 >= V_133 ) )
F_70 ( V_116 , V_24 -> V_126 ) ;
}
void F_87 ( T_5 V_140 )
{
unsigned long V_121 ;
unsigned long V_122 ;
for ( ; ; ) {
F_12 ( & V_121 , & V_122 ) ;
V_122 = F_44 ( V_122 ) ;
V_122 += V_122 / 10 ;
if ( F_9 ( V_31 ) +
F_9 ( V_32 ) <= V_122 )
break;
F_88 ( V_141 , V_81 / 10 ) ;
if ( ( V_140 & ( V_142 | V_143 ) ) != ( V_142 | V_143 ) )
break;
}
}
int F_89 ( V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_144 , T_3 * V_38 )
{
F_90 ( V_34 , V_35 , V_36 , V_144 , V_38 ) ;
return 0 ;
}
void F_91 ( unsigned long V_145 )
{
struct V_146 * V_147 = (struct V_146 * ) V_145 ;
int V_27 = F_9 ( V_30 ) +
F_9 ( V_31 ) ;
if ( F_92 ( & V_147 -> V_44 ) )
F_93 ( & V_147 -> V_44 , V_27 ,
V_148 ) ;
}
void F_94 ( struct V_44 * V_149 )
{
F_31 ( & V_149 -> V_150 , V_51 + V_130 ) ;
}
void F_95 ( void )
{
struct V_44 * V_45 ;
F_96 () ;
F_97 (bdi, &bdi_list, bdi_list)
F_98 ( & V_45 -> V_150 ) ;
F_99 () ;
}
void F_24 ( void )
{
unsigned long V_121 ;
unsigned long V_122 ;
F_12 ( & V_121 , & V_122 ) ;
V_65 = V_122 ;
V_137 = V_122 / ( F_100 () * 32 ) ;
if ( V_137 < 16 )
V_137 = 16 ;
}
static int
F_101 ( struct V_151 * V_152 , unsigned long V_153 ,
void * V_154 )
{
switch ( V_153 & ~ V_155 ) {
case V_156 :
case V_157 :
F_24 () ;
return V_158 ;
default:
return V_159 ;
}
}
void T_6 F_102 ( void )
{
F_24 () ;
F_103 ( & V_160 ) ;
F_104 ( & V_47 ) ;
}
void F_105 ( struct V_115 * V_116 ,
T_7 V_161 , T_7 V_162 )
{
#define F_106 4096
unsigned long V_163 ;
do {
F_107 ( & V_116 -> V_164 ) ;
V_163 = F_108 ( & V_116 -> V_165 ,
& V_161 , V_162 , F_106 ,
V_166 , V_167 ) ;
F_109 ( & V_116 -> V_164 ) ;
F_110 ( V_163 > F_106 ) ;
F_111 () ;
} while ( V_163 >= F_106 && V_161 );
}
int F_112 ( struct V_115 * V_116 ,
struct V_168 * V_169 , T_8 V_170 ,
void * V_145 )
{
int V_39 = 0 ;
int V_171 = 0 ;
struct V_172 V_173 ;
int V_27 ;
T_7 V_15 ( V_174 ) ;
T_7 V_175 ;
T_7 V_162 ;
T_7 V_176 ;
int V_177 ;
int V_178 = 0 ;
int V_179 ;
F_113 ( & V_173 , 0 ) ;
if ( V_169 -> V_180 ) {
V_174 = V_116 -> V_174 ;
V_175 = V_174 ;
if ( V_175 == 0 )
V_177 = 1 ;
else
V_177 = 0 ;
V_162 = - 1 ;
} else {
V_175 = V_169 -> V_181 >> V_182 ;
V_162 = V_169 -> V_183 >> V_182 ;
if ( V_169 -> V_181 == 0 && V_169 -> V_183 == V_184 )
V_178 = 1 ;
V_177 = 1 ;
}
if ( V_169 -> V_185 == V_186 || V_169 -> V_187 )
V_179 = V_167 ;
else
V_179 = V_166 ;
V_188:
if ( V_169 -> V_185 == V_186 || V_169 -> V_187 )
F_105 ( V_116 , V_175 , V_162 ) ;
V_176 = V_175 ;
while ( ! V_171 && ( V_175 <= V_162 ) ) {
int V_189 ;
V_27 = F_114 ( & V_173 , V_116 , & V_175 , V_179 ,
F_7 ( V_162 - V_175 , ( T_7 ) V_190 - 1 ) + 1 ) ;
if ( V_27 == 0 )
break;
for ( V_189 = 0 ; V_189 < V_27 ; V_189 ++ ) {
struct V_131 * V_131 = V_173 . V_113 [ V_189 ] ;
if ( V_131 -> V_175 > V_162 ) {
V_171 = 1 ;
break;
}
V_176 = V_131 -> V_175 ;
F_115 ( V_131 ) ;
if ( F_30 ( V_131 -> V_116 != V_116 ) ) {
V_191:
F_116 ( V_131 ) ;
continue;
}
if ( ! F_117 ( V_131 ) ) {
goto V_191;
}
if ( F_118 ( V_131 ) ) {
if ( V_169 -> V_185 != V_192 )
F_119 ( V_131 ) ;
else
goto V_191;
}
F_120 ( F_118 ( V_131 ) ) ;
if ( ! F_121 ( V_131 ) )
goto V_191;
F_122 ( V_169 , V_116 -> V_44 ) ;
V_39 = (* V_170)( V_131 , V_169 , V_145 ) ;
if ( F_30 ( V_39 ) ) {
if ( V_39 == V_193 ) {
F_116 ( V_131 ) ;
V_39 = 0 ;
} else {
V_176 = V_131 -> V_175 + 1 ;
V_171 = 1 ;
break;
}
}
if ( -- V_169 -> V_194 <= 0 &&
V_169 -> V_185 == V_192 ) {
V_171 = 1 ;
break;
}
}
F_123 ( & V_173 ) ;
F_111 () ;
}
if ( ! V_177 && ! V_171 ) {
V_177 = 1 ;
V_175 = 0 ;
V_162 = V_174 - 1 ;
goto V_188;
}
if ( V_169 -> V_180 || ( V_178 && V_169 -> V_194 > 0 ) )
V_116 -> V_174 = V_176 ;
return V_39 ;
}
static int F_124 ( struct V_131 * V_131 , struct V_168 * V_169 ,
void * V_145 )
{
struct V_115 * V_116 = V_145 ;
int V_39 = V_116 -> V_195 -> V_170 ( V_131 , V_169 ) ;
F_125 ( V_116 , V_39 ) ;
return V_39 ;
}
int F_126 ( struct V_115 * V_116 ,
struct V_168 * V_169 )
{
struct V_196 V_197 ;
int V_39 ;
if ( ! V_116 -> V_195 -> V_170 )
return 0 ;
F_127 ( & V_197 ) ;
V_39 = F_112 ( V_116 , V_169 , F_124 , V_116 ) ;
F_128 ( & V_197 ) ;
return V_39 ;
}
int F_129 ( struct V_115 * V_116 , struct V_168 * V_169 )
{
int V_39 ;
if ( V_169 -> V_194 <= 0 )
return 0 ;
if ( V_116 -> V_195 -> V_198 )
V_39 = V_116 -> V_195 -> V_198 ( V_116 , V_169 ) ;
else
V_39 = F_126 ( V_116 , V_169 ) ;
return V_39 ;
}
int F_130 ( struct V_131 * V_131 , int V_199 )
{
struct V_115 * V_116 = V_131 -> V_116 ;
int V_39 = 0 ;
struct V_168 V_169 = {
. V_185 = V_186 ,
. V_194 = 1 ,
} ;
F_120 ( ! F_131 ( V_131 ) ) ;
if ( V_199 )
F_119 ( V_131 ) ;
if ( F_121 ( V_131 ) ) {
F_132 ( V_131 ) ;
V_39 = V_116 -> V_195 -> V_170 ( V_131 , & V_169 ) ;
if ( V_39 == 0 && V_199 ) {
F_119 ( V_131 ) ;
if ( F_133 ( V_131 ) )
V_39 = - V_200 ;
}
F_134 ( V_131 ) ;
} else {
F_116 ( V_131 ) ;
}
return V_39 ;
}
int F_135 ( struct V_131 * V_131 )
{
if ( ! F_117 ( V_131 ) )
return ! F_136 ( V_131 ) ;
return 0 ;
}
void F_137 ( struct V_131 * V_131 , struct V_115 * V_116 )
{
F_138 ( V_131 , V_116 ) ;
if ( F_139 ( V_116 ) ) {
F_140 ( V_131 , V_30 ) ;
F_140 ( V_131 , V_201 ) ;
F_28 ( V_116 -> V_44 , V_127 ) ;
F_28 ( V_116 -> V_44 , V_103 ) ;
F_141 ( V_202 ) ;
V_24 -> V_126 ++ ;
F_142 ( V_136 ) ;
}
}
void F_143 ( struct V_131 * V_131 )
{
F_144 ( V_131 , V_32 ) ;
}
int F_145 ( struct V_131 * V_131 )
{
if ( ! F_136 ( V_131 ) ) {
struct V_115 * V_116 = F_81 ( V_131 ) ;
struct V_115 * V_203 ;
if ( ! V_116 )
return 1 ;
F_107 ( & V_116 -> V_164 ) ;
V_203 = F_81 ( V_131 ) ;
if ( V_203 ) {
F_120 ( V_203 != V_116 ) ;
F_110 ( ! F_146 ( V_131 ) && ! F_147 ( V_131 ) ) ;
F_137 ( V_131 , V_116 ) ;
F_148 ( & V_116 -> V_165 ,
F_149 ( V_131 ) , V_166 ) ;
}
F_109 ( & V_116 -> V_164 ) ;
if ( V_116 -> V_204 ) {
F_150 ( V_116 -> V_204 , V_205 ) ;
}
return 1 ;
}
return 0 ;
}
void F_151 ( struct V_131 * V_131 )
{
struct V_115 * V_116 = V_131 -> V_116 ;
if ( V_116 && F_139 ( V_116 ) ) {
V_24 -> V_126 -- ;
F_152 ( V_131 , V_201 ) ;
F_153 ( V_116 -> V_44 , V_103 ) ;
}
}
int F_154 ( struct V_168 * V_169 , struct V_131 * V_131 )
{
V_169 -> V_206 ++ ;
F_151 ( V_131 ) ;
return F_145 ( V_131 ) ;
}
int F_80 ( struct V_131 * V_131 )
{
struct V_115 * V_116 = F_81 ( V_131 ) ;
if ( F_155 ( V_116 ) ) {
int (* F_156)( struct V_131 * ) = V_116 -> V_195 -> F_80 ;
F_157 ( V_131 ) ;
#ifdef F_158
if ( ! F_156 )
F_156 = V_207 ;
#endif
return (* F_156)( V_131 ) ;
}
if ( ! F_117 ( V_131 ) ) {
if ( ! F_136 ( V_131 ) )
return 1 ;
}
return 0 ;
}
int F_159 ( struct V_131 * V_131 )
{
int V_39 ;
F_115 ( V_131 ) ;
V_39 = F_80 ( V_131 ) ;
F_116 ( V_131 ) ;
return V_39 ;
}
int F_121 ( struct V_131 * V_131 )
{
struct V_115 * V_116 = F_81 ( V_131 ) ;
F_120 ( ! F_131 ( V_131 ) ) ;
if ( V_116 && F_139 ( V_116 ) ) {
if ( F_160 ( V_131 ) )
F_80 ( V_131 ) ;
if ( F_161 ( V_131 ) ) {
F_152 ( V_131 , V_30 ) ;
F_153 ( V_116 -> V_44 ,
V_127 ) ;
return 1 ;
}
return 0 ;
}
return F_161 ( V_131 ) ;
}
int F_162 ( struct V_131 * V_131 )
{
struct V_115 * V_116 = F_81 ( V_131 ) ;
int V_39 ;
if ( V_116 ) {
struct V_44 * V_45 = V_116 -> V_44 ;
unsigned long V_25 ;
F_163 ( & V_116 -> V_164 , V_25 ) ;
V_39 = F_164 ( V_131 ) ;
if ( V_39 ) {
F_165 ( & V_116 -> V_165 ,
F_149 ( V_131 ) ,
V_208 ) ;
if ( F_166 ( V_45 ) ) {
F_167 ( V_45 , V_128 ) ;
F_27 ( V_45 ) ;
}
}
F_168 ( & V_116 -> V_164 , V_25 ) ;
} else {
V_39 = F_164 ( V_131 ) ;
}
if ( V_39 ) {
F_152 ( V_131 , V_32 ) ;
F_144 ( V_131 , V_209 ) ;
}
return V_39 ;
}
int F_169 ( struct V_131 * V_131 )
{
struct V_115 * V_116 = F_81 ( V_131 ) ;
int V_39 ;
if ( V_116 ) {
struct V_44 * V_45 = V_116 -> V_44 ;
unsigned long V_25 ;
F_163 ( & V_116 -> V_164 , V_25 ) ;
V_39 = F_170 ( V_131 ) ;
if ( ! V_39 ) {
F_148 ( & V_116 -> V_165 ,
F_149 ( V_131 ) ,
V_208 ) ;
if ( F_166 ( V_45 ) )
F_28 ( V_45 , V_128 ) ;
}
if ( ! F_117 ( V_131 ) )
F_165 ( & V_116 -> V_165 ,
F_149 ( V_131 ) ,
V_166 ) ;
F_165 ( & V_116 -> V_165 ,
F_149 ( V_131 ) ,
V_167 ) ;
F_168 ( & V_116 -> V_164 , V_25 ) ;
} else {
V_39 = F_170 ( V_131 ) ;
}
if ( ! V_39 )
F_143 ( V_131 ) ;
return V_39 ;
}
int F_171 ( struct V_115 * V_116 , int V_179 )
{
return F_172 ( & V_116 -> V_165 , V_179 ) ;
}
void F_173 ( struct V_131 * V_131 )
{
struct V_115 * V_116 = F_81 ( V_131 ) ;
struct V_44 * V_45 = V_116 -> V_44 ;
if ( ! F_174 ( V_45 ) )
return;
F_119 ( V_131 ) ;
}
