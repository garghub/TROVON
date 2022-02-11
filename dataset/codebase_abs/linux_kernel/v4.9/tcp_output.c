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
void F_16 ( struct V_1 * V_2 , T_3 V_22 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_23 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_24 = V_8 -> V_25 ;
F_18 ( V_2 , V_26 ) ;
V_8 -> V_27 = F_19 ( V_2 ) ;
V_23 = F_20 ( V_23 , V_24 ) ;
while ( ( V_22 -= F_2 ( V_2 ) -> V_28 ) > 0 && V_24 > V_23 )
V_24 >>= 1 ;
V_8 -> V_25 = F_21 ( V_24 , V_23 ) ;
V_8 -> V_29 = V_30 ;
V_8 -> V_31 = 0 ;
}
static void F_22 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_4 V_32 = V_30 ;
if ( F_23 ( V_8 ) == 0 )
F_18 ( V_2 , V_33 ) ;
V_8 -> V_34 = V_32 ;
if ( ( T_4 ) ( V_32 - V_6 -> V_35 . V_36 ) < V_6 -> V_35 . V_37 )
V_6 -> V_35 . V_38 = 1 ;
}
static inline void F_24 ( struct V_1 * V_2 , unsigned int V_39 )
{
F_25 ( V_2 , V_39 ) ;
F_26 ( V_2 , V_40 ) ;
}
T_4 F_27 ( T_4 V_19 )
{
T_4 V_41 = V_42 * 2 ;
if ( V_19 > 1460 )
V_41 = F_21 ( ( 1460 * V_41 ) / V_19 , 2U ) ;
return V_41 ;
}
void F_28 ( int V_43 , T_1 V_19 ,
T_1 * V_44 , T_1 * V_45 ,
int V_46 , T_5 * V_47 ,
T_1 V_48 )
{
unsigned int V_49 = ( V_43 < 0 ? 0 : V_43 ) ;
if ( * V_45 == 0 )
( * V_45 ) = ( 65535 << 14 ) ;
V_49 = F_20 ( * V_45 , V_49 ) ;
if ( V_49 > V_19 )
V_49 = ( V_49 / V_19 ) * V_19 ;
if ( V_50 )
( * V_44 ) = F_20 ( V_49 , V_51 ) ;
else
( * V_44 ) = V_49 ;
( * V_47 ) = 0 ;
if ( V_46 ) {
V_49 = F_29 ( T_4 , V_49 , V_52 [ 2 ] ) ;
V_49 = F_29 ( T_4 , V_49 , V_53 ) ;
V_49 = F_30 ( T_4 , V_49 , * V_45 ) ;
while ( V_49 > 65535 && ( * V_47 ) < 14 ) {
V_49 >>= 1 ;
( * V_47 ) ++ ;
}
}
if ( V_19 > ( 1 << * V_47 ) ) {
if ( ! V_48 )
V_48 = F_27 ( V_19 ) ;
* V_44 = F_20 ( * V_44 , V_48 * V_19 ) ;
}
( * V_45 ) = F_20 ( 65535U << ( * V_47 ) , * V_45 ) ;
}
static T_6 F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_54 = V_8 -> V_44 ;
T_4 V_55 = F_32 ( V_8 ) ;
T_4 V_56 = F_33 ( V_2 ) ;
if ( V_56 < V_55 ) {
if ( V_56 == 0 )
F_34 ( F_9 ( V_2 ) ,
V_57 ) ;
V_56 = F_35 ( V_55 , 1 << V_8 -> V_58 . V_47 ) ;
}
V_8 -> V_44 = V_56 ;
V_8 -> V_59 = V_8 -> V_60 ;
if ( ! V_8 -> V_58 . V_47 && V_50 )
V_56 = F_20 ( V_56 , V_51 ) ;
else
V_56 = F_20 ( V_56 , ( 65535U << V_8 -> V_58 . V_47 ) ) ;
V_56 >>= V_8 -> V_58 . V_47 ;
if ( V_56 == 0 ) {
V_8 -> V_61 = 0 ;
if ( V_54 )
F_34 ( F_9 ( V_2 ) ,
V_62 ) ;
} else if ( V_54 == 0 ) {
F_34 ( F_9 ( V_2 ) , V_63 ) ;
}
return V_56 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
F_5 ( V_4 ) -> V_64 &= ~ V_65 ;
if ( ! ( V_8 -> V_66 & V_67 ) )
F_5 ( V_4 ) -> V_64 &= ~ V_68 ;
else if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
bool V_69 = F_9 ( V_2 ) -> V_70 . V_71 == 1 ||
F_37 ( V_2 ) ;
if ( ! V_69 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_40 ( V_18 , V_72 ) )
V_69 = true ;
}
V_8 -> V_66 = 0 ;
if ( V_69 ) {
F_5 ( V_4 ) -> V_64 |= V_68 | V_65 ;
V_8 -> V_66 = V_67 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_9 ( V_2 ) -> V_70 . V_73 )
F_5 ( V_4 ) -> V_64 &= ~ ( V_68 | V_65 ) ;
}
static void
F_42 ( const struct V_74 * V_75 , struct V_76 * V_77 )
{
if ( F_43 ( V_75 ) -> V_78 )
V_77 -> V_79 = 1 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_76 * V_77 , int V_80 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_66 & V_67 ) {
if ( V_4 -> V_81 != V_80 &&
! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_11 ) ) {
F_38 ( V_2 ) ;
if ( V_8 -> V_66 & V_83 ) {
V_8 -> V_66 &= ~ V_83 ;
V_77 -> V_84 = 1 ;
F_45 ( V_4 ) -> V_85 |= V_86 ;
}
} else if ( ! F_37 ( V_2 ) ) {
F_46 ( V_2 ) ;
}
if ( V_8 -> V_66 & V_87 )
V_77 -> V_79 = 1 ;
}
}
static void F_47 ( struct V_3 * V_4 , T_4 V_82 , T_7 V_88 )
{
V_4 -> V_89 = V_90 ;
V_4 -> V_91 = 0 ;
F_5 ( V_4 ) -> V_64 = V_88 ;
F_5 ( V_4 ) -> V_92 = 0 ;
F_48 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_82 = V_82 ;
if ( V_88 & ( V_93 | V_94 ) )
V_82 ++ ;
F_5 ( V_4 ) -> V_12 = V_82 ;
}
static inline bool F_49 ( const struct V_7 * V_8 )
{
return V_8 -> V_95 != V_8 -> V_96 ;
}
static void F_50 ( T_8 * V_97 , struct V_7 * V_8 ,
struct V_98 * V_99 )
{
T_6 V_100 = V_99 -> V_100 ;
if ( F_51 ( V_101 & V_100 ) ) {
* V_97 ++ = F_52 ( ( V_102 << 24 ) | ( V_102 << 16 ) |
( V_103 << 8 ) | V_104 ) ;
V_99 -> V_105 = ( T_5 * ) V_97 ;
V_97 += 4 ;
}
if ( F_51 ( V_99 -> V_19 ) ) {
* V_97 ++ = F_52 ( ( V_106 << 24 ) |
( V_107 << 16 ) |
V_99 -> V_19 ) ;
}
if ( F_53 ( V_108 & V_100 ) ) {
if ( F_51 ( V_109 & V_100 ) ) {
* V_97 ++ = F_52 ( ( V_110 << 24 ) |
( V_111 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
V_100 &= ~ V_109 ;
} else {
* V_97 ++ = F_52 ( ( V_102 << 24 ) |
( V_102 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
}
* V_97 ++ = F_52 ( V_99 -> V_114 ) ;
* V_97 ++ = F_52 ( V_99 -> V_115 ) ;
}
if ( F_51 ( V_109 & V_100 ) ) {
* V_97 ++ = F_52 ( ( V_102 << 24 ) |
( V_102 << 16 ) |
( V_110 << 8 ) |
V_111 ) ;
}
if ( F_51 ( V_116 & V_100 ) ) {
* V_97 ++ = F_52 ( ( V_102 << 24 ) |
( V_117 << 16 ) |
( V_118 << 8 ) |
V_99 -> V_119 ) ;
}
if ( F_51 ( V_99 -> V_120 ) ) {
struct V_121 * V_122 = V_8 -> V_58 . V_123 ?
V_8 -> V_124 : V_8 -> V_125 ;
int V_126 ;
* V_97 ++ = F_52 ( ( V_102 << 24 ) |
( V_102 << 16 ) |
( V_127 << 8 ) |
( V_128 + ( V_99 -> V_120 *
V_129 ) ) ) ;
for ( V_126 = 0 ; V_126 < V_99 -> V_120 ;
++ V_126 ) {
* V_97 ++ = F_52 ( V_122 [ V_126 ] . V_130 ) ;
* V_97 ++ = F_52 ( V_122 [ V_126 ] . V_12 ) ;
}
V_8 -> V_58 . V_123 = 0 ;
}
if ( F_51 ( V_131 & V_100 ) ) {
struct V_132 * V_133 = V_99 -> V_134 ;
T_7 * V_135 = ( T_7 * ) V_97 ;
T_4 V_81 ;
if ( V_133 -> exp ) {
V_81 = V_136 + V_133 -> V_81 ;
* V_97 = F_52 ( ( V_137 << 24 ) | ( V_81 << 16 ) |
V_138 ) ;
V_135 += V_136 ;
} else {
V_81 = V_139 + V_133 -> V_81 ;
* V_135 ++ = V_140 ;
* V_135 ++ = V_81 ;
}
memcpy ( V_135 , V_133 -> V_141 , V_133 -> V_81 ) ;
if ( ( V_81 & 3 ) == 2 ) {
V_135 [ V_133 -> V_81 ] = V_102 ;
V_135 [ V_133 -> V_81 + 1 ] = V_102 ;
}
V_97 += ( V_81 + 3 ) >> 2 ;
}
}
static unsigned int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_98 * V_99 ,
struct V_142 * * V_143 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_144 = V_145 ;
struct V_146 * V_147 = V_8 -> V_148 ;
#ifdef F_55
* V_143 = V_8 -> V_149 -> V_150 ( V_2 , V_2 ) ;
if ( * V_143 ) {
V_99 -> V_100 |= V_101 ;
V_144 -= V_151 ;
}
#else
* V_143 = NULL ;
#endif
V_99 -> V_19 = F_13 ( V_2 ) ;
V_144 -= V_152 ;
if ( F_53 ( V_153 && ! * V_143 ) ) {
V_99 -> V_100 |= V_108 ;
V_99 -> V_114 = F_56 ( V_4 ) + V_8 -> V_154 ;
V_99 -> V_115 = V_8 -> V_58 . V_155 ;
V_144 -= V_156 ;
}
if ( F_53 ( V_157 ) ) {
V_99 -> V_119 = V_8 -> V_58 . V_47 ;
V_99 -> V_100 |= V_116 ;
V_144 -= V_158 ;
}
if ( F_53 ( V_159 ) ) {
V_99 -> V_100 |= V_109 ;
if ( F_51 ( ! ( V_108 & V_99 -> V_100 ) ) )
V_144 -= V_160 ;
}
if ( V_147 && V_147 -> V_161 . V_81 >= 0 ) {
T_4 V_162 = V_147 -> V_161 . V_81 ;
V_162 += V_147 -> V_161 . exp ? V_136 :
V_139 ;
V_162 = ( V_162 + 3 ) & ~ 3U ;
if ( V_144 >= V_162 ) {
V_99 -> V_100 |= V_131 ;
V_99 -> V_134 = & V_147 -> V_161 ;
V_144 -= V_162 ;
V_8 -> V_163 = 1 ;
V_8 -> V_164 = V_147 -> V_161 . exp ? 1 : 0 ;
}
}
return V_145 - V_144 ;
}
static unsigned int F_57 ( struct V_74 * V_75 ,
unsigned int V_19 , struct V_3 * V_4 ,
struct V_98 * V_99 ,
const struct V_142 * V_143 ,
struct V_132 * V_133 )
{
struct V_165 * V_166 = F_43 ( V_75 ) ;
unsigned int V_144 = V_145 ;
#ifdef F_55
if ( V_143 ) {
V_99 -> V_100 |= V_101 ;
V_144 -= V_151 ;
V_166 -> V_167 &= ! V_166 -> V_168 ;
}
#endif
V_99 -> V_19 = V_19 ;
V_144 -= V_152 ;
if ( F_53 ( V_166 -> V_46 ) ) {
V_99 -> V_119 = V_166 -> V_47 ;
V_99 -> V_100 |= V_116 ;
V_144 -= V_158 ;
}
if ( F_53 ( V_166 -> V_167 ) ) {
V_99 -> V_100 |= V_108 ;
V_99 -> V_114 = F_56 ( V_4 ) ;
V_99 -> V_115 = V_75 -> V_155 ;
V_144 -= V_156 ;
}
if ( F_53 ( V_166 -> V_168 ) ) {
V_99 -> V_100 |= V_109 ;
if ( F_51 ( ! V_166 -> V_167 ) )
V_144 -= V_160 ;
}
if ( V_133 != NULL && V_133 -> V_81 >= 0 ) {
T_4 V_162 = V_133 -> V_81 ;
V_162 += V_133 -> exp ? V_136 :
V_139 ;
V_162 = ( V_162 + 3 ) & ~ 3U ;
if ( V_144 >= V_162 ) {
V_99 -> V_100 |= V_131 ;
V_99 -> V_134 = V_133 ;
V_144 -= V_162 ;
}
}
return V_145 - V_144 ;
}
static unsigned int F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_98 * V_99 ,
struct V_142 * * V_143 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_169 = 0 ;
unsigned int V_170 ;
V_99 -> V_100 = 0 ;
#ifdef F_55
* V_143 = V_8 -> V_149 -> V_150 ( V_2 , V_2 ) ;
if ( F_51 ( * V_143 ) ) {
V_99 -> V_100 |= V_101 ;
V_169 += V_151 ;
}
#else
* V_143 = NULL ;
#endif
if ( F_53 ( V_8 -> V_58 . V_167 ) ) {
V_99 -> V_100 |= V_108 ;
V_99 -> V_114 = V_4 ? F_56 ( V_4 ) + V_8 -> V_154 : 0 ;
V_99 -> V_115 = V_8 -> V_58 . V_155 ;
V_169 += V_156 ;
}
V_170 = V_8 -> V_58 . V_171 + V_8 -> V_58 . V_123 ;
if ( F_51 ( V_170 ) ) {
const unsigned int V_144 = V_145 - V_169 ;
V_99 -> V_120 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_169 += V_172 +
V_99 -> V_120 * V_129 ;
}
return V_169 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_173 ) &
( V_174 | V_175 | V_176 |
V_177 | V_178 ) ) {
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_179 > V_8 -> V_180 &&
V_8 -> V_25 > F_23 ( V_8 ) )
F_60 ( V_2 ) ;
F_61 ( V_2 , F_62 ( V_2 ) , V_8 -> V_181 ,
0 , V_182 ) ;
}
}
static void F_63 ( unsigned long V_183 )
{
struct V_184 * V_185 = (struct V_184 * ) V_183 ;
F_64 ( V_186 ) ;
unsigned long V_88 ;
struct V_187 * V_188 , * V_189 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_65 ( V_88 ) ;
F_66 ( & V_185 -> V_190 , & V_186 ) ;
F_67 ( V_88 ) ;
F_68 (q, n, &list) {
V_8 = F_69 ( V_188 , struct V_7 , V_191 ) ;
F_70 ( & V_8 -> V_191 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_71 ( V_2 ) ;
if ( ! F_72 ( V_2 ) ) {
F_59 ( V_2 ) ;
} else {
F_73 ( V_192 , & V_8 -> V_193 ) ;
}
F_74 ( V_2 ) ;
F_75 ( V_194 , & V_8 -> V_193 ) ;
F_76 ( V_2 ) ;
}
}
void F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_88 , V_195 ;
do {
V_88 = V_8 -> V_193 ;
if ( ! ( V_88 & V_196 ) )
return;
V_195 = V_88 & ~ V_196 ;
} while ( F_78 ( & V_8 -> V_193 , V_88 , V_195 ) != V_88 );
if ( V_88 & ( 1UL << V_192 ) )
F_59 ( V_2 ) ;
F_79 ( V_2 ) ;
if ( V_88 & ( 1UL << V_197 ) ) {
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_198 ) ) {
F_82 ( V_2 ) ;
F_81 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_199 ) ) {
F_2 ( V_2 ) -> V_200 -> V_201 ( V_2 ) ;
F_81 ( V_2 ) ;
}
}
void T_9 F_83 ( void )
{
int V_202 ;
F_84 (i) {
struct V_184 * V_185 = & F_85 ( V_184 , V_202 ) ;
F_86 ( & V_185 -> V_190 ) ;
F_87 ( & V_185 -> V_203 ,
F_63 ,
( unsigned long ) V_185 ) ;
}
}
void F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_204 ;
V_204 = F_89 ( V_4 -> V_205 - 1 , & V_2 -> V_206 ) ;
if ( V_204 >= F_90 ( 1 ) && F_91 () == V_207 )
goto V_208;
if ( F_92 ( V_209 , & V_8 -> V_193 ) &&
! F_93 ( V_194 , & V_8 -> V_193 ) ) {
unsigned long V_88 ;
struct V_184 * V_185 ;
F_65 ( V_88 ) ;
V_185 = F_94 ( & V_184 ) ;
F_95 ( & V_8 -> V_191 , & V_185 -> V_190 ) ;
F_96 ( & V_185 -> V_203 ) ;
F_67 ( V_88 ) ;
return;
}
V_208:
F_76 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_210 ,
T_10 V_211 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_212 * V_213 ;
struct V_7 * V_8 ;
struct V_214 * V_215 ;
struct V_98 V_99 ;
unsigned int V_216 , V_217 ;
struct V_142 * V_143 ;
struct V_76 * V_77 ;
int V_218 ;
F_98 ( ! V_4 || ! F_6 ( V_4 ) ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_210 ) {
F_99 ( & V_4 -> V_219 ) ;
F_5 ( V_4 ) -> V_220 . V_221 = F_5 ( V_4 ) -> V_12
- V_8 -> V_95 ;
F_100 ( V_2 , V_4 ) ;
if ( F_51 ( F_101 ( V_4 ) ) )
V_4 = F_102 ( V_4 , V_211 ) ;
else
V_4 = F_103 ( V_4 , V_211 ) ;
if ( F_51 ( ! V_4 ) )
return - V_222 ;
}
V_213 = F_104 ( V_2 ) ;
V_215 = F_5 ( V_4 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( F_51 ( V_215 -> V_64 & V_93 ) )
V_216 = F_54 ( V_2 , V_4 , & V_99 , & V_143 ) ;
else
V_216 = F_58 ( V_2 , V_4 , & V_99 ,
& V_143 ) ;
V_217 = V_216 + sizeof( struct V_76 ) ;
V_4 -> V_223 = F_105 ( V_2 ) < F_90 ( 1 ) ;
F_106 ( V_4 , V_217 ) ;
F_107 ( V_4 ) ;
F_108 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_224 = F_109 ( V_4 ) ? V_225 : F_88 ;
F_110 ( V_4 , V_2 ) ;
F_111 ( V_4 -> V_205 , & V_2 -> V_206 ) ;
V_77 = (struct V_76 * ) V_4 -> V_183 ;
V_77 -> V_226 = V_213 -> V_227 ;
V_77 -> V_228 = V_213 -> V_229 ;
V_77 -> V_82 = F_52 ( V_215 -> V_82 ) ;
V_77 -> V_230 = F_52 ( V_8 -> V_60 ) ;
* ( ( ( V_231 * ) V_77 ) + 6 ) = F_112 ( ( ( V_217 >> 2 ) << 12 ) |
V_215 -> V_64 ) ;
V_77 -> V_232 = 0 ;
V_77 -> V_233 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_215 -> V_82 , V_8 -> V_96 ) ) ) {
if ( F_11 ( V_8 -> V_96 , V_215 -> V_82 + 0x10000 ) ) {
V_77 -> V_233 = F_112 ( V_8 -> V_96 - V_215 -> V_82 ) ;
V_77 -> V_234 = 1 ;
} else if ( F_113 ( V_215 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_233 = F_112 ( 0xFFFF ) ;
V_77 -> V_234 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_99 ) ;
F_45 ( V_4 ) -> V_85 = V_2 -> V_235 ;
if ( F_53 ( ! ( V_215 -> V_64 & V_93 ) ) ) {
V_77 -> V_236 = F_112 ( F_31 ( V_2 ) ) ;
F_44 ( V_2 , V_4 , V_77 , V_217 ) ;
} else {
V_77 -> V_236 = F_112 ( F_20 ( V_8 -> V_44 , 65535U ) ) ;
}
#ifdef F_55
if ( V_143 ) {
F_114 ( V_2 , V_237 ) ;
V_8 -> V_149 -> V_238 ( V_99 . V_105 ,
V_143 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_200 -> V_239 ( V_2 , V_4 ) ;
if ( F_53 ( V_215 -> V_64 & V_240 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_217 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_241 += F_6 ( V_4 ) ;
}
if ( F_113 ( V_215 -> V_12 , V_8 -> V_11 ) || V_215 -> V_82 == V_215 -> V_12 )
F_115 ( F_9 ( V_2 ) , V_242 ,
F_6 ( V_4 ) ) ;
V_8 -> V_243 += F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_244 = F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_245 = F_116 ( V_4 ) ;
V_4 -> V_246 . V_247 = 0 ;
memset ( V_4 -> V_248 , 0 , F_21 ( sizeof( struct V_249 ) ,
sizeof( struct V_250 ) ) ) ;
V_218 = V_6 -> V_200 -> V_251 ( V_2 , V_4 , & V_213 -> V_252 . V_253 ) ;
if ( F_53 ( V_218 <= 0 ) )
return V_218 ;
F_117 ( V_2 ) ;
return F_118 ( V_218 ) ;
}
static void F_119 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_254 = F_5 ( V_4 ) -> V_12 ;
F_120 ( V_4 ) ;
F_121 ( V_2 , V_4 ) ;
V_2 -> V_255 += V_4 -> V_205 ;
F_122 ( V_2 , V_4 -> V_205 ) ;
}
static void F_123 ( struct V_3 * V_4 , unsigned int V_256 )
{
if ( V_4 -> V_81 <= V_256 || V_4 -> V_89 == V_257 ) {
F_48 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_258 = 0 ;
} else {
F_48 ( V_4 , F_124 ( V_4 -> V_81 , V_256 ) ) ;
F_5 ( V_4 ) -> V_258 = V_256 ;
}
}
static void F_125 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_259 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_260 || F_126 ( V_8 ) )
return;
if ( F_113 ( F_127 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_261 -= V_259 ;
}
static void F_128 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_259 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_259 ;
if ( F_5 ( V_4 ) -> V_92 & V_262 )
V_8 -> V_260 -= V_259 ;
if ( F_5 ( V_4 ) -> V_92 & V_263 )
V_8 -> V_180 -= V_259 ;
if ( F_5 ( V_4 ) -> V_92 & V_264 )
V_8 -> V_179 -= V_259 ;
if ( F_126 ( V_8 ) && V_259 > 0 )
V_8 -> V_260 -= F_30 ( T_4 , V_8 -> V_260 , V_259 ) ;
F_125 ( V_2 , V_4 , V_259 ) ;
if ( V_8 -> V_265 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_265 ) -> V_82 ) &&
( F_129 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_262 ) ) )
V_8 -> V_266 -= V_259 ;
F_130 ( V_8 ) ;
}
static bool F_131 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_267 ||
( F_45 ( V_4 ) -> V_268 & V_269 ) ;
}
static void F_132 ( struct V_3 * V_4 , struct V_3 * V_270 )
{
struct V_271 * V_272 = F_45 ( V_4 ) ;
if ( F_51 ( F_131 ( V_4 ) ) &&
! F_11 ( V_272 -> V_273 , F_5 ( V_270 ) -> V_82 ) ) {
struct V_271 * V_274 = F_45 ( V_270 ) ;
T_7 V_275 = V_272 -> V_268 & V_269 ;
V_272 -> V_268 &= ~ V_275 ;
V_274 -> V_268 |= V_275 ;
F_133 ( V_272 -> V_273 , V_274 -> V_273 ) ;
F_5 ( V_270 ) -> V_267 = F_5 ( V_4 ) -> V_267 ;
F_5 ( V_4 ) -> V_267 = 0 ;
}
}
static void F_134 ( struct V_3 * V_4 , struct V_3 * V_270 )
{
F_5 ( V_270 ) -> V_276 = F_5 ( V_4 ) -> V_276 ;
F_5 ( V_4 ) -> V_276 = 0 ;
}
int F_135 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_256 , T_10 V_277 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_278 ;
int V_279 , V_280 ;
int V_281 ;
T_7 V_88 ;
if ( F_136 ( V_81 > V_4 -> V_81 ) )
return - V_282 ;
V_279 = F_137 ( V_4 ) - V_81 ;
if ( V_279 < 0 )
V_279 = 0 ;
if ( F_138 ( V_4 , V_277 ) )
return - V_283 ;
V_278 = F_139 ( V_2 , V_279 , V_277 , true ) ;
if ( ! V_278 )
return - V_283 ;
V_2 -> V_255 += V_278 -> V_205 ;
F_122 ( V_2 , V_278 -> V_205 ) ;
V_281 = V_4 -> V_81 - V_81 - V_279 ;
V_278 -> V_205 += V_281 ;
V_4 -> V_205 -= V_281 ;
F_5 ( V_278 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_278 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_278 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_284 ) ;
F_5 ( V_278 ) -> V_64 = V_88 ;
F_5 ( V_278 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
F_134 ( V_4 , V_278 ) ;
if ( ! F_45 ( V_4 ) -> V_285 && V_4 -> V_89 != V_90 ) {
V_278 -> V_91 = F_140 ( V_4 -> V_183 + V_81 ,
F_141 ( V_278 , V_279 ) ,
V_279 , 0 ) ;
F_142 ( V_4 , V_81 ) ;
V_4 -> V_91 = F_143 ( V_4 -> V_91 , V_278 -> V_91 , V_81 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_144 ( V_4 , V_278 , V_81 ) ;
}
V_278 -> V_89 = V_4 -> V_89 ;
V_278 -> V_246 = V_4 -> V_246 ;
F_132 ( V_4 , V_278 ) ;
V_280 = F_6 ( V_4 ) ;
F_123 ( V_4 , V_256 ) ;
F_123 ( V_278 , V_256 ) ;
F_5 ( V_278 ) -> V_220 = F_5 ( V_4 ) -> V_220 ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_278 ) -> V_12 ) ) {
int V_286 = V_280 - F_6 ( V_4 ) -
F_6 ( V_278 ) ;
if ( V_286 )
F_128 ( V_2 , V_4 , V_286 ) ;
}
F_120 ( V_278 ) ;
F_145 ( V_4 , V_278 , V_2 ) ;
return 0 ;
}
static void F_146 ( struct V_3 * V_4 , int V_81 )
{
struct V_271 * V_272 ;
int V_202 , V_287 , V_288 ;
V_288 = F_30 ( int , V_81 , F_137 ( V_4 ) ) ;
if ( V_288 ) {
F_147 ( V_4 , V_288 ) ;
V_81 -= V_288 ;
if ( ! V_81 )
return;
}
V_288 = V_81 ;
V_287 = 0 ;
V_272 = F_45 ( V_4 ) ;
for ( V_202 = 0 ; V_202 < V_272 -> V_285 ; V_202 ++ ) {
int V_169 = F_148 ( & V_272 -> V_289 [ V_202 ] ) ;
if ( V_169 <= V_288 ) {
F_149 ( V_4 , V_202 ) ;
V_288 -= V_169 ;
} else {
V_272 -> V_289 [ V_287 ] = V_272 -> V_289 [ V_202 ] ;
if ( V_288 ) {
V_272 -> V_289 [ V_287 ] . V_290 += V_288 ;
F_150 ( & V_272 -> V_289 [ V_287 ] , V_288 ) ;
V_288 = 0 ;
}
V_287 ++ ;
}
}
V_272 -> V_285 = V_287 ;
F_151 ( V_4 ) ;
V_4 -> V_291 -= V_81 ;
V_4 -> V_81 = V_4 -> V_291 ;
}
int F_152 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_138 ( V_4 , V_182 ) )
return - V_283 ;
F_146 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_205 -= V_81 ;
V_2 -> V_255 -= V_81 ;
F_153 ( V_2 , V_81 ) ;
F_154 ( V_2 , V_292 ) ;
if ( F_6 ( V_4 ) > 1 )
F_123 ( V_4 , F_116 ( V_4 ) ) ;
return 0 ;
}
static inline int F_155 ( struct V_1 * V_2 , int V_293 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_256 ;
V_256 = V_293 - V_6 -> V_200 -> V_294 - sizeof( struct V_76 ) ;
if ( V_6 -> V_200 -> V_295 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_156 ( V_18 ) )
V_256 -= V_6 -> V_200 -> V_295 ;
}
if ( V_256 > V_8 -> V_58 . V_296 )
V_256 = V_8 -> V_58 . V_296 ;
V_256 -= V_6 -> V_297 ;
if ( V_256 < 48 )
V_256 = 48 ;
return V_256 ;
}
int F_157 ( struct V_1 * V_2 , int V_293 )
{
return F_155 ( V_2 , V_293 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_158 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_298 ;
V_298 = V_19 +
V_8 -> V_80 +
V_6 -> V_297 +
V_6 -> V_200 -> V_294 ;
if ( V_6 -> V_200 -> V_295 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_156 ( V_18 ) )
V_298 += V_6 -> V_200 -> V_295 ;
}
return V_298 ;
}
void F_159 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
V_6 -> V_300 . V_301 = V_299 -> V_70 . V_302 > 1 ;
V_6 -> V_300 . V_303 = V_8 -> V_58 . V_296 + sizeof( struct V_76 ) +
V_6 -> V_200 -> V_294 ;
V_6 -> V_300 . V_304 = F_158 ( V_2 , V_299 -> V_70 . V_305 ) ;
V_6 -> V_300 . V_306 = 0 ;
if ( V_6 -> V_300 . V_301 )
V_6 -> V_300 . V_307 = V_30 ;
}
unsigned int F_160 ( struct V_1 * V_2 , T_4 V_293 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_256 ;
if ( V_6 -> V_300 . V_303 > V_293 )
V_6 -> V_300 . V_303 = V_293 ;
V_256 = F_157 ( V_2 , V_293 ) ;
V_256 = F_161 ( V_8 , V_256 ) ;
V_6 -> V_308 = V_293 ;
if ( V_6 -> V_300 . V_301 )
V_256 = F_20 ( V_256 , F_157 ( V_2 , V_6 -> V_300 . V_304 ) ) ;
V_8 -> V_309 = V_256 ;
return V_256 ;
}
unsigned int F_62 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_256 ;
unsigned int V_310 ;
struct V_98 V_99 ;
struct V_142 * V_143 ;
V_256 = V_8 -> V_309 ;
if ( V_18 ) {
T_4 V_298 = F_162 ( V_18 ) ;
if ( V_298 != F_2 ( V_2 ) -> V_308 )
V_256 = F_160 ( V_2 , V_298 ) ;
}
V_310 = F_58 ( V_2 , NULL , & V_99 , & V_143 ) +
sizeof( struct V_76 ) ;
if ( V_310 != V_8 -> V_80 ) {
int V_22 = ( int ) V_310 - V_8 -> V_80 ;
V_256 -= V_22 ;
}
return V_256 ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_311 == V_312 &&
V_2 -> V_313 && ! F_164 ( V_314 , & V_2 -> V_313 -> V_88 ) ) {
T_4 V_315 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_316 = F_21 ( V_8 -> V_31 , V_315 ) ;
if ( V_316 < V_8 -> V_25 ) {
V_8 -> V_27 = F_19 ( V_2 ) ;
V_8 -> V_25 = ( V_8 -> V_25 + V_316 ) >> 1 ;
}
V_8 -> V_31 = 0 ;
}
V_8 -> V_29 = V_30 ;
}
static void F_165 ( struct V_1 * V_2 , bool V_317 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_95 , V_8 -> V_318 ) ||
V_8 -> V_10 > V_8 -> V_319 ) {
V_8 -> V_319 = V_8 -> V_10 ;
V_8 -> V_318 = V_8 -> V_11 ;
V_8 -> V_317 = V_317 ;
}
if ( F_166 ( V_2 ) ) {
V_8 -> V_31 = 0 ;
V_8 -> V_29 = V_30 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_31 )
V_8 -> V_31 = V_8 -> V_10 ;
if ( V_320 &&
( T_3 ) ( V_30 - V_8 -> V_29 ) >= F_2 ( V_2 ) -> V_28 )
F_163 ( V_2 ) ;
}
}
static bool F_167 ( const struct V_7 * V_8 )
{
return F_113 ( V_8 -> V_321 , V_8 -> V_95 ) &&
! F_113 ( V_8 -> V_321 , V_8 -> V_11 ) ;
}
static void F_168 ( struct V_7 * V_8 , unsigned int V_256 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_256 )
V_8 -> V_321 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_169 ( bool V_322 , const struct V_7 * V_8 ,
int V_181 )
{
return V_322 &&
( ( V_181 & V_323 ) ||
( ! V_181 && V_8 -> V_10 && F_167 ( V_8 ) ) ) ;
}
T_4 F_170 ( const struct V_1 * V_2 , unsigned int V_256 ,
int V_324 )
{
T_4 V_325 , V_326 ;
V_325 = F_20 ( V_2 -> V_327 >> 10 ,
V_2 -> V_328 - 1 - V_329 ) ;
V_326 = F_29 ( T_4 , V_325 / V_256 , V_324 ) ;
return F_30 ( T_4 , V_326 , V_2 -> V_330 ) ;
}
static T_4 F_171 ( struct V_1 * V_2 , unsigned int V_256 )
{
const struct V_331 * V_332 = F_2 ( V_2 ) -> V_333 ;
T_4 V_334 = V_332 -> V_335 ? V_332 -> V_335 ( V_2 ) : 0 ;
return V_334 ? :
F_170 ( V_2 , V_256 , V_336 ) ;
}
static unsigned int F_172 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_256 ,
unsigned int V_337 ,
int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_322 , V_338 , V_236 , V_339 ;
V_236 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_339 = V_256 * V_337 ;
if ( F_53 ( V_339 <= V_236 && V_4 != F_173 ( V_2 ) ) )
return V_339 ;
V_338 = F_20 ( V_4 -> V_81 , V_236 ) ;
if ( V_339 <= V_338 )
return V_339 ;
V_322 = V_338 % V_256 ;
if ( F_169 ( V_322 != 0 , V_8 , V_181 ) )
return V_338 - V_322 ;
return V_338 ;
}
static inline unsigned int F_174 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_221 , V_24 , V_340 ;
if ( ( F_5 ( V_4 ) -> V_64 & V_94 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_221 = F_23 ( V_8 ) ;
V_24 = V_8 -> V_25 ;
if ( V_221 >= V_24 )
return 0 ;
V_340 = F_21 ( V_24 >> 1 , 1U ) ;
return F_20 ( V_340 , V_24 - V_221 ) ;
}
static int F_175 ( struct V_3 * V_4 , unsigned int V_256 )
{
int V_334 = F_6 ( V_4 ) ;
if ( ! V_334 || ( V_334 > 1 && F_116 ( V_4 ) != V_256 ) ) {
F_123 ( V_4 , V_256 ) ;
V_334 = F_6 ( V_4 ) ;
}
return V_334 ;
}
static inline bool F_176 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_341 , int V_181 )
{
if ( V_181 & V_342 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_64 & V_94 ) )
return true ;
if ( ! F_169 ( V_4 -> V_81 < V_341 , V_8 , V_181 ) )
return true ;
return false ;
}
static bool F_177 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_341 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_341 )
V_12 = F_5 ( V_4 ) -> V_82 + V_341 ;
return ! F_113 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_178 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_341 , int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_343 ;
F_175 ( V_4 , V_341 ) ;
if ( ! F_176 ( V_8 , V_4 , V_341 , V_181 ) )
return 0 ;
V_343 = F_174 ( V_8 , V_4 ) ;
if ( V_343 && ! F_177 ( V_8 , V_4 , V_341 ) )
V_343 = 0 ;
return V_343 ;
}
bool F_179 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_180 ( V_2 ) ;
return V_4 &&
F_178 ( V_2 , V_4 , F_62 ( V_2 ) ,
( F_181 ( V_2 , V_4 ) ?
V_8 -> V_181 : V_342 ) ) ;
}
static int F_182 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_256 , T_10 V_277 )
{
struct V_3 * V_278 ;
int V_281 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_291 )
return F_135 ( V_2 , V_4 , V_81 , V_256 , V_277 ) ;
V_278 = F_139 ( V_2 , 0 , V_277 , true ) ;
if ( F_51 ( ! V_278 ) )
return - V_283 ;
V_2 -> V_255 += V_278 -> V_205 ;
F_122 ( V_2 , V_278 -> V_205 ) ;
V_278 -> V_205 += V_281 ;
V_4 -> V_205 -= V_281 ;
F_5 ( V_278 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_278 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_278 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_284 ) ;
F_5 ( V_278 ) -> V_64 = V_88 ;
F_5 ( V_278 ) -> V_92 = 0 ;
F_134 ( V_4 , V_278 ) ;
V_278 -> V_89 = V_4 -> V_89 = V_90 ;
F_144 ( V_4 , V_278 , V_81 ) ;
F_132 ( V_4 , V_278 ) ;
F_123 ( V_4 , V_256 ) ;
F_123 ( V_278 , V_256 ) ;
F_120 ( V_278 ) ;
F_145 ( V_4 , V_278 , V_2 ) ;
return 0 ;
}
static bool F_183 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_317 , T_4 V_337 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_344 , V_345 , V_346 , V_347 , V_221 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_219 V_32 ;
struct V_3 * V_190 ;
int V_348 ;
if ( F_5 ( V_4 ) -> V_64 & V_94 )
goto V_349;
if ( V_6 -> V_311 >= V_350 )
goto V_349;
if ( ( T_3 ) ( V_30 - V_8 -> V_34 ) > 0 )
goto V_349;
V_221 = F_23 ( V_8 ) ;
F_98 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_25 <= V_221 ) ) ;
V_345 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_346 = ( V_8 -> V_25 - V_221 ) * V_8 -> V_309 ;
V_347 = F_20 ( V_345 , V_346 ) ;
if ( V_347 >= V_337 * V_8 -> V_309 )
goto V_349;
if ( ( V_4 != F_173 ( V_2 ) ) && ( V_347 >= V_4 -> V_81 ) )
goto V_349;
V_348 = F_184 ( V_351 ) ;
if ( V_348 ) {
T_4 V_352 = F_20 ( V_8 -> V_353 , V_8 -> V_25 * V_8 -> V_309 ) ;
V_352 /= V_348 ;
if ( V_347 >= V_352 )
goto V_349;
} else {
if ( V_347 > F_185 ( V_8 ) * V_8 -> V_309 )
goto V_349;
}
V_190 = F_186 ( V_2 ) ;
F_99 ( & V_32 ) ;
V_344 = F_187 ( & V_32 , & V_190 -> V_219 ) ;
if ( V_344 < ( V_8 -> V_354 >> 4 ) )
goto V_349;
if ( V_346 < V_345 && V_346 <= V_4 -> V_81 )
* V_317 = true ;
return true ;
V_349:
return false ;
}
static inline void F_188 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
T_4 V_355 ;
T_3 V_22 ;
V_355 = V_299 -> V_70 . V_356 ;
V_22 = V_30 - V_6 -> V_300 . V_307 ;
if ( F_51 ( V_22 >= V_355 * V_357 ) ) {
int V_19 = F_62 ( V_2 ) ;
V_6 -> V_300 . V_306 = 0 ;
V_6 -> V_300 . V_303 = V_8 -> V_58 . V_296 +
sizeof( struct V_76 ) +
V_6 -> V_200 -> V_294 ;
V_6 -> V_300 . V_304 = F_158 ( V_2 , V_19 ) ;
V_6 -> V_300 . V_307 = V_30 ;
}
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_358 , * V_359 ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
int V_81 ;
int V_306 ;
int V_360 ;
int V_361 ;
int V_256 ;
int V_355 ;
if ( ! V_6 -> V_300 . V_301 ||
V_6 -> V_300 . V_306 ||
F_2 ( V_2 ) -> V_311 != V_312 ||
V_8 -> V_25 < 11 ||
V_8 -> V_58 . V_171 || V_8 -> V_58 . V_123 )
return - 1 ;
V_256 = F_62 ( V_2 ) ;
V_306 = F_157 ( V_2 , ( V_6 -> V_300 . V_303 +
V_6 -> V_300 . V_304 ) >> 1 ) ;
V_360 = V_306 + ( V_8 -> V_362 + 1 ) * V_8 -> V_309 ;
V_355 = V_6 -> V_300 . V_303 - V_6 -> V_300 . V_304 ;
if ( V_306 > F_157 ( V_2 , V_6 -> V_300 . V_303 ) ||
V_355 < V_299 -> V_70 . V_363 ) {
F_188 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_254 - V_8 -> V_11 < V_360 )
return - 1 ;
if ( V_8 -> V_353 < V_360 )
return - 1 ;
if ( F_113 ( V_8 -> V_11 + V_360 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_25 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_358 = F_139 ( V_2 , V_306 , V_182 , false ) ;
if ( ! V_358 )
return - 1 ;
V_2 -> V_255 += V_358 -> V_205 ;
F_122 ( V_2 , V_358 -> V_205 ) ;
V_4 = F_180 ( V_2 ) ;
F_5 ( V_358 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_358 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_306 ;
F_5 ( V_358 ) -> V_64 = V_240 ;
F_5 ( V_358 ) -> V_92 = 0 ;
V_358 -> V_91 = 0 ;
V_358 -> V_89 = V_4 -> V_89 ;
F_190 ( V_358 , V_4 , V_2 ) ;
V_81 = 0 ;
F_191 (skb, next, sk) {
V_361 = F_30 ( int , V_4 -> V_81 , V_306 - V_81 ) ;
if ( V_358 -> V_89 ) {
F_192 ( V_4 , 0 , F_141 ( V_358 , V_361 ) , V_361 ) ;
} else {
T_11 V_91 = F_193 ( V_4 , 0 ,
F_141 ( V_358 , V_361 ) ,
V_361 , 0 ) ;
V_358 -> V_91 = F_194 ( V_358 -> V_91 , V_91 , V_81 ) ;
}
if ( V_4 -> V_81 <= V_361 ) {
F_5 ( V_358 ) -> V_64 |= F_5 ( V_4 ) -> V_64 ;
F_195 ( V_4 , V_2 ) ;
F_196 ( V_2 , V_4 ) ;
} else {
F_5 ( V_358 ) -> V_64 |= F_5 ( V_4 ) -> V_64 &
~ ( V_94 | V_284 ) ;
if ( ! F_45 ( V_4 ) -> V_285 ) {
F_197 ( V_4 , V_361 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_198 ( V_4 -> V_183 ,
V_4 -> V_81 , 0 ) ;
} else {
F_146 ( V_4 , V_361 ) ;
F_123 ( V_4 , V_256 ) ;
}
F_5 ( V_4 ) -> V_82 += V_361 ;
}
V_81 += V_361 ;
if ( V_81 >= V_306 )
break;
}
F_175 ( V_358 , V_358 -> V_81 ) ;
if ( ! F_97 ( V_2 , V_358 , 1 , V_182 ) ) {
V_8 -> V_25 -- ;
F_1 ( V_2 , V_358 ) ;
V_6 -> V_300 . V_306 = F_158 ( V_2 , V_358 -> V_81 ) ;
V_8 -> V_364 . V_365 = F_5 ( V_358 ) -> V_82 ;
V_8 -> V_364 . V_366 = F_5 ( V_358 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_199 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_367 )
{
unsigned int V_347 ;
V_347 = F_21 ( 2 * V_4 -> V_205 , V_2 -> V_327 >> 10 ) ;
V_347 = F_30 ( T_4 , V_347 , V_368 ) ;
V_347 <<= V_367 ;
if ( F_200 ( & V_2 -> V_206 ) > V_347 ) {
F_73 ( V_209 , & F_3 ( V_2 ) -> V_193 ) ;
F_201 () ;
if ( F_200 ( & V_2 -> V_206 ) > V_347 )
return true ;
}
return false ;
}
static bool F_61 ( struct V_1 * V_2 , unsigned int V_256 , int V_181 ,
int V_369 , T_10 V_277 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_334 , V_370 ;
int V_343 ;
int V_371 ;
bool V_317 = false ;
T_4 V_337 ;
V_370 = 0 ;
if ( ! V_369 ) {
V_371 = F_189 ( V_2 ) ;
if ( ! V_371 ) {
return false ;
} else if ( V_371 > 0 ) {
V_370 = 1 ;
}
}
V_337 = F_171 ( V_2 , V_256 ) ;
while ( ( V_4 = F_180 ( V_2 ) ) ) {
unsigned int V_347 ;
V_334 = F_175 ( V_4 , V_256 ) ;
F_98 ( ! V_334 ) ;
if ( F_51 ( V_8 -> V_372 ) && V_8 -> V_373 == V_374 ) {
F_99 ( & V_4 -> V_219 ) ;
goto V_372;
}
V_343 = F_174 ( V_8 , V_4 ) ;
if ( ! V_343 ) {
if ( V_369 == 2 )
V_343 = 1 ;
else
break;
}
if ( F_51 ( ! F_177 ( V_8 , V_4 , V_256 ) ) )
break;
if ( V_334 == 1 ) {
if ( F_51 ( ! F_176 ( V_8 , V_4 , V_256 ,
( F_181 ( V_2 , V_4 ) ?
V_181 : V_342 ) ) ) )
break;
} else {
if ( ! V_369 &&
F_183 ( V_2 , V_4 , & V_317 ,
V_337 ) )
break;
}
V_347 = V_256 ;
if ( V_334 > 1 && ! F_49 ( V_8 ) )
V_347 = F_172 ( V_2 , V_4 , V_256 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_181 ) ;
if ( V_4 -> V_81 > V_347 &&
F_51 ( F_182 ( V_2 , V_4 , V_347 , V_256 , V_277 ) ) )
break;
if ( F_199 ( V_2 , V_4 , 0 ) )
break;
if ( F_51 ( F_97 ( V_2 , V_4 , 1 , V_277 ) ) )
break;
V_372:
F_1 ( V_2 , V_4 ) ;
F_168 ( V_8 , V_256 , V_4 ) ;
V_370 += F_6 ( V_4 ) ;
if ( V_369 )
break;
}
if ( F_53 ( V_370 ) ) {
if ( F_202 ( V_2 ) )
V_8 -> V_375 += V_370 ;
if ( V_369 != 2 )
F_203 ( V_2 ) ;
V_317 |= ( F_23 ( V_8 ) >= V_8 -> V_25 ) ;
F_165 ( V_2 , V_317 ) ;
return false ;
}
return ! V_8 -> V_10 && F_180 ( V_2 ) ;
}
bool F_203 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_376 , V_377 , V_378 ;
T_4 V_379 = F_204 ( V_8 -> V_354 >> 3 ) ;
if ( F_136 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_136 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_8 -> V_380 )
return false ;
if ( V_6 -> V_13 != V_381 )
return false ;
if ( V_382 < 3 || ! V_8 -> V_10 ||
! F_205 ( V_8 ) || F_2 ( V_2 ) -> V_311 != V_312 )
return false ;
if ( ( V_8 -> V_25 > F_23 ( V_8 ) ) &&
F_180 ( V_2 ) )
return false ;
V_376 = V_379 << 1 ? : V_383 ;
if ( V_8 -> V_10 == 1 )
V_376 = F_29 ( T_4 , V_376 ,
( V_379 + ( V_379 >> 1 ) + V_384 ) ) ;
V_376 = F_29 ( T_4 , V_376 , F_206 ( 10 ) ) ;
V_377 = V_30 + V_376 ;
V_378 = ( T_4 ) F_2 ( V_2 ) -> V_385 ;
if ( ( T_3 ) ( V_377 - V_378 ) > 0 ) {
T_3 V_22 = V_378 - V_30 ;
if ( V_22 > 0 )
V_376 = V_22 ;
}
F_207 ( V_2 , V_15 , V_376 ,
V_386 ) ;
return true ;
}
static bool F_208 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_209 ( V_2 , V_4 ) ) ) {
F_34 ( F_9 ( V_2 ) ,
V_387 ) ;
return true ;
}
return false ;
}
void F_210 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_388 ;
int V_19 = F_62 ( V_2 ) ;
V_4 = F_180 ( V_2 ) ;
if ( V_4 ) {
if ( F_177 ( V_8 , V_4 , V_19 ) ) {
V_388 = V_8 -> V_10 ;
F_61 ( V_2 , V_19 , V_389 , 2 , V_182 ) ;
if ( V_8 -> V_10 > V_388 )
goto V_390;
goto V_391;
}
V_4 = F_211 ( V_2 , V_4 ) ;
} else {
V_4 = F_173 ( V_2 ) ;
}
if ( V_8 -> V_392 )
goto V_391;
if ( F_136 ( ! V_4 ) )
goto V_391;
if ( F_208 ( V_2 , V_4 ) )
goto V_391;
V_388 = F_6 ( V_4 ) ;
if ( F_136 ( ! V_388 ) )
goto V_391;
if ( ( V_388 > 1 ) && ( V_4 -> V_81 > ( V_388 - 1 ) * V_19 ) ) {
if ( F_51 ( F_135 ( V_2 , V_4 , ( V_388 - 1 ) * V_19 , V_19 ,
V_182 ) ) )
goto V_391;
V_4 = F_212 ( V_2 , V_4 ) ;
}
if ( F_136 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_391;
if ( F_213 ( V_2 , V_4 , 1 ) )
goto V_391;
V_8 -> V_392 = V_8 -> V_11 ;
V_390:
F_34 ( F_9 ( V_2 ) , V_393 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_391:
F_7 ( V_2 ) ;
}
void F_214 ( struct V_1 * V_2 , unsigned int V_341 ,
int V_181 )
{
if ( F_51 ( V_2 -> V_173 == V_394 ) )
return;
if ( F_61 ( V_2 , V_341 , V_181 , 0 ,
F_215 ( V_2 , V_182 ) ) )
F_216 ( V_2 ) ;
}
void F_217 ( struct V_1 * V_2 , unsigned int V_256 )
{
struct V_3 * V_4 = F_180 ( V_2 ) ;
F_98 ( ! V_4 || V_4 -> V_81 < V_256 ) ;
F_61 ( V_2 , V_256 , V_342 , 1 , V_2 -> V_395 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_396 ;
int V_397 = F_218 ( V_2 ) ;
int V_398 = F_219 ( V_2 ) ;
int V_399 = F_30 ( int , V_8 -> V_45 , V_398 ) ;
int V_236 ;
if ( V_19 > V_399 )
V_19 = V_399 ;
if ( V_397 < ( V_399 >> 1 ) ) {
V_6 -> V_35 . V_400 = 0 ;
if ( F_220 ( V_2 ) )
V_8 -> V_401 = F_20 ( V_8 -> V_401 ,
4U * V_8 -> V_20 ) ;
V_397 = F_221 ( V_397 , 1 << V_8 -> V_58 . V_47 ) ;
if ( V_397 < ( V_398 >> 4 ) || V_397 < V_19 )
return 0 ;
}
if ( V_397 > V_8 -> V_401 )
V_397 = V_8 -> V_401 ;
V_236 = V_8 -> V_44 ;
if ( V_8 -> V_58 . V_47 ) {
V_236 = V_397 ;
if ( ( ( V_236 >> V_8 -> V_58 . V_47 ) << V_8 -> V_58 . V_47 ) != V_236 )
V_236 = ( ( ( V_236 >> V_8 -> V_58 . V_47 ) + 1 )
<< V_8 -> V_58 . V_47 ) ;
} else {
if ( V_236 <= V_397 - V_19 || V_236 > V_397 )
V_236 = ( V_397 / V_19 ) * V_19 ;
else if ( V_19 == V_399 &&
V_397 > V_236 + ( V_399 >> 1 ) )
V_236 = V_397 ;
}
return V_236 ;
}
void F_222 ( struct V_3 * V_4 ,
const struct V_3 * V_402 )
{
if ( F_51 ( F_131 ( V_402 ) ) ) {
const struct V_271 * V_403 =
F_45 ( V_402 ) ;
struct V_271 * V_272 = F_45 ( V_4 ) ;
V_272 -> V_268 |= V_403 -> V_268 & V_269 ;
V_272 -> V_273 = V_403 -> V_273 ;
F_5 ( V_4 ) -> V_267 |=
F_5 ( V_402 ) -> V_267 ;
}
}
static void F_223 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_402 = F_212 ( V_2 , V_4 ) ;
int V_404 , V_405 ;
V_404 = V_4 -> V_81 ;
V_405 = V_402 -> V_81 ;
F_98 ( F_6 ( V_4 ) != 1 || F_6 ( V_402 ) != 1 ) ;
F_224 ( V_2 , V_402 , V_4 ) ;
F_195 ( V_402 , V_2 ) ;
F_225 ( V_402 , F_141 ( V_4 , V_405 ) ,
V_405 ) ;
if ( V_402 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_194 ( V_4 -> V_91 , V_402 -> V_91 , V_404 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_402 ) -> V_12 ;
F_5 ( V_4 ) -> V_64 |= F_5 ( V_402 ) -> V_64 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_402 ) -> V_92 & V_406 ;
F_5 ( V_4 ) -> V_276 = F_5 ( V_402 ) -> V_276 ;
F_226 ( V_8 ) ;
if ( V_402 == V_8 -> V_407 )
V_8 -> V_407 = V_4 ;
F_128 ( V_2 , V_402 , F_6 ( V_402 ) ) ;
F_222 ( V_4 , V_402 ) ;
F_196 ( V_2 , V_402 ) ;
}
static bool F_227 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_45 ( V_4 ) -> V_285 != 0 )
return false ;
if ( F_101 ( V_4 ) )
return false ;
if ( V_4 == F_180 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_262 )
return false ;
return true ;
}
static void F_228 ( struct V_1 * V_2 , struct V_3 * V_408 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_408 , * V_409 ;
bool V_410 = true ;
if ( ! V_411 )
return;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
return;
F_191 (skb, tmp, sk) {
if ( ! F_227 ( V_2 , V_4 ) )
break;
if ( ! F_229 ( V_408 ) )
break;
V_49 -= V_4 -> V_81 ;
if ( V_410 ) {
V_410 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_81 > F_230 ( V_408 ) )
break;
if ( F_113 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_223 ( V_2 , V_408 ) ;
}
}
int F_213 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_326 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_341 ;
int V_286 , V_81 , V_218 ;
if ( V_6 -> V_300 . V_306 )
V_6 -> V_300 . V_306 = 0 ;
if ( F_200 ( & V_2 -> V_206 ) >
F_30 ( T_4 , V_2 -> V_255 + ( V_2 -> V_255 >> 2 ) ,
V_2 -> V_412 ) )
return - V_413 ;
if ( F_208 ( V_2 , V_4 ) )
return - V_414 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_95 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_95 ) )
F_231 () ;
if ( F_152 ( V_2 , V_4 , V_8 -> V_95 - F_5 ( V_4 ) -> V_82 ) )
return - V_283 ;
}
if ( F_2 ( V_2 ) -> V_200 -> V_415 ( V_2 ) )
return - V_416 ;
V_341 = F_62 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_95 )
return - V_413 ;
V_81 = V_341 * V_326 ;
if ( V_4 -> V_81 > V_81 ) {
if ( F_135 ( V_2 , V_4 , V_81 , V_341 , V_182 ) )
return - V_283 ;
} else {
if ( F_138 ( V_4 , V_182 ) )
return - V_283 ;
V_286 = F_6 ( V_4 ) ;
F_123 ( V_4 , V_341 ) ;
V_286 -= F_6 ( V_4 ) ;
if ( V_286 )
F_128 ( V_2 , V_4 , V_286 ) ;
if ( V_4 -> V_81 < V_341 )
F_228 ( V_2 , V_4 , V_341 ) ;
}
if ( ( F_5 ( V_4 ) -> V_64 & V_417 ) == V_417 )
F_41 ( V_2 , V_4 ) ;
if ( F_51 ( ( V_418 && ( ( unsigned long ) V_4 -> V_183 & 3 ) ) ||
F_232 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_358 ;
F_99 ( & V_4 -> V_219 ) ;
V_358 = F_233 ( V_4 , V_329 , V_182 ) ;
V_218 = V_358 ? F_97 ( V_2 , V_358 , 0 , V_182 ) :
- V_222 ;
} else {
V_218 = F_97 ( V_2 , V_4 , 1 , V_182 ) ;
}
if ( F_53 ( ! V_218 ) ) {
V_326 = F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_92 |= V_406 ;
F_115 ( F_9 ( V_2 ) , V_419 , V_326 ) ;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
F_234 ( F_9 ( V_2 ) , V_420 ) ;
V_8 -> V_421 += V_326 ;
}
return V_218 ;
}
int F_235 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_326 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_218 = F_213 ( V_2 , V_4 , V_326 ) ;
if ( V_218 == 0 ) {
#if V_422 > 0
if ( F_5 ( V_4 ) -> V_92 & V_263 ) {
F_236 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_92 |= V_423 ;
V_8 -> V_180 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_424 )
V_8 -> V_424 = F_56 ( V_4 ) ;
} else if ( V_218 != - V_414 ) {
F_34 ( F_9 ( V_2 ) , V_425 ) ;
}
if ( V_8 -> V_426 < 0 )
V_8 -> V_426 = 0 ;
V_8 -> V_426 += F_6 ( V_4 ) ;
return V_218 ;
}
static bool F_237 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_311 != V_350 )
return false ;
if ( F_126 ( V_8 ) )
return false ;
if ( F_179 ( V_2 ) )
return false ;
return true ;
}
void F_60 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_427 = NULL ;
T_4 V_337 , V_428 ;
int V_429 ;
int V_430 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_179 )
V_8 -> V_431 = V_8 -> V_95 ;
if ( V_8 -> V_407 ) {
V_4 = V_8 -> V_407 ;
V_428 = F_5 ( V_4 ) -> V_12 ;
if ( F_113 ( V_428 , V_8 -> V_431 ) )
V_428 = V_8 -> V_431 ;
} else {
V_4 = F_186 ( V_2 ) ;
V_428 = V_8 -> V_95 ;
}
V_337 = F_171 ( V_2 , F_62 ( V_2 ) ) ;
F_238 (skb, sk) {
T_5 V_92 ;
int V_326 ;
if ( V_4 == F_180 ( V_2 ) )
break;
if ( ! V_427 )
V_8 -> V_407 = V_4 ;
V_326 = V_8 -> V_25 - F_23 ( V_8 ) ;
if ( V_326 <= 0 )
return;
V_92 = F_5 ( V_4 ) -> V_92 ;
V_326 = F_30 ( int , V_326 , V_337 ) ;
if ( V_430 ) {
V_432:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_127 ( V_8 ) ) )
break;
V_429 = V_433 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_431 ) ) {
V_8 -> V_431 = V_428 ;
if ( ! F_237 ( V_2 ) )
break;
if ( V_427 ) {
V_4 = V_427 ;
V_427 = NULL ;
}
V_430 = 1 ;
goto V_432;
} else if ( ! ( V_92 & V_264 ) ) {
if ( ! V_427 && ! ( V_92 & ( V_263 | V_262 ) ) )
V_427 = V_4 ;
continue;
} else {
V_428 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_311 != V_434 )
V_429 = V_435 ;
else
V_429 = V_436 ;
}
if ( V_92 & ( V_262 | V_263 ) )
continue;
if ( F_199 ( V_2 , V_4 , 1 ) )
return;
if ( F_235 ( V_2 , V_4 , V_326 ) )
return;
F_8 ( F_9 ( V_2 ) , V_429 , F_6 ( V_4 ) ) ;
if ( F_202 ( V_2 ) )
V_8 -> V_375 += F_6 ( V_4 ) ;
if ( V_4 == F_186 ( V_2 ) )
F_207 ( V_2 , V_381 ,
F_2 ( V_2 ) -> V_28 ,
V_386 ) ;
}
}
void F_239 ( struct V_1 * V_2 , int V_169 )
{
int V_437 ;
if ( V_169 <= V_2 -> V_438 )
return;
V_437 = F_240 ( V_169 ) ;
V_2 -> V_438 += V_437 * V_439 ;
F_241 ( V_2 , V_437 ) ;
if ( V_440 && V_2 -> V_441 )
F_242 ( V_2 -> V_441 , V_437 ) ;
}
void F_243 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_442 = F_173 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_442 && ( F_180 ( V_2 ) || F_220 ( V_2 ) ) ) {
V_443:
F_5 ( V_442 ) -> V_64 |= V_94 ;
F_5 ( V_442 ) -> V_12 ++ ;
V_8 -> V_254 ++ ;
if ( ! F_180 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_244 ( V_329 , V_2 -> V_395 ) ;
if ( F_51 ( ! V_4 ) ) {
if ( V_442 )
goto V_443;
return;
}
F_245 ( V_4 , V_329 ) ;
F_239 ( V_2 , V_4 -> V_205 ) ;
F_47 ( V_4 , V_8 -> V_254 ,
V_240 | V_94 ) ;
F_119 ( V_2 , V_4 ) ;
}
F_214 ( V_2 , F_62 ( V_2 ) , V_389 ) ;
}
void F_246 ( struct V_1 * V_2 , T_10 V_444 )
{
struct V_3 * V_4 ;
V_4 = F_247 ( V_329 , V_444 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_445 ) ;
return;
}
F_245 ( V_4 , V_329 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_240 | V_446 ) ;
F_99 ( & V_4 -> V_219 ) ;
if ( F_97 ( V_2 , V_4 , 0 , V_444 ) )
F_34 ( F_9 ( V_2 ) , V_445 ) ;
F_248 ( F_9 ( V_2 ) , V_447 ) ;
}
int F_249 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_186 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_64 & V_93 ) ) {
F_250 ( L_2 , V_448 ) ;
return - V_449 ;
}
if ( ! ( F_5 ( V_4 ) -> V_64 & V_240 ) ) {
if ( F_101 ( V_4 ) ) {
struct V_3 * V_358 = F_251 ( V_4 , V_182 ) ;
if ( ! V_358 )
return - V_283 ;
F_195 ( V_4 , V_2 ) ;
F_120 ( V_358 ) ;
F_252 ( V_2 , V_358 ) ;
F_196 ( V_2 , V_4 ) ;
V_2 -> V_255 += V_358 -> V_205 ;
F_122 ( V_2 , V_358 -> V_205 ) ;
V_4 = V_358 ;
}
F_5 ( V_4 ) -> V_64 |= V_240 ;
F_36 ( V_2 , V_4 ) ;
}
return F_97 ( V_2 , V_4 , 1 , V_182 ) ;
}
struct V_3 * F_253 ( const struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_132 * V_133 ,
enum V_450 V_451 )
{
struct V_165 * V_166 = F_43 ( V_75 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_142 * V_143 = NULL ;
struct V_98 V_99 ;
struct V_3 * V_4 ;
int V_217 ;
struct V_76 * V_77 ;
T_6 V_452 ;
int V_19 ;
V_4 = F_247 ( V_329 , V_182 ) ;
if ( F_51 ( ! V_4 ) ) {
F_254 ( V_18 ) ;
return NULL ;
}
F_245 ( V_4 , V_329 ) ;
switch ( V_451 ) {
case V_453 :
F_255 ( V_4 , F_256 ( V_75 ) ) ;
break;
case V_454 :
break;
case V_455 :
F_255 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_257 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
V_452 = F_258 ( V_8 -> V_58 . V_452 ) ;
if ( V_452 && V_452 < V_19 )
V_19 = V_452 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
#ifdef F_259
if ( F_51 ( V_75 -> V_456 ) )
V_4 -> V_219 . V_457 = F_260 ( V_75 ) ;
else
#endif
F_99 ( & V_4 -> V_219 ) ;
#ifdef F_55
F_261 () ;
V_143 = F_262 ( V_75 ) -> V_149 -> V_458 ( V_2 , F_256 ( V_75 ) ) ;
#endif
F_263 ( V_4 , F_262 ( V_75 ) -> V_459 , V_460 ) ;
V_217 = F_57 ( V_75 , V_19 , V_4 , & V_99 , V_143 , V_133 ) +
sizeof( * V_77 ) ;
F_106 ( V_4 , V_217 ) ;
F_107 ( V_4 ) ;
V_77 = (struct V_76 * ) V_4 -> V_183 ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_461 = 1 ;
V_77 -> V_462 = 1 ;
F_42 ( V_75 , V_77 ) ;
V_77 -> V_226 = F_112 ( V_166 -> V_463 ) ;
V_77 -> V_228 = V_166 -> V_464 ;
F_47 ( V_4 , F_262 ( V_75 ) -> V_465 ,
V_93 | V_240 ) ;
V_77 -> V_82 = F_52 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_230 = F_52 ( F_262 ( V_75 ) -> V_60 ) ;
V_77 -> V_236 = F_112 ( F_20 ( V_75 -> V_466 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_77 + 1 ) , NULL , & V_99 ) ;
V_77 -> V_467 = ( V_217 >> 2 ) ;
F_264 ( F_9 ( V_2 ) , V_242 ) ;
#ifdef F_55
if ( V_143 )
F_262 ( V_75 ) -> V_149 -> V_238 ( V_99 . V_105 ,
V_143 , F_256 ( V_75 ) , V_4 ) ;
F_265 () ;
#endif
V_4 -> V_246 . V_247 = 0 ;
return V_4 ;
}
static void F_266 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_331 * V_468 ;
T_4 V_469 = F_267 ( V_18 , V_470 ) ;
if ( V_469 == V_471 )
return;
F_261 () ;
V_468 = F_268 ( V_469 ) ;
if ( F_53 ( V_468 && F_269 ( V_468 -> V_472 ) ) ) {
F_270 ( V_6 -> V_333 -> V_472 ) ;
V_6 -> V_473 = F_271 ( V_18 ) ;
V_6 -> V_333 = V_468 ;
}
F_265 () ;
}
static void F_272 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_47 ;
V_8 -> V_80 = sizeof( struct V_76 ) +
( V_153 ? V_156 : 0 ) ;
#ifdef F_55
if ( V_8 -> V_149 -> V_150 ( V_2 , V_2 ) )
V_8 -> V_80 += V_151 ;
#endif
if ( V_8 -> V_58 . V_452 )
V_8 -> V_58 . V_296 = V_8 -> V_58 . V_452 ;
V_8 -> V_474 = 0 ;
F_159 ( V_2 ) ;
F_160 ( V_2 , F_162 ( V_18 ) ) ;
F_266 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_267 ( V_18 , V_475 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_58 . V_452 && V_8 -> V_58 . V_452 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_58 . V_452 ;
F_273 ( V_2 ) ;
if ( V_2 -> V_476 & V_477 &&
( V_8 -> V_45 > F_219 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_219 ( V_2 ) ;
F_28 ( F_219 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_58 . V_478 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_157 ,
& V_47 ,
F_267 ( V_18 , V_479 ) ) ;
V_8 -> V_58 . V_47 = V_47 ;
V_8 -> V_401 = V_8 -> V_44 ;
V_2 -> V_480 = 0 ;
F_274 ( V_2 , V_481 ) ;
V_8 -> V_353 = 0 ;
F_275 ( V_8 , 0 ) ;
V_8 -> V_95 = V_8 -> V_254 ;
V_8 -> V_321 = V_8 -> V_254 ;
V_8 -> V_96 = V_8 -> V_254 ;
V_8 -> V_11 = V_8 -> V_254 ;
if ( F_53 ( ! V_8 -> V_372 ) )
V_8 -> V_60 = 0 ;
else
V_8 -> V_482 = V_30 ;
V_8 -> V_59 = V_8 -> V_60 ;
V_8 -> V_483 = V_8 -> V_60 ;
F_2 ( V_2 ) -> V_28 = V_383 ;
F_2 ( V_2 ) -> V_484 = 0 ;
F_276 ( V_8 ) ;
}
static void F_277 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_214 * V_215 = F_5 ( V_4 ) ;
V_215 -> V_12 += V_4 -> V_81 ;
F_120 ( V_4 ) ;
F_278 ( V_2 , V_4 ) ;
V_2 -> V_255 += V_4 -> V_205 ;
F_122 ( V_2 , V_4 -> V_205 ) ;
V_8 -> V_254 = V_215 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_279 ( struct V_1 * V_2 , struct V_3 * V_461 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_485 = V_8 -> V_148 ;
int V_486 = 0 , V_49 , V_218 = 0 ;
unsigned long V_487 = 0 ;
struct V_3 * V_488 ;
V_8 -> V_58 . V_296 = V_8 -> V_20 ;
F_280 ( V_2 , & V_8 -> V_58 . V_296 , & V_485 -> V_161 ,
& V_486 , & V_487 ) ;
if ( V_486 > 1 &&
F_281 ( V_489 , V_487 + ( 60 * V_357 << V_486 ) ) ) {
V_485 -> V_161 . V_81 = - 1 ;
goto V_490;
}
if ( V_491 & V_492 )
V_485 -> V_161 . V_81 = - 1 ;
else if ( V_485 -> V_161 . V_81 <= 0 )
goto V_490;
if ( V_8 -> V_58 . V_452 && V_8 -> V_58 . V_452 < V_8 -> V_58 . V_296 )
V_8 -> V_58 . V_296 = V_8 -> V_58 . V_452 ;
V_49 = F_155 ( V_2 , F_2 ( V_2 ) -> V_308 ) -
V_145 ;
V_49 = F_30 ( V_493 , V_49 , V_485 -> V_169 ) ;
V_49 = F_30 ( V_493 , V_49 , F_282 ( V_329 ) ) ;
V_488 = F_139 ( V_2 , V_49 , V_2 -> V_395 , false ) ;
if ( ! V_488 )
goto V_490;
V_488 -> V_89 = V_90 ;
memcpy ( V_488 -> V_248 , V_461 -> V_248 , sizeof( V_461 -> V_248 ) ) ;
if ( V_49 ) {
int V_494 = F_283 ( F_141 ( V_488 , V_49 ) , V_49 ,
& V_485 -> V_183 -> V_495 ) ;
if ( F_51 ( ! V_494 ) ) {
F_284 ( V_488 ) ;
goto V_490;
}
if ( V_494 != V_49 ) {
F_142 ( V_488 , V_494 ) ;
V_49 = V_494 ;
}
}
if ( V_49 == V_485 -> V_169 )
V_485 -> V_183 = NULL ;
V_485 -> V_494 = V_49 ;
F_277 ( V_2 , V_488 ) ;
V_218 = F_97 ( V_2 , V_488 , 1 , V_2 -> V_395 ) ;
V_461 -> V_219 = V_488 -> V_219 ;
F_5 ( V_488 ) -> V_82 ++ ;
F_5 ( V_488 ) -> V_64 = V_240 | V_284 ;
if ( ! V_218 ) {
V_8 -> V_488 = ( V_485 -> V_494 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_496;
}
V_490:
if ( V_485 -> V_161 . V_81 > 0 )
V_485 -> V_161 . V_81 = 0 ;
V_218 = F_97 ( V_2 , V_461 , 1 , V_2 -> V_395 ) ;
if ( V_218 )
V_8 -> V_163 = 0 ;
V_496:
V_485 -> V_161 . V_81 = - 1 ;
return V_218 ;
}
int F_285 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_278 ;
int V_218 ;
F_272 ( V_2 ) ;
if ( F_51 ( V_8 -> V_372 ) ) {
F_286 ( V_2 , NULL ) ;
return 0 ;
}
V_278 = F_139 ( V_2 , 0 , V_2 -> V_395 , true ) ;
if ( F_51 ( ! V_278 ) )
return - V_222 ;
F_47 ( V_278 , V_8 -> V_254 ++ , V_93 ) ;
V_8 -> V_424 = V_30 ;
F_277 ( V_2 , V_278 ) ;
F_39 ( V_2 , V_278 ) ;
V_218 = V_8 -> V_148 ? F_279 ( V_2 , V_278 ) :
F_97 ( V_2 , V_278 , 1 , V_2 -> V_395 ) ;
if ( V_218 == - V_497 )
return V_218 ;
V_8 -> V_11 = V_8 -> V_254 ;
V_8 -> V_498 = V_8 -> V_254 ;
F_248 ( F_9 ( V_2 ) , V_499 ) ;
F_207 ( V_2 , V_381 ,
F_2 ( V_2 ) -> V_28 , V_386 ) ;
return 0 ;
}
void F_287 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_376 ;
F_18 ( V_2 , V_500 ) ;
if ( V_37 > V_501 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_502 = V_357 / 2 ;
if ( V_6 -> V_35 . V_38 ||
( V_6 -> V_35 . V_503 & V_504 ) )
V_502 = V_384 ;
if ( V_8 -> V_354 ) {
int V_379 = F_29 ( int , F_204 ( V_8 -> V_354 >> 3 ) ,
V_501 ) ;
if ( V_379 < V_502 )
V_502 = V_379 ;
}
V_37 = F_20 ( V_37 , V_502 ) ;
}
V_376 = V_489 + V_37 ;
if ( V_6 -> V_35 . V_503 & V_505 ) {
if ( V_6 -> V_35 . V_506 ||
F_288 ( V_6 -> V_35 . V_376 , V_489 + ( V_37 >> 2 ) ) ) {
F_289 ( V_2 ) ;
return;
}
if ( ! F_281 ( V_376 , V_6 -> V_35 . V_376 ) )
V_376 = V_6 -> V_35 . V_376 ;
}
V_6 -> V_35 . V_503 |= V_507 | V_505 ;
V_6 -> V_35 . V_376 = V_376 ;
F_290 ( V_2 , & V_6 -> V_508 , V_376 ) ;
}
void F_289 ( struct V_1 * V_2 )
{
struct V_3 * V_278 ;
if ( V_2 -> V_173 == V_394 )
return;
F_18 ( V_2 , V_509 ) ;
V_278 = F_247 ( V_329 ,
F_215 ( V_2 , V_182 | V_510 ) ) ;
if ( F_51 ( ! V_278 ) ) {
F_291 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_511 ;
F_207 ( V_2 , V_40 ,
V_384 , V_386 ) ;
return;
}
F_245 ( V_278 , V_329 ) ;
F_47 ( V_278 , F_10 ( V_2 ) , V_240 ) ;
F_292 ( V_278 ) ;
F_99 ( & V_278 -> V_219 ) ;
F_97 ( V_2 , V_278 , 0 , ( V_512 T_10 ) 0 ) ;
}
static int F_293 ( struct V_1 * V_2 , int V_513 , int V_514 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_247 ( V_329 ,
F_215 ( V_2 , V_182 | V_510 ) ) ;
if ( ! V_4 )
return - 1 ;
F_245 ( V_4 , V_329 ) ;
F_47 ( V_4 , V_8 -> V_95 - ! V_513 , V_240 ) ;
F_99 ( & V_4 -> V_219 ) ;
F_34 ( F_9 ( V_2 ) , V_514 ) ;
return F_97 ( V_2 , V_4 , 0 , ( V_512 T_10 ) 0 ) ;
}
void F_294 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_515 ) {
F_3 ( V_2 ) -> V_516 = F_3 ( V_2 ) -> V_60 - 1 ;
F_293 ( V_2 , 0 , V_517 ) ;
}
}
int F_295 ( struct V_1 * V_2 , int V_514 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_394 )
return - 1 ;
V_4 = F_180 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_218 ;
unsigned int V_19 = F_62 ( V_2 ) ;
unsigned int V_518 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_498 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_498 = F_5 ( V_4 ) -> V_12 ;
if ( V_518 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_518 = F_20 ( V_518 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_284 ;
if ( F_135 ( V_2 , V_4 , V_518 , V_19 , V_182 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_123 ( V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_284 ;
V_218 = F_97 ( V_2 , V_4 , 1 , V_182 ) ;
if ( ! V_218 )
F_1 ( V_2 , V_4 ) ;
return V_218 ;
} else {
if ( F_296 ( V_8 -> V_96 , V_8 -> V_95 + 1 , V_8 -> V_95 + 0xFFFF ) )
F_293 ( V_2 , 1 , V_514 ) ;
return F_293 ( V_2 , 0 , V_514 ) ;
}
}
void F_297 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
unsigned long V_519 ;
int V_218 ;
V_218 = F_295 ( V_2 , V_517 ) ;
if ( V_8 -> V_10 || ! F_180 ( V_2 ) ) {
V_6 -> V_520 = 0 ;
V_6 -> V_521 = 0 ;
return;
}
if ( V_218 <= 0 ) {
if ( V_6 -> V_521 < V_299 -> V_70 . V_522 )
V_6 -> V_521 ++ ;
V_6 -> V_520 ++ ;
V_519 = V_386 ;
} else {
if ( ! V_6 -> V_520 )
V_6 -> V_520 = 1 ;
V_519 = V_523 ;
}
F_207 ( V_2 , V_524 ,
F_298 ( V_2 , V_519 ) ,
V_386 ) ;
}
int F_299 ( const struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_525 * V_526 = F_262 ( V_75 ) -> V_149 ;
struct V_527 V_253 ;
int V_528 ;
F_262 ( V_75 ) -> V_459 = F_300 () ;
V_528 = V_526 -> V_529 ( V_2 , NULL , & V_253 , V_75 , NULL , V_453 ) ;
if ( ! V_528 ) {
F_264 ( F_9 ( V_2 ) , V_419 ) ;
F_234 ( F_9 ( V_2 ) , V_420 ) ;
if ( F_51 ( F_301 ( V_2 ) ) )
F_3 ( V_2 ) -> V_421 ++ ;
}
return V_528 ;
}
