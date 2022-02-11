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
unsigned long F_8 ( void )
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
static int F_18 ( void )
{
unsigned long V_32 ;
if ( V_19 )
V_32 = V_19 / V_21 ;
else
V_32 = ( V_22 * F_8 () ) /
100 ;
return 2 + F_19 ( V_32 - 1 ) ;
}
static void F_20 ( void )
{
int V_33 = F_18 () ;
F_21 ( & V_34 , V_33 ) ;
F_22 () ;
}
int F_23 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
int V_41 ;
V_41 = F_24 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 )
V_20 = 0 ;
return V_41 ;
}
int F_25 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
int V_41 ;
V_41 = F_26 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 )
V_23 = 0 ;
return V_41 ;
}
int F_27 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
int V_42 = V_22 ;
int V_41 ;
V_41 = F_24 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 && V_22 != V_42 ) {
F_20 () ;
V_19 = 0 ;
}
return V_41 ;
}
int F_28 ( struct V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_39 ,
T_3 * V_40 )
{
unsigned long V_43 = V_19 ;
int V_41 ;
V_41 = F_26 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 == 0 && V_37 && V_19 != V_43 ) {
F_20 () ;
V_22 = 0 ;
}
return V_41 ;
}
static inline void F_29 ( struct V_44 * V_45 )
{
F_30 ( V_45 , V_46 ) ;
F_31 ( & V_34 , & V_45 -> V_47 ,
V_45 -> V_48 ) ;
}
void F_32 ( struct V_44 * V_45 )
{
unsigned long V_25 ;
F_33 ( V_25 ) ;
F_29 ( V_45 ) ;
F_34 ( V_25 ) ;
}
static void F_35 ( struct V_44 * V_45 ,
long * V_49 , long * V_50 )
{
F_36 ( & V_34 , & V_45 -> V_47 ,
V_49 , V_50 ) ;
}
int F_37 ( struct V_44 * V_45 , unsigned int V_51 )
{
int V_41 = 0 ;
F_38 ( & V_52 ) ;
if ( V_51 > V_45 -> V_53 ) {
V_41 = - V_54 ;
} else {
V_51 -= V_45 -> V_51 ;
if ( V_55 + V_51 < 100 ) {
V_55 += V_51 ;
V_45 -> V_51 += V_51 ;
} else {
V_41 = - V_54 ;
}
}
F_39 ( & V_52 ) ;
return V_41 ;
}
int F_40 ( struct V_44 * V_45 , unsigned V_53 )
{
int V_41 = 0 ;
if ( V_53 > 100 )
return - V_54 ;
F_38 ( & V_52 ) ;
if ( V_45 -> V_51 > V_53 ) {
V_41 = - V_54 ;
} else {
V_45 -> V_53 = V_53 ;
V_45 -> V_48 = ( V_56 * V_53 ) / 100 ;
}
F_39 ( & V_52 ) ;
return V_41 ;
}
static unsigned long F_41 ( unsigned long V_57 ,
unsigned long V_58 )
{
return ( V_57 + V_58 ) / 2 ;
}
static unsigned long F_42 ( unsigned long V_57 )
{
return F_43 ( V_57 , V_59 ) ;
}
unsigned long F_44 ( struct V_44 * V_45 , unsigned long V_14 )
{
T_4 V_60 ;
long V_49 , V_50 ;
F_35 ( V_45 , & V_49 , & V_50 ) ;
V_60 = ( V_14 * ( 100 - V_55 ) ) / 100 ;
V_60 *= V_49 ;
F_45 ( V_60 , V_50 ) ;
V_60 += ( V_14 * V_45 -> V_51 ) / 100 ;
if ( V_60 > ( V_14 * V_45 -> V_53 ) / 100 )
V_60 = V_14 * V_45 -> V_53 / 100 ;
return V_60 ;
}
static unsigned long F_46 ( struct V_44 * V_45 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned long V_14 ,
unsigned long V_61 ,
unsigned long V_60 )
{
unsigned long V_62 = V_45 -> V_63 ;
unsigned long V_64 = F_41 ( V_57 , V_58 ) ;
unsigned long V_28 = F_42 ( V_57 ) ;
unsigned long V_65 ;
unsigned long V_66 ;
unsigned long V_67 ;
unsigned long V_68 ;
long long V_69 ;
long V_3 ;
if ( F_47 ( V_14 >= V_28 ) )
return 0 ;
V_66 = ( V_64 + V_28 ) / 2 ;
V_3 = F_48 ( ( V_66 - V_14 ) << V_70 ,
V_28 - V_66 + 1 ) ;
V_69 = V_3 ;
V_69 = V_69 * V_3 >> V_70 ;
V_69 = V_69 * V_3 >> V_70 ;
V_69 += 1 << V_70 ;
if ( F_47 ( V_61 > V_57 ) )
V_61 = V_57 ;
V_61 = F_43 ( V_61 , ( V_28 - V_14 ) / 8 ) ;
V_3 = F_49 ( ( T_4 ) V_61 << 16 , V_57 + 1 ) ;
V_67 = V_66 * ( T_4 ) V_3 >> 16 ;
V_68 = ( V_57 - V_61 + 8 * V_62 ) * ( T_4 ) V_3 >> 16 ;
V_65 = V_67 + V_68 ;
if ( V_60 < V_65 - V_68 / 4 ) {
V_69 = F_49 ( V_69 * ( V_65 - V_60 ) ,
V_65 - V_67 + 1 ) ;
} else
V_69 /= 4 ;
V_65 = V_61 / 2 ;
if ( V_60 < V_65 ) {
if ( V_60 > V_65 / 8 )
V_69 = F_49 ( V_69 * V_65 , V_60 ) ;
else
V_69 *= 8 ;
}
return V_69 ;
}
static void F_50 ( struct V_44 * V_45 ,
unsigned long V_71 ,
unsigned long V_72 )
{
const unsigned long V_73 = F_51 ( 3 * V_74 ) ;
unsigned long V_75 = V_45 -> V_63 ;
unsigned long V_76 = V_45 -> V_77 ;
T_4 V_78 ;
V_78 = V_72 - V_45 -> V_79 ;
V_78 *= V_74 ;
if ( F_47 ( V_71 > V_73 ) ) {
F_45 ( V_78 , V_71 ) ;
V_75 = V_78 ;
goto V_80;
}
V_78 += ( T_4 ) V_45 -> V_77 * ( V_73 - V_71 ) ;
V_78 >>= F_19 ( V_73 ) ;
if ( V_75 > V_76 && V_76 >= ( unsigned long ) V_78 )
V_75 -= ( V_75 - V_76 ) >> 3 ;
if ( V_75 < V_76 && V_76 <= ( unsigned long ) V_78 )
V_75 += ( V_76 - V_75 ) >> 3 ;
V_80:
V_45 -> V_77 = V_78 ;
V_45 -> V_63 = V_75 ;
}
static void F_52 ( unsigned long V_57 , unsigned long V_14 )
{
unsigned long V_28 = V_59 ;
if ( V_28 < V_57 ) {
V_28 = V_57 ;
goto V_81;
}
V_57 = F_43 ( V_57 , V_14 ) ;
if ( V_28 > V_57 ) {
V_28 -= ( V_28 - V_57 ) >> 5 ;
goto V_81;
}
return;
V_81:
V_59 = V_28 ;
}
static void F_53 ( unsigned long V_57 ,
unsigned long V_14 ,
unsigned long V_82 )
{
static F_54 ( V_83 ) ;
static unsigned long V_84 ;
if ( F_55 ( V_82 , V_84 + V_85 ) )
return;
F_56 ( & V_83 ) ;
if ( F_57 ( V_82 , V_84 + V_85 ) ) {
F_52 ( V_57 , V_14 ) ;
V_84 = V_82 ;
}
F_58 ( & V_83 ) ;
}
static void F_59 ( struct V_44 * V_45 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned long V_14 ,
unsigned long V_61 ,
unsigned long V_60 ,
unsigned long V_86 ,
unsigned long V_71 )
{
unsigned long V_64 = F_41 ( V_57 , V_58 ) ;
unsigned long V_28 = F_42 ( V_57 ) ;
unsigned long V_66 = ( V_64 + V_28 ) / 2 ;
unsigned long V_62 = V_45 -> V_63 ;
unsigned long V_87 = V_45 -> V_87 ;
unsigned long V_88 ;
unsigned long V_89 ;
unsigned long V_90 ;
unsigned long V_69 ;
unsigned long V_91 ;
unsigned long V_3 ;
V_88 = ( V_86 - V_45 -> V_92 ) * V_74 / V_71 ;
V_69 = F_46 ( V_45 , V_57 , V_58 , V_14 ,
V_61 , V_60 ) ;
V_89 = ( T_4 ) V_87 *
V_69 >> V_70 ;
V_89 ++ ;
V_90 = F_49 ( ( T_4 ) V_89 * V_62 ,
V_88 | 1 ) ;
if ( F_47 ( V_90 > V_62 ) )
V_90 = V_62 ;
V_91 = 0 ;
if ( V_14 < V_66 ) {
V_3 = F_7 ( V_45 -> V_90 ,
F_7 ( V_90 , V_89 ) ) ;
if ( V_87 < V_3 )
V_91 = V_3 - V_87 ;
} else {
V_3 = F_43 ( V_45 -> V_90 ,
F_43 ( V_90 , V_89 ) ) ;
if ( V_87 > V_3 )
V_91 = V_87 - V_3 ;
}
V_91 >>= V_87 / ( 2 * V_91 + 1 ) ;
V_91 = ( V_91 + 7 ) / 8 ;
if ( V_87 < V_90 )
V_87 += V_91 ;
else
V_87 -= V_91 ;
V_45 -> V_87 = F_43 ( V_87 , 1UL ) ;
V_45 -> V_90 = V_90 ;
F_60 ( V_45 , V_88 , V_89 ) ;
}
void F_61 ( struct V_44 * V_45 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned long V_14 ,
unsigned long V_61 ,
unsigned long V_60 ,
unsigned long V_93 )
{
unsigned long V_82 = V_94 ;
unsigned long V_71 = V_82 - V_45 -> V_95 ;
unsigned long V_86 ;
unsigned long V_72 ;
if ( V_71 < V_85 )
return;
V_86 = F_62 ( & V_45 -> V_96 [ V_97 ] ) ;
V_72 = F_62 ( & V_45 -> V_96 [ V_46 ] ) ;
if ( V_71 > V_74 && F_55 ( V_45 -> V_95 , V_93 ) )
goto V_98;
if ( V_57 ) {
F_53 ( V_57 , V_14 , V_82 ) ;
F_59 ( V_45 , V_57 , V_58 , V_14 ,
V_61 , V_60 ,
V_86 , V_71 ) ;
}
F_50 ( V_45 , V_71 , V_72 ) ;
V_98:
V_45 -> V_92 = V_86 ;
V_45 -> V_79 = V_72 ;
V_45 -> V_95 = V_82 ;
}
static void F_63 ( struct V_44 * V_45 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned long V_14 ,
unsigned long V_61 ,
unsigned long V_60 ,
unsigned long V_93 )
{
if ( F_64 ( V_45 -> V_95 + V_85 ) )
return;
F_56 ( & V_45 -> V_99 . V_100 ) ;
F_61 ( V_45 , V_57 , V_58 , V_14 ,
V_61 , V_60 , V_93 ) ;
F_58 ( & V_45 -> V_99 . V_100 ) ;
}
static unsigned long F_65 ( unsigned long V_14 ,
unsigned long V_57 )
{
if ( V_57 > V_14 )
return 1UL << ( F_19 ( V_57 - V_14 ) >> 1 ) ;
return 1 ;
}
static long F_66 ( struct V_44 * V_45 ,
unsigned long V_60 )
{
long V_78 = V_45 -> V_63 ;
long V_101 ;
V_101 = V_60 / ( 1 + V_78 / F_51 ( 1 + V_74 / 8 ) ) ;
V_101 ++ ;
return F_67 ( long , V_101 , V_102 ) ;
}
static long F_68 ( struct V_44 * V_45 ,
long V_103 ,
unsigned long V_89 ,
unsigned long V_87 ,
int * V_104 )
{
long V_105 = F_19 ( V_45 -> V_63 ) ;
long V_106 = F_19 ( V_45 -> V_87 ) ;
long V_101 ;
long V_107 ;
int V_108 ;
V_101 = F_43 ( 1 , V_74 / 100 ) ;
if ( V_105 > V_106 )
V_101 += ( V_105 - V_106 ) * ( 10 * V_74 ) / 1024 ;
V_101 = F_7 ( V_101 , 1 + V_103 / 2 ) ;
V_108 = V_87 * V_101 / F_51 ( V_74 ) ;
if ( V_108 < V_109 ) {
V_101 = V_103 ;
V_108 = V_87 * V_101 / F_51 ( V_74 ) ;
if ( V_108 > V_109 ) {
V_108 = V_109 ;
V_101 = V_74 * V_109 / V_87 ;
}
}
V_107 = V_74 * V_108 / ( V_89 + 1 ) ;
if ( V_107 > V_103 ) {
V_101 = V_103 ;
V_108 = V_89 * V_101 / F_51 ( V_74 ) ;
}
* V_104 = V_108 ;
return V_108 >= V_109 ? 1 + V_101 / 2 : V_101 ;
}
static void F_69 ( struct V_110 * V_111 ,
unsigned long V_112 )
{
unsigned long V_113 ;
unsigned long V_114 ;
unsigned long V_115 ;
unsigned long V_60 ;
unsigned long V_64 ;
unsigned long V_116 ;
unsigned long V_117 ;
unsigned long V_61 ;
long V_73 ;
long V_107 ;
long V_103 ;
long V_118 ;
int V_104 ;
bool V_119 = false ;
unsigned long V_89 ;
unsigned long V_87 ;
unsigned long V_69 ;
struct V_44 * V_45 = V_111 -> V_44 ;
unsigned long V_93 = V_94 ;
for (; ; ) {
unsigned long V_82 = V_94 ;
V_113 = F_9 ( V_29 ) +
F_9 ( V_30 ) ;
V_115 = V_113 + F_9 ( V_31 ) ;
F_11 ( & V_116 , & V_117 ) ;
V_64 = F_41 ( V_117 ,
V_116 ) ;
if ( V_115 <= V_64 ) {
V_24 -> V_120 = V_82 ;
V_24 -> V_121 = 0 ;
V_24 -> V_104 =
F_65 ( V_115 , V_117 ) ;
break;
}
if ( F_47 ( ! F_70 ( V_45 ) ) )
F_71 ( V_45 ) ;
V_61 = F_44 ( V_45 , V_117 ) ;
if ( V_61 < 2 * F_72 ( V_45 ) ) {
V_114 = F_73 ( V_45 , V_122 ) ;
V_60 = V_114 +
F_73 ( V_45 , V_123 ) ;
} else {
V_114 = V_96 ( V_45 , V_122 ) ;
V_60 = V_114 +
V_96 ( V_45 , V_123 ) ;
}
V_119 = ( V_60 > V_61 ) &&
( V_115 > V_117 ) ;
if ( V_119 && ! V_45 -> V_119 )
V_45 -> V_119 = 1 ;
F_63 ( V_45 , V_117 , V_116 ,
V_115 , V_61 , V_60 ,
V_93 ) ;
V_87 = V_45 -> V_87 ;
V_69 = F_46 ( V_45 , V_117 ,
V_116 , V_115 ,
V_61 , V_60 ) ;
V_89 = ( ( T_4 ) V_87 * V_69 ) >>
V_70 ;
V_103 = F_66 ( V_45 , V_60 ) ;
V_118 = F_68 ( V_45 , V_103 ,
V_89 , V_87 ,
& V_104 ) ;
if ( F_47 ( V_89 == 0 ) ) {
V_73 = V_103 ;
V_107 = V_103 ;
goto V_107;
}
V_73 = V_74 * V_112 / V_89 ;
V_107 = V_73 ;
if ( V_24 -> V_120 )
V_107 -= V_82 - V_24 -> V_120 ;
if ( V_107 < V_118 ) {
F_74 ( V_45 ,
V_117 ,
V_116 ,
V_115 ,
V_61 ,
V_60 ,
V_87 ,
V_89 ,
V_112 ,
V_73 ,
F_7 ( V_107 , 0L ) ,
V_93 ) ;
if ( V_107 < - V_74 ) {
V_24 -> V_120 = V_82 ;
V_24 -> V_121 = 0 ;
} else if ( V_73 ) {
V_24 -> V_120 += V_73 ;
V_24 -> V_121 = 0 ;
} else if ( V_24 -> V_104 <= V_112 )
V_24 -> V_104 += V_112 ;
break;
}
if ( F_47 ( V_107 > V_103 ) ) {
V_82 += F_7 ( V_107 - V_103 , V_103 ) ;
V_107 = V_103 ;
}
V_107:
F_74 ( V_45 ,
V_117 ,
V_116 ,
V_115 ,
V_61 ,
V_60 ,
V_87 ,
V_89 ,
V_112 ,
V_73 ,
V_107 ,
V_93 ) ;
F_75 ( V_124 ) ;
F_76 ( V_107 ) ;
V_24 -> V_120 = V_82 + V_107 ;
V_24 -> V_121 = 0 ;
V_24 -> V_104 = V_104 ;
if ( V_89 )
break;
if ( V_60 <= F_72 ( V_45 ) )
break;
if ( F_77 ( V_24 ) )
break;
}
if ( ! V_119 && V_45 -> V_119 )
V_45 -> V_119 = 0 ;
if ( F_70 ( V_45 ) )
return;
if ( V_125 )
return;
if ( V_113 > V_116 )
F_71 ( V_45 ) ;
}
void F_78 ( struct V_126 * V_126 , int V_127 )
{
if ( F_79 ( V_126 ) || V_127 ) {
struct V_110 * V_111 = F_80 ( V_126 ) ;
if ( V_111 )
F_81 ( V_111 ) ;
}
}
void F_82 ( struct V_110 * V_111 ,
unsigned long V_128 )
{
struct V_44 * V_45 = V_111 -> V_44 ;
int V_129 ;
int * V_130 ;
if ( ! F_83 ( V_45 ) )
return;
V_129 = V_24 -> V_104 ;
if ( V_45 -> V_119 )
V_129 = F_7 ( V_129 , 32 >> ( V_131 - 10 ) ) ;
F_84 () ;
V_130 = & F_85 ( V_132 ) ;
if ( F_47 ( V_24 -> V_121 >= V_129 ) )
* V_130 = 0 ;
else if ( F_47 ( * V_130 >= V_133 ) ) {
* V_130 = 0 ;
V_129 = 0 ;
}
V_130 = & F_85 ( V_134 ) ;
if ( * V_130 > 0 && V_24 -> V_121 < V_129 ) {
V_128 = F_7 ( * V_130 , V_129 - V_24 -> V_121 ) ;
* V_130 -= V_128 ;
V_24 -> V_121 += V_128 ;
}
F_86 () ;
if ( F_47 ( V_24 -> V_121 >= V_129 ) )
F_69 ( V_111 , V_24 -> V_121 ) ;
}
void F_87 ( T_5 V_135 )
{
unsigned long V_116 ;
unsigned long V_117 ;
for ( ; ; ) {
F_11 ( & V_116 , & V_117 ) ;
V_117 += V_117 / 10 ;
if ( F_9 ( V_30 ) +
F_9 ( V_31 ) <= V_117 )
break;
F_88 ( V_136 , V_74 / 10 ) ;
if ( ( V_135 & ( V_137 | V_138 ) ) != ( V_137 | V_138 ) )
break;
}
}
int F_89 ( V_35 * V_36 , int V_37 ,
void T_1 * V_38 , T_2 * V_139 , T_3 * V_40 )
{
F_90 ( V_36 , V_37 , V_38 , V_139 , V_40 ) ;
F_91 () ;
return 0 ;
}
void F_92 ( unsigned long V_140 )
{
struct V_141 * V_142 = (struct V_141 * ) V_140 ;
int V_143 = F_9 ( V_29 ) +
F_9 ( V_30 ) ;
if ( F_93 ( & V_142 -> V_44 ) )
F_94 ( & V_142 -> V_44 , V_143 ,
V_144 ) ;
}
void F_95 ( struct V_44 * V_145 )
{
F_96 ( & V_145 -> V_146 , V_94 + V_125 ) ;
}
void F_97 ( void )
{
struct V_44 * V_45 ;
F_98 () ;
F_99 (bdi, &bdi_list, bdi_list)
F_100 ( & V_45 -> V_146 ) ;
F_101 () ;
}
void F_22 ( void )
{
unsigned long V_116 ;
unsigned long V_117 ;
F_11 ( & V_116 , & V_117 ) ;
V_133 = V_117 / ( F_102 () * 32 ) ;
if ( V_133 < 16 )
V_133 = 16 ;
}
static int T_6
F_103 ( struct V_147 * V_148 , unsigned long V_149 , void * V_150 )
{
F_22 () ;
return V_151 ;
}
void T_7 F_104 ( void )
{
int V_33 ;
F_22 () ;
F_105 ( & V_152 ) ;
V_33 = F_18 () ;
F_106 ( & V_34 , V_33 ) ;
}
void F_107 ( struct V_110 * V_111 ,
T_8 V_153 , T_8 V_154 )
{
#define F_108 4096
unsigned long V_155 ;
do {
F_109 ( & V_111 -> V_156 ) ;
V_155 = F_110 ( & V_111 -> V_157 ,
& V_153 , V_154 , F_108 ,
V_158 , V_159 ) ;
F_111 ( & V_111 -> V_156 ) ;
F_112 ( V_155 > F_108 ) ;
F_113 () ;
} while ( V_155 >= F_108 && V_153 );
}
int F_114 ( struct V_110 * V_111 ,
struct V_160 * V_161 , T_9 V_162 ,
void * V_140 )
{
int V_41 = 0 ;
int V_163 = 0 ;
struct V_164 V_165 ;
int V_143 ;
T_8 V_15 ( V_166 ) ;
T_8 V_167 ;
T_8 V_154 ;
T_8 V_168 ;
int V_169 ;
int V_170 = 0 ;
int V_171 ;
F_115 ( & V_165 , 0 ) ;
if ( V_161 -> V_172 ) {
V_166 = V_111 -> V_166 ;
V_167 = V_166 ;
if ( V_167 == 0 )
V_169 = 1 ;
else
V_169 = 0 ;
V_154 = - 1 ;
} else {
V_167 = V_161 -> V_173 >> V_174 ;
V_154 = V_161 -> V_175 >> V_174 ;
if ( V_161 -> V_173 == 0 && V_161 -> V_175 == V_176 )
V_170 = 1 ;
V_169 = 1 ;
}
if ( V_161 -> V_177 == V_178 || V_161 -> V_179 )
V_171 = V_159 ;
else
V_171 = V_158 ;
V_180:
if ( V_161 -> V_177 == V_178 || V_161 -> V_179 )
F_107 ( V_111 , V_167 , V_154 ) ;
V_168 = V_167 ;
while ( ! V_163 && ( V_167 <= V_154 ) ) {
int V_181 ;
V_143 = F_116 ( & V_165 , V_111 , & V_167 , V_171 ,
F_7 ( V_154 - V_167 , ( T_8 ) V_182 - 1 ) + 1 ) ;
if ( V_143 == 0 )
break;
for ( V_181 = 0 ; V_181 < V_143 ; V_181 ++ ) {
struct V_126 * V_126 = V_165 . V_108 [ V_181 ] ;
if ( V_126 -> V_167 > V_154 ) {
V_163 = 1 ;
break;
}
V_168 = V_126 -> V_167 ;
F_117 ( V_126 ) ;
if ( F_47 ( V_126 -> V_111 != V_111 ) ) {
V_183:
F_118 ( V_126 ) ;
continue;
}
if ( ! F_119 ( V_126 ) ) {
goto V_183;
}
if ( F_120 ( V_126 ) ) {
if ( V_161 -> V_177 != V_184 )
F_121 ( V_126 ) ;
else
goto V_183;
}
F_122 ( F_120 ( V_126 ) ) ;
if ( ! F_123 ( V_126 ) )
goto V_183;
F_124 ( V_161 , V_111 -> V_44 ) ;
V_41 = (* V_162)( V_126 , V_161 , V_140 ) ;
if ( F_47 ( V_41 ) ) {
if ( V_41 == V_185 ) {
F_118 ( V_126 ) ;
V_41 = 0 ;
} else {
V_168 = V_126 -> V_167 + 1 ;
V_163 = 1 ;
break;
}
}
if ( -- V_161 -> V_186 <= 0 &&
V_161 -> V_177 == V_184 ) {
V_163 = 1 ;
break;
}
}
F_125 ( & V_165 ) ;
F_113 () ;
}
if ( ! V_169 && ! V_163 ) {
V_169 = 1 ;
V_167 = 0 ;
V_154 = V_166 - 1 ;
goto V_180;
}
if ( V_161 -> V_172 || ( V_170 && V_161 -> V_186 > 0 ) )
V_111 -> V_166 = V_168 ;
return V_41 ;
}
static int F_126 ( struct V_126 * V_126 , struct V_160 * V_161 ,
void * V_140 )
{
struct V_110 * V_111 = V_140 ;
int V_41 = V_111 -> V_187 -> V_162 ( V_126 , V_161 ) ;
F_127 ( V_111 , V_41 ) ;
return V_41 ;
}
int F_128 ( struct V_110 * V_111 ,
struct V_160 * V_161 )
{
struct V_188 V_189 ;
int V_41 ;
if ( ! V_111 -> V_187 -> V_162 )
return 0 ;
F_129 ( & V_189 ) ;
V_41 = F_114 ( V_111 , V_161 , F_126 , V_111 ) ;
F_130 ( & V_189 ) ;
return V_41 ;
}
int F_131 ( struct V_110 * V_111 , struct V_160 * V_161 )
{
int V_41 ;
if ( V_161 -> V_186 <= 0 )
return 0 ;
if ( V_111 -> V_187 -> V_190 )
V_41 = V_111 -> V_187 -> V_190 ( V_111 , V_161 ) ;
else
V_41 = F_128 ( V_111 , V_161 ) ;
return V_41 ;
}
int F_132 ( struct V_126 * V_126 , int V_191 )
{
struct V_110 * V_111 = V_126 -> V_111 ;
int V_41 = 0 ;
struct V_160 V_161 = {
. V_177 = V_178 ,
. V_186 = 1 ,
} ;
F_122 ( ! F_133 ( V_126 ) ) ;
if ( V_191 )
F_121 ( V_126 ) ;
if ( F_123 ( V_126 ) ) {
F_134 ( V_126 ) ;
V_41 = V_111 -> V_187 -> V_162 ( V_126 , & V_161 ) ;
if ( V_41 == 0 && V_191 ) {
F_121 ( V_126 ) ;
if ( F_135 ( V_126 ) )
V_41 = - V_192 ;
}
F_136 ( V_126 ) ;
} else {
F_118 ( V_126 ) ;
}
return V_41 ;
}
int F_137 ( struct V_126 * V_126 )
{
if ( ! F_119 ( V_126 ) )
return ! F_138 ( V_126 ) ;
return 0 ;
}
void F_139 ( struct V_126 * V_126 , struct V_110 * V_111 )
{
if ( F_140 ( V_111 ) ) {
F_141 ( V_126 , V_29 ) ;
F_141 ( V_126 , V_193 ) ;
F_30 ( V_111 -> V_44 , V_122 ) ;
F_30 ( V_111 -> V_44 , V_97 ) ;
F_142 ( V_194 ) ;
V_24 -> V_121 ++ ;
F_143 ( V_132 ) ;
}
}
void F_144 ( struct V_126 * V_126 )
{
F_145 ( V_126 , V_31 ) ;
}
int F_146 ( struct V_126 * V_126 )
{
if ( ! F_138 ( V_126 ) ) {
struct V_110 * V_111 = F_80 ( V_126 ) ;
struct V_110 * V_195 ;
if ( ! V_111 )
return 1 ;
F_109 ( & V_111 -> V_156 ) ;
V_195 = F_80 ( V_126 ) ;
if ( V_195 ) {
F_122 ( V_195 != V_111 ) ;
F_112 ( ! F_147 ( V_126 ) && ! F_148 ( V_126 ) ) ;
F_139 ( V_126 , V_111 ) ;
F_149 ( & V_111 -> V_157 ,
F_150 ( V_126 ) , V_158 ) ;
}
F_111 ( & V_111 -> V_156 ) ;
if ( V_111 -> V_196 ) {
F_151 ( V_111 -> V_196 , V_197 ) ;
}
return 1 ;
}
return 0 ;
}
void F_152 ( struct V_126 * V_126 )
{
struct V_110 * V_111 = V_126 -> V_111 ;
if ( V_111 && F_140 ( V_111 ) ) {
V_24 -> V_121 -- ;
F_153 ( V_126 , V_193 ) ;
F_154 ( V_111 -> V_44 , V_97 ) ;
}
}
int F_155 ( struct V_160 * V_161 , struct V_126 * V_126 )
{
V_161 -> V_198 ++ ;
F_152 ( V_126 ) ;
return F_146 ( V_126 ) ;
}
int F_79 ( struct V_126 * V_126 )
{
struct V_110 * V_111 = F_80 ( V_126 ) ;
if ( F_156 ( V_111 ) ) {
int (* F_157)( struct V_126 * ) = V_111 -> V_187 -> F_79 ;
F_158 ( V_126 ) ;
#ifdef F_159
if ( ! F_157 )
F_157 = V_199 ;
#endif
return (* F_157)( V_126 ) ;
}
if ( ! F_119 ( V_126 ) ) {
if ( ! F_138 ( V_126 ) )
return 1 ;
}
return 0 ;
}
int F_160 ( struct V_126 * V_126 )
{
int V_41 ;
F_117 ( V_126 ) ;
V_41 = F_79 ( V_126 ) ;
F_118 ( V_126 ) ;
return V_41 ;
}
int F_123 ( struct V_126 * V_126 )
{
struct V_110 * V_111 = F_80 ( V_126 ) ;
F_122 ( ! F_133 ( V_126 ) ) ;
if ( V_111 && F_140 ( V_111 ) ) {
if ( F_161 ( V_126 ) )
F_79 ( V_126 ) ;
if ( F_162 ( V_126 ) ) {
F_153 ( V_126 , V_29 ) ;
F_154 ( V_111 -> V_44 ,
V_122 ) ;
return 1 ;
}
return 0 ;
}
return F_162 ( V_126 ) ;
}
int F_163 ( struct V_126 * V_126 )
{
struct V_110 * V_111 = F_80 ( V_126 ) ;
int V_41 ;
if ( V_111 ) {
struct V_44 * V_45 = V_111 -> V_44 ;
unsigned long V_25 ;
F_164 ( & V_111 -> V_156 , V_25 ) ;
V_41 = F_165 ( V_126 ) ;
if ( V_41 ) {
F_166 ( & V_111 -> V_157 ,
F_150 ( V_126 ) ,
V_200 ) ;
if ( F_167 ( V_45 ) ) {
F_168 ( V_45 , V_123 ) ;
F_29 ( V_45 ) ;
}
}
F_169 ( & V_111 -> V_156 , V_25 ) ;
} else {
V_41 = F_165 ( V_126 ) ;
}
if ( V_41 ) {
F_153 ( V_126 , V_31 ) ;
F_145 ( V_126 , V_201 ) ;
}
return V_41 ;
}
int F_170 ( struct V_126 * V_126 )
{
struct V_110 * V_111 = F_80 ( V_126 ) ;
int V_41 ;
if ( V_111 ) {
struct V_44 * V_45 = V_111 -> V_44 ;
unsigned long V_25 ;
F_164 ( & V_111 -> V_156 , V_25 ) ;
V_41 = F_171 ( V_126 ) ;
if ( ! V_41 ) {
F_149 ( & V_111 -> V_157 ,
F_150 ( V_126 ) ,
V_200 ) ;
if ( F_167 ( V_45 ) )
F_30 ( V_45 , V_123 ) ;
}
if ( ! F_119 ( V_126 ) )
F_166 ( & V_111 -> V_157 ,
F_150 ( V_126 ) ,
V_158 ) ;
F_166 ( & V_111 -> V_157 ,
F_150 ( V_126 ) ,
V_159 ) ;
F_169 ( & V_111 -> V_156 , V_25 ) ;
} else {
V_41 = F_171 ( V_126 ) ;
}
if ( ! V_41 )
F_144 ( V_126 ) ;
return V_41 ;
}
int F_172 ( struct V_110 * V_111 , int V_171 )
{
return F_173 ( & V_111 -> V_157 , V_171 ) ;
}
