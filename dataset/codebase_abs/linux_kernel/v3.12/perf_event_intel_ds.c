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
V_44 = F_11 ( V_47 , V_48 , V_41 ) ;
if ( F_12 ( ! V_44 ) )
return - V_49 ;
V_42 = V_47 / V_45 . V_50 ;
V_37 -> V_51 = ( T_1 ) ( unsigned long ) V_44 ;
V_37 -> V_52 = V_37 -> V_51 ;
V_37 -> V_53 = V_37 -> V_51 +
V_42 * V_45 . V_50 ;
V_37 -> V_54 = V_37 -> V_51 +
V_43 * V_45 . V_50 ;
return 0 ;
}
static void F_13 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 || ! V_45 . V_46 )
return;
F_14 ( ( void * ) ( unsigned long ) V_37 -> V_51 ) ;
V_37 -> V_51 = 0 ;
}
static int F_15 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
int V_41 = F_10 ( V_35 ) ;
int V_42 , V_43 ;
void * V_44 ;
if ( ! V_45 . V_55 )
return 0 ;
V_44 = F_11 ( V_56 , V_48 , V_41 ) ;
if ( F_12 ( ! V_44 ) )
return - V_49 ;
V_42 = V_56 / V_57 ;
V_43 = V_42 / 16 ;
V_37 -> V_58 = ( T_1 ) ( unsigned long ) V_44 ;
V_37 -> V_59 = V_37 -> V_58 ;
V_37 -> V_60 = V_37 -> V_58 +
V_42 * V_57 ;
V_37 -> V_61 = V_37 -> V_60 -
V_43 * V_57 ;
return 0 ;
}
static void F_16 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 || ! V_45 . V_55 )
return;
F_14 ( ( void * ) ( unsigned long ) V_37 -> V_58 ) ;
V_37 -> V_58 = 0 ;
}
static int F_17 ( int V_35 )
{
int V_41 = F_10 ( V_35 ) ;
struct V_36 * V_37 ;
V_37 = F_11 ( sizeof( * V_37 ) , V_48 , V_41 ) ;
if ( F_12 ( ! V_37 ) )
return - V_49 ;
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
if ( ! V_45 . V_55 && ! V_45 . V_46 )
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
int V_62 = 0 , V_63 = 0 ;
int V_35 ;
V_45 . V_64 = 0 ;
V_45 . V_65 = 0 ;
if ( ! V_45 . V_55 && ! V_45 . V_46 )
return;
if ( ! V_45 . V_55 )
V_62 = 1 ;
if ( ! V_45 . V_46 )
V_63 = 1 ;
F_20 () ;
F_22 (cpu) {
if ( F_17 ( V_35 ) ) {
V_62 = 1 ;
V_63 = 1 ;
}
if ( ! V_62 && F_15 ( V_35 ) )
V_62 = 1 ;
if ( ! V_63 && F_9 ( V_35 ) )
V_63 = 1 ;
if ( V_62 && V_63 )
break;
}
if ( V_62 ) {
F_22 (cpu)
F_16 ( V_35 ) ;
}
if ( V_63 ) {
F_22 (cpu)
F_13 ( V_35 ) ;
}
if ( V_62 && V_63 ) {
F_22 (cpu)
F_18 ( V_35 ) ;
} else {
if ( V_45 . V_55 && ! V_62 )
V_45 . V_64 = 1 ;
if ( V_45 . V_46 && ! V_63 )
V_45 . V_65 = 1 ;
F_21 (cpu)
F_5 ( V_35 ) ;
}
F_23 () ;
}
void F_25 ( T_1 V_66 )
{
unsigned long V_67 ;
V_67 = F_26 () ;
V_67 |= V_68 ;
V_67 |= V_69 ;
V_67 |= V_70 ;
if ( ! ( V_66 & V_71 ) )
V_67 |= V_72 ;
if ( ! ( V_66 & V_73 ) )
V_67 |= V_74 ;
F_27 ( V_67 ) ;
}
void F_28 ( void )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
unsigned long V_67 ;
if ( ! V_75 -> V_37 )
return;
V_67 = F_26 () ;
V_67 &=
~ ( V_68 | V_69 | V_70 |
V_72 | V_74 ) ;
F_27 ( V_67 ) ;
}
int F_30 ( void )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_75 -> V_37 ;
struct V_76 {
T_1 V_77 ;
T_1 V_78 ;
T_1 V_79 ;
};
struct V_80 * V_81 = V_75 -> V_82 [ V_83 ] ;
struct V_76 * V_84 , * V_85 ;
struct V_86 V_87 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
struct V_92 V_93 ;
if ( ! V_81 )
return 0 ;
if ( ! V_45 . V_64 )
return 0 ;
V_84 = (struct V_76 * ) ( unsigned long ) V_37 -> V_58 ;
V_85 = (struct V_76 * ) ( unsigned long ) V_37 -> V_59 ;
if ( V_85 <= V_84 )
return 0 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_37 -> V_59 = V_37 -> V_58 ;
F_31 ( & V_91 , 0 , V_81 -> V_94 . V_95 ) ;
F_32 ( & V_89 , & V_91 , V_81 , & V_93 ) ;
if ( F_33 ( & V_87 , V_81 , V_89 . V_96 * ( V_85 - V_84 ) ) )
return 1 ;
for (; V_84 < V_85 ; V_84 ++ ) {
V_91 . V_97 = V_84 -> V_77 ;
V_91 . V_98 = V_84 -> V_78 ;
F_34 ( & V_87 , & V_89 , & V_91 , V_81 ) ;
}
F_35 ( & V_87 ) ;
V_81 -> V_94 . V_99 ++ ;
V_81 -> V_100 = V_101 ;
return 1 ;
}
struct V_102 * F_36 ( struct V_80 * V_81 )
{
struct V_102 * V_103 ;
if ( ! V_81 -> V_104 . V_105 )
return NULL ;
if ( V_45 . V_106 ) {
F_37 (c, x86_pmu.pebs_constraints) {
if ( ( V_81 -> V_94 . V_66 & V_103 -> V_107 ) == V_103 -> V_108 ) {
V_81 -> V_94 . V_79 |= V_103 -> V_79 ;
return V_103 ;
}
}
}
return & V_109 ;
}
void F_38 ( struct V_80 * V_81 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_110 * V_111 = & V_81 -> V_94 ;
V_111 -> V_66 &= ~ V_112 ;
V_75 -> V_113 |= 1ULL << V_111 -> V_114 ;
if ( V_81 -> V_94 . V_79 & V_115 )
V_75 -> V_113 |= 1ULL << ( V_111 -> V_114 + 32 ) ;
else if ( V_81 -> V_94 . V_79 & V_116 )
V_75 -> V_113 |= 1ULL << 63 ;
}
void F_39 ( struct V_80 * V_81 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_110 * V_111 = & V_81 -> V_94 ;
V_75 -> V_113 &= ~ ( 1ULL << V_111 -> V_114 ) ;
if ( V_81 -> V_94 . V_117 -> V_79 & V_115 )
V_75 -> V_113 &= ~ ( 1ULL << ( V_111 -> V_114 + 32 ) ) ;
else if ( V_81 -> V_94 . V_117 -> V_79 & V_116 )
V_75 -> V_113 &= ~ ( 1ULL << 63 ) ;
if ( V_75 -> V_118 )
F_40 ( V_119 , V_75 -> V_113 ) ;
V_111 -> V_66 |= V_112 ;
}
void F_41 ( void )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
if ( V_75 -> V_113 )
F_40 ( V_119 , V_75 -> V_113 ) ;
}
void F_42 ( void )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
if ( V_75 -> V_113 )
F_40 ( V_119 , 0 ) ;
}
static int F_43 ( struct V_92 * V_93 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
unsigned long V_77 = V_75 -> V_120 [ 0 ] . V_77 ;
unsigned long V_121 , V_78 = V_75 -> V_120 [ 0 ] . V_78 ;
unsigned long V_97 = V_93 -> V_97 ;
int V_122 = 0 ;
if ( ! V_45 . V_123 . V_124 )
return 1 ;
if ( ! V_75 -> V_125 . V_126 || ! V_77 || ! V_78 )
return 0 ;
if ( F_44 ( V_97 ) != F_44 ( V_78 ) )
return 0 ;
if ( ( V_97 - V_78 ) > V_127 )
return 0 ;
if ( V_97 == V_78 ) {
F_45 ( V_93 , V_77 ) ;
return 1 ;
}
do {
struct V_128 V_128 ;
T_2 V_129 [ V_130 ] ;
void * V_131 ;
V_121 = V_78 ;
if ( ! F_44 ( V_97 ) ) {
int V_132 , V_96 = V_130 ;
V_132 = F_46 ( V_129 , ( void V_133 * ) V_78 , V_96 ) ;
if ( V_132 != V_96 )
return 0 ;
V_131 = V_129 ;
} else
V_131 = ( void * ) V_78 ;
#ifdef F_47
V_122 = F_44 ( V_78 ) || ! F_48 ( V_134 ) ;
#endif
F_49 ( & V_128 , V_131 , V_122 ) ;
F_50 ( & V_128 ) ;
V_78 += V_128 . V_135 ;
} while ( V_78 < V_97 );
if ( V_78 == V_97 ) {
F_45 ( V_93 , V_121 ) ;
return 1 ;
}
return 0 ;
}
static void F_51 ( struct V_80 * V_81 ,
struct V_92 * V_136 , void * V_137 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_138 * V_46 = V_137 ;
struct V_139 * V_140 = V_137 ;
struct V_90 V_91 ;
struct V_92 V_93 ;
T_1 V_141 ;
int V_142 , V_143 ;
if ( ! F_52 ( V_81 ) )
return;
V_142 = V_81 -> V_94 . V_79 & V_115 ;
V_143 = V_81 -> V_94 . V_79 & ( V_116 |
V_144 ) ;
F_31 ( & V_91 , 0 , V_81 -> V_94 . V_95 ) ;
V_91 . V_145 = V_81 -> V_94 . V_95 ;
V_141 = V_81 -> V_104 . V_141 ;
if ( V_142 || V_143 ) {
if ( V_142 && ( V_141 & V_146 ) )
V_91 . V_147 = V_46 -> V_148 ;
if ( V_141 & V_149 ) {
if ( V_142 )
V_91 . V_150 . V_4 = F_4 ( V_46 -> V_3 ) ;
else if ( V_81 -> V_94 . V_79 & V_144 )
V_91 . V_150 . V_4 =
F_3 ( V_46 -> V_3 ) ;
else
V_91 . V_150 . V_4 = F_1 ( V_46 -> V_3 ) ;
}
}
V_93 = * V_136 ;
V_93 . V_79 = V_46 -> V_79 ;
F_45 ( & V_93 , V_46 -> V_97 ) ;
V_93 . V_151 = V_46 -> V_151 ;
V_93 . V_152 = V_46 -> V_152 ;
if ( V_81 -> V_104 . V_105 > 1 && V_45 . V_123 . V_153 >= 2 ) {
V_93 . V_97 = V_140 -> V_154 ;
V_93 . V_79 |= V_155 ;
} else if ( V_81 -> V_104 . V_105 > 1 && F_43 ( & V_93 ) )
V_93 . V_79 |= V_155 ;
else
V_93 . V_79 &= ~ V_155 ;
if ( ( V_81 -> V_104 . V_141 & V_156 ) &&
V_45 . V_123 . V_153 >= 1 )
V_91 . V_98 = V_46 -> V_157 ;
if ( F_53 ( V_81 ) )
V_91 . V_158 = & V_75 -> V_125 ;
if ( F_54 ( V_81 , & V_91 , & V_93 ) )
F_55 ( V_81 , 0 ) ;
}
static void F_56 ( struct V_92 * V_136 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_75 -> V_37 ;
struct V_80 * V_81 = V_75 -> V_82 [ 0 ] ;
struct V_159 * V_84 , * V_85 ;
int V_160 ;
if ( ! V_45 . V_65 )
return;
V_84 = (struct V_159 * ) ( unsigned long ) V_37 -> V_51 ;
V_85 = (struct V_159 * ) ( unsigned long ) V_37 -> V_52 ;
V_37 -> V_52 = V_37 -> V_51 ;
if ( ! F_57 ( 0 , V_75 -> V_161 ) )
return;
F_58 ( ! V_81 ) ;
if ( ! V_81 -> V_104 . V_105 )
return;
V_160 = V_85 - V_84 ;
if ( V_160 <= 0 )
return;
F_59 ( V_160 > 1 , L_1 , V_160 ) ;
V_84 += V_160 - 1 ;
F_51 ( V_81 , V_136 , V_84 ) ;
}
static void F_60 ( struct V_92 * V_136 , void * V_84 ,
void * V_85 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_75 -> V_37 ;
struct V_80 * V_81 = NULL ;
T_1 V_1 = 0 ;
int V_162 ;
V_37 -> V_52 = V_37 -> V_51 ;
for (; V_84 < V_85 ; V_84 += V_45 . V_50 ) {
struct V_138 * V_163 = V_84 ;
F_61 (bit, (unsigned long *)&p->status,
x86_pmu.max_pebs_events) {
V_81 = V_75 -> V_82 [ V_162 ] ;
if ( ! F_57 ( V_162 , V_75 -> V_161 ) )
continue;
F_58 ( ! V_81 ) ;
if ( ! V_81 -> V_104 . V_105 )
continue;
if ( F_62 ( V_162 , ( unsigned long * ) & V_1 ) )
continue;
break;
}
if ( ! V_81 || V_162 >= V_45 . V_164 )
continue;
F_51 ( V_81 , V_136 , V_84 ) ;
}
}
static void F_63 ( struct V_92 * V_136 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_75 -> V_37 ;
struct V_138 * V_84 , * V_85 ;
int V_160 ;
if ( ! V_45 . V_65 )
return;
V_84 = (struct V_138 * ) ( unsigned long ) V_37 -> V_51 ;
V_85 = (struct V_138 * ) ( unsigned long ) V_37 -> V_52 ;
V_37 -> V_52 = V_37 -> V_51 ;
V_160 = V_85 - V_84 ;
if ( V_160 <= 0 )
return;
F_59 ( V_160 > V_45 . V_164 ,
L_2 , V_160 ) ;
return F_60 ( V_136 , V_84 , V_85 ) ;
}
static void F_64 ( struct V_92 * V_136 )
{
struct V_38 * V_75 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_75 -> V_37 ;
struct V_139 * V_84 , * V_85 ;
int V_160 ;
if ( ! V_45 . V_65 )
return;
V_84 = (struct V_139 * ) ( unsigned long ) V_37 -> V_51 ;
V_85 = (struct V_139 * ) ( unsigned long ) V_37 -> V_52 ;
V_160 = V_85 - V_84 ;
if ( V_160 <= 0 )
return;
F_59 ( V_160 > V_45 . V_164 ,
L_2 , V_160 ) ;
return F_60 ( V_136 , V_84 , V_85 ) ;
}
void F_65 ( void )
{
if ( ! F_66 ( V_165 ) )
return;
V_45 . V_55 = F_66 ( V_166 ) ;
V_45 . V_46 = F_66 ( V_167 ) ;
if ( V_45 . V_46 ) {
char V_168 = V_45 . V_123 . V_124 ? '+' : '-' ;
int V_169 = V_45 . V_123 . V_153 ;
switch ( V_169 ) {
case 0 :
F_67 ( V_170 L_3 , V_168 ) ;
V_45 . V_50 = sizeof( struct V_159 ) ;
V_45 . V_171 = F_56 ;
break;
case 1 :
F_67 ( V_170 L_4 , V_168 ) ;
V_45 . V_50 = sizeof( struct V_138 ) ;
V_45 . V_171 = F_63 ;
break;
case 2 :
F_68 ( L_5 , V_168 ) ;
V_45 . V_50 = sizeof( struct V_139 ) ;
V_45 . V_171 = F_64 ;
break;
default:
F_67 ( V_170 L_6 , V_169 , V_168 ) ;
V_45 . V_46 = 0 ;
}
}
}
void F_69 ( void )
{
struct V_36 * V_37 = F_70 ( V_38 . V_37 ) ;
if ( ! V_45 . V_55 && ! V_45 . V_46 )
return;
F_40 ( V_39 , ( unsigned long ) V_37 ) ;
}
