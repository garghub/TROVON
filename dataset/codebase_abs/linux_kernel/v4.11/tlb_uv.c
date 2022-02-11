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
V_22 . V_23 ( V_16 ) ;
}
V_18 -> V_24 = 1 ;
V_18 -> V_20 = 0 ;
}
static void F_14 ( struct V_13 * V_14 ,
struct V_6 * V_7 )
{
int V_25 ;
int V_26 = 0 ;
unsigned long V_27 ;
unsigned long V_28 = 0 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_17 * V_29 ;
struct V_30 * V_31 = V_7 -> V_32 ;
V_31 -> V_33 ++ ;
for ( V_29 = V_18 + 1 , V_25 = 0 ; V_25 < V_34 ; V_29 ++ , V_25 ++ ) {
if ( V_29 > V_14 -> V_35 )
V_29 = V_14 -> V_36 ;
if ( V_29 == V_18 )
break;
if ( ( V_29 -> V_24 == 0 ) && ( V_29 -> V_19 == 0 ) &&
( V_29 -> V_20 ) && ( ( V_29 -> V_20 &
V_18 -> V_20 ) == 0 ) &&
( V_29 -> V_37 == V_18 -> V_37 ) &&
( V_29 -> V_38 != V_39 ) ) {
V_28 = V_22 . V_40 () ;
V_27 = V_29 -> V_20 ;
if ( V_28 & ( V_27 << V_21 ) ) {
unsigned long V_41 ;
V_29 -> V_19 = 1 ;
V_31 -> V_42 ++ ;
V_26 ++ ;
V_41 = ( V_27 << V_21 ) | V_27 ;
V_22 . V_23 ( V_41 ) ;
}
}
}
if ( ! V_26 )
V_31 -> V_43 ++ ;
}
static void F_15 ( struct V_13 * V_14 , struct V_6 * V_7 ,
int V_15 )
{
short V_44 = 0 ;
short * V_45 ;
struct atomic_short * V_46 ;
struct V_30 * V_31 = V_7 -> V_32 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_6 * V_47 = V_7 -> V_48 ;
if ( V_18 -> V_49 == V_50 ) {
F_16 () ;
V_31 -> V_51 ++ ;
} else {
F_17 ( V_18 -> V_49 ) ;
V_31 -> V_52 ++ ;
}
V_31 -> V_53 ++ ;
if ( V_18 -> V_38 == V_54 && V_7 == V_7 -> V_55 )
F_14 ( V_14 , V_7 ) ;
V_45 = & V_47 -> V_56 [ V_14 -> V_57 ] ;
V_46 = (struct atomic_short * ) V_45 ;
V_44 = F_18 ( 1 , V_46 ) ;
if ( V_44 == V_7 -> V_58 ) {
int V_59 ;
* V_45 = 0 ;
V_46 = (struct atomic_short * ) & V_18 -> V_60 ;
V_59 = F_18 ( V_44 , V_46 ) ;
if ( V_59 == V_7 -> V_61 ) {
F_13 ( V_14 , V_7 , V_15 ) ;
}
}
return;
}
static int F_19 ( int V_62 , struct V_6 * V_47 )
{
int V_5 ;
struct V_63 * V_64 ;
F_5 (cpu) {
V_64 = & V_47 -> V_65 [ V_5 ] ;
if ( V_62 == V_64 -> V_62 )
return V_5 ;
}
return - 1 ;
}
static void F_20 ( void * V_66 )
{
int V_25 ;
struct V_6 * V_7 = & F_6 ( V_6 , F_21 () ) ;
struct V_67 * V_68 = (struct V_67 * ) V_66 ;
struct V_17 * V_18 ;
struct V_30 * V_31 = V_7 -> V_32 ;
V_31 -> V_69 ++ ;
for ( V_18 = V_7 -> V_36 , V_25 = 0 ; V_25 < V_34 ; V_18 ++ , V_25 ++ ) {
unsigned long V_27 ;
if ( ( V_18 -> V_24 == 0 ) &&
( V_18 -> V_19 == 0 ) &&
( V_18 -> V_37 == V_68 -> V_70 ) &&
( V_18 -> V_20 ) &&
( V_18 -> V_38 != V_39 ) ) {
unsigned long V_28 ;
unsigned long V_41 ;
V_18 -> V_19 = 1 ;
V_28 = V_22 . V_40 () ;
V_27 = V_18 -> V_20 ;
V_41 = ( V_27 << V_21 ) | V_27 ;
if ( V_28 & V_27 ) {
V_31 -> V_71 ++ ;
V_22 . V_23 ( V_41 ) ;
}
}
}
return;
}
static void F_22 ( struct V_72 * V_73 , struct V_6 * V_7 )
{
int V_62 ;
int V_74 ;
int V_75 ;
int V_70 = V_7 -> V_5 ;
T_2 * V_76 = V_7 -> V_55 -> V_77 ;
struct V_6 * V_47 = V_7 -> V_48 ;
struct V_67 V_67 ;
V_67 . V_70 = V_70 ;
F_23 ( V_76 ) ;
V_75 = sizeof( struct V_72 ) * V_78 ;
for ( V_62 = 0 ; V_62 < V_75 ; V_62 ++ ) {
int V_5 ;
if ( ! F_24 ( V_62 , V_73 ) )
continue;
V_74 = V_62 + V_7 -> V_79 ;
V_5 = F_19 ( V_74 , V_47 ) ;
F_25 ( V_5 , V_76 ) ;
}
F_26 ( V_76 , F_20 , ( void * ) & V_67 , 1 ) ;
return;
}
static inline unsigned long long F_27 ( unsigned long long V_80 )
{
struct V_81 * V_82 = F_28 () ;
unsigned long long V_83 ;
V_83 = F_29 ( V_80 , V_82 -> V_84 , V_82 -> V_85 ) ;
F_30 ( V_82 ) ;
return V_83 ;
}
static inline unsigned long long F_31 ( unsigned long long V_83 )
{
struct V_81 * V_82 = F_28 () ;
unsigned long long V_80 ;
V_80 = ( V_83 << V_82 -> V_85 ) / V_82 -> V_84 ;
F_30 ( V_82 ) ;
return V_80 ;
}
static inline unsigned long F_32 ( unsigned long long V_80 )
{
return F_27 ( V_80 ) / V_86 ;
}
static inline T_3 F_33 ( unsigned long V_87 )
{
return F_31 ( V_87 * V_88 ) ;
}
static inline unsigned long long F_34 ( unsigned long V_89 )
{
return F_31 ( V_89 * V_86 ) ;
}
static inline void F_35 ( struct V_6 * V_90 )
{
F_18 ( 1 , (struct atomic_short * ) & V_90 -> V_91 ) ;
}
static inline void F_36 ( struct V_6 * V_90 )
{
F_18 ( - 1 , (struct atomic_short * ) & V_90 -> V_91 ) ;
}
static unsigned long F_37 ( unsigned long V_92 , int V_93 )
{
unsigned long V_94 ;
V_94 = F_38 ( V_92 ) ;
V_94 >>= V_93 ;
V_94 &= V_95 ;
return V_94 ;
}
static int F_39 ( struct V_96 * V_96 ,
unsigned long V_92 , int V_93 ,
struct V_6 * V_7 , long V_97 )
{
unsigned long V_94 ;
T_3 V_98 ;
struct V_30 * V_31 = V_7 -> V_32 ;
V_94 = F_37 ( V_92 , V_93 ) ;
while ( ( V_94 != V_99 ) ) {
if ( V_94 == V_100 ) {
V_31 -> V_101 ++ ;
return V_102 ;
} else if ( V_94 == V_103 ) {
V_31 -> V_104 ++ ;
V_98 = F_40 () ;
if ( F_32 ( V_98 - V_7 -> V_105 ) < V_106 ) {
V_7 -> V_107 = 0 ;
return V_108 ;
}
V_7 -> V_107 = 0 ;
return V_109 ;
} else {
F_41 () ;
}
V_94 = F_37 ( V_92 , V_93 ) ;
}
V_7 -> V_107 ++ ;
return V_110 ;
}
static unsigned long F_42 ( unsigned long V_111 , int V_112 , int V_113 )
{
return ( ( F_43 ( V_111 ) >> V_112 ) & V_95 ) << 1 ;
}
int F_44 ( struct V_6 * V_7 )
{
int V_5 = V_7 -> V_114 ;
int V_92 ;
int V_93 ;
V_92 = V_115 ;
V_93 = V_5 * V_116 ;
return ( ( ( ( ( F_43 ( V_92 ) >> V_93 ) &
V_95 ) ) << 1 ) == V_117 ) ;
}
int F_45 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_32 ;
V_31 -> V_118 ++ ;
V_7 -> V_119 = 1 ;
return V_102 ;
}
static int F_46 ( struct V_96 * V_96 ,
unsigned long V_92 , int V_93 ,
struct V_6 * V_7 , long V_97 )
{
unsigned long V_120 ;
T_3 V_98 ;
int V_113 = V_7 -> V_114 ;
long V_121 = 0 ;
struct V_30 * V_31 = V_7 -> V_32 ;
V_120 = F_42 ( V_92 , V_93 , V_113 ) ;
while ( V_120 != V_122 ) {
if ( ( V_120 == V_123 ) ) {
V_31 -> V_101 ++ ;
return V_102 ;
} else if ( V_120 == V_124 ) {
V_98 = F_40 () ;
if ( F_32 ( V_98 - V_7 -> V_105 ) < V_106 ) {
V_7 -> V_107 = 0 ;
V_31 -> V_125 ++ ;
return V_102 ;
}
V_31 -> V_104 ++ ;
V_7 -> V_107 = 0 ;
return V_102 ;
} else {
V_121 ++ ;
if ( V_121 > 1000000 ) {
V_121 = 0 ;
V_98 = F_40 () ;
if ( ( V_98 - V_7 -> V_105 ) > V_7 -> V_126 )
return F_45 ( V_7 ) ;
}
F_41 () ;
}
V_120 = F_42 ( V_92 , V_93 , V_113 ) ;
}
V_7 -> V_107 ++ ;
return V_110 ;
}
static int F_47 ( struct V_96 * V_96 , struct V_6 * V_7 , long V_97 )
{
int V_93 ;
unsigned long V_92 ;
int V_113 = V_7 -> V_114 ;
if ( V_113 < V_127 ) {
V_92 = V_115 ;
V_93 = V_113 * V_116 ;
} else {
V_92 = V_128 ;
V_93 = ( ( V_113 - V_127 ) * V_116 ) ;
}
if ( V_7 -> V_129 == 1 )
return F_39 ( V_96 , V_92 , V_93 , V_7 , V_97 ) ;
else
return F_46 ( V_96 , V_92 , V_93 , V_7 , V_97 ) ;
}
static void F_48 ( struct V_96 * V_96 ,
struct V_6 * V_7 ,
struct V_6 * V_90 , struct V_30 * V_31 )
{
F_49 ( V_7 -> V_130 ) ;
V_7 -> V_131 ++ ;
if ( V_7 -> V_131 >= V_7 -> V_132 ) {
V_7 -> V_131 = 0 ;
F_35 ( V_90 ) ;
F_50 ( & V_90 -> V_133 ) ;
F_22 ( & V_96 -> V_73 , V_7 ) ;
F_51 ( & V_90 -> V_133 ) ;
F_36 ( V_90 ) ;
V_7 -> V_134 ++ ;
V_31 -> V_135 ++ ;
}
}
static void F_52 ( struct V_96 * V_96 ,
struct V_6 * V_7 , struct V_6 * V_90 ,
struct V_30 * V_31 )
{
V_90 -> V_136 = 1 ;
V_7 -> V_137 ++ ;
if ( V_7 -> V_137 >= V_7 -> V_138 ) {
V_7 -> V_137 = 0 ;
F_35 ( V_90 ) ;
F_50 ( & V_90 -> V_133 ) ;
F_22 ( & V_96 -> V_73 , V_7 ) ;
F_51 ( & V_90 -> V_133 ) ;
F_36 ( V_90 ) ;
V_7 -> V_134 ++ ;
V_31 -> V_139 ++ ;
}
}
static void F_53 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
int V_140 ;
struct V_6 * V_141 ;
struct V_6 * V_90 ;
T_3 V_142 ;
V_90 = V_7 -> V_55 ;
F_50 ( & V_90 -> V_143 ) ;
if ( ! V_7 -> V_144 ) {
V_31 -> V_145 ++ ;
V_142 = F_40 () ;
F_5 (tcpu) {
V_141 = & F_6 ( V_6 , V_140 ) ;
if ( V_141 -> V_55 == V_90 ) {
V_141 -> V_144 = 1 ;
V_141 -> V_146 =
V_142 + V_7 -> V_147 ;
}
}
}
F_51 ( & V_90 -> V_143 ) ;
}
static void F_54 ( int V_31 , struct V_6 * V_7 ,
struct V_6 * V_90 )
{
V_7 -> V_131 = 0 ;
V_7 -> V_137 = 0 ;
if ( V_31 != V_110 )
return;
if ( V_7 -> V_107 <= V_7 -> V_148 )
return;
if ( V_90 -> V_136 >= V_90 -> V_149 )
return;
V_90 -> V_136 ++ ;
}
static void F_55 ( T_3 V_150 , T_3 V_151 ,
struct V_6 * V_7 , struct V_30 * V_31 ,
int V_152 , int V_97 )
{
T_3 V_153 ;
if ( V_151 > V_150 ) {
V_153 = V_151 - V_150 ;
V_31 -> V_154 += V_153 ;
if ( ( V_152 == V_110 ) && ( V_97 == 1 ) ) {
V_7 -> V_155 ++ ;
V_7 -> V_156 += V_153 ;
if ( ( V_153 > V_157 ) &&
( V_7 -> V_155 > V_7 -> V_158 ) &&
( ( V_7 -> V_156 / V_7 -> V_155 ) >
V_157 ) ) {
V_31 -> V_159 ++ ;
F_53 ( V_7 , V_31 ) ;
}
}
} else
V_31 -> V_160 -- ;
if ( V_152 == V_110 && V_97 > 1 )
V_31 -> V_161 ++ ;
else if ( V_152 == V_102 ) {
V_31 -> V_162 ++ ;
if ( F_40 () > V_7 -> V_163 )
V_7 -> V_164 = 0 ;
V_7 -> V_164 ++ ;
if ( V_7 -> V_164 == 1 )
V_7 -> V_163 = F_40 () + V_7 -> V_147 ;
if ( V_7 -> V_164 > V_7 -> V_165 ) {
F_53 ( V_7 , V_31 ) ;
V_31 -> V_166 ++ ;
}
}
}
static void F_56 ( struct V_6 * V_90 , struct V_30 * V_31 )
{
T_4 * V_167 = & V_90 -> V_168 ;
T_5 * V_169 ;
V_169 = & V_90 -> V_170 ;
if ( ! F_57 ( V_167 , V_169 , V_90 -> V_136 ) ) {
V_31 -> V_171 ++ ;
do {
F_41 () ;
} while ( ! F_57 ( V_167 , V_169 , V_90 -> V_136 ) );
}
}
static void F_58 ( int V_152 , struct V_96 * V_96 ,
struct V_6 * V_7 , struct V_6 * V_90 ,
struct V_30 * V_31 )
{
if ( V_152 == V_108 )
F_48 ( V_96 , V_7 , V_90 , V_31 ) ;
else if ( V_152 == V_109 )
F_52 ( V_96 , V_7 , V_90 , V_31 ) ;
}
int F_59 ( struct V_77 * V_172 , struct V_6 * V_7 ,
struct V_96 * V_96 )
{
int V_173 = 0 ;
int V_174 = 0 ;
int V_175 = 0 ;
long V_97 = 0 ;
unsigned long V_176 ;
T_3 V_150 ;
T_3 V_151 ;
struct V_30 * V_31 = V_7 -> V_32 ;
struct V_6 * V_90 = V_7 -> V_55 ;
struct V_177 * V_178 = NULL ;
struct V_179 * V_180 = NULL ;
if ( V_7 -> V_129 == 1 ) {
V_175 = 1 ;
F_56 ( V_90 , V_31 ) ;
}
while ( V_90 -> V_91 )
F_41 () ;
V_150 = F_40 () ;
if ( V_175 )
V_178 = & V_96 -> V_181 . V_178 ;
else
V_180 = & V_96 -> V_181 . V_180 ;
do {
if ( V_97 == 0 ) {
if ( V_175 )
V_178 -> V_38 = V_182 ;
else
V_180 -> V_38 = V_182 ;
V_173 = V_7 -> V_183 ++ ;
} else {
if ( V_175 )
V_178 -> V_38 = V_54 ;
else
V_180 -> V_38 = V_54 ;
V_31 -> V_184 ++ ;
}
if ( V_175 )
V_178 -> V_185 = V_173 ;
else
V_180 -> V_185 = V_173 ;
V_176 = ( 1UL << V_186 ) | V_7 -> V_114 ;
V_7 -> V_105 = F_40 () ;
F_60 ( V_176 ) ;
V_97 ++ ;
V_174 = F_47 ( V_96 , V_7 , V_97 ) ;
F_58 ( V_174 , V_96 , V_7 , V_90 , V_31 ) ;
if ( V_7 -> V_134 >= V_7 -> V_187 ) {
V_7 -> V_134 = 0 ;
V_31 -> V_188 ++ ;
V_174 = V_102 ;
break;
}
F_41 () ;
} while ( ( V_174 == V_108 ) ||
( V_174 == V_109 ) );
V_151 = F_40 () ;
F_54 ( V_174 , V_7 , V_90 ) ;
while ( V_90 -> V_91 )
F_41 () ;
F_61 ( & V_90 -> V_170 ) ;
F_55 ( V_150 , V_151 , V_7 , V_31 , V_174 , V_97 ) ;
if ( V_174 == V_102 )
return 1 ;
return 0 ;
}
static int F_62 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
int V_140 ;
struct V_6 * V_141 ;
struct V_6 * V_90 ;
V_90 = V_7 -> V_55 ;
F_50 ( & V_90 -> V_143 ) ;
if ( V_7 -> V_144 && ( F_40 () >= V_7 -> V_146 ) ) {
V_31 -> V_189 ++ ;
F_5 (tcpu) {
V_141 = & F_6 ( V_6 , V_140 ) ;
if ( V_141 -> V_55 == V_90 ) {
V_141 -> V_144 = 0 ;
V_141 -> V_155 = 0 ;
V_141 -> V_156 = 0 ;
V_141 -> V_164 = 0 ;
}
}
F_51 ( & V_90 -> V_143 ) ;
return 0 ;
}
F_51 ( & V_90 -> V_143 ) ;
return - 1 ;
}
static void F_63 ( struct V_30 * V_31 , int V_190 , int V_191 ,
int V_192 , struct V_96 * V_96 )
{
V_31 -> V_160 ++ ;
V_31 -> V_193 += V_192 + V_190 ;
V_31 -> V_194 += V_192 ;
V_31 -> V_195 += V_190 ;
V_191 = F_64 ( & V_96 -> V_73 ) ;
if ( V_190 ) {
V_31 -> V_196 ++ ;
V_31 -> V_197 += ( V_191 - 1 ) ;
} else
V_31 -> V_197 += V_191 ;
V_31 -> V_198 += V_191 ;
if ( V_191 >= 16 )
V_31 -> V_199 ++ ;
else if ( V_191 >= 8 )
V_31 -> V_200 ++ ;
else if ( V_191 >= 4 )
V_31 -> V_201 ++ ;
else if ( V_191 >= 2 )
V_31 -> V_202 ++ ;
else
V_31 -> V_203 ++ ;
}
static int F_65 ( struct V_77 * V_172 , struct V_6 * V_7 ,
struct V_96 * V_96 , int * V_204 , int * V_205 )
{
int V_5 ;
int V_62 ;
int V_206 = 0 ;
struct V_63 * V_64 ;
F_66 (cpu, flush_mask) {
V_64 = & V_7 -> V_48 -> V_65 [ V_5 ] ;
V_62 = V_64 -> V_62 - V_7 -> V_79 ;
F_67 ( V_62 , & V_96 -> V_73 ) ;
V_206 ++ ;
if ( V_64 -> V_9 == V_7 -> V_9 )
( * V_204 ) ++ ;
else
( * V_205 ) ++ ;
}
if ( ! V_206 )
return 1 ;
return 0 ;
}
const struct V_77 * F_68 ( const struct V_77 * V_77 ,
struct V_207 * V_208 ,
unsigned long V_209 ,
unsigned long V_210 ,
unsigned int V_5 )
{
int V_190 = 0 ;
int V_192 = 0 ;
int V_191 = 0 ;
struct V_96 * V_96 ;
struct V_77 * V_172 ;
struct V_30 * V_31 ;
struct V_6 * V_7 ;
unsigned long V_94 ;
unsigned long V_211 ;
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 )
return V_77 ;
V_31 = V_7 -> V_32 ;
V_31 -> V_212 ++ ;
if ( V_7 -> V_119 ) {
V_94 =
F_43 ( V_115 ) ;
V_211 = ( ( V_94 >> ( V_7 -> V_114 *
V_116 ) ) & V_95 ) << 1 ;
if ( V_211 == V_117 )
return V_77 ;
V_7 -> V_119 = 0 ;
}
if ( V_7 -> V_144 ) {
if ( F_62 ( V_7 , V_31 ) ) {
V_31 -> V_213 ++ ;
return V_77 ;
}
}
V_172 = (struct V_77 * ) F_6 ( V_214 , V_5 ) ;
F_69 ( V_172 , V_77 , F_70 ( V_5 ) ) ;
if ( F_71 ( V_5 , V_77 ) )
V_31 -> V_215 ++ ;
V_96 = V_7 -> V_216 ;
V_96 += ( V_217 * V_7 -> V_114 ) ;
F_72 ( & V_96 -> V_73 , V_218 ) ;
if ( F_65 ( V_172 , V_7 , V_96 , & V_190 , & V_192 ) )
return NULL ;
F_63 ( V_31 , V_190 , V_191 , V_192 , V_96 ) ;
if ( ! V_210 || ( V_210 - V_209 ) <= V_219 )
V_96 -> V_220 . V_49 = V_209 ;
else
V_96 -> V_220 . V_49 = V_50 ;
V_96 -> V_220 . V_37 = V_5 ;
if ( ! F_59 ( V_172 , V_7 , V_96 ) )
return NULL ;
else
return V_77 ;
}
struct V_17 * F_73 ( struct V_17 * V_18 ,
struct V_6 * V_7 )
{
struct V_17 * V_221 = V_18 + 1 ;
unsigned char V_20 = V_18 -> V_20 ;
if ( V_221 > V_7 -> V_35 )
V_221 = V_7 -> V_36 ;
while ( V_221 != V_18 ) {
if ( ( V_221 -> V_19 == 0 ) && ( V_221 -> V_24 == 0 ) &&
( V_221 -> V_20 == V_20 ) )
return V_221 ;
V_221 ++ ;
if ( V_221 > V_7 -> V_35 )
V_221 = V_7 -> V_36 ;
}
return NULL ;
}
void F_74 ( struct V_13 * V_14 , struct V_6 * V_7 )
{
unsigned long V_222 ;
unsigned char V_20 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_17 * V_223 ;
V_222 = V_22 . V_40 () ;
V_20 = V_18 -> V_20 ;
if ( ( V_20 & V_222 ) == 0 ) {
V_223 = F_73 ( V_18 , V_7 ) ;
if ( V_223 ) {
F_15 ( V_14 , V_7 , 0 ) ;
return;
}
}
F_15 ( V_14 , V_7 , 1 ) ;
return;
}
void F_75 ( struct V_224 * V_225 )
{
int V_226 = 0 ;
T_3 V_227 ;
struct V_17 * V_18 ;
struct V_6 * V_7 ;
struct V_30 * V_31 ;
struct V_13 V_228 ;
F_76 () ;
V_227 = F_40 () ;
V_7 = & F_6 ( V_6 , F_21 () ) ;
V_31 = V_7 -> V_32 ;
V_228 . V_36 = V_7 -> V_36 ;
V_228 . V_35 = V_7 -> V_35 ;
V_18 = V_7 -> V_229 ;
while ( V_18 -> V_20 ) {
V_226 ++ ;
V_228 . V_57 = V_18 - V_228 . V_36 ;
V_228 . V_18 = V_18 ;
if ( V_7 -> V_129 == 2 )
F_74 ( & V_228 , V_7 ) ;
else
F_15 ( & V_228 , V_7 , 1 ) ;
V_18 ++ ;
if ( V_18 > V_228 . V_35 )
V_18 = V_228 . V_36 ;
V_7 -> V_229 = V_18 ;
}
V_31 -> V_230 += ( F_40 () - V_227 ) ;
if ( ! V_226 )
V_31 -> V_231 ++ ;
else if ( V_226 > 1 )
V_31 -> V_232 ++ ;
}
static void T_1 F_77 ( void )
{
int V_9 ;
int V_233 ;
int V_62 ;
unsigned long V_222 ;
V_233 = F_78 () ;
for ( V_9 = 0 ; V_9 < V_233 ; V_9 ++ ) {
if ( ! F_79 ( V_9 ) )
continue;
V_62 = F_80 ( V_9 ) ;
V_222 = F_81 ( V_62 ) ;
V_222 &= ~ ( 1L << V_234 ) ;
F_82 ( V_62 , V_222 ) ;
V_222 &= ~ ( ( unsigned long ) 0xf << V_235 ) ;
V_222 |= ( V_236 << V_235 ) ;
F_82 ( V_62 , V_222 ) ;
V_222 |= ( 1L << V_234 ) ;
if ( F_83 () ) {
V_222 &= ~ ( 1L << V_237 ) ;
} else if ( F_84 () ) {
V_222 &= ~ ( 1L << V_238 ) ;
V_222 |= ( 1L << V_239 ) ;
}
F_82 ( V_62 , V_222 ) ;
}
}
static void * F_85 ( struct V_240 * V_241 , T_6 * V_111 )
{
if ( * V_111 < F_86 () )
return V_111 ;
return NULL ;
}
static void * F_87 ( struct V_240 * V_241 , void * V_82 , T_6 * V_111 )
{
( * V_111 ) ++ ;
if ( * V_111 < F_86 () )
return V_111 ;
return NULL ;
}
static void F_88 ( struct V_240 * V_241 , void * V_82 )
{
}
static int F_89 ( struct V_240 * V_241 , void * V_82 )
{
struct V_30 * V_31 ;
struct V_6 * V_7 ;
int V_5 ;
V_5 = * ( T_6 * ) V_82 ;
if ( ! V_5 ) {
F_90 ( V_241 ,
L_6 ) ;
F_90 ( V_241 , L_7 ) ;
F_90 ( V_241 ,
L_8 ) ;
F_90 ( V_241 ,
L_9 ) ;
F_90 ( V_241 ,
L_10 ) ;
F_90 ( V_241 ,
L_11 ) ;
F_90 ( V_241 , L_12 ) ;
}
if ( V_5 < F_86 () && F_91 ( V_5 ) ) {
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 ) {
F_92 ( V_241 , L_13 , V_5 ) ;
return 0 ;
}
V_31 = V_7 -> V_32 ;
F_92 ( V_241 ,
L_14 ,
V_5 , V_7 -> V_4 , V_31 -> V_160 ,
F_32 ( V_31 -> V_154 ) ,
V_31 -> V_215 , V_31 -> V_195 ,
V_31 -> V_194 , V_31 -> V_193 ,
V_31 -> V_196 , V_31 -> V_197 ,
V_31 -> V_198 , V_31 -> V_199 ) ;
F_92 ( V_241 , L_15 ,
V_31 -> V_200 , V_31 -> V_201 ,
V_31 -> V_202 , V_31 -> V_203 ,
V_31 -> V_104 , V_31 -> V_242 ) ;
F_92 ( V_241 , L_16 ,
V_31 -> V_184 , V_31 -> V_161 ,
V_31 -> V_135 , V_31 -> V_139 ,
V_31 -> V_162 , V_31 -> V_101 ,
V_31 -> V_243 , V_31 -> V_171 ) ;
F_92 ( V_241 , L_17 ,
V_31 -> V_145 , V_31 -> V_189 ,
V_31 -> V_118 , V_31 -> V_244 ,
V_31 -> V_245 , V_31 -> V_212 ,
V_31 -> V_213 , V_31 -> V_125 ,
V_31 -> V_188 , V_31 -> V_166 ,
V_31 -> V_159 ) ;
F_92 ( V_241 ,
L_18 ,
V_22 . V_246 ( F_93 ( V_5 ) ) ,
V_31 -> V_53 , F_32 ( V_31 -> V_230 ) ,
V_31 -> V_51 , V_31 -> V_52 , V_31 -> V_232 ,
V_31 -> V_231 , V_31 -> V_33 , V_31 -> V_42 ,
V_31 -> V_43 , V_31 -> V_69 ,
V_31 -> V_71 ) ;
}
return 0 ;
}
static T_7 F_94 ( struct V_241 * V_241 , char T_8 * V_247 ,
T_9 V_226 , T_6 * V_248 )
{
char * V_249 ;
int V_250 ;
V_249 = F_95 ( V_251 , L_19 ,
L_20 ,
L_21 ,
L_22 ,
V_136 , V_130 , V_132 ,
V_138 , V_187 , V_148 ,
V_252 , V_253 , V_147 ,
V_165 ) ;
if ( ! V_249 )
return - V_254 ;
V_250 = F_96 ( V_247 , V_226 , V_248 , V_249 , strlen ( V_249 ) ) ;
F_97 ( V_249 ) ;
return V_250 ;
}
static T_7 F_98 ( struct V_241 * V_241 , const char T_8 * V_255 ,
T_9 V_226 , T_6 * V_82 )
{
int V_5 ;
int V_25 ;
int V_256 ;
long V_257 ;
char V_258 [ 64 ] ;
struct V_30 * V_31 ;
if ( V_226 == 0 || V_226 > sizeof( V_258 ) )
return - V_3 ;
if ( F_99 ( V_258 , V_255 , V_226 ) )
return - V_259 ;
V_258 [ V_226 - 1 ] = '\0' ;
if ( ! strcmp ( V_258 , L_23 ) ) {
F_4 () ;
return V_226 ;
} else if ( ! strcmp ( V_258 , L_24 ) ) {
F_7 () ;
return V_226 ;
}
if ( F_100 ( V_258 , 10 , & V_257 ) < 0 ) {
F_101 ( L_25 , V_258 ) ;
return - V_3 ;
}
if ( V_257 == 0 ) {
V_256 = F_102 ( V_260 ) ;
F_101 ( L_26 ) ;
F_101 ( L_27 ) ;
for ( V_25 = 0 ; V_25 < V_256 ; V_25 ++ )
F_101 ( L_28 , V_260 [ V_25 ] ) ;
} else if ( V_257 == - 1 ) {
F_5 (cpu) {
V_31 = & F_6 ( V_261 , V_5 ) ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
}
}
return V_226 ;
}
static int F_103 ( const char * V_262 )
{
int V_263 = 0 ;
for (; ; V_262 ++ ) {
switch ( * V_262 ) {
case '0' ... '9' :
V_263 = 10 * V_263 + ( * V_262 - '0' ) ;
break;
default:
return V_263 ;
}
}
}
static int F_104 ( struct V_6 * V_7 , char * V_264 ,
int V_226 )
{
char * V_265 ;
char * V_266 ;
int V_206 = 0 ;
int V_263 ;
int V_267 = F_102 ( V_268 ) ;
V_265 = V_264 + strspn ( V_264 , V_269 ) ;
V_266 = V_265 ;
for (; * V_265 ; V_265 = V_266 + strspn ( V_266 , V_269 ) ) {
V_266 = V_265 + strcspn ( V_265 , V_269 ) ;
V_206 ++ ;
if ( V_266 == V_265 )
break;
}
if ( V_206 != V_267 ) {
F_3 ( L_29 , V_267 ) ;
return - V_3 ;
}
V_265 = V_264 + strspn ( V_264 , V_269 ) ;
V_266 = V_265 ;
for ( V_206 = 0 ; * V_265 ; V_265 = V_266 + strspn ( V_266 , V_269 ) , V_206 ++ ) {
V_266 = V_265 + strcspn ( V_265 , V_269 ) ;
V_263 = F_103 ( V_265 ) ;
switch ( V_206 ) {
case 0 :
if ( V_263 == 0 ) {
V_136 = V_270 ;
V_149 = V_270 ;
continue;
}
if ( V_263 < 1 || V_263 > V_7 -> V_61 ) {
F_101 (
L_30 ,
V_263 ) ;
return - V_3 ;
}
V_136 = V_263 ;
V_149 = V_263 ;
continue;
default:
if ( V_263 == 0 )
* V_268 [ V_206 ] . V_271 = V_268 [ V_206 ] . V_272 ;
else
* V_268 [ V_206 ] . V_271 = V_263 ;
continue;
}
if ( V_266 == V_265 )
break;
}
return 0 ;
}
static T_7 F_105 ( struct V_241 * V_241 , const char T_8 * V_255 ,
T_9 V_226 , T_6 * V_82 )
{
int V_5 ;
int V_250 ;
char V_264 [ 100 ] ;
struct V_6 * V_7 ;
if ( V_226 == 0 || V_226 > sizeof( V_264 ) - 1 )
return - V_3 ;
if ( F_99 ( V_264 , V_255 , V_226 ) )
return - V_259 ;
V_264 [ V_226 ] = '\0' ;
V_5 = F_106 () ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_250 = F_104 ( V_7 , V_264 , V_226 ) ;
F_107 () ;
if ( V_250 )
return V_250 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_136 = V_136 ;
V_7 -> V_149 = V_136 ;
V_7 -> V_130 = V_130 ;
V_7 -> V_132 = V_132 ;
V_7 -> V_138 = V_138 ;
V_7 -> V_187 = V_187 ;
V_7 -> V_148 = V_148 ;
V_7 -> V_273 = V_252 ;
V_7 -> V_158 = V_253 ;
V_7 -> V_147 = F_33 ( V_147 ) ;
V_7 -> V_165 = V_165 ;
}
return V_226 ;
}
static int F_108 ( struct V_274 * V_274 , struct V_241 * V_241 )
{
return F_109 ( V_241 , & V_275 ) ;
}
static int F_110 ( struct V_274 * V_274 , struct V_241 * V_241 )
{
return 0 ;
}
static int T_1 F_111 ( void )
{
struct V_276 * V_277 ;
if ( ! F_112 () )
return 0 ;
V_277 = F_113 ( V_278 , 0444 , NULL ,
& V_279 ) ;
if ( ! V_277 ) {
F_114 ( L_31 ,
V_278 ) ;
return - V_3 ;
}
V_280 = F_115 ( V_281 , NULL ) ;
if ( ! V_280 ) {
F_114 ( L_32 ,
V_281 ) ;
return - V_3 ;
}
V_282 = F_116 ( V_283 , 0600 ,
V_280 , NULL , & V_284 ) ;
if ( ! V_282 ) {
F_114 ( L_33 ,
V_283 ) ;
return - V_3 ;
}
return 0 ;
}
static void F_117 ( int V_10 , int V_62 , int V_285 )
{
int V_25 ;
int V_5 ;
int V_175 = 0 ;
unsigned long V_286 ;
unsigned long V_287 ;
unsigned long V_288 ;
T_9 V_289 ;
struct V_96 * V_96 ;
struct V_96 * V_290 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_6 * V_7 ;
V_289 = sizeof( struct V_96 ) * V_291 * V_217 ;
V_96 = F_118 ( V_289 , V_251 , V_10 ) ;
F_119 ( ! V_96 ) ;
V_286 = F_120 ( V_96 ) ;
V_288 = F_121 ( V_286 ) ;
V_287 = V_22 . V_292 ( V_286 ) ;
if ( F_122 () )
V_175 = 1 ;
F_123 ( V_62 , ( V_288 << V_293 | V_287 ) ) ;
for ( V_25 = 0 , V_290 = V_96 ; V_25 < ( V_291 * V_217 ) ; V_25 ++ , V_290 ++ ) {
memset ( V_290 , 0 , sizeof( struct V_96 ) ) ;
if ( V_175 ) {
V_178 = & V_290 -> V_181 . V_178 ;
V_178 -> V_294 = 1 ;
V_178 -> V_295 =
F_124 ( V_285 ) ;
V_178 -> V_296 = V_297 ;
V_178 -> V_298 = V_299 ;
V_178 -> V_300 = 1 ;
} else {
V_180 = & V_290 -> V_181 . V_180 ;
V_180 -> V_294 = 1 ;
V_180 -> V_295 =
F_124 ( V_285 ) ;
V_180 -> V_296 = V_297 ;
V_180 -> V_298 = V_299 ;
}
}
F_5 (cpu) {
if ( V_62 != F_80 ( F_12 ( V_5 ) ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_216 = V_96 ;
}
}
static void F_125 ( int V_10 , int V_62 )
{
int V_5 ;
T_9 V_301 ;
char * V_302 ;
void * V_303 ;
unsigned long V_304 , V_305 , V_306 , V_307 ;
struct V_17 * V_308 ;
struct V_6 * V_7 ;
V_301 = ( V_34 + 1 ) * sizeof( struct V_17 ) ;
V_303 = F_118 ( V_301 , V_251 , V_10 ) ;
V_308 = (struct V_17 * ) V_303 ;
F_119 ( ! V_308 ) ;
V_302 = ( char * ) V_308 + 31 ;
V_308 = (struct V_17 * ) ( ( ( unsigned long ) V_302 >> 5 ) << 5 ) ;
F_5 (cpu) {
if ( V_62 != F_93 ( V_5 ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_36 = V_308 ;
V_7 -> V_229 = V_308 ;
V_7 -> V_35 = V_308 + ( V_34 - 1 ) ;
}
V_305 = V_22 . V_292 ( F_120 ( V_308 ) ) ;
V_306 = V_22 . V_292 ( F_120 ( V_308 + ( V_34 - 1 ) ) ) ;
V_7 = & F_6 ( V_6 , F_21 () ) ;
if ( V_7 -> V_129 <= 3 ) {
V_307 = V_305 ;
V_304 = F_121 ( F_120 ( V_308 ) ) ;
V_305 = ( V_304 << V_309 ) | V_307 ;
F_126 ( V_62 , V_307 ) ;
}
V_22 . V_310 ( V_62 , V_305 ) ;
V_22 . V_311 ( V_62 , V_306 ) ;
memset ( V_308 , 0 , sizeof( struct V_17 ) * V_34 ) ;
}
static void T_1 F_127 ( int V_9 , int V_312 , int V_285 )
{
int V_10 ;
int V_62 ;
unsigned long V_313 ;
V_10 = F_8 ( V_9 ) ;
V_62 = F_80 ( V_9 ) ;
F_117 ( V_10 , V_62 , V_285 ) ;
F_125 ( V_10 , V_62 ) ;
V_313 = F_11 ( V_9 ) | V_314 ;
F_128 ( V_62 , ( ( V_313 << 32 ) | V_312 ) ) ;
}
static int F_129 ( void )
{
unsigned long V_222 ;
int V_315 ;
int V_316 ;
int V_176 ;
int V_317 ;
int V_250 ;
unsigned long V_318 ;
if ( F_122 () ) {
V_315 = V_236 & V_319 ;
V_222 = F_38 ( V_320 ) ;
V_176 = ( V_222 >> V_321 ) & V_322 ;
V_222 = F_38 ( V_323 ) ;
V_316 = ( V_222 >> V_324 ) & V_325 ;
V_318 = V_326 [ V_176 ] ;
V_318 *= ( V_315 * V_316 ) ;
V_250 = V_318 / 1000 ;
} else {
V_222 = F_38 ( V_327 ) ;
V_222 = ( V_222 & V_328 ) >> V_329 ;
if ( V_222 & ( 1L << V_330 ) )
V_317 = 80 ;
else
V_317 = 10 ;
V_315 = V_222 & V_331 ;
V_250 = V_315 * V_317 ;
}
return V_250 ;
}
static void T_1 F_130 ( void )
{
int V_5 ;
struct V_6 * V_7 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_144 = 0 ;
if ( V_4 )
V_7 -> V_4 = true ;
V_7 -> V_32 = & F_6 ( V_261 , V_5 ) ;
V_7 -> V_126 = F_34 ( 2 * V_106 ) ;
V_7 -> V_136 = V_136 ;
V_7 -> V_149 = V_136 ;
V_7 -> V_130 = V_130 ;
V_7 -> V_132 = V_132 ;
V_7 -> V_138 = V_138 ;
V_7 -> V_187 = V_187 ;
V_7 -> V_148 = V_148 ;
V_7 -> V_273 = V_252 ;
V_7 -> V_158 = V_253 ;
V_7 -> V_147 = F_33 ( V_147 ) ;
V_7 -> V_165 = V_165 ;
F_131 ( & V_7 -> V_133 ) ;
F_131 ( & V_7 -> V_168 ) ;
F_131 ( & V_7 -> V_143 ) ;
}
}
static int T_1 F_132 ( int V_285 ,
struct V_332 * V_333 ,
unsigned char * V_334 )
{
int V_5 ;
int V_62 ;
int V_9 ;
int V_335 ;
struct V_6 * V_7 ;
struct V_332 * V_336 ;
struct V_337 * V_338 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_62 = F_133 ( V_5 ) -> V_62 ;
if ( ( V_62 - V_285 ) >= V_218 ) {
F_134 (
L_34 ,
V_5 , V_62 , V_285 , V_218 ) ;
return 1 ;
}
V_7 -> V_339 = F_135 ( V_5 ) ;
V_7 -> V_79 = V_285 ;
V_9 = F_133 ( V_5 ) -> V_340 ;
* ( V_334 + ( V_9 / 8 ) ) |= ( 1 << ( V_9 % 8 ) ) ;
V_336 = & V_333 [ V_9 ] ;
V_336 -> V_341 ++ ;
V_336 -> V_9 = V_9 ;
V_336 -> V_62 = V_62 ;
V_335 = V_7 -> V_339 & 1 ;
V_336 -> V_342 |= ( 1 << V_335 ) ;
V_338 = & V_336 -> V_335 [ V_335 ] ;
V_338 -> V_343 [ V_338 -> V_341 ] = V_5 ;
V_338 -> V_341 ++ ;
if ( V_338 -> V_341 > V_344 ) {
F_134 ( L_35 ,
V_338 -> V_341 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_136 ( struct V_6 * V_47 )
{
int V_5 ;
T_9 V_345 = sizeof( struct V_63 ) * F_86 () ;
V_47 -> V_65 = F_118 ( V_345 , V_251 , V_47 -> V_339 ) ;
memset ( V_47 -> V_65 , 0 , V_345 ) ;
F_5 (cpu) {
V_47 -> V_65 [ V_5 ] . V_62 = F_133 ( V_5 ) -> V_62 ;
V_47 -> V_65 [ V_5 ] . V_9 = F_133 ( V_5 ) -> V_340 ;
}
}
static void F_137 ( struct V_6 * V_90 )
{
int V_346 = sizeof( T_2 ) ;
V_90 -> V_77 = F_138 ( V_346 , V_251 , V_90 -> V_339 ) ;
}
static int F_139 ( struct V_337 * V_338 , struct V_332 * V_336 ,
struct V_6 * * V_347 ,
struct V_6 * * V_348 )
{
int V_25 ;
int V_5 ;
struct V_6 * V_7 ;
for ( V_25 = 0 ; V_25 < V_338 -> V_341 ; V_25 ++ ) {
V_5 = V_338 -> V_343 [ V_25 ] ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_5 = V_5 ;
if ( V_25 == 0 ) {
* V_347 = V_7 ;
if ( ! ( * V_348 ) )
* V_348 = V_7 ;
}
V_7 -> V_61 = V_336 -> V_341 ;
V_7 -> V_58 = V_338 -> V_341 ;
V_7 -> V_48 = * V_347 ;
V_7 -> V_9 = V_336 -> V_9 ;
if ( F_122 () )
V_7 -> V_129 = 1 ;
else if ( F_83 () )
V_7 -> V_129 = 2 ;
else if ( F_84 () )
V_7 -> V_129 = 3 ;
else if ( F_140 () )
V_7 -> V_129 = 4 ;
else {
F_134 ( L_36 ) ;
return 1 ;
}
V_7 -> V_55 = * V_348 ;
V_7 -> V_114 = F_141 ( V_5 ) ;
if ( V_7 -> V_114 >= V_349 ) {
F_134 ( L_37 ,
V_7 -> V_114 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_142 ( int V_233 ,
struct V_332 * V_333 ,
unsigned char * V_334 )
{
int V_335 ;
int V_9 ;
unsigned short V_342 ;
for ( V_9 = 0 ; V_9 < V_233 ; V_9 ++ ) {
struct V_332 * V_336 ;
struct V_6 * V_47 = NULL ;
struct V_6 * V_90 = NULL ;
if ( ! ( * ( V_334 + ( V_9 / 8 ) ) & ( 1 << ( V_9 % 8 ) ) ) )
continue;
V_336 = & V_333 [ V_9 ] ;
V_342 = V_336 -> V_342 ;
V_335 = 0 ;
while ( V_342 ) {
struct V_337 * V_338 ;
if ( ( V_342 & 1 ) ) {
V_338 = & V_336 -> V_335 [ V_335 ] ;
if ( F_139 ( V_338 , V_336 , & V_47 , & V_90 ) )
return 1 ;
F_136 ( V_47 ) ;
}
V_335 ++ ;
V_342 = ( V_342 >> 1 ) ;
}
F_137 ( V_90 ) ;
}
return 0 ;
}
static int T_1 F_143 ( int V_233 , int V_350 )
{
unsigned char * V_334 ;
void * V_303 ;
struct V_332 * V_333 ;
if ( F_84 () || F_83 () || F_122 () )
V_106 = F_129 () ;
V_303 = F_144 ( V_233 * sizeof( struct V_332 ) , V_251 ) ;
V_333 = (struct V_332 * ) V_303 ;
memset ( V_333 , 0 , V_233 * sizeof( struct V_332 ) ) ;
V_334 = F_145 ( ( V_233 + 7 ) / 8 , V_251 ) ;
if ( F_132 ( V_350 , V_333 , V_334 ) )
goto V_351;
if ( F_142 ( V_233 , V_333 , V_334 ) )
goto V_351;
F_97 ( V_333 ) ;
F_97 ( V_334 ) ;
F_130 () ;
return 0 ;
V_351:
F_97 ( V_333 ) ;
F_97 ( V_334 ) ;
return 1 ;
}
static int T_1 F_146 ( void )
{
int V_9 ;
int V_62 ;
int V_233 ;
int V_352 ;
int V_353 ;
int V_312 ;
T_10 * V_76 ;
if ( ! F_112 () )
return 0 ;
if ( F_140 () )
V_22 = V_354 ;
else if ( F_84 () )
V_22 = V_355 ;
else if ( F_83 () )
V_22 = V_355 ;
else if ( F_122 () )
V_22 = V_355 ;
F_147 (cur_cpu) {
V_76 = & F_6 ( V_214 , V_352 ) ;
F_148 ( V_76 , V_251 , F_135 ( V_352 ) ) ;
}
V_233 = F_78 () ;
V_157 = F_34 ( V_252 ) ;
V_356 = 0x7fffffff ;
for ( V_9 = 0 ; V_9 < V_233 ; V_9 ++ ) {
V_353 = F_79 ( V_9 ) ;
if ( V_353 && ( F_80 ( V_9 ) < V_356 ) )
V_356 = F_80 ( V_9 ) ;
}
if ( F_84 () || F_83 () || F_122 () )
F_77 () ;
if ( F_143 ( V_233 , V_356 ) ) {
F_7 () ;
V_8 = 1 ;
return 0 ;
}
V_312 = V_357 ;
F_149 (uvhub) {
if ( F_79 ( V_9 ) )
F_127 ( V_9 , V_312 , V_356 ) ;
}
F_150 ( V_312 , V_358 ) ;
F_149 (uvhub) {
if ( F_79 ( V_9 ) ) {
unsigned long V_263 ;
unsigned long V_28 ;
V_62 = F_80 ( V_9 ) ;
V_263 = 1L << 63 ;
F_151 ( V_62 , V_263 ) ;
V_28 = 1 ;
if ( ! F_122 () )
F_152 ( V_62 , V_28 ) ;
}
}
return 0 ;
}
