static int T_1
F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static int T_1 F_2 ( int V_3 )
{
int V_4 , V_5 ;
F_3 (node) {
V_5 = F_4 ( V_4 ) ;
if ( V_3 == V_5 )
return V_4 ;
}
return - 1 ;
}
static int T_1 F_5 ( int V_3 )
{
int V_6 ;
F_6 (cpu)
if ( V_3 == F_7 ( V_6 ) )
return F_8 ( V_7 , V_6 ) ;
return - 1 ;
}
static void F_9 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
unsigned long V_12 ;
struct V_13 * V_14 ;
V_14 = V_9 -> V_14 ;
if ( ! V_14 -> V_15 ) {
V_12 = ( V_14 -> V_16 << V_17 ) | V_14 -> V_16 ;
F_10 ( V_12 ) ;
}
V_14 -> V_18 = 1 ;
V_14 -> V_16 = 0 ;
}
static void F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
int V_19 ;
int V_20 = 0 ;
unsigned long V_21 ;
unsigned long V_22 = 0 ;
struct V_13 * V_14 = V_9 -> V_14 ;
struct V_13 * V_23 ;
struct V_24 * V_25 = V_11 -> V_26 ;
V_25 -> V_27 ++ ;
for ( V_23 = V_14 + 1 , V_19 = 0 ; V_19 < V_28 ; V_23 ++ , V_19 ++ ) {
if ( V_23 > V_9 -> V_29 )
V_23 = V_9 -> V_30 ;
if ( V_23 == V_14 )
break;
if ( ( V_23 -> V_18 == 0 ) && ( V_23 -> V_15 == 0 ) &&
( V_23 -> V_16 ) && ( ( V_23 -> V_16 &
V_14 -> V_16 ) == 0 ) &&
( V_23 -> V_31 == V_14 -> V_31 ) &&
( V_23 -> V_32 != V_33 ) ) {
V_22 = F_12 () ;
V_21 = V_23 -> V_16 ;
if ( V_22 & ( V_21 << V_17 ) ) {
unsigned long V_34 ;
V_23 -> V_15 = 1 ;
V_25 -> V_35 ++ ;
V_20 ++ ;
V_34 = ( V_21 << V_17 ) | V_21 ;
F_10 ( V_34 ) ;
}
}
}
if ( ! V_20 )
V_25 -> V_36 ++ ;
}
static void F_13 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
short V_37 = 0 ;
short * V_38 ;
struct atomic_short * V_39 ;
struct V_24 * V_25 = V_11 -> V_26 ;
struct V_13 * V_14 = V_9 -> V_14 ;
struct V_10 * V_40 = V_11 -> V_41 ;
if ( V_14 -> V_42 == V_43 ) {
F_14 () ;
V_25 -> V_44 ++ ;
} else {
F_15 ( V_14 -> V_42 ) ;
V_25 -> V_45 ++ ;
}
V_25 -> V_46 ++ ;
if ( V_14 -> V_32 == V_47 && V_11 == V_11 -> V_48 )
F_11 ( V_9 , V_11 ) ;
V_38 = & V_40 -> V_49 [ V_9 -> V_50 ] ;
V_39 = (struct atomic_short * ) V_38 ;
V_37 = F_16 ( 1 , V_39 ) ;
if ( V_37 == V_11 -> V_51 ) {
int V_52 ;
V_40 -> V_49 [ V_9 -> V_50 ] = 0 ;
V_39 = (struct atomic_short * ) & V_14 -> V_53 ;
V_52 = F_16 ( V_37 , V_39 ) ;
if ( V_52 == V_11 -> V_54 ) {
F_9 ( V_9 , V_11 ) ;
}
}
return;
}
static int F_17 ( int V_3 )
{
int V_6 ;
F_6 (cpu)
if ( V_3 == F_7 ( V_6 ) )
return V_6 ;
return - 1 ;
}
static void F_18 ( void * V_55 )
{
int V_19 ;
struct V_10 * V_11 = & F_8 ( V_10 , F_19 () ) ;
struct V_56 * V_57 = (struct V_56 * ) V_55 ;
struct V_13 * V_14 ;
struct V_24 * V_25 = V_11 -> V_26 ;
V_25 -> V_58 ++ ;
for ( V_14 = V_11 -> V_30 , V_19 = 0 ; V_19 < V_28 ; V_14 ++ , V_19 ++ ) {
unsigned long V_21 ;
if ( ( V_14 -> V_18 == 0 ) &&
( V_14 -> V_15 == 0 ) &&
( V_14 -> V_31 == V_57 -> V_59 ) &&
( V_14 -> V_16 ) &&
( V_14 -> V_32 != V_33 ) ) {
unsigned long V_22 ;
unsigned long V_34 ;
V_14 -> V_15 = 1 ;
V_22 = F_12 () ;
V_21 = V_14 -> V_16 ;
V_34 = ( V_21 << V_17 ) | V_21 ;
if ( V_22 & V_21 ) {
V_25 -> V_60 ++ ;
F_10 ( V_34 ) ;
}
}
}
return;
}
static void F_20 ( struct V_61 * V_62 , int V_59 )
{
int V_3 ;
int V_63 ;
T_2 V_64 ;
struct V_56 V_56 ;
V_56 . V_59 = V_59 ;
F_21 ( V_64 ) ;
V_63 = sizeof( struct V_61 ) * V_65 ;
for ( V_3 = 0 ; V_3 < V_63 ; V_3 ++ ) {
int V_6 ;
if ( ! F_22 ( V_3 , V_62 ) )
continue;
V_6 = F_17 ( V_3 ) ;
F_23 ( V_6 , V_64 ) ;
}
F_24 ( & V_64 , F_18 , ( void * ) & V_56 , 1 ) ;
return;
}
static inline unsigned long F_25 ( unsigned long long V_66 )
{
unsigned long long V_67 ;
unsigned long V_68 ;
int V_6 = F_19 () ;
V_67 = ( V_66 * F_8 ( V_69 , V_6 ) ) >> V_70 ;
V_68 = V_67 / 1000 ;
return V_68 ;
}
static inline void F_26 ( struct V_10 * V_71 )
{
F_16 ( 1 , (struct atomic_short * ) & V_71 -> V_72 ) ;
}
static inline void F_27 ( struct V_10 * V_71 )
{
F_16 ( - 1 , (struct atomic_short * ) & V_71 -> V_72 ) ;
}
static unsigned long F_28 ( unsigned long V_73 , int V_74 )
{
unsigned long V_75 ;
V_75 = F_29 ( V_73 ) ;
V_75 >>= V_74 ;
V_75 &= V_76 ;
return V_75 ;
}
static int F_30 ( struct V_77 * V_77 ,
unsigned long V_73 , int V_74 ,
struct V_10 * V_11 , long V_78 )
{
unsigned long V_75 ;
T_3 V_79 ;
struct V_24 * V_25 = V_11 -> V_26 ;
V_75 = F_28 ( V_73 , V_74 ) ;
while ( ( V_75 != V_80 ) ) {
if ( V_75 == V_81 ) {
V_25 -> V_82 ++ ;
return V_83 ;
} else if ( V_75 == V_84 ) {
V_25 -> V_85 ++ ;
V_79 = F_31 () ;
if ( F_25 ( V_79 - V_11 -> V_86 ) < V_87 ) {
V_11 -> V_88 = 0 ;
return V_89 ;
}
V_11 -> V_88 = 0 ;
return V_90 ;
} else {
F_32 () ;
}
V_75 = F_28 ( V_73 , V_74 ) ;
}
V_11 -> V_88 ++ ;
return V_91 ;
}
static unsigned long F_33 ( unsigned long V_92 , int V_93 , int V_6 )
{
unsigned long V_75 ;
unsigned long V_94 ;
V_75 = ( ( F_34 ( V_92 ) >> V_93 ) & V_76 ) ;
V_94 = ( F_35 () >> V_6 ) & 0x1UL ;
V_75 = ( V_75 << 1 ) | V_94 ;
return V_75 ;
}
static int F_36 ( struct V_77 * V_77 ,
unsigned long V_73 , int V_74 ,
struct V_10 * V_11 , long V_78 )
{
unsigned long V_95 ;
T_3 V_79 ;
int V_6 = V_11 -> V_96 ;
struct V_24 * V_25 = V_11 -> V_26 ;
V_95 = F_33 ( V_73 , V_74 , V_6 ) ;
while ( V_95 != V_97 ) {
if ( ( V_95 == V_98 ) ||
( V_95 == V_99 ) ||
( V_95 == V_100 ) ) {
V_25 -> V_82 ++ ;
return V_83 ;
} else if ( V_95 == V_101 ) {
V_25 -> V_85 ++ ;
V_79 = F_31 () ;
if ( F_25 ( V_79 - V_11 -> V_86 ) < V_87 ) {
V_11 -> V_88 = 0 ;
return V_89 ;
}
V_11 -> V_88 = 0 ;
return V_90 ;
} else {
F_32 () ;
}
V_95 = F_33 ( V_73 , V_74 , V_6 ) ;
}
V_11 -> V_88 ++ ;
return V_91 ;
}
static int F_37 ( struct V_77 * V_77 ,
struct V_10 * V_11 , long V_78 )
{
int V_74 ;
unsigned long V_73 ;
int V_6 = V_11 -> V_96 ;
if ( V_6 < V_102 ) {
V_73 = V_103 ;
V_74 = V_6 * V_104 ;
} else {
V_73 = V_105 ;
V_74 = ( ( V_6 - V_102 ) * V_104 ) ;
}
if ( F_38 () )
return F_30 ( V_77 , V_73 , V_74 ,
V_11 , V_78 ) ;
else
return F_36 ( V_77 , V_73 , V_74 ,
V_11 , V_78 ) ;
}
static inline T_3 F_39 ( unsigned long V_106 )
{
unsigned long V_67 ;
T_3 V_66 ;
V_67 = V_106 * 1000000000 ;
V_66 = ( V_67 << V_70 ) / ( F_8 ( V_69 , F_19 () ) ) ;
return V_66 ;
}
static void F_40 ( struct V_77 * V_77 ,
struct V_10 * V_11 ,
struct V_10 * V_71 , struct V_24 * V_25 )
{
F_41 ( V_11 -> V_107 ) ;
V_11 -> V_108 ++ ;
if ( V_11 -> V_108 >= V_11 -> V_109 ) {
V_11 -> V_108 = 0 ;
F_26 ( V_71 ) ;
F_42 ( & V_71 -> V_110 ) ;
F_20 ( & V_77 -> V_62 , V_11 -> V_6 ) ;
F_43 ( & V_71 -> V_110 ) ;
F_27 ( V_71 ) ;
V_11 -> V_111 ++ ;
V_25 -> V_112 ++ ;
}
}
static void F_44 ( struct V_77 * V_77 ,
struct V_10 * V_11 , struct V_10 * V_71 ,
struct V_24 * V_25 )
{
V_71 -> V_113 = 1 ;
V_11 -> V_114 ++ ;
if ( V_11 -> V_114 >= V_11 -> V_115 ) {
V_11 -> V_114 = 0 ;
F_26 ( V_71 ) ;
F_42 ( & V_71 -> V_110 ) ;
F_20 ( & V_77 -> V_62 , V_11 -> V_6 ) ;
F_43 ( & V_71 -> V_110 ) ;
F_27 ( V_71 ) ;
V_11 -> V_111 ++ ;
V_25 -> V_116 ++ ;
}
}
static void F_45 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
F_42 ( & V_117 ) ;
if ( ! V_118 && V_11 -> V_119 &&
( ( V_11 -> V_120 / V_11 -> V_119 ) > V_121 ) ) {
int V_122 ;
struct V_10 * V_123 ;
V_118 = 1 ;
V_11 -> V_124 = 1 ;
V_11 -> V_125 = F_31 () ;
V_11 -> V_125 += F_39 ( V_11 -> V_126 ) ;
V_25 -> V_127 ++ ;
F_6 (tcpu) {
V_123 = & F_8 ( V_10 , V_122 ) ;
V_123 -> V_118 = 1 ;
}
}
F_43 ( & V_117 ) ;
}
static void F_46 ( int V_25 , struct V_10 * V_11 ,
struct V_10 * V_71 )
{
V_11 -> V_108 = 0 ;
V_11 -> V_114 = 0 ;
if ( V_25 != V_91 )
return;
if ( V_11 -> V_88 <= V_11 -> V_128 )
return;
if ( V_71 -> V_113 >= V_71 -> V_129 )
return;
V_71 -> V_113 ++ ;
}
static void F_47 ( T_3 V_130 , T_3 V_131 ,
struct V_10 * V_11 , struct V_24 * V_25 ,
int V_132 , int V_78 )
{
T_3 V_133 ;
if ( V_131 > V_130 ) {
V_133 = V_131 - V_130 ;
V_25 -> V_134 += V_133 ;
if ( ( V_132 == V_91 ) && ( V_78 == 1 ) ) {
V_11 -> V_119 ++ ;
V_11 -> V_120 += V_133 ;
if ( ( V_133 > V_121 ) &&
( V_11 -> V_119 > V_11 -> V_135 ) )
F_45 ( V_11 , V_25 ) ;
}
} else
V_25 -> V_136 -- ;
if ( V_132 == V_91 && V_78 > 1 )
V_25 -> V_137 ++ ;
else if ( V_132 == V_83 )
V_25 -> V_138 ++ ;
}
static void F_48 ( struct V_10 * V_71 , struct V_24 * V_25 )
{
T_4 * V_139 = & V_71 -> V_140 ;
T_5 * V_141 ;
V_141 = & V_71 -> V_142 ;
if ( ! F_49 ( V_139 , V_141 , V_71 -> V_113 ) ) {
V_25 -> V_143 ++ ;
do {
F_32 () ;
} while ( ! F_49 ( V_139 , V_141 , V_71 -> V_113 ) );
}
}
static void F_50 ( int V_132 , struct V_77 * V_77 ,
struct V_10 * V_11 , struct V_10 * V_71 ,
struct V_24 * V_25 )
{
if ( V_132 == V_89 )
F_40 ( V_77 , V_11 , V_71 , V_25 ) ;
else if ( V_132 == V_90 )
F_44 ( V_77 , V_11 , V_71 , V_25 ) ;
}
int F_51 ( struct V_77 * V_77 ,
struct V_144 * V_145 , struct V_10 * V_11 )
{
int V_146 = 0 ;
int V_147 = 0 ;
long V_78 = 0 ;
unsigned long V_148 ;
T_3 V_130 ;
T_3 V_131 ;
struct V_24 * V_25 = V_11 -> V_26 ;
struct V_10 * V_71 = V_11 -> V_48 ;
if ( F_38 () )
F_48 ( V_71 , V_25 ) ;
while ( V_71 -> V_72 )
F_32 () ;
V_130 = F_31 () ;
do {
if ( V_78 == 0 ) {
V_77 -> V_149 . V_32 = V_150 ;
V_146 = V_11 -> V_151 ++ ;
} else {
V_77 -> V_149 . V_32 = V_47 ;
V_25 -> V_152 ++ ;
}
V_77 -> V_149 . V_153 = V_146 ;
V_148 = ( 1UL << V_154 ) | V_11 -> V_96 ;
V_11 -> V_86 = F_31 () ;
F_52 ( V_148 ) ;
V_78 ++ ;
V_147 = F_37 ( V_77 , V_11 , V_78 ) ;
F_50 ( V_147 , V_77 , V_11 , V_71 , V_25 ) ;
if ( V_11 -> V_111 >= V_11 -> V_155 ) {
V_11 -> V_111 = 0 ;
V_147 = V_83 ;
break;
}
F_32 () ;
} while ( ( V_147 == V_89 ) ||
( V_147 == V_90 ) );
V_131 = F_31 () ;
F_46 ( V_147 , V_11 , V_71 ) ;
while ( V_71 -> V_72 )
F_32 () ;
F_53 ( & V_71 -> V_142 ) ;
F_47 ( V_130 , V_131 , V_11 , V_25 , V_147 , V_78 ) ;
if ( V_147 == V_83 )
return 1 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , struct V_24 * V_25 )
{
int V_122 ;
struct V_10 * V_123 ;
if ( V_11 -> V_124 ) {
if ( F_31 () >= V_11 -> V_125 ) {
V_25 -> V_156 ++ ;
V_118 = 0 ;
F_6 (tcpu) {
V_123 = & F_8 ( V_10 , V_122 ) ;
V_123 -> V_118 = 0 ;
V_123 -> V_119 = 0 ;
V_123 -> V_120 = 0 ;
}
return 0 ;
}
}
return - 1 ;
}
static void F_55 ( struct V_24 * V_25 , int V_157 , int V_158 ,
int V_159 , struct V_77 * V_77 )
{
V_25 -> V_136 ++ ;
V_25 -> V_160 += V_159 + V_157 ;
V_25 -> V_161 += V_159 ;
V_25 -> V_162 += V_157 ;
V_158 = F_56 ( & V_77 -> V_62 ) ;
if ( V_157 ) {
V_25 -> V_163 ++ ;
V_25 -> V_164 += ( V_158 - 1 ) ;
} else
V_25 -> V_164 += V_158 ;
V_25 -> V_165 += V_158 ;
if ( V_158 >= 16 )
V_25 -> V_166 ++ ;
else if ( V_158 >= 8 )
V_25 -> V_167 ++ ;
else if ( V_158 >= 4 )
V_25 -> V_168 ++ ;
else if ( V_158 >= 2 )
V_25 -> V_169 ++ ;
else
V_25 -> V_170 ++ ;
}
static int F_57 ( struct V_144 * V_145 , struct V_10 * V_11 ,
struct V_77 * V_77 , int * V_171 , int * V_172 )
{
int V_6 ;
int V_173 ;
int V_174 = 0 ;
struct V_175 * V_176 ;
F_58 (cpu, flush_mask) {
V_176 = & V_11 -> V_41 -> V_177 [ V_6 ] ;
V_173 = V_176 -> V_173 - V_11 -> V_178 ;
F_59 ( V_173 , & V_77 -> V_62 ) ;
V_174 ++ ;
if ( V_176 -> V_3 == V_11 -> V_3 )
( * V_171 ) ++ ;
else
( * V_172 ) ++ ;
}
if ( ! V_174 )
return 1 ;
return 0 ;
}
const struct V_144 * F_60 ( const struct V_144 * V_144 ,
struct V_179 * V_180 , unsigned long V_181 ,
unsigned int V_6 )
{
int V_157 = 0 ;
int V_159 = 0 ;
int V_158 = 0 ;
struct V_77 * V_77 ;
struct V_144 * V_145 ;
struct V_24 * V_25 ;
struct V_10 * V_11 ;
if ( V_2 )
return V_144 ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_25 = V_11 -> V_26 ;
if ( V_11 -> V_118 ) {
if ( F_54 ( V_11 , V_25 ) )
return V_144 ;
}
V_145 = (struct V_144 * ) F_8 ( V_182 , V_6 ) ;
F_61 ( V_145 , V_144 , F_62 ( V_6 ) ) ;
if ( F_63 ( V_6 , * V_144 ) )
V_25 -> V_183 ++ ;
V_77 = V_11 -> V_184 ;
V_77 += V_185 * V_11 -> V_96 ;
F_64 ( & V_77 -> V_62 , V_186 ) ;
if ( F_57 ( V_145 , V_11 , V_77 , & V_157 , & V_159 ) )
return NULL ;
F_55 ( V_25 , V_157 , V_158 , V_159 , V_77 ) ;
V_77 -> V_187 . V_42 = V_181 ;
V_77 -> V_187 . V_31 = V_6 ;
if ( ! F_51 ( V_77 , V_145 , V_11 ) )
return NULL ;
else
return V_144 ;
}
void F_65 ( struct V_188 * V_189 )
{
int V_190 = 0 ;
T_3 V_191 ;
struct V_13 * V_14 ;
struct V_10 * V_11 ;
struct V_24 * V_25 ;
struct V_8 V_192 ;
V_191 = F_31 () ;
V_11 = & F_8 ( V_10 , F_19 () ) ;
V_25 = V_11 -> V_26 ;
V_192 . V_30 = V_11 -> V_30 ;
V_192 . V_29 = V_11 -> V_29 ;
V_14 = V_11 -> V_193 ;
while ( V_14 -> V_16 ) {
V_190 ++ ;
V_192 . V_50 = V_14 - V_192 . V_30 ;
V_192 . V_194 = F_66 ( V_14 -> V_16 ) - 1 ;
V_192 . V_14 = V_14 ;
F_13 ( & V_192 , V_11 ) ;
V_14 ++ ;
if ( V_14 > V_192 . V_29 )
V_14 = V_192 . V_30 ;
V_11 -> V_193 = V_14 ;
}
V_25 -> V_195 += ( F_31 () - V_191 ) ;
if ( ! V_190 )
V_25 -> V_196 ++ ;
else if ( V_190 > 1 )
V_25 -> V_197 ++ ;
F_67 () ;
}
static void T_1 F_68 ( void )
{
int V_3 ;
int V_198 ;
int V_173 ;
unsigned long V_199 ;
V_198 = F_69 () ;
for ( V_3 = 0 ; V_3 < V_198 ; V_3 ++ ) {
if ( ! F_70 ( V_3 ) )
continue;
V_173 = F_71 ( V_3 ) ;
V_199 = F_72 ( V_173 ) ;
V_199 &= ~ ( 1L << V_200 ) ;
F_73 ( V_173 , V_199 ) ;
V_199 &= ~ ( ( unsigned long ) 0xf << V_201 ) ;
V_199 |= ( V_202 << V_201 ) ;
F_73 ( V_173 , V_199 ) ;
V_199 |= ( 1L << V_200 ) ;
if ( F_74 () ) {
V_199 |= ( 1L << V_203 ) ;
V_199 |= ( 1L << V_204 ) ;
}
F_73 ( V_173 , V_199 ) ;
}
}
static void * F_75 ( struct V_205 * V_206 , T_6 * V_92 )
{
if ( * V_92 < F_76 () )
return V_92 ;
return NULL ;
}
static void * F_77 ( struct V_205 * V_206 , void * V_207 , T_6 * V_92 )
{
( * V_92 ) ++ ;
if ( * V_92 < F_76 () )
return V_92 ;
return NULL ;
}
static void F_78 ( struct V_205 * V_206 , void * V_207 )
{
}
static inline unsigned long long F_79 ( unsigned long V_208 )
{
unsigned long V_67 ;
unsigned long long V_66 ;
V_67 = V_208 * 1000 ;
V_66 = ( V_67 << V_70 ) / ( F_8 ( V_69 , F_19 () ) ) ;
return V_66 ;
}
static int F_80 ( struct V_205 * V_206 , void * V_207 )
{
struct V_24 * V_25 ;
int V_6 ;
V_6 = * ( T_6 * ) V_207 ;
if ( ! V_6 ) {
F_81 ( V_206 ,
L_1 ) ;
F_81 ( V_206 ,
L_2 ) ;
F_81 ( V_206 ,
L_3 ) ;
F_81 ( V_206 ,
L_4 ) ;
F_81 ( V_206 ,
L_5 ) ;
F_81 ( V_206 ,
L_6 ) ;
}
if ( V_6 < F_76 () && F_82 ( V_6 ) ) {
V_25 = & F_8 ( V_209 , V_6 ) ;
F_81 ( V_206 ,
L_7 ,
V_6 , V_25 -> V_136 , F_25 ( V_25 -> V_134 ) ,
V_25 -> V_183 , V_25 -> V_162 ,
V_25 -> V_161 , V_25 -> V_160 ,
V_25 -> V_163 , V_25 -> V_164 ,
V_25 -> V_165 , V_25 -> V_166 ) ;
F_81 ( V_206 , L_8 ,
V_25 -> V_167 , V_25 -> V_168 ,
V_25 -> V_169 , V_25 -> V_170 ,
V_25 -> V_85 ) ;
F_81 ( V_206 , L_9 ,
V_25 -> V_152 , V_25 -> V_137 ,
V_25 -> V_112 , V_25 -> V_116 ,
V_25 -> V_138 , V_25 -> V_82 ,
V_25 -> V_210 , V_25 -> V_143 ) ;
F_81 ( V_206 ,
L_10 ,
F_83 ( F_84 ( V_6 ) ) ,
V_25 -> V_46 , F_25 ( V_25 -> V_195 ) ,
V_25 -> V_44 , V_25 -> V_45 , V_25 -> V_197 ,
V_25 -> V_196 , V_25 -> V_27 , V_25 -> V_35 ,
V_25 -> V_36 , V_25 -> V_58 ,
V_25 -> V_60 ) ;
F_81 ( V_206 , L_11 ,
V_25 -> V_127 , V_25 -> V_156 ) ;
}
return 0 ;
}
static T_7 F_85 ( struct V_206 * V_206 , char T_8 * V_211 ,
T_9 V_190 , T_6 * V_212 )
{
char * V_213 ;
int V_214 ;
V_213 = F_86 ( V_215 , L_12 ,
L_13 ,
L_14 ,
L_15 ,
V_113 , V_107 , V_109 ,
V_115 , V_155 , V_128 ,
V_216 , V_217 , V_218 ) ;
if ( ! V_213 )
return - V_219 ;
V_214 = F_87 ( V_211 , V_190 , V_212 , V_213 , strlen ( V_213 ) ) ;
F_88 ( V_213 ) ;
return V_214 ;
}
static T_7 F_89 ( struct V_206 * V_206 , const char T_8 * V_220 ,
T_9 V_190 , T_6 * V_207 )
{
int V_6 ;
int V_19 ;
int V_221 ;
long V_222 ;
char V_223 [ 64 ] ;
struct V_24 * V_25 ;
if ( V_190 == 0 || V_190 > sizeof( V_223 ) )
return - V_224 ;
if ( F_90 ( V_223 , V_220 , V_190 ) )
return - V_225 ;
V_223 [ V_190 - 1 ] = '\0' ;
if ( F_91 ( V_223 , 10 , & V_222 ) < 0 ) {
F_92 ( V_226 L_16 , V_223 ) ;
return - V_224 ;
}
if ( V_222 == 0 ) {
V_221 = sizeof( V_227 ) / sizeof( * V_227 ) ;
F_92 ( V_226 L_17 ) ;
F_92 ( V_226 L_18 ) ;
for ( V_19 = 0 ; V_19 < V_221 ; V_19 ++ )
F_92 ( V_226 L_19 , V_227 [ V_19 ] ) ;
} else if ( V_222 == - 1 ) {
F_6 (cpu) {
V_25 = & F_8 ( V_209 , V_6 ) ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
}
}
return V_190 ;
}
static int F_93 ( const char * V_228 )
{
int V_229 = 0 ;
for (; ; V_228 ++ ) {
switch ( * V_228 ) {
case '0' ... '9' :
V_229 = 10 * V_229 + ( * V_228 - '0' ) ;
break;
default:
return V_229 ;
}
}
}
static int F_94 ( struct V_10 * V_11 , char * V_230 ,
int V_190 )
{
char * V_231 ;
char * V_232 ;
int V_174 = 0 ;
int V_229 ;
int V_233 = sizeof( V_234 ) / sizeof( * V_234 ) ;
V_231 = V_230 + strspn ( V_230 , V_235 ) ;
V_232 = V_231 ;
for (; * V_231 ; V_231 = V_232 + strspn ( V_232 , V_235 ) ) {
V_232 = V_231 + strcspn ( V_231 , V_235 ) ;
V_174 ++ ;
if ( V_232 == V_231 )
break;
}
if ( V_174 != V_233 ) {
F_92 ( V_236 L_20 , V_233 ) ;
return - V_224 ;
}
V_231 = V_230 + strspn ( V_230 , V_235 ) ;
V_232 = V_231 ;
for ( V_174 = 0 ; * V_231 ; V_231 = V_232 + strspn ( V_232 , V_235 ) , V_174 ++ ) {
V_232 = V_231 + strcspn ( V_231 , V_235 ) ;
V_229 = F_93 ( V_231 ) ;
switch ( V_174 ) {
case 0 :
if ( V_229 == 0 ) {
V_113 = V_237 ;
V_129 = V_237 ;
continue;
}
if ( V_229 < 1 || V_229 > V_11 -> V_54 ) {
F_92 ( V_226
L_21 ,
V_229 ) ;
return - V_224 ;
}
V_113 = V_229 ;
V_129 = V_229 ;
continue;
default:
if ( V_229 == 0 )
* V_234 [ V_174 ] . V_238 = V_234 [ V_174 ] . V_239 ;
else
* V_234 [ V_174 ] . V_238 = V_229 ;
continue;
}
if ( V_232 == V_231 )
break;
}
return 0 ;
}
static T_7 F_95 ( struct V_206 * V_206 , const char T_8 * V_220 ,
T_9 V_190 , T_6 * V_207 )
{
int V_6 ;
int V_214 ;
char V_230 [ 100 ] ;
struct V_10 * V_11 ;
if ( V_190 == 0 || V_190 > sizeof( V_230 ) - 1 )
return - V_224 ;
if ( F_90 ( V_230 , V_220 , V_190 ) )
return - V_225 ;
V_230 [ V_190 ] = '\0' ;
V_11 = & F_8 ( V_10 , F_19 () ) ;
V_214 = F_94 ( V_11 , V_230 , V_190 ) ;
if ( V_214 )
return V_214 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_113 = V_113 ;
V_11 -> V_129 = V_113 ;
V_11 -> V_107 = V_107 ;
V_11 -> V_109 = V_109 ;
V_11 -> V_115 = V_115 ;
V_11 -> V_155 = V_155 ;
V_11 -> V_128 = V_128 ;
V_11 -> V_240 = V_216 ;
V_11 -> V_135 = V_217 ;
V_11 -> V_126 = V_218 ;
}
return V_190 ;
}
static int F_96 ( struct V_241 * V_241 , struct V_206 * V_206 )
{
return F_97 ( V_206 , & V_242 ) ;
}
static int F_98 ( struct V_241 * V_241 , struct V_206 * V_206 )
{
return 0 ;
}
static int T_1 F_99 ( void )
{
struct V_243 * V_244 ;
if ( ! F_100 () )
return 0 ;
V_244 = F_101 ( V_245 , 0444 , NULL ,
& V_246 ) ;
if ( ! V_244 ) {
F_92 ( V_247 L_22 ,
V_245 ) ;
return - V_224 ;
}
V_248 = F_102 ( V_249 , NULL ) ;
if ( ! V_248 ) {
F_92 ( V_247 L_23 ,
V_249 ) ;
return - V_224 ;
}
V_250 = F_103 ( V_251 , 0600 ,
V_248 , NULL , & V_252 ) ;
if ( ! V_250 ) {
F_92 ( V_247 L_24 ,
V_251 ) ;
return - V_224 ;
}
return 0 ;
}
static void F_104 ( int V_4 , int V_173 , int V_253 )
{
int V_19 ;
int V_6 ;
unsigned long V_254 ;
unsigned long V_255 ;
unsigned long V_256 ;
T_9 V_257 ;
struct V_77 * V_77 ;
struct V_77 * V_258 ;
struct V_10 * V_11 ;
V_257 = sizeof( struct V_77 ) * V_259 * V_185 ;
V_77 = F_105 ( V_257 , V_215 , V_4 ) ;
F_106 ( ! V_77 ) ;
V_254 = F_107 ( V_77 ) ;
V_256 = V_254 >> V_260 ;
V_255 = V_254 & V_261 ;
F_108 ( V_173 , ( V_256 << V_262 | V_255 ) ) ;
for ( V_19 = 0 , V_258 = V_77 ; V_19 < ( V_259 * V_185 ) ; V_19 ++ , V_258 ++ ) {
memset ( V_258 , 0 , sizeof( struct V_77 ) ) ;
V_258 -> V_149 . V_263 = 1 ;
V_258 -> V_149 . V_264 = F_109 ( V_253 ) ;
V_258 -> V_149 . V_265 = V_266 ;
V_258 -> V_149 . V_267 = V_268 ;
V_258 -> V_149 . V_269 = 1 ;
}
F_6 (cpu) {
if ( V_173 != F_71 ( F_7 ( V_6 ) ) )
continue;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_184 = V_77 ;
}
}
static void F_110 ( int V_4 , int V_173 )
{
int V_6 ;
T_9 V_270 ;
char * V_271 ;
void * V_272 ;
unsigned long V_273 ;
unsigned long V_274 ;
unsigned long V_275 ;
unsigned long V_276 ;
struct V_13 * V_277 ;
struct V_10 * V_11 ;
V_270 = ( V_28 + 1 ) * sizeof( struct V_13 ) ;
V_272 = F_105 ( V_270 , V_215 , V_4 ) ;
V_277 = (struct V_13 * ) V_272 ;
F_106 ( ! V_277 ) ;
V_271 = ( char * ) V_277 + 31 ;
V_277 = (struct V_13 * ) ( ( ( unsigned long ) V_271 >> 5 ) << 5 ) ;
F_6 (cpu) {
if ( V_173 != F_84 ( V_6 ) )
continue;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_30 = V_277 ;
V_11 -> V_193 = V_277 ;
V_11 -> V_29 = V_277 + ( V_28 - 1 ) ;
}
V_273 = F_107 ( V_277 ) >> V_260 ;
V_274 = F_111 ( V_277 ) ;
V_275 = ( ( unsigned long ) V_273 << V_278 ) | V_274 ;
V_276 = F_111 ( V_277 + ( V_28 - 1 ) ) ;
F_112 ( V_173 , V_275 ) ;
F_113 ( V_173 , V_274 ) ;
F_114 ( V_173 , V_276 ) ;
memset ( V_277 , 0 , sizeof( struct V_13 ) * V_28 ) ;
}
static void T_1 F_115 ( int V_3 , int V_279 , int V_253 )
{
int V_4 ;
int V_173 ;
unsigned long V_280 ;
V_4 = F_2 ( V_3 ) ;
V_173 = F_71 ( V_3 ) ;
F_104 ( V_4 , V_173 , V_253 ) ;
F_110 ( V_4 , V_173 ) ;
V_280 = F_5 ( V_3 ) | V_281 ;
F_116 ( V_173 , ( ( V_280 << 32 ) | V_279 ) ) ;
}
static int F_117 ( void )
{
unsigned long V_199 ;
int V_282 ;
int V_283 ;
int V_148 ;
int V_284 ;
int V_214 ;
unsigned long V_285 ;
if ( F_38 () ) {
V_282 = V_202 & V_286 ;
V_199 = F_29 ( V_287 ) ;
V_148 = ( V_199 >> V_288 ) & V_289 ;
V_199 = F_29 ( V_290 ) ;
V_283 = ( V_199 >> V_291 ) & V_292 ;
V_284 = V_293 [ V_148 ] ;
V_285 = V_284 * V_282 * V_283 ;
V_214 = V_285 / 1000 ;
} else {
V_199 = F_29 ( V_287 ) ;
V_199 = ( V_199 & V_294 ) >> V_295 ;
if ( V_199 & ( 1L << V_296 ) )
V_282 = 80 ;
else
V_282 = 10 ;
V_284 = V_199 & V_297 ;
V_214 = V_282 * V_284 ;
}
return V_214 ;
}
static void T_1 F_118 ( void )
{
int V_6 ;
struct V_10 * V_11 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_118 = 0 ;
V_11 -> V_26 = & F_8 ( V_209 , V_6 ) ;
V_11 -> V_298 = F_79 ( 2 * V_87 ) ;
V_11 -> V_113 = V_113 ;
V_11 -> V_129 = V_113 ;
V_11 -> V_107 = V_107 ;
V_11 -> V_109 = V_109 ;
V_11 -> V_115 = V_115 ;
V_11 -> V_155 = V_155 ;
V_11 -> V_128 = V_128 ;
V_11 -> V_240 = V_216 ;
V_11 -> V_135 = V_217 ;
V_11 -> V_126 = V_218 ;
}
}
static int T_1 F_119 ( int V_253 ,
struct V_299 * V_300 ,
unsigned char * V_301 )
{
int V_6 ;
int V_173 ;
int V_3 ;
int V_302 ;
struct V_10 * V_11 ;
struct V_299 * V_303 ;
struct V_304 * V_305 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_173 = F_120 ( V_6 ) -> V_173 ;
if ( ( V_173 - V_253 ) >= V_186 ) {
F_92 ( V_306
L_25 ,
V_6 , V_173 , V_253 , V_186 ) ;
return 1 ;
}
V_11 -> V_307 = F_121 ( V_6 ) ;
V_11 -> V_178 = V_253 ;
V_3 = F_120 ( V_6 ) -> V_308 ;
* ( V_301 + ( V_3 / 8 ) ) |= ( 1 << ( V_3 % 8 ) ) ;
V_303 = & V_300 [ V_3 ] ;
V_303 -> V_309 ++ ;
V_303 -> V_3 = V_3 ;
V_303 -> V_173 = V_173 ;
V_302 = V_11 -> V_307 & 1 ;
V_303 -> V_310 |= ( 1 << V_302 ) ;
V_305 = & V_303 -> V_302 [ V_302 ] ;
V_305 -> V_311 [ V_305 -> V_309 ] = V_6 ;
V_305 -> V_309 ++ ;
if ( V_305 -> V_309 > V_312 ) {
F_92 ( V_306 L_26 ,
V_305 -> V_309 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_122 ( struct V_10 * V_40 )
{
int V_6 ;
T_9 V_313 = sizeof( struct V_175 ) * F_76 () ;
V_40 -> V_177 = F_105 ( V_313 , V_215 , V_40 -> V_307 ) ;
memset ( V_40 -> V_177 , 0 , V_313 ) ;
F_6 (cpu) {
V_40 -> V_177 [ V_6 ] . V_173 = F_120 ( V_6 ) -> V_173 ;
V_40 -> V_177 [ V_6 ] . V_3 = F_120 ( V_6 ) -> V_308 ;
}
}
static int F_123 ( struct V_304 * V_305 , struct V_299 * V_303 ,
struct V_10 * * V_314 ,
struct V_10 * * V_315 )
{
int V_19 ;
int V_6 ;
struct V_10 * V_11 ;
for ( V_19 = 0 ; V_19 < V_305 -> V_309 ; V_19 ++ ) {
V_6 = V_305 -> V_311 [ V_19 ] ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_6 = V_6 ;
if ( V_19 == 0 ) {
* V_314 = V_11 ;
if ( ! ( * V_315 ) )
* V_315 = V_11 ;
}
V_11 -> V_54 = V_303 -> V_309 ;
V_11 -> V_51 = V_305 -> V_309 ;
V_11 -> V_41 = * V_314 ;
V_11 -> V_3 = V_303 -> V_3 ;
V_11 -> V_48 = * V_315 ;
V_11 -> V_96 = F_120 ( V_6 ) -> V_316 ;
if ( V_11 -> V_96 >= V_317 ) {
F_92 ( V_306 L_27 ,
V_11 -> V_96 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_124 ( int V_198 ,
struct V_299 * V_300 ,
unsigned char * V_301 )
{
int V_302 ;
int V_3 ;
unsigned short V_310 ;
for ( V_3 = 0 ; V_3 < V_198 ; V_3 ++ ) {
struct V_299 * V_303 ;
struct V_10 * V_40 = NULL ;
struct V_10 * V_71 = NULL ;
if ( ! ( * ( V_301 + ( V_3 / 8 ) ) & ( 1 << ( V_3 % 8 ) ) ) )
continue;
V_303 = & V_300 [ V_3 ] ;
V_310 = V_303 -> V_310 ;
V_302 = 0 ;
while ( V_310 ) {
struct V_304 * V_305 ;
if ( ( V_310 & 1 ) ) {
V_305 = & V_303 -> V_302 [ V_302 ] ;
if ( F_123 ( V_305 , V_303 , & V_40 , & V_71 ) )
return 1 ;
}
V_302 ++ ;
V_310 = ( V_310 >> 1 ) ;
F_122 ( V_40 ) ;
}
}
return 0 ;
}
static int T_1 F_125 ( int V_198 , int V_318 )
{
unsigned char * V_301 ;
void * V_272 ;
struct V_299 * V_300 ;
V_87 = F_117 () ;
V_272 = F_126 ( V_198 * sizeof( struct V_299 ) , V_215 ) ;
V_300 = (struct V_299 * ) V_272 ;
memset ( V_300 , 0 , V_198 * sizeof( struct V_299 ) ) ;
V_301 = F_127 ( ( V_198 + 7 ) / 8 , V_215 ) ;
if ( F_119 ( V_318 , V_300 , V_301 ) )
return 1 ;
if ( F_124 ( V_198 , V_300 , V_301 ) )
return 1 ;
F_88 ( V_300 ) ;
F_88 ( V_301 ) ;
F_118 () ;
return 0 ;
}
static int T_1 F_128 ( void )
{
int V_3 ;
int V_173 ;
int V_198 ;
int V_319 ;
int V_320 ;
int V_279 ;
T_10 * V_64 ;
if ( ! F_100 () )
return 0 ;
if ( V_2 )
return 0 ;
F_129 (cur_cpu) {
V_64 = & F_8 ( V_182 , V_319 ) ;
F_130 ( V_64 , V_215 , F_121 ( V_319 ) ) ;
}
V_260 = V_321 -> V_322 ;
V_261 = ( 1UL << V_321 -> V_322 ) - 1 ;
V_198 = F_69 () ;
F_131 ( & V_117 ) ;
V_121 = F_79 ( V_216 ) ;
V_323 = 0x7fffffff ;
for ( V_3 = 0 ; V_3 < V_198 ; V_3 ++ ) {
V_320 = F_70 ( V_3 ) ;
if ( V_320 && ( F_71 ( V_3 ) < V_323 ) )
V_323 = F_71 ( V_3 ) ;
}
if ( F_125 ( V_198 , V_323 ) ) {
V_2 = 1 ;
return 0 ;
}
V_279 = V_324 ;
F_132 (uvhub)
if ( F_70 ( V_3 ) )
F_115 ( V_3 , V_279 , V_323 ) ;
F_68 () ;
F_133 ( V_279 , V_325 ) ;
F_132 (uvhub) {
if ( F_70 ( V_3 ) ) {
unsigned long V_229 ;
unsigned long V_22 ;
V_173 = F_71 ( V_3 ) ;
V_229 = 1L << 63 ;
F_134 ( V_173 , V_229 ) ;
V_22 = 1 ;
F_135 ( V_173 , V_22 ) ;
}
}
return 0 ;
}
