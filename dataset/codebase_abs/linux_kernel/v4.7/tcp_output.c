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
if ( V_208 ) {
F_98 ( & V_4 -> V_217 ) ;
if ( F_51 ( F_99 ( V_4 ) ) )
V_4 = F_100 ( V_4 , V_209 ) ;
else
V_4 = F_101 ( V_4 , V_209 ) ;
if ( F_51 ( ! V_4 ) )
return - V_218 ;
}
V_211 = F_102 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_213 = F_5 ( V_4 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( F_51 ( V_213 -> V_64 & V_93 ) )
V_214 = F_54 ( V_2 , V_4 , & V_99 , & V_143 ) ;
else
V_214 = F_58 ( V_2 , V_4 , & V_99 ,
& V_143 ) ;
V_215 = V_214 + sizeof( struct V_76 ) ;
V_4 -> V_219 = F_103 ( V_2 ) < F_89 ( 1 ) ;
F_104 ( V_4 , V_215 ) ;
F_105 ( V_4 ) ;
F_106 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_220 = F_107 ( V_4 ) ? V_221 : F_87 ;
F_108 ( V_4 , V_2 ) ;
F_109 ( V_4 -> V_203 , & V_2 -> V_204 ) ;
V_77 = (struct V_76 * ) V_4 -> V_181 ;
V_77 -> V_222 = V_211 -> V_223 ;
V_77 -> V_224 = V_211 -> V_225 ;
V_77 -> V_82 = F_52 ( V_213 -> V_82 ) ;
V_77 -> V_226 = F_52 ( V_8 -> V_60 ) ;
* ( ( ( V_227 * ) V_77 ) + 6 ) = F_110 ( ( ( V_215 >> 2 ) << 12 ) |
V_213 -> V_64 ) ;
V_77 -> V_228 = 0 ;
V_77 -> V_229 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_213 -> V_82 , V_8 -> V_96 ) ) ) {
if ( F_11 ( V_8 -> V_96 , V_213 -> V_82 + 0x10000 ) ) {
V_77 -> V_229 = F_110 ( V_8 -> V_96 - V_213 -> V_82 ) ;
V_77 -> V_230 = 1 ;
} else if ( F_111 ( V_213 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_229 = F_110 ( 0xFFFF ) ;
V_77 -> V_230 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_99 ) ;
F_45 ( V_4 ) -> V_85 = V_2 -> V_231 ;
if ( F_53 ( ! ( V_213 -> V_64 & V_93 ) ) ) {
V_77 -> V_232 = F_110 ( F_31 ( V_2 ) ) ;
F_44 ( V_2 , V_4 , V_77 , V_215 ) ;
} else {
V_77 -> V_232 = F_110 ( F_20 ( V_8 -> V_44 , 65535U ) ) ;
}
#ifdef F_55
if ( V_143 ) {
F_112 ( V_2 , V_233 ) ;
V_8 -> V_149 -> V_234 ( V_99 . V_105 ,
V_143 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_198 -> V_235 ( V_2 , V_4 ) ;
if ( F_53 ( V_213 -> V_64 & V_236 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_215 ) {
F_22 ( V_8 , V_2 ) ;
V_8 -> V_237 += F_6 ( V_4 ) ;
}
if ( F_111 ( V_213 -> V_12 , V_8 -> V_11 ) || V_213 -> V_82 == V_213 -> V_12 )
F_113 ( F_9 ( V_2 ) , V_238 ,
F_6 ( V_4 ) ) ;
V_8 -> V_239 += F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_240 = F_6 ( V_4 ) ;
F_45 ( V_4 ) -> V_241 = F_114 ( V_4 ) ;
V_4 -> V_242 . V_243 = 0 ;
memset ( V_4 -> V_244 , 0 , F_21 ( sizeof( struct V_245 ) ,
sizeof( struct V_246 ) ) ) ;
V_216 = V_6 -> V_198 -> V_247 ( V_2 , V_4 , & V_211 -> V_248 . V_249 ) ;
if ( F_53 ( V_216 <= 0 ) )
return V_216 ;
F_115 ( V_2 ) ;
return F_116 ( V_216 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_250 = F_5 ( V_4 ) -> V_12 ;
F_118 ( V_4 ) ;
F_119 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_4 -> V_203 ;
F_120 ( V_2 , V_4 -> V_203 ) ;
}
static void F_121 ( struct V_3 * V_4 , unsigned int V_252 )
{
if ( V_4 -> V_81 <= V_252 || V_4 -> V_89 == V_253 ) {
F_48 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_254 = 0 ;
} else {
F_48 ( V_4 , F_122 ( V_4 -> V_81 , V_252 ) ) ;
F_5 ( V_4 ) -> V_254 = V_252 ;
}
}
static void F_123 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_255 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_256 || F_124 ( V_8 ) )
return;
if ( F_111 ( F_125 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_257 -= V_255 ;
}
static void F_126 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_255 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_255 ;
if ( F_5 ( V_4 ) -> V_92 & V_258 )
V_8 -> V_256 -= V_255 ;
if ( F_5 ( V_4 ) -> V_92 & V_259 )
V_8 -> V_260 -= V_255 ;
if ( F_5 ( V_4 ) -> V_92 & V_261 )
V_8 -> V_262 -= V_255 ;
if ( F_124 ( V_8 ) && V_255 > 0 )
V_8 -> V_256 -= F_30 ( T_4 , V_8 -> V_256 , V_255 ) ;
F_123 ( V_2 , V_4 , V_255 ) ;
if ( V_8 -> V_263 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_263 ) -> V_82 ) &&
( F_127 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_258 ) ) )
V_8 -> V_264 -= V_255 ;
F_128 ( V_8 ) ;
}
static bool F_129 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_265 ||
( F_45 ( V_4 ) -> V_266 & V_267 ) ;
}
static void F_130 ( struct V_3 * V_4 , struct V_3 * V_268 )
{
struct V_269 * V_270 = F_45 ( V_4 ) ;
if ( F_51 ( F_129 ( V_4 ) ) &&
! F_11 ( V_270 -> V_271 , F_5 ( V_268 ) -> V_82 ) ) {
struct V_269 * V_272 = F_45 ( V_268 ) ;
T_7 V_273 = V_270 -> V_266 & V_267 ;
V_270 -> V_266 &= ~ V_273 ;
V_272 -> V_266 |= V_273 ;
F_131 ( V_270 -> V_271 , V_272 -> V_271 ) ;
F_5 ( V_268 ) -> V_265 = F_5 ( V_4 ) -> V_265 ;
F_5 ( V_4 ) -> V_265 = 0 ;
}
}
static void F_132 ( struct V_3 * V_4 , struct V_3 * V_268 )
{
F_5 ( V_268 ) -> V_274 = F_5 ( V_4 ) -> V_274 ;
F_5 ( V_4 ) -> V_274 = 0 ;
}
int F_133 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_252 , T_10 V_275 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_276 ;
int V_277 , V_278 ;
int V_279 ;
T_7 V_88 ;
if ( F_134 ( V_81 > V_4 -> V_81 ) )
return - V_280 ;
V_277 = F_135 ( V_4 ) - V_81 ;
if ( V_277 < 0 )
V_277 = 0 ;
if ( F_136 ( V_4 , V_275 ) )
return - V_281 ;
V_276 = F_137 ( V_2 , V_277 , V_275 , true ) ;
if ( ! V_276 )
return - V_281 ;
V_2 -> V_251 += V_276 -> V_203 ;
F_120 ( V_2 , V_276 -> V_203 ) ;
V_279 = V_4 -> V_81 - V_81 - V_277 ;
V_276 -> V_203 += V_279 ;
V_4 -> V_203 -= V_279 ;
F_5 ( V_276 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_276 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_276 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_282 ) ;
F_5 ( V_276 ) -> V_64 = V_88 ;
F_5 ( V_276 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
F_132 ( V_4 , V_276 ) ;
if ( ! F_45 ( V_4 ) -> V_283 && V_4 -> V_89 != V_90 ) {
V_276 -> V_91 = F_138 ( V_4 -> V_181 + V_81 ,
F_139 ( V_276 , V_277 ) ,
V_277 , 0 ) ;
F_140 ( V_4 , V_81 ) ;
V_4 -> V_91 = F_141 ( V_4 -> V_91 , V_276 -> V_91 , V_81 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_142 ( V_4 , V_276 , V_81 ) ;
}
V_276 -> V_89 = V_4 -> V_89 ;
V_276 -> V_242 = V_4 -> V_242 ;
F_130 ( V_4 , V_276 ) ;
V_278 = F_6 ( V_4 ) ;
F_121 ( V_4 , V_252 ) ;
F_121 ( V_276 , V_252 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_276 ) -> V_12 ) ) {
int V_284 = V_278 - F_6 ( V_4 ) -
F_6 ( V_276 ) ;
if ( V_284 )
F_126 ( V_2 , V_4 , V_284 ) ;
}
F_118 ( V_276 ) ;
F_143 ( V_4 , V_276 , V_2 ) ;
return 0 ;
}
static void F_144 ( struct V_3 * V_4 , int V_81 )
{
struct V_269 * V_270 ;
int V_200 , V_285 , V_286 ;
V_286 = F_30 ( int , V_81 , F_135 ( V_4 ) ) ;
if ( V_286 ) {
F_145 ( V_4 , V_286 ) ;
V_81 -= V_286 ;
if ( ! V_81 )
return;
}
V_286 = V_81 ;
V_285 = 0 ;
V_270 = F_45 ( V_4 ) ;
for ( V_200 = 0 ; V_200 < V_270 -> V_283 ; V_200 ++ ) {
int V_169 = F_146 ( & V_270 -> V_287 [ V_200 ] ) ;
if ( V_169 <= V_286 ) {
F_147 ( V_4 , V_200 ) ;
V_286 -= V_169 ;
} else {
V_270 -> V_287 [ V_285 ] = V_270 -> V_287 [ V_200 ] ;
if ( V_286 ) {
V_270 -> V_287 [ V_285 ] . V_288 += V_286 ;
F_148 ( & V_270 -> V_287 [ V_285 ] , V_286 ) ;
V_286 = 0 ;
}
V_285 ++ ;
}
}
V_270 -> V_283 = V_285 ;
F_149 ( V_4 ) ;
V_4 -> V_289 -= V_81 ;
V_4 -> V_81 = V_4 -> V_289 ;
}
int F_150 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_136 ( V_4 , V_180 ) )
return - V_281 ;
F_144 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_203 -= V_81 ;
V_2 -> V_251 -= V_81 ;
F_151 ( V_2 , V_81 ) ;
F_152 ( V_2 , V_290 ) ;
if ( F_6 ( V_4 ) > 1 )
F_121 ( V_4 , F_114 ( V_4 ) ) ;
return 0 ;
}
static inline int F_153 ( struct V_1 * V_2 , int V_291 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_252 ;
V_252 = V_291 - V_6 -> V_198 -> V_292 - sizeof( struct V_76 ) ;
if ( V_6 -> V_198 -> V_293 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_252 -= V_6 -> V_198 -> V_293 ;
}
if ( V_252 > V_8 -> V_58 . V_294 )
V_252 = V_8 -> V_58 . V_294 ;
V_252 -= V_6 -> V_295 ;
if ( V_252 < 48 )
V_252 = 48 ;
return V_252 ;
}
int F_155 ( struct V_1 * V_2 , int V_291 )
{
return F_153 ( V_2 , V_291 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_156 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_296 ;
V_296 = V_19 +
V_8 -> V_80 +
V_6 -> V_295 +
V_6 -> V_198 -> V_292 ;
if ( V_6 -> V_198 -> V_293 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_296 += V_6 -> V_198 -> V_293 ;
}
return V_296 ;
}
void F_157 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_297 * V_297 = F_9 ( V_2 ) ;
V_6 -> V_298 . V_299 = V_297 -> V_70 . V_300 > 1 ;
V_6 -> V_298 . V_301 = V_8 -> V_58 . V_294 + sizeof( struct V_76 ) +
V_6 -> V_198 -> V_292 ;
V_6 -> V_298 . V_302 = F_156 ( V_2 , V_297 -> V_70 . V_303 ) ;
V_6 -> V_298 . V_304 = 0 ;
if ( V_6 -> V_298 . V_299 )
V_6 -> V_298 . V_305 = V_30 ;
}
unsigned int F_158 ( struct V_1 * V_2 , T_4 V_291 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_252 ;
if ( V_6 -> V_298 . V_301 > V_291 )
V_6 -> V_298 . V_301 = V_291 ;
V_252 = F_155 ( V_2 , V_291 ) ;
V_252 = F_159 ( V_8 , V_252 ) ;
V_6 -> V_306 = V_291 ;
if ( V_6 -> V_298 . V_299 )
V_252 = F_20 ( V_252 , F_155 ( V_2 , V_6 -> V_298 . V_302 ) ) ;
V_8 -> V_307 = V_252 ;
return V_252 ;
}
unsigned int F_61 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_252 ;
unsigned int V_308 ;
struct V_98 V_99 ;
struct V_142 * V_143 ;
V_252 = V_8 -> V_307 ;
if ( V_18 ) {
T_4 V_296 = F_160 ( V_18 ) ;
if ( V_296 != F_2 ( V_2 ) -> V_306 )
V_252 = F_158 ( V_2 , V_296 ) ;
}
V_308 = F_58 ( V_2 , NULL , & V_99 , & V_143 ) +
sizeof( struct V_76 ) ;
if ( V_308 != V_8 -> V_80 ) {
int V_22 = ( int ) V_308 - V_8 -> V_80 ;
V_252 -= V_22 ;
}
return V_252 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_309 == V_310 &&
V_2 -> V_311 && ! F_162 ( V_312 , & V_2 -> V_311 -> V_88 ) ) {
T_4 V_313 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_314 = F_21 ( V_8 -> V_31 , V_313 ) ;
if ( V_314 < V_8 -> V_25 ) {
V_8 -> V_27 = F_19 ( V_2 ) ;
V_8 -> V_25 = ( V_8 -> V_25 + V_314 ) >> 1 ;
}
V_8 -> V_31 = 0 ;
}
V_8 -> V_29 = V_30 ;
}
static void F_163 ( struct V_1 * V_2 , bool V_315 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_95 , V_8 -> V_316 ) ||
V_8 -> V_10 > V_8 -> V_317 ) {
V_8 -> V_317 = V_8 -> V_10 ;
V_8 -> V_316 = V_8 -> V_11 ;
V_8 -> V_315 = V_315 ;
}
if ( F_164 ( V_2 ) ) {
V_8 -> V_31 = 0 ;
V_8 -> V_29 = V_30 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_31 )
V_8 -> V_31 = V_8 -> V_10 ;
if ( V_318 &&
( T_3 ) ( V_30 - V_8 -> V_29 ) >= F_2 ( V_2 ) -> V_28 )
F_161 ( V_2 ) ;
}
}
static bool F_165 ( const struct V_7 * V_8 )
{
return F_111 ( V_8 -> V_319 , V_8 -> V_95 ) &&
! F_111 ( V_8 -> V_319 , V_8 -> V_11 ) ;
}
static void F_166 ( struct V_7 * V_8 , unsigned int V_252 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_252 )
V_8 -> V_319 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_167 ( bool V_320 , const struct V_7 * V_8 ,
int V_179 )
{
return V_320 &&
( ( V_179 & V_321 ) ||
( ! V_179 && V_8 -> V_10 && F_165 ( V_8 ) ) ) ;
}
static T_4 F_168 ( const struct V_1 * V_2 , unsigned int V_252 )
{
T_4 V_322 , V_323 ;
V_322 = F_20 ( V_2 -> V_324 >> 10 ,
V_2 -> V_325 - 1 - V_326 ) ;
V_323 = F_29 ( T_4 , V_322 / V_252 , V_327 ) ;
return F_30 ( T_4 , V_323 , V_2 -> V_328 ) ;
}
static unsigned int F_169 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_252 ,
unsigned int V_329 ,
int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_320 , V_330 , V_232 , V_331 ;
V_232 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_331 = V_252 * V_329 ;
if ( F_53 ( V_331 <= V_232 && V_4 != F_170 ( V_2 ) ) )
return V_331 ;
V_330 = F_20 ( V_4 -> V_81 , V_232 ) ;
if ( V_331 <= V_330 )
return V_331 ;
V_320 = V_330 % V_252 ;
if ( F_167 ( V_320 != 0 , V_8 , V_179 ) )
return V_330 - V_320 ;
return V_330 ;
}
static inline unsigned int F_171 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_332 , V_24 , V_333 ;
if ( ( F_5 ( V_4 ) -> V_64 & V_94 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_332 = F_23 ( V_8 ) ;
V_24 = V_8 -> V_25 ;
if ( V_332 >= V_24 )
return 0 ;
V_333 = F_21 ( V_24 >> 1 , 1U ) ;
return F_20 ( V_333 , V_24 - V_332 ) ;
}
static int F_172 ( struct V_3 * V_4 , unsigned int V_252 )
{
int V_334 = F_6 ( V_4 ) ;
if ( ! V_334 || ( V_334 > 1 && F_114 ( V_4 ) != V_252 ) ) {
F_121 ( V_4 , V_252 ) ;
V_334 = F_6 ( V_4 ) ;
}
return V_334 ;
}
static inline bool F_173 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_335 , int V_179 )
{
if ( V_179 & V_336 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_64 & V_94 ) )
return true ;
if ( ! F_167 ( V_4 -> V_81 < V_335 , V_8 , V_179 ) )
return true ;
return false ;
}
static bool F_174 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_335 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_335 )
V_12 = F_5 ( V_4 ) -> V_82 + V_335 ;
return ! F_111 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_175 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_335 , int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_337 ;
F_172 ( V_4 , V_335 ) ;
if ( ! F_173 ( V_8 , V_4 , V_335 , V_179 ) )
return 0 ;
V_337 = F_171 ( V_8 , V_4 ) ;
if ( V_337 && ! F_174 ( V_8 , V_4 , V_335 ) )
V_337 = 0 ;
return V_337 ;
}
bool F_176 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_177 ( V_2 ) ;
return V_4 &&
F_175 ( V_2 , V_4 , F_61 ( V_2 ) ,
( F_178 ( V_2 , V_4 ) ?
V_8 -> V_179 : V_336 ) ) ;
}
static int F_179 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_252 , T_10 V_275 )
{
struct V_3 * V_276 ;
int V_279 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_289 )
return F_133 ( V_2 , V_4 , V_81 , V_252 , V_275 ) ;
V_276 = F_137 ( V_2 , 0 , V_275 , true ) ;
if ( F_51 ( ! V_276 ) )
return - V_281 ;
V_2 -> V_251 += V_276 -> V_203 ;
F_120 ( V_2 , V_276 -> V_203 ) ;
V_276 -> V_203 += V_279 ;
V_4 -> V_203 -= V_279 ;
F_5 ( V_276 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_276 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_276 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_64 ;
F_5 ( V_4 ) -> V_64 = V_88 & ~ ( V_94 | V_282 ) ;
F_5 ( V_276 ) -> V_64 = V_88 ;
F_5 ( V_276 ) -> V_92 = 0 ;
F_132 ( V_4 , V_276 ) ;
V_276 -> V_89 = V_4 -> V_89 = V_90 ;
F_142 ( V_4 , V_276 , V_81 ) ;
F_130 ( V_4 , V_276 ) ;
F_121 ( V_4 , V_252 ) ;
F_121 ( V_276 , V_252 ) ;
F_118 ( V_276 ) ;
F_143 ( V_4 , V_276 , V_2 ) ;
return 0 ;
}
static bool F_180 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_315 , T_4 V_329 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_338 , V_339 , V_340 , V_341 , V_332 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_217 V_32 ;
struct V_3 * V_188 ;
int V_342 ;
if ( F_5 ( V_4 ) -> V_64 & V_94 )
goto V_343;
if ( V_6 -> V_309 >= V_344 )
goto V_343;
if ( ( T_3 ) ( V_30 - V_8 -> V_34 ) > 0 )
goto V_343;
V_332 = F_23 ( V_8 ) ;
F_97 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_25 <= V_332 ) ) ;
V_339 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_340 = ( V_8 -> V_25 - V_332 ) * V_8 -> V_307 ;
V_341 = F_20 ( V_339 , V_340 ) ;
if ( V_341 >= V_329 * V_8 -> V_307 )
goto V_343;
if ( ( V_4 != F_170 ( V_2 ) ) && ( V_341 >= V_4 -> V_81 ) )
goto V_343;
V_342 = F_181 ( V_345 ) ;
if ( V_342 ) {
T_4 V_346 = F_20 ( V_8 -> V_347 , V_8 -> V_25 * V_8 -> V_307 ) ;
V_346 /= V_342 ;
if ( V_341 >= V_346 )
goto V_343;
} else {
if ( V_341 > F_182 ( V_8 ) * V_8 -> V_307 )
goto V_343;
}
V_188 = F_183 ( V_2 ) ;
F_98 ( & V_32 ) ;
V_338 = F_184 ( & V_32 , & V_188 -> V_217 ) ;
if ( V_338 < ( V_8 -> V_348 >> 4 ) )
goto V_343;
if ( V_340 < V_339 && V_340 <= V_4 -> V_81 )
* V_315 = true ;
return true ;
V_343:
return false ;
}
static inline void F_185 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_297 * V_297 = F_9 ( V_2 ) ;
T_4 V_349 ;
T_3 V_22 ;
V_349 = V_297 -> V_70 . V_350 ;
V_22 = V_30 - V_6 -> V_298 . V_305 ;
if ( F_51 ( V_22 >= V_349 * V_351 ) ) {
int V_19 = F_61 ( V_2 ) ;
V_6 -> V_298 . V_304 = 0 ;
V_6 -> V_298 . V_301 = V_8 -> V_58 . V_294 +
sizeof( struct V_76 ) +
V_6 -> V_198 -> V_292 ;
V_6 -> V_298 . V_302 = F_156 ( V_2 , V_19 ) ;
V_6 -> V_298 . V_305 = V_30 ;
}
}
static int F_186 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_352 , * V_353 ;
struct V_297 * V_297 = F_9 ( V_2 ) ;
int V_81 ;
int V_304 ;
int V_354 ;
int V_355 ;
int V_252 ;
int V_349 ;
if ( ! V_6 -> V_298 . V_299 ||
V_6 -> V_298 . V_304 ||
F_2 ( V_2 ) -> V_309 != V_310 ||
V_8 -> V_25 < 11 ||
V_8 -> V_58 . V_171 || V_8 -> V_58 . V_123 )
return - 1 ;
V_252 = F_61 ( V_2 ) ;
V_304 = F_155 ( V_2 , ( V_6 -> V_298 . V_301 +
V_6 -> V_298 . V_302 ) >> 1 ) ;
V_354 = V_304 + ( V_8 -> V_356 + 1 ) * V_8 -> V_307 ;
V_349 = V_6 -> V_298 . V_301 - V_6 -> V_298 . V_302 ;
if ( V_304 > F_155 ( V_2 , V_6 -> V_298 . V_301 ) ||
V_349 < V_297 -> V_70 . V_357 ) {
F_185 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_250 - V_8 -> V_11 < V_354 )
return - 1 ;
if ( V_8 -> V_347 < V_354 )
return - 1 ;
if ( F_111 ( V_8 -> V_11 + V_354 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_23 ( V_8 ) + 2 > V_8 -> V_25 ) {
if ( ! F_23 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_352 = F_137 ( V_2 , V_304 , V_180 , false ) ;
if ( ! V_352 )
return - 1 ;
V_2 -> V_251 += V_352 -> V_203 ;
F_120 ( V_2 , V_352 -> V_203 ) ;
V_4 = F_177 ( V_2 ) ;
F_5 ( V_352 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_352 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_304 ;
F_5 ( V_352 ) -> V_64 = V_236 ;
F_5 ( V_352 ) -> V_92 = 0 ;
V_352 -> V_91 = 0 ;
V_352 -> V_89 = V_4 -> V_89 ;
F_187 ( V_352 , V_4 , V_2 ) ;
V_81 = 0 ;
F_188 (skb, next, sk) {
V_355 = F_30 ( int , V_4 -> V_81 , V_304 - V_81 ) ;
if ( V_352 -> V_89 )
F_189 ( V_4 , 0 , F_139 ( V_352 , V_355 ) , V_355 ) ;
else
V_352 -> V_91 = F_190 ( V_4 , 0 ,
F_139 ( V_352 , V_355 ) ,
V_355 , V_352 -> V_91 ) ;
if ( V_4 -> V_81 <= V_355 ) {
F_5 ( V_352 ) -> V_64 |= F_5 ( V_4 ) -> V_64 ;
F_191 ( V_4 , V_2 ) ;
F_192 ( V_2 , V_4 ) ;
} else {
F_5 ( V_352 ) -> V_64 |= F_5 ( V_4 ) -> V_64 &
~ ( V_94 | V_282 ) ;
if ( ! F_45 ( V_4 ) -> V_283 ) {
F_193 ( V_4 , V_355 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_194 ( V_4 -> V_181 ,
V_4 -> V_81 , 0 ) ;
} else {
F_144 ( V_4 , V_355 ) ;
F_121 ( V_4 , V_252 ) ;
}
F_5 ( V_4 ) -> V_82 += V_355 ;
}
V_81 += V_355 ;
if ( V_81 >= V_304 )
break;
}
F_172 ( V_352 , V_352 -> V_81 ) ;
if ( ! F_96 ( V_2 , V_352 , 1 , V_180 ) ) {
V_8 -> V_25 -- ;
F_1 ( V_2 , V_352 ) ;
V_6 -> V_298 . V_304 = F_156 ( V_2 , V_352 -> V_81 ) ;
V_8 -> V_358 . V_359 = F_5 ( V_352 ) -> V_82 ;
V_8 -> V_358 . V_360 = F_5 ( V_352 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_60 ( struct V_1 * V_2 , unsigned int V_252 , int V_179 ,
int V_361 , T_10 V_275 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_334 , V_362 ;
int V_337 ;
int V_363 ;
bool V_315 = false ;
T_4 V_329 ;
V_362 = 0 ;
if ( ! V_361 ) {
V_363 = F_186 ( V_2 ) ;
if ( ! V_363 ) {
return false ;
} else if ( V_363 > 0 ) {
V_362 = 1 ;
}
}
V_329 = F_168 ( V_2 , V_252 ) ;
while ( ( V_4 = F_177 ( V_2 ) ) ) {
unsigned int V_341 ;
V_334 = F_172 ( V_4 , V_252 ) ;
F_97 ( ! V_334 ) ;
if ( F_51 ( V_8 -> V_364 ) && V_8 -> V_365 == V_366 ) {
F_98 ( & V_4 -> V_217 ) ;
goto V_364;
}
V_337 = F_171 ( V_8 , V_4 ) ;
if ( ! V_337 ) {
if ( V_361 == 2 )
V_337 = 1 ;
else
break;
}
if ( F_51 ( ! F_174 ( V_8 , V_4 , V_252 ) ) )
break;
if ( V_334 == 1 ) {
if ( F_51 ( ! F_173 ( V_8 , V_4 , V_252 ,
( F_178 ( V_2 , V_4 ) ?
V_179 : V_336 ) ) ) )
break;
} else {
if ( ! V_361 &&
F_180 ( V_2 , V_4 , & V_315 ,
V_329 ) )
break;
}
V_341 = V_252 ;
if ( V_334 > 1 && ! F_49 ( V_8 ) )
V_341 = F_169 ( V_2 , V_4 , V_252 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_179 ) ;
if ( V_4 -> V_81 > V_341 &&
F_51 ( F_179 ( V_2 , V_4 , V_341 , V_252 , V_275 ) ) )
break;
V_341 = F_21 ( 2 * V_4 -> V_203 , V_2 -> V_324 >> 10 ) ;
V_341 = F_30 ( T_4 , V_341 , V_367 ) ;
if ( F_195 ( & V_2 -> V_204 ) > V_341 ) {
F_72 ( V_207 , & V_8 -> V_191 ) ;
F_196 () ;
if ( F_195 ( & V_2 -> V_204 ) > V_341 )
break;
}
if ( F_51 ( F_96 ( V_2 , V_4 , 1 , V_275 ) ) )
break;
V_364:
F_1 ( V_2 , V_4 ) ;
F_166 ( V_8 , V_252 , V_4 ) ;
V_362 += F_6 ( V_4 ) ;
if ( V_361 )
break;
}
if ( F_53 ( V_362 ) ) {
if ( F_197 ( V_2 ) )
V_8 -> V_368 += V_362 ;
if ( V_361 != 2 )
F_198 ( V_2 ) ;
V_315 |= ( F_23 ( V_8 ) >= V_8 -> V_25 ) ;
F_163 ( V_2 , V_315 ) ;
return false ;
}
return ! V_8 -> V_10 && F_177 ( V_2 ) ;
}
bool F_198 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_369 , V_370 , V_371 ;
T_4 V_372 = F_199 ( V_8 -> V_348 >> 3 ) ;
if ( F_134 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_134 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_8 -> V_373 )
return false ;
if ( V_6 -> V_13 != V_374 )
return false ;
if ( V_375 < 3 || ! V_8 -> V_10 ||
! F_200 ( V_8 ) || F_2 ( V_2 ) -> V_309 != V_310 )
return false ;
if ( ( V_8 -> V_25 > F_23 ( V_8 ) ) &&
F_177 ( V_2 ) )
return false ;
V_369 = V_372 << 1 ? : V_376 ;
if ( V_8 -> V_10 == 1 )
V_369 = F_29 ( T_4 , V_369 ,
( V_372 + ( V_372 >> 1 ) + V_377 ) ) ;
V_369 = F_29 ( T_4 , V_369 , F_201 ( 10 ) ) ;
V_370 = V_30 + V_369 ;
V_371 = ( T_4 ) F_2 ( V_2 ) -> V_378 ;
if ( ( T_3 ) ( V_370 - V_371 ) > 0 ) {
T_3 V_22 = V_371 - V_30 ;
if ( V_22 > 0 )
V_369 = V_22 ;
}
F_202 ( V_2 , V_15 , V_369 ,
V_379 ) ;
return true ;
}
static bool F_203 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_204 ( V_2 , V_4 ) ) ) {
F_34 ( F_9 ( V_2 ) ,
V_380 ) ;
return true ;
}
return false ;
}
void F_205 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_381 ;
int V_19 = F_61 ( V_2 ) ;
V_4 = F_177 ( V_2 ) ;
if ( V_4 ) {
if ( F_174 ( V_8 , V_4 , V_19 ) ) {
V_381 = V_8 -> V_10 ;
F_60 ( V_2 , V_19 , V_382 , 2 , V_180 ) ;
if ( V_8 -> V_10 > V_381 )
goto V_383;
goto V_384;
}
V_4 = F_206 ( V_2 , V_4 ) ;
} else {
V_4 = F_170 ( V_2 ) ;
}
if ( V_8 -> V_385 )
goto V_384;
if ( F_134 ( ! V_4 ) )
goto V_384;
if ( F_203 ( V_2 , V_4 ) )
goto V_384;
V_381 = F_6 ( V_4 ) ;
if ( F_134 ( ! V_381 ) )
goto V_384;
if ( ( V_381 > 1 ) && ( V_4 -> V_81 > ( V_381 - 1 ) * V_19 ) ) {
if ( F_51 ( F_133 ( V_2 , V_4 , ( V_381 - 1 ) * V_19 , V_19 ,
V_180 ) ) )
goto V_384;
V_4 = F_207 ( V_2 , V_4 ) ;
}
if ( F_134 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_384;
if ( F_208 ( V_2 , V_4 , 1 ) )
goto V_384;
V_8 -> V_385 = V_8 -> V_11 ;
V_383:
F_34 ( F_9 ( V_2 ) , V_386 ) ;
F_2 ( V_2 ) -> V_13 = 0 ;
V_384:
F_7 ( V_2 ) ;
}
void F_209 ( struct V_1 * V_2 , unsigned int V_335 ,
int V_179 )
{
if ( F_51 ( V_2 -> V_173 == V_387 ) )
return;
if ( F_60 ( V_2 , V_335 , V_179 , 0 ,
F_210 ( V_2 , V_180 ) ) )
F_211 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 , unsigned int V_252 )
{
struct V_3 * V_4 = F_177 ( V_2 ) ;
F_97 ( ! V_4 || V_4 -> V_81 < V_252 ) ;
F_60 ( V_2 , V_252 , V_336 , 1 , V_2 -> V_388 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_389 ;
int V_390 = F_213 ( V_2 ) ;
int V_391 = F_214 ( V_2 ) ;
int V_392 = F_30 ( int , V_8 -> V_45 , V_391 ) ;
int V_232 ;
if ( V_19 > V_392 )
V_19 = V_392 ;
if ( V_390 < ( V_392 >> 1 ) ) {
V_6 -> V_35 . V_393 = 0 ;
if ( F_215 ( V_2 ) )
V_8 -> V_394 = F_20 ( V_8 -> V_394 ,
4U * V_8 -> V_20 ) ;
V_390 = F_216 ( V_390 , 1 << V_8 -> V_58 . V_47 ) ;
if ( V_390 < ( V_391 >> 4 ) || V_390 < V_19 )
return 0 ;
}
if ( V_390 > V_8 -> V_394 )
V_390 = V_8 -> V_394 ;
V_232 = V_8 -> V_44 ;
if ( V_8 -> V_58 . V_47 ) {
V_232 = V_390 ;
if ( ( ( V_232 >> V_8 -> V_58 . V_47 ) << V_8 -> V_58 . V_47 ) != V_232 )
V_232 = ( ( ( V_232 >> V_8 -> V_58 . V_47 ) + 1 )
<< V_8 -> V_58 . V_47 ) ;
} else {
if ( V_232 <= V_390 - V_19 || V_232 > V_390 )
V_232 = ( V_390 / V_19 ) * V_19 ;
else if ( V_19 == V_392 &&
V_390 > V_232 + ( V_392 >> 1 ) )
V_232 = V_390 ;
}
return V_232 ;
}
void F_217 ( struct V_3 * V_4 ,
const struct V_3 * V_395 )
{
if ( F_51 ( F_129 ( V_395 ) ) ) {
const struct V_269 * V_396 =
F_45 ( V_395 ) ;
struct V_269 * V_270 = F_45 ( V_4 ) ;
V_270 -> V_266 |= V_396 -> V_266 & V_267 ;
V_270 -> V_271 = V_396 -> V_271 ;
F_5 ( V_4 ) -> V_265 |=
F_5 ( V_395 ) -> V_265 ;
}
}
static void F_218 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_395 = F_207 ( V_2 , V_4 ) ;
int V_397 , V_398 ;
V_397 = V_4 -> V_81 ;
V_398 = V_395 -> V_81 ;
F_97 ( F_6 ( V_4 ) != 1 || F_6 ( V_395 ) != 1 ) ;
F_219 ( V_2 , V_395 , V_4 ) ;
F_191 ( V_395 , V_2 ) ;
F_220 ( V_395 , F_139 ( V_4 , V_398 ) ,
V_398 ) ;
if ( V_395 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_221 ( V_4 -> V_91 , V_395 -> V_91 , V_397 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_395 ) -> V_12 ;
F_5 ( V_4 ) -> V_64 |= F_5 ( V_395 ) -> V_64 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_395 ) -> V_92 & V_399 ;
F_5 ( V_4 ) -> V_274 = F_5 ( V_395 ) -> V_274 ;
F_222 ( V_8 ) ;
if ( V_395 == V_8 -> V_400 )
V_8 -> V_400 = V_4 ;
F_126 ( V_2 , V_395 , F_6 ( V_395 ) ) ;
F_217 ( V_4 , V_395 ) ;
F_192 ( V_2 , V_395 ) ;
}
static bool F_223 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_45 ( V_4 ) -> V_283 != 0 )
return false ;
if ( F_99 ( V_4 ) )
return false ;
if ( V_4 == F_177 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_258 )
return false ;
return true ;
}
static void F_224 ( struct V_1 * V_2 , struct V_3 * V_401 ,
int V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_401 , * V_402 ;
bool V_403 = true ;
if ( ! V_404 )
return;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
return;
F_188 (skb, tmp, sk) {
if ( ! F_223 ( V_2 , V_4 ) )
break;
if ( ! F_225 ( V_401 ) )
break;
V_49 -= V_4 -> V_81 ;
if ( V_403 ) {
V_403 = false ;
continue;
}
if ( V_49 < 0 )
break;
if ( V_4 -> V_81 > F_226 ( V_401 ) )
break;
if ( F_111 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_218 ( V_2 , V_401 ) ;
}
}
int F_208 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_323 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_335 ;
int V_284 , V_81 , V_216 ;
if ( V_6 -> V_298 . V_304 )
V_6 -> V_298 . V_304 = 0 ;
if ( F_195 ( & V_2 -> V_204 ) >
F_20 ( V_2 -> V_251 + ( V_2 -> V_251 >> 2 ) , V_2 -> V_405 ) )
return - V_406 ;
if ( F_203 ( V_2 , V_4 ) )
return - V_407 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_95 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_95 ) )
F_227 () ;
if ( F_150 ( V_2 , V_4 , V_8 -> V_95 - F_5 ( V_4 ) -> V_82 ) )
return - V_281 ;
}
if ( F_2 ( V_2 ) -> V_198 -> V_408 ( V_2 ) )
return - V_409 ;
V_335 = F_61 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_95 )
return - V_406 ;
V_81 = V_335 * V_323 ;
if ( V_4 -> V_81 > V_81 ) {
if ( F_133 ( V_2 , V_4 , V_81 , V_335 , V_180 ) )
return - V_281 ;
} else {
if ( F_136 ( V_4 , V_180 ) )
return - V_281 ;
V_284 = F_6 ( V_4 ) ;
F_121 ( V_4 , V_335 ) ;
V_284 -= F_6 ( V_4 ) ;
if ( V_284 )
F_126 ( V_2 , V_4 , V_284 ) ;
if ( V_4 -> V_81 < V_335 )
F_224 ( V_2 , V_4 , V_335 ) ;
}
if ( ( F_5 ( V_4 ) -> V_64 & V_410 ) == V_410 )
F_41 ( V_2 , V_4 ) ;
if ( F_51 ( ( V_411 && ( ( unsigned long ) V_4 -> V_181 & 3 ) ) ||
F_228 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_352 ;
F_98 ( & V_4 -> V_217 ) ;
V_352 = F_229 ( V_4 , V_326 , V_180 ) ;
V_216 = V_352 ? F_96 ( V_2 , V_352 , 0 , V_180 ) :
- V_218 ;
} else {
V_216 = F_96 ( V_2 , V_4 , 1 , V_180 ) ;
}
if ( F_53 ( ! V_216 ) ) {
V_323 = F_6 ( V_4 ) ;
F_5 ( V_4 ) -> V_92 |= V_399 ;
F_113 ( F_9 ( V_2 ) , V_412 , V_323 ) ;
if ( F_5 ( V_4 ) -> V_64 & V_93 )
F_230 ( F_9 ( V_2 ) , V_413 ) ;
V_8 -> V_414 += V_323 ;
}
return V_216 ;
}
int F_231 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_323 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_216 = F_208 ( V_2 , V_4 , V_323 ) ;
if ( V_216 == 0 ) {
#if V_415 > 0
if ( F_5 ( V_4 ) -> V_92 & V_259 ) {
F_232 ( L_1 ) ;
}
#endif
F_5 ( V_4 ) -> V_92 |= V_416 ;
V_8 -> V_260 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_417 )
V_8 -> V_417 = F_56 ( V_4 ) ;
} else if ( V_216 != - V_407 ) {
F_34 ( F_9 ( V_2 ) , V_418 ) ;
}
if ( V_8 -> V_419 < 0 )
V_8 -> V_419 = 0 ;
V_8 -> V_419 += F_6 ( V_4 ) ;
return V_216 ;
}
static bool F_233 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_309 != V_344 )
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
struct V_3 * V_420 = NULL ;
T_4 V_329 , V_421 ;
int V_422 ;
int V_423 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_262 )
V_8 -> V_424 = V_8 -> V_95 ;
if ( V_8 -> V_400 ) {
V_4 = V_8 -> V_400 ;
V_421 = F_5 ( V_4 ) -> V_12 ;
if ( F_111 ( V_421 , V_8 -> V_424 ) )
V_421 = V_8 -> V_424 ;
} else {
V_4 = F_183 ( V_2 ) ;
V_421 = V_8 -> V_95 ;
}
V_329 = F_168 ( V_2 , F_61 ( V_2 ) ) ;
F_235 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
int V_323 ;
if ( V_4 == F_177 ( V_2 ) )
break;
if ( ! V_420 )
V_8 -> V_400 = V_4 ;
V_323 = V_8 -> V_25 - F_23 ( V_8 ) ;
if ( V_323 <= 0 )
return;
V_323 = F_30 ( int , V_323 , V_329 ) ;
if ( V_423 ) {
V_425:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_125 ( V_8 ) ) )
break;
V_422 = V_426 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_424 ) ) {
V_8 -> V_424 = V_421 ;
if ( ! F_233 ( V_2 ) )
break;
if ( V_420 ) {
V_4 = V_420 ;
V_420 = NULL ;
}
V_423 = 1 ;
goto V_425;
} else if ( ! ( V_92 & V_261 ) ) {
if ( ! V_420 && ! ( V_92 & ( V_259 | V_258 ) ) )
V_420 = V_4 ;
continue;
} else {
V_421 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_309 != V_427 )
V_422 = V_428 ;
else
V_422 = V_429 ;
}
if ( V_92 & ( V_258 | V_259 ) )
continue;
if ( F_231 ( V_2 , V_4 , V_323 ) )
return;
F_34 ( F_9 ( V_2 ) , V_422 ) ;
if ( F_197 ( V_2 ) )
V_8 -> V_368 += F_6 ( V_4 ) ;
if ( V_4 == F_183 ( V_2 ) )
F_202 ( V_2 , V_374 ,
F_2 ( V_2 ) -> V_28 ,
V_379 ) ;
}
}
void F_236 ( struct V_1 * V_2 , int V_169 )
{
int V_430 ;
if ( V_169 <= V_2 -> V_431 )
return;
V_430 = F_237 ( V_169 ) ;
V_2 -> V_431 += V_430 * V_432 ;
F_238 ( V_2 , V_430 ) ;
if ( V_433 && V_2 -> V_434 )
F_239 ( V_2 -> V_434 , V_430 ) ;
}
void F_240 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_435 = F_170 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_435 && ( F_177 ( V_2 ) || F_215 ( V_2 ) ) ) {
V_436:
F_5 ( V_435 ) -> V_64 |= V_94 ;
F_5 ( V_435 ) -> V_12 ++ ;
V_8 -> V_250 ++ ;
if ( ! F_177 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_241 ( V_326 , V_2 -> V_388 ) ;
if ( F_51 ( ! V_4 ) ) {
if ( V_435 )
goto V_436;
return;
}
F_242 ( V_4 , V_326 ) ;
F_236 ( V_2 , V_4 -> V_203 ) ;
F_47 ( V_4 , V_8 -> V_250 ,
V_236 | V_94 ) ;
F_117 ( V_2 , V_4 ) ;
}
F_209 ( V_2 , F_61 ( V_2 ) , V_382 ) ;
}
void F_243 ( struct V_1 * V_2 , T_10 V_437 )
{
struct V_3 * V_4 ;
V_4 = F_244 ( V_326 , V_437 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_438 ) ;
return;
}
F_242 ( V_4 , V_326 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_236 | V_439 ) ;
F_98 ( & V_4 -> V_217 ) ;
if ( F_96 ( V_2 , V_4 , 0 , V_437 ) )
F_34 ( F_9 ( V_2 ) , V_438 ) ;
F_245 ( F_9 ( V_2 ) , V_440 ) ;
}
int F_246 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_183 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_64 & V_93 ) ) {
F_247 ( L_2 , V_441 ) ;
return - V_442 ;
}
if ( ! ( F_5 ( V_4 ) -> V_64 & V_236 ) ) {
if ( F_99 ( V_4 ) ) {
struct V_3 * V_352 = F_248 ( V_4 , V_180 ) ;
if ( ! V_352 )
return - V_281 ;
F_191 ( V_4 , V_2 ) ;
F_118 ( V_352 ) ;
F_249 ( V_2 , V_352 ) ;
F_192 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_352 -> V_203 ;
F_120 ( V_2 , V_352 -> V_203 ) ;
V_4 = V_352 ;
}
F_5 ( V_4 ) -> V_64 |= V_236 ;
F_36 ( V_2 , V_4 ) ;
}
return F_96 ( V_2 , V_4 , 1 , V_180 ) ;
}
struct V_3 * F_250 ( const struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_132 * V_133 ,
enum V_443 V_444 )
{
struct V_165 * V_166 = F_43 ( V_75 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_142 * V_143 = NULL ;
struct V_98 V_99 ;
struct V_3 * V_4 ;
int V_215 ;
struct V_76 * V_77 ;
T_6 V_445 ;
int V_19 ;
V_4 = F_244 ( V_326 , V_180 ) ;
if ( F_51 ( ! V_4 ) ) {
F_251 ( V_18 ) ;
return NULL ;
}
F_242 ( V_4 , V_326 ) ;
switch ( V_444 ) {
case V_446 :
F_252 ( V_4 , F_253 ( V_75 ) ) ;
break;
case V_447 :
break;
case V_448 :
F_252 ( V_4 , (struct V_1 * ) V_2 ) ;
break;
}
F_254 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
V_445 = F_255 ( V_8 -> V_58 . V_445 ) ;
if ( V_445 && V_445 < V_19 )
V_19 = V_445 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
#ifdef F_256
if ( F_51 ( V_75 -> V_449 ) )
V_4 -> V_217 . V_450 = F_257 ( V_75 ) ;
else
#endif
F_98 ( & V_4 -> V_217 ) ;
#ifdef F_55
F_258 () ;
V_143 = F_259 ( V_75 ) -> V_149 -> V_451 ( V_2 , F_253 ( V_75 ) ) ;
#endif
F_260 ( V_4 , F_259 ( V_75 ) -> V_452 , V_453 ) ;
V_215 = F_57 ( V_75 , V_19 , V_4 , & V_99 , V_143 , V_133 ) +
sizeof( * V_77 ) ;
F_104 ( V_4 , V_215 ) ;
F_105 ( V_4 ) ;
V_77 = (struct V_76 * ) V_4 -> V_181 ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_454 = 1 ;
V_77 -> V_455 = 1 ;
F_42 ( V_75 , V_77 ) ;
V_77 -> V_222 = F_110 ( V_166 -> V_456 ) ;
V_77 -> V_224 = V_166 -> V_457 ;
F_47 ( V_4 , F_259 ( V_75 ) -> V_458 ,
V_93 | V_236 ) ;
V_77 -> V_82 = F_52 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_226 = F_52 ( F_259 ( V_75 ) -> V_60 ) ;
V_77 -> V_232 = F_110 ( F_20 ( V_75 -> V_459 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_77 + 1 ) , NULL , & V_99 ) ;
V_77 -> V_460 = ( V_215 >> 2 ) ;
F_261 ( F_9 ( V_2 ) , V_238 ) ;
#ifdef F_55
if ( V_143 )
F_259 ( V_75 ) -> V_149 -> V_234 ( V_99 . V_105 ,
V_143 , F_253 ( V_75 ) , V_4 ) ;
F_262 () ;
#endif
V_4 -> V_242 . V_243 = 0 ;
return V_4 ;
}
static void F_263 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_461 * V_462 ;
T_4 V_463 = F_264 ( V_18 , V_464 ) ;
if ( V_463 == V_465 )
return;
F_258 () ;
V_462 = F_265 ( V_463 ) ;
if ( F_53 ( V_462 && F_266 ( V_462 -> V_466 ) ) ) {
F_267 ( V_6 -> V_467 -> V_466 ) ;
V_6 -> V_468 = F_268 ( V_18 ) ;
V_6 -> V_467 = V_462 ;
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
if ( V_8 -> V_58 . V_445 )
V_8 -> V_58 . V_294 = V_8 -> V_58 . V_445 ;
V_8 -> V_469 = 0 ;
F_157 ( V_2 ) ;
F_158 ( V_2 , F_160 ( V_18 ) ) ;
F_263 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_45 )
V_8 -> V_45 = F_264 ( V_18 , V_470 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_58 . V_445 && V_8 -> V_58 . V_445 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_58 . V_445 ;
F_270 ( V_2 ) ;
if ( V_2 -> V_471 & V_472 &&
( V_8 -> V_45 > F_214 ( V_2 ) || V_8 -> V_45 == 0 ) )
V_8 -> V_45 = F_214 ( V_2 ) ;
F_28 ( F_214 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_58 . V_473 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_44 ,
& V_8 -> V_45 ,
V_157 ,
& V_47 ,
F_264 ( V_18 , V_474 ) ) ;
V_8 -> V_58 . V_47 = V_47 ;
V_8 -> V_394 = V_8 -> V_44 ;
V_2 -> V_475 = 0 ;
F_271 ( V_2 , V_476 ) ;
V_8 -> V_347 = 0 ;
F_272 ( V_8 , 0 ) ;
V_8 -> V_95 = V_8 -> V_250 ;
V_8 -> V_319 = V_8 -> V_250 ;
V_8 -> V_96 = V_8 -> V_250 ;
V_8 -> V_11 = V_8 -> V_250 ;
if ( F_53 ( ! V_8 -> V_364 ) )
V_8 -> V_60 = 0 ;
else
V_8 -> V_477 = V_30 ;
V_8 -> V_59 = V_8 -> V_60 ;
V_8 -> V_478 = V_8 -> V_60 ;
F_2 ( V_2 ) -> V_28 = V_376 ;
F_2 ( V_2 ) -> V_479 = 0 ;
F_273 ( V_8 ) ;
}
static void F_274 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_212 * V_213 = F_5 ( V_4 ) ;
V_213 -> V_12 += V_4 -> V_81 ;
F_118 ( V_4 ) ;
F_275 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_4 -> V_203 ;
F_120 ( V_2 , V_4 -> V_203 ) ;
V_8 -> V_250 = V_213 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_276 ( struct V_1 * V_2 , struct V_3 * V_454 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_146 * V_480 = V_8 -> V_148 ;
int V_481 = 0 , V_49 , V_216 = 0 ;
unsigned long V_482 = 0 ;
struct V_3 * V_483 ;
V_8 -> V_58 . V_294 = V_8 -> V_20 ;
F_277 ( V_2 , & V_8 -> V_58 . V_294 , & V_480 -> V_161 ,
& V_481 , & V_482 ) ;
if ( V_481 > 1 &&
F_278 ( V_484 , V_482 + ( 60 * V_351 << V_481 ) ) ) {
V_480 -> V_161 . V_81 = - 1 ;
goto V_485;
}
if ( V_486 & V_487 )
V_480 -> V_161 . V_81 = - 1 ;
else if ( V_480 -> V_161 . V_81 <= 0 )
goto V_485;
if ( V_8 -> V_58 . V_445 && V_8 -> V_58 . V_445 < V_8 -> V_58 . V_294 )
V_8 -> V_58 . V_294 = V_8 -> V_58 . V_445 ;
V_49 = F_153 ( V_2 , F_2 ( V_2 ) -> V_306 ) -
V_145 ;
V_49 = F_30 ( V_488 , V_49 , V_480 -> V_169 ) ;
V_49 = F_30 ( V_488 , V_49 , F_279 ( V_326 ) ) ;
V_483 = F_137 ( V_2 , V_49 , V_2 -> V_388 , false ) ;
if ( ! V_483 )
goto V_485;
V_483 -> V_89 = V_90 ;
memcpy ( V_483 -> V_244 , V_454 -> V_244 , sizeof( V_454 -> V_244 ) ) ;
if ( V_49 ) {
int V_489 = F_280 ( F_139 ( V_483 , V_49 ) , V_49 ,
& V_480 -> V_181 -> V_490 ) ;
if ( F_51 ( ! V_489 ) ) {
F_281 ( V_483 ) ;
goto V_485;
}
if ( V_489 != V_49 ) {
F_140 ( V_483 , V_489 ) ;
V_49 = V_489 ;
}
}
if ( V_49 == V_480 -> V_169 )
V_480 -> V_181 = NULL ;
V_480 -> V_489 = V_49 ;
F_274 ( V_2 , V_483 ) ;
V_216 = F_96 ( V_2 , V_483 , 1 , V_2 -> V_388 ) ;
V_454 -> V_217 = V_483 -> V_217 ;
F_5 ( V_483 ) -> V_82 ++ ;
F_5 ( V_483 ) -> V_64 = V_236 | V_282 ;
if ( ! V_216 ) {
V_8 -> V_483 = ( V_480 -> V_489 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_491;
}
V_485:
if ( V_480 -> V_161 . V_81 > 0 )
V_480 -> V_161 . V_81 = 0 ;
V_216 = F_96 ( V_2 , V_454 , 1 , V_2 -> V_388 ) ;
if ( V_216 )
V_8 -> V_163 = 0 ;
V_491:
V_480 -> V_161 . V_81 = - 1 ;
return V_216 ;
}
int F_282 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_276 ;
int V_216 ;
F_269 ( V_2 ) ;
if ( F_51 ( V_8 -> V_364 ) ) {
F_283 ( V_2 , NULL ) ;
return 0 ;
}
V_276 = F_137 ( V_2 , 0 , V_2 -> V_388 , true ) ;
if ( F_51 ( ! V_276 ) )
return - V_218 ;
F_47 ( V_276 , V_8 -> V_250 ++ , V_93 ) ;
V_8 -> V_417 = V_30 ;
F_274 ( V_2 , V_276 ) ;
F_39 ( V_2 , V_276 ) ;
V_216 = V_8 -> V_148 ? F_276 ( V_2 , V_276 ) :
F_96 ( V_2 , V_276 , 1 , V_2 -> V_388 ) ;
if ( V_216 == - V_492 )
return V_216 ;
V_8 -> V_11 = V_8 -> V_250 ;
V_8 -> V_493 = V_8 -> V_250 ;
F_245 ( F_9 ( V_2 ) , V_494 ) ;
F_202 ( V_2 , V_374 ,
F_2 ( V_2 ) -> V_28 , V_379 ) ;
return 0 ;
}
void F_284 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_369 ;
F_18 ( V_2 , V_495 ) ;
if ( V_37 > V_496 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_497 = V_351 / 2 ;
if ( V_6 -> V_35 . V_38 ||
( V_6 -> V_35 . V_498 & V_499 ) )
V_497 = V_377 ;
if ( V_8 -> V_348 ) {
int V_372 = F_29 ( int , F_199 ( V_8 -> V_348 >> 3 ) ,
V_496 ) ;
if ( V_372 < V_497 )
V_497 = V_372 ;
}
V_37 = F_20 ( V_37 , V_497 ) ;
}
V_369 = V_484 + V_37 ;
if ( V_6 -> V_35 . V_498 & V_500 ) {
if ( V_6 -> V_35 . V_501 ||
F_285 ( V_6 -> V_35 . V_369 , V_484 + ( V_37 >> 2 ) ) ) {
F_286 ( V_2 ) ;
return;
}
if ( ! F_278 ( V_369 , V_6 -> V_35 . V_369 ) )
V_369 = V_6 -> V_35 . V_369 ;
}
V_6 -> V_35 . V_498 |= V_502 | V_500 ;
V_6 -> V_35 . V_369 = V_369 ;
F_287 ( V_2 , & V_6 -> V_503 , V_369 ) ;
}
void F_286 ( struct V_1 * V_2 )
{
struct V_3 * V_276 ;
if ( V_2 -> V_173 == V_387 )
return;
F_18 ( V_2 , V_504 ) ;
V_276 = F_244 ( V_326 ,
F_210 ( V_2 , V_180 | V_505 ) ) ;
if ( F_51 ( ! V_276 ) ) {
F_288 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_506 ;
F_202 ( V_2 , V_40 ,
V_377 , V_379 ) ;
return;
}
F_242 ( V_276 , V_326 ) ;
F_47 ( V_276 , F_10 ( V_2 ) , V_236 ) ;
F_289 ( V_276 ) ;
F_98 ( & V_276 -> V_217 ) ;
F_96 ( V_2 , V_276 , 0 , ( V_507 T_10 ) 0 ) ;
}
static int F_290 ( struct V_1 * V_2 , int V_508 , int V_509 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_244 ( V_326 ,
F_210 ( V_2 , V_180 | V_505 ) ) ;
if ( ! V_4 )
return - 1 ;
F_242 ( V_4 , V_326 ) ;
F_47 ( V_4 , V_8 -> V_95 - ! V_508 , V_236 ) ;
F_98 ( & V_4 -> V_217 ) ;
F_34 ( F_9 ( V_2 ) , V_509 ) ;
return F_96 ( V_2 , V_4 , 0 , ( V_507 T_10 ) 0 ) ;
}
void F_291 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_510 ) {
F_3 ( V_2 ) -> V_511 = F_3 ( V_2 ) -> V_60 - 1 ;
F_290 ( V_2 , 0 , V_512 ) ;
}
}
int F_292 ( struct V_1 * V_2 , int V_509 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_387 )
return - 1 ;
V_4 = F_177 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_216 ;
unsigned int V_19 = F_61 ( V_2 ) ;
unsigned int V_513 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_493 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_493 = F_5 ( V_4 ) -> V_12 ;
if ( V_513 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_513 = F_20 ( V_513 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_282 ;
if ( F_133 ( V_2 , V_4 , V_513 , V_19 , V_180 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_121 ( V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_64 |= V_282 ;
V_216 = F_96 ( V_2 , V_4 , 1 , V_180 ) ;
if ( ! V_216 )
F_1 ( V_2 , V_4 ) ;
return V_216 ;
} else {
if ( F_293 ( V_8 -> V_96 , V_8 -> V_95 + 1 , V_8 -> V_95 + 0xFFFF ) )
F_290 ( V_2 , 1 , V_509 ) ;
return F_290 ( V_2 , 0 , V_509 ) ;
}
}
void F_294 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_297 * V_297 = F_9 ( V_2 ) ;
unsigned long V_514 ;
int V_216 ;
V_216 = F_292 ( V_2 , V_512 ) ;
if ( V_8 -> V_10 || ! F_177 ( V_2 ) ) {
V_6 -> V_515 = 0 ;
V_6 -> V_516 = 0 ;
return;
}
if ( V_216 <= 0 ) {
if ( V_6 -> V_516 < V_297 -> V_70 . V_517 )
V_6 -> V_516 ++ ;
V_6 -> V_515 ++ ;
V_514 = V_379 ;
} else {
if ( ! V_6 -> V_515 )
V_6 -> V_515 = 1 ;
V_514 = V_518 ;
}
F_202 ( V_2 , V_519 ,
F_295 ( V_2 , V_514 ) ,
V_379 ) ;
}
int F_296 ( const struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_520 * V_521 = F_259 ( V_75 ) -> V_149 ;
struct V_522 V_249 ;
int V_523 ;
F_259 ( V_75 ) -> V_452 = F_297 () ;
V_523 = V_521 -> V_524 ( V_2 , NULL , & V_249 , V_75 , NULL , V_446 ) ;
if ( ! V_523 ) {
F_261 ( F_9 ( V_2 ) , V_412 ) ;
F_230 ( F_9 ( V_2 ) , V_413 ) ;
}
return V_523 ;
}
