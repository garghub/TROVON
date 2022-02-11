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
static void F_25 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_4 -> V_20 ;
struct V_11 * V_12 = & F_5 ( V_11 ) ;
if ( F_26 ( V_32 -> V_33 == V_14 ) ) {
F_8 () ;
F_27 () ;
return;
}
V_12 -> V_18 &= ~ ( 1ull << V_32 -> V_33 ) ;
V_12 -> V_38 &= ~ ( 1ull << V_32 -> V_33 ) ;
if ( F_2 ( V_4 ) )
F_28 ( V_4 ) ;
if ( F_26 ( V_32 -> V_37 == V_39 ) ) {
F_24 ( V_32 ) ;
return;
}
F_29 ( V_4 ) ;
if ( F_26 ( V_4 -> V_8 . V_9 ) )
F_30 ( V_4 ) ;
}
static void F_31 ( struct V_31 * V_32 )
{
int V_33 = V_32 -> V_33 - V_34 ;
T_1 V_35 , V_40 , V_36 ;
V_40 = 0x8ULL ;
if ( V_32 -> V_21 & V_41 )
V_40 |= 0x2 ;
if ( V_32 -> V_21 & V_42 )
V_40 |= 0x1 ;
if ( V_5 . V_43 > 2 && V_32 -> V_21 & V_44 )
V_40 |= 0x4 ;
V_40 <<= ( V_33 * 4 ) ;
V_36 = 0xfULL << ( V_33 * 4 ) ;
F_22 ( V_32 -> V_37 , V_35 ) ;
V_35 &= ~ V_36 ;
V_35 |= V_40 ;
F_6 ( V_32 -> V_37 , V_35 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_4 -> V_20 ;
struct V_11 * V_12 = & F_5 ( V_11 ) ;
if ( F_26 ( V_32 -> V_33 == V_14 ) ) {
if ( ! F_33 ( V_11 . V_45 ) )
return;
F_15 ( V_32 -> V_21 ) ;
return;
}
if ( F_2 ( V_4 ) )
F_34 ( V_4 ) ;
if ( V_4 -> V_8 . V_46 )
V_12 -> V_18 |= ( 1ull << V_32 -> V_33 ) ;
if ( V_4 -> V_8 . V_47 )
V_12 -> V_38 |= ( 1ull << V_32 -> V_33 ) ;
if ( F_26 ( V_32 -> V_37 == V_39 ) ) {
F_31 ( V_32 ) ;
return;
}
if ( F_26 ( V_4 -> V_8 . V_9 ) )
F_35 ( V_4 ) ;
F_19 ( V_32 , V_26 ) ;
}
int F_36 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
return F_18 ( V_4 ) ;
}
static void F_37 ( void )
{
struct V_48 * V_49 = F_33 ( V_11 . V_49 ) ;
unsigned long V_50 ;
int V_33 ;
if ( ! V_5 . V_51 )
return;
F_38 ( V_50 ) ;
F_39 ( L_1 , F_40 () ) ;
for ( V_33 = 0 ; V_33 < V_5 . V_51 ; V_33 ++ ) {
F_41 ( F_42 ( V_33 ) , 0ull ) ;
F_41 ( F_43 ( V_33 ) , 0ull ) ;
}
for ( V_33 = 0 ; V_33 < V_5 . V_52 ; V_33 ++ )
F_41 ( V_53 + V_33 , 0ull ) ;
if ( V_49 )
V_49 -> V_54 = V_49 -> V_55 ;
F_44 ( V_50 ) ;
}
static int F_45 ( struct V_56 * V_57 )
{
struct V_58 V_59 ;
struct V_11 * V_12 ;
int V_60 , V_61 ;
T_1 V_27 ;
int V_62 ;
V_12 = & F_5 ( V_11 ) ;
if ( ! V_5 . V_63 )
F_46 ( V_64 , V_65 ) ;
F_4 () ;
V_62 = F_27 () ;
V_27 = F_21 () ;
if ( ! V_27 ) {
F_11 ( 0 ) ;
return V_62 ;
}
V_61 = 0 ;
V_66:
F_23 ( V_27 ) ;
if ( ++ V_61 > 100 ) {
static bool V_67 = false ;
if ( ! V_67 ) {
F_47 ( 1 , L_2 ) ;
F_48 () ;
V_67 = true ;
}
F_37 () ;
goto V_68;
}
F_49 ( V_69 ) ;
F_50 () ;
if ( F_51 ( 62 , ( unsigned long * ) & V_27 ) ) {
V_62 ++ ;
V_5 . V_70 ( V_57 ) ;
}
F_52 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_3 * V_4 = V_12 -> V_19 [ V_60 ] ;
V_62 ++ ;
if ( ! F_7 ( V_60 , V_12 -> V_15 ) )
continue;
if ( ! F_36 ( V_4 ) )
continue;
F_53 ( & V_59 , 0 , V_4 -> V_20 . V_71 ) ;
if ( F_3 ( V_4 ) )
V_59 . V_72 = & V_12 -> V_73 ;
if ( F_54 ( V_4 , & V_59 , V_57 ) )
F_55 ( V_4 , 0 ) ;
}
V_27 = F_21 () ;
if ( V_27 )
goto V_66;
V_68:
F_11 ( 0 ) ;
if ( V_5 . V_63 )
F_46 ( V_64 , V_65 ) ;
return V_62 ;
}
static struct V_74 *
F_56 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_4 -> V_20 ;
unsigned int V_1 , V_75 ;
if ( V_4 -> V_8 . V_76 )
return NULL ;
V_1 = V_32 -> V_21 & V_77 ;
V_75 = V_5 . V_78 ( V_79 ) ;
if ( F_26 ( V_1 == V_75 && V_32 -> V_80 == 1 ) )
return & V_81 ;
return NULL ;
}
static int F_57 ( int V_33 )
{
if ( ! ( V_5 . V_82 & V_83 ) )
return V_33 ;
if ( V_33 == V_84 )
return V_85 ;
if ( V_33 == V_85 )
return V_84 ;
return V_33 ;
}
static void F_58 ( struct V_3 * V_4 , int V_33 )
{
V_4 -> V_20 . V_86 . V_33 = V_33 ;
if ( V_33 == V_84 ) {
V_4 -> V_20 . V_21 &= ~ V_77 ;
V_4 -> V_20 . V_21 |= 0x01b7 ;
V_4 -> V_20 . V_86 . V_87 = V_88 ;
} else if ( V_33 == V_85 ) {
V_4 -> V_20 . V_21 &= ~ V_77 ;
V_4 -> V_20 . V_21 |= 0x01bb ;
V_4 -> V_20 . V_86 . V_87 = V_89 ;
}
}
static struct V_74 *
F_59 ( struct V_11 * V_12 ,
struct V_3 * V_4 ,
struct V_90 * V_87 )
{
struct V_74 * V_91 = & V_92 ;
struct V_93 * V_94 ;
unsigned long V_50 ;
int V_33 = V_87 -> V_33 ;
if ( V_87 -> V_95 && ! V_12 -> V_96 )
return NULL ;
V_66:
V_94 = & V_12 -> V_97 -> V_57 [ V_33 ] ;
F_60 ( & V_94 -> V_98 , V_50 ) ;
if ( ! F_61 ( & V_94 -> V_99 ) || V_94 -> V_21 == V_87 -> V_21 ) {
if ( ! V_12 -> V_96 ) {
if ( V_33 != V_87 -> V_33 )
F_58 ( V_4 , V_33 ) ;
V_87 -> V_95 = 1 ;
}
V_94 -> V_21 = V_87 -> V_21 ;
V_94 -> V_87 = V_87 -> V_87 ;
F_62 ( & V_94 -> V_99 ) ;
V_91 = NULL ;
} else {
V_33 = F_57 ( V_33 ) ;
if ( V_33 != V_87 -> V_33 ) {
F_63 ( & V_94 -> V_98 , V_50 ) ;
goto V_66;
}
}
F_63 ( & V_94 -> V_98 , V_50 ) ;
return V_91 ;
}
static void
F_64 ( struct V_11 * V_12 ,
struct V_90 * V_87 )
{
struct V_93 * V_94 ;
if ( ! V_87 -> V_95 || V_12 -> V_96 )
return;
V_94 = & V_12 -> V_97 -> V_57 [ V_87 -> V_33 ] ;
F_65 ( & V_94 -> V_99 ) ;
V_87 -> V_95 = 0 ;
}
static struct V_74 *
F_66 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_74 * V_91 = NULL , * V_100 ;
struct V_90 * V_101 , * V_102 ;
V_101 = & V_4 -> V_20 . V_86 ;
if ( V_101 -> V_33 != V_103 ) {
V_91 = F_59 ( V_12 , V_4 , V_101 ) ;
if ( V_91 == & V_92 )
return V_91 ;
}
V_102 = & V_4 -> V_20 . V_104 ;
if ( V_102 -> V_33 != V_103 ) {
V_100 = F_59 ( V_12 , V_4 , V_102 ) ;
if ( V_100 == & V_92 ) {
F_64 ( V_12 , V_101 ) ;
V_91 = V_100 ;
}
}
return V_91 ;
}
struct V_74 *
F_67 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
struct V_74 * V_91 ;
if ( V_5 . V_105 ) {
F_68 (c, x86_pmu.event_constraints) {
if ( ( V_4 -> V_20 . V_21 & V_91 -> V_106 ) == V_91 -> V_107 ) {
V_4 -> V_20 . V_50 |= V_91 -> V_50 ;
return V_91 ;
}
}
}
return & V_108 ;
}
static struct V_74 *
F_69 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
struct V_74 * V_91 ;
V_91 = F_56 ( V_4 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_70 ( V_4 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_66 ( V_12 , V_4 ) ;
if ( V_91 )
return V_91 ;
return F_67 ( V_12 , V_4 ) ;
}
static void
F_71 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_90 * V_87 ;
V_87 = & V_4 -> V_20 . V_86 ;
if ( V_87 -> V_33 != V_103 )
F_64 ( V_12 , V_87 ) ;
V_87 = & V_4 -> V_20 . V_104 ;
if ( V_87 -> V_33 != V_103 )
F_64 ( V_12 , V_87 ) ;
}
static void F_72 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
F_71 ( V_12 , V_4 ) ;
}
static void F_73 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_20 . V_21 & V_109 ) == 0x003c ) {
T_1 V_110 = F_74 ( . V_4 = 0xc0 , . V_111 = 1 , . V_106 = 16 ) ;
V_110 |= ( V_4 -> V_20 . V_21 & ~ V_109 ) ;
V_4 -> V_20 . V_21 = V_110 ;
}
}
static void F_75 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_20 . V_21 & V_109 ) == 0x003c ) {
T_1 V_110 = F_74 ( . V_4 = 0xc2 , . V_112 = 0x01 , . V_111 = 1 , . V_106 = 16 ) ;
V_110 |= ( V_4 -> V_20 . V_21 & ~ V_109 ) ;
V_4 -> V_20 . V_21 = V_110 ;
}
}
static int F_76 ( struct V_3 * V_4 )
{
int V_113 = F_77 ( V_4 ) ;
if ( V_113 )
return V_113 ;
if ( V_4 -> V_8 . V_9 && V_5 . V_114 )
V_5 . V_114 ( V_4 ) ;
if ( F_2 ( V_4 ) ) {
V_113 = F_78 ( V_4 ) ;
if ( V_113 )
return V_113 ;
}
if ( V_4 -> V_8 . type != V_115 )
return 0 ;
if ( ! ( V_4 -> V_8 . V_21 & V_44 ) )
return 0 ;
if ( V_5 . V_43 < 3 )
return - V_116 ;
if ( F_79 () && ! F_80 ( V_117 ) )
return - V_118 ;
V_4 -> V_20 . V_21 |= V_44 ;
return 0 ;
}
struct V_119 * F_81 ( int * V_120 )
{
if ( V_5 . V_121 )
return V_5 . V_121 ( V_120 ) ;
* V_120 = 0 ;
return NULL ;
}
static struct V_119 * F_82 ( int * V_120 )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
struct V_119 * V_122 = V_12 -> V_123 ;
V_122 [ 0 ] . V_124 = V_13 ;
V_122 [ 0 ] . V_125 = V_5 . V_17 & ~ V_12 -> V_18 ;
V_122 [ 0 ] . V_126 = V_5 . V_17 & ~ V_12 -> V_38 ;
V_122 [ 1 ] . V_124 = V_127 ;
V_122 [ 1 ] . V_125 = V_12 -> V_128 ;
V_122 [ 1 ] . V_126 = 0 ;
* V_120 = 2 ;
return V_122 ;
}
static struct V_119 * F_83 ( int * V_120 )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
struct V_119 * V_122 = V_12 -> V_123 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_5 . V_51 ; V_33 ++ ) {
struct V_3 * V_4 = V_12 -> V_19 [ V_33 ] ;
V_122 [ V_33 ] . V_124 = F_42 ( V_33 ) ;
V_122 [ V_33 ] . V_125 = V_122 [ V_33 ] . V_126 = 0 ;
if ( ! F_7 ( V_33 , V_12 -> V_15 ) )
continue;
V_122 [ V_33 ] . V_125 = V_122 [ V_33 ] . V_126 =
V_4 -> V_20 . V_21 | V_26 ;
if ( V_4 -> V_8 . V_46 )
V_122 [ V_33 ] . V_125 &= ~ V_26 ;
else if ( V_4 -> V_8 . V_47 )
V_122 [ V_33 ] . V_126 &= ~ V_26 ;
}
* V_120 = V_5 . V_51 ;
return V_122 ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_8 . V_46 )
F_85 ( V_4 ) ;
}
static void F_86 ( int V_16 )
{
struct V_11 * V_12 = & F_5 ( V_11 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_5 . V_51 ; V_33 ++ ) {
struct V_31 * V_32 = & V_12 -> V_19 [ V_33 ] -> V_20 ;
if ( ! F_7 ( V_33 , V_12 -> V_15 ) ||
V_12 -> V_19 [ V_33 ] -> V_8 . V_46 )
continue;
F_19 ( V_32 , V_26 ) ;
}
}
static int F_87 ( struct V_3 * V_4 )
{
int V_113 = F_76 ( V_4 ) ;
if ( V_113 )
return V_113 ;
if ( ! F_88 ( V_129 ) && ! F_88 ( V_130 ) )
return 0 ;
V_4 -> V_20 . V_21 |= V_4 -> V_8 . V_21 & ( V_131 | V_132 ) ;
if ( ( V_4 -> V_20 . V_21 & ( V_131 | V_132 ) ) &&
( ( V_4 -> V_20 . V_21 & V_44 ) ||
V_4 -> V_8 . V_9 > 0 ) )
return - V_133 ;
return 0 ;
}
static struct V_74 *
F_89 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
struct V_74 * V_91 = F_69 ( V_12 , V_4 ) ;
if ( V_4 -> V_20 . V_21 & V_132 ) {
if ( V_91 -> V_134 & ( 1U << 2 ) )
return & V_135 ;
return & V_92 ;
}
return V_91 ;
}
T_2 F_90 ( char * V_136 , T_1 V_21 )
{
T_1 V_4 = ( V_21 & V_137 ) ;
return F_91 ( V_136 , V_21 , V_4 ) ;
}
struct V_138 * F_92 ( int V_139 )
{
struct V_138 * V_57 ;
int V_23 ;
V_57 = F_93 ( sizeof( struct V_138 ) ,
V_140 , F_94 ( V_139 ) ) ;
if ( V_57 ) {
for ( V_23 = 0 ; V_23 < V_141 ; V_23 ++ )
F_95 ( & V_57 -> V_57 [ V_23 ] . V_98 ) ;
V_57 -> V_142 = - 1 ;
}
return V_57 ;
}
static int F_96 ( int V_139 )
{
struct V_11 * V_12 = & F_97 ( V_11 , V_139 ) ;
if ( ! ( V_5 . V_143 || V_5 . V_144 ) )
return V_145 ;
V_12 -> V_97 = F_92 ( V_139 ) ;
if ( ! V_12 -> V_97 )
return V_146 ;
return V_145 ;
}
static void F_98 ( int V_139 )
{
struct V_11 * V_12 = & F_97 ( V_11 , V_139 ) ;
int V_142 = F_99 ( V_139 ) ;
int V_23 ;
F_100 ( V_139 ) ;
F_101 () ;
V_12 -> V_147 = NULL ;
if ( ! V_12 -> V_97 )
return;
if ( ! ( V_5 . V_82 & V_148 ) ) {
F_102 (i, topology_thread_cpumask(cpu)) {
struct V_138 * V_149 ;
V_149 = F_97 ( V_11 , V_23 ) . V_97 ;
if ( V_149 && V_149 -> V_142 == V_142 ) {
V_12 -> V_150 = V_12 -> V_97 ;
V_12 -> V_97 = V_149 ;
break;
}
}
V_12 -> V_97 -> V_142 = V_142 ;
V_12 -> V_97 -> V_151 ++ ;
}
if ( V_5 . V_144 )
V_12 -> V_147 = & V_12 -> V_97 -> V_57 [ V_152 ] ;
}
static void F_103 ( int V_139 )
{
struct V_11 * V_12 = & F_97 ( V_11 , V_139 ) ;
struct V_138 * V_149 ;
V_149 = V_12 -> V_97 ;
if ( V_149 ) {
if ( V_149 -> V_142 == - 1 || -- V_149 -> V_151 == 0 )
F_104 ( V_149 ) ;
V_12 -> V_97 = NULL ;
}
F_105 ( V_139 ) ;
}
static void F_106 ( void )
{
if ( V_5 . V_153 )
F_101 () ;
}
static T_3 void F_107 ( void )
{
F_108 ( L_3 ) ;
V_5 . V_154 = 0 ;
V_5 . V_155 = NULL ;
}
static int F_109 ( int V_139 )
{
T_4 V_156 = V_157 ;
switch ( F_110 ( V_139 ) . V_158 ) {
case 42 :
V_156 = 0x28 ;
break;
case 45 :
switch ( F_110 ( V_139 ) . V_159 ) {
case 6 : V_156 = 0x618 ; break;
case 7 : V_156 = 0x70c ; break;
}
}
return ( F_110 ( V_139 ) . V_160 < V_156 ) ;
}
static void F_111 ( void )
{
int V_161 = 0 ;
int V_139 ;
F_112 () ;
F_113 (cpu) {
if ( ( V_161 = F_109 ( V_139 ) ) )
break;
}
F_114 () ;
if ( V_161 == V_5 . V_161 )
return;
if ( V_5 . V_161 ) {
F_39 ( L_4 ) ;
V_5 . V_161 = 0 ;
} else {
F_39 ( L_5 ) ;
V_5 . V_161 = 1 ;
}
}
static T_3 void F_115 ( void )
{
V_5 . V_162 = F_111 ;
F_111 () ;
}
static T_3 void F_116 ( void )
{
int V_60 ;
F_52 (bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
V_2 [ V_163 [ V_60 ] . V_164 ] = 0 ;
F_108 ( L_6 ,
V_163 [ V_60 ] . V_165 ) ;
}
}
static T_3 void F_117 ( void )
{
union V_166 V_167 ;
V_167 . V_168 = V_5 . V_169 ;
if ( V_167 . V_170 . V_171 ) {
V_2 [ V_172 ] = 0x7f89 ;
V_167 . V_170 . V_171 = 0 ;
V_5 . V_169 = V_167 . V_168 ;
F_39 ( L_7 ) ;
}
}
T_3 int F_118 ( void )
{
union V_173 V_174 ;
union V_175 V_176 ;
union V_166 V_167 ;
struct V_74 * V_91 ;
unsigned int V_177 ;
int V_43 ;
if ( ! F_119 ( & V_178 , V_179 ) ) {
switch ( V_178 . V_180 ) {
case 0x6 :
return F_120 () ;
case 0xb :
return F_121 () ;
case 0xf :
return F_122 () ;
}
return - V_181 ;
}
F_123 ( 10 , & V_176 . V_168 , & V_167 . V_168 , & V_177 , & V_174 . V_168 ) ;
if ( V_176 . V_170 . V_182 < V_183 )
return - V_181 ;
V_43 = V_176 . V_170 . V_184 ;
if ( V_43 < 2 )
V_5 = V_185 ;
else
V_5 = V_186 ;
V_5 . V_43 = V_43 ;
V_5 . V_51 = V_176 . V_170 . V_51 ;
V_5 . V_187 = V_176 . V_170 . V_188 ;
V_5 . V_189 = ( 1ULL << V_176 . V_170 . V_188 ) - 1 ;
V_5 . V_169 = V_167 . V_168 ;
V_5 . V_190 = V_176 . V_170 . V_182 ;
V_5 . V_191 = F_124 ( unsigned , V_192 , V_5 . V_51 ) ;
if ( V_43 > 1 )
V_5 . V_52 = F_125 ( ( int ) V_174 . V_170 . V_52 , 3 ) ;
if ( V_43 > 1 ) {
T_1 V_193 ;
F_22 ( V_194 , V_193 ) ;
V_5 . V_6 . V_193 = V_193 ;
}
F_126 () ;
F_127 ( F_116 ) ;
switch ( V_178 . V_158 ) {
case 14 :
F_128 ( L_8 ) ;
break;
case 15 :
F_127 ( F_107 ) ;
case 22 :
case 23 :
case 29 :
memcpy ( V_195 , V_196 ,
sizeof( V_195 ) ) ;
F_129 () ;
V_5 . V_105 = V_197 ;
V_5 . V_155 = V_198 ;
F_128 ( L_9 ) ;
break;
case 26 :
case 30 :
case 46 :
memcpy ( V_195 , V_199 ,
sizeof( V_195 ) ) ;
memcpy ( V_200 , V_201 ,
sizeof( V_200 ) ) ;
F_130 () ;
V_5 . V_105 = V_202 ;
V_5 . V_155 = V_203 ;
V_5 . V_204 = F_20 ;
V_5 . V_143 = V_205 ;
V_5 . V_206 = V_207 ;
V_2 [ V_208 ] =
F_74 ( . V_4 = 0x0e , . V_112 = 0x01 , . V_111 = 1 , . V_106 = 1 ) ;
V_2 [ V_209 ] =
F_74 ( . V_4 = 0xb1 , . V_112 = 0x3f , . V_111 = 1 , . V_106 = 1 ) ;
F_127 ( F_117 ) ;
F_128 ( L_10 ) ;
break;
case 28 :
case 38 :
case 39 :
case 53 :
case 54 :
memcpy ( V_195 , V_210 ,
sizeof( V_195 ) ) ;
F_131 () ;
V_5 . V_105 = V_211 ;
V_5 . V_155 = V_212 ;
F_128 ( L_11 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_195 , V_213 ,
sizeof( V_195 ) ) ;
memcpy ( V_200 , V_201 ,
sizeof( V_200 ) ) ;
F_130 () ;
V_5 . V_105 = V_214 ;
V_5 . V_204 = F_20 ;
V_5 . V_155 = V_215 ;
V_5 . V_143 = V_216 ;
V_5 . V_82 |= V_83 ;
V_5 . V_206 = V_207 ;
V_2 [ V_208 ] =
F_74 ( . V_4 = 0x0e , . V_112 = 0x01 , . V_111 = 1 , . V_106 = 1 ) ;
V_2 [ V_209 ] =
F_74 ( . V_4 = 0xb1 , . V_112 = 0x3f , . V_111 = 1 , . V_106 = 1 ) ;
F_128 ( L_12 ) ;
break;
case 42 :
case 45 :
F_127 ( F_115 ) ;
memcpy ( V_195 , V_217 ,
sizeof( V_195 ) ) ;
memcpy ( V_200 , V_218 ,
sizeof( V_200 ) ) ;
F_132 () ;
V_5 . V_105 = V_219 ;
V_5 . V_155 = V_220 ;
V_5 . V_114 = F_75 ;
if ( V_178 . V_158 == 45 )
V_5 . V_143 = V_221 ;
else
V_5 . V_143 = V_222 ;
V_5 . V_82 |= V_83 ;
V_5 . V_82 |= V_148 ;
V_5 . V_206 = V_223 ;
V_2 [ V_208 ] =
F_74 ( . V_4 = 0x0e , . V_112 = 0x01 , . V_111 = 1 , . V_106 = 1 ) ;
V_2 [ V_209 ] =
F_74 ( . V_4 = 0xb1 , . V_112 = 0x01 , . V_111 = 1 , . V_106 = 1 ) ;
F_128 ( L_13 ) ;
break;
case 58 :
case 62 :
memcpy ( V_195 , V_217 ,
sizeof( V_195 ) ) ;
memcpy ( V_200 , V_218 ,
sizeof( V_200 ) ) ;
F_132 () ;
V_5 . V_105 = V_224 ;
V_5 . V_155 = V_225 ;
V_5 . V_114 = F_75 ;
if ( V_178 . V_158 == 62 )
V_5 . V_143 = V_221 ;
else
V_5 . V_143 = V_222 ;
V_5 . V_82 |= V_83 ;
V_5 . V_82 |= V_148 ;
V_5 . V_206 = V_223 ;
V_2 [ V_208 ] =
F_74 ( . V_4 = 0x0e , . V_112 = 0x01 , . V_111 = 1 , . V_106 = 1 ) ;
F_128 ( L_14 ) ;
break;
case 60 :
case 70 :
case 71 :
case 63 :
case 69 :
V_5 . V_63 = true ;
memcpy ( V_195 , V_217 , sizeof( V_195 ) ) ;
memcpy ( V_200 , V_218 , sizeof( V_200 ) ) ;
F_132 () ;
V_5 . V_105 = V_226 ;
V_5 . V_155 = V_227 ;
V_5 . V_143 = V_222 ;
V_5 . V_114 = F_75 ;
V_5 . V_82 |= V_83 ;
V_5 . V_82 |= V_148 ;
V_5 . V_228 = F_87 ;
V_5 . V_229 = F_89 ;
V_5 . V_206 = V_230 ;
F_128 ( L_15 ) ;
break;
default:
switch ( V_5 . V_43 ) {
case 1 :
V_5 . V_105 = V_231 ;
F_128 ( L_16 ) ;
break;
default:
V_5 . V_105 = V_211 ;
F_128 ( L_17 ) ;
break;
}
}
if ( V_5 . V_51 > V_232 ) {
F_47 ( 1 , V_233 L_18 ,
V_5 . V_51 , V_232 ) ;
V_5 . V_51 = V_232 ;
}
V_5 . V_17 = ( 1 << V_5 . V_51 ) - 1 ;
if ( V_5 . V_52 > V_234 ) {
F_47 ( 1 , V_233 L_19 ,
V_5 . V_52 , V_234 ) ;
V_5 . V_52 = V_234 ;
}
V_5 . V_17 |=
( ( 1LL << V_5 . V_52 ) - 1 ) << V_34 ;
if ( V_5 . V_105 ) {
F_68 (c, x86_pmu.event_constraints) {
if ( V_91 -> V_106 != V_235
|| V_91 -> V_134 == V_236 ) {
continue;
}
V_91 -> V_134 |= ( 1ULL << V_5 . V_51 ) - 1 ;
V_91 -> V_237 += V_5 . V_51 ;
}
}
if ( V_5 . V_6 . V_238 ) {
V_5 . V_239 = V_5 . V_189 ;
V_5 . V_240 = V_241 ;
F_128 ( L_20 ) ;
}
return 0 ;
}
