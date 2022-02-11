static int T_1 F_1 ( char * V_1 )
{
int V_2 ;
if ( ! V_1 )
return - V_3 ;
V_2 = F_2 ( V_1 , & V_4 ) ;
if ( V_2 )
return V_2 ;
V_4 = ! V_4 ;
if ( ! V_4 )
F_3 ( L_1 ) ;
else
F_3 ( L_2 ) ;
return 0 ;
}
static void
F_4 ( void )
{
int V_5 ;
struct V_6 * V_7 ;
if ( V_8 ) {
F_3 ( L_3 ) ;
return;
}
V_4 = false ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_4 = false ;
}
F_3 ( L_4 ) ;
return;
}
static void
F_7 ( void )
{
int V_5 ;
struct V_6 * V_7 ;
V_4 = true ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_4 = true ;
}
F_3 ( L_5 ) ;
return;
}
static int T_1 F_8 ( int V_9 )
{
int V_10 , V_11 ;
F_9 (node) {
V_11 = F_10 ( V_10 ) ;
if ( V_9 == V_11 )
return V_10 ;
}
return - 1 ;
}
static int T_1 F_11 ( int V_9 )
{
int V_5 ;
F_5 (cpu)
if ( V_9 == F_12 ( V_5 ) )
return F_6 ( V_12 , V_5 ) ;
return - 1 ;
}
static void F_13 ( struct V_13 * V_14 , struct V_6 * V_7 ,
int V_15 )
{
unsigned long V_16 ;
struct V_17 * V_18 ;
V_18 = V_14 -> V_18 ;
if ( ! V_18 -> V_19 && V_15 ) {
V_16 = ( V_18 -> V_20 << V_21 ) | V_18 -> V_20 ;
F_14 ( V_16 ) ;
}
V_18 -> V_22 = 1 ;
V_18 -> V_20 = 0 ;
}
static void F_15 ( struct V_13 * V_14 ,
struct V_6 * V_7 )
{
int V_23 ;
int V_24 = 0 ;
unsigned long V_25 ;
unsigned long V_26 = 0 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_17 * V_27 ;
struct V_28 * V_29 = V_7 -> V_30 ;
V_29 -> V_31 ++ ;
for ( V_27 = V_18 + 1 , V_23 = 0 ; V_23 < V_32 ; V_27 ++ , V_23 ++ ) {
if ( V_27 > V_14 -> V_33 )
V_27 = V_14 -> V_34 ;
if ( V_27 == V_18 )
break;
if ( ( V_27 -> V_22 == 0 ) && ( V_27 -> V_19 == 0 ) &&
( V_27 -> V_20 ) && ( ( V_27 -> V_20 &
V_18 -> V_20 ) == 0 ) &&
( V_27 -> V_35 == V_18 -> V_35 ) &&
( V_27 -> V_36 != V_37 ) ) {
V_26 = F_16 () ;
V_25 = V_27 -> V_20 ;
if ( V_26 & ( V_25 << V_21 ) ) {
unsigned long V_38 ;
V_27 -> V_19 = 1 ;
V_29 -> V_39 ++ ;
V_24 ++ ;
V_38 = ( V_25 << V_21 ) | V_25 ;
F_14 ( V_38 ) ;
}
}
}
if ( ! V_24 )
V_29 -> V_40 ++ ;
}
static void F_17 ( struct V_13 * V_14 , struct V_6 * V_7 ,
int V_15 )
{
short V_41 = 0 ;
short * V_42 ;
struct atomic_short * V_43 ;
struct V_28 * V_29 = V_7 -> V_30 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_6 * V_44 = V_7 -> V_45 ;
if ( V_18 -> V_46 == V_47 ) {
F_18 () ;
V_29 -> V_48 ++ ;
} else {
F_19 ( V_18 -> V_46 ) ;
V_29 -> V_49 ++ ;
}
V_29 -> V_50 ++ ;
if ( V_18 -> V_36 == V_51 && V_7 == V_7 -> V_52 )
F_15 ( V_14 , V_7 ) ;
V_42 = & V_44 -> V_53 [ V_14 -> V_54 ] ;
V_43 = (struct atomic_short * ) V_42 ;
V_41 = F_20 ( 1 , V_43 ) ;
if ( V_41 == V_7 -> V_55 ) {
int V_56 ;
* V_42 = 0 ;
V_43 = (struct atomic_short * ) & V_18 -> V_57 ;
V_56 = F_20 ( V_41 , V_43 ) ;
if ( V_56 == V_7 -> V_58 ) {
F_13 ( V_14 , V_7 , V_15 ) ;
}
}
return;
}
static int F_21 ( int V_59 , struct V_6 * V_44 )
{
int V_5 ;
struct V_60 * V_61 ;
F_5 (cpu) {
V_61 = & V_44 -> V_62 [ V_5 ] ;
if ( V_59 == V_61 -> V_59 )
return V_5 ;
}
return - 1 ;
}
static void F_22 ( void * V_63 )
{
int V_23 ;
struct V_6 * V_7 = & F_6 ( V_6 , F_23 () ) ;
struct V_64 * V_65 = (struct V_64 * ) V_63 ;
struct V_17 * V_18 ;
struct V_28 * V_29 = V_7 -> V_30 ;
V_29 -> V_66 ++ ;
for ( V_18 = V_7 -> V_34 , V_23 = 0 ; V_23 < V_32 ; V_18 ++ , V_23 ++ ) {
unsigned long V_25 ;
if ( ( V_18 -> V_22 == 0 ) &&
( V_18 -> V_19 == 0 ) &&
( V_18 -> V_35 == V_65 -> V_67 ) &&
( V_18 -> V_20 ) &&
( V_18 -> V_36 != V_37 ) ) {
unsigned long V_26 ;
unsigned long V_38 ;
V_18 -> V_19 = 1 ;
V_26 = F_16 () ;
V_25 = V_18 -> V_20 ;
V_38 = ( V_25 << V_21 ) | V_25 ;
if ( V_26 & V_25 ) {
V_29 -> V_68 ++ ;
F_14 ( V_38 ) ;
}
}
}
return;
}
static void F_24 ( struct V_69 * V_70 , struct V_6 * V_7 )
{
int V_59 ;
int V_71 ;
int V_72 ;
int V_67 = V_7 -> V_5 ;
T_2 * V_73 = V_7 -> V_52 -> V_74 ;
struct V_6 * V_44 = V_7 -> V_45 ;
struct V_64 V_64 ;
V_64 . V_67 = V_67 ;
F_25 ( V_73 ) ;
V_72 = sizeof( struct V_69 ) * V_75 ;
for ( V_59 = 0 ; V_59 < V_72 ; V_59 ++ ) {
int V_5 ;
if ( ! F_26 ( V_59 , V_70 ) )
continue;
V_71 = V_59 + V_7 -> V_76 ;
V_5 = F_21 ( V_71 , V_44 ) ;
F_27 ( V_5 , V_73 ) ;
}
F_28 ( V_73 , F_22 , ( void * ) & V_64 , 1 ) ;
return;
}
static inline unsigned long long F_29 ( unsigned long long V_77 )
{
struct V_78 * V_79 = F_30 () ;
unsigned long long V_80 ;
V_80 = F_31 ( V_77 , V_79 -> V_81 , V_79 -> V_82 ) ;
F_32 ( V_79 ) ;
return V_80 ;
}
static inline unsigned long long F_33 ( unsigned long long V_80 )
{
struct V_78 * V_79 = F_30 () ;
unsigned long long V_77 ;
V_77 = ( V_80 << V_79 -> V_82 ) / V_79 -> V_81 ;
F_32 ( V_79 ) ;
return V_77 ;
}
static inline unsigned long F_34 ( unsigned long long V_77 )
{
return F_29 ( V_77 ) / V_83 ;
}
static inline T_3 F_35 ( unsigned long V_84 )
{
return F_33 ( V_84 * V_85 ) ;
}
static inline unsigned long long F_36 ( unsigned long V_86 )
{
return F_33 ( V_86 * V_83 ) ;
}
static inline void F_37 ( struct V_6 * V_87 )
{
F_20 ( 1 , (struct atomic_short * ) & V_87 -> V_88 ) ;
}
static inline void F_38 ( struct V_6 * V_87 )
{
F_20 ( - 1 , (struct atomic_short * ) & V_87 -> V_88 ) ;
}
static unsigned long F_39 ( unsigned long V_89 , int V_90 )
{
unsigned long V_91 ;
V_91 = F_40 ( V_89 ) ;
V_91 >>= V_90 ;
V_91 &= V_92 ;
return V_91 ;
}
static int F_41 ( struct V_93 * V_93 ,
unsigned long V_89 , int V_90 ,
struct V_6 * V_7 , long V_94 )
{
unsigned long V_91 ;
T_3 V_95 ;
struct V_28 * V_29 = V_7 -> V_30 ;
V_91 = F_39 ( V_89 , V_90 ) ;
while ( ( V_91 != V_96 ) ) {
if ( V_91 == V_97 ) {
V_29 -> V_98 ++ ;
return V_99 ;
} else if ( V_91 == V_100 ) {
V_29 -> V_101 ++ ;
V_95 = F_42 () ;
if ( F_34 ( V_95 - V_7 -> V_102 ) < V_103 ) {
V_7 -> V_104 = 0 ;
return V_105 ;
}
V_7 -> V_104 = 0 ;
return V_106 ;
} else {
F_43 () ;
}
V_91 = F_39 ( V_89 , V_90 ) ;
}
V_7 -> V_104 ++ ;
return V_107 ;
}
static unsigned long F_44 ( unsigned long V_108 , int V_109 , int V_110 )
{
unsigned long V_91 ;
V_91 =
( ( F_45 ( V_108 ) >> V_109 ) & V_92 ) << 1 ;
return V_91 ;
}
int F_46 ( struct V_6 * V_7 )
{
int V_5 = V_7 -> V_111 ;
int V_89 ;
int V_90 ;
V_89 = V_112 ;
V_90 = V_5 * V_113 ;
return ( ( ( ( ( F_45 ( V_89 ) >> V_90 ) &
V_92 ) ) << 1 ) == V_114 ) ;
}
int F_47 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_30 ;
V_29 -> V_115 ++ ;
V_7 -> V_116 = 1 ;
return V_99 ;
}
static int F_48 ( struct V_93 * V_93 ,
unsigned long V_89 , int V_90 ,
struct V_6 * V_7 , long V_94 )
{
unsigned long V_117 ;
T_3 V_95 ;
int V_110 = V_7 -> V_111 ;
long V_118 = 0 ;
struct V_28 * V_29 = V_7 -> V_30 ;
V_117 = F_44 ( V_89 , V_90 , V_110 ) ;
while ( V_117 != V_119 ) {
if ( ( V_117 == V_120 ) ) {
V_29 -> V_98 ++ ;
return V_99 ;
} else if ( V_117 == V_121 ) {
V_95 = F_42 () ;
if ( F_34 ( V_95 - V_7 -> V_102 ) < V_103 ) {
V_7 -> V_104 = 0 ;
V_29 -> V_122 ++ ;
return V_99 ;
}
V_29 -> V_101 ++ ;
V_7 -> V_104 = 0 ;
return V_99 ;
} else {
V_118 ++ ;
if ( V_118 > 1000000 ) {
V_118 = 0 ;
V_95 = F_42 () ;
if ( ( V_95 - V_7 -> V_102 ) > V_7 -> V_123 )
return F_47 ( V_7 ) ;
}
F_43 () ;
}
V_117 = F_44 ( V_89 , V_90 , V_110 ) ;
}
V_7 -> V_104 ++ ;
return V_107 ;
}
static int F_49 ( struct V_93 * V_93 , struct V_6 * V_7 , long V_94 )
{
int V_90 ;
unsigned long V_89 ;
int V_110 = V_7 -> V_111 ;
if ( V_110 < V_124 ) {
V_89 = V_112 ;
V_90 = V_110 * V_113 ;
} else {
V_89 = V_125 ;
V_90 = ( ( V_110 - V_124 ) * V_113 ) ;
}
if ( V_7 -> V_126 == 1 )
return F_41 ( V_93 , V_89 , V_90 , V_7 , V_94 ) ;
else
return F_48 ( V_93 , V_89 , V_90 , V_7 , V_94 ) ;
}
static void F_50 ( struct V_93 * V_93 ,
struct V_6 * V_7 ,
struct V_6 * V_87 , struct V_28 * V_29 )
{
F_51 ( V_7 -> V_127 ) ;
V_7 -> V_128 ++ ;
if ( V_7 -> V_128 >= V_7 -> V_129 ) {
V_7 -> V_128 = 0 ;
F_37 ( V_87 ) ;
F_52 ( & V_87 -> V_130 ) ;
F_24 ( & V_93 -> V_70 , V_7 ) ;
F_53 ( & V_87 -> V_130 ) ;
F_38 ( V_87 ) ;
V_7 -> V_131 ++ ;
V_29 -> V_132 ++ ;
}
}
static void F_54 ( struct V_93 * V_93 ,
struct V_6 * V_7 , struct V_6 * V_87 ,
struct V_28 * V_29 )
{
V_87 -> V_133 = 1 ;
V_7 -> V_134 ++ ;
if ( V_7 -> V_134 >= V_7 -> V_135 ) {
V_7 -> V_134 = 0 ;
F_37 ( V_87 ) ;
F_52 ( & V_87 -> V_130 ) ;
F_24 ( & V_93 -> V_70 , V_7 ) ;
F_53 ( & V_87 -> V_130 ) ;
F_38 ( V_87 ) ;
V_7 -> V_131 ++ ;
V_29 -> V_136 ++ ;
}
}
static void F_55 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
int V_137 ;
struct V_6 * V_138 ;
struct V_6 * V_87 ;
T_3 V_139 ;
V_87 = V_7 -> V_52 ;
F_52 ( & V_87 -> V_140 ) ;
if ( ! V_7 -> V_141 ) {
V_29 -> V_142 ++ ;
V_139 = F_42 () ;
F_5 (tcpu) {
V_138 = & F_6 ( V_6 , V_137 ) ;
if ( V_138 -> V_52 == V_87 ) {
V_138 -> V_141 = 1 ;
V_138 -> V_143 =
V_139 + V_7 -> V_144 ;
}
}
}
F_53 ( & V_87 -> V_140 ) ;
}
static void F_56 ( int V_29 , struct V_6 * V_7 ,
struct V_6 * V_87 )
{
V_7 -> V_128 = 0 ;
V_7 -> V_134 = 0 ;
if ( V_29 != V_107 )
return;
if ( V_7 -> V_104 <= V_7 -> V_145 )
return;
if ( V_87 -> V_133 >= V_87 -> V_146 )
return;
V_87 -> V_133 ++ ;
}
static void F_57 ( T_3 V_147 , T_3 V_148 ,
struct V_6 * V_7 , struct V_28 * V_29 ,
int V_149 , int V_94 )
{
T_3 V_150 ;
if ( V_148 > V_147 ) {
V_150 = V_148 - V_147 ;
V_29 -> V_151 += V_150 ;
if ( ( V_149 == V_107 ) && ( V_94 == 1 ) ) {
V_7 -> V_152 ++ ;
V_7 -> V_153 += V_150 ;
if ( ( V_150 > V_154 ) &&
( V_7 -> V_152 > V_7 -> V_155 ) &&
( ( V_7 -> V_153 / V_7 -> V_152 ) >
V_154 ) ) {
V_29 -> V_156 ++ ;
F_55 ( V_7 , V_29 ) ;
}
}
} else
V_29 -> V_157 -- ;
if ( V_149 == V_107 && V_94 > 1 )
V_29 -> V_158 ++ ;
else if ( V_149 == V_99 ) {
V_29 -> V_159 ++ ;
if ( F_42 () > V_7 -> V_160 )
V_7 -> V_161 = 0 ;
V_7 -> V_161 ++ ;
if ( V_7 -> V_161 == 1 )
V_7 -> V_160 = F_42 () + V_7 -> V_144 ;
if ( V_7 -> V_161 > V_7 -> V_162 ) {
F_55 ( V_7 , V_29 ) ;
V_29 -> V_163 ++ ;
}
}
}
static void F_58 ( struct V_6 * V_87 , struct V_28 * V_29 )
{
T_4 * V_164 = & V_87 -> V_165 ;
T_5 * V_166 ;
V_166 = & V_87 -> V_167 ;
if ( ! F_59 ( V_164 , V_166 , V_87 -> V_133 ) ) {
V_29 -> V_168 ++ ;
do {
F_43 () ;
} while ( ! F_59 ( V_164 , V_166 , V_87 -> V_133 ) );
}
}
static void F_60 ( int V_149 , struct V_93 * V_93 ,
struct V_6 * V_7 , struct V_6 * V_87 ,
struct V_28 * V_29 )
{
if ( V_149 == V_105 )
F_50 ( V_93 , V_7 , V_87 , V_29 ) ;
else if ( V_149 == V_106 )
F_54 ( V_93 , V_7 , V_87 , V_29 ) ;
}
int F_61 ( struct V_74 * V_169 , struct V_6 * V_7 ,
struct V_93 * V_93 )
{
int V_170 = 0 ;
int V_171 = 0 ;
int V_172 = 0 ;
long V_94 = 0 ;
unsigned long V_173 ;
T_3 V_147 ;
T_3 V_148 ;
struct V_28 * V_29 = V_7 -> V_30 ;
struct V_6 * V_87 = V_7 -> V_52 ;
struct V_174 * V_175 = NULL ;
struct V_176 * V_177 = NULL ;
if ( V_7 -> V_126 == 1 ) {
V_172 = 1 ;
F_58 ( V_87 , V_29 ) ;
}
while ( V_87 -> V_88 )
F_43 () ;
V_147 = F_42 () ;
if ( V_172 )
V_175 = & V_93 -> V_178 . V_175 ;
else
V_177 = & V_93 -> V_178 . V_177 ;
do {
if ( V_94 == 0 ) {
if ( V_172 )
V_175 -> V_36 = V_179 ;
else
V_177 -> V_36 = V_179 ;
V_170 = V_7 -> V_180 ++ ;
} else {
if ( V_172 )
V_175 -> V_36 = V_51 ;
else
V_177 -> V_36 = V_51 ;
V_29 -> V_181 ++ ;
}
if ( V_172 )
V_175 -> V_182 = V_170 ;
else
V_177 -> V_182 = V_170 ;
V_173 = ( 1UL << V_183 ) | V_7 -> V_111 ;
V_7 -> V_102 = F_42 () ;
F_62 ( V_173 ) ;
V_94 ++ ;
V_171 = F_49 ( V_93 , V_7 , V_94 ) ;
F_60 ( V_171 , V_93 , V_7 , V_87 , V_29 ) ;
if ( V_7 -> V_131 >= V_7 -> V_184 ) {
V_7 -> V_131 = 0 ;
V_29 -> V_185 ++ ;
V_171 = V_99 ;
break;
}
F_43 () ;
} while ( ( V_171 == V_105 ) ||
( V_171 == V_106 ) );
V_148 = F_42 () ;
F_56 ( V_171 , V_7 , V_87 ) ;
while ( V_87 -> V_88 )
F_43 () ;
F_63 ( & V_87 -> V_167 ) ;
F_57 ( V_147 , V_148 , V_7 , V_29 , V_171 , V_94 ) ;
if ( V_171 == V_99 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
int V_137 ;
struct V_6 * V_138 ;
struct V_6 * V_87 ;
V_87 = V_7 -> V_52 ;
F_52 ( & V_87 -> V_140 ) ;
if ( V_7 -> V_141 && ( F_42 () >= V_7 -> V_143 ) ) {
V_29 -> V_186 ++ ;
F_5 (tcpu) {
V_138 = & F_6 ( V_6 , V_137 ) ;
if ( V_138 -> V_52 == V_87 ) {
V_138 -> V_141 = 0 ;
V_138 -> V_152 = 0 ;
V_138 -> V_153 = 0 ;
V_138 -> V_161 = 0 ;
}
}
F_53 ( & V_87 -> V_140 ) ;
return 0 ;
}
F_53 ( & V_87 -> V_140 ) ;
return - 1 ;
}
static void F_65 ( struct V_28 * V_29 , int V_187 , int V_188 ,
int V_189 , struct V_93 * V_93 )
{
V_29 -> V_157 ++ ;
V_29 -> V_190 += V_189 + V_187 ;
V_29 -> V_191 += V_189 ;
V_29 -> V_192 += V_187 ;
V_188 = F_66 ( & V_93 -> V_70 ) ;
if ( V_187 ) {
V_29 -> V_193 ++ ;
V_29 -> V_194 += ( V_188 - 1 ) ;
} else
V_29 -> V_194 += V_188 ;
V_29 -> V_195 += V_188 ;
if ( V_188 >= 16 )
V_29 -> V_196 ++ ;
else if ( V_188 >= 8 )
V_29 -> V_197 ++ ;
else if ( V_188 >= 4 )
V_29 -> V_198 ++ ;
else if ( V_188 >= 2 )
V_29 -> V_199 ++ ;
else
V_29 -> V_200 ++ ;
}
static int F_67 ( struct V_74 * V_169 , struct V_6 * V_7 ,
struct V_93 * V_93 , int * V_201 , int * V_202 )
{
int V_5 ;
int V_59 ;
int V_203 = 0 ;
struct V_60 * V_61 ;
F_68 (cpu, flush_mask) {
V_61 = & V_7 -> V_45 -> V_62 [ V_5 ] ;
V_59 = V_61 -> V_59 - V_7 -> V_76 ;
F_69 ( V_59 , & V_93 -> V_70 ) ;
V_203 ++ ;
if ( V_61 -> V_9 == V_7 -> V_9 )
( * V_201 ) ++ ;
else
( * V_202 ) ++ ;
}
if ( ! V_203 )
return 1 ;
return 0 ;
}
const struct V_74 * F_70 ( const struct V_74 * V_74 ,
struct V_204 * V_205 ,
unsigned long V_206 ,
unsigned long V_207 ,
unsigned int V_5 )
{
int V_187 = 0 ;
int V_189 = 0 ;
int V_188 = 0 ;
struct V_93 * V_93 ;
struct V_74 * V_169 ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned long V_91 ;
unsigned long V_208 ;
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 )
return V_74 ;
V_29 = V_7 -> V_30 ;
V_29 -> V_209 ++ ;
if ( V_7 -> V_116 ) {
V_91 =
F_45 ( V_112 ) ;
V_208 = ( ( V_91 >> ( V_7 -> V_111 *
V_113 ) ) & V_92 ) << 1 ;
if ( V_208 == V_114 )
return V_74 ;
V_7 -> V_116 = 0 ;
}
if ( V_7 -> V_141 ) {
if ( F_64 ( V_7 , V_29 ) ) {
V_29 -> V_210 ++ ;
return V_74 ;
}
}
V_169 = (struct V_74 * ) F_6 ( V_211 , V_5 ) ;
F_71 ( V_169 , V_74 , F_72 ( V_5 ) ) ;
if ( F_73 ( V_5 , V_74 ) )
V_29 -> V_212 ++ ;
V_93 = V_7 -> V_213 ;
V_93 += ( V_214 * V_7 -> V_111 ) ;
F_74 ( & V_93 -> V_70 , V_215 ) ;
if ( F_67 ( V_169 , V_7 , V_93 , & V_187 , & V_189 ) )
return NULL ;
F_65 ( V_29 , V_187 , V_188 , V_189 , V_93 ) ;
if ( ! V_207 || ( V_207 - V_206 ) <= V_216 )
V_93 -> V_217 . V_46 = V_206 ;
else
V_93 -> V_217 . V_46 = V_47 ;
V_93 -> V_217 . V_35 = V_5 ;
if ( ! F_61 ( V_169 , V_7 , V_93 ) )
return NULL ;
else
return V_74 ;
}
struct V_17 * F_75 ( struct V_17 * V_18 ,
struct V_6 * V_7 )
{
struct V_17 * V_218 = V_18 + 1 ;
unsigned char V_20 = V_18 -> V_20 ;
if ( V_218 > V_7 -> V_33 )
V_218 = V_7 -> V_34 ;
while ( V_218 != V_18 ) {
if ( ( V_218 -> V_19 == 0 ) && ( V_218 -> V_22 == 0 ) &&
( V_218 -> V_20 == V_20 ) )
return V_218 ;
V_218 ++ ;
if ( V_218 > V_7 -> V_33 )
V_218 = V_7 -> V_34 ;
}
return NULL ;
}
void F_76 ( struct V_13 * V_14 , struct V_6 * V_7 )
{
unsigned long V_219 ;
unsigned char V_20 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_17 * V_220 ;
V_219 = F_16 () ;
V_20 = V_18 -> V_20 ;
if ( ( V_20 & V_219 ) == 0 ) {
V_220 = F_75 ( V_18 , V_7 ) ;
if ( V_220 ) {
F_17 ( V_14 , V_7 , 0 ) ;
return;
}
}
F_17 ( V_14 , V_7 , 1 ) ;
return;
}
void F_77 ( struct V_221 * V_222 )
{
int V_223 = 0 ;
T_3 V_224 ;
struct V_17 * V_18 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
struct V_13 V_225 ;
F_78 () ;
V_224 = F_42 () ;
V_7 = & F_6 ( V_6 , F_23 () ) ;
V_29 = V_7 -> V_30 ;
V_225 . V_34 = V_7 -> V_34 ;
V_225 . V_33 = V_7 -> V_33 ;
V_18 = V_7 -> V_226 ;
while ( V_18 -> V_20 ) {
V_223 ++ ;
V_225 . V_54 = V_18 - V_225 . V_34 ;
V_225 . V_18 = V_18 ;
if ( V_7 -> V_126 == 2 )
F_76 ( & V_225 , V_7 ) ;
else
F_17 ( & V_225 , V_7 , 1 ) ;
V_18 ++ ;
if ( V_18 > V_225 . V_33 )
V_18 = V_225 . V_34 ;
V_7 -> V_226 = V_18 ;
}
V_29 -> V_227 += ( F_42 () - V_224 ) ;
if ( ! V_223 )
V_29 -> V_228 ++ ;
else if ( V_223 > 1 )
V_29 -> V_229 ++ ;
}
static void T_1 F_79 ( void )
{
int V_9 ;
int V_230 ;
int V_59 ;
unsigned long V_219 ;
V_230 = F_80 () ;
for ( V_9 = 0 ; V_9 < V_230 ; V_9 ++ ) {
if ( ! F_81 ( V_9 ) )
continue;
V_59 = F_82 ( V_9 ) ;
V_219 = F_83 ( V_59 ) ;
V_219 &= ~ ( 1L << V_231 ) ;
F_84 ( V_59 , V_219 ) ;
V_219 &= ~ ( ( unsigned long ) 0xf << V_232 ) ;
V_219 |= ( V_233 << V_232 ) ;
F_84 ( V_59 , V_219 ) ;
V_219 |= ( 1L << V_231 ) ;
if ( F_85 () ) {
V_219 &= ~ ( 1L << V_234 ) ;
} else if ( F_86 () ) {
V_219 &= ~ ( 1L << V_235 ) ;
V_219 |= ( 1L << V_236 ) ;
}
F_84 ( V_59 , V_219 ) ;
}
}
static void * F_87 ( struct V_237 * V_238 , T_6 * V_108 )
{
if ( * V_108 < F_88 () )
return V_108 ;
return NULL ;
}
static void * F_89 ( struct V_237 * V_238 , void * V_79 , T_6 * V_108 )
{
( * V_108 ) ++ ;
if ( * V_108 < F_88 () )
return V_108 ;
return NULL ;
}
static void F_90 ( struct V_237 * V_238 , void * V_79 )
{
}
static int F_91 ( struct V_237 * V_238 , void * V_79 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
int V_5 ;
V_5 = * ( T_6 * ) V_79 ;
if ( ! V_5 ) {
F_92 ( V_238 ,
L_6 ) ;
F_92 ( V_238 , L_7 ) ;
F_92 ( V_238 ,
L_8 ) ;
F_92 ( V_238 ,
L_9 ) ;
F_92 ( V_238 ,
L_10 ) ;
F_92 ( V_238 ,
L_11 ) ;
F_92 ( V_238 , L_12 ) ;
}
if ( V_5 < F_88 () && F_93 ( V_5 ) ) {
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 ) {
F_94 ( V_238 , L_13 , V_5 ) ;
return 0 ;
}
V_29 = V_7 -> V_30 ;
F_94 ( V_238 ,
L_14 ,
V_5 , V_7 -> V_4 , V_29 -> V_157 ,
F_34 ( V_29 -> V_151 ) ,
V_29 -> V_212 , V_29 -> V_192 ,
V_29 -> V_191 , V_29 -> V_190 ,
V_29 -> V_193 , V_29 -> V_194 ,
V_29 -> V_195 , V_29 -> V_196 ) ;
F_94 ( V_238 , L_15 ,
V_29 -> V_197 , V_29 -> V_198 ,
V_29 -> V_199 , V_29 -> V_200 ,
V_29 -> V_101 , V_29 -> V_239 ) ;
F_94 ( V_238 , L_16 ,
V_29 -> V_181 , V_29 -> V_158 ,
V_29 -> V_132 , V_29 -> V_136 ,
V_29 -> V_159 , V_29 -> V_98 ,
V_29 -> V_240 , V_29 -> V_168 ) ;
F_94 ( V_238 , L_17 ,
V_29 -> V_142 , V_29 -> V_186 ,
V_29 -> V_115 , V_29 -> V_241 ,
V_29 -> V_242 , V_29 -> V_209 ,
V_29 -> V_210 , V_29 -> V_122 ,
V_29 -> V_185 , V_29 -> V_163 ,
V_29 -> V_156 ) ;
F_94 ( V_238 ,
L_18 ,
F_95 ( F_96 ( V_5 ) ) ,
V_29 -> V_50 , F_34 ( V_29 -> V_227 ) ,
V_29 -> V_48 , V_29 -> V_49 , V_29 -> V_229 ,
V_29 -> V_228 , V_29 -> V_31 , V_29 -> V_39 ,
V_29 -> V_40 , V_29 -> V_66 ,
V_29 -> V_68 ) ;
}
return 0 ;
}
static T_7 F_97 ( struct V_238 * V_238 , char T_8 * V_243 ,
T_9 V_223 , T_6 * V_244 )
{
char * V_245 ;
int V_246 ;
V_245 = F_98 ( V_247 , L_19 ,
L_20 ,
L_21 ,
L_22 ,
V_133 , V_127 , V_129 ,
V_135 , V_184 , V_145 ,
V_248 , V_249 , V_144 ,
V_162 ) ;
if ( ! V_245 )
return - V_250 ;
V_246 = F_99 ( V_243 , V_223 , V_244 , V_245 , strlen ( V_245 ) ) ;
F_100 ( V_245 ) ;
return V_246 ;
}
static T_7 F_101 ( struct V_238 * V_238 , const char T_8 * V_251 ,
T_9 V_223 , T_6 * V_79 )
{
int V_5 ;
int V_23 ;
int V_252 ;
long V_253 ;
char V_254 [ 64 ] ;
struct V_28 * V_29 ;
if ( V_223 == 0 || V_223 > sizeof( V_254 ) )
return - V_3 ;
if ( F_102 ( V_254 , V_251 , V_223 ) )
return - V_255 ;
V_254 [ V_223 - 1 ] = '\0' ;
if ( ! strcmp ( V_254 , L_23 ) ) {
F_4 () ;
return V_223 ;
} else if ( ! strcmp ( V_254 , L_24 ) ) {
F_7 () ;
return V_223 ;
}
if ( F_103 ( V_254 , 10 , & V_253 ) < 0 ) {
F_104 ( V_256 L_25 , V_254 ) ;
return - V_3 ;
}
if ( V_253 == 0 ) {
V_252 = F_105 ( V_257 ) ;
F_104 ( V_256 L_26 ) ;
F_104 ( V_256 L_27 ) ;
for ( V_23 = 0 ; V_23 < V_252 ; V_23 ++ )
F_104 ( V_256 L_28 , V_257 [ V_23 ] ) ;
} else if ( V_253 == - 1 ) {
F_5 (cpu) {
V_29 = & F_6 ( V_258 , V_5 ) ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
}
}
return V_223 ;
}
static int F_106 ( const char * V_259 )
{
int V_260 = 0 ;
for (; ; V_259 ++ ) {
switch ( * V_259 ) {
case '0' ... '9' :
V_260 = 10 * V_260 + ( * V_259 - '0' ) ;
break;
default:
return V_260 ;
}
}
}
static int F_107 ( struct V_6 * V_7 , char * V_261 ,
int V_223 )
{
char * V_262 ;
char * V_263 ;
int V_203 = 0 ;
int V_260 ;
int V_264 = F_105 ( V_265 ) ;
V_262 = V_261 + strspn ( V_261 , V_266 ) ;
V_263 = V_262 ;
for (; * V_262 ; V_262 = V_263 + strspn ( V_263 , V_266 ) ) {
V_263 = V_262 + strcspn ( V_262 , V_266 ) ;
V_203 ++ ;
if ( V_263 == V_262 )
break;
}
if ( V_203 != V_264 ) {
F_104 ( V_267 L_29 , V_264 ) ;
return - V_3 ;
}
V_262 = V_261 + strspn ( V_261 , V_266 ) ;
V_263 = V_262 ;
for ( V_203 = 0 ; * V_262 ; V_262 = V_263 + strspn ( V_263 , V_266 ) , V_203 ++ ) {
V_263 = V_262 + strcspn ( V_262 , V_266 ) ;
V_260 = F_106 ( V_262 ) ;
switch ( V_203 ) {
case 0 :
if ( V_260 == 0 ) {
V_133 = V_268 ;
V_146 = V_268 ;
continue;
}
if ( V_260 < 1 || V_260 > V_7 -> V_58 ) {
F_104 ( V_256
L_30 ,
V_260 ) ;
return - V_3 ;
}
V_133 = V_260 ;
V_146 = V_260 ;
continue;
default:
if ( V_260 == 0 )
* V_265 [ V_203 ] . V_269 = V_265 [ V_203 ] . V_270 ;
else
* V_265 [ V_203 ] . V_269 = V_260 ;
continue;
}
if ( V_263 == V_262 )
break;
}
return 0 ;
}
static T_7 F_108 ( struct V_238 * V_238 , const char T_8 * V_251 ,
T_9 V_223 , T_6 * V_79 )
{
int V_5 ;
int V_246 ;
char V_261 [ 100 ] ;
struct V_6 * V_7 ;
if ( V_223 == 0 || V_223 > sizeof( V_261 ) - 1 )
return - V_3 ;
if ( F_102 ( V_261 , V_251 , V_223 ) )
return - V_255 ;
V_261 [ V_223 ] = '\0' ;
V_5 = F_109 () ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_246 = F_107 ( V_7 , V_261 , V_223 ) ;
F_110 () ;
if ( V_246 )
return V_246 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_133 = V_133 ;
V_7 -> V_146 = V_133 ;
V_7 -> V_127 = V_127 ;
V_7 -> V_129 = V_129 ;
V_7 -> V_135 = V_135 ;
V_7 -> V_184 = V_184 ;
V_7 -> V_145 = V_145 ;
V_7 -> V_271 = V_248 ;
V_7 -> V_155 = V_249 ;
V_7 -> V_144 = F_35 ( V_144 ) ;
V_7 -> V_162 = V_162 ;
}
return V_223 ;
}
static int F_111 ( struct V_272 * V_272 , struct V_238 * V_238 )
{
return F_112 ( V_238 , & V_273 ) ;
}
static int F_113 ( struct V_272 * V_272 , struct V_238 * V_238 )
{
return 0 ;
}
static int T_1 F_114 ( void )
{
struct V_274 * V_275 ;
if ( ! F_115 () )
return 0 ;
V_275 = F_116 ( V_276 , 0444 , NULL ,
& V_277 ) ;
if ( ! V_275 ) {
F_104 ( V_278 L_31 ,
V_276 ) ;
return - V_3 ;
}
V_279 = F_117 ( V_280 , NULL ) ;
if ( ! V_279 ) {
F_104 ( V_278 L_32 ,
V_280 ) ;
return - V_3 ;
}
V_281 = F_118 ( V_282 , 0600 ,
V_279 , NULL , & V_283 ) ;
if ( ! V_281 ) {
F_104 ( V_278 L_33 ,
V_282 ) ;
return - V_3 ;
}
return 0 ;
}
static void F_119 ( int V_10 , int V_59 , int V_284 )
{
int V_23 ;
int V_5 ;
int V_172 = 0 ;
unsigned long V_285 ;
unsigned long V_286 ;
unsigned long V_287 ;
T_9 V_288 ;
struct V_93 * V_93 ;
struct V_93 * V_289 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
struct V_6 * V_7 ;
V_288 = sizeof( struct V_93 ) * V_290 * V_214 ;
V_93 = F_120 ( V_288 , V_247 , V_10 ) ;
F_121 ( ! V_93 ) ;
V_285 = F_122 ( V_93 ) ;
V_287 = F_123 ( V_285 ) ;
V_286 = F_124 ( V_285 ) ;
if ( F_125 () )
V_172 = 1 ;
F_126 ( V_59 , ( V_287 << V_291 | V_286 ) ) ;
for ( V_23 = 0 , V_289 = V_93 ; V_23 < ( V_290 * V_214 ) ; V_23 ++ , V_289 ++ ) {
memset ( V_289 , 0 , sizeof( struct V_93 ) ) ;
if ( V_172 ) {
V_175 = & V_289 -> V_178 . V_175 ;
V_175 -> V_292 = 1 ;
V_175 -> V_293 =
F_127 ( V_284 ) ;
V_175 -> V_294 = V_295 ;
V_175 -> V_296 = V_297 ;
V_175 -> V_298 = 1 ;
} else {
V_177 = & V_289 -> V_178 . V_177 ;
V_177 -> V_292 = 1 ;
V_177 -> V_293 =
F_127 ( V_284 ) ;
V_177 -> V_294 = V_295 ;
V_177 -> V_296 = V_297 ;
}
}
F_5 (cpu) {
if ( V_59 != F_82 ( F_12 ( V_5 ) ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_213 = V_93 ;
}
}
static void F_128 ( int V_10 , int V_59 )
{
int V_5 ;
T_9 V_299 ;
char * V_300 ;
void * V_301 ;
unsigned long V_302 ;
unsigned long V_303 ;
unsigned long V_304 ;
unsigned long V_305 ;
struct V_17 * V_306 ;
struct V_6 * V_7 ;
V_299 = ( V_32 + 1 ) * sizeof( struct V_17 ) ;
V_301 = F_120 ( V_299 , V_247 , V_10 ) ;
V_306 = (struct V_17 * ) V_301 ;
F_121 ( ! V_306 ) ;
V_300 = ( char * ) V_306 + 31 ;
V_306 = (struct V_17 * ) ( ( ( unsigned long ) V_300 >> 5 ) << 5 ) ;
F_5 (cpu) {
if ( V_59 != F_96 ( V_5 ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_34 = V_306 ;
V_7 -> V_226 = V_306 ;
V_7 -> V_33 = V_306 + ( V_32 - 1 ) ;
}
V_302 = F_123 ( F_122 ( V_306 ) ) ;
V_303 = F_129 ( V_306 ) ;
V_304 = ( ( unsigned long ) V_302 << V_307 ) | V_303 ;
V_305 = F_129 ( V_306 + ( V_32 - 1 ) ) ;
F_130 ( V_59 , V_304 ) ;
F_131 ( V_59 , V_303 ) ;
F_132 ( V_59 , V_305 ) ;
F_133 ( V_59 , 0xffffUL ) ;
memset ( V_306 , 0 , sizeof( struct V_17 ) * V_32 ) ;
}
static void T_1 F_134 ( int V_9 , int V_308 , int V_284 )
{
int V_10 ;
int V_59 ;
unsigned long V_309 ;
V_10 = F_8 ( V_9 ) ;
V_59 = F_82 ( V_9 ) ;
F_119 ( V_10 , V_59 , V_284 ) ;
F_128 ( V_10 , V_59 ) ;
V_309 = F_11 ( V_9 ) | V_310 ;
F_135 ( V_59 , ( ( V_309 << 32 ) | V_308 ) ) ;
}
static int F_136 ( void )
{
unsigned long V_219 ;
int V_311 ;
int V_312 ;
int V_173 ;
int V_313 ;
int V_246 ;
unsigned long V_314 ;
if ( F_125 () ) {
V_311 = V_233 & V_315 ;
V_219 = F_40 ( V_316 ) ;
V_173 = ( V_219 >> V_317 ) & V_318 ;
V_219 = F_40 ( V_319 ) ;
V_312 = ( V_219 >> V_320 ) & V_321 ;
V_314 = V_322 [ V_173 ] ;
V_314 *= ( V_311 * V_312 ) ;
V_246 = V_314 / 1000 ;
} else {
V_219 = F_40 ( V_323 ) ;
V_219 = ( V_219 & V_324 ) >> V_325 ;
if ( V_219 & ( 1L << V_326 ) )
V_313 = 80 ;
else
V_313 = 10 ;
V_311 = V_219 & V_327 ;
V_246 = V_311 * V_313 ;
}
return V_246 ;
}
static void T_1 F_137 ( void )
{
int V_5 ;
struct V_6 * V_7 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_141 = 0 ;
if ( V_4 )
V_7 -> V_4 = true ;
V_7 -> V_30 = & F_6 ( V_258 , V_5 ) ;
V_7 -> V_123 = F_36 ( 2 * V_103 ) ;
V_7 -> V_133 = V_133 ;
V_7 -> V_146 = V_133 ;
V_7 -> V_127 = V_127 ;
V_7 -> V_129 = V_129 ;
V_7 -> V_135 = V_135 ;
V_7 -> V_184 = V_184 ;
V_7 -> V_145 = V_145 ;
V_7 -> V_271 = V_248 ;
V_7 -> V_155 = V_249 ;
V_7 -> V_144 = F_35 ( V_144 ) ;
V_7 -> V_162 = V_162 ;
F_138 ( & V_7 -> V_130 ) ;
F_138 ( & V_7 -> V_165 ) ;
F_138 ( & V_7 -> V_140 ) ;
}
}
static int T_1 F_139 ( int V_284 ,
struct V_328 * V_329 ,
unsigned char * V_330 )
{
int V_5 ;
int V_59 ;
int V_9 ;
int V_331 ;
struct V_6 * V_7 ;
struct V_328 * V_332 ;
struct V_333 * V_334 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_59 = F_140 ( V_5 ) -> V_59 ;
if ( ( V_59 - V_284 ) >= V_215 ) {
F_104 ( V_335
L_34 ,
V_5 , V_59 , V_284 , V_215 ) ;
return 1 ;
}
V_7 -> V_336 = F_141 ( V_5 ) ;
V_7 -> V_76 = V_284 ;
V_9 = F_140 ( V_5 ) -> V_337 ;
* ( V_330 + ( V_9 / 8 ) ) |= ( 1 << ( V_9 % 8 ) ) ;
V_332 = & V_329 [ V_9 ] ;
V_332 -> V_338 ++ ;
V_332 -> V_9 = V_9 ;
V_332 -> V_59 = V_59 ;
V_331 = V_7 -> V_336 & 1 ;
V_332 -> V_339 |= ( 1 << V_331 ) ;
V_334 = & V_332 -> V_331 [ V_331 ] ;
V_334 -> V_340 [ V_334 -> V_338 ] = V_5 ;
V_334 -> V_338 ++ ;
if ( V_334 -> V_338 > V_341 ) {
F_104 ( V_335 L_35 ,
V_334 -> V_338 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_142 ( struct V_6 * V_44 )
{
int V_5 ;
T_9 V_342 = sizeof( struct V_60 ) * F_88 () ;
V_44 -> V_62 = F_120 ( V_342 , V_247 , V_44 -> V_336 ) ;
memset ( V_44 -> V_62 , 0 , V_342 ) ;
F_5 (cpu) {
V_44 -> V_62 [ V_5 ] . V_59 = F_140 ( V_5 ) -> V_59 ;
V_44 -> V_62 [ V_5 ] . V_9 = F_140 ( V_5 ) -> V_337 ;
}
}
static void F_143 ( struct V_6 * V_87 )
{
int V_343 = sizeof( T_2 ) ;
V_87 -> V_74 = F_144 ( V_343 , V_247 , V_87 -> V_336 ) ;
}
static int F_145 ( struct V_333 * V_334 , struct V_328 * V_332 ,
struct V_6 * * V_344 ,
struct V_6 * * V_345 )
{
int V_23 ;
int V_5 ;
struct V_6 * V_7 ;
for ( V_23 = 0 ; V_23 < V_334 -> V_338 ; V_23 ++ ) {
V_5 = V_334 -> V_340 [ V_23 ] ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_5 = V_5 ;
if ( V_23 == 0 ) {
* V_344 = V_7 ;
if ( ! ( * V_345 ) )
* V_345 = V_7 ;
}
V_7 -> V_58 = V_332 -> V_338 ;
V_7 -> V_55 = V_334 -> V_338 ;
V_7 -> V_45 = * V_344 ;
V_7 -> V_9 = V_332 -> V_9 ;
if ( F_125 () )
V_7 -> V_126 = 1 ;
else if ( F_85 () )
V_7 -> V_126 = 2 ;
else if ( F_86 () )
V_7 -> V_126 = 3 ;
else {
F_104 ( V_335 L_36 ) ;
return 1 ;
}
V_7 -> V_52 = * V_345 ;
V_7 -> V_111 = F_146 ( V_5 ) ;
if ( V_7 -> V_111 >= V_346 ) {
F_104 ( V_335 L_37 ,
V_7 -> V_111 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_147 ( int V_230 ,
struct V_328 * V_329 ,
unsigned char * V_330 )
{
int V_331 ;
int V_9 ;
unsigned short V_339 ;
for ( V_9 = 0 ; V_9 < V_230 ; V_9 ++ ) {
struct V_328 * V_332 ;
struct V_6 * V_44 = NULL ;
struct V_6 * V_87 = NULL ;
if ( ! ( * ( V_330 + ( V_9 / 8 ) ) & ( 1 << ( V_9 % 8 ) ) ) )
continue;
V_332 = & V_329 [ V_9 ] ;
V_339 = V_332 -> V_339 ;
V_331 = 0 ;
while ( V_339 ) {
struct V_333 * V_334 ;
if ( ( V_339 & 1 ) ) {
V_334 = & V_332 -> V_331 [ V_331 ] ;
if ( F_145 ( V_334 , V_332 , & V_44 , & V_87 ) )
return 1 ;
F_142 ( V_44 ) ;
}
V_331 ++ ;
V_339 = ( V_339 >> 1 ) ;
}
F_143 ( V_87 ) ;
}
return 0 ;
}
static int T_1 F_148 ( int V_230 , int V_347 )
{
unsigned char * V_330 ;
void * V_301 ;
struct V_328 * V_329 ;
V_103 = F_136 () ;
V_301 = F_149 ( V_230 * sizeof( struct V_328 ) , V_247 ) ;
V_329 = (struct V_328 * ) V_301 ;
memset ( V_329 , 0 , V_230 * sizeof( struct V_328 ) ) ;
V_330 = F_150 ( ( V_230 + 7 ) / 8 , V_247 ) ;
if ( F_139 ( V_347 , V_329 , V_330 ) )
goto V_348;
if ( F_147 ( V_230 , V_329 , V_330 ) )
goto V_348;
F_100 ( V_329 ) ;
F_100 ( V_330 ) ;
F_137 () ;
return 0 ;
V_348:
F_100 ( V_329 ) ;
F_100 ( V_330 ) ;
return 1 ;
}
static int T_1 F_151 ( void )
{
int V_9 ;
int V_59 ;
int V_230 ;
int V_349 ;
int V_350 ;
int V_308 ;
T_10 * V_73 ;
if ( ! F_115 () )
return 0 ;
F_152 (cur_cpu) {
V_73 = & F_6 ( V_211 , V_349 ) ;
F_153 ( V_73 , V_247 , F_141 ( V_349 ) ) ;
}
V_230 = F_80 () ;
V_154 = F_36 ( V_248 ) ;
V_351 = 0x7fffffff ;
for ( V_9 = 0 ; V_9 < V_230 ; V_9 ++ ) {
V_350 = F_81 ( V_9 ) ;
if ( V_350 && ( F_82 ( V_9 ) < V_351 ) )
V_351 = F_82 ( V_9 ) ;
}
F_79 () ;
if ( F_148 ( V_230 , V_351 ) ) {
F_7 () ;
V_8 = 1 ;
return 0 ;
}
V_308 = V_352 ;
F_154 (uvhub) {
if ( F_81 ( V_9 ) )
F_134 ( V_9 , V_308 , V_351 ) ;
}
F_155 ( V_308 , V_353 ) ;
F_154 (uvhub) {
if ( F_81 ( V_9 ) ) {
unsigned long V_260 ;
unsigned long V_26 ;
V_59 = F_82 ( V_9 ) ;
V_260 = 1L << 63 ;
F_156 ( V_59 , V_260 ) ;
V_26 = 1 ;
if ( ! F_125 () )
F_157 ( V_59 , V_26 ) ;
}
}
return 0 ;
}
