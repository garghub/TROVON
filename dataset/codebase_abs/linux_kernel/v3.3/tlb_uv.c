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
static void F_9 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 )
{
unsigned long V_13 ;
struct V_14 * V_15 ;
V_15 = V_9 -> V_15 ;
if ( ! V_15 -> V_16 && V_12 ) {
V_13 = ( V_15 -> V_17 << V_18 ) | V_15 -> V_17 ;
F_10 ( V_13 ) ;
}
V_15 -> V_19 = 1 ;
V_15 -> V_17 = 0 ;
}
static void F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
int V_20 ;
int V_21 = 0 ;
unsigned long V_22 ;
unsigned long V_23 = 0 ;
struct V_14 * V_15 = V_9 -> V_15 ;
struct V_14 * V_24 ;
struct V_25 * V_26 = V_11 -> V_27 ;
V_26 -> V_28 ++ ;
for ( V_24 = V_15 + 1 , V_20 = 0 ; V_20 < V_29 ; V_24 ++ , V_20 ++ ) {
if ( V_24 > V_9 -> V_30 )
V_24 = V_9 -> V_31 ;
if ( V_24 == V_15 )
break;
if ( ( V_24 -> V_19 == 0 ) && ( V_24 -> V_16 == 0 ) &&
( V_24 -> V_17 ) && ( ( V_24 -> V_17 &
V_15 -> V_17 ) == 0 ) &&
( V_24 -> V_32 == V_15 -> V_32 ) &&
( V_24 -> V_33 != V_34 ) ) {
V_23 = F_12 () ;
V_22 = V_24 -> V_17 ;
if ( V_23 & ( V_22 << V_18 ) ) {
unsigned long V_35 ;
V_24 -> V_16 = 1 ;
V_26 -> V_36 ++ ;
V_21 ++ ;
V_35 = ( V_22 << V_18 ) | V_22 ;
F_10 ( V_35 ) ;
}
}
}
if ( ! V_21 )
V_26 -> V_37 ++ ;
}
static void F_13 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 )
{
short V_38 = 0 ;
short * V_39 ;
struct atomic_short * V_40 ;
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_14 * V_15 = V_9 -> V_15 ;
struct V_10 * V_41 = V_11 -> V_42 ;
if ( V_15 -> V_43 == V_44 ) {
F_14 () ;
V_26 -> V_45 ++ ;
} else {
F_15 ( V_15 -> V_43 ) ;
V_26 -> V_46 ++ ;
}
V_26 -> V_47 ++ ;
if ( V_15 -> V_33 == V_48 && V_11 == V_11 -> V_49 )
F_11 ( V_9 , V_11 ) ;
V_39 = & V_41 -> V_50 [ V_9 -> V_51 ] ;
V_40 = (struct atomic_short * ) V_39 ;
V_38 = F_16 ( 1 , V_40 ) ;
if ( V_38 == V_11 -> V_52 ) {
int V_53 ;
V_41 -> V_50 [ V_9 -> V_51 ] = 0 ;
V_40 = (struct atomic_short * ) & V_15 -> V_54 ;
V_53 = F_16 ( V_38 , V_40 ) ;
if ( V_53 == V_11 -> V_55 ) {
F_9 ( V_9 , V_11 , V_12 ) ;
}
}
return;
}
static int F_17 ( int V_56 , struct V_10 * V_41 )
{
int V_6 ;
struct V_57 * V_58 ;
F_6 (cpu) {
V_58 = & V_41 -> V_59 [ V_6 ] ;
if ( V_56 == V_58 -> V_56 )
return V_6 ;
}
return - 1 ;
}
static void F_18 ( void * V_60 )
{
int V_20 ;
struct V_10 * V_11 = & F_8 ( V_10 , F_19 () ) ;
struct V_61 * V_62 = (struct V_61 * ) V_60 ;
struct V_14 * V_15 ;
struct V_25 * V_26 = V_11 -> V_27 ;
V_26 -> V_63 ++ ;
for ( V_15 = V_11 -> V_31 , V_20 = 0 ; V_20 < V_29 ; V_15 ++ , V_20 ++ ) {
unsigned long V_22 ;
if ( ( V_15 -> V_19 == 0 ) &&
( V_15 -> V_16 == 0 ) &&
( V_15 -> V_32 == V_62 -> V_64 ) &&
( V_15 -> V_17 ) &&
( V_15 -> V_33 != V_34 ) ) {
unsigned long V_23 ;
unsigned long V_35 ;
V_15 -> V_16 = 1 ;
V_23 = F_12 () ;
V_22 = V_15 -> V_17 ;
V_35 = ( V_22 << V_18 ) | V_22 ;
if ( V_23 & V_22 ) {
V_26 -> V_65 ++ ;
F_10 ( V_35 ) ;
}
}
}
return;
}
static void F_20 ( struct V_66 * V_67 , struct V_10 * V_11 )
{
int V_56 ;
int V_68 ;
int V_69 ;
int V_64 = V_11 -> V_6 ;
T_2 * V_70 = V_11 -> V_49 -> V_71 ;
struct V_10 * V_41 = V_11 -> V_42 ;
struct V_61 V_61 ;
V_61 . V_64 = V_64 ;
F_21 ( * V_70 ) ;
V_69 = sizeof( struct V_66 ) * V_72 ;
for ( V_56 = 0 ; V_56 < V_69 ; V_56 ++ ) {
int V_6 ;
if ( ! F_22 ( V_56 , V_67 ) )
continue;
V_68 = V_56 + V_11 -> V_73 ;
V_6 = F_17 ( V_68 , V_41 ) ;
F_23 ( V_6 , * V_70 ) ;
}
F_24 ( V_70 , F_18 , ( void * ) & V_61 , 1 ) ;
return;
}
static inline unsigned long F_25 ( unsigned long long V_74 )
{
unsigned long long V_75 ;
unsigned long V_76 ;
int V_6 = F_19 () ;
V_75 = ( V_74 * F_8 ( V_77 , V_6 ) ) >> V_78 ;
V_76 = V_75 / 1000 ;
return V_76 ;
}
static inline void F_26 ( struct V_10 * V_79 )
{
F_16 ( 1 , (struct atomic_short * ) & V_79 -> V_80 ) ;
}
static inline void F_27 ( struct V_10 * V_79 )
{
F_16 ( - 1 , (struct atomic_short * ) & V_79 -> V_80 ) ;
}
static unsigned long F_28 ( unsigned long V_81 , int V_82 )
{
unsigned long V_83 ;
V_83 = F_29 ( V_81 ) ;
V_83 >>= V_82 ;
V_83 &= V_84 ;
return V_83 ;
}
static int F_30 ( struct V_85 * V_85 ,
unsigned long V_81 , int V_82 ,
struct V_10 * V_11 , long V_86 )
{
unsigned long V_83 ;
T_3 V_87 ;
struct V_25 * V_26 = V_11 -> V_27 ;
V_83 = F_28 ( V_81 , V_82 ) ;
while ( ( V_83 != V_88 ) ) {
if ( V_83 == V_89 ) {
V_26 -> V_90 ++ ;
return V_91 ;
} else if ( V_83 == V_92 ) {
V_26 -> V_93 ++ ;
V_87 = F_31 () ;
if ( F_25 ( V_87 - V_11 -> V_94 ) < V_95 ) {
V_11 -> V_96 = 0 ;
return V_97 ;
}
V_11 -> V_96 = 0 ;
return V_98 ;
} else {
F_32 () ;
}
V_83 = F_28 ( V_81 , V_82 ) ;
}
V_11 -> V_96 ++ ;
return V_99 ;
}
static unsigned long F_33 ( unsigned long V_100 , int V_101 , int V_102 )
{
unsigned long V_83 ;
unsigned long V_103 ;
V_83 = ( ( F_34 ( V_100 ) >> V_101 ) & V_84 ) ;
V_103 = ( F_35 () >> V_102 ) & 0x1UL ;
V_83 = ( V_83 << 1 ) | V_103 ;
return V_83 ;
}
int F_36 ( struct V_10 * V_11 )
{
int V_6 = V_11 -> V_104 ;
int V_81 ;
int V_82 ;
V_81 = V_105 ;
V_82 = V_6 * V_106 ;
return ( ( ( ( ( F_34 ( V_81 ) >> V_82 ) &
V_84 ) ) << 1 ) == V_107 ) ;
}
int F_37 ( struct V_10 * V_11 )
{
int V_108 = V_11 -> V_109 ;
int V_110 = V_11 -> V_104 ;
int V_111 = - 1 ;
int V_20 ;
unsigned long V_83 ;
unsigned long V_112 ;
int V_81 ;
struct V_85 * V_113 ;
struct V_85 * V_114 ;
struct V_10 * V_79 = V_11 -> V_49 ;
struct V_25 * V_26 = V_11 -> V_27 ;
T_3 V_87 ;
V_26 -> V_115 ++ ;
F_38 ( & V_79 -> V_116 ) ;
if ( V_108 != V_110 ) {
if ( ! F_36 ( V_11 ) )
V_111 = V_110 ;
}
if ( V_111 < 0 ) {
V_81 = V_117 ;
V_83 = F_34 ( V_81 ) ;
for ( V_20 = 0 ; V_20 < V_118 ; V_20 ++ ) {
if ( ( V_79 -> V_119 & ( 1 << V_20 ) ) == 0 ) {
V_112 = ( ( V_83 >>
( V_20 * V_106 ) ) &
V_84 ) << 1 ;
if ( V_112 != V_107 ) {
V_111 = V_20 + V_118 ;
break;
}
}
}
}
if ( V_108 != V_110 )
V_79 -> V_119 &= ~ ( 1 << ( V_108 - V_118 ) ) ;
if ( V_111 >= 0 ) {
if ( V_111 != V_110 ) {
V_79 -> V_119 |=
( 1 << ( V_111 - V_118 ) ) ;
if ( V_111 > V_26 -> V_120 )
V_26 -> V_120 = V_111 ;
}
V_113 = V_11 -> V_121 ;
V_113 += ( V_122 * V_108 ) ;
V_11 -> V_109 = V_111 ;
V_114 = V_11 -> V_121 ;
V_114 += ( V_122 * V_111 ) ;
* V_114 = * V_113 ;
} else {
V_26 -> V_123 ++ ;
F_39 ( & V_79 -> V_116 ) ;
V_87 = F_31 () ;
do {
F_32 () ;
} while ( F_36 ( V_11 ) );
F_38 ( & V_79 -> V_116 ) ;
V_11 -> V_109 = V_110 ;
V_113 = V_11 -> V_121 ;
V_113 += ( V_122 * V_11 -> V_109 ) ;
V_11 -> V_109 = ( V_122 * V_110 ) ;
V_114 = V_11 -> V_121 ;
V_114 += ( V_122 * V_110 ) ;
* V_114 = * V_113 ;
}
F_39 ( & V_79 -> V_116 ) ;
return V_124 ;
}
static int F_40 ( struct V_85 * V_85 ,
unsigned long V_81 , int V_82 ,
struct V_10 * V_11 , long V_86 )
{
unsigned long V_125 ;
T_3 V_87 ;
int V_102 = V_11 -> V_109 ;
long V_126 = 0 ;
struct V_25 * V_26 = V_11 -> V_27 ;
V_125 = F_33 ( V_81 , V_82 , V_102 ) ;
while ( V_125 != V_127 ) {
if ( ( V_125 == V_128 ) ||
( V_125 == V_129 ) ) {
V_26 -> V_90 ++ ;
return V_91 ;
} else if ( V_125 == V_130 ) {
V_26 -> V_131 ++ ;
V_11 -> V_96 = 0 ;
return V_91 ;
} else if ( V_125 == V_132 ) {
V_26 -> V_93 ++ ;
V_11 -> V_96 = 0 ;
return V_98 ;
} else {
V_126 ++ ;
if ( V_126 > 1000000 ) {
V_126 = 0 ;
V_87 = F_31 () ;
if ( ( V_87 - V_11 -> V_94 ) >
( V_11 -> V_133 ) ) {
return F_37 ( V_11 ) ;
}
}
F_32 () ;
}
V_125 = F_33 ( V_81 , V_82 ,
V_102 ) ;
}
V_11 -> V_96 ++ ;
return V_99 ;
}
static int F_41 ( struct V_85 * V_85 ,
struct V_10 * V_11 , long V_86 )
{
int V_82 ;
unsigned long V_81 ;
int V_102 = V_11 -> V_109 ;
if ( V_102 < V_118 ) {
V_81 = V_105 ;
V_82 = V_102 * V_106 ;
} else {
V_81 = V_117 ;
V_82 = ( ( V_102 - V_118 ) * V_106 ) ;
}
if ( V_11 -> V_134 == 1 )
return F_30 ( V_85 , V_81 , V_82 ,
V_11 , V_86 ) ;
else
return F_40 ( V_85 , V_81 , V_82 ,
V_11 , V_86 ) ;
}
static inline T_3 F_42 ( unsigned long V_135 )
{
unsigned long V_75 ;
T_3 V_74 ;
V_75 = V_135 * 1000000000 ;
V_74 = ( V_75 << V_78 ) / ( F_8 ( V_77 , F_19 () ) ) ;
return V_74 ;
}
static void F_43 ( struct V_85 * V_85 ,
struct V_10 * V_11 ,
struct V_10 * V_79 , struct V_25 * V_26 )
{
F_44 ( V_11 -> V_136 ) ;
V_11 -> V_137 ++ ;
if ( V_11 -> V_137 >= V_11 -> V_138 ) {
V_11 -> V_137 = 0 ;
F_26 ( V_79 ) ;
F_38 ( & V_79 -> V_139 ) ;
F_20 ( & V_85 -> V_67 , V_11 ) ;
F_39 ( & V_79 -> V_139 ) ;
F_27 ( V_79 ) ;
V_11 -> V_140 ++ ;
V_26 -> V_141 ++ ;
}
}
static void F_45 ( struct V_85 * V_85 ,
struct V_10 * V_11 , struct V_10 * V_79 ,
struct V_25 * V_26 )
{
V_79 -> V_142 = 1 ;
V_11 -> V_143 ++ ;
if ( V_11 -> V_143 >= V_11 -> V_144 ) {
V_11 -> V_143 = 0 ;
F_26 ( V_79 ) ;
F_38 ( & V_79 -> V_139 ) ;
F_20 ( & V_85 -> V_67 , V_11 ) ;
F_39 ( & V_79 -> V_139 ) ;
F_27 ( V_79 ) ;
V_11 -> V_140 ++ ;
V_26 -> V_145 ++ ;
}
}
static void F_46 ( struct V_10 * V_11 ,
struct V_25 * V_26 )
{
F_38 ( & V_146 ) ;
if ( ! V_147 && V_11 -> V_148 &&
( ( V_11 -> V_149 / V_11 -> V_148 ) > V_150 ) ) {
int V_151 ;
struct V_10 * V_152 ;
V_147 = 1 ;
V_11 -> V_153 = 1 ;
V_11 -> V_154 = F_31 () ;
V_11 -> V_154 += F_42 ( V_11 -> V_155 ) ;
V_26 -> V_156 ++ ;
F_6 (tcpu) {
V_152 = & F_8 ( V_10 , V_151 ) ;
V_152 -> V_147 = 1 ;
}
}
F_39 ( & V_146 ) ;
}
static void F_47 ( int V_26 , struct V_10 * V_11 ,
struct V_10 * V_79 )
{
V_11 -> V_137 = 0 ;
V_11 -> V_143 = 0 ;
if ( V_26 != V_99 )
return;
if ( V_11 -> V_96 <= V_11 -> V_157 )
return;
if ( V_79 -> V_142 >= V_79 -> V_158 )
return;
V_79 -> V_142 ++ ;
}
static void F_48 ( T_3 V_159 , T_3 V_160 ,
struct V_10 * V_11 , struct V_25 * V_26 ,
int V_161 , int V_86 )
{
T_3 V_162 ;
if ( V_160 > V_159 ) {
V_162 = V_160 - V_159 ;
V_26 -> V_163 += V_162 ;
if ( ( V_161 == V_99 ) && ( V_86 == 1 ) ) {
V_11 -> V_148 ++ ;
V_11 -> V_149 += V_162 ;
if ( ( V_162 > V_150 ) &&
( V_11 -> V_148 > V_11 -> V_164 ) )
F_46 ( V_11 , V_26 ) ;
}
} else
V_26 -> V_165 -- ;
if ( V_161 == V_99 && V_86 > 1 )
V_26 -> V_166 ++ ;
else if ( V_161 == V_91 )
V_26 -> V_167 ++ ;
}
static void F_49 ( struct V_10 * V_79 , struct V_25 * V_26 )
{
T_4 * V_168 = & V_79 -> V_116 ;
T_5 * V_169 ;
V_169 = & V_79 -> V_170 ;
if ( ! F_50 ( V_168 , V_169 , V_79 -> V_142 ) ) {
V_26 -> V_171 ++ ;
do {
F_32 () ;
} while ( ! F_50 ( V_168 , V_169 , V_79 -> V_142 ) );
}
}
static void F_51 ( int V_161 , struct V_85 * V_85 ,
struct V_10 * V_11 , struct V_10 * V_79 ,
struct V_25 * V_26 )
{
if ( V_161 == V_97 )
F_43 ( V_85 , V_11 , V_79 , V_26 ) ;
else if ( V_161 == V_98 )
F_45 ( V_85 , V_11 , V_79 , V_26 ) ;
}
int F_52 ( struct V_71 * V_172 , struct V_10 * V_11 )
{
int V_173 = 0 ;
int V_174 = 0 ;
int V_175 = 0 ;
long V_86 = 0 ;
unsigned long V_176 ;
T_3 V_159 ;
T_3 V_160 ;
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_10 * V_79 = V_11 -> V_49 ;
struct V_177 * V_178 = NULL ;
struct V_179 * V_180 = NULL ;
struct V_85 * V_85 ;
if ( V_11 -> V_134 == 1 )
F_49 ( V_79 , V_26 ) ;
while ( V_79 -> V_80 )
F_32 () ;
V_159 = F_31 () ;
do {
V_85 = V_11 -> V_121 ;
V_85 += ( V_122 * V_11 -> V_109 ) ;
if ( V_11 -> V_134 == 1 ) {
V_175 = 1 ;
V_178 = & V_85 -> V_181 . V_178 ;
} else
V_180 = & V_85 -> V_181 . V_180 ;
if ( ( V_86 == 0 ) || ( V_174 == V_124 ) ) {
if ( V_175 )
V_178 -> V_33 = V_182 ;
else
V_180 -> V_33 = V_182 ;
V_173 = V_11 -> V_183 ++ ;
} else {
if ( V_175 )
V_178 -> V_33 = V_48 ;
else
V_180 -> V_33 = V_48 ;
V_26 -> V_184 ++ ;
}
if ( V_175 )
V_178 -> V_185 = V_173 ;
else
V_180 -> V_185 = V_173 ;
V_176 = ( 1UL << V_186 ) | V_11 -> V_109 ;
V_11 -> V_94 = F_31 () ;
F_53 ( V_176 ) ;
V_86 ++ ;
V_174 = F_41 ( V_85 , V_11 , V_86 ) ;
F_51 ( V_174 , V_85 , V_11 , V_79 , V_26 ) ;
if ( V_11 -> V_140 >= V_11 -> V_187 ) {
V_11 -> V_140 = 0 ;
V_174 = V_91 ;
break;
}
F_32 () ;
} while ( ( V_174 == V_97 ) ||
( V_174 == V_124 ) ||
( V_174 == V_98 ) );
V_160 = F_31 () ;
F_47 ( V_174 , V_11 , V_79 ) ;
while ( V_79 -> V_80 )
F_32 () ;
F_54 ( & V_79 -> V_170 ) ;
F_48 ( V_159 , V_160 , V_11 , V_26 , V_174 , V_86 ) ;
if ( V_174 == V_91 )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_10 * V_11 , struct V_25 * V_26 )
{
int V_151 ;
struct V_10 * V_152 ;
if ( V_11 -> V_153 ) {
if ( F_31 () >= V_11 -> V_154 ) {
V_26 -> V_188 ++ ;
V_147 = 0 ;
F_6 (tcpu) {
V_152 = & F_8 ( V_10 , V_151 ) ;
V_152 -> V_147 = 0 ;
V_152 -> V_148 = 0 ;
V_152 -> V_149 = 0 ;
}
return 0 ;
}
}
return - 1 ;
}
static void F_56 ( struct V_25 * V_26 , int V_189 , int V_190 ,
int V_191 , struct V_85 * V_85 )
{
V_26 -> V_165 ++ ;
V_26 -> V_192 += V_191 + V_189 ;
V_26 -> V_193 += V_191 ;
V_26 -> V_194 += V_189 ;
V_190 = F_57 ( & V_85 -> V_67 ) ;
if ( V_189 ) {
V_26 -> V_195 ++ ;
V_26 -> V_196 += ( V_190 - 1 ) ;
} else
V_26 -> V_196 += V_190 ;
V_26 -> V_197 += V_190 ;
if ( V_190 >= 16 )
V_26 -> V_198 ++ ;
else if ( V_190 >= 8 )
V_26 -> V_199 ++ ;
else if ( V_190 >= 4 )
V_26 -> V_200 ++ ;
else if ( V_190 >= 2 )
V_26 -> V_201 ++ ;
else
V_26 -> V_202 ++ ;
}
static int F_58 ( struct V_71 * V_172 , struct V_10 * V_11 ,
struct V_85 * V_85 , int * V_203 , int * V_204 )
{
int V_6 ;
int V_56 ;
int V_205 = 0 ;
struct V_57 * V_58 ;
F_59 (cpu, flush_mask) {
V_58 = & V_11 -> V_42 -> V_59 [ V_6 ] ;
V_56 = V_58 -> V_56 - V_11 -> V_73 ;
F_60 ( V_56 , & V_85 -> V_67 ) ;
V_205 ++ ;
if ( V_58 -> V_3 == V_11 -> V_3 )
( * V_203 ) ++ ;
else
( * V_204 ) ++ ;
}
if ( ! V_205 )
return 1 ;
return 0 ;
}
const struct V_71 * F_61 ( const struct V_71 * V_71 ,
struct V_206 * V_207 , unsigned long V_208 ,
unsigned int V_6 )
{
int V_189 = 0 ;
int V_191 = 0 ;
int V_190 = 0 ;
struct V_85 * V_85 ;
struct V_71 * V_172 ;
struct V_25 * V_26 ;
struct V_10 * V_11 ;
if ( V_2 )
return V_71 ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_26 = V_11 -> V_27 ;
if ( V_11 -> V_147 ) {
if ( F_55 ( V_11 , V_26 ) )
return V_71 ;
}
V_172 = (struct V_71 * ) F_8 ( V_209 , V_6 ) ;
F_62 ( V_172 , V_71 , F_63 ( V_6 ) ) ;
if ( F_64 ( V_6 , * V_71 ) )
V_26 -> V_210 ++ ;
V_85 = V_11 -> V_121 ;
V_85 += ( V_122 * V_11 -> V_109 ) ;
F_65 ( & V_85 -> V_67 , V_211 ) ;
if ( F_58 ( V_172 , V_11 , V_85 , & V_189 , & V_191 ) )
return NULL ;
F_56 ( V_26 , V_189 , V_190 , V_191 , V_85 ) ;
V_85 -> V_212 . V_43 = V_208 ;
V_85 -> V_212 . V_32 = V_6 ;
if ( ! F_52 ( V_172 , V_11 ) )
return NULL ;
else
return V_71 ;
}
struct V_14 * F_66 ( struct V_14 * V_15 ,
struct V_10 * V_11 , unsigned char V_17 )
{
struct V_14 * V_213 = V_15 + 1 ;
if ( V_213 > V_11 -> V_30 )
V_213 = V_11 -> V_31 ;
while ( ( V_213 -> V_17 != 0 ) && ( V_213 != V_15 ) ) {
if ( V_213 -> V_17 == V_17 )
return V_213 ;
V_213 ++ ;
if ( V_213 > V_11 -> V_30 )
V_213 = V_11 -> V_31 ;
}
return NULL ;
}
void F_67 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
unsigned long V_214 ;
unsigned char V_17 ;
struct V_14 * V_15 = V_9 -> V_15 ;
struct V_14 * V_215 ;
V_214 = F_12 () ;
V_17 = V_15 -> V_17 ;
if ( ( V_17 & V_214 ) == 0 ) {
F_13 ( V_9 , V_11 , 0 ) ;
return;
}
V_215 = F_66 ( V_15 , V_11 , V_15 -> V_17 ) ;
if ( V_215 ) {
F_13 ( V_9 , V_11 , 0 ) ;
return;
}
F_13 ( V_9 , V_11 , 1 ) ;
return;
}
void F_68 ( struct V_216 * V_217 )
{
int V_218 = 0 ;
T_3 V_219 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
struct V_25 * V_26 ;
struct V_8 V_220 ;
F_69 () ;
V_219 = F_31 () ;
V_11 = & F_8 ( V_10 , F_19 () ) ;
V_26 = V_11 -> V_27 ;
V_220 . V_31 = V_11 -> V_31 ;
V_220 . V_30 = V_11 -> V_30 ;
V_15 = V_11 -> V_221 ;
while ( V_15 -> V_17 ) {
V_218 ++ ;
V_220 . V_51 = V_15 - V_220 . V_31 ;
V_220 . V_15 = V_15 ;
if ( V_11 -> V_134 == 2 )
F_67 ( & V_220 , V_11 ) ;
else
F_13 ( & V_220 , V_11 , 1 ) ;
V_15 ++ ;
if ( V_15 > V_220 . V_30 )
V_15 = V_220 . V_31 ;
V_11 -> V_221 = V_15 ;
}
V_26 -> V_222 += ( F_31 () - V_219 ) ;
if ( ! V_218 )
V_26 -> V_223 ++ ;
else if ( V_218 > 1 )
V_26 -> V_224 ++ ;
}
static void T_1 F_70 ( void )
{
int V_3 ;
int V_225 ;
int V_56 ;
unsigned long V_214 ;
V_225 = F_71 () ;
for ( V_3 = 0 ; V_3 < V_225 ; V_3 ++ ) {
if ( ! F_72 ( V_3 ) )
continue;
V_56 = F_73 ( V_3 ) ;
V_214 = F_74 ( V_56 ) ;
V_214 &= ~ ( 1L << V_226 ) ;
F_75 ( V_56 , V_214 ) ;
V_214 &= ~ ( ( unsigned long ) 0xf << V_227 ) ;
V_214 |= ( V_228 << V_227 ) ;
F_75 ( V_56 , V_214 ) ;
V_214 |= ( 1L << V_226 ) ;
if ( F_76 () ) {
V_214 &= ~ ( 1L << V_229 ) ;
V_214 |= ( 1L << V_230 ) ;
}
F_75 ( V_56 , V_214 ) ;
}
}
static void * F_77 ( struct V_231 * V_232 , T_6 * V_100 )
{
if ( * V_100 < F_78 () )
return V_100 ;
return NULL ;
}
static void * F_79 ( struct V_231 * V_232 , void * V_233 , T_6 * V_100 )
{
( * V_100 ) ++ ;
if ( * V_100 < F_78 () )
return V_100 ;
return NULL ;
}
static void F_80 ( struct V_231 * V_232 , void * V_233 )
{
}
static inline unsigned long long F_81 ( unsigned long V_234 )
{
unsigned long V_75 ;
unsigned long long V_74 ;
V_75 = V_234 * 1000 ;
V_74 = ( V_75 << V_78 ) / ( F_8 ( V_77 , F_19 () ) ) ;
return V_74 ;
}
static int F_82 ( struct V_231 * V_232 , void * V_233 )
{
struct V_25 * V_26 ;
int V_6 ;
V_6 = * ( T_6 * ) V_233 ;
if ( ! V_6 ) {
F_83 ( V_232 ,
L_1 ) ;
F_83 ( V_232 ,
L_2 ) ;
F_83 ( V_232 ,
L_3 ) ;
F_83 ( V_232 ,
L_4 ) ;
F_83 ( V_232 ,
L_5 ) ;
F_83 ( V_232 ,
L_6 ) ;
}
if ( V_6 < F_78 () && F_84 ( V_6 ) ) {
V_26 = & F_8 ( V_235 , V_6 ) ;
F_83 ( V_232 ,
L_7 ,
V_6 , V_26 -> V_165 , F_25 ( V_26 -> V_163 ) ,
V_26 -> V_210 , V_26 -> V_194 ,
V_26 -> V_193 , V_26 -> V_192 ,
V_26 -> V_195 , V_26 -> V_196 ,
V_26 -> V_197 , V_26 -> V_198 ) ;
F_83 ( V_232 , L_8 ,
V_26 -> V_199 , V_26 -> V_200 ,
V_26 -> V_201 , V_26 -> V_202 ,
V_26 -> V_93 , V_26 -> V_131 ) ;
F_83 ( V_232 , L_9 ,
V_26 -> V_184 , V_26 -> V_166 ,
V_26 -> V_141 , V_26 -> V_145 ,
V_26 -> V_167 , V_26 -> V_90 ,
V_26 -> V_236 , V_26 -> V_171 ) ;
F_83 ( V_232 ,
L_10 ,
F_85 ( F_86 ( V_6 ) ) ,
V_26 -> V_47 , F_25 ( V_26 -> V_222 ) ,
V_26 -> V_45 , V_26 -> V_46 , V_26 -> V_224 ,
V_26 -> V_223 , V_26 -> V_28 , V_26 -> V_36 ,
V_26 -> V_37 , V_26 -> V_63 ,
V_26 -> V_65 ) ;
F_83 ( V_232 , L_11 ,
V_26 -> V_156 , V_26 -> V_188 ,
V_26 -> V_115 , V_26 -> V_120 ,
V_26 -> V_123 ) ;
}
return 0 ;
}
static T_7 F_87 ( struct V_232 * V_232 , char T_8 * V_237 ,
T_9 V_218 , T_6 * V_238 )
{
char * V_239 ;
int V_240 ;
V_239 = F_88 ( V_241 , L_12 ,
L_13 ,
L_14 ,
L_15 ,
V_142 , V_136 , V_138 ,
V_144 , V_187 , V_157 ,
V_242 , V_243 , V_244 ) ;
if ( ! V_239 )
return - V_245 ;
V_240 = F_89 ( V_237 , V_218 , V_238 , V_239 , strlen ( V_239 ) ) ;
F_90 ( V_239 ) ;
return V_240 ;
}
static T_7 F_91 ( struct V_232 * V_232 , const char T_8 * V_246 ,
T_9 V_218 , T_6 * V_233 )
{
int V_6 ;
int V_20 ;
int V_247 ;
long V_248 ;
char V_249 [ 64 ] ;
struct V_25 * V_26 ;
if ( V_218 == 0 || V_218 > sizeof( V_249 ) )
return - V_250 ;
if ( F_92 ( V_249 , V_246 , V_218 ) )
return - V_251 ;
V_249 [ V_218 - 1 ] = '\0' ;
if ( F_93 ( V_249 , 10 , & V_248 ) < 0 ) {
F_94 ( V_252 L_16 , V_249 ) ;
return - V_250 ;
}
if ( V_248 == 0 ) {
V_247 = sizeof( V_253 ) / sizeof( * V_253 ) ;
F_94 ( V_252 L_17 ) ;
F_94 ( V_252 L_18 ) ;
for ( V_20 = 0 ; V_20 < V_247 ; V_20 ++ )
F_94 ( V_252 L_19 , V_253 [ V_20 ] ) ;
} else if ( V_248 == - 1 ) {
F_6 (cpu) {
V_26 = & F_8 ( V_235 , V_6 ) ;
memset ( V_26 , 0 , sizeof( struct V_25 ) ) ;
}
}
return V_218 ;
}
static int F_95 ( const char * V_254 )
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
static int F_96 ( struct V_10 * V_11 , char * V_256 ,
int V_218 )
{
char * V_257 ;
char * V_258 ;
int V_205 = 0 ;
int V_255 ;
int V_259 = sizeof( V_260 ) / sizeof( * V_260 ) ;
V_257 = V_256 + strspn ( V_256 , V_261 ) ;
V_258 = V_257 ;
for (; * V_257 ; V_257 = V_258 + strspn ( V_258 , V_261 ) ) {
V_258 = V_257 + strcspn ( V_257 , V_261 ) ;
V_205 ++ ;
if ( V_258 == V_257 )
break;
}
if ( V_205 != V_259 ) {
F_94 ( V_262 L_20 , V_259 ) ;
return - V_250 ;
}
V_257 = V_256 + strspn ( V_256 , V_261 ) ;
V_258 = V_257 ;
for ( V_205 = 0 ; * V_257 ; V_257 = V_258 + strspn ( V_258 , V_261 ) , V_205 ++ ) {
V_258 = V_257 + strcspn ( V_257 , V_261 ) ;
V_255 = F_95 ( V_257 ) ;
switch ( V_205 ) {
case 0 :
if ( V_255 == 0 ) {
V_142 = V_263 ;
V_158 = V_263 ;
continue;
}
if ( V_255 < 1 || V_255 > V_11 -> V_55 ) {
F_94 ( V_252
L_21 ,
V_255 ) ;
return - V_250 ;
}
V_142 = V_255 ;
V_158 = V_255 ;
continue;
default:
if ( V_255 == 0 )
* V_260 [ V_205 ] . V_264 = V_260 [ V_205 ] . V_265 ;
else
* V_260 [ V_205 ] . V_264 = V_255 ;
continue;
}
if ( V_258 == V_257 )
break;
}
return 0 ;
}
static T_7 F_97 ( struct V_232 * V_232 , const char T_8 * V_246 ,
T_9 V_218 , T_6 * V_233 )
{
int V_6 ;
int V_240 ;
char V_256 [ 100 ] ;
struct V_10 * V_11 ;
if ( V_218 == 0 || V_218 > sizeof( V_256 ) - 1 )
return - V_250 ;
if ( F_92 ( V_256 , V_246 , V_218 ) )
return - V_251 ;
V_256 [ V_218 ] = '\0' ;
V_6 = F_98 () ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_240 = F_96 ( V_11 , V_256 , V_218 ) ;
F_99 () ;
if ( V_240 )
return V_240 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_142 = V_142 ;
V_11 -> V_158 = V_142 ;
V_11 -> V_136 = V_136 ;
V_11 -> V_138 = V_138 ;
V_11 -> V_144 = V_144 ;
V_11 -> V_187 = V_187 ;
V_11 -> V_157 = V_157 ;
V_11 -> V_266 = V_242 ;
V_11 -> V_164 = V_243 ;
V_11 -> V_155 = V_244 ;
}
return V_218 ;
}
static int F_100 ( struct V_267 * V_267 , struct V_232 * V_232 )
{
return F_101 ( V_232 , & V_268 ) ;
}
static int F_102 ( struct V_267 * V_267 , struct V_232 * V_232 )
{
return 0 ;
}
static int T_1 F_103 ( void )
{
struct V_269 * V_270 ;
if ( ! F_104 () )
return 0 ;
V_270 = F_105 ( V_271 , 0444 , NULL ,
& V_272 ) ;
if ( ! V_270 ) {
F_94 ( V_273 L_22 ,
V_271 ) ;
return - V_250 ;
}
V_274 = F_106 ( V_275 , NULL ) ;
if ( ! V_274 ) {
F_94 ( V_273 L_23 ,
V_275 ) ;
return - V_250 ;
}
V_276 = F_107 ( V_277 , 0600 ,
V_274 , NULL , & V_278 ) ;
if ( ! V_276 ) {
F_94 ( V_273 L_24 ,
V_277 ) ;
return - V_250 ;
}
return 0 ;
}
static void F_108 ( int V_4 , int V_56 , int V_279 )
{
int V_20 ;
int V_6 ;
int V_175 = 0 ;
unsigned long V_280 ;
unsigned long V_281 ;
unsigned long V_282 ;
T_9 V_283 ;
struct V_85 * V_85 ;
struct V_85 * V_284 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_10 * V_11 ;
V_283 = sizeof( struct V_85 ) * V_285 * V_122 ;
V_85 = F_109 ( V_283 , V_241 , V_4 ) ;
F_110 ( ! V_85 ) ;
V_280 = F_111 ( V_85 ) ;
V_282 = F_112 ( V_280 ) ;
V_281 = F_113 ( V_280 ) ;
if ( F_114 () )
V_175 = 1 ;
F_115 ( V_56 , ( V_282 << V_286 | V_281 ) ) ;
for ( V_20 = 0 , V_284 = V_85 ; V_20 < ( V_285 * V_122 ) ; V_20 ++ , V_284 ++ ) {
memset ( V_284 , 0 , sizeof( struct V_85 ) ) ;
if ( V_175 ) {
V_178 = & V_284 -> V_181 . V_178 ;
V_178 -> V_287 = 1 ;
V_178 -> V_288 =
F_116 ( V_279 ) ;
V_178 -> V_289 = V_290 ;
V_178 -> V_291 = V_292 ;
V_178 -> V_293 = 1 ;
} else {
V_180 = & V_284 -> V_181 . V_180 ;
V_180 -> V_287 = 1 ;
V_180 -> V_288 =
F_116 ( V_279 ) ;
V_180 -> V_289 = V_290 ;
V_180 -> V_291 = V_292 ;
}
}
F_6 (cpu) {
if ( V_56 != F_73 ( F_7 ( V_6 ) ) )
continue;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_121 = V_85 ;
}
}
static void F_117 ( int V_4 , int V_56 )
{
int V_6 ;
T_9 V_294 ;
char * V_295 ;
void * V_296 ;
unsigned long V_297 ;
unsigned long V_298 ;
unsigned long V_299 ;
unsigned long V_300 ;
struct V_14 * V_301 ;
struct V_10 * V_11 ;
V_294 = ( V_29 + 1 ) * sizeof( struct V_14 ) ;
V_296 = F_109 ( V_294 , V_241 , V_4 ) ;
V_301 = (struct V_14 * ) V_296 ;
F_110 ( ! V_301 ) ;
V_295 = ( char * ) V_301 + 31 ;
V_301 = (struct V_14 * ) ( ( ( unsigned long ) V_295 >> 5 ) << 5 ) ;
F_6 (cpu) {
if ( V_56 != F_86 ( V_6 ) )
continue;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_31 = V_301 ;
V_11 -> V_221 = V_301 ;
V_11 -> V_30 = V_301 + ( V_29 - 1 ) ;
}
V_297 = F_112 ( F_111 ( V_301 ) ) ;
V_298 = F_118 ( V_301 ) ;
V_299 = ( ( unsigned long ) V_297 << V_302 ) | V_298 ;
V_300 = F_118 ( V_301 + ( V_29 - 1 ) ) ;
F_119 ( V_56 , V_299 ) ;
F_120 ( V_56 , V_298 ) ;
F_121 ( V_56 , V_300 ) ;
F_122 ( V_56 , 0xffffUL ) ;
memset ( V_301 , 0 , sizeof( struct V_14 ) * V_29 ) ;
}
static void T_1 F_123 ( int V_3 , int V_303 , int V_279 )
{
int V_4 ;
int V_56 ;
unsigned long V_304 ;
V_4 = F_2 ( V_3 ) ;
V_56 = F_73 ( V_3 ) ;
F_108 ( V_4 , V_56 , V_279 ) ;
F_117 ( V_4 , V_56 ) ;
V_304 = F_5 ( V_3 ) | V_305 ;
F_124 ( V_56 , ( ( V_304 << 32 ) | V_303 ) ) ;
}
static int F_125 ( void )
{
unsigned long V_214 ;
int V_306 ;
int V_307 ;
int V_176 ;
int V_308 ;
int V_240 ;
unsigned long V_309 ;
if ( F_114 () ) {
V_306 = V_228 & V_310 ;
V_214 = F_29 ( V_311 ) ;
V_176 = ( V_214 >> V_312 ) & V_313 ;
V_214 = F_29 ( V_314 ) ;
V_307 = ( V_214 >> V_315 ) & V_316 ;
V_308 = V_317 [ V_176 ] ;
V_309 = V_308 * V_306 * V_307 ;
V_240 = V_309 / 1000 ;
} else {
V_214 = F_29 ( V_318 ) ;
V_214 = ( V_214 & V_319 ) >> V_320 ;
if ( V_214 & ( 1L << V_321 ) )
V_308 = 80 ;
else
V_308 = 10 ;
V_306 = V_214 & V_322 ;
V_240 = V_306 * V_308 ;
}
return V_240 ;
}
static void T_1 F_126 ( void )
{
int V_6 ;
struct V_10 * V_11 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_147 = 0 ;
V_11 -> V_27 = & F_8 ( V_235 , V_6 ) ;
V_11 -> V_323 = F_81 ( 2 * V_95 ) ;
V_11 -> V_142 = V_142 ;
V_11 -> V_158 = V_142 ;
V_11 -> V_136 = V_136 ;
V_11 -> V_138 = V_138 ;
V_11 -> V_144 = V_144 ;
V_11 -> V_187 = V_187 ;
V_11 -> V_157 = V_157 ;
V_11 -> V_266 = V_242 ;
V_11 -> V_164 = V_243 ;
V_11 -> V_155 = V_244 ;
V_11 -> V_133 = F_81 ( 100 ) ;
F_127 ( & V_11 -> V_139 ) ;
F_127 ( & V_11 -> V_116 ) ;
}
}
static int T_1 F_128 ( int V_279 ,
struct V_324 * V_325 ,
unsigned char * V_326 )
{
int V_6 ;
int V_56 ;
int V_3 ;
int V_327 ;
struct V_10 * V_11 ;
struct V_324 * V_328 ;
struct V_329 * V_330 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_56 = F_129 ( V_6 ) -> V_56 ;
if ( ( V_56 - V_279 ) >= V_211 ) {
F_94 ( V_331
L_25 ,
V_6 , V_56 , V_279 , V_211 ) ;
return 1 ;
}
V_11 -> V_332 = F_130 ( V_6 ) ;
V_11 -> V_73 = V_279 ;
V_3 = F_129 ( V_6 ) -> V_333 ;
* ( V_326 + ( V_3 / 8 ) ) |= ( 1 << ( V_3 % 8 ) ) ;
V_328 = & V_325 [ V_3 ] ;
V_328 -> V_334 ++ ;
V_328 -> V_3 = V_3 ;
V_328 -> V_56 = V_56 ;
V_327 = V_11 -> V_332 & 1 ;
V_328 -> V_335 |= ( 1 << V_327 ) ;
V_330 = & V_328 -> V_327 [ V_327 ] ;
V_330 -> V_336 [ V_330 -> V_334 ] = V_6 ;
V_330 -> V_334 ++ ;
if ( V_330 -> V_334 > V_337 ) {
F_94 ( V_331 L_26 ,
V_330 -> V_334 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_131 ( struct V_10 * V_41 )
{
int V_6 ;
T_9 V_338 = sizeof( struct V_57 ) * F_78 () ;
V_41 -> V_59 = F_109 ( V_338 , V_241 , V_41 -> V_332 ) ;
memset ( V_41 -> V_59 , 0 , V_338 ) ;
F_6 (cpu) {
V_41 -> V_59 [ V_6 ] . V_56 = F_129 ( V_6 ) -> V_56 ;
V_41 -> V_59 [ V_6 ] . V_3 = F_129 ( V_6 ) -> V_333 ;
}
}
static void F_132 ( struct V_10 * V_79 )
{
int V_339 = sizeof( T_2 ) ;
V_79 -> V_71 = F_133 ( V_339 , V_241 , V_79 -> V_332 ) ;
}
static int F_134 ( struct V_329 * V_330 , struct V_324 * V_328 ,
struct V_10 * * V_340 ,
struct V_10 * * V_341 )
{
int V_20 ;
int V_6 ;
struct V_10 * V_11 ;
for ( V_20 = 0 ; V_20 < V_330 -> V_334 ; V_20 ++ ) {
V_6 = V_330 -> V_336 [ V_20 ] ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_6 = V_6 ;
if ( V_20 == 0 ) {
* V_340 = V_11 ;
if ( ! ( * V_341 ) )
* V_341 = V_11 ;
}
V_11 -> V_55 = V_328 -> V_334 ;
V_11 -> V_52 = V_330 -> V_334 ;
V_11 -> V_42 = * V_340 ;
V_11 -> V_3 = V_328 -> V_3 ;
if ( F_114 () )
V_11 -> V_134 = 1 ;
else if ( F_76 () )
V_11 -> V_134 = 2 ;
else {
F_94 ( V_331 L_27 ) ;
return 1 ;
}
V_11 -> V_49 = * V_341 ;
V_11 -> V_104 = F_129 ( V_6 ) -> V_342 ;
V_11 -> V_109 = V_11 -> V_104 ;
if ( V_11 -> V_104 >= V_343 ) {
F_94 ( V_331 L_28 ,
V_11 -> V_104 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_135 ( int V_225 ,
struct V_324 * V_325 ,
unsigned char * V_326 )
{
int V_327 ;
int V_3 ;
unsigned short V_335 ;
for ( V_3 = 0 ; V_3 < V_225 ; V_3 ++ ) {
struct V_324 * V_328 ;
struct V_10 * V_41 = NULL ;
struct V_10 * V_79 = NULL ;
if ( ! ( * ( V_326 + ( V_3 / 8 ) ) & ( 1 << ( V_3 % 8 ) ) ) )
continue;
V_328 = & V_325 [ V_3 ] ;
V_335 = V_328 -> V_335 ;
V_327 = 0 ;
while ( V_335 ) {
struct V_329 * V_330 ;
if ( ( V_335 & 1 ) ) {
V_330 = & V_328 -> V_327 [ V_327 ] ;
if ( F_134 ( V_330 , V_328 , & V_41 , & V_79 ) )
return 1 ;
F_131 ( V_41 ) ;
}
V_327 ++ ;
V_335 = ( V_335 >> 1 ) ;
}
F_132 ( V_79 ) ;
}
return 0 ;
}
static int T_1 F_136 ( int V_225 , int V_344 )
{
unsigned char * V_326 ;
void * V_296 ;
struct V_324 * V_325 ;
V_95 = F_125 () ;
V_296 = F_137 ( V_225 * sizeof( struct V_324 ) , V_241 ) ;
V_325 = (struct V_324 * ) V_296 ;
memset ( V_325 , 0 , V_225 * sizeof( struct V_324 ) ) ;
V_326 = F_138 ( ( V_225 + 7 ) / 8 , V_241 ) ;
if ( F_128 ( V_344 , V_325 , V_326 ) )
goto V_345;
if ( F_135 ( V_225 , V_325 , V_326 ) )
goto V_345;
F_90 ( V_325 ) ;
F_90 ( V_326 ) ;
F_126 () ;
return 0 ;
V_345:
F_90 ( V_325 ) ;
F_90 ( V_326 ) ;
return 1 ;
}
static int T_1 F_139 ( void )
{
int V_3 ;
int V_56 ;
int V_225 ;
int V_346 ;
int V_347 ;
int V_303 ;
T_10 * V_70 ;
if ( ! F_104 () )
return 0 ;
if ( V_2 )
return 0 ;
F_140 (cur_cpu) {
V_70 = & F_8 ( V_209 , V_346 ) ;
F_141 ( V_70 , V_241 , F_130 ( V_346 ) ) ;
}
V_225 = F_71 () ;
F_127 ( & V_146 ) ;
V_150 = F_81 ( V_242 ) ;
V_348 = 0x7fffffff ;
for ( V_3 = 0 ; V_3 < V_225 ; V_3 ++ ) {
V_347 = F_72 ( V_3 ) ;
if ( V_347 && ( F_73 ( V_3 ) < V_348 ) )
V_348 = F_73 ( V_3 ) ;
}
F_70 () ;
if ( F_136 ( V_225 , V_348 ) ) {
V_2 = 1 ;
return 0 ;
}
V_303 = V_349 ;
F_142 (uvhub)
if ( F_72 ( V_3 ) )
F_123 ( V_3 , V_303 , V_348 ) ;
F_143 ( V_303 , V_350 ) ;
F_142 (uvhub) {
if ( F_72 ( V_3 ) ) {
unsigned long V_255 ;
unsigned long V_23 ;
V_56 = F_73 ( V_3 ) ;
V_255 = 1L << 63 ;
F_144 ( V_56 , V_255 ) ;
V_23 = 1 ;
if ( ! F_114 () )
F_145 ( V_56 , V_23 ) ;
}
}
return 0 ;
}
