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
if ( F_33 ( V_2 ) -> V_63 . V_64 == 1 ) {
F_4 ( V_4 ) -> V_58 |= V_62 | V_59 ;
V_6 -> V_60 = V_61 ;
}
}
static T_7 void
F_34 ( const struct V_65 * V_66 , struct V_67 * V_68 )
{
if ( F_35 ( V_66 ) -> V_69 )
V_68 -> V_70 = 1 ;
}
static inline void F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_60 & V_61 ) {
if ( V_4 -> V_72 != V_71 &&
! F_8 ( F_4 ( V_4 ) -> V_73 , V_6 -> V_9 ) ) {
F_37 ( V_2 ) ;
if ( V_6 -> V_60 & V_74 ) {
V_6 -> V_60 &= ~ V_74 ;
F_38 ( V_4 ) -> V_75 = 1 ;
F_39 ( V_4 ) -> V_76 |= V_77 ;
}
} else {
F_40 ( V_2 ) ;
}
if ( V_6 -> V_60 & V_78 )
F_38 ( V_4 ) -> V_70 = 1 ;
}
}
static void F_41 ( struct V_3 * V_4 , T_4 V_73 , T_8 V_79 )
{
V_4 -> V_80 = V_81 ;
V_4 -> V_82 = 0 ;
F_4 ( V_4 ) -> V_58 = V_79 ;
F_4 ( V_4 ) -> V_83 = 0 ;
F_39 ( V_4 ) -> V_84 = 1 ;
F_39 ( V_4 ) -> V_85 = 0 ;
F_39 ( V_4 ) -> V_76 = 0 ;
F_4 ( V_4 ) -> V_73 = V_73 ;
if ( V_79 & ( V_86 | V_87 ) )
V_73 ++ ;
F_4 ( V_4 ) -> V_10 = V_73 ;
}
static inline bool F_42 ( const struct V_5 * V_6 )
{
return V_6 -> V_88 != V_6 -> V_89 ;
}
static T_8 F_43 ( T_8 V_90 )
{
int V_91 ;
if ( V_90 > 0 )
return V_90 ;
V_91 = F_44 ( V_92 ) ;
if ( V_91 <= 0 )
return 0 ;
if ( V_91 <= V_93 )
return V_93 ;
if ( V_91 >= V_94 )
return V_94 ;
if ( V_91 & 1 )
V_91 ++ ;
return ( T_8 ) V_91 ;
}
static void F_45 ( T_9 * V_95 , struct V_5 * V_6 ,
struct V_96 * V_97 )
{
T_6 V_98 = V_97 -> V_98 ;
if ( F_46 ( V_99 & V_98 ) ) {
if ( F_46 ( V_100 & V_98 ) ) {
* V_95 ++ = F_47 ( ( V_101 << 24 ) |
( V_102 << 16 ) |
( V_103 << 8 ) |
V_104 ) ;
} else {
* V_95 ++ = F_47 ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_103 << 8 ) |
V_104 ) ;
}
V_98 &= ~ V_100 ;
V_97 -> V_106 = ( T_5 * ) V_95 ;
V_95 += 4 ;
}
if ( F_46 ( V_97 -> V_15 ) ) {
* V_95 ++ = F_47 ( ( V_107 << 24 ) |
( V_108 << 16 ) |
V_97 -> V_15 ) ;
}
if ( F_48 ( V_109 & V_98 ) ) {
if ( F_46 ( V_110 & V_98 ) ) {
* V_95 ++ = F_47 ( ( V_111 << 24 ) |
( V_112 << 16 ) |
( V_113 << 8 ) |
V_114 ) ;
V_98 &= ~ V_110 ;
} else {
* V_95 ++ = F_47 ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_113 << 8 ) |
V_114 ) ;
}
* V_95 ++ = F_47 ( V_97 -> V_115 ) ;
* V_95 ++ = F_47 ( V_97 -> V_116 ) ;
}
if ( F_46 ( V_100 & V_98 ) ) {
T_5 * V_117 = V_97 -> V_106 ;
T_8 V_91 = V_97 -> V_118 ;
if ( 0x2 & V_91 ) {
T_5 * V_119 = ( T_5 * ) V_95 ;
* V_119 ++ = V_101 ;
* V_119 ++ = V_102 + V_91 ;
* V_119 ++ = * V_117 ++ ;
* V_119 ++ = * V_117 ++ ;
V_95 ++ ;
V_91 -= 2 ;
} else {
* V_95 ++ = F_47 ( ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_101 << 8 ) |
V_102 ) +
V_91 ) ;
}
if ( V_91 > 0 ) {
memcpy ( V_95 , V_117 , V_91 ) ;
V_95 += ( V_91 / 4 ) ;
}
}
if ( F_46 ( V_110 & V_98 ) ) {
* V_95 ++ = F_47 ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_111 << 8 ) |
V_112 ) ;
}
if ( F_46 ( V_120 & V_98 ) ) {
* V_95 ++ = F_47 ( ( V_105 << 24 ) |
( V_121 << 16 ) |
( V_122 << 8 ) |
V_97 -> V_123 ) ;
}
if ( F_46 ( V_97 -> V_124 ) ) {
struct V_125 * V_126 = V_6 -> V_54 . V_127 ?
V_6 -> V_128 : V_6 -> V_129 ;
int V_130 ;
* V_95 ++ = F_47 ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_131 << 8 ) |
( V_132 + ( V_97 -> V_124 *
V_133 ) ) ) ;
for ( V_130 = 0 ; V_130 < V_97 -> V_124 ;
++ V_130 ) {
* V_95 ++ = F_47 ( V_126 [ V_130 ] . V_134 ) ;
* V_95 ++ = F_47 ( V_126 [ V_130 ] . V_10 ) ;
}
V_6 -> V_54 . V_127 = 0 ;
}
if ( F_46 ( V_135 & V_98 ) ) {
struct V_136 * V_137 = V_97 -> V_138 ;
* V_95 ++ = F_47 ( ( V_139 << 24 ) |
( ( V_140 + V_137 -> V_72 ) << 16 ) |
V_141 ) ;
memcpy ( V_95 , V_137 -> V_142 , V_137 -> V_72 ) ;
if ( ( V_137 -> V_72 & 3 ) == 2 ) {
T_8 * V_143 = ( ( T_8 * ) V_95 ) + V_137 -> V_72 ;
V_143 [ 0 ] = V_143 [ 1 ] = V_105 ;
}
V_95 += ( V_137 -> V_72 + 3 ) >> 2 ;
}
}
static unsigned int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_96 * V_97 ,
struct V_144 * * V_145 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_146 * V_147 = V_6 -> V_148 ;
unsigned int V_149 = V_150 ;
T_8 V_91 = ( ! V_6 -> V_54 . V_151 && V_147 != NULL ) ?
F_43 ( V_147 -> V_152 ) :
0 ;
struct V_153 * V_154 = V_6 -> V_155 ;
#ifdef F_50
* V_145 = V_6 -> V_156 -> V_157 ( V_2 , V_2 ) ;
if ( * V_145 ) {
V_97 -> V_98 |= V_99 ;
V_149 -= V_158 ;
}
#else
* V_145 = NULL ;
#endif
V_97 -> V_15 = F_10 ( V_2 ) ;
V_149 -= V_159 ;
if ( F_48 ( V_160 && * V_145 == NULL ) ) {
V_97 -> V_98 |= V_109 ;
V_97 -> V_115 = F_4 ( V_4 ) -> V_161 + V_6 -> V_162 ;
V_97 -> V_116 = V_6 -> V_54 . V_163 ;
V_149 -= V_164 ;
}
if ( F_48 ( V_165 ) ) {
V_97 -> V_123 = V_6 -> V_54 . V_43 ;
V_97 -> V_98 |= V_120 ;
V_149 -= V_166 ;
}
if ( F_48 ( V_167 ) ) {
V_97 -> V_98 |= V_110 ;
if ( F_46 ( ! ( V_109 & V_97 -> V_98 ) ) )
V_149 -= V_168 ;
}
if ( V_154 && V_154 -> V_169 . V_72 >= 0 ) {
T_4 V_170 = V_140 + V_154 -> V_169 . V_72 ;
V_170 = ( V_170 + 3 ) & ~ 3U ;
if ( V_149 >= V_170 ) {
V_97 -> V_98 |= V_135 ;
V_97 -> V_138 = & V_154 -> V_169 ;
V_149 -= V_170 ;
V_6 -> V_171 = 1 ;
}
}
if ( * V_145 == NULL &&
( V_109 & V_97 -> V_98 ) &&
V_91 > 0 ) {
int V_170 = V_102 + V_91 ;
if ( 0x2 & V_170 ) {
V_170 += 2 ;
if ( V_170 > V_149 ) {
V_91 -= 2 ;
V_170 -= 4 ;
}
}
while ( V_170 > V_149 && V_93 <= V_91 ) {
V_91 -= 4 ;
V_170 -= 4 ;
}
if ( V_93 <= V_91 ) {
V_97 -> V_98 |= V_100 ;
V_97 -> V_106 = ( T_5 * ) & V_147 -> V_172 [ 0 ] ;
V_97 -> V_118 = V_91 ;
V_147 -> V_152 = V_91 ;
if ( V_147 -> V_152 != V_147 -> V_173 ) {
F_51 ( & V_147 -> V_172 [ 0 ] ,
V_91 ) ;
V_147 -> V_173 = V_91 ;
}
V_149 -= V_170 ;
}
}
return V_150 - V_149 ;
}
static unsigned int F_52 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
unsigned int V_15 , struct V_3 * V_4 ,
struct V_96 * V_97 ,
struct V_144 * * V_145 ,
struct V_174 * V_175 ,
struct V_136 * V_137 )
{
struct V_176 * V_177 = F_35 ( V_66 ) ;
unsigned int V_149 = V_150 ;
T_8 V_178 = ( V_175 != NULL && ! V_175 -> V_151 ) ?
V_175 -> V_178 :
0 ;
#ifdef F_50
* V_145 = F_53 ( V_66 ) -> V_156 -> V_157 ( V_2 , V_66 ) ;
if ( * V_145 ) {
V_97 -> V_98 |= V_99 ;
V_149 -= V_158 ;
V_177 -> V_179 &= ! V_177 -> V_180 ;
}
#else
* V_145 = NULL ;
#endif
V_97 -> V_15 = V_15 ;
V_149 -= V_159 ;
if ( F_48 ( V_177 -> V_42 ) ) {
V_97 -> V_123 = V_177 -> V_43 ;
V_97 -> V_98 |= V_120 ;
V_149 -= V_166 ;
}
if ( F_48 ( V_177 -> V_179 ) ) {
V_97 -> V_98 |= V_109 ;
V_97 -> V_115 = F_4 ( V_4 ) -> V_161 ;
V_97 -> V_116 = V_66 -> V_163 ;
V_149 -= V_164 ;
}
if ( F_48 ( V_177 -> V_180 ) ) {
V_97 -> V_98 |= V_110 ;
if ( F_46 ( ! V_177 -> V_179 ) )
V_149 -= V_168 ;
}
if ( V_137 != NULL ) {
T_4 V_170 = V_140 + V_137 -> V_72 ;
V_170 = ( V_170 + 3 ) & ~ 3U ;
if ( V_149 >= V_170 ) {
V_97 -> V_98 |= V_135 ;
V_97 -> V_138 = V_137 ;
V_149 -= V_170 ;
}
}
if ( * V_145 == NULL &&
V_177 -> V_179 &&
V_178 > V_102 ) {
int V_170 = V_178 ;
if ( 0x2 & V_170 ) {
V_170 += 2 ;
}
if ( V_170 <= V_149 ) {
V_97 -> V_98 |= V_100 ;
V_97 -> V_118 = V_178 - V_102 ;
V_149 -= V_170 ;
} else {
V_175 -> V_151 = 1 ;
V_97 -> V_118 = 0 ;
}
}
return V_150 - V_149 ;
}
static unsigned int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_96 * V_97 ,
struct V_144 * * V_145 )
{
struct V_181 * V_182 = V_4 ? F_4 ( V_4 ) : NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_183 = 0 ;
unsigned int V_184 ;
#ifdef F_50
* V_145 = V_6 -> V_156 -> V_157 ( V_2 , V_2 ) ;
if ( F_46 ( * V_145 ) ) {
V_97 -> V_98 |= V_99 ;
V_183 += V_158 ;
}
#else
* V_145 = NULL ;
#endif
if ( F_48 ( V_6 -> V_54 . V_179 ) ) {
V_97 -> V_98 |= V_109 ;
V_97 -> V_115 = V_182 ? V_182 -> V_161 + V_6 -> V_162 : 0 ;
V_97 -> V_116 = V_6 -> V_54 . V_163 ;
V_183 += V_164 ;
}
V_184 = V_6 -> V_54 . V_185 + V_6 -> V_54 . V_127 ;
if ( F_46 ( V_184 ) ) {
const unsigned int V_149 = V_150 - V_183 ;
V_97 -> V_124 =
F_26 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_183 += V_186 +
V_97 -> V_124 * V_133 ;
}
return V_183 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_187 ) &
( V_188 | V_189 | V_190 |
V_191 | V_192 ) )
F_56 ( V_2 , F_57 ( V_2 ) , 0 , 0 , V_193 ) ;
}
static void F_58 ( unsigned long V_194 )
{
struct V_195 * V_196 = (struct V_195 * ) V_194 ;
F_59 ( V_197 ) ;
unsigned long V_79 ;
struct V_198 * V_199 , * V_200 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
F_60 ( V_79 ) ;
F_61 ( & V_196 -> V_201 , & V_197 ) ;
F_62 ( V_79 ) ;
F_63 (q, n, &list) {
V_6 = F_64 ( V_199 , struct V_5 , V_202 ) ;
F_65 ( & V_6 -> V_202 ) ;
V_2 = (struct V_1 * ) V_6 ;
F_66 ( V_2 ) ;
if ( ! F_67 ( V_2 ) ) {
F_55 ( V_2 ) ;
} else {
F_68 ( V_203 , & V_6 -> V_204 ) ;
}
F_69 ( V_2 ) ;
F_70 ( V_205 , & V_6 -> V_204 ) ;
F_71 ( V_2 ) ;
}
}
void F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_79 , V_206 ;
do {
V_79 = V_6 -> V_204 ;
if ( ! ( V_79 & V_207 ) )
return;
V_206 = V_79 & ~ V_207 ;
} while ( F_73 ( & V_6 -> V_204 , V_79 , V_206 ) != V_79 );
if ( V_79 & ( 1UL << V_203 ) )
F_55 ( V_2 ) ;
if ( V_79 & ( 1UL << V_208 ) ) {
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( V_79 & ( 1UL << V_209 ) ) {
F_76 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( V_79 & ( 1UL << V_210 ) ) {
V_2 -> V_211 -> V_212 ( V_2 ) ;
F_75 ( V_2 ) ;
}
}
void T_10 F_77 ( void )
{
int V_213 ;
F_78 (i) {
struct V_195 * V_196 = & F_79 ( V_195 , V_213 ) ;
F_80 ( & V_196 -> V_201 ) ;
F_81 ( & V_196 -> V_214 ,
F_58 ,
( unsigned long ) V_196 ) ;
}
}
static void F_82 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_83 ( V_215 , & V_6 -> V_204 ) &&
! F_84 ( V_205 , & V_6 -> V_204 ) ) {
unsigned long V_79 ;
struct V_195 * V_196 ;
F_85 ( V_4 -> V_216 - 1 , & V_2 -> V_217 ) ;
F_60 ( V_79 ) ;
V_196 = & F_86 ( V_195 ) ;
F_87 ( & V_6 -> V_202 , & V_196 -> V_201 ) ;
F_88 ( & V_196 -> V_214 ) ;
F_62 ( V_79 ) ;
} else {
F_89 ( V_4 ) ;
}
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_218 ,
T_11 V_219 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_220 * V_221 ;
struct V_5 * V_6 ;
struct V_181 * V_182 ;
struct V_96 V_97 ;
unsigned int V_222 , V_223 ;
struct V_144 * V_145 ;
struct V_67 * V_68 ;
int V_224 ;
F_91 ( ! V_4 || ! F_5 ( V_4 ) ) ;
if ( V_30 -> V_225 -> V_79 & V_226 )
F_92 ( V_4 ) ;
if ( F_48 ( V_218 ) ) {
if ( F_46 ( F_93 ( V_4 ) ) )
V_4 = F_94 ( V_4 , V_219 ) ;
else
V_4 = F_95 ( V_4 , V_219 ) ;
if ( F_46 ( ! V_4 ) )
return - V_227 ;
}
V_221 = F_96 ( V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_182 = F_4 ( V_4 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
if ( F_46 ( V_182 -> V_58 & V_86 ) )
V_222 = F_49 ( V_2 , V_4 , & V_97 , & V_145 ) ;
else
V_222 = F_54 ( V_2 , V_4 , & V_97 ,
& V_145 ) ;
V_223 = V_222 + sizeof( struct V_67 ) ;
if ( F_97 ( V_6 ) == 0 ) {
F_15 ( V_2 , V_228 ) ;
V_4 -> V_229 = 1 ;
} else
V_4 -> V_229 = 0 ;
F_98 ( V_4 , V_223 ) ;
F_99 ( V_4 ) ;
F_100 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_230 = ( V_231 > 0 ) ?
F_82 : F_89 ;
F_101 ( V_4 -> V_216 , & V_2 -> V_217 ) ;
V_68 = F_38 ( V_4 ) ;
V_68 -> V_232 = V_221 -> V_233 ;
V_68 -> V_234 = V_221 -> V_235 ;
V_68 -> V_73 = F_47 ( V_182 -> V_73 ) ;
V_68 -> V_236 = F_47 ( V_6 -> V_56 ) ;
* ( ( ( V_237 * ) V_68 ) + 6 ) = F_102 ( ( ( V_223 >> 2 ) << 12 ) |
V_182 -> V_58 ) ;
if ( F_46 ( V_182 -> V_58 & V_86 ) ) {
V_68 -> V_238 = F_102 ( F_17 ( V_6 -> V_40 , 65535U ) ) ;
} else {
V_68 -> V_238 = F_102 ( F_27 ( V_2 ) ) ;
}
V_68 -> V_239 = 0 ;
V_68 -> V_240 = 0 ;
if ( F_46 ( F_42 ( V_6 ) && F_8 ( V_182 -> V_73 , V_6 -> V_89 ) ) ) {
if ( F_8 ( V_6 -> V_89 , V_182 -> V_73 + 0x10000 ) ) {
V_68 -> V_240 = F_102 ( V_6 -> V_89 - V_182 -> V_73 ) ;
V_68 -> V_241 = 1 ;
} else if ( F_103 ( V_182 -> V_73 + 0xFFFF , V_6 -> V_9 ) ) {
V_68 -> V_240 = F_102 ( 0xFFFF ) ;
V_68 -> V_241 = 1 ;
}
}
F_45 ( ( T_9 * ) ( V_68 + 1 ) , V_6 , & V_97 ) ;
if ( F_48 ( ( V_182 -> V_58 & V_86 ) == 0 ) )
F_36 ( V_2 , V_4 , V_223 ) ;
#ifdef F_50
if ( V_145 ) {
F_104 ( V_2 , V_242 ) ;
V_6 -> V_156 -> V_243 ( V_97 . V_106 ,
V_145 , V_2 , NULL , V_4 ) ;
}
#endif
V_30 -> V_244 -> V_245 ( V_2 , V_4 ) ;
if ( F_48 ( V_182 -> V_58 & V_246 ) )
F_21 ( V_2 , F_5 ( V_4 ) ) ;
if ( V_4 -> V_72 != V_223 )
F_20 ( V_6 , V_2 ) ;
if ( F_103 ( V_182 -> V_10 , V_6 -> V_9 ) || V_182 -> V_73 == V_182 -> V_10 )
F_105 ( F_33 ( V_2 ) , V_247 ,
F_5 ( V_4 ) ) ;
V_224 = V_30 -> V_244 -> V_248 ( V_4 , & V_221 -> V_249 . V_250 ) ;
if ( F_48 ( V_224 <= 0 ) )
return V_224 ;
F_106 ( V_2 , 1 ) ;
return F_107 ( V_224 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_251 = F_4 ( V_4 ) -> V_10 ;
F_109 ( V_4 ) ;
F_110 ( V_2 , V_4 ) ;
V_2 -> V_252 += V_4 -> V_216 ;
F_111 ( V_2 , V_4 -> V_216 ) ;
}
static void F_112 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_253 )
{
if ( V_4 -> V_72 <= V_253 || ! F_113 ( V_2 ) ||
V_4 -> V_80 == V_254 ) {
F_39 ( V_4 ) -> V_84 = 1 ;
F_39 ( V_4 ) -> V_85 = 0 ;
F_39 ( V_4 ) -> V_76 = 0 ;
} else {
F_39 ( V_4 ) -> V_84 = F_114 ( V_4 -> V_72 , V_253 ) ;
F_39 ( V_4 ) -> V_85 = V_253 ;
F_39 ( V_4 ) -> V_76 = V_2 -> V_255 ;
}
}
static void F_115 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_256 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_257 || F_116 ( V_6 ) )
return;
if ( F_103 ( F_117 ( V_6 ) , F_4 ( V_4 ) -> V_73 ) )
V_6 -> V_258 -= V_256 ;
}
static void F_118 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_256 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 -= V_256 ;
if ( F_4 ( V_4 ) -> V_83 & V_259 )
V_6 -> V_257 -= V_256 ;
if ( F_4 ( V_4 ) -> V_83 & V_260 )
V_6 -> V_261 -= V_256 ;
if ( F_4 ( V_4 ) -> V_83 & V_262 )
V_6 -> V_263 -= V_256 ;
if ( F_116 ( V_6 ) && V_256 > 0 )
V_6 -> V_257 -= F_26 ( T_4 , V_6 -> V_257 , V_256 ) ;
F_115 ( V_2 , V_4 , V_256 ) ;
if ( V_6 -> V_264 &&
F_8 ( F_4 ( V_4 ) -> V_73 , F_4 ( V_6 -> V_264 ) -> V_73 ) &&
( F_119 ( V_6 ) || ( F_4 ( V_4 ) -> V_83 & V_259 ) ) )
V_6 -> V_265 -= V_256 ;
F_120 ( V_6 ) ;
}
int F_121 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_72 ,
unsigned int V_253 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_266 ;
int V_267 , V_268 ;
int V_269 ;
T_8 V_79 ;
if ( F_122 ( V_72 > V_4 -> V_72 ) )
return - V_270 ;
V_267 = F_123 ( V_4 ) - V_72 ;
if ( V_267 < 0 )
V_267 = 0 ;
if ( F_93 ( V_4 ) &&
F_124 ( V_4 ) &&
F_125 ( V_4 , 0 , 0 , V_193 ) )
return - V_271 ;
V_266 = F_126 ( V_2 , V_267 , V_193 ) ;
if ( V_266 == NULL )
return - V_271 ;
V_2 -> V_252 += V_266 -> V_216 ;
F_111 ( V_2 , V_266 -> V_216 ) ;
V_269 = V_4 -> V_72 - V_72 - V_267 ;
V_266 -> V_216 += V_269 ;
V_4 -> V_216 -= V_269 ;
F_4 ( V_266 ) -> V_73 = F_4 ( V_4 ) -> V_73 + V_72 ;
F_4 ( V_266 ) -> V_10 = F_4 ( V_4 ) -> V_10 ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_266 ) -> V_73 ;
V_79 = F_4 ( V_4 ) -> V_58 ;
F_4 ( V_4 ) -> V_58 = V_79 & ~ ( V_87 | V_272 ) ;
F_4 ( V_266 ) -> V_58 = V_79 ;
F_4 ( V_266 ) -> V_83 = F_4 ( V_4 ) -> V_83 ;
if ( ! F_39 ( V_4 ) -> V_273 && V_4 -> V_80 != V_81 ) {
V_266 -> V_82 = F_127 ( V_4 -> V_194 + V_72 ,
F_128 ( V_266 , V_267 ) ,
V_267 , 0 ) ;
F_129 ( V_4 , V_72 ) ;
V_4 -> V_82 = F_130 ( V_4 -> V_82 , V_266 -> V_82 , V_72 ) ;
} else {
V_4 -> V_80 = V_81 ;
F_131 ( V_4 , V_266 , V_72 ) ;
}
V_266 -> V_80 = V_4 -> V_80 ;
F_4 ( V_266 ) -> V_161 = F_4 ( V_4 ) -> V_161 ;
V_266 -> V_274 = V_4 -> V_274 ;
V_268 = F_5 ( V_4 ) ;
F_112 ( V_2 , V_4 , V_253 ) ;
F_112 ( V_2 , V_266 , V_253 ) ;
if ( ! F_8 ( V_6 -> V_9 , F_4 ( V_266 ) -> V_10 ) ) {
int V_275 = V_268 - F_5 ( V_4 ) -
F_5 ( V_266 ) ;
if ( V_275 )
F_118 ( V_2 , V_4 , V_275 ) ;
}
F_109 ( V_266 ) ;
F_132 ( V_4 , V_266 , V_2 ) ;
return 0 ;
}
static void F_133 ( struct V_3 * V_4 , int V_72 )
{
int V_213 , V_276 , V_277 ;
V_277 = F_26 ( int , V_72 , F_123 ( V_4 ) ) ;
if ( V_277 ) {
F_134 ( V_4 , V_277 ) ;
V_72 -= V_277 ;
if ( ! V_72 )
return;
}
V_277 = V_72 ;
V_276 = 0 ;
for ( V_213 = 0 ; V_213 < F_39 ( V_4 ) -> V_273 ; V_213 ++ ) {
int V_183 = F_135 ( & F_39 ( V_4 ) -> V_278 [ V_213 ] ) ;
if ( V_183 <= V_277 ) {
F_136 ( V_4 , V_213 ) ;
V_277 -= V_183 ;
} else {
F_39 ( V_4 ) -> V_278 [ V_276 ] = F_39 ( V_4 ) -> V_278 [ V_213 ] ;
if ( V_277 ) {
F_39 ( V_4 ) -> V_278 [ V_276 ] . V_279 += V_277 ;
F_137 ( & F_39 ( V_4 ) -> V_278 [ V_276 ] , V_277 ) ;
V_277 = 0 ;
}
V_276 ++ ;
}
}
F_39 ( V_4 ) -> V_273 = V_276 ;
F_138 ( V_4 ) ;
V_4 -> V_280 -= V_72 ;
V_4 -> V_72 = V_4 -> V_280 ;
}
int F_139 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_72 )
{
if ( F_140 ( V_4 , V_193 ) )
return - V_271 ;
F_133 ( V_4 , V_72 ) ;
F_4 ( V_4 ) -> V_73 += V_72 ;
V_4 -> V_80 = V_81 ;
V_4 -> V_216 -= V_72 ;
V_2 -> V_252 -= V_72 ;
F_141 ( V_2 , V_72 ) ;
F_142 ( V_2 , V_281 ) ;
if ( F_5 ( V_4 ) > 1 )
F_112 ( V_2 , V_4 , F_143 ( V_4 ) ) ;
return 0 ;
}
static inline int F_144 ( struct V_1 * V_2 , int V_282 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_253 ;
V_253 = V_282 - V_30 -> V_244 -> V_283 - sizeof( struct V_67 ) ;
if ( V_30 -> V_244 -> V_284 ) {
const struct V_13 * V_14 = F_11 ( V_2 ) ;
if ( V_14 && F_145 ( V_14 ) )
V_253 -= V_30 -> V_244 -> V_284 ;
}
if ( V_253 > V_6 -> V_54 . V_285 )
V_253 = V_6 -> V_54 . V_285 ;
V_253 -= V_30 -> V_286 ;
if ( V_253 < 48 )
V_253 = 48 ;
return V_253 ;
}
int F_146 ( struct V_1 * V_2 , int V_282 )
{
return F_144 ( V_2 , V_282 ) -
( F_2 ( V_2 ) -> V_71 - sizeof( struct V_67 ) ) ;
}
int F_147 ( struct V_1 * V_2 , int V_15 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_287 ;
V_287 = V_15 +
V_6 -> V_71 +
V_30 -> V_286 +
V_30 -> V_244 -> V_283 ;
if ( V_30 -> V_244 -> V_284 ) {
const struct V_13 * V_14 = F_11 ( V_2 ) ;
if ( V_14 && F_145 ( V_14 ) )
V_287 += V_30 -> V_244 -> V_284 ;
}
return V_287 ;
}
void F_148 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
V_30 -> V_288 . V_289 = V_290 > 1 ;
V_30 -> V_288 . V_291 = V_6 -> V_54 . V_285 + sizeof( struct V_67 ) +
V_30 -> V_244 -> V_283 ;
V_30 -> V_288 . V_292 = F_147 ( V_2 , V_293 ) ;
V_30 -> V_288 . V_294 = 0 ;
}
unsigned int F_149 ( struct V_1 * V_2 , T_4 V_282 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_253 ;
if ( V_30 -> V_288 . V_291 > V_282 )
V_30 -> V_288 . V_291 = V_282 ;
V_253 = F_146 ( V_2 , V_282 ) ;
V_253 = F_150 ( V_6 , V_253 ) ;
V_30 -> V_295 = V_282 ;
if ( V_30 -> V_288 . V_289 )
V_253 = F_17 ( V_253 , F_146 ( V_2 , V_30 -> V_288 . V_292 ) ) ;
V_6 -> V_296 = V_253 ;
return V_253 ;
}
unsigned int F_57 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = F_11 ( V_2 ) ;
T_4 V_253 ;
unsigned int V_297 ;
struct V_96 V_97 ;
struct V_144 * V_145 ;
V_253 = V_6 -> V_296 ;
if ( V_14 ) {
T_4 V_287 = F_151 ( V_14 ) ;
if ( V_287 != F_18 ( V_2 ) -> V_295 )
V_253 = F_149 ( V_2 , V_287 ) ;
}
V_297 = F_54 ( V_2 , NULL , & V_97 , & V_145 ) +
sizeof( struct V_67 ) ;
if ( V_297 != V_6 -> V_71 ) {
int V_18 = ( int ) V_297 - V_6 -> V_71 ;
V_253 -= V_18 ;
}
return V_253 ;
}
static void F_152 ( struct V_1 * V_2 )
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
F_153 ( V_2 ) ;
}
}
static unsigned int F_154 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_253 , unsigned int V_298 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_299 , V_238 , V_300 ;
V_238 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_73 ;
V_300 = V_253 * V_298 ;
if ( F_48 ( V_300 <= V_238 && V_4 != F_155 ( V_2 ) ) )
return V_300 ;
V_299 = F_17 ( V_4 -> V_72 , V_238 ) ;
if ( V_300 <= V_299 )
return V_300 ;
return V_299 - V_299 % V_253 ;
}
static inline unsigned int F_156 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_4 V_301 , V_22 ;
if ( ( F_4 ( V_4 ) -> V_58 & V_87 ) &&
F_5 ( V_4 ) == 1 )
return 1 ;
V_301 = F_97 ( V_6 ) ;
V_22 = V_6 -> V_23 ;
if ( V_301 < V_22 )
return ( V_22 - V_301 ) ;
return 0 ;
}
static int F_157 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_253 )
{
int V_302 = F_5 ( V_4 ) ;
if ( ! V_302 || ( V_302 > 1 && F_143 ( V_4 ) != V_253 ) ) {
F_112 ( V_2 , V_4 , V_253 ) ;
V_302 = F_5 ( V_4 ) ;
}
return V_302 ;
}
static inline bool F_158 ( const struct V_5 * V_6 )
{
return F_103 ( V_6 -> V_303 , V_6 -> V_88 ) &&
! F_103 ( V_6 -> V_303 , V_6 -> V_9 ) ;
}
static inline bool F_159 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
unsigned int V_253 , int V_304 )
{
return V_4 -> V_72 < V_253 &&
( ( V_304 & V_305 ) ||
( ! V_304 && V_6 -> V_8 && F_158 ( V_6 ) ) ) ;
}
static inline bool F_160 ( const struct V_5 * V_6 , const struct V_3 * V_4 ,
unsigned int V_306 , int V_304 )
{
if ( V_304 & V_307 )
return true ;
if ( F_42 ( V_6 ) || ( V_6 -> V_11 == 2 ) ||
( F_4 ( V_4 ) -> V_58 & V_87 ) )
return true ;
if ( ! F_159 ( V_6 , V_4 , V_306 , V_304 ) )
return true ;
return false ;
}
static bool F_161 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
unsigned int V_306 )
{
T_4 V_10 = F_4 ( V_4 ) -> V_10 ;
if ( V_4 -> V_72 > V_306 )
V_10 = F_4 ( V_4 ) -> V_73 + V_306 ;
return ! F_103 ( V_10 , F_9 ( V_6 ) ) ;
}
static unsigned int F_162 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_306 , int V_304 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_308 ;
F_157 ( V_2 , V_4 , V_306 ) ;
if ( ! F_160 ( V_6 , V_4 , V_306 , V_304 ) )
return 0 ;
V_308 = F_156 ( V_6 , V_4 ) ;
if ( V_308 && ! F_161 ( V_6 , V_4 , V_306 ) )
V_308 = 0 ;
return V_308 ;
}
bool F_163 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_164 ( V_2 ) ;
return V_4 &&
F_162 ( V_2 , V_4 , F_57 ( V_2 ) ,
( F_165 ( V_2 , V_4 ) ?
V_6 -> V_304 : V_307 ) ) ;
}
static int F_166 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_72 ,
unsigned int V_253 , T_11 V_309 )
{
struct V_3 * V_266 ;
int V_269 = V_4 -> V_72 - V_72 ;
T_8 V_79 ;
if ( V_4 -> V_72 != V_4 -> V_280 )
return F_121 ( V_2 , V_4 , V_72 , V_253 ) ;
V_266 = F_126 ( V_2 , 0 , V_309 ) ;
if ( F_46 ( V_266 == NULL ) )
return - V_271 ;
V_2 -> V_252 += V_266 -> V_216 ;
F_111 ( V_2 , V_266 -> V_216 ) ;
V_266 -> V_216 += V_269 ;
V_4 -> V_216 -= V_269 ;
F_4 ( V_266 ) -> V_73 = F_4 ( V_4 ) -> V_73 + V_72 ;
F_4 ( V_266 ) -> V_10 = F_4 ( V_4 ) -> V_10 ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_266 ) -> V_73 ;
V_79 = F_4 ( V_4 ) -> V_58 ;
F_4 ( V_4 ) -> V_58 = V_79 & ~ ( V_87 | V_272 ) ;
F_4 ( V_266 ) -> V_58 = V_79 ;
F_4 ( V_266 ) -> V_83 = 0 ;
V_266 -> V_80 = V_4 -> V_80 = V_81 ;
F_131 ( V_4 , V_266 , V_72 ) ;
F_112 ( V_2 , V_4 , V_253 ) ;
F_112 ( V_2 , V_266 , V_253 ) ;
F_109 ( V_266 ) ;
F_132 ( V_4 , V_266 , V_2 ) ;
return 0 ;
}
static bool F_167 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
T_4 V_310 , V_311 , V_312 , V_301 ;
int V_313 ;
if ( F_4 ( V_4 ) -> V_58 & V_87 )
goto V_314;
if ( V_30 -> V_315 != V_316 )
goto V_314;
if ( V_6 -> V_317 &&
( ( ( T_4 ) V_318 << 1 ) >> 1 ) - ( V_6 -> V_317 >> 1 ) > 1 )
goto V_314;
V_301 = F_97 ( V_6 ) ;
F_91 ( F_5 ( V_4 ) <= 1 || ( V_6 -> V_23 <= V_301 ) ) ;
V_310 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_73 ;
V_311 = ( V_6 -> V_23 - V_301 ) * V_6 -> V_296 ;
V_312 = F_17 ( V_310 , V_311 ) ;
if ( V_312 >= F_26 (unsigned int, sk->sk_gso_max_size,
sk->sk_gso_max_segs * tp->mss_cache) )
goto V_314;
if ( ( V_4 != F_155 ( V_2 ) ) && ( V_312 >= V_4 -> V_72 ) )
goto V_314;
V_313 = F_44 ( V_319 ) ;
if ( V_313 ) {
T_4 V_320 = F_17 ( V_6 -> V_321 , V_6 -> V_23 * V_6 -> V_296 ) ;
V_320 /= V_313 ;
if ( V_312 >= V_320 )
goto V_314;
} else {
if ( V_312 > F_168 ( V_6 ) * V_6 -> V_296 )
goto V_314;
}
if ( ! V_6 -> V_317 )
V_6 -> V_317 = 1 | ( V_318 << 1 ) ;
return true ;
V_314:
V_6 -> V_317 = 0 ;
return false ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_3 * V_4 , * V_322 , * V_323 ;
int V_72 ;
int V_294 ;
int V_324 ;
int V_325 ;
int V_253 ;
if ( ! V_30 -> V_288 . V_289 ||
V_30 -> V_288 . V_294 ||
F_18 ( V_2 ) -> V_315 != V_316 ||
V_6 -> V_23 < 11 ||
V_6 -> V_54 . V_185 || V_6 -> V_54 . V_127 )
return - 1 ;
V_253 = F_57 ( V_2 ) ;
V_294 = 2 * V_6 -> V_296 ;
V_324 = V_294 + ( V_6 -> V_326 + 1 ) * V_6 -> V_296 ;
if ( V_294 > F_146 ( V_2 , V_30 -> V_288 . V_291 ) ) {
return - 1 ;
}
if ( V_6 -> V_251 - V_6 -> V_9 < V_324 )
return - 1 ;
if ( V_6 -> V_321 < V_324 )
return - 1 ;
if ( F_103 ( V_6 -> V_9 + V_324 , F_9 ( V_6 ) ) )
return 0 ;
if ( F_97 ( V_6 ) + 2 > V_6 -> V_23 ) {
if ( ! F_97 ( V_6 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_322 = F_126 ( V_2 , V_294 , V_193 ) ) == NULL )
return - 1 ;
V_2 -> V_252 += V_322 -> V_216 ;
F_111 ( V_2 , V_322 -> V_216 ) ;
V_4 = F_164 ( V_2 ) ;
F_4 ( V_322 ) -> V_73 = F_4 ( V_4 ) -> V_73 ;
F_4 ( V_322 ) -> V_10 = F_4 ( V_4 ) -> V_73 + V_294 ;
F_4 ( V_322 ) -> V_58 = V_246 ;
F_4 ( V_322 ) -> V_83 = 0 ;
V_322 -> V_82 = 0 ;
V_322 -> V_80 = V_4 -> V_80 ;
F_170 ( V_322 , V_4 , V_2 ) ;
V_72 = 0 ;
F_171 (skb, next, sk) {
V_325 = F_26 ( int , V_4 -> V_72 , V_294 - V_72 ) ;
if ( V_322 -> V_80 )
F_172 ( V_4 , 0 , F_128 ( V_322 , V_325 ) , V_325 ) ;
else
V_322 -> V_82 = F_173 ( V_4 , 0 ,
F_128 ( V_322 , V_325 ) ,
V_325 , V_322 -> V_82 ) ;
if ( V_4 -> V_72 <= V_325 ) {
F_4 ( V_322 ) -> V_58 |= F_4 ( V_4 ) -> V_58 ;
F_174 ( V_4 , V_2 ) ;
F_175 ( V_2 , V_4 ) ;
} else {
F_4 ( V_322 ) -> V_58 |= F_4 ( V_4 ) -> V_58 &
~ ( V_87 | V_272 ) ;
if ( ! F_39 ( V_4 ) -> V_273 ) {
F_176 ( V_4 , V_325 ) ;
if ( V_4 -> V_80 != V_81 )
V_4 -> V_82 = F_177 ( V_4 -> V_194 ,
V_4 -> V_72 , 0 ) ;
} else {
F_133 ( V_4 , V_325 ) ;
F_112 ( V_2 , V_4 , V_253 ) ;
}
F_4 ( V_4 ) -> V_73 += V_325 ;
}
V_72 += V_325 ;
if ( V_72 >= V_294 )
break;
}
F_157 ( V_2 , V_322 , V_322 -> V_72 ) ;
F_4 ( V_322 ) -> V_161 = V_19 ;
if ( ! F_90 ( V_2 , V_322 , 1 , V_193 ) ) {
V_6 -> V_23 -- ;
F_1 ( V_2 , V_322 ) ;
V_30 -> V_288 . V_294 = F_147 ( V_2 , V_322 -> V_72 ) ;
V_6 -> V_327 . V_328 = F_4 ( V_322 ) -> V_73 ;
V_6 -> V_327 . V_329 = F_4 ( V_322 ) -> V_10 ;
return 1 ;
}
return - 1 ;
}
static bool F_56 ( struct V_1 * V_2 , unsigned int V_253 , int V_304 ,
int V_330 , T_11 V_309 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_302 , V_331 ;
int V_308 ;
int V_332 ;
V_331 = 0 ;
if ( ! V_330 ) {
V_332 = F_169 ( V_2 ) ;
if ( ! V_332 ) {
return false ;
} else if ( V_332 > 0 ) {
V_331 = 1 ;
}
}
while ( ( V_4 = F_164 ( V_2 ) ) ) {
unsigned int V_312 ;
V_302 = F_157 ( V_2 , V_4 , V_253 ) ;
F_91 ( ! V_302 ) ;
if ( F_46 ( V_6 -> V_333 ) && V_6 -> V_334 == V_335 )
goto V_333;
V_308 = F_156 ( V_6 , V_4 ) ;
if ( ! V_308 )
break;
if ( F_46 ( ! F_161 ( V_6 , V_4 , V_253 ) ) )
break;
if ( V_302 == 1 ) {
if ( F_46 ( ! F_160 ( V_6 , V_4 , V_253 ,
( F_165 ( V_2 , V_4 ) ?
V_304 : V_307 ) ) ) )
break;
} else {
if ( ! V_330 && F_167 ( V_2 , V_4 ) )
break;
}
if ( F_178 ( & V_2 -> V_217 ) >= V_231 ) {
F_68 ( V_215 , & V_6 -> V_204 ) ;
break;
}
V_312 = V_253 ;
if ( V_302 > 1 && ! F_42 ( V_6 ) )
V_312 = F_154 ( V_2 , V_4 , V_253 ,
F_26 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ) ;
if ( V_4 -> V_72 > V_312 &&
F_46 ( F_166 ( V_2 , V_4 , V_312 , V_253 , V_309 ) ) )
break;
F_4 ( V_4 ) -> V_161 = V_19 ;
if ( F_46 ( F_90 ( V_2 , V_4 , 1 , V_309 ) ) )
break;
V_333:
F_1 ( V_2 , V_4 ) ;
F_179 ( V_6 , V_253 , V_4 ) ;
V_331 += F_5 ( V_4 ) ;
if ( V_330 )
break;
}
if ( F_48 ( V_331 ) ) {
if ( F_180 ( V_2 ) )
V_6 -> V_336 += V_331 ;
F_152 ( V_2 ) ;
return false ;
}
return ! V_6 -> V_8 && F_164 ( V_2 ) ;
}
void F_181 ( struct V_1 * V_2 , unsigned int V_306 ,
int V_304 )
{
if ( F_46 ( V_2 -> V_187 == V_337 ) )
return;
if ( F_56 ( V_2 , V_306 , V_304 , 0 ,
F_182 ( V_2 , V_193 ) ) )
F_183 ( V_2 ) ;
}
void F_184 ( struct V_1 * V_2 , unsigned int V_253 )
{
struct V_3 * V_4 = F_164 ( V_2 ) ;
F_91 ( ! V_4 || V_4 -> V_72 < V_253 ) ;
F_56 ( V_2 , V_253 , V_307 , 1 , V_2 -> V_338 ) ;
}
T_4 F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 = V_30 -> V_33 . V_339 ;
int V_340 = F_185 ( V_2 ) ;
int V_341 = F_26 ( int , V_6 -> V_41 , F_186 ( V_2 ) ) ;
int V_238 ;
if ( V_15 > V_341 )
V_15 = V_341 ;
if ( V_340 < ( V_341 >> 1 ) ) {
V_30 -> V_33 . V_342 = 0 ;
if ( F_187 ( V_2 ) )
V_6 -> V_343 = F_17 ( V_6 -> V_343 ,
4U * V_6 -> V_16 ) ;
if ( V_340 < V_15 )
return 0 ;
}
if ( V_340 > V_6 -> V_343 )
V_340 = V_6 -> V_343 ;
V_238 = V_6 -> V_40 ;
if ( V_6 -> V_54 . V_43 ) {
V_238 = V_340 ;
if ( ( ( V_238 >> V_6 -> V_54 . V_43 ) << V_6 -> V_54 . V_43 ) != V_238 )
V_238 = ( ( ( V_238 >> V_6 -> V_54 . V_43 ) + 1 )
<< V_6 -> V_54 . V_43 ) ;
} else {
if ( V_238 <= V_340 - V_15 || V_238 > V_340 )
V_238 = ( V_340 / V_15 ) * V_15 ;
else if ( V_15 == V_341 &&
V_340 > V_238 + ( V_341 >> 1 ) )
V_238 = V_340 ;
}
return V_238 ;
}
static void F_188 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_344 = F_189 ( V_2 , V_4 ) ;
int V_345 , V_346 ;
V_345 = V_4 -> V_72 ;
V_346 = V_344 -> V_72 ;
F_91 ( F_5 ( V_4 ) != 1 || F_5 ( V_344 ) != 1 ) ;
F_190 ( V_2 , V_344 , V_4 ) ;
F_174 ( V_344 , V_2 ) ;
F_191 ( V_344 , F_128 ( V_4 , V_346 ) ,
V_346 ) ;
if ( V_344 -> V_80 == V_81 )
V_4 -> V_80 = V_81 ;
if ( V_4 -> V_80 != V_81 )
V_4 -> V_82 = F_192 ( V_4 -> V_82 , V_344 -> V_82 , V_345 ) ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_344 ) -> V_10 ;
F_4 ( V_4 ) -> V_58 |= F_4 ( V_344 ) -> V_58 ;
F_4 ( V_4 ) -> V_83 |= F_4 ( V_344 ) -> V_83 & V_347 ;
F_193 ( V_6 ) ;
if ( V_344 == V_6 -> V_348 )
V_6 -> V_348 = V_4 ;
F_118 ( V_2 , V_344 , F_5 ( V_344 ) ) ;
F_175 ( V_2 , V_344 ) ;
}
static bool F_194 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_5 ( V_4 ) > 1 )
return false ;
if ( F_39 ( V_4 ) -> V_273 != 0 )
return false ;
if ( F_93 ( V_4 ) )
return false ;
if ( V_4 == F_164 ( V_2 ) )
return false ;
if ( F_4 ( V_4 ) -> V_83 & V_259 )
return false ;
return true ;
}
static void F_195 ( struct V_1 * V_2 , struct V_3 * V_349 ,
int V_45 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_349 , * V_350 ;
bool V_351 = true ;
if ( ! V_352 )
return;
if ( F_4 ( V_4 ) -> V_58 & V_86 )
return;
F_171 (skb, tmp, sk) {
if ( ! F_194 ( V_2 , V_4 ) )
break;
V_45 -= V_4 -> V_72 ;
if ( V_351 ) {
V_351 = false ;
continue;
}
if ( V_45 < 0 )
break;
if ( V_4 -> V_72 > F_196 ( V_349 ) )
break;
if ( F_103 ( F_4 ( V_4 ) -> V_10 , F_9 ( V_6 ) ) )
break;
F_188 ( V_2 , V_349 ) ;
}
}
int F_197 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
unsigned int V_306 ;
if ( V_30 -> V_288 . V_294 ) {
V_30 -> V_288 . V_294 = 0 ;
}
if ( F_178 ( & V_2 -> V_217 ) >
F_17 ( V_2 -> V_252 + ( V_2 -> V_252 >> 2 ) , V_2 -> V_353 ) )
return - V_354 ;
if ( F_8 ( F_4 ( V_4 ) -> V_73 , V_6 -> V_88 ) ) {
if ( F_8 ( F_4 ( V_4 ) -> V_10 , V_6 -> V_88 ) )
F_198 () ;
if ( F_139 ( V_2 , V_4 , V_6 -> V_88 - F_4 ( V_4 ) -> V_73 ) )
return - V_271 ;
}
if ( F_18 ( V_2 ) -> V_244 -> V_355 ( V_2 ) )
return - V_356 ;
V_306 = F_57 ( V_2 ) ;
if ( ! F_8 ( F_4 ( V_4 ) -> V_73 , F_9 ( V_6 ) ) &&
F_4 ( V_4 ) -> V_73 != V_6 -> V_88 )
return - V_354 ;
if ( V_4 -> V_72 > V_306 ) {
if ( F_121 ( V_2 , V_4 , V_306 , V_306 ) )
return - V_271 ;
} else {
int V_357 = F_5 ( V_4 ) ;
if ( F_46 ( V_357 > 1 ) ) {
F_157 ( V_2 , V_4 , V_306 ) ;
F_118 ( V_2 , V_4 , V_357 - F_5 ( V_4 ) ) ;
}
}
F_195 ( V_2 , V_4 , V_306 ) ;
if ( V_4 -> V_72 > 0 &&
( F_4 ( V_4 ) -> V_58 & V_87 ) &&
V_6 -> V_88 == ( F_4 ( V_4 ) -> V_10 - 1 ) ) {
if ( ! F_199 ( V_4 , 0 ) ) {
F_41 ( V_4 , F_4 ( V_4 ) -> V_10 - 1 ,
F_4 ( V_4 ) -> V_58 ) ;
V_4 -> V_80 = V_254 ;
}
}
F_4 ( V_4 ) -> V_161 = V_19 ;
if ( F_46 ( ( V_358 && ( ( unsigned long ) V_4 -> V_194 & 3 ) ) ||
F_200 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_322 = F_201 ( V_4 , V_359 ,
V_193 ) ;
return V_322 ? F_90 ( V_2 , V_322 , 0 , V_193 ) :
- V_227 ;
} else {
return F_90 ( V_2 , V_4 , 1 , V_193 ) ;
}
}
int F_202 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_224 = F_197 ( V_2 , V_4 ) ;
if ( V_224 == 0 ) {
F_203 ( F_33 ( V_2 ) , V_360 ) ;
V_6 -> V_361 ++ ;
#if V_362 > 0
if ( F_4 ( V_4 ) -> V_83 & V_260 ) {
F_204 ( L_1 ) ;
}
#endif
if ( ! V_6 -> V_261 )
V_6 -> V_363 = V_6 -> V_9 ;
F_4 ( V_4 ) -> V_83 |= V_364 ;
V_6 -> V_261 += F_5 ( V_4 ) ;
if ( ! V_6 -> V_365 )
V_6 -> V_365 = F_4 ( V_4 ) -> V_161 ;
V_6 -> V_366 += F_5 ( V_4 ) ;
F_4 ( V_4 ) -> V_236 = V_6 -> V_9 ;
}
return V_224 ;
}
static bool F_205 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_315 != V_367 )
return false ;
if ( F_116 ( V_6 ) )
return false ;
if ( F_163 ( V_2 ) )
return false ;
return true ;
}
void F_206 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_368 = NULL ;
T_4 V_369 ;
int V_370 ;
int V_371 = 0 ;
if ( ! V_6 -> V_8 )
return;
if ( ! V_6 -> V_263 )
V_6 -> V_372 = V_6 -> V_88 ;
if ( V_6 -> V_348 ) {
V_4 = V_6 -> V_348 ;
V_369 = F_4 ( V_4 ) -> V_10 ;
if ( F_103 ( V_369 , V_6 -> V_372 ) )
V_369 = V_6 -> V_372 ;
} else {
V_4 = F_207 ( V_2 ) ;
V_369 = V_6 -> V_88 ;
}
F_208 (skb, sk) {
T_5 V_83 = F_4 ( V_4 ) -> V_83 ;
if ( V_4 == F_164 ( V_2 ) )
break;
if ( V_368 == NULL )
V_6 -> V_348 = V_4 ;
if ( F_97 ( V_6 ) >= V_6 -> V_23 )
return;
if ( V_371 ) {
V_373:
if ( ! F_8 ( F_4 ( V_4 ) -> V_73 , F_117 ( V_6 ) ) )
break;
V_370 = V_374 ;
} else if ( ! F_8 ( F_4 ( V_4 ) -> V_73 , V_6 -> V_372 ) ) {
V_6 -> V_372 = V_369 ;
if ( ! F_205 ( V_2 ) )
break;
if ( V_368 != NULL ) {
V_4 = V_368 ;
V_368 = NULL ;
}
V_371 = 1 ;
goto V_373;
} else if ( ! ( V_83 & V_262 ) ) {
if ( V_368 == NULL && ! ( V_83 & ( V_260 | V_259 ) ) )
V_368 = V_4 ;
continue;
} else {
V_369 = F_4 ( V_4 ) -> V_10 ;
if ( V_30 -> V_315 != V_375 )
V_370 = V_376 ;
else
V_370 = V_377 ;
}
if ( V_83 & ( V_259 | V_260 ) )
continue;
if ( F_202 ( V_2 , V_4 ) ) {
F_209 ( F_33 ( V_2 ) , V_378 ) ;
return;
}
F_209 ( F_33 ( V_2 ) , V_370 ) ;
if ( F_180 ( V_2 ) )
V_6 -> V_336 += F_5 ( V_4 ) ;
if ( V_4 == F_207 ( V_2 ) )
F_210 ( V_2 , V_379 ,
F_18 ( V_2 ) -> V_26 ,
V_380 ) ;
}
}
void F_211 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_155 ( V_2 ) ;
int V_253 ;
V_253 = F_57 ( V_2 ) ;
if ( F_164 ( V_2 ) != NULL ) {
F_4 ( V_4 ) -> V_58 |= V_87 ;
F_4 ( V_4 ) -> V_10 ++ ;
V_6 -> V_251 ++ ;
} else {
for (; ; ) {
V_4 = F_212 ( V_359 ,
V_2 -> V_338 ) ;
if ( V_4 )
break;
F_213 () ;
}
F_214 ( V_4 , V_359 ) ;
F_41 ( V_4 , V_6 -> V_251 ,
V_246 | V_87 ) ;
F_108 ( V_2 , V_4 ) ;
}
F_181 ( V_2 , V_253 , V_381 ) ;
}
void F_215 ( struct V_1 * V_2 , T_11 V_382 )
{
struct V_3 * V_4 ;
V_4 = F_216 ( V_359 , V_382 ) ;
if ( ! V_4 ) {
F_217 ( F_33 ( V_2 ) , V_383 ) ;
return;
}
F_214 ( V_4 , V_359 ) ;
F_41 ( V_4 , F_7 ( V_2 ) ,
V_246 | V_384 ) ;
F_4 ( V_4 ) -> V_161 = V_19 ;
if ( F_90 ( V_2 , V_4 , 0 , V_382 ) )
F_217 ( F_33 ( V_2 ) , V_383 ) ;
F_203 ( F_33 ( V_2 ) , V_385 ) ;
}
int F_218 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_207 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_4 ( V_4 ) -> V_58 & V_86 ) ) {
F_219 ( L_2 , V_386 ) ;
return - V_387 ;
}
if ( ! ( F_4 ( V_4 ) -> V_58 & V_246 ) ) {
if ( F_93 ( V_4 ) ) {
struct V_3 * V_322 = F_220 ( V_4 , V_193 ) ;
if ( V_322 == NULL )
return - V_271 ;
F_174 ( V_4 , V_2 ) ;
F_109 ( V_322 ) ;
F_221 ( V_2 , V_322 ) ;
F_175 ( V_2 , V_4 ) ;
V_2 -> V_252 += V_322 -> V_216 ;
F_111 ( V_2 , V_322 -> V_216 ) ;
V_4 = V_322 ;
}
F_4 ( V_4 ) -> V_58 |= V_246 ;
F_31 ( F_2 ( V_2 ) , V_4 ) ;
}
F_4 ( V_4 ) -> V_161 = V_19 ;
return F_90 ( V_2 , V_4 , 1 , V_193 ) ;
}
struct V_3 * F_222 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_65 * V_66 ,
struct V_388 * V_389 ,
struct V_136 * V_137 )
{
struct V_96 V_97 ;
struct V_174 * V_175 = F_223 ( V_389 ) ;
struct V_176 * V_177 = F_35 ( V_66 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_146 * V_147 = V_6 -> V_148 ;
struct V_67 * V_68 ;
struct V_3 * V_4 ;
struct V_144 * V_145 ;
int V_223 ;
int V_15 ;
int V_390 = 0 ;
if ( V_147 != NULL && V_147 -> V_391 && V_147 -> V_390 )
V_390 = V_147 -> V_390 ;
V_4 = F_216 ( V_359 + 15 + V_390 ,
F_182 ( V_2 , V_193 ) ) ;
if ( F_46 ( ! V_4 ) ) {
F_224 ( V_14 ) ;
return NULL ;
}
F_214 ( V_4 , V_359 ) ;
F_225 ( V_4 , V_14 ) ;
F_226 ( V_4 , V_2 ) ;
V_15 = F_12 ( V_14 ) ;
if ( V_6 -> V_54 . V_392 && V_6 -> V_54 . V_392 < V_15 )
V_15 = V_6 -> V_54 . V_392 ;
if ( V_66 -> V_40 == 0 ) {
T_5 V_43 ;
V_66 -> V_41 = V_6 -> V_41 ? : F_227 ( V_14 , V_393 ) ;
if ( V_2 -> V_394 & V_395 &&
( V_66 -> V_41 > F_186 ( V_2 ) || V_66 -> V_41 == 0 ) )
V_66 -> V_41 = F_186 ( V_2 ) ;
F_24 ( F_186 ( V_2 ) ,
V_15 - ( V_177 -> V_179 ? V_164 : 0 ) ,
& V_66 -> V_40 ,
& V_66 -> V_41 ,
V_177 -> V_42 ,
& V_43 ,
F_227 ( V_14 , V_396 ) ) ;
V_177 -> V_43 = V_43 ;
}
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
#ifdef F_228
if ( F_46 ( V_66 -> V_397 ) )
F_4 ( V_4 ) -> V_161 = F_229 ( V_66 ) ;
else
#endif
F_4 ( V_4 ) -> V_161 = V_19 ;
V_223 = F_52 ( V_2 , V_66 , V_15 ,
V_4 , & V_97 , & V_145 , V_175 , V_137 )
+ sizeof( * V_68 ) ;
F_98 ( V_4 , V_223 ) ;
F_99 ( V_4 ) ;
V_68 = F_38 ( V_4 ) ;
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 -> V_398 = 1 ;
V_68 -> V_399 = 1 ;
F_34 ( V_66 , V_68 ) ;
V_68 -> V_232 = V_177 -> V_400 ;
V_68 -> V_234 = V_177 -> V_401 ;
F_41 ( V_4 , F_53 ( V_66 ) -> V_402 ,
V_86 | V_246 ) ;
if ( V_100 & V_97 . V_98 ) {
if ( V_390 ) {
T_8 * V_403 = F_128 ( V_4 , V_390 ) ;
memcpy ( V_403 , V_147 -> V_404 , V_390 ) ;
F_4 ( V_4 ) -> V_10 += V_390 ;
}
if ( V_97 . V_118 > 0 ) {
T_1 V_405 [ V_406 ] ;
T_4 * V_407 = & V_175 -> V_408 [ V_409 ] ;
T_4 * V_410 = & V_407 [ V_411 - 1 ] ;
* V_410 -- ^= V_97 . V_115 ;
* V_410 -- ^= F_53 ( V_66 ) -> V_412 + 1 ;
* V_410 -- ^= F_4 ( V_4 ) -> V_73 + 1 ;
* V_410 -- ^= ( ( ( V_413 T_4 ) V_68 -> V_234 << 16 ) | ( V_413 T_4 ) V_68 -> V_232 ) ;
* V_410 -- ^= ( T_4 ) ( unsigned long ) V_147 ;
F_230 ( ( T_1 * ) & V_175 -> V_408 [ 0 ] ,
( char * ) V_407 ,
& V_405 [ 0 ] ) ;
V_97 . V_106 =
( T_5 * ) & V_175 -> V_408 [ 0 ] ;
}
}
V_68 -> V_73 = F_47 ( F_4 ( V_4 ) -> V_73 ) ;
V_68 -> V_236 = F_47 ( F_53 ( V_66 ) -> V_56 ) ;
V_68 -> V_238 = F_102 ( F_17 ( V_66 -> V_40 , 65535U ) ) ;
F_45 ( ( T_9 * ) ( V_68 + 1 ) , V_6 , & V_97 ) ;
V_68 -> V_414 = ( V_223 >> 2 ) ;
F_105 ( F_33 ( V_2 ) , V_247 , F_5 ( V_4 ) ) ;
#ifdef F_50
if ( V_145 ) {
F_53 ( V_66 ) -> V_156 -> V_243 ( V_97 . V_106 ,
V_145 , NULL , V_66 , V_4 ) ;
}
#endif
return V_4 ;
}
void F_231 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_5 V_43 ;
V_6 -> V_71 = sizeof( struct V_67 ) +
( V_160 ? V_164 : 0 ) ;
#ifdef F_50
if ( V_6 -> V_156 -> V_157 ( V_2 , V_2 ) != NULL )
V_6 -> V_71 += V_158 ;
#endif
if ( V_6 -> V_54 . V_392 )
V_6 -> V_54 . V_285 = V_6 -> V_54 . V_392 ;
V_6 -> V_415 = 0 ;
F_148 ( V_2 ) ;
F_149 ( V_2 , F_151 ( V_14 ) ) ;
if ( ! V_6 -> V_41 )
V_6 -> V_41 = F_227 ( V_14 , V_393 ) ;
V_6 -> V_16 = F_12 ( V_14 ) ;
if ( V_6 -> V_54 . V_392 && V_6 -> V_54 . V_392 < V_6 -> V_16 )
V_6 -> V_16 = V_6 -> V_54 . V_392 ;
F_232 ( V_2 ) ;
if ( V_2 -> V_394 & V_395 &&
( V_6 -> V_41 > F_186 ( V_2 ) || V_6 -> V_41 == 0 ) )
V_6 -> V_41 = F_186 ( V_2 ) ;
F_24 ( F_186 ( V_2 ) ,
V_6 -> V_16 - ( V_6 -> V_54 . V_416 ? V_6 -> V_71 - sizeof( struct V_67 ) : 0 ) ,
& V_6 -> V_40 ,
& V_6 -> V_41 ,
V_165 ,
& V_43 ,
F_227 ( V_14 , V_396 ) ) ;
V_6 -> V_54 . V_43 = V_43 ;
V_6 -> V_343 = V_6 -> V_40 ;
V_2 -> V_417 = 0 ;
F_233 ( V_2 , V_418 ) ;
V_6 -> V_321 = 0 ;
F_234 ( V_6 , 0 ) ;
V_6 -> V_88 = V_6 -> V_251 ;
V_6 -> V_303 = V_6 -> V_251 ;
V_6 -> V_89 = V_6 -> V_251 ;
V_6 -> V_9 = V_6 -> V_251 ;
if ( F_48 ( ! V_6 -> V_333 ) )
V_6 -> V_56 = 0 ;
V_6 -> V_55 = V_6 -> V_56 ;
V_6 -> V_419 = V_6 -> V_56 ;
F_18 ( V_2 ) -> V_26 = V_420 ;
F_18 ( V_2 ) -> V_421 = 0 ;
F_235 ( V_6 ) ;
}
static void F_236 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_181 * V_182 = F_4 ( V_4 ) ;
V_182 -> V_10 += V_4 -> V_72 ;
F_109 ( V_4 ) ;
F_237 ( V_2 , V_4 ) ;
V_2 -> V_252 += V_4 -> V_216 ;
F_111 ( V_2 , V_4 -> V_216 ) ;
V_6 -> V_251 = V_182 -> V_10 ;
V_6 -> V_8 += F_5 ( V_4 ) ;
}
static int F_238 ( struct V_1 * V_2 , struct V_3 * V_398 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_153 * V_422 = V_6 -> V_155 ;
int V_423 = 0 , V_45 , V_213 , V_224 = 0 , V_424 = V_422 -> V_194 -> V_425 ;
struct V_3 * V_426 = NULL , * V_194 ;
unsigned long V_427 = 0 ;
V_6 -> V_54 . V_285 = V_6 -> V_16 ;
F_239 ( V_2 , & V_6 -> V_54 . V_285 , & V_422 -> V_169 ,
& V_423 , & V_427 ) ;
if ( V_423 > 1 &&
F_240 ( V_318 , V_427 + ( 60 * V_428 << V_423 ) ) ) {
V_422 -> V_169 . V_72 = - 1 ;
goto V_429;
}
if ( V_430 & V_431 )
V_422 -> V_169 . V_72 = - 1 ;
else if ( V_422 -> V_169 . V_72 <= 0 )
goto V_429;
if ( V_6 -> V_54 . V_392 && V_6 -> V_54 . V_392 < V_6 -> V_54 . V_285 )
V_6 -> V_54 . V_285 = V_6 -> V_54 . V_392 ;
V_45 = F_144 ( V_2 , F_18 ( V_2 ) -> V_295 ) -
V_150 ;
V_426 = F_241 ( V_398 , F_200 ( V_398 ) , V_45 ,
V_2 -> V_338 ) ;
if ( V_426 == NULL )
goto V_429;
for ( V_213 = 0 ; V_213 < V_424 && V_426 -> V_72 < V_45 ; ++ V_213 ) {
struct V_432 * V_433 = & V_422 -> V_194 -> V_434 [ V_213 ] ;
unsigned char T_12 * V_435 = V_433 -> V_436 ;
int V_72 = V_433 -> V_437 ;
if ( V_426 -> V_72 + V_72 > V_45 )
V_72 = V_45 - V_426 -> V_72 ;
else if ( V_213 + 1 == V_424 )
V_422 -> V_194 = NULL ;
if ( F_242 ( V_426 , V_435 , V_72 ) )
goto V_429;
}
V_194 = F_94 ( V_426 , V_2 -> V_338 ) ;
if ( V_194 == NULL )
goto V_429;
F_4 ( V_194 ) -> V_73 ++ ;
F_4 ( V_194 ) -> V_58 &= ~ V_86 ;
F_4 ( V_194 ) -> V_58 = ( V_246 | V_272 ) ;
F_236 ( V_2 , V_194 ) ;
V_422 -> V_438 = V_194 -> V_72 ;
if ( F_90 ( V_2 , V_426 , 0 , V_2 -> V_338 ) == 0 ) {
V_6 -> V_426 = ( V_422 -> V_438 > 0 ) ;
F_217 ( F_33 ( V_2 ) , V_439 ) ;
goto V_440;
}
V_426 = NULL ;
V_429:
if ( V_422 -> V_169 . V_72 > 0 )
V_422 -> V_169 . V_72 = 0 ;
V_224 = F_90 ( V_2 , V_398 , 1 , V_2 -> V_338 ) ;
if ( V_224 )
V_6 -> V_171 = 0 ;
F_243 ( V_426 ) ;
V_440:
V_422 -> V_169 . V_72 = - 1 ;
return V_224 ;
}
int F_244 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_266 ;
int V_224 ;
F_231 ( V_2 ) ;
if ( F_46 ( V_6 -> V_333 ) ) {
F_245 ( V_2 , NULL ) ;
return 0 ;
}
V_266 = F_212 ( V_359 + 15 , V_2 -> V_338 ) ;
if ( F_46 ( V_266 == NULL ) )
return - V_227 ;
F_214 ( V_266 , V_359 ) ;
F_41 ( V_266 , V_6 -> V_251 ++ , V_86 ) ;
V_6 -> V_365 = F_4 ( V_266 ) -> V_161 = V_19 ;
F_236 ( V_2 , V_266 ) ;
F_32 ( V_2 , V_266 ) ;
V_224 = V_6 -> V_155 ? F_238 ( V_2 , V_266 ) :
F_90 ( V_2 , V_266 , 1 , V_2 -> V_338 ) ;
if ( V_224 == - V_441 )
return V_224 ;
V_6 -> V_9 = V_6 -> V_251 ;
V_6 -> V_442 = V_6 -> V_251 ;
F_203 ( F_33 ( V_2 ) , V_443 ) ;
F_210 ( V_2 , V_379 ,
F_18 ( V_2 ) -> V_26 , V_380 ) ;
return 0 ;
}
void F_246 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_35 = V_30 -> V_33 . V_35 ;
unsigned long V_444 ;
if ( V_35 > V_445 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_446 = V_428 / 2 ;
if ( V_30 -> V_33 . V_36 ||
( V_30 -> V_33 . V_447 & V_448 ) )
V_446 = V_449 ;
if ( V_6 -> V_450 ) {
int V_451 = F_19 ( V_6 -> V_450 >> 3 , V_445 ) ;
if ( V_451 < V_446 )
V_446 = V_451 ;
}
V_35 = F_17 ( V_35 , V_446 ) ;
}
V_444 = V_318 + V_35 ;
if ( V_30 -> V_33 . V_447 & V_452 ) {
if ( V_30 -> V_33 . V_453 ||
F_247 ( V_30 -> V_33 . V_444 , V_318 + ( V_35 >> 2 ) ) ) {
F_248 ( V_2 ) ;
return;
}
if ( ! F_240 ( V_444 , V_30 -> V_33 . V_444 ) )
V_444 = V_30 -> V_33 . V_444 ;
}
V_30 -> V_33 . V_447 |= V_454 | V_452 ;
V_30 -> V_33 . V_444 = V_444 ;
F_249 ( V_2 , & V_30 -> V_455 , V_444 ) ;
}
void F_248 ( struct V_1 * V_2 )
{
struct V_3 * V_266 ;
if ( V_2 -> V_187 == V_337 )
return;
V_266 = F_216 ( V_359 , F_182 ( V_2 , V_193 ) ) ;
if ( V_266 == NULL ) {
F_250 ( V_2 ) ;
F_18 ( V_2 ) -> V_33 . V_35 = V_456 ;
F_210 ( V_2 , V_38 ,
V_449 , V_380 ) ;
return;
}
F_214 ( V_266 , V_359 ) ;
F_41 ( V_266 , F_7 ( V_2 ) , V_246 ) ;
F_4 ( V_266 ) -> V_161 = V_19 ;
F_90 ( V_2 , V_266 , 0 , F_182 ( V_2 , V_193 ) ) ;
}
static int F_251 ( struct V_1 * V_2 , int V_457 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_216 ( V_359 , F_182 ( V_2 , V_193 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_214 ( V_4 , V_359 ) ;
F_41 ( V_4 , V_6 -> V_88 - ! V_457 , V_246 ) ;
F_4 ( V_4 ) -> V_161 = V_19 ;
return F_90 ( V_2 , V_4 , 0 , V_193 ) ;
}
void F_252 ( struct V_1 * V_2 )
{
if ( V_2 -> V_187 == V_458 ) {
F_2 ( V_2 ) -> V_459 = F_2 ( V_2 ) -> V_56 - 1 ;
F_2 ( V_2 ) -> V_9 = F_2 ( V_2 ) -> V_251 ;
F_251 ( V_2 , 0 ) ;
}
}
int F_253 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_187 == V_337 )
return - 1 ;
if ( ( V_4 = F_164 ( V_2 ) ) != NULL &&
F_8 ( F_4 ( V_4 ) -> V_73 , F_9 ( V_6 ) ) ) {
int V_224 ;
unsigned int V_15 = F_57 ( V_2 ) ;
unsigned int V_460 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_73 ;
if ( F_8 ( V_6 -> V_442 , F_4 ( V_4 ) -> V_10 ) )
V_6 -> V_442 = F_4 ( V_4 ) -> V_10 ;
if ( V_460 < F_4 ( V_4 ) -> V_10 - F_4 ( V_4 ) -> V_73 ||
V_4 -> V_72 > V_15 ) {
V_460 = F_17 ( V_460 , V_15 ) ;
F_4 ( V_4 ) -> V_58 |= V_272 ;
if ( F_121 ( V_2 , V_4 , V_460 , V_15 ) )
return - 1 ;
} else if ( ! F_5 ( V_4 ) )
F_112 ( V_2 , V_4 , V_15 ) ;
F_4 ( V_4 ) -> V_58 |= V_272 ;
F_4 ( V_4 ) -> V_161 = V_19 ;
V_224 = F_90 ( V_2 , V_4 , 1 , V_193 ) ;
if ( ! V_224 )
F_1 ( V_2 , V_4 ) ;
return V_224 ;
} else {
if ( F_254 ( V_6 -> V_89 , V_6 -> V_88 + 1 , V_6 -> V_88 + 0xFFFF ) )
F_251 ( V_2 , 1 ) ;
return F_251 ( V_2 , 0 ) ;
}
}
void F_255 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_224 ;
V_224 = F_253 ( V_2 ) ;
if ( V_6 -> V_8 || ! F_164 ( V_2 ) ) {
V_30 -> V_461 = 0 ;
V_30 -> V_462 = 0 ;
return;
}
if ( V_224 <= 0 ) {
if ( V_30 -> V_462 < V_463 )
V_30 -> V_462 ++ ;
V_30 -> V_461 ++ ;
F_210 ( V_2 , V_464 ,
F_17 ( V_30 -> V_26 << V_30 -> V_462 , V_380 ) ,
V_380 ) ;
} else {
if ( ! V_30 -> V_461 )
V_30 -> V_461 = 1 ;
F_210 ( V_2 , V_464 ,
F_17 ( V_30 -> V_26 << V_30 -> V_462 ,
V_465 ) ,
V_380 ) ;
}
}
