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
else if ( F_38 ( V_2 ) ||
F_39 ( V_2 ) )
F_40 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
bool V_70 = F_39 ( V_2 ) ;
bool V_71 = F_9 ( V_2 ) -> V_72 . V_73 == 1 ||
F_38 ( V_2 ) || V_70 ;
if ( ! V_71 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_42 ( V_20 , V_74 ) )
V_71 = true ;
}
V_8 -> V_67 = 0 ;
if ( V_71 ) {
F_5 ( V_4 ) -> V_65 |= V_69 | V_66 ;
V_8 -> V_67 = V_68 ;
if ( F_38 ( V_2 ) || V_70 )
F_40 ( V_2 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_9 ( V_2 ) -> V_72 . V_75 )
F_5 ( V_4 ) -> V_65 &= ~ ( V_69 | V_66 ) ;
}
static void
F_44 ( const struct V_76 * V_77 , struct V_78 * V_79 )
{
if ( F_45 ( V_77 ) -> V_80 )
V_79 -> V_81 = 1 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_78 * V_79 , int V_82 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_67 & V_68 ) {
if ( V_4 -> V_83 != V_82 &&
! F_11 ( F_5 ( V_4 ) -> V_84 , V_8 -> V_11 ) ) {
F_40 ( V_2 ) ;
if ( V_8 -> V_67 & V_85 ) {
V_8 -> V_67 &= ~ V_85 ;
V_79 -> V_86 = 1 ;
F_47 ( V_4 ) -> V_87 |= V_88 ;
}
} else if ( ! F_38 ( V_2 ) ) {
F_48 ( V_2 ) ;
}
if ( V_8 -> V_67 & V_89 )
V_79 -> V_81 = 1 ;
}
}
static void F_49 ( struct V_3 * V_4 , T_4 V_84 , T_7 V_90 )
{
V_4 -> V_91 = V_92 ;
V_4 -> V_93 = 0 ;
F_5 ( V_4 ) -> V_65 = V_90 ;
F_5 ( V_4 ) -> V_94 = 0 ;
F_50 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_84 = V_84 ;
if ( V_90 & ( V_95 | V_96 ) )
V_84 ++ ;
F_5 ( V_4 ) -> V_12 = V_84 ;
}
static inline bool F_51 ( const struct V_7 * V_8 )
{
return V_8 -> V_97 != V_8 -> V_98 ;
}
static void F_52 ( T_8 * V_99 , struct V_7 * V_8 ,
struct V_100 * V_101 )
{
T_6 V_102 = V_101 -> V_102 ;
if ( F_53 ( V_103 & V_102 ) ) {
* V_99 ++ = F_54 ( ( V_104 << 24 ) | ( V_104 << 16 ) |
( V_105 << 8 ) | V_106 ) ;
V_101 -> V_107 = ( T_5 * ) V_99 ;
V_99 += 4 ;
}
if ( F_53 ( V_101 -> V_21 ) ) {
* V_99 ++ = F_54 ( ( V_108 << 24 ) |
( V_109 << 16 ) |
V_101 -> V_21 ) ;
}
if ( F_55 ( V_110 & V_102 ) ) {
if ( F_53 ( V_111 & V_102 ) ) {
* V_99 ++ = F_54 ( ( V_112 << 24 ) |
( V_113 << 16 ) |
( V_114 << 8 ) |
V_115 ) ;
V_102 &= ~ V_111 ;
} else {
* V_99 ++ = F_54 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_114 << 8 ) |
V_115 ) ;
}
* V_99 ++ = F_54 ( V_101 -> V_116 ) ;
* V_99 ++ = F_54 ( V_101 -> V_117 ) ;
}
if ( F_53 ( V_111 & V_102 ) ) {
* V_99 ++ = F_54 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
}
if ( F_53 ( V_118 & V_102 ) ) {
* V_99 ++ = F_54 ( ( V_104 << 24 ) |
( V_119 << 16 ) |
( V_120 << 8 ) |
V_101 -> V_121 ) ;
}
if ( F_53 ( V_101 -> V_122 ) ) {
struct V_123 * V_124 = V_8 -> V_16 . V_125 ?
V_8 -> V_126 : V_8 -> V_127 ;
int V_128 ;
* V_99 ++ = F_54 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_129 << 8 ) |
( V_130 + ( V_101 -> V_122 *
V_131 ) ) ) ;
for ( V_128 = 0 ; V_128 < V_101 -> V_122 ;
++ V_128 ) {
* V_99 ++ = F_54 ( V_124 [ V_128 ] . V_132 ) ;
* V_99 ++ = F_54 ( V_124 [ V_128 ] . V_12 ) ;
}
V_8 -> V_16 . V_125 = 0 ;
}
if ( F_53 ( V_133 & V_102 ) ) {
struct V_134 * V_135 = V_101 -> V_136 ;
T_7 * V_137 = ( T_7 * ) V_99 ;
T_4 V_83 ;
if ( V_135 -> exp ) {
V_83 = V_138 + V_135 -> V_83 ;
* V_99 = F_54 ( ( V_139 << 24 ) | ( V_83 << 16 ) |
V_140 ) ;
V_137 += V_138 ;
} else {
V_83 = V_141 + V_135 -> V_83 ;
* V_137 ++ = V_142 ;
* V_137 ++ = V_83 ;
}
memcpy ( V_137 , V_135 -> V_143 , V_135 -> V_83 ) ;
if ( ( V_83 & 3 ) == 2 ) {
V_137 [ V_135 -> V_83 ] = V_104 ;
V_137 [ V_135 -> V_83 + 1 ] = V_104 ;
}
V_99 += ( V_83 + 3 ) >> 2 ;
}
}
static unsigned int F_56 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_144 * * V_145 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_146 = V_147 ;
struct V_148 * V_149 = V_8 -> V_150 ;
#ifdef F_57
* V_145 = V_8 -> V_151 -> V_152 ( V_2 , V_2 ) ;
if ( * V_145 ) {
V_101 -> V_102 |= V_103 ;
V_146 -= V_153 ;
}
#else
* V_145 = NULL ;
#endif
V_101 -> V_21 = F_13 ( V_2 ) ;
V_146 -= V_154 ;
if ( F_55 ( F_9 ( V_2 ) -> V_72 . V_155 && ! * V_145 ) ) {
V_101 -> V_102 |= V_110 ;
V_101 -> V_116 = F_58 ( V_4 ) + V_8 -> V_156 ;
V_101 -> V_117 = V_8 -> V_16 . V_157 ;
V_146 -= V_158 ;
}
if ( F_55 ( F_9 ( V_2 ) -> V_72 . V_159 ) ) {
V_101 -> V_121 = V_8 -> V_16 . V_18 ;
V_101 -> V_102 |= V_118 ;
V_146 -= V_160 ;
}
if ( F_55 ( F_9 ( V_2 ) -> V_72 . V_161 ) ) {
V_101 -> V_102 |= V_111 ;
if ( F_53 ( ! ( V_110 & V_101 -> V_102 ) ) )
V_146 -= V_162 ;
}
if ( V_149 && V_149 -> V_163 . V_83 >= 0 ) {
T_4 V_164 = V_149 -> V_163 . V_83 ;
V_164 += V_149 -> V_163 . exp ? V_138 :
V_141 ;
V_164 = ( V_164 + 3 ) & ~ 3U ;
if ( V_146 >= V_164 ) {
V_101 -> V_102 |= V_133 ;
V_101 -> V_136 = & V_149 -> V_163 ;
V_146 -= V_164 ;
V_8 -> V_165 = 1 ;
V_8 -> V_166 = V_149 -> V_163 . exp ? 1 : 0 ;
}
}
return V_147 - V_146 ;
}
static unsigned int F_59 ( struct V_76 * V_77 ,
unsigned int V_21 , struct V_3 * V_4 ,
struct V_100 * V_101 ,
const struct V_144 * V_145 ,
struct V_134 * V_135 )
{
struct V_167 * V_168 = F_45 ( V_77 ) ;
unsigned int V_146 = V_147 ;
#ifdef F_57
if ( V_145 ) {
V_101 -> V_102 |= V_103 ;
V_146 -= V_153 ;
V_168 -> V_169 &= ! V_168 -> V_170 ;
}
#endif
V_101 -> V_21 = V_21 ;
V_146 -= V_154 ;
if ( F_55 ( V_168 -> V_17 ) ) {
V_101 -> V_121 = V_168 -> V_18 ;
V_101 -> V_102 |= V_118 ;
V_146 -= V_160 ;
}
if ( F_55 ( V_168 -> V_169 ) ) {
V_101 -> V_102 |= V_110 ;
V_101 -> V_116 = F_58 ( V_4 ) + F_60 ( V_77 ) -> V_171 ;
V_101 -> V_117 = V_77 -> V_157 ;
V_146 -= V_158 ;
}
if ( F_55 ( V_168 -> V_170 ) ) {
V_101 -> V_102 |= V_111 ;
if ( F_53 ( ! V_168 -> V_169 ) )
V_146 -= V_162 ;
}
if ( V_135 != NULL && V_135 -> V_83 >= 0 ) {
T_4 V_164 = V_135 -> V_83 ;
V_164 += V_135 -> exp ? V_138 :
V_141 ;
V_164 = ( V_164 + 3 ) & ~ 3U ;
if ( V_146 >= V_164 ) {
V_101 -> V_102 |= V_133 ;
V_101 -> V_136 = V_135 ;
V_146 -= V_164 ;
}
}
return V_147 - V_146 ;
}
static unsigned int F_61 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_144 * * V_145 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_172 = 0 ;
unsigned int V_173 ;
V_101 -> V_102 = 0 ;
#ifdef F_57
* V_145 = V_8 -> V_151 -> V_152 ( V_2 , V_2 ) ;
if ( F_53 ( * V_145 ) ) {
V_101 -> V_102 |= V_103 ;
V_172 += V_153 ;
}
#else
* V_145 = NULL ;
#endif
if ( F_55 ( V_8 -> V_16 . V_169 ) ) {
V_101 -> V_102 |= V_110 ;
V_101 -> V_116 = V_4 ? F_58 ( V_4 ) + V_8 -> V_156 : 0 ;
V_101 -> V_117 = V_8 -> V_16 . V_157 ;
V_172 += V_158 ;
}
V_173 = V_8 -> V_16 . V_174 + V_8 -> V_16 . V_125 ;
if ( F_53 ( V_173 ) ) {
const unsigned int V_146 = V_147 - V_172 ;
V_101 -> V_122 =
F_31 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_172 += V_175 +
V_101 -> V_122 * V_131 ;
}
return V_172 ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_176 ) &
( V_177 | V_178 | V_179 |
V_180 | V_181 ) ) {
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_182 > V_8 -> V_183 &&
V_8 -> V_27 > F_23 ( V_8 ) )
F_63 ( V_2 ) ;
F_64 ( V_2 , F_65 ( V_2 ) , V_8 -> V_184 ,
0 , V_185 ) ;
}
}
static void F_66 ( unsigned long V_186 )
{
struct V_187 * V_188 = (struct V_187 * ) V_186 ;
F_67 ( V_189 ) ;
unsigned long V_90 ;
struct V_190 * V_191 , * V_192 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_68 ( V_90 ) ;
F_69 ( & V_188 -> V_193 , & V_189 ) ;
F_70 ( V_90 ) ;
F_71 (q, n, &list) {
V_8 = F_72 ( V_191 , struct V_7 , V_194 ) ;
F_73 ( & V_8 -> V_194 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_74 () ;
F_75 ( V_195 , & V_2 -> V_196 ) ;
if ( ! V_2 -> V_197 . V_198 &&
F_76 ( V_199 , & V_2 -> V_196 ) ) {
F_77 ( V_2 ) ;
if ( ! F_78 ( V_2 ) ) {
F_75 ( V_199 , & V_2 -> V_196 ) ;
F_62 ( V_2 ) ;
}
F_79 ( V_2 ) ;
}
F_80 ( V_2 ) ;
}
}
void F_81 ( struct V_1 * V_2 )
{
unsigned long V_90 , V_200 ;
do {
V_90 = V_2 -> V_196 ;
if ( ! ( V_90 & V_201 ) )
return;
V_200 = V_90 & ~ V_201 ;
} while ( F_82 ( & V_2 -> V_196 , V_90 , V_200 ) != V_90 );
if ( V_90 & V_202 )
F_62 ( V_2 ) ;
F_83 ( V_2 ) ;
if ( V_90 & V_203 ) {
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
}
if ( V_90 & V_204 ) {
F_86 ( V_2 ) ;
F_85 ( V_2 ) ;
}
if ( V_90 & V_205 ) {
F_2 ( V_2 ) -> V_206 -> V_207 ( V_2 ) ;
F_85 ( V_2 ) ;
}
}
void T_9 F_87 ( void )
{
int V_208 ;
F_88 (i) {
struct V_187 * V_188 = & F_89 ( V_187 , V_208 ) ;
F_90 ( & V_188 -> V_193 ) ;
F_91 ( & V_188 -> V_209 ,
F_66 ,
( unsigned long ) V_188 ) ;
}
}
void F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_90 , V_210 , V_211 ;
F_93 ( F_94 ( V_4 -> V_212 - 1 , & V_2 -> V_213 ) ) ;
if ( F_95 ( & V_2 -> V_213 ) >= F_96 ( 1 ) && F_97 () == V_214 )
goto V_215;
for ( V_211 = F_98 ( V_2 -> V_196 ) ; ; V_211 = V_210 ) {
struct V_187 * V_188 ;
bool V_216 ;
if ( ! ( V_211 & V_217 ) || ( V_211 & V_218 ) )
goto V_215;
V_210 = ( V_211 & ~ V_217 ) | V_218 | V_202 ;
V_210 = F_82 ( & V_2 -> V_196 , V_211 , V_210 ) ;
if ( V_210 != V_211 )
continue;
F_68 ( V_90 ) ;
V_188 = F_99 ( & V_187 ) ;
V_216 = F_100 ( & V_188 -> V_193 ) ;
F_101 ( & V_8 -> V_194 , & V_188 -> V_193 ) ;
if ( V_216 )
F_102 ( & V_188 -> V_209 ) ;
F_70 ( V_90 ) ;
return;
}
V_215:
F_80 ( V_2 ) ;
}
enum V_219 F_103 ( struct V_220 * V_221 )
{
struct V_7 * V_8 = F_104 ( V_221 , struct V_7 , V_222 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_210 , V_211 ;
for ( V_211 = F_98 ( V_2 -> V_196 ) ; ; V_211 = V_210 ) {
struct V_187 * V_188 ;
bool V_216 ;
if ( V_211 & V_218 )
break;
V_210 = ( V_211 & ~ V_217 ) | V_218 | V_202 ;
V_210 = F_82 ( & V_2 -> V_196 , V_211 , V_210 ) ;
if ( V_210 != V_211 )
continue;
if ( ! F_105 ( & V_2 -> V_213 ) )
break;
V_188 = F_99 ( & V_187 ) ;
V_216 = F_100 ( & V_188 -> V_193 ) ;
F_101 ( & V_8 -> V_194 , & V_188 -> V_193 ) ;
if ( V_216 )
F_102 ( & V_188 -> V_209 ) ;
break;
}
return V_223 ;
}
static bool F_106 ( const struct V_1 * V_2 )
{
return F_107 ( & V_2 -> V_224 ) == V_225 ;
}
static void F_108 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_10 V_226 ;
T_4 V_227 ;
if ( ! F_106 ( V_2 ) )
return;
V_227 = V_2 -> V_228 ;
if ( ! V_227 || V_227 == ~ 0U )
return;
V_226 = ( T_10 ) V_4 -> V_83 * V_229 ;
F_109 ( V_226 , V_227 ) ;
F_110 ( & F_3 ( V_2 ) -> V_222 ,
F_111 ( F_112 () , V_226 ) ,
V_230 ) ;
}
static int F_113 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_231 ,
T_11 V_232 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_233 * V_234 ;
struct V_7 * V_8 ;
struct V_235 * V_236 ;
struct V_100 V_101 ;
unsigned int V_237 , V_238 ;
struct V_144 * V_145 ;
struct V_78 * V_79 ;
int V_239 ;
F_114 ( ! V_4 || ! F_6 ( V_4 ) ) ;
V_8 = F_3 ( V_2 ) ;
V_4 -> V_240 = V_8 -> V_241 ;
if ( V_231 ) {
F_5 ( V_4 ) -> V_242 . V_243 = F_5 ( V_4 ) -> V_12
- V_8 -> V_97 ;
F_115 ( V_2 , V_4 ) ;
if ( F_53 ( F_116 ( V_4 ) ) )
V_4 = F_117 ( V_4 , V_232 ) ;
else
V_4 = F_118 ( V_4 , V_232 ) ;
if ( F_53 ( ! V_4 ) )
return - V_244 ;
}
V_234 = F_119 ( V_2 ) ;
V_236 = F_5 ( V_4 ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
if ( F_53 ( V_236 -> V_65 & V_95 ) )
V_237 = F_56 ( V_2 , V_4 , & V_101 , & V_145 ) ;
else
V_237 = F_61 ( V_2 , V_4 , & V_101 ,
& V_145 ) ;
V_238 = V_237 + sizeof( struct V_78 ) ;
V_4 -> V_245 = F_120 ( V_2 ) < F_96 ( 1 ) ;
V_4 -> V_246 = 0 ;
F_121 ( V_4 , V_238 ) ;
F_122 ( V_4 ) ;
F_123 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_247 = F_124 ( V_4 ) ? V_248 : F_92 ;
F_125 ( V_4 , V_2 ) ;
F_126 ( V_4 -> V_212 , & V_2 -> V_213 ) ;
F_127 ( V_4 , V_2 -> V_249 ) ;
V_79 = (struct V_78 * ) V_4 -> V_186 ;
V_79 -> V_250 = V_234 -> V_251 ;
V_79 -> V_252 = V_234 -> V_253 ;
V_79 -> V_84 = F_54 ( V_236 -> V_84 ) ;
V_79 -> V_254 = F_54 ( V_8 -> V_61 ) ;
* ( ( ( V_255 * ) V_79 ) + 6 ) = F_128 ( ( ( V_238 >> 2 ) << 12 ) |
V_236 -> V_65 ) ;
V_79 -> V_256 = 0 ;
V_79 -> V_257 = 0 ;
if ( F_53 ( F_51 ( V_8 ) && F_11 ( V_236 -> V_84 , V_8 -> V_98 ) ) ) {
if ( F_11 ( V_8 -> V_98 , V_236 -> V_84 + 0x10000 ) ) {
V_79 -> V_257 = F_128 ( V_8 -> V_98 - V_236 -> V_84 ) ;
V_79 -> V_258 = 1 ;
} else if ( F_129 ( V_236 -> V_84 + 0xFFFF , V_8 -> V_11 ) ) {
V_79 -> V_257 = F_128 ( 0xFFFF ) ;
V_79 -> V_258 = 1 ;
}
}
F_52 ( ( T_8 * ) ( V_79 + 1 ) , V_8 , & V_101 ) ;
F_47 ( V_4 ) -> V_87 = V_2 -> V_259 ;
if ( F_55 ( ! ( V_236 -> V_65 & V_95 ) ) ) {
V_79 -> V_260 = F_128 ( F_32 ( V_2 ) ) ;
F_46 ( V_2 , V_4 , V_79 , V_238 ) ;
} else {
V_79 -> V_260 = F_128 ( F_20 ( V_8 -> V_46 , 65535U ) ) ;
}
#ifdef F_57
if ( V_145 ) {
F_130 ( V_2 , V_261 ) ;
V_8 -> V_151 -> V_262 ( V_101 . V_107 ,
V_145 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_206 -> V_263 ( V_2 , V_4 ) ;
if ( F_55 ( V_236 -> V_65 & V_264 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_83 != V_238 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_265 += F_6 ( V_4 ) ;
F_108 ( V_2 , V_4 ) ;
}
if ( F_129 ( V_236 -> V_12 , V_8 -> V_11 ) || V_236 -> V_84 == V_236 -> V_12 )
F_131 ( F_9 ( V_2 ) , V_266 ,
F_6 ( V_4 ) ) ;
V_8 -> V_267 += F_6 ( V_4 ) ;
F_47 ( V_4 ) -> V_268 = F_6 ( V_4 ) ;
F_47 ( V_4 ) -> V_269 = F_132 ( V_4 ) ;
V_4 -> V_270 = 0 ;
memset ( V_4 -> V_271 , 0 , F_21 ( sizeof( struct V_272 ) ,
sizeof( struct V_273 ) ) ) ;
V_239 = V_6 -> V_206 -> V_274 ( V_2 , V_4 , & V_234 -> V_275 . V_276 ) ;
if ( F_55 ( V_239 <= 0 ) )
return V_239 ;
F_133 ( V_2 ) ;
return F_134 ( V_239 ) ;
}
static void F_135 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_277 = F_5 ( V_4 ) -> V_12 ;
F_136 ( V_4 ) ;
F_137 ( V_2 , V_4 ) ;
V_2 -> V_278 += V_4 -> V_212 ;
F_138 ( V_2 , V_4 -> V_212 ) ;
}
static void F_139 ( struct V_3 * V_4 , unsigned int V_279 )
{
if ( V_4 -> V_83 <= V_279 || V_4 -> V_91 == V_280 ) {
F_50 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_281 = 0 ;
} else {
F_50 ( V_4 , F_140 ( V_4 -> V_83 , V_279 ) ) ;
F_5 ( V_4 ) -> V_281 = V_279 ;
}
}
static void F_141 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_282 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_283 || F_142 ( V_8 ) )
return;
if ( F_129 ( F_143 ( V_8 ) , F_5 ( V_4 ) -> V_84 ) )
V_8 -> V_284 -= V_282 ;
}
static void F_144 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_282 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_282 ;
if ( F_5 ( V_4 ) -> V_94 & V_285 )
V_8 -> V_283 -= V_282 ;
if ( F_5 ( V_4 ) -> V_94 & V_286 )
V_8 -> V_183 -= V_282 ;
if ( F_5 ( V_4 ) -> V_94 & V_287 )
V_8 -> V_182 -= V_282 ;
if ( F_142 ( V_8 ) && V_282 > 0 )
V_8 -> V_283 -= F_31 ( T_4 , V_8 -> V_283 , V_282 ) ;
F_141 ( V_2 , V_4 , V_282 ) ;
if ( V_8 -> V_288 &&
F_11 ( F_5 ( V_4 ) -> V_84 , F_5 ( V_8 -> V_288 ) -> V_84 ) &&
( F_145 ( V_8 ) || ( F_5 ( V_4 ) -> V_94 & V_285 ) ) )
V_8 -> V_289 -= V_282 ;
F_146 ( V_8 ) ;
}
static bool F_147 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_290 ||
( F_47 ( V_4 ) -> V_291 & V_292 ) ;
}
static void F_148 ( struct V_3 * V_4 , struct V_3 * V_293 )
{
struct V_294 * V_295 = F_47 ( V_4 ) ;
if ( F_53 ( F_147 ( V_4 ) ) &&
! F_11 ( V_295 -> V_296 , F_5 ( V_293 ) -> V_84 ) ) {
struct V_294 * V_297 = F_47 ( V_293 ) ;
T_7 V_298 = V_295 -> V_291 & V_292 ;
V_295 -> V_291 &= ~ V_298 ;
V_297 -> V_291 |= V_298 ;
F_149 ( V_295 -> V_296 , V_297 -> V_296 ) ;
F_5 ( V_293 ) -> V_290 = F_5 ( V_4 ) -> V_290 ;
F_5 ( V_4 ) -> V_290 = 0 ;
}
}
static void F_150 ( struct V_3 * V_4 , struct V_3 * V_293 )
{
F_5 ( V_293 ) -> V_299 = F_5 ( V_4 ) -> V_299 ;
F_5 ( V_4 ) -> V_299 = 0 ;
}
int F_151 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_83 ,
unsigned int V_279 , T_11 V_300 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_301 ;
int V_302 , V_303 ;
int V_304 ;
T_7 V_90 ;
if ( F_93 ( V_83 > V_4 -> V_83 ) )
return - V_305 ;
V_302 = F_152 ( V_4 ) - V_83 ;
if ( V_302 < 0 )
V_302 = 0 ;
if ( F_153 ( V_4 , V_300 ) )
return - V_306 ;
V_301 = F_154 ( V_2 , V_302 , V_300 , true ) ;
if ( ! V_301 )
return - V_306 ;
V_2 -> V_278 += V_301 -> V_212 ;
F_138 ( V_2 , V_301 -> V_212 ) ;
V_304 = V_4 -> V_83 - V_83 - V_302 ;
V_301 -> V_212 += V_304 ;
V_4 -> V_212 -= V_304 ;
F_5 ( V_301 ) -> V_84 = F_5 ( V_4 ) -> V_84 + V_83 ;
F_5 ( V_301 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_301 ) -> V_84 ;
V_90 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_90 & ~ ( V_96 | V_307 ) ;
F_5 ( V_301 ) -> V_65 = V_90 ;
F_5 ( V_301 ) -> V_94 = F_5 ( V_4 ) -> V_94 ;
F_150 ( V_4 , V_301 ) ;
if ( ! F_47 ( V_4 ) -> V_308 && V_4 -> V_91 != V_92 ) {
V_301 -> V_93 = F_155 ( V_4 -> V_186 + V_83 ,
F_156 ( V_301 , V_302 ) ,
V_302 , 0 ) ;
F_157 ( V_4 , V_83 ) ;
V_4 -> V_93 = F_158 ( V_4 -> V_93 , V_301 -> V_93 , V_83 ) ;
} else {
V_4 -> V_91 = V_92 ;
F_159 ( V_4 , V_301 , V_83 ) ;
}
V_301 -> V_91 = V_4 -> V_91 ;
V_301 -> V_270 = V_4 -> V_270 ;
F_148 ( V_4 , V_301 ) ;
V_303 = F_6 ( V_4 ) ;
F_139 ( V_4 , V_279 ) ;
F_139 ( V_301 , V_279 ) ;
F_5 ( V_301 ) -> V_242 = F_5 ( V_4 ) -> V_242 ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_301 ) -> V_12 ) ) {
int V_309 = V_303 - F_6 ( V_4 ) -
F_6 ( V_301 ) ;
if ( V_309 )
F_144 ( V_2 , V_4 , V_309 ) ;
}
F_136 ( V_301 ) ;
F_160 ( V_4 , V_301 , V_2 ) ;
return 0 ;
}
static int F_161 ( struct V_3 * V_4 , int V_83 )
{
struct V_294 * V_295 ;
int V_208 , V_310 , V_311 ;
V_311 = F_31 ( int , V_83 , F_152 ( V_4 ) ) ;
if ( V_311 ) {
F_162 ( V_4 , V_311 ) ;
V_83 -= V_311 ;
if ( ! V_83 )
return 0 ;
}
V_311 = V_83 ;
V_310 = 0 ;
V_295 = F_47 ( V_4 ) ;
for ( V_208 = 0 ; V_208 < V_295 -> V_308 ; V_208 ++ ) {
int V_172 = F_163 ( & V_295 -> V_312 [ V_208 ] ) ;
if ( V_172 <= V_311 ) {
F_164 ( V_4 , V_208 ) ;
V_311 -= V_172 ;
} else {
V_295 -> V_312 [ V_310 ] = V_295 -> V_312 [ V_208 ] ;
if ( V_311 ) {
V_295 -> V_312 [ V_310 ] . V_313 += V_311 ;
F_165 ( & V_295 -> V_312 [ V_310 ] , V_311 ) ;
V_311 = 0 ;
}
V_310 ++ ;
}
}
V_295 -> V_308 = V_310 ;
V_4 -> V_314 -= V_83 ;
V_4 -> V_83 = V_4 -> V_314 ;
return V_83 ;
}
int F_166 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_83 )
{
T_4 V_315 ;
if ( F_153 ( V_4 , V_185 ) )
return - V_306 ;
V_315 = F_161 ( V_4 , V_83 ) ;
F_5 ( V_4 ) -> V_84 += V_83 ;
V_4 -> V_91 = V_92 ;
if ( V_315 ) {
V_4 -> V_212 -= V_315 ;
V_2 -> V_278 -= V_315 ;
F_167 ( V_2 , V_315 ) ;
F_168 ( V_2 , V_316 ) ;
}
if ( F_6 ( V_4 ) > 1 )
F_139 ( V_4 , F_132 ( V_4 ) ) ;
return 0 ;
}
static inline int F_169 ( struct V_1 * V_2 , int V_317 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_279 ;
V_279 = V_317 - V_6 -> V_206 -> V_318 - sizeof( struct V_78 ) ;
if ( V_6 -> V_206 -> V_319 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_170 ( V_20 ) )
V_279 -= V_6 -> V_206 -> V_319 ;
}
if ( V_279 > V_8 -> V_16 . V_320 )
V_279 = V_8 -> V_16 . V_320 ;
V_279 -= V_6 -> V_321 ;
if ( V_279 < 48 )
V_279 = 48 ;
return V_279 ;
}
int F_171 ( struct V_1 * V_2 , int V_317 )
{
return F_169 ( V_2 , V_317 ) -
( F_3 ( V_2 ) -> V_82 - sizeof( struct V_78 ) ) ;
}
int F_172 ( struct V_1 * V_2 , int V_21 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_322 ;
V_322 = V_21 +
V_8 -> V_82 +
V_6 -> V_321 +
V_6 -> V_206 -> V_318 ;
if ( V_6 -> V_206 -> V_319 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_170 ( V_20 ) )
V_322 += V_6 -> V_206 -> V_319 ;
}
return V_322 ;
}
void F_173 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_323 * V_323 = F_9 ( V_2 ) ;
V_6 -> V_324 . V_325 = V_323 -> V_72 . V_326 > 1 ;
V_6 -> V_324 . V_327 = V_8 -> V_16 . V_320 + sizeof( struct V_78 ) +
V_6 -> V_206 -> V_318 ;
V_6 -> V_324 . V_328 = F_172 ( V_2 , V_323 -> V_72 . V_329 ) ;
V_6 -> V_324 . V_330 = 0 ;
if ( V_6 -> V_324 . V_325 )
V_6 -> V_324 . V_331 = V_32 ;
}
unsigned int F_174 ( struct V_1 * V_2 , T_4 V_317 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_279 ;
if ( V_6 -> V_324 . V_327 > V_317 )
V_6 -> V_324 . V_327 = V_317 ;
V_279 = F_171 ( V_2 , V_317 ) ;
V_279 = F_175 ( V_8 , V_279 ) ;
V_6 -> V_332 = V_317 ;
if ( V_6 -> V_324 . V_325 )
V_279 = F_20 ( V_279 , F_171 ( V_2 , V_6 -> V_324 . V_328 ) ) ;
V_8 -> V_333 = V_279 ;
return V_279 ;
}
unsigned int F_65 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_19 * V_20 = F_14 ( V_2 ) ;
T_4 V_279 ;
unsigned int V_334 ;
struct V_100 V_101 ;
struct V_144 * V_145 ;
V_279 = V_8 -> V_333 ;
if ( V_20 ) {
T_4 V_322 = F_176 ( V_20 ) ;
if ( V_322 != F_2 ( V_2 ) -> V_332 )
V_279 = F_174 ( V_2 , V_322 ) ;
}
V_334 = F_61 ( V_2 , NULL , & V_101 , & V_145 ) +
sizeof( struct V_78 ) ;
if ( V_334 != V_8 -> V_82 ) {
int V_24 = ( int ) V_334 - V_8 -> V_82 ;
V_279 -= V_24 ;
}
return V_279 ;
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_335 == V_336 &&
V_2 -> V_337 && ! F_76 ( V_338 , & V_2 -> V_337 -> V_90 ) ) {
T_4 V_339 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_340 = F_21 ( V_8 -> V_33 , V_339 ) ;
if ( V_340 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_340 ) >> 1 ;
}
V_8 -> V_33 = 0 ;
}
V_8 -> V_31 = V_32 ;
}
static void F_178 ( struct V_1 * V_2 , bool V_341 )
{
const struct V_342 * V_343 = F_2 ( V_2 ) -> V_344 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_97 , V_8 -> V_345 ) ||
V_8 -> V_10 > V_8 -> V_346 ) {
V_8 -> V_346 = V_8 -> V_10 ;
V_8 -> V_345 = V_8 -> V_11 ;
V_8 -> V_341 = V_341 ;
}
if ( F_179 ( V_2 ) ) {
V_8 -> V_33 = 0 ;
V_8 -> V_31 = V_32 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_33 )
V_8 -> V_33 = V_8 -> V_10 ;
if ( V_347 &&
( T_3 ) ( V_32 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 &&
! V_343 -> V_348 )
F_177 ( V_2 ) ;
if ( ! F_180 ( V_2 ) && V_2 -> V_337 &&
F_76 ( V_338 , & V_2 -> V_337 -> V_90 ) &&
( 1 << V_2 -> V_176 ) & ( V_177 | V_180 ) )
F_181 ( V_2 , V_349 ) ;
}
}
static bool F_182 ( const struct V_7 * V_8 )
{
return F_129 ( V_8 -> V_350 , V_8 -> V_97 ) &&
! F_129 ( V_8 -> V_350 , V_8 -> V_11 ) ;
}
static void F_183 ( struct V_7 * V_8 , unsigned int V_279 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_83 < F_6 ( V_4 ) * V_279 )
V_8 -> V_350 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_184 ( bool V_351 , const struct V_7 * V_8 ,
int V_184 )
{
return V_351 &&
( ( V_184 & V_352 ) ||
( ! V_184 && V_8 -> V_10 && F_182 ( V_8 ) ) ) ;
}
T_4 F_185 ( const struct V_1 * V_2 , unsigned int V_279 ,
int V_353 )
{
T_4 V_354 , V_355 ;
V_354 = F_20 ( V_2 -> V_228 >> 10 ,
V_2 -> V_356 - 1 - V_357 ) ;
V_355 = F_30 ( T_4 , V_354 / V_279 , V_353 ) ;
return F_31 ( T_4 , V_355 , V_2 -> V_358 ) ;
}
static T_4 F_186 ( struct V_1 * V_2 , unsigned int V_279 )
{
const struct V_342 * V_343 = F_2 ( V_2 ) -> V_344 ;
T_4 V_359 = V_343 -> V_360 ? V_343 -> V_360 ( V_2 ) : 0 ;
return V_359 ? :
F_185 ( V_2 , V_279 , V_361 ) ;
}
static unsigned int F_187 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_279 ,
unsigned int V_362 ,
int V_184 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_351 , V_363 , V_260 , V_364 ;
V_260 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_84 ;
V_364 = V_279 * V_362 ;
if ( F_55 ( V_364 <= V_260 && V_4 != F_188 ( V_2 ) ) )
return V_364 ;
V_363 = F_20 ( V_4 -> V_83 , V_260 ) ;
if ( V_364 <= V_363 )
return V_364 ;
V_351 = V_363 % V_279 ;
if ( F_184 ( V_351 != 0 , V_8 , V_184 ) )
return V_363 - V_351 ;
return V_363 ;
}
static inline unsigned int F_189 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_243 , V_26 , V_365 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_96 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_243 = F_23 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_243 >= V_26 )
return 0 ;
V_365 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_365 , V_26 - V_243 ) ;
}
static int F_190 ( struct V_3 * V_4 , unsigned int V_279 )
{
int V_359 = F_6 ( V_4 ) ;
if ( ! V_359 || ( V_359 > 1 && F_132 ( V_4 ) != V_279 ) ) {
F_139 ( V_4 , V_279 ) ;
V_359 = F_6 ( V_4 ) ;
}
return V_359 ;
}
static inline bool F_191 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_366 , int V_184 )
{
if ( V_184 & V_367 )
return true ;
if ( F_51 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_96 ) )
return true ;
if ( ! F_184 ( V_4 -> V_83 < V_366 , V_8 , V_184 ) )
return true ;
return false ;
}
static bool F_192 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_366 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_83 > V_366 )
V_12 = F_5 ( V_4 ) -> V_84 + V_366 ;
return ! F_129 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_193 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_366 , int V_184 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_368 ;
F_190 ( V_4 , V_366 ) ;
if ( ! F_191 ( V_8 , V_4 , V_366 , V_184 ) )
return 0 ;
V_368 = F_189 ( V_8 , V_4 ) ;
if ( V_368 && ! F_192 ( V_8 , V_4 , V_366 ) )
V_368 = 0 ;
return V_368 ;
}
bool F_194 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_180 ( V_2 ) ;
return V_4 &&
F_193 ( V_2 , V_4 , F_65 ( V_2 ) ,
( F_195 ( V_2 , V_4 ) ?
V_8 -> V_184 : V_367 ) ) ;
}
static int F_196 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_83 ,
unsigned int V_279 , T_11 V_300 )
{
struct V_3 * V_301 ;
int V_304 = V_4 -> V_83 - V_83 ;
T_7 V_90 ;
if ( V_4 -> V_83 != V_4 -> V_314 )
return F_151 ( V_2 , V_4 , V_83 , V_279 , V_300 ) ;
V_301 = F_154 ( V_2 , 0 , V_300 , true ) ;
if ( F_53 ( ! V_301 ) )
return - V_306 ;
V_2 -> V_278 += V_301 -> V_212 ;
F_138 ( V_2 , V_301 -> V_212 ) ;
V_301 -> V_212 += V_304 ;
V_4 -> V_212 -= V_304 ;
F_5 ( V_301 ) -> V_84 = F_5 ( V_4 ) -> V_84 + V_83 ;
F_5 ( V_301 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_301 ) -> V_84 ;
V_90 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_90 & ~ ( V_96 | V_307 ) ;
F_5 ( V_301 ) -> V_65 = V_90 ;
F_5 ( V_301 ) -> V_94 = 0 ;
F_150 ( V_4 , V_301 ) ;
V_301 -> V_91 = V_4 -> V_91 = V_92 ;
F_159 ( V_4 , V_301 , V_83 ) ;
F_148 ( V_4 , V_301 ) ;
F_139 ( V_4 , V_279 ) ;
F_139 ( V_301 , V_279 ) ;
F_136 ( V_301 ) ;
F_160 ( V_4 , V_301 , V_2 ) ;
return 0 ;
}
static bool F_197 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_341 , T_4 V_362 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_369 , V_370 , V_371 , V_372 , V_243 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_193 ;
int V_373 ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
goto V_374;
if ( V_6 -> V_335 >= V_375 )
goto V_374;
if ( ( T_3 ) ( V_32 - V_8 -> V_36 ) > 0 )
goto V_374;
V_243 = F_23 ( V_8 ) ;
F_114 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_243 ) ) ;
V_370 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_84 ;
V_371 = ( V_8 -> V_27 - V_243 ) * V_8 -> V_333 ;
V_372 = F_20 ( V_370 , V_371 ) ;
if ( V_372 >= V_362 * V_8 -> V_333 )
goto V_374;
if ( ( V_4 != F_188 ( V_2 ) ) && ( V_372 >= V_4 -> V_83 ) )
goto V_374;
V_373 = F_198 ( V_376 ) ;
if ( V_373 ) {
T_4 V_377 = F_20 ( V_8 -> V_378 , V_8 -> V_27 * V_8 -> V_333 ) ;
V_377 /= V_373 ;
if ( V_372 >= V_377 )
goto V_374;
} else {
if ( V_372 > F_199 ( V_8 ) * V_8 -> V_333 )
goto V_374;
}
V_193 = F_200 ( V_2 ) ;
V_369 = F_201 ( V_8 -> V_241 , V_193 -> V_240 ) ;
if ( V_369 < ( V_8 -> V_379 >> 4 ) )
goto V_374;
if ( V_371 < V_370 && V_371 <= V_4 -> V_83 )
* V_341 = true ;
return true ;
V_374:
return false ;
}
static inline void F_202 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_323 * V_323 = F_9 ( V_2 ) ;
T_4 V_380 ;
T_3 V_24 ;
V_380 = V_323 -> V_72 . V_381 ;
V_24 = V_32 - V_6 -> V_324 . V_331 ;
if ( F_53 ( V_24 >= V_380 * V_382 ) ) {
int V_21 = F_65 ( V_2 ) ;
V_6 -> V_324 . V_330 = 0 ;
V_6 -> V_324 . V_327 = V_8 -> V_16 . V_320 +
sizeof( struct V_78 ) +
V_6 -> V_206 -> V_318 ;
V_6 -> V_324 . V_328 = F_172 ( V_2 , V_21 ) ;
V_6 -> V_324 . V_331 = V_32 ;
}
}
static int F_203 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 , * V_383 , * V_384 ;
struct V_323 * V_323 = F_9 ( V_2 ) ;
int V_330 ;
int V_385 ;
int V_386 , V_83 ;
int V_279 ;
int V_380 ;
if ( F_55 ( ! V_6 -> V_324 . V_325 ||
V_6 -> V_324 . V_330 ||
F_2 ( V_2 ) -> V_335 != V_336 ||
V_8 -> V_27 < 11 ||
V_8 -> V_16 . V_174 || V_8 -> V_16 . V_125 ) )
return - 1 ;
V_279 = F_65 ( V_2 ) ;
V_330 = F_171 ( V_2 , ( V_6 -> V_324 . V_327 +
V_6 -> V_324 . V_328 ) >> 1 ) ;
V_385 = V_330 + ( V_8 -> V_387 + 1 ) * V_8 -> V_333 ;
V_380 = V_6 -> V_324 . V_327 - V_6 -> V_324 . V_328 ;
if ( V_330 > F_171 ( V_2 , V_6 -> V_324 . V_327 ) ||
V_380 < V_323 -> V_72 . V_388 ) {
F_202 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_277 - V_8 -> V_11 < V_385 )
return - 1 ;
if ( V_8 -> V_378 < V_385 )
return - 1 ;
if ( F_129 ( V_8 -> V_11 + V_385 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_383 = F_154 ( V_2 , V_330 , V_185 , false ) ;
if ( ! V_383 )
return - 1 ;
V_2 -> V_278 += V_383 -> V_212 ;
F_138 ( V_2 , V_383 -> V_212 ) ;
V_4 = F_180 ( V_2 ) ;
F_5 ( V_383 ) -> V_84 = F_5 ( V_4 ) -> V_84 ;
F_5 ( V_383 ) -> V_12 = F_5 ( V_4 ) -> V_84 + V_330 ;
F_5 ( V_383 ) -> V_65 = V_264 ;
F_5 ( V_383 ) -> V_94 = 0 ;
V_383 -> V_93 = 0 ;
V_383 -> V_91 = V_4 -> V_91 ;
F_204 ( V_383 , V_4 , V_2 ) ;
V_83 = 0 ;
F_205 (skb, next, sk) {
V_386 = F_31 ( int , V_4 -> V_83 , V_330 - V_83 ) ;
if ( V_383 -> V_91 ) {
F_206 ( V_4 , 0 , F_156 ( V_383 , V_386 ) , V_386 ) ;
} else {
T_12 V_93 = F_207 ( V_4 , 0 ,
F_156 ( V_383 , V_386 ) ,
V_386 , 0 ) ;
V_383 -> V_93 = F_208 ( V_383 -> V_93 , V_93 , V_83 ) ;
}
if ( V_4 -> V_83 <= V_386 ) {
F_5 ( V_383 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_209 ( V_4 , V_2 ) ;
F_210 ( V_2 , V_4 ) ;
} else {
F_5 ( V_383 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_96 | V_307 ) ;
if ( ! F_47 ( V_4 ) -> V_308 ) {
F_211 ( V_4 , V_386 ) ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_212 ( V_4 -> V_186 ,
V_4 -> V_83 , 0 ) ;
} else {
F_161 ( V_4 , V_386 ) ;
F_139 ( V_4 , V_279 ) ;
}
F_5 ( V_4 ) -> V_84 += V_386 ;
}
V_83 += V_386 ;
if ( V_83 >= V_330 )
break;
}
F_190 ( V_383 , V_383 -> V_83 ) ;
if ( ! F_113 ( V_2 , V_383 , 1 , V_185 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_383 ) ;
V_6 -> V_324 . V_330 = F_172 ( V_2 , V_383 -> V_83 ) ;
V_8 -> V_389 . V_390 = F_5 ( V_383 ) -> V_84 ;
V_8 -> V_389 . V_391 = F_5 ( V_383 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_213 ( const struct V_1 * V_2 )
{
return F_106 ( V_2 ) &&
F_214 ( & F_3 ( V_2 ) -> V_222 ) ;
}
static bool F_215 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_392 )
{
unsigned int V_372 ;
V_372 = F_21 ( 2 * V_4 -> V_212 , V_2 -> V_228 >> 10 ) ;
V_372 = F_31 ( T_4 , V_372 , V_393 ) ;
V_372 <<= V_392 ;
if ( F_95 ( & V_2 -> V_213 ) > V_372 ) {
if ( V_4 == V_2 -> V_394 . V_384 ||
V_4 -> V_395 == V_2 -> V_394 . V_384 )
return false ;
F_216 ( V_396 , & V_2 -> V_196 ) ;
F_217 () ;
if ( F_95 ( & V_2 -> V_213 ) > V_372 )
return true ;
}
return false ;
}
static void F_218 ( struct V_7 * V_8 , const enum V_397 V_398 )
{
const T_4 V_34 = V_32 ;
enum V_397 V_399 = V_8 -> V_400 ;
if ( V_399 > V_401 )
V_8 -> V_402 [ V_399 - 1 ] += V_34 - V_8 -> V_403 ;
V_8 -> V_403 = V_34 ;
V_8 -> V_400 = V_398 ;
}
void F_181 ( struct V_1 * V_2 , const enum V_397 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( type > V_8 -> V_400 )
F_218 ( V_8 , type ) ;
}
void F_219 ( struct V_1 * V_2 , const enum V_397 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_220 ( V_2 ) )
F_218 ( V_8 , V_401 ) ;
else if ( type == V_8 -> V_400 )
F_218 ( V_8 , V_404 ) ;
}
static bool F_64 ( struct V_1 * V_2 , unsigned int V_279 , int V_184 ,
int V_405 , T_11 V_300 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_359 , V_406 ;
int V_368 ;
int V_407 ;
bool V_341 = false , V_408 = false ;
T_4 V_362 ;
V_406 = 0 ;
if ( ! V_405 ) {
V_407 = F_203 ( V_2 ) ;
if ( ! V_407 ) {
return false ;
} else if ( V_407 > 0 ) {
V_406 = 1 ;
}
}
V_362 = F_186 ( V_2 , V_279 ) ;
F_221 ( V_8 ) ;
while ( ( V_4 = F_180 ( V_2 ) ) ) {
unsigned int V_372 ;
if ( F_213 ( V_2 ) )
break;
V_359 = F_190 ( V_4 , V_279 ) ;
F_114 ( ! V_359 ) ;
if ( F_53 ( V_8 -> V_409 ) && V_8 -> V_410 == V_411 ) {
V_4 -> V_240 = V_8 -> V_241 ;
goto V_409;
}
V_368 = F_189 ( V_8 , V_4 ) ;
if ( ! V_368 ) {
if ( V_405 == 2 )
V_368 = 1 ;
else
break;
}
if ( F_53 ( ! F_192 ( V_8 , V_4 , V_279 ) ) ) {
V_408 = true ;
break;
}
if ( V_359 == 1 ) {
if ( F_53 ( ! F_191 ( V_8 , V_4 , V_279 ,
( F_195 ( V_2 , V_4 ) ?
V_184 : V_367 ) ) ) )
break;
} else {
if ( ! V_405 &&
F_197 ( V_2 , V_4 , & V_341 ,
V_362 ) )
break;
}
V_372 = V_279 ;
if ( V_359 > 1 && ! F_51 ( V_8 ) )
V_372 = F_187 ( V_2 , V_4 , V_279 ,
F_31 (unsigned int,
cwnd_quota,
max_segs) ,
V_184 ) ;
if ( V_4 -> V_83 > V_372 &&
F_53 ( F_196 ( V_2 , V_4 , V_372 , V_279 , V_300 ) ) )
break;
if ( F_76 ( V_199 , & V_2 -> V_196 ) )
F_75 ( V_199 , & V_2 -> V_196 ) ;
if ( F_215 ( V_2 , V_4 , 0 ) )
break;
if ( F_53 ( F_113 ( V_2 , V_4 , 1 , V_300 ) ) )
break;
V_409:
F_1 ( V_2 , V_4 ) ;
F_183 ( V_8 , V_279 , V_4 ) ;
V_406 += F_6 ( V_4 ) ;
if ( V_405 )
break;
}
if ( V_408 )
F_181 ( V_2 , V_412 ) ;
else
F_219 ( V_2 , V_412 ) ;
if ( F_55 ( V_406 ) ) {
if ( F_222 ( V_2 ) )
V_8 -> V_413 += V_406 ;
if ( V_405 != 2 )
F_223 ( V_2 ) ;
V_341 |= ( F_23 ( V_8 ) >= V_8 -> V_27 ) ;
F_178 ( V_2 , V_341 ) ;
return false ;
}
return ! V_8 -> V_10 && F_180 ( V_2 ) ;
}
bool F_223 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_414 = F_224 ( V_8 -> V_379 >> 3 ) ;
T_4 V_415 , V_416 ;
if ( V_8 -> V_417 )
return false ;
if ( ( V_418 != 3 && V_418 != 4 ) ||
! V_8 -> V_10 || ! F_225 ( V_8 ) ||
V_6 -> V_335 != V_336 )
return false ;
if ( ( V_8 -> V_27 > F_23 ( V_8 ) ) &&
F_180 ( V_2 ) )
return false ;
V_415 = V_414 << 1 ? : V_419 ;
if ( V_8 -> V_10 == 1 )
V_415 = F_30 ( T_4 , V_415 ,
( V_414 + ( V_414 >> 1 ) + V_420 ) ) ;
V_415 = F_30 ( T_4 , V_415 , F_226 ( 10 ) ) ;
V_416 = F_227 ( V_2 ) ;
if ( V_416 > 0 )
V_415 = F_31 ( T_4 , V_415 , F_224 ( V_416 ) ) ;
F_228 ( V_2 , V_14 , V_415 ,
V_421 ) ;
return true ;
}
static bool F_229 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_53 ( F_230 ( V_2 , V_4 ) ) ) {
F_35 ( F_9 ( V_2 ) ,
V_422 ) ;
return true ;
}
return false ;
}
void F_231 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_423 ;
int V_21 = F_65 ( V_2 ) ;
V_4 = F_180 ( V_2 ) ;
if ( V_4 ) {
if ( F_192 ( V_8 , V_4 , V_21 ) ) {
V_423 = V_8 -> V_10 ;
F_64 ( V_2 , V_21 , V_424 , 2 , V_185 ) ;
if ( V_8 -> V_10 > V_423 )
goto V_425;
goto V_426;
}
V_4 = F_232 ( V_2 , V_4 ) ;
} else {
V_4 = F_188 ( V_2 ) ;
}
if ( V_8 -> V_427 )
goto V_426;
if ( F_93 ( ! V_4 ) )
goto V_426;
if ( F_229 ( V_2 , V_4 ) )
goto V_426;
V_423 = F_6 ( V_4 ) ;
if ( F_93 ( ! V_423 ) )
goto V_426;
if ( ( V_423 > 1 ) && ( V_4 -> V_83 > ( V_423 - 1 ) * V_21 ) ) {
if ( F_53 ( F_151 ( V_2 , V_4 , ( V_423 - 1 ) * V_21 , V_21 ,
V_185 ) ) )
goto V_426;
V_4 = F_233 ( V_2 , V_4 ) ;
}
if ( F_93 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_426;
if ( F_234 ( V_2 , V_4 , 1 ) )
goto V_426;
V_8 -> V_427 = V_8 -> V_11 ;
V_425:
F_35 ( F_9 ( V_2 ) , V_428 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_426:
F_7 ( V_2 ) ;
}
void F_235 ( struct V_1 * V_2 , unsigned int V_366 ,
int V_184 )
{
if ( F_53 ( V_2 -> V_176 == V_429 ) )
return;
if ( F_64 ( V_2 , V_366 , V_184 , 0 ,
F_236 ( V_2 , V_185 ) ) )
F_237 ( V_2 ) ;
}
void F_238 ( struct V_1 * V_2 , unsigned int V_279 )
{
struct V_3 * V_4 = F_180 ( V_2 ) ;
F_114 ( ! V_4 || V_4 -> V_83 < V_279 ) ;
F_64 ( V_2 , V_279 , V_367 , 1 , V_2 -> V_430 ) ;
}
T_4 F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_21 = V_6 -> V_37 . V_431 ;
int V_432 = F_239 ( V_2 ) ;
int V_433 = F_240 ( V_2 ) ;
int V_434 = F_31 ( int , V_8 -> V_47 , V_433 ) ;
int V_260 ;
if ( F_53 ( V_21 > V_434 ) ) {
V_21 = V_434 ;
if ( V_21 <= 0 )
return 0 ;
}
if ( V_432 < ( V_434 >> 1 ) ) {
V_6 -> V_37 . V_435 = 0 ;
if ( F_241 ( V_2 ) )
V_8 -> V_436 = F_20 ( V_8 -> V_436 ,
4U * V_8 -> V_22 ) ;
V_432 = F_242 ( V_432 , 1 << V_8 -> V_16 . V_18 ) ;
if ( V_432 < ( V_433 >> 4 ) || V_432 < V_21 )
return 0 ;
}
if ( V_432 > V_8 -> V_436 )
V_432 = V_8 -> V_436 ;
if ( V_8 -> V_16 . V_18 ) {
V_260 = V_432 ;
V_260 = F_36 ( V_260 , ( 1 << V_8 -> V_16 . V_18 ) ) ;
} else {
V_260 = V_8 -> V_46 ;
if ( V_260 <= V_432 - V_21 || V_260 > V_432 )
V_260 = F_29 ( V_432 , V_21 ) ;
else if ( V_21 == V_434 &&
V_432 > V_260 + ( V_434 >> 1 ) )
V_260 = V_432 ;
}
return V_260 ;
}
void F_243 ( struct V_3 * V_4 ,
const struct V_3 * V_437 )
{
if ( F_53 ( F_147 ( V_437 ) ) ) {
const struct V_294 * V_438 =
F_47 ( V_437 ) ;
struct V_294 * V_295 = F_47 ( V_4 ) ;
V_295 -> V_291 |= V_438 -> V_291 & V_292 ;
V_295 -> V_296 = V_438 -> V_296 ;
F_5 ( V_4 ) -> V_290 |=
F_5 ( V_437 ) -> V_290 ;
}
}
static bool F_244 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_437 = F_233 ( V_2 , V_4 ) ;
int V_439 , V_440 ;
V_439 = V_4 -> V_83 ;
V_440 = V_437 -> V_83 ;
F_114 ( F_6 ( V_4 ) != 1 || F_6 ( V_437 ) != 1 ) ;
if ( V_440 ) {
if ( V_440 <= F_245 ( V_4 ) )
F_206 ( V_437 , 0 , F_156 ( V_4 , V_440 ) ,
V_440 ) ;
else if ( ! F_246 ( V_4 , V_437 , V_440 ) )
return false ;
}
F_247 ( V_2 , V_437 , V_4 ) ;
F_209 ( V_437 , V_2 ) ;
if ( V_437 -> V_91 == V_92 )
V_4 -> V_91 = V_92 ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_208 ( V_4 -> V_93 , V_437 -> V_93 , V_439 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_437 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_437 ) -> V_65 ;
F_5 ( V_4 ) -> V_94 |= F_5 ( V_437 ) -> V_94 & V_441 ;
F_5 ( V_4 ) -> V_299 = F_5 ( V_437 ) -> V_299 ;
F_248 ( V_8 ) ;
if ( V_437 == V_8 -> V_442 )
V_8 -> V_442 = V_4 ;
F_144 ( V_2 , V_437 , F_6 ( V_437 ) ) ;
F_243 ( V_4 , V_437 ) ;
F_210 ( V_2 , V_437 ) ;
return true ;
}
static bool F_249 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_116 ( V_4 ) )
return false ;
if ( V_4 == F_180 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_94 & V_285 )
return false ;
return true ;
}
static void F_250 ( struct V_1 * V_2 , struct V_3 * V_443 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_443 , * V_444 ;
bool V_445 = true ;
if ( ! V_446 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
return;
F_205 (skb, tmp, sk) {
if ( ! F_249 ( V_2 , V_4 ) )
break;
if ( ! F_251 ( V_443 ) )
break;
V_49 -= V_4 -> V_83 ;
if ( V_445 ) {
V_445 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( F_129 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
if ( ! F_244 ( V_2 , V_443 ) )
break;
}
}
int F_234 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_355 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_366 ;
int V_309 , V_83 , V_239 ;
if ( V_6 -> V_324 . V_330 )
V_6 -> V_324 . V_330 = 0 ;
if ( F_95 ( & V_2 -> V_213 ) >
F_31 ( T_4 , V_2 -> V_278 + ( V_2 -> V_278 >> 2 ) ,
V_2 -> V_447 ) )
return - V_448 ;
if ( F_229 ( V_2 , V_4 ) )
return - V_449 ;
if ( F_11 ( F_5 ( V_4 ) -> V_84 , V_8 -> V_97 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_97 ) )
F_252 () ;
if ( F_166 ( V_2 , V_4 , V_8 -> V_97 - F_5 ( V_4 ) -> V_84 ) )
return - V_306 ;
}
if ( F_2 ( V_2 ) -> V_206 -> V_450 ( V_2 ) )
return - V_451 ;
V_366 = F_65 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_84 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_84 != V_8 -> V_97 )
return - V_448 ;
V_83 = V_366 * V_355 ;
if ( V_4 -> V_83 > V_83 ) {
if ( F_151 ( V_2 , V_4 , V_83 , V_366 , V_185 ) )
return - V_306 ;
} else {
if ( F_153 ( V_4 , V_185 ) )
return - V_306 ;
V_309 = F_6 ( V_4 ) ;
F_139 ( V_4 , V_366 ) ;
V_309 -= F_6 ( V_4 ) ;
if ( V_309 )
F_144 ( V_2 , V_4 , V_309 ) ;
if ( V_4 -> V_83 < V_366 )
F_250 ( V_2 , V_4 , V_366 ) ;
}
if ( ( F_5 ( V_4 ) -> V_65 & V_452 ) == V_452 )
F_43 ( V_2 , V_4 ) ;
V_355 = F_6 ( V_4 ) ;
F_131 ( F_9 ( V_2 ) , V_453 , V_355 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
F_253 ( F_9 ( V_2 ) , V_454 ) ;
V_8 -> V_455 += V_355 ;
if ( F_53 ( ( V_456 && ( ( unsigned long ) V_4 -> V_186 & 3 ) ) ||
F_254 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_383 ;
V_4 -> V_240 = V_8 -> V_241 ;
V_383 = F_255 ( V_4 , V_357 , V_185 ) ;
V_239 = V_383 ? F_113 ( V_2 , V_383 , 0 , V_185 ) :
- V_244 ;
} else {
V_239 = F_113 ( V_2 , V_4 , 1 , V_185 ) ;
}
if ( F_55 ( ! V_239 ) ) {
F_5 ( V_4 ) -> V_94 |= V_441 ;
} else if ( V_239 != - V_449 ) {
F_35 ( F_9 ( V_2 ) , V_457 ) ;
}
return V_239 ;
}
int F_256 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_355 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_239 = F_234 ( V_2 , V_4 , V_355 ) ;
if ( V_239 == 0 ) {
#if V_458 > 0
if ( F_5 ( V_4 ) -> V_94 & V_286 ) {
F_257 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_94 |= V_459 ;
V_8 -> V_183 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_460 )
V_8 -> V_460 = F_58 ( V_4 ) ;
}
if ( V_8 -> V_461 < 0 )
V_8 -> V_461 = 0 ;
V_8 -> V_461 += F_6 ( V_4 ) ;
return V_239 ;
}
void F_63 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_462 = NULL ;
T_4 V_362 ;
int V_463 ;
if ( ! V_8 -> V_10 )
return;
if ( V_8 -> V_442 ) {
V_4 = V_8 -> V_442 ;
} else {
V_4 = F_200 ( V_2 ) ;
}
V_362 = F_186 ( V_2 , F_65 ( V_2 ) ) ;
F_258 (skb, sk) {
T_5 V_94 ;
int V_355 ;
if ( V_4 == F_180 ( V_2 ) )
break;
if ( F_213 ( V_2 ) )
break;
if ( ! V_462 )
V_8 -> V_442 = V_4 ;
V_355 = V_8 -> V_27 - F_23 ( V_8 ) ;
if ( V_355 <= 0 )
return;
V_94 = F_5 ( V_4 ) -> V_94 ;
V_355 = F_31 ( int , V_355 , V_362 ) ;
if ( V_8 -> V_183 >= V_8 -> V_182 ) {
break;
} else if ( ! ( V_94 & V_287 ) ) {
if ( ! V_462 && ! ( V_94 & ( V_286 | V_285 ) ) )
V_462 = V_4 ;
continue;
} else {
if ( V_6 -> V_335 != V_464 )
V_463 = V_465 ;
else
V_463 = V_466 ;
}
if ( V_94 & ( V_285 | V_286 ) )
continue;
if ( F_215 ( V_2 , V_4 , 1 ) )
return;
if ( F_256 ( V_2 , V_4 , V_355 ) )
return;
F_8 ( F_9 ( V_2 ) , V_463 , F_6 ( V_4 ) ) ;
if ( F_222 ( V_2 ) )
V_8 -> V_413 += F_6 ( V_4 ) ;
if ( V_4 == F_200 ( V_2 ) &&
V_6 -> V_13 != V_467 )
F_228 ( V_2 , V_468 ,
F_2 ( V_2 ) -> V_30 ,
V_421 ) ;
}
}
void F_259 ( struct V_1 * V_2 , int V_172 )
{
int V_469 ;
if ( V_172 <= V_2 -> V_470 )
return;
V_469 = F_260 ( V_172 ) ;
V_2 -> V_470 += V_469 * V_471 ;
F_261 ( V_2 , V_469 ) ;
if ( V_472 && V_2 -> V_473 )
F_262 ( V_2 -> V_473 , V_469 ) ;
}
void F_263 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_474 = F_188 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_474 && ( F_180 ( V_2 ) || F_241 ( V_2 ) ) ) {
V_475:
F_5 ( V_474 ) -> V_65 |= V_96 ;
F_5 ( V_474 ) -> V_12 ++ ;
V_8 -> V_277 ++ ;
if ( ! F_180 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_264 ( V_357 , V_2 -> V_430 ) ;
if ( F_53 ( ! V_4 ) ) {
if ( V_474 )
goto V_475;
return;
}
F_265 ( V_4 , V_357 ) ;
F_259 ( V_2 , V_4 -> V_212 ) ;
F_49 ( V_4 , V_8 -> V_277 ,
V_264 | V_96 ) ;
F_135 ( V_2 , V_4 ) ;
}
F_235 ( V_2 , F_65 ( V_2 ) , V_424 ) ;
}
void F_266 ( struct V_1 * V_2 , T_11 V_476 )
{
struct V_3 * V_4 ;
F_267 ( F_9 ( V_2 ) , V_477 ) ;
V_4 = F_268 ( V_357 , V_476 ) ;
if ( ! V_4 ) {
F_35 ( F_9 ( V_2 ) , V_478 ) ;
return;
}
F_265 ( V_4 , V_357 ) ;
F_49 ( V_4 , F_10 ( V_2 ) ,
V_264 | V_479 ) ;
F_221 ( F_3 ( V_2 ) ) ;
if ( F_113 ( V_2 , V_4 , 0 , V_476 ) )
F_35 ( F_9 ( V_2 ) , V_478 ) ;
}
int F_269 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_200 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_65 & V_95 ) ) {
F_270 ( L_2 , V_480 ) ;
return - V_481 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_264 ) ) {
if ( F_116 ( V_4 ) ) {
struct V_3 * V_383 = F_271 ( V_4 , V_185 ) ;
if ( ! V_383 )
return - V_306 ;
F_209 ( V_4 , V_2 ) ;
F_136 ( V_383 ) ;
F_272 ( V_2 , V_383 ) ;
F_210 ( V_2 , V_4 ) ;
V_2 -> V_278 += V_383 -> V_212 ;
F_138 ( V_2 , V_383 -> V_212 ) ;
V_4 = V_383 ;
}
F_5 ( V_4 ) -> V_65 |= V_264 ;
F_37 ( V_2 , V_4 ) ;
}
return F_113 ( V_2 , V_4 , 1 , V_185 ) ;
}
struct V_3 * F_273 ( const struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_76 * V_77 ,
struct V_134 * V_135 ,
enum V_482 V_483 )
{
struct V_167 * V_168 = F_45 ( V_77 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_144 * V_145 = NULL ;
struct V_100 V_101 ;
struct V_3 * V_4 ;
int V_238 ;
struct V_78 * V_79 ;
int V_21 ;
V_4 = F_268 ( V_357 , V_185 ) ;
if ( F_53 ( ! V_4 ) ) {
F_274 ( V_20 ) ;
return NULL ;
}
F_265 ( V_4 , V_357 ) ;
switch ( V_483 ) {
case V_484 :
F_275 ( V_4 , F_276 ( V_77 ) ) ;
break;
case V_485 :
break;
case V_486 :
F_275 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_277 ( V_4 , V_20 ) ;
V_21 = F_278 ( V_8 , F_15 ( V_20 ) ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
#ifdef F_279
if ( F_53 ( V_77 -> V_487 ) )
V_4 -> V_240 = F_280 ( V_77 ) ;
else
#endif
V_4 -> V_240 = F_281 () ;
#ifdef F_57
F_282 () ;
V_145 = F_60 ( V_77 ) -> V_151 -> V_488 ( V_2 , F_276 ( V_77 ) ) ;
#endif
F_283 ( V_4 , F_60 ( V_77 ) -> V_489 , V_490 ) ;
V_238 = F_59 ( V_77 , V_21 , V_4 , & V_101 , V_145 , V_135 ) +
sizeof( * V_79 ) ;
F_121 ( V_4 , V_238 ) ;
F_122 ( V_4 ) ;
V_79 = (struct V_78 * ) V_4 -> V_186 ;
memset ( V_79 , 0 , sizeof( struct V_78 ) ) ;
V_79 -> V_491 = 1 ;
V_79 -> V_492 = 1 ;
F_44 ( V_77 , V_79 ) ;
V_79 -> V_250 = F_128 ( V_168 -> V_493 ) ;
V_79 -> V_252 = V_168 -> V_494 ;
V_4 -> V_495 = V_168 -> V_496 ;
F_49 ( V_4 , F_60 ( V_77 ) -> V_497 ,
V_95 | V_264 ) ;
V_79 -> V_84 = F_54 ( F_5 ( V_4 ) -> V_84 ) ;
V_79 -> V_254 = F_54 ( F_60 ( V_77 ) -> V_61 ) ;
V_79 -> V_260 = F_128 ( F_20 ( V_77 -> V_498 , 65535U ) ) ;
F_52 ( ( T_8 * ) ( V_79 + 1 ) , NULL , & V_101 ) ;
V_79 -> V_499 = ( V_238 >> 2 ) ;
F_284 ( F_9 ( V_2 ) , V_266 ) ;
#ifdef F_57
if ( V_145 )
F_60 ( V_77 ) -> V_151 -> V_262 ( V_101 . V_107 ,
V_145 , F_276 ( V_77 ) , V_4 ) ;
F_285 () ;
#endif
V_4 -> V_270 = 0 ;
return V_4 ;
}
static void F_286 ( struct V_1 * V_2 , const struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_342 * V_500 ;
T_4 V_501 = F_287 ( V_20 , V_502 ) ;
if ( V_501 == V_503 )
return;
F_282 () ;
V_500 = F_288 ( V_501 ) ;
if ( F_55 ( V_500 && F_289 ( V_500 -> V_504 ) ) ) {
F_290 ( V_6 -> V_344 -> V_504 ) ;
V_6 -> V_505 = F_291 ( V_20 ) ;
V_6 -> V_344 = V_500 ;
}
F_285 () ;
}
static void F_292 ( struct V_1 * V_2 )
{
const struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_18 ;
T_4 V_46 ;
V_8 -> V_82 = sizeof( struct V_78 ) ;
if ( F_9 ( V_2 ) -> V_72 . V_155 )
V_8 -> V_82 += V_158 ;
#ifdef F_57
if ( V_8 -> V_151 -> V_152 ( V_2 , V_2 ) )
V_8 -> V_82 += V_153 ;
#endif
if ( V_8 -> V_16 . V_506 )
V_8 -> V_16 . V_320 = V_8 -> V_16 . V_506 ;
V_8 -> V_507 = 0 ;
F_173 ( V_2 ) ;
F_174 ( V_2 , F_176 ( V_20 ) ) ;
F_286 ( V_2 , V_20 ) ;
if ( ! V_8 -> V_47 )
V_8 -> V_47 = F_287 ( V_20 , V_508 ) ;
V_8 -> V_22 = F_278 ( V_8 , F_15 ( V_20 ) ) ;
F_293 ( V_2 ) ;
if ( V_2 -> V_509 & V_510 &&
( V_8 -> V_47 > F_240 ( V_2 ) || V_8 -> V_47 == 0 ) )
V_8 -> V_47 = F_240 ( V_2 ) ;
V_46 = F_294 ( V_2 ) ;
if ( V_46 == 0 )
V_46 = F_287 ( V_20 , V_511 ) ;
F_28 ( F_240 ( V_2 ) ,
V_8 -> V_22 - ( V_8 -> V_16 . V_512 ? V_8 -> V_82 - sizeof( struct V_78 ) : 0 ) ,
& V_8 -> V_46 ,
& V_8 -> V_47 ,
F_9 ( V_2 ) -> V_72 . V_159 ,
& V_18 ,
V_46 ) ;
V_8 -> V_16 . V_18 = V_18 ;
V_8 -> V_436 = V_8 -> V_46 ;
V_2 -> V_513 = 0 ;
F_295 ( V_2 , V_514 ) ;
V_8 -> V_378 = 0 ;
F_296 ( V_8 , 0 ) ;
V_8 -> V_97 = V_8 -> V_277 ;
V_8 -> V_350 = V_8 -> V_277 ;
V_8 -> V_98 = V_8 -> V_277 ;
V_8 -> V_11 = V_8 -> V_277 ;
if ( F_55 ( ! V_8 -> V_409 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_515 = V_32 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_516 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = F_297 ( V_2 ) ;
F_2 ( V_2 ) -> V_517 = 0 ;
F_298 ( V_8 ) ;
}
static void F_299 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_235 * V_236 = F_5 ( V_4 ) ;
V_236 -> V_12 += V_4 -> V_83 ;
F_136 ( V_4 ) ;
F_300 ( V_2 , V_4 ) ;
V_2 -> V_278 += V_4 -> V_212 ;
F_138 ( V_2 , V_4 -> V_212 ) ;
V_8 -> V_277 = V_236 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_301 ( struct V_1 * V_2 , struct V_3 * V_491 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_148 * V_518 = V_8 -> V_150 ;
int V_49 , V_239 = 0 ;
struct V_3 * V_519 ;
V_8 -> V_16 . V_320 = V_8 -> V_22 ;
if ( ! F_302 ( V_2 , & V_8 -> V_16 . V_320 , & V_518 -> V_163 ) )
goto V_520;
V_8 -> V_16 . V_320 = F_278 ( V_8 , V_8 -> V_16 . V_320 ) ;
V_49 = F_169 ( V_2 , F_2 ( V_2 ) -> V_332 ) -
V_147 ;
V_49 = F_31 ( V_521 , V_49 , V_518 -> V_172 ) ;
V_49 = F_31 ( V_521 , V_49 , F_303 ( V_357 ) ) ;
V_519 = F_154 ( V_2 , V_49 , V_2 -> V_430 , false ) ;
if ( ! V_519 )
goto V_520;
V_519 -> V_91 = V_92 ;
memcpy ( V_519 -> V_271 , V_491 -> V_271 , sizeof( V_491 -> V_271 ) ) ;
if ( V_49 ) {
int V_522 = F_304 ( F_156 ( V_519 , V_49 ) , V_49 ,
& V_518 -> V_186 -> V_523 ) ;
if ( F_53 ( ! V_522 ) ) {
F_305 ( V_519 ) ;
goto V_520;
}
if ( V_522 != V_49 ) {
F_157 ( V_519 , V_522 ) ;
V_49 = V_522 ;
}
}
if ( V_49 == V_518 -> V_172 )
V_518 -> V_186 = NULL ;
V_518 -> V_522 = V_49 ;
F_299 ( V_2 , V_519 ) ;
if ( V_519 -> V_83 )
F_181 ( V_2 , V_404 ) ;
V_239 = F_113 ( V_2 , V_519 , 1 , V_2 -> V_430 ) ;
V_491 -> V_240 = V_519 -> V_240 ;
F_5 ( V_519 ) -> V_84 ++ ;
F_5 ( V_519 ) -> V_65 = V_264 | V_307 ;
if ( ! V_239 ) {
V_8 -> V_519 = ( V_518 -> V_522 > 0 ) ;
F_35 ( F_9 ( V_2 ) , V_15 ) ;
goto V_524;
}
V_520:
if ( V_518 -> V_163 . V_83 > 0 )
V_518 -> V_163 . V_83 = 0 ;
V_239 = F_113 ( V_2 , V_491 , 1 , V_2 -> V_430 ) ;
if ( V_239 )
V_8 -> V_165 = 0 ;
V_524:
V_518 -> V_163 . V_83 = - 1 ;
return V_239 ;
}
int F_306 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_301 ;
int V_239 ;
F_307 ( V_2 , V_525 ) ;
if ( F_2 ( V_2 ) -> V_206 -> V_450 ( V_2 ) )
return - V_451 ;
F_292 ( V_2 ) ;
if ( F_53 ( V_8 -> V_409 ) ) {
F_308 ( V_2 , NULL ) ;
return 0 ;
}
V_301 = F_154 ( V_2 , 0 , V_2 -> V_430 , true ) ;
if ( F_53 ( ! V_301 ) )
return - V_244 ;
F_49 ( V_301 , V_8 -> V_277 ++ , V_95 ) ;
F_221 ( V_8 ) ;
V_8 -> V_460 = F_309 ( V_8 ) ;
F_299 ( V_2 , V_301 ) ;
F_41 ( V_2 , V_301 ) ;
V_239 = V_8 -> V_150 ? F_301 ( V_2 , V_301 ) :
F_113 ( V_2 , V_301 , 1 , V_2 -> V_430 ) ;
if ( V_239 == - V_526 )
return V_239 ;
V_8 -> V_11 = V_8 -> V_277 ;
V_8 -> V_527 = V_8 -> V_277 ;
F_267 ( F_9 ( V_2 ) , V_528 ) ;
F_228 ( V_2 , V_468 ,
F_2 ( V_2 ) -> V_30 , V_421 ) ;
return 0 ;
}
void F_310 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_39 = V_6 -> V_37 . V_39 ;
unsigned long V_415 ;
F_18 ( V_2 , V_529 ) ;
if ( V_39 > V_530 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_531 = V_382 / 2 ;
if ( V_6 -> V_37 . V_40 ||
( V_6 -> V_37 . V_532 & V_533 ) )
V_531 = V_420 ;
if ( V_8 -> V_379 ) {
int V_414 = F_30 ( int , F_224 ( V_8 -> V_379 >> 3 ) ,
V_530 ) ;
if ( V_414 < V_531 )
V_531 = V_414 ;
}
V_39 = F_20 ( V_39 , V_531 ) ;
}
V_415 = V_534 + V_39 ;
if ( V_6 -> V_37 . V_532 & V_535 ) {
if ( V_6 -> V_37 . V_536 ||
F_311 ( V_6 -> V_37 . V_415 , V_534 + ( V_39 >> 2 ) ) ) {
F_312 ( V_2 ) ;
return;
}
if ( ! F_313 ( V_415 , V_6 -> V_37 . V_415 ) )
V_415 = V_6 -> V_37 . V_415 ;
}
V_6 -> V_37 . V_532 |= V_537 | V_535 ;
V_6 -> V_37 . V_415 = V_415 ;
F_314 ( V_2 , & V_6 -> V_538 , V_415 ) ;
}
void F_312 ( struct V_1 * V_2 )
{
struct V_3 * V_301 ;
if ( V_2 -> V_176 == V_429 )
return;
F_18 ( V_2 , V_539 ) ;
V_301 = F_268 ( V_357 ,
F_236 ( V_2 , V_185 | V_540 ) ) ;
if ( F_53 ( ! V_301 ) ) {
F_315 ( V_2 ) ;
F_2 ( V_2 ) -> V_37 . V_39 = V_541 ;
F_228 ( V_2 , V_42 ,
V_420 , V_421 ) ;
return;
}
F_265 ( V_301 , V_357 ) ;
F_49 ( V_301 , F_10 ( V_2 ) , V_264 ) ;
F_316 ( V_301 ) ;
F_113 ( V_2 , V_301 , 0 , ( V_542 T_11 ) 0 ) ;
}
static int F_317 ( struct V_1 * V_2 , int V_543 , int V_544 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_268 ( V_357 ,
F_236 ( V_2 , V_185 | V_540 ) ) ;
if ( ! V_4 )
return - 1 ;
F_265 ( V_4 , V_357 ) ;
F_49 ( V_4 , V_8 -> V_97 - ! V_543 , V_264 ) ;
F_35 ( F_9 ( V_2 ) , V_544 ) ;
return F_113 ( V_2 , V_4 , 0 , ( V_542 T_11 ) 0 ) ;
}
void F_318 ( struct V_1 * V_2 )
{
if ( V_2 -> V_176 == V_545 ) {
F_3 ( V_2 ) -> V_546 = F_3 ( V_2 ) -> V_61 - 1 ;
F_221 ( F_3 ( V_2 ) ) ;
F_317 ( V_2 , 0 , V_547 ) ;
}
}
int F_319 ( struct V_1 * V_2 , int V_544 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_176 == V_429 )
return - 1 ;
V_4 = F_180 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_84 , F_12 ( V_8 ) ) ) {
int V_239 ;
unsigned int V_21 = F_65 ( V_2 ) ;
unsigned int V_548 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_84 ;
if ( F_11 ( V_8 -> V_527 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_527 = F_5 ( V_4 ) -> V_12 ;
if ( V_548 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_84 ||
V_4 -> V_83 > V_21 ) {
V_548 = F_20 ( V_548 , V_21 ) ;
F_5 ( V_4 ) -> V_65 |= V_307 ;
if ( F_151 ( V_2 , V_4 , V_548 , V_21 , V_185 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_139 ( V_4 , V_21 ) ;
F_5 ( V_4 ) -> V_65 |= V_307 ;
V_239 = F_113 ( V_2 , V_4 , 1 , V_185 ) ;
if ( ! V_239 )
F_1 ( V_2 , V_4 ) ;
return V_239 ;
} else {
if ( F_320 ( V_8 -> V_98 , V_8 -> V_97 + 1 , V_8 -> V_97 + 0xFFFF ) )
F_317 ( V_2 , 1 , V_544 ) ;
return F_317 ( V_2 , 0 , V_544 ) ;
}
}
void F_321 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_323 * V_323 = F_9 ( V_2 ) ;
unsigned long V_549 ;
int V_239 ;
V_239 = F_319 ( V_2 , V_547 ) ;
if ( V_8 -> V_10 || ! F_180 ( V_2 ) ) {
V_6 -> V_550 = 0 ;
V_6 -> V_551 = 0 ;
return;
}
if ( V_239 <= 0 ) {
if ( V_6 -> V_551 < V_323 -> V_72 . V_552 )
V_6 -> V_551 ++ ;
V_6 -> V_550 ++ ;
V_549 = V_421 ;
} else {
if ( ! V_6 -> V_550 )
V_6 -> V_550 = 1 ;
V_549 = V_553 ;
}
F_228 ( V_2 , V_554 ,
F_322 ( V_2 , V_549 ) ,
V_421 ) ;
}
int F_323 ( const struct V_1 * V_2 , struct V_76 * V_77 )
{
const struct V_555 * V_556 = F_60 ( V_77 ) -> V_151 ;
struct V_557 V_276 ;
int V_558 ;
F_60 ( V_77 ) -> V_489 = F_324 () ;
V_558 = V_556 -> V_559 ( V_2 , NULL , & V_276 , V_77 , NULL , V_484 ) ;
if ( ! V_558 ) {
F_284 ( F_9 ( V_2 ) , V_453 ) ;
F_253 ( F_9 ( V_2 ) , V_454 ) ;
if ( F_53 ( F_325 ( V_2 ) ) )
F_3 ( V_2 ) -> V_455 ++ ;
}
return V_558 ;
}
