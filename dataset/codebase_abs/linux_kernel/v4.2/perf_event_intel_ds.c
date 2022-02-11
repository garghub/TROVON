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
int V_51 ;
void * V_52 , * V_53 ;
if ( ! V_54 . V_55 )
return 0 ;
V_52 = F_11 ( V_56 , V_57 , V_50 ) ;
if ( F_12 ( ! V_52 ) )
return - V_58 ;
if ( V_54 . V_59 . V_60 < 2 ) {
V_53 = F_11 ( V_61 , V_57 , V_50 ) ;
if ( ! V_53 ) {
F_13 ( V_52 ) ;
return - V_58 ;
}
F_6 ( V_62 , V_44 ) = V_53 ;
}
V_51 = V_56 / V_54 . V_63 ;
V_46 -> V_64 = ( T_1 ) ( unsigned long ) V_52 ;
V_46 -> V_65 = V_46 -> V_64 ;
V_46 -> V_66 = V_46 -> V_64 +
V_51 * V_54 . V_63 ;
return 0 ;
}
static void F_14 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
if ( ! V_46 || ! V_54 . V_55 )
return;
F_13 ( F_6 ( V_62 , V_44 ) ) ;
F_6 ( V_62 , V_44 ) = NULL ;
F_13 ( ( void * ) ( unsigned long ) V_46 -> V_64 ) ;
V_46 -> V_64 = 0 ;
}
static int F_15 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
int V_50 = F_10 ( V_44 ) ;
int V_51 , V_67 ;
void * V_52 ;
if ( ! V_54 . V_68 )
return 0 ;
V_52 = F_11 ( V_69 , V_57 | V_70 , V_50 ) ;
if ( F_12 ( ! V_52 ) ) {
F_16 ( 1 , L_1 , V_71 ) ;
return - V_58 ;
}
V_51 = V_69 / V_72 ;
V_67 = V_51 / 16 ;
V_46 -> V_73 = ( T_1 ) ( unsigned long ) V_52 ;
V_46 -> V_74 = V_46 -> V_73 ;
V_46 -> V_75 = V_46 -> V_73 +
V_51 * V_72 ;
V_46 -> V_76 = V_46 -> V_75 -
V_67 * V_72 ;
return 0 ;
}
static void F_17 ( int V_44 )
{
struct V_45 * V_46 = F_6 ( V_47 , V_44 ) . V_46 ;
if ( ! V_46 || ! V_54 . V_68 )
return;
F_13 ( ( void * ) ( unsigned long ) V_46 -> V_73 ) ;
V_46 -> V_73 = 0 ;
}
static int F_18 ( int V_44 )
{
int V_50 = F_10 ( V_44 ) ;
struct V_45 * V_46 ;
V_46 = F_11 ( sizeof( * V_46 ) , V_57 , V_50 ) ;
if ( F_12 ( ! V_46 ) )
return - V_58 ;
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
if ( ! V_54 . V_68 && ! V_54 . V_55 )
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
int V_77 = 0 , V_78 = 0 ;
int V_44 ;
V_54 . V_79 = 0 ;
V_54 . V_80 = 0 ;
if ( ! V_54 . V_68 && ! V_54 . V_55 )
return;
if ( ! V_54 . V_68 )
V_77 = 1 ;
if ( ! V_54 . V_55 )
V_78 = 1 ;
F_21 () ;
F_23 (cpu) {
if ( F_18 ( V_44 ) ) {
V_77 = 1 ;
V_78 = 1 ;
}
if ( ! V_77 && F_15 ( V_44 ) )
V_77 = 1 ;
if ( ! V_78 && F_9 ( V_44 ) )
V_78 = 1 ;
if ( V_77 && V_78 )
break;
}
if ( V_77 ) {
F_23 (cpu)
F_17 ( V_44 ) ;
}
if ( V_78 ) {
F_23 (cpu)
F_14 ( V_44 ) ;
}
if ( V_77 && V_78 ) {
F_23 (cpu)
F_19 ( V_44 ) ;
} else {
if ( V_54 . V_68 && ! V_77 )
V_54 . V_79 = 1 ;
if ( V_54 . V_55 && ! V_78 )
V_54 . V_80 = 1 ;
F_22 (cpu)
F_5 ( V_44 ) ;
}
F_24 () ;
}
void F_26 ( T_1 V_81 )
{
unsigned long V_82 ;
V_82 = F_27 () ;
V_82 |= V_83 ;
V_82 |= V_84 ;
if ( V_81 & V_85 )
V_82 |= V_86 ;
if ( ! ( V_81 & V_87 ) )
V_82 |= V_88 ;
if ( ! ( V_81 & V_89 ) )
V_82 |= V_90 ;
F_28 ( V_82 ) ;
}
void F_29 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
unsigned long V_82 ;
if ( ! V_91 -> V_46 )
return;
V_82 = F_27 () ;
V_82 &=
~ ( V_83 | V_84 | V_86 |
V_88 | V_90 ) ;
F_28 ( V_82 ) ;
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
if ( ! V_54 . V_79 )
return 0 ;
V_97 = (struct V_92 * ) ( unsigned long ) V_46 -> V_73 ;
V_98 = (struct V_92 * ) ( unsigned long ) V_46 -> V_74 ;
if ( V_98 <= V_97 )
return 0 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_46 -> V_74 = V_46 -> V_73 ;
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
static inline void F_37 ( void )
{
struct V_105 V_106 ;
V_54 . V_114 ( & V_106 ) ;
}
void F_38 ( struct V_115 * V_116 , bool V_117 )
{
if ( ! V_117 )
F_37 () ;
}
struct V_118 * F_39 ( struct V_20 * V_21 )
{
struct V_118 * V_119 ;
if ( ! V_21 -> V_120 . V_121 )
return NULL ;
if ( V_54 . V_122 ) {
F_40 (c, x86_pmu.pebs_constraints) {
if ( ( V_21 -> V_24 . V_81 & V_119 -> V_123 ) == V_119 -> V_124 ) {
V_21 -> V_24 . V_25 |= V_119 -> V_25 ;
return V_119 ;
}
}
}
return & V_125 ;
}
static inline bool F_41 ( struct V_47 * V_91 )
{
return ( V_91 -> V_126 & ( ( 1ULL << V_127 ) - 1 ) ) ;
}
void F_42 ( struct V_20 * V_21 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_128 * V_129 = & V_21 -> V_24 ;
struct V_45 * V_46 = V_91 -> V_46 ;
bool V_130 ;
T_1 V_131 ;
V_129 -> V_81 &= ~ V_85 ;
V_130 = ! F_41 ( V_91 ) ;
V_91 -> V_126 |= 1ULL << V_129 -> V_132 ;
if ( V_21 -> V_24 . V_25 & V_133 )
V_91 -> V_126 |= 1ULL << ( V_129 -> V_132 + 32 ) ;
else if ( V_21 -> V_24 . V_25 & V_134 )
V_91 -> V_126 |= 1ULL << 63 ;
if ( V_129 -> V_25 & V_135 ) {
V_131 = V_46 -> V_66 -
V_54 . V_136 * V_54 . V_63 ;
if ( V_130 )
F_43 ( V_21 -> V_116 -> V_137 ) ;
} else {
V_131 = V_46 -> V_64 + V_54 . V_63 ;
if ( ! V_130 &&
( V_46 -> V_138 > V_131 ) )
F_44 ( V_21 -> V_116 -> V_137 ) ;
}
if ( V_129 -> V_25 & V_139 ) {
V_46 -> V_140 [ V_129 -> V_132 ] =
( T_1 ) ( - V_129 -> V_141 ) & V_54 . V_142 ;
}
if ( V_130 || V_46 -> V_138 > V_131 )
V_46 -> V_138 = V_131 ;
}
void F_45 ( struct V_20 * V_21 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_128 * V_129 = & V_21 -> V_24 ;
struct V_45 * V_46 = V_91 -> V_46 ;
V_91 -> V_126 &= ~ ( 1ULL << V_129 -> V_132 ) ;
if ( V_21 -> V_24 . V_25 & V_133 )
V_91 -> V_126 &= ~ ( 1ULL << ( V_129 -> V_132 + 32 ) ) ;
else if ( V_21 -> V_24 . V_25 & V_134 )
V_91 -> V_126 &= ~ ( 1ULL << 63 ) ;
if ( V_46 -> V_138 >
V_46 -> V_64 + V_54 . V_63 ) {
F_37 () ;
if ( ! F_41 ( V_91 ) )
F_44 ( V_21 -> V_116 -> V_137 ) ;
}
if ( V_91 -> V_143 )
F_46 ( V_144 , V_91 -> V_126 ) ;
V_129 -> V_81 |= V_85 ;
}
void F_47 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
if ( V_91 -> V_126 )
F_46 ( V_144 , V_91 -> V_126 ) ;
}
void F_48 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
if ( V_91 -> V_126 )
F_46 ( V_144 , 0 ) ;
}
static int F_49 ( struct V_105 * V_106 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
unsigned long V_93 = V_91 -> V_145 [ 0 ] . V_93 ;
unsigned long V_146 , V_94 = V_91 -> V_145 [ 0 ] . V_94 ;
unsigned long V_109 = V_106 -> V_109 ;
int V_147 = 0 ;
void * V_148 ;
int V_108 ;
if ( ! V_54 . V_59 . V_149 )
return 1 ;
if ( ! V_91 -> V_150 . V_151 || ! V_93 || ! V_94 )
return 0 ;
if ( F_50 ( V_109 ) != F_50 ( V_94 ) )
return 0 ;
if ( ( V_109 - V_94 ) > V_61 )
return 0 ;
if ( V_109 == V_94 ) {
F_51 ( V_106 , V_93 ) ;
return 1 ;
}
V_108 = V_109 - V_94 ;
if ( ! F_50 ( V_109 ) ) {
int V_152 ;
T_2 * V_153 = F_52 ( V_62 ) ;
V_152 = F_53 ( V_153 , ( void V_154 * ) V_94 , V_108 ) ;
if ( V_152 != 0 )
return 0 ;
V_148 = V_153 ;
} else {
V_148 = ( void * ) V_94 ;
}
do {
struct V_155 V_155 ;
V_146 = V_94 ;
#ifdef F_54
V_147 = F_50 ( V_94 ) || ! F_55 ( V_156 ) ;
#endif
F_56 ( & V_155 , V_148 , V_108 , V_147 ) ;
F_57 ( & V_155 ) ;
if ( ! V_155 . V_157 )
break;
V_94 += V_155 . V_157 ;
V_148 += V_155 . V_157 ;
V_108 -= V_155 . V_157 ;
} while ( V_94 < V_109 );
if ( V_94 == V_109 ) {
F_51 ( V_106 , V_146 ) ;
return 1 ;
}
return 0 ;
}
static inline T_1 F_58 ( struct V_158 * V_55 )
{
if ( V_55 -> V_159 ) {
union V_160 V_161 = { . V_162 = V_55 -> V_159 } ;
return V_161 . V_163 ;
}
return 0 ;
}
static inline T_1 F_59 ( struct V_158 * V_55 )
{
T_1 V_164 = ( V_55 -> V_159 & V_165 ) >> 32 ;
if ( ( V_164 & V_166 ) && ( V_55 -> V_167 & 1 ) )
V_164 |= ( ( V_55 -> V_167 >> 24 ) & 0xff ) << V_168 ;
return V_164 ;
}
static void F_60 ( struct V_20 * V_21 ,
struct V_105 * V_169 , void * V_170 ,
struct V_103 * V_104 ,
struct V_105 * V_106 )
{
#define F_61 \
(PERF_X86_EVENT_PEBS_ST_HSW | \
PERF_X86_EVENT_PEBS_LD_HSW | \
PERF_X86_EVENT_PEBS_NA_HSW)
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_158 * V_55 = V_170 ;
T_1 V_171 ;
int V_172 , V_173 , V_174 ;
int V_175 = V_21 -> V_24 . V_25 ;
if ( V_55 == NULL )
return;
V_171 = V_21 -> V_120 . V_171 ;
V_174 = V_171 & V_176 ;
V_172 = V_175 & V_133 ;
V_173 = V_175 & ( V_134 | F_61 ) ;
F_32 ( V_104 , 0 , V_21 -> V_24 . V_107 ) ;
V_104 -> V_177 = V_21 -> V_24 . V_107 ;
if ( V_172 && ( V_171 & V_178 ) )
V_104 -> V_179 = V_55 -> V_180 ;
if ( V_174 ) {
T_1 V_4 = V_23 ;
if ( V_172 )
V_4 = F_4 ( V_55 -> V_3 ) ;
else if ( V_173 && ( V_175 & F_61 ) )
V_4 = F_3 ( V_21 , V_55 -> V_3 ) ;
else if ( V_173 )
V_4 = F_1 ( V_55 -> V_3 ) ;
V_104 -> V_181 . V_4 = V_4 ;
}
* V_106 = * V_169 ;
V_106 -> V_25 = V_55 -> V_25 ;
F_51 ( V_106 , V_55 -> V_109 ) ;
V_106 -> V_182 = V_55 -> V_182 ;
V_106 -> V_183 = V_55 -> V_183 ;
if ( V_171 & V_184 ) {
V_106 -> V_167 = V_55 -> V_167 ;
V_106 -> V_185 = V_55 -> V_185 ;
V_106 -> V_186 = V_55 -> V_186 ;
V_106 -> V_187 = V_55 -> V_187 ;
V_106 -> V_188 = V_55 -> V_188 ;
V_106 -> V_189 = V_55 -> V_189 ;
V_106 -> V_182 = V_55 -> V_182 ;
V_106 -> V_183 = V_55 -> V_183 ;
V_106 -> V_25 = V_55 -> V_25 ;
#ifndef F_62
V_106 -> V_190 = V_55 -> V_190 ;
V_106 -> V_191 = V_55 -> V_191 ;
V_106 -> V_192 = V_55 -> V_192 ;
V_106 -> V_193 = V_55 -> V_193 ;
V_106 -> V_194 = V_55 -> V_194 ;
V_106 -> V_195 = V_55 -> V_195 ;
V_106 -> V_196 = V_55 -> V_196 ;
V_106 -> V_197 = V_55 -> V_197 ;
#endif
}
if ( V_21 -> V_120 . V_121 > 1 && V_54 . V_59 . V_60 >= 2 ) {
V_106 -> V_109 = V_55 -> V_198 ;
V_106 -> V_25 |= V_199 ;
} else if ( V_21 -> V_120 . V_121 > 1 && F_49 ( V_106 ) )
V_106 -> V_25 |= V_199 ;
else
V_106 -> V_25 &= ~ V_199 ;
if ( ( V_171 & V_200 ) &&
V_54 . V_59 . V_60 >= 1 )
V_104 -> V_110 = V_55 -> V_201 ;
if ( V_54 . V_59 . V_60 >= 2 ) {
if ( ( V_171 & V_178 ) && ! V_172 )
V_104 -> V_179 = F_58 ( V_55 ) ;
if ( V_171 & V_202 )
V_104 -> V_164 = F_59 ( V_55 ) ;
}
if ( F_63 ( V_21 ) )
V_104 -> V_203 = & V_91 -> V_150 ;
}
static inline void *
F_64 ( void * V_204 , void * V_98 , int V_205 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
void * V_97 ;
T_1 V_206 ;
if ( V_204 == NULL )
return NULL ;
for ( V_97 = V_204 ; V_97 < V_98 ; V_97 += V_54 . V_63 ) {
struct V_207 * V_208 = V_97 ;
if ( F_65 ( V_205 , ( unsigned long * ) & V_208 -> V_1 ) ) {
if ( V_54 . V_59 . V_60 >= 3 )
return V_97 ;
if ( V_208 -> V_1 == ( 1 << V_205 ) )
return V_97 ;
V_206 = V_208 -> V_1 & V_91 -> V_126 ;
V_206 &= ( 1ULL << V_127 ) - 1 ;
if ( V_206 == ( 1 << V_205 ) )
return V_97 ;
}
}
return NULL ;
}
static void F_66 ( struct V_20 * V_21 ,
struct V_105 * V_169 ,
void * V_204 , void * V_98 ,
int V_205 , int V_209 )
{
struct V_103 V_104 ;
struct V_105 V_106 ;
void * V_97 = F_64 ( V_204 , V_98 , V_205 ) ;
if ( ! F_67 ( V_21 ) &&
! ( V_21 -> V_24 . V_25 & V_139 ) )
return;
while ( V_209 > 1 ) {
F_60 ( V_21 , V_169 , V_97 , & V_104 , & V_106 ) ;
F_68 ( V_21 , & V_104 , & V_106 ) ;
V_97 += V_54 . V_63 ;
V_97 = F_64 ( V_97 , V_98 , V_205 ) ;
V_209 -- ;
}
F_60 ( V_21 , V_169 , V_97 , & V_104 , & V_106 ) ;
if ( F_69 ( V_21 , & V_104 , & V_106 ) ) {
F_70 ( V_21 , 0 ) ;
return;
}
}
static void F_71 ( struct V_105 * V_169 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_91 -> V_46 ;
struct V_20 * V_21 = V_91 -> V_95 [ 0 ] ;
struct V_210 * V_97 , * V_98 ;
int V_211 ;
if ( ! V_54 . V_80 )
return;
V_97 = (struct V_210 * ) ( unsigned long ) V_46 -> V_64 ;
V_98 = (struct V_210 * ) ( unsigned long ) V_46 -> V_65 ;
V_46 -> V_65 = V_46 -> V_64 ;
if ( ! F_65 ( 0 , V_91 -> V_212 ) )
return;
F_72 ( ! V_21 ) ;
if ( ! V_21 -> V_120 . V_121 )
return;
V_211 = ( V_98 - V_97 ) / V_54 . V_63 ;
if ( V_211 <= 0 )
return;
F_66 ( V_21 , V_169 , V_97 , V_98 , 0 , V_211 ) ;
}
static void F_73 ( struct V_105 * V_169 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_91 -> V_46 ;
struct V_20 * V_21 ;
void * V_204 , * V_97 , * V_98 ;
short V_213 [ V_127 ] = {} ;
short error [ V_127 ] = {} ;
int V_205 , V_214 ;
if ( ! V_54 . V_80 )
return;
V_204 = (struct V_207 * ) ( unsigned long ) V_46 -> V_64 ;
V_98 = (struct V_207 * ) ( unsigned long ) V_46 -> V_65 ;
V_46 -> V_65 = V_46 -> V_64 ;
if ( F_12 ( V_204 >= V_98 ) )
return;
for ( V_97 = V_204 ; V_97 < V_98 ; V_97 += V_54 . V_63 ) {
struct V_207 * V_208 = V_97 ;
if ( V_54 . V_59 . V_60 >= 3 ) {
F_74 (bit, (unsigned long *)&p->status,
MAX_PEBS_EVENTS)
V_213 [ V_205 ] ++ ;
continue;
}
V_205 = F_75 ( ( unsigned long * ) & V_208 -> V_1 ,
V_54 . V_136 ) ;
if ( V_205 >= V_54 . V_136 )
continue;
if ( ! F_65 ( V_205 , V_91 -> V_212 ) )
continue;
if ( V_208 -> V_1 != ( 1 << V_205 ) ) {
T_1 V_206 ;
V_206 = V_208 -> V_1 & V_91 -> V_126 ;
V_206 &= ( 1ULL << V_127 ) - 1 ;
if ( V_206 != ( 1 << V_205 ) ) {
F_74 ( V_214 , ( unsigned long * ) & V_206 ,
V_127 )
error [ V_214 ] ++ ;
continue;
}
}
V_213 [ V_205 ] ++ ;
}
for ( V_205 = 0 ; V_205 < V_54 . V_136 ; V_205 ++ ) {
if ( ( V_213 [ V_205 ] == 0 ) && ( error [ V_205 ] == 0 ) )
continue;
V_21 = V_91 -> V_95 [ V_205 ] ;
F_72 ( ! V_21 ) ;
F_72 ( ! V_21 -> V_120 . V_121 ) ;
if ( error [ V_205 ] )
F_76 ( V_21 , error [ V_205 ] ) ;
if ( V_213 [ V_205 ] ) {
F_66 ( V_21 , V_169 , V_204 ,
V_98 , V_205 , V_213 [ V_205 ] ) ;
}
}
}
void T_3 F_77 ( void )
{
if ( ! F_78 ( V_215 ) )
return;
V_54 . V_68 = F_78 ( V_216 ) ;
V_54 . V_55 = F_78 ( V_217 ) ;
if ( V_54 . V_55 ) {
char V_218 = V_54 . V_59 . V_149 ? '+' : '-' ;
int V_219 = V_54 . V_59 . V_60 ;
switch ( V_219 ) {
case 0 :
F_79 ( V_220 L_2 , V_218 ) ;
V_54 . V_63 = sizeof( struct V_210 ) ;
V_54 . V_114 = F_71 ;
break;
case 1 :
F_79 ( V_220 L_3 , V_218 ) ;
V_54 . V_63 = sizeof( struct V_207 ) ;
V_54 . V_114 = F_73 ;
break;
case 2 :
F_80 ( L_4 , V_218 ) ;
V_54 . V_63 = sizeof( struct V_158 ) ;
V_54 . V_114 = F_73 ;
break;
default:
F_79 ( V_220 L_5 , V_219 , V_218 ) ;
V_54 . V_55 = 0 ;
}
}
}
void F_81 ( void )
{
struct V_45 * V_46 = F_82 ( V_47 . V_46 ) ;
if ( ! V_54 . V_68 && ! V_54 . V_55 )
return;
F_46 ( V_48 , ( unsigned long ) V_46 ) ;
}
