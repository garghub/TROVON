static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_6 -> V_8 ;
F_3 ( V_2 , V_4 ) ;
V_6 -> V_9 = F_4 ( V_4 ) -> V_10 ;
if ( V_6 -> V_11 == 2 )
V_6 -> V_11 = 3 ;
V_6 -> V_8 += F_5 ( V_4 ) ;
if ( ! V_7 || V_6 -> V_12 )
F_6 ( V_2 ) ;
}
static inline T_1 F_7 ( const struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_8 ( F_9 ( V_6 ) , V_6 -> V_9 ) )
return V_6 -> V_9 ;
else
return F_9 ( V_6 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = F_11 ( V_2 ) ;
int V_15 = V_6 -> V_16 ;
if ( V_14 ) {
unsigned int V_17 = F_12 ( V_14 ) ;
if ( V_17 < V_15 ) {
V_15 = V_17 ;
V_6 -> V_16 = V_15 ;
}
}
return ( T_2 ) V_15 ;
}
static void F_13 ( struct V_1 * V_2 , const struct V_13 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_18 = V_19 - V_6 -> V_20 ;
T_4 V_21 = F_14 ( V_6 , V_14 ) ;
T_4 V_22 = V_6 -> V_23 ;
F_15 ( V_2 , V_24 ) ;
V_6 -> V_25 = F_16 ( V_2 ) ;
V_21 = F_17 ( V_21 , V_22 ) ;
while ( ( V_18 -= F_18 ( V_2 ) -> V_26 ) > 0 && V_22 > V_21 )
V_22 >>= 1 ;
V_6 -> V_23 = F_19 ( V_22 , V_21 ) ;
V_6 -> V_27 = V_19 ;
V_6 -> V_28 = 0 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
const T_4 V_31 = V_19 ;
if ( V_32 &&
( ! V_6 -> V_8 && ( T_3 ) ( V_31 - V_6 -> V_20 ) > V_30 -> V_26 ) )
F_13 ( V_2 , F_11 ( V_2 ) ) ;
V_6 -> V_20 = V_31 ;
if ( ( T_4 ) ( V_31 - V_30 -> V_33 . V_34 ) < V_30 -> V_33 . V_35 )
V_30 -> V_33 . V_36 = 1 ;
}
static inline void F_21 ( struct V_1 * V_2 , unsigned int V_37 )
{
F_22 ( V_2 , V_37 ) ;
F_23 ( V_2 , V_38 ) ;
}
void F_24 ( int V_39 , T_1 V_15 ,
T_1 * V_40 , T_1 * V_41 ,
int V_42 , T_5 * V_43 ,
T_1 V_44 )
{
unsigned int V_45 = ( V_39 < 0 ? 0 : V_39 ) ;
if ( * V_41 == 0 )
( * V_41 ) = ( 65535 << 14 ) ;
V_45 = F_17 ( * V_41 , V_45 ) ;
if ( V_45 > V_15 )
V_45 = ( V_45 / V_15 ) * V_15 ;
if ( V_46 )
( * V_40 ) = F_17 ( V_45 , V_47 ) ;
else
( * V_40 ) = V_45 ;
( * V_43 ) = 0 ;
if ( V_42 ) {
V_45 = F_25 ( T_4 , V_48 [ 2 ] , V_49 ) ;
V_45 = F_26 ( T_4 , V_45 , * V_41 ) ;
while ( V_45 > 65535 && ( * V_43 ) < 14 ) {
V_45 >>= 1 ;
( * V_43 ) ++ ;
}
}
if ( V_15 > ( 1 << * V_43 ) ) {
int V_50 = V_51 ;
if ( V_15 > 1460 )
V_50 =
F_25 ( T_4 , ( 1460 * V_51 ) / V_15 , 2 ) ;
if ( V_44 )
* V_40 = F_17 ( * V_40 , V_44 * V_15 ) ;
else
* V_40 = F_17 ( * V_40 , V_50 * V_15 ) ;
}
( * V_41 ) = F_17 ( 65535U << ( * V_43 ) , * V_41 ) ;
}
static T_6 F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_52 = F_28 ( V_6 ) ;
T_4 V_53 = F_29 ( V_2 ) ;
if ( V_53 < V_52 ) {
V_53 = F_30 ( V_52 , 1 << V_6 -> V_54 . V_43 ) ;
}
V_6 -> V_40 = V_53 ;
V_6 -> V_55 = V_6 -> V_56 ;
if ( ! V_6 -> V_54 . V_43 && V_46 )
V_53 = F_17 ( V_53 , V_47 ) ;
else
V_53 = F_17 ( V_53 , ( 65535U << V_6 -> V_54 . V_43 ) ) ;
V_53 >>= V_6 -> V_54 . V_43 ;
if ( V_53 == 0 )
V_6 -> V_57 = 0 ;
return V_53 ;
}
static inline void F_31 ( const struct V_5 * V_6 , struct V_3 * V_4 )
{
F_4 ( V_4 ) -> V_58 &= ~ V_59 ;
if ( ! ( V_6 -> V_60 & V_61 ) )
F_4 ( V_4 ) -> V_58 &= ~ V_62 ;
}
static inline void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_60 = 0 ;
if ( V_63 == 1 ) {
F_4 ( V_4 ) -> V_58 |= V_62 | V_59 ;
V_6 -> V_60 = V_61 ;
}
}
static T_7 void
F_33 ( const struct V_64 * V_65 , struct V_66 * V_67 )
{
if ( F_34 ( V_65 ) -> V_68 )
V_67 -> V_69 = 1 ;
}
static inline void F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_60 & V_61 ) {
if ( V_4 -> V_71 != V_70 &&
! F_8 ( F_4 ( V_4 ) -> V_72 , V_6 -> V_9 ) ) {
F_36 ( V_2 ) ;
if ( V_6 -> V_60 & V_73 ) {
V_6 -> V_60 &= ~ V_73 ;
F_37 ( V_4 ) -> V_74 = 1 ;
F_38 ( V_4 ) -> V_75 |= V_76 ;
}
} else {
F_39 ( V_2 ) ;
}
if ( V_6 -> V_60 & V_77 )
F_37 ( V_4 ) -> V_69 = 1 ;
}
}
static void F_40 ( struct V_3 * V_4 , T_4 V_72 , T_8 V_78 )
{
V_4 -> V_79 = V_80 ;
V_4 -> V_81 = 0 ;
F_4 ( V_4 ) -> V_58 = V_78 ;
F_4 ( V_4 ) -> V_82 = 0 ;
F_38 ( V_4 ) -> V_83 = 1 ;
F_38 ( V_4 ) -> V_84 = 0 ;
F_38 ( V_4 ) -> V_75 = 0 ;
F_4 ( V_4 ) -> V_72 = V_72 ;
if ( V_78 & ( V_85 | V_86 ) )
V_72 ++ ;
F_4 ( V_4 ) -> V_10 = V_72 ;
}
static inline bool F_41 ( const struct V_5 * V_6 )
{
return V_6 -> V_87 != V_6 -> V_88 ;
}
static T_8 F_42 ( T_8 V_89 )
{
int V_90 ;
if ( V_89 > 0 )
return V_89 ;
V_90 = F_43 ( V_91 ) ;
if ( V_90 <= 0 )
return 0 ;
if ( V_90 <= V_92 )
return V_92 ;
if ( V_90 >= V_93 )
return V_93 ;
if ( V_90 & 1 )
V_90 ++ ;
return ( T_8 ) V_90 ;
}
static void F_44 ( T_9 * V_94 , struct V_5 * V_6 ,
struct V_95 * V_96 )
{
T_6 V_97 = V_96 -> V_97 ;
if ( F_45 ( V_98 & V_97 ) ) {
if ( F_45 ( V_99 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_100 << 24 ) |
( V_101 << 16 ) |
( V_102 << 8 ) |
V_103 ) ;
} else {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_102 << 8 ) |
V_103 ) ;
}
V_97 &= ~ V_99 ;
V_96 -> V_105 = ( T_5 * ) V_94 ;
V_94 += 4 ;
}
if ( F_45 ( V_96 -> V_15 ) ) {
* V_94 ++ = F_46 ( ( V_106 << 24 ) |
( V_107 << 16 ) |
V_96 -> V_15 ) ;
}
if ( F_47 ( V_108 & V_97 ) ) {
if ( F_45 ( V_109 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_110 << 24 ) |
( V_111 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
V_97 &= ~ V_109 ;
} else {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
}
* V_94 ++ = F_46 ( V_96 -> V_114 ) ;
* V_94 ++ = F_46 ( V_96 -> V_115 ) ;
}
if ( F_45 ( V_99 & V_97 ) ) {
T_5 * V_116 = V_96 -> V_105 ;
T_8 V_90 = V_96 -> V_117 ;
if ( 0x2 & V_90 ) {
T_5 * V_118 = ( T_5 * ) V_94 ;
* V_118 ++ = V_100 ;
* V_118 ++ = V_101 + V_90 ;
* V_118 ++ = * V_116 ++ ;
* V_118 ++ = * V_116 ++ ;
V_94 ++ ;
V_90 -= 2 ;
} else {
* V_94 ++ = F_46 ( ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_100 << 8 ) |
V_101 ) +
V_90 ) ;
}
if ( V_90 > 0 ) {
memcpy ( V_94 , V_116 , V_90 ) ;
V_94 += ( V_90 / 4 ) ;
}
}
if ( F_45 ( V_109 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_110 << 8 ) |
V_111 ) ;
}
if ( F_45 ( V_119 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_120 << 16 ) |
( V_121 << 8 ) |
V_96 -> V_122 ) ;
}
if ( F_45 ( V_96 -> V_123 ) ) {
struct V_124 * V_125 = V_6 -> V_54 . V_126 ?
V_6 -> V_127 : V_6 -> V_128 ;
int V_129 ;
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_130 << 8 ) |
( V_131 + ( V_96 -> V_123 *
V_132 ) ) ) ;
for ( V_129 = 0 ; V_129 < V_96 -> V_123 ;
++ V_129 ) {
* V_94 ++ = F_46 ( V_125 [ V_129 ] . V_133 ) ;
* V_94 ++ = F_46 ( V_125 [ V_129 ] . V_10 ) ;
}
V_6 -> V_54 . V_126 = 0 ;
}
if ( F_45 ( V_134 & V_97 ) ) {
struct V_135 * V_136 = V_96 -> V_137 ;
* V_94 ++ = F_46 ( ( V_138 << 24 ) |
( ( V_139 + V_136 -> V_71 ) << 16 ) |
V_140 ) ;
memcpy ( V_94 , V_136 -> V_141 , V_136 -> V_71 ) ;
if ( ( V_136 -> V_71 & 3 ) == 2 ) {
T_8 * V_142 = ( ( T_8 * ) V_94 ) + V_136 -> V_71 ;
V_142 [ 0 ] = V_142 [ 1 ] = V_104 ;
}
V_94 += ( V_136 -> V_71 + 3 ) >> 2 ;
}
}
static unsigned int F_48 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_143 * * V_144 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_145 * V_146 = V_6 -> V_147 ;
unsigned int V_148 = V_149 ;
T_8 V_90 = ( ! V_6 -> V_54 . V_150 && V_146 != NULL ) ?
F_42 ( V_146 -> V_151 ) :
0 ;
struct V_152 * V_153 = V_6 -> V_154 ;
#ifdef F_49
* V_144 = V_6 -> V_155 -> V_156 ( V_2 , V_2 ) ;
if ( * V_144 ) {
V_96 -> V_97 |= V_98 ;
V_148 -= V_157 ;
}
#else
* V_144 = NULL ;
#endif
V_96 -> V_15 = F_10 ( V_2 ) ;
V_148 -= V_158 ;
if ( F_47 ( V_159 && * V_144 == NULL ) ) {
V_96 -> V_97 |= V_108 ;
V_96 -> V_114 = F_4 ( V_4 ) -> V_160 ;
V_96 -> V_115 = V_6 -> V_54 . V_161 ;
V_148 -= V_162 ;
}
if ( F_47 ( V_163 ) ) {
V_96 -> V_122 = V_6 -> V_54 . V_43 ;
V_96 -> V_97 |= V_119 ;
V_148 -= V_164 ;
}
if ( F_47 ( V_165 ) ) {
V_96 -> V_97 |= V_109 ;
if ( F_45 ( ! ( V_108 & V_96 -> V_97 ) ) )
V_148 -= V_166 ;
}
if ( V_153 && V_153 -> V_167 . V_71 >= 0 ) {
T_4 V_168 = V_139 + V_153 -> V_167 . V_71 ;
V_168 = ( V_168 + 3 ) & ~ 3U ;
if ( V_148 >= V_168 ) {
V_96 -> V_97 |= V_134 ;
V_96 -> V_137 = & V_153 -> V_167 ;
V_148 -= V_168 ;
V_6 -> V_169 = 1 ;
}
}
if ( * V_144 == NULL &&
( V_108 & V_96 -> V_97 ) &&
V_90 > 0 ) {
int V_168 = V_101 + V_90 ;
if ( 0x2 & V_168 ) {
V_168 += 2 ;
if ( V_168 > V_148 ) {
V_90 -= 2 ;
V_168 -= 4 ;
}
}
while ( V_168 > V_148 && V_92 <= V_90 ) {
V_90 -= 4 ;
V_168 -= 4 ;
}
if ( V_92 <= V_90 ) {
V_96 -> V_97 |= V_99 ;
V_96 -> V_105 = ( T_5 * ) & V_146 -> V_170 [ 0 ] ;
V_96 -> V_117 = V_90 ;
V_146 -> V_151 = V_90 ;
if ( V_146 -> V_151 != V_146 -> V_171 ) {
F_50 ( & V_146 -> V_170 [ 0 ] ,
V_90 ) ;
V_146 -> V_171 = V_90 ;
}
V_148 -= V_168 ;
}
}
return V_149 - V_148 ;
}
static unsigned int F_51 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
unsigned int V_15 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_143 * * V_144 ,
struct V_172 * V_173 )
{
struct V_174 * V_175 = F_34 ( V_65 ) ;
unsigned int V_148 = V_149 ;
T_8 V_176 = ( V_173 != NULL && ! V_173 -> V_150 ) ?
V_173 -> V_176 :
0 ;
#ifdef F_49
* V_144 = F_52 ( V_65 ) -> V_155 -> V_156 ( V_2 , V_65 ) ;
if ( * V_144 ) {
V_96 -> V_97 |= V_98 ;
V_148 -= V_157 ;
V_175 -> V_177 &= ! V_175 -> V_178 ;
}
#else
* V_144 = NULL ;
#endif
V_96 -> V_15 = V_15 ;
V_148 -= V_158 ;
if ( F_47 ( V_175 -> V_42 ) ) {
V_96 -> V_122 = V_175 -> V_43 ;
V_96 -> V_97 |= V_119 ;
V_148 -= V_164 ;
}
if ( F_47 ( V_175 -> V_177 ) ) {
V_96 -> V_97 |= V_108 ;
V_96 -> V_114 = F_4 ( V_4 ) -> V_160 ;
V_96 -> V_115 = V_65 -> V_161 ;
V_148 -= V_162 ;
}
if ( F_47 ( V_175 -> V_178 ) ) {
V_96 -> V_97 |= V_109 ;
if ( F_45 ( ! V_175 -> V_177 ) )
V_148 -= V_166 ;
}
if ( * V_144 == NULL &&
V_175 -> V_177 &&
V_176 > V_101 ) {
int V_168 = V_176 ;
if ( 0x2 & V_168 ) {
V_168 += 2 ;
}
if ( V_168 <= V_148 ) {
V_96 -> V_97 |= V_99 ;
V_96 -> V_117 = V_176 - V_101 ;
V_148 -= V_168 ;
} else {
V_173 -> V_150 = 1 ;
V_96 -> V_117 = 0 ;
}
}
return V_149 - V_148 ;
}
static unsigned int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_143 * * V_144 )
{
struct V_179 * V_180 = V_4 ? F_4 ( V_4 ) : NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_181 = 0 ;
unsigned int V_182 ;
#ifdef F_49
* V_144 = V_6 -> V_155 -> V_156 ( V_2 , V_2 ) ;
if ( F_45 ( * V_144 ) ) {
V_96 -> V_97 |= V_98 ;
V_181 += V_157 ;
}
#else
* V_144 = NULL ;
#endif
if ( F_47 ( V_6 -> V_54 . V_177 ) ) {
V_96 -> V_97 |= V_108 ;
V_96 -> V_114 = V_180 ? V_180 -> V_160 : 0 ;
V_96 -> V_115 = V_6 -> V_54 . V_161 ;
V_181 += V_162 ;
}
V_182 = V_6 -> V_54 . V_183 + V_6 -> V_54 . V_126 ;
if ( F_45 ( V_182 ) ) {
const unsigned int V_148 = V_149 - V_181 ;
V_96 -> V_123 =
F_26 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_181 += V_184 +
V_96 -> V_123 * V_132 ;
}
return V_181 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_185 ) &
( V_186 | V_187 | V_188 |
V_189 | V_190 ) )
F_55 ( V_2 , F_56 ( V_2 ) , 0 , 0 , V_191 ) ;
}
static void F_57 ( unsigned long V_192 )
{
struct V_193 * V_194 = (struct V_193 * ) V_192 ;
F_58 ( V_195 ) ;
unsigned long V_78 ;
struct V_196 * V_197 , * V_198 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
F_59 ( V_78 ) ;
F_60 ( & V_194 -> V_199 , & V_195 ) ;
F_61 ( V_78 ) ;
F_62 (q, n, &list) {
V_6 = F_63 ( V_197 , struct V_5 , V_200 ) ;
F_64 ( & V_6 -> V_200 ) ;
V_2 = (struct V_1 * ) V_6 ;
F_65 ( V_2 ) ;
if ( ! F_66 ( V_2 ) ) {
F_54 ( V_2 ) ;
} else {
F_67 ( V_201 , & V_6 -> V_202 ) ;
}
F_68 ( V_2 ) ;
F_69 ( V_203 , & V_6 -> V_202 ) ;
F_70 ( V_2 ) ;
}
}
void F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_78 , V_204 ;
do {
V_78 = V_6 -> V_202 ;
if ( ! ( V_78 & V_205 ) )
return;
V_204 = V_78 & ~ V_205 ;
} while ( F_72 ( & V_6 -> V_202 , V_78 , V_204 ) != V_78 );
if ( V_78 & ( 1UL << V_201 ) )
F_54 ( V_2 ) ;
if ( V_78 & ( 1UL << V_206 ) ) {
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
}
if ( V_78 & ( 1UL << V_207 ) ) {
F_75 ( V_2 ) ;
F_74 ( V_2 ) ;
}
if ( V_78 & ( 1UL << V_208 ) ) {
V_2 -> V_209 -> V_210 ( V_2 ) ;
F_74 ( V_2 ) ;
}
}
void T_10 F_76 ( void )
{
int V_211 ;
F_77 (i) {
struct V_193 * V_194 = & F_78 ( V_193 , V_211 ) ;
F_79 ( & V_194 -> V_199 ) ;
F_80 ( & V_194 -> V_212 ,
F_57 ,
( unsigned long ) V_194 ) ;
}
}
static void F_81 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_82 ( V_213 , & V_6 -> V_202 ) &&
! F_83 ( V_203 , & V_6 -> V_202 ) ) {
unsigned long V_78 ;
struct V_193 * V_194 ;
F_84 ( V_4 -> V_214 - 1 , & V_2 -> V_215 ) ;
F_59 ( V_78 ) ;
V_194 = & F_85 ( V_193 ) ;
F_86 ( & V_6 -> V_200 , & V_194 -> V_199 ) ;
F_87 ( & V_194 -> V_212 ) ;
F_61 ( V_78 ) ;
} else {
F_88 ( V_4 ) ;
}
}
static int F_89 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_216 ,
T_11 V_217 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_218 * V_219 ;
struct V_5 * V_6 ;
struct V_179 * V_180 ;
struct V_95 V_96 ;
unsigned int V_220 , V_221 ;
struct V_143 * V_144 ;
struct V_66 * V_67 ;
int V_222 ;
F_90 ( ! V_4 || ! F_5 ( V_4 ) ) ;
if ( V_30 -> V_223 -> V_78 & V_224 )
F_91 ( V_4 ) ;
if ( F_47 ( V_216 ) ) {
if ( F_45 ( F_92 ( V_4 ) ) )
V_4 = F_93 ( V_4 , V_217 ) ;
else
V_4 = F_94 ( V_4 , V_217 ) ;
if ( F_45 ( ! V_4 ) )
return - V_225 ;
}
V_219 = F_95 ( V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_180 = F_4 ( V_4 ) ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
if ( F_45 ( V_180 -> V_58 & V_85 ) )
V_220 = F_48 ( V_2 , V_4 , & V_96 , & V_144 ) ;
else
V_220 = F_53 ( V_2 , V_4 , & V_96 ,
& V_144 ) ;
V_221 = V_220 + sizeof( struct V_66 ) ;
if ( F_96 ( V_6 ) == 0 ) {
F_15 ( V_2 , V_226 ) ;
V_4 -> V_227 = 1 ;
} else
V_4 -> V_227 = 0 ;
F_97 ( V_4 , V_221 ) ;
F_98 ( V_4 ) ;
F_99 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_228 = ( V_229 > 0 ) ?
F_81 : F_88 ;
F_100 ( V_4 -> V_214 , & V_2 -> V_215 ) ;
V_67 = F_37 ( V_4 ) ;
V_67 -> V_230 = V_219 -> V_231 ;
V_67 -> V_232 = V_219 -> V_233 ;
V_67 -> V_72 = F_46 ( V_180 -> V_72 ) ;
V_67 -> V_234 = F_46 ( V_6 -> V_56 ) ;
* ( ( ( V_235 * ) V_67 ) + 6 ) = F_101 ( ( ( V_221 >> 2 ) << 12 ) |
V_180 -> V_58 ) ;
if ( F_45 ( V_180 -> V_58 & V_85 ) ) {
V_67 -> V_236 = F_101 ( F_17 ( V_6 -> V_40 , 65535U ) ) ;
} else {
V_67 -> V_236 = F_101 ( F_27 ( V_2 ) ) ;
}
V_67 -> V_237 = 0 ;
V_67 -> V_238 = 0 ;
if ( F_45 ( F_41 ( V_6 ) && F_8 ( V_180 -> V_72 , V_6 -> V_88 ) ) ) {
if ( F_8 ( V_6 -> V_88 , V_180 -> V_72 + 0x10000 ) ) {
V_67 -> V_238 = F_101 ( V_6 -> V_88 - V_180 -> V_72 ) ;
V_67 -> V_239 = 1 ;
} else if ( F_102 ( V_180 -> V_72 + 0xFFFF , V_6 -> V_9 ) ) {
V_67 -> V_238 = F_101 ( 0xFFFF ) ;
V_67 -> V_239 = 1 ;
}
}
F_44 ( ( T_9 * ) ( V_67 + 1 ) , V_6 , & V_96 ) ;
if ( F_47 ( ( V_180 -> V_58 & V_85 ) == 0 ) )
F_35 ( V_2 , V_4 , V_221 ) ;
#ifdef F_49
if ( V_144 ) {
F_103 ( V_2 , V_240 ) ;
V_6 -> V_155 -> V_241 ( V_96 . V_105 ,
V_144 , V_2 , NULL , V_4 ) ;
}
#endif
V_30 -> V_242 -> V_243 ( V_2 , V_4 ) ;
if ( F_47 ( V_180 -> V_58 & V_244 ) )
F_21 ( V_2 , F_5 ( V_4 ) ) ;
if ( V_4 -> V_71 != V_221 )
F_20 ( V_6 , V_2 ) ;
if ( F_102 ( V_180 -> V_10 , V_6 -> V_9 ) || V_180 -> V_72 == V_180 -> V_10 )
F_104 ( F_105 ( V_2 ) , V_245 ,
F_5 ( V_4 ) ) ;
V_222 = V_30 -> V_242 -> V_246 ( V_4 , & V_219 -> V_247 . V_248 ) ;
if ( F_47 ( V_222 <= 0 ) )
return V_222 ;
F_106 ( V_2 , 1 ) ;
return F_107 ( V_222 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_249 = F_4 ( V_4 ) -> V_10 ;
F_109 ( V_4 ) ;
F_110 ( V_2 , V_4 ) ;
V_2 -> V_250 += V_4 -> V_214 ;
F_111 ( V_2 , V_4 -> V_214 ) ;
}
static void F_112 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_251 )
{
if ( V_4 -> V_71 <= V_251 || ! F_113 ( V_2 ) ||
V_4 -> V_79 == V_252 ) {
F_38 ( V_4 ) -> V_83 = 1 ;
F_38 ( V_4 ) -> V_84 = 0 ;
F_38 ( V_4 ) -> V_75 = 0 ;
} else {
F_38 ( V_4 ) -> V_83 = F_114 ( V_4 -> V_71 , V_251 ) ;
F_38 ( V_4 ) -> V_84 = V_251 ;
F_38 ( V_4 ) -> V_75 = V_2 -> V_253 ;
}
}
static void F_115 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_254 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_255 || F_116 ( V_6 ) )
return;
if ( F_102 ( F_117 ( V_6 ) , F_4 ( V_4 ) -> V_72 ) )
V_6 -> V_256 -= V_254 ;
}
static void F_118 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_254 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 -= V_254 ;
if ( F_4 ( V_4 ) -> V_82 & V_257 )
V_6 -> V_255 -= V_254 ;
if ( F_4 ( V_4 ) -> V_82 & V_258 )
V_6 -> V_259 -= V_254 ;
if ( F_4 ( V_4 ) -> V_82 & V_260 )
V_6 -> V_261 -= V_254 ;
if ( F_116 ( V_6 ) && V_254 > 0 )
V_6 -> V_255 -= F_26 ( T_4 , V_6 -> V_255 , V_254 ) ;
F_115 ( V_2 , V_4 , V_254 ) ;
if ( V_6 -> V_262 &&
F_8 ( F_4 ( V_4 ) -> V_72 , F_4 ( V_6 -> V_262 ) -> V_72 ) &&
( F_119 ( V_6 ) || ( F_4 ( V_4 ) -> V_82 & V_257 ) ) )
V_6 -> V_263 -= V_254 ;
F_120 ( V_6 ) ;
}
int F_121 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_71 ,
unsigned int V_251 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_264 ;
int V_265 , V_266 ;
int V_267 ;
T_8 V_78 ;
if ( F_122 ( V_71 > V_4 -> V_71 ) )
return - V_268 ;
V_265 = F_123 ( V_4 ) - V_71 ;
if ( V_265 < 0 )
V_265 = 0 ;
if ( F_92 ( V_4 ) &&
F_124 ( V_4 ) &&
F_125 ( V_4 , 0 , 0 , V_191 ) )
return - V_269 ;
V_264 = F_126 ( V_2 , V_265 , V_191 ) ;
if ( V_264 == NULL )
return - V_269 ;
V_2 -> V_250 += V_264 -> V_214 ;
F_111 ( V_2 , V_264 -> V_214 ) ;
V_267 = V_4 -> V_71 - V_71 - V_265 ;
V_264 -> V_214 += V_267 ;
V_4 -> V_214 -= V_267 ;
F_4 ( V_264 ) -> V_72 = F_4 ( V_4 ) -> V_72 + V_71 ;
F_4 ( V_264 ) -> V_10 = F_4 ( V_4 ) -> V_10 ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_264 ) -> V_72 ;
V_78 = F_4 ( V_4 ) -> V_58 ;
F_4 ( V_4 ) -> V_58 = V_78 & ~ ( V_86 | V_270 ) ;
F_4 ( V_264 ) -> V_58 = V_78 ;
F_4 ( V_264 ) -> V_82 = F_4 ( V_4 ) -> V_82 ;
if ( ! F_38 ( V_4 ) -> V_271 && V_4 -> V_79 != V_80 ) {
V_264 -> V_81 = F_127 ( V_4 -> V_192 + V_71 ,
F_128 ( V_264 , V_265 ) ,
V_265 , 0 ) ;
F_129 ( V_4 , V_71 ) ;
V_4 -> V_81 = F_130 ( V_4 -> V_81 , V_264 -> V_81 , V_71 ) ;
} else {
V_4 -> V_79 = V_80 ;
F_131 ( V_4 , V_264 , V_71 ) ;
}
V_264 -> V_79 = V_4 -> V_79 ;
F_4 ( V_264 ) -> V_160 = F_4 ( V_4 ) -> V_160 ;
V_264 -> V_272 = V_4 -> V_272 ;
V_266 = F_5 ( V_4 ) ;
F_112 ( V_2 , V_4 , V_251 ) ;
F_112 ( V_2 , V_264 , V_251 ) ;
if ( ! F_8 ( V_6 -> V_9 , F_4 ( V_264 ) -> V_10 ) ) {
int V_273 = V_266 - F_5 ( V_4 ) -
F_5 ( V_264 ) ;
if ( V_273 )
F_118 ( V_2 , V_4 , V_273 ) ;
}
F_109 ( V_264 ) ;
F_132 ( V_4 , V_264 , V_2 ) ;
return 0 ;
}
static void F_133 ( struct V_3 * V_4 , int V_71 )
{
int V_211 , V_274 , V_275 ;
V_275 = F_26 ( int , V_71 , F_123 ( V_4 ) ) ;
if ( V_275 ) {
F_134 ( V_4 , V_275 ) ;
V_4 -> V_276 -= V_275 ;
V_71 -= V_275 ;
if ( ! V_71 )
return;
}
V_275 = V_71 ;
V_274 = 0 ;
for ( V_211 = 0 ; V_211 < F_38 ( V_4 ) -> V_271 ; V_211 ++ ) {
int V_181 = F_135 ( & F_38 ( V_4 ) -> V_277 [ V_211 ] ) ;
if ( V_181 <= V_275 ) {
F_136 ( V_4 , V_211 ) ;
V_275 -= V_181 ;
} else {
F_38 ( V_4 ) -> V_277 [ V_274 ] = F_38 ( V_4 ) -> V_277 [ V_211 ] ;
if ( V_275 ) {
F_38 ( V_4 ) -> V_277 [ V_274 ] . V_278 += V_275 ;
F_137 ( & F_38 ( V_4 ) -> V_277 [ V_274 ] , V_275 ) ;
V_275 = 0 ;
}
V_274 ++ ;
}
}
F_38 ( V_4 ) -> V_271 = V_274 ;
F_138 ( V_4 ) ;
V_4 -> V_279 -= V_71 ;
V_4 -> V_71 = V_4 -> V_279 ;
}
int F_139 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_71 )
{
if ( F_92 ( V_4 ) && F_125 ( V_4 , 0 , 0 , V_191 ) )
return - V_269 ;
F_133 ( V_4 , V_71 ) ;
F_4 ( V_4 ) -> V_72 += V_71 ;
V_4 -> V_79 = V_80 ;
V_4 -> V_214 -= V_71 ;
V_2 -> V_250 -= V_71 ;
F_140 ( V_2 , V_71 ) ;
F_141 ( V_2 , V_280 ) ;
if ( F_5 ( V_4 ) > 1 )
F_112 ( V_2 , V_4 , F_142 ( V_4 ) ) ;
return 0 ;
}
int F_143 ( struct V_1 * V_2 , int V_281 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_251 ;
V_251 = V_281 - V_30 -> V_242 -> V_282 - sizeof( struct V_66 ) ;
if ( V_30 -> V_242 -> V_283 ) {
const struct V_13 * V_14 = F_11 ( V_2 ) ;
if ( V_14 && F_144 ( V_14 ) )
V_251 -= V_30 -> V_242 -> V_283 ;
}
if ( V_251 > V_6 -> V_54 . V_284 )
V_251 = V_6 -> V_54 . V_284 ;
V_251 -= V_30 -> V_285 ;
if ( V_251 < 48 )
V_251 = 48 ;
V_251 -= V_6 -> V_70 - sizeof( struct V_66 ) ;
return V_251 ;
}
int F_145 ( struct V_1 * V_2 , int V_15 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_286 ;
V_286 = V_15 +
V_6 -> V_70 +
V_30 -> V_285 +
V_30 -> V_242 -> V_282 ;
if ( V_30 -> V_242 -> V_283 ) {
const struct V_13 * V_14 = F_11 ( V_2 ) ;
if ( V_14 && F_144 ( V_14 ) )
V_286 += V_30 -> V_242 -> V_283 ;
}
return V_286 ;
}
void F_146 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
V_30 -> V_287 . V_288 = V_289 > 1 ;
V_30 -> V_287 . V_290 = V_6 -> V_54 . V_284 + sizeof( struct V_66 ) +
V_30 -> V_242 -> V_282 ;
V_30 -> V_287 . V_291 = F_145 ( V_2 , V_292 ) ;
V_30 -> V_287 . V_293 = 0 ;
}
unsigned int F_147 ( struct V_1 * V_2 , T_4 V_281 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_251 ;
if ( V_30 -> V_287 . V_290 > V_281 )
V_30 -> V_287 . V_290 = V_281 ;
V_251 = F_143 ( V_2 , V_281 ) ;
V_251 = F_148 ( V_6 , V_251 ) ;
V_30 -> V_294 = V_281 ;
if ( V_30 -> V_287 . V_288 )
V_251 = F_17 ( V_251 , F_143 ( V_2 , V_30 -> V_287 . V_291 ) ) ;
V_6 -> V_295 = V_251 ;
return V_251 ;
}
unsigned int F_56 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = F_11 ( V_2 ) ;
T_4 V_251 ;
unsigned int V_296 ;
struct V_95 V_96 ;
struct V_143 * V_144 ;
V_251 = V_6 -> V_295 ;
if ( V_14 ) {
T_4 V_286 = F_149 ( V_14 ) ;
if ( V_286 != F_18 ( V_2 ) -> V_294 )
V_251 = F_147 ( V_2 , V_286 ) ;
}
V_296 = F_53 ( V_2 , NULL , & V_96 , & V_144 ) +
sizeof( struct V_66 ) ;
if ( V_296 != V_6 -> V_70 ) {
int V_18 = ( int ) V_296 - V_6 -> V_70 ;
V_251 -= V_18 ;
}
return V_251 ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 >= V_6 -> V_23 ) {
V_6 -> V_28 = 0 ;
V_6 -> V_27 = V_19 ;
} else {
if ( V_6 -> V_8 > V_6 -> V_28 )
V_6 -> V_28 = V_6 -> V_8 ;
if ( V_32 &&
( T_3 ) ( V_19 - V_6 -> V_27 ) >= F_18 ( V_2 ) -> V_26 )
F_151 ( V_2 ) ;
}
}
static unsigned int F_152 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_251 , unsigned int V_297 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_298 , V_236 , V_299 ;
V_236 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_72 ;
V_299 = V_251 * V_297 ;
if ( F_47 ( V_299 <= V_236 && V_4 != F_153 ( V_2 ) ) )
return V_299 ;
V_298 = F_17 ( V_4 -> V_71 , V_236 ) ;
if ( V_299 <= V_298 )
return V_299 ;
return V_298 - V_298 % V_251 ;
}
static inline unsigned int F_154 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_4 V_300 , V_22 ;
if ( ( F_4 ( V_4 ) -> V_58 & V_86 ) &&
F_5 ( V_4 ) == 1 )
return 1 ;
V_300 = F_96 ( V_6 ) ;
V_22 = V_6 -> V_23 ;
if ( V_300 < V_22 )
return ( V_22 - V_300 ) ;
return 0 ;
}
static int F_155 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_251 )
{
int V_301 = F_5 ( V_4 ) ;
if ( ! V_301 || ( V_301 > 1 && F_142 ( V_4 ) != V_251 ) ) {
F_112 ( V_2 , V_4 , V_251 ) ;
V_301 = F_5 ( V_4 ) ;
}
return V_301 ;
}
static inline bool F_156 ( const struct V_5 * V_6 )
{
return F_102 ( V_6 -> V_302 , V_6 -> V_87 ) &&
! F_102 ( V_6 -> V_302 , V_6 -> V_9 ) ;
}
static inline bool F_157 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
unsigned int V_251 , int V_303 )
{
return V_4 -> V_71 < V_251 &&
( ( V_303 & V_304 ) ||
( ! V_303 && V_6 -> V_8 && F_156 ( V_6 ) ) ) ;
}
static inline bool F_158 ( const struct V_5 * V_6 , const struct V_3 * V_4 ,
unsigned int V_305 , int V_303 )
{
if ( V_303 & V_306 )
return true ;
if ( F_41 ( V_6 ) || ( V_6 -> V_11 == 2 ) ||
( F_4 ( V_4 ) -> V_58 & V_86 ) )
return true ;
if ( ! F_157 ( V_6 , V_4 , V_305 , V_303 ) )
return true ;
return false ;
}
static bool F_159 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
unsigned int V_305 )
{
T_4 V_10 = F_4 ( V_4 ) -> V_10 ;
if ( V_4 -> V_71 > V_305 )
V_10 = F_4 ( V_4 ) -> V_72 + V_305 ;
return ! F_102 ( V_10 , F_9 ( V_6 ) ) ;
}
static unsigned int F_160 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_305 , int V_303 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_307 ;
F_155 ( V_2 , V_4 , V_305 ) ;
if ( ! F_158 ( V_6 , V_4 , V_305 , V_303 ) )
return 0 ;
V_307 = F_154 ( V_6 , V_4 ) ;
if ( V_307 && ! F_159 ( V_6 , V_4 , V_305 ) )
V_307 = 0 ;
return V_307 ;
}
bool F_161 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_162 ( V_2 ) ;
return V_4 &&
F_160 ( V_2 , V_4 , F_56 ( V_2 ) ,
( F_163 ( V_2 , V_4 ) ?
V_6 -> V_303 : V_306 ) ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_71 ,
unsigned int V_251 , T_11 V_308 )
{
struct V_3 * V_264 ;
int V_267 = V_4 -> V_71 - V_71 ;
T_8 V_78 ;
if ( V_4 -> V_71 != V_4 -> V_279 )
return F_121 ( V_2 , V_4 , V_71 , V_251 ) ;
V_264 = F_126 ( V_2 , 0 , V_308 ) ;
if ( F_45 ( V_264 == NULL ) )
return - V_269 ;
V_2 -> V_250 += V_264 -> V_214 ;
F_111 ( V_2 , V_264 -> V_214 ) ;
V_264 -> V_214 += V_267 ;
V_4 -> V_214 -= V_267 ;
F_4 ( V_264 ) -> V_72 = F_4 ( V_4 ) -> V_72 + V_71 ;
F_4 ( V_264 ) -> V_10 = F_4 ( V_4 ) -> V_10 ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_264 ) -> V_72 ;
V_78 = F_4 ( V_4 ) -> V_58 ;
F_4 ( V_4 ) -> V_58 = V_78 & ~ ( V_86 | V_270 ) ;
F_4 ( V_264 ) -> V_58 = V_78 ;
F_4 ( V_264 ) -> V_82 = 0 ;
V_264 -> V_79 = V_4 -> V_79 = V_80 ;
F_131 ( V_4 , V_264 , V_71 ) ;
F_112 ( V_2 , V_4 , V_251 ) ;
F_112 ( V_2 , V_264 , V_251 ) ;
F_109 ( V_264 ) ;
F_132 ( V_4 , V_264 , V_2 ) ;
return 0 ;
}
static bool F_165 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
T_4 V_309 , V_310 , V_311 , V_300 ;
int V_312 ;
if ( F_4 ( V_4 ) -> V_58 & V_86 )
goto V_313;
if ( V_30 -> V_314 != V_315 )
goto V_313;
if ( V_6 -> V_316 &&
( ( ( T_4 ) V_317 << 1 ) >> 1 ) - ( V_6 -> V_316 >> 1 ) > 1 )
goto V_313;
V_300 = F_96 ( V_6 ) ;
F_90 ( F_5 ( V_4 ) <= 1 || ( V_6 -> V_23 <= V_300 ) ) ;
V_309 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_72 ;
V_310 = ( V_6 -> V_23 - V_300 ) * V_6 -> V_295 ;
V_311 = F_17 ( V_309 , V_310 ) ;
if ( V_311 >= F_26 (unsigned int, sk->sk_gso_max_size,
sk->sk_gso_max_segs * tp->mss_cache) )
goto V_313;
if ( ( V_4 != F_153 ( V_2 ) ) && ( V_311 >= V_4 -> V_71 ) )
goto V_313;
V_312 = F_43 ( V_318 ) ;
if ( V_312 ) {
T_4 V_319 = F_17 ( V_6 -> V_320 , V_6 -> V_23 * V_6 -> V_295 ) ;
V_319 /= V_312 ;
if ( V_311 >= V_319 )
goto V_313;
} else {
if ( V_311 > F_166 ( V_6 ) * V_6 -> V_295 )
goto V_313;
}
V_6 -> V_316 = 1 | ( V_317 << 1 ) ;
return true ;
V_313:
V_6 -> V_316 = 0 ;
return false ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_3 * V_4 , * V_321 , * V_322 ;
int V_71 ;
int V_293 ;
int V_323 ;
int V_324 ;
int V_251 ;
if ( ! V_30 -> V_287 . V_288 ||
V_30 -> V_287 . V_293 ||
F_18 ( V_2 ) -> V_314 != V_315 ||
V_6 -> V_23 < 11 ||
V_6 -> V_54 . V_183 || V_6 -> V_54 . V_126 )
return - 1 ;
V_251 = F_56 ( V_2 ) ;
V_293 = 2 * V_6 -> V_295 ;
V_323 = V_293 + ( V_6 -> V_325 + 1 ) * V_6 -> V_295 ;
if ( V_293 > F_143 ( V_2 , V_30 -> V_287 . V_290 ) ) {
return - 1 ;
}
if ( V_6 -> V_249 - V_6 -> V_9 < V_323 )
return - 1 ;
if ( V_6 -> V_320 < V_323 )
return - 1 ;
if ( F_102 ( V_6 -> V_9 + V_323 , F_9 ( V_6 ) ) )
return 0 ;
if ( F_96 ( V_6 ) + 2 > V_6 -> V_23 ) {
if ( ! F_96 ( V_6 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_321 = F_126 ( V_2 , V_293 , V_191 ) ) == NULL )
return - 1 ;
V_2 -> V_250 += V_321 -> V_214 ;
F_111 ( V_2 , V_321 -> V_214 ) ;
V_4 = F_162 ( V_2 ) ;
F_4 ( V_321 ) -> V_72 = F_4 ( V_4 ) -> V_72 ;
F_4 ( V_321 ) -> V_10 = F_4 ( V_4 ) -> V_72 + V_293 ;
F_4 ( V_321 ) -> V_58 = V_244 ;
F_4 ( V_321 ) -> V_82 = 0 ;
V_321 -> V_81 = 0 ;
V_321 -> V_79 = V_4 -> V_79 ;
F_168 ( V_321 , V_4 , V_2 ) ;
V_71 = 0 ;
F_169 (skb, next, sk) {
V_324 = F_26 ( int , V_4 -> V_71 , V_293 - V_71 ) ;
if ( V_321 -> V_79 )
F_170 ( V_4 , 0 , F_128 ( V_321 , V_324 ) , V_324 ) ;
else
V_321 -> V_81 = F_171 ( V_4 , 0 ,
F_128 ( V_321 , V_324 ) ,
V_324 , V_321 -> V_81 ) ;
if ( V_4 -> V_71 <= V_324 ) {
F_4 ( V_321 ) -> V_58 |= F_4 ( V_4 ) -> V_58 ;
F_172 ( V_4 , V_2 ) ;
F_173 ( V_2 , V_4 ) ;
} else {
F_4 ( V_321 ) -> V_58 |= F_4 ( V_4 ) -> V_58 &
~ ( V_86 | V_270 ) ;
if ( ! F_38 ( V_4 ) -> V_271 ) {
F_174 ( V_4 , V_324 ) ;
if ( V_4 -> V_79 != V_80 )
V_4 -> V_81 = F_175 ( V_4 -> V_192 ,
V_4 -> V_71 , 0 ) ;
} else {
F_133 ( V_4 , V_324 ) ;
F_112 ( V_2 , V_4 , V_251 ) ;
}
F_4 ( V_4 ) -> V_72 += V_324 ;
}
V_71 += V_324 ;
if ( V_71 >= V_293 )
break;
}
F_155 ( V_2 , V_321 , V_321 -> V_71 ) ;
F_4 ( V_321 ) -> V_160 = V_19 ;
if ( ! F_89 ( V_2 , V_321 , 1 , V_191 ) ) {
V_6 -> V_23 -- ;
F_1 ( V_2 , V_321 ) ;
V_30 -> V_287 . V_293 = F_145 ( V_2 , V_321 -> V_71 ) ;
V_6 -> V_326 . V_327 = F_4 ( V_321 ) -> V_72 ;
V_6 -> V_326 . V_328 = F_4 ( V_321 ) -> V_10 ;
return 1 ;
}
return - 1 ;
}
static bool F_55 ( struct V_1 * V_2 , unsigned int V_251 , int V_303 ,
int V_329 , T_11 V_308 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_301 , V_330 ;
int V_307 ;
int V_331 ;
V_330 = 0 ;
if ( ! V_329 ) {
V_331 = F_167 ( V_2 ) ;
if ( ! V_331 ) {
return false ;
} else if ( V_331 > 0 ) {
V_330 = 1 ;
}
}
while ( ( V_4 = F_162 ( V_2 ) ) ) {
unsigned int V_311 ;
V_301 = F_155 ( V_2 , V_4 , V_251 ) ;
F_90 ( ! V_301 ) ;
V_307 = F_154 ( V_6 , V_4 ) ;
if ( ! V_307 )
break;
if ( F_45 ( ! F_159 ( V_6 , V_4 , V_251 ) ) )
break;
if ( V_301 == 1 ) {
if ( F_45 ( ! F_158 ( V_6 , V_4 , V_251 ,
( F_163 ( V_2 , V_4 ) ?
V_303 : V_306 ) ) ) )
break;
} else {
if ( ! V_329 && F_165 ( V_2 , V_4 ) )
break;
}
if ( F_176 ( & V_2 -> V_215 ) >= V_229 ) {
F_67 ( V_213 , & V_6 -> V_202 ) ;
break;
}
V_311 = V_251 ;
if ( V_301 > 1 && ! F_41 ( V_6 ) )
V_311 = F_152 ( V_2 , V_4 , V_251 ,
F_26 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ) ;
if ( V_4 -> V_71 > V_311 &&
F_45 ( F_164 ( V_2 , V_4 , V_311 , V_251 , V_308 ) ) )
break;
F_4 ( V_4 ) -> V_160 = V_19 ;
if ( F_45 ( F_89 ( V_2 , V_4 , 1 , V_308 ) ) )
break;
F_1 ( V_2 , V_4 ) ;
F_177 ( V_6 , V_251 , V_4 ) ;
V_330 += F_5 ( V_4 ) ;
if ( V_329 )
break;
}
if ( F_18 ( V_2 ) -> V_314 == V_332 )
V_6 -> V_333 += V_330 ;
if ( F_47 ( V_330 ) ) {
F_150 ( V_2 ) ;
return false ;
}
return ! V_6 -> V_8 && F_162 ( V_2 ) ;
}
void F_178 ( struct V_1 * V_2 , unsigned int V_305 ,
int V_303 )
{
if ( F_45 ( V_2 -> V_185 == V_334 ) )
return;
if ( F_55 ( V_2 , V_305 , V_303 , 0 ,
F_179 ( V_2 , V_191 ) ) )
F_180 ( V_2 ) ;
}
void F_181 ( struct V_1 * V_2 , unsigned int V_251 )
{
struct V_3 * V_4 = F_162 ( V_2 ) ;
F_90 ( ! V_4 || V_4 -> V_71 < V_251 ) ;
F_55 ( V_2 , V_251 , V_306 , 1 , V_2 -> V_335 ) ;
}
T_4 F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 = V_30 -> V_33 . V_336 ;
int V_337 = F_182 ( V_2 ) ;
int V_338 = F_26 ( int , V_6 -> V_41 , F_183 ( V_2 ) ) ;
int V_236 ;
if ( V_15 > V_338 )
V_15 = V_338 ;
if ( V_337 < ( V_338 >> 1 ) ) {
V_30 -> V_33 . V_339 = 0 ;
if ( F_184 ( V_2 ) )
V_6 -> V_340 = F_17 ( V_6 -> V_340 ,
4U * V_6 -> V_16 ) ;
if ( V_337 < V_15 )
return 0 ;
}
if ( V_337 > V_6 -> V_340 )
V_337 = V_6 -> V_340 ;
V_236 = V_6 -> V_40 ;
if ( V_6 -> V_54 . V_43 ) {
V_236 = V_337 ;
if ( ( ( V_236 >> V_6 -> V_54 . V_43 ) << V_6 -> V_54 . V_43 ) != V_236 )
V_236 = ( ( ( V_236 >> V_6 -> V_54 . V_43 ) + 1 )
<< V_6 -> V_54 . V_43 ) ;
} else {
if ( V_236 <= V_337 - V_15 || V_236 > V_337 )
V_236 = ( V_337 / V_15 ) * V_15 ;
else if ( V_15 == V_338 &&
V_337 > V_236 + ( V_338 >> 1 ) )
V_236 = V_337 ;
}
return V_236 ;
}
static void F_185 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_341 = F_186 ( V_2 , V_4 ) ;
int V_342 , V_343 ;
V_342 = V_4 -> V_71 ;
V_343 = V_341 -> V_71 ;
F_90 ( F_5 ( V_4 ) != 1 || F_5 ( V_341 ) != 1 ) ;
F_187 ( V_2 , V_341 , V_4 ) ;
F_172 ( V_341 , V_2 ) ;
F_188 ( V_341 , F_128 ( V_4 , V_343 ) ,
V_343 ) ;
if ( V_341 -> V_79 == V_80 )
V_4 -> V_79 = V_80 ;
if ( V_4 -> V_79 != V_80 )
V_4 -> V_81 = F_189 ( V_4 -> V_81 , V_341 -> V_81 , V_342 ) ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_341 ) -> V_10 ;
F_4 ( V_4 ) -> V_58 |= F_4 ( V_341 ) -> V_58 ;
F_4 ( V_4 ) -> V_82 |= F_4 ( V_341 ) -> V_82 & V_344 ;
F_190 ( V_6 ) ;
if ( V_341 == V_6 -> V_345 )
V_6 -> V_345 = V_4 ;
F_118 ( V_2 , V_341 , F_5 ( V_341 ) ) ;
F_173 ( V_2 , V_341 ) ;
}
static bool F_191 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_5 ( V_4 ) > 1 )
return false ;
if ( F_38 ( V_4 ) -> V_271 != 0 )
return false ;
if ( F_92 ( V_4 ) )
return false ;
if ( V_4 == F_162 ( V_2 ) )
return false ;
if ( F_4 ( V_4 ) -> V_82 & V_257 )
return false ;
return true ;
}
static void F_192 ( struct V_1 * V_2 , struct V_3 * V_346 ,
int V_45 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_346 , * V_347 ;
bool V_348 = true ;
if ( ! V_349 )
return;
if ( F_4 ( V_4 ) -> V_58 & V_85 )
return;
F_169 (skb, tmp, sk) {
if ( ! F_191 ( V_2 , V_4 ) )
break;
V_45 -= V_4 -> V_71 ;
if ( V_348 ) {
V_348 = false ;
continue;
}
if ( V_45 < 0 )
break;
if ( V_4 -> V_71 > F_193 ( V_346 ) )
break;
if ( F_102 ( F_4 ( V_4 ) -> V_10 , F_9 ( V_6 ) ) )
break;
F_185 ( V_2 , V_346 ) ;
}
}
int F_194 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
unsigned int V_305 ;
int V_222 ;
if ( V_30 -> V_287 . V_293 ) {
V_30 -> V_287 . V_293 = 0 ;
}
if ( F_176 ( & V_2 -> V_215 ) >
F_17 ( V_2 -> V_250 + ( V_2 -> V_250 >> 2 ) , V_2 -> V_350 ) )
return - V_351 ;
if ( F_8 ( F_4 ( V_4 ) -> V_72 , V_6 -> V_87 ) ) {
if ( F_8 ( F_4 ( V_4 ) -> V_10 , V_6 -> V_87 ) )
F_195 () ;
if ( F_139 ( V_2 , V_4 , V_6 -> V_87 - F_4 ( V_4 ) -> V_72 ) )
return - V_269 ;
}
if ( F_18 ( V_2 ) -> V_242 -> V_352 ( V_2 ) )
return - V_353 ;
V_305 = F_56 ( V_2 ) ;
if ( ! F_8 ( F_4 ( V_4 ) -> V_72 , F_9 ( V_6 ) ) &&
F_4 ( V_4 ) -> V_72 != V_6 -> V_87 )
return - V_351 ;
if ( V_4 -> V_71 > V_305 ) {
if ( F_121 ( V_2 , V_4 , V_305 , V_305 ) )
return - V_269 ;
} else {
int V_354 = F_5 ( V_4 ) ;
if ( F_45 ( V_354 > 1 ) ) {
F_155 ( V_2 , V_4 , V_305 ) ;
F_118 ( V_2 , V_4 , V_354 - F_5 ( V_4 ) ) ;
}
}
F_192 ( V_2 , V_4 , V_305 ) ;
if ( V_4 -> V_71 > 0 &&
( F_4 ( V_4 ) -> V_58 & V_86 ) &&
V_6 -> V_87 == ( F_4 ( V_4 ) -> V_10 - 1 ) ) {
if ( ! F_196 ( V_4 , 0 ) ) {
F_40 ( V_4 , F_4 ( V_4 ) -> V_10 - 1 ,
F_4 ( V_4 ) -> V_58 ) ;
V_4 -> V_79 = V_252 ;
}
}
F_4 ( V_4 ) -> V_160 = V_19 ;
if ( F_45 ( V_355 && ( ( unsigned long ) V_4 -> V_192 & 3 ) ) ) {
struct V_3 * V_321 = F_197 ( V_4 , V_356 ,
V_191 ) ;
V_222 = V_321 ? F_89 ( V_2 , V_321 , 0 , V_191 ) :
- V_225 ;
} else {
V_222 = F_89 ( V_2 , V_4 , 1 , V_191 ) ;
}
if ( V_222 == 0 ) {
F_198 ( F_105 ( V_2 ) , V_357 ) ;
V_6 -> V_358 ++ ;
#if V_359 > 0
if ( F_4 ( V_4 ) -> V_82 & V_258 ) {
F_199 ( L_1 ) ;
}
#endif
if ( ! V_6 -> V_259 )
V_6 -> V_360 = V_6 -> V_9 ;
F_4 ( V_4 ) -> V_82 |= V_361 ;
V_6 -> V_259 += F_5 ( V_4 ) ;
if ( ! V_6 -> V_362 )
V_6 -> V_362 = F_4 ( V_4 ) -> V_160 ;
V_6 -> V_363 += F_5 ( V_4 ) ;
F_4 ( V_4 ) -> V_234 = V_6 -> V_9 ;
}
return V_222 ;
}
static bool F_200 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_314 != V_332 )
return false ;
if ( F_116 ( V_6 ) )
return false ;
if ( F_161 ( V_2 ) )
return false ;
return true ;
}
void F_201 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_364 = NULL ;
T_4 V_365 ;
int V_366 ;
int V_367 = 0 ;
if ( ! V_6 -> V_8 )
return;
if ( ! V_6 -> V_261 )
V_6 -> V_368 = V_6 -> V_87 ;
if ( V_6 -> V_345 ) {
V_4 = V_6 -> V_345 ;
V_365 = F_4 ( V_4 ) -> V_10 ;
if ( F_102 ( V_365 , V_6 -> V_368 ) )
V_365 = V_6 -> V_368 ;
} else {
V_4 = F_202 ( V_2 ) ;
V_365 = V_6 -> V_87 ;
}
F_203 (skb, sk) {
T_5 V_82 = F_4 ( V_4 ) -> V_82 ;
if ( V_4 == F_162 ( V_2 ) )
break;
if ( V_364 == NULL )
V_6 -> V_345 = V_4 ;
if ( F_96 ( V_6 ) >= V_6 -> V_23 )
return;
if ( V_367 ) {
V_369:
if ( ! F_8 ( F_4 ( V_4 ) -> V_72 , F_117 ( V_6 ) ) )
break;
V_366 = V_370 ;
} else if ( ! F_8 ( F_4 ( V_4 ) -> V_72 , V_6 -> V_368 ) ) {
V_6 -> V_368 = V_365 ;
if ( ! F_200 ( V_2 ) )
break;
if ( V_364 != NULL ) {
V_4 = V_364 ;
V_364 = NULL ;
}
V_367 = 1 ;
goto V_369;
} else if ( ! ( V_82 & V_260 ) ) {
if ( V_364 == NULL && ! ( V_82 & ( V_258 | V_257 ) ) )
V_364 = V_4 ;
continue;
} else {
V_365 = F_4 ( V_4 ) -> V_10 ;
if ( V_30 -> V_314 != V_371 )
V_366 = V_372 ;
else
V_366 = V_373 ;
}
if ( V_82 & ( V_257 | V_258 ) )
continue;
if ( F_194 ( V_2 , V_4 ) ) {
F_204 ( F_105 ( V_2 ) , V_374 ) ;
return;
}
F_204 ( F_105 ( V_2 ) , V_366 ) ;
if ( F_18 ( V_2 ) -> V_314 == V_332 )
V_6 -> V_333 += F_5 ( V_4 ) ;
if ( V_4 == F_202 ( V_2 ) )
F_205 ( V_2 , V_375 ,
F_18 ( V_2 ) -> V_26 ,
V_376 ) ;
}
}
void F_206 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_153 ( V_2 ) ;
int V_251 ;
V_251 = F_56 ( V_2 ) ;
if ( F_162 ( V_2 ) != NULL ) {
F_4 ( V_4 ) -> V_58 |= V_86 ;
F_4 ( V_4 ) -> V_10 ++ ;
V_6 -> V_249 ++ ;
} else {
for (; ; ) {
V_4 = F_207 ( V_356 ,
V_2 -> V_335 ) ;
if ( V_4 )
break;
F_208 () ;
}
F_209 ( V_4 , V_356 ) ;
F_40 ( V_4 , V_6 -> V_249 ,
V_244 | V_86 ) ;
F_108 ( V_2 , V_4 ) ;
}
F_178 ( V_2 , V_251 , V_377 ) ;
}
void F_210 ( struct V_1 * V_2 , T_11 V_378 )
{
struct V_3 * V_4 ;
V_4 = F_211 ( V_356 , V_378 ) ;
if ( ! V_4 ) {
F_212 ( F_105 ( V_2 ) , V_379 ) ;
return;
}
F_209 ( V_4 , V_356 ) ;
F_40 ( V_4 , F_7 ( V_2 ) ,
V_244 | V_380 ) ;
F_4 ( V_4 ) -> V_160 = V_19 ;
if ( F_89 ( V_2 , V_4 , 0 , V_378 ) )
F_212 ( F_105 ( V_2 ) , V_379 ) ;
F_198 ( F_105 ( V_2 ) , V_381 ) ;
}
int F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_202 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_4 ( V_4 ) -> V_58 & V_85 ) ) {
F_214 ( L_2 , V_382 ) ;
return - V_383 ;
}
if ( ! ( F_4 ( V_4 ) -> V_58 & V_244 ) ) {
if ( F_92 ( V_4 ) ) {
struct V_3 * V_321 = F_215 ( V_4 , V_191 ) ;
if ( V_321 == NULL )
return - V_269 ;
F_172 ( V_4 , V_2 ) ;
F_109 ( V_321 ) ;
F_216 ( V_2 , V_321 ) ;
F_173 ( V_2 , V_4 ) ;
V_2 -> V_250 += V_321 -> V_214 ;
F_111 ( V_2 , V_321 -> V_214 ) ;
V_4 = V_321 ;
}
F_4 ( V_4 ) -> V_58 |= V_244 ;
F_31 ( F_2 ( V_2 ) , V_4 ) ;
}
F_4 ( V_4 ) -> V_160 = V_19 ;
return F_89 ( V_2 , V_4 , 1 , V_191 ) ;
}
struct V_3 * F_217 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_64 * V_65 ,
struct V_384 * V_385 )
{
struct V_95 V_96 ;
struct V_172 * V_173 = F_218 ( V_385 ) ;
struct V_174 * V_175 = F_34 ( V_65 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_145 * V_146 = V_6 -> V_147 ;
struct V_66 * V_67 ;
struct V_3 * V_4 ;
struct V_143 * V_144 ;
int V_221 ;
int V_15 ;
int V_386 = 0 ;
if ( V_146 != NULL && V_146 -> V_387 && V_146 -> V_386 )
V_386 = V_146 -> V_386 ;
V_4 = F_211 ( V_356 + 15 + V_386 ,
F_179 ( V_2 , V_191 ) ) ;
if ( F_45 ( ! V_4 ) ) {
F_219 ( V_14 ) ;
return NULL ;
}
F_209 ( V_4 , V_356 ) ;
F_220 ( V_4 , V_14 ) ;
V_15 = F_12 ( V_14 ) ;
if ( V_6 -> V_54 . V_388 && V_6 -> V_54 . V_388 < V_15 )
V_15 = V_6 -> V_54 . V_388 ;
if ( V_65 -> V_40 == 0 ) {
T_5 V_43 ;
V_65 -> V_41 = V_6 -> V_41 ? : F_221 ( V_14 , V_389 ) ;
if ( V_2 -> V_390 & V_391 &&
( V_65 -> V_41 > F_183 ( V_2 ) || V_65 -> V_41 == 0 ) )
V_65 -> V_41 = F_183 ( V_2 ) ;
F_24 ( F_183 ( V_2 ) ,
V_15 - ( V_175 -> V_177 ? V_162 : 0 ) ,
& V_65 -> V_40 ,
& V_65 -> V_41 ,
V_175 -> V_42 ,
& V_43 ,
F_221 ( V_14 , V_392 ) ) ;
V_175 -> V_43 = V_43 ;
}
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
#ifdef F_222
if ( F_45 ( V_65 -> V_393 ) )
F_4 ( V_4 ) -> V_160 = F_223 ( V_65 ) ;
else
#endif
F_4 ( V_4 ) -> V_160 = V_19 ;
V_221 = F_51 ( V_2 , V_65 , V_15 ,
V_4 , & V_96 , & V_144 , V_173 )
+ sizeof( * V_67 ) ;
F_97 ( V_4 , V_221 ) ;
F_98 ( V_4 ) ;
V_67 = F_37 ( V_4 ) ;
memset ( V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 -> V_394 = 1 ;
V_67 -> V_395 = 1 ;
F_33 ( V_65 , V_67 ) ;
V_67 -> V_230 = V_175 -> V_396 ;
V_67 -> V_232 = V_175 -> V_397 ;
F_40 ( V_4 , F_52 ( V_65 ) -> V_398 ,
V_85 | V_244 ) ;
if ( V_99 & V_96 . V_97 ) {
if ( V_386 ) {
T_8 * V_399 = F_128 ( V_4 , V_386 ) ;
memcpy ( V_399 , V_146 -> V_400 , V_386 ) ;
F_4 ( V_4 ) -> V_10 += V_386 ;
}
if ( V_96 . V_117 > 0 ) {
T_1 V_401 [ V_402 ] ;
T_4 * V_403 = & V_173 -> V_404 [ V_405 ] ;
T_4 * V_406 = & V_403 [ V_407 - 1 ] ;
* V_406 -- ^= V_96 . V_114 ;
* V_406 -- ^= F_52 ( V_65 ) -> V_408 + 1 ;
* V_406 -- ^= F_4 ( V_4 ) -> V_72 + 1 ;
* V_406 -- ^= ( ( ( V_409 T_4 ) V_67 -> V_232 << 16 ) | ( V_409 T_4 ) V_67 -> V_230 ) ;
* V_406 -- ^= ( T_4 ) ( unsigned long ) V_146 ;
F_224 ( ( T_1 * ) & V_173 -> V_404 [ 0 ] ,
( char * ) V_403 ,
& V_401 [ 0 ] ) ;
V_96 . V_105 =
( T_5 * ) & V_173 -> V_404 [ 0 ] ;
}
}
V_67 -> V_72 = F_46 ( F_4 ( V_4 ) -> V_72 ) ;
V_67 -> V_234 = F_46 ( F_52 ( V_65 ) -> V_408 + 1 ) ;
V_67 -> V_236 = F_101 ( F_17 ( V_65 -> V_40 , 65535U ) ) ;
F_44 ( ( T_9 * ) ( V_67 + 1 ) , V_6 , & V_96 ) ;
V_67 -> V_410 = ( V_221 >> 2 ) ;
F_104 ( F_105 ( V_2 ) , V_245 , F_5 ( V_4 ) ) ;
#ifdef F_49
if ( V_144 ) {
F_52 ( V_65 ) -> V_155 -> V_241 ( V_96 . V_105 ,
V_144 , NULL , V_65 , V_4 ) ;
}
#endif
return V_4 ;
}
void F_225 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_5 V_43 ;
V_6 -> V_70 = sizeof( struct V_66 ) +
( V_159 ? V_162 : 0 ) ;
#ifdef F_49
if ( V_6 -> V_155 -> V_156 ( V_2 , V_2 ) != NULL )
V_6 -> V_70 += V_157 ;
#endif
if ( V_6 -> V_54 . V_388 )
V_6 -> V_54 . V_284 = V_6 -> V_54 . V_388 ;
V_6 -> V_411 = 0 ;
F_146 ( V_2 ) ;
F_147 ( V_2 , F_149 ( V_14 ) ) ;
if ( ! V_6 -> V_41 )
V_6 -> V_41 = F_221 ( V_14 , V_389 ) ;
V_6 -> V_16 = F_12 ( V_14 ) ;
if ( V_6 -> V_54 . V_388 && V_6 -> V_54 . V_388 < V_6 -> V_16 )
V_6 -> V_16 = V_6 -> V_54 . V_388 ;
F_226 ( V_2 ) ;
if ( V_2 -> V_390 & V_391 &&
( V_6 -> V_41 > F_183 ( V_2 ) || V_6 -> V_41 == 0 ) )
V_6 -> V_41 = F_183 ( V_2 ) ;
F_24 ( F_183 ( V_2 ) ,
V_6 -> V_16 - ( V_6 -> V_54 . V_412 ? V_6 -> V_70 - sizeof( struct V_66 ) : 0 ) ,
& V_6 -> V_40 ,
& V_6 -> V_41 ,
V_163 ,
& V_43 ,
F_221 ( V_14 , V_392 ) ) ;
V_6 -> V_54 . V_43 = V_43 ;
V_6 -> V_340 = V_6 -> V_40 ;
V_2 -> V_413 = 0 ;
F_227 ( V_2 , V_414 ) ;
V_6 -> V_320 = 0 ;
F_228 ( V_6 , 0 ) ;
V_6 -> V_87 = V_6 -> V_249 ;
V_6 -> V_302 = V_6 -> V_249 ;
V_6 -> V_88 = V_6 -> V_249 ;
V_6 -> V_9 = V_6 -> V_249 ;
if ( F_47 ( ! V_6 -> V_415 ) )
V_6 -> V_56 = 0 ;
V_6 -> V_55 = V_6 -> V_56 ;
V_6 -> V_416 = V_6 -> V_56 ;
F_18 ( V_2 ) -> V_26 = V_417 ;
F_18 ( V_2 ) -> V_418 = 0 ;
F_229 ( V_6 ) ;
}
static void F_230 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_179 * V_180 = F_4 ( V_4 ) ;
V_180 -> V_10 += V_4 -> V_71 ;
F_109 ( V_4 ) ;
F_231 ( V_2 , V_4 ) ;
V_2 -> V_250 += V_4 -> V_214 ;
F_111 ( V_2 , V_4 -> V_214 ) ;
V_6 -> V_249 = V_180 -> V_10 ;
V_6 -> V_8 += F_5 ( V_4 ) ;
}
static int F_232 ( struct V_1 * V_2 , struct V_3 * V_394 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_152 * V_419 = V_6 -> V_154 ;
int V_420 = 0 , V_45 , V_211 , V_222 = 0 , V_421 = V_419 -> V_192 -> V_422 ;
struct V_3 * V_423 = NULL , * V_192 ;
unsigned long V_424 = 0 ;
V_6 -> V_54 . V_284 = V_6 -> V_16 ;
F_233 ( V_2 , & V_6 -> V_54 . V_284 , & V_419 -> V_167 ,
& V_420 , & V_424 ) ;
if ( V_420 > 1 &&
F_234 ( V_317 , V_424 + ( 60 * V_425 << V_420 ) ) ) {
V_419 -> V_167 . V_71 = - 1 ;
goto V_426;
}
if ( V_427 & V_428 )
V_419 -> V_167 . V_71 = - 1 ;
else if ( V_419 -> V_167 . V_71 <= 0 )
goto V_426;
if ( V_6 -> V_54 . V_388 && V_6 -> V_54 . V_388 < V_6 -> V_54 . V_284 )
V_6 -> V_54 . V_284 = V_6 -> V_54 . V_388 ;
V_45 = F_143 ( V_2 , F_18 ( V_2 ) -> V_294 ) -
V_149 ;
V_423 = F_235 ( V_394 , F_236 ( V_394 ) , V_45 ,
V_2 -> V_335 ) ;
if ( V_423 == NULL )
goto V_426;
for ( V_211 = 0 ; V_211 < V_421 && V_423 -> V_71 < V_45 ; ++ V_211 ) {
struct V_429 * V_430 = & V_419 -> V_192 -> V_431 [ V_211 ] ;
unsigned char T_12 * V_432 = V_430 -> V_433 ;
int V_71 = V_430 -> V_434 ;
if ( V_423 -> V_71 + V_71 > V_45 )
V_71 = V_45 - V_423 -> V_71 ;
else if ( V_211 + 1 == V_421 )
V_419 -> V_192 = NULL ;
if ( F_237 ( V_423 , V_432 , V_71 ) )
goto V_426;
}
V_192 = F_93 ( V_423 , V_2 -> V_335 ) ;
if ( V_192 == NULL )
goto V_426;
F_4 ( V_192 ) -> V_72 ++ ;
F_4 ( V_192 ) -> V_58 &= ~ V_85 ;
F_4 ( V_192 ) -> V_58 = ( V_244 | V_270 ) ;
F_230 ( V_2 , V_192 ) ;
V_419 -> V_435 = V_192 -> V_71 ;
if ( F_89 ( V_2 , V_423 , 0 , V_2 -> V_335 ) == 0 ) {
V_6 -> V_423 = ( V_419 -> V_435 > 0 ) ;
F_212 ( F_105 ( V_2 ) , V_436 ) ;
goto V_437;
}
V_423 = NULL ;
V_426:
if ( V_419 -> V_167 . V_71 > 0 )
V_419 -> V_167 . V_71 = 0 ;
V_222 = F_89 ( V_2 , V_394 , 1 , V_2 -> V_335 ) ;
if ( V_222 )
V_6 -> V_169 = 0 ;
F_238 ( V_423 ) ;
V_437:
V_419 -> V_167 . V_71 = - 1 ;
return V_222 ;
}
int F_239 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_264 ;
int V_222 ;
F_225 ( V_2 ) ;
V_264 = F_207 ( V_356 + 15 , V_2 -> V_335 ) ;
if ( F_45 ( V_264 == NULL ) )
return - V_225 ;
F_209 ( V_264 , V_356 ) ;
F_40 ( V_264 , V_6 -> V_249 ++ , V_85 ) ;
V_6 -> V_362 = F_4 ( V_264 ) -> V_160 = V_19 ;
F_230 ( V_2 , V_264 ) ;
F_32 ( V_2 , V_264 ) ;
V_222 = V_6 -> V_154 ? F_232 ( V_2 , V_264 ) :
F_89 ( V_2 , V_264 , 1 , V_2 -> V_335 ) ;
if ( V_222 == - V_438 )
return V_222 ;
V_6 -> V_9 = V_6 -> V_249 ;
V_6 -> V_439 = V_6 -> V_249 ;
F_198 ( F_105 ( V_2 ) , V_440 ) ;
F_205 ( V_2 , V_375 ,
F_18 ( V_2 ) -> V_26 , V_376 ) ;
return 0 ;
}
void F_240 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_35 = V_30 -> V_33 . V_35 ;
unsigned long V_441 ;
if ( V_35 > V_442 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_443 = V_425 / 2 ;
if ( V_30 -> V_33 . V_36 ||
( V_30 -> V_33 . V_444 & V_445 ) )
V_443 = V_446 ;
if ( V_6 -> V_447 ) {
int V_448 = F_19 ( V_6 -> V_447 >> 3 , V_442 ) ;
if ( V_448 < V_443 )
V_443 = V_448 ;
}
V_35 = F_17 ( V_35 , V_443 ) ;
}
V_441 = V_317 + V_35 ;
if ( V_30 -> V_33 . V_444 & V_449 ) {
if ( V_30 -> V_33 . V_450 ||
F_241 ( V_30 -> V_33 . V_441 , V_317 + ( V_35 >> 2 ) ) ) {
F_242 ( V_2 ) ;
return;
}
if ( ! F_234 ( V_441 , V_30 -> V_33 . V_441 ) )
V_441 = V_30 -> V_33 . V_441 ;
}
V_30 -> V_33 . V_444 |= V_451 | V_449 ;
V_30 -> V_33 . V_441 = V_441 ;
F_243 ( V_2 , & V_30 -> V_452 , V_441 ) ;
}
void F_242 ( struct V_1 * V_2 )
{
struct V_3 * V_264 ;
if ( V_2 -> V_185 == V_334 )
return;
V_264 = F_211 ( V_356 , F_179 ( V_2 , V_191 ) ) ;
if ( V_264 == NULL ) {
F_244 ( V_2 ) ;
F_18 ( V_2 ) -> V_33 . V_35 = V_453 ;
F_205 ( V_2 , V_38 ,
V_446 , V_376 ) ;
return;
}
F_209 ( V_264 , V_356 ) ;
F_40 ( V_264 , F_7 ( V_2 ) , V_244 ) ;
F_4 ( V_264 ) -> V_160 = V_19 ;
F_89 ( V_2 , V_264 , 0 , F_179 ( V_2 , V_191 ) ) ;
}
static int F_245 ( struct V_1 * V_2 , int V_454 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_211 ( V_356 , F_179 ( V_2 , V_191 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_209 ( V_4 , V_356 ) ;
F_40 ( V_4 , V_6 -> V_87 - ! V_454 , V_244 ) ;
F_4 ( V_4 ) -> V_160 = V_19 ;
return F_89 ( V_2 , V_4 , 0 , V_191 ) ;
}
void F_246 ( struct V_1 * V_2 )
{
if ( V_2 -> V_185 == V_455 ) {
F_2 ( V_2 ) -> V_456 = F_2 ( V_2 ) -> V_56 - 1 ;
F_2 ( V_2 ) -> V_9 = F_2 ( V_2 ) -> V_249 ;
F_245 ( V_2 , 0 ) ;
}
}
int F_247 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_185 == V_334 )
return - 1 ;
if ( ( V_4 = F_162 ( V_2 ) ) != NULL &&
F_8 ( F_4 ( V_4 ) -> V_72 , F_9 ( V_6 ) ) ) {
int V_222 ;
unsigned int V_15 = F_56 ( V_2 ) ;
unsigned int V_457 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_72 ;
if ( F_8 ( V_6 -> V_439 , F_4 ( V_4 ) -> V_10 ) )
V_6 -> V_439 = F_4 ( V_4 ) -> V_10 ;
if ( V_457 < F_4 ( V_4 ) -> V_10 - F_4 ( V_4 ) -> V_72 ||
V_4 -> V_71 > V_15 ) {
V_457 = F_17 ( V_457 , V_15 ) ;
F_4 ( V_4 ) -> V_58 |= V_270 ;
if ( F_121 ( V_2 , V_4 , V_457 , V_15 ) )
return - 1 ;
} else if ( ! F_5 ( V_4 ) )
F_112 ( V_2 , V_4 , V_15 ) ;
F_4 ( V_4 ) -> V_58 |= V_270 ;
F_4 ( V_4 ) -> V_160 = V_19 ;
V_222 = F_89 ( V_2 , V_4 , 1 , V_191 ) ;
if ( ! V_222 )
F_1 ( V_2 , V_4 ) ;
return V_222 ;
} else {
if ( F_248 ( V_6 -> V_88 , V_6 -> V_87 + 1 , V_6 -> V_87 + 0xFFFF ) )
F_245 ( V_2 , 1 ) ;
return F_245 ( V_2 , 0 ) ;
}
}
void F_249 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_222 ;
V_222 = F_247 ( V_2 ) ;
if ( V_6 -> V_8 || ! F_162 ( V_2 ) ) {
V_30 -> V_458 = 0 ;
V_30 -> V_459 = 0 ;
return;
}
if ( V_222 <= 0 ) {
if ( V_30 -> V_459 < V_460 )
V_30 -> V_459 ++ ;
V_30 -> V_458 ++ ;
F_205 ( V_2 , V_461 ,
F_17 ( V_30 -> V_26 << V_30 -> V_459 , V_376 ) ,
V_376 ) ;
} else {
if ( ! V_30 -> V_458 )
V_30 -> V_458 = 1 ;
F_205 ( V_2 , V_461 ,
F_17 ( V_30 -> V_26 << V_30 -> V_459 ,
V_462 ) ,
V_376 ) ;
}
}
