static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static inline bool F_2 ( struct V_3 * V_4 )
{
if ( F_3 ( V_4 ) )
return true ;
if ( V_5 . V_6 . V_7 && V_4 -> V_8 . V_9 > 1 &&
V_5 . V_6 . V_10 < 2 )
return true ;
return false ;
}
static void F_4 ( void )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
F_6 ( V_13 , 0 ) ;
if ( F_7 ( V_14 , V_12 -> V_15 ) )
F_8 () ;
F_9 () ;
F_10 () ;
}
static void F_11 ( int V_16 )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
F_12 () ;
F_13 () ;
F_6 ( V_13 ,
V_5 . V_17 & ~ V_12 -> V_18 ) ;
if ( F_7 ( V_14 , V_12 -> V_15 ) ) {
struct V_3 * V_4 =
V_12 -> V_19 [ V_14 ] ;
if ( F_14 ( ! V_4 ) )
return;
F_15 ( V_4 -> V_20 . V_21 ) ;
}
}
static void F_16 ( void )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
static const unsigned long V_22 [ 4 ] = {
0x4300B5 ,
0x4300D2 ,
0x4300B1 ,
0x4300B1
} ;
struct V_3 * V_4 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
V_4 = V_12 -> V_19 [ V_23 ] ;
if ( V_4 )
F_17 ( V_4 ) ;
}
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
F_6 ( V_24 + V_23 , V_22 [ V_23 ] ) ;
F_6 ( V_25 + V_23 , 0x0 ) ;
}
F_6 ( V_13 , 0xf ) ;
F_6 ( V_13 , 0x0 ) ;
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
V_4 = V_12 -> V_19 [ V_23 ] ;
if ( V_4 ) {
F_18 ( V_4 ) ;
F_19 ( & V_4 -> V_20 ,
V_26 ) ;
} else
F_6 ( V_24 + V_23 , 0x0 ) ;
}
}
static void F_20 ( int V_16 )
{
if ( V_16 )
F_16 () ;
F_11 ( V_16 ) ;
}
static inline T_1 F_21 ( void )
{
T_1 V_27 ;
F_22 ( V_28 , V_27 ) ;
return V_27 ;
}
static inline void F_23 ( T_1 V_29 )
{
F_6 ( V_30 , V_29 ) ;
}
static void F_24 ( struct V_31 * V_32 )
{
int V_33 = V_32 -> V_33 - V_34 ;
T_1 V_35 , V_36 ;
V_36 = 0xfULL << ( V_33 * 4 ) ;
F_22 ( V_32 -> V_37 , V_35 ) ;
V_35 &= ~ V_36 ;
F_6 ( V_32 -> V_37 , V_35 ) ;
}
static inline bool F_25 ( struct V_3 * V_4 )
{
return ( V_4 -> V_20 . V_21 & V_38 ) != 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_4 -> V_20 ;
struct V_11 * V_12 = & F_5 ( V_11 ) ;
if ( F_27 ( V_32 -> V_33 == V_14 ) ) {
F_8 () ;
F_28 () ;
return;
}
V_12 -> V_18 &= ~ ( 1ull << V_32 -> V_33 ) ;
V_12 -> V_39 &= ~ ( 1ull << V_32 -> V_33 ) ;
V_12 -> V_40 &= ~ ( 1ull << V_32 -> V_33 ) ;
if ( F_2 ( V_4 ) )
F_29 ( V_4 ) ;
if ( F_27 ( V_32 -> V_37 == V_41 ) ) {
F_24 ( V_32 ) ;
return;
}
F_30 ( V_4 ) ;
if ( F_27 ( V_4 -> V_8 . V_9 ) )
F_31 ( V_4 ) ;
}
static void F_32 ( struct V_31 * V_32 )
{
int V_33 = V_32 -> V_33 - V_34 ;
T_1 V_35 , V_42 , V_36 ;
V_42 = 0x8ULL ;
if ( V_32 -> V_21 & V_43 )
V_42 |= 0x2 ;
if ( V_32 -> V_21 & V_44 )
V_42 |= 0x1 ;
if ( V_5 . V_45 > 2 && V_32 -> V_21 & V_46 )
V_42 |= 0x4 ;
V_42 <<= ( V_33 * 4 ) ;
V_36 = 0xfULL << ( V_33 * 4 ) ;
F_22 ( V_32 -> V_37 , V_35 ) ;
V_35 &= ~ V_36 ;
V_35 |= V_42 ;
F_6 ( V_32 -> V_37 , V_35 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_4 -> V_20 ;
struct V_11 * V_12 = & F_5 ( V_11 ) ;
if ( F_27 ( V_32 -> V_33 == V_14 ) ) {
if ( ! F_34 ( V_11 . V_47 ) )
return;
F_15 ( V_32 -> V_21 ) ;
return;
}
if ( F_2 ( V_4 ) )
F_35 ( V_4 ) ;
if ( V_4 -> V_8 . V_48 )
V_12 -> V_18 |= ( 1ull << V_32 -> V_33 ) ;
if ( V_4 -> V_8 . V_49 )
V_12 -> V_39 |= ( 1ull << V_32 -> V_33 ) ;
if ( F_27 ( F_25 ( V_4 ) ) )
V_12 -> V_40 |= ( 1ull << V_32 -> V_33 ) ;
if ( F_27 ( V_32 -> V_37 == V_41 ) ) {
F_32 ( V_32 ) ;
return;
}
if ( F_27 ( V_4 -> V_8 . V_9 ) )
F_36 ( V_4 ) ;
F_19 ( V_32 , V_26 ) ;
}
int F_37 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
if ( F_27 ( F_25 ( V_4 ) ) ) {
F_6 ( V_4 -> V_20 . V_50 , 0 ) ;
F_38 ( & V_4 -> V_20 . V_51 , 0 ) ;
}
return F_18 ( V_4 ) ;
}
static void F_39 ( void )
{
struct V_52 * V_53 = F_34 ( V_11 . V_53 ) ;
unsigned long V_54 ;
int V_33 ;
if ( ! V_5 . V_55 )
return;
F_40 ( V_54 ) ;
F_41 ( L_1 , F_42 () ) ;
for ( V_33 = 0 ; V_33 < V_5 . V_55 ; V_33 ++ ) {
F_43 ( F_44 ( V_33 ) , 0ull ) ;
F_43 ( F_45 ( V_33 ) , 0ull ) ;
}
for ( V_33 = 0 ; V_33 < V_5 . V_56 ; V_33 ++ )
F_43 ( V_57 + V_33 , 0ull ) ;
if ( V_53 )
V_53 -> V_58 = V_53 -> V_59 ;
F_46 ( V_54 ) ;
}
static int F_47 ( struct V_60 * V_61 )
{
struct V_62 V_63 ;
struct V_11 * V_12 ;
int V_64 , V_65 ;
T_1 V_27 ;
int V_66 ;
V_12 = & F_5 ( V_11 ) ;
if ( ! V_5 . V_67 )
F_48 ( V_68 , V_69 ) ;
F_4 () ;
V_66 = F_28 () ;
V_27 = F_21 () ;
if ( ! V_27 )
goto V_70;
V_65 = 0 ;
V_71:
F_23 ( V_27 ) ;
if ( ++ V_65 > 100 ) {
static bool V_72 = false ;
if ( ! V_72 ) {
F_49 ( 1 , L_2 ) ;
F_50 () ;
V_72 = true ;
}
F_39 () ;
goto V_70;
}
F_51 ( V_73 ) ;
F_52 () ;
if ( F_53 ( 62 , ( unsigned long * ) & V_27 ) ) {
V_66 ++ ;
V_5 . V_74 ( V_61 ) ;
}
V_27 |= V_12 -> V_40 ;
F_54 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_3 * V_4 = V_12 -> V_19 [ V_64 ] ;
V_66 ++ ;
if ( ! F_7 ( V_64 , V_12 -> V_15 ) )
continue;
if ( ! F_37 ( V_4 ) )
continue;
F_55 ( & V_63 , 0 , V_4 -> V_20 . V_75 ) ;
if ( F_3 ( V_4 ) )
V_63 . V_76 = & V_12 -> V_77 ;
if ( F_56 ( V_4 , & V_63 , V_61 ) )
F_57 ( V_4 , 0 ) ;
}
V_27 = F_21 () ;
if ( V_27 )
goto V_71;
V_70:
F_11 ( 0 ) ;
if ( V_5 . V_67 )
F_48 ( V_68 , V_69 ) ;
return V_66 ;
}
static struct V_78 *
F_58 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_4 -> V_20 ;
unsigned int V_1 , V_79 ;
if ( V_4 -> V_8 . V_80 )
return NULL ;
V_1 = V_32 -> V_21 & V_81 ;
V_79 = V_5 . V_82 ( V_83 ) ;
if ( F_27 ( V_1 == V_79 && V_32 -> V_84 == 1 ) )
return & V_85 ;
return NULL ;
}
static int F_59 ( int V_33 )
{
if ( ! ( V_5 . V_86 & V_87 ) )
return V_33 ;
if ( V_33 == V_88 )
return V_89 ;
if ( V_33 == V_89 )
return V_88 ;
return V_33 ;
}
static void F_60 ( struct V_3 * V_4 , int V_33 )
{
V_4 -> V_20 . V_90 . V_33 = V_33 ;
if ( V_33 == V_88 ) {
V_4 -> V_20 . V_21 &= ~ V_81 ;
V_4 -> V_20 . V_21 |= V_5 . V_91 [ V_88 ] . V_4 ;
V_4 -> V_20 . V_90 . V_92 = V_93 ;
} else if ( V_33 == V_89 ) {
V_4 -> V_20 . V_21 &= ~ V_81 ;
V_4 -> V_20 . V_21 |= V_5 . V_91 [ V_89 ] . V_4 ;
V_4 -> V_20 . V_90 . V_92 = V_94 ;
}
}
static struct V_78 *
F_61 ( struct V_11 * V_12 ,
struct V_3 * V_4 ,
struct V_95 * V_92 )
{
struct V_78 * V_96 = & V_97 ;
struct V_98 * V_99 ;
unsigned long V_54 ;
int V_33 = V_92 -> V_33 ;
if ( V_92 -> V_100 && ! V_12 -> V_101 )
return NULL ;
V_71:
V_99 = & V_12 -> V_102 -> V_61 [ V_33 ] ;
F_62 ( & V_99 -> V_103 , V_54 ) ;
if ( ! F_63 ( & V_99 -> V_104 ) || V_99 -> V_21 == V_92 -> V_21 ) {
if ( ! V_12 -> V_101 ) {
if ( V_33 != V_92 -> V_33 )
F_60 ( V_4 , V_33 ) ;
V_92 -> V_100 = 1 ;
}
V_99 -> V_21 = V_92 -> V_21 ;
V_99 -> V_92 = V_92 -> V_92 ;
F_64 ( & V_99 -> V_104 ) ;
V_96 = NULL ;
} else {
V_33 = F_59 ( V_33 ) ;
if ( V_33 != V_92 -> V_33 ) {
F_65 ( & V_99 -> V_103 , V_54 ) ;
goto V_71;
}
}
F_65 ( & V_99 -> V_103 , V_54 ) ;
return V_96 ;
}
static void
F_66 ( struct V_11 * V_12 ,
struct V_95 * V_92 )
{
struct V_98 * V_99 ;
if ( ! V_92 -> V_100 || V_12 -> V_101 )
return;
V_99 = & V_12 -> V_102 -> V_61 [ V_92 -> V_33 ] ;
F_67 ( & V_99 -> V_104 ) ;
V_92 -> V_100 = 0 ;
}
static struct V_78 *
F_68 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_78 * V_96 = NULL , * V_105 ;
struct V_95 * V_106 , * V_107 ;
V_106 = & V_4 -> V_20 . V_90 ;
if ( V_106 -> V_33 != V_108 ) {
V_96 = F_61 ( V_12 , V_4 , V_106 ) ;
if ( V_96 == & V_97 )
return V_96 ;
}
V_107 = & V_4 -> V_20 . V_109 ;
if ( V_107 -> V_33 != V_108 ) {
V_105 = F_61 ( V_12 , V_4 , V_107 ) ;
if ( V_105 == & V_97 ) {
F_66 ( V_12 , V_106 ) ;
V_96 = V_105 ;
}
}
return V_96 ;
}
struct V_78 *
F_69 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
struct V_78 * V_96 ;
if ( V_5 . V_110 ) {
F_70 (c, x86_pmu.event_constraints) {
if ( ( V_4 -> V_20 . V_21 & V_96 -> V_111 ) == V_96 -> V_112 ) {
V_4 -> V_20 . V_54 |= V_96 -> V_54 ;
return V_96 ;
}
}
}
return & V_113 ;
}
static struct V_78 *
F_71 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
struct V_78 * V_96 ;
V_96 = F_58 ( V_4 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_72 ( V_4 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_68 ( V_12 , V_4 ) ;
if ( V_96 )
return V_96 ;
return F_69 ( V_12 , V_4 ) ;
}
static void
F_73 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_95 * V_92 ;
V_92 = & V_4 -> V_20 . V_90 ;
if ( V_92 -> V_33 != V_108 )
F_66 ( V_12 , V_92 ) ;
V_92 = & V_4 -> V_20 . V_109 ;
if ( V_92 -> V_33 != V_108 )
F_66 ( V_12 , V_92 ) ;
}
static void F_74 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
F_73 ( V_12 , V_4 ) ;
}
static void F_75 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_20 . V_21 & V_114 ) == 0x003c ) {
T_1 V_115 = F_76 ( . V_4 = 0xc0 , . V_116 = 1 , . V_111 = 16 ) ;
V_115 |= ( V_4 -> V_20 . V_21 & ~ V_114 ) ;
V_4 -> V_20 . V_21 = V_115 ;
}
}
static void F_77 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_20 . V_21 & V_114 ) == 0x003c ) {
T_1 V_115 = F_76 ( . V_4 = 0xc2 , . V_117 = 0x01 , . V_116 = 1 , . V_111 = 16 ) ;
V_115 |= ( V_4 -> V_20 . V_21 & ~ V_114 ) ;
V_4 -> V_20 . V_21 = V_115 ;
}
}
static int F_78 ( struct V_3 * V_4 )
{
int V_118 = F_79 ( V_4 ) ;
if ( V_118 )
return V_118 ;
if ( V_4 -> V_8 . V_9 && V_5 . V_119 )
V_5 . V_119 ( V_4 ) ;
if ( F_2 ( V_4 ) ) {
V_118 = F_80 ( V_4 ) ;
if ( V_118 )
return V_118 ;
}
if ( V_4 -> V_8 . type != V_120 )
return 0 ;
if ( ! ( V_4 -> V_8 . V_21 & V_46 ) )
return 0 ;
if ( V_5 . V_45 < 3 )
return - V_121 ;
if ( F_81 () && ! F_82 ( V_122 ) )
return - V_123 ;
V_4 -> V_20 . V_21 |= V_46 ;
return 0 ;
}
struct V_124 * F_83 ( int * V_125 )
{
if ( V_5 . V_126 )
return V_5 . V_126 ( V_125 ) ;
* V_125 = 0 ;
return NULL ;
}
static struct V_124 * F_84 ( int * V_125 )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
struct V_124 * V_127 = V_12 -> V_128 ;
V_127 [ 0 ] . V_129 = V_13 ;
V_127 [ 0 ] . V_130 = V_5 . V_17 & ~ V_12 -> V_18 ;
V_127 [ 0 ] . V_131 = V_5 . V_17 & ~ V_12 -> V_39 ;
V_127 [ 1 ] . V_129 = V_132 ;
V_127 [ 1 ] . V_130 = V_12 -> V_133 ;
V_127 [ 1 ] . V_131 = 0 ;
* V_125 = 2 ;
return V_127 ;
}
static struct V_124 * F_85 ( int * V_125 )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
struct V_124 * V_127 = V_12 -> V_128 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_5 . V_55 ; V_33 ++ ) {
struct V_3 * V_4 = V_12 -> V_19 [ V_33 ] ;
V_127 [ V_33 ] . V_129 = F_44 ( V_33 ) ;
V_127 [ V_33 ] . V_130 = V_127 [ V_33 ] . V_131 = 0 ;
if ( ! F_7 ( V_33 , V_12 -> V_15 ) )
continue;
V_127 [ V_33 ] . V_130 = V_127 [ V_33 ] . V_131 =
V_4 -> V_20 . V_21 | V_26 ;
if ( V_4 -> V_8 . V_48 )
V_127 [ V_33 ] . V_130 &= ~ V_26 ;
else if ( V_4 -> V_8 . V_49 )
V_127 [ V_33 ] . V_131 &= ~ V_26 ;
}
* V_125 = V_5 . V_55 ;
return V_127 ;
}
static void F_86 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_8 . V_48 )
F_87 ( V_4 ) ;
}
static void F_88 ( int V_16 )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_5 . V_55 ; V_33 ++ ) {
struct V_31 * V_32 = & V_12 -> V_19 [ V_33 ] -> V_20 ;
if ( ! F_7 ( V_33 , V_12 -> V_15 ) ||
V_12 -> V_19 [ V_33 ] -> V_8 . V_48 )
continue;
F_19 ( V_32 , V_26 ) ;
}
}
static int F_89 ( struct V_3 * V_4 )
{
int V_118 = F_78 ( V_4 ) ;
if ( V_118 )
return V_118 ;
if ( ! F_90 ( V_134 ) && ! F_90 ( V_135 ) )
return 0 ;
V_4 -> V_20 . V_21 |= V_4 -> V_8 . V_21 & ( V_136 | V_38 ) ;
if ( ( V_4 -> V_20 . V_21 & ( V_136 | V_38 ) ) &&
( ( V_4 -> V_20 . V_21 & V_46 ) ||
V_4 -> V_8 . V_9 > 0 ) )
return - V_137 ;
if ( F_25 ( V_4 ) ) {
if ( V_4 -> V_8 . V_84 > 0 &&
V_4 -> V_8 . V_84 < 0x7fffffff )
return - V_137 ;
}
return 0 ;
}
static struct V_78 *
F_91 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
struct V_78 * V_96 = F_71 ( V_12 , V_4 ) ;
if ( V_4 -> V_20 . V_21 & V_38 ) {
if ( V_96 -> V_138 & ( 1U << 2 ) )
return & V_139 ;
return & V_97 ;
}
return V_96 ;
}
T_2 F_92 ( char * V_140 , T_1 V_21 )
{
T_1 V_4 = ( V_21 & V_141 ) ;
return F_93 ( V_140 , V_21 , V_4 ) ;
}
struct V_142 * F_94 ( int V_143 )
{
struct V_142 * V_61 ;
int V_23 ;
V_61 = F_95 ( sizeof( struct V_142 ) ,
V_144 , F_96 ( V_143 ) ) ;
if ( V_61 ) {
for ( V_23 = 0 ; V_23 < V_145 ; V_23 ++ )
F_97 ( & V_61 -> V_61 [ V_23 ] . V_103 ) ;
V_61 -> V_146 = - 1 ;
}
return V_61 ;
}
static int F_98 ( int V_143 )
{
struct V_11 * V_12 = & F_99 ( V_11 , V_143 ) ;
if ( ! ( V_5 . V_91 || V_5 . V_147 ) )
return V_148 ;
V_12 -> V_102 = F_94 ( V_143 ) ;
if ( ! V_12 -> V_102 )
return V_149 ;
return V_148 ;
}
static void F_100 ( int V_143 )
{
struct V_11 * V_12 = & F_99 ( V_11 , V_143 ) ;
int V_146 = F_101 ( V_143 ) ;
int V_23 ;
F_102 ( V_143 ) ;
F_103 () ;
V_12 -> V_150 = NULL ;
if ( ! V_12 -> V_102 )
return;
if ( ! ( V_5 . V_86 & V_151 ) ) {
F_104 (i, topology_thread_cpumask(cpu)) {
struct V_142 * V_152 ;
V_152 = F_99 ( V_11 , V_23 ) . V_102 ;
if ( V_152 && V_152 -> V_146 == V_146 ) {
V_12 -> V_153 = V_12 -> V_102 ;
V_12 -> V_102 = V_152 ;
break;
}
}
V_12 -> V_102 -> V_146 = V_146 ;
V_12 -> V_102 -> V_154 ++ ;
}
if ( V_5 . V_147 )
V_12 -> V_150 = & V_12 -> V_102 -> V_61 [ V_155 ] ;
}
static void F_105 ( int V_143 )
{
struct V_11 * V_12 = & F_99 ( V_11 , V_143 ) ;
struct V_142 * V_152 ;
V_152 = V_12 -> V_102 ;
if ( V_152 ) {
if ( V_152 -> V_146 == - 1 || -- V_152 -> V_154 == 0 )
F_106 ( V_152 ) ;
V_12 -> V_102 = NULL ;
}
F_107 ( V_143 ) ;
}
static void F_108 ( void )
{
if ( V_5 . V_156 )
F_103 () ;
}
static T_3 void F_109 ( void )
{
F_110 ( L_3 ) ;
V_5 . V_157 = 0 ;
V_5 . V_158 = NULL ;
}
static int F_111 ( int V_143 )
{
T_4 V_159 = V_160 ;
switch ( F_112 ( V_143 ) . V_161 ) {
case 42 :
V_159 = 0x28 ;
break;
case 45 :
switch ( F_112 ( V_143 ) . V_162 ) {
case 6 : V_159 = 0x618 ; break;
case 7 : V_159 = 0x70c ; break;
}
}
return ( F_112 ( V_143 ) . V_163 < V_159 ) ;
}
static void F_113 ( void )
{
int V_164 = 0 ;
int V_143 ;
F_114 () ;
F_115 (cpu) {
if ( ( V_164 = F_111 ( V_143 ) ) )
break;
}
F_116 () ;
if ( V_164 == V_5 . V_164 )
return;
if ( V_5 . V_164 ) {
F_41 ( L_4 ) ;
V_5 . V_164 = 0 ;
} else {
F_41 ( L_5 ) ;
V_5 . V_164 = 1 ;
}
}
static T_3 void F_117 ( void )
{
V_5 . V_165 = F_113 ;
F_113 () ;
}
static T_3 void F_118 ( void )
{
int V_64 ;
F_54 (bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
V_2 [ V_166 [ V_64 ] . V_167 ] = 0 ;
F_110 ( L_6 ,
V_166 [ V_64 ] . V_168 ) ;
}
}
static T_3 void F_119 ( void )
{
union V_169 V_170 ;
V_170 . V_171 = V_5 . V_172 ;
if ( V_170 . V_173 . V_174 ) {
V_2 [ V_175 ] = 0x7f89 ;
V_170 . V_173 . V_174 = 0 ;
V_5 . V_172 = V_170 . V_171 ;
F_41 ( L_7 ) ;
}
}
T_3 int F_120 ( void )
{
union V_176 V_177 ;
union V_178 V_179 ;
union V_169 V_170 ;
struct V_78 * V_96 ;
unsigned int V_180 ;
int V_45 ;
if ( ! F_121 ( & V_181 , V_182 ) ) {
switch ( V_181 . V_183 ) {
case 0x6 :
return F_122 () ;
case 0xb :
return F_123 () ;
case 0xf :
return F_124 () ;
}
return - V_184 ;
}
F_125 ( 10 , & V_179 . V_171 , & V_170 . V_171 , & V_180 , & V_177 . V_171 ) ;
if ( V_179 . V_173 . V_185 < V_186 )
return - V_184 ;
V_45 = V_179 . V_173 . V_187 ;
if ( V_45 < 2 )
V_5 = V_188 ;
else
V_5 = V_189 ;
V_5 . V_45 = V_45 ;
V_5 . V_55 = V_179 . V_173 . V_55 ;
V_5 . V_190 = V_179 . V_173 . V_191 ;
V_5 . V_192 = ( 1ULL << V_179 . V_173 . V_191 ) - 1 ;
V_5 . V_172 = V_170 . V_171 ;
V_5 . V_193 = V_179 . V_173 . V_185 ;
V_5 . V_194 = F_126 ( unsigned , V_195 , V_5 . V_55 ) ;
if ( V_45 > 1 )
V_5 . V_56 = F_127 ( ( int ) V_177 . V_173 . V_56 , 3 ) ;
if ( F_90 ( V_196 ) ) {
T_1 V_197 ;
F_22 ( V_198 , V_197 ) ;
V_5 . V_6 . V_197 = V_197 ;
}
F_128 () ;
F_129 ( F_118 ) ;
switch ( V_181 . V_161 ) {
case 14 :
F_130 ( L_8 ) ;
break;
case 15 :
F_129 ( F_109 ) ;
case 22 :
case 23 :
case 29 :
memcpy ( V_199 , V_200 ,
sizeof( V_199 ) ) ;
F_131 () ;
V_5 . V_110 = V_201 ;
V_5 . V_158 = V_202 ;
F_130 ( L_9 ) ;
break;
case 26 :
case 30 :
case 46 :
memcpy ( V_199 , V_203 ,
sizeof( V_199 ) ) ;
memcpy ( V_204 , V_205 ,
sizeof( V_204 ) ) ;
F_132 () ;
V_5 . V_110 = V_206 ;
V_5 . V_158 = V_207 ;
V_5 . V_208 = F_20 ;
V_5 . V_91 = V_209 ;
V_5 . V_210 = V_211 ;
V_2 [ V_212 ] =
F_76 ( . V_4 = 0x0e , . V_117 = 0x01 , . V_116 = 1 , . V_111 = 1 ) ;
V_2 [ V_213 ] =
F_76 ( . V_4 = 0xb1 , . V_117 = 0x3f , . V_116 = 1 , . V_111 = 1 ) ;
F_129 ( F_119 ) ;
F_130 ( L_10 ) ;
break;
case 28 :
case 38 :
case 39 :
case 53 :
case 54 :
memcpy ( V_199 , V_214 ,
sizeof( V_199 ) ) ;
F_133 () ;
V_5 . V_110 = V_215 ;
V_5 . V_158 = V_216 ;
F_130 ( L_11 ) ;
break;
case 55 :
case 77 :
memcpy ( V_199 , V_217 ,
sizeof( V_199 ) ) ;
memcpy ( V_204 , V_218 ,
sizeof( V_204 ) ) ;
F_133 () ;
V_5 . V_110 = V_219 ;
V_5 . V_158 = V_220 ;
V_5 . V_91 = V_221 ;
V_5 . V_86 |= V_87 ;
F_130 ( L_12 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_199 , V_222 ,
sizeof( V_199 ) ) ;
memcpy ( V_204 , V_205 ,
sizeof( V_204 ) ) ;
F_132 () ;
V_5 . V_110 = V_223 ;
V_5 . V_208 = F_20 ;
V_5 . V_158 = V_224 ;
V_5 . V_91 = V_225 ;
V_5 . V_86 |= V_87 ;
V_5 . V_210 = V_211 ;
V_2 [ V_212 ] =
F_76 ( . V_4 = 0x0e , . V_117 = 0x01 , . V_116 = 1 , . V_111 = 1 ) ;
V_2 [ V_213 ] =
F_76 ( . V_4 = 0xb1 , . V_117 = 0x3f , . V_116 = 1 , . V_111 = 1 ) ;
F_130 ( L_13 ) ;
break;
case 42 :
case 45 :
F_129 ( F_117 ) ;
memcpy ( V_199 , V_226 ,
sizeof( V_199 ) ) ;
memcpy ( V_204 , V_227 ,
sizeof( V_204 ) ) ;
F_134 () ;
V_5 . V_110 = V_228 ;
V_5 . V_158 = V_229 ;
V_5 . V_119 = F_77 ;
if ( V_181 . V_161 == 45 )
V_5 . V_91 = V_230 ;
else
V_5 . V_91 = V_231 ;
V_5 . V_86 |= V_87 ;
V_5 . V_86 |= V_151 ;
V_5 . V_210 = V_232 ;
V_2 [ V_212 ] =
F_76 ( . V_4 = 0x0e , . V_117 = 0x01 , . V_116 = 1 , . V_111 = 1 ) ;
V_2 [ V_213 ] =
F_76 ( . V_4 = 0xb1 , . V_117 = 0x01 , . V_116 = 1 , . V_111 = 1 ) ;
F_130 ( L_14 ) ;
break;
case 58 :
case 62 :
memcpy ( V_199 , V_226 ,
sizeof( V_199 ) ) ;
memcpy ( V_204 , V_227 ,
sizeof( V_204 ) ) ;
F_134 () ;
V_5 . V_110 = V_233 ;
V_5 . V_158 = V_234 ;
V_5 . V_119 = F_77 ;
if ( V_181 . V_161 == 62 )
V_5 . V_91 = V_230 ;
else
V_5 . V_91 = V_231 ;
V_5 . V_86 |= V_87 ;
V_5 . V_86 |= V_151 ;
V_5 . V_210 = V_232 ;
V_2 [ V_212 ] =
F_76 ( . V_4 = 0x0e , . V_117 = 0x01 , . V_116 = 1 , . V_111 = 1 ) ;
F_130 ( L_15 ) ;
break;
case 60 :
case 70 :
case 71 :
case 63 :
case 69 :
V_5 . V_67 = true ;
memcpy ( V_199 , V_226 , sizeof( V_199 ) ) ;
memcpy ( V_204 , V_227 , sizeof( V_204 ) ) ;
F_134 () ;
V_5 . V_110 = V_235 ;
V_5 . V_158 = V_236 ;
V_5 . V_91 = V_231 ;
V_5 . V_119 = F_77 ;
V_5 . V_86 |= V_87 ;
V_5 . V_86 |= V_151 ;
V_5 . V_237 = F_89 ;
V_5 . V_238 = F_91 ;
V_5 . V_210 = V_239 ;
V_5 . V_240 = true ;
F_130 ( L_16 ) ;
break;
default:
switch ( V_5 . V_45 ) {
case 1 :
V_5 . V_110 = V_241 ;
F_130 ( L_17 ) ;
break;
default:
V_5 . V_110 = V_215 ;
F_130 ( L_18 ) ;
break;
}
}
if ( V_5 . V_55 > V_242 ) {
F_49 ( 1 , V_243 L_19 ,
V_5 . V_55 , V_242 ) ;
V_5 . V_55 = V_242 ;
}
V_5 . V_17 = ( 1 << V_5 . V_55 ) - 1 ;
if ( V_5 . V_56 > V_244 ) {
F_49 ( 1 , V_243 L_20 ,
V_5 . V_56 , V_244 ) ;
V_5 . V_56 = V_244 ;
}
V_5 . V_17 |=
( ( 1LL << V_5 . V_56 ) - 1 ) << V_34 ;
if ( V_5 . V_110 ) {
F_70 (c, x86_pmu.event_constraints) {
if ( V_96 -> V_111 != V_245
|| V_96 -> V_138 == V_246 ) {
continue;
}
V_96 -> V_138 |= ( 1ULL << V_5 . V_55 ) - 1 ;
V_96 -> V_247 += V_5 . V_55 ;
}
}
if ( V_5 . V_6 . V_248 ) {
V_5 . V_249 = V_5 . V_192 ;
V_5 . V_250 = V_251 ;
F_130 ( L_21 ) ;
}
return 0 ;
}
