static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_9 = V_8 -> V_10 ;
F_4 ( V_2 , V_4 ) ;
V_8 -> V_11 = F_5 ( V_4 ) -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
if ( ! V_9 || V_6 -> V_13 == V_14 )
F_7 ( V_2 ) ;
F_8 ( F_9 ( V_2 ) , V_15 ,
F_6 ( V_4 ) ) ;
}
static inline T_1 F_10 ( const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( F_12 ( V_8 ) , V_8 -> V_11 ) ||
( V_8 -> V_16 . V_17 &&
( ( V_8 -> V_11 - F_12 ( V_8 ) ) < ( 1 << V_8 -> V_16 . V_18 ) ) ) )
return V_8 -> V_11 ;
else
return F_12 ( V_8 ) ;
}
static T_2 F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_19 * V_20 = F_14 ( V_2 ) ;
int V_21 = V_8 -> V_22 ;
if ( V_20 ) {
unsigned int V_23 = F_15 ( V_20 ) ;
if ( V_23 < V_21 ) {
V_21 = V_23 ;
V_8 -> V_22 = V_21 ;
}
}
return ( T_2 ) V_21 ;
}
void F_16 ( struct V_1 * V_2 , T_3 V_24 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_25 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_26 = V_8 -> V_27 ;
F_18 ( V_2 , V_28 ) ;
V_8 -> V_29 = F_19 ( V_2 ) ;
V_25 = F_20 ( V_25 , V_26 ) ;
while ( ( V_24 -= F_2 ( V_2 ) -> V_30 ) > 0 && V_26 > V_25 )
V_26 >>= 1 ;
V_8 -> V_27 = F_21 ( V_26 , V_25 ) ;
V_8 -> V_31 = V_32 ;
V_8 -> V_33 = 0 ;
}
static void F_22 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_4 V_34 = V_32 ;
if ( F_23 ( V_8 ) == 0 )
F_18 ( V_2 , V_35 ) ;
V_8 -> V_36 = V_34 ;
if ( ( T_4 ) ( V_34 - V_6 -> V_37 . V_38 ) < V_6 -> V_37 . V_39 )
V_6 -> V_37 . V_40 = 1 ;
}
static inline void F_24 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_25 ( V_2 , V_41 ) ;
F_26 ( V_2 , V_42 ) ;
}
T_4 F_27 ( T_4 V_21 )
{
T_4 V_43 = V_44 * 2 ;
if ( V_21 > 1460 )
V_43 = F_21 ( ( 1460 * V_43 ) / V_21 , 2U ) ;
return V_43 ;
}
void F_28 ( int V_45 , T_1 V_21 ,
T_1 * V_46 , T_1 * V_47 ,
int V_17 , T_5 * V_18 ,
T_1 V_48 )
{
unsigned int V_49 = ( V_45 < 0 ? 0 : V_45 ) ;
if ( * V_47 == 0 )
( * V_47 ) = ( 65535 << 14 ) ;
V_49 = F_20 ( * V_47 , V_49 ) ;
if ( V_49 > V_21 )
V_49 = ( V_49 / V_21 ) * V_21 ;
if ( V_50 )
( * V_46 ) = F_20 ( V_49 , V_51 ) ;
else
( * V_46 ) = V_49 ;
( * V_18 ) = 0 ;
if ( V_17 ) {
V_49 = F_29 ( T_4 , V_49 , V_52 [ 2 ] ) ;
V_49 = F_29 ( T_4 , V_49 , V_53 ) ;
V_49 = F_30 ( T_4 , V_49 , * V_47 ) ;
while ( V_49 > 65535 && ( * V_18 ) < 14 ) {
V_49 >>= 1 ;
( * V_18 ) ++ ;
}
}
if ( V_21 > ( 1 << * V_18 ) ) {
if ( ! V_48 )
V_48 = F_27 ( V_21 ) ;
* V_46 = F_20 ( * V_46 , V_48 * V_21 ) ;
}
( * V_47 ) = F_20 ( 65535U << ( * V_18 ) , * V_47 ) ;
}
static T_6 F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_54 = V_8 -> V_46 ;
T_4 V_55 = F_32 ( V_8 ) ;
T_4 V_56 = F_33 ( V_2 ) ;
if ( V_56 < V_55 ) {
if ( V_56 == 0 )
F_34 ( F_9 ( V_2 ) ,
V_57 ) ;
V_56 = F_35 ( V_55 , 1 << V_8 -> V_16 . V_18 ) ;
}
V_8 -> V_46 = V_56 ;
V_8 -> V_58 = V_8 -> V_59 ;
if ( ! V_8 -> V_16 . V_18 && V_50 )
V_56 = F_20 ( V_56 , V_51 ) ;
else
V_56 = F_20 ( V_56 , ( 65535U << V_8 -> V_16 . V_18 ) ) ;
V_56 >>= V_8 -> V_16 . V_18 ;
if ( V_56 == 0 ) {
V_8 -> V_60 = 0 ;
if ( V_54 )
F_34 ( F_9 ( V_2 ) ,
V_61 ) ;
} else if ( V_54 == 0 ) {
F_34 ( F_9 ( V_2 ) , V_62 ) ;
}
return V_56 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
F_5 ( V_4 ) -> V_63 &= ~ V_64 ;
if ( ! ( V_8 -> V_65 & V_66 ) )
F_5 ( V_4 ) -> V_63 &= ~ V_67 ;
else if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
bool V_68 = F_9 ( V_2 ) -> V_69 . V_70 == 1 ||
F_37 ( V_2 ) ;
if ( ! V_68 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_40 ( V_20 , V_71 ) )
V_68 = true ;
}
V_8 -> V_65 = 0 ;
if ( V_68 ) {
F_5 ( V_4 ) -> V_63 |= V_67 | V_64 ;
V_8 -> V_65 = V_66 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_9 ( V_2 ) -> V_69 . V_72 )
F_5 ( V_4 ) -> V_63 &= ~ ( V_67 | V_64 ) ;
}
static void
F_42 ( const struct V_73 * V_74 , struct V_75 * V_76 )
{
if ( F_43 ( V_74 ) -> V_77 )
V_76 -> V_78 = 1 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_75 * V_76 , int V_79 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_65 & V_66 ) {
if ( V_4 -> V_80 != V_79 &&
! F_11 ( F_5 ( V_4 ) -> V_81 , V_8 -> V_11 ) ) {
F_38 ( V_2 ) ;
if ( V_8 -> V_65 & V_82 ) {
V_8 -> V_65 &= ~ V_82 ;
V_76 -> V_83 = 1 ;
F_45 ( V_4 ) -> V_84 |= V_85 ;
}
} else if ( ! F_37 ( V_2 ) ) {
F_46 ( V_2 ) ;
}
if ( V_8 -> V_65 & V_86 )
V_76 -> V_78 = 1 ;
}
}
static void F_47 ( struct V_3 * V_4 , T_4 V_81 , T_7 V_87 )
{
V_4 -> V_88 = V_89 ;
V_4 -> V_90 = 0 ;
F_5 ( V_4 ) -> V_63 = V_87 ;
F_5 ( V_4 ) -> V_91 = 0 ;
F_48 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_81 = V_81 ;
if ( V_87 & ( V_92 | V_93 ) )
V_81 ++ ;
F_5 ( V_4 ) -> V_12 = V_81 ;
}
static inline bool F_49 ( const struct V_7 * V_8 )
{
return V_8 -> V_94 != V_8 -> V_95 ;
}
static void F_50 ( T_8 * V_96 , struct V_7 * V_8 ,
struct V_97 * V_98 )
{
T_6 V_99 = V_98 -> V_99 ;
if ( F_51 ( V_100 & V_99 ) ) {
* V_96 ++ = F_52 ( ( V_101 << 24 ) | ( V_101 << 16 ) |
( V_102 << 8 ) | V_103 ) ;
V_98 -> V_104 = ( T_5 * ) V_96 ;
V_96 += 4 ;
}
if ( F_51 ( V_98 -> V_21 ) ) {
* V_96 ++ = F_52 ( ( V_105 << 24 ) |
( V_106 << 16 ) |
V_98 -> V_21 ) ;
}
if ( F_53 ( V_107 & V_99 ) ) {
if ( F_51 ( V_108 & V_99 ) ) {
* V_96 ++ = F_52 ( ( V_109 << 24 ) |
( V_110 << 16 ) |
( V_111 << 8 ) |
V_112 ) ;
V_99 &= ~ V_108 ;
} else {
* V_96 ++ = F_52 ( ( V_101 << 24 ) |
( V_101 << 16 ) |
( V_111 << 8 ) |
V_112 ) ;
}
* V_96 ++ = F_52 ( V_98 -> V_113 ) ;
* V_96 ++ = F_52 ( V_98 -> V_114 ) ;
}
if ( F_51 ( V_108 & V_99 ) ) {
* V_96 ++ = F_52 ( ( V_101 << 24 ) |
( V_101 << 16 ) |
( V_109 << 8 ) |
V_110 ) ;
}
if ( F_51 ( V_115 & V_99 ) ) {
* V_96 ++ = F_52 ( ( V_101 << 24 ) |
( V_116 << 16 ) |
( V_117 << 8 ) |
V_98 -> V_118 ) ;
}
if ( F_51 ( V_98 -> V_119 ) ) {
struct V_120 * V_121 = V_8 -> V_16 . V_122 ?
V_8 -> V_123 : V_8 -> V_124 ;
int V_125 ;
* V_96 ++ = F_52 ( ( V_101 << 24 ) |
( V_101 << 16 ) |
( V_126 << 8 ) |
( V_127 + ( V_98 -> V_119 *
V_128 ) ) ) ;
for ( V_125 = 0 ; V_125 < V_98 -> V_119 ;
++ V_125 ) {
* V_96 ++ = F_52 ( V_121 [ V_125 ] . V_129 ) ;
* V_96 ++ = F_52 ( V_121 [ V_125 ] . V_12 ) ;
}
V_8 -> V_16 . V_122 = 0 ;
}
if ( F_51 ( V_130 & V_99 ) ) {
struct V_131 * V_132 = V_98 -> V_133 ;
T_7 * V_134 = ( T_7 * ) V_96 ;
T_4 V_80 ;
if ( V_132 -> exp ) {
V_80 = V_135 + V_132 -> V_80 ;
* V_96 = F_52 ( ( V_136 << 24 ) | ( V_80 << 16 ) |
V_137 ) ;
V_134 += V_135 ;
} else {
V_80 = V_138 + V_132 -> V_80 ;
* V_134 ++ = V_139 ;
* V_134 ++ = V_80 ;
}
memcpy ( V_134 , V_132 -> V_140 , V_132 -> V_80 ) ;
if ( ( V_80 & 3 ) == 2 ) {
V_134 [ V_132 -> V_80 ] = V_101 ;
V_134 [ V_132 -> V_80 + 1 ] = V_101 ;
}
V_96 += ( V_80 + 3 ) >> 2 ;
}
}
static unsigned int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_97 * V_98 ,
struct V_141 * * V_142 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_143 = V_144 ;
struct V_145 * V_146 = V_8 -> V_147 ;
#ifdef F_55
* V_142 = V_8 -> V_148 -> V_149 ( V_2 , V_2 ) ;
if ( * V_142 ) {
V_98 -> V_99 |= V_100 ;
V_143 -= V_150 ;
}
#else
* V_142 = NULL ;
#endif
V_98 -> V_21 = F_13 ( V_2 ) ;
V_143 -= V_151 ;
if ( F_53 ( V_152 && ! * V_142 ) ) {
V_98 -> V_99 |= V_107 ;
V_98 -> V_113 = F_56 ( V_4 ) + V_8 -> V_153 ;
V_98 -> V_114 = V_8 -> V_16 . V_154 ;
V_143 -= V_155 ;
}
if ( F_53 ( V_156 ) ) {
V_98 -> V_118 = V_8 -> V_16 . V_18 ;
V_98 -> V_99 |= V_115 ;
V_143 -= V_157 ;
}
if ( F_53 ( V_158 ) ) {
V_98 -> V_99 |= V_108 ;
if ( F_51 ( ! ( V_107 & V_98 -> V_99 ) ) )
V_143 -= V_159 ;
}
if ( V_146 && V_146 -> V_160 . V_80 >= 0 ) {
T_4 V_161 = V_146 -> V_160 . V_80 ;
V_161 += V_146 -> V_160 . exp ? V_135 :
V_138 ;
V_161 = ( V_161 + 3 ) & ~ 3U ;
if ( V_143 >= V_161 ) {
V_98 -> V_99 |= V_130 ;
V_98 -> V_133 = & V_146 -> V_160 ;
V_143 -= V_161 ;
V_8 -> V_162 = 1 ;
V_8 -> V_163 = V_146 -> V_160 . exp ? 1 : 0 ;
}
}
return V_144 - V_143 ;
}
static unsigned int F_57 ( struct V_73 * V_74 ,
unsigned int V_21 , struct V_3 * V_4 ,
struct V_97 * V_98 ,
const struct V_141 * V_142 ,
struct V_131 * V_132 )
{
struct V_164 * V_165 = F_43 ( V_74 ) ;
unsigned int V_143 = V_144 ;
#ifdef F_55
if ( V_142 ) {
V_98 -> V_99 |= V_100 ;
V_143 -= V_150 ;
V_165 -> V_166 &= ! V_165 -> V_167 ;
}
#endif
V_98 -> V_21 = V_21 ;
V_143 -= V_151 ;
if ( F_53 ( V_165 -> V_17 ) ) {
V_98 -> V_118 = V_165 -> V_18 ;
V_98 -> V_99 |= V_115 ;
V_143 -= V_157 ;
}
if ( F_53 ( V_165 -> V_166 ) ) {
V_98 -> V_99 |= V_107 ;
V_98 -> V_113 = F_56 ( V_4 ) + F_58 ( V_74 ) -> V_168 ;
V_98 -> V_114 = V_74 -> V_154 ;
V_143 -= V_155 ;
}
if ( F_53 ( V_165 -> V_167 ) ) {
V_98 -> V_99 |= V_108 ;
if ( F_51 ( ! V_165 -> V_166 ) )
V_143 -= V_159 ;
}
if ( V_132 != NULL && V_132 -> V_80 >= 0 ) {
T_4 V_161 = V_132 -> V_80 ;
V_161 += V_132 -> exp ? V_135 :
V_138 ;
V_161 = ( V_161 + 3 ) & ~ 3U ;
if ( V_143 >= V_161 ) {
V_98 -> V_99 |= V_130 ;
V_98 -> V_133 = V_132 ;
V_143 -= V_161 ;
}
}
return V_144 - V_143 ;
}
static unsigned int F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_97 * V_98 ,
struct V_141 * * V_142 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_169 = 0 ;
unsigned int V_170 ;
V_98 -> V_99 = 0 ;
#ifdef F_55
* V_142 = V_8 -> V_148 -> V_149 ( V_2 , V_2 ) ;
if ( F_51 ( * V_142 ) ) {
V_98 -> V_99 |= V_100 ;
V_169 += V_150 ;
}
#else
* V_142 = NULL ;
#endif
if ( F_53 ( V_8 -> V_16 . V_166 ) ) {
V_98 -> V_99 |= V_107 ;
V_98 -> V_113 = V_4 ? F_56 ( V_4 ) + V_8 -> V_153 : 0 ;
V_98 -> V_114 = V_8 -> V_16 . V_154 ;
V_169 += V_155 ;
}
V_170 = V_8 -> V_16 . V_171 + V_8 -> V_16 . V_122 ;
if ( F_51 ( V_170 ) ) {
const unsigned int V_143 = V_144 - V_169 ;
V_98 -> V_119 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_169 += V_172 +
V_98 -> V_119 * V_128 ;
}
return V_169 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_173 ) &
( V_174 | V_175 | V_176 |
V_177 | V_178 ) ) {
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_179 > V_8 -> V_180 &&
V_8 -> V_27 > F_23 ( V_8 ) )
F_61 ( V_2 ) ;
F_62 ( V_2 , F_63 ( V_2 ) , V_8 -> V_181 ,
0 , V_182 ) ;
}
}
static void F_64 ( unsigned long V_183 )
{
struct V_184 * V_185 = (struct V_184 * ) V_183 ;
F_65 ( V_186 ) ;
unsigned long V_87 ;
struct V_187 * V_188 , * V_189 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_66 ( V_87 ) ;
F_67 ( & V_185 -> V_190 , & V_186 ) ;
F_68 ( V_87 ) ;
F_69 (q, n, &list) {
V_8 = F_70 ( V_188 , struct V_7 , V_191 ) ;
F_71 ( & V_8 -> V_191 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_72 () ;
F_73 ( V_192 , & V_2 -> V_193 ) ;
if ( ! V_2 -> V_194 . V_195 &&
F_74 ( V_196 , & V_2 -> V_193 ) ) {
F_75 ( V_2 ) ;
if ( ! F_76 ( V_2 ) ) {
F_73 ( V_196 , & V_2 -> V_193 ) ;
F_60 ( V_2 ) ;
}
F_77 ( V_2 ) ;
}
F_78 ( V_2 ) ;
}
}
void F_79 ( struct V_1 * V_2 )
{
unsigned long V_87 , V_197 ;
do {
V_87 = V_2 -> V_193 ;
if ( ! ( V_87 & V_198 ) )
return;
V_197 = V_87 & ~ V_198 ;
} while ( F_80 ( & V_2 -> V_193 , V_87 , V_197 ) != V_87 );
if ( V_87 & V_199 )
F_60 ( V_2 ) ;
F_81 ( V_2 ) ;
if ( V_87 & V_200 ) {
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
}
if ( V_87 & V_201 ) {
F_84 ( V_2 ) ;
F_83 ( V_2 ) ;
}
if ( V_87 & V_202 ) {
F_2 ( V_2 ) -> V_203 -> V_204 ( V_2 ) ;
F_83 ( V_2 ) ;
}
}
void T_9 F_85 ( void )
{
int V_205 ;
F_86 (i) {
struct V_184 * V_185 = & F_87 ( V_184 , V_205 ) ;
F_88 ( & V_185 -> V_190 ) ;
F_89 ( & V_185 -> V_206 ,
F_64 ,
( unsigned long ) V_185 ) ;
}
}
void F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_87 , V_207 , V_208 ;
int V_209 ;
V_209 = F_91 ( V_4 -> V_210 - 1 , & V_2 -> V_211 ) ;
if ( V_209 >= F_92 ( 1 ) && F_93 () == V_212 )
goto V_213;
for ( V_208 = F_94 ( V_2 -> V_193 ) ; ; V_208 = V_207 ) {
struct V_184 * V_185 ;
bool V_214 ;
if ( ! ( V_208 & V_215 ) || ( V_208 & V_216 ) )
goto V_213;
V_207 = ( V_208 & ~ V_215 ) | V_216 | V_199 ;
V_207 = F_80 ( & V_2 -> V_193 , V_208 , V_207 ) ;
if ( V_207 != V_208 )
continue;
F_66 ( V_87 ) ;
V_185 = F_95 ( & V_184 ) ;
V_214 = F_96 ( & V_185 -> V_190 ) ;
F_97 ( & V_8 -> V_191 , & V_185 -> V_190 ) ;
if ( V_214 )
F_98 ( & V_185 -> V_206 ) ;
F_68 ( V_87 ) ;
return;
}
V_213:
F_78 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_217 ,
T_10 V_218 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_219 * V_220 ;
struct V_7 * V_8 ;
struct V_221 * V_222 ;
struct V_97 V_98 ;
unsigned int V_223 , V_224 ;
struct V_141 * V_142 ;
struct V_75 * V_76 ;
int V_225 ;
F_100 ( ! V_4 || ! F_6 ( V_4 ) ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_217 ) {
F_101 ( & V_4 -> V_226 ) ;
F_5 ( V_4 ) -> V_227 . V_228 = F_5 ( V_4 ) -> V_12
- V_8 -> V_94 ;
F_102 ( V_2 , V_4 ) ;
if ( F_51 ( F_103 ( V_4 ) ) )
V_4 = F_104 ( V_4 , V_218 ) ;
else
V_4 = F_105 ( V_4 , V_218 ) ;
if ( F_51 ( ! V_4 ) )
return - V_229 ;
}
V_220 = F_106 ( V_2 ) ;
V_222 = F_5 ( V_4 ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
if ( F_51 ( V_222 -> V_63 & V_92 ) )
V_223 = F_54 ( V_2 , V_4 , & V_98 , & V_142 ) ;
else
V_223 = F_59 ( V_2 , V_4 , & V_98 ,
& V_142 ) ;
V_224 = V_223 + sizeof( struct V_75 ) ;
V_4 -> V_230 = F_107 ( V_2 ) < F_92 ( 1 ) ;
V_4 -> V_231 = 0 ;
F_108 ( V_4 , V_224 ) ;
F_109 ( V_4 ) ;
F_110 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_232 = F_111 ( V_4 ) ? V_233 : F_90 ;
F_112 ( V_4 , V_2 ) ;
F_113 ( V_4 -> V_210 , & V_2 -> V_211 ) ;
F_114 ( V_4 , V_2 -> V_234 ) ;
V_76 = (struct V_75 * ) V_4 -> V_183 ;
V_76 -> V_235 = V_220 -> V_236 ;
V_76 -> V_237 = V_220 -> V_238 ;
V_76 -> V_81 = F_52 ( V_222 -> V_81 ) ;
V_76 -> V_239 = F_52 ( V_8 -> V_59 ) ;
* ( ( ( V_240 * ) V_76 ) + 6 ) = F_115 ( ( ( V_224 >> 2 ) << 12 ) |
V_222 -> V_63 ) ;
V_76 -> V_241 = 0 ;
V_76 -> V_242 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_222 -> V_81 , V_8 -> V_95 ) ) ) {
if ( F_11 ( V_8 -> V_95 , V_222 -> V_81 + 0x10000 ) ) {
V_76 -> V_242 = F_115 ( V_8 -> V_95 - V_222 -> V_81 ) ;
V_76 -> V_243 = 1 ;
} else if ( F_116 ( V_222 -> V_81 + 0xFFFF , V_8 -> V_11 ) ) {
V_76 -> V_242 = F_115 ( 0xFFFF ) ;
V_76 -> V_243 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_76 + 1 ) , V_8 , & V_98 ) ;
F_45 ( V_4 ) -> V_84 = V_2 -> V_244 ;
if ( F_53 ( ! ( V_222 -> V_63 & V_92 ) ) ) {
V_76 -> V_245 = F_115 ( F_31 ( V_2 ) ) ;
F_44 ( V_2 , V_4 , V_76 , V_224 ) ;
} else {
V_76 -> V_245 = F_115 ( F_20 ( V_8 -> V_46 , 65535U ) ) ;
}
#ifdef F_55
if ( V_142 ) {
F_117 ( V_2 , V_246 ) ;
V_8 -> V_148 -> V_247 ( V_98 . V_104 ,
V_142 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_203 -> V_248 ( V_2 , V_4 ) ;
if ( F_53 ( V_222 -> V_63 & V_249 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_80 != V_224 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_250 += F_6 ( V_4 ) ;
}
if ( F_116 ( V_222 -> V_12 , V_8 -> V_11 ) || V_222 -> V_81 == V_222 -> V_12 )
F_118 ( F_9 ( V_2 ) , V_251 ,
F_6 ( V_4 ) ) ;
V_8 -> V_252 += F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_253 = F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_254 = F_119 ( V_4 ) ;
V_4 -> V_255 = 0 ;
memset ( V_4 -> V_256 , 0 , F_21 ( sizeof( struct V_257 ) ,
sizeof( struct V_258 ) ) ) ;
V_225 = V_6 -> V_203 -> V_259 ( V_2 , V_4 , & V_220 -> V_260 . V_261 ) ;
if ( F_53 ( V_225 <= 0 ) )
return V_225 ;
F_120 ( V_2 ) ;
return F_121 ( V_225 ) ;
}
static void F_122 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_262 = F_5 ( V_4 ) -> V_12 ;
F_123 ( V_4 ) ;
F_124 ( V_2 , V_4 ) ;
V_2 -> V_263 += V_4 -> V_210 ;
F_125 ( V_2 , V_4 -> V_210 ) ;
}
static void F_126 ( struct V_3 * V_4 , unsigned int V_264 )
{
if ( V_4 -> V_80 <= V_264 || V_4 -> V_88 == V_265 ) {
F_48 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_266 = 0 ;
} else {
F_48 ( V_4 , F_127 ( V_4 -> V_80 , V_264 ) ) ;
F_5 ( V_4 ) -> V_266 = V_264 ;
}
}
static void F_128 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_267 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_268 || F_129 ( V_8 ) )
return;
if ( F_116 ( F_130 ( V_8 ) , F_5 ( V_4 ) -> V_81 ) )
V_8 -> V_269 -= V_267 ;
}
static void F_131 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_267 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_267 ;
if ( F_5 ( V_4 ) -> V_91 & V_270 )
V_8 -> V_268 -= V_267 ;
if ( F_5 ( V_4 ) -> V_91 & V_271 )
V_8 -> V_180 -= V_267 ;
if ( F_5 ( V_4 ) -> V_91 & V_272 )
V_8 -> V_179 -= V_267 ;
if ( F_129 ( V_8 ) && V_267 > 0 )
V_8 -> V_268 -= F_30 ( T_4 , V_8 -> V_268 , V_267 ) ;
F_128 ( V_2 , V_4 , V_267 ) ;
if ( V_8 -> V_273 &&
F_11 ( F_5 ( V_4 ) -> V_81 , F_5 ( V_8 -> V_273 ) -> V_81 ) &&
( F_132 ( V_8 ) || ( F_5 ( V_4 ) -> V_91 & V_270 ) ) )
V_8 -> V_274 -= V_267 ;
F_133 ( V_8 ) ;
}
static bool F_134 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_275 ||
( F_45 ( V_4 ) -> V_276 & V_277 ) ;
}
static void F_135 ( struct V_3 * V_4 , struct V_3 * V_278 )
{
struct V_279 * V_280 = F_45 ( V_4 ) ;
if ( F_51 ( F_134 ( V_4 ) ) &&
! F_11 ( V_280 -> V_281 , F_5 ( V_278 ) -> V_81 ) ) {
struct V_279 * V_282 = F_45 ( V_278 ) ;
T_7 V_283 = V_280 -> V_276 & V_277 ;
V_280 -> V_276 &= ~ V_283 ;
V_282 -> V_276 |= V_283 ;
F_136 ( V_280 -> V_281 , V_282 -> V_281 ) ;
F_5 ( V_278 ) -> V_275 = F_5 ( V_4 ) -> V_275 ;
F_5 ( V_4 ) -> V_275 = 0 ;
}
}
static void F_137 ( struct V_3 * V_4 , struct V_3 * V_278 )
{
F_5 ( V_278 ) -> V_284 = F_5 ( V_4 ) -> V_284 ;
F_5 ( V_4 ) -> V_284 = 0 ;
}
int F_138 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_80 ,
unsigned int V_264 , T_10 V_285 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_286 ;
int V_287 , V_288 ;
int V_289 ;
T_7 V_87 ;
if ( F_139 ( V_80 > V_4 -> V_80 ) )
return - V_290 ;
V_287 = F_140 ( V_4 ) - V_80 ;
if ( V_287 < 0 )
V_287 = 0 ;
if ( F_141 ( V_4 , V_285 ) )
return - V_291 ;
V_286 = F_142 ( V_2 , V_287 , V_285 , true ) ;
if ( ! V_286 )
return - V_291 ;
V_2 -> V_263 += V_286 -> V_210 ;
F_125 ( V_2 , V_286 -> V_210 ) ;
V_289 = V_4 -> V_80 - V_80 - V_287 ;
V_286 -> V_210 += V_289 ;
V_4 -> V_210 -= V_289 ;
F_5 ( V_286 ) -> V_81 = F_5 ( V_4 ) -> V_81 + V_80 ;
F_5 ( V_286 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_286 ) -> V_81 ;
V_87 = F_5 ( V_4 ) -> V_63 ;
F_5 ( V_4 ) -> V_63 = V_87 & ~ ( V_93 | V_292 ) ;
F_5 ( V_286 ) -> V_63 = V_87 ;
F_5 ( V_286 ) -> V_91 = F_5 ( V_4 ) -> V_91 ;
F_137 ( V_4 , V_286 ) ;
if ( ! F_45 ( V_4 ) -> V_293 && V_4 -> V_88 != V_89 ) {
V_286 -> V_90 = F_143 ( V_4 -> V_183 + V_80 ,
F_144 ( V_286 , V_287 ) ,
V_287 , 0 ) ;
F_145 ( V_4 , V_80 ) ;
V_4 -> V_90 = F_146 ( V_4 -> V_90 , V_286 -> V_90 , V_80 ) ;
} else {
V_4 -> V_88 = V_89 ;
F_147 ( V_4 , V_286 , V_80 ) ;
}
V_286 -> V_88 = V_4 -> V_88 ;
V_286 -> V_255 = V_4 -> V_255 ;
F_135 ( V_4 , V_286 ) ;
V_288 = F_6 ( V_4 ) ;
F_126 ( V_4 , V_264 ) ;
F_126 ( V_286 , V_264 ) ;
F_5 ( V_286 ) -> V_227 = F_5 ( V_4 ) -> V_227 ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_286 ) -> V_12 ) ) {
int V_294 = V_288 - F_6 ( V_4 ) -
F_6 ( V_286 ) ;
if ( V_294 )
F_131 ( V_2 , V_4 , V_294 ) ;
}
F_123 ( V_286 ) ;
F_148 ( V_4 , V_286 , V_2 ) ;
return 0 ;
}
static int F_149 ( struct V_3 * V_4 , int V_80 )
{
struct V_279 * V_280 ;
int V_205 , V_295 , V_296 ;
V_296 = F_30 ( int , V_80 , F_140 ( V_4 ) ) ;
if ( V_296 ) {
F_150 ( V_4 , V_296 ) ;
V_80 -= V_296 ;
if ( ! V_80 )
return 0 ;
}
V_296 = V_80 ;
V_295 = 0 ;
V_280 = F_45 ( V_4 ) ;
for ( V_205 = 0 ; V_205 < V_280 -> V_293 ; V_205 ++ ) {
int V_169 = F_151 ( & V_280 -> V_297 [ V_205 ] ) ;
if ( V_169 <= V_296 ) {
F_152 ( V_4 , V_205 ) ;
V_296 -= V_169 ;
} else {
V_280 -> V_297 [ V_295 ] = V_280 -> V_297 [ V_205 ] ;
if ( V_296 ) {
V_280 -> V_297 [ V_295 ] . V_298 += V_296 ;
F_153 ( & V_280 -> V_297 [ V_295 ] , V_296 ) ;
V_296 = 0 ;
}
V_295 ++ ;
}
}
V_280 -> V_293 = V_295 ;
F_154 ( V_4 ) ;
V_4 -> V_299 -= V_80 ;
V_4 -> V_80 = V_4 -> V_299 ;
return V_80 ;
}
int F_155 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_80 )
{
T_4 V_300 ;
if ( F_141 ( V_4 , V_182 ) )
return - V_291 ;
V_300 = F_149 ( V_4 , V_80 ) ;
F_5 ( V_4 ) -> V_81 += V_80 ;
V_4 -> V_88 = V_89 ;
if ( V_300 ) {
V_4 -> V_210 -= V_300 ;
V_2 -> V_263 -= V_300 ;
F_156 ( V_2 , V_300 ) ;
F_157 ( V_2 , V_301 ) ;
}
if ( F_6 ( V_4 ) > 1 )
F_126 ( V_4 , F_119 ( V_4 ) ) ;
return 0 ;
}
static inline int F_158 ( struct V_1 * V_2 , int V_302 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_264 ;
V_264 = V_302 - V_6 -> V_203 -> V_303 - sizeof( struct V_75 ) ;
if ( V_6 -> V_203 -> V_304 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_159 ( V_20 ) )
V_264 -= V_6 -> V_203 -> V_304 ;
}
if ( V_264 > V_8 -> V_16 . V_305 )
V_264 = V_8 -> V_16 . V_305 ;
V_264 -= V_6 -> V_306 ;
if ( V_264 < 48 )
V_264 = 48 ;
return V_264 ;
}
int F_160 ( struct V_1 * V_2 , int V_302 )
{
return F_158 ( V_2 , V_302 ) -
( F_3 ( V_2 ) -> V_79 - sizeof( struct V_75 ) ) ;
}
int F_161 ( struct V_1 * V_2 , int V_21 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_307 ;
V_307 = V_21 +
V_8 -> V_79 +
V_6 -> V_306 +
V_6 -> V_203 -> V_303 ;
if ( V_6 -> V_203 -> V_304 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_159 ( V_20 ) )
V_307 += V_6 -> V_203 -> V_304 ;
}
return V_307 ;
}
void F_162 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_308 * V_308 = F_9 ( V_2 ) ;
V_6 -> V_309 . V_310 = V_308 -> V_69 . V_311 > 1 ;
V_6 -> V_309 . V_312 = V_8 -> V_16 . V_305 + sizeof( struct V_75 ) +
V_6 -> V_203 -> V_303 ;
V_6 -> V_309 . V_313 = F_161 ( V_2 , V_308 -> V_69 . V_314 ) ;
V_6 -> V_309 . V_315 = 0 ;
if ( V_6 -> V_309 . V_310 )
V_6 -> V_309 . V_316 = V_32 ;
}
unsigned int F_163 ( struct V_1 * V_2 , T_4 V_302 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_264 ;
if ( V_6 -> V_309 . V_312 > V_302 )
V_6 -> V_309 . V_312 = V_302 ;
V_264 = F_160 ( V_2 , V_302 ) ;
V_264 = F_164 ( V_8 , V_264 ) ;
V_6 -> V_317 = V_302 ;
if ( V_6 -> V_309 . V_310 )
V_264 = F_20 ( V_264 , F_160 ( V_2 , V_6 -> V_309 . V_313 ) ) ;
V_8 -> V_318 = V_264 ;
return V_264 ;
}
unsigned int F_63 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_19 * V_20 = F_14 ( V_2 ) ;
T_4 V_264 ;
unsigned int V_319 ;
struct V_97 V_98 ;
struct V_141 * V_142 ;
V_264 = V_8 -> V_318 ;
if ( V_20 ) {
T_4 V_307 = F_165 ( V_20 ) ;
if ( V_307 != F_2 ( V_2 ) -> V_317 )
V_264 = F_163 ( V_2 , V_307 ) ;
}
V_319 = F_59 ( V_2 , NULL , & V_98 , & V_142 ) +
sizeof( struct V_75 ) ;
if ( V_319 != V_8 -> V_79 ) {
int V_24 = ( int ) V_319 - V_8 -> V_79 ;
V_264 -= V_24 ;
}
return V_264 ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_320 == V_321 &&
V_2 -> V_322 && ! F_74 ( V_323 , & V_2 -> V_322 -> V_87 ) ) {
T_4 V_324 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_325 = F_21 ( V_8 -> V_33 , V_324 ) ;
if ( V_325 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_325 ) >> 1 ;
}
V_8 -> V_33 = 0 ;
}
V_8 -> V_31 = V_32 ;
}
static void F_167 ( struct V_1 * V_2 , bool V_326 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_94 , V_8 -> V_327 ) ||
V_8 -> V_10 > V_8 -> V_328 ) {
V_8 -> V_328 = V_8 -> V_10 ;
V_8 -> V_327 = V_8 -> V_11 ;
V_8 -> V_326 = V_326 ;
}
if ( F_168 ( V_2 ) ) {
V_8 -> V_33 = 0 ;
V_8 -> V_31 = V_32 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_33 )
V_8 -> V_33 = V_8 -> V_10 ;
if ( V_329 &&
( T_3 ) ( V_32 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 )
F_166 ( V_2 ) ;
if ( ! F_169 ( V_2 ) && V_2 -> V_322 &&
F_74 ( V_323 , & V_2 -> V_322 -> V_87 ) &&
( 1 << V_2 -> V_173 ) & ( V_174 | V_177 ) )
F_170 ( V_2 , V_330 ) ;
}
}
static bool F_171 ( const struct V_7 * V_8 )
{
return F_116 ( V_8 -> V_331 , V_8 -> V_94 ) &&
! F_116 ( V_8 -> V_331 , V_8 -> V_11 ) ;
}
static void F_172 ( struct V_7 * V_8 , unsigned int V_264 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_80 < F_6 ( V_4 ) * V_264 )
V_8 -> V_331 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_173 ( bool V_332 , const struct V_7 * V_8 ,
int V_181 )
{
return V_332 &&
( ( V_181 & V_333 ) ||
( ! V_181 && V_8 -> V_10 && F_171 ( V_8 ) ) ) ;
}
T_4 F_174 ( const struct V_1 * V_2 , unsigned int V_264 ,
int V_334 )
{
T_4 V_335 , V_336 ;
V_335 = F_20 ( V_2 -> V_337 >> 10 ,
V_2 -> V_338 - 1 - V_339 ) ;
V_336 = F_29 ( T_4 , V_335 / V_264 , V_334 ) ;
return F_30 ( T_4 , V_336 , V_2 -> V_340 ) ;
}
static T_4 F_175 ( struct V_1 * V_2 , unsigned int V_264 )
{
const struct V_341 * V_342 = F_2 ( V_2 ) -> V_343 ;
T_4 V_344 = V_342 -> V_345 ? V_342 -> V_345 ( V_2 ) : 0 ;
return V_344 ? :
F_174 ( V_2 , V_264 , V_346 ) ;
}
static unsigned int F_176 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_264 ,
unsigned int V_347 ,
int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_332 , V_348 , V_245 , V_349 ;
V_245 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_81 ;
V_349 = V_264 * V_347 ;
if ( F_53 ( V_349 <= V_245 && V_4 != F_177 ( V_2 ) ) )
return V_349 ;
V_348 = F_20 ( V_4 -> V_80 , V_245 ) ;
if ( V_349 <= V_348 )
return V_349 ;
V_332 = V_348 % V_264 ;
if ( F_173 ( V_332 != 0 , V_8 , V_181 ) )
return V_348 - V_332 ;
return V_348 ;
}
static inline unsigned int F_178 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_228 , V_26 , V_350 ;
if ( ( F_5 ( V_4 ) -> V_63 & V_93 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_228 = F_23 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_228 >= V_26 )
return 0 ;
V_350 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_350 , V_26 - V_228 ) ;
}
static int F_179 ( struct V_3 * V_4 , unsigned int V_264 )
{
int V_344 = F_6 ( V_4 ) ;
if ( ! V_344 || ( V_344 > 1 && F_119 ( V_4 ) != V_264 ) ) {
F_126 ( V_4 , V_264 ) ;
V_344 = F_6 ( V_4 ) ;
}
return V_344 ;
}
static inline bool F_180 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_351 , int V_181 )
{
if ( V_181 & V_352 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_63 & V_93 ) )
return true ;
if ( ! F_173 ( V_4 -> V_80 < V_351 , V_8 , V_181 ) )
return true ;
return false ;
}
static bool F_181 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_351 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_80 > V_351 )
V_12 = F_5 ( V_4 ) -> V_81 + V_351 ;
return ! F_116 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_182 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_351 , int V_181 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_353 ;
F_179 ( V_4 , V_351 ) ;
if ( ! F_180 ( V_8 , V_4 , V_351 , V_181 ) )
return 0 ;
V_353 = F_178 ( V_8 , V_4 ) ;
if ( V_353 && ! F_181 ( V_8 , V_4 , V_351 ) )
V_353 = 0 ;
return V_353 ;
}
bool F_183 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_169 ( V_2 ) ;
return V_4 &&
F_182 ( V_2 , V_4 , F_63 ( V_2 ) ,
( F_184 ( V_2 , V_4 ) ?
V_8 -> V_181 : V_352 ) ) ;
}
static int F_185 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_80 ,
unsigned int V_264 , T_10 V_285 )
{
struct V_3 * V_286 ;
int V_289 = V_4 -> V_80 - V_80 ;
T_7 V_87 ;
if ( V_4 -> V_80 != V_4 -> V_299 )
return F_138 ( V_2 , V_4 , V_80 , V_264 , V_285 ) ;
V_286 = F_142 ( V_2 , 0 , V_285 , true ) ;
if ( F_51 ( ! V_286 ) )
return - V_291 ;
V_2 -> V_263 += V_286 -> V_210 ;
F_125 ( V_2 , V_286 -> V_210 ) ;
V_286 -> V_210 += V_289 ;
V_4 -> V_210 -= V_289 ;
F_5 ( V_286 ) -> V_81 = F_5 ( V_4 ) -> V_81 + V_80 ;
F_5 ( V_286 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_286 ) -> V_81 ;
V_87 = F_5 ( V_4 ) -> V_63 ;
F_5 ( V_4 ) -> V_63 = V_87 & ~ ( V_93 | V_292 ) ;
F_5 ( V_286 ) -> V_63 = V_87 ;
F_5 ( V_286 ) -> V_91 = 0 ;
F_137 ( V_4 , V_286 ) ;
V_286 -> V_88 = V_4 -> V_88 = V_89 ;
F_147 ( V_4 , V_286 , V_80 ) ;
F_135 ( V_4 , V_286 ) ;
F_126 ( V_4 , V_264 ) ;
F_126 ( V_286 , V_264 ) ;
F_123 ( V_286 ) ;
F_148 ( V_4 , V_286 , V_2 ) ;
return 0 ;
}
static bool F_186 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_326 , T_4 V_347 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_354 , V_355 , V_356 , V_357 , V_228 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_226 V_34 ;
struct V_3 * V_190 ;
int V_358 ;
if ( F_5 ( V_4 ) -> V_63 & V_93 )
goto V_359;
if ( V_6 -> V_320 >= V_360 )
goto V_359;
if ( ( T_3 ) ( V_32 - V_8 -> V_36 ) > 0 )
goto V_359;
V_228 = F_23 ( V_8 ) ;
F_100 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_228 ) ) ;
V_355 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_81 ;
V_356 = ( V_8 -> V_27 - V_228 ) * V_8 -> V_318 ;
V_357 = F_20 ( V_355 , V_356 ) ;
if ( V_357 >= V_347 * V_8 -> V_318 )
goto V_359;
if ( ( V_4 != F_177 ( V_2 ) ) && ( V_357 >= V_4 -> V_80 ) )
goto V_359;
V_358 = F_187 ( V_361 ) ;
if ( V_358 ) {
T_4 V_362 = F_20 ( V_8 -> V_363 , V_8 -> V_27 * V_8 -> V_318 ) ;
V_362 /= V_358 ;
if ( V_357 >= V_362 )
goto V_359;
} else {
if ( V_357 > F_188 ( V_8 ) * V_8 -> V_318 )
goto V_359;
}
V_190 = F_189 ( V_2 ) ;
F_101 ( & V_34 ) ;
V_354 = F_190 ( & V_34 , & V_190 -> V_226 ) ;
if ( V_354 < ( V_8 -> V_364 >> 4 ) )
goto V_359;
if ( V_356 < V_355 && V_356 <= V_4 -> V_80 )
* V_326 = true ;
return true ;
V_359:
return false ;
}
static inline void F_191 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_308 * V_308 = F_9 ( V_2 ) ;
T_4 V_365 ;
T_3 V_24 ;
V_365 = V_308 -> V_69 . V_366 ;
V_24 = V_32 - V_6 -> V_309 . V_316 ;
if ( F_51 ( V_24 >= V_365 * V_367 ) ) {
int V_21 = F_63 ( V_2 ) ;
V_6 -> V_309 . V_315 = 0 ;
V_6 -> V_309 . V_312 = V_8 -> V_16 . V_305 +
sizeof( struct V_75 ) +
V_6 -> V_203 -> V_303 ;
V_6 -> V_309 . V_313 = F_161 ( V_2 , V_21 ) ;
V_6 -> V_309 . V_316 = V_32 ;
}
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 , * V_368 , * V_369 ;
struct V_308 * V_308 = F_9 ( V_2 ) ;
int V_315 ;
int V_370 ;
int V_371 , V_80 ;
int V_264 ;
int V_365 ;
if ( F_53 ( ! V_6 -> V_309 . V_310 ||
V_6 -> V_309 . V_315 ||
F_2 ( V_2 ) -> V_320 != V_321 ||
V_8 -> V_27 < 11 ||
V_8 -> V_16 . V_171 || V_8 -> V_16 . V_122 ) )
return - 1 ;
V_264 = F_63 ( V_2 ) ;
V_315 = F_160 ( V_2 , ( V_6 -> V_309 . V_312 +
V_6 -> V_309 . V_313 ) >> 1 ) ;
V_370 = V_315 + ( V_8 -> V_372 + 1 ) * V_8 -> V_318 ;
V_365 = V_6 -> V_309 . V_312 - V_6 -> V_309 . V_313 ;
if ( V_315 > F_160 ( V_2 , V_6 -> V_309 . V_312 ) ||
V_365 < V_308 -> V_69 . V_373 ) {
F_191 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_262 - V_8 -> V_11 < V_370 )
return - 1 ;
if ( V_8 -> V_363 < V_370 )
return - 1 ;
if ( F_116 ( V_8 -> V_11 + V_370 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_368 = F_142 ( V_2 , V_315 , V_182 , false ) ;
if ( ! V_368 )
return - 1 ;
V_2 -> V_263 += V_368 -> V_210 ;
F_125 ( V_2 , V_368 -> V_210 ) ;
V_4 = F_169 ( V_2 ) ;
F_5 ( V_368 ) -> V_81 = F_5 ( V_4 ) -> V_81 ;
F_5 ( V_368 ) -> V_12 = F_5 ( V_4 ) -> V_81 + V_315 ;
F_5 ( V_368 ) -> V_63 = V_249 ;
F_5 ( V_368 ) -> V_91 = 0 ;
V_368 -> V_90 = 0 ;
V_368 -> V_88 = V_4 -> V_88 ;
F_193 ( V_368 , V_4 , V_2 ) ;
V_80 = 0 ;
F_194 (skb, next, sk) {
V_371 = F_30 ( int , V_4 -> V_80 , V_315 - V_80 ) ;
if ( V_368 -> V_88 ) {
F_195 ( V_4 , 0 , F_144 ( V_368 , V_371 ) , V_371 ) ;
} else {
T_11 V_90 = F_196 ( V_4 , 0 ,
F_144 ( V_368 , V_371 ) ,
V_371 , 0 ) ;
V_368 -> V_90 = F_197 ( V_368 -> V_90 , V_90 , V_80 ) ;
}
if ( V_4 -> V_80 <= V_371 ) {
F_5 ( V_368 ) -> V_63 |= F_5 ( V_4 ) -> V_63 ;
F_198 ( V_4 , V_2 ) ;
F_199 ( V_2 , V_4 ) ;
} else {
F_5 ( V_368 ) -> V_63 |= F_5 ( V_4 ) -> V_63 &
~ ( V_93 | V_292 ) ;
if ( ! F_45 ( V_4 ) -> V_293 ) {
F_200 ( V_4 , V_371 ) ;
if ( V_4 -> V_88 != V_89 )
V_4 -> V_90 = F_201 ( V_4 -> V_183 ,
V_4 -> V_80 , 0 ) ;
} else {
F_149 ( V_4 , V_371 ) ;
F_126 ( V_4 , V_264 ) ;
}
F_5 ( V_4 ) -> V_81 += V_371 ;
}
V_80 += V_371 ;
if ( V_80 >= V_315 )
break;
}
F_179 ( V_368 , V_368 -> V_80 ) ;
if ( ! F_99 ( V_2 , V_368 , 1 , V_182 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_368 ) ;
V_6 -> V_309 . V_315 = F_161 ( V_2 , V_368 -> V_80 ) ;
V_8 -> V_374 . V_375 = F_5 ( V_368 ) -> V_81 ;
V_8 -> V_374 . V_376 = F_5 ( V_368 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_202 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_377 )
{
unsigned int V_357 ;
V_357 = F_21 ( 2 * V_4 -> V_210 , V_2 -> V_337 >> 10 ) ;
V_357 = F_30 ( T_4 , V_357 , V_378 ) ;
V_357 <<= V_377 ;
if ( F_203 ( & V_2 -> V_211 ) > V_357 ) {
if ( V_4 == V_2 -> V_379 . V_369 ||
V_4 -> V_380 == V_2 -> V_379 . V_369 )
return false ;
F_204 ( V_381 , & V_2 -> V_193 ) ;
F_205 () ;
if ( F_203 ( & V_2 -> V_211 ) > V_357 )
return true ;
}
return false ;
}
static void F_206 ( struct V_7 * V_8 , const enum V_382 V_383 )
{
const T_4 V_34 = V_32 ;
if ( V_8 -> V_384 > V_385 )
V_8 -> V_386 [ V_8 -> V_384 - 1 ] += V_34 - V_8 -> V_387 ;
V_8 -> V_387 = V_34 ;
V_8 -> V_384 = V_383 ;
}
void F_170 ( struct V_1 * V_2 , const enum V_382 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( type > V_8 -> V_384 )
F_206 ( V_8 , type ) ;
}
void F_207 ( struct V_1 * V_2 , const enum V_382 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_208 ( V_2 ) )
F_206 ( V_8 , V_385 ) ;
else if ( type == V_8 -> V_384 )
F_206 ( V_8 , V_388 ) ;
}
static bool F_62 ( struct V_1 * V_2 , unsigned int V_264 , int V_181 ,
int V_389 , T_10 V_285 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_344 , V_390 ;
int V_353 ;
int V_391 ;
bool V_326 = false , V_392 = false ;
T_4 V_347 ;
V_390 = 0 ;
if ( ! V_389 ) {
V_391 = F_192 ( V_2 ) ;
if ( ! V_391 ) {
return false ;
} else if ( V_391 > 0 ) {
V_390 = 1 ;
}
}
V_347 = F_175 ( V_2 , V_264 ) ;
while ( ( V_4 = F_169 ( V_2 ) ) ) {
unsigned int V_357 ;
V_344 = F_179 ( V_4 , V_264 ) ;
F_100 ( ! V_344 ) ;
if ( F_51 ( V_8 -> V_393 ) && V_8 -> V_394 == V_395 ) {
F_101 ( & V_4 -> V_226 ) ;
goto V_393;
}
V_353 = F_178 ( V_8 , V_4 ) ;
if ( ! V_353 ) {
if ( V_389 == 2 )
V_353 = 1 ;
else
break;
}
if ( F_51 ( ! F_181 ( V_8 , V_4 , V_264 ) ) ) {
V_392 = true ;
break;
}
if ( V_344 == 1 ) {
if ( F_51 ( ! F_180 ( V_8 , V_4 , V_264 ,
( F_184 ( V_2 , V_4 ) ?
V_181 : V_352 ) ) ) )
break;
} else {
if ( ! V_389 &&
F_186 ( V_2 , V_4 , & V_326 ,
V_347 ) )
break;
}
V_357 = V_264 ;
if ( V_344 > 1 && ! F_49 ( V_8 ) )
V_357 = F_176 ( V_2 , V_4 , V_264 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_181 ) ;
if ( V_4 -> V_80 > V_357 &&
F_51 ( F_185 ( V_2 , V_4 , V_357 , V_264 , V_285 ) ) )
break;
if ( F_74 ( V_196 , & V_2 -> V_193 ) )
F_73 ( V_196 , & V_2 -> V_193 ) ;
if ( F_202 ( V_2 , V_4 , 0 ) )
break;
if ( F_51 ( F_99 ( V_2 , V_4 , 1 , V_285 ) ) )
break;
V_393:
F_1 ( V_2 , V_4 ) ;
F_172 ( V_8 , V_264 , V_4 ) ;
V_390 += F_6 ( V_4 ) ;
if ( V_389 )
break;
}
if ( V_392 )
F_170 ( V_2 , V_396 ) ;
else
F_207 ( V_2 , V_396 ) ;
if ( F_53 ( V_390 ) ) {
if ( F_209 ( V_2 ) )
V_8 -> V_397 += V_390 ;
if ( V_389 != 2 )
F_210 ( V_2 ) ;
V_326 |= ( F_23 ( V_8 ) >= V_8 -> V_27 ) ;
F_167 ( V_2 , V_326 ) ;
return false ;
}
return ! V_8 -> V_10 && F_169 ( V_2 ) ;
}
bool F_210 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_398 , V_399 , V_400 ;
T_4 V_401 = F_211 ( V_8 -> V_364 >> 3 ) ;
if ( F_139 ( V_6 -> V_13 == V_14 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_8 -> V_402 )
return false ;
if ( V_6 -> V_13 != V_403 )
return false ;
if ( ( V_404 != 3 && V_404 != 4 ) ||
! V_8 -> V_10 || ! F_212 ( V_8 ) ||
V_6 -> V_320 != V_321 )
return false ;
if ( ( V_8 -> V_27 > F_23 ( V_8 ) ) &&
F_169 ( V_2 ) )
return false ;
V_398 = V_401 << 1 ? : V_405 ;
if ( V_8 -> V_10 == 1 )
V_398 = F_29 ( T_4 , V_398 ,
( V_401 + ( V_401 >> 1 ) + V_406 ) ) ;
V_398 = F_29 ( T_4 , V_398 , F_213 ( 10 ) ) ;
V_399 = V_32 + V_398 ;
V_400 = ( T_4 ) F_2 ( V_2 ) -> V_407 ;
if ( ( T_3 ) ( V_399 - V_400 ) > 0 ) {
T_3 V_24 = V_400 - V_32 ;
if ( V_24 > 0 )
V_398 = V_24 ;
}
F_214 ( V_2 , V_14 , V_398 ,
V_408 ) ;
return true ;
}
static bool F_215 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_216 ( V_2 , V_4 ) ) ) {
F_34 ( F_9 ( V_2 ) ,
V_409 ) ;
return true ;
}
return false ;
}
void F_217 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_410 ;
int V_21 = F_63 ( V_2 ) ;
V_4 = F_169 ( V_2 ) ;
if ( V_4 ) {
if ( F_181 ( V_8 , V_4 , V_21 ) ) {
V_410 = V_8 -> V_10 ;
F_62 ( V_2 , V_21 , V_411 , 2 , V_182 ) ;
if ( V_8 -> V_10 > V_410 )
goto V_412;
goto V_413;
}
V_4 = F_218 ( V_2 , V_4 ) ;
} else {
V_4 = F_177 ( V_2 ) ;
}
if ( V_8 -> V_414 )
goto V_413;
if ( F_139 ( ! V_4 ) )
goto V_413;
if ( F_215 ( V_2 , V_4 ) )
goto V_413;
V_410 = F_6 ( V_4 ) ;
if ( F_139 ( ! V_410 ) )
goto V_413;
if ( ( V_410 > 1 ) && ( V_4 -> V_80 > ( V_410 - 1 ) * V_21 ) ) {
if ( F_51 ( F_138 ( V_2 , V_4 , ( V_410 - 1 ) * V_21 , V_21 ,
V_182 ) ) )
goto V_413;
V_4 = F_219 ( V_2 , V_4 ) ;
}
if ( F_139 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_413;
if ( F_220 ( V_2 , V_4 , 1 ) )
goto V_413;
V_8 -> V_414 = V_8 -> V_11 ;
V_412:
F_34 ( F_9 ( V_2 ) , V_415 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_413:
F_7 ( V_2 ) ;
}
void F_221 ( struct V_1 * V_2 , unsigned int V_351 ,
int V_181 )
{
if ( F_51 ( V_2 -> V_173 == V_416 ) )
return;
if ( F_62 ( V_2 , V_351 , V_181 , 0 ,
F_222 ( V_2 , V_182 ) ) )
F_223 ( V_2 ) ;
}
void F_224 ( struct V_1 * V_2 , unsigned int V_264 )
{
struct V_3 * V_4 = F_169 ( V_2 ) ;
F_100 ( ! V_4 || V_4 -> V_80 < V_264 ) ;
F_62 ( V_2 , V_264 , V_352 , 1 , V_2 -> V_417 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_21 = V_6 -> V_37 . V_418 ;
int V_419 = F_225 ( V_2 ) ;
int V_420 = F_226 ( V_2 ) ;
int V_421 = F_30 ( int , V_8 -> V_47 , V_420 ) ;
int V_245 ;
if ( F_51 ( V_21 > V_421 ) ) {
V_21 = V_421 ;
if ( V_21 <= 0 )
return 0 ;
}
if ( V_419 < ( V_421 >> 1 ) ) {
V_6 -> V_37 . V_422 = 0 ;
if ( F_227 ( V_2 ) )
V_8 -> V_423 = F_20 ( V_8 -> V_423 ,
4U * V_8 -> V_22 ) ;
V_419 = F_228 ( V_419 , 1 << V_8 -> V_16 . V_18 ) ;
if ( V_419 < ( V_420 >> 4 ) || V_419 < V_21 )
return 0 ;
}
if ( V_419 > V_8 -> V_423 )
V_419 = V_8 -> V_423 ;
V_245 = V_8 -> V_46 ;
if ( V_8 -> V_16 . V_18 ) {
V_245 = V_419 ;
if ( ( ( V_245 >> V_8 -> V_16 . V_18 ) << V_8 -> V_16 . V_18 ) != V_245 )
V_245 = ( ( ( V_245 >> V_8 -> V_16 . V_18 ) + 1 )
<< V_8 -> V_16 . V_18 ) ;
} else {
if ( V_245 <= V_419 - V_21 || V_245 > V_419 )
V_245 = ( V_419 / V_21 ) * V_21 ;
else if ( V_21 == V_421 &&
V_419 > V_245 + ( V_421 >> 1 ) )
V_245 = V_419 ;
}
return V_245 ;
}
void F_229 ( struct V_3 * V_4 ,
const struct V_3 * V_424 )
{
if ( F_51 ( F_134 ( V_424 ) ) ) {
const struct V_279 * V_425 =
F_45 ( V_424 ) ;
struct V_279 * V_280 = F_45 ( V_4 ) ;
V_280 -> V_276 |= V_425 -> V_276 & V_277 ;
V_280 -> V_281 = V_425 -> V_281 ;
F_5 ( V_4 ) -> V_275 |=
F_5 ( V_424 ) -> V_275 ;
}
}
static bool F_230 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_424 = F_219 ( V_2 , V_4 ) ;
int V_426 , V_427 ;
V_426 = V_4 -> V_80 ;
V_427 = V_424 -> V_80 ;
F_100 ( F_6 ( V_4 ) != 1 || F_6 ( V_424 ) != 1 ) ;
if ( V_427 ) {
if ( V_427 <= F_231 ( V_4 ) )
F_195 ( V_424 , 0 , F_144 ( V_4 , V_427 ) ,
V_427 ) ;
else if ( ! F_232 ( V_4 , V_424 , V_427 ) )
return false ;
}
F_233 ( V_2 , V_424 , V_4 ) ;
F_198 ( V_424 , V_2 ) ;
if ( V_424 -> V_88 == V_89 )
V_4 -> V_88 = V_89 ;
if ( V_4 -> V_88 != V_89 )
V_4 -> V_90 = F_197 ( V_4 -> V_90 , V_424 -> V_90 , V_426 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_424 ) -> V_12 ;
F_5 ( V_4 ) -> V_63 |= F_5 ( V_424 ) -> V_63 ;
F_5 ( V_4 ) -> V_91 |= F_5 ( V_424 ) -> V_91 & V_428 ;
F_5 ( V_4 ) -> V_284 = F_5 ( V_424 ) -> V_284 ;
F_234 ( V_8 ) ;
if ( V_424 == V_8 -> V_429 )
V_8 -> V_429 = V_4 ;
F_131 ( V_2 , V_424 , F_6 ( V_424 ) ) ;
F_229 ( V_4 , V_424 ) ;
F_199 ( V_2 , V_424 ) ;
return true ;
}
static bool F_235 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_103 ( V_4 ) )
return false ;
if ( V_4 == F_169 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_91 & V_270 )
return false ;
return true ;
}
static void F_236 ( struct V_1 * V_2 , struct V_3 * V_430 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_430 , * V_431 ;
bool V_432 = true ;
if ( ! V_433 )
return;
if ( F_5 ( V_4 ) -> V_63 & V_92 )
return;
F_194 (skb, tmp, sk) {
if ( ! F_235 ( V_2 , V_4 ) )
break;
if ( ! F_237 ( V_430 ) )
break;
V_49 -= V_4 -> V_80 ;
if ( V_432 ) {
V_432 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( F_116 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
if ( ! F_230 ( V_2 , V_430 ) )
break;
}
}
int F_220 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_336 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_351 ;
int V_294 , V_80 , V_225 ;
if ( V_6 -> V_309 . V_315 )
V_6 -> V_309 . V_315 = 0 ;
if ( F_203 ( & V_2 -> V_211 ) >
F_30 ( T_4 , V_2 -> V_263 + ( V_2 -> V_263 >> 2 ) ,
V_2 -> V_434 ) )
return - V_435 ;
if ( F_215 ( V_2 , V_4 ) )
return - V_436 ;
if ( F_11 ( F_5 ( V_4 ) -> V_81 , V_8 -> V_94 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_94 ) )
F_238 () ;
if ( F_155 ( V_2 , V_4 , V_8 -> V_94 - F_5 ( V_4 ) -> V_81 ) )
return - V_291 ;
}
if ( F_2 ( V_2 ) -> V_203 -> V_437 ( V_2 ) )
return - V_438 ;
V_351 = F_63 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_81 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_81 != V_8 -> V_94 )
return - V_435 ;
V_80 = V_351 * V_336 ;
if ( V_4 -> V_80 > V_80 ) {
if ( F_138 ( V_2 , V_4 , V_80 , V_351 , V_182 ) )
return - V_291 ;
} else {
if ( F_141 ( V_4 , V_182 ) )
return - V_291 ;
V_294 = F_6 ( V_4 ) ;
F_126 ( V_4 , V_351 ) ;
V_294 -= F_6 ( V_4 ) ;
if ( V_294 )
F_131 ( V_2 , V_4 , V_294 ) ;
if ( V_4 -> V_80 < V_351 )
F_236 ( V_2 , V_4 , V_351 ) ;
}
if ( ( F_5 ( V_4 ) -> V_63 & V_439 ) == V_439 )
F_41 ( V_2 , V_4 ) ;
V_336 = F_6 ( V_4 ) ;
F_118 ( F_9 ( V_2 ) , V_440 , V_336 ) ;
if ( F_5 ( V_4 ) -> V_63 & V_92 )
F_239 ( F_9 ( V_2 ) , V_441 ) ;
V_8 -> V_442 += V_336 ;
if ( F_51 ( ( V_443 && ( ( unsigned long ) V_4 -> V_183 & 3 ) ) ||
F_240 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_368 ;
F_101 ( & V_4 -> V_226 ) ;
V_368 = F_241 ( V_4 , V_339 , V_182 ) ;
V_225 = V_368 ? F_99 ( V_2 , V_368 , 0 , V_182 ) :
- V_229 ;
} else {
V_225 = F_99 ( V_2 , V_4 , 1 , V_182 ) ;
}
if ( F_53 ( ! V_225 ) ) {
F_5 ( V_4 ) -> V_91 |= V_428 ;
} else if ( V_225 != - V_436 ) {
F_34 ( F_9 ( V_2 ) , V_444 ) ;
}
return V_225 ;
}
int F_242 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_336 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_225 = F_220 ( V_2 , V_4 , V_336 ) ;
if ( V_225 == 0 ) {
#if V_445 > 0
if ( F_5 ( V_4 ) -> V_91 & V_271 ) {
F_243 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_91 |= V_446 ;
V_8 -> V_180 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_447 )
V_8 -> V_447 = F_56 ( V_4 ) ;
}
if ( V_8 -> V_448 < 0 )
V_8 -> V_448 = 0 ;
V_8 -> V_448 += F_6 ( V_4 ) ;
return V_225 ;
}
void F_61 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_449 = NULL ;
T_4 V_347 ;
int V_450 ;
if ( ! V_8 -> V_10 )
return;
if ( V_8 -> V_429 ) {
V_4 = V_8 -> V_429 ;
} else {
V_4 = F_189 ( V_2 ) ;
}
V_347 = F_175 ( V_2 , F_63 ( V_2 ) ) ;
F_244 (skb, sk) {
T_5 V_91 ;
int V_336 ;
if ( V_4 == F_169 ( V_2 ) )
break;
if ( ! V_449 )
V_8 -> V_429 = V_4 ;
V_336 = V_8 -> V_27 - F_23 ( V_8 ) ;
if ( V_336 <= 0 )
return;
V_91 = F_5 ( V_4 ) -> V_91 ;
V_336 = F_30 ( int , V_336 , V_347 ) ;
if ( V_8 -> V_180 >= V_8 -> V_179 ) {
break;
} else if ( ! ( V_91 & V_272 ) ) {
if ( ! V_449 && ! ( V_91 & ( V_271 | V_270 ) ) )
V_449 = V_4 ;
continue;
} else {
if ( V_6 -> V_320 != V_451 )
V_450 = V_452 ;
else
V_450 = V_453 ;
}
if ( V_91 & ( V_270 | V_271 ) )
continue;
if ( F_202 ( V_2 , V_4 , 1 ) )
return;
if ( F_242 ( V_2 , V_4 , V_336 ) )
return;
F_8 ( F_9 ( V_2 ) , V_450 , F_6 ( V_4 ) ) ;
if ( F_209 ( V_2 ) )
V_8 -> V_397 += F_6 ( V_4 ) ;
if ( V_4 == F_189 ( V_2 ) &&
V_6 -> V_13 != V_454 )
F_214 ( V_2 , V_403 ,
F_2 ( V_2 ) -> V_30 ,
V_408 ) ;
}
}
void F_245 ( struct V_1 * V_2 , int V_169 )
{
int V_455 ;
if ( V_169 <= V_2 -> V_456 )
return;
V_455 = F_246 ( V_169 ) ;
V_2 -> V_456 += V_455 * V_457 ;
F_247 ( V_2 , V_455 ) ;
if ( V_458 && V_2 -> V_459 )
F_248 ( V_2 -> V_459 , V_455 ) ;
}
void F_249 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_460 = F_177 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_460 && ( F_169 ( V_2 ) || F_227 ( V_2 ) ) ) {
V_461:
F_5 ( V_460 ) -> V_63 |= V_93 ;
F_5 ( V_460 ) -> V_12 ++ ;
V_8 -> V_262 ++ ;
if ( ! F_169 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_250 ( V_339 , V_2 -> V_417 ) ;
if ( F_51 ( ! V_4 ) ) {
if ( V_460 )
goto V_461;
return;
}
F_251 ( V_4 , V_339 ) ;
F_245 ( V_2 , V_4 -> V_210 ) ;
F_47 ( V_4 , V_8 -> V_262 ,
V_249 | V_93 ) ;
F_122 ( V_2 , V_4 ) ;
}
F_221 ( V_2 , F_63 ( V_2 ) , V_411 ) ;
}
void F_252 ( struct V_1 * V_2 , T_10 V_462 )
{
struct V_3 * V_4 ;
F_253 ( F_9 ( V_2 ) , V_463 ) ;
V_4 = F_254 ( V_339 , V_462 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_464 ) ;
return;
}
F_251 ( V_4 , V_339 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_249 | V_465 ) ;
F_101 ( & V_4 -> V_226 ) ;
if ( F_99 ( V_2 , V_4 , 0 , V_462 ) )
F_34 ( F_9 ( V_2 ) , V_464 ) ;
}
int F_255 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_189 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_63 & V_92 ) ) {
F_256 ( L_2 , V_466 ) ;
return - V_467 ;
}
if ( ! ( F_5 ( V_4 ) -> V_63 & V_249 ) ) {
if ( F_103 ( V_4 ) ) {
struct V_3 * V_368 = F_257 ( V_4 , V_182 ) ;
if ( ! V_368 )
return - V_291 ;
F_198 ( V_4 , V_2 ) ;
F_123 ( V_368 ) ;
F_258 ( V_2 , V_368 ) ;
F_199 ( V_2 , V_4 ) ;
V_2 -> V_263 += V_368 -> V_210 ;
F_125 ( V_2 , V_368 -> V_210 ) ;
V_4 = V_368 ;
}
F_5 ( V_4 ) -> V_63 |= V_249 ;
F_36 ( V_2 , V_4 ) ;
}
return F_99 ( V_2 , V_4 , 1 , V_182 ) ;
}
struct V_3 * F_259 ( const struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_73 * V_74 ,
struct V_131 * V_132 ,
enum V_468 V_469 )
{
struct V_164 * V_165 = F_43 ( V_74 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_141 * V_142 = NULL ;
struct V_97 V_98 ;
struct V_3 * V_4 ;
int V_224 ;
struct V_75 * V_76 ;
int V_21 ;
V_4 = F_254 ( V_339 , V_182 ) ;
if ( F_51 ( ! V_4 ) ) {
F_260 ( V_20 ) ;
return NULL ;
}
F_251 ( V_4 , V_339 ) ;
switch ( V_469 ) {
case V_470 :
F_261 ( V_4 , F_262 ( V_74 ) ) ;
break;
case V_471 :
break;
case V_472 :
F_261 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_263 ( V_4 , V_20 ) ;
V_21 = F_264 ( V_8 , F_15 ( V_20 ) ) ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
#ifdef F_265
if ( F_51 ( V_74 -> V_473 ) )
V_4 -> V_226 . V_474 = F_266 ( V_74 ) ;
else
#endif
F_101 ( & V_4 -> V_226 ) ;
#ifdef F_55
F_267 () ;
V_142 = F_58 ( V_74 ) -> V_148 -> V_475 ( V_2 , F_262 ( V_74 ) ) ;
#endif
F_268 ( V_4 , F_58 ( V_74 ) -> V_476 , V_477 ) ;
V_224 = F_57 ( V_74 , V_21 , V_4 , & V_98 , V_142 , V_132 ) +
sizeof( * V_76 ) ;
F_108 ( V_4 , V_224 ) ;
F_109 ( V_4 ) ;
V_76 = (struct V_75 * ) V_4 -> V_183 ;
memset ( V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 -> V_478 = 1 ;
V_76 -> V_479 = 1 ;
F_42 ( V_74 , V_76 ) ;
V_76 -> V_235 = F_115 ( V_165 -> V_480 ) ;
V_76 -> V_237 = V_165 -> V_481 ;
F_47 ( V_4 , F_58 ( V_74 ) -> V_482 ,
V_92 | V_249 ) ;
V_76 -> V_81 = F_52 ( F_5 ( V_4 ) -> V_81 ) ;
V_76 -> V_239 = F_52 ( F_58 ( V_74 ) -> V_59 ) ;
V_76 -> V_245 = F_115 ( F_20 ( V_74 -> V_483 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_76 + 1 ) , NULL , & V_98 ) ;
V_76 -> V_484 = ( V_224 >> 2 ) ;
F_269 ( F_9 ( V_2 ) , V_251 ) ;
#ifdef F_55
if ( V_142 )
F_58 ( V_74 ) -> V_148 -> V_247 ( V_98 . V_104 ,
V_142 , F_262 ( V_74 ) , V_4 ) ;
F_270 () ;
#endif
V_4 -> V_255 = 0 ;
return V_4 ;
}
static void F_271 ( struct V_1 * V_2 , const struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_341 * V_485 ;
T_4 V_486 = F_272 ( V_20 , V_487 ) ;
if ( V_486 == V_488 )
return;
F_267 () ;
V_485 = F_273 ( V_486 ) ;
if ( F_53 ( V_485 && F_274 ( V_485 -> V_489 ) ) ) {
F_275 ( V_6 -> V_343 -> V_489 ) ;
V_6 -> V_490 = F_276 ( V_20 ) ;
V_6 -> V_343 = V_485 ;
}
F_270 () ;
}
static void F_277 ( struct V_1 * V_2 )
{
const struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_18 ;
V_8 -> V_79 = sizeof( struct V_75 ) +
( V_152 ? V_155 : 0 ) ;
#ifdef F_55
if ( V_8 -> V_148 -> V_149 ( V_2 , V_2 ) )
V_8 -> V_79 += V_150 ;
#endif
if ( V_8 -> V_16 . V_491 )
V_8 -> V_16 . V_305 = V_8 -> V_16 . V_491 ;
V_8 -> V_492 = 0 ;
F_162 ( V_2 ) ;
F_163 ( V_2 , F_165 ( V_20 ) ) ;
F_271 ( V_2 , V_20 ) ;
if ( ! V_8 -> V_47 )
V_8 -> V_47 = F_272 ( V_20 , V_493 ) ;
V_8 -> V_22 = F_264 ( V_8 , F_15 ( V_20 ) ) ;
F_278 ( V_2 ) ;
if ( V_2 -> V_494 & V_495 &&
( V_8 -> V_47 > F_226 ( V_2 ) || V_8 -> V_47 == 0 ) )
V_8 -> V_47 = F_226 ( V_2 ) ;
F_28 ( F_226 ( V_2 ) ,
V_8 -> V_22 - ( V_8 -> V_16 . V_496 ? V_8 -> V_79 - sizeof( struct V_75 ) : 0 ) ,
& V_8 -> V_46 ,
& V_8 -> V_47 ,
V_156 ,
& V_18 ,
F_272 ( V_20 , V_497 ) ) ;
V_8 -> V_16 . V_18 = V_18 ;
V_8 -> V_423 = V_8 -> V_46 ;
V_2 -> V_498 = 0 ;
F_279 ( V_2 , V_499 ) ;
V_8 -> V_363 = 0 ;
F_280 ( V_8 , 0 ) ;
V_8 -> V_94 = V_8 -> V_262 ;
V_8 -> V_331 = V_8 -> V_262 ;
V_8 -> V_95 = V_8 -> V_262 ;
V_8 -> V_11 = V_8 -> V_262 ;
if ( F_53 ( ! V_8 -> V_393 ) )
V_8 -> V_59 = 0 ;
else
V_8 -> V_500 = V_32 ;
V_8 -> V_58 = V_8 -> V_59 ;
V_8 -> V_501 = V_8 -> V_59 ;
F_2 ( V_2 ) -> V_30 = V_405 ;
F_2 ( V_2 ) -> V_502 = 0 ;
F_281 ( V_8 ) ;
}
static void F_282 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_221 * V_222 = F_5 ( V_4 ) ;
V_222 -> V_12 += V_4 -> V_80 ;
F_123 ( V_4 ) ;
F_283 ( V_2 , V_4 ) ;
V_2 -> V_263 += V_4 -> V_210 ;
F_125 ( V_2 , V_4 -> V_210 ) ;
V_8 -> V_262 = V_222 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_284 ( struct V_1 * V_2 , struct V_3 * V_478 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_145 * V_503 = V_8 -> V_147 ;
int V_49 , V_225 = 0 ;
struct V_3 * V_504 ;
V_8 -> V_16 . V_305 = V_8 -> V_22 ;
if ( ! F_285 ( V_2 , & V_8 -> V_16 . V_305 , & V_503 -> V_160 ) )
goto V_505;
V_8 -> V_16 . V_305 = F_264 ( V_8 , V_8 -> V_16 . V_305 ) ;
V_49 = F_158 ( V_2 , F_2 ( V_2 ) -> V_317 ) -
V_144 ;
V_49 = F_30 ( V_506 , V_49 , V_503 -> V_169 ) ;
V_49 = F_30 ( V_506 , V_49 , F_286 ( V_339 ) ) ;
V_504 = F_142 ( V_2 , V_49 , V_2 -> V_417 , false ) ;
if ( ! V_504 )
goto V_505;
V_504 -> V_88 = V_89 ;
memcpy ( V_504 -> V_256 , V_478 -> V_256 , sizeof( V_478 -> V_256 ) ) ;
if ( V_49 ) {
int V_507 = F_287 ( F_144 ( V_504 , V_49 ) , V_49 ,
& V_503 -> V_183 -> V_508 ) ;
if ( F_51 ( ! V_507 ) ) {
F_288 ( V_504 ) ;
goto V_505;
}
if ( V_507 != V_49 ) {
F_145 ( V_504 , V_507 ) ;
V_49 = V_507 ;
}
}
if ( V_49 == V_503 -> V_169 )
V_503 -> V_183 = NULL ;
V_503 -> V_507 = V_49 ;
F_282 ( V_2 , V_504 ) ;
if ( V_504 -> V_80 )
F_170 ( V_2 , V_388 ) ;
V_225 = F_99 ( V_2 , V_504 , 1 , V_2 -> V_417 ) ;
V_478 -> V_226 = V_504 -> V_226 ;
F_5 ( V_504 ) -> V_81 ++ ;
F_5 ( V_504 ) -> V_63 = V_249 | V_292 ;
if ( ! V_225 ) {
V_8 -> V_504 = ( V_503 -> V_507 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_15 ) ;
goto V_509;
}
V_505:
if ( V_503 -> V_160 . V_80 > 0 )
V_503 -> V_160 . V_80 = 0 ;
V_225 = F_99 ( V_2 , V_478 , 1 , V_2 -> V_417 ) ;
if ( V_225 )
V_8 -> V_162 = 0 ;
V_509:
V_503 -> V_160 . V_80 = - 1 ;
return V_225 ;
}
int F_289 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_286 ;
int V_225 ;
F_277 ( V_2 ) ;
if ( F_51 ( V_8 -> V_393 ) ) {
F_290 ( V_2 , NULL ) ;
return 0 ;
}
V_286 = F_142 ( V_2 , 0 , V_2 -> V_417 , true ) ;
if ( F_51 ( ! V_286 ) )
return - V_229 ;
F_47 ( V_286 , V_8 -> V_262 ++ , V_92 ) ;
V_8 -> V_447 = V_32 ;
F_282 ( V_2 , V_286 ) ;
F_39 ( V_2 , V_286 ) ;
V_225 = V_8 -> V_147 ? F_284 ( V_2 , V_286 ) :
F_99 ( V_2 , V_286 , 1 , V_2 -> V_417 ) ;
if ( V_225 == - V_510 )
return V_225 ;
V_8 -> V_11 = V_8 -> V_262 ;
V_8 -> V_511 = V_8 -> V_262 ;
F_253 ( F_9 ( V_2 ) , V_512 ) ;
F_214 ( V_2 , V_403 ,
F_2 ( V_2 ) -> V_30 , V_408 ) ;
return 0 ;
}
void F_291 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_39 = V_6 -> V_37 . V_39 ;
unsigned long V_398 ;
F_18 ( V_2 , V_513 ) ;
if ( V_39 > V_514 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_515 = V_367 / 2 ;
if ( V_6 -> V_37 . V_40 ||
( V_6 -> V_37 . V_516 & V_517 ) )
V_515 = V_406 ;
if ( V_8 -> V_364 ) {
int V_401 = F_29 ( int , F_211 ( V_8 -> V_364 >> 3 ) ,
V_514 ) ;
if ( V_401 < V_515 )
V_515 = V_401 ;
}
V_39 = F_20 ( V_39 , V_515 ) ;
}
V_398 = V_518 + V_39 ;
if ( V_6 -> V_37 . V_516 & V_519 ) {
if ( V_6 -> V_37 . V_520 ||
F_292 ( V_6 -> V_37 . V_398 , V_518 + ( V_39 >> 2 ) ) ) {
F_293 ( V_2 ) ;
return;
}
if ( ! F_294 ( V_398 , V_6 -> V_37 . V_398 ) )
V_398 = V_6 -> V_37 . V_398 ;
}
V_6 -> V_37 . V_516 |= V_521 | V_519 ;
V_6 -> V_37 . V_398 = V_398 ;
F_295 ( V_2 , & V_6 -> V_522 , V_398 ) ;
}
void F_293 ( struct V_1 * V_2 )
{
struct V_3 * V_286 ;
if ( V_2 -> V_173 == V_416 )
return;
F_18 ( V_2 , V_523 ) ;
V_286 = F_254 ( V_339 ,
F_222 ( V_2 , V_182 | V_524 ) ) ;
if ( F_51 ( ! V_286 ) ) {
F_296 ( V_2 ) ;
F_2 ( V_2 ) -> V_37 . V_39 = V_525 ;
F_214 ( V_2 , V_42 ,
V_406 , V_408 ) ;
return;
}
F_251 ( V_286 , V_339 ) ;
F_47 ( V_286 , F_10 ( V_2 ) , V_249 ) ;
F_297 ( V_286 ) ;
F_101 ( & V_286 -> V_226 ) ;
F_99 ( V_2 , V_286 , 0 , ( V_526 T_10 ) 0 ) ;
}
static int F_298 ( struct V_1 * V_2 , int V_527 , int V_528 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_254 ( V_339 ,
F_222 ( V_2 , V_182 | V_524 ) ) ;
if ( ! V_4 )
return - 1 ;
F_251 ( V_4 , V_339 ) ;
F_47 ( V_4 , V_8 -> V_94 - ! V_527 , V_249 ) ;
F_101 ( & V_4 -> V_226 ) ;
F_34 ( F_9 ( V_2 ) , V_528 ) ;
return F_99 ( V_2 , V_4 , 0 , ( V_526 T_10 ) 0 ) ;
}
void F_299 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_529 ) {
F_3 ( V_2 ) -> V_530 = F_3 ( V_2 ) -> V_59 - 1 ;
F_298 ( V_2 , 0 , V_531 ) ;
}
}
int F_300 ( struct V_1 * V_2 , int V_528 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_416 )
return - 1 ;
V_4 = F_169 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_81 , F_12 ( V_8 ) ) ) {
int V_225 ;
unsigned int V_21 = F_63 ( V_2 ) ;
unsigned int V_532 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_81 ;
if ( F_11 ( V_8 -> V_511 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_511 = F_5 ( V_4 ) -> V_12 ;
if ( V_532 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_81 ||
V_4 -> V_80 > V_21 ) {
V_532 = F_20 ( V_532 , V_21 ) ;
F_5 ( V_4 ) -> V_63 |= V_292 ;
if ( F_138 ( V_2 , V_4 , V_532 , V_21 , V_182 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_126 ( V_4 , V_21 ) ;
F_5 ( V_4 ) -> V_63 |= V_292 ;
V_225 = F_99 ( V_2 , V_4 , 1 , V_182 ) ;
if ( ! V_225 )
F_1 ( V_2 , V_4 ) ;
return V_225 ;
} else {
if ( F_301 ( V_8 -> V_95 , V_8 -> V_94 + 1 , V_8 -> V_94 + 0xFFFF ) )
F_298 ( V_2 , 1 , V_528 ) ;
return F_298 ( V_2 , 0 , V_528 ) ;
}
}
void F_302 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_308 * V_308 = F_9 ( V_2 ) ;
unsigned long V_533 ;
int V_225 ;
V_225 = F_300 ( V_2 , V_531 ) ;
if ( V_8 -> V_10 || ! F_169 ( V_2 ) ) {
V_6 -> V_534 = 0 ;
V_6 -> V_535 = 0 ;
return;
}
if ( V_225 <= 0 ) {
if ( V_6 -> V_535 < V_308 -> V_69 . V_536 )
V_6 -> V_535 ++ ;
V_6 -> V_534 ++ ;
V_533 = V_408 ;
} else {
if ( ! V_6 -> V_534 )
V_6 -> V_534 = 1 ;
V_533 = V_537 ;
}
F_214 ( V_2 , V_538 ,
F_303 ( V_2 , V_533 ) ,
V_408 ) ;
}
int F_304 ( const struct V_1 * V_2 , struct V_73 * V_74 )
{
const struct V_539 * V_540 = F_58 ( V_74 ) -> V_148 ;
struct V_541 V_261 ;
int V_542 ;
F_58 ( V_74 ) -> V_476 = F_305 () ;
V_542 = V_540 -> V_543 ( V_2 , NULL , & V_261 , V_74 , NULL , V_470 ) ;
if ( ! V_542 ) {
F_269 ( F_9 ( V_2 ) , V_440 ) ;
F_239 ( F_9 ( V_2 ) , V_441 ) ;
if ( F_51 ( F_306 ( V_2 ) ) )
F_3 ( V_2 ) -> V_442 ++ ;
}
return V_542 ;
}
