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
V_99 -> V_114 = F_56 ( V_4 ) + F_58 ( V_75 ) -> V_169 ;
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
static unsigned int F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_98 * V_99 ,
struct V_142 * * V_143 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_170 = 0 ;
unsigned int V_171 ;
V_99 -> V_100 = 0 ;
#ifdef F_55
* V_143 = V_8 -> V_149 -> V_150 ( V_2 , V_2 ) ;
if ( F_51 ( * V_143 ) ) {
V_99 -> V_100 |= V_101 ;
V_170 += V_151 ;
}
#else
* V_143 = NULL ;
#endif
if ( F_53 ( V_8 -> V_58 . V_167 ) ) {
V_99 -> V_100 |= V_108 ;
V_99 -> V_114 = V_4 ? F_56 ( V_4 ) + V_8 -> V_154 : 0 ;
V_99 -> V_115 = V_8 -> V_58 . V_155 ;
V_170 += V_156 ;
}
V_171 = V_8 -> V_58 . V_172 + V_8 -> V_58 . V_123 ;
if ( F_51 ( V_171 ) ) {
const unsigned int V_144 = V_145 - V_170 ;
V_99 -> V_120 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_170 += V_173 +
V_99 -> V_120 * V_129 ;
}
return V_170 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_174 ) &
( V_175 | V_176 | V_177 |
V_178 | V_179 ) ) {
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_180 > V_8 -> V_181 &&
V_8 -> V_25 > F_23 ( V_8 ) )
F_61 ( V_2 ) ;
F_62 ( V_2 , F_63 ( V_2 ) , V_8 -> V_182 ,
0 , V_183 ) ;
}
}
static void F_64 ( unsigned long V_184 )
{
struct V_185 * V_186 = (struct V_185 * ) V_184 ;
F_65 ( V_187 ) ;
unsigned long V_88 ;
struct V_188 * V_189 , * V_190 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_66 ( V_88 ) ;
F_67 ( & V_186 -> V_191 , & V_187 ) ;
F_68 ( V_88 ) ;
F_69 (q, n, &list) {
V_8 = F_70 ( V_189 , struct V_7 , V_192 ) ;
F_71 ( & V_8 -> V_192 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_72 () ;
F_73 ( V_193 , & V_2 -> V_194 ) ;
if ( ! V_2 -> V_195 . V_196 &&
F_74 ( V_197 , & V_2 -> V_194 ) ) {
F_75 ( V_2 ) ;
if ( ! F_76 ( V_2 ) ) {
F_73 ( V_197 , & V_2 -> V_194 ) ;
F_60 ( V_2 ) ;
}
F_77 ( V_2 ) ;
}
F_78 ( V_2 ) ;
}
}
void F_79 ( struct V_1 * V_2 )
{
unsigned long V_88 , V_198 ;
do {
V_88 = V_2 -> V_194 ;
if ( ! ( V_88 & V_199 ) )
return;
V_198 = V_88 & ~ V_199 ;
} while ( F_80 ( & V_2 -> V_194 , V_88 , V_198 ) != V_88 );
if ( V_88 & V_200 )
F_60 ( V_2 ) ;
F_81 ( V_2 ) ;
if ( V_88 & V_201 ) {
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
}
if ( V_88 & V_202 ) {
F_84 ( V_2 ) ;
F_83 ( V_2 ) ;
}
if ( V_88 & V_203 ) {
F_2 ( V_2 ) -> V_204 -> V_205 ( V_2 ) ;
F_83 ( V_2 ) ;
}
}
void T_9 F_85 ( void )
{
int V_206 ;
F_86 (i) {
struct V_185 * V_186 = & F_87 ( V_185 , V_206 ) ;
F_88 ( & V_186 -> V_191 ) ;
F_89 ( & V_186 -> V_207 ,
F_64 ,
( unsigned long ) V_186 ) ;
}
}
void F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_88 , V_208 , V_209 ;
int V_210 ;
V_210 = F_91 ( V_4 -> V_211 - 1 , & V_2 -> V_212 ) ;
if ( V_210 >= F_92 ( 1 ) && F_93 () == V_213 )
goto V_214;
for ( V_209 = F_94 ( V_2 -> V_194 ) ; ; V_209 = V_208 ) {
struct V_185 * V_186 ;
bool V_215 ;
if ( ! ( V_209 & V_216 ) || ( V_209 & V_217 ) )
goto V_214;
V_208 = ( V_209 & ~ V_216 ) | V_217 | V_200 ;
V_208 = F_80 ( & V_2 -> V_194 , V_209 , V_208 ) ;
if ( V_208 != V_209 )
continue;
F_66 ( V_88 ) ;
V_186 = F_95 ( & V_185 ) ;
V_215 = F_96 ( & V_186 -> V_191 ) ;
F_97 ( & V_8 -> V_192 , & V_186 -> V_191 ) ;
if ( V_215 )
F_98 ( & V_186 -> V_207 ) ;
F_68 ( V_88 ) ;
return;
}
V_214:
F_78 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_218 ,
T_10 V_219 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_220 * V_221 ;
struct V_7 * V_8 ;
struct V_222 * V_223 ;
struct V_98 V_99 ;
unsigned int V_224 , V_225 ;
struct V_142 * V_143 ;
struct V_76 * V_77 ;
int V_226 ;
F_100 ( ! V_4 || ! F_6 ( V_4 ) ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_218 ) {
F_101 ( & V_4 -> V_227 ) ;
F_5 ( V_4 ) -> V_228 . V_229 = F_5 ( V_4 ) -> V_12
- V_8 -> V_95 ;
F_102 ( V_2 , V_4 ) ;
if ( F_51 ( F_103 ( V_4 ) ) )
V_4 = F_104 ( V_4 , V_219 ) ;
else
V_4 = F_105 ( V_4 , V_219 ) ;
if ( F_51 ( ! V_4 ) )
return - V_230 ;
}
V_221 = F_106 ( V_2 ) ;
V_223 = F_5 ( V_4 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( F_51 ( V_223 -> V_64 & V_93 ) )
V_224 = F_54 ( V_2 , V_4 , & V_99 , & V_143 ) ;
else
V_224 = F_59 ( V_2 , V_4 , & V_99 ,
& V_143 ) ;
V_225 = V_224 + sizeof( struct V_76 ) ;
V_4 -> V_231 = F_107 ( V_2 ) < F_92 ( 1 ) ;
F_108 ( V_4 , V_225 ) ;
F_109 ( V_4 ) ;
F_110 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_232 = F_111 ( V_4 ) ? V_233 : F_90 ;
F_112 ( V_4 , V_2 ) ;
F_113 ( V_4 -> V_211 , & V_2 -> V_212 ) ;
V_77 = (struct V_76 * ) V_4 -> V_184 ;
V_77 -> V_234 = V_221 -> V_235 ;
V_77 -> V_236 = V_221 -> V_237 ;
V_77 -> V_82 = F_52 ( V_223 -> V_82 ) ;
V_77 -> V_238 = F_52 ( V_8 -> V_60 ) ;
* ( ( ( V_239 * ) V_77 ) + 6 ) = F_114 ( ( ( V_225 >> 2 ) << 12 ) |
V_223 -> V_64 ) ;
V_77 -> V_240 = 0 ;
V_77 -> V_241 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_223 -> V_82 , V_8 -> V_96 ) ) ) {
if ( F_11 ( V_8 -> V_96 , V_223 -> V_82 + 0x10000 ) ) {
V_77 -> V_241 = F_114 ( V_8 -> V_96 - V_223 -> V_82 ) ;
V_77 -> V_242 = 1 ;
} else if ( F_115 ( V_223 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_241 = F_114 ( 0xFFFF ) ;
V_77 -> V_242 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_99 ) ;
F_45 ( V_4 ) -> V_85 = V_2 -> V_243 ;
if ( F_53 ( ! ( V_223 -> V_64 & V_93 ) ) ) {
V_77 -> V_244 = F_114 ( F_31 ( V_2 ) ) ;
F_44 ( V_2 , V_4 , V_77 , V_225 ) ;
} else {
V_77 -> V_244 = F_114 ( F_20 ( V_8 -> V_44 , 65535U ) ) ;
}
#ifdef F_55
if ( V_143 ) {
F_116 ( V_2 , V_245 ) ;
V_8 -> V_149 -> V_246 ( V_99 . V_105 ,
V_143 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_204 -> V_247 ( V_2 , V_4 ) ;
if ( F_53 ( V_223 -> V_64 & V_248 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_225 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_249 += F_6 ( V_4 ) ;
}
if ( F_115 ( V_223 -> V_12 , V_8 -> V_11 ) || V_223 -> V_82 == V_223 -> V_12 )
F_117 ( F_9 ( V_2 ) , V_250 ,
F_6 ( V_4 ) ) ;
V_8 -> V_251 += F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_252 = F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_253 = F_118 ( V_4 ) ;
V_4 -> V_254 = 0 ;
memset ( V_4 -> V_255 , 0 , F_21 ( sizeof( struct V_256 ) ,
sizeof( struct V_257 ) ) ) ;
V_226 = V_6 -> V_204 -> V_258 ( V_2 , V_4 , & V_221 -> V_259 . V_260 ) ;
if ( F_53 ( V_226 <= 0 ) )
return V_226 ;
F_119 ( V_2 ) ;
return F_120 ( V_226 ) ;
}
static void F_121 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_261 = F_5 ( V_4 ) -> V_12 ;
F_122 ( V_4 ) ;
F_123 ( V_2 , V_4 ) ;
V_2 -> V_262 += V_4 -> V_211 ;
F_124 ( V_2 , V_4 -> V_211 ) ;
}
static void F_125 ( struct V_3 * V_4 , unsigned int V_263 )
{
if ( V_4 -> V_81 <= V_263 || V_4 -> V_89 == V_264 ) {
F_48 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_265 = 0 ;
} else {
F_48 ( V_4 , F_126 ( V_4 -> V_81 , V_263 ) ) ;
F_5 ( V_4 ) -> V_265 = V_263 ;
}
}
static void F_127 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_266 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_267 || F_128 ( V_8 ) )
return;
if ( F_115 ( F_129 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_268 -= V_266 ;
}
static void F_130 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_266 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_266 ;
if ( F_5 ( V_4 ) -> V_92 & V_269 )
V_8 -> V_267 -= V_266 ;
if ( F_5 ( V_4 ) -> V_92 & V_270 )
V_8 -> V_181 -= V_266 ;
if ( F_5 ( V_4 ) -> V_92 & V_271 )
V_8 -> V_180 -= V_266 ;
if ( F_128 ( V_8 ) && V_266 > 0 )
V_8 -> V_267 -= F_30 ( T_4 , V_8 -> V_267 , V_266 ) ;
F_127 ( V_2 , V_4 , V_266 ) ;
if ( V_8 -> V_272 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_272 ) -> V_82 ) &&
( F_131 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_269 ) ) )
V_8 -> V_273 -= V_266 ;
F_132 ( V_8 ) ;
}
static bool F_133 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_274 ||
( F_45 ( V_4 ) -> V_275 & V_276 ) ;
}
static void F_134 ( struct V_3 * V_4 , struct V_3 * V_277 )
{
struct V_278 * V_279 = F_45 ( V_4 ) ;
if ( F_51 ( F_133 ( V_4 ) ) &&
! F_11 ( V_279 -> V_280 , F_5 ( V_277 ) -> V_82 ) ) {
struct V_278 * V_281 = F_45 ( V_277 ) ;
T_7 V_282 = V_279 -> V_275 & V_276 ;
V_279 -> V_275 &= ~ V_282 ;
V_281 -> V_275 |= V_282 ;
F_135 ( V_279 -> V_280 , V_281 -> V_280 ) ;
F_5 ( V_277 ) -> V_274 = F_5 ( V_4 ) -> V_274 ;
F_5 ( V_4 ) -> V_274 = 0 ;
}
}
static void F_136 ( struct V_3 * V_4 , struct V_3 * V_277 )
{
F_5 ( V_277 ) -> V_283 = F_5 ( V_4 ) -> V_283 ;
F_5 ( V_4 ) -> V_283 = 0 ;
}
int F_137 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_263 , T_10 V_284 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_285 ;
int V_286 , V_287 ;
int V_288 ;
T_7 V_88 ;
if ( F_138 ( V_81 > V_4 -> V_81 ) )
return - V_289 ;
V_286 = F_139 ( V_4 ) - V_81 ;
if ( V_286 < 0 )
V_286 = 0 ;
if ( F_140 ( V_4 , V_284 ) )
return - V_290 ;
V_285 = F_141 ( V_2 , V_286 , V_284 , true ) ;
if ( ! V_285 )
return - V_290 ;
V_2 -> V_262 += V_285 -> V_211 ;
F_124 ( V_2 , V_285 -> V_211 ) ;
V_288 = V_4 -> V_81 - V_81 - V_286 ;
V_285 -> V_211 += V_288 ;
V_4 -> V_211 -= V_288 ;
F_5 ( V_285 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_285 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_285 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_291 ) ;
F_5 ( V_285 ) -> V_64 = V_88 ;
F_5 ( V_285 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
F_136 ( V_4 , V_285 ) ;
if ( ! F_45 ( V_4 ) -> V_292 && V_4 -> V_89 != V_90 ) {
V_285 -> V_91 = F_142 ( V_4 -> V_184 + V_81 ,
F_143 ( V_285 , V_286 ) ,
V_286 , 0 ) ;
F_144 ( V_4 , V_81 ) ;
V_4 -> V_91 = F_145 ( V_4 -> V_91 , V_285 -> V_91 , V_81 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_146 ( V_4 , V_285 , V_81 ) ;
}
V_285 -> V_89 = V_4 -> V_89 ;
V_285 -> V_254 = V_4 -> V_254 ;
F_134 ( V_4 , V_285 ) ;
V_287 = F_6 ( V_4 ) ;
F_125 ( V_4 , V_263 ) ;
F_125 ( V_285 , V_263 ) ;
F_5 ( V_285 ) -> V_228 = F_5 ( V_4 ) -> V_228 ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_285 ) -> V_12 ) ) {
int V_293 = V_287 - F_6 ( V_4 ) -
F_6 ( V_285 ) ;
if ( V_293 )
F_130 ( V_2 , V_4 , V_293 ) ;
}
F_122 ( V_285 ) ;
F_147 ( V_4 , V_285 , V_2 ) ;
return 0 ;
}
static void F_148 ( struct V_3 * V_4 , int V_81 )
{
struct V_278 * V_279 ;
int V_206 , V_294 , V_295 ;
V_295 = F_30 ( int , V_81 , F_139 ( V_4 ) ) ;
if ( V_295 ) {
F_149 ( V_4 , V_295 ) ;
V_81 -= V_295 ;
if ( ! V_81 )
return;
}
V_295 = V_81 ;
V_294 = 0 ;
V_279 = F_45 ( V_4 ) ;
for ( V_206 = 0 ; V_206 < V_279 -> V_292 ; V_206 ++ ) {
int V_170 = F_150 ( & V_279 -> V_296 [ V_206 ] ) ;
if ( V_170 <= V_295 ) {
F_151 ( V_4 , V_206 ) ;
V_295 -= V_170 ;
} else {
V_279 -> V_296 [ V_294 ] = V_279 -> V_296 [ V_206 ] ;
if ( V_295 ) {
V_279 -> V_296 [ V_294 ] . V_297 += V_295 ;
F_152 ( & V_279 -> V_296 [ V_294 ] , V_295 ) ;
V_295 = 0 ;
}
V_294 ++ ;
}
}
V_279 -> V_292 = V_294 ;
F_153 ( V_4 ) ;
V_4 -> V_298 -= V_81 ;
V_4 -> V_81 = V_4 -> V_298 ;
}
int F_154 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_140 ( V_4 , V_183 ) )
return - V_290 ;
F_148 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_211 -= V_81 ;
V_2 -> V_262 -= V_81 ;
F_155 ( V_2 , V_81 ) ;
F_156 ( V_2 , V_299 ) ;
if ( F_6 ( V_4 ) > 1 )
F_125 ( V_4 , F_118 ( V_4 ) ) ;
return 0 ;
}
static inline int F_157 ( struct V_1 * V_2 , int V_300 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_263 ;
V_263 = V_300 - V_6 -> V_204 -> V_301 - sizeof( struct V_76 ) ;
if ( V_6 -> V_204 -> V_302 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_158 ( V_18 ) )
V_263 -= V_6 -> V_204 -> V_302 ;
}
if ( V_263 > V_8 -> V_58 . V_303 )
V_263 = V_8 -> V_58 . V_303 ;
V_263 -= V_6 -> V_304 ;
if ( V_263 < 48 )
V_263 = 48 ;
return V_263 ;
}
int F_159 ( struct V_1 * V_2 , int V_300 )
{
return F_157 ( V_2 , V_300 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_160 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_305 ;
V_305 = V_19 +
V_8 -> V_80 +
V_6 -> V_304 +
V_6 -> V_204 -> V_301 ;
if ( V_6 -> V_204 -> V_302 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_158 ( V_18 ) )
V_305 += V_6 -> V_204 -> V_302 ;
}
return V_305 ;
}
void F_161 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_306 * V_306 = F_9 ( V_2 ) ;
V_6 -> V_307 . V_308 = V_306 -> V_70 . V_309 > 1 ;
V_6 -> V_307 . V_310 = V_8 -> V_58 . V_303 + sizeof( struct V_76 ) +
V_6 -> V_204 -> V_301 ;
V_6 -> V_307 . V_311 = F_160 ( V_2 , V_306 -> V_70 . V_312 ) ;
V_6 -> V_307 . V_313 = 0 ;
if ( V_6 -> V_307 . V_308 )
V_6 -> V_307 . V_314 = V_30 ;
}
unsigned int F_162 ( struct V_1 * V_2 , T_4 V_300 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_263 ;
if ( V_6 -> V_307 . V_310 > V_300 )
V_6 -> V_307 . V_310 = V_300 ;
V_263 = F_159 ( V_2 , V_300 ) ;
V_263 = F_163 ( V_8 , V_263 ) ;
V_6 -> V_315 = V_300 ;
if ( V_6 -> V_307 . V_308 )
V_263 = F_20 ( V_263 , F_159 ( V_2 , V_6 -> V_307 . V_311 ) ) ;
V_8 -> V_316 = V_263 ;
return V_263 ;
}
unsigned int F_63 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_263 ;
unsigned int V_317 ;
struct V_98 V_99 ;
struct V_142 * V_143 ;
V_263 = V_8 -> V_316 ;
if ( V_18 ) {
T_4 V_305 = F_164 ( V_18 ) ;
if ( V_305 != F_2 ( V_2 ) -> V_315 )
V_263 = F_162 ( V_2 , V_305 ) ;
}
V_317 = F_59 ( V_2 , NULL , & V_99 , & V_143 ) +
sizeof( struct V_76 ) ;
if ( V_317 != V_8 -> V_80 ) {
int V_22 = ( int ) V_317 - V_8 -> V_80 ;
V_263 -= V_22 ;
}
return V_263 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_318 == V_319 &&
V_2 -> V_320 && ! F_74 ( V_321 , & V_2 -> V_320 -> V_88 ) ) {
T_4 V_322 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_323 = F_21 ( V_8 -> V_31 , V_322 ) ;
if ( V_323 < V_8 -> V_25 ) {
V_8 -> V_27 = F_19 ( V_2 ) ;
V_8 -> V_25 = ( V_8 -> V_25 + V_323 ) >> 1 ;
}
V_8 -> V_31 = 0 ;
}
V_8 -> V_29 = V_30 ;
}
static void F_166 ( struct V_1 * V_2 , bool V_324 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_95 , V_8 -> V_325 ) ||
V_8 -> V_10 > V_8 -> V_326 ) {
V_8 -> V_326 = V_8 -> V_10 ;
V_8 -> V_325 = V_8 -> V_11 ;
V_8 -> V_324 = V_324 ;
}
if ( F_167 ( V_2 ) ) {
V_8 -> V_31 = 0 ;
V_8 -> V_29 = V_30 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_31 )
V_8 -> V_31 = V_8 -> V_10 ;
if ( V_327 &&
( T_3 ) ( V_30 - V_8 -> V_29 ) >= F_2 ( V_2 ) -> V_28 )
F_165 ( V_2 ) ;
if ( ! F_168 ( V_2 ) && V_2 -> V_320 &&
F_74 ( V_321 , & V_2 -> V_320 -> V_88 ) &&
( 1 << V_2 -> V_174 ) & ( V_175 | V_178 ) )
F_169 ( V_2 , V_328 ) ;
}
}
static bool F_170 ( const struct V_7 * V_8 )
{
return F_115 ( V_8 -> V_329 , V_8 -> V_95 ) &&
! F_115 ( V_8 -> V_329 , V_8 -> V_11 ) ;
}
static void F_171 ( struct V_7 * V_8 , unsigned int V_263 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_263 )
V_8 -> V_329 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_172 ( bool V_330 , const struct V_7 * V_8 ,
int V_182 )
{
return V_330 &&
( ( V_182 & V_331 ) ||
( ! V_182 && V_8 -> V_10 && F_170 ( V_8 ) ) ) ;
}
T_4 F_173 ( const struct V_1 * V_2 , unsigned int V_263 ,
int V_332 )
{
T_4 V_333 , V_334 ;
V_333 = F_20 ( V_2 -> V_335 >> 10 ,
V_2 -> V_336 - 1 - V_337 ) ;
V_334 = F_29 ( T_4 , V_333 / V_263 , V_332 ) ;
return F_30 ( T_4 , V_334 , V_2 -> V_338 ) ;
}
static T_4 F_174 ( struct V_1 * V_2 , unsigned int V_263 )
{
const struct V_339 * V_340 = F_2 ( V_2 ) -> V_341 ;
T_4 V_342 = V_340 -> V_343 ? V_340 -> V_343 ( V_2 ) : 0 ;
return V_342 ? :
F_173 ( V_2 , V_263 , V_344 ) ;
}
static unsigned int F_175 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_263 ,
unsigned int V_345 ,
int V_182 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_330 , V_346 , V_244 , V_347 ;
V_244 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_347 = V_263 * V_345 ;
if ( F_53 ( V_347 <= V_244 && V_4 != F_176 ( V_2 ) ) )
return V_347 ;
V_346 = F_20 ( V_4 -> V_81 , V_244 ) ;
if ( V_347 <= V_346 )
return V_347 ;
V_330 = V_346 % V_263 ;
if ( F_172 ( V_330 != 0 , V_8 , V_182 ) )
return V_346 - V_330 ;
return V_346 ;
}
static inline unsigned int F_177 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_229 , V_24 , V_348 ;
if ( ( F_5 ( V_4 ) -> V_64 & V_94 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_229 = F_23 ( V_8 ) ;
V_24 = V_8 -> V_25 ;
if ( V_229 >= V_24 )
return 0 ;
V_348 = F_21 ( V_24 >> 1 , 1U ) ;
return F_20 ( V_348 , V_24 - V_229 ) ;
}
static int F_178 ( struct V_3 * V_4 , unsigned int V_263 )
{
int V_342 = F_6 ( V_4 ) ;
if ( ! V_342 || ( V_342 > 1 && F_118 ( V_4 ) != V_263 ) ) {
F_125 ( V_4 , V_263 ) ;
V_342 = F_6 ( V_4 ) ;
}
return V_342 ;
}
static inline bool F_179 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_349 , int V_182 )
{
if ( V_182 & V_350 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_64 & V_94 ) )
return true ;
if ( ! F_172 ( V_4 -> V_81 < V_349 , V_8 , V_182 ) )
return true ;
return false ;
}
static bool F_180 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_349 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_349 )
V_12 = F_5 ( V_4 ) -> V_82 + V_349 ;
return ! F_115 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_181 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_349 , int V_182 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_351 ;
F_178 ( V_4 , V_349 ) ;
if ( ! F_179 ( V_8 , V_4 , V_349 , V_182 ) )
return 0 ;
V_351 = F_177 ( V_8 , V_4 ) ;
if ( V_351 && ! F_180 ( V_8 , V_4 , V_349 ) )
V_351 = 0 ;
return V_351 ;
}
bool F_182 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_168 ( V_2 ) ;
return V_4 &&
F_181 ( V_2 , V_4 , F_63 ( V_2 ) ,
( F_183 ( V_2 , V_4 ) ?
V_8 -> V_182 : V_350 ) ) ;
}
static int F_184 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_263 , T_10 V_284 )
{
struct V_3 * V_285 ;
int V_288 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_298 )
return F_137 ( V_2 , V_4 , V_81 , V_263 , V_284 ) ;
V_285 = F_141 ( V_2 , 0 , V_284 , true ) ;
if ( F_51 ( ! V_285 ) )
return - V_290 ;
V_2 -> V_262 += V_285 -> V_211 ;
F_124 ( V_2 , V_285 -> V_211 ) ;
V_285 -> V_211 += V_288 ;
V_4 -> V_211 -= V_288 ;
F_5 ( V_285 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_285 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_285 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_291 ) ;
F_5 ( V_285 ) -> V_64 = V_88 ;
F_5 ( V_285 ) -> V_92 = 0 ;
F_136 ( V_4 , V_285 ) ;
V_285 -> V_89 = V_4 -> V_89 = V_90 ;
F_146 ( V_4 , V_285 , V_81 ) ;
F_134 ( V_4 , V_285 ) ;
F_125 ( V_4 , V_263 ) ;
F_125 ( V_285 , V_263 ) ;
F_122 ( V_285 ) ;
F_147 ( V_4 , V_285 , V_2 ) ;
return 0 ;
}
static bool F_185 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_324 , T_4 V_345 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_352 , V_353 , V_354 , V_355 , V_229 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_227 V_32 ;
struct V_3 * V_191 ;
int V_356 ;
if ( F_5 ( V_4 ) -> V_64 & V_94 )
goto V_357;
if ( V_6 -> V_318 >= V_358 )
goto V_357;
if ( ( T_3 ) ( V_30 - V_8 -> V_34 ) > 0 )
goto V_357;
V_229 = F_23 ( V_8 ) ;
F_100 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_25 <= V_229 ) ) ;
V_353 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_354 = ( V_8 -> V_25 - V_229 ) * V_8 -> V_316 ;
V_355 = F_20 ( V_353 , V_354 ) ;
if ( V_355 >= V_345 * V_8 -> V_316 )
goto V_357;
if ( ( V_4 != F_176 ( V_2 ) ) && ( V_355 >= V_4 -> V_81 ) )
goto V_357;
V_356 = F_186 ( V_359 ) ;
if ( V_356 ) {
T_4 V_360 = F_20 ( V_8 -> V_361 , V_8 -> V_25 * V_8 -> V_316 ) ;
V_360 /= V_356 ;
if ( V_355 >= V_360 )
goto V_357;
} else {
if ( V_355 > F_187 ( V_8 ) * V_8 -> V_316 )
goto V_357;
}
V_191 = F_188 ( V_2 ) ;
F_101 ( & V_32 ) ;
V_352 = F_189 ( & V_32 , & V_191 -> V_227 ) ;
if ( V_352 < ( V_8 -> V_362 >> 4 ) )
goto V_357;
if ( V_354 < V_353 && V_354 <= V_4 -> V_81 )
* V_324 = true ;
return true ;
V_357:
return false ;
}
static inline void F_190 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_306 * V_306 = F_9 ( V_2 ) ;
T_4 V_363 ;
T_3 V_22 ;
V_363 = V_306 -> V_70 . V_364 ;
V_22 = V_30 - V_6 -> V_307 . V_314 ;
if ( F_51 ( V_22 >= V_363 * V_365 ) ) {
int V_19 = F_63 ( V_2 ) ;
V_6 -> V_307 . V_313 = 0 ;
V_6 -> V_307 . V_310 = V_8 -> V_58 . V_303 +
sizeof( struct V_76 ) +
V_6 -> V_204 -> V_301 ;
V_6 -> V_307 . V_311 = F_160 ( V_2 , V_19 ) ;
V_6 -> V_307 . V_314 = V_30 ;
}
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 , * V_366 , * V_367 ;
struct V_306 * V_306 = F_9 ( V_2 ) ;
int V_313 ;
int V_368 ;
int V_369 , V_81 ;
int V_263 ;
int V_363 ;
if ( F_53 ( ! V_6 -> V_307 . V_308 ||
V_6 -> V_307 . V_313 ||
F_2 ( V_2 ) -> V_318 != V_319 ||
V_8 -> V_25 < 11 ||
V_8 -> V_58 . V_172 || V_8 -> V_58 . V_123 ) )
return - 1 ;
V_263 = F_63 ( V_2 ) ;
V_313 = F_159 ( V_2 , ( V_6 -> V_307 . V_310 +
V_6 -> V_307 . V_311 ) >> 1 ) ;
V_368 = V_313 + ( V_8 -> V_370 + 1 ) * V_8 -> V_316 ;
V_363 = V_6 -> V_307 . V_310 - V_6 -> V_307 . V_311 ;
if ( V_313 > F_159 ( V_2 , V_6 -> V_307 . V_310 ) ||
V_363 < V_306 -> V_70 . V_371 ) {
F_190 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_261 - V_8 -> V_11 < V_368 )
return - 1 ;
if ( V_8 -> V_361 < V_368 )
return - 1 ;
if ( F_115 ( V_8 -> V_11 + V_368 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_25 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_366 = F_141 ( V_2 , V_313 , V_183 , false ) ;
if ( ! V_366 )
return - 1 ;
V_2 -> V_262 += V_366 -> V_211 ;
F_124 ( V_2 , V_366 -> V_211 ) ;
V_4 = F_168 ( V_2 ) ;
F_5 ( V_366 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_366 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_313 ;
F_5 ( V_366 ) -> V_64 = V_248 ;
F_5 ( V_366 ) -> V_92 = 0 ;
V_366 -> V_91 = 0 ;
V_366 -> V_89 = V_4 -> V_89 ;
F_192 ( V_366 , V_4 , V_2 ) ;
V_81 = 0 ;
F_193 (skb, next, sk) {
V_369 = F_30 ( int , V_4 -> V_81 , V_313 - V_81 ) ;
if ( V_366 -> V_89 ) {
F_194 ( V_4 , 0 , F_143 ( V_366 , V_369 ) , V_369 ) ;
} else {
T_11 V_91 = F_195 ( V_4 , 0 ,
F_143 ( V_366 , V_369 ) ,
V_369 , 0 ) ;
V_366 -> V_91 = F_196 ( V_366 -> V_91 , V_91 , V_81 ) ;
}
if ( V_4 -> V_81 <= V_369 ) {
F_5 ( V_366 ) -> V_64 |= F_5 ( V_4 ) -> V_64 ;
F_197 ( V_4 , V_2 ) ;
F_198 ( V_2 , V_4 ) ;
} else {
F_5 ( V_366 ) -> V_64 |= F_5 ( V_4 ) -> V_64 &
~ ( V_94 | V_291 ) ;
if ( ! F_45 ( V_4 ) -> V_292 ) {
F_199 ( V_4 , V_369 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_200 ( V_4 -> V_184 ,
V_4 -> V_81 , 0 ) ;
} else {
F_148 ( V_4 , V_369 ) ;
F_125 ( V_4 , V_263 ) ;
}
F_5 ( V_4 ) -> V_82 += V_369 ;
}
V_81 += V_369 ;
if ( V_81 >= V_313 )
break;
}
F_178 ( V_366 , V_366 -> V_81 ) ;
if ( ! F_99 ( V_2 , V_366 , 1 , V_183 ) ) {
V_8 -> V_25 -- ;
F_1 ( V_2 , V_366 ) ;
V_6 -> V_307 . V_313 = F_160 ( V_2 , V_366 -> V_81 ) ;
V_8 -> V_372 . V_373 = F_5 ( V_366 ) -> V_82 ;
V_8 -> V_372 . V_374 = F_5 ( V_366 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_201 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_375 )
{
unsigned int V_355 ;
V_355 = F_21 ( 2 * V_4 -> V_211 , V_2 -> V_335 >> 10 ) ;
V_355 = F_30 ( T_4 , V_355 , V_376 ) ;
V_355 <<= V_375 ;
if ( F_202 ( & V_2 -> V_212 ) > V_355 ) {
if ( V_4 == V_2 -> V_377 . V_367 ||
V_4 -> V_378 == V_2 -> V_377 . V_367 )
return false ;
F_203 ( V_379 , & V_2 -> V_194 ) ;
F_204 () ;
if ( F_202 ( & V_2 -> V_212 ) > V_355 )
return true ;
}
return false ;
}
static void F_205 ( struct V_7 * V_8 , const enum V_380 V_381 )
{
const T_4 V_32 = V_30 ;
if ( V_8 -> V_382 > V_383 )
V_8 -> V_384 [ V_8 -> V_382 - 1 ] += V_32 - V_8 -> V_385 ;
V_8 -> V_385 = V_32 ;
V_8 -> V_382 = V_381 ;
}
void F_169 ( struct V_1 * V_2 , const enum V_380 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( type > V_8 -> V_382 )
F_205 ( V_8 , type ) ;
}
void F_206 ( struct V_1 * V_2 , const enum V_380 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_207 ( V_2 ) )
F_205 ( V_8 , V_383 ) ;
else if ( type == V_8 -> V_382 )
F_205 ( V_8 , V_386 ) ;
}
static bool F_62 ( struct V_1 * V_2 , unsigned int V_263 , int V_182 ,
int V_387 , T_10 V_284 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_342 , V_388 ;
int V_351 ;
int V_389 ;
bool V_324 = false , V_390 = false ;
T_4 V_345 ;
V_388 = 0 ;
if ( ! V_387 ) {
V_389 = F_191 ( V_2 ) ;
if ( ! V_389 ) {
return false ;
} else if ( V_389 > 0 ) {
V_388 = 1 ;
}
}
V_345 = F_174 ( V_2 , V_263 ) ;
while ( ( V_4 = F_168 ( V_2 ) ) ) {
unsigned int V_355 ;
V_342 = F_178 ( V_4 , V_263 ) ;
F_100 ( ! V_342 ) ;
if ( F_51 ( V_8 -> V_391 ) && V_8 -> V_392 == V_393 ) {
F_101 ( & V_4 -> V_227 ) ;
goto V_391;
}
V_351 = F_177 ( V_8 , V_4 ) ;
if ( ! V_351 ) {
if ( V_387 == 2 )
V_351 = 1 ;
else
break;
}
if ( F_51 ( ! F_180 ( V_8 , V_4 , V_263 ) ) ) {
V_390 = true ;
break;
}
if ( V_342 == 1 ) {
if ( F_51 ( ! F_179 ( V_8 , V_4 , V_263 ,
( F_183 ( V_2 , V_4 ) ?
V_182 : V_350 ) ) ) )
break;
} else {
if ( ! V_387 &&
F_185 ( V_2 , V_4 , & V_324 ,
V_345 ) )
break;
}
V_355 = V_263 ;
if ( V_342 > 1 && ! F_49 ( V_8 ) )
V_355 = F_175 ( V_2 , V_4 , V_263 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_182 ) ;
if ( V_4 -> V_81 > V_355 &&
F_51 ( F_184 ( V_2 , V_4 , V_355 , V_263 , V_284 ) ) )
break;
if ( F_74 ( V_197 , & V_2 -> V_194 ) )
F_73 ( V_197 , & V_2 -> V_194 ) ;
if ( F_201 ( V_2 , V_4 , 0 ) )
break;
if ( F_51 ( F_99 ( V_2 , V_4 , 1 , V_284 ) ) )
break;
V_391:
F_1 ( V_2 , V_4 ) ;
F_171 ( V_8 , V_263 , V_4 ) ;
V_388 += F_6 ( V_4 ) ;
if ( V_387 )
break;
}
if ( V_390 )
F_169 ( V_2 , V_394 ) ;
else
F_206 ( V_2 , V_394 ) ;
if ( F_53 ( V_388 ) ) {
if ( F_208 ( V_2 ) )
V_8 -> V_395 += V_388 ;
if ( V_387 != 2 )
F_209 ( V_2 ) ;
V_324 |= ( F_23 ( V_8 ) >= V_8 -> V_25 ) ;
F_166 ( V_2 , V_324 ) ;
return false ;
}
return ! V_8 -> V_10 && F_168 ( V_2 ) ;
}
bool F_209 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_396 , V_397 , V_398 ;
T_4 V_399 = F_210 ( V_8 -> V_362 >> 3 ) ;
if ( F_138 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_138 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_8 -> V_400 )
return false ;
if ( V_6 -> V_13 != V_401 )
return false ;
if ( V_402 < 3 || ! V_8 -> V_10 ||
! F_211 ( V_8 ) || F_2 ( V_2 ) -> V_318 != V_319 )
return false ;
if ( ( V_8 -> V_25 > F_23 ( V_8 ) ) &&
F_168 ( V_2 ) )
return false ;
V_396 = V_399 << 1 ? : V_403 ;
if ( V_8 -> V_10 == 1 )
V_396 = F_29 ( T_4 , V_396 ,
( V_399 + ( V_399 >> 1 ) + V_404 ) ) ;
V_396 = F_29 ( T_4 , V_396 , F_212 ( 10 ) ) ;
V_397 = V_30 + V_396 ;
V_398 = ( T_4 ) F_2 ( V_2 ) -> V_405 ;
if ( ( T_3 ) ( V_397 - V_398 ) > 0 ) {
T_3 V_22 = V_398 - V_30 ;
if ( V_22 > 0 )
V_396 = V_22 ;
}
F_213 ( V_2 , V_15 , V_396 ,
V_406 ) ;
return true ;
}
static bool F_214 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_215 ( V_2 , V_4 ) ) ) {
F_34 ( F_9 ( V_2 ) ,
V_407 ) ;
return true ;
}
return false ;
}
void F_216 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_408 ;
int V_19 = F_63 ( V_2 ) ;
V_4 = F_168 ( V_2 ) ;
if ( V_4 ) {
if ( F_180 ( V_8 , V_4 , V_19 ) ) {
V_408 = V_8 -> V_10 ;
F_62 ( V_2 , V_19 , V_409 , 2 , V_183 ) ;
if ( V_8 -> V_10 > V_408 )
goto V_410;
goto V_411;
}
V_4 = F_217 ( V_2 , V_4 ) ;
} else {
V_4 = F_176 ( V_2 ) ;
}
if ( V_8 -> V_412 )
goto V_411;
if ( F_138 ( ! V_4 ) )
goto V_411;
if ( F_214 ( V_2 , V_4 ) )
goto V_411;
V_408 = F_6 ( V_4 ) ;
if ( F_138 ( ! V_408 ) )
goto V_411;
if ( ( V_408 > 1 ) && ( V_4 -> V_81 > ( V_408 - 1 ) * V_19 ) ) {
if ( F_51 ( F_137 ( V_2 , V_4 , ( V_408 - 1 ) * V_19 , V_19 ,
V_183 ) ) )
goto V_411;
V_4 = F_218 ( V_2 , V_4 ) ;
}
if ( F_138 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_411;
if ( F_219 ( V_2 , V_4 , 1 ) )
goto V_411;
V_8 -> V_412 = V_8 -> V_11 ;
V_410:
F_34 ( F_9 ( V_2 ) , V_413 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_411:
F_7 ( V_2 ) ;
}
void F_220 ( struct V_1 * V_2 , unsigned int V_349 ,
int V_182 )
{
if ( F_51 ( V_2 -> V_174 == V_414 ) )
return;
if ( F_62 ( V_2 , V_349 , V_182 , 0 ,
F_221 ( V_2 , V_183 ) ) )
F_222 ( V_2 ) ;
}
void F_223 ( struct V_1 * V_2 , unsigned int V_263 )
{
struct V_3 * V_4 = F_168 ( V_2 ) ;
F_100 ( ! V_4 || V_4 -> V_81 < V_263 ) ;
F_62 ( V_2 , V_263 , V_350 , 1 , V_2 -> V_415 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_416 ;
int V_417 = F_224 ( V_2 ) ;
int V_418 = F_225 ( V_2 ) ;
int V_419 = F_30 ( int , V_8 -> V_45 , V_418 ) ;
int V_244 ;
if ( F_51 ( V_19 > V_419 ) ) {
V_19 = V_419 ;
if ( V_19 <= 0 )
return 0 ;
}
if ( V_417 < ( V_419 >> 1 ) ) {
V_6 -> V_35 . V_420 = 0 ;
if ( F_226 ( V_2 ) )
V_8 -> V_421 = F_20 ( V_8 -> V_421 ,
4U * V_8 -> V_20 ) ;
V_417 = F_227 ( V_417 , 1 << V_8 -> V_58 . V_47 ) ;
if ( V_417 < ( V_418 >> 4 ) || V_417 < V_19 )
return 0 ;
}
if ( V_417 > V_8 -> V_421 )
V_417 = V_8 -> V_421 ;
V_244 = V_8 -> V_44 ;
if ( V_8 -> V_58 . V_47 ) {
V_244 = V_417 ;
if ( ( ( V_244 >> V_8 -> V_58 . V_47 ) << V_8 -> V_58 . V_47 ) != V_244 )
V_244 = ( ( ( V_244 >> V_8 -> V_58 . V_47 ) + 1 )
<< V_8 -> V_58 . V_47 ) ;
} else {
if ( V_244 <= V_417 - V_19 || V_244 > V_417 )
V_244 = ( V_417 / V_19 ) * V_19 ;
else if ( V_19 == V_419 &&
V_417 > V_244 + ( V_419 >> 1 ) )
V_244 = V_417 ;
}
return V_244 ;
}
void F_228 ( struct V_3 * V_4 ,
const struct V_3 * V_422 )
{
if ( F_51 ( F_133 ( V_422 ) ) ) {
const struct V_278 * V_423 =
F_45 ( V_422 ) ;
struct V_278 * V_279 = F_45 ( V_4 ) ;
V_279 -> V_275 |= V_423 -> V_275 & V_276 ;
V_279 -> V_280 = V_423 -> V_280 ;
F_5 ( V_4 ) -> V_274 |=
F_5 ( V_422 ) -> V_274 ;
}
}
static bool F_229 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_422 = F_218 ( V_2 , V_4 ) ;
int V_424 , V_425 ;
V_424 = V_4 -> V_81 ;
V_425 = V_422 -> V_81 ;
F_100 ( F_6 ( V_4 ) != 1 || F_6 ( V_422 ) != 1 ) ;
if ( V_425 ) {
if ( V_425 <= F_230 ( V_4 ) )
F_194 ( V_422 , 0 , F_143 ( V_4 , V_425 ) ,
V_425 ) ;
else if ( ! F_231 ( V_4 , V_422 , V_425 ) )
return false ;
}
F_232 ( V_2 , V_422 , V_4 ) ;
F_197 ( V_422 , V_2 ) ;
if ( V_422 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_196 ( V_4 -> V_91 , V_422 -> V_91 , V_424 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_422 ) -> V_12 ;
F_5 ( V_4 ) -> V_64 |= F_5 ( V_422 ) -> V_64 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_422 ) -> V_92 & V_426 ;
F_5 ( V_4 ) -> V_283 = F_5 ( V_422 ) -> V_283 ;
F_233 ( V_8 ) ;
if ( V_422 == V_8 -> V_427 )
V_8 -> V_427 = V_4 ;
F_130 ( V_2 , V_422 , F_6 ( V_422 ) ) ;
F_228 ( V_4 , V_422 ) ;
F_198 ( V_2 , V_422 ) ;
return true ;
}
static bool F_234 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_103 ( V_4 ) )
return false ;
if ( V_4 == F_168 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_269 )
return false ;
return true ;
}
static void F_235 ( struct V_1 * V_2 , struct V_3 * V_428 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_428 , * V_429 ;
bool V_430 = true ;
if ( ! V_431 )
return;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
return;
F_193 (skb, tmp, sk) {
if ( ! F_234 ( V_2 , V_4 ) )
break;
if ( ! F_236 ( V_428 ) )
break;
V_49 -= V_4 -> V_81 ;
if ( V_430 ) {
V_430 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( F_115 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
if ( ! F_229 ( V_2 , V_428 ) )
break;
}
}
int F_219 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_334 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_349 ;
int V_293 , V_81 , V_226 ;
if ( V_6 -> V_307 . V_313 )
V_6 -> V_307 . V_313 = 0 ;
if ( F_202 ( & V_2 -> V_212 ) >
F_30 ( T_4 , V_2 -> V_262 + ( V_2 -> V_262 >> 2 ) ,
V_2 -> V_432 ) )
return - V_433 ;
if ( F_214 ( V_2 , V_4 ) )
return - V_434 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_95 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_95 ) )
F_237 () ;
if ( F_154 ( V_2 , V_4 , V_8 -> V_95 - F_5 ( V_4 ) -> V_82 ) )
return - V_290 ;
}
if ( F_2 ( V_2 ) -> V_204 -> V_435 ( V_2 ) )
return - V_436 ;
V_349 = F_63 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_95 )
return - V_433 ;
V_81 = V_349 * V_334 ;
if ( V_4 -> V_81 > V_81 ) {
if ( F_137 ( V_2 , V_4 , V_81 , V_349 , V_183 ) )
return - V_290 ;
} else {
if ( F_140 ( V_4 , V_183 ) )
return - V_290 ;
V_293 = F_6 ( V_4 ) ;
F_125 ( V_4 , V_349 ) ;
V_293 -= F_6 ( V_4 ) ;
if ( V_293 )
F_130 ( V_2 , V_4 , V_293 ) ;
if ( V_4 -> V_81 < V_349 )
F_235 ( V_2 , V_4 , V_349 ) ;
}
if ( ( F_5 ( V_4 ) -> V_64 & V_437 ) == V_437 )
F_41 ( V_2 , V_4 ) ;
if ( F_51 ( ( V_438 && ( ( unsigned long ) V_4 -> V_184 & 3 ) ) ||
F_238 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_366 ;
F_101 ( & V_4 -> V_227 ) ;
V_366 = F_239 ( V_4 , V_337 , V_183 ) ;
V_226 = V_366 ? F_99 ( V_2 , V_366 , 0 , V_183 ) :
- V_230 ;
} else {
V_226 = F_99 ( V_2 , V_4 , 1 , V_183 ) ;
}
if ( F_53 ( ! V_226 ) ) {
V_334 = F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_92 |= V_426 ;
F_117 ( F_9 ( V_2 ) , V_439 , V_334 ) ;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
F_240 ( F_9 ( V_2 ) , V_440 ) ;
V_8 -> V_441 += V_334 ;
}
return V_226 ;
}
int F_241 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_334 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_226 = F_219 ( V_2 , V_4 , V_334 ) ;
if ( V_226 == 0 ) {
#if V_442 > 0
if ( F_5 ( V_4 ) -> V_92 & V_270 ) {
F_242 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_92 |= V_443 ;
V_8 -> V_181 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_444 )
V_8 -> V_444 = F_56 ( V_4 ) ;
} else if ( V_226 != - V_434 ) {
F_34 ( F_9 ( V_2 ) , V_445 ) ;
}
if ( V_8 -> V_446 < 0 )
V_8 -> V_446 = 0 ;
V_8 -> V_446 += F_6 ( V_4 ) ;
return V_226 ;
}
static bool F_243 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_318 != V_358 )
return false ;
if ( F_128 ( V_8 ) )
return false ;
if ( F_182 ( V_2 ) )
return false ;
return true ;
}
void F_61 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_447 = NULL ;
T_4 V_345 , V_448 ;
int V_449 ;
int V_450 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_180 )
V_8 -> V_451 = V_8 -> V_95 ;
if ( V_8 -> V_427 ) {
V_4 = V_8 -> V_427 ;
V_448 = F_5 ( V_4 ) -> V_12 ;
if ( F_115 ( V_448 , V_8 -> V_451 ) )
V_448 = V_8 -> V_451 ;
} else {
V_4 = F_188 ( V_2 ) ;
V_448 = V_8 -> V_95 ;
}
V_345 = F_174 ( V_2 , F_63 ( V_2 ) ) ;
F_244 (skb, sk) {
T_5 V_92 ;
int V_334 ;
if ( V_4 == F_168 ( V_2 ) )
break;
if ( ! V_447 )
V_8 -> V_427 = V_4 ;
V_334 = V_8 -> V_25 - F_23 ( V_8 ) ;
if ( V_334 <= 0 )
return;
V_92 = F_5 ( V_4 ) -> V_92 ;
V_334 = F_30 ( int , V_334 , V_345 ) ;
if ( V_450 ) {
V_452:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_129 ( V_8 ) ) )
break;
V_449 = V_453 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_451 ) ) {
V_8 -> V_451 = V_448 ;
if ( ! F_243 ( V_2 ) )
break;
if ( V_447 ) {
V_4 = V_447 ;
V_447 = NULL ;
}
V_450 = 1 ;
goto V_452;
} else if ( ! ( V_92 & V_271 ) ) {
if ( ! V_447 && ! ( V_92 & ( V_270 | V_269 ) ) )
V_447 = V_4 ;
continue;
} else {
V_448 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_318 != V_454 )
V_449 = V_455 ;
else
V_449 = V_456 ;
}
if ( V_92 & ( V_269 | V_270 ) )
continue;
if ( F_201 ( V_2 , V_4 , 1 ) )
return;
if ( F_241 ( V_2 , V_4 , V_334 ) )
return;
F_8 ( F_9 ( V_2 ) , V_449 , F_6 ( V_4 ) ) ;
if ( F_208 ( V_2 ) )
V_8 -> V_395 += F_6 ( V_4 ) ;
if ( V_4 == F_188 ( V_2 ) )
F_213 ( V_2 , V_401 ,
F_2 ( V_2 ) -> V_28 ,
V_406 ) ;
}
}
void F_245 ( struct V_1 * V_2 , int V_170 )
{
int V_457 ;
if ( V_170 <= V_2 -> V_458 )
return;
V_457 = F_246 ( V_170 ) ;
V_2 -> V_458 += V_457 * V_459 ;
F_247 ( V_2 , V_457 ) ;
if ( V_460 && V_2 -> V_461 )
F_248 ( V_2 -> V_461 , V_457 ) ;
}
void F_249 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_462 = F_176 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_462 && ( F_168 ( V_2 ) || F_226 ( V_2 ) ) ) {
V_463:
F_5 ( V_462 ) -> V_64 |= V_94 ;
F_5 ( V_462 ) -> V_12 ++ ;
V_8 -> V_261 ++ ;
if ( ! F_168 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_250 ( V_337 , V_2 -> V_415 ) ;
if ( F_51 ( ! V_4 ) ) {
if ( V_462 )
goto V_463;
return;
}
F_251 ( V_4 , V_337 ) ;
F_245 ( V_2 , V_4 -> V_211 ) ;
F_47 ( V_4 , V_8 -> V_261 ,
V_248 | V_94 ) ;
F_121 ( V_2 , V_4 ) ;
}
F_220 ( V_2 , F_63 ( V_2 ) , V_409 ) ;
}
void F_252 ( struct V_1 * V_2 , T_10 V_464 )
{
struct V_3 * V_4 ;
V_4 = F_253 ( V_337 , V_464 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_465 ) ;
return;
}
F_251 ( V_4 , V_337 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_248 | V_466 ) ;
F_101 ( & V_4 -> V_227 ) ;
if ( F_99 ( V_2 , V_4 , 0 , V_464 ) )
F_34 ( F_9 ( V_2 ) , V_465 ) ;
F_254 ( F_9 ( V_2 ) , V_467 ) ;
}
int F_255 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_188 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_64 & V_93 ) ) {
F_256 ( L_2 , V_468 ) ;
return - V_469 ;
}
if ( ! ( F_5 ( V_4 ) -> V_64 & V_248 ) ) {
if ( F_103 ( V_4 ) ) {
struct V_3 * V_366 = F_257 ( V_4 , V_183 ) ;
if ( ! V_366 )
return - V_290 ;
F_197 ( V_4 , V_2 ) ;
F_122 ( V_366 ) ;
F_258 ( V_2 , V_366 ) ;
F_198 ( V_2 , V_4 ) ;
V_2 -> V_262 += V_366 -> V_211 ;
F_124 ( V_2 , V_366 -> V_211 ) ;
V_4 = V_366 ;
}
F_5 ( V_4 ) -> V_64 |= V_248 ;
F_36 ( V_2 , V_4 ) ;
}
return F_99 ( V_2 , V_4 , 1 , V_183 ) ;
}
struct V_3 * F_259 ( const struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_132 * V_133 ,
enum V_470 V_471 )
{
struct V_165 * V_166 = F_43 ( V_75 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_142 * V_143 = NULL ;
struct V_98 V_99 ;
struct V_3 * V_4 ;
int V_225 ;
struct V_76 * V_77 ;
T_6 V_472 ;
int V_19 ;
V_4 = F_253 ( V_337 , V_183 ) ;
if ( F_51 ( ! V_4 ) ) {
F_260 ( V_18 ) ;
return NULL ;
}
F_251 ( V_4 , V_337 ) ;
switch ( V_471 ) {
case V_473 :
F_261 ( V_4 , F_262 ( V_75 ) ) ;
break;
case V_474 :
break;
case V_475 :
F_261 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_263 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
V_472 = F_94 ( V_8 -> V_58 . V_472 ) ;
if ( V_472 && V_472 < V_19 )
V_19 = V_472 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
#ifdef F_264
if ( F_51 ( V_75 -> V_476 ) )
V_4 -> V_227 . V_477 = F_265 ( V_75 ) ;
else
#endif
F_101 ( & V_4 -> V_227 ) ;
#ifdef F_55
F_266 () ;
V_143 = F_58 ( V_75 ) -> V_149 -> V_478 ( V_2 , F_262 ( V_75 ) ) ;
#endif
F_267 ( V_4 , F_58 ( V_75 ) -> V_479 , V_480 ) ;
V_225 = F_57 ( V_75 , V_19 , V_4 , & V_99 , V_143 , V_133 ) +
sizeof( * V_77 ) ;
F_108 ( V_4 , V_225 ) ;
F_109 ( V_4 ) ;
V_77 = (struct V_76 * ) V_4 -> V_184 ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_481 = 1 ;
V_77 -> V_482 = 1 ;
F_42 ( V_75 , V_77 ) ;
V_77 -> V_234 = F_114 ( V_166 -> V_483 ) ;
V_77 -> V_236 = V_166 -> V_484 ;
F_47 ( V_4 , F_58 ( V_75 ) -> V_485 ,
V_93 | V_248 ) ;
V_77 -> V_82 = F_52 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_238 = F_52 ( F_58 ( V_75 ) -> V_60 ) ;
V_77 -> V_244 = F_114 ( F_20 ( V_75 -> V_486 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_77 + 1 ) , NULL , & V_99 ) ;
V_77 -> V_487 = ( V_225 >> 2 ) ;
F_268 ( F_9 ( V_2 ) , V_250 ) ;
#ifdef F_55
if ( V_143 )
F_58 ( V_75 ) -> V_149 -> V_246 ( V_99 . V_105 ,
V_143 , F_262 ( V_75 ) , V_4 ) ;
F_269 () ;
#endif
V_4 -> V_254 = 0 ;
return V_4 ;
}
static void F_270 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_339 * V_488 ;
T_4 V_489 = F_271 ( V_18 , V_490 ) ;
if ( V_489 == V_491 )
return;
F_266 () ;
V_488 = F_272 ( V_489 ) ;
if ( F_53 ( V_488 && F_273 ( V_488 -> V_492 ) ) ) {
F_274 ( V_6 -> V_341 -> V_492 ) ;
V_6 -> V_493 = F_275 ( V_18 ) ;
V_6 -> V_341 = V_488 ;
}
F_269 () ;
}
static void F_276 ( struct V_1 * V_2 )
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
if ( V_8 -> V_58 . V_472 )
V_8 -> V_58 . V_303 = V_8 -> V_58 . V_472 ;
V_8 -> V_494 = 0 ;
F_161 ( V_2 ) ;
F_162 ( V_2 , F_164 ( V_18 ) ) ;
F_270 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_271 ( V_18 , V_495 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_58 . V_472 && V_8 -> V_58 . V_472 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_58 . V_472 ;
F_277 ( V_2 ) ;
if ( V_2 -> V_496 & V_497 &&
( V_8 -> V_45 > F_225 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_225 ( V_2 ) ;
F_28 ( F_225 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_58 . V_498 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_157 ,
& V_47 ,
F_271 ( V_18 , V_499 ) ) ;
V_8 -> V_58 . V_47 = V_47 ;
V_8 -> V_421 = V_8 -> V_44 ;
V_2 -> V_500 = 0 ;
F_278 ( V_2 , V_501 ) ;
V_8 -> V_361 = 0 ;
F_279 ( V_8 , 0 ) ;
V_8 -> V_95 = V_8 -> V_261 ;
V_8 -> V_329 = V_8 -> V_261 ;
V_8 -> V_96 = V_8 -> V_261 ;
V_8 -> V_11 = V_8 -> V_261 ;
if ( F_53 ( ! V_8 -> V_391 ) )
V_8 -> V_60 = 0 ;
else
V_8 -> V_502 = V_30 ;
V_8 -> V_59 = V_8 -> V_60 ;
V_8 -> V_503 = V_8 -> V_60 ;
F_2 ( V_2 ) -> V_28 = V_403 ;
F_2 ( V_2 ) -> V_504 = 0 ;
F_280 ( V_8 ) ;
}
static void F_281 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_222 * V_223 = F_5 ( V_4 ) ;
V_223 -> V_12 += V_4 -> V_81 ;
F_122 ( V_4 ) ;
F_282 ( V_2 , V_4 ) ;
V_2 -> V_262 += V_4 -> V_211 ;
F_124 ( V_2 , V_4 -> V_211 ) ;
V_8 -> V_261 = V_223 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_283 ( struct V_1 * V_2 , struct V_3 * V_481 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_505 = V_8 -> V_148 ;
int V_506 = 0 , V_49 , V_226 = 0 ;
unsigned long V_507 = 0 ;
struct V_3 * V_508 ;
V_8 -> V_58 . V_303 = V_8 -> V_20 ;
F_284 ( V_2 , & V_8 -> V_58 . V_303 , & V_505 -> V_161 ,
& V_506 , & V_507 ) ;
if ( V_506 > 1 &&
F_285 ( V_509 , V_507 + ( 60 * V_365 << V_506 ) ) ) {
V_505 -> V_161 . V_81 = - 1 ;
goto V_510;
}
if ( V_511 & V_512 )
V_505 -> V_161 . V_81 = - 1 ;
else if ( V_505 -> V_161 . V_81 <= 0 )
goto V_510;
if ( V_8 -> V_58 . V_472 && V_8 -> V_58 . V_472 < V_8 -> V_58 . V_303 )
V_8 -> V_58 . V_303 = V_8 -> V_58 . V_472 ;
V_49 = F_157 ( V_2 , F_2 ( V_2 ) -> V_315 ) -
V_145 ;
V_49 = F_30 ( V_513 , V_49 , V_505 -> V_170 ) ;
V_49 = F_30 ( V_513 , V_49 , F_286 ( V_337 ) ) ;
V_508 = F_141 ( V_2 , V_49 , V_2 -> V_415 , false ) ;
if ( ! V_508 )
goto V_510;
V_508 -> V_89 = V_90 ;
memcpy ( V_508 -> V_255 , V_481 -> V_255 , sizeof( V_481 -> V_255 ) ) ;
if ( V_49 ) {
int V_514 = F_287 ( F_143 ( V_508 , V_49 ) , V_49 ,
& V_505 -> V_184 -> V_515 ) ;
if ( F_51 ( ! V_514 ) ) {
F_288 ( V_508 ) ;
goto V_510;
}
if ( V_514 != V_49 ) {
F_144 ( V_508 , V_514 ) ;
V_49 = V_514 ;
}
}
if ( V_49 == V_505 -> V_170 )
V_505 -> V_184 = NULL ;
V_505 -> V_514 = V_49 ;
F_281 ( V_2 , V_508 ) ;
if ( V_508 -> V_81 )
F_169 ( V_2 , V_386 ) ;
V_226 = F_99 ( V_2 , V_508 , 1 , V_2 -> V_415 ) ;
V_481 -> V_227 = V_508 -> V_227 ;
F_5 ( V_508 ) -> V_82 ++ ;
F_5 ( V_508 ) -> V_64 = V_248 | V_291 ;
if ( ! V_226 ) {
V_8 -> V_508 = ( V_505 -> V_514 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_516;
}
V_510:
if ( V_505 -> V_161 . V_81 > 0 )
V_505 -> V_161 . V_81 = 0 ;
V_226 = F_99 ( V_2 , V_481 , 1 , V_2 -> V_415 ) ;
if ( V_226 )
V_8 -> V_163 = 0 ;
V_516:
V_505 -> V_161 . V_81 = - 1 ;
return V_226 ;
}
int F_289 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_285 ;
int V_226 ;
F_276 ( V_2 ) ;
if ( F_51 ( V_8 -> V_391 ) ) {
F_290 ( V_2 , NULL ) ;
return 0 ;
}
V_285 = F_141 ( V_2 , 0 , V_2 -> V_415 , true ) ;
if ( F_51 ( ! V_285 ) )
return - V_230 ;
F_47 ( V_285 , V_8 -> V_261 ++ , V_93 ) ;
V_8 -> V_444 = V_30 ;
F_281 ( V_2 , V_285 ) ;
F_39 ( V_2 , V_285 ) ;
V_226 = V_8 -> V_148 ? F_283 ( V_2 , V_285 ) :
F_99 ( V_2 , V_285 , 1 , V_2 -> V_415 ) ;
if ( V_226 == - V_517 )
return V_226 ;
V_8 -> V_11 = V_8 -> V_261 ;
V_8 -> V_518 = V_8 -> V_261 ;
F_254 ( F_9 ( V_2 ) , V_519 ) ;
F_213 ( V_2 , V_401 ,
F_2 ( V_2 ) -> V_28 , V_406 ) ;
return 0 ;
}
void F_291 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_396 ;
F_18 ( V_2 , V_520 ) ;
if ( V_37 > V_521 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_522 = V_365 / 2 ;
if ( V_6 -> V_35 . V_38 ||
( V_6 -> V_35 . V_523 & V_524 ) )
V_522 = V_404 ;
if ( V_8 -> V_362 ) {
int V_399 = F_29 ( int , F_210 ( V_8 -> V_362 >> 3 ) ,
V_521 ) ;
if ( V_399 < V_522 )
V_522 = V_399 ;
}
V_37 = F_20 ( V_37 , V_522 ) ;
}
V_396 = V_509 + V_37 ;
if ( V_6 -> V_35 . V_523 & V_525 ) {
if ( V_6 -> V_35 . V_526 ||
F_292 ( V_6 -> V_35 . V_396 , V_509 + ( V_37 >> 2 ) ) ) {
F_293 ( V_2 ) ;
return;
}
if ( ! F_285 ( V_396 , V_6 -> V_35 . V_396 ) )
V_396 = V_6 -> V_35 . V_396 ;
}
V_6 -> V_35 . V_523 |= V_527 | V_525 ;
V_6 -> V_35 . V_396 = V_396 ;
F_294 ( V_2 , & V_6 -> V_528 , V_396 ) ;
}
void F_293 ( struct V_1 * V_2 )
{
struct V_3 * V_285 ;
if ( V_2 -> V_174 == V_414 )
return;
F_18 ( V_2 , V_529 ) ;
V_285 = F_253 ( V_337 ,
F_221 ( V_2 , V_183 | V_530 ) ) ;
if ( F_51 ( ! V_285 ) ) {
F_295 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_531 ;
F_213 ( V_2 , V_40 ,
V_404 , V_406 ) ;
return;
}
F_251 ( V_285 , V_337 ) ;
F_47 ( V_285 , F_10 ( V_2 ) , V_248 ) ;
F_296 ( V_285 ) ;
F_101 ( & V_285 -> V_227 ) ;
F_99 ( V_2 , V_285 , 0 , ( V_532 T_10 ) 0 ) ;
}
static int F_297 ( struct V_1 * V_2 , int V_533 , int V_534 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_253 ( V_337 ,
F_221 ( V_2 , V_183 | V_530 ) ) ;
if ( ! V_4 )
return - 1 ;
F_251 ( V_4 , V_337 ) ;
F_47 ( V_4 , V_8 -> V_95 - ! V_533 , V_248 ) ;
F_101 ( & V_4 -> V_227 ) ;
F_34 ( F_9 ( V_2 ) , V_534 ) ;
return F_99 ( V_2 , V_4 , 0 , ( V_532 T_10 ) 0 ) ;
}
void F_298 ( struct V_1 * V_2 )
{
if ( V_2 -> V_174 == V_535 ) {
F_3 ( V_2 ) -> V_536 = F_3 ( V_2 ) -> V_60 - 1 ;
F_297 ( V_2 , 0 , V_537 ) ;
}
}
int F_299 ( struct V_1 * V_2 , int V_534 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_174 == V_414 )
return - 1 ;
V_4 = F_168 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_226 ;
unsigned int V_19 = F_63 ( V_2 ) ;
unsigned int V_538 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_518 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_518 = F_5 ( V_4 ) -> V_12 ;
if ( V_538 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_538 = F_20 ( V_538 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_291 ;
if ( F_137 ( V_2 , V_4 , V_538 , V_19 , V_183 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_125 ( V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_291 ;
V_226 = F_99 ( V_2 , V_4 , 1 , V_183 ) ;
if ( ! V_226 )
F_1 ( V_2 , V_4 ) ;
return V_226 ;
} else {
if ( F_300 ( V_8 -> V_96 , V_8 -> V_95 + 1 , V_8 -> V_95 + 0xFFFF ) )
F_297 ( V_2 , 1 , V_534 ) ;
return F_297 ( V_2 , 0 , V_534 ) ;
}
}
void F_301 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_306 * V_306 = F_9 ( V_2 ) ;
unsigned long V_539 ;
int V_226 ;
V_226 = F_299 ( V_2 , V_537 ) ;
if ( V_8 -> V_10 || ! F_168 ( V_2 ) ) {
V_6 -> V_540 = 0 ;
V_6 -> V_541 = 0 ;
return;
}
if ( V_226 <= 0 ) {
if ( V_6 -> V_541 < V_306 -> V_70 . V_542 )
V_6 -> V_541 ++ ;
V_6 -> V_540 ++ ;
V_539 = V_406 ;
} else {
if ( ! V_6 -> V_540 )
V_6 -> V_540 = 1 ;
V_539 = V_543 ;
}
F_213 ( V_2 , V_544 ,
F_302 ( V_2 , V_539 ) ,
V_406 ) ;
}
int F_303 ( const struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_545 * V_546 = F_58 ( V_75 ) -> V_149 ;
struct V_547 V_260 ;
int V_548 ;
F_58 ( V_75 ) -> V_479 = F_304 () ;
V_548 = V_546 -> V_549 ( V_2 , NULL , & V_260 , V_75 , NULL , V_473 ) ;
if ( ! V_548 ) {
F_268 ( F_9 ( V_2 ) , V_439 ) ;
F_240 ( F_9 ( V_2 ) , V_440 ) ;
if ( F_51 ( F_305 ( V_2 ) ) )
F_3 ( V_2 ) -> V_441 ++ ;
}
return V_548 ;
}
