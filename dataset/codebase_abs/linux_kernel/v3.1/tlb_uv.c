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
static int F_17 ( int V_55 , struct V_10 * V_40 )
{
int V_6 ;
struct V_56 * V_57 ;
F_6 (cpu) {
V_57 = & V_40 -> V_58 [ V_6 ] ;
if ( V_55 == V_57 -> V_55 )
return V_6 ;
}
return - 1 ;
}
static void F_18 ( void * V_59 )
{
int V_19 ;
struct V_10 * V_11 = & F_8 ( V_10 , F_19 () ) ;
struct V_60 * V_61 = (struct V_60 * ) V_59 ;
struct V_13 * V_14 ;
struct V_24 * V_25 = V_11 -> V_26 ;
V_25 -> V_62 ++ ;
for ( V_14 = V_11 -> V_30 , V_19 = 0 ; V_19 < V_28 ; V_14 ++ , V_19 ++ ) {
unsigned long V_21 ;
if ( ( V_14 -> V_18 == 0 ) &&
( V_14 -> V_15 == 0 ) &&
( V_14 -> V_31 == V_61 -> V_63 ) &&
( V_14 -> V_16 ) &&
( V_14 -> V_32 != V_33 ) ) {
unsigned long V_22 ;
unsigned long V_34 ;
V_14 -> V_15 = 1 ;
V_22 = F_12 () ;
V_21 = V_14 -> V_16 ;
V_34 = ( V_21 << V_17 ) | V_21 ;
if ( V_22 & V_21 ) {
V_25 -> V_64 ++ ;
F_10 ( V_34 ) ;
}
}
}
return;
}
static void F_20 ( struct V_65 * V_66 , struct V_10 * V_11 )
{
int V_55 ;
int V_67 ;
int V_68 ;
int V_63 = V_11 -> V_6 ;
T_2 * V_69 = V_11 -> V_48 -> V_70 ;
struct V_10 * V_40 = V_11 -> V_41 ;
struct V_60 V_60 ;
V_60 . V_63 = V_63 ;
F_21 ( * V_69 ) ;
V_68 = sizeof( struct V_65 ) * V_71 ;
for ( V_55 = 0 ; V_55 < V_68 ; V_55 ++ ) {
int V_6 ;
if ( ! F_22 ( V_55 , V_66 ) )
continue;
V_67 = V_55 + V_11 -> V_72 ;
V_6 = F_17 ( V_67 , V_40 ) ;
F_23 ( V_6 , * V_69 ) ;
}
F_24 ( V_69 , F_18 , ( void * ) & V_60 , 1 ) ;
return;
}
static inline unsigned long F_25 ( unsigned long long V_73 )
{
unsigned long long V_74 ;
unsigned long V_75 ;
int V_6 = F_19 () ;
V_74 = ( V_73 * F_8 ( V_76 , V_6 ) ) >> V_77 ;
V_75 = V_74 / 1000 ;
return V_75 ;
}
static inline void F_26 ( struct V_10 * V_78 )
{
F_16 ( 1 , (struct atomic_short * ) & V_78 -> V_79 ) ;
}
static inline void F_27 ( struct V_10 * V_78 )
{
F_16 ( - 1 , (struct atomic_short * ) & V_78 -> V_79 ) ;
}
static unsigned long F_28 ( unsigned long V_80 , int V_81 )
{
unsigned long V_82 ;
V_82 = F_29 ( V_80 ) ;
V_82 >>= V_81 ;
V_82 &= V_83 ;
return V_82 ;
}
static int F_30 ( struct V_84 * V_84 ,
unsigned long V_80 , int V_81 ,
struct V_10 * V_11 , long V_85 )
{
unsigned long V_82 ;
T_3 V_86 ;
struct V_24 * V_25 = V_11 -> V_26 ;
V_82 = F_28 ( V_80 , V_81 ) ;
while ( ( V_82 != V_87 ) ) {
if ( V_82 == V_88 ) {
V_25 -> V_89 ++ ;
return V_90 ;
} else if ( V_82 == V_91 ) {
V_25 -> V_92 ++ ;
V_86 = F_31 () ;
if ( F_25 ( V_86 - V_11 -> V_93 ) < V_94 ) {
V_11 -> V_95 = 0 ;
return V_96 ;
}
V_11 -> V_95 = 0 ;
return V_97 ;
} else {
F_32 () ;
}
V_82 = F_28 ( V_80 , V_81 ) ;
}
V_11 -> V_95 ++ ;
return V_98 ;
}
static unsigned long F_33 ( unsigned long V_99 , int V_100 , int V_6 )
{
unsigned long V_82 ;
unsigned long V_101 ;
V_82 = ( ( F_34 ( V_99 ) >> V_100 ) & V_83 ) ;
V_101 = ( F_35 () >> V_6 ) & 0x1UL ;
V_82 = ( V_82 << 1 ) | V_101 ;
return V_82 ;
}
static int F_36 ( struct V_84 * V_84 ,
unsigned long V_80 , int V_81 ,
struct V_10 * V_11 , long V_85 )
{
unsigned long V_102 ;
T_3 V_86 ;
int V_6 = V_11 -> V_103 ;
struct V_24 * V_25 = V_11 -> V_26 ;
V_102 = F_33 ( V_80 , V_81 , V_6 ) ;
while ( V_102 != V_104 ) {
if ( ( V_102 == V_105 ) ||
( V_102 == V_106 ) ||
( V_102 == V_107 ) ) {
V_25 -> V_89 ++ ;
return V_90 ;
} else if ( V_102 == V_108 ) {
V_25 -> V_92 ++ ;
V_86 = F_31 () ;
if ( F_25 ( V_86 - V_11 -> V_93 ) < V_94 ) {
V_11 -> V_95 = 0 ;
return V_96 ;
}
V_11 -> V_95 = 0 ;
return V_97 ;
} else {
F_32 () ;
}
V_102 = F_33 ( V_80 , V_81 , V_6 ) ;
}
V_11 -> V_95 ++ ;
return V_98 ;
}
static int F_37 ( struct V_84 * V_84 ,
struct V_10 * V_11 , long V_85 )
{
int V_81 ;
unsigned long V_80 ;
int V_6 = V_11 -> V_103 ;
if ( V_6 < V_109 ) {
V_80 = V_110 ;
V_81 = V_6 * V_111 ;
} else {
V_80 = V_112 ;
V_81 = ( ( V_6 - V_109 ) * V_111 ) ;
}
if ( F_38 () )
return F_30 ( V_84 , V_80 , V_81 ,
V_11 , V_85 ) ;
else
return F_36 ( V_84 , V_80 , V_81 ,
V_11 , V_85 ) ;
}
static inline T_3 F_39 ( unsigned long V_113 )
{
unsigned long V_74 ;
T_3 V_73 ;
V_74 = V_113 * 1000000000 ;
V_73 = ( V_74 << V_77 ) / ( F_8 ( V_76 , F_19 () ) ) ;
return V_73 ;
}
static void F_40 ( struct V_84 * V_84 ,
struct V_10 * V_11 ,
struct V_10 * V_78 , struct V_24 * V_25 )
{
F_41 ( V_11 -> V_114 ) ;
V_11 -> V_115 ++ ;
if ( V_11 -> V_115 >= V_11 -> V_116 ) {
V_11 -> V_115 = 0 ;
F_26 ( V_78 ) ;
F_42 ( & V_78 -> V_117 ) ;
F_20 ( & V_84 -> V_66 , V_11 ) ;
F_43 ( & V_78 -> V_117 ) ;
F_27 ( V_78 ) ;
V_11 -> V_118 ++ ;
V_25 -> V_119 ++ ;
}
}
static void F_44 ( struct V_84 * V_84 ,
struct V_10 * V_11 , struct V_10 * V_78 ,
struct V_24 * V_25 )
{
V_78 -> V_120 = 1 ;
V_11 -> V_121 ++ ;
if ( V_11 -> V_121 >= V_11 -> V_122 ) {
V_11 -> V_121 = 0 ;
F_26 ( V_78 ) ;
F_42 ( & V_78 -> V_117 ) ;
F_20 ( & V_84 -> V_66 , V_11 ) ;
F_43 ( & V_78 -> V_117 ) ;
F_27 ( V_78 ) ;
V_11 -> V_118 ++ ;
V_25 -> V_123 ++ ;
}
}
static void F_45 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
F_42 ( & V_124 ) ;
if ( ! V_125 && V_11 -> V_126 &&
( ( V_11 -> V_127 / V_11 -> V_126 ) > V_128 ) ) {
int V_129 ;
struct V_10 * V_130 ;
V_125 = 1 ;
V_11 -> V_131 = 1 ;
V_11 -> V_132 = F_31 () ;
V_11 -> V_132 += F_39 ( V_11 -> V_133 ) ;
V_25 -> V_134 ++ ;
F_6 (tcpu) {
V_130 = & F_8 ( V_10 , V_129 ) ;
V_130 -> V_125 = 1 ;
}
}
F_43 ( & V_124 ) ;
}
static void F_46 ( int V_25 , struct V_10 * V_11 ,
struct V_10 * V_78 )
{
V_11 -> V_115 = 0 ;
V_11 -> V_121 = 0 ;
if ( V_25 != V_98 )
return;
if ( V_11 -> V_95 <= V_11 -> V_135 )
return;
if ( V_78 -> V_120 >= V_78 -> V_136 )
return;
V_78 -> V_120 ++ ;
}
static void F_47 ( T_3 V_137 , T_3 V_138 ,
struct V_10 * V_11 , struct V_24 * V_25 ,
int V_139 , int V_85 )
{
T_3 V_140 ;
if ( V_138 > V_137 ) {
V_140 = V_138 - V_137 ;
V_25 -> V_141 += V_140 ;
if ( ( V_139 == V_98 ) && ( V_85 == 1 ) ) {
V_11 -> V_126 ++ ;
V_11 -> V_127 += V_140 ;
if ( ( V_140 > V_128 ) &&
( V_11 -> V_126 > V_11 -> V_142 ) )
F_45 ( V_11 , V_25 ) ;
}
} else
V_25 -> V_143 -- ;
if ( V_139 == V_98 && V_85 > 1 )
V_25 -> V_144 ++ ;
else if ( V_139 == V_90 )
V_25 -> V_145 ++ ;
}
static void F_48 ( struct V_10 * V_78 , struct V_24 * V_25 )
{
T_4 * V_146 = & V_78 -> V_147 ;
T_5 * V_148 ;
V_148 = & V_78 -> V_149 ;
if ( ! F_49 ( V_146 , V_148 , V_78 -> V_120 ) ) {
V_25 -> V_150 ++ ;
do {
F_32 () ;
} while ( ! F_49 ( V_146 , V_148 , V_78 -> V_120 ) );
}
}
static void F_50 ( int V_139 , struct V_84 * V_84 ,
struct V_10 * V_11 , struct V_10 * V_78 ,
struct V_24 * V_25 )
{
if ( V_139 == V_96 )
F_40 ( V_84 , V_11 , V_78 , V_25 ) ;
else if ( V_139 == V_97 )
F_44 ( V_84 , V_11 , V_78 , V_25 ) ;
}
int F_51 ( struct V_84 * V_84 ,
struct V_70 * V_151 , struct V_10 * V_11 )
{
int V_152 = 0 ;
int V_153 = 0 ;
long V_85 = 0 ;
unsigned long V_154 ;
T_3 V_137 ;
T_3 V_138 ;
struct V_24 * V_25 = V_11 -> V_26 ;
struct V_10 * V_78 = V_11 -> V_48 ;
if ( F_38 () )
F_48 ( V_78 , V_25 ) ;
while ( V_78 -> V_79 )
F_32 () ;
V_137 = F_31 () ;
do {
if ( V_85 == 0 ) {
V_84 -> V_155 . V_32 = V_156 ;
V_152 = V_11 -> V_157 ++ ;
} else {
V_84 -> V_155 . V_32 = V_47 ;
V_25 -> V_158 ++ ;
}
V_84 -> V_155 . V_159 = V_152 ;
V_154 = ( 1UL << V_160 ) | V_11 -> V_103 ;
V_11 -> V_93 = F_31 () ;
F_52 ( V_154 ) ;
V_85 ++ ;
V_153 = F_37 ( V_84 , V_11 , V_85 ) ;
F_50 ( V_153 , V_84 , V_11 , V_78 , V_25 ) ;
if ( V_11 -> V_118 >= V_11 -> V_161 ) {
V_11 -> V_118 = 0 ;
V_153 = V_90 ;
break;
}
F_32 () ;
} while ( ( V_153 == V_96 ) ||
( V_153 == V_97 ) );
V_138 = F_31 () ;
F_46 ( V_153 , V_11 , V_78 ) ;
while ( V_78 -> V_79 )
F_32 () ;
F_53 ( & V_78 -> V_149 ) ;
F_47 ( V_137 , V_138 , V_11 , V_25 , V_153 , V_85 ) ;
if ( V_153 == V_90 )
return 1 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , struct V_24 * V_25 )
{
int V_129 ;
struct V_10 * V_130 ;
if ( V_11 -> V_131 ) {
if ( F_31 () >= V_11 -> V_132 ) {
V_25 -> V_162 ++ ;
V_125 = 0 ;
F_6 (tcpu) {
V_130 = & F_8 ( V_10 , V_129 ) ;
V_130 -> V_125 = 0 ;
V_130 -> V_126 = 0 ;
V_130 -> V_127 = 0 ;
}
return 0 ;
}
}
return - 1 ;
}
static void F_55 ( struct V_24 * V_25 , int V_163 , int V_164 ,
int V_165 , struct V_84 * V_84 )
{
V_25 -> V_143 ++ ;
V_25 -> V_166 += V_165 + V_163 ;
V_25 -> V_167 += V_165 ;
V_25 -> V_168 += V_163 ;
V_164 = F_56 ( & V_84 -> V_66 ) ;
if ( V_163 ) {
V_25 -> V_169 ++ ;
V_25 -> V_170 += ( V_164 - 1 ) ;
} else
V_25 -> V_170 += V_164 ;
V_25 -> V_171 += V_164 ;
if ( V_164 >= 16 )
V_25 -> V_172 ++ ;
else if ( V_164 >= 8 )
V_25 -> V_173 ++ ;
else if ( V_164 >= 4 )
V_25 -> V_174 ++ ;
else if ( V_164 >= 2 )
V_25 -> V_175 ++ ;
else
V_25 -> V_176 ++ ;
}
static int F_57 ( struct V_70 * V_151 , struct V_10 * V_11 ,
struct V_84 * V_84 , int * V_177 , int * V_178 )
{
int V_6 ;
int V_55 ;
int V_179 = 0 ;
struct V_56 * V_57 ;
F_58 (cpu, flush_mask) {
V_57 = & V_11 -> V_41 -> V_58 [ V_6 ] ;
V_55 = V_57 -> V_55 - V_11 -> V_72 ;
F_59 ( V_55 , & V_84 -> V_66 ) ;
V_179 ++ ;
if ( V_57 -> V_3 == V_11 -> V_3 )
( * V_177 ) ++ ;
else
( * V_178 ) ++ ;
}
if ( ! V_179 )
return 1 ;
return 0 ;
}
const struct V_70 * F_60 ( const struct V_70 * V_70 ,
struct V_180 * V_181 , unsigned long V_182 ,
unsigned int V_6 )
{
int V_163 = 0 ;
int V_165 = 0 ;
int V_164 = 0 ;
struct V_84 * V_84 ;
struct V_70 * V_151 ;
struct V_24 * V_25 ;
struct V_10 * V_11 ;
if ( V_2 )
return V_70 ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_25 = V_11 -> V_26 ;
if ( V_11 -> V_125 ) {
if ( F_54 ( V_11 , V_25 ) )
return V_70 ;
}
V_151 = (struct V_70 * ) F_8 ( V_183 , V_6 ) ;
F_61 ( V_151 , V_70 , F_62 ( V_6 ) ) ;
if ( F_63 ( V_6 , * V_70 ) )
V_25 -> V_184 ++ ;
V_84 = V_11 -> V_185 ;
V_84 += V_186 * V_11 -> V_103 ;
F_64 ( & V_84 -> V_66 , V_187 ) ;
if ( F_57 ( V_151 , V_11 , V_84 , & V_163 , & V_165 ) )
return NULL ;
F_55 ( V_25 , V_163 , V_164 , V_165 , V_84 ) ;
V_84 -> V_188 . V_42 = V_182 ;
V_84 -> V_188 . V_31 = V_6 ;
if ( ! F_51 ( V_84 , V_151 , V_11 ) )
return NULL ;
else
return V_70 ;
}
void F_65 ( struct V_189 * V_190 )
{
int V_191 = 0 ;
T_3 V_192 ;
struct V_13 * V_14 ;
struct V_10 * V_11 ;
struct V_24 * V_25 ;
struct V_8 V_193 ;
V_192 = F_31 () ;
V_11 = & F_8 ( V_10 , F_19 () ) ;
V_25 = V_11 -> V_26 ;
V_193 . V_30 = V_11 -> V_30 ;
V_193 . V_29 = V_11 -> V_29 ;
V_14 = V_11 -> V_194 ;
while ( V_14 -> V_16 ) {
V_191 ++ ;
V_193 . V_50 = V_14 - V_193 . V_30 ;
V_193 . V_195 = F_66 ( V_14 -> V_16 ) - 1 ;
V_193 . V_14 = V_14 ;
F_13 ( & V_193 , V_11 ) ;
V_14 ++ ;
if ( V_14 > V_193 . V_29 )
V_14 = V_193 . V_30 ;
V_11 -> V_194 = V_14 ;
}
V_25 -> V_196 += ( F_31 () - V_192 ) ;
if ( ! V_191 )
V_25 -> V_197 ++ ;
else if ( V_191 > 1 )
V_25 -> V_198 ++ ;
F_67 () ;
}
static void T_1 F_68 ( void )
{
int V_3 ;
int V_199 ;
int V_55 ;
unsigned long V_200 ;
V_199 = F_69 () ;
for ( V_3 = 0 ; V_3 < V_199 ; V_3 ++ ) {
if ( ! F_70 ( V_3 ) )
continue;
V_55 = F_71 ( V_3 ) ;
V_200 = F_72 ( V_55 ) ;
V_200 &= ~ ( 1L << V_201 ) ;
F_73 ( V_55 , V_200 ) ;
V_200 &= ~ ( ( unsigned long ) 0xf << V_202 ) ;
V_200 |= ( V_203 << V_202 ) ;
F_73 ( V_55 , V_200 ) ;
V_200 |= ( 1L << V_201 ) ;
if ( F_74 () ) {
V_200 |= ( 1L << V_204 ) ;
V_200 |= ( 1L << V_205 ) ;
}
F_73 ( V_55 , V_200 ) ;
}
}
static void * F_75 ( struct V_206 * V_207 , T_6 * V_99 )
{
if ( * V_99 < F_76 () )
return V_99 ;
return NULL ;
}
static void * F_77 ( struct V_206 * V_207 , void * V_208 , T_6 * V_99 )
{
( * V_99 ) ++ ;
if ( * V_99 < F_76 () )
return V_99 ;
return NULL ;
}
static void F_78 ( struct V_206 * V_207 , void * V_208 )
{
}
static inline unsigned long long F_79 ( unsigned long V_209 )
{
unsigned long V_74 ;
unsigned long long V_73 ;
V_74 = V_209 * 1000 ;
V_73 = ( V_74 << V_77 ) / ( F_8 ( V_76 , F_19 () ) ) ;
return V_73 ;
}
static int F_80 ( struct V_206 * V_207 , void * V_208 )
{
struct V_24 * V_25 ;
int V_6 ;
V_6 = * ( T_6 * ) V_208 ;
if ( ! V_6 ) {
F_81 ( V_207 ,
L_1 ) ;
F_81 ( V_207 ,
L_2 ) ;
F_81 ( V_207 ,
L_3 ) ;
F_81 ( V_207 ,
L_4 ) ;
F_81 ( V_207 ,
L_5 ) ;
F_81 ( V_207 ,
L_6 ) ;
}
if ( V_6 < F_76 () && F_82 ( V_6 ) ) {
V_25 = & F_8 ( V_210 , V_6 ) ;
F_81 ( V_207 ,
L_7 ,
V_6 , V_25 -> V_143 , F_25 ( V_25 -> V_141 ) ,
V_25 -> V_184 , V_25 -> V_168 ,
V_25 -> V_167 , V_25 -> V_166 ,
V_25 -> V_169 , V_25 -> V_170 ,
V_25 -> V_171 , V_25 -> V_172 ) ;
F_81 ( V_207 , L_8 ,
V_25 -> V_173 , V_25 -> V_174 ,
V_25 -> V_175 , V_25 -> V_176 ,
V_25 -> V_92 ) ;
F_81 ( V_207 , L_9 ,
V_25 -> V_158 , V_25 -> V_144 ,
V_25 -> V_119 , V_25 -> V_123 ,
V_25 -> V_145 , V_25 -> V_89 ,
V_25 -> V_211 , V_25 -> V_150 ) ;
F_81 ( V_207 ,
L_10 ,
F_83 ( F_84 ( V_6 ) ) ,
V_25 -> V_46 , F_25 ( V_25 -> V_196 ) ,
V_25 -> V_44 , V_25 -> V_45 , V_25 -> V_198 ,
V_25 -> V_197 , V_25 -> V_27 , V_25 -> V_35 ,
V_25 -> V_36 , V_25 -> V_62 ,
V_25 -> V_64 ) ;
F_81 ( V_207 , L_11 ,
V_25 -> V_134 , V_25 -> V_162 ) ;
}
return 0 ;
}
static T_7 F_85 ( struct V_207 * V_207 , char T_8 * V_212 ,
T_9 V_191 , T_6 * V_213 )
{
char * V_214 ;
int V_215 ;
V_214 = F_86 ( V_216 , L_12 ,
L_13 ,
L_14 ,
L_15 ,
V_120 , V_114 , V_116 ,
V_122 , V_161 , V_135 ,
V_217 , V_218 , V_219 ) ;
if ( ! V_214 )
return - V_220 ;
V_215 = F_87 ( V_212 , V_191 , V_213 , V_214 , strlen ( V_214 ) ) ;
F_88 ( V_214 ) ;
return V_215 ;
}
static T_7 F_89 ( struct V_207 * V_207 , const char T_8 * V_221 ,
T_9 V_191 , T_6 * V_208 )
{
int V_6 ;
int V_19 ;
int V_222 ;
long V_223 ;
char V_224 [ 64 ] ;
struct V_24 * V_25 ;
if ( V_191 == 0 || V_191 > sizeof( V_224 ) )
return - V_225 ;
if ( F_90 ( V_224 , V_221 , V_191 ) )
return - V_226 ;
V_224 [ V_191 - 1 ] = '\0' ;
if ( F_91 ( V_224 , 10 , & V_223 ) < 0 ) {
F_92 ( V_227 L_16 , V_224 ) ;
return - V_225 ;
}
if ( V_223 == 0 ) {
V_222 = sizeof( V_228 ) / sizeof( * V_228 ) ;
F_92 ( V_227 L_17 ) ;
F_92 ( V_227 L_18 ) ;
for ( V_19 = 0 ; V_19 < V_222 ; V_19 ++ )
F_92 ( V_227 L_19 , V_228 [ V_19 ] ) ;
} else if ( V_223 == - 1 ) {
F_6 (cpu) {
V_25 = & F_8 ( V_210 , V_6 ) ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
}
}
return V_191 ;
}
static int F_93 ( const char * V_229 )
{
int V_230 = 0 ;
for (; ; V_229 ++ ) {
switch ( * V_229 ) {
case '0' ... '9' :
V_230 = 10 * V_230 + ( * V_229 - '0' ) ;
break;
default:
return V_230 ;
}
}
}
static int F_94 ( struct V_10 * V_11 , char * V_231 ,
int V_191 )
{
char * V_232 ;
char * V_233 ;
int V_179 = 0 ;
int V_230 ;
int V_234 = sizeof( V_235 ) / sizeof( * V_235 ) ;
V_232 = V_231 + strspn ( V_231 , V_236 ) ;
V_233 = V_232 ;
for (; * V_232 ; V_232 = V_233 + strspn ( V_233 , V_236 ) ) {
V_233 = V_232 + strcspn ( V_232 , V_236 ) ;
V_179 ++ ;
if ( V_233 == V_232 )
break;
}
if ( V_179 != V_234 ) {
F_92 ( V_237 L_20 , V_234 ) ;
return - V_225 ;
}
V_232 = V_231 + strspn ( V_231 , V_236 ) ;
V_233 = V_232 ;
for ( V_179 = 0 ; * V_232 ; V_232 = V_233 + strspn ( V_233 , V_236 ) , V_179 ++ ) {
V_233 = V_232 + strcspn ( V_232 , V_236 ) ;
V_230 = F_93 ( V_232 ) ;
switch ( V_179 ) {
case 0 :
if ( V_230 == 0 ) {
V_120 = V_238 ;
V_136 = V_238 ;
continue;
}
if ( V_230 < 1 || V_230 > V_11 -> V_54 ) {
F_92 ( V_227
L_21 ,
V_230 ) ;
return - V_225 ;
}
V_120 = V_230 ;
V_136 = V_230 ;
continue;
default:
if ( V_230 == 0 )
* V_235 [ V_179 ] . V_239 = V_235 [ V_179 ] . V_240 ;
else
* V_235 [ V_179 ] . V_239 = V_230 ;
continue;
}
if ( V_233 == V_232 )
break;
}
return 0 ;
}
static T_7 F_95 ( struct V_207 * V_207 , const char T_8 * V_221 ,
T_9 V_191 , T_6 * V_208 )
{
int V_6 ;
int V_215 ;
char V_231 [ 100 ] ;
struct V_10 * V_11 ;
if ( V_191 == 0 || V_191 > sizeof( V_231 ) - 1 )
return - V_225 ;
if ( F_90 ( V_231 , V_221 , V_191 ) )
return - V_226 ;
V_231 [ V_191 ] = '\0' ;
V_6 = F_96 () ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_215 = F_94 ( V_11 , V_231 , V_191 ) ;
F_97 () ;
if ( V_215 )
return V_215 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_120 = V_120 ;
V_11 -> V_136 = V_120 ;
V_11 -> V_114 = V_114 ;
V_11 -> V_116 = V_116 ;
V_11 -> V_122 = V_122 ;
V_11 -> V_161 = V_161 ;
V_11 -> V_135 = V_135 ;
V_11 -> V_241 = V_217 ;
V_11 -> V_142 = V_218 ;
V_11 -> V_133 = V_219 ;
}
return V_191 ;
}
static int F_98 ( struct V_242 * V_242 , struct V_207 * V_207 )
{
return F_99 ( V_207 , & V_243 ) ;
}
static int F_100 ( struct V_242 * V_242 , struct V_207 * V_207 )
{
return 0 ;
}
static int T_1 F_101 ( void )
{
struct V_244 * V_245 ;
if ( ! F_102 () )
return 0 ;
V_245 = F_103 ( V_246 , 0444 , NULL ,
& V_247 ) ;
if ( ! V_245 ) {
F_92 ( V_248 L_22 ,
V_246 ) ;
return - V_225 ;
}
V_249 = F_104 ( V_250 , NULL ) ;
if ( ! V_249 ) {
F_92 ( V_248 L_23 ,
V_250 ) ;
return - V_225 ;
}
V_251 = F_105 ( V_252 , 0600 ,
V_249 , NULL , & V_253 ) ;
if ( ! V_251 ) {
F_92 ( V_248 L_24 ,
V_252 ) ;
return - V_225 ;
}
return 0 ;
}
static void F_106 ( int V_4 , int V_55 , int V_254 )
{
int V_19 ;
int V_6 ;
unsigned long V_255 ;
unsigned long V_256 ;
unsigned long V_257 ;
T_9 V_258 ;
struct V_84 * V_84 ;
struct V_84 * V_259 ;
struct V_10 * V_11 ;
V_258 = sizeof( struct V_84 ) * V_260 * V_186 ;
V_84 = F_107 ( V_258 , V_216 , V_4 ) ;
F_108 ( ! V_84 ) ;
V_255 = F_109 ( V_84 ) ;
V_257 = V_255 >> V_261 ;
V_256 = V_255 & V_262 ;
F_110 ( V_55 , ( V_257 << V_263 | V_256 ) ) ;
for ( V_19 = 0 , V_259 = V_84 ; V_19 < ( V_260 * V_186 ) ; V_19 ++ , V_259 ++ ) {
memset ( V_259 , 0 , sizeof( struct V_84 ) ) ;
V_259 -> V_155 . V_264 = 1 ;
V_259 -> V_155 . V_265 = F_111 ( V_254 ) ;
V_259 -> V_155 . V_266 = V_267 ;
V_259 -> V_155 . V_268 = V_269 ;
V_259 -> V_155 . V_270 = 1 ;
}
F_6 (cpu) {
if ( V_55 != F_71 ( F_7 ( V_6 ) ) )
continue;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_185 = V_84 ;
}
}
static void F_112 ( int V_4 , int V_55 )
{
int V_6 ;
T_9 V_271 ;
char * V_272 ;
void * V_273 ;
unsigned long V_274 ;
unsigned long V_275 ;
unsigned long V_276 ;
unsigned long V_277 ;
struct V_13 * V_278 ;
struct V_10 * V_11 ;
V_271 = ( V_28 + 1 ) * sizeof( struct V_13 ) ;
V_273 = F_107 ( V_271 , V_216 , V_4 ) ;
V_278 = (struct V_13 * ) V_273 ;
F_108 ( ! V_278 ) ;
V_272 = ( char * ) V_278 + 31 ;
V_278 = (struct V_13 * ) ( ( ( unsigned long ) V_272 >> 5 ) << 5 ) ;
F_6 (cpu) {
if ( V_55 != F_84 ( V_6 ) )
continue;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_30 = V_278 ;
V_11 -> V_194 = V_278 ;
V_11 -> V_29 = V_278 + ( V_28 - 1 ) ;
}
V_274 = F_109 ( V_278 ) >> V_261 ;
V_275 = F_113 ( V_278 ) ;
V_276 = ( ( unsigned long ) V_274 << V_279 ) | V_275 ;
V_277 = F_113 ( V_278 + ( V_28 - 1 ) ) ;
F_114 ( V_55 , V_276 ) ;
F_115 ( V_55 , V_275 ) ;
F_116 ( V_55 , V_277 ) ;
memset ( V_278 , 0 , sizeof( struct V_13 ) * V_28 ) ;
}
static void T_1 F_117 ( int V_3 , int V_280 , int V_254 )
{
int V_4 ;
int V_55 ;
unsigned long V_281 ;
V_4 = F_2 ( V_3 ) ;
V_55 = F_71 ( V_3 ) ;
F_106 ( V_4 , V_55 , V_254 ) ;
F_112 ( V_4 , V_55 ) ;
V_281 = F_5 ( V_3 ) | V_282 ;
F_118 ( V_55 , ( ( V_281 << 32 ) | V_280 ) ) ;
}
static int F_119 ( void )
{
unsigned long V_200 ;
int V_283 ;
int V_284 ;
int V_154 ;
int V_285 ;
int V_215 ;
unsigned long V_286 ;
if ( F_38 () ) {
V_283 = V_203 & V_287 ;
V_200 = F_29 ( V_288 ) ;
V_154 = ( V_200 >> V_289 ) & V_290 ;
V_200 = F_29 ( V_291 ) ;
V_284 = ( V_200 >> V_292 ) & V_293 ;
V_285 = V_294 [ V_154 ] ;
V_286 = V_285 * V_283 * V_284 ;
V_215 = V_286 / 1000 ;
} else {
V_200 = F_29 ( V_288 ) ;
V_200 = ( V_200 & V_295 ) >> V_296 ;
if ( V_200 & ( 1L << V_297 ) )
V_283 = 80 ;
else
V_283 = 10 ;
V_285 = V_200 & V_298 ;
V_215 = V_283 * V_285 ;
}
return V_215 ;
}
static void T_1 F_120 ( void )
{
int V_6 ;
struct V_10 * V_11 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_125 = 0 ;
V_11 -> V_26 = & F_8 ( V_210 , V_6 ) ;
V_11 -> V_299 = F_79 ( 2 * V_94 ) ;
V_11 -> V_120 = V_120 ;
V_11 -> V_136 = V_120 ;
V_11 -> V_114 = V_114 ;
V_11 -> V_116 = V_116 ;
V_11 -> V_122 = V_122 ;
V_11 -> V_161 = V_161 ;
V_11 -> V_135 = V_135 ;
V_11 -> V_241 = V_217 ;
V_11 -> V_142 = V_218 ;
V_11 -> V_133 = V_219 ;
}
}
static int T_1 F_121 ( int V_254 ,
struct V_300 * V_301 ,
unsigned char * V_302 )
{
int V_6 ;
int V_55 ;
int V_3 ;
int V_303 ;
struct V_10 * V_11 ;
struct V_300 * V_304 ;
struct V_305 * V_306 ;
F_6 (cpu) {
V_11 = & F_8 ( V_10 , V_6 ) ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_55 = F_122 ( V_6 ) -> V_55 ;
if ( ( V_55 - V_254 ) >= V_187 ) {
F_92 ( V_307
L_25 ,
V_6 , V_55 , V_254 , V_187 ) ;
return 1 ;
}
V_11 -> V_308 = F_123 ( V_6 ) ;
V_11 -> V_72 = V_254 ;
V_3 = F_122 ( V_6 ) -> V_309 ;
* ( V_302 + ( V_3 / 8 ) ) |= ( 1 << ( V_3 % 8 ) ) ;
V_304 = & V_301 [ V_3 ] ;
V_304 -> V_310 ++ ;
V_304 -> V_3 = V_3 ;
V_304 -> V_55 = V_55 ;
V_303 = V_11 -> V_308 & 1 ;
V_304 -> V_311 |= ( 1 << V_303 ) ;
V_306 = & V_304 -> V_303 [ V_303 ] ;
V_306 -> V_312 [ V_306 -> V_310 ] = V_6 ;
V_306 -> V_310 ++ ;
if ( V_306 -> V_310 > V_313 ) {
F_92 ( V_307 L_26 ,
V_306 -> V_310 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_124 ( struct V_10 * V_40 )
{
int V_6 ;
T_9 V_314 = sizeof( struct V_56 ) * F_76 () ;
V_40 -> V_58 = F_107 ( V_314 , V_216 , V_40 -> V_308 ) ;
memset ( V_40 -> V_58 , 0 , V_314 ) ;
F_6 (cpu) {
V_40 -> V_58 [ V_6 ] . V_55 = F_122 ( V_6 ) -> V_55 ;
V_40 -> V_58 [ V_6 ] . V_3 = F_122 ( V_6 ) -> V_309 ;
}
}
static void F_125 ( struct V_10 * V_78 )
{
int V_315 = sizeof( T_2 ) ;
V_78 -> V_70 = F_126 ( V_315 , V_216 , V_78 -> V_308 ) ;
}
static int F_127 ( struct V_305 * V_306 , struct V_300 * V_304 ,
struct V_10 * * V_316 ,
struct V_10 * * V_317 )
{
int V_19 ;
int V_6 ;
struct V_10 * V_11 ;
for ( V_19 = 0 ; V_19 < V_306 -> V_310 ; V_19 ++ ) {
V_6 = V_306 -> V_312 [ V_19 ] ;
V_11 = & F_8 ( V_10 , V_6 ) ;
V_11 -> V_6 = V_6 ;
if ( V_19 == 0 ) {
* V_316 = V_11 ;
if ( ! ( * V_317 ) )
* V_317 = V_11 ;
}
V_11 -> V_54 = V_304 -> V_310 ;
V_11 -> V_51 = V_306 -> V_310 ;
V_11 -> V_41 = * V_316 ;
V_11 -> V_3 = V_304 -> V_3 ;
V_11 -> V_48 = * V_317 ;
V_11 -> V_103 = F_122 ( V_6 ) -> V_318 ;
if ( V_11 -> V_103 >= V_319 ) {
F_92 ( V_307 L_27 ,
V_11 -> V_103 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_128 ( int V_199 ,
struct V_300 * V_301 ,
unsigned char * V_302 )
{
int V_303 ;
int V_3 ;
unsigned short V_311 ;
for ( V_3 = 0 ; V_3 < V_199 ; V_3 ++ ) {
struct V_300 * V_304 ;
struct V_10 * V_40 = NULL ;
struct V_10 * V_78 = NULL ;
if ( ! ( * ( V_302 + ( V_3 / 8 ) ) & ( 1 << ( V_3 % 8 ) ) ) )
continue;
V_304 = & V_301 [ V_3 ] ;
V_311 = V_304 -> V_311 ;
V_303 = 0 ;
while ( V_311 ) {
struct V_305 * V_306 ;
if ( ( V_311 & 1 ) ) {
V_306 = & V_304 -> V_303 [ V_303 ] ;
if ( F_127 ( V_306 , V_304 , & V_40 , & V_78 ) )
return 1 ;
F_124 ( V_40 ) ;
}
V_303 ++ ;
V_311 = ( V_311 >> 1 ) ;
}
F_125 ( V_78 ) ;
}
return 0 ;
}
static int T_1 F_129 ( int V_199 , int V_320 )
{
unsigned char * V_302 ;
void * V_273 ;
struct V_300 * V_301 ;
V_94 = F_119 () ;
V_273 = F_130 ( V_199 * sizeof( struct V_300 ) , V_216 ) ;
V_301 = (struct V_300 * ) V_273 ;
memset ( V_301 , 0 , V_199 * sizeof( struct V_300 ) ) ;
V_302 = F_131 ( ( V_199 + 7 ) / 8 , V_216 ) ;
if ( F_121 ( V_320 , V_301 , V_302 ) )
goto V_321;
if ( F_128 ( V_199 , V_301 , V_302 ) )
goto V_321;
F_88 ( V_301 ) ;
F_88 ( V_302 ) ;
F_120 () ;
return 0 ;
V_321:
F_88 ( V_301 ) ;
F_88 ( V_302 ) ;
return 1 ;
}
static int T_1 F_132 ( void )
{
int V_3 ;
int V_55 ;
int V_199 ;
int V_322 ;
int V_323 ;
int V_280 ;
T_10 * V_69 ;
if ( ! F_102 () )
return 0 ;
if ( V_2 )
return 0 ;
F_133 (cur_cpu) {
V_69 = & F_8 ( V_183 , V_322 ) ;
F_134 ( V_69 , V_216 , F_123 ( V_322 ) ) ;
}
V_261 = V_324 -> V_325 ;
V_262 = ( 1UL << V_324 -> V_325 ) - 1 ;
V_199 = F_69 () ;
F_135 ( & V_124 ) ;
V_128 = F_79 ( V_217 ) ;
V_326 = 0x7fffffff ;
for ( V_3 = 0 ; V_3 < V_199 ; V_3 ++ ) {
V_323 = F_70 ( V_3 ) ;
if ( V_323 && ( F_71 ( V_3 ) < V_326 ) )
V_326 = F_71 ( V_3 ) ;
}
if ( F_129 ( V_199 , V_326 ) ) {
V_2 = 1 ;
return 0 ;
}
V_280 = V_327 ;
F_136 (uvhub)
if ( F_70 ( V_3 ) )
F_117 ( V_3 , V_280 , V_326 ) ;
F_68 () ;
F_137 ( V_280 , V_328 ) ;
F_136 (uvhub) {
if ( F_70 ( V_3 ) ) {
unsigned long V_230 ;
unsigned long V_22 ;
V_55 = F_71 ( V_3 ) ;
V_230 = 1L << 63 ;
F_138 ( V_55 , V_230 ) ;
V_22 = 1 ;
F_139 ( V_55 , V_22 ) ;
}
}
return 0 ;
}
