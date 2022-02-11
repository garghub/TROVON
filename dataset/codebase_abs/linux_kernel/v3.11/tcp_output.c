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
if ( V_6 -> V_206 -> V_81 & V_207 )
F_91 ( V_4 ) ;
if ( F_48 ( V_199 ) ) {
const struct V_3 * V_208 = V_4 + 1 ;
if ( F_46 ( V_4 -> V_208 == V_209 &&
V_208 -> V_208 == V_210 ) )
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
V_4 -> V_215 = ( V_216 > 0 ) ?
F_81 : F_88 ;
F_102 ( V_4 -> V_197 , & V_2 -> V_198 ) ;
V_70 = F_40 ( V_4 ) ;
V_70 -> V_217 = V_202 -> V_218 ;
V_70 -> V_219 = V_202 -> V_220 ;
V_70 -> V_75 = F_47 ( V_163 -> V_75 ) ;
V_70 -> V_221 = F_47 ( V_8 -> V_58 ) ;
* ( ( ( V_222 * ) V_70 ) + 6 ) = F_103 ( ( ( V_204 >> 2 ) << 12 ) |
V_163 -> V_60 ) ;
if ( F_46 ( V_163 -> V_60 & V_88 ) ) {
V_70 -> V_223 = F_103 ( F_18 ( V_8 -> V_44 , 65535U ) ) ;
} else {
V_70 -> V_223 = F_103 ( F_29 ( V_2 ) ) ;
}
V_70 -> V_224 = 0 ;
V_70 -> V_225 = 0 ;
if ( F_46 ( F_44 ( V_8 ) && F_9 ( V_163 -> V_75 , V_8 -> V_91 ) ) ) {
if ( F_9 ( V_8 -> V_91 , V_163 -> V_75 + 0x10000 ) ) {
V_70 -> V_225 = F_103 ( V_8 -> V_91 - V_163 -> V_75 ) ;
V_70 -> V_226 = 1 ;
} else if ( F_104 ( V_163 -> V_75 + 0xFFFF , V_8 -> V_11 ) ) {
V_70 -> V_225 = F_103 ( 0xFFFF ) ;
V_70 -> V_226 = 1 ;
}
}
F_45 ( ( T_9 * ) ( V_70 + 1 ) , V_8 , & V_94 ) ;
if ( F_48 ( ( V_163 -> V_60 & V_88 ) == 0 ) )
F_38 ( V_2 , V_4 , V_204 ) ;
#ifdef F_50
if ( V_136 ) {
F_105 ( V_2 , V_227 ) ;
V_8 -> V_142 -> V_228 ( V_94 . V_100 ,
V_136 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_229 -> V_230 ( V_2 , V_4 ) ;
if ( F_48 ( V_163 -> V_60 & V_231 ) )
F_22 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_74 != V_204 )
F_20 ( V_8 , V_2 ) ;
if ( F_104 ( V_163 -> V_12 , V_8 -> V_11 ) || V_163 -> V_75 == V_163 -> V_12 )
F_106 ( F_35 ( V_2 ) , V_232 ,
F_6 ( V_4 ) ) ;
V_205 = V_6 -> V_229 -> V_233 ( V_4 , & V_202 -> V_234 . V_235 ) ;
if ( F_48 ( V_205 <= 0 ) )
return V_205 ;
F_107 ( V_2 , 1 ) ;
return F_108 ( V_205 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_236 = F_5 ( V_4 ) -> V_12 ;
F_110 ( V_4 ) ;
F_111 ( V_2 , V_4 ) ;
V_2 -> V_237 += V_4 -> V_197 ;
F_112 ( V_2 , V_4 -> V_197 ) ;
}
static void F_113 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_238 )
{
if ( V_4 -> V_74 <= V_238 || ! F_114 ( V_2 ) ||
V_4 -> V_82 == V_239 ) {
F_41 ( V_4 ) -> V_86 = 1 ;
F_41 ( V_4 ) -> V_87 = 0 ;
F_41 ( V_4 ) -> V_78 = 0 ;
} else {
F_41 ( V_4 ) -> V_86 = F_115 ( V_4 -> V_74 , V_238 ) ;
F_41 ( V_4 ) -> V_87 = V_238 ;
F_41 ( V_4 ) -> V_78 = V_2 -> V_240 ;
}
}
static void F_116 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_241 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_242 || F_117 ( V_8 ) )
return;
if ( F_104 ( F_118 ( V_8 ) , F_5 ( V_4 ) -> V_75 ) )
V_8 -> V_243 -= V_241 ;
}
static void F_119 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_241 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_241 ;
if ( F_5 ( V_4 ) -> V_85 & V_244 )
V_8 -> V_242 -= V_241 ;
if ( F_5 ( V_4 ) -> V_85 & V_245 )
V_8 -> V_246 -= V_241 ;
if ( F_5 ( V_4 ) -> V_85 & V_247 )
V_8 -> V_248 -= V_241 ;
if ( F_117 ( V_8 ) && V_241 > 0 )
V_8 -> V_242 -= F_28 ( T_4 , V_8 -> V_242 , V_241 ) ;
F_116 ( V_2 , V_4 , V_241 ) ;
if ( V_8 -> V_249 &&
F_9 ( F_5 ( V_4 ) -> V_75 , F_5 ( V_8 -> V_249 ) -> V_75 ) &&
( F_120 ( V_8 ) || ( F_5 ( V_4 ) -> V_85 & V_244 ) ) )
V_8 -> V_250 -= V_241 ;
F_121 ( V_8 ) ;
}
int F_122 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_74 ,
unsigned int V_238 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_251 ;
int V_252 , V_253 ;
int V_254 ;
T_8 V_81 ;
if ( F_123 ( V_74 > V_4 -> V_74 ) )
return - V_255 ;
V_252 = F_124 ( V_4 ) - V_74 ;
if ( V_252 < 0 )
V_252 = 0 ;
if ( F_93 ( V_4 ) &&
F_125 ( V_4 ) &&
F_126 ( V_4 , 0 , 0 , V_174 ) )
return - V_256 ;
V_251 = F_127 ( V_2 , V_252 , V_174 ) ;
if ( V_251 == NULL )
return - V_256 ;
V_2 -> V_237 += V_251 -> V_197 ;
F_112 ( V_2 , V_251 -> V_197 ) ;
V_254 = V_4 -> V_74 - V_74 - V_252 ;
V_251 -> V_197 += V_254 ;
V_4 -> V_197 -= V_254 ;
F_5 ( V_251 ) -> V_75 = F_5 ( V_4 ) -> V_75 + V_74 ;
F_5 ( V_251 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_251 ) -> V_75 ;
V_81 = F_5 ( V_4 ) -> V_60 ;
F_5 ( V_4 ) -> V_60 = V_81 & ~ ( V_89 | V_257 ) ;
F_5 ( V_251 ) -> V_60 = V_81 ;
F_5 ( V_251 ) -> V_85 = F_5 ( V_4 ) -> V_85 ;
if ( ! F_41 ( V_4 ) -> V_258 && V_4 -> V_82 != V_83 ) {
V_251 -> V_84 = F_128 ( V_4 -> V_175 + V_74 ,
F_129 ( V_251 , V_252 ) ,
V_252 , 0 ) ;
F_130 ( V_4 , V_74 ) ;
V_4 -> V_84 = F_131 ( V_4 -> V_84 , V_251 -> V_84 , V_74 ) ;
} else {
V_4 -> V_82 = V_83 ;
F_132 ( V_4 , V_251 , V_74 ) ;
}
V_251 -> V_82 = V_4 -> V_82 ;
F_5 ( V_251 ) -> V_147 = F_5 ( V_4 ) -> V_147 ;
V_251 -> V_259 = V_4 -> V_259 ;
V_253 = F_6 ( V_4 ) ;
F_113 ( V_2 , V_4 , V_238 ) ;
F_113 ( V_2 , V_251 , V_238 ) ;
if ( ! F_9 ( V_8 -> V_11 , F_5 ( V_251 ) -> V_12 ) ) {
int V_260 = V_253 - F_6 ( V_4 ) -
F_6 ( V_251 ) ;
if ( V_260 )
F_119 ( V_2 , V_4 , V_260 ) ;
}
F_110 ( V_251 ) ;
F_133 ( V_4 , V_251 , V_2 ) ;
return 0 ;
}
static void F_134 ( struct V_3 * V_4 , int V_74 )
{
int V_194 , V_261 , V_262 ;
V_262 = F_28 ( int , V_74 , F_124 ( V_4 ) ) ;
if ( V_262 ) {
F_135 ( V_4 , V_262 ) ;
V_74 -= V_262 ;
if ( ! V_74 )
return;
}
V_262 = V_74 ;
V_261 = 0 ;
for ( V_194 = 0 ; V_194 < F_41 ( V_4 ) -> V_258 ; V_194 ++ ) {
int V_164 = F_136 ( & F_41 ( V_4 ) -> V_263 [ V_194 ] ) ;
if ( V_164 <= V_262 ) {
F_137 ( V_4 , V_194 ) ;
V_262 -= V_164 ;
} else {
F_41 ( V_4 ) -> V_263 [ V_261 ] = F_41 ( V_4 ) -> V_263 [ V_194 ] ;
if ( V_262 ) {
F_41 ( V_4 ) -> V_263 [ V_261 ] . V_264 += V_262 ;
F_138 ( & F_41 ( V_4 ) -> V_263 [ V_261 ] , V_262 ) ;
V_262 = 0 ;
}
V_261 ++ ;
}
}
F_41 ( V_4 ) -> V_258 = V_261 ;
F_139 ( V_4 ) ;
V_4 -> V_265 -= V_74 ;
V_4 -> V_74 = V_4 -> V_265 ;
}
int F_140 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_74 )
{
if ( F_141 ( V_4 , V_174 ) )
return - V_256 ;
F_134 ( V_4 , V_74 ) ;
F_5 ( V_4 ) -> V_75 += V_74 ;
V_4 -> V_82 = V_83 ;
V_4 -> V_197 -= V_74 ;
V_2 -> V_237 -= V_74 ;
F_142 ( V_2 , V_74 ) ;
F_143 ( V_2 , V_266 ) ;
if ( F_6 ( V_4 ) > 1 )
F_113 ( V_2 , V_4 , F_144 ( V_4 ) ) ;
return 0 ;
}
static inline int F_145 ( struct V_1 * V_2 , int V_267 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_238 ;
V_238 = V_267 - V_6 -> V_229 -> V_268 - sizeof( struct V_69 ) ;
if ( V_6 -> V_229 -> V_269 ) {
const struct V_16 * V_17 = F_12 ( V_2 ) ;
if ( V_17 && F_146 ( V_17 ) )
V_238 -= V_6 -> V_229 -> V_269 ;
}
if ( V_238 > V_8 -> V_56 . V_270 )
V_238 = V_8 -> V_56 . V_270 ;
V_238 -= V_6 -> V_271 ;
if ( V_238 < 48 )
V_238 = 48 ;
return V_238 ;
}
int F_147 ( struct V_1 * V_2 , int V_267 )
{
return F_145 ( V_2 , V_267 ) -
( F_3 ( V_2 ) -> V_73 - sizeof( struct V_69 ) ) ;
}
int F_148 ( struct V_1 * V_2 , int V_18 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_272 ;
V_272 = V_18 +
V_8 -> V_73 +
V_6 -> V_271 +
V_6 -> V_229 -> V_268 ;
if ( V_6 -> V_229 -> V_269 ) {
const struct V_16 * V_17 = F_12 ( V_2 ) ;
if ( V_17 && F_146 ( V_17 ) )
V_272 += V_6 -> V_229 -> V_269 ;
}
return V_272 ;
}
void F_149 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_273 . V_274 = V_275 > 1 ;
V_6 -> V_273 . V_276 = V_8 -> V_56 . V_270 + sizeof( struct V_69 ) +
V_6 -> V_229 -> V_268 ;
V_6 -> V_273 . V_277 = F_148 ( V_2 , V_278 ) ;
V_6 -> V_273 . V_279 = 0 ;
}
unsigned int F_150 ( struct V_1 * V_2 , T_4 V_267 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_238 ;
if ( V_6 -> V_273 . V_276 > V_267 )
V_6 -> V_273 . V_276 = V_267 ;
V_238 = F_147 ( V_2 , V_267 ) ;
V_238 = F_151 ( V_8 , V_238 ) ;
V_6 -> V_280 = V_267 ;
if ( V_6 -> V_273 . V_274 )
V_238 = F_18 ( V_238 , F_147 ( V_2 , V_6 -> V_273 . V_277 ) ) ;
V_8 -> V_281 = V_238 ;
return V_238 ;
}
unsigned int F_56 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_16 * V_17 = F_12 ( V_2 ) ;
T_4 V_238 ;
unsigned int V_282 ;
struct V_93 V_94 ;
struct V_135 * V_136 ;
V_238 = V_8 -> V_281 ;
if ( V_17 ) {
T_4 V_272 = F_152 ( V_17 ) ;
if ( V_272 != F_2 ( V_2 ) -> V_280 )
V_238 = F_150 ( V_2 , V_272 ) ;
}
V_282 = F_53 ( V_2 , NULL , & V_94 , & V_136 ) +
sizeof( struct V_69 ) ;
if ( V_282 != V_8 -> V_73 ) {
int V_21 = ( int ) V_282 - V_8 -> V_73 ;
V_238 -= V_21 ;
}
return V_238 ;
}
static void F_153 ( struct V_1 * V_2 )
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
F_154 ( V_2 ) ;
}
}
static unsigned int F_155 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_238 , unsigned int V_283 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_284 , V_223 , V_285 ;
V_223 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
V_285 = V_238 * V_283 ;
if ( F_48 ( V_285 <= V_223 && V_4 != F_156 ( V_2 ) ) )
return V_285 ;
V_284 = F_18 ( V_4 -> V_74 , V_223 ) ;
if ( V_285 <= V_284 )
return V_285 ;
return V_284 - V_284 % V_238 ;
}
static inline unsigned int F_157 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_286 , V_25 ;
if ( ( F_5 ( V_4 ) -> V_60 & V_89 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_286 = F_97 ( V_8 ) ;
V_25 = V_8 -> V_26 ;
if ( V_286 < V_25 )
return ( V_25 - V_286 ) ;
return 0 ;
}
static int F_158 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_238 )
{
int V_287 = F_6 ( V_4 ) ;
if ( ! V_287 || ( V_287 > 1 && F_144 ( V_4 ) != V_238 ) ) {
F_113 ( V_2 , V_4 , V_238 ) ;
V_287 = F_6 ( V_4 ) ;
}
return V_287 ;
}
static inline bool F_159 ( const struct V_7 * V_8 )
{
return F_104 ( V_8 -> V_288 , V_8 -> V_90 ) &&
! F_104 ( V_8 -> V_288 , V_8 -> V_11 ) ;
}
static inline bool F_160 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_238 , int V_289 )
{
return V_4 -> V_74 < V_238 &&
( ( V_289 & V_290 ) ||
( ! V_289 && V_8 -> V_10 && F_159 ( V_8 ) ) ) ;
}
static inline bool F_161 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_291 , int V_289 )
{
if ( V_289 & V_292 )
return true ;
if ( F_44 ( V_8 ) || ( F_5 ( V_4 ) -> V_60 & V_89 ) )
return true ;
if ( ! F_160 ( V_8 , V_4 , V_291 , V_289 ) )
return true ;
return false ;
}
static bool F_162 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_291 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_74 > V_291 )
V_12 = F_5 ( V_4 ) -> V_75 + V_291 ;
return ! F_104 ( V_12 , F_10 ( V_8 ) ) ;
}
static unsigned int F_163 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_291 , int V_289 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_293 ;
F_158 ( V_2 , V_4 , V_291 ) ;
if ( ! F_161 ( V_8 , V_4 , V_291 , V_289 ) )
return 0 ;
V_293 = F_157 ( V_8 , V_4 ) ;
if ( V_293 && ! F_162 ( V_8 , V_4 , V_291 ) )
V_293 = 0 ;
return V_293 ;
}
bool F_164 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_165 ( V_2 ) ;
return V_4 &&
F_163 ( V_2 , V_4 , F_56 ( V_2 ) ,
( F_166 ( V_2 , V_4 ) ?
V_8 -> V_289 : V_292 ) ) ;
}
static int F_167 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_74 ,
unsigned int V_238 , T_11 V_294 )
{
struct V_3 * V_251 ;
int V_254 = V_4 -> V_74 - V_74 ;
T_8 V_81 ;
if ( V_4 -> V_74 != V_4 -> V_265 )
return F_122 ( V_2 , V_4 , V_74 , V_238 ) ;
V_251 = F_127 ( V_2 , 0 , V_294 ) ;
if ( F_46 ( V_251 == NULL ) )
return - V_256 ;
V_2 -> V_237 += V_251 -> V_197 ;
F_112 ( V_2 , V_251 -> V_197 ) ;
V_251 -> V_197 += V_254 ;
V_4 -> V_197 -= V_254 ;
F_5 ( V_251 ) -> V_75 = F_5 ( V_4 ) -> V_75 + V_74 ;
F_5 ( V_251 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_251 ) -> V_75 ;
V_81 = F_5 ( V_4 ) -> V_60 ;
F_5 ( V_4 ) -> V_60 = V_81 & ~ ( V_89 | V_257 ) ;
F_5 ( V_251 ) -> V_60 = V_81 ;
F_5 ( V_251 ) -> V_85 = 0 ;
V_251 -> V_82 = V_4 -> V_82 = V_83 ;
F_132 ( V_4 , V_251 , V_74 ) ;
F_113 ( V_2 , V_4 , V_238 ) ;
F_113 ( V_2 , V_251 , V_238 ) ;
F_110 ( V_251 ) ;
F_133 ( V_4 , V_251 , V_2 ) ;
return 0 ;
}
static bool F_168 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_295 , V_296 , V_297 , V_286 ;
int V_298 ;
if ( F_5 ( V_4 ) -> V_60 & V_89 )
goto V_299;
if ( V_6 -> V_300 != V_301 )
goto V_299;
if ( V_8 -> V_302 &&
( ( ( T_4 ) V_303 << 1 ) >> 1 ) - ( V_8 -> V_302 >> 1 ) > 1 )
goto V_299;
V_286 = F_97 ( V_8 ) ;
F_90 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_26 <= V_286 ) ) ;
V_295 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
V_296 = ( V_8 -> V_26 - V_286 ) * V_8 -> V_281 ;
V_297 = F_18 ( V_295 , V_296 ) ;
if ( V_297 >= F_28 (unsigned int, sk->sk_gso_max_size,
sk->sk_gso_max_segs * tp->mss_cache) )
goto V_299;
if ( ( V_4 != F_156 ( V_2 ) ) && ( V_297 >= V_4 -> V_74 ) )
goto V_299;
V_298 = F_169 ( V_304 ) ;
if ( V_298 ) {
T_4 V_305 = F_18 ( V_8 -> V_306 , V_8 -> V_26 * V_8 -> V_281 ) ;
V_305 /= V_298 ;
if ( V_297 >= V_305 )
goto V_299;
} else {
if ( V_297 > F_170 ( V_8 ) * V_8 -> V_281 )
goto V_299;
}
if ( ! V_8 -> V_302 )
V_8 -> V_302 = 1 | ( V_303 << 1 ) ;
return true ;
V_299:
V_8 -> V_302 = 0 ;
return false ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_307 , * V_308 ;
int V_74 ;
int V_279 ;
int V_309 ;
int V_310 ;
int V_238 ;
if ( ! V_6 -> V_273 . V_274 ||
V_6 -> V_273 . V_279 ||
F_2 ( V_2 ) -> V_300 != V_301 ||
V_8 -> V_26 < 11 ||
V_8 -> V_56 . V_166 || V_8 -> V_56 . V_118 )
return - 1 ;
V_238 = F_56 ( V_2 ) ;
V_279 = 2 * V_8 -> V_281 ;
V_309 = V_279 + ( V_8 -> V_311 + 1 ) * V_8 -> V_281 ;
if ( V_279 > F_147 ( V_2 , V_6 -> V_273 . V_276 ) ) {
return - 1 ;
}
if ( V_8 -> V_236 - V_8 -> V_11 < V_309 )
return - 1 ;
if ( V_8 -> V_306 < V_309 )
return - 1 ;
if ( F_104 ( V_8 -> V_11 + V_309 , F_10 ( V_8 ) ) )
return 0 ;
if ( F_97 ( V_8 ) + 2 > V_8 -> V_26 ) {
if ( ! F_97 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_307 = F_127 ( V_2 , V_279 , V_174 ) ) == NULL )
return - 1 ;
V_2 -> V_237 += V_307 -> V_197 ;
F_112 ( V_2 , V_307 -> V_197 ) ;
V_4 = F_165 ( V_2 ) ;
F_5 ( V_307 ) -> V_75 = F_5 ( V_4 ) -> V_75 ;
F_5 ( V_307 ) -> V_12 = F_5 ( V_4 ) -> V_75 + V_279 ;
F_5 ( V_307 ) -> V_60 = V_231 ;
F_5 ( V_307 ) -> V_85 = 0 ;
V_307 -> V_84 = 0 ;
V_307 -> V_82 = V_4 -> V_82 ;
F_172 ( V_307 , V_4 , V_2 ) ;
V_74 = 0 ;
F_173 (skb, next, sk) {
V_310 = F_28 ( int , V_4 -> V_74 , V_279 - V_74 ) ;
if ( V_307 -> V_82 )
F_174 ( V_4 , 0 , F_129 ( V_307 , V_310 ) , V_310 ) ;
else
V_307 -> V_84 = F_175 ( V_4 , 0 ,
F_129 ( V_307 , V_310 ) ,
V_310 , V_307 -> V_84 ) ;
if ( V_4 -> V_74 <= V_310 ) {
F_5 ( V_307 ) -> V_60 |= F_5 ( V_4 ) -> V_60 ;
F_176 ( V_4 , V_2 ) ;
F_177 ( V_2 , V_4 ) ;
} else {
F_5 ( V_307 ) -> V_60 |= F_5 ( V_4 ) -> V_60 &
~ ( V_89 | V_257 ) ;
if ( ! F_41 ( V_4 ) -> V_258 ) {
F_178 ( V_4 , V_310 ) ;
if ( V_4 -> V_82 != V_83 )
V_4 -> V_84 = F_179 ( V_4 -> V_175 ,
V_4 -> V_74 , 0 ) ;
} else {
F_134 ( V_4 , V_310 ) ;
F_113 ( V_2 , V_4 , V_238 ) ;
}
F_5 ( V_4 ) -> V_75 += V_310 ;
}
V_74 += V_310 ;
if ( V_74 >= V_279 )
break;
}
F_158 ( V_2 , V_307 , V_307 -> V_74 ) ;
F_5 ( V_307 ) -> V_147 = V_22 ;
if ( ! F_89 ( V_2 , V_307 , 1 , V_174 ) ) {
V_8 -> V_26 -- ;
F_1 ( V_2 , V_307 ) ;
V_6 -> V_273 . V_279 = F_148 ( V_2 , V_307 -> V_74 ) ;
V_8 -> V_312 . V_313 = F_5 ( V_307 ) -> V_75 ;
V_8 -> V_312 . V_314 = F_5 ( V_307 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_55 ( struct V_1 * V_2 , unsigned int V_238 , int V_289 ,
int V_315 , T_11 V_294 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_287 , V_316 ;
int V_293 ;
int V_317 ;
V_316 = 0 ;
if ( ! V_315 ) {
V_317 = F_171 ( V_2 ) ;
if ( ! V_317 ) {
return false ;
} else if ( V_317 > 0 ) {
V_316 = 1 ;
}
}
while ( ( V_4 = F_165 ( V_2 ) ) ) {
unsigned int V_297 ;
V_287 = F_158 ( V_2 , V_4 , V_238 ) ;
F_90 ( ! V_287 ) ;
if ( F_46 ( V_8 -> V_318 ) && V_8 -> V_319 == V_320 )
goto V_318;
V_293 = F_157 ( V_8 , V_4 ) ;
if ( ! V_293 ) {
if ( V_315 == 2 )
V_293 = 1 ;
else
break;
}
if ( F_46 ( ! F_162 ( V_8 , V_4 , V_238 ) ) )
break;
if ( V_287 == 1 ) {
if ( F_46 ( ! F_161 ( V_8 , V_4 , V_238 ,
( F_166 ( V_2 , V_4 ) ?
V_289 : V_292 ) ) ) )
break;
} else {
if ( ! V_315 && F_168 ( V_2 , V_4 ) )
break;
}
if ( F_180 ( & V_2 -> V_198 ) >= V_216 ) {
F_67 ( V_196 , & V_8 -> V_185 ) ;
break;
}
V_297 = V_238 ;
if ( V_287 > 1 && ! F_44 ( V_8 ) )
V_297 = F_155 ( V_2 , V_4 , V_238 ,
F_28 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ) ;
if ( V_4 -> V_74 > V_297 &&
F_46 ( F_167 ( V_2 , V_4 , V_297 , V_238 , V_294 ) ) )
break;
F_5 ( V_4 ) -> V_147 = V_22 ;
if ( F_46 ( F_89 ( V_2 , V_4 , 1 , V_294 ) ) )
break;
V_318:
F_1 ( V_2 , V_4 ) ;
F_181 ( V_8 , V_238 , V_4 ) ;
V_316 += F_6 ( V_4 ) ;
if ( V_315 )
break;
}
if ( F_48 ( V_316 ) ) {
if ( F_182 ( V_2 ) )
V_8 -> V_321 += V_316 ;
if ( V_315 != 2 )
F_183 ( V_2 ) ;
F_153 ( V_2 ) ;
return false ;
}
return ( V_315 == 2 ) || ( ! V_8 -> V_10 && F_165 ( V_2 ) ) ;
}
bool F_183 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_322 , V_323 , V_324 ;
T_4 V_325 = V_8 -> V_326 >> 3 ;
if ( F_123 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_123 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_168 == V_327 )
return false ;
if ( V_6 -> V_13 != V_328 )
return false ;
if ( V_329 < 3 || ! V_325 || ! V_8 -> V_10 ||
! F_184 ( V_8 ) || F_2 ( V_2 ) -> V_300 != V_301 )
return false ;
if ( ( V_8 -> V_26 > F_97 ( V_8 ) ) &&
F_165 ( V_2 ) )
return false ;
V_322 = V_325 << 1 ;
if ( V_8 -> V_10 == 1 )
V_322 = F_27 ( T_4 , V_322 ,
( V_325 + ( V_325 >> 1 ) + V_330 ) ) ;
V_322 = F_27 ( T_4 , V_322 , F_185 ( 10 ) ) ;
V_323 = V_22 + V_322 ;
V_324 = ( T_4 ) F_2 ( V_2 ) -> V_331 ;
if ( ( T_3 ) ( V_323 - V_324 ) > 0 ) {
T_3 V_21 = V_324 - V_22 ;
if ( V_21 > 0 )
V_322 = V_21 ;
}
F_186 ( V_2 , V_15 , V_322 ,
V_332 ) ;
return true ;
}
void F_187 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_333 ;
int V_18 = F_56 ( V_2 ) ;
int V_205 = - 1 ;
if ( F_165 ( V_2 ) != NULL ) {
V_205 = F_55 ( V_2 , V_18 , V_334 , 2 , V_174 ) ;
goto V_335;
}
if ( V_8 -> V_336 )
goto V_335;
V_4 = F_156 ( V_2 ) ;
if ( F_123 ( ! V_4 ) )
goto V_335;
V_333 = F_6 ( V_4 ) ;
if ( F_123 ( ! V_333 ) )
goto V_335;
if ( ( V_333 > 1 ) && ( V_4 -> V_74 > ( V_333 - 1 ) * V_18 ) ) {
if ( F_46 ( F_122 ( V_2 , V_4 , ( V_333 - 1 ) * V_18 , V_18 ) ) )
goto V_335;
V_4 = F_156 ( V_2 ) ;
}
if ( F_123 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_335;
if ( V_4 -> V_74 > 0 )
V_205 = F_188 ( V_2 , V_4 ) ;
if ( F_48 ( ! V_205 ) )
V_8 -> V_336 = V_8 -> V_11 ;
V_335:
F_186 ( V_2 , V_328 ,
F_2 ( V_2 ) -> V_29 ,
V_332 ) ;
if ( F_48 ( ! V_205 ) )
F_92 ( F_35 ( V_2 ) ,
V_337 ) ;
return;
}
void F_189 ( struct V_1 * V_2 , unsigned int V_291 ,
int V_289 )
{
if ( F_46 ( V_2 -> V_168 == V_338 ) )
return;
if ( F_55 ( V_2 , V_291 , V_289 , 0 ,
F_190 ( V_2 , V_174 ) ) )
F_191 ( V_2 ) ;
}
void F_192 ( struct V_1 * V_2 , unsigned int V_238 )
{
struct V_3 * V_4 = F_165 ( V_2 ) ;
F_90 ( ! V_4 || V_4 -> V_74 < V_238 ) ;
F_55 ( V_2 , V_238 , V_292 , 1 , V_2 -> V_339 ) ;
}
T_4 F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_18 = V_6 -> V_34 . V_340 ;
int V_341 = F_193 ( V_2 ) ;
int V_342 = F_28 ( int , V_8 -> V_45 , F_194 ( V_2 ) ) ;
int V_223 ;
if ( V_18 > V_342 )
V_18 = V_342 ;
if ( V_341 < ( V_342 >> 1 ) ) {
V_6 -> V_34 . V_343 = 0 ;
if ( F_195 ( V_2 ) )
V_8 -> V_344 = F_18 ( V_8 -> V_344 ,
4U * V_8 -> V_19 ) ;
if ( V_341 < V_18 )
return 0 ;
}
if ( V_341 > V_8 -> V_344 )
V_341 = V_8 -> V_344 ;
V_223 = V_8 -> V_44 ;
if ( V_8 -> V_56 . V_47 ) {
V_223 = V_341 ;
if ( ( ( V_223 >> V_8 -> V_56 . V_47 ) << V_8 -> V_56 . V_47 ) != V_223 )
V_223 = ( ( ( V_223 >> V_8 -> V_56 . V_47 ) + 1 )
<< V_8 -> V_56 . V_47 ) ;
} else {
if ( V_223 <= V_341 - V_18 || V_223 > V_341 )
V_223 = ( V_341 / V_18 ) * V_18 ;
else if ( V_18 == V_342 &&
V_341 > V_223 + ( V_342 >> 1 ) )
V_223 = V_341 ;
}
return V_223 ;
}
static void F_196 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_345 = F_197 ( V_2 , V_4 ) ;
int V_346 , V_347 ;
V_346 = V_4 -> V_74 ;
V_347 = V_345 -> V_74 ;
F_90 ( F_6 ( V_4 ) != 1 || F_6 ( V_345 ) != 1 ) ;
F_198 ( V_2 , V_345 , V_4 ) ;
F_176 ( V_345 , V_2 ) ;
F_199 ( V_345 , F_129 ( V_4 , V_347 ) ,
V_347 ) ;
if ( V_345 -> V_82 == V_83 )
V_4 -> V_82 = V_83 ;
if ( V_4 -> V_82 != V_83 )
V_4 -> V_84 = F_200 ( V_4 -> V_84 , V_345 -> V_84 , V_346 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_345 ) -> V_12 ;
F_5 ( V_4 ) -> V_60 |= F_5 ( V_345 ) -> V_60 ;
F_5 ( V_4 ) -> V_85 |= F_5 ( V_345 ) -> V_85 & V_348 ;
F_201 ( V_8 ) ;
if ( V_345 == V_8 -> V_349 )
V_8 -> V_349 = V_4 ;
F_119 ( V_2 , V_345 , F_6 ( V_345 ) ) ;
F_177 ( V_2 , V_345 ) ;
}
static bool F_202 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_41 ( V_4 ) -> V_258 != 0 )
return false ;
if ( F_93 ( V_4 ) )
return false ;
if ( V_4 == F_165 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_85 & V_244 )
return false ;
return true ;
}
static void F_203 ( struct V_1 * V_2 , struct V_3 * V_350 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_350 , * V_351 ;
bool V_352 = true ;
if ( ! V_353 )
return;
if ( F_5 ( V_4 ) -> V_60 & V_88 )
return;
F_173 (skb, tmp, sk) {
if ( ! F_202 ( V_2 , V_4 ) )
break;
V_49 -= V_4 -> V_74 ;
if ( V_352 ) {
V_352 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_74 > F_204 ( V_350 ) )
break;
if ( F_104 ( F_5 ( V_4 ) -> V_12 , F_10 ( V_8 ) ) )
break;
F_196 ( V_2 , V_350 ) ;
}
}
int F_188 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_291 ;
if ( V_6 -> V_273 . V_279 ) {
V_6 -> V_273 . V_279 = 0 ;
}
if ( F_180 ( & V_2 -> V_198 ) >
F_18 ( V_2 -> V_237 + ( V_2 -> V_237 >> 2 ) , V_2 -> V_354 ) )
return - V_355 ;
if ( F_9 ( F_5 ( V_4 ) -> V_75 , V_8 -> V_90 ) ) {
if ( F_9 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_90 ) )
F_205 () ;
if ( F_140 ( V_2 , V_4 , V_8 -> V_90 - F_5 ( V_4 ) -> V_75 ) )
return - V_256 ;
}
if ( F_2 ( V_2 ) -> V_229 -> V_356 ( V_2 ) )
return - V_357 ;
V_291 = F_56 ( V_2 ) ;
if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , F_10 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_75 != V_8 -> V_90 )
return - V_355 ;
if ( V_4 -> V_74 > V_291 ) {
if ( F_122 ( V_2 , V_4 , V_291 , V_291 ) )
return - V_256 ;
} else {
int V_358 = F_6 ( V_4 ) ;
if ( F_46 ( V_358 > 1 ) ) {
F_158 ( V_2 , V_4 , V_291 ) ;
F_119 ( V_2 , V_4 , V_358 - F_6 ( V_4 ) ) ;
}
}
F_203 ( V_2 , V_4 , V_291 ) ;
if ( V_4 -> V_74 > 0 &&
( F_5 ( V_4 ) -> V_60 & V_89 ) &&
V_8 -> V_90 == ( F_5 ( V_4 ) -> V_12 - 1 ) ) {
if ( ! F_206 ( V_4 , 0 ) ) {
F_43 ( V_4 , F_5 ( V_4 ) -> V_12 - 1 ,
F_5 ( V_4 ) -> V_60 ) ;
V_4 -> V_82 = V_239 ;
}
}
F_5 ( V_4 ) -> V_147 = V_22 ;
if ( F_46 ( ( V_359 && ( ( unsigned long ) V_4 -> V_175 & 3 ) ) ||
F_207 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_307 = F_208 ( V_4 , V_360 ,
V_174 ) ;
return V_307 ? F_89 ( V_2 , V_307 , 0 , V_174 ) :
- V_212 ;
} else {
return F_89 ( V_2 , V_4 , 1 , V_174 ) ;
}
}
int F_209 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_205 = F_188 ( V_2 , V_4 ) ;
if ( V_205 == 0 ) {
F_210 ( F_35 ( V_2 ) , V_361 ) ;
V_8 -> V_362 ++ ;
#if V_363 > 0
if ( F_5 ( V_4 ) -> V_85 & V_245 ) {
F_211 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_246 )
V_8 -> V_364 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_85 |= V_365 ;
V_8 -> V_246 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_366 )
V_8 -> V_366 = F_5 ( V_4 ) -> V_147 ;
V_8 -> V_367 += F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_221 = V_8 -> V_11 ;
} else {
F_92 ( F_35 ( V_2 ) , V_368 ) ;
}
return V_205 ;
}
static bool F_212 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_300 != V_369 )
return false ;
if ( F_117 ( V_8 ) )
return false ;
if ( F_164 ( V_2 ) )
return false ;
return true ;
}
void F_213 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_370 = NULL ;
T_4 V_371 ;
int V_372 ;
int V_373 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_248 )
V_8 -> V_374 = V_8 -> V_90 ;
if ( V_8 -> V_349 ) {
V_4 = V_8 -> V_349 ;
V_371 = F_5 ( V_4 ) -> V_12 ;
if ( F_104 ( V_371 , V_8 -> V_374 ) )
V_371 = V_8 -> V_374 ;
} else {
V_4 = F_214 ( V_2 ) ;
V_371 = V_8 -> V_90 ;
}
F_215 (skb, sk) {
T_5 V_85 = F_5 ( V_4 ) -> V_85 ;
if ( V_4 == F_165 ( V_2 ) )
break;
if ( V_370 == NULL )
V_8 -> V_349 = V_4 ;
if ( F_97 ( V_8 ) >= V_8 -> V_26 )
return;
if ( V_373 ) {
V_375:
if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , F_118 ( V_8 ) ) )
break;
V_372 = V_376 ;
} else if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , V_8 -> V_374 ) ) {
V_8 -> V_374 = V_371 ;
if ( ! F_212 ( V_2 ) )
break;
if ( V_370 != NULL ) {
V_4 = V_370 ;
V_370 = NULL ;
}
V_373 = 1 ;
goto V_375;
} else if ( ! ( V_85 & V_247 ) ) {
if ( V_370 == NULL && ! ( V_85 & ( V_245 | V_244 ) ) )
V_370 = V_4 ;
continue;
} else {
V_371 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_300 != V_377 )
V_372 = V_378 ;
else
V_372 = V_379 ;
}
if ( V_85 & ( V_244 | V_245 ) )
continue;
if ( F_209 ( V_2 , V_4 ) )
return;
F_92 ( F_35 ( V_2 ) , V_372 ) ;
if ( F_182 ( V_2 ) )
V_8 -> V_321 += F_6 ( V_4 ) ;
if ( V_4 == F_214 ( V_2 ) )
F_186 ( V_2 , V_328 ,
F_2 ( V_2 ) -> V_29 ,
V_332 ) ;
}
}
void F_216 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_156 ( V_2 ) ;
int V_238 ;
V_238 = F_56 ( V_2 ) ;
if ( F_165 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_60 |= V_89 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_236 ++ ;
} else {
for (; ; ) {
V_4 = F_217 ( V_360 ,
V_2 -> V_339 ) ;
if ( V_4 )
break;
F_218 () ;
}
F_219 ( V_4 , V_360 ) ;
F_43 ( V_4 , V_8 -> V_236 ,
V_231 | V_89 ) ;
F_109 ( V_2 , V_4 ) ;
}
F_189 ( V_2 , V_238 , V_334 ) ;
}
void F_220 ( struct V_1 * V_2 , T_11 V_380 )
{
struct V_3 * V_4 ;
V_4 = F_221 ( V_360 , V_380 ) ;
if ( ! V_4 ) {
F_222 ( F_35 ( V_2 ) , V_381 ) ;
return;
}
F_219 ( V_4 , V_360 ) ;
F_43 ( V_4 , F_8 ( V_2 ) ,
V_231 | V_382 ) ;
F_5 ( V_4 ) -> V_147 = V_22 ;
if ( F_89 ( V_2 , V_4 , 0 , V_380 ) )
F_222 ( F_35 ( V_2 ) , V_381 ) ;
F_210 ( F_35 ( V_2 ) , V_383 ) ;
}
int F_223 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_214 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_60 & V_88 ) ) {
F_224 ( L_2 , V_384 ) ;
return - V_385 ;
}
if ( ! ( F_5 ( V_4 ) -> V_60 & V_231 ) ) {
if ( F_93 ( V_4 ) ) {
struct V_3 * V_307 = F_225 ( V_4 , V_174 ) ;
if ( V_307 == NULL )
return - V_256 ;
F_176 ( V_4 , V_2 ) ;
F_110 ( V_307 ) ;
F_226 ( V_2 , V_307 ) ;
F_177 ( V_2 , V_4 ) ;
V_2 -> V_237 += V_307 -> V_197 ;
F_112 ( V_2 , V_307 -> V_197 ) ;
V_4 = V_307 ;
}
F_5 ( V_4 ) -> V_60 |= V_231 ;
F_33 ( F_3 ( V_2 ) , V_4 ) ;
}
F_5 ( V_4 ) -> V_147 = V_22 ;
return F_89 ( V_2 , V_4 , 1 , V_174 ) ;
}
struct V_3 * F_227 ( struct V_1 * V_2 , struct V_16 * V_17 ,
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
V_4 = F_228 ( V_2 , V_360 + 15 , 1 , V_174 ) ;
if ( F_46 ( ! V_4 ) ) {
F_229 ( V_17 ) ;
return NULL ;
}
F_219 ( V_4 , V_360 ) ;
F_230 ( V_4 , V_17 ) ;
F_231 ( V_4 , V_2 ) ;
V_18 = F_13 ( V_17 ) ;
if ( V_8 -> V_56 . V_386 && V_8 -> V_56 . V_386 < V_18 )
V_18 = V_8 -> V_56 . V_386 ;
if ( V_68 -> V_44 == 0 ) {
T_5 V_47 ;
V_68 -> V_45 = V_8 -> V_45 ? : F_21 ( V_17 , V_387 ) ;
if ( V_2 -> V_388 & V_389 &&
( V_68 -> V_45 > F_194 ( V_2 ) || V_68 -> V_45 == 0 ) )
V_68 -> V_45 = F_194 ( V_2 ) ;
F_26 ( F_194 ( V_2 ) ,
V_18 - ( V_159 -> V_160 ? V_150 : 0 ) ,
& V_68 -> V_44 ,
& V_68 -> V_45 ,
V_159 -> V_46 ,
& V_47 ,
F_21 ( V_17 , V_390 ) ) ;
V_159 -> V_47 = V_47 ;
}
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
#ifdef F_232
if ( F_46 ( V_68 -> V_391 ) )
F_5 ( V_4 ) -> V_147 = F_233 ( V_68 ) ;
else
#endif
F_5 ( V_4 ) -> V_147 = V_22 ;
V_204 = F_51 ( V_2 , V_68 , V_18 , V_4 , & V_94 , & V_136 ,
V_128 ) + sizeof( * V_70 ) ;
F_99 ( V_4 , V_204 ) ;
F_100 ( V_4 ) ;
V_70 = F_40 ( V_4 ) ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_392 = 1 ;
V_70 -> V_393 = 1 ;
F_36 ( V_68 , V_70 ) ;
V_70 -> V_217 = V_159 -> V_394 ;
V_70 -> V_219 = V_159 -> V_395 ;
F_43 ( V_4 , F_52 ( V_68 ) -> V_396 ,
V_88 | V_231 ) ;
V_70 -> V_75 = F_47 ( F_5 ( V_4 ) -> V_75 ) ;
V_70 -> V_221 = F_47 ( F_52 ( V_68 ) -> V_58 ) ;
V_70 -> V_223 = F_103 ( F_18 ( V_68 -> V_44 , 65535U ) ) ;
F_45 ( ( T_9 * ) ( V_70 + 1 ) , V_8 , & V_94 ) ;
V_70 -> V_397 = ( V_204 >> 2 ) ;
F_106 ( F_35 ( V_2 ) , V_232 , F_6 ( V_4 ) ) ;
#ifdef F_50
if ( V_136 ) {
F_52 ( V_68 ) -> V_142 -> V_228 ( V_94 . V_100 ,
V_136 , NULL , V_68 , V_4 ) ;
}
#endif
return V_4 ;
}
void F_234 ( struct V_1 * V_2 )
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
if ( V_8 -> V_56 . V_386 )
V_8 -> V_56 . V_270 = V_8 -> V_56 . V_386 ;
V_8 -> V_398 = 0 ;
F_149 ( V_2 ) ;
F_150 ( V_2 , F_152 ( V_17 ) ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_21 ( V_17 , V_387 ) ;
V_8 -> V_19 = F_13 ( V_17 ) ;
if ( V_8 -> V_56 . V_386 && V_8 -> V_56 . V_386 < V_8 -> V_19 )
V_8 -> V_19 = V_8 -> V_56 . V_386 ;
F_235 ( V_2 ) ;
if ( V_2 -> V_388 & V_389 &&
( V_8 -> V_45 > F_194 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_194 ( V_2 ) ;
F_26 ( F_194 ( V_2 ) ,
V_8 -> V_19 - ( V_8 -> V_56 . V_399 ? V_8 -> V_73 - sizeof( struct V_69 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_151 ,
& V_47 ,
F_21 ( V_17 , V_390 ) ) ;
V_8 -> V_56 . V_47 = V_47 ;
V_8 -> V_344 = V_8 -> V_44 ;
V_2 -> V_400 = 0 ;
F_236 ( V_2 , V_401 ) ;
V_8 -> V_306 = 0 ;
F_237 ( V_8 , 0 ) ;
V_8 -> V_90 = V_8 -> V_236 ;
V_8 -> V_288 = V_8 -> V_236 ;
V_8 -> V_91 = V_8 -> V_236 ;
V_8 -> V_11 = V_8 -> V_236 ;
if ( F_48 ( ! V_8 -> V_318 ) )
V_8 -> V_58 = 0 ;
else
V_8 -> V_402 = V_22 ;
V_8 -> V_57 = V_8 -> V_58 ;
V_8 -> V_403 = V_8 -> V_58 ;
F_2 ( V_2 ) -> V_29 = V_404 ;
F_2 ( V_2 ) -> V_405 = 0 ;
F_238 ( V_8 ) ;
}
static void F_239 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_162 * V_163 = F_5 ( V_4 ) ;
V_163 -> V_12 += V_4 -> V_74 ;
F_110 ( V_4 ) ;
F_240 ( V_2 , V_4 ) ;
V_2 -> V_237 += V_4 -> V_197 ;
F_112 ( V_2 , V_4 -> V_197 ) ;
V_8 -> V_236 = V_163 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_241 ( struct V_1 * V_2 , struct V_3 * V_392 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_139 * V_406 = V_8 -> V_141 ;
int V_407 = 0 , V_49 , V_194 , V_205 = 0 , V_408 = V_406 -> V_175 -> V_409 ;
struct V_3 * V_410 = NULL , * V_175 ;
unsigned long V_411 = 0 ;
V_8 -> V_56 . V_270 = V_8 -> V_19 ;
F_242 ( V_2 , & V_8 -> V_56 . V_270 , & V_406 -> V_155 ,
& V_407 , & V_411 ) ;
if ( V_407 > 1 &&
F_243 ( V_303 , V_411 + ( 60 * V_412 << V_407 ) ) ) {
V_406 -> V_155 . V_74 = - 1 ;
goto V_413;
}
if ( V_414 & V_415 )
V_406 -> V_155 . V_74 = - 1 ;
else if ( V_406 -> V_155 . V_74 <= 0 )
goto V_413;
if ( V_8 -> V_56 . V_386 && V_8 -> V_56 . V_386 < V_8 -> V_56 . V_270 )
V_8 -> V_56 . V_270 = V_8 -> V_56 . V_386 ;
V_49 = F_145 ( V_2 , F_2 ( V_2 ) -> V_280 ) -
V_138 ;
V_410 = F_244 ( V_392 , F_207 ( V_392 ) , V_49 ,
V_2 -> V_339 ) ;
if ( V_410 == NULL )
goto V_413;
for ( V_194 = 0 ; V_194 < V_408 && V_410 -> V_74 < V_49 ; ++ V_194 ) {
struct V_416 * V_417 = & V_406 -> V_175 -> V_418 [ V_194 ] ;
unsigned char T_12 * V_419 = V_417 -> V_420 ;
int V_74 = V_417 -> V_421 ;
if ( V_410 -> V_74 + V_74 > V_49 )
V_74 = V_49 - V_410 -> V_74 ;
else if ( V_194 + 1 == V_408 )
V_406 -> V_175 = NULL ;
if ( F_245 ( V_410 , V_419 , V_74 ) )
goto V_413;
}
V_175 = F_94 ( V_410 , V_2 -> V_339 ) ;
if ( V_175 == NULL )
goto V_413;
F_5 ( V_175 ) -> V_75 ++ ;
F_5 ( V_175 ) -> V_60 &= ~ V_88 ;
F_5 ( V_175 ) -> V_60 = ( V_231 | V_257 ) ;
F_239 ( V_2 , V_175 ) ;
V_406 -> V_422 = V_175 -> V_74 ;
if ( F_89 ( V_2 , V_410 , 0 , V_2 -> V_339 ) == 0 ) {
V_8 -> V_410 = ( V_406 -> V_422 > 0 ) ;
F_222 ( F_35 ( V_2 ) , V_423 ) ;
goto V_424;
}
V_410 = NULL ;
V_413:
if ( V_406 -> V_155 . V_74 > 0 )
V_406 -> V_155 . V_74 = 0 ;
V_205 = F_89 ( V_2 , V_392 , 1 , V_2 -> V_339 ) ;
if ( V_205 )
V_8 -> V_157 = 0 ;
F_246 ( V_410 ) ;
V_424:
V_406 -> V_155 . V_74 = - 1 ;
return V_205 ;
}
int F_247 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_251 ;
int V_205 ;
F_234 ( V_2 ) ;
if ( F_46 ( V_8 -> V_318 ) ) {
F_248 ( V_2 , NULL ) ;
return 0 ;
}
V_251 = F_217 ( V_360 + 15 , V_2 -> V_339 ) ;
if ( F_46 ( V_251 == NULL ) )
return - V_212 ;
F_219 ( V_251 , V_360 ) ;
F_43 ( V_251 , V_8 -> V_236 ++ , V_88 ) ;
V_8 -> V_366 = F_5 ( V_251 ) -> V_147 = V_22 ;
F_239 ( V_2 , V_251 ) ;
F_34 ( V_2 , V_251 ) ;
V_205 = V_8 -> V_141 ? F_241 ( V_2 , V_251 ) :
F_89 ( V_2 , V_251 , 1 , V_2 -> V_339 ) ;
if ( V_205 == - V_425 )
return V_205 ;
V_8 -> V_11 = V_8 -> V_236 ;
V_8 -> V_426 = V_8 -> V_236 ;
F_210 ( F_35 ( V_2 ) , V_427 ) ;
F_186 ( V_2 , V_328 ,
F_2 ( V_2 ) -> V_29 , V_332 ) ;
return 0 ;
}
void F_249 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 = V_6 -> V_34 . V_36 ;
unsigned long V_322 ;
if ( V_36 > V_428 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_429 = V_412 / 2 ;
if ( V_6 -> V_34 . V_38 ||
( V_6 -> V_34 . V_430 & V_431 ) )
V_429 = V_330 ;
if ( V_8 -> V_326 ) {
int V_325 = F_19 ( V_8 -> V_326 >> 3 , V_428 ) ;
if ( V_325 < V_429 )
V_429 = V_325 ;
}
V_36 = F_18 ( V_36 , V_429 ) ;
}
V_322 = V_303 + V_36 ;
if ( V_6 -> V_34 . V_430 & V_432 ) {
if ( V_6 -> V_34 . V_433 ||
F_250 ( V_6 -> V_34 . V_322 , V_303 + ( V_36 >> 2 ) ) ) {
F_251 ( V_2 ) ;
return;
}
if ( ! F_243 ( V_322 , V_6 -> V_34 . V_322 ) )
V_322 = V_6 -> V_34 . V_322 ;
}
V_6 -> V_34 . V_430 |= V_434 | V_432 ;
V_6 -> V_34 . V_322 = V_322 ;
F_252 ( V_2 , & V_6 -> V_435 , V_322 ) ;
}
void F_251 ( struct V_1 * V_2 )
{
struct V_3 * V_251 ;
if ( V_2 -> V_168 == V_338 )
return;
V_251 = F_221 ( V_360 , F_190 ( V_2 , V_174 ) ) ;
if ( V_251 == NULL ) {
F_253 ( V_2 ) ;
F_2 ( V_2 ) -> V_34 . V_36 = V_436 ;
F_186 ( V_2 , V_40 ,
V_330 , V_332 ) ;
return;
}
F_219 ( V_251 , V_360 ) ;
F_43 ( V_251 , F_8 ( V_2 ) , V_231 ) ;
F_5 ( V_251 ) -> V_147 = V_22 ;
F_89 ( V_2 , V_251 , 0 , F_190 ( V_2 , V_174 ) ) ;
}
static int F_254 ( struct V_1 * V_2 , int V_437 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_221 ( V_360 , F_190 ( V_2 , V_174 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_219 ( V_4 , V_360 ) ;
F_43 ( V_4 , V_8 -> V_90 - ! V_437 , V_231 ) ;
F_5 ( V_4 ) -> V_147 = V_22 ;
return F_89 ( V_2 , V_4 , 0 , V_174 ) ;
}
void F_255 ( struct V_1 * V_2 )
{
if ( V_2 -> V_168 == V_438 ) {
F_3 ( V_2 ) -> V_439 = F_3 ( V_2 ) -> V_58 - 1 ;
F_3 ( V_2 ) -> V_11 = F_3 ( V_2 ) -> V_236 ;
F_254 ( V_2 , 0 ) ;
}
}
int F_256 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_168 == V_338 )
return - 1 ;
if ( ( V_4 = F_165 ( V_2 ) ) != NULL &&
F_9 ( F_5 ( V_4 ) -> V_75 , F_10 ( V_8 ) ) ) {
int V_205 ;
unsigned int V_18 = F_56 ( V_2 ) ;
unsigned int V_440 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
if ( F_9 ( V_8 -> V_426 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_426 = F_5 ( V_4 ) -> V_12 ;
if ( V_440 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_75 ||
V_4 -> V_74 > V_18 ) {
V_440 = F_18 ( V_440 , V_18 ) ;
F_5 ( V_4 ) -> V_60 |= V_257 ;
if ( F_122 ( V_2 , V_4 , V_440 , V_18 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_113 ( V_2 , V_4 , V_18 ) ;
F_5 ( V_4 ) -> V_60 |= V_257 ;
F_5 ( V_4 ) -> V_147 = V_22 ;
V_205 = F_89 ( V_2 , V_4 , 1 , V_174 ) ;
if ( ! V_205 )
F_1 ( V_2 , V_4 ) ;
return V_205 ;
} else {
if ( F_257 ( V_8 -> V_91 , V_8 -> V_90 + 1 , V_8 -> V_90 + 0xFFFF ) )
F_254 ( V_2 , 1 ) ;
return F_254 ( V_2 , 0 ) ;
}
}
void F_258 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_205 ;
V_205 = F_256 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_165 ( V_2 ) ) {
V_6 -> V_441 = 0 ;
V_6 -> V_442 = 0 ;
return;
}
if ( V_205 <= 0 ) {
if ( V_6 -> V_442 < V_443 )
V_6 -> V_442 ++ ;
V_6 -> V_441 ++ ;
F_186 ( V_2 , V_444 ,
F_18 ( V_6 -> V_29 << V_6 -> V_442 , V_332 ) ,
V_332 ) ;
} else {
if ( ! V_6 -> V_441 )
V_6 -> V_441 = 1 ;
F_186 ( V_2 , V_444 ,
F_18 ( V_6 -> V_29 << V_6 -> V_442 ,
V_445 ) ,
V_332 ) ;
}
}
