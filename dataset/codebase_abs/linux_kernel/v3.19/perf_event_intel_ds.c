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
V_83 |= V_86 ;
if ( ! ( V_82 & V_87 ) )
V_83 |= V_88 ;
if ( ! ( V_82 & V_89 ) )
V_83 |= V_90 ;
F_28 ( V_83 ) ;
}
void F_29 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
unsigned long V_83 ;
if ( ! V_91 -> V_46 )
return;
V_83 = F_27 () ;
V_83 &=
~ ( V_84 | V_85 | V_86 |
V_88 | V_90 ) ;
F_28 ( V_83 ) ;
}
int F_31 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_91 -> V_46 ;
struct V_92 {
T_1 V_93 ;
T_1 V_94 ;
T_1 V_25 ;
};
struct V_20 * V_21 = V_91 -> V_95 [ V_96 ] ;
struct V_92 * V_97 , * V_98 ;
struct V_99 V_100 ;
struct V_101 V_102 ;
struct V_103 V_104 ;
struct V_105 V_106 ;
if ( ! V_21 )
return 0 ;
if ( ! V_55 . V_80 )
return 0 ;
V_97 = (struct V_92 * ) ( unsigned long ) V_46 -> V_74 ;
V_98 = (struct V_92 * ) ( unsigned long ) V_46 -> V_75 ;
if ( V_98 <= V_97 )
return 0 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_46 -> V_75 = V_46 -> V_74 ;
F_32 ( & V_104 , 0 , V_21 -> V_24 . V_107 ) ;
F_33 ( & V_102 , & V_104 , V_21 , & V_106 ) ;
if ( F_34 ( & V_100 , V_21 , V_102 . V_108 * ( V_98 - V_97 ) ) )
return 1 ;
for (; V_97 < V_98 ; V_97 ++ ) {
V_104 . V_109 = V_97 -> V_93 ;
V_104 . V_110 = V_97 -> V_94 ;
F_35 ( & V_100 , & V_102 , & V_104 , V_21 ) ;
}
F_36 ( & V_100 ) ;
V_21 -> V_24 . V_111 ++ ;
V_21 -> V_112 = V_113 ;
return 1 ;
}
struct V_114 * F_37 ( struct V_20 * V_21 )
{
struct V_114 * V_115 ;
if ( ! V_21 -> V_116 . V_117 )
return NULL ;
if ( V_55 . V_118 ) {
F_38 (c, x86_pmu.pebs_constraints) {
if ( ( V_21 -> V_24 . V_82 & V_115 -> V_119 ) == V_115 -> V_120 ) {
V_21 -> V_24 . V_25 |= V_115 -> V_25 ;
return V_115 ;
}
}
}
return & V_121 ;
}
void F_39 ( struct V_20 * V_21 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_122 * V_123 = & V_21 -> V_24 ;
V_123 -> V_82 &= ~ V_124 ;
V_91 -> V_125 |= 1ULL << V_123 -> V_126 ;
if ( V_21 -> V_24 . V_25 & V_127 )
V_91 -> V_125 |= 1ULL << ( V_123 -> V_126 + 32 ) ;
else if ( V_21 -> V_24 . V_25 & V_128 )
V_91 -> V_125 |= 1ULL << 63 ;
}
void F_40 ( struct V_20 * V_21 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_122 * V_123 = & V_21 -> V_24 ;
V_91 -> V_125 &= ~ ( 1ULL << V_123 -> V_126 ) ;
if ( V_21 -> V_24 . V_129 -> V_25 & V_127 )
V_91 -> V_125 &= ~ ( 1ULL << ( V_123 -> V_126 + 32 ) ) ;
else if ( V_21 -> V_24 . V_129 -> V_25 & V_128 )
V_91 -> V_125 &= ~ ( 1ULL << 63 ) ;
if ( V_91 -> V_130 )
F_41 ( V_131 , V_91 -> V_125 ) ;
V_123 -> V_82 |= V_124 ;
}
void F_42 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
if ( V_91 -> V_125 )
F_41 ( V_131 , V_91 -> V_125 ) ;
}
void F_43 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
if ( V_91 -> V_125 )
F_41 ( V_131 , 0 ) ;
}
static int F_44 ( struct V_105 * V_106 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
unsigned long V_93 = V_91 -> V_132 [ 0 ] . V_93 ;
unsigned long V_133 , V_94 = V_91 -> V_132 [ 0 ] . V_94 ;
unsigned long V_109 = V_106 -> V_109 ;
int V_134 = 0 ;
void * V_135 ;
int V_108 ;
if ( ! V_55 . V_60 . V_136 )
return 1 ;
if ( ! V_91 -> V_137 . V_138 || ! V_93 || ! V_94 )
return 0 ;
if ( F_45 ( V_109 ) != F_45 ( V_94 ) )
return 0 ;
if ( ( V_109 - V_94 ) > V_62 )
return 0 ;
if ( V_109 == V_94 ) {
F_46 ( V_106 , V_93 ) ;
return 1 ;
}
V_108 = V_109 - V_94 ;
if ( ! F_45 ( V_109 ) ) {
int V_139 ;
T_2 * V_140 = F_47 ( V_63 ) ;
V_139 = F_48 ( V_140 , ( void V_141 * ) V_94 , V_108 ) ;
if ( V_139 != 0 )
return 0 ;
V_135 = V_140 ;
} else {
V_135 = ( void * ) V_94 ;
}
do {
struct V_142 V_142 ;
V_133 = V_94 ;
#ifdef F_49
V_134 = F_45 ( V_94 ) || ! F_50 ( V_143 ) ;
#endif
F_51 ( & V_142 , V_135 , V_108 , V_134 ) ;
F_52 ( & V_142 ) ;
if ( ! V_142 . V_144 )
break;
V_94 += V_142 . V_144 ;
V_135 += V_142 . V_144 ;
V_108 -= V_142 . V_144 ;
} while ( V_94 < V_109 );
if ( V_94 == V_109 ) {
F_46 ( V_106 , V_133 ) ;
return 1 ;
}
return 0 ;
}
static inline T_1 F_53 ( struct V_145 * V_56 )
{
if ( V_56 -> V_146 ) {
union V_147 V_148 = { . V_149 = V_56 -> V_146 } ;
return V_148 . V_150 ;
}
return 0 ;
}
static inline T_1 F_54 ( struct V_145 * V_56 )
{
T_1 V_151 = ( V_56 -> V_146 & V_152 ) >> 32 ;
if ( ( V_151 & V_153 ) && ( V_56 -> V_154 & 1 ) )
V_151 |= ( ( V_56 -> V_154 >> 24 ) & 0xff ) << V_155 ;
return V_151 ;
}
static void F_55 ( struct V_20 * V_21 ,
struct V_105 * V_156 , void * V_157 )
{
#define F_56 \
(PERF_X86_EVENT_PEBS_ST_HSW | \
PERF_X86_EVENT_PEBS_LD_HSW | \
PERF_X86_EVENT_PEBS_NA_HSW)
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_145 * V_56 = V_157 ;
struct V_103 V_104 ;
struct V_105 V_106 ;
T_1 V_158 ;
int V_159 , V_160 , V_161 ;
int V_162 = V_21 -> V_24 . V_25 ;
if ( ! F_57 ( V_21 ) )
return;
V_158 = V_21 -> V_116 . V_158 ;
V_161 = V_158 & V_163 ;
V_159 = V_162 & V_127 ;
V_160 = V_162 & ( V_128 | F_56 ) ;
F_32 ( & V_104 , 0 , V_21 -> V_24 . V_107 ) ;
V_104 . V_164 = V_21 -> V_24 . V_107 ;
if ( V_159 && ( V_158 & V_165 ) )
V_104 . V_166 = V_56 -> V_167 ;
if ( V_161 ) {
T_1 V_4 = V_23 ;
if ( V_159 )
V_4 = F_4 ( V_56 -> V_3 ) ;
else if ( V_160 && ( V_162 & F_56 ) )
V_4 = F_3 ( V_21 , V_56 -> V_3 ) ;
else if ( V_160 )
V_4 = F_1 ( V_56 -> V_3 ) ;
V_104 . V_168 . V_4 = V_4 ;
}
V_106 = * V_156 ;
V_106 . V_25 = V_56 -> V_25 ;
F_46 ( & V_106 , V_56 -> V_109 ) ;
V_106 . V_169 = V_56 -> V_169 ;
V_106 . V_170 = V_56 -> V_170 ;
if ( V_158 & V_171 ) {
V_106 . V_154 = V_56 -> V_154 ;
V_106 . V_172 = V_56 -> V_172 ;
V_106 . V_173 = V_56 -> V_173 ;
V_106 . V_174 = V_56 -> V_174 ;
V_106 . V_175 = V_56 -> V_175 ;
V_106 . V_176 = V_56 -> V_176 ;
V_106 . V_169 = V_56 -> V_169 ;
V_106 . V_170 = V_56 -> V_170 ;
V_106 . V_25 = V_56 -> V_25 ;
#ifndef F_58
V_106 . V_177 = V_56 -> V_177 ;
V_106 . V_178 = V_56 -> V_178 ;
V_106 . V_179 = V_56 -> V_179 ;
V_106 . V_180 = V_56 -> V_180 ;
V_106 . V_181 = V_56 -> V_181 ;
V_106 . V_182 = V_56 -> V_182 ;
V_106 . V_183 = V_56 -> V_183 ;
V_106 . V_184 = V_56 -> V_184 ;
#endif
}
if ( V_21 -> V_116 . V_117 > 1 && V_55 . V_60 . V_61 >= 2 ) {
V_106 . V_109 = V_56 -> V_185 ;
V_106 . V_25 |= V_186 ;
} else if ( V_21 -> V_116 . V_117 > 1 && F_44 ( & V_106 ) )
V_106 . V_25 |= V_186 ;
else
V_106 . V_25 &= ~ V_186 ;
if ( ( V_158 & V_187 ) &&
V_55 . V_60 . V_61 >= 1 )
V_104 . V_110 = V_56 -> V_188 ;
if ( V_55 . V_60 . V_61 >= 2 ) {
if ( ( V_158 & V_165 ) && ! V_159 )
V_104 . V_166 = F_53 ( V_56 ) ;
if ( V_158 & V_189 )
V_104 . V_151 = F_54 ( V_56 ) ;
}
if ( F_59 ( V_21 ) )
V_104 . V_190 = & V_91 -> V_137 ;
if ( F_60 ( V_21 , & V_104 , & V_106 ) )
F_61 ( V_21 , 0 ) ;
}
static void F_62 ( struct V_105 * V_156 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_91 -> V_46 ;
struct V_20 * V_21 = V_91 -> V_95 [ 0 ] ;
struct V_191 * V_97 , * V_98 ;
int V_192 ;
if ( ! V_55 . V_81 )
return;
V_97 = (struct V_191 * ) ( unsigned long ) V_46 -> V_65 ;
V_98 = (struct V_191 * ) ( unsigned long ) V_46 -> V_66 ;
V_46 -> V_66 = V_46 -> V_65 ;
if ( ! F_63 ( 0 , V_91 -> V_193 ) )
return;
F_64 ( ! V_21 ) ;
if ( ! V_21 -> V_116 . V_117 )
return;
V_192 = V_98 - V_97 ;
if ( V_192 <= 0 )
return;
F_16 ( V_192 > 1 , L_2 , V_192 ) ;
V_97 += V_192 - 1 ;
F_55 ( V_21 , V_156 , V_97 ) ;
}
static void F_65 ( struct V_105 * V_156 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_91 -> V_46 ;
struct V_20 * V_21 = NULL ;
void * V_97 , * V_98 ;
T_1 V_1 = 0 ;
int V_194 ;
if ( ! V_55 . V_81 )
return;
V_97 = (struct V_195 * ) ( unsigned long ) V_46 -> V_65 ;
V_98 = (struct V_195 * ) ( unsigned long ) V_46 -> V_66 ;
V_46 -> V_66 = V_46 -> V_65 ;
if ( F_12 ( V_97 > V_98 ) )
return;
F_16 ( V_98 - V_97 > V_55 . V_196 * V_55 . V_64 ,
L_3 ,
( long ) ( V_98 - V_97 ) / V_55 . V_64 ) ;
for (; V_97 < V_98 ; V_97 += V_55 . V_64 ) {
struct V_195 * V_197 = V_97 ;
F_66 (bit, (unsigned long *)&p->status,
x86_pmu.max_pebs_events) {
V_21 = V_91 -> V_95 [ V_194 ] ;
if ( ! F_63 ( V_194 , V_91 -> V_193 ) )
continue;
F_64 ( ! V_21 ) ;
if ( ! V_21 -> V_116 . V_117 )
continue;
if ( F_67 ( V_194 , ( unsigned long * ) & V_1 ) )
continue;
break;
}
if ( ! V_21 || V_194 >= V_55 . V_196 )
continue;
F_55 ( V_21 , V_156 , V_97 ) ;
}
}
void T_3 F_68 ( void )
{
if ( ! F_69 ( V_198 ) )
return;
V_55 . V_69 = F_69 ( V_199 ) ;
V_55 . V_56 = F_69 ( V_200 ) ;
if ( V_55 . V_56 ) {
char V_201 = V_55 . V_60 . V_136 ? '+' : '-' ;
int V_202 = V_55 . V_60 . V_61 ;
switch ( V_202 ) {
case 0 :
F_70 ( V_203 L_4 , V_201 ) ;
V_55 . V_64 = sizeof( struct V_191 ) ;
V_55 . V_204 = F_62 ;
break;
case 1 :
F_70 ( V_203 L_5 , V_201 ) ;
V_55 . V_64 = sizeof( struct V_195 ) ;
V_55 . V_204 = F_65 ;
break;
case 2 :
F_71 ( L_6 , V_201 ) ;
V_55 . V_64 = sizeof( struct V_145 ) ;
V_55 . V_204 = F_65 ;
break;
default:
F_70 ( V_203 L_7 , V_202 , V_201 ) ;
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
