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
F_24 ( V_71 ) ;
V_70 = sizeof( struct V_67 ) * V_73 ;
for ( V_57 = 0 ; V_57 < V_70 ; V_57 ++ ) {
int V_3 ;
if ( ! F_25 ( V_57 , V_68 ) )
continue;
V_69 = V_57 + V_5 -> V_74 ;
V_3 = F_20 ( V_69 , V_42 ) ;
F_26 ( V_3 , V_71 ) ;
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
if ( ( V_93 - V_5 -> V_100 ) > V_5 -> V_121 )
return F_46 ( V_5 ) ;
}
F_42 () ;
}
V_115 = F_43 ( V_87 , V_88 , V_108 ) ;
}
V_5 -> V_102 ++ ;
return V_105 ;
}
static int F_48 ( struct V_91 * V_91 , struct V_4 * V_5 , long V_92 )
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
return F_40 ( V_91 , V_87 , V_88 , V_5 , V_92 ) ;
else
return F_47 ( V_91 , V_87 , V_88 , V_5 , V_92 ) ;
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
struct V_202 * V_203 ,
unsigned long V_204 ,
unsigned long V_205 ,
unsigned int V_3 )
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
if ( F_72 ( V_3 , V_72 ) )
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
} else if ( F_85 () ) {
V_217 &= ~ ( 1L << V_233 ) ;
V_217 |= ( 1L << V_234 ) ;
}
F_83 ( V_57 , V_217 ) ;
}
}
static void * F_86 ( struct V_235 * V_236 , T_6 * V_106 )
{
if ( * V_106 < F_87 () )
return V_106 ;
return NULL ;
}
static void * F_88 ( struct V_235 * V_236 , void * V_77 , T_6 * V_106 )
{
( * V_106 ) ++ ;
if ( * V_106 < F_87 () )
return V_106 ;
return NULL ;
}
static void F_89 ( struct V_235 * V_236 , void * V_77 )
{
}
static int F_90 ( struct V_235 * V_236 , void * V_77 )
{
struct V_26 * V_27 ;
struct V_4 * V_5 ;
int V_3 ;
V_3 = * ( T_6 * ) V_77 ;
if ( ! V_3 ) {
F_91 ( V_236 ,
L_4 ) ;
F_91 ( V_236 , L_5 ) ;
F_91 ( V_236 ,
L_6 ) ;
F_91 ( V_236 ,
L_7 ) ;
F_91 ( V_236 ,
L_8 ) ;
F_91 ( V_236 ,
L_9 ) ;
F_91 ( V_236 , L_10 ) ;
}
if ( V_3 < F_87 () && F_92 ( V_3 ) ) {
V_5 = & F_5 ( V_4 , V_3 ) ;
if ( V_5 -> V_2 ) {
F_93 ( V_236 , L_11 , V_3 ) ;
return 0 ;
}
V_27 = V_5 -> V_28 ;
F_93 ( V_236 ,
L_12 ,
V_3 , V_5 -> V_2 , V_27 -> V_155 ,
F_33 ( V_27 -> V_149 ) ,
V_27 -> V_210 , V_27 -> V_190 ,
V_27 -> V_189 , V_27 -> V_188 ,
V_27 -> V_191 , V_27 -> V_192 ,
V_27 -> V_193 , V_27 -> V_194 ) ;
F_93 ( V_236 , L_13 ,
V_27 -> V_195 , V_27 -> V_196 ,
V_27 -> V_197 , V_27 -> V_198 ,
V_27 -> V_99 , V_27 -> V_237 ) ;
F_93 ( V_236 , L_14 ,
V_27 -> V_179 , V_27 -> V_156 ,
V_27 -> V_130 , V_27 -> V_134 ,
V_27 -> V_157 , V_27 -> V_96 ,
V_27 -> V_238 , V_27 -> V_166 ) ;
F_93 ( V_236 , L_15 ,
V_27 -> V_140 , V_27 -> V_184 ,
V_27 -> V_113 , V_27 -> V_239 ,
V_27 -> V_240 , V_27 -> V_207 ,
V_27 -> V_208 , V_27 -> V_120 ,
V_27 -> V_183 , V_27 -> V_161 ,
V_27 -> V_154 ) ;
F_93 ( V_236 ,
L_16 ,
F_94 ( F_95 ( V_3 ) ) ,
V_27 -> V_48 , F_33 ( V_27 -> V_225 ) ,
V_27 -> V_46 , V_27 -> V_47 , V_27 -> V_227 ,
V_27 -> V_226 , V_27 -> V_29 , V_27 -> V_37 ,
V_27 -> V_38 , V_27 -> V_64 ,
V_27 -> V_66 ) ;
}
return 0 ;
}
static T_7 F_96 ( struct V_236 * V_236 , char T_8 * V_241 ,
T_9 V_221 , T_6 * V_242 )
{
char * V_243 ;
int V_244 ;
V_243 = F_97 ( V_245 , L_17 ,
L_18 ,
L_19 ,
L_20 ,
V_131 , V_125 , V_127 ,
V_133 , V_182 , V_143 ,
V_246 , V_247 , V_142 ,
V_160 ) ;
if ( ! V_243 )
return - V_248 ;
V_244 = F_98 ( V_241 , V_221 , V_242 , V_243 , strlen ( V_243 ) ) ;
F_99 ( V_243 ) ;
return V_244 ;
}
static T_7 F_100 ( struct V_236 * V_236 , const char T_8 * V_249 ,
T_9 V_221 , T_6 * V_77 )
{
int V_3 ;
int V_21 ;
int V_250 ;
long V_251 ;
char V_252 [ 64 ] ;
struct V_26 * V_27 ;
if ( V_221 == 0 || V_221 > sizeof( V_252 ) )
return - V_253 ;
if ( F_101 ( V_252 , V_249 , V_221 ) )
return - V_254 ;
V_252 [ V_221 - 1 ] = '\0' ;
if ( ! strcmp ( V_252 , L_21 ) ) {
F_2 () ;
return V_221 ;
} else if ( ! strcmp ( V_252 , L_22 ) ) {
F_6 () ;
return V_221 ;
}
if ( F_102 ( V_252 , 10 , & V_251 ) < 0 ) {
F_103 ( V_255 L_23 , V_252 ) ;
return - V_253 ;
}
if ( V_251 == 0 ) {
V_250 = F_104 ( V_256 ) ;
F_103 ( V_255 L_24 ) ;
F_103 ( V_255 L_25 ) ;
for ( V_21 = 0 ; V_21 < V_250 ; V_21 ++ )
F_103 ( V_255 L_26 , V_256 [ V_21 ] ) ;
} else if ( V_251 == - 1 ) {
F_4 (cpu) {
V_27 = & F_5 ( V_257 , V_3 ) ;
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
}
}
return V_221 ;
}
static int F_105 ( const char * V_258 )
{
int V_259 = 0 ;
for (; ; V_258 ++ ) {
switch ( * V_258 ) {
case '0' ... '9' :
V_259 = 10 * V_259 + ( * V_258 - '0' ) ;
break;
default:
return V_259 ;
}
}
}
static int F_106 ( struct V_4 * V_5 , char * V_260 ,
int V_221 )
{
char * V_261 ;
char * V_262 ;
int V_201 = 0 ;
int V_259 ;
int V_263 = F_104 ( V_264 ) ;
V_261 = V_260 + strspn ( V_260 , V_265 ) ;
V_262 = V_261 ;
for (; * V_261 ; V_261 = V_262 + strspn ( V_262 , V_265 ) ) {
V_262 = V_261 + strcspn ( V_261 , V_265 ) ;
V_201 ++ ;
if ( V_262 == V_261 )
break;
}
if ( V_201 != V_263 ) {
F_103 ( V_266 L_27 , V_263 ) ;
return - V_253 ;
}
V_261 = V_260 + strspn ( V_260 , V_265 ) ;
V_262 = V_261 ;
for ( V_201 = 0 ; * V_261 ; V_261 = V_262 + strspn ( V_262 , V_265 ) , V_201 ++ ) {
V_262 = V_261 + strcspn ( V_261 , V_265 ) ;
V_259 = F_105 ( V_261 ) ;
switch ( V_201 ) {
case 0 :
if ( V_259 == 0 ) {
V_131 = V_267 ;
V_144 = V_267 ;
continue;
}
if ( V_259 < 1 || V_259 > V_5 -> V_56 ) {
F_103 ( V_255
L_28 ,
V_259 ) ;
return - V_253 ;
}
V_131 = V_259 ;
V_144 = V_259 ;
continue;
default:
if ( V_259 == 0 )
* V_264 [ V_201 ] . V_268 = V_264 [ V_201 ] . V_269 ;
else
* V_264 [ V_201 ] . V_268 = V_259 ;
continue;
}
if ( V_262 == V_261 )
break;
}
return 0 ;
}
static T_7 F_107 ( struct V_236 * V_236 , const char T_8 * V_249 ,
T_9 V_221 , T_6 * V_77 )
{
int V_3 ;
int V_244 ;
char V_260 [ 100 ] ;
struct V_4 * V_5 ;
if ( V_221 == 0 || V_221 > sizeof( V_260 ) - 1 )
return - V_253 ;
if ( F_101 ( V_260 , V_249 , V_221 ) )
return - V_254 ;
V_260 [ V_221 ] = '\0' ;
V_3 = F_108 () ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_244 = F_106 ( V_5 , V_260 , V_221 ) ;
F_109 () ;
if ( V_244 )
return V_244 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_131 = V_131 ;
V_5 -> V_144 = V_131 ;
V_5 -> V_125 = V_125 ;
V_5 -> V_127 = V_127 ;
V_5 -> V_133 = V_133 ;
V_5 -> V_182 = V_182 ;
V_5 -> V_143 = V_143 ;
V_5 -> V_270 = V_246 ;
V_5 -> V_153 = V_247 ;
V_5 -> V_142 = F_34 ( V_142 ) ;
V_5 -> V_160 = V_160 ;
}
return V_221 ;
}
static int F_110 ( struct V_271 * V_271 , struct V_236 * V_236 )
{
return F_111 ( V_236 , & V_272 ) ;
}
static int F_112 ( struct V_271 * V_271 , struct V_236 * V_236 )
{
return 0 ;
}
static int T_1 F_113 ( void )
{
struct V_273 * V_274 ;
if ( ! F_114 () )
return 0 ;
V_274 = F_115 ( V_275 , 0444 , NULL ,
& V_276 ) ;
if ( ! V_274 ) {
F_103 ( V_277 L_29 ,
V_275 ) ;
return - V_253 ;
}
V_278 = F_116 ( V_279 , NULL ) ;
if ( ! V_278 ) {
F_103 ( V_277 L_30 ,
V_279 ) ;
return - V_253 ;
}
V_280 = F_117 ( V_281 , 0600 ,
V_278 , NULL , & V_282 ) ;
if ( ! V_280 ) {
F_103 ( V_277 L_31 ,
V_281 ) ;
return - V_253 ;
}
return 0 ;
}
static void F_118 ( int V_8 , int V_57 , int V_283 )
{
int V_21 ;
int V_3 ;
int V_170 = 0 ;
unsigned long V_284 ;
unsigned long V_285 ;
unsigned long V_286 ;
T_9 V_287 ;
struct V_91 * V_91 ;
struct V_91 * V_288 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_4 * V_5 ;
V_287 = sizeof( struct V_91 ) * V_289 * V_212 ;
V_91 = F_119 ( V_287 , V_245 , V_8 ) ;
F_120 ( ! V_91 ) ;
V_284 = F_121 ( V_91 ) ;
V_286 = F_122 ( V_284 ) ;
V_285 = F_123 ( V_284 ) ;
if ( F_124 () )
V_170 = 1 ;
F_125 ( V_57 , ( V_286 << V_290 | V_285 ) ) ;
for ( V_21 = 0 , V_288 = V_91 ; V_21 < ( V_289 * V_212 ) ; V_21 ++ , V_288 ++ ) {
memset ( V_288 , 0 , sizeof( struct V_91 ) ) ;
if ( V_170 ) {
V_173 = & V_288 -> V_176 . V_173 ;
V_173 -> V_291 = 1 ;
V_173 -> V_292 =
F_126 ( V_283 ) ;
V_173 -> V_293 = V_294 ;
V_173 -> V_295 = V_296 ;
V_173 -> V_297 = 1 ;
} else {
V_175 = & V_288 -> V_176 . V_175 ;
V_175 -> V_291 = 1 ;
V_175 -> V_292 =
F_126 ( V_283 ) ;
V_175 -> V_293 = V_294 ;
V_175 -> V_295 = V_296 ;
}
}
F_4 (cpu) {
if ( V_57 != F_81 ( F_11 ( V_3 ) ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_211 = V_91 ;
}
}
static void F_127 ( int V_8 , int V_57 )
{
int V_3 ;
T_9 V_298 ;
char * V_299 ;
void * V_300 ;
unsigned long V_301 ;
unsigned long V_302 ;
unsigned long V_303 ;
unsigned long V_304 ;
struct V_15 * V_305 ;
struct V_4 * V_5 ;
V_298 = ( V_30 + 1 ) * sizeof( struct V_15 ) ;
V_300 = F_119 ( V_298 , V_245 , V_8 ) ;
V_305 = (struct V_15 * ) V_300 ;
F_120 ( ! V_305 ) ;
V_299 = ( char * ) V_305 + 31 ;
V_305 = (struct V_15 * ) ( ( ( unsigned long ) V_299 >> 5 ) << 5 ) ;
F_4 (cpu) {
if ( V_57 != F_95 ( V_3 ) )
continue;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_32 = V_305 ;
V_5 -> V_224 = V_305 ;
V_5 -> V_31 = V_305 + ( V_30 - 1 ) ;
}
V_301 = F_122 ( F_121 ( V_305 ) ) ;
V_302 = F_128 ( V_305 ) ;
V_303 = ( ( unsigned long ) V_301 << V_306 ) | V_302 ;
V_304 = F_128 ( V_305 + ( V_30 - 1 ) ) ;
F_129 ( V_57 , V_303 ) ;
F_130 ( V_57 , V_302 ) ;
F_131 ( V_57 , V_304 ) ;
F_132 ( V_57 , 0xffffUL ) ;
memset ( V_305 , 0 , sizeof( struct V_15 ) * V_30 ) ;
}
static void T_1 F_133 ( int V_7 , int V_307 , int V_283 )
{
int V_8 ;
int V_57 ;
unsigned long V_308 ;
V_8 = F_7 ( V_7 ) ;
V_57 = F_81 ( V_7 ) ;
F_118 ( V_8 , V_57 , V_283 ) ;
F_127 ( V_8 , V_57 ) ;
V_308 = F_10 ( V_7 ) | V_309 ;
F_134 ( V_57 , ( ( V_308 << 32 ) | V_307 ) ) ;
}
static int F_135 ( void )
{
unsigned long V_217 ;
int V_310 ;
int V_311 ;
int V_171 ;
int V_312 ;
int V_244 ;
unsigned long V_313 ;
if ( F_124 () ) {
V_310 = V_231 & V_314 ;
V_217 = F_39 ( V_315 ) ;
V_171 = ( V_217 >> V_316 ) & V_317 ;
V_217 = F_39 ( V_318 ) ;
V_311 = ( V_217 >> V_319 ) & V_320 ;
V_313 = V_321 [ V_171 ] ;
V_313 *= ( V_310 * V_311 ) ;
V_244 = V_313 / 1000 ;
} else {
V_217 = F_39 ( V_322 ) ;
V_217 = ( V_217 & V_323 ) >> V_324 ;
if ( V_217 & ( 1L << V_325 ) )
V_312 = 80 ;
else
V_312 = 10 ;
V_310 = V_217 & V_326 ;
V_244 = V_310 * V_312 ;
}
return V_244 ;
}
static void T_1 F_136 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_139 = 0 ;
if ( V_2 )
V_5 -> V_2 = 1 ;
V_5 -> V_28 = & F_5 ( V_257 , V_3 ) ;
V_5 -> V_121 = F_35 ( 2 * V_101 ) ;
V_5 -> V_131 = V_131 ;
V_5 -> V_144 = V_131 ;
V_5 -> V_125 = V_125 ;
V_5 -> V_127 = V_127 ;
V_5 -> V_133 = V_133 ;
V_5 -> V_182 = V_182 ;
V_5 -> V_143 = V_143 ;
V_5 -> V_270 = V_246 ;
V_5 -> V_153 = V_247 ;
V_5 -> V_142 = F_34 ( V_142 ) ;
V_5 -> V_160 = V_160 ;
F_137 ( & V_5 -> V_128 ) ;
F_137 ( & V_5 -> V_163 ) ;
F_137 ( & V_5 -> V_138 ) ;
}
}
static int T_1 F_138 ( int V_283 ,
struct V_327 * V_328 ,
unsigned char * V_329 )
{
int V_3 ;
int V_57 ;
int V_7 ;
int V_330 ;
struct V_4 * V_5 ;
struct V_327 * V_331 ;
struct V_332 * V_333 ;
F_4 (cpu) {
V_5 = & F_5 ( V_4 , V_3 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_57 = F_139 ( V_3 ) -> V_57 ;
if ( ( V_57 - V_283 ) >= V_213 ) {
F_103 ( V_334
L_32 ,
V_3 , V_57 , V_283 , V_213 ) ;
return 1 ;
}
V_5 -> V_335 = F_140 ( V_3 ) ;
V_5 -> V_74 = V_283 ;
V_7 = F_139 ( V_3 ) -> V_336 ;
* ( V_329 + ( V_7 / 8 ) ) |= ( 1 << ( V_7 % 8 ) ) ;
V_331 = & V_328 [ V_7 ] ;
V_331 -> V_337 ++ ;
V_331 -> V_7 = V_7 ;
V_331 -> V_57 = V_57 ;
V_330 = V_5 -> V_335 & 1 ;
V_331 -> V_338 |= ( 1 << V_330 ) ;
V_333 = & V_331 -> V_330 [ V_330 ] ;
V_333 -> V_339 [ V_333 -> V_337 ] = V_3 ;
V_333 -> V_337 ++ ;
if ( V_333 -> V_337 > V_340 ) {
F_103 ( V_334 L_33 ,
V_333 -> V_337 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_141 ( struct V_4 * V_42 )
{
int V_3 ;
T_9 V_341 = sizeof( struct V_58 ) * F_87 () ;
V_42 -> V_60 = F_119 ( V_341 , V_245 , V_42 -> V_335 ) ;
memset ( V_42 -> V_60 , 0 , V_341 ) ;
F_4 (cpu) {
V_42 -> V_60 [ V_3 ] . V_57 = F_139 ( V_3 ) -> V_57 ;
V_42 -> V_60 [ V_3 ] . V_7 = F_139 ( V_3 ) -> V_336 ;
}
}
static void F_142 ( struct V_4 * V_85 )
{
int V_342 = sizeof( T_2 ) ;
V_85 -> V_72 = F_143 ( V_342 , V_245 , V_85 -> V_335 ) ;
}
static int F_144 ( struct V_332 * V_333 , struct V_327 * V_331 ,
struct V_4 * * V_343 ,
struct V_4 * * V_344 )
{
int V_21 ;
int V_3 ;
struct V_4 * V_5 ;
for ( V_21 = 0 ; V_21 < V_333 -> V_337 ; V_21 ++ ) {
V_3 = V_333 -> V_339 [ V_21 ] ;
V_5 = & F_5 ( V_4 , V_3 ) ;
V_5 -> V_3 = V_3 ;
if ( V_21 == 0 ) {
* V_343 = V_5 ;
if ( ! ( * V_344 ) )
* V_344 = V_5 ;
}
V_5 -> V_56 = V_331 -> V_337 ;
V_5 -> V_53 = V_333 -> V_337 ;
V_5 -> V_43 = * V_343 ;
V_5 -> V_7 = V_331 -> V_7 ;
if ( F_124 () )
V_5 -> V_124 = 1 ;
else if ( F_84 () )
V_5 -> V_124 = 2 ;
else if ( F_85 () )
V_5 -> V_124 = 3 ;
else {
F_103 ( V_334 L_34 ) ;
return 1 ;
}
V_5 -> V_50 = * V_344 ;
V_5 -> V_109 = F_139 ( V_3 ) -> V_345 ;
if ( V_5 -> V_109 >= V_346 ) {
F_103 ( V_334 L_35 ,
V_5 -> V_109 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_145 ( int V_228 ,
struct V_327 * V_328 ,
unsigned char * V_329 )
{
int V_330 ;
int V_7 ;
unsigned short V_338 ;
for ( V_7 = 0 ; V_7 < V_228 ; V_7 ++ ) {
struct V_327 * V_331 ;
struct V_4 * V_42 = NULL ;
struct V_4 * V_85 = NULL ;
if ( ! ( * ( V_329 + ( V_7 / 8 ) ) & ( 1 << ( V_7 % 8 ) ) ) )
continue;
V_331 = & V_328 [ V_7 ] ;
V_338 = V_331 -> V_338 ;
V_330 = 0 ;
while ( V_338 ) {
struct V_332 * V_333 ;
if ( ( V_338 & 1 ) ) {
V_333 = & V_331 -> V_330 [ V_330 ] ;
if ( F_144 ( V_333 , V_331 , & V_42 , & V_85 ) )
return 1 ;
F_141 ( V_42 ) ;
}
V_330 ++ ;
V_338 = ( V_338 >> 1 ) ;
}
F_142 ( V_85 ) ;
}
return 0 ;
}
static int T_1 F_146 ( int V_228 , int V_347 )
{
unsigned char * V_329 ;
void * V_300 ;
struct V_327 * V_328 ;
V_101 = F_135 () ;
V_300 = F_147 ( V_228 * sizeof( struct V_327 ) , V_245 ) ;
V_328 = (struct V_327 * ) V_300 ;
memset ( V_328 , 0 , V_228 * sizeof( struct V_327 ) ) ;
V_329 = F_148 ( ( V_228 + 7 ) / 8 , V_245 ) ;
if ( F_138 ( V_347 , V_328 , V_329 ) )
goto V_348;
if ( F_145 ( V_228 , V_328 , V_329 ) )
goto V_348;
F_99 ( V_328 ) ;
F_99 ( V_329 ) ;
F_136 () ;
return 0 ;
V_348:
F_99 ( V_328 ) ;
F_99 ( V_329 ) ;
return 1 ;
}
static int T_1 F_149 ( void )
{
int V_7 ;
int V_57 ;
int V_228 ;
int V_349 ;
int V_350 ;
int V_307 ;
T_10 * V_71 ;
if ( ! F_114 () )
return 0 ;
F_150 (cur_cpu) {
V_71 = & F_5 ( V_209 , V_349 ) ;
F_151 ( V_71 , V_245 , F_140 ( V_349 ) ) ;
}
V_228 = F_79 () ;
V_152 = F_35 ( V_246 ) ;
V_351 = 0x7fffffff ;
for ( V_7 = 0 ; V_7 < V_228 ; V_7 ++ ) {
V_350 = F_80 ( V_7 ) ;
if ( V_350 && ( F_81 ( V_7 ) < V_351 ) )
V_351 = F_81 ( V_7 ) ;
}
F_78 () ;
if ( F_146 ( V_228 , V_351 ) ) {
F_6 () ;
V_6 = 1 ;
return 0 ;
}
V_307 = V_352 ;
F_152 (uvhub) {
if ( F_80 ( V_7 ) )
F_133 ( V_7 , V_307 , V_351 ) ;
}
F_153 ( V_307 , V_353 ) ;
F_152 (uvhub) {
if ( F_80 ( V_7 ) ) {
unsigned long V_259 ;
unsigned long V_24 ;
V_57 = F_81 ( V_7 ) ;
V_259 = 1L << 63 ;
F_154 ( V_57 , V_259 ) ;
V_24 = 1 ;
if ( ! F_124 () )
F_155 ( V_57 , V_24 ) ;
}
}
return 0 ;
}
