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
}
static inline T_1 F_8 ( const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_9 ( F_10 ( V_8 ) , V_8 -> V_11 ) )
return V_8 -> V_11 ;
else
return F_10 ( V_8 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_16 * V_17 = F_12 ( V_2 ) ;
int V_18 = V_8 -> V_19 ;
if ( V_17 ) {
unsigned int V_20 = F_13 ( V_17 ) ;
if ( V_20 < V_18 ) {
V_18 = V_20 ;
V_8 -> V_19 = V_18 ;
}
}
return ( T_2 ) V_18 ;
}
static void F_14 ( struct V_1 * V_2 , const struct V_16 * V_17 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_3 V_21 = V_22 - V_8 -> V_23 ;
T_4 V_24 = F_15 ( V_8 , V_17 ) ;
T_4 V_25 = V_8 -> V_26 ;
F_16 ( V_2 , V_27 ) ;
V_8 -> V_28 = F_17 ( V_2 ) ;
V_24 = F_18 ( V_24 , V_25 ) ;
while ( ( V_21 -= F_2 ( V_2 ) -> V_29 ) > 0 && V_25 > V_24 )
V_25 >>= 1 ;
V_8 -> V_26 = F_19 ( V_25 , V_24 ) ;
V_8 -> V_30 = V_22 ;
V_8 -> V_31 = 0 ;
}
static void F_20 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_4 V_32 = V_22 ;
const struct V_16 * V_17 = F_12 ( V_2 ) ;
if ( V_33 &&
( ! V_8 -> V_10 && ( T_3 ) ( V_32 - V_8 -> V_23 ) > V_6 -> V_29 ) )
F_14 ( V_2 , F_12 ( V_2 ) ) ;
V_8 -> V_23 = V_32 ;
if ( ( T_4 ) ( V_32 - V_6 -> V_34 . V_35 ) < V_6 -> V_34 . V_36 &&
( ! V_17 || ! F_21 ( V_17 , V_37 ) ) )
V_6 -> V_34 . V_38 = 1 ;
}
static inline void F_22 ( struct V_1 * V_2 , unsigned int V_39 )
{
F_23 ( V_2 , V_39 ) ;
F_24 ( V_2 , V_40 ) ;
}
T_4 F_25 ( T_4 V_18 )
{
T_4 V_41 = V_42 * 2 ;
if ( V_18 > 1460 )
V_41 = F_19 ( ( 1460 * V_41 ) / V_18 , 2U ) ;
return V_41 ;
}
void F_26 ( int V_43 , T_1 V_18 ,
T_1 * V_44 , T_1 * V_45 ,
int V_46 , T_5 * V_47 ,
T_1 V_48 )
{
unsigned int V_49 = ( V_43 < 0 ? 0 : V_43 ) ;
if ( * V_45 == 0 )
( * V_45 ) = ( 65535 << 14 ) ;
V_49 = F_18 ( * V_45 , V_49 ) ;
if ( V_49 > V_18 )
V_49 = ( V_49 / V_18 ) * V_18 ;
if ( V_50 )
( * V_44 ) = F_18 ( V_49 , V_51 ) ;
else
( * V_44 ) = V_49 ;
( * V_47 ) = 0 ;
if ( V_46 ) {
V_49 = F_27 ( T_4 , V_52 [ 2 ] , V_53 ) ;
V_49 = F_28 ( T_4 , V_49 , * V_45 ) ;
while ( V_49 > 65535 && ( * V_47 ) < 14 ) {
V_49 >>= 1 ;
( * V_47 ) ++ ;
}
}
if ( V_18 > ( 1 << * V_47 ) ) {
if ( ! V_48 )
V_48 = F_25 ( V_18 ) ;
* V_44 = F_18 ( * V_44 , V_48 * V_18 ) ;
}
( * V_45 ) = F_18 ( 65535U << ( * V_47 ) , * V_45 ) ;
}
static T_6 F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_54 = F_30 ( V_8 ) ;
T_4 V_55 = F_31 ( V_2 ) ;
if ( V_55 < V_54 ) {
V_55 = F_32 ( V_54 , 1 << V_8 -> V_56 . V_47 ) ;
}
V_8 -> V_44 = V_55 ;
V_8 -> V_57 = V_8 -> V_58 ;
if ( ! V_8 -> V_56 . V_47 && V_50 )
V_55 = F_18 ( V_55 , V_51 ) ;
else
V_55 = F_18 ( V_55 , ( 65535U << V_8 -> V_56 . V_47 ) ) ;
V_55 >>= V_8 -> V_56 . V_47 ;
if ( V_55 == 0 )
V_8 -> V_59 = 0 ;
return V_55 ;
}
static inline void F_33 ( const struct V_7 * V_8 , struct V_3 * V_4 )
{
F_5 ( V_4 ) -> V_60 &= ~ V_61 ;
if ( ! ( V_8 -> V_62 & V_63 ) )
F_5 ( V_4 ) -> V_60 &= ~ V_64 ;
}
static inline void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_62 = 0 ;
if ( F_35 ( V_2 ) -> V_65 . V_66 == 1 ) {
F_5 ( V_4 ) -> V_60 |= V_64 | V_61 ;
V_8 -> V_62 = V_63 ;
}
}
static T_7 void
F_36 ( const struct V_67 * V_68 , struct V_69 * V_70 )
{
if ( F_37 ( V_68 ) -> V_71 )
V_70 -> V_72 = 1 ;
}
static inline void F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_73 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_62 & V_63 ) {
if ( V_4 -> V_74 != V_73 &&
! F_9 ( F_5 ( V_4 ) -> V_75 , V_8 -> V_11 ) ) {
F_39 ( V_2 ) ;
if ( V_8 -> V_62 & V_76 ) {
V_8 -> V_62 &= ~ V_76 ;
F_40 ( V_4 ) -> V_77 = 1 ;
F_41 ( V_4 ) -> V_78 |= V_79 ;
}
} else {
F_42 ( V_2 ) ;
}
if ( V_8 -> V_62 & V_80 )
F_40 ( V_4 ) -> V_72 = 1 ;
}
}
static void F_43 ( struct V_3 * V_4 , T_4 V_75 , T_8 V_81 )
{
V_4 -> V_82 = V_83 ;
V_4 -> V_84 = 0 ;
F_5 ( V_4 ) -> V_60 = V_81 ;
F_5 ( V_4 ) -> V_85 = 0 ;
F_41 ( V_4 ) -> V_86 = 1 ;
F_41 ( V_4 ) -> V_87 = 0 ;
F_41 ( V_4 ) -> V_78 = 0 ;
F_5 ( V_4 ) -> V_75 = V_75 ;
if ( V_81 & ( V_88 | V_89 ) )
V_75 ++ ;
F_5 ( V_4 ) -> V_12 = V_75 ;
}
static inline bool F_44 ( const struct V_7 * V_8 )
{
return V_8 -> V_90 != V_8 -> V_91 ;
}
static void F_45 ( T_9 * V_92 , struct V_7 * V_8 ,
struct V_93 * V_94 )
{
T_6 V_95 = V_94 -> V_95 ;
if ( F_46 ( V_96 & V_95 ) ) {
* V_92 ++ = F_47 ( ( V_97 << 24 ) | ( V_97 << 16 ) |
( V_98 << 8 ) | V_99 ) ;
V_94 -> V_100 = ( T_5 * ) V_92 ;
V_92 += 4 ;
}
if ( F_46 ( V_94 -> V_18 ) ) {
* V_92 ++ = F_47 ( ( V_101 << 24 ) |
( V_102 << 16 ) |
V_94 -> V_18 ) ;
}
if ( F_48 ( V_103 & V_95 ) ) {
if ( F_46 ( V_104 & V_95 ) ) {
* V_92 ++ = F_47 ( ( V_105 << 24 ) |
( V_106 << 16 ) |
( V_107 << 8 ) |
V_108 ) ;
V_95 &= ~ V_104 ;
} else {
* V_92 ++ = F_47 ( ( V_97 << 24 ) |
( V_97 << 16 ) |
( V_107 << 8 ) |
V_108 ) ;
}
* V_92 ++ = F_47 ( V_94 -> V_109 ) ;
* V_92 ++ = F_47 ( V_94 -> V_110 ) ;
}
if ( F_46 ( V_104 & V_95 ) ) {
* V_92 ++ = F_47 ( ( V_97 << 24 ) |
( V_97 << 16 ) |
( V_105 << 8 ) |
V_106 ) ;
}
if ( F_46 ( V_111 & V_95 ) ) {
* V_92 ++ = F_47 ( ( V_97 << 24 ) |
( V_112 << 16 ) |
( V_113 << 8 ) |
V_94 -> V_114 ) ;
}
if ( F_46 ( V_94 -> V_115 ) ) {
struct V_116 * V_117 = V_8 -> V_56 . V_118 ?
V_8 -> V_119 : V_8 -> V_120 ;
int V_121 ;
* V_92 ++ = F_47 ( ( V_97 << 24 ) |
( V_97 << 16 ) |
( V_122 << 8 ) |
( V_123 + ( V_94 -> V_115 *
V_124 ) ) ) ;
for ( V_121 = 0 ; V_121 < V_94 -> V_115 ;
++ V_121 ) {
* V_92 ++ = F_47 ( V_117 [ V_121 ] . V_125 ) ;
* V_92 ++ = F_47 ( V_117 [ V_121 ] . V_12 ) ;
}
V_8 -> V_56 . V_118 = 0 ;
}
if ( F_46 ( V_126 & V_95 ) ) {
struct V_127 * V_128 = V_94 -> V_129 ;
* V_92 ++ = F_47 ( ( V_130 << 24 ) |
( ( V_131 + V_128 -> V_74 ) << 16 ) |
V_132 ) ;
memcpy ( V_92 , V_128 -> V_133 , V_128 -> V_74 ) ;
if ( ( V_128 -> V_74 & 3 ) == 2 ) {
T_8 * V_134 = ( ( T_8 * ) V_92 ) + V_128 -> V_74 ;
V_134 [ 0 ] = V_134 [ 1 ] = V_97 ;
}
V_92 += ( V_128 -> V_74 + 3 ) >> 2 ;
}
}
static unsigned int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_93 * V_94 ,
struct V_135 * * V_136 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_137 = V_138 ;
struct V_139 * V_140 = V_8 -> V_141 ;
#ifdef F_50
* V_136 = V_8 -> V_142 -> V_143 ( V_2 , V_2 ) ;
if ( * V_136 ) {
V_94 -> V_95 |= V_96 ;
V_137 -= V_144 ;
}
#else
* V_136 = NULL ;
#endif
V_94 -> V_18 = F_11 ( V_2 ) ;
V_137 -= V_145 ;
if ( F_48 ( V_146 && * V_136 == NULL ) ) {
V_94 -> V_95 |= V_103 ;
V_94 -> V_109 = F_5 ( V_4 ) -> V_147 + V_8 -> V_148 ;
V_94 -> V_110 = V_8 -> V_56 . V_149 ;
V_137 -= V_150 ;
}
if ( F_48 ( V_151 ) ) {
V_94 -> V_114 = V_8 -> V_56 . V_47 ;
V_94 -> V_95 |= V_111 ;
V_137 -= V_152 ;
}
if ( F_48 ( V_153 ) ) {
V_94 -> V_95 |= V_104 ;
if ( F_46 ( ! ( V_103 & V_94 -> V_95 ) ) )
V_137 -= V_154 ;
}
if ( V_140 && V_140 -> V_155 . V_74 >= 0 ) {
T_4 V_156 = V_131 + V_140 -> V_155 . V_74 ;
V_156 = ( V_156 + 3 ) & ~ 3U ;
if ( V_137 >= V_156 ) {
V_94 -> V_95 |= V_126 ;
V_94 -> V_129 = & V_140 -> V_155 ;
V_137 -= V_156 ;
V_8 -> V_157 = 1 ;
}
}
return V_138 - V_137 ;
}
static unsigned int F_51 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
unsigned int V_18 , struct V_3 * V_4 ,
struct V_93 * V_94 ,
struct V_135 * * V_136 ,
struct V_127 * V_128 )
{
struct V_158 * V_159 = F_37 ( V_68 ) ;
unsigned int V_137 = V_138 ;
#ifdef F_50
* V_136 = F_52 ( V_68 ) -> V_142 -> V_143 ( V_2 , V_68 ) ;
if ( * V_136 ) {
V_94 -> V_95 |= V_96 ;
V_137 -= V_144 ;
V_159 -> V_160 &= ! V_159 -> V_161 ;
}
#else
* V_136 = NULL ;
#endif
V_94 -> V_18 = V_18 ;
V_137 -= V_145 ;
if ( F_48 ( V_159 -> V_46 ) ) {
V_94 -> V_114 = V_159 -> V_47 ;
V_94 -> V_95 |= V_111 ;
V_137 -= V_152 ;
}
if ( F_48 ( V_159 -> V_160 ) ) {
V_94 -> V_95 |= V_103 ;
V_94 -> V_109 = F_5 ( V_4 ) -> V_147 ;
V_94 -> V_110 = V_68 -> V_149 ;
V_137 -= V_150 ;
}
if ( F_48 ( V_159 -> V_161 ) ) {
V_94 -> V_95 |= V_104 ;
if ( F_46 ( ! V_159 -> V_160 ) )
V_137 -= V_154 ;
}
if ( V_128 != NULL ) {
T_4 V_156 = V_131 + V_128 -> V_74 ;
V_156 = ( V_156 + 3 ) & ~ 3U ;
if ( V_137 >= V_156 ) {
V_94 -> V_95 |= V_126 ;
V_94 -> V_129 = V_128 ;
V_137 -= V_156 ;
}
}
return V_138 - V_137 ;
}
static unsigned int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_93 * V_94 ,
struct V_135 * * V_136 )
{
struct V_162 * V_163 = V_4 ? F_5 ( V_4 ) : NULL ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_164 = 0 ;
unsigned int V_165 ;
V_94 -> V_95 = 0 ;
#ifdef F_50
* V_136 = V_8 -> V_142 -> V_143 ( V_2 , V_2 ) ;
if ( F_46 ( * V_136 ) ) {
V_94 -> V_95 |= V_96 ;
V_164 += V_144 ;
}
#else
* V_136 = NULL ;
#endif
if ( F_48 ( V_8 -> V_56 . V_160 ) ) {
V_94 -> V_95 |= V_103 ;
V_94 -> V_109 = V_163 ? V_163 -> V_147 + V_8 -> V_148 : 0 ;
V_94 -> V_110 = V_8 -> V_56 . V_149 ;
V_164 += V_150 ;
}
V_165 = V_8 -> V_56 . V_166 + V_8 -> V_56 . V_118 ;
if ( F_46 ( V_165 ) ) {
const unsigned int V_137 = V_138 - V_164 ;
V_94 -> V_115 =
F_28 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_164 += V_167 +
V_94 -> V_115 * V_124 ;
}
return V_164 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_168 ) &
( V_169 | V_170 | V_171 |
V_172 | V_173 ) )
F_55 ( V_2 , F_56 ( V_2 ) , 0 , 0 , V_174 ) ;
}
static void F_57 ( unsigned long V_175 )
{
struct V_176 * V_177 = (struct V_176 * ) V_175 ;
F_58 ( V_178 ) ;
unsigned long V_81 ;
struct V_179 * V_180 , * V_181 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_59 ( V_81 ) ;
F_60 ( & V_177 -> V_182 , & V_178 ) ;
F_61 ( V_81 ) ;
F_62 (q, n, &list) {
V_8 = F_63 ( V_180 , struct V_7 , V_183 ) ;
F_64 ( & V_8 -> V_183 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_65 ( V_2 ) ;
if ( ! F_66 ( V_2 ) ) {
F_54 ( V_2 ) ;
} else {
F_67 ( V_184 , & V_8 -> V_185 ) ;
}
F_68 ( V_2 ) ;
F_69 ( V_186 , & V_8 -> V_185 ) ;
F_70 ( V_2 ) ;
}
}
void F_71 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_81 , V_187 ;
do {
V_81 = V_8 -> V_185 ;
if ( ! ( V_81 & V_188 ) )
return;
V_187 = V_81 & ~ V_188 ;
} while ( F_72 ( & V_8 -> V_185 , V_81 , V_187 ) != V_81 );
if ( V_81 & ( 1UL << V_184 ) )
F_54 ( V_2 ) ;
if ( V_81 & ( 1UL << V_189 ) ) {
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
}
if ( V_81 & ( 1UL << V_190 ) ) {
F_75 ( V_2 ) ;
F_74 ( V_2 ) ;
}
if ( V_81 & ( 1UL << V_191 ) ) {
V_2 -> V_192 -> V_193 ( V_2 ) ;
F_74 ( V_2 ) ;
}
}
void T_10 F_76 ( void )
{
int V_194 ;
F_77 (i) {
struct V_176 * V_177 = & F_78 ( V_176 , V_194 ) ;
F_79 ( & V_177 -> V_182 ) ;
F_80 ( & V_177 -> V_195 ,
F_57 ,
( unsigned long ) V_177 ) ;
}
}
void F_81 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_82 ( V_196 , & V_8 -> V_185 ) &&
! F_83 ( V_186 , & V_8 -> V_185 ) ) {
unsigned long V_81 ;
struct V_176 * V_177 ;
F_84 ( V_4 -> V_197 - 1 , & V_2 -> V_198 ) ;
F_59 ( V_81 ) ;
V_177 = & F_85 ( V_176 ) ;
F_86 ( & V_8 -> V_183 , & V_177 -> V_182 ) ;
F_87 ( & V_177 -> V_195 ) ;
F_61 ( V_81 ) ;
} else {
F_88 ( V_4 ) ;
}
}
static int F_89 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_199 ,
T_11 V_200 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_201 * V_202 ;
struct V_7 * V_8 ;
struct V_162 * V_163 ;
struct V_93 V_94 ;
unsigned int V_203 , V_204 ;
struct V_135 * V_136 ;
struct V_69 * V_70 ;
int V_205 ;
F_90 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_199 ) {
const struct V_3 * V_206 = V_4 + 1 ;
if ( V_6 -> V_207 -> V_81 & V_208 )
F_91 ( V_4 ) ;
if ( F_46 ( V_4 -> V_206 == V_209 &&
V_206 -> V_206 == V_210 ) )
F_92 ( F_35 ( V_2 ) ,
V_211 ) ;
if ( F_46 ( F_93 ( V_4 ) ) )
V_4 = F_94 ( V_4 , V_200 ) ;
else
V_4 = F_95 ( V_4 , V_200 ) ;
if ( F_46 ( ! V_4 ) )
return - V_212 ;
}
V_202 = F_96 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_163 = F_5 ( V_4 ) ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
if ( F_46 ( V_163 -> V_60 & V_88 ) )
V_203 = F_49 ( V_2 , V_4 , & V_94 , & V_136 ) ;
else
V_203 = F_53 ( V_2 , V_4 , & V_94 ,
& V_136 ) ;
V_204 = V_203 + sizeof( struct V_69 ) ;
if ( F_97 ( V_8 ) == 0 )
F_16 ( V_2 , V_213 ) ;
V_4 -> V_214 = F_98 ( V_2 ) == 0 ;
F_99 ( V_4 , V_204 ) ;
F_100 ( V_4 ) ;
F_101 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_215 = F_81 ;
F_102 ( V_4 -> V_197 , & V_2 -> V_198 ) ;
V_70 = F_40 ( V_4 ) ;
V_70 -> V_216 = V_202 -> V_217 ;
V_70 -> V_218 = V_202 -> V_219 ;
V_70 -> V_75 = F_47 ( V_163 -> V_75 ) ;
V_70 -> V_220 = F_47 ( V_8 -> V_58 ) ;
* ( ( ( V_221 * ) V_70 ) + 6 ) = F_103 ( ( ( V_204 >> 2 ) << 12 ) |
V_163 -> V_60 ) ;
if ( F_46 ( V_163 -> V_60 & V_88 ) ) {
V_70 -> V_222 = F_103 ( F_18 ( V_8 -> V_44 , 65535U ) ) ;
} else {
V_70 -> V_222 = F_103 ( F_29 ( V_2 ) ) ;
}
V_70 -> V_223 = 0 ;
V_70 -> V_224 = 0 ;
if ( F_46 ( F_44 ( V_8 ) && F_9 ( V_163 -> V_75 , V_8 -> V_91 ) ) ) {
if ( F_9 ( V_8 -> V_91 , V_163 -> V_75 + 0x10000 ) ) {
V_70 -> V_224 = F_103 ( V_8 -> V_91 - V_163 -> V_75 ) ;
V_70 -> V_225 = 1 ;
} else if ( F_104 ( V_163 -> V_75 + 0xFFFF , V_8 -> V_11 ) ) {
V_70 -> V_224 = F_103 ( 0xFFFF ) ;
V_70 -> V_225 = 1 ;
}
}
F_45 ( ( T_9 * ) ( V_70 + 1 ) , V_8 , & V_94 ) ;
if ( F_48 ( ( V_163 -> V_60 & V_88 ) == 0 ) )
F_38 ( V_2 , V_4 , V_204 ) ;
#ifdef F_50
if ( V_136 ) {
F_105 ( V_2 , V_226 ) ;
V_8 -> V_142 -> V_227 ( V_94 . V_100 ,
V_136 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_228 -> V_229 ( V_2 , V_4 ) ;
if ( F_48 ( V_163 -> V_60 & V_230 ) )
F_22 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_74 != V_204 )
F_20 ( V_8 , V_2 ) ;
if ( F_104 ( V_163 -> V_12 , V_8 -> V_11 ) || V_163 -> V_75 == V_163 -> V_12 )
F_106 ( F_35 ( V_2 ) , V_231 ,
F_6 ( V_4 ) ) ;
V_205 = V_6 -> V_228 -> V_232 ( V_4 , & V_202 -> V_233 . V_234 ) ;
if ( F_48 ( V_205 <= 0 ) )
return V_205 ;
F_107 ( V_2 , 1 ) ;
return F_108 ( V_205 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_235 = F_5 ( V_4 ) -> V_12 ;
F_110 ( V_4 ) ;
F_111 ( V_2 , V_4 ) ;
V_2 -> V_236 += V_4 -> V_197 ;
F_112 ( V_2 , V_4 -> V_197 ) ;
}
static void F_113 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_237 )
{
F_114 ( F_93 ( V_4 ) ) ;
if ( V_4 -> V_74 <= V_237 || V_4 -> V_82 == V_238 ) {
F_41 ( V_4 ) -> V_86 = 1 ;
F_41 ( V_4 ) -> V_87 = 0 ;
F_41 ( V_4 ) -> V_78 = 0 ;
} else {
F_41 ( V_4 ) -> V_86 = F_115 ( V_4 -> V_74 , V_237 ) ;
F_41 ( V_4 ) -> V_87 = V_237 ;
F_41 ( V_4 ) -> V_78 = V_2 -> V_239 ;
}
}
static void F_116 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_240 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_241 || F_117 ( V_8 ) )
return;
if ( F_104 ( F_118 ( V_8 ) , F_5 ( V_4 ) -> V_75 ) )
V_8 -> V_242 -= V_240 ;
}
static void F_119 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_240 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_240 ;
if ( F_5 ( V_4 ) -> V_85 & V_243 )
V_8 -> V_241 -= V_240 ;
if ( F_5 ( V_4 ) -> V_85 & V_244 )
V_8 -> V_245 -= V_240 ;
if ( F_5 ( V_4 ) -> V_85 & V_246 )
V_8 -> V_247 -= V_240 ;
if ( F_117 ( V_8 ) && V_240 > 0 )
V_8 -> V_241 -= F_28 ( T_4 , V_8 -> V_241 , V_240 ) ;
F_116 ( V_2 , V_4 , V_240 ) ;
if ( V_8 -> V_248 &&
F_9 ( F_5 ( V_4 ) -> V_75 , F_5 ( V_8 -> V_248 ) -> V_75 ) &&
( F_120 ( V_8 ) || ( F_5 ( V_4 ) -> V_85 & V_243 ) ) )
V_8 -> V_249 -= V_240 ;
F_121 ( V_8 ) ;
}
int F_122 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_74 ,
unsigned int V_237 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_250 ;
int V_251 , V_252 ;
int V_253 ;
T_8 V_81 ;
if ( F_123 ( V_74 > V_4 -> V_74 ) )
return - V_254 ;
V_251 = F_124 ( V_4 ) - V_74 ;
if ( V_251 < 0 )
V_251 = 0 ;
if ( F_125 ( V_4 , V_174 ) )
return - V_255 ;
V_250 = F_126 ( V_2 , V_251 , V_174 ) ;
if ( V_250 == NULL )
return - V_255 ;
V_2 -> V_236 += V_250 -> V_197 ;
F_112 ( V_2 , V_250 -> V_197 ) ;
V_253 = V_4 -> V_74 - V_74 - V_251 ;
V_250 -> V_197 += V_253 ;
V_4 -> V_197 -= V_253 ;
F_5 ( V_250 ) -> V_75 = F_5 ( V_4 ) -> V_75 + V_74 ;
F_5 ( V_250 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_250 ) -> V_75 ;
V_81 = F_5 ( V_4 ) -> V_60 ;
F_5 ( V_4 ) -> V_60 = V_81 & ~ ( V_89 | V_256 ) ;
F_5 ( V_250 ) -> V_60 = V_81 ;
F_5 ( V_250 ) -> V_85 = F_5 ( V_4 ) -> V_85 ;
if ( ! F_41 ( V_4 ) -> V_257 && V_4 -> V_82 != V_83 ) {
V_250 -> V_84 = F_127 ( V_4 -> V_175 + V_74 ,
F_128 ( V_250 , V_251 ) ,
V_251 , 0 ) ;
F_129 ( V_4 , V_74 ) ;
V_4 -> V_84 = F_130 ( V_4 -> V_84 , V_250 -> V_84 , V_74 ) ;
} else {
V_4 -> V_82 = V_83 ;
F_131 ( V_4 , V_250 , V_74 ) ;
}
V_250 -> V_82 = V_4 -> V_82 ;
F_5 ( V_250 ) -> V_147 = F_5 ( V_4 ) -> V_147 ;
V_250 -> V_258 = V_4 -> V_258 ;
V_252 = F_6 ( V_4 ) ;
F_113 ( V_2 , V_4 , V_237 ) ;
F_113 ( V_2 , V_250 , V_237 ) ;
if ( ! F_9 ( V_8 -> V_11 , F_5 ( V_250 ) -> V_12 ) ) {
int V_259 = V_252 - F_6 ( V_4 ) -
F_6 ( V_250 ) ;
if ( V_259 )
F_119 ( V_2 , V_4 , V_259 ) ;
}
F_110 ( V_250 ) ;
F_132 ( V_4 , V_250 , V_2 ) ;
return 0 ;
}
static void F_133 ( struct V_3 * V_4 , int V_74 )
{
int V_194 , V_260 , V_261 ;
V_261 = F_28 ( int , V_74 , F_124 ( V_4 ) ) ;
if ( V_261 ) {
F_134 ( V_4 , V_261 ) ;
V_74 -= V_261 ;
if ( ! V_74 )
return;
}
V_261 = V_74 ;
V_260 = 0 ;
for ( V_194 = 0 ; V_194 < F_41 ( V_4 ) -> V_257 ; V_194 ++ ) {
int V_164 = F_135 ( & F_41 ( V_4 ) -> V_262 [ V_194 ] ) ;
if ( V_164 <= V_261 ) {
F_136 ( V_4 , V_194 ) ;
V_261 -= V_164 ;
} else {
F_41 ( V_4 ) -> V_262 [ V_260 ] = F_41 ( V_4 ) -> V_262 [ V_194 ] ;
if ( V_261 ) {
F_41 ( V_4 ) -> V_262 [ V_260 ] . V_263 += V_261 ;
F_137 ( & F_41 ( V_4 ) -> V_262 [ V_260 ] , V_261 ) ;
V_261 = 0 ;
}
V_260 ++ ;
}
}
F_41 ( V_4 ) -> V_257 = V_260 ;
F_138 ( V_4 ) ;
V_4 -> V_264 -= V_74 ;
V_4 -> V_74 = V_4 -> V_264 ;
}
int F_139 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_74 )
{
if ( F_125 ( V_4 , V_174 ) )
return - V_255 ;
F_133 ( V_4 , V_74 ) ;
F_5 ( V_4 ) -> V_75 += V_74 ;
V_4 -> V_82 = V_83 ;
V_4 -> V_197 -= V_74 ;
V_2 -> V_236 -= V_74 ;
F_140 ( V_2 , V_74 ) ;
F_141 ( V_2 , V_265 ) ;
if ( F_6 ( V_4 ) > 1 )
F_113 ( V_2 , V_4 , F_142 ( V_4 ) ) ;
return 0 ;
}
static inline int F_143 ( struct V_1 * V_2 , int V_266 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_237 ;
V_237 = V_266 - V_6 -> V_228 -> V_267 - sizeof( struct V_69 ) ;
if ( V_6 -> V_228 -> V_268 ) {
const struct V_16 * V_17 = F_12 ( V_2 ) ;
if ( V_17 && F_144 ( V_17 ) )
V_237 -= V_6 -> V_228 -> V_268 ;
}
if ( V_237 > V_8 -> V_56 . V_269 )
V_237 = V_8 -> V_56 . V_269 ;
V_237 -= V_6 -> V_270 ;
if ( V_237 < 48 )
V_237 = 48 ;
return V_237 ;
}
int F_145 ( struct V_1 * V_2 , int V_266 )
{
return F_143 ( V_2 , V_266 ) -
( F_3 ( V_2 ) -> V_73 - sizeof( struct V_69 ) ) ;
}
int F_146 ( struct V_1 * V_2 , int V_18 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_271 ;
V_271 = V_18 +
V_8 -> V_73 +
V_6 -> V_270 +
V_6 -> V_228 -> V_267 ;
if ( V_6 -> V_228 -> V_268 ) {
const struct V_16 * V_17 = F_12 ( V_2 ) ;
if ( V_17 && F_144 ( V_17 ) )
V_271 += V_6 -> V_228 -> V_268 ;
}
return V_271 ;
}
void F_147 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_272 . V_273 = V_274 > 1 ;
V_6 -> V_272 . V_275 = V_8 -> V_56 . V_269 + sizeof( struct V_69 ) +
V_6 -> V_228 -> V_267 ;
V_6 -> V_272 . V_276 = F_146 ( V_2 , V_277 ) ;
V_6 -> V_272 . V_278 = 0 ;
}
unsigned int F_148 ( struct V_1 * V_2 , T_4 V_266 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_237 ;
if ( V_6 -> V_272 . V_275 > V_266 )
V_6 -> V_272 . V_275 = V_266 ;
V_237 = F_145 ( V_2 , V_266 ) ;
V_237 = F_149 ( V_8 , V_237 ) ;
V_6 -> V_279 = V_266 ;
if ( V_6 -> V_272 . V_273 )
V_237 = F_18 ( V_237 , F_145 ( V_2 , V_6 -> V_272 . V_276 ) ) ;
V_8 -> V_280 = V_237 ;
return V_237 ;
}
unsigned int F_56 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_16 * V_17 = F_12 ( V_2 ) ;
T_4 V_237 ;
unsigned int V_281 ;
struct V_93 V_94 ;
struct V_135 * V_136 ;
V_237 = V_8 -> V_280 ;
if ( V_17 ) {
T_4 V_271 = F_150 ( V_17 ) ;
if ( V_271 != F_2 ( V_2 ) -> V_279 )
V_237 = F_148 ( V_2 , V_271 ) ;
}
V_281 = F_53 ( V_2 , NULL , & V_94 , & V_136 ) +
sizeof( struct V_69 ) ;
if ( V_281 != V_8 -> V_73 ) {
int V_21 = ( int ) V_281 - V_8 -> V_73 ;
V_237 -= V_21 ;
}
return V_237 ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_10 >= V_8 -> V_26 ) {
V_8 -> V_31 = 0 ;
V_8 -> V_30 = V_22 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_31 )
V_8 -> V_31 = V_8 -> V_10 ;
if ( V_33 &&
( T_3 ) ( V_22 - V_8 -> V_30 ) >= F_2 ( V_2 ) -> V_29 )
F_152 ( V_2 ) ;
}
}
static unsigned int F_153 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_237 , unsigned int V_282 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_283 , V_222 , V_284 ;
V_222 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
V_284 = V_237 * V_282 ;
if ( F_48 ( V_284 <= V_222 && V_4 != F_154 ( V_2 ) ) )
return V_284 ;
V_283 = F_18 ( V_4 -> V_74 , V_222 ) ;
if ( V_284 <= V_283 )
return V_284 ;
return V_283 - V_283 % V_237 ;
}
static inline unsigned int F_155 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_285 , V_25 ;
if ( ( F_5 ( V_4 ) -> V_60 & V_89 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_285 = F_97 ( V_8 ) ;
V_25 = V_8 -> V_26 ;
if ( V_285 < V_25 )
return ( V_25 - V_285 ) ;
return 0 ;
}
static int F_156 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_237 )
{
int V_286 = F_6 ( V_4 ) ;
if ( ! V_286 || ( V_286 > 1 && F_142 ( V_4 ) != V_237 ) ) {
F_113 ( V_2 , V_4 , V_237 ) ;
V_286 = F_6 ( V_4 ) ;
}
return V_286 ;
}
static inline bool F_157 ( const struct V_7 * V_8 )
{
return F_104 ( V_8 -> V_287 , V_8 -> V_90 ) &&
! F_104 ( V_8 -> V_287 , V_8 -> V_11 ) ;
}
static inline bool F_158 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_237 , int V_288 )
{
return V_4 -> V_74 < V_237 &&
( ( V_288 & V_289 ) ||
( ! V_288 && V_8 -> V_10 && F_157 ( V_8 ) ) ) ;
}
static inline bool F_159 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_290 , int V_288 )
{
if ( V_288 & V_291 )
return true ;
if ( F_44 ( V_8 ) || ( F_5 ( V_4 ) -> V_60 & V_89 ) )
return true ;
if ( ! F_158 ( V_8 , V_4 , V_290 , V_288 ) )
return true ;
return false ;
}
static bool F_160 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_290 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_74 > V_290 )
V_12 = F_5 ( V_4 ) -> V_75 + V_290 ;
return ! F_104 ( V_12 , F_10 ( V_8 ) ) ;
}
static unsigned int F_161 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_290 , int V_288 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_292 ;
F_156 ( V_2 , V_4 , V_290 ) ;
if ( ! F_159 ( V_8 , V_4 , V_290 , V_288 ) )
return 0 ;
V_292 = F_155 ( V_8 , V_4 ) ;
if ( V_292 && ! F_160 ( V_8 , V_4 , V_290 ) )
V_292 = 0 ;
return V_292 ;
}
bool F_162 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_163 ( V_2 ) ;
return V_4 &&
F_161 ( V_2 , V_4 , F_56 ( V_2 ) ,
( F_164 ( V_2 , V_4 ) ?
V_8 -> V_288 : V_291 ) ) ;
}
static int F_165 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_74 ,
unsigned int V_237 , T_11 V_293 )
{
struct V_3 * V_250 ;
int V_253 = V_4 -> V_74 - V_74 ;
T_8 V_81 ;
if ( V_4 -> V_74 != V_4 -> V_264 )
return F_122 ( V_2 , V_4 , V_74 , V_237 ) ;
V_250 = F_126 ( V_2 , 0 , V_293 ) ;
if ( F_46 ( V_250 == NULL ) )
return - V_255 ;
V_2 -> V_236 += V_250 -> V_197 ;
F_112 ( V_2 , V_250 -> V_197 ) ;
V_250 -> V_197 += V_253 ;
V_4 -> V_197 -= V_253 ;
F_5 ( V_250 ) -> V_75 = F_5 ( V_4 ) -> V_75 + V_74 ;
F_5 ( V_250 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_250 ) -> V_75 ;
V_81 = F_5 ( V_4 ) -> V_60 ;
F_5 ( V_4 ) -> V_60 = V_81 & ~ ( V_89 | V_256 ) ;
F_5 ( V_250 ) -> V_60 = V_81 ;
F_5 ( V_250 ) -> V_85 = 0 ;
V_250 -> V_82 = V_4 -> V_82 = V_83 ;
F_131 ( V_4 , V_250 , V_74 ) ;
F_113 ( V_2 , V_4 , V_237 ) ;
F_113 ( V_2 , V_250 , V_237 ) ;
F_110 ( V_250 ) ;
F_132 ( V_4 , V_250 , V_2 ) ;
return 0 ;
}
static bool F_166 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_294 , V_295 , V_296 , V_285 ;
int V_297 ;
if ( F_5 ( V_4 ) -> V_60 & V_89 )
goto V_298;
if ( V_6 -> V_299 != V_300 )
goto V_298;
if ( V_8 -> V_301 &&
( ( ( T_4 ) V_302 << 1 ) >> 1 ) - ( V_8 -> V_301 >> 1 ) > 1 )
goto V_298;
V_285 = F_97 ( V_8 ) ;
F_90 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_26 <= V_285 ) ) ;
V_294 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
V_295 = ( V_8 -> V_26 - V_285 ) * V_8 -> V_280 ;
V_296 = F_18 ( V_294 , V_295 ) ;
if ( V_296 >= F_28 (unsigned int, sk->sk_gso_max_size,
tp->xmit_size_goal_segs * tp->mss_cache) )
goto V_298;
if ( ( V_4 != F_154 ( V_2 ) ) && ( V_296 >= V_4 -> V_74 ) )
goto V_298;
V_297 = F_167 ( V_303 ) ;
if ( V_297 ) {
T_4 V_304 = F_18 ( V_8 -> V_305 , V_8 -> V_26 * V_8 -> V_280 ) ;
V_304 /= V_297 ;
if ( V_296 >= V_304 )
goto V_298;
} else {
if ( V_296 > F_168 ( V_8 ) * V_8 -> V_280 )
goto V_298;
}
if ( ! V_8 -> V_301 )
V_8 -> V_301 = 1 | ( V_302 << 1 ) ;
return true ;
V_298:
V_8 -> V_301 = 0 ;
return false ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_306 , * V_307 ;
int V_74 ;
int V_278 ;
int V_308 ;
int V_309 ;
int V_237 ;
if ( ! V_6 -> V_272 . V_273 ||
V_6 -> V_272 . V_278 ||
F_2 ( V_2 ) -> V_299 != V_300 ||
V_8 -> V_26 < 11 ||
V_8 -> V_56 . V_166 || V_8 -> V_56 . V_118 )
return - 1 ;
V_237 = F_56 ( V_2 ) ;
V_278 = 2 * V_8 -> V_280 ;
V_308 = V_278 + ( V_8 -> V_310 + 1 ) * V_8 -> V_280 ;
if ( V_278 > F_145 ( V_2 , V_6 -> V_272 . V_275 ) ) {
return - 1 ;
}
if ( V_8 -> V_235 - V_8 -> V_11 < V_308 )
return - 1 ;
if ( V_8 -> V_305 < V_308 )
return - 1 ;
if ( F_104 ( V_8 -> V_11 + V_308 , F_10 ( V_8 ) ) )
return 0 ;
if ( F_97 ( V_8 ) + 2 > V_8 -> V_26 ) {
if ( ! F_97 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_306 = F_126 ( V_2 , V_278 , V_174 ) ) == NULL )
return - 1 ;
V_2 -> V_236 += V_306 -> V_197 ;
F_112 ( V_2 , V_306 -> V_197 ) ;
V_4 = F_163 ( V_2 ) ;
F_5 ( V_306 ) -> V_75 = F_5 ( V_4 ) -> V_75 ;
F_5 ( V_306 ) -> V_12 = F_5 ( V_4 ) -> V_75 + V_278 ;
F_5 ( V_306 ) -> V_60 = V_230 ;
F_5 ( V_306 ) -> V_85 = 0 ;
V_306 -> V_84 = 0 ;
V_306 -> V_82 = V_4 -> V_82 ;
F_170 ( V_306 , V_4 , V_2 ) ;
V_74 = 0 ;
F_171 (skb, next, sk) {
V_309 = F_28 ( int , V_4 -> V_74 , V_278 - V_74 ) ;
if ( V_306 -> V_82 )
F_172 ( V_4 , 0 , F_128 ( V_306 , V_309 ) , V_309 ) ;
else
V_306 -> V_84 = F_173 ( V_4 , 0 ,
F_128 ( V_306 , V_309 ) ,
V_309 , V_306 -> V_84 ) ;
if ( V_4 -> V_74 <= V_309 ) {
F_5 ( V_306 ) -> V_60 |= F_5 ( V_4 ) -> V_60 ;
F_174 ( V_4 , V_2 ) ;
F_175 ( V_2 , V_4 ) ;
} else {
F_5 ( V_306 ) -> V_60 |= F_5 ( V_4 ) -> V_60 &
~ ( V_89 | V_256 ) ;
if ( ! F_41 ( V_4 ) -> V_257 ) {
F_176 ( V_4 , V_309 ) ;
if ( V_4 -> V_82 != V_83 )
V_4 -> V_84 = F_177 ( V_4 -> V_175 ,
V_4 -> V_74 , 0 ) ;
} else {
F_133 ( V_4 , V_309 ) ;
F_113 ( V_2 , V_4 , V_237 ) ;
}
F_5 ( V_4 ) -> V_75 += V_309 ;
}
V_74 += V_309 ;
if ( V_74 >= V_278 )
break;
}
F_156 ( V_2 , V_306 , V_306 -> V_74 ) ;
F_5 ( V_306 ) -> V_147 = V_22 ;
if ( ! F_89 ( V_2 , V_306 , 1 , V_174 ) ) {
V_8 -> V_26 -- ;
F_1 ( V_2 , V_306 ) ;
V_6 -> V_272 . V_278 = F_146 ( V_2 , V_306 -> V_74 ) ;
V_8 -> V_311 . V_312 = F_5 ( V_306 ) -> V_75 ;
V_8 -> V_311 . V_313 = F_5 ( V_306 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_55 ( struct V_1 * V_2 , unsigned int V_237 , int V_288 ,
int V_314 , T_11 V_293 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_286 , V_315 ;
int V_292 ;
int V_316 ;
V_315 = 0 ;
if ( ! V_314 ) {
V_316 = F_169 ( V_2 ) ;
if ( ! V_316 ) {
return false ;
} else if ( V_316 > 0 ) {
V_315 = 1 ;
}
}
while ( ( V_4 = F_163 ( V_2 ) ) ) {
unsigned int V_296 ;
V_286 = F_156 ( V_2 , V_4 , V_237 ) ;
F_90 ( ! V_286 ) ;
if ( F_46 ( V_8 -> V_317 ) && V_8 -> V_318 == V_319 )
goto V_317;
V_292 = F_155 ( V_8 , V_4 ) ;
if ( ! V_292 ) {
if ( V_314 == 2 )
V_292 = 1 ;
else
break;
}
if ( F_46 ( ! F_160 ( V_8 , V_4 , V_237 ) ) )
break;
if ( V_286 == 1 ) {
if ( F_46 ( ! F_159 ( V_8 , V_4 , V_237 ,
( F_164 ( V_2 , V_4 ) ?
V_288 : V_291 ) ) ) )
break;
} else {
if ( ! V_314 && F_166 ( V_2 , V_4 ) )
break;
}
V_296 = F_27 (unsigned int, sysctl_tcp_limit_output_bytes,
sk->sk_pacing_rate >> 10 ) ;
if ( F_178 ( & V_2 -> V_198 ) > V_296 ) {
F_67 ( V_196 , & V_8 -> V_185 ) ;
break;
}
V_296 = V_237 ;
if ( V_286 > 1 && ! F_44 ( V_8 ) )
V_296 = F_153 ( V_2 , V_4 , V_237 ,
F_28 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ) ;
if ( V_4 -> V_74 > V_296 &&
F_46 ( F_165 ( V_2 , V_4 , V_296 , V_237 , V_293 ) ) )
break;
F_5 ( V_4 ) -> V_147 = V_22 ;
if ( F_46 ( F_89 ( V_2 , V_4 , 1 , V_293 ) ) )
break;
V_317:
F_1 ( V_2 , V_4 ) ;
F_179 ( V_8 , V_237 , V_4 ) ;
V_315 += F_6 ( V_4 ) ;
if ( V_314 )
break;
}
if ( F_48 ( V_315 ) ) {
if ( F_180 ( V_2 ) )
V_8 -> V_320 += V_315 ;
if ( V_314 != 2 )
F_181 ( V_2 ) ;
F_151 ( V_2 ) ;
return false ;
}
return ( V_314 == 2 ) || ( ! V_8 -> V_10 && F_163 ( V_2 ) ) ;
}
bool F_181 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_321 , V_322 , V_323 ;
T_4 V_324 = V_8 -> V_325 >> 3 ;
if ( F_123 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_123 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_168 == V_326 )
return false ;
if ( V_6 -> V_13 != V_327 )
return false ;
if ( V_328 < 3 || ! V_324 || ! V_8 -> V_10 ||
! F_182 ( V_8 ) || F_2 ( V_2 ) -> V_299 != V_300 )
return false ;
if ( ( V_8 -> V_26 > F_97 ( V_8 ) ) &&
F_163 ( V_2 ) )
return false ;
V_321 = V_324 << 1 ;
if ( V_8 -> V_10 == 1 )
V_321 = F_27 ( T_4 , V_321 ,
( V_324 + ( V_324 >> 1 ) + V_329 ) ) ;
V_321 = F_27 ( T_4 , V_321 , F_183 ( 10 ) ) ;
V_322 = V_22 + V_321 ;
V_323 = ( T_4 ) F_2 ( V_2 ) -> V_330 ;
if ( ( T_3 ) ( V_322 - V_323 ) > 0 ) {
T_3 V_21 = V_323 - V_22 ;
if ( V_21 > 0 )
V_321 = V_21 ;
}
F_184 ( V_2 , V_15 , V_321 ,
V_331 ) ;
return true ;
}
void F_185 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_332 ;
int V_18 = F_56 ( V_2 ) ;
int V_205 = - 1 ;
if ( F_163 ( V_2 ) != NULL ) {
V_205 = F_55 ( V_2 , V_18 , V_333 , 2 , V_174 ) ;
goto V_334;
}
if ( V_8 -> V_335 )
goto V_334;
V_4 = F_154 ( V_2 ) ;
if ( F_123 ( ! V_4 ) )
goto V_334;
V_332 = F_6 ( V_4 ) ;
if ( F_123 ( ! V_332 ) )
goto V_334;
if ( ( V_332 > 1 ) && ( V_4 -> V_74 > ( V_332 - 1 ) * V_18 ) ) {
if ( F_46 ( F_122 ( V_2 , V_4 , ( V_332 - 1 ) * V_18 , V_18 ) ) )
goto V_334;
V_4 = F_154 ( V_2 ) ;
}
if ( F_123 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_334;
if ( V_4 -> V_74 > 0 )
V_205 = F_186 ( V_2 , V_4 ) ;
if ( F_48 ( ! V_205 ) )
V_8 -> V_335 = V_8 -> V_11 ;
V_334:
F_184 ( V_2 , V_327 ,
F_2 ( V_2 ) -> V_29 ,
V_331 ) ;
if ( F_48 ( ! V_205 ) )
F_92 ( F_35 ( V_2 ) ,
V_336 ) ;
return;
}
void F_187 ( struct V_1 * V_2 , unsigned int V_290 ,
int V_288 )
{
if ( F_46 ( V_2 -> V_168 == V_337 ) )
return;
if ( F_55 ( V_2 , V_290 , V_288 , 0 ,
F_188 ( V_2 , V_174 ) ) )
F_189 ( V_2 ) ;
}
void F_190 ( struct V_1 * V_2 , unsigned int V_237 )
{
struct V_3 * V_4 = F_163 ( V_2 ) ;
F_90 ( ! V_4 || V_4 -> V_74 < V_237 ) ;
F_55 ( V_2 , V_237 , V_291 , 1 , V_2 -> V_338 ) ;
}
T_4 F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_18 = V_6 -> V_34 . V_339 ;
int V_340 = F_191 ( V_2 ) ;
int V_341 = F_28 ( int , V_8 -> V_45 , F_192 ( V_2 ) ) ;
int V_222 ;
if ( V_18 > V_341 )
V_18 = V_341 ;
if ( V_340 < ( V_341 >> 1 ) ) {
V_6 -> V_34 . V_342 = 0 ;
if ( F_193 ( V_2 ) )
V_8 -> V_343 = F_18 ( V_8 -> V_343 ,
4U * V_8 -> V_19 ) ;
if ( V_340 < V_18 )
return 0 ;
}
if ( V_340 > V_8 -> V_343 )
V_340 = V_8 -> V_343 ;
V_222 = V_8 -> V_44 ;
if ( V_8 -> V_56 . V_47 ) {
V_222 = V_340 ;
if ( ( ( V_222 >> V_8 -> V_56 . V_47 ) << V_8 -> V_56 . V_47 ) != V_222 )
V_222 = ( ( ( V_222 >> V_8 -> V_56 . V_47 ) + 1 )
<< V_8 -> V_56 . V_47 ) ;
} else {
if ( V_222 <= V_340 - V_18 || V_222 > V_340 )
V_222 = ( V_340 / V_18 ) * V_18 ;
else if ( V_18 == V_341 &&
V_340 > V_222 + ( V_341 >> 1 ) )
V_222 = V_340 ;
}
return V_222 ;
}
static void F_194 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_344 = F_195 ( V_2 , V_4 ) ;
int V_345 , V_346 ;
V_345 = V_4 -> V_74 ;
V_346 = V_344 -> V_74 ;
F_90 ( F_6 ( V_4 ) != 1 || F_6 ( V_344 ) != 1 ) ;
F_196 ( V_2 , V_344 , V_4 ) ;
F_174 ( V_344 , V_2 ) ;
F_197 ( V_344 , F_128 ( V_4 , V_346 ) ,
V_346 ) ;
if ( V_344 -> V_82 == V_83 )
V_4 -> V_82 = V_83 ;
if ( V_4 -> V_82 != V_83 )
V_4 -> V_84 = F_198 ( V_4 -> V_84 , V_344 -> V_84 , V_345 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_344 ) -> V_12 ;
F_5 ( V_4 ) -> V_60 |= F_5 ( V_344 ) -> V_60 ;
F_5 ( V_4 ) -> V_85 |= F_5 ( V_344 ) -> V_85 & V_347 ;
F_199 ( V_8 ) ;
if ( V_344 == V_8 -> V_348 )
V_8 -> V_348 = V_4 ;
F_119 ( V_2 , V_344 , F_6 ( V_344 ) ) ;
F_175 ( V_2 , V_344 ) ;
}
static bool F_200 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_41 ( V_4 ) -> V_257 != 0 )
return false ;
if ( F_93 ( V_4 ) )
return false ;
if ( V_4 == F_163 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_85 & V_243 )
return false ;
return true ;
}
static void F_201 ( struct V_1 * V_2 , struct V_3 * V_349 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_349 , * V_350 ;
bool V_351 = true ;
if ( ! V_352 )
return;
if ( F_5 ( V_4 ) -> V_60 & V_88 )
return;
F_171 (skb, tmp, sk) {
if ( ! F_200 ( V_2 , V_4 ) )
break;
V_49 -= V_4 -> V_74 ;
if ( V_351 ) {
V_351 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_74 > F_202 ( V_349 ) )
break;
if ( F_104 ( F_5 ( V_4 ) -> V_12 , F_10 ( V_8 ) ) )
break;
F_194 ( V_2 , V_349 ) ;
}
}
int F_186 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_290 ;
if ( V_6 -> V_272 . V_278 ) {
V_6 -> V_272 . V_278 = 0 ;
}
if ( F_178 ( & V_2 -> V_198 ) >
F_18 ( V_2 -> V_236 + ( V_2 -> V_236 >> 2 ) , V_2 -> V_353 ) )
return - V_354 ;
if ( F_9 ( F_5 ( V_4 ) -> V_75 , V_8 -> V_90 ) ) {
if ( F_9 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_90 ) )
F_203 () ;
if ( F_139 ( V_2 , V_4 , V_8 -> V_90 - F_5 ( V_4 ) -> V_75 ) )
return - V_255 ;
}
if ( F_2 ( V_2 ) -> V_228 -> V_355 ( V_2 ) )
return - V_356 ;
V_290 = F_56 ( V_2 ) ;
if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , F_10 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_75 != V_8 -> V_90 )
return - V_354 ;
if ( V_4 -> V_74 > V_290 ) {
if ( F_122 ( V_2 , V_4 , V_290 , V_290 ) )
return - V_255 ;
} else {
int V_357 = F_6 ( V_4 ) ;
if ( F_46 ( V_357 > 1 ) ) {
if ( F_125 ( V_4 , V_174 ) )
return - V_255 ;
F_156 ( V_2 , V_4 , V_290 ) ;
F_119 ( V_2 , V_4 , V_357 - F_6 ( V_4 ) ) ;
}
}
F_201 ( V_2 , V_4 , V_290 ) ;
F_5 ( V_4 ) -> V_147 = V_22 ;
if ( F_46 ( ( V_358 && ( ( unsigned long ) V_4 -> V_175 & 3 ) ) ||
F_204 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_306 = F_205 ( V_4 , V_359 ,
V_174 ) ;
return V_306 ? F_89 ( V_2 , V_306 , 0 , V_174 ) :
- V_212 ;
} else {
return F_89 ( V_2 , V_4 , 1 , V_174 ) ;
}
}
int F_206 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_205 = F_186 ( V_2 , V_4 ) ;
if ( V_205 == 0 ) {
F_207 ( F_35 ( V_2 ) , V_360 ) ;
V_8 -> V_361 ++ ;
#if V_362 > 0
if ( F_5 ( V_4 ) -> V_85 & V_244 ) {
F_208 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_245 )
V_8 -> V_363 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_85 |= V_364 ;
V_8 -> V_245 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_365 )
V_8 -> V_365 = F_5 ( V_4 ) -> V_147 ;
V_8 -> V_366 += F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_220 = V_8 -> V_11 ;
} else {
F_92 ( F_35 ( V_2 ) , V_367 ) ;
}
return V_205 ;
}
static bool F_209 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_299 != V_368 )
return false ;
if ( F_117 ( V_8 ) )
return false ;
if ( F_162 ( V_2 ) )
return false ;
return true ;
}
void F_210 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_369 = NULL ;
T_4 V_370 ;
int V_371 ;
int V_372 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_247 )
V_8 -> V_373 = V_8 -> V_90 ;
if ( V_8 -> V_348 ) {
V_4 = V_8 -> V_348 ;
V_370 = F_5 ( V_4 ) -> V_12 ;
if ( F_104 ( V_370 , V_8 -> V_373 ) )
V_370 = V_8 -> V_373 ;
} else {
V_4 = F_211 ( V_2 ) ;
V_370 = V_8 -> V_90 ;
}
F_212 (skb, sk) {
T_5 V_85 = F_5 ( V_4 ) -> V_85 ;
if ( V_4 == F_163 ( V_2 ) )
break;
if ( V_369 == NULL )
V_8 -> V_348 = V_4 ;
if ( F_97 ( V_8 ) >= V_8 -> V_26 )
return;
if ( V_372 ) {
V_374:
if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , F_118 ( V_8 ) ) )
break;
V_371 = V_375 ;
} else if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , V_8 -> V_373 ) ) {
V_8 -> V_373 = V_370 ;
if ( ! F_209 ( V_2 ) )
break;
if ( V_369 != NULL ) {
V_4 = V_369 ;
V_369 = NULL ;
}
V_372 = 1 ;
goto V_374;
} else if ( ! ( V_85 & V_246 ) ) {
if ( V_369 == NULL && ! ( V_85 & ( V_244 | V_243 ) ) )
V_369 = V_4 ;
continue;
} else {
V_370 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_299 != V_376 )
V_371 = V_377 ;
else
V_371 = V_378 ;
}
if ( V_85 & ( V_243 | V_244 ) )
continue;
if ( F_206 ( V_2 , V_4 ) )
return;
F_92 ( F_35 ( V_2 ) , V_371 ) ;
if ( F_180 ( V_2 ) )
V_8 -> V_320 += F_6 ( V_4 ) ;
if ( V_4 == F_211 ( V_2 ) )
F_184 ( V_2 , V_327 ,
F_2 ( V_2 ) -> V_29 ,
V_331 ) ;
}
}
void F_213 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_154 ( V_2 ) ;
int V_237 ;
V_237 = F_56 ( V_2 ) ;
if ( F_163 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_60 |= V_89 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_235 ++ ;
} else {
for (; ; ) {
V_4 = F_214 ( V_359 ,
V_2 -> V_338 ) ;
if ( V_4 )
break;
F_215 () ;
}
F_216 ( V_4 , V_359 ) ;
F_43 ( V_4 , V_8 -> V_235 ,
V_230 | V_89 ) ;
F_109 ( V_2 , V_4 ) ;
}
F_187 ( V_2 , V_237 , V_333 ) ;
}
void F_217 ( struct V_1 * V_2 , T_11 V_379 )
{
struct V_3 * V_4 ;
V_4 = F_218 ( V_359 , V_379 ) ;
if ( ! V_4 ) {
F_219 ( F_35 ( V_2 ) , V_380 ) ;
return;
}
F_216 ( V_4 , V_359 ) ;
F_43 ( V_4 , F_8 ( V_2 ) ,
V_230 | V_381 ) ;
F_5 ( V_4 ) -> V_147 = V_22 ;
if ( F_89 ( V_2 , V_4 , 0 , V_379 ) )
F_219 ( F_35 ( V_2 ) , V_380 ) ;
F_207 ( F_35 ( V_2 ) , V_382 ) ;
}
int F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_211 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_60 & V_88 ) ) {
F_221 ( L_2 , V_383 ) ;
return - V_384 ;
}
if ( ! ( F_5 ( V_4 ) -> V_60 & V_230 ) ) {
if ( F_93 ( V_4 ) ) {
struct V_3 * V_306 = F_222 ( V_4 , V_174 ) ;
if ( V_306 == NULL )
return - V_255 ;
F_174 ( V_4 , V_2 ) ;
F_110 ( V_306 ) ;
F_223 ( V_2 , V_306 ) ;
F_175 ( V_2 , V_4 ) ;
V_2 -> V_236 += V_306 -> V_197 ;
F_112 ( V_2 , V_306 -> V_197 ) ;
V_4 = V_306 ;
}
F_5 ( V_4 ) -> V_60 |= V_230 ;
F_33 ( F_3 ( V_2 ) , V_4 ) ;
}
F_5 ( V_4 ) -> V_147 = V_22 ;
return F_89 ( V_2 , V_4 , 1 , V_174 ) ;
}
struct V_3 * F_224 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_67 * V_68 ,
struct V_127 * V_128 )
{
struct V_93 V_94 ;
struct V_158 * V_159 = F_37 ( V_68 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_69 * V_70 ;
struct V_3 * V_4 ;
struct V_135 * V_136 ;
int V_204 ;
int V_18 ;
V_4 = F_225 ( V_2 , V_359 + 15 , 1 , V_174 ) ;
if ( F_46 ( ! V_4 ) ) {
F_226 ( V_17 ) ;
return NULL ;
}
F_216 ( V_4 , V_359 ) ;
F_227 ( V_4 , V_17 ) ;
F_228 ( V_4 , V_2 ) ;
V_18 = F_13 ( V_17 ) ;
if ( V_8 -> V_56 . V_385 && V_8 -> V_56 . V_385 < V_18 )
V_18 = V_8 -> V_56 . V_385 ;
if ( V_68 -> V_44 == 0 ) {
T_5 V_47 ;
V_68 -> V_45 = V_8 -> V_45 ? : F_21 ( V_17 , V_386 ) ;
if ( V_2 -> V_387 & V_388 &&
( V_68 -> V_45 > F_192 ( V_2 ) || V_68 -> V_45 == 0 ) )
V_68 -> V_45 = F_192 ( V_2 ) ;
F_26 ( F_192 ( V_2 ) ,
V_18 - ( V_159 -> V_160 ? V_150 : 0 ) ,
& V_68 -> V_44 ,
& V_68 -> V_45 ,
V_159 -> V_46 ,
& V_47 ,
F_21 ( V_17 , V_389 ) ) ;
V_159 -> V_47 = V_47 ;
}
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
#ifdef F_229
if ( F_46 ( V_68 -> V_390 ) )
F_5 ( V_4 ) -> V_147 = F_230 ( V_68 ) ;
else
#endif
F_5 ( V_4 ) -> V_147 = V_22 ;
V_204 = F_51 ( V_2 , V_68 , V_18 , V_4 , & V_94 , & V_136 ,
V_128 ) + sizeof( * V_70 ) ;
F_99 ( V_4 , V_204 ) ;
F_100 ( V_4 ) ;
V_70 = F_40 ( V_4 ) ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_391 = 1 ;
V_70 -> V_392 = 1 ;
F_36 ( V_68 , V_70 ) ;
V_70 -> V_216 = F_103 ( V_159 -> V_393 ) ;
V_70 -> V_218 = V_159 -> V_394 ;
F_43 ( V_4 , F_52 ( V_68 ) -> V_395 ,
V_88 | V_230 ) ;
V_70 -> V_75 = F_47 ( F_5 ( V_4 ) -> V_75 ) ;
V_70 -> V_220 = F_47 ( F_52 ( V_68 ) -> V_58 ) ;
V_70 -> V_222 = F_103 ( F_18 ( V_68 -> V_44 , 65535U ) ) ;
F_45 ( ( T_9 * ) ( V_70 + 1 ) , V_8 , & V_94 ) ;
V_70 -> V_396 = ( V_204 >> 2 ) ;
F_106 ( F_35 ( V_2 ) , V_231 , F_6 ( V_4 ) ) ;
#ifdef F_50
if ( V_136 ) {
F_52 ( V_68 ) -> V_142 -> V_227 ( V_94 . V_100 ,
V_136 , NULL , V_68 , V_4 ) ;
}
#endif
return V_4 ;
}
void F_231 ( struct V_1 * V_2 )
{
const struct V_16 * V_17 = F_12 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_47 ;
V_8 -> V_73 = sizeof( struct V_69 ) +
( V_146 ? V_150 : 0 ) ;
#ifdef F_50
if ( V_8 -> V_142 -> V_143 ( V_2 , V_2 ) != NULL )
V_8 -> V_73 += V_144 ;
#endif
if ( V_8 -> V_56 . V_385 )
V_8 -> V_56 . V_269 = V_8 -> V_56 . V_385 ;
V_8 -> V_397 = 0 ;
F_147 ( V_2 ) ;
F_148 ( V_2 , F_150 ( V_17 ) ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_21 ( V_17 , V_386 ) ;
V_8 -> V_19 = F_13 ( V_17 ) ;
if ( V_8 -> V_56 . V_385 && V_8 -> V_56 . V_385 < V_8 -> V_19 )
V_8 -> V_19 = V_8 -> V_56 . V_385 ;
F_232 ( V_2 ) ;
if ( V_2 -> V_387 & V_388 &&
( V_8 -> V_45 > F_192 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_192 ( V_2 ) ;
F_26 ( F_192 ( V_2 ) ,
V_8 -> V_19 - ( V_8 -> V_56 . V_398 ? V_8 -> V_73 - sizeof( struct V_69 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_151 ,
& V_47 ,
F_21 ( V_17 , V_389 ) ) ;
V_8 -> V_56 . V_47 = V_47 ;
V_8 -> V_343 = V_8 -> V_44 ;
V_2 -> V_399 = 0 ;
F_233 ( V_2 , V_400 ) ;
V_8 -> V_305 = 0 ;
F_234 ( V_8 , 0 ) ;
V_8 -> V_90 = V_8 -> V_235 ;
V_8 -> V_287 = V_8 -> V_235 ;
V_8 -> V_91 = V_8 -> V_235 ;
V_8 -> V_11 = V_8 -> V_235 ;
if ( F_48 ( ! V_8 -> V_317 ) )
V_8 -> V_58 = 0 ;
else
V_8 -> V_401 = V_22 ;
V_8 -> V_57 = V_8 -> V_58 ;
V_8 -> V_402 = V_8 -> V_58 ;
F_2 ( V_2 ) -> V_29 = V_403 ;
F_2 ( V_2 ) -> V_404 = 0 ;
F_235 ( V_8 ) ;
}
static void F_236 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_162 * V_163 = F_5 ( V_4 ) ;
V_163 -> V_12 += V_4 -> V_74 ;
F_110 ( V_4 ) ;
F_237 ( V_2 , V_4 ) ;
V_2 -> V_236 += V_4 -> V_197 ;
F_112 ( V_2 , V_4 -> V_197 ) ;
V_8 -> V_235 = V_163 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_238 ( struct V_1 * V_2 , struct V_3 * V_391 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_139 * V_405 = V_8 -> V_141 ;
int V_406 = 0 , V_49 , V_194 , V_205 = 0 , V_407 = V_405 -> V_175 -> V_408 ;
struct V_3 * V_409 = NULL , * V_175 ;
unsigned long V_410 = 0 ;
V_8 -> V_56 . V_269 = V_8 -> V_19 ;
F_239 ( V_2 , & V_8 -> V_56 . V_269 , & V_405 -> V_155 ,
& V_406 , & V_410 ) ;
if ( V_406 > 1 &&
F_240 ( V_302 , V_410 + ( 60 * V_411 << V_406 ) ) ) {
V_405 -> V_155 . V_74 = - 1 ;
goto V_412;
}
if ( V_413 & V_414 )
V_405 -> V_155 . V_74 = - 1 ;
else if ( V_405 -> V_155 . V_74 <= 0 )
goto V_412;
if ( V_8 -> V_56 . V_385 && V_8 -> V_56 . V_385 < V_8 -> V_56 . V_269 )
V_8 -> V_56 . V_269 = V_8 -> V_56 . V_385 ;
V_49 = F_143 ( V_2 , F_2 ( V_2 ) -> V_279 ) -
V_138 ;
V_409 = F_241 ( V_391 , F_204 ( V_391 ) , V_49 ,
V_2 -> V_338 ) ;
if ( V_409 == NULL )
goto V_412;
for ( V_194 = 0 ; V_194 < V_407 && V_409 -> V_74 < V_49 ; ++ V_194 ) {
struct V_415 * V_416 = & V_405 -> V_175 -> V_417 [ V_194 ] ;
unsigned char T_12 * V_418 = V_416 -> V_419 ;
int V_74 = V_416 -> V_420 ;
if ( V_409 -> V_74 + V_74 > V_49 )
V_74 = V_49 - V_409 -> V_74 ;
else if ( V_194 + 1 == V_407 )
V_405 -> V_175 = NULL ;
if ( F_242 ( V_409 , V_418 , V_74 ) )
goto V_412;
}
V_175 = F_94 ( V_409 , V_2 -> V_338 ) ;
if ( V_175 == NULL )
goto V_412;
F_5 ( V_175 ) -> V_75 ++ ;
F_5 ( V_175 ) -> V_60 &= ~ V_88 ;
F_5 ( V_175 ) -> V_60 = ( V_230 | V_256 ) ;
F_236 ( V_2 , V_175 ) ;
V_405 -> V_421 = V_175 -> V_74 ;
if ( F_89 ( V_2 , V_409 , 0 , V_2 -> V_338 ) == 0 ) {
V_8 -> V_409 = ( V_405 -> V_421 > 0 ) ;
F_219 ( F_35 ( V_2 ) , V_422 ) ;
goto V_423;
}
V_409 = NULL ;
V_412:
if ( V_405 -> V_155 . V_74 > 0 )
V_405 -> V_155 . V_74 = 0 ;
V_205 = F_89 ( V_2 , V_391 , 1 , V_2 -> V_338 ) ;
if ( V_205 )
V_8 -> V_157 = 0 ;
F_243 ( V_409 ) ;
V_423:
V_405 -> V_155 . V_74 = - 1 ;
return V_205 ;
}
int F_244 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_250 ;
int V_205 ;
F_231 ( V_2 ) ;
if ( F_46 ( V_8 -> V_317 ) ) {
F_245 ( V_2 , NULL ) ;
return 0 ;
}
V_250 = F_214 ( V_359 + 15 , V_2 -> V_338 ) ;
if ( F_46 ( V_250 == NULL ) )
return - V_212 ;
F_216 ( V_250 , V_359 ) ;
F_43 ( V_250 , V_8 -> V_235 ++ , V_88 ) ;
V_8 -> V_365 = F_5 ( V_250 ) -> V_147 = V_22 ;
F_236 ( V_2 , V_250 ) ;
F_34 ( V_2 , V_250 ) ;
V_205 = V_8 -> V_141 ? F_238 ( V_2 , V_250 ) :
F_89 ( V_2 , V_250 , 1 , V_2 -> V_338 ) ;
if ( V_205 == - V_424 )
return V_205 ;
V_8 -> V_11 = V_8 -> V_235 ;
V_8 -> V_425 = V_8 -> V_235 ;
F_207 ( F_35 ( V_2 ) , V_426 ) ;
F_184 ( V_2 , V_327 ,
F_2 ( V_2 ) -> V_29 , V_331 ) ;
return 0 ;
}
void F_246 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 = V_6 -> V_34 . V_36 ;
unsigned long V_321 ;
if ( V_36 > V_427 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_428 = V_411 / 2 ;
if ( V_6 -> V_34 . V_38 ||
( V_6 -> V_34 . V_429 & V_430 ) )
V_428 = V_329 ;
if ( V_8 -> V_325 ) {
int V_324 = F_19 ( V_8 -> V_325 >> 3 , V_427 ) ;
if ( V_324 < V_428 )
V_428 = V_324 ;
}
V_36 = F_18 ( V_36 , V_428 ) ;
}
V_321 = V_302 + V_36 ;
if ( V_6 -> V_34 . V_429 & V_431 ) {
if ( V_6 -> V_34 . V_432 ||
F_247 ( V_6 -> V_34 . V_321 , V_302 + ( V_36 >> 2 ) ) ) {
F_248 ( V_2 ) ;
return;
}
if ( ! F_240 ( V_321 , V_6 -> V_34 . V_321 ) )
V_321 = V_6 -> V_34 . V_321 ;
}
V_6 -> V_34 . V_429 |= V_433 | V_431 ;
V_6 -> V_34 . V_321 = V_321 ;
F_249 ( V_2 , & V_6 -> V_434 , V_321 ) ;
}
void F_248 ( struct V_1 * V_2 )
{
struct V_3 * V_250 ;
if ( V_2 -> V_168 == V_337 )
return;
V_250 = F_218 ( V_359 , F_188 ( V_2 , V_174 ) ) ;
if ( V_250 == NULL ) {
F_250 ( V_2 ) ;
F_2 ( V_2 ) -> V_34 . V_36 = V_435 ;
F_184 ( V_2 , V_40 ,
V_329 , V_331 ) ;
return;
}
F_216 ( V_250 , V_359 ) ;
F_43 ( V_250 , F_8 ( V_2 ) , V_230 ) ;
F_5 ( V_250 ) -> V_147 = V_22 ;
F_89 ( V_2 , V_250 , 0 , F_188 ( V_2 , V_174 ) ) ;
}
static int F_251 ( struct V_1 * V_2 , int V_436 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_218 ( V_359 , F_188 ( V_2 , V_174 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_216 ( V_4 , V_359 ) ;
F_43 ( V_4 , V_8 -> V_90 - ! V_436 , V_230 ) ;
F_5 ( V_4 ) -> V_147 = V_22 ;
return F_89 ( V_2 , V_4 , 0 , V_174 ) ;
}
void F_252 ( struct V_1 * V_2 )
{
if ( V_2 -> V_168 == V_437 ) {
F_3 ( V_2 ) -> V_438 = F_3 ( V_2 ) -> V_58 - 1 ;
F_251 ( V_2 , 0 ) ;
}
}
int F_253 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_168 == V_337 )
return - 1 ;
if ( ( V_4 = F_163 ( V_2 ) ) != NULL &&
F_9 ( F_5 ( V_4 ) -> V_75 , F_10 ( V_8 ) ) ) {
int V_205 ;
unsigned int V_18 = F_56 ( V_2 ) ;
unsigned int V_439 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
if ( F_9 ( V_8 -> V_425 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_425 = F_5 ( V_4 ) -> V_12 ;
if ( V_439 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_75 ||
V_4 -> V_74 > V_18 ) {
V_439 = F_18 ( V_439 , V_18 ) ;
F_5 ( V_4 ) -> V_60 |= V_256 ;
if ( F_122 ( V_2 , V_4 , V_439 , V_18 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_113 ( V_2 , V_4 , V_18 ) ;
F_5 ( V_4 ) -> V_60 |= V_256 ;
F_5 ( V_4 ) -> V_147 = V_22 ;
V_205 = F_89 ( V_2 , V_4 , 1 , V_174 ) ;
if ( ! V_205 )
F_1 ( V_2 , V_4 ) ;
return V_205 ;
} else {
if ( F_254 ( V_8 -> V_91 , V_8 -> V_90 + 1 , V_8 -> V_90 + 0xFFFF ) )
F_251 ( V_2 , 1 ) ;
return F_251 ( V_2 , 0 ) ;
}
}
void F_255 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_205 ;
V_205 = F_253 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_163 ( V_2 ) ) {
V_6 -> V_440 = 0 ;
V_6 -> V_441 = 0 ;
return;
}
if ( V_205 <= 0 ) {
if ( V_6 -> V_441 < V_442 )
V_6 -> V_441 ++ ;
V_6 -> V_440 ++ ;
F_184 ( V_2 , V_443 ,
F_18 ( V_6 -> V_29 << V_6 -> V_441 , V_331 ) ,
V_331 ) ;
} else {
if ( ! V_6 -> V_440 )
V_6 -> V_440 = 1 ;
F_184 ( V_2 , V_443 ,
F_18 ( V_6 -> V_29 << V_6 -> V_441 ,
V_444 ) ,
V_331 ) ;
}
}
