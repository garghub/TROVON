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
struct V_116 * V_117 , * V_118 ;
int V_119 = V_4 -> V_120 ;
int V_121 = 1 - V_119 ;
if ( V_4 -> V_101 || ! F_82 () )
return;
if ( ! V_115 )
return;
V_118 = & V_115 -> V_122 [ V_121 ] ;
V_117 = & V_115 -> V_122 [ V_119 ] ;
V_117 -> V_123 = true ;
F_14 ( ! F_83 () ) ;
F_84 ( & V_115 -> V_103 ) ;
memcpy ( V_118 -> V_124 , V_118 -> V_125 , sizeof( V_118 -> V_124 ) ) ;
}
static void
F_85 ( struct V_3 * V_4 )
{
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_116 * V_117 , * V_118 ;
int V_119 = V_4 -> V_120 ;
int V_121 = 1 - V_119 ;
if ( V_4 -> V_101 || ! F_82 () )
return;
if ( ! V_115 )
return;
V_118 = & V_115 -> V_122 [ V_121 ] ;
V_117 = & V_115 -> V_122 [ V_119 ] ;
memcpy ( V_118 -> V_125 , V_118 -> V_124 , sizeof( V_118 -> V_125 ) ) ;
V_117 -> V_123 = false ;
F_86 ( & V_115 -> V_103 ) ;
}
static struct V_79 *
F_87 ( struct V_3 * V_4 , struct V_13 * V_14 ,
int V_29 , struct V_79 * V_96 )
{
struct V_79 * V_126 ;
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_116 * V_117 , * V_118 ;
int V_127 , V_19 ;
int V_119 = V_4 -> V_120 ;
int V_121 = 1 - V_119 ;
if ( V_4 -> V_101 || ! F_82 () )
return V_96 ;
if ( ! V_115 )
return V_96 ;
V_127 = V_96 -> V_52 & V_128 ;
if ( V_127 && ! ( V_14 -> V_16 . V_52 & V_129 ) ) {
V_14 -> V_16 . V_52 |= V_129 ;
if ( ! V_4 -> V_130 ++ )
F_88 ( V_115 -> V_131 [ V_119 ] , 1 ) ;
}
V_117 = & V_115 -> V_122 [ V_119 ] ;
V_118 = & V_115 -> V_122 [ V_121 ] ;
V_126 = V_96 ;
if ( ! ( V_96 -> V_52 & V_132 ) ) {
if ( V_29 < 0 )
return & V_97 ;
V_126 = & V_4 -> V_133 [ V_29 ] ;
memcpy ( V_126 , V_96 , sizeof( * V_126 ) ) ;
V_126 -> V_52 |= V_132 ;
}
F_61 (i, cx->idxmsk, X86_PMC_IDX_MAX) {
if ( V_117 -> V_125 [ V_19 ] == V_134 )
F_89 ( V_19 , V_126 -> V_135 ) ;
if ( V_127 && V_117 -> V_125 [ V_19 ] == V_136 )
F_89 ( V_19 , V_126 -> V_135 ) ;
}
V_126 -> V_137 = F_90 ( V_126 -> V_138 ) ;
if ( V_126 -> V_137 == 0 )
V_126 = & V_97 ;
return V_126 ;
}
static struct V_79 *
F_91 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_79 * V_139 = V_4 -> V_79 [ V_29 ] ;
struct V_79 * V_140 ;
V_140 = F_79 ( V_4 , V_29 , V_14 ) ;
if ( V_139 && ( V_139 -> V_52 & V_132 ) ) {
F_92 ( V_139 -> V_135 , V_140 -> V_135 , V_141 ) ;
V_139 -> V_137 = V_140 -> V_137 ;
V_140 = V_139 ;
}
if ( V_4 -> V_115 )
return F_87 ( V_4 , V_14 , V_29 , V_140 ) ;
return V_140 ;
}
static void F_93 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_16 ;
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_116 * V_118 , * V_117 ;
unsigned long V_52 = 0 ;
int V_119 = V_4 -> V_120 ;
int V_121 = 1 - V_119 ;
if ( V_4 -> V_101 )
return;
F_14 ( ! V_115 ) ;
if ( ! V_115 )
return;
V_117 = & V_115 -> V_122 [ V_119 ] ;
V_118 = & V_115 -> V_122 [ V_121 ] ;
if ( V_28 -> V_52 & V_129 ) {
V_28 -> V_52 &= ~ V_129 ;
if ( ! -- V_4 -> V_130 )
F_88 ( V_115 -> V_131 [ V_119 ] , 0 ) ;
}
if ( ! V_117 -> V_123 )
F_70 ( & V_115 -> V_103 , V_52 ) ;
if ( V_28 -> V_29 >= 0 )
V_118 -> V_125 [ V_28 -> V_29 ] = V_142 ;
if ( ! V_117 -> V_123 )
F_73 ( & V_115 -> V_103 , V_52 ) ;
}
static void
F_94 ( struct V_3 * V_4 ,
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
static void F_95 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
F_94 ( V_4 , V_14 ) ;
if ( V_4 -> V_115 )
F_93 ( V_4 , V_14 ) ;
}
static void F_96 ( struct V_3 * V_4 , int V_29 , int V_143 )
{
struct V_114 * V_115 = V_4 -> V_115 ;
struct V_79 * V_96 = V_4 -> V_79 [ V_29 ] ;
struct V_116 * V_118 , * V_117 ;
int V_119 = V_4 -> V_120 ;
int V_121 = 1 - V_119 ;
int V_127 ;
if ( V_4 -> V_101 || ! V_96 )
return;
V_127 = V_96 -> V_52 & V_128 ;
if ( ! ( V_96 -> V_52 & V_132 ) )
return;
F_14 ( ! V_115 ) ;
if ( ! V_115 )
return;
V_117 = & V_115 -> V_122 [ V_119 ] ;
V_118 = & V_115 -> V_122 [ V_121 ] ;
F_14 ( ! F_97 ( & V_115 -> V_103 ) ) ;
if ( V_143 >= 0 ) {
if ( V_127 )
V_118 -> V_124 [ V_143 ] = V_134 ;
else
V_118 -> V_124 [ V_143 ] = V_136 ;
}
}
static void F_98 ( struct V_13 * V_14 )
{
if ( ( V_14 -> V_16 . V_17 & V_144 ) == 0x003c ) {
T_1 V_145 = F_99 ( . V_14 = 0xc0 , . V_146 = 1 , . V_111 = 16 ) ;
V_145 |= ( V_14 -> V_16 . V_17 & ~ V_144 ) ;
V_14 -> V_16 . V_17 = V_145 ;
}
}
static void F_100 ( struct V_13 * V_14 )
{
if ( ( V_14 -> V_16 . V_17 & V_144 ) == 0x003c ) {
T_1 V_145 = F_99 ( . V_14 = 0xc2 , . V_147 = 0x01 , . V_146 = 1 , . V_111 = 16 ) ;
V_145 |= ( V_14 -> V_16 . V_17 & ~ V_144 ) ;
V_14 -> V_16 . V_17 = V_145 ;
}
}
static int F_101 ( struct V_13 * V_14 )
{
int V_148 = F_102 ( V_14 ) ;
if ( V_148 )
return V_148 ;
if ( V_14 -> V_38 . V_39 && V_10 . V_149 )
V_10 . V_149 ( V_14 ) ;
if ( F_31 ( V_14 ) ) {
V_148 = F_103 ( V_14 ) ;
if ( V_148 )
return V_148 ;
if ( ! F_104 ( V_14 ) ) {
if ( F_105 ( V_150 ) )
return - V_151 ;
V_14 -> V_152 = V_153 ;
}
}
if ( V_14 -> V_38 . type != V_154 )
return 0 ;
if ( ! ( V_14 -> V_38 . V_17 & V_44 ) )
return 0 ;
if ( V_10 . V_43 < 3 )
return - V_155 ;
if ( F_106 () && ! F_107 ( V_156 ) )
return - V_157 ;
V_14 -> V_16 . V_17 |= V_44 ;
return 0 ;
}
struct V_158 * F_108 ( int * V_159 )
{
if ( V_10 . V_160 )
return V_10 . V_160 ( V_159 ) ;
* V_159 = 0 ;
return NULL ;
}
static struct V_158 * F_109 ( int * V_159 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
struct V_158 * V_161 = V_4 -> V_162 ;
V_161 [ 0 ] . V_163 = V_5 ;
V_161 [ 0 ] . V_164 = V_10 . V_11 & ~ V_4 -> V_12 ;
V_161 [ 0 ] . V_165 = V_10 . V_11 & ~ V_4 -> V_35 ;
V_161 [ 1 ] . V_163 = V_166 ;
V_161 [ 1 ] . V_164 = V_4 -> V_167 ;
V_161 [ 1 ] . V_165 = 0 ;
* V_159 = 2 ;
return V_161 ;
}
static struct V_158 * F_110 ( int * V_159 )
{
struct V_3 * V_4 = F_3 ( & V_3 ) ;
struct V_158 * V_161 = V_4 -> V_162 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_10 . V_53 ; V_29 ++ ) {
struct V_13 * V_14 = V_4 -> V_15 [ V_29 ] ;
V_161 [ V_29 ] . V_163 = F_47 ( V_29 ) ;
V_161 [ V_29 ] . V_164 = V_161 [ V_29 ] . V_165 = 0 ;
if ( ! F_5 ( V_29 , V_4 -> V_7 ) )
continue;
V_161 [ V_29 ] . V_164 = V_161 [ V_29 ] . V_165 =
V_14 -> V_16 . V_17 | V_22 ;
if ( V_14 -> V_38 . V_46 )
V_161 [ V_29 ] . V_164 &= ~ V_22 ;
else if ( V_14 -> V_38 . V_47 )
V_161 [ V_29 ] . V_165 &= ~ V_22 ;
}
* V_159 = V_10 . V_53 ;
return V_161 ;
}
static void F_111 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_38 . V_46 )
F_112 ( V_14 ) ;
}
static void F_113 ( int V_8 )
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
static int F_114 ( struct V_13 * V_14 )
{
int V_148 = F_101 ( V_14 ) ;
if ( V_148 )
return V_148 ;
if ( ! F_115 ( V_168 ) && ! F_115 ( V_169 ) )
return 0 ;
V_14 -> V_16 . V_17 |= V_14 -> V_38 . V_17 & ( V_170 | V_34 ) ;
if ( ( V_14 -> V_16 . V_17 & ( V_170 | V_34 ) ) &&
( ( V_14 -> V_16 . V_17 & V_44 ) ||
V_14 -> V_38 . V_39 > 0 ) )
return - V_171 ;
if ( F_27 ( V_14 ) ) {
if ( V_14 -> V_38 . V_85 > 0 &&
V_14 -> V_38 . V_85 < 0x7fffffff )
return - V_171 ;
}
return 0 ;
}
static struct V_79 *
F_116 ( struct V_3 * V_4 , int V_29 ,
struct V_13 * V_14 )
{
struct V_79 * V_96 ;
V_96 = F_91 ( V_4 , V_29 , V_14 ) ;
if ( V_14 -> V_16 . V_17 & V_34 ) {
if ( V_96 -> V_138 & ( 1U << 2 ) )
return & V_172 ;
return & V_97 ;
}
return V_96 ;
}
static unsigned F_117 ( struct V_13 * V_14 , unsigned V_173 )
{
if ( ( V_14 -> V_16 . V_17 & V_82 ) ==
F_99 ( . V_14 = 0xc0 , . V_147 = 0x01 ) ) {
if ( V_173 < 128 )
V_173 = 128 ;
V_173 &= ~ 0x3fu ;
}
return V_173 ;
}
T_2 F_118 ( char * V_174 , T_1 V_17 )
{
T_1 V_14 = ( V_17 & V_175 ) ;
return F_119 ( V_174 , V_17 , V_14 ) ;
}
struct V_176 * F_120 ( int V_177 )
{
struct V_176 * V_62 ;
int V_19 ;
V_62 = F_121 ( sizeof( struct V_176 ) ,
V_178 , F_122 ( V_177 ) ) ;
if ( V_62 ) {
for ( V_19 = 0 ; V_19 < V_179 ; V_19 ++ )
F_123 ( & V_62 -> V_62 [ V_19 ] . V_103 ) ;
V_62 -> V_180 = - 1 ;
}
return V_62 ;
}
static struct V_114 * F_124 ( int V_177 )
{
struct V_114 * V_96 ;
int V_19 ;
V_96 = F_121 ( sizeof( struct V_114 ) ,
V_178 , F_122 ( V_177 ) ) ;
if ( V_96 ) {
F_123 ( & V_96 -> V_103 ) ;
for ( V_19 = 0 ; V_19 < V_141 ; V_19 ++ ) {
V_96 -> V_122 [ 0 ] . V_125 [ V_19 ] = V_142 ;
V_96 -> V_122 [ 0 ] . V_124 [ V_19 ] = V_142 ;
V_96 -> V_122 [ 1 ] . V_125 [ V_19 ] = V_142 ;
V_96 -> V_122 [ 1 ] . V_124 [ V_19 ] = V_142 ;
}
V_96 -> V_180 = - 1 ;
}
return V_96 ;
}
static int F_125 ( int V_177 )
{
struct V_3 * V_4 = & F_126 ( V_3 , V_177 ) ;
if ( V_10 . V_91 || V_10 . V_181 ) {
V_4 -> V_102 = F_120 ( V_177 ) ;
if ( ! V_4 -> V_102 )
return V_182 ;
}
if ( V_10 . V_52 & V_183 ) {
T_3 V_184 = V_141 * sizeof( struct V_79 ) ;
V_4 -> V_133 = F_127 ( V_184 , V_178 ) ;
if ( ! V_4 -> V_133 )
return V_182 ;
V_4 -> V_115 = F_124 ( V_177 ) ;
if ( ! V_4 -> V_115 ) {
F_128 ( V_4 -> V_133 ) ;
F_128 ( V_4 -> V_102 ) ;
return V_182 ;
}
V_4 -> V_120 = 0 ;
}
return V_185 ;
}
static void F_129 ( int V_177 )
{
struct V_3 * V_4 = & F_126 ( V_3 , V_177 ) ;
int V_180 = F_130 ( V_177 ) ;
int V_19 ;
F_131 ( V_177 ) ;
F_132 () ;
V_4 -> V_186 = NULL ;
if ( ! V_4 -> V_102 )
return;
if ( ! ( V_10 . V_52 & V_187 ) ) {
void * * V_188 = & V_4 -> V_189 [ V_190 ] ;
F_133 (i, topology_thread_cpumask(cpu)) {
struct V_176 * V_191 ;
V_191 = F_126 ( V_3 , V_19 ) . V_102 ;
if ( V_191 && V_191 -> V_180 == V_180 ) {
* V_188 = V_4 -> V_102 ;
V_4 -> V_102 = V_191 ;
break;
}
}
V_4 -> V_102 -> V_180 = V_180 ;
V_4 -> V_102 -> V_192 ++ ;
}
if ( V_10 . V_181 )
V_4 -> V_186 = & V_4 -> V_102 -> V_62 [ V_193 ] ;
if ( V_10 . V_52 & V_183 ) {
F_133 (i, topology_thread_cpumask(cpu)) {
struct V_114 * V_96 ;
V_96 = F_126 ( V_3 , V_19 ) . V_115 ;
if ( V_96 && V_96 -> V_180 == V_180 ) {
V_4 -> V_189 [ 1 ] = V_4 -> V_115 ;
V_4 -> V_115 = V_96 ;
V_4 -> V_120 = 1 ;
break;
}
}
V_4 -> V_115 -> V_180 = V_180 ;
V_4 -> V_115 -> V_192 ++ ;
}
}
static void F_134 ( int V_177 )
{
struct V_3 * V_4 = & F_126 ( V_3 , V_177 ) ;
struct V_114 * V_96 ;
V_96 = V_4 -> V_115 ;
if ( V_96 ) {
if ( V_96 -> V_180 == - 1 || -- V_96 -> V_192 == 0 )
F_128 ( V_96 ) ;
V_4 -> V_115 = NULL ;
F_128 ( V_4 -> V_133 ) ;
V_4 -> V_133 = NULL ;
}
}
static void F_135 ( int V_177 )
{
struct V_3 * V_4 = & F_126 ( V_3 , V_177 ) ;
struct V_176 * V_191 ;
V_191 = V_4 -> V_102 ;
if ( V_191 ) {
if ( V_191 -> V_180 == - 1 || -- V_191 -> V_192 == 0 )
F_128 ( V_191 ) ;
V_4 -> V_102 = NULL ;
}
F_134 ( V_177 ) ;
F_136 ( V_177 ) ;
}
static T_4 void F_137 ( void )
{
F_138 ( L_3 ) ;
V_10 . V_194 = 0 ;
V_10 . V_195 = NULL ;
}
static int F_139 ( int V_177 )
{
T_5 V_196 = V_197 ;
switch ( F_140 ( V_177 ) . V_198 ) {
case 42 :
V_196 = 0x28 ;
break;
case 45 :
switch ( F_140 ( V_177 ) . V_199 ) {
case 6 : V_196 = 0x618 ; break;
case 7 : V_196 = 0x70c ; break;
}
}
return ( F_140 ( V_177 ) . V_200 < V_196 ) ;
}
static void F_141 ( void )
{
int V_201 = 0 ;
int V_177 ;
F_142 () ;
F_143 (cpu) {
if ( ( V_201 = F_139 ( V_177 ) ) )
break;
}
F_144 () ;
if ( V_201 == V_10 . V_201 )
return;
if ( V_10 . V_201 ) {
F_44 ( L_4 ) ;
V_10 . V_201 = 0 ;
} else {
F_44 ( L_5 ) ;
V_10 . V_201 = 1 ;
}
}
static bool F_145 ( unsigned long V_163 , T_1 V_32 )
{
T_1 V_202 , V_203 , V_204 ;
if ( F_146 ( V_163 , & V_202 ) )
return false ;
V_204 = V_202 ^ V_32 ;
if ( F_46 ( V_163 , V_204 ) ||
F_146 ( V_163 , & V_203 ) )
return false ;
if ( V_203 != V_204 )
return false ;
F_4 ( V_163 , V_202 ) ;
return true ;
}
static T_4 void F_147 ( void )
{
V_10 . V_205 = F_141 ;
F_141 () ;
}
static T_4 void F_148 ( void )
{
int V_65 ;
F_61 (bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
V_2 [ V_206 [ V_65 ] . V_207 ] = 0 ;
F_138 ( L_6 ,
V_206 [ V_65 ] . V_208 ) ;
}
}
static T_4 void F_149 ( void )
{
union V_209 V_210 ;
V_210 . V_211 = V_10 . V_212 ;
if ( V_210 . V_213 . V_214 ) {
V_2 [ V_215 ] = 0x7f89 ;
V_210 . V_213 . V_214 = 0 ;
V_10 . V_212 = V_210 . V_211 ;
F_44 ( L_7 ) ;
}
}
static T_4 void F_150 ( void )
{
V_10 . V_52 |= V_183 | V_216 ;
V_10 . V_217 = F_96 ;
V_10 . V_218 = F_81 ;
V_10 . V_219 = F_85 ;
}
T_4 int F_151 ( void )
{
union V_220 V_221 ;
union V_222 V_223 ;
union V_209 V_210 ;
struct V_79 * V_96 ;
unsigned int V_224 ;
struct V_90 * V_225 ;
int V_43 , V_19 ;
if ( ! F_152 ( & V_226 , V_227 ) ) {
switch ( V_226 . V_228 ) {
case 0x6 :
return F_153 () ;
case 0xb :
return F_154 () ;
case 0xf :
return F_155 () ;
}
return - V_229 ;
}
F_156 ( 10 , & V_223 . V_211 , & V_210 . V_211 , & V_224 , & V_221 . V_211 ) ;
if ( V_223 . V_213 . V_230 < V_231 )
return - V_229 ;
V_43 = V_223 . V_213 . V_232 ;
if ( V_43 < 2 )
V_10 = V_233 ;
else
V_10 = V_234 ;
V_10 . V_43 = V_43 ;
V_10 . V_53 = V_223 . V_213 . V_53 ;
V_10 . V_235 = V_223 . V_213 . V_236 ;
V_10 . V_237 = ( 1ULL << V_223 . V_213 . V_236 ) - 1 ;
V_10 . V_212 = V_210 . V_211 ;
V_10 . V_238 = V_223 . V_213 . V_230 ;
V_10 . V_239 = F_157 ( unsigned , V_240 , V_10 . V_53 ) ;
if ( V_43 > 1 )
V_10 . V_54 = F_158 ( ( int ) V_221 . V_213 . V_54 , 3 ) ;
if ( F_115 ( V_241 ) ) {
T_1 V_242 ;
F_24 ( V_243 , V_242 ) ;
V_10 . V_244 . V_242 = V_242 ;
}
F_159 () ;
F_160 ( F_148 ) ;
switch ( V_226 . V_198 ) {
case 14 :
F_161 ( L_8 ) ;
break;
case 15 :
F_160 ( F_137 ) ;
case 22 :
case 23 :
case 29 :
memcpy ( V_245 , V_246 ,
sizeof( V_245 ) ) ;
F_162 () ;
V_10 . V_110 = V_247 ;
V_10 . V_195 = V_248 ;
F_161 ( L_9 ) ;
break;
case 30 :
case 26 :
case 46 :
memcpy ( V_245 , V_249 ,
sizeof( V_245 ) ) ;
memcpy ( V_250 , V_251 ,
sizeof( V_250 ) ) ;
F_163 () ;
V_10 . V_110 = V_252 ;
V_10 . V_195 = V_253 ;
V_10 . V_254 = F_22 ;
V_10 . V_91 = V_255 ;
V_10 . V_256 = V_257 ;
V_2 [ V_258 ] =
F_99 ( . V_14 = 0x0e , . V_147 = 0x01 , . V_146 = 1 , . V_111 = 1 ) ;
V_2 [ V_259 ] =
F_99 ( . V_14 = 0xb1 , . V_147 = 0x3f , . V_146 = 1 , . V_111 = 1 ) ;
F_160 ( F_149 ) ;
F_161 ( L_10 ) ;
break;
case 28 :
case 38 :
case 39 :
case 53 :
case 54 :
memcpy ( V_245 , V_260 ,
sizeof( V_245 ) ) ;
F_164 () ;
V_10 . V_110 = V_261 ;
V_10 . V_195 = V_262 ;
F_161 ( L_11 ) ;
break;
case 55 :
case 76 :
case 77 :
memcpy ( V_245 , V_263 ,
sizeof( V_245 ) ) ;
memcpy ( V_250 , V_264 ,
sizeof( V_250 ) ) ;
F_164 () ;
V_10 . V_110 = V_265 ;
V_10 . V_195 = V_266 ;
V_10 . V_91 = V_267 ;
V_10 . V_52 |= V_87 ;
F_161 ( L_12 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_245 , V_268 ,
sizeof( V_245 ) ) ;
memcpy ( V_250 , V_251 ,
sizeof( V_250 ) ) ;
F_163 () ;
V_10 . V_110 = V_269 ;
V_10 . V_254 = F_22 ;
V_10 . V_195 = V_270 ;
V_10 . V_91 = V_271 ;
V_10 . V_52 |= V_87 ;
V_10 . V_256 = V_257 ;
V_2 [ V_258 ] =
F_99 ( . V_14 = 0x0e , . V_147 = 0x01 , . V_146 = 1 , . V_111 = 1 ) ;
V_2 [ V_259 ] =
F_99 ( . V_14 = 0xb1 , . V_147 = 0x3f , . V_146 = 1 , . V_111 = 1 ) ;
F_161 ( L_13 ) ;
break;
case 42 :
case 45 :
F_160 ( F_147 ) ;
F_160 ( F_150 ) ;
memcpy ( V_245 , V_272 ,
sizeof( V_245 ) ) ;
memcpy ( V_250 , V_273 ,
sizeof( V_250 ) ) ;
F_165 () ;
V_10 . V_110 = V_274 ;
V_10 . V_195 = V_275 ;
V_10 . V_149 = F_100 ;
if ( V_226 . V_198 == 45 )
V_10 . V_91 = V_276 ;
else
V_10 . V_91 = V_277 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_187 ;
V_10 . V_256 = V_278 ;
V_2 [ V_258 ] =
F_99 ( . V_14 = 0x0e , . V_147 = 0x01 , . V_146 = 1 , . V_111 = 1 ) ;
V_2 [ V_259 ] =
F_99 ( . V_14 = 0xb1 , . V_147 = 0x01 , . V_146 = 1 , . V_111 = 1 ) ;
F_161 ( L_14 ) ;
break;
case 58 :
case 62 :
F_160 ( F_150 ) ;
memcpy ( V_245 , V_272 ,
sizeof( V_245 ) ) ;
V_245 [ F_166 ( V_279 ) ] [ F_166 ( V_280 ) ] [ F_166 ( V_281 ) ] = 0x8108 ;
memcpy ( V_250 , V_273 ,
sizeof( V_250 ) ) ;
F_165 () ;
V_10 . V_110 = V_282 ;
V_10 . V_195 = V_283 ;
V_10 . V_149 = F_100 ;
if ( V_226 . V_198 == 62 )
V_10 . V_91 = V_276 ;
else
V_10 . V_91 = V_277 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_187 ;
V_10 . V_256 = V_278 ;
V_2 [ V_258 ] =
F_99 ( . V_14 = 0x0e , . V_147 = 0x01 , . V_146 = 1 , . V_111 = 1 ) ;
F_161 ( L_15 ) ;
break;
case 60 :
case 63 :
case 69 :
case 70 :
F_160 ( F_150 ) ;
V_10 . V_68 = true ;
memcpy ( V_245 , V_284 , sizeof( V_245 ) ) ;
memcpy ( V_250 , V_285 , sizeof( V_250 ) ) ;
F_167 () ;
V_10 . V_110 = V_286 ;
V_10 . V_195 = V_287 ;
V_10 . V_91 = V_276 ;
V_10 . V_149 = F_100 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_187 ;
V_10 . V_288 = F_114 ;
V_10 . V_289 = F_116 ;
V_10 . V_256 = V_290 ;
V_10 . V_291 = true ;
F_161 ( L_16 ) ;
break;
case 61 :
case 86 :
V_10 . V_68 = true ;
memcpy ( V_245 , V_284 , sizeof( V_245 ) ) ;
memcpy ( V_250 , V_285 , sizeof( V_250 ) ) ;
V_250 [ F_166 ( V_292 ) ] [ F_166 ( V_280 ) ] [ F_166 ( V_281 ) ] = V_293 |
V_294 | V_295 ;
V_250 [ F_166 ( V_292 ) ] [ F_166 ( V_296 ) ] [ F_166 ( V_281 ) ] = V_297 | V_294 |
V_295 ;
V_250 [ F_166 ( V_298 ) ] [ F_166 ( V_280 ) ] [ F_166 ( V_299 ) ] = V_293 |
V_300 | V_295 ;
V_250 [ F_166 ( V_298 ) ] [ F_166 ( V_296 ) ] [ F_166 ( V_299 ) ] = V_297 |
V_300 | V_295 ;
F_167 () ;
V_10 . V_110 = V_301 ;
V_10 . V_195 = V_287 ;
V_10 . V_91 = V_276 ;
V_10 . V_149 = F_100 ;
V_10 . V_52 |= V_87 ;
V_10 . V_52 |= V_187 ;
V_10 . V_288 = F_114 ;
V_10 . V_289 = F_116 ;
V_10 . V_256 = V_290 ;
V_10 . V_302 = F_117 ;
F_161 ( L_17 ) ;
break;
default:
switch ( V_10 . V_43 ) {
case 1 :
V_10 . V_110 = V_303 ;
F_161 ( L_18 ) ;
break;
default:
V_10 . V_110 = V_261 ;
F_161 ( L_19 ) ;
break;
}
}
if ( V_10 . V_53 > V_304 ) {
F_55 ( 1 , V_305 L_20 ,
V_10 . V_53 , V_304 ) ;
V_10 . V_53 = V_304 ;
}
V_10 . V_11 = ( 1 << V_10 . V_53 ) - 1 ;
if ( V_10 . V_54 > V_306 ) {
F_55 ( 1 , V_305 L_21 ,
V_10 . V_54 , V_306 ) ;
V_10 . V_54 = V_306 ;
}
V_10 . V_11 |=
( ( 1LL << V_10 . V_54 ) - 1 ) << V_30 ;
if ( V_10 . V_110 ) {
F_78 (c, x86_pmu.event_constraints) {
if ( V_96 -> V_111 != V_307
|| V_96 -> V_138 == V_308 ) {
continue;
}
V_96 -> V_138 |= ( 1ULL << V_10 . V_53 ) - 1 ;
V_96 -> V_137 += V_10 . V_53 ;
}
}
if ( V_10 . V_58 && ! F_145 ( V_10 . V_309 , 0x3UL ) )
V_10 . V_58 = 0 ;
for ( V_19 = 0 ; V_19 < V_10 . V_58 ; V_19 ++ ) {
if ( ! ( F_145 ( V_10 . V_310 + V_19 , 0xffffUL ) &&
F_145 ( V_10 . V_311 + V_19 , 0xffffUL ) ) )
V_10 . V_58 = 0 ;
}
if ( V_10 . V_91 ) {
for ( V_225 = V_10 . V_91 ; V_225 -> V_163 ; V_225 ++ ) {
V_225 -> V_312 = F_145 ( V_225 -> V_163 , 0x1ffUL ) ;
if ( ( V_225 -> V_29 == V_193 ) && ! V_225 -> V_312 )
V_10 . V_181 = NULL ;
}
}
if ( V_10 . V_244 . V_313 ) {
V_10 . V_314 = V_10 . V_237 ;
V_10 . V_315 = V_316 ;
F_161 ( L_22 ) ;
}
return 0 ;
}
static T_4 int F_168 ( void )
{
int V_177 = F_45 () ;
int V_317 , V_96 ;
if ( ! ( V_10 . V_52 & V_216 ) )
return 0 ;
V_317 = F_169 ( F_170 ( V_177 ) ) ;
if ( V_317 > 1 ) {
F_44 ( L_23 ) ;
return 0 ;
}
F_171 () ;
V_10 . V_52 &= ~ ( V_183 | V_216 ) ;
V_10 . V_217 = NULL ;
V_10 . V_218 = NULL ;
V_10 . V_219 = NULL ;
F_172 () ;
F_142 () ;
F_143 (c) {
F_134 ( V_96 ) ;
}
F_144 () ;
F_44 ( L_24 ) ;
return 0 ;
}
