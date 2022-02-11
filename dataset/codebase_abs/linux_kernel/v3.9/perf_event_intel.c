static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static inline bool F_2 ( struct V_3 * V_4 )
{
if ( F_3 ( V_4 ) )
return true ;
if ( V_5 . V_6 . V_7 && V_4 -> V_8 . V_9 > 1 )
return true ;
return false ;
}
static void F_4 ( void )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
F_6 ( V_12 , 0 ) ;
if ( F_7 ( V_13 , V_11 -> V_14 ) )
F_8 () ;
F_9 () ;
F_10 () ;
}
static void F_11 ( int V_15 )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
F_12 () ;
F_13 () ;
F_6 ( V_12 ,
V_5 . V_16 & ~ V_11 -> V_17 ) ;
if ( F_7 ( V_13 , V_11 -> V_14 ) ) {
struct V_3 * V_4 =
V_11 -> V_18 [ V_13 ] ;
if ( F_14 ( ! V_4 ) )
return;
F_15 ( V_4 -> V_19 . V_20 ) ;
}
}
static void F_16 ( void )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
static const unsigned long V_21 [ 4 ] = {
0x4300B5 ,
0x4300D2 ,
0x4300B1 ,
0x4300B1
} ;
struct V_3 * V_4 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
V_4 = V_11 -> V_18 [ V_22 ] ;
if ( V_4 )
F_17 ( V_4 ) ;
}
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
F_6 ( V_23 + V_22 , V_21 [ V_22 ] ) ;
F_6 ( V_24 + V_22 , 0x0 ) ;
}
F_6 ( V_12 , 0xf ) ;
F_6 ( V_12 , 0x0 ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
V_4 = V_11 -> V_18 [ V_22 ] ;
if ( V_4 ) {
F_18 ( V_4 ) ;
F_19 ( & V_4 -> V_19 ,
V_25 ) ;
} else
F_6 ( V_23 + V_22 , 0x0 ) ;
}
}
static void F_20 ( int V_15 )
{
if ( V_15 )
F_16 () ;
F_11 ( V_15 ) ;
}
static inline T_1 F_21 ( void )
{
T_1 V_26 ;
F_22 ( V_27 , V_26 ) ;
return V_26 ;
}
static inline void F_23 ( T_1 V_28 )
{
F_6 ( V_29 , V_28 ) ;
}
static void F_24 ( struct V_30 * V_31 )
{
int V_32 = V_31 -> V_32 - V_33 ;
T_1 V_34 , V_35 ;
V_35 = 0xfULL << ( V_32 * 4 ) ;
F_22 ( V_31 -> V_36 , V_34 ) ;
V_34 &= ~ V_35 ;
F_6 ( V_31 -> V_36 , V_34 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = & V_4 -> V_19 ;
struct V_10 * V_11 = & F_5 ( V_10 ) ;
if ( F_26 ( V_31 -> V_32 == V_13 ) ) {
F_8 () ;
F_27 () ;
return;
}
V_11 -> V_17 &= ~ ( 1ull << V_31 -> V_32 ) ;
V_11 -> V_37 &= ~ ( 1ull << V_31 -> V_32 ) ;
if ( F_2 ( V_4 ) )
F_28 ( V_4 ) ;
if ( F_26 ( V_31 -> V_36 == V_38 ) ) {
F_24 ( V_31 ) ;
return;
}
F_29 ( V_4 ) ;
if ( F_26 ( V_4 -> V_8 . V_9 ) )
F_30 ( V_4 ) ;
}
static void F_31 ( struct V_30 * V_31 )
{
int V_32 = V_31 -> V_32 - V_33 ;
T_1 V_34 , V_39 , V_35 ;
V_39 = 0x8ULL ;
if ( V_31 -> V_20 & V_40 )
V_39 |= 0x2 ;
if ( V_31 -> V_20 & V_41 )
V_39 |= 0x1 ;
if ( V_5 . V_42 > 2 && V_31 -> V_20 & V_43 )
V_39 |= 0x4 ;
V_39 <<= ( V_32 * 4 ) ;
V_35 = 0xfULL << ( V_32 * 4 ) ;
F_22 ( V_31 -> V_36 , V_34 ) ;
V_34 &= ~ V_35 ;
V_34 |= V_39 ;
F_6 ( V_31 -> V_36 , V_34 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = & V_4 -> V_19 ;
struct V_10 * V_11 = & F_5 ( V_10 ) ;
if ( F_26 ( V_31 -> V_32 == V_13 ) ) {
if ( ! F_33 ( V_10 . V_44 ) )
return;
F_15 ( V_31 -> V_20 ) ;
return;
}
if ( F_2 ( V_4 ) )
F_34 ( V_4 ) ;
if ( V_4 -> V_8 . V_45 )
V_11 -> V_17 |= ( 1ull << V_31 -> V_32 ) ;
if ( V_4 -> V_8 . V_46 )
V_11 -> V_37 |= ( 1ull << V_31 -> V_32 ) ;
if ( F_26 ( V_31 -> V_36 == V_38 ) ) {
F_31 ( V_31 ) ;
return;
}
if ( F_26 ( V_4 -> V_8 . V_9 ) )
F_35 ( V_4 ) ;
F_19 ( V_31 , V_25 ) ;
}
int F_36 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
return F_18 ( V_4 ) ;
}
static void F_37 ( void )
{
struct V_47 * V_48 = F_33 ( V_10 . V_48 ) ;
unsigned long V_49 ;
int V_32 ;
if ( ! V_5 . V_50 )
return;
F_38 ( V_49 ) ;
F_39 ( L_1 , F_40 () ) ;
for ( V_32 = 0 ; V_32 < V_5 . V_50 ; V_32 ++ ) {
F_41 ( F_42 ( V_32 ) , 0ull ) ;
F_41 ( F_43 ( V_32 ) , 0ull ) ;
}
for ( V_32 = 0 ; V_32 < V_5 . V_51 ; V_32 ++ )
F_41 ( V_52 + V_32 , 0ull ) ;
if ( V_48 )
V_48 -> V_53 = V_48 -> V_54 ;
F_44 ( V_49 ) ;
}
static int F_45 ( struct V_55 * V_56 )
{
struct V_57 V_58 ;
struct V_10 * V_11 ;
int V_59 , V_60 ;
T_1 V_26 ;
int V_61 ;
V_11 = & F_5 ( V_10 ) ;
F_46 ( V_62 , V_63 ) ;
F_4 () ;
V_61 = F_27 () ;
V_26 = F_21 () ;
if ( ! V_26 ) {
F_11 ( 0 ) ;
return V_61 ;
}
V_60 = 0 ;
V_64:
F_23 ( V_26 ) ;
if ( ++ V_60 > 100 ) {
F_47 ( 1 , L_2 ) ;
F_48 () ;
F_37 () ;
goto V_65;
}
F_49 ( V_66 ) ;
F_50 () ;
if ( F_51 ( 62 , ( unsigned long * ) & V_26 ) ) {
V_61 ++ ;
V_5 . V_67 ( V_56 ) ;
}
F_52 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_3 * V_4 = V_11 -> V_18 [ V_59 ] ;
V_61 ++ ;
if ( ! F_7 ( V_59 , V_11 -> V_14 ) )
continue;
if ( ! F_36 ( V_4 ) )
continue;
F_53 ( & V_58 , 0 , V_4 -> V_19 . V_68 ) ;
if ( F_3 ( V_4 ) )
V_58 . V_69 = & V_11 -> V_70 ;
if ( F_54 ( V_4 , & V_58 , V_56 ) )
F_55 ( V_4 , 0 ) ;
}
V_26 = F_21 () ;
if ( V_26 )
goto V_64;
V_65:
F_11 ( 0 ) ;
return V_61 ;
}
static struct V_71 *
F_56 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = & V_4 -> V_19 ;
unsigned int V_1 , V_72 ;
if ( V_4 -> V_8 . V_73 )
return NULL ;
V_1 = V_31 -> V_20 & V_74 ;
V_72 = V_5 . V_75 ( V_76 ) ;
if ( F_26 ( V_1 == V_72 && V_31 -> V_77 == 1 ) )
return & V_78 ;
return NULL ;
}
static int F_57 ( int V_32 )
{
if ( ! ( V_5 . V_79 & V_80 ) )
return V_32 ;
if ( V_32 == V_81 )
return V_82 ;
if ( V_32 == V_82 )
return V_81 ;
return V_32 ;
}
static void F_58 ( struct V_3 * V_4 , int V_32 )
{
V_4 -> V_19 . V_83 . V_32 = V_32 ;
if ( V_32 == V_81 ) {
V_4 -> V_19 . V_20 &= ~ V_74 ;
V_4 -> V_19 . V_20 |= 0x01b7 ;
V_4 -> V_19 . V_83 . V_84 = V_85 ;
} else if ( V_32 == V_82 ) {
V_4 -> V_19 . V_20 &= ~ V_74 ;
V_4 -> V_19 . V_20 |= 0x01bb ;
V_4 -> V_19 . V_83 . V_84 = V_86 ;
}
}
static struct V_71 *
F_59 ( struct V_10 * V_11 ,
struct V_3 * V_4 ,
struct V_87 * V_84 )
{
struct V_71 * V_88 = & V_89 ;
struct V_90 * V_91 ;
unsigned long V_49 ;
int V_32 = V_84 -> V_32 ;
if ( V_84 -> V_92 && ! V_11 -> V_93 )
return NULL ;
V_64:
V_91 = & V_11 -> V_94 -> V_56 [ V_32 ] ;
F_60 ( & V_91 -> V_95 , V_49 ) ;
if ( ! F_61 ( & V_91 -> V_96 ) || V_91 -> V_20 == V_84 -> V_20 ) {
if ( ! V_11 -> V_93 ) {
if ( V_32 != V_84 -> V_32 )
F_58 ( V_4 , V_32 ) ;
V_84 -> V_92 = 1 ;
}
V_91 -> V_20 = V_84 -> V_20 ;
V_91 -> V_84 = V_84 -> V_84 ;
F_62 ( & V_91 -> V_96 ) ;
V_88 = NULL ;
} else {
V_32 = F_57 ( V_32 ) ;
if ( V_32 != V_84 -> V_32 ) {
F_63 ( & V_91 -> V_95 , V_49 ) ;
goto V_64;
}
}
F_63 ( & V_91 -> V_95 , V_49 ) ;
return V_88 ;
}
static void
F_64 ( struct V_10 * V_11 ,
struct V_87 * V_84 )
{
struct V_90 * V_91 ;
if ( ! V_84 -> V_92 || V_11 -> V_93 )
return;
V_91 = & V_11 -> V_94 -> V_56 [ V_84 -> V_32 ] ;
F_65 ( & V_91 -> V_96 ) ;
V_84 -> V_92 = 0 ;
}
static struct V_71 *
F_66 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
struct V_71 * V_88 = NULL , * V_97 ;
struct V_87 * V_98 , * V_99 ;
V_98 = & V_4 -> V_19 . V_83 ;
if ( V_98 -> V_32 != V_100 ) {
V_88 = F_59 ( V_11 , V_4 , V_98 ) ;
if ( V_88 == & V_89 )
return V_88 ;
}
V_99 = & V_4 -> V_19 . V_101 ;
if ( V_99 -> V_32 != V_100 ) {
V_97 = F_59 ( V_11 , V_4 , V_99 ) ;
if ( V_97 == & V_89 ) {
F_64 ( V_11 , V_98 ) ;
V_88 = V_97 ;
}
}
return V_88 ;
}
struct V_71 *
F_67 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_71 * V_88 ;
if ( V_5 . V_102 ) {
F_68 (c, x86_pmu.event_constraints) {
if ( ( V_4 -> V_19 . V_20 & V_88 -> V_103 ) == V_88 -> V_104 )
return V_88 ;
}
}
return & V_105 ;
}
static struct V_71 *
F_69 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_71 * V_88 ;
V_88 = F_56 ( V_4 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_70 ( V_4 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_66 ( V_11 , V_4 ) ;
if ( V_88 )
return V_88 ;
return F_67 ( V_11 , V_4 ) ;
}
static void
F_71 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
struct V_87 * V_84 ;
V_84 = & V_4 -> V_19 . V_83 ;
if ( V_84 -> V_32 != V_100 )
F_64 ( V_11 , V_84 ) ;
V_84 = & V_4 -> V_19 . V_101 ;
if ( V_84 -> V_32 != V_100 )
F_64 ( V_11 , V_84 ) ;
}
static void F_72 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
F_71 ( V_11 , V_4 ) ;
}
static void F_73 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_19 . V_20 & V_106 ) == 0x003c ) {
T_1 V_107 = F_74 ( . V_4 = 0xc0 , . V_108 = 1 , . V_103 = 16 ) ;
V_107 |= ( V_4 -> V_19 . V_20 & ~ V_106 ) ;
V_4 -> V_19 . V_20 = V_107 ;
}
}
static void F_75 ( struct V_3 * V_4 )
{
if ( ( V_4 -> V_19 . V_20 & V_106 ) == 0x003c ) {
T_1 V_107 = F_74 ( . V_4 = 0xc2 , . V_109 = 0x01 , . V_108 = 1 , . V_103 = 16 ) ;
V_107 |= ( V_4 -> V_19 . V_20 & ~ V_106 ) ;
V_4 -> V_19 . V_20 = V_107 ;
}
}
static int F_76 ( struct V_3 * V_4 )
{
int V_110 = F_77 ( V_4 ) ;
if ( V_110 )
return V_110 ;
if ( V_4 -> V_8 . V_9 && V_5 . V_111 )
V_5 . V_111 ( V_4 ) ;
if ( F_2 ( V_4 ) ) {
V_110 = F_78 ( V_4 ) ;
if ( V_110 )
return V_110 ;
}
if ( V_4 -> V_8 . type != V_112 )
return 0 ;
if ( ! ( V_4 -> V_8 . V_20 & V_43 ) )
return 0 ;
if ( V_5 . V_42 < 3 )
return - V_113 ;
if ( F_79 () && ! F_80 ( V_114 ) )
return - V_115 ;
V_4 -> V_19 . V_20 |= V_43 ;
return 0 ;
}
struct V_116 * F_81 ( int * V_117 )
{
if ( V_5 . V_118 )
return V_5 . V_118 ( V_117 ) ;
* V_117 = 0 ;
return NULL ;
}
static struct V_116 * F_82 ( int * V_117 )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
struct V_116 * V_119 = V_11 -> V_120 ;
V_119 [ 0 ] . V_121 = V_12 ;
V_119 [ 0 ] . V_122 = V_5 . V_16 & ~ V_11 -> V_17 ;
V_119 [ 0 ] . V_123 = V_5 . V_16 & ~ V_11 -> V_37 ;
V_119 [ 1 ] . V_121 = V_124 ;
V_119 [ 1 ] . V_122 = V_11 -> V_125 ;
V_119 [ 1 ] . V_123 = 0 ;
* V_117 = 2 ;
return V_119 ;
}
static struct V_116 * F_83 ( int * V_117 )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
struct V_116 * V_119 = V_11 -> V_120 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_5 . V_50 ; V_32 ++ ) {
struct V_3 * V_4 = V_11 -> V_18 [ V_32 ] ;
V_119 [ V_32 ] . V_121 = F_42 ( V_32 ) ;
V_119 [ V_32 ] . V_122 = V_119 [ V_32 ] . V_123 = 0 ;
if ( ! F_7 ( V_32 , V_11 -> V_14 ) )
continue;
V_119 [ V_32 ] . V_122 = V_119 [ V_32 ] . V_123 =
V_4 -> V_19 . V_20 | V_25 ;
if ( V_4 -> V_8 . V_45 )
V_119 [ V_32 ] . V_122 &= ~ V_25 ;
else if ( V_4 -> V_8 . V_46 )
V_119 [ V_32 ] . V_123 &= ~ V_25 ;
}
* V_117 = V_5 . V_50 ;
return V_119 ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_8 . V_45 )
F_85 ( V_4 ) ;
}
static void F_86 ( int V_15 )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_5 . V_50 ; V_32 ++ ) {
struct V_30 * V_31 = & V_11 -> V_18 [ V_32 ] -> V_19 ;
if ( ! F_7 ( V_32 , V_11 -> V_14 ) ||
V_11 -> V_18 [ V_32 ] -> V_8 . V_45 )
continue;
F_19 ( V_31 , V_25 ) ;
}
}
T_2 F_87 ( char * V_126 , T_1 V_20 )
{
T_1 V_4 = ( V_20 & V_127 ) ;
return F_88 ( V_126 , V_20 , V_4 ) ;
}
struct V_128 * F_89 ( int V_129 )
{
struct V_128 * V_56 ;
int V_22 ;
V_56 = F_90 ( sizeof( struct V_128 ) ,
V_130 , F_91 ( V_129 ) ) ;
if ( V_56 ) {
for ( V_22 = 0 ; V_22 < V_131 ; V_22 ++ )
F_92 ( & V_56 -> V_56 [ V_22 ] . V_95 ) ;
V_56 -> V_132 = - 1 ;
}
return V_56 ;
}
static int F_93 ( int V_129 )
{
struct V_10 * V_11 = & F_94 ( V_10 , V_129 ) ;
if ( ! ( V_5 . V_133 || V_5 . V_134 ) )
return V_135 ;
V_11 -> V_94 = F_89 ( V_129 ) ;
if ( ! V_11 -> V_94 )
return V_136 ;
return V_135 ;
}
static void F_95 ( int V_129 )
{
struct V_10 * V_11 = & F_94 ( V_10 , V_129 ) ;
int V_132 = F_96 ( V_129 ) ;
int V_22 ;
F_97 ( V_129 ) ;
F_98 () ;
V_11 -> V_137 = NULL ;
if ( ! V_11 -> V_94 )
return;
if ( ! ( V_5 . V_79 & V_138 ) ) {
F_99 (i, topology_thread_cpumask(cpu)) {
struct V_128 * V_139 ;
V_139 = F_94 ( V_10 , V_22 ) . V_94 ;
if ( V_139 && V_139 -> V_132 == V_132 ) {
V_11 -> V_140 = V_11 -> V_94 ;
V_11 -> V_94 = V_139 ;
break;
}
}
V_11 -> V_94 -> V_132 = V_132 ;
V_11 -> V_94 -> V_141 ++ ;
}
if ( V_5 . V_134 )
V_11 -> V_137 = & V_11 -> V_94 -> V_56 [ V_142 ] ;
}
static void F_100 ( int V_129 )
{
struct V_10 * V_11 = & F_94 ( V_10 , V_129 ) ;
struct V_128 * V_139 ;
V_139 = V_11 -> V_94 ;
if ( V_139 ) {
if ( V_139 -> V_132 == - 1 || -- V_139 -> V_141 == 0 )
F_101 ( V_139 ) ;
V_11 -> V_94 = NULL ;
}
F_102 ( V_129 ) ;
}
static void F_103 ( void )
{
if ( V_5 . V_143 )
F_98 () ;
}
static T_3 void F_104 ( void )
{
F_105 ( L_3 ) ;
V_5 . V_144 = 0 ;
V_5 . V_145 = NULL ;
}
static int F_106 ( int V_129 )
{
T_4 V_146 = V_147 ;
switch ( F_107 ( V_129 ) . V_148 ) {
case 42 :
V_146 = 0x28 ;
break;
case 45 :
switch ( F_107 ( V_129 ) . V_149 ) {
case 6 : V_146 = 0x618 ; break;
case 7 : V_146 = 0x70c ; break;
}
}
return ( F_107 ( V_129 ) . V_150 < V_146 ) ;
}
static void F_108 ( void )
{
int V_151 = 0 ;
int V_129 ;
F_109 () ;
F_110 (cpu) {
if ( ( V_151 = F_106 ( V_129 ) ) )
break;
}
F_111 () ;
if ( V_151 == V_5 . V_151 )
return;
if ( V_5 . V_151 ) {
F_39 ( L_4 ) ;
V_5 . V_151 = 0 ;
} else {
F_39 ( L_5 ) ;
V_5 . V_151 = 1 ;
}
}
static T_3 void F_112 ( void )
{
V_5 . V_152 = F_108 ;
F_108 () ;
}
static T_3 void F_113 ( void )
{
int V_59 ;
F_52 (bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
V_2 [ V_153 [ V_59 ] . V_154 ] = 0 ;
F_105 ( L_6 ,
V_153 [ V_59 ] . V_155 ) ;
}
}
static T_3 void F_114 ( void )
{
union V_156 V_157 ;
V_157 . V_158 = V_5 . V_159 ;
if ( V_157 . V_160 . V_161 ) {
V_2 [ V_162 ] = 0x7f89 ;
V_157 . V_160 . V_161 = 0 ;
V_5 . V_159 = V_157 . V_158 ;
F_39 ( L_7 ) ;
}
}
T_3 int F_115 ( void )
{
union V_163 V_164 ;
union V_165 V_166 ;
union V_156 V_157 ;
struct V_71 * V_88 ;
unsigned int V_167 ;
int V_42 ;
if ( ! F_116 ( & V_168 , V_169 ) ) {
switch ( V_168 . V_170 ) {
case 0x6 :
return F_117 () ;
case 0xb :
return F_118 () ;
case 0xf :
return F_119 () ;
}
return - V_171 ;
}
F_120 ( 10 , & V_166 . V_158 , & V_157 . V_158 , & V_167 , & V_164 . V_158 ) ;
if ( V_166 . V_160 . V_172 < V_173 )
return - V_171 ;
V_42 = V_166 . V_160 . V_174 ;
if ( V_42 < 2 )
V_5 = V_175 ;
else
V_5 = V_176 ;
V_5 . V_42 = V_42 ;
V_5 . V_50 = V_166 . V_160 . V_50 ;
V_5 . V_177 = V_166 . V_160 . V_178 ;
V_5 . V_179 = ( 1ULL << V_166 . V_160 . V_178 ) - 1 ;
V_5 . V_159 = V_157 . V_158 ;
V_5 . V_180 = V_166 . V_160 . V_172 ;
V_5 . V_181 = F_121 ( unsigned , V_182 , V_5 . V_50 ) ;
if ( V_42 > 1 )
V_5 . V_51 = F_122 ( ( int ) V_164 . V_160 . V_51 , 3 ) ;
if ( V_42 > 1 ) {
T_1 V_183 ;
F_22 ( V_184 , V_183 ) ;
V_5 . V_6 . V_183 = V_183 ;
}
F_123 () ;
F_124 ( F_113 ) ;
switch ( V_168 . V_148 ) {
case 14 :
F_125 ( L_8 ) ;
break;
case 15 :
F_124 ( F_104 ) ;
case 22 :
case 23 :
case 29 :
memcpy ( V_185 , V_186 ,
sizeof( V_185 ) ) ;
F_126 () ;
V_5 . V_102 = V_187 ;
V_5 . V_145 = V_188 ;
F_125 ( L_9 ) ;
break;
case 26 :
case 30 :
case 46 :
memcpy ( V_185 , V_189 ,
sizeof( V_185 ) ) ;
memcpy ( V_190 , V_191 ,
sizeof( V_190 ) ) ;
F_127 () ;
V_5 . V_102 = V_192 ;
V_5 . V_145 = V_193 ;
V_5 . V_194 = F_20 ;
V_5 . V_133 = V_195 ;
V_2 [ V_196 ] =
F_74 ( . V_4 = 0x0e , . V_109 = 0x01 , . V_108 = 1 , . V_103 = 1 ) ;
V_2 [ V_197 ] =
F_74 ( . V_4 = 0xb1 , . V_109 = 0x3f , . V_108 = 1 , . V_103 = 1 ) ;
F_124 ( F_114 ) ;
F_125 ( L_10 ) ;
break;
case 28 :
case 38 :
case 39 :
case 53 :
case 54 :
memcpy ( V_185 , V_198 ,
sizeof( V_185 ) ) ;
F_128 () ;
V_5 . V_102 = V_199 ;
V_5 . V_145 = V_200 ;
F_125 ( L_11 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_185 , V_201 ,
sizeof( V_185 ) ) ;
memcpy ( V_190 , V_191 ,
sizeof( V_190 ) ) ;
F_127 () ;
V_5 . V_102 = V_202 ;
V_5 . V_194 = F_20 ;
V_5 . V_145 = V_203 ;
V_5 . V_133 = V_204 ;
V_5 . V_79 |= V_80 ;
V_2 [ V_196 ] =
F_74 ( . V_4 = 0x0e , . V_109 = 0x01 , . V_108 = 1 , . V_103 = 1 ) ;
V_2 [ V_197 ] =
F_74 ( . V_4 = 0xb1 , . V_109 = 0x3f , . V_108 = 1 , . V_103 = 1 ) ;
F_125 ( L_12 ) ;
break;
case 42 :
case 45 :
F_124 ( F_112 ) ;
memcpy ( V_185 , V_205 ,
sizeof( V_185 ) ) ;
memcpy ( V_190 , V_206 ,
sizeof( V_190 ) ) ;
F_129 () ;
V_5 . V_102 = V_207 ;
V_5 . V_145 = V_208 ;
V_5 . V_111 = F_75 ;
if ( V_168 . V_148 == 45 )
V_5 . V_133 = V_209 ;
else
V_5 . V_133 = V_210 ;
V_5 . V_79 |= V_80 ;
V_5 . V_79 |= V_138 ;
V_2 [ V_196 ] =
F_74 ( . V_4 = 0x0e , . V_109 = 0x01 , . V_108 = 1 , . V_103 = 1 ) ;
V_2 [ V_197 ] =
F_74 ( . V_4 = 0xb1 , . V_109 = 0x01 , . V_108 = 1 , . V_103 = 1 ) ;
F_125 ( L_13 ) ;
break;
case 58 :
case 62 :
memcpy ( V_185 , V_205 ,
sizeof( V_185 ) ) ;
memcpy ( V_190 , V_206 ,
sizeof( V_190 ) ) ;
F_129 () ;
V_5 . V_102 = V_211 ;
V_5 . V_145 = V_212 ;
V_5 . V_111 = F_75 ;
if ( V_168 . V_148 == 62 )
V_5 . V_133 = V_209 ;
else
V_5 . V_133 = V_210 ;
V_5 . V_79 |= V_80 ;
V_5 . V_79 |= V_138 ;
V_2 [ V_196 ] =
F_74 ( . V_4 = 0x0e , . V_109 = 0x01 , . V_108 = 1 , . V_103 = 1 ) ;
F_125 ( L_14 ) ;
break;
default:
switch ( V_5 . V_42 ) {
case 1 :
V_5 . V_102 = V_213 ;
F_125 ( L_15 ) ;
break;
default:
V_5 . V_102 = V_199 ;
F_125 ( L_16 ) ;
break;
}
}
if ( V_5 . V_50 > V_214 ) {
F_130 ( 1 , V_215 L_17 ,
V_5 . V_50 , V_214 ) ;
V_5 . V_50 = V_214 ;
}
V_5 . V_16 = ( 1 << V_5 . V_50 ) - 1 ;
if ( V_5 . V_51 > V_216 ) {
F_130 ( 1 , V_215 L_18 ,
V_5 . V_51 , V_216 ) ;
V_5 . V_51 = V_216 ;
}
V_5 . V_16 |=
( ( 1LL << V_5 . V_51 ) - 1 ) << V_33 ;
if ( V_5 . V_102 ) {
F_68 (c, x86_pmu.event_constraints) {
if ( V_88 -> V_103 != V_106
|| V_88 -> V_217 == V_218 ) {
continue;
}
V_88 -> V_217 |= ( 1ULL << V_5 . V_50 ) - 1 ;
V_88 -> V_219 += V_5 . V_50 ;
}
}
return 0 ;
}
