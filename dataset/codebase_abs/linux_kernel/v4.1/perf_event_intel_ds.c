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
static T_1 F_3 ( struct V_20 * V_21 , T_1 V_1 )
{
union V_22 V_3 ;
V_3 . V_4 = V_23 ;
if ( V_21 -> V_24 . V_25 & V_26 )
V_3 . V_27 = V_28 ;
else if ( V_21 -> V_24 . V_25 & V_29 )
V_3 . V_27 = V_30 ;
if ( V_21 -> V_24 . V_25 & V_26 ) {
if ( V_1 & 1 )
V_3 . V_31 = V_32 | V_33 ;
else
V_3 . V_31 = V_32 | V_34 ;
}
return V_3 . V_4 ;
}
static T_1 F_4 ( T_1 V_1 )
{
union V_2 V_3 ;
T_1 V_4 ;
int V_35 = V_36 . V_37 ;
int V_38 = V_36 . V_39 ;
V_3 . V_4 = V_1 ;
V_4 = V_40 [ V_3 . V_41 ] ;
if ( V_38 == 0x6 && ( V_35 == 26 || V_35 == 30
|| V_35 == 31 || V_35 == 46 ) ) {
V_4 |= F_2 ( V_11 , V_8 ) | F_2 ( V_18 , V_8 ) ;
return V_4 ;
}
if ( V_3 . V_42 )
V_4 |= F_2 ( V_11 , V_14 ) | F_2 ( V_11 , V_12 ) ;
else
V_4 |= F_2 ( V_11 , V_15 ) | F_2 ( V_11 , V_10 ) | F_2 ( V_11 , V_12 ) ;
if ( V_3 . V_43 )
V_4 |= F_2 ( V_18 , V_19 ) ;
return V_4 ;
}
void F_5 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
if ( ! V_46 )
return;
F_7 ( V_44 , V_48 ,
( V_49 ) ( ( T_1 ) ( unsigned long ) V_46 ) ,
( V_49 ) ( ( T_1 ) ( unsigned long ) V_46 >> 32 ) ) ;
}
void F_8 ( int V_44 )
{
if ( ! F_6 ( V_47 , V_44 ) . V_46 )
return;
F_7 ( V_44 , V_48 , 0 , 0 ) ;
}
static int F_9 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
int V_50 = F_10 ( V_44 ) ;
int V_51 , V_52 = 1 ;
void * V_53 , * V_54 ;
if ( ! V_55 . V_56 )
return 0 ;
V_53 = F_11 ( V_57 , V_58 , V_50 ) ;
if ( F_12 ( ! V_53 ) )
return - V_59 ;
if ( V_55 . V_60 . V_61 < 2 ) {
V_54 = F_11 ( V_62 , V_58 , V_50 ) ;
if ( ! V_54 ) {
F_13 ( V_53 ) ;
return - V_59 ;
}
F_6 ( V_63 , V_44 ) = V_54 ;
}
V_51 = V_57 / V_55 . V_64 ;
V_46 -> V_65 = ( T_1 ) ( unsigned long ) V_53 ;
V_46 -> V_66 = V_46 -> V_65 ;
V_46 -> V_67 = V_46 -> V_65 +
V_51 * V_55 . V_64 ;
V_46 -> V_68 = V_46 -> V_65 +
V_52 * V_55 . V_64 ;
return 0 ;
}
static void F_14 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
if ( ! V_46 || ! V_55 . V_56 )
return;
F_13 ( F_6 ( V_63 , V_44 ) ) ;
F_6 ( V_63 , V_44 ) = NULL ;
F_13 ( ( void * ) ( unsigned long ) V_46 -> V_65 ) ;
V_46 -> V_65 = 0 ;
}
static int F_15 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
int V_50 = F_10 ( V_44 ) ;
int V_51 , V_52 ;
void * V_53 ;
if ( ! V_55 . V_69 )
return 0 ;
V_53 = F_11 ( V_70 , V_58 | V_71 , V_50 ) ;
if ( F_12 ( ! V_53 ) ) {
F_16 ( 1 , L_1 , V_72 ) ;
return - V_59 ;
}
V_51 = V_70 / V_73 ;
V_52 = V_51 / 16 ;
V_46 -> V_74 = ( T_1 ) ( unsigned long ) V_53 ;
V_46 -> V_75 = V_46 -> V_74 ;
V_46 -> V_76 = V_46 -> V_74 +
V_51 * V_73 ;
V_46 -> V_77 = V_46 -> V_76 -
V_52 * V_73 ;
return 0 ;
}
static void F_17 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
if ( ! V_46 || ! V_55 . V_69 )
return;
F_13 ( ( void * ) ( unsigned long ) V_46 -> V_74 ) ;
V_46 -> V_74 = 0 ;
}
static int F_18 ( int V_44 )
{
int V_50 = F_10 ( V_44 ) ;
struct V_45 * V_46 ;
V_46 = F_11 ( sizeof( * V_46 ) , V_58 , V_50 ) ;
if ( F_12 ( ! V_46 ) )
return - V_59 ;
F_6 ( V_47 , V_44 ) . V_46 = V_46 ;
return 0 ;
}
static void F_19 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
if ( ! V_46 )
return;
F_6 ( V_47 , V_44 ) . V_46 = NULL ;
F_13 ( V_46 ) ;
}
void F_20 ( void )
{
int V_44 ;
if ( ! V_55 . V_69 && ! V_55 . V_56 )
return;
F_21 () ;
F_22 (cpu)
F_8 ( V_44 ) ;
F_23 (cpu) {
F_14 ( V_44 ) ;
F_17 ( V_44 ) ;
F_19 ( V_44 ) ;
}
F_24 () ;
}
void F_25 ( void )
{
int V_78 = 0 , V_79 = 0 ;
int V_44 ;
V_55 . V_80 = 0 ;
V_55 . V_81 = 0 ;
if ( ! V_55 . V_69 && ! V_55 . V_56 )
return;
if ( ! V_55 . V_69 )
V_78 = 1 ;
if ( ! V_55 . V_56 )
V_79 = 1 ;
F_21 () ;
F_23 (cpu) {
if ( F_18 ( V_44 ) ) {
V_78 = 1 ;
V_79 = 1 ;
}
if ( ! V_78 && F_15 ( V_44 ) )
V_78 = 1 ;
if ( ! V_79 && F_9 ( V_44 ) )
V_79 = 1 ;
if ( V_78 && V_79 )
break;
}
if ( V_78 ) {
F_23 (cpu)
F_17 ( V_44 ) ;
}
if ( V_79 ) {
F_23 (cpu)
F_14 ( V_44 ) ;
}
if ( V_78 && V_79 ) {
F_23 (cpu)
F_19 ( V_44 ) ;
} else {
if ( V_55 . V_69 && ! V_78 )
V_55 . V_80 = 1 ;
if ( V_55 . V_56 && ! V_79 )
V_55 . V_81 = 1 ;
F_22 (cpu)
F_5 ( V_44 ) ;
}
F_24 () ;
}
void F_26 ( T_1 V_82 )
{
unsigned long V_83 ;
V_83 = F_27 () ;
V_83 |= V_84 ;
V_83 |= V_85 ;
if ( V_82 & V_86 )
V_83 |= V_87 ;
if ( ! ( V_82 & V_88 ) )
V_83 |= V_89 ;
if ( ! ( V_82 & V_90 ) )
V_83 |= V_91 ;
F_28 ( V_83 ) ;
}
void F_29 ( void )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
unsigned long V_83 ;
if ( ! V_92 -> V_46 )
return;
V_83 = F_27 () ;
V_83 &=
~ ( V_84 | V_85 | V_87 |
V_89 | V_91 ) ;
F_28 ( V_83 ) ;
}
int F_31 ( void )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_92 -> V_46 ;
struct V_93 {
T_1 V_94 ;
T_1 V_95 ;
T_1 V_25 ;
};
struct V_20 * V_21 = V_92 -> V_96 [ V_97 ] ;
struct V_93 * V_98 , * V_99 ;
struct V_100 V_101 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
struct V_106 V_107 ;
if ( ! V_21 )
return 0 ;
if ( ! V_55 . V_80 )
return 0 ;
V_98 = (struct V_93 * ) ( unsigned long ) V_46 -> V_74 ;
V_99 = (struct V_93 * ) ( unsigned long ) V_46 -> V_75 ;
if ( V_99 <= V_98 )
return 0 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_46 -> V_75 = V_46 -> V_74 ;
F_32 ( & V_105 , 0 , V_21 -> V_24 . V_108 ) ;
F_33 ( & V_103 , & V_105 , V_21 , & V_107 ) ;
if ( F_34 ( & V_101 , V_21 , V_103 . V_109 * ( V_99 - V_98 ) ) )
return 1 ;
for (; V_98 < V_99 ; V_98 ++ ) {
V_105 . V_110 = V_98 -> V_94 ;
V_105 . V_111 = V_98 -> V_95 ;
F_35 ( & V_101 , & V_103 , & V_105 , V_21 ) ;
}
F_36 ( & V_101 ) ;
V_21 -> V_24 . V_112 ++ ;
V_21 -> V_113 = V_114 ;
return 1 ;
}
struct V_115 * F_37 ( struct V_20 * V_21 )
{
struct V_115 * V_116 ;
if ( ! V_21 -> V_117 . V_118 )
return NULL ;
if ( V_55 . V_119 ) {
F_38 (c, x86_pmu.pebs_constraints) {
if ( ( V_21 -> V_24 . V_82 & V_116 -> V_120 ) == V_116 -> V_121 ) {
V_21 -> V_24 . V_25 |= V_116 -> V_25 ;
return V_116 ;
}
}
}
return & V_122 ;
}
void F_39 ( struct V_20 * V_21 )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
struct V_123 * V_124 = & V_21 -> V_24 ;
V_124 -> V_82 &= ~ V_86 ;
V_92 -> V_125 |= 1ULL << V_124 -> V_126 ;
if ( V_21 -> V_24 . V_25 & V_127 )
V_92 -> V_125 |= 1ULL << ( V_124 -> V_126 + 32 ) ;
else if ( V_21 -> V_24 . V_25 & V_128 )
V_92 -> V_125 |= 1ULL << 63 ;
}
void F_40 ( struct V_20 * V_21 )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
struct V_123 * V_124 = & V_21 -> V_24 ;
V_92 -> V_125 &= ~ ( 1ULL << V_124 -> V_126 ) ;
if ( V_21 -> V_24 . V_25 & V_127 )
V_92 -> V_125 &= ~ ( 1ULL << ( V_124 -> V_126 + 32 ) ) ;
else if ( V_21 -> V_24 . V_25 & V_128 )
V_92 -> V_125 &= ~ ( 1ULL << 63 ) ;
if ( V_92 -> V_129 )
F_41 ( V_130 , V_92 -> V_125 ) ;
V_124 -> V_82 |= V_86 ;
}
void F_42 ( void )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
if ( V_92 -> V_125 )
F_41 ( V_130 , V_92 -> V_125 ) ;
}
void F_43 ( void )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
if ( V_92 -> V_125 )
F_41 ( V_130 , 0 ) ;
}
static int F_44 ( struct V_106 * V_107 )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
unsigned long V_94 = V_92 -> V_131 [ 0 ] . V_94 ;
unsigned long V_132 , V_95 = V_92 -> V_131 [ 0 ] . V_95 ;
unsigned long V_110 = V_107 -> V_110 ;
int V_133 = 0 ;
void * V_134 ;
int V_109 ;
if ( ! V_55 . V_60 . V_135 )
return 1 ;
if ( ! V_92 -> V_136 . V_137 || ! V_94 || ! V_95 )
return 0 ;
if ( F_45 ( V_110 ) != F_45 ( V_95 ) )
return 0 ;
if ( ( V_110 - V_95 ) > V_62 )
return 0 ;
if ( V_110 == V_95 ) {
F_46 ( V_107 , V_94 ) ;
return 1 ;
}
V_109 = V_110 - V_95 ;
if ( ! F_45 ( V_110 ) ) {
int V_138 ;
T_2 * V_139 = F_47 ( V_63 ) ;
V_138 = F_48 ( V_139 , ( void V_140 * ) V_95 , V_109 ) ;
if ( V_138 != 0 )
return 0 ;
V_134 = V_139 ;
} else {
V_134 = ( void * ) V_95 ;
}
do {
struct V_141 V_141 ;
V_132 = V_95 ;
#ifdef F_49
V_133 = F_45 ( V_95 ) || ! F_50 ( V_142 ) ;
#endif
F_51 ( & V_141 , V_134 , V_109 , V_133 ) ;
F_52 ( & V_141 ) ;
if ( ! V_141 . V_143 )
break;
V_95 += V_141 . V_143 ;
V_134 += V_141 . V_143 ;
V_109 -= V_141 . V_143 ;
} while ( V_95 < V_110 );
if ( V_95 == V_110 ) {
F_46 ( V_107 , V_132 ) ;
return 1 ;
}
return 0 ;
}
static inline T_1 F_53 ( struct V_144 * V_56 )
{
if ( V_56 -> V_145 ) {
union V_146 V_147 = { . V_148 = V_56 -> V_145 } ;
return V_147 . V_149 ;
}
return 0 ;
}
static inline T_1 F_54 ( struct V_144 * V_56 )
{
T_1 V_150 = ( V_56 -> V_145 & V_151 ) >> 32 ;
if ( ( V_150 & V_152 ) && ( V_56 -> V_153 & 1 ) )
V_150 |= ( ( V_56 -> V_153 >> 24 ) & 0xff ) << V_154 ;
return V_150 ;
}
static void F_55 ( struct V_20 * V_21 ,
struct V_106 * V_155 , void * V_156 )
{
#define F_56 \
(PERF_X86_EVENT_PEBS_ST_HSW | \
PERF_X86_EVENT_PEBS_LD_HSW | \
PERF_X86_EVENT_PEBS_NA_HSW)
struct V_47 * V_92 = F_30 ( & V_47 ) ;
struct V_144 * V_56 = V_156 ;
struct V_104 V_105 ;
struct V_106 V_107 ;
T_1 V_157 ;
int V_158 , V_159 , V_160 ;
int V_161 = V_21 -> V_24 . V_25 ;
if ( ! F_57 ( V_21 ) )
return;
V_157 = V_21 -> V_117 . V_157 ;
V_160 = V_157 & V_162 ;
V_158 = V_161 & V_127 ;
V_159 = V_161 & ( V_128 | F_56 ) ;
F_32 ( & V_105 , 0 , V_21 -> V_24 . V_108 ) ;
V_105 . V_163 = V_21 -> V_24 . V_108 ;
if ( V_158 && ( V_157 & V_164 ) )
V_105 . V_165 = V_56 -> V_166 ;
if ( V_160 ) {
T_1 V_4 = V_23 ;
if ( V_158 )
V_4 = F_4 ( V_56 -> V_3 ) ;
else if ( V_159 && ( V_161 & F_56 ) )
V_4 = F_3 ( V_21 , V_56 -> V_3 ) ;
else if ( V_159 )
V_4 = F_1 ( V_56 -> V_3 ) ;
V_105 . V_167 . V_4 = V_4 ;
}
V_107 = * V_155 ;
V_107 . V_25 = V_56 -> V_25 ;
F_46 ( & V_107 , V_56 -> V_110 ) ;
V_107 . V_168 = V_56 -> V_168 ;
V_107 . V_169 = V_56 -> V_169 ;
if ( V_157 & V_170 ) {
V_107 . V_153 = V_56 -> V_153 ;
V_107 . V_171 = V_56 -> V_171 ;
V_107 . V_172 = V_56 -> V_172 ;
V_107 . V_173 = V_56 -> V_173 ;
V_107 . V_174 = V_56 -> V_174 ;
V_107 . V_175 = V_56 -> V_175 ;
V_107 . V_168 = V_56 -> V_168 ;
V_107 . V_169 = V_56 -> V_169 ;
V_107 . V_25 = V_56 -> V_25 ;
#ifndef F_58
V_107 . V_176 = V_56 -> V_176 ;
V_107 . V_177 = V_56 -> V_177 ;
V_107 . V_178 = V_56 -> V_178 ;
V_107 . V_179 = V_56 -> V_179 ;
V_107 . V_180 = V_56 -> V_180 ;
V_107 . V_181 = V_56 -> V_181 ;
V_107 . V_182 = V_56 -> V_182 ;
V_107 . V_183 = V_56 -> V_183 ;
#endif
}
if ( V_21 -> V_117 . V_118 > 1 && V_55 . V_60 . V_61 >= 2 ) {
V_107 . V_110 = V_56 -> V_184 ;
V_107 . V_25 |= V_185 ;
} else if ( V_21 -> V_117 . V_118 > 1 && F_44 ( & V_107 ) )
V_107 . V_25 |= V_185 ;
else
V_107 . V_25 &= ~ V_185 ;
if ( ( V_157 & V_186 ) &&
V_55 . V_60 . V_61 >= 1 )
V_105 . V_111 = V_56 -> V_187 ;
if ( V_55 . V_60 . V_61 >= 2 ) {
if ( ( V_157 & V_164 ) && ! V_158 )
V_105 . V_165 = F_53 ( V_56 ) ;
if ( V_157 & V_188 )
V_105 . V_150 = F_54 ( V_56 ) ;
}
if ( F_59 ( V_21 ) )
V_105 . V_189 = & V_92 -> V_136 ;
if ( F_60 ( V_21 , & V_105 , & V_107 ) )
F_61 ( V_21 , 0 ) ;
}
static void F_62 ( struct V_106 * V_155 )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_92 -> V_46 ;
struct V_20 * V_21 = V_92 -> V_96 [ 0 ] ;
struct V_190 * V_98 , * V_99 ;
int V_191 ;
if ( ! V_55 . V_81 )
return;
V_98 = (struct V_190 * ) ( unsigned long ) V_46 -> V_65 ;
V_99 = (struct V_190 * ) ( unsigned long ) V_46 -> V_66 ;
V_46 -> V_66 = V_46 -> V_65 ;
if ( ! F_63 ( 0 , V_92 -> V_192 ) )
return;
F_64 ( ! V_21 ) ;
if ( ! V_21 -> V_117 . V_118 )
return;
V_191 = V_99 - V_98 ;
if ( V_191 <= 0 )
return;
F_16 ( V_191 > 1 , L_2 , V_191 ) ;
V_98 += V_191 - 1 ;
F_55 ( V_21 , V_155 , V_98 ) ;
}
static void F_65 ( struct V_106 * V_155 )
{
struct V_47 * V_92 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_92 -> V_46 ;
struct V_20 * V_21 = NULL ;
void * V_98 , * V_99 ;
T_1 V_1 = 0 ;
int V_193 ;
if ( ! V_55 . V_81 )
return;
V_98 = (struct V_194 * ) ( unsigned long ) V_46 -> V_65 ;
V_99 = (struct V_194 * ) ( unsigned long ) V_46 -> V_66 ;
V_46 -> V_66 = V_46 -> V_65 ;
if ( F_12 ( V_98 > V_99 ) )
return;
F_16 ( V_99 - V_98 > V_55 . V_195 * V_55 . V_64 ,
L_3 ,
( long ) ( V_99 - V_98 ) / V_55 . V_64 ) ;
for (; V_98 < V_99 ; V_98 += V_55 . V_64 ) {
struct V_194 * V_196 = V_98 ;
F_66 (bit, (unsigned long *)&p->status,
x86_pmu.max_pebs_events) {
V_21 = V_92 -> V_96 [ V_193 ] ;
if ( ! F_63 ( V_193 , V_92 -> V_192 ) )
continue;
F_64 ( ! V_21 ) ;
if ( ! V_21 -> V_117 . V_118 )
continue;
if ( F_67 ( V_193 , ( unsigned long * ) & V_1 ) )
continue;
break;
}
if ( ! V_21 || V_193 >= V_55 . V_195 )
continue;
F_55 ( V_21 , V_155 , V_98 ) ;
}
}
void T_3 F_68 ( void )
{
if ( ! F_69 ( V_197 ) )
return;
V_55 . V_69 = F_69 ( V_198 ) ;
V_55 . V_56 = F_69 ( V_199 ) ;
if ( V_55 . V_56 ) {
char V_200 = V_55 . V_60 . V_135 ? '+' : '-' ;
int V_201 = V_55 . V_60 . V_61 ;
switch ( V_201 ) {
case 0 :
F_70 ( V_202 L_4 , V_200 ) ;
V_55 . V_64 = sizeof( struct V_190 ) ;
V_55 . V_203 = F_62 ;
break;
case 1 :
F_70 ( V_202 L_5 , V_200 ) ;
V_55 . V_64 = sizeof( struct V_194 ) ;
V_55 . V_203 = F_65 ;
break;
case 2 :
F_71 ( L_6 , V_200 ) ;
V_55 . V_64 = sizeof( struct V_144 ) ;
V_55 . V_203 = F_65 ;
break;
default:
F_70 ( V_202 L_7 , V_201 , V_200 ) ;
V_55 . V_56 = 0 ;
}
}
}
void F_72 ( void )
{
struct V_45 * V_46 = F_73 ( V_47 . V_46 ) ;
if ( ! V_55 . V_69 && ! V_55 . V_56 )
return;
F_41 ( V_48 , ( unsigned long ) V_46 ) ;
}
