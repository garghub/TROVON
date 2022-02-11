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
struct V_82 * V_83 = F_41 ( V_4 ) ;
V_4 -> V_84 = V_85 ;
V_4 -> V_86 = 0 ;
F_5 ( V_4 ) -> V_60 = V_81 ;
F_5 ( V_4 ) -> V_87 = 0 ;
V_83 -> V_88 = 1 ;
V_83 -> V_89 = 0 ;
V_83 -> V_78 = 0 ;
F_5 ( V_4 ) -> V_75 = V_75 ;
if ( V_81 & ( V_90 | V_91 ) )
V_75 ++ ;
F_5 ( V_4 ) -> V_12 = V_75 ;
}
static inline bool F_44 ( const struct V_7 * V_8 )
{
return V_8 -> V_92 != V_8 -> V_93 ;
}
static void F_45 ( T_9 * V_94 , struct V_7 * V_8 ,
struct V_95 * V_96 )
{
T_6 V_97 = V_96 -> V_97 ;
if ( F_46 ( V_98 & V_97 ) ) {
* V_94 ++ = F_47 ( ( V_99 << 24 ) | ( V_99 << 16 ) |
( V_100 << 8 ) | V_101 ) ;
V_96 -> V_102 = ( T_5 * ) V_94 ;
V_94 += 4 ;
}
if ( F_46 ( V_96 -> V_18 ) ) {
* V_94 ++ = F_47 ( ( V_103 << 24 ) |
( V_104 << 16 ) |
V_96 -> V_18 ) ;
}
if ( F_48 ( V_105 & V_97 ) ) {
if ( F_46 ( V_106 & V_97 ) ) {
* V_94 ++ = F_47 ( ( V_107 << 24 ) |
( V_108 << 16 ) |
( V_109 << 8 ) |
V_110 ) ;
V_97 &= ~ V_106 ;
} else {
* V_94 ++ = F_47 ( ( V_99 << 24 ) |
( V_99 << 16 ) |
( V_109 << 8 ) |
V_110 ) ;
}
* V_94 ++ = F_47 ( V_96 -> V_111 ) ;
* V_94 ++ = F_47 ( V_96 -> V_112 ) ;
}
if ( F_46 ( V_106 & V_97 ) ) {
* V_94 ++ = F_47 ( ( V_99 << 24 ) |
( V_99 << 16 ) |
( V_107 << 8 ) |
V_108 ) ;
}
if ( F_46 ( V_113 & V_97 ) ) {
* V_94 ++ = F_47 ( ( V_99 << 24 ) |
( V_114 << 16 ) |
( V_115 << 8 ) |
V_96 -> V_116 ) ;
}
if ( F_46 ( V_96 -> V_117 ) ) {
struct V_118 * V_119 = V_8 -> V_56 . V_120 ?
V_8 -> V_121 : V_8 -> V_122 ;
int V_123 ;
* V_94 ++ = F_47 ( ( V_99 << 24 ) |
( V_99 << 16 ) |
( V_124 << 8 ) |
( V_125 + ( V_96 -> V_117 *
V_126 ) ) ) ;
for ( V_123 = 0 ; V_123 < V_96 -> V_117 ;
++ V_123 ) {
* V_94 ++ = F_47 ( V_119 [ V_123 ] . V_127 ) ;
* V_94 ++ = F_47 ( V_119 [ V_123 ] . V_12 ) ;
}
V_8 -> V_56 . V_120 = 0 ;
}
if ( F_46 ( V_128 & V_97 ) ) {
struct V_129 * V_130 = V_96 -> V_131 ;
* V_94 ++ = F_47 ( ( V_132 << 24 ) |
( ( V_133 + V_130 -> V_74 ) << 16 ) |
V_134 ) ;
memcpy ( V_94 , V_130 -> V_135 , V_130 -> V_74 ) ;
if ( ( V_130 -> V_74 & 3 ) == 2 ) {
T_8 * V_136 = ( ( T_8 * ) V_94 ) + V_130 -> V_74 ;
V_136 [ 0 ] = V_136 [ 1 ] = V_99 ;
}
V_94 += ( V_130 -> V_74 + 3 ) >> 2 ;
}
}
static unsigned int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_137 * * V_138 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_139 = V_140 ;
struct V_141 * V_142 = V_8 -> V_143 ;
#ifdef F_50
* V_138 = V_8 -> V_144 -> V_145 ( V_2 , V_2 ) ;
if ( * V_138 ) {
V_96 -> V_97 |= V_98 ;
V_139 -= V_146 ;
}
#else
* V_138 = NULL ;
#endif
V_96 -> V_18 = F_11 ( V_2 ) ;
V_139 -= V_147 ;
if ( F_48 ( V_148 && * V_138 == NULL ) ) {
V_96 -> V_97 |= V_105 ;
V_96 -> V_111 = F_5 ( V_4 ) -> V_149 + V_8 -> V_150 ;
V_96 -> V_112 = V_8 -> V_56 . V_151 ;
V_139 -= V_152 ;
}
if ( F_48 ( V_153 ) ) {
V_96 -> V_116 = V_8 -> V_56 . V_47 ;
V_96 -> V_97 |= V_113 ;
V_139 -= V_154 ;
}
if ( F_48 ( V_155 ) ) {
V_96 -> V_97 |= V_106 ;
if ( F_46 ( ! ( V_105 & V_96 -> V_97 ) ) )
V_139 -= V_156 ;
}
if ( V_142 && V_142 -> V_157 . V_74 >= 0 ) {
T_4 V_158 = V_133 + V_142 -> V_157 . V_74 ;
V_158 = ( V_158 + 3 ) & ~ 3U ;
if ( V_139 >= V_158 ) {
V_96 -> V_97 |= V_128 ;
V_96 -> V_131 = & V_142 -> V_157 ;
V_139 -= V_158 ;
V_8 -> V_159 = 1 ;
}
}
return V_140 - V_139 ;
}
static unsigned int F_51 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
unsigned int V_18 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_137 * * V_138 ,
struct V_129 * V_130 )
{
struct V_160 * V_161 = F_37 ( V_68 ) ;
unsigned int V_139 = V_140 ;
#ifdef F_50
* V_138 = F_52 ( V_68 ) -> V_144 -> V_145 ( V_2 , V_68 ) ;
if ( * V_138 ) {
V_96 -> V_97 |= V_98 ;
V_139 -= V_146 ;
V_161 -> V_162 &= ! V_161 -> V_163 ;
}
#else
* V_138 = NULL ;
#endif
V_96 -> V_18 = V_18 ;
V_139 -= V_147 ;
if ( F_48 ( V_161 -> V_46 ) ) {
V_96 -> V_116 = V_161 -> V_47 ;
V_96 -> V_97 |= V_113 ;
V_139 -= V_154 ;
}
if ( F_48 ( V_161 -> V_162 ) ) {
V_96 -> V_97 |= V_105 ;
V_96 -> V_111 = F_5 ( V_4 ) -> V_149 ;
V_96 -> V_112 = V_68 -> V_151 ;
V_139 -= V_152 ;
}
if ( F_48 ( V_161 -> V_163 ) ) {
V_96 -> V_97 |= V_106 ;
if ( F_46 ( ! V_161 -> V_162 ) )
V_139 -= V_156 ;
}
if ( V_130 != NULL ) {
T_4 V_158 = V_133 + V_130 -> V_74 ;
V_158 = ( V_158 + 3 ) & ~ 3U ;
if ( V_139 >= V_158 ) {
V_96 -> V_97 |= V_128 ;
V_96 -> V_131 = V_130 ;
V_139 -= V_158 ;
}
}
return V_140 - V_139 ;
}
static unsigned int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_137 * * V_138 )
{
struct V_164 * V_165 = V_4 ? F_5 ( V_4 ) : NULL ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_166 = 0 ;
unsigned int V_167 ;
V_96 -> V_97 = 0 ;
#ifdef F_50
* V_138 = V_8 -> V_144 -> V_145 ( V_2 , V_2 ) ;
if ( F_46 ( * V_138 ) ) {
V_96 -> V_97 |= V_98 ;
V_166 += V_146 ;
}
#else
* V_138 = NULL ;
#endif
if ( F_48 ( V_8 -> V_56 . V_162 ) ) {
V_96 -> V_97 |= V_105 ;
V_96 -> V_111 = V_165 ? V_165 -> V_149 + V_8 -> V_150 : 0 ;
V_96 -> V_112 = V_8 -> V_56 . V_151 ;
V_166 += V_152 ;
}
V_167 = V_8 -> V_56 . V_168 + V_8 -> V_56 . V_120 ;
if ( F_46 ( V_167 ) ) {
const unsigned int V_139 = V_140 - V_166 ;
V_96 -> V_117 =
F_28 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_166 += V_169 +
V_96 -> V_117 * V_126 ;
}
return V_166 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_170 ) &
( V_171 | V_172 | V_173 |
V_174 | V_175 ) )
F_55 ( V_2 , F_56 ( V_2 ) , F_3 ( V_2 ) -> V_176 ,
0 , V_177 ) ;
}
static void F_57 ( unsigned long V_178 )
{
struct V_179 * V_180 = (struct V_179 * ) V_178 ;
F_58 ( V_181 ) ;
unsigned long V_81 ;
struct V_182 * V_183 , * V_184 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_59 ( V_81 ) ;
F_60 ( & V_180 -> V_185 , & V_181 ) ;
F_61 ( V_81 ) ;
F_62 (q, n, &list) {
V_8 = F_63 ( V_183 , struct V_7 , V_186 ) ;
F_64 ( & V_8 -> V_186 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_65 ( V_2 ) ;
if ( ! F_66 ( V_2 ) ) {
F_54 ( V_2 ) ;
} else {
F_67 ( V_187 , & V_8 -> V_188 ) ;
}
F_68 ( V_2 ) ;
F_69 ( V_189 , & V_8 -> V_188 ) ;
F_70 ( V_2 ) ;
}
}
void F_71 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_81 , V_190 ;
do {
V_81 = V_8 -> V_188 ;
if ( ! ( V_81 & V_191 ) )
return;
V_190 = V_81 & ~ V_191 ;
} while ( F_72 ( & V_8 -> V_188 , V_81 , V_190 ) != V_81 );
if ( V_81 & ( 1UL << V_187 ) )
F_54 ( V_2 ) ;
F_73 ( V_2 ) ;
if ( V_81 & ( 1UL << V_192 ) ) {
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( V_81 & ( 1UL << V_193 ) ) {
F_76 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( V_81 & ( 1UL << V_194 ) ) {
V_2 -> V_195 -> V_196 ( V_2 ) ;
F_75 ( V_2 ) ;
}
}
void T_10 F_77 ( void )
{
int V_197 ;
F_78 (i) {
struct V_179 * V_180 = & F_79 ( V_179 , V_197 ) ;
F_80 ( & V_180 -> V_185 ) ;
F_81 ( & V_180 -> V_198 ,
F_57 ,
( unsigned long ) V_180 ) ;
}
}
void F_82 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_83 ( V_199 , & V_8 -> V_188 ) &&
! F_84 ( V_189 , & V_8 -> V_188 ) ) {
unsigned long V_81 ;
struct V_179 * V_180 ;
F_85 ( V_4 -> V_200 - 1 , & V_2 -> V_201 ) ;
F_59 ( V_81 ) ;
V_180 = & F_86 ( V_179 ) ;
F_87 ( & V_8 -> V_186 , & V_180 -> V_185 ) ;
F_88 ( & V_180 -> V_198 ) ;
F_61 ( V_81 ) ;
} else {
F_89 ( V_4 ) ;
}
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_202 ,
T_11 V_203 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_204 * V_205 ;
struct V_7 * V_8 ;
struct V_164 * V_165 ;
struct V_95 V_96 ;
unsigned int V_206 , V_207 ;
struct V_137 * V_138 ;
struct V_69 * V_70 ;
int V_208 ;
F_91 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_202 ) {
const struct V_3 * V_209 = V_4 + 1 ;
if ( V_6 -> V_210 -> V_81 & V_211 )
F_92 ( V_4 ) ;
if ( F_46 ( V_4 -> V_209 == V_212 &&
V_209 -> V_209 == V_213 ) )
F_93 ( F_35 ( V_2 ) ,
V_214 ) ;
if ( F_46 ( F_94 ( V_4 ) ) )
V_4 = F_95 ( V_4 , V_203 ) ;
else
V_4 = F_96 ( V_4 , V_203 ) ;
if ( F_46 ( ! V_4 ) )
return - V_215 ;
}
V_205 = F_97 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_165 = F_5 ( V_4 ) ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
if ( F_46 ( V_165 -> V_60 & V_90 ) )
V_206 = F_49 ( V_2 , V_4 , & V_96 , & V_138 ) ;
else
V_206 = F_53 ( V_2 , V_4 , & V_96 ,
& V_138 ) ;
V_207 = V_206 + sizeof( struct V_69 ) ;
if ( F_98 ( V_8 ) == 0 )
F_16 ( V_2 , V_216 ) ;
V_4 -> V_217 = F_99 ( V_2 ) == 0 ;
F_100 ( V_4 , V_207 ) ;
F_101 ( V_4 ) ;
F_102 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_218 = F_82 ;
F_103 ( V_4 -> V_200 , & V_2 -> V_201 ) ;
V_70 = F_40 ( V_4 ) ;
V_70 -> V_219 = V_205 -> V_220 ;
V_70 -> V_221 = V_205 -> V_222 ;
V_70 -> V_75 = F_47 ( V_165 -> V_75 ) ;
V_70 -> V_223 = F_47 ( V_8 -> V_58 ) ;
* ( ( ( V_224 * ) V_70 ) + 6 ) = F_104 ( ( ( V_207 >> 2 ) << 12 ) |
V_165 -> V_60 ) ;
if ( F_46 ( V_165 -> V_60 & V_90 ) ) {
V_70 -> V_225 = F_104 ( F_18 ( V_8 -> V_44 , 65535U ) ) ;
} else {
V_70 -> V_225 = F_104 ( F_29 ( V_2 ) ) ;
}
V_70 -> V_226 = 0 ;
V_70 -> V_227 = 0 ;
if ( F_46 ( F_44 ( V_8 ) && F_9 ( V_165 -> V_75 , V_8 -> V_93 ) ) ) {
if ( F_9 ( V_8 -> V_93 , V_165 -> V_75 + 0x10000 ) ) {
V_70 -> V_227 = F_104 ( V_8 -> V_93 - V_165 -> V_75 ) ;
V_70 -> V_228 = 1 ;
} else if ( F_105 ( V_165 -> V_75 + 0xFFFF , V_8 -> V_11 ) ) {
V_70 -> V_227 = F_104 ( 0xFFFF ) ;
V_70 -> V_228 = 1 ;
}
}
F_45 ( ( T_9 * ) ( V_70 + 1 ) , V_8 , & V_96 ) ;
if ( F_48 ( ( V_165 -> V_60 & V_90 ) == 0 ) )
F_38 ( V_2 , V_4 , V_207 ) ;
#ifdef F_50
if ( V_138 ) {
F_106 ( V_2 , V_229 ) ;
V_8 -> V_144 -> V_230 ( V_96 . V_102 ,
V_138 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_231 -> V_232 ( V_2 , V_4 ) ;
if ( F_48 ( V_165 -> V_60 & V_233 ) )
F_22 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_74 != V_207 )
F_20 ( V_8 , V_2 ) ;
if ( F_105 ( V_165 -> V_12 , V_8 -> V_11 ) || V_165 -> V_75 == V_165 -> V_12 )
F_107 ( F_35 ( V_2 ) , V_234 ,
F_6 ( V_4 ) ) ;
V_208 = V_6 -> V_231 -> V_235 ( V_4 , & V_205 -> V_236 . V_237 ) ;
if ( F_48 ( V_208 <= 0 ) )
return V_208 ;
F_108 ( V_2 , 1 ) ;
return F_109 ( V_208 ) ;
}
static void F_110 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_238 = F_5 ( V_4 ) -> V_12 ;
F_111 ( V_4 ) ;
F_112 ( V_2 , V_4 ) ;
V_2 -> V_239 += V_4 -> V_200 ;
F_113 ( V_2 , V_4 -> V_200 ) ;
}
static void F_114 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_240 )
{
struct V_82 * V_83 = F_41 ( V_4 ) ;
F_115 ( F_94 ( V_4 ) ) ;
if ( V_4 -> V_74 <= V_240 || V_4 -> V_84 == V_241 ) {
V_83 -> V_88 = 1 ;
V_83 -> V_89 = 0 ;
V_83 -> V_78 = 0 ;
} else {
V_83 -> V_88 = F_116 ( V_4 -> V_74 , V_240 ) ;
V_83 -> V_89 = V_240 ;
V_83 -> V_78 = V_2 -> V_242 ;
}
}
static void F_117 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_243 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_244 || F_118 ( V_8 ) )
return;
if ( F_105 ( F_119 ( V_8 ) , F_5 ( V_4 ) -> V_75 ) )
V_8 -> V_245 -= V_243 ;
}
static void F_120 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_243 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_243 ;
if ( F_5 ( V_4 ) -> V_87 & V_246 )
V_8 -> V_244 -= V_243 ;
if ( F_5 ( V_4 ) -> V_87 & V_247 )
V_8 -> V_248 -= V_243 ;
if ( F_5 ( V_4 ) -> V_87 & V_249 )
V_8 -> V_250 -= V_243 ;
if ( F_118 ( V_8 ) && V_243 > 0 )
V_8 -> V_244 -= F_28 ( T_4 , V_8 -> V_244 , V_243 ) ;
F_117 ( V_2 , V_4 , V_243 ) ;
if ( V_8 -> V_251 &&
F_9 ( F_5 ( V_4 ) -> V_75 , F_5 ( V_8 -> V_251 ) -> V_75 ) &&
( F_121 ( V_8 ) || ( F_5 ( V_4 ) -> V_87 & V_246 ) ) )
V_8 -> V_252 -= V_243 ;
F_122 ( V_8 ) ;
}
int F_123 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_74 ,
unsigned int V_240 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_253 ;
int V_254 , V_255 ;
int V_256 ;
T_8 V_81 ;
if ( F_124 ( V_74 > V_4 -> V_74 ) )
return - V_257 ;
V_254 = F_125 ( V_4 ) - V_74 ;
if ( V_254 < 0 )
V_254 = 0 ;
if ( F_126 ( V_4 , V_177 ) )
return - V_258 ;
V_253 = F_127 ( V_2 , V_254 , V_177 ) ;
if ( V_253 == NULL )
return - V_258 ;
V_2 -> V_239 += V_253 -> V_200 ;
F_113 ( V_2 , V_253 -> V_200 ) ;
V_256 = V_4 -> V_74 - V_74 - V_254 ;
V_253 -> V_200 += V_256 ;
V_4 -> V_200 -= V_256 ;
F_5 ( V_253 ) -> V_75 = F_5 ( V_4 ) -> V_75 + V_74 ;
F_5 ( V_253 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_253 ) -> V_75 ;
V_81 = F_5 ( V_4 ) -> V_60 ;
F_5 ( V_4 ) -> V_60 = V_81 & ~ ( V_91 | V_259 ) ;
F_5 ( V_253 ) -> V_60 = V_81 ;
F_5 ( V_253 ) -> V_87 = F_5 ( V_4 ) -> V_87 ;
if ( ! F_41 ( V_4 ) -> V_260 && V_4 -> V_84 != V_85 ) {
V_253 -> V_86 = F_128 ( V_4 -> V_178 + V_74 ,
F_129 ( V_253 , V_254 ) ,
V_254 , 0 ) ;
F_130 ( V_4 , V_74 ) ;
V_4 -> V_86 = F_131 ( V_4 -> V_86 , V_253 -> V_86 , V_74 ) ;
} else {
V_4 -> V_84 = V_85 ;
F_132 ( V_4 , V_253 , V_74 ) ;
}
V_253 -> V_84 = V_4 -> V_84 ;
F_5 ( V_253 ) -> V_149 = F_5 ( V_4 ) -> V_149 ;
V_253 -> V_261 = V_4 -> V_261 ;
V_255 = F_6 ( V_4 ) ;
F_114 ( V_2 , V_4 , V_240 ) ;
F_114 ( V_2 , V_253 , V_240 ) ;
if ( ! F_9 ( V_8 -> V_11 , F_5 ( V_253 ) -> V_12 ) ) {
int V_262 = V_255 - F_6 ( V_4 ) -
F_6 ( V_253 ) ;
if ( V_262 )
F_120 ( V_2 , V_4 , V_262 ) ;
}
F_111 ( V_253 ) ;
F_133 ( V_4 , V_253 , V_2 ) ;
return 0 ;
}
static void F_134 ( struct V_3 * V_4 , int V_74 )
{
struct V_82 * V_83 ;
int V_197 , V_263 , V_264 ;
V_264 = F_28 ( int , V_74 , F_125 ( V_4 ) ) ;
if ( V_264 ) {
F_135 ( V_4 , V_264 ) ;
V_74 -= V_264 ;
if ( ! V_74 )
return;
}
V_264 = V_74 ;
V_263 = 0 ;
V_83 = F_41 ( V_4 ) ;
for ( V_197 = 0 ; V_197 < V_83 -> V_260 ; V_197 ++ ) {
int V_166 = F_136 ( & V_83 -> V_265 [ V_197 ] ) ;
if ( V_166 <= V_264 ) {
F_137 ( V_4 , V_197 ) ;
V_264 -= V_166 ;
} else {
V_83 -> V_265 [ V_263 ] = V_83 -> V_265 [ V_197 ] ;
if ( V_264 ) {
V_83 -> V_265 [ V_263 ] . V_266 += V_264 ;
F_138 ( & V_83 -> V_265 [ V_263 ] , V_264 ) ;
V_264 = 0 ;
}
V_263 ++ ;
}
}
V_83 -> V_260 = V_263 ;
F_139 ( V_4 ) ;
V_4 -> V_267 -= V_74 ;
V_4 -> V_74 = V_4 -> V_267 ;
}
int F_140 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_74 )
{
if ( F_126 ( V_4 , V_177 ) )
return - V_258 ;
F_134 ( V_4 , V_74 ) ;
F_5 ( V_4 ) -> V_75 += V_74 ;
V_4 -> V_84 = V_85 ;
V_4 -> V_200 -= V_74 ;
V_2 -> V_239 -= V_74 ;
F_141 ( V_2 , V_74 ) ;
F_142 ( V_2 , V_268 ) ;
if ( F_6 ( V_4 ) > 1 )
F_114 ( V_2 , V_4 , F_143 ( V_4 ) ) ;
return 0 ;
}
static inline int F_144 ( struct V_1 * V_2 , int V_269 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_240 ;
V_240 = V_269 - V_6 -> V_231 -> V_270 - sizeof( struct V_69 ) ;
if ( V_6 -> V_231 -> V_271 ) {
const struct V_16 * V_17 = F_12 ( V_2 ) ;
if ( V_17 && F_145 ( V_17 ) )
V_240 -= V_6 -> V_231 -> V_271 ;
}
if ( V_240 > V_8 -> V_56 . V_272 )
V_240 = V_8 -> V_56 . V_272 ;
V_240 -= V_6 -> V_273 ;
if ( V_240 < 48 )
V_240 = 48 ;
return V_240 ;
}
int F_146 ( struct V_1 * V_2 , int V_269 )
{
return F_144 ( V_2 , V_269 ) -
( F_3 ( V_2 ) -> V_73 - sizeof( struct V_69 ) ) ;
}
int F_147 ( struct V_1 * V_2 , int V_18 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_274 ;
V_274 = V_18 +
V_8 -> V_73 +
V_6 -> V_273 +
V_6 -> V_231 -> V_270 ;
if ( V_6 -> V_231 -> V_271 ) {
const struct V_16 * V_17 = F_12 ( V_2 ) ;
if ( V_17 && F_145 ( V_17 ) )
V_274 += V_6 -> V_231 -> V_271 ;
}
return V_274 ;
}
void F_148 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_275 . V_276 = V_277 > 1 ;
V_6 -> V_275 . V_278 = V_8 -> V_56 . V_272 + sizeof( struct V_69 ) +
V_6 -> V_231 -> V_270 ;
V_6 -> V_275 . V_279 = F_147 ( V_2 , V_280 ) ;
V_6 -> V_275 . V_281 = 0 ;
}
unsigned int F_149 ( struct V_1 * V_2 , T_4 V_269 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_240 ;
if ( V_6 -> V_275 . V_278 > V_269 )
V_6 -> V_275 . V_278 = V_269 ;
V_240 = F_146 ( V_2 , V_269 ) ;
V_240 = F_150 ( V_8 , V_240 ) ;
V_6 -> V_282 = V_269 ;
if ( V_6 -> V_275 . V_276 )
V_240 = F_18 ( V_240 , F_146 ( V_2 , V_6 -> V_275 . V_279 ) ) ;
V_8 -> V_283 = V_240 ;
return V_240 ;
}
unsigned int F_56 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_16 * V_17 = F_12 ( V_2 ) ;
T_4 V_240 ;
unsigned int V_284 ;
struct V_95 V_96 ;
struct V_137 * V_138 ;
V_240 = V_8 -> V_283 ;
if ( V_17 ) {
T_4 V_274 = F_151 ( V_17 ) ;
if ( V_274 != F_2 ( V_2 ) -> V_282 )
V_240 = F_149 ( V_2 , V_274 ) ;
}
V_284 = F_53 ( V_2 , NULL , & V_96 , & V_138 ) +
sizeof( struct V_69 ) ;
if ( V_284 != V_8 -> V_73 ) {
int V_21 = ( int ) V_284 - V_8 -> V_73 ;
V_240 -= V_21 ;
}
return V_240 ;
}
static void F_152 ( struct V_1 * V_2 )
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
F_153 ( V_2 ) ;
}
}
static bool F_154 ( const struct V_7 * V_8 )
{
return F_105 ( V_8 -> V_285 , V_8 -> V_92 ) &&
! F_105 ( V_8 -> V_285 , V_8 -> V_11 ) ;
}
static void F_155 ( struct V_7 * V_8 , unsigned int V_240 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_74 < F_6 ( V_4 ) * V_240 )
V_8 -> V_285 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_156 ( bool V_286 , const struct V_7 * V_8 ,
unsigned int V_240 , int V_176 )
{
return V_286 &&
( ( V_176 & V_287 ) ||
( ! V_176 && V_8 -> V_10 && F_154 ( V_8 ) ) ) ;
}
static unsigned int F_157 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_240 ,
unsigned int V_288 ,
int V_176 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_286 , V_289 , V_225 , V_290 ;
V_225 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
V_290 = V_240 * V_288 ;
if ( F_48 ( V_290 <= V_225 && V_4 != F_158 ( V_2 ) ) )
return V_290 ;
V_289 = F_18 ( V_4 -> V_74 , V_225 ) ;
if ( V_290 <= V_289 )
return V_290 ;
V_286 = V_289 % V_240 ;
if ( F_156 ( V_286 != 0 , V_8 , V_240 , V_176 ) )
return V_289 - V_286 ;
return V_289 ;
}
static inline unsigned int F_159 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_291 , V_25 ;
if ( ( F_5 ( V_4 ) -> V_60 & V_91 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_291 = F_98 ( V_8 ) ;
V_25 = V_8 -> V_26 ;
if ( V_291 < V_25 )
return ( V_25 - V_291 ) ;
return 0 ;
}
static int F_160 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_240 )
{
int V_292 = F_6 ( V_4 ) ;
if ( ! V_292 || ( V_292 > 1 && F_143 ( V_4 ) != V_240 ) ) {
F_114 ( V_2 , V_4 , V_240 ) ;
V_292 = F_6 ( V_4 ) ;
}
return V_292 ;
}
static inline bool F_161 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_293 , int V_176 )
{
if ( V_176 & V_294 )
return true ;
if ( F_44 ( V_8 ) || ( F_5 ( V_4 ) -> V_60 & V_91 ) )
return true ;
if ( ! F_156 ( V_4 -> V_74 < V_293 , V_8 , V_293 , V_176 ) )
return true ;
return false ;
}
static bool F_162 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_293 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_74 > V_293 )
V_12 = F_5 ( V_4 ) -> V_75 + V_293 ;
return ! F_105 ( V_12 , F_10 ( V_8 ) ) ;
}
static unsigned int F_163 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_293 , int V_176 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_295 ;
F_160 ( V_2 , V_4 , V_293 ) ;
if ( ! F_161 ( V_8 , V_4 , V_293 , V_176 ) )
return 0 ;
V_295 = F_159 ( V_8 , V_4 ) ;
if ( V_295 && ! F_162 ( V_8 , V_4 , V_293 ) )
V_295 = 0 ;
return V_295 ;
}
bool F_164 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_165 ( V_2 ) ;
return V_4 &&
F_163 ( V_2 , V_4 , F_56 ( V_2 ) ,
( F_166 ( V_2 , V_4 ) ?
V_8 -> V_176 : V_294 ) ) ;
}
static int F_167 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_74 ,
unsigned int V_240 , T_11 V_296 )
{
struct V_3 * V_253 ;
int V_256 = V_4 -> V_74 - V_74 ;
T_8 V_81 ;
if ( V_4 -> V_74 != V_4 -> V_267 )
return F_123 ( V_2 , V_4 , V_74 , V_240 ) ;
V_253 = F_127 ( V_2 , 0 , V_296 ) ;
if ( F_46 ( V_253 == NULL ) )
return - V_258 ;
V_2 -> V_239 += V_253 -> V_200 ;
F_113 ( V_2 , V_253 -> V_200 ) ;
V_253 -> V_200 += V_256 ;
V_4 -> V_200 -= V_256 ;
F_5 ( V_253 ) -> V_75 = F_5 ( V_4 ) -> V_75 + V_74 ;
F_5 ( V_253 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_253 ) -> V_75 ;
V_81 = F_5 ( V_4 ) -> V_60 ;
F_5 ( V_4 ) -> V_60 = V_81 & ~ ( V_91 | V_259 ) ;
F_5 ( V_253 ) -> V_60 = V_81 ;
F_5 ( V_253 ) -> V_87 = 0 ;
V_253 -> V_84 = V_4 -> V_84 = V_85 ;
F_132 ( V_4 , V_253 , V_74 ) ;
F_114 ( V_2 , V_4 , V_240 ) ;
F_114 ( V_2 , V_253 , V_240 ) ;
F_111 ( V_253 ) ;
F_133 ( V_4 , V_253 , V_2 ) ;
return 0 ;
}
static bool F_168 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_297 , V_298 , V_299 , V_291 ;
int V_300 ;
if ( F_5 ( V_4 ) -> V_60 & V_91 )
goto V_301;
if ( V_6 -> V_302 != V_303 )
goto V_301;
if ( V_8 -> V_304 &&
( ( ( T_4 ) V_305 << 1 ) >> 1 ) - ( V_8 -> V_304 >> 1 ) > 1 )
goto V_301;
V_291 = F_98 ( V_8 ) ;
F_91 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_26 <= V_291 ) ) ;
V_297 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
V_298 = ( V_8 -> V_26 - V_291 ) * V_8 -> V_283 ;
V_299 = F_18 ( V_297 , V_298 ) ;
if ( V_299 >= F_28 (unsigned int, sk->sk_gso_max_size,
tp->xmit_size_goal_segs * tp->mss_cache) )
goto V_301;
if ( ( V_4 != F_158 ( V_2 ) ) && ( V_299 >= V_4 -> V_74 ) )
goto V_301;
V_300 = F_169 ( V_306 ) ;
if ( V_300 ) {
T_4 V_307 = F_18 ( V_8 -> V_308 , V_8 -> V_26 * V_8 -> V_283 ) ;
V_307 /= V_300 ;
if ( V_299 >= V_307 )
goto V_301;
} else {
if ( V_299 > F_170 ( V_8 ) * V_8 -> V_283 )
goto V_301;
}
if ( ! V_8 -> V_304 )
V_8 -> V_304 = 1 | ( V_305 << 1 ) ;
return true ;
V_301:
V_8 -> V_304 = 0 ;
return false ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_309 , * V_310 ;
int V_74 ;
int V_281 ;
int V_311 ;
int V_312 ;
int V_240 ;
if ( ! V_6 -> V_275 . V_276 ||
V_6 -> V_275 . V_281 ||
F_2 ( V_2 ) -> V_302 != V_303 ||
V_8 -> V_26 < 11 ||
V_8 -> V_56 . V_168 || V_8 -> V_56 . V_120 )
return - 1 ;
V_240 = F_56 ( V_2 ) ;
V_281 = 2 * V_8 -> V_283 ;
V_311 = V_281 + ( V_8 -> V_313 + 1 ) * V_8 -> V_283 ;
if ( V_281 > F_146 ( V_2 , V_6 -> V_275 . V_278 ) ) {
return - 1 ;
}
if ( V_8 -> V_238 - V_8 -> V_11 < V_311 )
return - 1 ;
if ( V_8 -> V_308 < V_311 )
return - 1 ;
if ( F_105 ( V_8 -> V_11 + V_311 , F_10 ( V_8 ) ) )
return 0 ;
if ( F_98 ( V_8 ) + 2 > V_8 -> V_26 ) {
if ( ! F_98 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_309 = F_127 ( V_2 , V_281 , V_177 ) ) == NULL )
return - 1 ;
V_2 -> V_239 += V_309 -> V_200 ;
F_113 ( V_2 , V_309 -> V_200 ) ;
V_4 = F_165 ( V_2 ) ;
F_5 ( V_309 ) -> V_75 = F_5 ( V_4 ) -> V_75 ;
F_5 ( V_309 ) -> V_12 = F_5 ( V_4 ) -> V_75 + V_281 ;
F_5 ( V_309 ) -> V_60 = V_233 ;
F_5 ( V_309 ) -> V_87 = 0 ;
V_309 -> V_86 = 0 ;
V_309 -> V_84 = V_4 -> V_84 ;
F_172 ( V_309 , V_4 , V_2 ) ;
V_74 = 0 ;
F_173 (skb, next, sk) {
V_312 = F_28 ( int , V_4 -> V_74 , V_281 - V_74 ) ;
if ( V_309 -> V_84 )
F_174 ( V_4 , 0 , F_129 ( V_309 , V_312 ) , V_312 ) ;
else
V_309 -> V_86 = F_175 ( V_4 , 0 ,
F_129 ( V_309 , V_312 ) ,
V_312 , V_309 -> V_86 ) ;
if ( V_4 -> V_74 <= V_312 ) {
F_5 ( V_309 ) -> V_60 |= F_5 ( V_4 ) -> V_60 ;
F_176 ( V_4 , V_2 ) ;
F_177 ( V_2 , V_4 ) ;
} else {
F_5 ( V_309 ) -> V_60 |= F_5 ( V_4 ) -> V_60 &
~ ( V_91 | V_259 ) ;
if ( ! F_41 ( V_4 ) -> V_260 ) {
F_178 ( V_4 , V_312 ) ;
if ( V_4 -> V_84 != V_85 )
V_4 -> V_86 = F_179 ( V_4 -> V_178 ,
V_4 -> V_74 , 0 ) ;
} else {
F_134 ( V_4 , V_312 ) ;
F_114 ( V_2 , V_4 , V_240 ) ;
}
F_5 ( V_4 ) -> V_75 += V_312 ;
}
V_74 += V_312 ;
if ( V_74 >= V_281 )
break;
}
F_160 ( V_2 , V_309 , V_309 -> V_74 ) ;
F_5 ( V_309 ) -> V_149 = V_22 ;
if ( ! F_90 ( V_2 , V_309 , 1 , V_177 ) ) {
V_8 -> V_26 -- ;
F_1 ( V_2 , V_309 ) ;
V_6 -> V_275 . V_281 = F_147 ( V_2 , V_309 -> V_74 ) ;
V_8 -> V_314 . V_315 = F_5 ( V_309 ) -> V_75 ;
V_8 -> V_314 . V_316 = F_5 ( V_309 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_55 ( struct V_1 * V_2 , unsigned int V_240 , int V_176 ,
int V_317 , T_11 V_296 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_292 , V_318 ;
int V_295 ;
int V_319 ;
V_318 = 0 ;
if ( ! V_317 ) {
V_319 = F_171 ( V_2 ) ;
if ( ! V_319 ) {
return false ;
} else if ( V_319 > 0 ) {
V_318 = 1 ;
}
}
while ( ( V_4 = F_165 ( V_2 ) ) ) {
unsigned int V_299 ;
V_292 = F_160 ( V_2 , V_4 , V_240 ) ;
F_91 ( ! V_292 ) ;
if ( F_46 ( V_8 -> V_320 ) && V_8 -> V_321 == V_322 )
goto V_320;
V_295 = F_159 ( V_8 , V_4 ) ;
if ( ! V_295 ) {
if ( V_317 == 2 )
V_295 = 1 ;
else
break;
}
if ( F_46 ( ! F_162 ( V_8 , V_4 , V_240 ) ) )
break;
if ( V_292 == 1 ) {
if ( F_46 ( ! F_161 ( V_8 , V_4 , V_240 ,
( F_166 ( V_2 , V_4 ) ?
V_176 : V_294 ) ) ) )
break;
} else {
if ( ! V_317 && F_168 ( V_2 , V_4 ) )
break;
}
V_299 = F_27 (unsigned int, sysctl_tcp_limit_output_bytes,
sk->sk_pacing_rate >> 10 ) ;
if ( F_180 ( & V_2 -> V_201 ) > V_299 ) {
F_67 ( V_199 , & V_8 -> V_188 ) ;
F_181 () ;
if ( F_180 ( & V_2 -> V_201 ) > V_299 )
break;
}
V_299 = V_240 ;
if ( V_292 > 1 && ! F_44 ( V_8 ) )
V_299 = F_157 ( V_2 , V_4 , V_240 ,
F_28 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ,
V_176 ) ;
if ( V_4 -> V_74 > V_299 &&
F_46 ( F_167 ( V_2 , V_4 , V_299 , V_240 , V_296 ) ) )
break;
F_5 ( V_4 ) -> V_149 = V_22 ;
if ( F_46 ( F_90 ( V_2 , V_4 , 1 , V_296 ) ) )
break;
V_320:
F_1 ( V_2 , V_4 ) ;
F_155 ( V_8 , V_240 , V_4 ) ;
V_318 += F_6 ( V_4 ) ;
if ( V_317 )
break;
}
if ( F_48 ( V_318 ) ) {
if ( F_182 ( V_2 ) )
V_8 -> V_323 += V_318 ;
if ( V_317 != 2 )
F_183 ( V_2 ) ;
F_152 ( V_2 ) ;
return false ;
}
return ( V_317 == 2 ) || ( ! V_8 -> V_10 && F_165 ( V_2 ) ) ;
}
bool F_183 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_324 , V_325 , V_326 ;
T_4 V_327 = V_8 -> V_328 >> 3 ;
if ( F_124 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_124 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_170 == V_329 )
return false ;
if ( V_6 -> V_13 != V_330 )
return false ;
if ( V_331 < 3 || ! V_8 -> V_328 || ! V_8 -> V_10 ||
! F_184 ( V_8 ) || F_2 ( V_2 ) -> V_302 != V_303 )
return false ;
if ( ( V_8 -> V_26 > F_98 ( V_8 ) ) &&
F_165 ( V_2 ) )
return false ;
V_324 = V_327 << 1 ;
if ( V_8 -> V_10 == 1 )
V_324 = F_27 ( T_4 , V_324 ,
( V_327 + ( V_327 >> 1 ) + V_332 ) ) ;
V_324 = F_27 ( T_4 , V_324 , F_185 ( 10 ) ) ;
V_325 = V_22 + V_324 ;
V_326 = ( T_4 ) F_2 ( V_2 ) -> V_333 ;
if ( ( T_3 ) ( V_325 - V_326 ) > 0 ) {
T_3 V_21 = V_326 - V_22 ;
if ( V_21 > 0 )
V_324 = V_21 ;
}
F_186 ( V_2 , V_15 , V_324 ,
V_334 ) ;
return true ;
}
void F_187 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_335 ;
int V_18 = F_56 ( V_2 ) ;
int V_208 = - 1 ;
if ( F_165 ( V_2 ) != NULL ) {
V_208 = F_55 ( V_2 , V_18 , V_336 , 2 , V_177 ) ;
goto V_337;
}
if ( V_8 -> V_338 )
goto V_337;
V_4 = F_158 ( V_2 ) ;
if ( F_124 ( ! V_4 ) )
goto V_337;
V_335 = F_6 ( V_4 ) ;
if ( F_124 ( ! V_335 ) )
goto V_337;
if ( ( V_335 > 1 ) && ( V_4 -> V_74 > ( V_335 - 1 ) * V_18 ) ) {
if ( F_46 ( F_123 ( V_2 , V_4 , ( V_335 - 1 ) * V_18 , V_18 ) ) )
goto V_337;
V_4 = F_158 ( V_2 ) ;
}
if ( F_124 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_337;
if ( V_4 -> V_74 > 0 )
V_208 = F_188 ( V_2 , V_4 ) ;
if ( F_48 ( ! V_208 ) )
V_8 -> V_338 = V_8 -> V_11 ;
V_337:
F_186 ( V_2 , V_330 ,
F_2 ( V_2 ) -> V_29 ,
V_334 ) ;
if ( F_48 ( ! V_208 ) )
F_189 ( F_35 ( V_2 ) ,
V_339 ) ;
return;
}
void F_190 ( struct V_1 * V_2 , unsigned int V_293 ,
int V_176 )
{
if ( F_46 ( V_2 -> V_170 == V_340 ) )
return;
if ( F_55 ( V_2 , V_293 , V_176 , 0 ,
F_191 ( V_2 , V_177 ) ) )
F_192 ( V_2 ) ;
}
void F_193 ( struct V_1 * V_2 , unsigned int V_240 )
{
struct V_3 * V_4 = F_165 ( V_2 ) ;
F_91 ( ! V_4 || V_4 -> V_74 < V_240 ) ;
F_55 ( V_2 , V_240 , V_294 , 1 , V_2 -> V_341 ) ;
}
T_4 F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_18 = V_6 -> V_34 . V_342 ;
int V_343 = F_194 ( V_2 ) ;
int V_344 = F_28 ( int , V_8 -> V_45 , F_195 ( V_2 ) ) ;
int V_225 ;
if ( V_18 > V_344 )
V_18 = V_344 ;
if ( V_343 < ( V_344 >> 1 ) ) {
V_6 -> V_34 . V_345 = 0 ;
if ( F_196 ( V_2 ) )
V_8 -> V_346 = F_18 ( V_8 -> V_346 ,
4U * V_8 -> V_19 ) ;
if ( V_343 < V_18 )
return 0 ;
}
if ( V_343 > V_8 -> V_346 )
V_343 = V_8 -> V_346 ;
V_225 = V_8 -> V_44 ;
if ( V_8 -> V_56 . V_47 ) {
V_225 = V_343 ;
if ( ( ( V_225 >> V_8 -> V_56 . V_47 ) << V_8 -> V_56 . V_47 ) != V_225 )
V_225 = ( ( ( V_225 >> V_8 -> V_56 . V_47 ) + 1 )
<< V_8 -> V_56 . V_47 ) ;
} else {
if ( V_225 <= V_343 - V_18 || V_225 > V_343 )
V_225 = ( V_343 / V_18 ) * V_18 ;
else if ( V_18 == V_344 &&
V_343 > V_225 + ( V_344 >> 1 ) )
V_225 = V_343 ;
}
return V_225 ;
}
static void F_197 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_347 = F_198 ( V_2 , V_4 ) ;
int V_348 , V_349 ;
V_348 = V_4 -> V_74 ;
V_349 = V_347 -> V_74 ;
F_91 ( F_6 ( V_4 ) != 1 || F_6 ( V_347 ) != 1 ) ;
F_199 ( V_2 , V_347 , V_4 ) ;
F_176 ( V_347 , V_2 ) ;
F_200 ( V_347 , F_129 ( V_4 , V_349 ) ,
V_349 ) ;
if ( V_347 -> V_84 == V_85 )
V_4 -> V_84 = V_85 ;
if ( V_4 -> V_84 != V_85 )
V_4 -> V_86 = F_201 ( V_4 -> V_86 , V_347 -> V_86 , V_348 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_347 ) -> V_12 ;
F_5 ( V_4 ) -> V_60 |= F_5 ( V_347 ) -> V_60 ;
F_5 ( V_4 ) -> V_87 |= F_5 ( V_347 ) -> V_87 & V_350 ;
F_202 ( V_8 ) ;
if ( V_347 == V_8 -> V_351 )
V_8 -> V_351 = V_4 ;
F_120 ( V_2 , V_347 , F_6 ( V_347 ) ) ;
F_177 ( V_2 , V_347 ) ;
}
static bool F_203 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_41 ( V_4 ) -> V_260 != 0 )
return false ;
if ( F_94 ( V_4 ) )
return false ;
if ( V_4 == F_165 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_87 & V_246 )
return false ;
return true ;
}
static void F_204 ( struct V_1 * V_2 , struct V_3 * V_352 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_352 , * V_353 ;
bool V_354 = true ;
if ( ! V_355 )
return;
if ( F_5 ( V_4 ) -> V_60 & V_90 )
return;
F_173 (skb, tmp, sk) {
if ( ! F_203 ( V_2 , V_4 ) )
break;
V_49 -= V_4 -> V_74 ;
if ( V_354 ) {
V_354 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_74 > F_205 ( V_352 ) )
break;
if ( F_105 ( F_5 ( V_4 ) -> V_12 , F_10 ( V_8 ) ) )
break;
F_197 ( V_2 , V_352 ) ;
}
}
int F_188 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_293 ;
int V_208 ;
if ( V_6 -> V_275 . V_281 ) {
V_6 -> V_275 . V_281 = 0 ;
}
if ( F_180 ( & V_2 -> V_201 ) >
F_18 ( V_2 -> V_239 + ( V_2 -> V_239 >> 2 ) , V_2 -> V_356 ) )
return - V_357 ;
if ( F_9 ( F_5 ( V_4 ) -> V_75 , V_8 -> V_92 ) ) {
if ( F_9 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_92 ) )
F_206 () ;
if ( F_140 ( V_2 , V_4 , V_8 -> V_92 - F_5 ( V_4 ) -> V_75 ) )
return - V_258 ;
}
if ( F_2 ( V_2 ) -> V_231 -> V_358 ( V_2 ) )
return - V_359 ;
V_293 = F_56 ( V_2 ) ;
if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , F_10 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_75 != V_8 -> V_92 )
return - V_357 ;
if ( V_4 -> V_74 > V_293 ) {
if ( F_123 ( V_2 , V_4 , V_293 , V_293 ) )
return - V_258 ;
} else {
int V_360 = F_6 ( V_4 ) ;
if ( F_46 ( V_360 > 1 ) ) {
if ( F_126 ( V_4 , V_177 ) )
return - V_258 ;
F_160 ( V_2 , V_4 , V_293 ) ;
F_120 ( V_2 , V_4 , V_360 - F_6 ( V_4 ) ) ;
}
}
F_204 ( V_2 , V_4 , V_293 ) ;
F_5 ( V_4 ) -> V_149 = V_22 ;
if ( F_46 ( ( V_361 && ( ( unsigned long ) V_4 -> V_178 & 3 ) ) ||
F_207 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_309 = F_208 ( V_4 , V_362 ,
V_177 ) ;
V_208 = V_309 ? F_90 ( V_2 , V_309 , 0 , V_177 ) :
- V_215 ;
} else {
V_208 = F_90 ( V_2 , V_4 , 1 , V_177 ) ;
}
if ( F_48 ( ! V_208 ) )
F_5 ( V_4 ) -> V_87 |= V_350 ;
return V_208 ;
}
int F_209 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_208 = F_188 ( V_2 , V_4 ) ;
if ( V_208 == 0 ) {
F_210 ( F_35 ( V_2 ) , V_363 ) ;
V_8 -> V_364 ++ ;
#if V_365 > 0
if ( F_5 ( V_4 ) -> V_87 & V_247 ) {
F_211 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_248 )
V_8 -> V_366 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_87 |= V_367 ;
V_8 -> V_248 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_368 )
V_8 -> V_368 = F_5 ( V_4 ) -> V_149 ;
V_8 -> V_369 += F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_223 = V_8 -> V_11 ;
} else {
F_189 ( F_35 ( V_2 ) , V_370 ) ;
}
return V_208 ;
}
static bool F_212 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_302 != V_371 )
return false ;
if ( F_118 ( V_8 ) )
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
struct V_3 * V_372 = NULL ;
T_4 V_373 ;
int V_374 ;
int V_375 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_250 )
V_8 -> V_376 = V_8 -> V_92 ;
if ( V_8 -> V_351 ) {
V_4 = V_8 -> V_351 ;
V_373 = F_5 ( V_4 ) -> V_12 ;
if ( F_105 ( V_373 , V_8 -> V_376 ) )
V_373 = V_8 -> V_376 ;
} else {
V_4 = F_214 ( V_2 ) ;
V_373 = V_8 -> V_92 ;
}
F_215 (skb, sk) {
T_5 V_87 = F_5 ( V_4 ) -> V_87 ;
if ( V_4 == F_165 ( V_2 ) )
break;
if ( V_372 == NULL )
V_8 -> V_351 = V_4 ;
if ( F_98 ( V_8 ) >= V_8 -> V_26 )
return;
if ( V_375 ) {
V_377:
if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , F_119 ( V_8 ) ) )
break;
V_374 = V_378 ;
} else if ( ! F_9 ( F_5 ( V_4 ) -> V_75 , V_8 -> V_376 ) ) {
V_8 -> V_376 = V_373 ;
if ( ! F_212 ( V_2 ) )
break;
if ( V_372 != NULL ) {
V_4 = V_372 ;
V_372 = NULL ;
}
V_375 = 1 ;
goto V_377;
} else if ( ! ( V_87 & V_249 ) ) {
if ( V_372 == NULL && ! ( V_87 & ( V_247 | V_246 ) ) )
V_372 = V_4 ;
continue;
} else {
V_373 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_302 != V_379 )
V_374 = V_380 ;
else
V_374 = V_381 ;
}
if ( V_87 & ( V_246 | V_247 ) )
continue;
if ( F_209 ( V_2 , V_4 ) )
return;
F_189 ( F_35 ( V_2 ) , V_374 ) ;
if ( F_182 ( V_2 ) )
V_8 -> V_323 += F_6 ( V_4 ) ;
if ( V_4 == F_214 ( V_2 ) )
F_186 ( V_2 , V_330 ,
F_2 ( V_2 ) -> V_29 ,
V_334 ) ;
}
}
void F_216 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_158 ( V_2 ) ;
int V_240 ;
V_240 = F_56 ( V_2 ) ;
if ( F_165 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_60 |= V_91 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_238 ++ ;
} else {
for (; ; ) {
V_4 = F_217 ( V_362 ,
V_2 -> V_341 ) ;
if ( V_4 )
break;
F_218 () ;
}
F_219 ( V_4 , V_362 ) ;
F_43 ( V_4 , V_8 -> V_238 ,
V_233 | V_91 ) ;
F_110 ( V_2 , V_4 ) ;
}
F_190 ( V_2 , V_240 , V_336 ) ;
}
void F_220 ( struct V_1 * V_2 , T_11 V_382 )
{
struct V_3 * V_4 ;
V_4 = F_221 ( V_362 , V_382 ) ;
if ( ! V_4 ) {
F_93 ( F_35 ( V_2 ) , V_383 ) ;
return;
}
F_219 ( V_4 , V_362 ) ;
F_43 ( V_4 , F_8 ( V_2 ) ,
V_233 | V_384 ) ;
F_5 ( V_4 ) -> V_149 = V_22 ;
if ( F_90 ( V_2 , V_4 , 0 , V_382 ) )
F_93 ( F_35 ( V_2 ) , V_383 ) ;
F_210 ( F_35 ( V_2 ) , V_385 ) ;
}
int F_222 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_214 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_60 & V_90 ) ) {
F_223 ( L_2 , V_386 ) ;
return - V_387 ;
}
if ( ! ( F_5 ( V_4 ) -> V_60 & V_233 ) ) {
if ( F_94 ( V_4 ) ) {
struct V_3 * V_309 = F_224 ( V_4 , V_177 ) ;
if ( V_309 == NULL )
return - V_258 ;
F_176 ( V_4 , V_2 ) ;
F_111 ( V_309 ) ;
F_225 ( V_2 , V_309 ) ;
F_177 ( V_2 , V_4 ) ;
V_2 -> V_239 += V_309 -> V_200 ;
F_113 ( V_2 , V_309 -> V_200 ) ;
V_4 = V_309 ;
}
F_5 ( V_4 ) -> V_60 |= V_233 ;
F_33 ( F_3 ( V_2 ) , V_4 ) ;
}
F_5 ( V_4 ) -> V_149 = V_22 ;
return F_90 ( V_2 , V_4 , 1 , V_177 ) ;
}
struct V_3 * F_226 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_67 * V_68 ,
struct V_129 * V_130 )
{
struct V_95 V_96 ;
struct V_160 * V_161 = F_37 ( V_68 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_69 * V_70 ;
struct V_3 * V_4 ;
struct V_137 * V_138 ;
int V_207 ;
int V_18 ;
V_4 = F_227 ( V_2 , V_362 + 15 , 1 , V_177 ) ;
if ( F_46 ( ! V_4 ) ) {
F_228 ( V_17 ) ;
return NULL ;
}
F_219 ( V_4 , V_362 ) ;
F_229 ( V_4 , V_17 ) ;
F_230 ( V_4 , V_2 ) ;
V_18 = F_13 ( V_17 ) ;
if ( V_8 -> V_56 . V_388 && V_8 -> V_56 . V_388 < V_18 )
V_18 = V_8 -> V_56 . V_388 ;
if ( V_68 -> V_44 == 0 ) {
T_5 V_47 ;
V_68 -> V_45 = V_8 -> V_45 ? : F_21 ( V_17 , V_389 ) ;
if ( V_2 -> V_390 & V_391 &&
( V_68 -> V_45 > F_195 ( V_2 ) || V_68 -> V_45 == 0 ) )
V_68 -> V_45 = F_195 ( V_2 ) ;
F_26 ( F_195 ( V_2 ) ,
V_18 - ( V_161 -> V_162 ? V_152 : 0 ) ,
& V_68 -> V_44 ,
& V_68 -> V_45 ,
V_161 -> V_46 ,
& V_47 ,
F_21 ( V_17 , V_392 ) ) ;
V_161 -> V_47 = V_47 ;
}
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
#ifdef F_231
if ( F_46 ( V_68 -> V_393 ) )
F_5 ( V_4 ) -> V_149 = F_232 ( V_68 ) ;
else
#endif
F_5 ( V_4 ) -> V_149 = V_22 ;
V_207 = F_51 ( V_2 , V_68 , V_18 , V_4 , & V_96 , & V_138 ,
V_130 ) + sizeof( * V_70 ) ;
F_100 ( V_4 , V_207 ) ;
F_101 ( V_4 ) ;
V_70 = F_40 ( V_4 ) ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_394 = 1 ;
V_70 -> V_395 = 1 ;
F_36 ( V_68 , V_70 ) ;
V_70 -> V_219 = F_104 ( V_161 -> V_396 ) ;
V_70 -> V_221 = V_161 -> V_397 ;
F_43 ( V_4 , F_52 ( V_68 ) -> V_398 ,
V_90 | V_233 ) ;
V_70 -> V_75 = F_47 ( F_5 ( V_4 ) -> V_75 ) ;
V_70 -> V_223 = F_47 ( F_52 ( V_68 ) -> V_58 ) ;
V_70 -> V_225 = F_104 ( F_18 ( V_68 -> V_44 , 65535U ) ) ;
F_45 ( ( T_9 * ) ( V_70 + 1 ) , V_8 , & V_96 ) ;
V_70 -> V_399 = ( V_207 >> 2 ) ;
F_107 ( F_35 ( V_2 ) , V_234 , F_6 ( V_4 ) ) ;
#ifdef F_50
if ( V_138 ) {
F_52 ( V_68 ) -> V_144 -> V_230 ( V_96 . V_102 ,
V_138 , NULL , V_68 , V_4 ) ;
}
#endif
return V_4 ;
}
static void F_233 ( struct V_1 * V_2 )
{
const struct V_16 * V_17 = F_12 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_47 ;
V_8 -> V_73 = sizeof( struct V_69 ) +
( V_148 ? V_152 : 0 ) ;
#ifdef F_50
if ( V_8 -> V_144 -> V_145 ( V_2 , V_2 ) != NULL )
V_8 -> V_73 += V_146 ;
#endif
if ( V_8 -> V_56 . V_388 )
V_8 -> V_56 . V_272 = V_8 -> V_56 . V_388 ;
V_8 -> V_400 = 0 ;
F_148 ( V_2 ) ;
F_149 ( V_2 , F_151 ( V_17 ) ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_21 ( V_17 , V_389 ) ;
V_8 -> V_19 = F_13 ( V_17 ) ;
if ( V_8 -> V_56 . V_388 && V_8 -> V_56 . V_388 < V_8 -> V_19 )
V_8 -> V_19 = V_8 -> V_56 . V_388 ;
F_234 ( V_2 ) ;
if ( V_2 -> V_390 & V_391 &&
( V_8 -> V_45 > F_195 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_195 ( V_2 ) ;
F_26 ( F_195 ( V_2 ) ,
V_8 -> V_19 - ( V_8 -> V_56 . V_401 ? V_8 -> V_73 - sizeof( struct V_69 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_153 ,
& V_47 ,
F_21 ( V_17 , V_392 ) ) ;
V_8 -> V_56 . V_47 = V_47 ;
V_8 -> V_346 = V_8 -> V_44 ;
V_2 -> V_402 = 0 ;
F_235 ( V_2 , V_403 ) ;
V_8 -> V_308 = 0 ;
F_236 ( V_8 , 0 ) ;
V_8 -> V_92 = V_8 -> V_238 ;
V_8 -> V_285 = V_8 -> V_238 ;
V_8 -> V_93 = V_8 -> V_238 ;
V_8 -> V_11 = V_8 -> V_238 ;
if ( F_48 ( ! V_8 -> V_320 ) )
V_8 -> V_58 = 0 ;
else
V_8 -> V_404 = V_22 ;
V_8 -> V_57 = V_8 -> V_58 ;
V_8 -> V_405 = V_8 -> V_58 ;
F_2 ( V_2 ) -> V_29 = V_406 ;
F_2 ( V_2 ) -> V_407 = 0 ;
F_237 ( V_8 ) ;
}
static void F_238 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_164 * V_165 = F_5 ( V_4 ) ;
V_165 -> V_12 += V_4 -> V_74 ;
F_111 ( V_4 ) ;
F_239 ( V_2 , V_4 ) ;
V_2 -> V_239 += V_4 -> V_200 ;
F_113 ( V_2 , V_4 -> V_200 ) ;
V_8 -> V_238 = V_165 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_240 ( struct V_1 * V_2 , struct V_3 * V_394 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_141 * V_408 = V_8 -> V_143 ;
int V_409 = 0 , V_49 , V_197 , V_208 = 0 , V_410 = V_408 -> V_178 -> V_411 ;
struct V_3 * V_412 = NULL , * V_178 ;
unsigned long V_413 = 0 ;
V_8 -> V_56 . V_272 = V_8 -> V_19 ;
F_241 ( V_2 , & V_8 -> V_56 . V_272 , & V_408 -> V_157 ,
& V_409 , & V_413 ) ;
if ( V_409 > 1 &&
F_242 ( V_305 , V_413 + ( 60 * V_414 << V_409 ) ) ) {
V_408 -> V_157 . V_74 = - 1 ;
goto V_415;
}
if ( V_416 & V_417 )
V_408 -> V_157 . V_74 = - 1 ;
else if ( V_408 -> V_157 . V_74 <= 0 )
goto V_415;
if ( V_8 -> V_56 . V_388 && V_8 -> V_56 . V_388 < V_8 -> V_56 . V_272 )
V_8 -> V_56 . V_272 = V_8 -> V_56 . V_388 ;
V_49 = F_144 ( V_2 , F_2 ( V_2 ) -> V_282 ) -
V_140 ;
V_49 = F_28 ( V_418 , V_49 , V_408 -> V_166 ) ;
V_49 = F_28 ( V_418 , V_49 , F_243 ( V_362 ) ) ;
V_412 = F_244 ( V_394 , V_362 , V_49 ,
V_2 -> V_341 ) ;
if ( V_412 == NULL )
goto V_415;
for ( V_197 = 0 ; V_197 < V_410 && V_412 -> V_74 < V_49 ; ++ V_197 ) {
struct V_419 * V_420 = & V_408 -> V_178 -> V_421 [ V_197 ] ;
unsigned char T_12 * V_422 = V_420 -> V_423 ;
int V_74 = V_420 -> V_424 ;
if ( V_412 -> V_74 + V_74 > V_49 )
V_74 = V_49 - V_412 -> V_74 ;
else if ( V_197 + 1 == V_410 )
V_408 -> V_178 = NULL ;
if ( F_245 ( V_412 , V_422 , V_74 ) )
goto V_415;
}
V_178 = F_95 ( V_412 , V_2 -> V_341 ) ;
if ( V_178 == NULL )
goto V_415;
F_5 ( V_178 ) -> V_75 ++ ;
F_5 ( V_178 ) -> V_60 &= ~ V_90 ;
F_5 ( V_178 ) -> V_60 = ( V_233 | V_259 ) ;
F_238 ( V_2 , V_178 ) ;
V_408 -> V_425 = V_178 -> V_74 ;
if ( F_90 ( V_2 , V_412 , 0 , V_2 -> V_341 ) == 0 ) {
V_8 -> V_412 = ( V_408 -> V_425 > 0 ) ;
F_93 ( F_35 ( V_2 ) , V_426 ) ;
goto V_427;
}
V_412 = NULL ;
V_415:
if ( V_408 -> V_157 . V_74 > 0 )
V_408 -> V_157 . V_74 = 0 ;
V_208 = F_90 ( V_2 , V_394 , 1 , V_2 -> V_341 ) ;
if ( V_208 )
V_8 -> V_159 = 0 ;
F_246 ( V_412 ) ;
V_427:
V_408 -> V_157 . V_74 = - 1 ;
return V_208 ;
}
int F_247 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_253 ;
int V_208 ;
F_233 ( V_2 ) ;
if ( F_46 ( V_8 -> V_320 ) ) {
F_248 ( V_2 , NULL ) ;
return 0 ;
}
V_253 = F_217 ( V_362 + 15 , V_2 -> V_341 ) ;
if ( F_46 ( V_253 == NULL ) )
return - V_215 ;
F_219 ( V_253 , V_362 ) ;
F_43 ( V_253 , V_8 -> V_238 ++ , V_90 ) ;
V_8 -> V_368 = F_5 ( V_253 ) -> V_149 = V_22 ;
F_238 ( V_2 , V_253 ) ;
F_34 ( V_2 , V_253 ) ;
V_208 = V_8 -> V_143 ? F_240 ( V_2 , V_253 ) :
F_90 ( V_2 , V_253 , 1 , V_2 -> V_341 ) ;
if ( V_208 == - V_428 )
return V_208 ;
V_8 -> V_11 = V_8 -> V_238 ;
V_8 -> V_429 = V_8 -> V_238 ;
F_210 ( F_35 ( V_2 ) , V_430 ) ;
F_186 ( V_2 , V_330 ,
F_2 ( V_2 ) -> V_29 , V_334 ) ;
return 0 ;
}
void F_249 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 = V_6 -> V_34 . V_36 ;
unsigned long V_324 ;
if ( V_36 > V_431 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_432 = V_414 / 2 ;
if ( V_6 -> V_34 . V_38 ||
( V_6 -> V_34 . V_433 & V_434 ) )
V_432 = V_332 ;
if ( V_8 -> V_328 ) {
int V_327 = F_19 ( V_8 -> V_328 >> 3 , V_431 ) ;
if ( V_327 < V_432 )
V_432 = V_327 ;
}
V_36 = F_18 ( V_36 , V_432 ) ;
}
V_324 = V_305 + V_36 ;
if ( V_6 -> V_34 . V_433 & V_435 ) {
if ( V_6 -> V_34 . V_436 ||
F_250 ( V_6 -> V_34 . V_324 , V_305 + ( V_36 >> 2 ) ) ) {
F_251 ( V_2 ) ;
return;
}
if ( ! F_242 ( V_324 , V_6 -> V_34 . V_324 ) )
V_324 = V_6 -> V_34 . V_324 ;
}
V_6 -> V_34 . V_433 |= V_437 | V_435 ;
V_6 -> V_34 . V_324 = V_324 ;
F_252 ( V_2 , & V_6 -> V_438 , V_324 ) ;
}
void F_251 ( struct V_1 * V_2 )
{
struct V_3 * V_253 ;
if ( V_2 -> V_170 == V_340 )
return;
V_253 = F_221 ( V_362 , F_191 ( V_2 , V_177 ) ) ;
if ( V_253 == NULL ) {
F_253 ( V_2 ) ;
F_2 ( V_2 ) -> V_34 . V_36 = V_439 ;
F_186 ( V_2 , V_40 ,
V_332 , V_334 ) ;
return;
}
F_219 ( V_253 , V_362 ) ;
F_43 ( V_253 , F_8 ( V_2 ) , V_233 ) ;
F_5 ( V_253 ) -> V_149 = V_22 ;
F_90 ( V_2 , V_253 , 0 , F_191 ( V_2 , V_177 ) ) ;
}
static int F_254 ( struct V_1 * V_2 , int V_440 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_221 ( V_362 , F_191 ( V_2 , V_177 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_219 ( V_4 , V_362 ) ;
F_43 ( V_4 , V_8 -> V_92 - ! V_440 , V_233 ) ;
F_5 ( V_4 ) -> V_149 = V_22 ;
return F_90 ( V_2 , V_4 , 0 , V_177 ) ;
}
void F_255 ( struct V_1 * V_2 )
{
if ( V_2 -> V_170 == V_441 ) {
F_3 ( V_2 ) -> V_442 = F_3 ( V_2 ) -> V_58 - 1 ;
F_254 ( V_2 , 0 ) ;
}
}
int F_256 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_170 == V_340 )
return - 1 ;
if ( ( V_4 = F_165 ( V_2 ) ) != NULL &&
F_9 ( F_5 ( V_4 ) -> V_75 , F_10 ( V_8 ) ) ) {
int V_208 ;
unsigned int V_18 = F_56 ( V_2 ) ;
unsigned int V_443 = F_10 ( V_8 ) - F_5 ( V_4 ) -> V_75 ;
if ( F_9 ( V_8 -> V_429 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_429 = F_5 ( V_4 ) -> V_12 ;
if ( V_443 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_75 ||
V_4 -> V_74 > V_18 ) {
V_443 = F_18 ( V_443 , V_18 ) ;
F_5 ( V_4 ) -> V_60 |= V_259 ;
if ( F_123 ( V_2 , V_4 , V_443 , V_18 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_114 ( V_2 , V_4 , V_18 ) ;
F_5 ( V_4 ) -> V_60 |= V_259 ;
F_5 ( V_4 ) -> V_149 = V_22 ;
V_208 = F_90 ( V_2 , V_4 , 1 , V_177 ) ;
if ( ! V_208 )
F_1 ( V_2 , V_4 ) ;
return V_208 ;
} else {
if ( F_257 ( V_8 -> V_93 , V_8 -> V_92 + 1 , V_8 -> V_92 + 0xFFFF ) )
F_254 ( V_2 , 1 ) ;
return F_254 ( V_2 , 0 ) ;
}
}
void F_258 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_208 ;
V_208 = F_256 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_165 ( V_2 ) ) {
V_6 -> V_444 = 0 ;
V_6 -> V_445 = 0 ;
return;
}
if ( V_208 <= 0 ) {
if ( V_6 -> V_445 < V_446 )
V_6 -> V_445 ++ ;
V_6 -> V_444 ++ ;
F_186 ( V_2 , V_447 ,
F_18 ( V_6 -> V_29 << V_6 -> V_445 , V_334 ) ,
V_334 ) ;
} else {
if ( ! V_6 -> V_444 )
V_6 -> V_444 = 1 ;
F_186 ( V_2 , V_447 ,
F_18 ( V_6 -> V_29 << V_6 -> V_445 ,
V_448 ) ,
V_334 ) ;
}
}
