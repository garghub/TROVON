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
V_49 = F_29 ( T_4 , V_52 [ 2 ] , V_53 ) ;
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
int V_80 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_66 & V_67 ) {
if ( V_4 -> V_81 != V_80 &&
! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_11 ) ) {
F_38 ( V_2 ) ;
if ( V_8 -> V_66 & V_83 ) {
V_8 -> V_66 &= ~ V_83 ;
F_45 ( V_4 ) -> V_84 = 1 ;
F_46 ( V_4 ) -> V_85 |= V_86 ;
}
} else if ( ! F_37 ( V_2 ) ) {
F_47 ( V_2 ) ;
}
if ( V_8 -> V_66 & V_87 )
F_45 ( V_4 ) -> V_79 = 1 ;
}
}
static void F_48 ( struct V_3 * V_4 , T_4 V_82 , T_7 V_88 )
{
V_4 -> V_89 = V_90 ;
V_4 -> V_91 = 0 ;
F_5 ( V_4 ) -> V_64 = V_88 ;
F_5 ( V_4 ) -> V_92 = 0 ;
F_49 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_82 = V_82 ;
if ( V_88 & ( V_93 | V_94 ) )
V_82 ++ ;
F_5 ( V_4 ) -> V_12 = V_82 ;
}
static inline bool F_50 ( const struct V_7 * V_8 )
{
return V_8 -> V_95 != V_8 -> V_96 ;
}
static void F_51 ( T_8 * V_97 , struct V_7 * V_8 ,
struct V_98 * V_99 )
{
T_6 V_100 = V_99 -> V_100 ;
if ( F_52 ( V_101 & V_100 ) ) {
* V_97 ++ = F_53 ( ( V_102 << 24 ) | ( V_102 << 16 ) |
( V_103 << 8 ) | V_104 ) ;
V_99 -> V_105 = ( T_5 * ) V_97 ;
V_97 += 4 ;
}
if ( F_52 ( V_99 -> V_19 ) ) {
* V_97 ++ = F_53 ( ( V_106 << 24 ) |
( V_107 << 16 ) |
V_99 -> V_19 ) ;
}
if ( F_54 ( V_108 & V_100 ) ) {
if ( F_52 ( V_109 & V_100 ) ) {
* V_97 ++ = F_53 ( ( V_110 << 24 ) |
( V_111 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
V_100 &= ~ V_109 ;
} else {
* V_97 ++ = F_53 ( ( V_102 << 24 ) |
( V_102 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
}
* V_97 ++ = F_53 ( V_99 -> V_114 ) ;
* V_97 ++ = F_53 ( V_99 -> V_115 ) ;
}
if ( F_52 ( V_109 & V_100 ) ) {
* V_97 ++ = F_53 ( ( V_102 << 24 ) |
( V_102 << 16 ) |
( V_110 << 8 ) |
V_111 ) ;
}
if ( F_52 ( V_116 & V_100 ) ) {
* V_97 ++ = F_53 ( ( V_102 << 24 ) |
( V_117 << 16 ) |
( V_118 << 8 ) |
V_99 -> V_119 ) ;
}
if ( F_52 ( V_99 -> V_120 ) ) {
struct V_121 * V_122 = V_8 -> V_58 . V_123 ?
V_8 -> V_124 : V_8 -> V_125 ;
int V_126 ;
* V_97 ++ = F_53 ( ( V_102 << 24 ) |
( V_102 << 16 ) |
( V_127 << 8 ) |
( V_128 + ( V_99 -> V_120 *
V_129 ) ) ) ;
for ( V_126 = 0 ; V_126 < V_99 -> V_120 ;
++ V_126 ) {
* V_97 ++ = F_53 ( V_122 [ V_126 ] . V_130 ) ;
* V_97 ++ = F_53 ( V_122 [ V_126 ] . V_12 ) ;
}
V_8 -> V_58 . V_123 = 0 ;
}
if ( F_52 ( V_131 & V_100 ) ) {
struct V_132 * V_133 = V_99 -> V_134 ;
T_7 * V_135 = ( T_7 * ) V_97 ;
T_4 V_81 ;
if ( V_133 -> exp ) {
V_81 = V_136 + V_133 -> V_81 ;
* V_97 = F_53 ( ( V_137 << 24 ) | ( V_81 << 16 ) |
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
static unsigned int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_98 * V_99 ,
struct V_142 * * V_143 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_144 = V_145 ;
struct V_146 * V_147 = V_8 -> V_148 ;
#ifdef F_56
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
if ( F_54 ( V_153 && ! * V_143 ) ) {
V_99 -> V_100 |= V_108 ;
V_99 -> V_114 = F_57 ( V_4 ) + V_8 -> V_154 ;
V_99 -> V_115 = V_8 -> V_58 . V_155 ;
V_144 -= V_156 ;
}
if ( F_54 ( V_157 ) ) {
V_99 -> V_119 = V_8 -> V_58 . V_47 ;
V_99 -> V_100 |= V_116 ;
V_144 -= V_158 ;
}
if ( F_54 ( V_159 ) ) {
V_99 -> V_100 |= V_109 ;
if ( F_52 ( ! ( V_108 & V_99 -> V_100 ) ) )
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
static unsigned int F_58 ( struct V_74 * V_75 ,
unsigned int V_19 , struct V_3 * V_4 ,
struct V_98 * V_99 ,
const struct V_142 * V_143 ,
struct V_132 * V_133 )
{
struct V_165 * V_166 = F_43 ( V_75 ) ;
unsigned int V_144 = V_145 ;
#ifdef F_56
if ( V_143 ) {
V_99 -> V_100 |= V_101 ;
V_144 -= V_151 ;
V_166 -> V_167 &= ! V_166 -> V_168 ;
}
#endif
V_99 -> V_19 = V_19 ;
V_144 -= V_152 ;
if ( F_54 ( V_166 -> V_46 ) ) {
V_99 -> V_119 = V_166 -> V_47 ;
V_99 -> V_100 |= V_116 ;
V_144 -= V_158 ;
}
if ( F_54 ( V_166 -> V_167 ) ) {
V_99 -> V_100 |= V_108 ;
V_99 -> V_114 = F_57 ( V_4 ) ;
V_99 -> V_115 = V_75 -> V_155 ;
V_144 -= V_156 ;
}
if ( F_54 ( V_166 -> V_168 ) ) {
V_99 -> V_100 |= V_109 ;
if ( F_52 ( ! V_166 -> V_167 ) )
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
unsigned int V_169 = 0 ;
unsigned int V_170 ;
V_99 -> V_100 = 0 ;
#ifdef F_56
* V_143 = V_8 -> V_149 -> V_150 ( V_2 , V_2 ) ;
if ( F_52 ( * V_143 ) ) {
V_99 -> V_100 |= V_101 ;
V_169 += V_151 ;
}
#else
* V_143 = NULL ;
#endif
if ( F_54 ( V_8 -> V_58 . V_167 ) ) {
V_99 -> V_100 |= V_108 ;
V_99 -> V_114 = V_4 ? F_57 ( V_4 ) + V_8 -> V_154 : 0 ;
V_99 -> V_115 = V_8 -> V_58 . V_155 ;
V_169 += V_156 ;
}
V_170 = V_8 -> V_58 . V_171 + V_8 -> V_58 . V_123 ;
if ( F_52 ( V_170 ) ) {
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
static void F_60 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_173 ) &
( V_174 | V_175 | V_176 |
V_177 | V_178 ) )
F_61 ( V_2 , F_62 ( V_2 ) , F_3 ( V_2 ) -> V_179 ,
0 , V_180 ) ;
}
static void F_63 ( unsigned long V_181 )
{
struct V_182 * V_183 = (struct V_182 * ) V_181 ;
F_64 ( V_184 ) ;
unsigned long V_88 ;
struct V_185 * V_186 , * V_187 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_65 ( V_88 ) ;
F_66 ( & V_183 -> V_188 , & V_184 ) ;
F_67 ( V_88 ) ;
F_68 (q, n, &list) {
V_8 = F_69 ( V_186 , struct V_7 , V_189 ) ;
F_70 ( & V_8 -> V_189 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_71 ( V_2 ) ;
if ( ! F_72 ( V_2 ) ) {
F_60 ( V_2 ) ;
} else {
F_73 ( V_190 , & V_8 -> V_191 ) ;
}
F_74 ( V_2 ) ;
F_75 ( V_192 , & V_8 -> V_191 ) ;
F_76 ( V_2 ) ;
}
}
void F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_88 , V_193 ;
do {
V_88 = V_8 -> V_191 ;
if ( ! ( V_88 & V_194 ) )
return;
V_193 = V_88 & ~ V_194 ;
} while ( F_78 ( & V_8 -> V_191 , V_88 , V_193 ) != V_88 );
if ( V_88 & ( 1UL << V_190 ) )
F_60 ( V_2 ) ;
F_79 ( V_2 ) ;
if ( V_88 & ( 1UL << V_195 ) ) {
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_196 ) ) {
F_82 ( V_2 ) ;
F_81 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_197 ) ) {
F_2 ( V_2 ) -> V_198 -> V_199 ( V_2 ) ;
F_81 ( V_2 ) ;
}
}
void T_9 F_83 ( void )
{
int V_200 ;
F_84 (i) {
struct V_182 * V_183 = & F_85 ( V_182 , V_200 ) ;
F_86 ( & V_183 -> V_188 ) ;
F_87 ( & V_183 -> V_201 ,
F_63 ,
( unsigned long ) V_183 ) ;
}
}
void F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_202 ;
V_202 = F_89 ( V_4 -> V_203 - 1 , & V_2 -> V_204 ) ;
if ( V_202 >= F_90 ( 1 ) && F_91 () == V_205 )
goto V_206;
if ( F_92 ( V_207 , & V_8 -> V_191 ) &&
! F_93 ( V_192 , & V_8 -> V_191 ) ) {
unsigned long V_88 ;
struct V_182 * V_183 ;
F_65 ( V_88 ) ;
V_183 = F_94 ( & V_182 ) ;
F_95 ( & V_8 -> V_189 , & V_183 -> V_188 ) ;
F_96 ( & V_183 -> V_201 ) ;
F_67 ( V_88 ) ;
return;
}
V_206:
F_76 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_208 ,
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
F_98 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_208 ) {
F_99 ( & V_4 -> V_217 ) ;
if ( F_52 ( F_100 ( V_4 ) ) )
V_4 = F_101 ( V_4 , V_209 ) ;
else
V_4 = F_102 ( V_4 , V_209 ) ;
if ( F_52 ( ! V_4 ) )
return - V_218 ;
}
V_211 = F_103 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_213 = F_5 ( V_4 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( F_52 ( V_213 -> V_64 & V_93 ) )
V_214 = F_55 ( V_2 , V_4 , & V_99 , & V_143 ) ;
else
V_214 = F_59 ( V_2 , V_4 , & V_99 ,
& V_143 ) ;
V_215 = V_214 + sizeof( struct V_76 ) ;
V_4 -> V_219 = F_104 ( V_2 ) < F_90 ( 1 ) ;
F_105 ( V_4 , V_215 ) ;
F_106 ( V_4 ) ;
F_107 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_220 = F_108 ( V_4 ) ? V_221 : F_88 ;
F_109 ( V_4 , V_2 ) ;
F_110 ( V_4 -> V_203 , & V_2 -> V_204 ) ;
V_77 = F_45 ( V_4 ) ;
V_77 -> V_222 = V_211 -> V_223 ;
V_77 -> V_224 = V_211 -> V_225 ;
V_77 -> V_82 = F_53 ( V_213 -> V_82 ) ;
V_77 -> V_226 = F_53 ( V_8 -> V_60 ) ;
* ( ( ( V_227 * ) V_77 ) + 6 ) = F_111 ( ( ( V_215 >> 2 ) << 12 ) |
V_213 -> V_64 ) ;
if ( F_52 ( V_213 -> V_64 & V_93 ) ) {
V_77 -> V_228 = F_111 ( F_20 ( V_8 -> V_44 , 65535U ) ) ;
} else {
V_77 -> V_228 = F_111 ( F_31 ( V_2 ) ) ;
}
V_77 -> V_229 = 0 ;
V_77 -> V_230 = 0 ;
if ( F_52 ( F_50 ( V_8 ) && F_11 ( V_213 -> V_82 , V_8 -> V_96 ) ) ) {
if ( F_11 ( V_8 -> V_96 , V_213 -> V_82 + 0x10000 ) ) {
V_77 -> V_230 = F_111 ( V_8 -> V_96 - V_213 -> V_82 ) ;
V_77 -> V_231 = 1 ;
} else if ( F_112 ( V_213 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_230 = F_111 ( 0xFFFF ) ;
V_77 -> V_231 = 1 ;
}
}
F_51 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_99 ) ;
F_46 ( V_4 ) -> V_85 = V_2 -> V_232 ;
if ( F_54 ( ( V_213 -> V_64 & V_93 ) == 0 ) )
F_44 ( V_2 , V_4 , V_215 ) ;
#ifdef F_56
if ( V_143 ) {
F_113 ( V_2 , V_233 ) ;
V_8 -> V_149 -> V_234 ( V_99 . V_105 ,
V_143 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_198 -> V_235 ( V_2 , V_4 ) ;
if ( F_54 ( V_213 -> V_64 & V_236 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_215 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_237 += F_6 ( V_4 ) ;
}
if ( F_112 ( V_213 -> V_12 , V_8 -> V_11 ) || V_213 -> V_82 == V_213 -> V_12 )
F_114 ( F_9 ( V_2 ) , V_238 ,
F_6 ( V_4 ) ) ;
V_8 -> V_239 += F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_240 = F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_241 = F_115 ( V_4 ) ;
V_4 -> V_242 . V_243 = 0 ;
memset ( V_4 -> V_244 , 0 , F_21 ( sizeof( struct V_245 ) ,
sizeof( struct V_246 ) ) ) ;
V_216 = V_6 -> V_198 -> V_247 ( V_2 , V_4 , & V_211 -> V_248 . V_249 ) ;
if ( F_54 ( V_216 <= 0 ) )
return V_216 ;
F_116 ( V_2 ) ;
return F_117 ( V_216 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_250 = F_5 ( V_4 ) -> V_12 ;
F_119 ( V_4 ) ;
F_120 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_4 -> V_203 ;
F_121 ( V_2 , V_4 -> V_203 ) ;
}
static void F_122 ( struct V_3 * V_4 , unsigned int V_252 )
{
if ( V_4 -> V_81 <= V_252 || V_4 -> V_89 == V_253 ) {
F_49 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_254 = 0 ;
} else {
F_49 ( V_4 , F_123 ( V_4 -> V_81 , V_252 ) ) ;
F_5 ( V_4 ) -> V_254 = V_252 ;
}
}
static void F_124 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_255 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_256 || F_125 ( V_8 ) )
return;
if ( F_112 ( F_126 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_257 -= V_255 ;
}
static void F_127 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_255 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_255 ;
if ( F_5 ( V_4 ) -> V_92 & V_258 )
V_8 -> V_256 -= V_255 ;
if ( F_5 ( V_4 ) -> V_92 & V_259 )
V_8 -> V_260 -= V_255 ;
if ( F_5 ( V_4 ) -> V_92 & V_261 )
V_8 -> V_262 -= V_255 ;
if ( F_125 ( V_8 ) && V_255 > 0 )
V_8 -> V_256 -= F_30 ( T_4 , V_8 -> V_256 , V_255 ) ;
F_124 ( V_2 , V_4 , V_255 ) ;
if ( V_8 -> V_263 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_263 ) -> V_82 ) &&
( F_128 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_258 ) ) )
V_8 -> V_264 -= V_255 ;
F_129 ( V_8 ) ;
}
static void F_130 ( struct V_3 * V_4 , struct V_3 * V_265 )
{
struct V_266 * V_267 = F_46 ( V_4 ) ;
if ( F_52 ( V_267 -> V_268 & V_269 ) &&
! F_11 ( V_267 -> V_270 , F_5 ( V_265 ) -> V_82 ) ) {
struct V_266 * V_271 = F_46 ( V_265 ) ;
T_7 V_272 = V_267 -> V_268 & V_269 ;
V_267 -> V_268 &= ~ V_272 ;
V_271 -> V_268 |= V_272 ;
F_131 ( V_267 -> V_270 , V_271 -> V_270 ) ;
}
}
int F_132 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_252 , T_10 V_273 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_274 ;
int V_275 , V_276 ;
int V_277 ;
T_7 V_88 ;
if ( F_133 ( V_81 > V_4 -> V_81 ) )
return - V_278 ;
V_275 = F_134 ( V_4 ) - V_81 ;
if ( V_275 < 0 )
V_275 = 0 ;
if ( F_135 ( V_4 , V_273 ) )
return - V_279 ;
V_274 = F_136 ( V_2 , V_275 , V_273 , true ) ;
if ( ! V_274 )
return - V_279 ;
V_2 -> V_251 += V_274 -> V_203 ;
F_121 ( V_2 , V_274 -> V_203 ) ;
V_277 = V_4 -> V_81 - V_81 - V_275 ;
V_274 -> V_203 += V_277 ;
V_4 -> V_203 -= V_277 ;
F_5 ( V_274 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_274 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_274 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_280 ) ;
F_5 ( V_274 ) -> V_64 = V_88 ;
F_5 ( V_274 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
if ( ! F_46 ( V_4 ) -> V_281 && V_4 -> V_89 != V_90 ) {
V_274 -> V_91 = F_137 ( V_4 -> V_181 + V_81 ,
F_138 ( V_274 , V_275 ) ,
V_275 , 0 ) ;
F_139 ( V_4 , V_81 ) ;
V_4 -> V_91 = F_140 ( V_4 -> V_91 , V_274 -> V_91 , V_81 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_141 ( V_4 , V_274 , V_81 ) ;
}
V_274 -> V_89 = V_4 -> V_89 ;
V_274 -> V_242 = V_4 -> V_242 ;
F_130 ( V_4 , V_274 ) ;
V_276 = F_6 ( V_4 ) ;
F_122 ( V_4 , V_252 ) ;
F_122 ( V_274 , V_252 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_274 ) -> V_12 ) ) {
int V_282 = V_276 - F_6 ( V_4 ) -
F_6 ( V_274 ) ;
if ( V_282 )
F_127 ( V_2 , V_4 , V_282 ) ;
}
F_119 ( V_274 ) ;
F_142 ( V_4 , V_274 , V_2 ) ;
return 0 ;
}
static void F_143 ( struct V_3 * V_4 , int V_81 )
{
struct V_266 * V_267 ;
int V_200 , V_283 , V_284 ;
V_284 = F_30 ( int , V_81 , F_134 ( V_4 ) ) ;
if ( V_284 ) {
F_144 ( V_4 , V_284 ) ;
V_81 -= V_284 ;
if ( ! V_81 )
return;
}
V_284 = V_81 ;
V_283 = 0 ;
V_267 = F_46 ( V_4 ) ;
for ( V_200 = 0 ; V_200 < V_267 -> V_281 ; V_200 ++ ) {
int V_169 = F_145 ( & V_267 -> V_285 [ V_200 ] ) ;
if ( V_169 <= V_284 ) {
F_146 ( V_4 , V_200 ) ;
V_284 -= V_169 ;
} else {
V_267 -> V_285 [ V_283 ] = V_267 -> V_285 [ V_200 ] ;
if ( V_284 ) {
V_267 -> V_285 [ V_283 ] . V_286 += V_284 ;
F_147 ( & V_267 -> V_285 [ V_283 ] , V_284 ) ;
V_284 = 0 ;
}
V_283 ++ ;
}
}
V_267 -> V_281 = V_283 ;
F_148 ( V_4 ) ;
V_4 -> V_287 -= V_81 ;
V_4 -> V_81 = V_4 -> V_287 ;
}
int F_149 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_135 ( V_4 , V_180 ) )
return - V_279 ;
F_143 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_203 -= V_81 ;
V_2 -> V_251 -= V_81 ;
F_150 ( V_2 , V_81 ) ;
F_151 ( V_2 , V_288 ) ;
if ( F_6 ( V_4 ) > 1 )
F_122 ( V_4 , F_115 ( V_4 ) ) ;
return 0 ;
}
static inline int F_152 ( struct V_1 * V_2 , int V_289 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_252 ;
V_252 = V_289 - V_6 -> V_198 -> V_290 - sizeof( struct V_76 ) ;
if ( V_6 -> V_198 -> V_291 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_153 ( V_18 ) )
V_252 -= V_6 -> V_198 -> V_291 ;
}
if ( V_252 > V_8 -> V_58 . V_292 )
V_252 = V_8 -> V_58 . V_292 ;
V_252 -= V_6 -> V_293 ;
if ( V_252 < 48 )
V_252 = 48 ;
return V_252 ;
}
int F_154 ( struct V_1 * V_2 , int V_289 )
{
return F_152 ( V_2 , V_289 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_155 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_294 ;
V_294 = V_19 +
V_8 -> V_80 +
V_6 -> V_293 +
V_6 -> V_198 -> V_290 ;
if ( V_6 -> V_198 -> V_291 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_153 ( V_18 ) )
V_294 += V_6 -> V_198 -> V_291 ;
}
return V_294 ;
}
void F_156 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_295 * V_295 = F_9 ( V_2 ) ;
V_6 -> V_296 . V_297 = V_295 -> V_70 . V_298 > 1 ;
V_6 -> V_296 . V_299 = V_8 -> V_58 . V_292 + sizeof( struct V_76 ) +
V_6 -> V_198 -> V_290 ;
V_6 -> V_296 . V_300 = F_155 ( V_2 , V_295 -> V_70 . V_301 ) ;
V_6 -> V_296 . V_302 = 0 ;
if ( V_6 -> V_296 . V_297 )
V_6 -> V_296 . V_303 = V_30 ;
}
unsigned int F_157 ( struct V_1 * V_2 , T_4 V_289 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_252 ;
if ( V_6 -> V_296 . V_299 > V_289 )
V_6 -> V_296 . V_299 = V_289 ;
V_252 = F_154 ( V_2 , V_289 ) ;
V_252 = F_158 ( V_8 , V_252 ) ;
V_6 -> V_304 = V_289 ;
if ( V_6 -> V_296 . V_297 )
V_252 = F_20 ( V_252 , F_154 ( V_2 , V_6 -> V_296 . V_300 ) ) ;
V_8 -> V_305 = V_252 ;
return V_252 ;
}
unsigned int F_62 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_252 ;
unsigned int V_306 ;
struct V_98 V_99 ;
struct V_142 * V_143 ;
V_252 = V_8 -> V_305 ;
if ( V_18 ) {
T_4 V_294 = F_159 ( V_18 ) ;
if ( V_294 != F_2 ( V_2 ) -> V_304 )
V_252 = F_157 ( V_2 , V_294 ) ;
}
V_306 = F_59 ( V_2 , NULL , & V_99 , & V_143 ) +
sizeof( struct V_76 ) ;
if ( V_306 != V_8 -> V_80 ) {
int V_22 = ( int ) V_306 - V_8 -> V_80 ;
V_252 -= V_22 ;
}
return V_252 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_307 == V_308 &&
V_2 -> V_309 && ! F_161 ( V_310 , & V_2 -> V_309 -> V_88 ) ) {
T_4 V_311 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_312 = F_21 ( V_8 -> V_31 , V_311 ) ;
if ( V_312 < V_8 -> V_25 ) {
V_8 -> V_27 = F_19 ( V_2 ) ;
V_8 -> V_25 = ( V_8 -> V_25 + V_312 ) >> 1 ;
}
V_8 -> V_31 = 0 ;
}
V_8 -> V_29 = V_30 ;
}
static void F_162 ( struct V_1 * V_2 , bool V_313 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_95 , V_8 -> V_314 ) ||
V_8 -> V_10 > V_8 -> V_315 ) {
V_8 -> V_315 = V_8 -> V_10 ;
V_8 -> V_314 = V_8 -> V_11 ;
V_8 -> V_313 = V_313 ;
}
if ( F_163 ( V_2 ) ) {
V_8 -> V_31 = 0 ;
V_8 -> V_29 = V_30 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_31 )
V_8 -> V_31 = V_8 -> V_10 ;
if ( V_316 &&
( T_3 ) ( V_30 - V_8 -> V_29 ) >= F_2 ( V_2 ) -> V_28 )
F_160 ( V_2 ) ;
}
}
static bool F_164 ( const struct V_7 * V_8 )
{
return F_112 ( V_8 -> V_317 , V_8 -> V_95 ) &&
! F_112 ( V_8 -> V_317 , V_8 -> V_11 ) ;
}
static void F_165 ( struct V_7 * V_8 , unsigned int V_252 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_252 )
V_8 -> V_317 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_166 ( bool V_318 , const struct V_7 * V_8 ,
int V_179 )
{
return V_318 &&
( ( V_179 & V_319 ) ||
( ! V_179 && V_8 -> V_10 && F_164 ( V_8 ) ) ) ;
}
static T_4 F_167 ( const struct V_1 * V_2 , unsigned int V_252 )
{
T_4 V_320 , V_321 ;
V_320 = F_20 ( V_2 -> V_322 >> 10 ,
V_2 -> V_323 - 1 - V_324 ) ;
V_321 = F_29 ( T_4 , V_320 / V_252 , V_325 ) ;
return F_30 ( T_4 , V_321 , V_2 -> V_326 ) ;
}
static unsigned int F_168 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_252 ,
unsigned int V_327 ,
int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_318 , V_328 , V_228 , V_329 ;
V_228 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_329 = V_252 * V_327 ;
if ( F_54 ( V_329 <= V_228 && V_4 != F_169 ( V_2 ) ) )
return V_329 ;
V_328 = F_20 ( V_4 -> V_81 , V_228 ) ;
if ( V_329 <= V_328 )
return V_329 ;
V_318 = V_328 % V_252 ;
if ( F_166 ( V_318 != 0 , V_8 , V_179 ) )
return V_328 - V_318 ;
return V_328 ;
}
static inline unsigned int F_170 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_330 , V_24 , V_331 ;
if ( ( F_5 ( V_4 ) -> V_64 & V_94 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_330 = F_23 ( V_8 ) ;
V_24 = V_8 -> V_25 ;
if ( V_330 >= V_24 )
return 0 ;
V_331 = F_21 ( V_24 >> 1 , 1U ) ;
return F_20 ( V_331 , V_24 - V_330 ) ;
}
static int F_171 ( struct V_3 * V_4 , unsigned int V_252 )
{
int V_332 = F_6 ( V_4 ) ;
if ( ! V_332 || ( V_332 > 1 && F_115 ( V_4 ) != V_252 ) ) {
F_122 ( V_4 , V_252 ) ;
V_332 = F_6 ( V_4 ) ;
}
return V_332 ;
}
static inline bool F_172 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_333 , int V_179 )
{
if ( V_179 & V_334 )
return true ;
if ( F_50 ( V_8 ) || ( F_5 ( V_4 ) -> V_64 & V_94 ) )
return true ;
if ( ! F_166 ( V_4 -> V_81 < V_333 , V_8 , V_179 ) )
return true ;
return false ;
}
static bool F_173 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_333 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_333 )
V_12 = F_5 ( V_4 ) -> V_82 + V_333 ;
return ! F_112 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_174 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_333 , int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_335 ;
F_171 ( V_4 , V_333 ) ;
if ( ! F_172 ( V_8 , V_4 , V_333 , V_179 ) )
return 0 ;
V_335 = F_170 ( V_8 , V_4 ) ;
if ( V_335 && ! F_173 ( V_8 , V_4 , V_333 ) )
V_335 = 0 ;
return V_335 ;
}
bool F_175 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_176 ( V_2 ) ;
return V_4 &&
F_174 ( V_2 , V_4 , F_62 ( V_2 ) ,
( F_177 ( V_2 , V_4 ) ?
V_8 -> V_179 : V_334 ) ) ;
}
static int F_178 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_252 , T_10 V_273 )
{
struct V_3 * V_274 ;
int V_277 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_287 )
return F_132 ( V_2 , V_4 , V_81 , V_252 , V_273 ) ;
V_274 = F_136 ( V_2 , 0 , V_273 , true ) ;
if ( F_52 ( ! V_274 ) )
return - V_279 ;
V_2 -> V_251 += V_274 -> V_203 ;
F_121 ( V_2 , V_274 -> V_203 ) ;
V_274 -> V_203 += V_277 ;
V_4 -> V_203 -= V_277 ;
F_5 ( V_274 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_274 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_274 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_280 ) ;
F_5 ( V_274 ) -> V_64 = V_88 ;
F_5 ( V_274 ) -> V_92 = 0 ;
V_274 -> V_89 = V_4 -> V_89 = V_90 ;
F_141 ( V_4 , V_274 , V_81 ) ;
F_130 ( V_4 , V_274 ) ;
F_122 ( V_4 , V_252 ) ;
F_122 ( V_274 , V_252 ) ;
F_119 ( V_274 ) ;
F_142 ( V_4 , V_274 , V_2 ) ;
return 0 ;
}
static bool F_179 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_313 , T_4 V_327 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_336 , V_337 , V_338 , V_339 , V_330 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_217 V_32 ;
struct V_3 * V_188 ;
int V_340 ;
if ( F_5 ( V_4 ) -> V_64 & V_94 )
goto V_341;
if ( V_6 -> V_307 >= V_342 )
goto V_341;
if ( ( T_3 ) ( V_30 - V_8 -> V_34 ) > 0 )
goto V_341;
V_330 = F_23 ( V_8 ) ;
F_98 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_25 <= V_330 ) ) ;
V_337 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_338 = ( V_8 -> V_25 - V_330 ) * V_8 -> V_305 ;
V_339 = F_20 ( V_337 , V_338 ) ;
if ( V_339 >= V_327 * V_8 -> V_305 )
goto V_341;
if ( ( V_4 != F_169 ( V_2 ) ) && ( V_339 >= V_4 -> V_81 ) )
goto V_341;
V_340 = F_180 ( V_343 ) ;
if ( V_340 ) {
T_4 V_344 = F_20 ( V_8 -> V_345 , V_8 -> V_25 * V_8 -> V_305 ) ;
V_344 /= V_340 ;
if ( V_339 >= V_344 )
goto V_341;
} else {
if ( V_339 > F_181 ( V_8 ) * V_8 -> V_305 )
goto V_341;
}
V_188 = F_182 ( V_2 ) ;
F_99 ( & V_32 ) ;
V_336 = F_183 ( & V_32 , & V_188 -> V_217 ) ;
if ( V_336 < ( V_8 -> V_346 >> 4 ) )
goto V_341;
if ( V_338 < V_337 && V_338 <= V_4 -> V_81 )
* V_313 = true ;
return true ;
V_341:
return false ;
}
static inline void F_184 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_295 * V_295 = F_9 ( V_2 ) ;
T_4 V_347 ;
T_3 V_22 ;
V_347 = V_295 -> V_70 . V_348 ;
V_22 = V_30 - V_6 -> V_296 . V_303 ;
if ( F_52 ( V_22 >= V_347 * V_349 ) ) {
int V_19 = F_62 ( V_2 ) ;
V_6 -> V_296 . V_302 = 0 ;
V_6 -> V_296 . V_299 = V_8 -> V_58 . V_292 +
sizeof( struct V_76 ) +
V_6 -> V_198 -> V_290 ;
V_6 -> V_296 . V_300 = F_155 ( V_2 , V_19 ) ;
V_6 -> V_296 . V_303 = V_30 ;
}
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_350 , * V_351 ;
struct V_295 * V_295 = F_9 ( V_2 ) ;
int V_81 ;
int V_302 ;
int V_352 ;
int V_353 ;
int V_252 ;
int V_347 ;
if ( ! V_6 -> V_296 . V_297 ||
V_6 -> V_296 . V_302 ||
F_2 ( V_2 ) -> V_307 != V_308 ||
V_8 -> V_25 < 11 ||
V_8 -> V_58 . V_171 || V_8 -> V_58 . V_123 )
return - 1 ;
V_252 = F_62 ( V_2 ) ;
V_302 = F_154 ( V_2 , ( V_6 -> V_296 . V_299 +
V_6 -> V_296 . V_300 ) >> 1 ) ;
V_352 = V_302 + ( V_8 -> V_354 + 1 ) * V_8 -> V_305 ;
V_347 = V_6 -> V_296 . V_299 - V_6 -> V_296 . V_300 ;
if ( V_302 > F_154 ( V_2 , V_6 -> V_296 . V_299 ) ||
V_347 < V_295 -> V_70 . V_355 ) {
F_184 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_250 - V_8 -> V_11 < V_352 )
return - 1 ;
if ( V_8 -> V_345 < V_352 )
return - 1 ;
if ( F_112 ( V_8 -> V_11 + V_352 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_25 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_350 = F_136 ( V_2 , V_302 , V_180 , false ) ;
if ( ! V_350 )
return - 1 ;
V_2 -> V_251 += V_350 -> V_203 ;
F_121 ( V_2 , V_350 -> V_203 ) ;
V_4 = F_176 ( V_2 ) ;
F_5 ( V_350 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_350 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_302 ;
F_5 ( V_350 ) -> V_64 = V_236 ;
F_5 ( V_350 ) -> V_92 = 0 ;
V_350 -> V_91 = 0 ;
V_350 -> V_89 = V_4 -> V_89 ;
F_186 ( V_350 , V_4 , V_2 ) ;
V_81 = 0 ;
F_187 (skb, next, sk) {
V_353 = F_30 ( int , V_4 -> V_81 , V_302 - V_81 ) ;
if ( V_350 -> V_89 )
F_188 ( V_4 , 0 , F_138 ( V_350 , V_353 ) , V_353 ) ;
else
V_350 -> V_91 = F_189 ( V_4 , 0 ,
F_138 ( V_350 , V_353 ) ,
V_353 , V_350 -> V_91 ) ;
if ( V_4 -> V_81 <= V_353 ) {
F_5 ( V_350 ) -> V_64 |= F_5 ( V_4 ) -> V_64 ;
F_190 ( V_4 , V_2 ) ;
F_191 ( V_2 , V_4 ) ;
} else {
F_5 ( V_350 ) -> V_64 |= F_5 ( V_4 ) -> V_64 &
~ ( V_94 | V_280 ) ;
if ( ! F_46 ( V_4 ) -> V_281 ) {
F_192 ( V_4 , V_353 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_193 ( V_4 -> V_181 ,
V_4 -> V_81 , 0 ) ;
} else {
F_143 ( V_4 , V_353 ) ;
F_122 ( V_4 , V_252 ) ;
}
F_5 ( V_4 ) -> V_82 += V_353 ;
}
V_81 += V_353 ;
if ( V_81 >= V_302 )
break;
}
F_171 ( V_350 , V_350 -> V_81 ) ;
if ( ! F_97 ( V_2 , V_350 , 1 , V_180 ) ) {
V_8 -> V_25 -- ;
F_1 ( V_2 , V_350 ) ;
V_6 -> V_296 . V_302 = F_155 ( V_2 , V_350 -> V_81 ) ;
V_8 -> V_356 . V_357 = F_5 ( V_350 ) -> V_82 ;
V_8 -> V_356 . V_358 = F_5 ( V_350 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_61 ( struct V_1 * V_2 , unsigned int V_252 , int V_179 ,
int V_359 , T_10 V_273 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_332 , V_360 ;
int V_335 ;
int V_361 ;
bool V_313 = false ;
T_4 V_327 ;
V_360 = 0 ;
if ( ! V_359 ) {
V_361 = F_185 ( V_2 ) ;
if ( ! V_361 ) {
return false ;
} else if ( V_361 > 0 ) {
V_360 = 1 ;
}
}
V_327 = F_167 ( V_2 , V_252 ) ;
while ( ( V_4 = F_176 ( V_2 ) ) ) {
unsigned int V_339 ;
V_332 = F_171 ( V_4 , V_252 ) ;
F_98 ( ! V_332 ) ;
if ( F_52 ( V_8 -> V_362 ) && V_8 -> V_363 == V_364 ) {
F_99 ( & V_4 -> V_217 ) ;
goto V_362;
}
V_335 = F_170 ( V_8 , V_4 ) ;
if ( ! V_335 ) {
if ( V_359 == 2 )
V_335 = 1 ;
else
break;
}
if ( F_52 ( ! F_173 ( V_8 , V_4 , V_252 ) ) )
break;
if ( V_332 == 1 ) {
if ( F_52 ( ! F_172 ( V_8 , V_4 , V_252 ,
( F_177 ( V_2 , V_4 ) ?
V_179 : V_334 ) ) ) )
break;
} else {
if ( ! V_359 &&
F_179 ( V_2 , V_4 , & V_313 ,
V_327 ) )
break;
}
V_339 = V_252 ;
if ( V_332 > 1 && ! F_50 ( V_8 ) )
V_339 = F_168 ( V_2 , V_4 , V_252 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_179 ) ;
if ( V_4 -> V_81 > V_339 &&
F_52 ( F_178 ( V_2 , V_4 , V_339 , V_252 , V_273 ) ) )
break;
V_339 = F_21 ( 2 * V_4 -> V_203 , V_2 -> V_322 >> 10 ) ;
V_339 = F_30 ( T_4 , V_339 , V_365 ) ;
if ( F_194 ( & V_2 -> V_204 ) > V_339 ) {
F_73 ( V_207 , & V_8 -> V_191 ) ;
F_195 () ;
if ( F_194 ( & V_2 -> V_204 ) > V_339 )
break;
}
if ( F_52 ( F_97 ( V_2 , V_4 , 1 , V_273 ) ) )
break;
V_362:
F_1 ( V_2 , V_4 ) ;
F_165 ( V_8 , V_252 , V_4 ) ;
V_360 += F_6 ( V_4 ) ;
if ( V_359 )
break;
}
if ( F_54 ( V_360 ) ) {
if ( F_196 ( V_2 ) )
V_8 -> V_366 += V_360 ;
if ( V_359 != 2 )
F_197 ( V_2 ) ;
V_313 |= ( F_23 ( V_8 ) >= V_8 -> V_25 ) ;
F_162 ( V_2 , V_313 ) ;
return false ;
}
return ! V_8 -> V_10 && F_176 ( V_2 ) ;
}
bool F_197 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_367 , V_368 , V_369 ;
T_4 V_370 = F_198 ( V_8 -> V_346 >> 3 ) ;
if ( F_133 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_133 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_8 -> V_371 )
return false ;
if ( V_6 -> V_13 != V_372 )
return false ;
if ( V_373 < 3 || ! V_8 -> V_10 ||
! F_199 ( V_8 ) || F_2 ( V_2 ) -> V_307 != V_308 )
return false ;
if ( ( V_8 -> V_25 > F_23 ( V_8 ) ) &&
F_176 ( V_2 ) )
return false ;
V_367 = V_370 << 1 ? : V_374 ;
if ( V_8 -> V_10 == 1 )
V_367 = F_29 ( T_4 , V_367 ,
( V_370 + ( V_370 >> 1 ) + V_375 ) ) ;
V_367 = F_29 ( T_4 , V_367 , F_200 ( 10 ) ) ;
V_368 = V_30 + V_367 ;
V_369 = ( T_4 ) F_2 ( V_2 ) -> V_376 ;
if ( ( T_3 ) ( V_368 - V_369 ) > 0 ) {
T_3 V_22 = V_369 - V_30 ;
if ( V_22 > 0 )
V_367 = V_22 ;
}
F_201 ( V_2 , V_15 , V_367 ,
V_377 ) ;
return true ;
}
static bool F_202 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_52 ( F_203 ( V_2 , V_4 ) ) ) {
F_204 ( F_9 ( V_2 ) ,
V_378 ) ;
return true ;
}
return false ;
}
void F_205 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_379 ;
int V_19 = F_62 ( V_2 ) ;
V_4 = F_176 ( V_2 ) ;
if ( V_4 ) {
if ( F_173 ( V_8 , V_4 , V_19 ) ) {
V_379 = V_8 -> V_10 ;
F_61 ( V_2 , V_19 , V_380 , 2 , V_180 ) ;
if ( V_8 -> V_10 > V_379 )
goto V_381;
goto V_382;
}
V_4 = F_206 ( V_2 , V_4 ) ;
} else {
V_4 = F_169 ( V_2 ) ;
}
if ( V_8 -> V_383 )
goto V_382;
if ( F_133 ( ! V_4 ) )
goto V_382;
if ( F_202 ( V_2 , V_4 ) )
goto V_382;
V_379 = F_6 ( V_4 ) ;
if ( F_133 ( ! V_379 ) )
goto V_382;
if ( ( V_379 > 1 ) && ( V_4 -> V_81 > ( V_379 - 1 ) * V_19 ) ) {
if ( F_52 ( F_132 ( V_2 , V_4 , ( V_379 - 1 ) * V_19 , V_19 ,
V_180 ) ) )
goto V_382;
V_4 = F_207 ( V_2 , V_4 ) ;
}
if ( F_133 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_382;
if ( F_208 ( V_2 , V_4 ) )
goto V_382;
V_8 -> V_383 = V_8 -> V_11 ;
V_381:
F_204 ( F_9 ( V_2 ) , V_384 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_382:
F_7 ( V_2 ) ;
}
void F_209 ( struct V_1 * V_2 , unsigned int V_333 ,
int V_179 )
{
if ( F_52 ( V_2 -> V_173 == V_385 ) )
return;
if ( F_61 ( V_2 , V_333 , V_179 , 0 ,
F_210 ( V_2 , V_180 ) ) )
F_211 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 , unsigned int V_252 )
{
struct V_3 * V_4 = F_176 ( V_2 ) ;
F_98 ( ! V_4 || V_4 -> V_81 < V_252 ) ;
F_61 ( V_2 , V_252 , V_334 , 1 , V_2 -> V_386 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_387 ;
int V_388 = F_213 ( V_2 ) ;
int V_389 = F_214 ( V_2 ) ;
int V_390 = F_30 ( int , V_8 -> V_45 , V_389 ) ;
int V_228 ;
if ( V_19 > V_390 )
V_19 = V_390 ;
if ( V_388 < ( V_390 >> 1 ) ) {
V_6 -> V_35 . V_391 = 0 ;
if ( F_215 ( V_2 ) )
V_8 -> V_392 = F_20 ( V_8 -> V_392 ,
4U * V_8 -> V_20 ) ;
V_388 = F_216 ( V_388 , 1 << V_8 -> V_58 . V_47 ) ;
if ( V_388 < ( V_389 >> 4 ) || V_388 < V_19 )
return 0 ;
}
if ( V_388 > V_8 -> V_392 )
V_388 = V_8 -> V_392 ;
V_228 = V_8 -> V_44 ;
if ( V_8 -> V_58 . V_47 ) {
V_228 = V_388 ;
if ( ( ( V_228 >> V_8 -> V_58 . V_47 ) << V_8 -> V_58 . V_47 ) != V_228 )
V_228 = ( ( ( V_228 >> V_8 -> V_58 . V_47 ) + 1 )
<< V_8 -> V_58 . V_47 ) ;
} else {
if ( V_228 <= V_388 - V_19 || V_228 > V_388 )
V_228 = ( V_388 / V_19 ) * V_19 ;
else if ( V_19 == V_390 &&
V_388 > V_228 + ( V_390 >> 1 ) )
V_228 = V_388 ;
}
return V_228 ;
}
void F_217 ( struct V_3 * V_4 ,
const struct V_3 * V_393 )
{
const struct V_266 * V_394 = F_46 ( V_393 ) ;
T_7 V_272 = V_394 -> V_268 & V_269 ;
if ( F_52 ( V_272 ) ) {
struct V_266 * V_267 = F_46 ( V_4 ) ;
V_267 -> V_268 |= V_272 ;
V_267 -> V_270 = V_394 -> V_270 ;
}
}
static void F_218 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_393 = F_207 ( V_2 , V_4 ) ;
int V_395 , V_396 ;
V_395 = V_4 -> V_81 ;
V_396 = V_393 -> V_81 ;
F_98 ( F_6 ( V_4 ) != 1 || F_6 ( V_393 ) != 1 ) ;
F_219 ( V_2 , V_393 , V_4 ) ;
F_190 ( V_393 , V_2 ) ;
F_220 ( V_393 , F_138 ( V_4 , V_396 ) ,
V_396 ) ;
if ( V_393 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_221 ( V_4 -> V_91 , V_393 -> V_91 , V_395 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_393 ) -> V_12 ;
F_5 ( V_4 ) -> V_64 |= F_5 ( V_393 ) -> V_64 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_393 ) -> V_92 & V_397 ;
F_222 ( V_8 ) ;
if ( V_393 == V_8 -> V_398 )
V_8 -> V_398 = V_4 ;
F_127 ( V_2 , V_393 , F_6 ( V_393 ) ) ;
F_217 ( V_4 , V_393 ) ;
F_191 ( V_2 , V_393 ) ;
}
static bool F_223 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_46 ( V_4 ) -> V_281 != 0 )
return false ;
if ( F_100 ( V_4 ) )
return false ;
if ( V_4 == F_176 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_258 )
return false ;
return true ;
}
static void F_224 ( struct V_1 * V_2 , struct V_3 * V_399 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_399 , * V_400 ;
bool V_401 = true ;
if ( ! V_402 )
return;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
return;
F_187 (skb, tmp, sk) {
if ( ! F_223 ( V_2 , V_4 ) )
break;
V_49 -= V_4 -> V_81 ;
if ( V_401 ) {
V_401 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_81 > F_225 ( V_399 ) )
break;
if ( F_112 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_218 ( V_2 , V_399 ) ;
}
}
int F_208 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_333 ;
int V_216 ;
if ( V_6 -> V_296 . V_302 ) {
V_6 -> V_296 . V_302 = 0 ;
}
if ( F_194 ( & V_2 -> V_204 ) >
F_20 ( V_2 -> V_251 + ( V_2 -> V_251 >> 2 ) , V_2 -> V_403 ) )
return - V_404 ;
if ( F_202 ( V_2 , V_4 ) )
return - V_405 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_95 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_95 ) )
F_226 () ;
if ( F_149 ( V_2 , V_4 , V_8 -> V_95 - F_5 ( V_4 ) -> V_82 ) )
return - V_279 ;
}
if ( F_2 ( V_2 ) -> V_198 -> V_406 ( V_2 ) )
return - V_407 ;
V_333 = F_62 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_95 )
return - V_404 ;
if ( V_4 -> V_81 > V_333 ) {
if ( F_132 ( V_2 , V_4 , V_333 , V_333 , V_180 ) )
return - V_279 ;
} else {
int V_408 = F_6 ( V_4 ) ;
if ( F_52 ( V_408 > 1 ) ) {
if ( F_135 ( V_4 , V_180 ) )
return - V_279 ;
F_171 ( V_4 , V_333 ) ;
F_127 ( V_2 , V_4 , V_408 - F_6 ( V_4 ) ) ;
}
}
if ( ( F_5 ( V_4 ) -> V_64 & V_409 ) == V_409 )
F_41 ( V_2 , V_4 ) ;
F_224 ( V_2 , V_4 , V_333 ) ;
if ( F_52 ( ( V_410 && ( ( unsigned long ) V_4 -> V_181 & 3 ) ) ||
F_227 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_350 ;
F_99 ( & V_4 -> V_217 ) ;
V_350 = F_228 ( V_4 , V_324 , V_180 ) ;
V_216 = V_350 ? F_97 ( V_2 , V_350 , 0 , V_180 ) :
- V_218 ;
} else {
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
}
if ( F_54 ( ! V_216 ) ) {
F_5 ( V_4 ) -> V_92 |= V_397 ;
F_229 ( F_9 ( V_2 ) , V_411 ) ;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
F_204 ( F_9 ( V_2 ) , V_412 ) ;
V_8 -> V_413 ++ ;
}
return V_216 ;
}
int F_230 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_216 = F_208 ( V_2 , V_4 ) ;
if ( V_216 == 0 ) {
#if V_414 > 0
if ( F_5 ( V_4 ) -> V_92 & V_259 ) {
F_231 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_92 |= V_415 ;
V_8 -> V_260 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_416 )
V_8 -> V_416 = F_57 ( V_4 ) ;
} else if ( V_216 != - V_405 ) {
F_204 ( F_9 ( V_2 ) , V_417 ) ;
}
if ( V_8 -> V_418 < 0 )
V_8 -> V_418 = 0 ;
V_8 -> V_418 += F_6 ( V_4 ) ;
return V_216 ;
}
static bool F_232 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_307 != V_342 )
return false ;
if ( F_125 ( V_8 ) )
return false ;
if ( F_175 ( V_2 ) )
return false ;
return true ;
}
void F_233 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_419 = NULL ;
T_4 V_420 ;
int V_421 ;
int V_422 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_262 )
V_8 -> V_423 = V_8 -> V_95 ;
if ( V_8 -> V_398 ) {
V_4 = V_8 -> V_398 ;
V_420 = F_5 ( V_4 ) -> V_12 ;
if ( F_112 ( V_420 , V_8 -> V_423 ) )
V_420 = V_8 -> V_423 ;
} else {
V_4 = F_182 ( V_2 ) ;
V_420 = V_8 -> V_95 ;
}
F_234 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
if ( V_4 == F_176 ( V_2 ) )
break;
if ( ! V_419 )
V_8 -> V_398 = V_4 ;
if ( F_23 ( V_8 ) >= V_8 -> V_25 )
return;
if ( V_422 ) {
V_424:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_126 ( V_8 ) ) )
break;
V_421 = V_425 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_423 ) ) {
V_8 -> V_423 = V_420 ;
if ( ! F_232 ( V_2 ) )
break;
if ( V_419 ) {
V_4 = V_419 ;
V_419 = NULL ;
}
V_422 = 1 ;
goto V_424;
} else if ( ! ( V_92 & V_261 ) ) {
if ( ! V_419 && ! ( V_92 & ( V_259 | V_258 ) ) )
V_419 = V_4 ;
continue;
} else {
V_420 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_307 != V_426 )
V_421 = V_427 ;
else
V_421 = V_428 ;
}
if ( V_92 & ( V_258 | V_259 ) )
continue;
if ( F_230 ( V_2 , V_4 ) )
return;
F_204 ( F_9 ( V_2 ) , V_421 ) ;
if ( F_196 ( V_2 ) )
V_8 -> V_366 += F_6 ( V_4 ) ;
if ( V_4 == F_182 ( V_2 ) )
F_201 ( V_2 , V_372 ,
F_2 ( V_2 ) -> V_28 ,
V_377 ) ;
}
}
void F_235 ( struct V_1 * V_2 , int V_169 )
{
int V_429 ;
if ( V_169 <= V_2 -> V_430 )
return;
V_429 = F_236 ( V_169 ) ;
V_2 -> V_430 += V_429 * V_431 ;
F_237 ( V_2 , V_429 ) ;
if ( V_432 && V_2 -> V_433 )
F_238 ( V_2 -> V_433 , V_429 ) ;
}
void F_239 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_434 = F_169 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_434 && ( F_176 ( V_2 ) || F_215 ( V_2 ) ) ) {
V_435:
F_5 ( V_434 ) -> V_64 |= V_94 ;
F_5 ( V_434 ) -> V_12 ++ ;
V_8 -> V_250 ++ ;
if ( ! F_176 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_240 ( V_324 , V_2 -> V_386 ) ;
if ( F_52 ( ! V_4 ) ) {
if ( V_434 )
goto V_435;
return;
}
F_241 ( V_4 , V_324 ) ;
F_235 ( V_2 , V_4 -> V_203 ) ;
F_48 ( V_4 , V_8 -> V_250 ,
V_236 | V_94 ) ;
F_118 ( V_2 , V_4 ) ;
}
F_209 ( V_2 , F_62 ( V_2 ) , V_380 ) ;
}
void F_242 ( struct V_1 * V_2 , T_10 V_436 )
{
struct V_3 * V_4 ;
V_4 = F_243 ( V_324 , V_436 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_437 ) ;
return;
}
F_241 ( V_4 , V_324 ) ;
F_48 ( V_4 , F_10 ( V_2 ) ,
V_236 | V_438 ) ;
F_99 ( & V_4 -> V_217 ) ;
if ( F_97 ( V_2 , V_4 , 0 , V_436 ) )
F_34 ( F_9 ( V_2 ) , V_437 ) ;
F_229 ( F_9 ( V_2 ) , V_439 ) ;
}
int F_244 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_182 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_64 & V_93 ) ) {
F_245 ( L_2 , V_440 ) ;
return - V_441 ;
}
if ( ! ( F_5 ( V_4 ) -> V_64 & V_236 ) ) {
if ( F_100 ( V_4 ) ) {
struct V_3 * V_350 = F_246 ( V_4 , V_180 ) ;
if ( ! V_350 )
return - V_279 ;
F_190 ( V_4 , V_2 ) ;
F_119 ( V_350 ) ;
F_247 ( V_2 , V_350 ) ;
F_191 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_350 -> V_203 ;
F_121 ( V_2 , V_350 -> V_203 ) ;
V_4 = V_350 ;
}
F_5 ( V_4 ) -> V_64 |= V_236 ;
F_36 ( V_2 , V_4 ) ;
}
return F_97 ( V_2 , V_4 , 1 , V_180 ) ;
}
struct V_3 * F_248 ( const struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_132 * V_133 ,
bool V_442 )
{
struct V_165 * V_166 = F_43 ( V_75 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_142 * V_143 = NULL ;
struct V_98 V_99 ;
struct V_3 * V_4 ;
int V_215 ;
struct V_76 * V_77 ;
T_6 V_443 ;
int V_19 ;
V_4 = F_243 ( V_324 , V_180 ) ;
if ( F_52 ( ! V_4 ) ) {
F_249 ( V_18 ) ;
return NULL ;
}
F_241 ( V_4 , V_324 ) ;
if ( V_442 ) {
F_250 ( V_4 , F_251 ( V_75 ) ) ;
} else {
F_250 ( V_4 , (struct V_1 * ) V_2 ) ;
}
F_252 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
V_443 = F_253 ( V_8 -> V_58 . V_443 ) ;
if ( V_443 && V_443 < V_19 )
V_19 = V_443 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
#ifdef F_254
if ( F_52 ( V_75 -> V_444 ) )
V_4 -> V_217 . V_445 = F_255 ( V_75 ) ;
else
#endif
F_99 ( & V_4 -> V_217 ) ;
#ifdef F_56
F_256 () ;
V_143 = F_257 ( V_75 ) -> V_149 -> V_446 ( V_2 , F_251 ( V_75 ) ) ;
#endif
F_258 ( V_4 , F_257 ( V_75 ) -> V_447 , V_448 ) ;
V_215 = F_58 ( V_75 , V_19 , V_4 , & V_99 , V_143 , V_133 ) +
sizeof( * V_77 ) ;
F_105 ( V_4 , V_215 ) ;
F_106 ( V_4 ) ;
V_77 = F_45 ( V_4 ) ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_449 = 1 ;
V_77 -> V_450 = 1 ;
F_42 ( V_75 , V_77 ) ;
V_77 -> V_222 = F_111 ( V_166 -> V_451 ) ;
V_77 -> V_224 = V_166 -> V_452 ;
F_48 ( V_4 , F_257 ( V_75 ) -> V_453 ,
V_93 | V_236 ) ;
V_77 -> V_82 = F_53 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_226 = F_53 ( F_257 ( V_75 ) -> V_60 ) ;
V_77 -> V_228 = F_111 ( F_20 ( V_75 -> V_454 , 65535U ) ) ;
F_51 ( ( T_8 * ) ( V_77 + 1 ) , NULL , & V_99 ) ;
V_77 -> V_455 = ( V_215 >> 2 ) ;
F_259 ( F_9 ( V_2 ) , V_238 ) ;
#ifdef F_56
if ( V_143 )
F_257 ( V_75 ) -> V_149 -> V_234 ( V_99 . V_105 ,
V_143 , F_251 ( V_75 ) , V_4 ) ;
F_260 () ;
#endif
V_4 -> V_242 . V_243 = 0 ;
return V_4 ;
}
static void F_261 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_456 * V_457 ;
T_4 V_458 = F_262 ( V_18 , V_459 ) ;
if ( V_458 == V_460 )
return;
F_256 () ;
V_457 = F_263 ( V_458 ) ;
if ( F_54 ( V_457 && F_264 ( V_457 -> V_461 ) ) ) {
F_265 ( V_6 -> V_462 -> V_461 ) ;
V_6 -> V_463 = F_266 ( V_18 ) ;
V_6 -> V_462 = V_457 ;
}
F_260 () ;
}
static void F_267 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_47 ;
V_8 -> V_80 = sizeof( struct V_76 ) +
( V_153 ? V_156 : 0 ) ;
#ifdef F_56
if ( V_8 -> V_149 -> V_150 ( V_2 , V_2 ) )
V_8 -> V_80 += V_151 ;
#endif
if ( V_8 -> V_58 . V_443 )
V_8 -> V_58 . V_292 = V_8 -> V_58 . V_443 ;
V_8 -> V_464 = 0 ;
F_156 ( V_2 ) ;
F_157 ( V_2 , F_159 ( V_18 ) ) ;
F_261 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_262 ( V_18 , V_465 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_58 . V_443 && V_8 -> V_58 . V_443 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_58 . V_443 ;
F_268 ( V_2 ) ;
if ( V_2 -> V_466 & V_467 &&
( V_8 -> V_45 > F_214 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_214 ( V_2 ) ;
F_28 ( F_214 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_58 . V_468 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_157 ,
& V_47 ,
F_262 ( V_18 , V_469 ) ) ;
V_8 -> V_58 . V_47 = V_47 ;
V_8 -> V_392 = V_8 -> V_44 ;
V_2 -> V_470 = 0 ;
F_269 ( V_2 , V_471 ) ;
V_8 -> V_345 = 0 ;
F_270 ( V_8 , 0 ) ;
V_8 -> V_95 = V_8 -> V_250 ;
V_8 -> V_317 = V_8 -> V_250 ;
V_8 -> V_96 = V_8 -> V_250 ;
V_8 -> V_11 = V_8 -> V_250 ;
if ( F_54 ( ! V_8 -> V_362 ) )
V_8 -> V_60 = 0 ;
else
V_8 -> V_472 = V_30 ;
V_8 -> V_59 = V_8 -> V_60 ;
V_8 -> V_473 = V_8 -> V_60 ;
F_2 ( V_2 ) -> V_28 = V_374 ;
F_2 ( V_2 ) -> V_474 = 0 ;
F_271 ( V_8 ) ;
}
static void F_272 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_212 * V_213 = F_5 ( V_4 ) ;
V_213 -> V_12 += V_4 -> V_81 ;
F_119 ( V_4 ) ;
F_273 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_4 -> V_203 ;
F_121 ( V_2 , V_4 -> V_203 ) ;
V_8 -> V_250 = V_213 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_274 ( struct V_1 * V_2 , struct V_3 * V_449 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_475 = V_8 -> V_148 ;
int V_476 = 0 , V_49 , V_216 = 0 ;
unsigned long V_477 = 0 ;
struct V_3 * V_478 ;
V_8 -> V_58 . V_292 = V_8 -> V_20 ;
F_275 ( V_2 , & V_8 -> V_58 . V_292 , & V_475 -> V_161 ,
& V_476 , & V_477 ) ;
if ( V_476 > 1 &&
F_276 ( V_479 , V_477 + ( 60 * V_349 << V_476 ) ) ) {
V_475 -> V_161 . V_81 = - 1 ;
goto V_480;
}
if ( V_481 & V_482 )
V_475 -> V_161 . V_81 = - 1 ;
else if ( V_475 -> V_161 . V_81 <= 0 )
goto V_480;
if ( V_8 -> V_58 . V_443 && V_8 -> V_58 . V_443 < V_8 -> V_58 . V_292 )
V_8 -> V_58 . V_292 = V_8 -> V_58 . V_443 ;
V_49 = F_152 ( V_2 , F_2 ( V_2 ) -> V_304 ) -
V_145 ;
V_49 = F_30 ( V_483 , V_49 , V_475 -> V_169 ) ;
V_49 = F_30 ( V_483 , V_49 , F_277 ( V_324 ) ) ;
V_478 = F_136 ( V_2 , V_49 , V_2 -> V_386 , false ) ;
if ( ! V_478 )
goto V_480;
V_478 -> V_89 = V_90 ;
memcpy ( V_478 -> V_244 , V_449 -> V_244 , sizeof( V_449 -> V_244 ) ) ;
if ( V_49 ) {
int V_484 = F_278 ( F_138 ( V_478 , V_49 ) , V_49 ,
& V_475 -> V_181 -> V_485 ) ;
if ( F_52 ( ! V_484 ) ) {
F_279 ( V_478 ) ;
goto V_480;
}
if ( V_484 != V_49 ) {
F_139 ( V_478 , V_484 ) ;
V_49 = V_484 ;
}
}
if ( V_49 == V_475 -> V_169 )
V_475 -> V_181 = NULL ;
V_475 -> V_484 = V_49 ;
F_272 ( V_2 , V_478 ) ;
V_216 = F_97 ( V_2 , V_478 , 1 , V_2 -> V_386 ) ;
V_449 -> V_217 = V_478 -> V_217 ;
F_5 ( V_478 ) -> V_82 ++ ;
F_5 ( V_478 ) -> V_64 = V_236 | V_280 ;
if ( ! V_216 ) {
V_8 -> V_478 = ( V_475 -> V_484 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_486;
}
V_480:
if ( V_475 -> V_161 . V_81 > 0 )
V_475 -> V_161 . V_81 = 0 ;
V_216 = F_97 ( V_2 , V_449 , 1 , V_2 -> V_386 ) ;
if ( V_216 )
V_8 -> V_163 = 0 ;
V_486:
V_475 -> V_161 . V_81 = - 1 ;
return V_216 ;
}
int F_280 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_274 ;
int V_216 ;
F_267 ( V_2 ) ;
if ( F_52 ( V_8 -> V_362 ) ) {
F_281 ( V_2 , NULL ) ;
return 0 ;
}
V_274 = F_136 ( V_2 , 0 , V_2 -> V_386 , true ) ;
if ( F_52 ( ! V_274 ) )
return - V_218 ;
F_48 ( V_274 , V_8 -> V_250 ++ , V_93 ) ;
V_8 -> V_416 = V_30 ;
F_272 ( V_2 , V_274 ) ;
F_39 ( V_2 , V_274 ) ;
V_216 = V_8 -> V_148 ? F_274 ( V_2 , V_274 ) :
F_97 ( V_2 , V_274 , 1 , V_2 -> V_386 ) ;
if ( V_216 == - V_487 )
return V_216 ;
V_8 -> V_11 = V_8 -> V_250 ;
V_8 -> V_488 = V_8 -> V_250 ;
F_229 ( F_9 ( V_2 ) , V_489 ) ;
F_201 ( V_2 , V_372 ,
F_2 ( V_2 ) -> V_28 , V_377 ) ;
return 0 ;
}
void F_282 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_367 ;
F_18 ( V_2 , V_490 ) ;
if ( V_37 > V_491 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_492 = V_349 / 2 ;
if ( V_6 -> V_35 . V_38 ||
( V_6 -> V_35 . V_493 & V_494 ) )
V_492 = V_375 ;
if ( V_8 -> V_346 ) {
int V_370 = F_29 ( int , F_198 ( V_8 -> V_346 >> 3 ) ,
V_491 ) ;
if ( V_370 < V_492 )
V_492 = V_370 ;
}
V_37 = F_20 ( V_37 , V_492 ) ;
}
V_367 = V_479 + V_37 ;
if ( V_6 -> V_35 . V_493 & V_495 ) {
if ( V_6 -> V_35 . V_496 ||
F_283 ( V_6 -> V_35 . V_367 , V_479 + ( V_37 >> 2 ) ) ) {
F_284 ( V_2 ) ;
return;
}
if ( ! F_276 ( V_367 , V_6 -> V_35 . V_367 ) )
V_367 = V_6 -> V_35 . V_367 ;
}
V_6 -> V_35 . V_493 |= V_497 | V_495 ;
V_6 -> V_35 . V_367 = V_367 ;
F_285 ( V_2 , & V_6 -> V_498 , V_367 ) ;
}
void F_284 ( struct V_1 * V_2 )
{
struct V_3 * V_274 ;
if ( V_2 -> V_173 == V_385 )
return;
F_18 ( V_2 , V_499 ) ;
V_274 = F_243 ( V_324 ,
F_210 ( V_2 , V_180 | V_500 ) ) ;
if ( F_52 ( ! V_274 ) ) {
F_286 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_501 ;
F_201 ( V_2 , V_40 ,
V_375 , V_377 ) ;
return;
}
F_241 ( V_274 , V_324 ) ;
F_48 ( V_274 , F_10 ( V_2 ) , V_236 ) ;
F_287 ( V_274 ) ;
F_99 ( & V_274 -> V_217 ) ;
F_97 ( V_2 , V_274 , 0 , ( V_502 T_10 ) 0 ) ;
}
static int F_288 ( struct V_1 * V_2 , int V_503 , int V_504 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_243 ( V_324 ,
F_210 ( V_2 , V_180 | V_500 ) ) ;
if ( ! V_4 )
return - 1 ;
F_241 ( V_4 , V_324 ) ;
F_48 ( V_4 , V_8 -> V_95 - ! V_503 , V_236 ) ;
F_99 ( & V_4 -> V_217 ) ;
F_34 ( F_9 ( V_2 ) , V_504 ) ;
return F_97 ( V_2 , V_4 , 0 , ( V_502 T_10 ) 0 ) ;
}
void F_289 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_505 ) {
F_3 ( V_2 ) -> V_506 = F_3 ( V_2 ) -> V_60 - 1 ;
F_288 ( V_2 , 0 , V_507 ) ;
}
}
int F_290 ( struct V_1 * V_2 , int V_504 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_385 )
return - 1 ;
V_4 = F_176 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_216 ;
unsigned int V_19 = F_62 ( V_2 ) ;
unsigned int V_508 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_488 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_488 = F_5 ( V_4 ) -> V_12 ;
if ( V_508 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_508 = F_20 ( V_508 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_280 ;
if ( F_132 ( V_2 , V_4 , V_508 , V_19 , V_180 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_122 ( V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_280 ;
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
if ( ! V_216 )
F_1 ( V_2 , V_4 ) ;
return V_216 ;
} else {
if ( F_291 ( V_8 -> V_96 , V_8 -> V_95 + 1 , V_8 -> V_95 + 0xFFFF ) )
F_288 ( V_2 , 1 , V_504 ) ;
return F_288 ( V_2 , 0 , V_504 ) ;
}
}
void F_292 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_295 * V_295 = F_9 ( V_2 ) ;
unsigned long V_509 ;
int V_216 ;
V_216 = F_290 ( V_2 , V_507 ) ;
if ( V_8 -> V_10 || ! F_176 ( V_2 ) ) {
V_6 -> V_510 = 0 ;
V_6 -> V_511 = 0 ;
return;
}
if ( V_216 <= 0 ) {
if ( V_6 -> V_511 < V_295 -> V_70 . V_512 )
V_6 -> V_511 ++ ;
V_6 -> V_510 ++ ;
V_509 = V_377 ;
} else {
if ( ! V_6 -> V_510 )
V_6 -> V_510 = 1 ;
V_509 = V_513 ;
}
F_201 ( V_2 , V_514 ,
F_293 ( V_2 , V_509 ) ,
V_377 ) ;
}
int F_294 ( const struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_515 * V_516 = F_257 ( V_75 ) -> V_149 ;
struct V_517 V_249 ;
int V_518 ;
F_257 ( V_75 ) -> V_447 = F_295 () ;
V_518 = V_516 -> V_519 ( V_2 , NULL , & V_249 , V_75 , NULL , true ) ;
if ( ! V_518 ) {
F_259 ( F_9 ( V_2 ) , V_411 ) ;
F_204 ( F_9 ( V_2 ) , V_412 ) ;
}
return V_518 ;
}
