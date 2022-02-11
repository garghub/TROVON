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
static void F_16 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_3 V_22 = V_23 - V_8 -> V_24 ;
T_4 V_25 = F_17 ( V_8 , V_18 ) ;
T_4 V_26 = V_8 -> V_27 ;
F_18 ( V_2 , V_28 ) ;
V_8 -> V_29 = F_19 ( V_2 ) ;
V_25 = F_20 ( V_25 , V_26 ) ;
while ( ( V_22 -= F_2 ( V_2 ) -> V_30 ) > 0 && V_26 > V_25 )
V_26 >>= 1 ;
V_8 -> V_27 = F_21 ( V_26 , V_25 ) ;
V_8 -> V_31 = V_23 ;
V_8 -> V_32 = 0 ;
}
static void F_22 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_4 V_33 = V_23 ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_34 &&
( ! V_8 -> V_10 && ( T_3 ) ( V_33 - V_8 -> V_24 ) > V_6 -> V_30 ) )
F_16 ( V_2 , F_14 ( V_2 ) ) ;
V_8 -> V_24 = V_33 ;
if ( ( T_4 ) ( V_33 - V_6 -> V_35 . V_36 ) < V_6 -> V_35 . V_37 &&
( ! V_18 || ! F_23 ( V_18 , V_38 ) ) )
V_6 -> V_35 . V_39 = 1 ;
}
static inline void F_24 ( struct V_1 * V_2 , unsigned int V_40 )
{
F_25 ( V_2 , V_40 ) ;
F_26 ( V_2 , V_41 ) ;
}
T_4 F_27 ( T_4 V_19 )
{
T_4 V_42 = V_43 * 2 ;
if ( V_19 > 1460 )
V_42 = F_21 ( ( 1460 * V_42 ) / V_19 , 2U ) ;
return V_42 ;
}
void F_28 ( int V_44 , T_1 V_19 ,
T_1 * V_45 , T_1 * V_46 ,
int V_47 , T_5 * V_48 ,
T_1 V_49 )
{
unsigned int V_50 = ( V_44 < 0 ? 0 : V_44 ) ;
if ( * V_46 == 0 )
( * V_46 ) = ( 65535 << 14 ) ;
V_50 = F_20 ( * V_46 , V_50 ) ;
if ( V_50 > V_19 )
V_50 = ( V_50 / V_19 ) * V_19 ;
if ( V_51 )
( * V_45 ) = F_20 ( V_50 , V_52 ) ;
else
( * V_45 ) = V_50 ;
( * V_48 ) = 0 ;
if ( V_47 ) {
V_50 = F_29 ( T_4 , V_53 [ 2 ] , V_54 ) ;
V_50 = F_30 ( T_4 , V_50 , * V_46 ) ;
while ( V_50 > 65535 && ( * V_48 ) < 14 ) {
V_50 >>= 1 ;
( * V_48 ) ++ ;
}
}
if ( V_19 > ( 1 << * V_48 ) ) {
if ( ! V_49 )
V_49 = F_27 ( V_19 ) ;
* V_45 = F_20 ( * V_45 , V_49 * V_19 ) ;
}
( * V_46 ) = F_20 ( 65535U << ( * V_48 ) , * V_46 ) ;
}
static T_6 F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_55 = V_8 -> V_45 ;
T_4 V_56 = F_32 ( V_8 ) ;
T_4 V_57 = F_33 ( V_2 ) ;
if ( V_57 < V_56 ) {
if ( V_57 == 0 )
F_34 ( F_9 ( V_2 ) ,
V_58 ) ;
V_57 = F_35 ( V_56 , 1 << V_8 -> V_59 . V_48 ) ;
}
V_8 -> V_45 = V_57 ;
V_8 -> V_60 = V_8 -> V_61 ;
if ( ! V_8 -> V_59 . V_48 && V_51 )
V_57 = F_20 ( V_57 , V_52 ) ;
else
V_57 = F_20 ( V_57 , ( 65535U << V_8 -> V_59 . V_48 ) ) ;
V_57 >>= V_8 -> V_59 . V_48 ;
if ( V_57 == 0 ) {
V_8 -> V_62 = 0 ;
if ( V_55 )
F_34 ( F_9 ( V_2 ) ,
V_63 ) ;
} else if ( V_55 == 0 ) {
F_34 ( F_9 ( V_2 ) , V_64 ) ;
}
return V_57 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
F_5 ( V_4 ) -> V_65 &= ~ V_66 ;
if ( ! ( V_8 -> V_67 & V_68 ) )
F_5 ( V_4 ) -> V_65 &= ~ V_69 ;
else if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
bool V_70 = F_9 ( V_2 ) -> V_71 . V_72 == 1 ||
F_37 ( V_2 ) ;
if ( ! V_70 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_40 ( V_18 , V_73 ) )
V_70 = true ;
}
V_8 -> V_67 = 0 ;
if ( V_70 ) {
F_5 ( V_4 ) -> V_65 |= V_69 | V_66 ;
V_8 -> V_67 = V_68 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
}
static void
F_41 ( const struct V_74 * V_75 , struct V_76 * V_77 ,
struct V_1 * V_2 )
{
if ( F_42 ( V_75 ) -> V_78 ) {
V_77 -> V_79 = 1 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_80 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_67 & V_68 ) {
if ( V_4 -> V_81 != V_80 &&
! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_11 ) ) {
F_38 ( V_2 ) ;
if ( V_8 -> V_67 & V_83 ) {
V_8 -> V_67 &= ~ V_83 ;
F_44 ( V_4 ) -> V_84 = 1 ;
F_45 ( V_4 ) -> V_85 |= V_86 ;
}
} else if ( ! F_37 ( V_2 ) ) {
F_46 ( V_2 ) ;
}
if ( V_8 -> V_67 & V_87 )
F_44 ( V_4 ) -> V_79 = 1 ;
}
}
static void F_47 ( struct V_3 * V_4 , T_4 V_82 , T_7 V_88 )
{
struct V_89 * V_90 = F_45 ( V_4 ) ;
V_4 -> V_91 = V_92 ;
V_4 -> V_93 = 0 ;
F_5 ( V_4 ) -> V_65 = V_88 ;
F_5 ( V_4 ) -> V_94 = 0 ;
F_48 ( V_4 , 1 ) ;
V_90 -> V_95 = 0 ;
V_90 -> V_85 = 0 ;
F_5 ( V_4 ) -> V_82 = V_82 ;
if ( V_88 & ( V_96 | V_97 ) )
V_82 ++ ;
F_5 ( V_4 ) -> V_12 = V_82 ;
}
static inline bool F_49 ( const struct V_7 * V_8 )
{
return V_8 -> V_98 != V_8 -> V_99 ;
}
static void F_50 ( T_8 * V_100 , struct V_7 * V_8 ,
struct V_101 * V_102 )
{
T_6 V_103 = V_102 -> V_103 ;
if ( F_51 ( V_104 & V_103 ) ) {
* V_100 ++ = F_52 ( ( V_105 << 24 ) | ( V_105 << 16 ) |
( V_106 << 8 ) | V_107 ) ;
V_102 -> V_108 = ( T_5 * ) V_100 ;
V_100 += 4 ;
}
if ( F_51 ( V_102 -> V_19 ) ) {
* V_100 ++ = F_52 ( ( V_109 << 24 ) |
( V_110 << 16 ) |
V_102 -> V_19 ) ;
}
if ( F_53 ( V_111 & V_103 ) ) {
if ( F_51 ( V_112 & V_103 ) ) {
* V_100 ++ = F_52 ( ( V_113 << 24 ) |
( V_114 << 16 ) |
( V_115 << 8 ) |
V_116 ) ;
V_103 &= ~ V_112 ;
} else {
* V_100 ++ = F_52 ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_115 << 8 ) |
V_116 ) ;
}
* V_100 ++ = F_52 ( V_102 -> V_117 ) ;
* V_100 ++ = F_52 ( V_102 -> V_118 ) ;
}
if ( F_51 ( V_112 & V_103 ) ) {
* V_100 ++ = F_52 ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_113 << 8 ) |
V_114 ) ;
}
if ( F_51 ( V_119 & V_103 ) ) {
* V_100 ++ = F_52 ( ( V_105 << 24 ) |
( V_120 << 16 ) |
( V_121 << 8 ) |
V_102 -> V_122 ) ;
}
if ( F_51 ( V_102 -> V_123 ) ) {
struct V_124 * V_125 = V_8 -> V_59 . V_126 ?
V_8 -> V_127 : V_8 -> V_128 ;
int V_129 ;
* V_100 ++ = F_52 ( ( V_105 << 24 ) |
( V_105 << 16 ) |
( V_130 << 8 ) |
( V_131 + ( V_102 -> V_123 *
V_132 ) ) ) ;
for ( V_129 = 0 ; V_129 < V_102 -> V_123 ;
++ V_129 ) {
* V_100 ++ = F_52 ( V_125 [ V_129 ] . V_133 ) ;
* V_100 ++ = F_52 ( V_125 [ V_129 ] . V_12 ) ;
}
V_8 -> V_59 . V_126 = 0 ;
}
if ( F_51 ( V_134 & V_103 ) ) {
struct V_135 * V_136 = V_102 -> V_137 ;
* V_100 ++ = F_52 ( ( V_138 << 24 ) |
( ( V_139 + V_136 -> V_81 ) << 16 ) |
V_140 ) ;
memcpy ( V_100 , V_136 -> V_141 , V_136 -> V_81 ) ;
if ( ( V_136 -> V_81 & 3 ) == 2 ) {
T_7 * V_142 = ( ( T_7 * ) V_100 ) + V_136 -> V_81 ;
V_142 [ 0 ] = V_142 [ 1 ] = V_105 ;
}
V_100 += ( V_136 -> V_81 + 3 ) >> 2 ;
}
}
static unsigned int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_143 * * V_144 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_145 = V_146 ;
struct V_147 * V_148 = V_8 -> V_149 ;
#ifdef F_55
* V_144 = V_8 -> V_150 -> V_151 ( V_2 , V_2 ) ;
if ( * V_144 ) {
V_102 -> V_103 |= V_104 ;
V_145 -= V_152 ;
}
#else
* V_144 = NULL ;
#endif
V_102 -> V_19 = F_13 ( V_2 ) ;
V_145 -= V_153 ;
if ( F_53 ( V_154 && * V_144 == NULL ) ) {
V_102 -> V_103 |= V_111 ;
V_102 -> V_117 = F_56 ( V_4 ) + V_8 -> V_155 ;
V_102 -> V_118 = V_8 -> V_59 . V_156 ;
V_145 -= V_157 ;
}
if ( F_53 ( V_158 ) ) {
V_102 -> V_122 = V_8 -> V_59 . V_48 ;
V_102 -> V_103 |= V_119 ;
V_145 -= V_159 ;
}
if ( F_53 ( V_160 ) ) {
V_102 -> V_103 |= V_112 ;
if ( F_51 ( ! ( V_111 & V_102 -> V_103 ) ) )
V_145 -= V_161 ;
}
if ( V_148 && V_148 -> V_162 . V_81 >= 0 ) {
T_4 V_163 = V_139 + V_148 -> V_162 . V_81 ;
V_163 = ( V_163 + 3 ) & ~ 3U ;
if ( V_145 >= V_163 ) {
V_102 -> V_103 |= V_134 ;
V_102 -> V_137 = & V_148 -> V_162 ;
V_145 -= V_163 ;
V_8 -> V_164 = 1 ;
}
}
return V_146 - V_145 ;
}
static unsigned int F_57 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
unsigned int V_19 , struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_143 * * V_144 ,
struct V_135 * V_136 )
{
struct V_165 * V_166 = F_42 ( V_75 ) ;
unsigned int V_145 = V_146 ;
#ifdef F_55
* V_144 = F_58 ( V_75 ) -> V_150 -> V_151 ( V_2 , V_75 ) ;
if ( * V_144 ) {
V_102 -> V_103 |= V_104 ;
V_145 -= V_152 ;
V_166 -> V_167 &= ! V_166 -> V_168 ;
}
#else
* V_144 = NULL ;
#endif
V_102 -> V_19 = V_19 ;
V_145 -= V_153 ;
if ( F_53 ( V_166 -> V_47 ) ) {
V_102 -> V_122 = V_166 -> V_48 ;
V_102 -> V_103 |= V_119 ;
V_145 -= V_159 ;
}
if ( F_53 ( V_166 -> V_167 ) ) {
V_102 -> V_103 |= V_111 ;
V_102 -> V_117 = F_56 ( V_4 ) ;
V_102 -> V_118 = V_75 -> V_156 ;
V_145 -= V_157 ;
}
if ( F_53 ( V_166 -> V_168 ) ) {
V_102 -> V_103 |= V_112 ;
if ( F_51 ( ! V_166 -> V_167 ) )
V_145 -= V_161 ;
}
if ( V_136 != NULL && V_136 -> V_81 >= 0 ) {
T_4 V_163 = V_139 + V_136 -> V_81 ;
V_163 = ( V_163 + 3 ) & ~ 3U ;
if ( V_145 >= V_163 ) {
V_102 -> V_103 |= V_134 ;
V_102 -> V_137 = V_136 ;
V_145 -= V_163 ;
}
}
return V_146 - V_145 ;
}
static unsigned int F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_143 * * V_144 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_169 = 0 ;
unsigned int V_170 ;
V_102 -> V_103 = 0 ;
#ifdef F_55
* V_144 = V_8 -> V_150 -> V_151 ( V_2 , V_2 ) ;
if ( F_51 ( * V_144 ) ) {
V_102 -> V_103 |= V_104 ;
V_169 += V_152 ;
}
#else
* V_144 = NULL ;
#endif
if ( F_53 ( V_8 -> V_59 . V_167 ) ) {
V_102 -> V_103 |= V_111 ;
V_102 -> V_117 = V_4 ? F_56 ( V_4 ) + V_8 -> V_155 : 0 ;
V_102 -> V_118 = V_8 -> V_59 . V_156 ;
V_169 += V_157 ;
}
V_170 = V_8 -> V_59 . V_171 + V_8 -> V_59 . V_126 ;
if ( F_51 ( V_170 ) ) {
const unsigned int V_145 = V_146 - V_169 ;
V_102 -> V_123 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_169 += V_172 +
V_102 -> V_123 * V_132 ;
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
struct V_101 V_102 ;
unsigned int V_214 , V_215 ;
struct V_143 * V_144 ;
struct V_76 * V_77 ;
int V_216 ;
F_98 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_208 ) {
F_99 ( & V_4 -> V_217 ) ;
if ( F_51 ( F_100 ( V_4 ) ) )
V_4 = F_101 ( V_4 , V_209 ) ;
else
V_4 = F_102 ( V_4 , V_209 ) ;
if ( F_51 ( ! V_4 ) )
return - V_218 ;
}
V_211 = F_103 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_213 = F_5 ( V_4 ) ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
if ( F_51 ( V_213 -> V_65 & V_96 ) )
V_214 = F_54 ( V_2 , V_4 , & V_102 , & V_144 ) ;
else
V_214 = F_59 ( V_2 , V_4 , & V_102 ,
& V_144 ) ;
V_215 = V_214 + sizeof( struct V_76 ) ;
if ( F_104 ( V_8 ) == 0 )
F_18 ( V_2 , V_219 ) ;
V_4 -> V_220 = F_105 ( V_2 ) < F_90 ( 1 ) ;
F_106 ( V_4 , V_215 ) ;
F_107 ( V_4 ) ;
F_108 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_221 = F_88 ;
F_109 ( V_4 , V_2 ) ;
F_110 ( V_4 -> V_203 , & V_2 -> V_204 ) ;
V_77 = F_44 ( V_4 ) ;
V_77 -> V_222 = V_211 -> V_223 ;
V_77 -> V_224 = V_211 -> V_225 ;
V_77 -> V_82 = F_52 ( V_213 -> V_82 ) ;
V_77 -> V_226 = F_52 ( V_8 -> V_61 ) ;
* ( ( ( V_227 * ) V_77 ) + 6 ) = F_111 ( ( ( V_215 >> 2 ) << 12 ) |
V_213 -> V_65 ) ;
if ( F_51 ( V_213 -> V_65 & V_96 ) ) {
V_77 -> V_228 = F_111 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_77 -> V_228 = F_111 ( F_31 ( V_2 ) ) ;
}
V_77 -> V_229 = 0 ;
V_77 -> V_230 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_213 -> V_82 , V_8 -> V_99 ) ) ) {
if ( F_11 ( V_8 -> V_99 , V_213 -> V_82 + 0x10000 ) ) {
V_77 -> V_230 = F_111 ( V_8 -> V_99 - V_213 -> V_82 ) ;
V_77 -> V_231 = 1 ;
} else if ( F_112 ( V_213 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_230 = F_111 ( 0xFFFF ) ;
V_77 -> V_231 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_102 ) ;
if ( F_53 ( ( V_213 -> V_65 & V_96 ) == 0 ) )
F_43 ( V_2 , V_4 , V_215 ) ;
#ifdef F_55
if ( V_144 ) {
F_113 ( V_2 , V_232 ) ;
V_8 -> V_150 -> V_233 ( V_102 . V_108 ,
V_144 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_198 -> V_234 ( V_2 , V_4 ) ;
if ( F_53 ( V_213 -> V_65 & V_235 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_215 )
F_22 ( V_8 , V_2 ) ;
if ( F_112 ( V_213 -> V_12 , V_8 -> V_11 ) || V_213 -> V_82 == V_213 -> V_12 )
F_114 ( F_9 ( V_2 ) , V_236 ,
F_6 ( V_4 ) ) ;
F_45 ( V_4 ) -> V_237 = F_6 ( V_4 ) ;
V_4 -> V_238 . V_239 = 0 ;
memset ( V_4 -> V_240 , 0 , F_21 ( sizeof( struct V_241 ) ,
sizeof( struct V_242 ) ) ) ;
V_216 = V_6 -> V_198 -> V_243 ( V_2 , V_4 , & V_211 -> V_244 . V_245 ) ;
if ( F_53 ( V_216 <= 0 ) )
return V_216 ;
F_115 ( V_2 ) ;
return F_116 ( V_216 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_246 = F_5 ( V_4 ) -> V_12 ;
F_118 ( V_4 ) ;
F_119 ( V_2 , V_4 ) ;
V_2 -> V_247 += V_4 -> V_203 ;
F_120 ( V_2 , V_4 -> V_203 ) ;
}
static void F_121 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_248 )
{
struct V_89 * V_90 = F_45 ( V_4 ) ;
F_122 ( F_100 ( V_4 ) ) ;
if ( V_4 -> V_81 <= V_248 || V_4 -> V_91 == V_249 ) {
F_48 ( V_4 , 1 ) ;
V_90 -> V_95 = 0 ;
V_90 -> V_85 = 0 ;
} else {
F_48 ( V_4 , F_123 ( V_4 -> V_81 , V_248 ) ) ;
V_90 -> V_95 = V_248 ;
V_90 -> V_85 = V_2 -> V_250 ;
}
}
static void F_124 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_251 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_252 || F_125 ( V_8 ) )
return;
if ( F_112 ( F_126 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_253 -= V_251 ;
}
static void F_127 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_251 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_251 ;
if ( F_5 ( V_4 ) -> V_94 & V_254 )
V_8 -> V_252 -= V_251 ;
if ( F_5 ( V_4 ) -> V_94 & V_255 )
V_8 -> V_256 -= V_251 ;
if ( F_5 ( V_4 ) -> V_94 & V_257 )
V_8 -> V_258 -= V_251 ;
if ( F_125 ( V_8 ) && V_251 > 0 )
V_8 -> V_252 -= F_30 ( T_4 , V_8 -> V_252 , V_251 ) ;
F_124 ( V_2 , V_4 , V_251 ) ;
if ( V_8 -> V_259 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_259 ) -> V_82 ) &&
( F_128 ( V_8 ) || ( F_5 ( V_4 ) -> V_94 & V_254 ) ) )
V_8 -> V_260 -= V_251 ;
F_129 ( V_8 ) ;
}
static void F_130 ( struct V_3 * V_4 , struct V_3 * V_261 )
{
struct V_89 * V_90 = F_45 ( V_4 ) ;
if ( F_51 ( V_90 -> V_262 & V_263 ) &&
! F_11 ( V_90 -> V_264 , F_5 ( V_261 ) -> V_82 ) ) {
struct V_89 * V_265 = F_45 ( V_261 ) ;
T_7 V_266 = V_90 -> V_262 & V_263 ;
V_90 -> V_262 &= ~ V_266 ;
V_265 -> V_262 |= V_266 ;
F_131 ( V_90 -> V_264 , V_265 -> V_264 ) ;
}
}
int F_132 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_248 , T_10 V_267 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_268 ;
int V_269 , V_270 ;
int V_271 ;
T_7 V_88 ;
if ( F_133 ( V_81 > V_4 -> V_81 ) )
return - V_272 ;
V_269 = F_134 ( V_4 ) - V_81 ;
if ( V_269 < 0 )
V_269 = 0 ;
if ( F_135 ( V_4 , V_267 ) )
return - V_273 ;
V_268 = F_136 ( V_2 , V_269 , V_267 ) ;
if ( V_268 == NULL )
return - V_273 ;
V_2 -> V_247 += V_268 -> V_203 ;
F_120 ( V_2 , V_268 -> V_203 ) ;
V_271 = V_4 -> V_81 - V_81 - V_269 ;
V_268 -> V_203 += V_271 ;
V_4 -> V_203 -= V_271 ;
F_5 ( V_268 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_268 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_268 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_88 & ~ ( V_97 | V_274 ) ;
F_5 ( V_268 ) -> V_65 = V_88 ;
F_5 ( V_268 ) -> V_94 = F_5 ( V_4 ) -> V_94 ;
if ( ! F_45 ( V_4 ) -> V_275 && V_4 -> V_91 != V_92 ) {
V_268 -> V_93 = F_137 ( V_4 -> V_181 + V_81 ,
F_138 ( V_268 , V_269 ) ,
V_269 , 0 ) ;
F_139 ( V_4 , V_81 ) ;
V_4 -> V_93 = F_140 ( V_4 -> V_93 , V_268 -> V_93 , V_81 ) ;
} else {
V_4 -> V_91 = V_92 ;
F_141 ( V_4 , V_268 , V_81 ) ;
}
V_268 -> V_91 = V_4 -> V_91 ;
V_268 -> V_238 = V_4 -> V_238 ;
F_130 ( V_4 , V_268 ) ;
V_270 = F_6 ( V_4 ) ;
F_121 ( V_2 , V_4 , V_248 ) ;
F_121 ( V_2 , V_268 , V_248 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_268 ) -> V_12 ) ) {
int V_276 = V_270 - F_6 ( V_4 ) -
F_6 ( V_268 ) ;
if ( V_276 )
F_127 ( V_2 , V_4 , V_276 ) ;
}
F_118 ( V_268 ) ;
F_142 ( V_4 , V_268 , V_2 ) ;
return 0 ;
}
static void F_143 ( struct V_3 * V_4 , int V_81 )
{
struct V_89 * V_90 ;
int V_200 , V_277 , V_278 ;
V_278 = F_30 ( int , V_81 , F_134 ( V_4 ) ) ;
if ( V_278 ) {
F_144 ( V_4 , V_278 ) ;
V_81 -= V_278 ;
if ( ! V_81 )
return;
}
V_278 = V_81 ;
V_277 = 0 ;
V_90 = F_45 ( V_4 ) ;
for ( V_200 = 0 ; V_200 < V_90 -> V_275 ; V_200 ++ ) {
int V_169 = F_145 ( & V_90 -> V_279 [ V_200 ] ) ;
if ( V_169 <= V_278 ) {
F_146 ( V_4 , V_200 ) ;
V_278 -= V_169 ;
} else {
V_90 -> V_279 [ V_277 ] = V_90 -> V_279 [ V_200 ] ;
if ( V_278 ) {
V_90 -> V_279 [ V_277 ] . V_280 += V_278 ;
F_147 ( & V_90 -> V_279 [ V_277 ] , V_278 ) ;
V_278 = 0 ;
}
V_277 ++ ;
}
}
V_90 -> V_275 = V_277 ;
F_148 ( V_4 ) ;
V_4 -> V_281 -= V_81 ;
V_4 -> V_81 = V_4 -> V_281 ;
}
int F_149 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_135 ( V_4 , V_180 ) )
return - V_273 ;
F_143 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_91 = V_92 ;
V_4 -> V_203 -= V_81 ;
V_2 -> V_247 -= V_81 ;
F_150 ( V_2 , V_81 ) ;
F_151 ( V_2 , V_282 ) ;
if ( F_6 ( V_4 ) > 1 )
F_121 ( V_2 , V_4 , F_152 ( V_4 ) ) ;
return 0 ;
}
static inline int F_153 ( struct V_1 * V_2 , int V_283 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_248 ;
V_248 = V_283 - V_6 -> V_198 -> V_284 - sizeof( struct V_76 ) ;
if ( V_6 -> V_198 -> V_285 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_248 -= V_6 -> V_198 -> V_285 ;
}
if ( V_248 > V_8 -> V_59 . V_286 )
V_248 = V_8 -> V_59 . V_286 ;
V_248 -= V_6 -> V_287 ;
if ( V_248 < 48 )
V_248 = 48 ;
return V_248 ;
}
int F_155 ( struct V_1 * V_2 , int V_283 )
{
return F_153 ( V_2 , V_283 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_156 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_288 ;
V_288 = V_19 +
V_8 -> V_80 +
V_6 -> V_287 +
V_6 -> V_198 -> V_284 ;
if ( V_6 -> V_198 -> V_285 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_288 += V_6 -> V_198 -> V_285 ;
}
return V_288 ;
}
void F_157 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_289 . V_290 = V_291 > 1 ;
V_6 -> V_289 . V_292 = V_8 -> V_59 . V_286 + sizeof( struct V_76 ) +
V_6 -> V_198 -> V_284 ;
V_6 -> V_289 . V_293 = F_156 ( V_2 , V_294 ) ;
V_6 -> V_289 . V_295 = 0 ;
}
unsigned int F_158 ( struct V_1 * V_2 , T_4 V_283 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_248 ;
if ( V_6 -> V_289 . V_292 > V_283 )
V_6 -> V_289 . V_292 = V_283 ;
V_248 = F_155 ( V_2 , V_283 ) ;
V_248 = F_159 ( V_8 , V_248 ) ;
V_6 -> V_296 = V_283 ;
if ( V_6 -> V_289 . V_290 )
V_248 = F_20 ( V_248 , F_155 ( V_2 , V_6 -> V_289 . V_293 ) ) ;
V_8 -> V_297 = V_248 ;
return V_248 ;
}
unsigned int F_62 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_248 ;
unsigned int V_298 ;
struct V_101 V_102 ;
struct V_143 * V_144 ;
V_248 = V_8 -> V_297 ;
if ( V_18 ) {
T_4 V_288 = F_160 ( V_18 ) ;
if ( V_288 != F_2 ( V_2 ) -> V_296 )
V_248 = F_158 ( V_2 , V_288 ) ;
}
V_298 = F_59 ( V_2 , NULL , & V_102 , & V_144 ) +
sizeof( struct V_76 ) ;
if ( V_298 != V_8 -> V_80 ) {
int V_22 = ( int ) V_298 - V_8 -> V_80 ;
V_248 -= V_22 ;
}
return V_248 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_299 == V_300 &&
V_2 -> V_301 && ! F_162 ( V_302 , & V_2 -> V_301 -> V_88 ) ) {
T_4 V_303 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_304 = F_21 ( V_8 -> V_32 , V_303 ) ;
if ( V_304 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_304 ) >> 1 ;
}
V_8 -> V_32 = 0 ;
}
V_8 -> V_31 = V_23 ;
}
static void F_163 ( struct V_1 * V_2 , bool V_305 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_98 , V_8 -> V_306 ) ||
V_8 -> V_10 > V_8 -> V_307 ) {
V_8 -> V_307 = V_8 -> V_10 ;
V_8 -> V_306 = V_8 -> V_11 ;
V_8 -> V_305 = V_305 ;
}
if ( F_164 ( V_2 ) ) {
V_8 -> V_32 = 0 ;
V_8 -> V_31 = V_23 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_32 )
V_8 -> V_32 = V_8 -> V_10 ;
if ( V_34 &&
( T_3 ) ( V_23 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 )
F_161 ( V_2 ) ;
}
}
static bool F_165 ( const struct V_7 * V_8 )
{
return F_112 ( V_8 -> V_308 , V_8 -> V_98 ) &&
! F_112 ( V_8 -> V_308 , V_8 -> V_11 ) ;
}
static void F_166 ( struct V_7 * V_8 , unsigned int V_248 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_248 )
V_8 -> V_308 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_167 ( bool V_309 , const struct V_7 * V_8 ,
int V_179 )
{
return V_309 &&
( ( V_179 & V_310 ) ||
( ! V_179 && V_8 -> V_10 && F_165 ( V_8 ) ) ) ;
}
static T_4 F_168 ( const struct V_1 * V_2 , unsigned int V_248 )
{
T_4 V_311 , V_312 ;
V_311 = F_20 ( V_2 -> V_313 >> 10 ,
V_2 -> V_314 - 1 - V_315 ) ;
V_312 = F_29 ( T_4 , V_311 / V_248 , V_316 ) ;
return F_30 ( T_4 , V_312 , V_2 -> V_317 ) ;
}
static unsigned int F_169 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_248 ,
unsigned int V_318 ,
int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_309 , V_319 , V_228 , V_320 ;
V_228 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_320 = V_248 * V_318 ;
if ( F_53 ( V_320 <= V_228 && V_4 != F_170 ( V_2 ) ) )
return V_320 ;
V_319 = F_20 ( V_4 -> V_81 , V_228 ) ;
if ( V_320 <= V_319 )
return V_320 ;
V_309 = V_319 % V_248 ;
if ( F_167 ( V_309 != 0 , V_8 , V_179 ) )
return V_319 - V_309 ;
return V_319 ;
}
static inline unsigned int F_171 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_321 , V_26 , V_322 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_97 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_321 = F_104 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_321 >= V_26 )
return 0 ;
V_322 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_322 , V_26 - V_321 ) ;
}
static int F_172 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_248 )
{
int V_323 = F_6 ( V_4 ) ;
if ( ! V_323 || ( V_323 > 1 && F_152 ( V_4 ) != V_248 ) ) {
F_121 ( V_2 , V_4 , V_248 ) ;
V_323 = F_6 ( V_4 ) ;
}
return V_323 ;
}
static inline bool F_173 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_324 , int V_179 )
{
if ( V_179 & V_325 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_97 ) )
return true ;
if ( ! F_167 ( V_4 -> V_81 < V_324 , V_8 , V_179 ) )
return true ;
return false ;
}
static bool F_174 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_324 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_324 )
V_12 = F_5 ( V_4 ) -> V_82 + V_324 ;
return ! F_112 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_175 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_324 , int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_326 ;
F_172 ( V_2 , V_4 , V_324 ) ;
if ( ! F_173 ( V_8 , V_4 , V_324 , V_179 ) )
return 0 ;
V_326 = F_171 ( V_8 , V_4 ) ;
if ( V_326 && ! F_174 ( V_8 , V_4 , V_324 ) )
V_326 = 0 ;
return V_326 ;
}
bool F_176 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_177 ( V_2 ) ;
return V_4 &&
F_175 ( V_2 , V_4 , F_62 ( V_2 ) ,
( F_178 ( V_2 , V_4 ) ?
V_8 -> V_179 : V_325 ) ) ;
}
static int F_179 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_248 , T_10 V_267 )
{
struct V_3 * V_268 ;
int V_271 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_281 )
return F_132 ( V_2 , V_4 , V_81 , V_248 , V_267 ) ;
V_268 = F_136 ( V_2 , 0 , V_267 ) ;
if ( F_51 ( V_268 == NULL ) )
return - V_273 ;
V_2 -> V_247 += V_268 -> V_203 ;
F_120 ( V_2 , V_268 -> V_203 ) ;
V_268 -> V_203 += V_271 ;
V_4 -> V_203 -= V_271 ;
F_5 ( V_268 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_268 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_268 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_88 & ~ ( V_97 | V_274 ) ;
F_5 ( V_268 ) -> V_65 = V_88 ;
F_5 ( V_268 ) -> V_94 = 0 ;
V_268 -> V_91 = V_4 -> V_91 = V_92 ;
F_141 ( V_4 , V_268 , V_81 ) ;
F_130 ( V_4 , V_268 ) ;
F_121 ( V_2 , V_4 , V_248 ) ;
F_121 ( V_2 , V_268 , V_248 ) ;
F_118 ( V_268 ) ;
F_142 ( V_4 , V_268 , V_2 ) ;
return 0 ;
}
static bool F_180 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_305 , T_4 V_318 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_327 , V_328 , V_329 , V_321 ;
int V_330 ;
if ( F_5 ( V_4 ) -> V_65 & V_97 )
goto V_331;
if ( V_6 -> V_299 != V_300 )
goto V_331;
if ( V_8 -> V_332 &&
( ( ( T_4 ) V_333 << 1 ) >> 1 ) - ( V_8 -> V_332 >> 1 ) > 1 )
goto V_331;
V_321 = F_104 ( V_8 ) ;
F_98 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_321 ) ) ;
V_327 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_328 = ( V_8 -> V_27 - V_321 ) * V_8 -> V_297 ;
V_329 = F_20 ( V_327 , V_328 ) ;
if ( V_329 >= V_318 * V_8 -> V_297 )
goto V_331;
if ( ( V_4 != F_170 ( V_2 ) ) && ( V_329 >= V_4 -> V_81 ) )
goto V_331;
V_330 = F_181 ( V_334 ) ;
if ( V_330 ) {
T_4 V_335 = F_20 ( V_8 -> V_336 , V_8 -> V_27 * V_8 -> V_297 ) ;
V_335 /= V_330 ;
if ( V_329 >= V_335 )
goto V_331;
} else {
if ( V_329 > F_182 ( V_8 ) * V_8 -> V_297 )
goto V_331;
}
if ( ! V_8 -> V_332 )
V_8 -> V_332 = 1 | ( V_333 << 1 ) ;
if ( V_328 < V_327 && V_328 < V_4 -> V_81 )
* V_305 = true ;
return true ;
V_331:
V_8 -> V_332 = 0 ;
return false ;
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_337 , * V_338 ;
int V_81 ;
int V_295 ;
int V_339 ;
int V_340 ;
int V_248 ;
if ( ! V_6 -> V_289 . V_290 ||
V_6 -> V_289 . V_295 ||
F_2 ( V_2 ) -> V_299 != V_300 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_171 || V_8 -> V_59 . V_126 )
return - 1 ;
V_248 = F_62 ( V_2 ) ;
V_295 = 2 * V_8 -> V_297 ;
V_339 = V_295 + ( V_8 -> V_341 + 1 ) * V_8 -> V_297 ;
if ( V_295 > F_155 ( V_2 , V_6 -> V_289 . V_292 ) ) {
return - 1 ;
}
if ( V_8 -> V_246 - V_8 -> V_11 < V_339 )
return - 1 ;
if ( V_8 -> V_336 < V_339 )
return - 1 ;
if ( F_112 ( V_8 -> V_11 + V_339 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_104 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_104 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_337 = F_136 ( V_2 , V_295 , V_180 ) ) == NULL )
return - 1 ;
V_2 -> V_247 += V_337 -> V_203 ;
F_120 ( V_2 , V_337 -> V_203 ) ;
V_4 = F_177 ( V_2 ) ;
F_5 ( V_337 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_337 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_295 ;
F_5 ( V_337 ) -> V_65 = V_235 ;
F_5 ( V_337 ) -> V_94 = 0 ;
V_337 -> V_93 = 0 ;
V_337 -> V_91 = V_4 -> V_91 ;
F_184 ( V_337 , V_4 , V_2 ) ;
V_81 = 0 ;
F_185 (skb, next, sk) {
V_340 = F_30 ( int , V_4 -> V_81 , V_295 - V_81 ) ;
if ( V_337 -> V_91 )
F_186 ( V_4 , 0 , F_138 ( V_337 , V_340 ) , V_340 ) ;
else
V_337 -> V_93 = F_187 ( V_4 , 0 ,
F_138 ( V_337 , V_340 ) ,
V_340 , V_337 -> V_93 ) ;
if ( V_4 -> V_81 <= V_340 ) {
F_5 ( V_337 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_188 ( V_4 , V_2 ) ;
F_189 ( V_2 , V_4 ) ;
} else {
F_5 ( V_337 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_97 | V_274 ) ;
if ( ! F_45 ( V_4 ) -> V_275 ) {
F_190 ( V_4 , V_340 ) ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_191 ( V_4 -> V_181 ,
V_4 -> V_81 , 0 ) ;
} else {
F_143 ( V_4 , V_340 ) ;
F_121 ( V_2 , V_4 , V_248 ) ;
}
F_5 ( V_4 ) -> V_82 += V_340 ;
}
V_81 += V_340 ;
if ( V_81 >= V_295 )
break;
}
F_172 ( V_2 , V_337 , V_337 -> V_81 ) ;
if ( ! F_97 ( V_2 , V_337 , 1 , V_180 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_337 ) ;
V_6 -> V_289 . V_295 = F_156 ( V_2 , V_337 -> V_81 ) ;
V_8 -> V_342 . V_343 = F_5 ( V_337 ) -> V_82 ;
V_8 -> V_342 . V_344 = F_5 ( V_337 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_61 ( struct V_1 * V_2 , unsigned int V_248 , int V_179 ,
int V_345 , T_10 V_267 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_323 , V_346 ;
int V_326 ;
int V_347 ;
bool V_305 = false ;
T_4 V_318 ;
V_346 = 0 ;
if ( ! V_345 ) {
V_347 = F_183 ( V_2 ) ;
if ( ! V_347 ) {
return false ;
} else if ( V_347 > 0 ) {
V_346 = 1 ;
}
}
V_318 = F_168 ( V_2 , V_248 ) ;
while ( ( V_4 = F_177 ( V_2 ) ) ) {
unsigned int V_329 ;
V_323 = F_172 ( V_2 , V_4 , V_248 ) ;
F_98 ( ! V_323 ) ;
if ( F_51 ( V_8 -> V_348 ) && V_8 -> V_349 == V_350 ) {
F_99 ( & V_4 -> V_217 ) ;
goto V_348;
}
V_326 = F_171 ( V_8 , V_4 ) ;
if ( ! V_326 ) {
V_305 = true ;
if ( V_345 == 2 )
V_326 = 1 ;
else
break;
}
if ( F_51 ( ! F_174 ( V_8 , V_4 , V_248 ) ) )
break;
if ( V_323 == 1 || ! V_318 ) {
if ( F_51 ( ! F_173 ( V_8 , V_4 , V_248 ,
( F_178 ( V_2 , V_4 ) ?
V_179 : V_325 ) ) ) )
break;
} else {
if ( ! V_345 &&
F_180 ( V_2 , V_4 , & V_305 ,
V_318 ) )
break;
}
V_329 = V_248 ;
if ( V_323 > 1 && V_318 && ! F_49 ( V_8 ) )
V_329 = F_169 ( V_2 , V_4 , V_248 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_179 ) ;
if ( V_4 -> V_81 > V_329 &&
F_51 ( F_179 ( V_2 , V_4 , V_329 , V_248 , V_267 ) ) )
break;
V_329 = F_21 ( 2 * V_4 -> V_203 , V_2 -> V_313 >> 10 ) ;
V_329 = F_30 ( T_4 , V_329 , V_351 ) ;
if ( F_192 ( & V_2 -> V_204 ) > V_329 ) {
F_73 ( V_207 , & V_8 -> V_191 ) ;
F_193 () ;
if ( F_192 ( & V_2 -> V_204 ) > V_329 )
break;
}
if ( F_51 ( F_97 ( V_2 , V_4 , 1 , V_267 ) ) )
break;
V_348:
F_1 ( V_2 , V_4 ) ;
F_166 ( V_8 , V_248 , V_4 ) ;
V_346 += F_6 ( V_4 ) ;
if ( V_345 )
break;
}
if ( F_53 ( V_346 ) ) {
if ( F_194 ( V_2 ) )
V_8 -> V_352 += V_346 ;
if ( V_345 != 2 )
F_195 ( V_2 ) ;
F_163 ( V_2 , V_305 ) ;
return false ;
}
return ( V_345 == 2 ) || ( ! V_8 -> V_10 && F_177 ( V_2 ) ) ;
}
bool F_195 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_353 , V_354 , V_355 ;
T_4 V_356 = F_196 ( V_8 -> V_357 >> 3 ) ;
if ( F_133 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_133 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_173 == V_358 )
return false ;
if ( V_6 -> V_13 != V_359 )
return false ;
if ( V_360 < 3 || ! V_8 -> V_357 || ! V_8 -> V_10 ||
! F_197 ( V_8 ) || F_2 ( V_2 ) -> V_299 != V_300 )
return false ;
if ( ( V_8 -> V_27 > F_104 ( V_8 ) ) &&
F_177 ( V_2 ) )
return false ;
V_353 = V_356 << 1 ;
if ( V_8 -> V_10 == 1 )
V_353 = F_29 ( T_4 , V_353 ,
( V_356 + ( V_356 >> 1 ) + V_361 ) ) ;
V_353 = F_29 ( T_4 , V_353 , F_198 ( 10 ) ) ;
V_354 = V_23 + V_353 ;
V_355 = ( T_4 ) F_2 ( V_2 ) -> V_362 ;
if ( ( T_3 ) ( V_354 - V_355 ) > 0 ) {
T_3 V_22 = V_355 - V_23 ;
if ( V_22 > 0 )
V_353 = V_22 ;
}
F_199 ( V_2 , V_15 , V_353 ,
V_363 ) ;
return true ;
}
static bool F_200 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_201 ( V_2 , V_4 ) ) ) {
F_202 ( F_9 ( V_2 ) ,
V_364 ) ;
return true ;
}
return false ;
}
void F_203 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_365 ;
int V_19 = F_62 ( V_2 ) ;
int V_216 = - 1 ;
if ( F_177 ( V_2 ) != NULL ) {
V_216 = F_61 ( V_2 , V_19 , V_366 , 2 , V_180 ) ;
goto V_367;
}
if ( V_8 -> V_368 )
goto V_367;
V_4 = F_170 ( V_2 ) ;
if ( F_133 ( ! V_4 ) )
goto V_367;
if ( F_200 ( V_2 , V_4 ) )
goto V_367;
V_365 = F_6 ( V_4 ) ;
if ( F_133 ( ! V_365 ) )
goto V_367;
if ( ( V_365 > 1 ) && ( V_4 -> V_81 > ( V_365 - 1 ) * V_19 ) ) {
if ( F_51 ( F_132 ( V_2 , V_4 , ( V_365 - 1 ) * V_19 , V_19 ,
V_180 ) ) )
goto V_367;
V_4 = F_170 ( V_2 ) ;
}
if ( F_133 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_367;
V_216 = F_204 ( V_2 , V_4 ) ;
if ( F_53 ( ! V_216 ) )
V_8 -> V_368 = V_8 -> V_11 ;
V_367:
F_199 ( V_2 , V_359 ,
F_2 ( V_2 ) -> V_30 ,
V_363 ) ;
if ( F_53 ( ! V_216 ) )
F_202 ( F_9 ( V_2 ) ,
V_369 ) ;
}
void F_205 ( struct V_1 * V_2 , unsigned int V_324 ,
int V_179 )
{
if ( F_51 ( V_2 -> V_173 == V_370 ) )
return;
if ( F_61 ( V_2 , V_324 , V_179 , 0 ,
F_206 ( V_2 , V_180 ) ) )
F_207 ( V_2 ) ;
}
void F_208 ( struct V_1 * V_2 , unsigned int V_248 )
{
struct V_3 * V_4 = F_177 ( V_2 ) ;
F_98 ( ! V_4 || V_4 -> V_81 < V_248 ) ;
F_61 ( V_2 , V_248 , V_325 , 1 , V_2 -> V_371 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_372 ;
int V_373 = F_209 ( V_2 ) ;
int V_374 = F_210 ( V_2 ) ;
int V_375 = F_30 ( int , V_8 -> V_46 , V_374 ) ;
int V_228 ;
if ( V_19 > V_375 )
V_19 = V_375 ;
if ( V_373 < ( V_375 >> 1 ) ) {
V_6 -> V_35 . V_376 = 0 ;
if ( F_211 ( V_2 ) )
V_8 -> V_377 = F_20 ( V_8 -> V_377 ,
4U * V_8 -> V_20 ) ;
V_373 = F_212 ( V_373 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_373 < ( V_374 >> 4 ) || V_373 < V_19 )
return 0 ;
}
if ( V_373 > V_8 -> V_377 )
V_373 = V_8 -> V_377 ;
V_228 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_228 = V_373 ;
if ( ( ( V_228 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_228 )
V_228 = ( ( ( V_228 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_228 <= V_373 - V_19 || V_228 > V_373 )
V_228 = ( V_373 / V_19 ) * V_19 ;
else if ( V_19 == V_375 &&
V_373 > V_228 + ( V_375 >> 1 ) )
V_228 = V_373 ;
}
return V_228 ;
}
static void F_213 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_378 = F_214 ( V_2 , V_4 ) ;
int V_379 , V_380 ;
V_379 = V_4 -> V_81 ;
V_380 = V_378 -> V_81 ;
F_98 ( F_6 ( V_4 ) != 1 || F_6 ( V_378 ) != 1 ) ;
F_215 ( V_2 , V_378 , V_4 ) ;
F_188 ( V_378 , V_2 ) ;
F_216 ( V_378 , F_138 ( V_4 , V_380 ) ,
V_380 ) ;
if ( V_378 -> V_91 == V_92 )
V_4 -> V_91 = V_92 ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_217 ( V_4 -> V_93 , V_378 -> V_93 , V_379 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_378 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_378 ) -> V_65 ;
F_5 ( V_4 ) -> V_94 |= F_5 ( V_378 ) -> V_94 & V_381 ;
F_218 ( V_8 ) ;
if ( V_378 == V_8 -> V_382 )
V_8 -> V_382 = V_4 ;
F_127 ( V_2 , V_378 , F_6 ( V_378 ) ) ;
F_189 ( V_2 , V_378 ) ;
}
static bool F_219 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_45 ( V_4 ) -> V_275 != 0 )
return false ;
if ( F_100 ( V_4 ) )
return false ;
if ( V_4 == F_177 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_94 & V_254 )
return false ;
return true ;
}
static void F_220 ( struct V_1 * V_2 , struct V_3 * V_383 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_383 , * V_384 ;
bool V_385 = true ;
if ( ! V_386 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
return;
F_185 (skb, tmp, sk) {
if ( ! F_219 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_81 ;
if ( V_385 ) {
V_385 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_81 > F_221 ( V_383 ) )
break;
if ( F_112 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_213 ( V_2 , V_383 ) ;
}
}
int F_204 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_324 ;
int V_216 ;
if ( V_6 -> V_289 . V_295 ) {
V_6 -> V_289 . V_295 = 0 ;
}
if ( F_192 ( & V_2 -> V_204 ) >
F_20 ( V_2 -> V_247 + ( V_2 -> V_247 >> 2 ) , V_2 -> V_387 ) )
return - V_388 ;
if ( F_200 ( V_2 , V_4 ) )
return - V_389 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_98 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_98 ) )
F_222 () ;
if ( F_149 ( V_2 , V_4 , V_8 -> V_98 - F_5 ( V_4 ) -> V_82 ) )
return - V_273 ;
}
if ( F_2 ( V_2 ) -> V_198 -> V_390 ( V_2 ) )
return - V_391 ;
V_324 = F_62 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_98 )
return - V_388 ;
if ( V_4 -> V_81 > V_324 ) {
if ( F_132 ( V_2 , V_4 , V_324 , V_324 , V_180 ) )
return - V_273 ;
} else {
int V_392 = F_6 ( V_4 ) ;
if ( F_51 ( V_392 > 1 ) ) {
if ( F_135 ( V_4 , V_180 ) )
return - V_273 ;
F_172 ( V_2 , V_4 , V_324 ) ;
F_127 ( V_2 , V_4 , V_392 - F_6 ( V_4 ) ) ;
}
}
F_220 ( V_2 , V_4 , V_324 ) ;
if ( F_51 ( ( V_393 && ( ( unsigned long ) V_4 -> V_181 & 3 ) ) ||
F_223 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_337 = F_224 ( V_4 , V_315 ,
V_180 ) ;
V_216 = V_337 ? F_97 ( V_2 , V_337 , 0 , V_180 ) :
- V_218 ;
} else {
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
}
if ( F_53 ( ! V_216 ) ) {
F_5 ( V_4 ) -> V_94 |= V_381 ;
F_225 ( F_9 ( V_2 ) , V_394 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
F_202 ( F_9 ( V_2 ) , V_395 ) ;
V_8 -> V_396 ++ ;
}
return V_216 ;
}
int F_226 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_216 = F_204 ( V_2 , V_4 ) ;
if ( V_216 == 0 ) {
#if V_397 > 0
if ( F_5 ( V_4 ) -> V_94 & V_255 ) {
F_227 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_256 )
V_8 -> V_398 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_94 |= V_399 ;
V_8 -> V_256 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_400 )
V_8 -> V_400 = F_56 ( V_4 ) ;
F_5 ( V_4 ) -> V_226 = V_8 -> V_11 ;
} else if ( V_216 != - V_389 ) {
F_202 ( F_9 ( V_2 ) , V_401 ) ;
}
if ( V_8 -> V_402 < 0 )
V_8 -> V_402 = 0 ;
V_8 -> V_402 += F_6 ( V_4 ) ;
return V_216 ;
}
static bool F_228 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_299 != V_403 )
return false ;
if ( F_125 ( V_8 ) )
return false ;
if ( F_176 ( V_2 ) )
return false ;
return true ;
}
void F_229 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_404 = NULL ;
T_4 V_405 ;
int V_406 ;
int V_407 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_258 )
V_8 -> V_408 = V_8 -> V_98 ;
if ( V_8 -> V_382 ) {
V_4 = V_8 -> V_382 ;
V_405 = F_5 ( V_4 ) -> V_12 ;
if ( F_112 ( V_405 , V_8 -> V_408 ) )
V_405 = V_8 -> V_408 ;
} else {
V_4 = F_230 ( V_2 ) ;
V_405 = V_8 -> V_98 ;
}
F_231 (skb, sk) {
T_5 V_94 = F_5 ( V_4 ) -> V_94 ;
if ( V_4 == F_177 ( V_2 ) )
break;
if ( V_404 == NULL )
V_8 -> V_382 = V_4 ;
if ( F_104 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_407 ) {
V_409:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_126 ( V_8 ) ) )
break;
V_406 = V_410 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_408 ) ) {
V_8 -> V_408 = V_405 ;
if ( ! F_228 ( V_2 ) )
break;
if ( V_404 != NULL ) {
V_4 = V_404 ;
V_404 = NULL ;
}
V_407 = 1 ;
goto V_409;
} else if ( ! ( V_94 & V_257 ) ) {
if ( V_404 == NULL && ! ( V_94 & ( V_255 | V_254 ) ) )
V_404 = V_4 ;
continue;
} else {
V_405 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_299 != V_411 )
V_406 = V_412 ;
else
V_406 = V_413 ;
}
if ( V_94 & ( V_254 | V_255 ) )
continue;
if ( F_226 ( V_2 , V_4 ) )
return;
F_202 ( F_9 ( V_2 ) , V_406 ) ;
if ( F_194 ( V_2 ) )
V_8 -> V_352 += F_6 ( V_4 ) ;
if ( V_4 == F_230 ( V_2 ) )
F_199 ( V_2 , V_359 ,
F_2 ( V_2 ) -> V_30 ,
V_363 ) ;
}
}
void F_232 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_170 ( V_2 ) ;
int V_248 ;
V_248 = F_62 ( V_2 ) ;
if ( F_177 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_65 |= V_97 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_246 ++ ;
} else {
for (; ; ) {
V_4 = F_233 ( V_315 ,
V_2 -> V_371 ) ;
if ( V_4 )
break;
F_234 () ;
}
F_235 ( V_4 , V_315 ) ;
F_47 ( V_4 , V_8 -> V_246 ,
V_235 | V_97 ) ;
F_117 ( V_2 , V_4 ) ;
}
F_205 ( V_2 , V_248 , V_366 ) ;
}
void F_236 ( struct V_1 * V_2 , T_10 V_414 )
{
struct V_3 * V_4 ;
V_4 = F_237 ( V_315 , V_414 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_415 ) ;
return;
}
F_235 ( V_4 , V_315 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_235 | V_416 ) ;
if ( F_97 ( V_2 , V_4 , 0 , V_414 ) )
F_34 ( F_9 ( V_2 ) , V_415 ) ;
F_225 ( F_9 ( V_2 ) , V_417 ) ;
}
int F_238 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_230 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_65 & V_96 ) ) {
F_239 ( L_2 , V_418 ) ;
return - V_419 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_235 ) ) {
if ( F_100 ( V_4 ) ) {
struct V_3 * V_337 = F_240 ( V_4 , V_180 ) ;
if ( V_337 == NULL )
return - V_273 ;
F_188 ( V_4 , V_2 ) ;
F_118 ( V_337 ) ;
F_241 ( V_2 , V_337 ) ;
F_189 ( V_2 , V_4 ) ;
V_2 -> V_247 += V_337 -> V_203 ;
F_120 ( V_2 , V_337 -> V_203 ) ;
V_4 = V_337 ;
}
F_5 ( V_4 ) -> V_65 |= V_235 ;
F_36 ( V_2 , V_4 ) ;
}
return F_97 ( V_2 , V_4 , 1 , V_180 ) ;
}
struct V_3 * F_242 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_135 * V_136 )
{
struct V_101 V_102 ;
struct V_165 * V_166 = F_42 ( V_75 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_76 * V_77 ;
struct V_3 * V_4 ;
struct V_143 * V_144 ;
int V_215 ;
int V_19 ;
V_4 = F_243 ( V_2 , V_315 , 1 , V_180 ) ;
if ( F_51 ( ! V_4 ) ) {
F_244 ( V_18 ) ;
return NULL ;
}
F_235 ( V_4 , V_315 ) ;
F_245 ( V_4 , V_18 ) ;
F_246 ( V_4 , V_2 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_420 && V_8 -> V_59 . V_420 < V_19 )
V_19 = V_8 -> V_59 . V_420 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
#ifdef F_247
if ( F_51 ( V_75 -> V_421 ) )
V_4 -> V_217 . V_422 = F_248 ( V_75 ) ;
else
#endif
F_99 ( & V_4 -> V_217 ) ;
V_215 = F_57 ( V_2 , V_75 , V_19 , V_4 , & V_102 , & V_144 ,
V_136 ) + sizeof( * V_77 ) ;
F_106 ( V_4 , V_215 ) ;
F_107 ( V_4 ) ;
V_77 = F_44 ( V_4 ) ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_423 = 1 ;
V_77 -> V_424 = 1 ;
F_41 ( V_75 , V_77 , V_2 ) ;
V_77 -> V_222 = F_111 ( V_166 -> V_425 ) ;
V_77 -> V_224 = V_166 -> V_426 ;
F_47 ( V_4 , F_58 ( V_75 ) -> V_427 ,
V_96 | V_235 ) ;
V_77 -> V_82 = F_52 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_226 = F_52 ( F_58 ( V_75 ) -> V_61 ) ;
V_77 -> V_228 = F_111 ( F_20 ( V_75 -> V_45 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_102 ) ;
V_77 -> V_428 = ( V_215 >> 2 ) ;
F_249 ( F_9 ( V_2 ) , V_236 ) ;
#ifdef F_55
if ( V_144 ) {
F_58 ( V_75 ) -> V_150 -> V_233 ( V_102 . V_108 ,
V_144 , NULL , V_75 , V_4 ) ;
}
#endif
return V_4 ;
}
static void F_250 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_48 ;
V_8 -> V_80 = sizeof( struct V_76 ) +
( V_154 ? V_157 : 0 ) ;
#ifdef F_55
if ( V_8 -> V_150 -> V_151 ( V_2 , V_2 ) != NULL )
V_8 -> V_80 += V_152 ;
#endif
if ( V_8 -> V_59 . V_420 )
V_8 -> V_59 . V_286 = V_8 -> V_59 . V_420 ;
V_8 -> V_429 = 0 ;
F_157 ( V_2 ) ;
F_158 ( V_2 , F_160 ( V_18 ) ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_430 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_420 && V_8 -> V_59 . V_420 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_420 ;
F_251 ( V_2 ) ;
if ( V_2 -> V_431 & V_432 &&
( V_8 -> V_46 > F_210 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_210 ( V_2 ) ;
F_28 ( F_210 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_433 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_158 ,
& V_48 ,
F_23 ( V_18 , V_434 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_377 = V_8 -> V_45 ;
V_2 -> V_435 = 0 ;
F_252 ( V_2 , V_436 ) ;
V_8 -> V_336 = 0 ;
F_253 ( V_8 , 0 ) ;
V_8 -> V_98 = V_8 -> V_246 ;
V_8 -> V_308 = V_8 -> V_246 ;
V_8 -> V_99 = V_8 -> V_246 ;
V_8 -> V_11 = V_8 -> V_246 ;
if ( F_53 ( ! V_8 -> V_348 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_437 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_438 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_439 ;
F_2 ( V_2 ) -> V_440 = 0 ;
F_254 ( V_8 ) ;
}
static void F_255 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_212 * V_213 = F_5 ( V_4 ) ;
V_213 -> V_12 += V_4 -> V_81 ;
F_118 ( V_4 ) ;
F_256 ( V_2 , V_4 ) ;
V_2 -> V_247 += V_4 -> V_203 ;
F_120 ( V_2 , V_4 -> V_203 ) ;
V_8 -> V_246 = V_213 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_257 ( struct V_1 * V_2 , struct V_3 * V_423 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_147 * V_441 = V_8 -> V_149 ;
int V_442 = 0 , V_50 , V_216 = 0 ;
unsigned long V_443 = 0 ;
struct V_3 * V_444 ;
V_8 -> V_59 . V_286 = V_8 -> V_20 ;
F_258 ( V_2 , & V_8 -> V_59 . V_286 , & V_441 -> V_162 ,
& V_442 , & V_443 ) ;
if ( V_442 > 1 &&
F_259 ( V_333 , V_443 + ( 60 * V_445 << V_442 ) ) ) {
V_441 -> V_162 . V_81 = - 1 ;
goto V_446;
}
if ( V_447 & V_448 )
V_441 -> V_162 . V_81 = - 1 ;
else if ( V_441 -> V_162 . V_81 <= 0 )
goto V_446;
if ( V_8 -> V_59 . V_420 && V_8 -> V_59 . V_420 < V_8 -> V_59 . V_286 )
V_8 -> V_59 . V_286 = V_8 -> V_59 . V_420 ;
V_50 = F_153 ( V_2 , F_2 ( V_2 ) -> V_296 ) -
V_146 ;
V_50 = F_30 ( V_449 , V_50 , V_441 -> V_169 ) ;
V_50 = F_30 ( V_449 , V_50 , F_260 ( V_315 ) ) ;
V_444 = F_136 ( V_2 , V_50 , V_2 -> V_371 ) ;
if ( ! V_444 )
goto V_446;
V_444 -> V_91 = V_92 ;
memcpy ( V_444 -> V_240 , V_423 -> V_240 , sizeof( V_423 -> V_240 ) ) ;
if ( F_51 ( F_261 ( F_138 ( V_444 , V_50 ) ,
V_441 -> V_181 -> V_450 . V_451 , 0 , V_50 ) ) ) {
F_262 ( V_444 ) ;
goto V_446;
}
if ( V_50 == V_441 -> V_169 )
V_441 -> V_181 = NULL ;
V_441 -> V_452 = V_50 ;
F_255 ( V_2 , V_444 ) ;
V_216 = F_97 ( V_2 , V_444 , 1 , V_2 -> V_371 ) ;
V_423 -> V_217 = V_444 -> V_217 ;
F_5 ( V_444 ) -> V_82 ++ ;
F_5 ( V_444 ) -> V_65 = V_235 | V_274 ;
if ( ! V_216 ) {
V_8 -> V_444 = ( V_441 -> V_452 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_453;
}
V_446:
if ( V_441 -> V_162 . V_81 > 0 )
V_441 -> V_162 . V_81 = 0 ;
V_216 = F_97 ( V_2 , V_423 , 1 , V_2 -> V_371 ) ;
if ( V_216 )
V_8 -> V_164 = 0 ;
V_453:
V_441 -> V_162 . V_81 = - 1 ;
return V_216 ;
}
int F_263 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_268 ;
int V_216 ;
F_250 ( V_2 ) ;
if ( F_51 ( V_8 -> V_348 ) ) {
F_264 ( V_2 , NULL ) ;
return 0 ;
}
V_268 = F_136 ( V_2 , 0 , V_2 -> V_371 ) ;
if ( F_51 ( ! V_268 ) )
return - V_218 ;
F_47 ( V_268 , V_8 -> V_246 ++ , V_96 ) ;
V_8 -> V_400 = V_23 ;
F_255 ( V_2 , V_268 ) ;
F_39 ( V_2 , V_268 ) ;
V_216 = V_8 -> V_149 ? F_257 ( V_2 , V_268 ) :
F_97 ( V_2 , V_268 , 1 , V_2 -> V_371 ) ;
if ( V_216 == - V_454 )
return V_216 ;
V_8 -> V_11 = V_8 -> V_246 ;
V_8 -> V_455 = V_8 -> V_246 ;
F_225 ( F_9 ( V_2 ) , V_456 ) ;
F_199 ( V_2 , V_359 ,
F_2 ( V_2 ) -> V_30 , V_363 ) ;
return 0 ;
}
void F_265 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_353 ;
F_18 ( V_2 , V_457 ) ;
if ( V_37 > V_458 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_459 = V_445 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_460 & V_461 ) )
V_459 = V_361 ;
if ( V_8 -> V_357 ) {
int V_356 = F_29 ( int , F_196 ( V_8 -> V_357 >> 3 ) ,
V_458 ) ;
if ( V_356 < V_459 )
V_459 = V_356 ;
}
V_37 = F_20 ( V_37 , V_459 ) ;
}
V_353 = V_333 + V_37 ;
if ( V_6 -> V_35 . V_460 & V_462 ) {
if ( V_6 -> V_35 . V_463 ||
F_266 ( V_6 -> V_35 . V_353 , V_333 + ( V_37 >> 2 ) ) ) {
F_267 ( V_2 ) ;
return;
}
if ( ! F_259 ( V_353 , V_6 -> V_35 . V_353 ) )
V_353 = V_6 -> V_35 . V_353 ;
}
V_6 -> V_35 . V_460 |= V_464 | V_462 ;
V_6 -> V_35 . V_353 = V_353 ;
F_268 ( V_2 , & V_6 -> V_465 , V_353 ) ;
}
void F_267 ( struct V_1 * V_2 )
{
struct V_3 * V_268 ;
if ( V_2 -> V_173 == V_370 )
return;
F_18 ( V_2 , V_466 ) ;
V_268 = F_237 ( V_315 , F_206 ( V_2 , V_180 ) ) ;
if ( V_268 == NULL ) {
F_269 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_467 ;
F_199 ( V_2 , V_41 ,
V_361 , V_363 ) ;
return;
}
F_235 ( V_268 , V_315 ) ;
F_47 ( V_268 , F_10 ( V_2 ) , V_235 ) ;
F_99 ( & V_268 -> V_217 ) ;
F_97 ( V_2 , V_268 , 0 , F_206 ( V_2 , V_180 ) ) ;
}
static int F_270 ( struct V_1 * V_2 , int V_468 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_237 ( V_315 , F_206 ( V_2 , V_180 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_235 ( V_4 , V_315 ) ;
F_47 ( V_4 , V_8 -> V_98 - ! V_468 , V_235 ) ;
F_99 ( & V_4 -> V_217 ) ;
return F_97 ( V_2 , V_4 , 0 , V_180 ) ;
}
void F_271 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_469 ) {
F_3 ( V_2 ) -> V_470 = F_3 ( V_2 ) -> V_61 - 1 ;
F_270 ( V_2 , 0 ) ;
}
}
int F_272 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_370 )
return - 1 ;
if ( ( V_4 = F_177 ( V_2 ) ) != NULL &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_216 ;
unsigned int V_19 = F_62 ( V_2 ) ;
unsigned int V_471 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_455 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_455 = F_5 ( V_4 ) -> V_12 ;
if ( V_471 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_471 = F_20 ( V_471 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_274 ;
if ( F_132 ( V_2 , V_4 , V_471 , V_19 , V_180 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_121 ( V_2 , V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_274 ;
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
if ( ! V_216 )
F_1 ( V_2 , V_4 ) ;
return V_216 ;
} else {
if ( F_273 ( V_8 -> V_99 , V_8 -> V_98 + 1 , V_8 -> V_98 + 0xFFFF ) )
F_270 ( V_2 , 1 ) ;
return F_270 ( V_2 , 0 ) ;
}
}
void F_274 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_472 ;
int V_216 ;
V_216 = F_272 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_177 ( V_2 ) ) {
V_6 -> V_473 = 0 ;
V_6 -> V_474 = 0 ;
return;
}
if ( V_216 <= 0 ) {
if ( V_6 -> V_474 < V_475 )
V_6 -> V_474 ++ ;
V_6 -> V_473 ++ ;
V_472 = V_363 ;
} else {
if ( ! V_6 -> V_473 )
V_6 -> V_473 = 1 ;
V_472 = V_476 ;
}
F_199 ( V_2 , V_477 ,
F_275 ( V_6 , V_472 ) ,
V_363 ) ;
}
int F_276 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_478 * V_479 = F_58 ( V_75 ) -> V_150 ;
struct V_480 V_245 ;
int V_481 ;
V_481 = V_479 -> V_482 ( V_2 , NULL , & V_245 , V_75 , 0 , NULL ) ;
if ( ! V_481 ) {
F_249 ( F_9 ( V_2 ) , V_394 ) ;
F_202 ( F_9 ( V_2 ) , V_395 ) ;
}
return V_481 ;
}
