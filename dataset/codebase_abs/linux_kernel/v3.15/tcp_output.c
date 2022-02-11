static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_9 = V_8 -> V_10 ;
F_4 ( V_2 , V_4 ) ;
V_8 -> V_11 = F_5 ( V_4 ) -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
if ( ! V_9 || V_6 -> V_13 == V_14 ||
V_6 -> V_13 == V_15 ) {
F_7 ( V_2 ) ;
}
F_8 ( F_9 ( V_2 ) , V_16 ,
F_6 ( V_4 ) ) ;
}
static inline T_1 F_10 ( const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( F_12 ( V_8 ) , V_8 -> V_11 ) )
return V_8 -> V_11 ;
else
return F_12 ( V_8 ) ;
}
static T_2 F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
int V_19 = V_8 -> V_20 ;
if ( V_18 ) {
unsigned int V_21 = F_15 ( V_18 ) ;
if ( V_21 < V_19 ) {
V_19 = V_21 ;
V_8 -> V_20 = V_19 ;
}
}
return ( T_2 ) V_19 ;
}
static void F_16 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_3 V_22 = V_23 - V_8 -> V_24 ;
T_4 V_25 = F_17 ( V_8 , V_18 ) ;
T_4 V_26 = V_8 -> V_27 ;
F_18 ( V_2 , V_28 ) ;
V_8 -> V_29 = F_19 ( V_2 ) ;
V_25 = F_20 ( V_25 , V_26 ) ;
while ( ( V_22 -= F_2 ( V_2 ) -> V_30 ) > 0 && V_26 > V_25 )
V_26 >>= 1 ;
V_8 -> V_27 = F_21 ( V_26 , V_25 ) ;
V_8 -> V_31 = V_23 ;
V_8 -> V_32 = 0 ;
}
static void F_22 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_4 V_33 = V_23 ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_34 &&
( ! V_8 -> V_10 && ( T_3 ) ( V_33 - V_8 -> V_24 ) > V_6 -> V_30 ) )
F_16 ( V_2 , F_14 ( V_2 ) ) ;
V_8 -> V_24 = V_33 ;
if ( ( T_4 ) ( V_33 - V_6 -> V_35 . V_36 ) < V_6 -> V_35 . V_37 &&
( ! V_18 || ! F_23 ( V_18 , V_38 ) ) )
V_6 -> V_35 . V_39 = 1 ;
}
static inline void F_24 ( struct V_1 * V_2 , unsigned int V_40 )
{
F_25 ( V_2 , V_40 ) ;
F_26 ( V_2 , V_41 ) ;
}
T_4 F_27 ( T_4 V_19 )
{
T_4 V_42 = V_43 * 2 ;
if ( V_19 > 1460 )
V_42 = F_21 ( ( 1460 * V_42 ) / V_19 , 2U ) ;
return V_42 ;
}
void F_28 ( int V_44 , T_1 V_19 ,
T_1 * V_45 , T_1 * V_46 ,
int V_47 , T_5 * V_48 ,
T_1 V_49 )
{
unsigned int V_50 = ( V_44 < 0 ? 0 : V_44 ) ;
if ( * V_46 == 0 )
( * V_46 ) = ( 65535 << 14 ) ;
V_50 = F_20 ( * V_46 , V_50 ) ;
if ( V_50 > V_19 )
V_50 = ( V_50 / V_19 ) * V_19 ;
if ( V_51 )
( * V_45 ) = F_20 ( V_50 , V_52 ) ;
else
( * V_45 ) = V_50 ;
( * V_48 ) = 0 ;
if ( V_47 ) {
V_50 = F_29 ( T_4 , V_53 [ 2 ] , V_54 ) ;
V_50 = F_30 ( T_4 , V_50 , * V_46 ) ;
while ( V_50 > 65535 && ( * V_48 ) < 14 ) {
V_50 >>= 1 ;
( * V_48 ) ++ ;
}
}
if ( V_19 > ( 1 << * V_48 ) ) {
if ( ! V_49 )
V_49 = F_27 ( V_19 ) ;
* V_45 = F_20 ( * V_45 , V_49 * V_19 ) ;
}
( * V_46 ) = F_20 ( 65535U << ( * V_48 ) , * V_46 ) ;
}
static T_6 F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_55 = V_8 -> V_45 ;
T_4 V_56 = F_32 ( V_8 ) ;
T_4 V_57 = F_33 ( V_2 ) ;
if ( V_57 < V_56 ) {
if ( V_57 == 0 )
F_34 ( F_9 ( V_2 ) ,
V_58 ) ;
V_57 = F_35 ( V_56 , 1 << V_8 -> V_59 . V_48 ) ;
}
V_8 -> V_45 = V_57 ;
V_8 -> V_60 = V_8 -> V_61 ;
if ( ! V_8 -> V_59 . V_48 && V_51 )
V_57 = F_20 ( V_57 , V_52 ) ;
else
V_57 = F_20 ( V_57 , ( 65535U << V_8 -> V_59 . V_48 ) ) ;
V_57 >>= V_8 -> V_59 . V_48 ;
if ( V_57 == 0 ) {
V_8 -> V_62 = 0 ;
if ( V_55 )
F_34 ( F_9 ( V_2 ) ,
V_63 ) ;
} else if ( V_55 == 0 ) {
F_34 ( F_9 ( V_2 ) , V_64 ) ;
}
return V_57 ;
}
static inline void F_36 ( const struct V_7 * V_8 , struct V_3 * V_4 )
{
F_5 ( V_4 ) -> V_65 &= ~ V_66 ;
if ( ! ( V_8 -> V_67 & V_68 ) )
F_5 ( V_4 ) -> V_65 &= ~ V_69 ;
}
static inline void F_37 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_67 = 0 ;
if ( F_9 ( V_2 ) -> V_70 . V_71 == 1 ) {
F_5 ( V_4 ) -> V_65 |= V_69 | V_66 ;
V_8 -> V_67 = V_68 ;
}
}
static T_7 void
F_38 ( const struct V_72 * V_73 , struct V_74 * V_75 )
{
if ( F_39 ( V_73 ) -> V_76 )
V_75 -> V_77 = 1 ;
}
static inline void F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_78 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_67 & V_68 ) {
if ( V_4 -> V_79 != V_78 &&
! F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_11 ) ) {
F_41 ( V_2 ) ;
if ( V_8 -> V_67 & V_81 ) {
V_8 -> V_67 &= ~ V_81 ;
F_42 ( V_4 ) -> V_82 = 1 ;
F_43 ( V_4 ) -> V_83 |= V_84 ;
}
} else {
F_44 ( V_2 ) ;
}
if ( V_8 -> V_67 & V_85 )
F_42 ( V_4 ) -> V_77 = 1 ;
}
}
static void F_45 ( struct V_3 * V_4 , T_4 V_80 , T_8 V_86 )
{
struct V_87 * V_88 = F_43 ( V_4 ) ;
V_4 -> V_89 = V_90 ;
V_4 -> V_91 = 0 ;
F_5 ( V_4 ) -> V_65 = V_86 ;
F_5 ( V_4 ) -> V_92 = 0 ;
V_88 -> V_93 = 1 ;
V_88 -> V_94 = 0 ;
V_88 -> V_83 = 0 ;
F_5 ( V_4 ) -> V_80 = V_80 ;
if ( V_86 & ( V_95 | V_96 ) )
V_80 ++ ;
F_5 ( V_4 ) -> V_12 = V_80 ;
}
static inline bool F_46 ( const struct V_7 * V_8 )
{
return V_8 -> V_97 != V_8 -> V_98 ;
}
static void F_47 ( T_9 * V_99 , struct V_7 * V_8 ,
struct V_100 * V_101 )
{
T_6 V_102 = V_101 -> V_102 ;
if ( F_48 ( V_103 & V_102 ) ) {
* V_99 ++ = F_49 ( ( V_104 << 24 ) | ( V_104 << 16 ) |
( V_105 << 8 ) | V_106 ) ;
V_101 -> V_107 = ( T_5 * ) V_99 ;
V_99 += 4 ;
}
if ( F_48 ( V_101 -> V_19 ) ) {
* V_99 ++ = F_49 ( ( V_108 << 24 ) |
( V_109 << 16 ) |
V_101 -> V_19 ) ;
}
if ( F_50 ( V_110 & V_102 ) ) {
if ( F_48 ( V_111 & V_102 ) ) {
* V_99 ++ = F_49 ( ( V_112 << 24 ) |
( V_113 << 16 ) |
( V_114 << 8 ) |
V_115 ) ;
V_102 &= ~ V_111 ;
} else {
* V_99 ++ = F_49 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_114 << 8 ) |
V_115 ) ;
}
* V_99 ++ = F_49 ( V_101 -> V_116 ) ;
* V_99 ++ = F_49 ( V_101 -> V_117 ) ;
}
if ( F_48 ( V_111 & V_102 ) ) {
* V_99 ++ = F_49 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
}
if ( F_48 ( V_118 & V_102 ) ) {
* V_99 ++ = F_49 ( ( V_104 << 24 ) |
( V_119 << 16 ) |
( V_120 << 8 ) |
V_101 -> V_121 ) ;
}
if ( F_48 ( V_101 -> V_122 ) ) {
struct V_123 * V_124 = V_8 -> V_59 . V_125 ?
V_8 -> V_126 : V_8 -> V_127 ;
int V_128 ;
* V_99 ++ = F_49 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_129 << 8 ) |
( V_130 + ( V_101 -> V_122 *
V_131 ) ) ) ;
for ( V_128 = 0 ; V_128 < V_101 -> V_122 ;
++ V_128 ) {
* V_99 ++ = F_49 ( V_124 [ V_128 ] . V_132 ) ;
* V_99 ++ = F_49 ( V_124 [ V_128 ] . V_12 ) ;
}
V_8 -> V_59 . V_125 = 0 ;
}
if ( F_48 ( V_133 & V_102 ) ) {
struct V_134 * V_135 = V_101 -> V_136 ;
* V_99 ++ = F_49 ( ( V_137 << 24 ) |
( ( V_138 + V_135 -> V_79 ) << 16 ) |
V_139 ) ;
memcpy ( V_99 , V_135 -> V_140 , V_135 -> V_79 ) ;
if ( ( V_135 -> V_79 & 3 ) == 2 ) {
T_8 * V_141 = ( ( T_8 * ) V_99 ) + V_135 -> V_79 ;
V_141 [ 0 ] = V_141 [ 1 ] = V_104 ;
}
V_99 += ( V_135 -> V_79 + 3 ) >> 2 ;
}
}
static unsigned int F_51 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_142 * * V_143 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_144 = V_145 ;
struct V_146 * V_147 = V_8 -> V_148 ;
#ifdef F_52
* V_143 = V_8 -> V_149 -> V_150 ( V_2 , V_2 ) ;
if ( * V_143 ) {
V_101 -> V_102 |= V_103 ;
V_144 -= V_151 ;
}
#else
* V_143 = NULL ;
#endif
V_101 -> V_19 = F_13 ( V_2 ) ;
V_144 -= V_152 ;
if ( F_50 ( V_153 && * V_143 == NULL ) ) {
V_101 -> V_102 |= V_110 ;
V_101 -> V_116 = F_5 ( V_4 ) -> V_154 + V_8 -> V_155 ;
V_101 -> V_117 = V_8 -> V_59 . V_156 ;
V_144 -= V_157 ;
}
if ( F_50 ( V_158 ) ) {
V_101 -> V_121 = V_8 -> V_59 . V_48 ;
V_101 -> V_102 |= V_118 ;
V_144 -= V_159 ;
}
if ( F_50 ( V_160 ) ) {
V_101 -> V_102 |= V_111 ;
if ( F_48 ( ! ( V_110 & V_101 -> V_102 ) ) )
V_144 -= V_161 ;
}
if ( V_147 && V_147 -> V_162 . V_79 >= 0 ) {
T_4 V_163 = V_138 + V_147 -> V_162 . V_79 ;
V_163 = ( V_163 + 3 ) & ~ 3U ;
if ( V_144 >= V_163 ) {
V_101 -> V_102 |= V_133 ;
V_101 -> V_136 = & V_147 -> V_162 ;
V_144 -= V_163 ;
V_8 -> V_164 = 1 ;
}
}
return V_145 - V_144 ;
}
static unsigned int F_53 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
unsigned int V_19 , struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_142 * * V_143 ,
struct V_134 * V_135 )
{
struct V_165 * V_166 = F_39 ( V_73 ) ;
unsigned int V_144 = V_145 ;
#ifdef F_52
* V_143 = F_54 ( V_73 ) -> V_149 -> V_150 ( V_2 , V_73 ) ;
if ( * V_143 ) {
V_101 -> V_102 |= V_103 ;
V_144 -= V_151 ;
V_166 -> V_167 &= ! V_166 -> V_168 ;
}
#else
* V_143 = NULL ;
#endif
V_101 -> V_19 = V_19 ;
V_144 -= V_152 ;
if ( F_50 ( V_166 -> V_47 ) ) {
V_101 -> V_121 = V_166 -> V_48 ;
V_101 -> V_102 |= V_118 ;
V_144 -= V_159 ;
}
if ( F_50 ( V_166 -> V_167 ) ) {
V_101 -> V_102 |= V_110 ;
V_101 -> V_116 = F_5 ( V_4 ) -> V_154 ;
V_101 -> V_117 = V_73 -> V_156 ;
V_144 -= V_157 ;
}
if ( F_50 ( V_166 -> V_168 ) ) {
V_101 -> V_102 |= V_111 ;
if ( F_48 ( ! V_166 -> V_167 ) )
V_144 -= V_161 ;
}
if ( V_135 != NULL ) {
T_4 V_163 = V_138 + V_135 -> V_79 ;
V_163 = ( V_163 + 3 ) & ~ 3U ;
if ( V_144 >= V_163 ) {
V_101 -> V_102 |= V_133 ;
V_101 -> V_136 = V_135 ;
V_144 -= V_163 ;
}
}
return V_145 - V_144 ;
}
static unsigned int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_142 * * V_143 )
{
struct V_169 * V_170 = V_4 ? F_5 ( V_4 ) : NULL ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_171 = 0 ;
unsigned int V_172 ;
V_101 -> V_102 = 0 ;
#ifdef F_52
* V_143 = V_8 -> V_149 -> V_150 ( V_2 , V_2 ) ;
if ( F_48 ( * V_143 ) ) {
V_101 -> V_102 |= V_103 ;
V_171 += V_151 ;
}
#else
* V_143 = NULL ;
#endif
if ( F_50 ( V_8 -> V_59 . V_167 ) ) {
V_101 -> V_102 |= V_110 ;
V_101 -> V_116 = V_170 ? V_170 -> V_154 + V_8 -> V_155 : 0 ;
V_101 -> V_117 = V_8 -> V_59 . V_156 ;
V_171 += V_157 ;
}
V_172 = V_8 -> V_59 . V_173 + V_8 -> V_59 . V_125 ;
if ( F_48 ( V_172 ) ) {
const unsigned int V_144 = V_145 - V_171 ;
V_101 -> V_122 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_171 += V_174 +
V_101 -> V_122 * V_131 ;
}
return V_171 ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_175 ) &
( V_176 | V_177 | V_178 |
V_179 | V_180 ) )
F_57 ( V_2 , F_58 ( V_2 ) , F_3 ( V_2 ) -> V_181 ,
0 , V_182 ) ;
}
static void F_59 ( unsigned long V_183 )
{
struct V_184 * V_185 = (struct V_184 * ) V_183 ;
F_60 ( V_186 ) ;
unsigned long V_86 ;
struct V_187 * V_188 , * V_189 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_61 ( V_86 ) ;
F_62 ( & V_185 -> V_190 , & V_186 ) ;
F_63 ( V_86 ) ;
F_64 (q, n, &list) {
V_8 = F_65 ( V_188 , struct V_7 , V_191 ) ;
F_66 ( & V_8 -> V_191 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_67 ( V_2 ) ;
if ( ! F_68 ( V_2 ) ) {
F_56 ( V_2 ) ;
} else {
F_69 ( V_192 , & V_8 -> V_193 ) ;
}
F_70 ( V_2 ) ;
F_71 ( V_194 , & V_8 -> V_193 ) ;
F_72 ( V_2 ) ;
}
}
void F_73 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_86 , V_195 ;
do {
V_86 = V_8 -> V_193 ;
if ( ! ( V_86 & V_196 ) )
return;
V_195 = V_86 & ~ V_196 ;
} while ( F_74 ( & V_8 -> V_193 , V_86 , V_195 ) != V_86 );
if ( V_86 & ( 1UL << V_192 ) )
F_56 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( V_86 & ( 1UL << V_197 ) ) {
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
}
if ( V_86 & ( 1UL << V_198 ) ) {
F_78 ( V_2 ) ;
F_77 ( V_2 ) ;
}
if ( V_86 & ( 1UL << V_199 ) ) {
V_2 -> V_200 -> V_201 ( V_2 ) ;
F_77 ( V_2 ) ;
}
}
void T_10 F_79 ( void )
{
int V_202 ;
F_80 (i) {
struct V_184 * V_185 = & F_81 ( V_184 , V_202 ) ;
F_82 ( & V_185 -> V_190 ) ;
F_83 ( & V_185 -> V_203 ,
F_59 ,
( unsigned long ) V_185 ) ;
}
}
void F_84 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_85 ( V_204 , & V_8 -> V_193 ) &&
! F_86 ( V_194 , & V_8 -> V_193 ) ) {
unsigned long V_86 ;
struct V_184 * V_185 ;
F_87 ( V_4 -> V_205 - 1 , & V_2 -> V_206 ) ;
F_61 ( V_86 ) ;
V_185 = & F_88 ( V_184 ) ;
F_89 ( & V_8 -> V_191 , & V_185 -> V_190 ) ;
F_90 ( & V_185 -> V_203 ) ;
F_63 ( V_86 ) ;
} else {
F_91 ( V_4 ) ;
}
}
static int F_92 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_207 ,
T_11 V_208 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_209 * V_210 ;
struct V_7 * V_8 ;
struct V_169 * V_170 ;
struct V_100 V_101 ;
unsigned int V_211 , V_212 ;
struct V_142 * V_143 ;
struct V_74 * V_75 ;
int V_213 ;
F_93 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_207 ) {
const struct V_3 * V_214 = V_4 + 1 ;
F_94 ( & V_4 -> V_215 ) ;
if ( F_48 ( V_4 -> V_214 == V_216 &&
V_214 -> V_214 == V_217 ) )
F_34 ( F_9 ( V_2 ) ,
V_218 ) ;
if ( F_48 ( F_95 ( V_4 ) ) )
V_4 = F_96 ( V_4 , V_208 ) ;
else
V_4 = F_97 ( V_4 , V_208 ) ;
if ( F_48 ( ! V_4 ) )
return - V_219 ;
V_4 -> V_220 . V_221 = 0 ;
}
V_210 = F_98 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_170 = F_5 ( V_4 ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
if ( F_48 ( V_170 -> V_65 & V_95 ) )
V_211 = F_51 ( V_2 , V_4 , & V_101 , & V_143 ) ;
else
V_211 = F_55 ( V_2 , V_4 , & V_101 ,
& V_143 ) ;
V_212 = V_211 + sizeof( struct V_74 ) ;
if ( F_99 ( V_8 ) == 0 )
F_18 ( V_2 , V_222 ) ;
V_4 -> V_223 = F_100 ( V_2 ) == 0 ;
F_101 ( V_4 , V_212 ) ;
F_102 ( V_4 ) ;
F_103 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_224 = F_84 ;
F_104 ( V_4 -> V_205 , & V_2 -> V_206 ) ;
V_75 = F_42 ( V_4 ) ;
V_75 -> V_225 = V_210 -> V_226 ;
V_75 -> V_227 = V_210 -> V_228 ;
V_75 -> V_80 = F_49 ( V_170 -> V_80 ) ;
V_75 -> V_229 = F_49 ( V_8 -> V_61 ) ;
* ( ( ( V_230 * ) V_75 ) + 6 ) = F_105 ( ( ( V_212 >> 2 ) << 12 ) |
V_170 -> V_65 ) ;
if ( F_48 ( V_170 -> V_65 & V_95 ) ) {
V_75 -> V_231 = F_105 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_75 -> V_231 = F_105 ( F_31 ( V_2 ) ) ;
}
V_75 -> V_232 = 0 ;
V_75 -> V_233 = 0 ;
if ( F_48 ( F_46 ( V_8 ) && F_11 ( V_170 -> V_80 , V_8 -> V_98 ) ) ) {
if ( F_11 ( V_8 -> V_98 , V_170 -> V_80 + 0x10000 ) ) {
V_75 -> V_233 = F_105 ( V_8 -> V_98 - V_170 -> V_80 ) ;
V_75 -> V_234 = 1 ;
} else if ( F_106 ( V_170 -> V_80 + 0xFFFF , V_8 -> V_11 ) ) {
V_75 -> V_233 = F_105 ( 0xFFFF ) ;
V_75 -> V_234 = 1 ;
}
}
F_47 ( ( T_9 * ) ( V_75 + 1 ) , V_8 , & V_101 ) ;
if ( F_50 ( ( V_170 -> V_65 & V_95 ) == 0 ) )
F_40 ( V_2 , V_4 , V_212 ) ;
#ifdef F_52
if ( V_143 ) {
F_107 ( V_2 , V_235 ) ;
V_8 -> V_149 -> V_236 ( V_101 . V_107 ,
V_143 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_237 -> V_238 ( V_2 , V_4 ) ;
if ( F_50 ( V_170 -> V_65 & V_239 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_79 != V_212 )
F_22 ( V_8 , V_2 ) ;
if ( F_106 ( V_170 -> V_12 , V_8 -> V_11 ) || V_170 -> V_80 == V_170 -> V_12 )
F_108 ( F_9 ( V_2 ) , V_240 ,
F_6 ( V_4 ) ) ;
V_213 = V_6 -> V_237 -> V_241 ( V_2 , V_4 , & V_210 -> V_242 . V_243 ) ;
if ( F_50 ( V_213 <= 0 ) )
return V_213 ;
F_109 ( V_2 , 1 ) ;
return F_110 ( V_213 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_244 = F_5 ( V_4 ) -> V_12 ;
F_112 ( V_4 ) ;
F_113 ( V_2 , V_4 ) ;
V_2 -> V_245 += V_4 -> V_205 ;
F_114 ( V_2 , V_4 -> V_205 ) ;
}
static void F_115 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_246 )
{
struct V_87 * V_88 = F_43 ( V_4 ) ;
F_116 ( F_95 ( V_4 ) ) ;
if ( V_4 -> V_79 <= V_246 || V_4 -> V_89 == V_247 ) {
V_88 -> V_93 = 1 ;
V_88 -> V_94 = 0 ;
V_88 -> V_83 = 0 ;
} else {
V_88 -> V_93 = F_117 ( V_4 -> V_79 , V_246 ) ;
V_88 -> V_94 = V_246 ;
V_88 -> V_83 = V_2 -> V_248 ;
}
}
static void F_118 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_249 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_250 || F_119 ( V_8 ) )
return;
if ( F_106 ( F_120 ( V_8 ) , F_5 ( V_4 ) -> V_80 ) )
V_8 -> V_251 -= V_249 ;
}
static void F_121 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_249 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_249 ;
if ( F_5 ( V_4 ) -> V_92 & V_252 )
V_8 -> V_250 -= V_249 ;
if ( F_5 ( V_4 ) -> V_92 & V_253 )
V_8 -> V_254 -= V_249 ;
if ( F_5 ( V_4 ) -> V_92 & V_255 )
V_8 -> V_256 -= V_249 ;
if ( F_119 ( V_8 ) && V_249 > 0 )
V_8 -> V_250 -= F_30 ( T_4 , V_8 -> V_250 , V_249 ) ;
F_118 ( V_2 , V_4 , V_249 ) ;
if ( V_8 -> V_257 &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_5 ( V_8 -> V_257 ) -> V_80 ) &&
( F_122 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_252 ) ) )
V_8 -> V_258 -= V_249 ;
F_123 ( V_8 ) ;
}
int F_124 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 ,
unsigned int V_246 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_259 ;
int V_260 , V_261 ;
int V_262 ;
T_8 V_86 ;
if ( F_125 ( V_79 > V_4 -> V_79 ) )
return - V_263 ;
V_260 = F_126 ( V_4 ) - V_79 ;
if ( V_260 < 0 )
V_260 = 0 ;
if ( F_127 ( V_4 , V_182 ) )
return - V_264 ;
V_259 = F_128 ( V_2 , V_260 , V_182 ) ;
if ( V_259 == NULL )
return - V_264 ;
V_2 -> V_245 += V_259 -> V_205 ;
F_114 ( V_2 , V_259 -> V_205 ) ;
V_262 = V_4 -> V_79 - V_79 - V_260 ;
V_259 -> V_205 += V_262 ;
V_4 -> V_205 -= V_262 ;
F_5 ( V_259 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_259 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_259 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_96 | V_265 ) ;
F_5 ( V_259 ) -> V_65 = V_86 ;
F_5 ( V_259 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
if ( ! F_43 ( V_4 ) -> V_266 && V_4 -> V_89 != V_90 ) {
V_259 -> V_91 = F_129 ( V_4 -> V_183 + V_79 ,
F_130 ( V_259 , V_260 ) ,
V_260 , 0 ) ;
F_131 ( V_4 , V_79 ) ;
V_4 -> V_91 = F_132 ( V_4 -> V_91 , V_259 -> V_91 , V_79 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_133 ( V_4 , V_259 , V_79 ) ;
}
V_259 -> V_89 = V_4 -> V_89 ;
F_5 ( V_259 ) -> V_154 = F_5 ( V_4 ) -> V_154 ;
V_259 -> V_220 = V_4 -> V_220 ;
V_261 = F_6 ( V_4 ) ;
F_115 ( V_2 , V_4 , V_246 ) ;
F_115 ( V_2 , V_259 , V_246 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_259 ) -> V_12 ) ) {
int V_267 = V_261 - F_6 ( V_4 ) -
F_6 ( V_259 ) ;
if ( V_267 )
F_121 ( V_2 , V_4 , V_267 ) ;
}
F_112 ( V_259 ) ;
F_134 ( V_4 , V_259 , V_2 ) ;
return 0 ;
}
static void F_135 ( struct V_3 * V_4 , int V_79 )
{
struct V_87 * V_88 ;
int V_202 , V_268 , V_269 ;
V_269 = F_30 ( int , V_79 , F_126 ( V_4 ) ) ;
if ( V_269 ) {
F_136 ( V_4 , V_269 ) ;
V_79 -= V_269 ;
if ( ! V_79 )
return;
}
V_269 = V_79 ;
V_268 = 0 ;
V_88 = F_43 ( V_4 ) ;
for ( V_202 = 0 ; V_202 < V_88 -> V_266 ; V_202 ++ ) {
int V_171 = F_137 ( & V_88 -> V_270 [ V_202 ] ) ;
if ( V_171 <= V_269 ) {
F_138 ( V_4 , V_202 ) ;
V_269 -= V_171 ;
} else {
V_88 -> V_270 [ V_268 ] = V_88 -> V_270 [ V_202 ] ;
if ( V_269 ) {
V_88 -> V_270 [ V_268 ] . V_271 += V_269 ;
F_139 ( & V_88 -> V_270 [ V_268 ] , V_269 ) ;
V_269 = 0 ;
}
V_268 ++ ;
}
}
V_88 -> V_266 = V_268 ;
F_140 ( V_4 ) ;
V_4 -> V_272 -= V_79 ;
V_4 -> V_79 = V_4 -> V_272 ;
}
int F_141 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 )
{
if ( F_127 ( V_4 , V_182 ) )
return - V_264 ;
F_135 ( V_4 , V_79 ) ;
F_5 ( V_4 ) -> V_80 += V_79 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_205 -= V_79 ;
V_2 -> V_245 -= V_79 ;
F_142 ( V_2 , V_79 ) ;
F_143 ( V_2 , V_273 ) ;
if ( F_6 ( V_4 ) > 1 )
F_115 ( V_2 , V_4 , F_144 ( V_4 ) ) ;
return 0 ;
}
static inline int F_145 ( struct V_1 * V_2 , int V_274 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_246 ;
V_246 = V_274 - V_6 -> V_237 -> V_275 - sizeof( struct V_74 ) ;
if ( V_6 -> V_237 -> V_276 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_146 ( V_18 ) )
V_246 -= V_6 -> V_237 -> V_276 ;
}
if ( V_246 > V_8 -> V_59 . V_277 )
V_246 = V_8 -> V_59 . V_277 ;
V_246 -= V_6 -> V_278 ;
if ( V_246 < 48 )
V_246 = 48 ;
return V_246 ;
}
int F_147 ( struct V_1 * V_2 , int V_274 )
{
return F_145 ( V_2 , V_274 ) -
( F_3 ( V_2 ) -> V_78 - sizeof( struct V_74 ) ) ;
}
int F_148 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_279 ;
V_279 = V_19 +
V_8 -> V_78 +
V_6 -> V_278 +
V_6 -> V_237 -> V_275 ;
if ( V_6 -> V_237 -> V_276 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_146 ( V_18 ) )
V_279 += V_6 -> V_237 -> V_276 ;
}
return V_279 ;
}
void F_149 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_280 . V_281 = V_282 > 1 ;
V_6 -> V_280 . V_283 = V_8 -> V_59 . V_277 + sizeof( struct V_74 ) +
V_6 -> V_237 -> V_275 ;
V_6 -> V_280 . V_284 = F_148 ( V_2 , V_285 ) ;
V_6 -> V_280 . V_286 = 0 ;
}
unsigned int F_150 ( struct V_1 * V_2 , T_4 V_274 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_246 ;
if ( V_6 -> V_280 . V_283 > V_274 )
V_6 -> V_280 . V_283 = V_274 ;
V_246 = F_147 ( V_2 , V_274 ) ;
V_246 = F_151 ( V_8 , V_246 ) ;
V_6 -> V_287 = V_274 ;
if ( V_6 -> V_280 . V_281 )
V_246 = F_20 ( V_246 , F_147 ( V_2 , V_6 -> V_280 . V_284 ) ) ;
V_8 -> V_288 = V_246 ;
return V_246 ;
}
unsigned int F_58 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_246 ;
unsigned int V_289 ;
struct V_100 V_101 ;
struct V_142 * V_143 ;
V_246 = V_8 -> V_288 ;
if ( V_18 ) {
T_4 V_279 = F_152 ( V_18 ) ;
if ( V_279 != F_2 ( V_2 ) -> V_287 )
V_246 = F_150 ( V_2 , V_279 ) ;
}
V_289 = F_55 ( V_2 , NULL , & V_101 , & V_143 ) +
sizeof( struct V_74 ) ;
if ( V_289 != V_8 -> V_78 ) {
int V_22 = ( int ) V_289 - V_8 -> V_78 ;
V_246 -= V_22 ;
}
return V_246 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_10 >= V_8 -> V_27 ) {
V_8 -> V_32 = 0 ;
V_8 -> V_31 = V_23 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_32 )
V_8 -> V_32 = V_8 -> V_10 ;
if ( V_34 &&
( T_3 ) ( V_23 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 )
F_154 ( V_2 ) ;
}
}
static bool F_155 ( const struct V_7 * V_8 )
{
return F_106 ( V_8 -> V_290 , V_8 -> V_97 ) &&
! F_106 ( V_8 -> V_290 , V_8 -> V_11 ) ;
}
static void F_156 ( struct V_7 * V_8 , unsigned int V_246 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_79 < F_6 ( V_4 ) * V_246 )
V_8 -> V_290 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_157 ( bool V_291 , const struct V_7 * V_8 ,
int V_181 )
{
return V_291 &&
( ( V_181 & V_292 ) ||
( ! V_181 && V_8 -> V_10 && F_155 ( V_8 ) ) ) ;
}
static unsigned int F_158 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_246 ,
unsigned int V_293 ,
int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_291 , V_294 , V_231 , V_295 ;
V_231 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_295 = V_246 * V_293 ;
if ( F_50 ( V_295 <= V_231 && V_4 != F_159 ( V_2 ) ) )
return V_295 ;
V_294 = F_20 ( V_4 -> V_79 , V_231 ) ;
if ( V_295 <= V_294 )
return V_295 ;
V_291 = V_294 % V_246 ;
if ( F_157 ( V_291 != 0 , V_8 , V_181 ) )
return V_294 - V_291 ;
return V_294 ;
}
static inline unsigned int F_160 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_296 , V_26 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_96 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_296 = F_99 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_296 < V_26 )
return ( V_26 - V_296 ) ;
return 0 ;
}
static int F_161 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_246 )
{
int V_297 = F_6 ( V_4 ) ;
if ( ! V_297 || ( V_297 > 1 && F_144 ( V_4 ) != V_246 ) ) {
F_115 ( V_2 , V_4 , V_246 ) ;
V_297 = F_6 ( V_4 ) ;
}
return V_297 ;
}
static inline bool F_162 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_298 , int V_181 )
{
if ( V_181 & V_299 )
return true ;
if ( F_46 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_96 ) )
return true ;
if ( ! F_157 ( V_4 -> V_79 < V_298 , V_8 , V_181 ) )
return true ;
return false ;
}
static bool F_163 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_298 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_79 > V_298 )
V_12 = F_5 ( V_4 ) -> V_80 + V_298 ;
return ! F_106 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_164 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_298 , int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_300 ;
F_161 ( V_2 , V_4 , V_298 ) ;
if ( ! F_162 ( V_8 , V_4 , V_298 , V_181 ) )
return 0 ;
V_300 = F_160 ( V_8 , V_4 ) ;
if ( V_300 && ! F_163 ( V_8 , V_4 , V_298 ) )
V_300 = 0 ;
return V_300 ;
}
bool F_165 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_166 ( V_2 ) ;
return V_4 &&
F_164 ( V_2 , V_4 , F_58 ( V_2 ) ,
( F_167 ( V_2 , V_4 ) ?
V_8 -> V_181 : V_299 ) ) ;
}
static int F_168 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_79 ,
unsigned int V_246 , T_11 V_301 )
{
struct V_3 * V_259 ;
int V_262 = V_4 -> V_79 - V_79 ;
T_8 V_86 ;
if ( V_4 -> V_79 != V_4 -> V_272 )
return F_124 ( V_2 , V_4 , V_79 , V_246 ) ;
V_259 = F_128 ( V_2 , 0 , V_301 ) ;
if ( F_48 ( V_259 == NULL ) )
return - V_264 ;
V_2 -> V_245 += V_259 -> V_205 ;
F_114 ( V_2 , V_259 -> V_205 ) ;
V_259 -> V_205 += V_262 ;
V_4 -> V_205 -= V_262 ;
F_5 ( V_259 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_259 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_259 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_96 | V_265 ) ;
F_5 ( V_259 ) -> V_65 = V_86 ;
F_5 ( V_259 ) -> V_92 = 0 ;
V_259 -> V_89 = V_4 -> V_89 = V_90 ;
F_133 ( V_4 , V_259 , V_79 ) ;
F_115 ( V_2 , V_4 , V_246 ) ;
F_115 ( V_2 , V_259 , V_246 ) ;
F_112 ( V_259 ) ;
F_134 ( V_4 , V_259 , V_2 ) ;
return 0 ;
}
static bool F_169 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_302 , V_303 , V_304 , V_296 ;
int V_305 ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
goto V_306;
if ( V_6 -> V_307 != V_308 )
goto V_306;
if ( V_8 -> V_309 &&
( ( ( T_4 ) V_310 << 1 ) >> 1 ) - ( V_8 -> V_309 >> 1 ) > 1 )
goto V_306;
V_296 = F_99 ( V_8 ) ;
F_93 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_296 ) ) ;
V_302 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_303 = ( V_8 -> V_27 - V_296 ) * V_8 -> V_288 ;
V_304 = F_20 ( V_302 , V_303 ) ;
if ( V_304 >= F_30 (unsigned int, sk->sk_gso_max_size,
tp->xmit_size_goal_segs * tp->mss_cache) )
goto V_306;
if ( ( V_4 != F_159 ( V_2 ) ) && ( V_304 >= V_4 -> V_79 ) )
goto V_306;
V_305 = F_170 ( V_311 ) ;
if ( V_305 ) {
T_4 V_312 = F_20 ( V_8 -> V_313 , V_8 -> V_27 * V_8 -> V_288 ) ;
V_312 /= V_305 ;
if ( V_304 >= V_312 )
goto V_306;
} else {
if ( V_304 > F_171 ( V_8 ) * V_8 -> V_288 )
goto V_306;
}
if ( ! V_8 -> V_309 )
V_8 -> V_309 = 1 | ( V_310 << 1 ) ;
return true ;
V_306:
V_8 -> V_309 = 0 ;
return false ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_314 , * V_315 ;
int V_79 ;
int V_286 ;
int V_316 ;
int V_317 ;
int V_246 ;
if ( ! V_6 -> V_280 . V_281 ||
V_6 -> V_280 . V_286 ||
F_2 ( V_2 ) -> V_307 != V_308 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_173 || V_8 -> V_59 . V_125 )
return - 1 ;
V_246 = F_58 ( V_2 ) ;
V_286 = 2 * V_8 -> V_288 ;
V_316 = V_286 + ( V_8 -> V_318 + 1 ) * V_8 -> V_288 ;
if ( V_286 > F_147 ( V_2 , V_6 -> V_280 . V_283 ) ) {
return - 1 ;
}
if ( V_8 -> V_244 - V_8 -> V_11 < V_316 )
return - 1 ;
if ( V_8 -> V_313 < V_316 )
return - 1 ;
if ( F_106 ( V_8 -> V_11 + V_316 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_99 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_99 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_314 = F_128 ( V_2 , V_286 , V_182 ) ) == NULL )
return - 1 ;
V_2 -> V_245 += V_314 -> V_205 ;
F_114 ( V_2 , V_314 -> V_205 ) ;
V_4 = F_166 ( V_2 ) ;
F_5 ( V_314 ) -> V_80 = F_5 ( V_4 ) -> V_80 ;
F_5 ( V_314 ) -> V_12 = F_5 ( V_4 ) -> V_80 + V_286 ;
F_5 ( V_314 ) -> V_65 = V_239 ;
F_5 ( V_314 ) -> V_92 = 0 ;
V_314 -> V_91 = 0 ;
V_314 -> V_89 = V_4 -> V_89 ;
F_173 ( V_314 , V_4 , V_2 ) ;
V_79 = 0 ;
F_174 (skb, next, sk) {
V_317 = F_30 ( int , V_4 -> V_79 , V_286 - V_79 ) ;
if ( V_314 -> V_89 )
F_175 ( V_4 , 0 , F_130 ( V_314 , V_317 ) , V_317 ) ;
else
V_314 -> V_91 = F_176 ( V_4 , 0 ,
F_130 ( V_314 , V_317 ) ,
V_317 , V_314 -> V_91 ) ;
if ( V_4 -> V_79 <= V_317 ) {
F_5 ( V_314 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_177 ( V_4 , V_2 ) ;
F_178 ( V_2 , V_4 ) ;
} else {
F_5 ( V_314 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_96 | V_265 ) ;
if ( ! F_43 ( V_4 ) -> V_266 ) {
F_179 ( V_4 , V_317 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_180 ( V_4 -> V_183 ,
V_4 -> V_79 , 0 ) ;
} else {
F_135 ( V_4 , V_317 ) ;
F_115 ( V_2 , V_4 , V_246 ) ;
}
F_5 ( V_4 ) -> V_80 += V_317 ;
}
V_79 += V_317 ;
if ( V_79 >= V_286 )
break;
}
F_161 ( V_2 , V_314 , V_314 -> V_79 ) ;
F_5 ( V_314 ) -> V_154 = V_23 ;
if ( ! F_92 ( V_2 , V_314 , 1 , V_182 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_314 ) ;
V_6 -> V_280 . V_286 = F_148 ( V_2 , V_314 -> V_79 ) ;
V_8 -> V_319 . V_320 = F_5 ( V_314 ) -> V_80 ;
V_8 -> V_319 . V_321 = F_5 ( V_314 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_57 ( struct V_1 * V_2 , unsigned int V_246 , int V_181 ,
int V_322 , T_11 V_301 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_297 , V_323 ;
int V_300 ;
int V_324 ;
V_323 = 0 ;
if ( ! V_322 ) {
V_324 = F_172 ( V_2 ) ;
if ( ! V_324 ) {
return false ;
} else if ( V_324 > 0 ) {
V_323 = 1 ;
}
}
while ( ( V_4 = F_166 ( V_2 ) ) ) {
unsigned int V_304 ;
V_297 = F_161 ( V_2 , V_4 , V_246 ) ;
F_93 ( ! V_297 ) ;
if ( F_48 ( V_8 -> V_325 ) && V_8 -> V_326 == V_327 )
goto V_325;
V_300 = F_160 ( V_8 , V_4 ) ;
if ( ! V_300 ) {
if ( V_322 == 2 )
V_300 = 1 ;
else
break;
}
if ( F_48 ( ! F_163 ( V_8 , V_4 , V_246 ) ) )
break;
if ( V_297 == 1 ) {
if ( F_48 ( ! F_162 ( V_8 , V_4 , V_246 ,
( F_167 ( V_2 , V_4 ) ?
V_181 : V_299 ) ) ) )
break;
} else {
if ( ! V_322 && F_169 ( V_2 , V_4 ) )
break;
}
V_304 = F_29 (unsigned int, sysctl_tcp_limit_output_bytes,
sk->sk_pacing_rate >> 10 ) ;
if ( F_181 ( & V_2 -> V_206 ) > V_304 ) {
F_69 ( V_204 , & V_8 -> V_193 ) ;
F_182 () ;
if ( F_181 ( & V_2 -> V_206 ) > V_304 )
break;
}
V_304 = V_246 ;
if ( V_297 > 1 && ! F_46 ( V_8 ) )
V_304 = F_158 ( V_2 , V_4 , V_246 ,
F_30 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ,
V_181 ) ;
if ( V_4 -> V_79 > V_304 &&
F_48 ( F_168 ( V_2 , V_4 , V_304 , V_246 , V_301 ) ) )
break;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_48 ( F_92 ( V_2 , V_4 , 1 , V_301 ) ) )
break;
V_325:
F_1 ( V_2 , V_4 ) ;
F_156 ( V_8 , V_246 , V_4 ) ;
V_323 += F_6 ( V_4 ) ;
if ( V_322 )
break;
}
if ( F_50 ( V_323 ) ) {
if ( F_183 ( V_2 ) )
V_8 -> V_328 += V_323 ;
if ( V_322 != 2 )
F_184 ( V_2 ) ;
F_153 ( V_2 ) ;
return false ;
}
return ( V_322 == 2 ) || ( ! V_8 -> V_10 && F_166 ( V_2 ) ) ;
}
bool F_184 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_329 , V_330 , V_331 ;
T_4 V_332 = F_185 ( V_8 -> V_333 >> 3 ) ;
if ( F_125 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_125 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_175 == V_334 )
return false ;
if ( V_6 -> V_13 != V_335 )
return false ;
if ( V_336 < 3 || ! V_8 -> V_333 || ! V_8 -> V_10 ||
! F_186 ( V_8 ) || F_2 ( V_2 ) -> V_307 != V_308 )
return false ;
if ( ( V_8 -> V_27 > F_99 ( V_8 ) ) &&
F_166 ( V_2 ) )
return false ;
V_329 = V_332 << 1 ;
if ( V_8 -> V_10 == 1 )
V_329 = F_29 ( T_4 , V_329 ,
( V_332 + ( V_332 >> 1 ) + V_337 ) ) ;
V_329 = F_29 ( T_4 , V_329 , F_187 ( 10 ) ) ;
V_330 = V_23 + V_329 ;
V_331 = ( T_4 ) F_2 ( V_2 ) -> V_338 ;
if ( ( T_3 ) ( V_330 - V_331 ) > 0 ) {
T_3 V_22 = V_331 - V_23 ;
if ( V_22 > 0 )
V_329 = V_22 ;
}
F_188 ( V_2 , V_15 , V_329 ,
V_339 ) ;
return true ;
}
void F_189 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_340 ;
int V_19 = F_58 ( V_2 ) ;
int V_213 = - 1 ;
if ( F_166 ( V_2 ) != NULL ) {
V_213 = F_57 ( V_2 , V_19 , V_341 , 2 , V_182 ) ;
goto V_342;
}
if ( V_8 -> V_343 )
goto V_342;
V_4 = F_159 ( V_2 ) ;
if ( F_125 ( ! V_4 ) )
goto V_342;
V_340 = F_6 ( V_4 ) ;
if ( F_125 ( ! V_340 ) )
goto V_342;
if ( ( V_340 > 1 ) && ( V_4 -> V_79 > ( V_340 - 1 ) * V_19 ) ) {
if ( F_48 ( F_124 ( V_2 , V_4 , ( V_340 - 1 ) * V_19 , V_19 ) ) )
goto V_342;
V_4 = F_159 ( V_2 ) ;
}
if ( F_125 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_342;
if ( V_4 -> V_79 > 0 )
V_213 = F_190 ( V_2 , V_4 ) ;
if ( F_50 ( ! V_213 ) )
V_8 -> V_343 = V_8 -> V_11 ;
V_342:
F_188 ( V_2 , V_335 ,
F_2 ( V_2 ) -> V_30 ,
V_339 ) ;
if ( F_50 ( ! V_213 ) )
F_191 ( F_9 ( V_2 ) ,
V_344 ) ;
}
void F_192 ( struct V_1 * V_2 , unsigned int V_298 ,
int V_181 )
{
if ( F_48 ( V_2 -> V_175 == V_345 ) )
return;
if ( F_57 ( V_2 , V_298 , V_181 , 0 ,
F_193 ( V_2 , V_182 ) ) )
F_194 ( V_2 ) ;
}
void F_195 ( struct V_1 * V_2 , unsigned int V_246 )
{
struct V_3 * V_4 = F_166 ( V_2 ) ;
F_93 ( ! V_4 || V_4 -> V_79 < V_246 ) ;
F_57 ( V_2 , V_246 , V_299 , 1 , V_2 -> V_346 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_347 ;
int V_348 = F_196 ( V_2 ) ;
int V_349 = F_197 ( V_2 ) ;
int V_350 = F_30 ( int , V_8 -> V_46 , V_349 ) ;
int V_231 ;
if ( V_19 > V_350 )
V_19 = V_350 ;
if ( V_348 < ( V_350 >> 1 ) ) {
V_6 -> V_35 . V_351 = 0 ;
if ( F_198 ( V_2 ) )
V_8 -> V_352 = F_20 ( V_8 -> V_352 ,
4U * V_8 -> V_20 ) ;
V_348 = F_199 ( V_348 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_348 < ( V_349 >> 4 ) || V_348 < V_19 )
return 0 ;
}
if ( V_348 > V_8 -> V_352 )
V_348 = V_8 -> V_352 ;
V_231 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_231 = V_348 ;
if ( ( ( V_231 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_231 )
V_231 = ( ( ( V_231 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_231 <= V_348 - V_19 || V_231 > V_348 )
V_231 = ( V_348 / V_19 ) * V_19 ;
else if ( V_19 == V_350 &&
V_348 > V_231 + ( V_350 >> 1 ) )
V_231 = V_348 ;
}
return V_231 ;
}
static void F_200 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_353 = F_201 ( V_2 , V_4 ) ;
int V_354 , V_355 ;
V_354 = V_4 -> V_79 ;
V_355 = V_353 -> V_79 ;
F_93 ( F_6 ( V_4 ) != 1 || F_6 ( V_353 ) != 1 ) ;
F_202 ( V_2 , V_353 , V_4 ) ;
F_177 ( V_353 , V_2 ) ;
F_203 ( V_353 , F_130 ( V_4 , V_355 ) ,
V_355 ) ;
if ( V_353 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_204 ( V_4 -> V_91 , V_353 -> V_91 , V_354 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_353 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_353 ) -> V_65 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_353 ) -> V_92 & V_356 ;
F_205 ( V_8 ) ;
if ( V_353 == V_8 -> V_357 )
V_8 -> V_357 = V_4 ;
F_121 ( V_2 , V_353 , F_6 ( V_353 ) ) ;
F_178 ( V_2 , V_353 ) ;
}
static bool F_206 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_43 ( V_4 ) -> V_266 != 0 )
return false ;
if ( F_95 ( V_4 ) )
return false ;
if ( V_4 == F_166 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_252 )
return false ;
return true ;
}
static void F_207 ( struct V_1 * V_2 , struct V_3 * V_358 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_358 , * V_359 ;
bool V_360 = true ;
if ( ! V_361 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
return;
F_174 (skb, tmp, sk) {
if ( ! F_206 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_79 ;
if ( V_360 ) {
V_360 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_79 > F_208 ( V_358 ) )
break;
if ( F_106 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_200 ( V_2 , V_358 ) ;
}
}
int F_190 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_298 ;
int V_213 ;
if ( V_6 -> V_280 . V_286 ) {
V_6 -> V_280 . V_286 = 0 ;
}
if ( F_181 ( & V_2 -> V_206 ) >
F_20 ( V_2 -> V_245 + ( V_2 -> V_245 >> 2 ) , V_2 -> V_362 ) )
return - V_363 ;
if ( F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_97 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_97 ) )
F_209 () ;
if ( F_141 ( V_2 , V_4 , V_8 -> V_97 - F_5 ( V_4 ) -> V_80 ) )
return - V_264 ;
}
if ( F_2 ( V_2 ) -> V_237 -> V_364 ( V_2 ) )
return - V_365 ;
V_298 = F_58 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_80 != V_8 -> V_97 )
return - V_363 ;
if ( V_4 -> V_79 > V_298 ) {
if ( F_124 ( V_2 , V_4 , V_298 , V_298 ) )
return - V_264 ;
} else {
int V_366 = F_6 ( V_4 ) ;
if ( F_48 ( V_366 > 1 ) ) {
if ( F_127 ( V_4 , V_182 ) )
return - V_264 ;
F_161 ( V_2 , V_4 , V_298 ) ;
F_121 ( V_2 , V_4 , V_366 - F_6 ( V_4 ) ) ;
}
}
F_207 ( V_2 , V_4 , V_298 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_48 ( ( V_367 && ( ( unsigned long ) V_4 -> V_183 & 3 ) ) ||
F_210 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_314 = F_211 ( V_4 , V_368 ,
V_182 ) ;
V_213 = V_314 ? F_92 ( V_2 , V_314 , 0 , V_182 ) :
- V_219 ;
} else {
V_213 = F_92 ( V_2 , V_4 , 1 , V_182 ) ;
}
if ( F_50 ( ! V_213 ) ) {
F_5 ( V_4 ) -> V_92 |= V_356 ;
F_212 ( F_9 ( V_2 ) , V_369 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
F_191 ( F_9 ( V_2 ) , V_370 ) ;
V_8 -> V_371 ++ ;
}
return V_213 ;
}
int F_213 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_213 = F_190 ( V_2 , V_4 ) ;
if ( V_213 == 0 ) {
#if V_372 > 0
if ( F_5 ( V_4 ) -> V_92 & V_253 ) {
F_214 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_254 )
V_8 -> V_373 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_92 |= V_374 ;
V_8 -> V_254 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_375 )
V_8 -> V_375 = F_5 ( V_4 ) -> V_154 ;
V_8 -> V_376 += F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_229 = V_8 -> V_11 ;
} else {
F_191 ( F_9 ( V_2 ) , V_377 ) ;
}
return V_213 ;
}
static bool F_215 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_307 != V_378 )
return false ;
if ( F_119 ( V_8 ) )
return false ;
if ( F_165 ( V_2 ) )
return false ;
return true ;
}
void F_216 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_379 = NULL ;
T_4 V_380 ;
int V_381 ;
int V_382 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_256 )
V_8 -> V_383 = V_8 -> V_97 ;
if ( V_8 -> V_357 ) {
V_4 = V_8 -> V_357 ;
V_380 = F_5 ( V_4 ) -> V_12 ;
if ( F_106 ( V_380 , V_8 -> V_383 ) )
V_380 = V_8 -> V_383 ;
} else {
V_4 = F_217 ( V_2 ) ;
V_380 = V_8 -> V_97 ;
}
F_218 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
if ( V_4 == F_166 ( V_2 ) )
break;
if ( V_379 == NULL )
V_8 -> V_357 = V_4 ;
if ( F_99 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_382 ) {
V_384:
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_120 ( V_8 ) ) )
break;
V_381 = V_385 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_383 ) ) {
V_8 -> V_383 = V_380 ;
if ( ! F_215 ( V_2 ) )
break;
if ( V_379 != NULL ) {
V_4 = V_379 ;
V_379 = NULL ;
}
V_382 = 1 ;
goto V_384;
} else if ( ! ( V_92 & V_255 ) ) {
if ( V_379 == NULL && ! ( V_92 & ( V_253 | V_252 ) ) )
V_379 = V_4 ;
continue;
} else {
V_380 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_307 != V_386 )
V_381 = V_387 ;
else
V_381 = V_388 ;
}
if ( V_92 & ( V_252 | V_253 ) )
continue;
if ( F_213 ( V_2 , V_4 ) )
return;
F_191 ( F_9 ( V_2 ) , V_381 ) ;
if ( F_183 ( V_2 ) )
V_8 -> V_328 += F_6 ( V_4 ) ;
if ( V_4 == F_217 ( V_2 ) )
F_188 ( V_2 , V_335 ,
F_2 ( V_2 ) -> V_30 ,
V_339 ) ;
}
}
void F_219 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_159 ( V_2 ) ;
int V_246 ;
V_246 = F_58 ( V_2 ) ;
if ( F_166 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_65 |= V_96 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_244 ++ ;
} else {
for (; ; ) {
V_4 = F_220 ( V_368 ,
V_2 -> V_346 ) ;
if ( V_4 )
break;
F_221 () ;
}
F_222 ( V_4 , V_368 ) ;
F_45 ( V_4 , V_8 -> V_244 ,
V_239 | V_96 ) ;
F_111 ( V_2 , V_4 ) ;
}
F_192 ( V_2 , V_246 , V_341 ) ;
}
void F_223 ( struct V_1 * V_2 , T_11 V_389 )
{
struct V_3 * V_4 ;
V_4 = F_224 ( V_368 , V_389 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_390 ) ;
return;
}
F_222 ( V_4 , V_368 ) ;
F_45 ( V_4 , F_10 ( V_2 ) ,
V_239 | V_391 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_92 ( V_2 , V_4 , 0 , V_389 ) )
F_34 ( F_9 ( V_2 ) , V_390 ) ;
F_212 ( F_9 ( V_2 ) , V_392 ) ;
}
int F_225 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_217 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_65 & V_95 ) ) {
F_226 ( L_2 , V_393 ) ;
return - V_394 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_239 ) ) {
if ( F_95 ( V_4 ) ) {
struct V_3 * V_314 = F_227 ( V_4 , V_182 ) ;
if ( V_314 == NULL )
return - V_264 ;
F_177 ( V_4 , V_2 ) ;
F_112 ( V_314 ) ;
F_228 ( V_2 , V_314 ) ;
F_178 ( V_2 , V_4 ) ;
V_2 -> V_245 += V_314 -> V_205 ;
F_114 ( V_2 , V_314 -> V_205 ) ;
V_4 = V_314 ;
}
F_5 ( V_4 ) -> V_65 |= V_239 ;
F_36 ( F_3 ( V_2 ) , V_4 ) ;
}
F_5 ( V_4 ) -> V_154 = V_23 ;
return F_92 ( V_2 , V_4 , 1 , V_182 ) ;
}
struct V_3 * F_229 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_72 * V_73 ,
struct V_134 * V_135 )
{
struct V_100 V_101 ;
struct V_165 * V_166 = F_39 ( V_73 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_74 * V_75 ;
struct V_3 * V_4 ;
struct V_142 * V_143 ;
int V_212 ;
int V_19 ;
V_4 = F_230 ( V_2 , V_368 , 1 , V_182 ) ;
if ( F_48 ( ! V_4 ) ) {
F_231 ( V_18 ) ;
return NULL ;
}
F_222 ( V_4 , V_368 ) ;
F_232 ( V_4 , V_18 ) ;
F_233 ( V_4 , V_2 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_395 && V_8 -> V_59 . V_395 < V_19 )
V_19 = V_8 -> V_59 . V_395 ;
if ( V_73 -> V_45 == 0 ) {
T_5 V_48 ;
V_73 -> V_46 = V_8 -> V_46 ? : F_23 ( V_18 , V_396 ) ;
if ( V_2 -> V_397 & V_398 &&
( V_73 -> V_46 > F_197 ( V_2 ) || V_73 -> V_46 == 0 ) )
V_73 -> V_46 = F_197 ( V_2 ) ;
F_28 ( F_197 ( V_2 ) ,
V_19 - ( V_166 -> V_167 ? V_157 : 0 ) ,
& V_73 -> V_45 ,
& V_73 -> V_46 ,
V_166 -> V_47 ,
& V_48 ,
F_23 ( V_18 , V_399 ) ) ;
V_166 -> V_48 = V_48 ;
}
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
#ifdef F_234
if ( F_48 ( V_73 -> V_400 ) )
F_5 ( V_4 ) -> V_154 = F_235 ( V_73 ) ;
else
#endif
F_5 ( V_4 ) -> V_154 = V_23 ;
V_212 = F_53 ( V_2 , V_73 , V_19 , V_4 , & V_101 , & V_143 ,
V_135 ) + sizeof( * V_75 ) ;
F_101 ( V_4 , V_212 ) ;
F_102 ( V_4 ) ;
V_75 = F_42 ( V_4 ) ;
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 -> V_401 = 1 ;
V_75 -> V_402 = 1 ;
F_38 ( V_73 , V_75 ) ;
V_75 -> V_225 = F_105 ( V_166 -> V_403 ) ;
V_75 -> V_227 = V_166 -> V_404 ;
F_45 ( V_4 , F_54 ( V_73 ) -> V_405 ,
V_95 | V_239 ) ;
V_75 -> V_80 = F_49 ( F_5 ( V_4 ) -> V_80 ) ;
V_75 -> V_229 = F_49 ( F_54 ( V_73 ) -> V_61 ) ;
V_75 -> V_231 = F_105 ( F_20 ( V_73 -> V_45 , 65535U ) ) ;
F_47 ( ( T_9 * ) ( V_75 + 1 ) , V_8 , & V_101 ) ;
V_75 -> V_406 = ( V_212 >> 2 ) ;
F_236 ( F_9 ( V_2 ) , V_240 ) ;
#ifdef F_52
if ( V_143 ) {
F_54 ( V_73 ) -> V_149 -> V_236 ( V_101 . V_107 ,
V_143 , NULL , V_73 , V_4 ) ;
}
#endif
return V_4 ;
}
static void F_237 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_48 ;
V_8 -> V_78 = sizeof( struct V_74 ) +
( V_153 ? V_157 : 0 ) ;
#ifdef F_52
if ( V_8 -> V_149 -> V_150 ( V_2 , V_2 ) != NULL )
V_8 -> V_78 += V_151 ;
#endif
if ( V_8 -> V_59 . V_395 )
V_8 -> V_59 . V_277 = V_8 -> V_59 . V_395 ;
V_8 -> V_407 = 0 ;
F_149 ( V_2 ) ;
F_150 ( V_2 , F_152 ( V_18 ) ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_396 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_395 && V_8 -> V_59 . V_395 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_395 ;
F_238 ( V_2 ) ;
if ( V_2 -> V_397 & V_398 &&
( V_8 -> V_46 > F_197 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_197 ( V_2 ) ;
F_28 ( F_197 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_408 ? V_8 -> V_78 - sizeof( struct V_74 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_158 ,
& V_48 ,
F_23 ( V_18 , V_399 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_352 = V_8 -> V_45 ;
V_2 -> V_409 = 0 ;
F_239 ( V_2 , V_410 ) ;
V_8 -> V_313 = 0 ;
F_240 ( V_8 , 0 ) ;
V_8 -> V_97 = V_8 -> V_244 ;
V_8 -> V_290 = V_8 -> V_244 ;
V_8 -> V_98 = V_8 -> V_244 ;
V_8 -> V_11 = V_8 -> V_244 ;
if ( F_50 ( ! V_8 -> V_325 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_411 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_412 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_413 ;
F_2 ( V_2 ) -> V_414 = 0 ;
F_241 ( V_8 ) ;
}
static void F_242 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_169 * V_170 = F_5 ( V_4 ) ;
V_170 -> V_12 += V_4 -> V_79 ;
F_112 ( V_4 ) ;
F_243 ( V_2 , V_4 ) ;
V_2 -> V_245 += V_4 -> V_205 ;
F_114 ( V_2 , V_4 -> V_205 ) ;
V_8 -> V_244 = V_170 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_244 ( struct V_1 * V_2 , struct V_3 * V_401 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_415 = V_8 -> V_148 ;
int V_416 = 0 , V_50 , V_202 , V_213 = 0 , V_417 = V_415 -> V_183 -> V_418 ;
struct V_3 * V_419 = NULL , * V_183 ;
unsigned long V_420 = 0 ;
V_8 -> V_59 . V_277 = V_8 -> V_20 ;
F_245 ( V_2 , & V_8 -> V_59 . V_277 , & V_415 -> V_162 ,
& V_416 , & V_420 ) ;
if ( V_416 > 1 &&
F_246 ( V_310 , V_420 + ( 60 * V_421 << V_416 ) ) ) {
V_415 -> V_162 . V_79 = - 1 ;
goto V_422;
}
if ( V_423 & V_424 )
V_415 -> V_162 . V_79 = - 1 ;
else if ( V_415 -> V_162 . V_79 <= 0 )
goto V_422;
if ( V_8 -> V_59 . V_395 && V_8 -> V_59 . V_395 < V_8 -> V_59 . V_277 )
V_8 -> V_59 . V_277 = V_8 -> V_59 . V_395 ;
V_50 = F_145 ( V_2 , F_2 ( V_2 ) -> V_287 ) -
V_145 ;
V_50 = F_30 ( V_425 , V_50 , V_415 -> V_171 ) ;
V_50 = F_30 ( V_425 , V_50 , F_247 ( V_368 ) ) ;
V_419 = F_248 ( V_401 , V_368 , V_50 ,
V_2 -> V_346 ) ;
if ( V_419 == NULL )
goto V_422;
for ( V_202 = 0 ; V_202 < V_417 && V_419 -> V_79 < V_50 ; ++ V_202 ) {
struct V_426 * V_427 = & V_415 -> V_183 -> V_428 [ V_202 ] ;
unsigned char T_12 * V_429 = V_427 -> V_430 ;
int V_79 = V_427 -> V_431 ;
if ( V_419 -> V_79 + V_79 > V_50 )
V_79 = V_50 - V_419 -> V_79 ;
else if ( V_202 + 1 == V_417 )
V_415 -> V_183 = NULL ;
if ( F_249 ( V_419 , V_429 , V_79 ) )
goto V_422;
}
V_183 = F_96 ( V_419 , V_2 -> V_346 ) ;
if ( V_183 == NULL )
goto V_422;
F_5 ( V_183 ) -> V_80 ++ ;
F_5 ( V_183 ) -> V_65 &= ~ V_95 ;
F_5 ( V_183 ) -> V_65 = ( V_239 | V_265 ) ;
F_242 ( V_2 , V_183 ) ;
V_415 -> V_432 = V_183 -> V_79 ;
F_94 ( & V_401 -> V_215 ) ;
V_183 -> V_215 = V_401 -> V_215 ;
if ( F_92 ( V_2 , V_419 , 0 , V_2 -> V_346 ) == 0 ) {
V_8 -> V_419 = ( V_415 -> V_432 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_433;
}
V_419 = NULL ;
V_422:
if ( V_415 -> V_162 . V_79 > 0 )
V_415 -> V_162 . V_79 = 0 ;
V_213 = F_92 ( V_2 , V_401 , 1 , V_2 -> V_346 ) ;
if ( V_213 )
V_8 -> V_164 = 0 ;
F_250 ( V_419 ) ;
V_433:
V_415 -> V_162 . V_79 = - 1 ;
return V_213 ;
}
int F_251 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_259 ;
int V_213 ;
F_237 ( V_2 ) ;
if ( F_48 ( V_8 -> V_325 ) ) {
F_252 ( V_2 , NULL ) ;
return 0 ;
}
V_259 = F_220 ( V_368 + 15 , V_2 -> V_346 ) ;
if ( F_48 ( V_259 == NULL ) )
return - V_219 ;
F_222 ( V_259 , V_368 ) ;
F_45 ( V_259 , V_8 -> V_244 ++ , V_95 ) ;
V_8 -> V_375 = F_5 ( V_259 ) -> V_154 = V_23 ;
F_242 ( V_2 , V_259 ) ;
F_37 ( V_2 , V_259 ) ;
V_213 = V_8 -> V_148 ? F_244 ( V_2 , V_259 ) :
F_92 ( V_2 , V_259 , 1 , V_2 -> V_346 ) ;
if ( V_213 == - V_434 )
return V_213 ;
V_8 -> V_11 = V_8 -> V_244 ;
V_8 -> V_435 = V_8 -> V_244 ;
F_212 ( F_9 ( V_2 ) , V_436 ) ;
F_188 ( V_2 , V_335 ,
F_2 ( V_2 ) -> V_30 , V_339 ) ;
return 0 ;
}
void F_253 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_329 ;
if ( V_37 > V_437 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_438 = V_421 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_439 & V_440 ) )
V_438 = V_337 ;
if ( V_8 -> V_333 ) {
int V_332 = F_29 ( int , F_185 ( V_8 -> V_333 >> 3 ) ,
V_437 ) ;
if ( V_332 < V_438 )
V_438 = V_332 ;
}
V_37 = F_20 ( V_37 , V_438 ) ;
}
V_329 = V_310 + V_37 ;
if ( V_6 -> V_35 . V_439 & V_441 ) {
if ( V_6 -> V_35 . V_442 ||
F_254 ( V_6 -> V_35 . V_329 , V_310 + ( V_37 >> 2 ) ) ) {
F_255 ( V_2 ) ;
return;
}
if ( ! F_246 ( V_329 , V_6 -> V_35 . V_329 ) )
V_329 = V_6 -> V_35 . V_329 ;
}
V_6 -> V_35 . V_439 |= V_443 | V_441 ;
V_6 -> V_35 . V_329 = V_329 ;
F_256 ( V_2 , & V_6 -> V_444 , V_329 ) ;
}
void F_255 ( struct V_1 * V_2 )
{
struct V_3 * V_259 ;
if ( V_2 -> V_175 == V_345 )
return;
V_259 = F_224 ( V_368 , F_193 ( V_2 , V_182 ) ) ;
if ( V_259 == NULL ) {
F_257 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_445 ;
F_188 ( V_2 , V_41 ,
V_337 , V_339 ) ;
return;
}
F_222 ( V_259 , V_368 ) ;
F_45 ( V_259 , F_10 ( V_2 ) , V_239 ) ;
F_5 ( V_259 ) -> V_154 = V_23 ;
F_92 ( V_2 , V_259 , 0 , F_193 ( V_2 , V_182 ) ) ;
}
static int F_258 ( struct V_1 * V_2 , int V_446 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_224 ( V_368 , F_193 ( V_2 , V_182 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_222 ( V_4 , V_368 ) ;
F_45 ( V_4 , V_8 -> V_97 - ! V_446 , V_239 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
return F_92 ( V_2 , V_4 , 0 , V_182 ) ;
}
void F_259 ( struct V_1 * V_2 )
{
if ( V_2 -> V_175 == V_447 ) {
F_3 ( V_2 ) -> V_448 = F_3 ( V_2 ) -> V_61 - 1 ;
F_258 ( V_2 , 0 ) ;
}
}
int F_260 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_175 == V_345 )
return - 1 ;
if ( ( V_4 = F_166 ( V_2 ) ) != NULL &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) ) {
int V_213 ;
unsigned int V_19 = F_58 ( V_2 ) ;
unsigned int V_449 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
if ( F_11 ( V_8 -> V_435 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_435 = F_5 ( V_4 ) -> V_12 ;
if ( V_449 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_80 ||
V_4 -> V_79 > V_19 ) {
V_449 = F_20 ( V_449 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_265 ;
if ( F_124 ( V_2 , V_4 , V_449 , V_19 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_115 ( V_2 , V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_265 ;
F_5 ( V_4 ) -> V_154 = V_23 ;
V_213 = F_92 ( V_2 , V_4 , 1 , V_182 ) ;
if ( ! V_213 )
F_1 ( V_2 , V_4 ) ;
return V_213 ;
} else {
if ( F_261 ( V_8 -> V_98 , V_8 -> V_97 + 1 , V_8 -> V_97 + 0xFFFF ) )
F_258 ( V_2 , 1 ) ;
return F_258 ( V_2 , 0 ) ;
}
}
void F_262 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_213 ;
V_213 = F_260 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_166 ( V_2 ) ) {
V_6 -> V_450 = 0 ;
V_6 -> V_451 = 0 ;
return;
}
if ( V_213 <= 0 ) {
if ( V_6 -> V_451 < V_452 )
V_6 -> V_451 ++ ;
V_6 -> V_450 ++ ;
F_188 ( V_2 , V_453 ,
F_20 ( V_6 -> V_30 << V_6 -> V_451 , V_339 ) ,
V_339 ) ;
} else {
if ( ! V_6 -> V_450 )
V_6 -> V_450 = 1 ;
F_188 ( V_2 , V_453 ,
F_20 ( V_6 -> V_30 << V_6 -> V_451 ,
V_454 ) ,
V_339 ) ;
}
}
