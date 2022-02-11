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
F_25 ( V_23 ) ;
if ( ++ V_66 > 100 ) {
static bool V_73 = false ;
if ( ! V_73 ) {
F_55 ( 1 , L_2 ) ;
F_56 () ;
V_73 = true ;
}
F_42 () ;
goto V_71;
}
F_57 ( V_74 ) ;
F_58 () ;
if ( F_59 ( 63 , ( unsigned long * ) & V_23 ) ) {
if ( ! V_23 )
goto V_71;
}
if ( F_59 ( 62 , ( unsigned long * ) & V_23 ) ) {
V_67 ++ ;
V_10 . V_75 ( V_62 ) ;
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
F_62 ( & V_64 , 0 , V_14 -> V_16 . V_76 ) ;
if ( F_63 ( V_14 ) )
V_64 . V_77 = & V_4 -> V_78 ;
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
static struct V_79 *
F_66 ( struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_16 ;
unsigned int V_1 , V_80 ;
if ( V_14 -> V_38 . V_81 )
return NULL ;
V_1 = V_28 -> V_17 & V_82 ;
V_80 = V_10 . V_83 ( V_84 ) ;
if ( F_29 ( V_1 == V_80 && V_28 -> V_85 == 1 ) )
return & V_86 ;
return NULL ;
}
static int F_67 ( int V_29 )
{
if ( ! ( V_10 . V_52 & V_87 ) )
return V_29 ;
if ( V_29 == V_88 )
return V_89 ;
if ( V_29 == V_89 )
return V_88 ;
return V_29 ;
}
static void F_68 ( struct V_13 * V_14 , int V_29 )
{
V_14 -> V_16 . V_90 . V_29 = V_29 ;
if ( V_29 == V_88 ) {
V_14 -> V_16 . V_17 &= ~ V_82 ;
V_14 -> V_16 . V_17 |= V_10 . V_91 [ V_88 ] . V_14 ;
V_14 -> V_16 . V_90 . V_92 = V_93 ;
} else if ( V_29 == V_89 ) {
V_14 -> V_16 . V_17 &= ~ V_82 ;
V_14 -> V_16 . V_17 |= V_10 . V_91 [ V_89 ] . V_14 ;
V_14 -> V_16 . V_90 . V_92 = V_94 ;
}
}
static struct V_79 *
F_69 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
struct V_95 * V_92 )
{
struct V_79 * V_96 = & V_97 ;
struct V_98 * V_99 ;
unsigned long V_52 ;
int V_29 = V_92 -> V_29 ;
if ( V_92 -> V_100 && ! V_4 -> V_101 )
return NULL ;
V_72:
V_99 = & V_4 -> V_102 -> V_62 [ V_29 ] ;
F_70 ( & V_99 -> V_103 , V_52 ) ;
if ( ! F_71 ( & V_99 -> V_104 ) || V_99 -> V_17 == V_92 -> V_17 ) {
if ( ! V_4 -> V_101 ) {
if ( V_29 != V_92 -> V_29 )
F_68 ( V_14 , V_29 ) ;
V_92 -> V_100 = 1 ;
}
V_99 -> V_17 = V_92 -> V_17 ;
V_99 -> V_92 = V_92 -> V_92 ;
F_72 ( & V_99 -> V_104 ) ;
V_96 = NULL ;
} else {
V_29 = F_67 ( V_29 ) ;
if ( V_29 != V_92 -> V_29 ) {
F_73 ( & V_99 -> V_103 , V_52 ) ;
goto V_72;
}
}
F_73 ( & V_99 -> V_103 , V_52 ) ;
return V_96 ;
}
static void
F_74 ( struct V_3 * V_4 ,
struct V_95 * V_92 )
{
struct V_98 * V_99 ;
if ( ! V_92 -> V_100 || V_4 -> V_101 )
return;
V_99 = & V_4 -> V_102 -> V_62 [ V_92 -> V_29 ] ;
F_75 ( & V_99 -> V_104 ) ;
V_92 -> V_100 = 0 ;
}
static struct V_79 *
F_76 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_79 * V_96 = NULL , * V_105 ;
struct V_95 * V_106 , * V_107 ;
V_106 = & V_14 -> V_16 . V_90 ;
if ( V_106 -> V_29 != V_108 ) {
V_96 = F_69 ( V_4 , V_14 , V_106 ) ;
if ( V_96 == & V_97 )
return V_96 ;
}
V_107 = & V_14 -> V_16 . V_109 ;
if ( V_107 -> V_29 != V_108 ) {
V_105 = F_69 ( V_4 , V_14 , V_107 ) ;
if ( V_105 == & V_97 ) {
F_74 ( V_4 , V_106 ) ;
V_96 = V_105 ;
}
}
return V_96 ;
}
struct V_79 *
F_77 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_79 * V_96 ;
if ( V_10 . V_110 ) {
F_78 (c, x86_pmu.event_constraints) {
if ( ( V_14 -> V_16 . V_17 & V_96 -> V_111 ) == V_96 -> V_112 ) {
V_14 -> V_16 . V_52 |= V_96 -> V_52 ;
return V_96 ;
}
}
}
return & V_113 ;
}
static struct V_79 *
F_79 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_79 * V_96 ;
V_96 = F_66 ( V_14 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_76 ( V_4 , V_14 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_80 ( V_14 ) ;
if ( V_96 )
return V_96 ;
return F_77 ( V_4 , V_29 , V_14 ) ;
}
static void
F_81 ( struct V_3 * V_4 )
{
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_116 * V_117 ;
int V_118 = V_4 -> V_119 ;
if ( V_4 -> V_101 || ! F_82 () )
return;
if ( F_14 ( ! V_115 ) )
return;
V_117 = & V_115 -> V_120 [ V_118 ] ;
V_117 -> V_121 = true ;
F_83 ( & V_115 -> V_103 ) ;
}
static void F_84 ( struct V_3 * V_4 , int V_29 , int V_122 )
{
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_79 * V_96 = V_4 -> V_79 [ V_29 ] ;
struct V_116 * V_117 ;
int V_118 = V_4 -> V_119 ;
if ( V_4 -> V_101 || ! F_82 () )
return;
if ( F_14 ( ! V_115 ) )
return;
if ( ! ( V_96 -> V_52 & V_123 ) )
return;
V_117 = & V_115 -> V_120 [ V_118 ] ;
F_85 ( & V_115 -> V_103 ) ;
if ( V_96 -> V_52 & V_124 )
V_117 -> V_125 [ V_122 ] = V_126 ;
else
V_117 -> V_125 [ V_122 ] = V_127 ;
}
static void
F_86 ( struct V_3 * V_4 )
{
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_116 * V_117 ;
int V_118 = V_4 -> V_119 ;
if ( V_4 -> V_101 || ! F_82 () )
return;
if ( F_14 ( ! V_115 ) )
return;
V_117 = & V_115 -> V_120 [ V_118 ] ;
V_117 -> V_121 = false ;
F_87 ( & V_115 -> V_103 ) ;
}
static struct V_79 *
F_88 ( struct V_3 * V_4 , struct V_13 * V_14 ,
int V_29 , struct V_79 * V_96 )
{
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_116 * V_128 ;
int V_118 = V_4 -> V_119 ;
int V_129 , V_19 ;
if ( V_4 -> V_101 || ! F_82 () )
return V_96 ;
if ( F_14 ( ! V_115 ) )
return V_96 ;
if ( ! ( V_96 -> V_52 & V_123 ) ) {
struct V_79 * V_130 ;
V_130 = & V_4 -> V_131 [ V_29 ] ;
* V_130 = * V_96 ;
V_130 -> V_52 |= V_123 ;
V_96 = V_130 ;
}
V_128 = & V_115 -> V_120 [ V_118 ^ 1 ] ;
V_129 = V_96 -> V_52 & V_124 ;
if ( V_129 && ! ( V_14 -> V_16 . V_52 & V_132 ) ) {
V_14 -> V_16 . V_52 |= V_132 ;
if ( ! V_4 -> V_133 ++ )
F_89 ( V_115 -> V_134 [ V_118 ] , 1 ) ;
}
F_61 (i, c->idxmsk, X86_PMC_IDX_MAX) {
if ( V_128 -> V_125 [ V_19 ] == V_126 )
F_90 ( V_19 , V_96 -> V_135 ) ;
if ( V_129 && V_128 -> V_125 [ V_19 ] == V_127 )
F_90 ( V_19 , V_96 -> V_135 ) ;
}
V_96 -> V_136 = F_91 ( V_96 -> V_137 ) ;
if ( V_96 -> V_136 == 0 )
V_96 = & V_97 ;
return V_96 ;
}
static struct V_79 *
F_92 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_79 * V_138 = V_4 -> V_79 [ V_29 ] ;
struct V_79 * V_139 ;
V_139 = F_79 ( V_4 , V_29 , V_14 ) ;
if ( V_138 && ( V_138 -> V_52 & V_123 ) ) {
F_93 ( V_138 -> V_135 , V_139 -> V_135 , V_140 ) ;
V_138 -> V_136 = V_139 -> V_136 ;
V_139 = V_138 ;
}
if ( V_4 -> V_115 )
return F_88 ( V_4 , V_14 , V_29 , V_139 ) ;
return V_139 ;
}
static void F_94 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_16 ;
struct V_114 * V_115 = V_4 -> V_115 ;
int V_118 = V_4 -> V_119 ;
struct V_116 * V_117 ;
if ( V_4 -> V_101 )
return;
if ( F_14 ( ! V_115 ) )
return;
if ( V_28 -> V_52 & V_132 ) {
V_28 -> V_52 &= ~ V_132 ;
if ( ! -- V_4 -> V_133 )
F_89 ( V_115 -> V_134 [ V_118 ] , 0 ) ;
}
if ( V_28 -> V_29 >= 0 ) {
V_117 = & V_115 -> V_120 [ V_118 ] ;
if ( ! V_117 -> V_121 )
F_83 ( & V_115 -> V_103 ) ;
V_117 -> V_125 [ V_28 -> V_29 ] = V_141 ;
if ( ! V_117 -> V_121 )
F_87 ( & V_115 -> V_103 ) ;
}
}
static void
F_95 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_95 * V_92 ;
V_92 = & V_14 -> V_16 . V_90 ;
if ( V_92 -> V_29 != V_108 )
F_74 ( V_4 , V_92 ) ;
V_92 = & V_14 -> V_16 . V_109 ;
if ( V_92 -> V_29 != V_108 )
F_74 ( V_4 , V_92 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
F_95 ( V_4 , V_14 ) ;
if ( V_4 -> V_115 )
F_94 ( V_4 , V_14 ) ;
}
static void F_97 ( struct V_13 * V_14 )
{
if ( ( V_14 -> V_16 . V_17 & V_142 ) == 0x003c ) {
T_1 V_143 = F_98 ( . V_14 = 0xc0 , . V_144 = 1 , . V_111 = 16 ) ;
V_143 |= ( V_14 -> V_16 . V_17 & ~ V_142 ) ;
V_14 -> V_16 . V_17 = V_143 ;
}
}
static void F_99 ( struct V_13 * V_14 )
{
if ( ( V_14 -> V_16 . V_17 & V_142 ) == 0x003c ) {
T_1 V_143 = F_98 ( . V_14 = 0xc2 , . V_145 = 0x01 , . V_144 = 1 , . V_111 = 16 ) ;
V_143 |= ( V_14 -> V_16 . V_17 & ~ V_142 ) ;
V_14 -> V_16 . V_17 = V_143 ;
}
}
static int F_100 ( struct V_13 * V_14 )
{
int V_146 = F_101 ( V_14 ) ;
if ( V_146 )
return V_146 ;
if ( V_14 -> V_38 . V_39 ) {
if ( ! V_14 -> V_38 . V_81 ) {
V_14 -> V_16 . V_52 |= V_147 ;
if ( ! ( V_14 -> V_38 . V_148 & ~ V_149 ) )
V_14 -> V_16 . V_52 |= V_150 ;
}
if ( V_10 . V_151 )
V_10 . V_151 ( V_14 ) ;
}
if ( F_31 ( V_14 ) ) {
V_146 = F_102 ( V_14 ) ;
if ( V_146 )
return V_146 ;
if ( ! F_103 ( V_14 ) ) {
if ( F_104 ( V_152 ) )
return - V_153 ;
V_14 -> V_154 = V_155 ;
}
}
if ( V_14 -> V_38 . type != V_156 )
return 0 ;
if ( ! ( V_14 -> V_38 . V_17 & V_44 ) )
return 0 ;
if ( V_10 . V_43 < 3 )
return - V_157 ;
if ( F_105 () && ! F_106 ( V_158 ) )
return - V_159 ;
V_14 -> V_16 . V_17 |= V_44 ;
return 0 ;
}
struct V_160 * F_107 ( int * V_161 )
{
if ( V_10 . V_162 )
return V_10 . V_162 ( V_161 ) ;
* V_161 = 0 ;
return NULL ;
}
static struct V_160 * F_108 ( int * V_161 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
struct V_160 * V_163 = V_4 -> V_164 ;
V_163 [ 0 ] . V_165 = V_5 ;
V_163 [ 0 ] . V_166 = V_10 . V_11 & ~ V_4 -> V_12 ;
V_163 [ 0 ] . V_167 = V_10 . V_11 & ~ V_4 -> V_35 ;
V_163 [ 1 ] . V_165 = V_168 ;
V_163 [ 1 ] . V_166 = V_4 -> V_169 ;
V_163 [ 1 ] . V_167 = 0 ;
* V_161 = 2 ;
return V_163 ;
}
static struct V_160 * F_109 ( int * V_161 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
struct V_160 * V_163 = V_4 -> V_164 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_10 . V_53 ; V_29 ++ ) {
struct V_13 * V_14 = V_4 -> V_15 [ V_29 ] ;
V_163 [ V_29 ] . V_165 = F_47 ( V_29 ) ;
V_163 [ V_29 ] . V_166 = V_163 [ V_29 ] . V_167 = 0 ;
if ( ! F_5 ( V_29 , V_4 -> V_7 ) )
continue;
V_163 [ V_29 ] . V_166 = V_163 [ V_29 ] . V_167 =
V_14 -> V_16 . V_17 | V_22 ;
if ( V_14 -> V_38 . V_46 )
V_163 [ V_29 ] . V_166 &= ~ V_22 ;
else if ( V_14 -> V_38 . V_47 )
V_163 [ V_29 ] . V_167 &= ~ V_22 ;
}
* V_161 = V_10 . V_53 ;
return V_163 ;
}
static void F_110 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_38 . V_46 )
F_111 ( V_14 ) ;
}
static void F_112 ( int V_8 )
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
static int F_113 ( struct V_13 * V_14 )
{
int V_146 = F_100 ( V_14 ) ;
if ( V_146 )
return V_146 ;
if ( ! F_114 ( V_170 ) && ! F_114 ( V_171 ) )
return 0 ;
V_14 -> V_16 . V_17 |= V_14 -> V_38 . V_17 & ( V_172 | V_34 ) ;
if ( ( V_14 -> V_16 . V_17 & ( V_172 | V_34 ) ) &&
( ( V_14 -> V_16 . V_17 & V_44 ) ||
V_14 -> V_38 . V_39 > 0 ) )
return - V_173 ;
if ( F_27 ( V_14 ) ) {
if ( V_14 -> V_38 . V_85 > 0 &&
V_14 -> V_38 . V_85 < 0x7fffffff )
return - V_173 ;
}
return 0 ;
}
static struct V_79 *
F_115 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_79 * V_96 ;
V_96 = F_92 ( V_4 , V_29 , V_14 ) ;
if ( V_14 -> V_16 . V_17 & V_34 ) {
if ( V_96 -> V_137 & ( 1U << 2 ) )
return & V_174 ;
return & V_97 ;
}
return V_96 ;
}
static unsigned F_116 ( struct V_13 * V_14 , unsigned V_175 )
{
if ( ( V_14 -> V_16 . V_17 & V_82 ) ==
F_98 ( . V_14 = 0xc0 , . V_145 = 0x01 ) ) {
if ( V_175 < 128 )
V_175 = 128 ;
V_175 &= ~ 0x3fu ;
}
return V_175 ;
}
T_2 F_117 ( char * V_176 , T_1 V_17 )
{
T_1 V_14 = ( V_17 & V_177 ) ;
return F_118 ( V_176 , V_17 , V_14 ) ;
}
struct V_178 * F_119 ( int V_179 )
{
struct V_178 * V_62 ;
int V_19 ;
V_62 = F_120 ( sizeof( struct V_178 ) ,
V_180 , F_121 ( V_179 ) ) ;
if ( V_62 ) {
for ( V_19 = 0 ; V_19 < V_181 ; V_19 ++ )
F_122 ( & V_62 -> V_62 [ V_19 ] . V_103 ) ;
V_62 -> V_182 = - 1 ;
}
return V_62 ;
}
static struct V_114 * F_123 ( int V_179 )
{
struct V_114 * V_96 ;
V_96 = F_120 ( sizeof( struct V_114 ) ,
V_180 , F_121 ( V_179 ) ) ;
if ( V_96 ) {
F_122 ( & V_96 -> V_103 ) ;
V_96 -> V_182 = - 1 ;
}
return V_96 ;
}
static int F_124 ( int V_179 )
{
struct V_3 * V_4 = & F_125 ( V_3 , V_179 ) ;
if ( V_10 . V_91 || V_10 . V_183 ) {
V_4 -> V_102 = F_119 ( V_179 ) ;
if ( ! V_4 -> V_102 )
goto V_184;
}
if ( V_10 . V_52 & V_185 ) {
T_3 V_186 = V_140 * sizeof( struct V_79 ) ;
V_4 -> V_131 = F_126 ( V_186 , V_180 ) ;
if ( ! V_4 -> V_131 )
goto V_187;
V_4 -> V_115 = F_123 ( V_179 ) ;
if ( ! V_4 -> V_115 )
goto V_188;
V_4 -> V_119 = 0 ;
}
return V_189 ;
V_188:
F_127 ( V_4 -> V_131 ) ;
V_4 -> V_131 = NULL ;
V_187:
F_127 ( V_4 -> V_102 ) ;
V_4 -> V_102 = NULL ;
V_184:
return V_190 ;
}
static void F_128 ( int V_179 )
{
struct V_3 * V_4 = & F_125 ( V_3 , V_179 ) ;
int V_182 = F_129 ( V_179 ) ;
int V_19 ;
F_130 ( V_179 ) ;
F_131 () ;
V_4 -> V_191 = NULL ;
if ( ! V_4 -> V_102 )
return;
if ( ! ( V_10 . V_52 & V_192 ) ) {
void * * V_193 = & V_4 -> V_194 [ V_195 ] ;
F_132 (i, topology_sibling_cpumask(cpu)) {
struct V_178 * V_196 ;
V_196 = F_125 ( V_3 , V_19 ) . V_102 ;
if ( V_196 && V_196 -> V_182 == V_182 ) {
* V_193 = V_4 -> V_102 ;
V_4 -> V_102 = V_196 ;
break;
}
}
V_4 -> V_102 -> V_182 = V_182 ;
V_4 -> V_102 -> V_197 ++ ;
}
if ( V_10 . V_183 )
V_4 -> V_191 = & V_4 -> V_102 -> V_62 [ V_198 ] ;
if ( V_10 . V_52 & V_185 ) {
F_132 (i, topology_sibling_cpumask(cpu)) {
struct V_114 * V_96 ;
V_96 = F_125 ( V_3 , V_19 ) . V_115 ;
if ( V_96 && V_96 -> V_182 == V_182 ) {
V_4 -> V_194 [ 1 ] = V_4 -> V_115 ;
V_4 -> V_115 = V_96 ;
V_4 -> V_119 = 1 ;
break;
}
}
V_4 -> V_115 -> V_182 = V_182 ;
V_4 -> V_115 -> V_197 ++ ;
}
}
static void F_133 ( int V_179 )
{
struct V_3 * V_4 = & F_125 ( V_3 , V_179 ) ;
struct V_114 * V_96 ;
V_96 = V_4 -> V_115 ;
if ( V_96 ) {
if ( V_96 -> V_182 == - 1 || -- V_96 -> V_197 == 0 )
F_127 ( V_96 ) ;
V_4 -> V_115 = NULL ;
F_127 ( V_4 -> V_131 ) ;
V_4 -> V_131 = NULL ;
}
}
static void F_134 ( int V_179 )
{
struct V_3 * V_4 = & F_125 ( V_3 , V_179 ) ;
struct V_178 * V_196 ;
V_196 = V_4 -> V_102 ;
if ( V_196 ) {
if ( V_196 -> V_182 == - 1 || -- V_196 -> V_197 == 0 )
F_127 ( V_196 ) ;
V_4 -> V_102 = NULL ;
}
F_133 ( V_179 ) ;
F_135 ( V_179 ) ;
}
static void F_136 ( struct V_199 * V_200 ,
bool V_201 )
{
if ( V_10 . V_202 )
F_137 ( V_200 , V_201 ) ;
if ( V_10 . V_58 )
F_138 ( V_200 , V_201 ) ;
}
static T_4 void F_139 ( void )
{
F_140 ( L_3 ) ;
V_10 . V_203 = 0 ;
V_10 . V_204 = NULL ;
}
static int F_141 ( int V_179 )
{
T_5 V_205 = V_206 ;
switch ( F_142 ( V_179 ) . V_207 ) {
case 42 :
V_205 = 0x28 ;
break;
case 45 :
switch ( F_142 ( V_179 ) . V_208 ) {
case 6 : V_205 = 0x618 ; break;
case 7 : V_205 = 0x70c ; break;
}
}
return ( F_142 ( V_179 ) . V_209 < V_205 ) ;
}
static void F_143 ( void )
{
int V_210 = 0 ;
int V_179 ;
F_144 () ;
F_145 (cpu) {
if ( ( V_210 = F_141 ( V_179 ) ) )
break;
}
F_146 () ;
if ( V_210 == V_10 . V_210 )
return;
if ( V_10 . V_210 ) {
F_44 ( L_4 ) ;
V_10 . V_210 = 0 ;
} else {
F_44 ( L_5 ) ;
V_10 . V_210 = 1 ;
}
}
static bool F_147 ( unsigned long V_165 , T_1 V_32 )
{
T_1 V_211 , V_212 , V_213 ;
if ( F_148 ( V_165 , & V_211 ) )
return false ;
V_213 = V_211 ^ V_32 ;
if ( F_46 ( V_165 , V_213 ) ||
F_148 ( V_165 , & V_212 ) )
return false ;
if ( V_212 != V_213 )
return false ;
F_4 ( V_165 , V_211 ) ;
return true ;
}
static T_4 void F_149 ( void )
{
V_10 . V_214 = F_143 ;
F_143 () ;
}
static T_4 void F_150 ( void )
{
int V_65 ;
F_61 (bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
V_2 [ V_215 [ V_65 ] . V_216 ] = 0 ;
F_140 ( L_6 ,
V_215 [ V_65 ] . V_217 ) ;
}
}
static T_4 void F_151 ( void )
{
union V_218 V_219 ;
V_219 . V_220 = V_10 . V_221 ;
if ( V_219 . V_222 . V_223 ) {
V_2 [ V_224 ] = 0x7f89 ;
V_219 . V_222 . V_223 = 0 ;
V_10 . V_221 = V_219 . V_220 ;
F_44 ( L_7 ) ;
}
}
static T_4 void F_152 ( void )
{
V_10 . V_52 |= V_185 | V_225 ;
V_10 . V_226 = F_81 ;
V_10 . V_227 = F_84 ;
V_10 . V_228 = F_86 ;
}
T_4 int F_153 ( void )
{
union V_229 V_230 ;
union V_231 V_232 ;
union V_218 V_219 ;
struct V_79 * V_96 ;
unsigned int V_233 ;
struct V_90 * V_234 ;
int V_43 , V_19 ;
if ( ! F_154 ( & V_235 , V_236 ) ) {
switch ( V_235 . V_237 ) {
case 0x6 :
return F_155 () ;
case 0xb :
return F_156 () ;
case 0xf :
return F_157 () ;
}
return - V_238 ;
}
F_158 ( 10 , & V_232 . V_220 , & V_219 . V_220 , & V_233 , & V_230 . V_220 ) ;
if ( V_232 . V_222 . V_239 < V_240 )
return - V_238 ;
V_43 = V_232 . V_222 . V_241 ;
if ( V_43 < 2 )
V_10 = V_242 ;
else
V_10 = V_243 ;
V_10 . V_43 = V_43 ;
V_10 . V_53 = V_232 . V_222 . V_53 ;
V_10 . V_244 = V_232 . V_222 . V_245 ;
V_10 . V_246 = ( 1ULL << V_232 . V_222 . V_245 ) - 1 ;
V_10 . V_221 = V_219 . V_220 ;
V_10 . V_247 = V_232 . V_222 . V_239 ;
V_10 . V_248 = F_159 ( unsigned , V_249 , V_10 . V_53 ) ;
if ( V_43 > 1 )
V_10 . V_54 = F_160 ( ( int ) V_230 . V_222 . V_54 , 3 ) ;
if ( F_114 ( V_250 ) ) {
T_1 V_251 ;
F_24 ( V_252 , V_251 ) ;
V_10 . V_253 . V_251 = V_251 ;
}
F_161 () ;
F_162 ( F_150 ) ;
switch ( V_235 . V_207 ) {
case 14 :
F_163 ( L_8 ) ;
break;
case 15 :
F_162 ( F_139 ) ;
case 22 :
case 23 :
case 29 :
memcpy ( V_254 , V_255 ,
sizeof( V_254 ) ) ;
F_164 () ;
V_10 . V_110 = V_256 ;
V_10 . V_204 = V_257 ;
F_163 ( L_9 ) ;
break;
case 30 :
case 26 :
case 46 :
memcpy ( V_254 , V_258 ,
sizeof( V_254 ) ) ;
memcpy ( V_259 , V_260 ,
sizeof( V_259 ) ) ;
F_165 () ;
V_10 . V_110 = V_261 ;
V_10 . V_204 = V_262 ;
V_10 . V_263 = F_22 ;
V_10 . V_91 = V_264 ;
V_10 . V_265 = V_266 ;
V_2 [ V_267 ] =
F_98 ( . V_14 = 0x0e , . V_145 = 0x01 , . V_144 = 1 , . V_111 = 1 ) ;
V_2 [ V_268 ] =
F_98 ( . V_14 = 0xb1 , . V_145 = 0x3f , . V_144 = 1 , . V_111 = 1 ) ;
F_162 ( F_151 ) ;
F_163 ( L_10 ) ;
break;
case 28 :
case 38 :
case 39 :
case 53 :
case 54 :
memcpy ( V_254 , V_269 ,
sizeof( V_254 ) ) ;
F_166 () ;
V_10 . V_110 = V_270 ;
V_10 . V_204 = V_271 ;
F_163 ( L_11 ) ;
break;
case 55 :
case 76 :
case 77 :
memcpy ( V_254 , V_272 ,
sizeof( V_254 ) ) ;
memcpy ( V_259 , V_273 ,
sizeof( V_259 ) ) ;
F_166 () ;
V_10 . V_110 = V_274 ;
V_10 . V_204 = V_275 ;
V_10 . V_91 = V_276 ;
V_10 . V_52 |= V_87 ;
F_163 ( L_12 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_254 , V_277 ,
sizeof( V_254 ) ) ;
memcpy ( V_259 , V_260 ,
sizeof( V_259 ) ) ;
F_165 () ;
V_10 . V_110 = V_278 ;
V_10 . V_263 = F_22 ;
V_10 . V_204 = V_279 ;
V_10 . V_91 = V_280 ;
V_10 . V_52 |= V_87 ;
V_10 . V_265 = V_266 ;
V_2 [ V_267 ] =
F_98 ( . V_14 = 0x0e , . V_145 = 0x01 , . V_144 = 1 , . V_111 = 1 ) ;
V_2 [ V_268 ] =
F_98 ( . V_14 = 0xb1 , . V_145 = 0x3f , . V_144 = 1 , . V_111 = 1 ) ;
F_163 ( L_13 ) ;
break;
case 42 :
case 45 :
F_162 ( F_149 ) ;
F_162 ( F_152 ) ;
memcpy ( V_254 , V_281 ,
sizeof( V_254 ) ) ;
memcpy ( V_259 , V_282 ,
sizeof( V_259 ) ) ;
F_167 () ;
V_10 . V_110 = V_283 ;
V_10 . V_204 = V_284 ;
V_10 . V_151 = F_99 ;
if ( V_235 . V_207 == 45 )
V_10 . V_91 = V_285 ;
else
V_10 . V_91 = V_286 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_192 ;
V_10 . V_265 = V_287 ;
V_2 [ V_267 ] =
F_98 ( . V_14 = 0x0e , . V_145 = 0x01 , . V_144 = 1 , . V_111 = 1 ) ;
V_2 [ V_268 ] =
F_98 ( . V_14 = 0xb1 , . V_145 = 0x01 , . V_144 = 1 , . V_111 = 1 ) ;
F_163 ( L_14 ) ;
break;
case 58 :
case 62 :
F_162 ( F_152 ) ;
memcpy ( V_254 , V_281 ,
sizeof( V_254 ) ) ;
V_254 [ F_168 ( V_288 ) ] [ F_168 ( V_289 ) ] [ F_168 ( V_290 ) ] = 0x8108 ;
memcpy ( V_259 , V_282 ,
sizeof( V_259 ) ) ;
F_167 () ;
V_10 . V_110 = V_291 ;
V_10 . V_204 = V_292 ;
V_10 . V_151 = F_99 ;
if ( V_235 . V_207 == 62 )
V_10 . V_91 = V_285 ;
else
V_10 . V_91 = V_286 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_192 ;
V_10 . V_265 = V_287 ;
V_2 [ V_267 ] =
F_98 ( . V_14 = 0x0e , . V_145 = 0x01 , . V_144 = 1 , . V_111 = 1 ) ;
F_163 ( L_15 ) ;
break;
case 60 :
case 63 :
case 69 :
case 70 :
F_162 ( F_152 ) ;
V_10 . V_68 = true ;
memcpy ( V_254 , V_293 , sizeof( V_254 ) ) ;
memcpy ( V_259 , V_294 , sizeof( V_259 ) ) ;
F_169 () ;
V_10 . V_110 = V_295 ;
V_10 . V_204 = V_296 ;
V_10 . V_91 = V_285 ;
V_10 . V_151 = F_99 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_192 ;
V_10 . V_297 = F_113 ;
V_10 . V_298 = F_115 ;
V_10 . V_265 = V_299 ;
V_10 . V_300 = true ;
F_163 ( L_16 ) ;
break;
case 61 :
case 86 :
case 71 :
case 79 :
V_10 . V_68 = true ;
memcpy ( V_254 , V_293 , sizeof( V_254 ) ) ;
memcpy ( V_259 , V_294 , sizeof( V_259 ) ) ;
V_259 [ F_168 ( V_301 ) ] [ F_168 ( V_289 ) ] [ F_168 ( V_290 ) ] = V_302 |
V_303 | V_304 ;
V_259 [ F_168 ( V_301 ) ] [ F_168 ( V_305 ) ] [ F_168 ( V_290 ) ] = V_306 | V_303 |
V_304 ;
V_259 [ F_168 ( V_307 ) ] [ F_168 ( V_289 ) ] [ F_168 ( V_308 ) ] = V_302 |
V_309 | V_304 ;
V_259 [ F_168 ( V_307 ) ] [ F_168 ( V_305 ) ] [ F_168 ( V_308 ) ] = V_306 |
V_309 | V_304 ;
F_169 () ;
V_10 . V_110 = V_310 ;
V_10 . V_204 = V_296 ;
V_10 . V_91 = V_285 ;
V_10 . V_151 = F_99 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_192 ;
V_10 . V_297 = F_113 ;
V_10 . V_298 = F_115 ;
V_10 . V_265 = V_299 ;
V_10 . V_311 = F_116 ;
F_163 ( L_17 ) ;
break;
default:
switch ( V_10 . V_43 ) {
case 1 :
V_10 . V_110 = V_312 ;
F_163 ( L_18 ) ;
break;
default:
V_10 . V_110 = V_270 ;
F_163 ( L_19 ) ;
break;
}
}
if ( V_10 . V_53 > V_313 ) {
F_55 ( 1 , V_314 L_20 ,
V_10 . V_53 , V_313 ) ;
V_10 . V_53 = V_313 ;
}
V_10 . V_11 = ( 1 << V_10 . V_53 ) - 1 ;
if ( V_10 . V_54 > V_315 ) {
F_55 ( 1 , V_314 L_21 ,
V_10 . V_54 , V_315 ) ;
V_10 . V_54 = V_315 ;
}
V_10 . V_11 |=
( ( 1LL << V_10 . V_54 ) - 1 ) << V_30 ;
if ( V_10 . V_110 ) {
F_78 (c, x86_pmu.event_constraints) {
if ( V_96 -> V_111 == V_316
&& V_96 -> V_137 != V_317 ) {
V_96 -> V_137 |= ( 1ULL << V_10 . V_53 ) - 1 ;
}
V_96 -> V_137 &=
~ ( ~ 0UL << ( V_30 + V_10 . V_54 ) ) ;
V_96 -> V_136 = F_91 ( V_96 -> V_137 ) ;
}
}
if ( V_10 . V_58 && ! F_147 ( V_10 . V_318 , 0x3UL ) )
V_10 . V_58 = 0 ;
for ( V_19 = 0 ; V_19 < V_10 . V_58 ; V_19 ++ ) {
if ( ! ( F_147 ( V_10 . V_319 + V_19 , 0xffffUL ) &&
F_147 ( V_10 . V_320 + V_19 , 0xffffUL ) ) )
V_10 . V_58 = 0 ;
}
if ( V_10 . V_91 ) {
for ( V_234 = V_10 . V_91 ; V_234 -> V_165 ; V_234 ++ ) {
V_234 -> V_321 = F_147 ( V_234 -> V_165 , 0x1ffUL ) ;
if ( ( V_234 -> V_29 == V_198 ) && ! V_234 -> V_321 )
V_10 . V_183 = NULL ;
}
}
if ( V_10 . V_253 . V_322 ) {
V_10 . V_323 = V_10 . V_246 ;
V_10 . V_324 = V_325 ;
F_163 ( L_22 ) ;
}
return 0 ;
}
static T_4 int F_170 ( void )
{
int V_179 = F_45 () ;
int V_326 , V_96 ;
if ( ! ( V_10 . V_52 & V_225 ) )
return 0 ;
V_326 = F_171 ( F_172 ( V_179 ) ) ;
if ( V_326 > 1 ) {
F_44 ( L_23 ) ;
return 0 ;
}
F_173 () ;
V_10 . V_52 &= ~ ( V_185 | V_225 ) ;
V_10 . V_226 = NULL ;
V_10 . V_227 = NULL ;
V_10 . V_228 = NULL ;
F_174 () ;
F_144 () ;
F_145 (c) {
F_133 ( V_96 ) ;
}
F_146 () ;
F_44 ( L_24 ) ;
return 0 ;
}
