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
F_2 ( V_2 ) -> V_200 -> V_201 ( V_2 ) ;
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
F_104 ( V_4 , V_2 ) ;
F_105 ( V_4 -> V_205 , & V_2 -> V_206 ) ;
V_75 = F_42 ( V_4 ) ;
V_75 -> V_221 = V_210 -> V_222 ;
V_75 -> V_223 = V_210 -> V_224 ;
V_75 -> V_80 = F_49 ( V_170 -> V_80 ) ;
V_75 -> V_225 = F_49 ( V_8 -> V_61 ) ;
* ( ( ( V_226 * ) V_75 ) + 6 ) = F_106 ( ( ( V_212 >> 2 ) << 12 ) |
V_170 -> V_65 ) ;
if ( F_48 ( V_170 -> V_65 & V_95 ) ) {
V_75 -> V_227 = F_106 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_75 -> V_227 = F_106 ( F_31 ( V_2 ) ) ;
}
V_75 -> V_228 = 0 ;
V_75 -> V_229 = 0 ;
if ( F_48 ( F_46 ( V_8 ) && F_11 ( V_170 -> V_80 , V_8 -> V_98 ) ) ) {
if ( F_11 ( V_8 -> V_98 , V_170 -> V_80 + 0x10000 ) ) {
V_75 -> V_229 = F_106 ( V_8 -> V_98 - V_170 -> V_80 ) ;
V_75 -> V_230 = 1 ;
} else if ( F_107 ( V_170 -> V_80 + 0xFFFF , V_8 -> V_11 ) ) {
V_75 -> V_229 = F_106 ( 0xFFFF ) ;
V_75 -> V_230 = 1 ;
}
}
F_47 ( ( T_9 * ) ( V_75 + 1 ) , V_8 , & V_101 ) ;
if ( F_50 ( ( V_170 -> V_65 & V_95 ) == 0 ) )
F_40 ( V_2 , V_4 , V_212 ) ;
#ifdef F_52
if ( V_143 ) {
F_108 ( V_2 , V_231 ) ;
V_8 -> V_149 -> V_232 ( V_101 . V_107 ,
V_143 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_200 -> V_233 ( V_2 , V_4 ) ;
if ( F_50 ( V_170 -> V_65 & V_234 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_79 != V_212 )
F_22 ( V_8 , V_2 ) ;
if ( F_107 ( V_170 -> V_12 , V_8 -> V_11 ) || V_170 -> V_80 == V_170 -> V_12 )
F_109 ( F_9 ( V_2 ) , V_235 ,
F_6 ( V_4 ) ) ;
V_213 = V_6 -> V_200 -> V_236 ( V_2 , V_4 , & V_210 -> V_237 . V_238 ) ;
if ( F_50 ( V_213 <= 0 ) )
return V_213 ;
F_110 ( V_2 ) ;
return F_111 ( V_213 ) ;
}
static void F_112 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_239 = F_5 ( V_4 ) -> V_12 ;
F_113 ( V_4 ) ;
F_114 ( V_2 , V_4 ) ;
V_2 -> V_240 += V_4 -> V_205 ;
F_115 ( V_2 , V_4 -> V_205 ) ;
}
static void F_116 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_241 )
{
struct V_87 * V_88 = F_43 ( V_4 ) ;
F_117 ( F_95 ( V_4 ) ) ;
if ( V_4 -> V_79 <= V_241 || V_4 -> V_89 == V_242 ) {
V_88 -> V_93 = 1 ;
V_88 -> V_94 = 0 ;
V_88 -> V_83 = 0 ;
} else {
V_88 -> V_93 = F_118 ( V_4 -> V_79 , V_241 ) ;
V_88 -> V_94 = V_241 ;
V_88 -> V_83 = V_2 -> V_243 ;
}
}
static void F_119 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_244 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_245 || F_120 ( V_8 ) )
return;
if ( F_107 ( F_121 ( V_8 ) , F_5 ( V_4 ) -> V_80 ) )
V_8 -> V_246 -= V_244 ;
}
static void F_122 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_244 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_244 ;
if ( F_5 ( V_4 ) -> V_92 & V_247 )
V_8 -> V_245 -= V_244 ;
if ( F_5 ( V_4 ) -> V_92 & V_248 )
V_8 -> V_249 -= V_244 ;
if ( F_5 ( V_4 ) -> V_92 & V_250 )
V_8 -> V_251 -= V_244 ;
if ( F_120 ( V_8 ) && V_244 > 0 )
V_8 -> V_245 -= F_30 ( T_4 , V_8 -> V_245 , V_244 ) ;
F_119 ( V_2 , V_4 , V_244 ) ;
if ( V_8 -> V_252 &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_5 ( V_8 -> V_252 ) -> V_80 ) &&
( F_123 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_247 ) ) )
V_8 -> V_253 -= V_244 ;
F_124 ( V_8 ) ;
}
static void F_125 ( struct V_3 * V_4 , struct V_3 * V_254 )
{
struct V_87 * V_88 = F_43 ( V_4 ) ;
if ( F_48 ( V_88 -> V_255 & V_256 ) &&
! F_11 ( V_88 -> V_257 , F_5 ( V_254 ) -> V_80 ) ) {
struct V_87 * V_258 = F_43 ( V_254 ) ;
T_8 V_259 = V_88 -> V_255 & V_256 ;
V_88 -> V_255 &= ~ V_259 ;
V_258 -> V_255 |= V_259 ;
F_126 ( V_88 -> V_257 , V_258 -> V_257 ) ;
}
}
int F_127 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 ,
unsigned int V_241 , T_11 V_260 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_261 ;
int V_262 , V_263 ;
int V_264 ;
T_8 V_86 ;
if ( F_128 ( V_79 > V_4 -> V_79 ) )
return - V_265 ;
V_262 = F_129 ( V_4 ) - V_79 ;
if ( V_262 < 0 )
V_262 = 0 ;
if ( F_130 ( V_4 , V_260 ) )
return - V_266 ;
V_261 = F_131 ( V_2 , V_262 , V_260 ) ;
if ( V_261 == NULL )
return - V_266 ;
V_2 -> V_240 += V_261 -> V_205 ;
F_115 ( V_2 , V_261 -> V_205 ) ;
V_264 = V_4 -> V_79 - V_79 - V_262 ;
V_261 -> V_205 += V_264 ;
V_4 -> V_205 -= V_264 ;
F_5 ( V_261 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_261 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_261 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_96 | V_267 ) ;
F_5 ( V_261 ) -> V_65 = V_86 ;
F_5 ( V_261 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
if ( ! F_43 ( V_4 ) -> V_268 && V_4 -> V_89 != V_90 ) {
V_261 -> V_91 = F_132 ( V_4 -> V_183 + V_79 ,
F_133 ( V_261 , V_262 ) ,
V_262 , 0 ) ;
F_134 ( V_4 , V_79 ) ;
V_4 -> V_91 = F_135 ( V_4 -> V_91 , V_261 -> V_91 , V_79 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_136 ( V_4 , V_261 , V_79 ) ;
}
V_261 -> V_89 = V_4 -> V_89 ;
F_5 ( V_261 ) -> V_154 = F_5 ( V_4 ) -> V_154 ;
V_261 -> V_216 = V_4 -> V_216 ;
F_125 ( V_4 , V_261 ) ;
V_263 = F_6 ( V_4 ) ;
F_116 ( V_2 , V_4 , V_241 ) ;
F_116 ( V_2 , V_261 , V_241 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_261 ) -> V_12 ) ) {
int V_269 = V_263 - F_6 ( V_4 ) -
F_6 ( V_261 ) ;
if ( V_269 )
F_122 ( V_2 , V_4 , V_269 ) ;
}
F_113 ( V_261 ) ;
F_137 ( V_4 , V_261 , V_2 ) ;
return 0 ;
}
static void F_138 ( struct V_3 * V_4 , int V_79 )
{
struct V_87 * V_88 ;
int V_202 , V_270 , V_271 ;
V_271 = F_30 ( int , V_79 , F_129 ( V_4 ) ) ;
if ( V_271 ) {
F_139 ( V_4 , V_271 ) ;
V_79 -= V_271 ;
if ( ! V_79 )
return;
}
V_271 = V_79 ;
V_270 = 0 ;
V_88 = F_43 ( V_4 ) ;
for ( V_202 = 0 ; V_202 < V_88 -> V_268 ; V_202 ++ ) {
int V_171 = F_140 ( & V_88 -> V_272 [ V_202 ] ) ;
if ( V_171 <= V_271 ) {
F_141 ( V_4 , V_202 ) ;
V_271 -= V_171 ;
} else {
V_88 -> V_272 [ V_270 ] = V_88 -> V_272 [ V_202 ] ;
if ( V_271 ) {
V_88 -> V_272 [ V_270 ] . V_273 += V_271 ;
F_142 ( & V_88 -> V_272 [ V_270 ] , V_271 ) ;
V_271 = 0 ;
}
V_270 ++ ;
}
}
V_88 -> V_268 = V_270 ;
F_143 ( V_4 ) ;
V_4 -> V_274 -= V_79 ;
V_4 -> V_79 = V_4 -> V_274 ;
}
int F_144 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 )
{
if ( F_130 ( V_4 , V_182 ) )
return - V_266 ;
F_138 ( V_4 , V_79 ) ;
F_5 ( V_4 ) -> V_80 += V_79 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_205 -= V_79 ;
V_2 -> V_240 -= V_79 ;
F_145 ( V_2 , V_79 ) ;
F_146 ( V_2 , V_275 ) ;
if ( F_6 ( V_4 ) > 1 )
F_116 ( V_2 , V_4 , F_147 ( V_4 ) ) ;
return 0 ;
}
static inline int F_148 ( struct V_1 * V_2 , int V_276 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_241 ;
V_241 = V_276 - V_6 -> V_200 -> V_277 - sizeof( struct V_74 ) ;
if ( V_6 -> V_200 -> V_278 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_149 ( V_18 ) )
V_241 -= V_6 -> V_200 -> V_278 ;
}
if ( V_241 > V_8 -> V_59 . V_279 )
V_241 = V_8 -> V_59 . V_279 ;
V_241 -= V_6 -> V_280 ;
if ( V_241 < 48 )
V_241 = 48 ;
return V_241 ;
}
int F_150 ( struct V_1 * V_2 , int V_276 )
{
return F_148 ( V_2 , V_276 ) -
( F_3 ( V_2 ) -> V_78 - sizeof( struct V_74 ) ) ;
}
int F_151 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_281 ;
V_281 = V_19 +
V_8 -> V_78 +
V_6 -> V_280 +
V_6 -> V_200 -> V_277 ;
if ( V_6 -> V_200 -> V_278 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_149 ( V_18 ) )
V_281 += V_6 -> V_200 -> V_278 ;
}
return V_281 ;
}
void F_152 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_282 . V_283 = V_284 > 1 ;
V_6 -> V_282 . V_285 = V_8 -> V_59 . V_279 + sizeof( struct V_74 ) +
V_6 -> V_200 -> V_277 ;
V_6 -> V_282 . V_286 = F_151 ( V_2 , V_287 ) ;
V_6 -> V_282 . V_288 = 0 ;
}
unsigned int F_153 ( struct V_1 * V_2 , T_4 V_276 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_241 ;
if ( V_6 -> V_282 . V_285 > V_276 )
V_6 -> V_282 . V_285 = V_276 ;
V_241 = F_150 ( V_2 , V_276 ) ;
V_241 = F_154 ( V_8 , V_241 ) ;
V_6 -> V_289 = V_276 ;
if ( V_6 -> V_282 . V_283 )
V_241 = F_20 ( V_241 , F_150 ( V_2 , V_6 -> V_282 . V_286 ) ) ;
V_8 -> V_290 = V_241 ;
return V_241 ;
}
unsigned int F_58 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_241 ;
unsigned int V_291 ;
struct V_100 V_101 ;
struct V_142 * V_143 ;
V_241 = V_8 -> V_290 ;
if ( V_18 ) {
T_4 V_281 = F_155 ( V_18 ) ;
if ( V_281 != F_2 ( V_2 ) -> V_289 )
V_241 = F_153 ( V_2 , V_281 ) ;
}
V_291 = F_55 ( V_2 , NULL , & V_101 , & V_143 ) +
sizeof( struct V_74 ) ;
if ( V_291 != V_8 -> V_78 ) {
int V_22 = ( int ) V_291 - V_8 -> V_78 ;
V_241 -= V_22 ;
}
return V_241 ;
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_292 == V_293 &&
V_2 -> V_294 && ! F_157 ( V_295 , & V_2 -> V_294 -> V_86 ) ) {
T_4 V_296 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_297 = F_21 ( V_8 -> V_32 , V_296 ) ;
if ( V_297 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_297 ) >> 1 ;
}
V_8 -> V_32 = 0 ;
}
V_8 -> V_31 = V_23 ;
}
static void F_158 ( struct V_1 * V_2 , bool V_298 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_97 , V_8 -> V_299 ) ||
V_8 -> V_10 > V_8 -> V_300 ) {
V_8 -> V_300 = V_8 -> V_10 ;
V_8 -> V_299 = V_8 -> V_11 ;
V_8 -> V_298 = V_298 ;
}
if ( F_159 ( V_2 ) ) {
V_8 -> V_32 = 0 ;
V_8 -> V_31 = V_23 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_32 )
V_8 -> V_32 = V_8 -> V_10 ;
if ( V_34 &&
( T_3 ) ( V_23 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 )
F_156 ( V_2 ) ;
}
}
static bool F_160 ( const struct V_7 * V_8 )
{
return F_107 ( V_8 -> V_301 , V_8 -> V_97 ) &&
! F_107 ( V_8 -> V_301 , V_8 -> V_11 ) ;
}
static void F_161 ( struct V_7 * V_8 , unsigned int V_241 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_79 < F_6 ( V_4 ) * V_241 )
V_8 -> V_301 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_162 ( bool V_302 , const struct V_7 * V_8 ,
int V_181 )
{
return V_302 &&
( ( V_181 & V_303 ) ||
( ! V_181 && V_8 -> V_10 && F_160 ( V_8 ) ) ) ;
}
static unsigned int F_163 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_241 ,
unsigned int V_304 ,
int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_302 , V_305 , V_227 , V_306 ;
V_227 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_306 = V_241 * V_304 ;
if ( F_50 ( V_306 <= V_227 && V_4 != F_164 ( V_2 ) ) )
return V_306 ;
V_305 = F_20 ( V_4 -> V_79 , V_227 ) ;
if ( V_306 <= V_305 )
return V_306 ;
V_302 = V_305 % V_241 ;
if ( F_162 ( V_302 != 0 , V_8 , V_181 ) )
return V_305 - V_302 ;
return V_305 ;
}
static inline unsigned int F_165 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_307 , V_26 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_96 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_307 = F_99 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_307 < V_26 )
return ( V_26 - V_307 ) ;
return 0 ;
}
static int F_166 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_241 )
{
int V_308 = F_6 ( V_4 ) ;
if ( ! V_308 || ( V_308 > 1 && F_147 ( V_4 ) != V_241 ) ) {
F_116 ( V_2 , V_4 , V_241 ) ;
V_308 = F_6 ( V_4 ) ;
}
return V_308 ;
}
static inline bool F_167 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_309 , int V_181 )
{
if ( V_181 & V_310 )
return true ;
if ( F_46 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_96 ) )
return true ;
if ( ! F_162 ( V_4 -> V_79 < V_309 , V_8 , V_181 ) )
return true ;
return false ;
}
static bool F_168 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_309 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_79 > V_309 )
V_12 = F_5 ( V_4 ) -> V_80 + V_309 ;
return ! F_107 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_169 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_309 , int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_311 ;
F_166 ( V_2 , V_4 , V_309 ) ;
if ( ! F_167 ( V_8 , V_4 , V_309 , V_181 ) )
return 0 ;
V_311 = F_165 ( V_8 , V_4 ) ;
if ( V_311 && ! F_168 ( V_8 , V_4 , V_309 ) )
V_311 = 0 ;
return V_311 ;
}
bool F_170 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_171 ( V_2 ) ;
return V_4 &&
F_169 ( V_2 , V_4 , F_58 ( V_2 ) ,
( F_172 ( V_2 , V_4 ) ?
V_8 -> V_181 : V_310 ) ) ;
}
static int F_173 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_79 ,
unsigned int V_241 , T_11 V_260 )
{
struct V_3 * V_261 ;
int V_264 = V_4 -> V_79 - V_79 ;
T_8 V_86 ;
if ( V_4 -> V_79 != V_4 -> V_274 )
return F_127 ( V_2 , V_4 , V_79 , V_241 , V_260 ) ;
V_261 = F_131 ( V_2 , 0 , V_260 ) ;
if ( F_48 ( V_261 == NULL ) )
return - V_266 ;
V_2 -> V_240 += V_261 -> V_205 ;
F_115 ( V_2 , V_261 -> V_205 ) ;
V_261 -> V_205 += V_264 ;
V_4 -> V_205 -= V_264 ;
F_5 ( V_261 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_261 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_261 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_96 | V_267 ) ;
F_5 ( V_261 ) -> V_65 = V_86 ;
F_5 ( V_261 ) -> V_92 = 0 ;
V_261 -> V_89 = V_4 -> V_89 = V_90 ;
F_136 ( V_4 , V_261 , V_79 ) ;
F_125 ( V_4 , V_261 ) ;
F_116 ( V_2 , V_4 , V_241 ) ;
F_116 ( V_2 , V_261 , V_241 ) ;
F_113 ( V_261 ) ;
F_137 ( V_4 , V_261 , V_2 ) ;
return 0 ;
}
static bool F_174 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_298 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_312 , V_313 , V_314 , V_307 ;
int V_315 ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
goto V_316;
if ( V_6 -> V_292 != V_293 )
goto V_316;
if ( V_8 -> V_317 &&
( ( ( T_4 ) V_318 << 1 ) >> 1 ) - ( V_8 -> V_317 >> 1 ) > 1 )
goto V_316;
V_307 = F_99 ( V_8 ) ;
F_93 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_307 ) ) ;
V_312 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_313 = ( V_8 -> V_27 - V_307 ) * V_8 -> V_290 ;
V_314 = F_20 ( V_312 , V_313 ) ;
if ( V_314 >= F_30 (unsigned int, sk->sk_gso_max_size,
tp->xmit_size_goal_segs * tp->mss_cache) )
goto V_316;
if ( ( V_4 != F_164 ( V_2 ) ) && ( V_314 >= V_4 -> V_79 ) )
goto V_316;
V_315 = F_175 ( V_319 ) ;
if ( V_315 ) {
T_4 V_320 = F_20 ( V_8 -> V_321 , V_8 -> V_27 * V_8 -> V_290 ) ;
V_320 /= V_315 ;
if ( V_314 >= V_320 )
goto V_316;
} else {
if ( V_314 > F_176 ( V_8 ) * V_8 -> V_290 )
goto V_316;
}
if ( ! V_8 -> V_317 )
V_8 -> V_317 = 1 | ( V_318 << 1 ) ;
if ( V_313 < V_312 && V_313 < V_4 -> V_79 )
* V_298 = true ;
return true ;
V_316:
V_8 -> V_317 = 0 ;
return false ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_322 , * V_323 ;
int V_79 ;
int V_288 ;
int V_324 ;
int V_325 ;
int V_241 ;
if ( ! V_6 -> V_282 . V_283 ||
V_6 -> V_282 . V_288 ||
F_2 ( V_2 ) -> V_292 != V_293 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_173 || V_8 -> V_59 . V_125 )
return - 1 ;
V_241 = F_58 ( V_2 ) ;
V_288 = 2 * V_8 -> V_290 ;
V_324 = V_288 + ( V_8 -> V_326 + 1 ) * V_8 -> V_290 ;
if ( V_288 > F_150 ( V_2 , V_6 -> V_282 . V_285 ) ) {
return - 1 ;
}
if ( V_8 -> V_239 - V_8 -> V_11 < V_324 )
return - 1 ;
if ( V_8 -> V_321 < V_324 )
return - 1 ;
if ( F_107 ( V_8 -> V_11 + V_324 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_99 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_99 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_322 = F_131 ( V_2 , V_288 , V_182 ) ) == NULL )
return - 1 ;
V_2 -> V_240 += V_322 -> V_205 ;
F_115 ( V_2 , V_322 -> V_205 ) ;
V_4 = F_171 ( V_2 ) ;
F_5 ( V_322 ) -> V_80 = F_5 ( V_4 ) -> V_80 ;
F_5 ( V_322 ) -> V_12 = F_5 ( V_4 ) -> V_80 + V_288 ;
F_5 ( V_322 ) -> V_65 = V_234 ;
F_5 ( V_322 ) -> V_92 = 0 ;
V_322 -> V_91 = 0 ;
V_322 -> V_89 = V_4 -> V_89 ;
F_178 ( V_322 , V_4 , V_2 ) ;
V_79 = 0 ;
F_179 (skb, next, sk) {
V_325 = F_30 ( int , V_4 -> V_79 , V_288 - V_79 ) ;
if ( V_322 -> V_89 )
F_180 ( V_4 , 0 , F_133 ( V_322 , V_325 ) , V_325 ) ;
else
V_322 -> V_91 = F_181 ( V_4 , 0 ,
F_133 ( V_322 , V_325 ) ,
V_325 , V_322 -> V_91 ) ;
if ( V_4 -> V_79 <= V_325 ) {
F_5 ( V_322 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_182 ( V_4 , V_2 ) ;
F_183 ( V_2 , V_4 ) ;
} else {
F_5 ( V_322 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_96 | V_267 ) ;
if ( ! F_43 ( V_4 ) -> V_268 ) {
F_184 ( V_4 , V_325 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_185 ( V_4 -> V_183 ,
V_4 -> V_79 , 0 ) ;
} else {
F_138 ( V_4 , V_325 ) ;
F_116 ( V_2 , V_4 , V_241 ) ;
}
F_5 ( V_4 ) -> V_80 += V_325 ;
}
V_79 += V_325 ;
if ( V_79 >= V_288 )
break;
}
F_166 ( V_2 , V_322 , V_322 -> V_79 ) ;
F_5 ( V_322 ) -> V_154 = V_23 ;
if ( ! F_92 ( V_2 , V_322 , 1 , V_182 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_322 ) ;
V_6 -> V_282 . V_288 = F_151 ( V_2 , V_322 -> V_79 ) ;
V_8 -> V_327 . V_328 = F_5 ( V_322 ) -> V_80 ;
V_8 -> V_327 . V_329 = F_5 ( V_322 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_57 ( struct V_1 * V_2 , unsigned int V_241 , int V_181 ,
int V_330 , T_11 V_260 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_308 , V_331 ;
int V_311 ;
int V_332 ;
bool V_298 = false ;
V_331 = 0 ;
if ( ! V_330 ) {
V_332 = F_177 ( V_2 ) ;
if ( ! V_332 ) {
return false ;
} else if ( V_332 > 0 ) {
V_331 = 1 ;
}
}
while ( ( V_4 = F_171 ( V_2 ) ) ) {
unsigned int V_314 ;
V_308 = F_166 ( V_2 , V_4 , V_241 ) ;
F_93 ( ! V_308 ) ;
if ( F_48 ( V_8 -> V_333 ) && V_8 -> V_334 == V_335 ) {
F_5 ( V_4 ) -> V_154 = V_23 ;
goto V_333;
}
V_311 = F_165 ( V_8 , V_4 ) ;
if ( ! V_311 ) {
V_298 = true ;
if ( V_330 == 2 )
V_311 = 1 ;
else
break;
}
if ( F_48 ( ! F_168 ( V_8 , V_4 , V_241 ) ) )
break;
if ( V_308 == 1 ) {
if ( F_48 ( ! F_167 ( V_8 , V_4 , V_241 ,
( F_172 ( V_2 , V_4 ) ?
V_181 : V_310 ) ) ) )
break;
} else {
if ( ! V_330 &&
F_174 ( V_2 , V_4 , & V_298 ) )
break;
}
V_314 = F_29 (unsigned int, sysctl_tcp_limit_output_bytes,
sk->sk_pacing_rate >> 10 ) ;
if ( F_186 ( & V_2 -> V_206 ) > V_314 ) {
F_69 ( V_204 , & V_8 -> V_193 ) ;
F_187 () ;
if ( F_186 ( & V_2 -> V_206 ) > V_314 )
break;
}
V_314 = V_241 ;
if ( V_308 > 1 && ! F_46 ( V_8 ) )
V_314 = F_163 ( V_2 , V_4 , V_241 ,
F_30 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ,
V_181 ) ;
if ( V_4 -> V_79 > V_314 &&
F_48 ( F_173 ( V_2 , V_4 , V_314 , V_241 , V_260 ) ) )
break;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_48 ( F_92 ( V_2 , V_4 , 1 , V_260 ) ) )
break;
V_333:
F_1 ( V_2 , V_4 ) ;
F_161 ( V_8 , V_241 , V_4 ) ;
V_331 += F_6 ( V_4 ) ;
if ( V_330 )
break;
}
if ( F_50 ( V_331 ) ) {
if ( F_188 ( V_2 ) )
V_8 -> V_336 += V_331 ;
if ( V_330 != 2 )
F_189 ( V_2 ) ;
F_158 ( V_2 , V_298 ) ;
return false ;
}
return ( V_330 == 2 ) || ( ! V_8 -> V_10 && F_171 ( V_2 ) ) ;
}
bool F_189 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_337 , V_338 , V_339 ;
T_4 V_340 = F_190 ( V_8 -> V_341 >> 3 ) ;
if ( F_128 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_128 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_175 == V_342 )
return false ;
if ( V_6 -> V_13 != V_343 )
return false ;
if ( V_344 < 3 || ! V_8 -> V_341 || ! V_8 -> V_10 ||
! F_191 ( V_8 ) || F_2 ( V_2 ) -> V_292 != V_293 )
return false ;
if ( ( V_8 -> V_27 > F_99 ( V_8 ) ) &&
F_171 ( V_2 ) )
return false ;
V_337 = V_340 << 1 ;
if ( V_8 -> V_10 == 1 )
V_337 = F_29 ( T_4 , V_337 ,
( V_340 + ( V_340 >> 1 ) + V_345 ) ) ;
V_337 = F_29 ( T_4 , V_337 , F_192 ( 10 ) ) ;
V_338 = V_23 + V_337 ;
V_339 = ( T_4 ) F_2 ( V_2 ) -> V_346 ;
if ( ( T_3 ) ( V_338 - V_339 ) > 0 ) {
T_3 V_22 = V_339 - V_23 ;
if ( V_22 > 0 )
V_337 = V_22 ;
}
F_193 ( V_2 , V_15 , V_337 ,
V_347 ) ;
return true ;
}
static bool F_194 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_3 * V_348 = V_4 + 1 ;
if ( F_48 ( V_4 -> V_348 == V_349 &&
V_348 -> V_348 == V_350 ) ) {
F_195 ( F_9 ( V_2 ) ,
V_351 ) ;
return true ;
}
return false ;
}
void F_196 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_352 ;
int V_19 = F_58 ( V_2 ) ;
int V_213 = - 1 ;
if ( F_171 ( V_2 ) != NULL ) {
V_213 = F_57 ( V_2 , V_19 , V_353 , 2 , V_182 ) ;
goto V_354;
}
if ( V_8 -> V_355 )
goto V_354;
V_4 = F_164 ( V_2 ) ;
if ( F_128 ( ! V_4 ) )
goto V_354;
if ( F_194 ( V_2 , V_4 ) )
goto V_354;
V_352 = F_6 ( V_4 ) ;
if ( F_128 ( ! V_352 ) )
goto V_354;
if ( ( V_352 > 1 ) && ( V_4 -> V_79 > ( V_352 - 1 ) * V_19 ) ) {
if ( F_48 ( F_127 ( V_2 , V_4 , ( V_352 - 1 ) * V_19 , V_19 ,
V_182 ) ) )
goto V_354;
V_4 = F_164 ( V_2 ) ;
}
if ( F_128 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_354;
V_213 = F_197 ( V_2 , V_4 ) ;
if ( F_50 ( ! V_213 ) )
V_8 -> V_355 = V_8 -> V_11 ;
V_354:
F_193 ( V_2 , V_343 ,
F_2 ( V_2 ) -> V_30 ,
V_347 ) ;
if ( F_50 ( ! V_213 ) )
F_195 ( F_9 ( V_2 ) ,
V_356 ) ;
}
void F_198 ( struct V_1 * V_2 , unsigned int V_309 ,
int V_181 )
{
if ( F_48 ( V_2 -> V_175 == V_357 ) )
return;
if ( F_57 ( V_2 , V_309 , V_181 , 0 ,
F_199 ( V_2 , V_182 ) ) )
F_200 ( V_2 ) ;
}
void F_201 ( struct V_1 * V_2 , unsigned int V_241 )
{
struct V_3 * V_4 = F_171 ( V_2 ) ;
F_93 ( ! V_4 || V_4 -> V_79 < V_241 ) ;
F_57 ( V_2 , V_241 , V_310 , 1 , V_2 -> V_358 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_359 ;
int V_360 = F_202 ( V_2 ) ;
int V_361 = F_203 ( V_2 ) ;
int V_362 = F_30 ( int , V_8 -> V_46 , V_361 ) ;
int V_227 ;
if ( V_19 > V_362 )
V_19 = V_362 ;
if ( V_360 < ( V_362 >> 1 ) ) {
V_6 -> V_35 . V_363 = 0 ;
if ( F_204 ( V_2 ) )
V_8 -> V_364 = F_20 ( V_8 -> V_364 ,
4U * V_8 -> V_20 ) ;
V_360 = F_205 ( V_360 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_360 < ( V_361 >> 4 ) || V_360 < V_19 )
return 0 ;
}
if ( V_360 > V_8 -> V_364 )
V_360 = V_8 -> V_364 ;
V_227 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_227 = V_360 ;
if ( ( ( V_227 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_227 )
V_227 = ( ( ( V_227 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_227 <= V_360 - V_19 || V_227 > V_360 )
V_227 = ( V_360 / V_19 ) * V_19 ;
else if ( V_19 == V_362 &&
V_360 > V_227 + ( V_362 >> 1 ) )
V_227 = V_360 ;
}
return V_227 ;
}
static void F_206 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_365 = F_207 ( V_2 , V_4 ) ;
int V_366 , V_367 ;
V_366 = V_4 -> V_79 ;
V_367 = V_365 -> V_79 ;
F_93 ( F_6 ( V_4 ) != 1 || F_6 ( V_365 ) != 1 ) ;
F_208 ( V_2 , V_365 , V_4 ) ;
F_182 ( V_365 , V_2 ) ;
F_209 ( V_365 , F_133 ( V_4 , V_367 ) ,
V_367 ) ;
if ( V_365 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_210 ( V_4 -> V_91 , V_365 -> V_91 , V_366 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_365 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_365 ) -> V_65 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_365 ) -> V_92 & V_368 ;
F_211 ( V_8 ) ;
if ( V_365 == V_8 -> V_369 )
V_8 -> V_369 = V_4 ;
F_122 ( V_2 , V_365 , F_6 ( V_365 ) ) ;
F_183 ( V_2 , V_365 ) ;
}
static bool F_212 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_43 ( V_4 ) -> V_268 != 0 )
return false ;
if ( F_95 ( V_4 ) )
return false ;
if ( V_4 == F_171 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_247 )
return false ;
return true ;
}
static void F_213 ( struct V_1 * V_2 , struct V_3 * V_370 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_370 , * V_371 ;
bool V_372 = true ;
if ( ! V_373 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
return;
F_179 (skb, tmp, sk) {
if ( ! F_212 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_79 ;
if ( V_372 ) {
V_372 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_79 > F_214 ( V_370 ) )
break;
if ( F_107 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_206 ( V_2 , V_370 ) ;
}
}
int F_197 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_309 ;
int V_213 ;
if ( V_6 -> V_282 . V_288 ) {
V_6 -> V_282 . V_288 = 0 ;
}
if ( F_186 ( & V_2 -> V_206 ) >
F_20 ( V_2 -> V_240 + ( V_2 -> V_240 >> 2 ) , V_2 -> V_374 ) )
return - V_375 ;
if ( F_194 ( V_2 , V_4 ) )
return - V_376 ;
if ( F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_97 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_97 ) )
F_215 () ;
if ( F_144 ( V_2 , V_4 , V_8 -> V_97 - F_5 ( V_4 ) -> V_80 ) )
return - V_266 ;
}
if ( F_2 ( V_2 ) -> V_200 -> V_377 ( V_2 ) )
return - V_378 ;
V_309 = F_58 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_80 != V_8 -> V_97 )
return - V_375 ;
if ( V_4 -> V_79 > V_309 ) {
if ( F_127 ( V_2 , V_4 , V_309 , V_309 , V_182 ) )
return - V_266 ;
} else {
int V_379 = F_6 ( V_4 ) ;
if ( F_48 ( V_379 > 1 ) ) {
if ( F_130 ( V_4 , V_182 ) )
return - V_266 ;
F_166 ( V_2 , V_4 , V_309 ) ;
F_122 ( V_2 , V_4 , V_379 - F_6 ( V_4 ) ) ;
}
}
F_213 ( V_2 , V_4 , V_309 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_48 ( ( V_380 && ( ( unsigned long ) V_4 -> V_183 & 3 ) ) ||
F_216 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_322 = F_217 ( V_4 , V_381 ,
V_182 ) ;
V_213 = V_322 ? F_92 ( V_2 , V_322 , 0 , V_182 ) :
- V_215 ;
} else {
V_213 = F_92 ( V_2 , V_4 , 1 , V_182 ) ;
}
if ( F_50 ( ! V_213 ) ) {
F_5 ( V_4 ) -> V_92 |= V_368 ;
F_218 ( F_9 ( V_2 ) , V_382 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
F_195 ( F_9 ( V_2 ) , V_383 ) ;
V_8 -> V_384 ++ ;
}
return V_213 ;
}
int F_219 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_213 = F_197 ( V_2 , V_4 ) ;
if ( V_213 == 0 ) {
#if V_385 > 0
if ( F_5 ( V_4 ) -> V_92 & V_248 ) {
F_220 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_249 )
V_8 -> V_386 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_92 |= V_387 ;
V_8 -> V_249 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_388 )
V_8 -> V_388 = F_5 ( V_4 ) -> V_154 ;
F_5 ( V_4 ) -> V_225 = V_8 -> V_11 ;
} else if ( V_213 != - V_376 ) {
F_195 ( F_9 ( V_2 ) , V_389 ) ;
}
if ( V_8 -> V_390 < 0 )
V_8 -> V_390 = 0 ;
V_8 -> V_390 += F_6 ( V_4 ) ;
return V_213 ;
}
static bool F_221 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_292 != V_391 )
return false ;
if ( F_120 ( V_8 ) )
return false ;
if ( F_170 ( V_2 ) )
return false ;
return true ;
}
void F_222 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_392 = NULL ;
T_4 V_393 ;
int V_394 ;
int V_395 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_251 )
V_8 -> V_396 = V_8 -> V_97 ;
if ( V_8 -> V_369 ) {
V_4 = V_8 -> V_369 ;
V_393 = F_5 ( V_4 ) -> V_12 ;
if ( F_107 ( V_393 , V_8 -> V_396 ) )
V_393 = V_8 -> V_396 ;
} else {
V_4 = F_223 ( V_2 ) ;
V_393 = V_8 -> V_97 ;
}
F_224 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
if ( V_4 == F_171 ( V_2 ) )
break;
if ( V_392 == NULL )
V_8 -> V_369 = V_4 ;
if ( F_99 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_395 ) {
V_397:
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_121 ( V_8 ) ) )
break;
V_394 = V_398 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_396 ) ) {
V_8 -> V_396 = V_393 ;
if ( ! F_221 ( V_2 ) )
break;
if ( V_392 != NULL ) {
V_4 = V_392 ;
V_392 = NULL ;
}
V_395 = 1 ;
goto V_397;
} else if ( ! ( V_92 & V_250 ) ) {
if ( V_392 == NULL && ! ( V_92 & ( V_248 | V_247 ) ) )
V_392 = V_4 ;
continue;
} else {
V_393 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_292 != V_399 )
V_394 = V_400 ;
else
V_394 = V_401 ;
}
if ( V_92 & ( V_247 | V_248 ) )
continue;
if ( F_219 ( V_2 , V_4 ) )
return;
F_195 ( F_9 ( V_2 ) , V_394 ) ;
if ( F_188 ( V_2 ) )
V_8 -> V_336 += F_6 ( V_4 ) ;
if ( V_4 == F_223 ( V_2 ) )
F_193 ( V_2 , V_343 ,
F_2 ( V_2 ) -> V_30 ,
V_347 ) ;
}
}
void F_225 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_164 ( V_2 ) ;
int V_241 ;
V_241 = F_58 ( V_2 ) ;
if ( F_171 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_65 |= V_96 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_239 ++ ;
} else {
for (; ; ) {
V_4 = F_226 ( V_381 ,
V_2 -> V_358 ) ;
if ( V_4 )
break;
F_227 () ;
}
F_228 ( V_4 , V_381 ) ;
F_45 ( V_4 , V_8 -> V_239 ,
V_234 | V_96 ) ;
F_112 ( V_2 , V_4 ) ;
}
F_198 ( V_2 , V_241 , V_353 ) ;
}
void F_229 ( struct V_1 * V_2 , T_11 V_402 )
{
struct V_3 * V_4 ;
V_4 = F_230 ( V_381 , V_402 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_403 ) ;
return;
}
F_228 ( V_4 , V_381 ) ;
F_45 ( V_4 , F_10 ( V_2 ) ,
V_234 | V_404 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
if ( F_92 ( V_2 , V_4 , 0 , V_402 ) )
F_34 ( F_9 ( V_2 ) , V_403 ) ;
F_218 ( F_9 ( V_2 ) , V_405 ) ;
}
int F_231 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_223 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_65 & V_95 ) ) {
F_232 ( L_2 , V_406 ) ;
return - V_407 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_234 ) ) {
if ( F_95 ( V_4 ) ) {
struct V_3 * V_322 = F_233 ( V_4 , V_182 ) ;
if ( V_322 == NULL )
return - V_266 ;
F_182 ( V_4 , V_2 ) ;
F_113 ( V_322 ) ;
F_234 ( V_2 , V_322 ) ;
F_183 ( V_2 , V_4 ) ;
V_2 -> V_240 += V_322 -> V_205 ;
F_115 ( V_2 , V_322 -> V_205 ) ;
V_4 = V_322 ;
}
F_5 ( V_4 ) -> V_65 |= V_234 ;
F_36 ( F_3 ( V_2 ) , V_4 ) ;
}
F_5 ( V_4 ) -> V_154 = V_23 ;
return F_92 ( V_2 , V_4 , 1 , V_182 ) ;
}
struct V_3 * F_235 ( struct V_1 * V_2 , struct V_17 * V_18 ,
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
V_4 = F_236 ( V_2 , V_381 , 1 , V_182 ) ;
if ( F_48 ( ! V_4 ) ) {
F_237 ( V_18 ) ;
return NULL ;
}
F_228 ( V_4 , V_381 ) ;
F_238 ( V_4 , V_18 ) ;
F_239 ( V_4 , V_2 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_408 && V_8 -> V_59 . V_408 < V_19 )
V_19 = V_8 -> V_59 . V_408 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
#ifdef F_240
if ( F_48 ( V_73 -> V_409 ) )
F_5 ( V_4 ) -> V_154 = F_241 ( V_73 ) ;
else
#endif
F_5 ( V_4 ) -> V_154 = V_23 ;
V_212 = F_53 ( V_2 , V_73 , V_19 , V_4 , & V_101 , & V_143 ,
V_135 ) + sizeof( * V_75 ) ;
F_101 ( V_4 , V_212 ) ;
F_102 ( V_4 ) ;
V_75 = F_42 ( V_4 ) ;
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 -> V_410 = 1 ;
V_75 -> V_411 = 1 ;
F_38 ( V_73 , V_75 ) ;
V_75 -> V_221 = F_106 ( V_166 -> V_412 ) ;
V_75 -> V_223 = V_166 -> V_413 ;
F_45 ( V_4 , F_54 ( V_73 ) -> V_414 ,
V_95 | V_234 ) ;
V_75 -> V_80 = F_49 ( F_5 ( V_4 ) -> V_80 ) ;
V_75 -> V_225 = F_49 ( F_54 ( V_73 ) -> V_61 ) ;
V_75 -> V_227 = F_106 ( F_20 ( V_73 -> V_45 , 65535U ) ) ;
F_47 ( ( T_9 * ) ( V_75 + 1 ) , V_8 , & V_101 ) ;
V_75 -> V_415 = ( V_212 >> 2 ) ;
F_242 ( F_9 ( V_2 ) , V_235 ) ;
#ifdef F_52
if ( V_143 ) {
F_54 ( V_73 ) -> V_149 -> V_232 ( V_101 . V_107 ,
V_143 , NULL , V_73 , V_4 ) ;
}
#endif
return V_4 ;
}
static void F_243 ( struct V_1 * V_2 )
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
if ( V_8 -> V_59 . V_408 )
V_8 -> V_59 . V_279 = V_8 -> V_59 . V_408 ;
V_8 -> V_416 = 0 ;
F_152 ( V_2 ) ;
F_153 ( V_2 , F_155 ( V_18 ) ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_417 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_408 && V_8 -> V_59 . V_408 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_408 ;
F_244 ( V_2 ) ;
if ( V_2 -> V_418 & V_419 &&
( V_8 -> V_46 > F_203 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_203 ( V_2 ) ;
F_28 ( F_203 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_420 ? V_8 -> V_78 - sizeof( struct V_74 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_158 ,
& V_48 ,
F_23 ( V_18 , V_421 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_364 = V_8 -> V_45 ;
V_2 -> V_422 = 0 ;
F_245 ( V_2 , V_423 ) ;
V_8 -> V_321 = 0 ;
F_246 ( V_8 , 0 ) ;
V_8 -> V_97 = V_8 -> V_239 ;
V_8 -> V_301 = V_8 -> V_239 ;
V_8 -> V_98 = V_8 -> V_239 ;
V_8 -> V_11 = V_8 -> V_239 ;
if ( F_50 ( ! V_8 -> V_333 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_424 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_425 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_426 ;
F_2 ( V_2 ) -> V_427 = 0 ;
F_247 ( V_8 ) ;
}
static void F_248 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_169 * V_170 = F_5 ( V_4 ) ;
V_170 -> V_12 += V_4 -> V_79 ;
F_113 ( V_4 ) ;
F_249 ( V_2 , V_4 ) ;
V_2 -> V_240 += V_4 -> V_205 ;
F_115 ( V_2 , V_4 -> V_205 ) ;
V_8 -> V_239 = V_170 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_250 ( struct V_1 * V_2 , struct V_3 * V_410 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_428 = V_8 -> V_148 ;
int V_429 = 0 , V_50 , V_202 , V_213 = 0 , V_430 = V_428 -> V_183 -> V_431 ;
struct V_3 * V_432 = NULL , * V_183 ;
unsigned long V_433 = 0 ;
V_8 -> V_59 . V_279 = V_8 -> V_20 ;
F_251 ( V_2 , & V_8 -> V_59 . V_279 , & V_428 -> V_162 ,
& V_429 , & V_433 ) ;
if ( V_429 > 1 &&
F_252 ( V_318 , V_433 + ( 60 * V_434 << V_429 ) ) ) {
V_428 -> V_162 . V_79 = - 1 ;
goto V_435;
}
if ( V_436 & V_437 )
V_428 -> V_162 . V_79 = - 1 ;
else if ( V_428 -> V_162 . V_79 <= 0 )
goto V_435;
if ( V_8 -> V_59 . V_408 && V_8 -> V_59 . V_408 < V_8 -> V_59 . V_279 )
V_8 -> V_59 . V_279 = V_8 -> V_59 . V_408 ;
V_50 = F_148 ( V_2 , F_2 ( V_2 ) -> V_289 ) -
V_145 ;
V_50 = F_30 ( V_438 , V_50 , V_428 -> V_171 ) ;
V_50 = F_30 ( V_438 , V_50 , F_253 ( V_381 ) ) ;
V_432 = F_254 ( V_410 , V_381 , V_50 ,
V_2 -> V_358 ) ;
if ( V_432 == NULL )
goto V_435;
for ( V_202 = 0 ; V_202 < V_430 && V_432 -> V_79 < V_50 ; ++ V_202 ) {
struct V_439 * V_440 = & V_428 -> V_183 -> V_441 [ V_202 ] ;
unsigned char T_12 * V_442 = V_440 -> V_443 ;
int V_79 = V_440 -> V_444 ;
if ( V_432 -> V_79 + V_79 > V_50 )
V_79 = V_50 - V_432 -> V_79 ;
else if ( V_202 + 1 == V_430 )
V_428 -> V_183 = NULL ;
if ( F_255 ( V_432 , V_442 , V_79 ) )
goto V_435;
}
V_183 = F_96 ( V_432 , V_2 -> V_358 ) ;
if ( V_183 == NULL )
goto V_435;
F_5 ( V_183 ) -> V_80 ++ ;
F_5 ( V_183 ) -> V_65 &= ~ V_95 ;
F_5 ( V_183 ) -> V_65 = ( V_234 | V_267 ) ;
F_248 ( V_2 , V_183 ) ;
V_428 -> V_445 = V_183 -> V_79 ;
F_94 ( & V_410 -> V_214 ) ;
V_183 -> V_214 = V_410 -> V_214 ;
if ( F_92 ( V_2 , V_432 , 0 , V_2 -> V_358 ) == 0 ) {
V_8 -> V_432 = ( V_428 -> V_445 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_446;
}
V_432 = NULL ;
V_435:
if ( V_428 -> V_162 . V_79 > 0 )
V_428 -> V_162 . V_79 = 0 ;
V_213 = F_92 ( V_2 , V_410 , 1 , V_2 -> V_358 ) ;
if ( V_213 )
V_8 -> V_164 = 0 ;
F_256 ( V_432 ) ;
V_446:
V_428 -> V_162 . V_79 = - 1 ;
return V_213 ;
}
int F_257 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_261 ;
int V_213 ;
F_243 ( V_2 ) ;
if ( F_48 ( V_8 -> V_333 ) ) {
F_258 ( V_2 , NULL ) ;
return 0 ;
}
V_261 = F_226 ( V_381 + 15 , V_2 -> V_358 ) ;
if ( F_48 ( V_261 == NULL ) )
return - V_215 ;
F_228 ( V_261 , V_381 ) ;
F_45 ( V_261 , V_8 -> V_239 ++ , V_95 ) ;
V_8 -> V_388 = F_5 ( V_261 ) -> V_154 = V_23 ;
F_248 ( V_2 , V_261 ) ;
F_37 ( V_2 , V_261 ) ;
V_213 = V_8 -> V_148 ? F_250 ( V_2 , V_261 ) :
F_92 ( V_2 , V_261 , 1 , V_2 -> V_358 ) ;
if ( V_213 == - V_447 )
return V_213 ;
V_8 -> V_11 = V_8 -> V_239 ;
V_8 -> V_448 = V_8 -> V_239 ;
F_218 ( F_9 ( V_2 ) , V_449 ) ;
F_193 ( V_2 , V_343 ,
F_2 ( V_2 ) -> V_30 , V_347 ) ;
return 0 ;
}
void F_259 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_337 ;
if ( V_37 > V_450 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_451 = V_434 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_452 & V_453 ) )
V_451 = V_345 ;
if ( V_8 -> V_341 ) {
int V_340 = F_29 ( int , F_190 ( V_8 -> V_341 >> 3 ) ,
V_450 ) ;
if ( V_340 < V_451 )
V_451 = V_340 ;
}
V_37 = F_20 ( V_37 , V_451 ) ;
}
V_337 = V_318 + V_37 ;
if ( V_6 -> V_35 . V_452 & V_454 ) {
if ( V_6 -> V_35 . V_455 ||
F_260 ( V_6 -> V_35 . V_337 , V_318 + ( V_37 >> 2 ) ) ) {
F_261 ( V_2 ) ;
return;
}
if ( ! F_252 ( V_337 , V_6 -> V_35 . V_337 ) )
V_337 = V_6 -> V_35 . V_337 ;
}
V_6 -> V_35 . V_452 |= V_456 | V_454 ;
V_6 -> V_35 . V_337 = V_337 ;
F_262 ( V_2 , & V_6 -> V_457 , V_337 ) ;
}
void F_261 ( struct V_1 * V_2 )
{
struct V_3 * V_261 ;
if ( V_2 -> V_175 == V_357 )
return;
V_261 = F_230 ( V_381 , F_199 ( V_2 , V_182 ) ) ;
if ( V_261 == NULL ) {
F_263 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_458 ;
F_193 ( V_2 , V_41 ,
V_345 , V_347 ) ;
return;
}
F_228 ( V_261 , V_381 ) ;
F_45 ( V_261 , F_10 ( V_2 ) , V_234 ) ;
F_5 ( V_261 ) -> V_154 = V_23 ;
F_92 ( V_2 , V_261 , 0 , F_199 ( V_2 , V_182 ) ) ;
}
static int F_264 ( struct V_1 * V_2 , int V_459 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_230 ( V_381 , F_199 ( V_2 , V_182 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_228 ( V_4 , V_381 ) ;
F_45 ( V_4 , V_8 -> V_97 - ! V_459 , V_234 ) ;
F_5 ( V_4 ) -> V_154 = V_23 ;
return F_92 ( V_2 , V_4 , 0 , V_182 ) ;
}
void F_265 ( struct V_1 * V_2 )
{
if ( V_2 -> V_175 == V_460 ) {
F_3 ( V_2 ) -> V_461 = F_3 ( V_2 ) -> V_61 - 1 ;
F_264 ( V_2 , 0 ) ;
}
}
int F_266 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_175 == V_357 )
return - 1 ;
if ( ( V_4 = F_171 ( V_2 ) ) != NULL &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) ) {
int V_213 ;
unsigned int V_19 = F_58 ( V_2 ) ;
unsigned int V_462 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
if ( F_11 ( V_8 -> V_448 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_448 = F_5 ( V_4 ) -> V_12 ;
if ( V_462 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_80 ||
V_4 -> V_79 > V_19 ) {
V_462 = F_20 ( V_462 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_267 ;
if ( F_127 ( V_2 , V_4 , V_462 , V_19 , V_182 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_116 ( V_2 , V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_267 ;
F_5 ( V_4 ) -> V_154 = V_23 ;
V_213 = F_92 ( V_2 , V_4 , 1 , V_182 ) ;
if ( ! V_213 )
F_1 ( V_2 , V_4 ) ;
return V_213 ;
} else {
if ( F_267 ( V_8 -> V_98 , V_8 -> V_97 + 1 , V_8 -> V_97 + 0xFFFF ) )
F_264 ( V_2 , 1 ) ;
return F_264 ( V_2 , 0 ) ;
}
}
void F_268 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_213 ;
V_213 = F_266 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_171 ( V_2 ) ) {
V_6 -> V_463 = 0 ;
V_6 -> V_464 = 0 ;
return;
}
if ( V_213 <= 0 ) {
if ( V_6 -> V_464 < V_465 )
V_6 -> V_464 ++ ;
V_6 -> V_463 ++ ;
F_193 ( V_2 , V_466 ,
F_20 ( V_6 -> V_30 << V_6 -> V_464 , V_347 ) ,
V_347 ) ;
} else {
if ( ! V_6 -> V_463 )
V_6 -> V_463 = 1 ;
F_193 ( V_2 , V_466 ,
F_20 ( V_6 -> V_30 << V_6 -> V_464 ,
V_467 ) ,
V_347 ) ;
}
}
int F_269 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
const struct V_468 * V_469 = F_54 ( V_73 ) -> V_149 ;
struct V_470 V_238 ;
int V_471 ;
V_471 = V_469 -> V_472 ( V_2 , NULL , & V_238 , V_73 , 0 , NULL ) ;
if ( ! V_471 ) {
F_242 ( F_9 ( V_2 ) , V_382 ) ;
F_195 ( F_9 ( V_2 ) , V_383 ) ;
}
return V_471 ;
}
