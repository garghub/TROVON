static T_1 F_1 ( T_1 V_1 )
{
union V_2 V_3 ;
T_1 V_4 = F_2 ( V_5 , V_6 ) | F_2 ( V_7 , V_8 ) | F_2 ( V_9 , V_10 ) | F_2 ( V_11 , V_12 ) ;
V_3 . V_4 = V_1 ;
if ( V_3 . V_13 )
V_4 |= F_2 ( V_11 , V_14 ) ;
else
V_4 |= F_2 ( V_11 , V_15 ) ;
if ( V_3 . V_16 )
V_4 |= F_2 ( V_9 , V_15 ) ;
else
V_4 |= F_2 ( V_9 , V_14 ) ;
if ( V_3 . V_17 )
V_4 |= F_2 ( V_18 , V_19 ) ;
return V_4 ;
}
static T_1 F_3 ( T_1 V_1 )
{
union V_2 V_3 ;
T_1 V_4 ;
int V_20 = V_21 . V_22 ;
int V_23 = V_21 . V_24 ;
V_3 . V_4 = V_1 ;
V_4 = V_25 [ V_3 . V_26 ] ;
if ( V_23 == 0x6 && ( V_20 == 26 || V_20 == 30
|| V_20 == 31 || V_20 == 46 ) ) {
V_4 |= F_2 ( V_11 , V_8 ) | F_2 ( V_18 , V_8 ) ;
return V_4 ;
}
if ( V_3 . V_27 )
V_4 |= F_2 ( V_11 , V_14 ) | F_2 ( V_11 , V_12 ) ;
else
V_4 |= F_2 ( V_11 , V_15 ) | F_2 ( V_11 , V_10 ) | F_2 ( V_11 , V_12 ) ;
if ( V_3 . V_28 )
V_4 |= F_2 ( V_18 , V_19 ) ;
return V_4 ;
}
void F_4 ( int V_29 )
{
struct V_30 * V_31 = F_5 ( V_32 , V_29 ) . V_31 ;
if ( ! V_31 )
return;
F_6 ( V_29 , V_33 ,
( V_34 ) ( ( T_1 ) ( unsigned long ) V_31 ) ,
( V_34 ) ( ( T_1 ) ( unsigned long ) V_31 >> 32 ) ) ;
}
void F_7 ( int V_29 )
{
if ( ! F_5 ( V_32 , V_29 ) . V_31 )
return;
F_6 ( V_29 , V_33 , 0 , 0 ) ;
}
static int F_8 ( int V_29 )
{
struct V_30 * V_31 = F_5 ( V_32 , V_29 ) . V_31 ;
int V_35 = F_9 ( V_29 ) ;
int V_36 , V_37 = 1 ;
void * V_38 ;
if ( ! V_39 . V_40 )
return 0 ;
V_38 = F_10 ( V_41 , V_42 | V_43 , V_35 ) ;
if ( F_11 ( ! V_38 ) )
return - V_44 ;
V_36 = V_41 / V_39 . V_45 ;
V_31 -> V_46 = ( T_1 ) ( unsigned long ) V_38 ;
V_31 -> V_47 = V_31 -> V_46 ;
V_31 -> V_48 = V_31 -> V_46 +
V_36 * V_39 . V_45 ;
V_31 -> V_49 = V_31 -> V_46 +
V_37 * V_39 . V_45 ;
return 0 ;
}
static void F_12 ( int V_29 )
{
struct V_30 * V_31 = F_5 ( V_32 , V_29 ) . V_31 ;
if ( ! V_31 || ! V_39 . V_40 )
return;
F_13 ( ( void * ) ( unsigned long ) V_31 -> V_46 ) ;
V_31 -> V_46 = 0 ;
}
static int F_14 ( int V_29 )
{
struct V_30 * V_31 = F_5 ( V_32 , V_29 ) . V_31 ;
int V_35 = F_9 ( V_29 ) ;
int V_36 , V_37 ;
void * V_38 ;
if ( ! V_39 . V_50 )
return 0 ;
V_38 = F_10 ( V_51 , V_42 | V_43 , V_35 ) ;
if ( F_11 ( ! V_38 ) )
return - V_44 ;
V_36 = V_51 / V_52 ;
V_37 = V_36 / 16 ;
V_31 -> V_53 = ( T_1 ) ( unsigned long ) V_38 ;
V_31 -> V_54 = V_31 -> V_53 ;
V_31 -> V_55 = V_31 -> V_53 +
V_36 * V_52 ;
V_31 -> V_56 = V_31 -> V_55 -
V_37 * V_52 ;
return 0 ;
}
static void F_15 ( int V_29 )
{
struct V_30 * V_31 = F_5 ( V_32 , V_29 ) . V_31 ;
if ( ! V_31 || ! V_39 . V_50 )
return;
F_13 ( ( void * ) ( unsigned long ) V_31 -> V_53 ) ;
V_31 -> V_53 = 0 ;
}
static int F_16 ( int V_29 )
{
int V_35 = F_9 ( V_29 ) ;
struct V_30 * V_31 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_42 | V_43 , V_35 ) ;
if ( F_11 ( ! V_31 ) )
return - V_44 ;
F_5 ( V_32 , V_29 ) . V_31 = V_31 ;
return 0 ;
}
static void F_17 ( int V_29 )
{
struct V_30 * V_31 = F_5 ( V_32 , V_29 ) . V_31 ;
if ( ! V_31 )
return;
F_5 ( V_32 , V_29 ) . V_31 = NULL ;
F_13 ( V_31 ) ;
}
void F_18 ( void )
{
int V_29 ;
if ( ! V_39 . V_50 && ! V_39 . V_40 )
return;
F_19 () ;
F_20 (cpu)
F_7 ( V_29 ) ;
F_21 (cpu) {
F_12 ( V_29 ) ;
F_15 ( V_29 ) ;
F_17 ( V_29 ) ;
}
F_22 () ;
}
void F_23 ( void )
{
int V_57 = 0 , V_58 = 0 ;
int V_29 ;
V_39 . V_59 = 0 ;
V_39 . V_60 = 0 ;
if ( ! V_39 . V_50 && ! V_39 . V_40 )
return;
if ( ! V_39 . V_50 )
V_57 = 1 ;
if ( ! V_39 . V_40 )
V_58 = 1 ;
F_19 () ;
F_21 (cpu) {
if ( F_16 ( V_29 ) ) {
V_57 = 1 ;
V_58 = 1 ;
}
if ( ! V_57 && F_14 ( V_29 ) )
V_57 = 1 ;
if ( ! V_58 && F_8 ( V_29 ) )
V_58 = 1 ;
if ( V_57 && V_58 )
break;
}
if ( V_57 ) {
F_21 (cpu)
F_15 ( V_29 ) ;
}
if ( V_58 ) {
F_21 (cpu)
F_12 ( V_29 ) ;
}
if ( V_57 && V_58 ) {
F_21 (cpu)
F_17 ( V_29 ) ;
} else {
if ( V_39 . V_50 && ! V_57 )
V_39 . V_59 = 1 ;
if ( V_39 . V_40 && ! V_58 )
V_39 . V_60 = 1 ;
F_20 (cpu)
F_4 ( V_29 ) ;
}
F_22 () ;
}
void F_24 ( T_1 V_61 )
{
unsigned long V_62 ;
V_62 = F_25 () ;
V_62 |= V_63 ;
V_62 |= V_64 ;
V_62 |= V_65 ;
if ( ! ( V_61 & V_66 ) )
V_62 |= V_67 ;
if ( ! ( V_61 & V_68 ) )
V_62 |= V_69 ;
F_26 ( V_62 ) ;
}
void F_27 ( void )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
unsigned long V_62 ;
if ( ! V_70 -> V_31 )
return;
V_62 = F_25 () ;
V_62 &=
~ ( V_63 | V_64 | V_65 |
V_67 | V_69 ) ;
F_26 ( V_62 ) ;
}
int F_29 ( void )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
struct V_30 * V_31 = V_70 -> V_31 ;
struct V_71 {
T_1 V_72 ;
T_1 V_73 ;
T_1 V_74 ;
};
struct V_75 * V_76 = V_70 -> V_77 [ V_78 ] ;
struct V_71 * V_79 , * V_80 ;
struct V_81 V_82 ;
struct V_83 V_84 ;
struct V_85 V_86 ;
struct V_87 V_88 ;
if ( ! V_76 )
return 0 ;
if ( ! V_39 . V_59 )
return 0 ;
V_79 = (struct V_71 * ) ( unsigned long ) V_31 -> V_53 ;
V_80 = (struct V_71 * ) ( unsigned long ) V_31 -> V_54 ;
if ( V_80 <= V_79 )
return 0 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_31 -> V_54 = V_31 -> V_53 ;
F_30 ( & V_86 , 0 , V_76 -> V_89 . V_90 ) ;
F_31 ( & V_84 , & V_86 , V_76 , & V_88 ) ;
if ( F_32 ( & V_82 , V_76 , V_84 . V_91 * ( V_80 - V_79 ) ) )
return 1 ;
for (; V_79 < V_80 ; V_79 ++ ) {
V_86 . V_92 = V_79 -> V_72 ;
V_86 . V_93 = V_79 -> V_73 ;
F_33 ( & V_82 , & V_84 , & V_86 , V_76 ) ;
}
F_34 ( & V_82 ) ;
V_76 -> V_89 . V_94 ++ ;
V_76 -> V_95 = V_96 ;
return 1 ;
}
struct V_97 * F_35 ( struct V_75 * V_76 )
{
struct V_97 * V_98 ;
if ( ! V_76 -> V_99 . V_100 )
return NULL ;
if ( V_39 . V_101 ) {
F_36 (c, x86_pmu.pebs_constraints) {
if ( ( V_76 -> V_89 . V_61 & V_98 -> V_102 ) == V_98 -> V_103 ) {
V_76 -> V_89 . V_74 |= V_98 -> V_74 ;
return V_98 ;
}
}
}
return & V_104 ;
}
void F_37 ( struct V_75 * V_76 )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
struct V_105 * V_106 = & V_76 -> V_89 ;
V_106 -> V_61 &= ~ V_107 ;
V_70 -> V_108 |= 1ULL << V_106 -> V_109 ;
if ( V_76 -> V_89 . V_74 & V_110 )
V_70 -> V_108 |= 1ULL << ( V_106 -> V_109 + 32 ) ;
else if ( V_76 -> V_89 . V_74 & V_111 )
V_70 -> V_108 |= 1ULL << 63 ;
}
void F_38 ( struct V_75 * V_76 )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
struct V_105 * V_106 = & V_76 -> V_89 ;
V_70 -> V_108 &= ~ ( 1ULL << V_106 -> V_109 ) ;
if ( V_70 -> V_112 )
F_39 ( V_113 , V_70 -> V_108 ) ;
V_106 -> V_61 |= V_107 ;
}
void F_40 ( void )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
if ( V_70 -> V_108 )
F_39 ( V_113 , V_70 -> V_108 ) ;
}
void F_41 ( void )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
if ( V_70 -> V_108 )
F_39 ( V_113 , 0 ) ;
}
static int F_42 ( struct V_87 * V_88 )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
unsigned long V_72 = V_70 -> V_114 [ 0 ] . V_72 ;
unsigned long V_115 , V_73 = V_70 -> V_114 [ 0 ] . V_73 ;
unsigned long V_92 = V_88 -> V_92 ;
int V_116 = 0 ;
if ( ! V_39 . V_117 . V_118 )
return 1 ;
if ( ! V_70 -> V_119 . V_120 || ! V_72 || ! V_73 )
return 0 ;
if ( F_43 ( V_92 ) != F_43 ( V_73 ) )
return 0 ;
if ( ( V_92 - V_73 ) > V_121 )
return 0 ;
if ( V_92 == V_73 ) {
F_44 ( V_88 , V_72 ) ;
return 1 ;
}
do {
struct V_122 V_122 ;
T_2 V_123 [ V_124 ] ;
void * V_125 ;
V_115 = V_73 ;
if ( ! F_43 ( V_92 ) ) {
int V_126 , V_91 = V_124 ;
V_126 = F_45 ( V_123 , ( void V_127 * ) V_73 , V_91 ) ;
if ( V_126 != V_91 )
return 0 ;
V_125 = V_123 ;
} else
V_125 = ( void * ) V_73 ;
#ifdef F_46
V_116 = F_43 ( V_73 ) || ! F_47 ( V_128 ) ;
#endif
F_48 ( & V_122 , V_125 , V_116 ) ;
F_49 ( & V_122 ) ;
V_73 += V_122 . V_129 ;
} while ( V_73 < V_92 );
if ( V_73 == V_92 ) {
F_44 ( V_88 , V_115 ) ;
return 1 ;
}
return 0 ;
}
static void F_50 ( struct V_75 * V_76 ,
struct V_87 * V_130 , void * V_131 )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
struct V_132 * V_40 = V_131 ;
struct V_85 V_86 ;
struct V_87 V_88 ;
T_1 V_133 ;
int V_134 , V_135 ;
if ( ! F_51 ( V_76 ) )
return;
V_134 = V_76 -> V_89 . V_74 & V_110 ;
V_135 = V_76 -> V_89 . V_74 & V_111 ;
F_30 ( & V_86 , 0 , V_76 -> V_89 . V_90 ) ;
V_86 . V_136 = V_76 -> V_89 . V_90 ;
V_133 = V_76 -> V_99 . V_133 ;
if ( V_134 || V_135 ) {
if ( V_133 & V_137 )
V_86 . V_93 = V_40 -> V_138 ;
if ( V_134 && ( V_133 & V_139 ) )
V_86 . V_140 = V_40 -> V_141 ;
if ( V_133 & V_142 ) {
if ( V_134 )
V_86 . V_143 . V_4 = F_3 ( V_40 -> V_3 ) ;
else
V_86 . V_143 . V_4 = F_1 ( V_40 -> V_3 ) ;
}
}
V_88 = * V_130 ;
V_88 . V_74 = V_40 -> V_74 ;
F_44 ( & V_88 , V_40 -> V_92 ) ;
V_88 . V_144 = V_40 -> V_144 ;
V_88 . V_145 = V_40 -> V_145 ;
if ( V_76 -> V_99 . V_100 > 1 && F_42 ( & V_88 ) )
V_88 . V_74 |= V_146 ;
else
V_88 . V_74 &= ~ V_146 ;
if ( F_52 ( V_76 ) )
V_86 . V_147 = & V_70 -> V_119 ;
if ( F_53 ( V_76 , & V_86 , & V_88 ) )
F_54 ( V_76 , 0 ) ;
}
static void F_55 ( struct V_87 * V_130 )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
struct V_30 * V_31 = V_70 -> V_31 ;
struct V_75 * V_76 = V_70 -> V_77 [ 0 ] ;
struct V_148 * V_79 , * V_80 ;
int V_149 ;
if ( ! V_39 . V_60 )
return;
V_79 = (struct V_148 * ) ( unsigned long ) V_31 -> V_46 ;
V_80 = (struct V_148 * ) ( unsigned long ) V_31 -> V_47 ;
V_31 -> V_47 = V_31 -> V_46 ;
if ( ! F_56 ( 0 , V_70 -> V_150 ) )
return;
F_57 ( ! V_76 ) ;
if ( ! V_76 -> V_99 . V_100 )
return;
V_149 = V_80 - V_79 ;
if ( V_149 <= 0 )
return;
F_58 ( V_149 > 1 , L_1 , V_149 ) ;
V_79 += V_149 - 1 ;
F_50 ( V_76 , V_130 , V_79 ) ;
}
static void F_59 ( struct V_87 * V_130 )
{
struct V_32 * V_70 = & F_28 ( V_32 ) ;
struct V_30 * V_31 = V_70 -> V_31 ;
struct V_132 * V_79 , * V_80 ;
struct V_75 * V_76 = NULL ;
T_1 V_1 = 0 ;
int V_151 , V_149 ;
if ( ! V_39 . V_60 )
return;
V_79 = (struct V_132 * ) ( unsigned long ) V_31 -> V_46 ;
V_80 = (struct V_132 * ) ( unsigned long ) V_31 -> V_47 ;
V_31 -> V_47 = V_31 -> V_46 ;
V_149 = V_80 - V_79 ;
if ( V_149 <= 0 )
return;
F_58 ( V_149 > V_39 . V_152 , L_2 , V_149 ) ;
for ( ; V_79 < V_80 ; V_79 ++ ) {
F_60 (bit, (unsigned long *)&at->status, x86_pmu.max_pebs_events) {
V_76 = V_70 -> V_77 [ V_151 ] ;
if ( ! F_56 ( V_151 , V_70 -> V_150 ) )
continue;
F_57 ( ! V_76 ) ;
if ( ! V_76 -> V_99 . V_100 )
continue;
if ( F_61 ( V_151 , ( unsigned long * ) & V_1 ) )
continue;
break;
}
if ( ! V_76 || V_151 >= V_39 . V_152 )
continue;
F_50 ( V_76 , V_130 , V_79 ) ;
}
}
void F_62 ( void )
{
if ( ! F_63 ( V_153 ) )
return;
V_39 . V_50 = F_63 ( V_154 ) ;
V_39 . V_40 = F_63 ( V_155 ) ;
if ( V_39 . V_40 ) {
char V_156 = V_39 . V_117 . V_118 ? '+' : '-' ;
int V_157 = V_39 . V_117 . V_158 ;
switch ( V_157 ) {
case 0 :
F_64 ( V_159 L_3 , V_156 ) ;
V_39 . V_45 = sizeof( struct V_148 ) ;
V_39 . V_160 = F_55 ;
break;
case 1 :
F_64 ( V_159 L_4 , V_156 ) ;
V_39 . V_45 = sizeof( struct V_132 ) ;
V_39 . V_160 = F_59 ;
break;
default:
F_64 ( V_159 L_5 , V_157 , V_156 ) ;
V_39 . V_40 = 0 ;
}
}
}
void F_65 ( void )
{
struct V_30 * V_31 = F_66 ( V_32 . V_31 ) ;
if ( ! V_39 . V_50 && ! V_39 . V_40 )
return;
F_39 ( V_33 , ( unsigned long ) V_31 ) ;
}
