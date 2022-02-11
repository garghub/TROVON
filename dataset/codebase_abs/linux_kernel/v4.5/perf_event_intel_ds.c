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
struct V_92 * V_97 , * V_98 , * V_99 ;
struct V_100 V_101 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
unsigned long V_106 = 0 ;
struct V_107 V_108 ;
if ( ! V_21 )
return 0 ;
if ( ! V_54 . V_79 )
return 0 ;
V_98 = (struct V_92 * ) ( unsigned long ) V_46 -> V_73 ;
V_99 = (struct V_92 * ) ( unsigned long ) V_46 -> V_74 ;
if ( V_99 <= V_98 )
return 0 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_46 -> V_74 = V_46 -> V_73 ;
F_32 ( & V_105 , 0 , V_21 -> V_24 . V_109 ) ;
for ( V_97 = V_98 ; V_97 < V_99 ; V_97 ++ ) {
if ( V_21 -> V_110 . V_111 &&
( F_33 ( V_97 -> V_93 ) || F_33 ( V_97 -> V_94 ) ) )
V_106 ++ ;
}
F_34 ( & V_103 , & V_105 , V_21 , & V_108 ) ;
if ( F_35 ( & V_101 , V_21 , V_103 . V_112 *
( V_99 - V_98 - V_106 ) ) )
return 1 ;
for ( V_97 = V_98 ; V_97 < V_99 ; V_97 ++ ) {
if ( V_21 -> V_110 . V_111 &&
( F_33 ( V_97 -> V_93 ) || F_33 ( V_97 -> V_94 ) ) )
continue;
V_105 . V_113 = V_97 -> V_93 ;
V_105 . V_114 = V_97 -> V_94 ;
F_36 ( & V_101 , & V_103 , & V_105 , V_21 ) ;
}
F_37 ( & V_101 ) ;
V_21 -> V_24 . V_115 ++ ;
V_21 -> V_116 = V_117 ;
return 1 ;
}
static inline void F_38 ( void )
{
struct V_107 V_108 ;
V_54 . V_118 ( & V_108 ) ;
}
void F_39 ( struct V_119 * V_120 , bool V_121 )
{
if ( ! V_121 )
F_38 () ;
}
struct V_122 * F_40 ( struct V_20 * V_21 )
{
struct V_122 * V_123 ;
if ( ! V_21 -> V_110 . V_124 )
return NULL ;
if ( V_54 . V_125 ) {
F_41 (c, x86_pmu.pebs_constraints) {
if ( ( V_21 -> V_24 . V_81 & V_123 -> V_126 ) == V_123 -> V_127 ) {
V_21 -> V_24 . V_25 |= V_123 -> V_25 ;
return V_123 ;
}
}
}
return & V_128 ;
}
static inline bool F_42 ( struct V_47 * V_91 )
{
return ( V_91 -> V_129 & ( ( 1ULL << V_130 ) - 1 ) ) ;
}
void F_43 ( struct V_20 * V_21 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_131 * V_132 = & V_21 -> V_24 ;
struct V_45 * V_46 = V_91 -> V_46 ;
bool V_133 ;
T_1 V_134 ;
V_132 -> V_81 &= ~ V_85 ;
V_133 = ! F_42 ( V_91 ) ;
V_91 -> V_129 |= 1ULL << V_132 -> V_135 ;
if ( V_21 -> V_24 . V_25 & V_136 )
V_91 -> V_129 |= 1ULL << ( V_132 -> V_135 + 32 ) ;
else if ( V_21 -> V_24 . V_25 & V_137 )
V_91 -> V_129 |= 1ULL << 63 ;
if ( V_132 -> V_25 & V_138 ) {
V_134 = V_46 -> V_66 -
V_54 . V_139 * V_54 . V_63 ;
if ( V_133 )
F_44 ( V_21 -> V_120 -> V_140 ) ;
} else {
V_134 = V_46 -> V_64 + V_54 . V_63 ;
if ( ! V_133 &&
( V_46 -> V_141 > V_134 ) )
F_45 ( V_21 -> V_120 -> V_140 ) ;
}
if ( V_132 -> V_25 & V_142 ) {
V_46 -> V_143 [ V_132 -> V_135 ] =
( T_1 ) ( - V_132 -> V_144 ) & V_54 . V_145 ;
}
if ( V_133 || V_46 -> V_141 > V_134 )
V_46 -> V_141 = V_134 ;
}
void F_46 ( struct V_20 * V_21 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_131 * V_132 = & V_21 -> V_24 ;
struct V_45 * V_46 = V_91 -> V_46 ;
bool V_146 = V_46 -> V_141 >
V_46 -> V_64 + V_54 . V_63 ;
if ( V_146 )
F_38 () ;
V_91 -> V_129 &= ~ ( 1ULL << V_132 -> V_135 ) ;
if ( V_21 -> V_24 . V_25 & V_136 )
V_91 -> V_129 &= ~ ( 1ULL << ( V_132 -> V_135 + 32 ) ) ;
else if ( V_21 -> V_24 . V_25 & V_137 )
V_91 -> V_129 &= ~ ( 1ULL << 63 ) ;
if ( V_146 && ! F_42 ( V_91 ) )
F_45 ( V_21 -> V_120 -> V_140 ) ;
if ( V_91 -> V_147 )
F_47 ( V_148 , V_91 -> V_129 ) ;
V_132 -> V_81 |= V_85 ;
}
void F_48 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
if ( V_91 -> V_129 )
F_47 ( V_148 , V_91 -> V_129 ) ;
}
void F_49 ( void )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
if ( V_91 -> V_129 )
F_47 ( V_148 , 0 ) ;
}
static int F_50 ( struct V_107 * V_108 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
unsigned long V_93 = V_91 -> V_149 [ 0 ] . V_93 ;
unsigned long V_150 , V_94 = V_91 -> V_149 [ 0 ] . V_94 ;
unsigned long V_113 = V_108 -> V_113 ;
int V_151 = 0 ;
void * V_152 ;
int V_112 ;
if ( ! V_54 . V_59 . V_153 )
return 1 ;
if ( ! V_91 -> V_154 . V_155 || ! V_93 || ! V_94 )
return 0 ;
if ( F_33 ( V_113 ) != F_33 ( V_94 ) )
return 0 ;
if ( ( V_113 - V_94 ) > V_61 )
return 0 ;
if ( V_113 == V_94 ) {
F_51 ( V_108 , V_93 ) ;
return 1 ;
}
V_112 = V_113 - V_94 ;
if ( ! F_33 ( V_113 ) ) {
int V_156 ;
T_2 * V_157 = F_52 ( V_62 ) ;
V_156 = F_53 ( V_157 , ( void V_158 * ) V_94 , V_112 ) ;
if ( V_156 != 0 )
return 0 ;
V_152 = V_157 ;
} else {
V_152 = ( void * ) V_94 ;
}
do {
struct V_159 V_159 ;
V_150 = V_94 ;
#ifdef F_54
V_151 = F_33 ( V_94 ) || ! F_55 ( V_160 ) ;
#endif
F_56 ( & V_159 , V_152 , V_112 , V_151 ) ;
F_57 ( & V_159 ) ;
if ( ! V_159 . V_161 )
break;
V_94 += V_159 . V_161 ;
V_152 += V_159 . V_161 ;
V_112 -= V_159 . V_161 ;
} while ( V_94 < V_113 );
if ( V_94 == V_113 ) {
F_51 ( V_108 , V_150 ) ;
return 1 ;
}
return 0 ;
}
static inline T_1 F_58 ( struct V_162 * V_55 )
{
if ( V_55 -> V_163 ) {
union V_164 V_165 = { . V_166 = V_55 -> V_163 } ;
return V_165 . V_167 ;
}
return 0 ;
}
static inline T_1 F_59 ( struct V_162 * V_55 )
{
T_1 V_168 = ( V_55 -> V_163 & V_169 ) >> 32 ;
if ( ( V_168 & V_170 ) && ( V_55 -> V_171 & 1 ) )
V_168 |= ( ( V_55 -> V_171 >> 24 ) & 0xff ) << V_172 ;
return V_168 ;
}
static void F_60 ( struct V_20 * V_21 ,
struct V_107 * V_173 , void * V_174 ,
struct V_104 * V_105 ,
struct V_107 * V_108 )
{
#define F_61 \
(PERF_X86_EVENT_PEBS_ST_HSW | \
PERF_X86_EVENT_PEBS_LD_HSW | \
PERF_X86_EVENT_PEBS_NA_HSW)
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_162 * V_55 = V_174 ;
T_1 V_175 ;
int V_176 , V_177 , V_178 ;
int V_179 = V_21 -> V_24 . V_25 ;
if ( V_55 == NULL )
return;
V_175 = V_21 -> V_110 . V_175 ;
V_178 = V_175 & V_180 ;
V_176 = V_179 & V_136 ;
V_177 = V_179 & ( V_137 | F_61 ) ;
F_32 ( V_105 , 0 , V_21 -> V_24 . V_109 ) ;
V_105 -> V_181 = V_21 -> V_24 . V_109 ;
if ( V_176 && ( V_175 & V_182 ) )
V_105 -> V_183 = V_55 -> V_184 ;
if ( V_178 ) {
T_1 V_4 = V_23 ;
if ( V_176 )
V_4 = F_4 ( V_55 -> V_3 ) ;
else if ( V_177 && ( V_179 & F_61 ) )
V_4 = F_3 ( V_21 , V_55 -> V_3 ) ;
else if ( V_177 )
V_4 = F_1 ( V_55 -> V_3 ) ;
V_105 -> V_185 . V_4 = V_4 ;
}
* V_108 = * V_173 ;
V_108 -> V_25 = V_55 -> V_25 ;
F_51 ( V_108 , V_55 -> V_113 ) ;
V_108 -> V_186 = V_55 -> V_186 ;
V_108 -> V_187 = V_55 -> V_187 ;
if ( V_175 & V_188 ) {
V_108 -> V_171 = V_55 -> V_171 ;
V_108 -> V_189 = V_55 -> V_189 ;
V_108 -> V_190 = V_55 -> V_190 ;
V_108 -> V_191 = V_55 -> V_191 ;
V_108 -> V_192 = V_55 -> V_192 ;
V_108 -> V_193 = V_55 -> V_193 ;
V_108 -> V_186 = V_55 -> V_186 ;
V_108 -> V_187 = V_55 -> V_187 ;
V_108 -> V_25 = V_55 -> V_25 ;
#ifndef F_62
V_108 -> V_194 = V_55 -> V_194 ;
V_108 -> V_195 = V_55 -> V_195 ;
V_108 -> V_196 = V_55 -> V_196 ;
V_108 -> V_197 = V_55 -> V_197 ;
V_108 -> V_198 = V_55 -> V_198 ;
V_108 -> V_199 = V_55 -> V_199 ;
V_108 -> V_200 = V_55 -> V_200 ;
V_108 -> V_201 = V_55 -> V_201 ;
#endif
}
if ( V_21 -> V_110 . V_124 > 1 && V_54 . V_59 . V_60 >= 2 ) {
V_108 -> V_113 = V_55 -> V_202 ;
V_108 -> V_25 |= V_203 ;
} else if ( V_21 -> V_110 . V_124 > 1 && F_50 ( V_108 ) )
V_108 -> V_25 |= V_203 ;
else
V_108 -> V_25 &= ~ V_203 ;
if ( ( V_175 & V_204 ) &&
V_54 . V_59 . V_60 >= 1 )
V_105 -> V_114 = V_55 -> V_205 ;
if ( V_54 . V_59 . V_60 >= 2 ) {
if ( ( V_175 & V_182 ) && ! V_176 )
V_105 -> V_183 = F_58 ( V_55 ) ;
if ( V_175 & V_206 )
V_105 -> V_168 = F_59 ( V_55 ) ;
}
if ( V_54 . V_59 . V_60 >= 3 &&
V_21 -> V_110 . V_207 == 0 )
V_105 -> time = F_63 ( V_55 -> V_208 ) ;
if ( F_64 ( V_21 ) )
V_105 -> V_209 = & V_91 -> V_154 ;
}
static inline void *
F_65 ( void * V_98 , void * V_99 , int V_210 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
void * V_97 ;
T_1 V_211 ;
if ( V_54 . V_59 . V_60 < 1 )
return V_98 ;
if ( V_98 == NULL )
return NULL ;
for ( V_97 = V_98 ; V_97 < V_99 ; V_97 += V_54 . V_63 ) {
struct V_212 * V_213 = V_97 ;
if ( F_66 ( V_210 , ( unsigned long * ) & V_213 -> V_1 ) ) {
if ( V_54 . V_59 . V_60 >= 3 )
return V_97 ;
if ( V_213 -> V_1 == ( 1 << V_210 ) )
return V_97 ;
V_211 = V_213 -> V_1 & V_91 -> V_129 ;
V_211 &= ( 1ULL << V_130 ) - 1 ;
if ( V_211 == ( 1 << V_210 ) )
return V_97 ;
}
}
return NULL ;
}
static void F_67 ( struct V_20 * V_21 ,
struct V_107 * V_173 ,
void * V_98 , void * V_99 ,
int V_210 , int V_214 )
{
struct V_104 V_105 ;
struct V_107 V_108 ;
void * V_97 = F_65 ( V_98 , V_99 , V_210 ) ;
if ( ! F_68 ( V_21 ) &&
! ( V_21 -> V_24 . V_25 & V_142 ) )
return;
while ( V_214 > 1 ) {
F_60 ( V_21 , V_173 , V_97 , & V_105 , & V_108 ) ;
F_69 ( V_21 , & V_105 , & V_108 ) ;
V_97 += V_54 . V_63 ;
V_97 = F_65 ( V_97 , V_99 , V_210 ) ;
V_214 -- ;
}
F_60 ( V_21 , V_173 , V_97 , & V_105 , & V_108 ) ;
if ( F_70 ( V_21 , & V_105 , & V_108 ) ) {
F_71 ( V_21 , 0 ) ;
return;
}
}
static void F_72 ( struct V_107 * V_173 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_91 -> V_46 ;
struct V_20 * V_21 = V_91 -> V_95 [ 0 ] ;
struct V_215 * V_97 , * V_99 ;
int V_216 ;
if ( ! V_54 . V_80 )
return;
V_97 = (struct V_215 * ) ( unsigned long ) V_46 -> V_64 ;
V_99 = (struct V_215 * ) ( unsigned long ) V_46 -> V_65 ;
V_46 -> V_65 = V_46 -> V_64 ;
if ( ! F_66 ( 0 , V_91 -> V_217 ) )
return;
F_73 ( ! V_21 ) ;
if ( ! V_21 -> V_110 . V_124 )
return;
V_216 = V_99 - V_97 ;
if ( V_216 <= 0 )
return;
F_67 ( V_21 , V_173 , V_97 , V_99 , 0 , V_216 ) ;
}
static void F_74 ( struct V_107 * V_173 )
{
struct V_47 * V_91 = F_30 ( & V_47 ) ;
struct V_45 * V_46 = V_91 -> V_46 ;
struct V_20 * V_21 ;
void * V_98 , * V_97 , * V_99 ;
short V_218 [ V_130 ] = {} ;
short error [ V_130 ] = {} ;
int V_210 , V_219 ;
if ( ! V_54 . V_80 )
return;
V_98 = (struct V_212 * ) ( unsigned long ) V_46 -> V_64 ;
V_99 = (struct V_212 * ) ( unsigned long ) V_46 -> V_65 ;
V_46 -> V_65 = V_46 -> V_64 ;
if ( F_12 ( V_98 >= V_99 ) )
return;
for ( V_97 = V_98 ; V_97 < V_99 ; V_97 += V_54 . V_63 ) {
struct V_212 * V_213 = V_97 ;
T_1 V_211 ;
if ( V_54 . V_59 . V_60 >= 3 ) {
F_75 (bit, (unsigned long *)&p->status,
MAX_PEBS_EVENTS)
V_218 [ V_210 ] ++ ;
continue;
}
V_211 = V_213 -> V_1 & V_91 -> V_129 ;
V_211 &= ( 1ULL << V_54 . V_139 ) - 1 ;
if ( ! V_211 && V_91 -> V_129 &&
! ( V_91 -> V_129 & ( V_91 -> V_129 - 1 ) ) )
V_211 = V_91 -> V_129 ;
V_210 = F_76 ( ( unsigned long * ) & V_211 ,
V_54 . V_139 ) ;
if ( V_210 >= V_54 . V_139 )
continue;
if ( V_213 -> V_1 != ( 1ULL << V_210 ) ) {
F_75 ( V_219 , ( unsigned long * ) & V_211 ,
V_54 . V_139 )
error [ V_219 ] ++ ;
continue;
}
V_218 [ V_210 ] ++ ;
}
for ( V_210 = 0 ; V_210 < V_54 . V_139 ; V_210 ++ ) {
if ( ( V_218 [ V_210 ] == 0 ) && ( error [ V_210 ] == 0 ) )
continue;
V_21 = V_91 -> V_95 [ V_210 ] ;
F_73 ( ! V_21 ) ;
F_73 ( ! V_21 -> V_110 . V_124 ) ;
if ( error [ V_210 ] )
F_77 ( V_21 , error [ V_210 ] ) ;
if ( V_218 [ V_210 ] ) {
F_67 ( V_21 , V_173 , V_98 ,
V_99 , V_210 , V_218 [ V_210 ] ) ;
}
}
}
void T_3 F_78 ( void )
{
if ( ! F_79 ( V_220 ) )
return;
V_54 . V_68 = F_79 ( V_221 ) ;
V_54 . V_55 = F_79 ( V_222 ) ;
if ( V_54 . V_55 ) {
char V_223 = V_54 . V_59 . V_153 ? '+' : '-' ;
int V_224 = V_54 . V_59 . V_60 ;
switch ( V_224 ) {
case 0 :
F_80 ( V_225 L_2 , V_223 ) ;
V_54 . V_63 = sizeof( struct V_215 ) ;
V_54 . V_118 = F_72 ;
break;
case 1 :
F_80 ( V_225 L_3 , V_223 ) ;
V_54 . V_63 = sizeof( struct V_212 ) ;
V_54 . V_118 = F_74 ;
break;
case 2 :
F_81 ( L_4 , V_223 ) ;
V_54 . V_63 = sizeof( struct V_226 ) ;
V_54 . V_118 = F_74 ;
break;
case 3 :
F_81 ( L_5 , V_223 ) ;
V_54 . V_63 =
sizeof( struct V_162 ) ;
V_54 . V_118 = F_74 ;
V_54 . V_227 |= V_228 ;
break;
default:
F_80 ( V_225 L_6 , V_224 , V_223 ) ;
V_54 . V_55 = 0 ;
}
}
}
void F_82 ( void )
{
struct V_45 * V_46 = F_83 ( V_47 . V_46 ) ;
if ( ! V_54 . V_68 && ! V_54 . V_55 )
return;
F_47 ( V_48 , ( unsigned long ) V_46 ) ;
}
