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
F_42 ( const struct V_74 * V_75 , struct V_76 * V_77 ,
struct V_1 * V_2 )
{
if ( F_43 ( V_75 ) -> V_78 ) {
V_77 -> V_79 = 1 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
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
static unsigned int F_58 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
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
if ( V_4 -> V_81 != V_215 )
F_22 ( V_8 , V_2 ) ;
if ( F_112 ( V_213 -> V_12 , V_8 -> V_11 ) || V_213 -> V_82 == V_213 -> V_12 )
F_114 ( F_9 ( V_2 ) , V_237 ,
F_6 ( V_4 ) ) ;
V_8 -> V_238 += F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_239 = F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_240 = F_115 ( V_4 ) ;
V_4 -> V_241 . V_242 = 0 ;
memset ( V_4 -> V_243 , 0 , F_21 ( sizeof( struct V_244 ) ,
sizeof( struct V_245 ) ) ) ;
V_216 = V_6 -> V_198 -> V_246 ( V_2 , V_4 , & V_211 -> V_247 . V_248 ) ;
if ( F_54 ( V_216 <= 0 ) )
return V_216 ;
F_116 ( V_2 ) ;
return F_117 ( V_216 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_249 = F_5 ( V_4 ) -> V_12 ;
F_119 ( V_4 ) ;
F_120 ( V_2 , V_4 ) ;
V_2 -> V_250 += V_4 -> V_203 ;
F_121 ( V_2 , V_4 -> V_203 ) ;
}
static void F_122 ( struct V_3 * V_4 , unsigned int V_251 )
{
if ( V_4 -> V_81 <= V_251 || V_4 -> V_89 == V_252 ) {
F_49 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_253 = 0 ;
} else {
F_49 ( V_4 , F_123 ( V_4 -> V_81 , V_251 ) ) ;
F_5 ( V_4 ) -> V_253 = V_251 ;
}
}
static void F_124 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_254 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_255 || F_125 ( V_8 ) )
return;
if ( F_112 ( F_126 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_256 -= V_254 ;
}
static void F_127 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_254 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_254 ;
if ( F_5 ( V_4 ) -> V_92 & V_257 )
V_8 -> V_255 -= V_254 ;
if ( F_5 ( V_4 ) -> V_92 & V_258 )
V_8 -> V_259 -= V_254 ;
if ( F_5 ( V_4 ) -> V_92 & V_260 )
V_8 -> V_261 -= V_254 ;
if ( F_125 ( V_8 ) && V_254 > 0 )
V_8 -> V_255 -= F_30 ( T_4 , V_8 -> V_255 , V_254 ) ;
F_124 ( V_2 , V_4 , V_254 ) ;
if ( V_8 -> V_262 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_262 ) -> V_82 ) &&
( F_128 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_257 ) ) )
V_8 -> V_263 -= V_254 ;
F_129 ( V_8 ) ;
}
static void F_130 ( struct V_3 * V_4 , struct V_3 * V_264 )
{
struct V_265 * V_266 = F_46 ( V_4 ) ;
if ( F_52 ( V_266 -> V_267 & V_268 ) &&
! F_11 ( V_266 -> V_269 , F_5 ( V_264 ) -> V_82 ) ) {
struct V_265 * V_270 = F_46 ( V_264 ) ;
T_7 V_271 = V_266 -> V_267 & V_268 ;
V_266 -> V_267 &= ~ V_271 ;
V_270 -> V_267 |= V_271 ;
F_131 ( V_266 -> V_269 , V_270 -> V_269 ) ;
}
}
int F_132 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_251 , T_10 V_272 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_273 ;
int V_274 , V_275 ;
int V_276 ;
T_7 V_88 ;
if ( F_133 ( V_81 > V_4 -> V_81 ) )
return - V_277 ;
V_274 = F_134 ( V_4 ) - V_81 ;
if ( V_274 < 0 )
V_274 = 0 ;
if ( F_135 ( V_4 , V_272 ) )
return - V_278 ;
V_273 = F_136 ( V_2 , V_274 , V_272 , true ) ;
if ( ! V_273 )
return - V_278 ;
V_2 -> V_250 += V_273 -> V_203 ;
F_121 ( V_2 , V_273 -> V_203 ) ;
V_276 = V_4 -> V_81 - V_81 - V_274 ;
V_273 -> V_203 += V_276 ;
V_4 -> V_203 -= V_276 ;
F_5 ( V_273 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_273 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_273 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_279 ) ;
F_5 ( V_273 ) -> V_64 = V_88 ;
F_5 ( V_273 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
if ( ! F_46 ( V_4 ) -> V_280 && V_4 -> V_89 != V_90 ) {
V_273 -> V_91 = F_137 ( V_4 -> V_181 + V_81 ,
F_138 ( V_273 , V_274 ) ,
V_274 , 0 ) ;
F_139 ( V_4 , V_81 ) ;
V_4 -> V_91 = F_140 ( V_4 -> V_91 , V_273 -> V_91 , V_81 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_141 ( V_4 , V_273 , V_81 ) ;
}
V_273 -> V_89 = V_4 -> V_89 ;
V_273 -> V_241 = V_4 -> V_241 ;
F_130 ( V_4 , V_273 ) ;
V_275 = F_6 ( V_4 ) ;
F_122 ( V_4 , V_251 ) ;
F_122 ( V_273 , V_251 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_273 ) -> V_12 ) ) {
int V_281 = V_275 - F_6 ( V_4 ) -
F_6 ( V_273 ) ;
if ( V_281 )
F_127 ( V_2 , V_4 , V_281 ) ;
}
F_119 ( V_273 ) ;
F_142 ( V_4 , V_273 , V_2 ) ;
return 0 ;
}
static void F_143 ( struct V_3 * V_4 , int V_81 )
{
struct V_265 * V_266 ;
int V_200 , V_282 , V_283 ;
V_283 = F_30 ( int , V_81 , F_134 ( V_4 ) ) ;
if ( V_283 ) {
F_144 ( V_4 , V_283 ) ;
V_81 -= V_283 ;
if ( ! V_81 )
return;
}
V_283 = V_81 ;
V_282 = 0 ;
V_266 = F_46 ( V_4 ) ;
for ( V_200 = 0 ; V_200 < V_266 -> V_280 ; V_200 ++ ) {
int V_169 = F_145 ( & V_266 -> V_284 [ V_200 ] ) ;
if ( V_169 <= V_283 ) {
F_146 ( V_4 , V_200 ) ;
V_283 -= V_169 ;
} else {
V_266 -> V_284 [ V_282 ] = V_266 -> V_284 [ V_200 ] ;
if ( V_283 ) {
V_266 -> V_284 [ V_282 ] . V_285 += V_283 ;
F_147 ( & V_266 -> V_284 [ V_282 ] , V_283 ) ;
V_283 = 0 ;
}
V_282 ++ ;
}
}
V_266 -> V_280 = V_282 ;
F_148 ( V_4 ) ;
V_4 -> V_286 -= V_81 ;
V_4 -> V_81 = V_4 -> V_286 ;
}
int F_149 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_135 ( V_4 , V_180 ) )
return - V_278 ;
F_143 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_203 -= V_81 ;
V_2 -> V_250 -= V_81 ;
F_150 ( V_2 , V_81 ) ;
F_151 ( V_2 , V_287 ) ;
if ( F_6 ( V_4 ) > 1 )
F_122 ( V_4 , F_115 ( V_4 ) ) ;
return 0 ;
}
static inline int F_152 ( struct V_1 * V_2 , int V_288 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_251 ;
V_251 = V_288 - V_6 -> V_198 -> V_289 - sizeof( struct V_76 ) ;
if ( V_6 -> V_198 -> V_290 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_153 ( V_18 ) )
V_251 -= V_6 -> V_198 -> V_290 ;
}
if ( V_251 > V_8 -> V_58 . V_291 )
V_251 = V_8 -> V_58 . V_291 ;
V_251 -= V_6 -> V_292 ;
if ( V_251 < 48 )
V_251 = 48 ;
return V_251 ;
}
int F_154 ( struct V_1 * V_2 , int V_288 )
{
return F_152 ( V_2 , V_288 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_155 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_293 ;
V_293 = V_19 +
V_8 -> V_80 +
V_6 -> V_292 +
V_6 -> V_198 -> V_289 ;
if ( V_6 -> V_198 -> V_290 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_153 ( V_18 ) )
V_293 += V_6 -> V_198 -> V_290 ;
}
return V_293 ;
}
void F_156 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_294 * V_294 = F_9 ( V_2 ) ;
V_6 -> V_295 . V_296 = V_294 -> V_70 . V_297 > 1 ;
V_6 -> V_295 . V_298 = V_8 -> V_58 . V_291 + sizeof( struct V_76 ) +
V_6 -> V_198 -> V_289 ;
V_6 -> V_295 . V_299 = F_155 ( V_2 , V_294 -> V_70 . V_300 ) ;
V_6 -> V_295 . V_301 = 0 ;
if ( V_6 -> V_295 . V_296 )
V_6 -> V_295 . V_302 = V_30 ;
}
unsigned int F_157 ( struct V_1 * V_2 , T_4 V_288 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_251 ;
if ( V_6 -> V_295 . V_298 > V_288 )
V_6 -> V_295 . V_298 = V_288 ;
V_251 = F_154 ( V_2 , V_288 ) ;
V_251 = F_158 ( V_8 , V_251 ) ;
V_6 -> V_303 = V_288 ;
if ( V_6 -> V_295 . V_296 )
V_251 = F_20 ( V_251 , F_154 ( V_2 , V_6 -> V_295 . V_299 ) ) ;
V_8 -> V_304 = V_251 ;
return V_251 ;
}
unsigned int F_62 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_251 ;
unsigned int V_305 ;
struct V_98 V_99 ;
struct V_142 * V_143 ;
V_251 = V_8 -> V_304 ;
if ( V_18 ) {
T_4 V_293 = F_159 ( V_18 ) ;
if ( V_293 != F_2 ( V_2 ) -> V_303 )
V_251 = F_157 ( V_2 , V_293 ) ;
}
V_305 = F_59 ( V_2 , NULL , & V_99 , & V_143 ) +
sizeof( struct V_76 ) ;
if ( V_305 != V_8 -> V_80 ) {
int V_22 = ( int ) V_305 - V_8 -> V_80 ;
V_251 -= V_22 ;
}
return V_251 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_306 == V_307 &&
V_2 -> V_308 && ! F_161 ( V_309 , & V_2 -> V_308 -> V_88 ) ) {
T_4 V_310 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_311 = F_21 ( V_8 -> V_31 , V_310 ) ;
if ( V_311 < V_8 -> V_25 ) {
V_8 -> V_27 = F_19 ( V_2 ) ;
V_8 -> V_25 = ( V_8 -> V_25 + V_311 ) >> 1 ;
}
V_8 -> V_31 = 0 ;
}
V_8 -> V_29 = V_30 ;
}
static void F_162 ( struct V_1 * V_2 , bool V_312 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_95 , V_8 -> V_313 ) ||
V_8 -> V_10 > V_8 -> V_314 ) {
V_8 -> V_314 = V_8 -> V_10 ;
V_8 -> V_313 = V_8 -> V_11 ;
V_8 -> V_312 = V_312 ;
}
if ( F_163 ( V_2 ) ) {
V_8 -> V_31 = 0 ;
V_8 -> V_29 = V_30 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_31 )
V_8 -> V_31 = V_8 -> V_10 ;
if ( V_315 &&
( T_3 ) ( V_30 - V_8 -> V_29 ) >= F_2 ( V_2 ) -> V_28 )
F_160 ( V_2 ) ;
}
}
static bool F_164 ( const struct V_7 * V_8 )
{
return F_112 ( V_8 -> V_316 , V_8 -> V_95 ) &&
! F_112 ( V_8 -> V_316 , V_8 -> V_11 ) ;
}
static void F_165 ( struct V_7 * V_8 , unsigned int V_251 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_251 )
V_8 -> V_316 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_166 ( bool V_317 , const struct V_7 * V_8 ,
int V_179 )
{
return V_317 &&
( ( V_179 & V_318 ) ||
( ! V_179 && V_8 -> V_10 && F_164 ( V_8 ) ) ) ;
}
static T_4 F_167 ( const struct V_1 * V_2 , unsigned int V_251 )
{
T_4 V_319 , V_320 ;
V_319 = F_20 ( V_2 -> V_321 >> 10 ,
V_2 -> V_322 - 1 - V_323 ) ;
V_320 = F_29 ( T_4 , V_319 / V_251 , V_324 ) ;
return F_30 ( T_4 , V_320 , V_2 -> V_325 ) ;
}
static unsigned int F_168 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_251 ,
unsigned int V_326 ,
int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_317 , V_327 , V_228 , V_328 ;
V_228 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_328 = V_251 * V_326 ;
if ( F_54 ( V_328 <= V_228 && V_4 != F_169 ( V_2 ) ) )
return V_328 ;
V_327 = F_20 ( V_4 -> V_81 , V_228 ) ;
if ( V_328 <= V_327 )
return V_328 ;
V_317 = V_327 % V_251 ;
if ( F_166 ( V_317 != 0 , V_8 , V_179 ) )
return V_327 - V_317 ;
return V_327 ;
}
static inline unsigned int F_170 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_329 , V_24 , V_330 ;
if ( ( F_5 ( V_4 ) -> V_64 & V_94 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_329 = F_23 ( V_8 ) ;
V_24 = V_8 -> V_25 ;
if ( V_329 >= V_24 )
return 0 ;
V_330 = F_21 ( V_24 >> 1 , 1U ) ;
return F_20 ( V_330 , V_24 - V_329 ) ;
}
static int F_171 ( struct V_3 * V_4 , unsigned int V_251 )
{
int V_331 = F_6 ( V_4 ) ;
if ( ! V_331 || ( V_331 > 1 && F_115 ( V_4 ) != V_251 ) ) {
F_122 ( V_4 , V_251 ) ;
V_331 = F_6 ( V_4 ) ;
}
return V_331 ;
}
static inline bool F_172 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_332 , int V_179 )
{
if ( V_179 & V_333 )
return true ;
if ( F_50 ( V_8 ) || ( F_5 ( V_4 ) -> V_64 & V_94 ) )
return true ;
if ( ! F_166 ( V_4 -> V_81 < V_332 , V_8 , V_179 ) )
return true ;
return false ;
}
static bool F_173 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_332 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_332 )
V_12 = F_5 ( V_4 ) -> V_82 + V_332 ;
return ! F_112 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_174 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_332 , int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_334 ;
F_171 ( V_4 , V_332 ) ;
if ( ! F_172 ( V_8 , V_4 , V_332 , V_179 ) )
return 0 ;
V_334 = F_170 ( V_8 , V_4 ) ;
if ( V_334 && ! F_173 ( V_8 , V_4 , V_332 ) )
V_334 = 0 ;
return V_334 ;
}
bool F_175 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_176 ( V_2 ) ;
return V_4 &&
F_174 ( V_2 , V_4 , F_62 ( V_2 ) ,
( F_177 ( V_2 , V_4 ) ?
V_8 -> V_179 : V_333 ) ) ;
}
static int F_178 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_251 , T_10 V_272 )
{
struct V_3 * V_273 ;
int V_276 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_286 )
return F_132 ( V_2 , V_4 , V_81 , V_251 , V_272 ) ;
V_273 = F_136 ( V_2 , 0 , V_272 , true ) ;
if ( F_52 ( ! V_273 ) )
return - V_278 ;
V_2 -> V_250 += V_273 -> V_203 ;
F_121 ( V_2 , V_273 -> V_203 ) ;
V_273 -> V_203 += V_276 ;
V_4 -> V_203 -= V_276 ;
F_5 ( V_273 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_273 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_273 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_279 ) ;
F_5 ( V_273 ) -> V_64 = V_88 ;
F_5 ( V_273 ) -> V_92 = 0 ;
V_273 -> V_89 = V_4 -> V_89 = V_90 ;
F_141 ( V_4 , V_273 , V_81 ) ;
F_130 ( V_4 , V_273 ) ;
F_122 ( V_4 , V_251 ) ;
F_122 ( V_273 , V_251 ) ;
F_119 ( V_273 ) ;
F_142 ( V_4 , V_273 , V_2 ) ;
return 0 ;
}
static bool F_179 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_312 , T_4 V_326 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_335 , V_336 , V_337 , V_338 , V_329 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_217 V_32 ;
struct V_3 * V_188 ;
int V_339 ;
if ( F_5 ( V_4 ) -> V_64 & V_94 )
goto V_340;
if ( V_6 -> V_306 >= V_341 )
goto V_340;
if ( ( T_3 ) ( V_30 - V_8 -> V_34 ) > 0 )
goto V_340;
V_329 = F_23 ( V_8 ) ;
F_98 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_25 <= V_329 ) ) ;
V_336 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_337 = ( V_8 -> V_25 - V_329 ) * V_8 -> V_304 ;
V_338 = F_20 ( V_336 , V_337 ) ;
if ( V_338 >= V_326 * V_8 -> V_304 )
goto V_340;
if ( ( V_4 != F_169 ( V_2 ) ) && ( V_338 >= V_4 -> V_81 ) )
goto V_340;
V_339 = F_180 ( V_342 ) ;
if ( V_339 ) {
T_4 V_343 = F_20 ( V_8 -> V_344 , V_8 -> V_25 * V_8 -> V_304 ) ;
V_343 /= V_339 ;
if ( V_338 >= V_343 )
goto V_340;
} else {
if ( V_338 > F_181 ( V_8 ) * V_8 -> V_304 )
goto V_340;
}
V_188 = F_182 ( V_2 ) ;
F_99 ( & V_32 ) ;
V_335 = F_183 ( & V_32 , & V_188 -> V_217 ) ;
if ( V_335 < ( V_8 -> V_345 >> 4 ) )
goto V_340;
if ( V_337 < V_336 && V_337 < V_4 -> V_81 )
* V_312 = true ;
return true ;
V_340:
return false ;
}
static inline void F_184 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_294 * V_294 = F_9 ( V_2 ) ;
T_4 V_346 ;
T_3 V_22 ;
V_346 = V_294 -> V_70 . V_347 ;
V_22 = V_30 - V_6 -> V_295 . V_302 ;
if ( F_52 ( V_22 >= V_346 * V_348 ) ) {
int V_19 = F_62 ( V_2 ) ;
V_6 -> V_295 . V_301 = 0 ;
V_6 -> V_295 . V_298 = V_8 -> V_58 . V_291 +
sizeof( struct V_76 ) +
V_6 -> V_198 -> V_289 ;
V_6 -> V_295 . V_299 = F_155 ( V_2 , V_19 ) ;
V_6 -> V_295 . V_302 = V_30 ;
}
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_349 , * V_350 ;
struct V_294 * V_294 = F_9 ( V_2 ) ;
int V_81 ;
int V_301 ;
int V_351 ;
int V_352 ;
int V_251 ;
int V_346 ;
if ( ! V_6 -> V_295 . V_296 ||
V_6 -> V_295 . V_301 ||
F_2 ( V_2 ) -> V_306 != V_307 ||
V_8 -> V_25 < 11 ||
V_8 -> V_58 . V_171 || V_8 -> V_58 . V_123 )
return - 1 ;
V_251 = F_62 ( V_2 ) ;
V_301 = F_154 ( V_2 , ( V_6 -> V_295 . V_298 +
V_6 -> V_295 . V_299 ) >> 1 ) ;
V_351 = V_301 + ( V_8 -> V_353 + 1 ) * V_8 -> V_304 ;
V_346 = V_6 -> V_295 . V_298 - V_6 -> V_295 . V_299 ;
if ( V_301 > F_154 ( V_2 , V_6 -> V_295 . V_298 ) ||
V_346 < V_294 -> V_70 . V_354 ) {
F_184 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_249 - V_8 -> V_11 < V_351 )
return - 1 ;
if ( V_8 -> V_344 < V_351 )
return - 1 ;
if ( F_112 ( V_8 -> V_11 + V_351 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_25 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_349 = F_136 ( V_2 , V_301 , V_180 , false ) ;
if ( ! V_349 )
return - 1 ;
V_2 -> V_250 += V_349 -> V_203 ;
F_121 ( V_2 , V_349 -> V_203 ) ;
V_4 = F_176 ( V_2 ) ;
F_5 ( V_349 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_349 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_301 ;
F_5 ( V_349 ) -> V_64 = V_236 ;
F_5 ( V_349 ) -> V_92 = 0 ;
V_349 -> V_91 = 0 ;
V_349 -> V_89 = V_4 -> V_89 ;
F_186 ( V_349 , V_4 , V_2 ) ;
V_81 = 0 ;
F_187 (skb, next, sk) {
V_352 = F_30 ( int , V_4 -> V_81 , V_301 - V_81 ) ;
if ( V_349 -> V_89 )
F_188 ( V_4 , 0 , F_138 ( V_349 , V_352 ) , V_352 ) ;
else
V_349 -> V_91 = F_189 ( V_4 , 0 ,
F_138 ( V_349 , V_352 ) ,
V_352 , V_349 -> V_91 ) ;
if ( V_4 -> V_81 <= V_352 ) {
F_5 ( V_349 ) -> V_64 |= F_5 ( V_4 ) -> V_64 ;
F_190 ( V_4 , V_2 ) ;
F_191 ( V_2 , V_4 ) ;
} else {
F_5 ( V_349 ) -> V_64 |= F_5 ( V_4 ) -> V_64 &
~ ( V_94 | V_279 ) ;
if ( ! F_46 ( V_4 ) -> V_280 ) {
F_192 ( V_4 , V_352 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_193 ( V_4 -> V_181 ,
V_4 -> V_81 , 0 ) ;
} else {
F_143 ( V_4 , V_352 ) ;
F_122 ( V_4 , V_251 ) ;
}
F_5 ( V_4 ) -> V_82 += V_352 ;
}
V_81 += V_352 ;
if ( V_81 >= V_301 )
break;
}
F_171 ( V_349 , V_349 -> V_81 ) ;
if ( ! F_97 ( V_2 , V_349 , 1 , V_180 ) ) {
V_8 -> V_25 -- ;
F_1 ( V_2 , V_349 ) ;
V_6 -> V_295 . V_301 = F_155 ( V_2 , V_349 -> V_81 ) ;
V_8 -> V_355 . V_356 = F_5 ( V_349 ) -> V_82 ;
V_8 -> V_355 . V_357 = F_5 ( V_349 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_61 ( struct V_1 * V_2 , unsigned int V_251 , int V_179 ,
int V_358 , T_10 V_272 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_331 , V_359 ;
int V_334 ;
int V_360 ;
bool V_312 = false ;
T_4 V_326 ;
V_359 = 0 ;
if ( ! V_358 ) {
V_360 = F_185 ( V_2 ) ;
if ( ! V_360 ) {
return false ;
} else if ( V_360 > 0 ) {
V_359 = 1 ;
}
}
V_326 = F_167 ( V_2 , V_251 ) ;
while ( ( V_4 = F_176 ( V_2 ) ) ) {
unsigned int V_338 ;
V_331 = F_171 ( V_4 , V_251 ) ;
F_98 ( ! V_331 ) ;
if ( F_52 ( V_8 -> V_361 ) && V_8 -> V_362 == V_363 ) {
F_99 ( & V_4 -> V_217 ) ;
goto V_361;
}
V_334 = F_170 ( V_8 , V_4 ) ;
if ( ! V_334 ) {
V_312 = true ;
if ( V_358 == 2 )
V_334 = 1 ;
else
break;
}
if ( F_52 ( ! F_173 ( V_8 , V_4 , V_251 ) ) )
break;
if ( V_331 == 1 ) {
if ( F_52 ( ! F_172 ( V_8 , V_4 , V_251 ,
( F_177 ( V_2 , V_4 ) ?
V_179 : V_333 ) ) ) )
break;
} else {
if ( ! V_358 &&
F_179 ( V_2 , V_4 , & V_312 ,
V_326 ) )
break;
}
V_338 = V_251 ;
if ( V_331 > 1 && ! F_50 ( V_8 ) )
V_338 = F_168 ( V_2 , V_4 , V_251 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_179 ) ;
if ( V_4 -> V_81 > V_338 &&
F_52 ( F_178 ( V_2 , V_4 , V_338 , V_251 , V_272 ) ) )
break;
V_338 = F_21 ( 2 * V_4 -> V_203 , V_2 -> V_321 >> 10 ) ;
V_338 = F_30 ( T_4 , V_338 , V_364 ) ;
if ( F_194 ( & V_2 -> V_204 ) > V_338 ) {
F_73 ( V_207 , & V_8 -> V_191 ) ;
F_195 () ;
if ( F_194 ( & V_2 -> V_204 ) > V_338 )
break;
}
if ( F_52 ( F_97 ( V_2 , V_4 , 1 , V_272 ) ) )
break;
V_361:
F_1 ( V_2 , V_4 ) ;
F_165 ( V_8 , V_251 , V_4 ) ;
V_359 += F_6 ( V_4 ) ;
if ( V_358 )
break;
}
if ( F_54 ( V_359 ) ) {
if ( F_196 ( V_2 ) )
V_8 -> V_365 += V_359 ;
if ( V_358 != 2 )
F_197 ( V_2 ) ;
F_162 ( V_2 , V_312 ) ;
return false ;
}
return ! V_8 -> V_10 && F_176 ( V_2 ) ;
}
bool F_197 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_366 , V_367 , V_368 ;
T_4 V_369 = F_198 ( V_8 -> V_345 >> 3 ) ;
if ( F_133 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_133 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_173 == V_370 )
return false ;
if ( V_6 -> V_13 != V_371 )
return false ;
if ( V_372 < 3 || ! V_8 -> V_345 || ! V_8 -> V_10 ||
! F_199 ( V_8 ) || F_2 ( V_2 ) -> V_306 != V_307 )
return false ;
if ( ( V_8 -> V_25 > F_23 ( V_8 ) ) &&
F_176 ( V_2 ) )
return false ;
V_366 = V_369 << 1 ;
if ( V_8 -> V_10 == 1 )
V_366 = F_29 ( T_4 , V_366 ,
( V_369 + ( V_369 >> 1 ) + V_373 ) ) ;
V_366 = F_29 ( T_4 , V_366 , F_200 ( 10 ) ) ;
V_367 = V_30 + V_366 ;
V_368 = ( T_4 ) F_2 ( V_2 ) -> V_374 ;
if ( ( T_3 ) ( V_367 - V_368 ) > 0 ) {
T_3 V_22 = V_368 - V_30 ;
if ( V_22 > 0 )
V_366 = V_22 ;
}
F_201 ( V_2 , V_15 , V_366 ,
V_375 ) ;
return true ;
}
static bool F_202 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_52 ( F_203 ( V_2 , V_4 ) ) ) {
F_204 ( F_9 ( V_2 ) ,
V_376 ) ;
return true ;
}
return false ;
}
void F_205 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_377 ;
int V_19 = F_62 ( V_2 ) ;
V_4 = F_176 ( V_2 ) ;
if ( V_4 ) {
if ( F_173 ( V_8 , V_4 , V_19 ) ) {
V_377 = V_8 -> V_10 ;
F_61 ( V_2 , V_19 , V_378 , 2 , V_180 ) ;
if ( V_8 -> V_10 > V_377 )
goto V_379;
goto V_380;
}
V_4 = F_206 ( V_2 , V_4 ) ;
} else {
V_4 = F_169 ( V_2 ) ;
}
if ( V_8 -> V_381 )
goto V_380;
if ( F_133 ( ! V_4 ) )
goto V_380;
if ( F_202 ( V_2 , V_4 ) )
goto V_380;
V_377 = F_6 ( V_4 ) ;
if ( F_133 ( ! V_377 ) )
goto V_380;
if ( ( V_377 > 1 ) && ( V_4 -> V_81 > ( V_377 - 1 ) * V_19 ) ) {
if ( F_52 ( F_132 ( V_2 , V_4 , ( V_377 - 1 ) * V_19 , V_19 ,
V_180 ) ) )
goto V_380;
V_4 = F_207 ( V_2 , V_4 ) ;
}
if ( F_133 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_380;
if ( F_208 ( V_2 , V_4 ) )
goto V_380;
V_8 -> V_381 = V_8 -> V_11 ;
V_379:
F_204 ( F_9 ( V_2 ) , V_382 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_380:
F_7 ( V_2 ) ;
}
void F_209 ( struct V_1 * V_2 , unsigned int V_332 ,
int V_179 )
{
if ( F_52 ( V_2 -> V_173 == V_383 ) )
return;
if ( F_61 ( V_2 , V_332 , V_179 , 0 ,
F_210 ( V_2 , V_180 ) ) )
F_211 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 , unsigned int V_251 )
{
struct V_3 * V_4 = F_176 ( V_2 ) ;
F_98 ( ! V_4 || V_4 -> V_81 < V_251 ) ;
F_61 ( V_2 , V_251 , V_333 , 1 , V_2 -> V_384 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_385 ;
int V_386 = F_213 ( V_2 ) ;
int V_387 = F_214 ( V_2 ) ;
int V_388 = F_30 ( int , V_8 -> V_45 , V_387 ) ;
int V_228 ;
if ( V_19 > V_388 )
V_19 = V_388 ;
if ( V_386 < ( V_388 >> 1 ) ) {
V_6 -> V_35 . V_389 = 0 ;
if ( F_215 ( V_2 ) )
V_8 -> V_390 = F_20 ( V_8 -> V_390 ,
4U * V_8 -> V_20 ) ;
V_386 = F_216 ( V_386 , 1 << V_8 -> V_58 . V_47 ) ;
if ( V_386 < ( V_387 >> 4 ) || V_386 < V_19 )
return 0 ;
}
if ( V_386 > V_8 -> V_390 )
V_386 = V_8 -> V_390 ;
V_228 = V_8 -> V_44 ;
if ( V_8 -> V_58 . V_47 ) {
V_228 = V_386 ;
if ( ( ( V_228 >> V_8 -> V_58 . V_47 ) << V_8 -> V_58 . V_47 ) != V_228 )
V_228 = ( ( ( V_228 >> V_8 -> V_58 . V_47 ) + 1 )
<< V_8 -> V_58 . V_47 ) ;
} else {
if ( V_228 <= V_386 - V_19 || V_228 > V_386 )
V_228 = ( V_386 / V_19 ) * V_19 ;
else if ( V_19 == V_388 &&
V_386 > V_228 + ( V_388 >> 1 ) )
V_228 = V_386 ;
}
return V_228 ;
}
static void F_217 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_391 = F_207 ( V_2 , V_4 ) ;
int V_392 , V_393 ;
V_392 = V_4 -> V_81 ;
V_393 = V_391 -> V_81 ;
F_98 ( F_6 ( V_4 ) != 1 || F_6 ( V_391 ) != 1 ) ;
F_218 ( V_2 , V_391 , V_4 ) ;
F_190 ( V_391 , V_2 ) ;
F_219 ( V_391 , F_138 ( V_4 , V_393 ) ,
V_393 ) ;
if ( V_391 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_220 ( V_4 -> V_91 , V_391 -> V_91 , V_392 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_391 ) -> V_12 ;
F_5 ( V_4 ) -> V_64 |= F_5 ( V_391 ) -> V_64 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_391 ) -> V_92 & V_394 ;
F_221 ( V_8 ) ;
if ( V_391 == V_8 -> V_395 )
V_8 -> V_395 = V_4 ;
F_127 ( V_2 , V_391 , F_6 ( V_391 ) ) ;
F_191 ( V_2 , V_391 ) ;
}
static bool F_222 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_46 ( V_4 ) -> V_280 != 0 )
return false ;
if ( F_100 ( V_4 ) )
return false ;
if ( V_4 == F_176 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_257 )
return false ;
return true ;
}
static void F_223 ( struct V_1 * V_2 , struct V_3 * V_396 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_396 , * V_397 ;
bool V_398 = true ;
if ( ! V_399 )
return;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
return;
F_187 (skb, tmp, sk) {
if ( ! F_222 ( V_2 , V_4 ) )
break;
V_49 -= V_4 -> V_81 ;
if ( V_398 ) {
V_398 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_81 > F_224 ( V_396 ) )
break;
if ( F_112 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_217 ( V_2 , V_396 ) ;
}
}
int F_208 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_332 ;
int V_216 ;
if ( V_6 -> V_295 . V_301 ) {
V_6 -> V_295 . V_301 = 0 ;
}
if ( F_194 ( & V_2 -> V_204 ) >
F_20 ( V_2 -> V_250 + ( V_2 -> V_250 >> 2 ) , V_2 -> V_400 ) )
return - V_401 ;
if ( F_202 ( V_2 , V_4 ) )
return - V_402 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_95 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_95 ) )
F_225 () ;
if ( F_149 ( V_2 , V_4 , V_8 -> V_95 - F_5 ( V_4 ) -> V_82 ) )
return - V_278 ;
}
if ( F_2 ( V_2 ) -> V_198 -> V_403 ( V_2 ) )
return - V_404 ;
V_332 = F_62 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_95 )
return - V_401 ;
if ( V_4 -> V_81 > V_332 ) {
if ( F_132 ( V_2 , V_4 , V_332 , V_332 , V_180 ) )
return - V_278 ;
} else {
int V_405 = F_6 ( V_4 ) ;
if ( F_52 ( V_405 > 1 ) ) {
if ( F_135 ( V_4 , V_180 ) )
return - V_278 ;
F_171 ( V_4 , V_332 ) ;
F_127 ( V_2 , V_4 , V_405 - F_6 ( V_4 ) ) ;
}
}
if ( ( F_5 ( V_4 ) -> V_64 & V_406 ) == V_406 )
F_41 ( V_2 , V_4 ) ;
F_223 ( V_2 , V_4 , V_332 ) ;
if ( F_52 ( ( V_407 && ( ( unsigned long ) V_4 -> V_181 & 3 ) ) ||
F_226 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_349 = F_227 ( V_4 , V_323 ,
V_180 ) ;
V_216 = V_349 ? F_97 ( V_2 , V_349 , 0 , V_180 ) :
- V_218 ;
} else {
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
}
if ( F_54 ( ! V_216 ) ) {
F_5 ( V_4 ) -> V_92 |= V_394 ;
F_228 ( F_9 ( V_2 ) , V_408 ) ;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
F_204 ( F_9 ( V_2 ) , V_409 ) ;
V_8 -> V_410 ++ ;
}
return V_216 ;
}
int F_229 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_216 = F_208 ( V_2 , V_4 ) ;
if ( V_216 == 0 ) {
#if V_411 > 0
if ( F_5 ( V_4 ) -> V_92 & V_258 ) {
F_230 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_259 )
V_8 -> V_412 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_92 |= V_413 ;
V_8 -> V_259 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_414 )
V_8 -> V_414 = F_57 ( V_4 ) ;
F_5 ( V_4 ) -> V_226 = V_8 -> V_11 ;
} else if ( V_216 != - V_402 ) {
F_204 ( F_9 ( V_2 ) , V_415 ) ;
}
if ( V_8 -> V_416 < 0 )
V_8 -> V_416 = 0 ;
V_8 -> V_416 += F_6 ( V_4 ) ;
return V_216 ;
}
static bool F_231 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_306 != V_341 )
return false ;
if ( F_125 ( V_8 ) )
return false ;
if ( F_175 ( V_2 ) )
return false ;
return true ;
}
void F_232 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_417 = NULL ;
T_4 V_418 ;
int V_419 ;
int V_420 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_261 )
V_8 -> V_421 = V_8 -> V_95 ;
if ( V_8 -> V_395 ) {
V_4 = V_8 -> V_395 ;
V_418 = F_5 ( V_4 ) -> V_12 ;
if ( F_112 ( V_418 , V_8 -> V_421 ) )
V_418 = V_8 -> V_421 ;
} else {
V_4 = F_182 ( V_2 ) ;
V_418 = V_8 -> V_95 ;
}
F_233 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
if ( V_4 == F_176 ( V_2 ) )
break;
if ( ! V_417 )
V_8 -> V_395 = V_4 ;
if ( F_23 ( V_8 ) >= V_8 -> V_25 )
return;
if ( V_420 ) {
V_422:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_126 ( V_8 ) ) )
break;
V_419 = V_423 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_421 ) ) {
V_8 -> V_421 = V_418 ;
if ( ! F_231 ( V_2 ) )
break;
if ( V_417 ) {
V_4 = V_417 ;
V_417 = NULL ;
}
V_420 = 1 ;
goto V_422;
} else if ( ! ( V_92 & V_260 ) ) {
if ( ! V_417 && ! ( V_92 & ( V_258 | V_257 ) ) )
V_417 = V_4 ;
continue;
} else {
V_418 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_306 != V_424 )
V_419 = V_425 ;
else
V_419 = V_426 ;
}
if ( V_92 & ( V_257 | V_258 ) )
continue;
if ( F_229 ( V_2 , V_4 ) )
return;
F_204 ( F_9 ( V_2 ) , V_419 ) ;
if ( F_196 ( V_2 ) )
V_8 -> V_365 += F_6 ( V_4 ) ;
if ( V_4 == F_182 ( V_2 ) )
F_201 ( V_2 , V_371 ,
F_2 ( V_2 ) -> V_28 ,
V_375 ) ;
}
}
void F_234 ( struct V_1 * V_2 , int V_169 )
{
int V_427 , V_428 ;
if ( V_169 <= V_2 -> V_429 )
return;
V_427 = F_235 ( V_169 ) ;
V_2 -> V_429 += V_427 * V_430 ;
F_236 ( V_2 , V_427 , & V_428 ) ;
}
void F_237 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_431 = F_169 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_431 && ( F_176 ( V_2 ) || F_215 ( V_2 ) ) ) {
V_432:
F_5 ( V_431 ) -> V_64 |= V_94 ;
F_5 ( V_431 ) -> V_12 ++ ;
V_8 -> V_249 ++ ;
if ( ! F_176 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_238 ( V_323 , V_2 -> V_384 ) ;
if ( F_52 ( ! V_4 ) ) {
if ( V_431 )
goto V_432;
return;
}
F_239 ( V_4 , V_323 ) ;
F_234 ( V_2 , V_4 -> V_203 ) ;
F_48 ( V_4 , V_8 -> V_249 ,
V_236 | V_94 ) ;
F_118 ( V_2 , V_4 ) ;
}
F_209 ( V_2 , F_62 ( V_2 ) , V_378 ) ;
}
void F_240 ( struct V_1 * V_2 , T_10 V_433 )
{
struct V_3 * V_4 ;
V_4 = F_241 ( V_323 , V_433 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_434 ) ;
return;
}
F_239 ( V_4 , V_323 ) ;
F_48 ( V_4 , F_10 ( V_2 ) ,
V_236 | V_435 ) ;
F_99 ( & V_4 -> V_217 ) ;
if ( F_97 ( V_2 , V_4 , 0 , V_433 ) )
F_34 ( F_9 ( V_2 ) , V_434 ) ;
F_228 ( F_9 ( V_2 ) , V_436 ) ;
}
int F_242 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_182 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_64 & V_93 ) ) {
F_243 ( L_2 , V_437 ) ;
return - V_438 ;
}
if ( ! ( F_5 ( V_4 ) -> V_64 & V_236 ) ) {
if ( F_100 ( V_4 ) ) {
struct V_3 * V_349 = F_244 ( V_4 , V_180 ) ;
if ( ! V_349 )
return - V_278 ;
F_190 ( V_4 , V_2 ) ;
F_119 ( V_349 ) ;
F_245 ( V_2 , V_349 ) ;
F_191 ( V_2 , V_4 ) ;
V_2 -> V_250 += V_349 -> V_203 ;
F_121 ( V_2 , V_349 -> V_203 ) ;
V_4 = V_349 ;
}
F_5 ( V_4 ) -> V_64 |= V_236 ;
F_36 ( V_2 , V_4 ) ;
}
return F_97 ( V_2 , V_4 , 1 , V_180 ) ;
}
struct V_3 * F_246 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_132 * V_133 )
{
struct V_98 V_99 ;
struct V_165 * V_166 = F_43 ( V_75 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_76 * V_77 ;
struct V_3 * V_4 ;
struct V_142 * V_143 = NULL ;
int V_215 ;
int V_19 ;
V_4 = F_247 ( V_2 , V_323 , 1 , V_180 ) ;
if ( F_52 ( ! V_4 ) ) {
F_248 ( V_18 ) ;
return NULL ;
}
F_239 ( V_4 , V_323 ) ;
F_249 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_58 . V_439 && V_8 -> V_58 . V_439 < V_19 )
V_19 = V_8 -> V_58 . V_439 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
#ifdef F_250
if ( F_52 ( V_75 -> V_440 ) )
V_4 -> V_217 . V_441 = F_251 ( V_75 ) ;
else
#endif
F_99 ( & V_4 -> V_217 ) ;
#ifdef F_56
F_252 () ;
V_143 = F_253 ( V_75 ) -> V_149 -> V_442 ( V_2 , F_254 ( V_75 ) ) ;
#endif
V_215 = F_58 ( V_2 , V_75 , V_19 , V_4 , & V_99 , V_143 ,
V_133 ) + sizeof( * V_77 ) ;
F_105 ( V_4 , V_215 ) ;
F_106 ( V_4 ) ;
V_77 = F_45 ( V_4 ) ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_443 = 1 ;
V_77 -> V_444 = 1 ;
F_42 ( V_75 , V_77 , V_2 ) ;
V_77 -> V_222 = F_111 ( V_166 -> V_445 ) ;
V_77 -> V_224 = V_166 -> V_446 ;
F_48 ( V_4 , F_253 ( V_75 ) -> V_447 ,
V_93 | V_236 ) ;
V_77 -> V_82 = F_53 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_226 = F_53 ( F_253 ( V_75 ) -> V_60 ) ;
V_77 -> V_228 = F_111 ( F_20 ( V_75 -> V_44 , 65535U ) ) ;
F_51 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_99 ) ;
V_77 -> V_448 = ( V_215 >> 2 ) ;
F_255 ( F_9 ( V_2 ) , V_237 ) ;
#ifdef F_56
if ( V_143 )
F_253 ( V_75 ) -> V_149 -> V_234 ( V_99 . V_105 ,
V_143 , F_254 ( V_75 ) , V_4 ) ;
F_256 () ;
#endif
V_4 -> V_241 . V_242 = 0 ;
return V_4 ;
}
static void F_257 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_449 * V_450 ;
T_4 V_451 = F_258 ( V_18 , V_452 ) ;
if ( V_451 == V_453 )
return;
F_252 () ;
V_450 = F_259 ( V_451 ) ;
if ( F_54 ( V_450 && F_260 ( V_450 -> V_454 ) ) ) {
F_261 ( V_6 -> V_455 -> V_454 ) ;
V_6 -> V_456 = F_262 ( V_18 ) ;
V_6 -> V_455 = V_450 ;
}
F_256 () ;
}
static void F_263 ( struct V_1 * V_2 )
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
if ( V_8 -> V_58 . V_439 )
V_8 -> V_58 . V_291 = V_8 -> V_58 . V_439 ;
V_8 -> V_457 = 0 ;
F_156 ( V_2 ) ;
F_157 ( V_2 , F_159 ( V_18 ) ) ;
F_257 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_258 ( V_18 , V_458 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_58 . V_439 && V_8 -> V_58 . V_439 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_58 . V_439 ;
F_264 ( V_2 ) ;
if ( V_2 -> V_459 & V_460 &&
( V_8 -> V_45 > F_214 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_214 ( V_2 ) ;
F_28 ( F_214 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_58 . V_461 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_157 ,
& V_47 ,
F_258 ( V_18 , V_462 ) ) ;
V_8 -> V_58 . V_47 = V_47 ;
V_8 -> V_390 = V_8 -> V_44 ;
V_2 -> V_463 = 0 ;
F_265 ( V_2 , V_464 ) ;
V_8 -> V_344 = 0 ;
F_266 ( V_8 , 0 ) ;
V_8 -> V_95 = V_8 -> V_249 ;
V_8 -> V_316 = V_8 -> V_249 ;
V_8 -> V_96 = V_8 -> V_249 ;
V_8 -> V_11 = V_8 -> V_249 ;
if ( F_54 ( ! V_8 -> V_361 ) )
V_8 -> V_60 = 0 ;
else
V_8 -> V_465 = V_30 ;
V_8 -> V_59 = V_8 -> V_60 ;
V_8 -> V_466 = V_8 -> V_60 ;
F_2 ( V_2 ) -> V_28 = V_467 ;
F_2 ( V_2 ) -> V_468 = 0 ;
F_267 ( V_8 ) ;
}
static void F_268 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_212 * V_213 = F_5 ( V_4 ) ;
V_213 -> V_12 += V_4 -> V_81 ;
F_119 ( V_4 ) ;
F_269 ( V_2 , V_4 ) ;
V_2 -> V_250 += V_4 -> V_203 ;
F_121 ( V_2 , V_4 -> V_203 ) ;
V_8 -> V_249 = V_213 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_270 ( struct V_1 * V_2 , struct V_3 * V_443 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_469 = V_8 -> V_148 ;
int V_470 = 0 , V_49 , V_216 = 0 , V_471 ;
unsigned long V_472 = 0 ;
struct V_3 * V_473 ;
V_8 -> V_58 . V_291 = V_8 -> V_20 ;
F_271 ( V_2 , & V_8 -> V_58 . V_291 , & V_469 -> V_161 ,
& V_470 , & V_472 ) ;
if ( V_470 > 1 &&
F_272 ( V_474 , V_472 + ( 60 * V_348 << V_470 ) ) ) {
V_469 -> V_161 . V_81 = - 1 ;
goto V_475;
}
if ( V_476 & V_477 )
V_469 -> V_161 . V_81 = - 1 ;
else if ( V_469 -> V_161 . V_81 <= 0 )
goto V_475;
if ( V_8 -> V_58 . V_439 && V_8 -> V_58 . V_439 < V_8 -> V_58 . V_291 )
V_8 -> V_58 . V_291 = V_8 -> V_58 . V_439 ;
V_49 = F_152 ( V_2 , F_2 ( V_2 ) -> V_303 ) -
V_145 ;
V_49 = F_30 ( V_478 , V_49 , V_469 -> V_169 ) ;
V_49 = F_30 ( V_478 , V_49 , F_273 ( V_323 ) ) ;
V_473 = F_136 ( V_2 , V_49 , V_2 -> V_384 , false ) ;
if ( ! V_473 )
goto V_475;
V_473 -> V_89 = V_90 ;
memcpy ( V_473 -> V_243 , V_443 -> V_243 , sizeof( V_443 -> V_243 ) ) ;
V_471 = F_274 ( F_138 ( V_473 , V_49 ) , V_49 ,
& V_469 -> V_181 -> V_479 ) ;
if ( F_52 ( ! V_471 ) ) {
F_275 ( V_473 ) ;
goto V_475;
}
if ( V_471 != V_49 ) {
F_139 ( V_473 , V_471 ) ;
V_49 = V_471 ;
}
if ( V_49 == V_469 -> V_169 )
V_469 -> V_181 = NULL ;
V_469 -> V_471 = V_49 ;
F_268 ( V_2 , V_473 ) ;
V_216 = F_97 ( V_2 , V_473 , 1 , V_2 -> V_384 ) ;
V_443 -> V_217 = V_473 -> V_217 ;
F_5 ( V_473 ) -> V_82 ++ ;
F_5 ( V_473 ) -> V_64 = V_236 | V_279 ;
if ( ! V_216 ) {
V_8 -> V_473 = ( V_469 -> V_471 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_480;
}
V_475:
if ( V_469 -> V_161 . V_81 > 0 )
V_469 -> V_161 . V_81 = 0 ;
V_216 = F_97 ( V_2 , V_443 , 1 , V_2 -> V_384 ) ;
if ( V_216 )
V_8 -> V_163 = 0 ;
V_480:
V_469 -> V_161 . V_81 = - 1 ;
return V_216 ;
}
int F_276 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_273 ;
int V_216 ;
F_263 ( V_2 ) ;
if ( F_52 ( V_8 -> V_361 ) ) {
F_277 ( V_2 , NULL ) ;
return 0 ;
}
V_273 = F_136 ( V_2 , 0 , V_2 -> V_384 , true ) ;
if ( F_52 ( ! V_273 ) )
return - V_218 ;
F_48 ( V_273 , V_8 -> V_249 ++ , V_93 ) ;
V_8 -> V_414 = V_30 ;
F_268 ( V_2 , V_273 ) ;
F_39 ( V_2 , V_273 ) ;
V_216 = V_8 -> V_148 ? F_270 ( V_2 , V_273 ) :
F_97 ( V_2 , V_273 , 1 , V_2 -> V_384 ) ;
if ( V_216 == - V_481 )
return V_216 ;
V_8 -> V_11 = V_8 -> V_249 ;
V_8 -> V_482 = V_8 -> V_249 ;
F_228 ( F_9 ( V_2 ) , V_483 ) ;
F_201 ( V_2 , V_371 ,
F_2 ( V_2 ) -> V_28 , V_375 ) ;
return 0 ;
}
void F_278 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_366 ;
F_18 ( V_2 , V_484 ) ;
if ( V_37 > V_485 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_486 = V_348 / 2 ;
if ( V_6 -> V_35 . V_38 ||
( V_6 -> V_35 . V_487 & V_488 ) )
V_486 = V_373 ;
if ( V_8 -> V_345 ) {
int V_369 = F_29 ( int , F_198 ( V_8 -> V_345 >> 3 ) ,
V_485 ) ;
if ( V_369 < V_486 )
V_486 = V_369 ;
}
V_37 = F_20 ( V_37 , V_486 ) ;
}
V_366 = V_474 + V_37 ;
if ( V_6 -> V_35 . V_487 & V_489 ) {
if ( V_6 -> V_35 . V_490 ||
F_279 ( V_6 -> V_35 . V_366 , V_474 + ( V_37 >> 2 ) ) ) {
F_280 ( V_2 ) ;
return;
}
if ( ! F_272 ( V_366 , V_6 -> V_35 . V_366 ) )
V_366 = V_6 -> V_35 . V_366 ;
}
V_6 -> V_35 . V_487 |= V_491 | V_489 ;
V_6 -> V_35 . V_366 = V_366 ;
F_281 ( V_2 , & V_6 -> V_492 , V_366 ) ;
}
void F_280 ( struct V_1 * V_2 )
{
struct V_3 * V_273 ;
if ( V_2 -> V_173 == V_383 )
return;
F_18 ( V_2 , V_493 ) ;
V_273 = F_241 ( V_323 , F_210 ( V_2 , V_180 ) ) ;
if ( ! V_273 ) {
F_282 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_494 ;
F_201 ( V_2 , V_40 ,
V_373 , V_375 ) ;
return;
}
F_239 ( V_273 , V_323 ) ;
F_48 ( V_273 , F_10 ( V_2 ) , V_236 ) ;
F_283 ( V_273 ) ;
F_99 ( & V_273 -> V_217 ) ;
F_97 ( V_2 , V_273 , 0 , F_210 ( V_2 , V_180 ) ) ;
}
static int F_284 ( struct V_1 * V_2 , int V_495 , int V_496 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_241 ( V_323 , F_210 ( V_2 , V_180 ) ) ;
if ( ! V_4 )
return - 1 ;
F_239 ( V_4 , V_323 ) ;
F_48 ( V_4 , V_8 -> V_95 - ! V_495 , V_236 ) ;
F_99 ( & V_4 -> V_217 ) ;
F_34 ( F_9 ( V_2 ) , V_496 ) ;
return F_97 ( V_2 , V_4 , 0 , V_180 ) ;
}
void F_285 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_497 ) {
F_3 ( V_2 ) -> V_498 = F_3 ( V_2 ) -> V_60 - 1 ;
F_284 ( V_2 , 0 , V_499 ) ;
}
}
int F_286 ( struct V_1 * V_2 , int V_496 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_383 )
return - 1 ;
V_4 = F_176 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_216 ;
unsigned int V_19 = F_62 ( V_2 ) ;
unsigned int V_500 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_482 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_482 = F_5 ( V_4 ) -> V_12 ;
if ( V_500 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_500 = F_20 ( V_500 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_279 ;
if ( F_132 ( V_2 , V_4 , V_500 , V_19 , V_180 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_122 ( V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_279 ;
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
if ( ! V_216 )
F_1 ( V_2 , V_4 ) ;
return V_216 ;
} else {
if ( F_287 ( V_8 -> V_96 , V_8 -> V_95 + 1 , V_8 -> V_95 + 0xFFFF ) )
F_284 ( V_2 , 1 , V_496 ) ;
return F_284 ( V_2 , 0 , V_496 ) ;
}
}
void F_288 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_501 ;
int V_216 ;
V_216 = F_286 ( V_2 , V_499 ) ;
if ( V_8 -> V_10 || ! F_176 ( V_2 ) ) {
V_6 -> V_502 = 0 ;
V_6 -> V_503 = 0 ;
return;
}
if ( V_216 <= 0 ) {
if ( V_6 -> V_503 < V_504 )
V_6 -> V_503 ++ ;
V_6 -> V_502 ++ ;
V_501 = V_375 ;
} else {
if ( ! V_6 -> V_502 )
V_6 -> V_502 = 1 ;
V_501 = V_505 ;
}
F_201 ( V_2 , V_506 ,
F_289 ( V_2 , V_501 ) ,
V_375 ) ;
}
int F_290 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_507 * V_508 = F_253 ( V_75 ) -> V_149 ;
struct V_509 V_248 ;
int V_510 ;
V_510 = V_508 -> V_511 ( V_2 , NULL , & V_248 , V_75 , 0 , NULL ) ;
if ( ! V_510 ) {
F_255 ( F_9 ( V_2 ) , V_408 ) ;
F_204 ( F_9 ( V_2 ) , V_409 ) ;
}
return V_510 ;
}
