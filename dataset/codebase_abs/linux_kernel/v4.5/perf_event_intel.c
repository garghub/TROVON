static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static void F_2 ( void )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
F_4 ( V_5 , 0 ) ;
if ( F_5 ( V_6 , V_4 -> V_7 ) )
F_6 () ;
else
F_7 () ;
F_8 () ;
}
static void F_9 ( void )
{
F_2 () ;
F_10 () ;
}
static void F_11 ( int V_8 , bool V_9 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
F_12 () ;
F_13 ( V_9 ) ;
F_4 ( V_5 ,
V_10 . V_11 & ~ V_4 -> V_12 ) ;
if ( F_5 ( V_6 , V_4 -> V_7 ) ) {
struct V_13 * V_14 =
V_4 -> V_15 [ V_6 ] ;
if ( F_14 ( ! V_14 ) )
return;
F_15 ( V_14 -> V_16 . V_17 ) ;
} else
F_16 () ;
}
static void F_17 ( int V_8 )
{
F_11 ( V_8 , false ) ;
}
static void F_18 ( void )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
static const unsigned long V_18 [ 4 ] = {
0x4300B5 ,
0x4300D2 ,
0x4300B1 ,
0x4300B1
} ;
struct V_13 * V_14 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_14 = V_4 -> V_15 [ V_19 ] ;
if ( V_14 )
F_19 ( V_14 ) ;
}
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_4 ( V_20 + V_19 , V_18 [ V_19 ] ) ;
F_4 ( V_21 + V_19 , 0x0 ) ;
}
F_4 ( V_5 , 0xf ) ;
F_4 ( V_5 , 0x0 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_14 = V_4 -> V_15 [ V_19 ] ;
if ( V_14 ) {
F_20 ( V_14 ) ;
F_21 ( & V_14 -> V_16 ,
V_22 ) ;
} else
F_4 ( V_20 + V_19 , 0x0 ) ;
}
}
static void F_22 ( int V_8 )
{
if ( V_8 )
F_18 () ;
F_17 ( V_8 ) ;
}
static inline T_1 F_23 ( void )
{
T_1 V_23 ;
F_24 ( V_24 , V_23 ) ;
return V_23 ;
}
static inline void F_25 ( T_1 V_25 )
{
F_4 ( V_26 , V_25 ) ;
}
static void F_26 ( struct V_27 * V_28 )
{
int V_29 = V_28 -> V_29 - V_30 ;
T_1 V_31 , V_32 ;
V_32 = 0xfULL << ( V_29 * 4 ) ;
F_24 ( V_28 -> V_33 , V_31 ) ;
V_31 &= ~ V_32 ;
F_4 ( V_28 -> V_33 , V_31 ) ;
}
static inline bool F_27 ( struct V_13 * V_14 )
{
return ( V_14 -> V_16 . V_17 & V_34 ) != 0 ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_16 ;
struct V_3 * V_4 = F_3 ( & V_3 ) ;
if ( F_29 ( V_28 -> V_29 == V_6 ) ) {
F_6 () ;
F_30 () ;
return;
}
V_4 -> V_12 &= ~ ( 1ull << V_28 -> V_29 ) ;
V_4 -> V_35 &= ~ ( 1ull << V_28 -> V_29 ) ;
V_4 -> V_36 &= ~ ( 1ull << V_28 -> V_29 ) ;
if ( F_31 ( V_14 ) )
F_32 ( V_14 ) ;
if ( F_29 ( V_28 -> V_33 == V_37 ) ) {
F_26 ( V_28 ) ;
return;
}
F_33 ( V_14 ) ;
if ( F_29 ( V_14 -> V_38 . V_39 ) )
F_34 ( V_14 ) ;
}
static void F_35 ( struct V_27 * V_28 )
{
int V_29 = V_28 -> V_29 - V_30 ;
T_1 V_31 , V_40 , V_32 ;
V_40 = 0x8ULL ;
if ( V_28 -> V_17 & V_41 )
V_40 |= 0x2 ;
if ( V_28 -> V_17 & V_42 )
V_40 |= 0x1 ;
if ( V_10 . V_43 > 2 && V_28 -> V_17 & V_44 )
V_40 |= 0x4 ;
V_40 <<= ( V_29 * 4 ) ;
V_32 = 0xfULL << ( V_29 * 4 ) ;
F_24 ( V_28 -> V_33 , V_31 ) ;
V_31 &= ~ V_32 ;
V_31 |= V_40 ;
F_4 ( V_28 -> V_33 , V_31 ) ;
}
static void F_36 ( struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_16 ;
struct V_3 * V_4 = F_3 ( & V_3 ) ;
if ( F_29 ( V_28 -> V_29 == V_6 ) ) {
if ( ! F_37 ( V_3 . V_45 ) )
return;
F_15 ( V_28 -> V_17 ) ;
return;
}
if ( F_31 ( V_14 ) )
F_38 ( V_14 ) ;
if ( V_14 -> V_38 . V_46 )
V_4 -> V_12 |= ( 1ull << V_28 -> V_29 ) ;
if ( V_14 -> V_38 . V_47 )
V_4 -> V_35 |= ( 1ull << V_28 -> V_29 ) ;
if ( F_29 ( F_27 ( V_14 ) ) )
V_4 -> V_36 |= ( 1ull << V_28 -> V_29 ) ;
if ( F_29 ( V_28 -> V_33 == V_37 ) ) {
F_35 ( V_28 ) ;
return;
}
if ( F_29 ( V_14 -> V_38 . V_39 ) )
F_39 ( V_14 ) ;
F_21 ( V_28 , V_22 ) ;
}
int F_40 ( struct V_13 * V_14 )
{
F_19 ( V_14 ) ;
if ( F_29 ( F_27 ( V_14 ) ) ) {
F_4 ( V_14 -> V_16 . V_48 , 0 ) ;
F_41 ( & V_14 -> V_16 . V_49 , 0 ) ;
}
return F_20 ( V_14 ) ;
}
static void F_42 ( void )
{
struct V_50 * V_51 = F_37 ( V_3 . V_51 ) ;
unsigned long V_52 ;
int V_29 ;
if ( ! V_10 . V_53 )
return;
F_43 ( V_52 ) ;
F_44 ( L_1 , F_45 () ) ;
for ( V_29 = 0 ; V_29 < V_10 . V_53 ; V_29 ++ ) {
F_46 ( F_47 ( V_29 ) , 0ull ) ;
F_46 ( F_48 ( V_29 ) , 0ull ) ;
}
for ( V_29 = 0 ; V_29 < V_10 . V_54 ; V_29 ++ )
F_46 ( V_55 + V_29 , 0ull ) ;
if ( V_51 )
V_51 -> V_56 = V_51 -> V_57 ;
if ( V_10 . V_43 >= 2 ) {
F_25 ( F_23 () ) ;
F_4 ( V_5 , 0 ) ;
}
if ( V_10 . V_58 ) {
F_49 ( F_50 () &
~ ( V_59 | V_60 ) ) ;
}
F_51 ( V_52 ) ;
}
static int F_52 ( struct V_61 * V_62 )
{
struct V_63 V_64 ;
struct V_3 * V_4 ;
int V_65 , V_66 ;
T_1 V_23 ;
int V_67 ;
V_4 = F_3 ( & V_3 ) ;
if ( ! V_10 . V_68 )
F_53 ( V_69 , V_70 ) ;
F_2 () ;
V_67 = F_30 () ;
V_67 += F_54 () ;
V_23 = F_23 () ;
if ( ! V_23 )
goto V_71;
V_66 = 0 ;
V_72:
F_55 () ;
F_25 ( V_23 ) ;
if ( ++ V_66 > 100 ) {
static bool V_73 = false ;
if ( ! V_73 ) {
F_56 ( 1 , L_2 ) ;
F_57 () ;
V_73 = true ;
}
F_42 () ;
goto V_71;
}
F_58 ( V_74 ) ;
V_23 &= ~ ( V_75 |
V_76 |
V_77 ) ;
if ( ! V_23 )
goto V_71;
if ( F_59 ( 62 , ( unsigned long * ) & V_23 ) ) {
V_67 ++ ;
V_10 . V_78 ( V_62 ) ;
}
if ( F_59 ( 55 , ( unsigned long * ) & V_23 ) ) {
V_67 ++ ;
F_60 () ;
}
V_23 |= V_4 -> V_36 ;
F_61 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_13 * V_14 = V_4 -> V_15 [ V_65 ] ;
V_67 ++ ;
if ( ! F_5 ( V_65 , V_4 -> V_7 ) )
continue;
if ( ! F_40 ( V_14 ) )
continue;
F_62 ( & V_64 , 0 , V_14 -> V_16 . V_79 ) ;
if ( F_63 ( V_14 ) )
V_64 . V_80 = & V_4 -> V_81 ;
if ( F_64 ( V_14 , & V_64 , V_62 ) )
F_65 ( V_14 , 0 ) ;
}
V_23 = F_23 () ;
if ( V_23 )
goto V_72;
V_71:
F_11 ( 0 , true ) ;
if ( V_10 . V_68 )
F_53 ( V_69 , V_70 ) ;
return V_67 ;
}
static struct V_82 *
F_66 ( struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_16 ;
unsigned int V_1 , V_83 ;
if ( V_14 -> V_38 . V_84 )
return NULL ;
V_1 = V_28 -> V_17 & V_85 ;
V_83 = V_10 . V_86 ( V_87 ) ;
if ( F_29 ( V_1 == V_83 && V_28 -> V_88 == 1 ) )
return & V_89 ;
return NULL ;
}
static int F_67 ( int V_29 , T_1 V_17 )
{
int V_90 = V_29 ;
if ( ! ( V_10 . V_52 & V_91 ) )
return V_29 ;
if ( V_29 == V_92 )
V_90 = V_93 ;
if ( V_29 == V_93 )
V_90 = V_92 ;
if ( V_17 & ~ V_10 . V_94 [ V_90 ] . V_95 )
return V_29 ;
return V_90 ;
}
static void F_68 ( struct V_13 * V_14 , int V_29 )
{
V_14 -> V_16 . V_96 . V_29 = V_29 ;
if ( V_29 == V_92 ) {
V_14 -> V_16 . V_17 &= ~ V_85 ;
V_14 -> V_16 . V_17 |= V_10 . V_94 [ V_92 ] . V_14 ;
V_14 -> V_16 . V_96 . V_97 = V_98 ;
} else if ( V_29 == V_93 ) {
V_14 -> V_16 . V_17 &= ~ V_85 ;
V_14 -> V_16 . V_17 |= V_10 . V_94 [ V_93 ] . V_14 ;
V_14 -> V_16 . V_96 . V_97 = V_99 ;
}
}
static struct V_82 *
F_69 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
struct V_100 * V_97 )
{
struct V_82 * V_101 = & V_102 ;
struct V_103 * V_104 ;
unsigned long V_52 ;
int V_29 = V_97 -> V_29 ;
if ( V_97 -> V_105 && ! V_4 -> V_106 )
return NULL ;
V_72:
V_104 = & V_4 -> V_107 -> V_62 [ V_29 ] ;
F_70 ( & V_104 -> V_108 , V_52 ) ;
if ( ! F_71 ( & V_104 -> V_109 ) || V_104 -> V_17 == V_97 -> V_17 ) {
if ( ! V_4 -> V_106 ) {
if ( V_29 != V_97 -> V_29 )
F_68 ( V_14 , V_29 ) ;
V_97 -> V_105 = 1 ;
}
V_104 -> V_17 = V_97 -> V_17 ;
V_104 -> V_97 = V_97 -> V_97 ;
F_72 ( & V_104 -> V_109 ) ;
V_101 = NULL ;
} else {
V_29 = F_67 ( V_29 , V_97 -> V_17 ) ;
if ( V_29 != V_97 -> V_29 ) {
F_73 ( & V_104 -> V_108 , V_52 ) ;
goto V_72;
}
}
F_73 ( & V_104 -> V_108 , V_52 ) ;
return V_101 ;
}
static void
F_74 ( struct V_3 * V_4 ,
struct V_100 * V_97 )
{
struct V_103 * V_104 ;
if ( ! V_97 -> V_105 || V_4 -> V_106 )
return;
V_104 = & V_4 -> V_107 -> V_62 [ V_97 -> V_29 ] ;
F_75 ( & V_104 -> V_109 ) ;
V_97 -> V_105 = 0 ;
}
static struct V_82 *
F_76 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_82 * V_101 = NULL , * V_110 ;
struct V_100 * V_111 , * V_112 ;
V_111 = & V_14 -> V_16 . V_96 ;
if ( V_111 -> V_29 != V_113 ) {
V_101 = F_69 ( V_4 , V_14 , V_111 ) ;
if ( V_101 == & V_102 )
return V_101 ;
}
V_112 = & V_14 -> V_16 . V_114 ;
if ( V_112 -> V_29 != V_113 ) {
V_110 = F_69 ( V_4 , V_14 , V_112 ) ;
if ( V_110 == & V_102 ) {
F_74 ( V_4 , V_111 ) ;
V_101 = V_110 ;
}
}
return V_101 ;
}
struct V_82 *
F_77 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_82 * V_101 ;
if ( V_10 . V_115 ) {
F_78 (c, x86_pmu.event_constraints) {
if ( ( V_14 -> V_16 . V_17 & V_101 -> V_116 ) == V_101 -> V_117 ) {
V_14 -> V_16 . V_52 |= V_101 -> V_52 ;
return V_101 ;
}
}
}
return & V_118 ;
}
static struct V_82 *
F_79 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_82 * V_101 ;
V_101 = F_66 ( V_14 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_76 ( V_4 , V_14 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_80 ( V_14 ) ;
if ( V_101 )
return V_101 ;
return F_77 ( V_4 , V_29 , V_14 ) ;
}
static void
F_81 ( struct V_3 * V_4 )
{
struct V_119 * V_120 = V_4 -> V_120 ;
struct V_121 * V_122 ;
int V_123 = V_4 -> V_124 ;
if ( V_4 -> V_106 || ! F_82 () )
return;
if ( F_14 ( ! V_120 ) )
return;
V_122 = & V_120 -> V_125 [ V_123 ] ;
V_122 -> V_126 = true ;
F_83 ( & V_120 -> V_108 ) ;
}
static void F_84 ( struct V_3 * V_4 , int V_29 , int V_127 )
{
struct V_119 * V_120 = V_4 -> V_120 ;
struct V_82 * V_101 = V_4 -> V_82 [ V_29 ] ;
struct V_121 * V_122 ;
int V_123 = V_4 -> V_124 ;
if ( V_4 -> V_106 || ! F_82 () )
return;
if ( F_14 ( ! V_120 ) )
return;
if ( ! ( V_101 -> V_52 & V_128 ) )
return;
V_122 = & V_120 -> V_125 [ V_123 ] ;
F_85 ( & V_120 -> V_108 ) ;
if ( V_101 -> V_52 & V_129 )
V_122 -> V_130 [ V_127 ] = V_131 ;
else
V_122 -> V_130 [ V_127 ] = V_132 ;
}
static void
F_86 ( struct V_3 * V_4 )
{
struct V_119 * V_120 = V_4 -> V_120 ;
struct V_121 * V_122 ;
int V_123 = V_4 -> V_124 ;
if ( V_4 -> V_106 || ! F_82 () )
return;
if ( F_14 ( ! V_120 ) )
return;
V_122 = & V_120 -> V_125 [ V_123 ] ;
V_122 -> V_126 = false ;
F_87 ( & V_120 -> V_108 ) ;
}
static struct V_82 *
F_88 ( struct V_3 * V_4 , struct V_13 * V_14 ,
int V_29 , struct V_82 * V_101 )
{
struct V_119 * V_120 = V_4 -> V_120 ;
struct V_121 * V_133 ;
int V_123 = V_4 -> V_124 ;
int V_134 , V_19 ;
if ( V_4 -> V_106 || ! F_82 () )
return V_101 ;
if ( F_14 ( ! V_120 ) )
return V_101 ;
if ( ! ( V_101 -> V_52 & V_128 ) ) {
struct V_82 * V_135 ;
V_135 = & V_4 -> V_136 [ V_29 ] ;
* V_135 = * V_101 ;
V_135 -> V_52 |= V_128 ;
V_101 = V_135 ;
}
V_133 = & V_120 -> V_125 [ V_123 ^ 1 ] ;
V_134 = V_101 -> V_52 & V_129 ;
if ( V_134 && ! ( V_14 -> V_16 . V_52 & V_137 ) ) {
V_14 -> V_16 . V_52 |= V_137 ;
if ( ! V_4 -> V_138 ++ )
F_89 ( V_120 -> V_139 [ V_123 ] , 1 ) ;
}
F_61 (i, c->idxmsk, X86_PMC_IDX_MAX) {
if ( V_133 -> V_130 [ V_19 ] == V_131 )
F_90 ( V_19 , V_101 -> V_140 ) ;
if ( V_134 && V_133 -> V_130 [ V_19 ] == V_132 )
F_90 ( V_19 , V_101 -> V_140 ) ;
}
V_101 -> V_141 = F_91 ( V_101 -> V_142 ) ;
if ( V_101 -> V_141 == 0 )
V_101 = & V_102 ;
return V_101 ;
}
static struct V_82 *
F_92 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_82 * V_143 = NULL ;
struct V_82 * V_144 ;
if ( V_29 >= 0 )
V_143 = V_4 -> V_82 [ V_29 ] ;
V_144 = F_79 ( V_4 , V_29 , V_14 ) ;
if ( V_143 && ( V_143 -> V_52 & V_128 ) ) {
F_93 ( V_143 -> V_140 , V_144 -> V_140 , V_145 ) ;
V_143 -> V_141 = V_144 -> V_141 ;
V_144 = V_143 ;
}
if ( V_4 -> V_120 )
return F_88 ( V_4 , V_14 , V_29 , V_144 ) ;
return V_144 ;
}
static void F_94 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_16 ;
struct V_119 * V_120 = V_4 -> V_120 ;
int V_123 = V_4 -> V_124 ;
struct V_121 * V_122 ;
if ( V_4 -> V_106 )
return;
if ( F_14 ( ! V_120 ) )
return;
if ( V_28 -> V_52 & V_137 ) {
V_28 -> V_52 &= ~ V_137 ;
if ( ! -- V_4 -> V_138 )
F_89 ( V_120 -> V_139 [ V_123 ] , 0 ) ;
}
if ( V_28 -> V_29 >= 0 ) {
V_122 = & V_120 -> V_125 [ V_123 ] ;
if ( ! V_122 -> V_126 )
F_83 ( & V_120 -> V_108 ) ;
V_122 -> V_130 [ V_28 -> V_29 ] = V_146 ;
if ( ! V_122 -> V_126 )
F_87 ( & V_120 -> V_108 ) ;
}
}
static void
F_95 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_100 * V_97 ;
V_97 = & V_14 -> V_16 . V_96 ;
if ( V_97 -> V_29 != V_113 )
F_74 ( V_4 , V_97 ) ;
V_97 = & V_14 -> V_16 . V_114 ;
if ( V_97 -> V_29 != V_113 )
F_74 ( V_4 , V_97 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
F_95 ( V_4 , V_14 ) ;
if ( V_4 -> V_120 )
F_94 ( V_4 , V_14 ) ;
}
static void F_97 ( struct V_13 * V_14 )
{
if ( ( V_14 -> V_16 . V_17 & V_147 ) == 0x003c ) {
T_1 V_148 = F_98 ( . V_14 = 0xc0 , . V_149 = 1 , . V_116 = 16 ) ;
V_148 |= ( V_14 -> V_16 . V_17 & ~ V_147 ) ;
V_14 -> V_16 . V_17 = V_148 ;
}
}
static void F_99 ( struct V_13 * V_14 )
{
if ( ( V_14 -> V_16 . V_17 & V_147 ) == 0x003c ) {
T_1 V_148 = F_98 ( . V_14 = 0xc2 , . V_150 = 0x01 , . V_149 = 1 , . V_116 = 16 ) ;
V_148 |= ( V_14 -> V_16 . V_17 & ~ V_147 ) ;
V_14 -> V_16 . V_17 = V_148 ;
}
}
static void F_100 ( struct V_13 * V_14 )
{
if ( ( V_14 -> V_16 . V_17 & V_147 ) == 0x003c ) {
T_1 V_148 = F_98 ( . V_14 = 0xc0 , . V_150 = 0x01 , . V_149 = 1 , . V_116 = 16 ) ;
V_148 |= ( V_14 -> V_16 . V_17 & ~ V_147 ) ;
V_14 -> V_16 . V_17 = V_148 ;
}
}
static void F_101 ( struct V_13 * V_14 )
{
if ( V_14 -> V_38 . V_39 < 3 )
return F_99 ( V_14 ) ;
return F_100 ( V_14 ) ;
}
static void F_102 ( struct V_13 * V_14 )
{
if ( V_14 -> V_38 . V_39 < 3 )
return F_97 ( V_14 ) ;
return F_100 ( V_14 ) ;
}
static unsigned long F_103 ( struct V_13 * V_14 )
{
unsigned long V_52 = V_10 . V_151 ;
if ( V_14 -> V_38 . V_152 )
V_52 &= ~ V_153 ;
return V_52 ;
}
static int F_104 ( struct V_13 * V_14 )
{
int V_154 = F_105 ( V_14 ) ;
if ( V_154 )
return V_154 ;
if ( V_14 -> V_38 . V_39 ) {
if ( ! V_14 -> V_38 . V_84 ) {
V_14 -> V_16 . V_52 |= V_155 ;
if ( ! ( V_14 -> V_38 . V_156 &
~ F_103 ( V_14 ) ) )
V_14 -> V_16 . V_52 |= V_157 ;
}
if ( V_10 . V_158 )
V_10 . V_158 ( V_14 ) ;
}
if ( F_31 ( V_14 ) ) {
V_154 = F_106 ( V_14 ) ;
if ( V_154 )
return V_154 ;
if ( ! F_107 ( V_14 ) ) {
if ( F_108 ( V_159 ) )
return - V_160 ;
V_14 -> V_161 = V_162 ;
}
}
if ( V_14 -> V_38 . type != V_163 )
return 0 ;
if ( ! ( V_14 -> V_38 . V_17 & V_44 ) )
return 0 ;
if ( V_10 . V_43 < 3 )
return - V_164 ;
if ( F_109 () && ! F_110 ( V_165 ) )
return - V_166 ;
V_14 -> V_16 . V_17 |= V_44 ;
return 0 ;
}
struct V_167 * F_111 ( int * V_168 )
{
if ( V_10 . V_169 )
return V_10 . V_169 ( V_168 ) ;
* V_168 = 0 ;
return NULL ;
}
static struct V_167 * F_112 ( int * V_168 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
struct V_167 * V_170 = V_4 -> V_171 ;
V_170 [ 0 ] . V_172 = V_5 ;
V_170 [ 0 ] . V_173 = V_10 . V_11 & ~ V_4 -> V_12 ;
V_170 [ 0 ] . V_174 = V_10 . V_11 & ~ V_4 -> V_35 ;
V_170 [ 1 ] . V_172 = V_175 ;
V_170 [ 1 ] . V_173 = V_4 -> V_176 ;
V_170 [ 1 ] . V_174 = 0 ;
* V_168 = 2 ;
return V_170 ;
}
static struct V_167 * F_113 ( int * V_168 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
struct V_167 * V_170 = V_4 -> V_171 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_10 . V_53 ; V_29 ++ ) {
struct V_13 * V_14 = V_4 -> V_15 [ V_29 ] ;
V_170 [ V_29 ] . V_172 = F_47 ( V_29 ) ;
V_170 [ V_29 ] . V_173 = V_170 [ V_29 ] . V_174 = 0 ;
if ( ! F_5 ( V_29 , V_4 -> V_7 ) )
continue;
V_170 [ V_29 ] . V_173 = V_170 [ V_29 ] . V_174 =
V_14 -> V_16 . V_17 | V_22 ;
if ( V_14 -> V_38 . V_46 )
V_170 [ V_29 ] . V_173 &= ~ V_22 ;
else if ( V_14 -> V_38 . V_47 )
V_170 [ V_29 ] . V_174 &= ~ V_22 ;
}
* V_168 = V_10 . V_53 ;
return V_170 ;
}
static void F_114 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_38 . V_46 )
F_115 ( V_14 ) ;
}
static void F_116 ( int V_8 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_10 . V_53 ; V_29 ++ ) {
struct V_27 * V_28 = & V_4 -> V_15 [ V_29 ] -> V_16 ;
if ( ! F_5 ( V_29 , V_4 -> V_7 ) ||
V_4 -> V_15 [ V_29 ] -> V_38 . V_46 )
continue;
F_21 ( V_28 , V_22 ) ;
}
}
static int F_117 ( struct V_13 * V_14 )
{
int V_154 = F_104 ( V_14 ) ;
if ( V_154 )
return V_154 ;
if ( ! F_118 ( V_177 ) && ! F_118 ( V_178 ) )
return 0 ;
V_14 -> V_16 . V_17 |= V_14 -> V_38 . V_17 & ( V_179 | V_34 ) ;
if ( ( V_14 -> V_16 . V_17 & ( V_179 | V_34 ) ) &&
( ( V_14 -> V_16 . V_17 & V_44 ) ||
V_14 -> V_38 . V_39 > 0 ) )
return - V_180 ;
if ( F_27 ( V_14 ) ) {
if ( V_14 -> V_38 . V_88 > 0 &&
V_14 -> V_38 . V_88 < 0x7fffffff )
return - V_180 ;
}
return 0 ;
}
static struct V_82 *
F_119 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_82 * V_101 ;
V_101 = F_92 ( V_4 , V_29 , V_14 ) ;
if ( V_14 -> V_16 . V_17 & V_34 ) {
if ( V_101 -> V_142 & ( 1U << 2 ) )
return & V_181 ;
return & V_102 ;
}
return V_101 ;
}
static unsigned F_120 ( struct V_13 * V_14 , unsigned V_182 )
{
if ( ( V_14 -> V_16 . V_17 & V_85 ) ==
F_98 ( . V_14 = 0xc0 , . V_150 = 0x01 ) ) {
if ( V_182 < 128 )
V_182 = 128 ;
V_182 &= ~ 0x3fu ;
}
return V_182 ;
}
T_2 F_121 ( char * V_183 , T_1 V_17 )
{
T_1 V_14 = ( V_17 & V_184 ) ;
return F_122 ( V_183 , V_17 , V_14 ) ;
}
struct V_185 * F_123 ( int V_186 )
{
struct V_185 * V_62 ;
int V_19 ;
V_62 = F_124 ( sizeof( struct V_185 ) ,
V_187 , F_125 ( V_186 ) ) ;
if ( V_62 ) {
for ( V_19 = 0 ; V_19 < V_188 ; V_19 ++ )
F_126 ( & V_62 -> V_62 [ V_19 ] . V_108 ) ;
V_62 -> V_189 = - 1 ;
}
return V_62 ;
}
static struct V_119 * F_127 ( int V_186 )
{
struct V_119 * V_101 ;
V_101 = F_124 ( sizeof( struct V_119 ) ,
V_187 , F_125 ( V_186 ) ) ;
if ( V_101 ) {
F_126 ( & V_101 -> V_108 ) ;
V_101 -> V_189 = - 1 ;
}
return V_101 ;
}
static int F_128 ( int V_186 )
{
struct V_3 * V_4 = & F_129 ( V_3 , V_186 ) ;
if ( V_10 . V_94 || V_10 . V_190 ) {
V_4 -> V_107 = F_123 ( V_186 ) ;
if ( ! V_4 -> V_107 )
goto V_191;
}
if ( V_10 . V_52 & V_192 ) {
T_3 V_193 = V_145 * sizeof( struct V_82 ) ;
V_4 -> V_136 = F_130 ( V_193 , V_187 ) ;
if ( ! V_4 -> V_136 )
goto V_194;
V_4 -> V_120 = F_127 ( V_186 ) ;
if ( ! V_4 -> V_120 )
goto V_195;
V_4 -> V_124 = 0 ;
}
return V_196 ;
V_195:
F_131 ( V_4 -> V_136 ) ;
V_4 -> V_136 = NULL ;
V_194:
F_131 ( V_4 -> V_107 ) ;
V_4 -> V_107 = NULL ;
V_191:
return V_197 ;
}
static void F_132 ( int V_186 )
{
struct V_3 * V_4 = & F_129 ( V_3 , V_186 ) ;
int V_189 = F_133 ( V_186 ) ;
int V_19 ;
F_134 ( V_186 ) ;
F_135 () ;
V_4 -> V_198 = NULL ;
if ( ! V_4 -> V_107 )
return;
if ( ! ( V_10 . V_52 & V_199 ) ) {
F_136 (i, topology_sibling_cpumask(cpu)) {
struct V_185 * V_200 ;
V_200 = F_129 ( V_3 , V_19 ) . V_107 ;
if ( V_200 && V_200 -> V_189 == V_189 ) {
V_4 -> V_201 [ 0 ] = V_4 -> V_107 ;
V_4 -> V_107 = V_200 ;
break;
}
}
V_4 -> V_107 -> V_189 = V_189 ;
V_4 -> V_107 -> V_202 ++ ;
}
if ( V_10 . V_190 )
V_4 -> V_198 = & V_4 -> V_107 -> V_62 [ V_203 ] ;
if ( V_10 . V_52 & V_192 ) {
F_136 (i, topology_sibling_cpumask(cpu)) {
struct V_119 * V_101 ;
V_101 = F_129 ( V_3 , V_19 ) . V_120 ;
if ( V_101 && V_101 -> V_189 == V_189 ) {
V_4 -> V_201 [ 1 ] = V_4 -> V_120 ;
V_4 -> V_120 = V_101 ;
V_4 -> V_124 = 1 ;
break;
}
}
V_4 -> V_120 -> V_189 = V_189 ;
V_4 -> V_120 -> V_202 ++ ;
}
}
static void F_137 ( int V_186 )
{
struct V_3 * V_4 = & F_129 ( V_3 , V_186 ) ;
struct V_119 * V_101 ;
V_101 = V_4 -> V_120 ;
if ( V_101 ) {
if ( V_101 -> V_189 == - 1 || -- V_101 -> V_202 == 0 )
F_131 ( V_101 ) ;
V_4 -> V_120 = NULL ;
F_131 ( V_4 -> V_136 ) ;
V_4 -> V_136 = NULL ;
}
}
static void F_138 ( int V_186 )
{
struct V_3 * V_4 = & F_129 ( V_3 , V_186 ) ;
struct V_185 * V_200 ;
V_200 = V_4 -> V_107 ;
if ( V_200 ) {
if ( V_200 -> V_189 == - 1 || -- V_200 -> V_202 == 0 )
F_131 ( V_200 ) ;
V_4 -> V_107 = NULL ;
}
F_137 ( V_186 ) ;
F_139 ( V_186 ) ;
}
static void F_140 ( struct V_204 * V_205 ,
bool V_206 )
{
if ( V_10 . V_207 )
F_141 ( V_205 , V_206 ) ;
if ( V_10 . V_58 )
F_142 ( V_205 , V_206 ) ;
}
static T_4 void F_143 ( void )
{
F_144 ( L_3 ) ;
V_10 . V_208 = 0 ;
V_10 . V_209 = NULL ;
}
static int F_145 ( int V_186 )
{
T_5 V_210 = V_211 ;
switch ( F_146 ( V_186 ) . V_212 ) {
case 42 :
V_210 = 0x28 ;
break;
case 45 :
switch ( F_146 ( V_186 ) . V_213 ) {
case 6 : V_210 = 0x618 ; break;
case 7 : V_210 = 0x70c ; break;
}
}
return ( F_146 ( V_186 ) . V_214 < V_210 ) ;
}
static void F_147 ( void )
{
int V_215 = 0 ;
int V_186 ;
F_148 () ;
F_149 (cpu) {
if ( ( V_215 = F_145 ( V_186 ) ) )
break;
}
F_150 () ;
if ( V_215 == V_10 . V_215 )
return;
if ( V_10 . V_215 ) {
F_44 ( L_4 ) ;
V_10 . V_215 = 0 ;
} else {
F_44 ( L_5 ) ;
V_10 . V_215 = 1 ;
}
}
static bool F_151 ( unsigned long V_172 , T_1 V_32 )
{
T_1 V_216 , V_217 , V_218 ;
if ( F_152 ( V_172 , & V_216 ) )
return false ;
V_218 = V_216 ^ V_32 ;
if ( F_46 ( V_172 , V_218 ) ||
F_152 ( V_172 , & V_217 ) )
return false ;
if ( V_217 != V_218 )
return false ;
F_4 ( V_172 , V_216 ) ;
return true ;
}
static T_4 void F_153 ( void )
{
V_10 . V_219 = F_147 ;
F_147 () ;
}
static T_4 void F_154 ( void )
{
int V_65 ;
F_61 (bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
V_2 [ V_220 [ V_65 ] . V_221 ] = 0 ;
F_144 ( L_6 ,
V_220 [ V_65 ] . V_222 ) ;
}
}
static T_4 void F_155 ( void )
{
union V_223 V_224 ;
V_224 . V_225 = V_10 . V_226 ;
if ( V_224 . V_227 . V_228 ) {
V_2 [ V_229 ] = 0x7f89 ;
V_224 . V_227 . V_228 = 0 ;
V_10 . V_226 = V_224 . V_225 ;
F_44 ( L_7 ) ;
}
}
static T_4 void F_156 ( void )
{
V_10 . V_52 |= V_192 | V_230 ;
V_10 . V_231 = F_81 ;
V_10 . V_232 = F_84 ;
V_10 . V_233 = F_86 ;
}
T_4 int F_157 ( void )
{
union V_234 V_235 ;
union V_236 V_237 ;
union V_223 V_224 ;
struct V_82 * V_101 ;
unsigned int V_238 ;
struct V_96 * V_239 ;
int V_43 , V_19 ;
if ( ! F_158 ( & V_240 , V_241 ) ) {
switch ( V_240 . V_242 ) {
case 0x6 :
return F_159 () ;
case 0xb :
return F_160 () ;
case 0xf :
return F_161 () ;
}
return - V_243 ;
}
F_162 ( 10 , & V_237 . V_225 , & V_224 . V_225 , & V_238 , & V_235 . V_225 ) ;
if ( V_237 . V_227 . V_244 < V_245 )
return - V_243 ;
V_43 = V_237 . V_227 . V_246 ;
if ( V_43 < 2 )
V_10 = V_247 ;
else
V_10 = V_248 ;
V_10 . V_43 = V_43 ;
V_10 . V_53 = V_237 . V_227 . V_53 ;
V_10 . V_249 = V_237 . V_227 . V_250 ;
V_10 . V_251 = ( 1ULL << V_237 . V_227 . V_250 ) - 1 ;
V_10 . V_226 = V_224 . V_225 ;
V_10 . V_252 = V_237 . V_227 . V_244 ;
V_10 . V_253 = F_163 ( unsigned , V_254 , V_10 . V_53 ) ;
if ( V_43 > 1 )
V_10 . V_54 = F_164 ( ( int ) V_235 . V_227 . V_54 , 3 ) ;
if ( F_118 ( V_255 ) ) {
T_1 V_256 ;
F_24 ( V_257 , V_256 ) ;
V_10 . V_258 . V_256 = V_256 ;
}
F_165 () ;
F_166 ( F_154 ) ;
switch ( V_240 . V_212 ) {
case 14 :
F_167 ( L_8 ) ;
break;
case 15 :
F_166 ( F_143 ) ;
case 22 :
case 23 :
case 29 :
memcpy ( V_259 , V_260 ,
sizeof( V_259 ) ) ;
F_168 () ;
V_10 . V_115 = V_261 ;
V_10 . V_209 = V_262 ;
F_167 ( L_9 ) ;
break;
case 30 :
case 26 :
case 46 :
memcpy ( V_259 , V_263 ,
sizeof( V_259 ) ) ;
memcpy ( V_264 , V_265 ,
sizeof( V_264 ) ) ;
F_169 () ;
V_10 . V_115 = V_266 ;
V_10 . V_209 = V_267 ;
V_10 . V_268 = F_22 ;
V_10 . V_94 = V_269 ;
V_10 . V_270 = V_271 ;
V_2 [ V_272 ] =
F_98 ( . V_14 = 0x0e , . V_150 = 0x01 , . V_149 = 1 , . V_116 = 1 ) ;
V_2 [ V_273 ] =
F_98 ( . V_14 = 0xb1 , . V_150 = 0x3f , . V_149 = 1 , . V_116 = 1 ) ;
F_166 ( F_155 ) ;
F_167 ( L_10 ) ;
break;
case 28 :
case 38 :
case 39 :
case 53 :
case 54 :
memcpy ( V_259 , V_274 ,
sizeof( V_259 ) ) ;
F_170 () ;
V_10 . V_115 = V_275 ;
V_10 . V_209 = V_276 ;
V_10 . V_158 = F_97 ;
F_167 ( L_11 ) ;
break;
case 55 :
case 76 :
case 77 :
memcpy ( V_259 , V_277 ,
sizeof( V_259 ) ) ;
memcpy ( V_264 , V_278 ,
sizeof( V_264 ) ) ;
F_170 () ;
V_10 . V_115 = V_279 ;
V_10 . V_209 = V_280 ;
V_10 . V_94 = V_281 ;
V_10 . V_52 |= V_91 ;
F_167 ( L_12 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_259 , V_282 ,
sizeof( V_259 ) ) ;
memcpy ( V_264 , V_265 ,
sizeof( V_264 ) ) ;
F_169 () ;
V_10 . V_115 = V_283 ;
V_10 . V_268 = F_22 ;
V_10 . V_209 = V_284 ;
V_10 . V_94 = V_285 ;
V_10 . V_52 |= V_91 ;
V_10 . V_270 = V_271 ;
V_2 [ V_272 ] =
F_98 ( . V_14 = 0x0e , . V_150 = 0x01 , . V_149 = 1 , . V_116 = 1 ) ;
V_2 [ V_273 ] =
F_98 ( . V_14 = 0xb1 , . V_150 = 0x3f , . V_149 = 1 , . V_116 = 1 ) ;
F_167 ( L_13 ) ;
break;
case 42 :
case 45 :
F_166 ( F_153 ) ;
F_166 ( F_156 ) ;
memcpy ( V_259 , V_286 ,
sizeof( V_259 ) ) ;
memcpy ( V_264 , V_287 ,
sizeof( V_264 ) ) ;
F_171 () ;
V_10 . V_115 = V_288 ;
V_10 . V_209 = V_289 ;
V_10 . V_158 = F_99 ;
if ( V_240 . V_212 == 45 )
V_10 . V_94 = V_290 ;
else
V_10 . V_94 = V_291 ;
V_10 . V_52 |= V_91 ;
V_10 . V_52 |= V_199 ;
V_10 . V_270 = V_292 ;
V_2 [ V_272 ] =
F_98 ( . V_14 = 0x0e , . V_150 = 0x01 , . V_149 = 1 , . V_116 = 1 ) ;
V_2 [ V_273 ] =
F_98 ( . V_14 = 0xb1 , . V_150 = 0x01 , . V_149 = 1 , . V_116 = 1 ) ;
F_167 ( L_14 ) ;
break;
case 58 :
case 62 :
F_166 ( F_156 ) ;
memcpy ( V_259 , V_286 ,
sizeof( V_259 ) ) ;
V_259 [ F_172 ( V_293 ) ] [ F_172 ( V_294 ) ] [ F_172 ( V_295 ) ] = 0x8108 ;
memcpy ( V_264 , V_287 ,
sizeof( V_264 ) ) ;
F_171 () ;
V_10 . V_115 = V_296 ;
V_10 . V_209 = V_297 ;
V_10 . V_158 = F_101 ;
V_10 . V_298 = true ;
if ( V_240 . V_212 == 62 )
V_10 . V_94 = V_290 ;
else
V_10 . V_94 = V_291 ;
V_10 . V_52 |= V_91 ;
V_10 . V_52 |= V_199 ;
V_10 . V_270 = V_292 ;
V_2 [ V_272 ] =
F_98 ( . V_14 = 0x0e , . V_150 = 0x01 , . V_149 = 1 , . V_116 = 1 ) ;
F_167 ( L_15 ) ;
break;
case 60 :
case 63 :
case 69 :
case 70 :
F_166 ( F_156 ) ;
V_10 . V_68 = true ;
memcpy ( V_259 , V_299 , sizeof( V_259 ) ) ;
memcpy ( V_264 , V_300 , sizeof( V_264 ) ) ;
F_173 () ;
V_10 . V_115 = V_301 ;
V_10 . V_209 = V_302 ;
V_10 . V_94 = V_290 ;
V_10 . V_158 = F_101 ;
V_10 . V_298 = true ;
V_10 . V_52 |= V_91 ;
V_10 . V_52 |= V_199 ;
V_10 . V_303 = F_117 ;
V_10 . V_304 = F_119 ;
V_10 . V_270 = V_305 ;
V_10 . V_306 = true ;
F_167 ( L_16 ) ;
break;
case 61 :
case 86 :
case 71 :
case 79 :
V_10 . V_68 = true ;
memcpy ( V_259 , V_299 , sizeof( V_259 ) ) ;
memcpy ( V_264 , V_300 , sizeof( V_264 ) ) ;
V_264 [ F_172 ( V_307 ) ] [ F_172 ( V_294 ) ] [ F_172 ( V_295 ) ] = V_308 |
V_309 | V_310 ;
V_264 [ F_172 ( V_307 ) ] [ F_172 ( V_311 ) ] [ F_172 ( V_295 ) ] = V_312 | V_309 |
V_310 ;
V_264 [ F_172 ( V_313 ) ] [ F_172 ( V_294 ) ] [ F_172 ( V_314 ) ] = V_308 |
V_315 | V_310 ;
V_264 [ F_172 ( V_313 ) ] [ F_172 ( V_311 ) ] [ F_172 ( V_314 ) ] = V_312 |
V_315 | V_310 ;
F_173 () ;
V_10 . V_115 = V_316 ;
V_10 . V_209 = V_302 ;
V_10 . V_94 = V_290 ;
V_10 . V_158 = F_101 ;
V_10 . V_298 = true ;
V_10 . V_52 |= V_91 ;
V_10 . V_52 |= V_199 ;
V_10 . V_303 = F_117 ;
V_10 . V_304 = F_119 ;
V_10 . V_270 = V_305 ;
V_10 . V_317 = F_120 ;
F_167 ( L_17 ) ;
break;
case 87 :
memcpy ( V_259 ,
V_277 , sizeof( V_259 ) ) ;
memcpy ( V_264 ,
V_318 , sizeof( V_264 ) ) ;
F_174 () ;
V_10 . V_115 = V_279 ;
V_10 . V_209 = V_280 ;
V_10 . V_94 = V_319 ;
V_10 . V_52 |= V_91 ;
V_10 . V_52 |= V_199 ;
F_167 ( L_18 ) ;
break;
case 78 :
case 94 :
V_10 . V_68 = true ;
memcpy ( V_259 , V_320 , sizeof( V_259 ) ) ;
memcpy ( V_264 , V_321 , sizeof( V_264 ) ) ;
F_175 () ;
V_10 . V_115 = V_322 ;
V_10 . V_209 = V_323 ;
V_10 . V_94 = V_324 ;
V_10 . V_158 = F_102 ;
V_10 . V_298 = true ;
V_10 . V_52 |= V_91 ;
V_10 . V_52 |= V_199 ;
V_10 . V_303 = F_117 ;
V_10 . V_304 = F_119 ;
V_10 . V_325 = F_176 ( V_326 ,
V_327 ) ;
F_177 ( ! V_10 . V_325 ) ;
V_10 . V_270 = V_305 ;
F_167 ( L_19 ) ;
break;
default:
switch ( V_10 . V_43 ) {
case 1 :
V_10 . V_115 = V_328 ;
F_167 ( L_20 ) ;
break;
default:
V_10 . V_115 = V_275 ;
F_167 ( L_21 ) ;
break;
}
}
if ( V_10 . V_53 > V_329 ) {
F_56 ( 1 , V_330 L_22 ,
V_10 . V_53 , V_329 ) ;
V_10 . V_53 = V_329 ;
}
V_10 . V_11 = ( 1 << V_10 . V_53 ) - 1 ;
if ( V_10 . V_54 > V_331 ) {
F_56 ( 1 , V_330 L_23 ,
V_10 . V_54 , V_331 ) ;
V_10 . V_54 = V_331 ;
}
V_10 . V_11 |=
( ( 1LL << V_10 . V_54 ) - 1 ) << V_30 ;
if ( V_10 . V_115 ) {
F_78 (c, x86_pmu.event_constraints) {
if ( V_101 -> V_116 == V_332
&& V_101 -> V_142 != V_333 ) {
V_101 -> V_142 |= ( 1ULL << V_10 . V_53 ) - 1 ;
}
V_101 -> V_142 &=
~ ( ~ 0UL << ( V_30 + V_10 . V_54 ) ) ;
V_101 -> V_141 = F_91 ( V_101 -> V_142 ) ;
}
}
if ( V_10 . V_58 && ! F_151 ( V_10 . V_334 , 0x3UL ) )
V_10 . V_58 = 0 ;
for ( V_19 = 0 ; V_19 < V_10 . V_58 ; V_19 ++ ) {
if ( ! ( F_151 ( V_10 . V_335 + V_19 , 0xffffUL ) &&
F_151 ( V_10 . V_336 + V_19 , 0xffffUL ) ) )
V_10 . V_58 = 0 ;
}
if ( V_10 . V_94 ) {
for ( V_239 = V_10 . V_94 ; V_239 -> V_172 ; V_239 ++ ) {
V_239 -> V_337 = F_151 ( V_239 -> V_172 , 0x11UL ) ;
if ( ( V_239 -> V_29 == V_203 ) && ! V_239 -> V_337 )
V_10 . V_190 = NULL ;
}
}
if ( V_10 . V_258 . V_338 ) {
V_10 . V_339 = V_10 . V_251 ;
V_10 . V_340 = V_341 ;
F_167 ( L_24 ) ;
}
return 0 ;
}
static T_4 int F_178 ( void )
{
int V_186 = F_45 () ;
int V_342 , V_101 ;
if ( ! ( V_10 . V_52 & V_230 ) )
return 0 ;
V_342 = F_179 ( F_180 ( V_186 ) ) ;
if ( V_342 > 1 ) {
F_44 ( L_25 ) ;
return 0 ;
}
if ( F_181 () != 0 ) {
F_182 ( L_26 ) ;
return 0 ;
}
V_10 . V_52 &= ~ ( V_192 | V_230 ) ;
V_10 . V_231 = NULL ;
V_10 . V_232 = NULL ;
V_10 . V_233 = NULL ;
F_183 () ;
F_148 () ;
F_149 (c) {
F_137 ( V_101 ) ;
}
F_150 () ;
F_44 ( L_27 ) ;
return 0 ;
}
