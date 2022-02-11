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
int F_44 ( struct V_6 * V_7 )
{
int V_5 = V_7 -> V_116 ;
int V_92 ;
int V_93 ;
V_92 = V_117 ;
V_93 = V_5 * V_118 ;
return ( ( ( ( ( F_43 ( V_92 ) >> V_93 ) &
V_95 ) ) << 1 ) == V_119 ) ;
}
int F_45 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_32 ;
V_31 -> V_120 ++ ;
V_7 -> V_121 = 1 ;
return V_104 ;
}
static int F_46 ( struct V_96 * V_96 ,
struct V_6 * V_7 , long V_97 )
{
unsigned long V_122 ;
T_3 V_98 ;
T_4 V_92 = V_7 -> V_99 ;
int V_93 = V_7 -> V_100 ;
int V_115 = V_7 -> V_116 ;
long V_123 = 0 ;
struct V_30 * V_31 = V_7 -> V_32 ;
V_122 = F_42 ( V_92 , V_93 , V_115 ) ;
while ( V_122 != V_124 ) {
if ( ( V_122 == V_125 ) ) {
V_31 -> V_103 ++ ;
return V_104 ;
} else if ( V_122 == V_126 ) {
V_98 = F_40 () ;
if ( F_32 ( V_98 - V_7 -> V_107 ) < V_108 ) {
V_7 -> V_109 = 0 ;
V_31 -> V_127 ++ ;
return V_104 ;
}
V_31 -> V_106 ++ ;
V_7 -> V_109 = 0 ;
return V_104 ;
} else {
V_123 ++ ;
if ( V_123 > 1000000 ) {
V_123 = 0 ;
V_98 = F_40 () ;
if ( ( V_98 - V_7 -> V_107 ) > V_7 -> V_128 )
return F_45 ( V_7 ) ;
}
F_41 () ;
}
V_122 = F_42 ( V_92 , V_93 , V_115 ) ;
}
V_7 -> V_109 ++ ;
return V_112 ;
}
static T_4 F_47 ( T_4 V_99 , int V_129 , int V_115 )
{
T_4 V_31 ;
V_31 = ( ( F_43 ( V_99 ) >> V_129 ) & V_95 ) << 1 ;
V_31 |= ( F_43 ( V_130 ) >> V_115 ) & 0x1 ;
return V_31 ;
}
static int F_48 ( struct V_96 * V_96 ,
struct V_6 * V_7 , long V_97 )
{
struct V_30 * V_31 = V_7 -> V_32 ;
T_4 V_122 ;
T_4 V_28 = V_7 -> V_99 ;
int V_129 = V_7 -> V_100 ;
int V_115 = V_7 -> V_116 ;
V_122 = F_47 ( V_28 , V_129 , V_115 ) ;
while ( V_122 != V_124 ) {
switch ( V_122 ) {
case V_125 :
V_31 -> V_103 ++ ;
return V_104 ;
case V_126 :
V_31 -> V_106 ++ ;
V_7 -> V_109 = 0 ;
return V_111 ;
case V_131 :
V_31 -> V_127 ++ ;
V_7 -> V_109 = 0 ;
return V_110 ;
case V_132 :
V_7 -> V_109 = 0 ;
return V_104 ;
default:
F_41 () ;
}
V_122 = F_47 ( V_28 , V_129 , V_115 ) ;
}
V_7 -> V_109 ++ ;
return V_112 ;
}
static void F_49 ( struct V_96 * V_96 ,
struct V_6 * V_7 ,
struct V_6 * V_90 , struct V_30 * V_31 )
{
F_50 ( V_7 -> V_133 ) ;
V_7 -> V_134 ++ ;
if ( V_7 -> V_134 >= V_7 -> V_135 ) {
V_7 -> V_134 = 0 ;
F_35 ( V_90 ) ;
F_51 ( & V_90 -> V_136 ) ;
F_22 ( & V_96 -> V_73 , V_7 ) ;
F_52 ( & V_90 -> V_136 ) ;
F_36 ( V_90 ) ;
V_7 -> V_137 ++ ;
V_31 -> V_138 ++ ;
}
}
static void F_53 ( struct V_96 * V_96 ,
struct V_6 * V_7 , struct V_6 * V_90 ,
struct V_30 * V_31 )
{
V_90 -> V_139 = 1 ;
V_7 -> V_140 ++ ;
if ( V_7 -> V_140 >= V_7 -> V_141 ) {
V_7 -> V_140 = 0 ;
F_35 ( V_90 ) ;
F_51 ( & V_90 -> V_136 ) ;
F_22 ( & V_96 -> V_73 , V_7 ) ;
F_52 ( & V_90 -> V_136 ) ;
F_36 ( V_90 ) ;
V_7 -> V_137 ++ ;
V_31 -> V_142 ++ ;
}
}
static void F_54 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
int V_143 ;
struct V_6 * V_144 ;
struct V_6 * V_90 ;
T_3 V_145 ;
V_90 = V_7 -> V_55 ;
F_51 ( & V_90 -> V_146 ) ;
if ( ! V_7 -> V_147 ) {
V_31 -> V_148 ++ ;
V_145 = F_40 () ;
F_5 (tcpu) {
V_144 = & F_6 ( V_6 , V_143 ) ;
if ( V_144 -> V_55 == V_90 ) {
V_144 -> V_147 = 1 ;
V_144 -> V_149 =
V_145 + V_7 -> V_150 ;
}
}
}
F_52 ( & V_90 -> V_146 ) ;
}
static void F_55 ( int V_31 , struct V_6 * V_7 ,
struct V_6 * V_90 )
{
V_7 -> V_134 = 0 ;
V_7 -> V_140 = 0 ;
if ( V_31 != V_112 )
return;
if ( V_7 -> V_109 <= V_7 -> V_151 )
return;
if ( V_90 -> V_139 >= V_90 -> V_152 )
return;
V_90 -> V_139 ++ ;
}
static void F_56 ( T_3 V_153 , T_3 V_154 ,
struct V_6 * V_7 , struct V_30 * V_31 ,
int V_155 , int V_97 )
{
T_3 V_156 ;
if ( V_154 > V_153 ) {
V_156 = V_154 - V_153 ;
V_31 -> V_157 += V_156 ;
if ( ( V_155 == V_112 ) && ( V_97 == 1 ) ) {
V_7 -> V_158 ++ ;
V_7 -> V_159 += V_156 ;
if ( ( V_156 > V_160 ) &&
( V_7 -> V_158 > V_7 -> V_161 ) &&
( ( V_7 -> V_159 / V_7 -> V_158 ) >
V_160 ) ) {
V_31 -> V_162 ++ ;
F_54 ( V_7 , V_31 ) ;
}
}
} else
V_31 -> V_163 -- ;
if ( V_155 == V_112 && V_97 > 1 )
V_31 -> V_164 ++ ;
else if ( V_155 == V_104 ) {
V_31 -> V_165 ++ ;
if ( F_40 () > V_7 -> V_166 )
V_7 -> V_167 = 0 ;
V_7 -> V_167 ++ ;
if ( V_7 -> V_167 == 1 )
V_7 -> V_166 = F_40 () + V_7 -> V_150 ;
if ( V_7 -> V_167 > V_7 -> V_168 ) {
F_54 ( V_7 , V_31 ) ;
V_31 -> V_169 ++ ;
}
}
}
static void F_57 ( struct V_6 * V_90 , struct V_30 * V_31 )
{
T_5 * V_170 = & V_90 -> V_171 ;
T_6 * V_172 ;
V_172 = & V_90 -> V_173 ;
if ( ! F_58 ( V_170 , V_172 , V_90 -> V_139 ) ) {
V_31 -> V_174 ++ ;
do {
F_41 () ;
} while ( ! F_58 ( V_170 , V_172 , V_90 -> V_139 ) );
}
}
static void F_59 ( int V_155 , struct V_96 * V_96 ,
struct V_6 * V_7 , struct V_6 * V_90 ,
struct V_30 * V_31 )
{
if ( V_155 == V_110 )
F_49 ( V_96 , V_7 , V_90 , V_31 ) ;
else if ( V_155 == V_111 )
F_53 ( V_96 , V_7 , V_90 , V_31 ) ;
}
int F_60 ( struct V_77 * V_175 , struct V_6 * V_7 ,
struct V_96 * V_96 )
{
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 0 ;
long V_97 = 0 ;
unsigned long V_129 ;
T_3 V_153 ;
T_3 V_154 ;
struct V_30 * V_31 = V_7 -> V_32 ;
struct V_6 * V_90 = V_7 -> V_55 ;
struct V_179 * V_180 = NULL ;
struct V_181 * V_182 = NULL ;
if ( V_7 -> V_183 == V_184 ) {
V_178 = 1 ;
F_57 ( V_90 , V_31 ) ;
}
while ( V_90 -> V_91 )
F_41 () ;
V_153 = F_40 () ;
if ( V_178 )
V_180 = & V_96 -> V_185 . V_180 ;
else
V_182 = & V_96 -> V_185 . V_182 ;
do {
if ( V_97 == 0 ) {
if ( V_178 )
V_180 -> V_38 = V_186 ;
else
V_182 -> V_38 = V_186 ;
V_176 = V_7 -> V_187 ++ ;
} else {
if ( V_178 )
V_180 -> V_38 = V_54 ;
else
V_182 -> V_38 = V_54 ;
V_31 -> V_188 ++ ;
}
if ( V_178 )
V_180 -> V_189 = V_176 ;
else
V_182 -> V_189 = V_176 ;
V_129 = ( 1UL << V_190 ) | V_7 -> V_116 ;
V_7 -> V_107 = F_40 () ;
F_61 ( V_129 ) ;
V_97 ++ ;
V_177 = V_22 . V_191 ( V_96 , V_7 , V_97 ) ;
F_59 ( V_177 , V_96 , V_7 , V_90 , V_31 ) ;
if ( V_7 -> V_137 >= V_7 -> V_192 ) {
V_7 -> V_137 = 0 ;
V_31 -> V_193 ++ ;
V_177 = V_104 ;
break;
}
F_41 () ;
} while ( ( V_177 == V_110 ) ||
( V_177 == V_111 ) );
V_154 = F_40 () ;
F_55 ( V_177 , V_7 , V_90 ) ;
while ( V_90 -> V_91 )
F_41 () ;
F_62 ( & V_90 -> V_173 ) ;
F_56 ( V_153 , V_154 , V_7 , V_31 , V_177 , V_97 ) ;
if ( V_177 == V_104 )
return 1 ;
return 0 ;
}
static int F_63 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
int V_143 ;
struct V_6 * V_144 ;
struct V_6 * V_90 ;
V_90 = V_7 -> V_55 ;
F_51 ( & V_90 -> V_146 ) ;
if ( V_7 -> V_147 && ( F_40 () >= V_7 -> V_149 ) ) {
V_31 -> V_194 ++ ;
F_5 (tcpu) {
V_144 = & F_6 ( V_6 , V_143 ) ;
if ( V_144 -> V_55 == V_90 ) {
V_144 -> V_147 = 0 ;
V_144 -> V_158 = 0 ;
V_144 -> V_159 = 0 ;
V_144 -> V_167 = 0 ;
}
}
F_52 ( & V_90 -> V_146 ) ;
return 0 ;
}
F_52 ( & V_90 -> V_146 ) ;
return - 1 ;
}
static void F_64 ( struct V_30 * V_31 , int V_195 , int V_196 ,
int V_197 , struct V_96 * V_96 )
{
V_31 -> V_163 ++ ;
V_31 -> V_198 += V_197 + V_195 ;
V_31 -> V_199 += V_197 ;
V_31 -> V_200 += V_195 ;
V_196 = F_65 ( & V_96 -> V_73 ) ;
if ( V_195 ) {
V_31 -> V_201 ++ ;
V_31 -> V_202 += ( V_196 - 1 ) ;
} else
V_31 -> V_202 += V_196 ;
V_31 -> V_203 += V_196 ;
if ( V_196 >= 16 )
V_31 -> V_204 ++ ;
else if ( V_196 >= 8 )
V_31 -> V_205 ++ ;
else if ( V_196 >= 4 )
V_31 -> V_206 ++ ;
else if ( V_196 >= 2 )
V_31 -> V_207 ++ ;
else
V_31 -> V_208 ++ ;
}
static int F_66 ( struct V_77 * V_175 , struct V_6 * V_7 ,
struct V_96 * V_96 , int * V_209 , int * V_210 )
{
int V_5 ;
int V_62 ;
int V_211 = 0 ;
struct V_63 * V_64 ;
F_67 (cpu, flush_mask) {
V_64 = & V_7 -> V_48 -> V_65 [ V_5 ] ;
V_62 = V_64 -> V_62 - V_7 -> V_79 ;
F_68 ( V_62 , & V_96 -> V_73 ) ;
V_211 ++ ;
if ( V_64 -> V_9 == V_7 -> V_9 )
( * V_209 ) ++ ;
else
( * V_210 ) ++ ;
}
if ( ! V_211 )
return 1 ;
return 0 ;
}
const struct V_77 * F_69 ( const struct V_77 * V_77 ,
struct V_212 * V_213 ,
unsigned long V_214 ,
unsigned long V_215 ,
unsigned int V_5 )
{
int V_195 = 0 , V_197 = 0 , V_196 = 0 ;
struct V_96 * V_96 ;
struct V_77 * V_175 ;
struct V_30 * V_31 ;
struct V_6 * V_7 ;
unsigned long V_94 , V_216 , V_49 ;
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 )
return V_77 ;
V_31 = V_7 -> V_32 ;
V_31 -> V_217 ++ ;
if ( V_7 -> V_121 ) {
V_94 =
F_43 ( V_117 ) ;
V_216 = ( ( V_94 >> ( V_7 -> V_116 *
V_118 ) ) & V_95 ) << 1 ;
if ( V_216 == V_119 )
return V_77 ;
V_7 -> V_121 = 0 ;
}
if ( V_7 -> V_147 ) {
if ( F_63 ( V_7 , V_31 ) ) {
V_31 -> V_218 ++ ;
return V_77 ;
}
}
V_175 = (struct V_77 * ) F_6 ( V_219 , V_5 ) ;
F_70 ( V_175 , V_77 , F_71 ( V_5 ) ) ;
if ( F_72 ( V_5 , V_77 ) )
V_31 -> V_220 ++ ;
V_96 = V_7 -> V_221 ;
V_96 += ( V_222 * V_7 -> V_116 ) ;
F_73 ( & V_96 -> V_73 , V_223 ) ;
if ( F_66 ( V_175 , V_7 , V_96 , & V_195 , & V_197 ) )
return NULL ;
F_64 ( V_31 , V_195 , V_196 , V_197 , V_96 ) ;
if ( ! V_215 || ( V_215 - V_214 ) <= V_224 )
V_49 = V_214 ;
else
V_49 = V_50 ;
switch ( V_7 -> V_183 ) {
case V_184 :
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
if ( ! F_60 ( V_175 , V_7 , V_96 ) )
return NULL ;
else
return V_77 ;
}
struct V_17 * F_74 ( struct V_17 * V_18 ,
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
void F_75 ( struct V_13 * V_14 , struct V_6 * V_7 )
{
unsigned long V_234 ;
unsigned char V_20 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_17 * V_235 ;
V_234 = V_22 . V_40 () ;
V_20 = V_18 -> V_20 ;
if ( ( V_20 & V_234 ) == 0 ) {
V_235 = F_74 ( V_18 , V_7 ) ;
if ( V_235 ) {
F_15 ( V_14 , V_7 , 0 ) ;
return;
}
}
F_15 ( V_14 , V_7 , 1 ) ;
return;
}
void F_76 ( struct V_236 * V_237 )
{
int V_238 = 0 ;
T_3 V_239 ;
struct V_17 * V_18 ;
struct V_6 * V_7 ;
struct V_30 * V_31 ;
struct V_13 V_240 ;
F_77 () ;
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
if ( V_7 -> V_183 == V_225 )
F_75 ( & V_240 , V_7 ) ;
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
static void T_1 F_78 ( void )
{
int V_9 ;
int V_245 ;
int V_62 ;
unsigned long V_234 ;
V_245 = F_79 () ;
for ( V_9 = 0 ; V_9 < V_245 ; V_9 ++ ) {
if ( ! F_80 ( V_9 ) )
continue;
V_62 = F_81 ( V_9 ) ;
V_234 = F_82 ( V_62 ) ;
V_234 &= ~ ( 1L << V_246 ) ;
F_83 ( V_62 , V_234 ) ;
V_234 &= ~ ( ( unsigned long ) 0xf << V_247 ) ;
V_234 |= ( V_248 << V_247 ) ;
F_83 ( V_62 , V_234 ) ;
V_234 |= ( 1L << V_246 ) ;
if ( F_84 () ) {
V_234 &= ~ ( 1L << V_249 ) ;
} else if ( F_85 () ) {
V_234 &= ~ ( 1L << V_250 ) ;
V_234 |= ( 1L << V_251 ) ;
}
F_83 ( V_62 , V_234 ) ;
}
}
static void * F_86 ( struct V_252 * V_253 , T_7 * V_113 )
{
if ( * V_113 < F_87 () )
return V_113 ;
return NULL ;
}
static void * F_88 ( struct V_252 * V_253 , void * V_82 , T_7 * V_113 )
{
( * V_113 ) ++ ;
if ( * V_113 < F_87 () )
return V_113 ;
return NULL ;
}
static void F_89 ( struct V_252 * V_253 , void * V_82 )
{
}
static int F_90 ( struct V_252 * V_253 , void * V_82 )
{
struct V_30 * V_31 ;
struct V_6 * V_7 ;
int V_5 ;
V_5 = * ( T_7 * ) V_82 ;
if ( ! V_5 ) {
F_91 ( V_253 ,
L_6 ) ;
F_91 ( V_253 , L_7 ) ;
F_91 ( V_253 ,
L_8 ) ;
F_91 ( V_253 ,
L_9 ) ;
F_91 ( V_253 ,
L_10 ) ;
F_91 ( V_253 ,
L_11 ) ;
F_91 ( V_253 , L_12 ) ;
}
if ( V_5 < F_87 () && F_92 ( V_5 ) ) {
V_7 = & F_6 ( V_6 , V_5 ) ;
if ( V_7 -> V_4 ) {
F_93 ( V_253 , L_13 , V_5 ) ;
return 0 ;
}
V_31 = V_7 -> V_32 ;
F_93 ( V_253 ,
L_14 ,
V_5 , V_7 -> V_4 , V_31 -> V_163 ,
F_32 ( V_31 -> V_157 ) ,
V_31 -> V_220 , V_31 -> V_200 ,
V_31 -> V_199 , V_31 -> V_198 ,
V_31 -> V_201 , V_31 -> V_202 ,
V_31 -> V_203 , V_31 -> V_204 ) ;
F_93 ( V_253 , L_15 ,
V_31 -> V_205 , V_31 -> V_206 ,
V_31 -> V_207 , V_31 -> V_208 ,
V_31 -> V_106 , V_31 -> V_254 ) ;
F_93 ( V_253 , L_16 ,
V_31 -> V_188 , V_31 -> V_164 ,
V_31 -> V_138 , V_31 -> V_142 ,
V_31 -> V_165 , V_31 -> V_103 ,
V_31 -> V_255 , V_31 -> V_174 ) ;
F_93 ( V_253 , L_17 ,
V_31 -> V_148 , V_31 -> V_194 ,
V_31 -> V_120 , V_31 -> V_256 ,
V_31 -> V_257 , V_31 -> V_217 ,
V_31 -> V_218 , V_31 -> V_127 ,
V_31 -> V_193 , V_31 -> V_169 ,
V_31 -> V_162 ) ;
F_93 ( V_253 ,
L_18 ,
V_22 . V_258 ( F_94 ( V_5 ) ) ,
V_31 -> V_53 , F_32 ( V_31 -> V_242 ) ,
V_31 -> V_51 , V_31 -> V_52 , V_31 -> V_244 ,
V_31 -> V_243 , V_31 -> V_33 , V_31 -> V_42 ,
V_31 -> V_43 , V_31 -> V_69 ,
V_31 -> V_71 ) ;
}
return 0 ;
}
static T_8 F_95 ( struct V_253 * V_253 , char T_9 * V_259 ,
T_10 V_238 , T_7 * V_260 )
{
char * V_261 ;
int V_262 ;
V_261 = F_96 ( V_263 , L_19 ,
L_20 ,
L_21 ,
L_22 ,
V_139 , V_133 , V_135 ,
V_141 , V_192 , V_151 ,
V_264 , V_265 , V_150 ,
V_168 ) ;
if ( ! V_261 )
return - V_266 ;
V_262 = F_97 ( V_259 , V_238 , V_260 , V_261 , strlen ( V_261 ) ) ;
F_98 ( V_261 ) ;
return V_262 ;
}
static T_8 F_99 ( struct V_253 * V_253 , const char T_9 * V_267 ,
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
if ( F_100 ( V_270 , V_267 , V_238 ) )
return - V_271 ;
V_270 [ V_238 - 1 ] = '\0' ;
if ( ! strcmp ( V_270 , L_23 ) ) {
F_4 () ;
return V_238 ;
} else if ( ! strcmp ( V_270 , L_24 ) ) {
F_7 () ;
return V_238 ;
}
if ( F_101 ( V_270 , 10 , & V_269 ) < 0 ) {
F_102 ( L_25 , V_270 ) ;
return - V_3 ;
}
if ( V_269 == 0 ) {
V_268 = F_103 ( V_272 ) ;
F_102 ( L_26 ) ;
F_102 ( L_27 ) ;
for ( V_25 = 0 ; V_25 < V_268 ; V_25 ++ )
F_102 ( L_28 , V_272 [ V_25 ] ) ;
} else if ( V_269 == - 1 ) {
F_5 (cpu) {
V_31 = & F_6 ( V_273 , V_5 ) ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
}
}
return V_238 ;
}
static int F_104 ( const char * V_274 )
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
static int F_105 ( struct V_6 * V_7 , char * V_276 ,
int V_238 )
{
char * V_277 ;
char * V_278 ;
int V_211 = 0 ;
int V_275 ;
int V_279 = F_103 ( V_280 ) ;
V_277 = V_276 + strspn ( V_276 , V_281 ) ;
V_278 = V_277 ;
for (; * V_277 ; V_277 = V_278 + strspn ( V_278 , V_281 ) ) {
V_278 = V_277 + strcspn ( V_277 , V_281 ) ;
V_211 ++ ;
if ( V_278 == V_277 )
break;
}
if ( V_211 != V_279 ) {
F_3 ( L_29 , V_279 ) ;
return - V_3 ;
}
V_277 = V_276 + strspn ( V_276 , V_281 ) ;
V_278 = V_277 ;
for ( V_211 = 0 ; * V_277 ; V_277 = V_278 + strspn ( V_278 , V_281 ) , V_211 ++ ) {
V_278 = V_277 + strcspn ( V_277 , V_281 ) ;
V_275 = F_104 ( V_277 ) ;
switch ( V_211 ) {
case 0 :
if ( V_275 == 0 ) {
V_139 = V_282 ;
V_152 = V_282 ;
continue;
}
if ( V_275 < 1 || V_275 > V_7 -> V_61 ) {
F_102 (
L_30 ,
V_275 ) ;
return - V_3 ;
}
V_139 = V_275 ;
V_152 = V_275 ;
continue;
default:
if ( V_275 == 0 )
* V_280 [ V_211 ] . V_283 = V_280 [ V_211 ] . V_284 ;
else
* V_280 [ V_211 ] . V_283 = V_275 ;
continue;
}
if ( V_278 == V_277 )
break;
}
return 0 ;
}
static T_8 F_106 ( struct V_253 * V_253 , const char T_9 * V_267 ,
T_10 V_238 , T_7 * V_82 )
{
int V_5 ;
int V_262 ;
char V_276 [ 100 ] ;
struct V_6 * V_7 ;
if ( V_238 == 0 || V_238 > sizeof( V_276 ) - 1 )
return - V_3 ;
if ( F_100 ( V_276 , V_267 , V_238 ) )
return - V_271 ;
V_276 [ V_238 ] = '\0' ;
V_5 = F_107 () ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_262 = F_105 ( V_7 , V_276 , V_238 ) ;
F_108 () ;
if ( V_262 )
return V_262 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_139 = V_139 ;
V_7 -> V_152 = V_139 ;
V_7 -> V_133 = V_133 ;
V_7 -> V_135 = V_135 ;
V_7 -> V_141 = V_141 ;
V_7 -> V_192 = V_192 ;
V_7 -> V_151 = V_151 ;
V_7 -> V_285 = V_264 ;
V_7 -> V_161 = V_265 ;
V_7 -> V_150 = F_33 ( V_150 ) ;
V_7 -> V_168 = V_168 ;
}
return V_238 ;
}
static int F_109 ( struct V_286 * V_286 , struct V_253 * V_253 )
{
return F_110 ( V_253 , & V_287 ) ;
}
static int F_111 ( struct V_286 * V_286 , struct V_253 * V_253 )
{
return 0 ;
}
static int T_1 F_112 ( void )
{
struct V_288 * V_289 ;
if ( ! F_113 () )
return 0 ;
V_289 = F_114 ( V_290 , 0444 , NULL ,
& V_291 ) ;
if ( ! V_289 ) {
F_115 ( L_31 ,
V_290 ) ;
return - V_3 ;
}
V_292 = F_116 ( V_293 , NULL ) ;
if ( ! V_292 ) {
F_115 ( L_32 ,
V_293 ) ;
return - V_3 ;
}
V_294 = F_117 ( V_295 , 0600 ,
V_292 , NULL , & V_296 ) ;
if ( ! V_294 ) {
F_115 ( L_33 ,
V_295 ) ;
return - V_3 ;
}
return 0 ;
}
static void F_118 ( int V_10 , int V_62 , int V_297 )
{
int V_25 ;
int V_5 ;
int V_178 = 0 ;
unsigned long V_298 ;
unsigned long V_299 ;
unsigned long V_300 ;
T_10 V_301 ;
struct V_96 * V_96 ;
struct V_96 * V_302 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
struct V_6 * V_7 ;
V_301 = sizeof( struct V_96 ) * V_303 * V_222 ;
V_96 = F_119 ( V_301 , V_263 , V_10 ) ;
F_120 ( ! V_96 ) ;
V_298 = F_121 ( V_96 ) ;
V_300 = F_122 ( V_298 ) ;
V_299 = V_22 . V_304 ( V_298 ) ;
if ( F_123 () )
V_178 = 1 ;
F_124 ( V_62 , ( V_300 << V_305 | V_299 ) ) ;
for ( V_25 = 0 , V_302 = V_96 ; V_25 < ( V_303 * V_222 ) ; V_25 ++ , V_302 ++ ) {
memset ( V_302 , 0 , sizeof( struct V_96 ) ) ;
if ( V_178 ) {
V_180 = & V_302 -> V_185 . V_180 ;
V_180 -> V_306 = 1 ;
V_180 -> V_307 =
F_125 ( V_297 ) ;
V_180 -> V_308 = V_309 ;
V_180 -> V_310 = V_311 ;
V_180 -> V_312 = 1 ;
} else {
V_182 = & V_302 -> V_185 . V_182 ;
V_182 -> V_306 = 1 ;
V_182 -> V_307 =
F_125 ( V_297 ) ;
V_182 -> V_308 = V_309 ;
V_182 -> V_310 = V_311 ;
}
}
F_5 (cpu) {
if ( V_62 != F_81 ( F_12 ( V_5 ) ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_221 = V_96 ;
}
}
static void F_126 ( int V_10 , int V_62 )
{
int V_5 ;
T_10 V_313 ;
char * V_314 ;
void * V_315 ;
unsigned long V_316 , V_317 , V_318 , V_319 ;
struct V_17 * V_320 ;
struct V_6 * V_7 ;
V_313 = ( V_34 + 1 ) * sizeof( struct V_17 ) ;
V_315 = F_119 ( V_313 , V_263 , V_10 ) ;
V_320 = (struct V_17 * ) V_315 ;
F_120 ( ! V_320 ) ;
V_314 = ( char * ) V_320 + 31 ;
V_320 = (struct V_17 * ) ( ( ( unsigned long ) V_314 >> 5 ) << 5 ) ;
F_5 (cpu) {
if ( V_62 != F_94 ( V_5 ) )
continue;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_36 = V_320 ;
V_7 -> V_241 = V_320 ;
V_7 -> V_35 = V_320 + ( V_34 - 1 ) ;
}
V_317 = V_22 . V_304 ( F_121 ( V_320 ) ) ;
V_318 = V_22 . V_304 ( F_121 ( V_320 + ( V_34 - 1 ) ) ) ;
V_7 = & F_6 ( V_6 , F_21 () ) ;
if ( V_7 -> V_183 <= V_226 ) {
V_319 = V_317 ;
V_316 = F_122 ( F_121 ( V_320 ) ) ;
V_317 = ( V_316 << V_321 ) | V_319 ;
F_127 ( V_62 , V_319 ) ;
}
V_22 . V_322 ( V_62 , V_317 ) ;
V_22 . V_323 ( V_62 , V_318 ) ;
memset ( V_320 , 0 , sizeof( struct V_17 ) * V_34 ) ;
}
static void T_1 F_128 ( int V_9 , int V_324 , int V_297 )
{
int V_10 ;
int V_62 ;
unsigned long V_325 ;
V_10 = F_8 ( V_9 ) ;
V_62 = F_81 ( V_9 ) ;
F_118 ( V_10 , V_62 , V_297 ) ;
F_126 ( V_10 , V_62 ) ;
V_325 = F_11 ( V_9 ) | V_326 ;
F_129 ( V_62 , ( ( V_325 << 32 ) | V_324 ) ) ;
}
static int F_130 ( void )
{
unsigned long V_234 ;
int V_327 ;
int V_328 ;
int V_129 ;
int V_329 ;
int V_262 ;
unsigned long V_330 ;
if ( F_123 () ) {
V_327 = V_248 & V_331 ;
V_234 = F_38 ( V_332 ) ;
V_129 = ( V_234 >> V_333 ) & V_334 ;
V_234 = F_38 ( V_335 ) ;
V_328 = ( V_234 >> V_336 ) & V_337 ;
V_330 = V_338 [ V_129 ] ;
V_330 *= ( V_327 * V_328 ) ;
V_262 = V_330 / 1000 ;
} else {
V_234 = F_38 ( V_339 ) ;
V_234 = ( V_234 & V_340 ) >> V_341 ;
if ( V_234 & ( 1L << V_342 ) )
V_329 = 80 ;
else
V_329 = 10 ;
V_327 = V_234 & V_343 ;
V_262 = V_327 * V_329 ;
}
return V_262 ;
}
static void T_1 F_131 ( void )
{
int V_5 ;
struct V_6 * V_7 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_147 = 0 ;
if ( V_4 )
V_7 -> V_4 = true ;
V_7 -> V_32 = & F_6 ( V_273 , V_5 ) ;
V_7 -> V_128 = F_34 ( 2 * V_108 ) ;
V_7 -> V_139 = V_139 ;
V_7 -> V_152 = V_139 ;
V_7 -> V_133 = V_133 ;
V_7 -> V_135 = V_135 ;
V_7 -> V_141 = V_141 ;
V_7 -> V_192 = V_192 ;
V_7 -> V_151 = V_151 ;
V_7 -> V_285 = V_264 ;
V_7 -> V_161 = V_265 ;
V_7 -> V_150 = F_33 ( V_150 ) ;
V_7 -> V_168 = V_168 ;
F_132 ( & V_7 -> V_136 ) ;
F_132 ( & V_7 -> V_171 ) ;
F_132 ( & V_7 -> V_146 ) ;
}
}
static int T_1 F_133 ( int V_297 ,
struct V_344 * V_345 ,
unsigned char * V_346 )
{
int V_5 ;
int V_62 ;
int V_9 ;
int V_347 ;
struct V_6 * V_7 ;
struct V_344 * V_348 ;
struct V_349 * V_350 ;
F_5 (cpu) {
V_7 = & F_6 ( V_6 , V_5 ) ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_62 = F_134 ( V_5 ) -> V_62 ;
if ( ( V_62 - V_297 ) >= V_223 ) {
F_135 (
L_34 ,
V_5 , V_62 , V_297 , V_223 ) ;
return 1 ;
}
V_7 -> V_351 = F_136 ( V_5 ) ;
V_7 -> V_79 = V_297 ;
V_9 = F_134 ( V_5 ) -> V_352 ;
* ( V_346 + ( V_9 / 8 ) ) |= ( 1 << ( V_9 % 8 ) ) ;
V_348 = & V_345 [ V_9 ] ;
V_348 -> V_353 ++ ;
V_348 -> V_9 = V_9 ;
V_348 -> V_62 = V_62 ;
V_347 = V_7 -> V_351 & 1 ;
V_348 -> V_354 |= ( 1 << V_347 ) ;
V_350 = & V_348 -> V_347 [ V_347 ] ;
V_350 -> V_355 [ V_350 -> V_353 ] = V_5 ;
V_350 -> V_353 ++ ;
if ( V_350 -> V_353 > V_356 ) {
F_135 ( L_35 ,
V_350 -> V_353 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_137 ( struct V_6 * V_47 )
{
int V_5 ;
T_10 V_357 = sizeof( struct V_63 ) * F_87 () ;
V_47 -> V_65 = F_119 ( V_357 , V_263 , V_47 -> V_351 ) ;
memset ( V_47 -> V_65 , 0 , V_357 ) ;
F_5 (cpu) {
V_47 -> V_65 [ V_5 ] . V_62 = F_134 ( V_5 ) -> V_62 ;
V_47 -> V_65 [ V_5 ] . V_9 = F_134 ( V_5 ) -> V_352 ;
}
}
static void F_138 ( struct V_6 * V_90 )
{
int V_358 = sizeof( T_2 ) ;
V_90 -> V_77 = F_139 ( V_358 , V_263 , V_90 -> V_351 ) ;
}
static int F_140 ( struct V_349 * V_350 , struct V_344 * V_348 ,
struct V_6 * * V_359 ,
struct V_6 * * V_360 )
{
int V_25 , V_5 , V_116 ;
struct V_6 * V_7 ;
for ( V_25 = 0 ; V_25 < V_350 -> V_353 ; V_25 ++ ) {
V_5 = V_350 -> V_355 [ V_25 ] ;
V_7 = & F_6 ( V_6 , V_5 ) ;
V_7 -> V_5 = V_5 ;
if ( V_25 == 0 ) {
* V_359 = V_7 ;
if ( ! ( * V_360 ) )
* V_360 = V_7 ;
}
V_7 -> V_61 = V_348 -> V_353 ;
V_7 -> V_58 = V_350 -> V_353 ;
V_7 -> V_48 = * V_359 ;
V_7 -> V_9 = V_348 -> V_9 ;
if ( F_123 () )
V_7 -> V_183 = V_184 ;
else if ( F_84 () )
V_7 -> V_183 = V_225 ;
else if ( F_85 () )
V_7 -> V_183 = V_226 ;
else if ( F_141 () )
V_7 -> V_183 = V_229 ;
else {
F_135 ( L_36 ) ;
return 1 ;
}
V_7 -> V_55 = * V_360 ;
V_116 = F_142 ( V_5 ) ;
V_7 -> V_116 = V_116 ;
if ( V_116 < V_361 ) {
V_7 -> V_99 = V_117 ;
V_7 -> V_100 = V_116 * V_118 ;
} else {
V_7 -> V_99 = V_362 ;
V_7 -> V_100 = ( V_116 - V_361 )
* V_118 ;
}
if ( V_7 -> V_116 >= V_363 ) {
F_135 ( L_37 ,
V_7 -> V_116 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_143 ( int V_245 ,
struct V_344 * V_345 ,
unsigned char * V_346 )
{
int V_347 ;
int V_9 ;
unsigned short V_354 ;
for ( V_9 = 0 ; V_9 < V_245 ; V_9 ++ ) {
struct V_344 * V_348 ;
struct V_6 * V_47 = NULL ;
struct V_6 * V_90 = NULL ;
if ( ! ( * ( V_346 + ( V_9 / 8 ) ) & ( 1 << ( V_9 % 8 ) ) ) )
continue;
V_348 = & V_345 [ V_9 ] ;
V_354 = V_348 -> V_354 ;
V_347 = 0 ;
while ( V_354 ) {
struct V_349 * V_350 ;
if ( ( V_354 & 1 ) ) {
V_350 = & V_348 -> V_347 [ V_347 ] ;
if ( F_140 ( V_350 , V_348 , & V_47 , & V_90 ) )
return 1 ;
F_137 ( V_47 ) ;
}
V_347 ++ ;
V_354 = ( V_354 >> 1 ) ;
}
F_138 ( V_90 ) ;
}
return 0 ;
}
static int T_1 F_144 ( int V_245 , int V_364 )
{
unsigned char * V_346 ;
void * V_315 ;
struct V_344 * V_345 ;
if ( F_85 () || F_84 () || F_123 () )
V_108 = F_130 () ;
V_315 = F_145 ( V_245 * sizeof( struct V_344 ) , V_263 ) ;
V_345 = (struct V_344 * ) V_315 ;
memset ( V_345 , 0 , V_245 * sizeof( struct V_344 ) ) ;
V_346 = F_146 ( ( V_245 + 7 ) / 8 , V_263 ) ;
if ( F_133 ( V_364 , V_345 , V_346 ) )
goto V_365;
if ( F_143 ( V_245 , V_345 , V_346 ) )
goto V_365;
F_98 ( V_345 ) ;
F_98 ( V_346 ) ;
F_131 () ;
return 0 ;
V_365:
F_98 ( V_345 ) ;
F_98 ( V_346 ) ;
return 1 ;
}
static int T_1 F_147 ( void )
{
int V_9 ;
int V_62 ;
int V_245 ;
int V_366 ;
int V_367 ;
int V_324 ;
T_11 * V_76 ;
if ( ! F_113 () )
return 0 ;
if ( F_141 () )
V_22 = V_368 ;
else if ( F_85 () )
V_22 = V_369 ;
else if ( F_84 () )
V_22 = V_369 ;
else if ( F_123 () )
V_22 = V_370 ;
F_148 (cur_cpu) {
V_76 = & F_6 ( V_219 , V_366 ) ;
F_149 ( V_76 , V_263 , F_136 ( V_366 ) ) ;
}
V_245 = F_79 () ;
V_160 = F_34 ( V_264 ) ;
V_371 = 0x7fffffff ;
for ( V_9 = 0 ; V_9 < V_245 ; V_9 ++ ) {
V_367 = F_80 ( V_9 ) ;
if ( V_367 && ( F_81 ( V_9 ) < V_371 ) )
V_371 = F_81 ( V_9 ) ;
}
if ( F_85 () || F_84 () || F_123 () )
F_78 () ;
if ( F_144 ( V_245 , V_371 ) ) {
F_7 () ;
V_8 = 1 ;
return 0 ;
}
V_324 = V_372 ;
F_150 (uvhub) {
if ( F_80 ( V_9 ) )
F_128 ( V_9 , V_324 , V_371 ) ;
}
F_151 ( V_324 , V_373 ) ;
F_150 (uvhub) {
if ( F_80 ( V_9 ) ) {
unsigned long V_275 ;
unsigned long V_28 ;
V_62 = F_81 ( V_9 ) ;
V_275 = 1L << 63 ;
F_152 ( V_62 , V_275 ) ;
V_28 = 1 ;
if ( ! F_123 () )
F_153 ( V_62 , V_28 ) ;
}
}
return 0 ;
}
