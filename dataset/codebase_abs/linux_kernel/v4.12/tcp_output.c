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
( * V_47 ) = ( V_50 << V_51 ) ;
V_49 = F_20 ( * V_47 , V_49 ) ;
if ( V_49 > V_21 )
V_49 = F_29 ( V_49 , V_21 ) ;
if ( V_52 )
( * V_46 ) = F_20 ( V_49 , V_53 ) ;
else
( * V_46 ) = V_49 ;
( * V_18 ) = 0 ;
if ( V_17 ) {
V_49 = F_30 ( T_4 , V_49 , V_54 [ 2 ] ) ;
V_49 = F_30 ( T_4 , V_49 , V_55 ) ;
V_49 = F_31 ( T_4 , V_49 , * V_47 ) ;
while ( V_49 > V_50 && ( * V_18 ) < V_51 ) {
V_49 >>= 1 ;
( * V_18 ) ++ ;
}
}
if ( V_21 > ( 1 << * V_18 ) ) {
if ( ! V_48 )
V_48 = F_27 ( V_21 ) ;
* V_46 = F_20 ( * V_46 , V_48 * V_21 ) ;
}
( * V_47 ) = F_31 ( T_1 , V_50 << ( * V_18 ) , * V_47 ) ;
}
static T_6 F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_56 = V_8 -> V_46 ;
T_4 V_57 = F_33 ( V_8 ) ;
T_4 V_58 = F_34 ( V_2 ) ;
if ( V_58 < V_57 ) {
if ( V_58 == 0 )
F_35 ( F_9 ( V_2 ) ,
V_59 ) ;
V_58 = F_36 ( V_57 , 1 << V_8 -> V_16 . V_18 ) ;
}
V_8 -> V_46 = V_58 ;
V_8 -> V_60 = V_8 -> V_61 ;
if ( ! V_8 -> V_16 . V_18 && V_52 )
V_58 = F_20 ( V_58 , V_53 ) ;
else
V_58 = F_20 ( V_58 , ( 65535U << V_8 -> V_16 . V_18 ) ) ;
V_58 >>= V_8 -> V_16 . V_18 ;
if ( V_58 == 0 ) {
V_8 -> V_62 = 0 ;
if ( V_56 )
F_35 ( F_9 ( V_2 ) ,
V_63 ) ;
} else if ( V_56 == 0 ) {
F_35 ( F_9 ( V_2 ) , V_64 ) ;
}
return V_58 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
F_5 ( V_4 ) -> V_65 &= ~ V_66 ;
if ( ! ( V_8 -> V_67 & V_68 ) )
F_5 ( V_4 ) -> V_65 &= ~ V_69 ;
else if ( F_38 ( V_2 ) )
F_39 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
bool V_70 = F_9 ( V_2 ) -> V_71 . V_72 == 1 ||
F_38 ( V_2 ) ;
if ( ! V_70 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_41 ( V_20 , V_73 ) )
V_70 = true ;
}
V_8 -> V_67 = 0 ;
if ( V_70 ) {
F_5 ( V_4 ) -> V_65 |= V_69 | V_66 ;
V_8 -> V_67 = V_68 ;
if ( F_38 ( V_2 ) )
F_39 ( V_2 ) ;
}
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_9 ( V_2 ) -> V_71 . V_74 )
F_5 ( V_4 ) -> V_65 &= ~ ( V_69 | V_66 ) ;
}
static void
F_43 ( const struct V_75 * V_76 , struct V_77 * V_78 )
{
if ( F_44 ( V_76 ) -> V_79 )
V_78 -> V_80 = 1 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_77 * V_78 , int V_81 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_67 & V_68 ) {
if ( V_4 -> V_82 != V_81 &&
! F_11 ( F_5 ( V_4 ) -> V_83 , V_8 -> V_11 ) ) {
F_39 ( V_2 ) ;
if ( V_8 -> V_67 & V_84 ) {
V_8 -> V_67 &= ~ V_84 ;
V_78 -> V_85 = 1 ;
F_46 ( V_4 ) -> V_86 |= V_87 ;
}
} else if ( ! F_38 ( V_2 ) ) {
F_47 ( V_2 ) ;
}
if ( V_8 -> V_67 & V_88 )
V_78 -> V_80 = 1 ;
}
}
static void F_48 ( struct V_3 * V_4 , T_4 V_83 , T_7 V_89 )
{
V_4 -> V_90 = V_91 ;
V_4 -> V_92 = 0 ;
F_5 ( V_4 ) -> V_65 = V_89 ;
F_5 ( V_4 ) -> V_93 = 0 ;
F_49 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_83 = V_83 ;
if ( V_89 & ( V_94 | V_95 ) )
V_83 ++ ;
F_5 ( V_4 ) -> V_12 = V_83 ;
}
static inline bool F_50 ( const struct V_7 * V_8 )
{
return V_8 -> V_96 != V_8 -> V_97 ;
}
static void F_51 ( T_8 * V_98 , struct V_7 * V_8 ,
struct V_99 * V_100 )
{
T_6 V_101 = V_100 -> V_101 ;
if ( F_52 ( V_102 & V_101 ) ) {
* V_98 ++ = F_53 ( ( V_103 << 24 ) | ( V_103 << 16 ) |
( V_104 << 8 ) | V_105 ) ;
V_100 -> V_106 = ( T_5 * ) V_98 ;
V_98 += 4 ;
}
if ( F_52 ( V_100 -> V_21 ) ) {
* V_98 ++ = F_53 ( ( V_107 << 24 ) |
( V_108 << 16 ) |
V_100 -> V_21 ) ;
}
if ( F_54 ( V_109 & V_101 ) ) {
if ( F_52 ( V_110 & V_101 ) ) {
* V_98 ++ = F_53 ( ( V_111 << 24 ) |
( V_112 << 16 ) |
( V_113 << 8 ) |
V_114 ) ;
V_101 &= ~ V_110 ;
} else {
* V_98 ++ = F_53 ( ( V_103 << 24 ) |
( V_103 << 16 ) |
( V_113 << 8 ) |
V_114 ) ;
}
* V_98 ++ = F_53 ( V_100 -> V_115 ) ;
* V_98 ++ = F_53 ( V_100 -> V_116 ) ;
}
if ( F_52 ( V_110 & V_101 ) ) {
* V_98 ++ = F_53 ( ( V_103 << 24 ) |
( V_103 << 16 ) |
( V_111 << 8 ) |
V_112 ) ;
}
if ( F_52 ( V_117 & V_101 ) ) {
* V_98 ++ = F_53 ( ( V_103 << 24 ) |
( V_118 << 16 ) |
( V_119 << 8 ) |
V_100 -> V_120 ) ;
}
if ( F_52 ( V_100 -> V_121 ) ) {
struct V_122 * V_123 = V_8 -> V_16 . V_124 ?
V_8 -> V_125 : V_8 -> V_126 ;
int V_127 ;
* V_98 ++ = F_53 ( ( V_103 << 24 ) |
( V_103 << 16 ) |
( V_128 << 8 ) |
( V_129 + ( V_100 -> V_121 *
V_130 ) ) ) ;
for ( V_127 = 0 ; V_127 < V_100 -> V_121 ;
++ V_127 ) {
* V_98 ++ = F_53 ( V_123 [ V_127 ] . V_131 ) ;
* V_98 ++ = F_53 ( V_123 [ V_127 ] . V_12 ) ;
}
V_8 -> V_16 . V_124 = 0 ;
}
if ( F_52 ( V_132 & V_101 ) ) {
struct V_133 * V_134 = V_100 -> V_135 ;
T_7 * V_136 = ( T_7 * ) V_98 ;
T_4 V_82 ;
if ( V_134 -> exp ) {
V_82 = V_137 + V_134 -> V_82 ;
* V_98 = F_53 ( ( V_138 << 24 ) | ( V_82 << 16 ) |
V_139 ) ;
V_136 += V_137 ;
} else {
V_82 = V_140 + V_134 -> V_82 ;
* V_136 ++ = V_141 ;
* V_136 ++ = V_82 ;
}
memcpy ( V_136 , V_134 -> V_142 , V_134 -> V_82 ) ;
if ( ( V_82 & 3 ) == 2 ) {
V_136 [ V_134 -> V_82 ] = V_103 ;
V_136 [ V_134 -> V_82 + 1 ] = V_103 ;
}
V_98 += ( V_82 + 3 ) >> 2 ;
}
}
static unsigned int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
struct V_143 * * V_144 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_145 = V_146 ;
struct V_147 * V_148 = V_8 -> V_149 ;
#ifdef F_56
* V_144 = V_8 -> V_150 -> V_151 ( V_2 , V_2 ) ;
if ( * V_144 ) {
V_100 -> V_101 |= V_102 ;
V_145 -= V_152 ;
}
#else
* V_144 = NULL ;
#endif
V_100 -> V_21 = F_13 ( V_2 ) ;
V_145 -= V_153 ;
if ( F_54 ( V_154 && ! * V_144 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = F_57 ( V_4 ) + V_8 -> V_155 ;
V_100 -> V_116 = V_8 -> V_16 . V_156 ;
V_145 -= V_157 ;
}
if ( F_54 ( V_158 ) ) {
V_100 -> V_120 = V_8 -> V_16 . V_18 ;
V_100 -> V_101 |= V_117 ;
V_145 -= V_159 ;
}
if ( F_54 ( V_160 ) ) {
V_100 -> V_101 |= V_110 ;
if ( F_52 ( ! ( V_109 & V_100 -> V_101 ) ) )
V_145 -= V_161 ;
}
if ( V_148 && V_148 -> V_162 . V_82 >= 0 ) {
T_4 V_163 = V_148 -> V_162 . V_82 ;
V_163 += V_148 -> V_162 . exp ? V_137 :
V_140 ;
V_163 = ( V_163 + 3 ) & ~ 3U ;
if ( V_145 >= V_163 ) {
V_100 -> V_101 |= V_132 ;
V_100 -> V_135 = & V_148 -> V_162 ;
V_145 -= V_163 ;
V_8 -> V_164 = 1 ;
V_8 -> V_165 = V_148 -> V_162 . exp ? 1 : 0 ;
}
}
return V_146 - V_145 ;
}
static unsigned int F_58 ( struct V_75 * V_76 ,
unsigned int V_21 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
const struct V_143 * V_144 ,
struct V_133 * V_134 )
{
struct V_166 * V_167 = F_44 ( V_76 ) ;
unsigned int V_145 = V_146 ;
#ifdef F_56
if ( V_144 ) {
V_100 -> V_101 |= V_102 ;
V_145 -= V_152 ;
V_167 -> V_168 &= ! V_167 -> V_169 ;
}
#endif
V_100 -> V_21 = V_21 ;
V_145 -= V_153 ;
if ( F_54 ( V_167 -> V_17 ) ) {
V_100 -> V_120 = V_167 -> V_18 ;
V_100 -> V_101 |= V_117 ;
V_145 -= V_159 ;
}
if ( F_54 ( V_167 -> V_168 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = F_57 ( V_4 ) + F_59 ( V_76 ) -> V_170 ;
V_100 -> V_116 = V_76 -> V_156 ;
V_145 -= V_157 ;
}
if ( F_54 ( V_167 -> V_169 ) ) {
V_100 -> V_101 |= V_110 ;
if ( F_52 ( ! V_167 -> V_168 ) )
V_145 -= V_161 ;
}
if ( V_134 != NULL && V_134 -> V_82 >= 0 ) {
T_4 V_163 = V_134 -> V_82 ;
V_163 += V_134 -> exp ? V_137 :
V_140 ;
V_163 = ( V_163 + 3 ) & ~ 3U ;
if ( V_145 >= V_163 ) {
V_100 -> V_101 |= V_132 ;
V_100 -> V_135 = V_134 ;
V_145 -= V_163 ;
}
}
return V_146 - V_145 ;
}
static unsigned int F_60 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
struct V_143 * * V_144 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_171 = 0 ;
unsigned int V_172 ;
V_100 -> V_101 = 0 ;
#ifdef F_56
* V_144 = V_8 -> V_150 -> V_151 ( V_2 , V_2 ) ;
if ( F_52 ( * V_144 ) ) {
V_100 -> V_101 |= V_102 ;
V_171 += V_152 ;
}
#else
* V_144 = NULL ;
#endif
if ( F_54 ( V_8 -> V_16 . V_168 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = V_4 ? F_57 ( V_4 ) + V_8 -> V_155 : 0 ;
V_100 -> V_116 = V_8 -> V_16 . V_156 ;
V_171 += V_157 ;
}
V_172 = V_8 -> V_16 . V_173 + V_8 -> V_16 . V_124 ;
if ( F_52 ( V_172 ) ) {
const unsigned int V_145 = V_146 - V_171 ;
V_100 -> V_121 =
F_31 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_171 += V_174 +
V_100 -> V_121 * V_130 ;
}
return V_171 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_175 ) &
( V_176 | V_177 | V_178 |
V_179 | V_180 ) ) {
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_181 > V_8 -> V_182 &&
V_8 -> V_27 > F_23 ( V_8 ) )
F_62 ( V_2 ) ;
F_63 ( V_2 , F_64 ( V_2 ) , V_8 -> V_183 ,
0 , V_184 ) ;
}
}
static void F_65 ( unsigned long V_185 )
{
struct V_186 * V_187 = (struct V_186 * ) V_185 ;
F_66 ( V_188 ) ;
unsigned long V_89 ;
struct V_189 * V_190 , * V_191 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_67 ( V_89 ) ;
F_68 ( & V_187 -> V_192 , & V_188 ) ;
F_69 ( V_89 ) ;
F_70 (q, n, &list) {
V_8 = F_71 ( V_190 , struct V_7 , V_193 ) ;
F_72 ( & V_8 -> V_193 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_73 () ;
F_74 ( V_194 , & V_2 -> V_195 ) ;
if ( ! V_2 -> V_196 . V_197 &&
F_75 ( V_198 , & V_2 -> V_195 ) ) {
F_76 ( V_2 ) ;
if ( ! F_77 ( V_2 ) ) {
F_74 ( V_198 , & V_2 -> V_195 ) ;
F_61 ( V_2 ) ;
}
F_78 ( V_2 ) ;
}
F_79 ( V_2 ) ;
}
}
void F_80 ( struct V_1 * V_2 )
{
unsigned long V_89 , V_199 ;
do {
V_89 = V_2 -> V_195 ;
if ( ! ( V_89 & V_200 ) )
return;
V_199 = V_89 & ~ V_200 ;
} while ( F_81 ( & V_2 -> V_195 , V_89 , V_199 ) != V_89 );
if ( V_89 & V_201 )
F_61 ( V_2 ) ;
F_82 ( V_2 ) ;
if ( V_89 & V_202 ) {
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
}
if ( V_89 & V_203 ) {
F_85 ( V_2 ) ;
F_84 ( V_2 ) ;
}
if ( V_89 & V_204 ) {
F_2 ( V_2 ) -> V_205 -> V_206 ( V_2 ) ;
F_84 ( V_2 ) ;
}
}
void T_9 F_86 ( void )
{
int V_207 ;
F_87 (i) {
struct V_186 * V_187 = & F_88 ( V_186 , V_207 ) ;
F_89 ( & V_187 -> V_192 ) ;
F_90 ( & V_187 -> V_208 ,
F_65 ,
( unsigned long ) V_187 ) ;
}
}
void F_91 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_89 , V_209 , V_210 ;
int V_211 ;
V_211 = F_92 ( V_4 -> V_212 - 1 , & V_2 -> V_213 ) ;
if ( V_211 >= F_93 ( 1 ) && F_94 () == V_214 )
goto V_215;
for ( V_210 = F_95 ( V_2 -> V_195 ) ; ; V_210 = V_209 ) {
struct V_186 * V_187 ;
bool V_216 ;
if ( ! ( V_210 & V_217 ) || ( V_210 & V_218 ) )
goto V_215;
V_209 = ( V_210 & ~ V_217 ) | V_218 | V_201 ;
V_209 = F_81 ( & V_2 -> V_195 , V_210 , V_209 ) ;
if ( V_209 != V_210 )
continue;
F_67 ( V_89 ) ;
V_187 = F_96 ( & V_186 ) ;
V_216 = F_97 ( & V_187 -> V_192 ) ;
F_98 ( & V_8 -> V_193 , & V_187 -> V_192 ) ;
if ( V_216 )
F_99 ( & V_187 -> V_208 ) ;
F_69 ( V_89 ) ;
return;
}
V_215:
F_79 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_219 ,
T_10 V_220 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_221 * V_222 ;
struct V_7 * V_8 ;
struct V_223 * V_224 ;
struct V_99 V_100 ;
unsigned int V_225 , V_226 ;
struct V_143 * V_144 ;
struct V_77 * V_78 ;
int V_227 ;
F_101 ( ! V_4 || ! F_6 ( V_4 ) ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_219 ) {
F_102 ( & V_4 -> V_228 ) ;
F_5 ( V_4 ) -> V_229 . V_230 = F_5 ( V_4 ) -> V_12
- V_8 -> V_96 ;
F_103 ( V_2 , V_4 ) ;
if ( F_52 ( F_104 ( V_4 ) ) )
V_4 = F_105 ( V_4 , V_220 ) ;
else
V_4 = F_106 ( V_4 , V_220 ) ;
if ( F_52 ( ! V_4 ) )
return - V_231 ;
}
V_222 = F_107 ( V_2 ) ;
V_224 = F_5 ( V_4 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
if ( F_52 ( V_224 -> V_65 & V_94 ) )
V_225 = F_55 ( V_2 , V_4 , & V_100 , & V_144 ) ;
else
V_225 = F_60 ( V_2 , V_4 , & V_100 ,
& V_144 ) ;
V_226 = V_225 + sizeof( struct V_77 ) ;
V_4 -> V_232 = F_108 ( V_2 ) < F_93 ( 1 ) ;
V_4 -> V_233 = 0 ;
F_109 ( V_4 , V_226 ) ;
F_110 ( V_4 ) ;
F_111 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_234 = F_112 ( V_4 ) ? V_235 : F_91 ;
F_113 ( V_4 , V_2 ) ;
F_114 ( V_4 -> V_212 , & V_2 -> V_213 ) ;
F_115 ( V_4 , V_2 -> V_236 ) ;
V_78 = (struct V_77 * ) V_4 -> V_185 ;
V_78 -> V_237 = V_222 -> V_238 ;
V_78 -> V_239 = V_222 -> V_240 ;
V_78 -> V_83 = F_53 ( V_224 -> V_83 ) ;
V_78 -> V_241 = F_53 ( V_8 -> V_61 ) ;
* ( ( ( V_242 * ) V_78 ) + 6 ) = F_116 ( ( ( V_226 >> 2 ) << 12 ) |
V_224 -> V_65 ) ;
V_78 -> V_243 = 0 ;
V_78 -> V_244 = 0 ;
if ( F_52 ( F_50 ( V_8 ) && F_11 ( V_224 -> V_83 , V_8 -> V_97 ) ) ) {
if ( F_11 ( V_8 -> V_97 , V_224 -> V_83 + 0x10000 ) ) {
V_78 -> V_244 = F_116 ( V_8 -> V_97 - V_224 -> V_83 ) ;
V_78 -> V_245 = 1 ;
} else if ( F_117 ( V_224 -> V_83 + 0xFFFF , V_8 -> V_11 ) ) {
V_78 -> V_244 = F_116 ( 0xFFFF ) ;
V_78 -> V_245 = 1 ;
}
}
F_51 ( ( T_8 * ) ( V_78 + 1 ) , V_8 , & V_100 ) ;
F_46 ( V_4 ) -> V_86 = V_2 -> V_246 ;
if ( F_54 ( ! ( V_224 -> V_65 & V_94 ) ) ) {
V_78 -> V_247 = F_116 ( F_32 ( V_2 ) ) ;
F_45 ( V_2 , V_4 , V_78 , V_226 ) ;
} else {
V_78 -> V_247 = F_116 ( F_20 ( V_8 -> V_46 , 65535U ) ) ;
}
#ifdef F_56
if ( V_144 ) {
F_118 ( V_2 , V_248 ) ;
V_8 -> V_150 -> V_249 ( V_100 . V_106 ,
V_144 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_205 -> V_250 ( V_2 , V_4 ) ;
if ( F_54 ( V_224 -> V_65 & V_251 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_82 != V_226 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_252 += F_6 ( V_4 ) ;
}
if ( F_117 ( V_224 -> V_12 , V_8 -> V_11 ) || V_224 -> V_83 == V_224 -> V_12 )
F_119 ( F_9 ( V_2 ) , V_253 ,
F_6 ( V_4 ) ) ;
V_8 -> V_254 += F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_255 = F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_256 = F_120 ( V_4 ) ;
V_4 -> V_257 = 0 ;
memset ( V_4 -> V_258 , 0 , F_21 ( sizeof( struct V_259 ) ,
sizeof( struct V_260 ) ) ) ;
V_227 = V_6 -> V_205 -> V_261 ( V_2 , V_4 , & V_222 -> V_262 . V_263 ) ;
if ( F_54 ( V_227 <= 0 ) )
return V_227 ;
F_121 ( V_2 ) ;
return F_122 ( V_227 ) ;
}
static void F_123 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_264 = F_5 ( V_4 ) -> V_12 ;
F_124 ( V_4 ) ;
F_125 ( V_2 , V_4 ) ;
V_2 -> V_265 += V_4 -> V_212 ;
F_126 ( V_2 , V_4 -> V_212 ) ;
}
static void F_127 ( struct V_3 * V_4 , unsigned int V_266 )
{
if ( V_4 -> V_82 <= V_266 || V_4 -> V_90 == V_267 ) {
F_49 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_268 = 0 ;
} else {
F_49 ( V_4 , F_128 ( V_4 -> V_82 , V_266 ) ) ;
F_5 ( V_4 ) -> V_268 = V_266 ;
}
}
static void F_129 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_269 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_270 || F_130 ( V_8 ) )
return;
if ( F_117 ( F_131 ( V_8 ) , F_5 ( V_4 ) -> V_83 ) )
V_8 -> V_271 -= V_269 ;
}
static void F_132 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_269 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_269 ;
if ( F_5 ( V_4 ) -> V_93 & V_272 )
V_8 -> V_270 -= V_269 ;
if ( F_5 ( V_4 ) -> V_93 & V_273 )
V_8 -> V_182 -= V_269 ;
if ( F_5 ( V_4 ) -> V_93 & V_274 )
V_8 -> V_181 -= V_269 ;
if ( F_130 ( V_8 ) && V_269 > 0 )
V_8 -> V_270 -= F_31 ( T_4 , V_8 -> V_270 , V_269 ) ;
F_129 ( V_2 , V_4 , V_269 ) ;
if ( V_8 -> V_275 &&
F_11 ( F_5 ( V_4 ) -> V_83 , F_5 ( V_8 -> V_275 ) -> V_83 ) &&
( F_133 ( V_8 ) || ( F_5 ( V_4 ) -> V_93 & V_272 ) ) )
V_8 -> V_276 -= V_269 ;
F_134 ( V_8 ) ;
}
static bool F_135 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_277 ||
( F_46 ( V_4 ) -> V_278 & V_279 ) ;
}
static void F_136 ( struct V_3 * V_4 , struct V_3 * V_280 )
{
struct V_281 * V_282 = F_46 ( V_4 ) ;
if ( F_52 ( F_135 ( V_4 ) ) &&
! F_11 ( V_282 -> V_283 , F_5 ( V_280 ) -> V_83 ) ) {
struct V_281 * V_284 = F_46 ( V_280 ) ;
T_7 V_285 = V_282 -> V_278 & V_279 ;
V_282 -> V_278 &= ~ V_285 ;
V_284 -> V_278 |= V_285 ;
F_137 ( V_282 -> V_283 , V_284 -> V_283 ) ;
F_5 ( V_280 ) -> V_277 = F_5 ( V_4 ) -> V_277 ;
F_5 ( V_4 ) -> V_277 = 0 ;
}
}
static void F_138 ( struct V_3 * V_4 , struct V_3 * V_280 )
{
F_5 ( V_280 ) -> V_286 = F_5 ( V_4 ) -> V_286 ;
F_5 ( V_4 ) -> V_286 = 0 ;
}
int F_139 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_82 ,
unsigned int V_266 , T_10 V_287 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_288 ;
int V_289 , V_290 ;
int V_291 ;
T_7 V_89 ;
if ( F_140 ( V_82 > V_4 -> V_82 ) )
return - V_292 ;
V_289 = F_141 ( V_4 ) - V_82 ;
if ( V_289 < 0 )
V_289 = 0 ;
if ( F_142 ( V_4 , V_287 ) )
return - V_293 ;
V_288 = F_143 ( V_2 , V_289 , V_287 , true ) ;
if ( ! V_288 )
return - V_293 ;
V_2 -> V_265 += V_288 -> V_212 ;
F_126 ( V_2 , V_288 -> V_212 ) ;
V_291 = V_4 -> V_82 - V_82 - V_289 ;
V_288 -> V_212 += V_291 ;
V_4 -> V_212 -= V_291 ;
F_5 ( V_288 ) -> V_83 = F_5 ( V_4 ) -> V_83 + V_82 ;
F_5 ( V_288 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_288 ) -> V_83 ;
V_89 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_89 & ~ ( V_95 | V_294 ) ;
F_5 ( V_288 ) -> V_65 = V_89 ;
F_5 ( V_288 ) -> V_93 = F_5 ( V_4 ) -> V_93 ;
F_138 ( V_4 , V_288 ) ;
if ( ! F_46 ( V_4 ) -> V_295 && V_4 -> V_90 != V_91 ) {
V_288 -> V_92 = F_144 ( V_4 -> V_185 + V_82 ,
F_145 ( V_288 , V_289 ) ,
V_289 , 0 ) ;
F_146 ( V_4 , V_82 ) ;
V_4 -> V_92 = F_147 ( V_4 -> V_92 , V_288 -> V_92 , V_82 ) ;
} else {
V_4 -> V_90 = V_91 ;
F_148 ( V_4 , V_288 , V_82 ) ;
}
V_288 -> V_90 = V_4 -> V_90 ;
V_288 -> V_257 = V_4 -> V_257 ;
F_136 ( V_4 , V_288 ) ;
V_290 = F_6 ( V_4 ) ;
F_127 ( V_4 , V_266 ) ;
F_127 ( V_288 , V_266 ) ;
F_5 ( V_288 ) -> V_229 = F_5 ( V_4 ) -> V_229 ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_288 ) -> V_12 ) ) {
int V_296 = V_290 - F_6 ( V_4 ) -
F_6 ( V_288 ) ;
if ( V_296 )
F_132 ( V_2 , V_4 , V_296 ) ;
}
F_124 ( V_288 ) ;
F_149 ( V_4 , V_288 , V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_3 * V_4 , int V_82 )
{
struct V_281 * V_282 ;
int V_207 , V_297 , V_298 ;
V_298 = F_31 ( int , V_82 , F_141 ( V_4 ) ) ;
if ( V_298 ) {
F_151 ( V_4 , V_298 ) ;
V_82 -= V_298 ;
if ( ! V_82 )
return 0 ;
}
V_298 = V_82 ;
V_297 = 0 ;
V_282 = F_46 ( V_4 ) ;
for ( V_207 = 0 ; V_207 < V_282 -> V_295 ; V_207 ++ ) {
int V_171 = F_152 ( & V_282 -> V_299 [ V_207 ] ) ;
if ( V_171 <= V_298 ) {
F_153 ( V_4 , V_207 ) ;
V_298 -= V_171 ;
} else {
V_282 -> V_299 [ V_297 ] = V_282 -> V_299 [ V_207 ] ;
if ( V_298 ) {
V_282 -> V_299 [ V_297 ] . V_300 += V_298 ;
F_154 ( & V_282 -> V_299 [ V_297 ] , V_298 ) ;
V_298 = 0 ;
}
V_297 ++ ;
}
}
V_282 -> V_295 = V_297 ;
F_155 ( V_4 ) ;
V_4 -> V_301 -= V_82 ;
V_4 -> V_82 = V_4 -> V_301 ;
return V_82 ;
}
int F_156 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_82 )
{
T_4 V_302 ;
if ( F_142 ( V_4 , V_184 ) )
return - V_293 ;
V_302 = F_150 ( V_4 , V_82 ) ;
F_5 ( V_4 ) -> V_83 += V_82 ;
V_4 -> V_90 = V_91 ;
if ( V_302 ) {
V_4 -> V_212 -= V_302 ;
V_2 -> V_265 -= V_302 ;
F_157 ( V_2 , V_302 ) ;
F_158 ( V_2 , V_303 ) ;
}
if ( F_6 ( V_4 ) > 1 )
F_127 ( V_4 , F_120 ( V_4 ) ) ;
return 0 ;
}
static inline int F_159 ( struct V_1 * V_2 , int V_304 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_266 ;
V_266 = V_304 - V_6 -> V_205 -> V_305 - sizeof( struct V_77 ) ;
if ( V_6 -> V_205 -> V_306 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_160 ( V_20 ) )
V_266 -= V_6 -> V_205 -> V_306 ;
}
if ( V_266 > V_8 -> V_16 . V_307 )
V_266 = V_8 -> V_16 . V_307 ;
V_266 -= V_6 -> V_308 ;
if ( V_266 < 48 )
V_266 = 48 ;
return V_266 ;
}
int F_161 ( struct V_1 * V_2 , int V_304 )
{
return F_159 ( V_2 , V_304 ) -
( F_3 ( V_2 ) -> V_81 - sizeof( struct V_77 ) ) ;
}
int F_162 ( struct V_1 * V_2 , int V_21 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_309 ;
V_309 = V_21 +
V_8 -> V_81 +
V_6 -> V_308 +
V_6 -> V_205 -> V_305 ;
if ( V_6 -> V_205 -> V_306 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_160 ( V_20 ) )
V_309 += V_6 -> V_205 -> V_306 ;
}
return V_309 ;
}
void F_163 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_310 * V_310 = F_9 ( V_2 ) ;
V_6 -> V_311 . V_312 = V_310 -> V_71 . V_313 > 1 ;
V_6 -> V_311 . V_314 = V_8 -> V_16 . V_307 + sizeof( struct V_77 ) +
V_6 -> V_205 -> V_305 ;
V_6 -> V_311 . V_315 = F_162 ( V_2 , V_310 -> V_71 . V_316 ) ;
V_6 -> V_311 . V_317 = 0 ;
if ( V_6 -> V_311 . V_312 )
V_6 -> V_311 . V_318 = V_32 ;
}
unsigned int F_164 ( struct V_1 * V_2 , T_4 V_304 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_266 ;
if ( V_6 -> V_311 . V_314 > V_304 )
V_6 -> V_311 . V_314 = V_304 ;
V_266 = F_161 ( V_2 , V_304 ) ;
V_266 = F_165 ( V_8 , V_266 ) ;
V_6 -> V_319 = V_304 ;
if ( V_6 -> V_311 . V_312 )
V_266 = F_20 ( V_266 , F_161 ( V_2 , V_6 -> V_311 . V_315 ) ) ;
V_8 -> V_320 = V_266 ;
return V_266 ;
}
unsigned int F_64 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_19 * V_20 = F_14 ( V_2 ) ;
T_4 V_266 ;
unsigned int V_321 ;
struct V_99 V_100 ;
struct V_143 * V_144 ;
V_266 = V_8 -> V_320 ;
if ( V_20 ) {
T_4 V_309 = F_166 ( V_20 ) ;
if ( V_309 != F_2 ( V_2 ) -> V_319 )
V_266 = F_164 ( V_2 , V_309 ) ;
}
V_321 = F_60 ( V_2 , NULL , & V_100 , & V_144 ) +
sizeof( struct V_77 ) ;
if ( V_321 != V_8 -> V_81 ) {
int V_24 = ( int ) V_321 - V_8 -> V_81 ;
V_266 -= V_24 ;
}
return V_266 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_322 == V_323 &&
V_2 -> V_324 && ! F_75 ( V_325 , & V_2 -> V_324 -> V_89 ) ) {
T_4 V_326 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_327 = F_21 ( V_8 -> V_33 , V_326 ) ;
if ( V_327 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_327 ) >> 1 ;
}
V_8 -> V_33 = 0 ;
}
V_8 -> V_31 = V_32 ;
}
static void F_168 ( struct V_1 * V_2 , bool V_328 )
{
const struct V_329 * V_330 = F_2 ( V_2 ) -> V_331 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_96 , V_8 -> V_332 ) ||
V_8 -> V_10 > V_8 -> V_333 ) {
V_8 -> V_333 = V_8 -> V_10 ;
V_8 -> V_332 = V_8 -> V_11 ;
V_8 -> V_328 = V_328 ;
}
if ( F_169 ( V_2 ) ) {
V_8 -> V_33 = 0 ;
V_8 -> V_31 = V_32 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_33 )
V_8 -> V_33 = V_8 -> V_10 ;
if ( V_334 &&
( T_3 ) ( V_32 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 &&
! V_330 -> V_335 )
F_167 ( V_2 ) ;
if ( ! F_170 ( V_2 ) && V_2 -> V_324 &&
F_75 ( V_325 , & V_2 -> V_324 -> V_89 ) &&
( 1 << V_2 -> V_175 ) & ( V_176 | V_179 ) )
F_171 ( V_2 , V_336 ) ;
}
}
static bool F_172 ( const struct V_7 * V_8 )
{
return F_117 ( V_8 -> V_337 , V_8 -> V_96 ) &&
! F_117 ( V_8 -> V_337 , V_8 -> V_11 ) ;
}
static void F_173 ( struct V_7 * V_8 , unsigned int V_266 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_82 < F_6 ( V_4 ) * V_266 )
V_8 -> V_337 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_174 ( bool V_338 , const struct V_7 * V_8 ,
int V_183 )
{
return V_338 &&
( ( V_183 & V_339 ) ||
( ! V_183 && V_8 -> V_10 && F_172 ( V_8 ) ) ) ;
}
T_4 F_175 ( const struct V_1 * V_2 , unsigned int V_266 ,
int V_340 )
{
T_4 V_341 , V_342 ;
V_341 = F_20 ( V_2 -> V_343 >> 10 ,
V_2 -> V_344 - 1 - V_345 ) ;
V_342 = F_30 ( T_4 , V_341 / V_266 , V_340 ) ;
return F_31 ( T_4 , V_342 , V_2 -> V_346 ) ;
}
static T_4 F_176 ( struct V_1 * V_2 , unsigned int V_266 )
{
const struct V_329 * V_330 = F_2 ( V_2 ) -> V_331 ;
T_4 V_347 = V_330 -> V_348 ? V_330 -> V_348 ( V_2 ) : 0 ;
return V_347 ? :
F_175 ( V_2 , V_266 , V_349 ) ;
}
static unsigned int F_177 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_266 ,
unsigned int V_350 ,
int V_183 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_338 , V_351 , V_247 , V_352 ;
V_247 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_83 ;
V_352 = V_266 * V_350 ;
if ( F_54 ( V_352 <= V_247 && V_4 != F_178 ( V_2 ) ) )
return V_352 ;
V_351 = F_20 ( V_4 -> V_82 , V_247 ) ;
if ( V_352 <= V_351 )
return V_352 ;
V_338 = V_351 % V_266 ;
if ( F_174 ( V_338 != 0 , V_8 , V_183 ) )
return V_351 - V_338 ;
return V_351 ;
}
static inline unsigned int F_179 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_230 , V_26 , V_353 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_95 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_230 = F_23 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_230 >= V_26 )
return 0 ;
V_353 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_353 , V_26 - V_230 ) ;
}
static int F_180 ( struct V_3 * V_4 , unsigned int V_266 )
{
int V_347 = F_6 ( V_4 ) ;
if ( ! V_347 || ( V_347 > 1 && F_120 ( V_4 ) != V_266 ) ) {
F_127 ( V_4 , V_266 ) ;
V_347 = F_6 ( V_4 ) ;
}
return V_347 ;
}
static inline bool F_181 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_354 , int V_183 )
{
if ( V_183 & V_355 )
return true ;
if ( F_50 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_95 ) )
return true ;
if ( ! F_174 ( V_4 -> V_82 < V_354 , V_8 , V_183 ) )
return true ;
return false ;
}
static bool F_182 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_354 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_82 > V_354 )
V_12 = F_5 ( V_4 ) -> V_83 + V_354 ;
return ! F_117 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_183 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_354 , int V_183 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_356 ;
F_180 ( V_4 , V_354 ) ;
if ( ! F_181 ( V_8 , V_4 , V_354 , V_183 ) )
return 0 ;
V_356 = F_179 ( V_8 , V_4 ) ;
if ( V_356 && ! F_182 ( V_8 , V_4 , V_354 ) )
V_356 = 0 ;
return V_356 ;
}
bool F_184 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_170 ( V_2 ) ;
return V_4 &&
F_183 ( V_2 , V_4 , F_64 ( V_2 ) ,
( F_185 ( V_2 , V_4 ) ?
V_8 -> V_183 : V_355 ) ) ;
}
static int F_186 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_82 ,
unsigned int V_266 , T_10 V_287 )
{
struct V_3 * V_288 ;
int V_291 = V_4 -> V_82 - V_82 ;
T_7 V_89 ;
if ( V_4 -> V_82 != V_4 -> V_301 )
return F_139 ( V_2 , V_4 , V_82 , V_266 , V_287 ) ;
V_288 = F_143 ( V_2 , 0 , V_287 , true ) ;
if ( F_52 ( ! V_288 ) )
return - V_293 ;
V_2 -> V_265 += V_288 -> V_212 ;
F_126 ( V_2 , V_288 -> V_212 ) ;
V_288 -> V_212 += V_291 ;
V_4 -> V_212 -= V_291 ;
F_5 ( V_288 ) -> V_83 = F_5 ( V_4 ) -> V_83 + V_82 ;
F_5 ( V_288 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_288 ) -> V_83 ;
V_89 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_89 & ~ ( V_95 | V_294 ) ;
F_5 ( V_288 ) -> V_65 = V_89 ;
F_5 ( V_288 ) -> V_93 = 0 ;
F_138 ( V_4 , V_288 ) ;
V_288 -> V_90 = V_4 -> V_90 = V_91 ;
F_148 ( V_4 , V_288 , V_82 ) ;
F_136 ( V_4 , V_288 ) ;
F_127 ( V_4 , V_266 ) ;
F_127 ( V_288 , V_266 ) ;
F_124 ( V_288 ) ;
F_149 ( V_4 , V_288 , V_2 ) ;
return 0 ;
}
static bool F_187 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_328 , T_4 V_350 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_357 , V_358 , V_359 , V_360 , V_230 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_228 V_34 ;
struct V_3 * V_192 ;
int V_361 ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
goto V_362;
if ( V_6 -> V_322 >= V_363 )
goto V_362;
if ( ( T_3 ) ( V_32 - V_8 -> V_36 ) > 0 )
goto V_362;
V_230 = F_23 ( V_8 ) ;
F_101 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_230 ) ) ;
V_358 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_83 ;
V_359 = ( V_8 -> V_27 - V_230 ) * V_8 -> V_320 ;
V_360 = F_20 ( V_358 , V_359 ) ;
if ( V_360 >= V_350 * V_8 -> V_320 )
goto V_362;
if ( ( V_4 != F_178 ( V_2 ) ) && ( V_360 >= V_4 -> V_82 ) )
goto V_362;
V_361 = F_188 ( V_364 ) ;
if ( V_361 ) {
T_4 V_365 = F_20 ( V_8 -> V_366 , V_8 -> V_27 * V_8 -> V_320 ) ;
V_365 /= V_361 ;
if ( V_360 >= V_365 )
goto V_362;
} else {
if ( V_360 > F_189 ( V_8 ) * V_8 -> V_320 )
goto V_362;
}
V_192 = F_190 ( V_2 ) ;
F_102 ( & V_34 ) ;
V_357 = F_191 ( & V_34 , & V_192 -> V_228 ) ;
if ( V_357 < ( V_8 -> V_367 >> 4 ) )
goto V_362;
if ( V_359 < V_358 && V_359 <= V_4 -> V_82 )
* V_328 = true ;
return true ;
V_362:
return false ;
}
static inline void F_192 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_310 * V_310 = F_9 ( V_2 ) ;
T_4 V_368 ;
T_3 V_24 ;
V_368 = V_310 -> V_71 . V_369 ;
V_24 = V_32 - V_6 -> V_311 . V_318 ;
if ( F_52 ( V_24 >= V_368 * V_370 ) ) {
int V_21 = F_64 ( V_2 ) ;
V_6 -> V_311 . V_317 = 0 ;
V_6 -> V_311 . V_314 = V_8 -> V_16 . V_307 +
sizeof( struct V_77 ) +
V_6 -> V_205 -> V_305 ;
V_6 -> V_311 . V_315 = F_162 ( V_2 , V_21 ) ;
V_6 -> V_311 . V_318 = V_32 ;
}
}
static int F_193 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 , * V_371 , * V_372 ;
struct V_310 * V_310 = F_9 ( V_2 ) ;
int V_317 ;
int V_373 ;
int V_374 , V_82 ;
int V_266 ;
int V_368 ;
if ( F_54 ( ! V_6 -> V_311 . V_312 ||
V_6 -> V_311 . V_317 ||
F_2 ( V_2 ) -> V_322 != V_323 ||
V_8 -> V_27 < 11 ||
V_8 -> V_16 . V_173 || V_8 -> V_16 . V_124 ) )
return - 1 ;
V_266 = F_64 ( V_2 ) ;
V_317 = F_161 ( V_2 , ( V_6 -> V_311 . V_314 +
V_6 -> V_311 . V_315 ) >> 1 ) ;
V_373 = V_317 + ( V_8 -> V_375 + 1 ) * V_8 -> V_320 ;
V_368 = V_6 -> V_311 . V_314 - V_6 -> V_311 . V_315 ;
if ( V_317 > F_161 ( V_2 , V_6 -> V_311 . V_314 ) ||
V_368 < V_310 -> V_71 . V_376 ) {
F_192 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_264 - V_8 -> V_11 < V_373 )
return - 1 ;
if ( V_8 -> V_366 < V_373 )
return - 1 ;
if ( F_117 ( V_8 -> V_11 + V_373 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_371 = F_143 ( V_2 , V_317 , V_184 , false ) ;
if ( ! V_371 )
return - 1 ;
V_2 -> V_265 += V_371 -> V_212 ;
F_126 ( V_2 , V_371 -> V_212 ) ;
V_4 = F_170 ( V_2 ) ;
F_5 ( V_371 ) -> V_83 = F_5 ( V_4 ) -> V_83 ;
F_5 ( V_371 ) -> V_12 = F_5 ( V_4 ) -> V_83 + V_317 ;
F_5 ( V_371 ) -> V_65 = V_251 ;
F_5 ( V_371 ) -> V_93 = 0 ;
V_371 -> V_92 = 0 ;
V_371 -> V_90 = V_4 -> V_90 ;
F_194 ( V_371 , V_4 , V_2 ) ;
V_82 = 0 ;
F_195 (skb, next, sk) {
V_374 = F_31 ( int , V_4 -> V_82 , V_317 - V_82 ) ;
if ( V_371 -> V_90 ) {
F_196 ( V_4 , 0 , F_145 ( V_371 , V_374 ) , V_374 ) ;
} else {
T_11 V_92 = F_197 ( V_4 , 0 ,
F_145 ( V_371 , V_374 ) ,
V_374 , 0 ) ;
V_371 -> V_92 = F_198 ( V_371 -> V_92 , V_92 , V_82 ) ;
}
if ( V_4 -> V_82 <= V_374 ) {
F_5 ( V_371 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_199 ( V_4 , V_2 ) ;
F_200 ( V_2 , V_4 ) ;
} else {
F_5 ( V_371 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_95 | V_294 ) ;
if ( ! F_46 ( V_4 ) -> V_295 ) {
F_201 ( V_4 , V_374 ) ;
if ( V_4 -> V_90 != V_91 )
V_4 -> V_92 = F_202 ( V_4 -> V_185 ,
V_4 -> V_82 , 0 ) ;
} else {
F_150 ( V_4 , V_374 ) ;
F_127 ( V_4 , V_266 ) ;
}
F_5 ( V_4 ) -> V_83 += V_374 ;
}
V_82 += V_374 ;
if ( V_82 >= V_317 )
break;
}
F_180 ( V_371 , V_371 -> V_82 ) ;
if ( ! F_100 ( V_2 , V_371 , 1 , V_184 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_371 ) ;
V_6 -> V_311 . V_317 = F_162 ( V_2 , V_371 -> V_82 ) ;
V_8 -> V_377 . V_378 = F_5 ( V_371 ) -> V_83 ;
V_8 -> V_377 . V_379 = F_5 ( V_371 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_203 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_380 )
{
unsigned int V_360 ;
V_360 = F_21 ( 2 * V_4 -> V_212 , V_2 -> V_343 >> 10 ) ;
V_360 = F_31 ( T_4 , V_360 , V_381 ) ;
V_360 <<= V_380 ;
if ( F_204 ( & V_2 -> V_213 ) > V_360 ) {
if ( V_4 == V_2 -> V_382 . V_372 ||
V_4 -> V_383 == V_2 -> V_382 . V_372 )
return false ;
F_205 ( V_384 , & V_2 -> V_195 ) ;
F_206 () ;
if ( F_204 ( & V_2 -> V_213 ) > V_360 )
return true ;
}
return false ;
}
static void F_207 ( struct V_7 * V_8 , const enum V_385 V_386 )
{
const T_4 V_34 = V_32 ;
if ( V_8 -> V_387 > V_388 )
V_8 -> V_389 [ V_8 -> V_387 - 1 ] += V_34 - V_8 -> V_390 ;
V_8 -> V_390 = V_34 ;
V_8 -> V_387 = V_386 ;
}
void F_171 ( struct V_1 * V_2 , const enum V_385 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( type > V_8 -> V_387 )
F_207 ( V_8 , type ) ;
}
void F_208 ( struct V_1 * V_2 , const enum V_385 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_209 ( V_2 ) )
F_207 ( V_8 , V_388 ) ;
else if ( type == V_8 -> V_387 )
F_207 ( V_8 , V_391 ) ;
}
static bool F_63 ( struct V_1 * V_2 , unsigned int V_266 , int V_183 ,
int V_392 , T_10 V_287 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_347 , V_393 ;
int V_356 ;
int V_394 ;
bool V_328 = false , V_395 = false ;
T_4 V_350 ;
V_393 = 0 ;
if ( ! V_392 ) {
V_394 = F_193 ( V_2 ) ;
if ( ! V_394 ) {
return false ;
} else if ( V_394 > 0 ) {
V_393 = 1 ;
}
}
V_350 = F_176 ( V_2 , V_266 ) ;
while ( ( V_4 = F_170 ( V_2 ) ) ) {
unsigned int V_360 ;
V_347 = F_180 ( V_4 , V_266 ) ;
F_101 ( ! V_347 ) ;
if ( F_52 ( V_8 -> V_396 ) && V_8 -> V_397 == V_398 ) {
F_102 ( & V_4 -> V_228 ) ;
goto V_396;
}
V_356 = F_179 ( V_8 , V_4 ) ;
if ( ! V_356 ) {
if ( V_392 == 2 )
V_356 = 1 ;
else
break;
}
if ( F_52 ( ! F_182 ( V_8 , V_4 , V_266 ) ) ) {
V_395 = true ;
break;
}
if ( V_347 == 1 ) {
if ( F_52 ( ! F_181 ( V_8 , V_4 , V_266 ,
( F_185 ( V_2 , V_4 ) ?
V_183 : V_355 ) ) ) )
break;
} else {
if ( ! V_392 &&
F_187 ( V_2 , V_4 , & V_328 ,
V_350 ) )
break;
}
V_360 = V_266 ;
if ( V_347 > 1 && ! F_50 ( V_8 ) )
V_360 = F_177 ( V_2 , V_4 , V_266 ,
F_31 (unsigned int,
cwnd_quota,
max_segs) ,
V_183 ) ;
if ( V_4 -> V_82 > V_360 &&
F_52 ( F_186 ( V_2 , V_4 , V_360 , V_266 , V_287 ) ) )
break;
if ( F_75 ( V_198 , & V_2 -> V_195 ) )
F_74 ( V_198 , & V_2 -> V_195 ) ;
if ( F_203 ( V_2 , V_4 , 0 ) )
break;
if ( F_52 ( F_100 ( V_2 , V_4 , 1 , V_287 ) ) )
break;
V_396:
F_1 ( V_2 , V_4 ) ;
F_173 ( V_8 , V_266 , V_4 ) ;
V_393 += F_6 ( V_4 ) ;
if ( V_392 )
break;
}
if ( V_395 )
F_171 ( V_2 , V_399 ) ;
else
F_208 ( V_2 , V_399 ) ;
if ( F_54 ( V_393 ) ) {
if ( F_210 ( V_2 ) )
V_8 -> V_400 += V_393 ;
if ( V_392 != 2 )
F_211 ( V_2 ) ;
V_328 |= ( F_23 ( V_8 ) >= V_8 -> V_27 ) ;
F_168 ( V_2 , V_328 ) ;
return false ;
}
return ! V_8 -> V_10 && F_170 ( V_2 ) ;
}
bool F_211 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_401 , V_402 , V_403 ;
T_4 V_404 = F_212 ( V_8 -> V_367 >> 3 ) ;
if ( F_140 ( V_6 -> V_13 == V_14 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_8 -> V_405 )
return false ;
if ( V_6 -> V_13 != V_406 )
return false ;
if ( ( V_407 != 3 && V_407 != 4 ) ||
! V_8 -> V_10 || ! F_213 ( V_8 ) ||
V_6 -> V_322 != V_323 )
return false ;
if ( ( V_8 -> V_27 > F_23 ( V_8 ) ) &&
F_170 ( V_2 ) )
return false ;
V_401 = V_404 << 1 ? : V_408 ;
if ( V_8 -> V_10 == 1 )
V_401 = F_30 ( T_4 , V_401 ,
( V_404 + ( V_404 >> 1 ) + V_409 ) ) ;
V_401 = F_30 ( T_4 , V_401 , F_214 ( 10 ) ) ;
V_402 = V_32 + V_401 ;
V_403 = ( T_4 ) F_2 ( V_2 ) -> V_410 ;
if ( ( T_3 ) ( V_402 - V_403 ) > 0 ) {
T_3 V_24 = V_403 - V_32 ;
if ( V_24 > 0 )
V_401 = V_24 ;
}
F_215 ( V_2 , V_14 , V_401 ,
V_411 ) ;
return true ;
}
static bool F_216 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_52 ( F_217 ( V_2 , V_4 ) ) ) {
F_35 ( F_9 ( V_2 ) ,
V_412 ) ;
return true ;
}
return false ;
}
void F_218 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_413 ;
int V_21 = F_64 ( V_2 ) ;
V_4 = F_170 ( V_2 ) ;
if ( V_4 ) {
if ( F_182 ( V_8 , V_4 , V_21 ) ) {
V_413 = V_8 -> V_10 ;
F_63 ( V_2 , V_21 , V_414 , 2 , V_184 ) ;
if ( V_8 -> V_10 > V_413 )
goto V_415;
goto V_416;
}
V_4 = F_219 ( V_2 , V_4 ) ;
} else {
V_4 = F_178 ( V_2 ) ;
}
if ( V_8 -> V_417 )
goto V_416;
if ( F_140 ( ! V_4 ) )
goto V_416;
if ( F_216 ( V_2 , V_4 ) )
goto V_416;
V_413 = F_6 ( V_4 ) ;
if ( F_140 ( ! V_413 ) )
goto V_416;
if ( ( V_413 > 1 ) && ( V_4 -> V_82 > ( V_413 - 1 ) * V_21 ) ) {
if ( F_52 ( F_139 ( V_2 , V_4 , ( V_413 - 1 ) * V_21 , V_21 ,
V_184 ) ) )
goto V_416;
V_4 = F_220 ( V_2 , V_4 ) ;
}
if ( F_140 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_416;
if ( F_221 ( V_2 , V_4 , 1 ) )
goto V_416;
V_8 -> V_417 = V_8 -> V_11 ;
V_415:
F_35 ( F_9 ( V_2 ) , V_418 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_416:
F_7 ( V_2 ) ;
}
void F_222 ( struct V_1 * V_2 , unsigned int V_354 ,
int V_183 )
{
if ( F_52 ( V_2 -> V_175 == V_419 ) )
return;
if ( F_63 ( V_2 , V_354 , V_183 , 0 ,
F_223 ( V_2 , V_184 ) ) )
F_224 ( V_2 ) ;
}
void F_225 ( struct V_1 * V_2 , unsigned int V_266 )
{
struct V_3 * V_4 = F_170 ( V_2 ) ;
F_101 ( ! V_4 || V_4 -> V_82 < V_266 ) ;
F_63 ( V_2 , V_266 , V_355 , 1 , V_2 -> V_420 ) ;
}
T_4 F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_21 = V_6 -> V_37 . V_421 ;
int V_422 = F_226 ( V_2 ) ;
int V_423 = F_227 ( V_2 ) ;
int V_424 = F_31 ( int , V_8 -> V_47 , V_423 ) ;
int V_247 ;
if ( F_52 ( V_21 > V_424 ) ) {
V_21 = V_424 ;
if ( V_21 <= 0 )
return 0 ;
}
if ( V_422 < ( V_424 >> 1 ) ) {
V_6 -> V_37 . V_425 = 0 ;
if ( F_228 ( V_2 ) )
V_8 -> V_426 = F_20 ( V_8 -> V_426 ,
4U * V_8 -> V_22 ) ;
V_422 = F_229 ( V_422 , 1 << V_8 -> V_16 . V_18 ) ;
if ( V_422 < ( V_423 >> 4 ) || V_422 < V_21 )
return 0 ;
}
if ( V_422 > V_8 -> V_426 )
V_422 = V_8 -> V_426 ;
if ( V_8 -> V_16 . V_18 ) {
V_247 = V_422 ;
V_247 = F_36 ( V_247 , ( 1 << V_8 -> V_16 . V_18 ) ) ;
} else {
V_247 = V_8 -> V_46 ;
if ( V_247 <= V_422 - V_21 || V_247 > V_422 )
V_247 = F_29 ( V_422 , V_21 ) ;
else if ( V_21 == V_424 &&
V_422 > V_247 + ( V_424 >> 1 ) )
V_247 = V_422 ;
}
return V_247 ;
}
void F_230 ( struct V_3 * V_4 ,
const struct V_3 * V_427 )
{
if ( F_52 ( F_135 ( V_427 ) ) ) {
const struct V_281 * V_428 =
F_46 ( V_427 ) ;
struct V_281 * V_282 = F_46 ( V_4 ) ;
V_282 -> V_278 |= V_428 -> V_278 & V_279 ;
V_282 -> V_283 = V_428 -> V_283 ;
F_5 ( V_4 ) -> V_277 |=
F_5 ( V_427 ) -> V_277 ;
}
}
static bool F_231 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_427 = F_220 ( V_2 , V_4 ) ;
int V_429 , V_430 ;
V_429 = V_4 -> V_82 ;
V_430 = V_427 -> V_82 ;
F_101 ( F_6 ( V_4 ) != 1 || F_6 ( V_427 ) != 1 ) ;
if ( V_430 ) {
if ( V_430 <= F_232 ( V_4 ) )
F_196 ( V_427 , 0 , F_145 ( V_4 , V_430 ) ,
V_430 ) ;
else if ( ! F_233 ( V_4 , V_427 , V_430 ) )
return false ;
}
F_234 ( V_2 , V_427 , V_4 ) ;
F_199 ( V_427 , V_2 ) ;
if ( V_427 -> V_90 == V_91 )
V_4 -> V_90 = V_91 ;
if ( V_4 -> V_90 != V_91 )
V_4 -> V_92 = F_198 ( V_4 -> V_92 , V_427 -> V_92 , V_429 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_427 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_427 ) -> V_65 ;
F_5 ( V_4 ) -> V_93 |= F_5 ( V_427 ) -> V_93 & V_431 ;
F_5 ( V_4 ) -> V_286 = F_5 ( V_427 ) -> V_286 ;
F_235 ( V_8 ) ;
if ( V_427 == V_8 -> V_432 )
V_8 -> V_432 = V_4 ;
F_132 ( V_2 , V_427 , F_6 ( V_427 ) ) ;
F_230 ( V_4 , V_427 ) ;
F_200 ( V_2 , V_427 ) ;
return true ;
}
static bool F_236 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_104 ( V_4 ) )
return false ;
if ( V_4 == F_170 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_93 & V_272 )
return false ;
return true ;
}
static void F_237 ( struct V_1 * V_2 , struct V_3 * V_433 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_433 , * V_434 ;
bool V_435 = true ;
if ( ! V_436 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_94 )
return;
F_195 (skb, tmp, sk) {
if ( ! F_236 ( V_2 , V_4 ) )
break;
if ( ! F_238 ( V_433 ) )
break;
V_49 -= V_4 -> V_82 ;
if ( V_435 ) {
V_435 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( F_117 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
if ( ! F_231 ( V_2 , V_433 ) )
break;
}
}
int F_221 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_342 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_354 ;
int V_296 , V_82 , V_227 ;
if ( V_6 -> V_311 . V_317 )
V_6 -> V_311 . V_317 = 0 ;
if ( F_204 ( & V_2 -> V_213 ) >
F_31 ( T_4 , V_2 -> V_265 + ( V_2 -> V_265 >> 2 ) ,
V_2 -> V_437 ) )
return - V_438 ;
if ( F_216 ( V_2 , V_4 ) )
return - V_439 ;
if ( F_11 ( F_5 ( V_4 ) -> V_83 , V_8 -> V_96 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_96 ) )
F_239 () ;
if ( F_156 ( V_2 , V_4 , V_8 -> V_96 - F_5 ( V_4 ) -> V_83 ) )
return - V_293 ;
}
if ( F_2 ( V_2 ) -> V_205 -> V_440 ( V_2 ) )
return - V_441 ;
V_354 = F_64 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_83 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_83 != V_8 -> V_96 )
return - V_438 ;
V_82 = V_354 * V_342 ;
if ( V_4 -> V_82 > V_82 ) {
if ( F_139 ( V_2 , V_4 , V_82 , V_354 , V_184 ) )
return - V_293 ;
} else {
if ( F_142 ( V_4 , V_184 ) )
return - V_293 ;
V_296 = F_6 ( V_4 ) ;
F_127 ( V_4 , V_354 ) ;
V_296 -= F_6 ( V_4 ) ;
if ( V_296 )
F_132 ( V_2 , V_4 , V_296 ) ;
if ( V_4 -> V_82 < V_354 )
F_237 ( V_2 , V_4 , V_354 ) ;
}
if ( ( F_5 ( V_4 ) -> V_65 & V_442 ) == V_442 )
F_42 ( V_2 , V_4 ) ;
V_342 = F_6 ( V_4 ) ;
F_119 ( F_9 ( V_2 ) , V_443 , V_342 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_94 )
F_240 ( F_9 ( V_2 ) , V_444 ) ;
V_8 -> V_445 += V_342 ;
if ( F_52 ( ( V_446 && ( ( unsigned long ) V_4 -> V_185 & 3 ) ) ||
F_241 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_371 ;
F_102 ( & V_4 -> V_228 ) ;
V_371 = F_242 ( V_4 , V_345 , V_184 ) ;
V_227 = V_371 ? F_100 ( V_2 , V_371 , 0 , V_184 ) :
- V_231 ;
} else {
V_227 = F_100 ( V_2 , V_4 , 1 , V_184 ) ;
}
if ( F_54 ( ! V_227 ) ) {
F_5 ( V_4 ) -> V_93 |= V_431 ;
} else if ( V_227 != - V_439 ) {
F_35 ( F_9 ( V_2 ) , V_447 ) ;
}
return V_227 ;
}
int F_243 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_342 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_227 = F_221 ( V_2 , V_4 , V_342 ) ;
if ( V_227 == 0 ) {
#if V_448 > 0
if ( F_5 ( V_4 ) -> V_93 & V_273 ) {
F_244 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_93 |= V_449 ;
V_8 -> V_182 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_450 )
V_8 -> V_450 = F_57 ( V_4 ) ;
}
if ( V_8 -> V_451 < 0 )
V_8 -> V_451 = 0 ;
V_8 -> V_451 += F_6 ( V_4 ) ;
return V_227 ;
}
void F_62 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_452 = NULL ;
T_4 V_350 ;
int V_453 ;
if ( ! V_8 -> V_10 )
return;
if ( V_8 -> V_432 ) {
V_4 = V_8 -> V_432 ;
} else {
V_4 = F_190 ( V_2 ) ;
}
V_350 = F_176 ( V_2 , F_64 ( V_2 ) ) ;
F_245 (skb, sk) {
T_5 V_93 ;
int V_342 ;
if ( V_4 == F_170 ( V_2 ) )
break;
if ( ! V_452 )
V_8 -> V_432 = V_4 ;
V_342 = V_8 -> V_27 - F_23 ( V_8 ) ;
if ( V_342 <= 0 )
return;
V_93 = F_5 ( V_4 ) -> V_93 ;
V_342 = F_31 ( int , V_342 , V_350 ) ;
if ( V_8 -> V_182 >= V_8 -> V_181 ) {
break;
} else if ( ! ( V_93 & V_274 ) ) {
if ( ! V_452 && ! ( V_93 & ( V_273 | V_272 ) ) )
V_452 = V_4 ;
continue;
} else {
if ( V_6 -> V_322 != V_454 )
V_453 = V_455 ;
else
V_453 = V_456 ;
}
if ( V_93 & ( V_272 | V_273 ) )
continue;
if ( F_203 ( V_2 , V_4 , 1 ) )
return;
if ( F_243 ( V_2 , V_4 , V_342 ) )
return;
F_8 ( F_9 ( V_2 ) , V_453 , F_6 ( V_4 ) ) ;
if ( F_210 ( V_2 ) )
V_8 -> V_400 += F_6 ( V_4 ) ;
if ( V_4 == F_190 ( V_2 ) &&
V_6 -> V_13 != V_457 )
F_215 ( V_2 , V_406 ,
F_2 ( V_2 ) -> V_30 ,
V_411 ) ;
}
}
void F_246 ( struct V_1 * V_2 , int V_171 )
{
int V_458 ;
if ( V_171 <= V_2 -> V_459 )
return;
V_458 = F_247 ( V_171 ) ;
V_2 -> V_459 += V_458 * V_460 ;
F_248 ( V_2 , V_458 ) ;
if ( V_461 && V_2 -> V_462 )
F_249 ( V_2 -> V_462 , V_458 ) ;
}
void F_250 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_463 = F_178 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_463 && ( F_170 ( V_2 ) || F_228 ( V_2 ) ) ) {
V_464:
F_5 ( V_463 ) -> V_65 |= V_95 ;
F_5 ( V_463 ) -> V_12 ++ ;
V_8 -> V_264 ++ ;
if ( ! F_170 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_251 ( V_345 , V_2 -> V_420 ) ;
if ( F_52 ( ! V_4 ) ) {
if ( V_463 )
goto V_464;
return;
}
F_252 ( V_4 , V_345 ) ;
F_246 ( V_2 , V_4 -> V_212 ) ;
F_48 ( V_4 , V_8 -> V_264 ,
V_251 | V_95 ) ;
F_123 ( V_2 , V_4 ) ;
}
F_222 ( V_2 , F_64 ( V_2 ) , V_414 ) ;
}
void F_253 ( struct V_1 * V_2 , T_10 V_465 )
{
struct V_3 * V_4 ;
F_254 ( F_9 ( V_2 ) , V_466 ) ;
V_4 = F_255 ( V_345 , V_465 ) ;
if ( ! V_4 ) {
F_35 ( F_9 ( V_2 ) , V_467 ) ;
return;
}
F_252 ( V_4 , V_345 ) ;
F_48 ( V_4 , F_10 ( V_2 ) ,
V_251 | V_468 ) ;
F_102 ( & V_4 -> V_228 ) ;
if ( F_100 ( V_2 , V_4 , 0 , V_465 ) )
F_35 ( F_9 ( V_2 ) , V_467 ) ;
}
int F_256 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_190 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_65 & V_94 ) ) {
F_257 ( L_2 , V_469 ) ;
return - V_470 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_251 ) ) {
if ( F_104 ( V_4 ) ) {
struct V_3 * V_371 = F_258 ( V_4 , V_184 ) ;
if ( ! V_371 )
return - V_293 ;
F_199 ( V_4 , V_2 ) ;
F_124 ( V_371 ) ;
F_259 ( V_2 , V_371 ) ;
F_200 ( V_2 , V_4 ) ;
V_2 -> V_265 += V_371 -> V_212 ;
F_126 ( V_2 , V_371 -> V_212 ) ;
V_4 = V_371 ;
}
F_5 ( V_4 ) -> V_65 |= V_251 ;
F_37 ( V_2 , V_4 ) ;
}
return F_100 ( V_2 , V_4 , 1 , V_184 ) ;
}
struct V_3 * F_260 ( const struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_75 * V_76 ,
struct V_133 * V_134 ,
enum V_471 V_472 )
{
struct V_166 * V_167 = F_44 ( V_76 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_143 * V_144 = NULL ;
struct V_99 V_100 ;
struct V_3 * V_4 ;
int V_226 ;
struct V_77 * V_78 ;
int V_21 ;
V_4 = F_255 ( V_345 , V_184 ) ;
if ( F_52 ( ! V_4 ) ) {
F_261 ( V_20 ) ;
return NULL ;
}
F_252 ( V_4 , V_345 ) ;
switch ( V_472 ) {
case V_473 :
F_262 ( V_4 , F_263 ( V_76 ) ) ;
break;
case V_474 :
break;
case V_475 :
F_262 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_264 ( V_4 , V_20 ) ;
V_21 = F_265 ( V_8 , F_15 ( V_20 ) ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
#ifdef F_266
if ( F_52 ( V_76 -> V_476 ) )
V_4 -> V_228 . V_477 = F_267 ( V_76 ) ;
else
#endif
F_102 ( & V_4 -> V_228 ) ;
#ifdef F_56
F_268 () ;
V_144 = F_59 ( V_76 ) -> V_150 -> V_478 ( V_2 , F_263 ( V_76 ) ) ;
#endif
F_269 ( V_4 , F_59 ( V_76 ) -> V_479 , V_480 ) ;
V_226 = F_58 ( V_76 , V_21 , V_4 , & V_100 , V_144 , V_134 ) +
sizeof( * V_78 ) ;
F_109 ( V_4 , V_226 ) ;
F_110 ( V_4 ) ;
V_78 = (struct V_77 * ) V_4 -> V_185 ;
memset ( V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 -> V_481 = 1 ;
V_78 -> V_482 = 1 ;
F_43 ( V_76 , V_78 ) ;
V_78 -> V_237 = F_116 ( V_167 -> V_483 ) ;
V_78 -> V_239 = V_167 -> V_484 ;
F_48 ( V_4 , F_59 ( V_76 ) -> V_485 ,
V_94 | V_251 ) ;
V_78 -> V_83 = F_53 ( F_5 ( V_4 ) -> V_83 ) ;
V_78 -> V_241 = F_53 ( F_59 ( V_76 ) -> V_61 ) ;
V_78 -> V_247 = F_116 ( F_20 ( V_76 -> V_486 , 65535U ) ) ;
F_51 ( ( T_8 * ) ( V_78 + 1 ) , NULL , & V_100 ) ;
V_78 -> V_487 = ( V_226 >> 2 ) ;
F_270 ( F_9 ( V_2 ) , V_253 ) ;
#ifdef F_56
if ( V_144 )
F_59 ( V_76 ) -> V_150 -> V_249 ( V_100 . V_106 ,
V_144 , F_263 ( V_76 ) , V_4 ) ;
F_271 () ;
#endif
V_4 -> V_257 = 0 ;
return V_4 ;
}
static void F_272 ( struct V_1 * V_2 , const struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_329 * V_488 ;
T_4 V_489 = F_273 ( V_20 , V_490 ) ;
if ( V_489 == V_491 )
return;
F_268 () ;
V_488 = F_274 ( V_489 ) ;
if ( F_54 ( V_488 && F_275 ( V_488 -> V_492 ) ) ) {
F_276 ( V_6 -> V_331 -> V_492 ) ;
V_6 -> V_493 = F_277 ( V_20 ) ;
V_6 -> V_331 = V_488 ;
}
F_271 () ;
}
static void F_278 ( struct V_1 * V_2 )
{
const struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_18 ;
V_8 -> V_81 = sizeof( struct V_77 ) +
( V_154 ? V_157 : 0 ) ;
#ifdef F_56
if ( V_8 -> V_150 -> V_151 ( V_2 , V_2 ) )
V_8 -> V_81 += V_152 ;
#endif
if ( V_8 -> V_16 . V_494 )
V_8 -> V_16 . V_307 = V_8 -> V_16 . V_494 ;
V_8 -> V_495 = 0 ;
F_163 ( V_2 ) ;
F_164 ( V_2 , F_166 ( V_20 ) ) ;
F_272 ( V_2 , V_20 ) ;
if ( ! V_8 -> V_47 )
V_8 -> V_47 = F_273 ( V_20 , V_496 ) ;
V_8 -> V_22 = F_265 ( V_8 , F_15 ( V_20 ) ) ;
F_279 ( V_2 ) ;
if ( V_2 -> V_497 & V_498 &&
( V_8 -> V_47 > F_227 ( V_2 ) || V_8 -> V_47 == 0 ) )
V_8 -> V_47 = F_227 ( V_2 ) ;
F_28 ( F_227 ( V_2 ) ,
V_8 -> V_22 - ( V_8 -> V_16 . V_499 ? V_8 -> V_81 - sizeof( struct V_77 ) : 0 ) ,
& V_8 -> V_46 ,
& V_8 -> V_47 ,
V_158 ,
& V_18 ,
F_273 ( V_20 , V_500 ) ) ;
V_8 -> V_16 . V_18 = V_18 ;
V_8 -> V_426 = V_8 -> V_46 ;
V_2 -> V_501 = 0 ;
F_280 ( V_2 , V_502 ) ;
V_8 -> V_366 = 0 ;
F_281 ( V_8 , 0 ) ;
V_8 -> V_96 = V_8 -> V_264 ;
V_8 -> V_337 = V_8 -> V_264 ;
V_8 -> V_97 = V_8 -> V_264 ;
V_8 -> V_11 = V_8 -> V_264 ;
if ( F_54 ( ! V_8 -> V_396 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_503 = V_32 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_504 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_408 ;
F_2 ( V_2 ) -> V_505 = 0 ;
F_282 ( V_8 ) ;
}
static void F_283 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_223 * V_224 = F_5 ( V_4 ) ;
V_224 -> V_12 += V_4 -> V_82 ;
F_124 ( V_4 ) ;
F_284 ( V_2 , V_4 ) ;
V_2 -> V_265 += V_4 -> V_212 ;
F_126 ( V_2 , V_4 -> V_212 ) ;
V_8 -> V_264 = V_224 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_285 ( struct V_1 * V_2 , struct V_3 * V_481 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_147 * V_506 = V_8 -> V_149 ;
int V_49 , V_227 = 0 ;
struct V_3 * V_507 ;
V_8 -> V_16 . V_307 = V_8 -> V_22 ;
if ( ! F_286 ( V_2 , & V_8 -> V_16 . V_307 , & V_506 -> V_162 ) )
goto V_508;
V_8 -> V_16 . V_307 = F_265 ( V_8 , V_8 -> V_16 . V_307 ) ;
V_49 = F_159 ( V_2 , F_2 ( V_2 ) -> V_319 ) -
V_146 ;
V_49 = F_31 ( V_509 , V_49 , V_506 -> V_171 ) ;
V_49 = F_31 ( V_509 , V_49 , F_287 ( V_345 ) ) ;
V_507 = F_143 ( V_2 , V_49 , V_2 -> V_420 , false ) ;
if ( ! V_507 )
goto V_508;
V_507 -> V_90 = V_91 ;
memcpy ( V_507 -> V_258 , V_481 -> V_258 , sizeof( V_481 -> V_258 ) ) ;
if ( V_49 ) {
int V_510 = F_288 ( F_145 ( V_507 , V_49 ) , V_49 ,
& V_506 -> V_185 -> V_511 ) ;
if ( F_52 ( ! V_510 ) ) {
F_289 ( V_507 ) ;
goto V_508;
}
if ( V_510 != V_49 ) {
F_146 ( V_507 , V_510 ) ;
V_49 = V_510 ;
}
}
if ( V_49 == V_506 -> V_171 )
V_506 -> V_185 = NULL ;
V_506 -> V_510 = V_49 ;
F_283 ( V_2 , V_507 ) ;
if ( V_507 -> V_82 )
F_171 ( V_2 , V_391 ) ;
V_227 = F_100 ( V_2 , V_507 , 1 , V_2 -> V_420 ) ;
V_481 -> V_228 = V_507 -> V_228 ;
F_5 ( V_507 ) -> V_83 ++ ;
F_5 ( V_507 ) -> V_65 = V_251 | V_294 ;
if ( ! V_227 ) {
V_8 -> V_507 = ( V_506 -> V_510 > 0 ) ;
F_35 ( F_9 ( V_2 ) , V_15 ) ;
goto V_512;
}
V_508:
if ( V_506 -> V_162 . V_82 > 0 )
V_506 -> V_162 . V_82 = 0 ;
V_227 = F_100 ( V_2 , V_481 , 1 , V_2 -> V_420 ) ;
if ( V_227 )
V_8 -> V_164 = 0 ;
V_512:
V_506 -> V_162 . V_82 = - 1 ;
return V_227 ;
}
int F_290 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_288 ;
int V_227 ;
F_278 ( V_2 ) ;
if ( F_52 ( V_8 -> V_396 ) ) {
F_291 ( V_2 , NULL ) ;
return 0 ;
}
V_288 = F_143 ( V_2 , 0 , V_2 -> V_420 , true ) ;
if ( F_52 ( ! V_288 ) )
return - V_231 ;
F_48 ( V_288 , V_8 -> V_264 ++ , V_94 ) ;
V_8 -> V_450 = V_32 ;
F_283 ( V_2 , V_288 ) ;
F_40 ( V_2 , V_288 ) ;
V_227 = V_8 -> V_149 ? F_285 ( V_2 , V_288 ) :
F_100 ( V_2 , V_288 , 1 , V_2 -> V_420 ) ;
if ( V_227 == - V_513 )
return V_227 ;
V_8 -> V_11 = V_8 -> V_264 ;
V_8 -> V_514 = V_8 -> V_264 ;
F_254 ( F_9 ( V_2 ) , V_515 ) ;
F_215 ( V_2 , V_406 ,
F_2 ( V_2 ) -> V_30 , V_411 ) ;
return 0 ;
}
void F_292 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_39 = V_6 -> V_37 . V_39 ;
unsigned long V_401 ;
F_18 ( V_2 , V_516 ) ;
if ( V_39 > V_517 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_518 = V_370 / 2 ;
if ( V_6 -> V_37 . V_40 ||
( V_6 -> V_37 . V_519 & V_520 ) )
V_518 = V_409 ;
if ( V_8 -> V_367 ) {
int V_404 = F_30 ( int , F_212 ( V_8 -> V_367 >> 3 ) ,
V_517 ) ;
if ( V_404 < V_518 )
V_518 = V_404 ;
}
V_39 = F_20 ( V_39 , V_518 ) ;
}
V_401 = V_521 + V_39 ;
if ( V_6 -> V_37 . V_519 & V_522 ) {
if ( V_6 -> V_37 . V_523 ||
F_293 ( V_6 -> V_37 . V_401 , V_521 + ( V_39 >> 2 ) ) ) {
F_294 ( V_2 ) ;
return;
}
if ( ! F_295 ( V_401 , V_6 -> V_37 . V_401 ) )
V_401 = V_6 -> V_37 . V_401 ;
}
V_6 -> V_37 . V_519 |= V_524 | V_522 ;
V_6 -> V_37 . V_401 = V_401 ;
F_296 ( V_2 , & V_6 -> V_525 , V_401 ) ;
}
void F_294 ( struct V_1 * V_2 )
{
struct V_3 * V_288 ;
if ( V_2 -> V_175 == V_419 )
return;
F_18 ( V_2 , V_526 ) ;
V_288 = F_255 ( V_345 ,
F_223 ( V_2 , V_184 | V_527 ) ) ;
if ( F_52 ( ! V_288 ) ) {
F_297 ( V_2 ) ;
F_2 ( V_2 ) -> V_37 . V_39 = V_528 ;
F_215 ( V_2 , V_42 ,
V_409 , V_411 ) ;
return;
}
F_252 ( V_288 , V_345 ) ;
F_48 ( V_288 , F_10 ( V_2 ) , V_251 ) ;
F_298 ( V_288 ) ;
F_102 ( & V_288 -> V_228 ) ;
F_100 ( V_2 , V_288 , 0 , ( V_529 T_10 ) 0 ) ;
}
static int F_299 ( struct V_1 * V_2 , int V_530 , int V_531 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_255 ( V_345 ,
F_223 ( V_2 , V_184 | V_527 ) ) ;
if ( ! V_4 )
return - 1 ;
F_252 ( V_4 , V_345 ) ;
F_48 ( V_4 , V_8 -> V_96 - ! V_530 , V_251 ) ;
F_102 ( & V_4 -> V_228 ) ;
F_35 ( F_9 ( V_2 ) , V_531 ) ;
return F_100 ( V_2 , V_4 , 0 , ( V_529 T_10 ) 0 ) ;
}
void F_300 ( struct V_1 * V_2 )
{
if ( V_2 -> V_175 == V_532 ) {
F_3 ( V_2 ) -> V_533 = F_3 ( V_2 ) -> V_61 - 1 ;
F_299 ( V_2 , 0 , V_534 ) ;
}
}
int F_301 ( struct V_1 * V_2 , int V_531 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_175 == V_419 )
return - 1 ;
V_4 = F_170 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_83 , F_12 ( V_8 ) ) ) {
int V_227 ;
unsigned int V_21 = F_64 ( V_2 ) ;
unsigned int V_535 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_83 ;
if ( F_11 ( V_8 -> V_514 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_514 = F_5 ( V_4 ) -> V_12 ;
if ( V_535 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_83 ||
V_4 -> V_82 > V_21 ) {
V_535 = F_20 ( V_535 , V_21 ) ;
F_5 ( V_4 ) -> V_65 |= V_294 ;
if ( F_139 ( V_2 , V_4 , V_535 , V_21 , V_184 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_127 ( V_4 , V_21 ) ;
F_5 ( V_4 ) -> V_65 |= V_294 ;
V_227 = F_100 ( V_2 , V_4 , 1 , V_184 ) ;
if ( ! V_227 )
F_1 ( V_2 , V_4 ) ;
return V_227 ;
} else {
if ( F_302 ( V_8 -> V_97 , V_8 -> V_96 + 1 , V_8 -> V_96 + 0xFFFF ) )
F_299 ( V_2 , 1 , V_531 ) ;
return F_299 ( V_2 , 0 , V_531 ) ;
}
}
void F_303 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_310 * V_310 = F_9 ( V_2 ) ;
unsigned long V_536 ;
int V_227 ;
V_227 = F_301 ( V_2 , V_534 ) ;
if ( V_8 -> V_10 || ! F_170 ( V_2 ) ) {
V_6 -> V_537 = 0 ;
V_6 -> V_538 = 0 ;
return;
}
if ( V_227 <= 0 ) {
if ( V_6 -> V_538 < V_310 -> V_71 . V_539 )
V_6 -> V_538 ++ ;
V_6 -> V_537 ++ ;
V_536 = V_411 ;
} else {
if ( ! V_6 -> V_537 )
V_6 -> V_537 = 1 ;
V_536 = V_540 ;
}
F_215 ( V_2 , V_541 ,
F_304 ( V_2 , V_536 ) ,
V_411 ) ;
}
int F_305 ( const struct V_1 * V_2 , struct V_75 * V_76 )
{
const struct V_542 * V_543 = F_59 ( V_76 ) -> V_150 ;
struct V_544 V_263 ;
int V_545 ;
F_59 ( V_76 ) -> V_479 = F_306 () ;
V_545 = V_543 -> V_546 ( V_2 , NULL , & V_263 , V_76 , NULL , V_473 ) ;
if ( ! V_545 ) {
F_270 ( F_9 ( V_2 ) , V_443 ) ;
F_240 ( F_9 ( V_2 ) , V_444 ) ;
if ( F_52 ( F_307 ( V_2 ) ) )
F_3 ( V_2 ) -> V_445 ++ ;
}
return V_545 ;
}
