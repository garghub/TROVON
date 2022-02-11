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
unsigned V_201 , unsigned int V_3 )
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
V_27 = V_5 -> V_28 ;
V_27 -> V_203 ++ ;
if ( V_5 -> V_2 )
return V_72 ;
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
V_86 -> V_210 . V_44 = V_200 ;
V_86 -> V_210 . V_33 = V_3 ;
if ( ! F_54 ( V_163 , V_5 , V_86 ) )
return NULL ;
else
return V_72 ;
}
struct V_15 * F_68 ( struct V_15 * V_16 ,
struct V_4 * V_5 )
{
struct V_15 * V_211 = V_16 + 1 ;
unsigned char V_18 = V_16 -> V_18 ;
if ( V_211 > V_5 -> V_31 )
V_211 = V_5 -> V_32 ;
while ( V_211 != V_16 ) {
if ( ( V_211 -> V_17 == 0 ) && ( V_211 -> V_20 == 0 ) &&
( V_211 -> V_18 == V_18 ) )
return V_211 ;
V_211 ++ ;
if ( V_211 > V_5 -> V_31 )
V_211 = V_5 -> V_32 ;
}
return NULL ;
}
void F_69 ( struct V_11 * V_12 , struct V_4 * V_5 )
{
unsigned long V_212 ;
unsigned char V_18 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_15 * V_213 ;
V_212 = F_15 () ;
V_18 = V_16 -> V_18 ;
if ( ( V_18 & V_212 ) == 0 ) {
V_213 = F_68 ( V_16 , V_5 ) ;
if ( V_213 ) {
F_16 ( V_12 , V_5 , 0 ) ;
return;
}
}
F_16 ( V_12 , V_5 , 1 ) ;
return;
}
void F_70 ( struct V_214 * V_215 )
{
int V_216 = 0 ;
T_3 V_217 ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_11 V_218 ;
F_71 () ;
V_217 = F_34 () ;
V_5 = & F_5 ( V_4 , F_22 () ) ;
V_27 = V_5 -> V_28 ;
V_218 . V_32 = V_5 -> V_32 ;
V_218 . V_31 = V_5 -> V_31 ;
V_16 = V_5 -> V_219 ;
while ( V_16 -> V_18 ) {
V_216 ++ ;
V_218 . V_52 = V_16 - V_218 . V_32 ;
V_218 . V_16 = V_16 ;
if ( V_5 -> V_119 == 2 )
F_69 ( & V_218 , V_5 ) ;
else
F_16 ( & V_218 , V_5 , 1 ) ;
V_16 ++ ;
if ( V_16 > V_218 . V_31 )
V_16 = V_218 . V_32 ;
V_5 -> V_219 = V_16 ;
}
V_27 -> V_220 += ( F_34 () - V_217 ) ;
if ( ! V_216 )
V_27 -> V_221 ++ ;
else if ( V_216 > 1 )
V_27 -> V_222 ++ ;
}
static void T_1 F_72 ( void )
{
int V_7 ;
int V_223 ;
int V_57 ;
unsigned long V_212 ;
V_223 = F_73 () ;
for ( V_7 = 0 ; V_7 < V_223 ; V_7 ++ ) {
if ( ! F_74 ( V_7 ) )
continue;
V_57 = F_75 ( V_7 ) ;
V_212 = F_76 ( V_57 ) ;
V_212 &= ~ ( 1L << V_224 ) ;
F_77 ( V_57 , V_212 ) ;
V_212 &= ~ ( ( unsigned long ) 0xf << V_225 ) ;
V_212 |= ( V_226 << V_225 ) ;
F_77 ( V_57 , V_212 ) ;
V_212 |= ( 1L << V_224 ) ;
if ( F_78 () ) {
V_212 &= ~ ( 1L << V_227 ) ;
}
F_77 ( V_57 , V_212 ) ;
}
}
static void * F_79 ( struct V_228 * V_229 , T_6 * V_101 )
{
if ( * V_101 < F_80 () )
return V_101 ;
return NULL ;
}
static void * F_81 ( struct V_228 * V_229 , void * V_230 , T_6 * V_101 )
{
( * V_101 ) ++ ;
if ( * V_101 < F_80 () )
return V_101 ;
return NULL ;
}
static void F_82 ( struct V_228 * V_229 , void * V_230 )
{
}
static inline unsigned long long F_83 ( unsigned long V_231 )
{
unsigned long V_76 ;
unsigned long long V_75 ;
V_76 = V_231 * 1000 ;
V_75 = ( V_76 << V_79 ) / ( F_5 ( V_78 , F_22 () ) ) ;
return V_75 ;
}
static int F_84 ( struct V_228 * V_229 , void * V_230 )
{
struct V_26 * V_27 ;
struct V_4 * V_5 ;
int V_3 ;
V_3 = * ( T_6 * ) V_230 ;
if ( ! V_3 ) {
F_85 ( V_229 ,
L_4 ) ;
F_85 ( V_229 ,
L_5 ) ;
F_85 ( V_229 ,
L_6 ) ;
F_85 ( V_229 ,
L_7 ) ;
F_85 ( V_229 ,
L_8 ) ;
F_85 ( V_229 ,
L_9 ) ;
F_85 ( V_229 ,
L_10 ) ;
}
if ( V_3 < F_80 () && F_86 ( V_3 ) ) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_27 = V_5 -> V_28 ;
F_85 ( V_229 ,
L_11 ,
V_3 , V_5 -> V_2 , V_27 -> V_151 ,
F_28 ( V_27 -> V_145 ) ,
V_27 -> V_206 , V_27 -> V_186 ,
V_27 -> V_185 , V_27 -> V_184 ,
V_27 -> V_187 , V_27 -> V_188 ,
V_27 -> V_189 , V_27 -> V_190 ) ;
F_85 ( V_229 , L_12 ,
V_27 -> V_191 , V_27 -> V_192 ,
V_27 -> V_193 , V_27 -> V_194 ,
V_27 -> V_94 , V_27 -> V_232 ) ;
F_85 ( V_229 , L_13 ,
V_27 -> V_175 , V_27 -> V_152 ,
V_27 -> V_126 , V_27 -> V_130 ,
V_27 -> V_153 , V_27 -> V_91 ,
V_27 -> V_233 , V_27 -> V_162 ) ;
F_85 ( V_229 , L_14 ,
V_27 -> V_136 , V_27 -> V_180 ,
V_27 -> V_108 , V_27 -> V_234 ,
V_27 -> V_235 , V_27 -> V_203 ,
V_27 -> V_204 , V_27 -> V_115 ,
V_27 -> V_179 , V_27 -> V_157 ,
V_27 -> V_150 ) ;
F_85 ( V_229 ,
L_15 ,
F_87 ( F_88 ( V_3 ) ) ,
V_27 -> V_48 , F_28 ( V_27 -> V_220 ) ,
V_27 -> V_46 , V_27 -> V_47 , V_27 -> V_222 ,
V_27 -> V_221 , V_27 -> V_29 , V_27 -> V_37 ,
V_27 -> V_38 , V_27 -> V_64 ,
V_27 -> V_66 ) ;
}
return 0 ;
}
static T_7 F_89 ( struct V_229 * V_229 , char T_8 * V_236 ,
T_9 V_216 , T_6 * V_237 )
{
char * V_238 ;
int V_239 ;
V_238 = F_90 ( V_240 , L_16 ,
L_17 ,
L_18 ,
L_19 ,
V_127 , V_121 , V_123 ,
V_129 , V_178 , V_139 ,
V_241 , V_242 , V_138 ,
V_156 ) ;
if ( ! V_238 )
return - V_243 ;
V_239 = F_91 ( V_236 , V_216 , V_237 , V_238 , strlen ( V_238 ) ) ;
F_92 ( V_238 ) ;
return V_239 ;
}
static T_7 F_93 ( struct V_229 * V_229 , const char T_8 * V_244 ,
T_9 V_216 , T_6 * V_230 )
{
int V_3 ;
int V_21 ;
int V_245 ;
long V_246 ;
char V_247 [ 64 ] ;
struct V_26 * V_27 ;
if ( V_216 == 0 || V_216 > sizeof( V_247 ) )
return - V_248 ;
if ( F_94 ( V_247 , V_244 , V_216 ) )
return - V_249 ;
V_247 [ V_216 - 1 ] = '\0' ;
if ( ! strcmp ( V_247 , L_20 ) ) {
F_2 () ;
return V_216 ;
} else if ( ! strcmp ( V_247 , L_21 ) ) {
F_6 () ;
return V_216 ;
}
if ( F_95 ( V_247 , 10 , & V_246 ) < 0 ) {
F_96 ( V_250 L_22 , V_247 ) ;
return - V_248 ;
}
if ( V_246 == 0 ) {
V_245 = sizeof( V_251 ) / sizeof( * V_251 ) ;
F_96 ( V_250 L_23 ) ;
F_96 ( V_250 L_24 ) ;
for ( V_21 = 0 ; V_21 < V_245 ; V_21 ++ )
F_96 ( V_250 L_25 , V_251 [ V_21 ] ) ;
} else if ( V_246 == - 1 ) {
F_4 (cpu) {
V_27 = & F_5 ( V_252 , V_3 ) ;
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
}
}
return V_216 ;
}
static int F_97 ( const char * V_253 )
{
int V_254 = 0 ;
for (; ; V_253 ++ ) {
switch ( * V_253 ) {
case '0' ... '9' :
V_254 = 10 * V_254 + ( * V_253 - '0' ) ;
break;
default:
return V_254 ;
}
}
}
static int F_98 ( struct V_4 * V_5 , char * V_255 ,
int V_216 )
{
char * V_256 ;
char * V_257 ;
int V_197 = 0 ;
int V_254 ;
int V_258 = sizeof( V_259 ) / sizeof( * V_259 ) ;
V_256 = V_255 + strspn ( V_255 , V_260 ) ;
V_257 = V_256 ;
for (; * V_256 ; V_256 = V_257 + strspn ( V_257 , V_260 ) ) {
V_257 = V_256 + strcspn ( V_256 , V_260 ) ;
V_197 ++ ;
if ( V_257 == V_256 )
break;
}
if ( V_197 != V_258 ) {
F_96 ( V_261 L_26 , V_258 ) ;
return - V_248 ;
}
V_256 = V_255 + strspn ( V_255 , V_260 ) ;
V_257 = V_256 ;
for ( V_197 = 0 ; * V_256 ; V_256 = V_257 + strspn ( V_257 , V_260 ) , V_197 ++ ) {
V_257 = V_256 + strcspn ( V_256 , V_260 ) ;
V_254 = F_97 ( V_256 ) ;
switch ( V_197 ) {
case 0 :
if ( V_254 == 0 ) {
V_127 = V_262 ;
V_140 = V_262 ;
continue;
}
if ( V_254 < 1 || V_254 > V_5 -> V_56 ) {
F_96 ( V_250
L_27 ,
V_254 ) ;
return - V_248 ;
}
V_127 = V_254 ;
V_140 = V_254 ;
continue;
default:
if ( V_254 == 0 )
* V_259 [ V_197 ] . V_263 = V_259 [ V_197 ] . V_264 ;
else
* V_259 [ V_197 ] . V_263 = V_254 ;
continue;
}
if ( V_257 == V_256 )
break;
}
return 0 ;
}
static T_7 F_99 ( struct V_229 * V_229 , const char T_8 * V_244 ,
T_9 V_216 , T_6 * V_230 )
{
int V_3 ;
int V_239 ;
char V_255 [ 100 ] ;
struct V_4 * V_5 ;
if ( V_216 == 0 || V_216 > sizeof( V_255 ) - 1 )
return - V_248 ;
if ( F_94 ( V_255 , V_244 , V_216 ) )
return - V_249 ;
V_255 [ V_216 ] = '\0' ;
V_3 = F_100 () ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_239 = F_98 ( V_5 , V_255 , V_216 ) ;
F_101 () ;
if ( V_239 )
return V_239 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_127 = V_127 ;
V_5 -> V_140 = V_127 ;
V_5 -> V_121 = V_121 ;
V_5 -> V_123 = V_123 ;
V_5 -> V_129 = V_129 ;
V_5 -> V_178 = V_178 ;
V_5 -> V_139 = V_139 ;
V_5 -> V_265 = V_241 ;
V_5 -> V_149 = V_242 ;
V_5 -> V_138 = F_42 ( V_138 ) ;
V_5 -> V_156 = V_156 ;
}
return V_216 ;
}
static int F_102 ( struct V_266 * V_266 , struct V_229 * V_229 )
{
return F_103 ( V_229 , & V_267 ) ;
}
static int F_104 ( struct V_266 * V_266 , struct V_229 * V_229 )
{
return 0 ;
}
static int T_1 F_105 ( void )
{
struct V_268 * V_269 ;
if ( ! F_106 () )
return 0 ;
V_269 = F_107 ( V_270 , 0444 , NULL ,
& V_271 ) ;
if ( ! V_269 ) {
F_96 ( V_272 L_28 ,
V_270 ) ;
return - V_248 ;
}
V_273 = F_108 ( V_274 , NULL ) ;
if ( ! V_273 ) {
F_96 ( V_272 L_29 ,
V_274 ) ;
return - V_248 ;
}
V_275 = F_109 ( V_276 , 0600 ,
V_273 , NULL , & V_277 ) ;
if ( ! V_275 ) {
F_96 ( V_272 L_30 ,
V_276 ) ;
return - V_248 ;
}
return 0 ;
}
static void F_110 ( int V_8 , int V_57 , int V_278 )
{
int V_21 ;
int V_3 ;
int V_166 = 0 ;
unsigned long V_279 ;
unsigned long V_280 ;
unsigned long V_281 ;
T_9 V_282 ;
struct V_86 * V_86 ;
struct V_86 * V_283 ;
struct V_168 * V_169 ;
struct V_170 * V_171 ;
struct V_4 * V_5 ;
V_282 = sizeof( struct V_86 ) * V_284 * V_208 ;
V_86 = F_111 ( V_282 , V_240 , V_8 ) ;
F_112 ( ! V_86 ) ;
V_279 = F_113 ( V_86 ) ;
V_281 = F_114 ( V_279 ) ;
V_280 = F_115 ( V_279 ) ;
if ( F_116 () )
V_166 = 1 ;
F_117 ( V_57 , ( V_281 << V_285 | V_280 ) ) ;
for ( V_21 = 0 , V_283 = V_86 ; V_21 < ( V_284 * V_208 ) ; V_21 ++ , V_283 ++ ) {
memset ( V_283 , 0 , sizeof( struct V_86 ) ) ;
if ( V_166 ) {
V_169 = & V_283 -> V_172 . V_169 ;
V_169 -> V_286 = 1 ;
V_169 -> V_287 =
F_118 ( V_278 ) ;
V_169 -> V_288 = V_289 ;
V_169 -> V_290 = V_291 ;
V_169 -> V_292 = 1 ;
} else {
V_171 = & V_283 -> V_172 . V_171 ;
V_171 -> V_286 = 1 ;
V_171 -> V_287 =
F_118 ( V_278 ) ;
V_171 -> V_288 = V_289 ;
V_171 -> V_290 = V_291 ;
}
}
F_4 (cpu) {
if ( V_57 != F_75 ( F_11 ( V_3 ) ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_207 = V_86 ;
}
}
static void F_119 ( int V_8 , int V_57 )
{
int V_3 ;
T_9 V_293 ;
char * V_294 ;
void * V_295 ;
unsigned long V_296 ;
unsigned long V_297 ;
unsigned long V_298 ;
unsigned long V_299 ;
struct V_15 * V_300 ;
struct V_4 * V_5 ;
V_293 = ( V_30 + 1 ) * sizeof( struct V_15 ) ;
V_295 = F_111 ( V_293 , V_240 , V_8 ) ;
V_300 = (struct V_15 * ) V_295 ;
F_112 ( ! V_300 ) ;
V_294 = ( char * ) V_300 + 31 ;
V_300 = (struct V_15 * ) ( ( ( unsigned long ) V_294 >> 5 ) << 5 ) ;
F_4 (cpu) {
if ( V_57 != F_88 ( V_3 ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_32 = V_300 ;
V_5 -> V_219 = V_300 ;
V_5 -> V_31 = V_300 + ( V_30 - 1 ) ;
}
V_296 = F_114 ( F_113 ( V_300 ) ) ;
V_297 = F_120 ( V_300 ) ;
V_298 = ( ( unsigned long ) V_296 << V_301 ) | V_297 ;
V_299 = F_120 ( V_300 + ( V_30 - 1 ) ) ;
F_121 ( V_57 , V_298 ) ;
F_122 ( V_57 , V_297 ) ;
F_123 ( V_57 , V_299 ) ;
F_124 ( V_57 , 0xffffUL ) ;
memset ( V_300 , 0 , sizeof( struct V_15 ) * V_30 ) ;
}
static void T_1 F_125 ( int V_7 , int V_302 , int V_278 )
{
int V_8 ;
int V_57 ;
unsigned long V_303 ;
V_8 = F_7 ( V_7 ) ;
V_57 = F_75 ( V_7 ) ;
F_110 ( V_8 , V_57 , V_278 ) ;
F_119 ( V_8 , V_57 ) ;
V_303 = F_10 ( V_7 ) | V_304 ;
F_126 ( V_57 , ( ( V_303 << 32 ) | V_302 ) ) ;
}
static int F_127 ( void )
{
unsigned long V_212 ;
int V_305 ;
int V_306 ;
int V_167 ;
int V_307 ;
int V_239 ;
unsigned long V_308 ;
if ( F_116 () ) {
V_305 = V_226 & V_309 ;
V_212 = F_32 ( V_310 ) ;
V_167 = ( V_212 >> V_311 ) & V_312 ;
V_212 = F_32 ( V_313 ) ;
V_306 = ( V_212 >> V_314 ) & V_315 ;
V_308 = V_316 [ V_167 ] ;
V_308 *= ( V_305 * V_306 ) ;
V_239 = V_308 / 1000 ;
} else {
V_212 = F_32 ( V_317 ) ;
V_212 = ( V_212 & V_318 ) >> V_319 ;
if ( V_212 & ( 1L << V_320 ) )
V_307 = 80 ;
else
V_307 = 10 ;
V_305 = V_212 & V_321 ;
V_239 = V_305 * V_307 ;
}
return V_239 ;
}
static void T_1 F_128 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_135 = 0 ;
if ( V_2 )
V_5 -> V_2 = 1 ;
V_5 -> V_28 = & F_5 ( V_252 , V_3 ) ;
V_5 -> V_116 = F_83 ( 2 * V_96 ) ;
V_5 -> V_127 = V_127 ;
V_5 -> V_140 = V_127 ;
V_5 -> V_121 = V_121 ;
V_5 -> V_123 = V_123 ;
V_5 -> V_129 = V_129 ;
V_5 -> V_178 = V_178 ;
V_5 -> V_139 = V_139 ;
V_5 -> V_265 = V_241 ;
V_5 -> V_149 = V_242 ;
V_5 -> V_138 = F_42 ( V_138 ) ;
V_5 -> V_156 = V_156 ;
F_129 ( & V_5 -> V_124 ) ;
F_129 ( & V_5 -> V_159 ) ;
F_129 ( & V_5 -> V_134 ) ;
}
}
static int T_1 F_130 ( int V_278 ,
struct V_322 * V_323 ,
unsigned char * V_324 )
{
int V_3 ;
int V_57 ;
int V_7 ;
int V_325 ;
struct V_4 * V_5 ;
struct V_322 * V_326 ;
struct V_327 * V_328 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_57 = F_131 ( V_3 ) -> V_57 ;
if ( ( V_57 - V_278 ) >= V_209 ) {
F_96 ( V_329
L_31 ,
V_3 , V_57 , V_278 , V_209 ) ;
return 1 ;
}
V_5 -> V_330 = F_132 ( V_3 ) ;
V_5 -> V_74 = V_278 ;
V_7 = F_131 ( V_3 ) -> V_331 ;
* ( V_324 + ( V_7 / 8 ) ) |= ( 1 << ( V_7 % 8 ) ) ;
V_326 = & V_323 [ V_7 ] ;
V_326 -> V_332 ++ ;
V_326 -> V_7 = V_7 ;
V_326 -> V_57 = V_57 ;
V_325 = V_5 -> V_330 & 1 ;
V_326 -> V_333 |= ( 1 << V_325 ) ;
V_328 = & V_326 -> V_325 [ V_325 ] ;
V_328 -> V_334 [ V_328 -> V_332 ] = V_3 ;
V_328 -> V_332 ++ ;
if ( V_328 -> V_332 > V_335 ) {
F_96 ( V_329 L_32 ,
V_328 -> V_332 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_133 ( struct V_4 * V_42 )
{
int V_3 ;
T_9 V_336 = sizeof( struct V_58 ) * F_80 () ;
V_42 -> V_60 = F_111 ( V_336 , V_240 , V_42 -> V_330 ) ;
memset ( V_42 -> V_60 , 0 , V_336 ) ;
F_4 (cpu) {
V_42 -> V_60 [ V_3 ] . V_57 = F_131 ( V_3 ) -> V_57 ;
V_42 -> V_60 [ V_3 ] . V_7 = F_131 ( V_3 ) -> V_331 ;
}
}
static void F_134 ( struct V_4 * V_80 )
{
int V_337 = sizeof( T_2 ) ;
V_80 -> V_72 = F_135 ( V_337 , V_240 , V_80 -> V_330 ) ;
}
static int F_136 ( struct V_327 * V_328 , struct V_322 * V_326 ,
struct V_4 * * V_338 ,
struct V_4 * * V_339 )
{
int V_21 ;
int V_3 ;
struct V_4 * V_5 ;
for ( V_21 = 0 ; V_21 < V_328 -> V_332 ; V_21 ++ ) {
V_3 = V_328 -> V_334 [ V_21 ] ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_3 = V_3 ;
if ( V_21 == 0 ) {
* V_338 = V_5 ;
if ( ! ( * V_339 ) )
* V_339 = V_5 ;
}
V_5 -> V_56 = V_326 -> V_332 ;
V_5 -> V_53 = V_328 -> V_332 ;
V_5 -> V_43 = * V_338 ;
V_5 -> V_7 = V_326 -> V_7 ;
if ( F_116 () )
V_5 -> V_119 = 1 ;
else if ( F_78 () )
V_5 -> V_119 = 2 ;
else {
F_96 ( V_329 L_33 ) ;
return 1 ;
}
V_5 -> V_50 = * V_339 ;
V_5 -> V_104 = F_131 ( V_3 ) -> V_340 ;
if ( V_5 -> V_104 >= V_341 ) {
F_96 ( V_329 L_34 ,
V_5 -> V_104 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_137 ( int V_223 ,
struct V_322 * V_323 ,
unsigned char * V_324 )
{
int V_325 ;
int V_7 ;
unsigned short V_333 ;
for ( V_7 = 0 ; V_7 < V_223 ; V_7 ++ ) {
struct V_322 * V_326 ;
struct V_4 * V_42 = NULL ;
struct V_4 * V_80 = NULL ;
if ( ! ( * ( V_324 + ( V_7 / 8 ) ) & ( 1 << ( V_7 % 8 ) ) ) )
continue;
V_326 = & V_323 [ V_7 ] ;
V_333 = V_326 -> V_333 ;
V_325 = 0 ;
while ( V_333 ) {
struct V_327 * V_328 ;
if ( ( V_333 & 1 ) ) {
V_328 = & V_326 -> V_325 [ V_325 ] ;
if ( F_136 ( V_328 , V_326 , & V_42 , & V_80 ) )
return 1 ;
F_133 ( V_42 ) ;
}
V_325 ++ ;
V_333 = ( V_333 >> 1 ) ;
}
F_134 ( V_80 ) ;
}
return 0 ;
}
static int T_1 F_138 ( int V_223 , int V_342 )
{
unsigned char * V_324 ;
void * V_295 ;
struct V_322 * V_323 ;
V_96 = F_127 () ;
V_295 = F_139 ( V_223 * sizeof( struct V_322 ) , V_240 ) ;
V_323 = (struct V_322 * ) V_295 ;
memset ( V_323 , 0 , V_223 * sizeof( struct V_322 ) ) ;
V_324 = F_140 ( ( V_223 + 7 ) / 8 , V_240 ) ;
if ( F_130 ( V_342 , V_323 , V_324 ) )
goto V_343;
if ( F_137 ( V_223 , V_323 , V_324 ) )
goto V_343;
F_92 ( V_323 ) ;
F_92 ( V_324 ) ;
F_128 () ;
return 0 ;
V_343:
F_92 ( V_323 ) ;
F_92 ( V_324 ) ;
return 1 ;
}
static int T_1 F_141 ( void )
{
int V_7 ;
int V_57 ;
int V_223 ;
int V_344 ;
int V_345 ;
int V_302 ;
T_10 * V_71 ;
if ( ! F_106 () )
return 0 ;
F_142 (cur_cpu) {
V_71 = & F_5 ( V_205 , V_344 ) ;
F_143 ( V_71 , V_240 , F_132 ( V_344 ) ) ;
}
V_223 = F_73 () ;
V_148 = F_83 ( V_241 ) ;
V_346 = 0x7fffffff ;
for ( V_7 = 0 ; V_7 < V_223 ; V_7 ++ ) {
V_345 = F_74 ( V_7 ) ;
if ( V_345 && ( F_75 ( V_7 ) < V_346 ) )
V_346 = F_75 ( V_7 ) ;
}
F_72 () ;
if ( F_138 ( V_223 , V_346 ) ) {
F_6 () ;
V_6 = 1 ;
return 0 ;
}
V_302 = V_347 ;
F_144 (uvhub)
if ( F_74 ( V_7 ) )
F_125 ( V_7 , V_302 , V_346 ) ;
F_145 ( V_302 , V_348 ) ;
F_144 (uvhub) {
if ( F_74 ( V_7 ) ) {
unsigned long V_254 ;
unsigned long V_24 ;
V_57 = F_75 ( V_7 ) ;
V_254 = 1L << 63 ;
F_146 ( V_57 , V_254 ) ;
V_24 = 1 ;
if ( ! F_116 () )
F_147 ( V_57 , V_24 ) ;
}
}
return 0 ;
}
