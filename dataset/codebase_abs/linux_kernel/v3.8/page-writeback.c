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
static unsigned long F_47 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 )
{
unsigned long V_68 = V_45 -> V_69 ;
unsigned long V_70 = F_42 ( V_63 , V_64 ) ;
unsigned long V_29 = F_43 ( V_63 ) ;
unsigned long V_71 ;
unsigned long V_72 ;
unsigned long V_73 ;
unsigned long V_74 ;
long long V_75 ;
long V_3 ;
if ( F_29 ( V_14 >= V_29 ) )
return 0 ;
V_72 = ( V_70 + V_29 ) / 2 ;
V_3 = F_48 ( ( V_72 - V_14 ) << V_76 ,
V_29 - V_72 + 1 ) ;
V_75 = V_3 ;
V_75 = V_75 * V_3 >> V_76 ;
V_75 = V_75 * V_3 >> V_76 ;
V_75 += 1 << V_76 ;
if ( F_29 ( V_67 > V_63 ) )
V_67 = V_63 ;
V_67 = F_44 ( V_67 , ( V_29 - V_14 ) / 8 ) ;
V_3 = F_49 ( ( T_4 ) V_67 << 16 , V_63 + 1 ) ;
V_73 = V_72 * ( T_4 ) V_3 >> 16 ;
V_74 = ( V_63 - V_67 + 8 * V_68 ) * ( T_4 ) V_3 >> 16 ;
V_71 = V_73 + V_74 ;
if ( V_66 < V_71 - V_74 / 4 ) {
V_75 = F_49 ( V_75 * ( V_71 - V_66 ) ,
V_71 - V_73 + 1 ) ;
} else
V_75 /= 4 ;
V_71 = V_67 / 2 ;
if ( V_66 < V_71 ) {
if ( V_66 > V_71 / 8 )
V_75 = F_49 ( V_75 * V_71 , V_66 ) ;
else
V_75 *= 8 ;
}
return V_75 ;
}
static void F_50 ( struct V_44 * V_45 ,
unsigned long V_77 ,
unsigned long V_78 )
{
const unsigned long V_79 = F_51 ( 3 * V_80 ) ;
unsigned long V_81 = V_45 -> V_69 ;
unsigned long V_82 = V_45 -> V_83 ;
T_4 V_84 ;
V_84 = V_78 - V_45 -> V_85 ;
V_84 *= V_80 ;
if ( F_29 ( V_77 > V_79 ) ) {
F_46 ( V_84 , V_77 ) ;
V_81 = V_84 ;
goto V_86;
}
V_84 += ( T_4 ) V_45 -> V_83 * ( V_79 - V_77 ) ;
V_84 >>= F_52 ( V_79 ) ;
if ( V_81 > V_82 && V_82 >= ( unsigned long ) V_84 )
V_81 -= ( V_81 - V_82 ) >> 3 ;
if ( V_81 < V_82 && V_82 <= ( unsigned long ) V_84 )
V_81 += ( V_82 - V_81 ) >> 3 ;
V_86:
V_45 -> V_83 = V_84 ;
V_45 -> V_69 = V_81 ;
}
static void F_53 ( unsigned long V_63 , unsigned long V_14 )
{
unsigned long V_29 = V_65 ;
if ( V_29 < V_63 ) {
V_29 = V_63 ;
goto V_87;
}
V_63 = F_44 ( V_63 , V_14 ) ;
if ( V_29 > V_63 ) {
V_29 -= ( V_29 - V_63 ) >> 5 ;
goto V_87;
}
return;
V_87:
V_65 = V_29 ;
}
static void F_54 ( unsigned long V_63 ,
unsigned long V_14 ,
unsigned long V_88 )
{
static F_55 ( V_89 ) ;
static unsigned long V_90 ;
if ( F_56 ( V_88 , V_90 + V_91 ) )
return;
F_57 ( & V_89 ) ;
if ( F_58 ( V_88 , V_90 + V_91 ) ) {
F_53 ( V_63 , V_14 ) ;
V_90 = V_88 ;
}
F_59 ( & V_89 ) ;
}
static void F_60 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 ,
unsigned long V_92 ,
unsigned long V_77 )
{
unsigned long V_70 = F_42 ( V_63 , V_64 ) ;
unsigned long V_29 = F_43 ( V_63 ) ;
unsigned long V_72 = ( V_70 + V_29 ) / 2 ;
unsigned long V_68 = V_45 -> V_69 ;
unsigned long V_93 = V_45 -> V_93 ;
unsigned long V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
unsigned long V_75 ;
unsigned long V_97 ;
unsigned long V_3 ;
V_94 = ( V_92 - V_45 -> V_98 ) * V_80 / V_77 ;
V_75 = F_47 ( V_45 , V_63 , V_64 , V_14 ,
V_67 , V_66 ) ;
V_95 = ( T_4 ) V_93 *
V_75 >> V_76 ;
V_95 ++ ;
V_96 = F_49 ( ( T_4 ) V_95 * V_68 ,
V_94 | 1 ) ;
if ( F_29 ( V_96 > V_68 ) )
V_96 = V_68 ;
V_97 = 0 ;
if ( V_14 < V_72 ) {
V_3 = F_7 ( V_45 -> V_96 ,
F_7 ( V_96 , V_95 ) ) ;
if ( V_93 < V_3 )
V_97 = V_3 - V_93 ;
} else {
V_3 = F_44 ( V_45 -> V_96 ,
F_44 ( V_96 , V_95 ) ) ;
if ( V_93 > V_3 )
V_97 = V_93 - V_3 ;
}
V_97 >>= V_93 / ( 2 * V_97 + 1 ) ;
V_97 = ( V_97 + 7 ) / 8 ;
if ( V_93 < V_96 )
V_93 += V_97 ;
else
V_93 -= V_97 ;
V_45 -> V_93 = F_44 ( V_93 , 1UL ) ;
V_45 -> V_96 = V_96 ;
F_61 ( V_45 , V_94 , V_95 ) ;
}
void F_62 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 ,
unsigned long V_99 )
{
unsigned long V_88 = V_51 ;
unsigned long V_77 = V_88 - V_45 -> V_100 ;
unsigned long V_92 ;
unsigned long V_78 ;
if ( V_77 < V_91 )
return;
V_92 = F_63 ( & V_45 -> V_101 [ V_102 ] ) ;
V_78 = F_63 ( & V_45 -> V_101 [ V_46 ] ) ;
if ( V_77 > V_80 && F_56 ( V_45 -> V_100 , V_99 ) )
goto V_103;
if ( V_63 ) {
F_54 ( V_63 , V_14 , V_88 ) ;
F_60 ( V_45 , V_63 , V_64 , V_14 ,
V_67 , V_66 ,
V_92 , V_77 ) ;
}
F_50 ( V_45 , V_77 , V_78 ) ;
V_103:
V_45 -> V_98 = V_92 ;
V_45 -> V_85 = V_78 ;
V_45 -> V_100 = V_88 ;
}
static void F_64 ( struct V_44 * V_45 ,
unsigned long V_63 ,
unsigned long V_64 ,
unsigned long V_14 ,
unsigned long V_67 ,
unsigned long V_66 ,
unsigned long V_99 )
{
if ( F_65 ( V_45 -> V_100 + V_91 ) )
return;
F_57 ( & V_45 -> V_104 . V_105 ) ;
F_62 ( V_45 , V_63 , V_64 , V_14 ,
V_67 , V_66 , V_99 ) ;
F_59 ( & V_45 -> V_104 . V_105 ) ;
}
static unsigned long F_66 ( unsigned long V_14 ,
unsigned long V_63 )
{
if ( V_63 > V_14 )
return 1UL << ( F_52 ( V_63 - V_14 ) >> 1 ) ;
return 1 ;
}
static long F_67 ( struct V_44 * V_45 ,
unsigned long V_66 )
{
long V_84 = V_45 -> V_69 ;
long V_55 ;
V_55 = V_66 / ( 1 + V_84 / F_51 ( 1 + V_80 / 8 ) ) ;
V_55 ++ ;
return F_68 ( long , V_55 , V_106 ) ;
}
static long F_69 ( struct V_44 * V_45 ,
long V_107 ,
unsigned long V_95 ,
unsigned long V_93 ,
int * V_108 )
{
long V_109 = F_52 ( V_45 -> V_69 ) ;
long V_110 = F_52 ( V_45 -> V_93 ) ;
long V_55 ;
long V_111 ;
int V_112 ;
V_55 = F_44 ( 1 , V_80 / 100 ) ;
if ( V_109 > V_110 )
V_55 += ( V_109 - V_110 ) * ( 10 * V_80 ) / 1024 ;
V_55 = F_7 ( V_55 , 1 + V_107 / 2 ) ;
V_112 = V_93 * V_55 / F_51 ( V_80 ) ;
if ( V_112 < V_113 ) {
V_55 = V_107 ;
V_112 = V_93 * V_55 / F_51 ( V_80 ) ;
if ( V_112 > V_113 ) {
V_112 = V_113 ;
V_55 = V_80 * V_113 / V_93 ;
}
}
V_111 = V_80 * V_112 / ( V_95 + 1 ) ;
if ( V_111 > V_107 ) {
V_55 = V_107 ;
V_112 = V_95 * V_55 / F_51 ( V_80 ) ;
}
* V_108 = V_112 ;
return V_112 >= V_113 ? 1 + V_55 / 2 : V_55 ;
}
static void F_70 ( struct V_114 * V_115 ,
unsigned long V_116 )
{
unsigned long V_117 ;
unsigned long V_118 ;
unsigned long V_119 ;
unsigned long V_66 ;
unsigned long V_70 ;
unsigned long V_120 ;
unsigned long V_121 ;
unsigned long V_67 ;
long V_79 ;
long V_111 ;
long V_107 ;
long V_122 ;
int V_108 ;
bool V_123 = false ;
unsigned long V_95 ;
unsigned long V_93 ;
unsigned long V_75 ;
struct V_44 * V_45 = V_115 -> V_44 ;
unsigned long V_99 = V_51 ;
for (; ; ) {
unsigned long V_88 = V_51 ;
V_117 = F_9 ( V_30 ) +
F_9 ( V_31 ) ;
V_119 = V_117 + F_9 ( V_32 ) ;
F_11 ( & V_120 , & V_121 ) ;
V_70 = F_42 ( V_121 ,
V_120 ) ;
if ( V_119 <= V_70 ) {
V_24 -> V_124 = V_88 ;
V_24 -> V_125 = 0 ;
V_24 -> V_108 =
F_66 ( V_119 , V_121 ) ;
break;
}
if ( F_29 ( ! F_71 ( V_45 ) ) )
F_72 ( V_45 ) ;
V_67 = F_45 ( V_45 , V_121 ) ;
if ( V_67 < 2 * F_73 ( V_45 ) ) {
V_118 = F_74 ( V_45 , V_126 ) ;
V_66 = V_118 +
F_74 ( V_45 , V_127 ) ;
} else {
V_118 = V_101 ( V_45 , V_126 ) ;
V_66 = V_118 +
V_101 ( V_45 , V_127 ) ;
}
V_123 = ( V_66 > V_67 ) &&
( V_119 > V_121 ) ;
if ( V_123 && ! V_45 -> V_123 )
V_45 -> V_123 = 1 ;
F_64 ( V_45 , V_121 , V_120 ,
V_119 , V_67 , V_66 ,
V_99 ) ;
V_93 = V_45 -> V_93 ;
V_75 = F_47 ( V_45 , V_121 ,
V_120 , V_119 ,
V_67 , V_66 ) ;
V_95 = ( ( T_4 ) V_93 * V_75 ) >>
V_76 ;
V_107 = F_67 ( V_45 , V_66 ) ;
V_122 = F_69 ( V_45 , V_107 ,
V_95 , V_93 ,
& V_108 ) ;
if ( F_29 ( V_95 == 0 ) ) {
V_79 = V_107 ;
V_111 = V_107 ;
goto V_111;
}
V_79 = V_80 * V_116 / V_95 ;
V_111 = V_79 ;
if ( V_24 -> V_124 )
V_111 -= V_88 - V_24 -> V_124 ;
if ( V_111 < V_122 ) {
F_75 ( V_45 ,
V_121 ,
V_120 ,
V_119 ,
V_67 ,
V_66 ,
V_93 ,
V_95 ,
V_116 ,
V_79 ,
F_7 ( V_111 , 0L ) ,
V_99 ) ;
if ( V_111 < - V_80 ) {
V_24 -> V_124 = V_88 ;
V_24 -> V_125 = 0 ;
} else if ( V_79 ) {
V_24 -> V_124 += V_79 ;
V_24 -> V_125 = 0 ;
} else if ( V_24 -> V_108 <= V_116 )
V_24 -> V_108 += V_116 ;
break;
}
if ( F_29 ( V_111 > V_107 ) ) {
V_88 += F_7 ( V_111 - V_107 , V_107 ) ;
V_111 = V_107 ;
}
V_111:
F_75 ( V_45 ,
V_121 ,
V_120 ,
V_119 ,
V_67 ,
V_66 ,
V_93 ,
V_95 ,
V_116 ,
V_79 ,
V_111 ,
V_99 ) ;
F_76 ( V_128 ) ;
F_77 ( V_111 ) ;
V_24 -> V_124 = V_88 + V_111 ;
V_24 -> V_125 = 0 ;
V_24 -> V_108 = V_108 ;
if ( V_95 )
break;
if ( V_66 <= F_73 ( V_45 ) )
break;
if ( F_78 ( V_24 ) )
break;
}
if ( ! V_123 && V_45 -> V_123 )
V_45 -> V_123 = 0 ;
if ( F_71 ( V_45 ) )
return;
if ( V_129 )
return;
if ( V_117 > V_120 )
F_72 ( V_45 ) ;
}
void F_79 ( struct V_130 * V_130 , int V_131 )
{
if ( F_80 ( V_130 ) || V_131 ) {
struct V_114 * V_115 = F_81 ( V_130 ) ;
if ( V_115 )
F_82 ( V_115 ) ;
}
}
void F_82 ( struct V_114 * V_115 )
{
struct V_44 * V_45 = V_115 -> V_44 ;
int V_132 ;
int * V_133 ;
if ( ! F_83 ( V_45 ) )
return;
V_132 = V_24 -> V_108 ;
if ( V_45 -> V_123 )
V_132 = F_7 ( V_132 , 32 >> ( V_134 - 10 ) ) ;
F_84 () ;
V_133 = & F_85 ( V_135 ) ;
if ( F_29 ( V_24 -> V_125 >= V_132 ) )
* V_133 = 0 ;
else if ( F_29 ( * V_133 >= V_136 ) ) {
* V_133 = 0 ;
V_132 = 0 ;
}
V_133 = & F_85 ( V_137 ) ;
if ( * V_133 > 0 && V_24 -> V_125 < V_132 ) {
unsigned long V_138 ;
V_138 = F_7 ( * V_133 , V_132 - V_24 -> V_125 ) ;
* V_133 -= V_138 ;
V_24 -> V_125 += V_138 ;
}
F_86 () ;
if ( F_29 ( V_24 -> V_125 >= V_132 ) )
F_70 ( V_115 , V_24 -> V_125 ) ;
}
void F_87 ( T_5 V_139 )
{
unsigned long V_120 ;
unsigned long V_121 ;
for ( ; ; ) {
F_11 ( & V_120 , & V_121 ) ;
V_121 = F_43 ( V_121 ) ;
V_121 += V_121 / 10 ;
if ( F_9 ( V_31 ) +
F_9 ( V_32 ) <= V_121 )
break;
F_88 ( V_140 , V_80 / 10 ) ;
if ( ( V_139 & ( V_141 | V_142 ) ) != ( V_141 | V_142 ) )
break;
}
}
int F_89 ( V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_143 , T_3 * V_38 )
{
F_90 ( V_34 , V_35 , V_36 , V_143 , V_38 ) ;
return 0 ;
}
void F_91 ( unsigned long V_144 )
{
struct V_145 * V_146 = (struct V_145 * ) V_144 ;
int V_27 = F_9 ( V_30 ) +
F_9 ( V_31 ) ;
if ( F_92 ( & V_146 -> V_44 ) )
F_93 ( & V_146 -> V_44 , V_27 ,
V_147 ) ;
}
void F_94 ( struct V_44 * V_148 )
{
F_30 ( & V_148 -> V_149 , V_51 + V_129 ) ;
}
void F_95 ( void )
{
struct V_44 * V_45 ;
F_96 () ;
F_97 (bdi, &bdi_list, bdi_list)
F_98 ( & V_45 -> V_149 ) ;
F_99 () ;
}
void F_23 ( void )
{
unsigned long V_120 ;
unsigned long V_121 ;
F_11 ( & V_120 , & V_121 ) ;
V_65 = V_121 ;
V_136 = V_121 / ( F_100 () * 32 ) ;
if ( V_136 < 16 )
V_136 = 16 ;
}
static int T_6
F_101 ( struct V_150 * V_151 , unsigned long V_152 ,
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
void T_7 F_102 ( void )
{
F_23 () ;
F_103 ( & V_159 ) ;
F_104 ( & V_47 ) ;
}
void F_105 ( struct V_114 * V_115 ,
T_8 V_160 , T_8 V_161 )
{
#define F_106 4096
unsigned long V_162 ;
do {
F_107 ( & V_115 -> V_163 ) ;
V_162 = F_108 ( & V_115 -> V_164 ,
& V_160 , V_161 , F_106 ,
V_165 , V_166 ) ;
F_109 ( & V_115 -> V_163 ) ;
F_110 ( V_162 > F_106 ) ;
F_111 () ;
} while ( V_162 >= F_106 && V_160 );
}
int F_112 ( struct V_114 * V_115 ,
struct V_167 * V_168 , T_9 V_169 ,
void * V_144 )
{
int V_39 = 0 ;
int V_170 = 0 ;
struct V_171 V_172 ;
int V_27 ;
T_8 V_15 ( V_173 ) ;
T_8 V_174 ;
T_8 V_161 ;
T_8 V_175 ;
int V_176 ;
int V_177 = 0 ;
int V_178 ;
F_113 ( & V_172 , 0 ) ;
if ( V_168 -> V_179 ) {
V_173 = V_115 -> V_173 ;
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
F_105 ( V_115 , V_174 , V_161 ) ;
V_175 = V_174 ;
while ( ! V_170 && ( V_174 <= V_161 ) ) {
int V_188 ;
V_27 = F_114 ( & V_172 , V_115 , & V_174 , V_178 ,
F_7 ( V_161 - V_174 , ( T_8 ) V_189 - 1 ) + 1 ) ;
if ( V_27 == 0 )
break;
for ( V_188 = 0 ; V_188 < V_27 ; V_188 ++ ) {
struct V_130 * V_130 = V_172 . V_112 [ V_188 ] ;
if ( V_130 -> V_174 > V_161 ) {
V_170 = 1 ;
break;
}
V_175 = V_130 -> V_174 ;
F_115 ( V_130 ) ;
if ( F_29 ( V_130 -> V_115 != V_115 ) ) {
V_190:
F_116 ( V_130 ) ;
continue;
}
if ( ! F_117 ( V_130 ) ) {
goto V_190;
}
if ( F_118 ( V_130 ) ) {
if ( V_168 -> V_184 != V_191 )
F_119 ( V_130 ) ;
else
goto V_190;
}
F_120 ( F_118 ( V_130 ) ) ;
if ( ! F_121 ( V_130 ) )
goto V_190;
F_122 ( V_168 , V_115 -> V_44 ) ;
V_39 = (* V_169)( V_130 , V_168 , V_144 ) ;
if ( F_29 ( V_39 ) ) {
if ( V_39 == V_192 ) {
F_116 ( V_130 ) ;
V_39 = 0 ;
} else {
V_175 = V_130 -> V_174 + 1 ;
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
F_123 ( & V_172 ) ;
F_111 () ;
}
if ( ! V_176 && ! V_170 ) {
V_176 = 1 ;
V_174 = 0 ;
V_161 = V_173 - 1 ;
goto V_187;
}
if ( V_168 -> V_179 || ( V_177 && V_168 -> V_193 > 0 ) )
V_115 -> V_173 = V_175 ;
return V_39 ;
}
static int F_124 ( struct V_130 * V_130 , struct V_167 * V_168 ,
void * V_144 )
{
struct V_114 * V_115 = V_144 ;
int V_39 = V_115 -> V_194 -> V_169 ( V_130 , V_168 ) ;
F_125 ( V_115 , V_39 ) ;
return V_39 ;
}
int F_126 ( struct V_114 * V_115 ,
struct V_167 * V_168 )
{
struct V_195 V_196 ;
int V_39 ;
if ( ! V_115 -> V_194 -> V_169 )
return 0 ;
F_127 ( & V_196 ) ;
V_39 = F_112 ( V_115 , V_168 , F_124 , V_115 ) ;
F_128 ( & V_196 ) ;
return V_39 ;
}
int F_129 ( struct V_114 * V_115 , struct V_167 * V_168 )
{
int V_39 ;
if ( V_168 -> V_193 <= 0 )
return 0 ;
if ( V_115 -> V_194 -> V_197 )
V_39 = V_115 -> V_194 -> V_197 ( V_115 , V_168 ) ;
else
V_39 = F_126 ( V_115 , V_168 ) ;
return V_39 ;
}
int F_130 ( struct V_130 * V_130 , int V_198 )
{
struct V_114 * V_115 = V_130 -> V_115 ;
int V_39 = 0 ;
struct V_167 V_168 = {
. V_184 = V_185 ,
. V_193 = 1 ,
} ;
F_120 ( ! F_131 ( V_130 ) ) ;
if ( V_198 )
F_119 ( V_130 ) ;
if ( F_121 ( V_130 ) ) {
F_132 ( V_130 ) ;
V_39 = V_115 -> V_194 -> V_169 ( V_130 , & V_168 ) ;
if ( V_39 == 0 && V_198 ) {
F_119 ( V_130 ) ;
if ( F_133 ( V_130 ) )
V_39 = - V_199 ;
}
F_134 ( V_130 ) ;
} else {
F_116 ( V_130 ) ;
}
return V_39 ;
}
int F_135 ( struct V_130 * V_130 )
{
if ( ! F_117 ( V_130 ) )
return ! F_136 ( V_130 ) ;
return 0 ;
}
void F_137 ( struct V_130 * V_130 , struct V_114 * V_115 )
{
if ( F_138 ( V_115 ) ) {
F_139 ( V_130 , V_30 ) ;
F_139 ( V_130 , V_200 ) ;
F_27 ( V_115 -> V_44 , V_126 ) ;
F_27 ( V_115 -> V_44 , V_102 ) ;
F_140 ( V_201 ) ;
V_24 -> V_125 ++ ;
F_141 ( V_135 ) ;
}
}
void F_142 ( struct V_130 * V_130 )
{
F_143 ( V_130 , V_32 ) ;
}
int F_144 ( struct V_130 * V_130 )
{
if ( ! F_136 ( V_130 ) ) {
struct V_114 * V_115 = F_81 ( V_130 ) ;
struct V_114 * V_202 ;
if ( ! V_115 )
return 1 ;
F_107 ( & V_115 -> V_163 ) ;
V_202 = F_81 ( V_130 ) ;
if ( V_202 ) {
F_120 ( V_202 != V_115 ) ;
F_110 ( ! F_145 ( V_130 ) && ! F_146 ( V_130 ) ) ;
F_137 ( V_130 , V_115 ) ;
F_147 ( & V_115 -> V_164 ,
F_148 ( V_130 ) , V_165 ) ;
}
F_109 ( & V_115 -> V_163 ) ;
if ( V_115 -> V_203 ) {
F_149 ( V_115 -> V_203 , V_204 ) ;
}
return 1 ;
}
return 0 ;
}
void F_150 ( struct V_130 * V_130 )
{
struct V_114 * V_115 = V_130 -> V_115 ;
if ( V_115 && F_138 ( V_115 ) ) {
V_24 -> V_125 -- ;
F_151 ( V_130 , V_200 ) ;
F_152 ( V_115 -> V_44 , V_102 ) ;
}
}
int F_153 ( struct V_167 * V_168 , struct V_130 * V_130 )
{
V_168 -> V_205 ++ ;
F_150 ( V_130 ) ;
return F_144 ( V_130 ) ;
}
int F_80 ( struct V_130 * V_130 )
{
struct V_114 * V_115 = F_81 ( V_130 ) ;
if ( F_154 ( V_115 ) ) {
int (* F_155)( struct V_130 * ) = V_115 -> V_194 -> F_80 ;
F_156 ( V_130 ) ;
#ifdef F_157
if ( ! F_155 )
F_155 = V_206 ;
#endif
return (* F_155)( V_130 ) ;
}
if ( ! F_117 ( V_130 ) ) {
if ( ! F_136 ( V_130 ) )
return 1 ;
}
return 0 ;
}
int F_158 ( struct V_130 * V_130 )
{
int V_39 ;
F_115 ( V_130 ) ;
V_39 = F_80 ( V_130 ) ;
F_116 ( V_130 ) ;
return V_39 ;
}
int F_121 ( struct V_130 * V_130 )
{
struct V_114 * V_115 = F_81 ( V_130 ) ;
F_120 ( ! F_131 ( V_130 ) ) ;
if ( V_115 && F_138 ( V_115 ) ) {
if ( F_159 ( V_130 ) )
F_80 ( V_130 ) ;
if ( F_160 ( V_130 ) ) {
F_151 ( V_130 , V_30 ) ;
F_152 ( V_115 -> V_44 ,
V_126 ) ;
return 1 ;
}
return 0 ;
}
return F_160 ( V_130 ) ;
}
int F_161 ( struct V_130 * V_130 )
{
struct V_114 * V_115 = F_81 ( V_130 ) ;
int V_39 ;
if ( V_115 ) {
struct V_44 * V_45 = V_115 -> V_44 ;
unsigned long V_25 ;
F_162 ( & V_115 -> V_163 , V_25 ) ;
V_39 = F_163 ( V_130 ) ;
if ( V_39 ) {
F_164 ( & V_115 -> V_164 ,
F_148 ( V_130 ) ,
V_207 ) ;
if ( F_165 ( V_45 ) ) {
F_166 ( V_45 , V_127 ) ;
F_26 ( V_45 ) ;
}
}
F_167 ( & V_115 -> V_163 , V_25 ) ;
} else {
V_39 = F_163 ( V_130 ) ;
}
if ( V_39 ) {
F_151 ( V_130 , V_32 ) ;
F_143 ( V_130 , V_208 ) ;
}
return V_39 ;
}
int F_168 ( struct V_130 * V_130 )
{
struct V_114 * V_115 = F_81 ( V_130 ) ;
int V_39 ;
if ( V_115 ) {
struct V_44 * V_45 = V_115 -> V_44 ;
unsigned long V_25 ;
F_162 ( & V_115 -> V_163 , V_25 ) ;
V_39 = F_169 ( V_130 ) ;
if ( ! V_39 ) {
F_147 ( & V_115 -> V_164 ,
F_148 ( V_130 ) ,
V_207 ) ;
if ( F_165 ( V_45 ) )
F_27 ( V_45 , V_127 ) ;
}
if ( ! F_117 ( V_130 ) )
F_164 ( & V_115 -> V_164 ,
F_148 ( V_130 ) ,
V_165 ) ;
F_164 ( & V_115 -> V_164 ,
F_148 ( V_130 ) ,
V_166 ) ;
F_167 ( & V_115 -> V_163 , V_25 ) ;
} else {
V_39 = F_169 ( V_130 ) ;
}
if ( ! V_39 )
F_142 ( V_130 ) ;
return V_39 ;
}
int F_170 ( struct V_114 * V_115 , int V_178 )
{
return F_171 ( & V_115 -> V_164 , V_178 ) ;
}
