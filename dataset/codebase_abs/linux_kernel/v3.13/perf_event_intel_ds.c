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
void * V_44 , * V_45 ;
if ( ! V_46 . V_47 )
return 0 ;
V_44 = F_11 ( V_48 , V_49 , V_41 ) ;
if ( F_12 ( ! V_44 ) )
return - V_50 ;
if ( V_46 . V_51 . V_52 < 2 ) {
V_45 = F_11 ( V_53 , V_49 , V_41 ) ;
if ( ! V_45 ) {
F_13 ( V_44 ) ;
return - V_50 ;
}
F_6 ( V_54 , V_35 ) = V_45 ;
}
V_42 = V_48 / V_46 . V_55 ;
V_37 -> V_56 = ( T_1 ) ( unsigned long ) V_44 ;
V_37 -> V_57 = V_37 -> V_56 ;
V_37 -> V_58 = V_37 -> V_56 +
V_42 * V_46 . V_55 ;
V_37 -> V_59 = V_37 -> V_56 +
V_43 * V_46 . V_55 ;
return 0 ;
}
static void F_14 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 || ! V_46 . V_47 )
return;
F_13 ( F_6 ( V_54 , V_35 ) ) ;
F_6 ( V_54 , V_35 ) = NULL ;
F_13 ( ( void * ) ( unsigned long ) V_37 -> V_56 ) ;
V_37 -> V_56 = 0 ;
}
static int F_15 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
int V_41 = F_10 ( V_35 ) ;
int V_42 , V_43 ;
void * V_44 ;
if ( ! V_46 . V_60 )
return 0 ;
V_44 = F_11 ( V_61 , V_49 , V_41 ) ;
if ( F_12 ( ! V_44 ) )
return - V_50 ;
V_42 = V_61 / V_62 ;
V_43 = V_42 / 16 ;
V_37 -> V_63 = ( T_1 ) ( unsigned long ) V_44 ;
V_37 -> V_64 = V_37 -> V_63 ;
V_37 -> V_65 = V_37 -> V_63 +
V_42 * V_62 ;
V_37 -> V_66 = V_37 -> V_65 -
V_43 * V_62 ;
return 0 ;
}
static void F_16 ( int V_35 )
{
struct V_36 * V_37 = F_6 ( V_38 , V_35 ) . V_37 ;
if ( ! V_37 || ! V_46 . V_60 )
return;
F_13 ( ( void * ) ( unsigned long ) V_37 -> V_63 ) ;
V_37 -> V_63 = 0 ;
}
static int F_17 ( int V_35 )
{
int V_41 = F_10 ( V_35 ) ;
struct V_36 * V_37 ;
V_37 = F_11 ( sizeof( * V_37 ) , V_49 , V_41 ) ;
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
F_13 ( V_37 ) ;
}
void F_19 ( void )
{
int V_35 ;
if ( ! V_46 . V_60 && ! V_46 . V_47 )
return;
F_20 () ;
F_21 (cpu)
F_8 ( V_35 ) ;
F_22 (cpu) {
F_14 ( V_35 ) ;
F_16 ( V_35 ) ;
F_18 ( V_35 ) ;
}
F_23 () ;
}
void F_24 ( void )
{
int V_67 = 0 , V_68 = 0 ;
int V_35 ;
V_46 . V_69 = 0 ;
V_46 . V_70 = 0 ;
if ( ! V_46 . V_60 && ! V_46 . V_47 )
return;
if ( ! V_46 . V_60 )
V_67 = 1 ;
if ( ! V_46 . V_47 )
V_68 = 1 ;
F_20 () ;
F_22 (cpu) {
if ( F_17 ( V_35 ) ) {
V_67 = 1 ;
V_68 = 1 ;
}
if ( ! V_67 && F_15 ( V_35 ) )
V_67 = 1 ;
if ( ! V_68 && F_9 ( V_35 ) )
V_68 = 1 ;
if ( V_67 && V_68 )
break;
}
if ( V_67 ) {
F_22 (cpu)
F_16 ( V_35 ) ;
}
if ( V_68 ) {
F_22 (cpu)
F_14 ( V_35 ) ;
}
if ( V_67 && V_68 ) {
F_22 (cpu)
F_18 ( V_35 ) ;
} else {
if ( V_46 . V_60 && ! V_67 )
V_46 . V_69 = 1 ;
if ( V_46 . V_47 && ! V_68 )
V_46 . V_70 = 1 ;
F_21 (cpu)
F_5 ( V_35 ) ;
}
F_23 () ;
}
void F_25 ( T_1 V_71 )
{
unsigned long V_72 ;
V_72 = F_26 () ;
V_72 |= V_73 ;
V_72 |= V_74 ;
V_72 |= V_75 ;
if ( ! ( V_71 & V_76 ) )
V_72 |= V_77 ;
if ( ! ( V_71 & V_78 ) )
V_72 |= V_79 ;
F_27 ( V_72 ) ;
}
void F_28 ( void )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
unsigned long V_72 ;
if ( ! V_80 -> V_37 )
return;
V_72 = F_26 () ;
V_72 &=
~ ( V_73 | V_74 | V_75 |
V_77 | V_79 ) ;
F_27 ( V_72 ) ;
}
int F_30 ( void )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_80 -> V_37 ;
struct V_81 {
T_1 V_82 ;
T_1 V_83 ;
T_1 V_84 ;
};
struct V_85 * V_86 = V_80 -> V_87 [ V_88 ] ;
struct V_81 * V_89 , * V_90 ;
struct V_91 V_92 ;
struct V_93 V_94 ;
struct V_95 V_96 ;
struct V_97 V_98 ;
if ( ! V_86 )
return 0 ;
if ( ! V_46 . V_69 )
return 0 ;
V_89 = (struct V_81 * ) ( unsigned long ) V_37 -> V_63 ;
V_90 = (struct V_81 * ) ( unsigned long ) V_37 -> V_64 ;
if ( V_90 <= V_89 )
return 0 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_37 -> V_64 = V_37 -> V_63 ;
F_31 ( & V_96 , 0 , V_86 -> V_99 . V_100 ) ;
F_32 ( & V_94 , & V_96 , V_86 , & V_98 ) ;
if ( F_33 ( & V_92 , V_86 , V_94 . V_101 * ( V_90 - V_89 ) ) )
return 1 ;
for (; V_89 < V_90 ; V_89 ++ ) {
V_96 . V_102 = V_89 -> V_82 ;
V_96 . V_103 = V_89 -> V_83 ;
F_34 ( & V_92 , & V_94 , & V_96 , V_86 ) ;
}
F_35 ( & V_92 ) ;
V_86 -> V_99 . V_104 ++ ;
V_86 -> V_105 = V_106 ;
return 1 ;
}
struct V_107 * F_36 ( struct V_85 * V_86 )
{
struct V_107 * V_108 ;
if ( ! V_86 -> V_109 . V_110 )
return NULL ;
if ( V_46 . V_111 ) {
F_37 (c, x86_pmu.pebs_constraints) {
if ( ( V_86 -> V_99 . V_71 & V_108 -> V_112 ) == V_108 -> V_113 ) {
V_86 -> V_99 . V_84 |= V_108 -> V_84 ;
return V_108 ;
}
}
}
return & V_114 ;
}
void F_38 ( struct V_85 * V_86 )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
struct V_115 * V_116 = & V_86 -> V_99 ;
V_116 -> V_71 &= ~ V_117 ;
V_80 -> V_118 |= 1ULL << V_116 -> V_119 ;
if ( V_86 -> V_99 . V_84 & V_120 )
V_80 -> V_118 |= 1ULL << ( V_116 -> V_119 + 32 ) ;
else if ( V_86 -> V_99 . V_84 & V_121 )
V_80 -> V_118 |= 1ULL << 63 ;
}
void F_39 ( struct V_85 * V_86 )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
struct V_115 * V_116 = & V_86 -> V_99 ;
V_80 -> V_118 &= ~ ( 1ULL << V_116 -> V_119 ) ;
if ( V_86 -> V_99 . V_122 -> V_84 & V_120 )
V_80 -> V_118 &= ~ ( 1ULL << ( V_116 -> V_119 + 32 ) ) ;
else if ( V_86 -> V_99 . V_122 -> V_84 & V_121 )
V_80 -> V_118 &= ~ ( 1ULL << 63 ) ;
if ( V_80 -> V_123 )
F_40 ( V_124 , V_80 -> V_118 ) ;
V_116 -> V_71 |= V_117 ;
}
void F_41 ( void )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
if ( V_80 -> V_118 )
F_40 ( V_124 , V_80 -> V_118 ) ;
}
void F_42 ( void )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
if ( V_80 -> V_118 )
F_40 ( V_124 , 0 ) ;
}
static int F_43 ( struct V_97 * V_98 )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
unsigned long V_82 = V_80 -> V_125 [ 0 ] . V_82 ;
unsigned long V_126 , V_83 = V_80 -> V_125 [ 0 ] . V_83 ;
unsigned long V_102 = V_98 -> V_102 ;
int V_127 = 0 ;
void * V_128 ;
if ( ! V_46 . V_51 . V_129 )
return 1 ;
if ( ! V_80 -> V_130 . V_131 || ! V_82 || ! V_83 )
return 0 ;
if ( F_44 ( V_102 ) != F_44 ( V_83 ) )
return 0 ;
if ( ( V_102 - V_83 ) > V_53 )
return 0 ;
if ( V_102 == V_83 ) {
F_45 ( V_98 , V_82 ) ;
return 1 ;
}
if ( ! F_44 ( V_102 ) ) {
int V_101 , V_132 ;
T_2 * V_133 = F_46 ( V_54 ) ;
V_101 = V_102 - V_83 ;
V_132 = F_47 ( V_133 , ( void V_134 * ) V_83 , V_101 ) ;
if ( V_132 != 0 )
return 0 ;
V_128 = V_133 ;
} else {
V_128 = ( void * ) V_83 ;
}
do {
struct V_135 V_135 ;
V_126 = V_83 ;
#ifdef F_48
V_127 = F_44 ( V_83 ) || ! F_49 ( V_136 ) ;
#endif
F_50 ( & V_135 , V_128 , V_127 ) ;
F_51 ( & V_135 ) ;
V_83 += V_135 . V_137 ;
V_128 += V_135 . V_137 ;
} while ( V_83 < V_102 );
if ( V_83 == V_102 ) {
F_45 ( V_98 , V_126 ) ;
return 1 ;
}
return 0 ;
}
static inline T_1 F_52 ( struct V_138 * V_47 )
{
if ( V_47 -> V_139 ) {
union V_140 V_141 = { . V_142 = V_47 -> V_139 } ;
return V_141 . V_143 ;
}
return 0 ;
}
static inline T_1 F_53 ( struct V_138 * V_47 )
{
T_1 V_144 = ( V_47 -> V_139 & V_145 ) >> 32 ;
if ( ( V_144 & V_146 ) && ( V_47 -> V_147 & 1 ) )
V_144 |= ( ( V_47 -> V_147 >> 24 ) & 0xff ) << V_148 ;
return V_144 ;
}
static void F_54 ( struct V_85 * V_86 ,
struct V_97 * V_149 , void * V_150 )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
struct V_138 * V_47 = V_150 ;
struct V_95 V_96 ;
struct V_97 V_98 ;
T_1 V_151 ;
int V_152 , V_153 ;
if ( ! F_55 ( V_86 ) )
return;
V_152 = V_86 -> V_99 . V_84 & V_120 ;
V_153 = V_86 -> V_99 . V_84 & ( V_121 |
V_154 ) ;
F_31 ( & V_96 , 0 , V_86 -> V_99 . V_100 ) ;
V_96 . V_155 = V_86 -> V_99 . V_100 ;
V_151 = V_86 -> V_109 . V_151 ;
if ( V_152 || V_153 ) {
if ( V_152 && ( V_151 & V_156 ) )
V_96 . V_157 = V_47 -> V_158 ;
if ( V_151 & V_159 ) {
if ( V_152 )
V_96 . V_160 . V_4 = F_4 ( V_47 -> V_3 ) ;
else if ( V_86 -> V_99 . V_84 & V_154 )
V_96 . V_160 . V_4 =
F_3 ( V_47 -> V_3 ) ;
else
V_96 . V_160 . V_4 = F_1 ( V_47 -> V_3 ) ;
}
}
V_98 = * V_149 ;
V_98 . V_84 = V_47 -> V_84 ;
F_45 ( & V_98 , V_47 -> V_102 ) ;
V_98 . V_161 = V_47 -> V_161 ;
V_98 . V_162 = V_47 -> V_162 ;
if ( V_86 -> V_109 . V_110 > 1 && V_46 . V_51 . V_52 >= 2 ) {
V_98 . V_102 = V_47 -> V_163 ;
V_98 . V_84 |= V_164 ;
} else if ( V_86 -> V_109 . V_110 > 1 && F_43 ( & V_98 ) )
V_98 . V_84 |= V_164 ;
else
V_98 . V_84 &= ~ V_164 ;
if ( ( V_86 -> V_109 . V_151 & V_165 ) &&
V_46 . V_51 . V_52 >= 1 )
V_96 . V_103 = V_47 -> V_166 ;
if ( V_46 . V_51 . V_52 >= 2 ) {
if ( ( V_86 -> V_109 . V_151 & V_156 ) && ! V_152 )
V_96 . V_157 = F_52 ( V_47 ) ;
if ( V_86 -> V_109 . V_151 & V_167 )
V_96 . V_144 = F_53 ( V_47 ) ;
}
if ( F_56 ( V_86 ) )
V_96 . V_168 = & V_80 -> V_130 ;
if ( F_57 ( V_86 , & V_96 , & V_98 ) )
F_58 ( V_86 , 0 ) ;
}
static void F_59 ( struct V_97 * V_149 )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_80 -> V_37 ;
struct V_85 * V_86 = V_80 -> V_87 [ 0 ] ;
struct V_169 * V_89 , * V_90 ;
int V_170 ;
if ( ! V_46 . V_70 )
return;
V_89 = (struct V_169 * ) ( unsigned long ) V_37 -> V_56 ;
V_90 = (struct V_169 * ) ( unsigned long ) V_37 -> V_57 ;
V_37 -> V_57 = V_37 -> V_56 ;
if ( ! F_60 ( 0 , V_80 -> V_171 ) )
return;
F_61 ( ! V_86 ) ;
if ( ! V_86 -> V_109 . V_110 )
return;
V_170 = V_90 - V_89 ;
if ( V_170 <= 0 )
return;
F_62 ( V_170 > 1 , L_1 , V_170 ) ;
V_89 += V_170 - 1 ;
F_54 ( V_86 , V_149 , V_89 ) ;
}
static void F_63 ( struct V_97 * V_149 )
{
struct V_38 * V_80 = & F_29 ( V_38 ) ;
struct V_36 * V_37 = V_80 -> V_37 ;
struct V_85 * V_86 = NULL ;
void * V_89 , * V_90 ;
T_1 V_1 = 0 ;
int V_172 ;
if ( ! V_46 . V_70 )
return;
V_89 = (struct V_173 * ) ( unsigned long ) V_37 -> V_56 ;
V_90 = (struct V_173 * ) ( unsigned long ) V_37 -> V_57 ;
V_37 -> V_57 = V_37 -> V_56 ;
if ( F_12 ( V_89 > V_90 ) )
return;
F_62 ( V_90 - V_89 > V_46 . V_174 * V_46 . V_55 ,
L_2 ,
( long ) ( V_90 - V_89 ) / V_46 . V_55 ) ;
for (; V_89 < V_90 ; V_89 += V_46 . V_55 ) {
struct V_173 * V_175 = V_89 ;
F_64 (bit, (unsigned long *)&p->status,
x86_pmu.max_pebs_events) {
V_86 = V_80 -> V_87 [ V_172 ] ;
if ( ! F_60 ( V_172 , V_80 -> V_171 ) )
continue;
F_61 ( ! V_86 ) ;
if ( ! V_86 -> V_109 . V_110 )
continue;
if ( F_65 ( V_172 , ( unsigned long * ) & V_1 ) )
continue;
break;
}
if ( ! V_86 || V_172 >= V_46 . V_174 )
continue;
F_54 ( V_86 , V_149 , V_89 ) ;
}
}
void F_66 ( void )
{
if ( ! F_67 ( V_176 ) )
return;
V_46 . V_60 = F_67 ( V_177 ) ;
V_46 . V_47 = F_67 ( V_178 ) ;
if ( V_46 . V_47 ) {
char V_179 = V_46 . V_51 . V_129 ? '+' : '-' ;
int V_180 = V_46 . V_51 . V_52 ;
switch ( V_180 ) {
case 0 :
F_68 ( V_181 L_3 , V_179 ) ;
V_46 . V_55 = sizeof( struct V_169 ) ;
V_46 . V_182 = F_59 ;
break;
case 1 :
F_68 ( V_181 L_4 , V_179 ) ;
V_46 . V_55 = sizeof( struct V_173 ) ;
V_46 . V_182 = F_63 ;
break;
case 2 :
F_69 ( L_5 , V_179 ) ;
V_46 . V_55 = sizeof( struct V_138 ) ;
V_46 . V_182 = F_63 ;
break;
default:
F_68 ( V_181 L_6 , V_180 , V_179 ) ;
V_46 . V_47 = 0 ;
}
}
}
void F_70 ( void )
{
struct V_36 * V_37 = F_71 ( V_38 . V_37 ) ;
if ( ! V_46 . V_60 && ! V_46 . V_47 )
return;
F_40 ( V_39 , ( unsigned long ) V_37 ) ;
}
