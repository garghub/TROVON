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
return F_7 ( V_3 , V_1 ) ;
#else
return 0 ;
#endif
}
static unsigned long F_8 ( void )
{
unsigned long V_3 ;
V_3 = F_9 ( V_8 ) + F_10 () -
V_9 ;
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
return F_5 ( V_4 , V_8 ) +
F_6 ( V_4 ) -
V_4 -> V_9 ;
}
static unsigned long F_16 ( struct V_4 * V_4 )
{
unsigned long V_27 = F_15 ( V_4 ) ;
struct V_17 * V_18 = V_24 ;
unsigned long V_14 ;
if ( V_19 )
V_14 = F_12 ( V_19 , V_21 ) *
V_27 / F_8 () ;
else
V_14 = V_22 * V_27 / 100 ;
if ( V_18 -> V_25 & V_26 || F_13 ( V_18 ) )
V_14 += V_14 / 4 ;
return V_14 ;
}
bool F_17 ( struct V_4 * V_4 )
{
unsigned long V_28 = F_16 ( V_4 ) ;
return F_5 ( V_4 , V_29 ) +
F_5 ( V_4 , V_30 ) +
F_5 ( V_4 , V_31 ) <= V_28 ;
}
int F_18 ( struct V_32 * V_33 , int V_34 ,
void T_1 * V_35 , T_2 * V_36 ,
T_3 * V_37 )
{
int V_38 ;
V_38 = F_19 ( V_33 , V_34 , V_35 , V_36 , V_37 ) ;
if ( V_38 == 0 && V_34 )
V_20 = 0 ;
return V_38 ;
}
int F_20 ( struct V_32 * V_33 , int V_34 ,
void T_1 * V_35 , T_2 * V_36 ,
T_3 * V_37 )
{
int V_38 ;
V_38 = F_21 ( V_33 , V_34 , V_35 , V_36 , V_37 ) ;
if ( V_38 == 0 && V_34 )
V_23 = 0 ;
return V_38 ;
}
int F_22 ( struct V_32 * V_33 , int V_34 ,
void T_1 * V_35 , T_2 * V_36 ,
T_3 * V_37 )
{
int V_39 = V_22 ;
int V_38 ;
V_38 = F_19 ( V_33 , V_34 , V_35 , V_36 , V_37 ) ;
if ( V_38 == 0 && V_34 && V_22 != V_39 ) {
F_23 () ;
V_19 = 0 ;
}
return V_38 ;
}
int F_24 ( struct V_32 * V_33 , int V_34 ,
void T_1 * V_35 , T_2 * V_36 ,
T_3 * V_37 )
{
unsigned long V_40 = V_19 ;
int V_38 ;
V_38 = F_21 ( V_33 , V_34 , V_35 , V_36 , V_37 ) ;
if ( V_38 == 0 && V_34 && V_19 != V_40 ) {
F_23 () ;
V_22 = 0 ;
}
return V_38 ;
}
static unsigned long F_25 ( unsigned long V_41 )
{
V_41 += V_42 ;
if ( ! V_41 )
return 1 ;
return V_41 ;
}
static inline void F_26 ( struct V_43 * V_44 )
{
F_27 ( V_44 , V_45 ) ;
F_28 ( & V_46 , & V_44 -> V_47 ,
V_44 -> V_48 ) ;
if ( ! F_29 ( V_49 ) ) {
V_49 = F_25 ( V_50 ) ;
F_30 ( & V_51 , V_49 ) ;
}
}
void F_31 ( struct V_43 * V_44 )
{
unsigned long V_25 ;
F_32 ( V_25 ) ;
F_26 ( V_44 ) ;
F_33 ( V_25 ) ;
}
static void F_34 ( struct V_43 * V_44 ,
long * V_52 , long * V_53 )
{
F_35 ( & V_46 , & V_44 -> V_47 ,
V_52 , V_53 ) ;
}
static void F_36 ( unsigned long V_54 )
{
int V_55 = ( V_50 - V_49 ) /
V_42 ;
if ( F_37 ( & V_46 , V_55 + 1 ) ) {
V_49 = F_25 ( V_49 +
V_55 * V_42 ) ;
F_30 ( & V_51 , V_49 ) ;
} else {
V_49 = 0 ;
}
}
int F_38 ( struct V_43 * V_44 , unsigned int V_56 )
{
int V_38 = 0 ;
F_39 ( & V_57 ) ;
if ( V_56 > V_44 -> V_58 ) {
V_38 = - V_59 ;
} else {
V_56 -= V_44 -> V_56 ;
if ( V_60 + V_56 < 100 ) {
V_60 += V_56 ;
V_44 -> V_56 += V_56 ;
} else {
V_38 = - V_59 ;
}
}
F_40 ( & V_57 ) ;
return V_38 ;
}
int F_41 ( struct V_43 * V_44 , unsigned V_58 )
{
int V_38 = 0 ;
if ( V_58 > 100 )
return - V_59 ;
F_39 ( & V_57 ) ;
if ( V_44 -> V_56 > V_58 ) {
V_38 = - V_59 ;
} else {
V_44 -> V_58 = V_58 ;
V_44 -> V_48 = ( V_61 * V_58 ) / 100 ;
}
F_40 ( & V_57 ) ;
return V_38 ;
}
static unsigned long F_42 ( unsigned long V_62 ,
unsigned long V_63 )
{
return ( V_62 + V_63 ) / 2 ;
}
static unsigned long F_43 ( unsigned long V_62 )
{
return F_44 ( V_62 , V_64 ) ;
}
unsigned long F_45 ( struct V_43 * V_44 , unsigned long V_14 )
{
T_4 V_65 ;
long V_52 , V_53 ;
F_34 ( V_44 , & V_52 , & V_53 ) ;
V_65 = ( V_14 * ( 100 - V_60 ) ) / 100 ;
V_65 *= V_52 ;
F_46 ( V_65 , V_53 ) ;
V_65 += ( V_14 * V_44 -> V_56 ) / 100 ;
if ( V_65 > ( V_14 * V_44 -> V_58 ) / 100 )
V_65 = V_14 * V_44 -> V_58 / 100 ;
return V_65 ;
}
static unsigned long F_47 ( struct V_43 * V_44 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_14 ,
unsigned long V_66 ,
unsigned long V_65 )
{
unsigned long V_67 = V_44 -> V_68 ;
unsigned long V_69 = F_42 ( V_62 , V_63 ) ;
unsigned long V_28 = F_43 ( V_62 ) ;
unsigned long V_70 ;
unsigned long V_71 ;
unsigned long V_72 ;
unsigned long V_73 ;
long long V_74 ;
long V_3 ;
if ( F_29 ( V_14 >= V_28 ) )
return 0 ;
V_71 = ( V_69 + V_28 ) / 2 ;
V_3 = F_48 ( ( V_71 - V_14 ) << V_75 ,
V_28 - V_71 + 1 ) ;
V_74 = V_3 ;
V_74 = V_74 * V_3 >> V_75 ;
V_74 = V_74 * V_3 >> V_75 ;
V_74 += 1 << V_75 ;
if ( F_29 ( V_66 > V_62 ) )
V_66 = V_62 ;
V_66 = F_44 ( V_66 , ( V_28 - V_14 ) / 8 ) ;
V_3 = F_49 ( ( T_4 ) V_66 << 16 , V_62 + 1 ) ;
V_72 = V_71 * ( T_4 ) V_3 >> 16 ;
V_73 = ( V_62 - V_66 + 8 * V_67 ) * ( T_4 ) V_3 >> 16 ;
V_70 = V_72 + V_73 ;
if ( V_65 < V_70 - V_73 / 4 ) {
V_74 = F_49 ( V_74 * ( V_70 - V_65 ) ,
V_70 - V_72 + 1 ) ;
} else
V_74 /= 4 ;
V_70 = V_66 / 2 ;
if ( V_65 < V_70 ) {
if ( V_65 > V_70 / 8 )
V_74 = F_49 ( V_74 * V_70 , V_65 ) ;
else
V_74 *= 8 ;
}
return V_74 ;
}
static void F_50 ( struct V_43 * V_44 ,
unsigned long V_76 ,
unsigned long V_77 )
{
const unsigned long V_78 = F_51 ( 3 * V_79 ) ;
unsigned long V_80 = V_44 -> V_68 ;
unsigned long V_81 = V_44 -> V_82 ;
T_4 V_83 ;
V_83 = V_77 - V_44 -> V_84 ;
V_83 *= V_79 ;
if ( F_29 ( V_76 > V_78 ) ) {
F_46 ( V_83 , V_76 ) ;
V_80 = V_83 ;
goto V_85;
}
V_83 += ( T_4 ) V_44 -> V_82 * ( V_78 - V_76 ) ;
V_83 >>= F_52 ( V_78 ) ;
if ( V_80 > V_81 && V_81 >= ( unsigned long ) V_83 )
V_80 -= ( V_80 - V_81 ) >> 3 ;
if ( V_80 < V_81 && V_81 <= ( unsigned long ) V_83 )
V_80 += ( V_81 - V_80 ) >> 3 ;
V_85:
V_44 -> V_82 = V_83 ;
V_44 -> V_68 = V_80 ;
}
static void F_53 ( unsigned long V_62 , unsigned long V_14 )
{
unsigned long V_28 = V_64 ;
if ( V_28 < V_62 ) {
V_28 = V_62 ;
goto V_86;
}
V_62 = F_44 ( V_62 , V_14 ) ;
if ( V_28 > V_62 ) {
V_28 -= ( V_28 - V_62 ) >> 5 ;
goto V_86;
}
return;
V_86:
V_64 = V_28 ;
}
static void F_54 ( unsigned long V_62 ,
unsigned long V_14 ,
unsigned long V_87 )
{
static F_55 ( V_88 ) ;
static unsigned long V_89 ;
if ( F_56 ( V_87 , V_89 + V_90 ) )
return;
F_57 ( & V_88 ) ;
if ( F_58 ( V_87 , V_89 + V_90 ) ) {
F_53 ( V_62 , V_14 ) ;
V_89 = V_87 ;
}
F_59 ( & V_88 ) ;
}
static void F_60 ( struct V_43 * V_44 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_14 ,
unsigned long V_66 ,
unsigned long V_65 ,
unsigned long V_91 ,
unsigned long V_76 )
{
unsigned long V_69 = F_42 ( V_62 , V_63 ) ;
unsigned long V_28 = F_43 ( V_62 ) ;
unsigned long V_71 = ( V_69 + V_28 ) / 2 ;
unsigned long V_67 = V_44 -> V_68 ;
unsigned long V_92 = V_44 -> V_92 ;
unsigned long V_93 ;
unsigned long V_94 ;
unsigned long V_95 ;
unsigned long V_74 ;
unsigned long V_96 ;
unsigned long V_3 ;
V_93 = ( V_91 - V_44 -> V_97 ) * V_79 / V_76 ;
V_74 = F_47 ( V_44 , V_62 , V_63 , V_14 ,
V_66 , V_65 ) ;
V_94 = ( T_4 ) V_92 *
V_74 >> V_75 ;
V_94 ++ ;
V_95 = F_49 ( ( T_4 ) V_94 * V_67 ,
V_93 | 1 ) ;
if ( F_29 ( V_95 > V_67 ) )
V_95 = V_67 ;
V_96 = 0 ;
if ( V_14 < V_71 ) {
V_3 = F_7 ( V_44 -> V_95 ,
F_7 ( V_95 , V_94 ) ) ;
if ( V_92 < V_3 )
V_96 = V_3 - V_92 ;
} else {
V_3 = F_44 ( V_44 -> V_95 ,
F_44 ( V_95 , V_94 ) ) ;
if ( V_92 > V_3 )
V_96 = V_92 - V_3 ;
}
V_96 >>= V_92 / ( 2 * V_96 + 1 ) ;
V_96 = ( V_96 + 7 ) / 8 ;
if ( V_92 < V_95 )
V_92 += V_96 ;
else
V_92 -= V_96 ;
V_44 -> V_92 = F_44 ( V_92 , 1UL ) ;
V_44 -> V_95 = V_95 ;
F_61 ( V_44 , V_93 , V_94 ) ;
}
void F_62 ( struct V_43 * V_44 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_14 ,
unsigned long V_66 ,
unsigned long V_65 ,
unsigned long V_98 )
{
unsigned long V_87 = V_50 ;
unsigned long V_76 = V_87 - V_44 -> V_99 ;
unsigned long V_91 ;
unsigned long V_77 ;
if ( V_76 < V_90 )
return;
V_91 = F_63 ( & V_44 -> V_100 [ V_101 ] ) ;
V_77 = F_63 ( & V_44 -> V_100 [ V_45 ] ) ;
if ( V_76 > V_79 && F_56 ( V_44 -> V_99 , V_98 ) )
goto V_102;
if ( V_62 ) {
F_54 ( V_62 , V_14 , V_87 ) ;
F_60 ( V_44 , V_62 , V_63 , V_14 ,
V_66 , V_65 ,
V_91 , V_76 ) ;
}
F_50 ( V_44 , V_76 , V_77 ) ;
V_102:
V_44 -> V_97 = V_91 ;
V_44 -> V_84 = V_77 ;
V_44 -> V_99 = V_87 ;
}
static void F_64 ( struct V_43 * V_44 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_14 ,
unsigned long V_66 ,
unsigned long V_65 ,
unsigned long V_98 )
{
if ( F_65 ( V_44 -> V_99 + V_90 ) )
return;
F_57 ( & V_44 -> V_103 . V_104 ) ;
F_62 ( V_44 , V_62 , V_63 , V_14 ,
V_66 , V_65 , V_98 ) ;
F_59 ( & V_44 -> V_103 . V_104 ) ;
}
static unsigned long F_66 ( unsigned long V_14 ,
unsigned long V_62 )
{
if ( V_62 > V_14 )
return 1UL << ( F_52 ( V_62 - V_14 ) >> 1 ) ;
return 1 ;
}
static long F_67 ( struct V_43 * V_44 ,
unsigned long V_65 )
{
long V_83 = V_44 -> V_68 ;
long V_54 ;
V_54 = V_65 / ( 1 + V_83 / F_51 ( 1 + V_79 / 8 ) ) ;
V_54 ++ ;
return F_68 ( long , V_54 , V_105 ) ;
}
static long F_69 ( struct V_43 * V_44 ,
long V_106 ,
unsigned long V_94 ,
unsigned long V_92 ,
int * V_107 )
{
long V_108 = F_52 ( V_44 -> V_68 ) ;
long V_109 = F_52 ( V_44 -> V_92 ) ;
long V_54 ;
long V_110 ;
int V_111 ;
V_54 = F_44 ( 1 , V_79 / 100 ) ;
if ( V_108 > V_109 )
V_54 += ( V_108 - V_109 ) * ( 10 * V_79 ) / 1024 ;
V_54 = F_7 ( V_54 , 1 + V_106 / 2 ) ;
V_111 = V_92 * V_54 / F_51 ( V_79 ) ;
if ( V_111 < V_112 ) {
V_54 = V_106 ;
V_111 = V_92 * V_54 / F_51 ( V_79 ) ;
if ( V_111 > V_112 ) {
V_111 = V_112 ;
V_54 = V_79 * V_112 / V_92 ;
}
}
V_110 = V_79 * V_111 / ( V_94 + 1 ) ;
if ( V_110 > V_106 ) {
V_54 = V_106 ;
V_111 = V_94 * V_54 / F_51 ( V_79 ) ;
}
* V_107 = V_111 ;
return V_111 >= V_112 ? 1 + V_54 / 2 : V_54 ;
}
static void F_70 ( struct V_113 * V_114 ,
unsigned long V_115 )
{
unsigned long V_116 ;
unsigned long V_117 ;
unsigned long V_118 ;
unsigned long V_65 ;
unsigned long V_69 ;
unsigned long V_119 ;
unsigned long V_120 ;
unsigned long V_66 ;
long V_78 ;
long V_110 ;
long V_106 ;
long V_121 ;
int V_107 ;
bool V_122 = false ;
unsigned long V_94 ;
unsigned long V_92 ;
unsigned long V_74 ;
struct V_43 * V_44 = V_114 -> V_43 ;
unsigned long V_98 = V_50 ;
for (; ; ) {
unsigned long V_87 = V_50 ;
V_116 = F_9 ( V_29 ) +
F_9 ( V_30 ) ;
V_118 = V_116 + F_9 ( V_31 ) ;
F_11 ( & V_119 , & V_120 ) ;
V_69 = F_42 ( V_120 ,
V_119 ) ;
if ( V_118 <= V_69 ) {
V_24 -> V_123 = V_87 ;
V_24 -> V_124 = 0 ;
V_24 -> V_107 =
F_66 ( V_118 , V_120 ) ;
break;
}
if ( F_29 ( ! F_71 ( V_44 ) ) )
F_72 ( V_44 ) ;
V_66 = F_45 ( V_44 , V_120 ) ;
if ( V_66 < 2 * F_73 ( V_44 ) ) {
V_117 = F_74 ( V_44 , V_125 ) ;
V_65 = V_117 +
F_74 ( V_44 , V_126 ) ;
} else {
V_117 = V_100 ( V_44 , V_125 ) ;
V_65 = V_117 +
V_100 ( V_44 , V_126 ) ;
}
V_122 = ( V_65 > V_66 ) &&
( V_118 > V_120 ) ;
if ( V_122 && ! V_44 -> V_122 )
V_44 -> V_122 = 1 ;
F_64 ( V_44 , V_120 , V_119 ,
V_118 , V_66 , V_65 ,
V_98 ) ;
V_92 = V_44 -> V_92 ;
V_74 = F_47 ( V_44 , V_120 ,
V_119 , V_118 ,
V_66 , V_65 ) ;
V_94 = ( ( T_4 ) V_92 * V_74 ) >>
V_75 ;
V_106 = F_67 ( V_44 , V_65 ) ;
V_121 = F_69 ( V_44 , V_106 ,
V_94 , V_92 ,
& V_107 ) ;
if ( F_29 ( V_94 == 0 ) ) {
V_78 = V_106 ;
V_110 = V_106 ;
goto V_110;
}
V_78 = V_79 * V_115 / V_94 ;
V_110 = V_78 ;
if ( V_24 -> V_123 )
V_110 -= V_87 - V_24 -> V_123 ;
if ( V_110 < V_121 ) {
F_75 ( V_44 ,
V_120 ,
V_119 ,
V_118 ,
V_66 ,
V_65 ,
V_92 ,
V_94 ,
V_115 ,
V_78 ,
F_7 ( V_110 , 0L ) ,
V_98 ) ;
if ( V_110 < - V_79 ) {
V_24 -> V_123 = V_87 ;
V_24 -> V_124 = 0 ;
} else if ( V_78 ) {
V_24 -> V_123 += V_78 ;
V_24 -> V_124 = 0 ;
} else if ( V_24 -> V_107 <= V_115 )
V_24 -> V_107 += V_115 ;
break;
}
if ( F_29 ( V_110 > V_106 ) ) {
V_87 += F_7 ( V_110 - V_106 , V_106 ) ;
V_110 = V_106 ;
}
V_110:
F_75 ( V_44 ,
V_120 ,
V_119 ,
V_118 ,
V_66 ,
V_65 ,
V_92 ,
V_94 ,
V_115 ,
V_78 ,
V_110 ,
V_98 ) ;
F_76 ( V_127 ) ;
F_77 ( V_110 ) ;
V_24 -> V_123 = V_87 + V_110 ;
V_24 -> V_124 = 0 ;
V_24 -> V_107 = V_107 ;
if ( V_94 )
break;
if ( V_65 <= F_73 ( V_44 ) )
break;
if ( F_78 ( V_24 ) )
break;
}
if ( ! V_122 && V_44 -> V_122 )
V_44 -> V_122 = 0 ;
if ( F_71 ( V_44 ) )
return;
if ( V_128 )
return;
if ( V_116 > V_119 )
F_72 ( V_44 ) ;
}
void F_79 ( struct V_129 * V_129 , int V_130 )
{
if ( F_80 ( V_129 ) || V_130 ) {
struct V_113 * V_114 = F_81 ( V_129 ) ;
if ( V_114 )
F_82 ( V_114 ) ;
}
}
void F_83 ( struct V_113 * V_114 ,
unsigned long V_131 )
{
struct V_43 * V_44 = V_114 -> V_43 ;
int V_132 ;
int * V_133 ;
if ( ! F_84 ( V_44 ) )
return;
V_132 = V_24 -> V_107 ;
if ( V_44 -> V_122 )
V_132 = F_7 ( V_132 , 32 >> ( V_134 - 10 ) ) ;
F_85 () ;
V_133 = & F_86 ( V_135 ) ;
if ( F_29 ( V_24 -> V_124 >= V_132 ) )
* V_133 = 0 ;
else if ( F_29 ( * V_133 >= V_136 ) ) {
* V_133 = 0 ;
V_132 = 0 ;
}
V_133 = & F_86 ( V_137 ) ;
if ( * V_133 > 0 && V_24 -> V_124 < V_132 ) {
V_131 = F_7 ( * V_133 , V_132 - V_24 -> V_124 ) ;
* V_133 -= V_131 ;
V_24 -> V_124 += V_131 ;
}
F_87 () ;
if ( F_29 ( V_24 -> V_124 >= V_132 ) )
F_70 ( V_114 , V_24 -> V_124 ) ;
}
void F_88 ( T_5 V_138 )
{
unsigned long V_119 ;
unsigned long V_120 ;
for ( ; ; ) {
F_11 ( & V_119 , & V_120 ) ;
V_120 = F_43 ( V_120 ) ;
V_120 += V_120 / 10 ;
if ( F_9 ( V_30 ) +
F_9 ( V_31 ) <= V_120 )
break;
F_89 ( V_139 , V_79 / 10 ) ;
if ( ( V_138 & ( V_140 | V_141 ) ) != ( V_140 | V_141 ) )
break;
}
}
int F_90 ( V_32 * V_33 , int V_34 ,
void T_1 * V_35 , T_2 * V_142 , T_3 * V_37 )
{
F_91 ( V_33 , V_34 , V_35 , V_142 , V_37 ) ;
return 0 ;
}
void F_92 ( unsigned long V_143 )
{
struct V_144 * V_145 = (struct V_144 * ) V_143 ;
int V_146 = F_9 ( V_29 ) +
F_9 ( V_30 ) ;
if ( F_93 ( & V_145 -> V_43 ) )
F_94 ( & V_145 -> V_43 , V_146 ,
V_147 ) ;
}
void F_95 ( struct V_43 * V_148 )
{
F_30 ( & V_148 -> V_149 , V_50 + V_128 ) ;
}
void F_96 ( void )
{
struct V_43 * V_44 ;
F_97 () ;
F_98 (bdi, &bdi_list, bdi_list)
F_99 ( & V_44 -> V_149 ) ;
F_100 () ;
}
void F_23 ( void )
{
unsigned long V_119 ;
unsigned long V_120 ;
F_11 ( & V_119 , & V_120 ) ;
V_64 = V_120 ;
V_136 = V_120 / ( F_101 () * 32 ) ;
if ( V_136 < 16 )
V_136 = 16 ;
}
static int T_6
F_102 ( struct V_150 * V_151 , unsigned long V_152 ,
void * V_153 )
{
switch ( V_152 & ~ V_154 ) {
case V_155 :
case V_156 :
F_23 () ;
return V_157 ;
default:
return V_158 ;
}
}
void T_7 F_103 ( void )
{
F_23 () ;
F_104 ( & V_159 ) ;
F_105 ( & V_46 ) ;
}
void F_106 ( struct V_113 * V_114 ,
T_8 V_160 , T_8 V_161 )
{
#define F_107 4096
unsigned long V_162 ;
do {
F_108 ( & V_114 -> V_163 ) ;
V_162 = F_109 ( & V_114 -> V_164 ,
& V_160 , V_161 , F_107 ,
V_165 , V_166 ) ;
F_110 ( & V_114 -> V_163 ) ;
F_111 ( V_162 > F_107 ) ;
F_112 () ;
} while ( V_162 >= F_107 && V_160 );
}
int F_113 ( struct V_113 * V_114 ,
struct V_167 * V_168 , T_9 V_169 ,
void * V_143 )
{
int V_38 = 0 ;
int V_170 = 0 ;
struct V_171 V_172 ;
int V_146 ;
T_8 V_15 ( V_173 ) ;
T_8 V_174 ;
T_8 V_161 ;
T_8 V_175 ;
int V_176 ;
int V_177 = 0 ;
int V_178 ;
F_114 ( & V_172 , 0 ) ;
if ( V_168 -> V_179 ) {
V_173 = V_114 -> V_173 ;
V_174 = V_173 ;
if ( V_174 == 0 )
V_176 = 1 ;
else
V_176 = 0 ;
V_161 = - 1 ;
} else {
V_174 = V_168 -> V_180 >> V_181 ;
V_161 = V_168 -> V_182 >> V_181 ;
if ( V_168 -> V_180 == 0 && V_168 -> V_182 == V_183 )
V_177 = 1 ;
V_176 = 1 ;
}
if ( V_168 -> V_184 == V_185 || V_168 -> V_186 )
V_178 = V_166 ;
else
V_178 = V_165 ;
V_187:
if ( V_168 -> V_184 == V_185 || V_168 -> V_186 )
F_106 ( V_114 , V_174 , V_161 ) ;
V_175 = V_174 ;
while ( ! V_170 && ( V_174 <= V_161 ) ) {
int V_188 ;
V_146 = F_115 ( & V_172 , V_114 , & V_174 , V_178 ,
F_7 ( V_161 - V_174 , ( T_8 ) V_189 - 1 ) + 1 ) ;
if ( V_146 == 0 )
break;
for ( V_188 = 0 ; V_188 < V_146 ; V_188 ++ ) {
struct V_129 * V_129 = V_172 . V_111 [ V_188 ] ;
if ( V_129 -> V_174 > V_161 ) {
V_170 = 1 ;
break;
}
V_175 = V_129 -> V_174 ;
F_116 ( V_129 ) ;
if ( F_29 ( V_129 -> V_114 != V_114 ) ) {
V_190:
F_117 ( V_129 ) ;
continue;
}
if ( ! F_118 ( V_129 ) ) {
goto V_190;
}
if ( F_119 ( V_129 ) ) {
if ( V_168 -> V_184 != V_191 )
F_120 ( V_129 ) ;
else
goto V_190;
}
F_121 ( F_119 ( V_129 ) ) ;
if ( ! F_122 ( V_129 ) )
goto V_190;
F_123 ( V_168 , V_114 -> V_43 ) ;
V_38 = (* V_169)( V_129 , V_168 , V_143 ) ;
if ( F_29 ( V_38 ) ) {
if ( V_38 == V_192 ) {
F_117 ( V_129 ) ;
V_38 = 0 ;
} else {
V_175 = V_129 -> V_174 + 1 ;
V_170 = 1 ;
break;
}
}
if ( -- V_168 -> V_193 <= 0 &&
V_168 -> V_184 == V_191 ) {
V_170 = 1 ;
break;
}
}
F_124 ( & V_172 ) ;
F_112 () ;
}
if ( ! V_176 && ! V_170 ) {
V_176 = 1 ;
V_174 = 0 ;
V_161 = V_173 - 1 ;
goto V_187;
}
if ( V_168 -> V_179 || ( V_177 && V_168 -> V_193 > 0 ) )
V_114 -> V_173 = V_175 ;
return V_38 ;
}
static int F_125 ( struct V_129 * V_129 , struct V_167 * V_168 ,
void * V_143 )
{
struct V_113 * V_114 = V_143 ;
int V_38 = V_114 -> V_194 -> V_169 ( V_129 , V_168 ) ;
F_126 ( V_114 , V_38 ) ;
return V_38 ;
}
int F_127 ( struct V_113 * V_114 ,
struct V_167 * V_168 )
{
struct V_195 V_196 ;
int V_38 ;
if ( ! V_114 -> V_194 -> V_169 )
return 0 ;
F_128 ( & V_196 ) ;
V_38 = F_113 ( V_114 , V_168 , F_125 , V_114 ) ;
F_129 ( & V_196 ) ;
return V_38 ;
}
int F_130 ( struct V_113 * V_114 , struct V_167 * V_168 )
{
int V_38 ;
if ( V_168 -> V_193 <= 0 )
return 0 ;
if ( V_114 -> V_194 -> V_197 )
V_38 = V_114 -> V_194 -> V_197 ( V_114 , V_168 ) ;
else
V_38 = F_127 ( V_114 , V_168 ) ;
return V_38 ;
}
int F_131 ( struct V_129 * V_129 , int V_198 )
{
struct V_113 * V_114 = V_129 -> V_114 ;
int V_38 = 0 ;
struct V_167 V_168 = {
. V_184 = V_185 ,
. V_193 = 1 ,
} ;
F_121 ( ! F_132 ( V_129 ) ) ;
if ( V_198 )
F_120 ( V_129 ) ;
if ( F_122 ( V_129 ) ) {
F_133 ( V_129 ) ;
V_38 = V_114 -> V_194 -> V_169 ( V_129 , & V_168 ) ;
if ( V_38 == 0 && V_198 ) {
F_120 ( V_129 ) ;
if ( F_134 ( V_129 ) )
V_38 = - V_199 ;
}
F_135 ( V_129 ) ;
} else {
F_117 ( V_129 ) ;
}
return V_38 ;
}
int F_136 ( struct V_129 * V_129 )
{
if ( ! F_118 ( V_129 ) )
return ! F_137 ( V_129 ) ;
return 0 ;
}
void F_138 ( struct V_129 * V_129 , struct V_113 * V_114 )
{
if ( F_139 ( V_114 ) ) {
F_140 ( V_129 , V_29 ) ;
F_140 ( V_129 , V_200 ) ;
F_27 ( V_114 -> V_43 , V_125 ) ;
F_27 ( V_114 -> V_43 , V_101 ) ;
F_141 ( V_201 ) ;
V_24 -> V_124 ++ ;
F_142 ( V_135 ) ;
}
}
void F_143 ( struct V_129 * V_129 )
{
F_144 ( V_129 , V_31 ) ;
}
int F_145 ( struct V_129 * V_129 )
{
if ( ! F_137 ( V_129 ) ) {
struct V_113 * V_114 = F_81 ( V_129 ) ;
struct V_113 * V_202 ;
if ( ! V_114 )
return 1 ;
F_108 ( & V_114 -> V_163 ) ;
V_202 = F_81 ( V_129 ) ;
if ( V_202 ) {
F_121 ( V_202 != V_114 ) ;
F_111 ( ! F_146 ( V_129 ) && ! F_147 ( V_129 ) ) ;
F_138 ( V_129 , V_114 ) ;
F_148 ( & V_114 -> V_164 ,
F_149 ( V_129 ) , V_165 ) ;
}
F_110 ( & V_114 -> V_163 ) ;
if ( V_114 -> V_203 ) {
F_150 ( V_114 -> V_203 , V_204 ) ;
}
return 1 ;
}
return 0 ;
}
void F_151 ( struct V_129 * V_129 )
{
struct V_113 * V_114 = V_129 -> V_114 ;
if ( V_114 && F_139 ( V_114 ) ) {
V_24 -> V_124 -- ;
F_152 ( V_129 , V_200 ) ;
F_153 ( V_114 -> V_43 , V_101 ) ;
}
}
int F_154 ( struct V_167 * V_168 , struct V_129 * V_129 )
{
V_168 -> V_205 ++ ;
F_151 ( V_129 ) ;
return F_145 ( V_129 ) ;
}
int F_80 ( struct V_129 * V_129 )
{
struct V_113 * V_114 = F_81 ( V_129 ) ;
if ( F_155 ( V_114 ) ) {
int (* F_156)( struct V_129 * ) = V_114 -> V_194 -> F_80 ;
F_157 ( V_129 ) ;
#ifdef F_158
if ( ! F_156 )
F_156 = V_206 ;
#endif
return (* F_156)( V_129 ) ;
}
if ( ! F_118 ( V_129 ) ) {
if ( ! F_137 ( V_129 ) )
return 1 ;
}
return 0 ;
}
int F_159 ( struct V_129 * V_129 )
{
int V_38 ;
F_116 ( V_129 ) ;
V_38 = F_80 ( V_129 ) ;
F_117 ( V_129 ) ;
return V_38 ;
}
int F_122 ( struct V_129 * V_129 )
{
struct V_113 * V_114 = F_81 ( V_129 ) ;
F_121 ( ! F_132 ( V_129 ) ) ;
if ( V_114 && F_139 ( V_114 ) ) {
if ( F_160 ( V_129 ) )
F_80 ( V_129 ) ;
if ( F_161 ( V_129 ) ) {
F_152 ( V_129 , V_29 ) ;
F_153 ( V_114 -> V_43 ,
V_125 ) ;
return 1 ;
}
return 0 ;
}
return F_161 ( V_129 ) ;
}
int F_162 ( struct V_129 * V_129 )
{
struct V_113 * V_114 = F_81 ( V_129 ) ;
int V_38 ;
if ( V_114 ) {
struct V_43 * V_44 = V_114 -> V_43 ;
unsigned long V_25 ;
F_163 ( & V_114 -> V_163 , V_25 ) ;
V_38 = F_164 ( V_129 ) ;
if ( V_38 ) {
F_165 ( & V_114 -> V_164 ,
F_149 ( V_129 ) ,
V_207 ) ;
if ( F_166 ( V_44 ) ) {
F_167 ( V_44 , V_126 ) ;
F_26 ( V_44 ) ;
}
}
F_168 ( & V_114 -> V_163 , V_25 ) ;
} else {
V_38 = F_164 ( V_129 ) ;
}
if ( V_38 ) {
F_152 ( V_129 , V_31 ) ;
F_144 ( V_129 , V_208 ) ;
}
return V_38 ;
}
int F_169 ( struct V_129 * V_129 )
{
struct V_113 * V_114 = F_81 ( V_129 ) ;
int V_38 ;
if ( V_114 ) {
struct V_43 * V_44 = V_114 -> V_43 ;
unsigned long V_25 ;
F_163 ( & V_114 -> V_163 , V_25 ) ;
V_38 = F_170 ( V_129 ) ;
if ( ! V_38 ) {
F_148 ( & V_114 -> V_164 ,
F_149 ( V_129 ) ,
V_207 ) ;
if ( F_166 ( V_44 ) )
F_27 ( V_44 , V_126 ) ;
}
if ( ! F_118 ( V_129 ) )
F_165 ( & V_114 -> V_164 ,
F_149 ( V_129 ) ,
V_165 ) ;
F_165 ( & V_114 -> V_164 ,
F_149 ( V_129 ) ,
V_166 ) ;
F_168 ( & V_114 -> V_163 , V_25 ) ;
} else {
V_38 = F_170 ( V_129 ) ;
}
if ( ! V_38 )
F_143 ( V_129 ) ;
return V_38 ;
}
int F_171 ( struct V_113 * V_114 , int V_178 )
{
return F_172 ( & V_114 -> V_164 , V_178 ) ;
}
