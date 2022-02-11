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
union V_20 V_3 ;
V_3 . V_4 = 0 ;
V_3 . V_21 = V_22 ;
V_3 . V_23 = V_24 ;
if ( V_1 & 1 )
V_3 . V_23 = V_25 ;
return V_3 . V_4 ;
}
static T_1 F_4 ( T_1 V_1 )
{
union V_2 V_3 ;
T_1 V_4 ;
int V_26 = V_27 . V_28 ;
int V_29 = V_27 . V_30 ;
V_3 . V_4 = V_1 ;
V_4 = V_31 [ V_3 . V_32 ] ;
if ( V_29 == 0x6 && ( V_26 == 26 || V_26 == 30
|| V_26 == 31 || V_26 == 46 ) ) {
V_4 |= F_2 ( V_11 , V_8 ) | F_2 ( V_18 , V_8 ) ;
return V_4 ;
}
if ( V_3 . V_33 )
V_4 |= F_2 ( V_11 , V_14 ) | F_2 ( V_11 , V_12 ) ;
else
V_4 |= F_2 ( V_11 , V_15 ) | F_2 ( V_11 , V_10 ) | F_2 ( V_11 , V_12 ) ;
if ( V_3 . V_34 )
V_4 |= F_2 ( V_18 , V_19 ) ;
return V_4 ;
}
void F_5 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 )
return;
F_7 ( V_35 , V_39 ,
( V_40 ) ( ( T_1 ) ( unsigned long ) V_37 ) ,
( V_40 ) ( ( T_1 ) ( unsigned long ) V_37 >> 32 ) ) ;
}
void F_8 ( int V_35 )
{
if ( ! F_6 ( V_38 , V_35 ) . V_37 )
return;
F_7 ( V_35 , V_39 , 0 , 0 ) ;
}
static int F_9 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
int V_41 = F_10 ( V_35 ) ;
int V_42 , V_43 = 1 ;
void * V_44 ;
if ( ! V_45 . V_46 )
return 0 ;
V_44 = F_11 ( V_47 , V_48 | V_49 , V_41 ) ;
if ( F_12 ( ! V_44 ) )
return - V_50 ;
V_42 = V_47 / V_45 . V_51 ;
V_37 -> V_52 = ( T_1 ) ( unsigned long ) V_44 ;
V_37 -> V_53 = V_37 -> V_52 ;
V_37 -> V_54 = V_37 -> V_52 +
V_42 * V_45 . V_51 ;
V_37 -> V_55 = V_37 -> V_52 +
V_43 * V_45 . V_51 ;
return 0 ;
}
static void F_13 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 || ! V_45 . V_46 )
return;
F_14 ( ( void * ) ( unsigned long ) V_37 -> V_52 ) ;
V_37 -> V_52 = 0 ;
}
static int F_15 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
int V_41 = F_10 ( V_35 ) ;
int V_42 , V_43 ;
void * V_44 ;
if ( ! V_45 . V_56 )
return 0 ;
V_44 = F_11 ( V_57 , V_48 | V_49 , V_41 ) ;
if ( F_12 ( ! V_44 ) )
return - V_50 ;
V_42 = V_57 / V_58 ;
V_43 = V_42 / 16 ;
V_37 -> V_59 = ( T_1 ) ( unsigned long ) V_44 ;
V_37 -> V_60 = V_37 -> V_59 ;
V_37 -> V_61 = V_37 -> V_59 +
V_42 * V_58 ;
V_37 -> V_62 = V_37 -> V_61 -
V_43 * V_58 ;
return 0 ;
}
static void F_16 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 || ! V_45 . V_56 )
return;
F_14 ( ( void * ) ( unsigned long ) V_37 -> V_59 ) ;
V_37 -> V_59 = 0 ;
}
static int F_17 ( int V_35 )
{
int V_41 = F_10 ( V_35 ) ;
struct V_36 * V_37 ;
V_37 = F_11 ( sizeof( * V_37 ) , V_48 | V_49 , V_41 ) ;
if ( F_12 ( ! V_37 ) )
return - V_50 ;
F_6 ( V_38 , V_35 ) . V_37 = V_37 ;
return 0 ;
}
static void F_18 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 )
return;
F_6 ( V_38 , V_35 ) . V_37 = NULL ;
F_14 ( V_37 ) ;
}
void F_19 ( void )
{
int V_35 ;
if ( ! V_45 . V_56 && ! V_45 . V_46 )
return;
F_20 () ;
F_21 (cpu)
F_8 ( V_35 ) ;
F_22 (cpu) {
F_13 ( V_35 ) ;
F_16 ( V_35 ) ;
F_18 ( V_35 ) ;
}
F_23 () ;
}
void F_24 ( void )
{
int V_63 = 0 , V_64 = 0 ;
int V_35 ;
V_45 . V_65 = 0 ;
V_45 . V_66 = 0 ;
if ( ! V_45 . V_56 && ! V_45 . V_46 )
return;
if ( ! V_45 . V_56 )
V_63 = 1 ;
if ( ! V_45 . V_46 )
V_64 = 1 ;
F_20 () ;
F_22 (cpu) {
if ( F_17 ( V_35 ) ) {
V_63 = 1 ;
V_64 = 1 ;
}
if ( ! V_63 && F_15 ( V_35 ) )
V_63 = 1 ;
if ( ! V_64 && F_9 ( V_35 ) )
V_64 = 1 ;
if ( V_63 && V_64 )
break;
}
if ( V_63 ) {
F_22 (cpu)
F_16 ( V_35 ) ;
}
if ( V_64 ) {
F_22 (cpu)
F_13 ( V_35 ) ;
}
if ( V_63 && V_64 ) {
F_22 (cpu)
F_18 ( V_35 ) ;
} else {
if ( V_45 . V_56 && ! V_63 )
V_45 . V_65 = 1 ;
if ( V_45 . V_46 && ! V_64 )
V_45 . V_66 = 1 ;
F_21 (cpu)
F_5 ( V_35 ) ;
}
F_23 () ;
}
void F_25 ( T_1 V_67 )
{
unsigned long V_68 ;
V_68 = F_26 () ;
V_68 |= V_69 ;
V_68 |= V_70 ;
V_68 |= V_71 ;
if ( ! ( V_67 & V_72 ) )
V_68 |= V_73 ;
if ( ! ( V_67 & V_74 ) )
V_68 |= V_75 ;
F_27 ( V_68 ) ;
}
void F_28 ( void )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
unsigned long V_68 ;
if ( ! V_76 -> V_37 )
return;
V_68 = F_26 () ;
V_68 &=
~ ( V_69 | V_70 | V_71 |
V_73 | V_75 ) ;
F_27 ( V_68 ) ;
}
int F_30 ( void )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_77 {
T_1 V_78 ;
T_1 V_79 ;
T_1 V_80 ;
};
struct V_81 * V_82 = V_76 -> V_83 [ V_84 ] ;
struct V_77 * V_85 , * V_86 ;
struct V_87 V_88 ;
struct V_89 V_90 ;
struct V_91 V_92 ;
struct V_93 V_94 ;
if ( ! V_82 )
return 0 ;
if ( ! V_45 . V_65 )
return 0 ;
V_85 = (struct V_77 * ) ( unsigned long ) V_37 -> V_59 ;
V_86 = (struct V_77 * ) ( unsigned long ) V_37 -> V_60 ;
if ( V_86 <= V_85 )
return 0 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_37 -> V_60 = V_37 -> V_59 ;
F_31 ( & V_92 , 0 , V_82 -> V_95 . V_96 ) ;
F_32 ( & V_90 , & V_92 , V_82 , & V_94 ) ;
if ( F_33 ( & V_88 , V_82 , V_90 . V_97 * ( V_86 - V_85 ) ) )
return 1 ;
for (; V_85 < V_86 ; V_85 ++ ) {
V_92 . V_98 = V_85 -> V_78 ;
V_92 . V_99 = V_85 -> V_79 ;
F_34 ( & V_88 , & V_90 , & V_92 , V_82 ) ;
}
F_35 ( & V_88 ) ;
V_82 -> V_95 . V_100 ++ ;
V_82 -> V_101 = V_102 ;
return 1 ;
}
struct V_103 * F_36 ( struct V_81 * V_82 )
{
struct V_103 * V_104 ;
if ( ! V_82 -> V_105 . V_106 )
return NULL ;
if ( V_45 . V_107 ) {
F_37 (c, x86_pmu.pebs_constraints) {
if ( ( V_82 -> V_95 . V_67 & V_104 -> V_108 ) == V_104 -> V_109 ) {
V_82 -> V_95 . V_80 |= V_104 -> V_80 ;
return V_104 ;
}
}
}
return & V_110 ;
}
void F_38 ( struct V_81 * V_82 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_111 * V_112 = & V_82 -> V_95 ;
V_112 -> V_67 &= ~ V_113 ;
V_76 -> V_114 |= 1ULL << V_112 -> V_115 ;
if ( V_82 -> V_95 . V_80 & V_116 )
V_76 -> V_114 |= 1ULL << ( V_112 -> V_115 + 32 ) ;
else if ( V_82 -> V_95 . V_80 & V_117 )
V_76 -> V_114 |= 1ULL << 63 ;
}
void F_39 ( struct V_81 * V_82 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_111 * V_112 = & V_82 -> V_95 ;
V_76 -> V_114 &= ~ ( 1ULL << V_112 -> V_115 ) ;
if ( V_82 -> V_95 . V_118 -> V_80 & V_116 )
V_76 -> V_114 &= ~ ( 1ULL << ( V_112 -> V_115 + 32 ) ) ;
else if ( V_82 -> V_95 . V_118 -> V_80 & V_117 )
V_76 -> V_114 &= ~ ( 1ULL << 63 ) ;
if ( V_76 -> V_119 )
F_40 ( V_120 , V_76 -> V_114 ) ;
V_112 -> V_67 |= V_113 ;
}
void F_41 ( void )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
if ( V_76 -> V_114 )
F_40 ( V_120 , V_76 -> V_114 ) ;
}
void F_42 ( void )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
if ( V_76 -> V_114 )
F_40 ( V_120 , 0 ) ;
}
static int F_43 ( struct V_93 * V_94 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
unsigned long V_78 = V_76 -> V_121 [ 0 ] . V_78 ;
unsigned long V_122 , V_79 = V_76 -> V_121 [ 0 ] . V_79 ;
unsigned long V_98 = V_94 -> V_98 ;
int V_123 = 0 ;
if ( ! V_45 . V_124 . V_125 )
return 1 ;
if ( ! V_76 -> V_126 . V_127 || ! V_78 || ! V_79 )
return 0 ;
if ( F_44 ( V_98 ) != F_44 ( V_79 ) )
return 0 ;
if ( ( V_98 - V_79 ) > V_128 )
return 0 ;
if ( V_98 == V_79 ) {
F_45 ( V_94 , V_78 ) ;
return 1 ;
}
do {
struct V_129 V_129 ;
T_2 V_130 [ V_131 ] ;
void * V_132 ;
V_122 = V_79 ;
if ( ! F_44 ( V_98 ) ) {
int V_133 , V_97 = V_131 ;
V_133 = F_46 ( V_130 , ( void V_134 * ) V_79 , V_97 ) ;
if ( V_133 != V_97 )
return 0 ;
V_132 = V_130 ;
} else
V_132 = ( void * ) V_79 ;
#ifdef F_47
V_123 = F_44 ( V_79 ) || ! F_48 ( V_135 ) ;
#endif
F_49 ( & V_129 , V_132 , V_123 ) ;
F_50 ( & V_129 ) ;
V_79 += V_129 . V_136 ;
} while ( V_79 < V_98 );
if ( V_79 == V_98 ) {
F_45 ( V_94 , V_122 ) ;
return 1 ;
}
return 0 ;
}
static void F_51 ( struct V_81 * V_82 ,
struct V_93 * V_137 , void * V_138 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_139 * V_46 = V_138 ;
struct V_140 * V_141 = V_138 ;
struct V_91 V_92 ;
struct V_93 V_94 ;
T_1 V_142 ;
int V_143 , V_144 ;
if ( ! F_52 ( V_82 ) )
return;
V_143 = V_82 -> V_95 . V_80 & V_116 ;
V_144 = V_82 -> V_95 . V_80 & ( V_117 |
V_145 ) ;
F_31 ( & V_92 , 0 , V_82 -> V_95 . V_96 ) ;
V_92 . V_146 = V_82 -> V_95 . V_96 ;
V_142 = V_82 -> V_105 . V_142 ;
if ( V_143 || V_144 ) {
if ( V_143 && ( V_142 & V_147 ) )
V_92 . V_148 = V_46 -> V_149 ;
if ( V_142 & V_150 ) {
if ( V_143 )
V_92 . V_151 . V_4 = F_4 ( V_46 -> V_3 ) ;
else if ( V_82 -> V_95 . V_80 & V_145 )
V_92 . V_151 . V_4 =
F_3 ( V_46 -> V_3 ) ;
else
V_92 . V_151 . V_4 = F_1 ( V_46 -> V_3 ) ;
}
}
V_94 = * V_137 ;
V_94 . V_80 = V_46 -> V_80 ;
F_45 ( & V_94 , V_46 -> V_98 ) ;
V_94 . V_152 = V_46 -> V_152 ;
V_94 . V_153 = V_46 -> V_153 ;
if ( V_82 -> V_105 . V_106 > 1 && V_45 . V_124 . V_154 >= 2 ) {
V_94 . V_98 = V_141 -> V_155 ;
V_94 . V_80 |= V_156 ;
} else if ( V_82 -> V_105 . V_106 > 1 && F_43 ( & V_94 ) )
V_94 . V_80 |= V_156 ;
else
V_94 . V_80 &= ~ V_156 ;
if ( ( V_82 -> V_105 . V_142 & V_157 ) &&
V_45 . V_124 . V_154 >= 1 )
V_92 . V_99 = V_46 -> V_158 ;
if ( F_53 ( V_82 ) )
V_92 . V_159 = & V_76 -> V_126 ;
if ( F_54 ( V_82 , & V_92 , & V_94 ) )
F_55 ( V_82 , 0 ) ;
}
static void F_56 ( struct V_93 * V_137 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_81 * V_82 = V_76 -> V_83 [ 0 ] ;
struct V_160 * V_85 , * V_86 ;
int V_161 ;
if ( ! V_45 . V_66 )
return;
V_85 = (struct V_160 * ) ( unsigned long ) V_37 -> V_52 ;
V_86 = (struct V_160 * ) ( unsigned long ) V_37 -> V_53 ;
V_37 -> V_53 = V_37 -> V_52 ;
if ( ! F_57 ( 0 , V_76 -> V_162 ) )
return;
F_58 ( ! V_82 ) ;
if ( ! V_82 -> V_105 . V_106 )
return;
V_161 = V_86 - V_85 ;
if ( V_161 <= 0 )
return;
F_59 ( V_161 > 1 , L_1 , V_161 ) ;
V_85 += V_161 - 1 ;
F_51 ( V_82 , V_137 , V_85 ) ;
}
static void F_60 ( struct V_93 * V_137 , void * V_85 ,
void * V_86 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_81 * V_82 = NULL ;
T_1 V_1 = 0 ;
int V_163 ;
V_37 -> V_53 = V_37 -> V_52 ;
for (; V_85 < V_86 ; V_85 += V_45 . V_51 ) {
struct V_139 * V_164 = V_85 ;
F_61 (bit, (unsigned long *)&p->status,
x86_pmu.max_pebs_events) {
V_82 = V_76 -> V_83 [ V_163 ] ;
if ( ! F_57 ( V_163 , V_76 -> V_162 ) )
continue;
F_58 ( ! V_82 ) ;
if ( ! V_82 -> V_105 . V_106 )
continue;
if ( F_62 ( V_163 , ( unsigned long * ) & V_1 ) )
continue;
break;
}
if ( ! V_82 || V_163 >= V_45 . V_165 )
continue;
F_51 ( V_82 , V_137 , V_85 ) ;
}
}
static void F_63 ( struct V_93 * V_137 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_139 * V_85 , * V_86 ;
int V_161 ;
if ( ! V_45 . V_66 )
return;
V_85 = (struct V_139 * ) ( unsigned long ) V_37 -> V_52 ;
V_86 = (struct V_139 * ) ( unsigned long ) V_37 -> V_53 ;
V_37 -> V_53 = V_37 -> V_52 ;
V_161 = V_86 - V_85 ;
if ( V_161 <= 0 )
return;
F_59 ( V_161 > V_45 . V_165 ,
L_2 , V_161 ) ;
return F_60 ( V_137 , V_85 , V_86 ) ;
}
static void F_64 ( struct V_93 * V_137 )
{
struct V_38 * V_76 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_140 * V_85 , * V_86 ;
int V_161 ;
if ( ! V_45 . V_66 )
return;
V_85 = (struct V_140 * ) ( unsigned long ) V_37 -> V_52 ;
V_86 = (struct V_140 * ) ( unsigned long ) V_37 -> V_53 ;
V_161 = V_86 - V_85 ;
if ( V_161 <= 0 )
return;
F_59 ( V_161 > V_45 . V_165 ,
L_2 , V_161 ) ;
return F_60 ( V_137 , V_85 , V_86 ) ;
}
void F_65 ( void )
{
if ( ! F_66 ( V_166 ) )
return;
V_45 . V_56 = F_66 ( V_167 ) ;
V_45 . V_46 = F_66 ( V_168 ) ;
if ( V_45 . V_46 ) {
char V_169 = V_45 . V_124 . V_125 ? '+' : '-' ;
int V_170 = V_45 . V_124 . V_154 ;
switch ( V_170 ) {
case 0 :
F_67 ( V_171 L_3 , V_169 ) ;
V_45 . V_51 = sizeof( struct V_160 ) ;
V_45 . V_172 = F_56 ;
break;
case 1 :
F_67 ( V_171 L_4 , V_169 ) ;
V_45 . V_51 = sizeof( struct V_139 ) ;
V_45 . V_172 = F_63 ;
break;
case 2 :
F_68 ( L_5 , V_169 ) ;
V_45 . V_51 = sizeof( struct V_140 ) ;
V_45 . V_172 = F_64 ;
break;
default:
F_67 ( V_171 L_6 , V_170 , V_169 ) ;
V_45 . V_46 = 0 ;
}
}
}
void F_69 ( void )
{
struct V_36 * V_37 = F_70 ( V_38 . V_37 ) ;
if ( ! V_45 . V_56 && ! V_45 . V_46 )
return;
F_40 ( V_39 , ( unsigned long ) V_37 ) ;
}
