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
struct V_81 V_82 ;
unsigned long long V_83 ;
F_28 ( & V_82 ) ;
V_83 = F_29 ( V_80 , V_82 . V_84 , V_82 . V_85 ) ;
F_30 () ;
return V_83 ;
}
static inline unsigned long long F_31 ( unsigned long long V_83 )
{
struct V_81 V_82 ;
unsigned long long V_80 ;
F_28 ( & V_82 ) ;
V_80 = ( V_83 << V_82 . V_85 ) / V_82 . V_84 ;
F_30 () ;
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
struct V_6 * V_7 , long V_97 )
{
unsigned long V_94 ;
T_3 V_98 ;
T_4 V_92 = V_7 -> V_99 ;
int V_93 = V_7 -> V_100 ;
struct V_30 * V_31 = V_7 -> V_32 ;
V_94 = F_37 ( V_92 , V_93 ) ;
while ( ( V_94 != V_101 ) ) {
if ( V_94 == V_102 ) {
V_31 -> V_103 ++ ;
return V_104 ;
} else if ( V_94 == V_105 ) {
V_31 -> V_106 ++ ;
V_98 = F_40 () ;
if ( F_32 ( V_98 - V_7 -> V_107 ) < V_108 ) {
V_7 -> V_109 = 0 ;
return V_110 ;
}
V_7 -> V_109 = 0 ;
return V_111 ;
} else {
F_41 () ;
}
V_94 = F_37 ( V_92 , V_93 ) ;
}
V_7 -> V_109 ++ ;
return V_112 ;
}
static unsigned long F_42 ( unsigned long V_113 , int V_114 , int V_115 )
{
return ( ( F_43 ( V_113 ) >> V_114 ) & V_95 ) << 1 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_32 ;
V_31 -> V_116 ++ ;
V_7 -> V_117 = 1 ;
return V_104 ;
}
static int F_45 ( struct V_96 * V_96 ,
struct V_6 * V_7 , long V_97 )
{
unsigned long V_118 ;
T_3 V_98 ;
T_4 V_92 = V_7 -> V_99 ;
int V_93 = V_7 -> V_100 ;
int V_115 = V_7 -> V_119 ;
long V_120 = 0 ;
struct V_30 * V_31 = V_7 -> V_32 ;
V_118 = F_42 ( V_92 , V_93 , V_115 ) ;
while ( V_118 != V_121 ) {
if ( ( V_118 == V_122 ) ) {
V_31 -> V_103 ++ ;
return V_104 ;
} else if ( V_118 == V_123 ) {
V_98 = F_40 () ;
if ( F_32 ( V_98 - V_7 -> V_107 ) < V_108 ) {
V_7 -> V_109 = 0 ;
V_31 -> V_124 ++ ;
return V_104 ;
}
V_31 -> V_106 ++ ;
V_7 -> V_109 = 0 ;
return V_104 ;
} else {
V_120 ++ ;
if ( V_120 > 1000000 ) {
V_120 = 0 ;
V_98 = F_40 () ;
if ( ( V_98 - V_7 -> V_107 ) > V_7 -> V_125 )
return F_44 ( V_7 ) ;
}
F_41 () ;
}
V_118 = F_42 ( V_92 , V_93 , V_115 ) ;
}
V_7 -> V_109 ++ ;
return V_112 ;
}
static T_4 F_46 ( T_4 V_99 , int V_126 , int V_115 )
{
T_4 V_31 ;
V_31 = ( ( F_43 ( V_99 ) >> V_126 ) & V_95 ) << 1 ;
V_31 |= ( F_43 ( V_127 ) >> V_115 ) & 0x1 ;
return V_31 ;
}
static int F_47 ( struct V_96 * V_96 ,
struct V_6 * V_7 , long V_97 )
{
struct V_30 * V_31 = V_7 -> V_32 ;
T_4 V_118 ;
T_4 V_28 = V_7 -> V_99 ;
int V_126 = V_7 -> V_100 ;
int V_115 = V_7 -> V_119 ;
V_118 = F_46 ( V_28 , V_126 , V_115 ) ;
while ( V_118 != V_121 ) {
switch ( V_118 ) {
case V_122 :
V_31 -> V_103 ++ ;
return V_104 ;
case V_123 :
V_31 -> V_106 ++ ;
V_7 -> V_109 = 0 ;
return V_111 ;
case V_128 :
V_31 -> V_124 ++ ;
V_7 -> V_109 = 0 ;
return V_110 ;
case V_129 :
V_7 -> V_109 = 0 ;
return V_104 ;
default:
F_41 () ;
}
V_118 = F_46 ( V_28 , V_126 , V_115 ) ;
}
V_7 -> V_109 ++ ;
return V_112 ;
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
if ( V_31 != V_112 )
return;
if ( V_7 -> V_109 <= V_7 -> V_148 )
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
if ( ( V_152 == V_112 ) && ( V_97 == 1 ) ) {
V_7 -> V_155 ++ ;
V_7 -> V_156 += V_153 ;
if ( ( V_153 > F_34 ( V_7 -> V_157 ) ) &&
( V_7 -> V_155 > V_7 -> V_158 ) &&
( ( V_7 -> V_156 / V_7 -> V_155 ) >
F_34 ( V_7 -> V_157 ) ) ) {
V_31 -> V_159 ++ ;
F_53 ( V_7 , V_31 ) ;
}
}
} else
V_31 -> V_160 -- ;
if ( V_152 == V_112 && V_97 > 1 )
V_31 -> V_161 ++ ;
else if ( V_152 == V_104 ) {
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
T_5 * V_167 = & V_90 -> V_168 ;
T_6 * V_169 ;
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
if ( V_152 == V_110 )
F_48 ( V_96 , V_7 , V_90 , V_31 ) ;
else if ( V_152 == V_111 )
F_52 ( V_96 , V_7 , V_90 , V_31 ) ;
}
static int F_59 ( struct V_77 * V_172 ,
struct V_6 * V_7 ,
struct V_96 * V_96 )
{
int V_173 = 0 ;
int V_174 = 0 ;
int V_175 = 0 ;
long V_97 = 0 ;
unsigned long V_126 ;
T_3 V_150 ;
T_3 V_151 ;
struct V_30 * V_31 = V_7 -> V_32 ;
struct V_6 * V_90 = V_7 -> V_55 ;
struct V_176 * V_177 = NULL ;
struct V_178 * V_179 = NULL ;
if ( V_7 -> V_180 == V_181 ) {
V_175 = 1 ;
F_56 ( V_90 , V_31 ) ;
}
while ( V_90 -> V_91 )
F_41 () ;
V_150 = F_40 () ;
if ( V_175 )
V_177 = & V_96 -> V_182 . V_177 ;
else
V_179 = & V_96 -> V_182 . V_179 ;
do {
if ( V_97 == 0 ) {
if ( V_175 )
V_177 -> V_38 = V_183 ;
else
V_179 -> V_38 = V_183 ;
V_173 = V_7 -> V_184 ++ ;
} else {
if ( V_175 )
V_177 -> V_38 = V_54 ;
else
V_179 -> V_38 = V_54 ;
V_31 -> V_185 ++ ;
}
if ( V_175 )
V_177 -> V_186 = V_173 ;
else
V_179 -> V_186 = V_173 ;
V_126 = ( 1UL << V_187 ) | V_7 -> V_119 ;
V_7 -> V_107 = F_40 () ;
F_60 ( V_126 ) ;
V_97 ++ ;
V_174 = V_22 . V_188 ( V_96 , V_7 , V_97 ) ;
F_58 ( V_174 , V_96 , V_7 , V_90 , V_31 ) ;
if ( V_7 -> V_134 >= V_7 -> V_189 ) {
V_7 -> V_134 = 0 ;
V_31 -> V_190 ++ ;
V_174 = V_104 ;
break;
}
F_41 () ;
} while ( ( V_174 == V_110 ) ||
( V_174 == V_111 ) );
V_151 = F_40 () ;
F_54 ( V_174 , V_7 , V_90 ) ;
while ( V_90 -> V_91 )
F_41 () ;
F_61 ( & V_90 -> V_170 ) ;
F_55 ( V_150 , V_151 , V_7 , V_31 , V_174 , V_97 ) ;
if ( V_174 == V_104 )
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
V_31 -> V_191 ++ ;
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
static void F_63 ( struct V_30 * V_31 , int V_192 , int V_193 ,
int V_194 , struct V_96 * V_96 )
{
V_31 -> V_160 ++ ;
V_31 -> V_195 += V_194 + V_192 ;
V_31 -> V_196 += V_194 ;
V_31 -> V_197 += V_192 ;
V_193 = F_64 ( & V_96 -> V_73 ) ;
if ( V_192 ) {
V_31 -> V_198 ++ ;
V_31 -> V_199 += ( V_193 - 1 ) ;
} else
V_31 -> V_199 += V_193 ;
V_31 -> V_200 += V_193 ;
if ( V_193 >= 16 )
V_31 -> V_201 ++ ;
else if ( V_193 >= 8 )
V_31 -> V_202 ++ ;
else if ( V_193 >= 4 )
V_31 -> V_203 ++ ;
else if ( V_193 >= 2 )
V_31 -> V_204 ++ ;
else
V_31 -> V_205 ++ ;
}
static int F_65 ( struct V_77 * V_172 , struct V_6 * V_7 ,
struct V_96 * V_96 , int * V_206 , int * V_207 )
{
int V_5 ;
int V_62 ;
int V_208 = 0 ;
struct V_63 * V_64 ;
F_66 (cpu, flush_mask) {
V_64 = & V_7 -> V_48 -> V_65 [ V_5 ] ;
V_62 = V_64 -> V_62 - V_7 -> V_79 ;
F_67 ( V_62 , & V_96 -> V_73 ) ;
V_208 ++ ;
if ( V_64 -> V_9 == V_7 -> V_9 )
( * V_206 ) ++ ;
else
( * V_207 ) ++ ;
}
if ( ! V_208 )
return 1 ;
return 0 ;
}
const struct V_77 * F_68 ( const struct V_77 * V_77 ,
const struct V_209 * V_210 )
{
unsigned int V_5 = F_21 () ;
int V_192 = 0 , V_194 = 0 , V_193 = 0 ;
struct V_96 * V_96 ;
struct V_77 * V_172 ;
struct V_30 * V_31 ;
struct V_6 * V_7 ;
unsigned long V_94 , V_211 , V_49 ;
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 )
return V_77 ;
V_31 = V_7 -> V_32 ;
V_31 -> V_212 ++ ;
if ( V_7 -> V_117 ) {
V_94 =
F_43 ( V_213 ) ;
V_211 = ( ( V_94 >> ( V_7 -> V_119 *
V_214 ) ) & V_95 ) << 1 ;
if ( V_211 == V_215 )
return V_77 ;
V_7 -> V_117 = 0 ;
}
if ( V_7 -> V_144 ) {
if ( F_62 ( V_7 , V_31 ) ) {
V_31 -> V_216 ++ ;
return V_77 ;
}
}
V_172 = (struct V_77 * ) F_6 ( V_217 , V_5 ) ;
F_69 ( V_172 , V_77 , F_70 ( V_5 ) ) ;
if ( F_71 ( V_5 , V_77 ) )
V_31 -> V_218 ++ ;
V_96 = V_7 -> V_219 ;
V_96 += ( V_220 * V_7 -> V_119 ) ;
F_72 ( & V_96 -> V_73 , V_221 ) ;
if ( F_65 ( V_172 , V_7 , V_96 , & V_192 , & V_194 ) )
return NULL ;
F_63 ( V_31 , V_192 , V_193 , V_194 , V_96 ) ;
if ( ! V_210 -> V_222 || ( V_210 -> V_222 - V_210 -> V_223 ) <= V_224 )
V_49 = V_210 -> V_223 ;
else
V_49 = V_50 ;
switch ( V_7 -> V_180 ) {
case V_181 :
case V_225 :
case V_226 :
V_96 -> V_227 . V_228 . V_49 = V_49 ;
V_96 -> V_227 . V_228 . V_37 = V_5 ;
break;
case V_229 :
V_96 -> V_227 . V_230 . V_49 = V_49 ;
V_96 -> V_227 . V_230 . V_37 = V_5 ;
V_96 -> V_227 . V_230 . V_231 = V_232 ;
break;
}
if ( ! F_59 ( V_172 , V_7 , V_96 ) )
return NULL ;
else
return V_77 ;
}
static struct V_17 * F_73 ( struct V_17 * V_18 ,
struct V_6 * V_7 )
{
struct V_17 * V_233 = V_18 + 1 ;
unsigned char V_20 = V_18 -> V_20 ;
if ( V_233 > V_7 -> V_35 )
V_233 = V_7 -> V_36 ;
while ( V_233 != V_18 ) {
if ( ( V_233 -> V_19 == 0 ) && ( V_233 -> V_24 == 0 ) &&
( V_233 -> V_20 == V_20 ) )
return V_233 ;
V_233 ++ ;
if ( V_233 > V_7 -> V_35 )
V_233 = V_7 -> V_36 ;
}
return NULL ;
}
static void F_74 ( struct V_13 * V_14 , struct V_6 * V_7 )
{
unsigned long V_234 ;
unsigned char V_20 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_17 * V_235 ;
V_234 = V_22 . V_40 () ;
V_20 = V_18 -> V_20 ;
if ( ( V_20 & V_234 ) == 0 ) {
V_235 = F_73 ( V_18 , V_7 ) ;
if ( V_235 ) {
F_15 ( V_14 , V_7 , 0 ) ;
return;
}
}
F_15 ( V_14 , V_7 , 1 ) ;
return;
}
void F_75 ( struct V_236 * V_237 )
{
int V_238 = 0 ;
T_3 V_239 ;
struct V_17 * V_18 ;
struct V_6 * V_7 ;
struct V_30 * V_31 ;
struct V_13 V_240 ;
F_76 () ;
V_239 = F_40 () ;
V_7 = & F_6 ( V_6 , F_21 () ) ;
V_31 = V_7 -> V_32 ;
V_240 . V_36 = V_7 -> V_36 ;
V_240 . V_35 = V_7 -> V_35 ;
V_18 = V_7 -> V_241 ;
while ( V_18 -> V_20 ) {
V_238 ++ ;
V_240 . V_57 = V_18 - V_240 . V_36 ;
V_240 . V_18 = V_18 ;
if ( V_7 -> V_180 == V_225 )
F_74 ( & V_240 , V_7 ) ;
else
F_15 ( & V_240 , V_7 , 1 ) ;
V_18 ++ ;
if ( V_18 > V_240 . V_35 )
V_18 = V_240 . V_36 ;
V_7 -> V_241 = V_18 ;
}
V_31 -> V_242 += ( F_40 () - V_239 ) ;
if ( ! V_238 )
V_31 -> V_243 ++ ;
else if ( V_238 > 1 )
V_31 -> V_244 ++ ;
}
static void T_1 F_77 ( void )
{
int V_9 ;
int V_245 ;
int V_62 ;
unsigned long V_234 ;
V_245 = F_78 () ;
for ( V_9 = 0 ; V_9 < V_245 ; V_9 ++ ) {
if ( ! F_79 ( V_9 ) )
continue;
V_62 = F_80 ( V_9 ) ;
V_234 = F_81 ( V_62 ) ;
V_234 &= ~ ( 1L << V_246 ) ;
F_82 ( V_62 , V_234 ) ;
V_234 &= ~ ( ( unsigned long ) 0xf << V_247 ) ;
V_234 |= ( V_248 << V_247 ) ;
F_82 ( V_62 , V_234 ) ;
V_234 |= ( 1L << V_246 ) ;
if ( F_83 () ) {
V_234 &= ~ ( 1L << V_249 ) ;
} else if ( F_84 () ) {
V_234 &= ~ ( 1L << V_250 ) ;
V_234 |= ( 1L << V_251 ) ;
}
F_82 ( V_62 , V_234 ) ;
}
}
static void * F_85 ( struct V_252 * V_253 , T_7 * V_113 )
{
if ( * V_113 < F_86 () )
return V_113 ;
return NULL ;
}
static void * F_87 ( struct V_252 * V_253 , void * V_82 , T_7 * V_113 )
{
( * V_113 ) ++ ;
if ( * V_113 < F_86 () )
return V_113 ;
return NULL ;
}
static void F_88 ( struct V_252 * V_253 , void * V_82 )
{
}
static int F_89 ( struct V_252 * V_253 , void * V_82 )
{
struct V_30 * V_31 ;
struct V_6 * V_7 ;
int V_5 ;
V_5 = * ( T_7 * ) V_82 ;
if ( ! V_5 ) {
F_90 ( V_253 ,
L_6 ) ;
F_90 ( V_253 , L_7 ) ;
F_90 ( V_253 ,
L_8 ) ;
F_90 ( V_253 ,
L_9 ) ;
F_90 ( V_253 ,
L_10 ) ;
F_90 ( V_253 ,
L_11 ) ;
F_90 ( V_253 , L_12 ) ;
}
if ( V_5 < F_86 () && F_91 ( V_5 ) ) {
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 ) {
F_92 ( V_253 , L_13 , V_5 ) ;
return 0 ;
}
V_31 = V_7 -> V_32 ;
F_92 ( V_253 ,
L_14 ,
V_5 , V_7 -> V_4 , V_31 -> V_160 ,
F_32 ( V_31 -> V_154 ) ,
V_31 -> V_218 , V_31 -> V_197 ,
V_31 -> V_196 , V_31 -> V_195 ,
V_31 -> V_198 , V_31 -> V_199 ,
V_31 -> V_200 , V_31 -> V_201 ) ;
F_92 ( V_253 , L_15 ,
V_31 -> V_202 , V_31 -> V_203 ,
V_31 -> V_204 , V_31 -> V_205 ,
V_31 -> V_106 , V_31 -> V_254 ) ;
F_92 ( V_253 , L_16 ,
V_31 -> V_185 , V_31 -> V_161 ,
V_31 -> V_135 , V_31 -> V_139 ,
V_31 -> V_162 , V_31 -> V_103 ,
V_31 -> V_255 , V_31 -> V_171 ) ;
F_92 ( V_253 , L_17 ,
V_31 -> V_145 , V_31 -> V_191 ,
V_31 -> V_116 , V_31 -> V_256 ,
V_31 -> V_257 , V_31 -> V_212 ,
V_31 -> V_216 , V_31 -> V_124 ,
V_31 -> V_190 , V_31 -> V_166 ,
V_31 -> V_159 ) ;
F_92 ( V_253 ,
L_18 ,
V_22 . V_258 ( F_93 ( V_5 ) ) ,
V_31 -> V_53 , F_32 ( V_31 -> V_242 ) ,
V_31 -> V_51 , V_31 -> V_52 , V_31 -> V_244 ,
V_31 -> V_243 , V_31 -> V_33 , V_31 -> V_42 ,
V_31 -> V_43 , V_31 -> V_69 ,
V_31 -> V_71 ) ;
}
return 0 ;
}
static T_8 F_94 ( struct V_253 * V_253 , char T_9 * V_259 ,
T_10 V_238 , T_7 * V_260 )
{
char * V_261 ;
int V_262 ;
V_261 = F_95 ( V_263 , L_19 ,
L_20 ,
L_21 ,
L_22 ,
V_136 , V_130 , V_132 ,
V_138 , V_189 , V_148 ,
V_264 , V_265 , V_147 ,
V_165 ) ;
if ( ! V_261 )
return - V_266 ;
V_262 = F_96 ( V_259 , V_238 , V_260 , V_261 , strlen ( V_261 ) ) ;
F_97 ( V_261 ) ;
return V_262 ;
}
static T_8 F_98 ( struct V_253 * V_253 , const char T_9 * V_267 ,
T_10 V_238 , T_7 * V_82 )
{
int V_5 ;
int V_25 ;
int V_268 ;
long V_269 ;
char V_270 [ 64 ] ;
struct V_30 * V_31 ;
if ( V_238 == 0 || V_238 > sizeof( V_270 ) )
return - V_3 ;
if ( F_99 ( V_270 , V_267 , V_238 ) )
return - V_271 ;
V_270 [ V_238 - 1 ] = '\0' ;
if ( ! strcmp ( V_270 , L_23 ) ) {
F_4 () ;
return V_238 ;
} else if ( ! strcmp ( V_270 , L_24 ) ) {
F_7 () ;
return V_238 ;
}
if ( F_100 ( V_270 , 10 , & V_269 ) < 0 ) {
F_101 ( L_25 , V_270 ) ;
return - V_3 ;
}
if ( V_269 == 0 ) {
V_268 = F_102 ( V_272 ) ;
F_101 ( L_26 ) ;
F_101 ( L_27 ) ;
for ( V_25 = 0 ; V_25 < V_268 ; V_25 ++ )
F_101 ( L_28 , V_272 [ V_25 ] ) ;
} else if ( V_269 == - 1 ) {
F_5 (cpu) {
V_31 = & F_6 ( V_273 , V_5 ) ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
}
}
return V_238 ;
}
static int F_103 ( const char * V_274 )
{
int V_275 = 0 ;
for (; ; V_274 ++ ) {
switch ( * V_274 ) {
case '0' ... '9' :
V_275 = 10 * V_275 + ( * V_274 - '0' ) ;
break;
default:
return V_275 ;
}
}
}
static int F_104 ( struct V_6 * V_7 , char * V_276 ,
int V_238 )
{
char * V_277 ;
char * V_278 ;
int V_208 = 0 ;
int V_275 ;
int V_279 = F_102 ( V_280 ) ;
V_277 = V_276 + strspn ( V_276 , V_281 ) ;
V_278 = V_277 ;
for (; * V_277 ; V_277 = V_278 + strspn ( V_278 , V_281 ) ) {
V_278 = V_277 + strcspn ( V_277 , V_281 ) ;
V_208 ++ ;
if ( V_278 == V_277 )
break;
}
if ( V_208 != V_279 ) {
F_3 ( L_29 , V_279 ) ;
return - V_3 ;
}
V_277 = V_276 + strspn ( V_276 , V_281 ) ;
V_278 = V_277 ;
for ( V_208 = 0 ; * V_277 ; V_277 = V_278 + strspn ( V_278 , V_281 ) , V_208 ++ ) {
V_278 = V_277 + strcspn ( V_277 , V_281 ) ;
V_275 = F_103 ( V_277 ) ;
switch ( V_208 ) {
case 0 :
if ( V_275 == 0 ) {
V_136 = V_282 ;
V_149 = V_282 ;
continue;
}
if ( V_275 < 1 || V_275 > V_7 -> V_61 ) {
F_101 (
L_30 ,
V_275 ) ;
return - V_3 ;
}
V_136 = V_275 ;
V_149 = V_275 ;
continue;
default:
if ( V_275 == 0 )
* V_280 [ V_208 ] . V_283 = V_280 [ V_208 ] . V_284 ;
else
* V_280 [ V_208 ] . V_283 = V_275 ;
continue;
}
if ( V_278 == V_277 )
break;
}
return 0 ;
}
static T_8 F_105 ( struct V_253 * V_253 , const char T_9 * V_267 ,
T_10 V_238 , T_7 * V_82 )
{
int V_5 ;
int V_262 ;
char V_276 [ 100 ] ;
struct V_6 * V_7 ;
if ( V_238 == 0 || V_238 > sizeof( V_276 ) - 1 )
return - V_3 ;
if ( F_99 ( V_276 , V_267 , V_238 ) )
return - V_271 ;
V_276 [ V_238 ] = '\0' ;
V_5 = F_106 () ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_262 = F_104 ( V_7 , V_276 , V_238 ) ;
F_107 () ;
if ( V_262 )
return V_262 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_136 = V_136 ;
V_7 -> V_149 = V_136 ;
V_7 -> V_130 = V_130 ;
V_7 -> V_132 = V_132 ;
V_7 -> V_138 = V_138 ;
V_7 -> V_189 = V_189 ;
V_7 -> V_148 = V_148 ;
V_7 -> V_157 = V_264 ;
V_7 -> V_158 = V_265 ;
V_7 -> V_147 = F_33 ( V_147 ) ;
V_7 -> V_165 = V_165 ;
}
return V_238 ;
}
static int F_108 ( struct V_285 * V_285 , struct V_253 * V_253 )
{
return F_109 ( V_253 , & V_286 ) ;
}
static int F_110 ( struct V_285 * V_285 , struct V_253 * V_253 )
{
return 0 ;
}
static int T_1 F_111 ( void )
{
struct V_287 * V_288 ;
if ( ! F_112 () )
return 0 ;
V_288 = F_113 ( V_289 , 0444 , NULL ,
& V_290 ) ;
if ( ! V_288 ) {
F_114 ( L_31 ,
V_289 ) ;
return - V_3 ;
}
V_291 = F_115 ( V_292 , NULL ) ;
if ( ! V_291 ) {
F_114 ( L_32 ,
V_292 ) ;
return - V_3 ;
}
V_293 = F_116 ( V_294 , 0600 ,
V_291 , NULL , & V_295 ) ;
if ( ! V_293 ) {
F_114 ( L_33 ,
V_294 ) ;
return - V_3 ;
}
return 0 ;
}
static void F_117 ( int V_10 , int V_62 , int V_296 )
{
int V_25 ;
int V_5 ;
int V_175 = 0 ;
unsigned long V_297 ;
unsigned long V_298 ;
unsigned long V_299 ;
T_10 V_300 ;
struct V_96 * V_96 ;
struct V_96 * V_301 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_6 * V_7 ;
V_300 = sizeof( struct V_96 ) * V_302 * V_220 ;
V_96 = F_118 ( V_300 , V_263 , V_10 ) ;
F_119 ( ! V_96 ) ;
V_297 = F_120 ( V_96 ) ;
V_299 = F_121 ( V_297 ) ;
V_298 = V_22 . V_303 ( V_297 ) ;
if ( F_122 () )
V_175 = 1 ;
F_123 ( V_62 , ( V_299 << V_304 | V_298 ) ) ;
for ( V_25 = 0 , V_301 = V_96 ; V_25 < ( V_302 * V_220 ) ; V_25 ++ , V_301 ++ ) {
memset ( V_301 , 0 , sizeof( struct V_96 ) ) ;
if ( V_175 ) {
V_177 = & V_301 -> V_182 . V_177 ;
V_177 -> V_305 = 1 ;
V_177 -> V_306 =
F_124 ( V_296 ) ;
V_177 -> V_307 = V_308 ;
V_177 -> V_309 = V_310 ;
V_177 -> V_311 = 1 ;
} else {
V_179 = & V_301 -> V_182 . V_179 ;
V_179 -> V_305 = 1 ;
V_179 -> V_306 =
F_124 ( V_296 ) ;
V_179 -> V_307 = V_308 ;
V_179 -> V_309 = V_310 ;
}
}
F_5 (cpu) {
if ( V_62 != F_80 ( F_12 ( V_5 ) ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_219 = V_96 ;
}
}
static void F_125 ( int V_10 , int V_62 )
{
int V_5 ;
T_10 V_312 ;
char * V_313 ;
void * V_314 ;
unsigned long V_315 , V_316 , V_317 , V_318 ;
struct V_17 * V_319 ;
struct V_6 * V_7 ;
V_312 = ( V_34 + 1 ) * sizeof( struct V_17 ) ;
V_314 = F_118 ( V_312 , V_263 , V_10 ) ;
V_319 = (struct V_17 * ) V_314 ;
F_119 ( ! V_319 ) ;
V_313 = ( char * ) V_319 + 31 ;
V_319 = (struct V_17 * ) ( ( ( unsigned long ) V_313 >> 5 ) << 5 ) ;
F_5 (cpu) {
if ( V_62 != F_93 ( V_5 ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_36 = V_319 ;
V_7 -> V_241 = V_319 ;
V_7 -> V_35 = V_319 + ( V_34 - 1 ) ;
}
V_316 = V_22 . V_303 ( F_120 ( V_319 ) ) ;
V_317 = V_22 . V_303 ( F_120 ( V_319 + ( V_34 - 1 ) ) ) ;
V_7 = & F_6 ( V_6 , F_21 () ) ;
if ( V_7 -> V_180 <= V_226 ) {
V_318 = V_316 ;
V_315 = F_121 ( F_120 ( V_319 ) ) ;
V_316 = ( V_315 << V_320 ) | V_318 ;
F_126 ( V_62 , V_318 ) ;
}
V_22 . V_321 ( V_62 , V_316 ) ;
V_22 . V_322 ( V_62 , V_317 ) ;
memset ( V_319 , 0 , sizeof( struct V_17 ) * V_34 ) ;
}
static void T_1 F_127 ( int V_9 , int V_323 , int V_296 )
{
int V_10 ;
int V_62 ;
unsigned long V_324 ;
V_10 = F_8 ( V_9 ) ;
V_62 = F_80 ( V_9 ) ;
F_117 ( V_10 , V_62 , V_296 ) ;
F_125 ( V_10 , V_62 ) ;
V_324 = F_11 ( V_9 ) | V_325 ;
F_128 ( V_62 , ( ( V_324 << 32 ) | V_323 ) ) ;
}
static int F_129 ( void )
{
unsigned long V_234 ;
int V_326 ;
int V_327 ;
int V_126 ;
int V_328 ;
int V_262 ;
unsigned long V_329 ;
if ( F_122 () ) {
V_326 = V_248 & V_330 ;
V_234 = F_38 ( V_331 ) ;
V_126 = ( V_234 >> V_332 ) & V_333 ;
V_234 = F_38 ( V_334 ) ;
V_327 = ( V_234 >> V_335 ) & V_336 ;
V_329 = V_337 [ V_126 ] ;
V_329 *= ( V_326 * V_327 ) ;
V_262 = V_329 / 1000 ;
} else {
V_234 = F_38 ( V_338 ) ;
V_234 = ( V_234 & V_339 ) >> V_340 ;
if ( V_234 & ( 1L << V_341 ) )
V_328 = 80 ;
else
V_328 = 10 ;
V_326 = V_234 & V_342 ;
V_262 = V_326 * V_328 ;
}
return V_262 ;
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
V_7 -> V_32 = & F_6 ( V_273 , V_5 ) ;
V_7 -> V_125 = F_34 ( 2 * V_108 ) ;
V_7 -> V_136 = V_136 ;
V_7 -> V_149 = V_136 ;
V_7 -> V_130 = V_130 ;
V_7 -> V_132 = V_132 ;
V_7 -> V_138 = V_138 ;
V_7 -> V_189 = V_189 ;
V_7 -> V_148 = V_148 ;
V_7 -> V_157 = V_264 ;
V_7 -> V_158 = V_265 ;
V_7 -> V_147 = F_33 ( V_147 ) ;
V_7 -> V_165 = V_165 ;
F_131 ( & V_7 -> V_133 ) ;
F_131 ( & V_7 -> V_168 ) ;
F_131 ( & V_7 -> V_143 ) ;
}
}
static int T_1 F_132 ( int V_296 ,
struct V_343 * V_344 ,
unsigned char * V_345 )
{
int V_5 ;
int V_62 ;
int V_9 ;
int V_346 ;
struct V_6 * V_7 ;
struct V_343 * V_347 ;
struct V_348 * V_349 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_62 = F_133 ( V_5 ) -> V_62 ;
if ( ( V_62 - V_296 ) >= V_221 ) {
F_134 (
L_34 ,
V_5 , V_62 , V_296 , V_221 ) ;
return 1 ;
}
V_7 -> V_350 = F_135 ( V_5 ) ;
V_7 -> V_79 = V_296 ;
V_9 = F_133 ( V_5 ) -> V_351 ;
* ( V_345 + ( V_9 / 8 ) ) |= ( 1 << ( V_9 % 8 ) ) ;
V_347 = & V_344 [ V_9 ] ;
V_347 -> V_352 ++ ;
V_347 -> V_9 = V_9 ;
V_347 -> V_62 = V_62 ;
V_346 = V_7 -> V_350 & 1 ;
V_347 -> V_353 |= ( 1 << V_346 ) ;
V_349 = & V_347 -> V_346 [ V_346 ] ;
V_349 -> V_354 [ V_349 -> V_352 ] = V_5 ;
V_349 -> V_352 ++ ;
if ( V_349 -> V_352 > V_355 ) {
F_134 ( L_35 ,
V_349 -> V_352 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_136 ( struct V_6 * V_47 )
{
int V_5 ;
T_10 V_356 = sizeof( struct V_63 ) * F_86 () ;
V_47 -> V_65 = F_118 ( V_356 , V_263 , V_47 -> V_350 ) ;
memset ( V_47 -> V_65 , 0 , V_356 ) ;
F_5 (cpu) {
V_47 -> V_65 [ V_5 ] . V_62 = F_133 ( V_5 ) -> V_62 ;
V_47 -> V_65 [ V_5 ] . V_9 = F_133 ( V_5 ) -> V_351 ;
}
}
static void F_137 ( struct V_6 * V_90 )
{
int V_357 = sizeof( T_2 ) ;
V_90 -> V_77 = F_138 ( V_357 , V_263 , V_90 -> V_350 ) ;
}
static int F_139 ( struct V_348 * V_349 , struct V_343 * V_347 ,
struct V_6 * * V_358 ,
struct V_6 * * V_359 )
{
int V_25 , V_5 , V_119 ;
struct V_6 * V_7 ;
for ( V_25 = 0 ; V_25 < V_349 -> V_352 ; V_25 ++ ) {
V_5 = V_349 -> V_354 [ V_25 ] ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_5 = V_5 ;
if ( V_25 == 0 ) {
* V_358 = V_7 ;
if ( ! ( * V_359 ) )
* V_359 = V_7 ;
}
V_7 -> V_61 = V_347 -> V_352 ;
V_7 -> V_58 = V_349 -> V_352 ;
V_7 -> V_48 = * V_358 ;
V_7 -> V_9 = V_347 -> V_9 ;
if ( F_122 () )
V_7 -> V_180 = V_181 ;
else if ( F_83 () )
V_7 -> V_180 = V_225 ;
else if ( F_84 () )
V_7 -> V_180 = V_226 ;
else if ( F_140 () )
V_7 -> V_180 = V_229 ;
else {
F_134 ( L_36 ) ;
return 1 ;
}
V_7 -> V_55 = * V_359 ;
V_119 = F_141 ( V_5 ) ;
V_7 -> V_119 = V_119 ;
if ( V_119 < V_360 ) {
V_7 -> V_99 = V_213 ;
V_7 -> V_100 = V_119 * V_214 ;
} else {
V_7 -> V_99 = V_361 ;
V_7 -> V_100 = ( V_119 - V_360 )
* V_214 ;
}
if ( V_7 -> V_119 >= V_362 ) {
F_134 ( L_37 ,
V_7 -> V_119 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_142 ( int V_245 ,
struct V_343 * V_344 ,
unsigned char * V_345 )
{
int V_346 ;
int V_9 ;
unsigned short V_353 ;
for ( V_9 = 0 ; V_9 < V_245 ; V_9 ++ ) {
struct V_343 * V_347 ;
struct V_6 * V_47 = NULL ;
struct V_6 * V_90 = NULL ;
if ( ! ( * ( V_345 + ( V_9 / 8 ) ) & ( 1 << ( V_9 % 8 ) ) ) )
continue;
V_347 = & V_344 [ V_9 ] ;
V_353 = V_347 -> V_353 ;
V_346 = 0 ;
while ( V_353 ) {
struct V_348 * V_349 ;
if ( ( V_353 & 1 ) ) {
V_349 = & V_347 -> V_346 [ V_346 ] ;
if ( F_139 ( V_349 , V_347 , & V_47 , & V_90 ) )
return 1 ;
F_136 ( V_47 ) ;
}
V_346 ++ ;
V_353 = ( V_353 >> 1 ) ;
}
F_137 ( V_90 ) ;
}
return 0 ;
}
static int T_1 F_143 ( int V_245 , int V_363 )
{
unsigned char * V_345 ;
void * V_314 ;
struct V_343 * V_344 ;
if ( F_84 () || F_83 () || F_122 () )
V_108 = F_129 () ;
V_314 = F_144 ( V_245 * sizeof( struct V_343 ) , V_263 ) ;
V_344 = (struct V_343 * ) V_314 ;
memset ( V_344 , 0 , V_245 * sizeof( struct V_343 ) ) ;
V_345 = F_145 ( ( V_245 + 7 ) / 8 , V_263 ) ;
if ( F_132 ( V_363 , V_344 , V_345 ) )
goto V_364;
if ( F_142 ( V_245 , V_344 , V_345 ) )
goto V_364;
F_97 ( V_344 ) ;
F_97 ( V_345 ) ;
F_130 () ;
return 0 ;
V_364:
F_97 ( V_344 ) ;
F_97 ( V_345 ) ;
return 1 ;
}
static int T_1 F_146 ( void )
{
int V_9 ;
int V_62 ;
int V_245 ;
int V_365 ;
int V_366 ;
int V_323 ;
T_11 * V_76 ;
if ( ! F_112 () )
return 0 ;
if ( F_140 () )
V_22 = V_367 ;
else if ( F_84 () )
V_22 = V_368 ;
else if ( F_83 () )
V_22 = V_368 ;
else if ( F_122 () )
V_22 = V_369 ;
V_245 = F_78 () ;
if ( V_245 < 2 ) {
F_147 ( L_38 ) ;
goto V_370;
}
F_148 (cur_cpu) {
V_76 = & F_6 ( V_217 , V_365 ) ;
F_149 ( V_76 , V_263 , F_135 ( V_365 ) ) ;
}
V_371 = 0x7fffffff ;
for ( V_9 = 0 ; V_9 < V_245 ; V_9 ++ ) {
V_366 = F_79 ( V_9 ) ;
if ( V_366 && ( F_80 ( V_9 ) < V_371 ) )
V_371 = F_80 ( V_9 ) ;
}
if ( F_84 () || F_83 () || F_122 () )
F_77 () ;
if ( F_143 ( V_245 , V_371 ) ) {
F_147 ( L_39 ) ;
goto V_370;
}
V_323 = V_372 ;
F_150 (uvhub) {
if ( F_79 ( V_9 ) )
F_127 ( V_9 , V_323 , V_371 ) ;
}
F_151 ( V_323 , V_373 ) ;
F_150 (uvhub) {
if ( F_79 ( V_9 ) ) {
unsigned long V_275 ;
unsigned long V_28 ;
V_62 = F_80 ( V_9 ) ;
V_275 = 1L << 63 ;
F_152 ( V_62 , V_275 ) ;
V_28 = 1 ;
if ( ! F_122 () )
F_153 ( V_62 , V_28 ) ;
}
}
return 0 ;
V_370:
F_148 (cur_cpu)
F_154 ( F_6 ( V_217 , V_365 ) ) ;
F_7 () ;
V_8 = 1 ;
return - V_3 ;
}
