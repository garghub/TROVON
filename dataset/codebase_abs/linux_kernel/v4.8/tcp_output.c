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
V_177 | V_178 ) )
F_60 ( V_2 , F_61 ( V_2 ) , F_3 ( V_2 ) -> V_179 ,
0 , V_180 ) ;
}
static void F_62 ( unsigned long V_181 )
{
struct V_182 * V_183 = (struct V_182 * ) V_181 ;
F_63 ( V_184 ) ;
unsigned long V_88 ;
struct V_185 * V_186 , * V_187 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_64 ( V_88 ) ;
F_65 ( & V_183 -> V_188 , & V_184 ) ;
F_66 ( V_88 ) ;
F_67 (q, n, &list) {
V_8 = F_68 ( V_186 , struct V_7 , V_189 ) ;
F_69 ( & V_8 -> V_189 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_70 ( V_2 ) ;
if ( ! F_71 ( V_2 ) ) {
F_59 ( V_2 ) ;
} else {
F_72 ( V_190 , & V_8 -> V_191 ) ;
}
F_73 ( V_2 ) ;
F_74 ( V_192 , & V_8 -> V_191 ) ;
F_75 ( V_2 ) ;
}
}
void F_76 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_88 , V_193 ;
do {
V_88 = V_8 -> V_191 ;
if ( ! ( V_88 & V_194 ) )
return;
V_193 = V_88 & ~ V_194 ;
} while ( F_77 ( & V_8 -> V_191 , V_88 , V_193 ) != V_88 );
if ( V_88 & ( 1UL << V_190 ) )
F_59 ( V_2 ) ;
F_78 ( V_2 ) ;
if ( V_88 & ( 1UL << V_195 ) ) {
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_196 ) ) {
F_81 ( V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_197 ) ) {
F_2 ( V_2 ) -> V_198 -> V_199 ( V_2 ) ;
F_80 ( V_2 ) ;
}
}
void T_9 F_82 ( void )
{
int V_200 ;
F_83 (i) {
struct V_182 * V_183 = & F_84 ( V_182 , V_200 ) ;
F_85 ( & V_183 -> V_188 ) ;
F_86 ( & V_183 -> V_201 ,
F_62 ,
( unsigned long ) V_183 ) ;
}
}
void F_87 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_202 ;
V_202 = F_88 ( V_4 -> V_203 - 1 , & V_2 -> V_204 ) ;
if ( V_202 >= F_89 ( 1 ) && F_90 () == V_205 )
goto V_206;
if ( F_91 ( V_207 , & V_8 -> V_191 ) &&
! F_92 ( V_192 , & V_8 -> V_191 ) ) {
unsigned long V_88 ;
struct V_182 * V_183 ;
F_64 ( V_88 ) ;
V_183 = F_93 ( & V_182 ) ;
F_94 ( & V_8 -> V_189 , & V_183 -> V_188 ) ;
F_95 ( & V_183 -> V_201 ) ;
F_66 ( V_88 ) ;
return;
}
V_206:
F_75 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_208 ,
T_10 V_209 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_210 * V_211 ;
struct V_7 * V_8 ;
struct V_212 * V_213 ;
struct V_98 V_99 ;
unsigned int V_214 , V_215 ;
struct V_142 * V_143 ;
struct V_76 * V_77 ;
int V_216 ;
F_97 ( ! V_4 || ! F_6 ( V_4 ) ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_208 ) {
F_98 ( & V_4 -> V_217 ) ;
F_5 ( V_4 ) -> V_218 . V_219 = F_5 ( V_4 ) -> V_12
- V_8 -> V_95 ;
if ( F_51 ( F_99 ( V_4 ) ) )
V_4 = F_100 ( V_4 , V_209 ) ;
else
V_4 = F_101 ( V_4 , V_209 ) ;
if ( F_51 ( ! V_4 ) )
return - V_220 ;
}
V_211 = F_102 ( V_2 ) ;
V_213 = F_5 ( V_4 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( F_51 ( V_213 -> V_64 & V_93 ) )
V_214 = F_54 ( V_2 , V_4 , & V_99 , & V_143 ) ;
else
V_214 = F_58 ( V_2 , V_4 , & V_99 ,
& V_143 ) ;
V_215 = V_214 + sizeof( struct V_76 ) ;
V_4 -> V_221 = F_103 ( V_2 ) < F_89 ( 1 ) ;
F_104 ( V_4 , V_215 ) ;
F_105 ( V_4 ) ;
F_106 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_222 = F_107 ( V_4 ) ? V_223 : F_87 ;
F_108 ( V_4 , V_2 ) ;
F_109 ( V_4 -> V_203 , & V_2 -> V_204 ) ;
V_77 = (struct V_76 * ) V_4 -> V_181 ;
V_77 -> V_224 = V_211 -> V_225 ;
V_77 -> V_226 = V_211 -> V_227 ;
V_77 -> V_82 = F_52 ( V_213 -> V_82 ) ;
V_77 -> V_228 = F_52 ( V_8 -> V_60 ) ;
* ( ( ( V_229 * ) V_77 ) + 6 ) = F_110 ( ( ( V_215 >> 2 ) << 12 ) |
V_213 -> V_64 ) ;
V_77 -> V_230 = 0 ;
V_77 -> V_231 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_213 -> V_82 , V_8 -> V_96 ) ) ) {
if ( F_11 ( V_8 -> V_96 , V_213 -> V_82 + 0x10000 ) ) {
V_77 -> V_231 = F_110 ( V_8 -> V_96 - V_213 -> V_82 ) ;
V_77 -> V_232 = 1 ;
} else if ( F_111 ( V_213 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_231 = F_110 ( 0xFFFF ) ;
V_77 -> V_232 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_99 ) ;
F_45 ( V_4 ) -> V_85 = V_2 -> V_233 ;
if ( F_53 ( ! ( V_213 -> V_64 & V_93 ) ) ) {
V_77 -> V_234 = F_110 ( F_31 ( V_2 ) ) ;
F_44 ( V_2 , V_4 , V_77 , V_215 ) ;
} else {
V_77 -> V_234 = F_110 ( F_20 ( V_8 -> V_44 , 65535U ) ) ;
}
#ifdef F_55
if ( V_143 ) {
F_112 ( V_2 , V_235 ) ;
V_8 -> V_149 -> V_236 ( V_99 . V_105 ,
V_143 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_198 -> V_237 ( V_2 , V_4 ) ;
if ( F_53 ( V_213 -> V_64 & V_238 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_215 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_239 += F_6 ( V_4 ) ;
}
if ( F_111 ( V_213 -> V_12 , V_8 -> V_11 ) || V_213 -> V_82 == V_213 -> V_12 )
F_113 ( F_9 ( V_2 ) , V_240 ,
F_6 ( V_4 ) ) ;
V_8 -> V_241 += F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_242 = F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_243 = F_114 ( V_4 ) ;
V_4 -> V_244 . V_245 = 0 ;
memset ( V_4 -> V_246 , 0 , F_21 ( sizeof( struct V_247 ) ,
sizeof( struct V_248 ) ) ) ;
V_216 = V_6 -> V_198 -> V_249 ( V_2 , V_4 , & V_211 -> V_250 . V_251 ) ;
if ( F_53 ( V_216 <= 0 ) )
return V_216 ;
F_115 ( V_2 ) ;
return F_116 ( V_216 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_252 = F_5 ( V_4 ) -> V_12 ;
F_118 ( V_4 ) ;
F_119 ( V_2 , V_4 ) ;
V_2 -> V_253 += V_4 -> V_203 ;
F_120 ( V_2 , V_4 -> V_203 ) ;
}
static void F_121 ( struct V_3 * V_4 , unsigned int V_254 )
{
if ( V_4 -> V_81 <= V_254 || V_4 -> V_89 == V_255 ) {
F_48 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_256 = 0 ;
} else {
F_48 ( V_4 , F_122 ( V_4 -> V_81 , V_254 ) ) ;
F_5 ( V_4 ) -> V_256 = V_254 ;
}
}
static void F_123 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_257 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_258 || F_124 ( V_8 ) )
return;
if ( F_111 ( F_125 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_259 -= V_257 ;
}
static void F_126 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_257 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_257 ;
if ( F_5 ( V_4 ) -> V_92 & V_260 )
V_8 -> V_258 -= V_257 ;
if ( F_5 ( V_4 ) -> V_92 & V_261 )
V_8 -> V_262 -= V_257 ;
if ( F_5 ( V_4 ) -> V_92 & V_263 )
V_8 -> V_264 -= V_257 ;
if ( F_124 ( V_8 ) && V_257 > 0 )
V_8 -> V_258 -= F_30 ( T_4 , V_8 -> V_258 , V_257 ) ;
F_123 ( V_2 , V_4 , V_257 ) ;
if ( V_8 -> V_265 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_265 ) -> V_82 ) &&
( F_127 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_260 ) ) )
V_8 -> V_266 -= V_257 ;
F_128 ( V_8 ) ;
}
static bool F_129 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_267 ||
( F_45 ( V_4 ) -> V_268 & V_269 ) ;
}
static void F_130 ( struct V_3 * V_4 , struct V_3 * V_270 )
{
struct V_271 * V_272 = F_45 ( V_4 ) ;
if ( F_51 ( F_129 ( V_4 ) ) &&
! F_11 ( V_272 -> V_273 , F_5 ( V_270 ) -> V_82 ) ) {
struct V_271 * V_274 = F_45 ( V_270 ) ;
T_7 V_275 = V_272 -> V_268 & V_269 ;
V_272 -> V_268 &= ~ V_275 ;
V_274 -> V_268 |= V_275 ;
F_131 ( V_272 -> V_273 , V_274 -> V_273 ) ;
F_5 ( V_270 ) -> V_267 = F_5 ( V_4 ) -> V_267 ;
F_5 ( V_4 ) -> V_267 = 0 ;
}
}
static void F_132 ( struct V_3 * V_4 , struct V_3 * V_270 )
{
F_5 ( V_270 ) -> V_276 = F_5 ( V_4 ) -> V_276 ;
F_5 ( V_4 ) -> V_276 = 0 ;
}
int F_133 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_254 , T_10 V_277 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_278 ;
int V_279 , V_280 ;
int V_281 ;
T_7 V_88 ;
if ( F_134 ( V_81 > V_4 -> V_81 ) )
return - V_282 ;
V_279 = F_135 ( V_4 ) - V_81 ;
if ( V_279 < 0 )
V_279 = 0 ;
if ( F_136 ( V_4 , V_277 ) )
return - V_283 ;
V_278 = F_137 ( V_2 , V_279 , V_277 , true ) ;
if ( ! V_278 )
return - V_283 ;
V_2 -> V_253 += V_278 -> V_203 ;
F_120 ( V_2 , V_278 -> V_203 ) ;
V_281 = V_4 -> V_81 - V_81 - V_279 ;
V_278 -> V_203 += V_281 ;
V_4 -> V_203 -= V_281 ;
F_5 ( V_278 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_278 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_278 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_284 ) ;
F_5 ( V_278 ) -> V_64 = V_88 ;
F_5 ( V_278 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
F_132 ( V_4 , V_278 ) ;
if ( ! F_45 ( V_4 ) -> V_285 && V_4 -> V_89 != V_90 ) {
V_278 -> V_91 = F_138 ( V_4 -> V_181 + V_81 ,
F_139 ( V_278 , V_279 ) ,
V_279 , 0 ) ;
F_140 ( V_4 , V_81 ) ;
V_4 -> V_91 = F_141 ( V_4 -> V_91 , V_278 -> V_91 , V_81 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_142 ( V_4 , V_278 , V_81 ) ;
}
V_278 -> V_89 = V_4 -> V_89 ;
V_278 -> V_244 = V_4 -> V_244 ;
F_130 ( V_4 , V_278 ) ;
V_280 = F_6 ( V_4 ) ;
F_121 ( V_4 , V_254 ) ;
F_121 ( V_278 , V_254 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_278 ) -> V_12 ) ) {
int V_286 = V_280 - F_6 ( V_4 ) -
F_6 ( V_278 ) ;
if ( V_286 )
F_126 ( V_2 , V_4 , V_286 ) ;
}
F_118 ( V_278 ) ;
F_143 ( V_4 , V_278 , V_2 ) ;
return 0 ;
}
static void F_144 ( struct V_3 * V_4 , int V_81 )
{
struct V_271 * V_272 ;
int V_200 , V_287 , V_288 ;
V_288 = F_30 ( int , V_81 , F_135 ( V_4 ) ) ;
if ( V_288 ) {
F_145 ( V_4 , V_288 ) ;
V_81 -= V_288 ;
if ( ! V_81 )
return;
}
V_288 = V_81 ;
V_287 = 0 ;
V_272 = F_45 ( V_4 ) ;
for ( V_200 = 0 ; V_200 < V_272 -> V_285 ; V_200 ++ ) {
int V_169 = F_146 ( & V_272 -> V_289 [ V_200 ] ) ;
if ( V_169 <= V_288 ) {
F_147 ( V_4 , V_200 ) ;
V_288 -= V_169 ;
} else {
V_272 -> V_289 [ V_287 ] = V_272 -> V_289 [ V_200 ] ;
if ( V_288 ) {
V_272 -> V_289 [ V_287 ] . V_290 += V_288 ;
F_148 ( & V_272 -> V_289 [ V_287 ] , V_288 ) ;
V_288 = 0 ;
}
V_287 ++ ;
}
}
V_272 -> V_285 = V_287 ;
F_149 ( V_4 ) ;
V_4 -> V_291 -= V_81 ;
V_4 -> V_81 = V_4 -> V_291 ;
}
int F_150 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_136 ( V_4 , V_180 ) )
return - V_283 ;
F_144 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_203 -= V_81 ;
V_2 -> V_253 -= V_81 ;
F_151 ( V_2 , V_81 ) ;
F_152 ( V_2 , V_292 ) ;
if ( F_6 ( V_4 ) > 1 )
F_121 ( V_4 , F_114 ( V_4 ) ) ;
return 0 ;
}
static inline int F_153 ( struct V_1 * V_2 , int V_293 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_254 ;
V_254 = V_293 - V_6 -> V_198 -> V_294 - sizeof( struct V_76 ) ;
if ( V_6 -> V_198 -> V_295 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_254 -= V_6 -> V_198 -> V_295 ;
}
if ( V_254 > V_8 -> V_58 . V_296 )
V_254 = V_8 -> V_58 . V_296 ;
V_254 -= V_6 -> V_297 ;
if ( V_254 < 48 )
V_254 = 48 ;
return V_254 ;
}
int F_155 ( struct V_1 * V_2 , int V_293 )
{
return F_153 ( V_2 , V_293 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_156 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_298 ;
V_298 = V_19 +
V_8 -> V_80 +
V_6 -> V_297 +
V_6 -> V_198 -> V_294 ;
if ( V_6 -> V_198 -> V_295 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_298 += V_6 -> V_198 -> V_295 ;
}
return V_298 ;
}
void F_157 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
V_6 -> V_300 . V_301 = V_299 -> V_70 . V_302 > 1 ;
V_6 -> V_300 . V_303 = V_8 -> V_58 . V_296 + sizeof( struct V_76 ) +
V_6 -> V_198 -> V_294 ;
V_6 -> V_300 . V_304 = F_156 ( V_2 , V_299 -> V_70 . V_305 ) ;
V_6 -> V_300 . V_306 = 0 ;
if ( V_6 -> V_300 . V_301 )
V_6 -> V_300 . V_307 = V_30 ;
}
unsigned int F_158 ( struct V_1 * V_2 , T_4 V_293 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_254 ;
if ( V_6 -> V_300 . V_303 > V_293 )
V_6 -> V_300 . V_303 = V_293 ;
V_254 = F_155 ( V_2 , V_293 ) ;
V_254 = F_159 ( V_8 , V_254 ) ;
V_6 -> V_308 = V_293 ;
if ( V_6 -> V_300 . V_301 )
V_254 = F_20 ( V_254 , F_155 ( V_2 , V_6 -> V_300 . V_304 ) ) ;
V_8 -> V_309 = V_254 ;
return V_254 ;
}
unsigned int F_61 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_254 ;
unsigned int V_310 ;
struct V_98 V_99 ;
struct V_142 * V_143 ;
V_254 = V_8 -> V_309 ;
if ( V_18 ) {
T_4 V_298 = F_160 ( V_18 ) ;
if ( V_298 != F_2 ( V_2 ) -> V_308 )
V_254 = F_158 ( V_2 , V_298 ) ;
}
V_310 = F_58 ( V_2 , NULL , & V_99 , & V_143 ) +
sizeof( struct V_76 ) ;
if ( V_310 != V_8 -> V_80 ) {
int V_22 = ( int ) V_310 - V_8 -> V_80 ;
V_254 -= V_22 ;
}
return V_254 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_311 == V_312 &&
V_2 -> V_313 && ! F_162 ( V_314 , & V_2 -> V_313 -> V_88 ) ) {
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
static void F_163 ( struct V_1 * V_2 , bool V_317 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_95 , V_8 -> V_318 ) ||
V_8 -> V_10 > V_8 -> V_319 ) {
V_8 -> V_319 = V_8 -> V_10 ;
V_8 -> V_318 = V_8 -> V_11 ;
V_8 -> V_317 = V_317 ;
}
if ( F_164 ( V_2 ) ) {
V_8 -> V_31 = 0 ;
V_8 -> V_29 = V_30 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_31 )
V_8 -> V_31 = V_8 -> V_10 ;
if ( V_320 &&
( T_3 ) ( V_30 - V_8 -> V_29 ) >= F_2 ( V_2 ) -> V_28 )
F_161 ( V_2 ) ;
}
}
static bool F_165 ( const struct V_7 * V_8 )
{
return F_111 ( V_8 -> V_321 , V_8 -> V_95 ) &&
! F_111 ( V_8 -> V_321 , V_8 -> V_11 ) ;
}
static void F_166 ( struct V_7 * V_8 , unsigned int V_254 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_254 )
V_8 -> V_321 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_167 ( bool V_322 , const struct V_7 * V_8 ,
int V_179 )
{
return V_322 &&
( ( V_179 & V_323 ) ||
( ! V_179 && V_8 -> V_10 && F_165 ( V_8 ) ) ) ;
}
static T_4 F_168 ( const struct V_1 * V_2 , unsigned int V_254 )
{
T_4 V_324 , V_325 ;
V_324 = F_20 ( V_2 -> V_326 >> 10 ,
V_2 -> V_327 - 1 - V_328 ) ;
V_325 = F_29 ( T_4 , V_324 / V_254 , V_329 ) ;
return F_30 ( T_4 , V_325 , V_2 -> V_330 ) ;
}
static unsigned int F_169 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_254 ,
unsigned int V_331 ,
int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_322 , V_332 , V_234 , V_333 ;
V_234 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_333 = V_254 * V_331 ;
if ( F_53 ( V_333 <= V_234 && V_4 != F_170 ( V_2 ) ) )
return V_333 ;
V_332 = F_20 ( V_4 -> V_81 , V_234 ) ;
if ( V_333 <= V_332 )
return V_333 ;
V_322 = V_332 % V_254 ;
if ( F_167 ( V_322 != 0 , V_8 , V_179 ) )
return V_332 - V_322 ;
return V_332 ;
}
static inline unsigned int F_171 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_219 , V_24 , V_334 ;
if ( ( F_5 ( V_4 ) -> V_64 & V_94 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_219 = F_23 ( V_8 ) ;
V_24 = V_8 -> V_25 ;
if ( V_219 >= V_24 )
return 0 ;
V_334 = F_21 ( V_24 >> 1 , 1U ) ;
return F_20 ( V_334 , V_24 - V_219 ) ;
}
static int F_172 ( struct V_3 * V_4 , unsigned int V_254 )
{
int V_335 = F_6 ( V_4 ) ;
if ( ! V_335 || ( V_335 > 1 && F_114 ( V_4 ) != V_254 ) ) {
F_121 ( V_4 , V_254 ) ;
V_335 = F_6 ( V_4 ) ;
}
return V_335 ;
}
static inline bool F_173 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_336 , int V_179 )
{
if ( V_179 & V_337 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_64 & V_94 ) )
return true ;
if ( ! F_167 ( V_4 -> V_81 < V_336 , V_8 , V_179 ) )
return true ;
return false ;
}
static bool F_174 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_336 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_336 )
V_12 = F_5 ( V_4 ) -> V_82 + V_336 ;
return ! F_111 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_175 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_336 , int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_338 ;
F_172 ( V_4 , V_336 ) ;
if ( ! F_173 ( V_8 , V_4 , V_336 , V_179 ) )
return 0 ;
V_338 = F_171 ( V_8 , V_4 ) ;
if ( V_338 && ! F_174 ( V_8 , V_4 , V_336 ) )
V_338 = 0 ;
return V_338 ;
}
bool F_176 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_177 ( V_2 ) ;
return V_4 &&
F_175 ( V_2 , V_4 , F_61 ( V_2 ) ,
( F_178 ( V_2 , V_4 ) ?
V_8 -> V_179 : V_337 ) ) ;
}
static int F_179 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_254 , T_10 V_277 )
{
struct V_3 * V_278 ;
int V_281 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_291 )
return F_133 ( V_2 , V_4 , V_81 , V_254 , V_277 ) ;
V_278 = F_137 ( V_2 , 0 , V_277 , true ) ;
if ( F_51 ( ! V_278 ) )
return - V_283 ;
V_2 -> V_253 += V_278 -> V_203 ;
F_120 ( V_2 , V_278 -> V_203 ) ;
V_278 -> V_203 += V_281 ;
V_4 -> V_203 -= V_281 ;
F_5 ( V_278 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_278 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_278 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_284 ) ;
F_5 ( V_278 ) -> V_64 = V_88 ;
F_5 ( V_278 ) -> V_92 = 0 ;
F_132 ( V_4 , V_278 ) ;
V_278 -> V_89 = V_4 -> V_89 = V_90 ;
F_142 ( V_4 , V_278 , V_81 ) ;
F_130 ( V_4 , V_278 ) ;
F_121 ( V_4 , V_254 ) ;
F_121 ( V_278 , V_254 ) ;
F_118 ( V_278 ) ;
F_143 ( V_4 , V_278 , V_2 ) ;
return 0 ;
}
static bool F_180 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_317 , T_4 V_331 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_339 , V_340 , V_341 , V_342 , V_219 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_217 V_32 ;
struct V_3 * V_188 ;
int V_343 ;
if ( F_5 ( V_4 ) -> V_64 & V_94 )
goto V_344;
if ( V_6 -> V_311 >= V_345 )
goto V_344;
if ( ( T_3 ) ( V_30 - V_8 -> V_34 ) > 0 )
goto V_344;
V_219 = F_23 ( V_8 ) ;
F_97 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_25 <= V_219 ) ) ;
V_340 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_341 = ( V_8 -> V_25 - V_219 ) * V_8 -> V_309 ;
V_342 = F_20 ( V_340 , V_341 ) ;
if ( V_342 >= V_331 * V_8 -> V_309 )
goto V_344;
if ( ( V_4 != F_170 ( V_2 ) ) && ( V_342 >= V_4 -> V_81 ) )
goto V_344;
V_343 = F_181 ( V_346 ) ;
if ( V_343 ) {
T_4 V_347 = F_20 ( V_8 -> V_348 , V_8 -> V_25 * V_8 -> V_309 ) ;
V_347 /= V_343 ;
if ( V_342 >= V_347 )
goto V_344;
} else {
if ( V_342 > F_182 ( V_8 ) * V_8 -> V_309 )
goto V_344;
}
V_188 = F_183 ( V_2 ) ;
F_98 ( & V_32 ) ;
V_339 = F_184 ( & V_32 , & V_188 -> V_217 ) ;
if ( V_339 < ( V_8 -> V_349 >> 4 ) )
goto V_344;
if ( V_341 < V_340 && V_341 <= V_4 -> V_81 )
* V_317 = true ;
return true ;
V_344:
return false ;
}
static inline void F_185 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
T_4 V_350 ;
T_3 V_22 ;
V_350 = V_299 -> V_70 . V_351 ;
V_22 = V_30 - V_6 -> V_300 . V_307 ;
if ( F_51 ( V_22 >= V_350 * V_352 ) ) {
int V_19 = F_61 ( V_2 ) ;
V_6 -> V_300 . V_306 = 0 ;
V_6 -> V_300 . V_303 = V_8 -> V_58 . V_296 +
sizeof( struct V_76 ) +
V_6 -> V_198 -> V_294 ;
V_6 -> V_300 . V_304 = F_156 ( V_2 , V_19 ) ;
V_6 -> V_300 . V_307 = V_30 ;
}
}
static int F_186 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_353 , * V_354 ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
int V_81 ;
int V_306 ;
int V_355 ;
int V_356 ;
int V_254 ;
int V_350 ;
if ( ! V_6 -> V_300 . V_301 ||
V_6 -> V_300 . V_306 ||
F_2 ( V_2 ) -> V_311 != V_312 ||
V_8 -> V_25 < 11 ||
V_8 -> V_58 . V_171 || V_8 -> V_58 . V_123 )
return - 1 ;
V_254 = F_61 ( V_2 ) ;
V_306 = F_155 ( V_2 , ( V_6 -> V_300 . V_303 +
V_6 -> V_300 . V_304 ) >> 1 ) ;
V_355 = V_306 + ( V_8 -> V_357 + 1 ) * V_8 -> V_309 ;
V_350 = V_6 -> V_300 . V_303 - V_6 -> V_300 . V_304 ;
if ( V_306 > F_155 ( V_2 , V_6 -> V_300 . V_303 ) ||
V_350 < V_299 -> V_70 . V_358 ) {
F_185 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_252 - V_8 -> V_11 < V_355 )
return - 1 ;
if ( V_8 -> V_348 < V_355 )
return - 1 ;
if ( F_111 ( V_8 -> V_11 + V_355 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_25 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_353 = F_137 ( V_2 , V_306 , V_180 , false ) ;
if ( ! V_353 )
return - 1 ;
V_2 -> V_253 += V_353 -> V_203 ;
F_120 ( V_2 , V_353 -> V_203 ) ;
V_4 = F_177 ( V_2 ) ;
F_5 ( V_353 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_353 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_306 ;
F_5 ( V_353 ) -> V_64 = V_238 ;
F_5 ( V_353 ) -> V_92 = 0 ;
V_353 -> V_91 = 0 ;
V_353 -> V_89 = V_4 -> V_89 ;
F_187 ( V_353 , V_4 , V_2 ) ;
V_81 = 0 ;
F_188 (skb, next, sk) {
V_356 = F_30 ( int , V_4 -> V_81 , V_306 - V_81 ) ;
if ( V_353 -> V_89 ) {
F_189 ( V_4 , 0 , F_139 ( V_353 , V_356 ) , V_356 ) ;
} else {
T_11 V_91 = F_190 ( V_4 , 0 ,
F_139 ( V_353 , V_356 ) ,
V_356 , 0 ) ;
V_353 -> V_91 = F_191 ( V_353 -> V_91 , V_91 , V_81 ) ;
}
if ( V_4 -> V_81 <= V_356 ) {
F_5 ( V_353 ) -> V_64 |= F_5 ( V_4 ) -> V_64 ;
F_192 ( V_4 , V_2 ) ;
F_193 ( V_2 , V_4 ) ;
} else {
F_5 ( V_353 ) -> V_64 |= F_5 ( V_4 ) -> V_64 &
~ ( V_94 | V_284 ) ;
if ( ! F_45 ( V_4 ) -> V_285 ) {
F_194 ( V_4 , V_356 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_195 ( V_4 -> V_181 ,
V_4 -> V_81 , 0 ) ;
} else {
F_144 ( V_4 , V_356 ) ;
F_121 ( V_4 , V_254 ) ;
}
F_5 ( V_4 ) -> V_82 += V_356 ;
}
V_81 += V_356 ;
if ( V_81 >= V_306 )
break;
}
F_172 ( V_353 , V_353 -> V_81 ) ;
if ( ! F_96 ( V_2 , V_353 , 1 , V_180 ) ) {
V_8 -> V_25 -- ;
F_1 ( V_2 , V_353 ) ;
V_6 -> V_300 . V_306 = F_156 ( V_2 , V_353 -> V_81 ) ;
V_8 -> V_359 . V_360 = F_5 ( V_353 ) -> V_82 ;
V_8 -> V_359 . V_361 = F_5 ( V_353 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_60 ( struct V_1 * V_2 , unsigned int V_254 , int V_179 ,
int V_362 , T_10 V_277 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_335 , V_363 ;
int V_338 ;
int V_364 ;
bool V_317 = false ;
T_4 V_331 ;
V_363 = 0 ;
if ( ! V_362 ) {
V_364 = F_186 ( V_2 ) ;
if ( ! V_364 ) {
return false ;
} else if ( V_364 > 0 ) {
V_363 = 1 ;
}
}
V_331 = F_168 ( V_2 , V_254 ) ;
while ( ( V_4 = F_177 ( V_2 ) ) ) {
unsigned int V_342 ;
V_335 = F_172 ( V_4 , V_254 ) ;
F_97 ( ! V_335 ) ;
if ( F_51 ( V_8 -> V_365 ) && V_8 -> V_366 == V_367 ) {
F_98 ( & V_4 -> V_217 ) ;
goto V_365;
}
V_338 = F_171 ( V_8 , V_4 ) ;
if ( ! V_338 ) {
if ( V_362 == 2 )
V_338 = 1 ;
else
break;
}
if ( F_51 ( ! F_174 ( V_8 , V_4 , V_254 ) ) )
break;
if ( V_335 == 1 ) {
if ( F_51 ( ! F_173 ( V_8 , V_4 , V_254 ,
( F_178 ( V_2 , V_4 ) ?
V_179 : V_337 ) ) ) )
break;
} else {
if ( ! V_362 &&
F_180 ( V_2 , V_4 , & V_317 ,
V_331 ) )
break;
}
V_342 = V_254 ;
if ( V_335 > 1 && ! F_49 ( V_8 ) )
V_342 = F_169 ( V_2 , V_4 , V_254 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_179 ) ;
if ( V_4 -> V_81 > V_342 &&
F_51 ( F_179 ( V_2 , V_4 , V_342 , V_254 , V_277 ) ) )
break;
V_342 = F_21 ( 2 * V_4 -> V_203 , V_2 -> V_326 >> 10 ) ;
V_342 = F_30 ( T_4 , V_342 , V_368 ) ;
if ( F_196 ( & V_2 -> V_204 ) > V_342 ) {
F_72 ( V_207 , & V_8 -> V_191 ) ;
F_197 () ;
if ( F_196 ( & V_2 -> V_204 ) > V_342 )
break;
}
if ( F_51 ( F_96 ( V_2 , V_4 , 1 , V_277 ) ) )
break;
V_365:
F_1 ( V_2 , V_4 ) ;
F_166 ( V_8 , V_254 , V_4 ) ;
V_363 += F_6 ( V_4 ) ;
if ( V_362 )
break;
}
if ( F_53 ( V_363 ) ) {
if ( F_198 ( V_2 ) )
V_8 -> V_369 += V_363 ;
if ( V_362 != 2 )
F_199 ( V_2 ) ;
V_317 |= ( F_23 ( V_8 ) >= V_8 -> V_25 ) ;
F_163 ( V_2 , V_317 ) ;
return false ;
}
return ! V_8 -> V_10 && F_177 ( V_2 ) ;
}
bool F_199 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_370 , V_371 , V_372 ;
T_4 V_373 = F_200 ( V_8 -> V_349 >> 3 ) ;
if ( F_134 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_134 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_8 -> V_374 )
return false ;
if ( V_6 -> V_13 != V_375 )
return false ;
if ( V_376 < 3 || ! V_8 -> V_10 ||
! F_201 ( V_8 ) || F_2 ( V_2 ) -> V_311 != V_312 )
return false ;
if ( ( V_8 -> V_25 > F_23 ( V_8 ) ) &&
F_177 ( V_2 ) )
return false ;
V_370 = V_373 << 1 ? : V_377 ;
if ( V_8 -> V_10 == 1 )
V_370 = F_29 ( T_4 , V_370 ,
( V_373 + ( V_373 >> 1 ) + V_378 ) ) ;
V_370 = F_29 ( T_4 , V_370 , F_202 ( 10 ) ) ;
V_371 = V_30 + V_370 ;
V_372 = ( T_4 ) F_2 ( V_2 ) -> V_379 ;
if ( ( T_3 ) ( V_371 - V_372 ) > 0 ) {
T_3 V_22 = V_372 - V_30 ;
if ( V_22 > 0 )
V_370 = V_22 ;
}
F_203 ( V_2 , V_15 , V_370 ,
V_380 ) ;
return true ;
}
static bool F_204 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_205 ( V_2 , V_4 ) ) ) {
F_34 ( F_9 ( V_2 ) ,
V_381 ) ;
return true ;
}
return false ;
}
void F_206 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_382 ;
int V_19 = F_61 ( V_2 ) ;
V_4 = F_177 ( V_2 ) ;
if ( V_4 ) {
if ( F_174 ( V_8 , V_4 , V_19 ) ) {
V_382 = V_8 -> V_10 ;
F_60 ( V_2 , V_19 , V_383 , 2 , V_180 ) ;
if ( V_8 -> V_10 > V_382 )
goto V_384;
goto V_385;
}
V_4 = F_207 ( V_2 , V_4 ) ;
} else {
V_4 = F_170 ( V_2 ) ;
}
if ( V_8 -> V_386 )
goto V_385;
if ( F_134 ( ! V_4 ) )
goto V_385;
if ( F_204 ( V_2 , V_4 ) )
goto V_385;
V_382 = F_6 ( V_4 ) ;
if ( F_134 ( ! V_382 ) )
goto V_385;
if ( ( V_382 > 1 ) && ( V_4 -> V_81 > ( V_382 - 1 ) * V_19 ) ) {
if ( F_51 ( F_133 ( V_2 , V_4 , ( V_382 - 1 ) * V_19 , V_19 ,
V_180 ) ) )
goto V_385;
V_4 = F_208 ( V_2 , V_4 ) ;
}
if ( F_134 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_385;
if ( F_209 ( V_2 , V_4 , 1 ) )
goto V_385;
V_8 -> V_386 = V_8 -> V_11 ;
V_384:
F_34 ( F_9 ( V_2 ) , V_387 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_385:
F_7 ( V_2 ) ;
}
void F_210 ( struct V_1 * V_2 , unsigned int V_336 ,
int V_179 )
{
if ( F_51 ( V_2 -> V_173 == V_388 ) )
return;
if ( F_60 ( V_2 , V_336 , V_179 , 0 ,
F_211 ( V_2 , V_180 ) ) )
F_212 ( V_2 ) ;
}
void F_213 ( struct V_1 * V_2 , unsigned int V_254 )
{
struct V_3 * V_4 = F_177 ( V_2 ) ;
F_97 ( ! V_4 || V_4 -> V_81 < V_254 ) ;
F_60 ( V_2 , V_254 , V_337 , 1 , V_2 -> V_389 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_390 ;
int V_391 = F_214 ( V_2 ) ;
int V_392 = F_215 ( V_2 ) ;
int V_393 = F_30 ( int , V_8 -> V_45 , V_392 ) ;
int V_234 ;
if ( V_19 > V_393 )
V_19 = V_393 ;
if ( V_391 < ( V_393 >> 1 ) ) {
V_6 -> V_35 . V_394 = 0 ;
if ( F_216 ( V_2 ) )
V_8 -> V_395 = F_20 ( V_8 -> V_395 ,
4U * V_8 -> V_20 ) ;
V_391 = F_217 ( V_391 , 1 << V_8 -> V_58 . V_47 ) ;
if ( V_391 < ( V_392 >> 4 ) || V_391 < V_19 )
return 0 ;
}
if ( V_391 > V_8 -> V_395 )
V_391 = V_8 -> V_395 ;
V_234 = V_8 -> V_44 ;
if ( V_8 -> V_58 . V_47 ) {
V_234 = V_391 ;
if ( ( ( V_234 >> V_8 -> V_58 . V_47 ) << V_8 -> V_58 . V_47 ) != V_234 )
V_234 = ( ( ( V_234 >> V_8 -> V_58 . V_47 ) + 1 )
<< V_8 -> V_58 . V_47 ) ;
} else {
if ( V_234 <= V_391 - V_19 || V_234 > V_391 )
V_234 = ( V_391 / V_19 ) * V_19 ;
else if ( V_19 == V_393 &&
V_391 > V_234 + ( V_393 >> 1 ) )
V_234 = V_391 ;
}
return V_234 ;
}
void F_218 ( struct V_3 * V_4 ,
const struct V_3 * V_396 )
{
if ( F_51 ( F_129 ( V_396 ) ) ) {
const struct V_271 * V_397 =
F_45 ( V_396 ) ;
struct V_271 * V_272 = F_45 ( V_4 ) ;
V_272 -> V_268 |= V_397 -> V_268 & V_269 ;
V_272 -> V_273 = V_397 -> V_273 ;
F_5 ( V_4 ) -> V_267 |=
F_5 ( V_396 ) -> V_267 ;
}
}
static void F_219 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_396 = F_208 ( V_2 , V_4 ) ;
int V_398 , V_399 ;
V_398 = V_4 -> V_81 ;
V_399 = V_396 -> V_81 ;
F_97 ( F_6 ( V_4 ) != 1 || F_6 ( V_396 ) != 1 ) ;
F_220 ( V_2 , V_396 , V_4 ) ;
F_192 ( V_396 , V_2 ) ;
F_221 ( V_396 , F_139 ( V_4 , V_399 ) ,
V_399 ) ;
if ( V_396 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_191 ( V_4 -> V_91 , V_396 -> V_91 , V_398 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_396 ) -> V_12 ;
F_5 ( V_4 ) -> V_64 |= F_5 ( V_396 ) -> V_64 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_396 ) -> V_92 & V_400 ;
F_5 ( V_4 ) -> V_276 = F_5 ( V_396 ) -> V_276 ;
F_222 ( V_8 ) ;
if ( V_396 == V_8 -> V_401 )
V_8 -> V_401 = V_4 ;
F_126 ( V_2 , V_396 , F_6 ( V_396 ) ) ;
F_218 ( V_4 , V_396 ) ;
F_193 ( V_2 , V_396 ) ;
}
static bool F_223 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_45 ( V_4 ) -> V_285 != 0 )
return false ;
if ( F_99 ( V_4 ) )
return false ;
if ( V_4 == F_177 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_260 )
return false ;
return true ;
}
static void F_224 ( struct V_1 * V_2 , struct V_3 * V_402 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_402 , * V_403 ;
bool V_404 = true ;
if ( ! V_405 )
return;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
return;
F_188 (skb, tmp, sk) {
if ( ! F_223 ( V_2 , V_4 ) )
break;
if ( ! F_225 ( V_402 ) )
break;
V_49 -= V_4 -> V_81 ;
if ( V_404 ) {
V_404 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_81 > F_226 ( V_402 ) )
break;
if ( F_111 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_219 ( V_2 , V_402 ) ;
}
}
int F_209 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_325 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_336 ;
int V_286 , V_81 , V_216 ;
if ( V_6 -> V_300 . V_306 )
V_6 -> V_300 . V_306 = 0 ;
if ( F_196 ( & V_2 -> V_204 ) >
F_30 ( T_4 , V_2 -> V_253 + ( V_2 -> V_253 >> 2 ) ,
V_2 -> V_406 ) )
return - V_407 ;
if ( F_204 ( V_2 , V_4 ) )
return - V_408 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_95 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_95 ) )
F_227 () ;
if ( F_150 ( V_2 , V_4 , V_8 -> V_95 - F_5 ( V_4 ) -> V_82 ) )
return - V_283 ;
}
if ( F_2 ( V_2 ) -> V_198 -> V_409 ( V_2 ) )
return - V_410 ;
V_336 = F_61 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_95 )
return - V_407 ;
V_81 = V_336 * V_325 ;
if ( V_4 -> V_81 > V_81 ) {
if ( F_133 ( V_2 , V_4 , V_81 , V_336 , V_180 ) )
return - V_283 ;
} else {
if ( F_136 ( V_4 , V_180 ) )
return - V_283 ;
V_286 = F_6 ( V_4 ) ;
F_121 ( V_4 , V_336 ) ;
V_286 -= F_6 ( V_4 ) ;
if ( V_286 )
F_126 ( V_2 , V_4 , V_286 ) ;
if ( V_4 -> V_81 < V_336 )
F_224 ( V_2 , V_4 , V_336 ) ;
}
if ( ( F_5 ( V_4 ) -> V_64 & V_411 ) == V_411 )
F_41 ( V_2 , V_4 ) ;
if ( F_51 ( ( V_412 && ( ( unsigned long ) V_4 -> V_181 & 3 ) ) ||
F_228 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_353 ;
F_98 ( & V_4 -> V_217 ) ;
V_353 = F_229 ( V_4 , V_328 , V_180 ) ;
V_216 = V_353 ? F_96 ( V_2 , V_353 , 0 , V_180 ) :
- V_220 ;
} else {
V_216 = F_96 ( V_2 , V_4 , 1 , V_180 ) ;
}
if ( F_53 ( ! V_216 ) ) {
V_325 = F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_92 |= V_400 ;
F_113 ( F_9 ( V_2 ) , V_413 , V_325 ) ;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
F_230 ( F_9 ( V_2 ) , V_414 ) ;
V_8 -> V_415 += V_325 ;
}
return V_216 ;
}
int F_231 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_325 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_216 = F_209 ( V_2 , V_4 , V_325 ) ;
if ( V_216 == 0 ) {
#if V_416 > 0
if ( F_5 ( V_4 ) -> V_92 & V_261 ) {
F_232 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_92 |= V_417 ;
V_8 -> V_262 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_418 )
V_8 -> V_418 = F_56 ( V_4 ) ;
} else if ( V_216 != - V_408 ) {
F_34 ( F_9 ( V_2 ) , V_419 ) ;
}
if ( V_8 -> V_420 < 0 )
V_8 -> V_420 = 0 ;
V_8 -> V_420 += F_6 ( V_4 ) ;
return V_216 ;
}
static bool F_233 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_311 != V_345 )
return false ;
if ( F_124 ( V_8 ) )
return false ;
if ( F_176 ( V_2 ) )
return false ;
return true ;
}
void F_234 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_421 = NULL ;
T_4 V_331 , V_422 ;
int V_423 ;
int V_424 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_264 )
V_8 -> V_425 = V_8 -> V_95 ;
if ( V_8 -> V_401 ) {
V_4 = V_8 -> V_401 ;
V_422 = F_5 ( V_4 ) -> V_12 ;
if ( F_111 ( V_422 , V_8 -> V_425 ) )
V_422 = V_8 -> V_425 ;
} else {
V_4 = F_183 ( V_2 ) ;
V_422 = V_8 -> V_95 ;
}
V_331 = F_168 ( V_2 , F_61 ( V_2 ) ) ;
F_235 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
int V_325 ;
if ( V_4 == F_177 ( V_2 ) )
break;
if ( ! V_421 )
V_8 -> V_401 = V_4 ;
V_325 = V_8 -> V_25 - F_23 ( V_8 ) ;
if ( V_325 <= 0 )
return;
V_325 = F_30 ( int , V_325 , V_331 ) ;
if ( V_424 ) {
V_426:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_125 ( V_8 ) ) )
break;
V_423 = V_427 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_425 ) ) {
V_8 -> V_425 = V_422 ;
if ( ! F_233 ( V_2 ) )
break;
if ( V_421 ) {
V_4 = V_421 ;
V_421 = NULL ;
}
V_424 = 1 ;
goto V_426;
} else if ( ! ( V_92 & V_263 ) ) {
if ( ! V_421 && ! ( V_92 & ( V_261 | V_260 ) ) )
V_421 = V_4 ;
continue;
} else {
V_422 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_311 != V_428 )
V_423 = V_429 ;
else
V_423 = V_430 ;
}
if ( V_92 & ( V_260 | V_261 ) )
continue;
if ( F_231 ( V_2 , V_4 , V_325 ) )
return;
F_8 ( F_9 ( V_2 ) , V_423 , F_6 ( V_4 ) ) ;
if ( F_198 ( V_2 ) )
V_8 -> V_369 += F_6 ( V_4 ) ;
if ( V_4 == F_183 ( V_2 ) )
F_203 ( V_2 , V_375 ,
F_2 ( V_2 ) -> V_28 ,
V_380 ) ;
}
}
void F_236 ( struct V_1 * V_2 , int V_169 )
{
int V_431 ;
if ( V_169 <= V_2 -> V_432 )
return;
V_431 = F_237 ( V_169 ) ;
V_2 -> V_432 += V_431 * V_433 ;
F_238 ( V_2 , V_431 ) ;
if ( V_434 && V_2 -> V_435 )
F_239 ( V_2 -> V_435 , V_431 ) ;
}
void F_240 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_436 = F_170 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_436 && ( F_177 ( V_2 ) || F_216 ( V_2 ) ) ) {
V_437:
F_5 ( V_436 ) -> V_64 |= V_94 ;
F_5 ( V_436 ) -> V_12 ++ ;
V_8 -> V_252 ++ ;
if ( ! F_177 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_241 ( V_328 , V_2 -> V_389 ) ;
if ( F_51 ( ! V_4 ) ) {
if ( V_436 )
goto V_437;
return;
}
F_242 ( V_4 , V_328 ) ;
F_236 ( V_2 , V_4 -> V_203 ) ;
F_47 ( V_4 , V_8 -> V_252 ,
V_238 | V_94 ) ;
F_117 ( V_2 , V_4 ) ;
}
F_210 ( V_2 , F_61 ( V_2 ) , V_383 ) ;
}
void F_243 ( struct V_1 * V_2 , T_10 V_438 )
{
struct V_3 * V_4 ;
V_4 = F_244 ( V_328 , V_438 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_439 ) ;
return;
}
F_242 ( V_4 , V_328 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_238 | V_440 ) ;
F_98 ( & V_4 -> V_217 ) ;
if ( F_96 ( V_2 , V_4 , 0 , V_438 ) )
F_34 ( F_9 ( V_2 ) , V_439 ) ;
F_245 ( F_9 ( V_2 ) , V_441 ) ;
}
int F_246 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_183 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_64 & V_93 ) ) {
F_247 ( L_2 , V_442 ) ;
return - V_443 ;
}
if ( ! ( F_5 ( V_4 ) -> V_64 & V_238 ) ) {
if ( F_99 ( V_4 ) ) {
struct V_3 * V_353 = F_248 ( V_4 , V_180 ) ;
if ( ! V_353 )
return - V_283 ;
F_192 ( V_4 , V_2 ) ;
F_118 ( V_353 ) ;
F_249 ( V_2 , V_353 ) ;
F_193 ( V_2 , V_4 ) ;
V_2 -> V_253 += V_353 -> V_203 ;
F_120 ( V_2 , V_353 -> V_203 ) ;
V_4 = V_353 ;
}
F_5 ( V_4 ) -> V_64 |= V_238 ;
F_36 ( V_2 , V_4 ) ;
}
return F_96 ( V_2 , V_4 , 1 , V_180 ) ;
}
struct V_3 * F_250 ( const struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_132 * V_133 ,
enum V_444 V_445 )
{
struct V_165 * V_166 = F_43 ( V_75 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_142 * V_143 = NULL ;
struct V_98 V_99 ;
struct V_3 * V_4 ;
int V_215 ;
struct V_76 * V_77 ;
T_6 V_446 ;
int V_19 ;
V_4 = F_244 ( V_328 , V_180 ) ;
if ( F_51 ( ! V_4 ) ) {
F_251 ( V_18 ) ;
return NULL ;
}
F_242 ( V_4 , V_328 ) ;
switch ( V_445 ) {
case V_447 :
F_252 ( V_4 , F_253 ( V_75 ) ) ;
break;
case V_448 :
break;
case V_449 :
F_252 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_254 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
V_446 = F_255 ( V_8 -> V_58 . V_446 ) ;
if ( V_446 && V_446 < V_19 )
V_19 = V_446 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
#ifdef F_256
if ( F_51 ( V_75 -> V_450 ) )
V_4 -> V_217 . V_451 = F_257 ( V_75 ) ;
else
#endif
F_98 ( & V_4 -> V_217 ) ;
#ifdef F_55
F_258 () ;
V_143 = F_259 ( V_75 ) -> V_149 -> V_452 ( V_2 , F_253 ( V_75 ) ) ;
#endif
F_260 ( V_4 , F_259 ( V_75 ) -> V_453 , V_454 ) ;
V_215 = F_57 ( V_75 , V_19 , V_4 , & V_99 , V_143 , V_133 ) +
sizeof( * V_77 ) ;
F_104 ( V_4 , V_215 ) ;
F_105 ( V_4 ) ;
V_77 = (struct V_76 * ) V_4 -> V_181 ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_455 = 1 ;
V_77 -> V_456 = 1 ;
F_42 ( V_75 , V_77 ) ;
V_77 -> V_224 = F_110 ( V_166 -> V_457 ) ;
V_77 -> V_226 = V_166 -> V_458 ;
F_47 ( V_4 , F_259 ( V_75 ) -> V_459 ,
V_93 | V_238 ) ;
V_77 -> V_82 = F_52 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_228 = F_52 ( F_259 ( V_75 ) -> V_60 ) ;
V_77 -> V_234 = F_110 ( F_20 ( V_75 -> V_460 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_77 + 1 ) , NULL , & V_99 ) ;
V_77 -> V_461 = ( V_215 >> 2 ) ;
F_261 ( F_9 ( V_2 ) , V_240 ) ;
#ifdef F_55
if ( V_143 )
F_259 ( V_75 ) -> V_149 -> V_236 ( V_99 . V_105 ,
V_143 , F_253 ( V_75 ) , V_4 ) ;
F_262 () ;
#endif
V_4 -> V_244 . V_245 = 0 ;
return V_4 ;
}
static void F_263 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_462 * V_463 ;
T_4 V_464 = F_264 ( V_18 , V_465 ) ;
if ( V_464 == V_466 )
return;
F_258 () ;
V_463 = F_265 ( V_464 ) ;
if ( F_53 ( V_463 && F_266 ( V_463 -> V_467 ) ) ) {
F_267 ( V_6 -> V_468 -> V_467 ) ;
V_6 -> V_469 = F_268 ( V_18 ) ;
V_6 -> V_468 = V_463 ;
}
F_262 () ;
}
static void F_269 ( struct V_1 * V_2 )
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
if ( V_8 -> V_58 . V_446 )
V_8 -> V_58 . V_296 = V_8 -> V_58 . V_446 ;
V_8 -> V_470 = 0 ;
F_157 ( V_2 ) ;
F_158 ( V_2 , F_160 ( V_18 ) ) ;
F_263 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_264 ( V_18 , V_471 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_58 . V_446 && V_8 -> V_58 . V_446 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_58 . V_446 ;
F_270 ( V_2 ) ;
if ( V_2 -> V_472 & V_473 &&
( V_8 -> V_45 > F_215 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_215 ( V_2 ) ;
F_28 ( F_215 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_58 . V_474 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_157 ,
& V_47 ,
F_264 ( V_18 , V_475 ) ) ;
V_8 -> V_58 . V_47 = V_47 ;
V_8 -> V_395 = V_8 -> V_44 ;
V_2 -> V_476 = 0 ;
F_271 ( V_2 , V_477 ) ;
V_8 -> V_348 = 0 ;
F_272 ( V_8 , 0 ) ;
V_8 -> V_95 = V_8 -> V_252 ;
V_8 -> V_321 = V_8 -> V_252 ;
V_8 -> V_96 = V_8 -> V_252 ;
V_8 -> V_11 = V_8 -> V_252 ;
if ( F_53 ( ! V_8 -> V_365 ) )
V_8 -> V_60 = 0 ;
else
V_8 -> V_478 = V_30 ;
V_8 -> V_59 = V_8 -> V_60 ;
V_8 -> V_479 = V_8 -> V_60 ;
F_2 ( V_2 ) -> V_28 = V_377 ;
F_2 ( V_2 ) -> V_480 = 0 ;
F_273 ( V_8 ) ;
}
static void F_274 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_212 * V_213 = F_5 ( V_4 ) ;
V_213 -> V_12 += V_4 -> V_81 ;
F_118 ( V_4 ) ;
F_275 ( V_2 , V_4 ) ;
V_2 -> V_253 += V_4 -> V_203 ;
F_120 ( V_2 , V_4 -> V_203 ) ;
V_8 -> V_252 = V_213 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_276 ( struct V_1 * V_2 , struct V_3 * V_455 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_481 = V_8 -> V_148 ;
int V_482 = 0 , V_49 , V_216 = 0 ;
unsigned long V_483 = 0 ;
struct V_3 * V_484 ;
V_8 -> V_58 . V_296 = V_8 -> V_20 ;
F_277 ( V_2 , & V_8 -> V_58 . V_296 , & V_481 -> V_161 ,
& V_482 , & V_483 ) ;
if ( V_482 > 1 &&
F_278 ( V_485 , V_483 + ( 60 * V_352 << V_482 ) ) ) {
V_481 -> V_161 . V_81 = - 1 ;
goto V_486;
}
if ( V_487 & V_488 )
V_481 -> V_161 . V_81 = - 1 ;
else if ( V_481 -> V_161 . V_81 <= 0 )
goto V_486;
if ( V_8 -> V_58 . V_446 && V_8 -> V_58 . V_446 < V_8 -> V_58 . V_296 )
V_8 -> V_58 . V_296 = V_8 -> V_58 . V_446 ;
V_49 = F_153 ( V_2 , F_2 ( V_2 ) -> V_308 ) -
V_145 ;
V_49 = F_30 ( V_489 , V_49 , V_481 -> V_169 ) ;
V_49 = F_30 ( V_489 , V_49 , F_279 ( V_328 ) ) ;
V_484 = F_137 ( V_2 , V_49 , V_2 -> V_389 , false ) ;
if ( ! V_484 )
goto V_486;
V_484 -> V_89 = V_90 ;
memcpy ( V_484 -> V_246 , V_455 -> V_246 , sizeof( V_455 -> V_246 ) ) ;
if ( V_49 ) {
int V_490 = F_280 ( F_139 ( V_484 , V_49 ) , V_49 ,
& V_481 -> V_181 -> V_491 ) ;
if ( F_51 ( ! V_490 ) ) {
F_281 ( V_484 ) ;
goto V_486;
}
if ( V_490 != V_49 ) {
F_140 ( V_484 , V_490 ) ;
V_49 = V_490 ;
}
}
if ( V_49 == V_481 -> V_169 )
V_481 -> V_181 = NULL ;
V_481 -> V_490 = V_49 ;
F_274 ( V_2 , V_484 ) ;
V_216 = F_96 ( V_2 , V_484 , 1 , V_2 -> V_389 ) ;
V_455 -> V_217 = V_484 -> V_217 ;
F_5 ( V_484 ) -> V_82 ++ ;
F_5 ( V_484 ) -> V_64 = V_238 | V_284 ;
if ( ! V_216 ) {
V_8 -> V_484 = ( V_481 -> V_490 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_492;
}
V_486:
if ( V_481 -> V_161 . V_81 > 0 )
V_481 -> V_161 . V_81 = 0 ;
V_216 = F_96 ( V_2 , V_455 , 1 , V_2 -> V_389 ) ;
if ( V_216 )
V_8 -> V_163 = 0 ;
V_492:
V_481 -> V_161 . V_81 = - 1 ;
return V_216 ;
}
int F_282 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_278 ;
int V_216 ;
F_269 ( V_2 ) ;
if ( F_51 ( V_8 -> V_365 ) ) {
F_283 ( V_2 , NULL ) ;
return 0 ;
}
V_278 = F_137 ( V_2 , 0 , V_2 -> V_389 , true ) ;
if ( F_51 ( ! V_278 ) )
return - V_220 ;
F_47 ( V_278 , V_8 -> V_252 ++ , V_93 ) ;
V_8 -> V_418 = V_30 ;
F_274 ( V_2 , V_278 ) ;
F_39 ( V_2 , V_278 ) ;
V_216 = V_8 -> V_148 ? F_276 ( V_2 , V_278 ) :
F_96 ( V_2 , V_278 , 1 , V_2 -> V_389 ) ;
if ( V_216 == - V_493 )
return V_216 ;
V_8 -> V_11 = V_8 -> V_252 ;
V_8 -> V_494 = V_8 -> V_252 ;
F_245 ( F_9 ( V_2 ) , V_495 ) ;
F_203 ( V_2 , V_375 ,
F_2 ( V_2 ) -> V_28 , V_380 ) ;
return 0 ;
}
void F_284 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_370 ;
F_18 ( V_2 , V_496 ) ;
if ( V_37 > V_497 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_498 = V_352 / 2 ;
if ( V_6 -> V_35 . V_38 ||
( V_6 -> V_35 . V_499 & V_500 ) )
V_498 = V_378 ;
if ( V_8 -> V_349 ) {
int V_373 = F_29 ( int , F_200 ( V_8 -> V_349 >> 3 ) ,
V_497 ) ;
if ( V_373 < V_498 )
V_498 = V_373 ;
}
V_37 = F_20 ( V_37 , V_498 ) ;
}
V_370 = V_485 + V_37 ;
if ( V_6 -> V_35 . V_499 & V_501 ) {
if ( V_6 -> V_35 . V_502 ||
F_285 ( V_6 -> V_35 . V_370 , V_485 + ( V_37 >> 2 ) ) ) {
F_286 ( V_2 ) ;
return;
}
if ( ! F_278 ( V_370 , V_6 -> V_35 . V_370 ) )
V_370 = V_6 -> V_35 . V_370 ;
}
V_6 -> V_35 . V_499 |= V_503 | V_501 ;
V_6 -> V_35 . V_370 = V_370 ;
F_287 ( V_2 , & V_6 -> V_504 , V_370 ) ;
}
void F_286 ( struct V_1 * V_2 )
{
struct V_3 * V_278 ;
if ( V_2 -> V_173 == V_388 )
return;
F_18 ( V_2 , V_505 ) ;
V_278 = F_244 ( V_328 ,
F_211 ( V_2 , V_180 | V_506 ) ) ;
if ( F_51 ( ! V_278 ) ) {
F_288 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_507 ;
F_203 ( V_2 , V_40 ,
V_378 , V_380 ) ;
return;
}
F_242 ( V_278 , V_328 ) ;
F_47 ( V_278 , F_10 ( V_2 ) , V_238 ) ;
F_289 ( V_278 ) ;
F_98 ( & V_278 -> V_217 ) ;
F_96 ( V_2 , V_278 , 0 , ( V_508 T_10 ) 0 ) ;
}
static int F_290 ( struct V_1 * V_2 , int V_509 , int V_510 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_244 ( V_328 ,
F_211 ( V_2 , V_180 | V_506 ) ) ;
if ( ! V_4 )
return - 1 ;
F_242 ( V_4 , V_328 ) ;
F_47 ( V_4 , V_8 -> V_95 - ! V_509 , V_238 ) ;
F_98 ( & V_4 -> V_217 ) ;
F_34 ( F_9 ( V_2 ) , V_510 ) ;
return F_96 ( V_2 , V_4 , 0 , ( V_508 T_10 ) 0 ) ;
}
void F_291 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_511 ) {
F_3 ( V_2 ) -> V_512 = F_3 ( V_2 ) -> V_60 - 1 ;
F_290 ( V_2 , 0 , V_513 ) ;
}
}
int F_292 ( struct V_1 * V_2 , int V_510 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_388 )
return - 1 ;
V_4 = F_177 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_216 ;
unsigned int V_19 = F_61 ( V_2 ) ;
unsigned int V_514 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_494 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_494 = F_5 ( V_4 ) -> V_12 ;
if ( V_514 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_514 = F_20 ( V_514 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_284 ;
if ( F_133 ( V_2 , V_4 , V_514 , V_19 , V_180 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_121 ( V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_284 ;
V_216 = F_96 ( V_2 , V_4 , 1 , V_180 ) ;
if ( ! V_216 )
F_1 ( V_2 , V_4 ) ;
return V_216 ;
} else {
if ( F_293 ( V_8 -> V_96 , V_8 -> V_95 + 1 , V_8 -> V_95 + 0xFFFF ) )
F_290 ( V_2 , 1 , V_510 ) ;
return F_290 ( V_2 , 0 , V_510 ) ;
}
}
void F_294 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_299 * V_299 = F_9 ( V_2 ) ;
unsigned long V_515 ;
int V_216 ;
V_216 = F_292 ( V_2 , V_513 ) ;
if ( V_8 -> V_10 || ! F_177 ( V_2 ) ) {
V_6 -> V_516 = 0 ;
V_6 -> V_517 = 0 ;
return;
}
if ( V_216 <= 0 ) {
if ( V_6 -> V_517 < V_299 -> V_70 . V_518 )
V_6 -> V_517 ++ ;
V_6 -> V_516 ++ ;
V_515 = V_380 ;
} else {
if ( ! V_6 -> V_516 )
V_6 -> V_516 = 1 ;
V_515 = V_519 ;
}
F_203 ( V_2 , V_520 ,
F_295 ( V_2 , V_515 ) ,
V_380 ) ;
}
int F_296 ( const struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_521 * V_522 = F_259 ( V_75 ) -> V_149 ;
struct V_523 V_251 ;
int V_524 ;
F_259 ( V_75 ) -> V_453 = F_297 () ;
V_524 = V_522 -> V_525 ( V_2 , NULL , & V_251 , V_75 , NULL , V_447 ) ;
if ( ! V_524 ) {
F_261 ( F_9 ( V_2 ) , V_413 ) ;
F_230 ( F_9 ( V_2 ) , V_414 ) ;
if ( F_51 ( F_298 ( V_2 ) ) )
F_3 ( V_2 ) -> V_415 ++ ;
}
return V_524 ;
}
