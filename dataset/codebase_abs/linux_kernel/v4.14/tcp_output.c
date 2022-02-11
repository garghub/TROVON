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
V_8 -> V_27 > F_23 ( V_8 ) ) {
F_63 ( V_8 ) ;
F_64 ( V_2 ) ;
}
F_65 ( V_2 , F_66 ( V_2 ) , V_8 -> V_184 ,
0 , V_185 ) ;
}
}
static void F_67 ( unsigned long V_186 )
{
struct V_187 * V_188 = (struct V_187 * ) V_186 ;
F_68 ( V_189 ) ;
unsigned long V_90 ;
struct V_190 * V_191 , * V_192 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_69 ( V_90 ) ;
F_70 ( & V_188 -> V_193 , & V_189 ) ;
F_71 ( V_90 ) ;
F_72 (q, n, &list) {
V_8 = F_73 ( V_191 , struct V_7 , V_194 ) ;
F_74 ( & V_8 -> V_194 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_75 () ;
F_76 ( V_195 , & V_2 -> V_196 ) ;
if ( ! V_2 -> V_197 . V_198 &&
F_77 ( V_199 , & V_2 -> V_196 ) ) {
F_78 ( V_2 ) ;
if ( ! F_79 ( V_2 ) ) {
F_76 ( V_199 , & V_2 -> V_196 ) ;
F_62 ( V_2 ) ;
}
F_80 ( V_2 ) ;
}
F_81 ( V_2 ) ;
}
}
void F_82 ( struct V_1 * V_2 )
{
unsigned long V_90 , V_200 ;
do {
V_90 = V_2 -> V_196 ;
if ( ! ( V_90 & V_201 ) )
return;
V_200 = V_90 & ~ V_201 ;
} while ( F_83 ( & V_2 -> V_196 , V_90 , V_200 ) != V_90 );
if ( V_90 & V_202 )
F_62 ( V_2 ) ;
F_84 ( V_2 ) ;
if ( V_90 & V_203 ) {
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
}
if ( V_90 & V_204 ) {
F_87 ( V_2 ) ;
F_86 ( V_2 ) ;
}
if ( V_90 & V_205 ) {
F_2 ( V_2 ) -> V_206 -> V_207 ( V_2 ) ;
F_86 ( V_2 ) ;
}
}
void T_9 F_88 ( void )
{
int V_208 ;
F_89 (i) {
struct V_187 * V_188 = & F_90 ( V_187 , V_208 ) ;
F_91 ( & V_188 -> V_193 ) ;
F_92 ( & V_188 -> V_209 ,
F_67 ,
( unsigned long ) V_188 ) ;
}
}
void F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_90 , V_210 , V_211 ;
F_94 ( F_95 ( V_4 -> V_212 - 1 , & V_2 -> V_213 ) ) ;
if ( F_96 ( & V_2 -> V_213 ) >= F_97 ( 1 ) && F_98 () == V_214 )
goto V_215;
for ( V_211 = F_99 ( V_2 -> V_196 ) ; ; V_211 = V_210 ) {
struct V_187 * V_188 ;
bool V_216 ;
if ( ! ( V_211 & V_217 ) || ( V_211 & V_218 ) )
goto V_215;
V_210 = ( V_211 & ~ V_217 ) | V_218 | V_202 ;
V_210 = F_83 ( & V_2 -> V_196 , V_211 , V_210 ) ;
if ( V_210 != V_211 )
continue;
F_69 ( V_90 ) ;
V_188 = F_100 ( & V_187 ) ;
V_216 = F_101 ( & V_188 -> V_193 ) ;
F_102 ( & V_8 -> V_194 , & V_188 -> V_193 ) ;
if ( V_216 )
F_103 ( & V_188 -> V_209 ) ;
F_71 ( V_90 ) ;
return;
}
V_215:
F_81 ( V_2 ) ;
}
enum V_219 F_104 ( struct V_220 * V_221 )
{
struct V_7 * V_8 = F_105 ( V_221 , struct V_7 , V_222 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_210 , V_211 ;
for ( V_211 = F_99 ( V_2 -> V_196 ) ; ; V_211 = V_210 ) {
struct V_187 * V_188 ;
bool V_216 ;
if ( V_211 & V_218 )
break;
V_210 = ( V_211 & ~ V_217 ) | V_218 | V_202 ;
V_210 = F_83 ( & V_2 -> V_196 , V_211 , V_210 ) ;
if ( V_210 != V_211 )
continue;
if ( ! F_106 ( & V_2 -> V_213 ) )
break;
V_188 = F_100 ( & V_187 ) ;
V_216 = F_101 ( & V_188 -> V_193 ) ;
F_102 ( & V_8 -> V_194 , & V_188 -> V_193 ) ;
if ( V_216 )
F_103 ( & V_188 -> V_209 ) ;
break;
}
return V_223 ;
}
static bool F_107 ( const struct V_1 * V_2 )
{
return F_108 ( & V_2 -> V_224 ) == V_225 ;
}
static void F_109 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_10 V_226 ;
T_4 V_227 ;
if ( ! F_107 ( V_2 ) )
return;
V_227 = V_2 -> V_228 ;
if ( ! V_227 || V_227 == ~ 0U )
return;
V_226 = ( T_10 ) V_4 -> V_83 * V_229 ;
F_110 ( V_226 , V_227 ) ;
F_111 ( & F_3 ( V_2 ) -> V_222 ,
F_112 ( F_113 () , V_226 ) ,
V_230 ) ;
}
static int F_114 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_231 ,
T_11 V_232 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_233 * V_234 ;
struct V_7 * V_8 ;
struct V_235 * V_236 ;
struct V_100 V_101 ;
unsigned int V_237 , V_238 ;
struct V_3 * V_239 = NULL ;
struct V_144 * V_145 ;
struct V_78 * V_79 ;
int V_240 ;
F_115 ( ! V_4 || ! F_6 ( V_4 ) ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_231 ) {
F_5 ( V_4 ) -> V_241 . V_242 = F_5 ( V_4 ) -> V_12
- V_8 -> V_97 ;
V_239 = V_4 ;
if ( F_53 ( F_116 ( V_4 ) ) )
V_4 = F_117 ( V_4 , V_232 ) ;
else
V_4 = F_118 ( V_4 , V_232 ) ;
if ( F_53 ( ! V_4 ) )
return - V_243 ;
}
V_4 -> V_244 = V_8 -> V_245 ;
V_234 = F_119 ( V_2 ) ;
V_236 = F_5 ( V_4 ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
if ( F_53 ( V_236 -> V_65 & V_95 ) )
V_237 = F_56 ( V_2 , V_4 , & V_101 , & V_145 ) ;
else
V_237 = F_61 ( V_2 , V_4 , & V_101 ,
& V_145 ) ;
V_238 = V_237 + sizeof( struct V_78 ) ;
V_4 -> V_246 = F_120 ( V_2 ) < F_97 ( 1 ) ;
V_4 -> V_247 = 0 ;
F_121 ( V_4 , V_238 ) ;
F_122 ( V_4 ) ;
F_123 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_248 = F_124 ( V_4 ) ? V_249 : F_93 ;
F_125 ( V_4 , V_2 ) ;
F_126 ( V_4 -> V_212 , & V_2 -> V_213 ) ;
F_127 ( V_4 , V_2 -> V_250 ) ;
V_79 = (struct V_78 * ) V_4 -> V_186 ;
V_79 -> V_251 = V_234 -> V_252 ;
V_79 -> V_253 = V_234 -> V_254 ;
V_79 -> V_84 = F_54 ( V_236 -> V_84 ) ;
V_79 -> V_255 = F_54 ( V_8 -> V_61 ) ;
* ( ( ( V_256 * ) V_79 ) + 6 ) = F_128 ( ( ( V_238 >> 2 ) << 12 ) |
V_236 -> V_65 ) ;
V_79 -> V_257 = 0 ;
V_79 -> V_258 = 0 ;
if ( F_53 ( F_51 ( V_8 ) && F_11 ( V_236 -> V_84 , V_8 -> V_98 ) ) ) {
if ( F_11 ( V_8 -> V_98 , V_236 -> V_84 + 0x10000 ) ) {
V_79 -> V_258 = F_128 ( V_8 -> V_98 - V_236 -> V_84 ) ;
V_79 -> V_259 = 1 ;
} else if ( F_129 ( V_236 -> V_84 + 0xFFFF , V_8 -> V_11 ) ) {
V_79 -> V_258 = F_128 ( 0xFFFF ) ;
V_79 -> V_259 = 1 ;
}
}
F_52 ( ( T_8 * ) ( V_79 + 1 ) , V_8 , & V_101 ) ;
F_47 ( V_4 ) -> V_87 = V_2 -> V_260 ;
if ( F_55 ( ! ( V_236 -> V_65 & V_95 ) ) ) {
V_79 -> V_261 = F_128 ( F_32 ( V_2 ) ) ;
F_46 ( V_2 , V_4 , V_79 , V_238 ) ;
} else {
V_79 -> V_261 = F_128 ( F_20 ( V_8 -> V_46 , 65535U ) ) ;
}
#ifdef F_57
if ( V_145 ) {
F_130 ( V_2 , V_262 ) ;
V_8 -> V_151 -> V_263 ( V_101 . V_107 ,
V_145 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_206 -> V_264 ( V_2 , V_4 ) ;
if ( F_55 ( V_236 -> V_65 & V_265 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_83 != V_238 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_266 += F_6 ( V_4 ) ;
F_109 ( V_2 , V_4 ) ;
}
if ( F_129 ( V_236 -> V_12 , V_8 -> V_11 ) || V_236 -> V_84 == V_236 -> V_12 )
F_131 ( F_9 ( V_2 ) , V_267 ,
F_6 ( V_4 ) ) ;
V_8 -> V_268 += F_6 ( V_4 ) ;
F_47 ( V_4 ) -> V_269 = F_6 ( V_4 ) ;
F_47 ( V_4 ) -> V_270 = F_132 ( V_4 ) ;
V_4 -> V_271 = 0 ;
memset ( V_4 -> V_272 , 0 , F_21 ( sizeof( struct V_273 ) ,
sizeof( struct V_274 ) ) ) ;
V_240 = V_6 -> V_206 -> V_275 ( V_2 , V_4 , & V_234 -> V_276 . V_277 ) ;
if ( F_53 ( V_240 > 0 ) ) {
F_133 ( V_2 ) ;
V_240 = F_134 ( V_240 ) ;
}
if ( ! V_240 && V_239 ) {
V_239 -> V_244 = V_8 -> V_245 ;
F_135 ( V_2 , V_239 ) ;
}
return V_240 ;
}
static void F_136 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_278 = F_5 ( V_4 ) -> V_12 ;
F_137 ( V_4 ) ;
F_138 ( V_2 , V_4 ) ;
V_2 -> V_279 += V_4 -> V_212 ;
F_139 ( V_2 , V_4 -> V_212 ) ;
}
static void F_140 ( struct V_3 * V_4 , unsigned int V_280 )
{
if ( V_4 -> V_83 <= V_280 || V_4 -> V_91 == V_281 ) {
F_50 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_282 = 0 ;
} else {
F_50 ( V_4 , F_141 ( V_4 -> V_83 , V_280 ) ) ;
F_5 ( V_4 ) -> V_282 = V_280 ;
}
}
static void F_142 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_283 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_284 || F_143 ( V_8 ) )
return;
if ( F_129 ( F_144 ( V_8 ) , F_5 ( V_4 ) -> V_84 ) )
V_8 -> V_285 -= V_283 ;
}
static void F_145 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_283 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_283 ;
if ( F_5 ( V_4 ) -> V_94 & V_286 )
V_8 -> V_284 -= V_283 ;
if ( F_5 ( V_4 ) -> V_94 & V_287 )
V_8 -> V_183 -= V_283 ;
if ( F_5 ( V_4 ) -> V_94 & V_288 )
V_8 -> V_182 -= V_283 ;
if ( F_143 ( V_8 ) && V_283 > 0 )
V_8 -> V_284 -= F_31 ( T_4 , V_8 -> V_284 , V_283 ) ;
F_142 ( V_2 , V_4 , V_283 ) ;
if ( V_8 -> V_289 &&
F_11 ( F_5 ( V_4 ) -> V_84 , F_5 ( V_8 -> V_289 ) -> V_84 ) &&
( F_146 ( V_8 ) || ( F_5 ( V_4 ) -> V_94 & V_286 ) ) )
V_8 -> V_290 -= V_283 ;
F_147 ( V_8 ) ;
}
static bool F_148 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_291 ||
( F_47 ( V_4 ) -> V_292 & V_293 ) ;
}
static void F_149 ( struct V_3 * V_4 , struct V_3 * V_294 )
{
struct V_295 * V_296 = F_47 ( V_4 ) ;
if ( F_53 ( F_148 ( V_4 ) ) &&
! F_11 ( V_296 -> V_297 , F_5 ( V_294 ) -> V_84 ) ) {
struct V_295 * V_298 = F_47 ( V_294 ) ;
T_7 V_299 = V_296 -> V_292 & V_293 ;
V_296 -> V_292 &= ~ V_299 ;
V_298 -> V_292 |= V_299 ;
F_150 ( V_296 -> V_297 , V_298 -> V_297 ) ;
F_5 ( V_294 ) -> V_291 = F_5 ( V_4 ) -> V_291 ;
F_5 ( V_4 ) -> V_291 = 0 ;
}
}
static void F_151 ( struct V_3 * V_4 , struct V_3 * V_294 )
{
F_5 ( V_294 ) -> V_300 = F_5 ( V_4 ) -> V_300 ;
F_5 ( V_4 ) -> V_300 = 0 ;
}
int F_152 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_83 ,
unsigned int V_280 , T_11 V_301 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_302 ;
int V_303 , V_304 ;
int V_305 ;
T_7 V_90 ;
if ( F_94 ( V_83 > V_4 -> V_83 ) )
return - V_306 ;
V_303 = F_153 ( V_4 ) - V_83 ;
if ( V_303 < 0 )
V_303 = 0 ;
if ( F_154 ( V_4 , V_301 ) )
return - V_307 ;
V_302 = F_155 ( V_2 , V_303 , V_301 , true ) ;
if ( ! V_302 )
return - V_307 ;
V_2 -> V_279 += V_302 -> V_212 ;
F_139 ( V_2 , V_302 -> V_212 ) ;
V_305 = V_4 -> V_83 - V_83 - V_303 ;
V_302 -> V_212 += V_305 ;
V_4 -> V_212 -= V_305 ;
F_5 ( V_302 ) -> V_84 = F_5 ( V_4 ) -> V_84 + V_83 ;
F_5 ( V_302 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_302 ) -> V_84 ;
V_90 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_90 & ~ ( V_96 | V_308 ) ;
F_5 ( V_302 ) -> V_65 = V_90 ;
F_5 ( V_302 ) -> V_94 = F_5 ( V_4 ) -> V_94 ;
F_151 ( V_4 , V_302 ) ;
if ( ! F_47 ( V_4 ) -> V_309 && V_4 -> V_91 != V_92 ) {
V_302 -> V_93 = F_156 ( V_4 -> V_186 + V_83 ,
F_157 ( V_302 , V_303 ) ,
V_303 , 0 ) ;
F_158 ( V_4 , V_83 ) ;
V_4 -> V_93 = F_159 ( V_4 -> V_93 , V_302 -> V_93 , V_83 ) ;
} else {
V_4 -> V_91 = V_92 ;
F_160 ( V_4 , V_302 , V_83 ) ;
}
V_302 -> V_91 = V_4 -> V_91 ;
V_302 -> V_271 = V_4 -> V_271 ;
F_149 ( V_4 , V_302 ) ;
V_304 = F_6 ( V_4 ) ;
F_140 ( V_4 , V_280 ) ;
F_140 ( V_302 , V_280 ) ;
F_5 ( V_302 ) -> V_241 = F_5 ( V_4 ) -> V_241 ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_302 ) -> V_12 ) ) {
int V_310 = V_304 - F_6 ( V_4 ) -
F_6 ( V_302 ) ;
if ( V_310 )
F_145 ( V_2 , V_4 , V_310 ) ;
}
F_137 ( V_302 ) ;
F_161 ( V_4 , V_302 , V_2 ) ;
return 0 ;
}
static int F_162 ( struct V_3 * V_4 , int V_83 )
{
struct V_295 * V_296 ;
int V_208 , V_311 , V_312 ;
V_312 = F_31 ( int , V_83 , F_153 ( V_4 ) ) ;
if ( V_312 ) {
F_163 ( V_4 , V_312 ) ;
V_83 -= V_312 ;
if ( ! V_83 )
return 0 ;
}
V_312 = V_83 ;
V_311 = 0 ;
V_296 = F_47 ( V_4 ) ;
for ( V_208 = 0 ; V_208 < V_296 -> V_309 ; V_208 ++ ) {
int V_172 = F_164 ( & V_296 -> V_313 [ V_208 ] ) ;
if ( V_172 <= V_312 ) {
F_165 ( V_4 , V_208 ) ;
V_312 -= V_172 ;
} else {
V_296 -> V_313 [ V_311 ] = V_296 -> V_313 [ V_208 ] ;
if ( V_312 ) {
V_296 -> V_313 [ V_311 ] . V_314 += V_312 ;
F_166 ( & V_296 -> V_313 [ V_311 ] , V_312 ) ;
V_312 = 0 ;
}
V_311 ++ ;
}
}
V_296 -> V_309 = V_311 ;
V_4 -> V_315 -= V_83 ;
V_4 -> V_83 = V_4 -> V_315 ;
return V_83 ;
}
int F_167 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_83 )
{
T_4 V_316 ;
if ( F_154 ( V_4 , V_185 ) )
return - V_307 ;
V_316 = F_162 ( V_4 , V_83 ) ;
F_5 ( V_4 ) -> V_84 += V_83 ;
V_4 -> V_91 = V_92 ;
if ( V_316 ) {
V_4 -> V_212 -= V_316 ;
V_2 -> V_279 -= V_316 ;
F_168 ( V_2 , V_316 ) ;
F_169 ( V_2 , V_317 ) ;
}
if ( F_6 ( V_4 ) > 1 )
F_140 ( V_4 , F_132 ( V_4 ) ) ;
return 0 ;
}
static inline int F_170 ( struct V_1 * V_2 , int V_318 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_280 ;
V_280 = V_318 - V_6 -> V_206 -> V_319 - sizeof( struct V_78 ) ;
if ( V_6 -> V_206 -> V_320 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_171 ( V_20 ) )
V_280 -= V_6 -> V_206 -> V_320 ;
}
if ( V_280 > V_8 -> V_16 . V_321 )
V_280 = V_8 -> V_16 . V_321 ;
V_280 -= V_6 -> V_322 ;
if ( V_280 < 48 )
V_280 = 48 ;
return V_280 ;
}
int F_172 ( struct V_1 * V_2 , int V_318 )
{
return F_170 ( V_2 , V_318 ) -
( F_3 ( V_2 ) -> V_82 - sizeof( struct V_78 ) ) ;
}
int F_173 ( struct V_1 * V_2 , int V_21 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_323 ;
V_323 = V_21 +
V_8 -> V_82 +
V_6 -> V_322 +
V_6 -> V_206 -> V_319 ;
if ( V_6 -> V_206 -> V_320 ) {
const struct V_19 * V_20 = F_14 ( V_2 ) ;
if ( V_20 && F_171 ( V_20 ) )
V_323 += V_6 -> V_206 -> V_320 ;
}
return V_323 ;
}
void F_174 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_324 * V_324 = F_9 ( V_2 ) ;
V_6 -> V_325 . V_326 = V_324 -> V_72 . V_327 > 1 ;
V_6 -> V_325 . V_328 = V_8 -> V_16 . V_321 + sizeof( struct V_78 ) +
V_6 -> V_206 -> V_319 ;
V_6 -> V_325 . V_329 = F_173 ( V_2 , V_324 -> V_72 . V_330 ) ;
V_6 -> V_325 . V_331 = 0 ;
if ( V_6 -> V_325 . V_326 )
V_6 -> V_325 . V_332 = V_32 ;
}
unsigned int F_175 ( struct V_1 * V_2 , T_4 V_318 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_280 ;
if ( V_6 -> V_325 . V_328 > V_318 )
V_6 -> V_325 . V_328 = V_318 ;
V_280 = F_172 ( V_2 , V_318 ) ;
V_280 = F_176 ( V_8 , V_280 ) ;
V_6 -> V_333 = V_318 ;
if ( V_6 -> V_325 . V_326 )
V_280 = F_20 ( V_280 , F_172 ( V_2 , V_6 -> V_325 . V_329 ) ) ;
V_8 -> V_334 = V_280 ;
return V_280 ;
}
unsigned int F_66 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_19 * V_20 = F_14 ( V_2 ) ;
T_4 V_280 ;
unsigned int V_335 ;
struct V_100 V_101 ;
struct V_144 * V_145 ;
V_280 = V_8 -> V_334 ;
if ( V_20 ) {
T_4 V_323 = F_177 ( V_20 ) ;
if ( V_323 != F_2 ( V_2 ) -> V_333 )
V_280 = F_175 ( V_2 , V_323 ) ;
}
V_335 = F_61 ( V_2 , NULL , & V_101 , & V_145 ) +
sizeof( struct V_78 ) ;
if ( V_335 != V_8 -> V_82 ) {
int V_24 = ( int ) V_335 - V_8 -> V_82 ;
V_280 -= V_24 ;
}
return V_280 ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_336 == V_337 &&
V_2 -> V_338 && ! F_77 ( V_339 , & V_2 -> V_338 -> V_90 ) ) {
T_4 V_340 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_341 = F_21 ( V_8 -> V_33 , V_340 ) ;
if ( V_341 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_341 ) >> 1 ;
}
V_8 -> V_33 = 0 ;
}
V_8 -> V_31 = V_32 ;
}
static void F_179 ( struct V_1 * V_2 , bool V_342 )
{
const struct V_343 * V_344 = F_2 ( V_2 ) -> V_345 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_97 , V_8 -> V_346 ) ||
V_8 -> V_10 > V_8 -> V_347 ) {
V_8 -> V_347 = V_8 -> V_10 ;
V_8 -> V_346 = V_8 -> V_11 ;
V_8 -> V_342 = V_342 ;
}
if ( F_180 ( V_2 ) ) {
V_8 -> V_33 = 0 ;
V_8 -> V_31 = V_32 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_33 )
V_8 -> V_33 = V_8 -> V_10 ;
if ( V_348 &&
( T_3 ) ( V_32 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 &&
! V_344 -> V_349 )
F_178 ( V_2 ) ;
if ( ! F_181 ( V_2 ) && V_2 -> V_338 &&
F_77 ( V_339 , & V_2 -> V_338 -> V_90 ) &&
( 1 << V_2 -> V_176 ) & ( V_177 | V_180 ) )
F_182 ( V_2 , V_350 ) ;
}
}
static bool F_183 ( const struct V_7 * V_8 )
{
return F_129 ( V_8 -> V_351 , V_8 -> V_97 ) &&
! F_129 ( V_8 -> V_351 , V_8 -> V_11 ) ;
}
static void F_184 ( struct V_7 * V_8 , unsigned int V_280 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_83 < F_6 ( V_4 ) * V_280 )
V_8 -> V_351 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_185 ( bool V_352 , const struct V_7 * V_8 ,
int V_184 )
{
return V_352 &&
( ( V_184 & V_353 ) ||
( ! V_184 && V_8 -> V_10 && F_183 ( V_8 ) ) ) ;
}
T_4 F_186 ( const struct V_1 * V_2 , unsigned int V_280 ,
int V_354 )
{
T_4 V_355 , V_356 ;
V_355 = F_20 ( V_2 -> V_228 >> 10 ,
V_2 -> V_357 - 1 - V_358 ) ;
V_356 = F_30 ( T_4 , V_355 / V_280 , V_354 ) ;
return F_31 ( T_4 , V_356 , V_2 -> V_359 ) ;
}
static T_4 F_187 ( struct V_1 * V_2 , unsigned int V_280 )
{
const struct V_343 * V_344 = F_2 ( V_2 ) -> V_345 ;
T_4 V_360 = V_344 -> V_361 ? V_344 -> V_361 ( V_2 ) : 0 ;
return V_360 ? :
F_186 ( V_2 , V_280 , V_362 ) ;
}
static unsigned int F_188 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_280 ,
unsigned int V_363 ,
int V_184 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_352 , V_364 , V_261 , V_365 ;
V_261 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_84 ;
V_365 = V_280 * V_363 ;
if ( F_55 ( V_365 <= V_261 && V_4 != F_189 ( V_2 ) ) )
return V_365 ;
V_364 = F_20 ( V_4 -> V_83 , V_261 ) ;
if ( V_365 <= V_364 )
return V_365 ;
V_352 = V_364 % V_280 ;
if ( F_185 ( V_352 != 0 , V_8 , V_184 ) )
return V_364 - V_352 ;
return V_364 ;
}
static inline unsigned int F_190 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_242 , V_26 , V_366 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_96 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_242 = F_23 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_242 >= V_26 )
return 0 ;
V_366 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_366 , V_26 - V_242 ) ;
}
static int F_191 ( struct V_3 * V_4 , unsigned int V_280 )
{
int V_360 = F_6 ( V_4 ) ;
if ( ! V_360 || ( V_360 > 1 && F_132 ( V_4 ) != V_280 ) ) {
F_140 ( V_4 , V_280 ) ;
V_360 = F_6 ( V_4 ) ;
}
return V_360 ;
}
static inline bool F_192 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_367 , int V_184 )
{
if ( V_184 & V_368 )
return true ;
if ( F_51 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_96 ) )
return true ;
if ( ! F_185 ( V_4 -> V_83 < V_367 , V_8 , V_184 ) )
return true ;
return false ;
}
static bool F_193 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_367 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_83 > V_367 )
V_12 = F_5 ( V_4 ) -> V_84 + V_367 ;
return ! F_129 ( V_12 , F_12 ( V_8 ) ) ;
}
static int F_194 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_83 ,
unsigned int V_280 , T_11 V_301 )
{
struct V_3 * V_302 ;
int V_305 = V_4 -> V_83 - V_83 ;
T_7 V_90 ;
if ( V_4 -> V_83 != V_4 -> V_315 )
return F_152 ( V_2 , V_4 , V_83 , V_280 , V_301 ) ;
V_302 = F_155 ( V_2 , 0 , V_301 , true ) ;
if ( F_53 ( ! V_302 ) )
return - V_307 ;
V_2 -> V_279 += V_302 -> V_212 ;
F_139 ( V_2 , V_302 -> V_212 ) ;
V_302 -> V_212 += V_305 ;
V_4 -> V_212 -= V_305 ;
F_5 ( V_302 ) -> V_84 = F_5 ( V_4 ) -> V_84 + V_83 ;
F_5 ( V_302 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_302 ) -> V_84 ;
V_90 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_90 & ~ ( V_96 | V_308 ) ;
F_5 ( V_302 ) -> V_65 = V_90 ;
F_5 ( V_302 ) -> V_94 = 0 ;
F_151 ( V_4 , V_302 ) ;
V_302 -> V_91 = V_4 -> V_91 = V_92 ;
F_160 ( V_4 , V_302 , V_83 ) ;
F_149 ( V_4 , V_302 ) ;
F_140 ( V_4 , V_280 ) ;
F_140 ( V_302 , V_280 ) ;
F_137 ( V_302 ) ;
F_161 ( V_4 , V_302 , V_2 ) ;
return 0 ;
}
static bool F_195 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_342 , T_4 V_363 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_369 , V_370 , V_371 , V_372 , V_242 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_193 ;
int V_373 ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
goto V_374;
if ( V_6 -> V_336 >= V_375 )
goto V_374;
if ( ( T_3 ) ( V_32 - V_8 -> V_36 ) > 0 )
goto V_374;
V_242 = F_23 ( V_8 ) ;
F_115 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_242 ) ) ;
V_370 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_84 ;
V_371 = ( V_8 -> V_27 - V_242 ) * V_8 -> V_334 ;
V_372 = F_20 ( V_370 , V_371 ) ;
if ( V_372 >= V_363 * V_8 -> V_334 )
goto V_374;
if ( ( V_4 != F_189 ( V_2 ) ) && ( V_372 >= V_4 -> V_83 ) )
goto V_374;
V_373 = F_196 ( V_376 ) ;
if ( V_373 ) {
T_4 V_377 = F_20 ( V_8 -> V_378 , V_8 -> V_27 * V_8 -> V_334 ) ;
V_377 /= V_373 ;
if ( V_372 >= V_377 )
goto V_374;
} else {
if ( V_372 > F_197 ( V_8 ) * V_8 -> V_334 )
goto V_374;
}
V_193 = F_198 ( V_2 ) ;
V_369 = F_199 ( V_8 -> V_245 , V_193 -> V_244 ) ;
if ( V_369 < ( V_8 -> V_379 >> 4 ) )
goto V_374;
if ( V_371 < V_370 && V_371 <= V_4 -> V_83 )
* V_342 = true ;
return true ;
V_374:
return false ;
}
static inline void F_200 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_324 * V_324 = F_9 ( V_2 ) ;
T_4 V_380 ;
T_3 V_24 ;
V_380 = V_324 -> V_72 . V_381 ;
V_24 = V_32 - V_6 -> V_325 . V_332 ;
if ( F_53 ( V_24 >= V_380 * V_382 ) ) {
int V_21 = F_66 ( V_2 ) ;
V_6 -> V_325 . V_331 = 0 ;
V_6 -> V_325 . V_328 = V_8 -> V_16 . V_321 +
sizeof( struct V_78 ) +
V_6 -> V_206 -> V_319 ;
V_6 -> V_325 . V_329 = F_173 ( V_2 , V_21 ) ;
V_6 -> V_325 . V_332 = V_32 ;
}
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 , * V_383 , * V_384 ;
struct V_324 * V_324 = F_9 ( V_2 ) ;
int V_331 ;
int V_385 ;
int V_386 , V_83 ;
int V_280 ;
int V_380 ;
if ( F_55 ( ! V_6 -> V_325 . V_326 ||
V_6 -> V_325 . V_331 ||
F_2 ( V_2 ) -> V_336 != V_337 ||
V_8 -> V_27 < 11 ||
V_8 -> V_16 . V_174 || V_8 -> V_16 . V_125 ) )
return - 1 ;
V_280 = F_66 ( V_2 ) ;
V_331 = F_172 ( V_2 , ( V_6 -> V_325 . V_328 +
V_6 -> V_325 . V_329 ) >> 1 ) ;
V_385 = V_331 + ( V_8 -> V_387 + 1 ) * V_8 -> V_334 ;
V_380 = V_6 -> V_325 . V_328 - V_6 -> V_325 . V_329 ;
if ( V_331 > F_172 ( V_2 , V_6 -> V_325 . V_328 ) ||
V_380 < V_324 -> V_72 . V_388 ) {
F_200 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_278 - V_8 -> V_11 < V_385 )
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
V_383 = F_155 ( V_2 , V_331 , V_185 , false ) ;
if ( ! V_383 )
return - 1 ;
V_2 -> V_279 += V_383 -> V_212 ;
F_139 ( V_2 , V_383 -> V_212 ) ;
V_4 = F_181 ( V_2 ) ;
F_5 ( V_383 ) -> V_84 = F_5 ( V_4 ) -> V_84 ;
F_5 ( V_383 ) -> V_12 = F_5 ( V_4 ) -> V_84 + V_331 ;
F_5 ( V_383 ) -> V_65 = V_265 ;
F_5 ( V_383 ) -> V_94 = 0 ;
V_383 -> V_93 = 0 ;
V_383 -> V_91 = V_4 -> V_91 ;
F_202 ( V_383 , V_4 , V_2 ) ;
F_203 ( V_2 , V_4 , V_383 ) ;
V_83 = 0 ;
F_204 (skb, next, sk) {
V_386 = F_31 ( int , V_4 -> V_83 , V_331 - V_83 ) ;
if ( V_383 -> V_91 ) {
F_205 ( V_4 , 0 , F_157 ( V_383 , V_386 ) , V_386 ) ;
} else {
T_12 V_93 = F_206 ( V_4 , 0 ,
F_157 ( V_383 , V_386 ) ,
V_386 , 0 ) ;
V_383 -> V_93 = F_207 ( V_383 -> V_93 , V_93 , V_83 ) ;
}
if ( V_4 -> V_83 <= V_386 ) {
F_5 ( V_383 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_208 ( V_4 , V_2 ) ;
F_209 ( V_2 , V_4 ) ;
} else {
F_5 ( V_383 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_96 | V_308 ) ;
if ( ! F_47 ( V_4 ) -> V_309 ) {
F_210 ( V_4 , V_386 ) ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_211 ( V_4 -> V_186 ,
V_4 -> V_83 , 0 ) ;
} else {
F_162 ( V_4 , V_386 ) ;
F_140 ( V_4 , V_280 ) ;
}
F_5 ( V_4 ) -> V_84 += V_386 ;
}
V_83 += V_386 ;
if ( V_83 >= V_331 )
break;
}
F_191 ( V_383 , V_383 -> V_83 ) ;
if ( ! F_114 ( V_2 , V_383 , 1 , V_185 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_383 ) ;
V_6 -> V_325 . V_331 = F_173 ( V_2 , V_383 -> V_83 ) ;
V_8 -> V_389 . V_390 = F_5 ( V_383 ) -> V_84 ;
V_8 -> V_389 . V_391 = F_5 ( V_383 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_212 ( const struct V_1 * V_2 )
{
return F_107 ( V_2 ) &&
F_213 ( & F_3 ( V_2 ) -> V_222 ) ;
}
static bool F_214 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_392 )
{
unsigned int V_372 ;
V_372 = F_21 ( 2 * V_4 -> V_212 , V_2 -> V_228 >> 10 ) ;
V_372 = F_31 ( T_4 , V_372 , V_393 ) ;
V_372 <<= V_392 ;
if ( F_96 ( & V_2 -> V_213 ) > V_372 ) {
if ( V_4 == V_2 -> V_394 . V_384 ||
V_4 -> V_395 == V_2 -> V_394 . V_384 )
return false ;
F_215 ( V_396 , & V_2 -> V_196 ) ;
F_216 () ;
if ( F_96 ( & V_2 -> V_213 ) > V_372 )
return true ;
}
return false ;
}
static void F_217 ( struct V_7 * V_8 , const enum V_397 V_398 )
{
const T_4 V_34 = V_32 ;
enum V_397 V_399 = V_8 -> V_400 ;
if ( V_399 > V_401 )
V_8 -> V_402 [ V_399 - 1 ] += V_34 - V_8 -> V_403 ;
V_8 -> V_403 = V_34 ;
V_8 -> V_400 = V_398 ;
}
void F_182 ( struct V_1 * V_2 , const enum V_397 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( type > V_8 -> V_400 )
F_217 ( V_8 , type ) ;
}
void F_218 ( struct V_1 * V_2 , const enum V_397 type )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_219 ( V_2 ) )
F_217 ( V_8 , V_401 ) ;
else if ( type == V_8 -> V_400 )
F_217 ( V_8 , V_404 ) ;
}
static bool F_65 ( struct V_1 * V_2 , unsigned int V_280 , int V_184 ,
int V_405 , T_11 V_301 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_360 , V_406 ;
int V_407 ;
int V_408 ;
bool V_342 = false , V_409 = false ;
T_4 V_363 ;
V_406 = 0 ;
F_63 ( V_8 ) ;
if ( ! V_405 ) {
V_408 = F_201 ( V_2 ) ;
if ( ! V_408 ) {
return false ;
} else if ( V_408 > 0 ) {
V_406 = 1 ;
}
}
V_363 = F_187 ( V_2 , V_280 ) ;
while ( ( V_4 = F_181 ( V_2 ) ) ) {
unsigned int V_372 ;
if ( F_212 ( V_2 ) )
break;
V_360 = F_191 ( V_4 , V_280 ) ;
F_115 ( ! V_360 ) ;
if ( F_53 ( V_8 -> V_410 ) && V_8 -> V_411 == V_412 ) {
V_4 -> V_244 = V_8 -> V_245 ;
goto V_410;
}
V_407 = F_190 ( V_8 , V_4 ) ;
if ( ! V_407 ) {
if ( V_405 == 2 )
V_407 = 1 ;
else
break;
}
if ( F_53 ( ! F_193 ( V_8 , V_4 , V_280 ) ) ) {
V_409 = true ;
break;
}
if ( V_360 == 1 ) {
if ( F_53 ( ! F_192 ( V_8 , V_4 , V_280 ,
( F_220 ( V_2 , V_4 ) ?
V_184 : V_368 ) ) ) )
break;
} else {
if ( ! V_405 &&
F_195 ( V_2 , V_4 , & V_342 ,
V_363 ) )
break;
}
V_372 = V_280 ;
if ( V_360 > 1 && ! F_51 ( V_8 ) )
V_372 = F_188 ( V_2 , V_4 , V_280 ,
F_31 (unsigned int,
cwnd_quota,
max_segs) ,
V_184 ) ;
if ( V_4 -> V_83 > V_372 &&
F_53 ( F_194 ( V_2 , V_4 , V_372 , V_280 , V_301 ) ) )
break;
if ( F_77 ( V_199 , & V_2 -> V_196 ) )
F_76 ( V_199 , & V_2 -> V_196 ) ;
if ( F_214 ( V_2 , V_4 , 0 ) )
break;
if ( F_53 ( F_114 ( V_2 , V_4 , 1 , V_301 ) ) )
break;
V_410:
F_1 ( V_2 , V_4 ) ;
F_184 ( V_8 , V_280 , V_4 ) ;
V_406 += F_6 ( V_4 ) ;
if ( V_405 )
break;
}
if ( V_409 )
F_182 ( V_2 , V_413 ) ;
else
F_218 ( V_2 , V_413 ) ;
if ( F_55 ( V_406 ) ) {
if ( F_221 ( V_2 ) )
V_8 -> V_414 += V_406 ;
if ( V_405 != 2 )
F_222 ( V_2 ) ;
V_342 |= ( F_23 ( V_8 ) >= V_8 -> V_27 ) ;
F_179 ( V_2 , V_342 ) ;
return false ;
}
return ! V_8 -> V_10 && F_181 ( V_2 ) ;
}
bool F_222 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_415 , V_416 ;
if ( V_8 -> V_417 )
return false ;
if ( ( V_418 != 3 && V_418 != 4 ) ||
! V_8 -> V_10 || ! F_223 ( V_8 ) ||
V_6 -> V_336 != V_337 )
return false ;
if ( ( V_8 -> V_27 > F_23 ( V_8 ) ) &&
F_181 ( V_2 ) )
return false ;
if ( V_8 -> V_379 ) {
V_415 = F_224 ( V_8 -> V_379 >> 2 ) ;
if ( V_8 -> V_10 == 1 )
V_415 += V_419 ;
else
V_415 += V_420 ;
} else {
V_415 = V_421 ;
}
V_416 = F_225 ( V_2 ) ;
if ( V_416 > 0 )
V_415 = F_31 ( T_4 , V_415 , F_224 ( V_416 ) ) ;
F_226 ( V_2 , V_14 , V_415 ,
V_422 ) ;
return true ;
}
static bool F_227 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_53 ( F_228 ( V_2 , V_4 ) ) ) {
F_35 ( F_9 ( V_2 ) ,
V_423 ) ;
return true ;
}
return false ;
}
void F_229 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_424 ;
int V_21 = F_66 ( V_2 ) ;
V_4 = F_181 ( V_2 ) ;
if ( V_4 ) {
if ( F_193 ( V_8 , V_4 , V_21 ) ) {
V_424 = V_8 -> V_10 ;
F_65 ( V_2 , V_21 , V_425 , 2 , V_185 ) ;
if ( V_8 -> V_10 > V_424 )
goto V_426;
goto V_427;
}
V_4 = F_230 ( V_2 , V_4 ) ;
} else {
V_4 = F_189 ( V_2 ) ;
}
if ( V_8 -> V_428 )
goto V_427;
if ( F_94 ( ! V_4 ) )
goto V_427;
if ( F_227 ( V_2 , V_4 ) )
goto V_427;
V_424 = F_6 ( V_4 ) ;
if ( F_94 ( ! V_424 ) )
goto V_427;
if ( ( V_424 > 1 ) && ( V_4 -> V_83 > ( V_424 - 1 ) * V_21 ) ) {
if ( F_53 ( F_152 ( V_2 , V_4 , ( V_424 - 1 ) * V_21 , V_21 ,
V_185 ) ) )
goto V_427;
V_4 = F_231 ( V_2 , V_4 ) ;
}
if ( F_94 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_427;
if ( F_232 ( V_2 , V_4 , 1 ) )
goto V_427;
V_8 -> V_428 = V_8 -> V_11 ;
V_426:
F_35 ( F_9 ( V_2 ) , V_429 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_427:
F_7 ( V_2 ) ;
}
void F_233 ( struct V_1 * V_2 , unsigned int V_367 ,
int V_184 )
{
if ( F_53 ( V_2 -> V_176 == V_430 ) )
return;
if ( F_65 ( V_2 , V_367 , V_184 , 0 ,
F_234 ( V_2 , V_185 ) ) )
F_235 ( V_2 ) ;
}
void F_236 ( struct V_1 * V_2 , unsigned int V_280 )
{
struct V_3 * V_4 = F_181 ( V_2 ) ;
F_115 ( ! V_4 || V_4 -> V_83 < V_280 ) ;
F_65 ( V_2 , V_280 , V_368 , 1 , V_2 -> V_431 ) ;
}
T_4 F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_21 = V_6 -> V_37 . V_432 ;
int V_433 = F_237 ( V_2 ) ;
int V_434 = F_238 ( V_2 ) ;
int V_435 = F_31 ( int , V_8 -> V_47 , V_434 ) ;
int V_261 ;
if ( F_53 ( V_21 > V_435 ) ) {
V_21 = V_435 ;
if ( V_21 <= 0 )
return 0 ;
}
if ( V_433 < ( V_435 >> 1 ) ) {
V_6 -> V_37 . V_436 = 0 ;
if ( F_239 ( V_2 ) )
V_8 -> V_437 = F_20 ( V_8 -> V_437 ,
4U * V_8 -> V_22 ) ;
V_433 = F_240 ( V_433 , 1 << V_8 -> V_16 . V_18 ) ;
if ( V_433 < ( V_434 >> 4 ) || V_433 < V_21 )
return 0 ;
}
if ( V_433 > V_8 -> V_437 )
V_433 = V_8 -> V_437 ;
if ( V_8 -> V_16 . V_18 ) {
V_261 = V_433 ;
V_261 = F_36 ( V_261 , ( 1 << V_8 -> V_16 . V_18 ) ) ;
} else {
V_261 = V_8 -> V_46 ;
if ( V_261 <= V_433 - V_21 || V_261 > V_433 )
V_261 = F_29 ( V_433 , V_21 ) ;
else if ( V_21 == V_435 &&
V_433 > V_261 + ( V_435 >> 1 ) )
V_261 = V_433 ;
}
return V_261 ;
}
void F_241 ( struct V_3 * V_4 ,
const struct V_3 * V_438 )
{
if ( F_53 ( F_148 ( V_438 ) ) ) {
const struct V_295 * V_439 =
F_47 ( V_438 ) ;
struct V_295 * V_296 = F_47 ( V_4 ) ;
V_296 -> V_292 |= V_439 -> V_292 & V_293 ;
V_296 -> V_297 = V_439 -> V_297 ;
F_5 ( V_4 ) -> V_291 |=
F_5 ( V_438 ) -> V_291 ;
}
}
static bool F_242 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_438 = F_231 ( V_2 , V_4 ) ;
int V_440 , V_441 ;
V_440 = V_4 -> V_83 ;
V_441 = V_438 -> V_83 ;
F_115 ( F_6 ( V_4 ) != 1 || F_6 ( V_438 ) != 1 ) ;
if ( V_441 ) {
if ( V_441 <= F_243 ( V_4 ) )
F_205 ( V_438 , 0 , F_157 ( V_4 , V_441 ) ,
V_441 ) ;
else if ( ! F_244 ( V_4 , V_438 , V_441 ) )
return false ;
}
F_203 ( V_2 , V_438 , V_4 ) ;
F_208 ( V_438 , V_2 ) ;
if ( V_438 -> V_91 == V_92 )
V_4 -> V_91 = V_92 ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_207 ( V_4 -> V_93 , V_438 -> V_93 , V_440 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_438 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_438 ) -> V_65 ;
F_5 ( V_4 ) -> V_94 |= F_5 ( V_438 ) -> V_94 & V_442 ;
F_5 ( V_4 ) -> V_300 = F_5 ( V_438 ) -> V_300 ;
F_245 ( V_8 ) ;
if ( V_438 == V_8 -> V_443 )
V_8 -> V_443 = V_4 ;
F_145 ( V_2 , V_438 , F_6 ( V_438 ) ) ;
F_241 ( V_4 , V_438 ) ;
F_209 ( V_2 , V_438 ) ;
return true ;
}
static bool F_246 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_116 ( V_4 ) )
return false ;
if ( V_4 == F_181 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_94 & V_286 )
return false ;
return true ;
}
static void F_247 ( struct V_1 * V_2 , struct V_3 * V_444 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_444 , * V_445 ;
bool V_446 = true ;
if ( ! V_447 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
return;
F_204 (skb, tmp, sk) {
if ( ! F_246 ( V_2 , V_4 ) )
break;
if ( ! F_248 ( V_444 ) )
break;
V_49 -= V_4 -> V_83 ;
if ( V_446 ) {
V_446 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( F_129 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
if ( ! F_242 ( V_2 , V_444 ) )
break;
}
}
int F_232 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_356 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_367 ;
int V_310 , V_83 , V_240 ;
if ( V_6 -> V_325 . V_331 )
V_6 -> V_325 . V_331 = 0 ;
if ( F_96 ( & V_2 -> V_213 ) >
F_31 ( T_4 , V_2 -> V_279 + ( V_2 -> V_279 >> 2 ) ,
V_2 -> V_448 ) )
return - V_449 ;
if ( F_227 ( V_2 , V_4 ) )
return - V_450 ;
if ( F_11 ( F_5 ( V_4 ) -> V_84 , V_8 -> V_97 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_97 ) )
F_249 () ;
if ( F_167 ( V_2 , V_4 , V_8 -> V_97 - F_5 ( V_4 ) -> V_84 ) )
return - V_307 ;
}
if ( F_2 ( V_2 ) -> V_206 -> V_451 ( V_2 ) )
return - V_452 ;
V_367 = F_66 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_84 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_84 != V_8 -> V_97 )
return - V_449 ;
V_83 = V_367 * V_356 ;
if ( V_4 -> V_83 > V_83 ) {
if ( F_152 ( V_2 , V_4 , V_83 , V_367 , V_185 ) )
return - V_307 ;
} else {
if ( F_154 ( V_4 , V_185 ) )
return - V_307 ;
V_310 = F_6 ( V_4 ) ;
F_140 ( V_4 , V_367 ) ;
V_310 -= F_6 ( V_4 ) ;
if ( V_310 )
F_145 ( V_2 , V_4 , V_310 ) ;
if ( V_4 -> V_83 < V_367 )
F_247 ( V_2 , V_4 , V_367 ) ;
}
if ( ( F_5 ( V_4 ) -> V_65 & V_453 ) == V_453 )
F_43 ( V_2 , V_4 ) ;
V_356 = F_6 ( V_4 ) ;
F_131 ( F_9 ( V_2 ) , V_454 , V_356 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
F_250 ( F_9 ( V_2 ) , V_455 ) ;
V_8 -> V_456 += V_356 ;
if ( F_53 ( ( V_457 && ( ( unsigned long ) V_4 -> V_186 & 3 ) ) ||
F_251 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_383 ;
V_383 = F_252 ( V_4 , V_358 , V_185 ) ;
V_240 = V_383 ? F_114 ( V_2 , V_383 , 0 , V_185 ) :
- V_243 ;
if ( ! V_240 ) {
V_4 -> V_244 = V_8 -> V_245 ;
F_135 ( V_2 , V_4 ) ;
}
} else {
V_240 = F_114 ( V_2 , V_4 , 1 , V_185 ) ;
}
if ( F_55 ( ! V_240 ) ) {
F_5 ( V_4 ) -> V_94 |= V_442 ;
} else if ( V_240 != - V_450 ) {
F_35 ( F_9 ( V_2 ) , V_458 ) ;
}
return V_240 ;
}
int F_253 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_356 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_240 = F_232 ( V_2 , V_4 , V_356 ) ;
if ( V_240 == 0 ) {
#if V_459 > 0
if ( F_5 ( V_4 ) -> V_94 & V_287 ) {
F_254 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_94 |= V_460 ;
V_8 -> V_183 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_461 )
V_8 -> V_461 = F_58 ( V_4 ) ;
}
if ( V_8 -> V_462 < 0 )
V_8 -> V_462 = 0 ;
V_8 -> V_462 += F_6 ( V_4 ) ;
return V_240 ;
}
void F_64 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_463 = NULL ;
T_4 V_363 ;
int V_464 ;
if ( ! V_8 -> V_10 )
return;
if ( V_8 -> V_443 ) {
V_4 = V_8 -> V_443 ;
} else {
V_4 = F_198 ( V_2 ) ;
}
V_363 = F_187 ( V_2 , F_66 ( V_2 ) ) ;
F_255 (skb, sk) {
T_5 V_94 ;
int V_356 ;
if ( V_4 == F_181 ( V_2 ) )
break;
if ( F_212 ( V_2 ) )
break;
if ( ! V_463 )
V_8 -> V_443 = V_4 ;
V_356 = V_8 -> V_27 - F_23 ( V_8 ) ;
if ( V_356 <= 0 )
return;
V_94 = F_5 ( V_4 ) -> V_94 ;
V_356 = F_31 ( int , V_356 , V_363 ) ;
if ( V_8 -> V_183 >= V_8 -> V_182 ) {
break;
} else if ( ! ( V_94 & V_288 ) ) {
if ( ! V_463 && ! ( V_94 & ( V_287 | V_286 ) ) )
V_463 = V_4 ;
continue;
} else {
if ( V_6 -> V_336 != V_465 )
V_464 = V_466 ;
else
V_464 = V_467 ;
}
if ( V_94 & ( V_286 | V_287 ) )
continue;
if ( F_214 ( V_2 , V_4 , 1 ) )
return;
if ( F_253 ( V_2 , V_4 , V_356 ) )
return;
F_8 ( F_9 ( V_2 ) , V_464 , F_6 ( V_4 ) ) ;
if ( F_221 ( V_2 ) )
V_8 -> V_414 += F_6 ( V_4 ) ;
if ( V_4 == F_198 ( V_2 ) &&
V_6 -> V_13 != V_468 )
F_226 ( V_2 , V_469 ,
F_2 ( V_2 ) -> V_30 ,
V_422 ) ;
}
}
void F_256 ( struct V_1 * V_2 , int V_172 )
{
int V_470 ;
if ( V_172 <= V_2 -> V_471 )
return;
V_470 = F_257 ( V_172 ) ;
V_2 -> V_471 += V_470 * V_472 ;
F_258 ( V_2 , V_470 ) ;
if ( V_473 && V_2 -> V_474 )
F_259 ( V_2 -> V_474 , V_470 ) ;
}
void F_260 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_475 = F_189 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_475 && ( F_181 ( V_2 ) || F_239 ( V_2 ) ) ) {
V_476:
F_5 ( V_475 ) -> V_65 |= V_96 ;
F_5 ( V_475 ) -> V_12 ++ ;
V_8 -> V_278 ++ ;
if ( ! F_181 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_261 ( V_358 , V_2 -> V_431 ) ;
if ( F_53 ( ! V_4 ) ) {
if ( V_475 )
goto V_476;
return;
}
F_262 ( V_4 , V_358 ) ;
F_256 ( V_2 , V_4 -> V_212 ) ;
F_49 ( V_4 , V_8 -> V_278 ,
V_265 | V_96 ) ;
F_136 ( V_2 , V_4 ) ;
}
F_233 ( V_2 , F_66 ( V_2 ) , V_425 ) ;
}
void F_263 ( struct V_1 * V_2 , T_11 V_477 )
{
struct V_3 * V_4 ;
F_264 ( F_9 ( V_2 ) , V_478 ) ;
V_4 = F_265 ( V_358 , V_477 ) ;
if ( ! V_4 ) {
F_35 ( F_9 ( V_2 ) , V_479 ) ;
return;
}
F_262 ( V_4 , V_358 ) ;
F_49 ( V_4 , F_10 ( V_2 ) ,
V_265 | V_480 ) ;
F_63 ( F_3 ( V_2 ) ) ;
if ( F_114 ( V_2 , V_4 , 0 , V_477 ) )
F_35 ( F_9 ( V_2 ) , V_479 ) ;
}
int F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_198 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_65 & V_95 ) ) {
F_267 ( L_2 , V_481 ) ;
return - V_482 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_265 ) ) {
if ( F_116 ( V_4 ) ) {
struct V_3 * V_383 = F_268 ( V_4 , V_185 ) ;
if ( ! V_383 )
return - V_307 ;
F_208 ( V_4 , V_2 ) ;
F_137 ( V_383 ) ;
F_269 ( V_2 , V_383 ) ;
F_209 ( V_2 , V_4 ) ;
V_2 -> V_279 += V_383 -> V_212 ;
F_139 ( V_2 , V_383 -> V_212 ) ;
V_4 = V_383 ;
}
F_5 ( V_4 ) -> V_65 |= V_265 ;
F_37 ( V_2 , V_4 ) ;
}
return F_114 ( V_2 , V_4 , 1 , V_185 ) ;
}
struct V_3 * F_270 ( const struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_76 * V_77 ,
struct V_134 * V_135 ,
enum V_483 V_484 )
{
struct V_167 * V_168 = F_45 ( V_77 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_144 * V_145 = NULL ;
struct V_100 V_101 ;
struct V_3 * V_4 ;
int V_238 ;
struct V_78 * V_79 ;
int V_21 ;
V_4 = F_265 ( V_358 , V_185 ) ;
if ( F_53 ( ! V_4 ) ) {
F_271 ( V_20 ) ;
return NULL ;
}
F_262 ( V_4 , V_358 ) ;
switch ( V_484 ) {
case V_485 :
F_272 ( V_4 , F_273 ( V_77 ) ) ;
break;
case V_486 :
break;
case V_487 :
F_272 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_274 ( V_4 , V_20 ) ;
V_21 = F_275 ( V_8 , F_15 ( V_20 ) ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
#ifdef F_276
if ( F_53 ( V_77 -> V_488 ) )
V_4 -> V_244 = F_277 ( V_77 ) ;
else
#endif
V_4 -> V_244 = F_278 () ;
#ifdef F_57
F_279 () ;
V_145 = F_60 ( V_77 ) -> V_151 -> V_489 ( V_2 , F_273 ( V_77 ) ) ;
#endif
F_280 ( V_4 , F_60 ( V_77 ) -> V_490 , V_491 ) ;
V_238 = F_59 ( V_77 , V_21 , V_4 , & V_101 , V_145 , V_135 ) +
sizeof( * V_79 ) ;
F_121 ( V_4 , V_238 ) ;
F_122 ( V_4 ) ;
V_79 = (struct V_78 * ) V_4 -> V_186 ;
memset ( V_79 , 0 , sizeof( struct V_78 ) ) ;
V_79 -> V_492 = 1 ;
V_79 -> V_493 = 1 ;
F_44 ( V_77 , V_79 ) ;
V_79 -> V_251 = F_128 ( V_168 -> V_494 ) ;
V_79 -> V_253 = V_168 -> V_495 ;
V_4 -> V_496 = V_168 -> V_497 ;
V_4 -> V_91 = V_92 ;
V_79 -> V_84 = F_54 ( F_60 ( V_77 ) -> V_498 ) ;
V_79 -> V_255 = F_54 ( F_60 ( V_77 ) -> V_61 ) ;
V_79 -> V_261 = F_128 ( F_20 ( V_77 -> V_499 , 65535U ) ) ;
F_52 ( ( T_8 * ) ( V_79 + 1 ) , NULL , & V_101 ) ;
V_79 -> V_500 = ( V_238 >> 2 ) ;
F_281 ( F_9 ( V_2 ) , V_267 ) ;
#ifdef F_57
if ( V_145 )
F_60 ( V_77 ) -> V_151 -> V_263 ( V_101 . V_107 ,
V_145 , F_273 ( V_77 ) , V_4 ) ;
F_282 () ;
#endif
V_4 -> V_271 = 0 ;
return V_4 ;
}
static void F_283 ( struct V_1 * V_2 , const struct V_19 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_343 * V_501 ;
T_4 V_502 = F_284 ( V_20 , V_503 ) ;
if ( V_502 == V_504 )
return;
F_279 () ;
V_501 = F_285 ( V_502 ) ;
if ( F_55 ( V_501 && F_286 ( V_501 -> V_505 ) ) ) {
F_287 ( V_6 -> V_345 -> V_505 ) ;
V_6 -> V_506 = F_288 ( V_20 ) ;
V_6 -> V_345 = V_501 ;
}
F_282 () ;
}
static void F_289 ( struct V_1 * V_2 )
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
if ( V_8 -> V_16 . V_507 )
V_8 -> V_16 . V_321 = V_8 -> V_16 . V_507 ;
V_8 -> V_508 = 0 ;
F_174 ( V_2 ) ;
F_175 ( V_2 , F_177 ( V_20 ) ) ;
F_283 ( V_2 , V_20 ) ;
if ( ! V_8 -> V_47 )
V_8 -> V_47 = F_284 ( V_20 , V_509 ) ;
V_8 -> V_22 = F_275 ( V_8 , F_15 ( V_20 ) ) ;
F_290 ( V_2 ) ;
if ( V_2 -> V_510 & V_511 &&
( V_8 -> V_47 > F_238 ( V_2 ) || V_8 -> V_47 == 0 ) )
V_8 -> V_47 = F_238 ( V_2 ) ;
V_46 = F_291 ( V_2 ) ;
if ( V_46 == 0 )
V_46 = F_284 ( V_20 , V_512 ) ;
F_28 ( F_238 ( V_2 ) ,
V_8 -> V_22 - ( V_8 -> V_16 . V_513 ? V_8 -> V_82 - sizeof( struct V_78 ) : 0 ) ,
& V_8 -> V_46 ,
& V_8 -> V_47 ,
F_9 ( V_2 ) -> V_72 . V_159 ,
& V_18 ,
V_46 ) ;
V_8 -> V_16 . V_18 = V_18 ;
V_8 -> V_437 = V_8 -> V_46 ;
V_2 -> V_514 = 0 ;
F_292 ( V_2 , V_515 ) ;
V_8 -> V_378 = 0 ;
F_293 ( V_8 , 0 ) ;
V_8 -> V_97 = V_8 -> V_278 ;
V_8 -> V_351 = V_8 -> V_278 ;
V_8 -> V_98 = V_8 -> V_278 ;
V_8 -> V_11 = V_8 -> V_278 ;
if ( F_55 ( ! V_8 -> V_410 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_516 = V_32 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_517 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = F_294 ( V_2 ) ;
F_2 ( V_2 ) -> V_518 = 0 ;
F_295 ( V_8 ) ;
}
static void F_296 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_235 * V_236 = F_5 ( V_4 ) ;
V_236 -> V_12 += V_4 -> V_83 ;
F_137 ( V_4 ) ;
F_297 ( V_2 , V_4 ) ;
V_2 -> V_279 += V_4 -> V_212 ;
F_139 ( V_2 , V_4 -> V_212 ) ;
V_8 -> V_278 = V_236 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_298 ( struct V_1 * V_2 , struct V_3 * V_492 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_148 * V_519 = V_8 -> V_150 ;
int V_49 , V_240 = 0 ;
struct V_3 * V_520 ;
V_8 -> V_16 . V_321 = V_8 -> V_22 ;
if ( ! F_299 ( V_2 , & V_8 -> V_16 . V_321 , & V_519 -> V_163 ) )
goto V_521;
V_8 -> V_16 . V_321 = F_275 ( V_8 , V_8 -> V_16 . V_321 ) ;
V_49 = F_170 ( V_2 , F_2 ( V_2 ) -> V_333 ) -
V_147 ;
V_49 = F_31 ( V_522 , V_49 , V_519 -> V_172 ) ;
V_49 = F_31 ( V_522 , V_49 , F_300 ( V_358 ) ) ;
V_520 = F_155 ( V_2 , V_49 , V_2 -> V_431 , false ) ;
if ( ! V_520 )
goto V_521;
V_520 -> V_91 = V_92 ;
memcpy ( V_520 -> V_272 , V_492 -> V_272 , sizeof( V_492 -> V_272 ) ) ;
if ( V_49 ) {
int V_523 = F_301 ( F_157 ( V_520 , V_49 ) , V_49 ,
& V_519 -> V_186 -> V_524 ) ;
if ( F_53 ( ! V_523 ) ) {
F_302 ( V_520 ) ;
goto V_521;
}
if ( V_523 != V_49 ) {
F_158 ( V_520 , V_523 ) ;
V_49 = V_523 ;
}
}
if ( V_49 == V_519 -> V_172 )
V_519 -> V_186 = NULL ;
V_519 -> V_523 = V_49 ;
F_296 ( V_2 , V_520 ) ;
if ( V_520 -> V_83 )
F_182 ( V_2 , V_404 ) ;
V_240 = F_114 ( V_2 , V_520 , 1 , V_2 -> V_431 ) ;
V_492 -> V_244 = V_520 -> V_244 ;
F_5 ( V_520 ) -> V_84 ++ ;
F_5 ( V_520 ) -> V_65 = V_265 | V_308 ;
if ( ! V_240 ) {
V_8 -> V_520 = ( V_519 -> V_523 > 0 ) ;
F_35 ( F_9 ( V_2 ) , V_15 ) ;
goto V_525;
}
V_2 -> V_526 = V_520 ;
V_8 -> V_10 -= F_6 ( V_520 ) ;
V_521:
if ( V_519 -> V_163 . V_83 > 0 )
V_519 -> V_163 . V_83 = 0 ;
V_240 = F_114 ( V_2 , V_492 , 1 , V_2 -> V_431 ) ;
if ( V_240 )
V_8 -> V_165 = 0 ;
V_525:
V_519 -> V_163 . V_83 = - 1 ;
return V_240 ;
}
int F_303 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_302 ;
int V_240 ;
F_304 ( V_2 , V_527 ) ;
if ( F_2 ( V_2 ) -> V_206 -> V_451 ( V_2 ) )
return - V_452 ;
F_289 ( V_2 ) ;
if ( F_53 ( V_8 -> V_410 ) ) {
F_305 ( V_2 , NULL ) ;
return 0 ;
}
V_302 = F_155 ( V_2 , 0 , V_2 -> V_431 , true ) ;
if ( F_53 ( ! V_302 ) )
return - V_243 ;
F_49 ( V_302 , V_8 -> V_278 ++ , V_95 ) ;
F_63 ( V_8 ) ;
V_8 -> V_461 = F_306 ( V_8 ) ;
F_296 ( V_2 , V_302 ) ;
F_41 ( V_2 , V_302 ) ;
V_240 = V_8 -> V_150 ? F_298 ( V_2 , V_302 ) :
F_114 ( V_2 , V_302 , 1 , V_2 -> V_431 ) ;
if ( V_240 == - V_528 )
return V_240 ;
V_8 -> V_11 = V_8 -> V_278 ;
V_8 -> V_529 = V_8 -> V_278 ;
V_302 = F_181 ( V_2 ) ;
if ( F_53 ( V_302 ) ) {
V_8 -> V_11 = F_5 ( V_302 ) -> V_84 ;
V_8 -> V_529 = F_5 ( V_302 ) -> V_84 ;
}
F_264 ( F_9 ( V_2 ) , V_530 ) ;
F_226 ( V_2 , V_469 ,
F_2 ( V_2 ) -> V_30 , V_422 ) ;
return 0 ;
}
void F_307 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_39 = V_6 -> V_37 . V_39 ;
unsigned long V_415 ;
F_18 ( V_2 , V_531 ) ;
if ( V_39 > V_532 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_533 = V_382 / 2 ;
if ( V_6 -> V_37 . V_40 ||
( V_6 -> V_37 . V_534 & V_535 ) )
V_533 = V_536 ;
if ( V_8 -> V_379 ) {
int V_537 = F_30 ( int , F_224 ( V_8 -> V_379 >> 3 ) ,
V_532 ) ;
if ( V_537 < V_533 )
V_533 = V_537 ;
}
V_39 = F_20 ( V_39 , V_533 ) ;
}
V_415 = V_538 + V_39 ;
if ( V_6 -> V_37 . V_534 & V_539 ) {
if ( V_6 -> V_37 . V_540 ||
F_308 ( V_6 -> V_37 . V_415 , V_538 + ( V_39 >> 2 ) ) ) {
F_309 ( V_2 ) ;
return;
}
if ( ! F_310 ( V_415 , V_6 -> V_37 . V_415 ) )
V_415 = V_6 -> V_37 . V_415 ;
}
V_6 -> V_37 . V_534 |= V_541 | V_539 ;
V_6 -> V_37 . V_415 = V_415 ;
F_311 ( V_2 , & V_6 -> V_542 , V_415 ) ;
}
void F_309 ( struct V_1 * V_2 )
{
struct V_3 * V_302 ;
if ( V_2 -> V_176 == V_430 )
return;
F_18 ( V_2 , V_543 ) ;
V_302 = F_265 ( V_358 ,
F_234 ( V_2 , V_185 | V_544 ) ) ;
if ( F_53 ( ! V_302 ) ) {
F_312 ( V_2 ) ;
F_2 ( V_2 ) -> V_37 . V_39 = V_545 ;
F_226 ( V_2 , V_42 ,
V_536 , V_422 ) ;
return;
}
F_262 ( V_302 , V_358 ) ;
F_49 ( V_302 , F_10 ( V_2 ) , V_265 ) ;
F_313 ( V_302 ) ;
F_114 ( V_2 , V_302 , 0 , ( V_546 T_11 ) 0 ) ;
}
static int F_314 ( struct V_1 * V_2 , int V_547 , int V_548 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_265 ( V_358 ,
F_234 ( V_2 , V_185 | V_544 ) ) ;
if ( ! V_4 )
return - 1 ;
F_262 ( V_4 , V_358 ) ;
F_49 ( V_4 , V_8 -> V_97 - ! V_547 , V_265 ) ;
F_35 ( F_9 ( V_2 ) , V_548 ) ;
return F_114 ( V_2 , V_4 , 0 , ( V_546 T_11 ) 0 ) ;
}
void F_315 ( struct V_1 * V_2 )
{
if ( V_2 -> V_176 == V_549 ) {
F_3 ( V_2 ) -> V_550 = F_3 ( V_2 ) -> V_61 - 1 ;
F_63 ( F_3 ( V_2 ) ) ;
F_314 ( V_2 , 0 , V_551 ) ;
}
}
int F_316 ( struct V_1 * V_2 , int V_548 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_176 == V_430 )
return - 1 ;
V_4 = F_181 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_84 , F_12 ( V_8 ) ) ) {
int V_240 ;
unsigned int V_21 = F_66 ( V_2 ) ;
unsigned int V_552 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_84 ;
if ( F_11 ( V_8 -> V_529 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_529 = F_5 ( V_4 ) -> V_12 ;
if ( V_552 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_84 ||
V_4 -> V_83 > V_21 ) {
V_552 = F_20 ( V_552 , V_21 ) ;
F_5 ( V_4 ) -> V_65 |= V_308 ;
if ( F_152 ( V_2 , V_4 , V_552 , V_21 , V_185 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_140 ( V_4 , V_21 ) ;
F_5 ( V_4 ) -> V_65 |= V_308 ;
V_240 = F_114 ( V_2 , V_4 , 1 , V_185 ) ;
if ( ! V_240 )
F_1 ( V_2 , V_4 ) ;
return V_240 ;
} else {
if ( F_317 ( V_8 -> V_98 , V_8 -> V_97 + 1 , V_8 -> V_97 + 0xFFFF ) )
F_314 ( V_2 , 1 , V_548 ) ;
return F_314 ( V_2 , 0 , V_548 ) ;
}
}
void F_318 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_324 * V_324 = F_9 ( V_2 ) ;
unsigned long V_553 ;
int V_240 ;
V_240 = F_316 ( V_2 , V_551 ) ;
if ( V_8 -> V_10 || ! F_181 ( V_2 ) ) {
V_6 -> V_554 = 0 ;
V_6 -> V_555 = 0 ;
return;
}
if ( V_240 <= 0 ) {
if ( V_6 -> V_555 < V_324 -> V_72 . V_556 )
V_6 -> V_555 ++ ;
V_6 -> V_554 ++ ;
V_553 = V_422 ;
} else {
if ( ! V_6 -> V_554 )
V_6 -> V_554 = 1 ;
V_553 = V_557 ;
}
F_226 ( V_2 , V_558 ,
F_319 ( V_2 , V_553 ) ,
V_422 ) ;
}
int F_320 ( const struct V_1 * V_2 , struct V_76 * V_77 )
{
const struct V_559 * V_560 = F_60 ( V_77 ) -> V_151 ;
struct V_561 V_277 ;
int V_562 ;
F_60 ( V_77 ) -> V_490 = F_321 () ;
V_562 = V_560 -> V_563 ( V_2 , NULL , & V_277 , V_77 , NULL , V_485 ) ;
if ( ! V_562 ) {
F_281 ( F_9 ( V_2 ) , V_454 ) ;
F_250 ( F_9 ( V_2 ) , V_455 ) ;
if ( F_53 ( F_322 ( V_2 ) ) )
F_3 ( V_2 ) -> V_456 ++ ;
}
return V_562 ;
}
