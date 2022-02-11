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
F_46 ( & V_58 , 0 ) ;
V_11 = & F_5 ( V_10 ) ;
F_47 ( V_62 , V_63 ) ;
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
F_48 ( 1 , L_2 ) ;
F_49 () ;
F_37 () ;
goto V_65;
}
F_50 ( V_66 ) ;
F_51 () ;
if ( F_52 ( 62 , ( unsigned long * ) & V_26 ) ) {
V_61 ++ ;
V_5 . V_67 ( V_56 ) ;
}
F_53 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_3 * V_4 = V_11 -> V_18 [ V_59 ] ;
V_61 ++ ;
if ( ! F_7 ( V_59 , V_11 -> V_14 ) )
continue;
if ( ! F_36 ( V_4 ) )
continue;
V_58 . V_68 = V_4 -> V_19 . V_69 ;
if ( F_3 ( V_4 ) )
V_58 . V_70 = & V_11 -> V_71 ;
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
static struct V_72 *
F_56 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = & V_4 -> V_19 ;
unsigned int V_1 , V_73 ;
if ( V_4 -> V_8 . V_74 )
return NULL ;
V_1 = V_31 -> V_20 & V_75 ;
V_73 = V_5 . V_76 ( V_77 ) ;
if ( F_26 ( V_1 == V_73 && V_31 -> V_78 == 1 ) )
return & V_79 ;
return NULL ;
}
static bool F_57 ( struct V_3 * V_4 , int V_80 )
{
if ( ! ( V_5 . V_81 & V_82 ) )
return false ;
if ( V_4 -> V_19 . V_83 . V_32 == V_84 ) {
V_4 -> V_19 . V_20 &= ~ V_75 ;
V_4 -> V_19 . V_20 |= 0x01bb ;
V_4 -> V_19 . V_83 . V_32 = V_85 ;
V_4 -> V_19 . V_83 . V_86 = V_87 ;
} else if ( V_4 -> V_19 . V_83 . V_32 == V_85 ) {
V_4 -> V_19 . V_20 &= ~ V_75 ;
V_4 -> V_19 . V_20 |= 0x01b7 ;
V_4 -> V_19 . V_83 . V_32 = V_84 ;
V_4 -> V_19 . V_83 . V_86 = V_88 ;
}
if ( V_4 -> V_19 . V_83 . V_32 == V_80 )
return false ;
return true ;
}
static struct V_72 *
F_58 ( struct V_10 * V_11 ,
struct V_3 * V_4 ,
struct V_89 * V_86 )
{
struct V_72 * V_90 = & V_91 ;
struct V_92 * V_93 ;
unsigned long V_49 ;
int V_80 = V_86 -> V_32 ;
if ( V_86 -> V_94 )
return NULL ;
V_64:
V_93 = & V_11 -> V_95 -> V_56 [ V_86 -> V_32 ] ;
F_59 ( & V_93 -> V_96 , V_49 ) ;
if ( ! F_60 ( & V_93 -> V_97 ) || V_93 -> V_20 == V_86 -> V_20 ) {
V_93 -> V_20 = V_86 -> V_20 ;
V_93 -> V_86 = V_86 -> V_86 ;
F_61 ( & V_93 -> V_97 ) ;
V_86 -> V_94 = 1 ;
V_90 = NULL ;
} else if ( F_57 ( V_4 , V_80 ) ) {
F_62 ( & V_93 -> V_96 , V_49 ) ;
goto V_64;
}
F_62 ( & V_93 -> V_96 , V_49 ) ;
return V_90 ;
}
static void
F_63 ( struct V_10 * V_11 ,
struct V_89 * V_86 )
{
struct V_92 * V_93 ;
if ( ! V_86 -> V_94 )
return;
V_93 = & V_11 -> V_95 -> V_56 [ V_86 -> V_32 ] ;
F_64 ( & V_93 -> V_97 ) ;
V_86 -> V_94 = 0 ;
}
static struct V_72 *
F_65 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
struct V_72 * V_90 = NULL , * V_98 ;
struct V_89 * V_99 , * V_100 ;
V_99 = & V_4 -> V_19 . V_83 ;
if ( V_99 -> V_32 != V_101 ) {
V_90 = F_58 ( V_11 , V_4 , V_99 ) ;
if ( V_90 == & V_91 )
return V_90 ;
}
V_100 = & V_4 -> V_19 . V_102 ;
if ( V_100 -> V_32 != V_101 ) {
V_98 = F_58 ( V_11 , V_4 , V_100 ) ;
if ( V_98 == & V_91 ) {
F_63 ( V_11 , V_99 ) ;
V_90 = V_98 ;
}
}
return V_90 ;
}
struct V_72 *
F_66 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_72 * V_90 ;
if ( V_5 . V_103 ) {
F_67 (c, x86_pmu.event_constraints) {
if ( ( V_4 -> V_19 . V_20 & V_90 -> V_104 ) == V_90 -> V_105 )
return V_90 ;
}
}
return & V_106 ;
}
static struct V_72 *
F_68 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_72 * V_90 ;
V_90 = F_56 ( V_4 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_69 ( V_4 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_65 ( V_11 , V_4 ) ;
if ( V_90 )
return V_90 ;
return F_66 ( V_11 , V_4 ) ;
}
static void
F_70 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
struct V_89 * V_86 ;
V_86 = & V_4 -> V_19 . V_83 ;
if ( V_86 -> V_32 != V_101 )
F_63 ( V_11 , V_86 ) ;
V_86 = & V_4 -> V_19 . V_102 ;
if ( V_86 -> V_32 != V_101 )
F_63 ( V_11 , V_86 ) ;
}
static void F_71 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
F_70 ( V_11 , V_4 ) ;
}
static int F_72 ( struct V_3 * V_4 )
{
int V_107 = F_73 ( V_4 ) ;
if ( V_107 )
return V_107 ;
if ( V_4 -> V_8 . V_9 &&
( V_4 -> V_19 . V_20 & V_108 ) == 0x003c ) {
T_1 V_109 = F_74 ( . V_4 = 0xc0 , . V_110 = 1 , . V_104 = 16 ) ;
V_109 |= ( V_4 -> V_19 . V_20 & ~ V_108 ) ;
V_4 -> V_19 . V_20 = V_109 ;
}
if ( F_2 ( V_4 ) ) {
V_107 = F_75 ( V_4 ) ;
if ( V_107 )
return V_107 ;
}
if ( V_4 -> V_8 . type != V_111 )
return 0 ;
if ( ! ( V_4 -> V_8 . V_20 & V_43 ) )
return 0 ;
if ( V_5 . V_42 < 3 )
return - V_112 ;
if ( F_76 () && ! F_77 ( V_113 ) )
return - V_114 ;
V_4 -> V_19 . V_20 |= V_43 ;
return 0 ;
}
struct V_115 * F_78 ( int * V_116 )
{
if ( V_5 . V_117 )
return V_5 . V_117 ( V_116 ) ;
* V_116 = 0 ;
return NULL ;
}
static struct V_115 * F_79 ( int * V_116 )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
struct V_115 * V_118 = V_11 -> V_119 ;
V_118 [ 0 ] . V_120 = V_12 ;
V_118 [ 0 ] . V_121 = V_5 . V_16 & ~ V_11 -> V_17 ;
V_118 [ 0 ] . V_122 = V_5 . V_16 & ~ V_11 -> V_37 ;
* V_116 = 1 ;
return V_118 ;
}
static struct V_115 * F_80 ( int * V_116 )
{
struct V_10 * V_11 = & F_5 ( V_10 ) ;
struct V_115 * V_118 = V_11 -> V_119 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_5 . V_50 ; V_32 ++ ) {
struct V_3 * V_4 = V_11 -> V_18 [ V_32 ] ;
V_118 [ V_32 ] . V_120 = F_42 ( V_32 ) ;
V_118 [ V_32 ] . V_121 = V_118 [ V_32 ] . V_122 = 0 ;
if ( ! F_7 ( V_32 , V_11 -> V_14 ) )
continue;
V_118 [ V_32 ] . V_121 = V_118 [ V_32 ] . V_122 =
V_4 -> V_19 . V_20 | V_25 ;
if ( V_4 -> V_8 . V_45 )
V_118 [ V_32 ] . V_121 &= ~ V_25 ;
else if ( V_4 -> V_8 . V_46 )
V_118 [ V_32 ] . V_122 &= ~ V_25 ;
}
* V_116 = V_5 . V_50 ;
return V_118 ;
}
static void F_81 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_8 . V_45 )
F_82 ( V_4 ) ;
}
static void F_83 ( int V_15 )
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
struct V_123 * F_84 ( int V_124 )
{
struct V_123 * V_56 ;
int V_22 ;
V_56 = F_85 ( sizeof( struct V_123 ) ,
V_125 , F_86 ( V_124 ) ) ;
if ( V_56 ) {
for ( V_22 = 0 ; V_22 < V_126 ; V_22 ++ )
F_87 ( & V_56 -> V_56 [ V_22 ] . V_96 ) ;
V_56 -> V_127 = - 1 ;
}
return V_56 ;
}
static int F_88 ( int V_124 )
{
struct V_10 * V_11 = & F_89 ( V_10 , V_124 ) ;
if ( ! ( V_5 . V_128 || V_5 . V_129 ) )
return V_130 ;
V_11 -> V_95 = F_84 ( V_124 ) ;
if ( ! V_11 -> V_95 )
return V_131 ;
return V_130 ;
}
static void F_90 ( int V_124 )
{
struct V_10 * V_11 = & F_89 ( V_10 , V_124 ) ;
int V_127 = F_91 ( V_124 ) ;
int V_22 ;
F_92 ( V_124 ) ;
F_93 () ;
V_11 -> V_132 = NULL ;
if ( ! V_11 -> V_95 )
return;
if ( ! ( V_5 . V_81 & V_133 ) ) {
F_94 (i, topology_thread_cpumask(cpu)) {
struct V_123 * V_134 ;
V_134 = F_89 ( V_10 , V_22 ) . V_95 ;
if ( V_134 && V_134 -> V_127 == V_127 ) {
V_11 -> V_135 = V_11 -> V_95 ;
V_11 -> V_95 = V_134 ;
break;
}
}
V_11 -> V_95 -> V_127 = V_127 ;
V_11 -> V_95 -> V_136 ++ ;
}
if ( V_5 . V_129 )
V_11 -> V_132 = & V_11 -> V_95 -> V_56 [ V_137 ] ;
}
static void F_95 ( int V_124 )
{
struct V_10 * V_11 = & F_89 ( V_10 , V_124 ) ;
struct V_123 * V_134 ;
V_134 = V_11 -> V_95 ;
if ( V_134 ) {
if ( V_134 -> V_127 == - 1 || -- V_134 -> V_136 == 0 )
F_96 ( V_134 ) ;
V_11 -> V_95 = NULL ;
}
F_97 ( V_124 ) ;
}
static void F_98 ( void )
{
if ( V_5 . V_138 )
F_93 () ;
}
static T_2 void F_99 ( void )
{
F_39 ( V_139 L_3 ) ;
V_5 . V_140 = 0 ;
V_5 . V_141 = NULL ;
}
static T_2 void F_100 ( void )
{
F_39 ( V_139 L_3 ) ;
V_5 . V_140 = 0 ;
V_5 . V_141 = NULL ;
}
static T_2 void F_101 ( void )
{
int V_59 ;
F_53 (bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
V_2 [ V_142 [ V_59 ] . V_143 ] = 0 ;
F_39 ( V_139 L_4 ,
V_142 [ V_59 ] . V_144 ) ;
}
}
static T_2 void F_102 ( void )
{
union V_145 V_146 ;
V_146 . V_147 = V_5 . V_148 ;
if ( V_146 . V_149 . V_150 ) {
V_2 [ V_151 ] = 0x7f89 ;
V_146 . V_149 . V_150 = 0 ;
V_5 . V_148 = V_146 . V_147 ;
F_39 ( V_152 L_5 ) ;
}
}
T_2 int F_103 ( void )
{
union V_153 V_154 ;
union V_155 V_156 ;
union V_145 V_146 ;
unsigned int V_157 ;
int V_42 ;
if ( ! F_104 ( & V_158 , V_159 ) ) {
switch ( V_158 . V_160 ) {
case 0x6 :
return F_105 () ;
case 0xf :
return F_106 () ;
}
return - V_161 ;
}
F_107 ( 10 , & V_156 . V_147 , & V_146 . V_147 , & V_157 , & V_154 . V_147 ) ;
if ( V_156 . V_149 . V_162 < V_163 )
return - V_161 ;
V_42 = V_156 . V_149 . V_164 ;
if ( V_42 < 2 )
V_5 = V_165 ;
else
V_5 = V_166 ;
V_5 . V_42 = V_42 ;
V_5 . V_50 = V_156 . V_149 . V_50 ;
V_5 . V_167 = V_156 . V_149 . V_168 ;
V_5 . V_169 = ( 1ULL << V_156 . V_149 . V_168 ) - 1 ;
V_5 . V_148 = V_146 . V_147 ;
V_5 . V_170 = V_156 . V_149 . V_162 ;
if ( V_42 > 1 )
V_5 . V_51 = F_108 ( ( int ) V_154 . V_149 . V_51 , 3 ) ;
if ( V_42 > 1 ) {
T_1 V_171 ;
F_22 ( V_172 , V_171 ) ;
V_5 . V_6 . V_171 = V_171 ;
}
F_109 () ;
F_110 ( F_101 ) ;
switch ( V_158 . V_173 ) {
case 14 :
F_111 ( L_6 ) ;
break;
case 15 :
F_110 ( F_99 ) ;
case 22 :
case 23 :
case 29 :
memcpy ( V_174 , V_175 ,
sizeof( V_174 ) ) ;
F_112 () ;
V_5 . V_103 = V_176 ;
V_5 . V_141 = V_177 ;
F_111 ( L_7 ) ;
break;
case 26 :
case 30 :
case 46 :
memcpy ( V_174 , V_178 ,
sizeof( V_174 ) ) ;
memcpy ( V_179 , V_180 ,
sizeof( V_179 ) ) ;
F_113 () ;
V_5 . V_103 = V_181 ;
V_5 . V_141 = V_182 ;
V_5 . V_183 = F_20 ;
V_5 . V_128 = V_184 ;
V_2 [ V_185 ] =
F_74 ( . V_4 = 0x0e , . V_186 = 0x01 , . V_110 = 1 , . V_104 = 1 ) ;
V_2 [ V_187 ] =
F_74 ( . V_4 = 0xb1 , . V_186 = 0x3f , . V_110 = 1 , . V_104 = 1 ) ;
F_110 ( F_102 ) ;
F_111 ( L_8 ) ;
break;
case 28 :
memcpy ( V_174 , V_188 ,
sizeof( V_174 ) ) ;
F_114 () ;
V_5 . V_103 = V_189 ;
V_5 . V_141 = V_190 ;
F_111 ( L_9 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_174 , V_191 ,
sizeof( V_174 ) ) ;
memcpy ( V_179 , V_180 ,
sizeof( V_179 ) ) ;
F_113 () ;
V_5 . V_103 = V_192 ;
V_5 . V_183 = F_20 ;
V_5 . V_141 = V_193 ;
V_5 . V_128 = V_194 ;
V_5 . V_81 |= V_82 ;
V_2 [ V_185 ] =
F_74 ( . V_4 = 0x0e , . V_186 = 0x01 , . V_110 = 1 , . V_104 = 1 ) ;
V_2 [ V_187 ] =
F_74 ( . V_4 = 0xb1 , . V_186 = 0x3f , . V_110 = 1 , . V_104 = 1 ) ;
F_111 ( L_10 ) ;
break;
case 42 :
F_110 ( F_100 ) ;
case 45 :
memcpy ( V_174 , V_195 ,
sizeof( V_174 ) ) ;
F_115 () ;
V_5 . V_103 = V_196 ;
V_5 . V_141 = V_197 ;
V_5 . V_128 = V_198 ;
V_5 . V_81 |= V_82 ;
V_5 . V_81 |= V_133 ;
V_2 [ V_185 ] =
F_74 ( . V_4 = 0x0e , . V_186 = 0x01 , . V_110 = 1 , . V_104 = 1 ) ;
V_2 [ V_187 ] =
F_74 ( . V_4 = 0xb1 , . V_186 = 0x01 , . V_110 = 1 , . V_104 = 1 ) ;
F_111 ( L_11 ) ;
break;
default:
switch ( V_5 . V_42 ) {
case 1 :
V_5 . V_103 = V_199 ;
F_111 ( L_12 ) ;
break;
default:
V_5 . V_103 = V_189 ;
F_111 ( L_13 ) ;
break;
}
}
return 0 ;
}
