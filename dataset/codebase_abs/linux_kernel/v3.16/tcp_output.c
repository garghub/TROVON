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
if ( V_135 != NULL && V_135 -> V_79 >= 0 ) {
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
F_94 ( & V_4 -> V_214 ) ;
if ( F_48 ( F_95 ( V_4 ) ) )
V_4 = F_96 ( V_4 , V_208 ) ;
else
V_4 = F_97 ( V_4 , V_208 ) ;
if ( F_48 ( ! V_4 ) )
return - V_215 ;
V_4 -> V_216 . V_217 = 0 ;
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
F_18 ( V_2 , V_218 ) ;
V_4 -> V_219 = F_100 ( V_2 ) == 0 ;
F_101 ( V_4 , V_212 ) ;
F_102 ( V_4 ) ;
F_103 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_220 = F_84 ;
F_104 ( V_4 -> V_205 , & V_2 -> V_206 ) ;
V_75 = F_42 ( V_4 ) ;
V_75 -> V_221 = V_210 -> V_222 ;
V_75 -> V_223 = V_210 -> V_224 ;
V_75 -> V_80 = F_49 ( V_170 -> V_80 ) ;
V_75 -> V_225 = F_49 ( V_8 -> V_61 ) ;
* ( ( ( V_226 * ) V_75 ) + 6 ) = F_105 ( ( ( V_212 >> 2 ) << 12 ) |
V_170 -> V_65 ) ;
if ( F_48 ( V_170 -> V_65 & V_95 ) ) {
V_75 -> V_227 = F_105 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_75 -> V_227 = F_105 ( F_31 ( V_2 ) ) ;
}
V_75 -> V_228 = 0 ;
V_75 -> V_229 = 0 ;
if ( F_48 ( F_46 ( V_8 ) && F_11 ( V_170 -> V_80 , V_8 -> V_98 ) ) ) {
if ( F_11 ( V_8 -> V_98 , V_170 -> V_80 + 0x10000 ) ) {
V_75 -> V_229 = F_105 ( V_8 -> V_98 - V_170 -> V_80 ) ;
V_75 -> V_230 = 1 ;
} else if ( F_106 ( V_170 -> V_80 + 0xFFFF , V_8 -> V_11 ) ) {
V_75 -> V_229 = F_105 ( 0xFFFF ) ;
V_75 -> V_230 = 1 ;
}
}
F_47 ( ( T_9 * ) ( V_75 + 1 ) , V_8 , & V_101 ) ;
if ( F_50 ( ( V_170 -> V_65 & V_95 ) == 0 ) )
F_40 ( V_2 , V_4 , V_212 ) ;
#ifdef F_52
if ( V_143 ) {
F_107 ( V_2 , V_231 ) ;
V_8 -> V_149 -> V_232 ( V_101 . V_107 ,
V_143 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_233 -> V_234 ( V_2 , V_4 ) ;
if ( F_50 ( V_170 -> V_65 & V_235 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_79 != V_212 )
F_22 ( V_8 , V_2 ) ;
if ( F_106 ( V_170 -> V_12 , V_8 -> V_11 ) || V_170 -> V_80 == V_170 -> V_12 )
F_108 ( F_9 ( V_2 ) , V_236 ,
F_6 ( V_4 ) ) ;
V_213 = V_6 -> V_233 -> V_237 ( V_2 , V_4 , & V_210 -> V_238 . V_239 ) ;
if ( F_50 ( V_213 <= 0 ) )
return V_213 ;
F_109 ( V_2 , 1 ) ;
return F_110 ( V_213 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_240 = F_5 ( V_4 ) -> V_12 ;
F_112 ( V_4 ) ;
F_113 ( V_2 , V_4 ) ;
V_2 -> V_241 += V_4 -> V_205 ;
F_114 ( V_2 , V_4 -> V_205 ) ;
}
static void F_115 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_242 )
{
struct V_87 * V_88 = F_43 ( V_4 ) ;
F_116 ( F_95 ( V_4 ) ) ;
if ( V_4 -> V_79 <= V_242 || V_4 -> V_89 == V_243 ) {
V_88 -> V_93 = 1 ;
V_88 -> V_94 = 0 ;
V_88 -> V_83 = 0 ;
} else {
V_88 -> V_93 = F_117 ( V_4 -> V_79 , V_242 ) ;
V_88 -> V_94 = V_242 ;
V_88 -> V_83 = V_2 -> V_244 ;
}
}
static void F_118 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_245 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_246 || F_119 ( V_8 ) )
return;
if ( F_106 ( F_120 ( V_8 ) , F_5 ( V_4 ) -> V_80 ) )
V_8 -> V_247 -= V_245 ;
}
static void F_121 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_245 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_245 ;
if ( F_5 ( V_4 ) -> V_92 & V_248 )
V_8 -> V_246 -= V_245 ;
if ( F_5 ( V_4 ) -> V_92 & V_249 )
V_8 -> V_250 -= V_245 ;
if ( F_5 ( V_4 ) -> V_92 & V_251 )
V_8 -> V_252 -= V_245 ;
if ( F_119 ( V_8 ) && V_245 > 0 )
V_8 -> V_246 -= F_30 ( T_4 , V_8 -> V_246 , V_245 ) ;
F_118 ( V_2 , V_4 , V_245 ) ;
if ( V_8 -> V_253 &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_5 ( V_8 -> V_253 ) -> V_80 ) &&
( F_122 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_248 ) ) )
V_8 -> V_254 -= V_245 ;
F_123 ( V_8 ) ;
}
int F_124 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 ,
unsigned int V_242 , T_11 V_255 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_256 ;
int V_257 , V_258 ;
int V_259 ;
T_8 V_86 ;
if ( F_125 ( V_79 > V_4 -> V_79 ) )
return - V_260 ;
V_257 = F_126 ( V_4 ) - V_79 ;
if ( V_257 < 0 )
V_257 = 0 ;
if ( F_127 ( V_4 , V_255 ) )
return - V_261 ;
V_256 = F_128 ( V_2 , V_257 , V_255 ) ;
if ( V_256 == NULL )
return - V_261 ;
V_2 -> V_241 += V_256 -> V_205 ;
F_114 ( V_2 , V_256 -> V_205 ) ;
V_259 = V_4 -> V_79 - V_79 - V_257 ;
V_256 -> V_205 += V_259 ;
V_4 -> V_205 -= V_259 ;
F_5 ( V_256 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_256 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_256 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_96 | V_262 ) ;
F_5 ( V_256 ) -> V_65 = V_86 ;
F_5 ( V_256 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
if ( ! F_43 ( V_4 ) -> V_263 && V_4 -> V_89 != V_90 ) {
V_256 -> V_91 = F_129 ( V_4 -> V_183 + V_79 ,
F_130 ( V_256 , V_257 ) ,
V_257 , 0 ) ;
F_131 ( V_4 , V_79 ) ;
V_4 -> V_91 = F_132 ( V_4 -> V_91 , V_256 -> V_91 , V_79 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_133 ( V_4 , V_256 , V_79 ) ;
}
V_256 -> V_89 = V_4 -> V_89 ;
F_5 ( V_256 ) -> V_154 = F_5 ( V_4 ) -> V_154 ;
V_256 -> V_216 = V_4 -> V_216 ;
V_258 = F_6 ( V_4 ) ;
F_115 ( V_2 , V_4 , V_242 ) ;
F_115 ( V_2 , V_256 , V_242 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_256 ) -> V_12 ) ) {
int V_264 = V_258 - F_6 ( V_4 ) -
F_6 ( V_256 ) ;
if ( V_264 )
F_121 ( V_2 , V_4 , V_264 ) ;
}
F_112 ( V_256 ) ;
F_134 ( V_4 , V_256 , V_2 ) ;
return 0 ;
}
static void F_135 ( struct V_3 * V_4 , int V_79 )
{
struct V_87 * V_88 ;
int V_202 , V_265 , V_266 ;
V_266 = F_30 ( int , V_79 , F_126 ( V_4 ) ) ;
if ( V_266 ) {
F_136 ( V_4 , V_266 ) ;
V_79 -= V_266 ;
if ( ! V_79 )
return;
}
V_266 = V_79 ;
V_265 = 0 ;
V_88 = F_43 ( V_4 ) ;
for ( V_202 = 0 ; V_202 < V_88 -> V_263 ; V_202 ++ ) {
int V_171 = F_137 ( & V_88 -> V_267 [ V_202 ] ) ;
if ( V_171 <= V_266 ) {
F_138 ( V_4 , V_202 ) ;
V_266 -= V_171 ;
} else {
V_88 -> V_267 [ V_265 ] = V_88 -> V_267 [ V_202 ] ;
if ( V_266 ) {
V_88 -> V_267 [ V_265 ] . V_268 += V_266 ;
F_139 ( & V_88 -> V_267 [ V_265 ] , V_266 ) ;
V_266 = 0 ;
}
V_265 ++ ;
}
}
V_88 -> V_263 = V_265 ;
F_140 ( V_4 ) ;
V_4 -> V_269 -= V_79 ;
V_4 -> V_79 = V_4 -> V_269 ;
}
int F_141 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 )
{
if ( F_127 ( V_4 , V_182 ) )
return - V_261 ;
F_135 ( V_4 , V_79 ) ;
F_5 ( V_4 ) -> V_80 += V_79 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_205 -= V_79 ;
V_2 -> V_241 -= V_79 ;
F_142 ( V_2 , V_79 ) ;
F_143 ( V_2 , V_270 ) ;
if ( F_6 ( V_4 ) > 1 )
F_115 ( V_2 , V_4 , F_144 ( V_4 ) ) ;
return 0 ;
}
static inline int F_145 ( struct V_1 * V_2 , int V_271 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_242 ;
V_242 = V_271 - V_6 -> V_233 -> V_272 - sizeof( struct V_74 ) ;
if ( V_6 -> V_233 -> V_273 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_146 ( V_18 ) )
V_242 -= V_6 -> V_233 -> V_273 ;
}
if ( V_242 > V_8 -> V_59 . V_274 )
V_242 = V_8 -> V_59 . V_274 ;
V_242 -= V_6 -> V_275 ;
if ( V_242 < 48 )
V_242 = 48 ;
return V_242 ;
}
int F_147 ( struct V_1 * V_2 , int V_271 )
{
return F_145 ( V_2 , V_271 ) -
( F_3 ( V_2 ) -> V_78 - sizeof( struct V_74 ) ) ;
}
int F_148 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_276 ;
V_276 = V_19 +
V_8 -> V_78 +
V_6 -> V_275 +
V_6 -> V_233 -> V_272 ;
if ( V_6 -> V_233 -> V_273 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_146 ( V_18 ) )
V_276 += V_6 -> V_233 -> V_273 ;
}
return V_276 ;
}
void F_149 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_277 . V_278 = V_279 > 1 ;
V_6 -> V_277 . V_280 = V_8 -> V_59 . V_274 + sizeof( struct V_74 ) +
V_6 -> V_233 -> V_272 ;
V_6 -> V_277 . V_281 = F_148 ( V_2 , V_282 ) ;
V_6 -> V_277 . V_283 = 0 ;
}
unsigned int F_150 ( struct V_1 * V_2 , T_4 V_271 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_242 ;
if ( V_6 -> V_277 . V_280 > V_271 )
V_6 -> V_277 . V_280 = V_271 ;
V_242 = F_147 ( V_2 , V_271 ) ;
V_242 = F_151 ( V_8 , V_242 ) ;
V_6 -> V_284 = V_271 ;
if ( V_6 -> V_277 . V_278 )
V_242 = F_20 ( V_242 , F_147 ( V_2 , V_6 -> V_277 . V_281 ) ) ;
V_8 -> V_285 = V_242 ;
return V_242 ;
}
unsigned int F_58 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_242 ;
unsigned int V_286 ;
struct V_100 V_101 ;
struct V_142 * V_143 ;
V_242 = V_8 -> V_285 ;
if ( V_18 ) {
T_4 V_276 = F_152 ( V_18 ) ;
if ( V_276 != F_2 ( V_2 ) -> V_284 )
V_242 = F_150 ( V_2 , V_276 ) ;
}
V_286 = F_55 ( V_2 , NULL , & V_101 , & V_143 ) +
sizeof( struct V_74 ) ;
if ( V_286 != V_8 -> V_78 ) {
int V_22 = ( int ) V_286 - V_8 -> V_78 ;
V_242 -= V_22 ;
}
return V_242 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_287 == V_288 &&
V_2 -> V_289 && ! F_154 ( V_290 , & V_2 -> V_289 -> V_86 ) ) {
T_4 V_291 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_292 = F_21 ( V_8 -> V_32 , V_291 ) ;
if ( V_292 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_292 ) >> 1 ;
}
V_8 -> V_32 = 0 ;
}
V_8 -> V_31 = V_23 ;
}
static void F_155 ( struct V_1 * V_2 , bool V_293 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_97 , V_8 -> V_294 ) ||
V_8 -> V_10 > V_8 -> V_295 ) {
V_8 -> V_295 = V_8 -> V_10 ;
V_8 -> V_294 = V_8 -> V_11 ;
V_8 -> V_293 = V_293 ;
}
if ( F_156 ( V_2 ) ) {
V_8 -> V_32 = 0 ;
V_8 -> V_31 = V_23 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_32 )
V_8 -> V_32 = V_8 -> V_10 ;
if ( V_34 &&
( T_3 ) ( V_23 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 )
F_153 ( V_2 ) ;
}
}
static bool F_157 ( const struct V_7 * V_8 )
{
return F_106 ( V_8 -> V_296 , V_8 -> V_97 ) &&
! F_106 ( V_8 -> V_296 , V_8 -> V_11 ) ;
}
static void F_158 ( struct V_7 * V_8 , unsigned int V_242 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_79 < F_6 ( V_4 ) * V_242 )
V_8 -> V_296 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_159 ( bool V_297 , const struct V_7 * V_8 ,
int V_181 )
{
return V_297 &&
( ( V_181 & V_298 ) ||
( ! V_181 && V_8 -> V_10 && F_157 ( V_8 ) ) ) ;
}
static unsigned int F_160 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_242 ,
unsigned int V_299 ,
int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_297 , V_300 , V_227 , V_301 ;
V_227 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_301 = V_242 * V_299 ;
if ( F_50 ( V_301 <= V_227 && V_4 != F_161 ( V_2 ) ) )
return V_301 ;
V_300 = F_20 ( V_4 -> V_79 , V_227 ) ;
if ( V_301 <= V_300 )
return V_301 ;
V_297 = V_300 % V_242 ;
if ( F_159 ( V_297 != 0 , V_8 , V_181 ) )
return V_300 - V_297 ;
return V_300 ;
}
static inline unsigned int F_162 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_302 , V_26 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_96 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_302 = F_99 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_302 < V_26 )
return ( V_26 - V_302 ) ;
return 0 ;
}
static int F_163 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_242 )
{
int V_303 = F_6 ( V_4 ) ;
if ( ! V_303 || ( V_303 > 1 && F_144 ( V_4 ) != V_242 ) ) {
F_115 ( V_2 , V_4 , V_242 ) ;
V_303 = F_6 ( V_4 ) ;
}
return V_303 ;
}
static inline bool F_164 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_304 , int V_181 )
{
if ( V_181 & V_305 )
return true ;
if ( F_46 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_96 ) )
return true ;
if ( ! F_159 ( V_4 -> V_79 < V_304 , V_8 , V_181 ) )
return true ;
return false ;
}
static bool F_165 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_304 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_79 > V_304 )
V_12 = F_5 ( V_4 ) -> V_80 + V_304 ;
return ! F_106 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_166 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_304 , int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_306 ;
F_163 ( V_2 , V_4 , V_304 ) ;
if ( ! F_164 ( V_8 , V_4 , V_304 , V_181 ) )
return 0 ;
V_306 = F_162 ( V_8 , V_4 ) ;
if ( V_306 && ! F_165 ( V_8 , V_4 , V_304 ) )
V_306 = 0 ;
return V_306 ;
}
bool F_167 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_168 ( V_2 ) ;
return V_4 &&
F_166 ( V_2 , V_4 , F_58 ( V_2 ) ,
( F_169 ( V_2 , V_4 ) ?
V_8 -> V_181 : V_305 ) ) ;
}
static int F_170 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_79 ,
unsigned int V_242 , T_11 V_255 )
{
struct V_3 * V_256 ;
int V_259 = V_4 -> V_79 - V_79 ;
T_8 V_86 ;
if ( V_4 -> V_79 != V_4 -> V_269 )
return F_124 ( V_2 , V_4 , V_79 , V_242 , V_255 ) ;
V_256 = F_128 ( V_2 , 0 , V_255 ) ;
if ( F_48 ( V_256 == NULL ) )
return - V_261 ;
V_2 -> V_241 += V_256 -> V_205 ;
F_114 ( V_2 , V_256 -> V_205 ) ;
V_256 -> V_205 += V_259 ;
V_4 -> V_205 -= V_259 ;
F_5 ( V_256 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_256 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_256 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_96 | V_262 ) ;
F_5 ( V_256 ) -> V_65 = V_86 ;
F_5 ( V_256 ) -> V_92 = 0 ;
V_256 -> V_89 = V_4 -> V_89 = V_90 ;
F_133 ( V_4 , V_256 , V_79 ) ;
F_115 ( V_2 , V_4 , V_242 ) ;
F_115 ( V_2 , V_256 , V_242 ) ;
F_112 ( V_256 ) ;
F_134 ( V_4 , V_256 , V_2 ) ;
return 0 ;
}
static bool F_171 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_293 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_307 , V_308 , V_309 , V_302 ;
int V_310 ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
goto V_311;
if ( V_6 -> V_287 != V_288 )
goto V_311;
if ( V_8 -> V_312 &&
( ( ( T_4 ) V_313 << 1 ) >> 1 ) - ( V_8 -> V_312 >> 1 ) > 1 )
goto V_311;
V_302 = F_99 ( V_8 ) ;
F_93 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_302 ) ) ;
V_307 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_308 = ( V_8 -> V_27 - V_302 ) * V_8 -> V_285 ;
V_309 = F_20 ( V_307 , V_308 ) ;
if ( V_309 >= F_30 (unsigned int, sk->sk_gso_max_size,
tp->xmit_size_goal_segs * tp->mss_cache) )
goto V_311;
if ( ( V_4 != F_161 ( V_2 ) ) && ( V_309 >= V_4 -> V_79 ) )
goto V_311;
V_310 = F_172 ( V_314 ) ;
if ( V_310 ) {
T_4 V_315 = F_20 ( V_8 -> V_316 , V_8 -> V_27 * V_8 -> V_285 ) ;
V_315 /= V_310 ;
if ( V_309 >= V_315 )
goto V_311;
} else {
if ( V_309 > F_173 ( V_8 ) * V_8 -> V_285 )
goto V_311;
}
if ( ! V_8 -> V_312 )
V_8 -> V_312 = 1 | ( V_313 << 1 ) ;
if ( V_308 < V_307 && V_308 < V_4 -> V_79 )
* V_293 = true ;
return true ;
V_311:
V_8 -> V_312 = 0 ;
return false ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_317 , * V_318 ;
int V_79 ;
int V_283 ;
int V_319 ;
int V_320 ;
int V_242 ;
if ( ! V_6 -> V_277 . V_278 ||
V_6 -> V_277 . V_283 ||
F_2 ( V_2 ) -> V_287 != V_288 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_173 || V_8 -> V_59 . V_125 )
return - 1 ;
V_242 = F_58 ( V_2 ) ;
V_283 = 2 * V_8 -> V_285 ;
V_319 = V_283 + ( V_8 -> V_321 + 1 ) * V_8 -> V_285 ;
if ( V_283 > F_147 ( V_2 , V_6 -> V_277 . V_280 ) ) {
return - 1 ;
}
if ( V_8 -> V_240 - V_8 -> V_11 < V_319 )
return - 1 ;
if ( V_8 -> V_316 < V_319 )
return - 1 ;
if ( F_106 ( V_8 -> V_11 + V_319 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_99 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_99 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_317 = F_128 ( V_2 , V_283 , V_182 ) ) == NULL )
return - 1 ;
V_2 -> V_241 += V_317 -> V_205 ;
F_114 ( V_2 , V_317 -> V_205 ) ;
V_4 = F_168 ( V_2 ) ;
F_5 ( V_317 ) -> V_80 = F_5 ( V_4 ) -> V_80 ;
F_5 ( V_317 ) -> V_12 = F_5 ( V_4 ) -> V_80 + V_283 ;
F_5 ( V_317 ) -> V_65 = V_235 ;
F_5 ( V_317 ) -> V_92 = 0 ;
V_317 -> V_91 = 0 ;
V_317 -> V_89 = V_4 -> V_89 ;
F_175 ( V_317 , V_4 , V_2 ) ;
V_79 = 0 ;
F_176 (skb, next, sk) {
V_320 = F_30 ( int , V_4 -> V_79 , V_283 - V_79 ) ;
if ( V_317 -> V_89 )
F_177 ( V_4 , 0 , F_130 ( V_317 , V_320 ) , V_320 ) ;
else
V_317 -> V_91 = F_178 ( V_4 , 0 ,
F_130 ( V_317 , V_320 ) ,
V_320 , V_317 -> V_91 ) ;
if ( V_4 -> V_79 <= V_320 ) {
F_5 ( V_317 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_179 ( V_4 , V_2 ) ;
F_180 ( V_2 , V_4 ) ;
} else {
F_5 ( V_317 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_96 | V_262 ) ;
if ( ! F_43 ( V_4 ) -> V_263 ) {
F_181 ( V_4 , V_320 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_182 ( V_4 -> V_183 ,
V_4 -> V_79 , 0 ) ;
} else {
F_135 ( V_4 , V_320 ) ;
F_115 ( V_2 , V_4 , V_242 ) ;
}
F_5 ( V_4 ) -> V_80 += V_320 ;
}
V_79 += V_320 ;
if ( V_79 >= V_283 )
break;
}
F_163 ( V_2 , V_317 , V_317 -> V_79 ) ;
F_5 ( V_317 ) -> V_154 = V_23 ;
if ( ! F_92 ( V_2 , V_317 , 1 , V_182 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_317 ) ;
V_6 -> V_277 . V_283 = F_148 ( V_2 , V_317 -> V_79 ) ;
V_8 -> V_322 . V_323 = F_5 ( V_317 ) -> V_80 ;
V_8 -> V_322 . V_324 = F_5 ( V_317 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_57 ( struct V_1 * V_2 , unsigned int V_242 , int V_181 ,
int V_325 , T_11 V_255 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_303 , V_326 ;
int V_306 ;
int V_327 ;
bool V_293 = false ;
V_326 = 0 ;
if ( ! V_325 ) {
V_327 = F_174 ( V_2 ) ;
if ( ! V_327 ) {
return false ;
} else if ( V_327 > 0 ) {
V_326 = 1 ;
}
}
while ( ( V_4 = F_168 ( V_2 ) ) ) {
unsigned int V_309 ;
V_303 = F_163 ( V_2 , V_4 , V_242 ) ;
F_93 ( ! V_303 ) ;
if ( F_48 ( V_8 -> V_328 ) && V_8 -> V_329 == V_330 )
goto V_328;
V_306 = F_162 ( V_8 , V_4 ) ;
if ( ! V_306 ) {
V_293 = true ;
if ( V_325 == 2 )
V_306 = 1 ;
else
break;
}
if ( F_48 ( ! F_165 ( V_8 , V_4 , V_242 ) ) )
break;
if ( V_303 == 1 ) {
if ( F_48 ( ! F_164 ( V_8 , V_4 , V_242 ,
( F_169 ( V_2 , V_4 ) ?
V_181 : V_305 ) ) ) )
break;
} else {
if ( ! V_325 &&
F_171 ( V_2 , V_4 , & V_293 ) )
break;
}
V_309 = F_29 (unsigned int, sysctl_tcp_limit_output_bytes,
sk->sk_pacing_rate >> 10 ) ;
if ( F_183 ( & V_2 -> V_206 ) > V_309 ) {
F_69 ( V_204 , & V_8 -> V_193 ) ;
F_184 () ;
if ( F_183 ( & V_2 -> V_206 ) > V_309 )
break;
}
V_309 = V_242 ;
if ( V_303 > 1 && ! F_46 ( V_8 ) )
V_309 = F_160 ( V_2 , V_4 , V_242 ,
F_30 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ,
V_181 ) ;
if ( V_4 -> V_79 > V_309 &&
F_48 ( F_170 ( V_2 , V_4 , V_309 , V_242 , V_255 ) ) )
break;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_48 ( F_92 ( V_2 , V_4 , 1 , V_255 ) ) )
break;
V_328:
F_1 ( V_2 , V_4 ) ;
F_158 ( V_8 , V_242 , V_4 ) ;
V_326 += F_6 ( V_4 ) ;
if ( V_325 )
break;
}
if ( F_50 ( V_326 ) ) {
if ( F_185 ( V_2 ) )
V_8 -> V_331 += V_326 ;
if ( V_325 != 2 )
F_186 ( V_2 ) ;
F_155 ( V_2 , V_293 ) ;
return false ;
}
return ( V_325 == 2 ) || ( ! V_8 -> V_10 && F_168 ( V_2 ) ) ;
}
bool F_186 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_332 , V_333 , V_334 ;
T_4 V_335 = F_187 ( V_8 -> V_336 >> 3 ) ;
if ( F_125 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_125 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_175 == V_337 )
return false ;
if ( V_6 -> V_13 != V_338 )
return false ;
if ( V_339 < 3 || ! V_8 -> V_336 || ! V_8 -> V_10 ||
! F_188 ( V_8 ) || F_2 ( V_2 ) -> V_287 != V_288 )
return false ;
if ( ( V_8 -> V_27 > F_99 ( V_8 ) ) &&
F_168 ( V_2 ) )
return false ;
V_332 = V_335 << 1 ;
if ( V_8 -> V_10 == 1 )
V_332 = F_29 ( T_4 , V_332 ,
( V_335 + ( V_335 >> 1 ) + V_340 ) ) ;
V_332 = F_29 ( T_4 , V_332 , F_189 ( 10 ) ) ;
V_333 = V_23 + V_332 ;
V_334 = ( T_4 ) F_2 ( V_2 ) -> V_341 ;
if ( ( T_3 ) ( V_333 - V_334 ) > 0 ) {
T_3 V_22 = V_334 - V_23 ;
if ( V_22 > 0 )
V_332 = V_22 ;
}
F_190 ( V_2 , V_15 , V_332 ,
V_342 ) ;
return true ;
}
static bool F_191 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_3 * V_343 = V_4 + 1 ;
if ( F_48 ( V_4 -> V_343 == V_344 &&
V_343 -> V_343 == V_345 ) ) {
F_192 ( F_9 ( V_2 ) ,
V_346 ) ;
return true ;
}
return false ;
}
void F_193 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_347 ;
int V_19 = F_58 ( V_2 ) ;
int V_213 = - 1 ;
if ( F_168 ( V_2 ) != NULL ) {
V_213 = F_57 ( V_2 , V_19 , V_348 , 2 , V_182 ) ;
goto V_349;
}
if ( V_8 -> V_350 )
goto V_349;
V_4 = F_161 ( V_2 ) ;
if ( F_125 ( ! V_4 ) )
goto V_349;
if ( F_191 ( V_2 , V_4 ) )
goto V_349;
V_347 = F_6 ( V_4 ) ;
if ( F_125 ( ! V_347 ) )
goto V_349;
if ( ( V_347 > 1 ) && ( V_4 -> V_79 > ( V_347 - 1 ) * V_19 ) ) {
if ( F_48 ( F_124 ( V_2 , V_4 , ( V_347 - 1 ) * V_19 , V_19 ,
V_182 ) ) )
goto V_349;
V_4 = F_161 ( V_2 ) ;
}
if ( F_125 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_349;
V_213 = F_194 ( V_2 , V_4 ) ;
if ( F_50 ( ! V_213 ) )
V_8 -> V_350 = V_8 -> V_11 ;
V_349:
F_190 ( V_2 , V_338 ,
F_2 ( V_2 ) -> V_30 ,
V_342 ) ;
if ( F_50 ( ! V_213 ) )
F_192 ( F_9 ( V_2 ) ,
V_351 ) ;
}
void F_195 ( struct V_1 * V_2 , unsigned int V_304 ,
int V_181 )
{
if ( F_48 ( V_2 -> V_175 == V_352 ) )
return;
if ( F_57 ( V_2 , V_304 , V_181 , 0 ,
F_196 ( V_2 , V_182 ) ) )
F_197 ( V_2 ) ;
}
void F_198 ( struct V_1 * V_2 , unsigned int V_242 )
{
struct V_3 * V_4 = F_168 ( V_2 ) ;
F_93 ( ! V_4 || V_4 -> V_79 < V_242 ) ;
F_57 ( V_2 , V_242 , V_305 , 1 , V_2 -> V_353 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_354 ;
int V_355 = F_199 ( V_2 ) ;
int V_356 = F_200 ( V_2 ) ;
int V_357 = F_30 ( int , V_8 -> V_46 , V_356 ) ;
int V_227 ;
if ( V_19 > V_357 )
V_19 = V_357 ;
if ( V_355 < ( V_357 >> 1 ) ) {
V_6 -> V_35 . V_358 = 0 ;
if ( F_201 ( V_2 ) )
V_8 -> V_359 = F_20 ( V_8 -> V_359 ,
4U * V_8 -> V_20 ) ;
V_355 = F_202 ( V_355 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_355 < ( V_356 >> 4 ) || V_355 < V_19 )
return 0 ;
}
if ( V_355 > V_8 -> V_359 )
V_355 = V_8 -> V_359 ;
V_227 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_227 = V_355 ;
if ( ( ( V_227 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_227 )
V_227 = ( ( ( V_227 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_227 <= V_355 - V_19 || V_227 > V_355 )
V_227 = ( V_355 / V_19 ) * V_19 ;
else if ( V_19 == V_357 &&
V_355 > V_227 + ( V_357 >> 1 ) )
V_227 = V_355 ;
}
return V_227 ;
}
static void F_203 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_360 = F_204 ( V_2 , V_4 ) ;
int V_361 , V_362 ;
V_361 = V_4 -> V_79 ;
V_362 = V_360 -> V_79 ;
F_93 ( F_6 ( V_4 ) != 1 || F_6 ( V_360 ) != 1 ) ;
F_205 ( V_2 , V_360 , V_4 ) ;
F_179 ( V_360 , V_2 ) ;
F_206 ( V_360 , F_130 ( V_4 , V_362 ) ,
V_362 ) ;
if ( V_360 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_207 ( V_4 -> V_91 , V_360 -> V_91 , V_361 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_360 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_360 ) -> V_65 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_360 ) -> V_92 & V_363 ;
F_208 ( V_8 ) ;
if ( V_360 == V_8 -> V_364 )
V_8 -> V_364 = V_4 ;
F_121 ( V_2 , V_360 , F_6 ( V_360 ) ) ;
F_180 ( V_2 , V_360 ) ;
}
static bool F_209 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_43 ( V_4 ) -> V_263 != 0 )
return false ;
if ( F_95 ( V_4 ) )
return false ;
if ( V_4 == F_168 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_248 )
return false ;
return true ;
}
static void F_210 ( struct V_1 * V_2 , struct V_3 * V_365 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_365 , * V_366 ;
bool V_367 = true ;
if ( ! V_368 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
return;
F_176 (skb, tmp, sk) {
if ( ! F_209 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_79 ;
if ( V_367 ) {
V_367 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_79 > F_211 ( V_365 ) )
break;
if ( F_106 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_203 ( V_2 , V_365 ) ;
}
}
int F_194 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_304 ;
int V_213 ;
if ( V_6 -> V_277 . V_283 ) {
V_6 -> V_277 . V_283 = 0 ;
}
if ( F_183 ( & V_2 -> V_206 ) >
F_20 ( V_2 -> V_241 + ( V_2 -> V_241 >> 2 ) , V_2 -> V_369 ) )
return - V_370 ;
if ( F_191 ( V_2 , V_4 ) )
return - V_371 ;
if ( F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_97 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_97 ) )
F_212 () ;
if ( F_141 ( V_2 , V_4 , V_8 -> V_97 - F_5 ( V_4 ) -> V_80 ) )
return - V_261 ;
}
if ( F_2 ( V_2 ) -> V_233 -> V_372 ( V_2 ) )
return - V_373 ;
V_304 = F_58 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_80 != V_8 -> V_97 )
return - V_370 ;
if ( V_4 -> V_79 > V_304 ) {
if ( F_124 ( V_2 , V_4 , V_304 , V_304 , V_182 ) )
return - V_261 ;
} else {
int V_374 = F_6 ( V_4 ) ;
if ( F_48 ( V_374 > 1 ) ) {
if ( F_127 ( V_4 , V_182 ) )
return - V_261 ;
F_163 ( V_2 , V_4 , V_304 ) ;
F_121 ( V_2 , V_4 , V_374 - F_6 ( V_4 ) ) ;
}
}
F_210 ( V_2 , V_4 , V_304 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_48 ( ( V_375 && ( ( unsigned long ) V_4 -> V_183 & 3 ) ) ||
F_213 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_317 = F_214 ( V_4 , V_376 ,
V_182 ) ;
V_213 = V_317 ? F_92 ( V_2 , V_317 , 0 , V_182 ) :
- V_215 ;
} else {
V_213 = F_92 ( V_2 , V_4 , 1 , V_182 ) ;
}
if ( F_50 ( ! V_213 ) ) {
F_5 ( V_4 ) -> V_92 |= V_363 ;
F_215 ( F_9 ( V_2 ) , V_377 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
F_192 ( F_9 ( V_2 ) , V_378 ) ;
V_8 -> V_379 ++ ;
}
return V_213 ;
}
int F_216 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_213 = F_194 ( V_2 , V_4 ) ;
if ( V_213 == 0 ) {
#if V_380 > 0
if ( F_5 ( V_4 ) -> V_92 & V_249 ) {
F_217 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_250 )
V_8 -> V_381 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_92 |= V_382 ;
V_8 -> V_250 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_383 )
V_8 -> V_383 = F_5 ( V_4 ) -> V_154 ;
F_5 ( V_4 ) -> V_225 = V_8 -> V_11 ;
} else if ( V_213 != - V_371 ) {
F_192 ( F_9 ( V_2 ) , V_384 ) ;
}
if ( V_8 -> V_385 < 0 )
V_8 -> V_385 = 0 ;
V_8 -> V_385 += F_6 ( V_4 ) ;
return V_213 ;
}
static bool F_218 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_287 != V_386 )
return false ;
if ( F_119 ( V_8 ) )
return false ;
if ( F_167 ( V_2 ) )
return false ;
return true ;
}
void F_219 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_387 = NULL ;
T_4 V_388 ;
int V_389 ;
int V_390 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_252 )
V_8 -> V_391 = V_8 -> V_97 ;
if ( V_8 -> V_364 ) {
V_4 = V_8 -> V_364 ;
V_388 = F_5 ( V_4 ) -> V_12 ;
if ( F_106 ( V_388 , V_8 -> V_391 ) )
V_388 = V_8 -> V_391 ;
} else {
V_4 = F_220 ( V_2 ) ;
V_388 = V_8 -> V_97 ;
}
F_221 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
if ( V_4 == F_168 ( V_2 ) )
break;
if ( V_387 == NULL )
V_8 -> V_364 = V_4 ;
if ( F_99 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_390 ) {
V_392:
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_120 ( V_8 ) ) )
break;
V_389 = V_393 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_391 ) ) {
V_8 -> V_391 = V_388 ;
if ( ! F_218 ( V_2 ) )
break;
if ( V_387 != NULL ) {
V_4 = V_387 ;
V_387 = NULL ;
}
V_390 = 1 ;
goto V_392;
} else if ( ! ( V_92 & V_251 ) ) {
if ( V_387 == NULL && ! ( V_92 & ( V_249 | V_248 ) ) )
V_387 = V_4 ;
continue;
} else {
V_388 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_287 != V_394 )
V_389 = V_395 ;
else
V_389 = V_396 ;
}
if ( V_92 & ( V_248 | V_249 ) )
continue;
if ( F_216 ( V_2 , V_4 ) )
return;
F_192 ( F_9 ( V_2 ) , V_389 ) ;
if ( F_185 ( V_2 ) )
V_8 -> V_331 += F_6 ( V_4 ) ;
if ( V_4 == F_220 ( V_2 ) )
F_190 ( V_2 , V_338 ,
F_2 ( V_2 ) -> V_30 ,
V_342 ) ;
}
}
void F_222 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_161 ( V_2 ) ;
int V_242 ;
V_242 = F_58 ( V_2 ) ;
if ( F_168 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_65 |= V_96 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_240 ++ ;
} else {
for (; ; ) {
V_4 = F_223 ( V_376 ,
V_2 -> V_353 ) ;
if ( V_4 )
break;
F_224 () ;
}
F_225 ( V_4 , V_376 ) ;
F_45 ( V_4 , V_8 -> V_240 ,
V_235 | V_96 ) ;
F_111 ( V_2 , V_4 ) ;
}
F_195 ( V_2 , V_242 , V_348 ) ;
}
void F_226 ( struct V_1 * V_2 , T_11 V_397 )
{
struct V_3 * V_4 ;
V_4 = F_227 ( V_376 , V_397 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_398 ) ;
return;
}
F_225 ( V_4 , V_376 ) ;
F_45 ( V_4 , F_10 ( V_2 ) ,
V_235 | V_399 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_92 ( V_2 , V_4 , 0 , V_397 ) )
F_34 ( F_9 ( V_2 ) , V_398 ) ;
F_215 ( F_9 ( V_2 ) , V_400 ) ;
}
int F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_220 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_65 & V_95 ) ) {
F_229 ( L_2 , V_401 ) ;
return - V_402 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_235 ) ) {
if ( F_95 ( V_4 ) ) {
struct V_3 * V_317 = F_230 ( V_4 , V_182 ) ;
if ( V_317 == NULL )
return - V_261 ;
F_179 ( V_4 , V_2 ) ;
F_112 ( V_317 ) ;
F_231 ( V_2 , V_317 ) ;
F_180 ( V_2 , V_4 ) ;
V_2 -> V_241 += V_317 -> V_205 ;
F_114 ( V_2 , V_317 -> V_205 ) ;
V_4 = V_317 ;
}
F_5 ( V_4 ) -> V_65 |= V_235 ;
F_36 ( F_3 ( V_2 ) , V_4 ) ;
}
F_5 ( V_4 ) -> V_154 = V_23 ;
return F_92 ( V_2 , V_4 , 1 , V_182 ) ;
}
struct V_3 * F_232 ( struct V_1 * V_2 , struct V_17 * V_18 ,
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
V_4 = F_233 ( V_2 , V_376 , 1 , V_182 ) ;
if ( F_48 ( ! V_4 ) ) {
F_234 ( V_18 ) ;
return NULL ;
}
F_225 ( V_4 , V_376 ) ;
F_235 ( V_4 , V_18 ) ;
F_236 ( V_4 , V_2 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_403 && V_8 -> V_59 . V_403 < V_19 )
V_19 = V_8 -> V_59 . V_403 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
#ifdef F_237
if ( F_48 ( V_73 -> V_404 ) )
F_5 ( V_4 ) -> V_154 = F_238 ( V_73 ) ;
else
#endif
F_5 ( V_4 ) -> V_154 = V_23 ;
V_212 = F_53 ( V_2 , V_73 , V_19 , V_4 , & V_101 , & V_143 ,
V_135 ) + sizeof( * V_75 ) ;
F_101 ( V_4 , V_212 ) ;
F_102 ( V_4 ) ;
V_75 = F_42 ( V_4 ) ;
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 -> V_405 = 1 ;
V_75 -> V_406 = 1 ;
F_38 ( V_73 , V_75 ) ;
V_75 -> V_221 = F_105 ( V_166 -> V_407 ) ;
V_75 -> V_223 = V_166 -> V_408 ;
F_45 ( V_4 , F_54 ( V_73 ) -> V_409 ,
V_95 | V_235 ) ;
V_75 -> V_80 = F_49 ( F_5 ( V_4 ) -> V_80 ) ;
V_75 -> V_225 = F_49 ( F_54 ( V_73 ) -> V_61 ) ;
V_75 -> V_227 = F_105 ( F_20 ( V_73 -> V_45 , 65535U ) ) ;
F_47 ( ( T_9 * ) ( V_75 + 1 ) , V_8 , & V_101 ) ;
V_75 -> V_410 = ( V_212 >> 2 ) ;
F_239 ( F_9 ( V_2 ) , V_236 ) ;
#ifdef F_52
if ( V_143 ) {
F_54 ( V_73 ) -> V_149 -> V_232 ( V_101 . V_107 ,
V_143 , NULL , V_73 , V_4 ) ;
}
#endif
return V_4 ;
}
static void F_240 ( struct V_1 * V_2 )
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
if ( V_8 -> V_59 . V_403 )
V_8 -> V_59 . V_274 = V_8 -> V_59 . V_403 ;
V_8 -> V_411 = 0 ;
F_149 ( V_2 ) ;
F_150 ( V_2 , F_152 ( V_18 ) ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_412 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_403 && V_8 -> V_59 . V_403 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_403 ;
F_241 ( V_2 ) ;
if ( V_2 -> V_413 & V_414 &&
( V_8 -> V_46 > F_200 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_200 ( V_2 ) ;
F_28 ( F_200 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_415 ? V_8 -> V_78 - sizeof( struct V_74 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_158 ,
& V_48 ,
F_23 ( V_18 , V_416 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_359 = V_8 -> V_45 ;
V_2 -> V_417 = 0 ;
F_242 ( V_2 , V_418 ) ;
V_8 -> V_316 = 0 ;
F_243 ( V_8 , 0 ) ;
V_8 -> V_97 = V_8 -> V_240 ;
V_8 -> V_296 = V_8 -> V_240 ;
V_8 -> V_98 = V_8 -> V_240 ;
V_8 -> V_11 = V_8 -> V_240 ;
if ( F_50 ( ! V_8 -> V_328 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_419 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_420 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_421 ;
F_2 ( V_2 ) -> V_422 = 0 ;
F_244 ( V_8 ) ;
}
static void F_245 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_169 * V_170 = F_5 ( V_4 ) ;
V_170 -> V_12 += V_4 -> V_79 ;
F_112 ( V_4 ) ;
F_246 ( V_2 , V_4 ) ;
V_2 -> V_241 += V_4 -> V_205 ;
F_114 ( V_2 , V_4 -> V_205 ) ;
V_8 -> V_240 = V_170 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_247 ( struct V_1 * V_2 , struct V_3 * V_405 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_423 = V_8 -> V_148 ;
int V_424 = 0 , V_50 , V_202 , V_213 = 0 , V_425 = V_423 -> V_183 -> V_426 ;
struct V_3 * V_427 = NULL , * V_183 ;
unsigned long V_428 = 0 ;
V_8 -> V_59 . V_274 = V_8 -> V_20 ;
F_248 ( V_2 , & V_8 -> V_59 . V_274 , & V_423 -> V_162 ,
& V_424 , & V_428 ) ;
if ( V_424 > 1 &&
F_249 ( V_313 , V_428 + ( 60 * V_429 << V_424 ) ) ) {
V_423 -> V_162 . V_79 = - 1 ;
goto V_430;
}
if ( V_431 & V_432 )
V_423 -> V_162 . V_79 = - 1 ;
else if ( V_423 -> V_162 . V_79 <= 0 )
goto V_430;
if ( V_8 -> V_59 . V_403 && V_8 -> V_59 . V_403 < V_8 -> V_59 . V_274 )
V_8 -> V_59 . V_274 = V_8 -> V_59 . V_403 ;
V_50 = F_145 ( V_2 , F_2 ( V_2 ) -> V_284 ) -
V_145 ;
V_50 = F_30 ( V_433 , V_50 , V_423 -> V_171 ) ;
V_50 = F_30 ( V_433 , V_50 , F_250 ( V_376 ) ) ;
V_427 = F_251 ( V_405 , V_376 , V_50 ,
V_2 -> V_353 ) ;
if ( V_427 == NULL )
goto V_430;
for ( V_202 = 0 ; V_202 < V_425 && V_427 -> V_79 < V_50 ; ++ V_202 ) {
struct V_434 * V_435 = & V_423 -> V_183 -> V_436 [ V_202 ] ;
unsigned char T_12 * V_437 = V_435 -> V_438 ;
int V_79 = V_435 -> V_439 ;
if ( V_427 -> V_79 + V_79 > V_50 )
V_79 = V_50 - V_427 -> V_79 ;
else if ( V_202 + 1 == V_425 )
V_423 -> V_183 = NULL ;
if ( F_252 ( V_427 , V_437 , V_79 ) )
goto V_430;
}
V_183 = F_96 ( V_427 , V_2 -> V_353 ) ;
if ( V_183 == NULL )
goto V_430;
F_5 ( V_183 ) -> V_80 ++ ;
F_5 ( V_183 ) -> V_65 &= ~ V_95 ;
F_5 ( V_183 ) -> V_65 = ( V_235 | V_262 ) ;
F_245 ( V_2 , V_183 ) ;
V_423 -> V_440 = V_183 -> V_79 ;
F_94 ( & V_405 -> V_214 ) ;
V_183 -> V_214 = V_405 -> V_214 ;
if ( F_92 ( V_2 , V_427 , 0 , V_2 -> V_353 ) == 0 ) {
V_8 -> V_427 = ( V_423 -> V_440 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_441;
}
V_427 = NULL ;
V_430:
if ( V_423 -> V_162 . V_79 > 0 )
V_423 -> V_162 . V_79 = 0 ;
V_213 = F_92 ( V_2 , V_405 , 1 , V_2 -> V_353 ) ;
if ( V_213 )
V_8 -> V_164 = 0 ;
F_253 ( V_427 ) ;
V_441:
V_423 -> V_162 . V_79 = - 1 ;
return V_213 ;
}
int F_254 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_256 ;
int V_213 ;
F_240 ( V_2 ) ;
if ( F_48 ( V_8 -> V_328 ) ) {
F_255 ( V_2 , NULL ) ;
return 0 ;
}
V_256 = F_223 ( V_376 + 15 , V_2 -> V_353 ) ;
if ( F_48 ( V_256 == NULL ) )
return - V_215 ;
F_225 ( V_256 , V_376 ) ;
F_45 ( V_256 , V_8 -> V_240 ++ , V_95 ) ;
V_8 -> V_383 = F_5 ( V_256 ) -> V_154 = V_23 ;
F_245 ( V_2 , V_256 ) ;
F_37 ( V_2 , V_256 ) ;
V_213 = V_8 -> V_148 ? F_247 ( V_2 , V_256 ) :
F_92 ( V_2 , V_256 , 1 , V_2 -> V_353 ) ;
if ( V_213 == - V_442 )
return V_213 ;
V_8 -> V_11 = V_8 -> V_240 ;
V_8 -> V_443 = V_8 -> V_240 ;
F_215 ( F_9 ( V_2 ) , V_444 ) ;
F_190 ( V_2 , V_338 ,
F_2 ( V_2 ) -> V_30 , V_342 ) ;
return 0 ;
}
void F_256 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_332 ;
if ( V_37 > V_445 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_446 = V_429 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_447 & V_448 ) )
V_446 = V_340 ;
if ( V_8 -> V_336 ) {
int V_335 = F_29 ( int , F_187 ( V_8 -> V_336 >> 3 ) ,
V_445 ) ;
if ( V_335 < V_446 )
V_446 = V_335 ;
}
V_37 = F_20 ( V_37 , V_446 ) ;
}
V_332 = V_313 + V_37 ;
if ( V_6 -> V_35 . V_447 & V_449 ) {
if ( V_6 -> V_35 . V_450 ||
F_257 ( V_6 -> V_35 . V_332 , V_313 + ( V_37 >> 2 ) ) ) {
F_258 ( V_2 ) ;
return;
}
if ( ! F_249 ( V_332 , V_6 -> V_35 . V_332 ) )
V_332 = V_6 -> V_35 . V_332 ;
}
V_6 -> V_35 . V_447 |= V_451 | V_449 ;
V_6 -> V_35 . V_332 = V_332 ;
F_259 ( V_2 , & V_6 -> V_452 , V_332 ) ;
}
void F_258 ( struct V_1 * V_2 )
{
struct V_3 * V_256 ;
if ( V_2 -> V_175 == V_352 )
return;
V_256 = F_227 ( V_376 , F_196 ( V_2 , V_182 ) ) ;
if ( V_256 == NULL ) {
F_260 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_453 ;
F_190 ( V_2 , V_41 ,
V_340 , V_342 ) ;
return;
}
F_225 ( V_256 , V_376 ) ;
F_45 ( V_256 , F_10 ( V_2 ) , V_235 ) ;
F_5 ( V_256 ) -> V_154 = V_23 ;
F_92 ( V_2 , V_256 , 0 , F_196 ( V_2 , V_182 ) ) ;
}
static int F_261 ( struct V_1 * V_2 , int V_454 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_227 ( V_376 , F_196 ( V_2 , V_182 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_225 ( V_4 , V_376 ) ;
F_45 ( V_4 , V_8 -> V_97 - ! V_454 , V_235 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
return F_92 ( V_2 , V_4 , 0 , V_182 ) ;
}
void F_262 ( struct V_1 * V_2 )
{
if ( V_2 -> V_175 == V_455 ) {
F_3 ( V_2 ) -> V_456 = F_3 ( V_2 ) -> V_61 - 1 ;
F_261 ( V_2 , 0 ) ;
}
}
int F_263 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_175 == V_352 )
return - 1 ;
if ( ( V_4 = F_168 ( V_2 ) ) != NULL &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) ) {
int V_213 ;
unsigned int V_19 = F_58 ( V_2 ) ;
unsigned int V_457 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
if ( F_11 ( V_8 -> V_443 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_443 = F_5 ( V_4 ) -> V_12 ;
if ( V_457 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_80 ||
V_4 -> V_79 > V_19 ) {
V_457 = F_20 ( V_457 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_262 ;
if ( F_124 ( V_2 , V_4 , V_457 , V_19 , V_182 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_115 ( V_2 , V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_262 ;
F_5 ( V_4 ) -> V_154 = V_23 ;
V_213 = F_92 ( V_2 , V_4 , 1 , V_182 ) ;
if ( ! V_213 )
F_1 ( V_2 , V_4 ) ;
return V_213 ;
} else {
if ( F_264 ( V_8 -> V_98 , V_8 -> V_97 + 1 , V_8 -> V_97 + 0xFFFF ) )
F_261 ( V_2 , 1 ) ;
return F_261 ( V_2 , 0 ) ;
}
}
void F_265 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_213 ;
V_213 = F_263 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_168 ( V_2 ) ) {
V_6 -> V_458 = 0 ;
V_6 -> V_459 = 0 ;
return;
}
if ( V_213 <= 0 ) {
if ( V_6 -> V_459 < V_460 )
V_6 -> V_459 ++ ;
V_6 -> V_458 ++ ;
F_190 ( V_2 , V_461 ,
F_20 ( V_6 -> V_30 << V_6 -> V_459 , V_342 ) ,
V_342 ) ;
} else {
if ( ! V_6 -> V_458 )
V_6 -> V_458 = 1 ;
F_190 ( V_2 , V_461 ,
F_20 ( V_6 -> V_30 << V_6 -> V_459 ,
V_462 ) ,
V_342 ) ;
}
}
