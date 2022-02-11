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
static inline unsigned long long F_28 ( unsigned long long V_75 )
{
struct V_76 * V_77 = F_29 () ;
unsigned long long V_78 ;
V_78 = F_30 ( V_75 , V_77 -> V_79 , V_77 -> V_80 ) ;
F_31 ( V_77 ) ;
return V_78 ;
}
static inline unsigned long long F_32 ( unsigned long long V_78 )
{
struct V_76 * V_77 = F_29 () ;
unsigned long long V_75 ;
V_75 = ( V_78 << V_77 -> V_80 ) / V_77 -> V_79 ;
F_31 ( V_77 ) ;
return V_75 ;
}
static inline unsigned long F_33 ( unsigned long long V_75 )
{
return F_28 ( V_75 ) / V_81 ;
}
static inline T_3 F_34 ( unsigned long V_82 )
{
return F_32 ( V_82 * V_83 ) ;
}
static inline unsigned long long F_35 ( unsigned long V_84 )
{
return F_32 ( V_84 * V_81 ) ;
}
static inline void F_36 ( struct V_4 * V_85 )
{
F_19 ( 1 , (struct atomic_short * ) & V_85 -> V_86 ) ;
}
static inline void F_37 ( struct V_4 * V_85 )
{
F_19 ( - 1 , (struct atomic_short * ) & V_85 -> V_86 ) ;
}
static unsigned long F_38 ( unsigned long V_87 , int V_88 )
{
unsigned long V_89 ;
V_89 = F_39 ( V_87 ) ;
V_89 >>= V_88 ;
V_89 &= V_90 ;
return V_89 ;
}
static int F_40 ( struct V_91 * V_91 ,
unsigned long V_87 , int V_88 ,
struct V_4 * V_5 , long V_92 )
{
unsigned long V_89 ;
T_3 V_93 ;
struct V_26 * V_27 = V_5 -> V_28 ;
V_89 = F_38 ( V_87 , V_88 ) ;
while ( ( V_89 != V_94 ) ) {
if ( V_89 == V_95 ) {
V_27 -> V_96 ++ ;
return V_97 ;
} else if ( V_89 == V_98 ) {
V_27 -> V_99 ++ ;
V_93 = F_41 () ;
if ( F_33 ( V_93 - V_5 -> V_100 ) < V_101 ) {
V_5 -> V_102 = 0 ;
return V_103 ;
}
V_5 -> V_102 = 0 ;
return V_104 ;
} else {
F_42 () ;
}
V_89 = F_38 ( V_87 , V_88 ) ;
}
V_5 -> V_102 ++ ;
return V_105 ;
}
static unsigned long F_43 ( unsigned long V_106 , int V_107 , int V_108 )
{
unsigned long V_89 ;
V_89 =
( ( F_44 ( V_106 ) >> V_107 ) & V_90 ) << 1 ;
return V_89 ;
}
int F_45 ( struct V_4 * V_5 )
{
int V_3 = V_5 -> V_109 ;
int V_87 ;
int V_88 ;
V_87 = V_110 ;
V_88 = V_3 * V_111 ;
return ( ( ( ( ( F_44 ( V_87 ) >> V_88 ) &
V_90 ) ) << 1 ) == V_112 ) ;
}
int F_46 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_28 ;
V_27 -> V_113 ++ ;
V_5 -> V_114 = 1 ;
return V_97 ;
}
static int F_47 ( struct V_91 * V_91 ,
unsigned long V_87 , int V_88 ,
struct V_4 * V_5 , long V_92 )
{
unsigned long V_115 ;
T_3 V_93 ;
int V_108 = V_5 -> V_109 ;
long V_116 = 0 ;
struct V_26 * V_27 = V_5 -> V_28 ;
V_115 = F_43 ( V_87 , V_88 , V_108 ) ;
while ( V_115 != V_117 ) {
if ( ( V_115 == V_118 ) ) {
V_27 -> V_96 ++ ;
return V_97 ;
} else if ( V_115 == V_119 ) {
V_93 = F_41 () ;
if ( F_33 ( V_93 - V_5 -> V_100 ) < V_101 ) {
V_5 -> V_102 = 0 ;
V_27 -> V_120 ++ ;
return V_97 ;
}
V_27 -> V_99 ++ ;
V_5 -> V_102 = 0 ;
return V_97 ;
} else {
V_116 ++ ;
if ( V_116 > 1000000 ) {
V_116 = 0 ;
V_93 = F_41 () ;
if ( ( V_93 - V_5 -> V_100 ) >
V_5 -> V_121 )
return F_46 ( V_5 ) ;
}
F_42 () ;
}
V_115 = F_43 ( V_87 , V_88 ,
V_108 ) ;
}
V_5 -> V_102 ++ ;
return V_105 ;
}
static int F_48 ( struct V_91 * V_91 ,
struct V_4 * V_5 , long V_92 )
{
int V_88 ;
unsigned long V_87 ;
int V_108 = V_5 -> V_109 ;
if ( V_108 < V_122 ) {
V_87 = V_110 ;
V_88 = V_108 * V_111 ;
} else {
V_87 = V_123 ;
V_88 = ( ( V_108 - V_122 ) * V_111 ) ;
}
if ( V_5 -> V_124 == 1 )
return F_40 ( V_91 , V_87 , V_88 ,
V_5 , V_92 ) ;
else
return F_47 ( V_91 , V_87 , V_88 ,
V_5 , V_92 ) ;
}
static void F_49 ( struct V_91 * V_91 ,
struct V_4 * V_5 ,
struct V_4 * V_85 , struct V_26 * V_27 )
{
F_50 ( V_5 -> V_125 ) ;
V_5 -> V_126 ++ ;
if ( V_5 -> V_126 >= V_5 -> V_127 ) {
V_5 -> V_126 = 0 ;
F_36 ( V_85 ) ;
F_51 ( & V_85 -> V_128 ) ;
F_23 ( & V_91 -> V_68 , V_5 ) ;
F_52 ( & V_85 -> V_128 ) ;
F_37 ( V_85 ) ;
V_5 -> V_129 ++ ;
V_27 -> V_130 ++ ;
}
}
static void F_53 ( struct V_91 * V_91 ,
struct V_4 * V_5 , struct V_4 * V_85 ,
struct V_26 * V_27 )
{
V_85 -> V_131 = 1 ;
V_5 -> V_132 ++ ;
if ( V_5 -> V_132 >= V_5 -> V_133 ) {
V_5 -> V_132 = 0 ;
F_36 ( V_85 ) ;
F_51 ( & V_85 -> V_128 ) ;
F_23 ( & V_91 -> V_68 , V_5 ) ;
F_52 ( & V_85 -> V_128 ) ;
F_37 ( V_85 ) ;
V_5 -> V_129 ++ ;
V_27 -> V_134 ++ ;
}
}
static void F_54 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
int V_135 ;
struct V_4 * V_136 ;
struct V_4 * V_85 ;
T_3 V_137 ;
V_85 = V_5 -> V_50 ;
F_51 ( & V_85 -> V_138 ) ;
if ( ! V_5 -> V_139 ) {
V_27 -> V_140 ++ ;
V_137 = F_41 () ;
F_4 (tcpu) {
V_136 = & F_5 ( V_4 , V_135 ) ;
if ( V_136 -> V_50 == V_85 ) {
V_136 -> V_139 = 1 ;
V_136 -> V_141 =
V_137 + V_5 -> V_142 ;
}
}
}
F_52 ( & V_85 -> V_138 ) ;
}
static void F_55 ( int V_27 , struct V_4 * V_5 ,
struct V_4 * V_85 )
{
V_5 -> V_126 = 0 ;
V_5 -> V_132 = 0 ;
if ( V_27 != V_105 )
return;
if ( V_5 -> V_102 <= V_5 -> V_143 )
return;
if ( V_85 -> V_131 >= V_85 -> V_144 )
return;
V_85 -> V_131 ++ ;
}
static void F_56 ( T_3 V_145 , T_3 V_146 ,
struct V_4 * V_5 , struct V_26 * V_27 ,
int V_147 , int V_92 )
{
T_3 V_148 ;
if ( V_146 > V_145 ) {
V_148 = V_146 - V_145 ;
V_27 -> V_149 += V_148 ;
if ( ( V_147 == V_105 ) && ( V_92 == 1 ) ) {
V_5 -> V_150 ++ ;
V_5 -> V_151 += V_148 ;
if ( ( V_148 > V_152 ) &&
( V_5 -> V_150 > V_5 -> V_153 ) &&
( ( V_5 -> V_151 / V_5 -> V_150 ) >
V_152 ) ) {
V_27 -> V_154 ++ ;
F_54 ( V_5 , V_27 ) ;
}
}
} else
V_27 -> V_155 -- ;
if ( V_147 == V_105 && V_92 > 1 )
V_27 -> V_156 ++ ;
else if ( V_147 == V_97 ) {
V_27 -> V_157 ++ ;
if ( F_41 () > V_5 -> V_158 )
V_5 -> V_159 = 0 ;
V_5 -> V_159 ++ ;
if ( V_5 -> V_159 == 1 )
V_5 -> V_158 = F_41 () + V_5 -> V_142 ;
if ( V_5 -> V_159 > V_5 -> V_160 ) {
F_54 ( V_5 , V_27 ) ;
V_27 -> V_161 ++ ;
}
}
}
static void F_57 ( struct V_4 * V_85 , struct V_26 * V_27 )
{
T_4 * V_162 = & V_85 -> V_163 ;
T_5 * V_164 ;
V_164 = & V_85 -> V_165 ;
if ( ! F_58 ( V_162 , V_164 , V_85 -> V_131 ) ) {
V_27 -> V_166 ++ ;
do {
F_42 () ;
} while ( ! F_58 ( V_162 , V_164 , V_85 -> V_131 ) );
}
}
static void F_59 ( int V_147 , struct V_91 * V_91 ,
struct V_4 * V_5 , struct V_4 * V_85 ,
struct V_26 * V_27 )
{
if ( V_147 == V_103 )
F_49 ( V_91 , V_5 , V_85 , V_27 ) ;
else if ( V_147 == V_104 )
F_53 ( V_91 , V_5 , V_85 , V_27 ) ;
}
int F_60 ( struct V_72 * V_167 , struct V_4 * V_5 ,
struct V_91 * V_91 )
{
int V_168 = 0 ;
int V_169 = 0 ;
int V_170 = 0 ;
long V_92 = 0 ;
unsigned long V_171 ;
T_3 V_145 ;
T_3 V_146 ;
struct V_26 * V_27 = V_5 -> V_28 ;
struct V_4 * V_85 = V_5 -> V_50 ;
struct V_172 * V_173 = NULL ;
struct V_174 * V_175 = NULL ;
if ( V_5 -> V_124 == 1 ) {
V_170 = 1 ;
F_57 ( V_85 , V_27 ) ;
}
while ( V_85 -> V_86 )
F_42 () ;
V_145 = F_41 () ;
if ( V_170 )
V_173 = & V_91 -> V_176 . V_173 ;
else
V_175 = & V_91 -> V_176 . V_175 ;
do {
if ( V_92 == 0 ) {
if ( V_170 )
V_173 -> V_34 = V_177 ;
else
V_175 -> V_34 = V_177 ;
V_168 = V_5 -> V_178 ++ ;
} else {
if ( V_170 )
V_173 -> V_34 = V_49 ;
else
V_175 -> V_34 = V_49 ;
V_27 -> V_179 ++ ;
}
if ( V_170 )
V_173 -> V_180 = V_168 ;
else
V_175 -> V_180 = V_168 ;
V_171 = ( 1UL << V_181 ) | V_5 -> V_109 ;
V_5 -> V_100 = F_41 () ;
F_61 ( V_171 ) ;
V_92 ++ ;
V_169 = F_48 ( V_91 , V_5 , V_92 ) ;
F_59 ( V_169 , V_91 , V_5 , V_85 , V_27 ) ;
if ( V_5 -> V_129 >= V_5 -> V_182 ) {
V_5 -> V_129 = 0 ;
V_27 -> V_183 ++ ;
V_169 = V_97 ;
break;
}
F_42 () ;
} while ( ( V_169 == V_103 ) ||
( V_169 == V_104 ) );
V_146 = F_41 () ;
F_55 ( V_169 , V_5 , V_85 ) ;
while ( V_85 -> V_86 )
F_42 () ;
F_62 ( & V_85 -> V_165 ) ;
F_56 ( V_145 , V_146 , V_5 , V_27 , V_169 , V_92 ) ;
if ( V_169 == V_97 )
return 1 ;
return 0 ;
}
static int F_63 ( struct V_4 * V_5 , struct V_26 * V_27 )
{
int V_135 ;
struct V_4 * V_136 ;
struct V_4 * V_85 ;
V_85 = V_5 -> V_50 ;
F_51 ( & V_85 -> V_138 ) ;
if ( V_5 -> V_139 && ( F_41 () >= V_5 -> V_141 ) ) {
V_27 -> V_184 ++ ;
F_4 (tcpu) {
V_136 = & F_5 ( V_4 , V_135 ) ;
if ( V_136 -> V_50 == V_85 ) {
V_136 -> V_139 = 0 ;
V_136 -> V_150 = 0 ;
V_136 -> V_151 = 0 ;
V_136 -> V_159 = 0 ;
}
}
F_52 ( & V_85 -> V_138 ) ;
return 0 ;
}
F_52 ( & V_85 -> V_138 ) ;
return - 1 ;
}
static void F_64 ( struct V_26 * V_27 , int V_185 , int V_186 ,
int V_187 , struct V_91 * V_91 )
{
V_27 -> V_155 ++ ;
V_27 -> V_188 += V_187 + V_185 ;
V_27 -> V_189 += V_187 ;
V_27 -> V_190 += V_185 ;
V_186 = F_65 ( & V_91 -> V_68 ) ;
if ( V_185 ) {
V_27 -> V_191 ++ ;
V_27 -> V_192 += ( V_186 - 1 ) ;
} else
V_27 -> V_192 += V_186 ;
V_27 -> V_193 += V_186 ;
if ( V_186 >= 16 )
V_27 -> V_194 ++ ;
else if ( V_186 >= 8 )
V_27 -> V_195 ++ ;
else if ( V_186 >= 4 )
V_27 -> V_196 ++ ;
else if ( V_186 >= 2 )
V_27 -> V_197 ++ ;
else
V_27 -> V_198 ++ ;
}
static int F_66 ( struct V_72 * V_167 , struct V_4 * V_5 ,
struct V_91 * V_91 , int * V_199 , int * V_200 )
{
int V_3 ;
int V_57 ;
int V_201 = 0 ;
struct V_58 * V_59 ;
F_67 (cpu, flush_mask) {
V_59 = & V_5 -> V_43 -> V_60 [ V_3 ] ;
V_57 = V_59 -> V_57 - V_5 -> V_74 ;
F_68 ( V_57 , & V_91 -> V_68 ) ;
V_201 ++ ;
if ( V_59 -> V_7 == V_5 -> V_7 )
( * V_199 ) ++ ;
else
( * V_200 ) ++ ;
}
if ( ! V_201 )
return 1 ;
return 0 ;
}
const struct V_72 * F_69 ( const struct V_72 * V_72 ,
struct V_202 * V_203 , unsigned long V_204 ,
unsigned long V_205 , unsigned int V_3 )
{
int V_185 = 0 ;
int V_187 = 0 ;
int V_186 = 0 ;
struct V_91 * V_91 ;
struct V_72 * V_167 ;
struct V_26 * V_27 ;
struct V_4 * V_5 ;
unsigned long V_89 ;
unsigned long V_206 ;
V_5 = & F_5 ( V_4 , V_3 ) ;
if ( V_5 -> V_2 )
return V_72 ;
V_27 = V_5 -> V_28 ;
V_27 -> V_207 ++ ;
if ( V_5 -> V_114 ) {
V_89 =
F_44 ( V_110 ) ;
V_206 = ( ( V_89 >> ( V_5 -> V_109 *
V_111 ) ) & V_90 ) << 1 ;
if ( V_206 == V_112 )
return V_72 ;
V_5 -> V_114 = 0 ;
}
if ( V_5 -> V_139 ) {
if ( F_63 ( V_5 , V_27 ) ) {
V_27 -> V_208 ++ ;
return V_72 ;
}
}
V_167 = (struct V_72 * ) F_5 ( V_209 , V_3 ) ;
F_70 ( V_167 , V_72 , F_71 ( V_3 ) ) ;
if ( F_72 ( V_3 , * V_72 ) )
V_27 -> V_210 ++ ;
V_91 = V_5 -> V_211 ;
V_91 += ( V_212 * V_5 -> V_109 ) ;
F_73 ( & V_91 -> V_68 , V_213 ) ;
if ( F_66 ( V_167 , V_5 , V_91 , & V_185 , & V_187 ) )
return NULL ;
F_64 ( V_27 , V_185 , V_186 , V_187 , V_91 ) ;
if ( ! V_205 || ( V_205 - V_204 ) <= V_214 )
V_91 -> V_215 . V_44 = V_204 ;
else
V_91 -> V_215 . V_44 = V_45 ;
V_91 -> V_215 . V_33 = V_3 ;
if ( ! F_60 ( V_167 , V_5 , V_91 ) )
return NULL ;
else
return V_72 ;
}
struct V_15 * F_74 ( struct V_15 * V_16 ,
struct V_4 * V_5 )
{
struct V_15 * V_216 = V_16 + 1 ;
unsigned char V_18 = V_16 -> V_18 ;
if ( V_216 > V_5 -> V_31 )
V_216 = V_5 -> V_32 ;
while ( V_216 != V_16 ) {
if ( ( V_216 -> V_17 == 0 ) && ( V_216 -> V_20 == 0 ) &&
( V_216 -> V_18 == V_18 ) )
return V_216 ;
V_216 ++ ;
if ( V_216 > V_5 -> V_31 )
V_216 = V_5 -> V_32 ;
}
return NULL ;
}
void F_75 ( struct V_11 * V_12 , struct V_4 * V_5 )
{
unsigned long V_217 ;
unsigned char V_18 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_15 * V_218 ;
V_217 = F_15 () ;
V_18 = V_16 -> V_18 ;
if ( ( V_18 & V_217 ) == 0 ) {
V_218 = F_74 ( V_16 , V_5 ) ;
if ( V_218 ) {
F_16 ( V_12 , V_5 , 0 ) ;
return;
}
}
F_16 ( V_12 , V_5 , 1 ) ;
return;
}
void F_76 ( struct V_219 * V_220 )
{
int V_221 = 0 ;
T_3 V_222 ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_11 V_223 ;
F_77 () ;
V_222 = F_41 () ;
V_5 = & F_5 ( V_4 , F_22 () ) ;
V_27 = V_5 -> V_28 ;
V_223 . V_32 = V_5 -> V_32 ;
V_223 . V_31 = V_5 -> V_31 ;
V_16 = V_5 -> V_224 ;
while ( V_16 -> V_18 ) {
V_221 ++ ;
V_223 . V_52 = V_16 - V_223 . V_32 ;
V_223 . V_16 = V_16 ;
if ( V_5 -> V_124 == 2 )
F_75 ( & V_223 , V_5 ) ;
else
F_16 ( & V_223 , V_5 , 1 ) ;
V_16 ++ ;
if ( V_16 > V_223 . V_31 )
V_16 = V_223 . V_32 ;
V_5 -> V_224 = V_16 ;
}
V_27 -> V_225 += ( F_41 () - V_222 ) ;
if ( ! V_221 )
V_27 -> V_226 ++ ;
else if ( V_221 > 1 )
V_27 -> V_227 ++ ;
}
static void T_1 F_78 ( void )
{
int V_7 ;
int V_228 ;
int V_57 ;
unsigned long V_217 ;
V_228 = F_79 () ;
for ( V_7 = 0 ; V_7 < V_228 ; V_7 ++ ) {
if ( ! F_80 ( V_7 ) )
continue;
V_57 = F_81 ( V_7 ) ;
V_217 = F_82 ( V_57 ) ;
V_217 &= ~ ( 1L << V_229 ) ;
F_83 ( V_57 , V_217 ) ;
V_217 &= ~ ( ( unsigned long ) 0xf << V_230 ) ;
V_217 |= ( V_231 << V_230 ) ;
F_83 ( V_57 , V_217 ) ;
V_217 |= ( 1L << V_229 ) ;
if ( F_84 () ) {
V_217 &= ~ ( 1L << V_232 ) ;
}
F_83 ( V_57 , V_217 ) ;
}
}
static void * F_85 ( struct V_233 * V_234 , T_6 * V_106 )
{
if ( * V_106 < F_86 () )
return V_106 ;
return NULL ;
}
static void * F_87 ( struct V_233 * V_234 , void * V_77 , T_6 * V_106 )
{
( * V_106 ) ++ ;
if ( * V_106 < F_86 () )
return V_106 ;
return NULL ;
}
static void F_88 ( struct V_233 * V_234 , void * V_77 )
{
}
static int F_89 ( struct V_233 * V_234 , void * V_77 )
{
struct V_26 * V_27 ;
struct V_4 * V_5 ;
int V_3 ;
V_3 = * ( T_6 * ) V_77 ;
if ( ! V_3 ) {
F_90 ( V_234 ,
L_4 ) ;
F_90 ( V_234 ,
L_5 ) ;
F_90 ( V_234 ,
L_6 ) ;
F_90 ( V_234 ,
L_7 ) ;
F_90 ( V_234 ,
L_8 ) ;
F_90 ( V_234 ,
L_9 ) ;
F_90 ( V_234 ,
L_10 ) ;
}
if ( V_3 < F_86 () && F_91 ( V_3 ) ) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_27 = V_5 -> V_28 ;
F_90 ( V_234 ,
L_11 ,
V_3 , V_5 -> V_2 , V_27 -> V_155 ,
F_33 ( V_27 -> V_149 ) ,
V_27 -> V_210 , V_27 -> V_190 ,
V_27 -> V_189 , V_27 -> V_188 ,
V_27 -> V_191 , V_27 -> V_192 ,
V_27 -> V_193 , V_27 -> V_194 ) ;
F_90 ( V_234 , L_12 ,
V_27 -> V_195 , V_27 -> V_196 ,
V_27 -> V_197 , V_27 -> V_198 ,
V_27 -> V_99 , V_27 -> V_235 ) ;
F_90 ( V_234 , L_13 ,
V_27 -> V_179 , V_27 -> V_156 ,
V_27 -> V_130 , V_27 -> V_134 ,
V_27 -> V_157 , V_27 -> V_96 ,
V_27 -> V_236 , V_27 -> V_166 ) ;
F_90 ( V_234 , L_14 ,
V_27 -> V_140 , V_27 -> V_184 ,
V_27 -> V_113 , V_27 -> V_237 ,
V_27 -> V_238 , V_27 -> V_207 ,
V_27 -> V_208 , V_27 -> V_120 ,
V_27 -> V_183 , V_27 -> V_161 ,
V_27 -> V_154 ) ;
F_90 ( V_234 ,
L_15 ,
F_92 ( F_93 ( V_3 ) ) ,
V_27 -> V_48 , F_33 ( V_27 -> V_225 ) ,
V_27 -> V_46 , V_27 -> V_47 , V_27 -> V_227 ,
V_27 -> V_226 , V_27 -> V_29 , V_27 -> V_37 ,
V_27 -> V_38 , V_27 -> V_64 ,
V_27 -> V_66 ) ;
}
return 0 ;
}
static T_7 F_94 ( struct V_234 * V_234 , char T_8 * V_239 ,
T_9 V_221 , T_6 * V_240 )
{
char * V_241 ;
int V_242 ;
V_241 = F_95 ( V_243 , L_16 ,
L_17 ,
L_18 ,
L_19 ,
V_131 , V_125 , V_127 ,
V_133 , V_182 , V_143 ,
V_244 , V_245 , V_142 ,
V_160 ) ;
if ( ! V_241 )
return - V_246 ;
V_242 = F_96 ( V_239 , V_221 , V_240 , V_241 , strlen ( V_241 ) ) ;
F_97 ( V_241 ) ;
return V_242 ;
}
static T_7 F_98 ( struct V_234 * V_234 , const char T_8 * V_247 ,
T_9 V_221 , T_6 * V_77 )
{
int V_3 ;
int V_21 ;
int V_248 ;
long V_249 ;
char V_250 [ 64 ] ;
struct V_26 * V_27 ;
if ( V_221 == 0 || V_221 > sizeof( V_250 ) )
return - V_251 ;
if ( F_99 ( V_250 , V_247 , V_221 ) )
return - V_252 ;
V_250 [ V_221 - 1 ] = '\0' ;
if ( ! strcmp ( V_250 , L_20 ) ) {
F_2 () ;
return V_221 ;
} else if ( ! strcmp ( V_250 , L_21 ) ) {
F_6 () ;
return V_221 ;
}
if ( F_100 ( V_250 , 10 , & V_249 ) < 0 ) {
F_101 ( V_253 L_22 , V_250 ) ;
return - V_251 ;
}
if ( V_249 == 0 ) {
V_248 = F_102 ( V_254 ) ;
F_101 ( V_253 L_23 ) ;
F_101 ( V_253 L_24 ) ;
for ( V_21 = 0 ; V_21 < V_248 ; V_21 ++ )
F_101 ( V_253 L_25 , V_254 [ V_21 ] ) ;
} else if ( V_249 == - 1 ) {
F_4 (cpu) {
V_27 = & F_5 ( V_255 , V_3 ) ;
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
}
}
return V_221 ;
}
static int F_103 ( const char * V_256 )
{
int V_257 = 0 ;
for (; ; V_256 ++ ) {
switch ( * V_256 ) {
case '0' ... '9' :
V_257 = 10 * V_257 + ( * V_256 - '0' ) ;
break;
default:
return V_257 ;
}
}
}
static int F_104 ( struct V_4 * V_5 , char * V_258 ,
int V_221 )
{
char * V_259 ;
char * V_260 ;
int V_201 = 0 ;
int V_257 ;
int V_261 = F_102 ( V_262 ) ;
V_259 = V_258 + strspn ( V_258 , V_263 ) ;
V_260 = V_259 ;
for (; * V_259 ; V_259 = V_260 + strspn ( V_260 , V_263 ) ) {
V_260 = V_259 + strcspn ( V_259 , V_263 ) ;
V_201 ++ ;
if ( V_260 == V_259 )
break;
}
if ( V_201 != V_261 ) {
F_101 ( V_264 L_26 , V_261 ) ;
return - V_251 ;
}
V_259 = V_258 + strspn ( V_258 , V_263 ) ;
V_260 = V_259 ;
for ( V_201 = 0 ; * V_259 ; V_259 = V_260 + strspn ( V_260 , V_263 ) , V_201 ++ ) {
V_260 = V_259 + strcspn ( V_259 , V_263 ) ;
V_257 = F_103 ( V_259 ) ;
switch ( V_201 ) {
case 0 :
if ( V_257 == 0 ) {
V_131 = V_265 ;
V_144 = V_265 ;
continue;
}
if ( V_257 < 1 || V_257 > V_5 -> V_56 ) {
F_101 ( V_253
L_27 ,
V_257 ) ;
return - V_251 ;
}
V_131 = V_257 ;
V_144 = V_257 ;
continue;
default:
if ( V_257 == 0 )
* V_262 [ V_201 ] . V_266 = V_262 [ V_201 ] . V_267 ;
else
* V_262 [ V_201 ] . V_266 = V_257 ;
continue;
}
if ( V_260 == V_259 )
break;
}
return 0 ;
}
static T_7 F_105 ( struct V_234 * V_234 , const char T_8 * V_247 ,
T_9 V_221 , T_6 * V_77 )
{
int V_3 ;
int V_242 ;
char V_258 [ 100 ] ;
struct V_4 * V_5 ;
if ( V_221 == 0 || V_221 > sizeof( V_258 ) - 1 )
return - V_251 ;
if ( F_99 ( V_258 , V_247 , V_221 ) )
return - V_252 ;
V_258 [ V_221 ] = '\0' ;
V_3 = F_106 () ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_242 = F_104 ( V_5 , V_258 , V_221 ) ;
F_107 () ;
if ( V_242 )
return V_242 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_131 = V_131 ;
V_5 -> V_144 = V_131 ;
V_5 -> V_125 = V_125 ;
V_5 -> V_127 = V_127 ;
V_5 -> V_133 = V_133 ;
V_5 -> V_182 = V_182 ;
V_5 -> V_143 = V_143 ;
V_5 -> V_268 = V_244 ;
V_5 -> V_153 = V_245 ;
V_5 -> V_142 = F_34 ( V_142 ) ;
V_5 -> V_160 = V_160 ;
}
return V_221 ;
}
static int F_108 ( struct V_269 * V_269 , struct V_234 * V_234 )
{
return F_109 ( V_234 , & V_270 ) ;
}
static int F_110 ( struct V_269 * V_269 , struct V_234 * V_234 )
{
return 0 ;
}
static int T_1 F_111 ( void )
{
struct V_271 * V_272 ;
if ( ! F_112 () )
return 0 ;
V_272 = F_113 ( V_273 , 0444 , NULL ,
& V_274 ) ;
if ( ! V_272 ) {
F_101 ( V_275 L_28 ,
V_273 ) ;
return - V_251 ;
}
V_276 = F_114 ( V_277 , NULL ) ;
if ( ! V_276 ) {
F_101 ( V_275 L_29 ,
V_277 ) ;
return - V_251 ;
}
V_278 = F_115 ( V_279 , 0600 ,
V_276 , NULL , & V_280 ) ;
if ( ! V_278 ) {
F_101 ( V_275 L_30 ,
V_279 ) ;
return - V_251 ;
}
return 0 ;
}
static void F_116 ( int V_8 , int V_57 , int V_281 )
{
int V_21 ;
int V_3 ;
int V_170 = 0 ;
unsigned long V_282 ;
unsigned long V_283 ;
unsigned long V_284 ;
T_9 V_285 ;
struct V_91 * V_91 ;
struct V_91 * V_286 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_4 * V_5 ;
V_285 = sizeof( struct V_91 ) * V_287 * V_212 ;
V_91 = F_117 ( V_285 , V_243 , V_8 ) ;
F_118 ( ! V_91 ) ;
V_282 = F_119 ( V_91 ) ;
V_284 = F_120 ( V_282 ) ;
V_283 = F_121 ( V_282 ) ;
if ( F_122 () )
V_170 = 1 ;
F_123 ( V_57 , ( V_284 << V_288 | V_283 ) ) ;
for ( V_21 = 0 , V_286 = V_91 ; V_21 < ( V_287 * V_212 ) ; V_21 ++ , V_286 ++ ) {
memset ( V_286 , 0 , sizeof( struct V_91 ) ) ;
if ( V_170 ) {
V_173 = & V_286 -> V_176 . V_173 ;
V_173 -> V_289 = 1 ;
V_173 -> V_290 =
F_124 ( V_281 ) ;
V_173 -> V_291 = V_292 ;
V_173 -> V_293 = V_294 ;
V_173 -> V_295 = 1 ;
} else {
V_175 = & V_286 -> V_176 . V_175 ;
V_175 -> V_289 = 1 ;
V_175 -> V_290 =
F_124 ( V_281 ) ;
V_175 -> V_291 = V_292 ;
V_175 -> V_293 = V_294 ;
}
}
F_4 (cpu) {
if ( V_57 != F_81 ( F_11 ( V_3 ) ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_211 = V_91 ;
}
}
static void F_125 ( int V_8 , int V_57 )
{
int V_3 ;
T_9 V_296 ;
char * V_297 ;
void * V_298 ;
unsigned long V_299 ;
unsigned long V_300 ;
unsigned long V_301 ;
unsigned long V_302 ;
struct V_15 * V_303 ;
struct V_4 * V_5 ;
V_296 = ( V_30 + 1 ) * sizeof( struct V_15 ) ;
V_298 = F_117 ( V_296 , V_243 , V_8 ) ;
V_303 = (struct V_15 * ) V_298 ;
F_118 ( ! V_303 ) ;
V_297 = ( char * ) V_303 + 31 ;
V_303 = (struct V_15 * ) ( ( ( unsigned long ) V_297 >> 5 ) << 5 ) ;
F_4 (cpu) {
if ( V_57 != F_93 ( V_3 ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_32 = V_303 ;
V_5 -> V_224 = V_303 ;
V_5 -> V_31 = V_303 + ( V_30 - 1 ) ;
}
V_299 = F_120 ( F_119 ( V_303 ) ) ;
V_300 = F_126 ( V_303 ) ;
V_301 = ( ( unsigned long ) V_299 << V_304 ) | V_300 ;
V_302 = F_126 ( V_303 + ( V_30 - 1 ) ) ;
F_127 ( V_57 , V_301 ) ;
F_128 ( V_57 , V_300 ) ;
F_129 ( V_57 , V_302 ) ;
F_130 ( V_57 , 0xffffUL ) ;
memset ( V_303 , 0 , sizeof( struct V_15 ) * V_30 ) ;
}
static void T_1 F_131 ( int V_7 , int V_305 , int V_281 )
{
int V_8 ;
int V_57 ;
unsigned long V_306 ;
V_8 = F_7 ( V_7 ) ;
V_57 = F_81 ( V_7 ) ;
F_116 ( V_8 , V_57 , V_281 ) ;
F_125 ( V_8 , V_57 ) ;
V_306 = F_10 ( V_7 ) | V_307 ;
F_132 ( V_57 , ( ( V_306 << 32 ) | V_305 ) ) ;
}
static int F_133 ( void )
{
unsigned long V_217 ;
int V_308 ;
int V_309 ;
int V_171 ;
int V_310 ;
int V_242 ;
unsigned long V_311 ;
if ( F_122 () ) {
V_308 = V_231 & V_312 ;
V_217 = F_39 ( V_313 ) ;
V_171 = ( V_217 >> V_314 ) & V_315 ;
V_217 = F_39 ( V_316 ) ;
V_309 = ( V_217 >> V_317 ) & V_318 ;
V_311 = V_319 [ V_171 ] ;
V_311 *= ( V_308 * V_309 ) ;
V_242 = V_311 / 1000 ;
} else {
V_217 = F_39 ( V_320 ) ;
V_217 = ( V_217 & V_321 ) >> V_322 ;
if ( V_217 & ( 1L << V_323 ) )
V_310 = 80 ;
else
V_310 = 10 ;
V_308 = V_217 & V_324 ;
V_242 = V_308 * V_310 ;
}
return V_242 ;
}
static void T_1 F_134 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_139 = 0 ;
if ( V_2 )
V_5 -> V_2 = 1 ;
V_5 -> V_28 = & F_5 ( V_255 , V_3 ) ;
V_5 -> V_121 = F_35 ( 2 * V_101 ) ;
V_5 -> V_131 = V_131 ;
V_5 -> V_144 = V_131 ;
V_5 -> V_125 = V_125 ;
V_5 -> V_127 = V_127 ;
V_5 -> V_133 = V_133 ;
V_5 -> V_182 = V_182 ;
V_5 -> V_143 = V_143 ;
V_5 -> V_268 = V_244 ;
V_5 -> V_153 = V_245 ;
V_5 -> V_142 = F_34 ( V_142 ) ;
V_5 -> V_160 = V_160 ;
F_135 ( & V_5 -> V_128 ) ;
F_135 ( & V_5 -> V_163 ) ;
F_135 ( & V_5 -> V_138 ) ;
}
}
static int T_1 F_136 ( int V_281 ,
struct V_325 * V_326 ,
unsigned char * V_327 )
{
int V_3 ;
int V_57 ;
int V_7 ;
int V_328 ;
struct V_4 * V_5 ;
struct V_325 * V_329 ;
struct V_330 * V_331 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_57 = F_137 ( V_3 ) -> V_57 ;
if ( ( V_57 - V_281 ) >= V_213 ) {
F_101 ( V_332
L_31 ,
V_3 , V_57 , V_281 , V_213 ) ;
return 1 ;
}
V_5 -> V_333 = F_138 ( V_3 ) ;
V_5 -> V_74 = V_281 ;
V_7 = F_137 ( V_3 ) -> V_334 ;
* ( V_327 + ( V_7 / 8 ) ) |= ( 1 << ( V_7 % 8 ) ) ;
V_329 = & V_326 [ V_7 ] ;
V_329 -> V_335 ++ ;
V_329 -> V_7 = V_7 ;
V_329 -> V_57 = V_57 ;
V_328 = V_5 -> V_333 & 1 ;
V_329 -> V_336 |= ( 1 << V_328 ) ;
V_331 = & V_329 -> V_328 [ V_328 ] ;
V_331 -> V_337 [ V_331 -> V_335 ] = V_3 ;
V_331 -> V_335 ++ ;
if ( V_331 -> V_335 > V_338 ) {
F_101 ( V_332 L_32 ,
V_331 -> V_335 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_139 ( struct V_4 * V_42 )
{
int V_3 ;
T_9 V_339 = sizeof( struct V_58 ) * F_86 () ;
V_42 -> V_60 = F_117 ( V_339 , V_243 , V_42 -> V_333 ) ;
memset ( V_42 -> V_60 , 0 , V_339 ) ;
F_4 (cpu) {
V_42 -> V_60 [ V_3 ] . V_57 = F_137 ( V_3 ) -> V_57 ;
V_42 -> V_60 [ V_3 ] . V_7 = F_137 ( V_3 ) -> V_334 ;
}
}
static void F_140 ( struct V_4 * V_85 )
{
int V_340 = sizeof( T_2 ) ;
V_85 -> V_72 = F_141 ( V_340 , V_243 , V_85 -> V_333 ) ;
}
static int F_142 ( struct V_330 * V_331 , struct V_325 * V_329 ,
struct V_4 * * V_341 ,
struct V_4 * * V_342 )
{
int V_21 ;
int V_3 ;
struct V_4 * V_5 ;
for ( V_21 = 0 ; V_21 < V_331 -> V_335 ; V_21 ++ ) {
V_3 = V_331 -> V_337 [ V_21 ] ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_3 = V_3 ;
if ( V_21 == 0 ) {
* V_341 = V_5 ;
if ( ! ( * V_342 ) )
* V_342 = V_5 ;
}
V_5 -> V_56 = V_329 -> V_335 ;
V_5 -> V_53 = V_331 -> V_335 ;
V_5 -> V_43 = * V_341 ;
V_5 -> V_7 = V_329 -> V_7 ;
if ( F_122 () )
V_5 -> V_124 = 1 ;
else if ( F_84 () )
V_5 -> V_124 = 2 ;
else {
F_101 ( V_332 L_33 ) ;
return 1 ;
}
V_5 -> V_50 = * V_342 ;
V_5 -> V_109 = F_137 ( V_3 ) -> V_343 ;
if ( V_5 -> V_109 >= V_344 ) {
F_101 ( V_332 L_34 ,
V_5 -> V_109 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_143 ( int V_228 ,
struct V_325 * V_326 ,
unsigned char * V_327 )
{
int V_328 ;
int V_7 ;
unsigned short V_336 ;
for ( V_7 = 0 ; V_7 < V_228 ; V_7 ++ ) {
struct V_325 * V_329 ;
struct V_4 * V_42 = NULL ;
struct V_4 * V_85 = NULL ;
if ( ! ( * ( V_327 + ( V_7 / 8 ) ) & ( 1 << ( V_7 % 8 ) ) ) )
continue;
V_329 = & V_326 [ V_7 ] ;
V_336 = V_329 -> V_336 ;
V_328 = 0 ;
while ( V_336 ) {
struct V_330 * V_331 ;
if ( ( V_336 & 1 ) ) {
V_331 = & V_329 -> V_328 [ V_328 ] ;
if ( F_142 ( V_331 , V_329 , & V_42 , & V_85 ) )
return 1 ;
F_139 ( V_42 ) ;
}
V_328 ++ ;
V_336 = ( V_336 >> 1 ) ;
}
F_140 ( V_85 ) ;
}
return 0 ;
}
static int T_1 F_144 ( int V_228 , int V_345 )
{
unsigned char * V_327 ;
void * V_298 ;
struct V_325 * V_326 ;
V_101 = F_133 () ;
V_298 = F_145 ( V_228 * sizeof( struct V_325 ) , V_243 ) ;
V_326 = (struct V_325 * ) V_298 ;
memset ( V_326 , 0 , V_228 * sizeof( struct V_325 ) ) ;
V_327 = F_146 ( ( V_228 + 7 ) / 8 , V_243 ) ;
if ( F_136 ( V_345 , V_326 , V_327 ) )
goto V_346;
if ( F_143 ( V_228 , V_326 , V_327 ) )
goto V_346;
F_97 ( V_326 ) ;
F_97 ( V_327 ) ;
F_134 () ;
return 0 ;
V_346:
F_97 ( V_326 ) ;
F_97 ( V_327 ) ;
return 1 ;
}
static int T_1 F_147 ( void )
{
int V_7 ;
int V_57 ;
int V_228 ;
int V_347 ;
int V_348 ;
int V_305 ;
T_10 * V_71 ;
if ( ! F_112 () )
return 0 ;
F_148 (cur_cpu) {
V_71 = & F_5 ( V_209 , V_347 ) ;
F_149 ( V_71 , V_243 , F_138 ( V_347 ) ) ;
}
V_228 = F_79 () ;
V_152 = F_35 ( V_244 ) ;
V_349 = 0x7fffffff ;
for ( V_7 = 0 ; V_7 < V_228 ; V_7 ++ ) {
V_348 = F_80 ( V_7 ) ;
if ( V_348 && ( F_81 ( V_7 ) < V_349 ) )
V_349 = F_81 ( V_7 ) ;
}
F_78 () ;
if ( F_144 ( V_228 , V_349 ) ) {
F_6 () ;
V_6 = 1 ;
return 0 ;
}
V_305 = V_350 ;
F_150 (uvhub)
if ( F_80 ( V_7 ) )
F_131 ( V_7 , V_305 , V_349 ) ;
F_151 ( V_305 , V_351 ) ;
F_150 (uvhub) {
if ( F_80 ( V_7 ) ) {
unsigned long V_257 ;
unsigned long V_24 ;
V_57 = F_81 ( V_7 ) ;
V_257 = 1L << 63 ;
F_152 ( V_57 , V_257 ) ;
V_24 = 1 ;
if ( ! F_122 () )
F_153 ( V_57 , V_24 ) ;
}
}
return 0 ;
}
