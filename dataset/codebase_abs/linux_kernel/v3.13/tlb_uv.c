static int T_1
F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static void
F_2 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
if ( V_6 ) {
F_3 ( L_1 ) ;
return;
}
V_2 = 0 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_2 = 0 ;
}
F_3 ( L_2 ) ;
return;
}
static void
F_6 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
V_2 = 1 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_2 = 1 ;
}
F_3 ( L_3 ) ;
return;
}
static int T_1 F_7 ( int V_7 )
{
int V_8 , V_9 ;
F_8 (node) {
V_9 = F_9 ( V_8 ) ;
if ( V_7 == V_9 )
return V_8 ;
}
return - 1 ;
}
static int T_1 F_10 ( int V_7 )
{
int V_3 ;
F_4 (cpu)
if ( V_7 == F_11 ( V_3 ) )
return F_5 ( V_10 , V_3 ) ;
return - 1 ;
}
static void F_12 ( struct V_11 * V_12 , struct V_4 * V_5 ,
int V_13 )
{
unsigned long V_14 ;
struct V_15 * V_16 ;
V_16 = V_12 -> V_16 ;
if ( ! V_16 -> V_17 && V_13 ) {
V_14 = ( V_16 -> V_18 << V_19 ) | V_16 -> V_18 ;
F_13 ( V_14 ) ;
}
V_16 -> V_20 = 1 ;
V_16 -> V_18 = 0 ;
}
static void F_14 ( struct V_11 * V_12 ,
struct V_4 * V_5 )
{
int V_21 ;
int V_22 = 0 ;
unsigned long V_23 ;
unsigned long V_24 = 0 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_15 * V_25 ;
struct V_26 * V_27 = V_5 -> V_28 ;
V_27 -> V_29 ++ ;
for ( V_25 = V_16 + 1 , V_21 = 0 ; V_21 < V_30 ; V_25 ++ , V_21 ++ ) {
if ( V_25 > V_12 -> V_31 )
V_25 = V_12 -> V_32 ;
if ( V_25 == V_16 )
break;
if ( ( V_25 -> V_20 == 0 ) && ( V_25 -> V_17 == 0 ) &&
( V_25 -> V_18 ) && ( ( V_25 -> V_18 &
V_16 -> V_18 ) == 0 ) &&
( V_25 -> V_33 == V_16 -> V_33 ) &&
( V_25 -> V_34 != V_35 ) ) {
V_24 = F_15 () ;
V_23 = V_25 -> V_18 ;
if ( V_24 & ( V_23 << V_19 ) ) {
unsigned long V_36 ;
V_25 -> V_17 = 1 ;
V_27 -> V_37 ++ ;
V_22 ++ ;
V_36 = ( V_23 << V_19 ) | V_23 ;
F_13 ( V_36 ) ;
}
}
}
if ( ! V_22 )
V_27 -> V_38 ++ ;
}
static void F_16 ( struct V_11 * V_12 , struct V_4 * V_5 ,
int V_13 )
{
short V_39 = 0 ;
short * V_40 ;
struct atomic_short * V_41 ;
struct V_26 * V_27 = V_5 -> V_28 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_4 * V_42 = V_5 -> V_43 ;
if ( V_16 -> V_44 == V_45 ) {
F_17 () ;
V_27 -> V_46 ++ ;
} else {
F_18 ( V_16 -> V_44 ) ;
V_27 -> V_47 ++ ;
}
V_27 -> V_48 ++ ;
if ( V_16 -> V_34 == V_49 && V_5 == V_5 -> V_50 )
F_14 ( V_12 , V_5 ) ;
V_40 = & V_42 -> V_51 [ V_12 -> V_52 ] ;
V_41 = (struct atomic_short * ) V_40 ;
V_39 = F_19 ( 1 , V_41 ) ;
if ( V_39 == V_5 -> V_53 ) {
int V_54 ;
* V_40 = 0 ;
V_41 = (struct atomic_short * ) & V_16 -> V_55 ;
V_54 = F_19 ( V_39 , V_41 ) ;
if ( V_54 == V_5 -> V_56 ) {
F_12 ( V_12 , V_5 , V_13 ) ;
}
}
return;
}
static int F_20 ( int V_57 , struct V_4 * V_42 )
{
int V_3 ;
struct V_58 * V_59 ;
F_4 (cpu) {
V_59 = & V_42 -> V_60 [ V_3 ] ;
if ( V_57 == V_59 -> V_57 )
return V_3 ;
}
return - 1 ;
}
static void F_21 ( void * V_61 )
{
int V_21 ;
struct V_4 * V_5 = & F_5 ( V_4 , F_22 () ) ;
struct V_62 * V_63 = (struct V_62 * ) V_61 ;
struct V_15 * V_16 ;
struct V_26 * V_27 = V_5 -> V_28 ;
V_27 -> V_64 ++ ;
for ( V_16 = V_5 -> V_32 , V_21 = 0 ; V_21 < V_30 ; V_16 ++ , V_21 ++ ) {
unsigned long V_23 ;
if ( ( V_16 -> V_20 == 0 ) &&
( V_16 -> V_17 == 0 ) &&
( V_16 -> V_33 == V_63 -> V_65 ) &&
( V_16 -> V_18 ) &&
( V_16 -> V_34 != V_35 ) ) {
unsigned long V_24 ;
unsigned long V_36 ;
V_16 -> V_17 = 1 ;
V_24 = F_15 () ;
V_23 = V_16 -> V_18 ;
V_36 = ( V_23 << V_19 ) | V_23 ;
if ( V_24 & V_23 ) {
V_27 -> V_66 ++ ;
F_13 ( V_36 ) ;
}
}
}
return;
}
static void F_23 ( struct V_67 * V_68 , struct V_4 * V_5 )
{
int V_57 ;
int V_69 ;
int V_70 ;
int V_65 = V_5 -> V_3 ;
T_2 * V_71 = V_5 -> V_50 -> V_72 ;
struct V_4 * V_42 = V_5 -> V_43 ;
struct V_62 V_62 ;
V_62 . V_65 = V_65 ;
F_24 ( * V_71 ) ;
V_70 = sizeof( struct V_67 ) * V_73 ;
for ( V_57 = 0 ; V_57 < V_70 ; V_57 ++ ) {
int V_3 ;
if ( ! F_25 ( V_57 , V_68 ) )
continue;
V_69 = V_57 + V_5 -> V_74 ;
V_3 = F_20 ( V_69 , V_42 ) ;
F_26 ( V_3 , * V_71 ) ;
}
F_27 ( V_71 , F_21 , ( void * ) & V_62 , 1 ) ;
return;
}
static inline unsigned long F_28 ( unsigned long long V_75 )
{
unsigned long long V_76 ;
unsigned long V_77 ;
int V_3 = F_22 () ;
V_76 = ( V_75 * F_5 ( V_78 , V_3 ) ) >> V_79 ;
V_77 = V_76 / 1000 ;
return V_77 ;
}
static inline void F_29 ( struct V_4 * V_80 )
{
F_19 ( 1 , (struct atomic_short * ) & V_80 -> V_81 ) ;
}
static inline void F_30 ( struct V_4 * V_80 )
{
F_19 ( - 1 , (struct atomic_short * ) & V_80 -> V_81 ) ;
}
static unsigned long F_31 ( unsigned long V_82 , int V_83 )
{
unsigned long V_84 ;
V_84 = F_32 ( V_82 ) ;
V_84 >>= V_83 ;
V_84 &= V_85 ;
return V_84 ;
}
static int F_33 ( struct V_86 * V_86 ,
unsigned long V_82 , int V_83 ,
struct V_4 * V_5 , long V_87 )
{
unsigned long V_84 ;
T_3 V_88 ;
struct V_26 * V_27 = V_5 -> V_28 ;
V_84 = F_31 ( V_82 , V_83 ) ;
while ( ( V_84 != V_89 ) ) {
if ( V_84 == V_90 ) {
V_27 -> V_91 ++ ;
return V_92 ;
} else if ( V_84 == V_93 ) {
V_27 -> V_94 ++ ;
V_88 = F_34 () ;
if ( F_28 ( V_88 - V_5 -> V_95 ) < V_96 ) {
V_5 -> V_97 = 0 ;
return V_98 ;
}
V_5 -> V_97 = 0 ;
return V_99 ;
} else {
F_35 () ;
}
V_84 = F_31 ( V_82 , V_83 ) ;
}
V_5 -> V_97 ++ ;
return V_100 ;
}
static unsigned long F_36 ( unsigned long V_101 , int V_102 , int V_103 )
{
unsigned long V_84 ;
V_84 =
( ( F_37 ( V_101 ) >> V_102 ) & V_85 ) << 1 ;
return V_84 ;
}
int F_38 ( struct V_4 * V_5 )
{
int V_3 = V_5 -> V_104 ;
int V_82 ;
int V_83 ;
V_82 = V_105 ;
V_83 = V_3 * V_106 ;
return ( ( ( ( ( F_37 ( V_82 ) >> V_83 ) &
V_85 ) ) << 1 ) == V_107 ) ;
}
int F_39 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_28 ;
V_27 -> V_108 ++ ;
V_5 -> V_109 = 1 ;
return V_92 ;
}
static int F_40 ( struct V_86 * V_86 ,
unsigned long V_82 , int V_83 ,
struct V_4 * V_5 , long V_87 )
{
unsigned long V_110 ;
T_3 V_88 ;
int V_103 = V_5 -> V_104 ;
long V_111 = 0 ;
struct V_26 * V_27 = V_5 -> V_28 ;
V_110 = F_36 ( V_82 , V_83 , V_103 ) ;
while ( V_110 != V_112 ) {
if ( ( V_110 == V_113 ) ) {
V_27 -> V_91 ++ ;
return V_92 ;
} else if ( V_110 == V_114 ) {
V_88 = F_34 () ;
if ( F_28 ( V_88 - V_5 -> V_95 ) < V_96 ) {
V_5 -> V_97 = 0 ;
V_27 -> V_115 ++ ;
return V_92 ;
}
V_27 -> V_94 ++ ;
V_5 -> V_97 = 0 ;
return V_92 ;
} else {
V_111 ++ ;
if ( V_111 > 1000000 ) {
V_111 = 0 ;
V_88 = F_34 () ;
if ( ( V_88 - V_5 -> V_95 ) >
V_5 -> V_116 )
return F_39 ( V_5 ) ;
}
F_35 () ;
}
V_110 = F_36 ( V_82 , V_83 ,
V_103 ) ;
}
V_5 -> V_97 ++ ;
return V_100 ;
}
static int F_41 ( struct V_86 * V_86 ,
struct V_4 * V_5 , long V_87 )
{
int V_83 ;
unsigned long V_82 ;
int V_103 = V_5 -> V_104 ;
if ( V_103 < V_117 ) {
V_82 = V_105 ;
V_83 = V_103 * V_106 ;
} else {
V_82 = V_118 ;
V_83 = ( ( V_103 - V_117 ) * V_106 ) ;
}
if ( V_5 -> V_119 == 1 )
return F_33 ( V_86 , V_82 , V_83 ,
V_5 , V_87 ) ;
else
return F_40 ( V_86 , V_82 , V_83 ,
V_5 , V_87 ) ;
}
static inline T_3 F_42 ( unsigned long V_120 )
{
unsigned long V_76 ;
T_3 V_75 ;
V_76 = V_120 * 1000000000 ;
V_75 = ( V_76 << V_79 ) / ( F_5 ( V_78 , F_22 () ) ) ;
return V_75 ;
}
static void F_43 ( struct V_86 * V_86 ,
struct V_4 * V_5 ,
struct V_4 * V_80 , struct V_26 * V_27 )
{
F_44 ( V_5 -> V_121 ) ;
V_5 -> V_122 ++ ;
if ( V_5 -> V_122 >= V_5 -> V_123 ) {
V_5 -> V_122 = 0 ;
F_29 ( V_80 ) ;
F_45 ( & V_80 -> V_124 ) ;
F_23 ( & V_86 -> V_68 , V_5 ) ;
F_46 ( & V_80 -> V_124 ) ;
F_30 ( V_80 ) ;
V_5 -> V_125 ++ ;
V_27 -> V_126 ++ ;
}
}
static void F_47 ( struct V_86 * V_86 ,
struct V_4 * V_5 , struct V_4 * V_80 ,
struct V_26 * V_27 )
{
V_80 -> V_127 = 1 ;
V_5 -> V_128 ++ ;
if ( V_5 -> V_128 >= V_5 -> V_129 ) {
V_5 -> V_128 = 0 ;
F_29 ( V_80 ) ;
F_45 ( & V_80 -> V_124 ) ;
F_23 ( & V_86 -> V_68 , V_5 ) ;
F_46 ( & V_80 -> V_124 ) ;
F_30 ( V_80 ) ;
V_5 -> V_125 ++ ;
V_27 -> V_130 ++ ;
}
}
static void F_48 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
int V_131 ;
struct V_4 * V_132 ;
struct V_4 * V_80 ;
T_3 V_133 ;
V_80 = V_5 -> V_50 ;
F_45 ( & V_80 -> V_134 ) ;
if ( ! V_5 -> V_135 ) {
V_27 -> V_136 ++ ;
V_133 = F_34 () ;
F_4 (tcpu) {
V_132 = & F_5 ( V_4 , V_131 ) ;
if ( V_132 -> V_50 == V_80 ) {
V_132 -> V_135 = 1 ;
V_132 -> V_137 =
V_133 + V_5 -> V_138 ;
}
}
}
F_46 ( & V_80 -> V_134 ) ;
}
static void F_49 ( int V_27 , struct V_4 * V_5 ,
struct V_4 * V_80 )
{
V_5 -> V_122 = 0 ;
V_5 -> V_128 = 0 ;
if ( V_27 != V_100 )
return;
if ( V_5 -> V_97 <= V_5 -> V_139 )
return;
if ( V_80 -> V_127 >= V_80 -> V_140 )
return;
V_80 -> V_127 ++ ;
}
static void F_50 ( T_3 V_141 , T_3 V_142 ,
struct V_4 * V_5 , struct V_26 * V_27 ,
int V_143 , int V_87 )
{
T_3 V_144 ;
if ( V_142 > V_141 ) {
V_144 = V_142 - V_141 ;
V_27 -> V_145 += V_144 ;
if ( ( V_143 == V_100 ) && ( V_87 == 1 ) ) {
V_5 -> V_146 ++ ;
V_5 -> V_147 += V_144 ;
if ( ( V_144 > V_148 ) &&
( V_5 -> V_146 > V_5 -> V_149 ) &&
( ( V_5 -> V_147 / V_5 -> V_146 ) >
V_148 ) ) {
V_27 -> V_150 ++ ;
F_48 ( V_5 , V_27 ) ;
}
}
} else
V_27 -> V_151 -- ;
if ( V_143 == V_100 && V_87 > 1 )
V_27 -> V_152 ++ ;
else if ( V_143 == V_92 ) {
V_27 -> V_153 ++ ;
if ( F_34 () > V_5 -> V_154 )
V_5 -> V_155 = 0 ;
V_5 -> V_155 ++ ;
if ( V_5 -> V_155 == 1 )
V_5 -> V_154 = F_34 () + V_5 -> V_138 ;
if ( V_5 -> V_155 > V_5 -> V_156 ) {
F_48 ( V_5 , V_27 ) ;
V_27 -> V_157 ++ ;
}
}
}
static void F_51 ( struct V_4 * V_80 , struct V_26 * V_27 )
{
T_4 * V_158 = & V_80 -> V_159 ;
T_5 * V_160 ;
V_160 = & V_80 -> V_161 ;
if ( ! F_52 ( V_158 , V_160 , V_80 -> V_127 ) ) {
V_27 -> V_162 ++ ;
do {
F_35 () ;
} while ( ! F_52 ( V_158 , V_160 , V_80 -> V_127 ) );
}
}
static void F_53 ( int V_143 , struct V_86 * V_86 ,
struct V_4 * V_5 , struct V_4 * V_80 ,
struct V_26 * V_27 )
{
if ( V_143 == V_98 )
F_43 ( V_86 , V_5 , V_80 , V_27 ) ;
else if ( V_143 == V_99 )
F_47 ( V_86 , V_5 , V_80 , V_27 ) ;
}
int F_54 ( struct V_72 * V_163 , struct V_4 * V_5 ,
struct V_86 * V_86 )
{
int V_164 = 0 ;
int V_165 = 0 ;
int V_166 = 0 ;
long V_87 = 0 ;
unsigned long V_167 ;
T_3 V_141 ;
T_3 V_142 ;
struct V_26 * V_27 = V_5 -> V_28 ;
struct V_4 * V_80 = V_5 -> V_50 ;
struct V_168 * V_169 = NULL ;
struct V_170 * V_171 = NULL ;
if ( V_5 -> V_119 == 1 ) {
V_166 = 1 ;
F_51 ( V_80 , V_27 ) ;
}
while ( V_80 -> V_81 )
F_35 () ;
V_141 = F_34 () ;
if ( V_166 )
V_169 = & V_86 -> V_172 . V_169 ;
else
V_171 = & V_86 -> V_172 . V_171 ;
do {
if ( V_87 == 0 ) {
if ( V_166 )
V_169 -> V_34 = V_173 ;
else
V_171 -> V_34 = V_173 ;
V_164 = V_5 -> V_174 ++ ;
} else {
if ( V_166 )
V_169 -> V_34 = V_49 ;
else
V_171 -> V_34 = V_49 ;
V_27 -> V_175 ++ ;
}
if ( V_166 )
V_169 -> V_176 = V_164 ;
else
V_171 -> V_176 = V_164 ;
V_167 = ( 1UL << V_177 ) | V_5 -> V_104 ;
V_5 -> V_95 = F_34 () ;
F_55 ( V_167 ) ;
V_87 ++ ;
V_165 = F_41 ( V_86 , V_5 , V_87 ) ;
F_53 ( V_165 , V_86 , V_5 , V_80 , V_27 ) ;
if ( V_5 -> V_125 >= V_5 -> V_178 ) {
V_5 -> V_125 = 0 ;
V_27 -> V_179 ++ ;
V_165 = V_92 ;
break;
}
F_35 () ;
} while ( ( V_165 == V_98 ) ||
( V_165 == V_99 ) );
V_142 = F_34 () ;
F_49 ( V_165 , V_5 , V_80 ) ;
while ( V_80 -> V_81 )
F_35 () ;
F_56 ( & V_80 -> V_161 ) ;
F_50 ( V_141 , V_142 , V_5 , V_27 , V_165 , V_87 ) ;
if ( V_165 == V_92 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
int V_131 ;
struct V_4 * V_132 ;
struct V_4 * V_80 ;
V_80 = V_5 -> V_50 ;
F_45 ( & V_80 -> V_134 ) ;
if ( V_5 -> V_135 && ( F_34 () >= V_5 -> V_137 ) ) {
V_27 -> V_180 ++ ;
F_4 (tcpu) {
V_132 = & F_5 ( V_4 , V_131 ) ;
if ( V_132 -> V_50 == V_80 ) {
V_132 -> V_135 = 0 ;
V_132 -> V_146 = 0 ;
V_132 -> V_147 = 0 ;
V_132 -> V_155 = 0 ;
}
}
F_46 ( & V_80 -> V_134 ) ;
return 0 ;
}
F_46 ( & V_80 -> V_134 ) ;
return - 1 ;
}
static void F_58 ( struct V_26 * V_27 , int V_181 , int V_182 ,
int V_183 , struct V_86 * V_86 )
{
V_27 -> V_151 ++ ;
V_27 -> V_184 += V_183 + V_181 ;
V_27 -> V_185 += V_183 ;
V_27 -> V_186 += V_181 ;
V_182 = F_59 ( & V_86 -> V_68 ) ;
if ( V_181 ) {
V_27 -> V_187 ++ ;
V_27 -> V_188 += ( V_182 - 1 ) ;
} else
V_27 -> V_188 += V_182 ;
V_27 -> V_189 += V_182 ;
if ( V_182 >= 16 )
V_27 -> V_190 ++ ;
else if ( V_182 >= 8 )
V_27 -> V_191 ++ ;
else if ( V_182 >= 4 )
V_27 -> V_192 ++ ;
else if ( V_182 >= 2 )
V_27 -> V_193 ++ ;
else
V_27 -> V_194 ++ ;
}
static int F_60 ( struct V_72 * V_163 , struct V_4 * V_5 ,
struct V_86 * V_86 , int * V_195 , int * V_196 )
{
int V_3 ;
int V_57 ;
int V_197 = 0 ;
struct V_58 * V_59 ;
F_61 (cpu, flush_mask) {
V_59 = & V_5 -> V_43 -> V_60 [ V_3 ] ;
V_57 = V_59 -> V_57 - V_5 -> V_74 ;
F_62 ( V_57 , & V_86 -> V_68 ) ;
V_197 ++ ;
if ( V_59 -> V_7 == V_5 -> V_7 )
( * V_195 ) ++ ;
else
( * V_196 ) ++ ;
}
if ( ! V_197 )
return 1 ;
return 0 ;
}
const struct V_72 * F_63 ( const struct V_72 * V_72 ,
struct V_198 * V_199 , unsigned long V_200 ,
unsigned long V_201 , unsigned int V_3 )
{
int V_181 = 0 ;
int V_183 = 0 ;
int V_182 = 0 ;
struct V_86 * V_86 ;
struct V_72 * V_163 ;
struct V_26 * V_27 ;
struct V_4 * V_5 ;
unsigned long V_84 ;
unsigned long V_202 ;
V_5 = & F_5 ( V_4 , V_3 ) ;
if ( V_5 -> V_2 )
return V_72 ;
V_27 = V_5 -> V_28 ;
V_27 -> V_203 ++ ;
if ( V_5 -> V_109 ) {
V_84 =
F_37 ( V_105 ) ;
V_202 = ( ( V_84 >> ( V_5 -> V_104 *
V_106 ) ) & V_85 ) << 1 ;
if ( V_202 == V_107 )
return V_72 ;
V_5 -> V_109 = 0 ;
}
if ( V_5 -> V_135 ) {
if ( F_57 ( V_5 , V_27 ) ) {
V_27 -> V_204 ++ ;
return V_72 ;
}
}
V_163 = (struct V_72 * ) F_5 ( V_205 , V_3 ) ;
F_64 ( V_163 , V_72 , F_65 ( V_3 ) ) ;
if ( F_66 ( V_3 , * V_72 ) )
V_27 -> V_206 ++ ;
V_86 = V_5 -> V_207 ;
V_86 += ( V_208 * V_5 -> V_104 ) ;
F_67 ( & V_86 -> V_68 , V_209 ) ;
if ( F_60 ( V_163 , V_5 , V_86 , & V_181 , & V_183 ) )
return NULL ;
F_58 ( V_27 , V_181 , V_182 , V_183 , V_86 ) ;
if ( ! V_201 || ( V_201 - V_200 ) <= V_210 )
V_86 -> V_211 . V_44 = V_200 ;
else
V_86 -> V_211 . V_44 = V_45 ;
V_86 -> V_211 . V_33 = V_3 ;
if ( ! F_54 ( V_163 , V_5 , V_86 ) )
return NULL ;
else
return V_72 ;
}
struct V_15 * F_68 ( struct V_15 * V_16 ,
struct V_4 * V_5 )
{
struct V_15 * V_212 = V_16 + 1 ;
unsigned char V_18 = V_16 -> V_18 ;
if ( V_212 > V_5 -> V_31 )
V_212 = V_5 -> V_32 ;
while ( V_212 != V_16 ) {
if ( ( V_212 -> V_17 == 0 ) && ( V_212 -> V_20 == 0 ) &&
( V_212 -> V_18 == V_18 ) )
return V_212 ;
V_212 ++ ;
if ( V_212 > V_5 -> V_31 )
V_212 = V_5 -> V_32 ;
}
return NULL ;
}
void F_69 ( struct V_11 * V_12 , struct V_4 * V_5 )
{
unsigned long V_213 ;
unsigned char V_18 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_15 * V_214 ;
V_213 = F_15 () ;
V_18 = V_16 -> V_18 ;
if ( ( V_18 & V_213 ) == 0 ) {
V_214 = F_68 ( V_16 , V_5 ) ;
if ( V_214 ) {
F_16 ( V_12 , V_5 , 0 ) ;
return;
}
}
F_16 ( V_12 , V_5 , 1 ) ;
return;
}
void F_70 ( struct V_215 * V_216 )
{
int V_217 = 0 ;
T_3 V_218 ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_11 V_219 ;
F_71 () ;
V_218 = F_34 () ;
V_5 = & F_5 ( V_4 , F_22 () ) ;
V_27 = V_5 -> V_28 ;
V_219 . V_32 = V_5 -> V_32 ;
V_219 . V_31 = V_5 -> V_31 ;
V_16 = V_5 -> V_220 ;
while ( V_16 -> V_18 ) {
V_217 ++ ;
V_219 . V_52 = V_16 - V_219 . V_32 ;
V_219 . V_16 = V_16 ;
if ( V_5 -> V_119 == 2 )
F_69 ( & V_219 , V_5 ) ;
else
F_16 ( & V_219 , V_5 , 1 ) ;
V_16 ++ ;
if ( V_16 > V_219 . V_31 )
V_16 = V_219 . V_32 ;
V_5 -> V_220 = V_16 ;
}
V_27 -> V_221 += ( F_34 () - V_218 ) ;
if ( ! V_217 )
V_27 -> V_222 ++ ;
else if ( V_217 > 1 )
V_27 -> V_223 ++ ;
}
static void T_1 F_72 ( void )
{
int V_7 ;
int V_224 ;
int V_57 ;
unsigned long V_213 ;
V_224 = F_73 () ;
for ( V_7 = 0 ; V_7 < V_224 ; V_7 ++ ) {
if ( ! F_74 ( V_7 ) )
continue;
V_57 = F_75 ( V_7 ) ;
V_213 = F_76 ( V_57 ) ;
V_213 &= ~ ( 1L << V_225 ) ;
F_77 ( V_57 , V_213 ) ;
V_213 &= ~ ( ( unsigned long ) 0xf << V_226 ) ;
V_213 |= ( V_227 << V_226 ) ;
F_77 ( V_57 , V_213 ) ;
V_213 |= ( 1L << V_225 ) ;
if ( F_78 () ) {
V_213 &= ~ ( 1L << V_228 ) ;
}
F_77 ( V_57 , V_213 ) ;
}
}
static void * F_79 ( struct V_229 * V_230 , T_6 * V_101 )
{
if ( * V_101 < F_80 () )
return V_101 ;
return NULL ;
}
static void * F_81 ( struct V_229 * V_230 , void * V_231 , T_6 * V_101 )
{
( * V_101 ) ++ ;
if ( * V_101 < F_80 () )
return V_101 ;
return NULL ;
}
static void F_82 ( struct V_229 * V_230 , void * V_231 )
{
}
static inline unsigned long long F_83 ( unsigned long V_232 )
{
unsigned long V_76 ;
unsigned long long V_75 ;
V_76 = V_232 * 1000 ;
V_75 = ( V_76 << V_79 ) / ( F_5 ( V_78 , F_22 () ) ) ;
return V_75 ;
}
static int F_84 ( struct V_229 * V_230 , void * V_231 )
{
struct V_26 * V_27 ;
struct V_4 * V_5 ;
int V_3 ;
V_3 = * ( T_6 * ) V_231 ;
if ( ! V_3 ) {
F_85 ( V_230 ,
L_4 ) ;
F_85 ( V_230 ,
L_5 ) ;
F_85 ( V_230 ,
L_6 ) ;
F_85 ( V_230 ,
L_7 ) ;
F_85 ( V_230 ,
L_8 ) ;
F_85 ( V_230 ,
L_9 ) ;
F_85 ( V_230 ,
L_10 ) ;
}
if ( V_3 < F_80 () && F_86 ( V_3 ) ) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_27 = V_5 -> V_28 ;
F_85 ( V_230 ,
L_11 ,
V_3 , V_5 -> V_2 , V_27 -> V_151 ,
F_28 ( V_27 -> V_145 ) ,
V_27 -> V_206 , V_27 -> V_186 ,
V_27 -> V_185 , V_27 -> V_184 ,
V_27 -> V_187 , V_27 -> V_188 ,
V_27 -> V_189 , V_27 -> V_190 ) ;
F_85 ( V_230 , L_12 ,
V_27 -> V_191 , V_27 -> V_192 ,
V_27 -> V_193 , V_27 -> V_194 ,
V_27 -> V_94 , V_27 -> V_233 ) ;
F_85 ( V_230 , L_13 ,
V_27 -> V_175 , V_27 -> V_152 ,
V_27 -> V_126 , V_27 -> V_130 ,
V_27 -> V_153 , V_27 -> V_91 ,
V_27 -> V_234 , V_27 -> V_162 ) ;
F_85 ( V_230 , L_14 ,
V_27 -> V_136 , V_27 -> V_180 ,
V_27 -> V_108 , V_27 -> V_235 ,
V_27 -> V_236 , V_27 -> V_203 ,
V_27 -> V_204 , V_27 -> V_115 ,
V_27 -> V_179 , V_27 -> V_157 ,
V_27 -> V_150 ) ;
F_85 ( V_230 ,
L_15 ,
F_87 ( F_88 ( V_3 ) ) ,
V_27 -> V_48 , F_28 ( V_27 -> V_221 ) ,
V_27 -> V_46 , V_27 -> V_47 , V_27 -> V_223 ,
V_27 -> V_222 , V_27 -> V_29 , V_27 -> V_37 ,
V_27 -> V_38 , V_27 -> V_64 ,
V_27 -> V_66 ) ;
}
return 0 ;
}
static T_7 F_89 ( struct V_230 * V_230 , char T_8 * V_237 ,
T_9 V_217 , T_6 * V_238 )
{
char * V_239 ;
int V_240 ;
V_239 = F_90 ( V_241 , L_16 ,
L_17 ,
L_18 ,
L_19 ,
V_127 , V_121 , V_123 ,
V_129 , V_178 , V_139 ,
V_242 , V_243 , V_138 ,
V_156 ) ;
if ( ! V_239 )
return - V_244 ;
V_240 = F_91 ( V_237 , V_217 , V_238 , V_239 , strlen ( V_239 ) ) ;
F_92 ( V_239 ) ;
return V_240 ;
}
static T_7 F_93 ( struct V_230 * V_230 , const char T_8 * V_245 ,
T_9 V_217 , T_6 * V_231 )
{
int V_3 ;
int V_21 ;
int V_246 ;
long V_247 ;
char V_248 [ 64 ] ;
struct V_26 * V_27 ;
if ( V_217 == 0 || V_217 > sizeof( V_248 ) )
return - V_249 ;
if ( F_94 ( V_248 , V_245 , V_217 ) )
return - V_250 ;
V_248 [ V_217 - 1 ] = '\0' ;
if ( ! strcmp ( V_248 , L_20 ) ) {
F_2 () ;
return V_217 ;
} else if ( ! strcmp ( V_248 , L_21 ) ) {
F_6 () ;
return V_217 ;
}
if ( F_95 ( V_248 , 10 , & V_247 ) < 0 ) {
F_96 ( V_251 L_22 , V_248 ) ;
return - V_249 ;
}
if ( V_247 == 0 ) {
V_246 = F_97 ( V_252 ) ;
F_96 ( V_251 L_23 ) ;
F_96 ( V_251 L_24 ) ;
for ( V_21 = 0 ; V_21 < V_246 ; V_21 ++ )
F_96 ( V_251 L_25 , V_252 [ V_21 ] ) ;
} else if ( V_247 == - 1 ) {
F_4 (cpu) {
V_27 = & F_5 ( V_253 , V_3 ) ;
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
}
}
return V_217 ;
}
static int F_98 ( const char * V_254 )
{
int V_255 = 0 ;
for (; ; V_254 ++ ) {
switch ( * V_254 ) {
case '0' ... '9' :
V_255 = 10 * V_255 + ( * V_254 - '0' ) ;
break;
default:
return V_255 ;
}
}
}
static int F_99 ( struct V_4 * V_5 , char * V_256 ,
int V_217 )
{
char * V_257 ;
char * V_258 ;
int V_197 = 0 ;
int V_255 ;
int V_259 = F_97 ( V_260 ) ;
V_257 = V_256 + strspn ( V_256 , V_261 ) ;
V_258 = V_257 ;
for (; * V_257 ; V_257 = V_258 + strspn ( V_258 , V_261 ) ) {
V_258 = V_257 + strcspn ( V_257 , V_261 ) ;
V_197 ++ ;
if ( V_258 == V_257 )
break;
}
if ( V_197 != V_259 ) {
F_96 ( V_262 L_26 , V_259 ) ;
return - V_249 ;
}
V_257 = V_256 + strspn ( V_256 , V_261 ) ;
V_258 = V_257 ;
for ( V_197 = 0 ; * V_257 ; V_257 = V_258 + strspn ( V_258 , V_261 ) , V_197 ++ ) {
V_258 = V_257 + strcspn ( V_257 , V_261 ) ;
V_255 = F_98 ( V_257 ) ;
switch ( V_197 ) {
case 0 :
if ( V_255 == 0 ) {
V_127 = V_263 ;
V_140 = V_263 ;
continue;
}
if ( V_255 < 1 || V_255 > V_5 -> V_56 ) {
F_96 ( V_251
L_27 ,
V_255 ) ;
return - V_249 ;
}
V_127 = V_255 ;
V_140 = V_255 ;
continue;
default:
if ( V_255 == 0 )
* V_260 [ V_197 ] . V_264 = V_260 [ V_197 ] . V_265 ;
else
* V_260 [ V_197 ] . V_264 = V_255 ;
continue;
}
if ( V_258 == V_257 )
break;
}
return 0 ;
}
static T_7 F_100 ( struct V_230 * V_230 , const char T_8 * V_245 ,
T_9 V_217 , T_6 * V_231 )
{
int V_3 ;
int V_240 ;
char V_256 [ 100 ] ;
struct V_4 * V_5 ;
if ( V_217 == 0 || V_217 > sizeof( V_256 ) - 1 )
return - V_249 ;
if ( F_94 ( V_256 , V_245 , V_217 ) )
return - V_250 ;
V_256 [ V_217 ] = '\0' ;
V_3 = F_101 () ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_240 = F_99 ( V_5 , V_256 , V_217 ) ;
F_102 () ;
if ( V_240 )
return V_240 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_127 = V_127 ;
V_5 -> V_140 = V_127 ;
V_5 -> V_121 = V_121 ;
V_5 -> V_123 = V_123 ;
V_5 -> V_129 = V_129 ;
V_5 -> V_178 = V_178 ;
V_5 -> V_139 = V_139 ;
V_5 -> V_266 = V_242 ;
V_5 -> V_149 = V_243 ;
V_5 -> V_138 = F_42 ( V_138 ) ;
V_5 -> V_156 = V_156 ;
}
return V_217 ;
}
static int F_103 ( struct V_267 * V_267 , struct V_230 * V_230 )
{
return F_104 ( V_230 , & V_268 ) ;
}
static int F_105 ( struct V_267 * V_267 , struct V_230 * V_230 )
{
return 0 ;
}
static int T_1 F_106 ( void )
{
struct V_269 * V_270 ;
if ( ! F_107 () )
return 0 ;
V_270 = F_108 ( V_271 , 0444 , NULL ,
& V_272 ) ;
if ( ! V_270 ) {
F_96 ( V_273 L_28 ,
V_271 ) ;
return - V_249 ;
}
V_274 = F_109 ( V_275 , NULL ) ;
if ( ! V_274 ) {
F_96 ( V_273 L_29 ,
V_275 ) ;
return - V_249 ;
}
V_276 = F_110 ( V_277 , 0600 ,
V_274 , NULL , & V_278 ) ;
if ( ! V_276 ) {
F_96 ( V_273 L_30 ,
V_277 ) ;
return - V_249 ;
}
return 0 ;
}
static void F_111 ( int V_8 , int V_57 , int V_279 )
{
int V_21 ;
int V_3 ;
int V_166 = 0 ;
unsigned long V_280 ;
unsigned long V_281 ;
unsigned long V_282 ;
T_9 V_283 ;
struct V_86 * V_86 ;
struct V_86 * V_284 ;
struct V_168 * V_169 ;
struct V_170 * V_171 ;
struct V_4 * V_5 ;
V_283 = sizeof( struct V_86 ) * V_285 * V_208 ;
V_86 = F_112 ( V_283 , V_241 , V_8 ) ;
F_113 ( ! V_86 ) ;
V_280 = F_114 ( V_86 ) ;
V_282 = F_115 ( V_280 ) ;
V_281 = F_116 ( V_280 ) ;
if ( F_117 () )
V_166 = 1 ;
F_118 ( V_57 , ( V_282 << V_286 | V_281 ) ) ;
for ( V_21 = 0 , V_284 = V_86 ; V_21 < ( V_285 * V_208 ) ; V_21 ++ , V_284 ++ ) {
memset ( V_284 , 0 , sizeof( struct V_86 ) ) ;
if ( V_166 ) {
V_169 = & V_284 -> V_172 . V_169 ;
V_169 -> V_287 = 1 ;
V_169 -> V_288 =
F_119 ( V_279 ) ;
V_169 -> V_289 = V_290 ;
V_169 -> V_291 = V_292 ;
V_169 -> V_293 = 1 ;
} else {
V_171 = & V_284 -> V_172 . V_171 ;
V_171 -> V_287 = 1 ;
V_171 -> V_288 =
F_119 ( V_279 ) ;
V_171 -> V_289 = V_290 ;
V_171 -> V_291 = V_292 ;
}
}
F_4 (cpu) {
if ( V_57 != F_75 ( F_11 ( V_3 ) ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_207 = V_86 ;
}
}
static void F_120 ( int V_8 , int V_57 )
{
int V_3 ;
T_9 V_294 ;
char * V_295 ;
void * V_296 ;
unsigned long V_297 ;
unsigned long V_298 ;
unsigned long V_299 ;
unsigned long V_300 ;
struct V_15 * V_301 ;
struct V_4 * V_5 ;
V_294 = ( V_30 + 1 ) * sizeof( struct V_15 ) ;
V_296 = F_112 ( V_294 , V_241 , V_8 ) ;
V_301 = (struct V_15 * ) V_296 ;
F_113 ( ! V_301 ) ;
V_295 = ( char * ) V_301 + 31 ;
V_301 = (struct V_15 * ) ( ( ( unsigned long ) V_295 >> 5 ) << 5 ) ;
F_4 (cpu) {
if ( V_57 != F_88 ( V_3 ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_32 = V_301 ;
V_5 -> V_220 = V_301 ;
V_5 -> V_31 = V_301 + ( V_30 - 1 ) ;
}
V_297 = F_115 ( F_114 ( V_301 ) ) ;
V_298 = F_121 ( V_301 ) ;
V_299 = ( ( unsigned long ) V_297 << V_302 ) | V_298 ;
V_300 = F_121 ( V_301 + ( V_30 - 1 ) ) ;
F_122 ( V_57 , V_299 ) ;
F_123 ( V_57 , V_298 ) ;
F_124 ( V_57 , V_300 ) ;
F_125 ( V_57 , 0xffffUL ) ;
memset ( V_301 , 0 , sizeof( struct V_15 ) * V_30 ) ;
}
static void T_1 F_126 ( int V_7 , int V_303 , int V_279 )
{
int V_8 ;
int V_57 ;
unsigned long V_304 ;
V_8 = F_7 ( V_7 ) ;
V_57 = F_75 ( V_7 ) ;
F_111 ( V_8 , V_57 , V_279 ) ;
F_120 ( V_8 , V_57 ) ;
V_304 = F_10 ( V_7 ) | V_305 ;
F_127 ( V_57 , ( ( V_304 << 32 ) | V_303 ) ) ;
}
static int F_128 ( void )
{
unsigned long V_213 ;
int V_306 ;
int V_307 ;
int V_167 ;
int V_308 ;
int V_240 ;
unsigned long V_309 ;
if ( F_117 () ) {
V_306 = V_227 & V_310 ;
V_213 = F_32 ( V_311 ) ;
V_167 = ( V_213 >> V_312 ) & V_313 ;
V_213 = F_32 ( V_314 ) ;
V_307 = ( V_213 >> V_315 ) & V_316 ;
V_309 = V_317 [ V_167 ] ;
V_309 *= ( V_306 * V_307 ) ;
V_240 = V_309 / 1000 ;
} else {
V_213 = F_32 ( V_318 ) ;
V_213 = ( V_213 & V_319 ) >> V_320 ;
if ( V_213 & ( 1L << V_321 ) )
V_308 = 80 ;
else
V_308 = 10 ;
V_306 = V_213 & V_322 ;
V_240 = V_306 * V_308 ;
}
return V_240 ;
}
static void T_1 F_129 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_135 = 0 ;
if ( V_2 )
V_5 -> V_2 = 1 ;
V_5 -> V_28 = & F_5 ( V_253 , V_3 ) ;
V_5 -> V_116 = F_83 ( 2 * V_96 ) ;
V_5 -> V_127 = V_127 ;
V_5 -> V_140 = V_127 ;
V_5 -> V_121 = V_121 ;
V_5 -> V_123 = V_123 ;
V_5 -> V_129 = V_129 ;
V_5 -> V_178 = V_178 ;
V_5 -> V_139 = V_139 ;
V_5 -> V_266 = V_242 ;
V_5 -> V_149 = V_243 ;
V_5 -> V_138 = F_42 ( V_138 ) ;
V_5 -> V_156 = V_156 ;
F_130 ( & V_5 -> V_124 ) ;
F_130 ( & V_5 -> V_159 ) ;
F_130 ( & V_5 -> V_134 ) ;
}
}
static int T_1 F_131 ( int V_279 ,
struct V_323 * V_324 ,
unsigned char * V_325 )
{
int V_3 ;
int V_57 ;
int V_7 ;
int V_326 ;
struct V_4 * V_5 ;
struct V_323 * V_327 ;
struct V_328 * V_329 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_57 = F_132 ( V_3 ) -> V_57 ;
if ( ( V_57 - V_279 ) >= V_209 ) {
F_96 ( V_330
L_31 ,
V_3 , V_57 , V_279 , V_209 ) ;
return 1 ;
}
V_5 -> V_331 = F_133 ( V_3 ) ;
V_5 -> V_74 = V_279 ;
V_7 = F_132 ( V_3 ) -> V_332 ;
* ( V_325 + ( V_7 / 8 ) ) |= ( 1 << ( V_7 % 8 ) ) ;
V_327 = & V_324 [ V_7 ] ;
V_327 -> V_333 ++ ;
V_327 -> V_7 = V_7 ;
V_327 -> V_57 = V_57 ;
V_326 = V_5 -> V_331 & 1 ;
V_327 -> V_334 |= ( 1 << V_326 ) ;
V_329 = & V_327 -> V_326 [ V_326 ] ;
V_329 -> V_335 [ V_329 -> V_333 ] = V_3 ;
V_329 -> V_333 ++ ;
if ( V_329 -> V_333 > V_336 ) {
F_96 ( V_330 L_32 ,
V_329 -> V_333 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_134 ( struct V_4 * V_42 )
{
int V_3 ;
T_9 V_337 = sizeof( struct V_58 ) * F_80 () ;
V_42 -> V_60 = F_112 ( V_337 , V_241 , V_42 -> V_331 ) ;
memset ( V_42 -> V_60 , 0 , V_337 ) ;
F_4 (cpu) {
V_42 -> V_60 [ V_3 ] . V_57 = F_132 ( V_3 ) -> V_57 ;
V_42 -> V_60 [ V_3 ] . V_7 = F_132 ( V_3 ) -> V_332 ;
}
}
static void F_135 ( struct V_4 * V_80 )
{
int V_338 = sizeof( T_2 ) ;
V_80 -> V_72 = F_136 ( V_338 , V_241 , V_80 -> V_331 ) ;
}
static int F_137 ( struct V_328 * V_329 , struct V_323 * V_327 ,
struct V_4 * * V_339 ,
struct V_4 * * V_340 )
{
int V_21 ;
int V_3 ;
struct V_4 * V_5 ;
for ( V_21 = 0 ; V_21 < V_329 -> V_333 ; V_21 ++ ) {
V_3 = V_329 -> V_335 [ V_21 ] ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_3 = V_3 ;
if ( V_21 == 0 ) {
* V_339 = V_5 ;
if ( ! ( * V_340 ) )
* V_340 = V_5 ;
}
V_5 -> V_56 = V_327 -> V_333 ;
V_5 -> V_53 = V_329 -> V_333 ;
V_5 -> V_43 = * V_339 ;
V_5 -> V_7 = V_327 -> V_7 ;
if ( F_117 () )
V_5 -> V_119 = 1 ;
else if ( F_78 () )
V_5 -> V_119 = 2 ;
else {
F_96 ( V_330 L_33 ) ;
return 1 ;
}
V_5 -> V_50 = * V_340 ;
V_5 -> V_104 = F_132 ( V_3 ) -> V_341 ;
if ( V_5 -> V_104 >= V_342 ) {
F_96 ( V_330 L_34 ,
V_5 -> V_104 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_138 ( int V_224 ,
struct V_323 * V_324 ,
unsigned char * V_325 )
{
int V_326 ;
int V_7 ;
unsigned short V_334 ;
for ( V_7 = 0 ; V_7 < V_224 ; V_7 ++ ) {
struct V_323 * V_327 ;
struct V_4 * V_42 = NULL ;
struct V_4 * V_80 = NULL ;
if ( ! ( * ( V_325 + ( V_7 / 8 ) ) & ( 1 << ( V_7 % 8 ) ) ) )
continue;
V_327 = & V_324 [ V_7 ] ;
V_334 = V_327 -> V_334 ;
V_326 = 0 ;
while ( V_334 ) {
struct V_328 * V_329 ;
if ( ( V_334 & 1 ) ) {
V_329 = & V_327 -> V_326 [ V_326 ] ;
if ( F_137 ( V_329 , V_327 , & V_42 , & V_80 ) )
return 1 ;
F_134 ( V_42 ) ;
}
V_326 ++ ;
V_334 = ( V_334 >> 1 ) ;
}
F_135 ( V_80 ) ;
}
return 0 ;
}
static int T_1 F_139 ( int V_224 , int V_343 )
{
unsigned char * V_325 ;
void * V_296 ;
struct V_323 * V_324 ;
V_96 = F_128 () ;
V_296 = F_140 ( V_224 * sizeof( struct V_323 ) , V_241 ) ;
V_324 = (struct V_323 * ) V_296 ;
memset ( V_324 , 0 , V_224 * sizeof( struct V_323 ) ) ;
V_325 = F_141 ( ( V_224 + 7 ) / 8 , V_241 ) ;
if ( F_131 ( V_343 , V_324 , V_325 ) )
goto V_344;
if ( F_138 ( V_224 , V_324 , V_325 ) )
goto V_344;
F_92 ( V_324 ) ;
F_92 ( V_325 ) ;
F_129 () ;
return 0 ;
V_344:
F_92 ( V_324 ) ;
F_92 ( V_325 ) ;
return 1 ;
}
static int T_1 F_142 ( void )
{
int V_7 ;
int V_57 ;
int V_224 ;
int V_345 ;
int V_346 ;
int V_303 ;
T_10 * V_71 ;
if ( ! F_107 () )
return 0 ;
F_143 (cur_cpu) {
V_71 = & F_5 ( V_205 , V_345 ) ;
F_144 ( V_71 , V_241 , F_133 ( V_345 ) ) ;
}
V_224 = F_73 () ;
V_148 = F_83 ( V_242 ) ;
V_347 = 0x7fffffff ;
for ( V_7 = 0 ; V_7 < V_224 ; V_7 ++ ) {
V_346 = F_74 ( V_7 ) ;
if ( V_346 && ( F_75 ( V_7 ) < V_347 ) )
V_347 = F_75 ( V_7 ) ;
}
F_72 () ;
if ( F_139 ( V_224 , V_347 ) ) {
F_6 () ;
V_6 = 1 ;
return 0 ;
}
V_303 = V_348 ;
F_145 (uvhub)
if ( F_74 ( V_7 ) )
F_126 ( V_7 , V_303 , V_347 ) ;
F_146 ( V_303 , V_349 ) ;
F_145 (uvhub) {
if ( F_74 ( V_7 ) ) {
unsigned long V_255 ;
unsigned long V_24 ;
V_57 = F_75 ( V_7 ) ;
V_255 = 1L << 63 ;
F_147 ( V_57 , V_255 ) ;
V_24 = 1 ;
if ( ! F_117 () )
F_148 ( V_57 , V_24 ) ;
}
}
return 0 ;
}
